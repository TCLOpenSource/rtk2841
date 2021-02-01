/**
* @file rbusHDMI_P3Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HDMI_P3_REG_H_
#define _RBUS_HDMI_P3_REG_H_

#include "rbus_types.h"



//  HDMI_P3 Register Address
#define  HDMI_P3_PORT3_TMDS_MSR0                                                 0x180B2000
#define  HDMI_P3_PORT3_TMDS_MSR0_reg_addr                                        "0xB80B2000"
#define  HDMI_P3_PORT3_TMDS_MSR0_reg                                             0xB80B2000
#define  HDMI_P3_PORT3_TMDS_MSR0_inst_addr                                       "0x0000"
#define  set_HDMI_P3_PORT3_TMDS_MSR0_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_MSR0_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_MSR0_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_MSR0_reg))
#define  HDMI_P3_PORT3_TMDS_MSR0_tmm_shift                                       (7)
#define  HDMI_P3_PORT3_TMDS_MSR0_mt_shift                                        (4)
#define  HDMI_P3_PORT3_TMDS_MSR0_ncp_shift                                       (0)
#define  HDMI_P3_PORT3_TMDS_MSR0_tmm_mask                                        (0x00000080)
#define  HDMI_P3_PORT3_TMDS_MSR0_mt_mask                                         (0x00000070)
#define  HDMI_P3_PORT3_TMDS_MSR0_ncp_mask                                        (0x0000000F)
#define  HDMI_P3_PORT3_TMDS_MSR0_tmm(data)                                       (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_MSR0_mt(data)                                        (0x00000070&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_MSR0_ncp(data)                                       (0x0000000F&(data))
#define  HDMI_P3_PORT3_TMDS_MSR0_get_tmm(data)                                   ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_MSR0_get_mt(data)                                    ((0x00000070&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_MSR0_get_ncp(data)                                   (0x0000000F&(data))

#define  HDMI_P3_PORT3_TMDS_MSR1                                                 0x180B2004
#define  HDMI_P3_PORT3_TMDS_MSR1_reg_addr                                        "0xB80B2004"
#define  HDMI_P3_PORT3_TMDS_MSR1_reg                                             0xB80B2004
#define  HDMI_P3_PORT3_TMDS_MSR1_inst_addr                                       "0x0001"
#define  set_HDMI_P3_PORT3_TMDS_MSR1_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_MSR1_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_MSR1_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_MSR1_reg))
#define  HDMI_P3_PORT3_TMDS_MSR1_tms_shift                                       (12)
#define  HDMI_P3_PORT3_TMDS_MSR1_mrs_shift                                       (10)
#define  HDMI_P3_PORT3_TMDS_MSR1_ms_shift                                        (8)
#define  HDMI_P3_PORT3_TMDS_MSR1_ctc_shift                                       (7)
#define  HDMI_P3_PORT3_TMDS_MSR1_vmr_shift                                       (0)
#define  HDMI_P3_PORT3_TMDS_MSR1_tms_mask                                        (0x00001000)
#define  HDMI_P3_PORT3_TMDS_MSR1_mrs_mask                                        (0x00000C00)
#define  HDMI_P3_PORT3_TMDS_MSR1_ms_mask                                         (0x00000300)
#define  HDMI_P3_PORT3_TMDS_MSR1_ctc_mask                                        (0x00000080)
#define  HDMI_P3_PORT3_TMDS_MSR1_vmr_mask                                        (0x0000007F)
#define  HDMI_P3_PORT3_TMDS_MSR1_tms(data)                                       (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_TMDS_MSR1_mrs(data)                                       (0x00000C00&((data)<<10))
#define  HDMI_P3_PORT3_TMDS_MSR1_ms(data)                                        (0x00000300&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_MSR1_ctc(data)                                       (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_MSR1_vmr(data)                                       (0x0000007F&(data))
#define  HDMI_P3_PORT3_TMDS_MSR1_get_tms(data)                                   ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_TMDS_MSR1_get_mrs(data)                                   ((0x00000C00&(data))>>10)
#define  HDMI_P3_PORT3_TMDS_MSR1_get_ms(data)                                    ((0x00000300&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_MSR1_get_ctc(data)                                   ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_MSR1_get_vmr(data)                                   (0x0000007F&(data))

#define  HDMI_P3_PORT3_TMDS_CRCC                                                 0x180B2008
#define  HDMI_P3_PORT3_TMDS_CRCC_reg_addr                                        "0xB80B2008"
#define  HDMI_P3_PORT3_TMDS_CRCC_reg                                             0xB80B2008
#define  HDMI_P3_PORT3_TMDS_CRCC_inst_addr                                       "0x0002"
#define  set_HDMI_P3_PORT3_TMDS_CRCC_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCC_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_CRCC_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCC_reg))
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_r_en_shift                                  (7)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_g_en_shift                                  (6)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_b_en_shift                                  (5)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_done_shift                                  (4)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_nonstable_shift                             (3)
#define  HDMI_P3_PORT3_TMDS_CRCC_crcts_shift                                     (1)
#define  HDMI_P3_PORT3_TMDS_CRCC_crcc_shift                                      (0)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_r_en_mask                                   (0x00000080)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_g_en_mask                                   (0x00000040)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_b_en_mask                                   (0x00000020)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_done_mask                                   (0x00000010)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_nonstable_mask                              (0x00000008)
#define  HDMI_P3_PORT3_TMDS_CRCC_crcts_mask                                      (0x00000006)
#define  HDMI_P3_PORT3_TMDS_CRCC_crcc_mask                                       (0x00000001)
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_r_en(data)                                  (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_g_en(data)                                  (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_b_en(data)                                  (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_done(data)                                  (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_CRCC_crc_nonstable(data)                             (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_CRCC_crcts(data)                                     (0x00000006&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_CRCC_crcc(data)                                      (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crc_r_en(data)                              ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crc_g_en(data)                              ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crc_b_en(data)                              ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crc_done(data)                              ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crc_nonstable(data)                         ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crcts(data)                                 ((0x00000006&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_CRCC_get_crcc(data)                                  (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_CRCO0                                                0x180B200C
#define  HDMI_P3_PORT3_TMDS_CRCO0_reg_addr                                       "0xB80B200C"
#define  HDMI_P3_PORT3_TMDS_CRCO0_reg                                            0xB80B200C
#define  HDMI_P3_PORT3_TMDS_CRCO0_inst_addr                                      "0x0003"
#define  set_HDMI_P3_PORT3_TMDS_CRCO0_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCO0_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_CRCO0_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCO0_reg))
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_3_shift                                 (16)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_2_shift                                 (8)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_1_shift                                 (0)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_3_mask                                  (0x00FF0000)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_2_mask                                  (0x0000FF00)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_1_mask                                  (0x000000FF)
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_3(data)                                 (0x00FF0000&((data)<<16))
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_2(data)                                 (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_CRCO0_crcob2_1(data)                                 (0x000000FF&(data))
#define  HDMI_P3_PORT3_TMDS_CRCO0_get_crcob2_3(data)                             ((0x00FF0000&(data))>>16)
#define  HDMI_P3_PORT3_TMDS_CRCO0_get_crcob2_2(data)                             ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_CRCO0_get_crcob2_1(data)                             (0x000000FF&(data))

#define  HDMI_P3_PORT3_TMDS_CRCO1                                                0x180B2010
#define  HDMI_P3_PORT3_TMDS_CRCO1_reg_addr                                       "0xB80B2010"
#define  HDMI_P3_PORT3_TMDS_CRCO1_reg                                            0xB80B2010
#define  HDMI_P3_PORT3_TMDS_CRCO1_inst_addr                                      "0x0004"
#define  set_HDMI_P3_PORT3_TMDS_CRCO1_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCO1_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_CRCO1_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CRCO1_reg))
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_6_shift                                 (16)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_5_shift                                 (8)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_4_shift                                 (0)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_6_mask                                  (0x00FF0000)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_5_mask                                  (0x0000FF00)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_4_mask                                  (0x000000FF)
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_6(data)                                 (0x00FF0000&((data)<<16))
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_5(data)                                 (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_CRCO1_crcob2_4(data)                                 (0x000000FF&(data))
#define  HDMI_P3_PORT3_TMDS_CRCO1_get_crcob2_6(data)                             ((0x00FF0000&(data))>>16)
#define  HDMI_P3_PORT3_TMDS_CRCO1_get_crcob2_5(data)                             ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_CRCO1_get_crcob2_4(data)                             (0x000000FF&(data))

#define  HDMI_P3_PORT3_TMDS_CTRL                                                 0x180B2014
#define  HDMI_P3_PORT3_TMDS_CTRL_reg_addr                                        "0xB80B2014"
#define  HDMI_P3_PORT3_TMDS_CTRL_reg                                             0xB80B2014
#define  HDMI_P3_PORT3_TMDS_CTRL_inst_addr                                       "0x0005"
#define  set_HDMI_P3_PORT3_TMDS_CTRL_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_CTRL_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CTRL_reg))
#define  HDMI_P3_PORT3_TMDS_CTRL_bcd_shift                                       (7)
#define  HDMI_P3_PORT3_TMDS_CTRL_gcd_shift                                       (6)
#define  HDMI_P3_PORT3_TMDS_CTRL_rcd_shift                                       (5)
#define  HDMI_P3_PORT3_TMDS_CTRL_ho_shift                                        (4)
#define  HDMI_P3_PORT3_TMDS_CTRL_yo_shift                                        (3)
#define  HDMI_P3_PORT3_TMDS_CTRL_dummy_2_0_shift                                 (0)
#define  HDMI_P3_PORT3_TMDS_CTRL_bcd_mask                                        (0x00000080)
#define  HDMI_P3_PORT3_TMDS_CTRL_gcd_mask                                        (0x00000040)
#define  HDMI_P3_PORT3_TMDS_CTRL_rcd_mask                                        (0x00000020)
#define  HDMI_P3_PORT3_TMDS_CTRL_ho_mask                                         (0x00000010)
#define  HDMI_P3_PORT3_TMDS_CTRL_yo_mask                                         (0x00000008)
#define  HDMI_P3_PORT3_TMDS_CTRL_dummy_2_0_mask                                  (0x00000007)
#define  HDMI_P3_PORT3_TMDS_CTRL_bcd(data)                                       (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_CTRL_gcd(data)                                       (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_CTRL_rcd(data)                                       (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_CTRL_ho(data)                                        (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_CTRL_yo(data)                                        (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_CTRL_dummy_2_0(data)                                 (0x00000007&(data))
#define  HDMI_P3_PORT3_TMDS_CTRL_get_bcd(data)                                   ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_CTRL_get_gcd(data)                                   ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_CTRL_get_rcd(data)                                   ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_CTRL_get_ho(data)                                    ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_CTRL_get_yo(data)                                    ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_CTRL_get_dummy_2_0(data)                             (0x00000007&(data))

#define  HDMI_P3_PORT3_TMDS_OUTCTL                                               0x180B2018
#define  HDMI_P3_PORT3_TMDS_OUTCTL_reg_addr                                      "0xB80B2018"
#define  HDMI_P3_PORT3_TMDS_OUTCTL_reg                                           0xB80B2018
#define  HDMI_P3_PORT3_TMDS_OUTCTL_inst_addr                                     "0x0006"
#define  set_HDMI_P3_PORT3_TMDS_OUTCTL_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_OUTCTL_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_OUTCTL_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_OUTCTL_reg))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe_r_shift                                 (13)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe_r_shift                                 (12)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe_r_shift                                 (11)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke_r_shift                                  (10)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_aoe_shift                                     (9)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe_shift                                   (8)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe_shift                                   (7)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe_shift                                   (6)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke_shift                                    (5)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ockie_shift                                   (4)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_focke_shift                                   (3)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_cbus_dbg_cke_shift                            (2)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_1_shift                                 (1)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_0_shift                                 (0)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe_r_mask                                  (0x00002000)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe_r_mask                                  (0x00001000)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe_r_mask                                  (0x00000800)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke_r_mask                                   (0x00000400)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_aoe_mask                                      (0x00000200)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe_mask                                    (0x00000100)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe_mask                                    (0x00000080)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe_mask                                    (0x00000040)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke_mask                                     (0x00000020)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ockie_mask                                    (0x00000010)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_focke_mask                                    (0x00000008)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_cbus_dbg_cke_mask                             (0x00000004)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_1_mask                                  (0x00000002)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_0_mask                                  (0x00000001)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe_r(data)                                 (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe_r(data)                                 (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe_r(data)                                 (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke_r(data)                                  (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_aoe(data)                                     (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_trcoe(data)                                   (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tgcoe(data)                                   (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_tbcoe(data)                                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ocke(data)                                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_ockie(data)                                   (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_focke(data)                                   (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_cbus_dbg_cke(data)                            (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_1(data)                                 (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_dummy_0(data)                                 (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_trcoe_r(data)                             ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_tgcoe_r(data)                             ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_tbcoe_r(data)                             ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_ocke_r(data)                              ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_aoe(data)                                 ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_trcoe(data)                               ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_tgcoe(data)                               ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_tbcoe(data)                               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_ocke(data)                                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_ockie(data)                               ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_focke(data)                               ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_cbus_dbg_cke(data)                        ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_dummy_1(data)                             ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_OUTCTL_get_dummy_0(data)                             (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_PWDCTL                                               0x180B201C
#define  HDMI_P3_PORT3_TMDS_PWDCTL_reg_addr                                      "0xB80B201C"
#define  HDMI_P3_PORT3_TMDS_PWDCTL_reg                                           0xB80B201C
#define  HDMI_P3_PORT3_TMDS_PWDCTL_inst_addr                                     "0x0007"
#define  set_HDMI_P3_PORT3_TMDS_PWDCTL_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_PWDCTL_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_PWDCTL_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_PWDCTL_reg))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc_r_shift                                   (31)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip_r_shift                                  (30)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip_r_shift                                  (29)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip_r_shift                                  (28)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_dummy_27_10_shift                             (10)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_video_preamble_off_en_shift                   (9)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_hs_width_sel_shift                            (8)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_deo_shift                                     (7)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_brcw_shift                                    (6)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_pnsw_shift                                    (5)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_iccaf_shift                                   (4)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc_shift                                     (3)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip_shift                                    (2)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip_shift                                    (1)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip_shift                                    (0)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc_r_mask                                    (0x80000000)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip_r_mask                                   (0x40000000)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip_r_mask                                   (0x20000000)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip_r_mask                                   (0x10000000)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_dummy_27_10_mask                              (0x0FFFFC00)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_video_preamble_off_en_mask                    (0x00000200)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_hs_width_sel_mask                             (0x00000100)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_deo_mask                                      (0x00000080)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_brcw_mask                                     (0x00000040)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_pnsw_mask                                     (0x00000020)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_iccaf_mask                                    (0x00000010)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip_mask                                     (0x00000001)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc_r(data)                                   (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip_r(data)                                  (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip_r(data)                                  (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip_r(data)                                  (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_dummy_27_10(data)                             (0x0FFFFC00&((data)<<10))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_video_preamble_off_en(data)                   (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_hs_width_sel(data)                            (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_deo(data)                                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_brcw(data)                                    (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_pnsw(data)                                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_iccaf(data)                                   (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ecc(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_erip(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_egip(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_ebip(data)                                    (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_ecc_r(data)                               ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_erip_r(data)                              ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_egip_r(data)                              ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_ebip_r(data)                              ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_dummy_27_10(data)                         ((0x0FFFFC00&(data))>>10)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_video_preamble_off_en(data)               ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_hs_width_sel(data)                        ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_deo(data)                                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_brcw(data)                                ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_pnsw(data)                                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_iccaf(data)                               ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_ecc(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_erip(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_egip(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_PWDCTL_get_ebip(data)                                (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_Z0CC                                                 0x180B2020
#define  HDMI_P3_PORT3_TMDS_Z0CC_reg_addr                                        "0xB80B2020"
#define  HDMI_P3_PORT3_TMDS_Z0CC_reg                                             0xB80B2020
#define  HDMI_P3_PORT3_TMDS_Z0CC_inst_addr                                       "0x0008"
#define  set_HDMI_P3_PORT3_TMDS_Z0CC_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_Z0CC_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_Z0CC_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_Z0CC_reg))
#define  HDMI_P3_PORT3_TMDS_Z0CC_hde_shift                                       (0)
#define  HDMI_P3_PORT3_TMDS_Z0CC_hde_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_TMDS_Z0CC_hde(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_Z0CC_get_hde(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_CPS                                                  0x180B2024
#define  HDMI_P3_PORT3_TMDS_CPS_reg_addr                                         "0xB80B2024"
#define  HDMI_P3_PORT3_TMDS_CPS_reg                                              0xB80B2024
#define  HDMI_P3_PORT3_TMDS_CPS_inst_addr                                        "0x0009"
#define  set_HDMI_P3_PORT3_TMDS_CPS_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CPS_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_CPS_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_CPS_reg))
#define  HDMI_P3_PORT3_TMDS_CPS_pll_div2_en_shift                                (9)
#define  HDMI_P3_PORT3_TMDS_CPS_no_clk_in_shift                                  (8)
#define  HDMI_P3_PORT3_TMDS_CPS_clkv_meas_sel_shift                              (6)
#define  HDMI_P3_PORT3_TMDS_CPS_de_inv_disable_shift                             (5)
#define  HDMI_P3_PORT3_TMDS_CPS_de_err_pulse_en_shift                            (4)
#define  HDMI_P3_PORT3_TMDS_CPS_clr_infoframe_dvi_shift                          (3)
#define  HDMI_P3_PORT3_TMDS_CPS_auto_dvi2hdmi_shift                              (2)
#define  HDMI_P3_PORT3_TMDS_CPS_dummy_1_0_shift                                  (0)
#define  HDMI_P3_PORT3_TMDS_CPS_pll_div2_en_mask                                 (0x00000200)
#define  HDMI_P3_PORT3_TMDS_CPS_no_clk_in_mask                                   (0x00000100)
#define  HDMI_P3_PORT3_TMDS_CPS_clkv_meas_sel_mask                               (0x000000C0)
#define  HDMI_P3_PORT3_TMDS_CPS_de_inv_disable_mask                              (0x00000020)
#define  HDMI_P3_PORT3_TMDS_CPS_de_err_pulse_en_mask                             (0x00000010)
#define  HDMI_P3_PORT3_TMDS_CPS_clr_infoframe_dvi_mask                           (0x00000008)
#define  HDMI_P3_PORT3_TMDS_CPS_auto_dvi2hdmi_mask                               (0x00000004)
#define  HDMI_P3_PORT3_TMDS_CPS_dummy_1_0_mask                                   (0x00000003)
#define  HDMI_P3_PORT3_TMDS_CPS_pll_div2_en(data)                                (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_TMDS_CPS_no_clk_in(data)                                  (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_CPS_clkv_meas_sel(data)                              (0x000000C0&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_CPS_de_inv_disable(data)                             (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_CPS_de_err_pulse_en(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_CPS_clr_infoframe_dvi(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_CPS_auto_dvi2hdmi(data)                              (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_CPS_dummy_1_0(data)                                  (0x00000003&(data))
#define  HDMI_P3_PORT3_TMDS_CPS_get_pll_div2_en(data)                            ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_TMDS_CPS_get_no_clk_in(data)                              ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_CPS_get_clkv_meas_sel(data)                          ((0x000000C0&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_CPS_get_de_inv_disable(data)                         ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_CPS_get_de_err_pulse_en(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_CPS_get_clr_infoframe_dvi(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_CPS_get_auto_dvi2hdmi(data)                          ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_CPS_get_dummy_1_0(data)                              (0x00000003&(data))

#define  HDMI_P3_PORT3_TMDS_UDC                                                  0x180B2028
#define  HDMI_P3_PORT3_TMDS_UDC_reg_addr                                         "0xB80B2028"
#define  HDMI_P3_PORT3_TMDS_UDC_reg                                              0xB80B2028
#define  HDMI_P3_PORT3_TMDS_UDC_inst_addr                                        "0x000A"
#define  set_HDMI_P3_PORT3_TMDS_UDC_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_UDC_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_UDC_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_UDC_reg))
#define  HDMI_P3_PORT3_TMDS_UDC_debug_sel_shift                                  (4)
#define  HDMI_P3_PORT3_TMDS_UDC_dummy_3_shift                                    (3)
#define  HDMI_P3_PORT3_TMDS_UDC_cptest_shift                                     (2)
#define  HDMI_P3_PORT3_TMDS_UDC_hmtm_shift                                       (0)
#define  HDMI_P3_PORT3_TMDS_UDC_debug_sel_mask                                   (0x000003F0)
#define  HDMI_P3_PORT3_TMDS_UDC_dummy_3_mask                                     (0x00000008)
#define  HDMI_P3_PORT3_TMDS_UDC_cptest_mask                                      (0x00000004)
#define  HDMI_P3_PORT3_TMDS_UDC_hmtm_mask                                        (0x00000003)
#define  HDMI_P3_PORT3_TMDS_UDC_debug_sel(data)                                  (0x000003F0&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_UDC_dummy_3(data)                                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_UDC_cptest(data)                                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_UDC_hmtm(data)                                       (0x00000003&(data))
#define  HDMI_P3_PORT3_TMDS_UDC_get_debug_sel(data)                              ((0x000003F0&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_UDC_get_dummy_3(data)                                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_UDC_get_cptest(data)                                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_UDC_get_hmtm(data)                                   (0x00000003&(data))

#define  HDMI_P3_PORT3_TMDS_ERRC                                                 0x180B202C
#define  HDMI_P3_PORT3_TMDS_ERRC_reg_addr                                        "0xB80B202C"
#define  HDMI_P3_PORT3_TMDS_ERRC_reg                                             0xB80B202C
#define  HDMI_P3_PORT3_TMDS_ERRC_inst_addr                                       "0x000B"
#define  set_HDMI_P3_PORT3_TMDS_ERRC_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_ERRC_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_ERRC_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_ERRC_reg))
#define  HDMI_P3_PORT3_TMDS_ERRC_nl_shift                                        (0)
#define  HDMI_P3_PORT3_TMDS_ERRC_nl_mask                                         (0x00000007)
#define  HDMI_P3_PORT3_TMDS_ERRC_nl(data)                                        (0x00000007&(data))
#define  HDMI_P3_PORT3_TMDS_ERRC_get_nl(data)                                    (0x00000007&(data))

#define  HDMI_P3_PORT3_TMDS_OUT_CTRL                                             0x180B2030
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_reg_addr                                    "0xB80B2030"
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_reg                                         0xB80B2030
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_inst_addr                                   "0x000C"
#define  set_HDMI_P3_PORT3_TMDS_OUT_CTRL_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_OUT_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_OUT_CTRL_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_OUT_CTRL_reg))
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_tmds_bypass_shift                           (7)
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_dummy_6_0_shift                             (0)
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_tmds_bypass_mask                            (0x00000080)
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_dummy_6_0_mask                              (0x0000007F)
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_tmds_bypass(data)                           (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_dummy_6_0(data)                             (0x0000007F&(data))
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_get_tmds_bypass(data)                       ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_OUT_CTRL_get_dummy_6_0(data)                         (0x0000007F&(data))

#define  HDMI_P3_PORT3_TMDS_ROUT                                                 0x180B2034
#define  HDMI_P3_PORT3_TMDS_ROUT_reg_addr                                        "0xB80B2034"
#define  HDMI_P3_PORT3_TMDS_ROUT_reg                                             0xB80B2034
#define  HDMI_P3_PORT3_TMDS_ROUT_inst_addr                                       "0x000D"
#define  set_HDMI_P3_PORT3_TMDS_ROUT_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_ROUT_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_ROUT_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_ROUT_reg))
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_h_shift                               (8)
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_l_shift                               (0)
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_h_mask                                (0x0000FF00)
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_l_mask                                (0x000000FF)
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_h(data)                               (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_ROUT_tmds_rout_l(data)                               (0x000000FF&(data))
#define  HDMI_P3_PORT3_TMDS_ROUT_get_tmds_rout_h(data)                           ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_ROUT_get_tmds_rout_l(data)                           (0x000000FF&(data))

#define  HDMI_P3_PORT3_TMDS_GOUT                                                 0x180B2038
#define  HDMI_P3_PORT3_TMDS_GOUT_reg_addr                                        "0xB80B2038"
#define  HDMI_P3_PORT3_TMDS_GOUT_reg                                             0xB80B2038
#define  HDMI_P3_PORT3_TMDS_GOUT_inst_addr                                       "0x000E"
#define  set_HDMI_P3_PORT3_TMDS_GOUT_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_GOUT_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_GOUT_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_GOUT_reg))
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_h_shift                               (8)
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_l_shift                               (0)
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_h_mask                                (0x0000FF00)
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_l_mask                                (0x000000FF)
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_h(data)                               (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_GOUT_tmds_gout_l(data)                               (0x000000FF&(data))
#define  HDMI_P3_PORT3_TMDS_GOUT_get_tmds_gout_h(data)                           ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_GOUT_get_tmds_gout_l(data)                           (0x000000FF&(data))

#define  HDMI_P3_PORT3_TMDS_BOUT                                                 0x180B203C
#define  HDMI_P3_PORT3_TMDS_BOUT_reg_addr                                        "0xB80B203C"
#define  HDMI_P3_PORT3_TMDS_BOUT_reg                                             0xB80B203C
#define  HDMI_P3_PORT3_TMDS_BOUT_inst_addr                                       "0x000F"
#define  set_HDMI_P3_PORT3_TMDS_BOUT_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_BOUT_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_BOUT_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_BOUT_reg))
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_h_shift                               (8)
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_l_shift                               (0)
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_h_mask                                (0x0000FF00)
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_l_mask                                (0x000000FF)
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_h(data)                               (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_BOUT_tmds_bout_l(data)                               (0x000000FF&(data))
#define  HDMI_P3_PORT3_TMDS_BOUT_get_tmds_bout_h(data)                           ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_BOUT_get_tmds_bout_l(data)                           (0x000000FF&(data))

#define  HDMI_P3_PORT3_TMDS_DPC0                                                 0x180B2040
#define  HDMI_P3_PORT3_TMDS_DPC0_reg_addr                                        "0xB80B2040"
#define  HDMI_P3_PORT3_TMDS_DPC0_reg                                             0xB80B2040
#define  HDMI_P3_PORT3_TMDS_DPC0_inst_addr                                       "0x0010"
#define  set_HDMI_P3_PORT3_TMDS_DPC0_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC0_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC0_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC0_reg))
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp_valid_shift                              (9)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_default_ph_shift                            (8)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp_shift                                    (4)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_cd_shift                                    (0)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp_valid_mask                               (0x00000200)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_default_ph_mask                             (0x00000100)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp_mask                                     (0x000000F0)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_cd_mask                                     (0x0000000F)
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp_valid(data)                              (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_default_ph(data)                            (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_pp(data)                                    (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC0_dpc_cd(data)                                    (0x0000000F&(data))
#define  HDMI_P3_PORT3_TMDS_DPC0_get_dpc_pp_valid(data)                          ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_TMDS_DPC0_get_dpc_default_ph(data)                        ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_DPC0_get_dpc_pp(data)                                ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DPC0_get_dpc_cd(data)                                (0x0000000F&(data))

#define  HDMI_P3_PORT3_TMDS_DPC1                                                 0x180B2044
#define  HDMI_P3_PORT3_TMDS_DPC1_reg_addr                                        "0xB80B2044"
#define  HDMI_P3_PORT3_TMDS_DPC1_reg                                             0xB80B2044
#define  HDMI_P3_PORT3_TMDS_DPC1_inst_addr                                       "0x0011"
#define  set_HDMI_P3_PORT3_TMDS_DPC1_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC1_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC1_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC1_reg))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_flag_shift                           (18)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_wd_en_shift                          (17)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_int_en_shift                         (16)
#define  HDMI_P3_PORT3_TMDS_DPC1_dummy_15_11_shift                               (11)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_auto_shift                                  (10)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_valid_fw_shift                           (9)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_default_ph_fw_shift                         (8)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_fw_shift                                 (4)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_fw_shift                                 (0)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_flag_mask                            (0x00040000)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_wd_en_mask                           (0x00020000)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_int_en_mask                          (0x00010000)
#define  HDMI_P3_PORT3_TMDS_DPC1_dummy_15_11_mask                                (0x0000F800)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_auto_mask                                   (0x00000400)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_valid_fw_mask                            (0x00000200)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_default_ph_fw_mask                          (0x00000100)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_fw_mask                                  (0x000000F0)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_fw_mask                                  (0x0000000F)
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_flag(data)                           (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_wd_en(data)                          (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_chg_int_en(data)                         (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_TMDS_DPC1_dummy_15_11(data)                               (0x0000F800&((data)<<11))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_auto(data)                                  (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_valid_fw(data)                           (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_default_ph_fw(data)                         (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_pp_fw(data)                                 (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC1_dpc_cd_fw(data)                                 (0x0000000F&(data))
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_cd_chg_flag(data)                       ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_cd_chg_wd_en(data)                      ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_cd_chg_int_en(data)                     ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dummy_15_11(data)                           ((0x0000F800&(data))>>11)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_auto(data)                              ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_pp_valid_fw(data)                       ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_default_ph_fw(data)                     ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_pp_fw(data)                             ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DPC1_get_dpc_cd_fw(data)                             (0x0000000F&(data))

#define  HDMI_P3_PORT3_TMDS_DPC_SET0                                             0x180B2048
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_reg_addr                                    "0xB80B2048"
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_reg                                         0xB80B2048
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_inst_addr                                   "0x0012"
#define  set_HDMI_P3_PORT3_TMDS_DPC_SET0_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET0_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC_SET0_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET0_reg))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_bypass_dis_shift                        (8)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_en_shift                                (7)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_errcnt_in_shift                       (4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clrcnt_in_shift                       (1)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clr_sel_shift                         (0)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_bypass_dis_mask                         (0x00000100)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_en_mask                                 (0x00000080)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_errcnt_in_mask                        (0x00000070)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clrcnt_in_mask                        (0x0000000E)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clr_sel_mask                          (0x00000001)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_bypass_dis(data)                        (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_dpc_en(data)                                (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_errcnt_in(data)                       (0x00000070&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clrcnt_in(data)                       (0x0000000E&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_phase_clr_sel(data)                         (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_get_dpc_bypass_dis(data)                    ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_get_dpc_en(data)                            ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_get_phase_errcnt_in(data)                   ((0x00000070&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_get_phase_clrcnt_in(data)                   ((0x0000000E&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_DPC_SET0_get_phase_clr_sel(data)                     (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_DPC_SET1                                             0x180B204C
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_reg_addr                                    "0xB80B204C"
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_reg                                         0xB80B204C
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_inst_addr                                   "0x0013"
#define  set_HDMI_P3_PORT3_TMDS_DPC_SET1_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET1_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC_SET1_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET1_reg))
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_full_noti_shift                         (4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_empty_noti_shift                        (0)
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_full_noti_mask                          (0x000000F0)
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_empty_noti_mask                         (0x0000000F)
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_full_noti(data)                         (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_set_empty_noti(data)                        (0x0000000F&(data))
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_get_set_full_noti(data)                     ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET1_get_set_empty_noti(data)                    (0x0000000F&(data))

#define  HDMI_P3_PORT3_TMDS_DPC_SET2                                             0x180B2050
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_reg_addr                                    "0xB80B2050"
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_reg                                         0xB80B2050
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_inst_addr                                   "0x0014"
#define  set_HDMI_P3_PORT3_TMDS_DPC_SET2_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET2_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC_SET2_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET2_reg))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_fifo_errcnt_in_shift                        (5)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_phase_flag_shift                        (4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_fifo_flag_shift                         (3)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_ok_shift                          (2)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_err_flag_shift                    (1)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_fifo_err_flag_shift                     (0)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_fifo_errcnt_in_mask                         (0x000000E0)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_phase_flag_mask                         (0x00000010)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_fifo_flag_mask                          (0x00000008)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_ok_mask                           (0x00000004)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_err_flag_mask                     (0x00000002)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_fifo_err_flag_mask                      (0x00000001)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_fifo_errcnt_in(data)                        (0x000000E0&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_phase_flag(data)                        (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_clr_fifo_flag(data)                         (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_ok(data)                          (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_phase_err_flag(data)                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_dpc_fifo_err_flag(data)                     (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_fifo_errcnt_in(data)                    ((0x000000E0&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_clr_phase_flag(data)                    ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_clr_fifo_flag(data)                     ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_dpc_phase_ok(data)                      ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_dpc_phase_err_flag(data)                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_DPC_SET2_get_dpc_fifo_err_flag(data)                 (0x00000001&(data))

#define  HDMI_P3_PORT3_TMDS_DPC_SET3                                             0x180B2054
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_reg_addr                                    "0xB80B2054"
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_reg                                         0xB80B2054
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_inst_addr                                   "0x0015"
#define  set_HDMI_P3_PORT3_TMDS_DPC_SET3_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET3_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DPC_SET3_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DPC_SET3_reg))
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_flag_shift                    (7)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_flag_shift                   (6)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_xflag_shift                   (5)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_xflag_shift                  (4)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_flag_mask                     (0x00000080)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_flag_mask                    (0x00000040)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_xflag_mask                    (0x00000020)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_xflag_mask                   (0x00000010)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_flag(data)                    (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_flag(data)                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_over_xflag(data)                   (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_dpc_fifo_under_xflag(data)                  (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_get_dpc_fifo_over_flag(data)                ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_get_dpc_fifo_under_flag(data)               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_get_dpc_fifo_over_xflag(data)               ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_DPC_SET3_get_dpc_fifo_under_xflag(data)              ((0x00000010&(data))>>4)

#define  HDMI_P3_PORT3_TMDS_DET_CTL                                              0x180B2058
#define  HDMI_P3_PORT3_TMDS_DET_CTL_reg_addr                                     "0xB80B2058"
#define  HDMI_P3_PORT3_TMDS_DET_CTL_reg                                          0xB80B2058
#define  HDMI_P3_PORT3_TMDS_DET_CTL_inst_addr                                    "0x0016"
#define  set_HDMI_P3_PORT3_TMDS_DET_CTL_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DET_CTL_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DET_CTL_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DET_CTL_reg))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_de_sel_shift                                 (28)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_tran_err_thrd_shift                          (24)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_err_thrd_shift                        (20)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_err_thrd_shift                        (16)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_15_shift                               (15)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_lowbd_shift                           (8)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_7_6_shift                              (6)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_lowbd_shift                           (0)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_de_sel_mask                                  (0x10000000)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_tran_err_thrd_mask                           (0x0F000000)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_err_thrd_mask                         (0x00F00000)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_err_thrd_mask                         (0x000F0000)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_15_mask                                (0x00008000)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_lowbd_mask                            (0x00007F00)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_7_6_mask                               (0x000000C0)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_lowbd_mask                            (0x0000003F)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_de_sel(data)                                 (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_tran_err_thrd(data)                          (0x0F000000&((data)<<24))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_err_thrd(data)                        (0x00F00000&((data)<<20))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_err_thrd(data)                        (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_15(data)                               (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_neg_de_lowbd(data)                           (0x00007F00&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_dummy_7_6(data)                              (0x000000C0&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_pos_de_lowbd(data)                           (0x0000003F&(data))
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_de_sel(data)                             ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_tran_err_thrd(data)                      ((0x0F000000&(data))>>24)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_neg_de_err_thrd(data)                    ((0x00F00000&(data))>>20)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_pos_de_err_thrd(data)                    ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_dummy_15(data)                           ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_neg_de_lowbd(data)                       ((0x00007F00&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_dummy_7_6(data)                          ((0x000000C0&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_DET_CTL_get_pos_de_lowbd(data)                       (0x0000003F&(data))

#define  HDMI_P3_PORT3_TMDS_DET_STS                                              0x180B205C
#define  HDMI_P3_PORT3_TMDS_DET_STS_reg_addr                                     "0xB80B205C"
#define  HDMI_P3_PORT3_TMDS_DET_STS_reg                                          0xB80B205C
#define  HDMI_P3_PORT3_TMDS_DET_STS_inst_addr                                    "0x0017"
#define  set_HDMI_P3_PORT3_TMDS_DET_STS_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DET_STS_reg)=data)
#define  get_HDMI_P3_PORT3_TMDS_DET_STS_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_TMDS_DET_STS_reg))
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_tran_err_flag_shift                      (8)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_tran_err_flag_shift                      (7)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_tran_err_flag_shift                      (6)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_pos_de_err_flag_shift                    (5)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_pos_de_err_flag_shift                    (4)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_pos_de_err_flag_shift                    (3)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_neg_de_err_flag_shift                    (2)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_neg_de_err_flag_shift                    (1)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_neg_de_err_flag_shift                    (0)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_tran_err_flag_mask                       (0x00000100)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_tran_err_flag_mask                       (0x00000080)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_tran_err_flag_mask                       (0x00000040)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_pos_de_err_flag_mask                     (0x00000020)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_pos_de_err_flag_mask                     (0x00000010)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_pos_de_err_flag_mask                     (0x00000008)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_neg_de_err_flag_mask                     (0x00000004)
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_neg_de_err_flag_mask                     (0x00000002)
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_neg_de_err_flag_mask                     (0x00000001)
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_tran_err_flag(data)                      (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_tran_err_flag(data)                      (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_tran_err_flag(data)                      (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_pos_de_err_flag(data)                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_pos_de_err_flag(data)                    (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_pos_de_err_flag(data)                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_TMDS_DET_STS_red_neg_de_err_flag(data)                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_TMDS_DET_STS_grn_neg_de_err_flag(data)                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_TMDS_DET_STS_blu_neg_de_err_flag(data)                    (0x00000001&(data))
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_red_tran_err_flag(data)                  ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_grn_tran_err_flag(data)                  ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_blu_tran_err_flag(data)                  ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_red_pos_de_err_flag(data)                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_grn_pos_de_err_flag(data)                ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_blu_pos_de_err_flag(data)                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_red_neg_de_err_flag(data)                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_grn_neg_de_err_flag(data)                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_TMDS_DET_STS_get_blu_neg_de_err_flag(data)                (0x00000001&(data))

#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET                                         0x180B2060
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg_addr                                "0xB80B2060"
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg                                     0xB80B2060
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_inst_addr                               "0x0018"
#define  set_HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg(data)                           (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg)=data)
#define  get_HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg                                 (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reg))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_thd_shift                               (16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_disparity_reset_mode_shift              (12)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_irq_en_shift                            (11)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reset_shift                             (10)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_period_shift                            (4)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_ch_sel_shift                            (2)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_mode_shift                              (1)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_en_shift                                (0)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_thd_mask                                (0xFFFF0000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_disparity_reset_mode_mask               (0x00001000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_irq_en_mask                             (0x00000800)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reset_mask                              (0x00000400)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_period_mask                             (0x000003F0)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_ch_sel_mask                             (0x0000000C)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_mode_mask                               (0x00000002)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_en_mask                                 (0x00000001)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_thd(data)                               (0xFFFF0000&((data)<<16))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_disparity_reset_mode(data)              (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_irq_en(data)                            (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_reset(data)                             (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_period(data)                            (0x000003F0&((data)<<4))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_ch_sel(data)                            (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_mode(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_en(data)                                (0x00000001&(data))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_thd(data)                           ((0xFFFF0000&(data))>>16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_disparity_reset_mode(data)          ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_irq_en(data)                        ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_reset(data)                         ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_period(data)                        ((0x000003F0&(data))>>4)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_ch_sel(data)                        ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_mode(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_DET_get_en(data)                            (0x00000001&(data))

#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B                                    0x180B2064
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg_addr                           "0xB80B2064"
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg                                0xB80B2064
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_inst_addr                          "0x0019"
#define  set_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg(data)                      (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg)=data)
#define  get_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg                            (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_reg))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_max_b_shift                     (26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_min_b_shift                     (20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_shift               (19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_shift                (18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_b_shift                    (17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_shift             (16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_b_shift                (0)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_max_b_mask                      (0xFC000000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_min_b_mask                      (0x03F00000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask                (0x00080000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask                 (0x00040000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask                     (0x00020000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask              (0x00010000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_b_mask                 (0x0000FFFF)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_max_b(data)                     (0xFC000000&((data)<<26))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_ad_min_b(data)                     (0x03F00000&((data)<<20))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b(data)               (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b(data)                (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_b(data)                    (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b(data)             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_b(data)                (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_ad_max_b(data)                 ((0xFC000000&(data))>>26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_ad_min_b(data)                 ((0x03F00000&(data))>>20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_no_dis_reset_b(data)           ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_bit_err_thd_b(data)            ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_bit_err_b(data)                ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_bit_err_cnt_of_b(data)         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_B_get_bit_err_cnt_b(data)            (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G                                    0x180B2068
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg_addr                           "0xB80B2068"
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg                                0xB80B2068
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_inst_addr                          "0x001A"
#define  set_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg(data)                      (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg)=data)
#define  get_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg                            (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_reg))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_max_g_shift                     (26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_min_g_shift                     (20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_no_dis_reset_g_shift               (19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_thd_g_shift                (18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_g_shift                    (17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_of_g_shift             (16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_g_shift                (0)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_max_g_mask                      (0xFC000000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_min_g_mask                      (0x03F00000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_no_dis_reset_g_mask                (0x00080000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_thd_g_mask                 (0x00040000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_g_mask                     (0x00020000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_of_g_mask              (0x00010000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_g_mask                 (0x0000FFFF)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_max_g(data)                     (0xFC000000&((data)<<26))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_ad_min_g(data)                     (0x03F00000&((data)<<20))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_no_dis_reset_g(data)               (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_thd_g(data)                (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_g(data)                    (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_of_g(data)             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_bit_err_cnt_g(data)                (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_ad_max_g(data)                 ((0xFC000000&(data))>>26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_ad_min_g(data)                 ((0x03F00000&(data))>>20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_no_dis_reset_g(data)           ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_bit_err_thd_g(data)            ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_bit_err_g(data)                ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_bit_err_cnt_of_g(data)         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_G_get_bit_err_cnt_g(data)            (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R                                    0x180B206C
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg_addr                           "0xB80B206C"
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg                                0xB80B206C
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_inst_addr                          "0x001B"
#define  set_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg(data)                      (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg)=data)
#define  get_HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg                            (*((volatile unsigned int*)HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_reg))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_max_r_shift                     (26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_min_r_shift                     (20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_no_dis_reset_r_shift               (19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_thd_r_shift                (18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_r_shift                    (17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_of_r_shift             (16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_r_shift                (0)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_max_r_mask                      (0xFC000000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_min_r_mask                      (0x03F00000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_no_dis_reset_r_mask                (0x00080000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_thd_r_mask                 (0x00040000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_r_mask                     (0x00020000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_of_r_mask              (0x00010000)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_r_mask                 (0x0000FFFF)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_max_r(data)                     (0xFC000000&((data)<<26))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_ad_min_r(data)                     (0x03F00000&((data)<<20))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_no_dis_reset_r(data)               (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_thd_r(data)                (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_r(data)                    (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_of_r(data)             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_bit_err_cnt_r(data)                (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_ad_max_r(data)                 ((0xFC000000&(data))>>26)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_ad_min_r(data)                 ((0x03F00000&(data))>>20)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_no_dis_reset_r(data)           ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_bit_err_thd_r(data)            ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_bit_err_r(data)                ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_bit_err_cnt_of_r(data)         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_VIDEO_BIT_ERR_STATUS_R_get_bit_err_cnt_r(data)            (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_TERC4_ERR_DET                                             0x180B2070
#define  HDMI_P3_PORT3_TERC4_ERR_DET_reg_addr                                    "0xB80B2070"
#define  HDMI_P3_PORT3_TERC4_ERR_DET_reg                                         0xB80B2070
#define  HDMI_P3_PORT3_TERC4_ERR_DET_inst_addr                                   "0x001C"
#define  set_HDMI_P3_PORT3_TERC4_ERR_DET_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_DET_reg)=data)
#define  get_HDMI_P3_PORT3_TERC4_ERR_DET_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_DET_reg))
#define  HDMI_P3_PORT3_TERC4_ERR_DET_terc4_thd_shift                             (0)
#define  HDMI_P3_PORT3_TERC4_ERR_DET_terc4_thd_mask                              (0x0000FFFF)
#define  HDMI_P3_PORT3_TERC4_ERR_DET_terc4_thd(data)                             (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_TERC4_ERR_DET_get_terc4_thd(data)                         (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B                                        0x180B2074
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg_addr                               "0xB80B2074"
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg                                    0xB80B2074
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_inst_addr                              "0x001D"
#define  set_HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg)=data)
#define  get_HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_B_reg))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_thd_b_shift                  (18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_b_shift                      (17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_of_b_shift               (16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_b_shift                  (0)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_thd_b_mask                   (0x00040000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_b_mask                       (0x00020000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_of_b_mask                (0x00010000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_b_mask                   (0x0000FFFF)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_thd_b(data)                  (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_b(data)                      (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_of_b(data)               (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_terc4_err_cnt_b(data)                  (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_get_terc4_err_thd_b(data)              ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_get_terc4_err_b(data)                  ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_get_terc4_err_cnt_of_b(data)           ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_B_get_terc4_err_cnt_b(data)              (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G                                        0x180B2078
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg_addr                               "0xB80B2078"
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg                                    0xB80B2078
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_inst_addr                              "0x001E"
#define  set_HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg)=data)
#define  get_HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_G_reg))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_thd_g_shift                  (18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_g_shift                      (17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_of_g_shift               (16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_g_shift                  (0)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_thd_g_mask                   (0x00040000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_g_mask                       (0x00020000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_of_g_mask                (0x00010000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_g_mask                   (0x0000FFFF)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_thd_g(data)                  (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_g(data)                      (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_of_g(data)               (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_terc4_err_cnt_g(data)                  (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_get_terc4_err_thd_g(data)              ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_get_terc4_err_g(data)                  ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_get_terc4_err_cnt_of_g(data)           ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_G_get_terc4_err_cnt_g(data)              (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R                                        0x180B207C
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg_addr                               "0xB80B207C"
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg                                    0xB80B207C
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_inst_addr                              "0x001F"
#define  set_HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg)=data)
#define  get_HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_TERC4_ERR_STATUS_R_reg))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_thd_r_shift                  (18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_r_shift                      (17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_of_r_shift               (16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_r_shift                  (0)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_thd_r_mask                   (0x00040000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_r_mask                       (0x00020000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_of_r_mask                (0x00010000)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_r_mask                   (0x0000FFFF)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_thd_r(data)                  (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_r(data)                      (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_of_r(data)               (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_terc4_err_cnt_r(data)                  (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_get_terc4_err_thd_r(data)              ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_get_terc4_err_r(data)                  ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_get_terc4_err_cnt_of_r(data)           ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_TERC4_ERR_STATUS_R_get_terc4_err_cnt_r(data)              (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_HDMI_SR                                                   0x180B2080
#define  HDMI_P3_PORT3_HDMI_SR_reg_addr                                          "0xB80B2080"
#define  HDMI_P3_PORT3_HDMI_SR_reg                                               0xB80B2080
#define  HDMI_P3_PORT3_HDMI_SR_inst_addr                                         "0x0020"
#define  set_HDMI_P3_PORT3_HDMI_SR_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_SR_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SR_reg))
#define  HDMI_P3_PORT3_HDMI_SR_avmute_bg_shift                                   (7)
#define  HDMI_P3_PORT3_HDMI_SR_avmute_shift                                      (6)
#define  HDMI_P3_PORT3_HDMI_SR_vic_shift                                         (5)
#define  HDMI_P3_PORT3_HDMI_SR_spdiftype_shift                                   (4)
#define  HDMI_P3_PORT3_HDMI_SR_pllsts_shift                                      (3)
#define  HDMI_P3_PORT3_HDMI_SR_afifoof_shift                                     (2)
#define  HDMI_P3_PORT3_HDMI_SR_afifouf_shift                                     (1)
#define  HDMI_P3_PORT3_HDMI_SR_mode_shift                                        (0)
#define  HDMI_P3_PORT3_HDMI_SR_avmute_bg_mask                                    (0x00000080)
#define  HDMI_P3_PORT3_HDMI_SR_avmute_mask                                       (0x00000040)
#define  HDMI_P3_PORT3_HDMI_SR_vic_mask                                          (0x00000020)
#define  HDMI_P3_PORT3_HDMI_SR_spdiftype_mask                                    (0x00000010)
#define  HDMI_P3_PORT3_HDMI_SR_pllsts_mask                                       (0x00000008)
#define  HDMI_P3_PORT3_HDMI_SR_afifoof_mask                                      (0x00000004)
#define  HDMI_P3_PORT3_HDMI_SR_afifouf_mask                                      (0x00000002)
#define  HDMI_P3_PORT3_HDMI_SR_mode_mask                                         (0x00000001)
#define  HDMI_P3_PORT3_HDMI_SR_avmute_bg(data)                                   (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_SR_avmute(data)                                      (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_SR_vic(data)                                         (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_SR_spdiftype(data)                                   (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_SR_pllsts(data)                                      (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_SR_afifoof(data)                                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_SR_afifouf(data)                                     (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_SR_mode(data)                                        (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_SR_get_avmute_bg(data)                               ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_SR_get_avmute(data)                                  ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_SR_get_vic(data)                                     ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_SR_get_spdiftype(data)                               ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_SR_get_pllsts(data)                                  ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_SR_get_afifoof(data)                                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_SR_get_afifouf(data)                                 ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_SR_get_mode(data)                                    (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_GPVS                                                 0x180B2084
#define  HDMI_P3_PORT3_HDMI_GPVS_reg_addr                                        "0xB80B2084"
#define  HDMI_P3_PORT3_HDMI_GPVS_reg                                             0xB80B2084
#define  HDMI_P3_PORT3_HDMI_GPVS_inst_addr                                       "0x0021"
#define  set_HDMI_P3_PORT3_HDMI_GPVS_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_GPVS_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_GPVS_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_GPVS_reg))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_31_shift                                  (31)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_30_shift                                  (30)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_29_shift                                  (29)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_28_shift                                  (28)
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps_v_shift                                   (27)
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps_v_shift                                  (26)
#define  HDMI_P3_PORT3_HDMI_GPVS_aps_v_shift                                     (25)
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps_v_shift                                   (24)
#define  HDMI_P3_PORT3_HDMI_GPVS_avips_v_shift                                   (23)
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps_v_shift                                    (22)
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps_v_shift                                    (21)
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps_v_shift                                 (20)
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps_v_shift                                   (19)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_18_shift                                  (18)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_17_shift                                  (17)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_16_shift                                  (16)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_15_shift                                  (15)
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps_shift                                     (14)
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps_shift                                    (13)
#define  HDMI_P3_PORT3_HDMI_GPVS_aps_shift                                       (12)
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps_shift                                     (11)
#define  HDMI_P3_PORT3_HDMI_GPVS_avips_shift                                     (10)
#define  HDMI_P3_PORT3_HDMI_GPVS_fvsps_shift                                     (9)
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps_shift                                      (8)
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps_shift                                      (7)
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps_shift                                   (6)
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps_shift                                     (5)
#define  HDMI_P3_PORT3_HDMI_GPVS_nps_shift                                       (4)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv3ps_shift                                    (3)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv2ps_shift                                    (2)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv1ps_shift                                    (1)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv0ps_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_31_mask                                   (0x80000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_30_mask                                   (0x40000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_29_mask                                   (0x20000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_28_mask                                   (0x10000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps_v_mask                                    (0x08000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps_v_mask                                   (0x04000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_aps_v_mask                                      (0x02000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps_v_mask                                    (0x01000000)
#define  HDMI_P3_PORT3_HDMI_GPVS_avips_v_mask                                    (0x00800000)
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps_v_mask                                     (0x00400000)
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps_v_mask                                     (0x00200000)
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps_v_mask                                  (0x00100000)
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps_v_mask                                    (0x00080000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_18_mask                                   (0x00040000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_17_mask                                   (0x00020000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_16_mask                                   (0x00010000)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_15_mask                                   (0x00008000)
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps_mask                                      (0x00004000)
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps_mask                                     (0x00002000)
#define  HDMI_P3_PORT3_HDMI_GPVS_aps_mask                                        (0x00001000)
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps_mask                                      (0x00000800)
#define  HDMI_P3_PORT3_HDMI_GPVS_avips_mask                                      (0x00000400)
#define  HDMI_P3_PORT3_HDMI_GPVS_fvsps_mask                                      (0x00000200)
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps_mask                                       (0x00000100)
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps_mask                                       (0x00000080)
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps_mask                                    (0x00000040)
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps_mask                                      (0x00000020)
#define  HDMI_P3_PORT3_HDMI_GPVS_nps_mask                                        (0x00000010)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv3ps_mask                                     (0x00000008)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv2ps_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv1ps_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv0ps_mask                                     (0x00000001)
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_31(data)                                  (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_30(data)                                  (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_29(data)                                  (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_28(data)                                  (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps_v(data)                                   (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps_v(data)                                  (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_HDMI_GPVS_aps_v(data)                                     (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps_v(data)                                   (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_GPVS_avips_v(data)                                   (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps_v(data)                                    (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps_v(data)                                    (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps_v(data)                                 (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps_v(data)                                   (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_18(data)                                  (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_17(data)                                  (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_16(data)                                  (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_GPVS_dummy_15(data)                                  (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_HDMI_GPVS_drmps(data)                                     (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_GPVS_mpegps(data)                                    (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_GPVS_aps(data)                                       (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_GPVS_spdps(data)                                     (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_HDMI_GPVS_avips(data)                                     (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDMI_GPVS_fvsps(data)                                     (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_GPVS_vsps(data)                                      (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_GPVS_gmps(data)                                      (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_GPVS_isrc1ps(data)                                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_GPVS_acpps(data)                                     (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_GPVS_nps(data)                                       (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv3ps(data)                                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv2ps(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv1ps(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_GPVS_rsv0ps(data)                                    (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_31(data)                              ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_30(data)                              ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_29(data)                              ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_28(data)                              ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_drmps_v(data)                               ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_mpegps_v(data)                              ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_aps_v(data)                                 ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_spdps_v(data)                               ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_avips_v(data)                               ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_vsps_v(data)                                ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_gmps_v(data)                                ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_isrc1ps_v(data)                             ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_acpps_v(data)                               ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_18(data)                              ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_17(data)                              ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_16(data)                              ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_dummy_15(data)                              ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_drmps(data)                                 ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_mpegps(data)                                ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_aps(data)                                   ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_spdps(data)                                 ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_avips(data)                                 ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_fvsps(data)                                 ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_vsps(data)                                  ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_gmps(data)                                  ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_isrc1ps(data)                               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_acpps(data)                                 ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_nps(data)                                   ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_rsv3ps(data)                                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_rsv2ps(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_rsv1ps(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_GPVS_get_rsv0ps(data)                                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_PSAP                                                 0x180B2088
#define  HDMI_P3_PORT3_HDMI_PSAP_reg_addr                                        "0xB80B2088"
#define  HDMI_P3_PORT3_HDMI_PSAP_reg                                             0xB80B2088
#define  HDMI_P3_PORT3_HDMI_PSAP_inst_addr                                       "0x0022"
#define  set_HDMI_P3_PORT3_HDMI_PSAP_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSAP_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PSAP_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSAP_reg))
#define  HDMI_P3_PORT3_HDMI_PSAP_apss_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_PSAP_apss_mask                                       (0x000001FF)
#define  HDMI_P3_PORT3_HDMI_PSAP_apss(data)                                      (0x000001FF&(data))
#define  HDMI_P3_PORT3_HDMI_PSAP_get_apss(data)                                  (0x000001FF&(data))

#define  HDMI_P3_PORT3_HDMI_PSDP                                                 0x180B208C
#define  HDMI_P3_PORT3_HDMI_PSDP_reg_addr                                        "0xB80B208C"
#define  HDMI_P3_PORT3_HDMI_PSDP_reg                                             0xB80B208C
#define  HDMI_P3_PORT3_HDMI_PSDP_inst_addr                                       "0x0023"
#define  set_HDMI_P3_PORT3_HDMI_PSDP_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSDP_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PSDP_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSDP_reg))
#define  HDMI_P3_PORT3_HDMI_PSDP_dpss_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_PSDP_dpss_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PSDP_dpss(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PSDP_get_dpss(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_SCR                                                  0x180B2090
#define  HDMI_P3_PORT3_HDMI_SCR_reg_addr                                         "0xB80B2090"
#define  HDMI_P3_PORT3_HDMI_SCR_reg                                              0xB80B2090
#define  HDMI_P3_PORT3_HDMI_SCR_inst_addr                                        "0x0024"
#define  set_HDMI_P3_PORT3_HDMI_SCR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_SCR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SCR_reg))
#define  HDMI_P3_PORT3_HDMI_SCR_nval_shift                                       (8)
#define  HDMI_P3_PORT3_HDMI_SCR_no_vs_det_en_shift                               (6)
#define  HDMI_P3_PORT3_HDMI_SCR_dvi_reset_ds_cm_en_shift                         (5)
#define  HDMI_P3_PORT3_HDMI_SCR_packet_ignore_shift                              (4)
#define  HDMI_P3_PORT3_HDMI_SCR_mode_shift                                       (3)
#define  HDMI_P3_PORT3_HDMI_SCR_msmode_shift                                     (2)
#define  HDMI_P3_PORT3_HDMI_SCR_cabs_shift                                       (1)
#define  HDMI_P3_PORT3_HDMI_SCR_fcddip_shift                                     (0)
#define  HDMI_P3_PORT3_HDMI_SCR_nval_mask                                        (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_SCR_no_vs_det_en_mask                                (0x00000040)
#define  HDMI_P3_PORT3_HDMI_SCR_dvi_reset_ds_cm_en_mask                          (0x00000020)
#define  HDMI_P3_PORT3_HDMI_SCR_packet_ignore_mask                               (0x00000010)
#define  HDMI_P3_PORT3_HDMI_SCR_mode_mask                                        (0x00000008)
#define  HDMI_P3_PORT3_HDMI_SCR_msmode_mask                                      (0x00000004)
#define  HDMI_P3_PORT3_HDMI_SCR_cabs_mask                                        (0x00000002)
#define  HDMI_P3_PORT3_HDMI_SCR_fcddip_mask                                      (0x00000001)
#define  HDMI_P3_PORT3_HDMI_SCR_nval(data)                                       (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_SCR_no_vs_det_en(data)                               (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_SCR_dvi_reset_ds_cm_en(data)                         (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_SCR_packet_ignore(data)                              (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_SCR_mode(data)                                       (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_SCR_msmode(data)                                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_SCR_cabs(data)                                       (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_SCR_fcddip(data)                                     (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_SCR_get_nval(data)                                   ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_SCR_get_no_vs_det_en(data)                           ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_SCR_get_dvi_reset_ds_cm_en(data)                     ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_SCR_get_packet_ignore(data)                          ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_SCR_get_mode(data)                                   ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_SCR_get_msmode(data)                                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_SCR_get_cabs(data)                                   ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_SCR_get_fcddip(data)                                 (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_BCHCR                                                0x180B2094
#define  HDMI_P3_PORT3_HDMI_BCHCR_reg_addr                                       "0xB80B2094"
#define  HDMI_P3_PORT3_HDMI_BCHCR_reg                                            0xB80B2094
#define  HDMI_P3_PORT3_HDMI_BCHCR_inst_addr                                      "0x0025"
#define  set_HDMI_P3_PORT3_HDMI_BCHCR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_BCHCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_BCHCR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_BCHCR_reg))
#define  HDMI_P3_PORT3_HDMI_BCHCR_spcss_shift                                    (5)
#define  HDMI_P3_PORT3_HDMI_BCHCR_enrwe_shift                                    (4)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bche_shift                                     (3)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches_shift                                    (2)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches2_shift                                   (1)
#define  HDMI_P3_PORT3_HDMI_BCHCR_pe_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_BCHCR_spcss_mask                                     (0x00000020)
#define  HDMI_P3_PORT3_HDMI_BCHCR_enrwe_mask                                     (0x00000010)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bche_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches2_mask                                    (0x00000002)
#define  HDMI_P3_PORT3_HDMI_BCHCR_pe_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_HDMI_BCHCR_spcss(data)                                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_BCHCR_enrwe(data)                                    (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_BCHCR_bche(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_BCHCR_bches2(data)                                   (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_BCHCR_pe(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_spcss(data)                                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_enrwe(data)                                ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_bche(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_bches(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_bches2(data)                               ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_BCHCR_get_pe(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_AVMCR                                                0x180B2098
#define  HDMI_P3_PORT3_HDMI_AVMCR_reg_addr                                       "0xB80B2098"
#define  HDMI_P3_PORT3_HDMI_AVMCR_reg                                            0xB80B2098
#define  HDMI_P3_PORT3_HDMI_AVMCR_inst_addr                                      "0x0026"
#define  set_HDMI_P3_PORT3_HDMI_AVMCR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AVMCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AVMCR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AVMCR_reg))
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_ptg_en_shift                                (10)
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_vclk_en_shift                               (9)
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_flag_shift                              (8)
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_win_en_shift                            (7)
#define  HDMI_P3_PORT3_HDMI_AVMCR_aoc_shift                                      (6)
#define  HDMI_P3_PORT3_HDMI_AVMCR_aomc_shift                                     (5)
#define  HDMI_P3_PORT3_HDMI_AVMCR_awd_shift                                      (4)
#define  HDMI_P3_PORT3_HDMI_AVMCR_ve_shift                                       (3)
#define  HDMI_P3_PORT3_HDMI_AVMCR_ampic_shift                                    (2)
#define  HDMI_P3_PORT3_HDMI_AVMCR_vdpic_shift                                    (1)
#define  HDMI_P3_PORT3_HDMI_AVMCR_nfpss_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_ptg_en_mask                                 (0x00000400)
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_vclk_en_mask                                (0x00000200)
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_flag_mask                               (0x00000100)
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_win_en_mask                             (0x00000080)
#define  HDMI_P3_PORT3_HDMI_AVMCR_aoc_mask                                       (0x00000040)
#define  HDMI_P3_PORT3_HDMI_AVMCR_aomc_mask                                      (0x00000020)
#define  HDMI_P3_PORT3_HDMI_AVMCR_awd_mask                                       (0x00000010)
#define  HDMI_P3_PORT3_HDMI_AVMCR_ve_mask                                        (0x00000008)
#define  HDMI_P3_PORT3_HDMI_AVMCR_ampic_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_HDMI_AVMCR_vdpic_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_HDMI_AVMCR_nfpss_mask                                     (0x00000001)
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_ptg_en(data)                                (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDMI_AVMCR_wd_vclk_en(data)                               (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_flag(data)                              (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_AVMCR_avmute_win_en(data)                            (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_AVMCR_aoc(data)                                      (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_AVMCR_aomc(data)                                     (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_AVMCR_awd(data)                                      (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_AVMCR_ve(data)                                       (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_AVMCR_ampic(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_AVMCR_vdpic(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_AVMCR_nfpss(data)                                    (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_wd_ptg_en(data)                            ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_wd_vclk_en(data)                           ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_avmute_flag(data)                          ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_avmute_win_en(data)                        ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_aoc(data)                                  ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_aomc(data)                                 ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_awd(data)                                  ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_ve(data)                                   ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_ampic(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_vdpic(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_AVMCR_get_nfpss(data)                                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_WDCR0                                                0x180B209C
#define  HDMI_P3_PORT3_HDMI_WDCR0_reg_addr                                       "0xB80B209C"
#define  HDMI_P3_PORT3_HDMI_WDCR0_reg                                            0xB80B209C
#define  HDMI_P3_PORT3_HDMI_WDCR0_inst_addr                                      "0x0027"
#define  set_HDMI_P3_PORT3_HDMI_WDCR0_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_WDCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_WDCR0_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_WDCR0_reg))
#define  HDMI_P3_PORT3_HDMI_WDCR0_wdm_shift                                      (27)
#define  HDMI_P3_PORT3_HDMI_WDCR0_wds_shift                                      (26)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdch_shift                                    (25)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdch_shift                                    (24)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdap_shift                                    (23)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdlf_shift                                    (22)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafo_shift                                   (21)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafu_shift                                   (20)
#define  HDMI_P3_PORT3_HDMI_WDCR0_yv_shift                                       (16)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdck_shift                                    (15)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdlf_shift                                    (14)
#define  HDMI_P3_PORT3_HDMI_WDCR0_ch_st_sel_shift                                (13)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdact_shift                                   (12)
#define  HDMI_P3_PORT3_HDMI_WDCR0_xv_shift                                       (8)
#define  HDMI_P3_PORT3_HDMI_WDCR0_asmfe_shift                                    (7)
#define  HDMI_P3_PORT3_HDMI_WDCR0_load_d_shift                                   (6)
#define  HDMI_P3_PORT3_HDMI_WDCR0_bt_track_en_shift                              (5)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdct_shift                                    (4)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdap_shift                                    (3)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfo_shift                                    (2)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfu_shift                                    (1)
#define  HDMI_P3_PORT3_HDMI_WDCR0_ct_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_WDCR0_wdm_mask                                       (0x08000000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_wds_mask                                       (0x04000000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdch_mask                                     (0x02000000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdch_mask                                     (0x01000000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdap_mask                                     (0x00800000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdlf_mask                                     (0x00400000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafo_mask                                    (0x00200000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafu_mask                                    (0x00100000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_yv_mask                                        (0x000F0000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdck_mask                                     (0x00008000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdlf_mask                                     (0x00004000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_ch_st_sel_mask                                 (0x00002000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdact_mask                                    (0x00001000)
#define  HDMI_P3_PORT3_HDMI_WDCR0_xv_mask                                        (0x00000F00)
#define  HDMI_P3_PORT3_HDMI_WDCR0_asmfe_mask                                     (0x00000080)
#define  HDMI_P3_PORT3_HDMI_WDCR0_load_d_mask                                    (0x00000040)
#define  HDMI_P3_PORT3_HDMI_WDCR0_bt_track_en_mask                               (0x00000020)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdct_mask                                     (0x00000010)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdap_mask                                     (0x00000008)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfo_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfu_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_HDMI_WDCR0_ct_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_HDMI_WDCR0_wdm(data)                                      (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_HDMI_WDCR0_wds(data)                                      (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdch(data)                                    (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdch(data)                                    (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdap(data)                                    (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdlf(data)                                    (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafo(data)                                   (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdafu(data)                                   (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_HDMI_WDCR0_yv(data)                                       (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdck(data)                                    (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdlf(data)                                    (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_WDCR0_ch_st_sel(data)                                (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_WDCR0_vwdact(data)                                   (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_WDCR0_xv(data)                                       (0x00000F00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_WDCR0_asmfe(data)                                    (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_WDCR0_load_d(data)                                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_WDCR0_bt_track_en(data)                              (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdct(data)                                    (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdap(data)                                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfo(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_WDCR0_awdfu(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_WDCR0_ct(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_wdm(data)                                  ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_wds(data)                                  ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdch(data)                                ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdch(data)                                ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdap(data)                                ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdlf(data)                                ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdafo(data)                               ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdafu(data)                               ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_yv(data)                                   ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdck(data)                                ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdlf(data)                                ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_ch_st_sel(data)                            ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_vwdact(data)                               ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_xv(data)                                   ((0x00000F00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_asmfe(data)                                ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_load_d(data)                               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_bt_track_en(data)                          ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdct(data)                                ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdap(data)                                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdfo(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_awdfu(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_WDCR0_get_ct(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_DBCR                                                 0x180B20A0
#define  HDMI_P3_PORT3_HDMI_DBCR_reg_addr                                        "0xB80B20A0"
#define  HDMI_P3_PORT3_HDMI_DBCR_reg                                             0xB80B20A0
#define  HDMI_P3_PORT3_HDMI_DBCR_inst_addr                                       "0x0028"
#define  set_HDMI_P3_PORT3_HDMI_DBCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DBCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_DBCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DBCR_reg))
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfv_shift                                    (3)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfo_shift                                    (2)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfu_shift                                    (1)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbpn_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfv_mask                                     (0x00000008)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfo_mask                                     (0x00000004)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfu_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbpn_mask                                     (0x00000001)
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfv(data)                                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfo(data)                                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbfu(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_DBCR_aldbpn(data)                                    (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_DBCR_get_aldbfv(data)                                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_DBCR_get_aldbfo(data)                                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_DBCR_get_aldbfu(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_DBCR_get_aldbpn(data)                                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_AWDSR                                                0x180B20A4
#define  HDMI_P3_PORT3_HDMI_AWDSR_reg_addr                                       "0xB80B20A4"
#define  HDMI_P3_PORT3_HDMI_AWDSR_reg                                            0xB80B20A4
#define  HDMI_P3_PORT3_HDMI_AWDSR_inst_addr                                      "0x0029"
#define  set_HDMI_P3_PORT3_HDMI_AWDSR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AWDSR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AWDSR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AWDSR_reg))
#define  HDMI_P3_PORT3_HDMI_AWDSR_awdpvsb_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_AWDSR_awdpvsb_mask                                   (0x0000007F)
#define  HDMI_P3_PORT3_HDMI_AWDSR_awdpvsb(data)                                  (0x0000007F&(data))
#define  HDMI_P3_PORT3_HDMI_AWDSR_get_awdpvsb(data)                              (0x0000007F&(data))

#define  HDMI_P3_PORT3_HDMI_VWDSR                                                0x180B20A8
#define  HDMI_P3_PORT3_HDMI_VWDSR_reg_addr                                       "0xB80B20A8"
#define  HDMI_P3_PORT3_HDMI_VWDSR_reg                                            0xB80B20A8
#define  HDMI_P3_PORT3_HDMI_VWDSR_inst_addr                                      "0x002A"
#define  set_HDMI_P3_PORT3_HDMI_VWDSR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VWDSR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VWDSR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VWDSR_reg))
#define  HDMI_P3_PORT3_HDMI_VWDSR_vwdpvsb_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_VWDSR_vwdpvsb_mask                                   (0x0000007F)
#define  HDMI_P3_PORT3_HDMI_VWDSR_vwdpvsb(data)                                  (0x0000007F&(data))
#define  HDMI_P3_PORT3_HDMI_VWDSR_get_vwdpvsb(data)                              (0x0000007F&(data))

#define  HDMI_P3_PORT3_HDMI_PAMICR                                               0x180B20AC
#define  HDMI_P3_PORT3_HDMI_PAMICR_reg_addr                                      "0xB80B20AC"
#define  HDMI_P3_PORT3_HDMI_PAMICR_reg                                           0xB80B20AC
#define  HDMI_P3_PORT3_HDMI_PAMICR_inst_addr                                     "0x002B"
#define  set_HDMI_P3_PORT3_HDMI_PAMICR_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PAMICR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PAMICR_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PAMICR_reg))
#define  HDMI_P3_PORT3_HDMI_PAMICR_icpvsb_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_PAMICR_icpvsb_mask                                   (0x0000007F)
#define  HDMI_P3_PORT3_HDMI_PAMICR_icpvsb(data)                                  (0x0000007F&(data))
#define  HDMI_P3_PORT3_HDMI_PAMICR_get_icpvsb(data)                              (0x0000007F&(data))

#define  HDMI_P3_PORT3_HDMI_PTRSV1                                               0x180B20B0
#define  HDMI_P3_PORT3_HDMI_PTRSV1_reg_addr                                      "0xB80B20B0"
#define  HDMI_P3_PORT3_HDMI_PTRSV1_reg                                           0xB80B20B0
#define  HDMI_P3_PORT3_HDMI_PTRSV1_inst_addr                                     "0x002C"
#define  set_HDMI_P3_PORT3_HDMI_PTRSV1_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PTRSV1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PTRSV1_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PTRSV1_reg))
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt3_shift                                     (24)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt2_shift                                     (16)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt1_shift                                     (8)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt0_shift                                     (0)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt3_mask                                      (0xFF000000)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt2_mask                                      (0x00FF0000)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt1_mask                                      (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt0_mask                                      (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt3(data)                                     (0xFF000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt2(data)                                     (0x00FF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt1(data)                                     (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_PTRSV1_pt0(data)                                     (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PTRSV1_get_pt3(data)                                 ((0xFF000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_get_pt2(data)                                 ((0x00FF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_get_pt1(data)                                 ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_PTRSV1_get_pt0(data)                                 (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PVGCR0                                               0x180B20B4
#define  HDMI_P3_PORT3_HDMI_PVGCR0_reg_addr                                      "0xB80B20B4"
#define  HDMI_P3_PORT3_HDMI_PVGCR0_reg                                           0xB80B20B4
#define  HDMI_P3_PORT3_HDMI_PVGCR0_inst_addr                                     "0x002D"
#define  set_HDMI_P3_PORT3_HDMI_PVGCR0_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PVGCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PVGCR0_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PVGCR0_reg))
#define  HDMI_P3_PORT3_HDMI_PVGCR0_pvsef_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_PVGCR0_pvsef_mask                                    (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDMI_PVGCR0_pvsef(data)                                   (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_PVGCR0_get_pvsef(data)                               (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_PVSR0                                                0x180B20B8
#define  HDMI_P3_PORT3_HDMI_PVSR0_reg_addr                                       "0xB80B20B8"
#define  HDMI_P3_PORT3_HDMI_PVSR0_reg                                            0xB80B20B8
#define  HDMI_P3_PORT3_HDMI_PVSR0_inst_addr                                      "0x002E"
#define  set_HDMI_P3_PORT3_HDMI_PVSR0_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PVSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PVSR0_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PVSR0_reg))
#define  HDMI_P3_PORT3_HDMI_PVSR0_pvs_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_PVSR0_pvs_mask                                       (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDMI_PVSR0_pvs(data)                                      (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_PVSR0_get_pvs(data)                                  (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_VCR                                                  0x180B20BC
#define  HDMI_P3_PORT3_HDMI_VCR_reg_addr                                         "0xB80B20BC"
#define  HDMI_P3_PORT3_HDMI_VCR_reg                                              0xB80B20BC
#define  HDMI_P3_PORT3_HDMI_VCR_inst_addr                                        "0x002F"
#define  set_HDMI_P3_PORT3_HDMI_VCR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VCR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VCR_reg))
#define  HDMI_P3_PORT3_HDMI_VCR_cbus_ddc_chsel_shift                             (28)
#define  HDMI_P3_PORT3_HDMI_VCR_hdmi_field_shift                                 (27)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_flag_shift                           (26)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_wd_en_shift                          (25)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_int_en_shift                         (24)
#define  HDMI_P3_PORT3_HDMI_VCR_hdcp_ddc_chsel_shift                             (22)
#define  HDMI_P3_PORT3_HDMI_VCR_iclk_sel_shift                                   (20)
#define  HDMI_P3_PORT3_HDMI_VCR_csc_r_shift                                      (18)
#define  HDMI_P3_PORT3_HDMI_VCR_hdirq_shift                                      (17)
#define  HDMI_P3_PORT3_HDMI_VCR_csam_shift                                       (16)
#define  HDMI_P3_PORT3_HDMI_VCR_csc_shift                                        (14)
#define  HDMI_P3_PORT3_HDMI_VCR_field_decide_sel_shift                           (13)
#define  HDMI_P3_PORT3_HDMI_VCR_prdsam_shift                                     (12)
#define  HDMI_P3_PORT3_HDMI_VCR_dsc_r_shift                                      (8)
#define  HDMI_P3_PORT3_HDMI_VCR_eoi_shift                                        (7)
#define  HDMI_P3_PORT3_HDMI_VCR_eot_shift                                        (6)
#define  HDMI_P3_PORT3_HDMI_VCR_se_shift                                         (5)
#define  HDMI_P3_PORT3_HDMI_VCR_rs_shift                                         (4)
#define  HDMI_P3_PORT3_HDMI_VCR_dsc_shift                                        (0)
#define  HDMI_P3_PORT3_HDMI_VCR_cbus_ddc_chsel_mask                              (0x10000000)
#define  HDMI_P3_PORT3_HDMI_VCR_hdmi_field_mask                                  (0x08000000)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_flag_mask                            (0x04000000)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_wd_en_mask                           (0x02000000)
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_int_en_mask                          (0x01000000)
#define  HDMI_P3_PORT3_HDMI_VCR_hdcp_ddc_chsel_mask                              (0x00C00000)
#define  HDMI_P3_PORT3_HDMI_VCR_iclk_sel_mask                                    (0x00300000)
#define  HDMI_P3_PORT3_HDMI_VCR_csc_r_mask                                       (0x000C0000)
#define  HDMI_P3_PORT3_HDMI_VCR_hdirq_mask                                       (0x00020000)
#define  HDMI_P3_PORT3_HDMI_VCR_csam_mask                                        (0x00010000)
#define  HDMI_P3_PORT3_HDMI_VCR_csc_mask                                         (0x0000C000)
#define  HDMI_P3_PORT3_HDMI_VCR_field_decide_sel_mask                            (0x00002000)
#define  HDMI_P3_PORT3_HDMI_VCR_prdsam_mask                                      (0x00001000)
#define  HDMI_P3_PORT3_HDMI_VCR_dsc_r_mask                                       (0x00000F00)
#define  HDMI_P3_PORT3_HDMI_VCR_eoi_mask                                         (0x00000080)
#define  HDMI_P3_PORT3_HDMI_VCR_eot_mask                                         (0x00000040)
#define  HDMI_P3_PORT3_HDMI_VCR_se_mask                                          (0x00000020)
#define  HDMI_P3_PORT3_HDMI_VCR_rs_mask                                          (0x00000010)
#define  HDMI_P3_PORT3_HDMI_VCR_dsc_mask                                         (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_VCR_cbus_ddc_chsel(data)                             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_HDMI_VCR_hdmi_field(data)                                 (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_flag(data)                           (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_wd_en(data)                          (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_HDMI_VCR_int_pro_chg_int_en(data)                         (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_VCR_hdcp_ddc_chsel(data)                             (0x00C00000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_VCR_iclk_sel(data)                                   (0x00300000&((data)<<20))
#define  HDMI_P3_PORT3_HDMI_VCR_csc_r(data)                                      (0x000C0000&((data)<<18))
#define  HDMI_P3_PORT3_HDMI_VCR_hdirq(data)                                      (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_VCR_csam(data)                                       (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_VCR_csc(data)                                        (0x0000C000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_VCR_field_decide_sel(data)                           (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_VCR_prdsam(data)                                     (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_VCR_dsc_r(data)                                      (0x00000F00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_VCR_eoi(data)                                        (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_VCR_eot(data)                                        (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_VCR_se(data)                                         (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_VCR_rs(data)                                         (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_VCR_dsc(data)                                        (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_VCR_get_cbus_ddc_chsel(data)                         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_HDMI_VCR_get_hdmi_field(data)                             ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_HDMI_VCR_get_int_pro_chg_flag(data)                       ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_HDMI_VCR_get_int_pro_chg_wd_en(data)                      ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_HDMI_VCR_get_int_pro_chg_int_en(data)                     ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_VCR_get_hdcp_ddc_chsel(data)                         ((0x00C00000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_VCR_get_iclk_sel(data)                               ((0x00300000&(data))>>20)
#define  HDMI_P3_PORT3_HDMI_VCR_get_csc_r(data)                                  ((0x000C0000&(data))>>18)
#define  HDMI_P3_PORT3_HDMI_VCR_get_hdirq(data)                                  ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_VCR_get_csam(data)                                   ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_VCR_get_csc(data)                                    ((0x0000C000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_VCR_get_field_decide_sel(data)                       ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_VCR_get_prdsam(data)                                 ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_VCR_get_dsc_r(data)                                  ((0x00000F00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_VCR_get_eoi(data)                                    ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_VCR_get_eot(data)                                    ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_VCR_get_se(data)                                     ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_VCR_get_rs(data)                                     ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_VCR_get_dsc(data)                                    (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_ACRCR                                                0x180B20C0
#define  HDMI_P3_PORT3_HDMI_ACRCR_reg_addr                                       "0xB80B20C0"
#define  HDMI_P3_PORT3_HDMI_ACRCR_reg                                            0xB80B20C0
#define  HDMI_P3_PORT3_HDMI_ACRCR_inst_addr                                      "0x0030"
#define  set_HDMI_P3_PORT3_HDMI_ACRCR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ACRCR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRCR_reg))
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucnr_shift                                    (1)
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucsr_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucnr_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucsr_mask                                     (0x00000001)
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucnr(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_ACRCR_pucsr(data)                                    (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_ACRCR_get_pucnr(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_ACRCR_get_pucsr(data)                                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_ACRSR0                                               0x180B20C4
#define  HDMI_P3_PORT3_HDMI_ACRSR0_reg_addr                                      "0xB80B20C4"
#define  HDMI_P3_PORT3_HDMI_ACRSR0_reg                                           0xB80B20C4
#define  HDMI_P3_PORT3_HDMI_ACRSR0_inst_addr                                     "0x0031"
#define  set_HDMI_P3_PORT3_HDMI_ACRSR0_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ACRSR0_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRSR0_reg))
#define  HDMI_P3_PORT3_HDMI_ACRSR0_cts_shift                                     (0)
#define  HDMI_P3_PORT3_HDMI_ACRSR0_cts_mask                                      (0x000FFFFF)
#define  HDMI_P3_PORT3_HDMI_ACRSR0_cts(data)                                     (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_ACRSR0_get_cts(data)                                 (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_ACRSR1                                               0x180B20C8
#define  HDMI_P3_PORT3_HDMI_ACRSR1_reg_addr                                      "0xB80B20C8"
#define  HDMI_P3_PORT3_HDMI_ACRSR1_reg                                           0xB80B20C8
#define  HDMI_P3_PORT3_HDMI_ACRSR1_inst_addr                                     "0x0032"
#define  set_HDMI_P3_PORT3_HDMI_ACRSR1_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRSR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ACRSR1_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACRSR1_reg))
#define  HDMI_P3_PORT3_HDMI_ACRSR1_n_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_ACRSR1_n_mask                                        (0x000FFFFF)
#define  HDMI_P3_PORT3_HDMI_ACRSR1_n(data)                                       (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_ACRSR1_get_n(data)                                   (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_ACS0                                                 0x180B20CC
#define  HDMI_P3_PORT3_HDMI_ACS0_reg_addr                                        "0xB80B20CC"
#define  HDMI_P3_PORT3_HDMI_ACS0_reg                                             0xB80B20CC
#define  HDMI_P3_PORT3_HDMI_ACS0_inst_addr                                       "0x0033"
#define  set_HDMI_P3_PORT3_HDMI_ACS0_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACS0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ACS0_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACS0_reg))
#define  HDMI_P3_PORT3_HDMI_ACS0_cs_shift                                        (0)
#define  HDMI_P3_PORT3_HDMI_ACS0_cs_mask                                         (0x0000FFFF)
#define  HDMI_P3_PORT3_HDMI_ACS0_cs(data)                                        (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_HDMI_ACS0_get_cs(data)                                    (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_HDMI_ACS1                                                 0x180B20D0
#define  HDMI_P3_PORT3_HDMI_ACS1_reg_addr                                        "0xB80B20D0"
#define  HDMI_P3_PORT3_HDMI_ACS1_reg                                             0xB80B20D0
#define  HDMI_P3_PORT3_HDMI_ACS1_inst_addr                                       "0x0034"
#define  set_HDMI_P3_PORT3_HDMI_ACS1_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACS1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ACS1_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ACS1_reg))
#define  HDMI_P3_PORT3_HDMI_ACS1_cs_shift                                        (0)
#define  HDMI_P3_PORT3_HDMI_ACS1_cs_mask                                         (0x00FFFFFF)
#define  HDMI_P3_PORT3_HDMI_ACS1_cs(data)                                        (0x00FFFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_ACS1_get_cs(data)                                    (0x00FFFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_INTCR                                                0x180B20D4
#define  HDMI_P3_PORT3_HDMI_INTCR_reg_addr                                       "0xB80B20D4"
#define  HDMI_P3_PORT3_HDMI_INTCR_reg                                            0xB80B20D4
#define  HDMI_P3_PORT3_HDMI_INTCR_inst_addr                                      "0x0035"
#define  set_HDMI_P3_PORT3_HDMI_INTCR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_INTCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_INTCR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_INTCR_reg))
#define  HDMI_P3_PORT3_HDMI_INTCR_pending_shift                                  (7)
#define  HDMI_P3_PORT3_HDMI_INTCR_avmute_shift                                   (6)
#define  HDMI_P3_PORT3_HDMI_INTCR_fifod_shift                                    (5)
#define  HDMI_P3_PORT3_HDMI_INTCR_act_shift                                      (4)
#define  HDMI_P3_PORT3_HDMI_INTCR_apll_shift                                     (3)
#define  HDMI_P3_PORT3_HDMI_INTCR_afifoo_shift                                   (2)
#define  HDMI_P3_PORT3_HDMI_INTCR_afifou_shift                                   (1)
#define  HDMI_P3_PORT3_HDMI_INTCR_vc_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_INTCR_pending_mask                                   (0x00000080)
#define  HDMI_P3_PORT3_HDMI_INTCR_avmute_mask                                    (0x00000040)
#define  HDMI_P3_PORT3_HDMI_INTCR_fifod_mask                                     (0x00000020)
#define  HDMI_P3_PORT3_HDMI_INTCR_act_mask                                       (0x00000010)
#define  HDMI_P3_PORT3_HDMI_INTCR_apll_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_HDMI_INTCR_afifoo_mask                                    (0x00000004)
#define  HDMI_P3_PORT3_HDMI_INTCR_afifou_mask                                    (0x00000002)
#define  HDMI_P3_PORT3_HDMI_INTCR_vc_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_HDMI_INTCR_pending(data)                                  (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_INTCR_avmute(data)                                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_INTCR_fifod(data)                                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_INTCR_act(data)                                      (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_INTCR_apll(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_INTCR_afifoo(data)                                   (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_INTCR_afifou(data)                                   (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_INTCR_vc(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_INTCR_get_pending(data)                              ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_avmute(data)                               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_fifod(data)                                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_act(data)                                  ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_apll(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_afifoo(data)                               ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_afifou(data)                               ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_INTCR_get_vc(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_ALCR                                                 0x180B20D8
#define  HDMI_P3_PORT3_HDMI_ALCR_reg_addr                                        "0xB80B20D8"
#define  HDMI_P3_PORT3_HDMI_ALCR_reg                                             0xB80B20D8
#define  HDMI_P3_PORT3_HDMI_ALCR_inst_addr                                       "0x0036"
#define  set_HDMI_P3_PORT3_HDMI_ALCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ALCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ALCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ALCR_reg))
#define  HDMI_P3_PORT3_HDMI_ALCR_lo1_shift                                       (6)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo2_shift                                       (4)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo3_shift                                       (2)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo4_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo1_mask                                        (0x000000C0)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo2_mask                                        (0x00000030)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo3_mask                                        (0x0000000C)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo4_mask                                        (0x00000003)
#define  HDMI_P3_PORT3_HDMI_ALCR_lo1(data)                                       (0x000000C0&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_ALCR_lo2(data)                                       (0x00000030&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_ALCR_lo3(data)                                       (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_ALCR_lo4(data)                                       (0x00000003&(data))
#define  HDMI_P3_PORT3_HDMI_ALCR_get_lo1(data)                                   ((0x000000C0&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_ALCR_get_lo2(data)                                   ((0x00000030&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_ALCR_get_lo3(data)                                   ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_ALCR_get_lo4(data)                                   (0x00000003&(data))

#define  HDMI_P3_PORT3_HDMI_AOCR                                                 0x180B20DC
#define  HDMI_P3_PORT3_HDMI_AOCR_reg_addr                                        "0xB80B20DC"
#define  HDMI_P3_PORT3_HDMI_AOCR_reg                                             0xB80B20DC
#define  HDMI_P3_PORT3_HDMI_AOCR_inst_addr                                       "0x0037"
#define  set_HDMI_P3_PORT3_HDMI_AOCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AOCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AOCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AOCR_reg))
#define  HDMI_P3_PORT3_HDMI_AOCR_i2s_clk_en_dvi_shift                            (8)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo1_shift                                   (7)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo2_shift                                   (6)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo3_shift                                   (5)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo4_shift                                   (4)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so1_shift                                     (3)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so2_shift                                     (2)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so3_shift                                     (1)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so4_shift                                     (0)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2s_clk_en_dvi_mask                             (0x00000100)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo1_mask                                    (0x00000080)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo2_mask                                    (0x00000040)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo3_mask                                    (0x00000020)
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo4_mask                                    (0x00000010)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so1_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so2_mask                                      (0x00000004)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so3_mask                                      (0x00000002)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so4_mask                                      (0x00000001)
#define  HDMI_P3_PORT3_HDMI_AOCR_i2s_clk_en_dvi(data)                            (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo1(data)                                   (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo2(data)                                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo3(data)                                   (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_AOCR_spdifo4(data)                                   (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so1(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so2(data)                                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so3(data)                                     (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_AOCR_i2so4(data)                                     (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_AOCR_get_i2s_clk_en_dvi(data)                        ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_spdifo1(data)                               ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_spdifo2(data)                               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_spdifo3(data)                               ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_spdifo4(data)                               ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_i2so1(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_i2so2(data)                                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_i2so3(data)                                 ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_AOCR_get_i2so4(data)                                 (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_BCSR                                                 0x180B20E0
#define  HDMI_P3_PORT3_HDMI_BCSR_reg_addr                                        "0xB80B20E0"
#define  HDMI_P3_PORT3_HDMI_BCSR_reg                                             0xB80B20E0
#define  HDMI_P3_PORT3_HDMI_BCSR_inst_addr                                       "0x0038"
#define  set_HDMI_P3_PORT3_HDMI_BCSR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_BCSR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_BCSR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_BCSR_reg))
#define  HDMI_P3_PORT3_HDMI_BCSR_nvlgb_shift                                     (5)
#define  HDMI_P3_PORT3_HDMI_BCSR_nalgb_shift                                     (4)
#define  HDMI_P3_PORT3_HDMI_BCSR_natgb_shift                                     (3)
#define  HDMI_P3_PORT3_HDMI_BCSR_ngb_shift                                       (2)
#define  HDMI_P3_PORT3_HDMI_BCSR_pe_shift                                        (1)
#define  HDMI_P3_PORT3_HDMI_BCSR_gcp_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_BCSR_nvlgb_mask                                      (0x00000020)
#define  HDMI_P3_PORT3_HDMI_BCSR_nalgb_mask                                      (0x00000010)
#define  HDMI_P3_PORT3_HDMI_BCSR_natgb_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_HDMI_BCSR_ngb_mask                                        (0x00000004)
#define  HDMI_P3_PORT3_HDMI_BCSR_pe_mask                                         (0x00000002)
#define  HDMI_P3_PORT3_HDMI_BCSR_gcp_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_HDMI_BCSR_nvlgb(data)                                     (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_BCSR_nalgb(data)                                     (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_BCSR_natgb(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_BCSR_ngb(data)                                       (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_BCSR_pe(data)                                        (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_BCSR_gcp(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_BCSR_get_nvlgb(data)                                 ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_BCSR_get_nalgb(data)                                 ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_BCSR_get_natgb(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_BCSR_get_ngb(data)                                   ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_BCSR_get_pe(data)                                    ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_BCSR_get_gcp(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_ASR0                                                 0x180B20E4
#define  HDMI_P3_PORT3_HDMI_ASR0_reg_addr                                        "0xB80B20E4"
#define  HDMI_P3_PORT3_HDMI_ASR0_reg                                             0xB80B20E4
#define  HDMI_P3_PORT3_HDMI_ASR0_inst_addr                                       "0x0039"
#define  set_HDMI_P3_PORT3_HDMI_ASR0_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ASR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ASR0_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ASR0_reg))
#define  HDMI_P3_PORT3_HDMI_ASR0_fsre_shift                                      (2)
#define  HDMI_P3_PORT3_HDMI_ASR0_fsif_shift                                      (1)
#define  HDMI_P3_PORT3_HDMI_ASR0_fscs_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_ASR0_fsre_mask                                       (0x00000004)
#define  HDMI_P3_PORT3_HDMI_ASR0_fsif_mask                                       (0x00000002)
#define  HDMI_P3_PORT3_HDMI_ASR0_fscs_mask                                       (0x00000001)
#define  HDMI_P3_PORT3_HDMI_ASR0_fsre(data)                                      (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_ASR0_fsif(data)                                      (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_ASR0_fscs(data)                                      (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_ASR0_get_fsre(data)                                  ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_ASR0_get_fsif(data)                                  ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_ASR0_get_fscs(data)                                  (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_ASR1                                                 0x180B20E8
#define  HDMI_P3_PORT3_HDMI_ASR1_reg_addr                                        "0xB80B20E8"
#define  HDMI_P3_PORT3_HDMI_ASR1_reg                                             0xB80B20E8
#define  HDMI_P3_PORT3_HDMI_ASR1_inst_addr                                       "0x003A"
#define  set_HDMI_P3_PORT3_HDMI_ASR1_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ASR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ASR1_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ASR1_reg))
#define  HDMI_P3_PORT3_HDMI_ASR1_fbif_shift                                      (4)
#define  HDMI_P3_PORT3_HDMI_ASR1_fbcs_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_ASR1_fbif_mask                                       (0x00000070)
#define  HDMI_P3_PORT3_HDMI_ASR1_fbcs_mask                                       (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_ASR1_fbif(data)                                      (0x00000070&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_ASR1_fbcs(data)                                      (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_ASR1_get_fbif(data)                                  ((0x00000070&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_ASR1_get_fbcs(data)                                  (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT                                         0x180B20EC
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg_addr                                "0xB80B20EC"
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg                                     0xB80B20EC
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_inst_addr                               "0x003B"
#define  set_HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg(data)                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_reg))
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hvf_shift                               (8)
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hdmi_vic_shift                          (0)
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hvf_mask                                (0x00000700)
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hdmi_vic_mask                           (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hvf(data)                               (0x00000700&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_hdmi_vic(data)                          (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_get_hvf(data)                           ((0x00000700&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_VIDEO_FORMAT_get_hdmi_vic(data)                      (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_3D_FORMAT                                            0x180B20F0
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_reg_addr                                   "0xB80B20F0"
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_reg                                        0xB80B20F0
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_inst_addr                                  "0x003C"
#define  set_HDMI_P3_PORT3_HDMI_3D_FORMAT_reg(data)                              (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_3D_FORMAT_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_3D_FORMAT_reg                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_3D_FORMAT_reg))
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_ext_data_shift                     (12)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_metadata_type_shift                (9)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_structure_shift                    (4)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_meta_present_shift                 (3)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_ext_data_mask                      (0x0000F000)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_metadata_type_mask                 (0x00000E00)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_structure_mask                     (0x000000F0)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_meta_present_mask                  (0x00000008)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_ext_data(data)                     (0x0000F000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_metadata_type(data)                (0x00000E00&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_structure(data)                    (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_hdmi_3d_meta_present(data)                 (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_get_hdmi_3d_ext_data(data)                 ((0x0000F000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_get_hdmi_3d_metadata_type(data)            ((0x00000E00&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_get_hdmi_3d_structure(data)                ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_3D_FORMAT_get_hdmi_3d_meta_present(data)             ((0x00000008&(data))>>3)

#define  HDMI_P3_PORT3_HDMI_FVS                                                  0x180B20F4
#define  HDMI_P3_PORT3_HDMI_FVS_reg_addr                                         "0xB80B20F4"
#define  HDMI_P3_PORT3_HDMI_FVS_reg                                              0xB80B20F4
#define  HDMI_P3_PORT3_HDMI_FVS_inst_addr                                        "0x003D"
#define  set_HDMI_P3_PORT3_HDMI_FVS_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FVS_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_FVS_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FVS_reg))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_preferred2dview_shift                    (13)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_viewdependency_shift                     (11)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_dualview_shift                           (10)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_additionalinfo_present_shift             (9)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_ext_data_shift                         (5)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_structure_shift                        (1)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_valid_shift                              (0)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_preferred2dview_mask                     (0x00006000)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_viewdependency_mask                      (0x00001800)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_dualview_mask                            (0x00000400)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_additionalinfo_present_mask              (0x00000200)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_ext_data_mask                          (0x000001E0)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_structure_mask                         (0x0000001E)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_valid_mask                               (0x00000001)
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_preferred2dview(data)                    (0x00006000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_viewdependency(data)                     (0x00001800&((data)<<11))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_dualview(data)                           (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_additionalinfo_present(data)             (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_ext_data(data)                         (0x000001E0&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_f_structure(data)                        (0x0000001E&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_FVS_info_3d_valid(data)                              (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_preferred2dview(data)                ((0x00006000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_viewdependency(data)                 ((0x00001800&(data))>>11)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_dualview(data)                       ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_additionalinfo_present(data)         ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_f_ext_data(data)                     ((0x000001E0&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_f_structure(data)                    ((0x0000001E&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_FVS_get_info_3d_valid(data)                          (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_DRM                                                  0x180B20F8
#define  HDMI_P3_PORT3_HDMI_DRM_reg_addr                                         "0xB80B20F8"
#define  HDMI_P3_PORT3_HDMI_DRM_reg                                              0xB80B20F8
#define  HDMI_P3_PORT3_HDMI_DRM_inst_addr                                        "0x003E"
#define  set_HDMI_P3_PORT3_HDMI_DRM_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DRM_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_DRM_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DRM_reg))
#define  HDMI_P3_PORT3_HDMI_DRM_static_metadata_descriptor_id_shift              (4)
#define  HDMI_P3_PORT3_HDMI_DRM_eotf_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_DRM_static_metadata_descriptor_id_mask               (0x00000070)
#define  HDMI_P3_PORT3_HDMI_DRM_eotf_mask                                        (0x00000007)
#define  HDMI_P3_PORT3_HDMI_DRM_static_metadata_descriptor_id(data)              (0x00000070&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_DRM_eotf(data)                                       (0x00000007&(data))
#define  HDMI_P3_PORT3_HDMI_DRM_get_static_metadata_descriptor_id(data)          ((0x00000070&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_DRM_get_eotf(data)                                   (0x00000007&(data))

#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ                              0x180B2100
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg_addr                     "0xB80B2100"
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg                          0xB80B2100
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_inst_addr                    "0x003F"
#define  set_HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg(data)                (*((volatile unsigned int*)HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg)=data)
#define  get_HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg                      (*((volatile unsigned int*)HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_reg))
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ncts_chg_irq_shift        (3)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ncts_chg_irq_shift           (2)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ch_status_chg_irq_shift   (1)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ch_status_chg_irq_shift      (0)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ncts_chg_irq_mask         (0x00000008)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ncts_chg_irq_mask            (0x00000004)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ch_status_chg_irq_mask    (0x00000002)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ch_status_chg_irq_mask       (0x00000001)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ncts_chg_irq(data)        (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ncts_chg_irq(data)           (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_en_ch_status_chg_irq(data)   (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_ch_status_chg_irq(data)      (0x00000001&(data))
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_get_en_ncts_chg_irq(data)    ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_get_ncts_chg_irq(data)       ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_get_en_ch_status_chg_irq(data) ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_Audio_Sample_Rate_Change_IRQ_get_ch_status_chg_irq(data)  (0x00000001&(data))

#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet                                0x180B2104
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg_addr                       "0xB80B2104"
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg                            0xB80B2104
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_inst_addr                      "0x0040"
#define  set_HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg(data)                  (*((volatile unsigned int*)HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg)=data)
#define  get_HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg                        (*((volatile unsigned int*)HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_reg))
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_manual_shift    (2)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_fw_shift        (1)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_shift           (0)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_manual_mask     (0x00000004)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_fw_mask         (0x00000002)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_mask            (0x00000001)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_manual(data)    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode_fw(data)        (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_hbr_audio_mode(data)           (0x00000001&(data))
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_get_hbr_audio_mode_manual(data) ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_get_hbr_audio_mode_fw(data)    ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_High_Bit_Rate_Audio_Packet_get_hbr_audio_mode(data)       (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_AFCR                                                 0x180B2108
#define  HDMI_P3_PORT3_HDMI_AFCR_reg_addr                                        "0xB80B2108"
#define  HDMI_P3_PORT3_HDMI_AFCR_reg                                             0xB80B2108
#define  HDMI_P3_PORT3_HDMI_AFCR_inst_addr                                       "0x0041"
#define  set_HDMI_P3_PORT3_HDMI_AFCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AFCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFCR_reg))
#define  HDMI_P3_PORT3_HDMI_AFCR_dummy_31_14_shift                               (14)
#define  HDMI_P3_PORT3_HDMI_AFCR_gain_bypass_en_shift                            (13)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifof_shift                                    (12)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifoe_shift                                    (11)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe_r_shift                                 (10)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore_r_shift                                 (8)
#define  HDMI_P3_PORT3_HDMI_AFCR_tst_i2s_sw_shift                                (7)
#define  HDMI_P3_PORT3_HDMI_AFCR_aoem_shift                                      (6)
#define  HDMI_P3_PORT3_HDMI_AFCR_aoc_shift                                       (5)
#define  HDMI_P3_PORT3_HDMI_AFCR_audio_test_enable_shift                         (4)
#define  HDMI_P3_PORT3_HDMI_AFCR_mgc_shift                                       (3)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe_shift                                   (2)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_AFCR_dummy_31_14_mask                                (0xFFFFC000)
#define  HDMI_P3_PORT3_HDMI_AFCR_gain_bypass_en_mask                             (0x00002000)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifof_mask                                     (0x00001000)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifoe_mask                                     (0x00000800)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe_r_mask                                  (0x00000400)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore_r_mask                                  (0x00000300)
#define  HDMI_P3_PORT3_HDMI_AFCR_tst_i2s_sw_mask                                 (0x00000080)
#define  HDMI_P3_PORT3_HDMI_AFCR_aoem_mask                                       (0x00000040)
#define  HDMI_P3_PORT3_HDMI_AFCR_aoc_mask                                        (0x00000020)
#define  HDMI_P3_PORT3_HDMI_AFCR_audio_test_enable_mask                          (0x00000010)
#define  HDMI_P3_PORT3_HDMI_AFCR_mgc_mask                                        (0x00000008)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe_mask                                    (0x00000004)
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore_mask                                    (0x00000003)
#define  HDMI_P3_PORT3_HDMI_AFCR_dummy_31_14(data)                               (0xFFFFC000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_AFCR_gain_bypass_en(data)                            (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifof(data)                                    (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifoe(data)                                    (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe_r(data)                                 (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore_r(data)                                 (0x00000300&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_AFCR_tst_i2s_sw(data)                                (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_AFCR_aoem(data)                                      (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_AFCR_aoc(data)                                       (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_AFCR_audio_test_enable(data)                         (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_AFCR_mgc(data)                                       (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifowe(data)                                   (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_AFCR_afifore(data)                                   (0x00000003&(data))
#define  HDMI_P3_PORT3_HDMI_AFCR_get_dummy_31_14(data)                           ((0xFFFFC000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_gain_bypass_en(data)                        ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifof(data)                                ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifoe(data)                                ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifowe_r(data)                             ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifore_r(data)                             ((0x00000300&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_tst_i2s_sw(data)                            ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_aoem(data)                                  ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_aoc(data)                                   ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_audio_test_enable(data)                     ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_mgc(data)                                   ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifowe(data)                               ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_AFCR_get_afifore(data)                               (0x00000003&(data))

#define  HDMI_P3_PORT3_HDMI_AFSR                                                 0x180B210C
#define  HDMI_P3_PORT3_HDMI_AFSR_reg_addr                                        "0xB80B210C"
#define  HDMI_P3_PORT3_HDMI_AFSR_reg                                             0xB80B210C
#define  HDMI_P3_PORT3_HDMI_AFSR_inst_addr                                       "0x0042"
#define  set_HDMI_P3_PORT3_HDMI_AFSR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFSR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AFSR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFSR_reg))
#define  HDMI_P3_PORT3_HDMI_AFSR_audio_bist_clksel_shift                         (0)
#define  HDMI_P3_PORT3_HDMI_AFSR_audio_bist_clksel_mask                          (0x00000001)
#define  HDMI_P3_PORT3_HDMI_AFSR_audio_bist_clksel(data)                         (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_AFSR_get_audio_bist_clksel(data)                     (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_MAGCR0                                               0x180B2110
#define  HDMI_P3_PORT3_HDMI_MAGCR0_reg_addr                                      "0xB80B2110"
#define  HDMI_P3_PORT3_HDMI_MAGCR0_reg                                           0xB80B2110
#define  HDMI_P3_PORT3_HDMI_MAGCR0_inst_addr                                     "0x0043"
#define  set_HDMI_P3_PORT3_HDMI_MAGCR0_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MAGCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_MAGCR0_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MAGCR0_reg))
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agi_shift                                     (13)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agd_shift                                     (8)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_mg_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agi_mask                                      (0x0000E000)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agd_mask                                      (0x00001F00)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_mg_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agi(data)                                     (0x0000E000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_MAGCR0_agd(data)                                     (0x00001F00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_MAGCR0_mg(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_MAGCR0_get_agi(data)                                 ((0x0000E000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_get_agd(data)                                 ((0x00001F00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_MAGCR0_get_mg(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL                                          0x180B2114
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg_addr                                 "0xB80B2114"
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg                                      0xB80B2114
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_inst_addr                                "0x0044"
#define  set_HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg(data)                            (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MAG_M_FINAL_reg))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time_shift                           (21)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time_mode_shift                      (20)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_r_shift                               (12)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_l_shift                               (4)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_auto_dly_mod_shift                       (3)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_en_shift                              (2)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_l_shift                              (1)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_r_shift                              (0)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time_mask                            (0x7FE00000)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time_mode_mask                       (0x00100000)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_r_mask                                (0x000FF000)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_l_mask                                (0x00000FF0)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_auto_dly_mod_mask                        (0x00000008)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_en_mask                               (0x00000004)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_l_mask                               (0x00000002)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_r_mask                               (0x00000001)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time(data)                           (0x7FE00000&((data)<<21))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ldp_time_mode(data)                      (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_r(data)                               (0x000FF000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_l(data)                               (0x00000FF0&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_auto_dly_mod(data)                       (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_fg_en(data)                              (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_l(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_ffg_r(data)                              (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_ldp_time(data)                       ((0x7FE00000&(data))>>21)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_ldp_time_mode(data)                  ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_fg_r(data)                           ((0x000FF000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_fg_l(data)                           ((0x00000FF0&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_auto_dly_mod(data)                   ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_fg_en(data)                          ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_ffg_l(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_MAG_M_FINAL_get_ffg_r(data)                          (0x00000001&(data))

#define  HDMI_P3_PORT3_ZCD_CTRL                                                  0x180B2118
#define  HDMI_P3_PORT3_ZCD_CTRL_reg_addr                                         "0xB80B2118"
#define  HDMI_P3_PORT3_ZCD_CTRL_reg                                              0xB80B2118
#define  HDMI_P3_PORT3_ZCD_CTRL_inst_addr                                        "0x0045"
#define  set_HDMI_P3_PORT3_ZCD_CTRL_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_ZCD_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_ZCD_CTRL_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_ZCD_CTRL_reg))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch7_done_shift                               (23)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch6_done_shift                               (22)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch5_done_shift                               (21)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch4_done_shift                               (20)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch3_done_shift                               (19)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch2_done_shift                               (18)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch1_done_shift                               (17)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch0_done_shift                               (16)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_timeout_shift                                (8)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_en_shift                                     (7)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_8ch_shift                                (6)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_st_shift                                 (5)
#define  HDMI_P3_PORT3_ZCD_CTRL_dummy_4_0_shift                                  (0)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch7_done_mask                                (0x00800000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch6_done_mask                                (0x00400000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch5_done_mask                                (0x00200000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch4_done_mask                                (0x00100000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch3_done_mask                                (0x00080000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch2_done_mask                                (0x00040000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch1_done_mask                                (0x00020000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch0_done_mask                                (0x00010000)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_timeout_mask                                 (0x00007F00)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_en_mask                                      (0x00000080)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_8ch_mask                                 (0x00000040)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_st_mask                                  (0x00000020)
#define  HDMI_P3_PORT3_ZCD_CTRL_dummy_4_0_mask                                   (0x0000001F)
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch7_done(data)                               (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch6_done(data)                               (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch5_done(data)                               (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch4_done(data)                               (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch3_done(data)                               (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch2_done(data)                               (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch1_done(data)                               (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_ch0_done(data)                               (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_timeout(data)                                (0x00007F00&((data)<<8))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_en(data)                                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_8ch(data)                                (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_ZCD_CTRL_zcd_sep_st(data)                                 (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_ZCD_CTRL_dummy_4_0(data)                                  (0x0000001F&(data))
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch7_done(data)                           ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch6_done(data)                           ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch5_done(data)                           ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch4_done(data)                           ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch3_done(data)                           ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch2_done(data)                           ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch1_done(data)                           ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_ch0_done(data)                           ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_timeout(data)                            ((0x00007F00&(data))>>8)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_en(data)                                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_sep_8ch(data)                            ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_zcd_sep_st(data)                             ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_ZCD_CTRL_get_dummy_4_0(data)                              (0x0000001F&(data))

#define  HDMI_P3_PORT3_AUDIO_FREQDET                                             0x180B211C
#define  HDMI_P3_PORT3_AUDIO_FREQDET_reg_addr                                    "0xB80B211C"
#define  HDMI_P3_PORT3_AUDIO_FREQDET_reg                                         0xB80B211C
#define  HDMI_P3_PORT3_AUDIO_FREQDET_inst_addr                                   "0x0046"
#define  set_HDMI_P3_PORT3_AUDIO_FREQDET_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_FREQDET_reg)=data)
#define  get_HDMI_P3_PORT3_AUDIO_FREQDET_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_FREQDET_reg))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_xtal_div_shift                              (24)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_result_shift                     (12)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_range_shift                      (9)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_popup_afreq_meas_result_shift               (8)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_audio_freq_detect_shift                     (7)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_auto_load_scode_shift                       (6)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_freqchange_shift                     (5)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_noaudio_shift                        (4)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_freqchange_shift                     (3)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_noaudio_shift                        (2)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_freqchange_shift                            (1)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_noaudio_shift                               (0)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_xtal_div_mask                               (0xFF000000)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_result_mask                      (0x00FFF000)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_range_mask                       (0x00000E00)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_popup_afreq_meas_result_mask                (0x00000100)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_audio_freq_detect_mask                      (0x00000080)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_auto_load_scode_mask                        (0x00000040)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_freqchange_mask                      (0x00000020)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_noaudio_mask                         (0x00000010)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_freqchange_mask                      (0x00000008)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_noaudio_mask                         (0x00000004)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_freqchange_mask                             (0x00000002)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_noaudio_mask                                (0x00000001)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_xtal_div(data)                              (0xFF000000&((data)<<24))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_result(data)                     (0x00FFF000&((data)<<12))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_afreq_meas_range(data)                      (0x00000E00&((data)<<9))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_popup_afreq_meas_result(data)               (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_audio_freq_detect(data)                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_auto_load_scode(data)                       (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_freqchange(data)                     (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_awd_by_noaudio(data)                        (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_freqchange(data)                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_irq_by_noaudio(data)                        (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_freqchange(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_noaudio(data)                               (0x00000001&(data))
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_xtal_div(data)                          ((0xFF000000&(data))>>24)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_afreq_meas_result(data)                 ((0x00FFF000&(data))>>12)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_afreq_meas_range(data)                  ((0x00000E00&(data))>>9)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_popup_afreq_meas_result(data)           ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_audio_freq_detect(data)                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_auto_load_scode(data)                   ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_awd_by_freqchange(data)                 ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_awd_by_noaudio(data)                    ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_irq_by_freqchange(data)                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_irq_by_noaudio(data)                    ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_freqchange(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_AUDIO_FREQDET_get_noaudio(data)                           (0x00000001&(data))

#define  HDMI_P3_PORT3_RANGE0_1                                                  0x180B2120
#define  HDMI_P3_PORT3_RANGE0_1_reg_addr                                         "0xB80B2120"
#define  HDMI_P3_PORT3_RANGE0_1_reg                                              0xB80B2120
#define  HDMI_P3_PORT3_RANGE0_1_inst_addr                                        "0x0047"
#define  set_HDMI_P3_PORT3_RANGE0_1_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE0_1_reg)=data)
#define  get_HDMI_P3_PORT3_RANGE0_1_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE0_1_reg))
#define  HDMI_P3_PORT3_RANGE0_1_range0_th_shift                                  (12)
#define  HDMI_P3_PORT3_RANGE0_1_range1_th_shift                                  (0)
#define  HDMI_P3_PORT3_RANGE0_1_range0_th_mask                                   (0x00FFF000)
#define  HDMI_P3_PORT3_RANGE0_1_range1_th_mask                                   (0x00000FFF)
#define  HDMI_P3_PORT3_RANGE0_1_range0_th(data)                                  (0x00FFF000&((data)<<12))
#define  HDMI_P3_PORT3_RANGE0_1_range1_th(data)                                  (0x00000FFF&(data))
#define  HDMI_P3_PORT3_RANGE0_1_get_range0_th(data)                              ((0x00FFF000&(data))>>12)
#define  HDMI_P3_PORT3_RANGE0_1_get_range1_th(data)                              (0x00000FFF&(data))

#define  HDMI_P3_PORT3_RANGE2_3                                                  0x180B2124
#define  HDMI_P3_PORT3_RANGE2_3_reg_addr                                         "0xB80B2124"
#define  HDMI_P3_PORT3_RANGE2_3_reg                                              0xB80B2124
#define  HDMI_P3_PORT3_RANGE2_3_inst_addr                                        "0x0048"
#define  set_HDMI_P3_PORT3_RANGE2_3_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE2_3_reg)=data)
#define  get_HDMI_P3_PORT3_RANGE2_3_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE2_3_reg))
#define  HDMI_P3_PORT3_RANGE2_3_range2_th_shift                                  (12)
#define  HDMI_P3_PORT3_RANGE2_3_range3_th_shift                                  (0)
#define  HDMI_P3_PORT3_RANGE2_3_range2_th_mask                                   (0x00FFF000)
#define  HDMI_P3_PORT3_RANGE2_3_range3_th_mask                                   (0x00000FFF)
#define  HDMI_P3_PORT3_RANGE2_3_range2_th(data)                                  (0x00FFF000&((data)<<12))
#define  HDMI_P3_PORT3_RANGE2_3_range3_th(data)                                  (0x00000FFF&(data))
#define  HDMI_P3_PORT3_RANGE2_3_get_range2_th(data)                              ((0x00FFF000&(data))>>12)
#define  HDMI_P3_PORT3_RANGE2_3_get_range3_th(data)                              (0x00000FFF&(data))

#define  HDMI_P3_PORT3_RANGE4_5                                                  0x180B2128
#define  HDMI_P3_PORT3_RANGE4_5_reg_addr                                         "0xB80B2128"
#define  HDMI_P3_PORT3_RANGE4_5_reg                                              0xB80B2128
#define  HDMI_P3_PORT3_RANGE4_5_inst_addr                                        "0x0049"
#define  set_HDMI_P3_PORT3_RANGE4_5_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE4_5_reg)=data)
#define  get_HDMI_P3_PORT3_RANGE4_5_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_RANGE4_5_reg))
#define  HDMI_P3_PORT3_RANGE4_5_range4_th_shift                                  (12)
#define  HDMI_P3_PORT3_RANGE4_5_range5_th_shift                                  (0)
#define  HDMI_P3_PORT3_RANGE4_5_range4_th_mask                                   (0x00FFF000)
#define  HDMI_P3_PORT3_RANGE4_5_range5_th_mask                                   (0x00000FFF)
#define  HDMI_P3_PORT3_RANGE4_5_range4_th(data)                                  (0x00FFF000&((data)<<12))
#define  HDMI_P3_PORT3_RANGE4_5_range5_th(data)                                  (0x00000FFF&(data))
#define  HDMI_P3_PORT3_RANGE4_5_get_range4_th(data)                              ((0x00FFF000&(data))>>12)
#define  HDMI_P3_PORT3_RANGE4_5_get_range5_th(data)                              (0x00000FFF&(data))

#define  HDMI_P3_PORT3_PRESET_S_CODE0                                            0x180B212C
#define  HDMI_P3_PORT3_PRESET_S_CODE0_reg_addr                                   "0xB80B212C"
#define  HDMI_P3_PORT3_PRESET_S_CODE0_reg                                        0xB80B212C
#define  HDMI_P3_PORT3_PRESET_S_CODE0_inst_addr                                  "0x004A"
#define  set_HDMI_P3_PORT3_PRESET_S_CODE0_reg(data)                              (*((volatile unsigned int*)HDMI_P3_PORT3_PRESET_S_CODE0_reg)=data)
#define  get_HDMI_P3_PORT3_PRESET_S_CODE0_reg                                    (*((volatile unsigned int*)HDMI_P3_PORT3_PRESET_S_CODE0_reg))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code3_shift                     (31)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code3_shift                      (24)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code2_shift                     (23)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code2_shift                      (16)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code1_shift                     (15)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code1_shift                      (8)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code0_shift                     (7)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code0_shift                      (0)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code3_mask                      (0x80000000)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code3_mask                       (0x7F000000)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code2_mask                      (0x00800000)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code2_mask                       (0x007F0000)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code1_mask                      (0x00008000)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code1_mask                       (0x00007F00)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code0_mask                      (0x00000080)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code0_mask                       (0x0000007F)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code3(data)                     (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code3(data)                      (0x7F000000&((data)<<24))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code2(data)                     (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code2(data)                      (0x007F0000&((data)<<16))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code1(data)                     (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code1(data)                      (0x00007F00&((data)<<8))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s1_code0(data)                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_pre_set_s_code0(data)                      (0x0000007F&(data))
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s1_code3(data)                 ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s_code3(data)                  ((0x7F000000&(data))>>24)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s1_code2(data)                 ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s_code2(data)                  ((0x007F0000&(data))>>16)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s1_code1(data)                 ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s_code1(data)                  ((0x00007F00&(data))>>8)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s1_code0(data)                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PRESET_S_CODE0_get_pre_set_s_code0(data)                  (0x0000007F&(data))

#define  HDMI_P3_PORT3_PRESET_S_CODE1                                            0x180B2130
#define  HDMI_P3_PORT3_PRESET_S_CODE1_reg_addr                                   "0xB80B2130"
#define  HDMI_P3_PORT3_PRESET_S_CODE1_reg                                        0xB80B2130
#define  HDMI_P3_PORT3_PRESET_S_CODE1_inst_addr                                  "0x004B"
#define  set_HDMI_P3_PORT3_PRESET_S_CODE1_reg(data)                              (*((volatile unsigned int*)HDMI_P3_PORT3_PRESET_S_CODE1_reg)=data)
#define  get_HDMI_P3_PORT3_PRESET_S_CODE1_reg                                    (*((volatile unsigned int*)HDMI_P3_PORT3_PRESET_S_CODE1_reg))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_dp_abuf_wr_mod_en_shift                    (23)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_auto_stop_trk_en_shift                     (22)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_trk_mod_en_shift                           (21)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_afsm_mod_en_shift                          (20)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code0_shift                     (15)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code1_shift                     (14)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code2_shift                     (13)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code3_shift                     (12)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code4_shift                     (11)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s1_code4_shift                     (7)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s_code4_shift                      (0)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_dp_abuf_wr_mod_en_mask                     (0x00800000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_auto_stop_trk_en_mask                      (0x00400000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_trk_mod_en_mask                            (0x00200000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_afsm_mod_en_mask                           (0x00100000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code0_mask                      (0x00008000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code1_mask                      (0x00004000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code2_mask                      (0x00002000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code3_mask                      (0x00001000)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code4_mask                      (0x00000800)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s1_code4_mask                      (0x00000080)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s_code4_mask                       (0x0000007F)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_dp_abuf_wr_mod_en(data)                    (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_auto_stop_trk_en(data)                     (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_trk_mod_en(data)                           (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_afsm_mod_en(data)                          (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code0(data)                     (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code1(data)                     (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code2(data)                     (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code3(data)                     (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_sm_code4(data)                     (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s1_code4(data)                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_pre_set_s_code4(data)                      (0x0000007F&(data))
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_dp_abuf_wr_mod_en(data)                ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_auto_stop_trk_en(data)                 ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_trk_mod_en(data)                       ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_afsm_mod_en(data)                      ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_sm_code0(data)                 ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_sm_code1(data)                 ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_sm_code2(data)                 ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_sm_code3(data)                 ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_sm_code4(data)                 ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_s1_code4(data)                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PRESET_S_CODE1_get_pre_set_s_code4(data)                  (0x0000007F&(data))

#define  HDMI_P3_PORT3_PRBS_R_CTRL                                               0x180B2134
#define  HDMI_P3_PORT3_PRBS_R_CTRL_reg_addr                                      "0xB80B2134"
#define  HDMI_P3_PORT3_PRBS_R_CTRL_reg                                           0xB80B2134
#define  HDMI_P3_PORT3_PRBS_R_CTRL_inst_addr                                     "0x004C"
#define  set_HDMI_P3_PORT3_PRBS_R_CTRL_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_R_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_PRBS_R_CTRL_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_R_CTRL_reg))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs23_rxen_shift                             (28)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_rxbist_err_cnt_shift                     (20)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt_shift                            (16)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_bit_err_shift                            (4)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_lock_shift                               (3)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt_clr_shift                        (2)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_reverse_shift                            (1)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs7_rxen_shift                              (0)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs23_rxen_mask                              (0x10000000)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_rxbist_err_cnt_mask                      (0x0FF00000)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt_mask                             (0x000F0000)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_bit_err_mask                             (0x00003FF0)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_lock_mask                                (0x00000008)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt_clr_mask                         (0x00000004)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_reverse_mask                             (0x00000002)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs7_rxen_mask                               (0x00000001)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs23_rxen(data)                             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_rxbist_err_cnt(data)                     (0x0FF00000&((data)<<20))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt(data)                            (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_bit_err(data)                            (0x00003FF0&((data)<<4))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_lock(data)                               (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_err_cnt_clr(data)                        (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs_reverse(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_prbs7_rxen(data)                              (0x00000001&(data))
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs23_rxen(data)                         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_rxbist_err_cnt(data)                 ((0x0FF00000&(data))>>20)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_err_cnt(data)                        ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_bit_err(data)                        ((0x00003FF0&(data))>>4)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_lock(data)                           ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_err_cnt_clr(data)                    ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs_reverse(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PRBS_R_CTRL_get_prbs7_rxen(data)                          (0x00000001&(data))

#define  HDMI_P3_PORT3_PRBS_G_CTRL                                               0x180B2138
#define  HDMI_P3_PORT3_PRBS_G_CTRL_reg_addr                                      "0xB80B2138"
#define  HDMI_P3_PORT3_PRBS_G_CTRL_reg                                           0xB80B2138
#define  HDMI_P3_PORT3_PRBS_G_CTRL_inst_addr                                     "0x004D"
#define  set_HDMI_P3_PORT3_PRBS_G_CTRL_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_G_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_PRBS_G_CTRL_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_G_CTRL_reg))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs23_rxen_shift                             (28)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_rxbist_err_cnt_shift                     (20)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt_shift                            (16)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_bit_err_shift                            (4)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_lock_shift                               (3)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt_clr_shift                        (2)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_reverse_shift                            (1)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs7_rxen_shift                              (0)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs23_rxen_mask                              (0x10000000)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_rxbist_err_cnt_mask                      (0x0FF00000)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt_mask                             (0x000F0000)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_bit_err_mask                             (0x00003FF0)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_lock_mask                                (0x00000008)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt_clr_mask                         (0x00000004)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_reverse_mask                             (0x00000002)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs7_rxen_mask                               (0x00000001)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs23_rxen(data)                             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_rxbist_err_cnt(data)                     (0x0FF00000&((data)<<20))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt(data)                            (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_bit_err(data)                            (0x00003FF0&((data)<<4))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_lock(data)                               (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_err_cnt_clr(data)                        (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs_reverse(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_prbs7_rxen(data)                              (0x00000001&(data))
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs23_rxen(data)                         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_rxbist_err_cnt(data)                 ((0x0FF00000&(data))>>20)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_err_cnt(data)                        ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_bit_err(data)                        ((0x00003FF0&(data))>>4)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_lock(data)                           ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_err_cnt_clr(data)                    ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs_reverse(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PRBS_G_CTRL_get_prbs7_rxen(data)                          (0x00000001&(data))

#define  HDMI_P3_PORT3_PRBS_B_CTRL                                               0x180B213C
#define  HDMI_P3_PORT3_PRBS_B_CTRL_reg_addr                                      "0xB80B213C"
#define  HDMI_P3_PORT3_PRBS_B_CTRL_reg                                           0xB80B213C
#define  HDMI_P3_PORT3_PRBS_B_CTRL_inst_addr                                     "0x004E"
#define  set_HDMI_P3_PORT3_PRBS_B_CTRL_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_B_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_PRBS_B_CTRL_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_PRBS_B_CTRL_reg))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs23_rxen_shift                             (28)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_rxbist_err_cnt_shift                     (20)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt_shift                            (16)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_bit_err_shift                            (4)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_lock_shift                               (3)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt_clr_shift                        (2)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_reverse_shift                            (1)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs7_rxen_shift                              (0)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs23_rxen_mask                              (0x10000000)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_rxbist_err_cnt_mask                      (0x0FF00000)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt_mask                             (0x000F0000)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_bit_err_mask                             (0x00003FF0)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_lock_mask                                (0x00000008)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt_clr_mask                         (0x00000004)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_reverse_mask                             (0x00000002)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs7_rxen_mask                               (0x00000001)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs23_rxen(data)                             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_rxbist_err_cnt(data)                     (0x0FF00000&((data)<<20))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt(data)                            (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_bit_err(data)                            (0x00003FF0&((data)<<4))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_lock(data)                               (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_err_cnt_clr(data)                        (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs_reverse(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_prbs7_rxen(data)                              (0x00000001&(data))
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs23_rxen(data)                         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_rxbist_err_cnt(data)                 ((0x0FF00000&(data))>>20)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_err_cnt(data)                        ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_bit_err(data)                        ((0x00003FF0&(data))>>4)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_lock(data)                           ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_err_cnt_clr(data)                    ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs_reverse(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PRBS_B_CTRL_get_prbs7_rxen(data)                          (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl                                  0x180B2140
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg_addr                         "0xB80B2140"
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg                              0xB80B2140
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_inst_addr                        "0x004F"
#define  set_HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg(data)                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_reg))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_flag_shift               (30)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_wd_en_shift              (29)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_int_en_shift             (28)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_preamble_shift                   (24)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_value_shift                  (8)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_dvi_mode_sel_shift               (4)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_channel_sel_shift                (2)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_conti_shift              (1)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_en_shift                 (0)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_flag_mask                (0x40000000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_wd_en_mask               (0x20000000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_int_en_mask              (0x10000000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_preamble_mask                    (0x0F000000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_value_mask                   (0x0003FF00)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_dvi_mode_sel_mask                (0x00000010)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_channel_sel_mask                 (0x0000000C)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_conti_mask               (0x00000002)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_en_mask                  (0x00000001)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_flag(data)               (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_wd_en(data)              (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_err_int_en(data)             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_preamble(data)                   (0x0F000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_cmp_value(data)                  (0x0003FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_dvi_mode_sel(data)               (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_channel_sel(data)                (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_conti(data)              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_lgb_cal_en(data)                 (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_cmp_err_flag(data)           ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_cmp_err_wd_en(data)          ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_cmp_err_int_en(data)         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_preamble(data)               ((0x0F000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_cmp_value(data)              ((0x0003FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_dvi_mode_sel(data)           ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_channel_sel(data)            ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_lgb_cal_conti(data)          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_ctrl_get_lgb_cal_en(data)             (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times                                 0x180B2144
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg_addr                        "0xB80B2144"
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg                             0xB80B2144
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_inst_addr                       "0x0050"
#define  set_HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg(data)                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_reg))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_err_cnt_shift               (16)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_times_shift                 (0)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_err_cnt_mask                (0xFFFF0000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_times_mask                  (0x0000FFFF)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_err_cnt(data)               (0xFFFF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_cmp_times(data)                 (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_get_cmp_err_cnt(data)           ((0xFFFF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_times_get_cmp_times(data)             (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt                                   0x180B2148
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg_addr                          "0xB80B2148"
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg                               0xB80B2148
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_inst_addr                         "0x0051"
#define  set_HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg(data)                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_reg))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt_shift            (16)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt_by_frame_shift   (0)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt_mask             (0xFFFF0000)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt_by_frame_mask    (0x0000FFFF)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt(data)            (0xFFFF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_preamble_cmp_cnt_by_frame(data)   (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_get_preamble_cmp_cnt(data)        ((0xFFFF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_leading_GB_cmp_cnt_get_preamble_cmp_cnt_by_frame(data) (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND                                        0x180B214C
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg_addr                               "0xB80B214C"
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg                                    0xB80B214C
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_inst_addr                              "0x0052"
#define  set_HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg)=data)
#define  get_HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_reg))
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_over_flag_shift                    (31)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_clip_en_shift                      (20)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_up_bound_shift                     (0)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_over_flag_mask                     (0x80000000)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_clip_en_mask                       (0x00100000)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_up_bound_mask                      (0x000FFFFF)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_over_flag(data)                    (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_clip_en(data)                      (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_cts_up_bound(data)                     (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_get_cts_over_flag(data)                ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_get_cts_clip_en(data)                  ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_AUDIO_CTS_UP_BOUND_get_cts_up_bound(data)                 (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND                                       0x180B2150
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg_addr                              "0xB80B2150"
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg                                   0xB80B2150
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_inst_addr                             "0x0053"
#define  set_HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg(data)                         (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg)=data)
#define  get_HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg                               (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_reg))
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_under_flag_shift                  (31)
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_low_bound_shift                   (0)
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_under_flag_mask                   (0x80000000)
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_low_bound_mask                    (0x000FFFFF)
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_under_flag(data)                  (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_cts_low_bound(data)                   (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_get_cts_under_flag(data)              ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_AUDIO_CTS_LOW_BOUND_get_cts_low_bound(data)               (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND                                          0x180B2154
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg_addr                                 "0xB80B2154"
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg                                      0xB80B2154
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_inst_addr                                "0x0054"
#define  set_HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg(data)                            (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg)=data)
#define  get_HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg                                  (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_N_UP_BOUND_reg))
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_over_flag_shift                        (31)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_clip_en_shift                          (20)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_up_bound_shift                         (0)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_over_flag_mask                         (0x80000000)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_clip_en_mask                           (0x00100000)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_up_bound_mask                          (0x000FFFFF)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_over_flag(data)                        (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_clip_en(data)                          (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_n_up_bound(data)                         (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_get_n_over_flag(data)                    ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_get_n_clip_en(data)                      ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_AUDIO_N_UP_BOUND_get_n_up_bound(data)                     (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND                                         0x180B2158
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg_addr                                "0xB80B2158"
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg                                     0xB80B2158
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_inst_addr                               "0x0055"
#define  set_HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg(data)                           (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg)=data)
#define  get_HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg                                 (*((volatile unsigned int*)HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_reg))
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_under_flag_shift                      (31)
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_low_bound_shift                       (0)
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_under_flag_mask                       (0x80000000)
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_low_bound_mask                        (0x000FFFFF)
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_under_flag(data)                      (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_n_low_bound(data)                       (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_get_n_under_flag(data)                  ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_AUDIO_N_LOW_BOUND_get_n_low_bound(data)                   (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL                                         0x180B215C
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg_addr                                "0xB80B215C"
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg                                     0xB80B215C
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_inst_addr                               "0x0056"
#define  set_HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg(data)                           (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg                                 (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_reg))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_hporch_offset_shift                     (16)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_dummy_15_14_shift                       (14)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_en_packet_retiming_vsrst_shift          (13)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_pp_mode_output_shift                    (12)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_packet_mhl_en_shift                     (8)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_xor_pixel_sel_shift                     (5)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_cal_pixel_sel_shift                     (4)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_shift                 (0)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_hporch_offset_mask                      (0x03FF0000)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_dummy_15_14_mask                        (0x0000C000)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_en_packet_retiming_vsrst_mask           (0x00002000)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_pp_mode_output_mask                     (0x00001000)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask                      (0x00000100)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask                      (0x000000E0)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_cal_pixel_sel_mask                      (0x00000010)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask                  (0x00000001)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_hporch_offset(data)                     (0x03FF0000&((data)<<16))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_dummy_15_14(data)                       (0x0000C000&((data)<<14))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_en_packet_retiming_vsrst(data)          (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_pp_mode_output(data)                    (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_packet_mhl_en(data)                     (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_xor_pixel_sel(data)                     (0x000000E0&((data)<<5))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_cal_pixel_sel(data)                     (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en(data)                 (0x00000001&(data))
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_hporch_offset(data)                 ((0x03FF0000&(data))>>16)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_dummy_15_14(data)                   ((0x0000C000&(data))>>14)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_en_packet_retiming_vsrst(data)      ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_pp_mode_output(data)                ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_packet_mhl_en(data)                 ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_xor_pixel_sel(data)                 ((0x000000E0&(data))>>5)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_cal_pixel_sel(data)                 ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_MHL_HDMI_MAC_CTRL_get_ch_dec_pp_mode_en(data)             (0x00000001&(data))

#define  HDMI_P3_PORT3_MHL_3D_FORMAT                                             0x180B2160
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_reg_addr                                    "0xB80B2160"
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_reg                                         0xB80B2160
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_inst_addr                                   "0x0057"
#define  set_HDMI_P3_PORT3_MHL_3D_FORMAT_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3D_FORMAT_reg)=data)
#define  get_HDMI_P3_PORT3_MHL_3D_FORMAT_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3D_FORMAT_reg))
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_3d_fmt_shift                            (26)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_vid_shift                               (24)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_oui_shift                                   (0)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_3d_fmt_mask                             (0x3C000000)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_vid_mask                                (0x03000000)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_oui_mask                                    (0x00FFFFFF)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_3d_fmt(data)                            (0x3C000000&((data)<<26))
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_mhl_vid(data)                               (0x03000000&((data)<<24))
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_oui(data)                                   (0x00FFFFFF&(data))
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_get_mhl_3d_fmt(data)                        ((0x3C000000&(data))>>26)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_get_mhl_vid(data)                           ((0x03000000&(data))>>24)
#define  HDMI_P3_PORT3_MHL_3D_FORMAT_get_oui(data)                               (0x00FFFFFF&(data))

#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0                                           0x180B2164
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg_addr                                  "0xB80B2164"
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg                                       0xB80B2164
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_inst_addr                                 "0x0058"
#define  set_HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg(data)                             (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg)=data)
#define  get_HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg                                   (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3p0_FORMAT0_reg))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt_shift                         (17)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_sep_aud_shift                             (16)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt_type_shift                    (0)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt_mask                          (0x00060000)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_sep_aud_mask                              (0x00010000)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt_type_mask                     (0x0000FFFF)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt(data)                         (0x00060000&((data)<<17))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_sep_aud(data)                             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_mhl_hev_fmt_type(data)                    (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_get_mhl_hev_fmt(data)                     ((0x00060000&(data))>>17)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_get_sep_aud(data)                         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT0_get_mhl_hev_fmt_type(data)                (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1                                           0x180B2168
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg_addr                                  "0xB80B2168"
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg                                       0xB80B2168
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_inst_addr                                 "0x0059"
#define  set_HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg(data)                             (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg)=data)
#define  get_HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg                                   (*((volatile unsigned int*)HDMI_P3_PORT3_MHL_3p0_FORMAT1_reg))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_acrfs_div_shift                           (21)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_dir_shift                        (20)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_sync_shift                       (0)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_acrfs_div_mask                            (0x00E00000)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_dir_mask                         (0x00100000)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_sync_mask                        (0x000FFFFF)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_acrfs_div(data)                           (0x00E00000&((data)<<21))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_dir(data)                        (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_av_delay_sync(data)                       (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_get_acrfs_div(data)                       ((0x00E00000&(data))>>21)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_get_av_delay_dir(data)                    ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_MHL_3p0_FORMAT1_get_av_delay_sync(data)                   (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_LIGHT_SLEEP                                               0x180B216C
#define  HDMI_P3_PORT3_LIGHT_SLEEP_reg_addr                                      "0xB80B216C"
#define  HDMI_P3_PORT3_LIGHT_SLEEP_reg                                           0xB80B216C
#define  HDMI_P3_PORT3_LIGHT_SLEEP_inst_addr                                     "0x005A"
#define  set_HDMI_P3_PORT3_LIGHT_SLEEP_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_LIGHT_SLEEP_reg)=data)
#define  get_HDMI_P3_PORT3_LIGHT_SLEEP_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_LIGHT_SLEEP_reg))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls3_shift                              (8)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls2_shift                              (7)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls1_shift                              (6)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls0_shift                              (5)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls1_shift                            (4)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls0_shift                            (3)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ksvfifo_ls_shift                         (2)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ls_shift                                 (1)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_audio_ls_shift                                (0)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls3_mask                               (0x00000100)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls2_mask                               (0x00000080)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls1_mask                               (0x00000040)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls0_mask                               (0x00000020)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls1_mask                             (0x00000010)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls0_mask                             (0x00000008)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ksvfifo_ls_mask                          (0x00000004)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ls_mask                                  (0x00000002)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_audio_ls_mask                                 (0x00000001)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls3(data)                              (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls2(data)                              (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls1(data)                              (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_yuv420_ls0(data)                              (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls1(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_2p2_ls0(data)                            (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ksvfifo_ls(data)                         (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_hdcp_ls(data)                                 (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_audio_ls(data)                                (0x00000001&(data))
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_yuv420_ls3(data)                          ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_yuv420_ls2(data)                          ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_yuv420_ls1(data)                          ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_yuv420_ls0(data)                          ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_hdcp_2p2_ls1(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_hdcp_2p2_ls0(data)                        ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_hdcp_ksvfifo_ls(data)                     ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_hdcp_ls(data)                             ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_LIGHT_SLEEP_get_audio_ls(data)                            (0x00000001&(data))

#define  HDMI_P3_PORT3_READ_MARGIN2                                              0x180B2170
#define  HDMI_P3_PORT3_READ_MARGIN2_reg_addr                                     "0xB80B2170"
#define  HDMI_P3_PORT3_READ_MARGIN2_reg                                          0xB80B2170
#define  HDMI_P3_PORT3_READ_MARGIN2_inst_addr                                    "0x005B"
#define  set_HDMI_P3_PORT3_READ_MARGIN2_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN2_reg)=data)
#define  get_HDMI_P3_PORT3_READ_MARGIN2_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN2_reg))
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm3_shift                             (12)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm2_shift                             (8)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm1_shift                             (4)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm0_shift                             (0)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm3_mask                              (0x0000F000)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm2_mask                              (0x00000F00)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm1_mask                              (0x000000F0)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm0_mask                              (0x0000000F)
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm3(data)                             (0x0000F000&((data)<<12))
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm2(data)                             (0x00000F00&((data)<<8))
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm1(data)                             (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_READ_MARGIN2_yuv420_rm0(data)                             (0x0000000F&(data))
#define  HDMI_P3_PORT3_READ_MARGIN2_get_yuv420_rm3(data)                         ((0x0000F000&(data))>>12)
#define  HDMI_P3_PORT3_READ_MARGIN2_get_yuv420_rm2(data)                         ((0x00000F00&(data))>>8)
#define  HDMI_P3_PORT3_READ_MARGIN2_get_yuv420_rm1(data)                         ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_READ_MARGIN2_get_yuv420_rm0(data)                         (0x0000000F&(data))

#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE                                        0x180B2174
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg_addr                               "0xB80B2174"
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg                                    0xB80B2174
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_inst_addr                              "0x005C"
#define  set_HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg)=data)
#define  get_HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN_ENABLE_reg))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme3_shift                      (8)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme2_shift                      (7)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme1_shift                      (6)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme0_shift                      (5)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme1_shift                    (4)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme0_shift                    (3)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_ksvfifo_rme_shift                 (2)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_rme_shift                         (1)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_audio_rme_shift                        (0)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme3_mask                       (0x00000100)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme2_mask                       (0x00000080)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme1_mask                       (0x00000040)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme0_mask                       (0x00000020)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme1_mask                     (0x00000010)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme0_mask                     (0x00000008)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_ksvfifo_rme_mask                  (0x00000004)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_rme_mask                          (0x00000002)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_audio_rme_mask                         (0x00000001)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme3(data)                      (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme2(data)                      (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme1(data)                      (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_yuv420_rme0(data)                      (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme1(data)                    (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_2p2_rme0(data)                    (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_ksvfifo_rme(data)                 (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_hdcp_rme(data)                         (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_audio_rme(data)                        (0x00000001&(data))
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_yuv420_rme3(data)                  ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_yuv420_rme2(data)                  ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_yuv420_rme1(data)                  ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_yuv420_rme0(data)                  ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_hdcp_2p2_rme1(data)                ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_hdcp_2p2_rme0(data)                ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_hdcp_ksvfifo_rme(data)             ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_hdcp_rme(data)                     ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_READ_MARGIN_ENABLE_get_audio_rme(data)                    (0x00000001&(data))

#define  HDMI_P3_PORT3_READ_MARGIN                                               0x180B2178
#define  HDMI_P3_PORT3_READ_MARGIN_reg_addr                                      "0xB80B2178"
#define  HDMI_P3_PORT3_READ_MARGIN_reg                                           0xB80B2178
#define  HDMI_P3_PORT3_READ_MARGIN_inst_addr                                     "0x005D"
#define  set_HDMI_P3_PORT3_READ_MARGIN_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN_reg)=data)
#define  get_HDMI_P3_PORT3_READ_MARGIN_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_READ_MARGIN_reg))
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm1_shift                            (16)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm0_shift                            (12)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_ksvfifo_rm_shift                         (8)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_rm_shift                                 (4)
#define  HDMI_P3_PORT3_READ_MARGIN_audio_rm_shift                                (0)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm1_mask                             (0x000F0000)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm0_mask                             (0x0000F000)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_ksvfifo_rm_mask                          (0x00000F00)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_rm_mask                                  (0x000000F0)
#define  HDMI_P3_PORT3_READ_MARGIN_audio_rm_mask                                 (0x0000000F)
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm1(data)                            (0x000F0000&((data)<<16))
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_2p2_rm0(data)                            (0x0000F000&((data)<<12))
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_ksvfifo_rm(data)                         (0x00000F00&((data)<<8))
#define  HDMI_P3_PORT3_READ_MARGIN_hdcp_rm(data)                                 (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_READ_MARGIN_audio_rm(data)                                (0x0000000F&(data))
#define  HDMI_P3_PORT3_READ_MARGIN_get_hdcp_2p2_rm1(data)                        ((0x000F0000&(data))>>16)
#define  HDMI_P3_PORT3_READ_MARGIN_get_hdcp_2p2_rm0(data)                        ((0x0000F000&(data))>>12)
#define  HDMI_P3_PORT3_READ_MARGIN_get_hdcp_ksvfifo_rm(data)                     ((0x00000F00&(data))>>8)
#define  HDMI_P3_PORT3_READ_MARGIN_get_hdcp_rm(data)                             ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_READ_MARGIN_get_audio_rm(data)                            (0x0000000F&(data))

#define  HDMI_P3_PORT3_BIST_MODE                                                 0x180B217C
#define  HDMI_P3_PORT3_BIST_MODE_reg_addr                                        "0xB80B217C"
#define  HDMI_P3_PORT3_BIST_MODE_reg                                             0xB80B217C
#define  HDMI_P3_PORT3_BIST_MODE_inst_addr                                       "0x005E"
#define  set_HDMI_P3_PORT3_BIST_MODE_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_MODE_reg)=data)
#define  get_HDMI_P3_PORT3_BIST_MODE_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_MODE_reg))
#define  HDMI_P3_PORT3_BIST_MODE_yuv420_bist_en_shift                            (4)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_2p2_bist_en_shift                          (3)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_ksvfifo_bist_en_shift                      (2)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_bist_en_shift                              (1)
#define  HDMI_P3_PORT3_BIST_MODE_audio_bist_en_shift                             (0)
#define  HDMI_P3_PORT3_BIST_MODE_yuv420_bist_en_mask                             (0x00000010)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_2p2_bist_en_mask                           (0x00000008)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_ksvfifo_bist_en_mask                       (0x00000004)
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_bist_en_mask                               (0x00000002)
#define  HDMI_P3_PORT3_BIST_MODE_audio_bist_en_mask                              (0x00000001)
#define  HDMI_P3_PORT3_BIST_MODE_yuv420_bist_en(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_2p2_bist_en(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_ksvfifo_bist_en(data)                      (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_BIST_MODE_hdcp_bist_en(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_BIST_MODE_audio_bist_en(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_BIST_MODE_get_yuv420_bist_en(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_BIST_MODE_get_hdcp_2p2_bist_en(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_BIST_MODE_get_hdcp_ksvfifo_bist_en(data)                  ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_BIST_MODE_get_hdcp_bist_en(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_BIST_MODE_get_audio_bist_en(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_BIST_DONE                                                 0x180B2180
#define  HDMI_P3_PORT3_BIST_DONE_reg_addr                                        "0xB80B2180"
#define  HDMI_P3_PORT3_BIST_DONE_reg                                             0xB80B2180
#define  HDMI_P3_PORT3_BIST_DONE_inst_addr                                       "0x005F"
#define  set_HDMI_P3_PORT3_BIST_DONE_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_DONE_reg)=data)
#define  get_HDMI_P3_PORT3_BIST_DONE_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_DONE_reg))
#define  HDMI_P3_PORT3_BIST_DONE_yuv420_bist_done_shift                          (4)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_2p2_bist_done_shift                        (3)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_ksvfifo_bist_done_shift                    (2)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_bist_done_shift                            (1)
#define  HDMI_P3_PORT3_BIST_DONE_audio_bist_done_shift                           (0)
#define  HDMI_P3_PORT3_BIST_DONE_yuv420_bist_done_mask                           (0x00000010)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_2p2_bist_done_mask                         (0x00000008)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_ksvfifo_bist_done_mask                     (0x00000004)
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_bist_done_mask                             (0x00000002)
#define  HDMI_P3_PORT3_BIST_DONE_audio_bist_done_mask                            (0x00000001)
#define  HDMI_P3_PORT3_BIST_DONE_yuv420_bist_done(data)                          (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_2p2_bist_done(data)                        (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_ksvfifo_bist_done(data)                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_BIST_DONE_hdcp_bist_done(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_BIST_DONE_audio_bist_done(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_BIST_DONE_get_yuv420_bist_done(data)                      ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_BIST_DONE_get_hdcp_2p2_bist_done(data)                    ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_BIST_DONE_get_hdcp_ksvfifo_bist_done(data)                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_BIST_DONE_get_hdcp_bist_done(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_BIST_DONE_get_audio_bist_done(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_BIST_FAIL                                                 0x180B2184
#define  HDMI_P3_PORT3_BIST_FAIL_reg_addr                                        "0xB80B2184"
#define  HDMI_P3_PORT3_BIST_FAIL_reg                                             0xB80B2184
#define  HDMI_P3_PORT3_BIST_FAIL_inst_addr                                       "0x0060"
#define  set_HDMI_P3_PORT3_BIST_FAIL_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_FAIL_reg)=data)
#define  get_HDMI_P3_PORT3_BIST_FAIL_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_BIST_FAIL_reg))
#define  HDMI_P3_PORT3_BIST_FAIL_yuv420_bist_fail_shift                          (4)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_2p2_bist_fail_shift                        (3)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_ksvfifo_bist_fail_shift                    (2)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_bist_fail_shift                            (1)
#define  HDMI_P3_PORT3_BIST_FAIL_audio_bist_fail_shift                           (0)
#define  HDMI_P3_PORT3_BIST_FAIL_yuv420_bist_fail_mask                           (0x00000010)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_2p2_bist_fail_mask                         (0x00000008)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_ksvfifo_bist_fail_mask                     (0x00000004)
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_bist_fail_mask                             (0x00000002)
#define  HDMI_P3_PORT3_BIST_FAIL_audio_bist_fail_mask                            (0x00000001)
#define  HDMI_P3_PORT3_BIST_FAIL_yuv420_bist_fail(data)                          (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_2p2_bist_fail(data)                        (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_ksvfifo_bist_fail(data)                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_BIST_FAIL_hdcp_bist_fail(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_BIST_FAIL_audio_bist_fail(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_BIST_FAIL_get_yuv420_bist_fail(data)                      ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_BIST_FAIL_get_hdcp_2p2_bist_fail(data)                    ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_BIST_FAIL_get_hdcp_ksvfifo_bist_fail(data)                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_BIST_FAIL_get_hdcp_bist_fail(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_BIST_FAIL_get_audio_bist_fail(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_DRF_MODE                                                  0x180B2188
#define  HDMI_P3_PORT3_DRF_MODE_reg_addr                                         "0xB80B2188"
#define  HDMI_P3_PORT3_DRF_MODE_reg                                              0xB80B2188
#define  HDMI_P3_PORT3_DRF_MODE_inst_addr                                        "0x0061"
#define  set_HDMI_P3_PORT3_DRF_MODE_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_MODE_reg)=data)
#define  get_HDMI_P3_PORT3_DRF_MODE_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_MODE_reg))
#define  HDMI_P3_PORT3_DRF_MODE_yuv420_drf_mode_shift                            (4)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_2p2_drf_mode_shift                          (3)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_ksvfifo_drf_mode_shift                      (2)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_drf_mode_shift                              (1)
#define  HDMI_P3_PORT3_DRF_MODE_audio_drf_mode_shift                             (0)
#define  HDMI_P3_PORT3_DRF_MODE_yuv420_drf_mode_mask                             (0x00000010)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_2p2_drf_mode_mask                           (0x00000008)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_ksvfifo_drf_mode_mask                       (0x00000004)
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_drf_mode_mask                               (0x00000002)
#define  HDMI_P3_PORT3_DRF_MODE_audio_drf_mode_mask                              (0x00000001)
#define  HDMI_P3_PORT3_DRF_MODE_yuv420_drf_mode(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_2p2_drf_mode(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_ksvfifo_drf_mode(data)                      (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_DRF_MODE_hdcp_drf_mode(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_DRF_MODE_audio_drf_mode(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_DRF_MODE_get_yuv420_drf_mode(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_DRF_MODE_get_hdcp_2p2_drf_mode(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_DRF_MODE_get_hdcp_ksvfifo_drf_mode(data)                  ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_DRF_MODE_get_hdcp_drf_mode(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_DRF_MODE_get_audio_drf_mode(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_DRF_RESUME                                                0x180B218C
#define  HDMI_P3_PORT3_DRF_RESUME_reg_addr                                       "0xB80B218C"
#define  HDMI_P3_PORT3_DRF_RESUME_reg                                            0xB80B218C
#define  HDMI_P3_PORT3_DRF_RESUME_inst_addr                                      "0x0062"
#define  set_HDMI_P3_PORT3_DRF_RESUME_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_RESUME_reg)=data)
#define  get_HDMI_P3_PORT3_DRF_RESUME_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_RESUME_reg))
#define  HDMI_P3_PORT3_DRF_RESUME_yuv420_drf_resume_shift                        (4)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_2p2_drf_resume_shift                      (3)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_ksvfifo_drf_resume_shift                  (2)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_drf_resume_shift                          (1)
#define  HDMI_P3_PORT3_DRF_RESUME_audio_drf_resume_shift                         (0)
#define  HDMI_P3_PORT3_DRF_RESUME_yuv420_drf_resume_mask                         (0x00000010)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_2p2_drf_resume_mask                       (0x00000008)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_ksvfifo_drf_resume_mask                   (0x00000004)
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_drf_resume_mask                           (0x00000002)
#define  HDMI_P3_PORT3_DRF_RESUME_audio_drf_resume_mask                          (0x00000001)
#define  HDMI_P3_PORT3_DRF_RESUME_yuv420_drf_resume(data)                        (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_2p2_drf_resume(data)                      (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_ksvfifo_drf_resume(data)                  (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_DRF_RESUME_hdcp_drf_resume(data)                          (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_DRF_RESUME_audio_drf_resume(data)                         (0x00000001&(data))
#define  HDMI_P3_PORT3_DRF_RESUME_get_yuv420_drf_resume(data)                    ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_DRF_RESUME_get_hdcp_2p2_drf_resume(data)                  ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_DRF_RESUME_get_hdcp_ksvfifo_drf_resume(data)              ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_DRF_RESUME_get_hdcp_drf_resume(data)                      ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_DRF_RESUME_get_audio_drf_resume(data)                     (0x00000001&(data))

#define  HDMI_P3_PORT3_DRF_DONE                                                  0x180B2190
#define  HDMI_P3_PORT3_DRF_DONE_reg_addr                                         "0xB80B2190"
#define  HDMI_P3_PORT3_DRF_DONE_reg                                              0xB80B2190
#define  HDMI_P3_PORT3_DRF_DONE_inst_addr                                        "0x0063"
#define  set_HDMI_P3_PORT3_DRF_DONE_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_DONE_reg)=data)
#define  get_HDMI_P3_PORT3_DRF_DONE_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_DONE_reg))
#define  HDMI_P3_PORT3_DRF_DONE_yuv420_drf_done_shift                            (4)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_2p2_drf_done_shift                          (3)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_ksvfifo_drf_done_shift                      (2)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_drf_done_shift                              (1)
#define  HDMI_P3_PORT3_DRF_DONE_audio_drf_done_shift                             (0)
#define  HDMI_P3_PORT3_DRF_DONE_yuv420_drf_done_mask                             (0x00000010)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_2p2_drf_done_mask                           (0x00000008)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_ksvfifo_drf_done_mask                       (0x00000004)
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_drf_done_mask                               (0x00000002)
#define  HDMI_P3_PORT3_DRF_DONE_audio_drf_done_mask                              (0x00000001)
#define  HDMI_P3_PORT3_DRF_DONE_yuv420_drf_done(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_2p2_drf_done(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_ksvfifo_drf_done(data)                      (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_DRF_DONE_hdcp_drf_done(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_DRF_DONE_audio_drf_done(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_DRF_DONE_get_yuv420_drf_done(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_DRF_DONE_get_hdcp_2p2_drf_done(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_DRF_DONE_get_hdcp_ksvfifo_drf_done(data)                  ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_DRF_DONE_get_hdcp_drf_done(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_DRF_DONE_get_audio_drf_done(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_DRF_PAUSE                                                 0x180B2194
#define  HDMI_P3_PORT3_DRF_PAUSE_reg_addr                                        "0xB80B2194"
#define  HDMI_P3_PORT3_DRF_PAUSE_reg                                             0xB80B2194
#define  HDMI_P3_PORT3_DRF_PAUSE_inst_addr                                       "0x0064"
#define  set_HDMI_P3_PORT3_DRF_PAUSE_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_PAUSE_reg)=data)
#define  get_HDMI_P3_PORT3_DRF_PAUSE_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_PAUSE_reg))
#define  HDMI_P3_PORT3_DRF_PAUSE_yuv420_drf_pause_shift                          (4)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_2p2_drf_pause_shift                        (3)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_ksvfifo_drf_pause_shift                    (2)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_drf_pause_shift                            (1)
#define  HDMI_P3_PORT3_DRF_PAUSE_audio_drf_pause_shift                           (0)
#define  HDMI_P3_PORT3_DRF_PAUSE_yuv420_drf_pause_mask                           (0x00000010)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_2p2_drf_pause_mask                         (0x00000008)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_ksvfifo_drf_pause_mask                     (0x00000004)
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_drf_pause_mask                             (0x00000002)
#define  HDMI_P3_PORT3_DRF_PAUSE_audio_drf_pause_mask                            (0x00000001)
#define  HDMI_P3_PORT3_DRF_PAUSE_yuv420_drf_pause(data)                          (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_2p2_drf_pause(data)                        (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_ksvfifo_drf_pause(data)                    (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_DRF_PAUSE_hdcp_drf_pause(data)                            (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_DRF_PAUSE_audio_drf_pause(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_DRF_PAUSE_get_yuv420_drf_pause(data)                      ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_DRF_PAUSE_get_hdcp_2p2_drf_pause(data)                    ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_DRF_PAUSE_get_hdcp_ksvfifo_drf_pause(data)                ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_DRF_PAUSE_get_hdcp_drf_pause(data)                        ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_DRF_PAUSE_get_audio_drf_pause(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_DRF_FAIL                                                  0x180B2198
#define  HDMI_P3_PORT3_DRF_FAIL_reg_addr                                         "0xB80B2198"
#define  HDMI_P3_PORT3_DRF_FAIL_reg                                              0xB80B2198
#define  HDMI_P3_PORT3_DRF_FAIL_inst_addr                                        "0x0065"
#define  set_HDMI_P3_PORT3_DRF_FAIL_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_FAIL_reg)=data)
#define  get_HDMI_P3_PORT3_DRF_FAIL_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_DRF_FAIL_reg))
#define  HDMI_P3_PORT3_DRF_FAIL_yuv420_drf_fail_shift                            (4)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_2p2_drf_fail_shift                          (3)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_ksvfifo_drf_fail_shift                      (2)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_drf_fail_shift                              (1)
#define  HDMI_P3_PORT3_DRF_FAIL_audio_drf_fail_shift                             (0)
#define  HDMI_P3_PORT3_DRF_FAIL_yuv420_drf_fail_mask                             (0x00000010)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_2p2_drf_fail_mask                           (0x00000008)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_ksvfifo_drf_fail_mask                       (0x00000004)
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_drf_fail_mask                               (0x00000002)
#define  HDMI_P3_PORT3_DRF_FAIL_audio_drf_fail_mask                              (0x00000001)
#define  HDMI_P3_PORT3_DRF_FAIL_yuv420_drf_fail(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_2p2_drf_fail(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_ksvfifo_drf_fail(data)                      (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_DRF_FAIL_hdcp_drf_fail(data)                              (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_DRF_FAIL_audio_drf_fail(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_DRF_FAIL_get_yuv420_drf_fail(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_DRF_FAIL_get_hdcp_2p2_drf_fail(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_DRF_FAIL_get_hdcp_ksvfifo_drf_fail(data)                  ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_DRF_FAIL_get_hdcp_drf_fail(data)                          ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_DRF_FAIL_get_audio_drf_fail(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_PHY_FIFO_CR0                                              0x180B219C
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_reg_addr                                     "0xB80B219C"
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_reg                                          0xB80B219C
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_inst_addr                                    "0x0066"
#define  set_HDMI_P3_PORT3_PHY_FIFO_CR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_CR0_reg)=data)
#define  get_HDMI_P3_PORT3_PHY_FIFO_CR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_CR0_reg))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_flush_shift                          (26)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_afifo_en_shift                       (25)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_flush_shift                          (24)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_afifo_en_shift                       (23)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_flush_shift                          (22)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_afifo_en_shift                       (21)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_20_shift                               (20)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_flush_shift                          (19)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_afifo_en_shift                       (18)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_flush_shift                          (17)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_afifo_en_shift                       (16)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_flush_shift                          (15)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_afifo_en_shift                       (14)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_13_shift                               (13)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_flush_shift                          (12)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_afifo_en_shift                       (11)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_flush_shift                          (10)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_afifo_en_shift                       (9)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_flush_shift                          (8)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_afifo_en_shift                       (7)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_6_shift                                (6)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_flush_shift                          (5)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_afifo_en_shift                       (4)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_flush_shift                          (3)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_afifo_en_shift                       (2)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_flush_shift                          (1)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_afifo_en_shift                       (0)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_flush_mask                           (0x04000000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_afifo_en_mask                        (0x02000000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_flush_mask                           (0x01000000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_afifo_en_mask                        (0x00800000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_flush_mask                           (0x00400000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_afifo_en_mask                        (0x00200000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_20_mask                                (0x00100000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_flush_mask                           (0x00080000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_afifo_en_mask                        (0x00040000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_flush_mask                           (0x00020000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_afifo_en_mask                        (0x00010000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_flush_mask                           (0x00008000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_afifo_en_mask                        (0x00004000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_13_mask                                (0x00002000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_flush_mask                           (0x00001000)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_afifo_en_mask                        (0x00000800)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_flush_mask                           (0x00000400)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_afifo_en_mask                        (0x00000200)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_flush_mask                           (0x00000100)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_afifo_en_mask                        (0x00000080)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_6_mask                                 (0x00000040)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_flush_mask                           (0x00000020)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_afifo_en_mask                        (0x00000010)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_flush_mask                           (0x00000008)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_afifo_en_mask                        (0x00000004)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_flush_mask                           (0x00000002)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_afifo_en_mask                        (0x00000001)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_flush(data)                          (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_r_afifo_en(data)                       (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_flush(data)                          (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_g_afifo_en(data)                       (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_flush(data)                          (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port3_b_afifo_en(data)                       (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_20(data)                               (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_flush(data)                          (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_r_afifo_en(data)                       (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_flush(data)                          (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_g_afifo_en(data)                       (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_flush(data)                          (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port2_b_afifo_en(data)                       (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_13(data)                               (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_flush(data)                          (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_r_afifo_en(data)                       (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_flush(data)                          (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_g_afifo_en(data)                       (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_flush(data)                          (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port1_b_afifo_en(data)                       (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_dummy_6(data)                                (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_flush(data)                          (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_r_afifo_en(data)                       (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_flush(data)                          (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_g_afifo_en(data)                       (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_flush(data)                          (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_port0_b_afifo_en(data)                       (0x00000001&(data))
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_r_flush(data)                      ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_r_afifo_en(data)                   ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_g_flush(data)                      ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_g_afifo_en(data)                   ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_b_flush(data)                      ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port3_b_afifo_en(data)                   ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_dummy_20(data)                           ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_r_flush(data)                      ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_r_afifo_en(data)                   ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_g_flush(data)                      ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_g_afifo_en(data)                   ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_b_flush(data)                      ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port2_b_afifo_en(data)                   ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_dummy_13(data)                           ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_r_flush(data)                      ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_r_afifo_en(data)                   ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_g_flush(data)                      ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_g_afifo_en(data)                   ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_b_flush(data)                      ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port1_b_afifo_en(data)                   ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_dummy_6(data)                            ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_r_flush(data)                      ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_r_afifo_en(data)                   ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_g_flush(data)                      ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_g_afifo_en(data)                   ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_b_flush(data)                      ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PHY_FIFO_CR0_get_port0_b_afifo_en(data)                   (0x00000001&(data))

#define  HDMI_P3_PORT3_PHY_FIFO_CR1                                              0x180B21A0
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_reg_addr                                     "0xB80B21A0"
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_reg                                          0xB80B21A0
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_inst_addr                                    "0x0067"
#define  set_HDMI_P3_PORT3_PHY_FIFO_CR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_CR1_reg)=data)
#define  get_HDMI_P3_PORT3_PHY_FIFO_CR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_CR1_reg))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_rclk_inv_shift                         (11)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_gclk_inv_shift                         (10)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_bclk_inv_shift                         (9)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_rclk_inv_shift                         (8)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_gclk_inv_shift                         (7)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_bclk_inv_shift                         (6)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_rclk_inv_shift                         (5)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_gclk_inv_shift                         (4)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_bclk_inv_shift                         (3)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_rclk_inv_shift                         (2)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_gclk_inv_shift                         (1)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_bclk_inv_shift                         (0)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_rclk_inv_mask                          (0x00000800)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_gclk_inv_mask                          (0x00000400)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_bclk_inv_mask                          (0x00000200)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_rclk_inv_mask                          (0x00000100)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_gclk_inv_mask                          (0x00000080)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_bclk_inv_mask                          (0x00000040)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_rclk_inv_mask                          (0x00000020)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_gclk_inv_mask                          (0x00000010)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_bclk_inv_mask                          (0x00000008)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_rclk_inv_mask                          (0x00000004)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_gclk_inv_mask                          (0x00000002)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_bclk_inv_mask                          (0x00000001)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_rclk_inv(data)                         (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_gclk_inv(data)                         (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port3_bclk_inv(data)                         (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_rclk_inv(data)                         (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_gclk_inv(data)                         (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port2_bclk_inv(data)                         (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_rclk_inv(data)                         (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_gclk_inv(data)                         (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port1_bclk_inv(data)                         (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_rclk_inv(data)                         (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_gclk_inv(data)                         (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_port0_bclk_inv(data)                         (0x00000001&(data))
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port3_rclk_inv(data)                     ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port3_gclk_inv(data)                     ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port3_bclk_inv(data)                     ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port2_rclk_inv(data)                     ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port2_gclk_inv(data)                     ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port2_bclk_inv(data)                     ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port1_rclk_inv(data)                     ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port1_gclk_inv(data)                     ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port1_bclk_inv(data)                     ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port0_rclk_inv(data)                     ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port0_gclk_inv(data)                     ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PHY_FIFO_CR1_get_port0_bclk_inv(data)                     (0x00000001&(data))

#define  HDMI_P3_PORT3_PHY_FIFO_SR0                                              0x180B21A4
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_reg_addr                                     "0xB80B21A4"
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_reg                                          0xB80B21A4
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_inst_addr                                    "0x0068"
#define  set_HDMI_P3_PORT3_PHY_FIFO_SR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_SR0_reg)=data)
#define  get_HDMI_P3_PORT3_PHY_FIFO_SR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_SR0_reg))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wrclk_det_timeout_flag_shift         (29)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rwclk_det_timeout_flag_shift         (28)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wovflow_flag_shift                   (27)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rudflow_flag_shift                   (26)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rflush_flag_shift                    (25)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wrclk_det_timeout_flag_shift         (24)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rwclk_det_timeout_flag_shift         (23)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wovflow_flag_shift                   (22)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rudflow_flag_shift                   (21)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rflush_flag_shift                    (20)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wrclk_det_timeout_flag_shift         (19)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rwclk_det_timeout_flag_shift         (18)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wovflow_flag_shift                   (17)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rudflow_flag_shift                   (16)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rflush_flag_shift                    (15)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wrclk_det_timeout_flag_shift         (14)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rwclk_det_timeout_flag_shift         (13)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wovflow_flag_shift                   (12)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rudflow_flag_shift                   (11)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rflush_flag_shift                    (10)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wrclk_det_timeout_flag_shift         (9)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rwclk_det_timeout_flag_shift         (8)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wovflow_flag_shift                   (7)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rudflow_flag_shift                   (6)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rflush_flag_shift                    (5)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wrclk_det_timeout_flag_shift         (4)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rwclk_det_timeout_flag_shift         (3)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wovflow_flag_shift                   (2)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rudflow_flag_shift                   (1)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rflush_flag_shift                    (0)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wrclk_det_timeout_flag_mask          (0x20000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rwclk_det_timeout_flag_mask          (0x10000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wovflow_flag_mask                    (0x08000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rudflow_flag_mask                    (0x04000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rflush_flag_mask                     (0x02000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wrclk_det_timeout_flag_mask          (0x01000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rwclk_det_timeout_flag_mask          (0x00800000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wovflow_flag_mask                    (0x00400000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rudflow_flag_mask                    (0x00200000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rflush_flag_mask                     (0x00100000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wrclk_det_timeout_flag_mask          (0x00080000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rwclk_det_timeout_flag_mask          (0x00040000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wovflow_flag_mask                    (0x00020000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rudflow_flag_mask                    (0x00010000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rflush_flag_mask                     (0x00008000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wrclk_det_timeout_flag_mask          (0x00004000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rwclk_det_timeout_flag_mask          (0x00002000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wovflow_flag_mask                    (0x00001000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rudflow_flag_mask                    (0x00000800)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rflush_flag_mask                     (0x00000400)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wrclk_det_timeout_flag_mask          (0x00000200)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rwclk_det_timeout_flag_mask          (0x00000100)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wovflow_flag_mask                    (0x00000080)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rudflow_flag_mask                    (0x00000040)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rflush_flag_mask                     (0x00000020)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wrclk_det_timeout_flag_mask          (0x00000010)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rwclk_det_timeout_flag_mask          (0x00000008)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wovflow_flag_mask                    (0x00000004)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rudflow_flag_mask                    (0x00000002)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rflush_flag_mask                     (0x00000001)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wrclk_det_timeout_flag(data)         (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rwclk_det_timeout_flag(data)         (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_wovflow_flag(data)                   (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rudflow_flag(data)                   (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_r_rflush_flag(data)                    (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wrclk_det_timeout_flag(data)         (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rwclk_det_timeout_flag(data)         (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_wovflow_flag(data)                   (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rudflow_flag(data)                   (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_g_rflush_flag(data)                    (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wrclk_det_timeout_flag(data)         (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rwclk_det_timeout_flag(data)         (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_wovflow_flag(data)                   (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rudflow_flag(data)                   (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port1_b_rflush_flag(data)                    (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wrclk_det_timeout_flag(data)         (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rwclk_det_timeout_flag(data)         (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_wovflow_flag(data)                   (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rudflow_flag(data)                   (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_r_rflush_flag(data)                    (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wrclk_det_timeout_flag(data)         (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rwclk_det_timeout_flag(data)         (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_wovflow_flag(data)                   (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rudflow_flag(data)                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_g_rflush_flag(data)                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wrclk_det_timeout_flag(data)         (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rwclk_det_timeout_flag(data)         (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_wovflow_flag(data)                   (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rudflow_flag(data)                   (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_port0_b_rflush_flag(data)                    (0x00000001&(data))
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_r_wrclk_det_timeout_flag(data)     ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_r_rwclk_det_timeout_flag(data)     ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_r_wovflow_flag(data)               ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_r_rudflow_flag(data)               ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_r_rflush_flag(data)                ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_g_wrclk_det_timeout_flag(data)     ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_g_rwclk_det_timeout_flag(data)     ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_g_wovflow_flag(data)               ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_g_rudflow_flag(data)               ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_g_rflush_flag(data)                ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_b_wrclk_det_timeout_flag(data)     ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_b_rwclk_det_timeout_flag(data)     ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_b_wovflow_flag(data)               ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_b_rudflow_flag(data)               ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port1_b_rflush_flag(data)                ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_r_wrclk_det_timeout_flag(data)     ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_r_rwclk_det_timeout_flag(data)     ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_r_wovflow_flag(data)               ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_r_rudflow_flag(data)               ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_r_rflush_flag(data)                ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_g_wrclk_det_timeout_flag(data)     ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_g_rwclk_det_timeout_flag(data)     ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_g_wovflow_flag(data)               ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_g_rudflow_flag(data)               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_g_rflush_flag(data)                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_b_wrclk_det_timeout_flag(data)     ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_b_rwclk_det_timeout_flag(data)     ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_b_wovflow_flag(data)               ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_b_rudflow_flag(data)               ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PHY_FIFO_SR0_get_port0_b_rflush_flag(data)                (0x00000001&(data))

#define  HDMI_P3_PORT3_PHY_FIFO_SR1                                              0x180B21A8
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_reg_addr                                     "0xB80B21A8"
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_reg                                          0xB80B21A8
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_inst_addr                                    "0x0069"
#define  set_HDMI_P3_PORT3_PHY_FIFO_SR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_SR1_reg)=data)
#define  get_HDMI_P3_PORT3_PHY_FIFO_SR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_PHY_FIFO_SR1_reg))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wrclk_det_timeout_flag_shift         (29)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rwclk_det_timeout_flag_shift         (28)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wovflow_flag_shift                   (27)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rudflow_flag_shift                   (26)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rflush_flag_shift                    (25)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wrclk_det_timeout_flag_shift         (24)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rwclk_det_timeout_flag_shift         (23)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wovflow_flag_shift                   (22)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rudflow_flag_shift                   (21)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rflush_flag_shift                    (20)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wrclk_det_timeout_flag_shift         (19)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rwclk_det_timeout_flag_shift         (18)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wovflow_flag_shift                   (17)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rudflow_flag_shift                   (16)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rflush_flag_shift                    (15)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wrclk_det_timeout_flag_shift         (14)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rwclk_det_timeout_flag_shift         (13)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wovflow_flag_shift                   (12)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rudflow_flag_shift                   (11)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rflush_flag_shift                    (10)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wrclk_det_timeout_flag_shift         (9)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rwclk_det_timeout_flag_shift         (8)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wovflow_flag_shift                   (7)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rudflow_flag_shift                   (6)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rflush_flag_shift                    (5)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wrclk_det_timeout_flag_shift         (4)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rwclk_det_timeout_flag_shift         (3)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wovflow_flag_shift                   (2)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rudflow_flag_shift                   (1)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rflush_flag_shift                    (0)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wrclk_det_timeout_flag_mask          (0x20000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rwclk_det_timeout_flag_mask          (0x10000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wovflow_flag_mask                    (0x08000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rudflow_flag_mask                    (0x04000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rflush_flag_mask                     (0x02000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wrclk_det_timeout_flag_mask          (0x01000000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rwclk_det_timeout_flag_mask          (0x00800000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wovflow_flag_mask                    (0x00400000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rudflow_flag_mask                    (0x00200000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rflush_flag_mask                     (0x00100000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wrclk_det_timeout_flag_mask          (0x00080000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rwclk_det_timeout_flag_mask          (0x00040000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wovflow_flag_mask                    (0x00020000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rudflow_flag_mask                    (0x00010000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rflush_flag_mask                     (0x00008000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wrclk_det_timeout_flag_mask          (0x00004000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rwclk_det_timeout_flag_mask          (0x00002000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wovflow_flag_mask                    (0x00001000)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rudflow_flag_mask                    (0x00000800)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rflush_flag_mask                     (0x00000400)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wrclk_det_timeout_flag_mask          (0x00000200)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rwclk_det_timeout_flag_mask          (0x00000100)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wovflow_flag_mask                    (0x00000080)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rudflow_flag_mask                    (0x00000040)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rflush_flag_mask                     (0x00000020)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wrclk_det_timeout_flag_mask          (0x00000010)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rwclk_det_timeout_flag_mask          (0x00000008)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wovflow_flag_mask                    (0x00000004)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rudflow_flag_mask                    (0x00000002)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rflush_flag_mask                     (0x00000001)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wrclk_det_timeout_flag(data)         (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rwclk_det_timeout_flag(data)         (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_wovflow_flag(data)                   (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rudflow_flag(data)                   (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_r_rflush_flag(data)                    (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wrclk_det_timeout_flag(data)         (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rwclk_det_timeout_flag(data)         (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_wovflow_flag(data)                   (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rudflow_flag(data)                   (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_g_rflush_flag(data)                    (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wrclk_det_timeout_flag(data)         (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rwclk_det_timeout_flag(data)         (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_wovflow_flag(data)                   (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rudflow_flag(data)                   (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port3_b_rflush_flag(data)                    (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wrclk_det_timeout_flag(data)         (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rwclk_det_timeout_flag(data)         (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_wovflow_flag(data)                   (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rudflow_flag(data)                   (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_r_rflush_flag(data)                    (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wrclk_det_timeout_flag(data)         (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rwclk_det_timeout_flag(data)         (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_wovflow_flag(data)                   (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rudflow_flag(data)                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_g_rflush_flag(data)                    (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wrclk_det_timeout_flag(data)         (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rwclk_det_timeout_flag(data)         (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_wovflow_flag(data)                   (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rudflow_flag(data)                   (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_port2_b_rflush_flag(data)                    (0x00000001&(data))
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_r_wrclk_det_timeout_flag(data)     ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_r_rwclk_det_timeout_flag(data)     ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_r_wovflow_flag(data)               ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_r_rudflow_flag(data)               ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_r_rflush_flag(data)                ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_g_wrclk_det_timeout_flag(data)     ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_g_rwclk_det_timeout_flag(data)     ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_g_wovflow_flag(data)               ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_g_rudflow_flag(data)               ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_g_rflush_flag(data)                ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_b_wrclk_det_timeout_flag(data)     ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_b_rwclk_det_timeout_flag(data)     ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_b_wovflow_flag(data)               ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_b_rudflow_flag(data)               ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port3_b_rflush_flag(data)                ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_r_wrclk_det_timeout_flag(data)     ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_r_rwclk_det_timeout_flag(data)     ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_r_wovflow_flag(data)               ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_r_rudflow_flag(data)               ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_r_rflush_flag(data)                ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_g_wrclk_det_timeout_flag(data)     ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_g_rwclk_det_timeout_flag(data)     ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_g_wovflow_flag(data)               ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_g_rudflow_flag(data)               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_g_rflush_flag(data)                ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_b_wrclk_det_timeout_flag(data)     ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_b_rwclk_det_timeout_flag(data)     ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_b_wovflow_flag(data)               ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_b_rudflow_flag(data)               ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_PHY_FIFO_SR1_get_port2_b_rflush_flag(data)                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL                                         0x180B21AC
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg_addr                                "0xB80B21AC"
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg                                     0xB80B21AC
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_inst_addr                               "0x006A"
#define  set_HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg(data)                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_reg))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_r_shift   (17)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_r_shift    (16)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_g_shift   (15)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_g_shift    (14)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_b_shift   (13)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_b_shift    (12)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_dfe_rstn_n_shift                        (11)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_2x_out_sel_shift                   (8)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_test_sel_shift                     (4)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_out_sel_shift                      (3)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_shift           (2)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_shift             (1)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_shift            (0)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_r_mask    (0x00020000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_r_mask     (0x00010000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_g_mask    (0x00008000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_g_mask     (0x00004000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_b_mask    (0x00002000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_b_mask     (0x00001000)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_dfe_rstn_n_mask                         (0x00000800)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_2x_out_sel_mask                    (0x00000300)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_test_sel_mask                      (0x000000F0)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_out_sel_mask                       (0x00000008)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_mask            (0x00000004)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_mask              (0x00000002)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_mask             (0x00000001)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_r(data)   (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_r(data)    (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_g(data)   (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_g(data)    (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_phy_dbgout_b(data)   (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_phy_dbgout_b(data)    (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_dfe_rstn_n(data)                        (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_2x_out_sel(data)                   (0x00000300&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_test_sel(data)                     (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_hdmi_out_sel(data)                      (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi(data)           (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi(data)             (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi(data)            (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_force_ctsfifo_rstn_phy_dbgout_r(data) ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_en_ctsfifo_bypass_phy_dbgout_r(data) ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_force_ctsfifo_rstn_phy_dbgout_g(data) ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_en_ctsfifo_bypass_phy_dbgout_g(data) ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_force_ctsfifo_rstn_phy_dbgout_b(data) ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_en_ctsfifo_bypass_phy_dbgout_b(data) ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_dfe_rstn_n(data)                    ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_hdmi_2x_out_sel(data)               ((0x00000300&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_hdmi_test_sel(data)                 ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_hdmi_out_sel(data)                  ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_force_ctsfifo_rstn_hdmi(data)       ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_en_ctsfifo_vsrst_hdmi(data)         ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_CTS_FIFO_CTL_get_en_ctsfifo_bypass_hdmi(data)        (0x00000001&(data))

#define  HDMI_P3_PORT3_CH_CR                                                     0x180B21B0
#define  HDMI_P3_PORT3_CH_CR_reg_addr                                            "0xB80B21B0"
#define  HDMI_P3_PORT3_CH_CR_reg                                                 0xB80B21B0
#define  HDMI_P3_PORT3_CH_CR_inst_addr                                           "0x006B"
#define  set_HDMI_P3_PORT3_CH_CR_reg(data)                                       (*((volatile unsigned int*)HDMI_P3_PORT3_CH_CR_reg)=data)
#define  get_HDMI_P3_PORT3_CH_CR_reg                                             (*((volatile unsigned int*)HDMI_P3_PORT3_CH_CR_reg))
#define  HDMI_P3_PORT3_CH_CR_r_ch_afifo_en_shift                                 (24)
#define  HDMI_P3_PORT3_CH_CR_g_ch_afifo_en_shift                                 (23)
#define  HDMI_P3_PORT3_CH_CR_b_ch_afifo_en_shift                                 (22)
#define  HDMI_P3_PORT3_CH_CR_ch_sync_sel_shift                                   (20)
#define  HDMI_P3_PORT3_CH_CR_dummy_19_17_shift                                   (17)
#define  HDMI_P3_PORT3_CH_CR_rden_thr_shift                                      (12)
#define  HDMI_P3_PORT3_CH_CR_dummy_11_9_shift                                    (9)
#define  HDMI_P3_PORT3_CH_CR_udwater_thr_shift                                   (4)
#define  HDMI_P3_PORT3_CH_CR_dummy_3_2_shift                                     (2)
#define  HDMI_P3_PORT3_CH_CR_flush_shift                                         (1)
#define  HDMI_P3_PORT3_CH_CR_ch_afifo_irq_en_shift                               (0)
#define  HDMI_P3_PORT3_CH_CR_r_ch_afifo_en_mask                                  (0x01000000)
#define  HDMI_P3_PORT3_CH_CR_g_ch_afifo_en_mask                                  (0x00800000)
#define  HDMI_P3_PORT3_CH_CR_b_ch_afifo_en_mask                                  (0x00400000)
#define  HDMI_P3_PORT3_CH_CR_ch_sync_sel_mask                                    (0x00300000)
#define  HDMI_P3_PORT3_CH_CR_dummy_19_17_mask                                    (0x000E0000)
#define  HDMI_P3_PORT3_CH_CR_rden_thr_mask                                       (0x0001F000)
#define  HDMI_P3_PORT3_CH_CR_dummy_11_9_mask                                     (0x00000E00)
#define  HDMI_P3_PORT3_CH_CR_udwater_thr_mask                                    (0x000001F0)
#define  HDMI_P3_PORT3_CH_CR_dummy_3_2_mask                                      (0x0000000C)
#define  HDMI_P3_PORT3_CH_CR_flush_mask                                          (0x00000002)
#define  HDMI_P3_PORT3_CH_CR_ch_afifo_irq_en_mask                                (0x00000001)
#define  HDMI_P3_PORT3_CH_CR_r_ch_afifo_en(data)                                 (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_CH_CR_g_ch_afifo_en(data)                                 (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_CH_CR_b_ch_afifo_en(data)                                 (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_CH_CR_ch_sync_sel(data)                                   (0x00300000&((data)<<20))
#define  HDMI_P3_PORT3_CH_CR_dummy_19_17(data)                                   (0x000E0000&((data)<<17))
#define  HDMI_P3_PORT3_CH_CR_rden_thr(data)                                      (0x0001F000&((data)<<12))
#define  HDMI_P3_PORT3_CH_CR_dummy_11_9(data)                                    (0x00000E00&((data)<<9))
#define  HDMI_P3_PORT3_CH_CR_udwater_thr(data)                                   (0x000001F0&((data)<<4))
#define  HDMI_P3_PORT3_CH_CR_dummy_3_2(data)                                     (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_CH_CR_flush(data)                                         (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_CH_CR_ch_afifo_irq_en(data)                               (0x00000001&(data))
#define  HDMI_P3_PORT3_CH_CR_get_r_ch_afifo_en(data)                             ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_CH_CR_get_g_ch_afifo_en(data)                             ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_CH_CR_get_b_ch_afifo_en(data)                             ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_CH_CR_get_ch_sync_sel(data)                               ((0x00300000&(data))>>20)
#define  HDMI_P3_PORT3_CH_CR_get_dummy_19_17(data)                               ((0x000E0000&(data))>>17)
#define  HDMI_P3_PORT3_CH_CR_get_rden_thr(data)                                  ((0x0001F000&(data))>>12)
#define  HDMI_P3_PORT3_CH_CR_get_dummy_11_9(data)                                ((0x00000E00&(data))>>9)
#define  HDMI_P3_PORT3_CH_CR_get_udwater_thr(data)                               ((0x000001F0&(data))>>4)
#define  HDMI_P3_PORT3_CH_CR_get_dummy_3_2(data)                                 ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_CH_CR_get_flush(data)                                     ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_CH_CR_get_ch_afifo_irq_en(data)                           (0x00000001&(data))

#define  HDMI_P3_PORT3_CH_SR                                                     0x180B21B4
#define  HDMI_P3_PORT3_CH_SR_reg_addr                                            "0xB80B21B4"
#define  HDMI_P3_PORT3_CH_SR_reg                                                 0xB80B21B4
#define  HDMI_P3_PORT3_CH_SR_inst_addr                                           "0x006C"
#define  set_HDMI_P3_PORT3_CH_SR_reg(data)                                       (*((volatile unsigned int*)HDMI_P3_PORT3_CH_SR_reg)=data)
#define  get_HDMI_P3_PORT3_CH_SR_reg                                             (*((volatile unsigned int*)HDMI_P3_PORT3_CH_SR_reg))
#define  HDMI_P3_PORT3_CH_SR_rgb_de_align_flag_shift                             (30)
#define  HDMI_P3_PORT3_CH_SR_r_rwclk_det_timeout_flag_shift                      (29)
#define  HDMI_P3_PORT3_CH_SR_r_wrclk_det_timeout_flag_shift                      (28)
#define  HDMI_P3_PORT3_CH_SR_g_rwclk_det_timeout_flag_shift                      (27)
#define  HDMI_P3_PORT3_CH_SR_g_wrclk_det_timeout_flag_shift                      (26)
#define  HDMI_P3_PORT3_CH_SR_b_rwclk_det_timeout_flag_shift                      (25)
#define  HDMI_P3_PORT3_CH_SR_b_wrclk_det_timeout_flag_shift                      (24)
#define  HDMI_P3_PORT3_CH_SR_r_rudflow_flag_shift                                (23)
#define  HDMI_P3_PORT3_CH_SR_r_wovflow_flag_shift                                (22)
#define  HDMI_P3_PORT3_CH_SR_r_rflush_flag_shift                                 (21)
#define  HDMI_P3_PORT3_CH_SR_r_rw_water_lv_shift                                 (16)
#define  HDMI_P3_PORT3_CH_SR_g_rudflow_flag_shift                                (15)
#define  HDMI_P3_PORT3_CH_SR_g_wovflow_flag_shift                                (14)
#define  HDMI_P3_PORT3_CH_SR_g_rflush_flag_shift                                 (13)
#define  HDMI_P3_PORT3_CH_SR_g_rw_water_lv_shift                                 (8)
#define  HDMI_P3_PORT3_CH_SR_b_rudflow_flag_shift                                (7)
#define  HDMI_P3_PORT3_CH_SR_b_wovflow_flag_shift                                (6)
#define  HDMI_P3_PORT3_CH_SR_b_rflush_flag_shift                                 (5)
#define  HDMI_P3_PORT3_CH_SR_b_rw_water_lv_shift                                 (0)
#define  HDMI_P3_PORT3_CH_SR_rgb_de_align_flag_mask                              (0x40000000)
#define  HDMI_P3_PORT3_CH_SR_r_rwclk_det_timeout_flag_mask                       (0x20000000)
#define  HDMI_P3_PORT3_CH_SR_r_wrclk_det_timeout_flag_mask                       (0x10000000)
#define  HDMI_P3_PORT3_CH_SR_g_rwclk_det_timeout_flag_mask                       (0x08000000)
#define  HDMI_P3_PORT3_CH_SR_g_wrclk_det_timeout_flag_mask                       (0x04000000)
#define  HDMI_P3_PORT3_CH_SR_b_rwclk_det_timeout_flag_mask                       (0x02000000)
#define  HDMI_P3_PORT3_CH_SR_b_wrclk_det_timeout_flag_mask                       (0x01000000)
#define  HDMI_P3_PORT3_CH_SR_r_rudflow_flag_mask                                 (0x00800000)
#define  HDMI_P3_PORT3_CH_SR_r_wovflow_flag_mask                                 (0x00400000)
#define  HDMI_P3_PORT3_CH_SR_r_rflush_flag_mask                                  (0x00200000)
#define  HDMI_P3_PORT3_CH_SR_r_rw_water_lv_mask                                  (0x001F0000)
#define  HDMI_P3_PORT3_CH_SR_g_rudflow_flag_mask                                 (0x00008000)
#define  HDMI_P3_PORT3_CH_SR_g_wovflow_flag_mask                                 (0x00004000)
#define  HDMI_P3_PORT3_CH_SR_g_rflush_flag_mask                                  (0x00002000)
#define  HDMI_P3_PORT3_CH_SR_g_rw_water_lv_mask                                  (0x00001F00)
#define  HDMI_P3_PORT3_CH_SR_b_rudflow_flag_mask                                 (0x00000080)
#define  HDMI_P3_PORT3_CH_SR_b_wovflow_flag_mask                                 (0x00000040)
#define  HDMI_P3_PORT3_CH_SR_b_rflush_flag_mask                                  (0x00000020)
#define  HDMI_P3_PORT3_CH_SR_b_rw_water_lv_mask                                  (0x0000001F)
#define  HDMI_P3_PORT3_CH_SR_rgb_de_align_flag(data)                             (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_CH_SR_r_rwclk_det_timeout_flag(data)                      (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_CH_SR_r_wrclk_det_timeout_flag(data)                      (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_CH_SR_g_rwclk_det_timeout_flag(data)                      (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_CH_SR_g_wrclk_det_timeout_flag(data)                      (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_CH_SR_b_rwclk_det_timeout_flag(data)                      (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_CH_SR_b_wrclk_det_timeout_flag(data)                      (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_CH_SR_r_rudflow_flag(data)                                (0x00800000&((data)<<23))
#define  HDMI_P3_PORT3_CH_SR_r_wovflow_flag(data)                                (0x00400000&((data)<<22))
#define  HDMI_P3_PORT3_CH_SR_r_rflush_flag(data)                                 (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_CH_SR_r_rw_water_lv(data)                                 (0x001F0000&((data)<<16))
#define  HDMI_P3_PORT3_CH_SR_g_rudflow_flag(data)                                (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_CH_SR_g_wovflow_flag(data)                                (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_CH_SR_g_rflush_flag(data)                                 (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_CH_SR_g_rw_water_lv(data)                                 (0x00001F00&((data)<<8))
#define  HDMI_P3_PORT3_CH_SR_b_rudflow_flag(data)                                (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_CH_SR_b_wovflow_flag(data)                                (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_CH_SR_b_rflush_flag(data)                                 (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_CH_SR_b_rw_water_lv(data)                                 (0x0000001F&(data))
#define  HDMI_P3_PORT3_CH_SR_get_rgb_de_align_flag(data)                         ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_CH_SR_get_r_rwclk_det_timeout_flag(data)                  ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_CH_SR_get_r_wrclk_det_timeout_flag(data)                  ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_CH_SR_get_g_rwclk_det_timeout_flag(data)                  ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_CH_SR_get_g_wrclk_det_timeout_flag(data)                  ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_CH_SR_get_b_rwclk_det_timeout_flag(data)                  ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_CH_SR_get_b_wrclk_det_timeout_flag(data)                  ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_CH_SR_get_r_rudflow_flag(data)                            ((0x00800000&(data))>>23)
#define  HDMI_P3_PORT3_CH_SR_get_r_wovflow_flag(data)                            ((0x00400000&(data))>>22)
#define  HDMI_P3_PORT3_CH_SR_get_r_rflush_flag(data)                             ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_CH_SR_get_r_rw_water_lv(data)                             ((0x001F0000&(data))>>16)
#define  HDMI_P3_PORT3_CH_SR_get_g_rudflow_flag(data)                            ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_CH_SR_get_g_wovflow_flag(data)                            ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_CH_SR_get_g_rflush_flag(data)                             ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_CH_SR_get_g_rw_water_lv(data)                             ((0x00001F00&(data))>>8)
#define  HDMI_P3_PORT3_CH_SR_get_b_rudflow_flag(data)                            ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_CH_SR_get_b_wovflow_flag(data)                            ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_CH_SR_get_b_rflush_flag(data)                             ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_CH_SR_get_b_rw_water_lv(data)                             (0x0000001F&(data))

#define  HDMI_P3_PORT3_HDMI_2p0_CR                                               0x180B21B8
#define  HDMI_P3_PORT3_HDMI_2p0_CR_reg_addr                                      "0xB80B21B8"
#define  HDMI_P3_PORT3_HDMI_2p0_CR_reg                                           0xB80B21B8
#define  HDMI_P3_PORT3_HDMI_2p0_CR_inst_addr                                     "0x006D"
#define  set_HDMI_P3_PORT3_HDMI_2p0_CR_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_2p0_CR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_2p0_CR_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_2p0_CR_reg))
#define  HDMI_P3_PORT3_HDMI_2p0_CR_gating_en_shift                               (8)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_ctr_char_num_shift                            (1)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_hdmi_2p0_en_shift                             (0)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_gating_en_mask                                (0x00000100)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_ctr_char_num_mask                             (0x000000FE)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_hdmi_2p0_en_mask                              (0x00000001)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_gating_en(data)                               (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_2p0_CR_ctr_char_num(data)                            (0x000000FE&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_2p0_CR_hdmi_2p0_en(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_2p0_CR_get_gating_en(data)                           ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_get_ctr_char_num(data)                        ((0x000000FE&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_2p0_CR_get_hdmi_2p0_en(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_SCR_CR                                                    0x180B21BC
#define  HDMI_P3_PORT3_SCR_CR_reg_addr                                           "0xB80B21BC"
#define  HDMI_P3_PORT3_SCR_CR_reg                                                0xB80B21BC
#define  HDMI_P3_PORT3_SCR_CR_inst_addr                                          "0x006E"
#define  set_HDMI_P3_PORT3_SCR_CR_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_SCR_CR_reg)=data)
#define  get_HDMI_P3_PORT3_SCR_CR_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_SCR_CR_reg))
#define  HDMI_P3_PORT3_SCR_CR_char_lock_shift                                    (17)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_r_shift                        (16)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_g_shift                        (15)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_b_shift                        (14)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_r_shift                            (13)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_g_shift                            (12)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_b_shift                            (11)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_r_shift                             (10)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_g_shift                             (9)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_b_shift                             (8)
#define  HDMI_P3_PORT3_SCR_CR_uscr_num_shift                                     (4)
#define  HDMI_P3_PORT3_SCR_CR_dummy_3_2_shift                                    (2)
#define  HDMI_P3_PORT3_SCR_CR_scr_en_fw_shift                                    (1)
#define  HDMI_P3_PORT3_SCR_CR_scr_auto_shift                                     (0)
#define  HDMI_P3_PORT3_SCR_CR_char_lock_mask                                     (0x00020000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_r_mask                         (0x00010000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_g_mask                         (0x00008000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_b_mask                         (0x00004000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_r_mask                             (0x00002000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_g_mask                             (0x00001000)
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_b_mask                             (0x00000800)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_r_mask                              (0x00000400)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_g_mask                              (0x00000200)
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_b_mask                              (0x00000100)
#define  HDMI_P3_PORT3_SCR_CR_uscr_num_mask                                      (0x000000F0)
#define  HDMI_P3_PORT3_SCR_CR_dummy_3_2_mask                                     (0x0000000C)
#define  HDMI_P3_PORT3_SCR_CR_scr_en_fw_mask                                     (0x00000002)
#define  HDMI_P3_PORT3_SCR_CR_scr_auto_mask                                      (0x00000001)
#define  HDMI_P3_PORT3_SCR_CR_char_lock(data)                                    (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_r(data)                        (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_g(data)                        (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_SCR_CR_uscr_fall_bound_err_b(data)                        (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_r(data)                            (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_g(data)                            (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_SCR_CR_uscr_per_glitch_b(data)                            (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_r(data)                             (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_g(data)                             (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_SCR_CR_uscr_char_flag_b(data)                             (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_SCR_CR_uscr_num(data)                                     (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_SCR_CR_dummy_3_2(data)                                    (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_SCR_CR_scr_en_fw(data)                                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_SCR_CR_scr_auto(data)                                     (0x00000001&(data))
#define  HDMI_P3_PORT3_SCR_CR_get_char_lock(data)                                ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_fall_bound_err_r(data)                    ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_fall_bound_err_g(data)                    ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_fall_bound_err_b(data)                    ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_per_glitch_r(data)                        ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_per_glitch_g(data)                        ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_per_glitch_b(data)                        ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_char_flag_r(data)                         ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_char_flag_g(data)                         ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_char_flag_b(data)                         ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_SCR_CR_get_uscr_num(data)                                 ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_SCR_CR_get_dummy_3_2(data)                                ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_SCR_CR_get_scr_en_fw(data)                                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_SCR_CR_get_scr_auto(data)                                 (0x00000001&(data))

#define  HDMI_P3_PORT3_CERCR                                                     0x180B21C0
#define  HDMI_P3_PORT3_CERCR_reg_addr                                            "0xB80B21C0"
#define  HDMI_P3_PORT3_CERCR_reg                                                 0xB80B21C0
#define  HDMI_P3_PORT3_CERCR_inst_addr                                           "0x006F"
#define  set_HDMI_P3_PORT3_CERCR_reg(data)                                       (*((volatile unsigned int*)HDMI_P3_PORT3_CERCR_reg)=data)
#define  get_HDMI_P3_PORT3_CERCR_reg                                             (*((volatile unsigned int*)HDMI_P3_PORT3_CERCR_reg))
#define  HDMI_P3_PORT3_CERCR_ch_locked_reset_shift                               (28)
#define  HDMI_P3_PORT3_CERCR_ch2_over_max_err_num_shift                          (27)
#define  HDMI_P3_PORT3_CERCR_ch1_over_max_err_num_shift                          (26)
#define  HDMI_P3_PORT3_CERCR_ch0_over_max_err_num_shift                          (25)
#define  HDMI_P3_PORT3_CERCR_max_err_num_shift                                   (15)
#define  HDMI_P3_PORT3_CERCR_valid_reset_shift                                   (14)
#define  HDMI_P3_PORT3_CERCR_reset_err_det_shift                                 (13)
#define  HDMI_P3_PORT3_CERCR_keep_err_det_shift                                  (12)
#define  HDMI_P3_PORT3_CERCR_refer_implem_shift                                  (11)
#define  HDMI_P3_PORT3_CERCR_reset_shift                                         (10)
#define  HDMI_P3_PORT3_CERCR_period_shift                                        (4)
#define  HDMI_P3_PORT3_CERCR_dummy_3_2_shift                                     (2)
#define  HDMI_P3_PORT3_CERCR_mode_shift                                          (1)
#define  HDMI_P3_PORT3_CERCR_en_shift                                            (0)
#define  HDMI_P3_PORT3_CERCR_ch_locked_reset_mask                                (0x10000000)
#define  HDMI_P3_PORT3_CERCR_ch2_over_max_err_num_mask                           (0x08000000)
#define  HDMI_P3_PORT3_CERCR_ch1_over_max_err_num_mask                           (0x04000000)
#define  HDMI_P3_PORT3_CERCR_ch0_over_max_err_num_mask                           (0x02000000)
#define  HDMI_P3_PORT3_CERCR_max_err_num_mask                                    (0x01FF8000)
#define  HDMI_P3_PORT3_CERCR_valid_reset_mask                                    (0x00004000)
#define  HDMI_P3_PORT3_CERCR_reset_err_det_mask                                  (0x00002000)
#define  HDMI_P3_PORT3_CERCR_keep_err_det_mask                                   (0x00001000)
#define  HDMI_P3_PORT3_CERCR_refer_implem_mask                                   (0x00000800)
#define  HDMI_P3_PORT3_CERCR_reset_mask                                          (0x00000400)
#define  HDMI_P3_PORT3_CERCR_period_mask                                         (0x000003F0)
#define  HDMI_P3_PORT3_CERCR_dummy_3_2_mask                                      (0x0000000C)
#define  HDMI_P3_PORT3_CERCR_mode_mask                                           (0x00000002)
#define  HDMI_P3_PORT3_CERCR_en_mask                                             (0x00000001)
#define  HDMI_P3_PORT3_CERCR_ch_locked_reset(data)                               (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_CERCR_ch2_over_max_err_num(data)                          (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_CERCR_ch1_over_max_err_num(data)                          (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_CERCR_ch0_over_max_err_num(data)                          (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_CERCR_max_err_num(data)                                   (0x01FF8000&((data)<<15))
#define  HDMI_P3_PORT3_CERCR_valid_reset(data)                                   (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_CERCR_reset_err_det(data)                                 (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_CERCR_keep_err_det(data)                                  (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_CERCR_refer_implem(data)                                  (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_CERCR_reset(data)                                         (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_CERCR_period(data)                                        (0x000003F0&((data)<<4))
#define  HDMI_P3_PORT3_CERCR_dummy_3_2(data)                                     (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_CERCR_mode(data)                                          (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_CERCR_en(data)                                            (0x00000001&(data))
#define  HDMI_P3_PORT3_CERCR_get_ch_locked_reset(data)                           ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_CERCR_get_ch2_over_max_err_num(data)                      ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_CERCR_get_ch1_over_max_err_num(data)                      ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_CERCR_get_ch0_over_max_err_num(data)                      ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_CERCR_get_max_err_num(data)                               ((0x01FF8000&(data))>>15)
#define  HDMI_P3_PORT3_CERCR_get_valid_reset(data)                               ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_CERCR_get_reset_err_det(data)                             ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_CERCR_get_keep_err_det(data)                              ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_CERCR_get_refer_implem(data)                              ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_CERCR_get_reset(data)                                     ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_CERCR_get_period(data)                                    ((0x000003F0&(data))>>4)
#define  HDMI_P3_PORT3_CERCR_get_dummy_3_2(data)                                 ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_CERCR_get_mode(data)                                      ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_CERCR_get_en(data)                                        (0x00000001&(data))

#define  HDMI_P3_PORT3_CERSR0                                                    0x180B21C4
#define  HDMI_P3_PORT3_CERSR0_reg_addr                                           "0xB80B21C4"
#define  HDMI_P3_PORT3_CERSR0_reg                                                0xB80B21C4
#define  HDMI_P3_PORT3_CERSR0_inst_addr                                          "0x0070"
#define  set_HDMI_P3_PORT3_CERSR0_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR0_reg)=data)
#define  get_HDMI_P3_PORT3_CERSR0_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR0_reg))
#define  HDMI_P3_PORT3_CERSR0_err_cnt1_video_shift                               (16)
#define  HDMI_P3_PORT3_CERSR0_err_cnt0_video_shift                               (0)
#define  HDMI_P3_PORT3_CERSR0_err_cnt1_video_mask                                (0x7FFF0000)
#define  HDMI_P3_PORT3_CERSR0_err_cnt0_video_mask                                (0x00007FFF)
#define  HDMI_P3_PORT3_CERSR0_err_cnt1_video(data)                               (0x7FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_CERSR0_err_cnt0_video(data)                               (0x00007FFF&(data))
#define  HDMI_P3_PORT3_CERSR0_get_err_cnt1_video(data)                           ((0x7FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_CERSR0_get_err_cnt0_video(data)                           (0x00007FFF&(data))

#define  HDMI_P3_PORT3_CERSR1                                                    0x180B21C8
#define  HDMI_P3_PORT3_CERSR1_reg_addr                                           "0xB80B21C8"
#define  HDMI_P3_PORT3_CERSR1_reg                                                0xB80B21C8
#define  HDMI_P3_PORT3_CERSR1_inst_addr                                          "0x0071"
#define  set_HDMI_P3_PORT3_CERSR1_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR1_reg)=data)
#define  get_HDMI_P3_PORT3_CERSR1_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR1_reg))
#define  HDMI_P3_PORT3_CERSR1_err_cnt0_pkt_shift                                 (16)
#define  HDMI_P3_PORT3_CERSR1_err_cnt2_video_shift                               (0)
#define  HDMI_P3_PORT3_CERSR1_err_cnt0_pkt_mask                                  (0x7FFF0000)
#define  HDMI_P3_PORT3_CERSR1_err_cnt2_video_mask                                (0x00007FFF)
#define  HDMI_P3_PORT3_CERSR1_err_cnt0_pkt(data)                                 (0x7FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_CERSR1_err_cnt2_video(data)                               (0x00007FFF&(data))
#define  HDMI_P3_PORT3_CERSR1_get_err_cnt0_pkt(data)                             ((0x7FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_CERSR1_get_err_cnt2_video(data)                           (0x00007FFF&(data))

#define  HDMI_P3_PORT3_CERSR2                                                    0x180B21CC
#define  HDMI_P3_PORT3_CERSR2_reg_addr                                           "0xB80B21CC"
#define  HDMI_P3_PORT3_CERSR2_reg                                                0xB80B21CC
#define  HDMI_P3_PORT3_CERSR2_inst_addr                                          "0x0072"
#define  set_HDMI_P3_PORT3_CERSR2_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR2_reg)=data)
#define  get_HDMI_P3_PORT3_CERSR2_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR2_reg))
#define  HDMI_P3_PORT3_CERSR2_err_cnt2_pkt_shift                                 (16)
#define  HDMI_P3_PORT3_CERSR2_err_cnt1_pkt_shift                                 (0)
#define  HDMI_P3_PORT3_CERSR2_err_cnt2_pkt_mask                                  (0x7FFF0000)
#define  HDMI_P3_PORT3_CERSR2_err_cnt1_pkt_mask                                  (0x00007FFF)
#define  HDMI_P3_PORT3_CERSR2_err_cnt2_pkt(data)                                 (0x7FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_CERSR2_err_cnt1_pkt(data)                                 (0x00007FFF&(data))
#define  HDMI_P3_PORT3_CERSR2_get_err_cnt2_pkt(data)                             ((0x7FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_CERSR2_get_err_cnt1_pkt(data)                             (0x00007FFF&(data))

#define  HDMI_P3_PORT3_CERSR3                                                    0x180B21D0
#define  HDMI_P3_PORT3_CERSR3_reg_addr                                           "0xB80B21D0"
#define  HDMI_P3_PORT3_CERSR3_reg                                                0xB80B21D0
#define  HDMI_P3_PORT3_CERSR3_inst_addr                                          "0x0073"
#define  set_HDMI_P3_PORT3_CERSR3_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR3_reg)=data)
#define  get_HDMI_P3_PORT3_CERSR3_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR3_reg))
#define  HDMI_P3_PORT3_CERSR3_err_cnt1_ctr_shift                                 (16)
#define  HDMI_P3_PORT3_CERSR3_err_cnt0_ctr_shift                                 (0)
#define  HDMI_P3_PORT3_CERSR3_err_cnt1_ctr_mask                                  (0x7FFF0000)
#define  HDMI_P3_PORT3_CERSR3_err_cnt0_ctr_mask                                  (0x00007FFF)
#define  HDMI_P3_PORT3_CERSR3_err_cnt1_ctr(data)                                 (0x7FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_CERSR3_err_cnt0_ctr(data)                                 (0x00007FFF&(data))
#define  HDMI_P3_PORT3_CERSR3_get_err_cnt1_ctr(data)                             ((0x7FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_CERSR3_get_err_cnt0_ctr(data)                             (0x00007FFF&(data))

#define  HDMI_P3_PORT3_CERSR4                                                    0x180B21D4
#define  HDMI_P3_PORT3_CERSR4_reg_addr                                           "0xB80B21D4"
#define  HDMI_P3_PORT3_CERSR4_reg                                                0xB80B21D4
#define  HDMI_P3_PORT3_CERSR4_inst_addr                                          "0x0074"
#define  set_HDMI_P3_PORT3_CERSR4_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR4_reg)=data)
#define  get_HDMI_P3_PORT3_CERSR4_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_CERSR4_reg))
#define  HDMI_P3_PORT3_CERSR4_err_cnt2_ctr_shift                                 (0)
#define  HDMI_P3_PORT3_CERSR4_err_cnt2_ctr_mask                                  (0x00007FFF)
#define  HDMI_P3_PORT3_CERSR4_err_cnt2_ctr(data)                                 (0x00007FFF&(data))
#define  HDMI_P3_PORT3_CERSR4_get_err_cnt2_ctr(data)                             (0x00007FFF&(data))

#define  HDMI_P3_PORT3_YUV420_CR                                                 0x180B21D8
#define  HDMI_P3_PORT3_YUV420_CR_reg_addr                                        "0xB80B21D8"
#define  HDMI_P3_PORT3_YUV420_CR_reg                                             0xB80B21D8
#define  HDMI_P3_PORT3_YUV420_CR_inst_addr                                       "0x0075"
#define  set_HDMI_P3_PORT3_YUV420_CR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_YUV420_CR_reg)=data)
#define  get_HDMI_P3_PORT3_YUV420_CR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_YUV420_CR_reg))
#define  HDMI_P3_PORT3_YUV420_CR_fifo_over_flag_shift                            (2)
#define  HDMI_P3_PORT3_YUV420_CR_fifo_under_flag_shift                           (1)
#define  HDMI_P3_PORT3_YUV420_CR_en_shift                                        (0)
#define  HDMI_P3_PORT3_YUV420_CR_fifo_over_flag_mask                             (0x00000004)
#define  HDMI_P3_PORT3_YUV420_CR_fifo_under_flag_mask                            (0x00000002)
#define  HDMI_P3_PORT3_YUV420_CR_en_mask                                         (0x00000001)
#define  HDMI_P3_PORT3_YUV420_CR_fifo_over_flag(data)                            (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_YUV420_CR_fifo_under_flag(data)                           (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_YUV420_CR_en(data)                                        (0x00000001&(data))
#define  HDMI_P3_PORT3_YUV420_CR_get_fifo_over_flag(data)                        ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_YUV420_CR_get_fifo_under_flag(data)                       ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_YUV420_CR_get_en(data)                                    (0x00000001&(data))

#define  HDMI_P3_PORT3_SCDC_CR                                                   0x180B21DC
#define  HDMI_P3_PORT3_SCDC_CR_reg_addr                                          "0xB80B21DC"
#define  HDMI_P3_PORT3_SCDC_CR_reg                                               0xB80B21DC
#define  HDMI_P3_PORT3_SCDC_CR_inst_addr                                         "0x0076"
#define  set_HDMI_P3_PORT3_SCDC_CR_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_CR_reg)=data)
#define  get_HDMI_P3_PORT3_SCDC_CR_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_CR_reg))
#define  HDMI_P3_PORT3_SCDC_CR_scdc_reset_shift                                  (5)
#define  HDMI_P3_PORT3_SCDC_CR_dummy_4_2_shift                                   (2)
#define  HDMI_P3_PORT3_SCDC_CR_maddf_shift                                       (1)
#define  HDMI_P3_PORT3_SCDC_CR_scdc_en_shift                                     (0)
#define  HDMI_P3_PORT3_SCDC_CR_scdc_reset_mask                                   (0x00000020)
#define  HDMI_P3_PORT3_SCDC_CR_dummy_4_2_mask                                    (0x0000001C)
#define  HDMI_P3_PORT3_SCDC_CR_maddf_mask                                        (0x00000002)
#define  HDMI_P3_PORT3_SCDC_CR_scdc_en_mask                                      (0x00000001)
#define  HDMI_P3_PORT3_SCDC_CR_scdc_reset(data)                                  (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_SCDC_CR_dummy_4_2(data)                                   (0x0000001C&((data)<<2))
#define  HDMI_P3_PORT3_SCDC_CR_maddf(data)                                       (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_SCDC_CR_scdc_en(data)                                     (0x00000001&(data))
#define  HDMI_P3_PORT3_SCDC_CR_get_scdc_reset(data)                              ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_SCDC_CR_get_dummy_4_2(data)                               ((0x0000001C&(data))>>2)
#define  HDMI_P3_PORT3_SCDC_CR_get_maddf(data)                                   ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_SCDC_CR_get_scdc_en(data)                                 (0x00000001&(data))

#define  HDMI_P3_PORT3_SCDC_PCR                                                  0x180B21E0
#define  HDMI_P3_PORT3_SCDC_PCR_reg_addr                                         "0xB80B21E0"
#define  HDMI_P3_PORT3_SCDC_PCR_reg                                              0xB80B21E0
#define  HDMI_P3_PORT3_SCDC_PCR_inst_addr                                        "0x0077"
#define  set_HDMI_P3_PORT3_SCDC_PCR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_PCR_reg)=data)
#define  get_HDMI_P3_PORT3_SCDC_PCR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_PCR_reg))
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_flag_shift                               (31)
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_sel_shift                                (29)
#define  HDMI_P3_PORT3_SCDC_PCR_status_flag_shift                                (28)
#define  HDMI_P3_PORT3_SCDC_PCR_config_flag_shift                                (27)
#define  HDMI_P3_PORT3_SCDC_PCR_scrambler_status_flag_shift                      (26)
#define  HDMI_P3_PORT3_SCDC_PCR_tmds_config_flag_shift                           (25)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_scl_dly_sel_shift                            (21)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_sda_dly_sel_shift                            (17)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_free_num_shift                               (10)
#define  HDMI_P3_PORT3_SCDC_PCR_rr_retry_sel_shift                               (8)
#define  HDMI_P3_PORT3_SCDC_PCR_dbnc_level_sel_shift                             (7)
#define  HDMI_P3_PORT3_SCDC_PCR_dummy_6_3_shift                                  (3)
#define  HDMI_P3_PORT3_SCDC_PCR_test_rr_added_delay_sel_shift                    (1)
#define  HDMI_P3_PORT3_SCDC_PCR_apai_shift                                       (0)
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_flag_mask                                (0x80000000)
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_sel_mask                                 (0x60000000)
#define  HDMI_P3_PORT3_SCDC_PCR_status_flag_mask                                 (0x10000000)
#define  HDMI_P3_PORT3_SCDC_PCR_config_flag_mask                                 (0x08000000)
#define  HDMI_P3_PORT3_SCDC_PCR_scrambler_status_flag_mask                       (0x04000000)
#define  HDMI_P3_PORT3_SCDC_PCR_tmds_config_flag_mask                            (0x02000000)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_scl_dly_sel_mask                             (0x01E00000)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_sda_dly_sel_mask                             (0x001E0000)
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_free_num_mask                                (0x0001FC00)
#define  HDMI_P3_PORT3_SCDC_PCR_rr_retry_sel_mask                                (0x00000300)
#define  HDMI_P3_PORT3_SCDC_PCR_dbnc_level_sel_mask                              (0x00000080)
#define  HDMI_P3_PORT3_SCDC_PCR_dummy_6_3_mask                                   (0x00000078)
#define  HDMI_P3_PORT3_SCDC_PCR_test_rr_added_delay_sel_mask                     (0x00000006)
#define  HDMI_P3_PORT3_SCDC_PCR_apai_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_flag(data)                               (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_SCDC_PCR_timeout_sel(data)                                (0x60000000&((data)<<29))
#define  HDMI_P3_PORT3_SCDC_PCR_status_flag(data)                                (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_SCDC_PCR_config_flag(data)                                (0x08000000&((data)<<27))
#define  HDMI_P3_PORT3_SCDC_PCR_scrambler_status_flag(data)                      (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_SCDC_PCR_tmds_config_flag(data)                           (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_scl_dly_sel(data)                            (0x01E00000&((data)<<21))
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_sda_dly_sel(data)                            (0x001E0000&((data)<<17))
#define  HDMI_P3_PORT3_SCDC_PCR_i2c_free_num(data)                               (0x0001FC00&((data)<<10))
#define  HDMI_P3_PORT3_SCDC_PCR_rr_retry_sel(data)                               (0x00000300&((data)<<8))
#define  HDMI_P3_PORT3_SCDC_PCR_dbnc_level_sel(data)                             (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_SCDC_PCR_dummy_6_3(data)                                  (0x00000078&((data)<<3))
#define  HDMI_P3_PORT3_SCDC_PCR_test_rr_added_delay_sel(data)                    (0x00000006&((data)<<1))
#define  HDMI_P3_PORT3_SCDC_PCR_apai(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_SCDC_PCR_get_timeout_flag(data)                           ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_SCDC_PCR_get_timeout_sel(data)                            ((0x60000000&(data))>>29)
#define  HDMI_P3_PORT3_SCDC_PCR_get_status_flag(data)                            ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_SCDC_PCR_get_config_flag(data)                            ((0x08000000&(data))>>27)
#define  HDMI_P3_PORT3_SCDC_PCR_get_scrambler_status_flag(data)                  ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_SCDC_PCR_get_tmds_config_flag(data)                       ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_SCDC_PCR_get_i2c_scl_dly_sel(data)                        ((0x01E00000&(data))>>21)
#define  HDMI_P3_PORT3_SCDC_PCR_get_i2c_sda_dly_sel(data)                        ((0x001E0000&(data))>>17)
#define  HDMI_P3_PORT3_SCDC_PCR_get_i2c_free_num(data)                           ((0x0001FC00&(data))>>10)
#define  HDMI_P3_PORT3_SCDC_PCR_get_rr_retry_sel(data)                           ((0x00000300&(data))>>8)
#define  HDMI_P3_PORT3_SCDC_PCR_get_dbnc_level_sel(data)                         ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_SCDC_PCR_get_dummy_6_3(data)                              ((0x00000078&(data))>>3)
#define  HDMI_P3_PORT3_SCDC_PCR_get_test_rr_added_delay_sel(data)                ((0x00000006&(data))>>1)
#define  HDMI_P3_PORT3_SCDC_PCR_get_apai(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_SCDC_AP                                                   0x180B21E4
#define  HDMI_P3_PORT3_SCDC_AP_reg_addr                                          "0xB80B21E4"
#define  HDMI_P3_PORT3_SCDC_AP_reg                                               0xB80B21E4
#define  HDMI_P3_PORT3_SCDC_AP_inst_addr                                         "0x0078"
#define  set_HDMI_P3_PORT3_SCDC_AP_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_AP_reg)=data)
#define  get_HDMI_P3_PORT3_SCDC_AP_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_AP_reg))
#define  HDMI_P3_PORT3_SCDC_AP_ap1_shift                                         (0)
#define  HDMI_P3_PORT3_SCDC_AP_ap1_mask                                          (0x000000FF)
#define  HDMI_P3_PORT3_SCDC_AP_ap1(data)                                         (0x000000FF&(data))
#define  HDMI_P3_PORT3_SCDC_AP_get_ap1(data)                                     (0x000000FF&(data))

#define  HDMI_P3_PORT3_SCDC_DP                                                   0x180B21E8
#define  HDMI_P3_PORT3_SCDC_DP_reg_addr                                          "0xB80B21E8"
#define  HDMI_P3_PORT3_SCDC_DP_reg                                               0xB80B21E8
#define  HDMI_P3_PORT3_SCDC_DP_inst_addr                                         "0x0079"
#define  set_HDMI_P3_PORT3_SCDC_DP_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_DP_reg)=data)
#define  get_HDMI_P3_PORT3_SCDC_DP_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_SCDC_DP_reg))
#define  HDMI_P3_PORT3_SCDC_DP_dp1_shift                                         (0)
#define  HDMI_P3_PORT3_SCDC_DP_dp1_mask                                          (0x000000FF)
#define  HDMI_P3_PORT3_SCDC_DP_dp1(data)                                         (0x000000FF&(data))
#define  HDMI_P3_PORT3_SCDC_DP_get_dp1(data)                                     (0x000000FF&(data))

#define  HDMI_P3_PORT3_ACDRCLKDETCR                                              0x180B21EC
#define  HDMI_P3_PORT3_ACDRCLKDETCR_reg_addr                                     "0xB80B21EC"
#define  HDMI_P3_PORT3_ACDRCLKDETCR_reg                                          0xB80B21EC
#define  HDMI_P3_PORT3_ACDRCLKDETCR_inst_addr                                    "0x007A"
#define  set_HDMI_P3_PORT3_ACDRCLKDETCR_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLKDETCR_reg)=data)
#define  get_HDMI_P3_PORT3_ACDRCLKDETCR_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLKDETCR_reg))
#define  HDMI_P3_PORT3_ACDRCLKDETCR_clock_det_en_shift                           (0)
#define  HDMI_P3_PORT3_ACDRCLKDETCR_clock_det_en_mask                            (0x00000001)
#define  HDMI_P3_PORT3_ACDRCLKDETCR_clock_det_en(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_ACDRCLKDETCR_get_clock_det_en(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_ACDRCLKDETSR                                              0x180B21F0
#define  HDMI_P3_PORT3_ACDRCLKDETSR_reg_addr                                     "0xB80B21F0"
#define  HDMI_P3_PORT3_ACDRCLKDETSR_reg                                          0xB80B21F0
#define  HDMI_P3_PORT3_ACDRCLKDETSR_inst_addr                                    "0x007B"
#define  set_HDMI_P3_PORT3_ACDRCLKDETSR_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLKDETSR_reg)=data)
#define  get_HDMI_P3_PORT3_ACDRCLKDETSR_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLKDETSR_reg))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_en_tmds_chg_irq_shift                        (5)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_tmds_chg_irq_shift                           (4)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_dummy_3_2_shift                              (2)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target_irq_en_shift               (1)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target_shift                      (0)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_en_tmds_chg_irq_mask                         (0x00000020)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_tmds_chg_irq_mask                            (0x00000010)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_dummy_3_2_mask                               (0x0000000C)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target_irq_en_mask                (0x00000002)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target_mask                       (0x00000001)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_en_tmds_chg_irq(data)                        (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_tmds_chg_irq(data)                           (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_dummy_3_2(data)                              (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target_irq_en(data)               (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_clk_not_in_target(data)                      (0x00000001&(data))
#define  HDMI_P3_PORT3_ACDRCLKDETSR_get_en_tmds_chg_irq(data)                    ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_get_tmds_chg_irq(data)                       ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_get_dummy_3_2(data)                          ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_get_clk_not_in_target_irq_en(data)           ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_ACDRCLKDETSR_get_clk_not_in_target(data)                  (0x00000001&(data))

#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00                                        0x180B21F4
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg_addr                               "0xB80B21F4"
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg                                    0xB80B21F4
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_inst_addr                              "0x007C"
#define  set_HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg)=data)
#define  get_HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_00_reg))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_start_shift                   (16)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_end_shift                     (0)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_start_mask                    (0x0FFF0000)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_end_mask                      (0x00000FFF)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_start(data)                   (0x0FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_dclk_cnt_end(data)                     (0x00000FFF&(data))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_get_dclk_cnt_start(data)               ((0x0FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_00_get_dclk_cnt_end(data)                 (0x00000FFF&(data))

#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01                                        0x180B21F8
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg_addr                               "0xB80B21F8"
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg                                    0xB80B21F8
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_inst_addr                              "0x007D"
#define  set_HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg)=data)
#define  get_HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_01_reg))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_maximum_clk_counter_shift   (16)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_minimum_clk_counter_shift   (0)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_maximum_clk_counter_mask    (0x0FFF0000)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_minimum_clk_counter_mask    (0x00000FFF)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_maximum_clk_counter(data)   (0x0FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_target_for_minimum_clk_counter(data)   (0x00000FFF&(data))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_get_target_for_maximum_clk_counter(data) ((0x0FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_01_get_target_for_minimum_clk_counter(data) (0x00000FFF&(data))

#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02                                        0x180B21FC
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg_addr                               "0xB80B21FC"
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg                                    0xB80B21FC
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_inst_addr                              "0x007E"
#define  set_HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg(data)                          (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg)=data)
#define  get_HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg                                (*((volatile unsigned int*)HDMI_P3_PORT3_ACDRCLK_SETTING_02_reg))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_err_threshold_shift        (8)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_debounce_shift             (0)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_err_threshold_mask         (0x00000F00)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_debounce_mask              (0x000000FF)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_err_threshold(data)        (0x00000F00&((data)<<8))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_clk_counter_debounce(data)             (0x000000FF&(data))
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_get_clk_counter_err_threshold(data)    ((0x00000F00&(data))>>8)
#define  HDMI_P3_PORT3_ACDRCLK_SETTING_02_get_clk_counter_debounce(data)         (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDCP_CR                                                   0x180B2204
#define  HDMI_P3_PORT3_HDCP_CR_reg_addr                                          "0xB80B2204"
#define  HDMI_P3_PORT3_HDCP_CR_reg                                               0xB80B2204
#define  HDMI_P3_PORT3_HDCP_CR_inst_addr                                         "0x007F"
#define  set_HDMI_P3_PORT3_HDCP_CR_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_CR_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_CR_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_CR_reg))
#define  HDMI_P3_PORT3_HDCP_CR_namfe_shift                                       (7)
#define  HDMI_P3_PORT3_HDCP_CR_rpt_shift                                         (6)
#define  HDMI_P3_PORT3_HDCP_CR_ivsp_shift                                        (5)
#define  HDMI_P3_PORT3_HDCP_CR_invvs_shift                                       (4)
#define  HDMI_P3_PORT3_HDCP_CR_ivspm_shift                                       (3)
#define  HDMI_P3_PORT3_HDCP_CR_maddf_shift                                       (2)
#define  HDMI_P3_PORT3_HDCP_CR_dkapde_shift                                      (1)
#define  HDMI_P3_PORT3_HDCP_CR_hdcp_en_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_CR_namfe_mask                                        (0x00000080)
#define  HDMI_P3_PORT3_HDCP_CR_rpt_mask                                          (0x00000040)
#define  HDMI_P3_PORT3_HDCP_CR_ivsp_mask                                         (0x00000020)
#define  HDMI_P3_PORT3_HDCP_CR_invvs_mask                                        (0x00000010)
#define  HDMI_P3_PORT3_HDCP_CR_ivspm_mask                                        (0x00000008)
#define  HDMI_P3_PORT3_HDCP_CR_maddf_mask                                        (0x00000004)
#define  HDMI_P3_PORT3_HDCP_CR_dkapde_mask                                       (0x00000002)
#define  HDMI_P3_PORT3_HDCP_CR_hdcp_en_mask                                      (0x00000001)
#define  HDMI_P3_PORT3_HDCP_CR_namfe(data)                                       (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_CR_rpt(data)                                         (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_CR_ivsp(data)                                        (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_CR_invvs(data)                                       (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_CR_ivspm(data)                                       (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_CR_maddf(data)                                       (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_CR_dkapde(data)                                      (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDCP_CR_hdcp_en(data)                                     (0x00000001&(data))
#define  HDMI_P3_PORT3_HDCP_CR_get_namfe(data)                                   ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_CR_get_rpt(data)                                     ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_CR_get_ivsp(data)                                    ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_CR_get_invvs(data)                                   ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_CR_get_ivspm(data)                                   ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_CR_get_maddf(data)                                   ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_CR_get_dkapde(data)                                  ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDCP_CR_get_hdcp_en(data)                                 (0x00000001&(data))

#define  HDMI_P3_PORT3_HDCP_DKAP                                                 0x180B2208
#define  HDMI_P3_PORT3_HDCP_DKAP_reg_addr                                        "0xB80B2208"
#define  HDMI_P3_PORT3_HDCP_DKAP_reg                                             0xB80B2208
#define  HDMI_P3_PORT3_HDCP_DKAP_inst_addr                                       "0x0080"
#define  set_HDMI_P3_PORT3_HDCP_DKAP_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_DKAP_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_DKAP_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_DKAP_reg))
#define  HDMI_P3_PORT3_HDCP_DKAP_dkap_shift                                      (0)
#define  HDMI_P3_PORT3_HDCP_DKAP_dkap_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDCP_DKAP_dkap(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDCP_DKAP_get_dkap(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDCP_PCR                                                  0x180B220C
#define  HDMI_P3_PORT3_HDCP_PCR_reg_addr                                         "0xB80B220C"
#define  HDMI_P3_PORT3_HDCP_PCR_reg                                              0xB80B220C
#define  HDMI_P3_PORT3_HDCP_PCR_inst_addr                                        "0x0081"
#define  set_HDMI_P3_PORT3_HDCP_PCR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_PCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_PCR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_PCR_reg))
#define  HDMI_P3_PORT3_HDCP_PCR_iic_st_shift                                     (28)
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_scl_dly_sel_shift                            (24)
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_sda_dly_sel_shift                            (20)
#define  HDMI_P3_PORT3_HDCP_PCR_tune_up_down_shift                               (17)
#define  HDMI_P3_PORT3_HDCP_PCR_tune_range_shift                                 (10)
#define  HDMI_P3_PORT3_HDCP_PCR_ddcdbnc_shift                                    (9)
#define  HDMI_P3_PORT3_HDCP_PCR_dvi_enc_mode_shift                               (8)
#define  HDMI_P3_PORT3_HDCP_PCR_dbnc_level_sel_shift                             (7)
#define  HDMI_P3_PORT3_HDCP_PCR_km_clk_sel_shift                                 (6)
#define  HDMI_P3_PORT3_HDCP_PCR_hdcp_vs_sel_shift                                (5)
#define  HDMI_P3_PORT3_HDCP_PCR_enc_tog_shift                                    (4)
#define  HDMI_P3_PORT3_HDCP_PCR_avmute_dis_shift                                 (3)
#define  HDMI_P3_PORT3_HDCP_PCR_km_start_sel_shift                               (2)
#define  HDMI_P3_PORT3_HDCP_PCR_apai_type_shift                                  (1)
#define  HDMI_P3_PORT3_HDCP_PCR_apai_shift                                       (0)
#define  HDMI_P3_PORT3_HDCP_PCR_iic_st_mask                                      (0x70000000)
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_scl_dly_sel_mask                             (0x0F000000)
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_sda_dly_sel_mask                             (0x00F00000)
#define  HDMI_P3_PORT3_HDCP_PCR_tune_up_down_mask                                (0x00020000)
#define  HDMI_P3_PORT3_HDCP_PCR_tune_range_mask                                  (0x0001FC00)
#define  HDMI_P3_PORT3_HDCP_PCR_ddcdbnc_mask                                     (0x00000200)
#define  HDMI_P3_PORT3_HDCP_PCR_dvi_enc_mode_mask                                (0x00000100)
#define  HDMI_P3_PORT3_HDCP_PCR_dbnc_level_sel_mask                              (0x00000080)
#define  HDMI_P3_PORT3_HDCP_PCR_km_clk_sel_mask                                  (0x00000040)
#define  HDMI_P3_PORT3_HDCP_PCR_hdcp_vs_sel_mask                                 (0x00000020)
#define  HDMI_P3_PORT3_HDCP_PCR_enc_tog_mask                                     (0x00000010)
#define  HDMI_P3_PORT3_HDCP_PCR_avmute_dis_mask                                  (0x00000008)
#define  HDMI_P3_PORT3_HDCP_PCR_km_start_sel_mask                                (0x00000004)
#define  HDMI_P3_PORT3_HDCP_PCR_apai_type_mask                                   (0x00000002)
#define  HDMI_P3_PORT3_HDCP_PCR_apai_mask                                        (0x00000001)
#define  HDMI_P3_PORT3_HDCP_PCR_iic_st(data)                                     (0x70000000&((data)<<28))
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_scl_dly_sel(data)                            (0x0F000000&((data)<<24))
#define  HDMI_P3_PORT3_HDCP_PCR_i2c_sda_dly_sel(data)                            (0x00F00000&((data)<<20))
#define  HDMI_P3_PORT3_HDCP_PCR_tune_up_down(data)                               (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDCP_PCR_tune_range(data)                                 (0x0001FC00&((data)<<10))
#define  HDMI_P3_PORT3_HDCP_PCR_ddcdbnc(data)                                    (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDCP_PCR_dvi_enc_mode(data)                               (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_PCR_dbnc_level_sel(data)                             (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_PCR_km_clk_sel(data)                                 (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_PCR_hdcp_vs_sel(data)                                (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_PCR_enc_tog(data)                                    (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_PCR_avmute_dis(data)                                 (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_PCR_km_start_sel(data)                               (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_PCR_apai_type(data)                                  (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDCP_PCR_apai(data)                                       (0x00000001&(data))
#define  HDMI_P3_PORT3_HDCP_PCR_get_iic_st(data)                                 ((0x70000000&(data))>>28)
#define  HDMI_P3_PORT3_HDCP_PCR_get_i2c_scl_dly_sel(data)                        ((0x0F000000&(data))>>24)
#define  HDMI_P3_PORT3_HDCP_PCR_get_i2c_sda_dly_sel(data)                        ((0x00F00000&(data))>>20)
#define  HDMI_P3_PORT3_HDCP_PCR_get_tune_up_down(data)                           ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDCP_PCR_get_tune_range(data)                             ((0x0001FC00&(data))>>10)
#define  HDMI_P3_PORT3_HDCP_PCR_get_ddcdbnc(data)                                ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDCP_PCR_get_dvi_enc_mode(data)                           ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_PCR_get_dbnc_level_sel(data)                         ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_PCR_get_km_clk_sel(data)                             ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_PCR_get_hdcp_vs_sel(data)                            ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_PCR_get_enc_tog(data)                                ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_PCR_get_avmute_dis(data)                             ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_PCR_get_km_start_sel(data)                           ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_PCR_get_apai_type(data)                              ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDCP_PCR_get_apai(data)                                   (0x00000001&(data))

#define  HDMI_P3_PORT3_HDCP_FLAG1                                                0x180B2210
#define  HDMI_P3_PORT3_HDCP_FLAG1_reg_addr                                       "0xB80B2210"
#define  HDMI_P3_PORT3_HDCP_FLAG1_reg                                            0xB80B2210
#define  HDMI_P3_PORT3_HDCP_FLAG1_inst_addr                                      "0x0082"
#define  set_HDMI_P3_PORT3_HDCP_FLAG1_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_FLAG1_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_FLAG1_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_FLAG1_reg))
#define  HDMI_P3_PORT3_HDCP_FLAG1_akm_flag_shift                                 (8)
#define  HDMI_P3_PORT3_HDCP_FLAG1_adne_flag_shift                                (7)
#define  HDMI_P3_PORT3_HDCP_FLAG1_ence_flag_shift                                (6)
#define  HDMI_P3_PORT3_HDCP_FLAG1_nc_flag_shift                                  (5)
#define  HDMI_P3_PORT3_HDCP_FLAG1_wr_aksv_flag_shift                             (4)
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_ri_flag_shift                               (3)
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_bksv_flag_shift                             (2)
#define  HDMI_P3_PORT3_HDCP_FLAG1_dummy_1_0_shift                                (0)
#define  HDMI_P3_PORT3_HDCP_FLAG1_akm_flag_mask                                  (0x00000100)
#define  HDMI_P3_PORT3_HDCP_FLAG1_adne_flag_mask                                 (0x00000080)
#define  HDMI_P3_PORT3_HDCP_FLAG1_ence_flag_mask                                 (0x00000040)
#define  HDMI_P3_PORT3_HDCP_FLAG1_nc_flag_mask                                   (0x00000020)
#define  HDMI_P3_PORT3_HDCP_FLAG1_wr_aksv_flag_mask                              (0x00000010)
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_ri_flag_mask                                (0x00000008)
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_bksv_flag_mask                              (0x00000004)
#define  HDMI_P3_PORT3_HDCP_FLAG1_dummy_1_0_mask                                 (0x00000003)
#define  HDMI_P3_PORT3_HDCP_FLAG1_akm_flag(data)                                 (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_FLAG1_adne_flag(data)                                (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_FLAG1_ence_flag(data)                                (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_FLAG1_nc_flag(data)                                  (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_FLAG1_wr_aksv_flag(data)                             (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_ri_flag(data)                               (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_FLAG1_rd_bksv_flag(data)                             (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_FLAG1_dummy_1_0(data)                                (0x00000003&(data))
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_akm_flag(data)                             ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_adne_flag(data)                            ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_ence_flag(data)                            ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_nc_flag(data)                              ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_wr_aksv_flag(data)                         ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_rd_ri_flag(data)                           ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_rd_bksv_flag(data)                         ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_FLAG1_get_dummy_1_0(data)                            (0x00000003&(data))

#define  HDMI_P3_PORT3_HDCP_FLAG2                                                0x180B2214
#define  HDMI_P3_PORT3_HDCP_FLAG2_reg_addr                                       "0xB80B2214"
#define  HDMI_P3_PORT3_HDCP_FLAG2_reg                                            0xB80B2214
#define  HDMI_P3_PORT3_HDCP_FLAG2_inst_addr                                      "0x0083"
#define  set_HDMI_P3_PORT3_HDCP_FLAG2_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_FLAG2_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_FLAG2_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_FLAG2_reg))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_akm_en_shift                               (8)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_adne_en_shift                              (7)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ence_en_shift                              (6)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_nc_en_shift                                (5)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_aksv_en_shift                              (4)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ri_en_shift                                (3)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_bksv_en_shift                              (2)
#define  HDMI_P3_PORT3_HDCP_FLAG2_dummy_1_0_shift                                (0)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_akm_en_mask                                (0x00000100)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_adne_en_mask                               (0x00000080)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ence_en_mask                               (0x00000040)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_nc_en_mask                                 (0x00000020)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_aksv_en_mask                               (0x00000010)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ri_en_mask                                 (0x00000008)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_bksv_en_mask                               (0x00000004)
#define  HDMI_P3_PORT3_HDCP_FLAG2_dummy_1_0_mask                                 (0x00000003)
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_akm_en(data)                               (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_adne_en(data)                              (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ence_en(data)                              (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_nc_en(data)                                (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_aksv_en(data)                              (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_ri_en(data)                                (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_FLAG2_irq_bksv_en(data)                              (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_FLAG2_dummy_1_0(data)                                (0x00000003&(data))
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_akm_en(data)                           ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_adne_en(data)                          ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_ence_en(data)                          ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_nc_en(data)                            ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_aksv_en(data)                          ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_ri_en(data)                            ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_irq_bksv_en(data)                          ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_FLAG2_get_dummy_1_0(data)                            (0x00000003&(data))

#define  HDMI_P3_PORT3_HDCP_AP                                                   0x180B2218
#define  HDMI_P3_PORT3_HDCP_AP_reg_addr                                          "0xB80B2218"
#define  HDMI_P3_PORT3_HDCP_AP_reg                                               0xB80B2218
#define  HDMI_P3_PORT3_HDCP_AP_inst_addr                                         "0x0084"
#define  set_HDMI_P3_PORT3_HDCP_AP_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_AP_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_AP_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_AP_reg))
#define  HDMI_P3_PORT3_HDCP_AP_ksvfifo_status_shift                              (18)
#define  HDMI_P3_PORT3_HDCP_AP_dp_ksvfifo_ptr_shift                              (8)
#define  HDMI_P3_PORT3_HDCP_AP_ap1_shift                                         (0)
#define  HDMI_P3_PORT3_HDCP_AP_ksvfifo_status_mask                               (0x00040000)
#define  HDMI_P3_PORT3_HDCP_AP_dp_ksvfifo_ptr_mask                               (0x0003FF00)
#define  HDMI_P3_PORT3_HDCP_AP_ap1_mask                                          (0x000000FF)
#define  HDMI_P3_PORT3_HDCP_AP_ksvfifo_status(data)                              (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_HDCP_AP_dp_ksvfifo_ptr(data)                              (0x0003FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_AP_ap1(data)                                         (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDCP_AP_get_ksvfifo_status(data)                          ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_HDCP_AP_get_dp_ksvfifo_ptr(data)                          ((0x0003FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_AP_get_ap1(data)                                     (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDCP_DP                                                   0x180B221C
#define  HDMI_P3_PORT3_HDCP_DP_reg_addr                                          "0xB80B221C"
#define  HDMI_P3_PORT3_HDCP_DP_reg                                               0xB80B221C
#define  HDMI_P3_PORT3_HDCP_DP_inst_addr                                         "0x0085"
#define  set_HDMI_P3_PORT3_HDCP_DP_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_DP_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_DP_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_DP_reg))
#define  HDMI_P3_PORT3_HDCP_DP_dp1_shift                                         (0)
#define  HDMI_P3_PORT3_HDCP_DP_dp1_mask                                          (0x000000FF)
#define  HDMI_P3_PORT3_HDCP_DP_dp1(data)                                         (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDCP_DP_get_dp1(data)                                     (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_CR                                               0x180B2220
#define  HDMI_P3_PORT3_HDCP_2p2_CR_reg_addr                                      "0xB80B2220"
#define  HDMI_P3_PORT3_HDCP_2p2_CR_reg                                           0xB80B2220
#define  HDMI_P3_PORT3_HDCP_2p2_CR_inst_addr                                     "0x0086"
#define  set_HDMI_P3_PORT3_HDCP_2p2_CR_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_CR_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_CR_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_CR_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_dummy_31_27_shift                             (27)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fn_auto_inc_shift                             (26)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_cp_fn_shift                             (25)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_encoded_shift                              (24)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_state_shift                            (12)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_rpt_thr_unauth_shift                          (11)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fw_mode_riv_shift                             (10)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_state_shift                             (9)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_mspai_shift                                   (8)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_new_auth_device_shift                         (7)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_pass_shift                          (6)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_done_shift                          (5)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_assemble_id_fail_shift                        (4)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_downstream_done_shift                         (3)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_done_shift                                 (2)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_unauth_shift                           (1)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_hdcp_2p2_en_shift                             (0)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_dummy_31_27_mask                              (0xF8000000)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fn_auto_inc_mask                              (0x04000000)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_cp_fn_mask                              (0x02000000)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_encoded_mask                               (0x01000000)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_state_mask                             (0x00FFF000)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_rpt_thr_unauth_mask                           (0x00000800)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fw_mode_riv_mask                              (0x00000400)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_state_mask                              (0x00000200)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_mspai_mask                                    (0x00000100)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_new_auth_device_mask                          (0x00000080)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_pass_mask                           (0x00000040)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_done_mask                           (0x00000020)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_assemble_id_fail_mask                         (0x00000010)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_downstream_done_mask                          (0x00000008)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_done_mask                                  (0x00000004)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_unauth_mask                            (0x00000002)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_hdcp_2p2_en_mask                              (0x00000001)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_dummy_31_27(data)                             (0xF8000000&((data)<<27))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fn_auto_inc(data)                             (0x04000000&((data)<<26))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_cp_fn(data)                             (0x02000000&((data)<<25))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_encoded(data)                              (0x01000000&((data)<<24))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_state(data)                            (0x00FFF000&((data)<<12))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_rpt_thr_unauth(data)                          (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_fw_mode_riv(data)                             (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_apply_state(data)                             (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_mspai(data)                                   (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_new_auth_device(data)                         (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_pass(data)                          (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_verify_id_done(data)                          (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_assemble_id_fail(data)                        (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_downstream_done(data)                         (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_ks_done(data)                                 (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_switch_unauth(data)                           (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_hdcp_2p2_en(data)                             (0x00000001&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_dummy_31_27(data)                         ((0xF8000000&(data))>>27)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_fn_auto_inc(data)                         ((0x04000000&(data))>>26)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_apply_cp_fn(data)                         ((0x02000000&(data))>>25)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_ks_encoded(data)                          ((0x01000000&(data))>>24)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_switch_state(data)                        ((0x00FFF000&(data))>>12)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_rpt_thr_unauth(data)                      ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_fw_mode_riv(data)                         ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_apply_state(data)                         ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_mspai(data)                               ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_new_auth_device(data)                     ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_verify_id_pass(data)                      ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_verify_id_done(data)                      ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_assemble_id_fail(data)                    ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_downstream_done(data)                     ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_ks_done(data)                             ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_switch_unauth(data)                       ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDCP_2p2_CR_get_hdcp_2p2_en(data)                         (0x00000001&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_ks0                                              0x180B2224
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_reg_addr                                     "0xB80B2224"
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_reg                                          0xB80B2224
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_inst_addr                                    "0x0087"
#define  set_HDMI_P3_PORT3_HDCP_2p2_ks0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks0_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_ks0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks0_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_ks_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_ks_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_ks(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_ks0_get_ks(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_ks1                                              0x180B2228
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_reg_addr                                     "0xB80B2228"
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_reg                                          0xB80B2228
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_inst_addr                                    "0x0088"
#define  set_HDMI_P3_PORT3_HDCP_2p2_ks1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks1_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_ks1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks1_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_ks_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_ks_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_ks(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_ks1_get_ks(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_ks2                                              0x180B222C
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_reg_addr                                     "0xB80B222C"
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_reg                                          0xB80B222C
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_inst_addr                                    "0x0089"
#define  set_HDMI_P3_PORT3_HDCP_2p2_ks2_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks2_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_ks2_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks2_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_ks_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_ks_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_ks(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_ks2_get_ks(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_ks3                                              0x180B2230
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_reg_addr                                     "0xB80B2230"
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_reg                                          0xB80B2230
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_inst_addr                                    "0x008A"
#define  set_HDMI_P3_PORT3_HDCP_2p2_ks3_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks3_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_ks3_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_ks3_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_ks_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_ks_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_ks(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_ks3_get_ks(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_lc0                                              0x180B2234
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_reg_addr                                     "0xB80B2234"
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_reg                                          0xB80B2234
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_inst_addr                                    "0x008B"
#define  set_HDMI_P3_PORT3_HDCP_2p2_lc0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc0_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_lc0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc0_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_lc_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_lc_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_lc(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_lc0_get_lc(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_lc1                                              0x180B2238
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_reg_addr                                     "0xB80B2238"
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_reg                                          0xB80B2238
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_inst_addr                                    "0x008C"
#define  set_HDMI_P3_PORT3_HDCP_2p2_lc1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc1_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_lc1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc1_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_lc_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_lc_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_lc(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_lc1_get_lc(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_lc2                                              0x180B223C
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_reg_addr                                     "0xB80B223C"
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_reg                                          0xB80B223C
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_inst_addr                                    "0x008D"
#define  set_HDMI_P3_PORT3_HDCP_2p2_lc2_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc2_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_lc2_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc2_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_lc_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_lc_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_lc(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_lc2_get_lc(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_lc3                                              0x180B2240
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_reg_addr                                     "0xB80B2240"
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_reg                                          0xB80B2240
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_inst_addr                                    "0x008E"
#define  set_HDMI_P3_PORT3_HDCP_2p2_lc3_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc3_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_lc3_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_lc3_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_lc_shift                                     (0)
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_lc_mask                                      (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_lc(data)                                     (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_lc3_get_lc(data)                                 (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_riv0                                             0x180B2244
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_reg_addr                                    "0xB80B2244"
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_reg                                         0xB80B2244
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_inst_addr                                   "0x008F"
#define  set_HDMI_P3_PORT3_HDCP_2p2_riv0_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_riv0_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_riv0_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_riv0_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_riv_shift                                   (0)
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_riv_mask                                    (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_riv(data)                                   (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_riv0_get_riv(data)                               (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_riv1                                             0x180B2248
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_reg_addr                                    "0xB80B2248"
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_reg                                         0xB80B2248
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_inst_addr                                   "0x0090"
#define  set_HDMI_P3_PORT3_HDCP_2p2_riv1_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_riv1_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_riv1_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_riv1_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_riv_shift                                   (0)
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_riv_mask                                    (0xFFFFFFFF)
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_riv(data)                                   (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_riv1_get_riv(data)                               (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_SR0                                              0x180B224C
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_reg_addr                                     "0xB80B224C"
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_reg                                          0xB80B224C
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_inst_addr                                    "0x0091"
#define  set_HDMI_P3_PORT3_HDCP_2p2_SR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_SR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_SR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_SR0_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_frame_number_shift                           (22)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_fn_compare_fail_shift                    (21)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_crc_fail_shift                           (20)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_no_cp_packet_shift                       (19)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_msg_overwrite_shift                      (18)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_unauth_chg_shift                         (17)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_state_chg_shift                          (16)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_done_shift                        (15)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_done_shift                        (14)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_start_shift                       (13)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_start_shift                       (12)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_state_shift                                  (0)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_frame_number_mask                            (0x3FC00000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_fn_compare_fail_mask                     (0x00200000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_crc_fail_mask                            (0x00100000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_no_cp_packet_mask                        (0x00080000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_msg_overwrite_mask                       (0x00040000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_unauth_chg_mask                          (0x00020000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_state_chg_mask                           (0x00010000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_done_mask                         (0x00008000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_done_mask                         (0x00004000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_start_mask                        (0x00002000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_start_mask                        (0x00001000)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_state_mask                                   (0x00000FFF)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_frame_number(data)                           (0x3FC00000&((data)<<22))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_fn_compare_fail(data)                    (0x00200000&((data)<<21))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_crc_fail(data)                           (0x00100000&((data)<<20))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_no_cp_packet(data)                       (0x00080000&((data)<<19))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_msg_overwrite(data)                      (0x00040000&((data)<<18))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_unauth_chg(data)                         (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_state_chg(data)                          (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_done(data)                        (0x00008000&((data)<<15))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_done(data)                        (0x00004000&((data)<<14))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_rd_msg_start(data)                       (0x00002000&((data)<<13))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_irq_wr_msg_start(data)                       (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_state(data)                                  (0x00000FFF&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_frame_number(data)                       ((0x3FC00000&(data))>>22)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_fn_compare_fail(data)                ((0x00200000&(data))>>21)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_crc_fail(data)                       ((0x00100000&(data))>>20)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_no_cp_packet(data)                   ((0x00080000&(data))>>19)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_msg_overwrite(data)                  ((0x00040000&(data))>>18)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_unauth_chg(data)                     ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_state_chg(data)                      ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_rd_msg_done(data)                    ((0x00008000&(data))>>15)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_wr_msg_done(data)                    ((0x00004000&(data))>>14)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_rd_msg_start(data)                   ((0x00002000&(data))>>13)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_irq_wr_msg_start(data)                   ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDCP_2p2_SR0_get_state(data)                              (0x00000FFF&(data))

#define  HDMI_P3_PORT3_HDCP_2p2_SR1                                              0x180B2250
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_reg_addr                                     "0xB80B2250"
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_reg                                          0xB80B2250
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_inst_addr                                    "0x0092"
#define  set_HDMI_P3_PORT3_HDCP_2p2_SR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_SR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_2p2_SR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_2p2_SR1_reg))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_crc_fail_wd_en_shift                         (11)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_no_cp_packet_wd_en_shift                     (10)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_fn_compare_fail_en_shift                 (9)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_crc_fail_en_shift                        (8)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_no_cp_packet_en_shift                    (7)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_msg_overwrite_en_shift                   (6)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_unauth_chg_en_shift                      (5)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_state_chg_en_shift                       (4)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_done_en_shift                     (3)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_done_en_shift                     (2)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_start_en_shift                    (1)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_start_en_shift                    (0)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_crc_fail_wd_en_mask                          (0x00000800)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_no_cp_packet_wd_en_mask                      (0x00000400)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_fn_compare_fail_en_mask                  (0x00000200)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_crc_fail_en_mask                         (0x00000100)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_no_cp_packet_en_mask                     (0x00000080)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_msg_overwrite_en_mask                    (0x00000040)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_unauth_chg_en_mask                       (0x00000020)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_state_chg_en_mask                        (0x00000010)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_done_en_mask                      (0x00000008)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_done_en_mask                      (0x00000004)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_start_en_mask                     (0x00000002)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_start_en_mask                     (0x00000001)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_crc_fail_wd_en(data)                         (0x00000800&((data)<<11))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_no_cp_packet_wd_en(data)                     (0x00000400&((data)<<10))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_fn_compare_fail_en(data)                 (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_crc_fail_en(data)                        (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_no_cp_packet_en(data)                    (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_msg_overwrite_en(data)                   (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_unauth_chg_en(data)                      (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_state_chg_en(data)                       (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_done_en(data)                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_done_en(data)                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_rd_msg_start_en(data)                    (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_irq_wr_msg_start_en(data)                    (0x00000001&(data))
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_crc_fail_wd_en(data)                     ((0x00000800&(data))>>11)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_no_cp_packet_wd_en(data)                 ((0x00000400&(data))>>10)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_fn_compare_fail_en(data)             ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_crc_fail_en(data)                    ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_no_cp_packet_en(data)                ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_msg_overwrite_en(data)               ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_unauth_chg_en(data)                  ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_state_chg_en(data)                   ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_rd_msg_done_en(data)                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_wr_msg_done_en(data)                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_rd_msg_start_en(data)                ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDCP_2p2_SR1_get_irq_wr_msg_start_en(data)                (0x00000001&(data))

#define  HDMI_P3_PORT3_HDCP_MSAP                                                 0x180B2254
#define  HDMI_P3_PORT3_HDCP_MSAP_reg_addr                                        "0xB80B2254"
#define  HDMI_P3_PORT3_HDCP_MSAP_reg                                             0xB80B2254
#define  HDMI_P3_PORT3_HDCP_MSAP_inst_addr                                       "0x0093"
#define  set_HDMI_P3_PORT3_HDCP_MSAP_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_MSAP_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_MSAP_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_MSAP_reg))
#define  HDMI_P3_PORT3_HDCP_MSAP_ap1_shift                                       (0)
#define  HDMI_P3_PORT3_HDCP_MSAP_ap1_mask                                        (0x000003FF)
#define  HDMI_P3_PORT3_HDCP_MSAP_ap1(data)                                       (0x000003FF&(data))
#define  HDMI_P3_PORT3_HDCP_MSAP_get_ap1(data)                                   (0x000003FF&(data))

#define  HDMI_P3_PORT3_HDCP_MSDP                                                 0x180B2258
#define  HDMI_P3_PORT3_HDCP_MSDP_reg_addr                                        "0xB80B2258"
#define  HDMI_P3_PORT3_HDCP_MSDP_reg                                             0xB80B2258
#define  HDMI_P3_PORT3_HDCP_MSDP_inst_addr                                       "0x0094"
#define  set_HDMI_P3_PORT3_HDCP_MSDP_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_MSDP_reg)=data)
#define  get_HDMI_P3_PORT3_HDCP_MSDP_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDCP_MSDP_reg))
#define  HDMI_P3_PORT3_HDCP_MSDP_dp1_shift                                       (0)
#define  HDMI_P3_PORT3_HDCP_MSDP_dp1_mask                                        (0x000000FF)
#define  HDMI_P3_PORT3_HDCP_MSDP_dp1(data)                                       (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDCP_MSDP_get_dp1(data)                                   (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_CMCR                                                 0x180B2300
#define  HDMI_P3_PORT3_HDMI_CMCR_reg_addr                                        "0xB80B2300"
#define  HDMI_P3_PORT3_HDMI_CMCR_reg                                             0xB80B2300
#define  HDMI_P3_PORT3_HDMI_CMCR_inst_addr                                       "0x0095"
#define  set_HDMI_P3_PORT3_HDMI_CMCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_CMCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_CMCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_CMCR_reg))
#define  HDMI_P3_PORT3_HDMI_CMCR_icmux_shift                                     (7)
#define  HDMI_P3_PORT3_HDMI_CMCR_ocs_shift                                       (5)
#define  HDMI_P3_PORT3_HDMI_CMCR_dbdcb_shift                                     (4)
#define  HDMI_P3_PORT3_HDMI_CMCR_dummy_3_0_shift                                 (0)
#define  HDMI_P3_PORT3_HDMI_CMCR_icmux_mask                                      (0x00000080)
#define  HDMI_P3_PORT3_HDMI_CMCR_ocs_mask                                        (0x00000060)
#define  HDMI_P3_PORT3_HDMI_CMCR_dbdcb_mask                                      (0x00000010)
#define  HDMI_P3_PORT3_HDMI_CMCR_dummy_3_0_mask                                  (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_CMCR_icmux(data)                                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_CMCR_ocs(data)                                       (0x00000060&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_CMCR_dbdcb(data)                                     (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_CMCR_dummy_3_0(data)                                 (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_CMCR_get_icmux(data)                                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_CMCR_get_ocs(data)                                   ((0x00000060&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_CMCR_get_dbdcb(data)                                 ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_CMCR_get_dummy_3_0(data)                             (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_MCAPR                                                0x180B2304
#define  HDMI_P3_PORT3_HDMI_MCAPR_reg_addr                                       "0xB80B2304"
#define  HDMI_P3_PORT3_HDMI_MCAPR_reg                                            0xB80B2304
#define  HDMI_P3_PORT3_HDMI_MCAPR_inst_addr                                      "0x0096"
#define  set_HDMI_P3_PORT3_HDMI_MCAPR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MCAPR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_MCAPR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_MCAPR_reg))
#define  HDMI_P3_PORT3_HDMI_MCAPR_dummy_7_0_shift                                (0)
#define  HDMI_P3_PORT3_HDMI_MCAPR_dummy_7_0_mask                                 (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_MCAPR_dummy_7_0(data)                                (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_MCAPR_get_dummy_7_0(data)                            (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_SCAPR                                                0x180B2308
#define  HDMI_P3_PORT3_HDMI_SCAPR_reg_addr                                       "0xB80B2308"
#define  HDMI_P3_PORT3_HDMI_SCAPR_reg                                            0xB80B2308
#define  HDMI_P3_PORT3_HDMI_SCAPR_inst_addr                                      "0x0097"
#define  set_HDMI_P3_PORT3_HDMI_SCAPR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SCAPR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_SCAPR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_SCAPR_reg))
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb_r_shift                            (17)
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc_r_shift                                    (16)
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc_r_shift                                     (9)
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb_shift                              (8)
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc_shift                                      (7)
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc_shift                                       (0)
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb_r_mask                             (0x00020000)
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc_r_mask                                     (0x00010000)
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc_r_mask                                      (0x0000FE00)
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb_mask                               (0x00000100)
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc_mask                                       (0x00000080)
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc_mask                                        (0x0000007F)
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb_r(data)                            (0x00020000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc_r(data)                                    (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc_r(data)                                     (0x0000FE00&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_SCAPR_s1_code_msb(data)                              (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_SCAPR_slc(data)                                      (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_SCAPR_sc(data)                                       (0x0000007F&(data))
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_s1_code_msb_r(data)                        ((0x00020000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_slc_r(data)                                ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_sc_r(data)                                 ((0x0000FE00&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_s1_code_msb(data)                          ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_slc(data)                                  ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_SCAPR_get_sc(data)                                   (0x0000007F&(data))

#define  HDMI_P3_PORT3_HDMI_DCAPR0                                               0x180B230C
#define  HDMI_P3_PORT3_HDMI_DCAPR0_reg_addr                                      "0xB80B230C"
#define  HDMI_P3_PORT3_HDMI_DCAPR0_reg                                           0xB80B230C
#define  HDMI_P3_PORT3_HDMI_DCAPR0_inst_addr                                     "0x0098"
#define  set_HDMI_P3_PORT3_HDMI_DCAPR0_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DCAPR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_DCAPR0_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_DCAPR0_reg))
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprh_shift                                  (8)
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprl_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprh_mask                                   (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprl_mask                                   (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprh(data)                                  (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_DCAPR0_dcaprl(data)                                  (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_DCAPR0_get_dcaprh(data)                              ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_DCAPR0_get_dcaprl(data)                              (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PSCR                                                 0x180B2310
#define  HDMI_P3_PORT3_HDMI_PSCR_reg_addr                                        "0xB80B2310"
#define  HDMI_P3_PORT3_HDMI_PSCR_reg                                             0xB80B2310
#define  HDMI_P3_PORT3_HDMI_PSCR_inst_addr                                       "0x0099"
#define  set_HDMI_P3_PORT3_HDMI_PSCR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PSCR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PSCR_reg))
#define  HDMI_P3_PORT3_HDMI_PSCR_fdint_shift                                     (5)
#define  HDMI_P3_PORT3_HDMI_PSCR_etcn_shift                                      (4)
#define  HDMI_P3_PORT3_HDMI_PSCR_etfd_shift                                      (3)
#define  HDMI_P3_PORT3_HDMI_PSCR_etfbc_shift                                     (2)
#define  HDMI_P3_PORT3_HDMI_PSCR_pecs_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_PSCR_fdint_mask                                      (0x000000E0)
#define  HDMI_P3_PORT3_HDMI_PSCR_etcn_mask                                       (0x00000010)
#define  HDMI_P3_PORT3_HDMI_PSCR_etfd_mask                                       (0x00000008)
#define  HDMI_P3_PORT3_HDMI_PSCR_etfbc_mask                                      (0x00000004)
#define  HDMI_P3_PORT3_HDMI_PSCR_pecs_mask                                       (0x00000003)
#define  HDMI_P3_PORT3_HDMI_PSCR_fdint(data)                                     (0x000000E0&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_PSCR_etcn(data)                                      (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_PSCR_etfd(data)                                      (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_PSCR_etfbc(data)                                     (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_PSCR_pecs(data)                                      (0x00000003&(data))
#define  HDMI_P3_PORT3_HDMI_PSCR_get_fdint(data)                                 ((0x000000E0&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_PSCR_get_etcn(data)                                  ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_PSCR_get_etfd(data)                                  ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_PSCR_get_etfbc(data)                                 ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_PSCR_get_pecs(data)                                  (0x00000003&(data))

#define  HDMI_P3_PORT3_HDMI_AFDD                                                 0x180B231C
#define  HDMI_P3_PORT3_HDMI_AFDD_reg_addr                                        "0xB80B231C"
#define  HDMI_P3_PORT3_HDMI_AFDD_reg                                             0xB80B231C
#define  HDMI_P3_PORT3_HDMI_AFDD_inst_addr                                       "0x009A"
#define  set_HDMI_P3_PORT3_HDMI_AFDD_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFDD_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AFDD_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AFDD_reg))
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddf_shift                                     (24)
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddr_shift                                     (16)
#define  HDMI_P3_PORT3_HDMI_AFDD_fddf_shift                                      (8)
#define  HDMI_P3_PORT3_HDMI_AFDD_fddr_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddf_mask                                      (0xFF000000)
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddr_mask                                      (0x00FF0000)
#define  HDMI_P3_PORT3_HDMI_AFDD_fddf_mask                                       (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_AFDD_fddr_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddf(data)                                     (0xFF000000&((data)<<24))
#define  HDMI_P3_PORT3_HDMI_AFDD_mfddr(data)                                     (0x00FF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_AFDD_fddf(data)                                      (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_AFDD_fddr(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_AFDD_get_mfddf(data)                                 ((0xFF000000&(data))>>24)
#define  HDMI_P3_PORT3_HDMI_AFDD_get_mfddr(data)                                 ((0x00FF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_AFDD_get_fddf(data)                                  ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_AFDD_get_fddr(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_FTR                                                  0x180B2320
#define  HDMI_P3_PORT3_HDMI_FTR_reg_addr                                         "0xB80B2320"
#define  HDMI_P3_PORT3_HDMI_FTR_reg                                              0xB80B2320
#define  HDMI_P3_PORT3_HDMI_FTR_inst_addr                                        "0x009B"
#define  set_HDMI_P3_PORT3_HDMI_FTR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FTR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_FTR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FTR_reg))
#define  HDMI_P3_PORT3_HDMI_FTR_tl2der_shift                                     (6)
#define  HDMI_P3_PORT3_HDMI_FTR_tl2def_shift                                     (4)
#define  HDMI_P3_PORT3_HDMI_FTR_tt_shift                                         (0)
#define  HDMI_P3_PORT3_HDMI_FTR_tl2der_mask                                      (0x000000C0)
#define  HDMI_P3_PORT3_HDMI_FTR_tl2def_mask                                      (0x00000030)
#define  HDMI_P3_PORT3_HDMI_FTR_tt_mask                                          (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_FTR_tl2der(data)                                     (0x000000C0&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_FTR_tl2def(data)                                     (0x00000030&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_FTR_tt(data)                                         (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_FTR_get_tl2der(data)                                 ((0x000000C0&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_FTR_get_tl2def(data)                                 ((0x00000030&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_FTR_get_tt(data)                                     (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_FBR                                                  0x180B2324
#define  HDMI_P3_PORT3_HDMI_FBR_reg_addr                                         "0xB80B2324"
#define  HDMI_P3_PORT3_HDMI_FBR_reg                                              0xB80B2324
#define  HDMI_P3_PORT3_HDMI_FBR_inst_addr                                        "0x009C"
#define  set_HDMI_P3_PORT3_HDMI_FBR_reg(data)                                    (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FBR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_FBR_reg                                          (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_FBR_reg))
#define  HDMI_P3_PORT3_HDMI_FBR_tfd_shift                                        (3)
#define  HDMI_P3_PORT3_HDMI_FBR_bad_shift                                        (0)
#define  HDMI_P3_PORT3_HDMI_FBR_tfd_mask                                         (0x000000F8)
#define  HDMI_P3_PORT3_HDMI_FBR_bad_mask                                         (0x00000007)
#define  HDMI_P3_PORT3_HDMI_FBR_tfd(data)                                        (0x000000F8&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_FBR_bad(data)                                        (0x00000007&(data))
#define  HDMI_P3_PORT3_HDMI_FBR_get_tfd(data)                                    ((0x000000F8&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_FBR_get_bad(data)                                    (0x00000007&(data))

#define  HDMI_P3_PORT3_HDMI_ICPSNCR0                                             0x180B2328
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_reg_addr                                    "0xB80B2328"
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_reg                                         0xB80B2328
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_inst_addr                                   "0x009D"
#define  set_HDMI_P3_PORT3_HDMI_ICPSNCR0_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICPSNCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ICPSNCR0_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICPSNCR0_reg))
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_ich_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_icl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_ich_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_icl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_ich(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_icl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_get_ich(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_ICPSNCR0_get_icl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PCPSNCR0                                             0x180B232C
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_reg_addr                                    "0xB80B232C"
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_reg                                         0xB80B232C
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_inst_addr                                   "0x009E"
#define  set_HDMI_P3_PORT3_HDMI_PCPSNCR0_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCPSNCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PCPSNCR0_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCPSNCR0_reg))
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pch_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pcl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pch_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pcl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pch(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_pcl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_get_pch(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_PCPSNCR0_get_pcl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_ICTPSR0                                              0x180B2330
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_reg_addr                                     "0xB80B2330"
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_reg                                          0xB80B2330
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_inst_addr                                    "0x009F"
#define  set_HDMI_P3_PORT3_HDMI_ICTPSR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICTPSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ICTPSR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICTPSR0_reg))
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_icth_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_ictl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_icth_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_ictl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_icth(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_ictl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_get_icth(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_ICTPSR0_get_ictl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PCTPSR0                                              0x180B2334
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_reg_addr                                     "0xB80B2334"
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_reg                                          0xB80B2334
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_inst_addr                                    "0x00A0"
#define  set_HDMI_P3_PORT3_HDMI_PCTPSR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCTPSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PCTPSR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCTPSR0_reg))
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pcth_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pctl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pcth_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pctl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pcth(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_pctl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_get_pcth(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_PCTPSR0_get_pctl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_ICBPSR0                                              0x180B2338
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_reg_addr                                     "0xB80B2338"
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_reg                                          0xB80B2338
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_inst_addr                                    "0x00A1"
#define  set_HDMI_P3_PORT3_HDMI_ICBPSR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICBPSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_ICBPSR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_ICBPSR0_reg))
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbh_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbh_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbh(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_icbl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_get_icbh(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_ICBPSR0_get_icbl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PCBPSR0                                              0x180B233C
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_reg_addr                                     "0xB80B233C"
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_reg                                          0xB80B233C
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_inst_addr                                    "0x00A2"
#define  set_HDMI_P3_PORT3_HDMI_PCBPSR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCBPSR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PCBPSR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PCBPSR0_reg))
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbh_shift                                   (8)
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbl_shift                                   (0)
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbh_mask                                    (0x0000FF00)
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbl_mask                                    (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbh(data)                                   (0x0000FF00&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_pcbl(data)                                   (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_get_pcbh(data)                               ((0x0000FF00&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_PCBPSR0_get_pcbl(data)                               (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_NTx1024TR0                                           0x180B2340
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_reg_addr                                  "0xB80B2340"
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_reg                                       0xB80B2340
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_inst_addr                                 "0x00A3"
#define  set_HDMI_P3_PORT3_HDMI_NTx1024TR0_reg(data)                             (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NTx1024TR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_NTx1024TR0_reg                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NTx1024TR0_reg))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_rm_shift                                  (12)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_nt_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_rm_mask                                   (0x00001000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_nt_mask                                   (0x00000FFF)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_rm(data)                                  (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_nt(data)                                  (0x00000FFF&(data))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_get_rm(data)                              ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_get_nt(data)                              (0x00000FFF&(data))

#define  HDMI_P3_PORT3_HDMI_STBPR                                                0x180B2344
#define  HDMI_P3_PORT3_HDMI_STBPR_reg_addr                                       "0xB80B2344"
#define  HDMI_P3_PORT3_HDMI_STBPR_reg                                            0xB80B2344
#define  HDMI_P3_PORT3_HDMI_STBPR_inst_addr                                      "0x00A4"
#define  set_HDMI_P3_PORT3_HDMI_STBPR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_STBPR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_STBPR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_STBPR_reg))
#define  HDMI_P3_PORT3_HDMI_STBPR_ftb_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_STBPR_ftb_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_STBPR_ftb(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_STBPR_get_ftb(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_NCPER                                                0x180B2348
#define  HDMI_P3_PORT3_HDMI_NCPER_reg_addr                                       "0xB80B2348"
#define  HDMI_P3_PORT3_HDMI_NCPER_reg                                            0xB80B2348
#define  HDMI_P3_PORT3_HDMI_NCPER_inst_addr                                      "0x00A5"
#define  set_HDMI_P3_PORT3_HDMI_NCPER_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NCPER_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_NCPER_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NCPER_reg))
#define  HDMI_P3_PORT3_HDMI_NCPER_ncper_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_NCPER_ncper_mask                                     (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_NCPER_ncper(data)                                    (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_NCPER_get_ncper(data)                                (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_PETR                                                 0x180B234C
#define  HDMI_P3_PORT3_HDMI_PETR_reg_addr                                        "0xB80B234C"
#define  HDMI_P3_PORT3_HDMI_PETR_reg                                             0xB80B234C
#define  HDMI_P3_PORT3_HDMI_PETR_inst_addr                                       "0x00A6"
#define  set_HDMI_P3_PORT3_HDMI_PETR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PETR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_PETR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_PETR_reg))
#define  HDMI_P3_PORT3_HDMI_PETR_petr_shift                                      (0)
#define  HDMI_P3_PORT3_HDMI_PETR_petr_mask                                       (0x000000FF)
#define  HDMI_P3_PORT3_HDMI_PETR_petr(data)                                      (0x000000FF&(data))
#define  HDMI_P3_PORT3_HDMI_PETR_get_petr(data)                                  (0x000000FF&(data))

#define  HDMI_P3_PORT3_HDMI_AAPNR                                                0x180B2350
#define  HDMI_P3_PORT3_HDMI_AAPNR_reg_addr                                       "0xB80B2350"
#define  HDMI_P3_PORT3_HDMI_AAPNR_reg                                            0xB80B2350
#define  HDMI_P3_PORT3_HDMI_AAPNR_inst_addr                                      "0x00A7"
#define  set_HDMI_P3_PORT3_HDMI_AAPNR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AAPNR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_AAPNR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_AAPNR_reg))
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvtc_shift                                    (7)
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvbc_shift                                    (6)
#define  HDMI_P3_PORT3_HDMI_AAPNR_ssdmou_shift                                   (5)
#define  HDMI_P3_PORT3_HDMI_AAPNR_tef_shift                                      (4)
#define  HDMI_P3_PORT3_HDMI_AAPNR_w1c5_shift                                     (3)
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_2_shift                                  (2)
#define  HDMI_P3_PORT3_HDMI_AAPNR_esdm_shift                                     (1)
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_0_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvtc_mask                                     (0x00000080)
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvbc_mask                                     (0x00000040)
#define  HDMI_P3_PORT3_HDMI_AAPNR_ssdmou_mask                                    (0x00000020)
#define  HDMI_P3_PORT3_HDMI_AAPNR_tef_mask                                       (0x00000010)
#define  HDMI_P3_PORT3_HDMI_AAPNR_w1c5_mask                                      (0x00000008)
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_2_mask                                   (0x00000004)
#define  HDMI_P3_PORT3_HDMI_AAPNR_esdm_mask                                      (0x00000002)
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_0_mask                                   (0x00000001)
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvtc(data)                                    (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_AAPNR_cmvbc(data)                                    (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_AAPNR_ssdmou(data)                                   (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_AAPNR_tef(data)                                      (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_AAPNR_w1c5(data)                                     (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_2(data)                                  (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_AAPNR_esdm(data)                                     (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_AAPNR_dummy_0(data)                                  (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_cmvtc(data)                                ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_cmvbc(data)                                ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_ssdmou(data)                               ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_tef(data)                                  ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_w1c5(data)                                 ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_dummy_2(data)                              ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_esdm(data)                                 ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_AAPNR_get_dummy_0(data)                              (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_APDMCR                                               0x180B2354
#define  HDMI_P3_PORT3_HDMI_APDMCR_reg_addr                                      "0xB80B2354"
#define  HDMI_P3_PORT3_HDMI_APDMCR_reg                                           0xB80B2354
#define  HDMI_P3_PORT3_HDMI_APDMCR_inst_addr                                     "0x00A8"
#define  set_HDMI_P3_PORT3_HDMI_APDMCR_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APDMCR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APDMCR_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APDMCR_reg))
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_7_shift                                 (7)
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_6_shift                                 (6)
#define  HDMI_P3_PORT3_HDMI_APDMCR_edm_shift                                     (5)
#define  HDMI_P3_PORT3_HDMI_APDMCR_pst_shift                                     (4)
#define  HDMI_P3_PORT3_HDMI_APDMCR_psc_shift                                     (0)
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_7_mask                                  (0x00000080)
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_6_mask                                  (0x00000040)
#define  HDMI_P3_PORT3_HDMI_APDMCR_edm_mask                                      (0x00000020)
#define  HDMI_P3_PORT3_HDMI_APDMCR_pst_mask                                      (0x00000010)
#define  HDMI_P3_PORT3_HDMI_APDMCR_psc_mask                                      (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_7(data)                                 (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_APDMCR_dummy_6(data)                                 (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_APDMCR_edm(data)                                     (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_APDMCR_pst(data)                                     (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_APDMCR_psc(data)                                     (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_APDMCR_get_dummy_7(data)                             ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_APDMCR_get_dummy_6(data)                             ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_APDMCR_get_edm(data)                                 ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_APDMCR_get_pst(data)                                 ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_APDMCR_get_psc(data)                                 (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_APTMCR0                                              0x180B2358
#define  HDMI_P3_PORT3_HDMI_APTMCR0_reg_addr                                     "0xB80B2358"
#define  HDMI_P3_PORT3_HDMI_APTMCR0_reg                                          0xB80B2358
#define  HDMI_P3_PORT3_HDMI_APTMCR0_inst_addr                                    "0x00A9"
#define  set_HDMI_P3_PORT3_HDMI_APTMCR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APTMCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APTMCR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APTMCR0_reg))
#define  HDMI_P3_PORT3_HDMI_APTMCR0_fps_shift                                    (4)
#define  HDMI_P3_PORT3_HDMI_APTMCR0_sps_shift                                    (0)
#define  HDMI_P3_PORT3_HDMI_APTMCR0_fps_mask                                     (0x000000F0)
#define  HDMI_P3_PORT3_HDMI_APTMCR0_sps_mask                                     (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_APTMCR0_fps(data)                                    (0x000000F0&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_APTMCR0_sps(data)                                    (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_APTMCR0_get_fps(data)                                ((0x000000F0&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_APTMCR0_get_sps(data)                                (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_APTMCR1                                              0x180B235C
#define  HDMI_P3_PORT3_HDMI_APTMCR1_reg_addr                                     "0xB80B235C"
#define  HDMI_P3_PORT3_HDMI_APTMCR1_reg                                          0xB80B235C
#define  HDMI_P3_PORT3_HDMI_APTMCR1_inst_addr                                    "0x00AA"
#define  set_HDMI_P3_PORT3_HDMI_APTMCR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APTMCR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APTMCR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APTMCR1_reg))
#define  HDMI_P3_PORT3_HDMI_APTMCR1_plltm_shift                                  (6)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_fpsd_shift                                   (5)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_spsd_shift                                   (4)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_nfpss_shift                                  (0)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_plltm_mask                                   (0x00000040)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_fpsd_mask                                    (0x00000020)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_spsd_mask                                    (0x00000010)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_nfpss_mask                                   (0x0000000F)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_plltm(data)                                  (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_APTMCR1_fpsd(data)                                   (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_APTMCR1_spsd(data)                                   (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_APTMCR1_nfpss(data)                                  (0x0000000F&(data))
#define  HDMI_P3_PORT3_HDMI_APTMCR1_get_plltm(data)                              ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_get_fpsd(data)                               ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_get_spsd(data)                               ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_APTMCR1_get_nfpss(data)                              (0x0000000F&(data))

#define  HDMI_P3_PORT3_HDMI_NPECR                                                0x180B2360
#define  HDMI_P3_PORT3_HDMI_NPECR_reg_addr                                       "0xB80B2360"
#define  HDMI_P3_PORT3_HDMI_NPECR_reg                                            0xB80B2360
#define  HDMI_P3_PORT3_HDMI_NPECR_inst_addr                                      "0x00AB"
#define  set_HDMI_P3_PORT3_HDMI_NPECR_reg(data)                                  (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NPECR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_NPECR_reg                                        (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NPECR_reg))
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_en_shift                 (31)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_re_enable_off_en_shift                    (30)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_status_shift             (29)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_irq_en_shift             (28)
#define  HDMI_P3_PORT3_HDMI_NPECR_dummy_27_20_shift                              (20)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_cnt_shift                (0)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_en_mask                  (0x80000000)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_re_enable_off_en_mask                     (0x40000000)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_status_mask              (0x20000000)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_irq_en_mask              (0x10000000)
#define  HDMI_P3_PORT3_HDMI_NPECR_dummy_27_20_mask                               (0x0FF00000)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_cnt_mask                 (0x000FFFFF)
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_en(data)                 (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_re_enable_off_en(data)                    (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_status(data)             (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_irq_en(data)             (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_HDMI_NPECR_dummy_27_20(data)                              (0x0FF00000&((data)<<20))
#define  HDMI_P3_PORT3_HDMI_NPECR_ncts_disable_pe_check_cnt(data)                (0x000FFFFF&(data))
#define  HDMI_P3_PORT3_HDMI_NPECR_get_ncts_disable_pe_check_en(data)             ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_HDMI_NPECR_get_ncts_re_enable_off_en(data)                ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_NPECR_get_ncts_disable_pe_check_status(data)         ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_HDMI_NPECR_get_ncts_disable_pe_check_irq_en(data)         ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_HDMI_NPECR_get_dummy_27_20(data)                          ((0x0FF00000&(data))>>20)
#define  HDMI_P3_PORT3_HDMI_NPECR_get_ncts_disable_pe_check_cnt(data)            (0x000FFFFF&(data))

#define  HDMI_P3_PORT3_HDMI_NROR                                                 0x180B2364
#define  HDMI_P3_PORT3_HDMI_NROR_reg_addr                                        "0xB80B2364"
#define  HDMI_P3_PORT3_HDMI_NROR_reg                                             0xB80B2364
#define  HDMI_P3_PORT3_HDMI_NROR_inst_addr                                       "0x00AC"
#define  set_HDMI_P3_PORT3_HDMI_NROR_reg(data)                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NROR_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_NROR_reg                                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NROR_reg))
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_start_shift                  (16)
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_end_shift                    (0)
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_start_mask                   (0xFFFF0000)
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_end_mask                     (0x0000FFFF)
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_start(data)                  (0xFFFF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_NROR_ncts_re_enable_off_end(data)                    (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_HDMI_NROR_get_ncts_re_enable_off_start(data)              ((0xFFFF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_NROR_get_ncts_re_enable_off_end(data)                (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold                                 0x180B2368
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg_addr                        "0xB80B2368"
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg                             0xB80B2368
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_inst_addr                       "0x00AD"
#define  set_HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg(data)                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg                         (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_reg))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_over_threshold_shift            (31)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_under_threshold_shift           (30)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_wd_by_tmds_clk_shift            (29)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_irq_by_tmds_clk_shift           (28)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_up_threshold_shift           (16)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_low_threshold_shift          (0)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_over_threshold_mask             (0x80000000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_under_threshold_mask            (0x40000000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_wd_by_tmds_clk_mask             (0x20000000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_irq_by_tmds_clk_mask            (0x10000000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_up_threshold_mask            (0x0FFF0000)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_low_threshold_mask           (0x00000FFF)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_over_threshold(data)            (0x80000000&((data)<<31))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_under_threshold(data)           (0x40000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_wd_by_tmds_clk(data)            (0x20000000&((data)<<29))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_irq_by_tmds_clk(data)           (0x10000000&((data)<<28))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_up_threshold(data)           (0x0FFF0000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_nt_low_threshold(data)          (0x00000FFF&(data))
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_over_threshold(data)        ((0x80000000&(data))>>31)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_under_threshold(data)       ((0x40000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_wd_by_tmds_clk(data)        ((0x20000000&(data))>>29)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_irq_by_tmds_clk(data)       ((0x10000000&(data))>>28)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_nt_up_threshold(data)       ((0x0FFF0000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_NTx1024TR0_Threshold_get_nt_low_threshold(data)      (0x00000FFF&(data))

#define  HDMI_P3_PORT3_HDMI_APLLCR0                                              0x180B2380
#define  HDMI_P3_PORT3_HDMI_APLLCR0_reg_addr                                     "0xB80B2380"
#define  HDMI_P3_PORT3_HDMI_APLLCR0_reg                                          0xB80B2380
#define  HDMI_P3_PORT3_HDMI_APLLCR0_inst_addr                                    "0x00AE"
#define  set_HDMI_P3_PORT3_HDMI_APLLCR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APLLCR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR0_reg))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reg_shift                               (30)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_m_shift                                 (22)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reser_shift                             (17)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_bpsin_shift                             (16)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_o_shift                                 (14)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_n_shift                                 (6)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_rs_shift                                (3)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_ip_shift                                (0)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reg_mask                                (0xC0000000)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_m_mask                                  (0x3FC00000)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reser_mask                              (0x001E0000)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_bpsin_mask                              (0x00010000)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_o_mask                                  (0x0000C000)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_n_mask                                  (0x000001C0)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_rs_mask                                 (0x00000038)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_ip_mask                                 (0x00000007)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reg(data)                               (0xC0000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_m(data)                                 (0x3FC00000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_reser(data)                             (0x001E0000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_bpsin(data)                             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_o(data)                                 (0x0000C000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_n(data)                                 (0x000001C0&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_rs(data)                                (0x00000038&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_dpll_ip(data)                                (0x00000007&(data))
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_reg(data)                           ((0xC0000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_m(data)                             ((0x3FC00000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_reser(data)                         ((0x001E0000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_bpsin(data)                         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_o(data)                             ((0x0000C000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_n(data)                             ((0x000001C0&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_rs(data)                            ((0x00000038&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_APLLCR0_get_dpll_ip(data)                            (0x00000007&(data))

#define  HDMI_P3_PORT3_HDMI_APLLCR1                                              0x180B2384
#define  HDMI_P3_PORT3_HDMI_APLLCR1_reg_addr                                     "0xB80B2384"
#define  HDMI_P3_PORT3_HDMI_APLLCR1_reg                                          0xB80B2384
#define  HDMI_P3_PORT3_HDMI_APLLCR1_inst_addr                                    "0x00AF"
#define  set_HDMI_P3_PORT3_HDMI_APLLCR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APLLCR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR1_reg))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cp_shift                                (21)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_seltst_shift                            (19)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cs_shift                                (17)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_reserve_shift                           (9)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_bpspsw_shift                            (8)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdo_shift                               (7)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdrst_shift                             (6)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdset_shift                             (5)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_rstb_shift                              (4)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_stoppsw_shift                           (3)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_freeze_shift                            (2)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_vcorstb_shift                           (1)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_pow_shift                               (0)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cp_mask                                 (0x00600000)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_seltst_mask                             (0x00180000)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cs_mask                                 (0x00060000)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_reserve_mask                            (0x00000200)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_bpspsw_mask                             (0x00000100)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdo_mask                                (0x00000080)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdrst_mask                              (0x00000040)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdset_mask                              (0x00000020)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_rstb_mask                               (0x00000010)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_stoppsw_mask                            (0x00000008)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_freeze_mask                             (0x00000004)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_vcorstb_mask                            (0x00000002)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_pow_mask                                (0x00000001)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cp(data)                                (0x00600000&((data)<<21))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_seltst(data)                            (0x00180000&((data)<<19))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_cs(data)                                (0x00060000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_reserve(data)                           (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_bpspsw(data)                            (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdo(data)                               (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdrst(data)                             (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_wdset(data)                             (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_rstb(data)                              (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_stoppsw(data)                           (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_freeze(data)                            (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_vcorstb(data)                           (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_dpll_pow(data)                               (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_cp(data)                            ((0x00600000&(data))>>21)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_seltst(data)                        ((0x00180000&(data))>>19)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_cs(data)                            ((0x00060000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_reserve(data)                       ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_bpspsw(data)                        ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_wdo(data)                           ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_wdrst(data)                         ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_wdset(data)                         ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_rstb(data)                          ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_stoppsw(data)                       ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_freeze(data)                        ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_vcorstb(data)                       ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_APLLCR1_get_dpll_pow(data)                           (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_APLLCR2                                              0x180B2388
#define  HDMI_P3_PORT3_HDMI_APLLCR2_reg_addr                                     "0xB80B2388"
#define  HDMI_P3_PORT3_HDMI_APLLCR2_reg                                          0xB80B2388
#define  HDMI_P3_PORT3_HDMI_APLLCR2_inst_addr                                    "0x00B0"
#define  set_HDMI_P3_PORT3_HDMI_APLLCR2_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR2_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APLLCR2_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR2_reg))
#define  HDMI_P3_PORT3_HDMI_APLLCR2_dpll_reloadm_shift                           (0)
#define  HDMI_P3_PORT3_HDMI_APLLCR2_dpll_reloadm_mask                            (0x00000001)
#define  HDMI_P3_PORT3_HDMI_APLLCR2_dpll_reloadm(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_APLLCR2_get_dpll_reloadm(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_APLLCR3                                              0x180B238C
#define  HDMI_P3_PORT3_HDMI_APLLCR3_reg_addr                                     "0xB80B238C"
#define  HDMI_P3_PORT3_HDMI_APLLCR3_reg                                          0xB80B238C
#define  HDMI_P3_PORT3_HDMI_APLLCR3_inst_addr                                    "0x00B1"
#define  set_HDMI_P3_PORT3_HDMI_APLLCR3_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR3_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APLLCR3_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLLCR3_reg))
#define  HDMI_P3_PORT3_HDMI_APLLCR3_sum_c_samp_shift                             (0)
#define  HDMI_P3_PORT3_HDMI_APLLCR3_sum_c_samp_mask                              (0x0000FFFF)
#define  HDMI_P3_PORT3_HDMI_APLLCR3_sum_c_samp(data)                             (0x0000FFFF&(data))
#define  HDMI_P3_PORT3_HDMI_APLLCR3_get_sum_c_samp(data)                         (0x0000FFFF&(data))

#define  HDMI_P3_PORT3_HDMI_APLL_TESTM                                           0x180B2390
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_reg_addr                                  "0xB80B2390"
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_reg                                       0xB80B2390
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_inst_addr                                 "0x00B2"
#define  set_HDMI_P3_PORT3_HDMI_APLL_TESTM_reg(data)                             (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLL_TESTM_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_APLL_TESTM_reg                                   (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_APLL_TESTM_reg))
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_test_shift                         (22)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_db_shift                           (1)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_sel_shift                          (0)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_test_mask                          (0x3FC00000)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_db_mask                            (0x00000002)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_sel_mask                           (0x00000001)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_test(data)                         (0x3FC00000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_db(data)                           (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_dpll_m_sel(data)                          (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_get_dpll_m_test(data)                     ((0x3FC00000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_get_dpll_m_db(data)                       ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_APLL_TESTM_get_dpll_m_sel(data)                      (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_VPLLCR0                                              0x180B2400
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_reg_addr                                     "0xB80B2400"
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_reg                                          0xB80B2400
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_inst_addr                                    "0x00B3"
#define  set_HDMI_P3_PORT3_HDMI_VPLLCR0_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR0_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VPLLCR0_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR0_reg))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reg_shift                               (30)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_m_shift                                 (22)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reser_shift                             (17)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_bpsin_shift                             (16)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_o_shift                                 (14)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_n_shift                                 (6)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_rs_shift                                (3)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_ip_shift                                (0)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reg_mask                                (0xC0000000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_m_mask                                  (0x3FC00000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reser_mask                              (0x001E0000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_bpsin_mask                              (0x00010000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_o_mask                                  (0x0000C000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_n_mask                                  (0x000001C0)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_rs_mask                                 (0x00000038)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_ip_mask                                 (0x00000007)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reg(data)                               (0xC0000000&((data)<<30))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_m(data)                                 (0x3FC00000&((data)<<22))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_reser(data)                             (0x001E0000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_bpsin(data)                             (0x00010000&((data)<<16))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_o(data)                                 (0x0000C000&((data)<<14))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_n(data)                                 (0x000001C0&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_rs(data)                                (0x00000038&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_dpll_ip(data)                                (0x00000007&(data))
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_reg(data)                           ((0xC0000000&(data))>>30)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_m(data)                             ((0x3FC00000&(data))>>22)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_reser(data)                         ((0x001E0000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_bpsin(data)                         ((0x00010000&(data))>>16)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_o(data)                             ((0x0000C000&(data))>>14)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_n(data)                             ((0x000001C0&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_rs(data)                            ((0x00000038&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_VPLLCR0_get_dpll_ip(data)                            (0x00000007&(data))

#define  HDMI_P3_PORT3_HDMI_VPLLCR1                                              0x180B2404
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_reg_addr                                     "0xB80B2404"
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_reg                                          0xB80B2404
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_inst_addr                                    "0x00B4"
#define  set_HDMI_P3_PORT3_HDMI_VPLLCR1_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR1_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VPLLCR1_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR1_reg))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cp_shift                                (21)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_seltst_shift                            (19)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cs_shift                                (17)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_pow_shift                           (12)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_sel_shift                           (10)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_reserve_shift                           (9)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_bpspsw_shift                            (8)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdo_shift                               (7)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdrst_shift                             (6)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdset_shift                             (5)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_rstb_shift                              (4)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_stoppsw_shift                           (3)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_freeze_shift                            (2)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_vcorstb_shift                           (1)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_pow_shift                               (0)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cp_mask                                 (0x00600000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_seltst_mask                             (0x00180000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cs_mask                                 (0x00060000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_pow_mask                            (0x00001000)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_sel_mask                            (0x00000C00)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_reserve_mask                            (0x00000200)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_bpspsw_mask                             (0x00000100)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdo_mask                                (0x00000080)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdrst_mask                              (0x00000040)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdset_mask                              (0x00000020)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_rstb_mask                               (0x00000010)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_stoppsw_mask                            (0x00000008)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_freeze_mask                             (0x00000004)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_vcorstb_mask                            (0x00000002)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_pow_mask                                (0x00000001)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cp(data)                                (0x00600000&((data)<<21))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_seltst(data)                            (0x00180000&((data)<<19))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_cs(data)                                (0x00060000&((data)<<17))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_pow(data)                           (0x00001000&((data)<<12))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_ldo_sel(data)                           (0x00000C00&((data)<<10))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_reserve(data)                           (0x00000200&((data)<<9))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_bpspsw(data)                            (0x00000100&((data)<<8))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdo(data)                               (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdrst(data)                             (0x00000040&((data)<<6))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_wdset(data)                             (0x00000020&((data)<<5))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_rstb(data)                              (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_stoppsw(data)                           (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_freeze(data)                            (0x00000004&((data)<<2))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_vcorstb(data)                           (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_dpll_pow(data)                               (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_cp(data)                            ((0x00600000&(data))>>21)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_seltst(data)                        ((0x00180000&(data))>>19)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_cs(data)                            ((0x00060000&(data))>>17)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_ldo_pow(data)                       ((0x00001000&(data))>>12)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_ldo_sel(data)                       ((0x00000C00&(data))>>10)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_reserve(data)                       ((0x00000200&(data))>>9)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_bpspsw(data)                        ((0x00000100&(data))>>8)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_wdo(data)                           ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_wdrst(data)                         ((0x00000040&(data))>>6)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_wdset(data)                         ((0x00000020&(data))>>5)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_rstb(data)                          ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_stoppsw(data)                       ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_freeze(data)                        ((0x00000004&(data))>>2)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_vcorstb(data)                       ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_HDMI_VPLLCR1_get_dpll_pow(data)                           (0x00000001&(data))

#define  HDMI_P3_PORT3_HDMI_VPLLCR2                                              0x180B2408
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_reg_addr                                     "0xB80B2408"
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_reg                                          0xB80B2408
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_inst_addr                                    "0x00B5"
#define  set_HDMI_P3_PORT3_HDMI_VPLLCR2_reg(data)                                (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR2_reg)=data)
#define  get_HDMI_P3_PORT3_HDMI_VPLLCR2_reg                                      (*((volatile unsigned int*)HDMI_P3_PORT3_HDMI_VPLLCR2_reg))
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_dpll_reloadm_shift                           (0)
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_dpll_reloadm_mask                            (0x00000001)
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_dpll_reloadm(data)                           (0x00000001&(data))
#define  HDMI_P3_PORT3_HDMI_VPLLCR2_get_dpll_reloadm(data)                       (0x00000001&(data))

#define  HDMI_P3_PORT3_MN_SCLKG_CTRL                                             0x180B2410
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_reg_addr                                    "0xB80B2410"
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_reg                                         0xB80B2410
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_inst_addr                                   "0x00B6"
#define  set_HDMI_P3_PORT3_MN_SCLKG_CTRL_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_MN_SCLKG_CTRL_reg)=data)
#define  get_HDMI_P3_PORT3_MN_SCLKG_CTRL_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_MN_SCLKG_CTRL_reg))
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_pll_in_sel_shift                      (7)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_oclk_sel_shift                        (5)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_dbuf_shift                            (4)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_dummy_3_0_shift                             (0)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_pll_in_sel_mask                       (0x00000080)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_oclk_sel_mask                         (0x00000060)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_dbuf_mask                             (0x00000010)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_dummy_3_0_mask                              (0x0000000F)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_pll_in_sel(data)                      (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_oclk_sel(data)                        (0x00000060&((data)<<5))
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_sclkg_dbuf(data)                            (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_dummy_3_0(data)                             (0x0000000F&(data))
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_get_sclkg_pll_in_sel(data)                  ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_get_sclkg_oclk_sel(data)                    ((0x00000060&(data))>>5)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_get_sclkg_dbuf(data)                        ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_MN_SCLKG_CTRL_get_dummy_3_0(data)                         (0x0000000F&(data))

#define  HDMI_P3_PORT3_MN_SCLKG_DIVS                                             0x180B2414
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_reg_addr                                    "0xB80B2414"
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_reg                                         0xB80B2414
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_inst_addr                                   "0x00B7"
#define  set_HDMI_P3_PORT3_MN_SCLKG_DIVS_reg(data)                               (*((volatile unsigned int*)HDMI_P3_PORT3_MN_SCLKG_DIVS_reg)=data)
#define  get_HDMI_P3_PORT3_MN_SCLKG_DIVS_reg                                     (*((volatile unsigned int*)HDMI_P3_PORT3_MN_SCLKG_DIVS_reg))
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_div2_en_shift                     (7)
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_divs_shift                        (0)
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_div2_en_mask                      (0x00000080)
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_divs_mask                         (0x0000007F)
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_div2_en(data)                     (0x00000080&((data)<<7))
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_sclkg_pll_divs(data)                        (0x0000007F&(data))
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_get_sclkg_pll_div2_en(data)                 ((0x00000080&(data))>>7)
#define  HDMI_P3_PORT3_MN_SCLKG_DIVS_get_sclkg_pll_divs(data)                    (0x0000007F&(data))

#define  HDMI_P3_PORT3_MDD_CR                                                    0x180B2500
#define  HDMI_P3_PORT3_MDD_CR_reg_addr                                           "0xB80B2500"
#define  HDMI_P3_PORT3_MDD_CR_reg                                                0xB80B2500
#define  HDMI_P3_PORT3_MDD_CR_inst_addr                                          "0x00B8"
#define  set_HDMI_P3_PORT3_MDD_CR_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_MDD_CR_reg)=data)
#define  get_HDMI_P3_PORT3_MDD_CR_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_MDD_CR_reg))
#define  HDMI_P3_PORT3_MDD_CR_dummy_16_8_shift                                   (8)
#define  HDMI_P3_PORT3_MDD_CR_dummy_7_5_shift                                    (5)
#define  HDMI_P3_PORT3_MDD_CR_det_con_shift                                      (4)
#define  HDMI_P3_PORT3_MDD_CR_irq_det_chg_en_shift                               (3)
#define  HDMI_P3_PORT3_MDD_CR_dummy_2_1_shift                                    (1)
#define  HDMI_P3_PORT3_MDD_CR_en_shift                                           (0)
#define  HDMI_P3_PORT3_MDD_CR_dummy_16_8_mask                                    (0x0001FF00)
#define  HDMI_P3_PORT3_MDD_CR_dummy_7_5_mask                                     (0x000000E0)
#define  HDMI_P3_PORT3_MDD_CR_det_con_mask                                       (0x00000010)
#define  HDMI_P3_PORT3_MDD_CR_irq_det_chg_en_mask                                (0x00000008)
#define  HDMI_P3_PORT3_MDD_CR_dummy_2_1_mask                                     (0x00000006)
#define  HDMI_P3_PORT3_MDD_CR_en_mask                                            (0x00000001)
#define  HDMI_P3_PORT3_MDD_CR_dummy_16_8(data)                                   (0x0001FF00&((data)<<8))
#define  HDMI_P3_PORT3_MDD_CR_dummy_7_5(data)                                    (0x000000E0&((data)<<5))
#define  HDMI_P3_PORT3_MDD_CR_det_con(data)                                      (0x00000010&((data)<<4))
#define  HDMI_P3_PORT3_MDD_CR_irq_det_chg_en(data)                               (0x00000008&((data)<<3))
#define  HDMI_P3_PORT3_MDD_CR_dummy_2_1(data)                                    (0x00000006&((data)<<1))
#define  HDMI_P3_PORT3_MDD_CR_en(data)                                           (0x00000001&(data))
#define  HDMI_P3_PORT3_MDD_CR_get_dummy_16_8(data)                               ((0x0001FF00&(data))>>8)
#define  HDMI_P3_PORT3_MDD_CR_get_dummy_7_5(data)                                ((0x000000E0&(data))>>5)
#define  HDMI_P3_PORT3_MDD_CR_get_det_con(data)                                  ((0x00000010&(data))>>4)
#define  HDMI_P3_PORT3_MDD_CR_get_irq_det_chg_en(data)                           ((0x00000008&(data))>>3)
#define  HDMI_P3_PORT3_MDD_CR_get_dummy_2_1(data)                                ((0x00000006&(data))>>1)
#define  HDMI_P3_PORT3_MDD_CR_get_en(data)                                       (0x00000001&(data))

#define  HDMI_P3_PORT3_MDD_SR                                                    0x180B2504
#define  HDMI_P3_PORT3_MDD_SR_reg_addr                                           "0xB80B2504"
#define  HDMI_P3_PORT3_MDD_SR_reg                                                0xB80B2504
#define  HDMI_P3_PORT3_MDD_SR_inst_addr                                          "0x00B9"
#define  set_HDMI_P3_PORT3_MDD_SR_reg(data)                                      (*((volatile unsigned int*)HDMI_P3_PORT3_MDD_SR_reg)=data)
#define  get_HDMI_P3_PORT3_MDD_SR_reg                                            (*((volatile unsigned int*)HDMI_P3_PORT3_MDD_SR_reg))
#define  HDMI_P3_PORT3_MDD_SR_det_result_chg_shift                               (1)
#define  HDMI_P3_PORT3_MDD_SR_det_result_shift                                   (0)
#define  HDMI_P3_PORT3_MDD_SR_det_result_chg_mask                                (0x00000002)
#define  HDMI_P3_PORT3_MDD_SR_det_result_mask                                    (0x00000001)
#define  HDMI_P3_PORT3_MDD_SR_det_result_chg(data)                               (0x00000002&((data)<<1))
#define  HDMI_P3_PORT3_MDD_SR_det_result(data)                                   (0x00000001&(data))
#define  HDMI_P3_PORT3_MDD_SR_get_det_result_chg(data)                           ((0x00000002&(data))>>1)
#define  HDMI_P3_PORT3_MDD_SR_get_det_result(data)                               (0x00000001&(data))

#define  HDMI_P3_PORT3_FW_FUNC                                                   0x180B2508
#define  HDMI_P3_PORT3_FW_FUNC_reg_addr                                          "0xB80B2508"
#define  HDMI_P3_PORT3_FW_FUNC_reg                                               0xB80B2508
#define  HDMI_P3_PORT3_FW_FUNC_inst_addr                                         "0x00BA"
#define  set_HDMI_P3_PORT3_FW_FUNC_reg(data)                                     (*((volatile unsigned int*)HDMI_P3_PORT3_FW_FUNC_reg)=data)
#define  get_HDMI_P3_PORT3_FW_FUNC_reg                                           (*((volatile unsigned int*)HDMI_P3_PORT3_FW_FUNC_reg))
#define  HDMI_P3_PORT3_FW_FUNC_application_shift                                 (0)
#define  HDMI_P3_PORT3_FW_FUNC_application_mask                                  (0xFFFFFFFF)
#define  HDMI_P3_PORT3_FW_FUNC_application(data)                                 (0xFFFFFFFF&(data))
#define  HDMI_P3_PORT3_FW_FUNC_get_application(data)                             (0xFFFFFFFF&(data))

#define  HDMI_P3_PORT3_PORT_SWITCH                                               0x180B250C
#define  HDMI_P3_PORT3_PORT_SWITCH_reg_addr                                      "0xB80B250C"
#define  HDMI_P3_PORT3_PORT_SWITCH_reg                                           0xB80B250C
#define  HDMI_P3_PORT3_PORT_SWITCH_inst_addr                                     "0x00BB"
#define  set_HDMI_P3_PORT3_PORT_SWITCH_reg(data)                                 (*((volatile unsigned int*)HDMI_P3_PORT3_PORT_SWITCH_reg)=data)
#define  get_HDMI_P3_PORT3_PORT_SWITCH_reg                                       (*((volatile unsigned int*)HDMI_P3_PORT3_PORT_SWITCH_reg))
#define  HDMI_P3_PORT3_PORT_SWITCH_port_sel_shift                                (2)
#define  HDMI_P3_PORT3_PORT_SWITCH_offms_port_sel_shift                          (0)
#define  HDMI_P3_PORT3_PORT_SWITCH_port_sel_mask                                 (0x0000000C)
#define  HDMI_P3_PORT3_PORT_SWITCH_offms_port_sel_mask                           (0x00000003)
#define  HDMI_P3_PORT3_PORT_SWITCH_port_sel(data)                                (0x0000000C&((data)<<2))
#define  HDMI_P3_PORT3_PORT_SWITCH_offms_port_sel(data)                          (0x00000003&(data))
#define  HDMI_P3_PORT3_PORT_SWITCH_get_port_sel(data)                            ((0x0000000C&(data))>>2)
#define  HDMI_P3_PORT3_PORT_SWITCH_get_offms_port_sel(data)                      (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HDMI_P3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tmm:1;
        RBus_UInt32  mt:3;
        RBus_UInt32  ncp:4;
    };
}hdmi_p3_port3_tmds_msr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  tms:1;
        RBus_UInt32  mrs:2;
        RBus_UInt32  ms:2;
        RBus_UInt32  ctc:1;
        RBus_UInt32  vmr:7;
    };
}hdmi_p3_port3_tmds_msr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  crc_r_en:1;
        RBus_UInt32  crc_g_en:1;
        RBus_UInt32  crc_b_en:1;
        RBus_UInt32  crc_done:1;
        RBus_UInt32  crc_nonstable:1;
        RBus_UInt32  crcts:2;
        RBus_UInt32  crcc:1;
    };
}hdmi_p3_port3_tmds_crcc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  crcob2_3:8;
        RBus_UInt32  crcob2_2:8;
        RBus_UInt32  crcob2_1:8;
    };
}hdmi_p3_port3_tmds_crco0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  crcob2_6:8;
        RBus_UInt32  crcob2_5:8;
        RBus_UInt32  crcob2_4:8;
    };
}hdmi_p3_port3_tmds_crco1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bcd:1;
        RBus_UInt32  gcd:1;
        RBus_UInt32  rcd:1;
        RBus_UInt32  ho:1;
        RBus_UInt32  yo:1;
        RBus_UInt32  dummy180b2014_2_0:3;
    };
}hdmi_p3_port3_tmds_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  trcoe_r:1;
        RBus_UInt32  tgcoe_r:1;
        RBus_UInt32  tbcoe_r:1;
        RBus_UInt32  ocke_r:1;
        RBus_UInt32  aoe:1;
        RBus_UInt32  trcoe:1;
        RBus_UInt32  tgcoe:1;
        RBus_UInt32  tbcoe:1;
        RBus_UInt32  ocke:1;
        RBus_UInt32  ockie:1;
        RBus_UInt32  focke:1;
        RBus_UInt32  cbus_dbg_cke:1;
        RBus_UInt32  dummy180b2018_1:1;
        RBus_UInt32  dummy180b2018_0:1;
    };
}hdmi_p3_port3_tmds_outctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ecc_r:1;
        RBus_UInt32  erip_r:1;
        RBus_UInt32  egip_r:1;
        RBus_UInt32  ebip_r:1;
        RBus_UInt32  dummy180b201c_27_10:18;
        RBus_UInt32  video_preamble_off_en:1;
        RBus_UInt32  hs_width_sel:1;
        RBus_UInt32  deo:1;
        RBus_UInt32  brcw:1;
        RBus_UInt32  pnsw:1;
        RBus_UInt32  iccaf:1;
        RBus_UInt32  ecc:1;
        RBus_UInt32  erip:1;
        RBus_UInt32  egip:1;
        RBus_UInt32  ebip:1;
    };
}hdmi_p3_port3_tmds_pwdctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  hde:1;
    };
}hdmi_p3_port3_tmds_z0cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pll_div2_en:1;
        RBus_UInt32  no_clk_in:1;
        RBus_UInt32  clkv_meas_sel:2;
        RBus_UInt32  de_inv_disable:1;
        RBus_UInt32  de_err_pulse_en:1;
        RBus_UInt32  clr_infoframe_dvi:1;
        RBus_UInt32  auto_dvi2hdmi:1;
        RBus_UInt32  dummy180b2024_1_0:2;
    };
}hdmi_p3_port3_tmds_cps_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  debug_sel:6;
        RBus_UInt32  dummy180b2028_3:1;
        RBus_UInt32  cptest:1;
        RBus_UInt32  hmtm:2;
    };
}hdmi_p3_port3_tmds_udc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  nl:3;
    };
}hdmi_p3_port3_tmds_errc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tmds_bypass:1;
        RBus_UInt32  dummy180b2030_6_0:7;
    };
}hdmi_p3_port3_tmds_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tmds_rout_h:8;
        RBus_UInt32  tmds_rout_l:8;
    };
}hdmi_p3_port3_tmds_rout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tmds_gout_h:8;
        RBus_UInt32  tmds_gout_l:8;
    };
}hdmi_p3_port3_tmds_gout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tmds_bout_h:8;
        RBus_UInt32  tmds_bout_l:8;
    };
}hdmi_p3_port3_tmds_bout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dpc_pp_valid:1;
        RBus_UInt32  dpc_default_ph:1;
        RBus_UInt32  dpc_pp:4;
        RBus_UInt32  dpc_cd:4;
    };
}hdmi_p3_port3_tmds_dpc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dpc_cd_chg_flag:1;
        RBus_UInt32  dpc_cd_chg_wd_en:1;
        RBus_UInt32  dpc_cd_chg_int_en:1;
        RBus_UInt32  dummy180b2044_15_11:5;
        RBus_UInt32  dpc_auto:1;
        RBus_UInt32  dpc_pp_valid_fw:1;
        RBus_UInt32  dpc_default_ph_fw:1;
        RBus_UInt32  dpc_pp_fw:4;
        RBus_UInt32  dpc_cd_fw:4;
    };
}hdmi_p3_port3_tmds_dpc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dpc_bypass_dis:1;
        RBus_UInt32  dpc_en:1;
        RBus_UInt32  phase_errcnt_in:3;
        RBus_UInt32  phase_clrcnt_in:3;
        RBus_UInt32  phase_clr_sel:1;
    };
}hdmi_p3_port3_tmds_dpc_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  set_full_noti:4;
        RBus_UInt32  set_empty_noti:4;
    };
}hdmi_p3_port3_tmds_dpc_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fifo_errcnt_in:3;
        RBus_UInt32  clr_phase_flag:1;
        RBus_UInt32  clr_fifo_flag:1;
        RBus_UInt32  dpc_phase_ok:1;
        RBus_UInt32  dpc_phase_err_flag:1;
        RBus_UInt32  dpc_fifo_err_flag:1;
    };
}hdmi_p3_port3_tmds_dpc_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dpc_fifo_over_flag:1;
        RBus_UInt32  dpc_fifo_under_flag:1;
        RBus_UInt32  dpc_fifo_over_xflag:1;
        RBus_UInt32  dpc_fifo_under_xflag:1;
        RBus_UInt32  res2:4;
    };
}hdmi_p3_port3_tmds_dpc_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  de_sel:1;
        RBus_UInt32  tran_err_thrd:4;
        RBus_UInt32  neg_de_err_thrd:4;
        RBus_UInt32  pos_de_err_thrd:4;
        RBus_UInt32  dummy180b2058_15:1;
        RBus_UInt32  neg_de_lowbd:7;
        RBus_UInt32  dummy180b2058_7_6:2;
        RBus_UInt32  pos_de_lowbd:6;
    };
}hdmi_p3_port3_tmds_det_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  red_tran_err_flag:1;
        RBus_UInt32  grn_tran_err_flag:1;
        RBus_UInt32  blu_tran_err_flag:1;
        RBus_UInt32  red_pos_de_err_flag:1;
        RBus_UInt32  grn_pos_de_err_flag:1;
        RBus_UInt32  blu_pos_de_err_flag:1;
        RBus_UInt32  red_neg_de_err_flag:1;
        RBus_UInt32  grn_neg_de_err_flag:1;
        RBus_UInt32  blu_neg_de_err_flag:1;
    };
}hdmi_p3_port3_tmds_det_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thd:16;
        RBus_UInt32  res1:3;
        RBus_UInt32  disparity_reset_mode:1;
        RBus_UInt32  irq_en:1;
        RBus_UInt32  reset:1;
        RBus_UInt32  period:6;
        RBus_UInt32  ch_sel:2;
        RBus_UInt32  mode:1;
        RBus_UInt32  en:1;
    };
}hdmi_p3_port3_video_bit_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad_max_b:6;
        RBus_UInt32  ad_min_b:6;
        RBus_UInt32  no_dis_reset_b:1;
        RBus_UInt32  bit_err_thd_b:1;
        RBus_UInt32  bit_err_b:1;
        RBus_UInt32  bit_err_cnt_of_b:1;
        RBus_UInt32  bit_err_cnt_b:16;
    };
}hdmi_p3_port3_video_bit_err_status_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad_max_g:6;
        RBus_UInt32  ad_min_g:6;
        RBus_UInt32  no_dis_reset_g:1;
        RBus_UInt32  bit_err_thd_g:1;
        RBus_UInt32  bit_err_g:1;
        RBus_UInt32  bit_err_cnt_of_g:1;
        RBus_UInt32  bit_err_cnt_g:16;
    };
}hdmi_p3_port3_video_bit_err_status_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad_max_r:6;
        RBus_UInt32  ad_min_r:6;
        RBus_UInt32  no_dis_reset_r:1;
        RBus_UInt32  bit_err_thd_r:1;
        RBus_UInt32  bit_err_r:1;
        RBus_UInt32  bit_err_cnt_of_r:1;
        RBus_UInt32  bit_err_cnt_r:16;
    };
}hdmi_p3_port3_video_bit_err_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  terc4_thd:16;
    };
}hdmi_p3_port3_terc4_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  terc4_err_thd_b:1;
        RBus_UInt32  terc4_err_b:1;
        RBus_UInt32  terc4_err_cnt_of_b:1;
        RBus_UInt32  terc4_err_cnt_b:16;
    };
}hdmi_p3_port3_terc4_err_status_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  terc4_err_thd_g:1;
        RBus_UInt32  terc4_err_g:1;
        RBus_UInt32  terc4_err_cnt_of_g:1;
        RBus_UInt32  terc4_err_cnt_g:16;
    };
}hdmi_p3_port3_terc4_err_status_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  terc4_err_thd_r:1;
        RBus_UInt32  terc4_err_r:1;
        RBus_UInt32  terc4_err_cnt_of_r:1;
        RBus_UInt32  terc4_err_cnt_r:16;
    };
}hdmi_p3_port3_terc4_err_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  avmute_bg:1;
        RBus_UInt32  avmute:1;
        RBus_UInt32  vic:1;
        RBus_UInt32  spdiftype:1;
        RBus_UInt32  pllsts:1;
        RBus_UInt32  afifoof:1;
        RBus_UInt32  afifouf:1;
        RBus_UInt32  mode:1;
    };
}hdmi_p3_port3_hdmi_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2084_31:1;
        RBus_UInt32  dummy180b2084_30:1;
        RBus_UInt32  dummy180b2084_29:1;
        RBus_UInt32  dummy180b2084_28:1;
        RBus_UInt32  drmps_v:1;
        RBus_UInt32  mpegps_v:1;
        RBus_UInt32  aps_v:1;
        RBus_UInt32  spdps_v:1;
        RBus_UInt32  avips_v:1;
        RBus_UInt32  vsps_v:1;
        RBus_UInt32  gmps_v:1;
        RBus_UInt32  isrc1ps_v:1;
        RBus_UInt32  acpps_v:1;
        RBus_UInt32  dummy180b2084_18:1;
        RBus_UInt32  dummy180b2084_17:1;
        RBus_UInt32  dummy180b2084_16:1;
        RBus_UInt32  dummy180b2084_15:1;
        RBus_UInt32  drmps:1;
        RBus_UInt32  mpegps:1;
        RBus_UInt32  aps:1;
        RBus_UInt32  spdps:1;
        RBus_UInt32  avips:1;
        RBus_UInt32  fvsps:1;
        RBus_UInt32  vsps:1;
        RBus_UInt32  gmps:1;
        RBus_UInt32  isrc1ps:1;
        RBus_UInt32  acpps:1;
        RBus_UInt32  nps:1;
        RBus_UInt32  rsv3ps:1;
        RBus_UInt32  rsv2ps:1;
        RBus_UInt32  rsv1ps:1;
        RBus_UInt32  rsv0ps:1;
    };
}hdmi_p3_port3_hdmi_gpvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  apss:9;
    };
}hdmi_p3_port3_hdmi_psap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dpss:8;
    };
}hdmi_p3_port3_hdmi_psdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  nval:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  no_vs_det_en:1;
        RBus_UInt32  dvi_reset_ds_cm_en:1;
        RBus_UInt32  packet_ignore:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  msmode:1;
        RBus_UInt32  cabs:1;
        RBus_UInt32  fcddip:1;
    };
}hdmi_p3_port3_hdmi_scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:2;
        RBus_UInt32  spcss:1;
        RBus_UInt32  enrwe:1;
        RBus_UInt32  bche:1;
        RBus_UInt32  bches:1;
        RBus_UInt32  bches2:1;
        RBus_UInt32  pe:1;
    };
}hdmi_p3_port3_hdmi_bchcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  wd_ptg_en:1;
        RBus_UInt32  wd_vclk_en:1;
        RBus_UInt32  avmute_flag:1;
        RBus_UInt32  avmute_win_en:1;
        RBus_UInt32  aoc:1;
        RBus_UInt32  aomc:1;
        RBus_UInt32  awd:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  ampic:1;
        RBus_UInt32  vdpic:1;
        RBus_UInt32  nfpss:1;
    };
}hdmi_p3_port3_hdmi_avmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wdm:1;
        RBus_UInt32  wds:1;
        RBus_UInt32  awdch:1;
        RBus_UInt32  vwdch:1;
        RBus_UInt32  vwdap:1;
        RBus_UInt32  vwdlf:1;
        RBus_UInt32  vwdafo:1;
        RBus_UInt32  vwdafu:1;
        RBus_UInt32  yv:4;
        RBus_UInt32  awdck:1;
        RBus_UInt32  awdlf:1;
        RBus_UInt32  ch_st_sel:1;
        RBus_UInt32  vwdact:1;
        RBus_UInt32  xv:4;
        RBus_UInt32  asmfe:1;
        RBus_UInt32  load_d:1;
        RBus_UInt32  bt_track_en:1;
        RBus_UInt32  awdct:1;
        RBus_UInt32  awdap:1;
        RBus_UInt32  awdfo:1;
        RBus_UInt32  awdfu:1;
        RBus_UInt32  ct:1;
    };
}hdmi_p3_port3_hdmi_wdcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  aldbfv:1;
        RBus_UInt32  aldbfo:1;
        RBus_UInt32  aldbfu:1;
        RBus_UInt32  aldbpn:1;
    };
}hdmi_p3_port3_hdmi_dbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  awdpvsb:7;
    };
}hdmi_p3_port3_hdmi_awdsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vwdpvsb:7;
    };
}hdmi_p3_port3_hdmi_vwdsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  icpvsb:7;
    };
}hdmi_p3_port3_hdmi_pamicr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pt3:8;
        RBus_UInt32  pt2:8;
        RBus_UInt32  pt1:8;
        RBus_UInt32  pt0:8;
    };
}hdmi_p3_port3_hdmi_ptrsv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvsef:32;
    };
}hdmi_p3_port3_hdmi_pvgcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs:32;
    };
}hdmi_p3_port3_hdmi_pvsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cbus_ddc_chsel:1;
        RBus_UInt32  hdmi_field:1;
        RBus_UInt32  int_pro_chg_flag:1;
        RBus_UInt32  int_pro_chg_wd_en:1;
        RBus_UInt32  int_pro_chg_int_en:1;
        RBus_UInt32  hdcp_ddc_chsel:2;
        RBus_UInt32  iclk_sel:2;
        RBus_UInt32  csc_r:2;
        RBus_UInt32  hdirq:1;
        RBus_UInt32  csam:1;
        RBus_UInt32  csc:2;
        RBus_UInt32  field_decide_sel:1;
        RBus_UInt32  prdsam:1;
        RBus_UInt32  dsc_r:4;
        RBus_UInt32  eoi:1;
        RBus_UInt32  eot:1;
        RBus_UInt32  se:1;
        RBus_UInt32  rs:1;
        RBus_UInt32  dsc:4;
    };
}hdmi_p3_port3_hdmi_vcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  pucnr:1;
        RBus_UInt32  pucsr:1;
    };
}hdmi_p3_port3_hdmi_acrcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cts:20;
    };
}hdmi_p3_port3_hdmi_acrsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  n:20;
    };
}hdmi_p3_port3_hdmi_acrsr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cs:16;
    };
}hdmi_p3_port3_hdmi_acs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cs:24;
    };
}hdmi_p3_port3_hdmi_acs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pending:1;
        RBus_UInt32  avmute:1;
        RBus_UInt32  fifod:1;
        RBus_UInt32  act:1;
        RBus_UInt32  apll:1;
        RBus_UInt32  afifoo:1;
        RBus_UInt32  afifou:1;
        RBus_UInt32  vc:1;
    };
}hdmi_p3_port3_hdmi_intcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lo1:2;
        RBus_UInt32  lo2:2;
        RBus_UInt32  lo3:2;
        RBus_UInt32  lo4:2;
    };
}hdmi_p3_port3_hdmi_alcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  i2s_clk_en_dvi:1;
        RBus_UInt32  spdifo1:1;
        RBus_UInt32  spdifo2:1;
        RBus_UInt32  spdifo3:1;
        RBus_UInt32  spdifo4:1;
        RBus_UInt32  i2so1:1;
        RBus_UInt32  i2so2:1;
        RBus_UInt32  i2so3:1;
        RBus_UInt32  i2so4:1;
    };
}hdmi_p3_port3_hdmi_aocr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  nvlgb:1;
        RBus_UInt32  nalgb:1;
        RBus_UInt32  natgb:1;
        RBus_UInt32  ngb:1;
        RBus_UInt32  pe:1;
        RBus_UInt32  gcp:1;
    };
}hdmi_p3_port3_hdmi_bcsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  fsre:1;
        RBus_UInt32  fsif:1;
        RBus_UInt32  fscs:1;
    };
}hdmi_p3_port3_hdmi_asr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  fbif:3;
        RBus_UInt32  fbcs:4;
    };
}hdmi_p3_port3_hdmi_asr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  hvf:3;
        RBus_UInt32  hdmi_vic:8;
    };
}hdmi_p3_port3_hdmi_video_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hdmi_3d_ext_data:4;
        RBus_UInt32  hdmi_3d_metadata_type:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  hdmi_3d_meta_present:1;
        RBus_UInt32  res3:3;
    };
}hdmi_p3_port3_hdmi_3d_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  info_3d_preferred2dview:2;
        RBus_UInt32  info_3d_viewdependency:2;
        RBus_UInt32  info_3d_dualview:1;
        RBus_UInt32  info_3d_additionalinfo_present:1;
        RBus_UInt32  info_3d_f_ext_data:4;
        RBus_UInt32  info_3d_f_structure:4;
        RBus_UInt32  info_3d_valid:1;
    };
}hdmi_p3_port3_hdmi_fvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  static_metadata_descriptor_id:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  eotf:3;
    };
}hdmi_p3_port3_hdmi_drm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  en_ncts_chg_irq:1;
        RBus_UInt32  ncts_chg_irq:1;
        RBus_UInt32  en_ch_status_chg_irq:1;
        RBus_UInt32  ch_status_chg_irq:1;
    };
}hdmi_p3_port3_audio_sample_rate_change_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  hbr_audio_mode_manual:1;
        RBus_UInt32  hbr_audio_mode_fw:1;
        RBus_UInt32  hbr_audio_mode:1;
    };
}hdmi_p3_port3_high_bit_rate_audio_packet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2108_31_14:18;
        RBus_UInt32  gain_bypass_en:1;
        RBus_UInt32  afifof:1;
        RBus_UInt32  afifoe:1;
        RBus_UInt32  afifowe_r:1;
        RBus_UInt32  afifore_r:2;
        RBus_UInt32  tst_i2s_sw:1;
        RBus_UInt32  aoem:1;
        RBus_UInt32  aoc:1;
        RBus_UInt32  audio_test_enable:1;
        RBus_UInt32  mgc:1;
        RBus_UInt32  afifowe:1;
        RBus_UInt32  afifore:2;
    };
}hdmi_p3_port3_hdmi_afcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  audio_bist_clksel:1;
    };
}hdmi_p3_port3_hdmi_afsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agi:3;
        RBus_UInt32  agd:5;
        RBus_UInt32  mg:8;
    };
}hdmi_p3_port3_hdmi_magcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ldp_time:10;
        RBus_UInt32  ldp_time_mode:1;
        RBus_UInt32  fg_r:8;
        RBus_UInt32  fg_l:8;
        RBus_UInt32  auto_dly_mod:1;
        RBus_UInt32  fg_en:1;
        RBus_UInt32  ffg_l:1;
        RBus_UInt32  ffg_r:1;
    };
}hdmi_p3_port3_hdmi_mag_m_final_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  zcd_ch7_done:1;
        RBus_UInt32  zcd_ch6_done:1;
        RBus_UInt32  zcd_ch5_done:1;
        RBus_UInt32  zcd_ch4_done:1;
        RBus_UInt32  zcd_ch3_done:1;
        RBus_UInt32  zcd_ch2_done:1;
        RBus_UInt32  zcd_ch1_done:1;
        RBus_UInt32  zcd_ch0_done:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  zcd_timeout:7;
        RBus_UInt32  zcd_en:1;
        RBus_UInt32  zcd_sep_8ch:1;
        RBus_UInt32  zcd_sep_st:1;
        RBus_UInt32  dummy180b2118_4_0:5;
    };
}hdmi_p3_port3_zcd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xtal_div:8;
        RBus_UInt32  afreq_meas_result:12;
        RBus_UInt32  afreq_meas_range:3;
        RBus_UInt32  popup_afreq_meas_result:1;
        RBus_UInt32  audio_freq_detect:1;
        RBus_UInt32  auto_load_scode:1;
        RBus_UInt32  awd_by_freqchange:1;
        RBus_UInt32  awd_by_noaudio:1;
        RBus_UInt32  irq_by_freqchange:1;
        RBus_UInt32  irq_by_noaudio:1;
        RBus_UInt32  freqchange:1;
        RBus_UInt32  noaudio:1;
    };
}hdmi_p3_port3_audio_freqdet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  range0_th:12;
        RBus_UInt32  range1_th:12;
    };
}hdmi_p3_port3_range0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  range2_th:12;
        RBus_UInt32  range3_th:12;
    };
}hdmi_p3_port3_range2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  range4_th:12;
        RBus_UInt32  range5_th:12;
    };
}hdmi_p3_port3_range4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_set_s1_code3:1;
        RBus_UInt32  pre_set_s_code3:7;
        RBus_UInt32  pre_set_s1_code2:1;
        RBus_UInt32  pre_set_s_code2:7;
        RBus_UInt32  pre_set_s1_code1:1;
        RBus_UInt32  pre_set_s_code1:7;
        RBus_UInt32  pre_set_s1_code0:1;
        RBus_UInt32  pre_set_s_code0:7;
    };
}hdmi_p3_port3_preset_s_code0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dp_abuf_wr_mod_en:1;
        RBus_UInt32  auto_stop_trk_en:1;
        RBus_UInt32  trk_mod_en:1;
        RBus_UInt32  afsm_mod_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pre_set_sm_code0:1;
        RBus_UInt32  pre_set_sm_code1:1;
        RBus_UInt32  pre_set_sm_code2:1;
        RBus_UInt32  pre_set_sm_code3:1;
        RBus_UInt32  pre_set_sm_code4:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pre_set_s1_code4:1;
        RBus_UInt32  pre_set_s_code4:7;
    };
}hdmi_p3_port3_preset_s_code1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs7_rxen:1;
    };
}hdmi_p3_port3_prbs_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs7_rxen:1;
    };
}hdmi_p3_port3_prbs_g_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs7_rxen:1;
    };
}hdmi_p3_port3_prbs_b_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cmp_err_flag:1;
        RBus_UInt32  cmp_err_wd_en:1;
        RBus_UInt32  cmp_err_int_en:1;
        RBus_UInt32  preamble:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  cmp_value:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  dvi_mode_sel:1;
        RBus_UInt32  channel_sel:2;
        RBus_UInt32  lgb_cal_conti:1;
        RBus_UInt32  lgb_cal_en:1;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_err_cnt:16;
        RBus_UInt32  cmp_times:16;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_times_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  preamble_cmp_cnt:16;
        RBus_UInt32  preamble_cmp_cnt_by_frame:16;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cts_over_flag:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  cts_clip_en:1;
        RBus_UInt32  cts_up_bound:20;
    };
}hdmi_p3_port3_audio_cts_up_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cts_under_flag:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  cts_low_bound:20;
    };
}hdmi_p3_port3_audio_cts_low_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_over_flag:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  n_clip_en:1;
        RBus_UInt32  n_up_bound:20;
    };
}hdmi_p3_port3_audio_n_up_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_under_flag:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  n_low_bound:20;
    };
}hdmi_p3_port3_audio_n_low_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hporch_offset:10;
        RBus_UInt32  dummy180b215c_15_14:2;
        RBus_UInt32  en_packet_retiming_vsrst:1;
        RBus_UInt32  pp_mode_output:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  packet_mhl_en:1;
        RBus_UInt32  xor_pixel_sel:3;
        RBus_UInt32  cal_pixel_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ch_dec_pp_mode_en:1;
    };
}hdmi_p3_port3_mhl_hdmi_mac_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  mhl_3d_fmt:4;
        RBus_UInt32  mhl_vid:2;
        RBus_UInt32  oui:24;
    };
}hdmi_p3_port3_mhl_3d_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  mhl_hev_fmt:2;
        RBus_UInt32  sep_aud:1;
        RBus_UInt32  mhl_hev_fmt_type:16;
    };
}hdmi_p3_port3_mhl_3p0_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  acrfs_div:3;
        RBus_UInt32  av_delay_dir:1;
        RBus_UInt32  av_delay_sync:20;
    };
}hdmi_p3_port3_mhl_3p0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  yuv420_ls3:1;
        RBus_UInt32  yuv420_ls2:1;
        RBus_UInt32  yuv420_ls1:1;
        RBus_UInt32  yuv420_ls0:1;
        RBus_UInt32  hdcp_2p2_ls1:1;
        RBus_UInt32  hdcp_2p2_ls0:1;
        RBus_UInt32  hdcp_ksvfifo_ls:1;
        RBus_UInt32  hdcp_ls:1;
        RBus_UInt32  audio_ls:1;
    };
}hdmi_p3_port3_light_sleep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  yuv420_rm3:4;
        RBus_UInt32  yuv420_rm2:4;
        RBus_UInt32  yuv420_rm1:4;
        RBus_UInt32  yuv420_rm0:4;
    };
}hdmi_p3_port3_read_margin2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  yuv420_rme3:1;
        RBus_UInt32  yuv420_rme2:1;
        RBus_UInt32  yuv420_rme1:1;
        RBus_UInt32  yuv420_rme0:1;
        RBus_UInt32  hdcp_2p2_rme1:1;
        RBus_UInt32  hdcp_2p2_rme0:1;
        RBus_UInt32  hdcp_ksvfifo_rme:1;
        RBus_UInt32  hdcp_rme:1;
        RBus_UInt32  audio_rme:1;
    };
}hdmi_p3_port3_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hdcp_2p2_rm1:4;
        RBus_UInt32  hdcp_2p2_rm0:4;
        RBus_UInt32  hdcp_ksvfifo_rm:4;
        RBus_UInt32  hdcp_rm:4;
        RBus_UInt32  audio_rm:4;
    };
}hdmi_p3_port3_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_bist_en:1;
        RBus_UInt32  hdcp_2p2_bist_en:1;
        RBus_UInt32  hdcp_ksvfifo_bist_en:1;
        RBus_UInt32  hdcp_bist_en:1;
        RBus_UInt32  audio_bist_en:1;
    };
}hdmi_p3_port3_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_bist_done:1;
        RBus_UInt32  hdcp_2p2_bist_done:1;
        RBus_UInt32  hdcp_ksvfifo_bist_done:1;
        RBus_UInt32  hdcp_bist_done:1;
        RBus_UInt32  audio_bist_done:1;
    };
}hdmi_p3_port3_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_bist_fail:1;
        RBus_UInt32  hdcp_2p2_bist_fail:1;
        RBus_UInt32  hdcp_ksvfifo_bist_fail:1;
        RBus_UInt32  hdcp_bist_fail:1;
        RBus_UInt32  audio_bist_fail:1;
    };
}hdmi_p3_port3_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_drf_mode:1;
        RBus_UInt32  hdcp_2p2_drf_mode:1;
        RBus_UInt32  hdcp_ksvfifo_drf_mode:1;
        RBus_UInt32  hdcp_drf_mode:1;
        RBus_UInt32  audio_drf_mode:1;
    };
}hdmi_p3_port3_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_drf_resume:1;
        RBus_UInt32  hdcp_2p2_drf_resume:1;
        RBus_UInt32  hdcp_ksvfifo_drf_resume:1;
        RBus_UInt32  hdcp_drf_resume:1;
        RBus_UInt32  audio_drf_resume:1;
    };
}hdmi_p3_port3_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_drf_done:1;
        RBus_UInt32  hdcp_2p2_drf_done:1;
        RBus_UInt32  hdcp_ksvfifo_drf_done:1;
        RBus_UInt32  hdcp_drf_done:1;
        RBus_UInt32  audio_drf_done:1;
    };
}hdmi_p3_port3_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_drf_pause:1;
        RBus_UInt32  hdcp_2p2_drf_pause:1;
        RBus_UInt32  hdcp_ksvfifo_drf_pause:1;
        RBus_UInt32  hdcp_drf_pause:1;
        RBus_UInt32  audio_drf_pause:1;
    };
}hdmi_p3_port3_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  yuv420_drf_fail:1;
        RBus_UInt32  hdcp_2p2_drf_fail:1;
        RBus_UInt32  hdcp_ksvfifo_drf_fail:1;
        RBus_UInt32  hdcp_drf_fail:1;
        RBus_UInt32  audio_drf_fail:1;
    };
}hdmi_p3_port3_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  port3_r_flush:1;
        RBus_UInt32  port3_r_afifo_en:1;
        RBus_UInt32  port3_g_flush:1;
        RBus_UInt32  port3_g_afifo_en:1;
        RBus_UInt32  port3_b_flush:1;
        RBus_UInt32  port3_b_afifo_en:1;
        RBus_UInt32  dummy180b219c_20:1;
        RBus_UInt32  port2_r_flush:1;
        RBus_UInt32  port2_r_afifo_en:1;
        RBus_UInt32  port2_g_flush:1;
        RBus_UInt32  port2_g_afifo_en:1;
        RBus_UInt32  port2_b_flush:1;
        RBus_UInt32  port2_b_afifo_en:1;
        RBus_UInt32  dummy180b219c_13:1;
        RBus_UInt32  port1_r_flush:1;
        RBus_UInt32  port1_r_afifo_en:1;
        RBus_UInt32  port1_g_flush:1;
        RBus_UInt32  port1_g_afifo_en:1;
        RBus_UInt32  port1_b_flush:1;
        RBus_UInt32  port1_b_afifo_en:1;
        RBus_UInt32  dummy180b219c_6:1;
        RBus_UInt32  port0_r_flush:1;
        RBus_UInt32  port0_r_afifo_en:1;
        RBus_UInt32  port0_g_flush:1;
        RBus_UInt32  port0_g_afifo_en:1;
        RBus_UInt32  port0_b_flush:1;
        RBus_UInt32  port0_b_afifo_en:1;
    };
}hdmi_p3_port3_phy_fifo_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  port3_rclk_inv:1;
        RBus_UInt32  port3_gclk_inv:1;
        RBus_UInt32  port3_bclk_inv:1;
        RBus_UInt32  port2_rclk_inv:1;
        RBus_UInt32  port2_gclk_inv:1;
        RBus_UInt32  port2_bclk_inv:1;
        RBus_UInt32  port1_rclk_inv:1;
        RBus_UInt32  port1_gclk_inv:1;
        RBus_UInt32  port1_bclk_inv:1;
        RBus_UInt32  port0_rclk_inv:1;
        RBus_UInt32  port0_gclk_inv:1;
        RBus_UInt32  port0_bclk_inv:1;
    };
}hdmi_p3_port3_phy_fifo_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  port1_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_r_wovflow_flag:1;
        RBus_UInt32  port1_r_rudflow_flag:1;
        RBus_UInt32  port1_r_rflush_flag:1;
        RBus_UInt32  port1_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_g_wovflow_flag:1;
        RBus_UInt32  port1_g_rudflow_flag:1;
        RBus_UInt32  port1_g_rflush_flag:1;
        RBus_UInt32  port1_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_b_wovflow_flag:1;
        RBus_UInt32  port1_b_rudflow_flag:1;
        RBus_UInt32  port1_b_rflush_flag:1;
        RBus_UInt32  port0_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port0_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_r_wovflow_flag:1;
        RBus_UInt32  port0_r_rudflow_flag:1;
        RBus_UInt32  port0_r_rflush_flag:1;
        RBus_UInt32  port0_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port0_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_g_wovflow_flag:1;
        RBus_UInt32  port0_g_rudflow_flag:1;
        RBus_UInt32  port0_g_rflush_flag:1;
        RBus_UInt32  port0_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port0_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_b_wovflow_flag:1;
        RBus_UInt32  port0_b_rudflow_flag:1;
        RBus_UInt32  port0_b_rflush_flag:1;
    };
}hdmi_p3_port3_phy_fifo_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  port3_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_r_wovflow_flag:1;
        RBus_UInt32  port3_r_rudflow_flag:1;
        RBus_UInt32  port3_r_rflush_flag:1;
        RBus_UInt32  port3_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_g_wovflow_flag:1;
        RBus_UInt32  port3_g_rudflow_flag:1;
        RBus_UInt32  port3_g_rflush_flag:1;
        RBus_UInt32  port3_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_b_wovflow_flag:1;
        RBus_UInt32  port3_b_rudflow_flag:1;
        RBus_UInt32  port3_b_rflush_flag:1;
        RBus_UInt32  port2_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port2_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_r_wovflow_flag:1;
        RBus_UInt32  port2_r_rudflow_flag:1;
        RBus_UInt32  port2_r_rflush_flag:1;
        RBus_UInt32  port2_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port2_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_g_wovflow_flag:1;
        RBus_UInt32  port2_g_rudflow_flag:1;
        RBus_UInt32  port2_g_rflush_flag:1;
        RBus_UInt32  port2_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port2_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_b_wovflow_flag:1;
        RBus_UInt32  port2_b_rudflow_flag:1;
        RBus_UInt32  port2_b_rflush_flag:1;
    };
}hdmi_p3_port3_phy_fifo_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_r:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_r:1;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_g:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_g:1;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_b:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_b:1;
        RBus_UInt32  dfe_rstn_n:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  hdmi_2x_out_sel:2;
        RBus_UInt32  hdmi_test_sel:4;
        RBus_UInt32  hdmi_out_sel:1;
        RBus_UInt32  force_ctsfifo_rstn_hdmi:1;
        RBus_UInt32  en_ctsfifo_vsrst_hdmi:1;
        RBus_UInt32  en_ctsfifo_bypass_hdmi:1;
    };
}hdmi_p3_port3_hdmi_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  r_ch_afifo_en:1;
        RBus_UInt32  g_ch_afifo_en:1;
        RBus_UInt32  b_ch_afifo_en:1;
        RBus_UInt32  ch_sync_sel:2;
        RBus_UInt32  dummy180b21b0_19_17:3;
        RBus_UInt32  rden_thr:5;
        RBus_UInt32  dummy180b21b0_11_9:3;
        RBus_UInt32  udwater_thr:5;
        RBus_UInt32  dummy180b21b0_3_2:2;
        RBus_UInt32  flush:1;
        RBus_UInt32  ch_afifo_irq_en:1;
    };
}hdmi_p3_port3_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rgb_de_align_flag:1;
        RBus_UInt32  r_rwclk_det_timeout_flag:1;
        RBus_UInt32  r_wrclk_det_timeout_flag:1;
        RBus_UInt32  g_rwclk_det_timeout_flag:1;
        RBus_UInt32  g_wrclk_det_timeout_flag:1;
        RBus_UInt32  b_rwclk_det_timeout_flag:1;
        RBus_UInt32  b_wrclk_det_timeout_flag:1;
        RBus_UInt32  r_rudflow_flag:1;
        RBus_UInt32  r_wovflow_flag:1;
        RBus_UInt32  r_rflush_flag:1;
        RBus_UInt32  r_rw_water_lv:5;
        RBus_UInt32  g_rudflow_flag:1;
        RBus_UInt32  g_wovflow_flag:1;
        RBus_UInt32  g_rflush_flag:1;
        RBus_UInt32  g_rw_water_lv:5;
        RBus_UInt32  b_rudflow_flag:1;
        RBus_UInt32  b_wovflow_flag:1;
        RBus_UInt32  b_rflush_flag:1;
        RBus_UInt32  b_rw_water_lv:5;
    };
}hdmi_p3_port3_ch_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  gating_en:1;
        RBus_UInt32  ctr_char_num:7;
        RBus_UInt32  hdmi_2p0_en:1;
    };
}hdmi_p3_port3_hdmi_2p0_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  char_lock:1;
        RBus_UInt32  uscr_fall_bound_err_r:1;
        RBus_UInt32  uscr_fall_bound_err_g:1;
        RBus_UInt32  uscr_fall_bound_err_b:1;
        RBus_UInt32  uscr_per_glitch_r:1;
        RBus_UInt32  uscr_per_glitch_g:1;
        RBus_UInt32  uscr_per_glitch_b:1;
        RBus_UInt32  uscr_char_flag_r:1;
        RBus_UInt32  uscr_char_flag_g:1;
        RBus_UInt32  uscr_char_flag_b:1;
        RBus_UInt32  uscr_num:4;
        RBus_UInt32  dummy180b21bc_3_2:2;
        RBus_UInt32  scr_en_fw:1;
        RBus_UInt32  scr_auto:1;
    };
}hdmi_p3_port3_scr_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ch_locked_reset:1;
        RBus_UInt32  ch2_over_max_err_num:1;
        RBus_UInt32  ch1_over_max_err_num:1;
        RBus_UInt32  ch0_over_max_err_num:1;
        RBus_UInt32  max_err_num:10;
        RBus_UInt32  valid_reset:1;
        RBus_UInt32  reset_err_det:1;
        RBus_UInt32  keep_err_det:1;
        RBus_UInt32  refer_implem:1;
        RBus_UInt32  reset:1;
        RBus_UInt32  period:6;
        RBus_UInt32  dummy180b21c0_3_2:2;
        RBus_UInt32  mode:1;
        RBus_UInt32  en:1;
    };
}hdmi_p3_port3_cercr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt1_video:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  err_cnt0_video:15;
    };
}hdmi_p3_port3_cersr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt0_pkt:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  err_cnt2_video:15;
    };
}hdmi_p3_port3_cersr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt2_pkt:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  err_cnt1_pkt:15;
    };
}hdmi_p3_port3_cersr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt1_ctr:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  err_cnt0_ctr:15;
    };
}hdmi_p3_port3_cersr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  err_cnt2_ctr:15;
    };
}hdmi_p3_port3_cersr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  fifo_over_flag:1;
        RBus_UInt32  fifo_under_flag:1;
        RBus_UInt32  en:1;
    };
}hdmi_p3_port3_yuv420_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  scdc_reset:1;
        RBus_UInt32  dummy180b21dc_4_2:3;
        RBus_UInt32  maddf:1;
        RBus_UInt32  scdc_en:1;
    };
}hdmi_p3_port3_scdc_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timeout_flag:1;
        RBus_UInt32  timeout_sel:2;
        RBus_UInt32  status_flag:1;
        RBus_UInt32  config_flag:1;
        RBus_UInt32  scrambler_status_flag:1;
        RBus_UInt32  tmds_config_flag:1;
        RBus_UInt32  i2c_scl_dly_sel:4;
        RBus_UInt32  i2c_sda_dly_sel:4;
        RBus_UInt32  i2c_free_num:7;
        RBus_UInt32  rr_retry_sel:2;
        RBus_UInt32  dbnc_level_sel:1;
        RBus_UInt32  dummy180b21e0_6_3:4;
        RBus_UInt32  test_rr_added_delay_sel:2;
        RBus_UInt32  apai:1;
    };
}hdmi_p3_port3_scdc_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ap1:8;
    };
}hdmi_p3_port3_scdc_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dp1:8;
    };
}hdmi_p3_port3_scdc_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clock_det_en:1;
    };
}hdmi_p3_port3_acdrclkdetcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  en_tmds_chg_irq:1;
        RBus_UInt32  tmds_chg_irq:1;
        RBus_UInt32  dummy180b21f0_3_2:2;
        RBus_UInt32  clk_not_in_target_irq_en:1;
        RBus_UInt32  clk_not_in_target:1;
    };
}hdmi_p3_port3_acdrclkdetsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_cnt_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_cnt_end:12;
    };
}hdmi_p3_port3_acdrclk_setting_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  target_for_maximum_clk_counter:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  target_for_minimum_clk_counter:12;
    };
}hdmi_p3_port3_acdrclk_setting_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  clk_counter_err_threshold:4;
        RBus_UInt32  clk_counter_debounce:8;
    };
}hdmi_p3_port3_acdrclk_setting_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}hdmi_p3_port3_hdcp_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  namfe:1;
        RBus_UInt32  rpt:1;
        RBus_UInt32  ivsp:1;
        RBus_UInt32  invvs:1;
        RBus_UInt32  ivspm:1;
        RBus_UInt32  maddf:1;
        RBus_UInt32  dkapde:1;
        RBus_UInt32  hdcp_en:1;
    };
}hdmi_p3_port3_hdcp_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dkap:8;
    };
}hdmi_p3_port3_hdcp_dkap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  iic_st:3;
        RBus_UInt32  i2c_scl_dly_sel:4;
        RBus_UInt32  i2c_sda_dly_sel:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  tune_up_down:1;
        RBus_UInt32  tune_range:7;
        RBus_UInt32  ddcdbnc:1;
        RBus_UInt32  dvi_enc_mode:1;
        RBus_UInt32  dbnc_level_sel:1;
        RBus_UInt32  km_clk_sel:1;
        RBus_UInt32  hdcp_vs_sel:1;
        RBus_UInt32  enc_tog:1;
        RBus_UInt32  avmute_dis:1;
        RBus_UInt32  km_start_sel:1;
        RBus_UInt32  apai_type:1;
        RBus_UInt32  apai:1;
    };
}hdmi_p3_port3_hdcp_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  akm_flag:1;
        RBus_UInt32  adne_flag:1;
        RBus_UInt32  ence_flag:1;
        RBus_UInt32  nc_flag:1;
        RBus_UInt32  wr_aksv_flag:1;
        RBus_UInt32  rd_ri_flag:1;
        RBus_UInt32  rd_bksv_flag:1;
        RBus_UInt32  dummy180b2210_1_0:2;
    };
}hdmi_p3_port3_hdcp_flag1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  irq_akm_en:1;
        RBus_UInt32  irq_adne_en:1;
        RBus_UInt32  irq_ence_en:1;
        RBus_UInt32  irq_nc_en:1;
        RBus_UInt32  irq_aksv_en:1;
        RBus_UInt32  irq_ri_en:1;
        RBus_UInt32  irq_bksv_en:1;
        RBus_UInt32  dummy180b2214_1_0:2;
    };
}hdmi_p3_port3_hdcp_flag2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  ksvfifo_status:1;
        RBus_UInt32  dp_ksvfifo_ptr:10;
        RBus_UInt32  ap1:8;
    };
}hdmi_p3_port3_hdcp_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dp1:8;
    };
}hdmi_p3_port3_hdcp_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2220_31_27:5;
        RBus_UInt32  fn_auto_inc:1;
        RBus_UInt32  apply_cp_fn:1;
        RBus_UInt32  ks_encoded:1;
        RBus_UInt32  switch_state:12;
        RBus_UInt32  rpt_thr_unauth:1;
        RBus_UInt32  fw_mode_riv:1;
        RBus_UInt32  apply_state:1;
        RBus_UInt32  mspai:1;
        RBus_UInt32  new_auth_device:1;
        RBus_UInt32  verify_id_pass:1;
        RBus_UInt32  verify_id_done:1;
        RBus_UInt32  assemble_id_fail:1;
        RBus_UInt32  downstream_done:1;
        RBus_UInt32  ks_done:1;
        RBus_UInt32  switch_unauth:1;
        RBus_UInt32  hdcp_2p2_en:1;
    };
}hdmi_p3_port3_hdcp_2p2_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  riv:32;
    };
}hdmi_p3_port3_hdcp_2p2_riv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  riv:32;
    };
}hdmi_p3_port3_hdcp_2p2_riv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  frame_number:8;
        RBus_UInt32  irq_fn_compare_fail:1;
        RBus_UInt32  irq_crc_fail:1;
        RBus_UInt32  irq_no_cp_packet:1;
        RBus_UInt32  irq_msg_overwrite:1;
        RBus_UInt32  irq_unauth_chg:1;
        RBus_UInt32  irq_state_chg:1;
        RBus_UInt32  irq_rd_msg_done:1;
        RBus_UInt32  irq_wr_msg_done:1;
        RBus_UInt32  irq_rd_msg_start:1;
        RBus_UInt32  irq_wr_msg_start:1;
        RBus_UInt32  state:12;
    };
}hdmi_p3_port3_hdcp_2p2_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  crc_fail_wd_en:1;
        RBus_UInt32  no_cp_packet_wd_en:1;
        RBus_UInt32  irq_fn_compare_fail_en:1;
        RBus_UInt32  irq_crc_fail_en:1;
        RBus_UInt32  irq_no_cp_packet_en:1;
        RBus_UInt32  irq_msg_overwrite_en:1;
        RBus_UInt32  irq_unauth_chg_en:1;
        RBus_UInt32  irq_state_chg_en:1;
        RBus_UInt32  irq_rd_msg_done_en:1;
        RBus_UInt32  irq_wr_msg_done_en:1;
        RBus_UInt32  irq_rd_msg_start_en:1;
        RBus_UInt32  irq_wr_msg_start_en:1;
    };
}hdmi_p3_port3_hdcp_2p2_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  ap1:10;
    };
}hdmi_p3_port3_hdcp_msap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dp1:8;
    };
}hdmi_p3_port3_hdcp_msdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  icmux:1;
        RBus_UInt32  ocs:2;
        RBus_UInt32  dbdcb:1;
        RBus_UInt32  dummy180b2300_3_0:4;
    };
}hdmi_p3_port3_hdmi_cmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy180b2304_7_0:8;
    };
}hdmi_p3_port3_hdmi_mcapr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  s1_code_msb_r:1;
        RBus_UInt32  slc_r:1;
        RBus_UInt32  sc_r:7;
        RBus_UInt32  s1_code_msb:1;
        RBus_UInt32  slc:1;
        RBus_UInt32  sc:7;
    };
}hdmi_p3_port3_hdmi_scapr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dcaprh:8;
        RBus_UInt32  dcaprl:8;
    };
}hdmi_p3_port3_hdmi_dcapr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fdint:3;
        RBus_UInt32  etcn:1;
        RBus_UInt32  etfd:1;
        RBus_UInt32  etfbc:1;
        RBus_UInt32  pecs:2;
    };
}hdmi_p3_port3_hdmi_pscr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mfddf:8;
        RBus_UInt32  mfddr:8;
        RBus_UInt32  fddf:8;
        RBus_UInt32  fddr:8;
    };
}hdmi_p3_port3_hdmi_afdd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tl2der:2;
        RBus_UInt32  tl2def:2;
        RBus_UInt32  tt:4;
    };
}hdmi_p3_port3_hdmi_ftr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tfd:5;
        RBus_UInt32  bad:3;
    };
}hdmi_p3_port3_hdmi_fbr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ich:8;
        RBus_UInt32  icl:8;
    };
}hdmi_p3_port3_hdmi_icpsncr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pch:8;
        RBus_UInt32  pcl:8;
    };
}hdmi_p3_port3_hdmi_pcpsncr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  icth:8;
        RBus_UInt32  ictl:8;
    };
}hdmi_p3_port3_hdmi_ictpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pcth:8;
        RBus_UInt32  pctl:8;
    };
}hdmi_p3_port3_hdmi_pctpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  icbh:8;
        RBus_UInt32  icbl:8;
    };
}hdmi_p3_port3_hdmi_icbpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pcbh:8;
        RBus_UInt32  pcbl:8;
    };
}hdmi_p3_port3_hdmi_pcbpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  rm:1;
        RBus_UInt32  nt:12;
    };
}hdmi_p3_port3_hdmi_ntx1024tr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ftb:8;
    };
}hdmi_p3_port3_hdmi_stbpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ncper:8;
    };
}hdmi_p3_port3_hdmi_ncper_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  petr:8;
    };
}hdmi_p3_port3_hdmi_petr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cmvtc:1;
        RBus_UInt32  cmvbc:1;
        RBus_UInt32  ssdmou:1;
        RBus_UInt32  tef:1;
        RBus_UInt32  w1c5:1;
        RBus_UInt32  dummy180b2350_2:1;
        RBus_UInt32  esdm:1;
        RBus_UInt32  dummy180b2350_0:1;
    };
}hdmi_p3_port3_hdmi_aapnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy180b2354_7:1;
        RBus_UInt32  dummy180b2354_6:1;
        RBus_UInt32  edm:1;
        RBus_UInt32  pst:1;
        RBus_UInt32  psc:4;
    };
}hdmi_p3_port3_hdmi_apdmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fps:4;
        RBus_UInt32  sps:4;
    };
}hdmi_p3_port3_hdmi_aptmcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  plltm:1;
        RBus_UInt32  fpsd:1;
        RBus_UInt32  spsd:1;
        RBus_UInt32  nfpss:4;
    };
}hdmi_p3_port3_hdmi_aptmcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncts_disable_pe_check_en:1;
        RBus_UInt32  ncts_re_enable_off_en:1;
        RBus_UInt32  ncts_disable_pe_check_status:1;
        RBus_UInt32  ncts_disable_pe_check_irq_en:1;
        RBus_UInt32  dummy180b2360_27_20:8;
        RBus_UInt32  ncts_disable_pe_check_cnt:20;
    };
}hdmi_p3_port3_hdmi_npecr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncts_re_enable_off_start:16;
        RBus_UInt32  ncts_re_enable_off_end:16;
    };
}hdmi_p3_port3_hdmi_nror_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  over_threshold:1;
        RBus_UInt32  under_threshold:1;
        RBus_UInt32  wd_by_tmds_clk:1;
        RBus_UInt32  irq_by_tmds_clk:1;
        RBus_UInt32  nt_up_threshold:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nt_low_threshold:12;
    };
}hdmi_p3_port3_hdmi_ntx1024tr0_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_reg:2;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  dpll_bpsin:1;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_ip:3;
    };
}hdmi_p3_port3_hdmi_apllcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_seltst:2;
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  dpll_bpspsw:1;
        RBus_UInt32  dpll_wdo:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_stoppsw:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_pow:1;
    };
}hdmi_p3_port3_hdmi_apllcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dpll_reloadm:1;
    };
}hdmi_p3_port3_hdmi_apllcr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sum_c_samp:16;
    };
}hdmi_p3_port3_hdmi_apllcr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dpll_m_test:8;
        RBus_UInt32  res2:20;
        RBus_UInt32  dpll_m_db:1;
        RBus_UInt32  dpll_m_sel:1;
    };
}hdmi_p3_port3_hdmi_apll_testm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_reg:2;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  dpll_bpsin:1;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_ip:3;
    };
}hdmi_p3_port3_hdmi_vpllcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_seltst:2;
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dpll_ldo_pow:1;
        RBus_UInt32  dpll_ldo_sel:2;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  dpll_bpspsw:1;
        RBus_UInt32  dpll_wdo:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_stoppsw:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_pow:1;
    };
}hdmi_p3_port3_hdmi_vpllcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dpll_reloadm:1;
    };
}hdmi_p3_port3_hdmi_vpllcr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sclkg_pll_in_sel:1;
        RBus_UInt32  sclkg_oclk_sel:2;
        RBus_UInt32  sclkg_dbuf:1;
        RBus_UInt32  dummy180b2410_3_0:4;
    };
}hdmi_p3_port3_mn_sclkg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sclkg_pll_div2_en:1;
        RBus_UInt32  sclkg_pll_divs:7;
    };
}hdmi_p3_port3_mn_sclkg_divs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dummy180b2500_16_8:9;
        RBus_UInt32  dummy180b2500_7_5:3;
        RBus_UInt32  det_con:1;
        RBus_UInt32  irq_det_chg_en:1;
        RBus_UInt32  dummy180b2500_2_1:2;
        RBus_UInt32  en:1;
    };
}hdmi_p3_port3_mdd_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  det_result_chg:1;
        RBus_UInt32  det_result:1;
    };
}hdmi_p3_port3_mdd_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  application:32;
    };
}hdmi_p3_port3_fw_func_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  port_sel:2;
        RBus_UInt32  offms_port_sel:2;
    };
}hdmi_p3_port3_port_switch_RBUS;

#else //apply LITTLE_ENDIAN

//======HDMI_P3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncp:4;
        RBus_UInt32  mt:3;
        RBus_UInt32  tmm:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_msr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmr:7;
        RBus_UInt32  ctc:1;
        RBus_UInt32  ms:2;
        RBus_UInt32  mrs:2;
        RBus_UInt32  tms:1;
        RBus_UInt32  res1:19;
    };
}hdmi_p3_port3_tmds_msr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crcc:1;
        RBus_UInt32  crcts:2;
        RBus_UInt32  crc_nonstable:1;
        RBus_UInt32  crc_done:1;
        RBus_UInt32  crc_b_en:1;
        RBus_UInt32  crc_g_en:1;
        RBus_UInt32  crc_r_en:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_crcc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crcob2_1:8;
        RBus_UInt32  crcob2_2:8;
        RBus_UInt32  crcob2_3:8;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_tmds_crco0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crcob2_4:8;
        RBus_UInt32  crcob2_5:8;
        RBus_UInt32  crcob2_6:8;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_tmds_crco1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2014_2_0:3;
        RBus_UInt32  yo:1;
        RBus_UInt32  ho:1;
        RBus_UInt32  rcd:1;
        RBus_UInt32  gcd:1;
        RBus_UInt32  bcd:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2018_0:1;
        RBus_UInt32  dummy180b2018_1:1;
        RBus_UInt32  cbus_dbg_cke:1;
        RBus_UInt32  focke:1;
        RBus_UInt32  ockie:1;
        RBus_UInt32  ocke:1;
        RBus_UInt32  tbcoe:1;
        RBus_UInt32  tgcoe:1;
        RBus_UInt32  trcoe:1;
        RBus_UInt32  aoe:1;
        RBus_UInt32  ocke_r:1;
        RBus_UInt32  tbcoe_r:1;
        RBus_UInt32  tgcoe_r:1;
        RBus_UInt32  trcoe_r:1;
        RBus_UInt32  res1:18;
    };
}hdmi_p3_port3_tmds_outctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ebip:1;
        RBus_UInt32  egip:1;
        RBus_UInt32  erip:1;
        RBus_UInt32  ecc:1;
        RBus_UInt32  iccaf:1;
        RBus_UInt32  pnsw:1;
        RBus_UInt32  brcw:1;
        RBus_UInt32  deo:1;
        RBus_UInt32  hs_width_sel:1;
        RBus_UInt32  video_preamble_off_en:1;
        RBus_UInt32  dummy180b201c_27:18;
        RBus_UInt32  ebip_r:1;
        RBus_UInt32  egip_r:1;
        RBus_UInt32  erip_r:1;
        RBus_UInt32  ecc_r:1;
    };
}hdmi_p3_port3_tmds_pwdctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hde:1;
        RBus_UInt32  res1:31;
    };
}hdmi_p3_port3_tmds_z0cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2024_1_0:2;
        RBus_UInt32  auto_dvi2hdmi:1;
        RBus_UInt32  clr_infoframe_dvi:1;
        RBus_UInt32  de_err_pulse_en:1;
        RBus_UInt32  de_inv_disable:1;
        RBus_UInt32  clkv_meas_sel:2;
        RBus_UInt32  no_clk_in:1;
        RBus_UInt32  pll_div2_en:1;
        RBus_UInt32  res1:22;
    };
}hdmi_p3_port3_tmds_cps_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmtm:2;
        RBus_UInt32  cptest:1;
        RBus_UInt32  dummy180b2028_3_3:1;
        RBus_UInt32  debug_sel:6;
        RBus_UInt32  res1:22;
    };
}hdmi_p3_port3_tmds_udc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nl:3;
        RBus_UInt32  res1:29;
    };
}hdmi_p3_port3_tmds_errc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2030_6_0:7;
        RBus_UInt32  tmds_bypass:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmds_rout_l:8;
        RBus_UInt32  tmds_rout_h:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_tmds_rout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmds_gout_l:8;
        RBus_UInt32  tmds_gout_h:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_tmds_gout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tmds_bout_l:8;
        RBus_UInt32  tmds_bout_h:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_tmds_bout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpc_cd:4;
        RBus_UInt32  dpc_pp:4;
        RBus_UInt32  dpc_default_ph:1;
        RBus_UInt32  dpc_pp_valid:1;
        RBus_UInt32  res1:22;
    };
}hdmi_p3_port3_tmds_dpc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpc_cd_fw:4;
        RBus_UInt32  dpc_pp_fw:4;
        RBus_UInt32  dpc_default_ph_fw:1;
        RBus_UInt32  dpc_pp_valid_fw:1;
        RBus_UInt32  dpc_auto:1;
        RBus_UInt32  dummy180b2044_15_11:5;
        RBus_UInt32  dpc_cd_chg_int_en:1;
        RBus_UInt32  dpc_cd_chg_wd_en:1;
        RBus_UInt32  dpc_cd_chg_flag:1;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_tmds_dpc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_clr_sel:1;
        RBus_UInt32  phase_clrcnt_in:3;
        RBus_UInt32  phase_errcnt_in:3;
        RBus_UInt32  dpc_en:1;
        RBus_UInt32  dpc_bypass_dis:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_tmds_dpc_set0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set_empty_noti:4;
        RBus_UInt32  set_full_noti:4;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_dpc_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpc_fifo_err_flag:1;
        RBus_UInt32  dpc_phase_err_flag:1;
        RBus_UInt32  dpc_phase_ok:1;
        RBus_UInt32  clr_fifo_flag:1;
        RBus_UInt32  clr_phase_flag:1;
        RBus_UInt32  fifo_errcnt_in:3;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_tmds_dpc_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dpc_fifo_under_xflag:1;
        RBus_UInt32  dpc_fifo_over_xflag:1;
        RBus_UInt32  dpc_fifo_under_flag:1;
        RBus_UInt32  dpc_fifo_over_flag:1;
        RBus_UInt32  res2:24;
    };
}hdmi_p3_port3_tmds_dpc_set3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_de_lowbd:6;
        RBus_UInt32  dummy180b2058_7_6:2;
        RBus_UInt32  neg_de_lowbd:7;
        RBus_UInt32  dummy180b2058_15_15:1;
        RBus_UInt32  pos_de_err_thrd:4;
        RBus_UInt32  neg_de_err_thrd:4;
        RBus_UInt32  tran_err_thrd:4;
        RBus_UInt32  de_sel:1;
        RBus_UInt32  res1:3;
    };
}hdmi_p3_port3_tmds_det_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blu_neg_de_err_flag:1;
        RBus_UInt32  grn_neg_de_err_flag:1;
        RBus_UInt32  red_neg_de_err_flag:1;
        RBus_UInt32  blu_pos_de_err_flag:1;
        RBus_UInt32  grn_pos_de_err_flag:1;
        RBus_UInt32  red_pos_de_err_flag:1;
        RBus_UInt32  blu_tran_err_flag:1;
        RBus_UInt32  grn_tran_err_flag:1;
        RBus_UInt32  red_tran_err_flag:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_tmds_det_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  ch_sel:2;
        RBus_UInt32  period:6;
        RBus_UInt32  reset:1;
        RBus_UInt32  irq_en:1;
        RBus_UInt32  disparity_reset_mode:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  thd:16;
    };
}hdmi_p3_port3_video_bit_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_err_cnt_b:16;
        RBus_UInt32  bit_err_cnt_of_b:1;
        RBus_UInt32  bit_err_b:1;
        RBus_UInt32  bit_err_thd_b:1;
        RBus_UInt32  no_dis_reset_b:1;
        RBus_UInt32  ad_min_b:6;
        RBus_UInt32  ad_max_b:6;
    };
}hdmi_p3_port3_video_bit_err_status_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_err_cnt_g:16;
        RBus_UInt32  bit_err_cnt_of_g:1;
        RBus_UInt32  bit_err_g:1;
        RBus_UInt32  bit_err_thd_g:1;
        RBus_UInt32  no_dis_reset_g:1;
        RBus_UInt32  ad_min_g:6;
        RBus_UInt32  ad_max_g:6;
    };
}hdmi_p3_port3_video_bit_err_status_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_err_cnt_r:16;
        RBus_UInt32  bit_err_cnt_of_r:1;
        RBus_UInt32  bit_err_r:1;
        RBus_UInt32  bit_err_thd_r:1;
        RBus_UInt32  no_dis_reset_r:1;
        RBus_UInt32  ad_min_r:6;
        RBus_UInt32  ad_max_r:6;
    };
}hdmi_p3_port3_video_bit_err_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  terc4_thd:16;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_terc4_err_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  terc4_err_cnt_b:16;
        RBus_UInt32  terc4_err_cnt_of_b:1;
        RBus_UInt32  terc4_err_b:1;
        RBus_UInt32  terc4_err_thd_b:1;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_terc4_err_status_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  terc4_err_cnt_g:16;
        RBus_UInt32  terc4_err_cnt_of_g:1;
        RBus_UInt32  terc4_err_g:1;
        RBus_UInt32  terc4_err_thd_g:1;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_terc4_err_status_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  terc4_err_cnt_r:16;
        RBus_UInt32  terc4_err_cnt_of_r:1;
        RBus_UInt32  terc4_err_r:1;
        RBus_UInt32  terc4_err_thd_r:1;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_terc4_err_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:1;
        RBus_UInt32  afifouf:1;
        RBus_UInt32  afifoof:1;
        RBus_UInt32  pllsts:1;
        RBus_UInt32  spdiftype:1;
        RBus_UInt32  vic:1;
        RBus_UInt32  avmute:1;
        RBus_UInt32  avmute_bg:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rsv0ps:1;
        RBus_UInt32  rsv1ps:1;
        RBus_UInt32  rsv2ps:1;
        RBus_UInt32  rsv3ps:1;
        RBus_UInt32  nps:1;
        RBus_UInt32  acpps:1;
        RBus_UInt32  isrc1ps:1;
        RBus_UInt32  gmps:1;
        RBus_UInt32  vsps:1;
        RBus_UInt32  fvsps:1;
        RBus_UInt32  avips:1;
        RBus_UInt32  spdps:1;
        RBus_UInt32  aps:1;
        RBus_UInt32  mpegps:1;
        RBus_UInt32  drmps:1;
        RBus_UInt32  dummy180b2084_15:1;
        RBus_UInt32  dummy180b2084_16:1;
        RBus_UInt32  dummy180b2084_17:1;
        RBus_UInt32  dummy180b2084_18:1;
        RBus_UInt32  acpps_v:1;
        RBus_UInt32  isrc1ps_v:1;
        RBus_UInt32  gmps_v:1;
        RBus_UInt32  vsps_v:1;
        RBus_UInt32  avips_v:1;
        RBus_UInt32  spdps_v:1;
        RBus_UInt32  aps_v:1;
        RBus_UInt32  mpegps_v:1;
        RBus_UInt32  drmps_v:1;
        RBus_UInt32  dummy180b2084_28:1;
        RBus_UInt32  dummy180b2084_29:1;
        RBus_UInt32  dummy180b2084_30:1;
        RBus_UInt32  dummy180b2084_31:1;
    };
}hdmi_p3_port3_hdmi_gpvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apss:9;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_hdmi_psap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpss:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_psdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcddip:1;
        RBus_UInt32  cabs:1;
        RBus_UInt32  msmode:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  packet_ignore:1;
        RBus_UInt32  dvi_reset_ds_cm_en:1;
        RBus_UInt32  no_vs_det_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  nval:8;
        RBus_UInt32  res2:16;
    };
}hdmi_p3_port3_hdmi_scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pe:1;
        RBus_UInt32  bches2:1;
        RBus_UInt32  bches:1;
        RBus_UInt32  bche:1;
        RBus_UInt32  enrwe:1;
        RBus_UInt32  spcss:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:24;
    };
}hdmi_p3_port3_hdmi_bchcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nfpss:1;
        RBus_UInt32  vdpic:1;
        RBus_UInt32  ampic:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  awd:1;
        RBus_UInt32  aomc:1;
        RBus_UInt32  aoc:1;
        RBus_UInt32  avmute_win_en:1;
        RBus_UInt32  avmute_flag:1;
        RBus_UInt32  wd_vclk_en:1;
        RBus_UInt32  wd_ptg_en:1;
        RBus_UInt32  res1:21;
    };
}hdmi_p3_port3_hdmi_avmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ct:1;
        RBus_UInt32  awdfu:1;
        RBus_UInt32  awdfo:1;
        RBus_UInt32  awdap:1;
        RBus_UInt32  awdct:1;
        RBus_UInt32  bt_track_en:1;
        RBus_UInt32  load_d:1;
        RBus_UInt32  asmfe:1;
        RBus_UInt32  xv:4;
        RBus_UInt32  vwdact:1;
        RBus_UInt32  ch_st_sel:1;
        RBus_UInt32  awdlf:1;
        RBus_UInt32  awdck:1;
        RBus_UInt32  yv:4;
        RBus_UInt32  vwdafu:1;
        RBus_UInt32  vwdafo:1;
        RBus_UInt32  vwdlf:1;
        RBus_UInt32  vwdap:1;
        RBus_UInt32  vwdch:1;
        RBus_UInt32  awdch:1;
        RBus_UInt32  wds:1;
        RBus_UInt32  wdm:1;
        RBus_UInt32  res1:4;
    };
}hdmi_p3_port3_hdmi_wdcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aldbpn:1;
        RBus_UInt32  aldbfu:1;
        RBus_UInt32  aldbfo:1;
        RBus_UInt32  aldbfv:1;
        RBus_UInt32  res1:28;
    };
}hdmi_p3_port3_hdmi_dbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  awdpvsb:7;
        RBus_UInt32  res1:25;
    };
}hdmi_p3_port3_hdmi_awdsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vwdpvsb:7;
        RBus_UInt32  res1:25;
    };
}hdmi_p3_port3_hdmi_vwdsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icpvsb:7;
        RBus_UInt32  res1:25;
    };
}hdmi_p3_port3_hdmi_pamicr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pt0:8;
        RBus_UInt32  pt1:8;
        RBus_UInt32  pt2:8;
        RBus_UInt32  pt3:8;
    };
}hdmi_p3_port3_hdmi_ptrsv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvsef:32;
    };
}hdmi_p3_port3_hdmi_pvgcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pvs:32;
    };
}hdmi_p3_port3_hdmi_pvsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dsc:4;
        RBus_UInt32  rs:1;
        RBus_UInt32  se:1;
        RBus_UInt32  eot:1;
        RBus_UInt32  eoi:1;
        RBus_UInt32  dsc_r:4;
        RBus_UInt32  prdsam:1;
        RBus_UInt32  field_decide_sel:1;
        RBus_UInt32  csc:2;
        RBus_UInt32  csam:1;
        RBus_UInt32  hdirq:1;
        RBus_UInt32  csc_r:2;
        RBus_UInt32  iclk_sel:2;
        RBus_UInt32  hdcp_ddc_chsel:2;
        RBus_UInt32  int_pro_chg_int_en:1;
        RBus_UInt32  int_pro_chg_wd_en:1;
        RBus_UInt32  int_pro_chg_flag:1;
        RBus_UInt32  hdmi_field:1;
        RBus_UInt32  cbus_ddc_chsel:1;
        RBus_UInt32  res1:3;
    };
}hdmi_p3_port3_hdmi_vcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pucsr:1;
        RBus_UInt32  pucnr:1;
        RBus_UInt32  res1:30;
    };
}hdmi_p3_port3_hdmi_acrcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cts:20;
        RBus_UInt32  res1:12;
    };
}hdmi_p3_port3_hdmi_acrsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n:20;
        RBus_UInt32  res1:12;
    };
}hdmi_p3_port3_hdmi_acrsr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs:16;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_acs0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs:24;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_hdmi_acs1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vc:1;
        RBus_UInt32  afifou:1;
        RBus_UInt32  afifoo:1;
        RBus_UInt32  apll:1;
        RBus_UInt32  act:1;
        RBus_UInt32  fifod:1;
        RBus_UInt32  avmute:1;
        RBus_UInt32  pending:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_intcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lo4:2;
        RBus_UInt32  lo3:2;
        RBus_UInt32  lo2:2;
        RBus_UInt32  lo1:2;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_alcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i2so4:1;
        RBus_UInt32  i2so3:1;
        RBus_UInt32  i2so2:1;
        RBus_UInt32  i2so1:1;
        RBus_UInt32  spdifo4:1;
        RBus_UInt32  spdifo3:1;
        RBus_UInt32  spdifo2:1;
        RBus_UInt32  spdifo1:1;
        RBus_UInt32  i2s_clk_en_dvi:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_hdmi_aocr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gcp:1;
        RBus_UInt32  pe:1;
        RBus_UInt32  ngb:1;
        RBus_UInt32  natgb:1;
        RBus_UInt32  nalgb:1;
        RBus_UInt32  nvlgb:1;
        RBus_UInt32  res1:26;
    };
}hdmi_p3_port3_hdmi_bcsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fscs:1;
        RBus_UInt32  fsif:1;
        RBus_UInt32  fsre:1;
        RBus_UInt32  res1:29;
    };
}hdmi_p3_port3_hdmi_asr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fbcs:4;
        RBus_UInt32  fbif:3;
        RBus_UInt32  res1:25;
    };
}hdmi_p3_port3_hdmi_asr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdmi_vic:8;
        RBus_UInt32  hvf:3;
        RBus_UInt32  res1:21;
    };
}hdmi_p3_port3_hdmi_video_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hdmi_3d_meta_present:1;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdmi_3d_metadata_type:3;
        RBus_UInt32  hdmi_3d_ext_data:4;
        RBus_UInt32  res3:16;
    };
}hdmi_p3_port3_hdmi_3d_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  info_3d_valid:1;
        RBus_UInt32  info_3d_f_structure:4;
        RBus_UInt32  info_3d_f_ext_data:4;
        RBus_UInt32  info_3d_additionalinfo_present:1;
        RBus_UInt32  info_3d_dualview:1;
        RBus_UInt32  info_3d_viewdependency:2;
        RBus_UInt32  info_3d_preferred2dview:2;
        RBus_UInt32  res1:17;
    };
}hdmi_p3_port3_hdmi_fvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eotf:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  static_metadata_descriptor_id:3;
        RBus_UInt32  res2:25;
    };
}hdmi_p3_port3_hdmi_drm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_status_chg_irq:1;
        RBus_UInt32  en_ch_status_chg_irq:1;
        RBus_UInt32  ncts_chg_irq:1;
        RBus_UInt32  en_ncts_chg_irq:1;
        RBus_UInt32  res1:28;
    };
}hdmi_p3_port3_audio_sample_rate_change_irq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hbr_audio_mode:1;
        RBus_UInt32  hbr_audio_mode_fw:1;
        RBus_UInt32  hbr_audio_mode_manual:1;
        RBus_UInt32  res1:29;
    };
}hdmi_p3_port3_high_bit_rate_audio_packet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  afifore:2;
        RBus_UInt32  afifowe:1;
        RBus_UInt32  mgc:1;
        RBus_UInt32  audio_test_enable:1;
        RBus_UInt32  aoc:1;
        RBus_UInt32  aoem:1;
        RBus_UInt32  tst_i2s_sw:1;
        RBus_UInt32  afifore_r:2;
        RBus_UInt32  afifowe_r:1;
        RBus_UInt32  afifoe:1;
        RBus_UInt32  afifof:1;
        RBus_UInt32  gain_bypass_en:1;
        RBus_UInt32  dummy180b2108_31_14:18;
    };
}hdmi_p3_port3_hdmi_afcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_clksel:1;
        RBus_UInt32  res1:31;
    };
}hdmi_p3_port3_hdmi_afsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mg:8;
        RBus_UInt32  agd:5;
        RBus_UInt32  agi:3;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_magcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ffg_r:1;
        RBus_UInt32  ffg_l:1;
        RBus_UInt32  fg_en:1;
        RBus_UInt32  auto_dly_mod:1;
        RBus_UInt32  fg_l:8;
        RBus_UInt32  fg_r:8;
        RBus_UInt32  ldp_time_mode:1;
        RBus_UInt32  ldp_time:10;
        RBus_UInt32  res1:1;
    };
}hdmi_p3_port3_hdmi_mag_m_final_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2118_4_0:5;
        RBus_UInt32  zcd_sep_st:1;
        RBus_UInt32  zcd_sep_8ch:1;
        RBus_UInt32  zcd_en:1;
        RBus_UInt32  zcd_timeout:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  zcd_ch0_done:1;
        RBus_UInt32  zcd_ch1_done:1;
        RBus_UInt32  zcd_ch2_done:1;
        RBus_UInt32  zcd_ch3_done:1;
        RBus_UInt32  zcd_ch4_done:1;
        RBus_UInt32  zcd_ch5_done:1;
        RBus_UInt32  zcd_ch6_done:1;
        RBus_UInt32  zcd_ch7_done:1;
        RBus_UInt32  res2:8;
    };
}hdmi_p3_port3_zcd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noaudio:1;
        RBus_UInt32  freqchange:1;
        RBus_UInt32  irq_by_noaudio:1;
        RBus_UInt32  irq_by_freqchange:1;
        RBus_UInt32  awd_by_noaudio:1;
        RBus_UInt32  awd_by_freqchange:1;
        RBus_UInt32  auto_load_scode:1;
        RBus_UInt32  audio_freq_detect:1;
        RBus_UInt32  popup_afreq_meas_result:1;
        RBus_UInt32  afreq_meas_range:3;
        RBus_UInt32  afreq_meas_result:12;
        RBus_UInt32  xtal_div:8;
    };
}hdmi_p3_port3_audio_freqdet_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  range1_th:12;
        RBus_UInt32  range0_th:12;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_range0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  range3_th:12;
        RBus_UInt32  range2_th:12;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_range2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  range5_th:12;
        RBus_UInt32  range4_th:12;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_range4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_set_s_code0:7;
        RBus_UInt32  pre_set_s1_code0:1;
        RBus_UInt32  pre_set_s_code1:7;
        RBus_UInt32  pre_set_s1_code1:1;
        RBus_UInt32  pre_set_s_code2:7;
        RBus_UInt32  pre_set_s1_code2:1;
        RBus_UInt32  pre_set_s_code3:7;
        RBus_UInt32  pre_set_s1_code3:1;
    };
}hdmi_p3_port3_preset_s_code0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_set_s_code4:7;
        RBus_UInt32  pre_set_s1_code4:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pre_set_sm_code4:1;
        RBus_UInt32  pre_set_sm_code3:1;
        RBus_UInt32  pre_set_sm_code2:1;
        RBus_UInt32  pre_set_sm_code1:1;
        RBus_UInt32  pre_set_sm_code0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  afsm_mod_en:1;
        RBus_UInt32  trk_mod_en:1;
        RBus_UInt32  auto_stop_trk_en:1;
        RBus_UInt32  dp_abuf_wr_mod_en:1;
        RBus_UInt32  res3:8;
    };
}hdmi_p3_port3_preset_s_code1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs7_rxen:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  res2:3;
    };
}hdmi_p3_port3_prbs_r_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs7_rxen:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  res2:3;
    };
}hdmi_p3_port3_prbs_g_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prbs7_rxen:1;
        RBus_UInt32  prbs_reverse:1;
        RBus_UInt32  prbs_err_cnt_clr:1;
        RBus_UInt32  prbs_lock:1;
        RBus_UInt32  prbs_bit_err:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  prbs_err_cnt:4;
        RBus_UInt32  prbs_rxbist_err_cnt:8;
        RBus_UInt32  prbs23_rxen:1;
        RBus_UInt32  res2:3;
    };
}hdmi_p3_port3_prbs_b_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lgb_cal_en:1;
        RBus_UInt32  lgb_cal_conti:1;
        RBus_UInt32  channel_sel:2;
        RBus_UInt32  dvi_mode_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cmp_value:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  preamble:4;
        RBus_UInt32  cmp_err_int_en:1;
        RBus_UInt32  cmp_err_wd_en:1;
        RBus_UInt32  cmp_err_flag:1;
        RBus_UInt32  res3:1;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_times:16;
        RBus_UInt32  cmp_err_cnt:16;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_times_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  preamble_cmp_cnt_by_frame:16;
        RBus_UInt32  preamble_cmp_cnt:16;
    };
}hdmi_p3_port3_hdmi_leading_gb_cmp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cts_up_bound:20;
        RBus_UInt32  cts_clip_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  cts_over_flag:1;
    };
}hdmi_p3_port3_audio_cts_up_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cts_low_bound:20;
        RBus_UInt32  res1:11;
        RBus_UInt32  cts_under_flag:1;
    };
}hdmi_p3_port3_audio_cts_low_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_up_bound:20;
        RBus_UInt32  n_clip_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  n_over_flag:1;
    };
}hdmi_p3_port3_audio_n_up_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_low_bound:20;
        RBus_UInt32  res1:11;
        RBus_UInt32  n_under_flag:1;
    };
}hdmi_p3_port3_audio_n_low_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_dec_pp_mode_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cal_pixel_sel:1;
        RBus_UInt32  xor_pixel_sel:3;
        RBus_UInt32  packet_mhl_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pp_mode_output:1;
        RBus_UInt32  en_packet_retiming_vsrst:1;
        RBus_UInt32  dummy180b215c_15:2;
        RBus_UInt32  hporch_offset:10;
        RBus_UInt32  res3:6;
    };
}hdmi_p3_port3_mhl_hdmi_mac_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oui:24;
        RBus_UInt32  mhl_vid:2;
        RBus_UInt32  mhl_3d_fmt:4;
        RBus_UInt32  res1:2;
    };
}hdmi_p3_port3_mhl_3d_format_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mhl_hev_fmt_type:16;
        RBus_UInt32  sep_aud:1;
        RBus_UInt32  mhl_hev_fmt:2;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_mhl_3p0_format0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  av_delay_sync:20;
        RBus_UInt32  av_delay_dir:1;
        RBus_UInt32  acrfs_div:3;
        RBus_UInt32  res1:8;
    };
}hdmi_p3_port3_mhl_3p0_format1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_ls:1;
        RBus_UInt32  hdcp_ls:1;
        RBus_UInt32  hdcp_ksvfifo_ls:1;
        RBus_UInt32  hdcp_2p2_ls0:1;
        RBus_UInt32  hdcp_2p2_ls1:1;
        RBus_UInt32  yuv420_ls0:1;
        RBus_UInt32  yuv420_ls1:1;
        RBus_UInt32  yuv420_ls2:1;
        RBus_UInt32  yuv420_ls3:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_light_sleep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yuv420_rm0:4;
        RBus_UInt32  yuv420_rm1:4;
        RBus_UInt32  yuv420_rm2:4;
        RBus_UInt32  yuv420_rm3:4;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_read_margin2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_rme:1;
        RBus_UInt32  hdcp_rme:1;
        RBus_UInt32  hdcp_ksvfifo_rme:1;
        RBus_UInt32  hdcp_2p2_rme0:1;
        RBus_UInt32  hdcp_2p2_rme1:1;
        RBus_UInt32  yuv420_rme0:1;
        RBus_UInt32  yuv420_rme1:1;
        RBus_UInt32  yuv420_rme2:1;
        RBus_UInt32  yuv420_rme3:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_rm:4;
        RBus_UInt32  hdcp_rm:4;
        RBus_UInt32  hdcp_ksvfifo_rm:4;
        RBus_UInt32  hdcp_2p2_rm0:4;
        RBus_UInt32  hdcp_2p2_rm1:4;
        RBus_UInt32  res1:12;
    };
}hdmi_p3_port3_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_en:1;
        RBus_UInt32  hdcp_bist_en:1;
        RBus_UInt32  hdcp_ksvfifo_bist_en:1;
        RBus_UInt32  hdcp_2p2_bist_en:1;
        RBus_UInt32  yuv420_bist_en:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_done:1;
        RBus_UInt32  hdcp_bist_done:1;
        RBus_UInt32  hdcp_ksvfifo_bist_done:1;
        RBus_UInt32  hdcp_2p2_bist_done:1;
        RBus_UInt32  yuv420_bist_done:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_fail:1;
        RBus_UInt32  hdcp_bist_fail:1;
        RBus_UInt32  hdcp_ksvfifo_bist_fail:1;
        RBus_UInt32  hdcp_2p2_bist_fail:1;
        RBus_UInt32  yuv420_bist_fail:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_mode:1;
        RBus_UInt32  hdcp_drf_mode:1;
        RBus_UInt32  hdcp_ksvfifo_drf_mode:1;
        RBus_UInt32  hdcp_2p2_drf_mode:1;
        RBus_UInt32  yuv420_drf_mode:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_resume:1;
        RBus_UInt32  hdcp_drf_resume:1;
        RBus_UInt32  hdcp_ksvfifo_drf_resume:1;
        RBus_UInt32  hdcp_2p2_drf_resume:1;
        RBus_UInt32  yuv420_drf_resume:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_done:1;
        RBus_UInt32  hdcp_drf_done:1;
        RBus_UInt32  hdcp_ksvfifo_drf_done:1;
        RBus_UInt32  hdcp_2p2_drf_done:1;
        RBus_UInt32  yuv420_drf_done:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_pause:1;
        RBus_UInt32  hdcp_drf_pause:1;
        RBus_UInt32  hdcp_ksvfifo_drf_pause:1;
        RBus_UInt32  hdcp_2p2_drf_pause:1;
        RBus_UInt32  yuv420_drf_pause:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_fail:1;
        RBus_UInt32  hdcp_drf_fail:1;
        RBus_UInt32  hdcp_ksvfifo_drf_fail:1;
        RBus_UInt32  hdcp_2p2_drf_fail:1;
        RBus_UInt32  yuv420_drf_fail:1;
        RBus_UInt32  res1:27;
    };
}hdmi_p3_port3_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  port0_b_afifo_en:1;
        RBus_UInt32  port0_b_flush:1;
        RBus_UInt32  port0_g_afifo_en:1;
        RBus_UInt32  port0_g_flush:1;
        RBus_UInt32  port0_r_afifo_en:1;
        RBus_UInt32  port0_r_flush:1;
        RBus_UInt32  dummy180b219c_6:1;
        RBus_UInt32  port1_b_afifo_en:1;
        RBus_UInt32  port1_b_flush:1;
        RBus_UInt32  port1_g_afifo_en:1;
        RBus_UInt32  port1_g_flush:1;
        RBus_UInt32  port1_r_afifo_en:1;
        RBus_UInt32  port1_r_flush:1;
        RBus_UInt32  dummy180b219c_13:1;
        RBus_UInt32  port2_b_afifo_en:1;
        RBus_UInt32  port2_b_flush:1;
        RBus_UInt32  port2_g_afifo_en:1;
        RBus_UInt32  port2_g_flush:1;
        RBus_UInt32  port2_r_afifo_en:1;
        RBus_UInt32  port2_r_flush:1;
        RBus_UInt32  dummy180b219c_20:1;
        RBus_UInt32  port3_b_afifo_en:1;
        RBus_UInt32  port3_b_flush:1;
        RBus_UInt32  port3_g_afifo_en:1;
        RBus_UInt32  port3_g_flush:1;
        RBus_UInt32  port3_r_afifo_en:1;
        RBus_UInt32  port3_r_flush:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:3;
    };
}hdmi_p3_port3_phy_fifo_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  port0_bclk_inv:1;
        RBus_UInt32  port0_gclk_inv:1;
        RBus_UInt32  port0_rclk_inv:1;
        RBus_UInt32  port1_bclk_inv:1;
        RBus_UInt32  port1_gclk_inv:1;
        RBus_UInt32  port1_rclk_inv:1;
        RBus_UInt32  port2_bclk_inv:1;
        RBus_UInt32  port2_gclk_inv:1;
        RBus_UInt32  port2_rclk_inv:1;
        RBus_UInt32  port3_bclk_inv:1;
        RBus_UInt32  port3_gclk_inv:1;
        RBus_UInt32  port3_rclk_inv:1;
        RBus_UInt32  res1:20;
    };
}hdmi_p3_port3_phy_fifo_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  port0_b_rflush_flag:1;
        RBus_UInt32  port0_b_rudflow_flag:1;
        RBus_UInt32  port0_b_wovflow_flag:1;
        RBus_UInt32  port0_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port0_g_rflush_flag:1;
        RBus_UInt32  port0_g_rudflow_flag:1;
        RBus_UInt32  port0_g_wovflow_flag:1;
        RBus_UInt32  port0_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port0_r_rflush_flag:1;
        RBus_UInt32  port0_r_rudflow_flag:1;
        RBus_UInt32  port0_r_wovflow_flag:1;
        RBus_UInt32  port0_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port0_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_b_rflush_flag:1;
        RBus_UInt32  port1_b_rudflow_flag:1;
        RBus_UInt32  port1_b_wovflow_flag:1;
        RBus_UInt32  port1_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_g_rflush_flag:1;
        RBus_UInt32  port1_g_rudflow_flag:1;
        RBus_UInt32  port1_g_wovflow_flag:1;
        RBus_UInt32  port1_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port1_r_rflush_flag:1;
        RBus_UInt32  port1_r_rudflow_flag:1;
        RBus_UInt32  port1_r_wovflow_flag:1;
        RBus_UInt32  port1_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port1_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  res1:2;
    };
}hdmi_p3_port3_phy_fifo_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  port2_b_rflush_flag:1;
        RBus_UInt32  port2_b_rudflow_flag:1;
        RBus_UInt32  port2_b_wovflow_flag:1;
        RBus_UInt32  port2_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port2_g_rflush_flag:1;
        RBus_UInt32  port2_g_rudflow_flag:1;
        RBus_UInt32  port2_g_wovflow_flag:1;
        RBus_UInt32  port2_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port2_r_rflush_flag:1;
        RBus_UInt32  port2_r_rudflow_flag:1;
        RBus_UInt32  port2_r_wovflow_flag:1;
        RBus_UInt32  port2_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port2_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_b_rflush_flag:1;
        RBus_UInt32  port3_b_rudflow_flag:1;
        RBus_UInt32  port3_b_wovflow_flag:1;
        RBus_UInt32  port3_b_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_b_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_g_rflush_flag:1;
        RBus_UInt32  port3_g_rudflow_flag:1;
        RBus_UInt32  port3_g_wovflow_flag:1;
        RBus_UInt32  port3_g_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_g_wrclk_det_timeout_flag:1;
        RBus_UInt32  port3_r_rflush_flag:1;
        RBus_UInt32  port3_r_rudflow_flag:1;
        RBus_UInt32  port3_r_wovflow_flag:1;
        RBus_UInt32  port3_r_rwclk_det_timeout_flag:1;
        RBus_UInt32  port3_r_wrclk_det_timeout_flag:1;
        RBus_UInt32  res1:2;
    };
}hdmi_p3_port3_phy_fifo_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ctsfifo_bypass_hdmi:1;
        RBus_UInt32  en_ctsfifo_vsrst_hdmi:1;
        RBus_UInt32  force_ctsfifo_rstn_hdmi:1;
        RBus_UInt32  hdmi_out_sel:1;
        RBus_UInt32  hdmi_test_sel:4;
        RBus_UInt32  hdmi_2x_out_sel:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  dfe_rstn_n:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_b:1;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_b:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_g:1;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_g:1;
        RBus_UInt32  en_ctsfifo_bypass_phy_dbgout_r:1;
        RBus_UInt32  force_ctsfifo_rstn_phy_dbgout_r:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:10;
    };
}hdmi_p3_port3_hdmi_cts_fifo_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_afifo_irq_en:1;
        RBus_UInt32  flush:1;
        RBus_UInt32  dummy180b21b0_3:2;
        RBus_UInt32  udwater_thr:5;
        RBus_UInt32  dummy180b21b0_11:3;
        RBus_UInt32  rden_thr:5;
        RBus_UInt32  dummy180b21b0_19:3;
        RBus_UInt32  ch_sync_sel:2;
        RBus_UInt32  b_ch_afifo_en:1;
        RBus_UInt32  g_ch_afifo_en:1;
        RBus_UInt32  r_ch_afifo_en:1;
        RBus_UInt32  res1:7;
    };
}hdmi_p3_port3_ch_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_rw_water_lv:5;
        RBus_UInt32  b_rflush_flag:1;
        RBus_UInt32  b_wovflow_flag:1;
        RBus_UInt32  b_rudflow_flag:1;
        RBus_UInt32  g_rw_water_lv:5;
        RBus_UInt32  g_rflush_flag:1;
        RBus_UInt32  g_wovflow_flag:1;
        RBus_UInt32  g_rudflow_flag:1;
        RBus_UInt32  r_rw_water_lv:5;
        RBus_UInt32  r_rflush_flag:1;
        RBus_UInt32  r_wovflow_flag:1;
        RBus_UInt32  r_rudflow_flag:1;
        RBus_UInt32  b_wrclk_det_timeout_flag:1;
        RBus_UInt32  b_rwclk_det_timeout_flag:1;
        RBus_UInt32  g_wrclk_det_timeout_flag:1;
        RBus_UInt32  g_rwclk_det_timeout_flag:1;
        RBus_UInt32  r_wrclk_det_timeout_flag:1;
        RBus_UInt32  r_rwclk_det_timeout_flag:1;
        RBus_UInt32  rgb_de_align_flag:1;
        RBus_UInt32  res1:1;
    };
}hdmi_p3_port3_ch_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdmi_2p0_en:1;
        RBus_UInt32  ctr_char_num:7;
        RBus_UInt32  gating_en:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_hdmi_2p0_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scr_auto:1;
        RBus_UInt32  scr_en_fw:1;
        RBus_UInt32  dummy180b21bc_3:2;
        RBus_UInt32  uscr_num:4;
        RBus_UInt32  uscr_char_flag_b:1;
        RBus_UInt32  uscr_char_flag_g:1;
        RBus_UInt32  uscr_char_flag_r:1;
        RBus_UInt32  uscr_per_glitch_b:1;
        RBus_UInt32  uscr_per_glitch_g:1;
        RBus_UInt32  uscr_per_glitch_r:1;
        RBus_UInt32  uscr_fall_bound_err_b:1;
        RBus_UInt32  uscr_fall_bound_err_g:1;
        RBus_UInt32  uscr_fall_bound_err_r:1;
        RBus_UInt32  char_lock:1;
        RBus_UInt32  res1:14;
    };
}hdmi_p3_port3_scr_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  dummy180b21c0_3:2;
        RBus_UInt32  period:6;
        RBus_UInt32  reset:1;
        RBus_UInt32  refer_implem:1;
        RBus_UInt32  keep_err_det:1;
        RBus_UInt32  reset_err_det:1;
        RBus_UInt32  valid_reset:1;
        RBus_UInt32  max_err_num:10;
        RBus_UInt32  ch0_over_max_err_num:1;
        RBus_UInt32  ch1_over_max_err_num:1;
        RBus_UInt32  ch2_over_max_err_num:1;
        RBus_UInt32  ch_locked_reset:1;
        RBus_UInt32  res1:3;
    };
}hdmi_p3_port3_cercr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt0_video:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt1_video:15;
        RBus_UInt32  res2:1;
    };
}hdmi_p3_port3_cersr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt2_video:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt0_pkt:15;
        RBus_UInt32  res2:1;
    };
}hdmi_p3_port3_cersr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt1_pkt:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt2_pkt:15;
        RBus_UInt32  res2:1;
    };
}hdmi_p3_port3_cersr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt0_ctr:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  err_cnt1_ctr:15;
        RBus_UInt32  res2:1;
    };
}hdmi_p3_port3_cersr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt2_ctr:15;
        RBus_UInt32  res1:17;
    };
}hdmi_p3_port3_cersr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  fifo_under_flag:1;
        RBus_UInt32  fifo_over_flag:1;
        RBus_UInt32  res1:29;
    };
}hdmi_p3_port3_yuv420_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scdc_en:1;
        RBus_UInt32  maddf:1;
        RBus_UInt32  dummy180b21dc_4:3;
        RBus_UInt32  scdc_reset:1;
        RBus_UInt32  res1:26;
    };
}hdmi_p3_port3_scdc_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apai:1;
        RBus_UInt32  test_rr_added_delay_sel:2;
        RBus_UInt32  dummy180b21e0_6:4;
        RBus_UInt32  dbnc_level_sel:1;
        RBus_UInt32  rr_retry_sel:2;
        RBus_UInt32  i2c_free_num:7;
        RBus_UInt32  i2c_sda_dly_sel:4;
        RBus_UInt32  i2c_scl_dly_sel:4;
        RBus_UInt32  tmds_config_flag:1;
        RBus_UInt32  scrambler_status_flag:1;
        RBus_UInt32  config_flag:1;
        RBus_UInt32  status_flag:1;
        RBus_UInt32  timeout_sel:2;
        RBus_UInt32  timeout_flag:1;
    };
}hdmi_p3_port3_scdc_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ap1:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_scdc_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dp1:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_scdc_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clock_det_en:1;
        RBus_UInt32  res1:31;
    };
}hdmi_p3_port3_acdrclkdetcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_not_in_target:1;
        RBus_UInt32  clk_not_in_target_irq_en:1;
        RBus_UInt32  dummy180b21f0_3:2;
        RBus_UInt32  tmds_chg_irq:1;
        RBus_UInt32  en_tmds_chg_irq:1;
        RBus_UInt32  res1:26;
    };
}hdmi_p3_port3_acdrclkdetsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_cnt_end:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_cnt_start:12;
        RBus_UInt32  res2:4;
    };
}hdmi_p3_port3_acdrclk_setting_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  target_for_minimum_clk_counter:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  target_for_maximum_clk_counter:12;
        RBus_UInt32  res2:4;
    };
}hdmi_p3_port3_acdrclk_setting_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_counter_debounce:8;
        RBus_UInt32  clk_counter_err_threshold:4;
        RBus_UInt32  res1:20;
    };
}hdmi_p3_port3_acdrclk_setting_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}hdmi_p3_port3_hdcp_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdcp_en:1;
        RBus_UInt32  dkapde:1;
        RBus_UInt32  maddf:1;
        RBus_UInt32  ivspm:1;
        RBus_UInt32  invvs:1;
        RBus_UInt32  ivsp:1;
        RBus_UInt32  rpt:1;
        RBus_UInt32  namfe:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdcp_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dkap:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdcp_dkap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apai:1;
        RBus_UInt32  apai_type:1;
        RBus_UInt32  km_start_sel:1;
        RBus_UInt32  avmute_dis:1;
        RBus_UInt32  enc_tog:1;
        RBus_UInt32  hdcp_vs_sel:1;
        RBus_UInt32  km_clk_sel:1;
        RBus_UInt32  dbnc_level_sel:1;
        RBus_UInt32  dvi_enc_mode:1;
        RBus_UInt32  ddcdbnc:1;
        RBus_UInt32  tune_range:7;
        RBus_UInt32  tune_up_down:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  i2c_sda_dly_sel:4;
        RBus_UInt32  i2c_scl_dly_sel:4;
        RBus_UInt32  iic_st:3;
        RBus_UInt32  res2:1;
    };
}hdmi_p3_port3_hdcp_pcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2210_1_0:2;
        RBus_UInt32  rd_bksv_flag:1;
        RBus_UInt32  rd_ri_flag:1;
        RBus_UInt32  wr_aksv_flag:1;
        RBus_UInt32  nc_flag:1;
        RBus_UInt32  ence_flag:1;
        RBus_UInt32  adne_flag:1;
        RBus_UInt32  akm_flag:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_hdcp_flag1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2214_1_0:2;
        RBus_UInt32  irq_bksv_en:1;
        RBus_UInt32  irq_ri_en:1;
        RBus_UInt32  irq_aksv_en:1;
        RBus_UInt32  irq_nc_en:1;
        RBus_UInt32  irq_ence_en:1;
        RBus_UInt32  irq_adne_en:1;
        RBus_UInt32  irq_akm_en:1;
        RBus_UInt32  res1:23;
    };
}hdmi_p3_port3_hdcp_flag2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ap1:8;
        RBus_UInt32  dp_ksvfifo_ptr:10;
        RBus_UInt32  ksvfifo_status:1;
        RBus_UInt32  res1:13;
    };
}hdmi_p3_port3_hdcp_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dp1:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdcp_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdcp_2p2_en:1;
        RBus_UInt32  switch_unauth:1;
        RBus_UInt32  ks_done:1;
        RBus_UInt32  downstream_done:1;
        RBus_UInt32  assemble_id_fail:1;
        RBus_UInt32  verify_id_done:1;
        RBus_UInt32  verify_id_pass:1;
        RBus_UInt32  new_auth_device:1;
        RBus_UInt32  mspai:1;
        RBus_UInt32  apply_state:1;
        RBus_UInt32  fw_mode_riv:1;
        RBus_UInt32  rpt_thr_unauth:1;
        RBus_UInt32  switch_state:12;
        RBus_UInt32  ks_encoded:1;
        RBus_UInt32  apply_cp_fn:1;
        RBus_UInt32  fn_auto_inc:1;
        RBus_UInt32  dummy180b2220_31:5;
    };
}hdmi_p3_port3_hdcp_2p2_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ks:32;
    };
}hdmi_p3_port3_hdcp_2p2_ks3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lc:32;
    };
}hdmi_p3_port3_hdcp_2p2_lc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  riv:32;
    };
}hdmi_p3_port3_hdcp_2p2_riv0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  riv:32;
    };
}hdmi_p3_port3_hdcp_2p2_riv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  state:12;
        RBus_UInt32  irq_wr_msg_start:1;
        RBus_UInt32  irq_rd_msg_start:1;
        RBus_UInt32  irq_wr_msg_done:1;
        RBus_UInt32  irq_rd_msg_done:1;
        RBus_UInt32  irq_state_chg:1;
        RBus_UInt32  irq_unauth_chg:1;
        RBus_UInt32  irq_msg_overwrite:1;
        RBus_UInt32  irq_no_cp_packet:1;
        RBus_UInt32  irq_crc_fail:1;
        RBus_UInt32  irq_fn_compare_fail:1;
        RBus_UInt32  frame_number:8;
        RBus_UInt32  res1:2;
    };
}hdmi_p3_port3_hdcp_2p2_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irq_wr_msg_start_en:1;
        RBus_UInt32  irq_rd_msg_start_en:1;
        RBus_UInt32  irq_wr_msg_done_en:1;
        RBus_UInt32  irq_rd_msg_done_en:1;
        RBus_UInt32  irq_state_chg_en:1;
        RBus_UInt32  irq_unauth_chg_en:1;
        RBus_UInt32  irq_msg_overwrite_en:1;
        RBus_UInt32  irq_no_cp_packet_en:1;
        RBus_UInt32  irq_crc_fail_en:1;
        RBus_UInt32  irq_fn_compare_fail_en:1;
        RBus_UInt32  no_cp_packet_wd_en:1;
        RBus_UInt32  crc_fail_wd_en:1;
        RBus_UInt32  res1:20;
    };
}hdmi_p3_port3_hdcp_2p2_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ap1:10;
        RBus_UInt32  res1:22;
    };
}hdmi_p3_port3_hdcp_msap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dp1:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdcp_msdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2300_3_0:4;
        RBus_UInt32  dbdcb:1;
        RBus_UInt32  ocs:2;
        RBus_UInt32  icmux:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_cmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2304_7_0:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_mcapr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc:7;
        RBus_UInt32  slc:1;
        RBus_UInt32  s1_code_msb:1;
        RBus_UInt32  sc_r:7;
        RBus_UInt32  slc_r:1;
        RBus_UInt32  s1_code_msb_r:1;
        RBus_UInt32  res1:14;
    };
}hdmi_p3_port3_hdmi_scapr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcaprl:8;
        RBus_UInt32  dcaprh:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_dcapr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pecs:2;
        RBus_UInt32  etfbc:1;
        RBus_UInt32  etfd:1;
        RBus_UInt32  etcn:1;
        RBus_UInt32  fdint:3;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_pscr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fddr:8;
        RBus_UInt32  fddf:8;
        RBus_UInt32  mfddr:8;
        RBus_UInt32  mfddf:8;
    };
}hdmi_p3_port3_hdmi_afdd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tt:4;
        RBus_UInt32  tl2def:2;
        RBus_UInt32  tl2der:2;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_ftr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bad:3;
        RBus_UInt32  tfd:5;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_fbr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icl:8;
        RBus_UInt32  ich:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_icpsncr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcl:8;
        RBus_UInt32  pch:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_pcpsncr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ictl:8;
        RBus_UInt32  icth:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_ictpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pctl:8;
        RBus_UInt32  pcth:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_pctpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  icbl:8;
        RBus_UInt32  icbh:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_icbpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcbl:8;
        RBus_UInt32  pcbh:8;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_pcbpsr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nt:12;
        RBus_UInt32  rm:1;
        RBus_UInt32  res1:19;
    };
}hdmi_p3_port3_hdmi_ntx1024tr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ftb:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_stbpr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncper:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_ncper_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  petr:8;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_petr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2350_0:1;
        RBus_UInt32  esdm:1;
        RBus_UInt32  dummy180b2350_2:1;
        RBus_UInt32  w1c5:1;
        RBus_UInt32  tef:1;
        RBus_UInt32  ssdmou:1;
        RBus_UInt32  cmvbc:1;
        RBus_UInt32  cmvtc:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_aapnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psc:4;
        RBus_UInt32  pst:1;
        RBus_UInt32  edm:1;
        RBus_UInt32  dummy180b2354_6_6:1;
        RBus_UInt32  dummy180b2354_7_7:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_apdmcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sps:4;
        RBus_UInt32  fps:4;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_hdmi_aptmcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nfpss:4;
        RBus_UInt32  spsd:1;
        RBus_UInt32  fpsd:1;
        RBus_UInt32  plltm:1;
        RBus_UInt32  res1:25;
    };
}hdmi_p3_port3_hdmi_aptmcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncts_disable_pe_check_cnt:20;
        RBus_UInt32  dummy180b2360_27_20:8;
        RBus_UInt32  ncts_disable_pe_check_irq_en:1;
        RBus_UInt32  ncts_disable_pe_check_status:1;
        RBus_UInt32  ncts_re_enable_off_en:1;
        RBus_UInt32  ncts_disable_pe_check_en:1;
    };
}hdmi_p3_port3_hdmi_npecr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ncts_re_enable_off_end:16;
        RBus_UInt32  ncts_re_enable_off_start:16;
    };
}hdmi_p3_port3_hdmi_nror_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nt_low_threshold:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nt_up_threshold:12;
        RBus_UInt32  irq_by_tmds_clk:1;
        RBus_UInt32  wd_by_tmds_clk:1;
        RBus_UInt32  under_threshold:1;
        RBus_UInt32  over_threshold:1;
    };
}hdmi_p3_port3_hdmi_ntx1024tr0_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  dpll_bpsin:1;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  dpll_reg:2;
    };
}hdmi_p3_port3_hdmi_apllcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pow:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_stoppsw:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdo:1;
        RBus_UInt32  dpll_bpspsw:1;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  dpll_seltst:2;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  res7:9;
    };
}hdmi_p3_port3_hdmi_apllcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_reloadm:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:27;
    };
}hdmi_p3_port3_hdmi_apllcr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_c_samp:16;
        RBus_UInt32  res1:16;
    };
}hdmi_p3_port3_hdmi_apllcr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_m_sel:1;
        RBus_UInt32  dpll_m_db:1;
        RBus_UInt32  res1:20;
        RBus_UInt32  dpll_m_test:8;
        RBus_UInt32  res2:2;
    };
}hdmi_p3_port3_hdmi_apll_testm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  dpll_bpsin:1;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  dpll_reg:2;
    };
}hdmi_p3_port3_hdmi_vpllcr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pow:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_stoppsw:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdo:1;
        RBus_UInt32  dpll_bpspsw:1;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  dpll_ldo_sel:2;
        RBus_UInt32  dpll_ldo_pow:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  dpll_seltst:2;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  res4:9;
    };
}hdmi_p3_port3_hdmi_vpllcr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_reloadm:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:27;
    };
}hdmi_p3_port3_hdmi_vpllcr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180b2410_3_0:4;
        RBus_UInt32  sclkg_dbuf:1;
        RBus_UInt32  sclkg_oclk_sel:2;
        RBus_UInt32  sclkg_pll_in_sel:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_mn_sclkg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sclkg_pll_divs:7;
        RBus_UInt32  sclkg_pll_div2_en:1;
        RBus_UInt32  res1:24;
    };
}hdmi_p3_port3_mn_sclkg_divs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  dummy180b2500_2:2;
        RBus_UInt32  irq_det_chg_en:1;
        RBus_UInt32  det_con:1;
        RBus_UInt32  dummy180b2500_7:3;
        RBus_UInt32  dummy180b2500_16:9;
        RBus_UInt32  res1:15;
    };
}hdmi_p3_port3_mdd_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  det_result:1;
        RBus_UInt32  det_result_chg:1;
        RBus_UInt32  res1:30;
    };
}hdmi_p3_port3_mdd_sr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  application:32;
    };
}hdmi_p3_port3_fw_func_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offms_port_sel:2;
        RBus_UInt32  port_sel:2;
        RBus_UInt32  res1:28;
    };
}hdmi_p3_port3_port_switch_RBUS;




#endif 


#endif 
