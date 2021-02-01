/**
* @file Mac5-DesignSpec-D_Domain_DISP_IF
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PIF_REG_H_
#define _RBUS_PIF_REG_H_

#include "rbus_types.h"



//  PIF Register Address
#define  PIF_LVDS_CTRL0                                                          0x1802D000
#define  PIF_LVDS_CTRL0_reg_addr                                                 "0xB802D000"
#define  PIF_LVDS_CTRL0_reg                                                      0xB802D000
#define  PIF_LVDS_CTRL0_inst_addr                                                "0x0000"
#define  set_PIF_LVDS_CTRL0_reg(data)                                            (*((volatile unsigned int*)PIF_LVDS_CTRL0_reg)=data)
#define  get_PIF_LVDS_CTRL0_reg                                                  (*((volatile unsigned int*)PIF_LVDS_CTRL0_reg))
#define  PIF_LVDS_CTRL0_pif_debug_sel_shift                                      (4)
#define  PIF_LVDS_CTRL0_plt_lvds_mode_shift                                      (2)
#define  PIF_LVDS_CTRL0_pif_debug_sel_mask                                       (0x000000F0)
#define  PIF_LVDS_CTRL0_plt_lvds_mode_mask                                       (0x0000000C)
#define  PIF_LVDS_CTRL0_pif_debug_sel(data)                                      (0x000000F0&((data)<<4))
#define  PIF_LVDS_CTRL0_plt_lvds_mode(data)                                      (0x0000000C&((data)<<2))
#define  PIF_LVDS_CTRL0_get_pif_debug_sel(data)                                  ((0x000000F0&(data))>>4)
#define  PIF_LVDS_CTRL0_get_plt_lvds_mode(data)                                  ((0x0000000C&(data))>>2)

#define  PIF_LVDS_DUMMY_0                                                        0x1802D004
#define  PIF_LVDS_DUMMY_0_reg_addr                                               "0xB802D004"
#define  PIF_LVDS_DUMMY_0_reg                                                    0xB802D004
#define  PIF_LVDS_DUMMY_0_inst_addr                                              "0x0001"
#define  set_PIF_LVDS_DUMMY_0_reg(data)                                          (*((volatile unsigned int*)PIF_LVDS_DUMMY_0_reg)=data)
#define  get_PIF_LVDS_DUMMY_0_reg                                                (*((volatile unsigned int*)PIF_LVDS_DUMMY_0_reg))
#define  PIF_LVDS_DUMMY_0_dummy_31_0_shift                                       (0)
#define  PIF_LVDS_DUMMY_0_dummy_31_0_mask                                        (0xFFFFFFFF)
#define  PIF_LVDS_DUMMY_0_dummy_31_0(data)                                       (0xFFFFFFFF&(data))
#define  PIF_LVDS_DUMMY_0_get_dummy_31_0(data)                                   (0xFFFFFFFF&(data))

#define  PIF_LVDS_CTRL1                                                          0x1802D008
#define  PIF_LVDS_CTRL1_reg_addr                                                 "0xB802D008"
#define  PIF_LVDS_CTRL1_reg                                                      0xB802D008
#define  PIF_LVDS_CTRL1_inst_addr                                                "0x0002"
#define  set_PIF_LVDS_CTRL1_reg(data)                                            (*((volatile unsigned int*)PIF_LVDS_CTRL1_reg)=data)
#define  get_PIF_LVDS_CTRL1_reg                                                  (*((volatile unsigned int*)PIF_LVDS_CTRL1_reg))
#define  PIF_LVDS_CTRL1_lvds_arsv1_sel_shift                                     (29)
#define  PIF_LVDS_CTRL1_lvds_arsv0_sel_shift                                     (26)
#define  PIF_LVDS_CTRL1_lvds_aden_sel_shift                                      (23)
#define  PIF_LVDS_CTRL1_lvds_avs_sel_shift                                       (20)
#define  PIF_LVDS_CTRL1_lvds_ahs_sel_shift                                       (17)
#define  PIF_LVDS_CTRL1_lvds_brsv1_sel_shift                                     (13)
#define  PIF_LVDS_CTRL1_lvds_brsv0_sel_shift                                     (10)
#define  PIF_LVDS_CTRL1_lvds_bden_sel_shift                                      (7)
#define  PIF_LVDS_CTRL1_lvds_bvs_sel_shift                                       (4)
#define  PIF_LVDS_CTRL1_lvds_bhs_sel_shift                                       (1)
#define  PIF_LVDS_CTRL1_lvds_arsv1_sel_mask                                      (0xE0000000)
#define  PIF_LVDS_CTRL1_lvds_arsv0_sel_mask                                      (0x1C000000)
#define  PIF_LVDS_CTRL1_lvds_aden_sel_mask                                       (0x03800000)
#define  PIF_LVDS_CTRL1_lvds_avs_sel_mask                                        (0x00700000)
#define  PIF_LVDS_CTRL1_lvds_ahs_sel_mask                                        (0x000E0000)
#define  PIF_LVDS_CTRL1_lvds_brsv1_sel_mask                                      (0x0000E000)
#define  PIF_LVDS_CTRL1_lvds_brsv0_sel_mask                                      (0x00001C00)
#define  PIF_LVDS_CTRL1_lvds_bden_sel_mask                                       (0x00000380)
#define  PIF_LVDS_CTRL1_lvds_bvs_sel_mask                                        (0x00000070)
#define  PIF_LVDS_CTRL1_lvds_bhs_sel_mask                                        (0x0000000E)
#define  PIF_LVDS_CTRL1_lvds_arsv1_sel(data)                                     (0xE0000000&((data)<<29))
#define  PIF_LVDS_CTRL1_lvds_arsv0_sel(data)                                     (0x1C000000&((data)<<26))
#define  PIF_LVDS_CTRL1_lvds_aden_sel(data)                                      (0x03800000&((data)<<23))
#define  PIF_LVDS_CTRL1_lvds_avs_sel(data)                                       (0x00700000&((data)<<20))
#define  PIF_LVDS_CTRL1_lvds_ahs_sel(data)                                       (0x000E0000&((data)<<17))
#define  PIF_LVDS_CTRL1_lvds_brsv1_sel(data)                                     (0x0000E000&((data)<<13))
#define  PIF_LVDS_CTRL1_lvds_brsv0_sel(data)                                     (0x00001C00&((data)<<10))
#define  PIF_LVDS_CTRL1_lvds_bden_sel(data)                                      (0x00000380&((data)<<7))
#define  PIF_LVDS_CTRL1_lvds_bvs_sel(data)                                       (0x00000070&((data)<<4))
#define  PIF_LVDS_CTRL1_lvds_bhs_sel(data)                                       (0x0000000E&((data)<<1))
#define  PIF_LVDS_CTRL1_get_lvds_arsv1_sel(data)                                 ((0xE0000000&(data))>>29)
#define  PIF_LVDS_CTRL1_get_lvds_arsv0_sel(data)                                 ((0x1C000000&(data))>>26)
#define  PIF_LVDS_CTRL1_get_lvds_aden_sel(data)                                  ((0x03800000&(data))>>23)
#define  PIF_LVDS_CTRL1_get_lvds_avs_sel(data)                                   ((0x00700000&(data))>>20)
#define  PIF_LVDS_CTRL1_get_lvds_ahs_sel(data)                                   ((0x000E0000&(data))>>17)
#define  PIF_LVDS_CTRL1_get_lvds_brsv1_sel(data)                                 ((0x0000E000&(data))>>13)
#define  PIF_LVDS_CTRL1_get_lvds_brsv0_sel(data)                                 ((0x00001C00&(data))>>10)
#define  PIF_LVDS_CTRL1_get_lvds_bden_sel(data)                                  ((0x00000380&(data))>>7)
#define  PIF_LVDS_CTRL1_get_lvds_bvs_sel(data)                                   ((0x00000070&(data))>>4)
#define  PIF_LVDS_CTRL1_get_lvds_bhs_sel(data)                                   ((0x0000000E&(data))>>1)

#define  PIF_LVDS_CTRL2                                                          0x1802D00C
#define  PIF_LVDS_CTRL2_reg_addr                                                 "0xB802D00C"
#define  PIF_LVDS_CTRL2_reg                                                      0xB802D00C
#define  PIF_LVDS_CTRL2_inst_addr                                                "0x0003"
#define  set_PIF_LVDS_CTRL2_reg(data)                                            (*((volatile unsigned int*)PIF_LVDS_CTRL2_reg)=data)
#define  get_PIF_LVDS_CTRL2_reg                                                  (*((volatile unsigned int*)PIF_LVDS_CTRL2_reg))
#define  PIF_LVDS_CTRL2_lvds_crsv1_sel_shift                                     (29)
#define  PIF_LVDS_CTRL2_lvds_crsv0_sel_shift                                     (26)
#define  PIF_LVDS_CTRL2_lvds_cden_sel_shift                                      (23)
#define  PIF_LVDS_CTRL2_lvds_cvs_sel_shift                                       (20)
#define  PIF_LVDS_CTRL2_lvds_chs_sel_shift                                       (17)
#define  PIF_LVDS_CTRL2_lvds_drsv1_sel_shift                                     (13)
#define  PIF_LVDS_CTRL2_lvds_drsv0_sel_shift                                     (10)
#define  PIF_LVDS_CTRL2_lvds_dden_sel_shift                                      (7)
#define  PIF_LVDS_CTRL2_lvds_dvs_sel_shift                                       (4)
#define  PIF_LVDS_CTRL2_lvds_dhs_sel_shift                                       (1)
#define  PIF_LVDS_CTRL2_lvds_crsv1_sel_mask                                      (0xE0000000)
#define  PIF_LVDS_CTRL2_lvds_crsv0_sel_mask                                      (0x1C000000)
#define  PIF_LVDS_CTRL2_lvds_cden_sel_mask                                       (0x03800000)
#define  PIF_LVDS_CTRL2_lvds_cvs_sel_mask                                        (0x00700000)
#define  PIF_LVDS_CTRL2_lvds_chs_sel_mask                                        (0x000E0000)
#define  PIF_LVDS_CTRL2_lvds_drsv1_sel_mask                                      (0x0000E000)
#define  PIF_LVDS_CTRL2_lvds_drsv0_sel_mask                                      (0x00001C00)
#define  PIF_LVDS_CTRL2_lvds_dden_sel_mask                                       (0x00000380)
#define  PIF_LVDS_CTRL2_lvds_dvs_sel_mask                                        (0x00000070)
#define  PIF_LVDS_CTRL2_lvds_dhs_sel_mask                                        (0x0000000E)
#define  PIF_LVDS_CTRL2_lvds_crsv1_sel(data)                                     (0xE0000000&((data)<<29))
#define  PIF_LVDS_CTRL2_lvds_crsv0_sel(data)                                     (0x1C000000&((data)<<26))
#define  PIF_LVDS_CTRL2_lvds_cden_sel(data)                                      (0x03800000&((data)<<23))
#define  PIF_LVDS_CTRL2_lvds_cvs_sel(data)                                       (0x00700000&((data)<<20))
#define  PIF_LVDS_CTRL2_lvds_chs_sel(data)                                       (0x000E0000&((data)<<17))
#define  PIF_LVDS_CTRL2_lvds_drsv1_sel(data)                                     (0x0000E000&((data)<<13))
#define  PIF_LVDS_CTRL2_lvds_drsv0_sel(data)                                     (0x00001C00&((data)<<10))
#define  PIF_LVDS_CTRL2_lvds_dden_sel(data)                                      (0x00000380&((data)<<7))
#define  PIF_LVDS_CTRL2_lvds_dvs_sel(data)                                       (0x00000070&((data)<<4))
#define  PIF_LVDS_CTRL2_lvds_dhs_sel(data)                                       (0x0000000E&((data)<<1))
#define  PIF_LVDS_CTRL2_get_lvds_crsv1_sel(data)                                 ((0xE0000000&(data))>>29)
#define  PIF_LVDS_CTRL2_get_lvds_crsv0_sel(data)                                 ((0x1C000000&(data))>>26)
#define  PIF_LVDS_CTRL2_get_lvds_cden_sel(data)                                  ((0x03800000&(data))>>23)
#define  PIF_LVDS_CTRL2_get_lvds_cvs_sel(data)                                   ((0x00700000&(data))>>20)
#define  PIF_LVDS_CTRL2_get_lvds_chs_sel(data)                                   ((0x000E0000&(data))>>17)
#define  PIF_LVDS_CTRL2_get_lvds_drsv1_sel(data)                                 ((0x0000E000&(data))>>13)
#define  PIF_LVDS_CTRL2_get_lvds_drsv0_sel(data)                                 ((0x00001C00&(data))>>10)
#define  PIF_LVDS_CTRL2_get_lvds_dden_sel(data)                                  ((0x00000380&(data))>>7)
#define  PIF_LVDS_CTRL2_get_lvds_dvs_sel(data)                                   ((0x00000070&(data))>>4)
#define  PIF_LVDS_CTRL2_get_lvds_dhs_sel(data)                                   ((0x0000000E&(data))>>1)

#define  PIF_LVDS_CTRL3                                                          0x1802D010
#define  PIF_LVDS_CTRL3_reg_addr                                                 "0xB802D010"
#define  PIF_LVDS_CTRL3_reg                                                      0xB802D010
#define  PIF_LVDS_CTRL3_inst_addr                                                "0x0004"
#define  set_PIF_LVDS_CTRL3_reg(data)                                            (*((volatile unsigned int*)PIF_LVDS_CTRL3_reg)=data)
#define  get_PIF_LVDS_CTRL3_reg                                                  (*((volatile unsigned int*)PIF_LVDS_CTRL3_reg))
#define  PIF_LVDS_CTRL3_lvds_map_inv_shift                                       (14)
#define  PIF_LVDS_CTRL3_lvds_map_shift                                           (12)
#define  PIF_LVDS_CTRL3_lvds_pn_swap_shift                                       (11)
#define  PIF_LVDS_CTRL3_dummy_10_shift                                           (10)
#define  PIF_LVDS_CTRL3_lvds_aport_en_shift                                      (7)
#define  PIF_LVDS_CTRL3_lvds_bport_en_shift                                      (6)
#define  PIF_LVDS_CTRL3_lvds_cport_en_shift                                      (5)
#define  PIF_LVDS_CTRL3_lvds_dport_en_shift                                      (4)
#define  PIF_LVDS_CTRL3_dummy_1_0_shift                                          (0)
#define  PIF_LVDS_CTRL3_lvds_map_inv_mask                                        (0x00004000)
#define  PIF_LVDS_CTRL3_lvds_map_mask                                            (0x00003000)
#define  PIF_LVDS_CTRL3_lvds_pn_swap_mask                                        (0x00000800)
#define  PIF_LVDS_CTRL3_dummy_10_mask                                            (0x00000400)
#define  PIF_LVDS_CTRL3_lvds_aport_en_mask                                       (0x00000080)
#define  PIF_LVDS_CTRL3_lvds_bport_en_mask                                       (0x00000040)
#define  PIF_LVDS_CTRL3_lvds_cport_en_mask                                       (0x00000020)
#define  PIF_LVDS_CTRL3_lvds_dport_en_mask                                       (0x00000010)
#define  PIF_LVDS_CTRL3_dummy_1_0_mask                                           (0x00000003)
#define  PIF_LVDS_CTRL3_lvds_map_inv(data)                                       (0x00004000&((data)<<14))
#define  PIF_LVDS_CTRL3_lvds_map(data)                                           (0x00003000&((data)<<12))
#define  PIF_LVDS_CTRL3_lvds_pn_swap(data)                                       (0x00000800&((data)<<11))
#define  PIF_LVDS_CTRL3_dummy_10(data)                                           (0x00000400&((data)<<10))
#define  PIF_LVDS_CTRL3_lvds_aport_en(data)                                      (0x00000080&((data)<<7))
#define  PIF_LVDS_CTRL3_lvds_bport_en(data)                                      (0x00000040&((data)<<6))
#define  PIF_LVDS_CTRL3_lvds_cport_en(data)                                      (0x00000020&((data)<<5))
#define  PIF_LVDS_CTRL3_lvds_dport_en(data)                                      (0x00000010&((data)<<4))
#define  PIF_LVDS_CTRL3_dummy_1_0(data)                                          (0x00000003&(data))
#define  PIF_LVDS_CTRL3_get_lvds_map_inv(data)                                   ((0x00004000&(data))>>14)
#define  PIF_LVDS_CTRL3_get_lvds_map(data)                                       ((0x00003000&(data))>>12)
#define  PIF_LVDS_CTRL3_get_lvds_pn_swap(data)                                   ((0x00000800&(data))>>11)
#define  PIF_LVDS_CTRL3_get_dummy_10(data)                                       ((0x00000400&(data))>>10)
#define  PIF_LVDS_CTRL3_get_lvds_aport_en(data)                                  ((0x00000080&(data))>>7)
#define  PIF_LVDS_CTRL3_get_lvds_bport_en(data)                                  ((0x00000040&(data))>>6)
#define  PIF_LVDS_CTRL3_get_lvds_cport_en(data)                                  ((0x00000020&(data))>>5)
#define  PIF_LVDS_CTRL3_get_lvds_dport_en(data)                                  ((0x00000010&(data))>>4)
#define  PIF_LVDS_CTRL3_get_dummy_1_0(data)                                      (0x00000003&(data))

#define  PIF_MLVDS_CTRL0                                                         0x1802D01C
#define  PIF_MLVDS_CTRL0_reg_addr                                                "0xB802D01C"
#define  PIF_MLVDS_CTRL0_reg                                                     0xB802D01C
#define  PIF_MLVDS_CTRL0_inst_addr                                               "0x0005"
#define  set_PIF_MLVDS_CTRL0_reg(data)                                           (*((volatile unsigned int*)PIF_MLVDS_CTRL0_reg)=data)
#define  get_PIF_MLVDS_CTRL0_reg                                                 (*((volatile unsigned int*)PIF_MLVDS_CTRL0_reg))
#define  PIF_MLVDS_CTRL0_dummy_31_12_shift                                       (12)
#define  PIF_MLVDS_CTRL0_mlvds_map_type_sel_shift                                (8)
#define  PIF_MLVDS_CTRL0_mlvds_en_shift                                          (7)
#define  PIF_MLVDS_CTRL0_mlvds_map_inv_shift                                     (6)
#define  PIF_MLVDS_CTRL0_mlvds_8p_special_swap_shift                             (5)
#define  PIF_MLVDS_CTRL0_mlvds_rl_swap_shift                                     (4)
#define  PIF_MLVDS_CTRL0_mlvds_pn_swap_shift                                     (3)
#define  PIF_MLVDS_CTRL0_dummy_2_shift                                           (2)
#define  PIF_MLVDS_CTRL0_mlvds_mode_shift                                        (0)
#define  PIF_MLVDS_CTRL0_dummy_31_12_mask                                        (0xFFFFF000)
#define  PIF_MLVDS_CTRL0_mlvds_map_type_sel_mask                                 (0x00000F00)
#define  PIF_MLVDS_CTRL0_mlvds_en_mask                                           (0x00000080)
#define  PIF_MLVDS_CTRL0_mlvds_map_inv_mask                                      (0x00000040)
#define  PIF_MLVDS_CTRL0_mlvds_8p_special_swap_mask                              (0x00000020)
#define  PIF_MLVDS_CTRL0_mlvds_rl_swap_mask                                      (0x00000010)
#define  PIF_MLVDS_CTRL0_mlvds_pn_swap_mask                                      (0x00000008)
#define  PIF_MLVDS_CTRL0_dummy_2_mask                                            (0x00000004)
#define  PIF_MLVDS_CTRL0_mlvds_mode_mask                                         (0x00000003)
#define  PIF_MLVDS_CTRL0_dummy_31_12(data)                                       (0xFFFFF000&((data)<<12))
#define  PIF_MLVDS_CTRL0_mlvds_map_type_sel(data)                                (0x00000F00&((data)<<8))
#define  PIF_MLVDS_CTRL0_mlvds_en(data)                                          (0x00000080&((data)<<7))
#define  PIF_MLVDS_CTRL0_mlvds_map_inv(data)                                     (0x00000040&((data)<<6))
#define  PIF_MLVDS_CTRL0_mlvds_8p_special_swap(data)                             (0x00000020&((data)<<5))
#define  PIF_MLVDS_CTRL0_mlvds_rl_swap(data)                                     (0x00000010&((data)<<4))
#define  PIF_MLVDS_CTRL0_mlvds_pn_swap(data)                                     (0x00000008&((data)<<3))
#define  PIF_MLVDS_CTRL0_dummy_2(data)                                           (0x00000004&((data)<<2))
#define  PIF_MLVDS_CTRL0_mlvds_mode(data)                                        (0x00000003&(data))
#define  PIF_MLVDS_CTRL0_get_dummy_31_12(data)                                   ((0xFFFFF000&(data))>>12)
#define  PIF_MLVDS_CTRL0_get_mlvds_map_type_sel(data)                            ((0x00000F00&(data))>>8)
#define  PIF_MLVDS_CTRL0_get_mlvds_en(data)                                      ((0x00000080&(data))>>7)
#define  PIF_MLVDS_CTRL0_get_mlvds_map_inv(data)                                 ((0x00000040&(data))>>6)
#define  PIF_MLVDS_CTRL0_get_mlvds_8p_special_swap(data)                         ((0x00000020&(data))>>5)
#define  PIF_MLVDS_CTRL0_get_mlvds_rl_swap(data)                                 ((0x00000010&(data))>>4)
#define  PIF_MLVDS_CTRL0_get_mlvds_pn_swap(data)                                 ((0x00000008&(data))>>3)
#define  PIF_MLVDS_CTRL0_get_dummy_2(data)                                       ((0x00000004&(data))>>2)
#define  PIF_MLVDS_CTRL0_get_mlvds_mode(data)                                    (0x00000003&(data))

#define  PIF_MLVDS_Reset_Pul_CTRL                                                0x1802D020
#define  PIF_MLVDS_Reset_Pul_CTRL_reg_addr                                       "0xB802D020"
#define  PIF_MLVDS_Reset_Pul_CTRL_reg                                            0xB802D020
#define  PIF_MLVDS_Reset_Pul_CTRL_inst_addr                                      "0x0006"
#define  set_PIF_MLVDS_Reset_Pul_CTRL_reg(data)                                  (*((volatile unsigned int*)PIF_MLVDS_Reset_Pul_CTRL_reg)=data)
#define  get_PIF_MLVDS_Reset_Pul_CTRL_reg                                        (*((volatile unsigned int*)PIF_MLVDS_Reset_Pul_CTRL_reg))
#define  PIF_MLVDS_Reset_Pul_CTRL_dummy_31_12_shift                              (12)
#define  PIF_MLVDS_Reset_Pul_CTRL_mlvds_reset_pul_sel_shift                      (0)
#define  PIF_MLVDS_Reset_Pul_CTRL_dummy_31_12_mask                               (0xFFFFF000)
#define  PIF_MLVDS_Reset_Pul_CTRL_mlvds_reset_pul_sel_mask                       (0x00000FFF)
#define  PIF_MLVDS_Reset_Pul_CTRL_dummy_31_12(data)                              (0xFFFFF000&((data)<<12))
#define  PIF_MLVDS_Reset_Pul_CTRL_mlvds_reset_pul_sel(data)                      (0x00000FFF&(data))
#define  PIF_MLVDS_Reset_Pul_CTRL_get_dummy_31_12(data)                          ((0xFFFFF000&(data))>>12)
#define  PIF_MLVDS_Reset_Pul_CTRL_get_mlvds_reset_pul_sel(data)                  (0x00000FFF&(data))

#define  PIF_MLVDS_CTRL1                                                         0x1802D024
#define  PIF_MLVDS_CTRL1_reg_addr                                                "0xB802D024"
#define  PIF_MLVDS_CTRL1_reg                                                     0xB802D024
#define  PIF_MLVDS_CTRL1_inst_addr                                               "0x0007"
#define  set_PIF_MLVDS_CTRL1_reg(data)                                           (*((volatile unsigned int*)PIF_MLVDS_CTRL1_reg)=data)
#define  get_PIF_MLVDS_CTRL1_reg                                                 (*((volatile unsigned int*)PIF_MLVDS_CTRL1_reg))
#define  PIF_MLVDS_CTRL1_tcon_sel_shift                                          (24)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_7_shift                                  (22)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_6_shift                                  (20)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_5_shift                                  (18)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_4_shift                                  (16)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_3_shift                                  (14)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_2_shift                                  (12)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_1_shift                                  (10)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_0_shift                                  (8)
#define  PIF_MLVDS_CTRL1_mlvds_rst_tcon_en_shift                                 (7)
#define  PIF_MLVDS_CTRL1_mlvds_rst_high_shift                                    (0)
#define  PIF_MLVDS_CTRL1_tcon_sel_mask                                           (0xFF000000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_7_mask                                   (0x00C00000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_6_mask                                   (0x00300000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_5_mask                                   (0x000C0000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_4_mask                                   (0x00030000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_3_mask                                   (0x0000C000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_2_mask                                   (0x00003000)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_1_mask                                   (0x00000C00)
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_0_mask                                   (0x00000300)
#define  PIF_MLVDS_CTRL1_mlvds_rst_tcon_en_mask                                  (0x00000080)
#define  PIF_MLVDS_CTRL1_mlvds_rst_high_mask                                     (0x0000001F)
#define  PIF_MLVDS_CTRL1_tcon_sel(data)                                          (0xFF000000&((data)<<24))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_7(data)                                  (0x00C00000&((data)<<22))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_6(data)                                  (0x00300000&((data)<<20))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_5(data)                                  (0x000C0000&((data)<<18))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_4(data)                                  (0x00030000&((data)<<16))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_3(data)                                  (0x0000C000&((data)<<14))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_2(data)                                  (0x00003000&((data)<<12))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_1(data)                                  (0x00000C00&((data)<<10))
#define  PIF_MLVDS_CTRL1_tcon_delay_sel_0(data)                                  (0x00000300&((data)<<8))
#define  PIF_MLVDS_CTRL1_mlvds_rst_tcon_en(data)                                 (0x00000080&((data)<<7))
#define  PIF_MLVDS_CTRL1_mlvds_rst_high(data)                                    (0x0000001F&(data))
#define  PIF_MLVDS_CTRL1_get_tcon_sel(data)                                      ((0xFF000000&(data))>>24)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_7(data)                              ((0x00C00000&(data))>>22)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_6(data)                              ((0x00300000&(data))>>20)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_5(data)                              ((0x000C0000&(data))>>18)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_4(data)                              ((0x00030000&(data))>>16)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_3(data)                              ((0x0000C000&(data))>>14)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_2(data)                              ((0x00003000&(data))>>12)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_1(data)                              ((0x00000C00&(data))>>10)
#define  PIF_MLVDS_CTRL1_get_tcon_delay_sel_0(data)                              ((0x00000300&(data))>>8)
#define  PIF_MLVDS_CTRL1_get_mlvds_rst_tcon_en(data)                             ((0x00000080&(data))>>7)
#define  PIF_MLVDS_CTRL1_get_mlvds_rst_high(data)                                (0x0000001F&(data))

#define  PIF_MLVDS_CTRL2                                                         0x1802D028
#define  PIF_MLVDS_CTRL2_reg_addr                                                "0xB802D028"
#define  PIF_MLVDS_CTRL2_reg                                                     0xB802D028
#define  PIF_MLVDS_CTRL2_inst_addr                                               "0x0008"
#define  set_PIF_MLVDS_CTRL2_reg(data)                                           (*((volatile unsigned int*)PIF_MLVDS_CTRL2_reg)=data)
#define  get_PIF_MLVDS_CTRL2_reg                                                 (*((volatile unsigned int*)PIF_MLVDS_CTRL2_reg))
#define  PIF_MLVDS_CTRL2_mlvds_rst_low_region_shift                              (31)
#define  PIF_MLVDS_CTRL2_dummy_29_28_shift                                       (28)
#define  PIF_MLVDS_CTRL2_mlvds_2ck_inv_shift                                     (27)
#define  PIF_MLVDS_CTRL2_mlvds_1ck_inv_shift                                     (26)
#define  PIF_MLVDS_CTRL2_fw_merge_tcon_en_shift                                  (24)
#define  PIF_MLVDS_CTRL2_p3_tcon_en_shift                                        (23)
#define  PIF_MLVDS_CTRL2_p3_tcon_sel_shift                                       (16)
#define  PIF_MLVDS_CTRL2_p2_tcon_en_shift                                        (15)
#define  PIF_MLVDS_CTRL2_p2_tcon_sel_shift                                       (8)
#define  PIF_MLVDS_CTRL2_p1_tcon_en_shift                                        (7)
#define  PIF_MLVDS_CTRL2_p1_tcon_sel_shift                                       (0)
#define  PIF_MLVDS_CTRL2_mlvds_rst_low_region_mask                               (0x80000000)
#define  PIF_MLVDS_CTRL2_dummy_29_28_mask                                        (0x30000000)
#define  PIF_MLVDS_CTRL2_mlvds_2ck_inv_mask                                      (0x08000000)
#define  PIF_MLVDS_CTRL2_mlvds_1ck_inv_mask                                      (0x04000000)
#define  PIF_MLVDS_CTRL2_fw_merge_tcon_en_mask                                   (0x01000000)
#define  PIF_MLVDS_CTRL2_p3_tcon_en_mask                                         (0x00800000)
#define  PIF_MLVDS_CTRL2_p3_tcon_sel_mask                                        (0x001F0000)
#define  PIF_MLVDS_CTRL2_p2_tcon_en_mask                                         (0x00008000)
#define  PIF_MLVDS_CTRL2_p2_tcon_sel_mask                                        (0x00001F00)
#define  PIF_MLVDS_CTRL2_p1_tcon_en_mask                                         (0x00000080)
#define  PIF_MLVDS_CTRL2_p1_tcon_sel_mask                                        (0x0000001F)
#define  PIF_MLVDS_CTRL2_mlvds_rst_low_region(data)                              (0x80000000&((data)<<31))
#define  PIF_MLVDS_CTRL2_dummy_29_28(data)                                       (0x30000000&((data)<<28))
#define  PIF_MLVDS_CTRL2_mlvds_2ck_inv(data)                                     (0x08000000&((data)<<27))
#define  PIF_MLVDS_CTRL2_mlvds_1ck_inv(data)                                     (0x04000000&((data)<<26))
#define  PIF_MLVDS_CTRL2_fw_merge_tcon_en(data)                                  (0x01000000&((data)<<24))
#define  PIF_MLVDS_CTRL2_p3_tcon_en(data)                                        (0x00800000&((data)<<23))
#define  PIF_MLVDS_CTRL2_p3_tcon_sel(data)                                       (0x001F0000&((data)<<16))
#define  PIF_MLVDS_CTRL2_p2_tcon_en(data)                                        (0x00008000&((data)<<15))
#define  PIF_MLVDS_CTRL2_p2_tcon_sel(data)                                       (0x00001F00&((data)<<8))
#define  PIF_MLVDS_CTRL2_p1_tcon_en(data)                                        (0x00000080&((data)<<7))
#define  PIF_MLVDS_CTRL2_p1_tcon_sel(data)                                       (0x0000001F&(data))
#define  PIF_MLVDS_CTRL2_get_mlvds_rst_low_region(data)                          ((0x80000000&(data))>>31)
#define  PIF_MLVDS_CTRL2_get_dummy_29_28(data)                                   ((0x30000000&(data))>>28)
#define  PIF_MLVDS_CTRL2_get_mlvds_2ck_inv(data)                                 ((0x08000000&(data))>>27)
#define  PIF_MLVDS_CTRL2_get_mlvds_1ck_inv(data)                                 ((0x04000000&(data))>>26)
#define  PIF_MLVDS_CTRL2_get_fw_merge_tcon_en(data)                              ((0x01000000&(data))>>24)
#define  PIF_MLVDS_CTRL2_get_p3_tcon_en(data)                                    ((0x00800000&(data))>>23)
#define  PIF_MLVDS_CTRL2_get_p3_tcon_sel(data)                                   ((0x001F0000&(data))>>16)
#define  PIF_MLVDS_CTRL2_get_p2_tcon_en(data)                                    ((0x00008000&(data))>>15)
#define  PIF_MLVDS_CTRL2_get_p2_tcon_sel(data)                                   ((0x00001F00&(data))>>8)
#define  PIF_MLVDS_CTRL2_get_p1_tcon_en(data)                                    ((0x00000080&(data))>>7)
#define  PIF_MLVDS_CTRL2_get_p1_tcon_sel(data)                                   (0x0000001F&(data))

#define  PIF_MLVDS_CTRL3                                                         0x1802D02C
#define  PIF_MLVDS_CTRL3_reg_addr                                                "0xB802D02C"
#define  PIF_MLVDS_CTRL3_reg                                                     0xB802D02C
#define  PIF_MLVDS_CTRL3_inst_addr                                               "0x0009"
#define  set_PIF_MLVDS_CTRL3_reg(data)                                           (*((volatile unsigned int*)PIF_MLVDS_CTRL3_reg)=data)
#define  get_PIF_MLVDS_CTRL3_reg                                                 (*((volatile unsigned int*)PIF_MLVDS_CTRL3_reg))
#define  PIF_MLVDS_CTRL3_mlvds_rst_low_0_shift                                   (0)
#define  PIF_MLVDS_CTRL3_mlvds_rst_low_0_mask                                    (0xFFFFFFFF)
#define  PIF_MLVDS_CTRL3_mlvds_rst_low_0(data)                                   (0xFFFFFFFF&(data))
#define  PIF_MLVDS_CTRL3_get_mlvds_rst_low_0(data)                               (0xFFFFFFFF&(data))

#define  PIF_MLVDS_CTRL4                                                         0x1802D030
#define  PIF_MLVDS_CTRL4_reg_addr                                                "0xB802D030"
#define  PIF_MLVDS_CTRL4_reg                                                     0xB802D030
#define  PIF_MLVDS_CTRL4_inst_addr                                               "0x000A"
#define  set_PIF_MLVDS_CTRL4_reg(data)                                           (*((volatile unsigned int*)PIF_MLVDS_CTRL4_reg)=data)
#define  get_PIF_MLVDS_CTRL4_reg                                                 (*((volatile unsigned int*)PIF_MLVDS_CTRL4_reg))
#define  PIF_MLVDS_CTRL4_mlvds_rst_low_1_shift                                   (0)
#define  PIF_MLVDS_CTRL4_mlvds_rst_low_1_mask                                    (0xFFFFFFFF)
#define  PIF_MLVDS_CTRL4_mlvds_rst_low_1(data)                                   (0xFFFFFFFF&(data))
#define  PIF_MLVDS_CTRL4_get_mlvds_rst_low_1(data)                               (0xFFFFFFFF&(data))

#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl                                        0x1802D034
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg_addr                               "0xB802D034"
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg                                    0xB802D034
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_inst_addr                              "0x000B"
#define  set_PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg(data)                          (*((volatile unsigned int*)PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg)=data)
#define  get_PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg                                (*((volatile unsigned int*)PIF_MLVDS_Multi_Reset_Pulse_Ctrl_reg))
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_data_gating_mode_shift                 (31)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_adv1t_auto_n_shift                     (1)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_mlvds_reset_pulse_adv1t_shift          (0)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_data_gating_mode_mask                  (0x80000000)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_adv1t_auto_n_mask                      (0x00000002)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_mlvds_reset_pulse_adv1t_mask           (0x00000001)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_data_gating_mode(data)                 (0x80000000&((data)<<31))
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_adv1t_auto_n(data)                     (0x00000002&((data)<<1))
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_mlvds_reset_pulse_adv1t(data)          (0x00000001&(data))
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_get_data_gating_mode(data)             ((0x80000000&(data))>>31)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_get_adv1t_auto_n(data)                 ((0x00000002&(data))>>1)
#define  PIF_MLVDS_Multi_Reset_Pulse_Ctrl_get_mlvds_reset_pulse_adv1t(data)      (0x00000001&(data))

#define  PIF_Pat_det_window_H_ini_sta_width                                      0x1802D070
#define  PIF_Pat_det_window_H_ini_sta_width_reg_addr                             "0xB802D070"
#define  PIF_Pat_det_window_H_ini_sta_width_reg                                  0xB802D070
#define  PIF_Pat_det_window_H_ini_sta_width_inst_addr                            "0x000C"
#define  set_PIF_Pat_det_window_H_ini_sta_width_reg(data)                        (*((volatile unsigned int*)PIF_Pat_det_window_H_ini_sta_width_reg)=data)
#define  get_PIF_Pat_det_window_H_ini_sta_width_reg                              (*((volatile unsigned int*)PIF_Pat_det_window_H_ini_sta_width_reg))
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_h_ini_sta_shift              (16)
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_width_shift                  (0)
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_h_ini_sta_mask               (0x1FFF0000)
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_width_mask                   (0x00001FFF)
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_h_ini_sta(data)              (0x1FFF0000&((data)<<16))
#define  PIF_Pat_det_window_H_ini_sta_width_pat_det_width(data)                  (0x00001FFF&(data))
#define  PIF_Pat_det_window_H_ini_sta_width_get_pat_det_h_ini_sta(data)          ((0x1FFF0000&(data))>>16)
#define  PIF_Pat_det_window_H_ini_sta_width_get_pat_det_width(data)              (0x00001FFF&(data))

#define  PIF_Pat_det_window_V_ini_sta_height                                     0x1802D074
#define  PIF_Pat_det_window_V_ini_sta_height_reg_addr                            "0xB802D074"
#define  PIF_Pat_det_window_V_ini_sta_height_reg                                 0xB802D074
#define  PIF_Pat_det_window_V_ini_sta_height_inst_addr                           "0x000D"
#define  set_PIF_Pat_det_window_V_ini_sta_height_reg(data)                       (*((volatile unsigned int*)PIF_Pat_det_window_V_ini_sta_height_reg)=data)
#define  get_PIF_Pat_det_window_V_ini_sta_height_reg                             (*((volatile unsigned int*)PIF_Pat_det_window_V_ini_sta_height_reg))
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_v_ini_sta_shift             (16)
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_height_shift                (0)
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_v_ini_sta_mask              (0x0FFF0000)
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_height_mask                 (0x00000FFF)
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_v_ini_sta(data)             (0x0FFF0000&((data)<<16))
#define  PIF_Pat_det_window_V_ini_sta_height_pat_det_height(data)                (0x00000FFF&(data))
#define  PIF_Pat_det_window_V_ini_sta_height_get_pat_det_v_ini_sta(data)         ((0x0FFF0000&(data))>>16)
#define  PIF_Pat_det_window_V_ini_sta_height_get_pat_det_height(data)            (0x00000FFF&(data))

#define  PIF_Pattern_detect_CTRL                                                 0x1802D078
#define  PIF_Pattern_detect_CTRL_reg_addr                                        "0xB802D078"
#define  PIF_Pattern_detect_CTRL_reg                                             0xB802D078
#define  PIF_Pattern_detect_CTRL_inst_addr                                       "0x000E"
#define  set_PIF_Pattern_detect_CTRL_reg(data)                                   (*((volatile unsigned int*)PIF_Pattern_detect_CTRL_reg)=data)
#define  get_PIF_Pattern_detect_CTRL_reg                                         (*((volatile unsigned int*)PIF_Pattern_detect_CTRL_reg))
#define  PIF_Pattern_detect_CTRL_spc_pt_1_shift                                  (23)
#define  PIF_Pattern_detect_CTRL_spc_pt_2_shift                                  (22)
#define  PIF_Pattern_detect_CTRL_spc_pt_3_shift                                  (21)
#define  PIF_Pattern_detect_CTRL_spc_pt_4_shift                                  (20)
#define  PIF_Pattern_detect_CTRL_spc_pt_5_shift                                  (19)
#define  PIF_Pattern_detect_CTRL_spc_pt_6_shift                                  (18)
#define  PIF_Pattern_detect_CTRL_spc_pt_7_shift                                  (17)
#define  PIF_Pattern_detect_CTRL_spc_pt_8_shift                                  (16)
#define  PIF_Pattern_detect_CTRL_spc_pt_9_shift                                  (15)
#define  PIF_Pattern_detect_CTRL_spc_pt_10_shift                                 (14)
#define  PIF_Pattern_detect_CTRL_spc_pt_11_shift                                 (13)
#define  PIF_Pattern_detect_CTRL_spc_pt_12_shift                                 (12)
#define  PIF_Pattern_detect_CTRL_spc_pt_13_shift                                 (11)
#define  PIF_Pattern_detect_CTRL_spc_pt_14_shift                                 (10)
#define  PIF_Pattern_detect_CTRL_spc_pt_15_shift                                 (9)
#define  PIF_Pattern_detect_CTRL_spc_pt_16_shift                                 (8)
#define  PIF_Pattern_detect_CTRL_pat_det_en_shift                                (1)
#define  PIF_Pattern_detect_CTRL_pat_det_auto_shift                              (0)
#define  PIF_Pattern_detect_CTRL_spc_pt_1_mask                                   (0x00800000)
#define  PIF_Pattern_detect_CTRL_spc_pt_2_mask                                   (0x00400000)
#define  PIF_Pattern_detect_CTRL_spc_pt_3_mask                                   (0x00200000)
#define  PIF_Pattern_detect_CTRL_spc_pt_4_mask                                   (0x00100000)
#define  PIF_Pattern_detect_CTRL_spc_pt_5_mask                                   (0x00080000)
#define  PIF_Pattern_detect_CTRL_spc_pt_6_mask                                   (0x00040000)
#define  PIF_Pattern_detect_CTRL_spc_pt_7_mask                                   (0x00020000)
#define  PIF_Pattern_detect_CTRL_spc_pt_8_mask                                   (0x00010000)
#define  PIF_Pattern_detect_CTRL_spc_pt_9_mask                                   (0x00008000)
#define  PIF_Pattern_detect_CTRL_spc_pt_10_mask                                  (0x00004000)
#define  PIF_Pattern_detect_CTRL_spc_pt_11_mask                                  (0x00002000)
#define  PIF_Pattern_detect_CTRL_spc_pt_12_mask                                  (0x00001000)
#define  PIF_Pattern_detect_CTRL_spc_pt_13_mask                                  (0x00000800)
#define  PIF_Pattern_detect_CTRL_spc_pt_14_mask                                  (0x00000400)
#define  PIF_Pattern_detect_CTRL_spc_pt_15_mask                                  (0x00000200)
#define  PIF_Pattern_detect_CTRL_spc_pt_16_mask                                  (0x00000100)
#define  PIF_Pattern_detect_CTRL_pat_det_en_mask                                 (0x00000002)
#define  PIF_Pattern_detect_CTRL_pat_det_auto_mask                               (0x00000001)
#define  PIF_Pattern_detect_CTRL_spc_pt_1(data)                                  (0x00800000&((data)<<23))
#define  PIF_Pattern_detect_CTRL_spc_pt_2(data)                                  (0x00400000&((data)<<22))
#define  PIF_Pattern_detect_CTRL_spc_pt_3(data)                                  (0x00200000&((data)<<21))
#define  PIF_Pattern_detect_CTRL_spc_pt_4(data)                                  (0x00100000&((data)<<20))
#define  PIF_Pattern_detect_CTRL_spc_pt_5(data)                                  (0x00080000&((data)<<19))
#define  PIF_Pattern_detect_CTRL_spc_pt_6(data)                                  (0x00040000&((data)<<18))
#define  PIF_Pattern_detect_CTRL_spc_pt_7(data)                                  (0x00020000&((data)<<17))
#define  PIF_Pattern_detect_CTRL_spc_pt_8(data)                                  (0x00010000&((data)<<16))
#define  PIF_Pattern_detect_CTRL_spc_pt_9(data)                                  (0x00008000&((data)<<15))
#define  PIF_Pattern_detect_CTRL_spc_pt_10(data)                                 (0x00004000&((data)<<14))
#define  PIF_Pattern_detect_CTRL_spc_pt_11(data)                                 (0x00002000&((data)<<13))
#define  PIF_Pattern_detect_CTRL_spc_pt_12(data)                                 (0x00001000&((data)<<12))
#define  PIF_Pattern_detect_CTRL_spc_pt_13(data)                                 (0x00000800&((data)<<11))
#define  PIF_Pattern_detect_CTRL_spc_pt_14(data)                                 (0x00000400&((data)<<10))
#define  PIF_Pattern_detect_CTRL_spc_pt_15(data)                                 (0x00000200&((data)<<9))
#define  PIF_Pattern_detect_CTRL_spc_pt_16(data)                                 (0x00000100&((data)<<8))
#define  PIF_Pattern_detect_CTRL_pat_det_en(data)                                (0x00000002&((data)<<1))
#define  PIF_Pattern_detect_CTRL_pat_det_auto(data)                              (0x00000001&(data))
#define  PIF_Pattern_detect_CTRL_get_spc_pt_1(data)                              ((0x00800000&(data))>>23)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_2(data)                              ((0x00400000&(data))>>22)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_3(data)                              ((0x00200000&(data))>>21)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_4(data)                              ((0x00100000&(data))>>20)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_5(data)                              ((0x00080000&(data))>>19)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_6(data)                              ((0x00040000&(data))>>18)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_7(data)                              ((0x00020000&(data))>>17)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_8(data)                              ((0x00010000&(data))>>16)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_9(data)                              ((0x00008000&(data))>>15)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_10(data)                             ((0x00004000&(data))>>14)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_11(data)                             ((0x00002000&(data))>>13)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_12(data)                             ((0x00001000&(data))>>12)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_13(data)                             ((0x00000800&(data))>>11)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_14(data)                             ((0x00000400&(data))>>10)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_15(data)                             ((0x00000200&(data))>>9)
#define  PIF_Pattern_detect_CTRL_get_spc_pt_16(data)                             ((0x00000100&(data))>>8)
#define  PIF_Pattern_detect_CTRL_get_pat_det_en(data)                            ((0x00000002&(data))>>1)
#define  PIF_Pattern_detect_CTRL_get_pat_det_auto(data)                          (0x00000001&(data))

#define  PIF_pat_det_sum1                                                        0x1802D080
#define  PIF_pat_det_sum1_reg_addr                                               "0xB802D080"
#define  PIF_pat_det_sum1_reg                                                    0xB802D080
#define  PIF_pat_det_sum1_inst_addr                                              "0x000F"
#define  set_PIF_pat_det_sum1_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum1_reg)=data)
#define  get_PIF_pat_det_sum1_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum1_reg))
#define  PIF_pat_det_sum1_sum_line_1_shift                                       (0)
#define  PIF_pat_det_sum1_sum_line_1_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum1_sum_line_1(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum1_get_sum_line_1(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum2                                                        0x1802D084
#define  PIF_pat_det_sum2_reg_addr                                               "0xB802D084"
#define  PIF_pat_det_sum2_reg                                                    0xB802D084
#define  PIF_pat_det_sum2_inst_addr                                              "0x0010"
#define  set_PIF_pat_det_sum2_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum2_reg)=data)
#define  get_PIF_pat_det_sum2_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum2_reg))
#define  PIF_pat_det_sum2_sum_line_2_shift                                       (0)
#define  PIF_pat_det_sum2_sum_line_2_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum2_sum_line_2(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum2_get_sum_line_2(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum3                                                        0x1802D088
#define  PIF_pat_det_sum3_reg_addr                                               "0xB802D088"
#define  PIF_pat_det_sum3_reg                                                    0xB802D088
#define  PIF_pat_det_sum3_inst_addr                                              "0x0011"
#define  set_PIF_pat_det_sum3_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum3_reg)=data)
#define  get_PIF_pat_det_sum3_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum3_reg))
#define  PIF_pat_det_sum3_sum_line_3_shift                                       (0)
#define  PIF_pat_det_sum3_sum_line_3_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum3_sum_line_3(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum3_get_sum_line_3(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum4                                                        0x1802D08C
#define  PIF_pat_det_sum4_reg_addr                                               "0xB802D08C"
#define  PIF_pat_det_sum4_reg                                                    0xB802D08C
#define  PIF_pat_det_sum4_inst_addr                                              "0x0012"
#define  set_PIF_pat_det_sum4_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum4_reg)=data)
#define  get_PIF_pat_det_sum4_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum4_reg))
#define  PIF_pat_det_sum4_sum_line_4_shift                                       (0)
#define  PIF_pat_det_sum4_sum_line_4_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum4_sum_line_4(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum4_get_sum_line_4(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum5                                                        0x1802D090
#define  PIF_pat_det_sum5_reg_addr                                               "0xB802D090"
#define  PIF_pat_det_sum5_reg                                                    0xB802D090
#define  PIF_pat_det_sum5_inst_addr                                              "0x0013"
#define  set_PIF_pat_det_sum5_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum5_reg)=data)
#define  get_PIF_pat_det_sum5_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum5_reg))
#define  PIF_pat_det_sum5_sum_line_5_shift                                       (0)
#define  PIF_pat_det_sum5_sum_line_5_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum5_sum_line_5(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum5_get_sum_line_5(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum6                                                        0x1802D094
#define  PIF_pat_det_sum6_reg_addr                                               "0xB802D094"
#define  PIF_pat_det_sum6_reg                                                    0xB802D094
#define  PIF_pat_det_sum6_inst_addr                                              "0x0014"
#define  set_PIF_pat_det_sum6_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum6_reg)=data)
#define  get_PIF_pat_det_sum6_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum6_reg))
#define  PIF_pat_det_sum6_sum_line_6_shift                                       (0)
#define  PIF_pat_det_sum6_sum_line_6_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum6_sum_line_6(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum6_get_sum_line_6(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum7                                                        0x1802D098
#define  PIF_pat_det_sum7_reg_addr                                               "0xB802D098"
#define  PIF_pat_det_sum7_reg                                                    0xB802D098
#define  PIF_pat_det_sum7_inst_addr                                              "0x0015"
#define  set_PIF_pat_det_sum7_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum7_reg)=data)
#define  get_PIF_pat_det_sum7_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum7_reg))
#define  PIF_pat_det_sum7_sum_line_7_shift                                       (0)
#define  PIF_pat_det_sum7_sum_line_7_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum7_sum_line_7(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum7_get_sum_line_7(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum8                                                        0x1802D09C
#define  PIF_pat_det_sum8_reg_addr                                               "0xB802D09C"
#define  PIF_pat_det_sum8_reg                                                    0xB802D09C
#define  PIF_pat_det_sum8_inst_addr                                              "0x0016"
#define  set_PIF_pat_det_sum8_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum8_reg)=data)
#define  get_PIF_pat_det_sum8_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum8_reg))
#define  PIF_pat_det_sum8_sum_line_8_shift                                       (0)
#define  PIF_pat_det_sum8_sum_line_8_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum8_sum_line_8(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum8_get_sum_line_8(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum9                                                        0x1802D0A0
#define  PIF_pat_det_sum9_reg_addr                                               "0xB802D0A0"
#define  PIF_pat_det_sum9_reg                                                    0xB802D0A0
#define  PIF_pat_det_sum9_inst_addr                                              "0x0017"
#define  set_PIF_pat_det_sum9_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_sum9_reg)=data)
#define  get_PIF_pat_det_sum9_reg                                                (*((volatile unsigned int*)PIF_pat_det_sum9_reg))
#define  PIF_pat_det_sum9_sum_line_9_shift                                       (0)
#define  PIF_pat_det_sum9_sum_line_9_mask                                        (0xFFFFFFFF)
#define  PIF_pat_det_sum9_sum_line_9(data)                                       (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum9_get_sum_line_9(data)                                   (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum10                                                       0x1802D0A4
#define  PIF_pat_det_sum10_reg_addr                                              "0xB802D0A4"
#define  PIF_pat_det_sum10_reg                                                   0xB802D0A4
#define  PIF_pat_det_sum10_inst_addr                                             "0x0018"
#define  set_PIF_pat_det_sum10_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum10_reg)=data)
#define  get_PIF_pat_det_sum10_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum10_reg))
#define  PIF_pat_det_sum10_sum_line_10_shift                                     (0)
#define  PIF_pat_det_sum10_sum_line_10_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum10_sum_line_10(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum10_get_sum_line_10(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum11                                                       0x1802D0A8
#define  PIF_pat_det_sum11_reg_addr                                              "0xB802D0A8"
#define  PIF_pat_det_sum11_reg                                                   0xB802D0A8
#define  PIF_pat_det_sum11_inst_addr                                             "0x0019"
#define  set_PIF_pat_det_sum11_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum11_reg)=data)
#define  get_PIF_pat_det_sum11_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum11_reg))
#define  PIF_pat_det_sum11_sum_line_11_shift                                     (0)
#define  PIF_pat_det_sum11_sum_line_11_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum11_sum_line_11(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum11_get_sum_line_11(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum12                                                       0x1802D0AC
#define  PIF_pat_det_sum12_reg_addr                                              "0xB802D0AC"
#define  PIF_pat_det_sum12_reg                                                   0xB802D0AC
#define  PIF_pat_det_sum12_inst_addr                                             "0x001A"
#define  set_PIF_pat_det_sum12_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum12_reg)=data)
#define  get_PIF_pat_det_sum12_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum12_reg))
#define  PIF_pat_det_sum12_sum_line_12_shift                                     (0)
#define  PIF_pat_det_sum12_sum_line_12_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum12_sum_line_12(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum12_get_sum_line_12(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum13                                                       0x1802D0B0
#define  PIF_pat_det_sum13_reg_addr                                              "0xB802D0B0"
#define  PIF_pat_det_sum13_reg                                                   0xB802D0B0
#define  PIF_pat_det_sum13_inst_addr                                             "0x001B"
#define  set_PIF_pat_det_sum13_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum13_reg)=data)
#define  get_PIF_pat_det_sum13_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum13_reg))
#define  PIF_pat_det_sum13_sum_line_13_shift                                     (0)
#define  PIF_pat_det_sum13_sum_line_13_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum13_sum_line_13(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum13_get_sum_line_13(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum14                                                       0x1802D0B4
#define  PIF_pat_det_sum14_reg_addr                                              "0xB802D0B4"
#define  PIF_pat_det_sum14_reg                                                   0xB802D0B4
#define  PIF_pat_det_sum14_inst_addr                                             "0x001C"
#define  set_PIF_pat_det_sum14_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum14_reg)=data)
#define  get_PIF_pat_det_sum14_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum14_reg))
#define  PIF_pat_det_sum14_sum_line_14_shift                                     (0)
#define  PIF_pat_det_sum14_sum_line_14_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum14_sum_line_14(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum14_get_sum_line_14(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum15                                                       0x1802D0B8
#define  PIF_pat_det_sum15_reg_addr                                              "0xB802D0B8"
#define  PIF_pat_det_sum15_reg                                                   0xB802D0B8
#define  PIF_pat_det_sum15_inst_addr                                             "0x001D"
#define  set_PIF_pat_det_sum15_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum15_reg)=data)
#define  get_PIF_pat_det_sum15_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum15_reg))
#define  PIF_pat_det_sum15_sum_line_15_shift                                     (0)
#define  PIF_pat_det_sum15_sum_line_15_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum15_sum_line_15(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum15_get_sum_line_15(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_sum16                                                       0x1802D0BC
#define  PIF_pat_det_sum16_reg_addr                                              "0xB802D0BC"
#define  PIF_pat_det_sum16_reg                                                   0xB802D0BC
#define  PIF_pat_det_sum16_inst_addr                                             "0x001E"
#define  set_PIF_pat_det_sum16_reg(data)                                         (*((volatile unsigned int*)PIF_pat_det_sum16_reg)=data)
#define  get_PIF_pat_det_sum16_reg                                               (*((volatile unsigned int*)PIF_pat_det_sum16_reg))
#define  PIF_pat_det_sum16_sum_line_16_shift                                     (0)
#define  PIF_pat_det_sum16_sum_line_16_mask                                      (0xFFFFFFFF)
#define  PIF_pat_det_sum16_sum_line_16(data)                                     (0xFFFFFFFF&(data))
#define  PIF_pat_det_sum16_get_sum_line_16(data)                                 (0xFFFFFFFF&(data))

#define  PIF_pat_det_th1                                                         0x1802D0C0
#define  PIF_pat_det_th1_reg_addr                                                "0xB802D0C0"
#define  PIF_pat_det_th1_reg                                                     0xB802D0C0
#define  PIF_pat_det_th1_inst_addr                                               "0x001F"
#define  set_PIF_pat_det_th1_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th1_reg)=data)
#define  get_PIF_pat_det_th1_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th1_reg))
#define  PIF_pat_det_th1_pat_th1_shift                                           (0)
#define  PIF_pat_det_th1_pat_th1_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th1_pat_th1(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th1_get_pat_th1(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th2                                                         0x1802D0C4
#define  PIF_pat_det_th2_reg_addr                                                "0xB802D0C4"
#define  PIF_pat_det_th2_reg                                                     0xB802D0C4
#define  PIF_pat_det_th2_inst_addr                                               "0x0020"
#define  set_PIF_pat_det_th2_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th2_reg)=data)
#define  get_PIF_pat_det_th2_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th2_reg))
#define  PIF_pat_det_th2_pat_th2_shift                                           (0)
#define  PIF_pat_det_th2_pat_th2_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th2_pat_th2(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th2_get_pat_th2(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th3                                                         0x1802D0C8
#define  PIF_pat_det_th3_reg_addr                                                "0xB802D0C8"
#define  PIF_pat_det_th3_reg                                                     0xB802D0C8
#define  PIF_pat_det_th3_inst_addr                                               "0x0021"
#define  set_PIF_pat_det_th3_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th3_reg)=data)
#define  get_PIF_pat_det_th3_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th3_reg))
#define  PIF_pat_det_th3_pat_th3_shift                                           (0)
#define  PIF_pat_det_th3_pat_th3_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th3_pat_th3(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th3_get_pat_th3(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th4                                                         0x1802D0CC
#define  PIF_pat_det_th4_reg_addr                                                "0xB802D0CC"
#define  PIF_pat_det_th4_reg                                                     0xB802D0CC
#define  PIF_pat_det_th4_inst_addr                                               "0x0022"
#define  set_PIF_pat_det_th4_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th4_reg)=data)
#define  get_PIF_pat_det_th4_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th4_reg))
#define  PIF_pat_det_th4_pat_th4_shift                                           (0)
#define  PIF_pat_det_th4_pat_th4_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th4_pat_th4(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th4_get_pat_th4(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th5                                                         0x1802D0D0
#define  PIF_pat_det_th5_reg_addr                                                "0xB802D0D0"
#define  PIF_pat_det_th5_reg                                                     0xB802D0D0
#define  PIF_pat_det_th5_inst_addr                                               "0x0023"
#define  set_PIF_pat_det_th5_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th5_reg)=data)
#define  get_PIF_pat_det_th5_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th5_reg))
#define  PIF_pat_det_th5_pat_th5_shift                                           (0)
#define  PIF_pat_det_th5_pat_th5_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th5_pat_th5(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th5_get_pat_th5(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th6                                                         0x1802D0D4
#define  PIF_pat_det_th6_reg_addr                                                "0xB802D0D4"
#define  PIF_pat_det_th6_reg                                                     0xB802D0D4
#define  PIF_pat_det_th6_inst_addr                                               "0x0024"
#define  set_PIF_pat_det_th6_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th6_reg)=data)
#define  get_PIF_pat_det_th6_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th6_reg))
#define  PIF_pat_det_th6_pat_th6_shift                                           (0)
#define  PIF_pat_det_th6_pat_th6_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th6_pat_th6(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th6_get_pat_th6(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th7                                                         0x1802D0D8
#define  PIF_pat_det_th7_reg_addr                                                "0xB802D0D8"
#define  PIF_pat_det_th7_reg                                                     0xB802D0D8
#define  PIF_pat_det_th7_inst_addr                                               "0x0025"
#define  set_PIF_pat_det_th7_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th7_reg)=data)
#define  get_PIF_pat_det_th7_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th7_reg))
#define  PIF_pat_det_th7_pat_th7_shift                                           (0)
#define  PIF_pat_det_th7_pat_th7_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th7_pat_th7(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th7_get_pat_th7(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th8                                                         0x1802D0DC
#define  PIF_pat_det_th8_reg_addr                                                "0xB802D0DC"
#define  PIF_pat_det_th8_reg                                                     0xB802D0DC
#define  PIF_pat_det_th8_inst_addr                                               "0x0026"
#define  set_PIF_pat_det_th8_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th8_reg)=data)
#define  get_PIF_pat_det_th8_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th8_reg))
#define  PIF_pat_det_th8_pat_th8_shift                                           (0)
#define  PIF_pat_det_th8_pat_th8_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th8_pat_th8(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th8_get_pat_th8(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th9                                                         0x1802D0E0
#define  PIF_pat_det_th9_reg_addr                                                "0xB802D0E0"
#define  PIF_pat_det_th9_reg                                                     0xB802D0E0
#define  PIF_pat_det_th9_inst_addr                                               "0x0027"
#define  set_PIF_pat_det_th9_reg(data)                                           (*((volatile unsigned int*)PIF_pat_det_th9_reg)=data)
#define  get_PIF_pat_det_th9_reg                                                 (*((volatile unsigned int*)PIF_pat_det_th9_reg))
#define  PIF_pat_det_th9_pat_th9_shift                                           (0)
#define  PIF_pat_det_th9_pat_th9_mask                                            (0xFFFFFFFF)
#define  PIF_pat_det_th9_pat_th9(data)                                           (0xFFFFFFFF&(data))
#define  PIF_pat_det_th9_get_pat_th9(data)                                       (0xFFFFFFFF&(data))

#define  PIF_pat_det_th10                                                        0x1802D0E4
#define  PIF_pat_det_th10_reg_addr                                               "0xB802D0E4"
#define  PIF_pat_det_th10_reg                                                    0xB802D0E4
#define  PIF_pat_det_th10_inst_addr                                              "0x0028"
#define  set_PIF_pat_det_th10_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th10_reg)=data)
#define  get_PIF_pat_det_th10_reg                                                (*((volatile unsigned int*)PIF_pat_det_th10_reg))
#define  PIF_pat_det_th10_pat_th10_shift                                         (0)
#define  PIF_pat_det_th10_pat_th10_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th10_pat_th10(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th10_get_pat_th10(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th11                                                        0x1802D0E8
#define  PIF_pat_det_th11_reg_addr                                               "0xB802D0E8"
#define  PIF_pat_det_th11_reg                                                    0xB802D0E8
#define  PIF_pat_det_th11_inst_addr                                              "0x0029"
#define  set_PIF_pat_det_th11_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th11_reg)=data)
#define  get_PIF_pat_det_th11_reg                                                (*((volatile unsigned int*)PIF_pat_det_th11_reg))
#define  PIF_pat_det_th11_pat_th11_shift                                         (0)
#define  PIF_pat_det_th11_pat_th11_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th11_pat_th11(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th11_get_pat_th11(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th12                                                        0x1802D0EC
#define  PIF_pat_det_th12_reg_addr                                               "0xB802D0EC"
#define  PIF_pat_det_th12_reg                                                    0xB802D0EC
#define  PIF_pat_det_th12_inst_addr                                              "0x002A"
#define  set_PIF_pat_det_th12_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th12_reg)=data)
#define  get_PIF_pat_det_th12_reg                                                (*((volatile unsigned int*)PIF_pat_det_th12_reg))
#define  PIF_pat_det_th12_pat_th12_shift                                         (0)
#define  PIF_pat_det_th12_pat_th12_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th12_pat_th12(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th12_get_pat_th12(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th13                                                        0x1802D0F0
#define  PIF_pat_det_th13_reg_addr                                               "0xB802D0F0"
#define  PIF_pat_det_th13_reg                                                    0xB802D0F0
#define  PIF_pat_det_th13_inst_addr                                              "0x002B"
#define  set_PIF_pat_det_th13_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th13_reg)=data)
#define  get_PIF_pat_det_th13_reg                                                (*((volatile unsigned int*)PIF_pat_det_th13_reg))
#define  PIF_pat_det_th13_pat_th13_shift                                         (0)
#define  PIF_pat_det_th13_pat_th13_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th13_pat_th13(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th13_get_pat_th13(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th14                                                        0x1802D0F4
#define  PIF_pat_det_th14_reg_addr                                               "0xB802D0F4"
#define  PIF_pat_det_th14_reg                                                    0xB802D0F4
#define  PIF_pat_det_th14_inst_addr                                              "0x002C"
#define  set_PIF_pat_det_th14_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th14_reg)=data)
#define  get_PIF_pat_det_th14_reg                                                (*((volatile unsigned int*)PIF_pat_det_th14_reg))
#define  PIF_pat_det_th14_pat_th14_shift                                         (0)
#define  PIF_pat_det_th14_pat_th14_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th14_pat_th14(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th14_get_pat_th14(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th15                                                        0x1802D0F8
#define  PIF_pat_det_th15_reg_addr                                               "0xB802D0F8"
#define  PIF_pat_det_th15_reg                                                    0xB802D0F8
#define  PIF_pat_det_th15_inst_addr                                              "0x002D"
#define  set_PIF_pat_det_th15_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th15_reg)=data)
#define  get_PIF_pat_det_th15_reg                                                (*((volatile unsigned int*)PIF_pat_det_th15_reg))
#define  PIF_pat_det_th15_pat_th15_shift                                         (0)
#define  PIF_pat_det_th15_pat_th15_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th15_pat_th15(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th15_get_pat_th15(data)                                     (0xFFFFFFFF&(data))

#define  PIF_pat_det_th16                                                        0x1802D0FC
#define  PIF_pat_det_th16_reg_addr                                               "0xB802D0FC"
#define  PIF_pat_det_th16_reg                                                    0xB802D0FC
#define  PIF_pat_det_th16_inst_addr                                              "0x002E"
#define  set_PIF_pat_det_th16_reg(data)                                          (*((volatile unsigned int*)PIF_pat_det_th16_reg)=data)
#define  get_PIF_pat_det_th16_reg                                                (*((volatile unsigned int*)PIF_pat_det_th16_reg))
#define  PIF_pat_det_th16_pat_th16_shift                                         (0)
#define  PIF_pat_det_th16_pat_th16_mask                                          (0xFFFFFFFF)
#define  PIF_pat_det_th16_pat_th16(data)                                         (0xFFFFFFFF&(data))
#define  PIF_pat_det_th16_get_pat_th16(data)                                     (0xFFFFFFFF&(data))

#define  PIF_LVDS_pair_select_ctrl_0                                             0x1802D100
#define  PIF_LVDS_pair_select_ctrl_0_reg_addr                                    "0xB802D100"
#define  PIF_LVDS_pair_select_ctrl_0_reg                                         0xB802D100
#define  PIF_LVDS_pair_select_ctrl_0_inst_addr                                   "0x002F"
#define  set_PIF_LVDS_pair_select_ctrl_0_reg(data)                               (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_0_reg)=data)
#define  get_PIF_LVDS_pair_select_ctrl_0_reg                                     (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_0_reg))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_a_pair_sel_shift                     (28)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_b_pair_sel_shift                     (24)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_c_pair_sel_shift                     (20)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_d_pair_sel_shift                     (16)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_e_pair_sel_shift                     (12)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_f_pair_sel_shift                     (8)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_a_pair_sel_shift                     (4)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_b_pair_sel_shift                     (0)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_a_pair_sel_mask                      (0xF0000000)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_b_pair_sel_mask                      (0x0F000000)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_c_pair_sel_mask                      (0x00F00000)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_d_pair_sel_mask                      (0x000F0000)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_e_pair_sel_mask                      (0x0000F000)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_f_pair_sel_mask                      (0x00000F00)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_a_pair_sel_mask                      (0x000000F0)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_b_pair_sel_mask                      (0x0000000F)
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_a_pair_sel(data)                     (0xF0000000&((data)<<28))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_b_pair_sel(data)                     (0x0F000000&((data)<<24))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_c_pair_sel(data)                     (0x00F00000&((data)<<20))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_d_pair_sel(data)                     (0x000F0000&((data)<<16))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_e_pair_sel(data)                     (0x0000F000&((data)<<12))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_a_f_pair_sel(data)                     (0x00000F00&((data)<<8))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_a_pair_sel(data)                     (0x000000F0&((data)<<4))
#define  PIF_LVDS_pair_select_ctrl_0_lvds_b_b_pair_sel(data)                     (0x0000000F&(data))
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_a_pair_sel(data)                 ((0xF0000000&(data))>>28)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_b_pair_sel(data)                 ((0x0F000000&(data))>>24)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_c_pair_sel(data)                 ((0x00F00000&(data))>>20)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_d_pair_sel(data)                 ((0x000F0000&(data))>>16)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_e_pair_sel(data)                 ((0x0000F000&(data))>>12)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_a_f_pair_sel(data)                 ((0x00000F00&(data))>>8)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_b_a_pair_sel(data)                 ((0x000000F0&(data))>>4)
#define  PIF_LVDS_pair_select_ctrl_0_get_lvds_b_b_pair_sel(data)                 (0x0000000F&(data))

#define  PIF_LVDS_pair_select_ctrl_1                                             0x1802D104
#define  PIF_LVDS_pair_select_ctrl_1_reg_addr                                    "0xB802D104"
#define  PIF_LVDS_pair_select_ctrl_1_reg                                         0xB802D104
#define  PIF_LVDS_pair_select_ctrl_1_inst_addr                                   "0x0030"
#define  set_PIF_LVDS_pair_select_ctrl_1_reg(data)                               (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_1_reg)=data)
#define  get_PIF_LVDS_pair_select_ctrl_1_reg                                     (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_1_reg))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_c_pair_sel_shift                     (28)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_d_pair_sel_shift                     (24)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_e_pair_sel_shift                     (20)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_f_pair_sel_shift                     (16)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_a_pair_sel_shift                     (12)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_b_pair_sel_shift                     (8)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_c_pair_sel_shift                     (4)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_d_pair_sel_shift                     (0)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_c_pair_sel_mask                      (0xF0000000)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_d_pair_sel_mask                      (0x0F000000)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_e_pair_sel_mask                      (0x00F00000)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_f_pair_sel_mask                      (0x000F0000)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_a_pair_sel_mask                      (0x0000F000)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_b_pair_sel_mask                      (0x00000F00)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_c_pair_sel_mask                      (0x000000F0)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_d_pair_sel_mask                      (0x0000000F)
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_c_pair_sel(data)                     (0xF0000000&((data)<<28))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_d_pair_sel(data)                     (0x0F000000&((data)<<24))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_e_pair_sel(data)                     (0x00F00000&((data)<<20))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_b_f_pair_sel(data)                     (0x000F0000&((data)<<16))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_a_pair_sel(data)                     (0x0000F000&((data)<<12))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_b_pair_sel(data)                     (0x00000F00&((data)<<8))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_c_pair_sel(data)                     (0x000000F0&((data)<<4))
#define  PIF_LVDS_pair_select_ctrl_1_lvds_c_d_pair_sel(data)                     (0x0000000F&(data))
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_b_c_pair_sel(data)                 ((0xF0000000&(data))>>28)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_b_d_pair_sel(data)                 ((0x0F000000&(data))>>24)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_b_e_pair_sel(data)                 ((0x00F00000&(data))>>20)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_b_f_pair_sel(data)                 ((0x000F0000&(data))>>16)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_c_a_pair_sel(data)                 ((0x0000F000&(data))>>12)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_c_b_pair_sel(data)                 ((0x00000F00&(data))>>8)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_c_c_pair_sel(data)                 ((0x000000F0&(data))>>4)
#define  PIF_LVDS_pair_select_ctrl_1_get_lvds_c_d_pair_sel(data)                 (0x0000000F&(data))

#define  PIF_LVDS_pair_select_ctrl_2                                             0x1802D108
#define  PIF_LVDS_pair_select_ctrl_2_reg_addr                                    "0xB802D108"
#define  PIF_LVDS_pair_select_ctrl_2_reg                                         0xB802D108
#define  PIF_LVDS_pair_select_ctrl_2_inst_addr                                   "0x0031"
#define  set_PIF_LVDS_pair_select_ctrl_2_reg(data)                               (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_2_reg)=data)
#define  get_PIF_LVDS_pair_select_ctrl_2_reg                                     (*((volatile unsigned int*)PIF_LVDS_pair_select_ctrl_2_reg))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_e_pair_sel_shift                     (28)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_f_pair_sel_shift                     (24)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_a_pair_sel_shift                     (20)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_b_pair_sel_shift                     (16)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_c_pair_sel_shift                     (12)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_d_pair_sel_shift                     (8)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_e_pair_sel_shift                     (4)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_f_pair_sel_shift                     (0)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_e_pair_sel_mask                      (0xF0000000)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_f_pair_sel_mask                      (0x0F000000)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_a_pair_sel_mask                      (0x00F00000)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_b_pair_sel_mask                      (0x000F0000)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_c_pair_sel_mask                      (0x0000F000)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_d_pair_sel_mask                      (0x00000F00)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_e_pair_sel_mask                      (0x000000F0)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_f_pair_sel_mask                      (0x0000000F)
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_e_pair_sel(data)                     (0xF0000000&((data)<<28))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_c_f_pair_sel(data)                     (0x0F000000&((data)<<24))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_a_pair_sel(data)                     (0x00F00000&((data)<<20))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_b_pair_sel(data)                     (0x000F0000&((data)<<16))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_c_pair_sel(data)                     (0x0000F000&((data)<<12))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_d_pair_sel(data)                     (0x00000F00&((data)<<8))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_e_pair_sel(data)                     (0x000000F0&((data)<<4))
#define  PIF_LVDS_pair_select_ctrl_2_lvds_d_f_pair_sel(data)                     (0x0000000F&(data))
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_c_e_pair_sel(data)                 ((0xF0000000&(data))>>28)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_c_f_pair_sel(data)                 ((0x0F000000&(data))>>24)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_a_pair_sel(data)                 ((0x00F00000&(data))>>20)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_b_pair_sel(data)                 ((0x000F0000&(data))>>16)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_c_pair_sel(data)                 ((0x0000F000&(data))>>12)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_d_pair_sel(data)                 ((0x00000F00&(data))>>8)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_e_pair_sel(data)                 ((0x000000F0&(data))>>4)
#define  PIF_LVDS_pair_select_ctrl_2_get_lvds_d_f_pair_sel(data)                 (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PIF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pif_debug_sel:4;
        RBus_UInt32  plt_lvds_mode:2;
        RBus_UInt32  res2:2;
    };
}pif_lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d004_31_0:32;
    };
}pif_lvds_dummy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_arsv1_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  res2:1;
    };
}pif_lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_crsv1_sel:3;
        RBus_UInt32  lvds_crsv0_sel:3;
        RBus_UInt32  lvds_cden_sel:3;
        RBus_UInt32  lvds_cvs_sel:3;
        RBus_UInt32  lvds_chs_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_drsv1_sel:3;
        RBus_UInt32  lvds_drsv0_sel:3;
        RBus_UInt32  lvds_dden_sel:3;
        RBus_UInt32  lvds_dvs_sel:3;
        RBus_UInt32  lvds_dhs_sel:3;
        RBus_UInt32  res2:1;
    };
}pif_lvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  lvds_map_inv:1;
        RBus_UInt32  lvds_map:2;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  dummy1802d010_10:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  lvds_bport_en:1;
        RBus_UInt32  lvds_cport_en:1;
        RBus_UInt32  lvds_dport_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  dummy1802d010_1_0:2;
    };
}pif_lvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}pif_lvds_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d01c_31_12:20;
        RBus_UInt32  mlvds_map_type_sel:4;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  mlvds_8p_special_swap:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  dummy1802d01c_2:1;
        RBus_UInt32  mlvds_mode:2;
    };
}pif_mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d020_31_12:20;
        RBus_UInt32  mlvds_reset_pul_sel:12;
    };
}pif_mlvds_reset_pul_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tcon_sel:8;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mlvds_rst_high:5;
    };
}pif_mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_region:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1802d028_29_28:2;
        RBus_UInt32  mlvds_2ck_inv:1;
        RBus_UInt32  mlvds_1ck_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  fw_merge_tcon_en:1;
        RBus_UInt32  p3_tcon_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  p3_tcon_sel:5;
        RBus_UInt32  p2_tcon_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  p2_tcon_sel:5;
        RBus_UInt32  p1_tcon_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  p1_tcon_sel:5;
    };
}pif_mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_0:32;
    };
}pif_mlvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_1:32;
    };
}pif_mlvds_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_gating_mode:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  adv1t_auto_n:1;
        RBus_UInt32  mlvds_reset_pulse_adv1t:1;
    };
}pif_mlvds_multi_reset_pulse_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  pat_det_width:13;
    };
}pif_pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pat_det_height:12;
    };
}pif_pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_9:1;
        RBus_UInt32  spc_pt_10:1;
        RBus_UInt32  spc_pt_11:1;
        RBus_UInt32  spc_pt_12:1;
        RBus_UInt32  spc_pt_13:1;
        RBus_UInt32  spc_pt_14:1;
        RBus_UInt32  spc_pt_15:1;
        RBus_UInt32  spc_pt_16:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  pat_det_auto:1;
    };
}pif_pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:32;
    };
}pif_pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:32;
    };
}pif_pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:32;
    };
}pif_pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:32;
    };
}pif_pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:32;
    };
}pif_pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:32;
    };
}pif_pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:32;
    };
}pif_pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:32;
    };
}pif_pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_9:32;
    };
}pif_pat_det_sum9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_10:32;
    };
}pif_pat_det_sum10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_11:32;
    };
}pif_pat_det_sum11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_12:32;
    };
}pif_pat_det_sum12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_13:32;
    };
}pif_pat_det_sum13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_14:32;
    };
}pif_pat_det_sum14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_15:32;
    };
}pif_pat_det_sum15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_16:32;
    };
}pif_pat_det_sum16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:32;
    };
}pif_pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:32;
    };
}pif_pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:32;
    };
}pif_pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:32;
    };
}pif_pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:32;
    };
}pif_pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:32;
    };
}pif_pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:32;
    };
}pif_pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:32;
    };
}pif_pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th9:32;
    };
}pif_pat_det_th9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th10:32;
    };
}pif_pat_det_th10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th11:32;
    };
}pif_pat_det_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th12:32;
    };
}pif_pat_det_th12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th13:32;
    };
}pif_pat_det_th13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th14:32;
    };
}pif_pat_det_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th15:32;
    };
}pif_pat_det_th15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th16:32;
    };
}pif_pat_det_th16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_a_pair_sel:4;
        RBus_UInt32  lvds_a_b_pair_sel:4;
        RBus_UInt32  lvds_a_c_pair_sel:4;
        RBus_UInt32  lvds_a_d_pair_sel:4;
        RBus_UInt32  lvds_a_e_pair_sel:4;
        RBus_UInt32  lvds_a_f_pair_sel:4;
        RBus_UInt32  lvds_b_a_pair_sel:4;
        RBus_UInt32  lvds_b_b_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_c_pair_sel:4;
        RBus_UInt32  lvds_b_d_pair_sel:4;
        RBus_UInt32  lvds_b_e_pair_sel:4;
        RBus_UInt32  lvds_b_f_pair_sel:4;
        RBus_UInt32  lvds_c_a_pair_sel:4;
        RBus_UInt32  lvds_c_b_pair_sel:4;
        RBus_UInt32  lvds_c_c_pair_sel:4;
        RBus_UInt32  lvds_c_d_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_e_pair_sel:4;
        RBus_UInt32  lvds_c_f_pair_sel:4;
        RBus_UInt32  lvds_d_a_pair_sel:4;
        RBus_UInt32  lvds_d_b_pair_sel:4;
        RBus_UInt32  lvds_d_c_pair_sel:4;
        RBus_UInt32  lvds_d_d_pair_sel:4;
        RBus_UInt32  lvds_d_e_pair_sel:4;
        RBus_UInt32  lvds_d_f_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_2_RBUS;

#else //apply LITTLE_ENDIAN

//======PIF register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  plt_lvds_mode:2;
        RBus_UInt32  pif_debug_sel:4;
        RBus_UInt32  res2:24;
    };
}pif_lvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d004_31_0:32;
    };
}pif_lvds_dummy_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_bhs_sel:3;
        RBus_UInt32  lvds_bvs_sel:3;
        RBus_UInt32  lvds_bden_sel:3;
        RBus_UInt32  lvds_brsv0_sel:3;
        RBus_UInt32  lvds_brsv1_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  lvds_ahs_sel:3;
        RBus_UInt32  lvds_avs_sel:3;
        RBus_UInt32  lvds_aden_sel:3;
        RBus_UInt32  lvds_arsv0_sel:3;
        RBus_UInt32  lvds_arsv1_sel:3;
    };
}pif_lvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lvds_dhs_sel:3;
        RBus_UInt32  lvds_dvs_sel:3;
        RBus_UInt32  lvds_dden_sel:3;
        RBus_UInt32  lvds_drsv0_sel:3;
        RBus_UInt32  lvds_drsv1_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  lvds_chs_sel:3;
        RBus_UInt32  lvds_cvs_sel:3;
        RBus_UInt32  lvds_cden_sel:3;
        RBus_UInt32  lvds_crsv0_sel:3;
        RBus_UInt32  lvds_crsv1_sel:3;
    };
}pif_lvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d010_1_0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  lvds_dport_en:1;
        RBus_UInt32  lvds_cport_en:1;
        RBus_UInt32  lvds_bport_en:1;
        RBus_UInt32  lvds_aport_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dummy1802d010_10:1;
        RBus_UInt32  lvds_pn_swap:1;
        RBus_UInt32  lvds_map:2;
        RBus_UInt32  lvds_map_inv:1;
        RBus_UInt32  res3:17;
    };
}pif_lvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}pif_lvds_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_mode:2;
        RBus_UInt32  dummy1802d01c_2:1;
        RBus_UInt32  mlvds_pn_swap:1;
        RBus_UInt32  mlvds_rl_swap:1;
        RBus_UInt32  mlvds_8p_special_swap:1;
        RBus_UInt32  mlvds_map_inv:1;
        RBus_UInt32  mlvds_en:1;
        RBus_UInt32  mlvds_map_type_sel:4;
        RBus_UInt32  dummy1802d01c_31_12:20;
    };
}pif_mlvds_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_reset_pul_sel:12;
        RBus_UInt32  dummy1802d020_31_12:20;
    };
}pif_mlvds_reset_pul_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_high:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  mlvds_rst_tcon_en:1;
        RBus_UInt32  tcon_delay_sel_0:2;
        RBus_UInt32  tcon_delay_sel_1:2;
        RBus_UInt32  tcon_delay_sel_2:2;
        RBus_UInt32  tcon_delay_sel_3:2;
        RBus_UInt32  tcon_delay_sel_4:2;
        RBus_UInt32  tcon_delay_sel_5:2;
        RBus_UInt32  tcon_delay_sel_6:2;
        RBus_UInt32  tcon_delay_sel_7:2;
        RBus_UInt32  tcon_sel:8;
    };
}pif_mlvds_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p1_tcon_sel:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  p1_tcon_en:1;
        RBus_UInt32  p2_tcon_sel:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  p2_tcon_en:1;
        RBus_UInt32  p3_tcon_sel:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  p3_tcon_en:1;
        RBus_UInt32  fw_merge_tcon_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  mlvds_1ck_inv:1;
        RBus_UInt32  mlvds_2ck_inv:1;
        RBus_UInt32  dummy1802d028_29_28:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  mlvds_rst_low_region:1;
    };
}pif_mlvds_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_0:32;
    };
}pif_mlvds_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_rst_low_1:32;
    };
}pif_mlvds_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mlvds_reset_pulse_adv1t:1;
        RBus_UInt32  adv1t_auto_n:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  data_gating_mode:1;
    };
}pif_mlvds_multi_reset_pulse_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_width:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  pat_det_h_ini_sta:13;
        RBus_UInt32  res2:3;
    };
}pif_pat_det_window_h_ini_sta_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_height:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  pat_det_v_ini_sta:12;
        RBus_UInt32  res2:4;
    };
}pif_pat_det_window_v_ini_sta_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_det_auto:1;
        RBus_UInt32  pat_det_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  spc_pt_16:1;
        RBus_UInt32  spc_pt_15:1;
        RBus_UInt32  spc_pt_14:1;
        RBus_UInt32  spc_pt_13:1;
        RBus_UInt32  spc_pt_12:1;
        RBus_UInt32  spc_pt_11:1;
        RBus_UInt32  spc_pt_10:1;
        RBus_UInt32  spc_pt_9:1;
        RBus_UInt32  spc_pt_8:1;
        RBus_UInt32  spc_pt_7:1;
        RBus_UInt32  spc_pt_6:1;
        RBus_UInt32  spc_pt_5:1;
        RBus_UInt32  spc_pt_4:1;
        RBus_UInt32  spc_pt_3:1;
        RBus_UInt32  spc_pt_2:1;
        RBus_UInt32  spc_pt_1:1;
        RBus_UInt32  res2:8;
    };
}pif_pattern_detect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_1:32;
    };
}pif_pat_det_sum1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_2:32;
    };
}pif_pat_det_sum2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_3:32;
    };
}pif_pat_det_sum3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_4:32;
    };
}pif_pat_det_sum4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_5:32;
    };
}pif_pat_det_sum5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_6:32;
    };
}pif_pat_det_sum6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_7:32;
    };
}pif_pat_det_sum7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_8:32;
    };
}pif_pat_det_sum8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_9:32;
    };
}pif_pat_det_sum9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_10:32;
    };
}pif_pat_det_sum10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_11:32;
    };
}pif_pat_det_sum11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_12:32;
    };
}pif_pat_det_sum12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_13:32;
    };
}pif_pat_det_sum13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_14:32;
    };
}pif_pat_det_sum14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_15:32;
    };
}pif_pat_det_sum15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_line_16:32;
    };
}pif_pat_det_sum16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th1:32;
    };
}pif_pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th2:32;
    };
}pif_pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th3:32;
    };
}pif_pat_det_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th4:32;
    };
}pif_pat_det_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th5:32;
    };
}pif_pat_det_th5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th6:32;
    };
}pif_pat_det_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th7:32;
    };
}pif_pat_det_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th8:32;
    };
}pif_pat_det_th8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th9:32;
    };
}pif_pat_det_th9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th10:32;
    };
}pif_pat_det_th10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th11:32;
    };
}pif_pat_det_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th12:32;
    };
}pif_pat_det_th12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th13:32;
    };
}pif_pat_det_th13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th14:32;
    };
}pif_pat_det_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th15:32;
    };
}pif_pat_det_th15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pat_th16:32;
    };
}pif_pat_det_th16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_b_pair_sel:4;
        RBus_UInt32  lvds_b_a_pair_sel:4;
        RBus_UInt32  lvds_a_f_pair_sel:4;
        RBus_UInt32  lvds_a_e_pair_sel:4;
        RBus_UInt32  lvds_a_d_pair_sel:4;
        RBus_UInt32  lvds_a_c_pair_sel:4;
        RBus_UInt32  lvds_a_b_pair_sel:4;
        RBus_UInt32  lvds_a_a_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_d_pair_sel:4;
        RBus_UInt32  lvds_c_c_pair_sel:4;
        RBus_UInt32  lvds_c_b_pair_sel:4;
        RBus_UInt32  lvds_c_a_pair_sel:4;
        RBus_UInt32  lvds_b_f_pair_sel:4;
        RBus_UInt32  lvds_b_e_pair_sel:4;
        RBus_UInt32  lvds_b_d_pair_sel:4;
        RBus_UInt32  lvds_b_c_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_f_pair_sel:4;
        RBus_UInt32  lvds_d_e_pair_sel:4;
        RBus_UInt32  lvds_d_d_pair_sel:4;
        RBus_UInt32  lvds_d_c_pair_sel:4;
        RBus_UInt32  lvds_d_b_pair_sel:4;
        RBus_UInt32  lvds_d_a_pair_sel:4;
        RBus_UInt32  lvds_c_f_pair_sel:4;
        RBus_UInt32  lvds_c_e_pair_sel:4;
    };
}pif_lvds_pair_select_ctrl_2_RBUS;




#endif 


#endif 
