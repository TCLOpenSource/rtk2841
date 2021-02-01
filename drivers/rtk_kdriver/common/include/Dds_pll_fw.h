/*=============================================================
* Copyright C        Realtek Semiconductor Corporation, 2004 *
* All rights reserved.                                       *
* Build by tools[RS_MM2_SD] For FW                           *
*============================================================*/
/*======================= Description =======================*/
/*
 * @date 2014/7/30
 * @version { 1.0 }
*/

#ifndef _DDS_PLL_REG_H_INCLUDED_
#define _DDS_PLL_REG_H_INCLUDED_

//#define _DDS_PLL_USE_STRUCT
#ifdef _DDS_PLL_USE_STRUCT

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  pllscp:1;
        unsigned int  pllscs:2;
        unsigned int  pllsrs:3;
        unsigned int  reserved_1:3;
        unsigned int  pllssi:5;
        unsigned int  pllsphnext:4;
        unsigned int  pllsnbp:1;
        unsigned int  pll_n:3;
        unsigned int  pll_m:8;
}PLL_SET;

typedef struct
{
        unsigned int  reserved_0:13;
        unsigned int  apllldopow:1;
        unsigned int  apllldosel:2;
        unsigned int  dummy18020104_15:1;
        unsigned int  dummy18020104_14:1;
        unsigned int  dummy18020104_13:1;
        unsigned int  dummy18020104_12:1;
        unsigned int  dummy18020104_11:1;
        unsigned int  adckmode:2;
        unsigned int  ps_en_already:1;
        unsigned int  pllstatus:1;
        unsigned int  pllswdrst:1;
        unsigned int  pllswdset:1;
        unsigned int  apll_reg:2;
        unsigned int  hs_dds2synp_sel:1;
        unsigned int  dds_rst:1;
        unsigned int  pllpwdn:1;
}PLL_CTRL;

typedef struct
{
        unsigned int  dummy18020108_31_24:8;
        unsigned int  apll_reserve:8;
        unsigned int  dummy18020108_15:1;
        unsigned int  reserved_0:3;
        unsigned int  pll_divider:12;
}PLLDIV;

typedef struct
{
        unsigned int  reserved_0:9;
        unsigned int  pll2_ph_lut:1;
        unsigned int  pllsph0path:1;
        unsigned int  pll2d2:1;
        unsigned int  pll2_d2x:1;
        unsigned int  pll2_d2y:1;
        unsigned int  pll2x:1;
        unsigned int  pll2y:1;
        unsigned int  reserved_1:3;
        unsigned int  pll2_psel:5;
        unsigned int  reserved_2:1;
        unsigned int  pll2_ph_lut_index_msb:1;
        unsigned int  pll2_ph_lut_index:6;
}PLLPHASE_CTRL;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  pllsphrl:2;
        unsigned int  reserved_1:1;
        unsigned int  pllsphrs:3;
        unsigned int  reserved_2:1;
        unsigned int  pllsadelay:2;
        unsigned int  dummy18020110_0:1;
}PLL_PHASE_INTERPOLATION;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  mapping_sel:2;
        unsigned int  g_value:4;
        unsigned int  reserved_1:2;
        unsigned int  adap_track_i_en:1;
        unsigned int  adap_track_p_en:1;
}P_CODE_mapping_methods;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  adap_track_pe_th:2;
        unsigned int  adap_track_time_th:2;
        unsigned int  high_speed_mask:1;
        unsigned int  adap_track_en:1;
        unsigned int  zoom_out_ratio:2;
}PE_tracking_method;

typedef struct
{
        unsigned int  dummy1802011c_31:1;
        unsigned int  lock_th:3;
        unsigned int  t_s:2;
        unsigned int  pll_lock:1;
        unsigned int  p_code_max:17;
        unsigned int  dummy1802011c_7:1;
        unsigned int  new_mode_lock_th:3;
        unsigned int  new_mode_en:1;
        unsigned int  new_mode_en_th:3;
}DDS_MIX_W1;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  pll_m_final:8;
        unsigned int  k_phase_final:4;
        unsigned int  new_mode_i_code_en:1;
        unsigned int  change_mode_th:3;
        unsigned int  delay_chain_length:2;
        unsigned int  sample_period:2;
        unsigned int  delay_chain_reset_sel:1;
        unsigned int  delay_chain_sat_rst:1;
        unsigned int  delay_chain_sat_reg:1;
        unsigned int  apll_free_run:1;
}DDS_MIX_W2;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  tracking_edge:1;
        unsigned int  tracking_inv:1;
        unsigned int  fast_lock_wait:2;
        unsigned int  delay_cp_mode:4;
}PLL_DIV_CTRL;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  dummy18020128_15:1;
        unsigned int  i_code:15;
}I_CODE;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  p_code:8;
}P_CODE;

typedef struct
{
        unsigned int  reserved_0:14;
        unsigned int  xclk_sel:2;
        unsigned int  pfd_cal_en:1;
        unsigned int  q_pe_4cal:15;
}PFD_CALIBRATED_RESULTS;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  pe_measure_en:1;
        unsigned int  dummy18020134_14_12:3;
        unsigned int  pe_measure_reg:12;
}PE_MEARSURE;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  max_pe_measure_en:1;
        unsigned int  max_pe_measure_clear:1;
        unsigned int  dummy18020138_13_12:2;
        unsigned int  max_pe_measure_reg:12;
}PE_MAX_MEASURE;

typedef struct
{
        unsigned int  reserved_0:25;
        unsigned int  apll_setting_en:1;
        unsigned int  fast_lock_en:1;
        unsigned int  v_active_sub:1;
        unsigned int  sum_i_update_en:1;
        unsigned int  measure_sum_i:1;
        unsigned int  dummy1802013c_1:1;
        unsigned int  dummy1802013c_0:1;
}FAST_PLL_CTRL;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  sum_i_pre:27;
}FAST_PLL_SUM_I;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  sum_i_measure_reg:27;
}FAST_PLL_SUM_I_MEASURE;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  debug_mux:3;
        unsigned int  porvset:2;
        unsigned int  pll_tp1_mux:3;
        unsigned int  reserved_1:1;
        unsigned int  pll_tp2_mux:3;
        unsigned int  reserved_2:2;
        unsigned int  testdiv_mux:2;
}APLL_TOP_MIX;

typedef struct
{
        unsigned int  wd_to_main:1;
        unsigned int  wd_to_sub:1;
        unsigned int  dummy18020150_29_28:2;
        unsigned int  new_mode_state_wd_en:1;
        unsigned int  wait_state_wd_en:1;
        unsigned int  change_mode_happen_wd_en:1;
        unsigned int  adc_nolock_wd_en:1;
        unsigned int  dummy18020150_23_20:4;
        unsigned int  new_mode_state_int_en:1;
        unsigned int  wait_state_int_en:1;
        unsigned int  change_mode_happen_int_en:1;
        unsigned int  adc_nolock_int_en:1;
        unsigned int  dummy18020150_15_4:12;
        unsigned int  new_mode_state_st:1;
        unsigned int  wait_state_st:1;
        unsigned int  change_mode_happen_st:1;
        unsigned int  adc_no_lock_st:1;
}DDS_status;

typedef struct
{
        unsigned int  reserved_0:11;
        unsigned int  jms_winsize:9;
        unsigned int  jms_lineth:4;
        unsigned int  reserved_1:1;
        unsigned int  jms_pethsel:3;
        unsigned int  reserved_2:3;
        unsigned int  jms_en:1;
}Jitter_Measure1;

typedef struct
{
        unsigned int  reserved_0:19;
        unsigned int  jitter_in_win_r:9;
        unsigned int  reserved_1:3;
        unsigned int  jitter_burst_happen_r:1;
}Jitter_Measure2;

typedef struct
{
        unsigned int  reserved_0:1;
        unsigned int  vpls_str:11;
        unsigned int  reserved_1:1;
        unsigned int  vpls_end:11;
        unsigned int  reserved_2:4;
        unsigned int  hs_glitch_en:1;
        unsigned int  p_jitter_pol:1;
        unsigned int  jitter_c2c:1;
        unsigned int  hsptg_en:1;
}Jitter_PG_CTRL1;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  linenum:11;
        unsigned int  reserved_1:2;
        unsigned int  data_length:14;
}Jitter_PG_CTRL2;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  fpor:10;
        unsigned int  reserved_1:6;
        unsigned int  bpor:10;
}Jitter_PG_CTRL3;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  hpls:10;
        unsigned int  reserved_1:7;
        unsigned int  h_jitter:9;
}Jitter_PG_CTRL4;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  jitter_str:11;
        unsigned int  reserved_1:5;
        unsigned int  jitter_end:11;
}Jitter_PG_CTRL5;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  reserved_1:7;
        unsigned int  dds_freq_chg_fsm_st_r:3;
        unsigned int  reserved_2:1;
        unsigned int  dds_freq_chg_sign_r:1;
        unsigned int  dds_freq_chg_valid_r:1;
        unsigned int  dds_freq_chg_mag40_r:6;
        unsigned int  freq_lpf_k_sel:2;
        unsigned int  delta_scale:2;
        unsigned int  new_freq_lpf_sel:1;
        unsigned int  stb_freq_lpf_sel:1;
        unsigned int  fw_catch_stb_freq:1;
        unsigned int  freq_chg_det_en:1;
}FREQ_CHG_DET_CTRL1;

