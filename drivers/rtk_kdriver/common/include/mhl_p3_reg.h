/**
* @file rbusMHL_P3Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MHL_P3_REG_H_
#define _RBUS_MHL_P3_REG_H_

#include "rbus_types.h"



//  MHL_P3 Register Address
#define  MHL_P3_PORT2_MHL_DAL_CTRL                                               0x180B2600
#define  MHL_P3_PORT2_MHL_DAL_CTRL_reg_addr                                      "0xB80B2600"
#define  MHL_P3_PORT2_MHL_DAL_CTRL_reg                                           0xB80B2600
#define  MHL_P3_PORT2_MHL_DAL_CTRL_inst_addr                                     "0x0000"
#define  set_MHL_P3_PORT2_MHL_DAL_CTRL_reg(data)                                 (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DAL_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_MHL_DAL_CTRL_reg                                       (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DAL_CTRL_reg))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_31_29_shift                             (29)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_de_sel_shift                              (28)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_tran_err_thrd_shift                       (24)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_err_thrd_shift                     (20)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_err_thrd_shift                     (16)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_b_r_ch_sel_shift                              (15)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_lowbd_shift                        (8)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_7_6_shift                               (6)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_lowbd_shift                        (0)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_31_29_mask                              (0xE0000000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_de_sel_mask                               (0x10000000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_tran_err_thrd_mask                        (0x0F000000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_err_thrd_mask                      (0x00F00000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_err_thrd_mask                      (0x000F0000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_b_r_ch_sel_mask                               (0x00008000)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_lowbd_mask                         (0x00007F00)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_7_6_mask                                (0x000000C0)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_lowbd_mask                         (0x0000003F)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_31_29(data)                             (0xE0000000&((data)<<29))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_de_sel(data)                              (0x10000000&((data)<<28))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_tran_err_thrd(data)                       (0x0F000000&((data)<<24))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_err_thrd(data)                     (0x00F00000&((data)<<20))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_err_thrd(data)                     (0x000F0000&((data)<<16))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_b_r_ch_sel(data)                              (0x00008000&((data)<<15))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_neg_de_lowbd(data)                        (0x00007F00&((data)<<8))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_dummy_7_6(data)                               (0x000000C0&((data)<<6))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_mhl_pos_de_lowbd(data)                        (0x0000003F&(data))
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_dummy_31_29(data)                         ((0xE0000000&(data))>>29)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_de_sel(data)                          ((0x10000000&(data))>>28)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_tran_err_thrd(data)                   ((0x0F000000&(data))>>24)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_neg_de_err_thrd(data)                 ((0x00F00000&(data))>>20)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_pos_de_err_thrd(data)                 ((0x000F0000&(data))>>16)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_b_r_ch_sel(data)                          ((0x00008000&(data))>>15)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_neg_de_lowbd(data)                    ((0x00007F00&(data))>>8)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_dummy_7_6(data)                           ((0x000000C0&(data))>>6)
#define  MHL_P3_PORT2_MHL_DAL_CTRL_get_mhl_pos_de_lowbd(data)                    (0x0000003F&(data))

#define  MHL_P3_PORT2_MHL_DAL_STATUS                                             0x180B2604
#define  MHL_P3_PORT2_MHL_DAL_STATUS_reg_addr                                    "0xB80B2604"
#define  MHL_P3_PORT2_MHL_DAL_STATUS_reg                                         0xB80B2604
#define  MHL_P3_PORT2_MHL_DAL_STATUS_inst_addr                                   "0x0001"
#define  set_MHL_P3_PORT2_MHL_DAL_STATUS_reg(data)                               (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DAL_STATUS_reg)=data)
#define  get_MHL_P3_PORT2_MHL_DAL_STATUS_reg                                     (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DAL_STATUS_reg))
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_cycle_shift                   (4)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_ver_1_2_shift                           (2)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_en_shift                      (1)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_pn_swap_shift                               (0)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_cycle_mask                    (0x000000F0)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_ver_1_2_mask                            (0x00000004)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_en_mask                       (0x00000002)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_pn_swap_mask                                (0x00000001)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_cycle(data)                   (0x000000F0&((data)<<4))
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_ver_1_2(data)                           (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL_DAL_STATUS_mhl_de_glitch_en(data)                      (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_DAL_STATUS_pn_swap(data)                               (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_DAL_STATUS_get_mhl_de_glitch_cycle(data)               ((0x000000F0&(data))>>4)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_get_mhl_ver_1_2(data)                       ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_get_mhl_de_glitch_en(data)                  ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_DAL_STATUS_get_pn_swap(data)                           (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_MD_CTRL                                                0x180B2608
#define  MHL_P3_PORT2_MHL_MD_CTRL_reg_addr                                       "0xB80B2608"
#define  MHL_P3_PORT2_MHL_MD_CTRL_reg                                            0xB80B2608
#define  MHL_P3_PORT2_MHL_MD_CTRL_inst_addr                                      "0x0002"
#define  set_MHL_P3_PORT2_MHL_MD_CTRL_reg(data)                                  (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_MHL_MD_CTRL_reg                                        (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_CTRL_reg))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_wd_shift                          (26)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_int_shift                         (25)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_shift                                 (24)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per_sel_shift                     (20)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per_shift                         (4)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_shift                             (2)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_cont_shift                        (1)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_start_shift                       (0)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_wd_mask                           (0x04000000)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_int_mask                          (0x02000000)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_mask                                  (0x01000000)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per_sel_mask                      (0x00100000)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per_mask                          (0x000FFFF0)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_mask                              (0x0000000C)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_cont_mask                         (0x00000002)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_start_mask                        (0x00000001)
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_wd(data)                          (0x04000000&((data)<<26))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_err_int(data)                         (0x02000000&((data)<<25))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode(data)                                 (0x01000000&((data)<<24))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per_sel(data)                     (0x00100000&((data)<<20))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_per(data)                         (0x000FFFF0&((data)<<4))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det(data)                             (0x0000000C&((data)<<2))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_cont(data)                        (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_MD_CTRL_mhl_mode_det_start(data)                       (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_err_wd(data)                      ((0x04000000&(data))>>26)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_err_int(data)                     ((0x02000000&(data))>>25)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode(data)                             ((0x01000000&(data))>>24)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_det_per_sel(data)                 ((0x00100000&(data))>>20)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_det_per(data)                     ((0x000FFFF0&(data))>>4)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_det(data)                         ((0x0000000C&(data))>>2)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_det_cont(data)                    ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_MD_CTRL_get_mhl_mode_det_start(data)                   (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_MD_THRESHOLD                                           0x180B260C
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_reg_addr                                  "0xB80B260C"
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_reg                                       0xB80B260C
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_inst_addr                                 "0x0003"
#define  set_MHL_P3_PORT2_MHL_MD_THRESHOLD_reg(data)                             (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_THRESHOLD_reg)=data)
#define  get_MHL_P3_PORT2_MHL_MD_THRESHOLD_reg                                   (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_THRESHOLD_reg))
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_pp_shift                        (16)
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_24bits_shift                    (0)
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_pp_mask                         (0xFFFF0000)
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_24bits_mask                     (0x0000FFFF)
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_pp(data)                        (0xFFFF0000&((data)<<16))
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_threshold_24bits(data)                    (0x0000FFFF&(data))
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_get_threshold_pp(data)                    ((0xFFFF0000&(data))>>16)
#define  MHL_P3_PORT2_MHL_MD_THRESHOLD_get_threshold_24bits(data)                (0x0000FFFF&(data))

#define  MHL_P3_PORT2_MHL_MD_CNT                                                 0x180B2610
#define  MHL_P3_PORT2_MHL_MD_CNT_reg_addr                                        "0xB80B2610"
#define  MHL_P3_PORT2_MHL_MD_CNT_reg                                             0xB80B2610
#define  MHL_P3_PORT2_MHL_MD_CNT_inst_addr                                       "0x0004"
#define  set_MHL_P3_PORT2_MHL_MD_CNT_reg(data)                                   (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_CNT_reg)=data)
#define  get_MHL_P3_PORT2_MHL_MD_CNT_reg                                         (*((volatile unsigned int*)MHL_P3_PORT2_MHL_MD_CNT_reg))
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_pp_shift                                (16)
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_24bit_shift                             (0)
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_pp_mask                                 (0xFFFF0000)
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_24bit_mask                              (0x0000FFFF)
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_pp(data)                                (0xFFFF0000&((data)<<16))
#define  MHL_P3_PORT2_MHL_MD_CNT_det_cnt_24bit(data)                             (0x0000FFFF&(data))
#define  MHL_P3_PORT2_MHL_MD_CNT_get_det_cnt_pp(data)                            ((0xFFFF0000&(data))>>16)
#define  MHL_P3_PORT2_MHL_MD_CNT_get_det_cnt_24bit(data)                         (0x0000FFFF&(data))

#define  MHL_P3_PORT2_MHL_DEMUX_CTRL                                             0x180B2614
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_reg_addr                                    "0xB80B2614"
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_reg                                         0xB80B2614
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_inst_addr                                   "0x0005"
#define  set_MHL_P3_PORT2_MHL_DEMUX_CTRL_reg(data)                               (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DEMUX_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_MHL_DEMUX_CTRL_reg                                     (*((volatile unsigned int*)MHL_P3_PORT2_MHL_DEMUX_CTRL_reg))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_video_wd_en_shift                           (12)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_audio_wd_en_shift                           (11)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_wd_en_shift                    (10)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_int_en_shift                   (9)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_det_shift                      (8)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_debug_select_shift                          (7)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_demux_sel_shift                             (4)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_dvi_ch_sync_shift                           (3)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_pp_en_shift                             (1)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_en_shift                                (0)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_video_wd_en_mask                            (0x00001000)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_audio_wd_en_mask                            (0x00000800)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_wd_en_mask                     (0x00000400)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_int_en_mask                    (0x00000200)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_det_mask                       (0x00000100)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_debug_select_mask                           (0x00000080)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_demux_sel_mask                              (0x00000070)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_dvi_ch_sync_mask                            (0x00000008)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_pp_en_mask                              (0x00000002)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_en_mask                                 (0x00000001)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_video_wd_en(data)                           (0x00001000&((data)<<12))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_audio_wd_en(data)                           (0x00000800&((data)<<11))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_wd_en(data)                    (0x00000400&((data)<<10))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_int_en(data)                   (0x00000200&((data)<<9))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_ch_bound_chg_det(data)                      (0x00000100&((data)<<8))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_debug_select(data)                          (0x00000080&((data)<<7))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_demux_sel(data)                             (0x00000070&((data)<<4))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_dvi_ch_sync(data)                           (0x00000008&((data)<<3))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_pp_en(data)                             (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_mhl_en(data)                                (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_video_wd_en(data)                       ((0x00001000&(data))>>12)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_audio_wd_en(data)                       ((0x00000800&(data))>>11)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_ch_bound_chg_wd_en(data)                ((0x00000400&(data))>>10)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_ch_bound_chg_int_en(data)               ((0x00000200&(data))>>9)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_ch_bound_chg_det(data)                  ((0x00000100&(data))>>8)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_debug_select(data)                      ((0x00000080&(data))>>7)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_demux_sel(data)                         ((0x00000070&(data))>>4)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_dvi_ch_sync(data)                       ((0x00000008&(data))>>3)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_mhl_pp_en(data)                         ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_DEMUX_CTRL_get_mhl_en(data)                            (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_STATUS                                                 0x180B2618
#define  MHL_P3_PORT2_MHL_STATUS_reg_addr                                        "0xB80B2618"
#define  MHL_P3_PORT2_MHL_STATUS_reg                                             0xB80B2618
#define  MHL_P3_PORT2_MHL_STATUS_inst_addr                                       "0x0006"
#define  set_MHL_P3_PORT2_MHL_STATUS_reg(data)                                   (*((volatile unsigned int*)MHL_P3_PORT2_MHL_STATUS_reg)=data)
#define  get_MHL_P3_PORT2_MHL_STATUS_reg                                         (*((volatile unsigned int*)MHL_P3_PORT2_MHL_STATUS_reg))
#define  MHL_P3_PORT2_MHL_STATUS_ch_bound_chg_shift                              (12)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_mode_err_shift                              (8)
#define  MHL_P3_PORT2_MHL_STATUS_non_ctrl_glitch_occ_flag_shift                  (5)
#define  MHL_P3_PORT2_MHL_STATUS_ctrl_glitch_occr_flag_shift                     (4)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_tran_err_flag_shift                         (2)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_pos_de_err_flag_shift                       (1)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_neg_de_err_flag_shift                       (0)
#define  MHL_P3_PORT2_MHL_STATUS_ch_bound_chg_mask                               (0x00001000)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_mode_err_mask                               (0x00000100)
#define  MHL_P3_PORT2_MHL_STATUS_non_ctrl_glitch_occ_flag_mask                   (0x00000020)
#define  MHL_P3_PORT2_MHL_STATUS_ctrl_glitch_occr_flag_mask                      (0x00000010)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_tran_err_flag_mask                          (0x00000004)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_pos_de_err_flag_mask                        (0x00000002)
#define  MHL_P3_PORT2_MHL_STATUS_mhl_neg_de_err_flag_mask                        (0x00000001)
#define  MHL_P3_PORT2_MHL_STATUS_ch_bound_chg(data)                              (0x00001000&((data)<<12))
#define  MHL_P3_PORT2_MHL_STATUS_mhl_mode_err(data)                              (0x00000100&((data)<<8))
#define  MHL_P3_PORT2_MHL_STATUS_non_ctrl_glitch_occ_flag(data)                  (0x00000020&((data)<<5))
#define  MHL_P3_PORT2_MHL_STATUS_ctrl_glitch_occr_flag(data)                     (0x00000010&((data)<<4))
#define  MHL_P3_PORT2_MHL_STATUS_mhl_tran_err_flag(data)                         (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL_STATUS_mhl_pos_de_err_flag(data)                       (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_STATUS_mhl_neg_de_err_flag(data)                       (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_STATUS_get_ch_bound_chg(data)                          ((0x00001000&(data))>>12)
#define  MHL_P3_PORT2_MHL_STATUS_get_mhl_mode_err(data)                          ((0x00000100&(data))>>8)
#define  MHL_P3_PORT2_MHL_STATUS_get_non_ctrl_glitch_occ_flag(data)              ((0x00000020&(data))>>5)
#define  MHL_P3_PORT2_MHL_STATUS_get_ctrl_glitch_occr_flag(data)                 ((0x00000010&(data))>>4)
#define  MHL_P3_PORT2_MHL_STATUS_get_mhl_tran_err_flag(data)                     ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL_STATUS_get_mhl_pos_de_err_flag(data)                   ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_STATUS_get_mhl_neg_de_err_flag(data)                   (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_CH_CR                                                  0x180B261C
#define  MHL_P3_PORT2_MHL_CH_CR_reg_addr                                         "0xB80B261C"
#define  MHL_P3_PORT2_MHL_CH_CR_reg                                              0xB80B261C
#define  MHL_P3_PORT2_MHL_CH_CR_inst_addr                                        "0x0007"
#define  set_MHL_P3_PORT2_MHL_CH_CR_reg(data)                                    (*((volatile unsigned int*)MHL_P3_PORT2_MHL_CH_CR_reg)=data)
#define  get_MHL_P3_PORT2_MHL_CH_CR_reg                                          (*((volatile unsigned int*)MHL_P3_PORT2_MHL_CH_CR_reg))
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_flush_shift                           (17)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_afifo_en_shift                        (16)
#define  MHL_P3_PORT2_MHL_CH_CR_dummy_15_2_shift                                 (2)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_flush_shift                           (1)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_afifo_en_shift                        (0)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_flush_mask                            (0x00020000)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask                         (0x00010000)
#define  MHL_P3_PORT2_MHL_CH_CR_dummy_15_2_mask                                  (0x0000FFFC)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_flush_mask                            (0x00000002)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask                         (0x00000001)
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_flush(data)                           (0x00020000&((data)<<17))
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch1_cr_afifo_en(data)                        (0x00010000&((data)<<16))
#define  MHL_P3_PORT2_MHL_CH_CR_dummy_15_2(data)                                 (0x0000FFFC&((data)<<2))
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_flush(data)                           (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_CH_CR_mhl_ch0_cr_afifo_en(data)                        (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_CH_CR_get_mhl_ch1_cr_flush(data)                       ((0x00020000&(data))>>17)
#define  MHL_P3_PORT2_MHL_CH_CR_get_mhl_ch1_cr_afifo_en(data)                    ((0x00010000&(data))>>16)
#define  MHL_P3_PORT2_MHL_CH_CR_get_dummy_15_2(data)                             ((0x0000FFFC&(data))>>2)
#define  MHL_P3_PORT2_MHL_CH_CR_get_mhl_ch0_cr_flush(data)                       ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_CH_CR_get_mhl_ch0_cr_afifo_en(data)                    (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_CH_SR                                                  0x180B2620
#define  MHL_P3_PORT2_MHL_CH_SR_reg_addr                                         "0xB80B2620"
#define  MHL_P3_PORT2_MHL_CH_SR_reg                                              0xB80B2620
#define  MHL_P3_PORT2_MHL_CH_SR_inst_addr                                        "0x0008"
#define  set_MHL_P3_PORT2_MHL_CH_SR_reg(data)                                    (*((volatile unsigned int*)MHL_P3_PORT2_MHL_CH_SR_reg)=data)
#define  get_MHL_P3_PORT2_MHL_CH_SR_reg                                          (*((volatile unsigned int*)MHL_P3_PORT2_MHL_CH_SR_reg))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_shift          (20)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_shift          (19)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wovflow_flag_shift                    (18)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rudflow_flag_shift                    (17)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rflush_flag_shift                     (16)
#define  MHL_P3_PORT2_MHL_CH_SR_dummy_15_5_shift                                 (5)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_shift          (4)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_shift          (3)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wovflow_flag_shift                    (2)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rudflow_flag_shift                    (1)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rflush_flag_shift                     (0)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_mask           (0x00100000)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_mask           (0x00080000)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wovflow_flag_mask                     (0x00040000)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rudflow_flag_mask                     (0x00020000)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rflush_flag_mask                      (0x00010000)
#define  MHL_P3_PORT2_MHL_CH_SR_dummy_15_5_mask                                  (0x0000FFE0)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_mask           (0x00000010)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_mask           (0x00000008)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wovflow_flag_mask                     (0x00000004)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rudflow_flag_mask                     (0x00000002)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rflush_flag_mask                      (0x00000001)
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag(data)          (0x00100000&((data)<<20))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag(data)          (0x00080000&((data)<<19))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_wovflow_flag(data)                    (0x00040000&((data)<<18))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rudflow_flag(data)                    (0x00020000&((data)<<17))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch1_sr_rflush_flag(data)                     (0x00010000&((data)<<16))
#define  MHL_P3_PORT2_MHL_CH_SR_dummy_15_5(data)                                 (0x0000FFE0&((data)<<5))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag(data)          (0x00000010&((data)<<4))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag(data)          (0x00000008&((data)<<3))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_wovflow_flag(data)                    (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rudflow_flag(data)                    (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_CH_SR_mhl_ch0_sr_rflush_flag(data)                     (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch1_sr_wrclk_det_timeout_flag(data)      ((0x00100000&(data))>>20)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch1_sr_rwclk_det_timeout_flag(data)      ((0x00080000&(data))>>19)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch1_sr_wovflow_flag(data)                ((0x00040000&(data))>>18)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch1_sr_rudflow_flag(data)                ((0x00020000&(data))>>17)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch1_sr_rflush_flag(data)                 ((0x00010000&(data))>>16)
#define  MHL_P3_PORT2_MHL_CH_SR_get_dummy_15_5(data)                             ((0x0000FFE0&(data))>>5)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch0_sr_wrclk_det_timeout_flag(data)      ((0x00000010&(data))>>4)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch0_sr_rwclk_det_timeout_flag(data)      ((0x00000008&(data))>>3)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch0_sr_wovflow_flag(data)                ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch0_sr_rudflow_flag(data)                ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_CH_SR_get_mhl_ch0_sr_rflush_flag(data)                 (0x00000001&(data))

#define  MHL_P3_PORT2_MHL3_CTRL                                                  0x180B2700
#define  MHL_P3_PORT2_MHL3_CTRL_reg_addr                                         "0xB80B2700"
#define  MHL_P3_PORT2_MHL3_CTRL_reg                                              0xB80B2700
#define  MHL_P3_PORT2_MHL3_CTRL_inst_addr                                        "0x0009"
#define  set_MHL_P3_PORT2_MHL3_CTRL_reg(data)                                    (*((volatile unsigned int*)MHL_P3_PORT2_MHL3_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_MHL3_CTRL_reg                                          (*((volatile unsigned int*)MHL_P3_PORT2_MHL3_CTRL_reg))
#define  MHL_P3_PORT2_MHL3_CTRL_rr_sync_clr_shift                                (13)
#define  MHL_P3_PORT2_MHL3_CTRL_debug_sel_shift                                  (10)
#define  MHL_P3_PORT2_MHL3_CTRL_pkt_type_decode_sel_shift                        (8)
#define  MHL_P3_PORT2_MHL3_CTRL_errc_sel_shift                                   (5)
#define  MHL_P3_PORT2_MHL3_CTRL_rr_mode_shift                                    (3)
#define  MHL_P3_PORT2_MHL3_CTRL_dummy_2_shift                                    (2)
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_24_16_bit_sel_shift                     (1)
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_en_shift                                (0)
#define  MHL_P3_PORT2_MHL3_CTRL_rr_sync_clr_mask                                 (0x00002000)
#define  MHL_P3_PORT2_MHL3_CTRL_debug_sel_mask                                   (0x00001C00)
#define  MHL_P3_PORT2_MHL3_CTRL_pkt_type_decode_sel_mask                         (0x00000300)
#define  MHL_P3_PORT2_MHL3_CTRL_errc_sel_mask                                    (0x000000E0)
#define  MHL_P3_PORT2_MHL3_CTRL_rr_mode_mask                                     (0x00000018)
#define  MHL_P3_PORT2_MHL3_CTRL_dummy_2_mask                                     (0x00000004)
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_24_16_bit_sel_mask                      (0x00000002)
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_en_mask                                 (0x00000001)
#define  MHL_P3_PORT2_MHL3_CTRL_rr_sync_clr(data)                                (0x00002000&((data)<<13))
#define  MHL_P3_PORT2_MHL3_CTRL_debug_sel(data)                                  (0x00001C00&((data)<<10))
#define  MHL_P3_PORT2_MHL3_CTRL_pkt_type_decode_sel(data)                        (0x00000300&((data)<<8))
#define  MHL_P3_PORT2_MHL3_CTRL_errc_sel(data)                                   (0x000000E0&((data)<<5))
#define  MHL_P3_PORT2_MHL3_CTRL_rr_mode(data)                                    (0x00000018&((data)<<3))
#define  MHL_P3_PORT2_MHL3_CTRL_dummy_2(data)                                    (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_24_16_bit_sel(data)                     (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL3_CTRL_mhl_ver3_en(data)                                (0x00000001&(data))
#define  MHL_P3_PORT2_MHL3_CTRL_get_rr_sync_clr(data)                            ((0x00002000&(data))>>13)
#define  MHL_P3_PORT2_MHL3_CTRL_get_debug_sel(data)                              ((0x00001C00&(data))>>10)
#define  MHL_P3_PORT2_MHL3_CTRL_get_pkt_type_decode_sel(data)                    ((0x00000300&(data))>>8)
#define  MHL_P3_PORT2_MHL3_CTRL_get_errc_sel(data)                               ((0x000000E0&(data))>>5)
#define  MHL_P3_PORT2_MHL3_CTRL_get_rr_mode(data)                                ((0x00000018&(data))>>3)
#define  MHL_P3_PORT2_MHL3_CTRL_get_dummy_2(data)                                ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL3_CTRL_get_mhl_ver3_24_16_bit_sel(data)                 ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL3_CTRL_get_mhl_ver3_en(data)                            (0x00000001&(data))

#define  MHL_P3_PORT2_MHL3_STATUS                                                0x180B2704
#define  MHL_P3_PORT2_MHL3_STATUS_reg_addr                                       "0xB80B2704"
#define  MHL_P3_PORT2_MHL3_STATUS_reg                                            0xB80B2704
#define  MHL_P3_PORT2_MHL3_STATUS_inst_addr                                      "0x000A"
#define  set_MHL_P3_PORT2_MHL3_STATUS_reg(data)                                  (*((volatile unsigned int*)MHL_P3_PORT2_MHL3_STATUS_reg)=data)
#define  get_MHL_P3_PORT2_MHL3_STATUS_reg                                        (*((volatile unsigned int*)MHL_P3_PORT2_MHL3_STATUS_reg))
#define  MHL_P3_PORT2_MHL3_STATUS_bits_per_pixel_mode_shift                      (8)
#define  MHL_P3_PORT2_MHL3_STATUS_max_trans_symbol_err_shift                     (7)
#define  MHL_P3_PORT2_MHL3_STATUS_rr_err_shift                                   (6)
#define  MHL_P3_PORT2_MHL3_STATUS_blank_payload_len_err_shift                    (5)
#define  MHL_P3_PORT2_MHL3_STATUS_video_payload_len_err_shift                    (4)
#define  MHL_P3_PORT2_MHL3_STATUS_hdr_err_shift                                  (3)
#define  MHL_P3_PORT2_MHL3_STATUS_packet_trail_gb_err_shift                      (2)
#define  MHL_P3_PORT2_MHL3_STATUS_packet_lead_gb_err_shift                       (1)
#define  MHL_P3_PORT2_MHL3_STATUS_video_gb_err_shift                             (0)
#define  MHL_P3_PORT2_MHL3_STATUS_bits_per_pixel_mode_mask                       (0x00000300)
#define  MHL_P3_PORT2_MHL3_STATUS_max_trans_symbol_err_mask                      (0x00000080)
#define  MHL_P3_PORT2_MHL3_STATUS_rr_err_mask                                    (0x00000040)
#define  MHL_P3_PORT2_MHL3_STATUS_blank_payload_len_err_mask                     (0x00000020)
#define  MHL_P3_PORT2_MHL3_STATUS_video_payload_len_err_mask                     (0x00000010)
#define  MHL_P3_PORT2_MHL3_STATUS_hdr_err_mask                                   (0x00000008)
#define  MHL_P3_PORT2_MHL3_STATUS_packet_trail_gb_err_mask                       (0x00000004)
#define  MHL_P3_PORT2_MHL3_STATUS_packet_lead_gb_err_mask                        (0x00000002)
#define  MHL_P3_PORT2_MHL3_STATUS_video_gb_err_mask                              (0x00000001)
#define  MHL_P3_PORT2_MHL3_STATUS_bits_per_pixel_mode(data)                      (0x00000300&((data)<<8))
#define  MHL_P3_PORT2_MHL3_STATUS_max_trans_symbol_err(data)                     (0x00000080&((data)<<7))
#define  MHL_P3_PORT2_MHL3_STATUS_rr_err(data)                                   (0x00000040&((data)<<6))
#define  MHL_P3_PORT2_MHL3_STATUS_blank_payload_len_err(data)                    (0x00000020&((data)<<5))
#define  MHL_P3_PORT2_MHL3_STATUS_video_payload_len_err(data)                    (0x00000010&((data)<<4))
#define  MHL_P3_PORT2_MHL3_STATUS_hdr_err(data)                                  (0x00000008&((data)<<3))
#define  MHL_P3_PORT2_MHL3_STATUS_packet_trail_gb_err(data)                      (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL3_STATUS_packet_lead_gb_err(data)                       (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL3_STATUS_video_gb_err(data)                             (0x00000001&(data))
#define  MHL_P3_PORT2_MHL3_STATUS_get_bits_per_pixel_mode(data)                  ((0x00000300&(data))>>8)
#define  MHL_P3_PORT2_MHL3_STATUS_get_max_trans_symbol_err(data)                 ((0x00000080&(data))>>7)
#define  MHL_P3_PORT2_MHL3_STATUS_get_rr_err(data)                               ((0x00000040&(data))>>6)
#define  MHL_P3_PORT2_MHL3_STATUS_get_blank_payload_len_err(data)                ((0x00000020&(data))>>5)
#define  MHL_P3_PORT2_MHL3_STATUS_get_video_payload_len_err(data)                ((0x00000010&(data))>>4)
#define  MHL_P3_PORT2_MHL3_STATUS_get_hdr_err(data)                              ((0x00000008&(data))>>3)
#define  MHL_P3_PORT2_MHL3_STATUS_get_packet_trail_gb_err(data)                  ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL3_STATUS_get_packet_lead_gb_err(data)                   ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL3_STATUS_get_video_gb_err(data)                         (0x00000001&(data))

#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET                                           0x180B2708
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg_addr                                  "0xB80B2708"
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg                                       0xB80B2708
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_inst_addr                                 "0x000B"
#define  set_MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg(data)                             (*((volatile unsigned int*)MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg)=data)
#define  get_MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg                                   (*((volatile unsigned int*)MHL_P3_PORT2_TMDS_BIT_ERR_DET_reg))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_thd_shift                     (16)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_irq_en_shift                      (11)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_reset_shift                       (10)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_period_shift                  (4)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_mode_shift                    (1)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_en_shift                      (0)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_thd_mask                      (0xFFFF0000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_irq_en_mask                       (0x00000800)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_reset_mask                        (0x00000400)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_period_mask                   (0x000003F0)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_mode_mask                     (0x00000002)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_en_mask                       (0x00000001)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_thd(data)                     (0xFFFF0000&((data)<<16))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_irq_en(data)                      (0x00000800&((data)<<11))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_reset(data)                       (0x00000400&((data)<<10))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_period(data)                  (0x000003F0&((data)<<4))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_mode(data)                    (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_bit_err_det_en(data)                      (0x00000001&(data))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_det_thd(data)                 ((0xFFFF0000&(data))>>16)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_irq_en(data)                  ((0x00000800&(data))>>11)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_reset(data)                   ((0x00000400&(data))>>10)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_det_period(data)              ((0x000003F0&(data))>>4)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_det_mode(data)                ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_DET_get_bit_err_det_en(data)                  (0x00000001&(data))

#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS                                        0x180B270C
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg_addr                               "0xB80B270C"
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg                                    0xB80B270C
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_inst_addr                              "0x000C"
#define  set_MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg(data)                          (*((volatile unsigned int*)MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg)=data)
#define  get_MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg                                (*((volatile unsigned int*)MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_reg))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_max_shift                      (26)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_min_shift                      (20)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_no_dis_reset_shift                (19)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_thd_shift                 (18)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_shift                     (17)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt_of_shift              (16)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt_shift                 (0)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_max_mask                       (0xFC000000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_min_mask                       (0x03F00000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_no_dis_reset_mask                 (0x00080000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_thd_mask                  (0x00040000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_mask                      (0x00020000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt_of_mask               (0x00010000)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt_mask                  (0x0000FFFF)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_max(data)                      (0xFC000000&((data)<<26))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_ad_min(data)                      (0x03F00000&((data)<<20))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_no_dis_reset(data)                (0x00080000&((data)<<19))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_thd(data)                 (0x00040000&((data)<<18))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err(data)                     (0x00020000&((data)<<17))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt_of(data)              (0x00010000&((data)<<16))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_tmds_bit_err_cnt(data)                 (0x0000FFFF&(data))
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_ad_max(data)                  ((0xFC000000&(data))>>26)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_ad_min(data)                  ((0x03F00000&(data))>>20)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_no_dis_reset(data)            ((0x00080000&(data))>>19)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_bit_err_thd(data)             ((0x00040000&(data))>>18)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_bit_err(data)                 ((0x00020000&(data))>>17)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_bit_err_cnt_of(data)          ((0x00010000&(data))>>16)
#define  MHL_P3_PORT2_TMDS_BIT_ERR_STATUS_get_tmds_bit_err_cnt(data)             (0x0000FFFF&(data))

#define  MHL_P3_PORT2_MHL_BIST_CTRL                                              0x180B2710
#define  MHL_P3_PORT2_MHL_BIST_CTRL_reg_addr                                     "0xB80B2710"
#define  MHL_P3_PORT2_MHL_BIST_CTRL_reg                                          0xB80B2710
#define  MHL_P3_PORT2_MHL_BIST_CTRL_inst_addr                                    "0x000D"
#define  set_MHL_P3_PORT2_MHL_BIST_CTRL_reg(data)                                (*((volatile unsigned int*)MHL_P3_PORT2_MHL_BIST_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_MHL_BIST_CTRL_reg                                      (*((volatile unsigned int*)MHL_P3_PORT2_MHL_BIST_CTRL_reg))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_frame_num_shift                         (24)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_dummy_23_shift                               (23)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_fixed10_align_en_shift                       (22)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed_shift                             (12)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fix10_inverse_shift                     (11)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_en_shift                     (10)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_num_shift                    (8)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_en_shift                                (7)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_pattern_shift                           (5)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_duration_shift                          (4)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_stop_shift                              (3)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_rdm_bypass_shift                        (2)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_cnt_mode_shift                          (1)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed10_align_bypass_shift              (0)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_frame_num_mask                          (0xFF000000)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_dummy_23_mask                                (0x00800000)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_fixed10_align_en_mask                        (0x00400000)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed_mask                              (0x003FF000)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fix10_inverse_mask                      (0x00000800)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_en_mask                      (0x00000400)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_num_mask                     (0x00000300)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_en_mask                                 (0x00000080)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_pattern_mask                            (0x00000060)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_duration_mask                           (0x00000010)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_stop_mask                               (0x00000008)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_rdm_bypass_mask                         (0x00000004)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_cnt_mode_mask                           (0x00000002)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed10_align_bypass_mask               (0x00000001)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_frame_num(data)                         (0xFF000000&((data)<<24))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_dummy_23(data)                               (0x00800000&((data)<<23))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_fixed10_align_en(data)                       (0x00400000&((data)<<22))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed(data)                             (0x003FF000&((data)<<12))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fix10_inverse(data)                     (0x00000800&((data)<<11))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_en(data)                     (0x00000400&((data)<<10))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_data_align_num(data)                    (0x00000300&((data)<<8))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_en(data)                                (0x00000080&((data)<<7))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_pattern(data)                           (0x00000060&((data)<<5))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_duration(data)                          (0x00000010&((data)<<4))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_stop(data)                              (0x00000008&((data)<<3))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_rdm_bypass(data)                        (0x00000004&((data)<<2))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_cnt_mode(data)                          (0x00000002&((data)<<1))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_bist_fixed10_align_bypass(data)              (0x00000001&(data))
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_frame_num(data)                     ((0xFF000000&(data))>>24)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_dummy_23(data)                           ((0x00800000&(data))>>23)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_fixed10_align_en(data)                   ((0x00400000&(data))>>22)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_fixed(data)                         ((0x003FF000&(data))>>12)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_fix10_inverse(data)                 ((0x00000800&(data))>>11)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_data_align_en(data)                 ((0x00000400&(data))>>10)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_data_align_num(data)                ((0x00000300&(data))>>8)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_en(data)                            ((0x00000080&(data))>>7)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_pattern(data)                       ((0x00000060&(data))>>5)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_duration(data)                      ((0x00000010&(data))>>4)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_stop(data)                          ((0x00000008&(data))>>3)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_rdm_bypass(data)                    ((0x00000004&(data))>>2)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_cnt_mode(data)                      ((0x00000002&(data))>>1)
#define  MHL_P3_PORT2_MHL_BIST_CTRL_get_bist_fixed10_align_bypass(data)          (0x00000001&(data))

#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT                                           0x180B2714
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg_addr                                  "0xB80B2714"
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg                                       0xB80B2714
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_inst_addr                                 "0x000E"
#define  set_MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg(data)                             (*((volatile unsigned int*)MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg)=data)
#define  get_MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg                                   (*((volatile unsigned int*)MHL_P3_PORT2_MHL_BIST_ERR_CNT_reg))
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_fixed10_align_done_shift                  (16)
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_bist_err_cnt_shift                        (0)
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_fixed10_align_done_mask                   (0x00010000)
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_bist_err_cnt_mask                         (0x0000FFFF)
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_fixed10_align_done(data)                  (0x00010000&((data)<<16))
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_bist_err_cnt(data)                        (0x0000FFFF&(data))
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_get_fixed10_align_done(data)              ((0x00010000&(data))>>16)
#define  MHL_P3_PORT2_MHL_BIST_ERR_CNT_get_bist_err_cnt(data)                    (0x0000FFFF&(data))

#define  MHL_P3_PORT2_HDCP_CTRL                                                  0x180B2718
#define  MHL_P3_PORT2_HDCP_CTRL_reg_addr                                         "0xB80B2718"
#define  MHL_P3_PORT2_HDCP_CTRL_reg                                              0xB80B2718
#define  MHL_P3_PORT2_HDCP_CTRL_inst_addr                                        "0x000F"
#define  set_MHL_P3_PORT2_HDCP_CTRL_reg(data)                                    (*((volatile unsigned int*)MHL_P3_PORT2_HDCP_CTRL_reg)=data)
#define  get_MHL_P3_PORT2_HDCP_CTRL_reg                                          (*((volatile unsigned int*)MHL_P3_PORT2_HDCP_CTRL_reg))
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_end_shift                             (12)
#define  MHL_P3_PORT2_HDCP_CTRL_dummy_11_10_shift                                (10)
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_start_shift                           (0)
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_end_mask                              (0x001FF000)
#define  MHL_P3_PORT2_HDCP_CTRL_dummy_11_10_mask                                 (0x00000C00)
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_start_mask                            (0x000003FF)
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_end(data)                             (0x001FF000&((data)<<12))
#define  MHL_P3_PORT2_HDCP_CTRL_dummy_11_10(data)                                (0x00000C00&((data)<<10))
#define  MHL_P3_PORT2_HDCP_CTRL_enc_window_start(data)                           (0x000003FF&(data))
#define  MHL_P3_PORT2_HDCP_CTRL_get_enc_window_end(data)                         ((0x001FF000&(data))>>12)
#define  MHL_P3_PORT2_HDCP_CTRL_get_dummy_11_10(data)                            ((0x00000C00&(data))>>10)
#define  MHL_P3_PORT2_HDCP_CTRL_get_enc_window_start(data)                       (0x000003FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MHL_P3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2600_31_29:3;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  dummy180b2600_7_6:2;
        RBus_UInt32  mhl_pos_de_lowbd:6;
    };
}mhl_p3_port2_mhl_dal_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mhl_de_glitch_cycle:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  mhl_ver_1_2:1;
        RBus_UInt32  mhl_de_glitch_en:1;
        RBus_UInt32  pn_swap:1;
    };
}mhl_p3_port2_mhl_dal_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  mhl_mode_err_wd:1;
        RBus_UInt32  mhl_mode_err_int:1;
        RBus_UInt32  mhl_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mhl_mode_det_per_sel:1;
        RBus_UInt32  mhl_mode_det_per:16;
        RBus_UInt32  mhl_mode_det:2;
        RBus_UInt32  mhl_mode_det_cont:1;
        RBus_UInt32  mhl_mode_det_start:1;
    };
}mhl_p3_port2_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_pp:16;
        RBus_UInt32  threshold_24bits:16;
    };
}mhl_p3_port2_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_pp:16;
        RBus_UInt32  det_cnt_24bit:16;
    };
}mhl_p3_port2_mhl_md_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  video_wd_en:1;
        RBus_UInt32  audio_wd_en:1;
        RBus_UInt32  ch_bound_chg_wd_en:1;
        RBus_UInt32  ch_bound_chg_int_en:1;
        RBus_UInt32  ch_bound_chg_det:1;
        RBus_UInt32  debug_select:1;
        RBus_UInt32  demux_sel:3;
        RBus_UInt32  dvi_ch_sync:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mhl_pp_en:1;
        RBus_UInt32  mhl_en:1;
    };
}mhl_p3_port2_mhl_demux_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch_bound_chg:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mhl_mode_err:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  non_ctrl_glitch_occ_flag:1;
        RBus_UInt32  ctrl_glitch_occr_flag:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  mhl_tran_err_flag:1;
        RBus_UInt32  mhl_pos_de_err_flag:1;
        RBus_UInt32  mhl_neg_de_err_flag:1;
    };
}mhl_p3_port2_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  dummy180b261c_15_2:14;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
    };
}mhl_p3_port2_mhl_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mhl_ch1_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rflush_flag:1;
        RBus_UInt32  dummy180b2620_15_5:11;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
    };
}mhl_p3_port2_mhl_ch_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  rr_sync_clr:1;
        RBus_UInt32  debug_sel:3;
        RBus_UInt32  pkt_type_decode_sel:2;
        RBus_UInt32  errc_sel:3;
        RBus_UInt32  rr_mode:2;
        RBus_UInt32  dummy180b2700_2:1;
        RBus_UInt32  mhl_ver3_24_16_bit_sel:1;
        RBus_UInt32  mhl_ver3_en:1;
    };
}mhl_p3_port2_mhl3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  bits_per_pixel_mode:2;
        RBus_UInt32  max_trans_symbol_err:1;
        RBus_UInt32  rr_err:1;
        RBus_UInt32  blank_payload_len_err:1;
        RBus_UInt32  video_payload_len_err:1;
        RBus_UInt32  hdr_err:1;
        RBus_UInt32  packet_trail_gb_err:1;
        RBus_UInt32  packet_lead_gb_err:1;
        RBus_UInt32  video_gb_err:1;
    };
}mhl_p3_port2_mhl3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_err_det_thd:16;
        RBus_UInt32  res1:4;
        RBus_UInt32  bit_err_irq_en:1;
        RBus_UInt32  bit_err_reset:1;
        RBus_UInt32  bit_err_det_period:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  bit_err_det_mode:1;
        RBus_UInt32  bit_err_det_en:1;
    };
}mhl_p3_port2_tmds_bit_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmds_ad_max:6;
        RBus_UInt32  tmds_ad_min:6;
        RBus_UInt32  tmds_no_dis_reset:1;
        RBus_UInt32  tmds_bit_err_thd:1;
        RBus_UInt32  tmds_bit_err:1;
        RBus_UInt32  tmds_bit_err_cnt_of:1;
        RBus_UInt32  tmds_bit_err_cnt:16;
    };
}mhl_p3_port2_tmds_bit_err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_frame_num:8;
        RBus_UInt32  dummy180b2710_23:1;
        RBus_UInt32  fixed10_align_en:1;
        RBus_UInt32  bist_fixed:10;
        RBus_UInt32  bist_fix10_inverse:1;
        RBus_UInt32  bist_data_align_en:1;
        RBus_UInt32  bist_data_align_num:2;
        RBus_UInt32  bist_en:1;
        RBus_UInt32  bist_pattern:2;
        RBus_UInt32  bist_duration:1;
        RBus_UInt32  bist_stop:1;
        RBus_UInt32  bist_rdm_bypass:1;
        RBus_UInt32  bist_cnt_mode:1;
        RBus_UInt32  bist_fixed10_align_bypass:1;
    };
}mhl_p3_port2_mhl_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  fixed10_align_done:1;
        RBus_UInt32  bist_err_cnt:16;
    };
}mhl_p3_port2_mhl_bist_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  enc_window_end:9;
        RBus_UInt32  dummy180b2718_11_10:2;
        RBus_UInt32  enc_window_start:10;
    };
}mhl_p3_port2_hdcp_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MHL_P3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_pos_de_lowbd:6;
        RBus_UInt32  dummy180b2600_7_6:2;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  dummy180b2600_31_29:3;
    };
}mhl_p3_port2_mhl_dal_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pn_swap:1;
        RBus_UInt32  mhl_de_glitch_en:1;
        RBus_UInt32  mhl_ver_1_2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mhl_de_glitch_cycle:4;
        RBus_UInt32  res2:24;
    };
}mhl_p3_port2_mhl_dal_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_mode_det_start:1;
        RBus_UInt32  mhl_mode_det_cont:1;
        RBus_UInt32  mhl_mode_det:2;
        RBus_UInt32  mhl_mode_det_per:16;
        RBus_UInt32  mhl_mode_det_per_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  mhl_mode:1;
        RBus_UInt32  mhl_mode_err_int:1;
        RBus_UInt32  mhl_mode_err_wd:1;
        RBus_UInt32  res2:5;
    };
}mhl_p3_port2_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_24bits:16;
        RBus_UInt32  threshold_pp:16;
    };
}mhl_p3_port2_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_24bit:16;
        RBus_UInt32  det_cnt_pp:16;
    };
}mhl_p3_port2_mhl_md_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_en:1;
        RBus_UInt32  mhl_pp_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dvi_ch_sync:1;
        RBus_UInt32  demux_sel:3;
        RBus_UInt32  debug_select:1;
        RBus_UInt32  ch_bound_chg_det:1;
        RBus_UInt32  ch_bound_chg_int_en:1;
        RBus_UInt32  ch_bound_chg_wd_en:1;
        RBus_UInt32  audio_wd_en:1;
        RBus_UInt32  video_wd_en:1;
        RBus_UInt32  res2:19;
    };
}mhl_p3_port2_mhl_demux_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_neg_de_err_flag:1;
        RBus_UInt32  mhl_pos_de_err_flag:1;
        RBus_UInt32  mhl_tran_err_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ctrl_glitch_occr_flag:1;
        RBus_UInt32  non_ctrl_glitch_occ_flag:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mhl_mode_err:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ch_bound_chg:1;
        RBus_UInt32  res4:19;
    };
}mhl_p3_port2_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  dummy180b261c_15:14;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  res1:14;
    };
}mhl_p3_port2_mhl_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  dummy180b2620_15:11;
        RBus_UInt32  mhl_ch1_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch1_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  res1:11;
    };
}mhl_p3_port2_mhl_ch_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ver3_en:1;
        RBus_UInt32  mhl_ver3_24_16_bit_sel:1;
        RBus_UInt32  dummy180b2700_2:1;
        RBus_UInt32  rr_mode:2;
        RBus_UInt32  errc_sel:3;
        RBus_UInt32  pkt_type_decode_sel:2;
        RBus_UInt32  debug_sel:3;
        RBus_UInt32  rr_sync_clr:1;
        RBus_UInt32  res1:18;
    };
}mhl_p3_port2_mhl3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  video_gb_err:1;
        RBus_UInt32  packet_lead_gb_err:1;
        RBus_UInt32  packet_trail_gb_err:1;
        RBus_UInt32  hdr_err:1;
        RBus_UInt32  video_payload_len_err:1;
        RBus_UInt32  blank_payload_len_err:1;
        RBus_UInt32  rr_err:1;
        RBus_UInt32  max_trans_symbol_err:1;
        RBus_UInt32  bits_per_pixel_mode:2;
        RBus_UInt32  res1:22;
    };
}mhl_p3_port2_mhl3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_err_det_en:1;
        RBus_UInt32  bit_err_det_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  bit_err_det_period:6;
        RBus_UInt32  bit_err_reset:1;
        RBus_UInt32  bit_err_irq_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  bit_err_det_thd:16;
    };
}mhl_p3_port2_tmds_bit_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmds_bit_err_cnt:16;
        RBus_UInt32  tmds_bit_err_cnt_of:1;
        RBus_UInt32  tmds_bit_err:1;
        RBus_UInt32  tmds_bit_err_thd:1;
        RBus_UInt32  tmds_no_dis_reset:1;
        RBus_UInt32  tmds_ad_min:6;
        RBus_UInt32  tmds_ad_max:6;
    };
}mhl_p3_port2_tmds_bit_err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fixed10_align_bypass:1;
        RBus_UInt32  bist_cnt_mode:1;
        RBus_UInt32  bist_rdm_bypass:1;
        RBus_UInt32  bist_stop:1;
        RBus_UInt32  bist_duration:1;
        RBus_UInt32  bist_pattern:2;
        RBus_UInt32  bist_en:1;
        RBus_UInt32  bist_data_align_num:2;
        RBus_UInt32  bist_data_align_en:1;
        RBus_UInt32  bist_fix10_inverse:1;
        RBus_UInt32  bist_fixed:10;
        RBus_UInt32  fixed10_align_en:1;
        RBus_UInt32  dummy180b2710_23:1;
        RBus_UInt32  bist_frame_num:8;
    };
}mhl_p3_port2_mhl_bist_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_err_cnt:16;
        RBus_UInt32  fixed10_align_done:1;
        RBus_UInt32  res1:15;
    };
}mhl_p3_port2_mhl_bist_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enc_window_start:10;
        RBus_UInt32  dummy180b2718_11_10:2;
        RBus_UInt32  enc_window_end:9;
        RBus_UInt32  res1:11;
    };
}mhl_p3_port2_hdcp_ctrl_RBUS;




#endif 


#endif 
