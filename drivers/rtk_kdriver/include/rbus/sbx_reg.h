/**
* @file Mac5-DesignSpec-SBX
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SBX_REG_H_
#define _RBUS_SBX_REG_H_

#include "rbus_types.h"



//  SBX Register Address
#define  SBX_sb1_pri_0                                                           0x1801C000
#define  SBX_sb1_pri_0_reg_addr                                                  "0xB801C000"
#define  SBX_sb1_pri_0_reg                                                       0xB801C000
#define  SBX_sb1_pri_0_inst_addr                                                 "0x0000"
#define  set_SBX_sb1_pri_0_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_0_reg)=data)
#define  get_SBX_sb1_pri_0_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_0_reg))
#define  SBX_sb1_pri_0_sb1_c0_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_0_sb1_c0_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_0_sb1_c0_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_0_sb1_c0_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_0_sb1_c0_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_0_sb1_c0_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_0_get_sb1_c0_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_0_get_sb1_c0_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_1                                                           0x1801C004
#define  SBX_sb1_pri_1_reg_addr                                                  "0xB801C004"
#define  SBX_sb1_pri_1_reg                                                       0xB801C004
#define  SBX_sb1_pri_1_inst_addr                                                 "0x0001"
#define  set_SBX_sb1_pri_1_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_1_reg)=data)
#define  get_SBX_sb1_pri_1_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_1_reg))
#define  SBX_sb1_pri_1_sb1_c1_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_1_sb1_c1_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_1_sb1_c1_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_1_sb1_c1_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_1_sb1_c1_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_1_sb1_c1_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_1_get_sb1_c1_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_1_get_sb1_c1_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_2                                                           0x1801C008
#define  SBX_sb1_pri_2_reg_addr                                                  "0xB801C008"
#define  SBX_sb1_pri_2_reg                                                       0xB801C008
#define  SBX_sb1_pri_2_inst_addr                                                 "0x0002"
#define  set_SBX_sb1_pri_2_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_2_reg)=data)
#define  get_SBX_sb1_pri_2_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_2_reg))
#define  SBX_sb1_pri_2_sb1_c2_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_2_sb1_c2_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_2_sb1_c2_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_2_sb1_c2_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_2_sb1_c2_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_2_sb1_c2_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_2_get_sb1_c2_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_2_get_sb1_c2_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_3                                                           0x1801C00C
#define  SBX_sb1_pri_3_reg_addr                                                  "0xB801C00C"
#define  SBX_sb1_pri_3_reg                                                       0xB801C00C
#define  SBX_sb1_pri_3_inst_addr                                                 "0x0003"
#define  set_SBX_sb1_pri_3_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_3_reg)=data)
#define  get_SBX_sb1_pri_3_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_3_reg))
#define  SBX_sb1_pri_3_sb1_c3_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_3_sb1_c3_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_3_sb1_c3_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_3_sb1_c3_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_3_sb1_c3_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_3_sb1_c3_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_3_get_sb1_c3_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_3_get_sb1_c3_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_4                                                           0x1801C010
#define  SBX_sb1_pri_4_reg_addr                                                  "0xB801C010"
#define  SBX_sb1_pri_4_reg                                                       0xB801C010
#define  SBX_sb1_pri_4_inst_addr                                                 "0x0004"
#define  set_SBX_sb1_pri_4_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_4_reg)=data)
#define  get_SBX_sb1_pri_4_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_4_reg))
#define  SBX_sb1_pri_4_sb1_c4_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_4_sb1_c4_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_4_sb1_c4_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_4_sb1_c4_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_4_sb1_c4_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_4_sb1_c4_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_4_get_sb1_c4_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_4_get_sb1_c4_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_5                                                           0x1801C014
#define  SBX_sb1_pri_5_reg_addr                                                  "0xB801C014"
#define  SBX_sb1_pri_5_reg                                                       0xB801C014
#define  SBX_sb1_pri_5_inst_addr                                                 "0x0005"
#define  set_SBX_sb1_pri_5_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_5_reg)=data)
#define  get_SBX_sb1_pri_5_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_5_reg))
#define  SBX_sb1_pri_5_sb1_c5_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_5_sb1_c5_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_5_sb1_c5_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_5_sb1_c5_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_5_sb1_c5_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_5_sb1_c5_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_5_get_sb1_c5_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_5_get_sb1_c5_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_6                                                           0x1801C018
#define  SBX_sb1_pri_6_reg_addr                                                  "0xB801C018"
#define  SBX_sb1_pri_6_reg                                                       0xB801C018
#define  SBX_sb1_pri_6_inst_addr                                                 "0x0006"
#define  set_SBX_sb1_pri_6_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_6_reg)=data)
#define  get_SBX_sb1_pri_6_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_6_reg))
#define  SBX_sb1_pri_6_sb1_c6_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_6_sb1_c6_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_6_sb1_c6_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_6_sb1_c6_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_6_sb1_c6_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_6_sb1_c6_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_6_get_sb1_c6_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_6_get_sb1_c6_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_7                                                           0x1801C01C
#define  SBX_sb1_pri_7_reg_addr                                                  "0xB801C01C"
#define  SBX_sb1_pri_7_reg                                                       0xB801C01C
#define  SBX_sb1_pri_7_inst_addr                                                 "0x0007"
#define  set_SBX_sb1_pri_7_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_7_reg)=data)
#define  get_SBX_sb1_pri_7_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_7_reg))
#define  SBX_sb1_pri_7_sb1_c7_latcnt_end_shift                                   (16)
#define  SBX_sb1_pri_7_sb1_c7_latcnt_beg_shift                                   (0)
#define  SBX_sb1_pri_7_sb1_c7_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb1_pri_7_sb1_c7_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb1_pri_7_sb1_c7_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb1_pri_7_sb1_c7_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb1_pri_7_get_sb1_c7_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb1_pri_7_get_sb1_c7_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb1_pri_8                                                           0x1801C020
#define  SBX_sb1_pri_8_reg_addr                                                  "0xB801C020"
#define  SBX_sb1_pri_8_reg                                                       0xB801C020
#define  SBX_sb1_pri_8_inst_addr                                                 "0x0008"
#define  set_SBX_sb1_pri_8_reg(data)                                             (*((volatile unsigned int*)SBX_sb1_pri_8_reg)=data)
#define  get_SBX_sb1_pri_8_reg                                                   (*((volatile unsigned int*)SBX_sb1_pri_8_reg))
#define  SBX_sb1_pri_8_sb1_pri_cnt_period_shift                                  (0)
#define  SBX_sb1_pri_8_sb1_pri_cnt_period_mask                                   (0x000000FF)
#define  SBX_sb1_pri_8_sb1_pri_cnt_period(data)                                  (0x000000FF&(data))
#define  SBX_sb1_pri_8_get_sb1_pri_cnt_period(data)                              (0x000000FF&(data))

#define  SBX_sb1_channel_0                                                       0x1801C024
#define  SBX_sb1_channel_0_reg_addr                                              "0xB801C024"
#define  SBX_sb1_channel_0_reg                                                   0xB801C024
#define  SBX_sb1_channel_0_inst_addr                                             "0x0009"
#define  set_SBX_sb1_channel_0_reg(data)                                         (*((volatile unsigned int*)SBX_sb1_channel_0_reg)=data)
#define  get_SBX_sb1_channel_0_reg                                               (*((volatile unsigned int*)SBX_sb1_channel_0_reg))
#define  SBX_sb1_channel_0_sb1_req_mask_index_shift                              (0)
#define  SBX_sb1_channel_0_sb1_req_mask_index_mask                               (0x000000FF)
#define  SBX_sb1_channel_0_sb1_req_mask_index(data)                              (0x000000FF&(data))
#define  SBX_sb1_channel_0_get_sb1_req_mask_index(data)                          (0x000000FF&(data))

#define  SBX_sb1_channel_1                                                       0x1801C028
#define  SBX_sb1_channel_1_reg_addr                                              "0xB801C028"
#define  SBX_sb1_channel_1_reg                                                   0xB801C028
#define  SBX_sb1_channel_1_inst_addr                                             "0x000A"
#define  set_SBX_sb1_channel_1_reg(data)                                         (*((volatile unsigned int*)SBX_sb1_channel_1_reg)=data)
#define  get_SBX_sb1_channel_1_reg                                               (*((volatile unsigned int*)SBX_sb1_channel_1_reg))
#define  SBX_sb1_channel_1_sb1_req_busy_index_shift                              (0)
#define  SBX_sb1_channel_1_sb1_req_busy_index_mask                               (0x000000FF)
#define  SBX_sb1_channel_1_sb1_req_busy_index(data)                              (0x000000FF&(data))
#define  SBX_sb1_channel_1_get_sb1_req_busy_index(data)                          (0x000000FF&(data))

#define  SBX_sb1_misc_ctrl                                                       0x1801C02C
#define  SBX_sb1_misc_ctrl_reg_addr                                              "0xB801C02C"
#define  SBX_sb1_misc_ctrl_reg                                                   0xB801C02C
#define  SBX_sb1_misc_ctrl_inst_addr                                             "0x000B"
#define  set_SBX_sb1_misc_ctrl_reg(data)                                         (*((volatile unsigned int*)SBX_sb1_misc_ctrl_reg)=data)
#define  get_SBX_sb1_misc_ctrl_reg                                               (*((volatile unsigned int*)SBX_sb1_misc_ctrl_reg))
#define  SBX_sb1_misc_ctrl_sb1_allow_cmd_cnt_shift                               (0)
#define  SBX_sb1_misc_ctrl_sb1_allow_cmd_cnt_mask                                (0x00000007)
#define  SBX_sb1_misc_ctrl_sb1_allow_cmd_cnt(data)                               (0x00000007&(data))
#define  SBX_sb1_misc_ctrl_get_sb1_allow_cmd_cnt(data)                           (0x00000007&(data))

#define  SBX_sb1_sftx_test0                                                      0x1801C040
#define  SBX_sb1_sftx_test0_reg_addr                                             "0xB801C040"
#define  SBX_sb1_sftx_test0_reg                                                  0xB801C040
#define  SBX_sb1_sftx_test0_inst_addr                                            "0x000C"
#define  set_SBX_sb1_sftx_test0_reg(data)                                        (*((volatile unsigned int*)SBX_sb1_sftx_test0_reg)=data)
#define  get_SBX_sb1_sftx_test0_reg                                              (*((volatile unsigned int*)SBX_sb1_sftx_test0_reg))
#define  SBX_sb1_sftx_test0_sf_tx_mode_emmc_shift                                (7)
#define  SBX_sb1_sftx_test0_dummy_6_shift                                        (6)
#define  SBX_sb1_sftx_test0_sf_tx_mode_etn_shift                                 (5)
#define  SBX_sb1_sftx_test0_dummy_4_3_shift                                      (3)
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb_shift                                 (2)
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb_ex_shift                              (1)
#define  SBX_sb1_sftx_test0_sf_tx_mode_ssb1_shift                                (0)
#define  SBX_sb1_sftx_test0_sf_tx_mode_emmc_mask                                 (0x00000080)
#define  SBX_sb1_sftx_test0_dummy_6_mask                                         (0x00000040)
#define  SBX_sb1_sftx_test0_sf_tx_mode_etn_mask                                  (0x00000020)
#define  SBX_sb1_sftx_test0_dummy_4_3_mask                                       (0x00000018)
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb_mask                                  (0x00000004)
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb_ex_mask                               (0x00000002)
#define  SBX_sb1_sftx_test0_sf_tx_mode_ssb1_mask                                 (0x00000001)
#define  SBX_sb1_sftx_test0_sf_tx_mode_emmc(data)                                (0x00000080&((data)<<7))
#define  SBX_sb1_sftx_test0_dummy_6(data)                                        (0x00000040&((data)<<6))
#define  SBX_sb1_sftx_test0_sf_tx_mode_etn(data)                                 (0x00000020&((data)<<5))
#define  SBX_sb1_sftx_test0_dummy_4_3(data)                                      (0x00000018&((data)<<3))
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb(data)                                 (0x00000004&((data)<<2))
#define  SBX_sb1_sftx_test0_sf_tx_mode_usb_ex(data)                              (0x00000002&((data)<<1))
#define  SBX_sb1_sftx_test0_sf_tx_mode_ssb1(data)                                (0x00000001&(data))
#define  SBX_sb1_sftx_test0_get_sf_tx_mode_emmc(data)                            ((0x00000080&(data))>>7)
#define  SBX_sb1_sftx_test0_get_dummy_6(data)                                    ((0x00000040&(data))>>6)
#define  SBX_sb1_sftx_test0_get_sf_tx_mode_etn(data)                             ((0x00000020&(data))>>5)
#define  SBX_sb1_sftx_test0_get_dummy_4_3(data)                                  ((0x00000018&(data))>>3)
#define  SBX_sb1_sftx_test0_get_sf_tx_mode_usb(data)                             ((0x00000004&(data))>>2)
#define  SBX_sb1_sftx_test0_get_sf_tx_mode_usb_ex(data)                          ((0x00000002&(data))>>1)
#define  SBX_sb1_sftx_test0_get_sf_tx_mode_ssb1(data)                            (0x00000001&(data))

#define  SBX_sb1_sftx_test1                                                      0x1801C044
#define  SBX_sb1_sftx_test1_reg_addr                                             "0xB801C044"
#define  SBX_sb1_sftx_test1_reg                                                  0xB801C044
#define  SBX_sb1_sftx_test1_inst_addr                                            "0x000D"
#define  set_SBX_sb1_sftx_test1_reg(data)                                        (*((volatile unsigned int*)SBX_sb1_sftx_test1_reg)=data)
#define  get_SBX_sb1_sftx_test1_reg                                              (*((volatile unsigned int*)SBX_sb1_sftx_test1_reg))
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_emmc_shift                             (23)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_etn_shift                              (21)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb_shift                              (18)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb_ex_shift                           (17)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_ssb1_shift                             (16)
#define  SBX_sb1_sftx_test1_sf_tx_start_emmc_shift                               (7)
#define  SBX_sb1_sftx_test1_dummy_6_shift                                        (6)
#define  SBX_sb1_sftx_test1_sf_tx_start_etn_shift                                (5)
#define  SBX_sb1_sftx_test1_dummy_4_3_shift                                      (3)
#define  SBX_sb1_sftx_test1_sf_tx_start_usb_shift                                (2)
#define  SBX_sb1_sftx_test1_sf_tx_start_usb_ex_shift                             (1)
#define  SBX_sb1_sftx_test1_sf_tx_start_ssb1_shift                               (0)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_emmc_mask                              (0x00800000)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_etn_mask                               (0x00200000)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb_mask                               (0x00040000)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb_ex_mask                            (0x00020000)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_ssb1_mask                              (0x00010000)
#define  SBX_sb1_sftx_test1_sf_tx_start_emmc_mask                                (0x00000080)
#define  SBX_sb1_sftx_test1_dummy_6_mask                                         (0x00000040)
#define  SBX_sb1_sftx_test1_sf_tx_start_etn_mask                                 (0x00000020)
#define  SBX_sb1_sftx_test1_dummy_4_3_mask                                       (0x00000018)
#define  SBX_sb1_sftx_test1_sf_tx_start_usb_mask                                 (0x00000004)
#define  SBX_sb1_sftx_test1_sf_tx_start_usb_ex_mask                              (0x00000002)
#define  SBX_sb1_sftx_test1_sf_tx_start_ssb1_mask                                (0x00000001)
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_emmc(data)                             (0x00800000&((data)<<23))
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_etn(data)                              (0x00200000&((data)<<21))
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb(data)                              (0x00040000&((data)<<18))
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_usb_ex(data)                           (0x00020000&((data)<<17))
#define  SBX_sb1_sftx_test1_sf_tx_work_ro_ssb1(data)                             (0x00010000&((data)<<16))
#define  SBX_sb1_sftx_test1_sf_tx_start_emmc(data)                               (0x00000080&((data)<<7))
#define  SBX_sb1_sftx_test1_dummy_6(data)                                        (0x00000040&((data)<<6))
#define  SBX_sb1_sftx_test1_sf_tx_start_etn(data)                                (0x00000020&((data)<<5))
#define  SBX_sb1_sftx_test1_dummy_4_3(data)                                      (0x00000018&((data)<<3))
#define  SBX_sb1_sftx_test1_sf_tx_start_usb(data)                                (0x00000004&((data)<<2))
#define  SBX_sb1_sftx_test1_sf_tx_start_usb_ex(data)                             (0x00000002&((data)<<1))
#define  SBX_sb1_sftx_test1_sf_tx_start_ssb1(data)                               (0x00000001&(data))
#define  SBX_sb1_sftx_test1_get_sf_tx_work_ro_emmc(data)                         ((0x00800000&(data))>>23)
#define  SBX_sb1_sftx_test1_get_sf_tx_work_ro_etn(data)                          ((0x00200000&(data))>>21)
#define  SBX_sb1_sftx_test1_get_sf_tx_work_ro_usb(data)                          ((0x00040000&(data))>>18)
#define  SBX_sb1_sftx_test1_get_sf_tx_work_ro_usb_ex(data)                       ((0x00020000&(data))>>17)
#define  SBX_sb1_sftx_test1_get_sf_tx_work_ro_ssb1(data)                         ((0x00010000&(data))>>16)
#define  SBX_sb1_sftx_test1_get_sf_tx_start_emmc(data)                           ((0x00000080&(data))>>7)
#define  SBX_sb1_sftx_test1_get_dummy_6(data)                                    ((0x00000040&(data))>>6)
#define  SBX_sb1_sftx_test1_get_sf_tx_start_etn(data)                            ((0x00000020&(data))>>5)
#define  SBX_sb1_sftx_test1_get_dummy_4_3(data)                                  ((0x00000018&(data))>>3)
#define  SBX_sb1_sftx_test1_get_sf_tx_start_usb(data)                            ((0x00000004&(data))>>2)
#define  SBX_sb1_sftx_test1_get_sf_tx_start_usb_ex(data)                         ((0x00000002&(data))>>1)
#define  SBX_sb1_sftx_test1_get_sf_tx_start_ssb1(data)                           (0x00000001&(data))

#define  SBX_sb1_sfrx_test0                                                      0x1801C048
#define  SBX_sb1_sfrx_test0_reg_addr                                             "0xB801C048"
#define  SBX_sb1_sfrx_test0_reg                                                  0xB801C048
#define  SBX_sb1_sfrx_test0_inst_addr                                            "0x000E"
#define  set_SBX_sb1_sfrx_test0_reg(data)                                        (*((volatile unsigned int*)SBX_sb1_sfrx_test0_reg)=data)
#define  get_SBX_sb1_sfrx_test0_reg                                              (*((volatile unsigned int*)SBX_sb1_sfrx_test0_reg))
#define  SBX_sb1_sfrx_test0_sf_rx_gated_emmc_shift                               (23)
#define  SBX_sb1_sfrx_test0_dummy_22_shift                                       (22)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_etn_shift                                (21)
#define  SBX_sb1_sfrx_test0_dummy_20_19_shift                                    (19)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb_shift                                (18)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb_ex_shift                             (17)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_ssb1_shift                               (16)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_emmc_shift                                (7)
#define  SBX_sb1_sfrx_test0_dummy_6_shift                                        (6)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_etn_shift                                 (5)
#define  SBX_sb1_sfrx_test0_dummy_4_3_shift                                      (3)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb_shift                                 (2)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb_ex_shift                              (1)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_ssb1_shift                                (0)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_emmc_mask                                (0x00800000)
#define  SBX_sb1_sfrx_test0_dummy_22_mask                                        (0x00400000)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_etn_mask                                 (0x00200000)
#define  SBX_sb1_sfrx_test0_dummy_20_19_mask                                     (0x00180000)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb_mask                                 (0x00040000)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb_ex_mask                              (0x00020000)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_ssb1_mask                                (0x00010000)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_emmc_mask                                 (0x00000080)
#define  SBX_sb1_sfrx_test0_dummy_6_mask                                         (0x00000040)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_etn_mask                                  (0x00000020)
#define  SBX_sb1_sfrx_test0_dummy_4_3_mask                                       (0x00000018)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb_mask                                  (0x00000004)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb_ex_mask                               (0x00000002)
#define  SBX_sb1_sfrx_test0_sf_rx_mode_ssb1_mask                                 (0x00000001)
#define  SBX_sb1_sfrx_test0_sf_rx_gated_emmc(data)                               (0x00800000&((data)<<23))
#define  SBX_sb1_sfrx_test0_dummy_22(data)                                       (0x00400000&((data)<<22))
#define  SBX_sb1_sfrx_test0_sf_rx_gated_etn(data)                                (0x00200000&((data)<<21))
#define  SBX_sb1_sfrx_test0_dummy_20_19(data)                                    (0x00180000&((data)<<19))
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb(data)                                (0x00040000&((data)<<18))
#define  SBX_sb1_sfrx_test0_sf_rx_gated_usb_ex(data)                             (0x00020000&((data)<<17))
#define  SBX_sb1_sfrx_test0_sf_rx_gated_ssb1(data)                               (0x00010000&((data)<<16))
#define  SBX_sb1_sfrx_test0_sf_rx_mode_emmc(data)                                (0x00000080&((data)<<7))
#define  SBX_sb1_sfrx_test0_dummy_6(data)                                        (0x00000040&((data)<<6))
#define  SBX_sb1_sfrx_test0_sf_rx_mode_etn(data)                                 (0x00000020&((data)<<5))
#define  SBX_sb1_sfrx_test0_dummy_4_3(data)                                      (0x00000018&((data)<<3))
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb(data)                                 (0x00000004&((data)<<2))
#define  SBX_sb1_sfrx_test0_sf_rx_mode_usb_ex(data)                              (0x00000002&((data)<<1))
#define  SBX_sb1_sfrx_test0_sf_rx_mode_ssb1(data)                                (0x00000001&(data))
#define  SBX_sb1_sfrx_test0_get_sf_rx_gated_emmc(data)                           ((0x00800000&(data))>>23)
#define  SBX_sb1_sfrx_test0_get_dummy_22(data)                                   ((0x00400000&(data))>>22)
#define  SBX_sb1_sfrx_test0_get_sf_rx_gated_etn(data)                            ((0x00200000&(data))>>21)
#define  SBX_sb1_sfrx_test0_get_dummy_20_19(data)                                ((0x00180000&(data))>>19)
#define  SBX_sb1_sfrx_test0_get_sf_rx_gated_usb(data)                            ((0x00040000&(data))>>18)
#define  SBX_sb1_sfrx_test0_get_sf_rx_gated_usb_ex(data)                         ((0x00020000&(data))>>17)
#define  SBX_sb1_sfrx_test0_get_sf_rx_gated_ssb1(data)                           ((0x00010000&(data))>>16)
#define  SBX_sb1_sfrx_test0_get_sf_rx_mode_emmc(data)                            ((0x00000080&(data))>>7)
#define  SBX_sb1_sfrx_test0_get_dummy_6(data)                                    ((0x00000040&(data))>>6)
#define  SBX_sb1_sfrx_test0_get_sf_rx_mode_etn(data)                             ((0x00000020&(data))>>5)
#define  SBX_sb1_sfrx_test0_get_dummy_4_3(data)                                  ((0x00000018&(data))>>3)
#define  SBX_sb1_sfrx_test0_get_sf_rx_mode_usb(data)                             ((0x00000004&(data))>>2)
#define  SBX_sb1_sfrx_test0_get_sf_rx_mode_usb_ex(data)                          ((0x00000002&(data))>>1)
#define  SBX_sb1_sfrx_test0_get_sf_rx_mode_ssb1(data)                            (0x00000001&(data))

#define  SBX_sb1_sfrx_test1                                                      0x1801C04C
#define  SBX_sb1_sfrx_test1_reg_addr                                             "0xB801C04C"
#define  SBX_sb1_sfrx_test1_reg                                                  0xB801C04C
#define  SBX_sb1_sfrx_test1_inst_addr                                            "0x000F"
#define  set_SBX_sb1_sfrx_test1_reg(data)                                        (*((volatile unsigned int*)SBX_sb1_sfrx_test1_reg)=data)
#define  get_SBX_sb1_sfrx_test1_reg                                              (*((volatile unsigned int*)SBX_sb1_sfrx_test1_reg))
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_emmc_shift                             (23)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_etn_shift                              (21)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb_shift                              (18)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb_ex_shift                           (17)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_ssb1_shift                             (16)
#define  SBX_sb1_sfrx_test1_sf_rx_start_emmc_shift                               (7)
#define  SBX_sb1_sfrx_test1_dummy_6_shift                                        (6)
#define  SBX_sb1_sfrx_test1_sf_rx_start_etn_shift                                (5)
#define  SBX_sb1_sfrx_test1_dummy_4_3_shift                                      (3)
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb_shift                                (2)
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb_ex_shift                             (1)
#define  SBX_sb1_sfrx_test1_sf_rx_start_ssb1_shift                               (0)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_emmc_mask                              (0x00800000)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_etn_mask                               (0x00200000)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb_mask                               (0x00040000)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb_ex_mask                            (0x00020000)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_ssb1_mask                              (0x00010000)
#define  SBX_sb1_sfrx_test1_sf_rx_start_emmc_mask                                (0x00000080)
#define  SBX_sb1_sfrx_test1_dummy_6_mask                                         (0x00000040)
#define  SBX_sb1_sfrx_test1_sf_rx_start_etn_mask                                 (0x00000020)
#define  SBX_sb1_sfrx_test1_dummy_4_3_mask                                       (0x00000018)
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb_mask                                 (0x00000004)
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb_ex_mask                              (0x00000002)
#define  SBX_sb1_sfrx_test1_sf_rx_start_ssb1_mask                                (0x00000001)
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_emmc(data)                             (0x00800000&((data)<<23))
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_etn(data)                              (0x00200000&((data)<<21))
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb(data)                              (0x00040000&((data)<<18))
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_usb_ex(data)                           (0x00020000&((data)<<17))
#define  SBX_sb1_sfrx_test1_sf_rx_done_ro_ssb1(data)                             (0x00010000&((data)<<16))
#define  SBX_sb1_sfrx_test1_sf_rx_start_emmc(data)                               (0x00000080&((data)<<7))
#define  SBX_sb1_sfrx_test1_dummy_6(data)                                        (0x00000040&((data)<<6))
#define  SBX_sb1_sfrx_test1_sf_rx_start_etn(data)                                (0x00000020&((data)<<5))
#define  SBX_sb1_sfrx_test1_dummy_4_3(data)                                      (0x00000018&((data)<<3))
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb(data)                                (0x00000004&((data)<<2))
#define  SBX_sb1_sfrx_test1_sf_rx_start_usb_ex(data)                             (0x00000002&((data)<<1))
#define  SBX_sb1_sfrx_test1_sf_rx_start_ssb1(data)                               (0x00000001&(data))
#define  SBX_sb1_sfrx_test1_get_sf_rx_done_ro_emmc(data)                         ((0x00800000&(data))>>23)
#define  SBX_sb1_sfrx_test1_get_sf_rx_done_ro_etn(data)                          ((0x00200000&(data))>>21)
#define  SBX_sb1_sfrx_test1_get_sf_rx_done_ro_usb(data)                          ((0x00040000&(data))>>18)
#define  SBX_sb1_sfrx_test1_get_sf_rx_done_ro_usb_ex(data)                       ((0x00020000&(data))>>17)
#define  SBX_sb1_sfrx_test1_get_sf_rx_done_ro_ssb1(data)                         ((0x00010000&(data))>>16)
#define  SBX_sb1_sfrx_test1_get_sf_rx_start_emmc(data)                           ((0x00000080&(data))>>7)
#define  SBX_sb1_sfrx_test1_get_dummy_6(data)                                    ((0x00000040&(data))>>6)
#define  SBX_sb1_sfrx_test1_get_sf_rx_start_etn(data)                            ((0x00000020&(data))>>5)
#define  SBX_sb1_sfrx_test1_get_dummy_4_3(data)                                  ((0x00000018&(data))>>3)
#define  SBX_sb1_sfrx_test1_get_sf_rx_start_usb(data)                            ((0x00000004&(data))>>2)
#define  SBX_sb1_sfrx_test1_get_sf_rx_start_usb_ex(data)                         ((0x00000002&(data))>>1)
#define  SBX_sb1_sfrx_test1_get_sf_rx_start_ssb1(data)                           (0x00000001&(data))

#define  SBX_sb1_sfrx_test2                                                      0x1801C050
#define  SBX_sb1_sfrx_test2_reg_addr                                             "0xB801C050"
#define  SBX_sb1_sfrx_test2_reg                                                  0xB801C050
#define  SBX_sb1_sfrx_test2_inst_addr                                            "0x0010"
#define  set_SBX_sb1_sfrx_test2_reg(data)                                        (*((volatile unsigned int*)SBX_sb1_sfrx_test2_reg)=data)
#define  get_SBX_sb1_sfrx_test2_reg                                              (*((volatile unsigned int*)SBX_sb1_sfrx_test2_reg))
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_emmc_shift                              (7)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_etn_shift                               (5)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb_shift                               (2)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb_ex_shift                            (1)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_ssb1_shift                              (0)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_emmc_mask                               (0x00000080)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_etn_mask                                (0x00000020)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb_mask                                (0x00000004)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb_ex_mask                             (0x00000002)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_ssb1_mask                               (0x00000001)
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_emmc(data)                              (0x00000080&((data)<<7))
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_etn(data)                               (0x00000020&((data)<<5))
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb(data)                               (0x00000004&((data)<<2))
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_usb_ex(data)                            (0x00000002&((data)<<1))
#define  SBX_sb1_sfrx_test2_sf_rx_err_ro_ssb1(data)                              (0x00000001&(data))
#define  SBX_sb1_sfrx_test2_get_sf_rx_err_ro_emmc(data)                          ((0x00000080&(data))>>7)
#define  SBX_sb1_sfrx_test2_get_sf_rx_err_ro_etn(data)                           ((0x00000020&(data))>>5)
#define  SBX_sb1_sfrx_test2_get_sf_rx_err_ro_usb(data)                           ((0x00000004&(data))>>2)
#define  SBX_sb1_sfrx_test2_get_sf_rx_err_ro_usb_ex(data)                        ((0x00000002&(data))>>1)
#define  SBX_sb1_sfrx_test2_get_sf_rx_err_ro_ssb1(data)                          (0x00000001&(data))

#define  SBX_sb3_pri_0                                                           0x1801C200
#define  SBX_sb3_pri_0_reg_addr                                                  "0xB801C200"
#define  SBX_sb3_pri_0_reg                                                       0xB801C200
#define  SBX_sb3_pri_0_inst_addr                                                 "0x0011"
#define  set_SBX_sb3_pri_0_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_0_reg)=data)
#define  get_SBX_sb3_pri_0_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_0_reg))
#define  SBX_sb3_pri_0_sb3_c0_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_0_sb3_c0_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_0_sb3_c0_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_0_sb3_c0_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_0_sb3_c0_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_0_sb3_c0_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_0_get_sb3_c0_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_0_get_sb3_c0_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_1                                                           0x1801C204
#define  SBX_sb3_pri_1_reg_addr                                                  "0xB801C204"
#define  SBX_sb3_pri_1_reg                                                       0xB801C204
#define  SBX_sb3_pri_1_inst_addr                                                 "0x0012"
#define  set_SBX_sb3_pri_1_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_1_reg)=data)
#define  get_SBX_sb3_pri_1_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_1_reg))
#define  SBX_sb3_pri_1_sb3_c1_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_1_sb3_c1_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_1_sb3_c1_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_1_sb3_c1_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_1_sb3_c1_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_1_sb3_c1_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_1_get_sb3_c1_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_1_get_sb3_c1_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_2                                                           0x1801C208
#define  SBX_sb3_pri_2_reg_addr                                                  "0xB801C208"
#define  SBX_sb3_pri_2_reg                                                       0xB801C208
#define  SBX_sb3_pri_2_inst_addr                                                 "0x0013"
#define  set_SBX_sb3_pri_2_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_2_reg)=data)
#define  get_SBX_sb3_pri_2_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_2_reg))
#define  SBX_sb3_pri_2_sb3_c2_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_2_sb3_c2_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_2_sb3_c2_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_2_sb3_c2_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_2_sb3_c2_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_2_sb3_c2_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_2_get_sb3_c2_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_2_get_sb3_c2_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_3                                                           0x1801C20C
#define  SBX_sb3_pri_3_reg_addr                                                  "0xB801C20C"
#define  SBX_sb3_pri_3_reg                                                       0xB801C20C
#define  SBX_sb3_pri_3_inst_addr                                                 "0x0014"
#define  set_SBX_sb3_pri_3_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_3_reg)=data)
#define  get_SBX_sb3_pri_3_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_3_reg))
#define  SBX_sb3_pri_3_sb3_c3_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_3_sb3_c3_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_3_sb3_c3_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_3_sb3_c3_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_3_sb3_c3_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_3_sb3_c3_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_3_get_sb3_c3_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_3_get_sb3_c3_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_4                                                           0x1801C210
#define  SBX_sb3_pri_4_reg_addr                                                  "0xB801C210"
#define  SBX_sb3_pri_4_reg                                                       0xB801C210
#define  SBX_sb3_pri_4_inst_addr                                                 "0x0015"
#define  set_SBX_sb3_pri_4_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_4_reg)=data)
#define  get_SBX_sb3_pri_4_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_4_reg))
#define  SBX_sb3_pri_4_sb3_c4_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_4_sb3_c4_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_4_sb3_c4_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_4_sb3_c4_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_4_sb3_c4_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_4_sb3_c4_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_4_get_sb3_c4_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_4_get_sb3_c4_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_5                                                           0x1801C214
#define  SBX_sb3_pri_5_reg_addr                                                  "0xB801C214"
#define  SBX_sb3_pri_5_reg                                                       0xB801C214
#define  SBX_sb3_pri_5_inst_addr                                                 "0x0016"
#define  set_SBX_sb3_pri_5_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_5_reg)=data)
#define  get_SBX_sb3_pri_5_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_5_reg))
#define  SBX_sb3_pri_5_sb3_c5_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_5_sb3_c5_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_5_sb3_c5_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_5_sb3_c5_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_5_sb3_c5_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_5_sb3_c5_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_5_get_sb3_c5_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_5_get_sb3_c5_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_6                                                           0x1801C218
#define  SBX_sb3_pri_6_reg_addr                                                  "0xB801C218"
#define  SBX_sb3_pri_6_reg                                                       0xB801C218
#define  SBX_sb3_pri_6_inst_addr                                                 "0x0017"
#define  set_SBX_sb3_pri_6_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_6_reg)=data)
#define  get_SBX_sb3_pri_6_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_6_reg))
#define  SBX_sb3_pri_6_sb3_c6_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_6_sb3_c6_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_6_sb3_c6_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_6_sb3_c6_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_6_sb3_c6_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_6_sb3_c6_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_6_get_sb3_c6_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_6_get_sb3_c6_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_7                                                           0x1801C21C
#define  SBX_sb3_pri_7_reg_addr                                                  "0xB801C21C"
#define  SBX_sb3_pri_7_reg                                                       0xB801C21C
#define  SBX_sb3_pri_7_inst_addr                                                 "0x0018"
#define  set_SBX_sb3_pri_7_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_7_reg)=data)
#define  get_SBX_sb3_pri_7_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_7_reg))
#define  SBX_sb3_pri_7_sb3_c7_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_7_sb3_c7_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_7_sb3_c7_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_7_sb3_c7_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_7_sb3_c7_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_7_sb3_c7_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_7_get_sb3_c7_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_7_get_sb3_c7_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_8                                                           0x1801C230
#define  SBX_sb3_pri_8_reg_addr                                                  "0xB801C230"
#define  SBX_sb3_pri_8_reg                                                       0xB801C230
#define  SBX_sb3_pri_8_inst_addr                                                 "0x0019"
#define  set_SBX_sb3_pri_8_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_8_reg)=data)
#define  get_SBX_sb3_pri_8_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_8_reg))
#define  SBX_sb3_pri_8_sb3_c8_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_8_sb3_c8_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_8_sb3_c8_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_8_sb3_c8_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_8_sb3_c8_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_8_sb3_c8_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_8_get_sb3_c8_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_8_get_sb3_c8_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_9                                                           0x1801C234
#define  SBX_sb3_pri_9_reg_addr                                                  "0xB801C234"
#define  SBX_sb3_pri_9_reg                                                       0xB801C234
#define  SBX_sb3_pri_9_inst_addr                                                 "0x001A"
#define  set_SBX_sb3_pri_9_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_9_reg)=data)
#define  get_SBX_sb3_pri_9_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_9_reg))
#define  SBX_sb3_pri_9_sb3_c9_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_9_sb3_c9_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_9_sb3_c9_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_9_sb3_c9_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_9_sb3_c9_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_9_sb3_c9_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_9_get_sb3_c9_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_9_get_sb3_c9_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_a                                                           0x1801C238
#define  SBX_sb3_pri_a_reg_addr                                                  "0xB801C238"
#define  SBX_sb3_pri_a_reg                                                       0xB801C238
#define  SBX_sb3_pri_a_inst_addr                                                 "0x001B"
#define  set_SBX_sb3_pri_a_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_a_reg)=data)
#define  get_SBX_sb3_pri_a_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_a_reg))
#define  SBX_sb3_pri_a_sb3_ca_latcnt_end_shift                                   (16)
#define  SBX_sb3_pri_a_sb3_ca_latcnt_beg_shift                                   (0)
#define  SBX_sb3_pri_a_sb3_ca_latcnt_end_mask                                    (0x00FF0000)
#define  SBX_sb3_pri_a_sb3_ca_latcnt_beg_mask                                    (0x000000FF)
#define  SBX_sb3_pri_a_sb3_ca_latcnt_end(data)                                   (0x00FF0000&((data)<<16))
#define  SBX_sb3_pri_a_sb3_ca_latcnt_beg(data)                                   (0x000000FF&(data))
#define  SBX_sb3_pri_a_get_sb3_ca_latcnt_end(data)                               ((0x00FF0000&(data))>>16)
#define  SBX_sb3_pri_a_get_sb3_ca_latcnt_beg(data)                               (0x000000FF&(data))

#define  SBX_sb3_pri_b                                                           0x1801C220
#define  SBX_sb3_pri_b_reg_addr                                                  "0xB801C220"
#define  SBX_sb3_pri_b_reg                                                       0xB801C220
#define  SBX_sb3_pri_b_inst_addr                                                 "0x001C"
#define  set_SBX_sb3_pri_b_reg(data)                                             (*((volatile unsigned int*)SBX_sb3_pri_b_reg)=data)
#define  get_SBX_sb3_pri_b_reg                                                   (*((volatile unsigned int*)SBX_sb3_pri_b_reg))
#define  SBX_sb3_pri_b_sb3_pri_cnt_period_shift                                  (0)
#define  SBX_sb3_pri_b_sb3_pri_cnt_period_mask                                   (0x000000FF)
#define  SBX_sb3_pri_b_sb3_pri_cnt_period(data)                                  (0x000000FF&(data))
#define  SBX_sb3_pri_b_get_sb3_pri_cnt_period(data)                              (0x000000FF&(data))

#define  SBX_sb3_channel_0                                                       0x1801C224
#define  SBX_sb3_channel_0_reg_addr                                              "0xB801C224"
#define  SBX_sb3_channel_0_reg                                                   0xB801C224
#define  SBX_sb3_channel_0_inst_addr                                             "0x001D"
#define  set_SBX_sb3_channel_0_reg(data)                                         (*((volatile unsigned int*)SBX_sb3_channel_0_reg)=data)
#define  get_SBX_sb3_channel_0_reg                                               (*((volatile unsigned int*)SBX_sb3_channel_0_reg))
#define  SBX_sb3_channel_0_sb3_req_mask_index_shift                              (0)
#define  SBX_sb3_channel_0_sb3_req_mask_index_mask                               (0x000007FF)
#define  SBX_sb3_channel_0_sb3_req_mask_index(data)                              (0x000007FF&(data))
#define  SBX_sb3_channel_0_get_sb3_req_mask_index(data)                          (0x000007FF&(data))

#define  SBX_sb3_channel_1                                                       0x1801C228
#define  SBX_sb3_channel_1_reg_addr                                              "0xB801C228"
#define  SBX_sb3_channel_1_reg                                                   0xB801C228
#define  SBX_sb3_channel_1_inst_addr                                             "0x001E"
#define  set_SBX_sb3_channel_1_reg(data)                                         (*((volatile unsigned int*)SBX_sb3_channel_1_reg)=data)
#define  get_SBX_sb3_channel_1_reg                                               (*((volatile unsigned int*)SBX_sb3_channel_1_reg))
#define  SBX_sb3_channel_1_sb3_req_busy_index_shift                              (0)
#define  SBX_sb3_channel_1_sb3_req_busy_index_mask                               (0x000007FF)
#define  SBX_sb3_channel_1_sb3_req_busy_index(data)                              (0x000007FF&(data))
#define  SBX_sb3_channel_1_get_sb3_req_busy_index(data)                          (0x000007FF&(data))

#define  SBX_sb3_misc_ctrl                                                       0x1801C22C
#define  SBX_sb3_misc_ctrl_reg_addr                                              "0xB801C22C"
#define  SBX_sb3_misc_ctrl_reg                                                   0xB801C22C
#define  SBX_sb3_misc_ctrl_inst_addr                                             "0x001F"
#define  set_SBX_sb3_misc_ctrl_reg(data)                                         (*((volatile unsigned int*)SBX_sb3_misc_ctrl_reg)=data)
#define  get_SBX_sb3_misc_ctrl_reg                                               (*((volatile unsigned int*)SBX_sb3_misc_ctrl_reg))
#define  SBX_sb3_misc_ctrl_sb3_allow_cmd_cnt_shift                               (0)
#define  SBX_sb3_misc_ctrl_sb3_allow_cmd_cnt_mask                                (0x00000007)
#define  SBX_sb3_misc_ctrl_sb3_allow_cmd_cnt(data)                               (0x00000007&(data))
#define  SBX_sb3_misc_ctrl_get_sb3_allow_cmd_cnt(data)                           (0x00000007&(data))

#define  SBX_sb3_sftx_test0                                                      0x1801C240
#define  SBX_sb3_sftx_test0_reg_addr                                             "0xB801C240"
#define  SBX_sb3_sftx_test0_reg                                                  0xB801C240
#define  SBX_sb3_sftx_test0_inst_addr                                            "0x0020"
#define  set_SBX_sb3_sftx_test0_reg(data)                                        (*((volatile unsigned int*)SBX_sb3_sftx_test0_reg)=data)
#define  get_SBX_sb3_sftx_test0_reg                                              (*((volatile unsigned int*)SBX_sb3_sftx_test0_reg))
#define  SBX_sb3_sftx_test0_sf_tx_mode_vde_shift                                 (5)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ve_shift                                  (4)
#define  SBX_sb3_sftx_test0_dummy_3_shift                                        (3)
#define  SBX_sb3_sftx_test0_dummy_2_shift                                        (2)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ade_shift                                 (1)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ae_shift                                  (0)
#define  SBX_sb3_sftx_test0_sf_tx_mode_vde_mask                                  (0x00000020)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ve_mask                                   (0x00000010)
#define  SBX_sb3_sftx_test0_dummy_3_mask                                         (0x00000008)
#define  SBX_sb3_sftx_test0_dummy_2_mask                                         (0x00000004)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ade_mask                                  (0x00000002)
#define  SBX_sb3_sftx_test0_sf_tx_mode_ae_mask                                   (0x00000001)
#define  SBX_sb3_sftx_test0_sf_tx_mode_vde(data)                                 (0x00000020&((data)<<5))
#define  SBX_sb3_sftx_test0_sf_tx_mode_ve(data)                                  (0x00000010&((data)<<4))
#define  SBX_sb3_sftx_test0_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  SBX_sb3_sftx_test0_dummy_2(data)                                        (0x00000004&((data)<<2))
#define  SBX_sb3_sftx_test0_sf_tx_mode_ade(data)                                 (0x00000002&((data)<<1))
#define  SBX_sb3_sftx_test0_sf_tx_mode_ae(data)                                  (0x00000001&(data))
#define  SBX_sb3_sftx_test0_get_sf_tx_mode_vde(data)                             ((0x00000020&(data))>>5)
#define  SBX_sb3_sftx_test0_get_sf_tx_mode_ve(data)                              ((0x00000010&(data))>>4)
#define  SBX_sb3_sftx_test0_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  SBX_sb3_sftx_test0_get_dummy_2(data)                                    ((0x00000004&(data))>>2)
#define  SBX_sb3_sftx_test0_get_sf_tx_mode_ade(data)                             ((0x00000002&(data))>>1)
#define  SBX_sb3_sftx_test0_get_sf_tx_mode_ae(data)                              (0x00000001&(data))

#define  SBX_sb3_sftx_test1                                                      0x1801C244
#define  SBX_sb3_sftx_test1_reg_addr                                             "0xB801C244"
#define  SBX_sb3_sftx_test1_reg                                                  0xB801C244
#define  SBX_sb3_sftx_test1_inst_addr                                            "0x0021"
#define  set_SBX_sb3_sftx_test1_reg(data)                                        (*((volatile unsigned int*)SBX_sb3_sftx_test1_reg)=data)
#define  get_SBX_sb3_sftx_test1_reg                                              (*((volatile unsigned int*)SBX_sb3_sftx_test1_reg))
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_vde_shift                              (21)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ve_shift                               (20)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ade_shift                              (17)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ae_shift                               (16)
#define  SBX_sb3_sftx_test1_sf_tx_start_vde_shift                                (5)
#define  SBX_sb3_sftx_test1_sf_tx_start_ve_shift                                 (4)
#define  SBX_sb3_sftx_test1_dummy_3_shift                                        (3)
#define  SBX_sb3_sftx_test1_dummy_2_shift                                        (2)
#define  SBX_sb3_sftx_test1_sf_tx_start_ade_shift                                (1)
#define  SBX_sb3_sftx_test1_sf_tx_start_ae_shift                                 (0)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_vde_mask                               (0x00200000)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ve_mask                                (0x00100000)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ade_mask                               (0x00020000)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ae_mask                                (0x00010000)
#define  SBX_sb3_sftx_test1_sf_tx_start_vde_mask                                 (0x00000020)
#define  SBX_sb3_sftx_test1_sf_tx_start_ve_mask                                  (0x00000010)
#define  SBX_sb3_sftx_test1_dummy_3_mask                                         (0x00000008)
#define  SBX_sb3_sftx_test1_dummy_2_mask                                         (0x00000004)
#define  SBX_sb3_sftx_test1_sf_tx_start_ade_mask                                 (0x00000002)
#define  SBX_sb3_sftx_test1_sf_tx_start_ae_mask                                  (0x00000001)
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_vde(data)                              (0x00200000&((data)<<21))
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ve(data)                               (0x00100000&((data)<<20))
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ade(data)                              (0x00020000&((data)<<17))
#define  SBX_sb3_sftx_test1_sf_tx_work_ro_ae(data)                               (0x00010000&((data)<<16))
#define  SBX_sb3_sftx_test1_sf_tx_start_vde(data)                                (0x00000020&((data)<<5))
#define  SBX_sb3_sftx_test1_sf_tx_start_ve(data)                                 (0x00000010&((data)<<4))
#define  SBX_sb3_sftx_test1_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  SBX_sb3_sftx_test1_dummy_2(data)                                        (0x00000004&((data)<<2))
#define  SBX_sb3_sftx_test1_sf_tx_start_ade(data)                                (0x00000002&((data)<<1))
#define  SBX_sb3_sftx_test1_sf_tx_start_ae(data)                                 (0x00000001&(data))
#define  SBX_sb3_sftx_test1_get_sf_tx_work_ro_vde(data)                          ((0x00200000&(data))>>21)
#define  SBX_sb3_sftx_test1_get_sf_tx_work_ro_ve(data)                           ((0x00100000&(data))>>20)
#define  SBX_sb3_sftx_test1_get_sf_tx_work_ro_ade(data)                          ((0x00020000&(data))>>17)
#define  SBX_sb3_sftx_test1_get_sf_tx_work_ro_ae(data)                           ((0x00010000&(data))>>16)
#define  SBX_sb3_sftx_test1_get_sf_tx_start_vde(data)                            ((0x00000020&(data))>>5)
#define  SBX_sb3_sftx_test1_get_sf_tx_start_ve(data)                             ((0x00000010&(data))>>4)
#define  SBX_sb3_sftx_test1_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  SBX_sb3_sftx_test1_get_dummy_2(data)                                    ((0x00000004&(data))>>2)
#define  SBX_sb3_sftx_test1_get_sf_tx_start_ade(data)                            ((0x00000002&(data))>>1)
#define  SBX_sb3_sftx_test1_get_sf_tx_start_ae(data)                             (0x00000001&(data))

#define  SBX_sb3_sfrx_test0                                                      0x1801C248
#define  SBX_sb3_sfrx_test0_reg_addr                                             "0xB801C248"
#define  SBX_sb3_sfrx_test0_reg                                                  0xB801C248
#define  SBX_sb3_sfrx_test0_inst_addr                                            "0x0022"
#define  set_SBX_sb3_sfrx_test0_reg(data)                                        (*((volatile unsigned int*)SBX_sb3_sfrx_test0_reg)=data)
#define  get_SBX_sb3_sfrx_test0_reg                                              (*((volatile unsigned int*)SBX_sb3_sfrx_test0_reg))
#define  SBX_sb3_sfrx_test0_sf_rx_gated_vde_shift                                (21)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ve_shift                                 (20)
#define  SBX_sb3_sfrx_test0_dummy_19_shift                                       (19)
#define  SBX_sb3_sfrx_test0_dummy_18_shift                                       (18)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ade_shift                                (17)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ae_shift                                 (16)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_vde_shift                                 (5)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ve_shift                                  (4)
#define  SBX_sb3_sfrx_test0_dummy_3_shift                                        (3)
#define  SBX_sb3_sfrx_test0_dummy_2_shift                                        (2)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ade_shift                                 (1)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ae_shift                                  (0)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_vde_mask                                 (0x00200000)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ve_mask                                  (0x00100000)
#define  SBX_sb3_sfrx_test0_dummy_19_mask                                        (0x00080000)
#define  SBX_sb3_sfrx_test0_dummy_18_mask                                        (0x00040000)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ade_mask                                 (0x00020000)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ae_mask                                  (0x00010000)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_vde_mask                                  (0x00000020)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ve_mask                                   (0x00000010)
#define  SBX_sb3_sfrx_test0_dummy_3_mask                                         (0x00000008)
#define  SBX_sb3_sfrx_test0_dummy_2_mask                                         (0x00000004)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ade_mask                                  (0x00000002)
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ae_mask                                   (0x00000001)
#define  SBX_sb3_sfrx_test0_sf_rx_gated_vde(data)                                (0x00200000&((data)<<21))
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ve(data)                                 (0x00100000&((data)<<20))
#define  SBX_sb3_sfrx_test0_dummy_19(data)                                       (0x00080000&((data)<<19))
#define  SBX_sb3_sfrx_test0_dummy_18(data)                                       (0x00040000&((data)<<18))
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ade(data)                                (0x00020000&((data)<<17))
#define  SBX_sb3_sfrx_test0_sf_rx_gated_ae(data)                                 (0x00010000&((data)<<16))
#define  SBX_sb3_sfrx_test0_sf_rx_mode_vde(data)                                 (0x00000020&((data)<<5))
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ve(data)                                  (0x00000010&((data)<<4))
#define  SBX_sb3_sfrx_test0_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  SBX_sb3_sfrx_test0_dummy_2(data)                                        (0x00000004&((data)<<2))
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ade(data)                                 (0x00000002&((data)<<1))
#define  SBX_sb3_sfrx_test0_sf_rx_mode_ae(data)                                  (0x00000001&(data))
#define  SBX_sb3_sfrx_test0_get_sf_rx_gated_vde(data)                            ((0x00200000&(data))>>21)
#define  SBX_sb3_sfrx_test0_get_sf_rx_gated_ve(data)                             ((0x00100000&(data))>>20)
#define  SBX_sb3_sfrx_test0_get_dummy_19(data)                                   ((0x00080000&(data))>>19)
#define  SBX_sb3_sfrx_test0_get_dummy_18(data)                                   ((0x00040000&(data))>>18)
#define  SBX_sb3_sfrx_test0_get_sf_rx_gated_ade(data)                            ((0x00020000&(data))>>17)
#define  SBX_sb3_sfrx_test0_get_sf_rx_gated_ae(data)                             ((0x00010000&(data))>>16)
#define  SBX_sb3_sfrx_test0_get_sf_rx_mode_vde(data)                             ((0x00000020&(data))>>5)
#define  SBX_sb3_sfrx_test0_get_sf_rx_mode_ve(data)                              ((0x00000010&(data))>>4)
#define  SBX_sb3_sfrx_test0_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  SBX_sb3_sfrx_test0_get_dummy_2(data)                                    ((0x00000004&(data))>>2)
#define  SBX_sb3_sfrx_test0_get_sf_rx_mode_ade(data)                             ((0x00000002&(data))>>1)
#define  SBX_sb3_sfrx_test0_get_sf_rx_mode_ae(data)                              (0x00000001&(data))

#define  SBX_sb3_sfrx_test1                                                      0x1801C24C
#define  SBX_sb3_sfrx_test1_reg_addr                                             "0xB801C24C"
#define  SBX_sb3_sfrx_test1_reg                                                  0xB801C24C
#define  SBX_sb3_sfrx_test1_inst_addr                                            "0x0023"
#define  set_SBX_sb3_sfrx_test1_reg(data)                                        (*((volatile unsigned int*)SBX_sb3_sfrx_test1_reg)=data)
#define  get_SBX_sb3_sfrx_test1_reg                                              (*((volatile unsigned int*)SBX_sb3_sfrx_test1_reg))
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_vde_shift                              (21)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ve_shift                               (20)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ade_shift                              (17)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ae_shift                               (16)
#define  SBX_sb3_sfrx_test1_sf_rx_start_vde_shift                                (5)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ve_shift                                 (4)
#define  SBX_sb3_sfrx_test1_dummy_3_shift                                        (3)
#define  SBX_sb3_sfrx_test1_dummy_2_shift                                        (2)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ade_shift                                (1)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ae_shift                                 (0)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_vde_mask                               (0x00200000)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ve_mask                                (0x00100000)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ade_mask                               (0x00020000)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ae_mask                                (0x00010000)
#define  SBX_sb3_sfrx_test1_sf_rx_start_vde_mask                                 (0x00000020)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ve_mask                                  (0x00000010)
#define  SBX_sb3_sfrx_test1_dummy_3_mask                                         (0x00000008)
#define  SBX_sb3_sfrx_test1_dummy_2_mask                                         (0x00000004)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ade_mask                                 (0x00000002)
#define  SBX_sb3_sfrx_test1_sf_rx_start_ae_mask                                  (0x00000001)
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_vde(data)                              (0x00200000&((data)<<21))
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ve(data)                               (0x00100000&((data)<<20))
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ade(data)                              (0x00020000&((data)<<17))
#define  SBX_sb3_sfrx_test1_sf_rx_done_ro_ae(data)                               (0x00010000&((data)<<16))
#define  SBX_sb3_sfrx_test1_sf_rx_start_vde(data)                                (0x00000020&((data)<<5))
#define  SBX_sb3_sfrx_test1_sf_rx_start_ve(data)                                 (0x00000010&((data)<<4))
#define  SBX_sb3_sfrx_test1_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  SBX_sb3_sfrx_test1_dummy_2(data)                                        (0x00000004&((data)<<2))
#define  SBX_sb3_sfrx_test1_sf_rx_start_ade(data)                                (0x00000002&((data)<<1))
#define  SBX_sb3_sfrx_test1_sf_rx_start_ae(data)                                 (0x00000001&(data))
#define  SBX_sb3_sfrx_test1_get_sf_rx_done_ro_vde(data)                          ((0x00200000&(data))>>21)
#define  SBX_sb3_sfrx_test1_get_sf_rx_done_ro_ve(data)                           ((0x00100000&(data))>>20)
#define  SBX_sb3_sfrx_test1_get_sf_rx_done_ro_ade(data)                          ((0x00020000&(data))>>17)
#define  SBX_sb3_sfrx_test1_get_sf_rx_done_ro_ae(data)                           ((0x00010000&(data))>>16)
#define  SBX_sb3_sfrx_test1_get_sf_rx_start_vde(data)                            ((0x00000020&(data))>>5)
#define  SBX_sb3_sfrx_test1_get_sf_rx_start_ve(data)                             ((0x00000010&(data))>>4)
#define  SBX_sb3_sfrx_test1_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  SBX_sb3_sfrx_test1_get_dummy_2(data)                                    ((0x00000004&(data))>>2)
#define  SBX_sb3_sfrx_test1_get_sf_rx_start_ade(data)                            ((0x00000002&(data))>>1)
#define  SBX_sb3_sfrx_test1_get_sf_rx_start_ae(data)                             (0x00000001&(data))

#define  SBX_sb3_sfrx_test2                                                      0x1801C250
#define  SBX_sb3_sfrx_test2_reg_addr                                             "0xB801C250"
#define  SBX_sb3_sfrx_test2_reg                                                  0xB801C250
#define  SBX_sb3_sfrx_test2_inst_addr                                            "0x0024"
#define  set_SBX_sb3_sfrx_test2_reg(data)                                        (*((volatile unsigned int*)SBX_sb3_sfrx_test2_reg)=data)
#define  get_SBX_sb3_sfrx_test2_reg                                              (*((volatile unsigned int*)SBX_sb3_sfrx_test2_reg))
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_vde_shift                               (5)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ve_shift                                (4)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ade_shift                               (1)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ae_shift                                (0)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_vde_mask                                (0x00000020)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ve_mask                                 (0x00000010)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ade_mask                                (0x00000002)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ae_mask                                 (0x00000001)
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_vde(data)                               (0x00000020&((data)<<5))
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ve(data)                                (0x00000010&((data)<<4))
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ade(data)                               (0x00000002&((data)<<1))
#define  SBX_sb3_sfrx_test2_sf_rx_err_ro_ae(data)                                (0x00000001&(data))
#define  SBX_sb3_sfrx_test2_get_sf_rx_err_ro_vde(data)                           ((0x00000020&(data))>>5)
#define  SBX_sb3_sfrx_test2_get_sf_rx_err_ro_ve(data)                            ((0x00000010&(data))>>4)
#define  SBX_sb3_sfrx_test2_get_sf_rx_err_ro_ade(data)                           ((0x00000002&(data))>>1)
#define  SBX_sb3_sfrx_test2_get_sf_rx_err_ro_ae(data)                            (0x00000001&(data))

#define  SBX_ssb1_pri_0                                                          0x1801C800
#define  SBX_ssb1_pri_0_reg_addr                                                 "0xB801C800"
#define  SBX_ssb1_pri_0_reg                                                      0xB801C800
#define  SBX_ssb1_pri_0_inst_addr                                                "0x0025"
#define  set_SBX_ssb1_pri_0_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_0_reg)=data)
#define  get_SBX_ssb1_pri_0_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_0_reg))
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_0_sb1_c0_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_0_get_sb1_c0_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_0_get_sb1_c0_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_1                                                          0x1801C804
#define  SBX_ssb1_pri_1_reg_addr                                                 "0xB801C804"
#define  SBX_ssb1_pri_1_reg                                                      0xB801C804
#define  SBX_ssb1_pri_1_inst_addr                                                "0x0026"
#define  set_SBX_ssb1_pri_1_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_1_reg)=data)
#define  get_SBX_ssb1_pri_1_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_1_reg))
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_1_sb1_c1_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_1_get_sb1_c1_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_1_get_sb1_c1_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_2                                                          0x1801C808
#define  SBX_ssb1_pri_2_reg_addr                                                 "0xB801C808"
#define  SBX_ssb1_pri_2_reg                                                      0xB801C808
#define  SBX_ssb1_pri_2_inst_addr                                                "0x0027"
#define  set_SBX_ssb1_pri_2_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_2_reg)=data)
#define  get_SBX_ssb1_pri_2_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_2_reg))
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_2_sb1_c2_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_2_get_sb1_c2_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_2_get_sb1_c2_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_3                                                          0x1801C80C
#define  SBX_ssb1_pri_3_reg_addr                                                 "0xB801C80C"
#define  SBX_ssb1_pri_3_reg                                                      0xB801C80C
#define  SBX_ssb1_pri_3_inst_addr                                                "0x0028"
#define  set_SBX_ssb1_pri_3_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_3_reg)=data)
#define  get_SBX_ssb1_pri_3_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_3_reg))
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_3_sb1_c3_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_3_get_sb1_c3_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_3_get_sb1_c3_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_4                                                          0x1801C810
#define  SBX_ssb1_pri_4_reg_addr                                                 "0xB801C810"
#define  SBX_ssb1_pri_4_reg                                                      0xB801C810
#define  SBX_ssb1_pri_4_inst_addr                                                "0x0029"
#define  set_SBX_ssb1_pri_4_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_4_reg)=data)
#define  get_SBX_ssb1_pri_4_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_4_reg))
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_4_sb1_c4_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_4_get_sb1_c4_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_4_get_sb1_c4_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_5                                                          0x1801C814
#define  SBX_ssb1_pri_5_reg_addr                                                 "0xB801C814"
#define  SBX_ssb1_pri_5_reg                                                      0xB801C814
#define  SBX_ssb1_pri_5_inst_addr                                                "0x002A"
#define  set_SBX_ssb1_pri_5_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_5_reg)=data)
#define  get_SBX_ssb1_pri_5_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_5_reg))
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_5_sb1_c5_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_5_get_sb1_c5_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_5_get_sb1_c5_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_6                                                          0x1801C818
#define  SBX_ssb1_pri_6_reg_addr                                                 "0xB801C818"
#define  SBX_ssb1_pri_6_reg                                                      0xB801C818
#define  SBX_ssb1_pri_6_inst_addr                                                "0x002B"
#define  set_SBX_ssb1_pri_6_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_6_reg)=data)
#define  get_SBX_ssb1_pri_6_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_6_reg))
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_6_sb1_c6_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_6_get_sb1_c6_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_6_get_sb1_c6_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_7                                                          0x1801C81C
#define  SBX_ssb1_pri_7_reg_addr                                                 "0xB801C81C"
#define  SBX_ssb1_pri_7_reg                                                      0xB801C81C
#define  SBX_ssb1_pri_7_inst_addr                                                "0x002C"
#define  set_SBX_ssb1_pri_7_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_7_reg)=data)
#define  get_SBX_ssb1_pri_7_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_7_reg))
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_end_shift                                  (16)
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_beg_shift                                  (0)
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_end_mask                                   (0x00FF0000)
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_beg_mask                                   (0x000000FF)
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_end(data)                                  (0x00FF0000&((data)<<16))
#define  SBX_ssb1_pri_7_sb1_c7_latcnt_beg(data)                                  (0x000000FF&(data))
#define  SBX_ssb1_pri_7_get_sb1_c7_latcnt_end(data)                              ((0x00FF0000&(data))>>16)
#define  SBX_ssb1_pri_7_get_sb1_c7_latcnt_beg(data)                              (0x000000FF&(data))

#define  SBX_ssb1_pri_8                                                          0x1801C820
#define  SBX_ssb1_pri_8_reg_addr                                                 "0xB801C820"
#define  SBX_ssb1_pri_8_reg                                                      0xB801C820
#define  SBX_ssb1_pri_8_inst_addr                                                "0x002D"
#define  set_SBX_ssb1_pri_8_reg(data)                                            (*((volatile unsigned int*)SBX_ssb1_pri_8_reg)=data)
#define  get_SBX_ssb1_pri_8_reg                                                  (*((volatile unsigned int*)SBX_ssb1_pri_8_reg))
#define  SBX_ssb1_pri_8_sb1_pri_cnt_period_shift                                 (0)
#define  SBX_ssb1_pri_8_sb1_pri_cnt_period_mask                                  (0x000000FF)
#define  SBX_ssb1_pri_8_sb1_pri_cnt_period(data)                                 (0x000000FF&(data))
#define  SBX_ssb1_pri_8_get_sb1_pri_cnt_period(data)                             (0x000000FF&(data))

#define  SBX_ssb1_channel_0                                                      0x1801C824
#define  SBX_ssb1_channel_0_reg_addr                                             "0xB801C824"
#define  SBX_ssb1_channel_0_reg                                                  0xB801C824
#define  SBX_ssb1_channel_0_inst_addr                                            "0x002E"
#define  set_SBX_ssb1_channel_0_reg(data)                                        (*((volatile unsigned int*)SBX_ssb1_channel_0_reg)=data)
#define  get_SBX_ssb1_channel_0_reg                                              (*((volatile unsigned int*)SBX_ssb1_channel_0_reg))
#define  SBX_ssb1_channel_0_sb1_req_mask_index_shift                             (0)
#define  SBX_ssb1_channel_0_sb1_req_mask_index_mask                              (0x000000FF)
#define  SBX_ssb1_channel_0_sb1_req_mask_index(data)                             (0x000000FF&(data))
#define  SBX_ssb1_channel_0_get_sb1_req_mask_index(data)                         (0x000000FF&(data))

#define  SBX_ssb1_channel_1                                                      0x1801C828
#define  SBX_ssb1_channel_1_reg_addr                                             "0xB801C828"
#define  SBX_ssb1_channel_1_reg                                                  0xB801C828
#define  SBX_ssb1_channel_1_inst_addr                                            "0x002F"
#define  set_SBX_ssb1_channel_1_reg(data)                                        (*((volatile unsigned int*)SBX_ssb1_channel_1_reg)=data)
#define  get_SBX_ssb1_channel_1_reg                                              (*((volatile unsigned int*)SBX_ssb1_channel_1_reg))
#define  SBX_ssb1_channel_1_sb1_req_busy_index_shift                             (0)
#define  SBX_ssb1_channel_1_sb1_req_busy_index_mask                              (0x000000FF)
#define  SBX_ssb1_channel_1_sb1_req_busy_index(data)                             (0x000000FF&(data))
#define  SBX_ssb1_channel_1_get_sb1_req_busy_index(data)                         (0x000000FF&(data))

#define  SBX_ssb1_misc_ctrl                                                      0x1801C82C
#define  SBX_ssb1_misc_ctrl_reg_addr                                             "0xB801C82C"
#define  SBX_ssb1_misc_ctrl_reg                                                  0xB801C82C
#define  SBX_ssb1_misc_ctrl_inst_addr                                            "0x0030"
#define  set_SBX_ssb1_misc_ctrl_reg(data)                                        (*((volatile unsigned int*)SBX_ssb1_misc_ctrl_reg)=data)
#define  get_SBX_ssb1_misc_ctrl_reg                                              (*((volatile unsigned int*)SBX_ssb1_misc_ctrl_reg))
#define  SBX_ssb1_misc_ctrl_sb1_allow_cmd_cnt_shift                              (0)
#define  SBX_ssb1_misc_ctrl_sb1_allow_cmd_cnt_mask                               (0x00000007)
#define  SBX_ssb1_misc_ctrl_sb1_allow_cmd_cnt(data)                              (0x00000007&(data))
#define  SBX_ssb1_misc_ctrl_get_sb1_allow_cmd_cnt(data)                          (0x00000007&(data))

#define  SBX_ssb1_sftx_test0                                                     0x1801C840
#define  SBX_ssb1_sftx_test0_reg_addr                                            "0xB801C840"
#define  SBX_ssb1_sftx_test0_reg                                                 0xB801C840
#define  SBX_ssb1_sftx_test0_inst_addr                                           "0x0031"
#define  set_SBX_ssb1_sftx_test0_reg(data)                                       (*((volatile unsigned int*)SBX_ssb1_sftx_test0_reg)=data)
#define  get_SBX_ssb1_sftx_test0_reg                                             (*((volatile unsigned int*)SBX_ssb1_sftx_test0_reg))
#define  SBX_ssb1_sftx_test0_sf_tx_mode_sb1_shift                                (0)
#define  SBX_ssb1_sftx_test0_sf_tx_mode_sb1_mask                                 (0x00000001)
#define  SBX_ssb1_sftx_test0_sf_tx_mode_sb1(data)                                (0x00000001&(data))
#define  SBX_ssb1_sftx_test0_get_sf_tx_mode_sb1(data)                            (0x00000001&(data))

#define  SBX_ssb1_sftx_test1                                                     0x1801C844
#define  SBX_ssb1_sftx_test1_reg_addr                                            "0xB801C844"
#define  SBX_ssb1_sftx_test1_reg                                                 0xB801C844
#define  SBX_ssb1_sftx_test1_inst_addr                                           "0x0032"
#define  set_SBX_ssb1_sftx_test1_reg(data)                                       (*((volatile unsigned int*)SBX_ssb1_sftx_test1_reg)=data)
#define  get_SBX_ssb1_sftx_test1_reg                                             (*((volatile unsigned int*)SBX_ssb1_sftx_test1_reg))
#define  SBX_ssb1_sftx_test1_sf_tx_work_ro_sb1_shift                             (16)
#define  SBX_ssb1_sftx_test1_sf_tx_start_sb1_shift                               (0)
#define  SBX_ssb1_sftx_test1_sf_tx_work_ro_sb1_mask                              (0x00010000)
#define  SBX_ssb1_sftx_test1_sf_tx_start_sb1_mask                                (0x00000001)
#define  SBX_ssb1_sftx_test1_sf_tx_work_ro_sb1(data)                             (0x00010000&((data)<<16))
#define  SBX_ssb1_sftx_test1_sf_tx_start_sb1(data)                               (0x00000001&(data))
#define  SBX_ssb1_sftx_test1_get_sf_tx_work_ro_sb1(data)                         ((0x00010000&(data))>>16)
#define  SBX_ssb1_sftx_test1_get_sf_tx_start_sb1(data)                           (0x00000001&(data))

#define  SBX_ssb1_sfrx_test0                                                     0x1801C848
#define  SBX_ssb1_sfrx_test0_reg_addr                                            "0xB801C848"
#define  SBX_ssb1_sfrx_test0_reg                                                 0xB801C848
#define  SBX_ssb1_sfrx_test0_inst_addr                                           "0x0033"
#define  set_SBX_ssb1_sfrx_test0_reg(data)                                       (*((volatile unsigned int*)SBX_ssb1_sfrx_test0_reg)=data)
#define  get_SBX_ssb1_sfrx_test0_reg                                             (*((volatile unsigned int*)SBX_ssb1_sfrx_test0_reg))
#define  SBX_ssb1_sfrx_test0_sf_rx_gated_sb1_shift                               (16)
#define  SBX_ssb1_sfrx_test0_sf_rx_mode_sb1_shift                                (0)
#define  SBX_ssb1_sfrx_test0_sf_rx_gated_sb1_mask                                (0x00010000)
#define  SBX_ssb1_sfrx_test0_sf_rx_mode_sb1_mask                                 (0x00000001)
#define  SBX_ssb1_sfrx_test0_sf_rx_gated_sb1(data)                               (0x00010000&((data)<<16))
#define  SBX_ssb1_sfrx_test0_sf_rx_mode_sb1(data)                                (0x00000001&(data))
#define  SBX_ssb1_sfrx_test0_get_sf_rx_gated_sb1(data)                           ((0x00010000&(data))>>16)
#define  SBX_ssb1_sfrx_test0_get_sf_rx_mode_sb1(data)                            (0x00000001&(data))

#define  SBX_ssb1_sfrx_test1                                                     0x1801C84C
#define  SBX_ssb1_sfrx_test1_reg_addr                                            "0xB801C84C"
#define  SBX_ssb1_sfrx_test1_reg                                                 0xB801C84C
#define  SBX_ssb1_sfrx_test1_inst_addr                                           "0x0034"
#define  set_SBX_ssb1_sfrx_test1_reg(data)                                       (*((volatile unsigned int*)SBX_ssb1_sfrx_test1_reg)=data)
#define  get_SBX_ssb1_sfrx_test1_reg                                             (*((volatile unsigned int*)SBX_ssb1_sfrx_test1_reg))
#define  SBX_ssb1_sfrx_test1_sf_rx_done_ro_sb1_shift                             (16)
#define  SBX_ssb1_sfrx_test1_sf_rx_start_sb1_shift                               (0)
#define  SBX_ssb1_sfrx_test1_sf_rx_done_ro_sb1_mask                              (0x00010000)
#define  SBX_ssb1_sfrx_test1_sf_rx_start_sb1_mask                                (0x00000001)
#define  SBX_ssb1_sfrx_test1_sf_rx_done_ro_sb1(data)                             (0x00010000&((data)<<16))
#define  SBX_ssb1_sfrx_test1_sf_rx_start_sb1(data)                               (0x00000001&(data))
#define  SBX_ssb1_sfrx_test1_get_sf_rx_done_ro_sb1(data)                         ((0x00010000&(data))>>16)
#define  SBX_ssb1_sfrx_test1_get_sf_rx_start_sb1(data)                           (0x00000001&(data))

#define  SBX_ssb1_sfrx_test2                                                     0x1801C850
#define  SBX_ssb1_sfrx_test2_reg_addr                                            "0xB801C850"
#define  SBX_ssb1_sfrx_test2_reg                                                 0xB801C850
#define  SBX_ssb1_sfrx_test2_inst_addr                                           "0x0035"
#define  set_SBX_ssb1_sfrx_test2_reg(data)                                       (*((volatile unsigned int*)SBX_ssb1_sfrx_test2_reg)=data)
#define  get_SBX_ssb1_sfrx_test2_reg                                             (*((volatile unsigned int*)SBX_ssb1_sfrx_test2_reg))
#define  SBX_ssb1_sfrx_test2_sf_rx_err_ro_sb1_shift                              (0)
#define  SBX_ssb1_sfrx_test2_sf_rx_err_ro_sb1_mask                               (0x00000001)
#define  SBX_ssb1_sfrx_test2_sf_rx_err_ro_sb1(data)                              (0x00000001&(data))
#define  SBX_ssb1_sfrx_test2_get_sf_rx_err_ro_sb1(data)                          (0x00000001&(data))

#define  SBX_SBX_PC_CTRL                                                         0x1801C100
#define  SBX_SBX_PC_CTRL_reg_addr                                                "0xB801C100"
#define  SBX_SBX_PC_CTRL_reg                                                     0xB801C100
#define  SBX_SBX_PC_CTRL_inst_addr                                               "0x0036"
#define  set_SBX_SBX_PC_CTRL_reg(data)                                           (*((volatile unsigned int*)SBX_SBX_PC_CTRL_reg)=data)
#define  get_SBX_SBX_PC_CTRL_reg                                                 (*((volatile unsigned int*)SBX_SBX_PC_CTRL_reg))
#define  SBX_SBX_PC_CTRL_pc_rcmd_only_shift                                      (31)
#define  SBX_SBX_PC_CTRL_pc_go_shift                                             (0)
#define  SBX_SBX_PC_CTRL_pc_rcmd_only_mask                                       (0x80000000)
#define  SBX_SBX_PC_CTRL_pc_go_mask                                              (0x00000001)
#define  SBX_SBX_PC_CTRL_pc_rcmd_only(data)                                      (0x80000000&((data)<<31))
#define  SBX_SBX_PC_CTRL_pc_go(data)                                             (0x00000001&(data))
#define  SBX_SBX_PC_CTRL_get_pc_rcmd_only(data)                                  ((0x80000000&(data))>>31)
#define  SBX_SBX_PC_CTRL_get_pc_go(data)                                         (0x00000001&(data))

#define  SBX_SBX_PC_TOTA_MON_NUM                                                 0x1801C104
#define  SBX_SBX_PC_TOTA_MON_NUM_reg_addr                                        "0xB801C104"
#define  SBX_SBX_PC_TOTA_MON_NUM_reg                                             0xB801C104
#define  SBX_SBX_PC_TOTA_MON_NUM_inst_addr                                       "0x0037"
#define  set_SBX_SBX_PC_TOTA_MON_NUM_reg(data)                                   (*((volatile unsigned int*)SBX_SBX_PC_TOTA_MON_NUM_reg)=data)
#define  get_SBX_SBX_PC_TOTA_MON_NUM_reg                                         (*((volatile unsigned int*)SBX_SBX_PC_TOTA_MON_NUM_reg))
#define  SBX_SBX_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                           (0)
#define  SBX_SBX_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                            (0xFFFFFFFF)
#define  SBX_SBX_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                           (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)                       (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_ctrl                                                0x1801C110
#define  SBX_SBX_PC_SYS_prog_ctrl_reg_addr                                       "0xB801C110"
#define  SBX_SBX_PC_SYS_prog_ctrl_reg                                            0xB801C110
#define  SBX_SBX_PC_SYS_prog_ctrl_inst_addr                                      "0x0038"
#define  set_SBX_SBX_PC_SYS_prog_ctrl_reg(data)                                  (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_ctrl_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_ctrl_reg                                        (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_ctrl_reg))
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_3_shift                               (23)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel_shift                         (16)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_2_shift                               (15)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel_shift                         (8)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_1_shift                               (7)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel_shift                         (0)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_3_mask                                (0x00800000)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel_mask                          (0x007F0000)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_2_mask                                (0x00008000)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel_mask                          (0x00007F00)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_1_mask                                (0x00000080)
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel_mask                          (0x0000007F)
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_3(data)                               (0x00800000&((data)<<23))
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel(data)                         (0x007F0000&((data)<<16))
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_2(data)                               (0x00008000&((data)<<15))
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel(data)                         (0x00007F00&((data)<<8))
#define  SBX_SBX_PC_SYS_prog_ctrl_write_en_1(data)                               (0x00000080&((data)<<7))
#define  SBX_SBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel(data)                         (0x0000007F&(data))
#define  SBX_SBX_PC_SYS_prog_ctrl_get_write_en_3(data)                           ((0x00800000&(data))>>23)
#define  SBX_SBX_PC_SYS_prog_ctrl_get_pc_sys_prog2_sel(data)                     ((0x007F0000&(data))>>16)
#define  SBX_SBX_PC_SYS_prog_ctrl_get_write_en_2(data)                           ((0x00008000&(data))>>15)
#define  SBX_SBX_PC_SYS_prog_ctrl_get_pc_sys_prog1_sel(data)                     ((0x00007F00&(data))>>8)
#define  SBX_SBX_PC_SYS_prog_ctrl_get_write_en_1(data)                           ((0x00000080&(data))>>7)
#define  SBX_SBX_PC_SYS_prog_ctrl_get_pc_sys_prog0_sel(data)                     (0x0000007F&(data))

#define  SBX_SBX_PC_SYS_prog_ctrl1                                               0x1801C120
#define  SBX_SBX_PC_SYS_prog_ctrl1_reg_addr                                      "0xB801C120"
#define  SBX_SBX_PC_SYS_prog_ctrl1_reg                                           0xB801C120
#define  SBX_SBX_PC_SYS_prog_ctrl1_inst_addr                                     "0x0039"
#define  set_SBX_SBX_PC_SYS_prog_ctrl1_reg(data)                                 (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_ctrl1_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_ctrl1_reg                                       (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_ctrl1_reg))
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur_shift                  (6)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur_shift                  (5)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur_shift                  (4)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur_mask                   (0x00000040)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur_mask                   (0x00000020)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur_mask                   (0x00000010)
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur(data)                  (0x00000040&((data)<<6))
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur(data)                  (0x00000020&((data)<<5))
#define  SBX_SBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur(data)                  (0x00000010&((data)<<4))
#define  SBX_SBX_PC_SYS_prog_ctrl1_get_pc_sys_prog2_req_occur(data)              ((0x00000040&(data))>>6)
#define  SBX_SBX_PC_SYS_prog_ctrl1_get_pc_sys_prog1_req_occur(data)              ((0x00000020&(data))>>5)
#define  SBX_SBX_PC_SYS_prog_ctrl1_get_pc_sys_prog0_req_occur(data)              ((0x00000010&(data))>>4)

#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT                                           0x1801C130
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg_addr                                  "0xB801C130"
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg                                       0xB801C130
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_inst_addr                                 "0x003A"
#define  set_SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_ACC_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_0_ACC_LAT_get_sys_prog0_acc_lat(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT                                           0x1801C134
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg_addr                                  "0xB801C134"
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg                                       0xB801C134
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_inst_addr                                 "0x003B"
#define  set_SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_MAX_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat_mask                    (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat(data)                   (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_0_MAX_LAT_get_sys_prog0_max_lat(data)               (0x0000FFFF&(data))

#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM                                           0x1801C138
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg_addr                                  "0xB801C138"
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg                                       0xB801C138
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_inst_addr                                 "0x003C"
#define  set_SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_REQ_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num_mask                    (0x00FFFFFF)
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num(data)                   (0x00FFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_0_REQ_NUM_get_sys_prog0_req_num(data)               (0x00FFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM                                           0x1801C13C
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg_addr                                  "0xB801C13C"
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg                                       0xB801C13C
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_inst_addr                                 "0x003D"
#define  set_SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_ACK_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_0_ACK_NUM_get_sys_prog0_ack_num(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT                                           0x1801C140
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg_addr                                  "0xB801C140"
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg                                       0xB801C140
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_inst_addr                                 "0x003E"
#define  set_SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_ACC_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_1_ACC_LAT_get_sys_prog1_acc_lat(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT                                           0x1801C144
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg_addr                                  "0xB801C144"
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg                                       0xB801C144
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_inst_addr                                 "0x003F"
#define  set_SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_MAX_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat_mask                    (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat(data)                   (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_1_MAX_LAT_get_sys_prog1_max_lat(data)               (0x0000FFFF&(data))

#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM                                           0x1801C148
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg_addr                                  "0xB801C148"
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg                                       0xB801C148
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_inst_addr                                 "0x0040"
#define  set_SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_REQ_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num_mask                    (0x00FFFFFF)
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num(data)                   (0x00FFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_1_REQ_NUM_get_sys_prog1_req_num(data)               (0x00FFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM                                           0x1801C14C
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg_addr                                  "0xB801C14C"
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg                                       0xB801C14C
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_inst_addr                                 "0x0041"
#define  set_SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_ACK_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_1_ACK_NUM_get_sys_prog1_ack_num(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT                                           0x1801C150
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg_addr                                  "0xB801C150"
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg                                       0xB801C150
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_inst_addr                                 "0x0042"
#define  set_SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_ACC_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_2_ACC_LAT_get_sys_prog2_acc_lat(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT                                           0x1801C154
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg_addr                                  "0xB801C154"
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg                                       0xB801C154
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_inst_addr                                 "0x0043"
#define  set_SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_MAX_LAT_reg))
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat_mask                    (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat(data)                   (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_2_MAX_LAT_get_sys_prog2_max_lat(data)               (0x0000FFFF&(data))

#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM                                           0x1801C158
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg_addr                                  "0xB801C158"
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg                                       0xB801C158
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_inst_addr                                 "0x0044"
#define  set_SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_REQ_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num_mask                    (0x00FFFFFF)
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num(data)                   (0x00FFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_2_REQ_NUM_get_sys_prog2_req_num(data)               (0x00FFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM                                           0x1801C15C
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg_addr                                  "0xB801C15C"
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg                                       0xB801C15C
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_inst_addr                                 "0x0045"
#define  set_SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_ACK_NUM_reg))
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num_shift                   (0)
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num_mask                    (0xFFFFFFFF)
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num(data)                   (0xFFFFFFFF&(data))
#define  SBX_SBX_PC_SYS_prog_2_ACK_NUM_get_sys_prog2_ack_num(data)               (0xFFFFFFFF&(data))

#define  SBX_SBX_PC_SYS_prog_cmd_num_0                                           0x1801C174
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_reg_addr                                  "0xB801C174"
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_reg                                       0xB801C174
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_inst_addr                                 "0x0046"
#define  set_SBX_SBX_PC_SYS_prog_cmd_num_0_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_cmd_num_0_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_cmd_num_0_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_cmd_num_0_reg))
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2_shift               (16)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1_shift               (8)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0_shift               (0)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2_mask                (0x00FF0000)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1_mask                (0x0000FF00)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0_mask                (0x000000FF)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2(data)               (0x00FF0000&((data)<<16))
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1(data)               (0x0000FF00&((data)<<8))
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0(data)               (0x000000FF&(data))
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog2(data)           ((0x00FF0000&(data))>>16)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog1(data)           ((0x0000FF00&(data))>>8)
#define  SBX_SBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog0(data)           (0x000000FF&(data))

#define  SBX_SBX_PC_SYS_prog_cmd_num_1                                           0x1801C178
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_reg_addr                                  "0xB801C178"
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_reg                                       0xB801C178
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_inst_addr                                 "0x0047"
#define  set_SBX_SBX_PC_SYS_prog_cmd_num_1_reg(data)                             (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_cmd_num_1_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_cmd_num_1_reg                                   (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_cmd_num_1_reg))
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2_shift               (16)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1_shift               (8)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0_shift               (0)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2_mask                (0x00FF0000)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1_mask                (0x0000FF00)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0_mask                (0x000000FF)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2(data)               (0x00FF0000&((data)<<16))
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1(data)               (0x0000FF00&((data)<<8))
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0(data)               (0x000000FF&(data))
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog2(data)           ((0x00FF0000&(data))>>16)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog1(data)           ((0x0000FF00&(data))>>8)
#define  SBX_SBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog0(data)           (0x000000FF&(data))

#define  SBX_SBX_PC_SYS_prog_0                                                   0x1801C190
#define  SBX_SBX_PC_SYS_prog_0_reg_addr                                          "0xB801C190"
#define  SBX_SBX_PC_SYS_prog_0_reg                                               0xB801C190
#define  SBX_SBX_PC_SYS_prog_0_inst_addr                                         "0x0048"
#define  set_SBX_SBX_PC_SYS_prog_0_reg(data)                                     (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_0_reg                                           (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_0_reg))
#define  SBX_SBX_PC_SYS_prog_0_sys0_hitend_cnt_shift                             (0)
#define  SBX_SBX_PC_SYS_prog_0_sys0_hitend_cnt_mask                              (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_0_sys0_hitend_cnt(data)                             (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_0_get_sys0_hitend_cnt(data)                         (0x0000FFFF&(data))

#define  SBX_SBX_PC_SYS_prog_1                                                   0x1801C194
#define  SBX_SBX_PC_SYS_prog_1_reg_addr                                          "0xB801C194"
#define  SBX_SBX_PC_SYS_prog_1_reg                                               0xB801C194
#define  SBX_SBX_PC_SYS_prog_1_inst_addr                                         "0x0049"
#define  set_SBX_SBX_PC_SYS_prog_1_reg(data)                                     (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_1_reg                                           (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_1_reg))
#define  SBX_SBX_PC_SYS_prog_1_sys1_hitend_cnt_shift                             (0)
#define  SBX_SBX_PC_SYS_prog_1_sys1_hitend_cnt_mask                              (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_1_sys1_hitend_cnt(data)                             (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_1_get_sys1_hitend_cnt(data)                         (0x0000FFFF&(data))

#define  SBX_SBX_PC_SYS_prog_2                                                   0x1801C198
#define  SBX_SBX_PC_SYS_prog_2_reg_addr                                          "0xB801C198"
#define  SBX_SBX_PC_SYS_prog_2_reg                                               0xB801C198
#define  SBX_SBX_PC_SYS_prog_2_inst_addr                                         "0x004A"
#define  set_SBX_SBX_PC_SYS_prog_2_reg(data)                                     (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_reg)=data)
#define  get_SBX_SBX_PC_SYS_prog_2_reg                                           (*((volatile unsigned int*)SBX_SBX_PC_SYS_prog_2_reg))
#define  SBX_SBX_PC_SYS_prog_2_sys2_hitend_cnt_shift                             (0)
#define  SBX_SBX_PC_SYS_prog_2_sys2_hitend_cnt_mask                              (0x0000FFFF)
#define  SBX_SBX_PC_SYS_prog_2_sys2_hitend_cnt(data)                             (0x0000FFFF&(data))
#define  SBX_SBX_PC_SYS_prog_2_get_sys2_hitend_cnt(data)                         (0x0000FFFF&(data))

#define  SBX_SSBX_PC_CTRL                                                        0x1801C880
#define  SBX_SSBX_PC_CTRL_reg_addr                                               "0xB801C880"
#define  SBX_SSBX_PC_CTRL_reg                                                    0xB801C880
#define  SBX_SSBX_PC_CTRL_inst_addr                                              "0x004B"
#define  set_SBX_SSBX_PC_CTRL_reg(data)                                          (*((volatile unsigned int*)SBX_SSBX_PC_CTRL_reg)=data)
#define  get_SBX_SSBX_PC_CTRL_reg                                                (*((volatile unsigned int*)SBX_SSBX_PC_CTRL_reg))
#define  SBX_SSBX_PC_CTRL_pc_rcmd_only_shift                                     (31)
#define  SBX_SSBX_PC_CTRL_pc_go_shift                                            (0)
#define  SBX_SSBX_PC_CTRL_pc_rcmd_only_mask                                      (0x80000000)
#define  SBX_SSBX_PC_CTRL_pc_go_mask                                             (0x00000001)
#define  SBX_SSBX_PC_CTRL_pc_rcmd_only(data)                                     (0x80000000&((data)<<31))
#define  SBX_SSBX_PC_CTRL_pc_go(data)                                            (0x00000001&(data))
#define  SBX_SSBX_PC_CTRL_get_pc_rcmd_only(data)                                 ((0x80000000&(data))>>31)
#define  SBX_SSBX_PC_CTRL_get_pc_go(data)                                        (0x00000001&(data))

#define  SBX_SSBX_PC_TOTA_MON_NUM                                                0x1801C884
#define  SBX_SSBX_PC_TOTA_MON_NUM_reg_addr                                       "0xB801C884"
#define  SBX_SSBX_PC_TOTA_MON_NUM_reg                                            0xB801C884
#define  SBX_SSBX_PC_TOTA_MON_NUM_inst_addr                                      "0x004C"
#define  set_SBX_SSBX_PC_TOTA_MON_NUM_reg(data)                                  (*((volatile unsigned int*)SBX_SSBX_PC_TOTA_MON_NUM_reg)=data)
#define  get_SBX_SSBX_PC_TOTA_MON_NUM_reg                                        (*((volatile unsigned int*)SBX_SSBX_PC_TOTA_MON_NUM_reg))
#define  SBX_SSBX_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                          (0)
#define  SBX_SSBX_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                           (0xFFFFFFFF)
#define  SBX_SSBX_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                          (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)                      (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_ctrl                                               0x1801C890
#define  SBX_SSBX_PC_SYS_prog_ctrl_reg_addr                                      "0xB801C890"
#define  SBX_SSBX_PC_SYS_prog_ctrl_reg                                           0xB801C890
#define  SBX_SSBX_PC_SYS_prog_ctrl_inst_addr                                     "0x004D"
#define  set_SBX_SSBX_PC_SYS_prog_ctrl_reg(data)                                 (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_ctrl_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_ctrl_reg                                       (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_ctrl_reg))
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_3_shift                              (23)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel_shift                        (16)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_2_shift                              (15)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel_shift                        (8)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_1_shift                              (7)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel_shift                        (0)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_3_mask                               (0x00800000)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel_mask                         (0x007F0000)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_2_mask                               (0x00008000)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel_mask                         (0x00007F00)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_1_mask                               (0x00000080)
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel_mask                         (0x0000007F)
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_3(data)                              (0x00800000&((data)<<23))
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog2_sel(data)                        (0x007F0000&((data)<<16))
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_2(data)                              (0x00008000&((data)<<15))
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog1_sel(data)                        (0x00007F00&((data)<<8))
#define  SBX_SSBX_PC_SYS_prog_ctrl_write_en_1(data)                              (0x00000080&((data)<<7))
#define  SBX_SSBX_PC_SYS_prog_ctrl_pc_sys_prog0_sel(data)                        (0x0000007F&(data))
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_write_en_3(data)                          ((0x00800000&(data))>>23)
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_pc_sys_prog2_sel(data)                    ((0x007F0000&(data))>>16)
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_write_en_2(data)                          ((0x00008000&(data))>>15)
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_pc_sys_prog1_sel(data)                    ((0x00007F00&(data))>>8)
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_write_en_1(data)                          ((0x00000080&(data))>>7)
#define  SBX_SSBX_PC_SYS_prog_ctrl_get_pc_sys_prog0_sel(data)                    (0x0000007F&(data))

#define  SBX_SSBX_PC_SYS_prog_ctrl1                                              0x1801C894
#define  SBX_SSBX_PC_SYS_prog_ctrl1_reg_addr                                     "0xB801C894"
#define  SBX_SSBX_PC_SYS_prog_ctrl1_reg                                          0xB801C894
#define  SBX_SSBX_PC_SYS_prog_ctrl1_inst_addr                                    "0x004E"
#define  set_SBX_SSBX_PC_SYS_prog_ctrl1_reg(data)                                (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_ctrl1_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_ctrl1_reg                                      (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_ctrl1_reg))
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur_shift                 (6)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur_shift                 (5)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur_shift                 (4)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur_mask                  (0x00000040)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur_mask                  (0x00000020)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur_mask                  (0x00000010)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog2_req_occur(data)                 (0x00000040&((data)<<6))
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog1_req_occur(data)                 (0x00000020&((data)<<5))
#define  SBX_SSBX_PC_SYS_prog_ctrl1_pc_sys_prog0_req_occur(data)                 (0x00000010&((data)<<4))
#define  SBX_SSBX_PC_SYS_prog_ctrl1_get_pc_sys_prog2_req_occur(data)             ((0x00000040&(data))>>6)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_get_pc_sys_prog1_req_occur(data)             ((0x00000020&(data))>>5)
#define  SBX_SSBX_PC_SYS_prog_ctrl1_get_pc_sys_prog0_req_occur(data)             ((0x00000010&(data))>>4)

#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT                                          0x1801C8A0
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg_addr                                 "0xB801C8A0"
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg                                      0xB801C8A0
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_inst_addr                                "0x004F"
#define  set_SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_ACC_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_sys_prog0_acc_lat(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_0_ACC_LAT_get_sys_prog0_acc_lat(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT                                          0x1801C8A4
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg_addr                                 "0xB801C8A4"
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg                                      0xB801C8A4
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_inst_addr                                "0x0050"
#define  set_SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_MAX_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat_mask                   (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_sys_prog0_max_lat(data)                  (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_0_MAX_LAT_get_sys_prog0_max_lat(data)              (0x0000FFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM                                          0x1801C8A8
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg_addr                                 "0xB801C8A8"
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg                                      0xB801C8A8
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_inst_addr                                "0x0051"
#define  set_SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_REQ_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num_mask                   (0x00FFFFFF)
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_sys_prog0_req_num(data)                  (0x00FFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_0_REQ_NUM_get_sys_prog0_req_num(data)              (0x00FFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM                                          0x1801C8AC
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg_addr                                 "0xB801C8AC"
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg                                      0xB801C8AC
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_inst_addr                                "0x0052"
#define  set_SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_ACK_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_sys_prog0_ack_num(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_0_ACK_NUM_get_sys_prog0_ack_num(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT                                          0x1801C8B0
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg_addr                                 "0xB801C8B0"
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg                                      0xB801C8B0
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_inst_addr                                "0x0053"
#define  set_SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_ACC_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_sys_prog1_acc_lat(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_1_ACC_LAT_get_sys_prog1_acc_lat(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT                                          0x1801C8B4
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg_addr                                 "0xB801C8B4"
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg                                      0xB801C8B4
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_inst_addr                                "0x0054"
#define  set_SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_MAX_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat_mask                   (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_sys_prog1_max_lat(data)                  (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_1_MAX_LAT_get_sys_prog1_max_lat(data)              (0x0000FFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM                                          0x1801C8B8
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg_addr                                 "0xB801C8B8"
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg                                      0xB801C8B8
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_inst_addr                                "0x0055"
#define  set_SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_REQ_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num_mask                   (0x00FFFFFF)
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_sys_prog1_req_num(data)                  (0x00FFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_1_REQ_NUM_get_sys_prog1_req_num(data)              (0x00FFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM                                          0x1801C8BC
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg_addr                                 "0xB801C8BC"
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg                                      0xB801C8BC
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_inst_addr                                "0x0056"
#define  set_SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_ACK_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_sys_prog1_ack_num(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_1_ACK_NUM_get_sys_prog1_ack_num(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT                                          0x1801C8C0
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg_addr                                 "0xB801C8C0"
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg                                      0xB801C8C0
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_inst_addr                                "0x0057"
#define  set_SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_ACC_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_sys_prog2_acc_lat(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_2_ACC_LAT_get_sys_prog2_acc_lat(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT                                          0x1801C8C4
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg_addr                                 "0xB801C8C4"
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg                                      0xB801C8C4
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_inst_addr                                "0x0058"
#define  set_SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_MAX_LAT_reg))
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat_mask                   (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_sys_prog2_max_lat(data)                  (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_2_MAX_LAT_get_sys_prog2_max_lat(data)              (0x0000FFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM                                          0x1801C8C8
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg_addr                                 "0xB801C8C8"
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg                                      0xB801C8C8
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_inst_addr                                "0x0059"
#define  set_SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_REQ_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num_mask                   (0x00FFFFFF)
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_sys_prog2_req_num(data)                  (0x00FFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_2_REQ_NUM_get_sys_prog2_req_num(data)              (0x00FFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM                                          0x1801C8CC
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg_addr                                 "0xB801C8CC"
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg                                      0xB801C8CC
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_inst_addr                                "0x005A"
#define  set_SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_ACK_NUM_reg))
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num_shift                  (0)
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num_mask                   (0xFFFFFFFF)
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_sys_prog2_ack_num(data)                  (0xFFFFFFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_2_ACK_NUM_get_sys_prog2_ack_num(data)              (0xFFFFFFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_cmd_num_0                                          0x1801C8D0
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_reg_addr                                 "0xB801C8D0"
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_reg                                      0xB801C8D0
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_inst_addr                                "0x005B"
#define  set_SBX_SSBX_PC_SYS_prog_cmd_num_0_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_cmd_num_0_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_cmd_num_0_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_cmd_num_0_reg))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2_shift              (16)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1_shift              (8)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0_shift              (0)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2_mask               (0x00FF0000)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1_mask               (0x0000FF00)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0_mask               (0x000000FF)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog2(data)              (0x00FF0000&((data)<<16))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog1(data)              (0x0000FF00&((data)<<8))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_remain_cmd_num0_prog0(data)              (0x000000FF&(data))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog2(data)          ((0x00FF0000&(data))>>16)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog1(data)          ((0x0000FF00&(data))>>8)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_0_get_remain_cmd_num0_prog0(data)          (0x000000FF&(data))

#define  SBX_SSBX_PC_SYS_prog_cmd_num_1                                          0x1801C8D4
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_reg_addr                                 "0xB801C8D4"
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_reg                                      0xB801C8D4
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_inst_addr                                "0x005C"
#define  set_SBX_SSBX_PC_SYS_prog_cmd_num_1_reg(data)                            (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_cmd_num_1_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_cmd_num_1_reg                                  (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_cmd_num_1_reg))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2_shift              (16)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1_shift              (8)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0_shift              (0)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2_mask               (0x00FF0000)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1_mask               (0x0000FF00)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0_mask               (0x000000FF)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog2(data)              (0x00FF0000&((data)<<16))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog1(data)              (0x0000FF00&((data)<<8))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_remain_cmd_num1_prog0(data)              (0x000000FF&(data))
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog2(data)          ((0x00FF0000&(data))>>16)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog1(data)          ((0x0000FF00&(data))>>8)
#define  SBX_SSBX_PC_SYS_prog_cmd_num_1_get_remain_cmd_num1_prog0(data)          (0x000000FF&(data))

#define  SBX_SSBX_PC_SYS_prog_0                                                  0x1801C8E0
#define  SBX_SSBX_PC_SYS_prog_0_reg_addr                                         "0xB801C8E0"
#define  SBX_SSBX_PC_SYS_prog_0_reg                                              0xB801C8E0
#define  SBX_SSBX_PC_SYS_prog_0_inst_addr                                        "0x005D"
#define  set_SBX_SSBX_PC_SYS_prog_0_reg(data)                                    (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_0_reg                                          (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_0_reg))
#define  SBX_SSBX_PC_SYS_prog_0_sys0_hitend_cnt_shift                            (0)
#define  SBX_SSBX_PC_SYS_prog_0_sys0_hitend_cnt_mask                             (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_0_sys0_hitend_cnt(data)                            (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_0_get_sys0_hitend_cnt(data)                        (0x0000FFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_1                                                  0x1801C8E4
#define  SBX_SSBX_PC_SYS_prog_1_reg_addr                                         "0xB801C8E4"
#define  SBX_SSBX_PC_SYS_prog_1_reg                                              0xB801C8E4
#define  SBX_SSBX_PC_SYS_prog_1_inst_addr                                        "0x005E"
#define  set_SBX_SSBX_PC_SYS_prog_1_reg(data)                                    (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_1_reg                                          (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_1_reg))
#define  SBX_SSBX_PC_SYS_prog_1_sys1_hitend_cnt_shift                            (0)
#define  SBX_SSBX_PC_SYS_prog_1_sys1_hitend_cnt_mask                             (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_1_sys1_hitend_cnt(data)                            (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_1_get_sys1_hitend_cnt(data)                        (0x0000FFFF&(data))

#define  SBX_SSBX_PC_SYS_prog_2                                                  0x1801C8E8
#define  SBX_SSBX_PC_SYS_prog_2_reg_addr                                         "0xB801C8E8"
#define  SBX_SSBX_PC_SYS_prog_2_reg                                              0xB801C8E8
#define  SBX_SSBX_PC_SYS_prog_2_inst_addr                                        "0x005F"
#define  set_SBX_SSBX_PC_SYS_prog_2_reg(data)                                    (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_reg)=data)
#define  get_SBX_SSBX_PC_SYS_prog_2_reg                                          (*((volatile unsigned int*)SBX_SSBX_PC_SYS_prog_2_reg))
#define  SBX_SSBX_PC_SYS_prog_2_sys2_hitend_cnt_shift                            (0)
#define  SBX_SSBX_PC_SYS_prog_2_sys2_hitend_cnt_mask                             (0x0000FFFF)
#define  SBX_SSBX_PC_SYS_prog_2_sys2_hitend_cnt(data)                            (0x0000FFFF&(data))
#define  SBX_SSBX_PC_SYS_prog_2_get_sys2_hitend_cnt(data)                        (0x0000FFFF&(data))

#define  SBX_SBX_TS_DBG                                                          0x1801C1F0
#define  SBX_SBX_TS_DBG_reg_addr                                                 "0xB801C1F0"
#define  SBX_SBX_TS_DBG_reg                                                      0xB801C1F0
#define  SBX_SBX_TS_DBG_inst_addr                                                "0x0060"
#define  set_SBX_SBX_TS_DBG_reg(data)                                            (*((volatile unsigned int*)SBX_SBX_TS_DBG_reg)=data)
#define  get_SBX_SBX_TS_DBG_reg                                                  (*((volatile unsigned int*)SBX_SBX_TS_DBG_reg))
#define  SBX_SBX_TS_DBG_ts_dbg_sel_shift                                         (16)
#define  SBX_SBX_TS_DBG_ts_dbg_out_shift                                         (0)
#define  SBX_SBX_TS_DBG_ts_dbg_sel_mask                                          (0x000F0000)
#define  SBX_SBX_TS_DBG_ts_dbg_out_mask                                          (0x000000FF)
#define  SBX_SBX_TS_DBG_ts_dbg_sel(data)                                         (0x000F0000&((data)<<16))
#define  SBX_SBX_TS_DBG_ts_dbg_out(data)                                         (0x000000FF&(data))
#define  SBX_SBX_TS_DBG_get_ts_dbg_sel(data)                                     ((0x000F0000&(data))>>16)
#define  SBX_SBX_TS_DBG_get_ts_dbg_out(data)                                     (0x000000FF&(data))

#define  SBX_SSBX_TS_DBG                                                         0x1801C8F0
#define  SBX_SSBX_TS_DBG_reg_addr                                                "0xB801C8F0"
#define  SBX_SSBX_TS_DBG_reg                                                     0xB801C8F0
#define  SBX_SSBX_TS_DBG_inst_addr                                               "0x0061"
#define  set_SBX_SSBX_TS_DBG_reg(data)                                           (*((volatile unsigned int*)SBX_SSBX_TS_DBG_reg)=data)
#define  get_SBX_SSBX_TS_DBG_reg                                                 (*((volatile unsigned int*)SBX_SSBX_TS_DBG_reg))
#define  SBX_SSBX_TS_DBG_ts_dbg_sel_shift                                        (16)
#define  SBX_SSBX_TS_DBG_ts_dbg_out_shift                                        (0)
#define  SBX_SSBX_TS_DBG_ts_dbg_sel_mask                                         (0x000F0000)
#define  SBX_SSBX_TS_DBG_ts_dbg_out_mask                                         (0x000000FF)
#define  SBX_SSBX_TS_DBG_ts_dbg_sel(data)                                        (0x000F0000&((data)<<16))
#define  SBX_SSBX_TS_DBG_ts_dbg_out(data)                                        (0x000000FF&(data))
#define  SBX_SSBX_TS_DBG_get_ts_dbg_sel(data)                                    ((0x000F0000&(data))>>16)
#define  SBX_SSBX_TS_DBG_get_ts_dbg_out(data)                                    (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SBX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c0_latcnt_beg:8;
    };
}sbx_sb1_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c1_latcnt_beg:8;
    };
}sbx_sb1_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c2_latcnt_beg:8;
    };
}sbx_sb1_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c3_latcnt_beg:8;
    };
}sbx_sb1_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c4_latcnt_beg:8;
    };
}sbx_sb1_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c5_latcnt_beg:8;
    };
}sbx_sb1_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c6_latcnt_beg:8;
    };
}sbx_sb1_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c7_latcnt_beg:8;
    };
}sbx_sb1_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_pri_cnt_period:8;
    };
}sbx_sb1_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_req_mask_index:8;
    };
}sbx_sb1_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_req_busy_index:8;
    };
}sbx_sb1_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  sb1_allow_cmd_cnt:3;
    };
}sbx_sb1_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sf_tx_mode_emmc:1;
        RBus_UInt32  dummy1801c040_6:1;
        RBus_UInt32  sf_tx_mode_etn:1;
        RBus_UInt32  dummy1801c040_4_3:2;
        RBus_UInt32  sf_tx_mode_usb:1;
        RBus_UInt32  sf_tx_mode_usb_ex:1;
        RBus_UInt32  sf_tx_mode_ssb1:1;
    };
}sbx_sb1_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_tx_work_ro_emmc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_tx_work_ro_etn:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  sf_tx_work_ro_usb:1;
        RBus_UInt32  sf_tx_work_ro_usb_ex:1;
        RBus_UInt32  sf_tx_work_ro_ssb1:1;
        RBus_UInt32  res4:8;
        RBus_UInt32  sf_tx_start_emmc:1;
        RBus_UInt32  dummy1801c044_6:1;
        RBus_UInt32  sf_tx_start_etn:1;
        RBus_UInt32  dummy1801c044_4_3:2;
        RBus_UInt32  sf_tx_start_usb:1;
        RBus_UInt32  sf_tx_start_usb_ex:1;
        RBus_UInt32  sf_tx_start_ssb1:1;
    };
}sbx_sb1_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_rx_gated_emmc:1;
        RBus_UInt32  dummy1801c048_22:1;
        RBus_UInt32  sf_rx_gated_etn:1;
        RBus_UInt32  dummy1801c048_20_19:2;
        RBus_UInt32  sf_rx_gated_usb:1;
        RBus_UInt32  sf_rx_gated_usb_ex:1;
        RBus_UInt32  sf_rx_gated_ssb1:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  sf_rx_mode_emmc:1;
        RBus_UInt32  dummy1801c048_6:1;
        RBus_UInt32  sf_rx_mode_etn:1;
        RBus_UInt32  dummy1801c048_4_3:2;
        RBus_UInt32  sf_rx_mode_usb:1;
        RBus_UInt32  sf_rx_mode_usb_ex:1;
        RBus_UInt32  sf_rx_mode_ssb1:1;
    };
}sbx_sb1_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_rx_done_ro_emmc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_rx_done_ro_etn:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  sf_rx_done_ro_usb:1;
        RBus_UInt32  sf_rx_done_ro_usb_ex:1;
        RBus_UInt32  sf_rx_done_ro_ssb1:1;
        RBus_UInt32  res4:8;
        RBus_UInt32  sf_rx_start_emmc:1;
        RBus_UInt32  dummy1801c04c_6:1;
        RBus_UInt32  sf_rx_start_etn:1;
        RBus_UInt32  dummy1801c04c_4_3:2;
        RBus_UInt32  sf_rx_start_usb:1;
        RBus_UInt32  sf_rx_start_usb_ex:1;
        RBus_UInt32  sf_rx_start_ssb1:1;
    };
}sbx_sb1_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sf_rx_err_ro_emmc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_rx_err_ro_etn:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  sf_rx_err_ro_usb:1;
        RBus_UInt32  sf_rx_err_ro_usb_ex:1;
        RBus_UInt32  sf_rx_err_ro_ssb1:1;
    };
}sbx_sb1_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c0_latcnt_beg:8;
    };
}sbx_sb3_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c1_latcnt_beg:8;
    };
}sbx_sb3_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c2_latcnt_beg:8;
    };
}sbx_sb3_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c3_latcnt_beg:8;
    };
}sbx_sb3_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c4_latcnt_beg:8;
    };
}sbx_sb3_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c5_latcnt_beg:8;
    };
}sbx_sb3_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c6_latcnt_beg:8;
    };
}sbx_sb3_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c7_latcnt_beg:8;
    };
}sbx_sb3_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c8_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c8_latcnt_beg:8;
    };
}sbx_sb3_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c9_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_c9_latcnt_beg:8;
    };
}sbx_sb3_pri_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_ca_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb3_ca_latcnt_beg:8;
    };
}sbx_sb3_pri_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb3_pri_cnt_period:8;
    };
}sbx_sb3_pri_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sb3_req_mask_index:11;
    };
}sbx_sb3_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sb3_req_busy_index:11;
    };
}sbx_sb3_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  sb3_allow_cmd_cnt:3;
    };
}sbx_sb3_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sf_tx_mode_vde:1;
        RBus_UInt32  sf_tx_mode_ve:1;
        RBus_UInt32  dummy1801c240_3:1;
        RBus_UInt32  dummy1801c240_2:1;
        RBus_UInt32  sf_tx_mode_ade:1;
        RBus_UInt32  sf_tx_mode_ae:1;
    };
}sbx_sb3_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_tx_work_ro_vde:1;
        RBus_UInt32  sf_tx_work_ro_ve:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_tx_work_ro_ade:1;
        RBus_UInt32  sf_tx_work_ro_ae:1;
        RBus_UInt32  res4:10;
        RBus_UInt32  sf_tx_start_vde:1;
        RBus_UInt32  sf_tx_start_ve:1;
        RBus_UInt32  dummy1801c244_3:1;
        RBus_UInt32  dummy1801c244_2:1;
        RBus_UInt32  sf_tx_start_ade:1;
        RBus_UInt32  sf_tx_start_ae:1;
    };
}sbx_sb3_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_rx_gated_vde:1;
        RBus_UInt32  sf_rx_gated_ve:1;
        RBus_UInt32  dummy1801c248_19:1;
        RBus_UInt32  dummy1801c248_18:1;
        RBus_UInt32  sf_rx_gated_ade:1;
        RBus_UInt32  sf_rx_gated_ae:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  sf_rx_mode_vde:1;
        RBus_UInt32  sf_rx_mode_ve:1;
        RBus_UInt32  dummy1801c248_3:1;
        RBus_UInt32  dummy1801c248_2:1;
        RBus_UInt32  sf_rx_mode_ade:1;
        RBus_UInt32  sf_rx_mode_ae:1;
    };
}sbx_sb3_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_rx_done_ro_vde:1;
        RBus_UInt32  sf_rx_done_ro_ve:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_done_ro_ade:1;
        RBus_UInt32  sf_rx_done_ro_ae:1;
        RBus_UInt32  res4:10;
        RBus_UInt32  sf_rx_start_vde:1;
        RBus_UInt32  sf_rx_start_ve:1;
        RBus_UInt32  dummy1801c24c_3:1;
        RBus_UInt32  dummy1801c24c_2:1;
        RBus_UInt32  sf_rx_start_ade:1;
        RBus_UInt32  sf_rx_start_ae:1;
    };
}sbx_sb3_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sf_rx_err_ro_vde:1;
        RBus_UInt32  sf_rx_err_ro_ve:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_err_ro_ade:1;
        RBus_UInt32  sf_rx_err_ro_ae:1;
    };
}sbx_sb3_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c0_latcnt_beg:8;
    };
}sbx_ssb1_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c1_latcnt_beg:8;
    };
}sbx_ssb1_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c2_latcnt_beg:8;
    };
}sbx_ssb1_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c3_latcnt_beg:8;
    };
}sbx_ssb1_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c4_latcnt_beg:8;
    };
}sbx_ssb1_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c5_latcnt_beg:8;
    };
}sbx_ssb1_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c6_latcnt_beg:8;
    };
}sbx_ssb1_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb1_c7_latcnt_beg:8;
    };
}sbx_ssb1_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_pri_cnt_period:8;
    };
}sbx_ssb1_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_req_mask_index:8;
    };
}sbx_ssb1_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sb1_req_busy_index:8;
    };
}sbx_ssb1_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  sb1_allow_cmd_cnt:3;
    };
}sbx_ssb1_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sf_tx_mode_sb1:1;
    };
}sbx_ssb1_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_tx_work_ro_sb1:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  sf_tx_start_sb1:1;
    };
}sbx_ssb1_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_rx_gated_sb1:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  sf_rx_mode_sb1:1;
    };
}sbx_ssb1_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_rx_done_ro_sb1:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  sf_rx_start_sb1:1;
    };
}sbx_ssb1_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sf_rx_err_ro_sb1:1;
    };
}sbx_ssb1_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_rcmd_only:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_go:1;
    };
}sbx_sbx_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}sbx_sbx_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_sys_prog2_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sys_prog1_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sys_prog0_sel:7;
    };
}sbx_sbx_pc_sys_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pc_sys_prog2_req_occur:1;
        RBus_UInt32  pc_sys_prog1_req_occur:1;
        RBus_UInt32  pc_sys_prog0_req_occur:1;
        RBus_UInt32  res2:4;
    };
}sbx_sbx_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog0_max_lat:16;
    };
}sbx_sbx_pc_sys_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog0_req_num:24;
    };
}sbx_sbx_pc_sys_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog1_max_lat:16;
    };
}sbx_sbx_pc_sys_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog1_req_num:24;
    };
}sbx_sbx_pc_sys_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog2_max_lat:16;
    };
}sbx_sbx_pc_sys_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog2_req_num:24;
    };
}sbx_sbx_pc_sys_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog0:8;
    };
}sbx_sbx_pc_sys_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog0:8;
    };
}sbx_sbx_pc_sys_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys0_hitend_cnt:16;
    };
}sbx_sbx_pc_sys_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys1_hitend_cnt:16;
    };
}sbx_sbx_pc_sys_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys2_hitend_cnt:16;
    };
}sbx_sbx_pc_sys_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_rcmd_only:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_go:1;
    };
}sbx_ssbx_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}sbx_ssbx_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_sys_prog2_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sys_prog1_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sys_prog0_sel:7;
    };
}sbx_ssbx_pc_sys_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pc_sys_prog2_req_occur:1;
        RBus_UInt32  pc_sys_prog1_req_occur:1;
        RBus_UInt32  pc_sys_prog0_req_occur:1;
        RBus_UInt32  res2:4;
    };
}sbx_ssbx_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog0_max_lat:16;
    };
}sbx_ssbx_pc_sys_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog0_req_num:24;
    };
}sbx_ssbx_pc_sys_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog1_max_lat:16;
    };
}sbx_ssbx_pc_sys_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog1_req_num:24;
    };
}sbx_ssbx_pc_sys_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys_prog2_max_lat:16;
    };
}sbx_ssbx_pc_sys_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sys_prog2_req_num:24;
    };
}sbx_ssbx_pc_sys_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog0:8;
    };
}sbx_ssbx_pc_sys_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog0:8;
    };
}sbx_ssbx_pc_sys_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys0_hitend_cnt:16;
    };
}sbx_ssbx_pc_sys_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys1_hitend_cnt:16;
    };
}sbx_ssbx_pc_sys_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sys2_hitend_cnt:16;
    };
}sbx_ssbx_pc_sys_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  ts_dbg_out:8;
    };
}sbx_sbx_ts_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  ts_dbg_out:8;
    };
}sbx_ssbx_ts_dbg_RBUS;

#else //apply LITTLE_ENDIAN

//======SBX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_pri_cnt_period:8;
        RBus_UInt32  res1:24;
    };
}sbx_sb1_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_req_mask_index:8;
        RBus_UInt32  res1:24;
    };
}sbx_sb1_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_req_busy_index:8;
        RBus_UInt32  res1:24;
    };
}sbx_sb1_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_allow_cmd_cnt:3;
        RBus_UInt32  res1:29;
    };
}sbx_sb1_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_mode_ssb1:1;
        RBus_UInt32  sf_tx_mode_usb_ex:1;
        RBus_UInt32  sf_tx_mode_usb:1;
        RBus_UInt32  dummy1801c040_4_3:2;
        RBus_UInt32  sf_tx_mode_etn:1;
        RBus_UInt32  dummy1801c040_6:1;
        RBus_UInt32  sf_tx_mode_emmc:1;
        RBus_UInt32  res1:24;
    };
}sbx_sb1_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_start_ssb1:1;
        RBus_UInt32  sf_tx_start_usb_ex:1;
        RBus_UInt32  sf_tx_start_usb:1;
        RBus_UInt32  dummy1801c044_4_3:2;
        RBus_UInt32  sf_tx_start_etn:1;
        RBus_UInt32  dummy1801c044_6:1;
        RBus_UInt32  sf_tx_start_emmc:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_tx_work_ro_ssb1:1;
        RBus_UInt32  sf_tx_work_ro_usb_ex:1;
        RBus_UInt32  sf_tx_work_ro_usb:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sf_tx_work_ro_etn:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_tx_work_ro_emmc:1;
        RBus_UInt32  res4:8;
    };
}sbx_sb1_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_mode_ssb1:1;
        RBus_UInt32  sf_rx_mode_usb_ex:1;
        RBus_UInt32  sf_rx_mode_usb:1;
        RBus_UInt32  dummy1801c048_4_3:2;
        RBus_UInt32  sf_rx_mode_etn:1;
        RBus_UInt32  dummy1801c048_6:1;
        RBus_UInt32  sf_rx_mode_emmc:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_rx_gated_ssb1:1;
        RBus_UInt32  sf_rx_gated_usb_ex:1;
        RBus_UInt32  sf_rx_gated_usb:1;
        RBus_UInt32  dummy1801c048_20_19:2;
        RBus_UInt32  sf_rx_gated_etn:1;
        RBus_UInt32  dummy1801c048_22:1;
        RBus_UInt32  sf_rx_gated_emmc:1;
        RBus_UInt32  res2:8;
    };
}sbx_sb1_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_start_ssb1:1;
        RBus_UInt32  sf_rx_start_usb_ex:1;
        RBus_UInt32  sf_rx_start_usb:1;
        RBus_UInt32  dummy1801c04c_4_3:2;
        RBus_UInt32  sf_rx_start_etn:1;
        RBus_UInt32  dummy1801c04c_6:1;
        RBus_UInt32  sf_rx_start_emmc:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  sf_rx_done_ro_ssb1:1;
        RBus_UInt32  sf_rx_done_ro_usb_ex:1;
        RBus_UInt32  sf_rx_done_ro_usb:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sf_rx_done_ro_etn:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_done_ro_emmc:1;
        RBus_UInt32  res4:8;
    };
}sbx_sb1_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_err_ro_ssb1:1;
        RBus_UInt32  sf_rx_err_ro_usb_ex:1;
        RBus_UInt32  sf_rx_err_ro_usb:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  sf_rx_err_ro_etn:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_rx_err_ro_emmc:1;
        RBus_UInt32  res3:24;
    };
}sbx_sb1_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c8_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c8_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_c9_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_c9_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_ca_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb3_ca_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_sb3_pri_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_pri_cnt_period:8;
        RBus_UInt32  res1:24;
    };
}sbx_sb3_pri_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_req_mask_index:11;
        RBus_UInt32  res1:21;
    };
}sbx_sb3_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_req_busy_index:11;
        RBus_UInt32  res1:21;
    };
}sbx_sb3_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb3_allow_cmd_cnt:3;
        RBus_UInt32  res1:29;
    };
}sbx_sb3_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_mode_ae:1;
        RBus_UInt32  sf_tx_mode_ade:1;
        RBus_UInt32  dummy1801c240_2:1;
        RBus_UInt32  dummy1801c240_3:1;
        RBus_UInt32  sf_tx_mode_ve:1;
        RBus_UInt32  sf_tx_mode_vde:1;
        RBus_UInt32  res1:26;
    };
}sbx_sb3_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_start_ae:1;
        RBus_UInt32  sf_tx_start_ade:1;
        RBus_UInt32  dummy1801c244_2:1;
        RBus_UInt32  dummy1801c244_3:1;
        RBus_UInt32  sf_tx_start_ve:1;
        RBus_UInt32  sf_tx_start_vde:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_tx_work_ro_ae:1;
        RBus_UInt32  sf_tx_work_ro_ade:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_tx_work_ro_ve:1;
        RBus_UInt32  sf_tx_work_ro_vde:1;
        RBus_UInt32  res4:10;
    };
}sbx_sb3_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_mode_ae:1;
        RBus_UInt32  sf_rx_mode_ade:1;
        RBus_UInt32  dummy1801c248_2:1;
        RBus_UInt32  dummy1801c248_3:1;
        RBus_UInt32  sf_rx_mode_ve:1;
        RBus_UInt32  sf_rx_mode_vde:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_rx_gated_ae:1;
        RBus_UInt32  sf_rx_gated_ade:1;
        RBus_UInt32  dummy1801c248_18:1;
        RBus_UInt32  dummy1801c248_19:1;
        RBus_UInt32  sf_rx_gated_ve:1;
        RBus_UInt32  sf_rx_gated_vde:1;
        RBus_UInt32  res2:10;
    };
}sbx_sb3_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_start_ae:1;
        RBus_UInt32  sf_rx_start_ade:1;
        RBus_UInt32  dummy1801c24c_2:1;
        RBus_UInt32  dummy1801c24c_3:1;
        RBus_UInt32  sf_rx_start_ve:1;
        RBus_UInt32  sf_rx_start_vde:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  sf_rx_done_ro_ae:1;
        RBus_UInt32  sf_rx_done_ro_ade:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_done_ro_ve:1;
        RBus_UInt32  sf_rx_done_ro_vde:1;
        RBus_UInt32  res4:10;
    };
}sbx_sb3_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_err_ro_ae:1;
        RBus_UInt32  sf_rx_err_ro_ade:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_rx_err_ro_ve:1;
        RBus_UInt32  sf_rx_err_ro_vde:1;
        RBus_UInt32  res3:26;
    };
}sbx_sb3_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb1_c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}sbx_ssb1_pri_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_pri_cnt_period:8;
        RBus_UInt32  res1:24;
    };
}sbx_ssb1_pri_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_req_mask_index:8;
        RBus_UInt32  res1:24;
    };
}sbx_ssb1_channel_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_req_busy_index:8;
        RBus_UInt32  res1:24;
    };
}sbx_ssb1_channel_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb1_allow_cmd_cnt:3;
        RBus_UInt32  res1:29;
    };
}sbx_ssb1_misc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_mode_sb1:1;
        RBus_UInt32  res1:31;
    };
}sbx_ssb1_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_start_sb1:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_tx_work_ro_sb1:1;
        RBus_UInt32  res2:15;
    };
}sbx_ssb1_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_mode_sb1:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_rx_gated_sb1:1;
        RBus_UInt32  res2:15;
    };
}sbx_ssb1_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_start_sb1:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  sf_rx_done_ro_sb1:1;
        RBus_UInt32  res2:15;
    };
}sbx_ssb1_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_err_ro_sb1:1;
        RBus_UInt32  res1:31;
    };
}sbx_ssb1_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_rcmd_only:1;
    };
}sbx_sbx_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}sbx_sbx_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_sys_prog0_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sys_prog1_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sys_prog2_sel:7;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pc_sys_prog0_req_occur:1;
        RBus_UInt32  pc_sys_prog1_req_occur:1;
        RBus_UInt32  pc_sys_prog2_req_occur:1;
        RBus_UInt32  res2:25;
    };
}sbx_sbx_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_acc_lat:32;
    };
}sbx_sbx_pc_sys_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_ack_num:32;
    };
}sbx_sbx_pc_sys_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num0_prog0:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num1_prog0:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  res1:8;
    };
}sbx_sbx_pc_sys_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys0_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys1_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys2_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_sbx_pc_sys_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_rcmd_only:1;
    };
}sbx_ssbx_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}sbx_ssbx_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_sys_prog0_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sys_prog1_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sys_prog2_sel:7;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pc_sys_prog0_req_occur:1;
        RBus_UInt32  pc_sys_prog1_req_occur:1;
        RBus_UInt32  pc_sys_prog2_req_occur:1;
        RBus_UInt32  res2:25;
    };
}sbx_ssbx_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog0_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog1_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_acc_lat:32;
    };
}sbx_ssbx_pc_sys_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_max_lat:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_req_num:24;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys_prog2_ack_num:32;
    };
}sbx_ssbx_pc_sys_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num0_prog0:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num1_prog0:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  res1:8;
    };
}sbx_ssbx_pc_sys_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys0_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys1_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sys2_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}sbx_ssbx_pc_sys_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_dbg_out:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:12;
    };
}sbx_sbx_ts_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_dbg_out:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:12;
    };
}sbx_ssbx_ts_dbg_RBUS;




#endif 


#endif 