typedef struct
{
        unsigned int  reserved_0:11;
        unsigned int  k_of_sum_i_stb_r:19;
        unsigned int  dummy18020178_1:1;
        unsigned int  stb_k_manual_wr:1;
}FREQ_CHG_DET_CTRL2;

#define  PLL_SET                                                                0x18020100
#define  PLL_SET_reg_addr                                                       "0xB8020100"
#define  PLL_SET_reg                                                            0xB8020100
#define  PLL_SET_inst_addr                                                      "0x0000"
#define  PLL_SET_inst                                                           0x0000
#define  PLL_SET_pllscp_shift                                                   (29)
#define  PLL_SET_pllscs_shift                                                   (27)
#define  PLL_SET_pllsrs_shift                                                   (24)
#define  PLL_SET_pllssi_shift                                                   (16)
#define  PLL_SET_pllsphnext_shift                                               (12)
#define  PLL_SET_pllsnbp_shift                                                  (11)
#define  PLL_SET_pll_n_shift                                                    (8)
#define  PLL_SET_pll_m_shift                                                    (0)
#define  PLL_SET_pllscp_mask                                                    (0x20000000)
#define  PLL_SET_pllscs_mask                                                    (0x18000000)
#define  PLL_SET_pllsrs_mask                                                    (0x07000000)
#define  PLL_SET_pllssi_mask                                                    (0x001F0000)
#define  PLL_SET_pllsphnext_mask                                                (0x0000F000)
#define  PLL_SET_pllsnbp_mask                                                   (0x00000800)
#define  PLL_SET_pll_n_mask                                                     (0x00000700)
#define  PLL_SET_pll_m_mask                                                     (0x000000FF)
#define  PLL_SET_pllscp(data)                                                   (0x20000000&((data)<<29))
#define  PLL_SET_pllscs(data)                                                   (0x18000000&((data)<<27))
#define  PLL_SET_pllsrs(data)                                                   (0x07000000&((data)<<24))
#define  PLL_SET_pllssi(data)                                                   (0x001F0000&((data)<<16))
#define  PLL_SET_pllsphnext(data)                                               (0x0000F000&((data)<<12))
#define  PLL_SET_pllsnbp(data)                                                  (0x00000800&((data)<<11))
#define  PLL_SET_pll_n(data)                                                    (0x00000700&((data)<<8))
#define  PLL_SET_pll_m(data)                                                    (0x000000FF&(data))
#define  PLL_SET_get_pllscp(data)                                               ((0x20000000&(data))>>29)
#define  PLL_SET_get_pllscs(data)                                               ((0x18000000&(data))>>27)
#define  PLL_SET_get_pllsrs(data)                                               ((0x07000000&(data))>>24)
#define  PLL_SET_get_pllssi(data)                                               ((0x001F0000&(data))>>16)
#define  PLL_SET_get_pllsphnext(data)                                           ((0x0000F000&(data))>>12)
#define  PLL_SET_get_pllsnbp(data)                                              ((0x00000800&(data))>>11)
#define  PLL_SET_get_pll_n(data)                                                ((0x00000700&(data))>>8)
#define  PLL_SET_get_pll_m(data)                                                (0x000000FF&(data))

#define  PLL_CTRL                                                               0x18020104
#define  PLL_CTRL_reg_addr                                                      "0xB8020104"
#define  PLL_CTRL_reg                                                           0xB8020104
#define  PLL_CTRL_inst_addr                                                     "0x0001"
#define  PLL_CTRL_inst                                                          0x0001
#define  PLL_CTRL_apllldopow_shift                                              (18)
#define  PLL_CTRL_apllldosel_shift                                              (16)
#define  PLL_CTRL_dummy_shift                                                   (15)
#define  PLL_CTRL_dummy_shift                                                   (14)
#define  PLL_CTRL_dummy_shift                                                   (13)
#define  PLL_CTRL_dummy_shift                                                   (12)
#define  PLL_CTRL_dummy_shift                                                   (11)
#define  PLL_CTRL_adckmode_shift                                                (9)
#define  PLL_CTRL_ps_en_already_shift                                           (8)
#define  PLL_CTRL_pllstatus_shift                                               (7)
#define  PLL_CTRL_pllswdrst_shift                                               (6)
#define  PLL_CTRL_pllswdset_shift                                               (5)
#define  PLL_CTRL_apll_reg_shift                                                (3)
#define  PLL_CTRL_hs_dds2synp_sel_shift                                         (2)
#define  PLL_CTRL_dds_rst_shift                                                 (1)
#define  PLL_CTRL_pllpwdn_shift                                                 (0)
#define  PLL_CTRL_apllldopow_mask                                               (0x00040000)
#define  PLL_CTRL_apllldosel_mask                                               (0x00030000)
#define  PLL_CTRL_dummy_mask                                                    (0x00008000)
#define  PLL_CTRL_dummy_mask                                                    (0x00004000)
#define  PLL_CTRL_dummy_mask                                                    (0x00002000)
#define  PLL_CTRL_dummy_mask                                                    (0x00001000)
#define  PLL_CTRL_dummy_mask                                                    (0x00000800)
#define  PLL_CTRL_adckmode_mask                                                 (0x00000600)
#define  PLL_CTRL_ps_en_already_mask                                            (0x00000100)
#define  PLL_CTRL_pllstatus_mask                                                (0x00000080)
#define  PLL_CTRL_pllswdrst_mask                                                (0x00000040)
#define  PLL_CTRL_pllswdset_mask                                                (0x00000020)
#define  PLL_CTRL_apll_reg_mask                                                 (0x00000018)
#define  PLL_CTRL_hs_dds2synp_sel_mask                                          (0x00000004)
#define  PLL_CTRL_dds_rst_mask                                                  (0x00000002)
#define  PLL_CTRL_pllpwdn_mask                                                  (0x00000001)
#define  PLL_CTRL_apllldopow(data)                                              (0x00040000&((data)<<18))
#define  PLL_CTRL_apllldosel(data)                                              (0x00030000&((data)<<16))
#define  PLL_CTRL_dummy(data)                                                   (0x00008000&((data)<<15))
#define  PLL_CTRL_dummy(data)                                                   (0x00004000&((data)<<14))
#define  PLL_CTRL_dummy(data)                                                   (0x00002000&((data)<<13))
#define  PLL_CTRL_dummy(data)                                                   (0x00001000&((data)<<12))
#define  PLL_CTRL_dummy(data)                                                   (0x00000800&((data)<<11))
#define  PLL_CTRL_adckmode(data)                                                (0x00000600&((data)<<9))
#define  PLL_CTRL_ps_en_already(data)                                           (0x00000100&((data)<<8))
#define  PLL_CTRL_pllstatus(data)                                               (0x00000080&((data)<<7))
#define  PLL_CTRL_pllswdrst(data)                                               (0x00000040&((data)<<6))
#define  PLL_CTRL_pllswdset(data)                                               (0x00000020&((data)<<5))
#define  PLL_CTRL_apll_reg(data)                                                (0x00000018&((data)<<3))
#define  PLL_CTRL_hs_dds2synp_sel(data)                                         (0x00000004&((data)<<2))
#define  PLL_CTRL_dds_rst(data)                                                 (0x00000002&((data)<<1))
#define  PLL_CTRL_pllpwdn(data)                                                 (0x00000001&(data))
#define  PLL_CTRL_get_apllldopow(data)                                          ((0x00040000&(data))>>18)
#define  PLL_CTRL_get_apllldosel(data)                                          ((0x00030000&(data))>>16)
#define  PLL_CTRL_get_dummy(data)                                               ((0x00008000&(data))>>15)
#define  PLL_CTRL_get_dummy(data)                                               ((0x00004000&(data))>>14)
#define  PLL_CTRL_get_dummy(data)                                               ((0x00002000&(data))>>13)
#define  PLL_CTRL_get_dummy(data)                                               ((0x00001000&(data))>>12)
#define  PLL_CTRL_get_dummy(data)                                               ((0x00000800&(data))>>11)
#define  PLL_CTRL_get_adckmode(data)                                            ((0x00000600&(data))>>9)
#define  PLL_CTRL_get_ps_en_already(data)                                       ((0x00000100&(data))>>8)
#define  PLL_CTRL_get_pllstatus(data)                                           ((0x00000080&(data))>>7)
#define  PLL_CTRL_get_pllswdrst(data)                                           ((0x00000040&(data))>>6)
#define  PLL_CTRL_get_pllswdset(data)                                           ((0x00000020&(data))>>5)
#define  PLL_CTRL_get_apll_reg(data)                                            ((0x00000018&(data))>>3)
#define  PLL_CTRL_get_hs_dds2synp_sel(data)                                     ((0x00000004&(data))>>2)
#define  PLL_CTRL_get_dds_rst(data)                                             ((0x00000002&(data))>>1)
#define  PLL_CTRL_get_pllpwdn(data)                                             (0x00000001&(data))

