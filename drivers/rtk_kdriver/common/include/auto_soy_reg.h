/**
* @file rbusAuto_soyReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_AUTO_SOY_REG_H_
#define _RBUS_AUTO_SOY_REG_H_

#include "rbus_types.h"



//  AUTO_SOY Register Address
#define  AUTO_SOY_SOYCH0_A0                                                      0x18020300
#define  AUTO_SOY_SOYCH0_A0_reg_addr                                             "0xB8020300"
#define  AUTO_SOY_SOYCH0_A0_reg                                                  0xB8020300
#define  AUTO_SOY_SOYCH0_A0_inst_addr                                            "0x0000"
#define  set_AUTO_SOY_SOYCH0_A0_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A0_reg)=data)
#define  get_AUTO_SOY_SOYCH0_A0_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A0_reg))
#define  AUTO_SOY_SOYCH0_A0_reg_auto_ini_dc_shift                                (24)
#define  AUTO_SOY_SOYCH0_A0_reg_deb_valid_shift                                  (16)
#define  AUTO_SOY_SOYCH0_A0_dummy_15_14_shift                                    (14)
#define  AUTO_SOY_SOYCH0_A0_reg_deb_update_shift                                 (8)
#define  AUTO_SOY_SOYCH0_A0_dummy_7_shift                                        (7)
#define  AUTO_SOY_SOYCH0_A0_reg_diff_sel_dclevel_shift                           (6)
#define  AUTO_SOY_SOYCH0_A0_reg_update_mode_shift                                (4)
#define  AUTO_SOY_SOYCH0_A0_reg_ma_mode_shift                                    (1)
#define  AUTO_SOY_SOYCH0_A0_reg_auto_mode_shift                                  (0)
#define  AUTO_SOY_SOYCH0_A0_reg_auto_ini_dc_mask                                 (0x3F000000)
#define  AUTO_SOY_SOYCH0_A0_reg_deb_valid_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_A0_dummy_15_14_mask                                     (0x0000C000)
#define  AUTO_SOY_SOYCH0_A0_reg_deb_update_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_A0_dummy_7_mask                                         (0x00000080)
#define  AUTO_SOY_SOYCH0_A0_reg_diff_sel_dclevel_mask                            (0x00000040)
#define  AUTO_SOY_SOYCH0_A0_reg_update_mode_mask                                 (0x00000030)
#define  AUTO_SOY_SOYCH0_A0_reg_ma_mode_mask                                     (0x0000000E)
#define  AUTO_SOY_SOYCH0_A0_reg_auto_mode_mask                                   (0x00000001)
#define  AUTO_SOY_SOYCH0_A0_reg_auto_ini_dc(data)                                (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_A0_reg_deb_valid(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_A0_dummy_15_14(data)                                    (0x0000C000&((data)<<14))
#define  AUTO_SOY_SOYCH0_A0_reg_deb_update(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_A0_dummy_7(data)                                        (0x00000080&((data)<<7))
#define  AUTO_SOY_SOYCH0_A0_reg_diff_sel_dclevel(data)                           (0x00000040&((data)<<6))
#define  AUTO_SOY_SOYCH0_A0_reg_update_mode(data)                                (0x00000030&((data)<<4))
#define  AUTO_SOY_SOYCH0_A0_reg_ma_mode(data)                                    (0x0000000E&((data)<<1))
#define  AUTO_SOY_SOYCH0_A0_reg_auto_mode(data)                                  (0x00000001&(data))
#define  AUTO_SOY_SOYCH0_A0_get_reg_auto_ini_dc(data)                            ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_A0_get_reg_deb_valid(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_A0_get_dummy_15_14(data)                                ((0x0000C000&(data))>>14)
#define  AUTO_SOY_SOYCH0_A0_get_reg_deb_update(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_A0_get_dummy_7(data)                                    ((0x00000080&(data))>>7)
#define  AUTO_SOY_SOYCH0_A0_get_reg_diff_sel_dclevel(data)                       ((0x00000040&(data))>>6)
#define  AUTO_SOY_SOYCH0_A0_get_reg_update_mode(data)                            ((0x00000030&(data))>>4)
#define  AUTO_SOY_SOYCH0_A0_get_reg_ma_mode(data)                                ((0x0000000E&(data))>>1)
#define  AUTO_SOY_SOYCH0_A0_get_reg_auto_mode(data)                              (0x00000001&(data))

#define  AUTO_SOY_SOYCH0_A1                                                      0x18020304
#define  AUTO_SOY_SOYCH0_A1_reg_addr                                             "0xB8020304"
#define  AUTO_SOY_SOYCH0_A1_reg                                                  0xB8020304
#define  AUTO_SOY_SOYCH0_A1_inst_addr                                            "0x0001"
#define  set_AUTO_SOY_SOYCH0_A1_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A1_reg)=data)
#define  get_AUTO_SOY_SOYCH0_A1_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A1_reg))
#define  AUTO_SOY_SOYCH0_A1_reg_max_hb_shift                                     (24)
#define  AUTO_SOY_SOYCH0_A1_reg_max_lb_shift                                     (16)
#define  AUTO_SOY_SOYCH0_A1_reg_min_hb_shift                                     (8)
#define  AUTO_SOY_SOYCH0_A1_reg_min_lb_shift                                     (0)
#define  AUTO_SOY_SOYCH0_A1_reg_max_hb_mask                                      (0x3F000000)
#define  AUTO_SOY_SOYCH0_A1_reg_max_lb_mask                                      (0x003F0000)
#define  AUTO_SOY_SOYCH0_A1_reg_min_hb_mask                                      (0x00003F00)
#define  AUTO_SOY_SOYCH0_A1_reg_min_lb_mask                                      (0x0000003F)
#define  AUTO_SOY_SOYCH0_A1_reg_max_hb(data)                                     (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_A1_reg_max_lb(data)                                     (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_A1_reg_min_hb(data)                                     (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_A1_reg_min_lb(data)                                     (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_A1_get_reg_max_hb(data)                                 ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_A1_get_reg_max_lb(data)                                 ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_A1_get_reg_min_hb(data)                                 ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_A1_get_reg_min_lb(data)                                 (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_A2                                                      0x18020308
#define  AUTO_SOY_SOYCH0_A2_reg_addr                                             "0xB8020308"
#define  AUTO_SOY_SOYCH0_A2_reg                                                  0xB8020308
#define  AUTO_SOY_SOYCH0_A2_inst_addr                                            "0x0002"
#define  set_AUTO_SOY_SOYCH0_A2_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A2_reg)=data)
#define  get_AUTO_SOY_SOYCH0_A2_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A2_reg))
#define  AUTO_SOY_SOYCH0_A2_reg_max_window_shift                                 (16)
#define  AUTO_SOY_SOYCH0_A2_reg_min_window_shift                                 (8)
#define  AUTO_SOY_SOYCH0_A2_reg_min_diff_shift                                   (0)
#define  AUTO_SOY_SOYCH0_A2_reg_max_window_mask                                  (0x001F0000)
#define  AUTO_SOY_SOYCH0_A2_reg_min_window_mask                                  (0x00001F00)
#define  AUTO_SOY_SOYCH0_A2_reg_min_diff_mask                                    (0x0000003F)
#define  AUTO_SOY_SOYCH0_A2_reg_max_window(data)                                 (0x001F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_A2_reg_min_window(data)                                 (0x00001F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_A2_reg_min_diff(data)                                   (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_A2_get_reg_max_window(data)                             ((0x001F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_A2_get_reg_min_window(data)                             ((0x00001F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_A2_get_reg_min_diff(data)                               (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_A3                                                      0x1802030C
#define  AUTO_SOY_SOYCH0_A3_reg_addr                                             "0xB802030C"
#define  AUTO_SOY_SOYCH0_A3_reg                                                  0xB802030C
#define  AUTO_SOY_SOYCH0_A3_inst_addr                                            "0x0003"
#define  set_AUTO_SOY_SOYCH0_A3_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A3_reg)=data)
#define  get_AUTO_SOY_SOYCH0_A3_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A3_reg))
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_offset_shift                              (24)
#define  AUTO_SOY_SOYCH0_A3_reg_manu_comp_shift                                  (16)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_level_avg_shift                               (4)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_mode_shift                                (0)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_offset_mask                               (0x3F000000)
#define  AUTO_SOY_SOYCH0_A3_reg_manu_comp_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_level_avg_mask                                (0x00000030)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_mode_mask                                 (0x0000000F)
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_offset(data)                              (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_A3_reg_manu_comp(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_A3_reg_dc_level_avg(data)                               (0x00000030&((data)<<4))
#define  AUTO_SOY_SOYCH0_A3_reg_dc_out_mode(data)                                (0x0000000F&(data))
#define  AUTO_SOY_SOYCH0_A3_get_reg_dc_out_offset(data)                          ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_A3_get_reg_manu_comp(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_A3_get_reg_dc_level_avg(data)                           ((0x00000030&(data))>>4)
#define  AUTO_SOY_SOYCH0_A3_get_reg_dc_out_mode(data)                            (0x0000000F&(data))

#define  AUTO_SOY_SOYCH0_A4                                                      0x18020310
#define  AUTO_SOY_SOYCH0_A4_reg_addr                                             "0xB8020310"
#define  AUTO_SOY_SOYCH0_A4_reg                                                  0xB8020310
#define  AUTO_SOY_SOYCH0_A4_inst_addr                                            "0x0004"
#define  set_AUTO_SOY_SOYCH0_A4_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A4_reg)=data)
#define  get_AUTO_SOY_SOYCH0_A4_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_A4_reg))
#define  AUTO_SOY_SOYCH0_A4_cmp_level_r_shift                                    (24)
#define  AUTO_SOY_SOYCH0_A4_dc_level_r_shift                                     (16)
#define  AUTO_SOY_SOYCH0_A4_max_hb_flag_r_shift                                  (15)
#define  AUTO_SOY_SOYCH0_A4_max_lb_flag_r_shift                                  (14)
#define  AUTO_SOY_SOYCH0_A4_max_r_shift                                          (8)
#define  AUTO_SOY_SOYCH0_A4_min_hb_flag_r_shift                                  (7)
#define  AUTO_SOY_SOYCH0_A4_min_lb_flag_r_shift                                  (6)
#define  AUTO_SOY_SOYCH0_A4_min_r_shift                                          (0)
#define  AUTO_SOY_SOYCH0_A4_cmp_level_r_mask                                     (0x3F000000)
#define  AUTO_SOY_SOYCH0_A4_dc_level_r_mask                                      (0x003F0000)
#define  AUTO_SOY_SOYCH0_A4_max_hb_flag_r_mask                                   (0x00008000)
#define  AUTO_SOY_SOYCH0_A4_max_lb_flag_r_mask                                   (0x00004000)
#define  AUTO_SOY_SOYCH0_A4_max_r_mask                                           (0x00003F00)
#define  AUTO_SOY_SOYCH0_A4_min_hb_flag_r_mask                                   (0x00000080)
#define  AUTO_SOY_SOYCH0_A4_min_lb_flag_r_mask                                   (0x00000040)
#define  AUTO_SOY_SOYCH0_A4_min_r_mask                                           (0x0000003F)
#define  AUTO_SOY_SOYCH0_A4_cmp_level_r(data)                                    (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_A4_dc_level_r(data)                                     (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_A4_max_hb_flag_r(data)                                  (0x00008000&((data)<<15))
#define  AUTO_SOY_SOYCH0_A4_max_lb_flag_r(data)                                  (0x00004000&((data)<<14))
#define  AUTO_SOY_SOYCH0_A4_max_r(data)                                          (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_A4_min_hb_flag_r(data)                                  (0x00000080&((data)<<7))
#define  AUTO_SOY_SOYCH0_A4_min_lb_flag_r(data)                                  (0x00000040&((data)<<6))
#define  AUTO_SOY_SOYCH0_A4_min_r(data)                                          (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_A4_get_cmp_level_r(data)                                ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_A4_get_dc_level_r(data)                                 ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_A4_get_max_hb_flag_r(data)                              ((0x00008000&(data))>>15)
#define  AUTO_SOY_SOYCH0_A4_get_max_lb_flag_r(data)                              ((0x00004000&(data))>>14)
#define  AUTO_SOY_SOYCH0_A4_get_max_r(data)                                      ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_A4_get_min_hb_flag_r(data)                              ((0x00000080&(data))>>7)
#define  AUTO_SOY_SOYCH0_A4_get_min_lb_flag_r(data)                              ((0x00000040&(data))>>6)
#define  AUTO_SOY_SOYCH0_A4_get_min_r(data)                                      (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_B0                                                      0x18020314
#define  AUTO_SOY_SOYCH0_B0_reg_addr                                             "0xB8020314"
#define  AUTO_SOY_SOYCH0_B0_reg                                                  0xB8020314
#define  AUTO_SOY_SOYCH0_B0_inst_addr                                            "0x0005"
#define  set_AUTO_SOY_SOYCH0_B0_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_B0_reg)=data)
#define  get_AUTO_SOY_SOYCH0_B0_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_B0_reg))
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_addr_shift                                (24)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_data_shift                                (16)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_1t_shift                                  (9)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_cnt_base_shift                     (4)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_bypass_shift                       (3)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_val_rst_shift                      (2)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_auto_calibrate_en_shift                      (0)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_addr_mask                                 (0x3F000000)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_data_mask                                 (0x003F0000)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_1t_mask                                   (0x00000200)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_cnt_base_mask                      (0x000001F0)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_bypass_mask                        (0x00000008)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_val_rst_mask                       (0x00000004)
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_auto_calibrate_en_mask                       (0x00000001)
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_addr(data)                                (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_data(data)                                (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_B0_reg_man_wr_1t(data)                                  (0x00000200&((data)<<9))
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_cnt_base(data)                     (0x000001F0&((data)<<4))
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_bypass(data)                       (0x00000008&((data)<<3))
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_calibrate_val_rst(data)                      (0x00000004&((data)<<2))
#define  AUTO_SOY_SOYCH0_B0_reg_ch0_auto_calibrate_en(data)                      (0x00000001&(data))
#define  AUTO_SOY_SOYCH0_B0_get_reg_man_wr_addr(data)                            ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_B0_get_reg_man_wr_data(data)                            ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_B0_get_reg_man_wr_1t(data)                              ((0x00000200&(data))>>9)
#define  AUTO_SOY_SOYCH0_B0_get_reg_ch0_calibrate_cnt_base(data)                 ((0x000001F0&(data))>>4)
#define  AUTO_SOY_SOYCH0_B0_get_reg_ch0_calibrate_bypass(data)                   ((0x00000008&(data))>>3)
#define  AUTO_SOY_SOYCH0_B0_get_reg_ch0_calibrate_val_rst(data)                  ((0x00000004&(data))>>2)
#define  AUTO_SOY_SOYCH0_B0_get_reg_ch0_auto_calibrate_en(data)                  (0x00000001&(data))

#define  AUTO_SOY_SOYCH0_B1                                                      0x18020318
#define  AUTO_SOY_SOYCH0_B1_reg_addr                                             "0xB8020318"
#define  AUTO_SOY_SOYCH0_B1_reg                                                  0xB8020318
#define  AUTO_SOY_SOYCH0_B1_inst_addr                                            "0x0006"
#define  set_AUTO_SOY_SOYCH0_B1_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_B1_reg)=data)
#define  get_AUTO_SOY_SOYCH0_B1_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_B1_reg))
#define  AUTO_SOY_SOYCH0_B1_reg_soy_tst_sel_shift                                (16)
#define  AUTO_SOY_SOYCH0_B1_seek_min_st_r_shift                                  (14)
#define  AUTO_SOY_SOYCH0_B1_seek_max_st_r_shift                                  (12)
#define  AUTO_SOY_SOYCH0_B1_main_st_r_shift                                      (8)
#define  AUTO_SOY_SOYCH0_B1_dummy_7_6_shift                                      (6)
#define  AUTO_SOY_SOYCH0_B1_cali_st_r_shift                                      (4)
#define  AUTO_SOY_SOYCH0_B1_dummy_3_1_shift                                      (1)
#define  AUTO_SOY_SOYCH0_B1_ch0_cali_done_r_shift                                (0)
#define  AUTO_SOY_SOYCH0_B1_reg_soy_tst_sel_mask                                 (0x00030000)
#define  AUTO_SOY_SOYCH0_B1_seek_min_st_r_mask                                   (0x0000C000)
#define  AUTO_SOY_SOYCH0_B1_seek_max_st_r_mask                                   (0x00003000)
#define  AUTO_SOY_SOYCH0_B1_main_st_r_mask                                       (0x00000700)
#define  AUTO_SOY_SOYCH0_B1_dummy_7_6_mask                                       (0x000000C0)
#define  AUTO_SOY_SOYCH0_B1_cali_st_r_mask                                       (0x00000030)
#define  AUTO_SOY_SOYCH0_B1_dummy_3_1_mask                                       (0x0000000E)
#define  AUTO_SOY_SOYCH0_B1_ch0_cali_done_r_mask                                 (0x00000001)
#define  AUTO_SOY_SOYCH0_B1_reg_soy_tst_sel(data)                                (0x00030000&((data)<<16))
#define  AUTO_SOY_SOYCH0_B1_seek_min_st_r(data)                                  (0x0000C000&((data)<<14))
#define  AUTO_SOY_SOYCH0_B1_seek_max_st_r(data)                                  (0x00003000&((data)<<12))
#define  AUTO_SOY_SOYCH0_B1_main_st_r(data)                                      (0x00000700&((data)<<8))
#define  AUTO_SOY_SOYCH0_B1_dummy_7_6(data)                                      (0x000000C0&((data)<<6))
#define  AUTO_SOY_SOYCH0_B1_cali_st_r(data)                                      (0x00000030&((data)<<4))
#define  AUTO_SOY_SOYCH0_B1_dummy_3_1(data)                                      (0x0000000E&((data)<<1))
#define  AUTO_SOY_SOYCH0_B1_ch0_cali_done_r(data)                                (0x00000001&(data))
#define  AUTO_SOY_SOYCH0_B1_get_reg_soy_tst_sel(data)                            ((0x00030000&(data))>>16)
#define  AUTO_SOY_SOYCH0_B1_get_seek_min_st_r(data)                              ((0x0000C000&(data))>>14)
#define  AUTO_SOY_SOYCH0_B1_get_seek_max_st_r(data)                              ((0x00003000&(data))>>12)
#define  AUTO_SOY_SOYCH0_B1_get_main_st_r(data)                                  ((0x00000700&(data))>>8)
#define  AUTO_SOY_SOYCH0_B1_get_dummy_7_6(data)                                  ((0x000000C0&(data))>>6)
#define  AUTO_SOY_SOYCH0_B1_get_cali_st_r(data)                                  ((0x00000030&(data))>>4)
#define  AUTO_SOY_SOYCH0_B1_get_dummy_3_1(data)                                  ((0x0000000E&(data))>>1)
#define  AUTO_SOY_SOYCH0_B1_get_ch0_cali_done_r(data)                            (0x00000001&(data))

#define  AUTO_SOY_SOYCH0_D0                                                      0x1802031C
#define  AUTO_SOY_SOYCH0_D0_reg_addr                                             "0xB802031C"
#define  AUTO_SOY_SOYCH0_D0_reg                                                  0xB802031C
#define  AUTO_SOY_SOYCH0_D0_inst_addr                                            "0x0007"
#define  set_AUTO_SOY_SOYCH0_D0_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D0_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D0_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D0_reg))
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_3_r_shift                                   (24)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_2_r_shift                                   (16)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_1_r_shift                                   (8)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_0_r_shift                                   (0)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_3_r_mask                                    (0x3F000000)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_2_r_mask                                    (0x003F0000)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_1_r_mask                                    (0x00003F00)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_0_r_mask                                    (0x0000003F)
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_3_r(data)                                   (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_2_r(data)                                   (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_1_r(data)                                   (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D0_ch0_cali_0_r(data)                                   (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D0_get_ch0_cali_3_r(data)                               ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D0_get_ch0_cali_2_r(data)                               ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D0_get_ch0_cali_1_r(data)                               ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D0_get_ch0_cali_0_r(data)                               (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D1                                                      0x18020320
#define  AUTO_SOY_SOYCH0_D1_reg_addr                                             "0xB8020320"
#define  AUTO_SOY_SOYCH0_D1_reg                                                  0xB8020320
#define  AUTO_SOY_SOYCH0_D1_inst_addr                                            "0x0008"
#define  set_AUTO_SOY_SOYCH0_D1_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D1_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D1_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D1_reg))
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_7_r_shift                                   (24)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_6_r_shift                                   (16)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_5_r_shift                                   (8)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_4_r_shift                                   (0)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_7_r_mask                                    (0x3F000000)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_6_r_mask                                    (0x003F0000)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_5_r_mask                                    (0x00003F00)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_4_r_mask                                    (0x0000003F)
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_7_r(data)                                   (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_6_r(data)                                   (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_5_r(data)                                   (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D1_ch0_cali_4_r(data)                                   (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D1_get_ch0_cali_7_r(data)                               ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D1_get_ch0_cali_6_r(data)                               ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D1_get_ch0_cali_5_r(data)                               ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D1_get_ch0_cali_4_r(data)                               (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D2                                                      0x18020324
#define  AUTO_SOY_SOYCH0_D2_reg_addr                                             "0xB8020324"
#define  AUTO_SOY_SOYCH0_D2_reg                                                  0xB8020324
#define  AUTO_SOY_SOYCH0_D2_inst_addr                                            "0x0009"
#define  set_AUTO_SOY_SOYCH0_D2_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D2_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D2_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D2_reg))
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_11_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_10_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_9_r_shift                                   (8)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_8_r_shift                                   (0)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_11_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_10_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_9_r_mask                                    (0x00003F00)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_8_r_mask                                    (0x0000003F)
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_11_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_10_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_9_r(data)                                   (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D2_ch0_cali_8_r(data)                                   (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D2_get_ch0_cali_11_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D2_get_ch0_cali_10_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D2_get_ch0_cali_9_r(data)                               ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D2_get_ch0_cali_8_r(data)                               (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D3                                                      0x18020328
#define  AUTO_SOY_SOYCH0_D3_reg_addr                                             "0xB8020328"
#define  AUTO_SOY_SOYCH0_D3_reg                                                  0xB8020328
#define  AUTO_SOY_SOYCH0_D3_inst_addr                                            "0x000A"
#define  set_AUTO_SOY_SOYCH0_D3_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D3_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D3_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D3_reg))
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_15_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_14_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_13_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_12_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_15_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_14_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_13_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_12_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_15_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_14_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_13_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D3_ch0_cali_12_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D3_get_ch0_cali_15_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D3_get_ch0_cali_14_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D3_get_ch0_cali_13_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D3_get_ch0_cali_12_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D4                                                      0x1802032C
#define  AUTO_SOY_SOYCH0_D4_reg_addr                                             "0xB802032C"
#define  AUTO_SOY_SOYCH0_D4_reg                                                  0xB802032C
#define  AUTO_SOY_SOYCH0_D4_inst_addr                                            "0x000B"
#define  set_AUTO_SOY_SOYCH0_D4_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D4_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D4_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D4_reg))
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_19_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_18_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_17_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_16_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_19_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_18_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_17_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_16_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_19_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_18_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_17_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D4_ch0_cali_16_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D4_get_ch0_cali_19_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D4_get_ch0_cali_18_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D4_get_ch0_cali_17_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D4_get_ch0_cali_16_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D5                                                      0x18020330
#define  AUTO_SOY_SOYCH0_D5_reg_addr                                             "0xB8020330"
#define  AUTO_SOY_SOYCH0_D5_reg                                                  0xB8020330
#define  AUTO_SOY_SOYCH0_D5_inst_addr                                            "0x000C"
#define  set_AUTO_SOY_SOYCH0_D5_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D5_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D5_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D5_reg))
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_23_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_22_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_21_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_20_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_23_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_22_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_21_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_20_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_23_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_22_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_21_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D5_ch0_cali_20_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D5_get_ch0_cali_23_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D5_get_ch0_cali_22_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D5_get_ch0_cali_21_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D5_get_ch0_cali_20_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D6                                                      0x18020334
#define  AUTO_SOY_SOYCH0_D6_reg_addr                                             "0xB8020334"
#define  AUTO_SOY_SOYCH0_D6_reg                                                  0xB8020334
#define  AUTO_SOY_SOYCH0_D6_inst_addr                                            "0x000D"
#define  set_AUTO_SOY_SOYCH0_D6_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D6_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D6_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D6_reg))
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_27_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_26_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_25_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_24_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_27_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_26_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_25_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_24_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_27_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_26_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_25_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D6_ch0_cali_24_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D6_get_ch0_cali_27_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D6_get_ch0_cali_26_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D6_get_ch0_cali_25_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D6_get_ch0_cali_24_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D7                                                      0x18020338
#define  AUTO_SOY_SOYCH0_D7_reg_addr                                             "0xB8020338"
#define  AUTO_SOY_SOYCH0_D7_reg                                                  0xB8020338
#define  AUTO_SOY_SOYCH0_D7_inst_addr                                            "0x000E"
#define  set_AUTO_SOY_SOYCH0_D7_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D7_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D7_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D7_reg))
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_31_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_30_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_29_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_28_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_31_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_30_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_29_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_28_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_31_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_30_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_29_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D7_ch0_cali_28_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D7_get_ch0_cali_31_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D7_get_ch0_cali_30_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D7_get_ch0_cali_29_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D7_get_ch0_cali_28_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D8                                                      0x1802033C
#define  AUTO_SOY_SOYCH0_D8_reg_addr                                             "0xB802033C"
#define  AUTO_SOY_SOYCH0_D8_reg                                                  0xB802033C
#define  AUTO_SOY_SOYCH0_D8_inst_addr                                            "0x000F"
#define  set_AUTO_SOY_SOYCH0_D8_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D8_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D8_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D8_reg))
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_35_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_34_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_33_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_32_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_35_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_34_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_33_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_32_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_35_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_34_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_33_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D8_ch0_cali_32_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D8_get_ch0_cali_35_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D8_get_ch0_cali_34_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D8_get_ch0_cali_33_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D8_get_ch0_cali_32_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D9                                                      0x18020340
#define  AUTO_SOY_SOYCH0_D9_reg_addr                                             "0xB8020340"
#define  AUTO_SOY_SOYCH0_D9_reg                                                  0xB8020340
#define  AUTO_SOY_SOYCH0_D9_inst_addr                                            "0x0010"
#define  set_AUTO_SOY_SOYCH0_D9_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D9_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D9_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D9_reg))
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_39_r_shift                                  (24)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_38_r_shift                                  (16)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_37_r_shift                                  (8)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_36_r_shift                                  (0)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_39_r_mask                                   (0x3F000000)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_38_r_mask                                   (0x003F0000)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_37_r_mask                                   (0x00003F00)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_36_r_mask                                   (0x0000003F)
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_39_r(data)                                  (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_38_r(data)                                  (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_37_r(data)                                  (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D9_ch0_cali_36_r(data)                                  (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D9_get_ch0_cali_39_r(data)                              ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D9_get_ch0_cali_38_r(data)                              ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D9_get_ch0_cali_37_r(data)                              ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D9_get_ch0_cali_36_r(data)                              (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D10                                                     0x18020344
#define  AUTO_SOY_SOYCH0_D10_reg_addr                                            "0xB8020344"
#define  AUTO_SOY_SOYCH0_D10_reg                                                 0xB8020344
#define  AUTO_SOY_SOYCH0_D10_inst_addr                                           "0x0011"
#define  set_AUTO_SOY_SOYCH0_D10_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D10_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D10_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D10_reg))
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_43_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_42_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_41_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_40_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_43_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_42_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_41_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_40_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_43_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_42_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_41_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D10_ch0_cali_40_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D10_get_ch0_cali_43_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D10_get_ch0_cali_42_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D10_get_ch0_cali_41_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D10_get_ch0_cali_40_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D11                                                     0x18020348
#define  AUTO_SOY_SOYCH0_D11_reg_addr                                            "0xB8020348"
#define  AUTO_SOY_SOYCH0_D11_reg                                                 0xB8020348
#define  AUTO_SOY_SOYCH0_D11_inst_addr                                           "0x0012"
#define  set_AUTO_SOY_SOYCH0_D11_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D11_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D11_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D11_reg))
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_47_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_46_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_45_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_44_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_47_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_46_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_45_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_44_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_47_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_46_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_45_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D11_ch0_cali_44_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D11_get_ch0_cali_47_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D11_get_ch0_cali_46_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D11_get_ch0_cali_45_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D11_get_ch0_cali_44_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D12                                                     0x1802034C
#define  AUTO_SOY_SOYCH0_D12_reg_addr                                            "0xB802034C"
#define  AUTO_SOY_SOYCH0_D12_reg                                                 0xB802034C
#define  AUTO_SOY_SOYCH0_D12_inst_addr                                           "0x0013"
#define  set_AUTO_SOY_SOYCH0_D12_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D12_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D12_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D12_reg))
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_51_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_50_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_49_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_48_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_51_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_50_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_49_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_48_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_51_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_50_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_49_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D12_ch0_cali_48_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D12_get_ch0_cali_51_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D12_get_ch0_cali_50_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D12_get_ch0_cali_49_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D12_get_ch0_cali_48_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D13                                                     0x18020350
#define  AUTO_SOY_SOYCH0_D13_reg_addr                                            "0xB8020350"
#define  AUTO_SOY_SOYCH0_D13_reg                                                 0xB8020350
#define  AUTO_SOY_SOYCH0_D13_inst_addr                                           "0x0014"
#define  set_AUTO_SOY_SOYCH0_D13_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D13_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D13_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D13_reg))
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_55_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_54_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_53_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_52_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_55_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_54_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_53_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_52_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_55_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_54_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_53_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D13_ch0_cali_52_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D13_get_ch0_cali_55_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D13_get_ch0_cali_54_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D13_get_ch0_cali_53_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D13_get_ch0_cali_52_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D14                                                     0x18020354
#define  AUTO_SOY_SOYCH0_D14_reg_addr                                            "0xB8020354"
#define  AUTO_SOY_SOYCH0_D14_reg                                                 0xB8020354
#define  AUTO_SOY_SOYCH0_D14_inst_addr                                           "0x0015"
#define  set_AUTO_SOY_SOYCH0_D14_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D14_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D14_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D14_reg))
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_59_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_58_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_57_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_56_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_59_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_58_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_57_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_56_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_59_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_58_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_57_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D14_ch0_cali_56_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D14_get_ch0_cali_59_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D14_get_ch0_cali_58_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D14_get_ch0_cali_57_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D14_get_ch0_cali_56_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH0_D15                                                     0x18020358
#define  AUTO_SOY_SOYCH0_D15_reg_addr                                            "0xB8020358"
#define  AUTO_SOY_SOYCH0_D15_reg                                                 0xB8020358
#define  AUTO_SOY_SOYCH0_D15_inst_addr                                           "0x0016"
#define  set_AUTO_SOY_SOYCH0_D15_reg(data)                                       (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D15_reg)=data)
#define  get_AUTO_SOY_SOYCH0_D15_reg                                             (*((volatile unsigned int*)AUTO_SOY_SOYCH0_D15_reg))
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_63_r_shift                                 (24)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_62_r_shift                                 (16)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_61_r_shift                                 (8)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_60_r_shift                                 (0)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_63_r_mask                                  (0x3F000000)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_62_r_mask                                  (0x003F0000)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_61_r_mask                                  (0x00003F00)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_60_r_mask                                  (0x0000003F)
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_63_r(data)                                 (0x3F000000&((data)<<24))
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_62_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_61_r(data)                                 (0x00003F00&((data)<<8))
#define  AUTO_SOY_SOYCH0_D15_ch0_cali_60_r(data)                                 (0x0000003F&(data))
#define  AUTO_SOY_SOYCH0_D15_get_ch0_cali_63_r(data)                             ((0x3F000000&(data))>>24)
#define  AUTO_SOY_SOYCH0_D15_get_ch0_cali_62_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_SOYCH0_D15_get_ch0_cali_61_r(data)                             ((0x00003F00&(data))>>8)
#define  AUTO_SOY_SOYCH0_D15_get_ch0_cali_60_r(data)                             (0x0000003F&(data))

#define  AUTO_SOY_SOYCH1_A0                                                      0x1802035C
#define  AUTO_SOY_SOYCH1_A0_reg_addr                                             "0xB802035C"
#define  AUTO_SOY_SOYCH1_A0_reg                                                  0xB802035C
#define  AUTO_SOY_SOYCH1_A0_inst_addr                                            "0x0017"
#define  set_AUTO_SOY_SOYCH1_A0_reg(data)                                        (*((volatile unsigned int*)AUTO_SOY_SOYCH1_A0_reg)=data)
#define  get_AUTO_SOY_SOYCH1_A0_reg                                              (*((volatile unsigned int*)AUTO_SOY_SOYCH1_A0_reg))
#define  AUTO_SOY_SOYCH1_A0_reg_off_manu_comp_shift                              (0)
#define  AUTO_SOY_SOYCH1_A0_reg_off_manu_comp_mask                               (0x0000003F)
#define  AUTO_SOY_SOYCH1_A0_reg_off_manu_comp(data)                              (0x0000003F&(data))
#define  AUTO_SOY_SOYCH1_A0_get_reg_off_manu_comp(data)                          (0x0000003F&(data))

#define  AUTO_SOY_NO_TRIGGER_FLAG                                                0x18020360
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_addr                                       "0xB8020360"
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg                                            0xB8020360
#define  AUTO_SOY_NO_TRIGGER_FLAG_inst_addr                                      "0x0018"
#define  set_AUTO_SOY_NO_TRIGGER_FLAG_reg(data)                                  (*((volatile unsigned int*)AUTO_SOY_NO_TRIGGER_FLAG_reg)=data)
#define  get_AUTO_SOY_NO_TRIGGER_FLAG_reg                                        (*((volatile unsigned int*)AUTO_SOY_NO_TRIGGER_FLAG_reg))
#define  AUTO_SOY_NO_TRIGGER_FLAG_prev_glitch_st_en_shift                        (24)
#define  AUTO_SOY_NO_TRIGGER_FLAG_tap_01_r_shift                                 (16)
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_win_size_shift                     (2)
#define  AUTO_SOY_NO_TRIGGER_FLAG_no_trig_r_shift                                (1)
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_watch_en_shift                     (0)
#define  AUTO_SOY_NO_TRIGGER_FLAG_prev_glitch_st_en_mask                         (0x01000000)
#define  AUTO_SOY_NO_TRIGGER_FLAG_tap_01_r_mask                                  (0x003F0000)
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_win_size_mask                      (0x0000FFFC)
#define  AUTO_SOY_NO_TRIGGER_FLAG_no_trig_r_mask                                 (0x00000002)
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_watch_en_mask                      (0x00000001)
#define  AUTO_SOY_NO_TRIGGER_FLAG_prev_glitch_st_en(data)                        (0x01000000&((data)<<24))
#define  AUTO_SOY_NO_TRIGGER_FLAG_tap_01_r(data)                                 (0x003F0000&((data)<<16))
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_win_size(data)                     (0x0000FFFC&((data)<<2))
#define  AUTO_SOY_NO_TRIGGER_FLAG_no_trig_r(data)                                (0x00000002&((data)<<1))
#define  AUTO_SOY_NO_TRIGGER_FLAG_reg_no_trig_watch_en(data)                     (0x00000001&(data))
#define  AUTO_SOY_NO_TRIGGER_FLAG_get_prev_glitch_st_en(data)                    ((0x01000000&(data))>>24)
#define  AUTO_SOY_NO_TRIGGER_FLAG_get_tap_01_r(data)                             ((0x003F0000&(data))>>16)
#define  AUTO_SOY_NO_TRIGGER_FLAG_get_reg_no_trig_win_size(data)                 ((0x0000FFFC&(data))>>2)
#define  AUTO_SOY_NO_TRIGGER_FLAG_get_no_trig_r(data)                            ((0x00000002&(data))>>1)
#define  AUTO_SOY_NO_TRIGGER_FLAG_get_reg_no_trig_watch_en(data)                 (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======AUTO_SOY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_auto_ini_dc:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_deb_valid:6;
        RBus_UInt32  dummy18020300_15_14:2;
        RBus_UInt32  reg_deb_update:6;
        RBus_UInt32  dummy18020300_7:1;
        RBus_UInt32  reg_diff_sel_dclevel:1;
        RBus_UInt32  reg_update_mode:2;
        RBus_UInt32  reg_ma_mode:3;
        RBus_UInt32  reg_auto_mode:1;
    };
}auto_soy_soych0_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_max_hb:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_max_lb:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_min_hb:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_min_lb:6;
    };
}auto_soy_soych0_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  reg_max_window:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_min_window:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_min_diff:6;
    };
}auto_soy_soych0_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dc_out_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_manu_comp:6;
        RBus_UInt32  res3:10;
        RBus_UInt32  reg_dc_level_avg:2;
        RBus_UInt32  reg_dc_out_mode:4;
    };
}auto_soy_soych0_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cmp_level_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc_level_r:6;
        RBus_UInt32  max_hb_flag_r:1;
        RBus_UInt32  max_lb_flag_r:1;
        RBus_UInt32  max_r:6;
        RBus_UInt32  min_hb_flag_r:1;
        RBus_UInt32  min_lb_flag_r:1;
        RBus_UInt32  min_r:6;
    };
}auto_soy_soych0_a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_man_wr_addr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_man_wr_data:6;
        RBus_UInt32  res3:6;
        RBus_UInt32  reg_man_wr_1t:1;
        RBus_UInt32  reg_ch0_calibrate_cnt_base:5;
        RBus_UInt32  reg_ch0_calibrate_bypass:1;
        RBus_UInt32  reg_ch0_calibrate_val_rst:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_ch0_auto_calibrate_en:1;
    };
}auto_soy_soych0_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  reg_soy_tst_sel:2;
        RBus_UInt32  seek_min_st_r:2;
        RBus_UInt32  seek_max_st_r:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  main_st_r:3;
        RBus_UInt32  dummy18020318_7_6:2;
        RBus_UInt32  cali_st_r:2;
        RBus_UInt32  dummy18020318_3_1:3;
        RBus_UInt32  ch0_cali_done_r:1;
    };
}auto_soy_soych0_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_3_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_2_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_1_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_0_r:6;
    };
}auto_soy_soych0_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_7_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_6_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_5_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_4_r:6;
    };
}auto_soy_soych0_d1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_11_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_10_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_9_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_8_r:6;
    };
}auto_soy_soych0_d2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_15_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_14_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_13_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_12_r:6;
    };
}auto_soy_soych0_d3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_19_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_18_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_17_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_16_r:6;
    };
}auto_soy_soych0_d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_23_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_22_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_21_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_20_r:6;
    };
}auto_soy_soych0_d5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_27_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_26_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_25_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_24_r:6;
    };
}auto_soy_soych0_d6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_31_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_30_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_29_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_28_r:6;
    };
}auto_soy_soych0_d7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_35_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_34_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_33_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_32_r:6;
    };
}auto_soy_soych0_d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_39_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_38_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_37_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_36_r:6;
    };
}auto_soy_soych0_d9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_43_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_42_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_41_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_40_r:6;
    };
}auto_soy_soych0_d10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_47_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_46_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_45_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_44_r:6;
    };
}auto_soy_soych0_d11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_51_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_50_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_49_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_48_r:6;
    };
}auto_soy_soych0_d12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_55_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_54_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_53_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_52_r:6;
    };
}auto_soy_soych0_d13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_59_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_58_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_57_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_56_r:6;
    };
}auto_soy_soych0_d14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_63_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_62_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_61_r:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch0_cali_60_r:6;
    };
}auto_soy_soych0_d15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  reg_off_manu_comp:6;
    };
}auto_soy_soych1_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  prev_glitch_st_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  tap_01_r:6;
        RBus_UInt32  reg_no_trig_win_size:14;
        RBus_UInt32  no_trig_r:1;
        RBus_UInt32  reg_no_trig_watch_en:1;
    };
}auto_soy_no_trigger_flag_RBUS;

#else //apply LITTLE_ENDIAN

//======AUTO_SOY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_auto_mode:1;
        RBus_UInt32  reg_ma_mode:3;
        RBus_UInt32  reg_update_mode:2;
        RBus_UInt32  reg_diff_sel_dclevel:1;
        RBus_UInt32  dummy18020300_7:1;
        RBus_UInt32  reg_deb_update:6;
        RBus_UInt32  dummy18020300_15:2;
        RBus_UInt32  reg_deb_valid:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_auto_ini_dc:6;
        RBus_UInt32  res2:2;
    };
}auto_soy_soych0_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_min_lb:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_min_hb:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_max_lb:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_max_hb:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_a1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_min_diff:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_min_window:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_max_window:5;
        RBus_UInt32  res3:11;
    };
}auto_soy_soych0_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dc_out_mode:4;
        RBus_UInt32  reg_dc_level_avg:2;
        RBus_UInt32  res1:10;
        RBus_UInt32  reg_manu_comp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_dc_out_offset:6;
        RBus_UInt32  res3:2;
    };
}auto_soy_soych0_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_r:6;
        RBus_UInt32  min_lb_flag_r:1;
        RBus_UInt32  min_hb_flag_r:1;
        RBus_UInt32  max_r:6;
        RBus_UInt32  max_lb_flag_r:1;
        RBus_UInt32  max_hb_flag_r:1;
        RBus_UInt32  dc_level_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cmp_level_r:6;
        RBus_UInt32  res2:2;
    };
}auto_soy_soych0_a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ch0_auto_calibrate_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_ch0_calibrate_val_rst:1;
        RBus_UInt32  reg_ch0_calibrate_bypass:1;
        RBus_UInt32  reg_ch0_calibrate_cnt_base:5;
        RBus_UInt32  reg_man_wr_1t:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  reg_man_wr_data:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_man_wr_addr:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_done_r:1;
        RBus_UInt32  dummy18020318_3:3;
        RBus_UInt32  cali_st_r:2;
        RBus_UInt32  dummy18020318_7:2;
        RBus_UInt32  main_st_r:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  seek_max_st_r:2;
        RBus_UInt32  seek_min_st_r:2;
        RBus_UInt32  reg_soy_tst_sel:2;
        RBus_UInt32  res2:14;
    };
}auto_soy_soych0_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_0_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_1_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_2_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_3_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_4_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_5_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_6_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_7_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_8_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_9_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_10_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_11_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_12_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_13_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_14_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_15_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_16_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_17_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_18_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_19_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_20_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_21_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_22_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_23_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_24_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_25_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_26_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_27_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_28_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_29_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_30_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_31_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_32_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_33_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_34_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_35_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_36_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_37_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_38_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_39_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_40_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_41_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_42_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_43_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_44_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_45_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_46_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_47_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_48_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_49_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_50_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_51_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_52_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_53_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_54_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_55_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_56_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_57_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_58_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_59_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch0_cali_60_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ch0_cali_61_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ch0_cali_62_r:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch0_cali_63_r:6;
        RBus_UInt32  res4:2;
    };
}auto_soy_soych0_d15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_off_manu_comp:6;
        RBus_UInt32  res1:26;
    };
}auto_soy_soych1_a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_no_trig_watch_en:1;
        RBus_UInt32  no_trig_r:1;
        RBus_UInt32  reg_no_trig_win_size:14;
        RBus_UInt32  tap_01_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  prev_glitch_st_en:1;
        RBus_UInt32  res2:7;
    };
}auto_soy_no_trigger_flag_RBUS;




#endif 


#endif 
