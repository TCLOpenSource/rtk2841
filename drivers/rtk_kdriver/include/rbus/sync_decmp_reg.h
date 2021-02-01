/**
* @file MacArthur5-DesignSpec-StandbyTop_SyncProcessor
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SYNC_DECMP_REG_H_
#define _RBUS_SYNC_DECMP_REG_H_

#include "rbus_types.h"



//  SYNC_DECMP Register Address
#define  SYNC_DECMP_ST_SP_CTRL                                                   0x18062000
#define  SYNC_DECMP_ST_SP_CTRL_reg_addr                                          "0xB8062000"
#define  SYNC_DECMP_ST_SP_CTRL_reg                                               0xB8062000
#define  SYNC_DECMP_ST_SP_CTRL_inst_addr                                         "0x0000"
#define  set_SYNC_DECMP_ST_SP_CTRL_reg(data)                                     (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CTRL_reg)=data)
#define  get_SYNC_DECMP_ST_SP_CTRL_reg                                           (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CTRL_reg))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_dehs_out_en_shift                           (31)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_30_shift                                    (30)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_29_shift                                    (29)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsraw_inv_shift                             (28)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_27_shift                                    (27)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_26_24_shift                                 (24)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hrecovery_en_shift                          (23)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_adc_vsout_testmd_shift                      (22)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_devs_out_en_shift                           (21)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_sel_clpmsk_as_devs_shift                    (20)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_inv_shift                             (19)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_18_shift                                    (18)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_sync_source_shift                        (17)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_en_shift                              (16)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_15_13_shift                                 (13)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_seperate_testmode_shift                     (12)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run_done_ie_shift                      (11)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run_shift                              (10)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_en_shift                              (9)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_decmp_en_shift                              (8)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_7_shift                                     (7)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_fb_plswid_md_shift                       (5)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_inv_shift                             (4)
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_vsync_inv_shift                           (3)
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_src_sel_shift                             (2)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_polling_en_shift                            (1)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_vhs_source_sel_shift                        (0)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_dehs_out_en_mask                            (0x80000000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_30_mask                                     (0x40000000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_29_mask                                     (0x20000000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsraw_inv_mask                              (0x10000000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_27_mask                                     (0x08000000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_26_24_mask                                  (0x07000000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hrecovery_en_mask                           (0x00800000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_adc_vsout_testmd_mask                       (0x00400000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_devs_out_en_mask                            (0x00200000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_sel_clpmsk_as_devs_mask                     (0x00100000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_inv_mask                              (0x00080000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_18_mask                                     (0x00040000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_sync_source_mask                         (0x00020000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_en_mask                               (0x00010000)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_15_13_mask                                  (0x0000E000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_seperate_testmode_mask                      (0x00001000)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run_done_ie_mask                       (0x00000800)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run_mask                               (0x00000400)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_en_mask                               (0x00000200)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_decmp_en_mask                               (0x00000100)
#define  SYNC_DECMP_ST_SP_CTRL_dummy_7_mask                                      (0x00000080)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_fb_plswid_md_mask                        (0x00000060)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_inv_mask                              (0x00000010)
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_vsync_inv_mask                            (0x00000008)
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_src_sel_mask                              (0x00000004)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_polling_en_mask                             (0x00000002)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_vhs_source_sel_mask                         (0x00000001)
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_dehs_out_en(data)                           (0x80000000&((data)<<31))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_30(data)                                    (0x40000000&((data)<<30))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_29(data)                                    (0x20000000&((data)<<29))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsraw_inv(data)                             (0x10000000&((data)<<28))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_27(data)                                    (0x08000000&((data)<<27))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_26_24(data)                                 (0x07000000&((data)<<24))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hrecovery_en(data)                          (0x00800000&((data)<<23))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_adc_vsout_testmd(data)                      (0x00400000&((data)<<22))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_devs_out_en(data)                           (0x00200000&((data)<<21))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_sel_clpmsk_as_devs(data)                    (0x00100000&((data)<<20))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_inv(data)                             (0x00080000&((data)<<19))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_18(data)                                    (0x00040000&((data)<<18))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_sync_source(data)                        (0x00020000&((data)<<17))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hsout_en(data)                              (0x00010000&((data)<<16))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_15_13(data)                                 (0x0000E000&((data)<<13))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_seperate_testmode(data)                     (0x00001000&((data)<<12))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run_done_ie(data)                      (0x00000800&((data)<<11))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_auto_run(data)                              (0x00000400&((data)<<10))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_en(data)                              (0x00000200&((data)<<9))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_decmp_en(data)                              (0x00000100&((data)<<8))
#define  SYNC_DECMP_ST_SP_CTRL_dummy_7(data)                                     (0x00000080&((data)<<7))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_hs_fb_plswid_md(data)                       (0x00000060&((data)<<5))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_coast_inv(data)                             (0x00000010&((data)<<4))
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_vsync_inv(data)                           (0x00000008&((data)<<3))
#define  SYNC_DECMP_ST_SP_CTRL_reg_ddc_src_sel(data)                             (0x00000004&((data)<<2))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_polling_en(data)                            (0x00000002&((data)<<1))
#define  SYNC_DECMP_ST_SP_CTRL_st_sp_vhs_source_sel(data)                        (0x00000001&(data))
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_dehs_out_en(data)                       ((0x80000000&(data))>>31)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_30(data)                                ((0x40000000&(data))>>30)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_29(data)                                ((0x20000000&(data))>>29)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hsraw_inv(data)                         ((0x10000000&(data))>>28)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_27(data)                                ((0x08000000&(data))>>27)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_26_24(data)                             ((0x07000000&(data))>>24)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hrecovery_en(data)                      ((0x00800000&(data))>>23)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_adc_vsout_testmd(data)                  ((0x00400000&(data))>>22)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_devs_out_en(data)                       ((0x00200000&(data))>>21)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_sel_clpmsk_as_devs(data)                ((0x00100000&(data))>>20)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hsout_inv(data)                         ((0x00080000&(data))>>19)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_18(data)                                ((0x00040000&(data))>>18)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hs_sync_source(data)                    ((0x00020000&(data))>>17)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hsout_en(data)                          ((0x00010000&(data))>>16)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_15_13(data)                             ((0x0000E000&(data))>>13)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_seperate_testmode(data)                 ((0x00001000&(data))>>12)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_auto_run_done_ie(data)                  ((0x00000800&(data))>>11)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_auto_run(data)                          ((0x00000400&(data))>>10)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_coast_en(data)                          ((0x00000200&(data))>>9)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_decmp_en(data)                          ((0x00000100&(data))>>8)
#define  SYNC_DECMP_ST_SP_CTRL_get_dummy_7(data)                                 ((0x00000080&(data))>>7)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_hs_fb_plswid_md(data)                   ((0x00000060&(data))>>5)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_coast_inv(data)                         ((0x00000010&(data))>>4)
#define  SYNC_DECMP_ST_SP_CTRL_get_reg_ddc_vsync_inv(data)                       ((0x00000008&(data))>>3)
#define  SYNC_DECMP_ST_SP_CTRL_get_reg_ddc_src_sel(data)                         ((0x00000004&(data))>>2)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_polling_en(data)                        ((0x00000002&(data))>>1)
#define  SYNC_DECMP_ST_SP_CTRL_get_st_sp_vhs_source_sel(data)                    (0x00000001&(data))

#define  SYNC_DECMP_ST_SP_AutoRst                                                0x18062004
#define  SYNC_DECMP_ST_SP_AutoRst_reg_addr                                       "0xB8062004"
#define  SYNC_DECMP_ST_SP_AutoRst_reg                                            0xB8062004
#define  SYNC_DECMP_ST_SP_AutoRst_inst_addr                                      "0x0001"
#define  set_SYNC_DECMP_ST_SP_AutoRst_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_SP_AutoRst_reg)=data)
#define  get_SYNC_DECMP_ST_SP_AutoRst_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_SP_AutoRst_reg))
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result_rdy_shift                    (31)
#define  SYNC_DECMP_ST_SP_AutoRst_dummy_30_shift                                 (30)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_str_shift                   (24)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_end_shift                   (12)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result_shift                        (4)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_input_signal_be_inverted_shift           (0)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result_rdy_mask                     (0x80000000)
#define  SYNC_DECMP_ST_SP_AutoRst_dummy_30_mask                                  (0x40000000)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_str_mask                    (0x3F000000)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_end_mask                    (0x00FFF000)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result_mask                         (0x00000070)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_input_signal_be_inverted_mask            (0x00000001)
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result_rdy(data)                    (0x80000000&((data)<<31))
#define  SYNC_DECMP_ST_SP_AutoRst_dummy_30(data)                                 (0x40000000&((data)<<30))
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_str(data)                   (0x3F000000&((data)<<24))
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_unlock_no_vs_end(data)                   (0x00FFF000&((data)<<12))
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_auto_result(data)                        (0x00000070&((data)<<4))
#define  SYNC_DECMP_ST_SP_AutoRst_st_sp_input_signal_be_inverted(data)           (0x00000001&(data))
#define  SYNC_DECMP_ST_SP_AutoRst_get_st_sp_auto_result_rdy(data)                ((0x80000000&(data))>>31)
#define  SYNC_DECMP_ST_SP_AutoRst_get_dummy_30(data)                             ((0x40000000&(data))>>30)
#define  SYNC_DECMP_ST_SP_AutoRst_get_st_sp_unlock_no_vs_str(data)               ((0x3F000000&(data))>>24)
#define  SYNC_DECMP_ST_SP_AutoRst_get_st_sp_unlock_no_vs_end(data)               ((0x00FFF000&(data))>>12)
#define  SYNC_DECMP_ST_SP_AutoRst_get_st_sp_auto_result(data)                    ((0x00000070&(data))>>4)
#define  SYNC_DECMP_ST_SP_AutoRst_get_st_sp_input_signal_be_inverted(data)       (0x00000001&(data))

#define  SYNC_DECMP_ST_SP_StbCtrl                                                0x18062008
#define  SYNC_DECMP_ST_SP_StbCtrl_reg_addr                                       "0xB8062008"
#define  SYNC_DECMP_ST_SP_StbCtrl_reg                                            0xB8062008
#define  SYNC_DECMP_ST_SP_StbCtrl_inst_addr                                      "0x0002"
#define  set_SYNC_DECMP_ST_SP_StbCtrl_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbCtrl_reg)=data)
#define  get_SYNC_DECMP_ST_SP_StbCtrl_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbCtrl_reg))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range_lsb_shift                  (20)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_stbline_shift             (18)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_en_shift                  (17)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_clo_shift                        (16)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range_shift                      (11)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_per_range_shift                          (8)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_popup_stable_per_shift                   (7)
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_6_4_shift                                (4)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_step_shift                       (3)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_miss_lock_limit_shift                    (2)
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_1_shift                                  (1)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_stable_en_shift                          (0)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range_lsb_mask                   (0x00300000)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_stbline_mask              (0x000C0000)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_en_mask                   (0x00020000)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_clo_mask                         (0x00010000)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range_mask                       (0x0000F800)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_per_range_mask                           (0x00000700)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_popup_stable_per_mask                    (0x00000080)
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_6_4_mask                                 (0x00000070)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_step_mask                        (0x00000008)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_miss_lock_limit_mask                     (0x00000004)
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_1_mask                                   (0x00000002)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_stable_en_mask                           (0x00000001)
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range_lsb(data)                  (0x00300000&((data)<<20))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_stbline(data)             (0x000C0000&((data)<<18))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_hsper_realtime_en(data)                  (0x00020000&((data)<<17))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_clo(data)                        (0x00010000&((data)<<16))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_range(data)                      (0x0000F800&((data)<<11))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_per_range(data)                          (0x00000700&((data)<<8))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_popup_stable_per(data)                   (0x00000080&((data)<<7))
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_6_4(data)                                (0x00000070&((data)<<4))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_cap_win_step(data)                       (0x00000008&((data)<<3))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_miss_lock_limit(data)                    (0x00000004&((data)<<2))
#define  SYNC_DECMP_ST_SP_StbCtrl_dummy_1(data)                                  (0x00000002&((data)<<1))
#define  SYNC_DECMP_ST_SP_StbCtrl_st_sp_stable_en(data)                          (0x00000001&(data))
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_cap_win_range_lsb(data)              ((0x00300000&(data))>>20)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_hsper_realtime_stbline(data)         ((0x000C0000&(data))>>18)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_hsper_realtime_en(data)              ((0x00020000&(data))>>17)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_cap_win_clo(data)                    ((0x00010000&(data))>>16)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_cap_win_range(data)                  ((0x0000F800&(data))>>11)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_per_range(data)                      ((0x00000700&(data))>>8)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_popup_stable_per(data)               ((0x00000080&(data))>>7)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_dummy_6_4(data)                            ((0x00000070&(data))>>4)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_cap_win_step(data)                   ((0x00000008&(data))>>3)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_miss_lock_limit(data)                ((0x00000004&(data))>>2)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_dummy_1(data)                              ((0x00000002&(data))>>1)
#define  SYNC_DECMP_ST_SP_StbCtrl_get_st_sp_stable_en(data)                      (0x00000001&(data))

#define  SYNC_DECMP_ST_SP_StbRst0                                                0x1806200C
#define  SYNC_DECMP_ST_SP_StbRst0_reg_addr                                       "0xB806200C"
#define  SYNC_DECMP_ST_SP_StbRst0_reg                                            0xB806200C
#define  SYNC_DECMP_ST_SP_StbRst0_inst_addr                                      "0x0003"
#define  set_SYNC_DECMP_ST_SP_StbRst0_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbRst0_reg)=data)
#define  get_SYNC_DECMP_ST_SP_StbRst0_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbRst0_reg))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_of_shift                        (31)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_per_chg_shift                        (30)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_pol_chg_shift                        (29)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_vs_raw_vld_shift                         (28)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_32unlock_shift                       (27)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_eq_occur_shift                           (26)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_hs_pol_chg_shift                         (25)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock_shift                         (24)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable_shift                    (23)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stable_pol_out_shift                     (22)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock_no_vs_shift                   (21)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_giltch_in_win_shift                      (20)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det_shift                           (19)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det_ie_shift                        (18)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable_ie_shift                 (17)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_of_mask                         (0x80000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_per_chg_mask                         (0x40000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_pol_chg_mask                         (0x20000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_vs_raw_vld_mask                          (0x10000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_32unlock_mask                        (0x08000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_eq_occur_mask                            (0x04000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_hs_pol_chg_mask                          (0x02000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock_mask                          (0x01000000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable_mask                     (0x00800000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stable_pol_out_mask                      (0x00400000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock_no_vs_mask                    (0x00200000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_giltch_in_win_mask                       (0x00100000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det_mask                            (0x00080000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det_ie_mask                         (0x00040000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable_ie_mask                  (0x00020000)
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_of(data)                        (0x80000000&((data)<<31))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_per_chg(data)                        (0x40000000&((data)<<30))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stb_pol_chg(data)                        (0x20000000&((data)<<29))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_vs_raw_vld(data)                         (0x10000000&((data)<<28))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_32unlock(data)                       (0x08000000&((data)<<27))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_eq_occur(data)                           (0x04000000&((data)<<26))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_hs_pol_chg(data)                         (0x02000000&((data)<<25))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock(data)                         (0x01000000&((data)<<24))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable(data)                    (0x00800000&((data)<<23))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_stable_pol_out(data)                     (0x00400000&((data)<<22))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_cap_unlock_no_vs(data)                   (0x00200000&((data)<<21))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_giltch_in_win(data)                      (0x00100000&((data)<<20))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det(data)                           (0x00080000&((data)<<19))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_type_det_ie(data)                        (0x00040000&((data)<<18))
#define  SYNC_DECMP_ST_SP_StbRst0_st_sp_mode_det_stable_ie(data)                 (0x00020000&((data)<<17))
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_mode_det_of(data)                    ((0x80000000&(data))>>31)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_stb_per_chg(data)                    ((0x40000000&(data))>>30)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_stb_pol_chg(data)                    ((0x20000000&(data))>>29)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_vs_raw_vld(data)                     ((0x10000000&(data))>>28)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_cap_32unlock(data)                   ((0x08000000&(data))>>27)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_eq_occur(data)                       ((0x04000000&(data))>>26)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_hs_pol_chg(data)                     ((0x02000000&(data))>>25)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_cap_unlock(data)                     ((0x01000000&(data))>>24)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_mode_det_stable(data)                ((0x00800000&(data))>>23)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_stable_pol_out(data)                 ((0x00400000&(data))>>22)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_cap_unlock_no_vs(data)               ((0x00200000&(data))>>21)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_giltch_in_win(data)                  ((0x00100000&(data))>>20)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_type_det(data)                       ((0x00080000&(data))>>19)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_type_det_ie(data)                    ((0x00040000&(data))>>18)
#define  SYNC_DECMP_ST_SP_StbRst0_get_st_sp_mode_det_stable_ie(data)             ((0x00020000&(data))>>17)

#define  SYNC_DECMP_ST_SP_StbRst1                                                0x18062010
#define  SYNC_DECMP_ST_SP_StbRst1_reg_addr                                       "0xB8062010"
#define  SYNC_DECMP_ST_SP_StbRst1_reg                                            0xB8062010
#define  SYNC_DECMP_ST_SP_StbRst1_inst_addr                                      "0x0004"
#define  set_SYNC_DECMP_ST_SP_StbRst1_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbRst1_reg)=data)
#define  get_SYNC_DECMP_ST_SP_StbRst1_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_SP_StbRst1_reg))
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_period_out_shift                  (16)
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_plswid_out_shift                  (0)
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_period_out_mask                   (0x07FF0000)
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_plswid_out_mask                   (0x000007FF)
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_period_out(data)                  (0x07FF0000&((data)<<16))
#define  SYNC_DECMP_ST_SP_StbRst1_st_sp_stable_plswid_out(data)                  (0x000007FF&(data))
#define  SYNC_DECMP_ST_SP_StbRst1_get_st_sp_stable_period_out(data)              ((0x07FF0000&(data))>>16)
#define  SYNC_DECMP_ST_SP_StbRst1_get_st_sp_stable_plswid_out(data)              (0x000007FF&(data))

#define  SYNC_DECMP_ST_SP_dcnt                                                   0x18062014
#define  SYNC_DECMP_ST_SP_dcnt_reg_addr                                          "0xB8062014"
#define  SYNC_DECMP_ST_SP_dcnt_reg                                               0xB8062014
#define  SYNC_DECMP_ST_SP_dcnt_inst_addr                                         "0x0005"
#define  set_SYNC_DECMP_ST_SP_dcnt_reg(data)                                     (*((volatile unsigned int*)SYNC_DECMP_ST_SP_dcnt_reg)=data)
#define  get_SYNC_DECMP_ST_SP_dcnt_reg                                           (*((volatile unsigned int*)SYNC_DECMP_ST_SP_dcnt_reg))
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_deb_num_shift                               (11)
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_dcnt_level_shift                            (0)
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_deb_num_mask                                (0x0000F800)
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_dcnt_level_mask                             (0x000007FF)
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_deb_num(data)                               (0x0000F800&((data)<<11))
#define  SYNC_DECMP_ST_SP_dcnt_st_sp_dcnt_level(data)                            (0x000007FF&(data))
#define  SYNC_DECMP_ST_SP_dcnt_get_st_sp_deb_num(data)                           ((0x0000F800&(data))>>11)
#define  SYNC_DECMP_ST_SP_dcnt_get_st_sp_dcnt_level(data)                        (0x000007FF&(data))

#define  SYNC_DECMP_ST_SP_Field                                                  0x18062018
#define  SYNC_DECMP_ST_SP_Field_reg_addr                                         "0xB8062018"
#define  SYNC_DECMP_ST_SP_Field_reg                                              0xB8062018
#define  SYNC_DECMP_ST_SP_Field_inst_addr                                        "0x0006"
#define  set_SYNC_DECMP_ST_SP_Field_reg(data)                                    (*((volatile unsigned int*)SYNC_DECMP_ST_SP_Field_reg)=data)
#define  get_SYNC_DECMP_ST_SP_Field_reg                                          (*((volatile unsigned int*)SYNC_DECMP_ST_SP_Field_reg))
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_vs_sel_shift                     (8)
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_mode_shift                       (7)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field_shift                          (6)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field_tgle_shift                     (5)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field_shift                        (4)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field_tgle_shift                   (3)
#define  SYNC_DECMP_ST_SP_Field_st_sp_l_cnt_lsb1_shift                           (0)
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_vs_sel_mask                      (0x00000100)
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_mode_mask                        (0x00000080)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field_mask                           (0x00000040)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field_tgle_mask                      (0x00000020)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field_mask                         (0x00000010)
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field_tgle_mask                    (0x00000008)
#define  SYNC_DECMP_ST_SP_Field_st_sp_l_cnt_lsb1_mask                            (0x00000007)
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_vs_sel(data)                     (0x00000100&((data)<<8))
#define  SYNC_DECMP_ST_SP_Field_st_sp_field_det_mode(data)                       (0x00000080&((data)<<7))
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field(data)                          (0x00000040&((data)<<6))
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_pos_field_tgle(data)                     (0x00000020&((data)<<5))
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field(data)                        (0x00000010&((data)<<4))
#define  SYNC_DECMP_ST_SP_Field_st_sp_f_count_field_tgle(data)                   (0x00000008&((data)<<3))
#define  SYNC_DECMP_ST_SP_Field_st_sp_l_cnt_lsb1(data)                           (0x00000007&(data))
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_field_det_vs_sel(data)                 ((0x00000100&(data))>>8)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_field_det_mode(data)                   ((0x00000080&(data))>>7)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_f_pos_field(data)                      ((0x00000040&(data))>>6)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_f_pos_field_tgle(data)                 ((0x00000020&(data))>>5)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_f_count_field(data)                    ((0x00000010&(data))>>4)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_f_count_field_tgle(data)               ((0x00000008&(data))>>3)
#define  SYNC_DECMP_ST_SP_Field_get_st_sp_l_cnt_lsb1(data)                       (0x00000007&(data))

#define  SYNC_DECMP_ST_SP_CLMPMSK                                                0x1806201C
#define  SYNC_DECMP_ST_SP_CLMPMSK_reg_addr                                       "0xB806201C"
#define  SYNC_DECMP_ST_SP_CLMPMSK_reg                                            0xB806201C
#define  SYNC_DECMP_ST_SP_CLMPMSK_inst_addr                                      "0x0007"
#define  set_SYNC_DECMP_ST_SP_CLMPMSK_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CLMPMSK_reg)=data)
#define  get_SYNC_DECMP_ST_SP_CLMPMSK_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CLMPMSK_reg))
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_clamp_en_shift                      (15)
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_14_shift                                 (14)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_front_shift                         (8)
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_7_6_shift                                (6)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_back_shift                          (0)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_clamp_en_mask                       (0x00008000)
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_14_mask                                  (0x00004000)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_front_mask                          (0x00003F00)
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_7_6_mask                                 (0x000000C0)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_back_mask                           (0x0000003F)
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_clamp_en(data)                      (0x00008000&((data)<<15))
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_14(data)                                 (0x00004000&((data)<<14))
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_front(data)                         (0x00003F00&((data)<<8))
#define  SYNC_DECMP_ST_SP_CLMPMSK_dummy_7_6(data)                                (0x000000C0&((data)<<6))
#define  SYNC_DECMP_ST_SP_CLMPMSK_st_sp_mask_back(data)                          (0x0000003F&(data))
#define  SYNC_DECMP_ST_SP_CLMPMSK_get_st_sp_mask_clamp_en(data)                  ((0x00008000&(data))>>15)
#define  SYNC_DECMP_ST_SP_CLMPMSK_get_dummy_14(data)                             ((0x00004000&(data))>>14)
#define  SYNC_DECMP_ST_SP_CLMPMSK_get_st_sp_mask_front(data)                     ((0x00003F00&(data))>>8)
#define  SYNC_DECMP_ST_SP_CLMPMSK_get_dummy_7_6(data)                            ((0x000000C0&(data))>>6)
#define  SYNC_DECMP_ST_SP_CLMPMSK_get_st_sp_mask_back(data)                      (0x0000003F&(data))

#define  SYNC_DECMP_ST_SP_CoastFtBk                                              0x18062020
#define  SYNC_DECMP_ST_SP_CoastFtBk_reg_addr                                     "0xB8062020"
#define  SYNC_DECMP_ST_SP_CoastFtBk_reg                                          0xB8062020
#define  SYNC_DECMP_ST_SP_CoastFtBk_inst_addr                                    "0x0008"
#define  set_SYNC_DECMP_ST_SP_CoastFtBk_reg(data)                                (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CoastFtBk_reg)=data)
#define  get_SYNC_DECMP_ST_SP_CoastFtBk_reg                                      (*((volatile unsigned int*)SYNC_DECMP_ST_SP_CoastFtBk_reg))
#define  SYNC_DECMP_ST_SP_CoastFtBk_dummy_9_8_shift                              (8)
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_front_shift                      (4)
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_back_shift                       (0)
#define  SYNC_DECMP_ST_SP_CoastFtBk_dummy_9_8_mask                               (0x00000300)
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_front_mask                       (0x000000F0)
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_back_mask                        (0x0000000F)
#define  SYNC_DECMP_ST_SP_CoastFtBk_dummy_9_8(data)                              (0x00000300&((data)<<8))
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_front(data)                      (0x000000F0&((data)<<4))
#define  SYNC_DECMP_ST_SP_CoastFtBk_st_sp_coast_back(data)                       (0x0000000F&(data))
#define  SYNC_DECMP_ST_SP_CoastFtBk_get_dummy_9_8(data)                          ((0x00000300&(data))>>8)
#define  SYNC_DECMP_ST_SP_CoastFtBk_get_st_sp_coast_front(data)                  ((0x000000F0&(data))>>4)
#define  SYNC_DECMP_ST_SP_CoastFtBk_get_st_sp_coast_back(data)                   (0x0000000F&(data))

#define  SYNC_DECMP_ST_Mv_CTRL                                                   0x18062024
#define  SYNC_DECMP_ST_Mv_CTRL_reg_addr                                          "0xB8062024"
#define  SYNC_DECMP_ST_Mv_CTRL_reg                                               0xB8062024
#define  SYNC_DECMP_ST_Mv_CTRL_inst_addr                                         "0x0009"
#define  set_SYNC_DECMP_ST_Mv_CTRL_reg(data)                                     (*((volatile unsigned int*)SYNC_DECMP_ST_Mv_CTRL_reg)=data)
#define  get_SYNC_DECMP_ST_Mv_CTRL_reg                                           (*((volatile unsigned int*)SYNC_DECMP_ST_Mv_CTRL_reg))
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_15_13_shift                                 (13)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_deb_num_mvhs_shift                          (8)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_skip_line_len_shift                         (4)
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_3_2_shift                                   (2)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_occur_shift                              (1)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_enable_shift                             (0)
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_15_13_mask                                  (0x0000E000)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_deb_num_mvhs_mask                           (0x00001F00)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_skip_line_len_mask                          (0x000000F0)
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_3_2_mask                                    (0x0000000C)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_occur_mask                               (0x00000002)
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_enable_mask                              (0x00000001)
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_15_13(data)                                 (0x0000E000&((data)<<13))
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_deb_num_mvhs(data)                          (0x00001F00&((data)<<8))
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_skip_line_len(data)                         (0x000000F0&((data)<<4))
#define  SYNC_DECMP_ST_Mv_CTRL_dummy_3_2(data)                                   (0x0000000C&((data)<<2))
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_occur(data)                              (0x00000002&((data)<<1))
#define  SYNC_DECMP_ST_Mv_CTRL_st_sp_mv_enable(data)                             (0x00000001&(data))
#define  SYNC_DECMP_ST_Mv_CTRL_get_dummy_15_13(data)                             ((0x0000E000&(data))>>13)
#define  SYNC_DECMP_ST_Mv_CTRL_get_st_sp_deb_num_mvhs(data)                      ((0x00001F00&(data))>>8)
#define  SYNC_DECMP_ST_Mv_CTRL_get_st_sp_skip_line_len(data)                     ((0x000000F0&(data))>>4)
#define  SYNC_DECMP_ST_Mv_CTRL_get_dummy_3_2(data)                               ((0x0000000C&(data))>>2)
#define  SYNC_DECMP_ST_Mv_CTRL_get_st_sp_mv_occur(data)                          ((0x00000002&(data))>>1)
#define  SYNC_DECMP_ST_Mv_CTRL_get_st_sp_mv_enable(data)                         (0x00000001&(data))

#define  SYNC_DECMP_ST_Mv_fld_Pos                                                0x18062028
#define  SYNC_DECMP_ST_Mv_fld_Pos_reg_addr                                       "0xB8062028"
#define  SYNC_DECMP_ST_Mv_fld_Pos_reg                                            0xB8062028
#define  SYNC_DECMP_ST_Mv_fld_Pos_inst_addr                                      "0x000A"
#define  set_SYNC_DECMP_ST_Mv_fld_Pos_reg(data)                                  (*((volatile unsigned int*)SYNC_DECMP_ST_Mv_fld_Pos_reg)=data)
#define  get_SYNC_DECMP_ST_Mv_fld_Pos_reg                                        (*((volatile unsigned int*)SYNC_DECMP_ST_Mv_fld_Pos_reg))
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_31_shift                                 (31)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_str_shift                           (24)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_rdy_shift                           (23)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_end_shift                           (16)
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_15_shift                                 (15)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_str_shift                           (8)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_rdy_shift                           (7)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_end_shift                           (0)
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_31_mask                                  (0x80000000)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_str_mask                            (0x7F000000)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_rdy_mask                            (0x00800000)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_end_mask                            (0x007F0000)
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_15_mask                                  (0x00008000)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_str_mask                            (0x00007F00)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_rdy_mask                            (0x00000080)
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_end_mask                            (0x0000007F)
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_31(data)                                 (0x80000000&((data)<<31))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_str(data)                           (0x7F000000&((data)<<24))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_rdy(data)                           (0x00800000&((data)<<23))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_o_mv_end(data)                           (0x007F0000&((data)<<16))
#define  SYNC_DECMP_ST_Mv_fld_Pos_dummy_15(data)                                 (0x00008000&((data)<<15))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_str(data)                           (0x00007F00&((data)<<8))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_rdy(data)                           (0x00000080&((data)<<7))
#define  SYNC_DECMP_ST_Mv_fld_Pos_st_sp_e_mv_end(data)                           (0x0000007F&(data))
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_dummy_31(data)                             ((0x80000000&(data))>>31)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_o_mv_str(data)                       ((0x7F000000&(data))>>24)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_o_mv_rdy(data)                       ((0x00800000&(data))>>23)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_o_mv_end(data)                       ((0x007F0000&(data))>>16)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_dummy_15(data)                             ((0x00008000&(data))>>15)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_e_mv_str(data)                       ((0x00007F00&(data))>>8)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_e_mv_rdy(data)                       ((0x00000080&(data))>>7)
#define  SYNC_DECMP_ST_Mv_fld_Pos_get_st_sp_e_mv_end(data)                       (0x0000007F&(data))

#define  SYNC_DECMP_ST_SP_TEST_Sel                                               0x1806202C
#define  SYNC_DECMP_ST_SP_TEST_Sel_reg_addr                                      "0xB806202C"
#define  SYNC_DECMP_ST_SP_TEST_Sel_reg                                           0xB806202C
#define  SYNC_DECMP_ST_SP_TEST_Sel_inst_addr                                     "0x000B"
#define  set_SYNC_DECMP_ST_SP_TEST_Sel_reg(data)                                 (*((volatile unsigned int*)SYNC_DECMP_ST_SP_TEST_Sel_reg)=data)
#define  get_SYNC_DECMP_ST_SP_TEST_Sel_reg                                       (*((volatile unsigned int*)SYNC_DECMP_ST_SP_TEST_Sel_reg))
#define  SYNC_DECMP_ST_SP_TEST_Sel_dummy_4_shift                                 (4)
#define  SYNC_DECMP_ST_SP_TEST_Sel_st_sp_sync_test_sel_shift                     (0)
#define  SYNC_DECMP_ST_SP_TEST_Sel_dummy_4_mask                                  (0x00000010)
#define  SYNC_DECMP_ST_SP_TEST_Sel_st_sp_sync_test_sel_mask                      (0x0000000F)
#define  SYNC_DECMP_ST_SP_TEST_Sel_dummy_4(data)                                 (0x00000010&((data)<<4))
#define  SYNC_DECMP_ST_SP_TEST_Sel_st_sp_sync_test_sel(data)                     (0x0000000F&(data))
#define  SYNC_DECMP_ST_SP_TEST_Sel_get_dummy_4(data)                             ((0x00000010&(data))>>4)
#define  SYNC_DECMP_ST_SP_TEST_Sel_get_st_sp_sync_test_sel(data)                 (0x0000000F&(data))

#define  SYNC_DECMP_ST_SP_PAD_STATUS                                             0x18062030
#define  SYNC_DECMP_ST_SP_PAD_STATUS_reg_addr                                    "0xB8062030"
#define  SYNC_DECMP_ST_SP_PAD_STATUS_reg                                         0xB8062030
#define  SYNC_DECMP_ST_SP_PAD_STATUS_inst_addr                                   "0x000C"
#define  set_SYNC_DECMP_ST_SP_PAD_STATUS_reg(data)                               (*((volatile unsigned int*)SYNC_DECMP_ST_SP_PAD_STATUS_reg)=data)
#define  get_SYNC_DECMP_ST_SP_PAD_STATUS_reg                                     (*((volatile unsigned int*)SYNC_DECMP_ST_SP_PAD_STATUS_reg))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1_ie_shift                 (10)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1_ie_shift                 (9)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1_ie_shift                 (8)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_dummy_7_5_shift                             (5)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1_shift                    (4)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1_shift                    (1)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1_shift                    (0)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1_ie_mask                  (0x00000400)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1_ie_mask                  (0x00000200)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1_ie_mask                  (0x00000100)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_dummy_7_5_mask                              (0x000000E0)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1_mask                     (0x00000010)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1_mask                     (0x00000002)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1_mask                     (0x00000001)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1_ie(data)                 (0x00000400&((data)<<10))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1_ie(data)                 (0x00000200&((data)<<9))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1_ie(data)                 (0x00000100&((data)<<8))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_dummy_7_5(data)                             (0x000000E0&((data)<<5))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_adc_sog1(data)                    (0x00000010&((data)<<4))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_avs1(data)                    (0x00000002&((data)<<1))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_st_sp_tog_pad_ahs1(data)                    (0x00000001&(data))
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_adc_sog1_ie(data)             ((0x00000400&(data))>>10)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_pad_avs1_ie(data)             ((0x00000200&(data))>>9)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_pad_ahs1_ie(data)             ((0x00000100&(data))>>8)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_dummy_7_5(data)                         ((0x000000E0&(data))>>5)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_adc_sog1(data)                ((0x00000010&(data))>>4)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_pad_avs1(data)                ((0x00000002&(data))>>1)
#define  SYNC_DECMP_ST_SP_PAD_STATUS_get_st_sp_tog_pad_ahs1(data)                (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SYNC_DECMP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_dehs_out_en:1;
        RBus_UInt32  dummy18062000_30:1;
        RBus_UInt32  dummy18062000_29:1;
        RBus_UInt32  st_sp_hsraw_inv:1;
        RBus_UInt32  dummy18062000_27:1;
        RBus_UInt32  dummy18062000_26_24:3;
        RBus_UInt32  st_sp_hrecovery_en:1;
        RBus_UInt32  st_sp_adc_vsout_testmd:1;
        RBus_UInt32  st_sp_devs_out_en:1;
        RBus_UInt32  st_sp_sel_clpmsk_as_devs:1;
        RBus_UInt32  st_sp_hsout_inv:1;
        RBus_UInt32  dummy18062000_18:1;
        RBus_UInt32  st_sp_hs_sync_source:1;
        RBus_UInt32  st_sp_hsout_en:1;
        RBus_UInt32  dummy18062000_15_13:3;
        RBus_UInt32  st_sp_seperate_testmode:1;
        RBus_UInt32  st_sp_auto_run_done_ie:1;
        RBus_UInt32  st_sp_auto_run:1;
        RBus_UInt32  st_sp_coast_en:1;
        RBus_UInt32  st_sp_decmp_en:1;
        RBus_UInt32  dummy18062000_7:1;
        RBus_UInt32  st_sp_hs_fb_plswid_md:2;
        RBus_UInt32  st_sp_coast_inv:1;
        RBus_UInt32  reg_ddc_vsync_inv:1;
        RBus_UInt32  reg_ddc_src_sel:1;
        RBus_UInt32  st_sp_polling_en:1;
        RBus_UInt32  st_sp_vhs_source_sel:1;
    };
}sync_decmp_st_sp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_auto_result_rdy:1;
        RBus_UInt32  dummy18062004_30:1;
        RBus_UInt32  st_sp_unlock_no_vs_str:6;
        RBus_UInt32  st_sp_unlock_no_vs_end:12;
        RBus_UInt32  res1:5;
        RBus_UInt32  st_sp_auto_result:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  st_sp_input_signal_be_inverted:1;
    };
}sync_decmp_st_sp_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  st_sp_cap_win_range_lsb:2;
        RBus_UInt32  st_sp_hsper_realtime_stbline:2;
        RBus_UInt32  st_sp_hsper_realtime_en:1;
        RBus_UInt32  st_sp_cap_win_clo:1;
        RBus_UInt32  st_sp_cap_win_range:5;
        RBus_UInt32  st_sp_per_range:3;
        RBus_UInt32  st_sp_popup_stable_per:1;
        RBus_UInt32  dummy18062008_6_4:3;
        RBus_UInt32  st_sp_cap_win_step:1;
        RBus_UInt32  st_sp_miss_lock_limit:1;
        RBus_UInt32  dummy18062008_1:1;
        RBus_UInt32  st_sp_stable_en:1;
    };
}sync_decmp_st_sp_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_mode_det_of:1;
        RBus_UInt32  st_sp_stb_per_chg:1;
        RBus_UInt32  st_sp_stb_pol_chg:1;
        RBus_UInt32  st_sp_vs_raw_vld:1;
        RBus_UInt32  st_sp_cap_32unlock:1;
        RBus_UInt32  st_sp_eq_occur:1;
        RBus_UInt32  st_sp_hs_pol_chg:1;
        RBus_UInt32  st_sp_cap_unlock:1;
        RBus_UInt32  st_sp_mode_det_stable:1;
        RBus_UInt32  st_sp_stable_pol_out:1;
        RBus_UInt32  st_sp_cap_unlock_no_vs:1;
        RBus_UInt32  st_sp_giltch_in_win:1;
        RBus_UInt32  st_sp_type_det:1;
        RBus_UInt32  st_sp_type_det_ie:1;
        RBus_UInt32  st_sp_mode_det_stable_ie:1;
        RBus_UInt32  res1:17;
    };
}sync_decmp_st_sp_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  st_sp_stable_period_out:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  st_sp_stable_plswid_out:11;
    };
}sync_decmp_st_sp_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_sp_deb_num:5;
        RBus_UInt32  st_sp_dcnt_level:11;
    };
}sync_decmp_st_sp_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  st_sp_field_det_vs_sel:1;
        RBus_UInt32  st_sp_field_det_mode:1;
        RBus_UInt32  st_sp_f_pos_field:1;
        RBus_UInt32  st_sp_f_pos_field_tgle:1;
        RBus_UInt32  st_sp_f_count_field:1;
        RBus_UInt32  st_sp_f_count_field_tgle:1;
        RBus_UInt32  st_sp_l_cnt_lsb1:3;
    };
}sync_decmp_st_sp_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_sp_mask_clamp_en:1;
        RBus_UInt32  dummy1806201c_14:1;
        RBus_UInt32  st_sp_mask_front:6;
        RBus_UInt32  dummy1806201c_7_6:2;
        RBus_UInt32  st_sp_mask_back:6;
    };
}sync_decmp_st_sp_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dummy18062020_9_8:2;
        RBus_UInt32  st_sp_coast_front:4;
        RBus_UInt32  st_sp_coast_back:4;
    };
}sync_decmp_st_sp_coastftbk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy18062024_15_13:3;
        RBus_UInt32  st_sp_deb_num_mvhs:5;
        RBus_UInt32  st_sp_skip_line_len:4;
        RBus_UInt32  dummy18062024_3_2:2;
        RBus_UInt32  st_sp_mv_occur:1;
        RBus_UInt32  st_sp_mv_enable:1;
    };
}sync_decmp_st_mv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18062028_31:1;
        RBus_UInt32  st_sp_o_mv_str:7;
        RBus_UInt32  st_sp_o_mv_rdy:1;
        RBus_UInt32  st_sp_o_mv_end:7;
        RBus_UInt32  dummy18062028_15:1;
        RBus_UInt32  st_sp_e_mv_str:7;
        RBus_UInt32  st_sp_e_mv_rdy:1;
        RBus_UInt32  st_sp_e_mv_end:7;
    };
}sync_decmp_st_mv_fld_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dummy1806202c_4:1;
        RBus_UInt32  st_sp_sync_test_sel:4;
    };
}sync_decmp_st_sp_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  st_sp_tog_adc_sog1_ie:1;
        RBus_UInt32  st_sp_tog_pad_avs1_ie:1;
        RBus_UInt32  st_sp_tog_pad_ahs1_ie:1;
        RBus_UInt32  dummy18062030_7_5:3;
        RBus_UInt32  st_sp_tog_adc_sog1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  st_sp_tog_pad_avs1:1;
        RBus_UInt32  st_sp_tog_pad_ahs1:1;
    };
}sync_decmp_st_sp_pad_status_RBUS;

#else //apply LITTLE_ENDIAN

//======SYNC_DECMP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_vhs_source_sel:1;
        RBus_UInt32  st_sp_polling_en:1;
        RBus_UInt32  reg_ddc_src_sel:1;
        RBus_UInt32  reg_ddc_vsync_inv:1;
        RBus_UInt32  st_sp_coast_inv:1;
        RBus_UInt32  st_sp_hs_fb_plswid_md:2;
        RBus_UInt32  dummy18062000_7:1;
        RBus_UInt32  st_sp_decmp_en:1;
        RBus_UInt32  st_sp_coast_en:1;
        RBus_UInt32  st_sp_auto_run:1;
        RBus_UInt32  st_sp_auto_run_done_ie:1;
        RBus_UInt32  st_sp_seperate_testmode:1;
        RBus_UInt32  dummy18062000_15_13:3;
        RBus_UInt32  st_sp_hsout_en:1;
        RBus_UInt32  st_sp_hs_sync_source:1;
        RBus_UInt32  dummy18062000_18:1;
        RBus_UInt32  st_sp_hsout_inv:1;
        RBus_UInt32  st_sp_sel_clpmsk_as_devs:1;
        RBus_UInt32  st_sp_devs_out_en:1;
        RBus_UInt32  st_sp_adc_vsout_testmd:1;
        RBus_UInt32  st_sp_hrecovery_en:1;
        RBus_UInt32  dummy18062000_26_24:3;
        RBus_UInt32  dummy18062000_27:1;
        RBus_UInt32  st_sp_hsraw_inv:1;
        RBus_UInt32  dummy18062000_29:1;
        RBus_UInt32  dummy18062000_30:1;
        RBus_UInt32  st_sp_dehs_out_en:1;
    };
}sync_decmp_st_sp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_input_signal_be_inverted:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  st_sp_auto_result:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  st_sp_unlock_no_vs_end:12;
        RBus_UInt32  st_sp_unlock_no_vs_str:6;
        RBus_UInt32  dummy18062004_30:1;
        RBus_UInt32  st_sp_auto_result_rdy:1;
    };
}sync_decmp_st_sp_autorst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_stable_en:1;
        RBus_UInt32  dummy18062008_1:1;
        RBus_UInt32  st_sp_miss_lock_limit:1;
        RBus_UInt32  st_sp_cap_win_step:1;
        RBus_UInt32  dummy18062008_6_4:3;
        RBus_UInt32  st_sp_popup_stable_per:1;
        RBus_UInt32  st_sp_per_range:3;
        RBus_UInt32  st_sp_cap_win_range:5;
        RBus_UInt32  st_sp_cap_win_clo:1;
        RBus_UInt32  st_sp_hsper_realtime_en:1;
        RBus_UInt32  st_sp_hsper_realtime_stbline:2;
        RBus_UInt32  st_sp_cap_win_range_lsb:2;
        RBus_UInt32  res1:10;
    };
}sync_decmp_st_sp_stbctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  st_sp_mode_det_stable_ie:1;
        RBus_UInt32  st_sp_type_det_ie:1;
        RBus_UInt32  st_sp_type_det:1;
        RBus_UInt32  st_sp_giltch_in_win:1;
        RBus_UInt32  st_sp_cap_unlock_no_vs:1;
        RBus_UInt32  st_sp_stable_pol_out:1;
        RBus_UInt32  st_sp_mode_det_stable:1;
        RBus_UInt32  st_sp_cap_unlock:1;
        RBus_UInt32  st_sp_hs_pol_chg:1;
        RBus_UInt32  st_sp_eq_occur:1;
        RBus_UInt32  st_sp_cap_32unlock:1;
        RBus_UInt32  st_sp_vs_raw_vld:1;
        RBus_UInt32  st_sp_stb_pol_chg:1;
        RBus_UInt32  st_sp_stb_per_chg:1;
        RBus_UInt32  st_sp_mode_det_of:1;
    };
}sync_decmp_st_sp_stbrst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_stable_plswid_out:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  st_sp_stable_period_out:11;
        RBus_UInt32  res2:5;
    };
}sync_decmp_st_sp_stbrst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_dcnt_level:11;
        RBus_UInt32  st_sp_deb_num:5;
        RBus_UInt32  res1:16;
    };
}sync_decmp_st_sp_dcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_l_cnt_lsb1:3;
        RBus_UInt32  st_sp_f_count_field_tgle:1;
        RBus_UInt32  st_sp_f_count_field:1;
        RBus_UInt32  st_sp_f_pos_field_tgle:1;
        RBus_UInt32  st_sp_f_pos_field:1;
        RBus_UInt32  st_sp_field_det_mode:1;
        RBus_UInt32  st_sp_field_det_vs_sel:1;
        RBus_UInt32  res1:23;
    };
}sync_decmp_st_sp_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_mask_back:6;
        RBus_UInt32  dummy1806201c_7_6:2;
        RBus_UInt32  st_sp_mask_front:6;
        RBus_UInt32  dummy1806201c_14:1;
        RBus_UInt32  st_sp_mask_clamp_en:1;
        RBus_UInt32  res1:16;
    };
}sync_decmp_st_sp_clmpmsk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_coast_back:4;
        RBus_UInt32  st_sp_coast_front:4;
        RBus_UInt32  dummy18062020_9_8:2;
        RBus_UInt32  res1:22;
    };
}sync_decmp_st_sp_coastftbk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_mv_enable:1;
        RBus_UInt32  st_sp_mv_occur:1;
        RBus_UInt32  dummy18062024_3_2:2;
        RBus_UInt32  st_sp_skip_line_len:4;
        RBus_UInt32  st_sp_deb_num_mvhs:5;
        RBus_UInt32  dummy18062024_15_13:3;
        RBus_UInt32  res1:16;
    };
}sync_decmp_st_mv_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_e_mv_end:7;
        RBus_UInt32  st_sp_e_mv_rdy:1;
        RBus_UInt32  st_sp_e_mv_str:7;
        RBus_UInt32  dummy18062028_15:1;
        RBus_UInt32  st_sp_o_mv_end:7;
        RBus_UInt32  st_sp_o_mv_rdy:1;
        RBus_UInt32  st_sp_o_mv_str:7;
        RBus_UInt32  dummy18062028_31:1;
    };
}sync_decmp_st_mv_fld_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_sync_test_sel:4;
        RBus_UInt32  dummy1806202c_4:1;
        RBus_UInt32  res1:27;
    };
}sync_decmp_st_sp_test_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_sp_tog_pad_ahs1:1;
        RBus_UInt32  st_sp_tog_pad_avs1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  st_sp_tog_adc_sog1:1;
        RBus_UInt32  dummy18062030_7_5:3;
        RBus_UInt32  st_sp_tog_pad_ahs1_ie:1;
        RBus_UInt32  st_sp_tog_pad_avs1_ie:1;
        RBus_UInt32  st_sp_tog_adc_sog1_ie:1;
        RBus_UInt32  res2:21;
    };
}sync_decmp_st_sp_pad_status_RBUS;




#endif 


#endif 