#define  PLLDIV                                                                 0x18020108
#define  PLLDIV_reg_addr                                                        "0xB8020108"
#define  PLLDIV_reg                                                             0xB8020108
#define  PLLDIV_inst_addr                                                       "0x0002"
#define  PLLDIV_inst                                                            0x0002
#define  PLLDIV_dummy_shift                                                     (24)
#define  PLLDIV_apll_reserve_shift                                              (16)
#define  PLLDIV_dummy_shift                                                     (15)
#define  PLLDIV_pll_divider_shift                                               (0)
#define  PLLDIV_dummy_mask                                                      (0xFF000000)
#define  PLLDIV_apll_reserve_mask                                               (0x00FF0000)
#define  PLLDIV_dummy_mask                                                      (0x00008000)
#define  PLLDIV_pll_divider_mask                                                (0x00000FFF)
#define  PLLDIV_dummy(data)                                                     (0xFF000000&((data)<<24))
#define  PLLDIV_apll_reserve(data)                                              (0x00FF0000&((data)<<16))
#define  PLLDIV_dummy(data)                                                     (0x00008000&((data)<<15))
#define  PLLDIV_pll_divider(data)                                               (0x00000FFF&(data))
#define  PLLDIV_get_dummy(data)                                                 ((0xFF000000&(data))>>24)
#define  PLLDIV_get_apll_reserve(data)                                          ((0x00FF0000&(data))>>16)
#define  PLLDIV_get_dummy(data)                                                 ((0x00008000&(data))>>15)
#define  PLLDIV_get_pll_divider(data)                                           (0x00000FFF&(data))

#define  PLLPHASE_CTRL                                                          0x1802010C
#define  PLLPHASE_CTRL_reg_addr                                                 "0xB802010C"
#define  PLLPHASE_CTRL_reg                                                      0xB802010C
#define  PLLPHASE_CTRL_inst_addr                                                "0x0003"
#define  PLLPHASE_CTRL_inst                                                     0x0003
#define  PLLPHASE_CTRL_pll2_ph_lut_shift                                        (22)
#define  PLLPHASE_CTRL_pllsph0path_shift                                        (21)
#define  PLLPHASE_CTRL_pll2d2_shift                                             (20)
#define  PLLPHASE_CTRL_pll2_d2x_shift                                           (19)
#define  PLLPHASE_CTRL_pll2_d2y_shift                                           (18)
#define  PLLPHASE_CTRL_pll2x_shift                                              (17)
#define  PLLPHASE_CTRL_pll2y_shift                                              (16)
#define  PLLPHASE_CTRL_pll2_psel_shift                                          (8)
#define  PLLPHASE_CTRL_pll2_ph_lut_index_msb_shift                              (6)
#define  PLLPHASE_CTRL_pll2_ph_lut_index_shift                                  (0)
#define  PLLPHASE_CTRL_pll2_ph_lut_mask                                         (0x00400000)
#define  PLLPHASE_CTRL_pllsph0path_mask                                         (0x00200000)
#define  PLLPHASE_CTRL_pll2d2_mask                                              (0x00100000)
#define  PLLPHASE_CTRL_pll2_d2x_mask                                            (0x00080000)
#define  PLLPHASE_CTRL_pll2_d2y_mask                                            (0x00040000)
#define  PLLPHASE_CTRL_pll2x_mask                                               (0x00020000)
#define  PLLPHASE_CTRL_pll2y_mask                                               (0x00010000)
#define  PLLPHASE_CTRL_pll2_psel_mask                                           (0x00001F00)
#define  PLLPHASE_CTRL_pll2_ph_lut_index_msb_mask                               (0x00000040)
#define  PLLPHASE_CTRL_pll2_ph_lut_index_mask                                   (0x0000003F)
#define  PLLPHASE_CTRL_pll2_ph_lut(data)                                        (0x00400000&((data)<<22))
#define  PLLPHASE_CTRL_pllsph0path(data)                                        (0x00200000&((data)<<21))
#define  PLLPHASE_CTRL_pll2d2(data)                                             (0x00100000&((data)<<20))
#define  PLLPHASE_CTRL_pll2_d2x(data)                                           (0x00080000&((data)<<19))
#define  PLLPHASE_CTRL_pll2_d2y(data)                                           (0x00040000&((data)<<18))
#define  PLLPHASE_CTRL_pll2x(data)                                              (0x00020000&((data)<<17))
#define  PLLPHASE_CTRL_pll2y(data)                                              (0x00010000&((data)<<16))
#define  PLLPHASE_CTRL_pll2_psel(data)                                          (0x00001F00&((data)<<8))
#define  PLLPHASE_CTRL_pll2_ph_lut_index_msb(data)                              (0x00000040&((data)<<6))
#define  PLLPHASE_CTRL_pll2_ph_lut_index(data)                                  (0x0000003F&(data))
#define  PLLPHASE_CTRL_get_pll2_ph_lut(data)                                    ((0x00400000&(data))>>22)
#define  PLLPHASE_CTRL_get_pllsph0path(data)                                    ((0x00200000&(data))>>21)
#define  PLLPHASE_CTRL_get_pll2d2(data)                                         ((0x00100000&(data))>>20)
#define  PLLPHASE_CTRL_get_pll2_d2x(data)                                       ((0x00080000&(data))>>19)
#define  PLLPHASE_CTRL_get_pll2_d2y(data)                                       ((0x00040000&(data))>>18)
#define  PLLPHASE_CTRL_get_pll2x(data)                                          ((0x00020000&(data))>>17)
#define  PLLPHASE_CTRL_get_pll2y(data)                                          ((0x00010000&(data))>>16)
#define  PLLPHASE_CTRL_get_pll2_psel(data)                                      ((0x00001F00&(data))>>8)
#define  PLLPHASE_CTRL_get_pll2_ph_lut_index_msb(data)                          ((0x00000040&(data))>>6)
#define  PLLPHASE_CTRL_get_pll2_ph_lut_index(data)                              (0x0000003F&(data))

#define  PLL_PHASE_INTERPOLATION                                                0x18020110
#define  PLL_PHASE_INTERPOLATION_reg_addr                                       "0xB8020110"
#define  PLL_PHASE_INTERPOLATION_reg                                            0xB8020110
#define  PLL_PHASE_INTERPOLATION_inst_addr                                      "0x0004"
#define  PLL_PHASE_INTERPOLATION_inst                                           0x0004
#define  PLL_PHASE_INTERPOLATION_pllsphrl_shift                                 (8)
#define  PLL_PHASE_INTERPOLATION_pllsphrs_shift                                 (4)
#define  PLL_PHASE_INTERPOLATION_pllsadelay_shift                               (1)
#define  PLL_PHASE_INTERPOLATION_dummy_shift                                    (0)
#define  PLL_PHASE_INTERPOLATION_pllsphrl_mask                                  (0x00000300)
#define  PLL_PHASE_INTERPOLATION_pllsphrs_mask                                  (0x00000070)
#define  PLL_PHASE_INTERPOLATION_pllsadelay_mask                                (0x00000006)
#define  PLL_PHASE_INTERPOLATION_dummy_mask                                     (0x00000001)
#define  PLL_PHASE_INTERPOLATION_pllsphrl(data)                                 (0x00000300&((data)<<8))
#define  PLL_PHASE_INTERPOLATION_pllsphrs(data)                                 (0x00000070&((data)<<4))
#define  PLL_PHASE_INTERPOLATION_pllsadelay(data)                               (0x00000006&((data)<<1))
#define  PLL_PHASE_INTERPOLATION_dummy(data)                                    (0x00000001&(data))
#define  PLL_PHASE_INTERPOLATION_get_pllsphrl(data)                             ((0x00000300&(data))>>8)
#define  PLL_PHASE_INTERPOLATION_get_pllsphrs(data)                             ((0x00000070&(data))>>4)
#define  PLL_PHASE_INTERPOLATION_get_pllsadelay(data)                           ((0x00000006&(data))>>1)
#define  PLL_PHASE_INTERPOLATION_get_dummy(data)                                (0x00000001&(data))

#define  P_CODE_mapping_methods                                                 0x18020114
#define  P_CODE_mapping_methods_reg_addr                                        "0xB8020114"
#define  P_CODE_mapping_methods_reg                                             0xB8020114
#define  P_CODE_mapping_methods_inst_addr                                       "0x0005"
#define  P_CODE_mapping_methods_inst                                            0x0005
#define  P_CODE_mapping_methods_mapping_sel_shift                               (8)
#define  P_CODE_mapping_methods_g_value_shift                                   (4)
#define  P_CODE_mapping_methods_adap_track_i_en_shift                           (1)
#define  P_CODE_mapping_methods_adap_track_p_en_shift                           (0)
#define  P_CODE_mapping_methods_mapping_sel_mask                                (0x00000300)
#define  P_CODE_mapping_methods_g_value_mask                                    (0x000000F0)
#define  P_CODE_mapping_methods_adap_track_i_en_mask                            (0x00000002)
#define  P_CODE_mapping_methods_adap_track_p_en_mask                            (0x00000001)
#define  P_CODE_mapping_methods_mapping_sel(data)                               (0x00000300&((data)<<8))
#define  P_CODE_mapping_methods_g_value(data)                                   (0x000000F0&((data)<<4))
#define  P_CODE_mapping_methods_adap_track_i_en(data)                           (0x00000002&((data)<<1))
#define  P_CODE_mapping_methods_adap_track_p_en(data)                           (0x00000001&(data))
#define  P_CODE_mapping_methods_get_mapping_sel(data)                           ((0x00000300&(data))>>8)
#define  P_CODE_mapping_methods_get_g_value(data)                               ((0x000000F0&(data))>>4)
#define  P_CODE_mapping_methods_get_adap_track_i_en(data)                       ((0x00000002&(data))>>1)
#define  P_CODE_mapping_methods_get_adap_track_p_en(data)                       (0x00000001&(data))

