/**
* @file Mac5_DC_PHY_PTG_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC_PHY_PTG_REG_H_
#define _RBUS_DC_PHY_PTG_REG_H_

#include "rbus_types.h"



//  DC_PHY_PTG Register Address
#define  DC_PHY_PTG_Cfg_Reg_00                                                   0x180B3000
#define  DC_PHY_PTG_Cfg_Reg_00_reg_addr                                          "0xB80B3000"
#define  DC_PHY_PTG_Cfg_Reg_00_reg                                               0xB80B3000
#define  DC_PHY_PTG_Cfg_Reg_00_inst_addr                                         "0x0000"
#define  set_DC_PHY_PTG_Cfg_Reg_00_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_00_reg)=data)
#define  get_DC_PHY_PTG_Cfg_Reg_00_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_00_reg))
#define  DC_PHY_PTG_Cfg_Reg_00_errstp_num_shift                                  (24)
#define  DC_PHY_PTG_Cfg_Reg_00_cmdwai_num_shift                                  (16)
#define  DC_PHY_PTG_Cfg_Reg_00_torept_num_shift                                  (8)
#define  DC_PHY_PTG_Cfg_Reg_00_rwrept_num_shift                                  (0)
#define  DC_PHY_PTG_Cfg_Reg_00_errstp_num_mask                                   (0xFF000000)
#define  DC_PHY_PTG_Cfg_Reg_00_cmdwai_num_mask                                   (0x00FF0000)
#define  DC_PHY_PTG_Cfg_Reg_00_torept_num_mask                                   (0x0000FF00)
#define  DC_PHY_PTG_Cfg_Reg_00_rwrept_num_mask                                   (0x000000FF)
#define  DC_PHY_PTG_Cfg_Reg_00_errstp_num(data)                                  (0xFF000000&((data)<<24))
#define  DC_PHY_PTG_Cfg_Reg_00_cmdwai_num(data)                                  (0x00FF0000&((data)<<16))
#define  DC_PHY_PTG_Cfg_Reg_00_torept_num(data)                                  (0x0000FF00&((data)<<8))
#define  DC_PHY_PTG_Cfg_Reg_00_rwrept_num(data)                                  (0x000000FF&(data))
#define  DC_PHY_PTG_Cfg_Reg_00_get_errstp_num(data)                              ((0xFF000000&(data))>>24)
#define  DC_PHY_PTG_Cfg_Reg_00_get_cmdwai_num(data)                              ((0x00FF0000&(data))>>16)
#define  DC_PHY_PTG_Cfg_Reg_00_get_torept_num(data)                              ((0x0000FF00&(data))>>8)
#define  DC_PHY_PTG_Cfg_Reg_00_get_rwrept_num(data)                              (0x000000FF&(data))

#define  DC_PHY_PTG_Cfg_Reg_04                                                   0x180B3004
#define  DC_PHY_PTG_Cfg_Reg_04_reg_addr                                          "0xB80B3004"
#define  DC_PHY_PTG_Cfg_Reg_04_reg                                               0xB80B3004
#define  DC_PHY_PTG_Cfg_Reg_04_inst_addr                                         "0x0001"
#define  set_DC_PHY_PTG_Cfg_Reg_04_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_04_reg)=data)
#define  get_DC_PHY_PTG_Cfg_Reg_04_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_04_reg))
#define  DC_PHY_PTG_Cfg_Reg_04_dummy_reg_shift                                   (30)
#define  DC_PHY_PTG_Cfg_Reg_04_cmd_tag_1_0_shift                                 (28)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_mod_shift                                     (25)
#define  DC_PHY_PTG_Cfg_Reg_04_inc_bak_shift                                     (23)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_bak_shift                                     (20)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_y_shift                                       (18)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_x_shift                                       (17)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_ddr_shift                                     (16)
#define  DC_PHY_PTG_Cfg_Reg_04_door_shift                                        (9)
#define  DC_PHY_PTG_Cfg_Reg_04_slflopback_shift                                  (8)
#define  DC_PHY_PTG_Cfg_Reg_04_phylopback_shift                                  (7)
#define  DC_PHY_PTG_Cfg_Reg_04_torept_cti_shift                                  (6)
#define  DC_PHY_PTG_Cfg_Reg_04_rcv_closed_shift                                  (5)
#define  DC_PHY_PTG_Cfg_Reg_04_xmt_closed_shift                                  (4)
#define  DC_PHY_PTG_Cfg_Reg_04_tst_st_shift                                      (1)
#define  DC_PHY_PTG_Cfg_Reg_04_tst_strt_shift                                    (0)
#define  DC_PHY_PTG_Cfg_Reg_04_dummy_reg_mask                                    (0xC0000000)
#define  DC_PHY_PTG_Cfg_Reg_04_cmd_tag_1_0_mask                                  (0x30000000)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_mod_mask                                      (0x0E000000)
#define  DC_PHY_PTG_Cfg_Reg_04_inc_bak_mask                                      (0x01800000)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_bak_mask                                      (0x00700000)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_y_mask                                        (0x000C0000)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_x_mask                                        (0x00020000)
#define  DC_PHY_PTG_Cfg_Reg_04_ini_ddr_mask                                      (0x00010000)
#define  DC_PHY_PTG_Cfg_Reg_04_door_mask                                         (0x0000FE00)
#define  DC_PHY_PTG_Cfg_Reg_04_slflopback_mask                                   (0x00000100)
#define  DC_PHY_PTG_Cfg_Reg_04_phylopback_mask                                   (0x00000080)
#define  DC_PHY_PTG_Cfg_Reg_04_torept_cti_mask                                   (0x00000040)
#define  DC_PHY_PTG_Cfg_Reg_04_rcv_closed_mask                                   (0x00000020)
#define  DC_PHY_PTG_Cfg_Reg_04_xmt_closed_mask                                   (0x00000010)
#define  DC_PHY_PTG_Cfg_Reg_04_tst_st_mask                                       (0x0000000E)
#define  DC_PHY_PTG_Cfg_Reg_04_tst_strt_mask                                     (0x00000001)
#define  DC_PHY_PTG_Cfg_Reg_04_dummy_reg(data)                                   (0xC0000000&((data)<<30))
#define  DC_PHY_PTG_Cfg_Reg_04_cmd_tag_1_0(data)                                 (0x30000000&((data)<<28))
#define  DC_PHY_PTG_Cfg_Reg_04_ini_mod(data)                                     (0x0E000000&((data)<<25))
#define  DC_PHY_PTG_Cfg_Reg_04_inc_bak(data)                                     (0x01800000&((data)<<23))
#define  DC_PHY_PTG_Cfg_Reg_04_ini_bak(data)                                     (0x00700000&((data)<<20))
#define  DC_PHY_PTG_Cfg_Reg_04_ini_y(data)                                       (0x000C0000&((data)<<18))
#define  DC_PHY_PTG_Cfg_Reg_04_ini_x(data)                                       (0x00020000&((data)<<17))
#define  DC_PHY_PTG_Cfg_Reg_04_ini_ddr(data)                                     (0x00010000&((data)<<16))
#define  DC_PHY_PTG_Cfg_Reg_04_door(data)                                        (0x0000FE00&((data)<<9))
#define  DC_PHY_PTG_Cfg_Reg_04_slflopback(data)                                  (0x00000100&((data)<<8))
#define  DC_PHY_PTG_Cfg_Reg_04_phylopback(data)                                  (0x00000080&((data)<<7))
#define  DC_PHY_PTG_Cfg_Reg_04_torept_cti(data)                                  (0x00000040&((data)<<6))
#define  DC_PHY_PTG_Cfg_Reg_04_rcv_closed(data)                                  (0x00000020&((data)<<5))
#define  DC_PHY_PTG_Cfg_Reg_04_xmt_closed(data)                                  (0x00000010&((data)<<4))
#define  DC_PHY_PTG_Cfg_Reg_04_tst_st(data)                                      (0x0000000E&((data)<<1))
#define  DC_PHY_PTG_Cfg_Reg_04_tst_strt(data)                                    (0x00000001&(data))
#define  DC_PHY_PTG_Cfg_Reg_04_get_dummy_reg(data)                               ((0xC0000000&(data))>>30)
#define  DC_PHY_PTG_Cfg_Reg_04_get_cmd_tag_1_0(data)                             ((0x30000000&(data))>>28)
#define  DC_PHY_PTG_Cfg_Reg_04_get_ini_mod(data)                                 ((0x0E000000&(data))>>25)
#define  DC_PHY_PTG_Cfg_Reg_04_get_inc_bak(data)                                 ((0x01800000&(data))>>23)
#define  DC_PHY_PTG_Cfg_Reg_04_get_ini_bak(data)                                 ((0x00700000&(data))>>20)
#define  DC_PHY_PTG_Cfg_Reg_04_get_ini_y(data)                                   ((0x000C0000&(data))>>18)
#define  DC_PHY_PTG_Cfg_Reg_04_get_ini_x(data)                                   ((0x00020000&(data))>>17)
#define  DC_PHY_PTG_Cfg_Reg_04_get_ini_ddr(data)                                 ((0x00010000&(data))>>16)
#define  DC_PHY_PTG_Cfg_Reg_04_get_door(data)                                    ((0x0000FE00&(data))>>9)
#define  DC_PHY_PTG_Cfg_Reg_04_get_slflopback(data)                              ((0x00000100&(data))>>8)
#define  DC_PHY_PTG_Cfg_Reg_04_get_phylopback(data)                              ((0x00000080&(data))>>7)
#define  DC_PHY_PTG_Cfg_Reg_04_get_torept_cti(data)                              ((0x00000040&(data))>>6)
#define  DC_PHY_PTG_Cfg_Reg_04_get_rcv_closed(data)                              ((0x00000020&(data))>>5)
#define  DC_PHY_PTG_Cfg_Reg_04_get_xmt_closed(data)                              ((0x00000010&(data))>>4)
#define  DC_PHY_PTG_Cfg_Reg_04_get_tst_st(data)                                  ((0x0000000E&(data))>>1)
#define  DC_PHY_PTG_Cfg_Reg_04_get_tst_strt(data)                                (0x00000001&(data))

#define  DC_PHY_PTG_Cfg_Reg_08                                                   0x180B3008
#define  DC_PHY_PTG_Cfg_Reg_08_reg_addr                                          "0xB80B3008"
#define  DC_PHY_PTG_Cfg_Reg_08_reg                                               0xB80B3008
#define  DC_PHY_PTG_Cfg_Reg_08_inst_addr                                         "0x0002"
#define  set_DC_PHY_PTG_Cfg_Reg_08_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_08_reg)=data)
#define  get_DC_PHY_PTG_Cfg_Reg_08_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_08_reg))
#define  DC_PHY_PTG_Cfg_Reg_08_ini_wr_shift                                      (22)
#define  DC_PHY_PTG_Cfg_Reg_08_inc_col_shift                                     (18)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_col_shift                                     (8)
#define  DC_PHY_PTG_Cfg_Reg_08_inc_bl_shift                                      (5)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_bl_shift                                      (0)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_wr_mask                                       (0x00400000)
#define  DC_PHY_PTG_Cfg_Reg_08_inc_col_mask                                      (0x003C0000)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_col_mask                                      (0x0003FF00)
#define  DC_PHY_PTG_Cfg_Reg_08_inc_bl_mask                                       (0x000000E0)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_bl_mask                                       (0x0000001F)
#define  DC_PHY_PTG_Cfg_Reg_08_ini_wr(data)                                      (0x00400000&((data)<<22))
#define  DC_PHY_PTG_Cfg_Reg_08_inc_col(data)                                     (0x003C0000&((data)<<18))
#define  DC_PHY_PTG_Cfg_Reg_08_ini_col(data)                                     (0x0003FF00&((data)<<8))
#define  DC_PHY_PTG_Cfg_Reg_08_inc_bl(data)                                      (0x000000E0&((data)<<5))
#define  DC_PHY_PTG_Cfg_Reg_08_ini_bl(data)                                      (0x0000001F&(data))
#define  DC_PHY_PTG_Cfg_Reg_08_get_ini_wr(data)                                  ((0x00400000&(data))>>22)
#define  DC_PHY_PTG_Cfg_Reg_08_get_inc_col(data)                                 ((0x003C0000&(data))>>18)
#define  DC_PHY_PTG_Cfg_Reg_08_get_ini_col(data)                                 ((0x0003FF00&(data))>>8)
#define  DC_PHY_PTG_Cfg_Reg_08_get_inc_bl(data)                                  ((0x000000E0&(data))>>5)
#define  DC_PHY_PTG_Cfg_Reg_08_get_ini_bl(data)                                  (0x0000001F&(data))

#define  DC_PHY_PTG_Cfg_Reg_0c                                                   0x180B300C
#define  DC_PHY_PTG_Cfg_Reg_0c_reg_addr                                          "0xB80B300C"
#define  DC_PHY_PTG_Cfg_Reg_0c_reg                                               0xB80B300C
#define  DC_PHY_PTG_Cfg_Reg_0c_inst_addr                                         "0x0003"
#define  set_DC_PHY_PTG_Cfg_Reg_0c_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_0c_reg)=data)
#define  get_DC_PHY_PTG_Cfg_Reg_0c_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_0c_reg))
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_id_4_shift                                    (22)
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_tag_3_2_shift                                 (20)
#define  DC_PHY_PTG_Cfg_Reg_0c_inc_pag_shift                                     (17)
#define  DC_PHY_PTG_Cfg_Reg_0c_ini_pag_shift                                     (0)
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_id_4_mask                                     (0x00400000)
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_tag_3_2_mask                                  (0x00300000)
#define  DC_PHY_PTG_Cfg_Reg_0c_inc_pag_mask                                      (0x000E0000)
#define  DC_PHY_PTG_Cfg_Reg_0c_ini_pag_mask                                      (0x0001FFFF)
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_id_4(data)                                    (0x00400000&((data)<<22))
#define  DC_PHY_PTG_Cfg_Reg_0c_cmd_tag_3_2(data)                                 (0x00300000&((data)<<20))
#define  DC_PHY_PTG_Cfg_Reg_0c_inc_pag(data)                                     (0x000E0000&((data)<<17))
#define  DC_PHY_PTG_Cfg_Reg_0c_ini_pag(data)                                     (0x0001FFFF&(data))
#define  DC_PHY_PTG_Cfg_Reg_0c_get_cmd_id_4(data)                                ((0x00400000&(data))>>22)
#define  DC_PHY_PTG_Cfg_Reg_0c_get_cmd_tag_3_2(data)                             ((0x00300000&(data))>>20)
#define  DC_PHY_PTG_Cfg_Reg_0c_get_inc_pag(data)                                 ((0x000E0000&(data))>>17)
#define  DC_PHY_PTG_Cfg_Reg_0c_get_ini_pag(data)                                 (0x0001FFFF&(data))

#define  DC_PHY_PTG_Cfg_Reg_10                                                   0x180B3010
#define  DC_PHY_PTG_Cfg_Reg_10_reg_addr                                          "0xB80B3010"
#define  DC_PHY_PTG_Cfg_Reg_10_reg                                               0xB80B3010
#define  DC_PHY_PTG_Cfg_Reg_10_inst_addr                                         "0x0004"
#define  set_DC_PHY_PTG_Cfg_Reg_10_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_10_reg)=data)
#define  get_DC_PHY_PTG_Cfg_Reg_10_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_Cfg_Reg_10_reg))
#define  DC_PHY_PTG_Cfg_Reg_10_sa_rcverr_shift                                   (8)
#define  DC_PHY_PTG_Cfg_Reg_10_cnt_rcverr_shift                                  (0)
#define  DC_PHY_PTG_Cfg_Reg_10_sa_rcverr_mask                                    (0x00000F00)
#define  DC_PHY_PTG_Cfg_Reg_10_cnt_rcverr_mask                                   (0x000000FF)
#define  DC_PHY_PTG_Cfg_Reg_10_sa_rcverr(data)                                   (0x00000F00&((data)<<8))
#define  DC_PHY_PTG_Cfg_Reg_10_cnt_rcverr(data)                                  (0x000000FF&(data))
#define  DC_PHY_PTG_Cfg_Reg_10_get_sa_rcverr(data)                               ((0x00000F00&(data))>>8)
#define  DC_PHY_PTG_Cfg_Reg_10_get_cnt_rcverr(data)                              (0x000000FF&(data))

#define  DC_PHY_PTG_HW_SW_CTRL                                                   0x180B3014
#define  DC_PHY_PTG_HW_SW_CTRL_reg_addr                                          "0xB80B3014"
#define  DC_PHY_PTG_HW_SW_CTRL_reg                                               0xB80B3014
#define  DC_PHY_PTG_HW_SW_CTRL_inst_addr                                         "0x0005"
#define  set_DC_PHY_PTG_HW_SW_CTRL_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_HW_SW_CTRL_reg)=data)
#define  get_DC_PHY_PTG_HW_SW_CTRL_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_HW_SW_CTRL_reg))
#define  DC_PHY_PTG_HW_SW_CTRL_clr_fail_cmd_shift                                (5)
#define  DC_PHY_PTG_HW_SW_CTRL_en_cap_fail_cmd_shift                             (4)
#define  DC_PHY_PTG_HW_SW_CTRL_cmp_err_flag_shift                                (3)
#define  DC_PHY_PTG_HW_SW_CTRL_scramble_en_shift                                 (2)
#define  DC_PHY_PTG_HW_SW_CTRL_pause_shift                                       (1)
#define  DC_PHY_PTG_HW_SW_CTRL_sw_en_shift                                       (0)
#define  DC_PHY_PTG_HW_SW_CTRL_clr_fail_cmd_mask                                 (0x00000020)
#define  DC_PHY_PTG_HW_SW_CTRL_en_cap_fail_cmd_mask                              (0x00000010)
#define  DC_PHY_PTG_HW_SW_CTRL_cmp_err_flag_mask                                 (0x00000008)
#define  DC_PHY_PTG_HW_SW_CTRL_scramble_en_mask                                  (0x00000004)
#define  DC_PHY_PTG_HW_SW_CTRL_pause_mask                                        (0x00000002)
#define  DC_PHY_PTG_HW_SW_CTRL_sw_en_mask                                        (0x00000001)
#define  DC_PHY_PTG_HW_SW_CTRL_clr_fail_cmd(data)                                (0x00000020&((data)<<5))
#define  DC_PHY_PTG_HW_SW_CTRL_en_cap_fail_cmd(data)                             (0x00000010&((data)<<4))
#define  DC_PHY_PTG_HW_SW_CTRL_cmp_err_flag(data)                                (0x00000008&((data)<<3))
#define  DC_PHY_PTG_HW_SW_CTRL_scramble_en(data)                                 (0x00000004&((data)<<2))
#define  DC_PHY_PTG_HW_SW_CTRL_pause(data)                                       (0x00000002&((data)<<1))
#define  DC_PHY_PTG_HW_SW_CTRL_sw_en(data)                                       (0x00000001&(data))
#define  DC_PHY_PTG_HW_SW_CTRL_get_clr_fail_cmd(data)                            ((0x00000020&(data))>>5)
#define  DC_PHY_PTG_HW_SW_CTRL_get_en_cap_fail_cmd(data)                         ((0x00000010&(data))>>4)
#define  DC_PHY_PTG_HW_SW_CTRL_get_cmp_err_flag(data)                            ((0x00000008&(data))>>3)
#define  DC_PHY_PTG_HW_SW_CTRL_get_scramble_en(data)                             ((0x00000004&(data))>>2)
#define  DC_PHY_PTG_HW_SW_CTRL_get_pause(data)                                   ((0x00000002&(data))>>1)
#define  DC_PHY_PTG_HW_SW_CTRL_get_sw_en(data)                                   (0x00000001&(data))

#define  DC_PHY_PTG_CMD_SRAM_CTR                                                 0x180B3018
#define  DC_PHY_PTG_CMD_SRAM_CTR_reg_addr                                        "0xB80B3018"
#define  DC_PHY_PTG_CMD_SRAM_CTR_reg                                             0xB80B3018
#define  DC_PHY_PTG_CMD_SRAM_CTR_inst_addr                                       "0x0006"
#define  set_DC_PHY_PTG_CMD_SRAM_CTR_reg(data)                                   (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_CTR_reg)=data)
#define  get_DC_PHY_PTG_CMD_SRAM_CTR_reg                                         (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_CTR_reg))
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmd_num_shift                                   (16)
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmp_fail_stop_num_shift                         (10)
#define  DC_PHY_PTG_CMD_SRAM_CTR_go_shift                                        (9)
#define  DC_PHY_PTG_CMD_SRAM_CTR_rpt_num_shift                                   (0)
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmd_num_mask                                    (0x007F0000)
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmp_fail_stop_num_mask                          (0x00000400)
#define  DC_PHY_PTG_CMD_SRAM_CTR_go_mask                                         (0x00000200)
#define  DC_PHY_PTG_CMD_SRAM_CTR_rpt_num_mask                                    (0x000000FF)
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmd_num(data)                                   (0x007F0000&((data)<<16))
#define  DC_PHY_PTG_CMD_SRAM_CTR_cmp_fail_stop_num(data)                         (0x00000400&((data)<<10))
#define  DC_PHY_PTG_CMD_SRAM_CTR_go(data)                                        (0x00000200&((data)<<9))
#define  DC_PHY_PTG_CMD_SRAM_CTR_rpt_num(data)                                   (0x000000FF&(data))
#define  DC_PHY_PTG_CMD_SRAM_CTR_get_cmd_num(data)                               ((0x007F0000&(data))>>16)
#define  DC_PHY_PTG_CMD_SRAM_CTR_get_cmp_fail_stop_num(data)                     ((0x00000400&(data))>>10)
#define  DC_PHY_PTG_CMD_SRAM_CTR_get_go(data)                                    ((0x00000200&(data))>>9)
#define  DC_PHY_PTG_CMD_SRAM_CTR_get_rpt_num(data)                               (0x000000FF&(data))

#define  DC_PHY_PTG_CMD_SRAM_ADDR                                                0x180B301C
#define  DC_PHY_PTG_CMD_SRAM_ADDR_reg_addr                                       "0xB80B301C"
#define  DC_PHY_PTG_CMD_SRAM_ADDR_reg                                            0xB80B301C
#define  DC_PHY_PTG_CMD_SRAM_ADDR_inst_addr                                      "0x0007"
#define  set_DC_PHY_PTG_CMD_SRAM_ADDR_reg(data)                                  (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_ADDR_reg)=data)
#define  get_DC_PHY_PTG_CMD_SRAM_ADDR_reg                                        (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_ADDR_reg))
#define  DC_PHY_PTG_CMD_SRAM_ADDR_write_en_shift                                 (9)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_en_sw_acc_shift                                (8)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_sw_shift                                       (0)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_write_en_mask                                  (0x00000200)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_en_sw_acc_mask                                 (0x00000100)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_sw_mask                                        (0x0000003F)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_write_en(data)                                 (0x00000200&((data)<<9))
#define  DC_PHY_PTG_CMD_SRAM_ADDR_en_sw_acc(data)                                (0x00000100&((data)<<8))
#define  DC_PHY_PTG_CMD_SRAM_ADDR_sw(data)                                       (0x0000003F&(data))
#define  DC_PHY_PTG_CMD_SRAM_ADDR_get_write_en(data)                             ((0x00000200&(data))>>9)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_get_en_sw_acc(data)                            ((0x00000100&(data))>>8)
#define  DC_PHY_PTG_CMD_SRAM_ADDR_get_sw(data)                                   (0x0000003F&(data))

#define  DC_PHY_PTG_CMD_SRAM_0                                                   0x180B3020
#define  DC_PHY_PTG_CMD_SRAM_0_reg_addr                                          "0xB80B3020"
#define  DC_PHY_PTG_CMD_SRAM_0_reg                                               0xB80B3020
#define  DC_PHY_PTG_CMD_SRAM_0_inst_addr                                         "0x0008"
#define  set_DC_PHY_PTG_CMD_SRAM_0_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_0_reg)=data)
#define  get_DC_PHY_PTG_CMD_SRAM_0_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_0_reg))
#define  DC_PHY_PTG_CMD_SRAM_0_dat_shift                                         (0)
#define  DC_PHY_PTG_CMD_SRAM_0_dat_mask                                          (0xFFFFFFFF)
#define  DC_PHY_PTG_CMD_SRAM_0_dat(data)                                         (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMD_SRAM_0_get_dat(data)                                     (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMD_SRAM_1                                                   0x180B3024
#define  DC_PHY_PTG_CMD_SRAM_1_reg_addr                                          "0xB80B3024"
#define  DC_PHY_PTG_CMD_SRAM_1_reg                                               0xB80B3024
#define  DC_PHY_PTG_CMD_SRAM_1_inst_addr                                         "0x0009"
#define  set_DC_PHY_PTG_CMD_SRAM_1_reg(data)                                     (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_1_reg)=data)
#define  get_DC_PHY_PTG_CMD_SRAM_1_reg                                           (*((volatile unsigned int*)DC_PHY_PTG_CMD_SRAM_1_reg))
#define  DC_PHY_PTG_CMD_SRAM_1_cmp_dat_shift                                     (19)
#define  DC_PHY_PTG_CMD_SRAM_1_dat_shift                                         (0)
#define  DC_PHY_PTG_CMD_SRAM_1_cmp_dat_mask                                      (0x00380000)
#define  DC_PHY_PTG_CMD_SRAM_1_dat_mask                                          (0x0007FFFF)
#define  DC_PHY_PTG_CMD_SRAM_1_cmp_dat(data)                                     (0x00380000&((data)<<19))
#define  DC_PHY_PTG_CMD_SRAM_1_dat(data)                                         (0x0007FFFF&(data))
#define  DC_PHY_PTG_CMD_SRAM_1_get_cmp_dat(data)                                 ((0x00380000&(data))>>19)
#define  DC_PHY_PTG_CMD_SRAM_1_get_dat(data)                                     (0x0007FFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_CMD_0                                               0x180B3028
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_reg_addr                                      "0xB80B3028"
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_reg                                           0xB80B3028
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_inst_addr                                     "0x000A"
#define  set_DC_PHY_PTG_CMP_FAIL_CMD_0_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_CMD_0_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_CMD_0_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_CMD_0_reg))
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_cmp_dat_shift                                 (0)
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_cmp_dat_mask                                  (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_cmp_dat(data)                                 (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_CMD_0_get_cmp_dat(data)                             (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_CMD_1                                               0x180B302C
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_reg_addr                                      "0xB80B302C"
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_reg                                           0xB80B302C
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_inst_addr                                     "0x000B"
#define  set_DC_PHY_PTG_CMP_FAIL_CMD_1_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_CMD_1_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_CMD_1_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_CMD_1_reg))
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_wmask_shift                                   (16)
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_cmp_dat_shift                                 (0)
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_wmask_mask                                    (0xFFFF0000)
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_cmp_dat_mask                                  (0x0000FFFF)
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_wmask(data)                                   (0xFFFF0000&((data)<<16))
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_cmp_dat(data)                                 (0x0000FFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_get_wmask(data)                               ((0xFFFF0000&(data))>>16)
#define  DC_PHY_PTG_CMP_FAIL_CMD_1_get_cmp_dat(data)                             (0x0000FFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_EXP_0                                               0x180B3030
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_reg_addr                                      "0xB80B3030"
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_reg                                           0xB80B3030
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_inst_addr                                     "0x000C"
#define  set_DC_PHY_PTG_CMP_FAIL_EXP_0_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_0_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_EXP_0_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_0_reg))
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_dat_shift                                     (0)
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_dat_mask                                      (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_dat(data)                                     (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_EXP_0_get_dat(data)                                 (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_EXP_1                                               0x180B3034
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_reg_addr                                      "0xB80B3034"
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_reg                                           0xB80B3034
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_inst_addr                                     "0x000D"
#define  set_DC_PHY_PTG_CMP_FAIL_EXP_1_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_1_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_EXP_1_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_1_reg))
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_dat_shift                                     (0)
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_dat_mask                                      (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_dat(data)                                     (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_EXP_1_get_dat(data)                                 (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_EXP_2                                               0x180B3038
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_reg_addr                                      "0xB80B3038"
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_reg                                           0xB80B3038
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_inst_addr                                     "0x000E"
#define  set_DC_PHY_PTG_CMP_FAIL_EXP_2_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_2_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_EXP_2_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_2_reg))
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_dat_shift                                     (0)
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_dat_mask                                      (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_dat(data)                                     (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_EXP_2_get_dat(data)                                 (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_EXP_3                                               0x180B303C
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_reg_addr                                      "0xB80B303C"
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_reg                                           0xB80B303C
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_inst_addr                                     "0x000F"
#define  set_DC_PHY_PTG_CMP_FAIL_EXP_3_reg(data)                                 (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_3_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_EXP_3_reg                                       (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_EXP_3_reg))
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_dat_shift                                     (0)
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_dat_mask                                      (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_dat(data)                                     (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_EXP_3_get_dat(data)                                 (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_READ_0                                              0x180B3040
#define  DC_PHY_PTG_CMP_FAIL_READ_0_reg_addr                                     "0xB80B3040"
#define  DC_PHY_PTG_CMP_FAIL_READ_0_reg                                          0xB80B3040
#define  DC_PHY_PTG_CMP_FAIL_READ_0_inst_addr                                    "0x0010"
#define  set_DC_PHY_PTG_CMP_FAIL_READ_0_reg(data)                                (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_0_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_READ_0_reg                                      (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_0_reg))
#define  DC_PHY_PTG_CMP_FAIL_READ_0_dat_shift                                    (0)
#define  DC_PHY_PTG_CMP_FAIL_READ_0_dat_mask                                     (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_READ_0_dat(data)                                    (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_READ_0_get_dat(data)                                (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_READ_1                                              0x180B3044
#define  DC_PHY_PTG_CMP_FAIL_READ_1_reg_addr                                     "0xB80B3044"
#define  DC_PHY_PTG_CMP_FAIL_READ_1_reg                                          0xB80B3044
#define  DC_PHY_PTG_CMP_FAIL_READ_1_inst_addr                                    "0x0011"
#define  set_DC_PHY_PTG_CMP_FAIL_READ_1_reg(data)                                (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_1_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_READ_1_reg                                      (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_1_reg))
#define  DC_PHY_PTG_CMP_FAIL_READ_1_dat_shift                                    (0)
#define  DC_PHY_PTG_CMP_FAIL_READ_1_dat_mask                                     (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_READ_1_dat(data)                                    (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_READ_1_get_dat(data)                                (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_READ_2                                              0x180B3048
#define  DC_PHY_PTG_CMP_FAIL_READ_2_reg_addr                                     "0xB80B3048"
#define  DC_PHY_PTG_CMP_FAIL_READ_2_reg                                          0xB80B3048
#define  DC_PHY_PTG_CMP_FAIL_READ_2_inst_addr                                    "0x0012"
#define  set_DC_PHY_PTG_CMP_FAIL_READ_2_reg(data)                                (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_2_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_READ_2_reg                                      (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_2_reg))
#define  DC_PHY_PTG_CMP_FAIL_READ_2_dat_shift                                    (0)
#define  DC_PHY_PTG_CMP_FAIL_READ_2_dat_mask                                     (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_READ_2_dat(data)                                    (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_READ_2_get_dat(data)                                (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CMP_FAIL_READ_3                                              0x180B304C
#define  DC_PHY_PTG_CMP_FAIL_READ_3_reg_addr                                     "0xB80B304C"
#define  DC_PHY_PTG_CMP_FAIL_READ_3_reg                                          0xB80B304C
#define  DC_PHY_PTG_CMP_FAIL_READ_3_inst_addr                                    "0x0013"
#define  set_DC_PHY_PTG_CMP_FAIL_READ_3_reg(data)                                (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_3_reg)=data)
#define  get_DC_PHY_PTG_CMP_FAIL_READ_3_reg                                      (*((volatile unsigned int*)DC_PHY_PTG_CMP_FAIL_READ_3_reg))
#define  DC_PHY_PTG_CMP_FAIL_READ_3_dat_shift                                    (0)
#define  DC_PHY_PTG_CMP_FAIL_READ_3_dat_mask                                     (0xFFFFFFFF)
#define  DC_PHY_PTG_CMP_FAIL_READ_3_dat(data)                                    (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_CMP_FAIL_READ_3_get_dat(data)                                (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_STS_0                                                        0x180B3050
#define  DC_PHY_PTG_STS_0_reg_addr                                               "0xB80B3050"
#define  DC_PHY_PTG_STS_0_reg                                                    0xB80B3050
#define  DC_PHY_PTG_STS_0_inst_addr                                              "0x0014"
#define  set_DC_PHY_PTG_STS_0_reg(data)                                          (*((volatile unsigned int*)DC_PHY_PTG_STS_0_reg)=data)
#define  get_DC_PHY_PTG_STS_0_reg                                                (*((volatile unsigned int*)DC_PHY_PTG_STS_0_reg))
#define  DC_PHY_PTG_STS_0_sent_cmd_shift                                         (0)
#define  DC_PHY_PTG_STS_0_sent_cmd_mask                                          (0xFFFFFFFF)
#define  DC_PHY_PTG_STS_0_sent_cmd(data)                                         (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_STS_0_get_sent_cmd(data)                                     (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_STS_1                                                        0x180B3054
#define  DC_PHY_PTG_STS_1_reg_addr                                               "0xB80B3054"
#define  DC_PHY_PTG_STS_1_reg                                                    0xB80B3054
#define  DC_PHY_PTG_STS_1_inst_addr                                              "0x0015"
#define  set_DC_PHY_PTG_STS_1_reg(data)                                          (*((volatile unsigned int*)DC_PHY_PTG_STS_1_reg)=data)
#define  get_DC_PHY_PTG_STS_1_reg                                                (*((volatile unsigned int*)DC_PHY_PTG_STS_1_reg))
#define  DC_PHY_PTG_STS_1_cmp_cmd_shift                                          (0)
#define  DC_PHY_PTG_STS_1_cmp_cmd_mask                                           (0xFFFFFFFF)
#define  DC_PHY_PTG_STS_1_cmp_cmd(data)                                          (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_STS_1_get_cmp_cmd(data)                                      (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_STS_2                                                        0x180B3058
#define  DC_PHY_PTG_STS_2_reg_addr                                               "0xB80B3058"
#define  DC_PHY_PTG_STS_2_reg                                                    0xB80B3058
#define  DC_PHY_PTG_STS_2_inst_addr                                              "0x0016"
#define  set_DC_PHY_PTG_STS_2_reg(data)                                          (*((volatile unsigned int*)DC_PHY_PTG_STS_2_reg)=data)
#define  get_DC_PHY_PTG_STS_2_reg                                                (*((volatile unsigned int*)DC_PHY_PTG_STS_2_reg))
#define  DC_PHY_PTG_STS_2_sent_wr_cmd_shift                                      (0)
#define  DC_PHY_PTG_STS_2_sent_wr_cmd_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_STS_2_sent_wr_cmd(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_STS_2_get_sent_wr_cmd(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_STS_3                                                        0x180B305C
#define  DC_PHY_PTG_STS_3_reg_addr                                               "0xB80B305C"
#define  DC_PHY_PTG_STS_3_reg                                                    0xB80B305C
#define  DC_PHY_PTG_STS_3_inst_addr                                              "0x0017"
#define  set_DC_PHY_PTG_STS_3_reg(data)                                          (*((volatile unsigned int*)DC_PHY_PTG_STS_3_reg)=data)
#define  get_DC_PHY_PTG_STS_3_reg                                                (*((volatile unsigned int*)DC_PHY_PTG_STS_3_reg))
#define  DC_PHY_PTG_STS_3_sent_rd_cmd_shift                                      (0)
#define  DC_PHY_PTG_STS_3_sent_rd_cmd_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_STS_3_sent_rd_cmd(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_STS_3_get_sent_rd_cmd(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_RANDOM_0                                                     0x180B3060
#define  DC_PHY_PTG_RANDOM_0_reg_addr                                            "0xB80B3060"
#define  DC_PHY_PTG_RANDOM_0_reg                                                 0xB80B3060
#define  DC_PHY_PTG_RANDOM_0_inst_addr                                           "0x0018"
#define  set_DC_PHY_PTG_RANDOM_0_reg(data)                                       (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_0_reg)=data)
#define  get_DC_PHY_PTG_RANDOM_0_reg                                             (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_0_reg))
#define  DC_PHY_PTG_RANDOM_0_rnd_dat0_shift                                      (0)
#define  DC_PHY_PTG_RANDOM_0_rnd_dat0_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_RANDOM_0_rnd_dat0(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_RANDOM_0_get_rnd_dat0(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_RANDOM_1                                                     0x180B3064
#define  DC_PHY_PTG_RANDOM_1_reg_addr                                            "0xB80B3064"
#define  DC_PHY_PTG_RANDOM_1_reg                                                 0xB80B3064
#define  DC_PHY_PTG_RANDOM_1_inst_addr                                           "0x0019"
#define  set_DC_PHY_PTG_RANDOM_1_reg(data)                                       (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_1_reg)=data)
#define  get_DC_PHY_PTG_RANDOM_1_reg                                             (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_1_reg))
#define  DC_PHY_PTG_RANDOM_1_rnd_dat1_shift                                      (0)
#define  DC_PHY_PTG_RANDOM_1_rnd_dat1_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_RANDOM_1_rnd_dat1(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_RANDOM_1_get_rnd_dat1(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_RANDOM_2                                                     0x180B3068
#define  DC_PHY_PTG_RANDOM_2_reg_addr                                            "0xB80B3068"
#define  DC_PHY_PTG_RANDOM_2_reg                                                 0xB80B3068
#define  DC_PHY_PTG_RANDOM_2_inst_addr                                           "0x001A"
#define  set_DC_PHY_PTG_RANDOM_2_reg(data)                                       (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_2_reg)=data)
#define  get_DC_PHY_PTG_RANDOM_2_reg                                             (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_2_reg))
#define  DC_PHY_PTG_RANDOM_2_rnd_dat2_shift                                      (0)
#define  DC_PHY_PTG_RANDOM_2_rnd_dat2_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_RANDOM_2_rnd_dat2(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_RANDOM_2_get_rnd_dat2(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_RANDOM_3                                                     0x180B306C
#define  DC_PHY_PTG_RANDOM_3_reg_addr                                            "0xB80B306C"
#define  DC_PHY_PTG_RANDOM_3_reg                                                 0xB80B306C
#define  DC_PHY_PTG_RANDOM_3_inst_addr                                           "0x001B"
#define  set_DC_PHY_PTG_RANDOM_3_reg(data)                                       (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_3_reg)=data)
#define  get_DC_PHY_PTG_RANDOM_3_reg                                             (*((volatile unsigned int*)DC_PHY_PTG_RANDOM_3_reg))
#define  DC_PHY_PTG_RANDOM_3_rnd_dat3_shift                                      (0)
#define  DC_PHY_PTG_RANDOM_3_rnd_dat3_mask                                       (0xFFFFFFFF)
#define  DC_PHY_PTG_RANDOM_3_rnd_dat3(data)                                      (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_RANDOM_3_get_rnd_dat3(data)                                  (0xFFFFFFFF&(data))

#define  DC_PHY_PTG_CTRL_DDR                                                     0x180B3088
#define  DC_PHY_PTG_CTRL_DDR_reg_addr                                            "0xB80B3088"
#define  DC_PHY_PTG_CTRL_DDR_reg                                                 0xB80B3088
#define  DC_PHY_PTG_CTRL_DDR_inst_addr                                           "0x001C"
#define  set_DC_PHY_PTG_CTRL_DDR_reg(data)                                       (*((volatile unsigned int*)DC_PHY_PTG_CTRL_DDR_reg)=data)
#define  get_DC_PHY_PTG_CTRL_DDR_reg                                             (*((volatile unsigned int*)DC_PHY_PTG_CTRL_DDR_reg))
#define  DC_PHY_PTG_CTRL_DDR_qfifo_thr_shift                                     (8)
#define  DC_PHY_PTG_CTRL_DDR_rzv_6422_shift                                      (0)
#define  DC_PHY_PTG_CTRL_DDR_qfifo_thr_mask                                      (0x00001F00)
#define  DC_PHY_PTG_CTRL_DDR_rzv_6422_mask                                       (0x00000001)
#define  DC_PHY_PTG_CTRL_DDR_qfifo_thr(data)                                     (0x00001F00&((data)<<8))
#define  DC_PHY_PTG_CTRL_DDR_rzv_6422(data)                                      (0x00000001&(data))
#define  DC_PHY_PTG_CTRL_DDR_get_qfifo_thr(data)                                 ((0x00001F00&(data))>>8)
#define  DC_PHY_PTG_CTRL_DDR_get_rzv_6422(data)                                  (0x00000001&(data))

#define  DC_PHY_PTG_DBG                                                          0x180B30BC
#define  DC_PHY_PTG_DBG_reg_addr                                                 "0xB80B30BC"
#define  DC_PHY_PTG_DBG_reg                                                      0xB80B30BC
#define  DC_PHY_PTG_DBG_inst_addr                                                "0x001D"
#define  set_DC_PHY_PTG_DBG_reg(data)                                            (*((volatile unsigned int*)DC_PHY_PTG_DBG_reg)=data)
#define  get_DC_PHY_PTG_DBG_reg                                                  (*((volatile unsigned int*)DC_PHY_PTG_DBG_reg))
#define  DC_PHY_PTG_DBG_test_sys_en_shift                                        (28)
#define  DC_PHY_PTG_DBG_test_sys_sel2_shift                                      (24)
#define  DC_PHY_PTG_DBG_test_sys_sel1_shift                                      (20)
#define  DC_PHY_PTG_DBG_test_sys_sel0_shift                                      (16)
#define  DC_PHY_PTG_DBG_enable_shift                                             (12)
#define  DC_PHY_PTG_DBG_sel2_shift                                               (8)
#define  DC_PHY_PTG_DBG_sel1_shift                                               (4)
#define  DC_PHY_PTG_DBG_sel0_shift                                               (0)
#define  DC_PHY_PTG_DBG_test_sys_en_mask                                         (0x10000000)
#define  DC_PHY_PTG_DBG_test_sys_sel2_mask                                       (0x0F000000)
#define  DC_PHY_PTG_DBG_test_sys_sel1_mask                                       (0x00F00000)
#define  DC_PHY_PTG_DBG_test_sys_sel0_mask                                       (0x000F0000)
#define  DC_PHY_PTG_DBG_enable_mask                                              (0x00001000)
#define  DC_PHY_PTG_DBG_sel2_mask                                                (0x00000F00)
#define  DC_PHY_PTG_DBG_sel1_mask                                                (0x000000F0)
#define  DC_PHY_PTG_DBG_sel0_mask                                                (0x0000000F)
#define  DC_PHY_PTG_DBG_test_sys_en(data)                                        (0x10000000&((data)<<28))
#define  DC_PHY_PTG_DBG_test_sys_sel2(data)                                      (0x0F000000&((data)<<24))
#define  DC_PHY_PTG_DBG_test_sys_sel1(data)                                      (0x00F00000&((data)<<20))
#define  DC_PHY_PTG_DBG_test_sys_sel0(data)                                      (0x000F0000&((data)<<16))
#define  DC_PHY_PTG_DBG_enable(data)                                             (0x00001000&((data)<<12))
#define  DC_PHY_PTG_DBG_sel2(data)                                               (0x00000F00&((data)<<8))
#define  DC_PHY_PTG_DBG_sel1(data)                                               (0x000000F0&((data)<<4))
#define  DC_PHY_PTG_DBG_sel0(data)                                               (0x0000000F&(data))
#define  DC_PHY_PTG_DBG_get_test_sys_en(data)                                    ((0x10000000&(data))>>28)
#define  DC_PHY_PTG_DBG_get_test_sys_sel2(data)                                  ((0x0F000000&(data))>>24)
#define  DC_PHY_PTG_DBG_get_test_sys_sel1(data)                                  ((0x00F00000&(data))>>20)
#define  DC_PHY_PTG_DBG_get_test_sys_sel0(data)                                  ((0x000F0000&(data))>>16)
#define  DC_PHY_PTG_DBG_get_enable(data)                                         ((0x00001000&(data))>>12)
#define  DC_PHY_PTG_DBG_get_sel2(data)                                           ((0x00000F00&(data))>>8)
#define  DC_PHY_PTG_DBG_get_sel1(data)                                           ((0x000000F0&(data))>>4)
#define  DC_PHY_PTG_DBG_get_sel0(data)                                           (0x0000000F&(data))

#define  DC_PHY_PTG_WMASK                                                        0x180B3400
#define  DC_PHY_PTG_WMASK_reg_addr                                               "0xB80B3400"
#define  DC_PHY_PTG_WMASK_reg                                                    0xB80B3400
#define  DC_PHY_PTG_WMASK_inst_addr                                              "0x001E"
#define  set_DC_PHY_PTG_WMASK_reg(data)                                          (*((volatile unsigned int*)DC_PHY_PTG_WMASK_reg)=data)
#define  get_DC_PHY_PTG_WMASK_reg                                                (*((volatile unsigned int*)DC_PHY_PTG_WMASK_reg))
#define  DC_PHY_PTG_WMASK_dat_shift                                              (0)
#define  DC_PHY_PTG_WMASK_dat_mask                                               (0xFFFFFFFF)
#define  DC_PHY_PTG_WMASK_dat(data)                                              (0xFFFFFFFF&(data))
#define  DC_PHY_PTG_WMASK_get_dat(data)                                          (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC_PHY_PTG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  errstp_num:8;
        RBus_UInt32  cmdwai_num:8;
        RBus_UInt32  torept_num:8;
        RBus_UInt32  rwrept_num:8;
    };
}dc_phy_ptg_cfg_reg_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg:2;
        RBus_UInt32  cmd_tag_1_0:2;
        RBus_UInt32  ini_mod:3;
        RBus_UInt32  inc_bak:2;
        RBus_UInt32  ini_bak:3;
        RBus_UInt32  ini_y:2;
        RBus_UInt32  ini_x:1;
        RBus_UInt32  ini_ddr:1;
        RBus_UInt32  door:7;
        RBus_UInt32  slflopback:1;
        RBus_UInt32  phylopback:1;
        RBus_UInt32  torept_cti:1;
        RBus_UInt32  rcv_closed:1;
        RBus_UInt32  xmt_closed:1;
        RBus_UInt32  tst_st:3;
        RBus_UInt32  tst_strt:1;
    };
}dc_phy_ptg_cfg_reg_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ini_wr:1;
        RBus_UInt32  inc_col:4;
        RBus_UInt32  ini_col:10;
        RBus_UInt32  inc_bl:3;
        RBus_UInt32  ini_bl:5;
    };
}dc_phy_ptg_cfg_reg_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cmd_id_4:1;
        RBus_UInt32  cmd_tag_3_2:2;
        RBus_UInt32  inc_pag:3;
        RBus_UInt32  ini_pag:17;
    };
}dc_phy_ptg_cfg_reg_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sa_rcverr:4;
        RBus_UInt32  cnt_rcverr:8;
    };
}dc_phy_ptg_cfg_reg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  clr_fail_cmd:1;
        RBus_UInt32  en_cap_fail_cmd:1;
        RBus_UInt32  cmp_err_flag:1;
        RBus_UInt32  scramble_en:1;
        RBus_UInt32  pause:1;
        RBus_UInt32  sw_en:1;
    };
}dc_phy_ptg_hw_sw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cmd_num:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  cmp_fail_stop_num:1;
        RBus_UInt32  go:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rpt_num:8;
    };
}dc_phy_ptg_cmd_sram_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  write_en:1;
        RBus_UInt32  en_sw_acc:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sw:6;
    };
}dc_phy_ptg_cmd_sram_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmd_sram_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cmp_dat:3;
        RBus_UInt32  dat:19;
    };
}dc_phy_ptg_cmd_sram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_dat:32;
    };
}dc_phy_ptg_cmp_fail_cmd_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wmask:16;
        RBus_UInt32  cmp_dat:16;
    };
}dc_phy_ptg_cmp_fail_cmd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_cmd:32;
    };
}dc_phy_ptg_sts_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_cmd:32;
    };
}dc_phy_ptg_sts_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_wr_cmd:32;
    };
}dc_phy_ptg_sts_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_rd_cmd:32;
    };
}dc_phy_ptg_sts_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat0:32;
    };
}dc_phy_ptg_random_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat1:32;
    };
}dc_phy_ptg_random_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat2:32;
    };
}dc_phy_ptg_random_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat3:32;
    };
}dc_phy_ptg_random_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  qfifo_thr:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  rzv_6422:1;
    };
}dc_phy_ptg_ctrl_ddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  test_sys_en:1;
        RBus_UInt32  test_sys_sel2:4;
        RBus_UInt32  test_sys_sel1:4;
        RBus_UInt32  test_sys_sel0:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  enable:1;
        RBus_UInt32  sel2:4;
        RBus_UInt32  sel1:4;
        RBus_UInt32  sel0:4;
    };
}dc_phy_ptg_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_wmask_RBUS;

#else //apply LITTLE_ENDIAN

//======DC_PHY_PTG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rwrept_num:8;
        RBus_UInt32  torept_num:8;
        RBus_UInt32  cmdwai_num:8;
        RBus_UInt32  errstp_num:8;
    };
}dc_phy_ptg_cfg_reg_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tst_strt:1;
        RBus_UInt32  tst_st:3;
        RBus_UInt32  xmt_closed:1;
        RBus_UInt32  rcv_closed:1;
        RBus_UInt32  torept_cti:1;
        RBus_UInt32  phylopback:1;
        RBus_UInt32  slflopback:1;
        RBus_UInt32  door:7;
        RBus_UInt32  ini_ddr:1;
        RBus_UInt32  ini_x:1;
        RBus_UInt32  ini_y:2;
        RBus_UInt32  ini_bak:3;
        RBus_UInt32  inc_bak:2;
        RBus_UInt32  ini_mod:3;
        RBus_UInt32  cmd_tag_1_0:2;
        RBus_UInt32  dummy_reg:2;
    };
}dc_phy_ptg_cfg_reg_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_bl:5;
        RBus_UInt32  inc_bl:3;
        RBus_UInt32  ini_col:10;
        RBus_UInt32  inc_col:4;
        RBus_UInt32  ini_wr:1;
        RBus_UInt32  res1:9;
    };
}dc_phy_ptg_cfg_reg_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ini_pag:17;
        RBus_UInt32  inc_pag:3;
        RBus_UInt32  cmd_tag_3_2:2;
        RBus_UInt32  cmd_id_4:1;
        RBus_UInt32  res1:9;
    };
}dc_phy_ptg_cfg_reg_0c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_rcverr:8;
        RBus_UInt32  sa_rcverr:4;
        RBus_UInt32  res1:20;
    };
}dc_phy_ptg_cfg_reg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_en:1;
        RBus_UInt32  pause:1;
        RBus_UInt32  scramble_en:1;
        RBus_UInt32  cmp_err_flag:1;
        RBus_UInt32  en_cap_fail_cmd:1;
        RBus_UInt32  clr_fail_cmd:1;
        RBus_UInt32  res1:26;
    };
}dc_phy_ptg_hw_sw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rpt_num:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  go:1;
        RBus_UInt32  cmp_fail_stop_num:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cmd_num:7;
        RBus_UInt32  res3:9;
    };
}dc_phy_ptg_cmd_sram_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  en_sw_acc:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res2:22;
    };
}dc_phy_ptg_cmd_sram_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmd_sram_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:19;
        RBus_UInt32  cmp_dat:3;
        RBus_UInt32  res1:10;
    };
}dc_phy_ptg_cmd_sram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_dat:32;
    };
}dc_phy_ptg_cmp_fail_cmd_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_dat:16;
        RBus_UInt32  wmask:16;
    };
}dc_phy_ptg_cmp_fail_cmd_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_exp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_cmp_fail_read_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_cmd:32;
    };
}dc_phy_ptg_sts_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_cmd:32;
    };
}dc_phy_ptg_sts_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_wr_cmd:32;
    };
}dc_phy_ptg_sts_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sent_rd_cmd:32;
    };
}dc_phy_ptg_sts_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat0:32;
    };
}dc_phy_ptg_random_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat1:32;
    };
}dc_phy_ptg_random_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat2:32;
    };
}dc_phy_ptg_random_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rnd_dat3:32;
    };
}dc_phy_ptg_random_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rzv_6422:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  qfifo_thr:5;
        RBus_UInt32  res2:19;
    };
}dc_phy_ptg_ctrl_ddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel0:4;
        RBus_UInt32  sel1:4;
        RBus_UInt32  sel2:4;
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  test_sys_sel0:4;
        RBus_UInt32  test_sys_sel1:4;
        RBus_UInt32  test_sys_sel2:4;
        RBus_UInt32  test_sys_en:1;
        RBus_UInt32  res2:3;
    };
}dc_phy_ptg_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat:32;
    };
}dc_phy_ptg_wmask_RBUS;




#endif 


#endif 
