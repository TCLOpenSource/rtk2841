/**
* @file Mac5-DesignSpec-D-Domain_DCC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_DCC_REG_H_
#define _RBUS_COLOR_DCC_REG_H_

#include "rbus_types.h"



//  COLOR_DCC Register Address
#define  COLOR_DCC_D_DCC_CTRL                                                    0x1802E400
#define  COLOR_DCC_D_DCC_CTRL_reg_addr                                           "0xB802E400"
#define  COLOR_DCC_D_DCC_CTRL_reg                                                0xB802E400
#define  COLOR_DCC_D_DCC_CTRL_inst_addr                                          "0x0000"
#define  set_COLOR_DCC_D_DCC_CTRL_reg(data)                                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_CTRL_reg)=data)
#define  get_COLOR_DCC_D_DCC_CTRL_reg                                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_CTRL_reg))
#define  COLOR_DCC_D_DCC_CTRL_dummy_31_10_shift                                  (10)
#define  COLOR_DCC_D_DCC_CTRL_dcc_user_curve_en_shift                            (9)
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_mode_shift                               (8)
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_blending_wt_shift                        (3)
#define  COLOR_DCC_D_DCC_CTRL_main_table_segment_shift                           (2)
#define  COLOR_DCC_D_DCC_CTRL_main_table_sel_shift                               (1)
#define  COLOR_DCC_D_DCC_CTRL_dcc_main_en_shift                                  (0)
#define  COLOR_DCC_D_DCC_CTRL_dummy_31_10_mask                                   (0xFFFFFC00)
#define  COLOR_DCC_D_DCC_CTRL_dcc_user_curve_en_mask                             (0x00000200)
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_mode_mask                                (0x00000100)
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_blending_wt_mask                         (0x000000F8)
#define  COLOR_DCC_D_DCC_CTRL_main_table_segment_mask                            (0x00000004)
#define  COLOR_DCC_D_DCC_CTRL_main_table_sel_mask                                (0x00000002)
#define  COLOR_DCC_D_DCC_CTRL_dcc_main_en_mask                                   (0x00000001)
#define  COLOR_DCC_D_DCC_CTRL_dummy_31_10(data)                                  (0xFFFFFC00&((data)<<10))
#define  COLOR_DCC_D_DCC_CTRL_dcc_user_curve_en(data)                            (0x00000200&((data)<<9))
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_mode(data)                               (0x00000100&((data)<<8))
#define  COLOR_DCC_D_DCC_CTRL_y_mapping_blending_wt(data)                        (0x000000F8&((data)<<3))
#define  COLOR_DCC_D_DCC_CTRL_main_table_segment(data)                           (0x00000004&((data)<<2))
#define  COLOR_DCC_D_DCC_CTRL_main_table_sel(data)                               (0x00000002&((data)<<1))
#define  COLOR_DCC_D_DCC_CTRL_dcc_main_en(data)                                  (0x00000001&(data))
#define  COLOR_DCC_D_DCC_CTRL_get_dummy_31_10(data)                              ((0xFFFFFC00&(data))>>10)
#define  COLOR_DCC_D_DCC_CTRL_get_dcc_user_curve_en(data)                        ((0x00000200&(data))>>9)
#define  COLOR_DCC_D_DCC_CTRL_get_y_mapping_mode(data)                           ((0x00000100&(data))>>8)
#define  COLOR_DCC_D_DCC_CTRL_get_y_mapping_blending_wt(data)                    ((0x000000F8&(data))>>3)
#define  COLOR_DCC_D_DCC_CTRL_get_main_table_segment(data)                       ((0x00000004&(data))>>2)
#define  COLOR_DCC_D_DCC_CTRL_get_main_table_sel(data)                           ((0x00000002&(data))>>1)
#define  COLOR_DCC_D_DCC_CTRL_get_dcc_main_en(data)                              (0x00000001&(data))

#define  COLOR_DCC_DCC_CTRL_LUMA                                                 0x1802E404
#define  COLOR_DCC_DCC_CTRL_LUMA_reg_addr                                        "0xB802E404"
#define  COLOR_DCC_DCC_CTRL_LUMA_reg                                             0xB802E404
#define  COLOR_DCC_DCC_CTRL_LUMA_inst_addr                                       "0x0001"
#define  set_COLOR_DCC_DCC_CTRL_LUMA_reg(data)                                   (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_LUMA_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_LUMA_reg                                         (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_LUMA_reg))
#define  COLOR_DCC_DCC_CTRL_LUMA_luma_offset_main_shift                          (16)
#define  COLOR_DCC_DCC_CTRL_LUMA_luma_offset_main_mask                           (0x00FF0000)
#define  COLOR_DCC_DCC_CTRL_LUMA_luma_offset_main(data)                          (0x00FF0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_LUMA_get_luma_offset_main(data)                      ((0x00FF0000&(data))>>16)

#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0                                       0x1802E408
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg_addr                              "0xB802E408"
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg                                   0xB802E408
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_inst_addr                             "0x0002"
#define  set_COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg(data)                         (*((volatile unsigned int*)COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg)=data)
#define  get_COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg                               (*((volatile unsigned int*)COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_en_shift            (31)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg3_shift          (24)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg2_shift          (16)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg1_shift          (8)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg0_shift          (0)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_en_mask             (0x80000000)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg3_mask           (0x3F000000)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg2_mask           (0x003F0000)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg1_mask           (0x00003F00)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg0_mask           (0x0000003F)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_en(data)            (0x80000000&((data)<<31))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg3(data)          (0x3F000000&((data)<<24))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg2(data)          (0x003F0000&((data)<<16))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg1(data)          (0x00003F00&((data)<<8))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_chroma_gain_limit_seg0(data)          (0x0000003F&(data))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_get_chroma_gain_limit_en(data)        ((0x80000000&(data))>>31)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_get_chroma_gain_limit_seg3(data)      ((0x3F000000&(data))>>24)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_get_chroma_gain_limit_seg2(data)      ((0x003F0000&(data))>>16)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_get_chroma_gain_limit_seg1(data)      ((0x00003F00&(data))>>8)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_get_chroma_gain_limit_seg0(data)      (0x0000003F&(data))

#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1                                       0x1802E40C
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg_addr                              "0xB802E40C"
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg                                   0xB802E40C
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_inst_addr                             "0x0003"
#define  set_COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg(data)                         (*((volatile unsigned int*)COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg)=data)
#define  get_COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg                               (*((volatile unsigned int*)COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg7_shift          (24)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg6_shift          (16)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg5_shift          (8)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg4_shift          (0)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg7_mask           (0x3F000000)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg6_mask           (0x003F0000)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg5_mask           (0x00003F00)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg4_mask           (0x0000003F)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg7(data)          (0x3F000000&((data)<<24))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg6(data)          (0x003F0000&((data)<<16))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg5(data)          (0x00003F00&((data)<<8))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_chroma_gain_limit_seg4(data)          (0x0000003F&(data))
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_get_chroma_gain_limit_seg7(data)      ((0x3F000000&(data))>>24)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_get_chroma_gain_limit_seg6(data)      ((0x003F0000&(data))>>16)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_get_chroma_gain_limit_seg5(data)      ((0x00003F00&(data))>>8)
#define  COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_get_chroma_gain_limit_seg4(data)      (0x0000003F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN                                          0x1802E410
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg_addr                                 "0xB802E410"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg                                      0xB802E410
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_inst_addr                                "0x0004"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg(data)                            (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg                                  (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab0_seg0_shift              (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab1_seg0_shift              (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_v_tab_select_main_shift   (11)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_u_tab_select_main_shift   (10)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_below_tab_select_main_shift (9)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_above_tab_select_main_shift (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_base_shift                   (4)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_lookup_mode_shift            (2)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_mode_shift                   (1)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_en_shift                     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab0_seg0_mask               (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab1_seg0_mask               (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_v_tab_select_main_mask    (0x00000800)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_u_tab_select_main_mask    (0x00000400)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_below_tab_select_main_mask (0x00000200)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_above_tab_select_main_mask (0x00000100)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_base_mask                    (0x00000070)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_lookup_mode_mask             (0x00000004)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_mode_mask                    (0x00000002)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_en_mask                      (0x00000001)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab0_seg0(data)              (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_tab1_seg0(data)              (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_v_tab_select_main(data)   (0x00000800&((data)<<11))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_saturation_byy_u_tab_select_main(data)   (0x00000400&((data)<<10))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_below_tab_select_main(data) (0x00000200&((data)<<9))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_enhance_above_tab_select_main(data) (0x00000100&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_base(data)                   (0x00000070&((data)<<4))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_lookup_mode(data)            (0x00000004&((data)<<2))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_mode(data)                   (0x00000002&((data)<<1))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_chroma_gain_en(data)                     (0x00000001&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_tab0_seg0(data)          ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_tab1_seg0(data)          ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_saturation_byy_v_tab_select_main(data) ((0x00000800&(data))>>11)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_saturation_byy_u_tab_select_main(data) ((0x00000400&(data))>>10)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_enhance_below_tab_select_main(data) ((0x00000200&(data))>>9)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_enhance_above_tab_select_main(data) ((0x00000100&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_base(data)               ((0x00000070&(data))>>4)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_lookup_mode(data)        ((0x00000004&(data))>>2)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_mode(data)               ((0x00000002&(data))>>1)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_get_chroma_gain_en(data)                 (0x00000001&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0                                   0x1802E414
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg_addr                          "0xB802E414"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg                               0xB802E414
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_inst_addr                         "0x0005"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg4_shift       (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg3_shift       (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg2_shift       (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg1_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg4_mask        (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg3_mask        (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg2_mask        (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg1_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg4(data)       (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg3(data)       (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg2(data)       (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_chroma_gain_tab0_seg1(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_get_chroma_gain_tab0_seg4(data)   ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_get_chroma_gain_tab0_seg3(data)   ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_get_chroma_gain_tab0_seg2(data)   ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_get_chroma_gain_tab0_seg1(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1                                   0x1802E418
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg_addr                          "0xB802E418"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg                               0xB802E418
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_inst_addr                         "0x0006"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg8_shift       (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg7_shift       (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg6_shift       (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg5_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg8_mask        (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg7_mask        (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg6_mask        (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg5_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg8(data)       (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg7(data)       (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg6(data)       (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_chroma_gain_tab0_seg5(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_get_chroma_gain_tab0_seg8(data)   ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_get_chroma_gain_tab0_seg7(data)   ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_get_chroma_gain_tab0_seg6(data)   ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_get_chroma_gain_tab0_seg5(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2                                   0x1802E41C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg_addr                          "0xB802E41C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg                               0xB802E41C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_inst_addr                         "0x0007"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg12_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg11_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg10_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg9_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg12_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg11_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg10_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg9_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg12(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg11(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg10(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_chroma_gain_tab0_seg9(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_get_chroma_gain_tab0_seg12(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_get_chroma_gain_tab0_seg11(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_get_chroma_gain_tab0_seg10(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_get_chroma_gain_tab0_seg9(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3                                   0x1802E420
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg_addr                          "0xB802E420"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg                               0xB802E420
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_inst_addr                         "0x0008"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg16_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg15_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg14_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg13_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg16_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg15_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg14_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg13_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg16(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg15(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg14(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_chroma_gain_tab0_seg13(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_get_chroma_gain_tab0_seg16(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_get_chroma_gain_tab0_seg15(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_get_chroma_gain_tab0_seg14(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_get_chroma_gain_tab0_seg13(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4                                   0x1802E424
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg_addr                          "0xB802E424"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg                               0xB802E424
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_inst_addr                         "0x0009"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg20_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg19_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg18_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg17_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg20_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg19_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg18_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg17_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg20(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg19(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg18(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_chroma_gain_tab0_seg17(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_get_chroma_gain_tab0_seg20(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_get_chroma_gain_tab0_seg19(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_get_chroma_gain_tab0_seg18(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_get_chroma_gain_tab0_seg17(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5                                   0x1802E428
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg_addr                          "0xB802E428"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg                               0xB802E428
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_inst_addr                         "0x000A"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg24_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg23_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg22_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg21_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg24_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg23_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg22_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg21_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg24(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg23(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg22(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_chroma_gain_tab0_seg21(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_get_chroma_gain_tab0_seg24(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_get_chroma_gain_tab0_seg23(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_get_chroma_gain_tab0_seg22(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_get_chroma_gain_tab0_seg21(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6                                   0x1802E42C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg_addr                          "0xB802E42C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg                               0xB802E42C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_inst_addr                         "0x000B"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg28_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg27_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg26_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg25_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg28_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg27_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg26_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg25_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg28(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg27(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg26(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_chroma_gain_tab0_seg25(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_get_chroma_gain_tab0_seg28(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_get_chroma_gain_tab0_seg27(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_get_chroma_gain_tab0_seg26(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_get_chroma_gain_tab0_seg25(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7                                   0x1802E430
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg_addr                          "0xB802E430"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg                               0xB802E430
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_inst_addr                         "0x000C"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg32_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg31_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg30_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg29_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg32_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg31_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg30_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg29_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg32(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg31(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg30(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_chroma_gain_tab0_seg29(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_get_chroma_gain_tab0_seg32(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_get_chroma_gain_tab0_seg31(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_get_chroma_gain_tab0_seg30(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_get_chroma_gain_tab0_seg29(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8                                   0x1802E500
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg_addr                          "0xB802E500"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg                               0xB802E500
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_inst_addr                         "0x000D"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg36_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg35_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg34_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg33_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg36_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg35_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg34_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg33_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg36(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg35(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg34(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_chroma_gain_tab0_seg33(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_get_chroma_gain_tab0_seg36(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_get_chroma_gain_tab0_seg35(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_get_chroma_gain_tab0_seg34(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_get_chroma_gain_tab0_seg33(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9                                   0x1802E504
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg_addr                          "0xB802E504"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg                               0xB802E504
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_inst_addr                         "0x000E"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg40_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg39_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg38_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg37_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg40_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg39_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg38_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg37_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg40(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg39(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg38(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_chroma_gain_tab0_seg37(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_get_chroma_gain_tab0_seg40(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_get_chroma_gain_tab0_seg39(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_get_chroma_gain_tab0_seg38(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_get_chroma_gain_tab0_seg37(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10                                  0x1802E508
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg_addr                         "0xB802E508"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg                              0xB802E508
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_inst_addr                        "0x000F"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg44_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg43_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg42_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg41_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg44_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg43_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg42_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg41_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg44(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg43(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg42(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_chroma_gain_tab0_seg41(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_get_chroma_gain_tab0_seg44(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_get_chroma_gain_tab0_seg43(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_get_chroma_gain_tab0_seg42(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_get_chroma_gain_tab0_seg41(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11                                  0x1802E50C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg_addr                         "0xB802E50C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg                              0xB802E50C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_inst_addr                        "0x0010"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg48_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg47_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg46_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg45_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg48_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg47_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg46_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg45_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg48(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg47(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg46(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_chroma_gain_tab0_seg45(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_get_chroma_gain_tab0_seg48(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_get_chroma_gain_tab0_seg47(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_get_chroma_gain_tab0_seg46(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_get_chroma_gain_tab0_seg45(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12                                  0x1802E510
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg_addr                         "0xB802E510"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg                              0xB802E510
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_inst_addr                        "0x0011"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg52_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg51_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg50_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg49_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg52_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg51_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg50_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg49_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg52(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg51(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg50(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_chroma_gain_tab0_seg49(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_get_chroma_gain_tab0_seg52(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_get_chroma_gain_tab0_seg51(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_get_chroma_gain_tab0_seg50(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_get_chroma_gain_tab0_seg49(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13                                  0x1802E514
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg_addr                         "0xB802E514"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg                              0xB802E514
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_inst_addr                        "0x0012"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg56_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg55_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg54_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg53_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg56_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg55_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg54_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg53_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg56(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg55(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg54(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_chroma_gain_tab0_seg53(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_get_chroma_gain_tab0_seg56(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_get_chroma_gain_tab0_seg55(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_get_chroma_gain_tab0_seg54(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_get_chroma_gain_tab0_seg53(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14                                  0x1802E518
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg_addr                         "0xB802E518"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg                              0xB802E518
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_inst_addr                        "0x0013"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg60_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg59_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg58_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg57_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg60_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg59_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg58_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg57_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg60(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg59(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg58(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_chroma_gain_tab0_seg57(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_get_chroma_gain_tab0_seg60(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_get_chroma_gain_tab0_seg59(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_get_chroma_gain_tab0_seg58(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_get_chroma_gain_tab0_seg57(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15                                  0x1802E51C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg_addr                         "0xB802E51C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg                              0xB802E51C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_inst_addr                        "0x0014"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg64_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg63_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg62_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg61_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg64_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg63_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg62_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg61_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg64(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg63(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg62(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_chroma_gain_tab0_seg61(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_get_chroma_gain_tab0_seg64(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_get_chroma_gain_tab0_seg63(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_get_chroma_gain_tab0_seg62(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_get_chroma_gain_tab0_seg61(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0                                   0x1802E434
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg_addr                          "0xB802E434"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg                               0xB802E434
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_inst_addr                         "0x0015"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg4_shift       (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg3_shift       (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg2_shift       (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg1_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg4_mask        (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg3_mask        (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg2_mask        (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg1_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg4(data)       (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg3(data)       (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg2(data)       (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_chroma_gain_tab1_seg1(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_get_chroma_gain_tab1_seg4(data)   ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_get_chroma_gain_tab1_seg3(data)   ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_get_chroma_gain_tab1_seg2(data)   ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_get_chroma_gain_tab1_seg1(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1                                   0x1802E438
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg_addr                          "0xB802E438"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg                               0xB802E438
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_inst_addr                         "0x0016"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg8_shift       (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg7_shift       (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg6_shift       (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg5_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg8_mask        (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg7_mask        (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg6_mask        (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg5_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg8(data)       (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg7(data)       (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg6(data)       (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_chroma_gain_tab1_seg5(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_get_chroma_gain_tab1_seg8(data)   ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_get_chroma_gain_tab1_seg7(data)   ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_get_chroma_gain_tab1_seg6(data)   ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_get_chroma_gain_tab1_seg5(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2                                   0x1802E43C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg_addr                          "0xB802E43C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg                               0xB802E43C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_inst_addr                         "0x0017"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg12_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg11_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg10_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg9_shift       (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg12_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg11_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg10_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg9_mask        (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg12(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg11(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg10(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_chroma_gain_tab1_seg9(data)       (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_get_chroma_gain_tab1_seg12(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_get_chroma_gain_tab1_seg11(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_get_chroma_gain_tab1_seg10(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_get_chroma_gain_tab1_seg9(data)   (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3                                   0x1802E440
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg_addr                          "0xB802E440"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg                               0xB802E440
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_inst_addr                         "0x0018"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg16_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg15_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg14_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg13_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg16_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg15_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg14_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg13_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg16(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg15(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg14(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_chroma_gain_tab1_seg13(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_get_chroma_gain_tab1_seg16(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_get_chroma_gain_tab1_seg15(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_get_chroma_gain_tab1_seg14(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_get_chroma_gain_tab1_seg13(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4                                   0x1802E444
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg_addr                          "0xB802E444"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg                               0xB802E444
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_inst_addr                         "0x0019"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg20_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg19_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg18_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg17_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg20_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg19_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg18_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg17_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg20(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg19(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg18(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_chroma_gain_tab1_seg17(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_get_chroma_gain_tab1_seg20(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_get_chroma_gain_tab1_seg19(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_get_chroma_gain_tab1_seg18(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_get_chroma_gain_tab1_seg17(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5                                   0x1802E448
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg_addr                          "0xB802E448"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg                               0xB802E448
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_inst_addr                         "0x001A"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg24_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg23_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg22_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg21_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg24_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg23_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg22_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg21_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg24(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg23(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg22(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_chroma_gain_tab1_seg21(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_get_chroma_gain_tab1_seg24(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_get_chroma_gain_tab1_seg23(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_get_chroma_gain_tab1_seg22(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_get_chroma_gain_tab1_seg21(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6                                   0x1802E44C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg_addr                          "0xB802E44C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg                               0xB802E44C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_inst_addr                         "0x001B"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg28_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg27_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg26_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg25_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg28_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg27_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg26_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg25_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg28(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg27(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg26(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_chroma_gain_tab1_seg25(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_get_chroma_gain_tab1_seg28(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_get_chroma_gain_tab1_seg27(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_get_chroma_gain_tab1_seg26(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_get_chroma_gain_tab1_seg25(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7                                   0x1802E450
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg_addr                          "0xB802E450"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg                               0xB802E450
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_inst_addr                         "0x001C"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg32_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg31_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg30_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg29_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg32_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg31_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg30_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg29_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg32(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg31(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg30(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_chroma_gain_tab1_seg29(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_get_chroma_gain_tab1_seg32(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_get_chroma_gain_tab1_seg31(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_get_chroma_gain_tab1_seg30(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_get_chroma_gain_tab1_seg29(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8                                   0x1802E520
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg_addr                          "0xB802E520"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg                               0xB802E520
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_inst_addr                         "0x001D"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg36_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg35_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg34_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg33_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg36_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg35_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg34_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg33_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg36(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg35(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg34(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_chroma_gain_tab1_seg33(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_get_chroma_gain_tab1_seg36(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_get_chroma_gain_tab1_seg35(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_get_chroma_gain_tab1_seg34(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_get_chroma_gain_tab1_seg33(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9                                   0x1802E524
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg_addr                          "0xB802E524"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg                               0xB802E524
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_inst_addr                         "0x001E"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg                           (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg40_shift      (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg39_shift      (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg38_shift      (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg37_shift      (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg40_mask       (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg39_mask       (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg38_mask       (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg37_mask       (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg40(data)      (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg39(data)      (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg38(data)      (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_chroma_gain_tab1_seg37(data)      (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_get_chroma_gain_tab1_seg40(data)  ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_get_chroma_gain_tab1_seg39(data)  ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_get_chroma_gain_tab1_seg38(data)  ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_get_chroma_gain_tab1_seg37(data)  (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10                                  0x1802E528
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg_addr                         "0xB802E528"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg                              0xB802E528
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_inst_addr                        "0x001F"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg44_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg43_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg42_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg41_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg44_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg43_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg42_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg41_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg44(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg43(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg42(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_chroma_gain_tab1_seg41(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_get_chroma_gain_tab1_seg44(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_get_chroma_gain_tab1_seg43(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_get_chroma_gain_tab1_seg42(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_get_chroma_gain_tab1_seg41(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11                                  0x1802E52C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg_addr                         "0xB802E52C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg                              0xB802E52C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_inst_addr                        "0x0020"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg48_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg47_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg46_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg45_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg48_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg47_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg46_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg45_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg48(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg47(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg46(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_chroma_gain_tab1_seg45(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_get_chroma_gain_tab1_seg48(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_get_chroma_gain_tab1_seg47(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_get_chroma_gain_tab1_seg46(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_get_chroma_gain_tab1_seg45(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12                                  0x1802E530
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg_addr                         "0xB802E530"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg                              0xB802E530
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_inst_addr                        "0x0021"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg52_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg51_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg50_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg49_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg52_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg51_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg50_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg49_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg52(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg51(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg50(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_chroma_gain_tab1_seg49(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_get_chroma_gain_tab1_seg52(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_get_chroma_gain_tab1_seg51(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_get_chroma_gain_tab1_seg50(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_get_chroma_gain_tab1_seg49(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13                                  0x1802E534
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg_addr                         "0xB802E534"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg                              0xB802E534
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_inst_addr                        "0x0022"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg56_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg55_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg54_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg53_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg56_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg55_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg54_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg53_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg56(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg55(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg54(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_chroma_gain_tab1_seg53(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_get_chroma_gain_tab1_seg56(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_get_chroma_gain_tab1_seg55(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_get_chroma_gain_tab1_seg54(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_get_chroma_gain_tab1_seg53(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14                                  0x1802E538
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg_addr                         "0xB802E538"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg                              0xB802E538
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_inst_addr                        "0x0023"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg60_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg59_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg58_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg57_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg60_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg59_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg58_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg57_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg60(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg59(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg58(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_chroma_gain_tab1_seg57(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_get_chroma_gain_tab1_seg60(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_get_chroma_gain_tab1_seg59(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_get_chroma_gain_tab1_seg58(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_get_chroma_gain_tab1_seg57(data) (0x0000007F&(data))

#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15                                  0x1802E53C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg_addr                         "0xB802E53C"
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg                              0xB802E53C
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_inst_addr                        "0x0024"
#define  set_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg)=data)
#define  get_COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg                          (*((volatile unsigned int*)COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg64_shift     (24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg63_shift     (16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg62_shift     (8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg61_shift     (0)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg64_mask      (0x7F000000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg63_mask      (0x007F0000)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg62_mask      (0x00007F00)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg61_mask      (0x0000007F)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg64(data)     (0x7F000000&((data)<<24))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg63(data)     (0x007F0000&((data)<<16))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg62(data)     (0x00007F00&((data)<<8))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_chroma_gain_tab1_seg61(data)     (0x0000007F&(data))
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_get_chroma_gain_tab1_seg64(data) ((0x7F000000&(data))>>24)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_get_chroma_gain_tab1_seg63(data) ((0x007F0000&(data))>>16)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_get_chroma_gain_tab1_seg62(data) ((0x00007F00&(data))>>8)
#define  COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_get_chroma_gain_tab1_seg61(data) (0x0000007F&(data))

#define  COLOR_DCC_SRAM_TAB_CTL_0                                                0x1802E454
#define  COLOR_DCC_SRAM_TAB_CTL_0_reg_addr                                       "0xB802E454"
#define  COLOR_DCC_SRAM_TAB_CTL_0_reg                                            0xB802E454
#define  COLOR_DCC_SRAM_TAB_CTL_0_inst_addr                                      "0x0025"
#define  set_COLOR_DCC_SRAM_TAB_CTL_0_reg(data)                                  (*((volatile unsigned int*)COLOR_DCC_SRAM_TAB_CTL_0_reg)=data)
#define  get_COLOR_DCC_SRAM_TAB_CTL_0_reg                                        (*((volatile unsigned int*)COLOR_DCC_SRAM_TAB_CTL_0_reg))
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index_cur_shift                   (10)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index_shift                       (4)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_rw_sel_shift                          (2)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_sel_shift                         (1)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_ready_shift                       (0)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index_cur_mask                    (0x0000FC00)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index_mask                        (0x000003F0)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_rw_sel_mask                           (0x0000000C)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_sel_mask                          (0x00000002)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_ready_mask                        (0x00000001)
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index_cur(data)                   (0x0000FC00&((data)<<10))
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_index(data)                       (0x000003F0&((data)<<4))
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_rw_sel(data)                          (0x0000000C&((data)<<2))
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_sel(data)                         (0x00000002&((data)<<1))
#define  COLOR_DCC_SRAM_TAB_CTL_0_sram_tab_acc_ready(data)                       (0x00000001&(data))
#define  COLOR_DCC_SRAM_TAB_CTL_0_get_sram_tab_acc_index_cur(data)               ((0x0000FC00&(data))>>10)
#define  COLOR_DCC_SRAM_TAB_CTL_0_get_sram_tab_acc_index(data)                   ((0x000003F0&(data))>>4)
#define  COLOR_DCC_SRAM_TAB_CTL_0_get_sram_tab_rw_sel(data)                      ((0x0000000C&(data))>>2)
#define  COLOR_DCC_SRAM_TAB_CTL_0_get_sram_tab_acc_sel(data)                     ((0x00000002&(data))>>1)
#define  COLOR_DCC_SRAM_TAB_CTL_0_get_sram_tab_acc_ready(data)                   (0x00000001&(data))

#define  COLOR_DCC_SRAM_TAB_PORT                                                 0x1802E458
#define  COLOR_DCC_SRAM_TAB_PORT_reg_addr                                        "0xB802E458"
#define  COLOR_DCC_SRAM_TAB_PORT_reg                                             0xB802E458
#define  COLOR_DCC_SRAM_TAB_PORT_inst_addr                                       "0x0026"
#define  set_COLOR_DCC_SRAM_TAB_PORT_reg(data)                                   (*((volatile unsigned int*)COLOR_DCC_SRAM_TAB_PORT_reg)=data)
#define  get_COLOR_DCC_SRAM_TAB_PORT_reg                                         (*((volatile unsigned int*)COLOR_DCC_SRAM_TAB_PORT_reg))
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_base_shift                             (16)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g0_shift                               (8)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g1_shift                               (0)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_base_mask                              (0x03FF0000)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g0_mask                                (0x0000FF00)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g1_mask                                (0x000000FF)
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_base(data)                             (0x03FF0000&((data)<<16))
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g0(data)                               (0x0000FF00&((data)<<8))
#define  COLOR_DCC_SRAM_TAB_PORT_sram_tab_g1(data)                               (0x000000FF&(data))
#define  COLOR_DCC_SRAM_TAB_PORT_get_sram_tab_base(data)                         ((0x03FF0000&(data))>>16)
#define  COLOR_DCC_SRAM_TAB_PORT_get_sram_tab_g0(data)                           ((0x0000FF00&(data))>>8)
#define  COLOR_DCC_SRAM_TAB_PORT_get_sram_tab_g1(data)                           (0x000000FF&(data))

#define  COLOR_DCC_SRAM_USER_TAB_CTL_0                                           0x1802E540
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_reg_addr                                  "0xB802E540"
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_reg                                       0xB802E540
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_inst_addr                                 "0x0027"
#define  set_COLOR_DCC_SRAM_USER_TAB_CTL_0_reg(data)                             (*((volatile unsigned int*)COLOR_DCC_SRAM_USER_TAB_CTL_0_reg)=data)
#define  get_COLOR_DCC_SRAM_USER_TAB_CTL_0_reg                                   (*((volatile unsigned int*)COLOR_DCC_SRAM_USER_TAB_CTL_0_reg))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index_cur_shift         (10)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index_shift             (4)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_rw_sel_shift                (2)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_sel_shift               (1)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_ready_shift             (0)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index_cur_mask          (0x0000FC00)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index_mask              (0x000003F0)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_rw_sel_mask                 (0x0000000C)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_sel_mask                (0x00000002)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_ready_mask              (0x00000001)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index_cur(data)         (0x0000FC00&((data)<<10))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_index(data)             (0x000003F0&((data)<<4))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_rw_sel(data)                (0x0000000C&((data)<<2))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_sel(data)               (0x00000002&((data)<<1))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_sram_user_tab_acc_ready(data)             (0x00000001&(data))
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_get_sram_user_tab_acc_index_cur(data)     ((0x0000FC00&(data))>>10)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_get_sram_user_tab_acc_index(data)         ((0x000003F0&(data))>>4)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_get_sram_user_tab_rw_sel(data)            ((0x0000000C&(data))>>2)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_get_sram_user_tab_acc_sel(data)           ((0x00000002&(data))>>1)
#define  COLOR_DCC_SRAM_USER_TAB_CTL_0_get_sram_user_tab_acc_ready(data)         (0x00000001&(data))

#define  COLOR_DCC_SRAM_USER_TAB_PORT                                            0x1802E544
#define  COLOR_DCC_SRAM_USER_TAB_PORT_reg_addr                                   "0xB802E544"
#define  COLOR_DCC_SRAM_USER_TAB_PORT_reg                                        0xB802E544
#define  COLOR_DCC_SRAM_USER_TAB_PORT_inst_addr                                  "0x0028"
#define  set_COLOR_DCC_SRAM_USER_TAB_PORT_reg(data)                              (*((volatile unsigned int*)COLOR_DCC_SRAM_USER_TAB_PORT_reg)=data)
#define  get_COLOR_DCC_SRAM_USER_TAB_PORT_reg                                    (*((volatile unsigned int*)COLOR_DCC_SRAM_USER_TAB_PORT_reg))
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_base_shift                   (16)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g0_shift                     (8)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g1_shift                     (0)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_base_mask                    (0x03FF0000)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g0_mask                      (0x0000FF00)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g1_mask                      (0x000000FF)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_base(data)                   (0x03FF0000&((data)<<16))
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g0(data)                     (0x0000FF00&((data)<<8))
#define  COLOR_DCC_SRAM_USER_TAB_PORT_sram_user_tab_g1(data)                     (0x000000FF&(data))
#define  COLOR_DCC_SRAM_USER_TAB_PORT_get_sram_user_tab_base(data)               ((0x03FF0000&(data))>>16)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_get_sram_user_tab_g0(data)                 ((0x0000FF00&(data))>>8)
#define  COLOR_DCC_SRAM_USER_TAB_PORT_get_sram_user_tab_g1(data)                 (0x000000FF&(data))

#define  COLOR_DCC_D_DCC_DB_CTRL                                                 0x1802E45C
#define  COLOR_DCC_D_DCC_DB_CTRL_reg_addr                                        "0xB802E45C"
#define  COLOR_DCC_D_DCC_DB_CTRL_reg                                             0xB802E45C
#define  COLOR_DCC_D_DCC_DB_CTRL_inst_addr                                       "0x0029"
#define  set_COLOR_DCC_D_DCC_DB_CTRL_reg(data)                                   (*((volatile unsigned int*)COLOR_DCC_D_DCC_DB_CTRL_reg)=data)
#define  get_COLOR_DCC_D_DCC_DB_CTRL_reg                                         (*((volatile unsigned int*)COLOR_DCC_D_DCC_DB_CTRL_reg))
#define  COLOR_DCC_D_DCC_DB_CTRL_db_en_shift                                     (2)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_read_level_shift                             (1)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_apply_shift                                  (0)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_en_mask                                      (0x00000004)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_read_level_mask                              (0x00000002)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_apply_mask                                   (0x00000001)
#define  COLOR_DCC_D_DCC_DB_CTRL_db_en(data)                                     (0x00000004&((data)<<2))
#define  COLOR_DCC_D_DCC_DB_CTRL_db_read_level(data)                             (0x00000002&((data)<<1))
#define  COLOR_DCC_D_DCC_DB_CTRL_db_apply(data)                                  (0x00000001&(data))
#define  COLOR_DCC_D_DCC_DB_CTRL_get_db_en(data)                                 ((0x00000004&(data))>>2)
#define  COLOR_DCC_D_DCC_DB_CTRL_get_db_read_level(data)                         ((0x00000002&(data))>>1)
#define  COLOR_DCC_D_DCC_DB_CTRL_get_db_apply(data)                              (0x00000001&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_EN                                            0x1802E460
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_reg_addr                                   "0xB802E460"
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_reg                                        0xB802E460
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_inst_addr                                  "0x002A"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_EN_reg(data)                              (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_EN_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_EN_reg                                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_EN_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_en_shift             (18)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_sel_shift            (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_mode_shift                      (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_ratio_lpf_en_shift                         (7)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg0_en_shift                   (4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg1_en_shift                   (3)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg2_en_shift                   (2)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg3_en_shift                   (1)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_en_shift                        (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_en_mask              (0x00040000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_sel_mask             (0x00030000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_mode_mask                       (0x00000100)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_ratio_lpf_en_mask                          (0x00000080)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg0_en_mask                    (0x00000010)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg1_en_mask                    (0x00000008)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg2_en_mask                    (0x00000004)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg3_en_mask                    (0x00000002)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_en_mask                         (0x00000001)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_en(data)             (0x00040000&((data)<<18))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_debug_mode_sel(data)            (0x00030000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_mode(data)                      (0x00000100&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_ratio_lpf_en(data)                         (0x00000080&((data)<<7))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg0_en(data)                   (0x00000010&((data)<<4))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg1_en(data)                   (0x00000008&((data)<<3))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg2_en(data)                   (0x00000004&((data)<<2))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_reg3_en(data)                   (0x00000002&((data)<<1))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_y_blending_en(data)                        (0x00000001&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_debug_mode_en(data)         ((0x00040000&(data))>>18)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_debug_mode_sel(data)        ((0x00030000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_mode(data)                  ((0x00000100&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_ratio_lpf_en(data)                     ((0x00000080&(data))>>7)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_reg0_en(data)               ((0x00000010&(data))>>4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_reg1_en(data)               ((0x00000008&(data))>>3)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_reg2_en(data)               ((0x00000004&(data))>>2)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_reg3_en(data)               ((0x00000002&(data))>>1)
#define  COLOR_DCC_D_DCC_SKIN_TONE_EN_get_y_blending_en(data)                    (0x00000001&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0                                  0x1802E464
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg_addr                         "0xB802E464"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg                              0xB802E464
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_inst_addr                        "0x002B"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_y_center_shift      (20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_u_center_shift      (10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_v_center_shift      (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_y_center_mask       (0x3FF00000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_u_center_mask       (0x000FFC00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_v_center_mask       (0x000003FF)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_y_center(data)      (0x3FF00000&((data)<<20))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_u_center(data)      (0x000FFC00&((data)<<10))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_y_blending_0_v_center(data)      (0x000003FF&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_get_y_blending_0_y_center(data)  ((0x3FF00000&(data))>>20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_get_y_blending_0_u_center(data)  ((0x000FFC00&(data))>>10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_get_y_blending_0_v_center(data)  (0x000003FF&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0                                   0x1802E468
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg_addr                          "0xB802E468"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg                               0xB802E468
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_inst_addr                         "0x002C"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg                           (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_y_range_shift        (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_u_range_shift        (4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_v_range_shift        (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_y_range_mask         (0x00000F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_u_range_mask         (0x000000F0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_v_range_mask         (0x0000000F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_y_range(data)        (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_u_range(data)        (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_y_blending_0_v_range(data)        (0x0000000F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_get_y_blending_0_y_range(data)    ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_get_y_blending_0_u_range(data)    ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_get_y_blending_0_v_range(data)    (0x0000000F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1                                  0x1802E46C
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg_addr                         "0xB802E46C"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg                              0xB802E46C
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_inst_addr                        "0x002D"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_y_center_shift      (20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_u_center_shift      (10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_v_center_shift      (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_y_center_mask       (0x3FF00000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_u_center_mask       (0x000FFC00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_v_center_mask       (0x000003FF)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_y_center(data)      (0x3FF00000&((data)<<20))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_u_center(data)      (0x000FFC00&((data)<<10))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_y_blending_1_v_center(data)      (0x000003FF&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_get_y_blending_1_y_center(data)  ((0x3FF00000&(data))>>20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_get_y_blending_1_u_center(data)  ((0x000FFC00&(data))>>10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_get_y_blending_1_v_center(data)  (0x000003FF&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1                                   0x1802E470
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg_addr                          "0xB802E470"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg                               0xB802E470
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_inst_addr                         "0x002E"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg                           (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_y_range_shift        (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_u_range_shift        (4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_v_range_shift        (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_y_range_mask         (0x00000F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_u_range_mask         (0x000000F0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_v_range_mask         (0x0000000F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_y_range(data)        (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_u_range(data)        (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_y_blending_1_v_range(data)        (0x0000000F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_get_y_blending_1_y_range(data)    ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_get_y_blending_1_u_range(data)    ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_get_y_blending_1_v_range(data)    (0x0000000F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2                                  0x1802E474
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg_addr                         "0xB802E474"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg                              0xB802E474
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_inst_addr                        "0x002F"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_y_center_shift      (20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_u_center_shift      (10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_v_center_shift      (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_y_center_mask       (0x3FF00000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_u_center_mask       (0x000FFC00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_v_center_mask       (0x000003FF)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_y_center(data)      (0x3FF00000&((data)<<20))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_u_center(data)      (0x000FFC00&((data)<<10))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_y_blending_2_v_center(data)      (0x000003FF&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_get_y_blending_2_y_center(data)  ((0x3FF00000&(data))>>20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_get_y_blending_2_u_center(data)  ((0x000FFC00&(data))>>10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_get_y_blending_2_v_center(data)  (0x000003FF&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2                                   0x1802E478
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg_addr                          "0xB802E478"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg                               0xB802E478
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_inst_addr                         "0x0030"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg                           (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_y_range_shift        (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_u_range_shift        (4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_v_range_shift        (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_y_range_mask         (0x00000F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_u_range_mask         (0x000000F0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_v_range_mask         (0x0000000F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_y_range(data)        (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_u_range(data)        (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_y_blending_2_v_range(data)        (0x0000000F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_get_y_blending_2_y_range(data)    ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_get_y_blending_2_u_range(data)    ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_get_y_blending_2_v_range(data)    (0x0000000F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3                                  0x1802E47C
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg_addr                         "0xB802E47C"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg                              0xB802E47C
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_inst_addr                        "0x0031"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_y_center_shift      (20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_u_center_shift      (10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_v_center_shift      (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_y_center_mask       (0x3FF00000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_u_center_mask       (0x000FFC00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_v_center_mask       (0x000003FF)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_y_center(data)      (0x3FF00000&((data)<<20))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_u_center(data)      (0x000FFC00&((data)<<10))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_y_blending_3_v_center(data)      (0x000003FF&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_get_y_blending_3_y_center(data)  ((0x3FF00000&(data))>>20)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_get_y_blending_3_u_center(data)  ((0x000FFC00&(data))>>10)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_get_y_blending_3_v_center(data)  (0x000003FF&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3                                   0x1802E480
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg_addr                          "0xB802E480"
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg                               0xB802E480
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_inst_addr                         "0x0032"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg(data)                     (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg                           (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_y_range_shift        (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_u_range_shift        (4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_v_range_shift        (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_y_range_mask         (0x00000F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_u_range_mask         (0x000000F0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_v_range_mask         (0x0000000F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_y_range(data)        (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_u_range(data)        (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_y_blending_3_v_range(data)        (0x0000000F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_get_y_blending_3_y_range(data)    ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_get_y_blending_3_u_range(data)    ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_get_y_blending_3_v_range(data)    (0x0000000F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0                                    0x1802E484
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg_addr                           "0xB802E484"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg                                0xB802E484
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_inst_addr                          "0x0033"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_0_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_1_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_2_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_3_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_0_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_1_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_2_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_3_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_0(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_1(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_2(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_y_blending_0_ratio_3(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_get_y_blending_0_ratio_0(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_get_y_blending_0_ratio_1(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_get_y_blending_0_ratio_2(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_get_y_blending_0_ratio_3(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1                                    0x1802E488
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg_addr                           "0xB802E488"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg                                0xB802E488
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_inst_addr                          "0x0034"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_4_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_5_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_6_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_7_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_4_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_5_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_6_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_7_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_4(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_5(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_6(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_y_blending_0_ratio_7(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_get_y_blending_0_ratio_4(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_get_y_blending_0_ratio_5(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_get_y_blending_0_ratio_6(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_get_y_blending_0_ratio_7(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0                                    0x1802E48C
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg_addr                           "0xB802E48C"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg                                0xB802E48C
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_inst_addr                          "0x0035"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_0_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_1_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_2_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_3_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_0_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_1_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_2_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_3_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_0(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_1(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_2(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_y_blending_1_ratio_3(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_get_y_blending_1_ratio_0(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_get_y_blending_1_ratio_1(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_get_y_blending_1_ratio_2(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_get_y_blending_1_ratio_3(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1                                    0x1802E490
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg_addr                           "0xB802E490"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg                                0xB802E490
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_inst_addr                          "0x0036"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_4_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_5_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_6_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_7_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_4_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_5_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_6_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_7_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_4(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_5(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_6(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_y_blending_1_ratio_7(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_get_y_blending_1_ratio_4(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_get_y_blending_1_ratio_5(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_get_y_blending_1_ratio_6(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_get_y_blending_1_ratio_7(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0                                    0x1802E494
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg_addr                           "0xB802E494"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg                                0xB802E494
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_inst_addr                          "0x0037"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_0_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_1_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_2_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_3_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_0_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_1_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_2_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_3_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_0(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_1(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_2(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_y_blending_2_ratio_3(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_get_y_blending_2_ratio_0(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_get_y_blending_2_ratio_1(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_get_y_blending_2_ratio_2(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_get_y_blending_2_ratio_3(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1                                    0x1802E498
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg_addr                           "0xB802E498"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg                                0xB802E498
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_inst_addr                          "0x0038"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_4_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_5_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_6_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_7_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_4_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_5_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_6_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_7_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_4(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_5(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_6(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_y_blending_2_ratio_7(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_get_y_blending_2_ratio_4(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_get_y_blending_2_ratio_5(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_get_y_blending_2_ratio_6(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_get_y_blending_2_ratio_7(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0                                    0x1802E49C
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg_addr                           "0xB802E49C"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg                                0xB802E49C
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_inst_addr                          "0x0039"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_0_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_1_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_2_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_3_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_0_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_1_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_2_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_3_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_0(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_1(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_2(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_y_blending_3_ratio_3(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_get_y_blending_3_ratio_0(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_get_y_blending_3_ratio_1(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_get_y_blending_3_ratio_2(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_get_y_blending_3_ratio_3(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1                                    0x1802E4A0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg_addr                           "0xB802E4A0"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg                                0xB802E4A0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_inst_addr                          "0x003A"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg(data)                      (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg                            (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_4_shift         (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_5_shift         (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_6_shift         (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_7_shift         (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_4_mask          (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_5_mask          (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_6_mask          (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_7_mask          (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_4(data)         (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_5(data)         (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_6(data)         (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_y_blending_3_ratio_7(data)         (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_get_y_blending_3_ratio_4(data)     ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_get_y_blending_3_ratio_5(data)     ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_get_y_blending_3_ratio_6(data)     ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_get_y_blending_3_ratio_7(data)     (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0                                  0x1802E4A4
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg_addr                         "0xB802E4A4"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg                              0xB802E4A4
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_inst_addr                        "0x003B"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_0_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_1_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_2_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_3_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_0_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_1_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_2_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_3_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_0(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_1(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_2(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_c_blending_0_ratio_3(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_get_c_blending_0_ratio_0(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_get_c_blending_0_ratio_1(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_get_c_blending_0_ratio_2(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_get_c_blending_0_ratio_3(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1                                  0x1802E4A8
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg_addr                         "0xB802E4A8"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg                              0xB802E4A8
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_inst_addr                        "0x003C"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_4_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_5_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_6_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_7_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_4_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_5_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_6_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_7_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_4(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_5(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_6(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_c_blending_0_ratio_7(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_get_c_blending_0_ratio_4(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_get_c_blending_0_ratio_5(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_get_c_blending_0_ratio_6(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_get_c_blending_0_ratio_7(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0                                  0x1802E4AC
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg_addr                         "0xB802E4AC"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg                              0xB802E4AC
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_inst_addr                        "0x003D"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_0_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_1_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_2_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_3_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_0_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_1_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_2_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_3_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_0(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_1(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_2(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_c_blending_1_ratio_3(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_get_c_blending_1_ratio_0(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_get_c_blending_1_ratio_1(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_get_c_blending_1_ratio_2(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_get_c_blending_1_ratio_3(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1                                  0x1802E4B0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg_addr                         "0xB802E4B0"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg                              0xB802E4B0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_inst_addr                        "0x003E"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_4_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_5_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_6_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_7_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_4_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_5_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_6_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_7_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_4(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_5(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_6(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_c_blending_1_ratio_7(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_get_c_blending_1_ratio_4(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_get_c_blending_1_ratio_5(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_get_c_blending_1_ratio_6(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_get_c_blending_1_ratio_7(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0                                  0x1802E4B4
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg_addr                         "0xB802E4B4"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg                              0xB802E4B4
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_inst_addr                        "0x003F"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_0_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_1_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_2_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_3_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_0_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_1_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_2_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_3_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_0(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_1(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_2(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_c_blending_2_ratio_3(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_get_c_blending_2_ratio_0(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_get_c_blending_2_ratio_1(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_get_c_blending_2_ratio_2(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_get_c_blending_2_ratio_3(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1                                  0x1802E4B8
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg_addr                         "0xB802E4B8"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg                              0xB802E4B8
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_inst_addr                        "0x0040"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_4_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_5_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_6_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_7_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_4_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_5_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_6_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_7_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_4(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_5(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_6(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_c_blending_2_ratio_7(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_get_c_blending_2_ratio_4(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_get_c_blending_2_ratio_5(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_get_c_blending_2_ratio_6(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_get_c_blending_2_ratio_7(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0                                  0x1802E4BC
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg_addr                         "0xB802E4BC"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg                              0xB802E4BC
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_inst_addr                        "0x0041"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_0_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_1_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_2_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_3_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_0_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_1_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_2_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_3_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_0(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_1(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_2(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_c_blending_3_ratio_3(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_get_c_blending_3_ratio_0(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_get_c_blending_3_ratio_1(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_get_c_blending_3_ratio_2(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_get_c_blending_3_ratio_3(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1                                  0x1802E4C0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg_addr                         "0xB802E4C0"
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg                              0xB802E4C0
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_inst_addr                        "0x0042"
#define  set_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg(data)                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_4_shift       (24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_5_shift       (16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_6_shift       (8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_7_shift       (0)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_4_mask        (0x3F000000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_5_mask        (0x003F0000)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_6_mask        (0x00003F00)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_7_mask        (0x0000003F)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_4(data)       (0x3F000000&((data)<<24))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_5(data)       (0x003F0000&((data)<<16))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_6(data)       (0x00003F00&((data)<<8))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_c_blending_3_ratio_7(data)       (0x0000003F&(data))
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_get_c_blending_3_ratio_4(data)   ((0x3F000000&(data))>>24)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_get_c_blending_3_ratio_5(data)   ((0x003F0000&(data))>>16)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_get_c_blending_3_ratio_6(data)   ((0x00003F00&(data))>>8)
#define  COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_get_c_blending_3_ratio_7(data)   (0x0000003F&(data))

#define  COLOR_DCC_D_DCC_FWUSED_0                                                0x1802E4F0
#define  COLOR_DCC_D_DCC_FWUSED_0_reg_addr                                       "0xB802E4F0"
#define  COLOR_DCC_D_DCC_FWUSED_0_reg                                            0xB802E4F0
#define  COLOR_DCC_D_DCC_FWUSED_0_inst_addr                                      "0x0043"
#define  set_COLOR_DCC_D_DCC_FWUSED_0_reg(data)                                  (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_FWUSED_0_reg                                        (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_0_reg))
#define  COLOR_DCC_D_DCC_FWUSED_0_fw_0_shift                                     (0)
#define  COLOR_DCC_D_DCC_FWUSED_0_fw_0_mask                                      (0xFFFFFFFF)
#define  COLOR_DCC_D_DCC_FWUSED_0_fw_0(data)                                     (0xFFFFFFFF&(data))
#define  COLOR_DCC_D_DCC_FWUSED_0_get_fw_0(data)                                 (0xFFFFFFFF&(data))

#define  COLOR_DCC_D_DCC_FWUSED_1                                                0x1802E4F4
#define  COLOR_DCC_D_DCC_FWUSED_1_reg_addr                                       "0xB802E4F4"
#define  COLOR_DCC_D_DCC_FWUSED_1_reg                                            0xB802E4F4
#define  COLOR_DCC_D_DCC_FWUSED_1_inst_addr                                      "0x0044"
#define  set_COLOR_DCC_D_DCC_FWUSED_1_reg(data)                                  (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_FWUSED_1_reg                                        (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_1_reg))
#define  COLOR_DCC_D_DCC_FWUSED_1_fw_1_shift                                     (0)
#define  COLOR_DCC_D_DCC_FWUSED_1_fw_1_mask                                      (0xFFFFFFFF)
#define  COLOR_DCC_D_DCC_FWUSED_1_fw_1(data)                                     (0xFFFFFFFF&(data))
#define  COLOR_DCC_D_DCC_FWUSED_1_get_fw_1(data)                                 (0xFFFFFFFF&(data))

#define  COLOR_DCC_D_DCC_FWUSED_2                                                0x1802E4F8
#define  COLOR_DCC_D_DCC_FWUSED_2_reg_addr                                       "0xB802E4F8"
#define  COLOR_DCC_D_DCC_FWUSED_2_reg                                            0xB802E4F8
#define  COLOR_DCC_D_DCC_FWUSED_2_inst_addr                                      "0x0045"
#define  set_COLOR_DCC_D_DCC_FWUSED_2_reg(data)                                  (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_2_reg)=data)
#define  get_COLOR_DCC_D_DCC_FWUSED_2_reg                                        (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_2_reg))
#define  COLOR_DCC_D_DCC_FWUSED_2_fw_2_shift                                     (0)
#define  COLOR_DCC_D_DCC_FWUSED_2_fw_2_mask                                      (0xFFFFFFFF)
#define  COLOR_DCC_D_DCC_FWUSED_2_fw_2(data)                                     (0xFFFFFFFF&(data))
#define  COLOR_DCC_D_DCC_FWUSED_2_get_fw_2(data)                                 (0xFFFFFFFF&(data))

#define  COLOR_DCC_D_DCC_FWUSED_3                                                0x1802E4FC
#define  COLOR_DCC_D_DCC_FWUSED_3_reg_addr                                       "0xB802E4FC"
#define  COLOR_DCC_D_DCC_FWUSED_3_reg                                            0xB802E4FC
#define  COLOR_DCC_D_DCC_FWUSED_3_inst_addr                                      "0x0046"
#define  set_COLOR_DCC_D_DCC_FWUSED_3_reg(data)                                  (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_3_reg)=data)
#define  get_COLOR_DCC_D_DCC_FWUSED_3_reg                                        (*((volatile unsigned int*)COLOR_DCC_D_DCC_FWUSED_3_reg))
#define  COLOR_DCC_D_DCC_FWUSED_3_fw_3_shift                                     (0)
#define  COLOR_DCC_D_DCC_FWUSED_3_fw_3_mask                                      (0xFFFFFFFF)
#define  COLOR_DCC_D_DCC_FWUSED_3_fw_3(data)                                     (0xFFFFFFFF&(data))
#define  COLOR_DCC_D_DCC_FWUSED_3_get_fw_3(data)                                 (0xFFFFFFFF&(data))

#define  COLOR_DCC_D_DCC_Bist_0                                                  0x1802E4E4
#define  COLOR_DCC_D_DCC_Bist_0_reg_addr                                         "0xB802E4E4"
#define  COLOR_DCC_D_DCC_Bist_0_reg                                              0xB802E4E4
#define  COLOR_DCC_D_DCC_Bist_0_inst_addr                                        "0x0047"
#define  set_COLOR_DCC_D_DCC_Bist_0_reg(data)                                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_Bist_0_reg)=data)
#define  get_COLOR_DCC_D_DCC_Bist_0_reg                                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_Bist_0_reg))
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_1_shift                                (29)
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_0_shift                                (28)
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_1_shift                            (25)
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_0_shift                            (24)
#define  COLOR_DCC_D_DCC_Bist_0_rme_1_shift                                      (21)
#define  COLOR_DCC_D_DCC_Bist_0_rme_0_shift                                      (20)
#define  COLOR_DCC_D_DCC_Bist_0_rm_1_shift                                       (8)
#define  COLOR_DCC_D_DCC_Bist_0_rm_0_shift                                       (4)
#define  COLOR_DCC_D_DCC_Bist_0_ls_1_shift                                       (1)
#define  COLOR_DCC_D_DCC_Bist_0_ls_0_shift                                       (0)
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_1_mask                                 (0x20000000)
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_0_mask                                 (0x10000000)
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_1_mask                             (0x02000000)
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_0_mask                             (0x01000000)
#define  COLOR_DCC_D_DCC_Bist_0_rme_1_mask                                       (0x00200000)
#define  COLOR_DCC_D_DCC_Bist_0_rme_0_mask                                       (0x00100000)
#define  COLOR_DCC_D_DCC_Bist_0_rm_1_mask                                        (0x00000F00)
#define  COLOR_DCC_D_DCC_Bist_0_rm_0_mask                                        (0x000000F0)
#define  COLOR_DCC_D_DCC_Bist_0_ls_1_mask                                        (0x00000002)
#define  COLOR_DCC_D_DCC_Bist_0_ls_0_mask                                        (0x00000001)
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_1(data)                                (0x20000000&((data)<<29))
#define  COLOR_DCC_D_DCC_Bist_0_bist_fail_0(data)                                (0x10000000&((data)<<28))
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_1(data)                            (0x02000000&((data)<<25))
#define  COLOR_DCC_D_DCC_Bist_0_drf_bist_fail_0(data)                            (0x01000000&((data)<<24))
#define  COLOR_DCC_D_DCC_Bist_0_rme_1(data)                                      (0x00200000&((data)<<21))
#define  COLOR_DCC_D_DCC_Bist_0_rme_0(data)                                      (0x00100000&((data)<<20))
#define  COLOR_DCC_D_DCC_Bist_0_rm_1(data)                                       (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_Bist_0_rm_0(data)                                       (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_Bist_0_ls_1(data)                                       (0x00000002&((data)<<1))
#define  COLOR_DCC_D_DCC_Bist_0_ls_0(data)                                       (0x00000001&(data))
#define  COLOR_DCC_D_DCC_Bist_0_get_bist_fail_1(data)                            ((0x20000000&(data))>>29)
#define  COLOR_DCC_D_DCC_Bist_0_get_bist_fail_0(data)                            ((0x10000000&(data))>>28)
#define  COLOR_DCC_D_DCC_Bist_0_get_drf_bist_fail_1(data)                        ((0x02000000&(data))>>25)
#define  COLOR_DCC_D_DCC_Bist_0_get_drf_bist_fail_0(data)                        ((0x01000000&(data))>>24)
#define  COLOR_DCC_D_DCC_Bist_0_get_rme_1(data)                                  ((0x00200000&(data))>>21)
#define  COLOR_DCC_D_DCC_Bist_0_get_rme_0(data)                                  ((0x00100000&(data))>>20)
#define  COLOR_DCC_D_DCC_Bist_0_get_rm_1(data)                                   ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_Bist_0_get_rm_0(data)                                   ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_Bist_0_get_ls_1(data)                                   ((0x00000002&(data))>>1)
#define  COLOR_DCC_D_DCC_Bist_0_get_ls_0(data)                                   (0x00000001&(data))

#define  COLOR_DCC_D_DCC_Bist_1                                                  0x1802E548
#define  COLOR_DCC_D_DCC_Bist_1_reg_addr                                         "0xB802E548"
#define  COLOR_DCC_D_DCC_Bist_1_reg                                              0xB802E548
#define  COLOR_DCC_D_DCC_Bist_1_inst_addr                                        "0x0048"
#define  set_COLOR_DCC_D_DCC_Bist_1_reg(data)                                    (*((volatile unsigned int*)COLOR_DCC_D_DCC_Bist_1_reg)=data)
#define  get_COLOR_DCC_D_DCC_Bist_1_reg                                          (*((volatile unsigned int*)COLOR_DCC_D_DCC_Bist_1_reg))
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_3_shift                                (29)
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_2_shift                                (28)
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_3_shift                            (25)
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_2_shift                            (24)
#define  COLOR_DCC_D_DCC_Bist_1_rme_3_shift                                      (21)
#define  COLOR_DCC_D_DCC_Bist_1_rme_2_shift                                      (20)
#define  COLOR_DCC_D_DCC_Bist_1_rm_3_shift                                       (8)
#define  COLOR_DCC_D_DCC_Bist_1_rm_2_shift                                       (4)
#define  COLOR_DCC_D_DCC_Bist_1_ls_3_shift                                       (1)
#define  COLOR_DCC_D_DCC_Bist_1_ls_2_shift                                       (0)
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_3_mask                                 (0x20000000)
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_2_mask                                 (0x10000000)
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_3_mask                             (0x02000000)
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_2_mask                             (0x01000000)
#define  COLOR_DCC_D_DCC_Bist_1_rme_3_mask                                       (0x00200000)
#define  COLOR_DCC_D_DCC_Bist_1_rme_2_mask                                       (0x00100000)
#define  COLOR_DCC_D_DCC_Bist_1_rm_3_mask                                        (0x00000F00)
#define  COLOR_DCC_D_DCC_Bist_1_rm_2_mask                                        (0x000000F0)
#define  COLOR_DCC_D_DCC_Bist_1_ls_3_mask                                        (0x00000002)
#define  COLOR_DCC_D_DCC_Bist_1_ls_2_mask                                        (0x00000001)
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_3(data)                                (0x20000000&((data)<<29))
#define  COLOR_DCC_D_DCC_Bist_1_bist_fail_2(data)                                (0x10000000&((data)<<28))
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_3(data)                            (0x02000000&((data)<<25))
#define  COLOR_DCC_D_DCC_Bist_1_drf_bist_fail_2(data)                            (0x01000000&((data)<<24))
#define  COLOR_DCC_D_DCC_Bist_1_rme_3(data)                                      (0x00200000&((data)<<21))
#define  COLOR_DCC_D_DCC_Bist_1_rme_2(data)                                      (0x00100000&((data)<<20))
#define  COLOR_DCC_D_DCC_Bist_1_rm_3(data)                                       (0x00000F00&((data)<<8))
#define  COLOR_DCC_D_DCC_Bist_1_rm_2(data)                                       (0x000000F0&((data)<<4))
#define  COLOR_DCC_D_DCC_Bist_1_ls_3(data)                                       (0x00000002&((data)<<1))
#define  COLOR_DCC_D_DCC_Bist_1_ls_2(data)                                       (0x00000001&(data))
#define  COLOR_DCC_D_DCC_Bist_1_get_bist_fail_3(data)                            ((0x20000000&(data))>>29)
#define  COLOR_DCC_D_DCC_Bist_1_get_bist_fail_2(data)                            ((0x10000000&(data))>>28)
#define  COLOR_DCC_D_DCC_Bist_1_get_drf_bist_fail_3(data)                        ((0x02000000&(data))>>25)
#define  COLOR_DCC_D_DCC_Bist_1_get_drf_bist_fail_2(data)                        ((0x01000000&(data))>>24)
#define  COLOR_DCC_D_DCC_Bist_1_get_rme_3(data)                                  ((0x00200000&(data))>>21)
#define  COLOR_DCC_D_DCC_Bist_1_get_rme_2(data)                                  ((0x00100000&(data))>>20)
#define  COLOR_DCC_D_DCC_Bist_1_get_rm_3(data)                                   ((0x00000F00&(data))>>8)
#define  COLOR_DCC_D_DCC_Bist_1_get_rm_2(data)                                   ((0x000000F0&(data))>>4)
#define  COLOR_DCC_D_DCC_Bist_1_get_ls_3(data)                                   ((0x00000002&(data))>>1)
#define  COLOR_DCC_D_DCC_Bist_1_get_ls_2(data)                                   (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_DCC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e400_31_10:22;
        RBus_UInt32  dcc_user_curve_en:1;
        RBus_UInt32  y_mapping_mode:1;
        RBus_UInt32  y_mapping_blending_wt:5;
        RBus_UInt32  main_table_segment:1;
        RBus_UInt32  main_table_sel:1;
        RBus_UInt32  dcc_main_en:1;
    };
}color_dcc_d_dcc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  luma_offset_main:8;
        RBus_UInt32  res2:16;
    };
}color_dcc_dcc_ctrl_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_limit_seg3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg0:6;
    };
}color_dcc_dcc_chroma_gain_limit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg7:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg5:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  chroma_gain_limit_seg4:6;
    };
}color_dcc_dcc_chroma_gain_limit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg0:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg0:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  saturation_byy_v_tab_select_main:1;
        RBus_UInt32  saturation_byy_u_tab_select_main:1;
        RBus_UInt32  chroma_enhance_below_tab_select_main:1;
        RBus_UInt32  chroma_enhance_above_tab_select_main:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_base:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  chroma_gain_lookup_mode:1;
        RBus_UInt32  chroma_gain_mode:1;
        RBus_UInt32  chroma_gain_en:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg4:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg2:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg1:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg8:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg7:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg6:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg5:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg12:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg11:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg10:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg9:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg16:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg15:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg14:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg13:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg20:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg19:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg18:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg17:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg24:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg23:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg22:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg21:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg28:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg27:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg26:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg25:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg32:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg31:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg30:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg29:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg36:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg35:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg34:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg33:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg40:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg39:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg38:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg37:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg44:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg43:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg42:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg41:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg48:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg47:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg46:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg45:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg52:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg51:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg50:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg49:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg56:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg55:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg54:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg53:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg60:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg59:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg58:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg57:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg64:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg63:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg62:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg61:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg4:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg2:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg1:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg8:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg7:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg6:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg5:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg12:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg11:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg10:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg9:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg16:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg15:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg14:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg13:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg20:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg19:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg18:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg17:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg24:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg23:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg22:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg21:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg28:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg27:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg26:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg25:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg32:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg31:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg30:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg29:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg36:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg35:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg34:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg33:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg40:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg39:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg38:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg37:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg44:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg43:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg42:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg41:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg48:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg47:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg46:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg45:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg52:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg51:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg50:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg49:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg56:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg55:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg54:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg53:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg60:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg59:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg58:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg57:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg64:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg63:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg62:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab1_seg61:7;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sram_tab_acc_index_cur:6;
        RBus_UInt32  sram_tab_acc_index:6;
        RBus_UInt32  sram_tab_rw_sel:2;
        RBus_UInt32  sram_tab_acc_sel:1;
        RBus_UInt32  sram_tab_acc_ready:1;
    };
}color_dcc_sram_tab_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sram_tab_base:10;
        RBus_UInt32  sram_tab_g0:8;
        RBus_UInt32  sram_tab_g1:8;
    };
}color_dcc_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sram_user_tab_acc_index_cur:6;
        RBus_UInt32  sram_user_tab_acc_index:6;
        RBus_UInt32  sram_user_tab_rw_sel:2;
        RBus_UInt32  sram_user_tab_acc_sel:1;
        RBus_UInt32  sram_user_tab_acc_ready:1;
    };
}color_dcc_sram_user_tab_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sram_user_tab_base:10;
        RBus_UInt32  sram_user_tab_g0:8;
        RBus_UInt32  sram_user_tab_g1:8;
    };
}color_dcc_sram_user_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}color_dcc_d_dcc_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  y_blending_debug_mode_en:1;
        RBus_UInt32  y_blending_debug_mode_sel:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  y_blending_mode:1;
        RBus_UInt32  ratio_lpf_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_reg0_en:1;
        RBus_UInt32  y_blending_reg1_en:1;
        RBus_UInt32  y_blending_reg2_en:1;
        RBus_UInt32  y_blending_reg3_en:1;
        RBus_UInt32  y_blending_en:1;
    };
}color_dcc_d_dcc_skin_tone_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_y_center:10;
        RBus_UInt32  y_blending_0_u_center:10;
        RBus_UInt32  y_blending_0_v_center:10;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  y_blending_0_y_range:4;
        RBus_UInt32  y_blending_0_u_range:4;
        RBus_UInt32  y_blending_0_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_y_center:10;
        RBus_UInt32  y_blending_1_u_center:10;
        RBus_UInt32  y_blending_1_v_center:10;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  y_blending_1_y_range:4;
        RBus_UInt32  y_blending_1_u_range:4;
        RBus_UInt32  y_blending_1_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_y_center:10;
        RBus_UInt32  y_blending_2_u_center:10;
        RBus_UInt32  y_blending_2_v_center:10;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  y_blending_2_y_range:4;
        RBus_UInt32  y_blending_2_u_range:4;
        RBus_UInt32  y_blending_2_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_y_center:10;
        RBus_UInt32  y_blending_3_u_center:10;
        RBus_UInt32  y_blending_3_v_center:10;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  y_blending_3_y_range:4;
        RBus_UInt32  y_blending_3_u_range:4;
        RBus_UInt32  y_blending_3_v_range:4;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_0_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_0_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_1_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_1_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_2_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_2_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_3_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  y_blending_3_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_0_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_0_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_1_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_1_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_2_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_2_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_3_ratio_3:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  c_blending_3_ratio_7:6;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DCC_Level:4;// 28 ~ 31
	RBus_UInt32  res1:3; // 25 ~ 27
	RBus_UInt32  H_LPF_Tap:2; // 23 ~ 24
	RBus_UInt32  Panel_compensation:1;//22
	RBus_UInt32  Boundary_Type:4; // 18:21
	RBus_UInt32  C_LPF_Tap:3; // 15~17
	RBus_UInt32  Curve_LPF_Enable:1; // 14
	RBus_UInt32  Hist_LPF_Enable:1; // 13
	RBus_UInt32  Output_LimitRange_Enable:1; // 12
	RBus_UInt32  Limit_range_Hist_Cut_Enable:1;// 11
	RBus_UInt32  Bin_boundary_Enable:1;// 10

	RBus_UInt32  Database_Enable:1; // 9
	RBus_UInt32  UserCurve_Enable:1; // 8
	RBus_UInt32  Expand_Enable:1; // 7
	RBus_UInt32  Scurve_Enable:1; // 6
	RBus_UInt32  Hist_Adjust_Enable:1;// 5
	RBus_UInt32  DCL_Enable:1; // 4

	RBus_UInt32  SkinTone:1; // 3
	RBus_UInt32  SceneChange:1; // 2
	RBus_UInt32  PureColor:1; // 1

	RBus_UInt32  Dummy_debug_enable:1;//0
    };
}color_dcc_d_dcc_fwused_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  VipInfo:1;
        RBus_UInt32  fw_1:7;
        RBus_UInt32  ThreeSEGXIndex1:8;
        RBus_UInt32  ThreeSEGXIndex0:8;
        RBus_UInt32  Res1:3;
        RBus_UInt32  HistogramScanningEnable:1;
        RBus_UInt32  CurveCoefInterpolationEnable:1;
        RBus_UInt32  Res0:1;
        RBus_UInt32  ThreeSegCurveEnable:1;
        RBus_UInt32  HighResCurveEnable:1;
    };
}color_dcc_d_dcc_fwused_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_2:24;
        RBus_UInt32  delay_time:8;
    };
}color_dcc_d_dcc_fwused_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ThreeSEGYNegOffset1:8;
	RBus_UInt32  ThreeSEGYNegOffset0:8;
        RBus_UInt32  ThreeSEGYPosOffset1:8;
        RBus_UInt32  ThreeSEGYPosOffset0:8;
    };
}color_dcc_d_dcc_fwused_3_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res4:8;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  res5:2;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
    };
}color_dcc_d_dcc_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  res4:8;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  res5:2;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
    };
}color_dcc_d_dcc_bist_1_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_DCC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_main_en:1;
        RBus_UInt32  main_table_sel:1;
        RBus_UInt32  main_table_segment:1;
        RBus_UInt32  y_mapping_blending_wt:5;
        RBus_UInt32  y_mapping_mode:1;
        RBus_UInt32  dcc_user_curve_en:1;
        RBus_UInt32  dummy1802e400_31_10:22;
    };
}color_dcc_d_dcc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  luma_offset_main:8;
        RBus_UInt32  res2:8;
    };
}color_dcc_dcc_ctrl_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg3:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_limit_en:1;
    };
}color_dcc_dcc_chroma_gain_limit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_limit_seg4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_gain_limit_seg5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  chroma_gain_limit_seg6:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_gain_limit_seg7:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_dcc_chroma_gain_limit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_en:1;
        RBus_UInt32  chroma_gain_mode:1;
        RBus_UInt32  chroma_gain_lookup_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_base:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_enhance_above_tab_select_main:1;
        RBus_UInt32  chroma_enhance_below_tab_select_main:1;
        RBus_UInt32  saturation_byy_u_tab_select_main:1;
        RBus_UInt32  saturation_byy_v_tab_select_main:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  chroma_gain_tab1_seg0:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  chroma_gain_tab0_seg0:7;
        RBus_UInt32  res5:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg4:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg5:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg6:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg7:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg8:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg9:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg10:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg11:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg12:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg13:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg14:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg15:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg16:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg17:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg18:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg19:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg20:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg21:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg22:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg23:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg24:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg25:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg26:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg27:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg28:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg29:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg30:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg31:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg32:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg33:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg34:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg35:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg36:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg37:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg38:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg39:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg40:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg41:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg42:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg43:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg44:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg45:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg46:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg47:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg48:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg49:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg50:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg51:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg52:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg53:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg54:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg55:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg56:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg57:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg58:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg59:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg60:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab0_seg61:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab0_seg62:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab0_seg63:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab0_seg64:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab0_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg4:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg5:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg6:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg7:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg8:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg9:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg10:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg11:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg12:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg13:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg14:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg15:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg16:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg17:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg18:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg19:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg20:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg21:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg22:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg23:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg24:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg25:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg26:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg27:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg28:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg29:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg30:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg31:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg32:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg33:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg34:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg35:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg36:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg37:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg38:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg39:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg40:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg41:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg42:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg43:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg44:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg45:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg46:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg47:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg48:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg49:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg50:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg51:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg52:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg53:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg54:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg55:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg56:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg57:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg58:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg59:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg60:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_tab1_seg61:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_gain_tab1_seg62:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_gain_tab1_seg63:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  chroma_gain_tab1_seg64:7;
        RBus_UInt32  res4:1;
    };
}color_dcc_dcc_ctrl_chroma_gain_tab1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_tab_acc_ready:1;
        RBus_UInt32  sram_tab_acc_sel:1;
        RBus_UInt32  sram_tab_rw_sel:2;
        RBus_UInt32  sram_tab_acc_index:6;
        RBus_UInt32  sram_tab_acc_index_cur:6;
        RBus_UInt32  res1:16;
    };
}color_dcc_sram_tab_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_tab_g1:8;
        RBus_UInt32  sram_tab_g0:8;
        RBus_UInt32  sram_tab_base:10;
        RBus_UInt32  res1:6;
    };
}color_dcc_sram_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_user_tab_acc_ready:1;
        RBus_UInt32  sram_user_tab_acc_sel:1;
        RBus_UInt32  sram_user_tab_rw_sel:2;
        RBus_UInt32  sram_user_tab_acc_index:6;
        RBus_UInt32  sram_user_tab_acc_index_cur:6;
        RBus_UInt32  res1:16;
    };
}color_dcc_sram_user_tab_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sram_user_tab_g1:8;
        RBus_UInt32  sram_user_tab_g0:8;
        RBus_UInt32  sram_user_tab_base:10;
        RBus_UInt32  res1:6;
    };
}color_dcc_sram_user_tab_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}color_dcc_d_dcc_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_en:1;
        RBus_UInt32  y_blending_reg3_en:1;
        RBus_UInt32  y_blending_reg2_en:1;
        RBus_UInt32  y_blending_reg1_en:1;
        RBus_UInt32  y_blending_reg0_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ratio_lpf_en:1;
        RBus_UInt32  y_blending_mode:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  y_blending_debug_mode_sel:2;
        RBus_UInt32  y_blending_debug_mode_en:1;
        RBus_UInt32  res3:13;
    };
}color_dcc_d_dcc_skin_tone_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_v_center:10;
        RBus_UInt32  y_blending_0_u_center:10;
        RBus_UInt32  y_blending_0_y_center:10;
        RBus_UInt32  res1:2;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_v_range:4;
        RBus_UInt32  y_blending_0_u_range:4;
        RBus_UInt32  y_blending_0_y_range:4;
        RBus_UInt32  res1:20;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_v_center:10;
        RBus_UInt32  y_blending_1_u_center:10;
        RBus_UInt32  y_blending_1_y_center:10;
        RBus_UInt32  res1:2;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_v_range:4;
        RBus_UInt32  y_blending_1_u_range:4;
        RBus_UInt32  y_blending_1_y_range:4;
        RBus_UInt32  res1:20;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_v_center:10;
        RBus_UInt32  y_blending_2_u_center:10;
        RBus_UInt32  y_blending_2_y_center:10;
        RBus_UInt32  res1:2;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_v_range:4;
        RBus_UInt32  y_blending_2_u_range:4;
        RBus_UInt32  y_blending_2_y_range:4;
        RBus_UInt32  res1:20;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_v_center:10;
        RBus_UInt32  y_blending_3_u_center:10;
        RBus_UInt32  y_blending_3_y_center:10;
        RBus_UInt32  res1:2;
    };
}color_dcc_d_dcc_skin_tone_yuv_center_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_v_range:4;
        RBus_UInt32  y_blending_3_u_range:4;
        RBus_UInt32  y_blending_3_y_range:4;
        RBus_UInt32  res1:20;
    };
}color_dcc_d_dcc_skin_tone_yuv_range_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_0_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_0_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_0_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_1_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_1_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_1_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_2_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_2_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_2_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_blending_3_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  y_blending_3_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_blending_3_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_0_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_0_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_0_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_0_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_0_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_1_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_1_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_1_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_1_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_1_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_2_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_2_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_2_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_2_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_2_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_3_ratio_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_0:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_blending_3_ratio_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c_blending_3_ratio_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  c_blending_3_ratio_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  c_blending_3_ratio_4:6;
        RBus_UInt32  res4:2;
    };
}color_dcc_d_dcc_skin_tone_segment_c3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Dummy_debug_enable:1;//0
	RBus_UInt32  PureColor:1; // 1
	RBus_UInt32  SceneChange:1; // 2
	RBus_UInt32  SkinTone:1; // 3
	RBus_UInt32  DCL_Enable:1; // 4
	RBus_UInt32  Hist_Adjust_Enable:1;// 5
	RBus_UInt32  Scurve_Enable:1; // 6
	RBus_UInt32  Expand_Enable:1; // 7
	RBus_UInt32  UserCurve_Enable:1; // 8
	RBus_UInt32  Database_Enable:1; // 9
	RBus_UInt32  Bin_boundary_Enable:1;// 10
	RBus_UInt32  Limit_range_Hist_Cut_Enable:1;// 11
	RBus_UInt32  Output_LimitRange_Enable:1; // 12
	RBus_UInt32  Hist_LPF_Enable:1; // 13
	RBus_UInt32  Curve_LPF_Enable:1; // 14
	RBus_UInt32  C_LPF_Tap:3; // 15~17
	RBus_UInt32  Boundary_Type:4; // 18:21
	RBus_UInt32  Panel_compensation:1;//22
	RBus_UInt32  H_LPF_Tap:2; // 23 ~ 24
	RBus_UInt32  res1:3; // 25 ~ 27
	RBus_UInt32  DCC_Level:4;// 28 ~ 31
    };
}color_dcc_d_dcc_fwused_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  HighResCurveEnable:1;
        RBus_UInt32  ThreeSegCurveEnable:1;
        RBus_UInt32  Res0:1;
        RBus_UInt32  CurveCoefInterpolationEnable:1;
        RBus_UInt32  HistogramScanningEnable:1;
        RBus_UInt32  Res1:3;
        RBus_UInt32  ThreeSEGXIndex0:8;
        RBus_UInt32  ThreeSEGXIndex1:8;
        RBus_UInt32  fw_1:7;
        RBus_UInt32  VipInfo:1;
    };
}color_dcc_d_dcc_fwused_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_time:8;
        RBus_UInt32  fw_2:24;
    };
}color_dcc_d_dcc_fwused_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ThreeSEGYPosOffset0:8;
        RBus_UInt32  ThreeSEGYPosOffset1:8;
	RBus_UInt32  ThreeSEGYNegOffset0:8;
        RBus_UInt32  ThreeSEGYNegOffset1:8;
    };
}color_dcc_d_dcc_fwused_3_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  res5:2;
    };
}color_dcc_d_dcc_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  res5:2;
    };
}color_dcc_d_dcc_bist_1_RBUS;




#endif


#endif