#define  PE_tracking_method                                                     0x18020118
#define  PE_tracking_method_reg_addr                                            "0xB8020118"
#define  PE_tracking_method_reg                                                 0xB8020118
#define  PE_tracking_method_inst_addr                                           "0x0006"
#define  PE_tracking_method_inst                                                0x0006
#define  PE_tracking_method_adap_track_pe_th_shift                              (6)
#define  PE_tracking_method_adap_track_time_th_shift                            (4)
#define  PE_tracking_method_high_speed_mask_shift                               (3)
#define  PE_tracking_method_adap_track_en_shift                                 (2)
#define  PE_tracking_method_zoom_out_ratio_shift                                (0)
#define  PE_tracking_method_adap_track_pe_th_mask                               (0x000000C0)
#define  PE_tracking_method_adap_track_time_th_mask                             (0x00000030)
#define  PE_tracking_method_high_speed_mask_mask                                (0x00000008)
#define  PE_tracking_method_adap_track_en_mask                                  (0x00000004)
#define  PE_tracking_method_zoom_out_ratio_mask                                 (0x00000003)
#define  PE_tracking_method_adap_track_pe_th(data)                              (0x000000C0&((data)<<6))
#define  PE_tracking_method_adap_track_time_th(data)                            (0x00000030&((data)<<4))
#define  PE_tracking_method_high_speed_mask(data)                               (0x00000008&((data)<<3))
#define  PE_tracking_method_adap_track_en(data)                                 (0x00000004&((data)<<2))
#define  PE_tracking_method_zoom_out_ratio(data)                                (0x00000003&(data))
#define  PE_tracking_method_get_adap_track_pe_th(data)                          ((0x000000C0&(data))>>6)
#define  PE_tracking_method_get_adap_track_time_th(data)                        ((0x00000030&(data))>>4)
#define  PE_tracking_method_get_high_speed_mask(data)                           ((0x00000008&(data))>>3)
#define  PE_tracking_method_get_adap_track_en(data)                             ((0x00000004&(data))>>2)
#define  PE_tracking_method_get_zoom_out_ratio(data)                            (0x00000003&(data))

#define  DDS_MIX_W1                                                             0x1802011C
#define  DDS_MIX_W1_reg_addr                                                    "0xB802011C"
#define  DDS_MIX_W1_reg                                                         0xB802011C
#define  DDS_MIX_W1_inst_addr                                                   "0x0007"
#define  DDS_MIX_W1_inst                                                        0x0007
#define  DDS_MIX_W1_dummy_shift                                                 (31)
#define  DDS_MIX_W1_lock_th_shift                                               (28)
#define  DDS_MIX_W1_t_s_shift                                                   (26)
#define  DDS_MIX_W1_pll_lock_shift                                              (25)
#define  DDS_MIX_W1_p_code_max_shift                                            (8)
#define  DDS_MIX_W1_dummy_shift                                                 (7)
#define  DDS_MIX_W1_new_mode_lock_th_shift                                      (4)
#define  DDS_MIX_W1_new_mode_en_shift                                           (3)
#define  DDS_MIX_W1_new_mode_en_th_shift                                        (0)
#define  DDS_MIX_W1_dummy_mask                                                  (0x80000000)
#define  DDS_MIX_W1_lock_th_mask                                                (0x70000000)
#define  DDS_MIX_W1_t_s_mask                                                    (0x0C000000)
#define  DDS_MIX_W1_pll_lock_mask                                               (0x02000000)
#define  DDS_MIX_W1_p_code_max_mask                                             (0x01FFFF00)
#define  DDS_MIX_W1_dummy_mask                                                  (0x00000080)
#define  DDS_MIX_W1_new_mode_lock_th_mask                                       (0x00000070)
#define  DDS_MIX_W1_new_mode_en_mask                                            (0x00000008)
#define  DDS_MIX_W1_new_mode_en_th_mask                                         (0x00000007)
#define  DDS_MIX_W1_dummy(data)                                                 (0x80000000&((data)<<31))
#define  DDS_MIX_W1_lock_th(data)                                               (0x70000000&((data)<<28))
#define  DDS_MIX_W1_t_s(data)                                                   (0x0C000000&((data)<<26))
#define  DDS_MIX_W1_pll_lock(data)                                              (0x02000000&((data)<<25))
#define  DDS_MIX_W1_p_code_max(data)                                            (0x01FFFF00&((data)<<8))
#define  DDS_MIX_W1_dummy(data)                                                 (0x00000080&((data)<<7))
#define  DDS_MIX_W1_new_mode_lock_th(data)                                      (0x00000070&((data)<<4))
#define  DDS_MIX_W1_new_mode_en(data)                                           (0x00000008&((data)<<3))
#define  DDS_MIX_W1_new_mode_en_th(data)                                        (0x00000007&(data))
#define  DDS_MIX_W1_get_dummy(data)                                             ((0x80000000&(data))>>31)
#define  DDS_MIX_W1_get_lock_th(data)                                           ((0x70000000&(data))>>28)
#define  DDS_MIX_W1_get_t_s(data)                                               ((0x0C000000&(data))>>26)
#define  DDS_MIX_W1_get_pll_lock(data)                                          ((0x02000000&(data))>>25)
#define  DDS_MIX_W1_get_p_code_max(data)                                        ((0x01FFFF00&(data))>>8)
#define  DDS_MIX_W1_get_dummy(data)                                             ((0x00000080&(data))>>7)
#define  DDS_MIX_W1_get_new_mode_lock_th(data)                                  ((0x00000070&(data))>>4)
#define  DDS_MIX_W1_get_new_mode_en(data)                                       ((0x00000008&(data))>>3)
#define  DDS_MIX_W1_get_new_mode_en_th(data)                                    (0x00000007&(data))

#define  DDS_MIX_W2                                                             0x18020120
#define  DDS_MIX_W2_reg_addr                                                    "0xB8020120"
#define  DDS_MIX_W2_reg                                                         0xB8020120
#define  DDS_MIX_W2_inst_addr                                                   "0x0008"
#define  DDS_MIX_W2_inst                                                        0x0008
#define  DDS_MIX_W2_pll_m_final_shift                                           (16)
#define  DDS_MIX_W2_k_phase_final_shift                                         (12)
#define  DDS_MIX_W2_new_mode_i_code_en_shift                                    (11)
#define  DDS_MIX_W2_change_mode_th_shift                                        (8)
#define  DDS_MIX_W2_delay_chain_length_shift                                    (6)
#define  DDS_MIX_W2_sample_period_shift                                         (4)
#define  DDS_MIX_W2_delay_chain_reset_sel_shift                                 (3)
#define  DDS_MIX_W2_delay_chain_sat_rst_shift                                   (2)
#define  DDS_MIX_W2_delay_chain_sat_reg_shift                                   (1)
#define  DDS_MIX_W2_apll_free_run_shift                                         (0)
#define  DDS_MIX_W2_pll_m_final_mask                                            (0x00FF0000)
#define  DDS_MIX_W2_k_phase_final_mask                                          (0x0000F000)
#define  DDS_MIX_W2_new_mode_i_code_en_mask                                     (0x00000800)
#define  DDS_MIX_W2_change_mode_th_mask                                         (0x00000700)
#define  DDS_MIX_W2_delay_chain_length_mask                                     (0x000000C0)
#define  DDS_MIX_W2_sample_period_mask                                          (0x00000030)
#define  DDS_MIX_W2_delay_chain_reset_sel_mask                                  (0x00000008)
#define  DDS_MIX_W2_delay_chain_sat_rst_mask                                    (0x00000004)
#define  DDS_MIX_W2_delay_chain_sat_reg_mask                                    (0x00000002)
#define  DDS_MIX_W2_apll_free_run_mask                                          (0x00000001)
#define  DDS_MIX_W2_pll_m_final(data)                                           (0x00FF0000&((data)<<16))
#define  DDS_MIX_W2_k_phase_final(data)                                         (0x0000F000&((data)<<12))
#define  DDS_MIX_W2_new_mode_i_code_en(data)                                    (0x00000800&((data)<<11))
#define  DDS_MIX_W2_change_mode_th(data)                                        (0x00000700&((data)<<8))
#define  DDS_MIX_W2_delay_chain_length(data)                                    (0x000000C0&((data)<<6))
#define  DDS_MIX_W2_sample_period(data)                                         (0x00000030&((data)<<4))
#define  DDS_MIX_W2_delay_chain_reset_sel(data)                                 (0x00000008&((data)<<3))
#define  DDS_MIX_W2_delay_chain_sat_rst(data)                                   (0x00000004&((data)<<2))
#define  DDS_MIX_W2_delay_chain_sat_reg(data)                                   (0x00000002&((data)<<1))
#define  DDS_MIX_W2_apll_free_run(data)                                         (0x00000001&(data))
#define  DDS_MIX_W2_get_pll_m_final(data)                                       ((0x00FF0000&(data))>>16)
#define  DDS_MIX_W2_get_k_phase_final(data)                                     ((0x0000F000&(data))>>12)
#define  DDS_MIX_W2_get_new_mode_i_code_en(data)                                ((0x00000800&(data))>>11)
#define  DDS_MIX_W2_get_change_mode_th(data)                                    ((0x00000700&(data))>>8)
#define  DDS_MIX_W2_get_delay_chain_length(data)                                ((0x000000C0&(data))>>6)
#define  DDS_MIX_W2_get_sample_period(data)                                     ((0x00000030&(data))>>4)
#define  DDS_MIX_W2_get_delay_chain_reset_sel(data)                             ((0x00000008&(data))>>3)
#define  DDS_MIX_W2_get_delay_chain_sat_rst(data)                               ((0x00000004&(data))>>2)
#define  DDS_MIX_W2_get_delay_chain_sat_reg(data)                               ((0x00000002&(data))>>1)
#define  DDS_MIX_W2_get_apll_free_run(data)                                     (0x00000001&(data))

