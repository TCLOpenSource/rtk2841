/**
* @file rbusMHL_P0Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/21
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MHL_P0_REG_H_
#define _RBUS_MHL_P0_REG_H_

#include "rbus_types.h"



//  MHL_P0 Register Address
#define  MHL_P0_PORT0_MHL_DAL_CTRL                                               0x1800D600
#define  MHL_P0_PORT0_MHL_DAL_CTRL_reg_addr                                      "0xB800D600"
#define  MHL_P0_PORT0_MHL_DAL_CTRL_reg                                           0xB800D600
#define  MHL_P0_PORT0_MHL_DAL_CTRL_inst_addr                                     "0x0000"
#define  set_MHL_P0_PORT0_MHL_DAL_CTRL_reg(data)                                 (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DAL_CTRL_reg)=data)
#define  get_MHL_P0_PORT0_MHL_DAL_CTRL_reg                                       (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DAL_CTRL_reg))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_31_29_shift                             (29)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_de_sel_shift                              (28)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_tran_err_thrd_shift                       (24)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_err_thrd_shift                     (20)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_err_thrd_shift                     (16)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_b_r_ch_sel_shift                              (15)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_lowbd_shift                        (8)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_7_6_shift                               (6)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_lowbd_shift                        (0)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_31_29_mask                              (0xE0000000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_de_sel_mask                               (0x10000000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_tran_err_thrd_mask                        (0x0F000000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_err_thrd_mask                      (0x00F00000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_err_thrd_mask                      (0x000F0000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_b_r_ch_sel_mask                               (0x00008000)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_lowbd_mask                         (0x00007F00)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_7_6_mask                                (0x000000C0)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_lowbd_mask                         (0x0000003F)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_31_29(data)                             (0xE0000000&((data)<<29))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_de_sel(data)                              (0x10000000&((data)<<28))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_tran_err_thrd(data)                       (0x0F000000&((data)<<24))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_err_thrd(data)                     (0x00F00000&((data)<<20))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_err_thrd(data)                     (0x000F0000&((data)<<16))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_b_r_ch_sel(data)                              (0x00008000&((data)<<15))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_neg_de_lowbd(data)                        (0x00007F00&((data)<<8))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_dummy_7_6(data)                               (0x000000C0&((data)<<6))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_mhl_pos_de_lowbd(data)                        (0x0000003F&(data))
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_dummy_31_29(data)                         ((0xE0000000&(data))>>29)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_de_sel(data)                          ((0x10000000&(data))>>28)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_tran_err_thrd(data)                   ((0x0F000000&(data))>>24)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_neg_de_err_thrd(data)                 ((0x00F00000&(data))>>20)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_pos_de_err_thrd(data)                 ((0x000F0000&(data))>>16)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_b_r_ch_sel(data)                          ((0x00008000&(data))>>15)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_neg_de_lowbd(data)                    ((0x00007F00&(data))>>8)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_dummy_7_6(data)                           ((0x000000C0&(data))>>6)
#define  MHL_P0_PORT0_MHL_DAL_CTRL_get_mhl_pos_de_lowbd(data)                    (0x0000003F&(data))

#define  MHL_P0_PORT0_MHL_DAL_STATUS                                             0x1800D604
#define  MHL_P0_PORT0_MHL_DAL_STATUS_reg_addr                                    "0xB800D604"
#define  MHL_P0_PORT0_MHL_DAL_STATUS_reg                                         0xB800D604
#define  MHL_P0_PORT0_MHL_DAL_STATUS_inst_addr                                   "0x0001"
#define  set_MHL_P0_PORT0_MHL_DAL_STATUS_reg(data)                               (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DAL_STATUS_reg)=data)
#define  get_MHL_P0_PORT0_MHL_DAL_STATUS_reg                                     (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DAL_STATUS_reg))
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_cycle_shift                   (4)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_ver_1_2_shift                           (2)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_en_shift                      (1)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_pn_swap_shift                               (0)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_cycle_mask                    (0x000000F0)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_ver_1_2_mask                            (0x00000004)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_en_mask                       (0x00000002)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_pn_swap_mask                                (0x00000001)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_cycle(data)                   (0x000000F0&((data)<<4))
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_ver_1_2(data)                           (0x00000004&((data)<<2))
#define  MHL_P0_PORT0_MHL_DAL_STATUS_mhl_de_glitch_en(data)                      (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_DAL_STATUS_pn_swap(data)                               (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_DAL_STATUS_get_mhl_de_glitch_cycle(data)               ((0x000000F0&(data))>>4)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_get_mhl_ver_1_2(data)                       ((0x00000004&(data))>>2)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_get_mhl_de_glitch_en(data)                  ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_DAL_STATUS_get_pn_swap(data)                           (0x00000001&(data))

#define  MHL_P0_PORT0_MHL_MD_CTRL                                                0x1800D608
#define  MHL_P0_PORT0_MHL_MD_CTRL_reg_addr                                       "0xB800D608"
#define  MHL_P0_PORT0_MHL_MD_CTRL_reg                                            0xB800D608
#define  MHL_P0_PORT0_MHL_MD_CTRL_inst_addr                                      "0x0002"
#define  set_MHL_P0_PORT0_MHL_MD_CTRL_reg(data)                                  (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_CTRL_reg)=data)
#define  get_MHL_P0_PORT0_MHL_MD_CTRL_reg                                        (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_CTRL_reg))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_wd_shift                          (26)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_int_shift                         (25)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_shift                                 (24)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per_sel_shift                     (20)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per_shift                         (4)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_shift                             (2)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_cont_shift                        (1)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_start_shift                       (0)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_wd_mask                           (0x04000000)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_int_mask                          (0x02000000)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_mask                                  (0x01000000)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per_sel_mask                      (0x00100000)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per_mask                          (0x000FFFF0)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_mask                              (0x0000000C)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_cont_mask                         (0x00000002)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_start_mask                        (0x00000001)
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_wd(data)                          (0x04000000&((data)<<26))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_err_int(data)                         (0x02000000&((data)<<25))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode(data)                                 (0x01000000&((data)<<24))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per_sel(data)                     (0x00100000&((data)<<20))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_per(data)                         (0x000FFFF0&((data)<<4))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det(data)                             (0x0000000C&((data)<<2))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_cont(data)                        (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_MD_CTRL_mhl_mode_det_start(data)                       (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_err_wd(data)                      ((0x04000000&(data))>>26)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_err_int(data)                     ((0x02000000&(data))>>25)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode(data)                             ((0x01000000&(data))>>24)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_det_per_sel(data)                 ((0x00100000&(data))>>20)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_det_per(data)                     ((0x000FFFF0&(data))>>4)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_det(data)                         ((0x0000000C&(data))>>2)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_det_cont(data)                    ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_MD_CTRL_get_mhl_mode_det_start(data)                   (0x00000001&(data))

#define  MHL_P0_PORT0_MHL_MD_THRESHOLD                                           0x1800D60C
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_reg_addr                                  "0xB800D60C"
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_reg                                       0xB800D60C
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_inst_addr                                 "0x0003"
#define  set_MHL_P0_PORT0_MHL_MD_THRESHOLD_reg(data)                             (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_THRESHOLD_reg)=data)
#define  get_MHL_P0_PORT0_MHL_MD_THRESHOLD_reg                                   (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_THRESHOLD_reg))
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_pp_shift                        (16)
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_24bits_shift                    (0)
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_pp_mask                         (0xFFFF0000)
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_24bits_mask                     (0x0000FFFF)
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_pp(data)                        (0xFFFF0000&((data)<<16))
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_threshold_24bits(data)                    (0x0000FFFF&(data))
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_get_threshold_pp(data)                    ((0xFFFF0000&(data))>>16)
#define  MHL_P0_PORT0_MHL_MD_THRESHOLD_get_threshold_24bits(data)                (0x0000FFFF&(data))

#define  MHL_P0_PORT0_MHL_MD_CNT                                                 0x1800D610
#define  MHL_P0_PORT0_MHL_MD_CNT_reg_addr                                        "0xB800D610"
#define  MHL_P0_PORT0_MHL_MD_CNT_reg                                             0xB800D610
#define  MHL_P0_PORT0_MHL_MD_CNT_inst_addr                                       "0x0004"
#define  set_MHL_P0_PORT0_MHL_MD_CNT_reg(data)                                   (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_CNT_reg)=data)
#define  get_MHL_P0_PORT0_MHL_MD_CNT_reg                                         (*((volatile unsigned int*)MHL_P0_PORT0_MHL_MD_CNT_reg))
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_pp_shift                                (16)
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_24bit_shift                             (0)
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_pp_mask                                 (0xFFFF0000)
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_24bit_mask                              (0x0000FFFF)
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_pp(data)                                (0xFFFF0000&((data)<<16))
#define  MHL_P0_PORT0_MHL_MD_CNT_det_cnt_24bit(data)                             (0x0000FFFF&(data))
#define  MHL_P0_PORT0_MHL_MD_CNT_get_det_cnt_pp(data)                            ((0xFFFF0000&(data))>>16)
#define  MHL_P0_PORT0_MHL_MD_CNT_get_det_cnt_24bit(data)                         (0x0000FFFF&(data))

#define  MHL_P0_PORT0_MHL_DEMUX_CTRL                                             0x1800D614
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_reg_addr                                    "0xB800D614"
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_reg                                         0xB800D614
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_inst_addr                                   "0x0005"
#define  set_MHL_P0_PORT0_MHL_DEMUX_CTRL_reg(data)                               (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DEMUX_CTRL_reg)=data)
#define  get_MHL_P0_PORT0_MHL_DEMUX_CTRL_reg                                     (*((volatile unsigned int*)MHL_P0_PORT0_MHL_DEMUX_CTRL_reg))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_video_wd_en_shift                           (12)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_audio_wd_en_shift                           (11)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_wd_en_shift                    (10)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_int_en_shift                   (9)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_det_shift                      (8)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_debug_select_shift                          (7)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_demux_sel_shift                             (4)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_shift                           (3)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_shift                             (1)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_shift                                (0)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_video_wd_en_mask                            (0x00001000)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_audio_wd_en_mask                            (0x00000800)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_wd_en_mask                     (0x00000400)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_int_en_mask                    (0x00000200)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_det_mask                       (0x00000100)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_debug_select_mask                           (0x00000080)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_demux_sel_mask                              (0x00000070)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync_mask                            (0x00000008)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en_mask                              (0x00000002)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en_mask                                 (0x00000001)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_video_wd_en(data)                           (0x00001000&((data)<<12))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_audio_wd_en(data)                           (0x00000800&((data)<<11))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_wd_en(data)                    (0x00000400&((data)<<10))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_int_en(data)                   (0x00000200&((data)<<9))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_ch_bound_chg_det(data)                      (0x00000100&((data)<<8))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_debug_select(data)                          (0x00000080&((data)<<7))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_demux_sel(data)                             (0x00000070&((data)<<4))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_dvi_ch_sync(data)                           (0x00000008&((data)<<3))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_pp_en(data)                             (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_mhl_en(data)                                (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_video_wd_en(data)                       ((0x00001000&(data))>>12)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_audio_wd_en(data)                       ((0x00000800&(data))>>11)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_ch_bound_chg_wd_en(data)                ((0x00000400&(data))>>10)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_ch_bound_chg_int_en(data)               ((0x00000200&(data))>>9)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_ch_bound_chg_det(data)                  ((0x00000100&(data))>>8)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_debug_select(data)                      ((0x00000080&(data))>>7)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_demux_sel(data)                         ((0x00000070&(data))>>4)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_dvi_ch_sync(data)                       ((0x00000008&(data))>>3)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_mhl_pp_en(data)                         ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_DEMUX_CTRL_get_mhl_en(data)                            (0x00000001&(data))

#define  MHL_P0_PORT0_MHL_STATUS                                                 0x1800D618
#define  MHL_P0_PORT0_MHL_STATUS_reg_addr                                        "0xB800D618"
#define  MHL_P0_PORT0_MHL_STATUS_reg                                             0xB800D618
#define  MHL_P0_PORT0_MHL_STATUS_inst_addr                                       "0x0006"
#define  set_MHL_P0_PORT0_MHL_STATUS_reg(data)                                   (*((volatile unsigned int*)MHL_P0_PORT0_MHL_STATUS_reg)=data)
#define  get_MHL_P0_PORT0_MHL_STATUS_reg                                         (*((volatile unsigned int*)MHL_P0_PORT0_MHL_STATUS_reg))
#define  MHL_P0_PORT0_MHL_STATUS_ch_bound_chg_shift                              (12)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_mode_err_shift                              (8)
#define  MHL_P0_PORT0_MHL_STATUS_non_ctrl_glitch_occ_flag_shift                  (5)
#define  MHL_P0_PORT0_MHL_STATUS_ctrl_glitch_occr_flag_shift                     (4)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_tran_err_flag_shift                         (2)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_pos_de_err_flag_shift                       (1)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_neg_de_err_flag_shift                       (0)
#define  MHL_P0_PORT0_MHL_STATUS_ch_bound_chg_mask                               (0x00001000)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_mode_err_mask                               (0x00000100)
#define  MHL_P0_PORT0_MHL_STATUS_non_ctrl_glitch_occ_flag_mask                   (0x00000020)
#define  MHL_P0_PORT0_MHL_STATUS_ctrl_glitch_occr_flag_mask                      (0x00000010)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_tran_err_flag_mask                          (0x00000004)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_pos_de_err_flag_mask                        (0x00000002)
#define  MHL_P0_PORT0_MHL_STATUS_mhl_neg_de_err_flag_mask                        (0x00000001)
#define  MHL_P0_PORT0_MHL_STATUS_ch_bound_chg(data)                              (0x00001000&((data)<<12))
#define  MHL_P0_PORT0_MHL_STATUS_mhl_mode_err(data)                              (0x00000100&((data)<<8))
#define  MHL_P0_PORT0_MHL_STATUS_non_ctrl_glitch_occ_flag(data)                  (0x00000020&((data)<<5))
#define  MHL_P0_PORT0_MHL_STATUS_ctrl_glitch_occr_flag(data)                     (0x00000010&((data)<<4))
#define  MHL_P0_PORT0_MHL_STATUS_mhl_tran_err_flag(data)                         (0x00000004&((data)<<2))
#define  MHL_P0_PORT0_MHL_STATUS_mhl_pos_de_err_flag(data)                       (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_STATUS_mhl_neg_de_err_flag(data)                       (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_STATUS_get_ch_bound_chg(data)                          ((0x00001000&(data))>>12)
#define  MHL_P0_PORT0_MHL_STATUS_get_mhl_mode_err(data)                          ((0x00000100&(data))>>8)
#define  MHL_P0_PORT0_MHL_STATUS_get_non_ctrl_glitch_occ_flag(data)              ((0x00000020&(data))>>5)
#define  MHL_P0_PORT0_MHL_STATUS_get_ctrl_glitch_occr_flag(data)                 ((0x00000010&(data))>>4)
#define  MHL_P0_PORT0_MHL_STATUS_get_mhl_tran_err_flag(data)                     ((0x00000004&(data))>>2)
#define  MHL_P0_PORT0_MHL_STATUS_get_mhl_pos_de_err_flag(data)                   ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_STATUS_get_mhl_neg_de_err_flag(data)                   (0x00000001&(data))

#define  MHL_P0_PORT0_MHL_CH_CR                                                  0x1800D61C
#define  MHL_P0_PORT0_MHL_CH_CR_reg_addr                                         "0xB800D61C"
#define  MHL_P0_PORT0_MHL_CH_CR_reg                                              0xB800D61C
#define  MHL_P0_PORT0_MHL_CH_CR_inst_addr                                        "0x0007"
#define  set_MHL_P0_PORT0_MHL_CH_CR_reg(data)                                    (*((volatile unsigned int*)MHL_P0_PORT0_MHL_CH_CR_reg)=data)
#define  get_MHL_P0_PORT0_MHL_CH_CR_reg                                          (*((volatile unsigned int*)MHL_P0_PORT0_MHL_CH_CR_reg))
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_flush_shift                           (17)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_shift                        (16)
#define  MHL_P0_PORT0_MHL_CH_CR_dummy_15_2_shift                                 (2)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_flush_shift                           (1)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_shift                        (0)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_flush_mask                            (0x00020000)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en_mask                         (0x00010000)
#define  MHL_P0_PORT0_MHL_CH_CR_dummy_15_2_mask                                  (0x0000FFFC)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_flush_mask                            (0x00000002)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en_mask                         (0x00000001)
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_flush(data)                           (0x00020000&((data)<<17))
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch1_cr_afifo_en(data)                        (0x00010000&((data)<<16))
#define  MHL_P0_PORT0_MHL_CH_CR_dummy_15_2(data)                                 (0x0000FFFC&((data)<<2))
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_flush(data)                           (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_CH_CR_mhl_ch0_cr_afifo_en(data)                        (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_CH_CR_get_mhl_ch1_cr_flush(data)                       ((0x00020000&(data))>>17)
#define  MHL_P0_PORT0_MHL_CH_CR_get_mhl_ch1_cr_afifo_en(data)                    ((0x00010000&(data))>>16)
#define  MHL_P0_PORT0_MHL_CH_CR_get_dummy_15_2(data)                             ((0x0000FFFC&(data))>>2)
#define  MHL_P0_PORT0_MHL_CH_CR_get_mhl_ch0_cr_flush(data)                       ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_CH_CR_get_mhl_ch0_cr_afifo_en(data)                    (0x00000001&(data))

#define  MHL_P0_PORT0_MHL_CH_SR                                                  0x1800D620
#define  MHL_P0_PORT0_MHL_CH_SR_reg_addr                                         "0xB800D620"
#define  MHL_P0_PORT0_MHL_CH_SR_reg                                              0xB800D620
#define  MHL_P0_PORT0_MHL_CH_SR_inst_addr                                        "0x0008"
#define  set_MHL_P0_PORT0_MHL_CH_SR_reg(data)                                    (*((volatile unsigned int*)MHL_P0_PORT0_MHL_CH_SR_reg)=data)
#define  get_MHL_P0_PORT0_MHL_CH_SR_reg                                          (*((volatile unsigned int*)MHL_P0_PORT0_MHL_CH_SR_reg))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_shift          (20)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_shift          (19)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wovflow_flag_shift                    (18)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rudflow_flag_shift                    (17)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rflush_flag_shift                     (16)
#define  MHL_P0_PORT0_MHL_CH_SR_dummy_15_5_shift                                 (5)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_shift          (4)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_shift          (3)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wovflow_flag_shift                    (2)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rudflow_flag_shift                    (1)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rflush_flag_shift                     (0)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag_mask           (0x00100000)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag_mask           (0x00080000)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wovflow_flag_mask                     (0x00040000)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rudflow_flag_mask                     (0x00020000)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rflush_flag_mask                      (0x00010000)
#define  MHL_P0_PORT0_MHL_CH_SR_dummy_15_5_mask                                  (0x0000FFE0)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag_mask           (0x00000010)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag_mask           (0x00000008)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wovflow_flag_mask                     (0x00000004)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rudflow_flag_mask                     (0x00000002)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rflush_flag_mask                      (0x00000001)
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wrclk_det_timeout_flag(data)          (0x00100000&((data)<<20))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rwclk_det_timeout_flag(data)          (0x00080000&((data)<<19))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_wovflow_flag(data)                    (0x00040000&((data)<<18))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rudflow_flag(data)                    (0x00020000&((data)<<17))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch1_sr_rflush_flag(data)                     (0x00010000&((data)<<16))
#define  MHL_P0_PORT0_MHL_CH_SR_dummy_15_5(data)                                 (0x0000FFE0&((data)<<5))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wrclk_det_timeout_flag(data)          (0x00000010&((data)<<4))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rwclk_det_timeout_flag(data)          (0x00000008&((data)<<3))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_wovflow_flag(data)                    (0x00000004&((data)<<2))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rudflow_flag(data)                    (0x00000002&((data)<<1))
#define  MHL_P0_PORT0_MHL_CH_SR_mhl_ch0_sr_rflush_flag(data)                     (0x00000001&(data))
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch1_sr_wrclk_det_timeout_flag(data)      ((0x00100000&(data))>>20)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch1_sr_rwclk_det_timeout_flag(data)      ((0x00080000&(data))>>19)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch1_sr_wovflow_flag(data)                ((0x00040000&(data))>>18)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch1_sr_rudflow_flag(data)                ((0x00020000&(data))>>17)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch1_sr_rflush_flag(data)                 ((0x00010000&(data))>>16)
#define  MHL_P0_PORT0_MHL_CH_SR_get_dummy_15_5(data)                             ((0x0000FFE0&(data))>>5)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch0_sr_wrclk_det_timeout_flag(data)      ((0x00000010&(data))>>4)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch0_sr_rwclk_det_timeout_flag(data)      ((0x00000008&(data))>>3)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch0_sr_wovflow_flag(data)                ((0x00000004&(data))>>2)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch0_sr_rudflow_flag(data)                ((0x00000002&(data))>>1)
#define  MHL_P0_PORT0_MHL_CH_SR_get_mhl_ch0_sr_rflush_flag(data)                 (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MHL_P0 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800d600_31_29:3;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  dummy1800d600_7_6:2;
        RBus_UInt32  mhl_pos_de_lowbd:6;
    };
}mhl_p0_port0_mhl_dal_ctrl_RBUS;

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
}mhl_p0_port0_mhl_dal_status_RBUS;

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
}mhl_p0_port0_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_pp:16;
        RBus_UInt32  threshold_24bits:16;
    };
}mhl_p0_port0_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_pp:16;
        RBus_UInt32  det_cnt_24bit:16;
    };
}mhl_p0_port0_mhl_md_cnt_RBUS;

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
}mhl_p0_port0_mhl_demux_ctrl_RBUS;

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
}mhl_p0_port0_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  dummy1800d61c_15_2:14;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
    };
}mhl_p0_port0_mhl_ch_cr_RBUS;

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
        RBus_UInt32  dummy1800d620_15_5:11;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
    };
}mhl_p0_port0_mhl_ch_sr_RBUS;

#else //apply LITTLE_ENDIAN

//======MHL_P0 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_pos_de_lowbd:6;
        RBus_UInt32  dummy1800d600_7_6:2;
        RBus_UInt32  mhl_neg_de_lowbd:7;
        RBus_UInt32  b_r_ch_sel:1;
        RBus_UInt32  mhl_pos_de_err_thrd:4;
        RBus_UInt32  mhl_neg_de_err_thrd:4;
        RBus_UInt32  mhl_tran_err_thrd:4;
        RBus_UInt32  mhl_de_sel:1;
        RBus_UInt32  dummy1800d600_31_29:3;
    };
}mhl_p0_port0_mhl_dal_ctrl_RBUS;

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
}mhl_p0_port0_mhl_dal_status_RBUS;

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
}mhl_p0_port0_mhl_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold_24bits:16;
        RBus_UInt32  threshold_pp:16;
    };
}mhl_p0_port0_mhl_md_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_cnt_24bit:16;
        RBus_UInt32  det_cnt_pp:16;
    };
}mhl_p0_port0_mhl_md_cnt_RBUS;

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
}mhl_p0_port0_mhl_demux_ctrl_RBUS;

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
}mhl_p0_port0_mhl_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_cr_afifo_en:1;
        RBus_UInt32  mhl_ch0_cr_flush:1;
        RBus_UInt32  dummy1800d61c_15_2:14;
        RBus_UInt32  mhl_ch1_cr_afifo_en:1;
        RBus_UInt32  mhl_ch1_cr_flush:1;
        RBus_UInt32  res1:14;
    };
}mhl_p0_port0_mhl_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_ch0_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch0_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch0_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch0_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  dummy1800d620_15_5:11;
        RBus_UInt32  mhl_ch1_sr_rflush_flag:1;
        RBus_UInt32  mhl_ch1_sr_rudflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_wovflow_flag:1;
        RBus_UInt32  mhl_ch1_sr_rwclk_det_timeout_flag:1;
        RBus_UInt32  mhl_ch1_sr_wrclk_det_timeout_flag:1;
        RBus_UInt32  res1:11;
    };
}mhl_p0_port0_mhl_ch_sr_RBUS;




#endif 


#endif 
