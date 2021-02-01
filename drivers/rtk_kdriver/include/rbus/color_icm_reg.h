/**
* @file Mac5-DesignSpec-D-Domain_ICM
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_ICM_REG_H_
#define _RBUS_COLOR_ICM_REG_H_

#include "rbus_types.h"



//  COLOR_ICM Register Address
#define  COLOR_ICM_DM_ICM_CTRL                                                   0x1802A100
#define  COLOR_ICM_DM_ICM_CTRL_reg_addr                                          "0xB802A100"
#define  COLOR_ICM_DM_ICM_CTRL_reg                                               0xB802A100
#define  COLOR_ICM_DM_ICM_CTRL_inst_addr                                         "0x0000"
#define  set_COLOR_ICM_DM_ICM_CTRL_reg(data)                                     (*((volatile unsigned int*)COLOR_ICM_DM_ICM_CTRL_reg)=data)
#define  get_COLOR_ICM_DM_ICM_CTRL_reg                                           (*((volatile unsigned int*)COLOR_ICM_DM_ICM_CTRL_reg))
#define  COLOR_ICM_DM_ICM_CTRL_hsi_grid_sel_shift                                (30)
#define  COLOR_ICM_DM_ICM_CTRL_bypass_yuv2rgb_enable_shift                       (29)
#define  COLOR_ICM_DM_ICM_CTRL_out_grid_process_shift                            (28)
#define  COLOR_ICM_DM_ICM_CTRL_y_ctrl_shift                                      (27)
#define  COLOR_ICM_DM_ICM_CTRL_debug_en_shift                                    (26)
#define  COLOR_ICM_DM_ICM_CTRL_debug_color_shift                                 (24)
#define  COLOR_ICM_DM_ICM_CTRL_data_format_sel_shift                             (22)
#define  COLOR_ICM_DM_ICM_CTRL_data_range_sel_shift                              (21)
#define  COLOR_ICM_DM_ICM_CTRL_m_icm_bypass_en_shift                             (17)
#define  COLOR_ICM_DM_ICM_CTRL_dummy_16_0_shift                                  (0)
#define  COLOR_ICM_DM_ICM_CTRL_hsi_grid_sel_mask                                 (0x40000000)
#define  COLOR_ICM_DM_ICM_CTRL_bypass_yuv2rgb_enable_mask                        (0x20000000)
#define  COLOR_ICM_DM_ICM_CTRL_out_grid_process_mask                             (0x10000000)
#define  COLOR_ICM_DM_ICM_CTRL_y_ctrl_mask                                       (0x08000000)
#define  COLOR_ICM_DM_ICM_CTRL_debug_en_mask                                     (0x04000000)
#define  COLOR_ICM_DM_ICM_CTRL_debug_color_mask                                  (0x03000000)
#define  COLOR_ICM_DM_ICM_CTRL_data_format_sel_mask                              (0x00400000)
#define  COLOR_ICM_DM_ICM_CTRL_data_range_sel_mask                               (0x00200000)
#define  COLOR_ICM_DM_ICM_CTRL_m_icm_bypass_en_mask                              (0x00020000)
#define  COLOR_ICM_DM_ICM_CTRL_dummy_16_0_mask                                   (0x0001FFFF)
#define  COLOR_ICM_DM_ICM_CTRL_hsi_grid_sel(data)                                (0x40000000&((data)<<30))
#define  COLOR_ICM_DM_ICM_CTRL_bypass_yuv2rgb_enable(data)                       (0x20000000&((data)<<29))
#define  COLOR_ICM_DM_ICM_CTRL_out_grid_process(data)                            (0x10000000&((data)<<28))
#define  COLOR_ICM_DM_ICM_CTRL_y_ctrl(data)                                      (0x08000000&((data)<<27))
#define  COLOR_ICM_DM_ICM_CTRL_debug_en(data)                                    (0x04000000&((data)<<26))
#define  COLOR_ICM_DM_ICM_CTRL_debug_color(data)                                 (0x03000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_CTRL_data_format_sel(data)                             (0x00400000&((data)<<22))
#define  COLOR_ICM_DM_ICM_CTRL_data_range_sel(data)                              (0x00200000&((data)<<21))
#define  COLOR_ICM_DM_ICM_CTRL_m_icm_bypass_en(data)                             (0x00020000&((data)<<17))
#define  COLOR_ICM_DM_ICM_CTRL_dummy_16_0(data)                                  (0x0001FFFF&(data))
#define  COLOR_ICM_DM_ICM_CTRL_get_hsi_grid_sel(data)                            ((0x40000000&(data))>>30)
#define  COLOR_ICM_DM_ICM_CTRL_get_bypass_yuv2rgb_enable(data)                   ((0x20000000&(data))>>29)
#define  COLOR_ICM_DM_ICM_CTRL_get_out_grid_process(data)                        ((0x10000000&(data))>>28)
#define  COLOR_ICM_DM_ICM_CTRL_get_y_ctrl(data)                                  ((0x08000000&(data))>>27)
#define  COLOR_ICM_DM_ICM_CTRL_get_debug_en(data)                                ((0x04000000&(data))>>26)
#define  COLOR_ICM_DM_ICM_CTRL_get_debug_color(data)                             ((0x03000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_CTRL_get_data_format_sel(data)                         ((0x00400000&(data))>>22)
#define  COLOR_ICM_DM_ICM_CTRL_get_data_range_sel(data)                          ((0x00200000&(data))>>21)
#define  COLOR_ICM_DM_ICM_CTRL_get_m_icm_bypass_en(data)                         ((0x00020000&(data))>>17)
#define  COLOR_ICM_DM_ICM_CTRL_get_dummy_16_0(data)                              (0x0001FFFF&(data))

#define  COLOR_ICM_DM_UV_Coring                                                  0x1802A104
#define  COLOR_ICM_DM_UV_Coring_reg_addr                                         "0xB802A104"
#define  COLOR_ICM_DM_UV_Coring_reg                                              0xB802A104
#define  COLOR_ICM_DM_UV_Coring_inst_addr                                        "0x0001"
#define  set_COLOR_ICM_DM_UV_Coring_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_DM_UV_Coring_reg)=data)
#define  get_COLOR_ICM_DM_UV_Coring_reg                                          (*((volatile unsigned int*)COLOR_ICM_DM_UV_Coring_reg))
#define  COLOR_ICM_DM_UV_Coring_u_coring_shift                                   (8)
#define  COLOR_ICM_DM_UV_Coring_v_coring_shift                                   (0)
#define  COLOR_ICM_DM_UV_Coring_u_coring_mask                                    (0x0000FF00)
#define  COLOR_ICM_DM_UV_Coring_v_coring_mask                                    (0x000000FF)
#define  COLOR_ICM_DM_UV_Coring_u_coring(data)                                   (0x0000FF00&((data)<<8))
#define  COLOR_ICM_DM_UV_Coring_v_coring(data)                                   (0x000000FF&(data))
#define  COLOR_ICM_DM_UV_Coring_get_u_coring(data)                               ((0x0000FF00&(data))>>8)
#define  COLOR_ICM_DM_UV_Coring_get_v_coring(data)                               (0x000000FF&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0                                          0x1802A108
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg_addr                                 "0xB802A108"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg                                      0xB802A108
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_inst_addr                                "0x0002"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_0_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_1_shift                         (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_2_shift                         (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_3_shift                         (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_4_shift                         (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_1_mask                          (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_2_mask                          (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_3_mask                          (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_4_mask                          (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_1(data)                         (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_2(data)                         (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_3(data)                         (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_h_pillar_4(data)                         (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_get_h_pillar_1(data)                     ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_get_h_pillar_2(data)                     ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_get_h_pillar_3(data)                     ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_0_get_h_pillar_4(data)                     (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1                                          0x1802A10C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg_addr                                 "0xB802A10C"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg                                      0xB802A10C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_inst_addr                                "0x0003"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_1_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_5_shift                         (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_6_shift                         (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_7_shift                         (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_8_shift                         (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_5_mask                          (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_6_mask                          (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_7_mask                          (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_8_mask                          (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_5(data)                         (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_6(data)                         (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_7(data)                         (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_h_pillar_8(data)                         (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_get_h_pillar_5(data)                     ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_get_h_pillar_6(data)                     ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_get_h_pillar_7(data)                     ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_1_get_h_pillar_8(data)                     (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2                                          0x1802A110
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg_addr                                 "0xB802A110"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg                                      0xB802A110
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_inst_addr                                "0x0004"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_2_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_9_shift                         (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_10_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_11_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_12_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_9_mask                          (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_10_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_11_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_12_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_9(data)                         (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_10(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_11(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_h_pillar_12(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_get_h_pillar_9(data)                     ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_get_h_pillar_10(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_get_h_pillar_11(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_2_get_h_pillar_12(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3                                          0x1802A114
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg_addr                                 "0xB802A114"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg                                      0xB802A114
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_inst_addr                                "0x0005"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_3_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_13_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_14_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_15_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_16_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_13_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_14_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_15_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_16_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_13(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_14(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_15(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_h_pillar_16(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_get_h_pillar_13(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_get_h_pillar_14(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_get_h_pillar_15(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_3_get_h_pillar_16(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4                                          0x1802A118
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg_addr                                 "0xB802A118"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg                                      0xB802A118
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_inst_addr                                "0x0006"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_4_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_17_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_18_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_19_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_20_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_17_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_18_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_19_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_20_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_17(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_18(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_19(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_h_pillar_20(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_get_h_pillar_17(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_get_h_pillar_18(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_get_h_pillar_19(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_4_get_h_pillar_20(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5                                          0x1802A11C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg_addr                                 "0xB802A11C"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg                                      0xB802A11C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_inst_addr                                "0x0007"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_5_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_21_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_22_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_23_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_24_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_21_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_22_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_23_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_24_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_21(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_22(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_23(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_h_pillar_24(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_get_h_pillar_21(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_get_h_pillar_22(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_get_h_pillar_23(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_5_get_h_pillar_24(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6                                          0x1802A120
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg_addr                                 "0xB802A120"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg                                      0xB802A120
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_inst_addr                                "0x0008"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_6_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_25_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_26_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_27_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_28_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_25_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_26_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_27_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_28_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_25(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_26(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_27(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_h_pillar_28(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_get_h_pillar_25(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_get_h_pillar_26(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_get_h_pillar_27(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_6_get_h_pillar_28(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7                                          0x1802A124
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg_addr                                 "0xB802A124"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg                                      0xB802A124
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_inst_addr                                "0x0009"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_7_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_29_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_30_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_31_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_32_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_29_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_30_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_31_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_32_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_29(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_30(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_31(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_h_pillar_32(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_get_h_pillar_29(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_get_h_pillar_30(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_get_h_pillar_31(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_7_get_h_pillar_32(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8                                          0x1802A128
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg_addr                                 "0xB802A128"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg                                      0xB802A128
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_inst_addr                                "0x000A"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_8_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_33_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_34_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_35_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_36_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_33_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_34_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_35_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_36_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_33(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_34(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_35(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_h_pillar_36(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_get_h_pillar_33(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_get_h_pillar_34(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_get_h_pillar_35(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_8_get_h_pillar_36(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9                                          0x1802A12C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg_addr                                 "0xB802A12C"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg                                      0xB802A12C
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_inst_addr                                "0x000B"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_9_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_37_shift                        (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_38_shift                        (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_39_shift                        (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_40_shift                        (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_37_mask                         (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_38_mask                         (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_39_mask                         (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_40_mask                         (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_37(data)                        (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_38(data)                        (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_39(data)                        (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_h_pillar_40(data)                        (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_get_h_pillar_37(data)                    ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_get_h_pillar_38(data)                    ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_get_h_pillar_39(data)                    ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_9_get_h_pillar_40(data)                    (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10                                         0x1802A130
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg_addr                                "0xB802A130"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg                                     0xB802A130
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_inst_addr                               "0x000C"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg(data)                           (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg                                 (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_10_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_41_shift                       (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_42_shift                       (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_43_shift                       (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_44_shift                       (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_41_mask                        (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_42_mask                        (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_43_mask                        (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_44_mask                        (0x0000003F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_41(data)                       (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_42(data)                       (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_43(data)                       (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_h_pillar_44(data)                       (0x0000003F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_get_h_pillar_41(data)                   ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_get_h_pillar_42(data)                   ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_get_h_pillar_43(data)                   ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_10_get_h_pillar_44(data)                   (0x0000003F&(data))

#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11                                         0x1802A134
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg_addr                                "0xB802A134"
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg                                     0xB802A134
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_inst_addr                               "0x000D"
#define  set_COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg(data)                           (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg)=data)
#define  get_COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg                                 (*((volatile unsigned int*)COLOR_ICM_DM_ICM_HUE_SEGMENT_11_reg))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_45_shift                       (24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_46_shift                       (16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_47_shift                       (8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_48_shift                       (0)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_45_mask                        (0x3F000000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_46_mask                        (0x003F0000)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_47_mask                        (0x00003F00)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_48_mask                        (0x0000007F)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_45(data)                       (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_46(data)                       (0x003F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_47(data)                       (0x00003F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_h_pillar_48(data)                       (0x0000007F&(data))
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_get_h_pillar_45(data)                   ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_get_h_pillar_46(data)                   ((0x003F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_get_h_pillar_47(data)                   ((0x00003F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_HUE_SEGMENT_11_get_h_pillar_48(data)                   (0x0000007F&(data))

#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0                                          0x1802A138
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg_addr                                 "0xB802A138"
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg                                      0xB802A138
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_inst_addr                                "0x000E"
#define  set_COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_SAT_SEGMENT_0_reg))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_1_shift                         (28)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_2_shift                         (24)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_3_shift                         (20)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_4_shift                         (16)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_5_shift                         (12)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_6_shift                         (8)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_7_shift                         (4)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_8_shift                         (0)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_1_mask                          (0xF0000000)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_2_mask                          (0x0F000000)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_3_mask                          (0x00F00000)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_4_mask                          (0x000F0000)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_5_mask                          (0x0000F000)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_6_mask                          (0x00000F00)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_7_mask                          (0x000000F0)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_8_mask                          (0x0000000F)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_1(data)                         (0xF0000000&((data)<<28))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_2(data)                         (0x0F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_3(data)                         (0x00F00000&((data)<<20))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_4(data)                         (0x000F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_5(data)                         (0x0000F000&((data)<<12))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_6(data)                         (0x00000F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_7(data)                         (0x000000F0&((data)<<4))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_s_pillar_8(data)                         (0x0000000F&(data))
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_1(data)                     ((0xF0000000&(data))>>28)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_2(data)                     ((0x0F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_3(data)                     ((0x00F00000&(data))>>20)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_4(data)                     ((0x000F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_5(data)                     ((0x0000F000&(data))>>12)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_6(data)                     ((0x00000F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_7(data)                     ((0x000000F0&(data))>>4)
#define  COLOR_ICM_DM_ICM_SAT_SEGMENT_0_get_s_pillar_8(data)                     (0x0000000F&(data))

#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0                                          0x1802A13C
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg_addr                                 "0xB802A13C"
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg                                      0xB802A13C
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_inst_addr                                "0x000F"
#define  set_COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg                                  (*((volatile unsigned int*)COLOR_ICM_DM_ICM_INT_SEGMENT_0_reg))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_1_shift                         (28)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_2_shift                         (24)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_3_shift                         (20)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_4_shift                         (16)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_5_shift                         (12)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_6_shift                         (8)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_7_shift                         (4)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_8_shift                         (0)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_1_mask                          (0xF0000000)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_2_mask                          (0x0F000000)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_3_mask                          (0x00F00000)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_4_mask                          (0x000F0000)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_5_mask                          (0x0000F000)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_6_mask                          (0x00000F00)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_7_mask                          (0x000000F0)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_8_mask                          (0x0000000F)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_1(data)                         (0xF0000000&((data)<<28))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_2(data)                         (0x0F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_3(data)                         (0x00F00000&((data)<<20))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_4(data)                         (0x000F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_5(data)                         (0x0000F000&((data)<<12))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_6(data)                         (0x00000F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_7(data)                         (0x000000F0&((data)<<4))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_i_pillar_8(data)                         (0x0000000F&(data))
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_1(data)                     ((0xF0000000&(data))>>28)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_2(data)                     ((0x0F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_3(data)                     ((0x00F00000&(data))>>20)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_4(data)                     ((0x000F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_5(data)                     ((0x0000F000&(data))>>12)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_6(data)                     ((0x00000F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_7(data)                     ((0x000000F0&(data))>>4)
#define  COLOR_ICM_DM_ICM_INT_SEGMENT_0_get_i_pillar_8(data)                     (0x0000000F&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL                                          0x1802A140
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg_addr                                 "0xB802A140"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg                                      0xB802A140
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_inst_addr                                "0x0010"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg(data)                            (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg                                  (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_sat_hist_mode_shift                      (5)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_d_auto_sat_ctrl_sat_hist_mode_sel_shift  (4)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_ok_shift                        (3)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_enable_shift                    (2)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_sat_hist_mode_mask                       (0x00000020)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_d_auto_sat_ctrl_sat_hist_mode_sel_mask   (0x00000010)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_ok_mask                         (0x00000008)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_enable_mask                     (0x00000004)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_sat_hist_mode(data)                      (0x00000020&((data)<<5))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_d_auto_sat_ctrl_sat_hist_mode_sel(data)  (0x00000010&((data)<<4))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_ok(data)                        (0x00000008&((data)<<3))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_hist_sat_enable(data)                    (0x00000004&((data)<<2))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_get_sat_hist_mode(data)                  ((0x00000020&(data))>>5)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_get_d_auto_sat_ctrl_sat_hist_mode_sel(data) ((0x00000010&(data))>>4)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_get_hist_sat_ok(data)                    ((0x00000008&(data))>>3)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL_get_hist_sat_enable(data)                ((0x00000004&(data))>>2)

#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD                                     0x1802A144
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg_addr                            "0xB802A144"
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg                                 0xB802A144
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_inst_addr                           "0x0011"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_u_thre0_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_l_thre0_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_u_thre0_mask (0x3FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_l_thre0_mask (0x00003FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_u_thre0(data) (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_d_hist0_thrd_auto_sat_i_l_thre0(data) (0x00003FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_get_d_hist0_thrd_auto_sat_i_u_thre0(data) ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST0_INT_THRD_get_d_hist0_thrd_auto_sat_i_l_thre0(data) (0x00003FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD                                     0x1802A148
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg_addr                            "0xB802A148"
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg                                 0xB802A148
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_inst_addr                           "0x0012"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_u_thre1_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_l_thre1_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_u_thre1_mask (0x3FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_l_thre1_mask (0x00003FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_u_thre1(data) (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_d_hist1_thrd_auto_sat_i_l_thre1(data) (0x00003FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_get_d_hist1_thrd_auto_sat_i_u_thre1(data) ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST1_INT_THRD_get_d_hist1_thrd_auto_sat_i_l_thre1(data) (0x00003FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD                                     0x1802A14C
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg_addr                            "0xB802A14C"
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg                                 0xB802A14C
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_inst_addr                           "0x0013"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_u_thre2_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_l_thre2_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_u_thre2_mask (0x3FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_l_thre2_mask (0x00003FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_u_thre2(data) (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_d_hist2_thrd_auto_sat_i_l_thre2(data) (0x00003FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_get_d_hist2_thrd_auto_sat_i_u_thre2(data) ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST2_INT_THRD_get_d_hist2_thrd_auto_sat_i_l_thre2(data) (0x00003FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD                                     0x1802A150
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg_addr                            "0xB802A150"
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg                                 0xB802A150
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_inst_addr                           "0x0014"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_u_thre3_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_l_thre3_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_u_thre3_mask (0x3FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_l_thre3_mask (0x00003FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_u_thre3(data) (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_d_hist3_thrd_auto_sat_i_l_thre3(data) (0x00003FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_get_d_hist3_thrd_auto_sat_i_u_thre3(data) ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST3_INT_THRD_get_d_hist3_thrd_auto_sat_i_l_thre3(data) (0x00003FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD                                    0x1802A154
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg_addr                           "0xB802A154"
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg                                0xB802A154
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_inst_addr                          "0x0015"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg                            (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist0_thrd_auto_sat_s_thre0_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist1_thrd_auto_sat_s_thre1_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist0_thrd_auto_sat_s_thre0_mask (0x1FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist1_thrd_auto_sat_s_thre1_mask (0x00001FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist0_thrd_auto_sat_s_thre0(data) (0x1FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_d_hist1_thrd_auto_sat_s_thre1(data) (0x00001FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_get_d_hist0_thrd_auto_sat_s_thre0(data) ((0x1FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST01_SAT_THRD_get_d_hist1_thrd_auto_sat_s_thre1(data) (0x00001FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD                                    0x1802A158
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg_addr                           "0xB802A158"
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg                                0xB802A158
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_inst_addr                          "0x0016"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg                            (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist2_thrd_auto_sat_s_thre2_shift (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist3_thrd_auto_sat_s_thre3_shift (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist2_thrd_auto_sat_s_thre2_mask (0x1FFF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist3_thrd_auto_sat_s_thre3_mask (0x00001FFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist2_thrd_auto_sat_s_thre2(data) (0x1FFF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_d_hist3_thrd_auto_sat_s_thre3(data) (0x00001FFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_get_d_hist2_thrd_auto_sat_s_thre2(data) ((0x1FFF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST23_SAT_THRD_get_d_hist3_thrd_auto_sat_s_thre3(data) (0x00001FFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0                                         0x1802A15C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg_addr                                "0xB802A15C"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg                                     0xB802A15C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_inst_addr                               "0x0017"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg(data)                           (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg                                 (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_sta_shift                 (24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_end_shift                 (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_sta_shift                 (8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_end_shift                 (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_sta_mask                  (0xFF000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_end_mask                  (0x00FF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_sta_mask                  (0x0000FF00)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_end_mask                  (0x000000FF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_sta(data)                 (0xFF000000&((data)<<24))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist0_hue_end(data)                 (0x00FF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_sta(data)                 (0x0000FF00&((data)<<8))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_sat_hist1_hue_end(data)                 (0x000000FF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_get_sat_hist0_hue_sta(data)             ((0xFF000000&(data))>>24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_get_sat_hist0_hue_end(data)             ((0x00FF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_get_sat_hist1_hue_sta(data)             ((0x0000FF00&(data))>>8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_get_sat_hist1_hue_end(data)             (0x000000FF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1                                         0x1802A160
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg_addr                                "0xB802A160"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg                                     0xB802A160
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_inst_addr                               "0x0018"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg(data)                           (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg                                 (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_sta_shift                 (24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_end_shift                 (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_sta_shift                 (8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_end_shift                 (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_sta_mask                  (0xFF000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_end_mask                  (0x00FF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_sta_mask                  (0x0000FF00)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_end_mask                  (0x000000FF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_sta(data)                 (0xFF000000&((data)<<24))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist2_hue_end(data)                 (0x00FF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_sta(data)                 (0x0000FF00&((data)<<8))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_sat_hist3_hue_end(data)                 (0x000000FF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_get_sat_hist2_hue_sta(data)             ((0xFF000000&(data))>>24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_get_sat_hist2_hue_end(data)             ((0x00FF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_get_sat_hist3_hue_sta(data)             ((0x0000FF00&(data))>>8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_get_sat_hist3_hue_end(data)             (0x000000FF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL                                     0x1802A164
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg_addr                            "0xB802A164"
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg                                 0xB802A164
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_inst_addr                           "0x0019"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_sram_read_shift                     (31)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_hist_ctrl_shift                     (29)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_cnt_block_shift                     (28)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_sram_read_mask                      (0x80000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_hist_ctrl_mask                      (0x60000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_cnt_block_mask                      (0x10000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_sram_read(data)                     (0x80000000&((data)<<31))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_hist_ctrl(data)                     (0x60000000&((data)<<29))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_cnt_block(data)                     (0x10000000&((data)<<28))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_get_sram_read(data)                 ((0x80000000&(data))>>31)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_get_hist_ctrl(data)                 ((0x60000000&(data))>>29)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_CTRL_get_cnt_block(data)                 ((0x10000000&(data))>>28)

#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS                                  0x1802A168
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg_addr                         "0xB802A168"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg                              0xB802A168
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_inst_addr                        "0x001A"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_sta_status_shift   (24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_end_status_shift   (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_sta_status_shift   (8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_end_status_shift   (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_sta_status_mask    (0xFF000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_end_status_mask    (0x00FF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_sta_status_mask    (0x0000FF00)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_end_status_mask    (0x000000FF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_sta_status(data)   (0xFF000000&((data)<<24))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist0_hue_end_status(data)   (0x00FF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_sta_status(data)   (0x0000FF00&((data)<<8))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_sat_hist1_hue_end_status(data)   (0x000000FF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_get_sat_hist0_hue_sta_status(data) ((0xFF000000&(data))>>24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_get_sat_hist0_hue_end_status(data) ((0x00FF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_get_sat_hist1_hue_sta_status(data) ((0x0000FF00&(data))>>8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL0_STATUS_get_sat_hist1_hue_end_status(data) (0x000000FF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS                                  0x1802A16C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg_addr                         "0xB802A16C"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg                              0xB802A16C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_inst_addr                        "0x001B"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_sta_status_shift   (24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_end_status_shift   (16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_sta_status_shift   (8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_end_status_shift   (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_sta_status_mask    (0xFF000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_end_status_mask    (0x00FF0000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_sta_status_mask    (0x0000FF00)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_end_status_mask    (0x000000FF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_sta_status(data)   (0xFF000000&((data)<<24))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist2_hue_end_status(data)   (0x00FF0000&((data)<<16))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_sta_status(data)   (0x0000FF00&((data)<<8))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_sat_hist3_hue_end_status(data)   (0x000000FF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_get_sat_hist2_hue_sta_status(data) ((0xFF000000&(data))>>24)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_get_sat_hist2_hue_end_status(data) ((0x00FF0000&(data))>>16)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_get_sat_hist3_hue_sta_status(data) ((0x0000FF00&(data))>>8)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CTRL1_STATUS_get_sat_hist3_hue_end_status(data) (0x000000FF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16                                  0x1802A170
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg_addr                         "0xB802A170"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg                              0xB802A170
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_inst_addr                        "0x001C"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_sat_hist_cnt_00_or_16_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_sat_hist_cnt_00_or_16_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_sat_hist_cnt_00_or_16(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_00_OR_16_get_sat_hist_cnt_00_or_16(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17                                  0x1802A174
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg_addr                         "0xB802A174"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg                              0xB802A174
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_inst_addr                        "0x001D"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_sat_hist_cnt_01_or_17_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_sat_hist_cnt_01_or_17_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_sat_hist_cnt_01_or_17(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_01_OR_17_get_sat_hist_cnt_01_or_17(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18                                  0x1802A178
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg_addr                         "0xB802A178"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg                              0xB802A178
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_inst_addr                        "0x001E"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_sat_hist_cnt_02_or_18_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_sat_hist_cnt_02_or_18_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_sat_hist_cnt_02_or_18(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_02_OR_18_get_sat_hist_cnt_02_or_18(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19                                  0x1802A17C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg_addr                         "0xB802A17C"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg                              0xB802A17C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_inst_addr                        "0x001F"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_sat_hist_cnt_03_or_19_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_sat_hist_cnt_03_or_19_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_sat_hist_cnt_03_or_19(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_03_OR_19_get_sat_hist_cnt_03_or_19(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20                                  0x1802A180
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg_addr                         "0xB802A180"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg                              0xB802A180
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_inst_addr                        "0x0020"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_sat_hist_cnt_04_or_20_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_sat_hist_cnt_04_or_20_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_sat_hist_cnt_04_or_20(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_04_OR_20_get_sat_hist_cnt_04_or_20(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21                                  0x1802A184
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg_addr                         "0xB802A184"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg                              0xB802A184
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_inst_addr                        "0x0021"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_sat_hist_cnt_05_or_21_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_sat_hist_cnt_05_or_21_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_sat_hist_cnt_05_or_21(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_05_OR_21_get_sat_hist_cnt_05_or_21(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22                                  0x1802A188
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg_addr                         "0xB802A188"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg                              0xB802A188
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_inst_addr                        "0x0022"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_sat_hist_cnt_06_or_22_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_sat_hist_cnt_06_or_22_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_sat_hist_cnt_06_or_22(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_06_OR_22_get_sat_hist_cnt_06_or_22(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23                                  0x1802A18C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg_addr                         "0xB802A18C"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg                              0xB802A18C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_inst_addr                        "0x0023"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_sat_hist_cnt_07_or_23_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_sat_hist_cnt_07_or_23_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_sat_hist_cnt_07_or_23(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_07_OR_23_get_sat_hist_cnt_07_or_23(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24                                  0x1802A190
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg_addr                         "0xB802A190"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg                              0xB802A190
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_inst_addr                        "0x0024"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_sat_hist_cnt_08_or_24_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_sat_hist_cnt_08_or_24_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_sat_hist_cnt_08_or_24(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_08_OR_24_get_sat_hist_cnt_08_or_24(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25                                  0x1802A194
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg_addr                         "0xB802A194"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg                              0xB802A194
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_inst_addr                        "0x0025"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_sat_hist_cnt_09_or_25_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_sat_hist_cnt_09_or_25_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_sat_hist_cnt_09_or_25(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_09_OR_25_get_sat_hist_cnt_09_or_25(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26                                  0x1802A198
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg_addr                         "0xB802A198"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg                              0xB802A198
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_inst_addr                        "0x0026"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_sat_hist_cnt_10_or_26_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_sat_hist_cnt_10_or_26_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_sat_hist_cnt_10_or_26(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_10_OR_26_get_sat_hist_cnt_10_or_26(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27                                  0x1802A19C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg_addr                         "0xB802A19C"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg                              0xB802A19C
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_inst_addr                        "0x0027"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_sat_hist_cnt_11_or_27_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_sat_hist_cnt_11_or_27_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_sat_hist_cnt_11_or_27(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_11_OR_27_get_sat_hist_cnt_11_or_27(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28                                  0x1802A1A0
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg_addr                         "0xB802A1A0"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg                              0xB802A1A0
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_inst_addr                        "0x0028"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_sat_hist_cnt_12_or_28_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_sat_hist_cnt_12_or_28_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_sat_hist_cnt_12_or_28(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_12_OR_28_get_sat_hist_cnt_12_or_28(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29                                  0x1802A1A4
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg_addr                         "0xB802A1A4"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg                              0xB802A1A4
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_inst_addr                        "0x0029"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_sat_hist_cnt_13_or_29_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_sat_hist_cnt_13_or_29_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_sat_hist_cnt_13_or_29(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_13_OR_29_get_sat_hist_cnt_13_or_29(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30                                  0x1802A1A8
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg_addr                         "0xB802A1A8"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg                              0xB802A1A8
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_inst_addr                        "0x002A"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_sat_hist_cnt_14_or_30_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_sat_hist_cnt_14_or_30_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_sat_hist_cnt_14_or_30(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_14_OR_30_get_sat_hist_cnt_14_or_30(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31                                  0x1802A1AC
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg_addr                         "0xB802A1AC"
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg                              0xB802A1AC
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_inst_addr                        "0x002B"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg                          (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_sat_hist_cnt_15_or_31_shift      (0)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_sat_hist_cnt_15_or_31_mask       (0x00FFFFFF)
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_sat_hist_cnt_15_or_31(data)      (0x00FFFFFF&(data))
#define  COLOR_ICM_D_AUTO_SAT_HIST_CNT_15_OR_31_get_sat_hist_cnt_15_or_31(data)  (0x00FFFFFF&(data))

#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG                                     0x1802A1B0
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg_addr                            "0xB802A1B0"
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg                                 0xB802A1B0
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_inst_addr                           "0x002C"
#define  set_COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg)=data)
#define  get_COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg                             (*((volatile unsigned int*)COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_reg))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_sat_hist_sram_read_consistent_flag_shift (31)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_sat_hist_sram_read_consistent_flag_mask (0x80000000)
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_sat_hist_sram_read_consistent_flag(data) (0x80000000&((data)<<31))
#define  COLOR_ICM_D_AUTO_SAT_HIST_READ_FLAG_get_sat_hist_sram_read_consistent_flag(data) ((0x80000000&(data))>>31)

#define  COLOR_ICM_ICM_AUTO_CTRL                                                 0x1802A1B4
#define  COLOR_ICM_ICM_AUTO_CTRL_reg_addr                                        "0xB802A1B4"
#define  COLOR_ICM_ICM_AUTO_CTRL_reg                                             0xB802A1B4
#define  COLOR_ICM_ICM_AUTO_CTRL_inst_addr                                       "0x002D"
#define  set_COLOR_ICM_ICM_AUTO_CTRL_reg(data)                                   (*((volatile unsigned int*)COLOR_ICM_ICM_AUTO_CTRL_reg)=data)
#define  get_COLOR_ICM_ICM_AUTO_CTRL_reg                                         (*((volatile unsigned int*)COLOR_ICM_ICM_AUTO_CTRL_reg))
#define  COLOR_ICM_ICM_AUTO_CTRL_icm_auto_ctrl_hue_hist_mode_sel_shift           (4)
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_ok_shift                               (2)
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_enable_shift                           (1)
#define  COLOR_ICM_ICM_AUTO_CTRL_inside_enable_shift                             (0)
#define  COLOR_ICM_ICM_AUTO_CTRL_icm_auto_ctrl_hue_hist_mode_sel_mask            (0x00000010)
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_ok_mask                                (0x00000004)
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_enable_mask                            (0x00000002)
#define  COLOR_ICM_ICM_AUTO_CTRL_inside_enable_mask                              (0x00000001)
#define  COLOR_ICM_ICM_AUTO_CTRL_icm_auto_ctrl_hue_hist_mode_sel(data)           (0x00000010&((data)<<4))
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_ok(data)                               (0x00000004&((data)<<2))
#define  COLOR_ICM_ICM_AUTO_CTRL_hist_hue_enable(data)                           (0x00000002&((data)<<1))
#define  COLOR_ICM_ICM_AUTO_CTRL_inside_enable(data)                             (0x00000001&(data))
#define  COLOR_ICM_ICM_AUTO_CTRL_get_icm_auto_ctrl_hue_hist_mode_sel(data)       ((0x00000010&(data))>>4)
#define  COLOR_ICM_ICM_AUTO_CTRL_get_hist_hue_ok(data)                           ((0x00000004&(data))>>2)
#define  COLOR_ICM_ICM_AUTO_CTRL_get_hist_hue_enable(data)                       ((0x00000002&(data))>>1)
#define  COLOR_ICM_ICM_AUTO_CTRL_get_inside_enable(data)                         (0x00000001&(data))

#define  COLOR_ICM_HUE_HIST_SETTINGS0                                            0x1802A1B8
#define  COLOR_ICM_HUE_HIST_SETTINGS0_reg_addr                                   "0xB802A1B8"
#define  COLOR_ICM_HUE_HIST_SETTINGS0_reg                                        0xB802A1B8
#define  COLOR_ICM_HUE_HIST_SETTINGS0_inst_addr                                  "0x002E"
#define  set_COLOR_ICM_HUE_HIST_SETTINGS0_reg(data)                              (*((volatile unsigned int*)COLOR_ICM_HUE_HIST_SETTINGS0_reg)=data)
#define  get_COLOR_ICM_HUE_HIST_SETTINGS0_reg                                    (*((volatile unsigned int*)COLOR_ICM_HUE_HIST_SETTINGS0_reg))
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_offset_add_shift                  (16)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_sat_lb_shift                      (0)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_offset_add_mask                   (0x00FF0000)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_sat_lb_mask                       (0x00001FFF)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_offset_add(data)                  (0x00FF0000&((data)<<16))
#define  COLOR_ICM_HUE_HIST_SETTINGS0_hue_hist_sat_lb(data)                      (0x00001FFF&(data))
#define  COLOR_ICM_HUE_HIST_SETTINGS0_get_hue_hist_offset_add(data)              ((0x00FF0000&(data))>>16)
#define  COLOR_ICM_HUE_HIST_SETTINGS0_get_hue_hist_sat_lb(data)                  (0x00001FFF&(data))

#define  COLOR_ICM_HUE_HIST_SETTINGS1                                            0x1802A1BC
#define  COLOR_ICM_HUE_HIST_SETTINGS1_reg_addr                                   "0xB802A1BC"
#define  COLOR_ICM_HUE_HIST_SETTINGS1_reg                                        0xB802A1BC
#define  COLOR_ICM_HUE_HIST_SETTINGS1_inst_addr                                  "0x002F"
#define  set_COLOR_ICM_HUE_HIST_SETTINGS1_reg(data)                              (*((volatile unsigned int*)COLOR_ICM_HUE_HIST_SETTINGS1_reg)=data)
#define  get_COLOR_ICM_HUE_HIST_SETTINGS1_reg                                    (*((volatile unsigned int*)COLOR_ICM_HUE_HIST_SETTINGS1_reg))
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_hb_shift                      (16)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_lb_shift                      (0)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_hb_mask                       (0x3FFF0000)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_lb_mask                       (0x00003FFF)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_hb(data)                      (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_HUE_HIST_SETTINGS1_hue_hist_itn_lb(data)                      (0x00003FFF&(data))
#define  COLOR_ICM_HUE_HIST_SETTINGS1_get_hue_hist_itn_hb(data)                  ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_HUE_HIST_SETTINGS1_get_hue_hist_itn_lb(data)                  (0x00003FFF&(data))

#define  COLOR_ICM_HUE_COUNT_00                                                  0x1802A1C0
#define  COLOR_ICM_HUE_COUNT_00_reg_addr                                         "0xB802A1C0"
#define  COLOR_ICM_HUE_COUNT_00_reg                                              0xB802A1C0
#define  COLOR_ICM_HUE_COUNT_00_inst_addr                                        "0x0030"
#define  set_COLOR_ICM_HUE_COUNT_00_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_00_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_00_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_00_reg))
#define  COLOR_ICM_HUE_COUNT_00_hue_count_00_lut0_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_00_hue_count_00_lut0_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_00_hue_count_00_lut0(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_00_get_hue_count_00_lut0(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_01                                                  0x1802A1C4
#define  COLOR_ICM_HUE_COUNT_01_reg_addr                                         "0xB802A1C4"
#define  COLOR_ICM_HUE_COUNT_01_reg                                              0xB802A1C4
#define  COLOR_ICM_HUE_COUNT_01_inst_addr                                        "0x0031"
#define  set_COLOR_ICM_HUE_COUNT_01_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_01_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_01_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_01_reg))
#define  COLOR_ICM_HUE_COUNT_01_hue_count_01_lut1_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_01_hue_count_01_lut1_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_01_hue_count_01_lut1(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_01_get_hue_count_01_lut1(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_02                                                  0x1802A1C8
#define  COLOR_ICM_HUE_COUNT_02_reg_addr                                         "0xB802A1C8"
#define  COLOR_ICM_HUE_COUNT_02_reg                                              0xB802A1C8
#define  COLOR_ICM_HUE_COUNT_02_inst_addr                                        "0x0032"
#define  set_COLOR_ICM_HUE_COUNT_02_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_02_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_02_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_02_reg))
#define  COLOR_ICM_HUE_COUNT_02_hue_count_02_lut2_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_02_hue_count_02_lut2_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_02_hue_count_02_lut2(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_02_get_hue_count_02_lut2(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_03                                                  0x1802A1CC
#define  COLOR_ICM_HUE_COUNT_03_reg_addr                                         "0xB802A1CC"
#define  COLOR_ICM_HUE_COUNT_03_reg                                              0xB802A1CC
#define  COLOR_ICM_HUE_COUNT_03_inst_addr                                        "0x0033"
#define  set_COLOR_ICM_HUE_COUNT_03_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_03_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_03_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_03_reg))
#define  COLOR_ICM_HUE_COUNT_03_hue_count_03_lut3_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_03_hue_count_03_lut3_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_03_hue_count_03_lut3(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_03_get_hue_count_03_lut3(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_04                                                  0x1802A1D0
#define  COLOR_ICM_HUE_COUNT_04_reg_addr                                         "0xB802A1D0"
#define  COLOR_ICM_HUE_COUNT_04_reg                                              0xB802A1D0
#define  COLOR_ICM_HUE_COUNT_04_inst_addr                                        "0x0034"
#define  set_COLOR_ICM_HUE_COUNT_04_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_04_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_04_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_04_reg))
#define  COLOR_ICM_HUE_COUNT_04_hue_count_04_lut4_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_04_hue_count_04_lut4_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_04_hue_count_04_lut4(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_04_get_hue_count_04_lut4(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_05                                                  0x1802A1D4
#define  COLOR_ICM_HUE_COUNT_05_reg_addr                                         "0xB802A1D4"
#define  COLOR_ICM_HUE_COUNT_05_reg                                              0xB802A1D4
#define  COLOR_ICM_HUE_COUNT_05_inst_addr                                        "0x0035"
#define  set_COLOR_ICM_HUE_COUNT_05_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_05_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_05_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_05_reg))
#define  COLOR_ICM_HUE_COUNT_05_hue_count_05_lut5_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_05_hue_count_05_lut5_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_05_hue_count_05_lut5(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_05_get_hue_count_05_lut5(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_06                                                  0x1802A1D8
#define  COLOR_ICM_HUE_COUNT_06_reg_addr                                         "0xB802A1D8"
#define  COLOR_ICM_HUE_COUNT_06_reg                                              0xB802A1D8
#define  COLOR_ICM_HUE_COUNT_06_inst_addr                                        "0x0036"
#define  set_COLOR_ICM_HUE_COUNT_06_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_06_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_06_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_06_reg))
#define  COLOR_ICM_HUE_COUNT_06_hue_count_06_lut6_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_06_hue_count_06_lut6_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_06_hue_count_06_lut6(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_06_get_hue_count_06_lut6(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_07                                                  0x1802A1DC
#define  COLOR_ICM_HUE_COUNT_07_reg_addr                                         "0xB802A1DC"
#define  COLOR_ICM_HUE_COUNT_07_reg                                              0xB802A1DC
#define  COLOR_ICM_HUE_COUNT_07_inst_addr                                        "0x0037"
#define  set_COLOR_ICM_HUE_COUNT_07_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_07_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_07_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_07_reg))
#define  COLOR_ICM_HUE_COUNT_07_hue_count_07_lut7_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_07_hue_count_07_lut7_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_07_hue_count_07_lut7(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_07_get_hue_count_07_lut7(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_08                                                  0x1802A1E0
#define  COLOR_ICM_HUE_COUNT_08_reg_addr                                         "0xB802A1E0"
#define  COLOR_ICM_HUE_COUNT_08_reg                                              0xB802A1E0
#define  COLOR_ICM_HUE_COUNT_08_inst_addr                                        "0x0038"
#define  set_COLOR_ICM_HUE_COUNT_08_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_08_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_08_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_08_reg))
#define  COLOR_ICM_HUE_COUNT_08_hue_count_08_lut8_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_08_hue_count_08_lut8_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_08_hue_count_08_lut8(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_08_get_hue_count_08_lut8(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_09                                                  0x1802A1E4
#define  COLOR_ICM_HUE_COUNT_09_reg_addr                                         "0xB802A1E4"
#define  COLOR_ICM_HUE_COUNT_09_reg                                              0xB802A1E4
#define  COLOR_ICM_HUE_COUNT_09_inst_addr                                        "0x0039"
#define  set_COLOR_ICM_HUE_COUNT_09_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_09_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_09_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_09_reg))
#define  COLOR_ICM_HUE_COUNT_09_hue_count_09_lut9_shift                          (0)
#define  COLOR_ICM_HUE_COUNT_09_hue_count_09_lut9_mask                           (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_09_hue_count_09_lut9(data)                          (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_09_get_hue_count_09_lut9(data)                      (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0A                                                  0x1802A1E8
#define  COLOR_ICM_HUE_COUNT_0A_reg_addr                                         "0xB802A1E8"
#define  COLOR_ICM_HUE_COUNT_0A_reg                                              0xB802A1E8
#define  COLOR_ICM_HUE_COUNT_0A_inst_addr                                        "0x003A"
#define  set_COLOR_ICM_HUE_COUNT_0A_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0A_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0A_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0A_reg))
#define  COLOR_ICM_HUE_COUNT_0A_hue_count_0a_lut10_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0A_hue_count_0a_lut10_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0A_hue_count_0a_lut10(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0A_get_hue_count_0a_lut10(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0B                                                  0x1802A1EC
#define  COLOR_ICM_HUE_COUNT_0B_reg_addr                                         "0xB802A1EC"
#define  COLOR_ICM_HUE_COUNT_0B_reg                                              0xB802A1EC
#define  COLOR_ICM_HUE_COUNT_0B_inst_addr                                        "0x003B"
#define  set_COLOR_ICM_HUE_COUNT_0B_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0B_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0B_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0B_reg))
#define  COLOR_ICM_HUE_COUNT_0B_hue_count_0b_lut11_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0B_hue_count_0b_lut11_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0B_hue_count_0b_lut11(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0B_get_hue_count_0b_lut11(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0C                                                  0x1802A1F0
#define  COLOR_ICM_HUE_COUNT_0C_reg_addr                                         "0xB802A1F0"
#define  COLOR_ICM_HUE_COUNT_0C_reg                                              0xB802A1F0
#define  COLOR_ICM_HUE_COUNT_0C_inst_addr                                        "0x003C"
#define  set_COLOR_ICM_HUE_COUNT_0C_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0C_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0C_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0C_reg))
#define  COLOR_ICM_HUE_COUNT_0C_hue_count_0c_lut12_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0C_hue_count_0c_lut12_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0C_hue_count_0c_lut12(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0C_get_hue_count_0c_lut12(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0D                                                  0x1802A1F4
#define  COLOR_ICM_HUE_COUNT_0D_reg_addr                                         "0xB802A1F4"
#define  COLOR_ICM_HUE_COUNT_0D_reg                                              0xB802A1F4
#define  COLOR_ICM_HUE_COUNT_0D_inst_addr                                        "0x003D"
#define  set_COLOR_ICM_HUE_COUNT_0D_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0D_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0D_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0D_reg))
#define  COLOR_ICM_HUE_COUNT_0D_hue_count_0d_lut13_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0D_hue_count_0d_lut13_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0D_hue_count_0d_lut13(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0D_get_hue_count_0d_lut13(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0E                                                  0x1802A1F8
#define  COLOR_ICM_HUE_COUNT_0E_reg_addr                                         "0xB802A1F8"
#define  COLOR_ICM_HUE_COUNT_0E_reg                                              0xB802A1F8
#define  COLOR_ICM_HUE_COUNT_0E_inst_addr                                        "0x003E"
#define  set_COLOR_ICM_HUE_COUNT_0E_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0E_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0E_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0E_reg))
#define  COLOR_ICM_HUE_COUNT_0E_hue_count_0e_lut14_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0E_hue_count_0e_lut14_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0E_hue_count_0e_lut14(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0E_get_hue_count_0e_lut14(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_0F                                                  0x1802A1FC
#define  COLOR_ICM_HUE_COUNT_0F_reg_addr                                         "0xB802A1FC"
#define  COLOR_ICM_HUE_COUNT_0F_reg                                              0xB802A1FC
#define  COLOR_ICM_HUE_COUNT_0F_inst_addr                                        "0x003F"
#define  set_COLOR_ICM_HUE_COUNT_0F_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0F_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_0F_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_0F_reg))
#define  COLOR_ICM_HUE_COUNT_0F_hue_count_0f_lut15_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_0F_hue_count_0f_lut15_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_0F_hue_count_0f_lut15(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_0F_get_hue_count_0f_lut15(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_10                                                  0x1802A200
#define  COLOR_ICM_HUE_COUNT_10_reg_addr                                         "0xB802A200"
#define  COLOR_ICM_HUE_COUNT_10_reg                                              0xB802A200
#define  COLOR_ICM_HUE_COUNT_10_inst_addr                                        "0x0040"
#define  set_COLOR_ICM_HUE_COUNT_10_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_10_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_10_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_10_reg))
#define  COLOR_ICM_HUE_COUNT_10_hue_count_10_lut16_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_10_hue_count_10_lut16_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_10_hue_count_10_lut16(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_10_get_hue_count_10_lut16(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_11                                                  0x1802A204
#define  COLOR_ICM_HUE_COUNT_11_reg_addr                                         "0xB802A204"
#define  COLOR_ICM_HUE_COUNT_11_reg                                              0xB802A204
#define  COLOR_ICM_HUE_COUNT_11_inst_addr                                        "0x0041"
#define  set_COLOR_ICM_HUE_COUNT_11_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_11_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_11_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_11_reg))
#define  COLOR_ICM_HUE_COUNT_11_hue_count_11_lut17_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_11_hue_count_11_lut17_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_11_hue_count_11_lut17(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_11_get_hue_count_11_lut17(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_12                                                  0x1802A208
#define  COLOR_ICM_HUE_COUNT_12_reg_addr                                         "0xB802A208"
#define  COLOR_ICM_HUE_COUNT_12_reg                                              0xB802A208
#define  COLOR_ICM_HUE_COUNT_12_inst_addr                                        "0x0042"
#define  set_COLOR_ICM_HUE_COUNT_12_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_12_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_12_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_12_reg))
#define  COLOR_ICM_HUE_COUNT_12_hue_count_12_lut18_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_12_hue_count_12_lut18_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_12_hue_count_12_lut18(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_12_get_hue_count_12_lut18(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_13                                                  0x1802A20C
#define  COLOR_ICM_HUE_COUNT_13_reg_addr                                         "0xB802A20C"
#define  COLOR_ICM_HUE_COUNT_13_reg                                              0xB802A20C
#define  COLOR_ICM_HUE_COUNT_13_inst_addr                                        "0x0043"
#define  set_COLOR_ICM_HUE_COUNT_13_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_13_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_13_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_13_reg))
#define  COLOR_ICM_HUE_COUNT_13_hue_count_13_lut19_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_13_hue_count_13_lut19_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_13_hue_count_13_lut19(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_13_get_hue_count_13_lut19(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_14                                                  0x1802A210
#define  COLOR_ICM_HUE_COUNT_14_reg_addr                                         "0xB802A210"
#define  COLOR_ICM_HUE_COUNT_14_reg                                              0xB802A210
#define  COLOR_ICM_HUE_COUNT_14_inst_addr                                        "0x0044"
#define  set_COLOR_ICM_HUE_COUNT_14_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_14_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_14_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_14_reg))
#define  COLOR_ICM_HUE_COUNT_14_hue_count_14_lut20_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_14_hue_count_14_lut20_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_14_hue_count_14_lut20(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_14_get_hue_count_14_lut20(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_15                                                  0x1802A214
#define  COLOR_ICM_HUE_COUNT_15_reg_addr                                         "0xB802A214"
#define  COLOR_ICM_HUE_COUNT_15_reg                                              0xB802A214
#define  COLOR_ICM_HUE_COUNT_15_inst_addr                                        "0x0045"
#define  set_COLOR_ICM_HUE_COUNT_15_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_15_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_15_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_15_reg))
#define  COLOR_ICM_HUE_COUNT_15_hue_count_15_lut21_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_15_hue_count_15_lut21_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_15_hue_count_15_lut21(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_15_get_hue_count_15_lut21(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_16                                                  0x1802A218
#define  COLOR_ICM_HUE_COUNT_16_reg_addr                                         "0xB802A218"
#define  COLOR_ICM_HUE_COUNT_16_reg                                              0xB802A218
#define  COLOR_ICM_HUE_COUNT_16_inst_addr                                        "0x0046"
#define  set_COLOR_ICM_HUE_COUNT_16_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_16_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_16_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_16_reg))
#define  COLOR_ICM_HUE_COUNT_16_hue_count_16_lut22_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_16_hue_count_16_lut22_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_16_hue_count_16_lut22(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_16_get_hue_count_16_lut22(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_COUNT_17                                                  0x1802A21C
#define  COLOR_ICM_HUE_COUNT_17_reg_addr                                         "0xB802A21C"
#define  COLOR_ICM_HUE_COUNT_17_reg                                              0xB802A21C
#define  COLOR_ICM_HUE_COUNT_17_inst_addr                                        "0x0047"
#define  set_COLOR_ICM_HUE_COUNT_17_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_17_reg)=data)
#define  get_COLOR_ICM_HUE_COUNT_17_reg                                          (*((volatile unsigned int*)COLOR_ICM_HUE_COUNT_17_reg))
#define  COLOR_ICM_HUE_COUNT_17_hue_count_17_lut23_shift                         (0)
#define  COLOR_ICM_HUE_COUNT_17_hue_count_17_lut23_mask                          (0x00FFFFFF)
#define  COLOR_ICM_HUE_COUNT_17_hue_count_17_lut23(data)                         (0x00FFFFFF&(data))
#define  COLOR_ICM_HUE_COUNT_17_get_hue_count_17_lut23(data)                     (0x00FFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_00                                                    0x1802A220
#define  COLOR_ICM_HUE_SUM_00_reg_addr                                           "0xB802A220"
#define  COLOR_ICM_HUE_SUM_00_reg                                                0xB802A220
#define  COLOR_ICM_HUE_SUM_00_inst_addr                                          "0x0048"
#define  set_COLOR_ICM_HUE_SUM_00_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_00_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_00_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_00_reg))
#define  COLOR_ICM_HUE_SUM_00_hue_sum_00_lut0_shift                              (0)
#define  COLOR_ICM_HUE_SUM_00_hue_sum_00_lut0_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_00_hue_sum_00_lut0(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_00_get_hue_sum_00_lut0(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_01                                                    0x1802A224
#define  COLOR_ICM_HUE_SUM_01_reg_addr                                           "0xB802A224"
#define  COLOR_ICM_HUE_SUM_01_reg                                                0xB802A224
#define  COLOR_ICM_HUE_SUM_01_inst_addr                                          "0x0049"
#define  set_COLOR_ICM_HUE_SUM_01_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_01_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_01_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_01_reg))
#define  COLOR_ICM_HUE_SUM_01_hue_sum_01_lut1_shift                              (0)
#define  COLOR_ICM_HUE_SUM_01_hue_sum_01_lut1_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_01_hue_sum_01_lut1(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_01_get_hue_sum_01_lut1(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_02                                                    0x1802A228
#define  COLOR_ICM_HUE_SUM_02_reg_addr                                           "0xB802A228"
#define  COLOR_ICM_HUE_SUM_02_reg                                                0xB802A228
#define  COLOR_ICM_HUE_SUM_02_inst_addr                                          "0x004A"
#define  set_COLOR_ICM_HUE_SUM_02_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_02_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_02_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_02_reg))
#define  COLOR_ICM_HUE_SUM_02_hue_sum_02_lut2_shift                              (0)
#define  COLOR_ICM_HUE_SUM_02_hue_sum_02_lut2_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_02_hue_sum_02_lut2(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_02_get_hue_sum_02_lut2(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_03                                                    0x1802A22C
#define  COLOR_ICM_HUE_SUM_03_reg_addr                                           "0xB802A22C"
#define  COLOR_ICM_HUE_SUM_03_reg                                                0xB802A22C
#define  COLOR_ICM_HUE_SUM_03_inst_addr                                          "0x004B"
#define  set_COLOR_ICM_HUE_SUM_03_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_03_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_03_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_03_reg))
#define  COLOR_ICM_HUE_SUM_03_hue_sum_03_lut3_shift                              (0)
#define  COLOR_ICM_HUE_SUM_03_hue_sum_03_lut3_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_03_hue_sum_03_lut3(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_03_get_hue_sum_03_lut3(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_04                                                    0x1802A230
#define  COLOR_ICM_HUE_SUM_04_reg_addr                                           "0xB802A230"
#define  COLOR_ICM_HUE_SUM_04_reg                                                0xB802A230
#define  COLOR_ICM_HUE_SUM_04_inst_addr                                          "0x004C"
#define  set_COLOR_ICM_HUE_SUM_04_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_04_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_04_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_04_reg))
#define  COLOR_ICM_HUE_SUM_04_hue_sum_04_lut4_shift                              (0)
#define  COLOR_ICM_HUE_SUM_04_hue_sum_04_lut4_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_04_hue_sum_04_lut4(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_04_get_hue_sum_04_lut4(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_HUE_SUM_05                                                    0x1802A234
#define  COLOR_ICM_HUE_SUM_05_reg_addr                                           "0xB802A234"
#define  COLOR_ICM_HUE_SUM_05_reg                                                0xB802A234
#define  COLOR_ICM_HUE_SUM_05_inst_addr                                          "0x004D"
#define  set_COLOR_ICM_HUE_SUM_05_reg(data)                                      (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_05_reg)=data)
#define  get_COLOR_ICM_HUE_SUM_05_reg                                            (*((volatile unsigned int*)COLOR_ICM_HUE_SUM_05_reg))
#define  COLOR_ICM_HUE_SUM_05_hue_sum_05_lut5_shift                              (0)
#define  COLOR_ICM_HUE_SUM_05_hue_sum_05_lut5_mask                               (0x7FFFFFFF)
#define  COLOR_ICM_HUE_SUM_05_hue_sum_05_lut5(data)                              (0x7FFFFFFF&(data))
#define  COLOR_ICM_HUE_SUM_05_get_hue_sum_05_lut5(data)                          (0x7FFFFFFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL                                       0x1802A23C
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg_addr                              "0xB802A23C"
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg                                   0xB802A23C
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_inst_addr                             "0x004E"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_dmato3dlut_en_shift                   (30)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_h_shift                  (24)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_s_shift                  (20)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_i_shift                  (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_hw_fw_priority_opt_shift              (5)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_type_shift                       (4)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_sel_shift                        (3)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_random_access_en_shift          (2)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_en_shift                        (1)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_en_shift                         (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_dmato3dlut_en_mask                    (0x40000000)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_h_mask                   (0x3F000000)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_s_mask                   (0x00F00000)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_i_mask                   (0x000F0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_hw_fw_priority_opt_mask               (0x00000020)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_type_mask                        (0x00000010)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_sel_mask                         (0x00000008)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_random_access_en_mask           (0x00000004)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_en_mask                         (0x00000002)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_en_mask                          (0x00000001)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_dmato3dlut_en(data)                   (0x40000000&((data)<<30))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_h(data)                  (0x3F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_s(data)                  (0x00F00000&((data)<<20))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_addrres_i(data)                  (0x000F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_hw_fw_priority_opt(data)              (0x00000020&((data)<<5))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_sram_type(data)                       (0x00000010&((data)<<4))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_sel(data)                        (0x00000008&((data)<<3))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_random_access_en(data)          (0x00000004&((data)<<2))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_write_en(data)                        (0x00000002&((data)<<1))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_read_en(data)                         (0x00000001&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_dmato3dlut_en(data)               ((0x40000000&(data))>>30)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_sram_addrres_h(data)              ((0x3F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_sram_addrres_s(data)              ((0x00F00000&(data))>>20)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_sram_addrres_i(data)              ((0x000F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_hw_fw_priority_opt(data)          ((0x00000020&(data))>>5)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_sram_type(data)                   ((0x00000010&(data))>>4)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_read_sel(data)                    ((0x00000008&(data))>>3)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_write_random_access_en(data)      ((0x00000004&(data))>>2)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_write_en(data)                    ((0x00000002&(data))>>1)
#define  COLOR_ICM_DM_ICM_3D_TAB_SRAM_CTRL_get_read_en(data)                     (0x00000001&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00                                    0x1802A240
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg_addr                           "0xB802A240"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg                                0xB802A240
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_inst_addr                          "0x004F"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_h0_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_s0_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_h0_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_s0_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_h0(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_write_table_s0(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_get_write_table_h0(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_00_get_write_table_s0(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01                                    0x1802A244
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg_addr                           "0xB802A244"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg                                0xB802A244
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_inst_addr                          "0x0050"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_write_table_i0_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_write_table_i0_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_write_table_i0(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_01_get_write_table_i0(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10                                    0x1802A248
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg_addr                           "0xB802A248"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg                                0xB802A248
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_inst_addr                          "0x0051"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_h1_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_s1_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_h1_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_s1_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_h1(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_write_table_s1(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_get_write_table_h1(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_10_get_write_table_s1(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11                                    0x1802A24C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg_addr                           "0xB802A24C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg                                0xB802A24C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_inst_addr                          "0x0052"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_write_table_i1_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_write_table_i1_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_write_table_i1(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_11_get_write_table_i1(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20                                    0x1802A250
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg_addr                           "0xB802A250"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg                                0xB802A250
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_inst_addr                          "0x0053"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_h2_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_s2_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_h2_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_s2_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_h2(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_write_table_s2(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_get_write_table_h2(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_20_get_write_table_s2(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21                                    0x1802A254
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg_addr                           "0xB802A254"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg                                0xB802A254
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_inst_addr                          "0x0054"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_write_table_i2_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_write_table_i2_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_write_table_i2(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_21_get_write_table_i2(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30                                    0x1802A258
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg_addr                           "0xB802A258"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg                                0xB802A258
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_inst_addr                          "0x0055"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_h3_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_s3_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_h3_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_s3_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_h3(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_write_table_s3(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_get_write_table_h3(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_30_get_write_table_s3(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31                                    0x1802A25C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg_addr                           "0xB802A25C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg                                0xB802A25C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_inst_addr                          "0x0056"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_write_table_i3_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_write_table_i3_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_write_table_i3(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_31_get_write_table_i3(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40                                    0x1802A260
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg_addr                           "0xB802A260"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg                                0xB802A260
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_inst_addr                          "0x0057"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_h4_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_s4_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_h4_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_s4_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_h4(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_write_table_s4(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_get_write_table_h4(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_40_get_write_table_s4(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41                                    0x1802A264
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg_addr                           "0xB802A264"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg                                0xB802A264
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_inst_addr                          "0x0058"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_write_table_i4_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_write_table_i4_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_write_table_i4(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_41_get_write_table_i4(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50                                    0x1802A268
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg_addr                           "0xB802A268"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg                                0xB802A268
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_inst_addr                          "0x0059"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_h5_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_s5_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_h5_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_s5_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_h5(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_write_table_s5(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_get_write_table_h5(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_50_get_write_table_s5(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51                                    0x1802A26C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg_addr                           "0xB802A26C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg                                0xB802A26C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_inst_addr                          "0x005A"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_write_table_i5_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_write_table_i5_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_write_table_i5(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_51_get_write_table_i5(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60                                    0x1802A270
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg_addr                           "0xB802A270"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg                                0xB802A270
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_inst_addr                          "0x005B"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_h6_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_s6_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_h6_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_s6_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_h6(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_write_table_s6(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_get_write_table_h6(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_60_get_write_table_s6(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61                                    0x1802A274
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg_addr                           "0xB802A274"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg                                0xB802A274
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_inst_addr                          "0x005C"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_write_table_i6_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_write_table_i6_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_write_table_i6(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_61_get_write_table_i6(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70                                    0x1802A278
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg_addr                           "0xB802A278"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg                                0xB802A278
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_inst_addr                          "0x005D"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_h7_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_s7_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_h7_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_s7_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_h7(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_write_table_s7(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_get_write_table_h7(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_70_get_write_table_s7(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71                                    0x1802A27C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg_addr                           "0xB802A27C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg                                0xB802A27C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_inst_addr                          "0x005E"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_write_table_i7_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_write_table_i7_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_write_table_i7(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_71_get_write_table_i7(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80                                    0x1802A280
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg_addr                           "0xB802A280"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg                                0xB802A280
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_inst_addr                          "0x005F"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_h8_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_s8_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_h8_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_s8_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_h8(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_write_table_s8(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_get_write_table_h8(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_80_get_write_table_s8(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81                                    0x1802A284
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg_addr                           "0xB802A284"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg                                0xB802A284
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_inst_addr                          "0x0060"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_write_table_i8_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_write_table_i8_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_write_table_i8(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_81_get_write_table_i8(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90                                    0x1802A288
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg_addr                           "0xB802A288"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg                                0xB802A288
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_inst_addr                          "0x0061"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_h9_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_s9_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_h9_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_s9_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_h9(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_write_table_s9(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_get_write_table_h9(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_90_get_write_table_s9(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91                                    0x1802A28C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg_addr                           "0xB802A28C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg                                0xB802A28C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_inst_addr                          "0x0062"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_write_table_i9_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_write_table_i9_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_write_table_i9(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_91_get_write_table_i9(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0                                    0x1802A290
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg_addr                           "0xB802A290"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg                                0xB802A290
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_inst_addr                          "0x0063"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_ha_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_sa_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_ha_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_sa_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_ha(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_write_table_sa(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_get_write_table_ha(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A0_get_write_table_sa(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1                                    0x1802A294
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg_addr                           "0xB802A294"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg                                0xB802A294
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_inst_addr                          "0x0064"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_write_table_ia_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_write_table_ia_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_write_table_ia(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_A1_get_write_table_ia(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0                                    0x1802A298
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg_addr                           "0xB802A298"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg                                0xB802A298
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_inst_addr                          "0x0065"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_hb_shift               (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_sb_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_hb_mask                (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_sb_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_hb(data)               (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_write_table_sb(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_get_write_table_hb(data)           ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B0_get_write_table_sb(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1                                    0x1802A29C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg_addr                           "0xB802A29C"
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg                                0xB802A29C
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_inst_addr                          "0x0066"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg                            (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_write_table_ib_shift               (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_write_table_ib_mask                (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_write_table_ib(data)               (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_WRITE_HSI_B1_get_write_table_ib(data)           (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00                                     0x1802A2A0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg_addr                            "0xB802A2A0"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg                                 0xB802A2A0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_inst_addr                           "0x0067"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_h0_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_s0_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_h0_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_s0_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_h0(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_read_table_s0(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_get_read_table_h0(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_00_get_read_table_s0(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01                                     0x1802A2A4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg_addr                            "0xB802A2A4"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg                                 0xB802A2A4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_inst_addr                           "0x0068"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_read_table_i0_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_read_table_i0_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_read_table_i0(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_01_get_read_table_i0(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10                                     0x1802A2A8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg_addr                            "0xB802A2A8"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg                                 0xB802A2A8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_inst_addr                           "0x0069"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_h1_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_s1_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_h1_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_s1_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_h1(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_read_table_s1(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_get_read_table_h1(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_10_get_read_table_s1(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11                                     0x1802A2AC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg_addr                            "0xB802A2AC"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg                                 0xB802A2AC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_inst_addr                           "0x006A"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_read_table_i1_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_read_table_i1_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_read_table_i1(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_11_get_read_table_i1(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20                                     0x1802A2B0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg_addr                            "0xB802A2B0"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg                                 0xB802A2B0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_inst_addr                           "0x006B"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_h2_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_s2_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_h2_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_s2_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_h2(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_read_table_s2(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_get_read_table_h2(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_20_get_read_table_s2(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21                                     0x1802A2B4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg_addr                            "0xB802A2B4"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg                                 0xB802A2B4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_inst_addr                           "0x006C"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_read_table_i2_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_read_table_i2_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_read_table_i2(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_21_get_read_table_i2(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30                                     0x1802A2B8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg_addr                            "0xB802A2B8"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg                                 0xB802A2B8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_inst_addr                           "0x006D"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_h3_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_s3_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_h3_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_s3_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_h3(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_read_table_s3(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_get_read_table_h3(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_30_get_read_table_s3(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31                                     0x1802A2BC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg_addr                            "0xB802A2BC"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg                                 0xB802A2BC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_inst_addr                           "0x006E"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_read_table_i3_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_read_table_i3_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_read_table_i3(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_31_get_read_table_i3(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40                                     0x1802A2C0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg_addr                            "0xB802A2C0"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg                                 0xB802A2C0
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_inst_addr                           "0x006F"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_h4_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_s4_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_h4_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_s4_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_h4(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_read_table_s4(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_get_read_table_h4(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_40_get_read_table_s4(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41                                     0x1802A2C4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg_addr                            "0xB802A2C4"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg                                 0xB802A2C4
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_inst_addr                           "0x0070"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_read_table_i4_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_read_table_i4_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_read_table_i4(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_41_get_read_table_i4(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50                                     0x1802A2C8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg_addr                            "0xB802A2C8"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg                                 0xB802A2C8
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_inst_addr                           "0x0071"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_h5_shift                 (16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_s5_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_h5_mask                  (0x07FF0000)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_s5_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_h5(data)                 (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_read_table_s5(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_get_read_table_h5(data)             ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_50_get_read_table_s5(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51                                     0x1802A2CC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg_addr                            "0xB802A2CC"
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg                                 0xB802A2CC
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_inst_addr                           "0x0072"
#define  set_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg)=data)
#define  get_COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_reg))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_read_table_i5_shift                 (0)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_read_table_i5_mask                  (0x00001FFF)
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_read_table_i5(data)                 (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_3D_TAB_READ_HSI_51_get_read_table_i5(data)             (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_AccessData_CTRL                                        0x1802A2D0
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_reg_addr                               "0xB802A2D0"
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_reg                                    0xB802A2D0
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_inst_addr                              "0x0073"
#define  set_COLOR_ICM_DM_ICM_AccessData_CTRL_reg(data)                          (*((volatile unsigned int*)COLOR_ICM_DM_ICM_AccessData_CTRL_reg)=data)
#define  get_COLOR_ICM_DM_ICM_AccessData_CTRL_reg                                (*((volatile unsigned int*)COLOR_ICM_DM_ICM_AccessData_CTRL_reg))
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_write_en_shift              (1)
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_read_en_shift               (0)
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_write_en_mask               (0x00000002)
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_read_en_mask                (0x00000001)
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_write_en(data)              (0x00000002&((data)<<1))
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_accessdata_read_en(data)               (0x00000001&(data))
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_get_accessdata_write_en(data)          ((0x00000002&(data))>>1)
#define  COLOR_ICM_DM_ICM_AccessData_CTRL_get_accessdata_read_en(data)           (0x00000001&(data))

#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl                                     0x1802A2D4
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg_addr                            "0xB802A2D4"
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg                                 0xB802A2D4
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_inst_addr                           "0x0074"
#define  set_COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg(data)                       (*((volatile unsigned int*)COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg)=data)
#define  get_COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg                             (*((volatile unsigned int*)COLOR_ICM_DM_ICM_AccessData_PosCtrl_reg))
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_starty_shift             (16)
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_startx_shift             (0)
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_starty_mask              (0x0FFF0000)
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_startx_mask              (0x00001FFF)
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_starty(data)             (0x0FFF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_accessdata_startx(data)             (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_get_accessdata_starty(data)         ((0x0FFF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_AccessData_PosCtrl_get_accessdata_startx(data)         (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1                                       0x1802A2D8
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg_addr                              "0xB802A2D8"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg                                   0xB802A2D8
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_inst_addr                             "0x0075"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_H1_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h00_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h01_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h00_mask                     (0x07FF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h01_mask                     (0x000007FF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h00(data)                    (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_readdata_h01(data)                    (0x000007FF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_get_readdata_h00(data)                ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H1_get_readdata_h01(data)                (0x000007FF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2                                       0x1802A2DC
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg_addr                              "0xB802A2DC"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg                                   0xB802A2DC
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_inst_addr                             "0x0076"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_H2_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h10_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h11_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h10_mask                     (0x07FF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h11_mask                     (0x000007FF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h10(data)                    (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_readdata_h11(data)                    (0x000007FF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_get_readdata_h10(data)                ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_H2_get_readdata_h11(data)                (0x000007FF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1                                       0x1802A2E0
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg_addr                              "0xB802A2E0"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg                                   0xB802A2E0
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_inst_addr                             "0x0077"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_S1_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s00_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s01_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s00_mask                     (0x1FFF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s01_mask                     (0x00001FFF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s00(data)                    (0x1FFF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_readdata_s01(data)                    (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_get_readdata_s00(data)                ((0x1FFF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S1_get_readdata_s01(data)                (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2                                       0x1802A2E4
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg_addr                              "0xB802A2E4"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg                                   0xB802A2E4
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_inst_addr                             "0x0078"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_S2_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s10_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s11_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s10_mask                     (0x1FFF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s11_mask                     (0x00001FFF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s10(data)                    (0x1FFF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_readdata_s11(data)                    (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_get_readdata_s10(data)                ((0x1FFF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_S2_get_readdata_s11(data)                (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1                                       0x1802A2E8
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg_addr                              "0xB802A2E8"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg                                   0xB802A2E8
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_inst_addr                             "0x0079"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_I1_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i00_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i01_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i00_mask                     (0x3FFF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i01_mask                     (0x00003FFF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i00(data)                    (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_readdata_i01(data)                    (0x00003FFF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_get_readdata_i00(data)                ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I1_get_readdata_i01(data)                (0x00003FFF&(data))

#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2                                       0x1802A2EC
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg_addr                              "0xB802A2EC"
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg                                   0xB802A2EC
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_inst_addr                             "0x007A"
#define  set_COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg(data)                         (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg)=data)
#define  get_COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg                               (*((volatile unsigned int*)COLOR_ICM_DM_ICM_ReadData_DATA_I2_reg))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i10_shift                    (16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i11_shift                    (0)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i10_mask                     (0x3FFF0000)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i11_mask                     (0x00003FFF)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i10(data)                    (0x3FFF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_readdata_i11(data)                    (0x00003FFF&(data))
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_get_readdata_i10(data)                ((0x3FFF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_ReadData_DATA_I2_get_readdata_i11(data)                (0x00003FFF&(data))

#define  COLOR_ICM_DM_ICM_WriteData_DATA1                                        0x1802A2F0
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_reg_addr                               "0xB802A2F0"
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_reg                                    0xB802A2F0
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_inst_addr                              "0x007B"
#define  set_COLOR_ICM_DM_ICM_WriteData_DATA1_reg(data)                          (*((volatile unsigned int*)COLOR_ICM_DM_ICM_WriteData_DATA1_reg)=data)
#define  get_COLOR_ICM_DM_ICM_WriteData_DATA1_reg                                (*((volatile unsigned int*)COLOR_ICM_DM_ICM_WriteData_DATA1_reg))
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_h_shift                      (16)
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_s_shift                      (0)
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_h_mask                       (0x07FF0000)
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_s_mask                       (0x00001FFF)
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_h(data)                      (0x07FF0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_writedata_s(data)                      (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_get_writedata_h(data)                  ((0x07FF0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_WriteData_DATA1_get_writedata_s(data)                  (0x00001FFF&(data))

#define  COLOR_ICM_DM_ICM_WriteData_DATA2                                        0x1802A2F4
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_reg_addr                               "0xB802A2F4"
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_reg                                    0xB802A2F4
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_inst_addr                              "0x007C"
#define  set_COLOR_ICM_DM_ICM_WriteData_DATA2_reg(data)                          (*((volatile unsigned int*)COLOR_ICM_DM_ICM_WriteData_DATA2_reg)=data)
#define  get_COLOR_ICM_DM_ICM_WriteData_DATA2_reg                                (*((volatile unsigned int*)COLOR_ICM_DM_ICM_WriteData_DATA2_reg))
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_writedata_i_shift                      (0)
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_writedata_i_mask                       (0x00001FFF)
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_writedata_i(data)                      (0x00001FFF&(data))
#define  COLOR_ICM_DM_ICM_WriteData_DATA2_get_writedata_i(data)                  (0x00001FFF&(data))

#define  COLOR_ICM_ICM_CRC_CTRL                                                  0x1802A2F8
#define  COLOR_ICM_ICM_CRC_CTRL_reg_addr                                         "0xB802A2F8"
#define  COLOR_ICM_ICM_CRC_CTRL_reg                                              0xB802A2F8
#define  COLOR_ICM_ICM_CRC_CTRL_inst_addr                                        "0x007D"
#define  set_COLOR_ICM_ICM_CRC_CTRL_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_ICM_CRC_CTRL_reg)=data)
#define  get_COLOR_ICM_ICM_CRC_CTRL_reg                                          (*((volatile unsigned int*)COLOR_ICM_ICM_CRC_CTRL_reg))
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_conti_shift                              (1)
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_start_shift                              (0)
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_conti_mask                               (0x00000002)
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_start_mask                               (0x00000001)
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_conti(data)                              (0x00000002&((data)<<1))
#define  COLOR_ICM_ICM_CRC_CTRL_icm_crc_start(data)                              (0x00000001&(data))
#define  COLOR_ICM_ICM_CRC_CTRL_get_icm_crc_conti(data)                          ((0x00000002&(data))>>1)
#define  COLOR_ICM_ICM_CRC_CTRL_get_icm_crc_start(data)                          (0x00000001&(data))

#define  COLOR_ICM_ICM_CRC_RESULT                                                0x1802A2FC
#define  COLOR_ICM_ICM_CRC_RESULT_reg_addr                                       "0xB802A2FC"
#define  COLOR_ICM_ICM_CRC_RESULT_reg                                            0xB802A2FC
#define  COLOR_ICM_ICM_CRC_RESULT_inst_addr                                      "0x007E"
#define  set_COLOR_ICM_ICM_CRC_RESULT_reg(data)                                  (*((volatile unsigned int*)COLOR_ICM_ICM_CRC_RESULT_reg)=data)
#define  get_COLOR_ICM_ICM_CRC_RESULT_reg                                        (*((volatile unsigned int*)COLOR_ICM_ICM_CRC_RESULT_reg))
#define  COLOR_ICM_ICM_CRC_RESULT_icm_crc_result_shift                           (0)
#define  COLOR_ICM_ICM_CRC_RESULT_icm_crc_result_mask                            (0xFFFFFFFF)
#define  COLOR_ICM_ICM_CRC_RESULT_icm_crc_result(data)                           (0xFFFFFFFF&(data))
#define  COLOR_ICM_ICM_CRC_RESULT_get_icm_crc_result(data)                       (0xFFFFFFFF&(data))

#define  COLOR_ICM_DM_ICM_DEBUG                                                  0x1802A300
#define  COLOR_ICM_DM_ICM_DEBUG_reg_addr                                         "0xB802A300"
#define  COLOR_ICM_DM_ICM_DEBUG_reg                                              0xB802A300
#define  COLOR_ICM_DM_ICM_DEBUG_inst_addr                                        "0x007F"
#define  set_COLOR_ICM_DM_ICM_DEBUG_reg(data)                                    (*((volatile unsigned int*)COLOR_ICM_DM_ICM_DEBUG_reg)=data)
#define  get_COLOR_ICM_DM_ICM_DEBUG_reg                                          (*((volatile unsigned int*)COLOR_ICM_DM_ICM_DEBUG_reg))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_sta_shift                         (24)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_end_shift                         (16)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_sta_shift                         (12)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_end_shift                         (8)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_sta_shift                         (4)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_end_shift                         (0)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_sta_mask                          (0x7F000000)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_end_mask                          (0x007F0000)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_sta_mask                          (0x0000F000)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_end_mask                          (0x00000F00)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_sta_mask                          (0x000000F0)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_end_mask                          (0x0000000F)
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_sta(data)                         (0x7F000000&((data)<<24))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_h_pillar_end(data)                         (0x007F0000&((data)<<16))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_sta(data)                         (0x0000F000&((data)<<12))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_s_pillar_end(data)                         (0x00000F00&((data)<<8))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_sta(data)                         (0x000000F0&((data)<<4))
#define  COLOR_ICM_DM_ICM_DEBUG_debug_i_pillar_end(data)                         (0x0000000F&(data))
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_h_pillar_sta(data)                     ((0x7F000000&(data))>>24)
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_h_pillar_end(data)                     ((0x007F0000&(data))>>16)
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_s_pillar_sta(data)                     ((0x0000F000&(data))>>12)
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_s_pillar_end(data)                     ((0x00000F00&(data))>>8)
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_i_pillar_sta(data)                     ((0x000000F0&(data))>>4)
#define  COLOR_ICM_DM_ICM_DEBUG_get_debug_i_pillar_end(data)                     (0x0000000F&(data))

#define  COLOR_ICM_DM_ICM_DB_CTRL_0                                              0x1802A310
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_reg_addr                                     "0xB802A310"
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_reg                                          0xB802A310
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_inst_addr                                    "0x0080"
#define  set_COLOR_ICM_DM_ICM_DB_CTRL_0_reg(data)                                (*((volatile unsigned int*)COLOR_ICM_DM_ICM_DB_CTRL_0_reg)=data)
#define  get_COLOR_ICM_DM_ICM_DB_CTRL_0_reg                                      (*((volatile unsigned int*)COLOR_ICM_DM_ICM_DB_CTRL_0_reg))
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_read_0_shift                              (2)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_en_0_shift                                (1)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_apply_0_shift                             (0)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_read_0_mask                               (0x00000004)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_en_0_mask                                 (0x00000002)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_apply_0_mask                              (0x00000001)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_read_0(data)                              (0x00000004&((data)<<2))
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_en_0(data)                                (0x00000002&((data)<<1))
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_db_apply_0(data)                             (0x00000001&(data))
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_get_db_read_0(data)                          ((0x00000004&(data))>>2)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_get_db_en_0(data)                            ((0x00000002&(data))>>1)
#define  COLOR_ICM_DM_ICM_DB_CTRL_0_get_db_apply_0(data)                         (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL                                  0x1802A330
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg_addr                         "0xB802A330"
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg                              0xB802A330
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_inst_addr                        "0x0081"
#define  set_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg                          (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_7_shift (7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_6_shift (6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_5_shift (5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_4_shift (4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_7_mask (0x00000080)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_6_mask (0x00000040)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_5_mask (0x00000020)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_4_mask (0x00000010)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_7(data) (0x00000080&((data)<<7))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_6(data) (0x00000040&((data)<<6))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_5(data) (0x00000020&((data)<<5))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_4(data) (0x00000010&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_mbist_icm_3d_table_bist_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_7(data) ((0x00000080&(data))>>7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_6(data) ((0x00000040&(data))>>6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_5(data) ((0x00000020&(data))>>5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_4(data) ((0x00000010&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_FAIL_get_mbist_icm_3d_table_bist_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL                                   0x1802A334
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg_addr                          "0xB802A334"
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg                               0xB802A334
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_inst_addr                         "0x0082"
#define  set_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_mbist_icm_hist_2p_bist_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_get_mbist_icm_hist_2p_bist_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_get_mbist_icm_hist_2p_bist_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_get_mbist_icm_hist_2p_bist_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_FAIL_get_mbist_icm_hist_2p_bist_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL                                   0x1802A338
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg_addr                          "0xB802A338"
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg                               0xB802A338
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_inst_addr                         "0x0083"
#define  set_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_mbist_icm_hist_1p_bist_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_get_mbist_icm_hist_1p_bist_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_get_mbist_icm_hist_1p_bist_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_get_mbist_icm_hist_1p_bist_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_FAIL_get_mbist_icm_hist_1p_bist_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL                                   0x1802A33C
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg_addr                          "0xB802A33C"
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg                               0xB802A33C
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_inst_addr                         "0x0084"
#define  set_COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_7_shift (7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_6_shift (6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_5_shift (5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_4_shift (4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_7_mask (0x00000080)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_6_mask (0x00000040)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_5_mask (0x00000020)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_4_mask (0x00000010)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_7(data) (0x00000080&((data)<<7))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_6(data) (0x00000040&((data)<<6))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_5(data) (0x00000020&((data)<<5))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_4(data) (0x00000010&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_mbist_icm_3d_table_drf_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_7(data) ((0x00000080&(data))>>7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_6(data) ((0x00000040&(data))>>6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_5(data) ((0x00000020&(data))>>5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_4(data) ((0x00000010&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_DRF_FAIL_get_mbist_icm_3d_table_drf_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL                                    0x1802A340
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg_addr                           "0xB802A340"
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg                                0xB802A340
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_inst_addr                          "0x0085"
#define  set_COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg                            (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_3_mask  (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_2_mask  (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_1_mask  (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_0_mask  (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_mbist_icm_hist_2p_drf_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_get_mbist_icm_hist_2p_drf_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_get_mbist_icm_hist_2p_drf_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_get_mbist_icm_hist_2p_drf_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_DRF_FAIL_get_mbist_icm_hist_2p_drf_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL                                    0x1802A344
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg_addr                           "0xB802A344"
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg                                0xB802A344
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_inst_addr                          "0x0086"
#define  set_COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg                            (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_3_mask  (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_2_mask  (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_1_mask  (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_0_mask  (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_mbist_icm_hist_1p_drf_fail_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_get_mbist_icm_hist_1p_drf_fail_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_get_mbist_icm_hist_1p_drf_fail_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_get_mbist_icm_hist_1p_drf_fail_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_DRF_FAIL_get_mbist_icm_hist_1p_drf_fail_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE                                  0x1802A348
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg_addr                         "0xB802A348"
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg                              0xB802A348
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_inst_addr                        "0x0087"
#define  set_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg(data)                    (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg                          (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_reg))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_7_shift (7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_6_shift (6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_5_shift (5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_4_shift (4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_7_mask (0x00000080)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_6_mask (0x00000040)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_5_mask (0x00000020)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_4_mask (0x00000010)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_7(data) (0x00000080&((data)<<7))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_6(data) (0x00000040&((data)<<6))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_5(data) (0x00000020&((data)<<5))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_4(data) (0x00000010&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_mbist_icm_3d_table_bist_dvse_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_7(data) ((0x00000080&(data))>>7)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_6(data) ((0x00000040&(data))>>6)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_5(data) ((0x00000020&(data))>>5)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_4(data) ((0x00000010&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVSE_get_mbist_icm_3d_table_bist_dvse_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE                                   0x1802A34C
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg_addr                          "0xB802A34C"
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg                               0xB802A34C
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_inst_addr                         "0x0088"
#define  set_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_a_shift (7)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_b_shift (6)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_a_shift (5)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_b_shift (4)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_a_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_b_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_a_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_b_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_a_mask (0x00000080)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_b_mask (0x00000040)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_a_mask (0x00000020)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_b_mask (0x00000010)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_a_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_b_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_a_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_b_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_a(data) (0x00000080&((data)<<7))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_3_b(data) (0x00000040&((data)<<6))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_a(data) (0x00000020&((data)<<5))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_2_b(data) (0x00000010&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_a(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_1_b(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_a(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_mbist_icm_hist_2p_bist_dvse_0_b(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_3_a(data) ((0x00000080&(data))>>7)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_3_b(data) ((0x00000040&(data))>>6)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_2_a(data) ((0x00000020&(data))>>5)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_2_b(data) ((0x00000010&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_1_a(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_1_b(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_0_a(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVSE_get_mbist_icm_hist_2p_bist_dvse_0_b(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE                                   0x1802A350
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg_addr                          "0xB802A350"
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg                               0xB802A350
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_inst_addr                         "0x0089"
#define  set_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_3_shift (3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_2_shift (2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_1_shift (1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_3_mask (0x00000008)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_2_mask (0x00000004)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_1_mask (0x00000002)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_0_mask (0x00000001)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_3(data) (0x00000008&((data)<<3))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_2(data) (0x00000004&((data)<<2))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_1(data) (0x00000002&((data)<<1))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_mbist_icm_hist_1p_bist_dvse_0(data) (0x00000001&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_get_mbist_icm_hist_1p_bist_dvse_3(data) ((0x00000008&(data))>>3)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_get_mbist_icm_hist_1p_bist_dvse_2(data) ((0x00000004&(data))>>2)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_get_mbist_icm_hist_1p_bist_dvse_1(data) ((0x00000002&(data))>>1)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVSE_get_mbist_icm_hist_1p_bist_dvse_0(data) (0x00000001&(data))

#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS                                   0x1802A354
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg_addr                          "0xB802A354"
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg                               0xB802A354
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_inst_addr                         "0x008A"
#define  set_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg(data)                     (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg                           (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_reg))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_7_shift (28)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_6_shift (24)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_5_shift (20)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_4_shift (16)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_3_shift (12)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_2_shift (8)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_1_shift (4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_7_mask (0xF0000000)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_6_mask (0x0F000000)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_5_mask (0x00F00000)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_4_mask (0x000F0000)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_3_mask (0x0000F000)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_2_mask (0x00000F00)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_1_mask (0x000000F0)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_0_mask (0x0000000F)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_7(data) (0xF0000000&((data)<<28))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_6(data) (0x0F000000&((data)<<24))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_5(data) (0x00F00000&((data)<<20))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_4(data) (0x000F0000&((data)<<16))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_3(data) (0x0000F000&((data)<<12))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_2(data) (0x00000F00&((data)<<8))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_1(data) (0x000000F0&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_mbist_icm_3d_table_bist_dvs_0(data) (0x0000000F&(data))
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_7(data) ((0xF0000000&(data))>>28)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_6(data) ((0x0F000000&(data))>>24)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_5(data) ((0x00F00000&(data))>>20)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_4(data) ((0x000F0000&(data))>>16)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_3(data) ((0x0000F000&(data))>>12)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_2(data) ((0x00000F00&(data))>>8)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_1(data) ((0x000000F0&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_3D_TABLE_BIST_DVS_get_mbist_icm_3d_table_bist_dvs_0(data) (0x0000000F&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS                                    0x1802A358
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg_addr                           "0xB802A358"
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg                                0xB802A358
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_inst_addr                          "0x008B"
#define  set_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg                            (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_a_shift (28)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_b_shift (24)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_a_shift (20)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_b_shift (16)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_a_shift (12)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_b_shift (8)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_a_shift (4)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_b_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_a_mask (0xF0000000)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_b_mask (0x0F000000)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_a_mask (0x00F00000)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_b_mask (0x000F0000)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_a_mask (0x0000F000)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_b_mask (0x00000F00)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_a_mask (0x000000F0)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_b_mask (0x0000000F)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_a(data) (0xF0000000&((data)<<28))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_3_b(data) (0x0F000000&((data)<<24))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_a(data) (0x00F00000&((data)<<20))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_2_b(data) (0x000F0000&((data)<<16))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_a(data) (0x0000F000&((data)<<12))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_1_b(data) (0x00000F00&((data)<<8))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_a(data) (0x000000F0&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_mbist_icm_hist_2p_bist_dvs_0_b(data) (0x0000000F&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_3_a(data) ((0xF0000000&(data))>>28)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_3_b(data) ((0x0F000000&(data))>>24)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_2_a(data) ((0x00F00000&(data))>>20)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_2_b(data) ((0x000F0000&(data))>>16)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_1_a(data) ((0x0000F000&(data))>>12)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_1_b(data) ((0x00000F00&(data))>>8)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_0_a(data) ((0x000000F0&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_HIST_2P_BIST_DVS_get_mbist_icm_hist_2p_bist_dvs_0_b(data) (0x0000000F&(data))

#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS                                    0x1802A35C
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg_addr                           "0xB802A35C"
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg                                0xB802A35C
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_inst_addr                          "0x008C"
#define  set_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg(data)                      (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg)=data)
#define  get_COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg                            (*((volatile unsigned int*)COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_reg))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_3_shift (12)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_2_shift (8)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_1_shift (4)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_0_shift (0)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_3_mask  (0x0000F000)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_2_mask  (0x00000F00)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_1_mask  (0x000000F0)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_0_mask  (0x0000000F)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_3(data) (0x0000F000&((data)<<12))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_2(data) (0x00000F00&((data)<<8))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_1(data) (0x000000F0&((data)<<4))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_mbist_icm_hist_1p_bist_dvs_0(data) (0x0000000F&(data))
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_get_mbist_icm_hist_1p_bist_dvs_3(data) ((0x0000F000&(data))>>12)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_get_mbist_icm_hist_1p_bist_dvs_2(data) ((0x00000F00&(data))>>8)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_get_mbist_icm_hist_1p_bist_dvs_1(data) ((0x000000F0&(data))>>4)
#define  COLOR_ICM_MBIST_ICM_HIST_1P_BIST_DVS_get_mbist_icm_hist_1p_bist_dvs_0(data) (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_ICM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hsi_grid_sel:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  out_grid_process:1;
        RBus_UInt32  y_ctrl:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  debug_color:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  data_format_sel:1;
        RBus_UInt32  data_range_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  m_icm_bypass_en:1;
        RBus_UInt32  dummy1802a100_16_0:17;
    };
}color_icm_dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  v_coring:8;
    };
}color_icm_dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_4:6;
    };
}color_icm_dm_icm_hue_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_7:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_8:6;
    };
}color_icm_dm_icm_hue_segment_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_9:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_11:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_12:6;
    };
}color_icm_dm_icm_hue_segment_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_13:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_14:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_15:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_16:6;
    };
}color_icm_dm_icm_hue_segment_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_17:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_18:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_19:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_20:6;
    };
}color_icm_dm_icm_hue_segment_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_21:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_22:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_23:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_24:6;
    };
}color_icm_dm_icm_hue_segment_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_25:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_26:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_27:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_28:6;
    };
}color_icm_dm_icm_hue_segment_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_29:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_31:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_32:6;
    };
}color_icm_dm_icm_hue_segment_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_33:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_34:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_35:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_36:6;
    };
}color_icm_dm_icm_hue_segment_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_37:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_38:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_39:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_40:6;
    };
}color_icm_dm_icm_hue_segment_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_41:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_42:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_43:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  h_pillar_44:6;
    };
}color_icm_dm_icm_hue_segment_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_45:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_46:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_47:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  h_pillar_48:7;
    };
}color_icm_dm_icm_hue_segment_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_pillar_1:4;
        RBus_UInt32  s_pillar_2:4;
        RBus_UInt32  s_pillar_3:4;
        RBus_UInt32  s_pillar_4:4;
        RBus_UInt32  s_pillar_5:4;
        RBus_UInt32  s_pillar_6:4;
        RBus_UInt32  s_pillar_7:4;
        RBus_UInt32  s_pillar_8:4;
    };
}color_icm_dm_icm_sat_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_pillar_1:4;
        RBus_UInt32  i_pillar_2:4;
        RBus_UInt32  i_pillar_3:4;
        RBus_UInt32  i_pillar_4:4;
        RBus_UInt32  i_pillar_5:4;
        RBus_UInt32  i_pillar_6:4;
        RBus_UInt32  i_pillar_7:4;
        RBus_UInt32  i_pillar_8:4;
    };
}color_icm_dm_icm_int_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sat_hist_mode:1;
        RBus_UInt32  d_auto_sat_ctrl_sat_hist_mode_sel:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  hist_sat_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
    };
}color_icm_d_auto_sat_hist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_u_thre0:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_l_thre0:14;
    };
}color_icm_d_auto_sat_hist0_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_u_thre1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_l_thre1:14;
    };
}color_icm_d_auto_sat_hist1_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_u_thre2:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_l_thre2:14;
    };
}color_icm_d_auto_sat_hist2_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_u_thre3:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_l_thre3:14;
    };
}color_icm_d_auto_sat_hist3_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist0_thrd_auto_sat_s_thre0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_hist1_thrd_auto_sat_s_thre1:13;
    };
}color_icm_d_auto_sat_hist01_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist2_thrd_auto_sat_s_thre2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  d_hist3_thrd_auto_sat_s_thre3:13;
    };
}color_icm_d_auto_sat_hist23_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist0_hue_sta:8;
        RBus_UInt32  sat_hist0_hue_end:8;
        RBus_UInt32  sat_hist1_hue_sta:8;
        RBus_UInt32  sat_hist1_hue_end:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist2_hue_sta:8;
        RBus_UInt32  sat_hist2_hue_end:8;
        RBus_UInt32  sat_hist3_hue_sta:8;
        RBus_UInt32  sat_hist3_hue_end:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_read:1;
        RBus_UInt32  hist_ctrl:2;
        RBus_UInt32  cnt_block:1;
        RBus_UInt32  res1:28;
    };
}color_icm_d_auto_sat_hist_read_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist0_hue_sta_status:8;
        RBus_UInt32  sat_hist0_hue_end_status:8;
        RBus_UInt32  sat_hist1_hue_sta_status:8;
        RBus_UInt32  sat_hist1_hue_end_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist2_hue_sta_status:8;
        RBus_UInt32  sat_hist2_hue_end_status:8;
        RBus_UInt32  sat_hist3_hue_sta_status:8;
        RBus_UInt32  sat_hist3_hue_end_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_00_or_16:24;
    };
}color_icm_d_auto_sat_hist_cnt_00_or_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_01_or_17:24;
    };
}color_icm_d_auto_sat_hist_cnt_01_or_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_02_or_18:24;
    };
}color_icm_d_auto_sat_hist_cnt_02_or_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_03_or_19:24;
    };
}color_icm_d_auto_sat_hist_cnt_03_or_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_04_or_20:24;
    };
}color_icm_d_auto_sat_hist_cnt_04_or_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_05_or_21:24;
    };
}color_icm_d_auto_sat_hist_cnt_05_or_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_06_or_22:24;
    };
}color_icm_d_auto_sat_hist_cnt_06_or_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_07_or_23:24;
    };
}color_icm_d_auto_sat_hist_cnt_07_or_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_08_or_24:24;
    };
}color_icm_d_auto_sat_hist_cnt_08_or_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_09_or_25:24;
    };
}color_icm_d_auto_sat_hist_cnt_09_or_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_10_or_26:24;
    };
}color_icm_d_auto_sat_hist_cnt_10_or_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_11_or_27:24;
    };
}color_icm_d_auto_sat_hist_cnt_11_or_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_12_or_28:24;
    };
}color_icm_d_auto_sat_hist_cnt_12_or_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_13_or_29:24;
    };
}color_icm_d_auto_sat_hist_cnt_13_or_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_14_or_30:24;
    };
}color_icm_d_auto_sat_hist_cnt_14_or_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sat_hist_cnt_15_or_31:24;
    };
}color_icm_d_auto_sat_hist_cnt_15_or_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_sram_read_consistent_flag:1;
        RBus_UInt32  res1:31;
    };
}color_icm_d_auto_sat_hist_read_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  icm_auto_ctrl_hue_hist_mode_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  hist_hue_enable:1;
        RBus_UInt32  inside_enable:1;
    };
}color_icm_icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_hist_offset_add:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  hue_hist_sat_lb:13;
    };
}color_icm_hue_hist_settings0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hue_hist_itn_hb:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  hue_hist_itn_lb:14;
    };
}color_icm_hue_hist_settings1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_00_lut0:24;
    };
}color_icm_hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_01_lut1:24;
    };
}color_icm_hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_02_lut2:24;
    };
}color_icm_hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_03_lut3:24;
    };
}color_icm_hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_04_lut4:24;
    };
}color_icm_hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_05_lut5:24;
    };
}color_icm_hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_06_lut6:24;
    };
}color_icm_hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_07_lut7:24;
    };
}color_icm_hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_08_lut8:24;
    };
}color_icm_hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_09_lut9:24;
    };
}color_icm_hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0a_lut10:24;
    };
}color_icm_hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0b_lut11:24;
    };
}color_icm_hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0c_lut12:24;
    };
}color_icm_hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0d_lut13:24;
    };
}color_icm_hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0e_lut14:24;
    };
}color_icm_hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_0f_lut15:24;
    };
}color_icm_hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_10_lut16:24;
    };
}color_icm_hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_11_lut17:24;
    };
}color_icm_hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_12_lut18:24;
    };
}color_icm_hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_13_lut19:24;
    };
}color_icm_hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_14_lut20:24;
    };
}color_icm_hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_15_lut21:24;
    };
}color_icm_hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_16_lut22:24;
    };
}color_icm_hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hue_count_17_lut23:24;
    };
}color_icm_hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_00_lut0:31;
    };
}color_icm_hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_01_lut1:31;
    };
}color_icm_hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_02_lut2:31;
    };
}color_icm_hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_03_lut3:31;
    };
}color_icm_hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_04_lut4:31;
    };
}color_icm_hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  hue_sum_05_lut5:31;
    };
}color_icm_hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dmato3dlut_en:1;
        RBus_UInt32  sram_addrres_h:6;
        RBus_UInt32  sram_addrres_s:4;
        RBus_UInt32  sram_addrres_i:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  hw_fw_priority_opt:1;
        RBus_UInt32  sram_type:1;
        RBus_UInt32  read_sel:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}color_icm_dm_icm_3d_tab_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h0:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s0:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i0:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h1:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s1:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i1:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h2:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s2:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i2:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h3:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s3:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i3:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h4:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s4:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i4:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h5:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s5:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i5:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h6:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s6:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i6:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h7:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s7:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i7:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h8:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s8:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i8:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_h9:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_s9:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_i9:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_ha:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_sa:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_ia:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  write_table_hb:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_table_sb:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  write_table_ib:13;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h0:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s0:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i0:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h1:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s1:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i1:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h2:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s2:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i2:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h3:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s3:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i3:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h4:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s4:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i4:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  read_table_h5:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  read_table_s5:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  read_table_i5:13;
    };
}color_icm_dm_icm_3d_tab_read_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  accessdata_write_en:1;
        RBus_UInt32  accessdata_read_en:1;
    };
}color_icm_dm_icm_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  accessdata_starty:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  accessdata_startx:13;
    };
}color_icm_dm_icm_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  readdata_h00:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  readdata_h01:11;
    };
}color_icm_dm_icm_readdata_data_h1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  readdata_h10:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  readdata_h11:11;
    };
}color_icm_dm_icm_readdata_data_h2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s00:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_s01:13;
    };
}color_icm_dm_icm_readdata_data_s1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s10:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  readdata_s11:13;
    };
}color_icm_dm_icm_readdata_data_s2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i00:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  readdata_i01:14;
    };
}color_icm_dm_icm_readdata_data_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i10:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  readdata_i11:14;
    };
}color_icm_dm_icm_readdata_data_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  writedata_h:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  writedata_s:13;
    };
}color_icm_dm_icm_writedata_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  writedata_i:13;
    };
}color_icm_dm_icm_writedata_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  icm_crc_start:1;
    };
}color_icm_icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}color_icm_icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_h_pillar_sta:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_h_pillar_end:7;
        RBus_UInt32  debug_s_pillar_sta:4;
        RBus_UInt32  debug_s_pillar_end:4;
        RBus_UInt32  debug_i_pillar_sta:4;
        RBus_UInt32  debug_i_pillar_end:4;
    };
}color_icm_dm_icm_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read_0:1;
        RBus_UInt32  db_en_0:1;
        RBus_UInt32  db_apply_0:1;
    };
}color_icm_dm_icm_db_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_7:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_0:1;
    };
}color_icm_mbist_icm_3d_table_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_3:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_0:1;
    };
}color_icm_mbist_icm_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_3:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_0:1;
    };
}color_icm_mbist_icm_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_7:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_0:1;
    };
}color_icm_mbist_icm_3d_table_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_3:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_0:1;
    };
}color_icm_mbist_icm_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_3:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_0:1;
    };
}color_icm_mbist_icm_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_7:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_0:1;
    };
}color_icm_mbist_icm_3d_table_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0_b:1;
    };
}color_icm_mbist_icm_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_0:1;
    };
}color_icm_mbist_icm_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_7:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_6:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_5:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_4:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_0:4;
    };
}color_icm_mbist_icm_3d_table_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0_b:4;
    };
}color_icm_mbist_icm_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_0:4;
    };
}color_icm_mbist_icm_hist_1p_bist_dvs_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_ICM register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802a100_16_0:17;
        RBus_UInt32  m_icm_bypass_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  data_range_sel:1;
        RBus_UInt32  data_format_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_color:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  y_ctrl:1;
        RBus_UInt32  out_grid_process:1;
        RBus_UInt32  bypass_yuv2rgb_enable:1;
        RBus_UInt32  hsi_grid_sel:1;
        RBus_UInt32  res3:1;
    };
}color_icm_dm_icm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_coring:8;
        RBus_UInt32  u_coring:8;
        RBus_UInt32  res1:16;
    };
}color_icm_dm_uv_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_1:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_8:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_7:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_5:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_12:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_11:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_9:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_16:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_15:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_14:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_13:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_20:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_19:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_18:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_17:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_24:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_23:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_22:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_21:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_28:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_27:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_26:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_25:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_32:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_31:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_29:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_36:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_35:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_34:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_33:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_40:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_39:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_38:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_37:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_44:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_pillar_43:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_42:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_41:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pillar_48:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  h_pillar_47:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_pillar_46:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  h_pillar_45:6;
        RBus_UInt32  res4:2;
    };
}color_icm_dm_icm_hue_segment_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_pillar_8:4;
        RBus_UInt32  s_pillar_7:4;
        RBus_UInt32  s_pillar_6:4;
        RBus_UInt32  s_pillar_5:4;
        RBus_UInt32  s_pillar_4:4;
        RBus_UInt32  s_pillar_3:4;
        RBus_UInt32  s_pillar_2:4;
        RBus_UInt32  s_pillar_1:4;
    };
}color_icm_dm_icm_sat_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_pillar_8:4;
        RBus_UInt32  i_pillar_7:4;
        RBus_UInt32  i_pillar_6:4;
        RBus_UInt32  i_pillar_5:4;
        RBus_UInt32  i_pillar_4:4;
        RBus_UInt32  i_pillar_3:4;
        RBus_UInt32  i_pillar_2:4;
        RBus_UInt32  i_pillar_1:4;
    };
}color_icm_dm_icm_int_segment_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hist_sat_enable:1;
        RBus_UInt32  hist_sat_ok:1;
        RBus_UInt32  d_auto_sat_ctrl_sat_hist_mode_sel:1;
        RBus_UInt32  sat_hist_mode:1;
        RBus_UInt32  res3:26;
    };
}color_icm_d_auto_sat_hist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist0_thrd_auto_sat_i_l_thre0:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist0_thrd_auto_sat_i_u_thre0:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist0_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist1_thrd_auto_sat_i_l_thre1:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist1_thrd_auto_sat_i_u_thre1:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist1_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist2_thrd_auto_sat_i_l_thre2:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist2_thrd_auto_sat_i_u_thre2:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist2_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist3_thrd_auto_sat_i_l_thre3:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  d_hist3_thrd_auto_sat_i_u_thre3:14;
        RBus_UInt32  res2:2;
    };
}color_icm_d_auto_sat_hist3_int_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist1_thrd_auto_sat_s_thre1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist0_thrd_auto_sat_s_thre0:13;
        RBus_UInt32  res2:3;
    };
}color_icm_d_auto_sat_hist01_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_hist3_thrd_auto_sat_s_thre3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  d_hist2_thrd_auto_sat_s_thre2:13;
        RBus_UInt32  res2:3;
    };
}color_icm_d_auto_sat_hist23_sat_thrd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist1_hue_end:8;
        RBus_UInt32  sat_hist1_hue_sta:8;
        RBus_UInt32  sat_hist0_hue_end:8;
        RBus_UInt32  sat_hist0_hue_sta:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist3_hue_end:8;
        RBus_UInt32  sat_hist3_hue_sta:8;
        RBus_UInt32  sat_hist2_hue_end:8;
        RBus_UInt32  sat_hist2_hue_sta:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cnt_block:1;
        RBus_UInt32  hist_ctrl:2;
        RBus_UInt32  sram_read:1;
    };
}color_icm_d_auto_sat_hist_read_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist1_hue_end_status:8;
        RBus_UInt32  sat_hist1_hue_sta_status:8;
        RBus_UInt32  sat_hist0_hue_end_status:8;
        RBus_UInt32  sat_hist0_hue_sta_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist3_hue_end_status:8;
        RBus_UInt32  sat_hist3_hue_sta_status:8;
        RBus_UInt32  sat_hist2_hue_end_status:8;
        RBus_UInt32  sat_hist2_hue_sta_status:8;
    };
}color_icm_d_auto_sat_hist_ctrl1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_00_or_16:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_00_or_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_01_or_17:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_01_or_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_02_or_18:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_02_or_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_03_or_19:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_03_or_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_04_or_20:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_04_or_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_05_or_21:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_05_or_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_06_or_22:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_06_or_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_07_or_23:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_07_or_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_08_or_24:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_08_or_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_09_or_25:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_09_or_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_10_or_26:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_10_or_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_11_or_27:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_11_or_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_12_or_28:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_12_or_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_13_or_29:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_13_or_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_14_or_30:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_14_or_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_hist_cnt_15_or_31:24;
        RBus_UInt32  res1:8;
    };
}color_icm_d_auto_sat_hist_cnt_15_or_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sat_hist_sram_read_consistent_flag:1;
    };
}color_icm_d_auto_sat_hist_read_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inside_enable:1;
        RBus_UInt32  hist_hue_enable:1;
        RBus_UInt32  hist_hue_ok:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  icm_auto_ctrl_hue_hist_mode_sel:1;
        RBus_UInt32  res2:27;
    };
}color_icm_icm_auto_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_sat_lb:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  hue_hist_offset_add:8;
        RBus_UInt32  res2:8;
    };
}color_icm_hue_hist_settings0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_hist_itn_lb:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  hue_hist_itn_hb:14;
        RBus_UInt32  res2:2;
    };
}color_icm_hue_hist_settings1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_00_lut0:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_01_lut1:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_02_lut2:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_03_lut3:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_04_lut4:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_05_lut5:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_06_lut6:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_07_lut7:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_08_lut8:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_09_lut9:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0a_lut10:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0b_lut11:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0c_lut12:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0d_lut13:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0e_lut14:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0e_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_0f_lut15:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_0f_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_10_lut16:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_11_lut17:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_12_lut18:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_13_lut19:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_14_lut20:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_15_lut21:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_16_lut22:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_count_17_lut23:24;
        RBus_UInt32  res1:8;
    };
}color_icm_hue_count_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_00_lut0:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_01_lut1:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_02_lut2:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_03_lut3:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_04_lut4:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue_sum_05_lut5:31;
        RBus_UInt32  res1:1;
    };
}color_icm_hue_sum_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  write_random_access_en:1;
        RBus_UInt32  read_sel:1;
        RBus_UInt32  sram_type:1;
        RBus_UInt32  hw_fw_priority_opt:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  sram_addrres_i:4;
        RBus_UInt32  sram_addrres_s:4;
        RBus_UInt32  sram_addrres_h:6;
        RBus_UInt32  dmato3dlut_en:1;
        RBus_UInt32  res2:1;
    };
}color_icm_dm_icm_3d_tab_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h0:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i0:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h1:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i1:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h2:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i2:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h3:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i3:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h4:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i4:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h5:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i5:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s6:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h6:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i6:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s7:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h7:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i7:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s8:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h8:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i8:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_s9:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_h9:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_90_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_i9:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_sa:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_ha:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_ia:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_sb:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  write_table_hb:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_table_ib:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_write_hsi_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h0:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i0:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h1:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i1:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h2:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i2:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h3:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i3:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h4:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i4:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_s5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  read_table_h5:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_3d_tab_read_hsi_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_table_i5:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_3d_tab_read_hsi_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  accessdata_read_en:1;
        RBus_UInt32  accessdata_write_en:1;
        RBus_UInt32  res1:30;
    };
}color_icm_dm_icm_accessdata_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  accessdata_startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  accessdata_starty:12;
        RBus_UInt32  res2:4;
    };
}color_icm_dm_icm_accessdata_posctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_h01:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  readdata_h00:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_readdata_data_h1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_h11:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  readdata_h10:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_readdata_data_h2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_s01:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s00:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_s1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_s11:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  readdata_s10:13;
        RBus_UInt32  res2:3;
    };
}color_icm_dm_icm_readdata_data_s2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_i01:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i00:14;
        RBus_UInt32  res2:2;
    };
}color_icm_dm_icm_readdata_data_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  readdata_i11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  readdata_i10:14;
        RBus_UInt32  res2:2;
    };
}color_icm_dm_icm_readdata_data_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  writedata_s:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  writedata_h:11;
        RBus_UInt32  res2:5;
    };
}color_icm_dm_icm_writedata_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  writedata_i:13;
        RBus_UInt32  res1:19;
    };
}color_icm_dm_icm_writedata_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_start:1;
        RBus_UInt32  icm_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}color_icm_icm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icm_crc_result:32;
    };
}color_icm_icm_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_i_pillar_end:4;
        RBus_UInt32  debug_i_pillar_sta:4;
        RBus_UInt32  debug_s_pillar_end:4;
        RBus_UInt32  debug_s_pillar_sta:4;
        RBus_UInt32  debug_h_pillar_end:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_h_pillar_sta:7;
        RBus_UInt32  res2:1;
    };
}color_icm_dm_icm_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply_0:1;
        RBus_UInt32  db_en_0:1;
        RBus_UInt32  db_read_0:1;
        RBus_UInt32  res1:29;
    };
}color_icm_dm_icm_db_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_fail_0:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_fail_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_0:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_2p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_0:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_drf_fail_0:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_1:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_2:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_3:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_4:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_5:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_6:1;
        RBus_UInt32  mbist_icm_3d_table_drf_fail_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_0:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_2p_drf_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_2p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_0:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_1:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_2:1;
        RBus_UInt32  mbist_icm_hist_1p_drf_fail_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_0:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_3:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_4:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_5:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_6:1;
        RBus_UInt32  mbist_icm_3d_table_bist_dvse_7:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_3d_table_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_0_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_1_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_2_a:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3_b:1;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvse_3_a:1;
        RBus_UInt32  res1:24;
    };
}color_icm_mbist_icm_hist_2p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_0:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_1:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_2:1;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvse_3:1;
        RBus_UInt32  res1:28;
    };
}color_icm_mbist_icm_hist_1p_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_0:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_3:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_4:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_5:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_6:4;
        RBus_UInt32  mbist_icm_3d_table_bist_dvs_7:4;
    };
}color_icm_mbist_icm_3d_table_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_0_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_1_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_2_a:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3_b:4;
        RBus_UInt32  mbist_icm_hist_2p_bist_dvs_3_a:4;
    };
}color_icm_mbist_icm_hist_2p_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_0:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_1:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_2:4;
        RBus_UInt32  mbist_icm_hist_1p_bist_dvs_3:4;
        RBus_UInt32  res1:16;
    };
}color_icm_mbist_icm_hist_1p_bist_dvs_RBUS;




#endif 


#endif 