#define  PLL_DIV_CTRL                                                           0x18020124
#define  PLL_DIV_CTRL_reg_addr                                                  "0xB8020124"
#define  PLL_DIV_CTRL_reg                                                       0xB8020124
#define  PLL_DIV_CTRL_inst_addr                                                 "0x0009"
#define  PLL_DIV_CTRL_inst                                                      0x0009
#define  PLL_DIV_CTRL_tracking_edge_shift                                       (7)
#define  PLL_DIV_CTRL_tracking_inv_shift                                        (6)
#define  PLL_DIV_CTRL_fast_lock_wait_shift                                      (4)
#define  PLL_DIV_CTRL_delay_cp_mode_shift                                       (0)
#define  PLL_DIV_CTRL_tracking_edge_mask                                        (0x00000080)
#define  PLL_DIV_CTRL_tracking_inv_mask                                         (0x00000040)
#define  PLL_DIV_CTRL_fast_lock_wait_mask                                       (0x00000030)
#define  PLL_DIV_CTRL_delay_cp_mode_mask                                        (0x0000000F)
#define  PLL_DIV_CTRL_tracking_edge(data)                                       (0x00000080&((data)<<7))
#define  PLL_DIV_CTRL_tracking_inv(data)                                        (0x00000040&((data)<<6))
#define  PLL_DIV_CTRL_fast_lock_wait(data)                                      (0x00000030&((data)<<4))
#define  PLL_DIV_CTRL_delay_cp_mode(data)                                       (0x0000000F&(data))
#define  PLL_DIV_CTRL_get_tracking_edge(data)                                   ((0x00000080&(data))>>7)
#define  PLL_DIV_CTRL_get_tracking_inv(data)                                    ((0x00000040&(data))>>6)
#define  PLL_DIV_CTRL_get_fast_lock_wait(data)                                  ((0x00000030&(data))>>4)
#define  PLL_DIV_CTRL_get_delay_cp_mode(data)                                   (0x0000000F&(data))

#define  I_CODE                                                                 0x18020128
#define  I_CODE_reg_addr                                                        "0xB8020128"
#define  I_CODE_reg                                                             0xB8020128
#define  I_CODE_inst_addr                                                       "0x000A"
#define  I_CODE_inst                                                            0x000A
#define  I_CODE_dummy_shift                                                     (15)
#define  I_CODE_i_code_shift                                                    (0)
#define  I_CODE_dummy_mask                                                      (0x00008000)
#define  I_CODE_i_code_mask                                                     (0x00007FFF)
#define  I_CODE_dummy(data)                                                     (0x00008000&((data)<<15))
#define  I_CODE_i_code(data)                                                    (0x00007FFF&(data))
#define  I_CODE_get_dummy(data)                                                 ((0x00008000&(data))>>15)
#define  I_CODE_get_i_code(data)                                                (0x00007FFF&(data))

#define  P_CODE                                                                 0x1802012C
#define  P_CODE_reg_addr                                                        "0xB802012C"
#define  P_CODE_reg                                                             0xB802012C
#define  P_CODE_inst_addr                                                       "0x000B"
#define  P_CODE_inst                                                            0x000B
#define  P_CODE_p_code_shift                                                    (0)
#define  P_CODE_p_code_mask                                                     (0x000000FF)
#define  P_CODE_p_code(data)                                                    (0x000000FF&(data))
#define  P_CODE_get_p_code(data)                                                (0x000000FF&(data))

#define  PFD_CALIBRATED_RESULTS                                                 0x18020130
#define  PFD_CALIBRATED_RESULTS_reg_addr                                        "0xB8020130"
#define  PFD_CALIBRATED_RESULTS_reg                                             0xB8020130
#define  PFD_CALIBRATED_RESULTS_inst_addr                                       "0x000C"
#define  PFD_CALIBRATED_RESULTS_inst                                            0x000C
#define  PFD_CALIBRATED_RESULTS_xclk_sel_shift                                  (16)
#define  PFD_CALIBRATED_RESULTS_pfd_cal_en_shift                                (15)
#define  PFD_CALIBRATED_RESULTS_q_pe_4cal_shift                                 (0)
#define  PFD_CALIBRATED_RESULTS_xclk_sel_mask                                   (0x00030000)
#define  PFD_CALIBRATED_RESULTS_pfd_cal_en_mask                                 (0x00008000)
#define  PFD_CALIBRATED_RESULTS_q_pe_4cal_mask                                  (0x00007FFF)
#define  PFD_CALIBRATED_RESULTS_xclk_sel(data)                                  (0x00030000&((data)<<16))
#define  PFD_CALIBRATED_RESULTS_pfd_cal_en(data)                                (0x00008000&((data)<<15))
#define  PFD_CALIBRATED_RESULTS_q_pe_4cal(data)                                 (0x00007FFF&(data))
#define  PFD_CALIBRATED_RESULTS_get_xclk_sel(data)                              ((0x00030000&(data))>>16)
#define  PFD_CALIBRATED_RESULTS_get_pfd_cal_en(data)                            ((0x00008000&(data))>>15)
#define  PFD_CALIBRATED_RESULTS_get_q_pe_4cal(data)                             (0x00007FFF&(data))

#define  PE_MEARSURE                                                            0x18020134
#define  PE_MEARSURE_reg_addr                                                   "0xB8020134"
#define  PE_MEARSURE_reg                                                        0xB8020134
#define  PE_MEARSURE_inst_addr                                                  "0x000D"
#define  PE_MEARSURE_inst                                                       0x000D
#define  PE_MEARSURE_pe_measure_en_shift                                        (15)
#define  PE_MEARSURE_dummy_shift                                                (12)
#define  PE_MEARSURE_pe_measure_reg_shift                                       (0)
#define  PE_MEARSURE_pe_measure_en_mask                                         (0x00008000)
#define  PE_MEARSURE_dummy_mask                                                 (0x00007000)
#define  PE_MEARSURE_pe_measure_reg_mask                                        (0x00000FFF)
#define  PE_MEARSURE_pe_measure_en(data)                                        (0x00008000&((data)<<15))
#define  PE_MEARSURE_dummy(data)                                                (0x00007000&((data)<<12))
#define  PE_MEARSURE_pe_measure_reg(data)                                       (0x00000FFF&(data))
#define  PE_MEARSURE_get_pe_measure_en(data)                                    ((0x00008000&(data))>>15)
#define  PE_MEARSURE_get_dummy(data)                                            ((0x00007000&(data))>>12)
#define  PE_MEARSURE_get_pe_measure_reg(data)                                   (0x00000FFF&(data))

#define  PE_MAX_MEASURE                                                         0x18020138
#define  PE_MAX_MEASURE_reg_addr                                                "0xB8020138"
#define  PE_MAX_MEASURE_reg                                                     0xB8020138
#define  PE_MAX_MEASURE_inst_addr                                               "0x000E"
#define  PE_MAX_MEASURE_inst                                                    0x000E
#define  PE_MAX_MEASURE_max_pe_measure_en_shift                                 (15)
#define  PE_MAX_MEASURE_max_pe_measure_clear_shift                              (14)
#define  PE_MAX_MEASURE_dummy_shift                                             (12)
#define  PE_MAX_MEASURE_max_pe_measure_reg_shift                                (0)
#define  PE_MAX_MEASURE_max_pe_measure_en_mask                                  (0x00008000)
#define  PE_MAX_MEASURE_max_pe_measure_clear_mask                               (0x00004000)
#define  PE_MAX_MEASURE_dummy_mask                                              (0x00003000)
#define  PE_MAX_MEASURE_max_pe_measure_reg_mask                                 (0x00000FFF)
#define  PE_MAX_MEASURE_max_pe_measure_en(data)                                 (0x00008000&((data)<<15))
#define  PE_MAX_MEASURE_max_pe_measure_clear(data)                              (0x00004000&((data)<<14))
#define  PE_MAX_MEASURE_dummy(data)                                             (0x00003000&((data)<<12))
#define  PE_MAX_MEASURE_max_pe_measure_reg(data)                                (0x00000FFF&(data))
#define  PE_MAX_MEASURE_get_max_pe_measure_en(data)                             ((0x00008000&(data))>>15)
#define  PE_MAX_MEASURE_get_max_pe_measure_clear(data)                          ((0x00004000&(data))>>14)
#define  PE_MAX_MEASURE_get_dummy(data)                                         ((0x00003000&(data))>>12)
#define  PE_MAX_MEASURE_get_max_pe_measure_reg(data)                            (0x00000FFF&(data))

