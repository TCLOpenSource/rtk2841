/**
* @file rbusHDMIpatternGenReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HDMIPATTERNGEN_REG_H_
#define _RBUS_HDMIPATTERNGEN_REG_H_

#include "rbus_types.h"



//  HDMIPATTERNGEN Register Address
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV                                         0x1800D800
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg_addr                                "0xB800D800"
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg                                     0xB800D800
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_inst_addr                               "0x0000"
#define  set_HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg(data)                           (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg                                 (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TOTALHV_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalh_pixel_shift                      (16)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_dummy_15_13_shift                       (13)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalv_line_shift                       (0)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalh_pixel_mask                       (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_dummy_15_13_mask                        (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalv_line_mask                        (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalh_pixel(data)                      (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_dummy_15_13(data)                       (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_totalv_line(data)                       (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_get_totalh_pixel(data)                  ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_get_dummy_15_13(data)                   ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_TOTALHV_get_totalv_line(data)                   (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width                               0x1800D804
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg_addr                      "0xB800D804"
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg                           0xB800D804
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_inst_addr                     "0x0001"
#define  set_HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg(data)                 (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_h_sta_shift               (16)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_dummy_15_13_shift             (13)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_wid_shift                 (0)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_h_sta_mask                (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_dummy_15_13_mask              (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_wid_mask                  (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_h_sta(data)               (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_dummy_15_13(data)             (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_act_wid(data)                 (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_get_act_h_sta(data)           ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_get_dummy_15_13(data)         ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_H_Start_Width_get_act_wid(data)             (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length                              0x1800D808
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg_addr                     "0xB800D808"
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg                          0xB800D808
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_inst_addr                    "0x0002"
#define  set_HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg(data)                (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg                      (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_v_sta_shift              (16)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_dummy_15_13_shift            (13)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_len_shift                (0)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_v_sta_mask               (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_dummy_15_13_mask             (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_len_mask                 (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_v_sta(data)              (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_dummy_15_13(data)            (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_act_len(data)                (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_get_act_v_sta(data)          ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_get_dummy_15_13(data)        ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_ACT_V_Start_Length_get_act_len(data)            (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_TG                                              0x1800D80C
#define  HDMIPATTERNGEN_HDMI_PTG_TG_reg_addr                                     "0xB800D80C"
#define  HDMIPATTERNGEN_HDMI_PTG_TG_reg                                          0xB800D80C
#define  HDMIPATTERNGEN_HDMI_PTG_TG_inst_addr                                    "0x0003"
#define  set_HDMIPATTERNGEN_HDMI_PTG_TG_reg(data)                                (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TG_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_TG_reg                                      (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TG_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_cs_sel_shift                                 (28)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_demo_4k2k_en_shift                           (13)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_sync_timing_sel_shift                        (12)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover_en_shift                           (11)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover_shift                              (10)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_hs_highpulse_wid_shift                       (8)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_dummy_7_shift                                (7)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag_shift                             (6)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag_en_shift                          (5)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_active_space_fix_en_shift                    (4)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_mode_sel_shift                            (2)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_en_field_shift                            (1)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_enable_shift                              (0)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_cs_sel_mask                                  (0xF0000000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_demo_4k2k_en_mask                            (0x00002000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_sync_timing_sel_mask                         (0x00001000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover_en_mask                            (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover_mask                               (0x00000400)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_hs_highpulse_wid_mask                        (0x00000300)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_dummy_7_mask                                 (0x00000080)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag_mask                              (0x00000040)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag_en_mask                           (0x00000020)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_active_space_fix_en_mask                     (0x00000010)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_mode_sel_mask                             (0x0000000C)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_en_field_mask                             (0x00000002)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_enable_mask                               (0x00000001)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_cs_sel(data)                                 (0xF0000000&((data)<<28))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_demo_4k2k_en(data)                           (0x00002000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_sync_timing_sel(data)                        (0x00001000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover_en(data)                           (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_pat_cover(data)                              (0x00000400&((data)<<10))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_hs_highpulse_wid(data)                       (0x00000300&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_dummy_7(data)                                (0x00000080&((data)<<7))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag(data)                             (0x00000040&((data)<<6))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_fix_l_flag_en(data)                          (0x00000020&((data)<<5))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_active_space_fix_en(data)                    (0x00000010&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_mode_sel(data)                            (0x0000000C&((data)<<2))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_en_field(data)                            (0x00000002&((data)<<1))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_tg_enable(data)                              (0x00000001&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_cs_sel(data)                             ((0xF0000000&(data))>>28)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_demo_4k2k_en(data)                       ((0x00002000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_sync_timing_sel(data)                    ((0x00001000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_pat_cover_en(data)                       ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_pat_cover(data)                          ((0x00000400&(data))>>10)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_hs_highpulse_wid(data)                   ((0x00000300&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_dummy_7(data)                            ((0x00000080&(data))>>7)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_fix_l_flag(data)                         ((0x00000040&(data))>>6)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_fix_l_flag_en(data)                      ((0x00000020&(data))>>5)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_active_space_fix_en(data)                ((0x00000010&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_tg_mode_sel(data)                        ((0x0000000C&(data))>>2)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_tg_en_field(data)                        ((0x00000002&(data))>>1)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_get_tg_enable(data)                          (0x00000001&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE                                         0x1800D810
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg_addr                                "0xB800D810"
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg                                     0xB800D810
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_inst_addr                               "0x0004"
#define  set_HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg(data)                           (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg                                 (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_TG_LINE_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_popup_linecnt_shift                     (15)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_l_flag_out_shift                    (14)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_field_out_shift                     (13)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_linecnt_out_shift                   (0)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_popup_linecnt_mask                      (0x00008000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_l_flag_out_mask                     (0x00004000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_field_out_mask                      (0x00002000)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_linecnt_out_mask                    (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_popup_linecnt(data)                     (0x00008000&((data)<<15))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_l_flag_out(data)                    (0x00004000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_field_out(data)                     (0x00002000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_cur_linecnt_out(data)                   (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_get_popup_linecnt(data)                 ((0x00008000&(data))>>15)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_get_cur_l_flag_out(data)                ((0x00004000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_get_cur_field_out(data)                 ((0x00002000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_TG_LINE_get_cur_linecnt_out(data)               (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width                                0x1800D814
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg_addr                       "0xB800D814"
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg                            0xB800D814
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_inst_addr                      "0x0005"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg(data)                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg                        (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_h_sta_l_shift              (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_dummy_15_13_shift              (13)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_wid_l_shift                (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_h_sta_l_mask               (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_dummy_15_13_mask               (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_wid_l_mask                 (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_h_sta_l(data)              (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_dummy_15_13(data)              (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_pat_wid_l(data)                (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_get_pat_h_sta_l(data)          ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_get_dummy_15_13(data)          ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_HSTA_Width_get_pat_wid_l(data)            (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length                               0x1800D818
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg_addr                      "0xB800D818"
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg                           0xB800D818
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_inst_addr                     "0x0006"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg(data)                 (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_v_sta_l_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_dummy_15_13_shift             (13)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_len_l_shift               (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_v_sta_l_mask              (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_dummy_15_13_mask              (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_len_l_mask                (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_v_sta_l(data)             (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_dummy_15_13(data)             (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_pat_len_l(data)               (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_get_pat_v_sta_l(data)         ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_get_dummy_15_13(data)         ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_L_PAT_VSTA_Length_get_pat_len_l(data)           (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl                                          0x1800D81C
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg_addr                                 "0xB800D81C"
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg                                      0xB800D81C
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_inst_addr                                "0x0007"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg(data)                            (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg                                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_rdy_shift                         (10)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_en_shift                          (9)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_rdm_bkg_l_shift                       (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_xc_seq_l_shift                           (5)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_xc_l_shift                            (4)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_pat_mode_l_shift                         (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_rdy_mask                          (0x00000400)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_en_mask                           (0x00000200)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_rdm_bkg_l_mask                        (0x00000100)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_xc_seq_l_mask                            (0x000000E0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_xc_l_mask                             (0x00000010)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_pat_mode_l_mask                          (0x0000000F)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_rdy(data)                         (0x00000400&((data)<<10))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_ptg_db_en(data)                          (0x00000200&((data)<<9))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_rdm_bkg_l(data)                       (0x00000100&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_xc_seq_l(data)                           (0x000000E0&((data)<<5))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_en_xc_l(data)                            (0x00000010&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_pat_mode_l(data)                         (0x0000000F&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_ptg_db_rdy(data)                     ((0x00000400&(data))>>10)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_ptg_db_en(data)                      ((0x00000200&(data))>>9)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_en_rdm_bkg_l(data)                   ((0x00000100&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_xc_seq_l(data)                       ((0x000000E0&(data))>>5)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_en_xc_l(data)                        ((0x00000010&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_L_Ctrl_get_pat_mode_l(data)                     (0x0000000F&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW                                          0x1800D820
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg_addr                                 "0xB800D820"
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg                                      0xB800D820
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_inst_addr                                "0x0008"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg(data)                            (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg                                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_BARW_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_auto_state_l_shift                       (14)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_l_shift                       (12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_rdy_l_shift                   (11)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_barw_l_shift                             (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_auto_state_l_mask                        (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_l_mask                        (0x00003000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_rdy_l_mask                    (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_barw_l_mask                              (0x000007FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_auto_state_l(data)                       (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_l(data)                       (0x00003000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_hold_state_rdy_l(data)                   (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_barw_l(data)                             (0x000007FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_get_auto_state_l(data)                   ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_get_hold_state_l(data)                   ((0x00003000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_get_hold_state_rdy_l(data)               ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_L_BARW_get_barw_l(data)                         (0x000007FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr                                     0x1800D824
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg_addr                            "0xB800D824"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg                                 0xB800D824
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_inst_addr                           "0x0009"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0y_92b_l_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cr_92b_l_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cb_92b_l_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0y_92b_l_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cr_92b_l_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cb_92b_l_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0y_92b_l(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cr_92b_l(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_i_c0cb_92b_l(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_get_i_c0y_92b_l(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_get_i_c0cr_92b_l(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C0Y_Cb_Cr_get_i_c0cb_92b_l(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr                                     0x1800D828
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg_addr                            "0xB800D828"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg                                 0xB800D828
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_inst_addr                           "0x000A"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1y_92b_l_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cr_92b_l_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cb_92b_l_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1y_92b_l_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cr_92b_l_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cb_92b_l_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1y_92b_l(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cr_92b_l(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_i_c1cb_92b_l(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_get_i_c1y_92b_l(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_get_i_c1cr_92b_l(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C1Y_Cb_Cr_get_i_c1cb_92b_l(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr                                     0x1800D82C
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg_addr                            "0xB800D82C"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg                                 0xB800D82C
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_inst_addr                           "0x000B"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2y_92b_l_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cr_92b_l_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cb_92b_l_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2y_92b_l_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cr_92b_l_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cb_92b_l_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2y_92b_l(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cr_92b_l(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_i_c2cb_92b_l(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_get_i_c2y_92b_l(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_get_i_c2cr_92b_l(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C2Y_Cb_Cr_get_i_c2cb_92b_l(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr                                     0x1800D830
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg_addr                            "0xB800D830"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg                                 0xB800D830
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_inst_addr                           "0x000C"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_98b_l_shift                   (30)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_72b_grady_l_shift             (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_98b_l_shift                  (22)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_72b_gradcr_l_shift           (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_98b_l_shift                  (14)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_72b_gradcb_l_shift           (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_dummy_7_0_shift                     (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_98b_l_mask                    (0xC0000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_72b_grady_l_mask              (0x3F000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_98b_l_mask                   (0x00C00000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_72b_gradcr_l_mask            (0x003F0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_98b_l_mask                   (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_72b_gradcb_l_mask            (0x00003F00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_dummy_7_0_mask                      (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_98b_l(data)                   (0xC0000000&((data)<<30))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3y_72b_grady_l(data)             (0x3F000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_98b_l(data)                  (0x00C00000&((data)<<22))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cr_72b_gradcr_l(data)           (0x003F0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_98b_l(data)                  (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_i_c3cb_72b_gradcb_l(data)           (0x00003F00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_dummy_7_0(data)                     (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3y_98b_l(data)               ((0xC0000000&(data))>>30)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3y_72b_grady_l(data)         ((0x3F000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3cr_98b_l(data)              ((0x00C00000&(data))>>22)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3cr_72b_gradcr_l(data)       ((0x003F0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3cb_98b_l(data)              ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_i_c3cb_72b_gradcb_l(data)       ((0x00003F00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C3Y_Cb_Cr_get_dummy_7_0(data)                 (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr                                     0x1800D834
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg_addr                            "0xB800D834"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg                                 0xB800D834
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_inst_addr                           "0x000D"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_96b_l_shift                   (28)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_52b_step_hv_l_shift           (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cr_92b_l_shift                  (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_9b_l_shift                   (15)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_l_shift            (12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_5b_l_shift                   (11)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_l_shift            (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_96b_l_mask                    (0xF0000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_52b_step_hv_l_mask            (0x0F000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cr_92b_l_mask                   (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_9b_l_mask                    (0x00008000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_l_mask             (0x00007000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_5b_l_mask                    (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_l_mask             (0x00000700)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_96b_l(data)                   (0xF0000000&((data)<<28))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4y_52b_step_hv_l(data)           (0x0F000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cr_92b_l(data)                  (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_9b_l(data)                   (0x00008000&((data)<<15))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_l(data)            (0x00007000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_5b_l(data)                   (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_l(data)            (0x00000700&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4y_96b_l(data)               ((0xF0000000&(data))>>28)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4y_52b_step_hv_l(data)       ((0x0F000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4cr_92b_l(data)              ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4cb_9b_l(data)               ((0x00008000&(data))>>15)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4cb_86b_bmp_w_l(data)        ((0x00007000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4cb_5b_l(data)               ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C4Y_Cb_Cr_get_i_c4cb_42b_bmp_h_l(data)        ((0x00000700&(data))>>8)

#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb                                     0x1800D838
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg_addr                            "0xB800D838"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg                                 0xB800D838
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_inst_addr                           "0x000E"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5y_92b_bmptp_l_shift             (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cr_92b_bmp0_l_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cb_92b_bmp1_l_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_dummy_7_0_shift                     (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5y_92b_bmptp_l_mask              (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cr_92b_bmp0_l_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cb_92b_bmp1_l_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_dummy_7_0_mask                      (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5y_92b_bmptp_l(data)             (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cr_92b_bmp0_l(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_i_c5cb_92b_bmp1_l(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_dummy_7_0(data)                     (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_get_i_c5y_92b_bmptp_l(data)         ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_get_i_c5cr_92b_bmp0_l(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_get_i_c5cb_92b_bmp1_l(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C5Y_Cr_Cb_get_dummy_7_0(data)                 (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr                                     0x1800D83C
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg_addr                            "0xB800D83C"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg                                 0xB800D83C
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_inst_addr                           "0x000F"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6y_92b_bmp2_l_shift              (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cr_92b_bmp3_l_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cb_92b_bmp4_l_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_nonactive_color_def_l_shift         (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6y_92b_bmp2_l_mask               (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cr_92b_bmp3_l_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cb_92b_bmp4_l_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_nonactive_color_def_l_mask          (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6y_92b_bmp2_l(data)              (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cr_92b_bmp3_l(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_i_c6cb_92b_bmp4_l(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_nonactive_color_def_l(data)         (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_get_i_c6y_92b_bmp2_l(data)          ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_get_i_c6cr_92b_bmp3_l(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_get_i_c6cb_92b_bmp4_l(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C6Y_Cb_Cr_get_nonactive_color_def_l(data)     (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr                                     0x1800D840
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg_addr                            "0xB800D840"
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg                                 0xB800D840
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_inst_addr                           "0x0010"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7y_92b_bmp5_l_shift              (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cr_92b_bmp6_l_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cb_92b_bmp7_l_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_dummy_7_3_shift                     (3)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_max_color_l_shift                   (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7y_92b_bmp5_l_mask               (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cr_92b_bmp6_l_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cb_92b_bmp7_l_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_dummy_7_3_mask                      (0x000000F8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_max_color_l_mask                    (0x00000007)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7y_92b_bmp5_l(data)              (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cr_92b_bmp6_l(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_i_c7cb_92b_bmp7_l(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_dummy_7_3(data)                     (0x000000F8&((data)<<3))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_max_color_l(data)                   (0x00000007&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_get_i_c7y_92b_bmp5_l(data)          ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_get_i_c7cr_92b_bmp6_l(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_get_i_c7cb_92b_bmp7_l(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_get_dummy_7_3(data)                 ((0x000000F8&(data))>>3)
#define  HDMIPATTERNGEN_HDMI_PTG_L_C7Y_Cb_Cr_get_max_color_l(data)               (0x00000007&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl                                0x1800D844
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg_addr                       "0xB800D844"
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg                            0xB800D844
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_inst_addr                      "0x0011"
#define  set_HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg(data)                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg                        (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_h_l_shift                   (24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_v_l_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_seq_type_l_shift            (15)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_rdm_period_l_shift             (12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_vs_num_l_shift              (8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mp_adj_num_l_shift             (0)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_h_l_mask                    (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_v_l_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_seq_type_l_mask             (0x00008000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_rdm_period_l_mask              (0x00007000)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_vs_num_l_mask               (0x00000F00)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mp_adj_num_l_mask              (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_h_l(data)                   (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_v_l(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_seq_type_l(data)            (0x00008000&((data)<<15))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_rdm_period_l(data)             (0x00007000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mv_vs_num_l(data)              (0x00000F00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_mp_adj_num_l(data)             (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_mv_h_l(data)               ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_mv_v_l(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_mv_seq_type_l(data)        ((0x00008000&(data))>>15)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_rdm_period_l(data)         ((0x00007000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_mv_vs_num_l(data)          ((0x00000F00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_L_MAX_COLOR_Ctrl_get_mp_adj_num_l(data)         (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width                                0x1800D848
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg_addr                       "0xB800D848"
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg                            0xB800D848
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_inst_addr                      "0x0012"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg(data)                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg                        (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_h_sta_r_shift              (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_dummy_15_13_shift              (13)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_wid_r_shift                (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_h_sta_r_mask               (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_dummy_15_13_mask               (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_wid_r_mask                 (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_h_sta_r(data)              (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_dummy_15_13(data)              (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_pat_wid_r(data)                (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_get_pat_h_sta_r(data)          ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_get_dummy_15_13(data)          ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_HSTA_Width_get_pat_wid_r(data)            (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length                               0x1800D84C
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg_addr                      "0xB800D84C"
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg                           0xB800D84C
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_inst_addr                     "0x0013"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg(data)                 (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_v_sta_r_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_dummy_15_13_shift             (13)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_len_r_shift               (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_v_sta_r_mask              (0x1FFF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_dummy_15_13_mask              (0x0000E000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_len_r_mask                (0x00001FFF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_v_sta_r(data)             (0x1FFF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_dummy_15_13(data)             (0x0000E000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_pat_len_r(data)               (0x00001FFF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_get_pat_v_sta_r(data)         ((0x1FFF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_get_dummy_15_13(data)         ((0x0000E000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_R_PAT_VSTA_Length_get_pat_len_r(data)           (0x00001FFF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl                                          0x1800D850
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg_addr                                 "0xB800D850"
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg                                      0xB800D850
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_inst_addr                                "0x0014"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg(data)                            (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg                                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_rdm_bkg_r_shift                       (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_xc_seq_r_shift                           (5)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_xc_r_shift                            (4)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_pat_mode_r_shift                         (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_rdm_bkg_r_mask                        (0x00000100)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_xc_seq_r_mask                            (0x000000E0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_xc_r_mask                             (0x00000010)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_pat_mode_r_mask                          (0x0000000F)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_rdm_bkg_r(data)                       (0x00000100&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_xc_seq_r(data)                           (0x000000E0&((data)<<5))
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_en_xc_r(data)                            (0x00000010&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_pat_mode_r(data)                         (0x0000000F&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_get_en_rdm_bkg_r(data)                   ((0x00000100&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_get_xc_seq_r(data)                       ((0x000000E0&(data))>>5)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_get_en_xc_r(data)                        ((0x00000010&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_R_Ctrl_get_pat_mode_r(data)                     (0x0000000F&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW                                          0x1800D854
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg_addr                                 "0xB800D854"
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg                                      0xB800D854
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_inst_addr                                "0x0015"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg(data)                            (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg                                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_BARW_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_auto_state_r_shift                       (14)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_r_shift                       (12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_rdy_r_shift                   (11)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_barw_r_shift                             (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_auto_state_r_mask                        (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_r_mask                        (0x00003000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_rdy_r_mask                    (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_barw_r_mask                              (0x000007FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_auto_state_r(data)                       (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_r(data)                       (0x00003000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_hold_state_rdy_r(data)                   (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_barw_r(data)                             (0x000007FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_get_auto_state_r(data)                   ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_get_hold_state_r(data)                   ((0x00003000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_get_hold_state_rdy_r(data)               ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_R_BARW_get_barw_r(data)                         (0x000007FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr                                     0x1800D858
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg_addr                            "0xB800D858"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg                                 0xB800D858
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_inst_addr                           "0x0016"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0y_92b_r_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cr_92b_r_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cb_92b_r_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0y_92b_r_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cr_92b_r_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cb_92b_r_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0y_92b_r(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cr_92b_r(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_i_c0cb_92b_r(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_get_i_c0y_92b_r(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_get_i_c0cr_92b_r(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C0Y_Cb_Cr_get_i_c0cb_92b_r(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr                                     0x1800D85C
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg_addr                            "0xB800D85C"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg                                 0xB800D85C
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_inst_addr                           "0x0017"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1y_92b_r_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cr_92b_r_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cb_92b_r_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1y_92b_r_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cr_92b_r_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cb_92b_r_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1y_92b_r(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cr_92b_r(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_i_c1cb_92b_r(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_get_i_c1y_92b_r(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_get_i_c1cr_92b_r(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C1Y_Cb_Cr_get_i_c1cb_92b_r(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr                                     0x1800D860
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg_addr                            "0xB800D860"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg                                 0xB800D860
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_inst_addr                           "0x0018"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2y_92b_r_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cr_92b_r_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cb_92b_r_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2y_92b_r_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cr_92b_r_mask                   (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cb_92b_r_mask                   (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2y_92b_r(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cr_92b_r(data)                  (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_i_c2cb_92b_r(data)                  (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_get_i_c2y_92b_r(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_get_i_c2cr_92b_r(data)              ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C2Y_Cb_Cr_get_i_c2cb_92b_r(data)              (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr                                     0x1800D864
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg_addr                            "0xB800D864"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg                                 0xB800D864
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_inst_addr                           "0x0019"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_98b_r_shift                   (30)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_72b_grady_r_shift             (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_98b_r_shift                  (22)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_72b_gradcr_r_shift           (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_98b_r_shift                  (14)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_72b_gradcb_r_shift           (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_dummy_7_0_shift                     (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_98b_r_mask                    (0xC0000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_72b_grady_r_mask              (0x3F000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_98b_r_mask                   (0x00C00000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_72b_gradcr_r_mask            (0x003F0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_98b_r_mask                   (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_72b_gradcb_r_mask            (0x00003F00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_dummy_7_0_mask                      (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_98b_r(data)                   (0xC0000000&((data)<<30))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3y_72b_grady_r(data)             (0x3F000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_98b_r(data)                  (0x00C00000&((data)<<22))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cr_72b_gradcr_r(data)           (0x003F0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_98b_r(data)                  (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_i_c3cb_72b_gradcb_r(data)           (0x00003F00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_dummy_7_0(data)                     (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3y_98b_r(data)               ((0xC0000000&(data))>>30)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3y_72b_grady_r(data)         ((0x3F000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3cr_98b_r(data)              ((0x00C00000&(data))>>22)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3cr_72b_gradcr_r(data)       ((0x003F0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3cb_98b_r(data)              ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_i_c3cb_72b_gradcb_r(data)       ((0x00003F00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C3Y_Cb_Cr_get_dummy_7_0(data)                 (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr                                     0x1800D868
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg_addr                            "0xB800D868"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg                                 0xB800D868
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_inst_addr                           "0x001A"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_96b_r_shift                   (28)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_52b_step_hv_r_shift           (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cr_92b_r_shift                  (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_9b_r_shift                   (15)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_r_shift            (12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_5b_r_shift                   (11)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_r_shift            (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_96b_r_mask                    (0xF0000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_52b_step_hv_r_mask            (0x0F000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cr_92b_r_mask                   (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_9b_r_mask                    (0x00008000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_r_mask             (0x00007000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_5b_r_mask                    (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_r_mask             (0x00000700)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_96b_r(data)                   (0xF0000000&((data)<<28))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4y_52b_step_hv_r(data)           (0x0F000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cr_92b_r(data)                  (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_9b_r(data)                   (0x00008000&((data)<<15))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_86b_bmp_w_r(data)            (0x00007000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_5b_r(data)                   (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_i_c4cb_42b_bmp_h_r(data)            (0x00000700&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4y_96b_r(data)               ((0xF0000000&(data))>>28)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4y_52b_step_hv_r(data)       ((0x0F000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4cr_92b_r(data)              ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4cb_9b_r(data)               ((0x00008000&(data))>>15)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4cb_86b_bmp_w_r(data)        ((0x00007000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4cb_5b_r(data)               ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C4Y_Cb_Cr_get_i_c4cb_42b_bmp_h_r(data)        ((0x00000700&(data))>>8)

#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb                                     0x1800D86C
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg_addr                            "0xB800D86C"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg                                 0xB800D86C
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_inst_addr                           "0x001B"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5y_92b_bmptp_r_shift             (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cr_92b_bmp0_r_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cb_92b_bmp1_r_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_dummy_7_0_shift                     (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5y_92b_bmptp_r_mask              (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cr_92b_bmp0_r_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cb_92b_bmp1_r_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_dummy_7_0_mask                      (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5y_92b_bmptp_r(data)             (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cr_92b_bmp0_r(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_i_c5cb_92b_bmp1_r(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_dummy_7_0(data)                     (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_get_i_c5y_92b_bmptp_r(data)         ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_get_i_c5cr_92b_bmp0_r(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_get_i_c5cb_92b_bmp1_r(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C5Y_Cr_Cb_get_dummy_7_0(data)                 (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr                                     0x1800D870
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg_addr                            "0xB800D870"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg                                 0xB800D870
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_inst_addr                           "0x001C"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6y_92b_bmp2_r_shift              (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cr_92b_bmp3_r_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cb_92b_bmp4_r_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_nonactive_color_def_r_shift         (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6y_92b_bmp2_r_mask               (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cr_92b_bmp3_r_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cb_92b_bmp4_r_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_nonactive_color_def_r_mask          (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6y_92b_bmp2_r(data)              (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cr_92b_bmp3_r(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_i_c6cb_92b_bmp4_r(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_nonactive_color_def_r(data)         (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_get_i_c6y_92b_bmp2_r(data)          ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_get_i_c6cr_92b_bmp3_r(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_get_i_c6cb_92b_bmp4_r(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C6Y_Cb_Cr_get_nonactive_color_def_r(data)     (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr                                     0x1800D874
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg_addr                            "0xB800D874"
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg                                 0xB800D874
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_inst_addr                           "0x001D"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg(data)                       (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg                             (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7y_92b_bmp5_r_shift              (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cr_92b_bmp6_r_shift             (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cb_92b_bmp7_r_shift             (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_dummy_7_3_shift                     (3)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_max_color_r_shift                   (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7y_92b_bmp5_r_mask               (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cr_92b_bmp6_r_mask              (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cb_92b_bmp7_r_mask              (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_dummy_7_3_mask                      (0x000000F8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_max_color_r_mask                    (0x00000007)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7y_92b_bmp5_r(data)              (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cr_92b_bmp6_r(data)             (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_i_c7cb_92b_bmp7_r(data)             (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_dummy_7_3(data)                     (0x000000F8&((data)<<3))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_max_color_r(data)                   (0x00000007&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_get_i_c7y_92b_bmp5_r(data)          ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_get_i_c7cr_92b_bmp6_r(data)         ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_get_i_c7cb_92b_bmp7_r(data)         ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_get_dummy_7_3(data)                 ((0x000000F8&(data))>>3)
#define  HDMIPATTERNGEN_HDMI_PTG_R_C7Y_Cb_Cr_get_max_color_r(data)               (0x00000007&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl                                0x1800D878
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg_addr                       "0xB800D878"
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg                            0xB800D878
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_inst_addr                      "0x001E"
#define  set_HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg(data)                  (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg                        (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_h_r_shift                   (24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_v_r_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_seq_type_r_shift            (15)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_rdm_period_r_shift             (12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_vs_num_r_shift              (8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mp_adj_num_r_shift             (0)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_h_r_mask                    (0xFF000000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_v_r_mask                    (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_seq_type_r_mask             (0x00008000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_rdm_period_r_mask              (0x00007000)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_vs_num_r_mask               (0x00000F00)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mp_adj_num_r_mask              (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_h_r(data)                   (0xFF000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_v_r(data)                   (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_seq_type_r(data)            (0x00008000&((data)<<15))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_rdm_period_r(data)             (0x00007000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mv_vs_num_r(data)              (0x00000F00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_mp_adj_num_r(data)             (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_mv_h_r(data)               ((0xFF000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_mv_v_r(data)               ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_mv_seq_type_r(data)        ((0x00008000&(data))>>15)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_rdm_period_r(data)         ((0x00007000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_mv_vs_num_r(data)          ((0x00000F00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_R_MAX_COLOR_Ctrl_get_mp_adj_num_r(data)         (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1                                       0x1800D87C
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg_addr                              "0xB800D87C"
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg                                   0xB800D87C
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_inst_addr                             "0x001F"
#define  set_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg(data)                         (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg                               (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_chess_v_size_shift                    (16)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_en_shift                 (13)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_en_shift                    (12)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_pos_shift                   (7)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_on_mask_shift            (4)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_step_hv_shift               (0)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_chess_v_size_mask                     (0x07FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_en_mask                  (0x00002000)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_en_mask                     (0x00001000)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_pos_mask                    (0x00000080)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_on_mask_mask             (0x00000070)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_step_hv_mask                (0x0000000F)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_chess_v_size(data)                    (0x07FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_en(data)                 (0x00002000&((data)<<13))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_en(data)                    (0x00001000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_pos(data)                   (0x00000080&((data)<<7))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_sub_pix_on_mask(data)            (0x00000070&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_grad_cbar_step_hv(data)               (0x0000000F&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_chess_v_size(data)                ((0x07FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_grad_sub_pix_en(data)             ((0x00002000&(data))>>13)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_grad_cbar_en(data)                ((0x00001000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_grad_cbar_pos(data)               ((0x00000080&(data))>>7)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_grad_sub_pix_on_mask(data)        ((0x00000070&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL1_get_grad_cbar_step_hv(data)           (0x0000000F&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2                                       0x1800D880
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg_addr                              "0xB800D880"
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg                                   0xB800D880
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_inst_addr                             "0x0020"
#define  set_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg(data)                         (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg                               (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_y_bright_en_shift                     (16)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cb_bright_en_shift                    (8)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cr_bright_en_shift                    (0)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_y_bright_en_mask                      (0x00FF0000)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cb_bright_en_mask                     (0x0000FF00)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cr_bright_en_mask                     (0x000000FF)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_y_bright_en(data)                     (0x00FF0000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cb_bright_en(data)                    (0x0000FF00&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_cr_bright_en(data)                    (0x000000FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_get_y_bright_en(data)                 ((0x00FF0000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_get_cb_bright_en(data)                ((0x0000FF00&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL2_get_cr_bright_en(data)                (0x000000FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3                                       0x1800D884
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg_addr                              "0xB800D884"
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg                                   0xB800D884
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_inst_addr                             "0x0021"
#define  set_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg(data)                         (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg                               (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bmp_sub_pix_en_shift                  (11)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bright_shift                          (0)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bmp_sub_pix_en_mask                   (0x00000800)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bright_mask                           (0x000003FF)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bmp_sub_pix_en(data)                  (0x00000800&((data)<<11))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_bright(data)                          (0x000003FF&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_get_bmp_sub_pix_en(data)              ((0x00000800&(data))>>11)
#define  HDMIPATTERNGEN_HDMI_PTG_CMI_CTRL3_get_bright(data)                      (0x000003FF&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1                                   0x1800D888
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg_addr                          "0xB800D888"
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg                               0xB800D888
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_inst_addr                         "0x0022"
#define  set_HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg(data)                     (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg                           (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_color_ext_en_shift                (24)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3y_ext_shift                   (22)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cb_ext_shift                  (20)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cr_ext_shift                  (18)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2y_ext_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cr_ext_shift                  (14)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cb_ext_shift                  (12)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1y_ext_shift                   (10)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cr_ext_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cb_ext_shift                  (6)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0y_ext_shift                   (4)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cr_ext_shift                  (2)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cb_ext_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_color_ext_en_mask                 (0x01000000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3y_ext_mask                    (0x00C00000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cb_ext_mask                   (0x00300000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cr_ext_mask                   (0x000C0000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2y_ext_mask                    (0x00030000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cr_ext_mask                   (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cb_ext_mask                   (0x00003000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1y_ext_mask                    (0x00000C00)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cr_ext_mask                   (0x00000300)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cb_ext_mask                   (0x000000C0)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0y_ext_mask                    (0x00000030)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cr_ext_mask                   (0x0000000C)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cb_ext_mask                   (0x00000003)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_color_ext_en(data)                (0x01000000&((data)<<24))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3y_ext(data)                   (0x00C00000&((data)<<22))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cb_ext(data)                  (0x00300000&((data)<<20))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c3cr_ext(data)                  (0x000C0000&((data)<<18))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2y_ext(data)                   (0x00030000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cr_ext(data)                  (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c2cb_ext(data)                  (0x00003000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1y_ext(data)                   (0x00000C00&((data)<<10))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cr_ext(data)                  (0x00000300&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c1cb_ext(data)                  (0x000000C0&((data)<<6))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0y_ext(data)                   (0x00000030&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cr_ext(data)                  (0x0000000C&((data)<<2))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_i_c0cb_ext(data)                  (0x00000003&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_color_ext_en(data)            ((0x01000000&(data))>>24)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c3y_ext(data)               ((0x00C00000&(data))>>22)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c3cb_ext(data)              ((0x00300000&(data))>>20)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c3cr_ext(data)              ((0x000C0000&(data))>>18)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c2y_ext(data)               ((0x00030000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c2cr_ext(data)              ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c2cb_ext(data)              ((0x00003000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c1y_ext(data)               ((0x00000C00&(data))>>10)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c1cr_ext(data)              ((0x00000300&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c1cb_ext(data)              ((0x000000C0&(data))>>6)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c0y_ext(data)               ((0x00000030&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c0cr_ext(data)              ((0x0000000C&(data))>>2)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND1_get_i_c0cb_ext(data)              (0x00000003&(data))

#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2                                   0x1800D88C
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg_addr                          "0xB800D88C"
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg                               0xB800D88C
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_inst_addr                         "0x0023"
#define  set_HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg(data)                     (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg)=data)
#define  get_HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg                           (*((volatile unsigned int*)HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_reg))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7y_ext_shift                   (22)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cb_ext_shift                  (20)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cr_ext_shift                  (18)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6y_ext_shift                   (16)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cr_ext_shift                  (14)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cb_ext_shift                  (12)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5y_ext_shift                   (10)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cr_ext_shift                  (8)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cb_ext_shift                  (6)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4y_ext_shift                   (4)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cr_ext_shift                  (2)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cb_ext_shift                  (0)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7y_ext_mask                    (0x00C00000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cb_ext_mask                   (0x00300000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cr_ext_mask                   (0x000C0000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6y_ext_mask                    (0x00030000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cr_ext_mask                   (0x0000C000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cb_ext_mask                   (0x00003000)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5y_ext_mask                    (0x00000C00)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cr_ext_mask                   (0x00000300)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cb_ext_mask                   (0x000000C0)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4y_ext_mask                    (0x00000030)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cr_ext_mask                   (0x0000000C)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cb_ext_mask                   (0x00000003)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7y_ext(data)                   (0x00C00000&((data)<<22))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cb_ext(data)                  (0x00300000&((data)<<20))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c7cr_ext(data)                  (0x000C0000&((data)<<18))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6y_ext(data)                   (0x00030000&((data)<<16))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cr_ext(data)                  (0x0000C000&((data)<<14))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c6cb_ext(data)                  (0x00003000&((data)<<12))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5y_ext(data)                   (0x00000C00&((data)<<10))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cr_ext(data)                  (0x00000300&((data)<<8))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c5cb_ext(data)                  (0x000000C0&((data)<<6))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4y_ext(data)                   (0x00000030&((data)<<4))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cr_ext(data)                  (0x0000000C&((data)<<2))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_i_c4cb_ext(data)                  (0x00000003&(data))
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c7y_ext(data)               ((0x00C00000&(data))>>22)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c7cb_ext(data)              ((0x00300000&(data))>>20)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c7cr_ext(data)              ((0x000C0000&(data))>>18)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c6y_ext(data)               ((0x00030000&(data))>>16)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c6cr_ext(data)              ((0x0000C000&(data))>>14)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c6cb_ext(data)              ((0x00003000&(data))>>12)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c5y_ext(data)               ((0x00000C00&(data))>>10)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c5cr_ext(data)              ((0x00000300&(data))>>8)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c5cb_ext(data)              ((0x000000C0&(data))>>6)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c4y_ext(data)               ((0x00000030&(data))>>4)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c4cr_ext(data)              ((0x0000000C&(data))>>2)
#define  HDMIPATTERNGEN_HDMI_PTG_COLOR_EXTEND2_get_i_c4cb_ext(data)              (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HDMIPATTERNGEN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  totalh_pixel:13;
        RBus_UInt32  dummy1800d800_15_13:3;
        RBus_UInt32  totalv_line:13;
    };
}hdmipatterngen_hdmi_ptg_totalhv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  act_h_sta:13;
        RBus_UInt32  dummy1800d804_15_13:3;
        RBus_UInt32  act_wid:13;
    };
}hdmipatterngen_hdmi_ptg_act_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  act_v_sta:13;
        RBus_UInt32  dummy1800d808_15_13:3;
        RBus_UInt32  act_len:13;
    };
}hdmipatterngen_hdmi_ptg_act_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_sel:4;
        RBus_UInt32  res1:14;
        RBus_UInt32  demo_4k2k_en:1;
        RBus_UInt32  sync_timing_sel:1;
        RBus_UInt32  pat_cover_en:1;
        RBus_UInt32  pat_cover:1;
        RBus_UInt32  hs_highpulse_wid:2;
        RBus_UInt32  dummy1800d80c_7:1;
        RBus_UInt32  fix_l_flag:1;
        RBus_UInt32  fix_l_flag_en:1;
        RBus_UInt32  active_space_fix_en:1;
        RBus_UInt32  tg_mode_sel:2;
        RBus_UInt32  tg_en_field:1;
        RBus_UInt32  tg_enable:1;
    };
}hdmipatterngen_hdmi_ptg_tg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  popup_linecnt:1;
        RBus_UInt32  cur_l_flag_out:1;
        RBus_UInt32  cur_field_out:1;
        RBus_UInt32  cur_linecnt_out:13;
    };
}hdmipatterngen_hdmi_ptg_tg_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_h_sta_l:13;
        RBus_UInt32  dummy1800d814_15_13:3;
        RBus_UInt32  pat_wid_l:13;
    };
}hdmipatterngen_hdmi_ptg_l_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_v_sta_l:13;
        RBus_UInt32  dummy1800d818_15_13:3;
        RBus_UInt32  pat_len_l:13;
    };
}hdmipatterngen_hdmi_ptg_l_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  ptg_db_rdy:1;
        RBus_UInt32  ptg_db_en:1;
        RBus_UInt32  en_rdm_bkg_l:1;
        RBus_UInt32  xc_seq_l:3;
        RBus_UInt32  en_xc_l:1;
        RBus_UInt32  pat_mode_l:4;
    };
}hdmipatterngen_hdmi_ptg_l_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  auto_state_l:2;
        RBus_UInt32  hold_state_l:2;
        RBus_UInt32  hold_state_rdy_l:1;
        RBus_UInt32  barw_l:11;
    };
}hdmipatterngen_hdmi_ptg_l_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c0y_92b_l:8;
        RBus_UInt32  i_c0cr_92b_l:8;
        RBus_UInt32  i_c0cb_92b_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c1y_92b_l:8;
        RBus_UInt32  i_c1cr_92b_l:8;
        RBus_UInt32  i_c1cb_92b_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c2y_92b_l:8;
        RBus_UInt32  i_c2cr_92b_l:8;
        RBus_UInt32  i_c2cb_92b_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c3y_98b_l:2;
        RBus_UInt32  i_c3y_72b_grady_l:6;
        RBus_UInt32  i_c3cr_98b_l:2;
        RBus_UInt32  i_c3cr_72b_gradcr_l:6;
        RBus_UInt32  i_c3cb_98b_l:2;
        RBus_UInt32  i_c3cb_72b_gradcb_l:6;
        RBus_UInt32  dummy1800d830_7_0:8;
    };
}hdmipatterngen_hdmi_ptg_l_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4y_96b_l:4;
        RBus_UInt32  i_c4y_52b_step_hv_l:4;
        RBus_UInt32  i_c4cr_92b_l:8;
        RBus_UInt32  i_c4cb_9b_l:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_l:3;
        RBus_UInt32  i_c4cb_5b_l:1;
        RBus_UInt32  i_c4cb_42b_bmp_h_l:3;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_l_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c5y_92b_bmptp_l:8;
        RBus_UInt32  i_c5cr_92b_bmp0_l:8;
        RBus_UInt32  i_c5cb_92b_bmp1_l:8;
        RBus_UInt32  dummy1800d838_7_0:8;
    };
}hdmipatterngen_hdmi_ptg_l_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c6y_92b_bmp2_l:8;
        RBus_UInt32  i_c6cr_92b_bmp3_l:8;
        RBus_UInt32  i_c6cb_92b_bmp4_l:8;
        RBus_UInt32  nonactive_color_def_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c7y_92b_bmp5_l:8;
        RBus_UInt32  i_c7cr_92b_bmp6_l:8;
        RBus_UInt32  i_c7cb_92b_bmp7_l:8;
        RBus_UInt32  dummy1800d840_7_3:5;
        RBus_UInt32  max_color_l:3;
    };
}hdmipatterngen_hdmi_ptg_l_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_h_l:8;
        RBus_UInt32  mv_v_l:8;
        RBus_UInt32  mv_seq_type_l:1;
        RBus_UInt32  rdm_period_l:3;
        RBus_UInt32  mv_vs_num_l:4;
        RBus_UInt32  mp_adj_num_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_h_sta_r:13;
        RBus_UInt32  dummy1800d848_15_13:3;
        RBus_UInt32  pat_wid_r:13;
    };
}hdmipatterngen_hdmi_ptg_r_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_v_sta_r:13;
        RBus_UInt32  dummy1800d84c_15_13:3;
        RBus_UInt32  pat_len_r:13;
    };
}hdmipatterngen_hdmi_ptg_r_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  en_rdm_bkg_r:1;
        RBus_UInt32  xc_seq_r:3;
        RBus_UInt32  en_xc_r:1;
        RBus_UInt32  pat_mode_r:4;
    };
}hdmipatterngen_hdmi_ptg_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  auto_state_r:2;
        RBus_UInt32  hold_state_r:2;
        RBus_UInt32  hold_state_rdy_r:1;
        RBus_UInt32  barw_r:11;
    };
}hdmipatterngen_hdmi_ptg_r_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c0y_92b_r:8;
        RBus_UInt32  i_c0cr_92b_r:8;
        RBus_UInt32  i_c0cb_92b_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c1y_92b_r:8;
        RBus_UInt32  i_c1cr_92b_r:8;
        RBus_UInt32  i_c1cb_92b_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c2y_92b_r:8;
        RBus_UInt32  i_c2cr_92b_r:8;
        RBus_UInt32  i_c2cb_92b_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c3y_98b_r:2;
        RBus_UInt32  i_c3y_72b_grady_r:6;
        RBus_UInt32  i_c3cr_98b_r:2;
        RBus_UInt32  i_c3cr_72b_gradcr_r:6;
        RBus_UInt32  i_c3cb_98b_r:2;
        RBus_UInt32  i_c3cb_72b_gradcb_r:6;
        RBus_UInt32  dummy1800d864_7_0:8;
    };
}hdmipatterngen_hdmi_ptg_r_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4y_96b_r:4;
        RBus_UInt32  i_c4y_52b_step_hv_r:4;
        RBus_UInt32  i_c4cr_92b_r:8;
        RBus_UInt32  i_c4cb_9b_r:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_r:3;
        RBus_UInt32  i_c4cb_5b_r:1;
        RBus_UInt32  i_c4cb_42b_bmp_h_r:3;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_r_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c5y_92b_bmptp_r:8;
        RBus_UInt32  i_c5cr_92b_bmp0_r:8;
        RBus_UInt32  i_c5cb_92b_bmp1_r:8;
        RBus_UInt32  dummy1800d86c_7_0:8;
    };
}hdmipatterngen_hdmi_ptg_r_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c6y_92b_bmp2_r:8;
        RBus_UInt32  i_c6cr_92b_bmp3_r:8;
        RBus_UInt32  i_c6cb_92b_bmp4_r:8;
        RBus_UInt32  nonactive_color_def_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c7y_92b_bmp5_r:8;
        RBus_UInt32  i_c7cr_92b_bmp6_r:8;
        RBus_UInt32  i_c7cb_92b_bmp7_r:8;
        RBus_UInt32  dummy1800d874_7_3:5;
        RBus_UInt32  max_color_r:3;
    };
}hdmipatterngen_hdmi_ptg_r_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_h_r:8;
        RBus_UInt32  mv_v_r:8;
        RBus_UInt32  mv_seq_type_r:1;
        RBus_UInt32  rdm_period_r:3;
        RBus_UInt32  mv_vs_num_r:4;
        RBus_UInt32  mp_adj_num_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  chess_v_size:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  grad_sub_pix_en:1;
        RBus_UInt32  grad_cbar_en:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  grad_cbar_pos:1;
        RBus_UInt32  grad_sub_pix_on_mask:3;
        RBus_UInt32  grad_cbar_step_hv:4;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_bright_en:8;
        RBus_UInt32  cb_bright_en:8;
        RBus_UInt32  cr_bright_en:8;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  bmp_sub_pix_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bright:10;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  color_ext_en:1;
        RBus_UInt32  i_c3y_ext:2;
        RBus_UInt32  i_c3cb_ext:2;
        RBus_UInt32  i_c3cr_ext:2;
        RBus_UInt32  i_c2y_ext:2;
        RBus_UInt32  i_c2cr_ext:2;
        RBus_UInt32  i_c2cb_ext:2;
        RBus_UInt32  i_c1y_ext:2;
        RBus_UInt32  i_c1cr_ext:2;
        RBus_UInt32  i_c1cb_ext:2;
        RBus_UInt32  i_c0y_ext:2;
        RBus_UInt32  i_c0cr_ext:2;
        RBus_UInt32  i_c0cb_ext:2;
    };
}hdmipatterngen_hdmi_ptg_color_extend1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c7y_ext:2;
        RBus_UInt32  i_c7cb_ext:2;
        RBus_UInt32  i_c7cr_ext:2;
        RBus_UInt32  i_c6y_ext:2;
        RBus_UInt32  i_c6cr_ext:2;
        RBus_UInt32  i_c6cb_ext:2;
        RBus_UInt32  i_c5y_ext:2;
        RBus_UInt32  i_c5cr_ext:2;
        RBus_UInt32  i_c5cb_ext:2;
        RBus_UInt32  i_c4y_ext:2;
        RBus_UInt32  i_c4cr_ext:2;
        RBus_UInt32  i_c4cb_ext:2;
    };
}hdmipatterngen_hdmi_ptg_color_extend2_RBUS;

#else //apply LITTLE_ENDIAN

//======HDMIPATTERNGEN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  totalv_line:13;
        RBus_UInt32  dummy1800d800_15_13:3;
        RBus_UInt32  totalh_pixel:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_totalhv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  act_wid:13;
        RBus_UInt32  dummy1800d804_15_13:3;
        RBus_UInt32  act_h_sta:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_act_h_start_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  act_len:13;
        RBus_UInt32  dummy1800d808_15_13:3;
        RBus_UInt32  act_v_sta:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_act_v_start_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_enable:1;
        RBus_UInt32  tg_en_field:1;
        RBus_UInt32  tg_mode_sel:2;
        RBus_UInt32  active_space_fix_en:1;
        RBus_UInt32  fix_l_flag_en:1;
        RBus_UInt32  fix_l_flag:1;
        RBus_UInt32  dummy1800d80c_7:1;
        RBus_UInt32  hs_highpulse_wid:2;
        RBus_UInt32  pat_cover:1;
        RBus_UInt32  pat_cover_en:1;
        RBus_UInt32  sync_timing_sel:1;
        RBus_UInt32  demo_4k2k_en:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  cs_sel:4;
    };
}hdmipatterngen_hdmi_ptg_tg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_linecnt_out:13;
        RBus_UInt32  cur_field_out:1;
        RBus_UInt32  cur_l_flag_out:1;
        RBus_UInt32  popup_linecnt:1;
        RBus_UInt32  res1:16;
    };
}hdmipatterngen_hdmi_ptg_tg_line_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_wid_l:13;
        RBus_UInt32  dummy1800d814_15_13:3;
        RBus_UInt32  pat_h_sta_l:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_l_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_len_l:13;
        RBus_UInt32  dummy1800d818_15_13:3;
        RBus_UInt32  pat_v_sta_l:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_l_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_mode_l:4;
        RBus_UInt32  en_xc_l:1;
        RBus_UInt32  xc_seq_l:3;
        RBus_UInt32  en_rdm_bkg_l:1;
        RBus_UInt32  ptg_db_en:1;
        RBus_UInt32  ptg_db_rdy:1;
        RBus_UInt32  res1:21;
    };
}hdmipatterngen_hdmi_ptg_l_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  barw_l:11;
        RBus_UInt32  hold_state_rdy_l:1;
        RBus_UInt32  hold_state_l:2;
        RBus_UInt32  auto_state_l:2;
        RBus_UInt32  res1:16;
    };
}hdmipatterngen_hdmi_ptg_l_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_92b_l:8;
        RBus_UInt32  i_c0cr_92b_l:8;
        RBus_UInt32  i_c0y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_l_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c1cb_92b_l:8;
        RBus_UInt32  i_c1cr_92b_l:8;
        RBus_UInt32  i_c1y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_l_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c2cb_92b_l:8;
        RBus_UInt32  i_c2cr_92b_l:8;
        RBus_UInt32  i_c2y_92b_l:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_l_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800d830_7_0:8;
        RBus_UInt32  i_c3cb_72b_gradcb_l:6;
        RBus_UInt32  i_c3cb_98b_l:2;
        RBus_UInt32  i_c3cr_72b_gradcr_l:6;
        RBus_UInt32  i_c3cr_98b_l:2;
        RBus_UInt32  i_c3y_72b_grady_l:6;
        RBus_UInt32  i_c3y_98b_l:2;
    };
}hdmipatterngen_hdmi_ptg_l_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c4cb_42b_bmp_h_l:3;
        RBus_UInt32  i_c4cb_5b_l:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_l:3;
        RBus_UInt32  i_c4cb_9b_l:1;
        RBus_UInt32  i_c4cr_92b_l:8;
        RBus_UInt32  i_c4y_52b_step_hv_l:4;
        RBus_UInt32  i_c4y_96b_l:4;
    };
}hdmipatterngen_hdmi_ptg_l_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800d838_7_0:8;
        RBus_UInt32  i_c5cb_92b_bmp1_l:8;
        RBus_UInt32  i_c5cr_92b_bmp0_l:8;
        RBus_UInt32  i_c5y_92b_bmptp_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nonactive_color_def_l:8;
        RBus_UInt32  i_c6cb_92b_bmp4_l:8;
        RBus_UInt32  i_c6cr_92b_bmp3_l:8;
        RBus_UInt32  i_c6y_92b_bmp2_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_color_l:3;
        RBus_UInt32  dummy1800d840_7_3:5;
        RBus_UInt32  i_c7cb_92b_bmp7_l:8;
        RBus_UInt32  i_c7cr_92b_bmp6_l:8;
        RBus_UInt32  i_c7y_92b_bmp5_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_adj_num_l:8;
        RBus_UInt32  mv_vs_num_l:4;
        RBus_UInt32  rdm_period_l:3;
        RBus_UInt32  mv_seq_type_l:1;
        RBus_UInt32  mv_v_l:8;
        RBus_UInt32  mv_h_l:8;
    };
}hdmipatterngen_hdmi_ptg_l_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_wid_r:13;
        RBus_UInt32  dummy1800d848_15_13:3;
        RBus_UInt32  pat_h_sta_r:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_r_pat_hsta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_len_r:13;
        RBus_UInt32  dummy1800d84c_15_13:3;
        RBus_UInt32  pat_v_sta_r:13;
        RBus_UInt32  res1:3;
    };
}hdmipatterngen_hdmi_ptg_r_pat_vsta_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_mode_r:4;
        RBus_UInt32  en_xc_r:1;
        RBus_UInt32  xc_seq_r:3;
        RBus_UInt32  en_rdm_bkg_r:1;
        RBus_UInt32  res1:23;
    };
}hdmipatterngen_hdmi_ptg_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  barw_r:11;
        RBus_UInt32  hold_state_rdy_r:1;
        RBus_UInt32  hold_state_r:2;
        RBus_UInt32  auto_state_r:2;
        RBus_UInt32  res1:16;
    };
}hdmipatterngen_hdmi_ptg_r_barw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_92b_r:8;
        RBus_UInt32  i_c0cr_92b_r:8;
        RBus_UInt32  i_c0y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_r_c0y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c1cb_92b_r:8;
        RBus_UInt32  i_c1cr_92b_r:8;
        RBus_UInt32  i_c1y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_r_c1y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c2cb_92b_r:8;
        RBus_UInt32  i_c2cr_92b_r:8;
        RBus_UInt32  i_c2y_92b_r:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_r_c2y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800d864_7_0:8;
        RBus_UInt32  i_c3cb_72b_gradcb_r:6;
        RBus_UInt32  i_c3cb_98b_r:2;
        RBus_UInt32  i_c3cr_72b_gradcr_r:6;
        RBus_UInt32  i_c3cr_98b_r:2;
        RBus_UInt32  i_c3y_72b_grady_r:6;
        RBus_UInt32  i_c3y_98b_r:2;
    };
}hdmipatterngen_hdmi_ptg_r_c3y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_c4cb_42b_bmp_h_r:3;
        RBus_UInt32  i_c4cb_5b_r:1;
        RBus_UInt32  i_c4cb_86b_bmp_w_r:3;
        RBus_UInt32  i_c4cb_9b_r:1;
        RBus_UInt32  i_c4cr_92b_r:8;
        RBus_UInt32  i_c4y_52b_step_hv_r:4;
        RBus_UInt32  i_c4y_96b_r:4;
    };
}hdmipatterngen_hdmi_ptg_r_c4y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800d86c_7_0:8;
        RBus_UInt32  i_c5cb_92b_bmp1_r:8;
        RBus_UInt32  i_c5cr_92b_bmp0_r:8;
        RBus_UInt32  i_c5y_92b_bmptp_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c5y_cr_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nonactive_color_def_r:8;
        RBus_UInt32  i_c6cb_92b_bmp4_r:8;
        RBus_UInt32  i_c6cr_92b_bmp3_r:8;
        RBus_UInt32  i_c6y_92b_bmp2_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c6y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_color_r:3;
        RBus_UInt32  dummy1800d874_7_3:5;
        RBus_UInt32  i_c7cb_92b_bmp7_r:8;
        RBus_UInt32  i_c7cr_92b_bmp6_r:8;
        RBus_UInt32  i_c7y_92b_bmp5_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_c7y_cb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mp_adj_num_r:8;
        RBus_UInt32  mv_vs_num_r:4;
        RBus_UInt32  rdm_period_r:3;
        RBus_UInt32  mv_seq_type_r:1;
        RBus_UInt32  mv_v_r:8;
        RBus_UInt32  mv_h_r:8;
    };
}hdmipatterngen_hdmi_ptg_r_max_color_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grad_cbar_step_hv:4;
        RBus_UInt32  grad_sub_pix_on_mask:3;
        RBus_UInt32  grad_cbar_pos:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  grad_cbar_en:1;
        RBus_UInt32  grad_sub_pix_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  chess_v_size:11;
        RBus_UInt32  res3:5;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bright_en:8;
        RBus_UInt32  cb_bright_en:8;
        RBus_UInt32  y_bright_en:8;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bright:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  bmp_sub_pix_en:1;
        RBus_UInt32  res2:20;
    };
}hdmipatterngen_hdmi_ptg_cmi_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c0cb_ext:2;
        RBus_UInt32  i_c0cr_ext:2;
        RBus_UInt32  i_c0y_ext:2;
        RBus_UInt32  i_c1cb_ext:2;
        RBus_UInt32  i_c1cr_ext:2;
        RBus_UInt32  i_c1y_ext:2;
        RBus_UInt32  i_c2cb_ext:2;
        RBus_UInt32  i_c2cr_ext:2;
        RBus_UInt32  i_c2y_ext:2;
        RBus_UInt32  i_c3cr_ext:2;
        RBus_UInt32  i_c3cb_ext:2;
        RBus_UInt32  i_c3y_ext:2;
        RBus_UInt32  color_ext_en:1;
        RBus_UInt32  res1:7;
    };
}hdmipatterngen_hdmi_ptg_color_extend1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_c4cb_ext:2;
        RBus_UInt32  i_c4cr_ext:2;
        RBus_UInt32  i_c4y_ext:2;
        RBus_UInt32  i_c5cb_ext:2;
        RBus_UInt32  i_c5cr_ext:2;
        RBus_UInt32  i_c5y_ext:2;
        RBus_UInt32  i_c6cb_ext:2;
        RBus_UInt32  i_c6cr_ext:2;
        RBus_UInt32  i_c6y_ext:2;
        RBus_UInt32  i_c7cr_ext:2;
        RBus_UInt32  i_c7cb_ext:2;
        RBus_UInt32  i_c7y_ext:2;
        RBus_UInt32  res1:8;
    };
}hdmipatterngen_hdmi_ptg_color_extend2_RBUS;




#endif 


#endif 
