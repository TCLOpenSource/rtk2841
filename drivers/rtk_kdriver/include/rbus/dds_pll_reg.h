/**
* @file MacArthur5-DesignSpec-I-Domain_DDS_PLL
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DDS_PLL_REG_H_
#define _RBUS_DDS_PLL_REG_H_

#include "rbus_types.h"



//  DDS_PLL Register Address
#define  DDS_PLL_PLL_SET                                                         0x18020100
#define  DDS_PLL_PLL_SET_reg_addr                                                "0xB8020100"
#define  DDS_PLL_PLL_SET_reg                                                     0xB8020100
#define  DDS_PLL_PLL_SET_inst_addr                                               "0x0000"
#define  set_DDS_PLL_PLL_SET_reg(data)                                           (*((volatile unsigned int*)DDS_PLL_PLL_SET_reg)=data)
#define  get_DDS_PLL_PLL_SET_reg                                                 (*((volatile unsigned int*)DDS_PLL_PLL_SET_reg))
#define  DDS_PLL_PLL_SET_pllscp_shift                                            (29)
#define  DDS_PLL_PLL_SET_pllscs_shift                                            (27)
#define  DDS_PLL_PLL_SET_pllsrs_shift                                            (24)
#define  DDS_PLL_PLL_SET_pllssi_shift                                            (16)
#define  DDS_PLL_PLL_SET_pllsphnext_shift                                        (12)
#define  DDS_PLL_PLL_SET_pllsnbp_shift                                           (11)
#define  DDS_PLL_PLL_SET_pll_n_shift                                             (8)
#define  DDS_PLL_PLL_SET_pll_m_shift                                             (0)
#define  DDS_PLL_PLL_SET_pllscp_mask                                             (0x20000000)
#define  DDS_PLL_PLL_SET_pllscs_mask                                             (0x18000000)
#define  DDS_PLL_PLL_SET_pllsrs_mask                                             (0x07000000)
#define  DDS_PLL_PLL_SET_pllssi_mask                                             (0x001F0000)
#define  DDS_PLL_PLL_SET_pllsphnext_mask                                         (0x0000F000)
#define  DDS_PLL_PLL_SET_pllsnbp_mask                                            (0x00000800)
#define  DDS_PLL_PLL_SET_pll_n_mask                                              (0x00000700)
#define  DDS_PLL_PLL_SET_pll_m_mask                                              (0x000000FF)
#define  DDS_PLL_PLL_SET_pllscp(data)                                            (0x20000000&((data)<<29))
#define  DDS_PLL_PLL_SET_pllscs(data)                                            (0x18000000&((data)<<27))
#define  DDS_PLL_PLL_SET_pllsrs(data)                                            (0x07000000&((data)<<24))
#define  DDS_PLL_PLL_SET_pllssi(data)                                            (0x001F0000&((data)<<16))
#define  DDS_PLL_PLL_SET_pllsphnext(data)                                        (0x0000F000&((data)<<12))
#define  DDS_PLL_PLL_SET_pllsnbp(data)                                           (0x00000800&((data)<<11))
#define  DDS_PLL_PLL_SET_pll_n(data)                                             (0x00000700&((data)<<8))
#define  DDS_PLL_PLL_SET_pll_m(data)                                             (0x000000FF&(data))
#define  DDS_PLL_PLL_SET_get_pllscp(data)                                        ((0x20000000&(data))>>29)
#define  DDS_PLL_PLL_SET_get_pllscs(data)                                        ((0x18000000&(data))>>27)
#define  DDS_PLL_PLL_SET_get_pllsrs(data)                                        ((0x07000000&(data))>>24)
#define  DDS_PLL_PLL_SET_get_pllssi(data)                                        ((0x001F0000&(data))>>16)
#define  DDS_PLL_PLL_SET_get_pllsphnext(data)                                    ((0x0000F000&(data))>>12)
#define  DDS_PLL_PLL_SET_get_pllsnbp(data)                                       ((0x00000800&(data))>>11)
#define  DDS_PLL_PLL_SET_get_pll_n(data)                                         ((0x00000700&(data))>>8)
#define  DDS_PLL_PLL_SET_get_pll_m(data)                                         (0x000000FF&(data))

#define  DDS_PLL_PLL_CTRL                                                        0x18020104
#define  DDS_PLL_PLL_CTRL_reg_addr                                               "0xB8020104"
#define  DDS_PLL_PLL_CTRL_reg                                                    0xB8020104
#define  DDS_PLL_PLL_CTRL_inst_addr                                              "0x0001"
#define  set_DDS_PLL_PLL_CTRL_reg(data)                                          (*((volatile unsigned int*)DDS_PLL_PLL_CTRL_reg)=data)
#define  get_DDS_PLL_PLL_CTRL_reg                                                (*((volatile unsigned int*)DDS_PLL_PLL_CTRL_reg))
#define  DDS_PLL_PLL_CTRL_apllldopow_shift                                       (18)
#define  DDS_PLL_PLL_CTRL_apllldosel_shift                                       (16)
#define  DDS_PLL_PLL_CTRL_dummy_15_shift                                         (15)
#define  DDS_PLL_PLL_CTRL_dummy_14_shift                                         (14)
#define  DDS_PLL_PLL_CTRL_dummy_13_shift                                         (13)
#define  DDS_PLL_PLL_CTRL_dummy_12_shift                                         (12)
#define  DDS_PLL_PLL_CTRL_dummy_11_shift                                         (11)
#define  DDS_PLL_PLL_CTRL_adckmode_shift                                         (9)
#define  DDS_PLL_PLL_CTRL_ps_en_already_shift                                    (8)
#define  DDS_PLL_PLL_CTRL_pllstatus_shift                                        (7)
#define  DDS_PLL_PLL_CTRL_pllswdrst_shift                                        (6)
#define  DDS_PLL_PLL_CTRL_pllswdset_shift                                        (5)
#define  DDS_PLL_PLL_CTRL_apll_reg_shift                                         (3)
#define  DDS_PLL_PLL_CTRL_hs_dds2synp_sel_shift                                  (2)
#define  DDS_PLL_PLL_CTRL_dds_rst_shift                                          (1)
#define  DDS_PLL_PLL_CTRL_pllpwdn_shift                                          (0)
#define  DDS_PLL_PLL_CTRL_apllldopow_mask                                        (0x00040000)
#define  DDS_PLL_PLL_CTRL_apllldosel_mask                                        (0x00030000)
#define  DDS_PLL_PLL_CTRL_dummy_15_mask                                          (0x00008000)
#define  DDS_PLL_PLL_CTRL_dummy_14_mask                                          (0x00004000)
#define  DDS_PLL_PLL_CTRL_dummy_13_mask                                          (0x00002000)
#define  DDS_PLL_PLL_CTRL_dummy_12_mask                                          (0x00001000)
#define  DDS_PLL_PLL_CTRL_dummy_11_mask                                          (0x00000800)
#define  DDS_PLL_PLL_CTRL_adckmode_mask                                          (0x00000600)
#define  DDS_PLL_PLL_CTRL_ps_en_already_mask                                     (0x00000100)
#define  DDS_PLL_PLL_CTRL_pllstatus_mask                                         (0x00000080)
#define  DDS_PLL_PLL_CTRL_pllswdrst_mask                                         (0x00000040)
#define  DDS_PLL_PLL_CTRL_pllswdset_mask                                         (0x00000020)
#define  DDS_PLL_PLL_CTRL_apll_reg_mask                                          (0x00000018)
#define  DDS_PLL_PLL_CTRL_hs_dds2synp_sel_mask                                   (0x00000004)
#define  DDS_PLL_PLL_CTRL_dds_rst_mask                                           (0x00000002)
#define  DDS_PLL_PLL_CTRL_pllpwdn_mask                                           (0x00000001)
#define  DDS_PLL_PLL_CTRL_apllldopow(data)                                       (0x00040000&((data)<<18))
#define  DDS_PLL_PLL_CTRL_apllldosel(data)                                       (0x00030000&((data)<<16))
#define  DDS_PLL_PLL_CTRL_dummy_15(data)                                         (0x00008000&((data)<<15))
#define  DDS_PLL_PLL_CTRL_dummy_14(data)                                         (0x00004000&((data)<<14))
#define  DDS_PLL_PLL_CTRL_dummy_13(data)                                         (0x00002000&((data)<<13))
#define  DDS_PLL_PLL_CTRL_dummy_12(data)                                         (0x00001000&((data)<<12))
#define  DDS_PLL_PLL_CTRL_dummy_11(data)                                         (0x00000800&((data)<<11))
#define  DDS_PLL_PLL_CTRL_adckmode(data)                                         (0x00000600&((data)<<9))
#define  DDS_PLL_PLL_CTRL_ps_en_already(data)                                    (0x00000100&((data)<<8))
#define  DDS_PLL_PLL_CTRL_pllstatus(data)                                        (0x00000080&((data)<<7))
#define  DDS_PLL_PLL_CTRL_pllswdrst(data)                                        (0x00000040&((data)<<6))
#define  DDS_PLL_PLL_CTRL_pllswdset(data)                                        (0x00000020&((data)<<5))
#define  DDS_PLL_PLL_CTRL_apll_reg(data)                                         (0x00000018&((data)<<3))
#define  DDS_PLL_PLL_CTRL_hs_dds2synp_sel(data)                                  (0x00000004&((data)<<2))
#define  DDS_PLL_PLL_CTRL_dds_rst(data)                                          (0x00000002&((data)<<1))
#define  DDS_PLL_PLL_CTRL_pllpwdn(data)                                          (0x00000001&(data))
#define  DDS_PLL_PLL_CTRL_get_apllldopow(data)                                   ((0x00040000&(data))>>18)
#define  DDS_PLL_PLL_CTRL_get_apllldosel(data)                                   ((0x00030000&(data))>>16)
#define  DDS_PLL_PLL_CTRL_get_dummy_15(data)                                     ((0x00008000&(data))>>15)
#define  DDS_PLL_PLL_CTRL_get_dummy_14(data)                                     ((0x00004000&(data))>>14)
#define  DDS_PLL_PLL_CTRL_get_dummy_13(data)                                     ((0x00002000&(data))>>13)
#define  DDS_PLL_PLL_CTRL_get_dummy_12(data)                                     ((0x00001000&(data))>>12)
#define  DDS_PLL_PLL_CTRL_get_dummy_11(data)                                     ((0x00000800&(data))>>11)
#define  DDS_PLL_PLL_CTRL_get_adckmode(data)                                     ((0x00000600&(data))>>9)
#define  DDS_PLL_PLL_CTRL_get_ps_en_already(data)                                ((0x00000100&(data))>>8)
#define  DDS_PLL_PLL_CTRL_get_pllstatus(data)                                    ((0x00000080&(data))>>7)
#define  DDS_PLL_PLL_CTRL_get_pllswdrst(data)                                    ((0x00000040&(data))>>6)
#define  DDS_PLL_PLL_CTRL_get_pllswdset(data)                                    ((0x00000020&(data))>>5)
#define  DDS_PLL_PLL_CTRL_get_apll_reg(data)                                     ((0x00000018&(data))>>3)
#define  DDS_PLL_PLL_CTRL_get_hs_dds2synp_sel(data)                              ((0x00000004&(data))>>2)
#define  DDS_PLL_PLL_CTRL_get_dds_rst(data)                                      ((0x00000002&(data))>>1)
#define  DDS_PLL_PLL_CTRL_get_pllpwdn(data)                                      (0x00000001&(data))

#define  DDS_PLL_PLLDIV                                                          0x18020108
#define  DDS_PLL_PLLDIV_reg_addr                                                 "0xB8020108"
#define  DDS_PLL_PLLDIV_reg                                                      0xB8020108
#define  DDS_PLL_PLLDIV_inst_addr                                                "0x0002"
#define  set_DDS_PLL_PLLDIV_reg(data)                                            (*((volatile unsigned int*)DDS_PLL_PLLDIV_reg)=data)
#define  get_DDS_PLL_PLLDIV_reg                                                  (*((volatile unsigned int*)DDS_PLL_PLLDIV_reg))
#define  DDS_PLL_PLLDIV_dummy_31_24_shift                                        (24)
#define  DDS_PLL_PLLDIV_apll_reserve_shift                                       (16)
#define  DDS_PLL_PLLDIV_dummy_15_shift                                           (15)
#define  DDS_PLL_PLLDIV_pll_divider_shift                                        (0)
#define  DDS_PLL_PLLDIV_dummy_31_24_mask                                         (0xFF000000)
#define  DDS_PLL_PLLDIV_apll_reserve_mask                                        (0x00FF0000)
#define  DDS_PLL_PLLDIV_dummy_15_mask                                            (0x00008000)
#define  DDS_PLL_PLLDIV_pll_divider_mask                                         (0x00000FFF)
#define  DDS_PLL_PLLDIV_dummy_31_24(data)                                        (0xFF000000&((data)<<24))
#define  DDS_PLL_PLLDIV_apll_reserve(data)                                       (0x00FF0000&((data)<<16))
#define  DDS_PLL_PLLDIV_dummy_15(data)                                           (0x00008000&((data)<<15))
#define  DDS_PLL_PLLDIV_pll_divider(data)                                        (0x00000FFF&(data))
#define  DDS_PLL_PLLDIV_get_dummy_31_24(data)                                    ((0xFF000000&(data))>>24)
#define  DDS_PLL_PLLDIV_get_apll_reserve(data)                                   ((0x00FF0000&(data))>>16)
#define  DDS_PLL_PLLDIV_get_dummy_15(data)                                       ((0x00008000&(data))>>15)
#define  DDS_PLL_PLLDIV_get_pll_divider(data)                                    (0x00000FFF&(data))

#define  DDS_PLL_PLLPHASE_CTRL                                                   0x1802010C
#define  DDS_PLL_PLLPHASE_CTRL_reg_addr                                          "0xB802010C"
#define  DDS_PLL_PLLPHASE_CTRL_reg                                               0xB802010C
#define  DDS_PLL_PLLPHASE_CTRL_inst_addr                                         "0x0003"
#define  set_DDS_PLL_PLLPHASE_CTRL_reg(data)                                     (*((volatile unsigned int*)DDS_PLL_PLLPHASE_CTRL_reg)=data)
#define  get_DDS_PLL_PLLPHASE_CTRL_reg                                           (*((volatile unsigned int*)DDS_PLL_PLLPHASE_CTRL_reg))
#define  DDS_PLL_PLLPHASE_CTRL_pllsph0path_shift                                 (21)
#define  DDS_PLL_PLLPHASE_CTRL_pllsph0path_mask                                  (0x00200000)
#define  DDS_PLL_PLLPHASE_CTRL_pllsph0path(data)                                 (0x00200000&((data)<<21))
#define  DDS_PLL_PLLPHASE_CTRL_get_pllsph0path(data)                             ((0x00200000&(data))>>21)

#define  DDS_PLL_PLL_PHASE_INTERPOLATION                                         0x18020110
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_reg_addr                                "0xB8020110"
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_reg                                     0xB8020110
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_inst_addr                               "0x0004"
#define  set_DDS_PLL_PLL_PHASE_INTERPOLATION_reg(data)                           (*((volatile unsigned int*)DDS_PLL_PLL_PHASE_INTERPOLATION_reg)=data)
#define  get_DDS_PLL_PLL_PHASE_INTERPOLATION_reg                                 (*((volatile unsigned int*)DDS_PLL_PLL_PHASE_INTERPOLATION_reg))
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrl_shift                          (8)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrs_shift                          (4)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsadelay_shift                        (1)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_dummy_0_shift                           (0)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrl_mask                           (0x00000300)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrs_mask                           (0x00000070)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsadelay_mask                         (0x00000006)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_dummy_0_mask                            (0x00000001)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrl(data)                          (0x00000300&((data)<<8))
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsphrs(data)                          (0x00000070&((data)<<4))
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_pllsadelay(data)                        (0x00000006&((data)<<1))
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_dummy_0(data)                           (0x00000001&(data))
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_get_pllsphrl(data)                      ((0x00000300&(data))>>8)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_get_pllsphrs(data)                      ((0x00000070&(data))>>4)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_get_pllsadelay(data)                    ((0x00000006&(data))>>1)
#define  DDS_PLL_PLL_PHASE_INTERPOLATION_get_dummy_0(data)                       (0x00000001&(data))

#define  DDS_PLL_P_CODE_mapping_methods                                          0x18020114
#define  DDS_PLL_P_CODE_mapping_methods_reg_addr                                 "0xB8020114"
#define  DDS_PLL_P_CODE_mapping_methods_reg                                      0xB8020114
#define  DDS_PLL_P_CODE_mapping_methods_inst_addr                                "0x0005"
#define  set_DDS_PLL_P_CODE_mapping_methods_reg(data)                            (*((volatile unsigned int*)DDS_PLL_P_CODE_mapping_methods_reg)=data)
#define  get_DDS_PLL_P_CODE_mapping_methods_reg                                  (*((volatile unsigned int*)DDS_PLL_P_CODE_mapping_methods_reg))
#define  DDS_PLL_P_CODE_mapping_methods_mapping_sel_shift                        (8)
#define  DDS_PLL_P_CODE_mapping_methods_g_value_shift                            (4)
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_i_en_shift                    (1)
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_p_en_shift                    (0)
#define  DDS_PLL_P_CODE_mapping_methods_mapping_sel_mask                         (0x00000300)
#define  DDS_PLL_P_CODE_mapping_methods_g_value_mask                             (0x000000F0)
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_i_en_mask                     (0x00000002)
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_p_en_mask                     (0x00000001)
#define  DDS_PLL_P_CODE_mapping_methods_mapping_sel(data)                        (0x00000300&((data)<<8))
#define  DDS_PLL_P_CODE_mapping_methods_g_value(data)                            (0x000000F0&((data)<<4))
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_i_en(data)                    (0x00000002&((data)<<1))
#define  DDS_PLL_P_CODE_mapping_methods_adap_track_p_en(data)                    (0x00000001&(data))
#define  DDS_PLL_P_CODE_mapping_methods_get_mapping_sel(data)                    ((0x00000300&(data))>>8)
#define  DDS_PLL_P_CODE_mapping_methods_get_g_value(data)                        ((0x000000F0&(data))>>4)
#define  DDS_PLL_P_CODE_mapping_methods_get_adap_track_i_en(data)                ((0x00000002&(data))>>1)
#define  DDS_PLL_P_CODE_mapping_methods_get_adap_track_p_en(data)                (0x00000001&(data))

#define  DDS_PLL_PE_tracking_method                                              0x18020118
#define  DDS_PLL_PE_tracking_method_reg_addr                                     "0xB8020118"
#define  DDS_PLL_PE_tracking_method_reg                                          0xB8020118
#define  DDS_PLL_PE_tracking_method_inst_addr                                    "0x0006"
#define  set_DDS_PLL_PE_tracking_method_reg(data)                                (*((volatile unsigned int*)DDS_PLL_PE_tracking_method_reg)=data)
#define  get_DDS_PLL_PE_tracking_method_reg                                      (*((volatile unsigned int*)DDS_PLL_PE_tracking_method_reg))
#define  DDS_PLL_PE_tracking_method_adap_track_pe_th_shift                       (6)
#define  DDS_PLL_PE_tracking_method_adap_track_time_th_shift                     (4)
#define  DDS_PLL_PE_tracking_method_high_speed_mask_shift                        (3)
#define  DDS_PLL_PE_tracking_method_adap_track_en_shift                          (2)
#define  DDS_PLL_PE_tracking_method_zoom_out_ratio_shift                         (0)
#define  DDS_PLL_PE_tracking_method_adap_track_pe_th_mask                        (0x000000C0)
#define  DDS_PLL_PE_tracking_method_adap_track_time_th_mask                      (0x00000030)
#define  DDS_PLL_PE_tracking_method_high_speed_mask_mask                         (0x00000008)
#define  DDS_PLL_PE_tracking_method_adap_track_en_mask                           (0x00000004)
#define  DDS_PLL_PE_tracking_method_zoom_out_ratio_mask                          (0x00000003)
#define  DDS_PLL_PE_tracking_method_adap_track_pe_th(data)                       (0x000000C0&((data)<<6))
#define  DDS_PLL_PE_tracking_method_adap_track_time_th(data)                     (0x00000030&((data)<<4))
#define  DDS_PLL_PE_tracking_method_high_speed_mask(data)                        (0x00000008&((data)<<3))
#define  DDS_PLL_PE_tracking_method_adap_track_en(data)                          (0x00000004&((data)<<2))
#define  DDS_PLL_PE_tracking_method_zoom_out_ratio(data)                         (0x00000003&(data))
#define  DDS_PLL_PE_tracking_method_get_adap_track_pe_th(data)                   ((0x000000C0&(data))>>6)
#define  DDS_PLL_PE_tracking_method_get_adap_track_time_th(data)                 ((0x00000030&(data))>>4)
#define  DDS_PLL_PE_tracking_method_get_high_speed_mask(data)                    ((0x00000008&(data))>>3)
#define  DDS_PLL_PE_tracking_method_get_adap_track_en(data)                      ((0x00000004&(data))>>2)
#define  DDS_PLL_PE_tracking_method_get_zoom_out_ratio(data)                     (0x00000003&(data))

#define  DDS_PLL_DDS_MIX_W1                                                      0x1802011C
#define  DDS_PLL_DDS_MIX_W1_reg_addr                                             "0xB802011C"
#define  DDS_PLL_DDS_MIX_W1_reg                                                  0xB802011C
#define  DDS_PLL_DDS_MIX_W1_inst_addr                                            "0x0007"
#define  set_DDS_PLL_DDS_MIX_W1_reg(data)                                        (*((volatile unsigned int*)DDS_PLL_DDS_MIX_W1_reg)=data)
#define  get_DDS_PLL_DDS_MIX_W1_reg                                              (*((volatile unsigned int*)DDS_PLL_DDS_MIX_W1_reg))
#define  DDS_PLL_DDS_MIX_W1_dummy_31_shift                                       (31)
#define  DDS_PLL_DDS_MIX_W1_lock_th_shift                                        (28)
#define  DDS_PLL_DDS_MIX_W1_t_s_shift                                            (26)
#define  DDS_PLL_DDS_MIX_W1_pll_lock_shift                                       (25)
#define  DDS_PLL_DDS_MIX_W1_p_code_max_shift                                     (8)
#define  DDS_PLL_DDS_MIX_W1_dummy_7_shift                                        (7)
#define  DDS_PLL_DDS_MIX_W1_new_mode_lock_th_shift                               (4)
#define  DDS_PLL_DDS_MIX_W1_new_mode_en_shift                                    (3)
#define  DDS_PLL_DDS_MIX_W1_new_mode_en_th_shift                                 (0)
#define  DDS_PLL_DDS_MIX_W1_dummy_31_mask                                        (0x80000000)
#define  DDS_PLL_DDS_MIX_W1_lock_th_mask                                         (0x70000000)
#define  DDS_PLL_DDS_MIX_W1_t_s_mask                                             (0x0C000000)
#define  DDS_PLL_DDS_MIX_W1_pll_lock_mask                                        (0x02000000)
#define  DDS_PLL_DDS_MIX_W1_p_code_max_mask                                      (0x01FFFF00)
#define  DDS_PLL_DDS_MIX_W1_dummy_7_mask                                         (0x00000080)
#define  DDS_PLL_DDS_MIX_W1_new_mode_lock_th_mask                                (0x00000070)
#define  DDS_PLL_DDS_MIX_W1_new_mode_en_mask                                     (0x00000008)
#define  DDS_PLL_DDS_MIX_W1_new_mode_en_th_mask                                  (0x00000007)
#define  DDS_PLL_DDS_MIX_W1_dummy_31(data)                                       (0x80000000&((data)<<31))
#define  DDS_PLL_DDS_MIX_W1_lock_th(data)                                        (0x70000000&((data)<<28))
#define  DDS_PLL_DDS_MIX_W1_t_s(data)                                            (0x0C000000&((data)<<26))
#define  DDS_PLL_DDS_MIX_W1_pll_lock(data)                                       (0x02000000&((data)<<25))
#define  DDS_PLL_DDS_MIX_W1_p_code_max(data)                                     (0x01FFFF00&((data)<<8))
#define  DDS_PLL_DDS_MIX_W1_dummy_7(data)                                        (0x00000080&((data)<<7))
#define  DDS_PLL_DDS_MIX_W1_new_mode_lock_th(data)                               (0x00000070&((data)<<4))
#define  DDS_PLL_DDS_MIX_W1_new_mode_en(data)                                    (0x00000008&((data)<<3))
#define  DDS_PLL_DDS_MIX_W1_new_mode_en_th(data)                                 (0x00000007&(data))
#define  DDS_PLL_DDS_MIX_W1_get_dummy_31(data)                                   ((0x80000000&(data))>>31)
#define  DDS_PLL_DDS_MIX_W1_get_lock_th(data)                                    ((0x70000000&(data))>>28)
#define  DDS_PLL_DDS_MIX_W1_get_t_s(data)                                        ((0x0C000000&(data))>>26)
#define  DDS_PLL_DDS_MIX_W1_get_pll_lock(data)                                   ((0x02000000&(data))>>25)
#define  DDS_PLL_DDS_MIX_W1_get_p_code_max(data)                                 ((0x01FFFF00&(data))>>8)
#define  DDS_PLL_DDS_MIX_W1_get_dummy_7(data)                                    ((0x00000080&(data))>>7)
#define  DDS_PLL_DDS_MIX_W1_get_new_mode_lock_th(data)                           ((0x00000070&(data))>>4)
#define  DDS_PLL_DDS_MIX_W1_get_new_mode_en(data)                                ((0x00000008&(data))>>3)
#define  DDS_PLL_DDS_MIX_W1_get_new_mode_en_th(data)                             (0x00000007&(data))

#define  DDS_PLL_DDS_MIX_W2                                                      0x18020120
#define  DDS_PLL_DDS_MIX_W2_reg_addr                                             "0xB8020120"
#define  DDS_PLL_DDS_MIX_W2_reg                                                  0xB8020120
#define  DDS_PLL_DDS_MIX_W2_inst_addr                                            "0x0008"
#define  set_DDS_PLL_DDS_MIX_W2_reg(data)                                        (*((volatile unsigned int*)DDS_PLL_DDS_MIX_W2_reg)=data)
#define  get_DDS_PLL_DDS_MIX_W2_reg                                              (*((volatile unsigned int*)DDS_PLL_DDS_MIX_W2_reg))
#define  DDS_PLL_DDS_MIX_W2_pll_m_final_shift                                    (16)
#define  DDS_PLL_DDS_MIX_W2_k_phase_final_shift                                  (12)
#define  DDS_PLL_DDS_MIX_W2_new_mode_i_code_en_shift                             (11)
#define  DDS_PLL_DDS_MIX_W2_change_mode_th_shift                                 (8)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_length_shift                             (6)
#define  DDS_PLL_DDS_MIX_W2_sample_period_shift                                  (4)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_reset_sel_shift                          (3)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_rst_shift                            (2)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_reg_shift                            (1)
#define  DDS_PLL_DDS_MIX_W2_apll_free_run_shift                                  (0)
#define  DDS_PLL_DDS_MIX_W2_pll_m_final_mask                                     (0x00FF0000)
#define  DDS_PLL_DDS_MIX_W2_k_phase_final_mask                                   (0x0000F000)
#define  DDS_PLL_DDS_MIX_W2_new_mode_i_code_en_mask                              (0x00000800)
#define  DDS_PLL_DDS_MIX_W2_change_mode_th_mask                                  (0x00000700)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_length_mask                              (0x000000C0)
#define  DDS_PLL_DDS_MIX_W2_sample_period_mask                                   (0x00000030)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_reset_sel_mask                           (0x00000008)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_rst_mask                             (0x00000004)
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_reg_mask                             (0x00000002)
#define  DDS_PLL_DDS_MIX_W2_apll_free_run_mask                                   (0x00000001)
#define  DDS_PLL_DDS_MIX_W2_pll_m_final(data)                                    (0x00FF0000&((data)<<16))
#define  DDS_PLL_DDS_MIX_W2_k_phase_final(data)                                  (0x0000F000&((data)<<12))
#define  DDS_PLL_DDS_MIX_W2_new_mode_i_code_en(data)                             (0x00000800&((data)<<11))
#define  DDS_PLL_DDS_MIX_W2_change_mode_th(data)                                 (0x00000700&((data)<<8))
#define  DDS_PLL_DDS_MIX_W2_delay_chain_length(data)                             (0x000000C0&((data)<<6))
#define  DDS_PLL_DDS_MIX_W2_sample_period(data)                                  (0x00000030&((data)<<4))
#define  DDS_PLL_DDS_MIX_W2_delay_chain_reset_sel(data)                          (0x00000008&((data)<<3))
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_rst(data)                            (0x00000004&((data)<<2))
#define  DDS_PLL_DDS_MIX_W2_delay_chain_sat_reg(data)                            (0x00000002&((data)<<1))
#define  DDS_PLL_DDS_MIX_W2_apll_free_run(data)                                  (0x00000001&(data))
#define  DDS_PLL_DDS_MIX_W2_get_pll_m_final(data)                                ((0x00FF0000&(data))>>16)
#define  DDS_PLL_DDS_MIX_W2_get_k_phase_final(data)                              ((0x0000F000&(data))>>12)
#define  DDS_PLL_DDS_MIX_W2_get_new_mode_i_code_en(data)                         ((0x00000800&(data))>>11)
#define  DDS_PLL_DDS_MIX_W2_get_change_mode_th(data)                             ((0x00000700&(data))>>8)
#define  DDS_PLL_DDS_MIX_W2_get_delay_chain_length(data)                         ((0x000000C0&(data))>>6)
#define  DDS_PLL_DDS_MIX_W2_get_sample_period(data)                              ((0x00000030&(data))>>4)
#define  DDS_PLL_DDS_MIX_W2_get_delay_chain_reset_sel(data)                      ((0x00000008&(data))>>3)
#define  DDS_PLL_DDS_MIX_W2_get_delay_chain_sat_rst(data)                        ((0x00000004&(data))>>2)
#define  DDS_PLL_DDS_MIX_W2_get_delay_chain_sat_reg(data)                        ((0x00000002&(data))>>1)
#define  DDS_PLL_DDS_MIX_W2_get_apll_free_run(data)                              (0x00000001&(data))

#define  DDS_PLL_PLL_DIV_CTRL                                                    0x18020124
#define  DDS_PLL_PLL_DIV_CTRL_reg_addr                                           "0xB8020124"
#define  DDS_PLL_PLL_DIV_CTRL_reg                                                0xB8020124
#define  DDS_PLL_PLL_DIV_CTRL_inst_addr                                          "0x0009"
#define  set_DDS_PLL_PLL_DIV_CTRL_reg(data)                                      (*((volatile unsigned int*)DDS_PLL_PLL_DIV_CTRL_reg)=data)
#define  get_DDS_PLL_PLL_DIV_CTRL_reg                                            (*((volatile unsigned int*)DDS_PLL_PLL_DIV_CTRL_reg))
#define  DDS_PLL_PLL_DIV_CTRL_tracking_edge_shift                                (7)
#define  DDS_PLL_PLL_DIV_CTRL_tracking_inv_shift                                 (6)
#define  DDS_PLL_PLL_DIV_CTRL_fast_lock_wait_shift                               (4)
#define  DDS_PLL_PLL_DIV_CTRL_delay_cp_mode_shift                                (0)
#define  DDS_PLL_PLL_DIV_CTRL_tracking_edge_mask                                 (0x00000080)
#define  DDS_PLL_PLL_DIV_CTRL_tracking_inv_mask                                  (0x00000040)
#define  DDS_PLL_PLL_DIV_CTRL_fast_lock_wait_mask                                (0x00000030)
#define  DDS_PLL_PLL_DIV_CTRL_delay_cp_mode_mask                                 (0x0000000F)
#define  DDS_PLL_PLL_DIV_CTRL_tracking_edge(data)                                (0x00000080&((data)<<7))
#define  DDS_PLL_PLL_DIV_CTRL_tracking_inv(data)                                 (0x00000040&((data)<<6))
#define  DDS_PLL_PLL_DIV_CTRL_fast_lock_wait(data)                               (0x00000030&((data)<<4))
#define  DDS_PLL_PLL_DIV_CTRL_delay_cp_mode(data)                                (0x0000000F&(data))
#define  DDS_PLL_PLL_DIV_CTRL_get_tracking_edge(data)                            ((0x00000080&(data))>>7)
#define  DDS_PLL_PLL_DIV_CTRL_get_tracking_inv(data)                             ((0x00000040&(data))>>6)
#define  DDS_PLL_PLL_DIV_CTRL_get_fast_lock_wait(data)                           ((0x00000030&(data))>>4)
#define  DDS_PLL_PLL_DIV_CTRL_get_delay_cp_mode(data)                            (0x0000000F&(data))

#define  DDS_PLL_I_CODE                                                          0x18020128
#define  DDS_PLL_I_CODE_reg_addr                                                 "0xB8020128"
#define  DDS_PLL_I_CODE_reg                                                      0xB8020128
#define  DDS_PLL_I_CODE_inst_addr                                                "0x000A"
#define  set_DDS_PLL_I_CODE_reg(data)                                            (*((volatile unsigned int*)DDS_PLL_I_CODE_reg)=data)
#define  get_DDS_PLL_I_CODE_reg                                                  (*((volatile unsigned int*)DDS_PLL_I_CODE_reg))
#define  DDS_PLL_I_CODE_dummy_15_shift                                           (15)
#define  DDS_PLL_I_CODE_i_code_shift                                             (0)
#define  DDS_PLL_I_CODE_dummy_15_mask                                            (0x00008000)
#define  DDS_PLL_I_CODE_i_code_mask                                              (0x00007FFF)
#define  DDS_PLL_I_CODE_dummy_15(data)                                           (0x00008000&((data)<<15))
#define  DDS_PLL_I_CODE_i_code(data)                                             (0x00007FFF&(data))
#define  DDS_PLL_I_CODE_get_dummy_15(data)                                       ((0x00008000&(data))>>15)
#define  DDS_PLL_I_CODE_get_i_code(data)                                         (0x00007FFF&(data))

#define  DDS_PLL_P_CODE                                                          0x1802012C
#define  DDS_PLL_P_CODE_reg_addr                                                 "0xB802012C"
#define  DDS_PLL_P_CODE_reg                                                      0xB802012C
#define  DDS_PLL_P_CODE_inst_addr                                                "0x000B"
#define  set_DDS_PLL_P_CODE_reg(data)                                            (*((volatile unsigned int*)DDS_PLL_P_CODE_reg)=data)
#define  get_DDS_PLL_P_CODE_reg                                                  (*((volatile unsigned int*)DDS_PLL_P_CODE_reg))
#define  DDS_PLL_P_CODE_p_code_shift                                             (0)
#define  DDS_PLL_P_CODE_p_code_mask                                              (0x000000FF)
#define  DDS_PLL_P_CODE_p_code(data)                                             (0x000000FF&(data))
#define  DDS_PLL_P_CODE_get_p_code(data)                                         (0x000000FF&(data))

#define  DDS_PLL_PFD_CALIBRATED_RESULTS                                          0x18020130
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_reg_addr                                 "0xB8020130"
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_reg                                      0xB8020130
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_inst_addr                                "0x000C"
#define  set_DDS_PLL_PFD_CALIBRATED_RESULTS_reg(data)                            (*((volatile unsigned int*)DDS_PLL_PFD_CALIBRATED_RESULTS_reg)=data)
#define  get_DDS_PLL_PFD_CALIBRATED_RESULTS_reg                                  (*((volatile unsigned int*)DDS_PLL_PFD_CALIBRATED_RESULTS_reg))
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_xclk_sel_shift                           (16)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_pfd_cal_en_shift                         (15)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_q_pe_4cal_shift                          (0)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_xclk_sel_mask                            (0x00030000)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_pfd_cal_en_mask                          (0x00008000)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_q_pe_4cal_mask                           (0x00007FFF)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_xclk_sel(data)                           (0x00030000&((data)<<16))
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_pfd_cal_en(data)                         (0x00008000&((data)<<15))
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_q_pe_4cal(data)                          (0x00007FFF&(data))
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_get_xclk_sel(data)                       ((0x00030000&(data))>>16)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_get_pfd_cal_en(data)                     ((0x00008000&(data))>>15)
#define  DDS_PLL_PFD_CALIBRATED_RESULTS_get_q_pe_4cal(data)                      (0x00007FFF&(data))

#define  DDS_PLL_PE_MEARSURE                                                     0x18020134
#define  DDS_PLL_PE_MEARSURE_reg_addr                                            "0xB8020134"
#define  DDS_PLL_PE_MEARSURE_reg                                                 0xB8020134
#define  DDS_PLL_PE_MEARSURE_inst_addr                                           "0x000D"
#define  set_DDS_PLL_PE_MEARSURE_reg(data)                                       (*((volatile unsigned int*)DDS_PLL_PE_MEARSURE_reg)=data)
#define  get_DDS_PLL_PE_MEARSURE_reg                                             (*((volatile unsigned int*)DDS_PLL_PE_MEARSURE_reg))
#define  DDS_PLL_PE_MEARSURE_pe_measure_en_shift                                 (15)
#define  DDS_PLL_PE_MEARSURE_dummy_14_12_shift                                   (12)
#define  DDS_PLL_PE_MEARSURE_pe_measure_reg_shift                                (0)
#define  DDS_PLL_PE_MEARSURE_pe_measure_en_mask                                  (0x00008000)
#define  DDS_PLL_PE_MEARSURE_dummy_14_12_mask                                    (0x00007000)
#define  DDS_PLL_PE_MEARSURE_pe_measure_reg_mask                                 (0x00000FFF)
#define  DDS_PLL_PE_MEARSURE_pe_measure_en(data)                                 (0x00008000&((data)<<15))
#define  DDS_PLL_PE_MEARSURE_dummy_14_12(data)                                   (0x00007000&((data)<<12))
#define  DDS_PLL_PE_MEARSURE_pe_measure_reg(data)                                (0x00000FFF&(data))
#define  DDS_PLL_PE_MEARSURE_get_pe_measure_en(data)                             ((0x00008000&(data))>>15)
#define  DDS_PLL_PE_MEARSURE_get_dummy_14_12(data)                               ((0x00007000&(data))>>12)
#define  DDS_PLL_PE_MEARSURE_get_pe_measure_reg(data)                            (0x00000FFF&(data))

#define  DDS_PLL_PE_MAX_MEASURE                                                  0x18020138
#define  DDS_PLL_PE_MAX_MEASURE_reg_addr                                         "0xB8020138"
#define  DDS_PLL_PE_MAX_MEASURE_reg                                              0xB8020138
#define  DDS_PLL_PE_MAX_MEASURE_inst_addr                                        "0x000E"
#define  set_DDS_PLL_PE_MAX_MEASURE_reg(data)                                    (*((volatile unsigned int*)DDS_PLL_PE_MAX_MEASURE_reg)=data)
#define  get_DDS_PLL_PE_MAX_MEASURE_reg                                          (*((volatile unsigned int*)DDS_PLL_PE_MAX_MEASURE_reg))
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_en_shift                          (15)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_clear_shift                       (14)
#define  DDS_PLL_PE_MAX_MEASURE_dummy_13_12_shift                                (12)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_reg_shift                         (0)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_en_mask                           (0x00008000)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_clear_mask                        (0x00004000)
#define  DDS_PLL_PE_MAX_MEASURE_dummy_13_12_mask                                 (0x00003000)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_reg_mask                          (0x00000FFF)
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_en(data)                          (0x00008000&((data)<<15))
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_clear(data)                       (0x00004000&((data)<<14))
#define  DDS_PLL_PE_MAX_MEASURE_dummy_13_12(data)                                (0x00003000&((data)<<12))
#define  DDS_PLL_PE_MAX_MEASURE_max_pe_measure_reg(data)                         (0x00000FFF&(data))
#define  DDS_PLL_PE_MAX_MEASURE_get_max_pe_measure_en(data)                      ((0x00008000&(data))>>15)
#define  DDS_PLL_PE_MAX_MEASURE_get_max_pe_measure_clear(data)                   ((0x00004000&(data))>>14)
#define  DDS_PLL_PE_MAX_MEASURE_get_dummy_13_12(data)                            ((0x00003000&(data))>>12)
#define  DDS_PLL_PE_MAX_MEASURE_get_max_pe_measure_reg(data)                     (0x00000FFF&(data))

#define  DDS_PLL_FAST_PLL_CTRL                                                   0x1802013C
#define  DDS_PLL_FAST_PLL_CTRL_reg_addr                                          "0xB802013C"
#define  DDS_PLL_FAST_PLL_CTRL_reg                                               0xB802013C
#define  DDS_PLL_FAST_PLL_CTRL_inst_addr                                         "0x000F"
#define  set_DDS_PLL_FAST_PLL_CTRL_reg(data)                                     (*((volatile unsigned int*)DDS_PLL_FAST_PLL_CTRL_reg)=data)
#define  get_DDS_PLL_FAST_PLL_CTRL_reg                                           (*((volatile unsigned int*)DDS_PLL_FAST_PLL_CTRL_reg))
#define  DDS_PLL_FAST_PLL_CTRL_apll_setting_en_shift                             (6)
#define  DDS_PLL_FAST_PLL_CTRL_fast_lock_en_shift                                (5)
#define  DDS_PLL_FAST_PLL_CTRL_v_active_sub_shift                                (4)
#define  DDS_PLL_FAST_PLL_CTRL_sum_i_update_en_shift                             (3)
#define  DDS_PLL_FAST_PLL_CTRL_measure_sum_i_shift                               (2)
#define  DDS_PLL_FAST_PLL_CTRL_dummy_1_shift                                     (1)
#define  DDS_PLL_FAST_PLL_CTRL_dummy_0_shift                                     (0)
#define  DDS_PLL_FAST_PLL_CTRL_apll_setting_en_mask                              (0x00000040)
#define  DDS_PLL_FAST_PLL_CTRL_fast_lock_en_mask                                 (0x00000020)
#define  DDS_PLL_FAST_PLL_CTRL_v_active_sub_mask                                 (0x00000010)
#define  DDS_PLL_FAST_PLL_CTRL_sum_i_update_en_mask                              (0x00000008)
#define  DDS_PLL_FAST_PLL_CTRL_measure_sum_i_mask                                (0x00000004)
#define  DDS_PLL_FAST_PLL_CTRL_dummy_1_mask                                      (0x00000002)
#define  DDS_PLL_FAST_PLL_CTRL_dummy_0_mask                                      (0x00000001)
#define  DDS_PLL_FAST_PLL_CTRL_apll_setting_en(data)                             (0x00000040&((data)<<6))
#define  DDS_PLL_FAST_PLL_CTRL_fast_lock_en(data)                                (0x00000020&((data)<<5))
#define  DDS_PLL_FAST_PLL_CTRL_v_active_sub(data)                                (0x00000010&((data)<<4))
#define  DDS_PLL_FAST_PLL_CTRL_sum_i_update_en(data)                             (0x00000008&((data)<<3))
#define  DDS_PLL_FAST_PLL_CTRL_measure_sum_i(data)                               (0x00000004&((data)<<2))
#define  DDS_PLL_FAST_PLL_CTRL_dummy_1(data)                                     (0x00000002&((data)<<1))
#define  DDS_PLL_FAST_PLL_CTRL_dummy_0(data)                                     (0x00000001&(data))
#define  DDS_PLL_FAST_PLL_CTRL_get_apll_setting_en(data)                         ((0x00000040&(data))>>6)
#define  DDS_PLL_FAST_PLL_CTRL_get_fast_lock_en(data)                            ((0x00000020&(data))>>5)
#define  DDS_PLL_FAST_PLL_CTRL_get_v_active_sub(data)                            ((0x00000010&(data))>>4)
#define  DDS_PLL_FAST_PLL_CTRL_get_sum_i_update_en(data)                         ((0x00000008&(data))>>3)
#define  DDS_PLL_FAST_PLL_CTRL_get_measure_sum_i(data)                           ((0x00000004&(data))>>2)
#define  DDS_PLL_FAST_PLL_CTRL_get_dummy_1(data)                                 ((0x00000002&(data))>>1)
#define  DDS_PLL_FAST_PLL_CTRL_get_dummy_0(data)                                 (0x00000001&(data))

#define  DDS_PLL_FAST_PLL_SUM_I                                                  0x18020140
#define  DDS_PLL_FAST_PLL_SUM_I_reg_addr                                         "0xB8020140"
#define  DDS_PLL_FAST_PLL_SUM_I_reg                                              0xB8020140
#define  DDS_PLL_FAST_PLL_SUM_I_inst_addr                                        "0x0010"
#define  set_DDS_PLL_FAST_PLL_SUM_I_reg(data)                                    (*((volatile unsigned int*)DDS_PLL_FAST_PLL_SUM_I_reg)=data)
#define  get_DDS_PLL_FAST_PLL_SUM_I_reg                                          (*((volatile unsigned int*)DDS_PLL_FAST_PLL_SUM_I_reg))
#define  DDS_PLL_FAST_PLL_SUM_I_sum_i_pre_shift                                  (0)
#define  DDS_PLL_FAST_PLL_SUM_I_sum_i_pre_mask                                   (0x07FFFFFF)
#define  DDS_PLL_FAST_PLL_SUM_I_sum_i_pre(data)                                  (0x07FFFFFF&(data))
#define  DDS_PLL_FAST_PLL_SUM_I_get_sum_i_pre(data)                              (0x07FFFFFF&(data))

#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE                                          0x18020144
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg_addr                                 "0xB8020144"
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg                                      0xB8020144
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_inst_addr                                "0x0011"
#define  set_DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg(data)                            (*((volatile unsigned int*)DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg)=data)
#define  get_DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg                                  (*((volatile unsigned int*)DDS_PLL_FAST_PLL_SUM_I_MEASURE_reg))
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg_shift                  (0)
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg_mask                   (0x07FFFFFF)
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg(data)                  (0x07FFFFFF&(data))
#define  DDS_PLL_FAST_PLL_SUM_I_MEASURE_get_sum_i_measure_reg(data)              (0x07FFFFFF&(data))

#define  DDS_PLL_APLL_TOP_MIX                                                    0x1802014C
#define  DDS_PLL_APLL_TOP_MIX_reg_addr                                           "0xB802014C"
#define  DDS_PLL_APLL_TOP_MIX_reg                                                0xB802014C
#define  DDS_PLL_APLL_TOP_MIX_inst_addr                                          "0x0012"
#define  set_DDS_PLL_APLL_TOP_MIX_reg(data)                                      (*((volatile unsigned int*)DDS_PLL_APLL_TOP_MIX_reg)=data)
#define  get_DDS_PLL_APLL_TOP_MIX_reg                                            (*((volatile unsigned int*)DDS_PLL_APLL_TOP_MIX_reg))
#define  DDS_PLL_APLL_TOP_MIX_debug_mux_shift                                    (13)
#define  DDS_PLL_APLL_TOP_MIX_porvset_shift                                      (11)
#define  DDS_PLL_APLL_TOP_MIX_pll_tp1_mux_shift                                  (8)
#define  DDS_PLL_APLL_TOP_MIX_pll_tp2_mux_shift                                  (4)
#define  DDS_PLL_APLL_TOP_MIX_testdiv_mux_shift                                  (0)
#define  DDS_PLL_APLL_TOP_MIX_debug_mux_mask                                     (0x0000E000)
#define  DDS_PLL_APLL_TOP_MIX_porvset_mask                                       (0x00001800)
#define  DDS_PLL_APLL_TOP_MIX_pll_tp1_mux_mask                                   (0x00000700)
#define  DDS_PLL_APLL_TOP_MIX_pll_tp2_mux_mask                                   (0x00000070)
#define  DDS_PLL_APLL_TOP_MIX_testdiv_mux_mask                                   (0x00000003)
#define  DDS_PLL_APLL_TOP_MIX_debug_mux(data)                                    (0x0000E000&((data)<<13))
#define  DDS_PLL_APLL_TOP_MIX_porvset(data)                                      (0x00001800&((data)<<11))
#define  DDS_PLL_APLL_TOP_MIX_pll_tp1_mux(data)                                  (0x00000700&((data)<<8))
#define  DDS_PLL_APLL_TOP_MIX_pll_tp2_mux(data)                                  (0x00000070&((data)<<4))
#define  DDS_PLL_APLL_TOP_MIX_testdiv_mux(data)                                  (0x00000003&(data))
#define  DDS_PLL_APLL_TOP_MIX_get_debug_mux(data)                                ((0x0000E000&(data))>>13)
#define  DDS_PLL_APLL_TOP_MIX_get_porvset(data)                                  ((0x00001800&(data))>>11)
#define  DDS_PLL_APLL_TOP_MIX_get_pll_tp1_mux(data)                              ((0x00000700&(data))>>8)
#define  DDS_PLL_APLL_TOP_MIX_get_pll_tp2_mux(data)                              ((0x00000070&(data))>>4)
#define  DDS_PLL_APLL_TOP_MIX_get_testdiv_mux(data)                              (0x00000003&(data))

#define  DDS_PLL_DDS_status                                                      0x18020150
#define  DDS_PLL_DDS_status_reg_addr                                             "0xB8020150"
#define  DDS_PLL_DDS_status_reg                                                  0xB8020150
#define  DDS_PLL_DDS_status_inst_addr                                            "0x0013"
#define  set_DDS_PLL_DDS_status_reg(data)                                        (*((volatile unsigned int*)DDS_PLL_DDS_status_reg)=data)
#define  get_DDS_PLL_DDS_status_reg                                              (*((volatile unsigned int*)DDS_PLL_DDS_status_reg))
#define  DDS_PLL_DDS_status_wd_to_main_shift                                     (31)
#define  DDS_PLL_DDS_status_wd_to_sub_shift                                      (30)
#define  DDS_PLL_DDS_status_dummy_29_28_shift                                    (28)
#define  DDS_PLL_DDS_status_new_mode_state_wd_en_shift                           (27)
#define  DDS_PLL_DDS_status_wait_state_wd_en_shift                               (26)
#define  DDS_PLL_DDS_status_change_mode_happen_wd_en_shift                       (25)
#define  DDS_PLL_DDS_status_adc_nolock_wd_en_shift                               (24)
#define  DDS_PLL_DDS_status_dummy_23_20_shift                                    (20)
#define  DDS_PLL_DDS_status_new_mode_state_int_en_shift                          (19)
#define  DDS_PLL_DDS_status_wait_state_int_en_shift                              (18)
#define  DDS_PLL_DDS_status_change_mode_happen_int_en_shift                      (17)
#define  DDS_PLL_DDS_status_adc_nolock_int_en_shift                              (16)
#define  DDS_PLL_DDS_status_dummy_15_4_shift                                     (4)
#define  DDS_PLL_DDS_status_new_mode_state_st_shift                              (3)
#define  DDS_PLL_DDS_status_wait_state_st_shift                                  (2)
#define  DDS_PLL_DDS_status_change_mode_happen_st_shift                          (1)
#define  DDS_PLL_DDS_status_adc_no_lock_st_shift                                 (0)
#define  DDS_PLL_DDS_status_wd_to_main_mask                                      (0x80000000)
#define  DDS_PLL_DDS_status_wd_to_sub_mask                                       (0x40000000)
#define  DDS_PLL_DDS_status_dummy_29_28_mask                                     (0x30000000)
#define  DDS_PLL_DDS_status_new_mode_state_wd_en_mask                            (0x08000000)
#define  DDS_PLL_DDS_status_wait_state_wd_en_mask                                (0x04000000)
#define  DDS_PLL_DDS_status_change_mode_happen_wd_en_mask                        (0x02000000)
#define  DDS_PLL_DDS_status_adc_nolock_wd_en_mask                                (0x01000000)
#define  DDS_PLL_DDS_status_dummy_23_20_mask                                     (0x00F00000)
#define  DDS_PLL_DDS_status_new_mode_state_int_en_mask                           (0x00080000)
#define  DDS_PLL_DDS_status_wait_state_int_en_mask                               (0x00040000)
#define  DDS_PLL_DDS_status_change_mode_happen_int_en_mask                       (0x00020000)
#define  DDS_PLL_DDS_status_adc_nolock_int_en_mask                               (0x00010000)
#define  DDS_PLL_DDS_status_dummy_15_4_mask                                      (0x0000FFF0)
#define  DDS_PLL_DDS_status_new_mode_state_st_mask                               (0x00000008)
#define  DDS_PLL_DDS_status_wait_state_st_mask                                   (0x00000004)
#define  DDS_PLL_DDS_status_change_mode_happen_st_mask                           (0x00000002)
#define  DDS_PLL_DDS_status_adc_no_lock_st_mask                                  (0x00000001)
#define  DDS_PLL_DDS_status_wd_to_main(data)                                     (0x80000000&((data)<<31))
#define  DDS_PLL_DDS_status_wd_to_sub(data)                                      (0x40000000&((data)<<30))
#define  DDS_PLL_DDS_status_dummy_29_28(data)                                    (0x30000000&((data)<<28))
#define  DDS_PLL_DDS_status_new_mode_state_wd_en(data)                           (0x08000000&((data)<<27))
#define  DDS_PLL_DDS_status_wait_state_wd_en(data)                               (0x04000000&((data)<<26))
#define  DDS_PLL_DDS_status_change_mode_happen_wd_en(data)                       (0x02000000&((data)<<25))
#define  DDS_PLL_DDS_status_adc_nolock_wd_en(data)                               (0x01000000&((data)<<24))
#define  DDS_PLL_DDS_status_dummy_23_20(data)                                    (0x00F00000&((data)<<20))
#define  DDS_PLL_DDS_status_new_mode_state_int_en(data)                          (0x00080000&((data)<<19))
#define  DDS_PLL_DDS_status_wait_state_int_en(data)                              (0x00040000&((data)<<18))
#define  DDS_PLL_DDS_status_change_mode_happen_int_en(data)                      (0x00020000&((data)<<17))
#define  DDS_PLL_DDS_status_adc_nolock_int_en(data)                              (0x00010000&((data)<<16))
#define  DDS_PLL_DDS_status_dummy_15_4(data)                                     (0x0000FFF0&((data)<<4))
#define  DDS_PLL_DDS_status_new_mode_state_st(data)                              (0x00000008&((data)<<3))
#define  DDS_PLL_DDS_status_wait_state_st(data)                                  (0x00000004&((data)<<2))
#define  DDS_PLL_DDS_status_change_mode_happen_st(data)                          (0x00000002&((data)<<1))
#define  DDS_PLL_DDS_status_adc_no_lock_st(data)                                 (0x00000001&(data))
#define  DDS_PLL_DDS_status_get_wd_to_main(data)                                 ((0x80000000&(data))>>31)
#define  DDS_PLL_DDS_status_get_wd_to_sub(data)                                  ((0x40000000&(data))>>30)
#define  DDS_PLL_DDS_status_get_dummy_29_28(data)                                ((0x30000000&(data))>>28)
#define  DDS_PLL_DDS_status_get_new_mode_state_wd_en(data)                       ((0x08000000&(data))>>27)
#define  DDS_PLL_DDS_status_get_wait_state_wd_en(data)                           ((0x04000000&(data))>>26)
#define  DDS_PLL_DDS_status_get_change_mode_happen_wd_en(data)                   ((0x02000000&(data))>>25)
#define  DDS_PLL_DDS_status_get_adc_nolock_wd_en(data)                           ((0x01000000&(data))>>24)
#define  DDS_PLL_DDS_status_get_dummy_23_20(data)                                ((0x00F00000&(data))>>20)
#define  DDS_PLL_DDS_status_get_new_mode_state_int_en(data)                      ((0x00080000&(data))>>19)
#define  DDS_PLL_DDS_status_get_wait_state_int_en(data)                          ((0x00040000&(data))>>18)
#define  DDS_PLL_DDS_status_get_change_mode_happen_int_en(data)                  ((0x00020000&(data))>>17)
#define  DDS_PLL_DDS_status_get_adc_nolock_int_en(data)                          ((0x00010000&(data))>>16)
#define  DDS_PLL_DDS_status_get_dummy_15_4(data)                                 ((0x0000FFF0&(data))>>4)
#define  DDS_PLL_DDS_status_get_new_mode_state_st(data)                          ((0x00000008&(data))>>3)
#define  DDS_PLL_DDS_status_get_wait_state_st(data)                              ((0x00000004&(data))>>2)
#define  DDS_PLL_DDS_status_get_change_mode_happen_st(data)                      ((0x00000002&(data))>>1)
#define  DDS_PLL_DDS_status_get_adc_no_lock_st(data)                             (0x00000001&(data))

#define  DDS_PLL_Jitter_Measure1                                                 0x18020154
#define  DDS_PLL_Jitter_Measure1_reg_addr                                        "0xB8020154"
#define  DDS_PLL_Jitter_Measure1_reg                                             0xB8020154
#define  DDS_PLL_Jitter_Measure1_inst_addr                                       "0x0014"
#define  set_DDS_PLL_Jitter_Measure1_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_Measure1_reg)=data)
#define  get_DDS_PLL_Jitter_Measure1_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_Measure1_reg))
#define  DDS_PLL_Jitter_Measure1_jms_winsize_shift                               (12)
#define  DDS_PLL_Jitter_Measure1_jms_lineth_shift                                (8)
#define  DDS_PLL_Jitter_Measure1_jms_pethsel_shift                               (4)
#define  DDS_PLL_Jitter_Measure1_jms_en_shift                                    (0)
#define  DDS_PLL_Jitter_Measure1_jms_winsize_mask                                (0x001FF000)
#define  DDS_PLL_Jitter_Measure1_jms_lineth_mask                                 (0x00000F00)
#define  DDS_PLL_Jitter_Measure1_jms_pethsel_mask                                (0x00000070)
#define  DDS_PLL_Jitter_Measure1_jms_en_mask                                     (0x00000001)
#define  DDS_PLL_Jitter_Measure1_jms_winsize(data)                               (0x001FF000&((data)<<12))
#define  DDS_PLL_Jitter_Measure1_jms_lineth(data)                                (0x00000F00&((data)<<8))
#define  DDS_PLL_Jitter_Measure1_jms_pethsel(data)                               (0x00000070&((data)<<4))
#define  DDS_PLL_Jitter_Measure1_jms_en(data)                                    (0x00000001&(data))
#define  DDS_PLL_Jitter_Measure1_get_jms_winsize(data)                           ((0x001FF000&(data))>>12)
#define  DDS_PLL_Jitter_Measure1_get_jms_lineth(data)                            ((0x00000F00&(data))>>8)
#define  DDS_PLL_Jitter_Measure1_get_jms_pethsel(data)                           ((0x00000070&(data))>>4)
#define  DDS_PLL_Jitter_Measure1_get_jms_en(data)                                (0x00000001&(data))

#define  DDS_PLL_Jitter_Measure2                                                 0x18020158
#define  DDS_PLL_Jitter_Measure2_reg_addr                                        "0xB8020158"
#define  DDS_PLL_Jitter_Measure2_reg                                             0xB8020158
#define  DDS_PLL_Jitter_Measure2_inst_addr                                       "0x0015"
#define  set_DDS_PLL_Jitter_Measure2_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_Measure2_reg)=data)
#define  get_DDS_PLL_Jitter_Measure2_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_Measure2_reg))
#define  DDS_PLL_Jitter_Measure2_jitter_in_win_r_shift                           (4)
#define  DDS_PLL_Jitter_Measure2_jitter_burst_happen_r_shift                     (0)
#define  DDS_PLL_Jitter_Measure2_jitter_in_win_r_mask                            (0x00001FF0)
#define  DDS_PLL_Jitter_Measure2_jitter_burst_happen_r_mask                      (0x00000001)
#define  DDS_PLL_Jitter_Measure2_jitter_in_win_r(data)                           (0x00001FF0&((data)<<4))
#define  DDS_PLL_Jitter_Measure2_jitter_burst_happen_r(data)                     (0x00000001&(data))
#define  DDS_PLL_Jitter_Measure2_get_jitter_in_win_r(data)                       ((0x00001FF0&(data))>>4)
#define  DDS_PLL_Jitter_Measure2_get_jitter_burst_happen_r(data)                 (0x00000001&(data))

#define  DDS_PLL_Jitter_PG_CTRL1                                                 0x18020160
#define  DDS_PLL_Jitter_PG_CTRL1_reg_addr                                        "0xB8020160"
#define  DDS_PLL_Jitter_PG_CTRL1_reg                                             0xB8020160
#define  DDS_PLL_Jitter_PG_CTRL1_inst_addr                                       "0x0016"
#define  set_DDS_PLL_Jitter_PG_CTRL1_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL1_reg)=data)
#define  get_DDS_PLL_Jitter_PG_CTRL1_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL1_reg))
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_str_shift                                  (20)
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_end_shift                                  (8)
#define  DDS_PLL_Jitter_PG_CTRL1_hs_glitch_en_shift                              (3)
#define  DDS_PLL_Jitter_PG_CTRL1_p_jitter_pol_shift                              (2)
#define  DDS_PLL_Jitter_PG_CTRL1_jitter_c2c_shift                                (1)
#define  DDS_PLL_Jitter_PG_CTRL1_hsptg_en_shift                                  (0)
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_str_mask                                   (0x7FF00000)
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_end_mask                                   (0x0007FF00)
#define  DDS_PLL_Jitter_PG_CTRL1_hs_glitch_en_mask                               (0x00000008)
#define  DDS_PLL_Jitter_PG_CTRL1_p_jitter_pol_mask                               (0x00000004)
#define  DDS_PLL_Jitter_PG_CTRL1_jitter_c2c_mask                                 (0x00000002)
#define  DDS_PLL_Jitter_PG_CTRL1_hsptg_en_mask                                   (0x00000001)
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_str(data)                                  (0x7FF00000&((data)<<20))
#define  DDS_PLL_Jitter_PG_CTRL1_vpls_end(data)                                  (0x0007FF00&((data)<<8))
#define  DDS_PLL_Jitter_PG_CTRL1_hs_glitch_en(data)                              (0x00000008&((data)<<3))
#define  DDS_PLL_Jitter_PG_CTRL1_p_jitter_pol(data)                              (0x00000004&((data)<<2))
#define  DDS_PLL_Jitter_PG_CTRL1_jitter_c2c(data)                                (0x00000002&((data)<<1))
#define  DDS_PLL_Jitter_PG_CTRL1_hsptg_en(data)                                  (0x00000001&(data))
#define  DDS_PLL_Jitter_PG_CTRL1_get_vpls_str(data)                              ((0x7FF00000&(data))>>20)
#define  DDS_PLL_Jitter_PG_CTRL1_get_vpls_end(data)                              ((0x0007FF00&(data))>>8)
#define  DDS_PLL_Jitter_PG_CTRL1_get_hs_glitch_en(data)                          ((0x00000008&(data))>>3)
#define  DDS_PLL_Jitter_PG_CTRL1_get_p_jitter_pol(data)                          ((0x00000004&(data))>>2)
#define  DDS_PLL_Jitter_PG_CTRL1_get_jitter_c2c(data)                            ((0x00000002&(data))>>1)
#define  DDS_PLL_Jitter_PG_CTRL1_get_hsptg_en(data)                              (0x00000001&(data))

#define  DDS_PLL_Jitter_PG_CTRL2                                                 0x18020164
#define  DDS_PLL_Jitter_PG_CTRL2_reg_addr                                        "0xB8020164"
#define  DDS_PLL_Jitter_PG_CTRL2_reg                                             0xB8020164
#define  DDS_PLL_Jitter_PG_CTRL2_inst_addr                                       "0x0017"
#define  set_DDS_PLL_Jitter_PG_CTRL2_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL2_reg)=data)
#define  get_DDS_PLL_Jitter_PG_CTRL2_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL2_reg))
#define  DDS_PLL_Jitter_PG_CTRL2_linenum_shift                                   (16)
#define  DDS_PLL_Jitter_PG_CTRL2_data_length_shift                               (0)
#define  DDS_PLL_Jitter_PG_CTRL2_linenum_mask                                    (0x07FF0000)
#define  DDS_PLL_Jitter_PG_CTRL2_data_length_mask                                (0x00003FFF)
#define  DDS_PLL_Jitter_PG_CTRL2_linenum(data)                                   (0x07FF0000&((data)<<16))
#define  DDS_PLL_Jitter_PG_CTRL2_data_length(data)                               (0x00003FFF&(data))
#define  DDS_PLL_Jitter_PG_CTRL2_get_linenum(data)                               ((0x07FF0000&(data))>>16)
#define  DDS_PLL_Jitter_PG_CTRL2_get_data_length(data)                           (0x00003FFF&(data))

#define  DDS_PLL_Jitter_PG_CTRL3                                                 0x18020168
#define  DDS_PLL_Jitter_PG_CTRL3_reg_addr                                        "0xB8020168"
#define  DDS_PLL_Jitter_PG_CTRL3_reg                                             0xB8020168
#define  DDS_PLL_Jitter_PG_CTRL3_inst_addr                                       "0x0018"
#define  set_DDS_PLL_Jitter_PG_CTRL3_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL3_reg)=data)
#define  get_DDS_PLL_Jitter_PG_CTRL3_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL3_reg))
#define  DDS_PLL_Jitter_PG_CTRL3_fpor_shift                                      (16)
#define  DDS_PLL_Jitter_PG_CTRL3_bpor_shift                                      (0)
#define  DDS_PLL_Jitter_PG_CTRL3_fpor_mask                                       (0x03FF0000)
#define  DDS_PLL_Jitter_PG_CTRL3_bpor_mask                                       (0x000003FF)
#define  DDS_PLL_Jitter_PG_CTRL3_fpor(data)                                      (0x03FF0000&((data)<<16))
#define  DDS_PLL_Jitter_PG_CTRL3_bpor(data)                                      (0x000003FF&(data))
#define  DDS_PLL_Jitter_PG_CTRL3_get_fpor(data)                                  ((0x03FF0000&(data))>>16)
#define  DDS_PLL_Jitter_PG_CTRL3_get_bpor(data)                                  (0x000003FF&(data))

#define  DDS_PLL_Jitter_PG_CTRL4                                                 0x1802016C
#define  DDS_PLL_Jitter_PG_CTRL4_reg_addr                                        "0xB802016C"
#define  DDS_PLL_Jitter_PG_CTRL4_reg                                             0xB802016C
#define  DDS_PLL_Jitter_PG_CTRL4_inst_addr                                       "0x0019"
#define  set_DDS_PLL_Jitter_PG_CTRL4_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL4_reg)=data)
#define  get_DDS_PLL_Jitter_PG_CTRL4_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL4_reg))
#define  DDS_PLL_Jitter_PG_CTRL4_hpls_shift                                      (16)
#define  DDS_PLL_Jitter_PG_CTRL4_h_jitter_shift                                  (0)
#define  DDS_PLL_Jitter_PG_CTRL4_hpls_mask                                       (0x03FF0000)
#define  DDS_PLL_Jitter_PG_CTRL4_h_jitter_mask                                   (0x000001FF)
#define  DDS_PLL_Jitter_PG_CTRL4_hpls(data)                                      (0x03FF0000&((data)<<16))
#define  DDS_PLL_Jitter_PG_CTRL4_h_jitter(data)                                  (0x000001FF&(data))
#define  DDS_PLL_Jitter_PG_CTRL4_get_hpls(data)                                  ((0x03FF0000&(data))>>16)
#define  DDS_PLL_Jitter_PG_CTRL4_get_h_jitter(data)                              (0x000001FF&(data))

#define  DDS_PLL_Jitter_PG_CTRL5                                                 0x18020170
#define  DDS_PLL_Jitter_PG_CTRL5_reg_addr                                        "0xB8020170"
#define  DDS_PLL_Jitter_PG_CTRL5_reg                                             0xB8020170
#define  DDS_PLL_Jitter_PG_CTRL5_inst_addr                                       "0x001A"
#define  set_DDS_PLL_Jitter_PG_CTRL5_reg(data)                                   (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL5_reg)=data)
#define  get_DDS_PLL_Jitter_PG_CTRL5_reg                                         (*((volatile unsigned int*)DDS_PLL_Jitter_PG_CTRL5_reg))
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_str_shift                                (16)
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_end_shift                                (0)
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_str_mask                                 (0x07FF0000)
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_end_mask                                 (0x000007FF)
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_str(data)                                (0x07FF0000&((data)<<16))
#define  DDS_PLL_Jitter_PG_CTRL5_jitter_end(data)                                (0x000007FF&(data))
#define  DDS_PLL_Jitter_PG_CTRL5_get_jitter_str(data)                            ((0x07FF0000&(data))>>16)
#define  DDS_PLL_Jitter_PG_CTRL5_get_jitter_end(data)                            (0x000007FF&(data))

#define  DDS_PLL_FREQ_CHG_DET_CTRL1                                              0x18020174
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_reg_addr                                     "0xB8020174"
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_reg                                          0xB8020174
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_inst_addr                                    "0x001B"
#define  set_DDS_PLL_FREQ_CHG_DET_CTRL1_reg(data)                                (*((volatile unsigned int*)DDS_PLL_FREQ_CHG_DET_CTRL1_reg)=data)
#define  get_DDS_PLL_FREQ_CHG_DET_CTRL1_reg                                      (*((volatile unsigned int*)DDS_PLL_FREQ_CHG_DET_CTRL1_reg))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r_shift                  (17)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r_shift                    (15)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r_shift                   (14)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r_shift                   (8)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_lpf_k_sel_shift                         (6)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_delta_scale_shift                            (4)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_new_freq_lpf_sel_shift                       (3)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel_shift                       (2)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_fw_catch_stb_freq_shift                      (1)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_chg_det_en_shift                        (0)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r_mask                   (0x000E0000)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r_mask                     (0x00008000)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r_mask                    (0x00004000)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r_mask                    (0x00003F00)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_lpf_k_sel_mask                          (0x000000C0)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_delta_scale_mask                             (0x00000030)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_new_freq_lpf_sel_mask                        (0x00000008)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel_mask                        (0x00000004)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_fw_catch_stb_freq_mask                       (0x00000002)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_chg_det_en_mask                         (0x00000001)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r(data)                  (0x000E0000&((data)<<17))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r(data)                    (0x00008000&((data)<<15))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r(data)                   (0x00004000&((data)<<14))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r(data)                   (0x00003F00&((data)<<8))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_lpf_k_sel(data)                         (0x000000C0&((data)<<6))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_delta_scale(data)                            (0x00000030&((data)<<4))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_new_freq_lpf_sel(data)                       (0x00000008&((data)<<3))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel(data)                       (0x00000004&((data)<<2))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_fw_catch_stb_freq(data)                      (0x00000002&((data)<<1))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_freq_chg_det_en(data)                        (0x00000001&(data))
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_dds_freq_chg_fsm_st_r(data)              ((0x000E0000&(data))>>17)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_dds_freq_chg_sign_r(data)                ((0x00008000&(data))>>15)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_dds_freq_chg_valid_r(data)               ((0x00004000&(data))>>14)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_dds_freq_chg_mag40_r(data)               ((0x00003F00&(data))>>8)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_freq_lpf_k_sel(data)                     ((0x000000C0&(data))>>6)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_delta_scale(data)                        ((0x00000030&(data))>>4)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_new_freq_lpf_sel(data)                   ((0x00000008&(data))>>3)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_stb_freq_lpf_sel(data)                   ((0x00000004&(data))>>2)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_fw_catch_stb_freq(data)                  ((0x00000002&(data))>>1)
#define  DDS_PLL_FREQ_CHG_DET_CTRL1_get_freq_chg_det_en(data)                    (0x00000001&(data))

#define  DDS_PLL_FREQ_CHG_DET_CTRL2                                              0x18020178
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_reg_addr                                     "0xB8020178"
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_reg                                          0xB8020178
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_inst_addr                                    "0x001C"
#define  set_DDS_PLL_FREQ_CHG_DET_CTRL2_reg(data)                                (*((volatile unsigned int*)DDS_PLL_FREQ_CHG_DET_CTRL2_reg)=data)
#define  get_DDS_PLL_FREQ_CHG_DET_CTRL2_reg                                      (*((volatile unsigned int*)DDS_PLL_FREQ_CHG_DET_CTRL2_reg))
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r_shift                       (2)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_dummy_1_shift                                (1)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_stb_k_manual_wr_shift                        (0)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r_mask                        (0x001FFFFC)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_dummy_1_mask                                 (0x00000002)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_stb_k_manual_wr_mask                         (0x00000001)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r(data)                       (0x001FFFFC&((data)<<2))
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_dummy_1(data)                                (0x00000002&((data)<<1))
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_stb_k_manual_wr(data)                        (0x00000001&(data))
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_get_k_of_sum_i_stb_r(data)                   ((0x001FFFFC&(data))>>2)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_get_dummy_1(data)                            ((0x00000002&(data))>>1)
#define  DDS_PLL_FREQ_CHG_DET_CTRL2_get_stb_k_manual_wr(data)                    (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DDS_PLL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  pllsphnext:4;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pll_n:3;
        RBus_UInt32  pll_m:8;
    };
}dds_pll_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  apllldopow:1;
        RBus_UInt32  apllldosel:2;
        RBus_UInt32  dummy18020104_15:1;
        RBus_UInt32  dummy18020104_14:1;
        RBus_UInt32  dummy18020104_13:1;
        RBus_UInt32  dummy18020104_12:1;
        RBus_UInt32  dummy18020104_11:1;
        RBus_UInt32  adckmode:2;
        RBus_UInt32  ps_en_already:1;
        RBus_UInt32  pllstatus:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  apll_reg:2;
        RBus_UInt32  hs_dds2synp_sel:1;
        RBus_UInt32  dds_rst:1;
        RBus_UInt32  pllpwdn:1;
    };
}dds_pll_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18020108_31_24:8;
        RBus_UInt32  apll_reserve:8;
        RBus_UInt32  dummy18020108_15:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pll_divider:12;
    };
}dds_pll_plldiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllsph0path:1;
        RBus_UInt32  res2:21;
    };
}dds_pll_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllsphrs:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllsadelay:2;
        RBus_UInt32  dummy18020110_0:1;
    };
}dds_pll_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  mapping_sel:2;
        RBus_UInt32  g_value:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  adap_track_i_en:1;
        RBus_UInt32  adap_track_p_en:1;
    };
}dds_pll_p_code_mapping_methods_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adap_track_pe_th:2;
        RBus_UInt32  adap_track_time_th:2;
        RBus_UInt32  high_speed_mask:1;
        RBus_UInt32  adap_track_en:1;
        RBus_UInt32  zoom_out_ratio:2;
    };
}dds_pll_pe_tracking_method_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802011c_31:1;
        RBus_UInt32  lock_th:3;
        RBus_UInt32  t_s:2;
        RBus_UInt32  pll_lock:1;
        RBus_UInt32  p_code_max:17;
        RBus_UInt32  dummy1802011c_7:1;
        RBus_UInt32  new_mode_lock_th:3;
        RBus_UInt32  new_mode_en:1;
        RBus_UInt32  new_mode_en_th:3;
    };
}dds_pll_dds_mix_w1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pll_m_final:8;
        RBus_UInt32  k_phase_final:4;
        RBus_UInt32  new_mode_i_code_en:1;
        RBus_UInt32  change_mode_th:3;
        RBus_UInt32  delay_chain_length:2;
        RBus_UInt32  sample_period:2;
        RBus_UInt32  delay_chain_reset_sel:1;
        RBus_UInt32  delay_chain_sat_rst:1;
        RBus_UInt32  delay_chain_sat_reg:1;
        RBus_UInt32  apll_free_run:1;
    };
}dds_pll_dds_mix_w2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  tracking_edge:1;
        RBus_UInt32  tracking_inv:1;
        RBus_UInt32  fast_lock_wait:2;
        RBus_UInt32  delay_cp_mode:4;
    };
}dds_pll_pll_div_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy18020128_15:1;
        RBus_UInt32  i_code:15;
    };
}dds_pll_i_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  p_code:8;
    };
}dds_pll_p_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  xclk_sel:2;
        RBus_UInt32  pfd_cal_en:1;
        RBus_UInt32  q_pe_4cal:15;
    };
}dds_pll_pfd_calibrated_results_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pe_measure_en:1;
        RBus_UInt32  dummy18020134_14_12:3;
        RBus_UInt32  pe_measure_reg:12;
    };
}dds_pll_pe_mearsure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  max_pe_measure_en:1;
        RBus_UInt32  max_pe_measure_clear:1;
        RBus_UInt32  dummy18020138_13_12:2;
        RBus_UInt32  max_pe_measure_reg:12;
    };
}dds_pll_pe_max_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  apll_setting_en:1;
        RBus_UInt32  fast_lock_en:1;
        RBus_UInt32  v_active_sub:1;
        RBus_UInt32  sum_i_update_en:1;
        RBus_UInt32  measure_sum_i:1;
        RBus_UInt32  dummy1802013c_1:1;
        RBus_UInt32  dummy1802013c_0:1;
    };
}dds_pll_fast_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sum_i_pre:27;
    };
}dds_pll_fast_pll_sum_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sum_i_measure_reg:27;
    };
}dds_pll_fast_pll_sum_i_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  debug_mux:3;
        RBus_UInt32  porvset:2;
        RBus_UInt32  pll_tp1_mux:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_tp2_mux:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  testdiv_mux:2;
    };
}dds_pll_apll_top_mix_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wd_to_main:1;
        RBus_UInt32  wd_to_sub:1;
        RBus_UInt32  dummy18020150_29_28:2;
        RBus_UInt32  new_mode_state_wd_en:1;
        RBus_UInt32  wait_state_wd_en:1;
        RBus_UInt32  change_mode_happen_wd_en:1;
        RBus_UInt32  adc_nolock_wd_en:1;
        RBus_UInt32  dummy18020150_23_20:4;
        RBus_UInt32  new_mode_state_int_en:1;
        RBus_UInt32  wait_state_int_en:1;
        RBus_UInt32  change_mode_happen_int_en:1;
        RBus_UInt32  adc_nolock_int_en:1;
        RBus_UInt32  dummy18020150_15_4:12;
        RBus_UInt32  new_mode_state_st:1;
        RBus_UInt32  wait_state_st:1;
        RBus_UInt32  change_mode_happen_st:1;
        RBus_UInt32  adc_no_lock_st:1;
    };
}dds_pll_dds_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  jms_winsize:9;
        RBus_UInt32  jms_lineth:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  jms_pethsel:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  jms_en:1;
    };
}dds_pll_jitter_measure1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  jitter_in_win_r:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  jitter_burst_happen_r:1;
    };
}dds_pll_jitter_measure2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vpls_str:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  vpls_end:11;
        RBus_UInt32  res3:4;
        RBus_UInt32  hs_glitch_en:1;
        RBus_UInt32  p_jitter_pol:1;
        RBus_UInt32  jitter_c2c:1;
        RBus_UInt32  hsptg_en:1;
    };
}dds_pll_jitter_pg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  linenum:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  data_length:14;
    };
}dds_pll_jitter_pg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  fpor:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  bpor:10;
    };
}dds_pll_jitter_pg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hpls:10;
        RBus_UInt32  res2:7;
        RBus_UInt32  h_jitter:9;
    };
}dds_pll_jitter_pg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  jitter_str:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  jitter_end:11;
    };
}dds_pll_jitter_pg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  dds_freq_chg_fsm_st_r:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dds_freq_chg_sign_r:1;
        RBus_UInt32  dds_freq_chg_valid_r:1;
        RBus_UInt32  dds_freq_chg_mag40_r:6;
        RBus_UInt32  freq_lpf_k_sel:2;
        RBus_UInt32  delta_scale:2;
        RBus_UInt32  new_freq_lpf_sel:1;
        RBus_UInt32  stb_freq_lpf_sel:1;
        RBus_UInt32  fw_catch_stb_freq:1;
        RBus_UInt32  freq_chg_det_en:1;
    };
}dds_pll_freq_chg_det_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  k_of_sum_i_stb_r:19;
        RBus_UInt32  dummy18020178_1:1;
        RBus_UInt32  stb_k_manual_wr:1;
    };
}dds_pll_freq_chg_det_ctrl2_RBUS;

#else //apply LITTLE_ENDIAN

//======DDS_PLL register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_m:8;
        RBus_UInt32  pll_n:3;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pllsphnext:4;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  res2:2;
    };
}dds_pll_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllpwdn:1;
        RBus_UInt32  dds_rst:1;
        RBus_UInt32  hs_dds2synp_sel:1;
        RBus_UInt32  apll_reg:2;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllstatus:1;
        RBus_UInt32  ps_en_already:1;
        RBus_UInt32  adckmode:2;
        RBus_UInt32  dummy18020104_11:1;
        RBus_UInt32  dummy18020104_12:1;
        RBus_UInt32  dummy18020104_13:1;
        RBus_UInt32  dummy18020104_14:1;
        RBus_UInt32  dummy18020104_15:1;
        RBus_UInt32  apllldosel:2;
        RBus_UInt32  apllldopow:1;
        RBus_UInt32  res1:13;
    };
}dds_pll_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_divider:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18020108_15:1;
        RBus_UInt32  apll_reserve:8;
        RBus_UInt32  dummy18020108_31_24:8;
    };
}dds_pll_plldiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  pllsph0path:1;
        RBus_UInt32  res2:10;
    };
}dds_pll_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18020110_0:1;
        RBus_UInt32  pllsadelay:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllsphrs:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res3:22;
    };
}dds_pll_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adap_track_p_en:1;
        RBus_UInt32  adap_track_i_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  g_value:4;
        RBus_UInt32  mapping_sel:2;
        RBus_UInt32  res2:22;
    };
}dds_pll_p_code_mapping_methods_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zoom_out_ratio:2;
        RBus_UInt32  adap_track_en:1;
        RBus_UInt32  high_speed_mask:1;
        RBus_UInt32  adap_track_time_th:2;
        RBus_UInt32  adap_track_pe_th:2;
        RBus_UInt32  res1:24;
    };
}dds_pll_pe_tracking_method_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_mode_en_th:3;
        RBus_UInt32  new_mode_en:1;
        RBus_UInt32  new_mode_lock_th:3;
        RBus_UInt32  dummy1802011c_7:1;
        RBus_UInt32  p_code_max:17;
        RBus_UInt32  pll_lock:1;
        RBus_UInt32  t_s:2;
        RBus_UInt32  lock_th:3;
        RBus_UInt32  dummy1802011c_31:1;
    };
}dds_pll_dds_mix_w1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  apll_free_run:1;
        RBus_UInt32  delay_chain_sat_reg:1;
        RBus_UInt32  delay_chain_sat_rst:1;
        RBus_UInt32  delay_chain_reset_sel:1;
        RBus_UInt32  sample_period:2;
        RBus_UInt32  delay_chain_length:2;
        RBus_UInt32  change_mode_th:3;
        RBus_UInt32  new_mode_i_code_en:1;
        RBus_UInt32  k_phase_final:4;
        RBus_UInt32  pll_m_final:8;
        RBus_UInt32  res1:8;
    };
}dds_pll_dds_mix_w2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_cp_mode:4;
        RBus_UInt32  fast_lock_wait:2;
        RBus_UInt32  tracking_inv:1;
        RBus_UInt32  tracking_edge:1;
        RBus_UInt32  res1:24;
    };
}dds_pll_pll_div_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_code:15;
        RBus_UInt32  dummy18020128_15:1;
        RBus_UInt32  res1:16;
    };
}dds_pll_i_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_code:8;
        RBus_UInt32  res1:24;
    };
}dds_pll_p_code_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  q_pe_4cal:15;
        RBus_UInt32  pfd_cal_en:1;
        RBus_UInt32  xclk_sel:2;
        RBus_UInt32  res1:14;
    };
}dds_pll_pfd_calibrated_results_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pe_measure_reg:12;
        RBus_UInt32  dummy18020134_14_12:3;
        RBus_UInt32  pe_measure_en:1;
        RBus_UInt32  res1:16;
    };
}dds_pll_pe_mearsure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_pe_measure_reg:12;
        RBus_UInt32  dummy18020138_13_12:2;
        RBus_UInt32  max_pe_measure_clear:1;
        RBus_UInt32  max_pe_measure_en:1;
        RBus_UInt32  res1:16;
    };
}dds_pll_pe_max_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802013c_0:1;
        RBus_UInt32  dummy1802013c_1:1;
        RBus_UInt32  measure_sum_i:1;
        RBus_UInt32  sum_i_update_en:1;
        RBus_UInt32  v_active_sub:1;
        RBus_UInt32  fast_lock_en:1;
        RBus_UInt32  apll_setting_en:1;
        RBus_UInt32  res1:25;
    };
}dds_pll_fast_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_i_pre:27;
        RBus_UInt32  res1:5;
    };
}dds_pll_fast_pll_sum_i_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_i_measure_reg:27;
        RBus_UInt32  res1:5;
    };
}dds_pll_fast_pll_sum_i_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testdiv_mux:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pll_tp2_mux:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_tp1_mux:3;
        RBus_UInt32  porvset:2;
        RBus_UInt32  debug_mux:3;
        RBus_UInt32  res3:16;
    };
}dds_pll_apll_top_mix_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_no_lock_st:1;
        RBus_UInt32  change_mode_happen_st:1;
        RBus_UInt32  wait_state_st:1;
        RBus_UInt32  new_mode_state_st:1;
        RBus_UInt32  dummy18020150_15_4:12;
        RBus_UInt32  adc_nolock_int_en:1;
        RBus_UInt32  change_mode_happen_int_en:1;
        RBus_UInt32  wait_state_int_en:1;
        RBus_UInt32  new_mode_state_int_en:1;
        RBus_UInt32  dummy18020150_23_20:4;
        RBus_UInt32  adc_nolock_wd_en:1;
        RBus_UInt32  change_mode_happen_wd_en:1;
        RBus_UInt32  wait_state_wd_en:1;
        RBus_UInt32  new_mode_state_wd_en:1;
        RBus_UInt32  dummy18020150_29_28:2;
        RBus_UInt32  wd_to_sub:1;
        RBus_UInt32  wd_to_main:1;
    };
}dds_pll_dds_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jms_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  jms_pethsel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  jms_lineth:4;
        RBus_UInt32  jms_winsize:9;
        RBus_UInt32  res3:11;
    };
}dds_pll_jitter_measure1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jitter_burst_happen_r:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  jitter_in_win_r:9;
        RBus_UInt32  res2:19;
    };
}dds_pll_jitter_measure2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsptg_en:1;
        RBus_UInt32  jitter_c2c:1;
        RBus_UInt32  p_jitter_pol:1;
        RBus_UInt32  hs_glitch_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  vpls_end:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  vpls_str:11;
        RBus_UInt32  res3:1;
    };
}dds_pll_jitter_pg_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_length:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  linenum:11;
        RBus_UInt32  res2:5;
    };
}dds_pll_jitter_pg_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bpor:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  fpor:10;
        RBus_UInt32  res2:6;
    };
}dds_pll_jitter_pg_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_jitter:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  hpls:10;
        RBus_UInt32  res2:6;
    };
}dds_pll_jitter_pg_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jitter_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  jitter_str:11;
        RBus_UInt32  res2:5;
    };
}dds_pll_jitter_pg_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  freq_chg_det_en:1;
        RBus_UInt32  fw_catch_stb_freq:1;
        RBus_UInt32  stb_freq_lpf_sel:1;
        RBus_UInt32  new_freq_lpf_sel:1;
        RBus_UInt32  delta_scale:2;
        RBus_UInt32  freq_lpf_k_sel:2;
        RBus_UInt32  dds_freq_chg_mag40_r:6;
        RBus_UInt32  dds_freq_chg_valid_r:1;
        RBus_UInt32  dds_freq_chg_sign_r:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dds_freq_chg_fsm_st_r:3;
        RBus_UInt32  res2:7;
        RBus_UInt32  res3:5;
    };
}dds_pll_freq_chg_det_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stb_k_manual_wr:1;
        RBus_UInt32  dummy18020178_1:1;
        RBus_UInt32  k_of_sum_i_stb_r:19;
        RBus_UInt32  res1:11;
    };
}dds_pll_freq_chg_det_ctrl2_RBUS;




#endif 


#endif 