#define  FAST_PLL_CTRL                                                          0x1802013C
#define  FAST_PLL_CTRL_reg_addr                                                 "0xB802013C"
#define  FAST_PLL_CTRL_reg                                                      0xB802013C
#define  FAST_PLL_CTRL_inst_addr                                                "0x000F"
#define  FAST_PLL_CTRL_inst                                                     0x000F
#define  FAST_PLL_CTRL_apll_setting_en_shift                                    (6)
#define  FAST_PLL_CTRL_fast_lock_en_shift                                       (5)
#define  FAST_PLL_CTRL_v_active_sub_shift                                       (4)
#define  FAST_PLL_CTRL_sum_i_update_en_shift                                    (3)
#define  FAST_PLL_CTRL_measure_sum_i_shift                                      (2)
#define  FAST_PLL_CTRL_dummy_shift                                              (1)
#define  FAST_PLL_CTRL_dummy_shift                                              (0)
#define  FAST_PLL_CTRL_apll_setting_en_mask                                     (0x00000040)
#define  FAST_PLL_CTRL_fast_lock_en_mask                                        (0x00000020)
#define  FAST_PLL_CTRL_v_active_sub_mask                                        (0x00000010)
#define  FAST_PLL_CTRL_sum_i_update_en_mask                                     (0x00000008)
#define  FAST_PLL_CTRL_measure_sum_i_mask                                       (0x00000004)
#define  FAST_PLL_CTRL_dummy_mask                                               (0x00000002)
#define  FAST_PLL_CTRL_dummy_mask                                               (0x00000001)
#define  FAST_PLL_CTRL_apll_setting_en(data)                                    (0x00000040&((data)<<6))
#define  FAST_PLL_CTRL_fast_lock_en(data)                                       (0x00000020&((data)<<5))
#define  FAST_PLL_CTRL_v_active_sub(data)                                       (0x00000010&((data)<<4))
#define  FAST_PLL_CTRL_sum_i_update_en(data)                                    (0x00000008&((data)<<3))
#define  FAST_PLL_CTRL_measure_sum_i(data)                                      (0x00000004&((data)<<2))
#define  FAST_PLL_CTRL_dummy(data)                                              (0x00000002&((data)<<1))
#define  FAST_PLL_CTRL_dummy(data)                                              (0x00000001&(data))
#define  FAST_PLL_CTRL_get_apll_setting_en(data)                                ((0x00000040&(data))>>6)
#define  FAST_PLL_CTRL_get_fast_lock_en(data)                                   ((0x00000020&(data))>>5)
#define  FAST_PLL_CTRL_get_v_active_sub(data)                                   ((0x00000010&(data))>>4)
#define  FAST_PLL_CTRL_get_sum_i_update_en(data)                                ((0x00000008&(data))>>3)
#define  FAST_PLL_CTRL_get_measure_sum_i(data)                                  ((0x00000004&(data))>>2)
#define  FAST_PLL_CTRL_get_dummy(data)                                          ((0x00000002&(data))>>1)
#define  FAST_PLL_CTRL_get_dummy(data)                                          (0x00000001&(data))

#define  FAST_PLL_SUM_I                                                         0x18020140
#define  FAST_PLL_SUM_I_reg_addr                                                "0xB8020140"
#define  FAST_PLL_SUM_I_reg                                                     0xB8020140
#define  FAST_PLL_SUM_I_inst_addr                                               "0x0010"
#define  FAST_PLL_SUM_I_inst                                                    0x0010
#define  FAST_PLL_SUM_I_sum_i_pre_shift                                         (0)
#define  FAST_PLL_SUM_I_sum_i_pre_mask                                          (0x07FFFFFF)
#define  FAST_PLL_SUM_I_sum_i_pre(data)                                         (0x07FFFFFF&(data))
#define  FAST_PLL_SUM_I_get_sum_i_pre(data)                                     (0x07FFFFFF&(data))

#define  FAST_PLL_SUM_I_MEASURE                                                 0x18020144
#define  FAST_PLL_SUM_I_MEASURE_reg_addr                                        "0xB8020144"
#define  FAST_PLL_SUM_I_MEASURE_reg                                             0xB8020144
#define  FAST_PLL_SUM_I_MEASURE_inst_addr                                       "0x0011"
#define  FAST_PLL_SUM_I_MEASURE_inst                                            0x0011
#define  FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg_shift                         (0)
#define  FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg_mask                          (0x07FFFFFF)
#define  FAST_PLL_SUM_I_MEASURE_sum_i_measure_reg(data)                         (0x07FFFFFF&(data))
#define  FAST_PLL_SUM_I_MEASURE_get_sum_i_measure_reg(data)                     (0x07FFFFFF&(data))

#define  APLL_TOP_MIX                                                           0x1802014C
#define  APLL_TOP_MIX_reg_addr                                                  "0xB802014C"
#define  APLL_TOP_MIX_reg                                                       0xB802014C
#define  APLL_TOP_MIX_inst_addr                                                 "0x0012"
#define  APLL_TOP_MIX_inst                                                      0x0012
#define  APLL_TOP_MIX_debug_mux_shift                                           (13)
#define  APLL_TOP_MIX_porvset_shift                                             (11)
#define  APLL_TOP_MIX_pll_tp1_mux_shift                                         (8)
#define  APLL_TOP_MIX_pll_tp2_mux_shift                                         (4)
#define  APLL_TOP_MIX_testdiv_mux_shift                                         (0)
#define  APLL_TOP_MIX_debug_mux_mask                                            (0x0000E000)
#define  APLL_TOP_MIX_porvset_mask                                              (0x00001800)
#define  APLL_TOP_MIX_pll_tp1_mux_mask                                          (0x00000700)
#define  APLL_TOP_MIX_pll_tp2_mux_mask                                          (0x00000070)
#define  APLL_TOP_MIX_testdiv_mux_mask                                          (0x00000003)
#define  APLL_TOP_MIX_debug_mux(data)                                           (0x0000E000&((data)<<13))
#define  APLL_TOP_MIX_porvset(data)                                             (0x00001800&((data)<<11))
#define  APLL_TOP_MIX_pll_tp1_mux(data)                                         (0x00000700&((data)<<8))
#define  APLL_TOP_MIX_pll_tp2_mux(data)                                         (0x00000070&((data)<<4))
#define  APLL_TOP_MIX_testdiv_mux(data)                                         (0x00000003&(data))
#define  APLL_TOP_MIX_get_debug_mux(data)                                       ((0x0000E000&(data))>>13)
#define  APLL_TOP_MIX_get_porvset(data)                                         ((0x00001800&(data))>>11)
#define  APLL_TOP_MIX_get_pll_tp1_mux(data)                                     ((0x00000700&(data))>>8)
#define  APLL_TOP_MIX_get_pll_tp2_mux(data)                                     ((0x00000070&(data))>>4)
#define  APLL_TOP_MIX_get_testdiv_mux(data)                                     (0x00000003&(data))

#define  DDS_status                                                             0x18020150
#define  DDS_status_reg_addr                                                    "0xB8020150"
#define  DDS_status_reg                                                         0xB8020150
#define  DDS_status_inst_addr                                                   "0x0013"
#define  DDS_status_inst                                                        0x0013
#define  DDS_status_wd_to_main_shift                                            (31)
#define  DDS_status_wd_to_sub_shift                                             (30)
#define  DDS_status_dummy_shift                                                 (28)
#define  DDS_status_new_mode_state_wd_en_shift                                  (27)
#define  DDS_status_wait_state_wd_en_shift                                      (26)
#define  DDS_status_change_mode_happen_wd_en_shift                              (25)
#define  DDS_status_adc_nolock_wd_en_shift                                      (24)
#define  DDS_status_dummy_shift                                                 (20)
#define  DDS_status_new_mode_state_int_en_shift                                 (19)
#define  DDS_status_wait_state_int_en_shift                                     (18)
#define  DDS_status_change_mode_happen_int_en_shift                             (17)
#define  DDS_status_adc_nolock_int_en_shift                                     (16)
#define  DDS_status_dummy_shift                                                 (4)
#define  DDS_status_new_mode_state_st_shift                                     (3)
#define  DDS_status_wait_state_st_shift                                         (2)
#define  DDS_status_change_mode_happen_st_shift                                 (1)
#define  DDS_status_adc_no_lock_st_shift                                        (0)
#define  DDS_status_wd_to_main_mask                                             (0x80000000)
#define  DDS_status_wd_to_sub_mask                                              (0x40000000)
#define  DDS_status_dummy_mask                                                  (0x30000000)
#define  DDS_status_new_mode_state_wd_en_mask                                   (0x08000000)
#define  DDS_status_wait_state_wd_en_mask                                       (0x04000000)
#define  DDS_status_change_mode_happen_wd_en_mask                               (0x02000000)
#define  DDS_status_adc_nolock_wd_en_mask                                       (0x01000000)
#define  DDS_status_dummy_mask                                                  (0x00F00000)
#define  DDS_status_new_mode_state_int_en_mask                                  (0x00080000)
#define  DDS_status_wait_state_int_en_mask                                      (0x00040000)
#define  DDS_status_change_mode_happen_int_en_mask                              (0x00020000)
#define  DDS_status_adc_nolock_int_en_mask                                      (0x00010000)
#define  DDS_status_dummy_mask                                                  (0x0000FFF0)
#define  DDS_status_new_mode_state_st_mask                                      (0x00000008)
#define  DDS_status_wait_state_st_mask                                          (0x00000004)
#define  DDS_status_change_mode_happen_st_mask                                  (0x00000002)
#define  DDS_status_adc_no_lock_st_mask                                         (0x00000001)
#define  DDS_status_wd_to_main(data)                                            (0x80000000&((data)<<31))
#define  DDS_status_wd_to_sub(data)                                             (0x40000000&((data)<<30))
#define  DDS_status_dummy(data)                                                 (0x30000000&((data)<<28))
#define  DDS_status_new_mode_state_wd_en(data)                                  (0x08000000&((data)<<27))
#define  DDS_status_wait_state_wd_en(data)                                      (0x04000000&((data)<<26))
#define  DDS_status_change_mode_happen_wd_en(data)                              (0x02000000&((data)<<25))
#define  DDS_status_adc_nolock_wd_en(data)                                      (0x01000000&((data)<<24))
#define  DDS_status_dummy(data)                                                 (0x00F00000&((data)<<20))
#define  DDS_status_new_mode_state_int_en(data)                                 (0x00080000&((data)<<19))
#define  DDS_status_wait_state_int_en(data)                                     (0x00040000&((data)<<18))
#define  DDS_status_change_mode_happen_int_en(data)                             (0x00020000&((data)<<17))
#define  DDS_status_adc_nolock_int_en(data)                                     (0x00010000&((data)<<16))
#define  DDS_status_dummy(data)                                                 (0x0000FFF0&((data)<<4))
#define  DDS_status_new_mode_state_st(data)                                     (0x00000008&((data)<<3))
#define  DDS_status_wait_state_st(data)                                         (0x00000004&((data)<<2))
#define  DDS_status_change_mode_happen_st(data)                                 (0x00000002&((data)<<1))
#define  DDS_status_adc_no_lock_st(data)                                        (0x00000001&(data))
#define  DDS_status_get_wd_to_main(data)                                        ((0x80000000&(data))>>31)
#define  DDS_status_get_wd_to_sub(data)                                         ((0x40000000&(data))>>30)
#define  DDS_status_get_dummy(data)                                             ((0x30000000&(data))>>28)
#define  DDS_status_get_new_mode_state_wd_en(data)                              ((0x08000000&(data))>>27)
#define  DDS_status_get_wait_state_wd_en(data)                                  ((0x04000000&(data))>>26)
#define  DDS_status_get_change_mode_happen_wd_en(data)                          ((0x02000000&(data))>>25)
#define  DDS_status_get_adc_nolock_wd_en(data)                                  ((0x01000000&(data))>>24)
#define  DDS_status_get_dummy(data)                                             ((0x00F00000&(data))>>20)
#define  DDS_status_get_new_mode_state_int_en(data)                             ((0x00080000&(data))>>19)
#define  DDS_status_get_wait_state_int_en(data)                                 ((0x00040000&(data))>>18)
#define  DDS_status_get_change_mode_happen_int_en(data)                         ((0x00020000&(data))>>17)
#define  DDS_status_get_adc_nolock_int_en(data)                                 ((0x00010000&(data))>>16)
#define  DDS_status_get_dummy(data)                                             ((0x0000FFF0&(data))>>4)
#define  DDS_status_get_new_mode_state_st(data)                                 ((0x00000008&(data))>>3)
#define  DDS_status_get_wait_state_st(data)                                     ((0x00000004&(data))>>2)
#define  DDS_status_get_change_mode_happen_st(data)                             ((0x00000002&(data))>>1)
#define  DDS_status_get_adc_no_lock_st(data)                                    (0x00000001&(data))

