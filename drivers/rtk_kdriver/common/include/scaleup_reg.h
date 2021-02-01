/**
* @file Mac5-DesignSpec-D-Domain_UZU
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SCALEUP_REG_H_
#define _RBUS_SCALEUP_REG_H_

#include "rbus_types.h"



//  SCALEUP Register Address
#define  SCALEUP_D_UZU_Globle_Ctrl                                               0x18029000
#define  SCALEUP_D_UZU_Globle_Ctrl_reg_addr                                      "0xB8029000"
#define  SCALEUP_D_UZU_Globle_Ctrl_reg                                           0xB8029000
#define  SCALEUP_D_UZU_Globle_Ctrl_inst_addr                                     "0x0000"
#define  set_SCALEUP_D_UZU_Globle_Ctrl_reg(data)                                 (*((volatile unsigned int*)SCALEUP_D_UZU_Globle_Ctrl_reg)=data)
#define  get_SCALEUP_D_UZU_Globle_Ctrl_reg                                       (*((volatile unsigned int*)SCALEUP_D_UZU_Globle_Ctrl_reg))
#define  SCALEUP_D_UZU_Globle_Ctrl_dummy_31_16_shift                             (16)
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_no_pwrsave_shift                   (15)
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_force_shift                        (14)
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_en_shift                             (13)
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_sel_shift                            (12)
#define  SCALEUP_D_UZU_Globle_Ctrl_in_black_en_shift                             (11)
#define  SCALEUP_D_UZU_Globle_Ctrl_in_even_black_shift                           (10)
#define  SCALEUP_D_UZU_Globle_Ctrl_out_black_en_shift                            (9)
#define  SCALEUP_D_UZU_Globle_Ctrl_out_even_black_shift                          (8)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sync_shift                             (7)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_mode_shift                             (4)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_lflag_en_shift                         (3)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_field_shift                            (2)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sel_shift                              (0)
#define  SCALEUP_D_UZU_Globle_Ctrl_dummy_31_16_mask                              (0xFFFF0000)
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_no_pwrsave_mask                    (0x00008000)
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_force_mask                         (0x00004000)
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_en_mask                              (0x00002000)
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_sel_mask                             (0x00001000)
#define  SCALEUP_D_UZU_Globle_Ctrl_in_black_en_mask                              (0x00000800)
#define  SCALEUP_D_UZU_Globle_Ctrl_in_even_black_mask                            (0x00000400)
#define  SCALEUP_D_UZU_Globle_Ctrl_out_black_en_mask                             (0x00000200)
#define  SCALEUP_D_UZU_Globle_Ctrl_out_even_black_mask                           (0x00000100)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sync_mask                              (0x00000080)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_mode_mask                              (0x00000070)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_lflag_en_mask                          (0x00000008)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_field_mask                             (0x00000004)
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sel_mask                               (0x00000003)
#define  SCALEUP_D_UZU_Globle_Ctrl_dummy_31_16(data)                             (0xFFFF0000&((data)<<16))
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_no_pwrsave(data)                   (0x00008000&((data)<<15))
#define  SCALEUP_D_UZU_Globle_Ctrl_uzu_bypass_force(data)                        (0x00004000&((data)<<14))
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_en(data)                             (0x00002000&((data)<<13))
#define  SCALEUP_D_UZU_Globle_Ctrl_lr_black_sel(data)                            (0x00001000&((data)<<12))
#define  SCALEUP_D_UZU_Globle_Ctrl_in_black_en(data)                             (0x00000800&((data)<<11))
#define  SCALEUP_D_UZU_Globle_Ctrl_in_even_black(data)                           (0x00000400&((data)<<10))
#define  SCALEUP_D_UZU_Globle_Ctrl_out_black_en(data)                            (0x00000200&((data)<<9))
#define  SCALEUP_D_UZU_Globle_Ctrl_out_even_black(data)                          (0x00000100&((data)<<8))
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sync(data)                             (0x00000080&((data)<<7))
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_mode(data)                             (0x00000070&((data)<<4))
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_lflag_en(data)                         (0x00000008&((data)<<3))
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_field(data)                            (0x00000004&((data)<<2))
#define  SCALEUP_D_UZU_Globle_Ctrl_patgen_sel(data)                              (0x00000003&(data))
#define  SCALEUP_D_UZU_Globle_Ctrl_get_dummy_31_16(data)                         ((0xFFFF0000&(data))>>16)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_uzu_bypass_no_pwrsave(data)               ((0x00008000&(data))>>15)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_uzu_bypass_force(data)                    ((0x00004000&(data))>>14)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_lr_black_en(data)                         ((0x00002000&(data))>>13)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_lr_black_sel(data)                        ((0x00001000&(data))>>12)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_in_black_en(data)                         ((0x00000800&(data))>>11)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_in_even_black(data)                       ((0x00000400&(data))>>10)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_out_black_en(data)                        ((0x00000200&(data))>>9)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_out_even_black(data)                      ((0x00000100&(data))>>8)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_patgen_sync(data)                         ((0x00000080&(data))>>7)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_patgen_mode(data)                         ((0x00000070&(data))>>4)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_patgen_lflag_en(data)                     ((0x00000008&(data))>>3)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_patgen_field(data)                        ((0x00000004&(data))>>2)
#define  SCALEUP_D_UZU_Globle_Ctrl_get_patgen_sel(data)                          (0x00000003&(data))

#define  SCALEUP_DM_UZU_Ctrl                                                     0x18029004
#define  SCALEUP_DM_UZU_Ctrl_reg_addr                                            "0xB8029004"
#define  SCALEUP_DM_UZU_Ctrl_reg                                                 0xB8029004
#define  SCALEUP_DM_UZU_Ctrl_inst_addr                                           "0x0001"
#define  set_SCALEUP_DM_UZU_Ctrl_reg(data)                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_Ctrl_reg)=data)
#define  get_SCALEUP_DM_UZU_Ctrl_reg                                             (*((volatile unsigned int*)SCALEUP_DM_UZU_Ctrl_reg))
#define  SCALEUP_DM_UZU_Ctrl_hor_mode_sel_shift                                  (29)
#define  SCALEUP_DM_UZU_Ctrl_ver_pr_mode_shift                                   (26)
#define  SCALEUP_DM_UZU_Ctrl_wd_main_buf_udf_en_shift                            (25)
#define  SCALEUP_DM_UZU_Ctrl_irq_main_buf_udf_en_shift                           (24)
#define  SCALEUP_DM_UZU_Ctrl_bypassfornr_shift                                   (23)
#define  SCALEUP_DM_UZU_Ctrl_v_y_consttab_sel_shift                              (21)
#define  SCALEUP_DM_UZU_Ctrl_v_c_consttab_sel_shift                              (19)
#define  SCALEUP_DM_UZU_Ctrl_h_y_consttab_sel_shift                              (17)
#define  SCALEUP_DM_UZU_Ctrl_h_c_consttab_sel_shift                              (15)
#define  SCALEUP_DM_UZU_Ctrl_hor8_table_sel_shift                                (13)
#define  SCALEUP_DM_UZU_Ctrl_d_3d_sel_en_shift                                   (12)
#define  SCALEUP_DM_UZU_Ctrl_video_comp_en_shift                                 (11)
#define  SCALEUP_DM_UZU_Ctrl_odd_inv_shift                                       (10)
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_conv_shift                                   (9)
#define  SCALEUP_DM_UZU_Ctrl_conv_type_shift                                     (8)
#define  SCALEUP_DM_UZU_Ctrl_v_y_table_sel_shift                                 (7)
#define  SCALEUP_DM_UZU_Ctrl_v_c_table_sel_shift                                 (6)
#define  SCALEUP_DM_UZU_Ctrl_h_y_table_sel_shift                                 (5)
#define  SCALEUP_DM_UZU_Ctrl_h_c_table_sel_shift                                 (4)
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_dup_shift                                    (3)
#define  SCALEUP_DM_UZU_Ctrl_v_zoom_en_shift                                     (1)
#define  SCALEUP_DM_UZU_Ctrl_h_zoom_en_shift                                     (0)
#define  SCALEUP_DM_UZU_Ctrl_hor_mode_sel_mask                                   (0xE0000000)
#define  SCALEUP_DM_UZU_Ctrl_ver_pr_mode_mask                                    (0x0C000000)
#define  SCALEUP_DM_UZU_Ctrl_wd_main_buf_udf_en_mask                             (0x02000000)
#define  SCALEUP_DM_UZU_Ctrl_irq_main_buf_udf_en_mask                            (0x01000000)
#define  SCALEUP_DM_UZU_Ctrl_bypassfornr_mask                                    (0x00800000)
#define  SCALEUP_DM_UZU_Ctrl_v_y_consttab_sel_mask                               (0x00600000)
#define  SCALEUP_DM_UZU_Ctrl_v_c_consttab_sel_mask                               (0x00180000)
#define  SCALEUP_DM_UZU_Ctrl_h_y_consttab_sel_mask                               (0x00060000)
#define  SCALEUP_DM_UZU_Ctrl_h_c_consttab_sel_mask                               (0x00018000)
#define  SCALEUP_DM_UZU_Ctrl_hor8_table_sel_mask                                 (0x00006000)
#define  SCALEUP_DM_UZU_Ctrl_d_3d_sel_en_mask                                    (0x00001000)
#define  SCALEUP_DM_UZU_Ctrl_video_comp_en_mask                                  (0x00000800)
#define  SCALEUP_DM_UZU_Ctrl_odd_inv_mask                                        (0x00000400)
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_conv_mask                                    (0x00000200)
#define  SCALEUP_DM_UZU_Ctrl_conv_type_mask                                      (0x00000100)
#define  SCALEUP_DM_UZU_Ctrl_v_y_table_sel_mask                                  (0x00000080)
#define  SCALEUP_DM_UZU_Ctrl_v_c_table_sel_mask                                  (0x00000040)
#define  SCALEUP_DM_UZU_Ctrl_h_y_table_sel_mask                                  (0x00000020)
#define  SCALEUP_DM_UZU_Ctrl_h_c_table_sel_mask                                  (0x00000010)
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_dup_mask                                     (0x00000008)
#define  SCALEUP_DM_UZU_Ctrl_v_zoom_en_mask                                      (0x00000002)
#define  SCALEUP_DM_UZU_Ctrl_h_zoom_en_mask                                      (0x00000001)
#define  SCALEUP_DM_UZU_Ctrl_hor_mode_sel(data)                                  (0xE0000000&((data)<<29))
#define  SCALEUP_DM_UZU_Ctrl_ver_pr_mode(data)                                   (0x0C000000&((data)<<26))
#define  SCALEUP_DM_UZU_Ctrl_wd_main_buf_udf_en(data)                            (0x02000000&((data)<<25))
#define  SCALEUP_DM_UZU_Ctrl_irq_main_buf_udf_en(data)                           (0x01000000&((data)<<24))
#define  SCALEUP_DM_UZU_Ctrl_bypassfornr(data)                                   (0x00800000&((data)<<23))
#define  SCALEUP_DM_UZU_Ctrl_v_y_consttab_sel(data)                              (0x00600000&((data)<<21))
#define  SCALEUP_DM_UZU_Ctrl_v_c_consttab_sel(data)                              (0x00180000&((data)<<19))
#define  SCALEUP_DM_UZU_Ctrl_h_y_consttab_sel(data)                              (0x00060000&((data)<<17))
#define  SCALEUP_DM_UZU_Ctrl_h_c_consttab_sel(data)                              (0x00018000&((data)<<15))
#define  SCALEUP_DM_UZU_Ctrl_hor8_table_sel(data)                                (0x00006000&((data)<<13))
#define  SCALEUP_DM_UZU_Ctrl_d_3d_sel_en(data)                                   (0x00001000&((data)<<12))
#define  SCALEUP_DM_UZU_Ctrl_video_comp_en(data)                                 (0x00000800&((data)<<11))
#define  SCALEUP_DM_UZU_Ctrl_odd_inv(data)                                       (0x00000400&((data)<<10))
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_conv(data)                                   (0x00000200&((data)<<9))
#define  SCALEUP_DM_UZU_Ctrl_conv_type(data)                                     (0x00000100&((data)<<8))
#define  SCALEUP_DM_UZU_Ctrl_v_y_table_sel(data)                                 (0x00000080&((data)<<7))
#define  SCALEUP_DM_UZU_Ctrl_v_c_table_sel(data)                                 (0x00000040&((data)<<6))
#define  SCALEUP_DM_UZU_Ctrl_h_y_table_sel(data)                                 (0x00000020&((data)<<5))
#define  SCALEUP_DM_UZU_Ctrl_h_c_table_sel(data)                                 (0x00000010&((data)<<4))
#define  SCALEUP_DM_UZU_Ctrl_in_fmt_dup(data)                                    (0x00000008&((data)<<3))
#define  SCALEUP_DM_UZU_Ctrl_v_zoom_en(data)                                     (0x00000002&((data)<<1))
#define  SCALEUP_DM_UZU_Ctrl_h_zoom_en(data)                                     (0x00000001&(data))
#define  SCALEUP_DM_UZU_Ctrl_get_hor_mode_sel(data)                              ((0xE0000000&(data))>>29)
#define  SCALEUP_DM_UZU_Ctrl_get_ver_pr_mode(data)                               ((0x0C000000&(data))>>26)
#define  SCALEUP_DM_UZU_Ctrl_get_wd_main_buf_udf_en(data)                        ((0x02000000&(data))>>25)
#define  SCALEUP_DM_UZU_Ctrl_get_irq_main_buf_udf_en(data)                       ((0x01000000&(data))>>24)
#define  SCALEUP_DM_UZU_Ctrl_get_bypassfornr(data)                               ((0x00800000&(data))>>23)
#define  SCALEUP_DM_UZU_Ctrl_get_v_y_consttab_sel(data)                          ((0x00600000&(data))>>21)
#define  SCALEUP_DM_UZU_Ctrl_get_v_c_consttab_sel(data)                          ((0x00180000&(data))>>19)
#define  SCALEUP_DM_UZU_Ctrl_get_h_y_consttab_sel(data)                          ((0x00060000&(data))>>17)
#define  SCALEUP_DM_UZU_Ctrl_get_h_c_consttab_sel(data)                          ((0x00018000&(data))>>15)
#define  SCALEUP_DM_UZU_Ctrl_get_hor8_table_sel(data)                            ((0x00006000&(data))>>13)
#define  SCALEUP_DM_UZU_Ctrl_get_d_3d_sel_en(data)                               ((0x00001000&(data))>>12)
#define  SCALEUP_DM_UZU_Ctrl_get_video_comp_en(data)                             ((0x00000800&(data))>>11)
#define  SCALEUP_DM_UZU_Ctrl_get_odd_inv(data)                                   ((0x00000400&(data))>>10)
#define  SCALEUP_DM_UZU_Ctrl_get_in_fmt_conv(data)                               ((0x00000200&(data))>>9)
#define  SCALEUP_DM_UZU_Ctrl_get_conv_type(data)                                 ((0x00000100&(data))>>8)
#define  SCALEUP_DM_UZU_Ctrl_get_v_y_table_sel(data)                             ((0x00000080&(data))>>7)
#define  SCALEUP_DM_UZU_Ctrl_get_v_c_table_sel(data)                             ((0x00000040&(data))>>6)
#define  SCALEUP_DM_UZU_Ctrl_get_h_y_table_sel(data)                             ((0x00000020&(data))>>5)
#define  SCALEUP_DM_UZU_Ctrl_get_h_c_table_sel(data)                             ((0x00000010&(data))>>4)
#define  SCALEUP_DM_UZU_Ctrl_get_in_fmt_dup(data)                                ((0x00000008&(data))>>3)
#define  SCALEUP_DM_UZU_Ctrl_get_v_zoom_en(data)                                 ((0x00000002&(data))>>1)
#define  SCALEUP_DM_UZU_Ctrl_get_h_zoom_en(data)                                 (0x00000001&(data))

#define  SCALEUP_DM_UZU_Scale_Hor_Factor                                         0x18029008
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_reg_addr                                "0xB8029008"
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_reg                                     0xB8029008
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_inst_addr                               "0x0002"
#define  set_SCALEUP_DM_UZU_Scale_Hor_Factor_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Scale_Hor_Factor_reg)=data)
#define  get_SCALEUP_DM_UZU_Scale_Hor_Factor_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Scale_Hor_Factor_reg))
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_hor_factor_shift                        (0)
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_hor_factor_mask                         (0x000FFFFF)
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_hor_factor(data)                        (0x000FFFFF&(data))
#define  SCALEUP_DM_UZU_Scale_Hor_Factor_get_hor_factor(data)                    (0x000FFFFF&(data))

#define  SCALEUP_DM_UZU_Scale_Ver_Factor                                         0x1802900C
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_reg_addr                                "0xB802900C"
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_reg                                     0xB802900C
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_inst_addr                               "0x0003"
#define  set_SCALEUP_DM_UZU_Scale_Ver_Factor_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Scale_Ver_Factor_reg)=data)
#define  get_SCALEUP_DM_UZU_Scale_Ver_Factor_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Scale_Ver_Factor_reg))
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_ver_factor_shift                        (0)
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_ver_factor_mask                         (0x000FFFFF)
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_ver_factor(data)                        (0x000FFFFF&(data))
#define  SCALEUP_DM_UZU_Scale_Ver_Factor_get_ver_factor(data)                    (0x000FFFFF&(data))

#define  SCALEUP_DM_UZU_Hor_Delta1                                               0x18029010
#define  SCALEUP_DM_UZU_Hor_Delta1_reg_addr                                      "0xB8029010"
#define  SCALEUP_DM_UZU_Hor_Delta1_reg                                           0xB8029010
#define  SCALEUP_DM_UZU_Hor_Delta1_inst_addr                                     "0x0004"
#define  set_SCALEUP_DM_UZU_Hor_Delta1_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Delta1_reg)=data)
#define  get_SCALEUP_DM_UZU_Hor_Delta1_reg                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Delta1_reg))
#define  SCALEUP_DM_UZU_Hor_Delta1_hor_delta1_shift                              (0)
#define  SCALEUP_DM_UZU_Hor_Delta1_hor_delta1_mask                               (0x00001FFF)
#define  SCALEUP_DM_UZU_Hor_Delta1_hor_delta1(data)                              (0x00001FFF&(data))
#define  SCALEUP_DM_UZU_Hor_Delta1_get_hor_delta1(data)                          (0x00001FFF&(data))

#define  SCALEUP_DM_UZU_Hor_Delta2                                               0x18029014
#define  SCALEUP_DM_UZU_Hor_Delta2_reg_addr                                      "0xB8029014"
#define  SCALEUP_DM_UZU_Hor_Delta2_reg                                           0xB8029014
#define  SCALEUP_DM_UZU_Hor_Delta2_inst_addr                                     "0x0005"
#define  set_SCALEUP_DM_UZU_Hor_Delta2_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Delta2_reg)=data)
#define  get_SCALEUP_DM_UZU_Hor_Delta2_reg                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Delta2_reg))
#define  SCALEUP_DM_UZU_Hor_Delta2_hor_delta2_shift                              (0)
#define  SCALEUP_DM_UZU_Hor_Delta2_hor_delta2_mask                               (0x00001FFF)
#define  SCALEUP_DM_UZU_Hor_Delta2_hor_delta2(data)                              (0x00001FFF&(data))
#define  SCALEUP_DM_UZU_Hor_Delta2_get_hor_delta2(data)                          (0x00001FFF&(data))

#define  SCALEUP_DM_UZU_Hor_Segment1                                             0x18029018
#define  SCALEUP_DM_UZU_Hor_Segment1_reg_addr                                    "0xB8029018"
#define  SCALEUP_DM_UZU_Hor_Segment1_reg                                         0xB8029018
#define  SCALEUP_DM_UZU_Hor_Segment1_inst_addr                                   "0x0006"
#define  set_SCALEUP_DM_UZU_Hor_Segment1_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment1_reg)=data)
#define  get_SCALEUP_DM_UZU_Hor_Segment1_reg                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment1_reg))
#define  SCALEUP_DM_UZU_Hor_Segment1_hor_segment1_shift                          (0)
#define  SCALEUP_DM_UZU_Hor_Segment1_hor_segment1_mask                           (0x000007FF)
#define  SCALEUP_DM_UZU_Hor_Segment1_hor_segment1(data)                          (0x000007FF&(data))
#define  SCALEUP_DM_UZU_Hor_Segment1_get_hor_segment1(data)                      (0x000007FF&(data))

#define  SCALEUP_DM_UZU_Hor_Segment2                                             0x1802901C
#define  SCALEUP_DM_UZU_Hor_Segment2_reg_addr                                    "0xB802901C"
#define  SCALEUP_DM_UZU_Hor_Segment2_reg                                         0xB802901C
#define  SCALEUP_DM_UZU_Hor_Segment2_inst_addr                                   "0x0007"
#define  set_SCALEUP_DM_UZU_Hor_Segment2_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment2_reg)=data)
#define  get_SCALEUP_DM_UZU_Hor_Segment2_reg                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment2_reg))
#define  SCALEUP_DM_UZU_Hor_Segment2_hor_segment2_shift                          (0)
#define  SCALEUP_DM_UZU_Hor_Segment2_hor_segment2_mask                           (0x000007FF)
#define  SCALEUP_DM_UZU_Hor_Segment2_hor_segment2(data)                          (0x000007FF&(data))
#define  SCALEUP_DM_UZU_Hor_Segment2_get_hor_segment2(data)                      (0x000007FF&(data))

#define  SCALEUP_DM_UZU_Hor_Segment3                                             0x18029020
#define  SCALEUP_DM_UZU_Hor_Segment3_reg_addr                                    "0xB8029020"
#define  SCALEUP_DM_UZU_Hor_Segment3_reg                                         0xB8029020
#define  SCALEUP_DM_UZU_Hor_Segment3_inst_addr                                   "0x0008"
#define  set_SCALEUP_DM_UZU_Hor_Segment3_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment3_reg)=data)
#define  get_SCALEUP_DM_UZU_Hor_Segment3_reg                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Hor_Segment3_reg))
#define  SCALEUP_DM_UZU_Hor_Segment3_hor_segment3_shift                          (0)
#define  SCALEUP_DM_UZU_Hor_Segment3_hor_segment3_mask                           (0x00000FFF)
#define  SCALEUP_DM_UZU_Hor_Segment3_hor_segment3(data)                          (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Hor_Segment3_get_hor_segment3(data)                      (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Initial_Value                                            0x18029024
#define  SCALEUP_DM_UZU_Initial_Value_reg_addr                                   "0xB8029024"
#define  SCALEUP_DM_UZU_Initial_Value_reg                                        0xB8029024
#define  SCALEUP_DM_UZU_Initial_Value_inst_addr                                  "0x0009"
#define  set_SCALEUP_DM_UZU_Initial_Value_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_UZU_Initial_Value_reg)=data)
#define  get_SCALEUP_DM_UZU_Initial_Value_reg                                    (*((volatile unsigned int*)SCALEUP_DM_UZU_Initial_Value_reg))
#define  SCALEUP_DM_UZU_Initial_Value_hflip_en_shift                             (28)
#define  SCALEUP_DM_UZU_Initial_Value_hor_ini_shift                              (8)
#define  SCALEUP_DM_UZU_Initial_Value_ver_ini_shift                              (0)
#define  SCALEUP_DM_UZU_Initial_Value_hflip_en_mask                              (0x10000000)
#define  SCALEUP_DM_UZU_Initial_Value_hor_ini_mask                               (0x0000FF00)
#define  SCALEUP_DM_UZU_Initial_Value_ver_ini_mask                               (0x000000FF)
#define  SCALEUP_DM_UZU_Initial_Value_hflip_en(data)                             (0x10000000&((data)<<28))
#define  SCALEUP_DM_UZU_Initial_Value_hor_ini(data)                              (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZU_Initial_Value_ver_ini(data)                              (0x000000FF&(data))
#define  SCALEUP_DM_UZU_Initial_Value_get_hflip_en(data)                         ((0x10000000&(data))>>28)
#define  SCALEUP_DM_UZU_Initial_Value_get_hor_ini(data)                          ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZU_Initial_Value_get_ver_ini(data)                          (0x000000FF&(data))

#define  SCALEUP_DM_UZU_Input_Size                                               0x18029028
#define  SCALEUP_DM_UZU_Input_Size_reg_addr                                      "0xB8029028"
#define  SCALEUP_DM_UZU_Input_Size_reg                                           0xB8029028
#define  SCALEUP_DM_UZU_Input_Size_inst_addr                                     "0x000A"
#define  set_SCALEUP_DM_UZU_Input_Size_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Input_Size_reg)=data)
#define  get_SCALEUP_DM_UZU_Input_Size_reg                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_Input_Size_reg))
#define  SCALEUP_DM_UZU_Input_Size_hor_input_size_shift                          (16)
#define  SCALEUP_DM_UZU_Input_Size_ver_input_size_shift                          (0)
#define  SCALEUP_DM_UZU_Input_Size_hor_input_size_mask                           (0x0FFF0000)
#define  SCALEUP_DM_UZU_Input_Size_ver_input_size_mask                           (0x00000FFF)
#define  SCALEUP_DM_UZU_Input_Size_hor_input_size(data)                          (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Input_Size_ver_input_size(data)                          (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Input_Size_get_hor_input_size(data)                      ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Input_Size_get_ver_input_size(data)                      (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_8tap_dering                                              0x1802902C
#define  SCALEUP_DM_UZU_8tap_dering_reg_addr                                     "0xB802902C"
#define  SCALEUP_DM_UZU_8tap_dering_reg                                          0xB802902C
#define  SCALEUP_DM_UZU_8tap_dering_inst_addr                                    "0x000B"
#define  set_SCALEUP_DM_UZU_8tap_dering_reg(data)                                (*((volatile unsigned int*)SCALEUP_DM_UZU_8tap_dering_reg)=data)
#define  get_SCALEUP_DM_UZU_8tap_dering_reg                                      (*((volatile unsigned int*)SCALEUP_DM_UZU_8tap_dering_reg))
#define  SCALEUP_DM_UZU_8tap_dering_level_flatness_coeff_shift                   (29)
#define  SCALEUP_DM_UZU_8tap_dering_dering_dbg_mode_shift                        (26)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_range_shift                       (24)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_lowbound_shift                    (16)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_mask_sel_shift                     (15)
#define  SCALEUP_DM_UZU_8tap_dering_level_maxmin_coeff_shift                     (12)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_en_shift                          (11)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_en_shift                           (10)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_range_shift                        (8)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_lowbound_shift                     (0)
#define  SCALEUP_DM_UZU_8tap_dering_level_flatness_coeff_mask                    (0xE0000000)
#define  SCALEUP_DM_UZU_8tap_dering_dering_dbg_mode_mask                         (0x1C000000)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_range_mask                        (0x03000000)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_lowbound_mask                     (0x00FF0000)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_mask_sel_mask                      (0x00008000)
#define  SCALEUP_DM_UZU_8tap_dering_level_maxmin_coeff_mask                      (0x00007000)
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_en_mask                           (0x00000800)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_en_mask                            (0x00000400)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_range_mask                         (0x00000300)
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_lowbound_mask                      (0x000000FF)
#define  SCALEUP_DM_UZU_8tap_dering_level_flatness_coeff(data)                   (0xE0000000&((data)<<29))
#define  SCALEUP_DM_UZU_8tap_dering_dering_dbg_mode(data)                        (0x1C000000&((data)<<26))
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_range(data)                       (0x03000000&((data)<<24))
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_lowbound(data)                    (0x00FF0000&((data)<<16))
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_mask_sel(data)                     (0x00008000&((data)<<15))
#define  SCALEUP_DM_UZU_8tap_dering_level_maxmin_coeff(data)                     (0x00007000&((data)<<12))
#define  SCALEUP_DM_UZU_8tap_dering_h4h8_blend_en(data)                          (0x00000800&((data)<<11))
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_en(data)                           (0x00000400&((data)<<10))
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_range(data)                        (0x00000300&((data)<<8))
#define  SCALEUP_DM_UZU_8tap_dering_lpf_blend_lowbound(data)                     (0x000000FF&(data))
#define  SCALEUP_DM_UZU_8tap_dering_get_level_flatness_coeff(data)               ((0xE0000000&(data))>>29)
#define  SCALEUP_DM_UZU_8tap_dering_get_dering_dbg_mode(data)                    ((0x1C000000&(data))>>26)
#define  SCALEUP_DM_UZU_8tap_dering_get_h4h8_blend_range(data)                   ((0x03000000&(data))>>24)
#define  SCALEUP_DM_UZU_8tap_dering_get_h4h8_blend_lowbound(data)                ((0x00FF0000&(data))>>16)
#define  SCALEUP_DM_UZU_8tap_dering_get_lpf_blend_mask_sel(data)                 ((0x00008000&(data))>>15)
#define  SCALEUP_DM_UZU_8tap_dering_get_level_maxmin_coeff(data)                 ((0x00007000&(data))>>12)
#define  SCALEUP_DM_UZU_8tap_dering_get_h4h8_blend_en(data)                      ((0x00000800&(data))>>11)
#define  SCALEUP_DM_UZU_8tap_dering_get_lpf_blend_en(data)                       ((0x00000400&(data))>>10)
#define  SCALEUP_DM_UZU_8tap_dering_get_lpf_blend_range(data)                    ((0x00000300&(data))>>8)
#define  SCALEUP_DM_UZU_8tap_dering_get_lpf_blend_lowbound(data)                 (0x000000FF&(data))

#define  SCALEUP_DM_UZU_8tap_dering_cross                                        0x18029034
#define  SCALEUP_DM_UZU_8tap_dering_cross_reg_addr                               "0xB8029034"
#define  SCALEUP_DM_UZU_8tap_dering_cross_reg                                    0xB8029034
#define  SCALEUP_DM_UZU_8tap_dering_cross_inst_addr                              "0x000C"
#define  set_SCALEUP_DM_UZU_8tap_dering_cross_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_8tap_dering_cross_reg)=data)
#define  get_SCALEUP_DM_UZU_8tap_dering_cross_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_8tap_dering_cross_reg))
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_lowbd_shift               (8)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_en_shift                  (7)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_slope_shift               (4)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_edgelevel_gain_shift            (0)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_lowbd_mask                (0x00001F00)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_en_mask                   (0x00000080)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_slope_mask                (0x00000070)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_edgelevel_gain_mask             (0x00000007)
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_lowbd(data)               (0x00001F00&((data)<<8))
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_en(data)                  (0x00000080&((data)<<7))
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_cross_slope(data)               (0x00000070&((data)<<4))
#define  SCALEUP_DM_UZU_8tap_dering_cross_dering_edgelevel_gain(data)            (0x00000007&(data))
#define  SCALEUP_DM_UZU_8tap_dering_cross_get_dering_cross_lowbd(data)           ((0x00001F00&(data))>>8)
#define  SCALEUP_DM_UZU_8tap_dering_cross_get_dering_cross_en(data)              ((0x00000080&(data))>>7)
#define  SCALEUP_DM_UZU_8tap_dering_cross_get_dering_cross_slope(data)           ((0x00000070&(data))>>4)
#define  SCALEUP_DM_UZU_8tap_dering_cross_get_dering_edgelevel_gain(data)        (0x00000007&(data))

#define  SCALEUP_DM_UZU_gap_dering                                               0x18029170
#define  SCALEUP_DM_UZU_gap_dering_reg_addr                                      "0xB8029170"
#define  SCALEUP_DM_UZU_gap_dering_reg                                           0xB8029170
#define  SCALEUP_DM_UZU_gap_dering_inst_addr                                     "0x000D"
#define  set_SCALEUP_DM_UZU_gap_dering_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_gap_dering_reg)=data)
#define  get_SCALEUP_DM_UZU_gap_dering_reg                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_gap_dering_reg))
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_side_gain_shift                    (28)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_center_gain_shift                  (25)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_offset_shift                       (21)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_sidemode_shift                     (20)
#define  SCALEUP_DM_UZU_gap_dering_dering_h4h8_blend_type_shift                  (18)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_side_gain_mask                     (0xF0000000)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_center_gain_mask                   (0x0E000000)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_offset_mask                        (0x01E00000)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_sidemode_mask                      (0x00100000)
#define  SCALEUP_DM_UZU_gap_dering_dering_h4h8_blend_type_mask                   (0x000C0000)
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_side_gain(data)                    (0xF0000000&((data)<<28))
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_center_gain(data)                  (0x0E000000&((data)<<25))
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_offset(data)                       (0x01E00000&((data)<<21))
#define  SCALEUP_DM_UZU_gap_dering_dering_gap_sidemode(data)                     (0x00100000&((data)<<20))
#define  SCALEUP_DM_UZU_gap_dering_dering_h4h8_blend_type(data)                  (0x000C0000&((data)<<18))
#define  SCALEUP_DM_UZU_gap_dering_get_dering_gap_side_gain(data)                ((0xF0000000&(data))>>28)
#define  SCALEUP_DM_UZU_gap_dering_get_dering_gap_center_gain(data)              ((0x0E000000&(data))>>25)
#define  SCALEUP_DM_UZU_gap_dering_get_dering_gap_offset(data)                   ((0x01E00000&(data))>>21)
#define  SCALEUP_DM_UZU_gap_dering_get_dering_gap_sidemode(data)                 ((0x00100000&(data))>>20)
#define  SCALEUP_DM_UZU_gap_dering_get_dering_h4h8_blend_type(data)              ((0x000C0000&(data))>>18)

#define  SCALEUP_DM_UZU_Peaking_Coring                                           0x18029038
#define  SCALEUP_DM_UZU_Peaking_Coring_reg_addr                                  "0xB8029038"
#define  SCALEUP_DM_UZU_Peaking_Coring_reg                                       0xB8029038
#define  SCALEUP_DM_UZU_Peaking_Coring_inst_addr                                 "0x000E"
#define  set_SCALEUP_DM_UZU_Peaking_Coring_reg(data)                             (*((volatile unsigned int*)SCALEUP_DM_UZU_Peaking_Coring_reg)=data)
#define  get_SCALEUP_DM_UZU_Peaking_Coring_reg                                   (*((volatile unsigned int*)SCALEUP_DM_UZU_Peaking_Coring_reg))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c0_shift                          (25)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c1_shift                          (21)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c2_shift                          (17)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_en_shift                               (16)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_coring_shift                           (8)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_x1_shift                               (0)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c0_mask                           (0x3E000000)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c1_mask                           (0x01E00000)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c2_mask                           (0x001E0000)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_en_mask                                (0x00010000)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_coring_mask                            (0x0000FF00)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_x1_mask                                (0x000000FF)
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c0(data)                          (0x3E000000&((data)<<25))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c1(data)                          (0x01E00000&((data)<<21))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_mask_c2(data)                          (0x001E0000&((data)<<17))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_en(data)                               (0x00010000&((data)<<16))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_coring(data)                           (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZU_Peaking_Coring_pk_x1(data)                               (0x000000FF&(data))
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_mask_c0(data)                      ((0x3E000000&(data))>>25)
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_mask_c1(data)                      ((0x01E00000&(data))>>21)
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_mask_c2(data)                      ((0x001E0000&(data))>>17)
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_en(data)                           ((0x00010000&(data))>>16)
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_coring(data)                       ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZU_Peaking_Coring_get_pk_x1(data)                           (0x000000FF&(data))

#define  SCALEUP_DM_UZU_Peaking_Gain                                             0x1802903C
#define  SCALEUP_DM_UZU_Peaking_Gain_reg_addr                                    "0xB802903C"
#define  SCALEUP_DM_UZU_Peaking_Gain_reg                                         0xB802903C
#define  SCALEUP_DM_UZU_Peaking_Gain_inst_addr                                   "0x000F"
#define  set_SCALEUP_DM_UZU_Peaking_Gain_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_UZU_Peaking_Gain_reg)=data)
#define  get_SCALEUP_DM_UZU_Peaking_Gain_reg                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Peaking_Gain_reg))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_mask_c3_shift                            (26)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_shiftbit_shift                           (24)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_offset_shift                             (16)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtp_shift                               (12)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtn_shift                               (8)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g1_shift                                 (4)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g2_shift                                 (0)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_mask_c3_mask                             (0x3C000000)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_shiftbit_mask                            (0x03000000)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_offset_mask                              (0x00FF0000)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtp_mask                                (0x0000F000)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtn_mask                                (0x00000F00)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g1_mask                                  (0x000000F0)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g2_mask                                  (0x0000000F)
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_mask_c3(data)                            (0x3C000000&((data)<<26))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_shiftbit(data)                           (0x03000000&((data)<<24))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_offset(data)                             (0x00FF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtp(data)                               (0x0000F000&((data)<<12))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_lmtn(data)                               (0x00000F00&((data)<<8))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g1(data)                                 (0x000000F0&((data)<<4))
#define  SCALEUP_DM_UZU_Peaking_Gain_pk_g2(data)                                 (0x0000000F&(data))
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_mask_c3(data)                        ((0x3C000000&(data))>>26)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_shiftbit(data)                       ((0x03000000&(data))>>24)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_offset(data)                         ((0x00FF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_lmtp(data)                           ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_lmtn(data)                           ((0x00000F00&(data))>>8)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_g1(data)                             ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_UZU_Peaking_Gain_get_pk_g2(data)                             (0x0000000F&(data))

#define  SCALEUP_DM_MEM_CRC_CTRL                                                 0x18029040
#define  SCALEUP_DM_MEM_CRC_CTRL_reg_addr                                        "0xB8029040"
#define  SCALEUP_DM_MEM_CRC_CTRL_reg                                             0xB8029040
#define  SCALEUP_DM_MEM_CRC_CTRL_inst_addr                                       "0x0010"
#define  set_SCALEUP_DM_MEM_CRC_CTRL_reg(data)                                   (*((volatile unsigned int*)SCALEUP_DM_MEM_CRC_CTRL_reg)=data)
#define  get_SCALEUP_DM_MEM_CRC_CTRL_reg                                         (*((volatile unsigned int*)SCALEUP_DM_MEM_CRC_CTRL_reg))
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_type3_thd_shift                            (16)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_gain_shift                                 (8)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_select_shift                               (5)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_en_shift                                   (4)
#define  SCALEUP_DM_MEM_CRC_CTRL_conti_shift                                     (1)
#define  SCALEUP_DM_MEM_CRC_CTRL_start_shift                                     (0)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_type3_thd_mask                             (0x003F0000)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_gain_mask                                  (0x00007F00)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_select_mask                                (0x00000060)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_en_mask                                    (0x00000010)
#define  SCALEUP_DM_MEM_CRC_CTRL_conti_mask                                      (0x00000002)
#define  SCALEUP_DM_MEM_CRC_CTRL_start_mask                                      (0x00000001)
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_type3_thd(data)                            (0x003F0000&((data)<<16))
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_gain(data)                                 (0x00007F00&((data)<<8))
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_select(data)                               (0x00000060&((data)<<5))
#define  SCALEUP_DM_MEM_CRC_CTRL_vcti_en(data)                                   (0x00000010&((data)<<4))
#define  SCALEUP_DM_MEM_CRC_CTRL_conti(data)                                     (0x00000002&((data)<<1))
#define  SCALEUP_DM_MEM_CRC_CTRL_start(data)                                     (0x00000001&(data))
#define  SCALEUP_DM_MEM_CRC_CTRL_get_vcti_type3_thd(data)                        ((0x003F0000&(data))>>16)
#define  SCALEUP_DM_MEM_CRC_CTRL_get_vcti_gain(data)                             ((0x00007F00&(data))>>8)
#define  SCALEUP_DM_MEM_CRC_CTRL_get_vcti_select(data)                           ((0x00000060&(data))>>5)
#define  SCALEUP_DM_MEM_CRC_CTRL_get_vcti_en(data)                               ((0x00000010&(data))>>4)
#define  SCALEUP_DM_MEM_CRC_CTRL_get_conti(data)                                 ((0x00000002&(data))>>1)
#define  SCALEUP_DM_MEM_CRC_CTRL_get_start(data)                                 (0x00000001&(data))

#define  SCALEUP_DM_MEM_CRC_Result                                               0x18029044
#define  SCALEUP_DM_MEM_CRC_Result_reg_addr                                      "0xB8029044"
#define  SCALEUP_DM_MEM_CRC_Result_reg                                           0xB8029044
#define  SCALEUP_DM_MEM_CRC_Result_inst_addr                                     "0x0011"
#define  set_SCALEUP_DM_MEM_CRC_Result_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DM_MEM_CRC_Result_reg)=data)
#define  get_SCALEUP_DM_MEM_CRC_Result_reg                                       (*((volatile unsigned int*)SCALEUP_DM_MEM_CRC_Result_reg))
#define  SCALEUP_DM_MEM_CRC_Result_mem_crc_shift                                 (0)
#define  SCALEUP_DM_MEM_CRC_Result_mem_crc_mask                                  (0xFFFFFFFF)
#define  SCALEUP_DM_MEM_CRC_Result_mem_crc(data)                                 (0xFFFFFFFF&(data))
#define  SCALEUP_DM_MEM_CRC_Result_get_mem_crc(data)                             (0xFFFFFFFF&(data))

#define  SCALEUP_MEM_CRC_Ctr2                                                    0x18029048
#define  SCALEUP_MEM_CRC_Ctr2_reg_addr                                           "0xB8029048"
#define  SCALEUP_MEM_CRC_Ctr2_reg                                                0xB8029048
#define  SCALEUP_MEM_CRC_Ctr2_inst_addr                                          "0x0012"
#define  set_SCALEUP_MEM_CRC_Ctr2_reg(data)                                      (*((volatile unsigned int*)SCALEUP_MEM_CRC_Ctr2_reg)=data)
#define  get_SCALEUP_MEM_CRC_Ctr2_reg                                            (*((volatile unsigned int*)SCALEUP_MEM_CRC_Ctr2_reg))
#define  SCALEUP_MEM_CRC_Ctr2_r_auto_cmp_en_shift                                (2)
#define  SCALEUP_MEM_CRC_Ctr2_l_auto_cmp_en_shift                                (1)
#define  SCALEUP_MEM_CRC_Ctr2_crc_3d_en_shift                                    (0)
#define  SCALEUP_MEM_CRC_Ctr2_r_auto_cmp_en_mask                                 (0x00000004)
#define  SCALEUP_MEM_CRC_Ctr2_l_auto_cmp_en_mask                                 (0x00000002)
#define  SCALEUP_MEM_CRC_Ctr2_crc_3d_en_mask                                     (0x00000001)
#define  SCALEUP_MEM_CRC_Ctr2_r_auto_cmp_en(data)                                (0x00000004&((data)<<2))
#define  SCALEUP_MEM_CRC_Ctr2_l_auto_cmp_en(data)                                (0x00000002&((data)<<1))
#define  SCALEUP_MEM_CRC_Ctr2_crc_3d_en(data)                                    (0x00000001&(data))
#define  SCALEUP_MEM_CRC_Ctr2_get_r_auto_cmp_en(data)                            ((0x00000004&(data))>>2)
#define  SCALEUP_MEM_CRC_Ctr2_get_l_auto_cmp_en(data)                            ((0x00000002&(data))>>1)
#define  SCALEUP_MEM_CRC_Ctr2_get_crc_3d_en(data)                                (0x00000001&(data))

#define  SCALEUP_MEM_CRC_R_Result                                                0x1802904C
#define  SCALEUP_MEM_CRC_R_Result_reg_addr                                       "0xB802904C"
#define  SCALEUP_MEM_CRC_R_Result_reg                                            0xB802904C
#define  SCALEUP_MEM_CRC_R_Result_inst_addr                                      "0x0013"
#define  set_SCALEUP_MEM_CRC_R_Result_reg(data)                                  (*((volatile unsigned int*)SCALEUP_MEM_CRC_R_Result_reg)=data)
#define  get_SCALEUP_MEM_CRC_R_Result_reg                                        (*((volatile unsigned int*)SCALEUP_MEM_CRC_R_Result_reg))
#define  SCALEUP_MEM_CRC_R_Result_crc_r_result_shift                             (0)
#define  SCALEUP_MEM_CRC_R_Result_crc_r_result_mask                              (0xFFFFFFFF)
#define  SCALEUP_MEM_CRC_R_Result_crc_r_result(data)                             (0xFFFFFFFF&(data))
#define  SCALEUP_MEM_CRC_R_Result_get_crc_r_result(data)                         (0xFFFFFFFF&(data))

#define  SCALEUP_MEM_L_DES_CRC                                                   0x18029050
#define  SCALEUP_MEM_L_DES_CRC_reg_addr                                          "0xB8029050"
#define  SCALEUP_MEM_L_DES_CRC_reg                                               0xB8029050
#define  SCALEUP_MEM_L_DES_CRC_inst_addr                                         "0x0014"
#define  set_SCALEUP_MEM_L_DES_CRC_reg(data)                                     (*((volatile unsigned int*)SCALEUP_MEM_L_DES_CRC_reg)=data)
#define  get_SCALEUP_MEM_L_DES_CRC_reg                                           (*((volatile unsigned int*)SCALEUP_MEM_L_DES_CRC_reg))
#define  SCALEUP_MEM_L_DES_CRC_l_des_crc_shift                                   (0)
#define  SCALEUP_MEM_L_DES_CRC_l_des_crc_mask                                    (0xFFFFFFFF)
#define  SCALEUP_MEM_L_DES_CRC_l_des_crc(data)                                   (0xFFFFFFFF&(data))
#define  SCALEUP_MEM_L_DES_CRC_get_l_des_crc(data)                               (0xFFFFFFFF&(data))

#define  SCALEUP_MEM_R_DES_CRC                                                   0x18029054
#define  SCALEUP_MEM_R_DES_CRC_reg_addr                                          "0xB8029054"
#define  SCALEUP_MEM_R_DES_CRC_reg                                               0xB8029054
#define  SCALEUP_MEM_R_DES_CRC_inst_addr                                         "0x0015"
#define  set_SCALEUP_MEM_R_DES_CRC_reg(data)                                     (*((volatile unsigned int*)SCALEUP_MEM_R_DES_CRC_reg)=data)
#define  get_SCALEUP_MEM_R_DES_CRC_reg                                           (*((volatile unsigned int*)SCALEUP_MEM_R_DES_CRC_reg))
#define  SCALEUP_MEM_R_DES_CRC_r_des_crc_shift                                   (0)
#define  SCALEUP_MEM_R_DES_CRC_r_des_crc_mask                                    (0xFFFFFFFF)
#define  SCALEUP_MEM_R_DES_CRC_r_des_crc(data)                                   (0xFFFFFFFF&(data))
#define  SCALEUP_MEM_R_DES_CRC_get_r_des_crc(data)                               (0xFFFFFFFF&(data))

#define  SCALEUP_MEM_CRC_ERR_CNT                                                 0x18029058
#define  SCALEUP_MEM_CRC_ERR_CNT_reg_addr                                        "0xB8029058"
#define  SCALEUP_MEM_CRC_ERR_CNT_reg                                             0xB8029058
#define  SCALEUP_MEM_CRC_ERR_CNT_inst_addr                                       "0x0016"
#define  set_SCALEUP_MEM_CRC_ERR_CNT_reg(data)                                   (*((volatile unsigned int*)SCALEUP_MEM_CRC_ERR_CNT_reg)=data)
#define  get_SCALEUP_MEM_CRC_ERR_CNT_reg                                         (*((volatile unsigned int*)SCALEUP_MEM_CRC_ERR_CNT_reg))
#define  SCALEUP_MEM_CRC_ERR_CNT_r_crc_err_cnt_shift                             (16)
#define  SCALEUP_MEM_CRC_ERR_CNT_l_crc_err_cnt_shift                             (0)
#define  SCALEUP_MEM_CRC_ERR_CNT_r_crc_err_cnt_mask                              (0xFFFF0000)
#define  SCALEUP_MEM_CRC_ERR_CNT_l_crc_err_cnt_mask                              (0x0000FFFF)
#define  SCALEUP_MEM_CRC_ERR_CNT_r_crc_err_cnt(data)                             (0xFFFF0000&((data)<<16))
#define  SCALEUP_MEM_CRC_ERR_CNT_l_crc_err_cnt(data)                             (0x0000FFFF&(data))
#define  SCALEUP_MEM_CRC_ERR_CNT_get_r_crc_err_cnt(data)                         ((0xFFFF0000&(data))>>16)
#define  SCALEUP_MEM_CRC_ERR_CNT_get_l_crc_err_cnt(data)                         (0x0000FFFF&(data))

#define  SCALEUP_D_UZU_CRC_CTRL                                                  0x1802905C
#define  SCALEUP_D_UZU_CRC_CTRL_reg_addr                                         "0xB802905C"
#define  SCALEUP_D_UZU_CRC_CTRL_reg                                              0xB802905C
#define  SCALEUP_D_UZU_CRC_CTRL_inst_addr                                        "0x0017"
#define  set_SCALEUP_D_UZU_CRC_CTRL_reg(data)                                    (*((volatile unsigned int*)SCALEUP_D_UZU_CRC_CTRL_reg)=data)
#define  get_SCALEUP_D_UZU_CRC_CTRL_reg                                          (*((volatile unsigned int*)SCALEUP_D_UZU_CRC_CTRL_reg))
#define  SCALEUP_D_UZU_CRC_CTRL_ch_sel_shift                                     (2)
#define  SCALEUP_D_UZU_CRC_CTRL_conti_shift                                      (1)
#define  SCALEUP_D_UZU_CRC_CTRL_start_shift                                      (0)
#define  SCALEUP_D_UZU_CRC_CTRL_ch_sel_mask                                      (0x00000004)
#define  SCALEUP_D_UZU_CRC_CTRL_conti_mask                                       (0x00000002)
#define  SCALEUP_D_UZU_CRC_CTRL_start_mask                                       (0x00000001)
#define  SCALEUP_D_UZU_CRC_CTRL_ch_sel(data)                                     (0x00000004&((data)<<2))
#define  SCALEUP_D_UZU_CRC_CTRL_conti(data)                                      (0x00000002&((data)<<1))
#define  SCALEUP_D_UZU_CRC_CTRL_start(data)                                      (0x00000001&(data))
#define  SCALEUP_D_UZU_CRC_CTRL_get_ch_sel(data)                                 ((0x00000004&(data))>>2)
#define  SCALEUP_D_UZU_CRC_CTRL_get_conti(data)                                  ((0x00000002&(data))>>1)
#define  SCALEUP_D_UZU_CRC_CTRL_get_start(data)                                  (0x00000001&(data))

#define  SCALEUP_D_UZU_CRC_Result                                                0x18029060
#define  SCALEUP_D_UZU_CRC_Result_reg_addr                                       "0xB8029060"
#define  SCALEUP_D_UZU_CRC_Result_reg                                            0xB8029060
#define  SCALEUP_D_UZU_CRC_Result_inst_addr                                      "0x0018"
#define  set_SCALEUP_D_UZU_CRC_Result_reg(data)                                  (*((volatile unsigned int*)SCALEUP_D_UZU_CRC_Result_reg)=data)
#define  get_SCALEUP_D_UZU_CRC_Result_reg                                        (*((volatile unsigned int*)SCALEUP_D_UZU_CRC_Result_reg))
#define  SCALEUP_D_UZU_CRC_Result_uzu_crc_shift                                  (0)
#define  SCALEUP_D_UZU_CRC_Result_uzu_crc_mask                                   (0xFFFFFFFF)
#define  SCALEUP_D_UZU_CRC_Result_uzu_crc(data)                                  (0xFFFFFFFF&(data))
#define  SCALEUP_D_UZU_CRC_Result_get_uzu_crc(data)                              (0xFFFFFFFF&(data))

#define  SCALEUP_D_UZU_PATGEN_COLOR0                                             0x18029064
#define  SCALEUP_D_UZU_PATGEN_COLOR0_reg_addr                                    "0xB8029064"
#define  SCALEUP_D_UZU_PATGEN_COLOR0_reg                                         0xB8029064
#define  SCALEUP_D_UZU_PATGEN_COLOR0_inst_addr                                   "0x0019"
#define  set_SCALEUP_D_UZU_PATGEN_COLOR0_reg(data)                               (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR0_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_COLOR0_reg                                     (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR0_reg))
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_y_shift                           (16)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cr_shift                          (8)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cb_shift                          (0)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_y_mask                            (0x00FF0000)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cr_mask                           (0x0000FF00)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cb_mask                           (0x000000FF)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_y(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cr(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_D_UZU_PATGEN_COLOR0_patgen_c0_cb(data)                          (0x000000FF&(data))
#define  SCALEUP_D_UZU_PATGEN_COLOR0_get_patgen_c0_y(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_get_patgen_c0_cr(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_D_UZU_PATGEN_COLOR0_get_patgen_c0_cb(data)                      (0x000000FF&(data))

#define  SCALEUP_D_UZU_PATGEN_COLOR1                                             0x18029068
#define  SCALEUP_D_UZU_PATGEN_COLOR1_reg_addr                                    "0xB8029068"
#define  SCALEUP_D_UZU_PATGEN_COLOR1_reg                                         0xB8029068
#define  SCALEUP_D_UZU_PATGEN_COLOR1_inst_addr                                   "0x001A"
#define  set_SCALEUP_D_UZU_PATGEN_COLOR1_reg(data)                               (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR1_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_COLOR1_reg                                     (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR1_reg))
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_y_shift                           (16)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cr_shift                          (8)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cb_shift                          (0)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_y_mask                            (0x00FF0000)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cr_mask                           (0x0000FF00)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cb_mask                           (0x000000FF)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_y(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cr(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_D_UZU_PATGEN_COLOR1_patgen_c1_cb(data)                          (0x000000FF&(data))
#define  SCALEUP_D_UZU_PATGEN_COLOR1_get_patgen_c1_y(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_get_patgen_c1_cr(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_D_UZU_PATGEN_COLOR1_get_patgen_c1_cb(data)                      (0x000000FF&(data))

#define  SCALEUP_D_UZU_PATGEN_COLOR2                                             0x1802906C
#define  SCALEUP_D_UZU_PATGEN_COLOR2_reg_addr                                    "0xB802906C"
#define  SCALEUP_D_UZU_PATGEN_COLOR2_reg                                         0xB802906C
#define  SCALEUP_D_UZU_PATGEN_COLOR2_inst_addr                                   "0x001B"
#define  set_SCALEUP_D_UZU_PATGEN_COLOR2_reg(data)                               (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR2_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_COLOR2_reg                                     (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR2_reg))
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_y_shift                           (16)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cr_shift                          (8)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cb_shift                          (0)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_y_mask                            (0x00FF0000)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cr_mask                           (0x0000FF00)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cb_mask                           (0x000000FF)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_y(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cr(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_D_UZU_PATGEN_COLOR2_patgen_c2_cb(data)                          (0x000000FF&(data))
#define  SCALEUP_D_UZU_PATGEN_COLOR2_get_patgen_c2_y(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_get_patgen_c2_cr(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_D_UZU_PATGEN_COLOR2_get_patgen_c2_cb(data)                      (0x000000FF&(data))

#define  SCALEUP_D_UZU_PATGEN_COLOR3                                             0x18029070
#define  SCALEUP_D_UZU_PATGEN_COLOR3_reg_addr                                    "0xB8029070"
#define  SCALEUP_D_UZU_PATGEN_COLOR3_reg                                         0xB8029070
#define  SCALEUP_D_UZU_PATGEN_COLOR3_inst_addr                                   "0x001C"
#define  set_SCALEUP_D_UZU_PATGEN_COLOR3_reg(data)                               (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR3_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_COLOR3_reg                                     (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_COLOR3_reg))
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_y_shift                           (16)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cr_shift                          (8)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cb_shift                          (0)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_y_mask                            (0x00FF0000)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cr_mask                           (0x0000FF00)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cb_mask                           (0x000000FF)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_y(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cr(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_D_UZU_PATGEN_COLOR3_patgen_c3_cb(data)                          (0x000000FF&(data))
#define  SCALEUP_D_UZU_PATGEN_COLOR3_get_patgen_c3_y(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_get_patgen_c3_cr(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_D_UZU_PATGEN_COLOR3_get_patgen_c3_cb(data)                      (0x000000FF&(data))

#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE                                       0x18029074
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg_addr                              "0xB8029074"
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg                                   0xB8029074
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_inst_addr                             "0x001D"
#define  set_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg(data)                         (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg                               (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_reg))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num_shift                  (27)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel_shift                  (25)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_lflag_shift                    (24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_width_shift                    (0)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num_mask                   (0xF8000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel_mask                   (0x06000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_lflag_mask                     (0x01000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_width_mask                     (0x003FFFFF)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num(data)                  (0xF8000000&((data)<<27))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel(data)                  (0x06000000&((data)<<25))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_lflag(data)                    (0x01000000&((data)<<24))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_patgen_width(data)                    (0x003FFFFF&(data))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_get_patgen_tog_num(data)              ((0xF8000000&(data))>>27)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_get_patgen_tog_sel(data)              ((0x06000000&(data))>>25)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_get_patgen_lflag(data)                ((0x01000000&(data))>>24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE_get_patgen_width(data)                (0x003FFFFF&(data))

#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1                                      0x18029078
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg_addr                             "0xB8029078"
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg                                  0xB8029078
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_inst_addr                            "0x001E"
#define  set_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg(data)                        (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg                              (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_reg))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_lflag_1_shift                 (24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1_shift                 (0)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_lflag_1_mask                  (0x01000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1_mask                  (0x003FFFFF)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_lflag_1(data)                 (0x01000000&((data)<<24))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1(data)                 (0x003FFFFF&(data))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_get_patgen_lflag_1(data)             ((0x01000000&(data))>>24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE1_get_patgen_width_1(data)             (0x003FFFFF&(data))

#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2                                      0x1802907C
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg_addr                             "0xB802907C"
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg                                  0xB802907C
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_inst_addr                            "0x001F"
#define  set_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg(data)                        (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg                              (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_reg))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_lflag_2_shift                 (24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2_shift                 (0)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_lflag_2_mask                  (0x01000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2_mask                  (0x003FFFFF)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_lflag_2(data)                 (0x01000000&((data)<<24))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2(data)                 (0x003FFFFF&(data))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_get_patgen_lflag_2(data)             ((0x01000000&(data))>>24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE2_get_patgen_width_2(data)             (0x003FFFFF&(data))

#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3                                      0x18029080
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg_addr                             "0xB8029080"
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg                                  0xB8029080
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_inst_addr                            "0x0020"
#define  set_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg(data)                        (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg)=data)
#define  get_SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg                              (*((volatile unsigned int*)SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_reg))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_lflag_3_shift                 (24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3_shift                 (0)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_lflag_3_mask                  (0x01000000)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3_mask                  (0x003FFFFF)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_lflag_3(data)                 (0x01000000&((data)<<24))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3(data)                 (0x003FFFFF&(data))
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_get_patgen_lflag_3(data)             ((0x01000000&(data))>>24)
#define  SCALEUP_D_UZU_PATGEN_FRAME_TOGGLE3_get_patgen_width_3(data)             (0x003FFFFF&(data))

#define  SCALEUP_AccessData_CTRL_UZU                                             0x18029090
#define  SCALEUP_AccessData_CTRL_UZU_reg_addr                                    "0xB8029090"
#define  SCALEUP_AccessData_CTRL_UZU_reg                                         0xB8029090
#define  SCALEUP_AccessData_CTRL_UZU_inst_addr                                   "0x0021"
#define  set_SCALEUP_AccessData_CTRL_UZU_reg(data)                               (*((volatile unsigned int*)SCALEUP_AccessData_CTRL_UZU_reg)=data)
#define  get_SCALEUP_AccessData_CTRL_UZU_reg                                     (*((volatile unsigned int*)SCALEUP_AccessData_CTRL_UZU_reg))
#define  SCALEUP_AccessData_CTRL_UZU_ch_sel_shift                                (2)
#define  SCALEUP_AccessData_CTRL_UZU_write_en_shift                              (1)
#define  SCALEUP_AccessData_CTRL_UZU_read_en_shift                               (0)
#define  SCALEUP_AccessData_CTRL_UZU_ch_sel_mask                                 (0x00000004)
#define  SCALEUP_AccessData_CTRL_UZU_write_en_mask                               (0x00000002)
#define  SCALEUP_AccessData_CTRL_UZU_read_en_mask                                (0x00000001)
#define  SCALEUP_AccessData_CTRL_UZU_ch_sel(data)                                (0x00000004&((data)<<2))
#define  SCALEUP_AccessData_CTRL_UZU_write_en(data)                              (0x00000002&((data)<<1))
#define  SCALEUP_AccessData_CTRL_UZU_read_en(data)                               (0x00000001&(data))
#define  SCALEUP_AccessData_CTRL_UZU_get_ch_sel(data)                            ((0x00000004&(data))>>2)
#define  SCALEUP_AccessData_CTRL_UZU_get_write_en(data)                          ((0x00000002&(data))>>1)
#define  SCALEUP_AccessData_CTRL_UZU_get_read_en(data)                           (0x00000001&(data))

#define  SCALEUP_AccessData_PosCtrl_UZU                                          0x18029094
#define  SCALEUP_AccessData_PosCtrl_UZU_reg_addr                                 "0xB8029094"
#define  SCALEUP_AccessData_PosCtrl_UZU_reg                                      0xB8029094
#define  SCALEUP_AccessData_PosCtrl_UZU_inst_addr                                "0x0022"
#define  set_SCALEUP_AccessData_PosCtrl_UZU_reg(data)                            (*((volatile unsigned int*)SCALEUP_AccessData_PosCtrl_UZU_reg)=data)
#define  get_SCALEUP_AccessData_PosCtrl_UZU_reg                                  (*((volatile unsigned int*)SCALEUP_AccessData_PosCtrl_UZU_reg))
#define  SCALEUP_AccessData_PosCtrl_UZU_starty_shift                             (16)
#define  SCALEUP_AccessData_PosCtrl_UZU_startx_shift                             (0)
#define  SCALEUP_AccessData_PosCtrl_UZU_starty_mask                              (0x0FFF0000)
#define  SCALEUP_AccessData_PosCtrl_UZU_startx_mask                              (0x00000FFF)
#define  SCALEUP_AccessData_PosCtrl_UZU_starty(data)                             (0x0FFF0000&((data)<<16))
#define  SCALEUP_AccessData_PosCtrl_UZU_startx(data)                             (0x00000FFF&(data))
#define  SCALEUP_AccessData_PosCtrl_UZU_get_starty(data)                         ((0x0FFF0000&(data))>>16)
#define  SCALEUP_AccessData_PosCtrl_UZU_get_startx(data)                         (0x00000FFF&(data))

#define  SCALEUP_ReadData_DATA_Y1_UZU                                            0x18029098
#define  SCALEUP_ReadData_DATA_Y1_UZU_reg_addr                                   "0xB8029098"
#define  SCALEUP_ReadData_DATA_Y1_UZU_reg                                        0xB8029098
#define  SCALEUP_ReadData_DATA_Y1_UZU_inst_addr                                  "0x0023"
#define  set_SCALEUP_ReadData_DATA_Y1_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_Y1_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_Y1_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_Y1_UZU_reg))
#define  SCALEUP_ReadData_DATA_Y1_UZU_y01_shift                                  (16)
#define  SCALEUP_ReadData_DATA_Y1_UZU_y00_shift                                  (0)
#define  SCALEUP_ReadData_DATA_Y1_UZU_y01_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_Y1_UZU_y00_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_Y1_UZU_y01(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_Y1_UZU_y00(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_Y1_UZU_get_y01(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_Y1_UZU_get_y00(data)                              (0x000003FF&(data))

#define  SCALEUP_ReadData_DATA_Y2_UZU                                            0x1802909C
#define  SCALEUP_ReadData_DATA_Y2_UZU_reg_addr                                   "0xB802909C"
#define  SCALEUP_ReadData_DATA_Y2_UZU_reg                                        0xB802909C
#define  SCALEUP_ReadData_DATA_Y2_UZU_inst_addr                                  "0x0024"
#define  set_SCALEUP_ReadData_DATA_Y2_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_Y2_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_Y2_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_Y2_UZU_reg))
#define  SCALEUP_ReadData_DATA_Y2_UZU_y11_shift                                  (16)
#define  SCALEUP_ReadData_DATA_Y2_UZU_y10_shift                                  (0)
#define  SCALEUP_ReadData_DATA_Y2_UZU_y11_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_Y2_UZU_y10_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_Y2_UZU_y11(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_Y2_UZU_y10(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_Y2_UZU_get_y11(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_Y2_UZU_get_y10(data)                              (0x000003FF&(data))

#define  SCALEUP_ReadData_DATA_C1_UZU                                            0x180290A0
#define  SCALEUP_ReadData_DATA_C1_UZU_reg_addr                                   "0xB80290A0"
#define  SCALEUP_ReadData_DATA_C1_UZU_reg                                        0xB80290A0
#define  SCALEUP_ReadData_DATA_C1_UZU_inst_addr                                  "0x0025"
#define  set_SCALEUP_ReadData_DATA_C1_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C1_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_C1_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C1_UZU_reg))
#define  SCALEUP_ReadData_DATA_C1_UZU_v00_shift                                  (16)
#define  SCALEUP_ReadData_DATA_C1_UZU_u00_shift                                  (0)
#define  SCALEUP_ReadData_DATA_C1_UZU_v00_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_C1_UZU_u00_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_C1_UZU_v00(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_C1_UZU_u00(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_C1_UZU_get_v00(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_C1_UZU_get_u00(data)                              (0x000003FF&(data))

#define  SCALEUP_ReadData_DATA_C2_UZU                                            0x180290A4
#define  SCALEUP_ReadData_DATA_C2_UZU_reg_addr                                   "0xB80290A4"
#define  SCALEUP_ReadData_DATA_C2_UZU_reg                                        0xB80290A4
#define  SCALEUP_ReadData_DATA_C2_UZU_inst_addr                                  "0x0026"
#define  set_SCALEUP_ReadData_DATA_C2_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C2_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_C2_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C2_UZU_reg))
#define  SCALEUP_ReadData_DATA_C2_UZU_v01_shift                                  (16)
#define  SCALEUP_ReadData_DATA_C2_UZU_u01_shift                                  (0)
#define  SCALEUP_ReadData_DATA_C2_UZU_v01_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_C2_UZU_u01_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_C2_UZU_v01(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_C2_UZU_u01(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_C2_UZU_get_v01(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_C2_UZU_get_u01(data)                              (0x000003FF&(data))

#define  SCALEUP_ReadData_DATA_C3_UZU                                            0x180290A8
#define  SCALEUP_ReadData_DATA_C3_UZU_reg_addr                                   "0xB80290A8"
#define  SCALEUP_ReadData_DATA_C3_UZU_reg                                        0xB80290A8
#define  SCALEUP_ReadData_DATA_C3_UZU_inst_addr                                  "0x0027"
#define  set_SCALEUP_ReadData_DATA_C3_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C3_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_C3_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C3_UZU_reg))
#define  SCALEUP_ReadData_DATA_C3_UZU_v10_shift                                  (16)
#define  SCALEUP_ReadData_DATA_C3_UZU_u10_shift                                  (0)
#define  SCALEUP_ReadData_DATA_C3_UZU_v10_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_C3_UZU_u10_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_C3_UZU_v10(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_C3_UZU_u10(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_C3_UZU_get_v10(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_C3_UZU_get_u10(data)                              (0x000003FF&(data))

#define  SCALEUP_ReadData_DATA_C4_UZU                                            0x180290AC
#define  SCALEUP_ReadData_DATA_C4_UZU_reg_addr                                   "0xB80290AC"
#define  SCALEUP_ReadData_DATA_C4_UZU_reg                                        0xB80290AC
#define  SCALEUP_ReadData_DATA_C4_UZU_inst_addr                                  "0x0028"
#define  set_SCALEUP_ReadData_DATA_C4_UZU_reg(data)                              (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C4_UZU_reg)=data)
#define  get_SCALEUP_ReadData_DATA_C4_UZU_reg                                    (*((volatile unsigned int*)SCALEUP_ReadData_DATA_C4_UZU_reg))
#define  SCALEUP_ReadData_DATA_C4_UZU_v11_shift                                  (16)
#define  SCALEUP_ReadData_DATA_C4_UZU_u11_shift                                  (0)
#define  SCALEUP_ReadData_DATA_C4_UZU_v11_mask                                   (0x03FF0000)
#define  SCALEUP_ReadData_DATA_C4_UZU_u11_mask                                   (0x000003FF)
#define  SCALEUP_ReadData_DATA_C4_UZU_v11(data)                                  (0x03FF0000&((data)<<16))
#define  SCALEUP_ReadData_DATA_C4_UZU_u11(data)                                  (0x000003FF&(data))
#define  SCALEUP_ReadData_DATA_C4_UZU_get_v11(data)                              ((0x03FF0000&(data))>>16)
#define  SCALEUP_ReadData_DATA_C4_UZU_get_u11(data)                              (0x000003FF&(data))

#define  SCALEUP_WriteData_DATA_UZU                                              0x180290B0
#define  SCALEUP_WriteData_DATA_UZU_reg_addr                                     "0xB80290B0"
#define  SCALEUP_WriteData_DATA_UZU_reg                                          0xB80290B0
#define  SCALEUP_WriteData_DATA_UZU_inst_addr                                    "0x0029"
#define  set_SCALEUP_WriteData_DATA_UZU_reg(data)                                (*((volatile unsigned int*)SCALEUP_WriteData_DATA_UZU_reg)=data)
#define  get_SCALEUP_WriteData_DATA_UZU_reg                                      (*((volatile unsigned int*)SCALEUP_WriteData_DATA_UZU_reg))
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_lbound2_shift                       (22)
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_hbound2_shift                       (12)
#define  SCALEUP_WriteData_DATA_UZU_v_shift                                      (8)
#define  SCALEUP_WriteData_DATA_UZU_u_shift                                      (4)
#define  SCALEUP_WriteData_DATA_UZU_y_shift                                      (0)
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_lbound2_mask                        (0xFFC00000)
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_hbound2_mask                        (0x003FF000)
#define  SCALEUP_WriteData_DATA_UZU_v_mask                                       (0x00000F00)
#define  SCALEUP_WriteData_DATA_UZU_u_mask                                       (0x000000F0)
#define  SCALEUP_WriteData_DATA_UZU_y_mask                                       (0x0000000F)
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_lbound2(data)                       (0xFFC00000&((data)<<22))
#define  SCALEUP_WriteData_DATA_UZU_vcti_lpf_hbound2(data)                       (0x003FF000&((data)<<12))
#define  SCALEUP_WriteData_DATA_UZU_v(data)                                      (0x00000F00&((data)<<8))
#define  SCALEUP_WriteData_DATA_UZU_u(data)                                      (0x000000F0&((data)<<4))
#define  SCALEUP_WriteData_DATA_UZU_y(data)                                      (0x0000000F&(data))
#define  SCALEUP_WriteData_DATA_UZU_get_vcti_lpf_lbound2(data)                   ((0xFFC00000&(data))>>22)
#define  SCALEUP_WriteData_DATA_UZU_get_vcti_lpf_hbound2(data)                   ((0x003FF000&(data))>>12)
#define  SCALEUP_WriteData_DATA_UZU_get_v(data)                                  ((0x00000F00&(data))>>8)
#define  SCALEUP_WriteData_DATA_UZU_get_u(data)                                  ((0x000000F0&(data))>>4)
#define  SCALEUP_WriteData_DATA_UZU_get_y(data)                                  (0x0000000F&(data))

#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP                                       0x180290B4
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg_addr                              "0xB80290B4"
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg                                   0xB80290B4
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_inst_addr                             "0x002A"
#define  set_SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg(data)                         (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg)=data)
#define  get_SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg                               (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg))
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_vcti_lpf_lbound1_shift                (22)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_front_drop_shift                (12)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_back_drop_shift                 (0)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_vcti_lpf_lbound1_mask                 (0xFFC00000)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_front_drop_mask                 (0x003FF000)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_back_drop_mask                  (0x000003FF)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_vcti_lpf_lbound1(data)                (0xFFC00000&((data)<<22))
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_front_drop(data)                (0x003FF000&((data)<<12))
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_hor_m_back_drop(data)                 (0x000003FF&(data))
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_get_vcti_lpf_lbound1(data)            ((0xFFC00000&(data))>>22)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_get_hor_m_front_drop(data)            ((0x003FF000&(data))>>12)
#define  SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_get_hor_m_back_drop(data)             (0x000003FF&(data))

#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP                                       0x180290B8
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg_addr                              "0xB80290B8"
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg                                   0xB80290B8
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_inst_addr                             "0x002B"
#define  set_SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg(data)                         (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg)=data)
#define  get_SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg                               (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_reg))
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_lpf_hbound1_shift                (22)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_low_pass_filter_en_shift         (21)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_front_drop_shift                (8)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_back_drop_shift                 (0)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_lpf_hbound1_mask                 (0xFFC00000)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_low_pass_filter_en_mask          (0x00200000)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_front_drop_mask                 (0x0000FF00)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_back_drop_mask                  (0x000000FF)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_lpf_hbound1(data)                (0xFFC00000&((data)<<22))
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_vcti_low_pass_filter_en(data)         (0x00200000&((data)<<21))
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_front_drop(data)                (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_ver_m_back_drop(data)                 (0x000000FF&(data))
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_get_vcti_lpf_hbound1(data)            ((0xFFC00000&(data))>>22)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_get_vcti_low_pass_filter_en(data)     ((0x00200000&(data))>>21)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_get_ver_m_front_drop(data)            ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZUMAIN_V_PARTIAL_DROP_get_ver_m_back_drop(data)             (0x000000FF&(data))

#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL                                        0x180290BC
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg_addr                               "0xB80290BC"
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg                                    0xB80290BC
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_inst_addr                              "0x002C"
#define  set_SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg)=data)
#define  get_SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_reg))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_front_drop_odd_shift             (16)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_back_drop_odd_shift              (4)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_pixel_drop_mode_shift                  (2)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_front_drop_odd_mask              (0x03FF0000)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_back_drop_odd_mask               (0x00003FF0)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_pixel_drop_mode_mask                   (0x00000004)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_front_drop_odd(data)             (0x03FF0000&((data)<<16))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_hor_m_back_drop_odd(data)              (0x00003FF0&((data)<<4))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_pixel_drop_mode(data)                  (0x00000004&((data)<<2))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_get_hor_m_front_drop_odd(data)         ((0x03FF0000&(data))>>16)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_get_hor_m_back_drop_odd(data)          ((0x00003FF0&(data))>>4)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_CTRL_get_pixel_drop_mode(data)              ((0x00000004&(data))>>2)

#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL                                    0x180290F8
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg_addr                           "0xB80290F8"
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg                                0xB80290F8
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_inst_addr                          "0x002D"
#define  set_SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg(data)                      (*((volatile unsigned int*)SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg)=data)
#define  get_SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg                            (*((volatile unsigned int*)SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_reg))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_en_shift                (31)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_sta_shift               (16)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_size_shift              (0)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_en_mask                 (0x80000000)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_sta_mask                (0x0FFF0000)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_size_mask               (0x00000FFF)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_en(data)                (0x80000000&((data)<<31))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_sta(data)               (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_m_mid_drop_size(data)              (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_get_m_mid_drop_en(data)            ((0x80000000&(data))>>31)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_get_m_mid_drop_sta(data)           ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_PARTIAL_DROP_MID_CTRL_get_m_mid_drop_size(data)          (0x00000FFF&(data))

#define  SCALEUP_DM_UZUMAIN_Adapt8tap                                            0x180290C0
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_reg_addr                                   "0xB80290C0"
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_reg                                        0xB80290C0
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_inst_addr                                  "0x002E"
#define  set_SCALEUP_DM_UZUMAIN_Adapt8tap_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_Adapt8tap_reg)=data)
#define  get_SCALEUP_DM_UZUMAIN_Adapt8tap_reg                                    (*((volatile unsigned int*)SCALEUP_DM_UZUMAIN_Adapt8tap_reg))
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_upbnd_shift                         (24)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec3_shift                          (16)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec2_shift                          (8)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec1_shift                          (0)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_upbnd_mask                          (0xFF000000)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec3_mask                           (0x00FF0000)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec2_mask                           (0x0000FF00)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec1_mask                           (0x000000FF)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_upbnd(data)                         (0xFF000000&((data)<<24))
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec3(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec2(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_adapt8_sec1(data)                          (0x000000FF&(data))
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_get_adapt8_upbnd(data)                     ((0xFF000000&(data))>>24)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_get_adapt8_sec3(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_get_adapt8_sec2(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZUMAIN_Adapt8tap_get_adapt8_sec1(data)                      (0x000000FF&(data))

#define  SCALEUP_DM_USM                                                          0x180290C4
#define  SCALEUP_DM_USM_reg_addr                                                 "0xB80290C4"
#define  SCALEUP_DM_USM_reg                                                      0xB80290C4
#define  SCALEUP_DM_USM_inst_addr                                                "0x002F"
#define  set_SCALEUP_DM_USM_reg(data)                                            (*((volatile unsigned int*)SCALEUP_DM_USM_reg)=data)
#define  get_SCALEUP_DM_USM_reg                                                  (*((volatile unsigned int*)SCALEUP_DM_USM_reg))
#define  SCALEUP_DM_USM_debug_mode_shift                                         (29)
#define  SCALEUP_DM_USM_usm_gain_shift                                           (8)
#define  SCALEUP_DM_USM_max_min_range_shift                                      (6)
#define  SCALEUP_DM_USM_max_minus_min_range_shift                                (4)
#define  SCALEUP_DM_USM_max_minus_min_mode_shift                                 (3)
#define  SCALEUP_DM_USM_usm_en_shift                                             (0)
#define  SCALEUP_DM_USM_debug_mode_mask                                          (0xE0000000)
#define  SCALEUP_DM_USM_usm_gain_mask                                            (0x00003F00)
#define  SCALEUP_DM_USM_max_min_range_mask                                       (0x000000C0)
#define  SCALEUP_DM_USM_max_minus_min_range_mask                                 (0x00000030)
#define  SCALEUP_DM_USM_max_minus_min_mode_mask                                  (0x00000008)
#define  SCALEUP_DM_USM_usm_en_mask                                              (0x00000001)
#define  SCALEUP_DM_USM_debug_mode(data)                                         (0xE0000000&((data)<<29))
#define  SCALEUP_DM_USM_usm_gain(data)                                           (0x00003F00&((data)<<8))
#define  SCALEUP_DM_USM_max_min_range(data)                                      (0x000000C0&((data)<<6))
#define  SCALEUP_DM_USM_max_minus_min_range(data)                                (0x00000030&((data)<<4))
#define  SCALEUP_DM_USM_max_minus_min_mode(data)                                 (0x00000008&((data)<<3))
#define  SCALEUP_DM_USM_usm_en(data)                                             (0x00000001&(data))
#define  SCALEUP_DM_USM_get_debug_mode(data)                                     ((0xE0000000&(data))>>29)
#define  SCALEUP_DM_USM_get_usm_gain(data)                                       ((0x00003F00&(data))>>8)
#define  SCALEUP_DM_USM_get_max_min_range(data)                                  ((0x000000C0&(data))>>6)
#define  SCALEUP_DM_USM_get_max_minus_min_range(data)                            ((0x00000030&(data))>>4)
#define  SCALEUP_DM_USM_get_max_minus_min_mode(data)                             ((0x00000008&(data))>>3)
#define  SCALEUP_DM_USM_get_usm_en(data)                                         (0x00000001&(data))

#define  SCALEUP_DM_USM_GAIN_CURVE_0                                             0x180290C8
#define  SCALEUP_DM_USM_GAIN_CURVE_0_reg_addr                                    "0xB80290C8"
#define  SCALEUP_DM_USM_GAIN_CURVE_0_reg                                         0xB80290C8
#define  SCALEUP_DM_USM_GAIN_CURVE_0_inst_addr                                   "0x0030"
#define  set_SCALEUP_DM_USM_GAIN_CURVE_0_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_USM_GAIN_CURVE_0_reg)=data)
#define  get_SCALEUP_DM_USM_GAIN_CURVE_0_reg                                     (*((volatile unsigned int*)SCALEUP_DM_USM_GAIN_CURVE_0_reg))
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_en_shift                         (31)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd0_shift                       (16)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd1_shift                       (8)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd2_shift                       (0)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_en_mask                          (0x80000000)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd0_mask                        (0x00FF0000)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd1_mask                        (0x0000FF00)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd2_mask                        (0x000000FF)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_en(data)                         (0x80000000&((data)<<31))
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd0(data)                       (0x00FF0000&((data)<<16))
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd1(data)                       (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_USM_GAIN_CURVE_0_gain_curve_thd2(data)                       (0x000000FF&(data))
#define  SCALEUP_DM_USM_GAIN_CURVE_0_get_gain_curve_en(data)                     ((0x80000000&(data))>>31)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_get_gain_curve_thd0(data)                   ((0x00FF0000&(data))>>16)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_get_gain_curve_thd1(data)                   ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_USM_GAIN_CURVE_0_get_gain_curve_thd2(data)                   (0x000000FF&(data))

#define  SCALEUP_DM_USM_GAIN_CURVE_1                                             0x180290CC
#define  SCALEUP_DM_USM_GAIN_CURVE_1_reg_addr                                    "0xB80290CC"
#define  SCALEUP_DM_USM_GAIN_CURVE_1_reg                                         0xB80290CC
#define  SCALEUP_DM_USM_GAIN_CURVE_1_inst_addr                                   "0x0031"
#define  set_SCALEUP_DM_USM_GAIN_CURVE_1_reg(data)                               (*((volatile unsigned int*)SCALEUP_DM_USM_GAIN_CURVE_1_reg)=data)
#define  get_SCALEUP_DM_USM_GAIN_CURVE_1_reg                                     (*((volatile unsigned int*)SCALEUP_DM_USM_GAIN_CURVE_1_reg))
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step0_shift                      (24)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step1_shift                      (16)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain0_shift                      (8)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain1_shift                      (0)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step0_mask                       (0x07000000)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step1_mask                       (0x00070000)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain0_mask                       (0x00001F00)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain1_mask                       (0x0000001F)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step0(data)                      (0x07000000&((data)<<24))
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_step1(data)                      (0x00070000&((data)<<16))
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain0(data)                      (0x00001F00&((data)<<8))
#define  SCALEUP_DM_USM_GAIN_CURVE_1_gain_curve_gain1(data)                      (0x0000001F&(data))
#define  SCALEUP_DM_USM_GAIN_CURVE_1_get_gain_curve_step0(data)                  ((0x07000000&(data))>>24)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_get_gain_curve_step1(data)                  ((0x00070000&(data))>>16)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_get_gain_curve_gain0(data)                  ((0x00001F00&(data))>>8)
#define  SCALEUP_DM_USM_GAIN_CURVE_1_get_gain_curve_gain1(data)                  (0x0000001F&(data))

#define  SCALEUP_DM_USM_LIMIT_BLEND_0                                            0x180290D0
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_reg_addr                                   "0xB80290D0"
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_reg                                        0xB80290D0
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_inst_addr                                  "0x0032"
#define  set_SCALEUP_DM_USM_LIMIT_BLEND_0_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_USM_LIMIT_BLEND_0_reg)=data)
#define  get_SCALEUP_DM_USM_LIMIT_BLEND_0_reg                                    (*((volatile unsigned int*)SCALEUP_DM_USM_LIMIT_BLEND_0_reg))
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_en_shift                       (31)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd0_shift                     (8)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd1_shift                     (0)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_en_mask                        (0x80000000)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd0_mask                      (0x0000FF00)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd1_mask                      (0x000000FF)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_en(data)                       (0x80000000&((data)<<31))
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd0(data)                     (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_limit_blend_thd1(data)                     (0x000000FF&(data))
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_get_limit_blend_en(data)                   ((0x80000000&(data))>>31)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_get_limit_blend_thd0(data)                 ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_USM_LIMIT_BLEND_0_get_limit_blend_thd1(data)                 (0x000000FF&(data))

#define  SCALEUP_DM_USM_LIMIT_BLEND_1                                            0x180290D4
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_reg_addr                                   "0xB80290D4"
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_reg                                        0xB80290D4
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_inst_addr                                  "0x0033"
#define  set_SCALEUP_DM_USM_LIMIT_BLEND_1_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_USM_LIMIT_BLEND_1_reg)=data)
#define  get_SCALEUP_DM_USM_LIMIT_BLEND_1_reg                                    (*((volatile unsigned int*)SCALEUP_DM_USM_LIMIT_BLEND_1_reg))
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_step_shift                     (16)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight0_shift                  (8)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight1_shift                  (0)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_step_mask                      (0x00070000)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight0_mask                   (0x00001F00)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight1_mask                   (0x0000001F)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_step(data)                     (0x00070000&((data)<<16))
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight0(data)                  (0x00001F00&((data)<<8))
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_limit_blend_weight1(data)                  (0x0000001F&(data))
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_get_limit_blend_step(data)                 ((0x00070000&(data))>>16)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_get_limit_blend_weight0(data)              ((0x00001F00&(data))>>8)
#define  SCALEUP_DM_USM_LIMIT_BLEND_1_get_limit_blend_weight1(data)              (0x0000001F&(data))

#define  SCALEUP_DM_USM_HLPF_COEF                                                0x180290D8
#define  SCALEUP_DM_USM_HLPF_COEF_reg_addr                                       "0xB80290D8"
#define  SCALEUP_DM_USM_HLPF_COEF_reg                                            0xB80290D8
#define  SCALEUP_DM_USM_HLPF_COEF_inst_addr                                      "0x0034"
#define  set_SCALEUP_DM_USM_HLPF_COEF_reg(data)                                  (*((volatile unsigned int*)SCALEUP_DM_USM_HLPF_COEF_reg)=data)
#define  get_SCALEUP_DM_USM_HLPF_COEF_reg                                        (*((volatile unsigned int*)SCALEUP_DM_USM_HLPF_COEF_reg))
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c3_shift                              (12)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c2_shift                              (8)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c1_shift                              (4)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c0_shift                              (0)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c3_mask                               (0x0003F000)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c2_mask                               (0x00000F00)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c1_mask                               (0x000000F0)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c0_mask                               (0x0000000F)
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c3(data)                              (0x0003F000&((data)<<12))
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c2(data)                              (0x00000F00&((data)<<8))
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c1(data)                              (0x000000F0&((data)<<4))
#define  SCALEUP_DM_USM_HLPF_COEF_usm_hlpf_c0(data)                              (0x0000000F&(data))
#define  SCALEUP_DM_USM_HLPF_COEF_get_usm_hlpf_c3(data)                          ((0x0003F000&(data))>>12)
#define  SCALEUP_DM_USM_HLPF_COEF_get_usm_hlpf_c2(data)                          ((0x00000F00&(data))>>8)
#define  SCALEUP_DM_USM_HLPF_COEF_get_usm_hlpf_c1(data)                          ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_USM_HLPF_COEF_get_usm_hlpf_c0(data)                          (0x0000000F&(data))

#define  SCALEUP_DM_UZU_V6CTRL                                                   0x180290E0
#define  SCALEUP_DM_UZU_V6CTRL_reg_addr                                          "0xB80290E0"
#define  SCALEUP_DM_UZU_V6CTRL_reg                                               0xB80290E0
#define  SCALEUP_DM_UZU_V6CTRL_inst_addr                                         "0x0035"
#define  set_SCALEUP_DM_UZU_V6CTRL_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_V6CTRL_reg)=data)
#define  get_SCALEUP_DM_UZU_V6CTRL_reg                                           (*((volatile unsigned int*)SCALEUP_DM_UZU_V6CTRL_reg))
#define  SCALEUP_DM_UZU_V6CTRL_dummy_31_4_shift                                  (4)
#define  SCALEUP_DM_UZU_V6CTRL_v6tap_table_sel_shift                             (2)
#define  SCALEUP_DM_UZU_V6CTRL_ver_mode_sel_shift                                (0)
#define  SCALEUP_DM_UZU_V6CTRL_dummy_31_4_mask                                   (0xFFFFFFF0)
#define  SCALEUP_DM_UZU_V6CTRL_v6tap_table_sel_mask                              (0x0000000C)
#define  SCALEUP_DM_UZU_V6CTRL_ver_mode_sel_mask                                 (0x00000003)
#define  SCALEUP_DM_UZU_V6CTRL_dummy_31_4(data)                                  (0xFFFFFFF0&((data)<<4))
#define  SCALEUP_DM_UZU_V6CTRL_v6tap_table_sel(data)                             (0x0000000C&((data)<<2))
#define  SCALEUP_DM_UZU_V6CTRL_ver_mode_sel(data)                                (0x00000003&(data))
#define  SCALEUP_DM_UZU_V6CTRL_get_dummy_31_4(data)                              ((0xFFFFFFF0&(data))>>4)
#define  SCALEUP_DM_UZU_V6CTRL_get_v6tap_table_sel(data)                         ((0x0000000C&(data))>>2)
#define  SCALEUP_DM_UZU_V6CTRL_get_ver_mode_sel(data)                            (0x00000003&(data))

#define  SCALEUP_DM_UZU_AdaptV6CTRL                                              0x180290E4
#define  SCALEUP_DM_UZU_AdaptV6CTRL_reg_addr                                     "0xB80290E4"
#define  SCALEUP_DM_UZU_AdaptV6CTRL_reg                                          0xB80290E4
#define  SCALEUP_DM_UZU_AdaptV6CTRL_inst_addr                                    "0x0036"
#define  set_SCALEUP_DM_UZU_AdaptV6CTRL_reg(data)                                (*((volatile unsigned int*)SCALEUP_DM_UZU_AdaptV6CTRL_reg)=data)
#define  get_SCALEUP_DM_UZU_AdaptV6CTRL_reg                                      (*((volatile unsigned int*)SCALEUP_DM_UZU_AdaptV6CTRL_reg))
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_upbnd_shift                          (24)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec3_shift                           (16)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec2_shift                           (8)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec1_shift                           (0)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_upbnd_mask                           (0xFF000000)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec3_mask                            (0x00FF0000)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec2_mask                            (0x0000FF00)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec1_mask                            (0x000000FF)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_upbnd(data)                          (0xFF000000&((data)<<24))
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec3(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec2(data)                           (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZU_AdaptV6CTRL_adaptv6_sec1(data)                           (0x000000FF&(data))
#define  SCALEUP_DM_UZU_AdaptV6CTRL_get_adaptv6_upbnd(data)                      ((0xFF000000&(data))>>24)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_get_adaptv6_sec3(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_get_adaptv6_sec2(data)                       ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZU_AdaptV6CTRL_get_adaptv6_sec1(data)                       (0x000000FF&(data))

#define  SCALEUP_DM_UZU_Initial_Value_left                                       0x180290E8
#define  SCALEUP_DM_UZU_Initial_Value_left_reg_addr                              "0xB80290E8"
#define  SCALEUP_DM_UZU_Initial_Value_left_reg                                   0xB80290E8
#define  SCALEUP_DM_UZU_Initial_Value_left_inst_addr                             "0x0037"
#define  set_SCALEUP_DM_UZU_Initial_Value_left_reg(data)                         (*((volatile unsigned int*)SCALEUP_DM_UZU_Initial_Value_left_reg)=data)
#define  get_SCALEUP_DM_UZU_Initial_Value_left_reg                               (*((volatile unsigned int*)SCALEUP_DM_UZU_Initial_Value_left_reg))
#define  SCALEUP_DM_UZU_Initial_Value_left_hor_ini_l_shift                       (8)
#define  SCALEUP_DM_UZU_Initial_Value_left_ver_ini_l_shift                       (0)
#define  SCALEUP_DM_UZU_Initial_Value_left_hor_ini_l_mask                        (0x0000FF00)
#define  SCALEUP_DM_UZU_Initial_Value_left_ver_ini_l_mask                        (0x000000FF)
#define  SCALEUP_DM_UZU_Initial_Value_left_hor_ini_l(data)                       (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_UZU_Initial_Value_left_ver_ini_l(data)                       (0x000000FF&(data))
#define  SCALEUP_DM_UZU_Initial_Value_left_get_hor_ini_l(data)                   ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_UZU_Initial_Value_left_get_ver_ini_l(data)                   (0x000000FF&(data))

#define  SCALEUP_DM_UZU_DB_CTRL                                                  0x180290F0
#define  SCALEUP_DM_UZU_DB_CTRL_reg_addr                                         "0xB80290F0"
#define  SCALEUP_DM_UZU_DB_CTRL_reg                                              0xB80290F0
#define  SCALEUP_DM_UZU_DB_CTRL_inst_addr                                        "0x0038"
#define  set_SCALEUP_DM_UZU_DB_CTRL_reg(data)                                    (*((volatile unsigned int*)SCALEUP_DM_UZU_DB_CTRL_reg)=data)
#define  get_SCALEUP_DM_UZU_DB_CTRL_reg                                          (*((volatile unsigned int*)SCALEUP_DM_UZU_DB_CTRL_reg))
#define  SCALEUP_DM_UZU_DB_CTRL_db_write_hold_cnt_shift                          (4)
#define  SCALEUP_DM_UZU_DB_CTRL_db_en_shift                                      (2)
#define  SCALEUP_DM_UZU_DB_CTRL_db_read_level_shift                              (1)
#define  SCALEUP_DM_UZU_DB_CTRL_db_apply_shift                                   (0)
#define  SCALEUP_DM_UZU_DB_CTRL_db_write_hold_cnt_mask                           (0x000000F0)
#define  SCALEUP_DM_UZU_DB_CTRL_db_en_mask                                       (0x00000004)
#define  SCALEUP_DM_UZU_DB_CTRL_db_read_level_mask                               (0x00000002)
#define  SCALEUP_DM_UZU_DB_CTRL_db_apply_mask                                    (0x00000001)
#define  SCALEUP_DM_UZU_DB_CTRL_db_write_hold_cnt(data)                          (0x000000F0&((data)<<4))
#define  SCALEUP_DM_UZU_DB_CTRL_db_en(data)                                      (0x00000004&((data)<<2))
#define  SCALEUP_DM_UZU_DB_CTRL_db_read_level(data)                              (0x00000002&((data)<<1))
#define  SCALEUP_DM_UZU_DB_CTRL_db_apply(data)                                   (0x00000001&(data))
#define  SCALEUP_DM_UZU_DB_CTRL_get_db_write_hold_cnt(data)                      ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_UZU_DB_CTRL_get_db_en(data)                                  ((0x00000004&(data))>>2)
#define  SCALEUP_DM_UZU_DB_CTRL_get_db_read_level(data)                          ((0x00000002&(data))>>1)
#define  SCALEUP_DM_UZU_DB_CTRL_get_db_apply(data)                               (0x00000001&(data))

#define  SCALEUP_DM_UZU_WCLR                                                     0x180290F4
#define  SCALEUP_DM_UZU_WCLR_reg_addr                                            "0xB80290F4"
#define  SCALEUP_DM_UZU_WCLR_reg                                                 0xB80290F4
#define  SCALEUP_DM_UZU_WCLR_inst_addr                                           "0x0039"
#define  set_SCALEUP_DM_UZU_WCLR_reg(data)                                       (*((volatile unsigned int*)SCALEUP_DM_UZU_WCLR_reg)=data)
#define  get_SCALEUP_DM_UZU_WCLR_reg                                             (*((volatile unsigned int*)SCALEUP_DM_UZU_WCLR_reg))
#define  SCALEUP_DM_UZU_WCLR_buff_unf_shift                                      (0)
#define  SCALEUP_DM_UZU_WCLR_buff_unf_mask                                       (0x00000001)
#define  SCALEUP_DM_UZU_WCLR_buff_unf(data)                                      (0x00000001&(data))
#define  SCALEUP_DM_UZU_WCLR_get_buff_unf(data)                                  (0x00000001&(data))

#define  SCALEUP_LEFT_3D_PTG_Ctrl3                                               0x18029100
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_reg_addr                                      "0xB8029100"
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_reg                                           0xB8029100
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_inst_addr                                     "0x003A"
#define  set_SCALEUP_LEFT_3D_PTG_Ctrl3_reg(data)                                 (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl3_reg)=data)
#define  get_SCALEUP_LEFT_3D_PTG_Ctrl3_reg                                       (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl3_reg))
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_ydi_shift                                (16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_udi_shift                                (8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_vdi_shift                                (0)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_ydi_mask                                 (0x00FF0000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_udi_mask                                 (0x0000FF00)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_vdi_mask                                 (0x000000FF)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_ydi(data)                                (0x00FF0000&((data)<<16))
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_udi(data)                                (0x0000FF00&((data)<<8))
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_left_vdi(data)                                (0x000000FF&(data))
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_get_left_ydi(data)                            ((0x00FF0000&(data))>>16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_get_left_udi(data)                            ((0x0000FF00&(data))>>8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl3_get_left_vdi(data)                            (0x000000FF&(data))

#define  SCALEUP_LEFT_3D_PTG_Ctrl4                                               0x18029104
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_reg_addr                                      "0xB8029104"
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_reg                                           0xB8029104
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_inst_addr                                     "0x003B"
#define  set_SCALEUP_LEFT_3D_PTG_Ctrl4_reg(data)                                 (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl4_reg)=data)
#define  get_SCALEUP_LEFT_3D_PTG_Ctrl4_reg                                       (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl4_reg))
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_saddr_shift                            (24)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_saddr_shift                            (16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_limit_shift                            (8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_limit_shift                            (0)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_saddr_mask                             (0xFF000000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_saddr_mask                             (0x00FF0000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_limit_mask                             (0x0000FF00)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_limit_mask                             (0x000000FF)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_saddr(data)                            (0xFF000000&((data)<<24))
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_saddr(data)                            (0x00FF0000&((data)<<16))
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_h_limit(data)                            (0x0000FF00&((data)<<8))
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_left_v_limit(data)                            (0x000000FF&(data))
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_get_left_h_saddr(data)                        ((0xFF000000&(data))>>24)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_get_left_v_saddr(data)                        ((0x00FF0000&(data))>>16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_get_left_h_limit(data)                        ((0x0000FF00&(data))>>8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl4_get_left_v_limit(data)                        (0x000000FF&(data))

#define  SCALEUP_LEFT_3D_PTG_Ctrl5                                               0x18029108
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_reg_addr                                      "0xB8029108"
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_reg                                           0xB8029108
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_inst_addr                                     "0x003C"
#define  set_SCALEUP_LEFT_3D_PTG_Ctrl5_reg(data)                                 (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl5_reg)=data)
#define  get_SCALEUP_LEFT_3D_PTG_Ctrl5_reg                                       (*((volatile unsigned int*)SCALEUP_LEFT_3D_PTG_Ctrl5_reg))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hsize_shift                              (24)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vsize_shift                              (16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_see_sadr_only_l_shift                         (15)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hstep_shift                              (8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vstep_shift                              (0)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hsize_mask                               (0xFF000000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vsize_mask                               (0x00FF0000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_see_sadr_only_l_mask                          (0x00008000)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hstep_mask                               (0x00003F00)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vstep_mask                               (0x0000003F)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hsize(data)                              (0xFF000000&((data)<<24))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vsize(data)                              (0x00FF0000&((data)<<16))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_see_sadr_only_l(data)                         (0x00008000&((data)<<15))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_hstep(data)                              (0x00003F00&((data)<<8))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_left_vstep(data)                              (0x0000003F&(data))
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_get_left_hsize(data)                          ((0xFF000000&(data))>>24)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_get_left_vsize(data)                          ((0x00FF0000&(data))>>16)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_get_see_sadr_only_l(data)                     ((0x00008000&(data))>>15)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_get_left_hstep(data)                          ((0x00003F00&(data))>>8)
#define  SCALEUP_LEFT_3D_PTG_Ctrl5_get_left_vstep(data)                          (0x0000003F&(data))

#define  SCALEUP_RIGHT_3D_PTG_Ctrl1                                              0x1802910C
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_reg_addr                                     "0xB802910C"
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_reg                                          0xB802910C
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_inst_addr                                    "0x003D"
#define  set_SCALEUP_RIGHT_3D_PTG_Ctrl1_reg(data)                                (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl1_reg)=data)
#define  get_SCALEUP_RIGHT_3D_PTG_Ctrl1_reg                                      (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl1_reg))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_ydi_shift                              (16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_udi_shift                              (8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_vdi_shift                              (0)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_ydi_mask                               (0x00FF0000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_udi_mask                               (0x0000FF00)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_vdi_mask                               (0x000000FF)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_ydi(data)                              (0x00FF0000&((data)<<16))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_udi(data)                              (0x0000FF00&((data)<<8))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_right_vdi(data)                              (0x000000FF&(data))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_get_right_ydi(data)                          ((0x00FF0000&(data))>>16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_get_right_udi(data)                          ((0x0000FF00&(data))>>8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl1_get_right_vdi(data)                          (0x000000FF&(data))

#define  SCALEUP_RIGHT_3D_PTG_Ctrl2                                              0x18029110
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_reg_addr                                     "0xB8029110"
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_reg                                          0xB8029110
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_inst_addr                                    "0x003E"
#define  set_SCALEUP_RIGHT_3D_PTG_Ctrl2_reg(data)                                (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl2_reg)=data)
#define  get_SCALEUP_RIGHT_3D_PTG_Ctrl2_reg                                      (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl2_reg))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_saddr_shift                          (24)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_saddr_shift                          (16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_limit_shift                          (8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_limit_shift                          (0)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_saddr_mask                           (0xFF000000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_saddr_mask                           (0x00FF0000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_limit_mask                           (0x0000FF00)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_limit_mask                           (0x000000FF)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_saddr(data)                          (0xFF000000&((data)<<24))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_saddr(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_h_limit(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_right_v_limit(data)                          (0x000000FF&(data))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_get_right_h_saddr(data)                      ((0xFF000000&(data))>>24)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_get_right_v_saddr(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_get_right_h_limit(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl2_get_right_v_limit(data)                      (0x000000FF&(data))

#define  SCALEUP_RIGHT_3D_PTG_Ctrl3                                              0x18029114
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_reg_addr                                     "0xB8029114"
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_reg                                          0xB8029114
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_inst_addr                                    "0x003F"
#define  set_SCALEUP_RIGHT_3D_PTG_Ctrl3_reg(data)                                (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl3_reg)=data)
#define  get_SCALEUP_RIGHT_3D_PTG_Ctrl3_reg                                      (*((volatile unsigned int*)SCALEUP_RIGHT_3D_PTG_Ctrl3_reg))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hsize_shift                            (24)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vsize_shift                            (16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_see_sadr_only_r_shift                        (15)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hstep_shift                            (8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vstep_shift                            (0)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hsize_mask                             (0xFF000000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vsize_mask                             (0x00FF0000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_see_sadr_only_r_mask                         (0x00008000)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hstep_mask                             (0x00003F00)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vstep_mask                             (0x0000003F)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hsize(data)                            (0xFF000000&((data)<<24))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vsize(data)                            (0x00FF0000&((data)<<16))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_see_sadr_only_r(data)                        (0x00008000&((data)<<15))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_hstep(data)                            (0x00003F00&((data)<<8))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_right_vstep(data)                            (0x0000003F&(data))
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_get_right_hsize(data)                        ((0xFF000000&(data))>>24)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_get_right_vsize(data)                        ((0x00FF0000&(data))>>16)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_get_see_sadr_only_r(data)                    ((0x00008000&(data))>>15)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_get_right_hstep(data)                        ((0x00003F00&(data))>>8)
#define  SCALEUP_RIGHT_3D_PTG_Ctrl3_get_right_vstep(data)                        (0x0000003F&(data))

#define  SCALEUP_PTG_3D_Ctr1                                                     0x18029118
#define  SCALEUP_PTG_3D_Ctr1_reg_addr                                            "0xB8029118"
#define  SCALEUP_PTG_3D_Ctr1_reg                                                 0xB8029118
#define  SCALEUP_PTG_3D_Ctr1_inst_addr                                           "0x0040"
#define  set_SCALEUP_PTG_3D_Ctr1_reg(data)                                       (*((volatile unsigned int*)SCALEUP_PTG_3D_Ctr1_reg)=data)
#define  get_SCALEUP_PTG_3D_Ctr1_reg                                             (*((volatile unsigned int*)SCALEUP_PTG_3D_Ctr1_reg))
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_ydi_shift                                    (16)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_udi_shift                                    (8)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_vdi_shift                                    (0)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_ydi_mask                                     (0x00FF0000)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_udi_mask                                     (0x0000FF00)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_vdi_mask                                     (0x000000FF)
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_ydi(data)                                    (0x00FF0000&((data)<<16))
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_udi(data)                                    (0x0000FF00&((data)<<8))
#define  SCALEUP_PTG_3D_Ctr1_ptg_bg_vdi(data)                                    (0x000000FF&(data))
#define  SCALEUP_PTG_3D_Ctr1_get_ptg_bg_ydi(data)                                ((0x00FF0000&(data))>>16)
#define  SCALEUP_PTG_3D_Ctr1_get_ptg_bg_udi(data)                                ((0x0000FF00&(data))>>8)
#define  SCALEUP_PTG_3D_Ctr1_get_ptg_bg_vdi(data)                                (0x000000FF&(data))

#define  SCALEUP_DM_DIR_UZU_Ctrl                                                 0x18029130
#define  SCALEUP_DM_DIR_UZU_Ctrl_reg_addr                                        "0xB8029130"
#define  SCALEUP_DM_DIR_UZU_Ctrl_reg                                             0xB8029130
#define  SCALEUP_DM_DIR_UZU_Ctrl_inst_addr                                       "0x0041"
#define  set_SCALEUP_DM_DIR_UZU_Ctrl_reg(data)                                   (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_Ctrl_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_Ctrl_reg                                         (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_Ctrl_reg))
#define  SCALEUP_DM_DIR_UZU_Ctrl_directionalscale_en_shift                       (31)
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_vlpf_en_shift                                (28)
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_hlpf_en_shift                                (27)
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_mode_shift                                   (20)
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_magfilter_shift                              (16)
#define  SCALEUP_DM_DIR_UZU_Ctrl_mag_ang_lpf_ratio_shift                         (12)
#define  SCALEUP_DM_DIR_UZU_Ctrl_dummy_11_0_shift                                (0)
#define  SCALEUP_DM_DIR_UZU_Ctrl_directionalscale_en_mask                        (0x80000000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_vlpf_en_mask                                 (0x10000000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_hlpf_en_mask                                 (0x08000000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_mode_mask                                    (0x00F00000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_magfilter_mask                               (0x000F0000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_mag_ang_lpf_ratio_mask                          (0x0000F000)
#define  SCALEUP_DM_DIR_UZU_Ctrl_dummy_11_0_mask                                 (0x00000FFF)
#define  SCALEUP_DM_DIR_UZU_Ctrl_directionalscale_en(data)                       (0x80000000&((data)<<31))
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_vlpf_en(data)                                (0x10000000&((data)<<28))
#define  SCALEUP_DM_DIR_UZU_Ctrl_ds_hlpf_en(data)                                (0x08000000&((data)<<27))
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_mode(data)                                   (0x00F00000&((data)<<20))
#define  SCALEUP_DM_DIR_UZU_Ctrl_db_magfilter(data)                              (0x000F0000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_Ctrl_mag_ang_lpf_ratio(data)                         (0x0000F000&((data)<<12))
#define  SCALEUP_DM_DIR_UZU_Ctrl_dummy_11_0(data)                                (0x00000FFF&(data))
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_directionalscale_en(data)                   ((0x80000000&(data))>>31)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_ds_vlpf_en(data)                            ((0x10000000&(data))>>28)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_ds_hlpf_en(data)                            ((0x08000000&(data))>>27)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_db_mode(data)                               ((0x00F00000&(data))>>20)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_db_magfilter(data)                          ((0x000F0000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_mag_ang_lpf_ratio(data)                     ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_DIR_UZU_Ctrl_get_dummy_11_0(data)                            (0x00000FFF&(data))

#define  SCALEUP_DM_DIR_UZU_TransAng1                                            0x18029134
#define  SCALEUP_DM_DIR_UZU_TransAng1_reg_addr                                   "0xB8029134"
#define  SCALEUP_DM_DIR_UZU_TransAng1_reg                                        0xB8029134
#define  SCALEUP_DM_DIR_UZU_TransAng1_inst_addr                                  "0x0042"
#define  set_SCALEUP_DM_DIR_UZU_TransAng1_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_TransAng1_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_TransAng1_reg                                    (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_TransAng1_reg))
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec3_shift                        (24)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec2_shift                        (16)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec1_shift                        (8)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec0_shift                        (0)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec3_mask                         (0x7F000000)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec2_mask                         (0x003F0000)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec1_mask                         (0x00003F00)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec0_mask                         (0x0000003F)
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec3(data)                        (0x7F000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec2(data)                        (0x003F0000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec1(data)                        (0x00003F00&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_TransAng1_transang_sec0(data)                        (0x0000003F&(data))
#define  SCALEUP_DM_DIR_UZU_TransAng1_get_transang_sec3(data)                    ((0x7F000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_TransAng1_get_transang_sec2(data)                    ((0x003F0000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_TransAng1_get_transang_sec1(data)                    ((0x00003F00&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_TransAng1_get_transang_sec0(data)                    (0x0000003F&(data))

#define  SCALEUP_DM_DIR_UZU_TransAng2                                            0x18029138
#define  SCALEUP_DM_DIR_UZU_TransAng2_reg_addr                                   "0xB8029138"
#define  SCALEUP_DM_DIR_UZU_TransAng2_reg                                        0xB8029138
#define  SCALEUP_DM_DIR_UZU_TransAng2_inst_addr                                  "0x0043"
#define  set_SCALEUP_DM_DIR_UZU_TransAng2_reg(data)                              (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_TransAng2_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_TransAng2_reg                                    (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_TransAng2_reg))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_sec4_shift                        (24)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step4_shift                       (16)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step3_shift                       (12)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step2_shift                       (8)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step1_shift                       (4)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step0_shift                       (0)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_sec4_mask                         (0x7F000000)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step4_mask                        (0x000F0000)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step3_mask                        (0x0000F000)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step2_mask                        (0x00000F00)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step1_mask                        (0x000000F0)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step0_mask                        (0x0000000F)
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_sec4(data)                        (0x7F000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step4(data)                       (0x000F0000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step3(data)                       (0x0000F000&((data)<<12))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step2(data)                       (0x00000F00&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step1(data)                       (0x000000F0&((data)<<4))
#define  SCALEUP_DM_DIR_UZU_TransAng2_transang_step0(data)                       (0x0000000F&(data))
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_sec4(data)                    ((0x7F000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_step4(data)                   ((0x000F0000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_step3(data)                   ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_step2(data)                   ((0x00000F00&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_step1(data)                   ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_DIR_UZU_TransAng2_get_transang_step0(data)                   (0x0000000F&(data))

#define  SCALEUP_DM_DIR_UZU_AngMagScore                                          0x18029140
#define  SCALEUP_DM_DIR_UZU_AngMagScore_reg_addr                                 "0xB8029140"
#define  SCALEUP_DM_DIR_UZU_AngMagScore_reg                                      0xB8029140
#define  SCALEUP_DM_DIR_UZU_AngMagScore_inst_addr                                "0x0044"
#define  set_SCALEUP_DM_DIR_UZU_AngMagScore_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_AngMagScore_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_AngMagScore_reg                                  (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_AngMagScore_reg))
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_lowbnd_shift                     (24)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_step_shift                       (16)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_lowbnd_shift                         (8)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_step_shift                           (0)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_lowbnd_mask                      (0x3F000000)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_step_mask                        (0x00070000)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_lowbnd_mask                          (0x0000FF00)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_step_mask                            (0x00000007)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_lowbnd(data)                     (0x3F000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_AngMagScore_angdiff_step(data)                       (0x00070000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_lowbnd(data)                         (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_AngMagScore_mag_step(data)                           (0x00000007&(data))
#define  SCALEUP_DM_DIR_UZU_AngMagScore_get_angdiff_lowbnd(data)                 ((0x3F000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_get_angdiff_step(data)                   ((0x00070000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_get_mag_lowbnd(data)                     ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_AngMagScore_get_mag_step(data)                       (0x00000007&(data))

#define  SCALEUP_DM_DIR_UZU_OnePixelDetect                                       0x18029144
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_reg_addr                              "0xB8029144"
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_reg                                   0xB8029144
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_inst_addr                             "0x0045"
#define  set_SCALEUP_DM_DIR_UZU_OnePixelDetect_reg(data)                         (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_OnePixelDetect_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_OnePixelDetect_reg                               (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_OnePixelDetect_reg))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_en_shift                        (28)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_centerdiffthd_shift             (24)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_sidediffthd_shift               (20)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_diffstep_shift                  (16)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_lowbnd_shift                    (8)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_step_shift                      (4)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_en_mask                         (0x10000000)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_centerdiffthd_mask              (0x0F000000)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_sidediffthd_mask                (0x00F00000)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_diffstep_mask                   (0x00070000)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_lowbnd_mask                     (0x0000FF00)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_step_mask                       (0x00000070)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_en(data)                        (0x10000000&((data)<<28))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_centerdiffthd(data)             (0x0F000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_sidediffthd(data)               (0x00F00000&((data)<<20))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_diffstep(data)                  (0x00070000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_lowbnd(data)                    (0x0000FF00&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_onepx_step(data)                      (0x00000070&((data)<<4))
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_en(data)                    ((0x10000000&(data))>>28)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_centerdiffthd(data)         ((0x0F000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_sidediffthd(data)           ((0x00F00000&(data))>>20)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_diffstep(data)              ((0x00070000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_lowbnd(data)                ((0x0000FF00&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_OnePixelDetect_get_onepx_step(data)                  ((0x00000070&(data))>>4)

#define  SCALEUP_DM_DIR_UZU_Conf                                                 0x18029148
#define  SCALEUP_DM_DIR_UZU_Conf_reg_addr                                        "0xB8029148"
#define  SCALEUP_DM_DIR_UZU_Conf_reg                                             0xB8029148
#define  SCALEUP_DM_DIR_UZU_Conf_inst_addr                                       "0x0046"
#define  set_SCALEUP_DM_DIR_UZU_Conf_reg(data)                                   (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_Conf_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_Conf_reg                                         (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_Conf_reg))
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_lowbnd2_shift                           (24)
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_step2_shift                             (20)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_step_shift                                 (13)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_offset_shift                               (8)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_lowbnd_shift                               (0)
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_lowbnd2_mask                            (0x3F000000)
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_step2_mask                              (0x00700000)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_step_mask                                  (0x0000E000)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_offset_mask                                (0x00001F00)
#define  SCALEUP_DM_DIR_UZU_Conf_conf_lowbnd_mask                                (0x000000FF)
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_lowbnd2(data)                           (0x3F000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_Conf_angdiff_step2(data)                             (0x00700000&((data)<<20))
#define  SCALEUP_DM_DIR_UZU_Conf_conf_step(data)                                 (0x0000E000&((data)<<13))
#define  SCALEUP_DM_DIR_UZU_Conf_conf_offset(data)                               (0x00001F00&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_Conf_conf_lowbnd(data)                               (0x000000FF&(data))
#define  SCALEUP_DM_DIR_UZU_Conf_get_angdiff_lowbnd2(data)                       ((0x3F000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_Conf_get_angdiff_step2(data)                         ((0x00700000&(data))>>20)
#define  SCALEUP_DM_DIR_UZU_Conf_get_conf_step(data)                             ((0x0000E000&(data))>>13)
#define  SCALEUP_DM_DIR_UZU_Conf_get_conf_offset(data)                           ((0x00001F00&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_Conf_get_conf_lowbnd(data)                           (0x000000FF&(data))

#define  SCALEUP_DM_DIR_UZU_AngleCheck                                           0x1802914C
#define  SCALEUP_DM_DIR_UZU_AngleCheck_reg_addr                                  "0xB802914C"
#define  SCALEUP_DM_DIR_UZU_AngleCheck_reg                                       0xB802914C
#define  SCALEUP_DM_DIR_UZU_AngleCheck_inst_addr                                 "0x0047"
#define  set_SCALEUP_DM_DIR_UZU_AngleCheck_reg(data)                             (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_AngleCheck_reg)=data)
#define  get_SCALEUP_DM_DIR_UZU_AngleCheck_reg                                   (*((volatile unsigned int*)SCALEUP_DM_DIR_UZU_AngleCheck_reg))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angrange_shift                    (28)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_en_shift                          (27)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angstep_shift                     (24)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffstep_shift                    (21)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffrange_shift                   (16)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angrange_shift                    (12)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_en_shift                          (11)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angstep_shift                     (8)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffstep_shift                    (5)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffrange_shift                   (0)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angrange_mask                     (0xF0000000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_en_mask                           (0x08000000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angstep_mask                      (0x07000000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffstep_mask                     (0x00E00000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffrange_mask                    (0x001F0000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angrange_mask                     (0x0000F000)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_en_mask                           (0x00000800)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angstep_mask                      (0x00000700)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffstep_mask                     (0x000000E0)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffrange_mask                    (0x0000001F)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angrange(data)                    (0xF0000000&((data)<<28))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_en(data)                          (0x08000000&((data)<<27))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_angstep(data)                     (0x07000000&((data)<<24))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffstep(data)                    (0x00E00000&((data)<<21))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkhv_diffrange(data)                   (0x001F0000&((data)<<16))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angrange(data)                    (0x0000F000&((data)<<12))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_en(data)                          (0x00000800&((data)<<11))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_angstep(data)                     (0x00000700&((data)<<8))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffstep(data)                    (0x000000E0&((data)<<5))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_checkpn_diffrange(data)                   (0x0000001F&(data))
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkhv_angrange(data)                ((0xF0000000&(data))>>28)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkhv_en(data)                      ((0x08000000&(data))>>27)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkhv_angstep(data)                 ((0x07000000&(data))>>24)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkhv_diffstep(data)                ((0x00E00000&(data))>>21)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkhv_diffrange(data)               ((0x001F0000&(data))>>16)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkpn_angrange(data)                ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkpn_en(data)                      ((0x00000800&(data))>>11)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkpn_angstep(data)                 ((0x00000700&(data))>>8)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkpn_diffstep(data)                ((0x000000E0&(data))>>5)
#define  SCALEUP_DM_DIR_UZU_AngleCheck_get_checkpn_diffrange(data)               (0x0000001F&(data))

#define  SCALEUP_DM_UZU_Bist_0                                                   0x18029180
#define  SCALEUP_DM_UZU_Bist_0_reg_addr                                          "0xB8029180"
#define  SCALEUP_DM_UZU_Bist_0_reg                                               0xB8029180
#define  SCALEUP_DM_UZU_Bist_0_inst_addr                                         "0x0048"
#define  set_SCALEUP_DM_UZU_Bist_0_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_0_reg)=data)
#define  get_SCALEUP_DM_UZU_Bist_0_reg                                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_0_reg))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_11_shift                            (27)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_10_shift                            (26)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_9_shift                             (25)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_8_shift                             (24)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_7_shift                             (23)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_6_shift                             (22)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_5_shift                             (21)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_4_shift                             (20)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_3_shift                             (19)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_2_shift                             (18)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_1_shift                             (17)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_0_shift                             (16)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_11_shift                                (11)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_10_shift                                (10)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_9_shift                                 (9)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_8_shift                                 (8)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_7_shift                                 (7)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_6_shift                                 (6)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_5_shift                                 (5)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_4_shift                                 (4)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_3_shift                                 (3)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_2_shift                                 (2)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_1_shift                                 (1)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_0_shift                                 (0)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_11_mask                             (0x08000000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_10_mask                             (0x04000000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_9_mask                              (0x02000000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_8_mask                              (0x01000000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_7_mask                              (0x00800000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_6_mask                              (0x00400000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_5_mask                              (0x00200000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_4_mask                              (0x00100000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_3_mask                              (0x00080000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_2_mask                              (0x00040000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_1_mask                              (0x00020000)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_0_mask                              (0x00010000)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_11_mask                                 (0x00000800)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_10_mask                                 (0x00000400)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_9_mask                                  (0x00000200)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_8_mask                                  (0x00000100)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_7_mask                                  (0x00000080)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_6_mask                                  (0x00000040)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_5_mask                                  (0x00000020)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_4_mask                                  (0x00000010)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_3_mask                                  (0x00000008)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_2_mask                                  (0x00000004)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_1_mask                                  (0x00000002)
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_0_mask                                  (0x00000001)
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_11(data)                            (0x08000000&((data)<<27))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_10(data)                            (0x04000000&((data)<<26))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_9(data)                             (0x02000000&((data)<<25))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_8(data)                             (0x01000000&((data)<<24))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_7(data)                             (0x00800000&((data)<<23))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_6(data)                             (0x00400000&((data)<<22))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_5(data)                             (0x00200000&((data)<<21))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_4(data)                             (0x00100000&((data)<<20))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_3(data)                             (0x00080000&((data)<<19))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_2(data)                             (0x00040000&((data)<<18))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_1(data)                             (0x00020000&((data)<<17))
#define  SCALEUP_DM_UZU_Bist_0_drf_bist_fail_0(data)                             (0x00010000&((data)<<16))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_11(data)                                (0x00000800&((data)<<11))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_10(data)                                (0x00000400&((data)<<10))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_9(data)                                 (0x00000200&((data)<<9))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_8(data)                                 (0x00000100&((data)<<8))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_7(data)                                 (0x00000080&((data)<<7))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_6(data)                                 (0x00000040&((data)<<6))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_5(data)                                 (0x00000020&((data)<<5))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_4(data)                                 (0x00000010&((data)<<4))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_3(data)                                 (0x00000008&((data)<<3))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_2(data)                                 (0x00000004&((data)<<2))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_1(data)                                 (0x00000002&((data)<<1))
#define  SCALEUP_DM_UZU_Bist_0_bist_fail_0(data)                                 (0x00000001&(data))
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_11(data)                        ((0x08000000&(data))>>27)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_10(data)                        ((0x04000000&(data))>>26)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_9(data)                         ((0x02000000&(data))>>25)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_8(data)                         ((0x01000000&(data))>>24)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_7(data)                         ((0x00800000&(data))>>23)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_6(data)                         ((0x00400000&(data))>>22)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_5(data)                         ((0x00200000&(data))>>21)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_4(data)                         ((0x00100000&(data))>>20)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_3(data)                         ((0x00080000&(data))>>19)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_2(data)                         ((0x00040000&(data))>>18)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_1(data)                         ((0x00020000&(data))>>17)
#define  SCALEUP_DM_UZU_Bist_0_get_drf_bist_fail_0(data)                         ((0x00010000&(data))>>16)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_11(data)                            ((0x00000800&(data))>>11)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_10(data)                            ((0x00000400&(data))>>10)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_9(data)                             ((0x00000200&(data))>>9)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_8(data)                             ((0x00000100&(data))>>8)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_7(data)                             ((0x00000080&(data))>>7)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_6(data)                             ((0x00000040&(data))>>6)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_5(data)                             ((0x00000020&(data))>>5)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_4(data)                             ((0x00000010&(data))>>4)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_3(data)                             ((0x00000008&(data))>>3)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_2(data)                             ((0x00000004&(data))>>2)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_1(data)                             ((0x00000002&(data))>>1)
#define  SCALEUP_DM_UZU_Bist_0_get_bist_fail_0(data)                             (0x00000001&(data))

#define  SCALEUP_DM_UZU_Bist_2                                                   0x18029184
#define  SCALEUP_DM_UZU_Bist_2_reg_addr                                          "0xB8029184"
#define  SCALEUP_DM_UZU_Bist_2_reg                                               0xB8029184
#define  SCALEUP_DM_UZU_Bist_2_inst_addr                                         "0x0049"
#define  set_SCALEUP_DM_UZU_Bist_2_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_2_reg)=data)
#define  get_SCALEUP_DM_UZU_Bist_2_reg                                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_2_reg))
#define  SCALEUP_DM_UZU_Bist_2_ls_0_shift                                        (16)
#define  SCALEUP_DM_UZU_Bist_2_rme_11_shift                                      (11)
#define  SCALEUP_DM_UZU_Bist_2_rme_10_shift                                      (10)
#define  SCALEUP_DM_UZU_Bist_2_rme_9_shift                                       (9)
#define  SCALEUP_DM_UZU_Bist_2_rme_8_shift                                       (8)
#define  SCALEUP_DM_UZU_Bist_2_rme_7_shift                                       (7)
#define  SCALEUP_DM_UZU_Bist_2_rme_6_shift                                       (6)
#define  SCALEUP_DM_UZU_Bist_2_rme_5_shift                                       (5)
#define  SCALEUP_DM_UZU_Bist_2_rme_4_shift                                       (4)
#define  SCALEUP_DM_UZU_Bist_2_rme_3_shift                                       (3)
#define  SCALEUP_DM_UZU_Bist_2_rme_2_shift                                       (2)
#define  SCALEUP_DM_UZU_Bist_2_rme_1_shift                                       (1)
#define  SCALEUP_DM_UZU_Bist_2_rme_0_shift                                       (0)
#define  SCALEUP_DM_UZU_Bist_2_ls_0_mask                                         (0x00010000)
#define  SCALEUP_DM_UZU_Bist_2_rme_11_mask                                       (0x00000800)
#define  SCALEUP_DM_UZU_Bist_2_rme_10_mask                                       (0x00000400)
#define  SCALEUP_DM_UZU_Bist_2_rme_9_mask                                        (0x00000200)
#define  SCALEUP_DM_UZU_Bist_2_rme_8_mask                                        (0x00000100)
#define  SCALEUP_DM_UZU_Bist_2_rme_7_mask                                        (0x00000080)
#define  SCALEUP_DM_UZU_Bist_2_rme_6_mask                                        (0x00000040)
#define  SCALEUP_DM_UZU_Bist_2_rme_5_mask                                        (0x00000020)
#define  SCALEUP_DM_UZU_Bist_2_rme_4_mask                                        (0x00000010)
#define  SCALEUP_DM_UZU_Bist_2_rme_3_mask                                        (0x00000008)
#define  SCALEUP_DM_UZU_Bist_2_rme_2_mask                                        (0x00000004)
#define  SCALEUP_DM_UZU_Bist_2_rme_1_mask                                        (0x00000002)
#define  SCALEUP_DM_UZU_Bist_2_rme_0_mask                                        (0x00000001)
#define  SCALEUP_DM_UZU_Bist_2_ls_0(data)                                        (0x00010000&((data)<<16))
#define  SCALEUP_DM_UZU_Bist_2_rme_11(data)                                      (0x00000800&((data)<<11))
#define  SCALEUP_DM_UZU_Bist_2_rme_10(data)                                      (0x00000400&((data)<<10))
#define  SCALEUP_DM_UZU_Bist_2_rme_9(data)                                       (0x00000200&((data)<<9))
#define  SCALEUP_DM_UZU_Bist_2_rme_8(data)                                       (0x00000100&((data)<<8))
#define  SCALEUP_DM_UZU_Bist_2_rme_7(data)                                       (0x00000080&((data)<<7))
#define  SCALEUP_DM_UZU_Bist_2_rme_6(data)                                       (0x00000040&((data)<<6))
#define  SCALEUP_DM_UZU_Bist_2_rme_5(data)                                       (0x00000020&((data)<<5))
#define  SCALEUP_DM_UZU_Bist_2_rme_4(data)                                       (0x00000010&((data)<<4))
#define  SCALEUP_DM_UZU_Bist_2_rme_3(data)                                       (0x00000008&((data)<<3))
#define  SCALEUP_DM_UZU_Bist_2_rme_2(data)                                       (0x00000004&((data)<<2))
#define  SCALEUP_DM_UZU_Bist_2_rme_1(data)                                       (0x00000002&((data)<<1))
#define  SCALEUP_DM_UZU_Bist_2_rme_0(data)                                       (0x00000001&(data))
#define  SCALEUP_DM_UZU_Bist_2_get_ls_0(data)                                    ((0x00010000&(data))>>16)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_11(data)                                  ((0x00000800&(data))>>11)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_10(data)                                  ((0x00000400&(data))>>10)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_9(data)                                   ((0x00000200&(data))>>9)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_8(data)                                   ((0x00000100&(data))>>8)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_7(data)                                   ((0x00000080&(data))>>7)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_6(data)                                   ((0x00000040&(data))>>6)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_5(data)                                   ((0x00000020&(data))>>5)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_4(data)                                   ((0x00000010&(data))>>4)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_3(data)                                   ((0x00000008&(data))>>3)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_2(data)                                   ((0x00000004&(data))>>2)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_1(data)                                   ((0x00000002&(data))>>1)
#define  SCALEUP_DM_UZU_Bist_2_get_rme_0(data)                                   (0x00000001&(data))

#define  SCALEUP_DM_UZU_Bist_3                                                   0x18029188
#define  SCALEUP_DM_UZU_Bist_3_reg_addr                                          "0xB8029188"
#define  SCALEUP_DM_UZU_Bist_3_reg                                               0xB8029188
#define  SCALEUP_DM_UZU_Bist_3_inst_addr                                         "0x004A"
#define  set_SCALEUP_DM_UZU_Bist_3_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_3_reg)=data)
#define  get_SCALEUP_DM_UZU_Bist_3_reg                                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_3_reg))
#define  SCALEUP_DM_UZU_Bist_3_rm_7_shift                                        (28)
#define  SCALEUP_DM_UZU_Bist_3_rm_6_shift                                        (24)
#define  SCALEUP_DM_UZU_Bist_3_rm_5_shift                                        (20)
#define  SCALEUP_DM_UZU_Bist_3_rm_4_shift                                        (16)
#define  SCALEUP_DM_UZU_Bist_3_rm_3_shift                                        (12)
#define  SCALEUP_DM_UZU_Bist_3_rm_2_shift                                        (8)
#define  SCALEUP_DM_UZU_Bist_3_rm_1_shift                                        (4)
#define  SCALEUP_DM_UZU_Bist_3_rm_0_shift                                        (0)
#define  SCALEUP_DM_UZU_Bist_3_rm_7_mask                                         (0xF0000000)
#define  SCALEUP_DM_UZU_Bist_3_rm_6_mask                                         (0x0F000000)
#define  SCALEUP_DM_UZU_Bist_3_rm_5_mask                                         (0x00F00000)
#define  SCALEUP_DM_UZU_Bist_3_rm_4_mask                                         (0x000F0000)
#define  SCALEUP_DM_UZU_Bist_3_rm_3_mask                                         (0x0000F000)
#define  SCALEUP_DM_UZU_Bist_3_rm_2_mask                                         (0x00000F00)
#define  SCALEUP_DM_UZU_Bist_3_rm_1_mask                                         (0x000000F0)
#define  SCALEUP_DM_UZU_Bist_3_rm_0_mask                                         (0x0000000F)
#define  SCALEUP_DM_UZU_Bist_3_rm_7(data)                                        (0xF0000000&((data)<<28))
#define  SCALEUP_DM_UZU_Bist_3_rm_6(data)                                        (0x0F000000&((data)<<24))
#define  SCALEUP_DM_UZU_Bist_3_rm_5(data)                                        (0x00F00000&((data)<<20))
#define  SCALEUP_DM_UZU_Bist_3_rm_4(data)                                        (0x000F0000&((data)<<16))
#define  SCALEUP_DM_UZU_Bist_3_rm_3(data)                                        (0x0000F000&((data)<<12))
#define  SCALEUP_DM_UZU_Bist_3_rm_2(data)                                        (0x00000F00&((data)<<8))
#define  SCALEUP_DM_UZU_Bist_3_rm_1(data)                                        (0x000000F0&((data)<<4))
#define  SCALEUP_DM_UZU_Bist_3_rm_0(data)                                        (0x0000000F&(data))
#define  SCALEUP_DM_UZU_Bist_3_get_rm_7(data)                                    ((0xF0000000&(data))>>28)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_6(data)                                    ((0x0F000000&(data))>>24)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_5(data)                                    ((0x00F00000&(data))>>20)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_4(data)                                    ((0x000F0000&(data))>>16)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_3(data)                                    ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_2(data)                                    ((0x00000F00&(data))>>8)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_1(data)                                    ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_UZU_Bist_3_get_rm_0(data)                                    (0x0000000F&(data))

#define  SCALEUP_DM_UZU_Bist_4                                                   0x1802918C
#define  SCALEUP_DM_UZU_Bist_4_reg_addr                                          "0xB802918C"
#define  SCALEUP_DM_UZU_Bist_4_reg                                               0xB802918C
#define  SCALEUP_DM_UZU_Bist_4_inst_addr                                         "0x004B"
#define  set_SCALEUP_DM_UZU_Bist_4_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_4_reg)=data)
#define  get_SCALEUP_DM_UZU_Bist_4_reg                                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Bist_4_reg))
#define  SCALEUP_DM_UZU_Bist_4_rm_11_shift                                       (12)
#define  SCALEUP_DM_UZU_Bist_4_rm_10_shift                                       (8)
#define  SCALEUP_DM_UZU_Bist_4_rm_9_shift                                        (4)
#define  SCALEUP_DM_UZU_Bist_4_rm_8_shift                                        (0)
#define  SCALEUP_DM_UZU_Bist_4_rm_11_mask                                        (0x0000F000)
#define  SCALEUP_DM_UZU_Bist_4_rm_10_mask                                        (0x00000F00)
#define  SCALEUP_DM_UZU_Bist_4_rm_9_mask                                         (0x000000F0)
#define  SCALEUP_DM_UZU_Bist_4_rm_8_mask                                         (0x0000000F)
#define  SCALEUP_DM_UZU_Bist_4_rm_11(data)                                       (0x0000F000&((data)<<12))
#define  SCALEUP_DM_UZU_Bist_4_rm_10(data)                                       (0x00000F00&((data)<<8))
#define  SCALEUP_DM_UZU_Bist_4_rm_9(data)                                        (0x000000F0&((data)<<4))
#define  SCALEUP_DM_UZU_Bist_4_rm_8(data)                                        (0x0000000F&(data))
#define  SCALEUP_DM_UZU_Bist_4_get_rm_11(data)                                   ((0x0000F000&(data))>>12)
#define  SCALEUP_DM_UZU_Bist_4_get_rm_10(data)                                   ((0x00000F00&(data))>>8)
#define  SCALEUP_DM_UZU_Bist_4_get_rm_9(data)                                    ((0x000000F0&(data))>>4)
#define  SCALEUP_DM_UZU_Bist_4_get_rm_8(data)                                    (0x0000000F&(data))

#define  SCALEUP_DM_UZU_COEF_BIST                                                0x18029190
#define  SCALEUP_DM_UZU_COEF_BIST_reg_addr                                       "0xB8029190"
#define  SCALEUP_DM_UZU_COEF_BIST_reg                                            0xB8029190
#define  SCALEUP_DM_UZU_COEF_BIST_inst_addr                                      "0x004C"
#define  set_SCALEUP_DM_UZU_COEF_BIST_reg(data)                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_COEF_BIST_reg)=data)
#define  get_SCALEUP_DM_UZU_COEF_BIST_reg                                        (*((volatile unsigned int*)SCALEUP_DM_UZU_COEF_BIST_reg))
#define  SCALEUP_DM_UZU_COEF_BIST_drf_bist_fail_0_shift                          (31)
#define  SCALEUP_DM_UZU_COEF_BIST_bist_fail_0_shift                              (30)
#define  SCALEUP_DM_UZU_COEF_BIST_rme_0_shift                                    (4)
#define  SCALEUP_DM_UZU_COEF_BIST_rm_0_shift                                     (0)
#define  SCALEUP_DM_UZU_COEF_BIST_drf_bist_fail_0_mask                           (0x80000000)
#define  SCALEUP_DM_UZU_COEF_BIST_bist_fail_0_mask                               (0x40000000)
#define  SCALEUP_DM_UZU_COEF_BIST_rme_0_mask                                     (0x00000010)
#define  SCALEUP_DM_UZU_COEF_BIST_rm_0_mask                                      (0x0000000F)
#define  SCALEUP_DM_UZU_COEF_BIST_drf_bist_fail_0(data)                          (0x80000000&((data)<<31))
#define  SCALEUP_DM_UZU_COEF_BIST_bist_fail_0(data)                              (0x40000000&((data)<<30))
#define  SCALEUP_DM_UZU_COEF_BIST_rme_0(data)                                    (0x00000010&((data)<<4))
#define  SCALEUP_DM_UZU_COEF_BIST_rm_0(data)                                     (0x0000000F&(data))
#define  SCALEUP_DM_UZU_COEF_BIST_get_drf_bist_fail_0(data)                      ((0x80000000&(data))>>31)
#define  SCALEUP_DM_UZU_COEF_BIST_get_bist_fail_0(data)                          ((0x40000000&(data))>>30)
#define  SCALEUP_DM_UZU_COEF_BIST_get_rme_0(data)                                ((0x00000010&(data))>>4)
#define  SCALEUP_DM_UZU_COEF_BIST_get_rm_0(data)                                 (0x0000000F&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0                                         0x18029200
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg_addr                                "0xB8029200"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg                                     0xB8029200
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_inst_addr                               "0x004D"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c0_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c1_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c0_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c1_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c0(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_tab1_c1(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_get_tab1_c0(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C0_get_tab1_c1(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2                                         0x18029204
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg_addr                                "0xB8029204"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg                                     0xB8029204
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_inst_addr                               "0x004E"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c2_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c3_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c2_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c3_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c2(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_tab1_c3(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_get_tab1_c2(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C2_get_tab1_c3(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4                                         0x18029208
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg_addr                                "0xB8029208"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg                                     0xB8029208
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_inst_addr                               "0x004F"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c4_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c5_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c4_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c5_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c4(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_tab1_c5(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_get_tab1_c4(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C4_get_tab1_c5(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6                                         0x1802920C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg_addr                                "0xB802920C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg                                     0xB802920C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_inst_addr                               "0x0050"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c6_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c7_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c6_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c7_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c6(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_tab1_c7(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_get_tab1_c6(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C6_get_tab1_c7(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8                                         0x18029210
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg_addr                                "0xB8029210"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg                                     0xB8029210
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_inst_addr                               "0x0051"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c8_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c9_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c8_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c9_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c8(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_tab1_c9(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_get_tab1_c8(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C8_get_tab1_c9(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10                                        0x18029214
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg_addr                               "0xB8029214"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg                                    0xB8029214
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_inst_addr                              "0x0052"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c10_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c11_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c10_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c11_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c10(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_tab1_c11(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_get_tab1_c10(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C10_get_tab1_c11(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12                                        0x18029218
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg_addr                               "0xB8029218"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg                                    0xB8029218
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_inst_addr                              "0x0053"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c12_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c13_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c12_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c13_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c12(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_tab1_c13(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_get_tab1_c12(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C12_get_tab1_c13(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14                                        0x1802921C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg_addr                               "0xB802921C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg                                    0xB802921C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_inst_addr                              "0x0054"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c14_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c15_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c14_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c15_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c14(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_tab1_c15(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_get_tab1_c14(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C14_get_tab1_c15(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16                                        0x18029220
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg_addr                               "0xB8029220"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg                                    0xB8029220
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_inst_addr                              "0x0055"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c16_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c17_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c16_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c17_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c16(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_tab1_c17(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_get_tab1_c16(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C16_get_tab1_c17(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18                                        0x18029224
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg_addr                               "0xB8029224"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg                                    0xB8029224
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_inst_addr                              "0x0056"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c18_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c19_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c18_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c19_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c18(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_tab1_c19(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_get_tab1_c18(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C18_get_tab1_c19(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20                                        0x18029228
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg_addr                               "0xB8029228"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg                                    0xB8029228
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_inst_addr                              "0x0057"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c20_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c21_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c20_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c21_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c20(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_tab1_c21(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_get_tab1_c20(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C20_get_tab1_c21(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22                                        0x1802922C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg_addr                               "0xB802922C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg                                    0xB802922C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_inst_addr                              "0x0058"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c22_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c23_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c22_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c23_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c22(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_tab1_c23(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_get_tab1_c22(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C22_get_tab1_c23(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24                                        0x18029230
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg_addr                               "0xB8029230"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg                                    0xB8029230
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_inst_addr                              "0x0059"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c24_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c25_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c24_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c25_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c24(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_tab1_c25(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_get_tab1_c24(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C24_get_tab1_c25(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26                                        0x18029234
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg_addr                               "0xB8029234"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg                                    0xB8029234
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_inst_addr                              "0x005A"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c26_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c27_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c26_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c27_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c26(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_tab1_c27(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_get_tab1_c26(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C26_get_tab1_c27(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28                                        0x18029238
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg_addr                               "0xB8029238"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg                                    0xB8029238
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_inst_addr                              "0x005B"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c28_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c29_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c28_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c29_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c28(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_tab1_c29(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_get_tab1_c28(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C28_get_tab1_c29(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30                                        0x1802923C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg_addr                               "0xB802923C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg                                    0xB802923C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_inst_addr                              "0x005C"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c30_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c31_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c30_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c31_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c30(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_tab1_c31(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_get_tab1_c30(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C30_get_tab1_c31(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32                                        0x18029240
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg_addr                               "0xB8029240"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg                                    0xB8029240
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_inst_addr                              "0x005D"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c32_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c33_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c32_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c33_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c32(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_tab1_c33(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_get_tab1_c32(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C32_get_tab1_c33(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34                                        0x18029244
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg_addr                               "0xB8029244"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg                                    0xB8029244
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_inst_addr                              "0x005E"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c34_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c35_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c34_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c35_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c34(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_tab1_c35(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_get_tab1_c34(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C34_get_tab1_c35(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36                                        0x18029248
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg_addr                               "0xB8029248"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg                                    0xB8029248
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_inst_addr                              "0x005F"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c36_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c37_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c36_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c37_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c36(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_tab1_c37(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_get_tab1_c36(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C36_get_tab1_c37(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38                                        0x1802924C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg_addr                               "0xB802924C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg                                    0xB802924C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_inst_addr                              "0x0060"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c38_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c39_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c38_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c39_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c38(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_tab1_c39(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_get_tab1_c38(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C38_get_tab1_c39(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40                                        0x18029250
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg_addr                               "0xB8029250"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg                                    0xB8029250
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_inst_addr                              "0x0061"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c40_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c41_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c40_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c41_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c40(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_tab1_c41(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_get_tab1_c40(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C40_get_tab1_c41(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42                                        0x18029254
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg_addr                               "0xB8029254"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg                                    0xB8029254
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_inst_addr                              "0x0062"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c42_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c43_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c42_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c43_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c42(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_tab1_c43(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_get_tab1_c42(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C42_get_tab1_c43(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44                                        0x18029258
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg_addr                               "0xB8029258"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg                                    0xB8029258
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_inst_addr                              "0x0063"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c44_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c45_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c44_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c45_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c44(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_tab1_c45(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_get_tab1_c44(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C44_get_tab1_c45(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46                                        0x1802925C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg_addr                               "0xB802925C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg                                    0xB802925C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_inst_addr                              "0x0064"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c46_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c47_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c46_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c47_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c46(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_tab1_c47(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_get_tab1_c46(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C46_get_tab1_c47(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48                                        0x18029260
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg_addr                               "0xB8029260"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg                                    0xB8029260
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_inst_addr                              "0x0065"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c48_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c49_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c48_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c49_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c48(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_tab1_c49(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_get_tab1_c48(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C48_get_tab1_c49(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50                                        0x18029264
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg_addr                               "0xB8029264"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg                                    0xB8029264
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_inst_addr                              "0x0066"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c50_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c51_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c50_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c51_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c50(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_tab1_c51(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_get_tab1_c50(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C50_get_tab1_c51(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52                                        0x18029268
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg_addr                               "0xB8029268"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg                                    0xB8029268
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_inst_addr                              "0x0067"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c52_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c53_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c52_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c53_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c52(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_tab1_c53(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_get_tab1_c52(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C52_get_tab1_c53(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54                                        0x1802926C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg_addr                               "0xB802926C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg                                    0xB802926C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_inst_addr                              "0x0068"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c54_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c55_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c54_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c55_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c54(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_tab1_c55(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_get_tab1_c54(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C54_get_tab1_c55(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56                                        0x18029270
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg_addr                               "0xB8029270"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg                                    0xB8029270
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_inst_addr                              "0x0069"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c56_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c57_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c56_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c57_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c56(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_tab1_c57(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_get_tab1_c56(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C56_get_tab1_c57(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58                                        0x18029274
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg_addr                               "0xB8029274"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg                                    0xB8029274
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_inst_addr                              "0x006A"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c58_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c59_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c58_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c59_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c58(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_tab1_c59(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_get_tab1_c58(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C58_get_tab1_c59(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60                                        0x18029278
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg_addr                               "0xB8029278"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg                                    0xB8029278
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_inst_addr                              "0x006B"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c60_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c61_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c60_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c61_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c60(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_tab1_c61(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_get_tab1_c60(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C60_get_tab1_c61(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62                                        0x1802927C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg_addr                               "0xB802927C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg                                    0xB802927C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_inst_addr                              "0x006C"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c62_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c63_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c62_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c63_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c62(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_tab1_c63(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_get_tab1_c62(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab1_C62_get_tab1_c63(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0                                         0x18029280
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg_addr                                "0xB8029280"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg                                     0xB8029280
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_inst_addr                               "0x006D"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c0_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c1_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c0_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c1_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c0(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_tab2_c1(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_get_tab2_c0(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C0_get_tab2_c1(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2                                         0x18029284
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg_addr                                "0xB8029284"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg                                     0xB8029284
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_inst_addr                               "0x006E"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c2_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c3_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c2_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c3_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c2(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_tab2_c3(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_get_tab2_c2(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C2_get_tab2_c3(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4                                         0x18029288
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg_addr                                "0xB8029288"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg                                     0xB8029288
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_inst_addr                               "0x006F"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c4_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c5_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c4_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c5_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c4(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_tab2_c5(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_get_tab2_c4(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C4_get_tab2_c5(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6                                         0x1802928C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg_addr                                "0xB802928C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg                                     0xB802928C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_inst_addr                               "0x0070"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c6_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c7_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c6_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c7_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c6(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_tab2_c7(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_get_tab2_c6(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C6_get_tab2_c7(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8                                         0x18029290
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg_addr                                "0xB8029290"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg                                     0xB8029290
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_inst_addr                               "0x0071"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c8_shift                           (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c9_shift                           (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c8_mask                            (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c9_mask                            (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c8(data)                           (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_tab2_c9(data)                           (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_get_tab2_c8(data)                       ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C8_get_tab2_c9(data)                       (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10                                        0x18029294
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg_addr                               "0xB8029294"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg                                    0xB8029294
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_inst_addr                              "0x0072"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c10_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c11_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c10_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c11_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c10(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_tab2_c11(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_get_tab2_c10(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C10_get_tab2_c11(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12                                        0x18029298
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg_addr                               "0xB8029298"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg                                    0xB8029298
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_inst_addr                              "0x0073"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c12_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c13_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c12_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c13_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c12(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_tab2_c13(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_get_tab2_c12(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C12_get_tab2_c13(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14                                        0x1802929C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg_addr                               "0xB802929C"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg                                    0xB802929C
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_inst_addr                              "0x0074"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c14_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c15_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c14_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c15_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c14(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_tab2_c15(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_get_tab2_c14(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C14_get_tab2_c15(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16                                        0x180292A0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg_addr                               "0xB80292A0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg                                    0xB80292A0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_inst_addr                              "0x0075"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c16_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c17_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c16_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c17_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c16(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_tab2_c17(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_get_tab2_c16(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C16_get_tab2_c17(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18                                        0x180292A4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg_addr                               "0xB80292A4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg                                    0xB80292A4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_inst_addr                              "0x0076"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c18_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c19_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c18_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c19_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c18(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_tab2_c19(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_get_tab2_c18(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C18_get_tab2_c19(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20                                        0x180292A8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg_addr                               "0xB80292A8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg                                    0xB80292A8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_inst_addr                              "0x0077"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c20_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c21_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c20_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c21_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c20(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_tab2_c21(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_get_tab2_c20(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C20_get_tab2_c21(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22                                        0x180292AC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg_addr                               "0xB80292AC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg                                    0xB80292AC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_inst_addr                              "0x0078"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c22_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c23_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c22_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c23_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c22(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_tab2_c23(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_get_tab2_c22(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C22_get_tab2_c23(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24                                        0x180292B0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg_addr                               "0xB80292B0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg                                    0xB80292B0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_inst_addr                              "0x0079"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c24_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c25_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c24_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c25_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c24(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_tab2_c25(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_get_tab2_c24(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C24_get_tab2_c25(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26                                        0x180292B4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg_addr                               "0xB80292B4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg                                    0xB80292B4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_inst_addr                              "0x007A"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c26_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c27_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c26_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c27_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c26(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_tab2_c27(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_get_tab2_c26(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C26_get_tab2_c27(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28                                        0x180292B8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg_addr                               "0xB80292B8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg                                    0xB80292B8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_inst_addr                              "0x007B"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c28_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c29_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c28_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c29_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c28(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_tab2_c29(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_get_tab2_c28(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C28_get_tab2_c29(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30                                        0x180292BC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg_addr                               "0xB80292BC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg                                    0xB80292BC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_inst_addr                              "0x007C"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c30_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c31_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c30_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c31_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c30(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_tab2_c31(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_get_tab2_c30(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C30_get_tab2_c31(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32                                        0x180292C0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg_addr                               "0xB80292C0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg                                    0xB80292C0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_inst_addr                              "0x007D"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c32_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c33_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c32_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c33_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c32(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_tab2_c33(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_get_tab2_c32(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C32_get_tab2_c33(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34                                        0x180292C4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg_addr                               "0xB80292C4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg                                    0xB80292C4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_inst_addr                              "0x007E"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c34_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c35_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c34_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c35_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c34(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_tab2_c35(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_get_tab2_c34(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C34_get_tab2_c35(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36                                        0x180292C8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg_addr                               "0xB80292C8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg                                    0xB80292C8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_inst_addr                              "0x007F"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c36_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c37_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c36_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c37_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c36(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_tab2_c37(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_get_tab2_c36(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C36_get_tab2_c37(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38                                        0x180292CC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg_addr                               "0xB80292CC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg                                    0xB80292CC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_inst_addr                              "0x0080"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c38_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c39_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c38_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c39_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c38(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_tab2_c39(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_get_tab2_c38(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C38_get_tab2_c39(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40                                        0x180292D0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg_addr                               "0xB80292D0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg                                    0xB80292D0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_inst_addr                              "0x0081"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c40_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c41_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c40_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c41_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c40(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_tab2_c41(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_get_tab2_c40(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C40_get_tab2_c41(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42                                        0x180292D4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg_addr                               "0xB80292D4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg                                    0xB80292D4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_inst_addr                              "0x0082"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c42_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c43_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c42_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c43_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c42(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_tab2_c43(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_get_tab2_c42(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C42_get_tab2_c43(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44                                        0x180292D8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg_addr                               "0xB80292D8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg                                    0xB80292D8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_inst_addr                              "0x0083"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c44_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c45_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c44_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c45_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c44(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_tab2_c45(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_get_tab2_c44(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C44_get_tab2_c45(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46                                        0x180292DC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg_addr                               "0xB80292DC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg                                    0xB80292DC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_inst_addr                              "0x0084"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c46_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c47_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c46_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c47_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c46(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_tab2_c47(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_get_tab2_c46(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C46_get_tab2_c47(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48                                        0x180292E0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg_addr                               "0xB80292E0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg                                    0xB80292E0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_inst_addr                              "0x0085"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c48_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c49_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c48_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c49_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c48(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_tab2_c49(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_get_tab2_c48(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C48_get_tab2_c49(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50                                        0x180292E4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg_addr                               "0xB80292E4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg                                    0xB80292E4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_inst_addr                              "0x0086"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c50_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c51_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c50_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c51_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c50(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_tab2_c51(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_get_tab2_c50(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C50_get_tab2_c51(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52                                        0x180292E8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg_addr                               "0xB80292E8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg                                    0xB80292E8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_inst_addr                              "0x0087"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c52_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c53_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c52_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c53_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c52(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_tab2_c53(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_get_tab2_c52(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C52_get_tab2_c53(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54                                        0x180292EC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg_addr                               "0xB80292EC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg                                    0xB80292EC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_inst_addr                              "0x0088"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c54_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c55_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c54_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c55_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c54(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_tab2_c55(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_get_tab2_c54(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C54_get_tab2_c55(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56                                        0x180292F0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg_addr                               "0xB80292F0"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg                                    0xB80292F0
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_inst_addr                              "0x0089"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c56_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c57_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c56_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c57_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c56(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_tab2_c57(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_get_tab2_c56(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C56_get_tab2_c57(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58                                        0x180292F4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg_addr                               "0xB80292F4"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg                                    0xB80292F4
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_inst_addr                              "0x008A"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c58_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c59_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c58_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c59_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c58(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_tab2_c59(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_get_tab2_c58(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C58_get_tab2_c59(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60                                        0x180292F8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg_addr                               "0xB80292F8"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg                                    0xB80292F8
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_inst_addr                              "0x008B"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c60_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c61_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c60_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c61_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c60(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_tab2_c61(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_get_tab2_c60(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C60_get_tab2_c61(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62                                        0x180292FC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg_addr                               "0xB80292FC"
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg                                    0xB80292FC
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_inst_addr                              "0x008C"
#define  set_SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg(data)                          (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg)=data)
#define  get_SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg                                (*((volatile unsigned int*)SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_reg))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c62_shift                         (16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c63_shift                         (0)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c62_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c63_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c62(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_tab2_c63(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_get_tab2_c62(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_FIR_Coef_Tab2_C62_get_tab2_c63(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0                                          0x18029300
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg_addr                                 "0xB8029300"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg                                      0xB8029300
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_inst_addr                                "0x008D"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C0_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c0_shift                         (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c1_shift                         (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c0_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c1_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c0(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_dir_tab_c1(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_get_dir_tab_c0(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C0_get_dir_tab_c1(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2                                          0x18029304
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg_addr                                 "0xB8029304"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg                                      0xB8029304
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_inst_addr                                "0x008E"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C2_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c2_shift                         (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c3_shift                         (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c2_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c3_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c2(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_dir_tab_c3(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_get_dir_tab_c2(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C2_get_dir_tab_c3(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4                                          0x18029308
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg_addr                                 "0xB8029308"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg                                      0xB8029308
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_inst_addr                                "0x008F"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C4_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c4_shift                         (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c5_shift                         (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c4_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c5_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c4(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_dir_tab_c5(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_get_dir_tab_c4(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C4_get_dir_tab_c5(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6                                          0x1802930C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg_addr                                 "0xB802930C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg                                      0xB802930C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_inst_addr                                "0x0090"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C6_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c6_shift                         (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c7_shift                         (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c6_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c7_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c6(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_dir_tab_c7(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_get_dir_tab_c6(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C6_get_dir_tab_c7(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8                                          0x18029310
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg_addr                                 "0xB8029310"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg                                      0xB8029310
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_inst_addr                                "0x0091"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg(data)                            (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg                                  (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C8_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c8_shift                         (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c9_shift                         (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c8_mask                          (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c9_mask                          (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c8(data)                         (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_dir_tab_c9(data)                         (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_get_dir_tab_c8(data)                     ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C8_get_dir_tab_c9(data)                     (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10                                         0x18029314
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg_addr                                "0xB8029314"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg                                     0xB8029314
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_inst_addr                               "0x0092"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C10_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c10_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c11_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c10_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c11_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c10(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_dir_tab_c11(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_get_dir_tab_c10(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C10_get_dir_tab_c11(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12                                         0x18029318
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg_addr                                "0xB8029318"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg                                     0xB8029318
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_inst_addr                               "0x0093"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C12_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c12_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c13_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c12_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c13_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c12(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_dir_tab_c13(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_get_dir_tab_c12(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C12_get_dir_tab_c13(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14                                         0x1802931C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg_addr                                "0xB802931C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg                                     0xB802931C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_inst_addr                               "0x0094"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C14_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c14_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c15_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c14_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c15_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c14(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_dir_tab_c15(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_get_dir_tab_c14(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C14_get_dir_tab_c15(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16                                         0x18029320
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg_addr                                "0xB8029320"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg                                     0xB8029320
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_inst_addr                               "0x0095"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C16_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c16_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c17_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c16_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c17_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c16(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_dir_tab_c17(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_get_dir_tab_c16(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C16_get_dir_tab_c17(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18                                         0x18029324
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg_addr                                "0xB8029324"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg                                     0xB8029324
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_inst_addr                               "0x0096"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C18_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c18_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c19_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c18_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c19_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c18(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_dir_tab_c19(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_get_dir_tab_c18(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C18_get_dir_tab_c19(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20                                         0x18029328
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg_addr                                "0xB8029328"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg                                     0xB8029328
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_inst_addr                               "0x0097"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C20_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c20_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c21_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c20_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c21_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c20(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_dir_tab_c21(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_get_dir_tab_c20(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C20_get_dir_tab_c21(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22                                         0x1802932C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg_addr                                "0xB802932C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg                                     0xB802932C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_inst_addr                               "0x0098"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C22_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c22_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c23_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c22_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c23_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c22(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_dir_tab_c23(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_get_dir_tab_c22(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C22_get_dir_tab_c23(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24                                         0x18029330
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg_addr                                "0xB8029330"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg                                     0xB8029330
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_inst_addr                               "0x0099"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C24_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c24_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c25_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c24_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c25_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c24(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_dir_tab_c25(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_get_dir_tab_c24(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C24_get_dir_tab_c25(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26                                         0x18029334
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg_addr                                "0xB8029334"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg                                     0xB8029334
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_inst_addr                               "0x009A"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C26_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c26_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c27_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c26_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c27_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c26(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_dir_tab_c27(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_get_dir_tab_c26(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C26_get_dir_tab_c27(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28                                         0x18029338
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg_addr                                "0xB8029338"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg                                     0xB8029338
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_inst_addr                               "0x009B"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C28_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c28_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c29_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c28_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c29_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c28(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_dir_tab_c29(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_get_dir_tab_c28(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C28_get_dir_tab_c29(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30                                         0x1802933C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg_addr                                "0xB802933C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg                                     0xB802933C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_inst_addr                               "0x009C"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C30_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c30_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c31_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c30_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c31_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c30(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_dir_tab_c31(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_get_dir_tab_c30(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C30_get_dir_tab_c31(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32                                         0x18029340
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg_addr                                "0xB8029340"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg                                     0xB8029340
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_inst_addr                               "0x009D"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C32_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c32_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c33_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c32_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c33_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c32(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_dir_tab_c33(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_get_dir_tab_c32(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C32_get_dir_tab_c33(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34                                         0x18029344
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg_addr                                "0xB8029344"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg                                     0xB8029344
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_inst_addr                               "0x009E"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C34_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c34_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c35_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c34_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c35_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c34(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_dir_tab_c35(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_get_dir_tab_c34(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C34_get_dir_tab_c35(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36                                         0x18029348
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg_addr                                "0xB8029348"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg                                     0xB8029348
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_inst_addr                               "0x009F"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C36_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c36_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c37_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c36_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c37_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c36(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_dir_tab_c37(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_get_dir_tab_c36(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C36_get_dir_tab_c37(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38                                         0x1802934C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg_addr                                "0xB802934C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg                                     0xB802934C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_inst_addr                               "0x00A0"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C38_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c38_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c39_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c38_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c39_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c38(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_dir_tab_c39(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_get_dir_tab_c38(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C38_get_dir_tab_c39(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40                                         0x18029350
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg_addr                                "0xB8029350"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg                                     0xB8029350
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_inst_addr                               "0x00A1"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C40_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c40_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c41_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c40_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c41_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c40(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_dir_tab_c41(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_get_dir_tab_c40(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C40_get_dir_tab_c41(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42                                         0x18029354
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg_addr                                "0xB8029354"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg                                     0xB8029354
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_inst_addr                               "0x00A2"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C42_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c42_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c43_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c42_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c43_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c42(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_dir_tab_c43(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_get_dir_tab_c42(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C42_get_dir_tab_c43(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44                                         0x18029358
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg_addr                                "0xB8029358"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg                                     0xB8029358
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_inst_addr                               "0x00A3"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C44_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c44_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c45_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c44_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c45_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c44(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_dir_tab_c45(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_get_dir_tab_c44(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C44_get_dir_tab_c45(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46                                         0x1802935C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg_addr                                "0xB802935C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg                                     0xB802935C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_inst_addr                               "0x00A4"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C46_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c46_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c47_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c46_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c47_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c46(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_dir_tab_c47(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_get_dir_tab_c46(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C46_get_dir_tab_c47(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48                                         0x18029360
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg_addr                                "0xB8029360"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg                                     0xB8029360
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_inst_addr                               "0x00A5"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C48_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c48_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c49_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c48_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c49_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c48(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_dir_tab_c49(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_get_dir_tab_c48(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C48_get_dir_tab_c49(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50                                         0x18029364
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg_addr                                "0xB8029364"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg                                     0xB8029364
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_inst_addr                               "0x00A6"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C50_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c50_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c51_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c50_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c51_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c50(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_dir_tab_c51(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_get_dir_tab_c50(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C50_get_dir_tab_c51(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52                                         0x18029368
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg_addr                                "0xB8029368"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg                                     0xB8029368
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_inst_addr                               "0x00A7"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C52_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c52_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c53_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c52_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c53_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c52(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_dir_tab_c53(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_get_dir_tab_c52(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C52_get_dir_tab_c53(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54                                         0x1802936C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg_addr                                "0xB802936C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg                                     0xB802936C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_inst_addr                               "0x00A8"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C54_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c54_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c55_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c54_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c55_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c54(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_dir_tab_c55(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_get_dir_tab_c54(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C54_get_dir_tab_c55(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56                                         0x18029370
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg_addr                                "0xB8029370"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg                                     0xB8029370
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_inst_addr                               "0x00A9"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C56_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c56_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c57_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c56_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c57_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c56(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_dir_tab_c57(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_get_dir_tab_c56(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C56_get_dir_tab_c57(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58                                         0x18029374
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg_addr                                "0xB8029374"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg                                     0xB8029374
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_inst_addr                               "0x00AA"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C58_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c58_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c59_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c58_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c59_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c58(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_dir_tab_c59(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_get_dir_tab_c58(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C58_get_dir_tab_c59(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60                                         0x18029378
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg_addr                                "0xB8029378"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg                                     0xB8029378
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_inst_addr                               "0x00AB"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C60_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c60_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c61_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c60_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c61_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c60(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_dir_tab_c61(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_get_dir_tab_c60(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C60_get_dir_tab_c61(data)                   (0x00000FFF&(data))

#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62                                         0x1802937C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg_addr                                "0xB802937C"
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg                                     0xB802937C
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_inst_addr                               "0x00AC"
#define  set_SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg(data)                           (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg)=data)
#define  get_SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg                                 (*((volatile unsigned int*)SCALEUP_DM_UZU_Dir_Coef_Tab_C62_reg))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c62_shift                       (16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c63_shift                       (0)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c62_mask                        (0x0FFF0000)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c63_mask                        (0x00000FFF)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c62(data)                       (0x0FFF0000&((data)<<16))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_dir_tab_c63(data)                       (0x00000FFF&(data))
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_get_dir_tab_c62(data)                   ((0x0FFF0000&(data))>>16)
#define  SCALEUP_DM_UZU_Dir_Coef_Tab_C62_get_dir_tab_c63(data)                   (0x00000FFF&(data))

#define  SCALEUP_COEF_TABLE_RW_CTL                                               0x18029390
#define  SCALEUP_COEF_TABLE_RW_CTL_reg_addr                                      "0xB8029390"
#define  SCALEUP_COEF_TABLE_RW_CTL_reg                                           0xB8029390
#define  SCALEUP_COEF_TABLE_RW_CTL_inst_addr                                     "0x00AD"
#define  set_SCALEUP_COEF_TABLE_RW_CTL_reg(data)                                 (*((volatile unsigned int*)SCALEUP_COEF_TABLE_RW_CTL_reg)=data)
#define  get_SCALEUP_COEF_TABLE_RW_CTL_reg                                       (*((volatile unsigned int*)SCALEUP_COEF_TABLE_RW_CTL_reg))
#define  SCALEUP_COEF_TABLE_RW_CTL_coef_rw_sel_shift                             (0)
#define  SCALEUP_COEF_TABLE_RW_CTL_coef_rw_sel_mask                              (0x00000003)
#define  SCALEUP_COEF_TABLE_RW_CTL_coef_rw_sel(data)                             (0x00000003&(data))
#define  SCALEUP_COEF_TABLE_RW_CTL_get_coef_rw_sel(data)                         (0x00000003&(data))

#define  SCALEUP_COEF_TABLE_CTL                                                  0x18029394
#define  SCALEUP_COEF_TABLE_CTL_reg_addr                                         "0xB8029394"
#define  SCALEUP_COEF_TABLE_CTL_reg                                              0xB8029394
#define  SCALEUP_COEF_TABLE_CTL_inst_addr                                        "0x00AE"
#define  set_SCALEUP_COEF_TABLE_CTL_reg(data)                                    (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_reg)=data)
#define  get_SCALEUP_COEF_TABLE_CTL_reg                                          (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_reg))
#define  SCALEUP_COEF_TABLE_CTL_coef_addr_shift                                  (8)
#define  SCALEUP_COEF_TABLE_CTL_coef_write_shift                                 (4)
#define  SCALEUP_COEF_TABLE_CTL_coef_tab_sel_shift                               (0)
#define  SCALEUP_COEF_TABLE_CTL_coef_addr_mask                                   (0x00001F00)
#define  SCALEUP_COEF_TABLE_CTL_coef_write_mask                                  (0x00000010)
#define  SCALEUP_COEF_TABLE_CTL_coef_tab_sel_mask                                (0x00000001)
#define  SCALEUP_COEF_TABLE_CTL_coef_addr(data)                                  (0x00001F00&((data)<<8))
#define  SCALEUP_COEF_TABLE_CTL_coef_write(data)                                 (0x00000010&((data)<<4))
#define  SCALEUP_COEF_TABLE_CTL_coef_tab_sel(data)                               (0x00000001&(data))
#define  SCALEUP_COEF_TABLE_CTL_get_coef_addr(data)                              ((0x00001F00&(data))>>8)
#define  SCALEUP_COEF_TABLE_CTL_get_coef_write(data)                             ((0x00000010&(data))>>4)
#define  SCALEUP_COEF_TABLE_CTL_get_coef_tab_sel(data)                           (0x00000001&(data))

#define  SCALEUP_COEF_TABLE_CTL_0                                                0x18029398
#define  SCALEUP_COEF_TABLE_CTL_0_reg_addr                                       "0xB8029398"
#define  SCALEUP_COEF_TABLE_CTL_0_reg                                            0xB8029398
#define  SCALEUP_COEF_TABLE_CTL_0_inst_addr                                      "0x00AF"
#define  set_SCALEUP_COEF_TABLE_CTL_0_reg(data)                                  (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_0_reg)=data)
#define  get_SCALEUP_COEF_TABLE_CTL_0_reg                                        (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_0_reg))
#define  SCALEUP_COEF_TABLE_CTL_0_coef0_shift                                    (16)
#define  SCALEUP_COEF_TABLE_CTL_0_coef1_shift                                    (0)
#define  SCALEUP_COEF_TABLE_CTL_0_coef0_mask                                     (0x0FFF0000)
#define  SCALEUP_COEF_TABLE_CTL_0_coef1_mask                                     (0x00000FFF)
#define  SCALEUP_COEF_TABLE_CTL_0_coef0(data)                                    (0x0FFF0000&((data)<<16))
#define  SCALEUP_COEF_TABLE_CTL_0_coef1(data)                                    (0x00000FFF&(data))
#define  SCALEUP_COEF_TABLE_CTL_0_get_coef0(data)                                ((0x0FFF0000&(data))>>16)
#define  SCALEUP_COEF_TABLE_CTL_0_get_coef1(data)                                (0x00000FFF&(data))

#define  SCALEUP_COEF_TABLE_CTL_1                                                0x1802939C
#define  SCALEUP_COEF_TABLE_CTL_1_reg_addr                                       "0xB802939C"
#define  SCALEUP_COEF_TABLE_CTL_1_reg                                            0xB802939C
#define  SCALEUP_COEF_TABLE_CTL_1_inst_addr                                      "0x00B0"
#define  set_SCALEUP_COEF_TABLE_CTL_1_reg(data)                                  (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_1_reg)=data)
#define  get_SCALEUP_COEF_TABLE_CTL_1_reg                                        (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_1_reg))
#define  SCALEUP_COEF_TABLE_CTL_1_coef2_shift                                    (16)
#define  SCALEUP_COEF_TABLE_CTL_1_coef3_shift                                    (0)
#define  SCALEUP_COEF_TABLE_CTL_1_coef2_mask                                     (0x0FFF0000)
#define  SCALEUP_COEF_TABLE_CTL_1_coef3_mask                                     (0x00000FFF)
#define  SCALEUP_COEF_TABLE_CTL_1_coef2(data)                                    (0x0FFF0000&((data)<<16))
#define  SCALEUP_COEF_TABLE_CTL_1_coef3(data)                                    (0x00000FFF&(data))
#define  SCALEUP_COEF_TABLE_CTL_1_get_coef2(data)                                ((0x0FFF0000&(data))>>16)
#define  SCALEUP_COEF_TABLE_CTL_1_get_coef3(data)                                (0x00000FFF&(data))

#define  SCALEUP_COEF_TABLE_CTL_2                                                0x180293A0
#define  SCALEUP_COEF_TABLE_CTL_2_reg_addr                                       "0xB80293A0"
#define  SCALEUP_COEF_TABLE_CTL_2_reg                                            0xB80293A0
#define  SCALEUP_COEF_TABLE_CTL_2_inst_addr                                      "0x00B1"
#define  set_SCALEUP_COEF_TABLE_CTL_2_reg(data)                                  (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_2_reg)=data)
#define  get_SCALEUP_COEF_TABLE_CTL_2_reg                                        (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_2_reg))
#define  SCALEUP_COEF_TABLE_CTL_2_coef4_shift                                    (16)
#define  SCALEUP_COEF_TABLE_CTL_2_coef5_shift                                    (0)
#define  SCALEUP_COEF_TABLE_CTL_2_coef4_mask                                     (0x0FFF0000)
#define  SCALEUP_COEF_TABLE_CTL_2_coef5_mask                                     (0x00000FFF)
#define  SCALEUP_COEF_TABLE_CTL_2_coef4(data)                                    (0x0FFF0000&((data)<<16))
#define  SCALEUP_COEF_TABLE_CTL_2_coef5(data)                                    (0x00000FFF&(data))
#define  SCALEUP_COEF_TABLE_CTL_2_get_coef4(data)                                ((0x0FFF0000&(data))>>16)
#define  SCALEUP_COEF_TABLE_CTL_2_get_coef5(data)                                (0x00000FFF&(data))

#define  SCALEUP_COEF_TABLE_CTL_3                                                0x180293A4
#define  SCALEUP_COEF_TABLE_CTL_3_reg_addr                                       "0xB80293A4"
#define  SCALEUP_COEF_TABLE_CTL_3_reg                                            0xB80293A4
#define  SCALEUP_COEF_TABLE_CTL_3_inst_addr                                      "0x00B2"
#define  set_SCALEUP_COEF_TABLE_CTL_3_reg(data)                                  (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_3_reg)=data)
#define  get_SCALEUP_COEF_TABLE_CTL_3_reg                                        (*((volatile unsigned int*)SCALEUP_COEF_TABLE_CTL_3_reg))
#define  SCALEUP_COEF_TABLE_CTL_3_coef6_shift                                    (16)
#define  SCALEUP_COEF_TABLE_CTL_3_coef7_shift                                    (0)
#define  SCALEUP_COEF_TABLE_CTL_3_coef6_mask                                     (0x0FFF0000)
#define  SCALEUP_COEF_TABLE_CTL_3_coef7_mask                                     (0x00000FFF)
#define  SCALEUP_COEF_TABLE_CTL_3_coef6(data)                                    (0x0FFF0000&((data)<<16))
#define  SCALEUP_COEF_TABLE_CTL_3_coef7(data)                                    (0x00000FFF&(data))
#define  SCALEUP_COEF_TABLE_CTL_3_get_coef6(data)                                ((0x0FFF0000&(data))>>16)
#define  SCALEUP_COEF_TABLE_CTL_3_get_coef7(data)                                (0x00000FFF&(data))

#define  SCALEUP_DS_UZU_Ctrl                                                     0x18029B00
#define  SCALEUP_DS_UZU_Ctrl_reg_addr                                            "0xB8029B00"
#define  SCALEUP_DS_UZU_Ctrl_reg                                                 0xB8029B00
#define  SCALEUP_DS_UZU_Ctrl_inst_addr                                           "0x00B3"
#define  set_SCALEUP_DS_UZU_Ctrl_reg(data)                                       (*((volatile unsigned int*)SCALEUP_DS_UZU_Ctrl_reg)=data)
#define  get_SCALEUP_DS_UZU_Ctrl_reg                                             (*((volatile unsigned int*)SCALEUP_DS_UZU_Ctrl_reg))
#define  SCALEUP_DS_UZU_Ctrl_wd_sub_buf_udf_en_shift                             (24)
#define  SCALEUP_DS_UZU_Ctrl_irq_sub_buf_udf_en_shift                            (23)
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_dup_shift                                    (6)
#define  SCALEUP_DS_UZU_Ctrl_video_comp_en_shift                                 (5)
#define  SCALEUP_DS_UZU_Ctrl_odd_inv_shift                                       (4)
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_conv_shift                                   (3)
#define  SCALEUP_DS_UZU_Ctrl_conv_type_shift                                     (2)
#define  SCALEUP_DS_UZU_Ctrl_v_zoom_en_shift                                     (1)
#define  SCALEUP_DS_UZU_Ctrl_h_zoom_en_shift                                     (0)
#define  SCALEUP_DS_UZU_Ctrl_wd_sub_buf_udf_en_mask                              (0x01000000)
#define  SCALEUP_DS_UZU_Ctrl_irq_sub_buf_udf_en_mask                             (0x00800000)
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_dup_mask                                     (0x00000040)
#define  SCALEUP_DS_UZU_Ctrl_video_comp_en_mask                                  (0x00000020)
#define  SCALEUP_DS_UZU_Ctrl_odd_inv_mask                                        (0x00000010)
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_conv_mask                                    (0x00000008)
#define  SCALEUP_DS_UZU_Ctrl_conv_type_mask                                      (0x00000004)
#define  SCALEUP_DS_UZU_Ctrl_v_zoom_en_mask                                      (0x00000002)
#define  SCALEUP_DS_UZU_Ctrl_h_zoom_en_mask                                      (0x00000001)
#define  SCALEUP_DS_UZU_Ctrl_wd_sub_buf_udf_en(data)                             (0x01000000&((data)<<24))
#define  SCALEUP_DS_UZU_Ctrl_irq_sub_buf_udf_en(data)                            (0x00800000&((data)<<23))
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_dup(data)                                    (0x00000040&((data)<<6))
#define  SCALEUP_DS_UZU_Ctrl_video_comp_en(data)                                 (0x00000020&((data)<<5))
#define  SCALEUP_DS_UZU_Ctrl_odd_inv(data)                                       (0x00000010&((data)<<4))
#define  SCALEUP_DS_UZU_Ctrl_in_fmt_conv(data)                                   (0x00000008&((data)<<3))
#define  SCALEUP_DS_UZU_Ctrl_conv_type(data)                                     (0x00000004&((data)<<2))
#define  SCALEUP_DS_UZU_Ctrl_v_zoom_en(data)                                     (0x00000002&((data)<<1))
#define  SCALEUP_DS_UZU_Ctrl_h_zoom_en(data)                                     (0x00000001&(data))
#define  SCALEUP_DS_UZU_Ctrl_get_wd_sub_buf_udf_en(data)                         ((0x01000000&(data))>>24)
#define  SCALEUP_DS_UZU_Ctrl_get_irq_sub_buf_udf_en(data)                        ((0x00800000&(data))>>23)
#define  SCALEUP_DS_UZU_Ctrl_get_in_fmt_dup(data)                                ((0x00000040&(data))>>6)
#define  SCALEUP_DS_UZU_Ctrl_get_video_comp_en(data)                             ((0x00000020&(data))>>5)
#define  SCALEUP_DS_UZU_Ctrl_get_odd_inv(data)                                   ((0x00000010&(data))>>4)
#define  SCALEUP_DS_UZU_Ctrl_get_in_fmt_conv(data)                               ((0x00000008&(data))>>3)
#define  SCALEUP_DS_UZU_Ctrl_get_conv_type(data)                                 ((0x00000004&(data))>>2)
#define  SCALEUP_DS_UZU_Ctrl_get_v_zoom_en(data)                                 ((0x00000002&(data))>>1)
#define  SCALEUP_DS_UZU_Ctrl_get_h_zoom_en(data)                                 (0x00000001&(data))

#define  SCALEUP_DS_UZU_Scale_Hor_Factor                                         0x18029B04
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_reg_addr                                "0xB8029B04"
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_reg                                     0xB8029B04
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_inst_addr                               "0x00B4"
#define  set_SCALEUP_DS_UZU_Scale_Hor_Factor_reg(data)                           (*((volatile unsigned int*)SCALEUP_DS_UZU_Scale_Hor_Factor_reg)=data)
#define  get_SCALEUP_DS_UZU_Scale_Hor_Factor_reg                                 (*((volatile unsigned int*)SCALEUP_DS_UZU_Scale_Hor_Factor_reg))
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_hor_factor_shift                        (0)
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_hor_factor_mask                         (0x000FFFFF)
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_hor_factor(data)                        (0x000FFFFF&(data))
#define  SCALEUP_DS_UZU_Scale_Hor_Factor_get_hor_factor(data)                    (0x000FFFFF&(data))

#define  SCALEUP_DS_UZU_Scale_Ver_Factor                                         0x18029B08
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_reg_addr                                "0xB8029B08"
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_reg                                     0xB8029B08
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_inst_addr                               "0x00B5"
#define  set_SCALEUP_DS_UZU_Scale_Ver_Factor_reg(data)                           (*((volatile unsigned int*)SCALEUP_DS_UZU_Scale_Ver_Factor_reg)=data)
#define  get_SCALEUP_DS_UZU_Scale_Ver_Factor_reg                                 (*((volatile unsigned int*)SCALEUP_DS_UZU_Scale_Ver_Factor_reg))
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_ver_factor_shift                        (0)
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_ver_factor_mask                         (0x000FFFFF)
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_ver_factor(data)                        (0x000FFFFF&(data))
#define  SCALEUP_DS_UZU_Scale_Ver_Factor_get_ver_factor(data)                    (0x000FFFFF&(data))

#define  SCALEUP_DS_UZU_Initial_Value                                            0x18029B0C
#define  SCALEUP_DS_UZU_Initial_Value_reg_addr                                   "0xB8029B0C"
#define  SCALEUP_DS_UZU_Initial_Value_reg                                        0xB8029B0C
#define  SCALEUP_DS_UZU_Initial_Value_inst_addr                                  "0x00B6"
#define  set_SCALEUP_DS_UZU_Initial_Value_reg(data)                              (*((volatile unsigned int*)SCALEUP_DS_UZU_Initial_Value_reg)=data)
#define  get_SCALEUP_DS_UZU_Initial_Value_reg                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_Initial_Value_reg))
#define  SCALEUP_DS_UZU_Initial_Value_hor_ini_shift                              (8)
#define  SCALEUP_DS_UZU_Initial_Value_ver_ini_shift                              (0)
#define  SCALEUP_DS_UZU_Initial_Value_hor_ini_mask                               (0x0000FF00)
#define  SCALEUP_DS_UZU_Initial_Value_ver_ini_mask                               (0x000000FF)
#define  SCALEUP_DS_UZU_Initial_Value_hor_ini(data)                              (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_Initial_Value_ver_ini(data)                              (0x000000FF&(data))
#define  SCALEUP_DS_UZU_Initial_Value_get_hor_ini(data)                          ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_Initial_Value_get_ver_ini(data)                          (0x000000FF&(data))

#define  SCALEUP_DS_UZU_Input_Size                                               0x18029B10
#define  SCALEUP_DS_UZU_Input_Size_reg_addr                                      "0xB8029B10"
#define  SCALEUP_DS_UZU_Input_Size_reg                                           0xB8029B10
#define  SCALEUP_DS_UZU_Input_Size_inst_addr                                     "0x00B7"
#define  set_SCALEUP_DS_UZU_Input_Size_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DS_UZU_Input_Size_reg)=data)
#define  get_SCALEUP_DS_UZU_Input_Size_reg                                       (*((volatile unsigned int*)SCALEUP_DS_UZU_Input_Size_reg))
#define  SCALEUP_DS_UZU_Input_Size_hor_input_size_shift                          (16)
#define  SCALEUP_DS_UZU_Input_Size_ver_input_size_shift                          (0)
#define  SCALEUP_DS_UZU_Input_Size_hor_input_size_mask                           (0x1FFF0000)
#define  SCALEUP_DS_UZU_Input_Size_ver_input_size_mask                           (0x00000FFF)
#define  SCALEUP_DS_UZU_Input_Size_hor_input_size(data)                          (0x1FFF0000&((data)<<16))
#define  SCALEUP_DS_UZU_Input_Size_ver_input_size(data)                          (0x00000FFF&(data))
#define  SCALEUP_DS_UZU_Input_Size_get_hor_input_size(data)                      ((0x1FFF0000&(data))>>16)
#define  SCALEUP_DS_UZU_Input_Size_get_ver_input_size(data)                      (0x00000FFF&(data))

#define  SCALEUP_DS_MEM_CRC_CTRL                                                 0x18029B14
#define  SCALEUP_DS_MEM_CRC_CTRL_reg_addr                                        "0xB8029B14"
#define  SCALEUP_DS_MEM_CRC_CTRL_reg                                             0xB8029B14
#define  SCALEUP_DS_MEM_CRC_CTRL_inst_addr                                       "0x00B8"
#define  set_SCALEUP_DS_MEM_CRC_CTRL_reg(data)                                   (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_CTRL_reg)=data)
#define  get_SCALEUP_DS_MEM_CRC_CTRL_reg                                         (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_CTRL_reg))
#define  SCALEUP_DS_MEM_CRC_CTRL_conti_shift                                     (1)
#define  SCALEUP_DS_MEM_CRC_CTRL_start_shift                                     (0)
#define  SCALEUP_DS_MEM_CRC_CTRL_conti_mask                                      (0x00000002)
#define  SCALEUP_DS_MEM_CRC_CTRL_start_mask                                      (0x00000001)
#define  SCALEUP_DS_MEM_CRC_CTRL_conti(data)                                     (0x00000002&((data)<<1))
#define  SCALEUP_DS_MEM_CRC_CTRL_start(data)                                     (0x00000001&(data))
#define  SCALEUP_DS_MEM_CRC_CTRL_get_conti(data)                                 ((0x00000002&(data))>>1)
#define  SCALEUP_DS_MEM_CRC_CTRL_get_start(data)                                 (0x00000001&(data))

#define  SCALEUP_DS_MEM_CRC_Result                                               0x18029B18
#define  SCALEUP_DS_MEM_CRC_Result_reg_addr                                      "0xB8029B18"
#define  SCALEUP_DS_MEM_CRC_Result_reg                                           0xB8029B18
#define  SCALEUP_DS_MEM_CRC_Result_inst_addr                                     "0x00B9"
#define  set_SCALEUP_DS_MEM_CRC_Result_reg(data)                                 (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_Result_reg)=data)
#define  get_SCALEUP_DS_MEM_CRC_Result_reg                                       (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_Result_reg))
#define  SCALEUP_DS_MEM_CRC_Result_mem_crc_shift                                 (0)
#define  SCALEUP_DS_MEM_CRC_Result_mem_crc_mask                                  (0xFFFFFFFF)
#define  SCALEUP_DS_MEM_CRC_Result_mem_crc(data)                                 (0xFFFFFFFF&(data))
#define  SCALEUP_DS_MEM_CRC_Result_get_mem_crc(data)                             (0xFFFFFFFF&(data))

#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP                                        0x18029B1C
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg_addr                               "0xB8029B1C"
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg                                    0xB8029B1C
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_inst_addr                              "0x00BA"
#define  set_SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg(data)                          (*((volatile unsigned int*)SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg)=data)
#define  get_SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg                                (*((volatile unsigned int*)SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_reg))
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_front_drop_shift                 (12)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_back_drop_shift                  (0)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_front_drop_mask                  (0x007FF000)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_back_drop_mask                   (0x000007FF)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_front_drop(data)                 (0x007FF000&((data)<<12))
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_hor_s_back_drop(data)                  (0x000007FF&(data))
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_get_hor_s_front_drop(data)             ((0x007FF000&(data))>>12)
#define  SCALEUP_DS_UZUSUB_H_PARTIAL_DROP_get_hor_s_back_drop(data)              (0x000007FF&(data))

#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP                                        0x18029B20
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg_addr                               "0xB8029B20"
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg                                    0xB8029B20
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_inst_addr                              "0x00BB"
#define  set_SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg(data)                          (*((volatile unsigned int*)SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg)=data)
#define  get_SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg                                (*((volatile unsigned int*)SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_reg))
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_front_drop_shift                 (16)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_back_drop_shift                  (0)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_front_drop_mask                  (0x01FF0000)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_back_drop_mask                   (0x000001FF)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_front_drop(data)                 (0x01FF0000&((data)<<16))
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_ver_s_back_drop(data)                  (0x000001FF&(data))
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_get_ver_s_front_drop(data)             ((0x01FF0000&(data))>>16)
#define  SCALEUP_DS_UZUSUB_V_PARTIAL_DROP_get_ver_s_back_drop(data)              (0x000001FF&(data))

#define  SCALEUP_DS_UZU_DB_CTRL                                                  0x18029B24
#define  SCALEUP_DS_UZU_DB_CTRL_reg_addr                                         "0xB8029B24"
#define  SCALEUP_DS_UZU_DB_CTRL_reg                                              0xB8029B24
#define  SCALEUP_DS_UZU_DB_CTRL_inst_addr                                        "0x00BC"
#define  set_SCALEUP_DS_UZU_DB_CTRL_reg(data)                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_DB_CTRL_reg)=data)
#define  get_SCALEUP_DS_UZU_DB_CTRL_reg                                          (*((volatile unsigned int*)SCALEUP_DS_UZU_DB_CTRL_reg))
#define  SCALEUP_DS_UZU_DB_CTRL_db_en_shift                                      (2)
#define  SCALEUP_DS_UZU_DB_CTRL_db_read_level_shift                              (1)
#define  SCALEUP_DS_UZU_DB_CTRL_db_apply_shift                                   (0)
#define  SCALEUP_DS_UZU_DB_CTRL_db_en_mask                                       (0x00000004)
#define  SCALEUP_DS_UZU_DB_CTRL_db_read_level_mask                               (0x00000002)
#define  SCALEUP_DS_UZU_DB_CTRL_db_apply_mask                                    (0x00000001)
#define  SCALEUP_DS_UZU_DB_CTRL_db_en(data)                                      (0x00000004&((data)<<2))
#define  SCALEUP_DS_UZU_DB_CTRL_db_read_level(data)                              (0x00000002&((data)<<1))
#define  SCALEUP_DS_UZU_DB_CTRL_db_apply(data)                                   (0x00000001&(data))
#define  SCALEUP_DS_UZU_DB_CTRL_get_db_en(data)                                  ((0x00000004&(data))>>2)
#define  SCALEUP_DS_UZU_DB_CTRL_get_db_read_level(data)                          ((0x00000002&(data))>>1)
#define  SCALEUP_DS_UZU_DB_CTRL_get_db_apply(data)                               (0x00000001&(data))

#define  SCALEUP_DS_MEM_CRC_Ctr2                                                 0x18029B28
#define  SCALEUP_DS_MEM_CRC_Ctr2_reg_addr                                        "0xB8029B28"
#define  SCALEUP_DS_MEM_CRC_Ctr2_reg                                             0xB8029B28
#define  SCALEUP_DS_MEM_CRC_Ctr2_inst_addr                                       "0x00BD"
#define  set_SCALEUP_DS_MEM_CRC_Ctr2_reg(data)                                   (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_Ctr2_reg)=data)
#define  get_SCALEUP_DS_MEM_CRC_Ctr2_reg                                         (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_Ctr2_reg))
#define  SCALEUP_DS_MEM_CRC_Ctr2_auto_cmp_en_shift                               (0)
#define  SCALEUP_DS_MEM_CRC_Ctr2_auto_cmp_en_mask                                (0x00000001)
#define  SCALEUP_DS_MEM_CRC_Ctr2_auto_cmp_en(data)                               (0x00000001&(data))
#define  SCALEUP_DS_MEM_CRC_Ctr2_get_auto_cmp_en(data)                           (0x00000001&(data))

#define  SCALEUP_DS_MEM_L_DES_CRC                                                0x18029B2C
#define  SCALEUP_DS_MEM_L_DES_CRC_reg_addr                                       "0xB8029B2C"
#define  SCALEUP_DS_MEM_L_DES_CRC_reg                                            0xB8029B2C
#define  SCALEUP_DS_MEM_L_DES_CRC_inst_addr                                      "0x00BE"
#define  set_SCALEUP_DS_MEM_L_DES_CRC_reg(data)                                  (*((volatile unsigned int*)SCALEUP_DS_MEM_L_DES_CRC_reg)=data)
#define  get_SCALEUP_DS_MEM_L_DES_CRC_reg                                        (*((volatile unsigned int*)SCALEUP_DS_MEM_L_DES_CRC_reg))
#define  SCALEUP_DS_MEM_L_DES_CRC_des_crc_shift                                  (0)
#define  SCALEUP_DS_MEM_L_DES_CRC_des_crc_mask                                   (0xFFFFFFFF)
#define  SCALEUP_DS_MEM_L_DES_CRC_des_crc(data)                                  (0xFFFFFFFF&(data))
#define  SCALEUP_DS_MEM_L_DES_CRC_get_des_crc(data)                              (0xFFFFFFFF&(data))

#define  SCALEUP_DS_MEM_CRC_ERR_CNT                                              0x18029B30
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_reg_addr                                     "0xB8029B30"
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_reg                                          0xB8029B30
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_inst_addr                                    "0x00BF"
#define  set_SCALEUP_DS_MEM_CRC_ERR_CNT_reg(data)                                (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_ERR_CNT_reg)=data)
#define  get_SCALEUP_DS_MEM_CRC_ERR_CNT_reg                                      (*((volatile unsigned int*)SCALEUP_DS_MEM_CRC_ERR_CNT_reg))
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_crc_err_cnt_shift                            (0)
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_crc_err_cnt_mask                             (0x0000FFFF)
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_crc_err_cnt(data)                            (0x0000FFFF&(data))
#define  SCALEUP_DS_MEM_CRC_ERR_CNT_get_crc_err_cnt(data)                        (0x0000FFFF&(data))

#define  SCALEUP_DS_UZU_WCLR                                                     0x18029B34
#define  SCALEUP_DS_UZU_WCLR_reg_addr                                            "0xB8029B34"
#define  SCALEUP_DS_UZU_WCLR_reg                                                 0xB8029B34
#define  SCALEUP_DS_UZU_WCLR_inst_addr                                           "0x00C0"
#define  set_SCALEUP_DS_UZU_WCLR_reg(data)                                       (*((volatile unsigned int*)SCALEUP_DS_UZU_WCLR_reg)=data)
#define  get_SCALEUP_DS_UZU_WCLR_reg                                             (*((volatile unsigned int*)SCALEUP_DS_UZU_WCLR_reg))
#define  SCALEUP_DS_UZU_WCLR_buff_unf_shift                                      (0)
#define  SCALEUP_DS_UZU_WCLR_buff_unf_mask                                       (0x00000001)
#define  SCALEUP_DS_UZU_WCLR_buff_unf(data)                                      (0x00000001&(data))
#define  SCALEUP_DS_UZU_WCLR_get_buff_unf(data)                                  (0x00000001&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3                                       0x18029B40
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg_addr                              "0xB8029B40"
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg                                   0xB8029B40
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_inst_addr                             "0x00C1"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg(data)                         (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg                               (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c0_shift                          (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c1_shift                          (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c2_shift                          (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c3_shift                          (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c0_mask                           (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c1_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c2_mask                           (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c3_mask                           (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c0(data)                          (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c1(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c2(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_ver_c3(data)                          (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_get_ver_c0(data)                      ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_get_ver_c1(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_get_ver_c2(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C0_C3_get_ver_c3(data)                      (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7                                       0x18029B44
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg_addr                              "0xB8029B44"
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg                                   0xB8029B44
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_inst_addr                             "0x00C2"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg(data)                         (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg                               (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c4_shift                          (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c5_shift                          (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c6_shift                          (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c7_shift                          (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c4_mask                           (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c5_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c6_mask                           (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c7_mask                           (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c4(data)                          (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c5(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c6(data)                          (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_ver_c7(data)                          (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_get_ver_c4(data)                      ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_get_ver_c5(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_get_ver_c6(data)                      ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C4_C7_get_ver_c7(data)                      (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11                                      0x18029B48
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg_addr                             "0xB8029B48"
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg                                  0xB8029B48
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_inst_addr                            "0x00C3"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg(data)                        (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg                              (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c8_shift                         (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c9_shift                         (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c10_shift                        (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c11_shift                        (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c8_mask                          (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c9_mask                          (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c10_mask                         (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c11_mask                         (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c8(data)                         (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c9(data)                         (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c10(data)                        (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_ver_c11(data)                        (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_get_ver_c8(data)                     ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_get_ver_c9(data)                     ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_get_ver_c10(data)                    ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C8_C11_get_ver_c11(data)                    (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15                                     0x18029B4C
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg_addr                            "0xB8029B4C"
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg                                 0xB8029B4C
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_inst_addr                           "0x00C4"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg(data)                       (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg                             (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c12_shift                       (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c13_shift                       (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c14_shift                       (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c15_shift                       (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c12_mask                        (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c13_mask                        (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c14_mask                        (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c15_mask                        (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c12(data)                       (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c13(data)                       (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c14(data)                       (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_ver_c15(data)                       (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_get_ver_c12(data)                   ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_get_ver_c13(data)                   ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_get_ver_c14(data)                   ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Ver_C12_C15_get_ver_c15(data)                   (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0                                          0x18029B50
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg_addr                                 "0xB8029B50"
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg                                      0xB8029B50
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_inst_addr                                "0x00C5"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg(data)                            (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg                                  (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C0_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c0_shift                             (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c1_shift                             (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c2_shift                             (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c3_shift                             (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c0_mask                              (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c1_mask                              (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c2_mask                              (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c3_mask                              (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c0(data)                             (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c1(data)                             (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c2(data)                             (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_hor_c3(data)                             (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_get_hor_c0(data)                         ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_get_hor_c1(data)                         ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_get_hor_c2(data)                         ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C0_get_hor_c3(data)                         (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4                                          0x18029B54
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg_addr                                 "0xB8029B54"
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg                                      0xB8029B54
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_inst_addr                                "0x00C6"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg(data)                            (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg                                  (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C4_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c4_shift                             (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c5_shift                             (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c6_shift                             (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c7_shift                             (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c4_mask                              (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c5_mask                              (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c6_mask                              (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c7_mask                              (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c4(data)                             (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c5(data)                             (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c6(data)                             (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_hor_c7(data)                             (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_get_hor_c4(data)                         ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_get_hor_c5(data)                         ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_get_hor_c6(data)                         ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C4_get_hor_c7(data)                         (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8                                          0x18029B58
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg_addr                                 "0xB8029B58"
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg                                      0xB8029B58
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_inst_addr                                "0x00C7"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg(data)                            (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg                                  (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C8_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c8_shift                             (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c9_shift                             (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c10_shift                            (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c11_shift                            (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c8_mask                              (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c9_mask                              (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c10_mask                             (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c11_mask                             (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c8(data)                             (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c9(data)                             (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c10(data)                            (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_hor_c11(data)                            (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_get_hor_c8(data)                         ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_get_hor_c9(data)                         ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_get_hor_c10(data)                        ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C8_get_hor_c11(data)                        (0x000000FF&(data))

#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12                                         0x18029B5C
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg_addr                                "0xB8029B5C"
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg                                     0xB8029B5C
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_inst_addr                               "0x00C8"
#define  set_SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg(data)                           (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg)=data)
#define  get_SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg                                 (*((volatile unsigned int*)SCALEUP_DS_UZU_FIR_Coef_Hor_C12_reg))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c12_shift                           (24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c13_shift                           (16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c14_shift                           (8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c15_shift                           (0)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c12_mask                            (0xFF000000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c13_mask                            (0x00FF0000)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c14_mask                            (0x0000FF00)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c15_mask                            (0x000000FF)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c12(data)                           (0xFF000000&((data)<<24))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c13(data)                           (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c14(data)                           (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_hor_c15(data)                           (0x000000FF&(data))
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_get_hor_c12(data)                       ((0xFF000000&(data))>>24)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_get_hor_c13(data)                       ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_get_hor_c14(data)                       ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_FIR_Coef_Hor_C12_get_hor_c15(data)                       (0x000000FF&(data))

#define  SCALEUP_DS_UZU_Bist_1                                                   0x18029B64
#define  SCALEUP_DS_UZU_Bist_1_reg_addr                                          "0xB8029B64"
#define  SCALEUP_DS_UZU_Bist_1_reg                                               0xB8029B64
#define  SCALEUP_DS_UZU_Bist_1_inst_addr                                         "0x00C9"
#define  set_SCALEUP_DS_UZU_Bist_1_reg(data)                                     (*((volatile unsigned int*)SCALEUP_DS_UZU_Bist_1_reg)=data)
#define  get_SCALEUP_DS_UZU_Bist_1_reg                                           (*((volatile unsigned int*)SCALEUP_DS_UZU_Bist_1_reg))
#define  SCALEUP_DS_UZU_Bist_1_rm_3_shift                                        (28)
#define  SCALEUP_DS_UZU_Bist_1_rm_2_shift                                        (24)
#define  SCALEUP_DS_UZU_Bist_1_rm_1_shift                                        (20)
#define  SCALEUP_DS_UZU_Bist_1_rm_0_shift                                        (16)
#define  SCALEUP_DS_UZU_Bist_1_ls_3_shift                                        (15)
#define  SCALEUP_DS_UZU_Bist_1_ls_2_shift                                        (14)
#define  SCALEUP_DS_UZU_Bist_1_ls_1_shift                                        (13)
#define  SCALEUP_DS_UZU_Bist_1_ls_0_shift                                        (12)
#define  SCALEUP_DS_UZU_Bist_1_rme_3_shift                                       (11)
#define  SCALEUP_DS_UZU_Bist_1_rme_2_shift                                       (10)
#define  SCALEUP_DS_UZU_Bist_1_rme_1_shift                                       (9)
#define  SCALEUP_DS_UZU_Bist_1_rme_0_shift                                       (8)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_3_shift                             (7)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_2_shift                             (6)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_1_shift                             (5)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_0_shift                             (4)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_3_shift                                 (3)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_2_shift                                 (2)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_1_shift                                 (1)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_0_shift                                 (0)
#define  SCALEUP_DS_UZU_Bist_1_rm_3_mask                                         (0xF0000000)
#define  SCALEUP_DS_UZU_Bist_1_rm_2_mask                                         (0x0F000000)
#define  SCALEUP_DS_UZU_Bist_1_rm_1_mask                                         (0x00F00000)
#define  SCALEUP_DS_UZU_Bist_1_rm_0_mask                                         (0x000F0000)
#define  SCALEUP_DS_UZU_Bist_1_ls_3_mask                                         (0x00008000)
#define  SCALEUP_DS_UZU_Bist_1_ls_2_mask                                         (0x00004000)
#define  SCALEUP_DS_UZU_Bist_1_ls_1_mask                                         (0x00002000)
#define  SCALEUP_DS_UZU_Bist_1_ls_0_mask                                         (0x00001000)
#define  SCALEUP_DS_UZU_Bist_1_rme_3_mask                                        (0x00000800)
#define  SCALEUP_DS_UZU_Bist_1_rme_2_mask                                        (0x00000400)
#define  SCALEUP_DS_UZU_Bist_1_rme_1_mask                                        (0x00000200)
#define  SCALEUP_DS_UZU_Bist_1_rme_0_mask                                        (0x00000100)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_3_mask                              (0x00000080)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_2_mask                              (0x00000040)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_1_mask                              (0x00000020)
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_0_mask                              (0x00000010)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_3_mask                                  (0x00000008)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_2_mask                                  (0x00000004)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_1_mask                                  (0x00000002)
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_0_mask                                  (0x00000001)
#define  SCALEUP_DS_UZU_Bist_1_rm_3(data)                                        (0xF0000000&((data)<<28))
#define  SCALEUP_DS_UZU_Bist_1_rm_2(data)                                        (0x0F000000&((data)<<24))
#define  SCALEUP_DS_UZU_Bist_1_rm_1(data)                                        (0x00F00000&((data)<<20))
#define  SCALEUP_DS_UZU_Bist_1_rm_0(data)                                        (0x000F0000&((data)<<16))
#define  SCALEUP_DS_UZU_Bist_1_ls_3(data)                                        (0x00008000&((data)<<15))
#define  SCALEUP_DS_UZU_Bist_1_ls_2(data)                                        (0x00004000&((data)<<14))
#define  SCALEUP_DS_UZU_Bist_1_ls_1(data)                                        (0x00002000&((data)<<13))
#define  SCALEUP_DS_UZU_Bist_1_ls_0(data)                                        (0x00001000&((data)<<12))
#define  SCALEUP_DS_UZU_Bist_1_rme_3(data)                                       (0x00000800&((data)<<11))
#define  SCALEUP_DS_UZU_Bist_1_rme_2(data)                                       (0x00000400&((data)<<10))
#define  SCALEUP_DS_UZU_Bist_1_rme_1(data)                                       (0x00000200&((data)<<9))
#define  SCALEUP_DS_UZU_Bist_1_rme_0(data)                                       (0x00000100&((data)<<8))
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_3(data)                             (0x00000080&((data)<<7))
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_2(data)                             (0x00000040&((data)<<6))
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_1(data)                             (0x00000020&((data)<<5))
#define  SCALEUP_DS_UZU_Bist_1_drf_bist_fail_0(data)                             (0x00000010&((data)<<4))
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_3(data)                                 (0x00000008&((data)<<3))
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_2(data)                                 (0x00000004&((data)<<2))
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_1(data)                                 (0x00000002&((data)<<1))
#define  SCALEUP_DS_UZU_Bist_1_bist_fail_0(data)                                 (0x00000001&(data))
#define  SCALEUP_DS_UZU_Bist_1_get_rm_3(data)                                    ((0xF0000000&(data))>>28)
#define  SCALEUP_DS_UZU_Bist_1_get_rm_2(data)                                    ((0x0F000000&(data))>>24)
#define  SCALEUP_DS_UZU_Bist_1_get_rm_1(data)                                    ((0x00F00000&(data))>>20)
#define  SCALEUP_DS_UZU_Bist_1_get_rm_0(data)                                    ((0x000F0000&(data))>>16)
#define  SCALEUP_DS_UZU_Bist_1_get_ls_3(data)                                    ((0x00008000&(data))>>15)
#define  SCALEUP_DS_UZU_Bist_1_get_ls_2(data)                                    ((0x00004000&(data))>>14)
#define  SCALEUP_DS_UZU_Bist_1_get_ls_1(data)                                    ((0x00002000&(data))>>13)
#define  SCALEUP_DS_UZU_Bist_1_get_ls_0(data)                                    ((0x00001000&(data))>>12)
#define  SCALEUP_DS_UZU_Bist_1_get_rme_3(data)                                   ((0x00000800&(data))>>11)
#define  SCALEUP_DS_UZU_Bist_1_get_rme_2(data)                                   ((0x00000400&(data))>>10)
#define  SCALEUP_DS_UZU_Bist_1_get_rme_1(data)                                   ((0x00000200&(data))>>9)
#define  SCALEUP_DS_UZU_Bist_1_get_rme_0(data)                                   ((0x00000100&(data))>>8)
#define  SCALEUP_DS_UZU_Bist_1_get_drf_bist_fail_3(data)                         ((0x00000080&(data))>>7)
#define  SCALEUP_DS_UZU_Bist_1_get_drf_bist_fail_2(data)                         ((0x00000040&(data))>>6)
#define  SCALEUP_DS_UZU_Bist_1_get_drf_bist_fail_1(data)                         ((0x00000020&(data))>>5)
#define  SCALEUP_DS_UZU_Bist_1_get_drf_bist_fail_0(data)                         ((0x00000010&(data))>>4)
#define  SCALEUP_DS_UZU_Bist_1_get_bist_fail_3(data)                             ((0x00000008&(data))>>3)
#define  SCALEUP_DS_UZU_Bist_1_get_bist_fail_2(data)                             ((0x00000004&(data))>>2)
#define  SCALEUP_DS_UZU_Bist_1_get_bist_fail_1(data)                             ((0x00000002&(data))>>1)
#define  SCALEUP_DS_UZU_Bist_1_get_bist_fail_0(data)                             (0x00000001&(data))

#define  SCALEUP_DS_UZU_Globle_Ctrl                                              0x18029B90
#define  SCALEUP_DS_UZU_Globle_Ctrl_reg_addr                                     "0xB8029B90"
#define  SCALEUP_DS_UZU_Globle_Ctrl_reg                                          0xB8029B90
#define  SCALEUP_DS_UZU_Globle_Ctrl_inst_addr                                    "0x00CA"
#define  set_SCALEUP_DS_UZU_Globle_Ctrl_reg(data)                                (*((volatile unsigned int*)SCALEUP_DS_UZU_Globle_Ctrl_reg)=data)
#define  get_SCALEUP_DS_UZU_Globle_Ctrl_reg                                      (*((volatile unsigned int*)SCALEUP_DS_UZU_Globle_Ctrl_reg))
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sync_shift                            (7)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_mode_shift                            (4)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_field_shift                           (1)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sel_shift                             (0)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sync_mask                             (0x00000080)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_mode_mask                             (0x00000070)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_field_mask                            (0x00000002)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sel_mask                              (0x00000001)
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sync(data)                            (0x00000080&((data)<<7))
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_mode(data)                            (0x00000070&((data)<<4))
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_field(data)                           (0x00000002&((data)<<1))
#define  SCALEUP_DS_UZU_Globle_Ctrl_patgen_sel(data)                             (0x00000001&(data))
#define  SCALEUP_DS_UZU_Globle_Ctrl_get_patgen_sync(data)                        ((0x00000080&(data))>>7)
#define  SCALEUP_DS_UZU_Globle_Ctrl_get_patgen_mode(data)                        ((0x00000070&(data))>>4)
#define  SCALEUP_DS_UZU_Globle_Ctrl_get_patgen_field(data)                       ((0x00000002&(data))>>1)
#define  SCALEUP_DS_UZU_Globle_Ctrl_get_patgen_sel(data)                         (0x00000001&(data))

#define  SCALEUP_DS_UZU_PATGEN_COLOR0                                            0x18029B94
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_reg_addr                                   "0xB8029B94"
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_reg                                        0xB8029B94
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_inst_addr                                  "0x00CB"
#define  set_SCALEUP_DS_UZU_PATGEN_COLOR0_reg(data)                              (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR0_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_COLOR0_reg                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR0_reg))
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_y_shift                          (16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cr_shift                         (8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cb_shift                         (0)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_y_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cr_mask                          (0x0000FF00)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cb_mask                          (0x000000FF)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_y(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cr(data)                         (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_patgen_c0_cb(data)                         (0x000000FF&(data))
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_get_patgen_c0_y(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_get_patgen_c0_cr(data)                     ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR0_get_patgen_c0_cb(data)                     (0x000000FF&(data))

#define  SCALEUP_DS_UZU_PATGEN_COLOR1                                            0x18029B98
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_reg_addr                                   "0xB8029B98"
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_reg                                        0xB8029B98
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_inst_addr                                  "0x00CC"
#define  set_SCALEUP_DS_UZU_PATGEN_COLOR1_reg(data)                              (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR1_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_COLOR1_reg                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR1_reg))
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_y_shift                          (16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cr_shift                         (8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cb_shift                         (0)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_y_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cr_mask                          (0x0000FF00)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cb_mask                          (0x000000FF)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_y(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cr(data)                         (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_patgen_c1_cb(data)                         (0x000000FF&(data))
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_get_patgen_c1_y(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_get_patgen_c1_cr(data)                     ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR1_get_patgen_c1_cb(data)                     (0x000000FF&(data))

#define  SCALEUP_DS_UZU_PATGEN_COLOR2                                            0x18029B9C
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_reg_addr                                   "0xB8029B9C"
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_reg                                        0xB8029B9C
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_inst_addr                                  "0x00CD"
#define  set_SCALEUP_DS_UZU_PATGEN_COLOR2_reg(data)                              (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR2_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_COLOR2_reg                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR2_reg))
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_y_shift                          (16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cr_shift                         (8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cb_shift                         (0)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_y_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cr_mask                          (0x0000FF00)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cb_mask                          (0x000000FF)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_y(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cr(data)                         (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_patgen_c2_cb(data)                         (0x000000FF&(data))
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_get_patgen_c2_y(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_get_patgen_c2_cr(data)                     ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR2_get_patgen_c2_cb(data)                     (0x000000FF&(data))

#define  SCALEUP_DS_UZU_PATGEN_COLOR3                                            0x18029BA0
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_reg_addr                                   "0xB8029BA0"
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_reg                                        0xB8029BA0
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_inst_addr                                  "0x00CE"
#define  set_SCALEUP_DS_UZU_PATGEN_COLOR3_reg(data)                              (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR3_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_COLOR3_reg                                    (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_COLOR3_reg))
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_y_shift                          (16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cr_shift                         (8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cb_shift                         (0)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_y_mask                           (0x00FF0000)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cr_mask                          (0x0000FF00)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cb_mask                          (0x000000FF)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_y(data)                          (0x00FF0000&((data)<<16))
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cr(data)                         (0x0000FF00&((data)<<8))
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_patgen_c3_cb(data)                         (0x000000FF&(data))
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_get_patgen_c3_y(data)                      ((0x00FF0000&(data))>>16)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_get_patgen_c3_cr(data)                     ((0x0000FF00&(data))>>8)
#define  SCALEUP_DS_UZU_PATGEN_COLOR3_get_patgen_c3_cb(data)                     (0x000000FF&(data))

#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE                                      0x18029BA4
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg_addr                             "0xB8029BA4"
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg                                  0xB8029BA4
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_inst_addr                            "0x00CF"
#define  set_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg(data)                        (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg                              (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_reg))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num_shift                 (27)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel_shift                 (25)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_width_shift                   (0)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num_mask                  (0xF8000000)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel_mask                  (0x06000000)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_width_mask                    (0x003FFFFF)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_num(data)                 (0xF8000000&((data)<<27))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_tog_sel(data)                 (0x06000000&((data)<<25))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_patgen_width(data)                   (0x003FFFFF&(data))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_get_patgen_tog_num(data)             ((0xF8000000&(data))>>27)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_get_patgen_tog_sel(data)             ((0x06000000&(data))>>25)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE_get_patgen_width(data)               (0x003FFFFF&(data))

#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1                                     0x18029BA8
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg_addr                            "0xB8029BA8"
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg                                 0xB8029BA8
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_inst_addr                           "0x00D0"
#define  set_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg(data)                       (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg                             (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_reg))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1_shift                (0)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1_mask                 (0x003FFFFF)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_patgen_width_1(data)                (0x003FFFFF&(data))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE1_get_patgen_width_1(data)            (0x003FFFFF&(data))

#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2                                     0x18029BAC
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg_addr                            "0xB8029BAC"
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg                                 0xB8029BAC
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_inst_addr                           "0x00D1"
#define  set_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg(data)                       (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg                             (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_reg))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2_shift                (0)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2_mask                 (0x003FFFFF)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_patgen_width_2(data)                (0x003FFFFF&(data))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE2_get_patgen_width_2(data)            (0x003FFFFF&(data))

#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3                                     0x18029BB0
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg_addr                            "0xB8029BB0"
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg                                 0xB8029BB0
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_inst_addr                           "0x00D2"
#define  set_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg(data)                       (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg)=data)
#define  get_SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg                             (*((volatile unsigned int*)SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_reg))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3_shift                (0)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3_mask                 (0x003FFFFF)
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_patgen_width_3(data)                (0x003FFFFF&(data))
#define  SCALEUP_DS_UZU_PATGEN_FRAME_TOGGLE3_get_patgen_width_3(data)            (0x003FFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SCALEUP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029000_31_16:16;
        RBus_UInt32  uzu_bypass_no_pwrsave:1;
        RBus_UInt32  uzu_bypass_force:1;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  out_even_black:1;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_lflag_en:1;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_sel:2;
    };
}scaleup_d_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_mode_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_pr_mode:2;
        RBus_UInt32  wd_main_buf_udf_en:1;
        RBus_UInt32  irq_main_buf_udf_en:1;
        RBus_UInt32  bypassfornr:1;
        RBus_UInt32  v_y_consttab_sel:2;
        RBus_UInt32  v_c_consttab_sel:2;
        RBus_UInt32  h_y_consttab_sel:2;
        RBus_UInt32  h_c_consttab_sel:2;
        RBus_UInt32  hor8_table_sel:2;
        RBus_UInt32  d_3d_sel_en:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaleup_dm_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}scaleup_dm_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}scaleup_dm_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hor_delta1:13;
    };
}scaleup_dm_uzu_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hor_delta2:13;
    };
}scaleup_dm_uzu_hor_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  hor_segment1:11;
    };
}scaleup_dm_uzu_hor_segment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  hor_segment2:11;
    };
}scaleup_dm_uzu_hor_segment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  hor_segment3:12;
    };
}scaleup_dm_uzu_hor_segment3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hflip_en:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaleup_dm_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_input_size:12;
    };
}scaleup_dm_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  level_flatness_coeff:3;
        RBus_UInt32  dering_dbg_mode:3;
        RBus_UInt32  h4h8_blend_range:2;
        RBus_UInt32  h4h8_blend_lowbound:8;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  h4h8_blend_en:1;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_lowbound:8;
    };
}scaleup_dm_uzu_8tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  dering_cross_lowbd:5;
        RBus_UInt32  dering_cross_en:1;
        RBus_UInt32  dering_cross_slope:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dering_edgelevel_gain:3;
    };
}scaleup_dm_uzu_8tap_dering_cross_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dering_gap_side_gain:4;
        RBus_UInt32  dering_gap_center_gain:3;
        RBus_UInt32  dering_gap_offset:4;
        RBus_UInt32  dering_gap_sidemode:1;
        RBus_UInt32  dering_h4h8_blend_type:2;
        RBus_UInt32  res1:18;
    };
}scaleup_dm_uzu_gap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_mask_c0:5;
        RBus_UInt32  pk_mask_c1:4;
        RBus_UInt32  pk_mask_c2:4;
        RBus_UInt32  pk_en:1;
        RBus_UInt32  pk_coring:8;
        RBus_UInt32  pk_x1:8;
    };
}scaleup_dm_uzu_peaking_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_mask_c3:4;
        RBus_UInt32  pk_shiftbit:2;
        RBus_UInt32  pk_offset:8;
        RBus_UInt32  pk_lmtp:4;
        RBus_UInt32  pk_lmtn:4;
        RBus_UInt32  pk_g1:4;
        RBus_UInt32  pk_g2:4;
    };
}scaleup_dm_uzu_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vcti_type3_thd:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcti_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcti_select:2;
        RBus_UInt32  vcti_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_dm_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_dm_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
    };
}scaleup_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaleup_mem_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaleup_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaleup_mem_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}scaleup_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_d_uzu_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uzu_crc:32;
    };
}scaleup_d_uzu_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_cb:8;
    };
}scaleup_d_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_cb:8;
    };
}scaleup_d_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_cb:8;
    };
}scaleup_d_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_cb:8;
    };
}scaleup_d_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_tog_num:5;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_lflag:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_width:22;
    };
}scaleup_d_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_1:22;
    };
}scaleup_d_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_2:22;
    };
}scaleup_d_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  patgen_lflag_3:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_width_3:22;
    };
}scaleup_d_uzu_patgen_frame_toggle3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}scaleup_accessdata_ctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  startx:12;
    };
}scaleup_accessdata_posctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}scaleup_readdata_data_y1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}scaleup_readdata_data_y2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}scaleup_readdata_data_c1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}scaleup_readdata_data_c2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}scaleup_readdata_data_c3_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}scaleup_readdata_data_c4_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_lbound2:10;
        RBus_UInt32  vcti_lpf_hbound2:10;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}scaleup_writedata_data_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_lbound1:10;
        RBus_UInt32  hor_m_front_drop:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  hor_m_back_drop:10;
    };
}scaleup_dm_uzumain_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcti_lpf_hbound1:10;
        RBus_UInt32  vcti_low_pass_filter_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  ver_m_front_drop:8;
        RBus_UInt32  ver_m_back_drop:8;
    };
}scaleup_dm_uzumain_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hor_m_front_drop_odd:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  hor_m_back_drop_odd:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pixel_drop_mode:1;
        RBus_UInt32  res4:2;
    };
}scaleup_dm_uzu_partial_drop_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_mid_drop_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_mid_drop_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_mid_drop_size:12;
    };
}scaleup_dm_uzu_partial_drop_mid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt8_upbnd:8;
        RBus_UInt32  adapt8_sec3:8;
        RBus_UInt32  adapt8_sec2:8;
        RBus_UInt32  adapt8_sec1:8;
    };
}scaleup_dm_uzumain_adapt8tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  res1:15;
        RBus_UInt32  usm_gain:6;
        RBus_UInt32  max_min_range:2;
        RBus_UInt32  max_minus_min_range:2;
        RBus_UInt32  max_minus_min_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  usm_en:1;
    };
}scaleup_dm_usm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  gain_curve_thd0:8;
        RBus_UInt32  gain_curve_thd1:8;
        RBus_UInt32  gain_curve_thd2:8;
    };
}scaleup_dm_usm_gain_curve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gain_curve_step0:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  gain_curve_step1:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  gain_curve_gain0:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  gain_curve_gain1:5;
    };
}scaleup_dm_usm_gain_curve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  limit_blend_thd0:8;
        RBus_UInt32  limit_blend_thd1:8;
    };
}scaleup_dm_usm_limit_blend_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  limit_blend_step:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  limit_blend_weight0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  limit_blend_weight1:5;
    };
}scaleup_dm_usm_limit_blend_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  usm_hlpf_c3:6;
        RBus_UInt32  usm_hlpf_c2:4;
        RBus_UInt32  usm_hlpf_c1:4;
        RBus_UInt32  usm_hlpf_c0:4;
    };
}scaleup_dm_usm_hlpf_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180290e0_31_4:28;
        RBus_UInt32  v6tap_table_sel:2;
        RBus_UInt32  ver_mode_sel:2;
    };
}scaleup_dm_uzu_v6ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptv6_upbnd:8;
        RBus_UInt32  adaptv6_sec3:8;
        RBus_UInt32  adaptv6_sec2:8;
        RBus_UInt32  adaptv6_sec1:8;
    };
}scaleup_dm_uzu_adaptv6ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  ver_ini_l:8;
    };
}scaleup_dm_uzu_initial_value_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  db_write_hold_cnt:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}scaleup_dm_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  buff_unf:1;
    };
}scaleup_dm_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  left_ydi:8;
        RBus_UInt32  left_udi:8;
        RBus_UInt32  left_vdi:8;
    };
}scaleup_left_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_h_saddr:8;
        RBus_UInt32  left_v_saddr:8;
        RBus_UInt32  left_h_limit:8;
        RBus_UInt32  left_v_limit:8;
    };
}scaleup_left_3d_ptg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_hsize:8;
        RBus_UInt32  left_vsize:8;
        RBus_UInt32  see_sadr_only_l:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  left_hstep:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  left_vstep:6;
    };
}scaleup_left_3d_ptg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  right_ydi:8;
        RBus_UInt32  right_udi:8;
        RBus_UInt32  right_vdi:8;
    };
}scaleup_right_3d_ptg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_h_saddr:8;
        RBus_UInt32  right_v_saddr:8;
        RBus_UInt32  right_h_limit:8;
        RBus_UInt32  right_v_limit:8;
    };
}scaleup_right_3d_ptg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_hsize:8;
        RBus_UInt32  right_vsize:8;
        RBus_UInt32  see_sadr_only_r:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  right_hstep:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  right_vstep:6;
    };
}scaleup_right_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ptg_bg_ydi:8;
        RBus_UInt32  ptg_bg_udi:8;
        RBus_UInt32  ptg_bg_vdi:8;
    };
}scaleup_ptg_3d_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  directionalscale_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ds_vlpf_en:1;
        RBus_UInt32  ds_hlpf_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  db_mode:4;
        RBus_UInt32  db_magfilter:4;
        RBus_UInt32  mag_ang_lpf_ratio:4;
        RBus_UInt32  dummy18029130_11_0:12;
    };
}scaleup_dm_dir_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  transang_sec3:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  transang_sec2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  transang_sec1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  transang_sec0:6;
    };
}scaleup_dm_dir_uzu_transang1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  transang_sec4:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  transang_step4:4;
        RBus_UInt32  transang_step3:4;
        RBus_UInt32  transang_step2:4;
        RBus_UInt32  transang_step1:4;
        RBus_UInt32  transang_step0:4;
    };
}scaleup_dm_dir_uzu_transang2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  angdiff_lowbnd:6;
        RBus_UInt32  res2:5;
        RBus_UInt32  angdiff_step:3;
        RBus_UInt32  mag_lowbnd:8;
        RBus_UInt32  res3:5;
        RBus_UInt32  mag_step:3;
    };
}scaleup_dm_dir_uzu_angmagscore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  onepx_en:1;
        RBus_UInt32  onepx_centerdiffthd:4;
        RBus_UInt32  onepx_sidediffthd:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  onepx_diffstep:3;
        RBus_UInt32  onepx_lowbnd:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  onepx_step:3;
        RBus_UInt32  res4:4;
    };
}scaleup_dm_dir_uzu_onepixeldetect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  angdiff_lowbnd2:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  angdiff_step2:3;
        RBus_UInt32  res3:4;
        RBus_UInt32  conf_step:3;
        RBus_UInt32  conf_offset:5;
        RBus_UInt32  conf_lowbnd:8;
    };
}scaleup_dm_dir_uzu_conf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  checkhv_angrange:4;
        RBus_UInt32  checkhv_en:1;
        RBus_UInt32  checkhv_angstep:3;
        RBus_UInt32  checkhv_diffstep:3;
        RBus_UInt32  checkhv_diffrange:5;
        RBus_UInt32  checkpn_angrange:4;
        RBus_UInt32  checkpn_en:1;
        RBus_UInt32  checkpn_angstep:3;
        RBus_UInt32  checkpn_diffstep:3;
        RBus_UInt32  checkpn_diffrange:5;
    };
}scaleup_dm_dir_uzu_anglecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}scaleup_dm_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
    };
}scaleup_dm_uzu_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_7:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}scaleup_dm_uzu_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_8:4;
    };
}scaleup_dm_uzu_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rm_0:4;
    };
}scaleup_dm_uzu_coef_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c32:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c33:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c34:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c35:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c36:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c37:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c38:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c39:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c40:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c41:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c42:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c43:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c44:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c45:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c46:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c47:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c48:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c49:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c50:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c51:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c52:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c53:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c54:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c55:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c56:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c57:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c58:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c59:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c60:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c61:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c62:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c63:12;
    };
}scaleup_dm_uzu_fir_coef_tab1_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c32:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c33:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c34:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c35:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c36:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c37:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c38:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c39:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c40:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c41:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c42:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c43:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c44:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c45:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c46:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c47:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c48:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c49:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c50:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c51:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c52:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c53:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c54:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c55:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c56:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c57:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c58:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c59:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c60:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c61:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c62:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c63:12;
    };
}scaleup_dm_uzu_fir_coef_tab2_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c1:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c3:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c5:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c7:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c9:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c11:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c13:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c15:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c17:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c19:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c21:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c23:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c25:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c27:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c29:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c31:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c32:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c33:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c34:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c35:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c36:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c37:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c38:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c39:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c40:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c41:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c42:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c43:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c44:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c45:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c46:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c47:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c48:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c49:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c50:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c51:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c52:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c53:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c54:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c55:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c56:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c57:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c58:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c59:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c60:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c61:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c62:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dir_tab_c63:12;
    };
}scaleup_dm_uzu_dir_coef_tab_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  coef_rw_sel:2;
    };
}scaleup_coef_table_rw_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  coef_addr:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  coef_write:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  coef_tab_sel:1;
    };
}scaleup_coef_table_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef1:12;
    };
}scaleup_coef_table_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef3:12;
    };
}scaleup_coef_table_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef5:12;
    };
}scaleup_coef_table_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  coef6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  coef7:12;
    };
}scaleup_coef_table_ctl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  wd_sub_buf_udf_en:1;
        RBus_UInt32  irq_sub_buf_udf_en:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  h_zoom_en:1;
    };
}scaleup_ds_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hor_factor:20;
    };
}scaleup_ds_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ver_factor:20;
    };
}scaleup_ds_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  ver_ini:8;
    };
}scaleup_ds_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:4;
        RBus_UInt32  ver_input_size:12;
    };
}scaleup_ds_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}scaleup_ds_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_ds_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  hor_s_front_drop:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_s_back_drop:11;
    };
}scaleup_ds_uzusub_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ver_s_front_drop:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  ver_s_back_drop:9;
    };
}scaleup_ds_uzusub_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
    };
}scaleup_ds_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  auto_cmp_en:1;
    };
}scaleup_ds_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc:32;
    };
}scaleup_ds_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_err_cnt:16;
    };
}scaleup_ds_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  buff_unf:1;
    };
}scaleup_ds_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c0:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c3:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c0_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c4:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c7:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c4_c7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c8:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c11:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c8_c11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c12:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c15:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c12_c15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c0:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c3:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c4:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c7:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c8:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c11:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c12:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c15:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}scaleup_ds_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}scaleup_ds_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_sel:1;
    };
}scaleup_ds_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_cb:8;
    };
}scaleup_ds_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_cb:8;
    };
}scaleup_ds_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_cb:8;
    };
}scaleup_ds_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_cb:8;
    };
}scaleup_ds_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_tog_num:5;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  patgen_width:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_1:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_2:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  patgen_width_3:22;
    };
}scaleup_ds_uzu_patgen_frame_toggle3_RBUS;

#else //apply LITTLE_ENDIAN

//======SCALEUP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_sel:2;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  patgen_lflag_en:1;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  out_even_black:1;
        RBus_UInt32  out_black_en:1;
        RBus_UInt32  in_even_black:1;
        RBus_UInt32  in_black_en:1;
        RBus_UInt32  lr_black_sel:1;
        RBus_UInt32  lr_black_en:1;
        RBus_UInt32  uzu_bypass_force:1;
        RBus_UInt32  uzu_bypass_no_pwrsave:1;
        RBus_UInt32  dummy18029000_31_16:16;
    };
}scaleup_d_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  d_3d_sel_en:1;
        RBus_UInt32  hor8_table_sel:2;
        RBus_UInt32  h_c_consttab_sel:2;
        RBus_UInt32  h_y_consttab_sel:2;
        RBus_UInt32  v_c_consttab_sel:2;
        RBus_UInt32  v_y_consttab_sel:2;
        RBus_UInt32  bypassfornr:1;
        RBus_UInt32  irq_main_buf_udf_en:1;
        RBus_UInt32  wd_main_buf_udf_en:1;
        RBus_UInt32  ver_pr_mode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_mode_sel:3;
    };
}scaleup_dm_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_dm_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_dm_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_delta1:13;
        RBus_UInt32  res1:19;
    };
}scaleup_dm_uzu_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_delta2:13;
        RBus_UInt32  res1:19;
    };
}scaleup_dm_uzu_hor_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment1:11;
        RBus_UInt32  res1:21;
    };
}scaleup_dm_uzu_hor_segment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment2:11;
        RBus_UInt32  res1:21;
    };
}scaleup_dm_uzu_hor_segment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_segment3:12;
        RBus_UInt32  res1:20;
    };
}scaleup_dm_uzu_hor_segment3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:12;
        RBus_UInt32  hflip_en:1;
        RBus_UInt32  res2:3;
    };
}scaleup_dm_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_blend_lowbound:8;
        RBus_UInt32  lpf_blend_range:2;
        RBus_UInt32  lpf_blend_en:1;
        RBus_UInt32  h4h8_blend_en:1;
        RBus_UInt32  level_maxmin_coeff:3;
        RBus_UInt32  lpf_blend_mask_sel:1;
        RBus_UInt32  h4h8_blend_lowbound:8;
        RBus_UInt32  h4h8_blend_range:2;
        RBus_UInt32  dering_dbg_mode:3;
        RBus_UInt32  level_flatness_coeff:3;
    };
}scaleup_dm_uzu_8tap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dering_edgelevel_gain:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dering_cross_slope:3;
        RBus_UInt32  dering_cross_en:1;
        RBus_UInt32  dering_cross_lowbd:5;
        RBus_UInt32  res2:19;
    };
}scaleup_dm_uzu_8tap_dering_cross_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  dering_h4h8_blend_type:2;
        RBus_UInt32  dering_gap_sidemode:1;
        RBus_UInt32  dering_gap_offset:4;
        RBus_UInt32  dering_gap_center_gain:3;
        RBus_UInt32  dering_gap_side_gain:4;
    };
}scaleup_dm_uzu_gap_dering_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pk_x1:8;
        RBus_UInt32  pk_coring:8;
        RBus_UInt32  pk_en:1;
        RBus_UInt32  pk_mask_c2:4;
        RBus_UInt32  pk_mask_c1:4;
        RBus_UInt32  pk_mask_c0:5;
        RBus_UInt32  res1:2;
    };
}scaleup_dm_uzu_peaking_coring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pk_g2:4;
        RBus_UInt32  pk_g1:4;
        RBus_UInt32  pk_lmtn:4;
        RBus_UInt32  pk_lmtp:4;
        RBus_UInt32  pk_offset:8;
        RBus_UInt32  pk_shiftbit:2;
        RBus_UInt32  pk_mask_c3:4;
        RBus_UInt32  res1:2;
    };
}scaleup_dm_uzu_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vcti_en:1;
        RBus_UInt32  vcti_select:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcti_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcti_type3_thd:6;
        RBus_UInt32  res4:10;
    };
}scaleup_dm_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_dm_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  res1:29;
    };
}scaleup_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}scaleup_mem_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}scaleup_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}scaleup_mem_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}scaleup_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  res1:29;
    };
}scaleup_d_uzu_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uzu_crc:32;
    };
}scaleup_d_uzu_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c0_cb:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_cb:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c2_cb:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_cb:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_d_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag:1;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_tog_num:5;
    };
}scaleup_d_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_1:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_1:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_2:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_2:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_3:22;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_lflag_3:1;
        RBus_UInt32  res2:7;
    };
}scaleup_d_uzu_patgen_frame_toggle3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  ch_sel:1;
        RBus_UInt32  res1:29;
    };
}scaleup_accessdata_ctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  starty:12;
        RBus_UInt32  res2:4;
    };
}scaleup_accessdata_posctrl_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_y1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_y2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c1_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c2_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c3_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}scaleup_readdata_data_c4_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  vcti_lpf_hbound2:10;
        RBus_UInt32  vcti_lpf_lbound2:10;
    };
}scaleup_writedata_data_uzu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_m_back_drop:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  hor_m_front_drop:10;
        RBus_UInt32  vcti_lpf_lbound1:10;
    };
}scaleup_dm_uzumain_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_m_back_drop:8;
        RBus_UInt32  ver_m_front_drop:8;
        RBus_UInt32  res1:5;
        RBus_UInt32  vcti_low_pass_filter_en:1;
        RBus_UInt32  vcti_lpf_hbound1:10;
    };
}scaleup_dm_uzumain_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pixel_drop_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_m_back_drop_odd:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  hor_m_front_drop_odd:10;
        RBus_UInt32  res4:6;
    };
}scaleup_dm_uzu_partial_drop_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_mid_drop_size:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  m_mid_drop_sta:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_mid_drop_en:1;
    };
}scaleup_dm_uzu_partial_drop_mid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt8_sec1:8;
        RBus_UInt32  adapt8_sec2:8;
        RBus_UInt32  adapt8_sec3:8;
        RBus_UInt32  adapt8_upbnd:8;
    };
}scaleup_dm_uzumain_adapt8tap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usm_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  max_minus_min_mode:1;
        RBus_UInt32  max_minus_min_range:2;
        RBus_UInt32  max_min_range:2;
        RBus_UInt32  usm_gain:6;
        RBus_UInt32  res2:15;
        RBus_UInt32  debug_mode:3;
    };
}scaleup_dm_usm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_thd2:8;
        RBus_UInt32  gain_curve_thd1:8;
        RBus_UInt32  gain_curve_thd0:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  gain_curve_en:1;
    };
}scaleup_dm_usm_gain_curve_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_curve_gain1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  gain_curve_gain0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  gain_curve_step1:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  gain_curve_step0:3;
        RBus_UInt32  res4:5;
    };
}scaleup_dm_usm_gain_curve_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_thd1:8;
        RBus_UInt32  limit_blend_thd0:8;
        RBus_UInt32  res1:15;
        RBus_UInt32  limit_blend_en:1;
    };
}scaleup_dm_usm_limit_blend_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_blend_weight1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  limit_blend_weight0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  limit_blend_step:3;
        RBus_UInt32  res3:13;
    };
}scaleup_dm_usm_limit_blend_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  usm_hlpf_c0:4;
        RBus_UInt32  usm_hlpf_c1:4;
        RBus_UInt32  usm_hlpf_c2:4;
        RBus_UInt32  usm_hlpf_c3:6;
        RBus_UInt32  res1:14;
    };
}scaleup_dm_usm_hlpf_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_mode_sel:2;
        RBus_UInt32  v6tap_table_sel:2;
        RBus_UInt32  dummy180290e0_31_4:28;
    };
}scaleup_dm_uzu_v6ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptv6_sec1:8;
        RBus_UInt32  adaptv6_sec2:8;
        RBus_UInt32  adaptv6_sec3:8;
        RBus_UInt32  adaptv6_upbnd:8;
    };
}scaleup_dm_uzu_adaptv6ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  res1:16;
    };
}scaleup_dm_uzu_initial_value_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  db_write_hold_cnt:4;
        RBus_UInt32  res2:24;
    };
}scaleup_dm_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  res1:31;
    };
}scaleup_dm_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_vdi:8;
        RBus_UInt32  left_udi:8;
        RBus_UInt32  left_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_left_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_v_limit:8;
        RBus_UInt32  left_h_limit:8;
        RBus_UInt32  left_v_saddr:8;
        RBus_UInt32  left_h_saddr:8;
    };
}scaleup_left_3d_ptg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_vstep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  left_hstep:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  see_sadr_only_l:1;
        RBus_UInt32  left_vsize:8;
        RBus_UInt32  left_hsize:8;
    };
}scaleup_left_3d_ptg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_vdi:8;
        RBus_UInt32  right_udi:8;
        RBus_UInt32  right_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_right_3d_ptg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_v_limit:8;
        RBus_UInt32  right_h_limit:8;
        RBus_UInt32  right_v_saddr:8;
        RBus_UInt32  right_h_saddr:8;
    };
}scaleup_right_3d_ptg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  right_vstep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  right_hstep:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  see_sadr_only_r:1;
        RBus_UInt32  right_vsize:8;
        RBus_UInt32  right_hsize:8;
    };
}scaleup_right_3d_ptg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ptg_bg_vdi:8;
        RBus_UInt32  ptg_bg_udi:8;
        RBus_UInt32  ptg_bg_ydi:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ptg_3d_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029130_11_0:12;
        RBus_UInt32  mag_ang_lpf_ratio:4;
        RBus_UInt32  db_magfilter:4;
        RBus_UInt32  db_mode:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  ds_hlpf_en:1;
        RBus_UInt32  ds_vlpf_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  directionalscale_en:1;
    };
}scaleup_dm_dir_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  transang_sec0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  transang_sec1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  transang_sec2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  transang_sec3:7;
        RBus_UInt32  res4:1;
    };
}scaleup_dm_dir_uzu_transang1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  transang_step0:4;
        RBus_UInt32  transang_step1:4;
        RBus_UInt32  transang_step2:4;
        RBus_UInt32  transang_step3:4;
        RBus_UInt32  transang_step4:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  transang_sec4:7;
        RBus_UInt32  res2:1;
    };
}scaleup_dm_dir_uzu_transang2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mag_step:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  mag_lowbnd:8;
        RBus_UInt32  angdiff_step:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  angdiff_lowbnd:6;
        RBus_UInt32  res3:2;
    };
}scaleup_dm_dir_uzu_angmagscore_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  onepx_step:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  onepx_lowbnd:8;
        RBus_UInt32  onepx_diffstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  onepx_sidediffthd:4;
        RBus_UInt32  onepx_centerdiffthd:4;
        RBus_UInt32  onepx_en:1;
        RBus_UInt32  res4:3;
    };
}scaleup_dm_dir_uzu_onepixeldetect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  conf_lowbnd:8;
        RBus_UInt32  conf_offset:5;
        RBus_UInt32  conf_step:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  angdiff_step2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  angdiff_lowbnd2:6;
        RBus_UInt32  res3:2;
    };
}scaleup_dm_dir_uzu_conf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  checkpn_diffrange:5;
        RBus_UInt32  checkpn_diffstep:3;
        RBus_UInt32  checkpn_angstep:3;
        RBus_UInt32  checkpn_en:1;
        RBus_UInt32  checkpn_angrange:4;
        RBus_UInt32  checkhv_diffrange:5;
        RBus_UInt32  checkhv_diffstep:3;
        RBus_UInt32  checkhv_angstep:3;
        RBus_UInt32  checkhv_en:1;
        RBus_UInt32  checkhv_angrange:4;
    };
}scaleup_dm_dir_uzu_anglecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_2:1;
        RBus_UInt32  bist_fail_3:1;
        RBus_UInt32  bist_fail_4:1;
        RBus_UInt32  bist_fail_5:1;
        RBus_UInt32  bist_fail_6:1;
        RBus_UInt32  bist_fail_7:1;
        RBus_UInt32  bist_fail_8:1;
        RBus_UInt32  bist_fail_9:1;
        RBus_UInt32  bist_fail_10:1;
        RBus_UInt32  bist_fail_11:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  drf_bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_1:1;
        RBus_UInt32  drf_bist_fail_2:1;
        RBus_UInt32  drf_bist_fail_3:1;
        RBus_UInt32  drf_bist_fail_4:1;
        RBus_UInt32  drf_bist_fail_5:1;
        RBus_UInt32  drf_bist_fail_6:1;
        RBus_UInt32  drf_bist_fail_7:1;
        RBus_UInt32  drf_bist_fail_8:1;
        RBus_UInt32  drf_bist_fail_9:1;
        RBus_UInt32  drf_bist_fail_10:1;
        RBus_UInt32  drf_bist_fail_11:1;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_9:1;
        RBus_UInt32  rme_10:1;
        RBus_UInt32  rme_11:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  res2:15;
    };
}scaleup_dm_uzu_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_7:4;
    };
}scaleup_dm_uzu_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_8:4;
        RBus_UInt32  rm_9:4;
        RBus_UInt32  rm_10:4;
        RBus_UInt32  rm_11:4;
        RBus_UInt32  res1:16;
    };
}scaleup_dm_uzu_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  drf_bist_fail_0:1;
    };
}scaleup_dm_uzu_coef_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c33:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c32:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c35:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c34:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c37:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c36:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c39:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c38:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c41:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c40:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c43:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c42:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c45:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c44:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c47:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c46:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c49:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c48:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c51:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c50:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c53:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c52:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c55:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c54:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c57:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c56:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c59:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c58:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c61:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c60:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c63:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c62:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab1_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c33:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c32:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c35:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c34:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c37:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c36:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c39:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c38:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c41:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c40:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c43:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c42:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c45:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c44:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c47:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c46:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c49:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c48:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c51:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c50:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c53:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c52:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c55:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c54:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c57:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c56:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c59:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c58:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c61:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c60:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c63:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c62:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_fir_coef_tab2_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c0:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c2:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c4:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c6:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c8:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c10:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c12:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c14:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c16:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c18:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c20:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c22:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c24:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c26:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c28:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c30:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c33:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c32:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c35:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c34:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c37:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c36:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c36_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c39:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c38:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c38_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c41:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c40:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c43:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c42:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c42_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c45:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c44:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c44_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c47:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c46:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c46_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c49:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c48:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c48_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c51:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c50:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c53:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c52:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c52_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c55:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c54:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c54_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c57:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c56:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c56_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c59:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c58:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c58_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c61:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c60:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir_tab_c63:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_tab_c62:12;
        RBus_UInt32  res2:4;
    };
}scaleup_dm_uzu_dir_coef_tab_c62_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_rw_sel:2;
        RBus_UInt32  res1:30;
    };
}scaleup_coef_table_rw_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_tab_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  coef_write:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  coef_addr:5;
        RBus_UInt32  res3:19;
    };
}scaleup_coef_table_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef0:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef2:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef4:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  coef6:12;
        RBus_UInt32  res2:4;
    };
}scaleup_coef_table_ctl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  conv_type:1;
        RBus_UInt32  in_fmt_conv:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  in_fmt_dup:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  irq_sub_buf_udf_en:1;
        RBus_UInt32  wd_sub_buf_udf_en:1;
        RBus_UInt32  res2:7;
    };
}scaleup_ds_uzu_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_ds_uzu_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  res1:12;
    };
}scaleup_ds_uzu_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res1:16;
    };
}scaleup_ds_uzu_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_input_size:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hor_input_size:13;
        RBus_UInt32  res2:3;
    };
}scaleup_ds_uzu_input_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:30;
    };
}scaleup_ds_mem_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_crc:32;
    };
}scaleup_ds_mem_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_s_back_drop:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  hor_s_front_drop:11;
        RBus_UInt32  res2:9;
    };
}scaleup_ds_uzusub_h_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_s_back_drop:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  ver_s_front_drop:9;
        RBus_UInt32  res2:7;
    };
}scaleup_ds_uzusub_v_partial_drop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  res1:29;
    };
}scaleup_ds_uzu_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_cmp_en:1;
        RBus_UInt32  res1:31;
    };
}scaleup_ds_mem_crc_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_crc:32;
    };
}scaleup_ds_mem_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_err_cnt:16;
        RBus_UInt32  res1:16;
    };
}scaleup_ds_mem_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buff_unf:1;
        RBus_UInt32  res1:31;
    };
}scaleup_ds_uzu_wclr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c3:8;
        RBus_UInt32  ver_c2:8;
        RBus_UInt32  ver_c1:8;
        RBus_UInt32  ver_c0:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c0_c3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c7:8;
        RBus_UInt32  ver_c6:8;
        RBus_UInt32  ver_c5:8;
        RBus_UInt32  ver_c4:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c4_c7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c11:8;
        RBus_UInt32  ver_c10:8;
        RBus_UInt32  ver_c9:8;
        RBus_UInt32  ver_c8:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c8_c11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_c15:8;
        RBus_UInt32  ver_c14:8;
        RBus_UInt32  ver_c13:8;
        RBus_UInt32  ver_c12:8;
    };
}scaleup_ds_uzu_fir_coef_ver_c12_c15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c3:8;
        RBus_UInt32  hor_c2:8;
        RBus_UInt32  hor_c1:8;
        RBus_UInt32  hor_c0:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c7:8;
        RBus_UInt32  hor_c6:8;
        RBus_UInt32  hor_c5:8;
        RBus_UInt32  hor_c4:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c11:8;
        RBus_UInt32  hor_c10:8;
        RBus_UInt32  hor_c9:8;
        RBus_UInt32  hor_c8:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c15:8;
        RBus_UInt32  hor_c14:8;
        RBus_UInt32  hor_c13:8;
        RBus_UInt32  hor_c12:8;
    };
}scaleup_ds_uzu_fir_coef_hor_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}scaleup_ds_uzu_bist_0_RBUS;

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
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
    };
}scaleup_ds_uzu_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_sel:1;
        RBus_UInt32  patgen_field:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_mode:3;
        RBus_UInt32  patgen_sync:1;
        RBus_UInt32  res2:24;
    };
}scaleup_ds_uzu_globle_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c0_cb:8;
        RBus_UInt32  patgen_c0_cr:8;
        RBus_UInt32  patgen_c0_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c1_cb:8;
        RBus_UInt32  patgen_c1_cr:8;
        RBus_UInt32  patgen_c1_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c2_cb:8;
        RBus_UInt32  patgen_c2_cr:8;
        RBus_UInt32  patgen_c2_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_c3_cb:8;
        RBus_UInt32  patgen_c3_cr:8;
        RBus_UInt32  patgen_c3_y:8;
        RBus_UInt32  res1:8;
    };
}scaleup_ds_uzu_patgen_color3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width:22;
        RBus_UInt32  res1:3;
        RBus_UInt32  patgen_tog_sel:2;
        RBus_UInt32  patgen_tog_num:5;
    };
}scaleup_ds_uzu_patgen_frame_toggle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_1:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_2:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_width_3:22;
        RBus_UInt32  res1:10;
    };
}scaleup_ds_uzu_patgen_frame_toggle3_RBUS;




#endif 


#endif 
