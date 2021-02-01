/**
* @file rbusSync_processorReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-3-4
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SYNC_PROCESSOR_REG_H_
#define _RBUS_SYNC_PROCESSOR_REG_H_

#include "rbusTypes.h"



//  SYNC_PROCESSOR Register Address
#define  SYNC_PROCESSOR_SP1_CTRL                                                 0x18021000
#define  SYNC_PROCESSOR_SP1_CTRL_reg_addr                                        "0xB8021000"
#define  SYNC_PROCESSOR_SP1_CTRL_reg                                             0xB8021000
#define  SYNC_PROCESSOR_SP1_CTRL_inst_addr                                       "0x0000"
#define  set_SYNC_PROCESSOR_SP1_CTRL_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CTRL_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_CTRL_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CTRL_reg))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_dehs_out_en_shift                            (31)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_30_shift                                  (30)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_29_shift                                  (29)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsraw_inv_shift                              (28)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_27_shift                                  (27)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_26_24_shift                               (24)
#define  SYNC_PROCESSOR_SP1_CTRL_hrecovery_en_shift                              (23)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_adc_vsout_testmd_shift                       (22)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_devs_out_en_shift                            (21)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_sel_clpmsk_as_devs_shift                     (20)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_inv_shift                              (19)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_18_shift                                  (18)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_sync_source_shift                         (17)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_en_shift                               (16)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_15_13_shift                               (13)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_seperate_testmode_shift                      (12)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run_done_ie_shift                       (11)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run_shift                               (10)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_en_shift                               (9)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_decmp_en_shift                               (8)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_7_shift                                   (7)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_fb_plswid_md_shift                        (5)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_inv_shift                              (4)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_3_shift                                   (3)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_vhs_source_sel_shift                         (0)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_dehs_out_en_mask                             (0x80000000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_30_mask                                   (0x40000000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_29_mask                                   (0x20000000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsraw_inv_mask                               (0x10000000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_27_mask                                   (0x08000000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_26_24_mask                                (0x07000000)
#define  SYNC_PROCESSOR_SP1_CTRL_hrecovery_en_mask                               (0x00800000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_adc_vsout_testmd_mask                        (0x00400000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_devs_out_en_mask                             (0x00200000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_sel_clpmsk_as_devs_mask                      (0x00100000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_inv_mask                               (0x00080000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_18_mask                                   (0x00040000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_sync_source_mask                          (0x00020000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_en_mask                                (0x00010000)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_15_13_mask                                (0x0000E000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_seperate_testmode_mask                       (0x00001000)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run_done_ie_mask                        (0x00000800)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run_mask                                (0x00000400)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_en_mask                                (0x00000200)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_decmp_en_mask                                (0x00000100)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_7_mask                                    (0x00000080)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_fb_plswid_md_mask                         (0x00000060)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_inv_mask                               (0x00000010)
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_3_mask                                    (0x00000008)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_vhs_source_sel_mask                          (0x00000007)
#define  SYNC_PROCESSOR_SP1_CTRL_s1_dehs_out_en(data)                            (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_30(data)                                  (0x40000000&((data)<<30))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_29(data)                                  (0x20000000&((data)<<29))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsraw_inv(data)                              (0x10000000&((data)<<28))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_27(data)                                  (0x08000000&((data)<<27))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_26_24(data)                               (0x07000000&((data)<<24))
#define  SYNC_PROCESSOR_SP1_CTRL_hrecovery_en(data)                              (0x00800000&((data)<<23))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_adc_vsout_testmd(data)                       (0x00400000&((data)<<22))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_devs_out_en(data)                            (0x00200000&((data)<<21))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_sel_clpmsk_as_devs(data)                     (0x00100000&((data)<<20))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_inv(data)                              (0x00080000&((data)<<19))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_18(data)                                  (0x00040000&((data)<<18))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_sync_source(data)                         (0x00020000&((data)<<17))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hsout_en(data)                               (0x00010000&((data)<<16))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_15_13(data)                               (0x0000E000&((data)<<13))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_seperate_testmode(data)                      (0x00001000&((data)<<12))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run_done_ie(data)                       (0x00000800&((data)<<11))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_auto_run(data)                               (0x00000400&((data)<<10))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_en(data)                               (0x00000200&((data)<<9))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_decmp_en(data)                               (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_7(data)                                   (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_hs_fb_plswid_md(data)                        (0x00000060&((data)<<5))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_coast_inv(data)                              (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP1_CTRL_dummy_3(data)                                   (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP1_CTRL_s1_vhs_source_sel(data)                         (0x00000007&(data))
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_dehs_out_en(data)                        ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_30(data)                              ((0x40000000&(data))>>30)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_29(data)                              ((0x20000000&(data))>>29)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_hsraw_inv(data)                          ((0x10000000&(data))>>28)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_27(data)                              ((0x08000000&(data))>>27)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_26_24(data)                           ((0x07000000&(data))>>24)
#define  SYNC_PROCESSOR_SP1_CTRL_get_hrecovery_en(data)                          ((0x00800000&(data))>>23)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_adc_vsout_testmd(data)                   ((0x00400000&(data))>>22)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_devs_out_en(data)                        ((0x00200000&(data))>>21)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_sel_clpmsk_as_devs(data)                 ((0x00100000&(data))>>20)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_hsout_inv(data)                          ((0x00080000&(data))>>19)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_18(data)                              ((0x00040000&(data))>>18)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_hs_sync_source(data)                     ((0x00020000&(data))>>17)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_hsout_en(data)                           ((0x00010000&(data))>>16)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_15_13(data)                           ((0x0000E000&(data))>>13)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_seperate_testmode(data)                  ((0x00001000&(data))>>12)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_auto_run_done_ie(data)                   ((0x00000800&(data))>>11)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_auto_run(data)                           ((0x00000400&(data))>>10)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_coast_en(data)                           ((0x00000200&(data))>>9)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_decmp_en(data)                           ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_7(data)                               ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_hs_fb_plswid_md(data)                    ((0x00000060&(data))>>5)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_coast_inv(data)                          ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP1_CTRL_get_dummy_3(data)                               ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP1_CTRL_get_s1_vhs_source_sel(data)                     (0x00000007&(data))

#define  SYNC_PROCESSOR_SP1_AutoRst                                              0x18021004
#define  SYNC_PROCESSOR_SP1_AutoRst_reg_addr                                     "0xB8021004"
#define  SYNC_PROCESSOR_SP1_AutoRst_reg                                          0xB8021004
#define  SYNC_PROCESSOR_SP1_AutoRst_inst_addr                                    "0x0001"
#define  set_SYNC_PROCESSOR_SP1_AutoRst_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_AutoRst_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_AutoRst_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_AutoRst_reg))
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result_rdy_shift                     (31)
#define  SYNC_PROCESSOR_SP1_AutoRst_dummy_30_shift                               (30)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_str_shift                    (24)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_end_shift                    (12)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result_shift                         (4)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_input_signal_be_inverted_shift            (0)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result_rdy_mask                      (0x80000000)
#define  SYNC_PROCESSOR_SP1_AutoRst_dummy_30_mask                                (0x40000000)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_str_mask                     (0x3F000000)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_end_mask                     (0x00FFF000)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result_mask                          (0x00000070)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_input_signal_be_inverted_mask             (0x00000001)
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result_rdy(data)                     (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP1_AutoRst_dummy_30(data)                               (0x40000000&((data)<<30))
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_str(data)                    (0x3F000000&((data)<<24))
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_unlock_no_vs_end(data)                    (0x00FFF000&((data)<<12))
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_auto_result(data)                         (0x00000070&((data)<<4))
#define  SYNC_PROCESSOR_SP1_AutoRst_s1_input_signal_be_inverted(data)            (0x00000001&(data))
#define  SYNC_PROCESSOR_SP1_AutoRst_get_s1_auto_result_rdy(data)                 ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP1_AutoRst_get_dummy_30(data)                           ((0x40000000&(data))>>30)
#define  SYNC_PROCESSOR_SP1_AutoRst_get_s1_unlock_no_vs_str(data)                ((0x3F000000&(data))>>24)
#define  SYNC_PROCESSOR_SP1_AutoRst_get_s1_unlock_no_vs_end(data)                ((0x00FFF000&(data))>>12)
#define  SYNC_PROCESSOR_SP1_AutoRst_get_s1_auto_result(data)                     ((0x00000070&(data))>>4)
#define  SYNC_PROCESSOR_SP1_AutoRst_get_s1_input_signal_be_inverted(data)        (0x00000001&(data))

#define  SYNC_PROCESSOR_SP2_CTRL                                                 0x18021008
#define  SYNC_PROCESSOR_SP2_CTRL_reg_addr                                        "0xB8021008"
#define  SYNC_PROCESSOR_SP2_CTRL_reg                                             0xB8021008
#define  SYNC_PROCESSOR_SP2_CTRL_inst_addr                                       "0x0002"
#define  set_SYNC_PROCESSOR_SP2_CTRL_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CTRL_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_CTRL_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CTRL_reg))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_dehs_out_en_shift                            (31)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_30_29_shift                               (29)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_hsraw_inv_shift                              (28)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_27_23_shift                               (23)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_adc_vsout_testmd_shift                       (22)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_devs_out_en_shift                            (21)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_sel_clpmsk_as_devs_shift                     (20)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_19_13_shift                               (13)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_seperate_testmode_shift                      (12)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run_done_ie_shift                       (11)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run_shift                               (10)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_9_shift                                   (9)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_decmp_en_shift                               (8)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_7_3_shift                                 (3)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_vhs_source_sel_shift                         (0)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_dehs_out_en_mask                             (0x80000000)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_30_29_mask                                (0x60000000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_hsraw_inv_mask                               (0x10000000)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_27_23_mask                                (0x0F800000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_adc_vsout_testmd_mask                        (0x00400000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_devs_out_en_mask                             (0x00200000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_sel_clpmsk_as_devs_mask                      (0x00100000)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_19_13_mask                                (0x000FE000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_seperate_testmode_mask                       (0x00001000)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run_done_ie_mask                        (0x00000800)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run_mask                                (0x00000400)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_9_mask                                    (0x00000200)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_decmp_en_mask                                (0x00000100)
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_7_3_mask                                  (0x000000F8)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_vhs_source_sel_mask                          (0x00000007)
#define  SYNC_PROCESSOR_SP2_CTRL_s2_dehs_out_en(data)                            (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_30_29(data)                               (0x60000000&((data)<<29))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_hsraw_inv(data)                              (0x10000000&((data)<<28))
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_27_23(data)                               (0x0F800000&((data)<<23))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_adc_vsout_testmd(data)                       (0x00400000&((data)<<22))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_devs_out_en(data)                            (0x00200000&((data)<<21))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_sel_clpmsk_as_devs(data)                     (0x00100000&((data)<<20))
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_19_13(data)                               (0x000FE000&((data)<<13))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_seperate_testmode(data)                      (0x00001000&((data)<<12))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run_done_ie(data)                       (0x00000800&((data)<<11))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_auto_run(data)                               (0x00000400&((data)<<10))
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_9(data)                                   (0x00000200&((data)<<9))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_decmp_en(data)                               (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_SP2_CTRL_dummy_7_3(data)                                 (0x000000F8&((data)<<3))
#define  SYNC_PROCESSOR_SP2_CTRL_s2_vhs_source_sel(data)                         (0x00000007&(data))
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_dehs_out_en(data)                        ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP2_CTRL_get_dummy_30_29(data)                           ((0x60000000&(data))>>29)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_hsraw_inv(data)                          ((0x10000000&(data))>>28)
#define  SYNC_PROCESSOR_SP2_CTRL_get_dummy_27_23(data)                           ((0x0F800000&(data))>>23)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_adc_vsout_testmd(data)                   ((0x00400000&(data))>>22)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_devs_out_en(data)                        ((0x00200000&(data))>>21)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_sel_clpmsk_as_devs(data)                 ((0x00100000&(data))>>20)
#define  SYNC_PROCESSOR_SP2_CTRL_get_dummy_19_13(data)                           ((0x000FE000&(data))>>13)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_seperate_testmode(data)                  ((0x00001000&(data))>>12)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_auto_run_done_ie(data)                   ((0x00000800&(data))>>11)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_auto_run(data)                           ((0x00000400&(data))>>10)
#define  SYNC_PROCESSOR_SP2_CTRL_get_dummy_9(data)                               ((0x00000200&(data))>>9)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_decmp_en(data)                           ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_SP2_CTRL_get_dummy_7_3(data)                             ((0x000000F8&(data))>>3)
#define  SYNC_PROCESSOR_SP2_CTRL_get_s2_vhs_source_sel(data)                     (0x00000007&(data))

#define  SYNC_PROCESSOR_SP2_AutoRst                                              0x1802100C
#define  SYNC_PROCESSOR_SP2_AutoRst_reg_addr                                     "0xB802100C"
#define  SYNC_PROCESSOR_SP2_AutoRst_reg                                          0xB802100C
#define  SYNC_PROCESSOR_SP2_AutoRst_inst_addr                                    "0x0003"
#define  set_SYNC_PROCESSOR_SP2_AutoRst_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_AutoRst_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_AutoRst_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_AutoRst_reg))
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result_rdy_shift                     (31)
#define  SYNC_PROCESSOR_SP2_AutoRst_dummy_30_shift                               (30)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_str_shift                    (24)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_end_shift                    (12)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result_shift                         (4)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_input_signal_be_inverted_shift            (0)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result_rdy_mask                      (0x80000000)
#define  SYNC_PROCESSOR_SP2_AutoRst_dummy_30_mask                                (0x40000000)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_str_mask                     (0x3F000000)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_end_mask                     (0x00FFF000)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result_mask                          (0x00000070)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_input_signal_be_inverted_mask             (0x00000001)
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result_rdy(data)                     (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP2_AutoRst_dummy_30(data)                               (0x40000000&((data)<<30))
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_str(data)                    (0x3F000000&((data)<<24))
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_unlock_no_vs_end(data)                    (0x00FFF000&((data)<<12))
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_auto_result(data)                         (0x00000070&((data)<<4))
#define  SYNC_PROCESSOR_SP2_AutoRst_s2_input_signal_be_inverted(data)            (0x00000001&(data))
#define  SYNC_PROCESSOR_SP2_AutoRst_get_s2_auto_result_rdy(data)                 ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP2_AutoRst_get_dummy_30(data)                           ((0x40000000&(data))>>30)
#define  SYNC_PROCESSOR_SP2_AutoRst_get_s2_unlock_no_vs_str(data)                ((0x3F000000&(data))>>24)
#define  SYNC_PROCESSOR_SP2_AutoRst_get_s2_unlock_no_vs_end(data)                ((0x00FFF000&(data))>>12)
#define  SYNC_PROCESSOR_SP2_AutoRst_get_s2_auto_result(data)                     ((0x00000070&(data))>>4)
#define  SYNC_PROCESSOR_SP2_AutoRst_get_s2_input_signal_be_inverted(data)        (0x00000001&(data))

#define  SYNC_PROCESSOR_SP1_StbCtrl                                              0x18021010
#define  SYNC_PROCESSOR_SP1_StbCtrl_reg_addr                                     "0xB8021010"
#define  SYNC_PROCESSOR_SP1_StbCtrl_reg                                          0xB8021010
#define  SYNC_PROCESSOR_SP1_StbCtrl_inst_addr                                    "0x0004"
#define  set_SYNC_PROCESSOR_SP1_StbCtrl_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbCtrl_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_StbCtrl_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbCtrl_reg))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range_lsb_shift                   (20)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_stbline_shift              (18)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_en_shift                   (17)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range_shift                       (11)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_per_range_shift                           (8)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_popup_stable_per_shift                    (7)
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_6_4_shift                              (4)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_step_shift                        (3)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_miss_lock_limit_shift                     (2)
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_1_shift                                (1)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_stable_en_shift                           (0)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range_lsb_mask                    (0x00300000)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_stbline_mask               (0x000C0000)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_en_mask                    (0x00020000)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range_mask                        (0x0000F800)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_per_range_mask                            (0x00000700)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_popup_stable_per_mask                     (0x00000080)
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_6_4_mask                               (0x00000070)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_step_mask                         (0x00000008)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_miss_lock_limit_mask                      (0x00000004)
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_1_mask                                 (0x00000002)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_stable_en_mask                            (0x00000001)
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range_lsb(data)                   (0x00300000&((data)<<20))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_stbline(data)              (0x000C0000&((data)<<18))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_hsper_realtime_en(data)                   (0x00020000&((data)<<17))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_range(data)                       (0x0000F800&((data)<<11))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_per_range(data)                           (0x00000700&((data)<<8))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_popup_stable_per(data)                    (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_6_4(data)                              (0x00000070&((data)<<4))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_cap_win_step(data)                        (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_miss_lock_limit(data)                     (0x00000004&((data)<<2))
#define  SYNC_PROCESSOR_SP1_StbCtrl_dummy_1(data)                                (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_SP1_StbCtrl_s1_stable_en(data)                           (0x00000001&(data))
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_cap_win_range_lsb(data)               ((0x00300000&(data))>>20)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_hsper_realtime_stbline(data)          ((0x000C0000&(data))>>18)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_hsper_realtime_en(data)               ((0x00020000&(data))>>17)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_cap_win_range(data)                   ((0x0000F800&(data))>>11)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_per_range(data)                       ((0x00000700&(data))>>8)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_popup_stable_per(data)                ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_dummy_6_4(data)                          ((0x00000070&(data))>>4)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_cap_win_step(data)                    ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_miss_lock_limit(data)                 ((0x00000004&(data))>>2)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_dummy_1(data)                            ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_SP1_StbCtrl_get_s1_stable_en(data)                       (0x00000001&(data))

#define  SYNC_PROCESSOR_SP1_StbRst0                                              0x18021014
#define  SYNC_PROCESSOR_SP1_StbRst0_reg_addr                                     "0xB8021014"
#define  SYNC_PROCESSOR_SP1_StbRst0_reg                                          0xB8021014
#define  SYNC_PROCESSOR_SP1_StbRst0_inst_addr                                    "0x0005"
#define  set_SYNC_PROCESSOR_SP1_StbRst0_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbRst0_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_StbRst0_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbRst0_reg))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_of_shift                         (31)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg_shift                         (30)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg_shift                         (29)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_vs_raw_vld_shift                          (28)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_32unlock_shift                        (27)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_eq_occur_shift                            (26)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_hs_pol_chg_shift                          (25)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock_shift                          (24)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_stable_shift                     (23)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stable_pol_out_shift                      (22)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock_no_vs_shift                    (21)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win_shift                       (20)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win_int_shift                   (19)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg_wde_shift                     (18)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg_wde_shift                     (17)
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_main_shift                        (16)
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_sub_shift                         (15)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_of_mask                          (0x80000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg_mask                          (0x40000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg_mask                          (0x20000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_vs_raw_vld_mask                           (0x10000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_32unlock_mask                         (0x08000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_eq_occur_mask                             (0x04000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_hs_pol_chg_mask                           (0x02000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock_mask                           (0x01000000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_stable_mask                      (0x00800000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stable_pol_out_mask                       (0x00400000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock_no_vs_mask                     (0x00200000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win_mask                        (0x00100000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win_int_mask                    (0x00080000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg_wde_mask                      (0x00040000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg_wde_mask                      (0x00020000)
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_main_mask                         (0x00010000)
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_sub_mask                          (0x00008000)
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_of(data)                         (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg(data)                         (0x40000000&((data)<<30))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg(data)                         (0x20000000&((data)<<29))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_vs_raw_vld(data)                          (0x10000000&((data)<<28))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_32unlock(data)                        (0x08000000&((data)<<27))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_eq_occur(data)                            (0x04000000&((data)<<26))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_hs_pol_chg(data)                          (0x02000000&((data)<<25))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock(data)                          (0x01000000&((data)<<24))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_mode_det_stable(data)                     (0x00800000&((data)<<23))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stable_pol_out(data)                      (0x00400000&((data)<<22))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_cap_unlock_no_vs(data)                    (0x00200000&((data)<<21))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win(data)                       (0x00100000&((data)<<20))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_giltch_in_win_int(data)                   (0x00080000&((data)<<19))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_per_chg_wde(data)                     (0x00040000&((data)<<18))
#define  SYNC_PROCESSOR_SP1_StbRst0_s1_stb_pol_chg_wde(data)                     (0x00020000&((data)<<17))
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_main(data)                        (0x00010000&((data)<<16))
#define  SYNC_PROCESSOR_SP1_StbRst0_sync_wd_to_sub(data)                         (0x00008000&((data)<<15))
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_mode_det_of(data)                     ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_stb_per_chg(data)                     ((0x40000000&(data))>>30)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_stb_pol_chg(data)                     ((0x20000000&(data))>>29)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_vs_raw_vld(data)                      ((0x10000000&(data))>>28)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_cap_32unlock(data)                    ((0x08000000&(data))>>27)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_eq_occur(data)                        ((0x04000000&(data))>>26)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_hs_pol_chg(data)                      ((0x02000000&(data))>>25)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_cap_unlock(data)                      ((0x01000000&(data))>>24)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_mode_det_stable(data)                 ((0x00800000&(data))>>23)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_stable_pol_out(data)                  ((0x00400000&(data))>>22)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_cap_unlock_no_vs(data)                ((0x00200000&(data))>>21)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_giltch_in_win(data)                   ((0x00100000&(data))>>20)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_giltch_in_win_int(data)               ((0x00080000&(data))>>19)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_stb_per_chg_wde(data)                 ((0x00040000&(data))>>18)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_s1_stb_pol_chg_wde(data)                 ((0x00020000&(data))>>17)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_sync_wd_to_main(data)                    ((0x00010000&(data))>>16)
#define  SYNC_PROCESSOR_SP1_StbRst0_get_sync_wd_to_sub(data)                     ((0x00008000&(data))>>15)

#define  SYNC_PROCESSOR_SP1_StbRst1                                              0x18021018
#define  SYNC_PROCESSOR_SP1_StbRst1_reg_addr                                     "0xB8021018"
#define  SYNC_PROCESSOR_SP1_StbRst1_reg                                          0xB8021018
#define  SYNC_PROCESSOR_SP1_StbRst1_inst_addr                                    "0x0006"
#define  set_SYNC_PROCESSOR_SP1_StbRst1_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbRst1_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_StbRst1_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_StbRst1_reg))
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_period_out_shift                   (16)
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_plswid_out_shift                   (0)
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_period_out_mask                    (0x07FF0000)
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_plswid_out_mask                    (0x000007FF)
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_period_out(data)                   (0x07FF0000&((data)<<16))
#define  SYNC_PROCESSOR_SP1_StbRst1_s1_stable_plswid_out(data)                   (0x000007FF&(data))
#define  SYNC_PROCESSOR_SP1_StbRst1_get_s1_stable_period_out(data)               ((0x07FF0000&(data))>>16)
#define  SYNC_PROCESSOR_SP1_StbRst1_get_s1_stable_plswid_out(data)               (0x000007FF&(data))

#define  SYNC_PROCESSOR_SP2_StbCtrl                                              0x1802101C
#define  SYNC_PROCESSOR_SP2_StbCtrl_reg_addr                                     "0xB802101C"
#define  SYNC_PROCESSOR_SP2_StbCtrl_reg                                          0xB802101C
#define  SYNC_PROCESSOR_SP2_StbCtrl_inst_addr                                    "0x0007"
#define  set_SYNC_PROCESSOR_SP2_StbCtrl_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbCtrl_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_StbCtrl_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbCtrl_reg))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range_lsb_shift                   (20)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_stbline_shift              (18)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_en_shift                   (17)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range_shift                       (11)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_per_range_shift                           (8)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_popup_stable_per_shift                    (7)
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_6_4_shift                              (4)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_step_shift                        (3)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_miss_lock_limit_shift                     (2)
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_1_shift                                (1)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_stable_en_shift                           (0)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range_lsb_mask                    (0x00300000)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_stbline_mask               (0x000C0000)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_en_mask                    (0x00020000)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range_mask                        (0x0000F800)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_per_range_mask                            (0x00000700)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_popup_stable_per_mask                     (0x00000080)
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_6_4_mask                               (0x00000070)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_step_mask                         (0x00000008)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_miss_lock_limit_mask                      (0x00000004)
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_1_mask                                 (0x00000002)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_stable_en_mask                            (0x00000001)
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range_lsb(data)                   (0x00300000&((data)<<20))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_stbline(data)              (0x000C0000&((data)<<18))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_hsper_realtime_en(data)                   (0x00020000&((data)<<17))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_range(data)                       (0x0000F800&((data)<<11))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_per_range(data)                           (0x00000700&((data)<<8))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_popup_stable_per(data)                    (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_6_4(data)                              (0x00000070&((data)<<4))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_cap_win_step(data)                        (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_miss_lock_limit(data)                     (0x00000004&((data)<<2))
#define  SYNC_PROCESSOR_SP2_StbCtrl_dummy_1(data)                                (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_SP2_StbCtrl_s2_stable_en(data)                           (0x00000001&(data))
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_cap_win_range_lsb(data)               ((0x00300000&(data))>>20)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_hsper_realtime_stbline(data)          ((0x000C0000&(data))>>18)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_hsper_realtime_en(data)               ((0x00020000&(data))>>17)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_cap_win_range(data)                   ((0x0000F800&(data))>>11)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_per_range(data)                       ((0x00000700&(data))>>8)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_popup_stable_per(data)                ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_dummy_6_4(data)                          ((0x00000070&(data))>>4)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_cap_win_step(data)                    ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_miss_lock_limit(data)                 ((0x00000004&(data))>>2)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_dummy_1(data)                            ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_SP2_StbCtrl_get_s2_stable_en(data)                       (0x00000001&(data))

#define  SYNC_PROCESSOR_SP2_StbRst0                                              0x18021020
#define  SYNC_PROCESSOR_SP2_StbRst0_reg_addr                                     "0xB8021020"
#define  SYNC_PROCESSOR_SP2_StbRst0_reg                                          0xB8021020
#define  SYNC_PROCESSOR_SP2_StbRst0_inst_addr                                    "0x0008"
#define  set_SYNC_PROCESSOR_SP2_StbRst0_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbRst0_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_StbRst0_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbRst0_reg))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_of_shift                         (31)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_per_chg_shift                         (30)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_pol_chg_shift                         (29)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_vs_raw_vld_shift                          (28)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_32unlock_shift                        (27)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_eq_occur_shift                            (26)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_hs_pol_chg_shift                          (25)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock_shift                          (24)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_stable_shift                     (23)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stable_pol_out_shift                      (22)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock_no_vs_shift                    (21)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win_shift                       (20)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win_int_shift                   (19)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_of_mask                          (0x80000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_per_chg_mask                          (0x40000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_pol_chg_mask                          (0x20000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_vs_raw_vld_mask                           (0x10000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_32unlock_mask                         (0x08000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_eq_occur_mask                             (0x04000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_hs_pol_chg_mask                           (0x02000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock_mask                           (0x01000000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_stable_mask                      (0x00800000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stable_pol_out_mask                       (0x00400000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock_no_vs_mask                     (0x00200000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win_mask                        (0x00100000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win_int_mask                    (0x00080000)
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_of(data)                         (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_per_chg(data)                         (0x40000000&((data)<<30))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stb_pol_chg(data)                         (0x20000000&((data)<<29))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_vs_raw_vld(data)                          (0x10000000&((data)<<28))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_32unlock(data)                        (0x08000000&((data)<<27))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_eq_occur(data)                            (0x04000000&((data)<<26))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_hs_pol_chg(data)                          (0x02000000&((data)<<25))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock(data)                          (0x01000000&((data)<<24))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_mode_det_stable(data)                     (0x00800000&((data)<<23))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_stable_pol_out(data)                      (0x00400000&((data)<<22))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_cap_unlock_no_vs(data)                    (0x00200000&((data)<<21))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win(data)                       (0x00100000&((data)<<20))
#define  SYNC_PROCESSOR_SP2_StbRst0_s2_giltch_in_win_int(data)                   (0x00080000&((data)<<19))
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_mode_det_of(data)                     ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_stb_per_chg(data)                     ((0x40000000&(data))>>30)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_stb_pol_chg(data)                     ((0x20000000&(data))>>29)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_vs_raw_vld(data)                      ((0x10000000&(data))>>28)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_cap_32unlock(data)                    ((0x08000000&(data))>>27)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_eq_occur(data)                        ((0x04000000&(data))>>26)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_hs_pol_chg(data)                      ((0x02000000&(data))>>25)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_cap_unlock(data)                      ((0x01000000&(data))>>24)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_mode_det_stable(data)                 ((0x00800000&(data))>>23)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_stable_pol_out(data)                  ((0x00400000&(data))>>22)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_cap_unlock_no_vs(data)                ((0x00200000&(data))>>21)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_giltch_in_win(data)                   ((0x00100000&(data))>>20)
#define  SYNC_PROCESSOR_SP2_StbRst0_get_s2_giltch_in_win_int(data)               ((0x00080000&(data))>>19)

#define  SYNC_PROCESSOR_SP2_StbRst1                                              0x18021024
#define  SYNC_PROCESSOR_SP2_StbRst1_reg_addr                                     "0xB8021024"
#define  SYNC_PROCESSOR_SP2_StbRst1_reg                                          0xB8021024
#define  SYNC_PROCESSOR_SP2_StbRst1_inst_addr                                    "0x0009"
#define  set_SYNC_PROCESSOR_SP2_StbRst1_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbRst1_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_StbRst1_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_StbRst1_reg))
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_period_out_shift                   (16)
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_plswid_out_shift                   (0)
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_period_out_mask                    (0x07FF0000)
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_plswid_out_mask                    (0x000007FF)
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_period_out(data)                   (0x07FF0000&((data)<<16))
#define  SYNC_PROCESSOR_SP2_StbRst1_s2_stable_plswid_out(data)                   (0x000007FF&(data))
#define  SYNC_PROCESSOR_SP2_StbRst1_get_s2_stable_period_out(data)               ((0x07FF0000&(data))>>16)
#define  SYNC_PROCESSOR_SP2_StbRst1_get_s2_stable_plswid_out(data)               (0x000007FF&(data))

#define  SYNC_PROCESSOR_SP1_dcnt                                                 0x18021028
#define  SYNC_PROCESSOR_SP1_dcnt_reg_addr                                        "0xB8021028"
#define  SYNC_PROCESSOR_SP1_dcnt_reg                                             0xB8021028
#define  SYNC_PROCESSOR_SP1_dcnt_inst_addr                                       "0x000A"
#define  set_SYNC_PROCESSOR_SP1_dcnt_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_dcnt_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_dcnt_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_dcnt_reg))
#define  SYNC_PROCESSOR_SP1_dcnt_s1_deb_num_shift                                (11)
#define  SYNC_PROCESSOR_SP1_dcnt_s1_dcnt_level_shift                             (0)
#define  SYNC_PROCESSOR_SP1_dcnt_s1_deb_num_mask                                 (0x0000F800)
#define  SYNC_PROCESSOR_SP1_dcnt_s1_dcnt_level_mask                              (0x000007FF)
#define  SYNC_PROCESSOR_SP1_dcnt_s1_deb_num(data)                                (0x0000F800&((data)<<11))
#define  SYNC_PROCESSOR_SP1_dcnt_s1_dcnt_level(data)                             (0x000007FF&(data))
#define  SYNC_PROCESSOR_SP1_dcnt_get_s1_deb_num(data)                            ((0x0000F800&(data))>>11)
#define  SYNC_PROCESSOR_SP1_dcnt_get_s1_dcnt_level(data)                         (0x000007FF&(data))

#define  SYNC_PROCESSOR_SP2_dcnt                                                 0x1802102C
#define  SYNC_PROCESSOR_SP2_dcnt_reg_addr                                        "0xB802102C"
#define  SYNC_PROCESSOR_SP2_dcnt_reg                                             0xB802102C
#define  SYNC_PROCESSOR_SP2_dcnt_inst_addr                                       "0x000B"
#define  set_SYNC_PROCESSOR_SP2_dcnt_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_dcnt_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_dcnt_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_dcnt_reg))
#define  SYNC_PROCESSOR_SP2_dcnt_s2_deb_num_shift                                (11)
#define  SYNC_PROCESSOR_SP2_dcnt_s2_dcnt_level_shift                             (0)
#define  SYNC_PROCESSOR_SP2_dcnt_s2_deb_num_mask                                 (0x0000F800)
#define  SYNC_PROCESSOR_SP2_dcnt_s2_dcnt_level_mask                              (0x000007FF)
#define  SYNC_PROCESSOR_SP2_dcnt_s2_deb_num(data)                                (0x0000F800&((data)<<11))
#define  SYNC_PROCESSOR_SP2_dcnt_s2_dcnt_level(data)                             (0x000007FF&(data))
#define  SYNC_PROCESSOR_SP2_dcnt_get_s2_deb_num(data)                            ((0x0000F800&(data))>>11)
#define  SYNC_PROCESSOR_SP2_dcnt_get_s2_dcnt_level(data)                         (0x000007FF&(data))

#define  SYNC_PROCESSOR_SP1_Field                                                0x18021030
#define  SYNC_PROCESSOR_SP1_Field_reg_addr                                       "0xB8021030"
#define  SYNC_PROCESSOR_SP1_Field_reg                                            0xB8021030
#define  SYNC_PROCESSOR_SP1_Field_inst_addr                                      "0x000C"
#define  set_SYNC_PROCESSOR_SP1_Field_reg(data)                                  (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_Field_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_Field_reg                                        (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_Field_reg))
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_vs_sel_shift                      (8)
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_mode_shift                        (7)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field_shift                           (6)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field_tgle_shift                      (5)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field_shift                         (4)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field_tgle_shift                    (3)
#define  SYNC_PROCESSOR_SP1_Field_s1_l_cnt_lsb1_shift                            (0)
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_vs_sel_mask                       (0x00000100)
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_mode_mask                         (0x00000080)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field_mask                            (0x00000040)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field_tgle_mask                       (0x00000020)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field_mask                          (0x00000010)
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field_tgle_mask                     (0x00000008)
#define  SYNC_PROCESSOR_SP1_Field_s1_l_cnt_lsb1_mask                             (0x00000007)
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_vs_sel(data)                      (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_SP1_Field_s1_field_det_mode(data)                        (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field(data)                           (0x00000040&((data)<<6))
#define  SYNC_PROCESSOR_SP1_Field_s1_f_pos_field_tgle(data)                      (0x00000020&((data)<<5))
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field(data)                         (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP1_Field_s1_f_count_field_tgle(data)                    (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP1_Field_s1_l_cnt_lsb1(data)                            (0x00000007&(data))
#define  SYNC_PROCESSOR_SP1_Field_get_s1_field_det_vs_sel(data)                  ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_field_det_mode(data)                    ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_f_pos_field(data)                       ((0x00000040&(data))>>6)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_f_pos_field_tgle(data)                  ((0x00000020&(data))>>5)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_f_count_field(data)                     ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_f_count_field_tgle(data)                ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP1_Field_get_s1_l_cnt_lsb1(data)                        (0x00000007&(data))

#define  SYNC_PROCESSOR_SP2_Field                                                0x18021034
#define  SYNC_PROCESSOR_SP2_Field_reg_addr                                       "0xB8021034"
#define  SYNC_PROCESSOR_SP2_Field_reg                                            0xB8021034
#define  SYNC_PROCESSOR_SP2_Field_inst_addr                                      "0x000D"
#define  set_SYNC_PROCESSOR_SP2_Field_reg(data)                                  (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_Field_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_Field_reg                                        (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_Field_reg))
#define  SYNC_PROCESSOR_SP2_Field_dummy_31_9_shift                               (9)
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_vs_sel_shift                      (8)
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_mode_shift                        (7)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field_shift                           (6)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field_tgle_shift                      (5)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field_shift                         (4)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field_tgle_shift                    (3)
#define  SYNC_PROCESSOR_SP2_Field_s2_l_cnt_lsb1_shift                            (0)
#define  SYNC_PROCESSOR_SP2_Field_dummy_31_9_mask                                (0xFFFFFE00)
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_vs_sel_mask                       (0x00000100)
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_mode_mask                         (0x00000080)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field_mask                            (0x00000040)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field_tgle_mask                       (0x00000020)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field_mask                          (0x00000010)
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field_tgle_mask                     (0x00000008)
#define  SYNC_PROCESSOR_SP2_Field_s2_l_cnt_lsb1_mask                             (0x00000007)
#define  SYNC_PROCESSOR_SP2_Field_dummy_31_9(data)                               (0xFFFFFE00&((data)<<9))
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_vs_sel(data)                      (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_SP2_Field_s2_field_det_mode(data)                        (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field(data)                           (0x00000040&((data)<<6))
#define  SYNC_PROCESSOR_SP2_Field_s2_f_pos_field_tgle(data)                      (0x00000020&((data)<<5))
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field(data)                         (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP2_Field_s2_f_count_field_tgle(data)                    (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP2_Field_s2_l_cnt_lsb1(data)                            (0x00000007&(data))
#define  SYNC_PROCESSOR_SP2_Field_get_dummy_31_9(data)                           ((0xFFFFFE00&(data))>>9)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_field_det_vs_sel(data)                  ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_field_det_mode(data)                    ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_f_pos_field(data)                       ((0x00000040&(data))>>6)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_f_pos_field_tgle(data)                  ((0x00000020&(data))>>5)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_f_count_field(data)                     ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_f_count_field_tgle(data)                ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP2_Field_get_s2_l_cnt_lsb1(data)                        (0x00000007&(data))

#define  SYNC_PROCESSOR_SP1_CLMPCTRL                                             0x18021038
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_reg_addr                                    "0xB8021038"
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_reg                                         0xB8021038
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_inst_addr                                   "0x000E"
#define  set_SYNC_PROCESSOR_SP1_CLMPCTRL_reg(data)                               (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMPCTRL_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_CLMPCTRL_reg                                     (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMPCTRL_reg))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_dummy_13_8_shift                            (8)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_dben_shift                         (7)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_cnt_unit_shift                     (6)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_clksrc_shift                       (5)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_en_shift                           (4)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_yclamp_hs_inv_shift                      (3)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_nyclamp_hs_inv_shift                     (2)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_test_en_shift                      (1)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_adc_hs_syncedge_shift                    (0)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_dummy_13_8_mask                             (0x00003F00)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_dben_mask                          (0x00000080)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_cnt_unit_mask                      (0x00000040)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_clksrc_mask                        (0x00000020)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_en_mask                            (0x00000010)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_yclamp_hs_inv_mask                       (0x00000008)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_nyclamp_hs_inv_mask                      (0x00000004)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_test_en_mask                       (0x00000002)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_adc_hs_syncedge_mask                     (0x00000001)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_dummy_13_8(data)                            (0x00003F00&((data)<<8))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_dben(data)                         (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_cnt_unit(data)                     (0x00000040&((data)<<6))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_clksrc(data)                       (0x00000020&((data)<<5))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_en(data)                           (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_yclamp_hs_inv(data)                      (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_nyclamp_hs_inv(data)                     (0x00000004&((data)<<2))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_clamp_test_en(data)                      (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_s1_adc_hs_syncedge(data)                    (0x00000001&(data))
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_dummy_13_8(data)                        ((0x00003F00&(data))>>8)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_clamp_dben(data)                     ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_clamp_cnt_unit(data)                 ((0x00000040&(data))>>6)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_clamp_clksrc(data)                   ((0x00000020&(data))>>5)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_clamp_en(data)                       ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_yclamp_hs_inv(data)                  ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_nyclamp_hs_inv(data)                 ((0x00000004&(data))>>2)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_clamp_test_en(data)                  ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_SP1_CLMPCTRL_get_s1_adc_hs_syncedge(data)                (0x00000001&(data))

#define  SYNC_PROCESSOR_SP1_CLMP                                                 0x1802103C
#define  SYNC_PROCESSOR_SP1_CLMP_reg_addr                                        "0xB802103C"
#define  SYNC_PROCESSOR_SP1_CLMP_reg                                             0xB802103C
#define  SYNC_PROCESSOR_SP1_CLMP_inst_addr                                       "0x000F"
#define  set_SYNC_PROCESSOR_SP1_CLMP_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMP_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_CLMP_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMP_reg))
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_sta_shift                             (24)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_end_shift                             (16)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_sta_shift                            (8)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_end_shift                            (0)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_sta_mask                              (0xFF000000)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_end_mask                              (0x00FF0000)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_sta_mask                             (0x0000FF00)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_end_mask                             (0x000000FF)
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_sta(data)                             (0xFF000000&((data)<<24))
#define  SYNC_PROCESSOR_SP1_CLMP_s1_yclamp_end(data)                             (0x00FF0000&((data)<<16))
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_sta(data)                            (0x0000FF00&((data)<<8))
#define  SYNC_PROCESSOR_SP1_CLMP_s1_nyclamp_end(data)                            (0x000000FF&(data))
#define  SYNC_PROCESSOR_SP1_CLMP_get_s1_yclamp_sta(data)                         ((0xFF000000&(data))>>24)
#define  SYNC_PROCESSOR_SP1_CLMP_get_s1_yclamp_end(data)                         ((0x00FF0000&(data))>>16)
#define  SYNC_PROCESSOR_SP1_CLMP_get_s1_nyclamp_sta(data)                        ((0x0000FF00&(data))>>8)
#define  SYNC_PROCESSOR_SP1_CLMP_get_s1_nyclamp_end(data)                        (0x000000FF&(data))

#define  SYNC_PROCESSOR_SP1_CLMPMSK                                              0x18021040
#define  SYNC_PROCESSOR_SP1_CLMPMSK_reg_addr                                     "0xB8021040"
#define  SYNC_PROCESSOR_SP1_CLMPMSK_reg                                          0xB8021040
#define  SYNC_PROCESSOR_SP1_CLMPMSK_inst_addr                                    "0x0010"
#define  set_SYNC_PROCESSOR_SP1_CLMPMSK_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMPMSK_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_CLMPMSK_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CLMPMSK_reg))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_clamp_en_shift                       (15)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_14_shift                               (14)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_front_shift                          (8)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_7_6_shift                              (6)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_back_shift                           (0)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_clamp_en_mask                        (0x00008000)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_14_mask                                (0x00004000)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_front_mask                           (0x00003F00)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_7_6_mask                               (0x000000C0)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_back_mask                            (0x0000003F)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_clamp_en(data)                       (0x00008000&((data)<<15))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_14(data)                               (0x00004000&((data)<<14))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_front(data)                          (0x00003F00&((data)<<8))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_dummy_7_6(data)                              (0x000000C0&((data)<<6))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_s1_mask_back(data)                           (0x0000003F&(data))
#define  SYNC_PROCESSOR_SP1_CLMPMSK_get_s1_mask_clamp_en(data)                   ((0x00008000&(data))>>15)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_get_dummy_14(data)                           ((0x00004000&(data))>>14)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_get_s1_mask_front(data)                      ((0x00003F00&(data))>>8)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_get_dummy_7_6(data)                          ((0x000000C0&(data))>>6)
#define  SYNC_PROCESSOR_SP1_CLMPMSK_get_s1_mask_back(data)                       (0x0000003F&(data))

#define  SYNC_PROCESSOR_SP1_CoastFtBk                                            0x18021044
#define  SYNC_PROCESSOR_SP1_CoastFtBk_reg_addr                                   "0xB8021044"
#define  SYNC_PROCESSOR_SP1_CoastFtBk_reg                                        0xB8021044
#define  SYNC_PROCESSOR_SP1_CoastFtBk_inst_addr                                  "0x0011"
#define  set_SYNC_PROCESSOR_SP1_CoastFtBk_reg(data)                              (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CoastFtBk_reg)=data)
#define  get_SYNC_PROCESSOR_SP1_CoastFtBk_reg                                    (*((volatile unsigned int*)SYNC_PROCESSOR_SP1_CoastFtBk_reg))
#define  SYNC_PROCESSOR_SP1_CoastFtBk_dummy_9_8_shift                            (8)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_front_shift                       (4)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_back_shift                        (0)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_dummy_9_8_mask                             (0x00000300)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_front_mask                        (0x000000F0)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_back_mask                         (0x0000000F)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_dummy_9_8(data)                            (0x00000300&((data)<<8))
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_front(data)                       (0x000000F0&((data)<<4))
#define  SYNC_PROCESSOR_SP1_CoastFtBk_s1_coast_back(data)                        (0x0000000F&(data))
#define  SYNC_PROCESSOR_SP1_CoastFtBk_get_dummy_9_8(data)                        ((0x00000300&(data))>>8)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_get_s1_coast_front(data)                   ((0x000000F0&(data))>>4)
#define  SYNC_PROCESSOR_SP1_CoastFtBk_get_s1_coast_back(data)                    (0x0000000F&(data))

#define  SYNC_PROCESSOR_SP2_CLMPCTRL                                             0x18021048
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_reg_addr                                    "0xB8021048"
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_reg                                         0xB8021048
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_inst_addr                                   "0x0012"
#define  set_SYNC_PROCESSOR_SP2_CLMPCTRL_reg(data)                               (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMPCTRL_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_CLMPCTRL_reg                                     (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMPCTRL_reg))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_13_8_shift                            (8)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_dben_shift                         (7)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_cnt_unit_shift                     (6)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_clksrc_shift                       (5)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_en_shift                           (4)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_yclamp_hs_inv_shift                      (3)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_2_shift                               (2)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_test_en_shift                      (1)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_adc_hs_syncedge_shift                    (0)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_13_8_mask                             (0x00003F00)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_dben_mask                          (0x00000080)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_cnt_unit_mask                      (0x00000040)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_clksrc_mask                        (0x00000020)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_en_mask                            (0x00000010)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_yclamp_hs_inv_mask                       (0x00000008)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_2_mask                                (0x00000004)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_test_en_mask                       (0x00000002)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_adc_hs_syncedge_mask                     (0x00000001)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_13_8(data)                            (0x00003F00&((data)<<8))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_dben(data)                         (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_cnt_unit(data)                     (0x00000040&((data)<<6))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_clksrc(data)                       (0x00000020&((data)<<5))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_en(data)                           (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_yclamp_hs_inv(data)                      (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_dummy_2(data)                               (0x00000004&((data)<<2))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_clamp_test_en(data)                      (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_s2_adc_hs_syncedge(data)                    (0x00000001&(data))
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_dummy_13_8(data)                        ((0x00003F00&(data))>>8)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_clamp_dben(data)                     ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_clamp_cnt_unit(data)                 ((0x00000040&(data))>>6)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_clamp_clksrc(data)                   ((0x00000020&(data))>>5)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_clamp_en(data)                       ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_yclamp_hs_inv(data)                  ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_dummy_2(data)                           ((0x00000004&(data))>>2)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_clamp_test_en(data)                  ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_SP2_CLMPCTRL_get_s2_adc_hs_syncedge(data)                (0x00000001&(data))

#define  SYNC_PROCESSOR_SP2_CLMP                                                 0x1802104C
#define  SYNC_PROCESSOR_SP2_CLMP_reg_addr                                        "0xB802104C"
#define  SYNC_PROCESSOR_SP2_CLMP_reg                                             0xB802104C
#define  SYNC_PROCESSOR_SP2_CLMP_inst_addr                                       "0x0013"
#define  set_SYNC_PROCESSOR_SP2_CLMP_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMP_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_CLMP_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMP_reg))
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_sta_shift                             (24)
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_end_shift                             (16)
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_sta_mask                              (0xFF000000)
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_end_mask                              (0x00FF0000)
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_sta(data)                             (0xFF000000&((data)<<24))
#define  SYNC_PROCESSOR_SP2_CLMP_s2_yclamp_end(data)                             (0x00FF0000&((data)<<16))
#define  SYNC_PROCESSOR_SP2_CLMP_get_s2_yclamp_sta(data)                         ((0xFF000000&(data))>>24)
#define  SYNC_PROCESSOR_SP2_CLMP_get_s2_yclamp_end(data)                         ((0x00FF0000&(data))>>16)

#define  SYNC_PROCESSOR_SP2_CLMPMSK                                              0x18021050
#define  SYNC_PROCESSOR_SP2_CLMPMSK_reg_addr                                     "0xB8021050"
#define  SYNC_PROCESSOR_SP2_CLMPMSK_reg                                          0xB8021050
#define  SYNC_PROCESSOR_SP2_CLMPMSK_inst_addr                                    "0x0014"
#define  set_SYNC_PROCESSOR_SP2_CLMPMSK_reg(data)                                (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMPMSK_reg)=data)
#define  get_SYNC_PROCESSOR_SP2_CLMPMSK_reg                                      (*((volatile unsigned int*)SYNC_PROCESSOR_SP2_CLMPMSK_reg))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_clamp_en_shift                       (15)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_14_shift                               (14)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_front_shift                          (8)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_7_6_shift                              (6)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_back_shift                           (0)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_clamp_en_mask                        (0x00008000)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_14_mask                                (0x00004000)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_front_mask                           (0x00003F00)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_7_6_mask                               (0x000000C0)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_back_mask                            (0x0000003F)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_clamp_en(data)                       (0x00008000&((data)<<15))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_14(data)                               (0x00004000&((data)<<14))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_front(data)                          (0x00003F00&((data)<<8))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_dummy_7_6(data)                              (0x000000C0&((data)<<6))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_s2_mask_back(data)                           (0x0000003F&(data))
#define  SYNC_PROCESSOR_SP2_CLMPMSK_get_s2_mask_clamp_en(data)                   ((0x00008000&(data))>>15)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_get_dummy_14(data)                           ((0x00004000&(data))>>14)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_get_s2_mask_front(data)                      ((0x00003F00&(data))>>8)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_get_dummy_7_6(data)                          ((0x000000C0&(data))>>6)
#define  SYNC_PROCESSOR_SP2_CLMPMSK_get_s2_mask_back(data)                       (0x0000003F&(data))

#define  SYNC_PROCESSOR_Mv_CTRL                                                  0x18021058
#define  SYNC_PROCESSOR_Mv_CTRL_reg_addr                                         "0xB8021058"
#define  SYNC_PROCESSOR_Mv_CTRL_reg                                              0xB8021058
#define  SYNC_PROCESSOR_Mv_CTRL_inst_addr                                        "0x0015"
#define  set_SYNC_PROCESSOR_Mv_CTRL_reg(data)                                    (*((volatile unsigned int*)SYNC_PROCESSOR_Mv_CTRL_reg)=data)
#define  get_SYNC_PROCESSOR_Mv_CTRL_reg                                          (*((volatile unsigned int*)SYNC_PROCESSOR_Mv_CTRL_reg))
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_15_13_shift                                (13)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_deb_num_mvhs_shift                            (8)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_skip_line_len_shift                           (4)
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_3_2_shift                                  (2)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_occur_shift                                (1)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_enable_shift                               (0)
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_15_13_mask                                 (0x0000E000)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_deb_num_mvhs_mask                             (0x00001F00)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_skip_line_len_mask                            (0x000000F0)
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_3_2_mask                                   (0x0000000C)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_occur_mask                                 (0x00000002)
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_enable_mask                                (0x00000001)
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_15_13(data)                                (0x0000E000&((data)<<13))
#define  SYNC_PROCESSOR_Mv_CTRL_s1_deb_num_mvhs(data)                            (0x00001F00&((data)<<8))
#define  SYNC_PROCESSOR_Mv_CTRL_s1_skip_line_len(data)                           (0x000000F0&((data)<<4))
#define  SYNC_PROCESSOR_Mv_CTRL_dummy_3_2(data)                                  (0x0000000C&((data)<<2))
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_occur(data)                                (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_Mv_CTRL_s1_mv_enable(data)                               (0x00000001&(data))
#define  SYNC_PROCESSOR_Mv_CTRL_get_dummy_15_13(data)                            ((0x0000E000&(data))>>13)
#define  SYNC_PROCESSOR_Mv_CTRL_get_s1_deb_num_mvhs(data)                        ((0x00001F00&(data))>>8)
#define  SYNC_PROCESSOR_Mv_CTRL_get_s1_skip_line_len(data)                       ((0x000000F0&(data))>>4)
#define  SYNC_PROCESSOR_Mv_CTRL_get_dummy_3_2(data)                              ((0x0000000C&(data))>>2)
#define  SYNC_PROCESSOR_Mv_CTRL_get_s1_mv_occur(data)                            ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_Mv_CTRL_get_s1_mv_enable(data)                           (0x00000001&(data))

#define  SYNC_PROCESSOR_Mv_fld_Pos                                               0x1802105C
#define  SYNC_PROCESSOR_Mv_fld_Pos_reg_addr                                      "0xB802105C"
#define  SYNC_PROCESSOR_Mv_fld_Pos_reg                                           0xB802105C
#define  SYNC_PROCESSOR_Mv_fld_Pos_inst_addr                                     "0x0016"
#define  set_SYNC_PROCESSOR_Mv_fld_Pos_reg(data)                                 (*((volatile unsigned int*)SYNC_PROCESSOR_Mv_fld_Pos_reg)=data)
#define  get_SYNC_PROCESSOR_Mv_fld_Pos_reg                                       (*((volatile unsigned int*)SYNC_PROCESSOR_Mv_fld_Pos_reg))
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_31_shift                                (31)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_str_shift                             (24)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_rdy_shift                             (23)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_end_shift                             (16)
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_15_shift                                (15)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_str_shift                             (8)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_rdy_shift                             (7)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_end_shift                             (0)
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_31_mask                                 (0x80000000)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_str_mask                              (0x7F000000)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_rdy_mask                              (0x00800000)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_end_mask                              (0x007F0000)
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_15_mask                                 (0x00008000)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_str_mask                              (0x00007F00)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_rdy_mask                              (0x00000080)
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_end_mask                              (0x0000007F)
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_31(data)                                (0x80000000&((data)<<31))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_str(data)                             (0x7F000000&((data)<<24))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_rdy(data)                             (0x00800000&((data)<<23))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_o_mv_end(data)                             (0x007F0000&((data)<<16))
#define  SYNC_PROCESSOR_Mv_fld_Pos_dummy_15(data)                                (0x00008000&((data)<<15))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_str(data)                             (0x00007F00&((data)<<8))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_rdy(data)                             (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_Mv_fld_Pos_s1_e_mv_end(data)                             (0x0000007F&(data))
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_dummy_31(data)                            ((0x80000000&(data))>>31)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_o_mv_str(data)                         ((0x7F000000&(data))>>24)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_o_mv_rdy(data)                         ((0x00800000&(data))>>23)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_o_mv_end(data)                         ((0x007F0000&(data))>>16)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_dummy_15(data)                            ((0x00008000&(data))>>15)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_e_mv_str(data)                         ((0x00007F00&(data))>>8)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_e_mv_rdy(data)                         ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_Mv_fld_Pos_get_s1_e_mv_end(data)                         (0x0000007F&(data))

#define  SYNC_PROCESSOR_Mv2_CTRL                                                 0x18021060
#define  SYNC_PROCESSOR_Mv2_CTRL_reg_addr                                        "0xB8021060"
#define  SYNC_PROCESSOR_Mv2_CTRL_reg                                             0xB8021060
#define  SYNC_PROCESSOR_Mv2_CTRL_inst_addr                                       "0x0017"
#define  set_SYNC_PROCESSOR_Mv2_CTRL_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_Mv2_CTRL_reg)=data)
#define  get_SYNC_PROCESSOR_Mv2_CTRL_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_Mv2_CTRL_reg))
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_15_13_shift                               (13)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_deb_num_mvhs_shift                           (8)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_skip_line_len_shift                          (4)
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_3_1_shift                                 (1)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_mv_enable_shift                              (0)
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_15_13_mask                                (0x0000E000)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_deb_num_mvhs_mask                            (0x00001F00)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_skip_line_len_mask                           (0x000000F0)
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_3_1_mask                                  (0x0000000E)
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_mv_enable_mask                               (0x00000001)
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_15_13(data)                               (0x0000E000&((data)<<13))
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_deb_num_mvhs(data)                           (0x00001F00&((data)<<8))
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_skip_line_len(data)                          (0x000000F0&((data)<<4))
#define  SYNC_PROCESSOR_Mv2_CTRL_dummy_3_1(data)                                 (0x0000000E&((data)<<1))
#define  SYNC_PROCESSOR_Mv2_CTRL_s2_mv_enable(data)                              (0x00000001&(data))
#define  SYNC_PROCESSOR_Mv2_CTRL_get_dummy_15_13(data)                           ((0x0000E000&(data))>>13)
#define  SYNC_PROCESSOR_Mv2_CTRL_get_s2_deb_num_mvhs(data)                       ((0x00001F00&(data))>>8)
#define  SYNC_PROCESSOR_Mv2_CTRL_get_s2_skip_line_len(data)                      ((0x000000F0&(data))>>4)
#define  SYNC_PROCESSOR_Mv2_CTRL_get_dummy_3_1(data)                             ((0x0000000E&(data))>>1)
#define  SYNC_PROCESSOR_Mv2_CTRL_get_s2_mv_enable(data)                          (0x00000001&(data))

#define  SYNC_PROCESSOR_SP_ADCClampSel0                                          0x18021064
#define  SYNC_PROCESSOR_SP_ADCClampSel0_reg_addr                                 "0xB8021064"
#define  SYNC_PROCESSOR_SP_ADCClampSel0_reg                                      0xB8021064
#define  SYNC_PROCESSOR_SP_ADCClampSel0_inst_addr                                "0x0018"
#define  set_SYNC_PROCESSOR_SP_ADCClampSel0_reg(data)                            (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADCClampSel0_reg)=data)
#define  get_SYNC_PROCESSOR_SP_ADCClampSel0_reg                                  (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADCClampSel0_reg))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin32_clamp_sel_shift                (22)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin31_clamp_sel_shift                (20)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin30_clamp_sel_shift                (18)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin22_clamp_sel_shift                (16)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin21_clamp_sel_shift                (14)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin20_clamp_sel_shift                (12)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin12_clamp_sel_shift                (10)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin11_clamp_sel_shift                (8)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin10_clamp_sel_shift                (6)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin02_clamp_sel_shift                (4)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin01_clamp_sel_shift                (2)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin00_clamp_sel_shift                (0)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin32_clamp_sel_mask                 (0x00C00000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin31_clamp_sel_mask                 (0x00300000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin30_clamp_sel_mask                 (0x000C0000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin22_clamp_sel_mask                 (0x00030000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin21_clamp_sel_mask                 (0x0000C000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin20_clamp_sel_mask                 (0x00003000)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin12_clamp_sel_mask                 (0x00000C00)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin11_clamp_sel_mask                 (0x00000300)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin10_clamp_sel_mask                 (0x000000C0)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin02_clamp_sel_mask                 (0x00000030)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin01_clamp_sel_mask                 (0x0000000C)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin00_clamp_sel_mask                 (0x00000003)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin32_clamp_sel(data)                (0x00C00000&((data)<<22))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin31_clamp_sel(data)                (0x00300000&((data)<<20))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin30_clamp_sel(data)                (0x000C0000&((data)<<18))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin22_clamp_sel(data)                (0x00030000&((data)<<16))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin21_clamp_sel(data)                (0x0000C000&((data)<<14))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin20_clamp_sel(data)                (0x00003000&((data)<<12))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin12_clamp_sel(data)                (0x00000C00&((data)<<10))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin11_clamp_sel(data)                (0x00000300&((data)<<8))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin10_clamp_sel(data)                (0x000000C0&((data)<<6))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin02_clamp_sel(data)                (0x00000030&((data)<<4))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin01_clamp_sel(data)                (0x0000000C&((data)<<2))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_adc_vin00_clamp_sel(data)                (0x00000003&(data))
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin32_clamp_sel(data)            ((0x00C00000&(data))>>22)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin31_clamp_sel(data)            ((0x00300000&(data))>>20)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin30_clamp_sel(data)            ((0x000C0000&(data))>>18)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin22_clamp_sel(data)            ((0x00030000&(data))>>16)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin21_clamp_sel(data)            ((0x0000C000&(data))>>14)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin20_clamp_sel(data)            ((0x00003000&(data))>>12)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin12_clamp_sel(data)            ((0x00000C00&(data))>>10)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin11_clamp_sel(data)            ((0x00000300&(data))>>8)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin10_clamp_sel(data)            ((0x000000C0&(data))>>6)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin02_clamp_sel(data)            ((0x00000030&(data))>>4)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin01_clamp_sel(data)            ((0x0000000C&(data))>>2)
#define  SYNC_PROCESSOR_SP_ADCClampSel0_get_adc_vin00_clamp_sel(data)            (0x00000003&(data))

#define  SYNC_PROCESSOR_SP_ADCClampSel1                                          0x18021068
#define  SYNC_PROCESSOR_SP_ADCClampSel1_reg_addr                                 "0xB8021068"
#define  SYNC_PROCESSOR_SP_ADCClampSel1_reg                                      0xB8021068
#define  SYNC_PROCESSOR_SP_ADCClampSel1_inst_addr                                "0x0019"
#define  set_SYNC_PROCESSOR_SP_ADCClampSel1_reg(data)                            (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADCClampSel1_reg)=data)
#define  get_SYNC_PROCESSOR_SP_ADCClampSel1_reg                                  (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADCClampSel1_reg))
#define  SYNC_PROCESSOR_SP_ADCClampSel1_dummy_4_shift                            (4)
#define  SYNC_PROCESSOR_SP_ADCClampSel1_sync_test_sel_shift                      (0)
#define  SYNC_PROCESSOR_SP_ADCClampSel1_dummy_4_mask                             (0x00000010)
#define  SYNC_PROCESSOR_SP_ADCClampSel1_sync_test_sel_mask                       (0x0000000F)
#define  SYNC_PROCESSOR_SP_ADCClampSel1_dummy_4(data)                            (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP_ADCClampSel1_sync_test_sel(data)                      (0x0000000F&(data))
#define  SYNC_PROCESSOR_SP_ADCClampSel1_get_dummy_4(data)                        ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP_ADCClampSel1_get_sync_test_sel(data)                  (0x0000000F&(data))

#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL                                           0x1802106C
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg_addr                                  "0xB802106C"
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg                                       0xB802106C
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_inst_addr                                 "0x001A"
#define  set_SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg(data)                             (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg)=data)
#define  get_SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg                                   (*((volatile unsigned int*)SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_force_rgb_from_adc_shift                  (9)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_rgb_shift                        (8)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_hs_shift                         (7)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_vs_shift                         (6)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_rgb_shift                        (4)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_hs_shift                         (3)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_vs_shift                         (2)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_sync_out_source_shift                     (0)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_force_rgb_from_adc_mask                   (0x00000200)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_rgb_mask                         (0x00000100)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_hs_mask                          (0x00000080)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_vs_mask                          (0x00000040)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_rgb_mask                         (0x00000030)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_hs_mask                          (0x00000008)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_vs_mask                          (0x00000004)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_sync_out_source_mask                      (0x00000003)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_force_rgb_from_adc(data)                  (0x00000200&((data)<<9))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_rgb(data)                        (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_hs(data)                         (0x00000080&((data)<<7))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_syncedge_vs(data)                         (0x00000040&((data)<<6))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_rgb(data)                        (0x00000030&((data)<<4))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_hs(data)                         (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_test_sel_vs(data)                         (0x00000004&((data)<<2))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_sync_out_source(data)                     (0x00000003&(data))
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_force_rgb_from_adc(data)              ((0x00000200&(data))>>9)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_syncedge_rgb(data)                    ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_syncedge_hs(data)                     ((0x00000080&(data))>>7)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_syncedge_vs(data)                     ((0x00000040&(data))>>6)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_test_sel_rgb(data)                    ((0x00000030&(data))>>4)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_test_sel_hs(data)                     ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_test_sel_vs(data)                     ((0x00000004&(data))>>2)
#define  SYNC_PROCESSOR_SP_ADC_OUT_SEL_get_sync_out_source(data)                 (0x00000003&(data))

#define  SYNC_PROCESSOR_SP_PAD_STATUS                                            0x18021070
#define  SYNC_PROCESSOR_SP_PAD_STATUS_reg_addr                                   "0xB8021070"
#define  SYNC_PROCESSOR_SP_PAD_STATUS_reg                                        0xB8021070
#define  SYNC_PROCESSOR_SP_PAD_STATUS_inst_addr                                  "0x001B"
#define  set_SYNC_PROCESSOR_SP_PAD_STATUS_reg(data)                              (*((volatile unsigned int*)SYNC_PROCESSOR_SP_PAD_STATUS_reg)=data)
#define  get_SYNC_PROCESSOR_SP_PAD_STATUS_reg                                    (*((volatile unsigned int*)SYNC_PROCESSOR_SP_PAD_STATUS_reg))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_dummy_7_6_shift                            (6)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog0_shift                         (5)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog1_shift                         (4)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_soy_vd_shift                           (3)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_avs1_shift                         (1)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_ahs1_shift                         (0)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_dummy_7_6_mask                             (0x000000C0)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog0_mask                          (0x00000020)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog1_mask                          (0x00000010)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_soy_vd_mask                            (0x00000008)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_avs1_mask                          (0x00000002)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_ahs1_mask                          (0x00000001)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_dummy_7_6(data)                            (0x000000C0&((data)<<6))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog0(data)                         (0x00000020&((data)<<5))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_adc_sog1(data)                         (0x00000010&((data)<<4))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_soy_vd(data)                           (0x00000008&((data)<<3))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_avs1(data)                         (0x00000002&((data)<<1))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_tog_pad_ahs1(data)                         (0x00000001&(data))
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_dummy_7_6(data)                        ((0x000000C0&(data))>>6)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_tog_adc_sog0(data)                     ((0x00000020&(data))>>5)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_tog_adc_sog1(data)                     ((0x00000010&(data))>>4)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_tog_soy_vd(data)                       ((0x00000008&(data))>>3)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_tog_pad_avs1(data)                     ((0x00000002&(data))>>1)
#define  SYNC_PROCESSOR_SP_PAD_STATUS_get_tog_pad_ahs1(data)                     (0x00000001&(data))

#define  SYNC_PROCESSOR_DEGLITCH                                                 0x18021074
#define  SYNC_PROCESSOR_DEGLITCH_reg_addr                                        "0xB8021074"
#define  SYNC_PROCESSOR_DEGLITCH_reg                                             0xB8021074
#define  SYNC_PROCESSOR_DEGLITCH_inst_addr                                       "0x001C"
#define  set_SYNC_PROCESSOR_DEGLITCH_reg(data)                                   (*((volatile unsigned int*)SYNC_PROCESSOR_DEGLITCH_reg)=data)
#define  get_SYNC_PROCESSOR_DEGLITCH_reg                                         (*((volatile unsigned int*)SYNC_PROCESSOR_DEGLITCH_reg))
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det_rst_shift                            (25)
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det_shift                                (24)
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_no_shift                               (16)
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_auto_shift                             (9)
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_en_shift                            (8)
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_num_shift                           (0)
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det_rst_mask                             (0x02000000)
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det_mask                                 (0x01000000)
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_no_mask                                (0x000F0000)
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_auto_mask                              (0x00000200)
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_en_mask                             (0x00000100)
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_num_mask                            (0x000000FF)
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det_rst(data)                            (0x02000000&((data)<<25))
#define  SYNC_PROCESSOR_DEGLITCH_glitch_det(data)                                (0x01000000&((data)<<24))
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_no(data)                               (0x000F0000&((data)<<16))
#define  SYNC_PROCESSOR_DEGLITCH_pe_delay_auto(data)                             (0x00000200&((data)<<9))
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_en(data)                            (0x00000100&((data)<<8))
#define  SYNC_PROCESSOR_DEGLITCH_hs_deglitch_num(data)                           (0x000000FF&(data))
#define  SYNC_PROCESSOR_DEGLITCH_get_glitch_det_rst(data)                        ((0x02000000&(data))>>25)
#define  SYNC_PROCESSOR_DEGLITCH_get_glitch_det(data)                            ((0x01000000&(data))>>24)
#define  SYNC_PROCESSOR_DEGLITCH_get_pe_delay_no(data)                           ((0x000F0000&(data))>>16)
#define  SYNC_PROCESSOR_DEGLITCH_get_pe_delay_auto(data)                         ((0x00000200&(data))>>9)
#define  SYNC_PROCESSOR_DEGLITCH_get_hs_deglitch_en(data)                        ((0x00000100&(data))>>8)
#define  SYNC_PROCESSOR_DEGLITCH_get_hs_deglitch_num(data)                       (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SYNC_PROCESSOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_dehs_out_en:1;
        RBus_UInt32  dummy18021000_30:1;
        RBus_UInt32  dummy18021000_29:1;
        RBus_UInt32  s1_hsraw_inv:1;
        RBus_UInt32  dummy18021000_27:1;
        RBus_UInt32  dummy18021000_26_24:3;
        RBus_UInt32  hrecovery_en:1;
        RBus_UInt32  s1_adc_vsout_testmd:1;
        RBus_UInt32  s1_devs_out_en:1;
        RBus_UInt32  s1_sel_clpmsk_as_devs:1;
        RBus_UInt32  s1_hsout_inv:1;
        RBus_UInt32  dummy18021000_18:1;
        RBus_UInt32  s1_hs_sync_source:1;
        RBus_UInt32  s1_hsout_en:1;
        RBus_UInt32  dummy18021000_15_13:3;
        RBus_UInt32  s1_seperate_testmode:1;
        RBus_UInt32  s1_auto_run_done_ie:1;
        RBus_UInt32  s1_auto_run:1;
        RBus_UInt32  s1_coast_en:1;
        RBus_UInt32  s1_decmp_en:1;
        RBus_UInt32  dummy18021000_7:1;
        RBus_UInt32  s1_hs_fb_plswid_md:2;
        RBus_UInt32  s1_coast_inv:1;
        RBus_UInt32  dummy18021000_3:1;
        RBus_UInt32  s1_vhs_source_sel:3;
    };
}sync_processor_sp1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_auto_result_rdy:1;
        RBus_UInt32  dummy18021004_30:1;
        RBus_UInt32  s1_unlock_no_vs_str:6;
        RBus_UInt32  s1_unlock_no_vs_end:12;
        RBus_UInt32  res1:5;
        RBus_UInt32  s1_auto_result:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  s1_input_signal_be_inverted:1;
    };
}sync_processor_sp1_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_dehs_out_en:1;
        RBus_UInt32  dummy18021008_30_29:2;
        RBus_UInt32  s2_hsraw_inv:1;
        RBus_UInt32  dummy18021008_27_23:5;
        RBus_UInt32  s2_adc_vsout_testmd:1;
        RBus_UInt32  s2_devs_out_en:1;
        RBus_UInt32  s2_sel_clpmsk_as_devs:1;
        RBus_UInt32  dummy18021008_19_13:7;
        RBus_UInt32  s2_seperate_testmode:1;
        RBus_UInt32  s2_auto_run_done_ie:1;
        RBus_UInt32  s2_auto_run:1;
        RBus_UInt32  dummy18021008_9:1;
        RBus_UInt32  s2_decmp_en:1;
        RBus_UInt32  dummy18021008_7_3:5;
        RBus_UInt32  s2_vhs_source_sel:3;
    };
}sync_processor_sp2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_auto_result_rdy:1;
        RBus_UInt32  dummy1802100c_30:1;
        RBus_UInt32  s2_unlock_no_vs_str:6;
        RBus_UInt32  s2_unlock_no_vs_end:12;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2_auto_result:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  s2_input_signal_be_inverted:1;
    };
}sync_processor_sp2_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  s1_cap_win_range_lsb:2;
        RBus_UInt32  s1_hsper_realtime_stbline:2;
        RBus_UInt32  s1_hsper_realtime_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  s1_cap_win_range:5;
        RBus_UInt32  s1_per_range:3;
        RBus_UInt32  s1_popup_stable_per:1;
        RBus_UInt32  dummy18021010_6_4:3;
        RBus_UInt32  s1_cap_win_step:1;
        RBus_UInt32  s1_miss_lock_limit:1;
        RBus_UInt32  dummy18021010_1:1;
        RBus_UInt32  s1_stable_en:1;
    };
}sync_processor_sp1_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_mode_det_of:1;
        RBus_UInt32  s1_stb_per_chg:1;
        RBus_UInt32  s1_stb_pol_chg:1;
        RBus_UInt32  s1_vs_raw_vld:1;
        RBus_UInt32  s1_cap_32unlock:1;
        RBus_UInt32  s1_eq_occur:1;
        RBus_UInt32  s1_hs_pol_chg:1;
        RBus_UInt32  s1_cap_unlock:1;
        RBus_UInt32  s1_mode_det_stable:1;
        RBus_UInt32  s1_stable_pol_out:1;
        RBus_UInt32  s1_cap_unlock_no_vs:1;
        RBus_UInt32  s1_giltch_in_win:1;
        RBus_UInt32  s1_giltch_in_win_int:1;
        RBus_UInt32  s1_stb_per_chg_wde:1;
        RBus_UInt32  s1_stb_pol_chg_wde:1;
        RBus_UInt32  sync_wd_to_main:1;
        RBus_UInt32  sync_wd_to_sub:1;
        RBus_UInt32  res1:15;
    };
}sync_processor_sp1_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s1_stable_period_out:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s1_stable_plswid_out:11;
    };
}sync_processor_sp1_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  s2_cap_win_range_lsb:2;
        RBus_UInt32  s2_hsper_realtime_stbline:2;
        RBus_UInt32  s2_hsper_realtime_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  s2_cap_win_range:5;
        RBus_UInt32  s2_per_range:3;
        RBus_UInt32  s2_popup_stable_per:1;
        RBus_UInt32  dummy1802101c_6_4:3;
        RBus_UInt32  s2_cap_win_step:1;
        RBus_UInt32  s2_miss_lock_limit:1;
        RBus_UInt32  dummy1802101c_1:1;
        RBus_UInt32  s2_stable_en:1;
    };
}sync_processor_sp2_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_mode_det_of:1;
        RBus_UInt32  s2_stb_per_chg:1;
        RBus_UInt32  s2_stb_pol_chg:1;
        RBus_UInt32  s2_vs_raw_vld:1;
        RBus_UInt32  s2_cap_32unlock:1;
        RBus_UInt32  s2_eq_occur:1;
        RBus_UInt32  s2_hs_pol_chg:1;
        RBus_UInt32  s2_cap_unlock:1;
        RBus_UInt32  s2_mode_det_stable:1;
        RBus_UInt32  s2_stable_pol_out:1;
        RBus_UInt32  s2_cap_unlock_no_vs:1;
        RBus_UInt32  s2_giltch_in_win:1;
        RBus_UInt32  s2_giltch_in_win_int:1;
        RBus_UInt32  res1:19;
    };
}sync_processor_sp2_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2_stable_period_out:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s2_stable_plswid_out:11;
    };
}sync_processor_sp2_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s1_deb_num:5;
        RBus_UInt32  s1_dcnt_level:11;
    };
}sync_processor_sp1_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s2_deb_num:5;
        RBus_UInt32  s2_dcnt_level:11;
    };
}sync_processor_sp2_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  s1_field_det_vs_sel:1;
        RBus_UInt32  s1_field_det_mode:1;
        RBus_UInt32  s1_f_pos_field:1;
        RBus_UInt32  s1_f_pos_field_tgle:1;
        RBus_UInt32  s1_f_count_field:1;
        RBus_UInt32  s1_f_count_field_tgle:1;
        RBus_UInt32  s1_l_cnt_lsb1:3;
    };
}sync_processor_sp1_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18021034_31_9:23;
        RBus_UInt32  s2_field_det_vs_sel:1;
        RBus_UInt32  s2_field_det_mode:1;
        RBus_UInt32  s2_f_pos_field:1;
        RBus_UInt32  s2_f_pos_field_tgle:1;
        RBus_UInt32  s2_f_count_field:1;
        RBus_UInt32  s2_f_count_field_tgle:1;
        RBus_UInt32  s2_l_cnt_lsb1:3;
    };
}sync_processor_sp2_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  dummy18021038_13_8:6;
        RBus_UInt32  s1_clamp_dben:1;
        RBus_UInt32  s1_clamp_cnt_unit:1;
        RBus_UInt32  s1_clamp_clksrc:1;
        RBus_UInt32  s1_clamp_en:1;
        RBus_UInt32  s1_yclamp_hs_inv:1;
        RBus_UInt32  s1_nyclamp_hs_inv:1;
        RBus_UInt32  s1_clamp_test_en:1;
        RBus_UInt32  s1_adc_hs_syncedge:1;
    };
}sync_processor_sp1_clmpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_yclamp_sta:8;
        RBus_UInt32  s1_yclamp_end:8;
        RBus_UInt32  s1_nyclamp_sta:8;
        RBus_UInt32  s1_nyclamp_end:8;
    };
}sync_processor_sp1_clmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s1_mask_clamp_en:1;
        RBus_UInt32  dummy18021040_14:1;
        RBus_UInt32  s1_mask_front:6;
        RBus_UInt32  dummy18021040_7_6:2;
        RBus_UInt32  s1_mask_back:6;
    };
}sync_processor_sp1_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dummy18021044_9_8:2;
        RBus_UInt32  s1_coast_front:4;
        RBus_UInt32  s1_coast_back:4;
    };
}sync_processor_sp1_coastftbk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  dummy18021048_13_8:6;
        RBus_UInt32  s2_clamp_dben:1;
        RBus_UInt32  s2_clamp_cnt_unit:1;
        RBus_UInt32  s2_clamp_clksrc:1;
        RBus_UInt32  s2_clamp_en:1;
        RBus_UInt32  s2_yclamp_hs_inv:1;
        RBus_UInt32  dummy18021048_2:1;
        RBus_UInt32  s2_clamp_test_en:1;
        RBus_UInt32  s2_adc_hs_syncedge:1;
    };
}sync_processor_sp2_clmpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_yclamp_sta:8;
        RBus_UInt32  s2_yclamp_end:8;
        RBus_UInt32  res1:16;
    };
}sync_processor_sp2_clmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s2_mask_clamp_en:1;
        RBus_UInt32  dummy18021050_14:1;
        RBus_UInt32  s2_mask_front:6;
        RBus_UInt32  dummy18021050_7_6:2;
        RBus_UInt32  s2_mask_back:6;
    };
}sync_processor_sp2_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy18021058_15_13:3;
        RBus_UInt32  s1_deb_num_mvhs:5;
        RBus_UInt32  s1_skip_line_len:4;
        RBus_UInt32  dummy18021058_3_2:2;
        RBus_UInt32  s1_mv_occur:1;
        RBus_UInt32  s1_mv_enable:1;
    };
}sync_processor_mv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802105c_31:1;
        RBus_UInt32  s1_o_mv_str:7;
        RBus_UInt32  s1_o_mv_rdy:1;
        RBus_UInt32  s1_o_mv_end:7;
        RBus_UInt32  dummy1802105c_15:1;
        RBus_UInt32  s1_e_mv_str:7;
        RBus_UInt32  s1_e_mv_rdy:1;
        RBus_UInt32  s1_e_mv_end:7;
    };
}sync_processor_mv_fld_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy18021060_15_13:3;
        RBus_UInt32  s2_deb_num_mvhs:5;
        RBus_UInt32  s2_skip_line_len:4;
        RBus_UInt32  dummy18021060_3_1:3;
        RBus_UInt32  s2_mv_enable:1;
    };
}sync_processor_mv2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  adc_vin32_clamp_sel:2;
        RBus_UInt32  adc_vin31_clamp_sel:2;
        RBus_UInt32  adc_vin30_clamp_sel:2;
        RBus_UInt32  adc_vin22_clamp_sel:2;
        RBus_UInt32  adc_vin21_clamp_sel:2;
        RBus_UInt32  adc_vin20_clamp_sel:2;
        RBus_UInt32  adc_vin12_clamp_sel:2;
        RBus_UInt32  adc_vin11_clamp_sel:2;
        RBus_UInt32  adc_vin10_clamp_sel:2;
        RBus_UInt32  adc_vin02_clamp_sel:2;
        RBus_UInt32  adc_vin01_clamp_sel:2;
        RBus_UInt32  adc_vin00_clamp_sel:2;
    };
}sync_processor_sp_adcclampsel0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dummy18021068_4:1;
        RBus_UInt32  sync_test_sel:4;
    };
}sync_processor_sp_adcclampsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  force_rgb_from_adc:1;
        RBus_UInt32  syncedge_rgb:1;
        RBus_UInt32  syncedge_hs:1;
        RBus_UInt32  syncedge_vs:1;
        RBus_UInt32  test_sel_rgb:2;
        RBus_UInt32  test_sel_hs:1;
        RBus_UInt32  test_sel_vs:1;
        RBus_UInt32  sync_out_source:2;
    };
}sync_processor_sp_adc_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18021070_7_6:2;
        RBus_UInt32  tog_adc_sog0:1;
        RBus_UInt32  tog_adc_sog1:1;
        RBus_UInt32  tog_soy_vd:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tog_pad_avs1:1;
        RBus_UInt32  tog_pad_ahs1:1;
    };
}sync_processor_sp_pad_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  glitch_det_rst:1;
        RBus_UInt32  glitch_det:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pe_delay_no:4;
        RBus_UInt32  res3:6;
        RBus_UInt32  pe_delay_auto:1;
        RBus_UInt32  hs_deglitch_en:1;
        RBus_UInt32  hs_deglitch_num:8;
    };
}sync_processor_deglitch_RBUS;

#else //apply LITTLE_ENDIAN

//======SYNC_PROCESSOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_vhs_source_sel:3;
        RBus_UInt32  dummy18021000_3_3:1;
        RBus_UInt32  s1_coast_inv:1;
        RBus_UInt32  s1_hs_fb_plswid_md:2;
        RBus_UInt32  dummy18021000_7_7:1;
        RBus_UInt32  s1_decmp_en:1;
        RBus_UInt32  s1_coast_en:1;
        RBus_UInt32  s1_auto_run:1;
        RBus_UInt32  s1_auto_run_done_ie:1;
        RBus_UInt32  s1_seperate_testmode:1;
        RBus_UInt32  dummy18021000_15_13:3;
        RBus_UInt32  s1_hsout_en:1;
        RBus_UInt32  s1_hs_sync_source:1;
        RBus_UInt32  dummy18021000_18_18:1;
        RBus_UInt32  s1_hsout_inv:1;
        RBus_UInt32  s1_sel_clpmsk_as_devs:1;
        RBus_UInt32  s1_devs_out_en:1;
        RBus_UInt32  s1_adc_vsout_testmd:1;
        RBus_UInt32  hrecovery_en:1;
        RBus_UInt32  dummy18021000_26_24:3;
        RBus_UInt32  dummy18021000_27_27:1;
        RBus_UInt32  s1_hsraw_inv:1;
        RBus_UInt32  dummy18021000_29_29:1;
        RBus_UInt32  dummy18021000_30_30:1;
        RBus_UInt32  s1_dehs_out_en:1;
    };
}sync_processor_sp1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_input_signal_be_inverted:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  s1_auto_result:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  s1_unlock_no_vs_end:12;
        RBus_UInt32  s1_unlock_no_vs_str:6;
        RBus_UInt32  dummy18021004_30:1;
        RBus_UInt32  s1_auto_result_rdy:1;
    };
}sync_processor_sp1_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_vhs_source_sel:3;
        RBus_UInt32  dummy18021008_7_3:5;
        RBus_UInt32  s2_decmp_en:1;
        RBus_UInt32  dummy18021008_9_9:1;
        RBus_UInt32  s2_auto_run:1;
        RBus_UInt32  s2_auto_run_done_ie:1;
        RBus_UInt32  s2_seperate_testmode:1;
        RBus_UInt32  dummy18021008_19_13:7;
        RBus_UInt32  s2_sel_clpmsk_as_devs:1;
        RBus_UInt32  s2_devs_out_en:1;
        RBus_UInt32  s2_adc_vsout_testmd:1;
        RBus_UInt32  dummy18021008_27_23:5;
        RBus_UInt32  s2_hsraw_inv:1;
        RBus_UInt32  dummy18021008_30_29:2;
        RBus_UInt32  s2_dehs_out_en:1;
    };
}sync_processor_sp2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_input_signal_be_inverted:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  s2_auto_result:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  s2_unlock_no_vs_end:12;
        RBus_UInt32  s2_unlock_no_vs_str:6;
        RBus_UInt32  dummy1802100c_30:1;
        RBus_UInt32  s2_auto_result_rdy:1;
    };
}sync_processor_sp2_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_stable_en:1;
        RBus_UInt32  dummy18021010_1:1;
        RBus_UInt32  s1_miss_lock_limit:1;
        RBus_UInt32  s1_cap_win_step:1;
        RBus_UInt32  dummy18021010_6:3;
        RBus_UInt32  s1_popup_stable_per:1;
        RBus_UInt32  s1_per_range:3;
        RBus_UInt32  s1_cap_win_range:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  s1_hsper_realtime_en:1;
        RBus_UInt32  s1_hsper_realtime_stbline:2;
        RBus_UInt32  s1_cap_win_range_lsb:2;
        RBus_UInt32  res2:10;
    };
}sync_processor_sp1_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sync_wd_to_sub:1;
        RBus_UInt32  sync_wd_to_main:1;
        RBus_UInt32  s1_stb_pol_chg_wde:1;
        RBus_UInt32  s1_stb_per_chg_wde:1;
        RBus_UInt32  s1_giltch_in_win_int:1;
        RBus_UInt32  s1_giltch_in_win:1;
        RBus_UInt32  s1_cap_unlock_no_vs:1;
        RBus_UInt32  s1_stable_pol_out:1;
        RBus_UInt32  s1_mode_det_stable:1;
        RBus_UInt32  s1_cap_unlock:1;
        RBus_UInt32  s1_hs_pol_chg:1;
        RBus_UInt32  s1_eq_occur:1;
        RBus_UInt32  s1_cap_32unlock:1;
        RBus_UInt32  s1_vs_raw_vld:1;
        RBus_UInt32  s1_stb_pol_chg:1;
        RBus_UInt32  s1_stb_per_chg:1;
        RBus_UInt32  s1_mode_det_of:1;
    };
}sync_processor_sp1_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_stable_plswid_out:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s1_stable_period_out:11;
        RBus_UInt32  res2:5;
    };
}sync_processor_sp1_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_stable_en:1;
        RBus_UInt32  dummy1802101c_1:1;
        RBus_UInt32  s2_miss_lock_limit:1;
        RBus_UInt32  s2_cap_win_step:1;
        RBus_UInt32  dummy1802101c_6:3;
        RBus_UInt32  s2_popup_stable_per:1;
        RBus_UInt32  s2_per_range:3;
        RBus_UInt32  s2_cap_win_range:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  s2_hsper_realtime_en:1;
        RBus_UInt32  s2_hsper_realtime_stbline:2;
        RBus_UInt32  s2_cap_win_range_lsb:2;
        RBus_UInt32  res2:10;
    };
}sync_processor_sp2_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  s2_giltch_in_win_int:1;
        RBus_UInt32  s2_giltch_in_win:1;
        RBus_UInt32  s2_cap_unlock_no_vs:1;
        RBus_UInt32  s2_stable_pol_out:1;
        RBus_UInt32  s2_mode_det_stable:1;
        RBus_UInt32  s2_cap_unlock:1;
        RBus_UInt32  s2_hs_pol_chg:1;
        RBus_UInt32  s2_eq_occur:1;
        RBus_UInt32  s2_cap_32unlock:1;
        RBus_UInt32  s2_vs_raw_vld:1;
        RBus_UInt32  s2_stb_pol_chg:1;
        RBus_UInt32  s2_stb_per_chg:1;
        RBus_UInt32  s2_mode_det_of:1;
    };
}sync_processor_sp2_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_stable_plswid_out:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2_stable_period_out:11;
        RBus_UInt32  res2:5;
    };
}sync_processor_sp2_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_dcnt_level:11;
        RBus_UInt32  s1_deb_num:5;
        RBus_UInt32  res1:16;
    };
}sync_processor_sp1_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_dcnt_level:11;
        RBus_UInt32  s2_deb_num:5;
        RBus_UInt32  res1:16;
    };
}sync_processor_sp2_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_l_cnt_lsb1:3;
        RBus_UInt32  s1_f_count_field_tgle:1;
        RBus_UInt32  s1_f_count_field:1;
        RBus_UInt32  s1_f_pos_field_tgle:1;
        RBus_UInt32  s1_f_pos_field:1;
        RBus_UInt32  s1_field_det_mode:1;
        RBus_UInt32  s1_field_det_vs_sel:1;
        RBus_UInt32  res1:23;
    };
}sync_processor_sp1_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_l_cnt_lsb1:3;
        RBus_UInt32  s2_f_count_field_tgle:1;
        RBus_UInt32  s2_f_count_field:1;
        RBus_UInt32  s2_f_pos_field_tgle:1;
        RBus_UInt32  s2_f_pos_field:1;
        RBus_UInt32  s2_field_det_mode:1;
        RBus_UInt32  s2_field_det_vs_sel:1;
        RBus_UInt32  dummy18021034_31_9:23;
    };
}sync_processor_sp2_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_adc_hs_syncedge:1;
        RBus_UInt32  s1_clamp_test_en:1;
        RBus_UInt32  s1_nyclamp_hs_inv:1;
        RBus_UInt32  s1_yclamp_hs_inv:1;
        RBus_UInt32  s1_clamp_en:1;
        RBus_UInt32  s1_clamp_clksrc:1;
        RBus_UInt32  s1_clamp_cnt_unit:1;
        RBus_UInt32  s1_clamp_dben:1;
        RBus_UInt32  dummy18021038_13:6;
        RBus_UInt32  res1:18;
    };
}sync_processor_sp1_clmpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_nyclamp_end:8;
        RBus_UInt32  s1_nyclamp_sta:8;
        RBus_UInt32  s1_yclamp_end:8;
        RBus_UInt32  s1_yclamp_sta:8;
    };
}sync_processor_sp1_clmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_mask_back:6;
        RBus_UInt32  dummy18021040_7_6:2;
        RBus_UInt32  s1_mask_front:6;
        RBus_UInt32  dummy18021040_14_14:1;
        RBus_UInt32  s1_mask_clamp_en:1;
        RBus_UInt32  res1:16;
    };
}sync_processor_sp1_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_coast_back:4;
        RBus_UInt32  s1_coast_front:4;
        RBus_UInt32  dummy18021044_9_8:2;
        RBus_UInt32  res1:22;
    };
}sync_processor_sp1_coastftbk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_adc_hs_syncedge:1;
        RBus_UInt32  s2_clamp_test_en:1;
        RBus_UInt32  dummy18021048_2:1;
        RBus_UInt32  s2_yclamp_hs_inv:1;
        RBus_UInt32  s2_clamp_en:1;
        RBus_UInt32  s2_clamp_clksrc:1;
        RBus_UInt32  s2_clamp_cnt_unit:1;
        RBus_UInt32  s2_clamp_dben:1;
        RBus_UInt32  dummy18021048_13:6;
        RBus_UInt32  res1:18;
    };
}sync_processor_sp2_clmpctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s2_yclamp_end:8;
        RBus_UInt32  s2_yclamp_sta:8;
    };
}sync_processor_sp2_clmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_mask_back:6;
        RBus_UInt32  dummy18021050_7_6:2;
        RBus_UInt32  s2_mask_front:6;
        RBus_UInt32  dummy18021050_14_14:1;
        RBus_UInt32  s2_mask_clamp_en:1;
        RBus_UInt32  res1:16;
    };
}sync_processor_sp2_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_mv_enable:1;
        RBus_UInt32  s1_mv_occur:1;
        RBus_UInt32  dummy18021058_3:2;
        RBus_UInt32  s1_skip_line_len:4;
        RBus_UInt32  s1_deb_num_mvhs:5;
        RBus_UInt32  dummy18021058_15:3;
        RBus_UInt32  res1:16;
    };
}sync_processor_mv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1_e_mv_end:7;
        RBus_UInt32  s1_e_mv_rdy:1;
        RBus_UInt32  s1_e_mv_str:7;
        RBus_UInt32  dummy1802105c_15_15:1;
        RBus_UInt32  s1_o_mv_end:7;
        RBus_UInt32  s1_o_mv_rdy:1;
        RBus_UInt32  s1_o_mv_str:7;
        RBus_UInt32  dummy1802105c_31_31:1;
    };
}sync_processor_mv_fld_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s2_mv_enable:1;
        RBus_UInt32  dummy18021060_3:3;
        RBus_UInt32  s2_skip_line_len:4;
        RBus_UInt32  s2_deb_num_mvhs:5;
        RBus_UInt32  dummy18021060_15:3;
        RBus_UInt32  res1:16;
    };
}sync_processor_mv2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_vin00_clamp_sel:2;
        RBus_UInt32  adc_vin01_clamp_sel:2;
        RBus_UInt32  adc_vin02_clamp_sel:2;
        RBus_UInt32  adc_vin10_clamp_sel:2;
        RBus_UInt32  adc_vin11_clamp_sel:2;
        RBus_UInt32  adc_vin12_clamp_sel:2;
        RBus_UInt32  adc_vin20_clamp_sel:2;
        RBus_UInt32  adc_vin21_clamp_sel:2;
        RBus_UInt32  adc_vin22_clamp_sel:2;
        RBus_UInt32  adc_vin30_clamp_sel:2;
        RBus_UInt32  adc_vin31_clamp_sel:2;
        RBus_UInt32  adc_vin32_clamp_sel:2;
        RBus_UInt32  res1:8;
    };
}sync_processor_sp_adcclampsel0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_test_sel:4;
        RBus_UInt32  dummy18021068_4_4:1;
        RBus_UInt32  res1:27;
    };
}sync_processor_sp_adcclampsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_out_source:2;
        RBus_UInt32  test_sel_vs:1;
        RBus_UInt32  test_sel_hs:1;
        RBus_UInt32  test_sel_rgb:2;
        RBus_UInt32  syncedge_vs:1;
        RBus_UInt32  syncedge_hs:1;
        RBus_UInt32  syncedge_rgb:1;
        RBus_UInt32  force_rgb_from_adc:1;
        RBus_UInt32  res1:22;
    };
}sync_processor_sp_adc_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tog_pad_ahs1:1;
        RBus_UInt32  tog_pad_avs1:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tog_soy_vd:1;
        RBus_UInt32  tog_adc_sog1:1;
        RBus_UInt32  tog_adc_sog0:1;
        RBus_UInt32  dummy18021070_7:2;
        RBus_UInt32  res2:24;
    };
}sync_processor_sp_pad_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hs_deglitch_num:8;
        RBus_UInt32  hs_deglitch_en:1;
        RBus_UInt32  pe_delay_auto:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  pe_delay_no:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  glitch_det:1;
        RBus_UInt32  glitch_det_rst:1;
        RBus_UInt32  res3:6;
    };
}sync_processor_deglitch_RBUS;




#endif 


#endif 