#define  Jitter_Measure1                                                        0x18020154
#define  Jitter_Measure1_reg_addr                                               "0xB8020154"
#define  Jitter_Measure1_reg                                                    0xB8020154
#define  Jitter_Measure1_inst_addr                                              "0x0014"
#define  Jitter_Measure1_inst                                                   0x0014
#define  Jitter_Measure1_jms_winsize_shift                                      (12)
#define  Jitter_Measure1_jms_lineth_shift                                       (8)
#define  Jitter_Measure1_jms_pethsel_shift                                      (4)
#define  Jitter_Measure1_jms_en_shift                                           (0)
#define  Jitter_Measure1_jms_winsize_mask                                       (0x001FF000)
#define  Jitter_Measure1_jms_lineth_mask                                        (0x00000F00)
#define  Jitter_Measure1_jms_pethsel_mask                                       (0x00000070)
#define  Jitter_Measure1_jms_en_mask                                            (0x00000001)
#define  Jitter_Measure1_jms_winsize(data)                                      (0x001FF000&((data)<<12))
#define  Jitter_Measure1_jms_lineth(data)                                       (0x00000F00&((data)<<8))
#define  Jitter_Measure1_jms_pethsel(data)                                      (0x00000070&((data)<<4))
#define  Jitter_Measure1_jms_en(data)                                           (0x00000001&(data))
#define  Jitter_Measure1_get_jms_winsize(data)                                  ((0x001FF000&(data))>>12)
#define  Jitter_Measure1_get_jms_lineth(data)                                   ((0x00000F00&(data))>>8)
#define  Jitter_Measure1_get_jms_pethsel(data)                                  ((0x00000070&(data))>>4)
#define  Jitter_Measure1_get_jms_en(data)                                       (0x00000001&(data))

#define  Jitter_Measure2                                                        0x18020158
#define  Jitter_Measure2_reg_addr                                               "0xB8020158"
#define  Jitter_Measure2_reg                                                    0xB8020158
#define  Jitter_Measure2_inst_addr                                              "0x0015"
#define  Jitter_Measure2_inst                                                   0x0015
#define  Jitter_Measure2_jitter_in_win_r_shift                                  (4)
#define  Jitter_Measure2_jitter_burst_happen_r_shift                            (0)
#define  Jitter_Measure2_jitter_in_win_r_mask                                   (0x00001FF0)
#define  Jitter_Measure2_jitter_burst_happen_r_mask                             (0x00000001)
#define  Jitter_Measure2_jitter_in_win_r(data)                                  (0x00001FF0&((data)<<4))
#define  Jitter_Measure2_jitter_burst_happen_r(data)                            (0x00000001&(data))
#define  Jitter_Measure2_get_jitter_in_win_r(data)                              ((0x00001FF0&(data))>>4)
#define  Jitter_Measure2_get_jitter_burst_happen_r(data)                        (0x00000001&(data))

#define  Jitter_PG_CTRL1                                                        0x18020160
#define  Jitter_PG_CTRL1_reg_addr                                               "0xB8020160"
#define  Jitter_PG_CTRL1_reg                                                    0xB8020160
#define  Jitter_PG_CTRL1_inst_addr                                              "0x0016"
#define  Jitter_PG_CTRL1_inst                                                   0x0016
#define  Jitter_PG_CTRL1_vpls_str_shift                                         (20)
#define  Jitter_PG_CTRL1_vpls_end_shift                                         (8)
#define  Jitter_PG_CTRL1_hs_glitch_en_shift                                     (3)
#define  Jitter_PG_CTRL1_p_jitter_pol_shift                                     (2)
#define  Jitter_PG_CTRL1_jitter_c2c_shift                                       (1)
#define  Jitter_PG_CTRL1_hsptg_en_shift                                         (0)
#define  Jitter_PG_CTRL1_vpls_str_mask                                          (0x7FF00000)
#define  Jitter_PG_CTRL1_vpls_end_mask                                          (0x0007FF00)
#define  Jitter_PG_CTRL1_hs_glitch_en_mask                                      (0x00000008)
#define  Jitter_PG_CTRL1_p_jitter_pol_mask                                      (0x00000004)
#define  Jitter_PG_CTRL1_jitter_c2c_mask                                        (0x00000002)
#define  Jitter_PG_CTRL1_hsptg_en_mask                                          (0x00000001)
#define  Jitter_PG_CTRL1_vpls_str(data)                                         (0x7FF00000&((data)<<20))
#define  Jitter_PG_CTRL1_vpls_end(data)                                         (0x0007FF00&((data)<<8))
#define  Jitter_PG_CTRL1_hs_glitch_en(data)                                     (0x00000008&((data)<<3))
#define  Jitter_PG_CTRL1_p_jitter_pol(data)                                     (0x00000004&((data)<<2))
#define  Jitter_PG_CTRL1_jitter_c2c(data)                                       (0x00000002&((data)<<1))
#define  Jitter_PG_CTRL1_hsptg_en(data)                                         (0x00000001&(data))
#define  Jitter_PG_CTRL1_get_vpls_str(data)                                     ((0x7FF00000&(data))>>20)
#define  Jitter_PG_CTRL1_get_vpls_end(data)                                     ((0x0007FF00&(data))>>8)
#define  Jitter_PG_CTRL1_get_hs_glitch_en(data)                                 ((0x00000008&(data))>>3)
#define  Jitter_PG_CTRL1_get_p_jitter_pol(data)                                 ((0x00000004&(data))>>2)
#define  Jitter_PG_CTRL1_get_jitter_c2c(data)                                   ((0x00000002&(data))>>1)
#define  Jitter_PG_CTRL1_get_hsptg_en(data)                                     (0x00000001&(data))

#define  Jitter_PG_CTRL2                                                        0x18020164
#define  Jitter_PG_CTRL2_reg_addr                                               "0xB8020164"
#define  Jitter_PG_CTRL2_reg                                                    0xB8020164
#define  Jitter_PG_CTRL2_inst_addr                                              "0x0017"
#define  Jitter_PG_CTRL2_inst                                                   0x0017
#define  Jitter_PG_CTRL2_linenum_shift                                          (16)
#define  Jitter_PG_CTRL2_data_length_shift                                      (0)
#define  Jitter_PG_CTRL2_linenum_mask                                           (0x07FF0000)
#define  Jitter_PG_CTRL2_data_length_mask                                       (0x00003FFF)
#define  Jitter_PG_CTRL2_linenum(data)                                          (0x07FF0000&((data)<<16))
#define  Jitter_PG_CTRL2_data_length(data)                                      (0x00003FFF&(data))
#define  Jitter_PG_CTRL2_get_linenum(data)                                      ((0x07FF0000&(data))>>16)
#define  Jitter_PG_CTRL2_get_data_length(data)                                  (0x00003FFF&(data))

