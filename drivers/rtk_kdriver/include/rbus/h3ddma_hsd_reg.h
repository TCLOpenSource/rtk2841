/**
* @file MacArthur5-DesignSpec-I-Domain_IDMA_HSD
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_H3DDMA_HSD_REG_H_
#define _RBUS_H3DDMA_HSD_REG_H_

#include "rbus_types.h"



//  H3DDMA_HSD Register Address
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0                                             0x18025900
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg_addr                                    "0xB8025900"
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg                                         0xB8025900
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_inst_addr                                   "0x0000"
#define  set_H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg(data)                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg                                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_3d_sel_en_shift                           (3)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_y_table_sel_shift                         (2)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_c_table_sel_shift                         (1)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_zoom_en_shift                             (0)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_3d_sel_en_mask                            (0x00000008)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_y_table_sel_mask                          (0x00000004)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_c_table_sel_mask                          (0x00000002)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_zoom_en_mask                              (0x00000001)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_3d_sel_en(data)                           (0x00000008&((data)<<3))
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_y_table_sel(data)                         (0x00000004&((data)<<2))
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_c_table_sel(data)                         (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_h_zoom_en(data)                             (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_get_h_3d_sel_en(data)                       ((0x00000008&(data))>>3)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_get_h_y_table_sel(data)                     ((0x00000004&(data))>>2)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_get_h_c_table_sel(data)                     ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_HSD_Ctrl0_get_h_zoom_en(data)                         (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor                                  0x18025904
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg_addr                         "0xB8025904"
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg                              0xB8025904
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_inst_addr                        "0x0001"
#define  set_H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_hor_fac_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_hor_fac_mask                     (0x01FFFFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_hor_fac(data)                    (0x01FFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_get_hor_fac(data)                (0x01FFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value                                     0x18025908
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg_addr                            "0xB8025908"
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg                                 0xB8025908
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_inst_addr                           "0x0002"
#define  set_H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg(data)                       (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg                             (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini_l_shift                     (8)
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini_shift                       (0)
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini_l_mask                      (0x0000FF00)
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini_mask                        (0x000000FF)
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini_l(data)                     (0x0000FF00&((data)<<8))
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_hor_ini(data)                       (0x000000FF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_get_hor_ini_l(data)                 ((0x0000FF00&(data))>>8)
#define  H3DDMA_HSD_I3DDMA_HSD_Initial_Value_get_hor_ini(data)                   (0x000000FF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1                                        0x1802590C
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg_addr                               "0xB802590C"
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg                                    0xB802590C
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_inst_addr                              "0x0003"
#define  set_H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg(data)                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg                                (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_nl_d1_shift                            (0)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_nl_d1_mask                             (0x00003FFF)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_nl_d1(data)                            (0x00003FFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_get_nl_d1(data)                        (0x00003FFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment                                       0x18025910
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg_addr                              "0xB8025910"
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg                                   0xB8025910
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_inst_addr                             "0x0004"
#define  set_H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg(data)                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg1_shift                         (16)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg2_shift                         (0)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg1_mask                          (0x1FFF0000)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg2_mask                          (0x00001FFF)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg1(data)                         (0x1FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_nl_seg2(data)                         (0x00001FFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_get_nl_seg1(data)                     ((0x1FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_get_nl_seg2(data)                     (0x00001FFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL                                          0x18025914
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg_addr                                 "0xB8025914"
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg                                      0xB8025914
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_inst_addr                                "0x0005"
#define  set_H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg(data)                            (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg                                  (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_crc_3d_en_shift                          (4)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_r_auto_cmp_en_shift                      (3)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_l_auto_cmp_en_shift                      (2)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_conti_shift                  (1)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_start_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_crc_3d_en_mask                           (0x00000010)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_r_auto_cmp_en_mask                       (0x00000008)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_l_auto_cmp_en_mask                       (0x00000004)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_conti_mask                   (0x00000002)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_start_mask                   (0x00000001)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_crc_3d_en(data)                          (0x00000010&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_r_auto_cmp_en(data)                      (0x00000008&((data)<<3))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_l_auto_cmp_en(data)                      (0x00000004&((data)<<2))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_conti(data)                  (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_ch1_hsd_crc_start(data)                  (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_get_crc_3d_en(data)                      ((0x00000010&(data))>>4)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_get_r_auto_cmp_en(data)                  ((0x00000008&(data))>>3)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_get_l_auto_cmp_en(data)                  ((0x00000004&(data))>>2)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_get_ch1_hsd_crc_conti(data)              ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_CTRL_get_ch1_hsd_crc_start(data)              (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left                                   0x18025918
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg_addr                          "0xB8025918"
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg                               0xB8025918
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_inst_addr                         "0x0006"
#define  set_H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg(data)                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_ch1_hsd_crc_l_result_shift        (0)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_ch1_hsd_crc_l_result_mask         (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_ch1_hsd_crc_l_result(data)        (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_left_get_ch1_hsd_crc_l_result(data)    (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result                                        0x1802591C
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg_addr                               "0xB802591C"
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg                                    0xB802591C
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_inst_addr                              "0x0007"
#define  set_H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg(data)                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg                                (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_Result_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_ch1_hsd_crc_r_result_shift             (0)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_ch1_hsd_crc_r_result_mask              (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_ch1_hsd_crc_r_result(data)             (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_Result_get_ch1_hsd_crc_r_result(data)         (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC                                         0x18025920
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg_addr                                "0xB8025920"
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg                                     0xB8025920
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_inst_addr                               "0x0008"
#define  set_H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg(data)                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg                                 (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_l_des_crc_shift                         (0)
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_l_des_crc_mask                          (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_l_des_crc(data)                         (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_L_DES_CRC_get_l_des_crc(data)                     (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC                                         0x18025924
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg_addr                                "0xB8025924"
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg                                     0xB8025924
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_inst_addr                               "0x0009"
#define  set_H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg(data)                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg                                 (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_r_des_crc_shift                         (0)
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_r_des_crc_mask                          (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_r_des_crc(data)                         (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_R_DES_CRC_get_r_des_crc(data)                     (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT                                       0x18025928
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg_addr                              "0xB8025928"
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg                                   0xB8025928
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_inst_addr                             "0x000A"
#define  set_H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg(data)                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_reg))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_r_crc_err_cnt_shift                   (16)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_l_crc_err_cnt_shift                   (0)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_r_crc_err_cnt_mask                    (0xFFFF0000)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_l_crc_err_cnt_mask                    (0x0000FFFF)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_r_crc_err_cnt(data)                   (0xFFFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_l_crc_err_cnt(data)                   (0x0000FFFF&(data))
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_get_r_crc_err_cnt(data)               ((0xFFFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_HSD_CRC_ERR_CNT_get_l_crc_err_cnt(data)               (0x0000FFFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0                                  0x1802592C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg_addr                         "0xB802592C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg                              0xB802592C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_inst_addr                        "0x000B"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c0_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c1_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c0_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c1_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c0(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_tab1_c1(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_get_tab1_c0(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_get_tab1_c1(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2                                  0x18025930
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg_addr                         "0xB8025930"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg                              0xB8025930
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_inst_addr                        "0x000C"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c2_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c3_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c2_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c3_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c2(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_tab1_c3(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_get_tab1_c2(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C2_get_tab1_c3(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4                                  0x18025934
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg_addr                         "0xB8025934"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg                              0xB8025934
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_inst_addr                        "0x000D"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c4_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c5_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c4_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c5_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c4(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_tab1_c5(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_get_tab1_c4(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C4_get_tab1_c5(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6                                  0x18025938
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg_addr                         "0xB8025938"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg                              0xB8025938
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_inst_addr                        "0x000E"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c6_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c7_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c6_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c7_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c6(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_tab1_c7(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_get_tab1_c6(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C6_get_tab1_c7(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8                                  0x1802593C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg_addr                         "0xB802593C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg                              0xB802593C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_inst_addr                        "0x000F"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c8_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c9_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c8_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c9_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c8(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_tab1_c9(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_get_tab1_c8(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C8_get_tab1_c9(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10                                 0x18025940
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg_addr                        "0xB8025940"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg                             0xB8025940
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_inst_addr                       "0x0010"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c10_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c11_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c10_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c11_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c10(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_tab1_c11(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_get_tab1_c10(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C10_get_tab1_c11(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12                                 0x18025944
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg_addr                        "0xB8025944"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg                             0xB8025944
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_inst_addr                       "0x0011"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c12_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c13_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c12_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c13_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c12(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_tab1_c13(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_get_tab1_c12(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C12_get_tab1_c13(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14                                 0x18025948
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg_addr                        "0xB8025948"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg                             0xB8025948
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_inst_addr                       "0x0012"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c14_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c15_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c14_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c15_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c14(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_tab1_c15(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_get_tab1_c14(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C14_get_tab1_c15(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16                                 0x1802594C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg_addr                        "0xB802594C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg                             0xB802594C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_inst_addr                       "0x0013"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c16_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c17_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c16_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c17_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c16(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_tab1_c17(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_get_tab1_c16(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C16_get_tab1_c17(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18                                 0x18025950
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg_addr                        "0xB8025950"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg                             0xB8025950
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_inst_addr                       "0x0014"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c18_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c19_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c18_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c19_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c18(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_tab1_c19(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_get_tab1_c18(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C18_get_tab1_c19(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20                                 0x18025954
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg_addr                        "0xB8025954"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg                             0xB8025954
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_inst_addr                       "0x0015"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c20_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c21_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c20_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c21_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c20(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_tab1_c21(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_get_tab1_c20(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C20_get_tab1_c21(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22                                 0x18025958
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg_addr                        "0xB8025958"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg                             0xB8025958
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_inst_addr                       "0x0016"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c22_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c23_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c22_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c23_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c22(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_tab1_c23(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_get_tab1_c22(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C22_get_tab1_c23(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24                                 0x1802595C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg_addr                        "0xB802595C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg                             0xB802595C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_inst_addr                       "0x0017"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c24_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c25_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c24_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c25_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c24(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_tab1_c25(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_get_tab1_c24(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C24_get_tab1_c25(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26                                 0x18025960
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg_addr                        "0xB8025960"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg                             0xB8025960
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_inst_addr                       "0x0018"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c26_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c27_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c26_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c27_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c26(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_tab1_c27(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_get_tab1_c26(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C26_get_tab1_c27(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28                                 0x18025964
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg_addr                        "0xB8025964"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg                             0xB8025964
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_inst_addr                       "0x0019"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c28_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c29_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c28_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c29_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c28(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_tab1_c29(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_get_tab1_c28(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C28_get_tab1_c29(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30                                 0x18025968
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg_addr                        "0xB8025968"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg                             0xB8025968
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_inst_addr                       "0x001A"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c30_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c31_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c30_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c31_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c30(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_tab1_c31(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_get_tab1_c30(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C30_get_tab1_c31(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0                                  0x1802596C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg_addr                         "0xB802596C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg                              0xB802596C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_inst_addr                        "0x001B"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c0_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c1_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c0_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c1_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c0(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_tab2_c1(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_get_tab2_c0(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_get_tab2_c1(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2                                  0x18025970
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg_addr                         "0xB8025970"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg                              0xB8025970
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_inst_addr                        "0x001C"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c2_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c3_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c2_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c3_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c2(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_tab2_c3(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_get_tab2_c2(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C2_get_tab2_c3(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4                                  0x18025974
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg_addr                         "0xB8025974"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg                              0xB8025974
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_inst_addr                        "0x001D"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c4_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c5_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c4_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c5_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c4(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_tab2_c5(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_get_tab2_c4(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C4_get_tab2_c5(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6                                  0x18025978
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg_addr                         "0xB8025978"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg                              0xB8025978
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_inst_addr                        "0x001E"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c6_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c7_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c6_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c7_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c6(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_tab2_c7(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_get_tab2_c6(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C6_get_tab2_c7(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8                                  0x1802597C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg_addr                         "0xB802597C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg                              0xB802597C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_inst_addr                        "0x001F"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c8_shift                    (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c9_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c8_mask                     (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c9_mask                     (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c8(data)                    (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_tab2_c9(data)                    (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_get_tab2_c8(data)                ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C8_get_tab2_c9(data)                (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10                                 0x18025980
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg_addr                        "0xB8025980"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg                             0xB8025980
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_inst_addr                       "0x0020"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c10_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c11_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c10_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c11_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c10(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_tab2_c11(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_get_tab2_c10(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C10_get_tab2_c11(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12                                 0x18025984
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg_addr                        "0xB8025984"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg                             0xB8025984
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_inst_addr                       "0x0021"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c12_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c13_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c12_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c13_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c12(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_tab2_c13(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_get_tab2_c12(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C12_get_tab2_c13(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14                                 0x18025988
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg_addr                        "0xB8025988"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg                             0xB8025988
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_inst_addr                       "0x0022"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c14_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c15_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c14_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c15_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c14(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_tab2_c15(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_get_tab2_c14(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C14_get_tab2_c15(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16                                 0x1802598C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg_addr                        "0xB802598C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg                             0xB802598C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_inst_addr                       "0x0023"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c16_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c17_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c16_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c17_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c16(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_tab2_c17(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_get_tab2_c16(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C16_get_tab2_c17(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18                                 0x18025990
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg_addr                        "0xB8025990"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg                             0xB8025990
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_inst_addr                       "0x0024"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c18_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c19_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c18_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c19_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c18(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_tab2_c19(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_get_tab2_c18(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C18_get_tab2_c19(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20                                 0x18025994
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg_addr                        "0xB8025994"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg                             0xB8025994
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_inst_addr                       "0x0025"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c20_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c21_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c20_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c21_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c20(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_tab2_c21(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_get_tab2_c20(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C20_get_tab2_c21(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22                                 0x18025998
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg_addr                        "0xB8025998"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg                             0xB8025998
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_inst_addr                       "0x0026"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c22_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c23_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c22_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c23_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c22(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_tab2_c23(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_get_tab2_c22(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C22_get_tab2_c23(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24                                 0x1802599C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg_addr                        "0xB802599C"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg                             0xB802599C
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_inst_addr                       "0x0027"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c24_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c25_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c24_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c25_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c24(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_tab2_c25(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_get_tab2_c24(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C24_get_tab2_c25(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26                                 0x180259A0
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg_addr                        "0xB80259A0"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg                             0xB80259A0
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_inst_addr                       "0x0028"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c26_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c27_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c26_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c27_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c26(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_tab2_c27(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_get_tab2_c26(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C26_get_tab2_c27(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28                                 0x180259A4
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg_addr                        "0xB80259A4"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg                             0xB80259A4
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_inst_addr                       "0x0029"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c28_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c29_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c28_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c29_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c28(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_tab2_c29(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_get_tab2_c28(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C28_get_tab2_c29(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30                                 0x180259A8
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg_addr                        "0xB80259A8"
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg                             0xB80259A8
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_inst_addr                       "0x002A"
#define  set_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c30_shift                  (16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c31_shift                  (0)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c30_mask                   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c31_mask                   (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c30(data)                  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_tab2_c31(data)                  (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_get_tab2_c30(data)              ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C30_get_tab2_c31(data)              (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL                                             0x180259AC
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg_addr                                    "0xB80259AC"
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg                                         0xB80259AC
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_inst_addr                                   "0x002B"
#define  set_H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg(data)                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg                                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_H_DB_CTRL_reg))
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_apply_shift                            (6)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_rd_sel_shift                           (5)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_en_shift                               (4)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_apply_mask                             (0x00000040)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_rd_sel_mask                            (0x00000020)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_en_mask                                (0x00000010)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_apply(data)                            (0x00000040&((data)<<6))
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_rd_sel(data)                           (0x00000020&((data)<<5))
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_h_db_en(data)                               (0x00000010&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_get_h_db_apply(data)                        ((0x00000040&(data))>>6)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_get_h_db_rd_sel(data)                       ((0x00000020&(data))>>5)
#define  H3DDMA_HSD_I3DDMA_H_DB_CTRL_get_h_db_en(data)                           ((0x00000010&(data))>>4)

#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0                                             0x18025600
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg_addr                                    "0xB8025600"
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg                                         0xB8025600
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_inst_addr                                   "0x002C"
#define  set_H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg(data)                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg                                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_truncationctrl_shift                        (24)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_dummy_data_shift                       (16)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_dummy_15_14_shift                           (14)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_swap_shift                             (13)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_rgb_to_argb_en_shift                        (12)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_video_comp_en_shift                         (11)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_odd_inv_shift                               (10)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_out_bit_shift                               (9)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_sort_fmt_shift                              (8)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_y_table_sel_shift                         (7)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_c_table_sel_shift                         (6)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_buffer_mode_shift                           (2)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_zoom_en_shift                             (1)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_truncationctrl_mask                         (0x01000000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_dummy_data_mask                        (0x00FF0000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_dummy_15_14_mask                            (0x0000C000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_swap_mask                              (0x00002000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_rgb_to_argb_en_mask                         (0x00001000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_video_comp_en_mask                          (0x00000800)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_odd_inv_mask                                (0x00000400)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_out_bit_mask                                (0x00000200)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_sort_fmt_mask                               (0x00000100)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_y_table_sel_mask                          (0x00000080)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_c_table_sel_mask                          (0x00000040)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_buffer_mode_mask                            (0x0000000C)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_zoom_en_mask                              (0x00000002)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_truncationctrl(data)                        (0x01000000&((data)<<24))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_dummy_data(data)                       (0x00FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_dummy_15_14(data)                           (0x0000C000&((data)<<14))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_argb_swap(data)                             (0x00002000&((data)<<13))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_rgb_to_argb_en(data)                        (0x00001000&((data)<<12))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_video_comp_en(data)                         (0x00000800&((data)<<11))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_odd_inv(data)                               (0x00000400&((data)<<10))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_out_bit(data)                               (0x00000200&((data)<<9))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_sort_fmt(data)                              (0x00000100&((data)<<8))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_y_table_sel(data)                         (0x00000080&((data)<<7))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_c_table_sel(data)                         (0x00000040&((data)<<6))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_buffer_mode(data)                           (0x0000000C&((data)<<2))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_v_zoom_en(data)                             (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_truncationctrl(data)                    ((0x01000000&(data))>>24)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_argb_dummy_data(data)                   ((0x00FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_dummy_15_14(data)                       ((0x0000C000&(data))>>14)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_argb_swap(data)                         ((0x00002000&(data))>>13)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_rgb_to_argb_en(data)                    ((0x00001000&(data))>>12)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_video_comp_en(data)                     ((0x00000800&(data))>>11)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_odd_inv(data)                           ((0x00000400&(data))>>10)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_out_bit(data)                           ((0x00000200&(data))>>9)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_sort_fmt(data)                          ((0x00000100&(data))>>8)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_v_y_table_sel(data)                     ((0x00000080&(data))>>7)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_v_c_table_sel(data)                     ((0x00000040&(data))>>6)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_buffer_mode(data)                       ((0x0000000C&(data))>>2)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl0_get_v_zoom_en(data)                         ((0x00000002&(data))>>1)

#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1                                             0x18025604
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg_addr                                    "0xB8025604"
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg                                         0xB8025604
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_inst_addr                                   "0x002D"
#define  set_H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg(data)                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg                                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Ctrl1_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_lp121_en_shift                              (25)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_boundary_shift                       (3)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_mode_shift                           (0)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_lp121_en_mask                               (0x02000000)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_boundary_mask                        (0x0000FFF8)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_mode_mask                            (0x00000003)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_lp121_en(data)                              (0x02000000&((data)<<25))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_boundary(data)                       (0x0000FFF8&((data)<<3))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_vsd_3d_mode(data)                           (0x00000003&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_get_lp121_en(data)                          ((0x02000000&(data))>>25)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_get_vsd_3d_boundary(data)                   ((0x0000FFF8&(data))>>3)
#define  H3DDMA_HSD_I3DDMA_VSD_Ctrl1_get_vsd_3d_mode(data)                       (0x00000003&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor                                  0x18025608
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg_addr                         "0xB8025608"
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg                              0xB8025608
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_inst_addr                        "0x002E"
#define  set_H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int_l_shift              (26)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int_shift                (25)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_fac_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int_l_mask               (0x04000000)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int_mask                 (0x02000000)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_fac_mask                     (0x01FFFFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int_l(data)              (0x04000000&((data)<<26))
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_ini_int(data)                (0x02000000&((data)<<25))
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_ver_fac(data)                    (0x01FFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_get_ver_ini_int_l(data)          ((0x04000000&(data))>>26)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_get_ver_ini_int(data)            ((0x02000000&(data))>>25)
#define  H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_get_ver_fac(data)                (0x01FFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value                                     0x1802560C
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg_addr                            "0xB802560C"
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg                                 0xB802560C
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_inst_addr                           "0x002F"
#define  set_H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg(data)                       (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg                             (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini_l_shift                     (16)
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini_shift                       (0)
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini_l_mask                      (0x00FF0000)
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini_mask                        (0x000000FF)
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini_l(data)                     (0x00FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_ver_ini(data)                       (0x000000FF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_get_ver_ini_l(data)                 ((0x00FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_VSD_Initial_Value_get_ver_ini(data)                   (0x000000FF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL                                          0x18025610
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg_addr                                 "0xB8025610"
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg                                      0xB8025610
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_inst_addr                                "0x0030"
#define  set_H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg(data)                            (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg                                  (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_r_auto_cmp_en_shift                      (4)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_l_auto_cmp_en_shift                      (3)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_conti_shift                              (1)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_start_shift                              (0)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_r_auto_cmp_en_mask                       (0x00000010)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_l_auto_cmp_en_mask                       (0x00000008)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_conti_mask                               (0x00000002)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_start_mask                               (0x00000001)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_r_auto_cmp_en(data)                      (0x00000010&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_l_auto_cmp_en(data)                      (0x00000008&((data)<<3))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_conti(data)                              (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_start(data)                              (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_get_r_auto_cmp_en(data)                  ((0x00000010&(data))>>4)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_get_l_auto_cmp_en(data)                  ((0x00000008&(data))>>3)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_get_conti(data)                          ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_CTRL_get_start(data)                          (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result                                        0x18025614
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg_addr                               "0xB8025614"
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg                                    0xB8025614
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_inst_addr                              "0x0031"
#define  set_H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg(data)                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg                                (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_Result_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_crc_l_result_shift                     (0)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_crc_l_result_mask                      (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_crc_l_result(data)                     (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_get_crc_l_result(data)                 (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right                                  0x18025618
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg_addr                         "0xB8025618"
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg                              0xB8025618
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_inst_addr                        "0x0032"
#define  set_H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_crc_r_result_shift               (0)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_crc_r_result_mask                (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_crc_r_result(data)               (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_Result_right_get_crc_r_result(data)           (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC                                         0x1802561C
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg_addr                                "0xB802561C"
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg                                     0xB802561C
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_inst_addr                               "0x0033"
#define  set_H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg(data)                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg                                 (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_l_des_crc_shift                         (0)
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_l_des_crc_mask                          (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_l_des_crc(data)                         (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_L_DES_CRC_get_l_des_crc(data)                     (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC                                         0x18025620
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg_addr                                "0xB8025620"
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg                                     0xB8025620
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_inst_addr                               "0x0034"
#define  set_H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg(data)                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg                                 (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_r_des_crc_shift                         (0)
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_r_des_crc_mask                          (0xFFFFFFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_r_des_crc(data)                         (0xFFFFFFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_R_DES_CRC_get_r_des_crc(data)                     (0xFFFFFFFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT                                       0x18025624
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg_addr                              "0xB8025624"
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg                                   0xB8025624
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_inst_addr                             "0x0035"
#define  set_H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg(data)                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_r_crc_err_cnt_shift                   (16)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_l_crc_err_cnt_shift                   (0)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_r_crc_err_cnt_mask                    (0xFFFF0000)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_l_crc_err_cnt_mask                    (0x0000FFFF)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_r_crc_err_cnt(data)                   (0xFFFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_l_crc_err_cnt(data)                   (0x0000FFFF&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_get_r_crc_err_cnt(data)               ((0xFFFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_VSD_CRC_ERR_CNT_get_l_crc_err_cnt(data)               (0x0000FFFF&(data))

#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL                                 0x18025628
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg_addr                        "0xB8025628"
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg                             0xB8025628
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_inst_addr                       "0x0036"
#define  set_H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg(data)                   (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_reg))
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size_shift               (16)
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size_shift               (0)
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size_mask                (0x1FFF0000)
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size_mask                (0x00001FFF)
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_v_size(data)               (0x1FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_ibuf_h_size(data)               (0x00001FFF&(data))
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_get_ibuf_v_size(data)           ((0x1FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_IBUFF_CTRLI_BUFF_CTRL_get_ibuf_h_size(data)           (0x00001FFF&(data))

#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap                                      0x1802562C
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg_addr                             "0xB802562C"
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg                                  0xB802562C
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_inst_addr                            "0x0037"
#define  set_H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg(data)                        (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg                              (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_VSD_channel_swap_reg))
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb565_en_shift                      (3)
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb_ch_swap_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb565_en_mask                       (0x00000008)
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb_ch_swap_mask                     (0x00000007)
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb565_en(data)                      (0x00000008&((data)<<3))
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_rgb_ch_swap(data)                    (0x00000007&(data))
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_get_rgb565_en(data)                  ((0x00000008&(data))>>3)
#define  H3DDMA_HSD_I3DDMA_VSD_channel_swap_get_rgb_ch_swap(data)                (0x00000007&(data))

#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL                                             0x18025630
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg_addr                                    "0xB8025630"
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg                                         0xB8025630
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_inst_addr                                   "0x0038"
#define  set_H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg(data)                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg                                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_V_DB_CTRL_reg))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_6_shift                               (6)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_5_shift                               (5)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_4_shift                               (4)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_apply_shift                            (2)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_rd_sel_shift                           (1)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_en_shift                               (0)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_6_mask                                (0x00000040)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_5_mask                                (0x00000020)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_4_mask                                (0x00000010)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_apply_mask                             (0x00000004)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_rd_sel_mask                            (0x00000002)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_en_mask                                (0x00000001)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_6(data)                               (0x00000040&((data)<<6))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_5(data)                               (0x00000020&((data)<<5))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_dummy_4(data)                               (0x00000010&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_apply(data)                            (0x00000004&((data)<<2))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_rd_sel(data)                           (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_v_db_en(data)                               (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_dummy_6(data)                           ((0x00000040&(data))>>6)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_dummy_5(data)                           ((0x00000020&(data))>>5)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_dummy_4(data)                           ((0x00000010&(data))>>4)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_v_db_apply(data)                        ((0x00000004&(data))>>2)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_v_db_rd_sel(data)                       ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_V_DB_CTRL_get_v_db_en(data)                           (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS                                          0x18025680
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg_addr                                 "0xB8025680"
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg                                      0xB8025680
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_inst_addr                                "0x0039"
#define  set_H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg(data)                            (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg                                  (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_STATUS_reg))
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_1_shift                            (1)
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_0_shift                            (0)
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_1_mask                             (0x00000002)
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_0_mask                             (0x00000001)
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_1(data)                            (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_dummy_0(data)                            (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_get_dummy_1(data)                        ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_IBUFF_STATUS_get_dummy_0(data)                        (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL                                        0x18025684
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg_addr                               "0xB8025684"
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg                                    0xB8025684
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_inst_addr                              "0x003A"
#define  set_H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg(data)                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg                                (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_reg))
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_1_shift                          (1)
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_0_shift                          (0)
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_1_mask                           (0x00000002)
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_0_mask                           (0x00000001)
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_1(data)                          (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_dummy_0(data)                          (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_get_dummy_1(data)                      ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_IBUFF_DRF_FAIL_get_dummy_0(data)                      (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS                                       0x18025688
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg_addr                              "0xB8025688"
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg                                   0xB8025688
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_inst_addr                             "0x003B"
#define  set_H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg(data)                         (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg                               (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_reg))
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_bisr_linebuff_fail_0_shift            (0)
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_bisr_linebuff_fail_0_mask             (0x00000001)
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_bisr_linebuff_fail_0(data)            (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_STATUS_get_bisr_linebuff_fail_0(data)        (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL                                     0x1802568C
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg_addr                            "0xB802568C"
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg                                 0xB802568C
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_inst_addr                           "0x003C"
#define  set_H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg(data)                       (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg                             (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_reg))
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_linebuff_drf_fail_0_shift           (0)
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_linebuff_drf_fail_0_mask            (0x00000001)
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_linebuff_drf_fail_0(data)           (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_LINEBUFF_DRF_FAIL_get_linebuff_drf_fail_0(data)       (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF                                          0x18025690
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg_addr                                 "0xB8025690"
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg                                      0xB8025690
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_inst_addr                                "0x003D"
#define  set_H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg(data)                            (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg                                  (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_reg))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_ls_en_shift                      (31)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_20_shift                           (20)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_19_16_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_12_shift                           (12)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_11_8_shift                         (8)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvse_shift                   (4)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvs_shift                    (0)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_ls_en_mask                       (0x80000000)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_20_mask                            (0x00100000)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_19_16_mask                         (0x000F0000)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_12_mask                            (0x00001000)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_11_8_mask                          (0x00000F00)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvse_mask                    (0x00000010)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvs_mask                     (0x0000000F)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_ls_en(data)                      (0x80000000&((data)<<31))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_20(data)                           (0x00100000&((data)<<20))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_19_16(data)                        (0x000F0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_12(data)                           (0x00001000&((data)<<12))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_dummy_11_8(data)                         (0x00000F00&((data)<<8))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvse(data)                   (0x00000010&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_linebuf_drf_dvs(data)                    (0x0000000F&(data))
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_linebuf_ls_en(data)                  ((0x80000000&(data))>>31)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_dummy_20(data)                       ((0x00100000&(data))>>20)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_dummy_19_16(data)                    ((0x000F0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_dummy_12(data)                       ((0x00001000&(data))>>12)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_dummy_11_8(data)                     ((0x00000F00&(data))>>8)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_linebuf_drf_dvse(data)               ((0x00000010&(data))>>4)
#define  H3DDMA_HSD_I3DDMA_UZD_SRAM_DRF_get_linebuf_drf_dvs(data)                (0x0000000F&(data))

#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL                                     0x180256A0
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg_addr                            "0xB80256A0"
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg                                 0xB80256A0
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_inst_addr                           "0x003E"
#define  set_H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg(data)                       (*((volatile unsigned int*)H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg)=data)
#define  get_H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg                             (*((volatile unsigned int*)H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_reg))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_en_shift                 (31)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_mode_shift               (30)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_blend_sel_shift          (16)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cbcr_swap_en_shift                  (3)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cr_dly_cb_shift                     (2)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_drop_shift                          (1)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_dummy_0_shift                       (0)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_en_mask                  (0x80000000)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_mode_mask                (0x40000000)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_blend_sel_mask           (0x00FF0000)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cbcr_swap_en_mask                   (0x00000008)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cr_dly_cb_mask                      (0x00000004)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_drop_mask                           (0x00000002)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_dummy_0_mask                        (0x00000001)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_en(data)                 (0x80000000&((data)<<31))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_mode(data)               (0x40000000&((data)<<30))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_i3ddma_420_blend_sel(data)          (0x00FF0000&((data)<<16))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cbcr_swap_en(data)                  (0x00000008&((data)<<3))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_cr_dly_cb(data)                     (0x00000004&((data)<<2))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_drop(data)                          (0x00000002&((data)<<1))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_dummy_0(data)                       (0x00000001&(data))
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_i3ddma_420_en(data)             ((0x80000000&(data))>>31)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_i3ddma_420_mode(data)           ((0x40000000&(data))>>30)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_i3ddma_420_blend_sel(data)      ((0x00FF0000&(data))>>16)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_cbcr_swap_en(data)              ((0x00000008&(data))>>3)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_cr_dly_cb(data)                 ((0x00000004&(data))>>2)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_drop(data)                      ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_i3ddma_uzd_444to422_CTRL_get_dummy_0(data)                   (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path                         0x180256B0
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg_addr                "0xB80256B0"
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg                     0xB80256B0
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_inst_addr               "0x003F"
#define  set_H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg(data)           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg                 (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_reg))
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_en_shift         (31)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ihs_mode_shift        (30)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_odd_shift  (16)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_even_shift (0)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_en_mask          (0x80000000)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ihs_mode_mask         (0x40000000)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_odd_mask   (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_even_mask  (0x00000FFF)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_en(data)         (0x80000000&((data)<<31))
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ihs_mode(data)        (0x40000000&((data)<<30))
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_odd(data)  (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_m_ivst_value_even(data) (0x00000FFF&(data))
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_get_m_ivst_en(data)     ((0x80000000&(data))>>31)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_get_m_ihs_mode(data)    ((0x40000000&(data))>>30)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_get_m_ivst_value_odd(data) ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_Measure_IVST_Result_Main_Path_get_m_ivst_value_even(data) (0x00000FFF&(data))

#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path                        0x180256B4
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg_addr               "0xB80256B4"
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg                    0xB80256B4
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_inst_addr              "0x0040"
#define  set_H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg(data)          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg                (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_reg))
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_active_line_pixel_en_shift (31)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_vactive_line_value_shift (16)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_hactive_hpixel_value_shift (0)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_active_line_pixel_en_mask (0x80000000)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_vactive_line_value_mask (0x0FFF0000)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_hactive_hpixel_value_mask (0x00001FFF)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_active_line_pixel_en(data) (0x80000000&((data)<<31))
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_vactive_line_value(data) (0x0FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_m_hactive_hpixel_value(data) (0x00001FFF&(data))
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_get_m_active_line_pixel_en(data) ((0x80000000&(data))>>31)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_get_m_vactive_line_value(data) ((0x0FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_Measure_ActLinePixel_Main_Path_get_m_hactive_hpixel_value(data) (0x00001FFF&(data))

#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD                                   0x180256C0
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg_addr                          "0xB80256C0"
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg                               0xB80256C0
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_inst_addr                         "0x0041"
#define  set_H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg(data)                     (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg                           (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_write_en_shift                    (1)
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_read_en_shift                     (0)
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_write_en_mask                     (0x00000002)
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_read_en_mask                      (0x00000001)
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_write_en(data)                    (0x00000002&((data)<<1))
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_read_en(data)                     (0x00000001&(data))
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_get_write_en(data)                ((0x00000002&(data))>>1)
#define  H3DDMA_HSD_I3DDMA_AccessData_CTRL_UZD_get_read_en(data)                 (0x00000001&(data))

#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD                                0x180256C4
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg_addr                       "0xB80256C4"
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg                            0xB80256C4
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_inst_addr                      "0x0042"
#define  set_H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg(data)                  (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg                        (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_starty_shift                   (16)
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_startx_shift                   (0)
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_starty_mask                    (0x1FFF0000)
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_startx_mask                    (0x00001FFF)
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_starty(data)                   (0x1FFF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_startx(data)                   (0x00001FFF&(data))
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_get_starty(data)               ((0x1FFF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_AccessData_PosCtrl_UZD_get_startx(data)               (0x00001FFF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD                                  0x180256C8
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg_addr                         "0xB80256C8"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg                              0xB80256C8
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_inst_addr                        "0x0043"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y01_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y00_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y01_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y00_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y01(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_y00(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_get_y01(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y1_UZD_get_y00(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD                                  0x180256CC
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg_addr                         "0xB80256CC"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg                              0xB80256CC
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_inst_addr                        "0x0044"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y11_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y10_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y11_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y10_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y11(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_y10(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_get_y11(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_Y2_UZD_get_y10(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD                                  0x180256D0
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg_addr                         "0xB80256D0"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg                              0xB80256D0
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_inst_addr                        "0x0045"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_v00_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_u00_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_v00_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_u00_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_v00(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_u00(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_get_v00(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C1_UZD_get_u00(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD                                  0x180256D4
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg_addr                         "0xB80256D4"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg                              0xB80256D4
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_inst_addr                        "0x0046"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_v01_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_u01_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_v01_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_u01_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_v01(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_u01(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_get_v01(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C2_UZD_get_u01(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD                                  0x180256D8
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg_addr                         "0xB80256D8"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg                              0xB80256D8
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_inst_addr                        "0x0047"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_v10_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_u10_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_v10_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_u10_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_v10(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_u10(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_get_v10(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C3_UZD_get_u10(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD                                  0x180256DC
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg_addr                         "0xB80256DC"
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg                              0xB80256DC
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_inst_addr                        "0x0048"
#define  set_H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg(data)                    (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg                          (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_v11_shift                        (16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_u11_shift                        (0)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_v11_mask                         (0x03FF0000)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_u11_mask                         (0x000003FF)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_v11(data)                        (0x03FF0000&((data)<<16))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_u11(data)                        (0x000003FF&(data))
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_get_v11(data)                    ((0x03FF0000&(data))>>16)
#define  H3DDMA_HSD_I3DDMA_ReadData_DATA_C4_UZD_get_u11(data)                    (0x000003FF&(data))

#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD                                    0x180256E0
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg_addr                           "0xB80256E0"
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg                                0xB80256E0
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_inst_addr                          "0x0049"
#define  set_H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg(data)                      (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg)=data)
#define  get_H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg                            (*((volatile unsigned int*)H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_reg))
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_v_shift                            (8)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_u_shift                            (4)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_y_shift                            (0)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_v_mask                             (0x00000F00)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_u_mask                             (0x000000F0)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_y_mask                             (0x0000000F)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_v(data)                            (0x00000F00&((data)<<8))
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_u(data)                            (0x000000F0&((data)<<4))
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_y(data)                            (0x0000000F&(data))
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_get_v(data)                        ((0x00000F00&(data))>>8)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_get_u(data)                        ((0x000000F0&(data))>>4)
#define  H3DDMA_HSD_I3DDMA_WriteData_DATA_UZD_get_y(data)                        (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======H3DDMA_HSD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_zoom_en:1;
    };
}h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hor_fac:25;
    };
}h3ddma_hsd_i3ddma_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  hor_ini:8;
    };
}h3ddma_hsd_i3ddma_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  nl_d1:14;
    };
}h3ddma_hsd_i3ddma_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  nl_seg1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  nl_seg2:13;
    };
}h3ddma_hsd_i3ddma_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  ch1_hsd_crc_start:1;
    };
}h3ddma_hsd_i3ddma_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}h3ddma_hsd_i3ddma_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}h3ddma_hsd_i3ddma_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}h3ddma_hsd_i3ddma_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}h3ddma_hsd_i3ddma_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}h3ddma_hsd_i3ddma_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c1:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c3:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c5:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c7:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c9:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c11:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c13:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c15:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c17:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c19:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c21:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c23:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c25:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c27:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c29:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab1_c31:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c1:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c3:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c5:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c7:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c9:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c11:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c13:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c15:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c17:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c19:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c21:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c23:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c25:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c27:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c29:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  tab2_c31:12;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}h3ddma_hsd_i3ddma_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  dummy18025600_15_14:2;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res6:1;
    };
}h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res3:1;
        RBus_UInt32  vsd_3d_mode:2;
    };
}h3ddma_hsd_i3ddma_vsd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_fac:25;
    };
}h3ddma_hsd_i3ddma_vsd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  ver_ini:8;
    };
}h3ddma_hsd_i3ddma_vsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  start:1;
    };
}h3ddma_hsd_i3ddma_vsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}h3ddma_hsd_i3ddma_vsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}h3ddma_hsd_i3ddma_vsd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}h3ddma_hsd_i3ddma_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}h3ddma_hsd_i3ddma_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_crc_err_cnt:16;
        RBus_UInt32  l_crc_err_cnt:16;
    };
}h3ddma_hsd_i3ddma_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ibuf_h_size:13;
    };
}h3ddma_hsd_i3ddma_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  rgb_ch_swap:3;
    };
}h3ddma_hsd_i3ddma_vsd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dummy18025630_6:1;
        RBus_UInt32  dummy18025630_5:1;
        RBus_UInt32  dummy18025630_4:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_en:1;
    };
}h3ddma_hsd_i3ddma_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dummy18025680_1:1;
        RBus_UInt32  dummy18025680_0:1;
    };
}h3ddma_hsd_i3ddma_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dummy18025684_1:1;
        RBus_UInt32  dummy18025684_0:1;
    };
}h3ddma_hsd_i3ddma_ibuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bisr_linebuff_fail_0:1;
    };
}h3ddma_hsd_i3ddma_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  linebuff_drf_fail_0:1;
    };
}h3ddma_hsd_i3ddma_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuf_ls_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18025690_20:1;
        RBus_UInt32  dummy18025690_19_16:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18025690_12:1;
        RBus_UInt32  dummy18025690_11_8:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  linebuf_drf_dvs:4;
    };
}h3ddma_hsd_i3ddma_uzd_sram_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_420_en:1;
        RBus_UInt32  i3ddma_420_mode:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  i3ddma_420_blend_sel:8;
        RBus_UInt32  res2:12;
        RBus_UInt32  cbcr_swap_en:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  dummy180256a0_0:1;
    };
}h3ddma_hsd_i3ddma_uzd_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_ivst_en:1;
        RBus_UInt32  m_ihs_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m_ivst_value_odd:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  m_ivst_value_even:12;
    };
}h3ddma_hsd_i3ddma_measure_ivst_result_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_active_line_pixel_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_vactive_line_value:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_hactive_hpixel_value:13;
    };
}h3ddma_hsd_i3ddma_measure_actlinepixel_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}h3ddma_hsd_i3ddma_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  startx:13;
    };
}h3ddma_hsd_i3ddma_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}h3ddma_hsd_i3ddma_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}h3ddma_hsd_i3ddma_writedata_data_uzd_RBUS;

#else //apply LITTLE_ENDIAN

//======H3DDMA_HSD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  h_c_table_sel:1;
        RBus_UInt32  h_y_table_sel:1;
        RBus_UInt32  h_3d_sel_en:1;
        RBus_UInt32  res1:28;
    };
}h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_fac:25;
        RBus_UInt32  res1:7;
    };
}h3ddma_hsd_i3ddma_hsd_scale_hor_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  hor_ini_l:8;
        RBus_UInt32  res1:16;
    };
}h3ddma_hsd_i3ddma_hsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_d1:14;
        RBus_UInt32  res1:18;
    };
}h3ddma_hsd_i3ddma_hsd_hor_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl_seg2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  nl_seg1:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_hsd_i3ddma_hsd_hor_segment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_start:1;
        RBus_UInt32  ch1_hsd_crc_conti:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  crc_3d_en:1;
        RBus_UInt32  res1:27;
    };
}h3ddma_hsd_i3ddma_hsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_l_result:32;
    };
}h3ddma_hsd_i3ddma_hsd_crc_result_left_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_hsd_crc_r_result:32;
    };
}h3ddma_hsd_i3ddma_hsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}h3ddma_hsd_i3ddma_hsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}h3ddma_hsd_i3ddma_hsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}h3ddma_hsd_i3ddma_hsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c0:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c2:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c4:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c6:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c8:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c10:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c12:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c14:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c16:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c18:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c20:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c22:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c24:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c26:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c28:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab1_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab1_c30:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab1_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c0:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c2:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c4:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c7:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c6:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c9:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c8:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c11:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c10:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c13:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c12:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c15:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c14:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c17:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c16:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c19:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c18:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c21:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c20:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c23:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c22:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c25:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c24:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c27:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c26:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c29:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c28:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tab2_c31:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  tab2_c30:12;
        RBus_UInt32  res2:4;
    };
}h3ddma_hsd_i3ddma_uzd_fir_coef_tab2_c30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  h_db_en:1;
        RBus_UInt32  h_db_rd_sel:1;
        RBus_UInt32  h_db_apply:1;
        RBus_UInt32  res5:25;
    };
}h3ddma_hsd_i3ddma_h_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  buffer_mode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  v_c_table_sel:1;
        RBus_UInt32  v_y_table_sel:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  odd_inv:1;
        RBus_UInt32  video_comp_en:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  dummy18025600_15_14:2;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  truncationctrl:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:3;
    };
}h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsd_3d_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  vsd_3d_boundary:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  lp121_en:1;
        RBus_UInt32  res3:6;
    };
}h3ddma_hsd_i3ddma_vsd_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_fac:25;
        RBus_UInt32  ver_ini_int:1;
        RBus_UInt32  ver_ini_int_l:1;
        RBus_UInt32  res1:5;
    };
}h3ddma_hsd_i3ddma_vsd_scale_ver_factor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ver_ini_l:8;
        RBus_UInt32  res2:8;
    };
}h3ddma_hsd_i3ddma_vsd_initial_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  conti:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  l_auto_cmp_en:1;
        RBus_UInt32  r_auto_cmp_en:1;
        RBus_UInt32  res2:27;
    };
}h3ddma_hsd_i3ddma_vsd_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}h3ddma_hsd_i3ddma_vsd_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}h3ddma_hsd_i3ddma_vsd_crc_result_right_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_des_crc:32;
    };
}h3ddma_hsd_i3ddma_vsd_l_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_des_crc:32;
    };
}h3ddma_hsd_i3ddma_vsd_r_des_crc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_err_cnt:16;
        RBus_UInt32  r_crc_err_cnt:16;
    };
}h3ddma_hsd_i3ddma_vsd_crc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ibuf_h_size:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ibuf_v_size:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_hsd_i3ddma_ibuff_ctrli_buff_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb_ch_swap:3;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  res1:28;
    };
}h3ddma_hsd_i3ddma_vsd_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_db_en:1;
        RBus_UInt32  v_db_rd_sel:1;
        RBus_UInt32  v_db_apply:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy18025630_4:1;
        RBus_UInt32  dummy18025630_5:1;
        RBus_UInt32  dummy18025630_6:1;
        RBus_UInt32  res2:25;
    };
}h3ddma_hsd_i3ddma_v_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025680_0:1;
        RBus_UInt32  dummy18025680_1:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_hsd_i3ddma_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18025684_0:1;
        RBus_UInt32  dummy18025684_1:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_hsd_i3ddma_ibuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_linebuff_fail_0:1;
        RBus_UInt32  res1:31;
    };
}h3ddma_hsd_i3ddma_linebuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuff_drf_fail_0:1;
        RBus_UInt32  res1:31;
    };
}h3ddma_hsd_i3ddma_linebuff_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linebuf_drf_dvs:4;
        RBus_UInt32  linebuf_drf_dvse:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18025690_11_8:4;
        RBus_UInt32  dummy18025690_12:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dummy18025690_19_16:4;
        RBus_UInt32  dummy18025690_20:1;
        RBus_UInt32  res3:10;
        RBus_UInt32  linebuf_ls_en:1;
    };
}h3ddma_hsd_i3ddma_uzd_sram_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180256a0_0:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  cr_dly_cb:1;
        RBus_UInt32  cbcr_swap_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  i3ddma_420_blend_sel:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  i3ddma_420_mode:1;
        RBus_UInt32  i3ddma_420_en:1;
    };
}h3ddma_hsd_i3ddma_uzd_444to422_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_ivst_value_even:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  m_ivst_value_odd:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  m_ihs_mode:1;
        RBus_UInt32  m_ivst_en:1;
    };
}h3ddma_hsd_i3ddma_measure_ivst_result_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m_hactive_hpixel_value:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  m_vactive_line_value:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  m_active_line_pixel_en:1;
    };
}h3ddma_hsd_i3ddma_measure_actlinepixel_main_path_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_hsd_i3ddma_accessdata_ctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  starty:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_hsd_i3ddma_accessdata_posctrl_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_y1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_y2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_c1_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_c2_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_c3_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}h3ddma_hsd_i3ddma_readdata_data_c4_uzd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}h3ddma_hsd_i3ddma_writedata_data_uzd_RBUS;




#endif 


#endif 
