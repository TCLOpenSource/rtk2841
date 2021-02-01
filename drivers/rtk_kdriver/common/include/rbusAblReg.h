/**
* @file rbusAblReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ABL_REG_H_
#define _RBUS_ABL_REG_H_

#include "rbusTypes.h"



//  ABL Register Address
#define  ABL_ABL_CTRL                                                            0x18020200
#define  ABL_ABL_CTRL_reg_addr                                                   "0xB8020200"
#define  ABL_ABL_CTRL_reg                                                        0xB8020200
#define  ABL_ABL_CTRL_inst_addr                                                  "0x0000"
#define  set_ABL_ABL_CTRL_reg(data)                                              (*((volatile unsigned int*)ABL_ABL_CTRL_reg)=data)
#define  get_ABL_ABL_CTRL_reg                                                    (*((volatile unsigned int*)ABL_ABL_CTRL_reg))
#define  ABL_ABL_CTRL_abl_en_shift                                               (31)
#define  ABL_ABL_CTRL_abl_red_en_shift                                           (30)
#define  ABL_ABL_CTRL_abl_grn_en_shift                                           (29)
#define  ABL_ABL_CTRL_abl_blu_en_shift                                           (28)
#define  ABL_ABL_CTRL_dummy_shift1                                                (27)
#define  ABL_ABL_CTRL_abl_software_mode_shift                                    (26)
#define  ABL_ABL_CTRL_abl_min_measure_shift                                      (25)
#define  ABL_ABL_CTRL_abl_ypbpr_en_shift                                         (24)
#define  ABL_ABL_CTRL_abl_online_mode_shift                                      (23)
#define  ABL_ABL_CTRL_dummy_shift2                                                (22)
#define  ABL_ABL_CTRL_abl_max_frame_shift                                        (20)
#define  ABL_ABL_CTRL_abl_r_dir_inv_shift                                        (19)
#define  ABL_ABL_CTRL_abl_g_dir_inv_shift                                        (18)
#define  ABL_ABL_CTRL_abl_b_dir_inv_shift                                        (17)
#define  ABL_ABL_CTRL_abl_href_sel_shift                                         (16)
#define  ABL_ABL_CTRL_abl_target_value_shift                                     (8)
#define  ABL_ABL_CTRL_dummy_shift3                                                (6)
#define  ABL_ABL_CTRL_abl_en_mask                                                (0x80000000)
#define  ABL_ABL_CTRL_abl_red_en_mask                                            (0x40000000)
#define  ABL_ABL_CTRL_abl_grn_en_mask                                            (0x20000000)
#define  ABL_ABL_CTRL_abl_blu_en_mask                                            (0x10000000)
#define  ABL_ABL_CTRL_dummy_mask1                                                 (0x08000000)
#define  ABL_ABL_CTRL_abl_software_mode_mask                                     (0x04000000)
#define  ABL_ABL_CTRL_abl_min_measure_mask                                       (0x02000000)
#define  ABL_ABL_CTRL_abl_ypbpr_en_mask                                          (0x01000000)
#define  ABL_ABL_CTRL_abl_online_mode_mask                                       (0x00800000)
#define  ABL_ABL_CTRL_dummy_mask2                                                 (0x00400000)
#define  ABL_ABL_CTRL_abl_max_frame_mask                                         (0x00300000)
#define  ABL_ABL_CTRL_abl_r_dir_inv_mask                                         (0x00080000)
#define  ABL_ABL_CTRL_abl_g_dir_inv_mask                                         (0x00040000)
#define  ABL_ABL_CTRL_abl_b_dir_inv_mask                                         (0x00020000)
#define  ABL_ABL_CTRL_abl_href_sel_mask                                          (0x00010000)
#define  ABL_ABL_CTRL_abl_target_value_mask                                      (0x00000F00)
#define  ABL_ABL_CTRL_dummy_mask3                                                 (0x000000C0)
#define  ABL_ABL_CTRL_abl_en(data)                                               (0x80000000&((data)<<31))
#define  ABL_ABL_CTRL_abl_red_en(data)                                           (0x40000000&((data)<<30))
#define  ABL_ABL_CTRL_abl_grn_en(data)                                           (0x20000000&((data)<<29))
#define  ABL_ABL_CTRL_abl_blu_en(data)                                           (0x10000000&((data)<<28))
#define  ABL_ABL_CTRL_dummy1(data)                                                (0x08000000&((data)<<27))
#define  ABL_ABL_CTRL_abl_software_mode(data)                                    (0x04000000&((data)<<26))
#define  ABL_ABL_CTRL_abl_min_measure(data)                                      (0x02000000&((data)<<25))
#define  ABL_ABL_CTRL_abl_ypbpr_en(data)                                         (0x01000000&((data)<<24))
#define  ABL_ABL_CTRL_abl_online_mode(data)                                      (0x00800000&((data)<<23))
#define  ABL_ABL_CTRL_dummy2(data)                                                (0x00400000&((data)<<22))
#define  ABL_ABL_CTRL_abl_max_frame(data)                                        (0x00300000&((data)<<20))
#define  ABL_ABL_CTRL_abl_r_dir_inv(data)                                        (0x00080000&((data)<<19))
#define  ABL_ABL_CTRL_abl_g_dir_inv(data)                                        (0x00040000&((data)<<18))
#define  ABL_ABL_CTRL_abl_b_dir_inv(data)                                        (0x00020000&((data)<<17))
#define  ABL_ABL_CTRL_abl_href_sel(data)                                         (0x00010000&((data)<<16))
#define  ABL_ABL_CTRL_abl_target_value(data)                                     (0x00000F00&((data)<<8))
#define  ABL_ABL_CTRL_dummy3(data)                                                (0x000000C0&((data)<<6))
#define  ABL_ABL_CTRL_get_abl_en(data)                                           ((0x80000000&(data))>>31)
#define  ABL_ABL_CTRL_get_abl_red_en(data)                                       ((0x40000000&(data))>>30)
#define  ABL_ABL_CTRL_get_abl_grn_en(data)                                       ((0x20000000&(data))>>29)
#define  ABL_ABL_CTRL_get_abl_blu_en(data)                                       ((0x10000000&(data))>>28)
#define  ABL_ABL_CTRL_get_dummy1(data)                                            ((0x08000000&(data))>>27)
#define  ABL_ABL_CTRL_get_abl_software_mode(data)                                ((0x04000000&(data))>>26)
#define  ABL_ABL_CTRL_get_abl_min_measure(data)                                  ((0x02000000&(data))>>25)
#define  ABL_ABL_CTRL_get_abl_ypbpr_en(data)                                     ((0x01000000&(data))>>24)
#define  ABL_ABL_CTRL_get_abl_online_mode(data)                                  ((0x00800000&(data))>>23)
#define  ABL_ABL_CTRL_get_dummy2(data)                                            ((0x00400000&(data))>>22)
#define  ABL_ABL_CTRL_get_abl_max_frame(data)                                    ((0x00300000&(data))>>20)
#define  ABL_ABL_CTRL_get_abl_r_dir_inv(data)                                    ((0x00080000&(data))>>19)
#define  ABL_ABL_CTRL_get_abl_g_dir_inv(data)                                    ((0x00040000&(data))>>18)
#define  ABL_ABL_CTRL_get_abl_b_dir_inv(data)                                    ((0x00020000&(data))>>17)
#define  ABL_ABL_CTRL_get_abl_href_sel(data)                                     ((0x00010000&(data))>>16)
#define  ABL_ABL_CTRL_get_abl_target_value(data)                                 ((0x00000F00&(data))>>8)
#define  ABL_ABL_CTRL_get_dummy3(data)                                            ((0x000000C0&(data))>>6)

#define  ABL_ABL_WINDOW                                                          0x18020204
#define  ABL_ABL_WINDOW_reg_addr                                                 "0xB8020204"
#define  ABL_ABL_WINDOW_reg                                                      0xB8020204
#define  ABL_ABL_WINDOW_inst_addr                                                "0x0001"
#define  set_ABL_ABL_WINDOW_reg(data)                                            (*((volatile unsigned int*)ABL_ABL_WINDOW_reg)=data)
#define  get_ABL_ABL_WINDOW_reg                                                  (*((volatile unsigned int*)ABL_ABL_WINDOW_reg))
#define  ABL_ABL_WINDOW_abl_start_pos_mul_shift                                  (30)
#define  ABL_ABL_WINDOW_abl_vend_shift                                           (20)
#define  ABL_ABL_WINDOW_abl_wait_line_shift                                      (17)
#define  ABL_ABL_WINDOW_abl_vsta_shift                                           (12)
#define  ABL_ABL_WINDOW_abl_line_shift                                           (10)
#define  ABL_ABL_WINDOW_abl_h_width_shift                                        (8)
#define  ABL_ABL_WINDOW_abl_start_pos_shift                                      (0)
#define  ABL_ABL_WINDOW_abl_start_pos_mul_mask                                   (0xC0000000)
#define  ABL_ABL_WINDOW_abl_vend_mask                                            (0x3FF00000)
#define  ABL_ABL_WINDOW_abl_wait_line_mask                                       (0x000E0000)
#define  ABL_ABL_WINDOW_abl_vsta_mask                                            (0x0001F000)
#define  ABL_ABL_WINDOW_abl_line_mask                                            (0x00000C00)
#define  ABL_ABL_WINDOW_abl_h_width_mask                                         (0x00000300)
#define  ABL_ABL_WINDOW_abl_start_pos_mask                                       (0x000000FF)
#define  ABL_ABL_WINDOW_abl_start_pos_mul(data)                                  (0xC0000000&((data)<<30))
#define  ABL_ABL_WINDOW_abl_vend(data)                                           (0x3FF00000&((data)<<20))
#define  ABL_ABL_WINDOW_abl_wait_line(data)                                      (0x000E0000&((data)<<17))
#define  ABL_ABL_WINDOW_abl_vsta(data)                                           (0x0001F000&((data)<<12))
#define  ABL_ABL_WINDOW_abl_line(data)                                           (0x00000C00&((data)<<10))
#define  ABL_ABL_WINDOW_abl_h_width(data)                                        (0x00000300&((data)<<8))
#define  ABL_ABL_WINDOW_abl_start_pos(data)                                      (0x000000FF&(data))
#define  ABL_ABL_WINDOW_get_abl_start_pos_mul(data)                              ((0xC0000000&(data))>>30)
#define  ABL_ABL_WINDOW_get_abl_vend(data)                                       ((0x3FF00000&(data))>>20)
#define  ABL_ABL_WINDOW_get_abl_wait_line(data)                                  ((0x000E0000&(data))>>17)
#define  ABL_ABL_WINDOW_get_abl_vsta(data)                                       ((0x0001F000&(data))>>12)
#define  ABL_ABL_WINDOW_get_abl_line(data)                                       ((0x00000C00&(data))>>10)
#define  ABL_ABL_WINDOW_get_abl_h_width(data)                                    ((0x00000300&(data))>>8)
#define  ABL_ABL_WINDOW_get_abl_start_pos(data)                                  (0x000000FF&(data))

#define  ABL_ABL_STATUS                                                          0x18020208
#define  ABL_ABL_STATUS_reg_addr                                                 "0xB8020208"
#define  ABL_ABL_STATUS_reg                                                      0xB8020208
#define  ABL_ABL_STATUS_inst_addr                                                "0x0002"
#define  set_ABL_ABL_STATUS_reg(data)                                            (*((volatile unsigned int*)ABL_ABL_STATUS_reg)=data)
#define  get_ABL_ABL_STATUS_reg                                                  (*((volatile unsigned int*)ABL_ABL_STATUS_reg))
#define  ABL_ABL_STATUS_abl_measure_error_flag_rst_shift                         (31)
#define  ABL_ABL_STATUS_abl_measure_error_flag_shift                             (30)
#define  ABL_ABL_STATUS_abl_red_equal_shift                                      (2)
#define  ABL_ABL_STATUS_abl_grn_equal_shift                                      (1)
#define  ABL_ABL_STATUS_abl_blu_equal_shift                                      (0)
#define  ABL_ABL_STATUS_abl_measure_error_flag_rst_mask                          (0x80000000)
#define  ABL_ABL_STATUS_abl_measure_error_flag_mask                              (0x40000000)
#define  ABL_ABL_STATUS_abl_red_equal_mask                                       (0x00000004)
#define  ABL_ABL_STATUS_abl_grn_equal_mask                                       (0x00000002)
#define  ABL_ABL_STATUS_abl_blu_equal_mask                                       (0x00000001)
#define  ABL_ABL_STATUS_abl_measure_error_flag_rst(data)                         (0x80000000&((data)<<31))
#define  ABL_ABL_STATUS_abl_measure_error_flag(data)                             (0x40000000&((data)<<30))
#define  ABL_ABL_STATUS_abl_red_equal(data)                                      (0x00000004&((data)<<2))
#define  ABL_ABL_STATUS_abl_grn_equal(data)                                      (0x00000002&((data)<<1))
#define  ABL_ABL_STATUS_abl_blu_equal(data)                                      (0x00000001&(data))
#define  ABL_ABL_STATUS_get_abl_measure_error_flag_rst(data)                     ((0x80000000&(data))>>31)
#define  ABL_ABL_STATUS_get_abl_measure_error_flag(data)                         ((0x40000000&(data))>>30)
#define  ABL_ABL_STATUS_get_abl_red_equal(data)                                  ((0x00000004&(data))>>2)
#define  ABL_ABL_STATUS_get_abl_grn_equal(data)                                  ((0x00000002&(data))>>1)
#define  ABL_ABL_STATUS_get_abl_blu_equal(data)                                  (0x00000001&(data))

#define  ABL_Reserved                                                            0x1802020C
#define  ABL_Reserved_reg_addr                                                   "0xB802020C"
#define  ABL_Reserved_reg                                                        0xB802020C
#define  ABL_Reserved_inst_addr                                                  "0x0003"
#define  set_ABL_Reserved_reg(data)                                              (*((volatile unsigned int*)ABL_Reserved_reg)=data)
#define  get_ABL_Reserved_reg                                                    (*((volatile unsigned int*)ABL_Reserved_reg))
#define  ABL_Reserved_dummy_shift                                                (0)
#define  ABL_Reserved_dummy_mask                                                 (0xFFFFFFFF)
#define  ABL_Reserved_dummy(data)                                                (0xFFFFFFFF&(data))
#define  ABL_Reserved_get_dummy(data)                                            (0xFFFFFFFF&(data))

#define  ABL_ABL_RSLT0                                                           0x18020210
#define  ABL_ABL_RSLT0_reg_addr                                                  "0xB8020210"
#define  ABL_ABL_RSLT0_reg                                                       0xB8020210
#define  ABL_ABL_RSLT0_inst_addr                                                 "0x0004"
#define  set_ABL_ABL_RSLT0_reg(data)                                             (*((volatile unsigned int*)ABL_ABL_RSLT0_reg)=data)
#define  get_ABL_ABL_RSLT0_reg                                                   (*((volatile unsigned int*)ABL_ABL_RSLT0_reg))
#define  ABL_ABL_RSLT0_abl_r_l_avg_min_shift                                     (16)
#define  ABL_ABL_RSLT0_abl_g_l_avg_min_shift                                     (0)
#define  ABL_ABL_RSLT0_abl_r_l_avg_min_mask                                      (0x03FF0000)
#define  ABL_ABL_RSLT0_abl_g_l_avg_min_mask                                      (0x000003FF)
#define  ABL_ABL_RSLT0_abl_r_l_avg_min(data)                                     (0x03FF0000&((data)<<16))
#define  ABL_ABL_RSLT0_abl_g_l_avg_min(data)                                     (0x000003FF&(data))
#define  ABL_ABL_RSLT0_get_abl_r_l_avg_min(data)                                 ((0x03FF0000&(data))>>16)
#define  ABL_ABL_RSLT0_get_abl_g_l_avg_min(data)                                 (0x000003FF&(data))

#define  ABL_ABL_RSLT1                                                           0x18020214
#define  ABL_ABL_RSLT1_reg_addr                                                  "0xB8020214"
#define  ABL_ABL_RSLT1_reg                                                       0xB8020214
#define  ABL_ABL_RSLT1_inst_addr                                                 "0x0005"
#define  set_ABL_ABL_RSLT1_reg(data)                                             (*((volatile unsigned int*)ABL_ABL_RSLT1_reg)=data)
#define  get_ABL_ABL_RSLT1_reg                                                   (*((volatile unsigned int*)ABL_ABL_RSLT1_reg))
#define  ABL_ABL_RSLT1_abl_b_l_avg_min_shift                                     (0)
#define  ABL_ABL_RSLT1_abl_b_l_avg_min_mask                                      (0x000003FF)
#define  ABL_ABL_RSLT1_abl_b_l_avg_min(data)                                     (0x000003FF&(data))
#define  ABL_ABL_RSLT1_get_abl_b_l_avg_min(data)                                 (0x000003FF&(data))

#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0                                        0x18020218
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg_addr                               "0xB8020218"
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg                                    0xB8020218
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_inst_addr                              "0x0006"
#define  set_ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg(data)                          (*((volatile unsigned int*)ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg)=data)
#define  get_ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg                                (*((volatile unsigned int*)ABL_AUTO_OFST_RD0_ABL_NOISE_val0_reg))
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_red_diff2_shift                    (16)
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_grn_diff2_shift                    (0)
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_red_diff2_mask                     (0x03FF0000)
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_grn_diff2_mask                     (0x000003FF)
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_red_diff2(data)                    (0x03FF0000&((data)<<16))
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_abl_grn_diff2(data)                    (0x000003FF&(data))
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_get_abl_red_diff2(data)                ((0x03FF0000&(data))>>16)
#define  ABL_AUTO_OFST_RD0_ABL_NOISE_val0_get_abl_grn_diff2(data)                (0x000003FF&(data))

#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1                                        0x1802021C
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg_addr                               "0xB802021C"
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg                                    0xB802021C
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_inst_addr                              "0x0007"
#define  set_ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg(data)                          (*((volatile unsigned int*)ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg)=data)
#define  get_ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg                                (*((volatile unsigned int*)ABL_AUTO_OFST_RD1_ABL_NOISE_val1_reg))
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_abl_blu_diff2_shift                    (0)
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_abl_blu_diff2_mask                     (0x000003FF)
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_abl_blu_diff2(data)                    (0x000003FF&(data))
#define  ABL_AUTO_OFST_RD1_ABL_NOISE_val1_get_abl_blu_diff2(data)                (0x000003FF&(data))

#define  ABL_ABL_MGN_RG                                                          0x18020220
#define  ABL_ABL_MGN_RG_reg_addr                                                 "0xB8020220"
#define  ABL_ABL_MGN_RG_reg                                                      0xB8020220
#define  ABL_ABL_MGN_RG_inst_addr                                                "0x0008"
#define  set_ABL_ABL_MGN_RG_reg(data)                                            (*((volatile unsigned int*)ABL_ABL_MGN_RG_reg)=data)
#define  get_ABL_ABL_MGN_RG_reg                                                  (*((volatile unsigned int*)ABL_ABL_MGN_RG_reg))
#define  ABL_ABL_MGN_RG_abl_eq_mgn_red_shift                                     (26)
#define  ABL_ABL_MGN_RG_abl_l_mgn_red_shift                                      (21)
#define  ABL_ABL_MGN_RG_abl_lock_mgn_red_shift                                   (16)
#define  ABL_ABL_MGN_RG_abl_eq_mgn_grn_shift                                     (10)
#define  ABL_ABL_MGN_RG_abl_l_mgn_grn_shift                                      (5)
#define  ABL_ABL_MGN_RG_abl_lock_mgn_grn_shift                                   (0)
#define  ABL_ABL_MGN_RG_abl_eq_mgn_red_mask                                      (0x7C000000)
#define  ABL_ABL_MGN_RG_abl_l_mgn_red_mask                                       (0x03E00000)
#define  ABL_ABL_MGN_RG_abl_lock_mgn_red_mask                                    (0x001F0000)
#define  ABL_ABL_MGN_RG_abl_eq_mgn_grn_mask                                      (0x00007C00)
#define  ABL_ABL_MGN_RG_abl_l_mgn_grn_mask                                       (0x000003E0)
#define  ABL_ABL_MGN_RG_abl_lock_mgn_grn_mask                                    (0x0000001F)
#define  ABL_ABL_MGN_RG_abl_eq_mgn_red(data)                                     (0x7C000000&((data)<<26))
#define  ABL_ABL_MGN_RG_abl_l_mgn_red(data)                                      (0x03E00000&((data)<<21))
#define  ABL_ABL_MGN_RG_abl_lock_mgn_red(data)                                   (0x001F0000&((data)<<16))
#define  ABL_ABL_MGN_RG_abl_eq_mgn_grn(data)                                     (0x00007C00&((data)<<10))
#define  ABL_ABL_MGN_RG_abl_l_mgn_grn(data)                                      (0x000003E0&((data)<<5))
#define  ABL_ABL_MGN_RG_abl_lock_mgn_grn(data)                                   (0x0000001F&(data))
#define  ABL_ABL_MGN_RG_get_abl_eq_mgn_red(data)                                 ((0x7C000000&(data))>>26)
#define  ABL_ABL_MGN_RG_get_abl_l_mgn_red(data)                                  ((0x03E00000&(data))>>21)
#define  ABL_ABL_MGN_RG_get_abl_lock_mgn_red(data)                               ((0x001F0000&(data))>>16)
#define  ABL_ABL_MGN_RG_get_abl_eq_mgn_grn(data)                                 ((0x00007C00&(data))>>10)
#define  ABL_ABL_MGN_RG_get_abl_l_mgn_grn(data)                                  ((0x000003E0&(data))>>5)
#define  ABL_ABL_MGN_RG_get_abl_lock_mgn_grn(data)                               (0x0000001F&(data))

#define  ABL_ABL_MGN_B                                                           0x18020224
#define  ABL_ABL_MGN_B_reg_addr                                                  "0xB8020224"
#define  ABL_ABL_MGN_B_reg                                                       0xB8020224
#define  ABL_ABL_MGN_B_inst_addr                                                 "0x0009"
#define  set_ABL_ABL_MGN_B_reg(data)                                             (*((volatile unsigned int*)ABL_ABL_MGN_B_reg)=data)
#define  get_ABL_ABL_MGN_B_reg                                                   (*((volatile unsigned int*)ABL_ABL_MGN_B_reg))
#define  ABL_ABL_MGN_B_abl_eq_mgn_blu_shift                                      (10)
#define  ABL_ABL_MGN_B_abl_l_mgn_blu_shift                                       (5)
#define  ABL_ABL_MGN_B_abl_lock_mgn_blu_shift                                    (0)
#define  ABL_ABL_MGN_B_abl_eq_mgn_blu_mask                                       (0x00007C00)
#define  ABL_ABL_MGN_B_abl_l_mgn_blu_mask                                        (0x000003E0)
#define  ABL_ABL_MGN_B_abl_lock_mgn_blu_mask                                     (0x0000001F)
#define  ABL_ABL_MGN_B_abl_eq_mgn_blu(data)                                      (0x00007C00&((data)<<10))
#define  ABL_ABL_MGN_B_abl_l_mgn_blu(data)                                       (0x000003E0&((data)<<5))
#define  ABL_ABL_MGN_B_abl_lock_mgn_blu(data)                                    (0x0000001F&(data))
#define  ABL_ABL_MGN_B_get_abl_eq_mgn_blu(data)                                  ((0x00007C00&(data))>>10)
#define  ABL_ABL_MGN_B_get_abl_l_mgn_blu(data)                                   ((0x000003E0&(data))>>5)
#define  ABL_ABL_MGN_B_get_abl_lock_mgn_blu(data)                                (0x0000001F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ABL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_en:1;
        RBus_UInt32  abl_red_en:1;
        RBus_UInt32  abl_grn_en:1;
        RBus_UInt32  abl_blu_en:1;
        RBus_UInt32  dummy18020200_27:1;
        RBus_UInt32  abl_software_mode:1;
        RBus_UInt32  abl_min_measure:1;
        RBus_UInt32  abl_ypbpr_en:1;
        RBus_UInt32  abl_online_mode:1;
        RBus_UInt32  dummy18020200_22:1;
        RBus_UInt32  abl_max_frame:2;
        RBus_UInt32  abl_r_dir_inv:1;
        RBus_UInt32  abl_g_dir_inv:1;
        RBus_UInt32  abl_b_dir_inv:1;
        RBus_UInt32  abl_href_sel:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  abl_target_value:4;
        RBus_UInt32  dummy18020200_7_6:2;
        RBus_UInt32  res2:6;
    };
}abl_abl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_start_pos_mul:2;
        RBus_UInt32  abl_vend:10;
        RBus_UInt32  abl_wait_line:3;
        RBus_UInt32  abl_vsta:5;
        RBus_UInt32  abl_line:2;
        RBus_UInt32  abl_h_width:2;
        RBus_UInt32  abl_start_pos:8;
    };
}abl_abl_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_measure_error_flag_rst:1;
        RBus_UInt32  abl_measure_error_flag:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  abl_red_equal:1;
        RBus_UInt32  abl_grn_equal:1;
        RBus_UInt32  abl_blu_equal:1;
    };
}abl_abl_status_RBUS;

#if 0
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802020c_31_0:32;
    };
}abl_reserved_RBUS;
#else
typedef union
{
	RBus_UInt32 regValue;
    struct{
        RBus_UInt32  self_awb_code_diff_b:10;
        RBus_UInt32  self_awb_code_diff_r:10;
        RBus_UInt32  self_awb_code_diff_g:10;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  agc_peak_en:1;
        //RBus_UInt32  dummy1802020c_31_0:32;
    };
}abl_reserved_RBUS;
#endif

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_r_l_avg_min:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_g_l_avg_min:10;
    };
}abl_abl_rslt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  abl_b_l_avg_min:10;
    };
}abl_abl_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_red_diff2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  abl_grn_diff2:10;
    };
}abl_auto_ofst_rd0_abl_noise_val0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  abl_blu_diff2:10;
    };
}abl_auto_ofst_rd1_abl_noise_val1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  abl_eq_mgn_red:5;
        RBus_UInt32  abl_l_mgn_red:5;
        RBus_UInt32  abl_lock_mgn_red:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  abl_eq_mgn_grn:5;
        RBus_UInt32  abl_l_mgn_grn:5;
        RBus_UInt32  abl_lock_mgn_grn:5;
    };
}abl_abl_mgn_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  abl_eq_mgn_blu:5;
        RBus_UInt32  abl_l_mgn_blu:5;
        RBus_UInt32  abl_lock_mgn_blu:5;
    };
}abl_abl_mgn_b_RBUS;

#else //apply LITTLE_ENDIAN

//======ABL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dummy18020200_7_6:2;
        RBus_UInt32  abl_target_value:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  abl_href_sel:1;
        RBus_UInt32  abl_b_dir_inv:1;
        RBus_UInt32  abl_g_dir_inv:1;
        RBus_UInt32  abl_r_dir_inv:1;
        RBus_UInt32  abl_max_frame:2;
        RBus_UInt32  dummy18020200_22_22:1;
        RBus_UInt32  abl_online_mode:1;
        RBus_UInt32  abl_ypbpr_en:1;
        RBus_UInt32  abl_min_measure:1;
        RBus_UInt32  abl_software_mode:1;
        RBus_UInt32  dummy18020200_27_27:1;
        RBus_UInt32  abl_blu_en:1;
        RBus_UInt32  abl_grn_en:1;
        RBus_UInt32  abl_red_en:1;
        RBus_UInt32  abl_en:1;
    };
}abl_abl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_start_pos:8;
        RBus_UInt32  abl_h_width:2;
        RBus_UInt32  abl_line:2;
        RBus_UInt32  abl_vsta:5;
        RBus_UInt32  abl_wait_line:3;
        RBus_UInt32  abl_vend:10;
        RBus_UInt32  abl_start_pos_mul:2;
    };
}abl_abl_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_blu_equal:1;
        RBus_UInt32  abl_grn_equal:1;
        RBus_UInt32  abl_red_equal:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  abl_measure_error_flag:1;
        RBus_UInt32  abl_measure_error_flag_rst:1;
    };
}abl_abl_status_RBUS;

#if 0
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802020c_31_0:32;
    };
}abl_reserved_RBUS;
#else
typedef union
{
    RBus_UInt32 regValue;
    struct{
        //RBus_UInt32  dummy1802020c_31_0:32;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  self_awb_code_diff_g:10;
        RBus_UInt32  self_awb_code_diff_r:10;
        RBus_UInt32  self_awb_code_diff_b:10;
    };
}abl_reserved_RBUS;
#endif

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_g_l_avg_min:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_r_l_avg_min:10;
        RBus_UInt32  res2:6;
    };
}abl_abl_rslt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_b_l_avg_min:10;
        RBus_UInt32  res1:22;
    };
}abl_abl_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_grn_diff2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  abl_red_diff2:10;
        RBus_UInt32  res2:6;
    };
}abl_auto_ofst_rd0_abl_noise_val0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_blu_diff2:10;
        RBus_UInt32  res1:22;
    };
}abl_auto_ofst_rd1_abl_noise_val1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_lock_mgn_grn:5;
        RBus_UInt32  abl_l_mgn_grn:5;
        RBus_UInt32  abl_eq_mgn_grn:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  abl_lock_mgn_red:5;
        RBus_UInt32  abl_l_mgn_red:5;
        RBus_UInt32  abl_eq_mgn_red:5;
        RBus_UInt32  res2:1;
    };
}abl_abl_mgn_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abl_lock_mgn_blu:5;
        RBus_UInt32  abl_l_mgn_blu:5;
        RBus_UInt32  abl_eq_mgn_blu:5;
        RBus_UInt32  res1:17;
    };
}abl_abl_mgn_b_RBUS;




#endif 


#endif 