#define  Jitter_PG_CTRL3                                                        0x18020168
#define  Jitter_PG_CTRL3_reg_addr                                               "0xB8020168"
#define  Jitter_PG_CTRL3_reg                                                    0xB8020168
#define  Jitter_PG_CTRL3_inst_addr                                              "0x0018"
#define  Jitter_PG_CTRL3_inst                                                   0x0018
#define  Jitter_PG_CTRL3_fpor_shift                                             (16)
#define  Jitter_PG_CTRL3_bpor_shift                                             (0)
#define  Jitter_PG_CTRL3_fpor_mask                                              (0x03FF0000)
#define  Jitter_PG_CTRL3_bpor_mask                                              (0x000003FF)
#define  Jitter_PG_CTRL3_fpor(data)                                             (0x03FF0000&((data)<<16))
#define  Jitter_PG_CTRL3_bpor(data)                                             (0x000003FF&(data))
#define  Jitter_PG_CTRL3_get_fpor(data)                                         ((0x03FF0000&(data))>>16)
#define  Jitter_PG_CTRL3_get_bpor(data)                                         (0x000003FF&(data))

#define  Jitter_PG_CTRL4                                                        0x1802016C
#define  Jitter_PG_CTRL4_reg_addr                                               "0xB802016C"
#define  Jitter_PG_CTRL4_reg                                                    0xB802016C
#define  Jitter_PG_CTRL4_inst_addr                                              "0x0019"
#define  Jitter_PG_CTRL4_inst                                                   0x0019
#define  Jitter_PG_CTRL4_hpls_shift                                             (16)
#define  Jitter_PG_CTRL4_h_jitter_shift                                         (0)
#define  Jitter_PG_CTRL4_hpls_mask                                              (0x03FF0000)
#define  Jitter_PG_CTRL4_h_jitter_mask                                          (0x000001FF)
#define  Jitter_PG_CTRL4_hpls(data)                                             (0x03FF0000&((data)<<16))
#define  Jitter_PG_CTRL4_h_jitter(data)                                         (0x000001FF&(data))
#define  Jitter_PG_CTRL4_get_hpls(data)                                         ((0x03FF0000&(data))>>16)
#define  Jitter_PG_CTRL4_get_h_jitter(data)                                     (0x000001FF&(data))

#define  Jitter_PG_CTRL5                                                        0x18020170
#define  Jitter_PG_CTRL5_reg_addr                                               "0xB8020170"
#define  Jitter_PG_CTRL5_reg                                                    0xB8020170
#define  Jitter_PG_CTRL5_inst_addr                                              "0x001A"
#define  Jitter_PG_CTRL5_inst                                                   0x001A
#define  Jitter_PG_CTRL5_jitter_str_shift                                       (16)
#define  Jitter_PG_CTRL5_jitter_end_shift                                       (0)
#define  Jitter_PG_CTRL5_jitter_str_mask                                        (0x07FF0000)
#define  Jitter_PG_CTRL5_jitter_end_mask                                        (0x000007FF)
#define  Jitter_PG_CTRL5_jitter_str(data)                                       (0x07FF0000&((data)<<16))
#define  Jitter_PG_CTRL5_jitter_end(data)                                       (0x000007FF&(data))
#define  Jitter_PG_CTRL5_get_jitter_str(data)                                   ((0x07FF0000&(data))>>16)
#define  Jitter_PG_CTRL5_get_jitter_end(data)                                   (0x000007FF&(data))

#define  FREQ_CHG_DET_CTRL1                                                     0x18020174
#define  FREQ_CHG_DET_CTRL1_reg_addr                                            "0xB8020174"
#define  FREQ_CHG_DET_CTRL1_reg                                                 0xB8020174
#define  FREQ_CHG_DET_CTRL1_inst_addr                                           "0x001B"
#define  FREQ_CHG_DET_CTRL1_inst                                                0x001B
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r_shift                         (17)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r_shift                           (15)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r_shift                          (14)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r_shift                          (8)
#define  FREQ_CHG_DET_CTRL1_freq_lpf_k_sel_shift                                (6)
#define  FREQ_CHG_DET_CTRL1_delta_scale_shift                                   (4)
#define  FREQ_CHG_DET_CTRL1_new_freq_lpf_sel_shift                              (3)
#define  FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel_shift                              (2)
#define  FREQ_CHG_DET_CTRL1_fw_catch_stb_freq_shift                             (1)
#define  FREQ_CHG_DET_CTRL1_freq_chg_det_en_shift                               (0)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r_mask                          (0x000E0000)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r_mask                            (0x00008000)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r_mask                           (0x00004000)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r_mask                           (0x00003F00)
#define  FREQ_CHG_DET_CTRL1_freq_lpf_k_sel_mask                                 (0x000000C0)
#define  FREQ_CHG_DET_CTRL1_delta_scale_mask                                    (0x00000030)
#define  FREQ_CHG_DET_CTRL1_new_freq_lpf_sel_mask                               (0x00000008)
#define  FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel_mask                               (0x00000004)
#define  FREQ_CHG_DET_CTRL1_fw_catch_stb_freq_mask                              (0x00000002)
#define  FREQ_CHG_DET_CTRL1_freq_chg_det_en_mask                                (0x00000001)
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_fsm_st_r(data)                         (0x000E0000&((data)<<17))
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_sign_r(data)                           (0x00008000&((data)<<15))
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_valid_r(data)                          (0x00004000&((data)<<14))
#define  FREQ_CHG_DET_CTRL1_dds_freq_chg_mag40_r(data)                          (0x00003F00&((data)<<8))
#define  FREQ_CHG_DET_CTRL1_freq_lpf_k_sel(data)                                (0x000000C0&((data)<<6))
#define  FREQ_CHG_DET_CTRL1_delta_scale(data)                                   (0x00000030&((data)<<4))
#define  FREQ_CHG_DET_CTRL1_new_freq_lpf_sel(data)                              (0x00000008&((data)<<3))
#define  FREQ_CHG_DET_CTRL1_stb_freq_lpf_sel(data)                              (0x00000004&((data)<<2))
#define  FREQ_CHG_DET_CTRL1_fw_catch_stb_freq(data)                             (0x00000002&((data)<<1))
#define  FREQ_CHG_DET_CTRL1_freq_chg_det_en(data)                               (0x00000001&(data))
#define  FREQ_CHG_DET_CTRL1_get_dds_freq_chg_fsm_st_r(data)                     ((0x000E0000&(data))>>17)
#define  FREQ_CHG_DET_CTRL1_get_dds_freq_chg_sign_r(data)                       ((0x00008000&(data))>>15)
#define  FREQ_CHG_DET_CTRL1_get_dds_freq_chg_valid_r(data)                      ((0x00004000&(data))>>14)
#define  FREQ_CHG_DET_CTRL1_get_dds_freq_chg_mag40_r(data)                      ((0x00003F00&(data))>>8)
#define  FREQ_CHG_DET_CTRL1_get_freq_lpf_k_sel(data)                            ((0x000000C0&(data))>>6)
#define  FREQ_CHG_DET_CTRL1_get_delta_scale(data)                               ((0x00000030&(data))>>4)
#define  FREQ_CHG_DET_CTRL1_get_new_freq_lpf_sel(data)                          ((0x00000008&(data))>>3)
#define  FREQ_CHG_DET_CTRL1_get_stb_freq_lpf_sel(data)                          ((0x00000004&(data))>>2)
#define  FREQ_CHG_DET_CTRL1_get_fw_catch_stb_freq(data)                         ((0x00000002&(data))>>1)
#define  FREQ_CHG_DET_CTRL1_get_freq_chg_det_en(data)                           (0x00000001&(data))

#define  FREQ_CHG_DET_CTRL2                                                     0x18020178
#define  FREQ_CHG_DET_CTRL2_reg_addr                                            "0xB8020178"
#define  FREQ_CHG_DET_CTRL2_reg                                                 0xB8020178
#define  FREQ_CHG_DET_CTRL2_inst_addr                                           "0x001C"
#define  FREQ_CHG_DET_CTRL2_inst                                                0x001C
#define  FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r_shift                              (2)
#define  FREQ_CHG_DET_CTRL2_dummy_shift                                         (1)
#define  FREQ_CHG_DET_CTRL2_stb_k_manual_wr_shift                               (0)
#define  FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r_mask                               (0x001FFFFC)
#define  FREQ_CHG_DET_CTRL2_dummy_mask                                          (0x00000002)
#define  FREQ_CHG_DET_CTRL2_stb_k_manual_wr_mask                                (0x00000001)
#define  FREQ_CHG_DET_CTRL2_k_of_sum_i_stb_r(data)                              (0x001FFFFC&((data)<<2))
#define  FREQ_CHG_DET_CTRL2_dummy(data)                                         (0x00000002&((data)<<1))
#define  FREQ_CHG_DET_CTRL2_stb_k_manual_wr(data)                               (0x00000001&(data))
#define  FREQ_CHG_DET_CTRL2_get_k_of_sum_i_stb_r(data)                          ((0x001FFFFC&(data))>>2)
#define  FREQ_CHG_DET_CTRL2_get_dummy(data)                                     ((0x00000002&(data))>>1)
#define  FREQ_CHG_DET_CTRL2_get_stb_k_manual_wr(data)                           (0x00000001&(data))

#endif 
