/*=============================================================
* Copyright C        Realtek Semiconductor Corporation, 2004 *
* All rights reserved.                                       *
* Build by tools[RS_MM2_SD] For FW                           *
*============================================================*/
/*======================= Description =======================*/
/*
 * @date 2014-7-11
 * @version { 1.0 }
*/

#ifndef _MACARTHUR3_DESIGNSPEC_TP_REG_H_INCLUDED_
#define _MACARTHUR3_DESIGNSPEC_TP_REG_H_INCLUDED_

//#define _MACARTHUR3_DESIGNSPEC_TP_USE_STRUCT
#ifdef _MACARTHUR3_DESIGNSPEC_TP_USE_STRUCT

typedef struct
{
        unsigned int  reserved_0:14;
        unsigned int  tp_err_fix_en:1;
        unsigned int  strm_id_en:1;
        unsigned int  buf_rdy_ctl:1;
        unsigned int  psc_en:1;
        unsigned int  pes_en:1;
        unsigned int  tsc_en:1;
        unsigned int  tb:1;
        unsigned int  busy:1;
        unsigned int  mode:1;
        unsigned int  du_en:1;
        unsigned int  de_en:1;
        unsigned int  xt_en:1;
        unsigned int  pid_en:1;
        unsigned int  null_en:1;
        unsigned int  trerr_en:1;
        unsigned int  sync_en:1;
        unsigned int  rst_en:1;
        unsigned int  write_data:1;
}TP_TF0_CNTL;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF0_STRM_ID_0;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF0_STRM_ID_1;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF0_STRM_ID_2;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF0_STRM_ID_3;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  val_set33:1;
        unsigned int  val_set32:1;
        unsigned int  val_set31:1;
        unsigned int  val_set30:1;
        unsigned int  val_set23:1;
        unsigned int  val_set22:1;
        unsigned int  val_set21:1;
        unsigned int  val_set20:1;
        unsigned int  val_set13:1;
        unsigned int  val_set12:1;
        unsigned int  val_set11:1;
        unsigned int  val_set10:1;
        unsigned int  val_set03:1;
        unsigned int  val_set02:1;
        unsigned int  val_set01:1;
        unsigned int  val_set00:1;
}TP_TF0_STRM_VAL;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  cnt:24;
}TP_TF0_CNT;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  drp_cnt:16;
}TP_TF0_DRP_CNT;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  err_cnt:16;
}TP_TF0_ERR_CNT;

typedef struct
{
        unsigned int  sync_byte:8;
        unsigned int  dropno:4;
        unsigned int  lockno:4;
        unsigned int  packet_size:2;
        unsigned int  data_order:1;
        unsigned int  frm_en:1;
        unsigned int  forcedrop:1;
        unsigned int  syncmode:5;
        unsigned int  serial:1;
        unsigned int  datapin:1;
        unsigned int  err_pol:1;
        unsigned int  sync_pol:1;
        unsigned int  val_pol:1;
        unsigned int  clk_pol:1;
}TP_TF0_FRMCFG;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  adf_pcr_in:1;
        unsigned int  overflow:1;
        unsigned int  drop:1;
        unsigned int  sync:1;
        unsigned int  write_data:1;
}TP_TF0_INT;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  adf_pcr_in_en:1;
        unsigned int  overflow_en:1;
        unsigned int  drop_en:1;
        unsigned int  sync_en:1;
        unsigned int  write_data:1;
}TP_TF0_INT_EN;

typedef struct
{
        unsigned int  reserved_0:14;
        unsigned int  tp_err_fix_en:1;
        unsigned int  strm_id_en:1;
        unsigned int  buf_rdy_ctl:1;
        unsigned int  psc_en:1;
        unsigned int  pes_en:1;
        unsigned int  tsc_en:1;
        unsigned int  tb:1;
        unsigned int  busy:1;
        unsigned int  mode:1;
        unsigned int  du_en:1;
        unsigned int  de_en:1;
        unsigned int  xt_en:1;
        unsigned int  pid_en:1;
        unsigned int  null_en:1;
        unsigned int  trerr_en:1;
        unsigned int  sync_en:1;
        unsigned int  rst_en:1;
        unsigned int  write_data:1;
}TP_TF1_CNTL;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF1_STRM_ID_0;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF1_STRM_ID_1;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF1_STRM_ID_2;

typedef struct
{
        unsigned int  set3:8;
        unsigned int  set2:8;
        unsigned int  set1:8;
        unsigned int  set0:8;
}TP_TF1_STRM_ID_3;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  val_set33:1;
        unsigned int  val_set32:1;
        unsigned int  val_set31:1;
        unsigned int  val_set30:1;
        unsigned int  val_set23:1;
        unsigned int  val_set22:1;
        unsigned int  val_set21:1;
        unsigned int  val_set20:1;
        unsigned int  val_set13:1;
        unsigned int  val_set12:1;
        unsigned int  val_set11:1;
        unsigned int  val_set10:1;
        unsigned int  val_set03:1;
        unsigned int  val_set02:1;
        unsigned int  val_set01:1;
        unsigned int  val_set00:1;
}TP_TF1_STRM_VAL;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  cnt:24;
}TP_TF1_CNT;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  drp_cnt:16;
}TP_TF1_DRP_CNT;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  err_cnt:16;
}TP_TF1_ERR_CNT;

typedef struct
{
        unsigned int  sync_byte:8;
        unsigned int  dropno:4;
        unsigned int  lockno:4;
        unsigned int  packet_size:2;
        unsigned int  data_order:1;
        unsigned int  frm_en:1;
        unsigned int  forcedrop:1;
        unsigned int  syncmode:5;
        unsigned int  serial:1;
        unsigned int  datapin:1;
        unsigned int  err_pol:1;
        unsigned int  sync_pol:1;
        unsigned int  val_pol:1;
        unsigned int  clk_pol:1;
}TP_TF1_FRMCFG;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  adf_pcr_in:1;
        unsigned int  overflow:1;
        unsigned int  drop:1;
        unsigned int  sync:1;
        unsigned int  write_data:1;
}TP_TF1_INT;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  adf_pcr_in_en:1;
        unsigned int  overflow_en:1;
        unsigned int  drop_en:1;
        unsigned int  sync_en:1;
        unsigned int  write_data:1;
}TP_TF1_INT_EN;

typedef struct
{
        unsigned int  reserved_0:10;
        unsigned int  byps_tperr_en:1;
        unsigned int  tperr_bit_sel:1;
        unsigned int  in_tp_out_en:1;
        unsigned int  in_tp_rst:1;
        unsigned int  data_src:2;
        unsigned int  reserved_1:1;
        unsigned int  in_data_order:1;
        unsigned int  in_serial:1;
        unsigned int  in_datapin:1;
        unsigned int  in_err_pol:1;
        unsigned int  in_sync_pol:1;
        unsigned int  in_val_pol:1;
        unsigned int  in_clk_pol:1;
        unsigned int  reserved_2:1;
        unsigned int  out_data_order:1;
        unsigned int  out_serial:1;
        unsigned int  reserved_3:1;
        unsigned int  out_err_pol:1;
        unsigned int  out_sync_pol:1;
        unsigned int  out_val_pol:1;
        unsigned int  out_clk_pol:1;
}TP_TF_OUT_FRMCFG;

typedef struct
{
        unsigned int  reserved_0:12;
        unsigned int  sync_dur:1;
        unsigned int  ck_gate:1;
        unsigned int  tp_frame_rate:13;
        unsigned int  tp_clk_div:5;
}TP_OUT_CTRL;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  tp_err_fix_en:1;
        unsigned int  write_data:1;
}TP_TF2_CNTL;

typedef struct
{
        unsigned int  reserved_0:21;
        unsigned int  syncmode:5;
        unsigned int  reserved_1:6;
}TP_TF2_FRMCFG;

typedef struct
{
        unsigned int  pcr_90k_cnt_high:32;
}TP_PCR_90K_CNT_HIGH;

typedef struct
{
        unsigned int  pcr_90k_cnt:32;
}TP_PCR_90K_CNT;

typedef struct
{
        unsigned int  reserved_0:21;
        unsigned int  stc_cnt_sel:1;
        unsigned int  stc_64bit_en:1;
        unsigned int  extra_func_ena:1;
        unsigned int  reserved_1:1;
        unsigned int  extra_pid_addr:7;
}TP0_PCR_CTL;

typedef struct
{
        unsigned int  reserved_0:23;
        unsigned int  extra_func_ena:1;
        unsigned int  reserved_1:1;
        unsigned int  extra_pid_addr:7;
}TP1_PCR_CTL;

typedef struct
{
        unsigned int  reserved_0:23;
        unsigned int  latch_ena:1;
        unsigned int  reserved_1:6;
        unsigned int  latch_sel:2;
}TP_PCR_LATCH;

typedef struct
{
        unsigned int  pcr_base_lo:32;
}TP_PCR_BASE;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  pcr_base_hi:1;
        unsigned int  reserved_1:7;
        unsigned int  pcr_ext:9;
}TP_PCR_EXT;

typedef struct
{
        unsigned int  system_ts:32;
}TP_PCR_SYSTEM;

typedef struct
{
        unsigned int  reserved_0:25;
        unsigned int  partition1:7;
}TP_PID_PART;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  r_w:1;
        unsigned int  idx:7;
}TP_PID_CTRL;

typedef struct
{
        unsigned int  si_en:1;
        unsigned int  pid_ini:1;
        unsigned int  ai_en:1;
        unsigned int  ti_en:1;
        unsigned int  sec_idx:6;
        unsigned int  sec_en:1;
        unsigned int  ddr_q_en:1;
        unsigned int  ddr_q:5;
        unsigned int  cc_en:1;
        unsigned int  v:1;
        unsigned int  pid:13;
}TP_PID_DATA;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  info_q_en:1;
        unsigned int  pre_des:1;
        unsigned int  key:5;
        unsigned int  reversed:2;
        unsigned int  info_q:5;
}TP_PID_DATA2;

typedef struct
{
        unsigned int  reserved_0:25;
        unsigned int  r_w:1;
        unsigned int  idx:6;
}TP_SEC_CTRL;

typedef struct
{
        unsigned int  filter_value_msb:32;
}TP_SEC_DATA0;

typedef struct
{
        unsigned int  filter_value_lsb:32;
}TP_SEC_DATA1;

typedef struct
{
        unsigned int  mask_value_msb:32;
}TP_SEC_DATA2;

typedef struct
{
        unsigned int  mask_value_lsb:32;
}TP_SEC_DATA3;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  sp_filter:2;
        unsigned int  sp_mask:2;
        unsigned int  crc_en:1;
        unsigned int  p_d:1;
        unsigned int  p_n:1;
        unsigned int  last:1;
        unsigned int  next_sec:6;
}TP_SEC_DATA4;

typedef struct
{
        unsigned int  neg_filter_value_msb:32;
}TP_SEC_DATA5;

typedef struct
{
        unsigned int  neg_filter_value_lsb:32;
}TP_SEC_DATA6;

typedef struct
{
        unsigned int  neg_mask_value_msb:32;
}TP_SEC_DATA7;

typedef struct
{
        unsigned int  neg_mask_value_lsb:32;
}TP_SEC_DATA8;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  neg_sp_filter:2;
        unsigned int  neg_sp_mask:2;
        unsigned int  reserved_1:8;
        unsigned int  filter_sel:2;
}TP_SEC_DATA9;

typedef struct
{
        unsigned int  reserved_0:12;
        unsigned int  ofb_mode:2;
        unsigned int  csa_mode:2;
        unsigned int  round:8;
        unsigned int  multi2_mode:1;
        unsigned int  map_11:1;
        unsigned int  map_10:1;
        unsigned int  map_01:1;
        unsigned int  des_mode:1;
        unsigned int  mode:3;
}TP_TP0_DES_CNTL;

typedef struct
{
        unsigned int  key_info:32;
}TP_KEY_INFO;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  r_w:1;
        unsigned int  idx:7;
}TP_KEY_CTRL;

typedef struct
{
        unsigned int  reserved_0:12;
        unsigned int  ofb_mode:2;
        unsigned int  csa_mode:2;
        unsigned int  round:8;
        unsigned int  multi2_mode:1;
        unsigned int  map_11:1;
        unsigned int  map_10:1;
        unsigned int  map_01:1;
        unsigned int  des_mode:1;
        unsigned int  mode:3;
}TP_TP1_DES_CNTL;

typedef struct
{
        unsigned int  crc_init:32;
}TP_CRC_INIT;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  threshold:27;
}TP_THRESHOLD;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  fullness:27;
}TP_FULLNESS;

typedef struct
{
        unsigned int  reserved_0:21;
        unsigned int  wm:4;
        unsigned int  r_w:1;
        unsigned int  reserved_1:1;
        unsigned int  idx:5;
}TP_RING_CTRL;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_limit:27;
        unsigned int  reserved_1:3;
}TP_RING_LIMIT;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_base:27;
        unsigned int  reserved_1:3;
}TP_RING_BASE;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_rp:30;
}TP_RING_RP;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_wp:30;
}TP_RING_WP;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  ring_avail_15:1;
        unsigned int  ring_avail_14:1;
        unsigned int  ring_avail_13:1;
        unsigned int  ring_avail_12:1;
        unsigned int  ring_avail_11:1;
        unsigned int  ring_avail_10:1;
        unsigned int  ring_avail_9:1;
        unsigned int  ring_avail_8:1;
        unsigned int  ring_avail_7:1;
        unsigned int  ring_avail_6:1;
        unsigned int  ring_avail_5:1;
        unsigned int  ring_avail_4:1;
        unsigned int  ring_avail_3:1;
        unsigned int  ring_avail_2:1;
        unsigned int  ring_avail_1:1;
        unsigned int  ring_avail_0:1;
        unsigned int  write_data:1;
}TP_RING_AVAIL_INT;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  ring_full_15:1;
        unsigned int  ring_full_14:1;
        unsigned int  ring_full_13:1;
        unsigned int  ring_full_12:1;
        unsigned int  ring_full_11:1;
        unsigned int  ring_full_10:1;
        unsigned int  ring_full_9:1;
        unsigned int  ring_full_8:1;
        unsigned int  ring_full_7:1;
        unsigned int  ring_full_6:1;
        unsigned int  ring_full_5:1;
        unsigned int  ring_full_4:1;
        unsigned int  ring_full_3:1;
        unsigned int  ring_full_2:1;
        unsigned int  ring_full_1:1;
        unsigned int  ring_full_0:1;
        unsigned int  write_data:1;
}TP_RING_FULL_INT;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  ring_avail_15_en:1;
        unsigned int  ring_avail_14_en:1;
        unsigned int  ring_avail_13_en:1;
        unsigned int  ring_avail_12_en:1;
        unsigned int  ring_avail_11_en:1;
        unsigned int  ring_avail_10_en:1;
        unsigned int  ring_avail_9_en:1;
        unsigned int  ring_avail_8_en:1;
        unsigned int  ring_avail_7_en:1;
        unsigned int  ring_avail_6_en:1;
        unsigned int  ring_avail_5_en:1;
        unsigned int  ring_avail_4_en:1;
        unsigned int  ring_avail_3_en:1;
        unsigned int  ring_avail_2_en:1;
        unsigned int  ring_avail_1_en:1;
        unsigned int  ring_avail_0_en:1;
        unsigned int  write_data:1;
}TP_RING_AVAIL_INT_EN;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  ring_full_15_en:1;
        unsigned int  ring_full_14_en:1;
        unsigned int  ring_full_13_en:1;
        unsigned int  ring_full_12_en:1;
        unsigned int  ring_full_11_en:1;
        unsigned int  ring_full_10_en:1;
        unsigned int  ring_full_9_en:1;
        unsigned int  ring_full_8_en:1;
        unsigned int  ring_full_7_en:1;
        unsigned int  ring_full_6_en:1;
        unsigned int  ring_full_5_en:1;
        unsigned int  ring_full_4_en:1;
        unsigned int  ring_full_3_en:1;
        unsigned int  ring_full_2_en:1;
        unsigned int  ring_full_1_en:1;
        unsigned int  ring_full_0_en:1;
        unsigned int  write_data:1;
}TP_RING_FULL_INT_EN;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_limit:27;
        unsigned int  reserved_1:3;
}TP_M2M_RING_LIMIT;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_base:27;
        unsigned int  reserved_1:3;
}TP_M2M_RING_BASE;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_rp:30;
}TP_M2M_RING_RP;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  ring_wp:30;
}TP_M2M_RING_WP;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  empty:1;
        unsigned int  empty_en:1;
        unsigned int  stop:1;
        unsigned int  go:1;
        unsigned int  write_data:1;
}TP_M2M_RING_CTRL;

typedef struct
{
        unsigned int  reserved_0:2;
        unsigned int  sync_pos:30;
}TP_SYNC_POS;

typedef struct
{
        unsigned int  dmy:32;
}TP_DMY_A;

typedef struct
{
        unsigned int  dmy:32;
}TP_DMY_B;

typedef struct
{
        unsigned int  reserved_0:30;
        unsigned int  ls:1;
        unsigned int  bist_mode_tp:1;
}BIST_MODE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_done_tp:1;
}bist_done;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  tp_bist_fail_group_tp:1;
}bist_fail_group;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  tp_bist_dma_fail_0:1;
        unsigned int  tp_bist_ri_sram:1;
        unsigned int  tp_bist_reg_crc_sram_fail_2:1;
        unsigned int  tp_bist_reg_crc_sram_fail_1:1;
        unsigned int  tp_bist_reg_crc_sram_fail_0:1;
}bist_fail;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  drf_mode_tp:1;
}DRF_MODE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  drf_resume_tp:1;
}drf_resume;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  drf_done_tp:1;
}drf_done;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  drf_pause_tp:1;
}drf_pause;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  drf_fail_group_tp:1;
}drf_fail_group;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  tp_drf_dma_fail_0:1;
        unsigned int  tp_drf_ri_sram_fail:1;
        unsigned int  tp_drf_reg_crc_sram_fail_2:1;
        unsigned int  tp_drf_reg_crc_sram_fail_1:1;
        unsigned int  tp_drf_reg_crc_sram_fail_0:1;
}drf_fail;

typedef struct
{
        unsigned int  reserved_0:27;
        unsigned int  tp_dvse_dma0:1;
        unsigned int  tp_dvse_ri_sram:1;
        unsigned int  tp_dvse_reg_crc_sram2:1;
        unsigned int  tp_dvse_reg_crc_sram1:1;
        unsigned int  tp_dvse_reg_crc_sram0:1;
}bist_dvse;

typedef struct
{
        unsigned int  reserved_0:12;
        unsigned int  tp_dvs_dma0:4;
        unsigned int  tp_dvs_ri_sram:4;
        unsigned int  tp_dvs_reg_crc_sram2:4;
        unsigned int  tp_dvs_reg_crc_sram1:4;
        unsigned int  tp_dvs_reg_crc_sram0:4;
}bist_dvs;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_1;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_2;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_3;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_4;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_5;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_6;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_7;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_8;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_9;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_10;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_11;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF0_DETECT_12;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  delay_cnt_status:24;
}TP_TF0_DETECT_13;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  detect_delay:8;
        unsigned int  detect_en:1;
        unsigned int  detect_start:1;
}TP_TF0_DETECT_CTRL;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_1;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_2;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_3;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_4;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_5;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_6;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_7;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_8;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_9;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_10;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_11;

typedef struct
{
        unsigned int  delay_cnt_status:32;
}TP_TF1_DETECT_12;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  delay_cnt_status:24;
}TP_TF1_DETECT_13;

typedef struct
{
        unsigned int  reserved_0:22;
        unsigned int  detect_delay:8;
        unsigned int  detect_en:1;
        unsigned int  detect_start:1;
}TP_TF1_DETECT_CTRL;

typedef struct
{
        unsigned int  dummy180141f8_31_0:32;
}TP_dummy_1;

typedef struct
{
        unsigned int  dummy180141fc_31_0:32;
}TP_dummy_2;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  dv_verify_only:1;
        unsigned int  tp_sram_sleep_off:1;
        unsigned int  tp_pkt_sram_addr_rst_sel:1;
        unsigned int  dbg_mode:5;
}TP_DEBUG;

#define  TP_TF0_CNTL                                                            0x18014000
#define  TP_TF0_CNTL_reg_addr                                                   "0xB8014000"
#define  TP_TF0_CNTL_reg                                                        0xB8014000
#define  TP_TF0_CNTL_inst_addr                                                  "0x0000"
#define  TP_TF0_CNTL_inst                                                       0x0000
#define  TP_TF0_CNTL_rvd_shift                                                  (18)
#define  TP_TF0_CNTL_tp_err_fix_en_shift                                        (17)
#define  TP_TF0_CNTL_strm_id_en_shift                                           (16)
#define  TP_TF0_CNTL_buf_rdy_ctl_shift                                          (15)
#define  TP_TF0_CNTL_psc_en_shift                                               (14)
#define  TP_TF0_CNTL_pes_en_shift                                               (13)
#define  TP_TF0_CNTL_tsc_en_shift                                               (12)
#define  TP_TF0_CNTL_tb_shift                                                   (11)
#define  TP_TF0_CNTL_busy_shift                                                 (10)
#define  TP_TF0_CNTL_mode_shift                                                 (9)
#define  TP_TF0_CNTL_du_en_shift                                                (8)
#define  TP_TF0_CNTL_de_en_shift                                                (7)
#define  TP_TF0_CNTL_xt_en_shift                                                (6)
#define  TP_TF0_CNTL_pid_en_shift                                               (5)
#define  TP_TF0_CNTL_null_en_shift                                              (4)
#define  TP_TF0_CNTL_trerr_en_shift                                             (3)
#define  TP_TF0_CNTL_sync_en_shift                                              (2)
#define  TP_TF0_CNTL_rst_en_shift                                               (1)
#define  TP_TF0_CNTL_write_data_shift                                           (0)
#define  TP_TF0_CNTL_rvd_mask                                                   (0xFFFC0000)
#define  TP_TF0_CNTL_tp_err_fix_en_mask                                         (0x00020000)
#define  TP_TF0_CNTL_strm_id_en_mask                                            (0x00010000)
#define  TP_TF0_CNTL_buf_rdy_ctl_mask                                           (0x00008000)
#define  TP_TF0_CNTL_psc_en_mask                                                (0x00004000)
#define  TP_TF0_CNTL_pes_en_mask                                                (0x00002000)
#define  TP_TF0_CNTL_tsc_en_mask                                                (0x00001000)
#define  TP_TF0_CNTL_tb_mask                                                    (0x00000800)
#define  TP_TF0_CNTL_busy_mask                                                  (0x00000400)
#define  TP_TF0_CNTL_mode_mask                                                  (0x00000200)
#define  TP_TF0_CNTL_du_en_mask                                                 (0x00000100)
#define  TP_TF0_CNTL_de_en_mask                                                 (0x00000080)
#define  TP_TF0_CNTL_xt_en_mask                                                 (0x00000040)
#define  TP_TF0_CNTL_pid_en_mask                                                (0x00000020)
#define  TP_TF0_CNTL_null_en_mask                                               (0x00000010)
#define  TP_TF0_CNTL_trerr_en_mask                                              (0x00000008)
#define  TP_TF0_CNTL_sync_en_mask                                               (0x00000004)
#define  TP_TF0_CNTL_rst_en_mask                                                (0x00000002)
#define  TP_TF0_CNTL_write_data_mask                                            (0x00000001)
#define  TP_TF0_CNTL_rvd(data)                                                  (0xFFFC0000&((data)<<18))
#define  TP_TF0_CNTL_tp_err_fix_en(data)                                        (0x00020000&((data)<<17))
#define  TP_TF0_CNTL_strm_id_en(data)                                           (0x00010000&((data)<<16))
#define  TP_TF0_CNTL_buf_rdy_ctl(data)                                          (0x00008000&((data)<<15))
#define  TP_TF0_CNTL_psc_en(data)                                               (0x00004000&((data)<<14))
#define  TP_TF0_CNTL_pes_en(data)                                               (0x00002000&((data)<<13))
#define  TP_TF0_CNTL_tsc_en(data)                                               (0x00001000&((data)<<12))
#define  TP_TF0_CNTL_tb(data)                                                   (0x00000800&((data)<<11))
#define  TP_TF0_CNTL_busy(data)                                                 (0x00000400&((data)<<10))
#define  TP_TF0_CNTL_mode(data)                                                 (0x00000200&((data)<<9))
#define  TP_TF0_CNTL_du_en(data)                                                (0x00000100&((data)<<8))
#define  TP_TF0_CNTL_de_en(data)                                                (0x00000080&((data)<<7))
#define  TP_TF0_CNTL_xt_en(data)                                                (0x00000040&((data)<<6))
#define  TP_TF0_CNTL_pid_en(data)                                               (0x00000020&((data)<<5))
#define  TP_TF0_CNTL_null_en(data)                                              (0x00000010&((data)<<4))
#define  TP_TF0_CNTL_trerr_en(data)                                             (0x00000008&((data)<<3))
#define  TP_TF0_CNTL_sync_en(data)                                              (0x00000004&((data)<<2))
#define  TP_TF0_CNTL_rst_en(data)                                               (0x00000002&((data)<<1))
#define  TP_TF0_CNTL_write_data(data)                                           (0x00000001&(data))
#define  TP_TF0_CNTL_get_rvd(data)                                              ((0xFFFC0000&(data))>>18)
#define  TP_TF0_CNTL_get_tp_err_fix_en(data)                                    ((0x00020000&(data))>>17)
#define  TP_TF0_CNTL_get_strm_id_en(data)                                       ((0x00010000&(data))>>16)
#define  TP_TF0_CNTL_get_buf_rdy_ctl(data)                                      ((0x00008000&(data))>>15)
#define  TP_TF0_CNTL_get_psc_en(data)                                           ((0x00004000&(data))>>14)
#define  TP_TF0_CNTL_get_pes_en(data)                                           ((0x00002000&(data))>>13)
#define  TP_TF0_CNTL_get_tsc_en(data)                                           ((0x00001000&(data))>>12)
#define  TP_TF0_CNTL_get_tb(data)                                               ((0x00000800&(data))>>11)
#define  TP_TF0_CNTL_get_busy(data)                                             ((0x00000400&(data))>>10)
#define  TP_TF0_CNTL_get_mode(data)                                             ((0x00000200&(data))>>9)
#define  TP_TF0_CNTL_get_du_en(data)                                            ((0x00000100&(data))>>8)
#define  TP_TF0_CNTL_get_de_en(data)                                            ((0x00000080&(data))>>7)
#define  TP_TF0_CNTL_get_xt_en(data)                                            ((0x00000040&(data))>>6)
#define  TP_TF0_CNTL_get_pid_en(data)                                           ((0x00000020&(data))>>5)
#define  TP_TF0_CNTL_get_null_en(data)                                          ((0x00000010&(data))>>4)
#define  TP_TF0_CNTL_get_trerr_en(data)                                         ((0x00000008&(data))>>3)
#define  TP_TF0_CNTL_get_sync_en(data)                                          ((0x00000004&(data))>>2)
#define  TP_TF0_CNTL_get_rst_en(data)                                           ((0x00000002&(data))>>1)
#define  TP_TF0_CNTL_get_write_data(data)                                       (0x00000001&(data))

#define  TP_TF0_STRM_ID_0                                                       0x18014004
#define  TP_TF0_STRM_ID_0_reg_addr                                              "0xB8014004"
#define  TP_TF0_STRM_ID_0_reg                                                   0xB8014004
#define  TP_TF0_STRM_ID_0_inst_addr                                             "0x0001"
#define  TP_TF0_STRM_ID_0_inst                                                  0x0001
#define  TP_TF0_STRM_ID_0_set3_shift                                            (24)
#define  TP_TF0_STRM_ID_0_set2_shift                                            (16)
#define  TP_TF0_STRM_ID_0_set1_shift                                            (8)
#define  TP_TF0_STRM_ID_0_set0_shift                                            (0)
#define  TP_TF0_STRM_ID_0_set3_mask                                             (0xFF000000)
#define  TP_TF0_STRM_ID_0_set2_mask                                             (0x00FF0000)
#define  TP_TF0_STRM_ID_0_set1_mask                                             (0x0000FF00)
#define  TP_TF0_STRM_ID_0_set0_mask                                             (0x000000FF)
#define  TP_TF0_STRM_ID_0_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF0_STRM_ID_0_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF0_STRM_ID_0_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF0_STRM_ID_0_set0(data)                                            (0x000000FF&(data))
#define  TP_TF0_STRM_ID_0_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF0_STRM_ID_0_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF0_STRM_ID_0_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF0_STRM_ID_0_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF0_STRM_ID_1                                                       0x18014008
#define  TP_TF0_STRM_ID_1_reg_addr                                              "0xB8014008"
#define  TP_TF0_STRM_ID_1_reg                                                   0xB8014008
#define  TP_TF0_STRM_ID_1_inst_addr                                             "0x0002"
#define  TP_TF0_STRM_ID_1_inst                                                  0x0002
#define  TP_TF0_STRM_ID_1_set3_shift                                            (24)
#define  TP_TF0_STRM_ID_1_set2_shift                                            (16)
#define  TP_TF0_STRM_ID_1_set1_shift                                            (8)
#define  TP_TF0_STRM_ID_1_set0_shift                                            (0)
#define  TP_TF0_STRM_ID_1_set3_mask                                             (0xFF000000)
#define  TP_TF0_STRM_ID_1_set2_mask                                             (0x00FF0000)
#define  TP_TF0_STRM_ID_1_set1_mask                                             (0x0000FF00)
#define  TP_TF0_STRM_ID_1_set0_mask                                             (0x000000FF)
#define  TP_TF0_STRM_ID_1_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF0_STRM_ID_1_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF0_STRM_ID_1_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF0_STRM_ID_1_set0(data)                                            (0x000000FF&(data))
#define  TP_TF0_STRM_ID_1_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF0_STRM_ID_1_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF0_STRM_ID_1_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF0_STRM_ID_1_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF0_STRM_ID_2                                                       0x1801400C
#define  TP_TF0_STRM_ID_2_reg_addr                                              "0xB801400C"
#define  TP_TF0_STRM_ID_2_reg                                                   0xB801400C
#define  TP_TF0_STRM_ID_2_inst_addr                                             "0x0003"
#define  TP_TF0_STRM_ID_2_inst                                                  0x0003
#define  TP_TF0_STRM_ID_2_set3_shift                                            (24)
#define  TP_TF0_STRM_ID_2_set2_shift                                            (16)
#define  TP_TF0_STRM_ID_2_set1_shift                                            (8)
#define  TP_TF0_STRM_ID_2_set0_shift                                            (0)
#define  TP_TF0_STRM_ID_2_set3_mask                                             (0xFF000000)
#define  TP_TF0_STRM_ID_2_set2_mask                                             (0x00FF0000)
#define  TP_TF0_STRM_ID_2_set1_mask                                             (0x0000FF00)
#define  TP_TF0_STRM_ID_2_set0_mask                                             (0x000000FF)
#define  TP_TF0_STRM_ID_2_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF0_STRM_ID_2_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF0_STRM_ID_2_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF0_STRM_ID_2_set0(data)                                            (0x000000FF&(data))
#define  TP_TF0_STRM_ID_2_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF0_STRM_ID_2_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF0_STRM_ID_2_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF0_STRM_ID_2_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF0_STRM_ID_3                                                       0x18014010
#define  TP_TF0_STRM_ID_3_reg_addr                                              "0xB8014010"
#define  TP_TF0_STRM_ID_3_reg                                                   0xB8014010
#define  TP_TF0_STRM_ID_3_inst_addr                                             "0x0004"
#define  TP_TF0_STRM_ID_3_inst                                                  0x0004
#define  TP_TF0_STRM_ID_3_set3_shift                                            (24)
#define  TP_TF0_STRM_ID_3_set2_shift                                            (16)
#define  TP_TF0_STRM_ID_3_set1_shift                                            (8)
#define  TP_TF0_STRM_ID_3_set0_shift                                            (0)
#define  TP_TF0_STRM_ID_3_set3_mask                                             (0xFF000000)
#define  TP_TF0_STRM_ID_3_set2_mask                                             (0x00FF0000)
#define  TP_TF0_STRM_ID_3_set1_mask                                             (0x0000FF00)
#define  TP_TF0_STRM_ID_3_set0_mask                                             (0x000000FF)
#define  TP_TF0_STRM_ID_3_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF0_STRM_ID_3_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF0_STRM_ID_3_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF0_STRM_ID_3_set0(data)                                            (0x000000FF&(data))
#define  TP_TF0_STRM_ID_3_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF0_STRM_ID_3_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF0_STRM_ID_3_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF0_STRM_ID_3_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF0_STRM_VAL                                                        0x18014014
#define  TP_TF0_STRM_VAL_reg_addr                                               "0xB8014014"
#define  TP_TF0_STRM_VAL_reg                                                    0xB8014014
#define  TP_TF0_STRM_VAL_inst_addr                                              "0x0005"
#define  TP_TF0_STRM_VAL_inst                                                   0x0005
#define  TP_TF0_STRM_VAL_rvd_shift                                              (16)
#define  TP_TF0_STRM_VAL_val_set33_shift                                        (15)
#define  TP_TF0_STRM_VAL_val_set32_shift                                        (14)
#define  TP_TF0_STRM_VAL_val_set31_shift                                        (13)
#define  TP_TF0_STRM_VAL_val_set30_shift                                        (12)
#define  TP_TF0_STRM_VAL_val_set23_shift                                        (11)
#define  TP_TF0_STRM_VAL_val_set22_shift                                        (10)
#define  TP_TF0_STRM_VAL_val_set21_shift                                        (9)
#define  TP_TF0_STRM_VAL_val_set20_shift                                        (8)
#define  TP_TF0_STRM_VAL_val_set13_shift                                        (7)
#define  TP_TF0_STRM_VAL_val_set12_shift                                        (6)
#define  TP_TF0_STRM_VAL_val_set11_shift                                        (5)
#define  TP_TF0_STRM_VAL_val_set10_shift                                        (4)
#define  TP_TF0_STRM_VAL_val_set03_shift                                        (3)
#define  TP_TF0_STRM_VAL_val_set02_shift                                        (2)
#define  TP_TF0_STRM_VAL_val_set01_shift                                        (1)
#define  TP_TF0_STRM_VAL_val_set00_shift                                        (0)
#define  TP_TF0_STRM_VAL_rvd_mask                                               (0xFFFF0000)
#define  TP_TF0_STRM_VAL_val_set33_mask                                         (0x00008000)
#define  TP_TF0_STRM_VAL_val_set32_mask                                         (0x00004000)
#define  TP_TF0_STRM_VAL_val_set31_mask                                         (0x00002000)
#define  TP_TF0_STRM_VAL_val_set30_mask                                         (0x00001000)
#define  TP_TF0_STRM_VAL_val_set23_mask                                         (0x00000800)
#define  TP_TF0_STRM_VAL_val_set22_mask                                         (0x00000400)
#define  TP_TF0_STRM_VAL_val_set21_mask                                         (0x00000200)
#define  TP_TF0_STRM_VAL_val_set20_mask                                         (0x00000100)
#define  TP_TF0_STRM_VAL_val_set13_mask                                         (0x00000080)
#define  TP_TF0_STRM_VAL_val_set12_mask                                         (0x00000040)
#define  TP_TF0_STRM_VAL_val_set11_mask                                         (0x00000020)
#define  TP_TF0_STRM_VAL_val_set10_mask                                         (0x00000010)
#define  TP_TF0_STRM_VAL_val_set03_mask                                         (0x00000008)
#define  TP_TF0_STRM_VAL_val_set02_mask                                         (0x00000004)
#define  TP_TF0_STRM_VAL_val_set01_mask                                         (0x00000002)
#define  TP_TF0_STRM_VAL_val_set00_mask                                         (0x00000001)
#define  TP_TF0_STRM_VAL_rvd(data)                                              (0xFFFF0000&((data)<<16))
#define  TP_TF0_STRM_VAL_val_set33(data)                                        (0x00008000&((data)<<15))
#define  TP_TF0_STRM_VAL_val_set32(data)                                        (0x00004000&((data)<<14))
#define  TP_TF0_STRM_VAL_val_set31(data)                                        (0x00002000&((data)<<13))
#define  TP_TF0_STRM_VAL_val_set30(data)                                        (0x00001000&((data)<<12))
#define  TP_TF0_STRM_VAL_val_set23(data)                                        (0x00000800&((data)<<11))
#define  TP_TF0_STRM_VAL_val_set22(data)                                        (0x00000400&((data)<<10))
#define  TP_TF0_STRM_VAL_val_set21(data)                                        (0x00000200&((data)<<9))
#define  TP_TF0_STRM_VAL_val_set20(data)                                        (0x00000100&((data)<<8))
#define  TP_TF0_STRM_VAL_val_set13(data)                                        (0x00000080&((data)<<7))
#define  TP_TF0_STRM_VAL_val_set12(data)                                        (0x00000040&((data)<<6))
#define  TP_TF0_STRM_VAL_val_set11(data)                                        (0x00000020&((data)<<5))
#define  TP_TF0_STRM_VAL_val_set10(data)                                        (0x00000010&((data)<<4))
#define  TP_TF0_STRM_VAL_val_set03(data)                                        (0x00000008&((data)<<3))
#define  TP_TF0_STRM_VAL_val_set02(data)                                        (0x00000004&((data)<<2))
#define  TP_TF0_STRM_VAL_val_set01(data)                                        (0x00000002&((data)<<1))
#define  TP_TF0_STRM_VAL_val_set00(data)                                        (0x00000001&(data))
#define  TP_TF0_STRM_VAL_get_rvd(data)                                          ((0xFFFF0000&(data))>>16)
#define  TP_TF0_STRM_VAL_get_val_set33(data)                                    ((0x00008000&(data))>>15)
#define  TP_TF0_STRM_VAL_get_val_set32(data)                                    ((0x00004000&(data))>>14)
#define  TP_TF0_STRM_VAL_get_val_set31(data)                                    ((0x00002000&(data))>>13)
#define  TP_TF0_STRM_VAL_get_val_set30(data)                                    ((0x00001000&(data))>>12)
#define  TP_TF0_STRM_VAL_get_val_set23(data)                                    ((0x00000800&(data))>>11)
#define  TP_TF0_STRM_VAL_get_val_set22(data)                                    ((0x00000400&(data))>>10)
#define  TP_TF0_STRM_VAL_get_val_set21(data)                                    ((0x00000200&(data))>>9)
#define  TP_TF0_STRM_VAL_get_val_set20(data)                                    ((0x00000100&(data))>>8)
#define  TP_TF0_STRM_VAL_get_val_set13(data)                                    ((0x00000080&(data))>>7)
#define  TP_TF0_STRM_VAL_get_val_set12(data)                                    ((0x00000040&(data))>>6)
#define  TP_TF0_STRM_VAL_get_val_set11(data)                                    ((0x00000020&(data))>>5)
#define  TP_TF0_STRM_VAL_get_val_set10(data)                                    ((0x00000010&(data))>>4)
#define  TP_TF0_STRM_VAL_get_val_set03(data)                                    ((0x00000008&(data))>>3)
#define  TP_TF0_STRM_VAL_get_val_set02(data)                                    ((0x00000004&(data))>>2)
#define  TP_TF0_STRM_VAL_get_val_set01(data)                                    ((0x00000002&(data))>>1)
#define  TP_TF0_STRM_VAL_get_val_set00(data)                                    (0x00000001&(data))

#define  TP_TF0_CNT                                                             0x18014018
#define  TP_TF0_CNT_reg_addr                                                    "0xB8014018"
#define  TP_TF0_CNT_reg                                                         0xB8014018
#define  TP_TF0_CNT_inst_addr                                                   "0x0006"
#define  TP_TF0_CNT_inst                                                        0x0006
#define  TP_TF0_CNT_rvd_shift                                                   (24)
#define  TP_TF0_CNT_cnt_shift                                                   (0)
#define  TP_TF0_CNT_rvd_mask                                                    (0xFF000000)
#define  TP_TF0_CNT_cnt_mask                                                    (0x00FFFFFF)
#define  TP_TF0_CNT_rvd(data)                                                   (0xFF000000&((data)<<24))
#define  TP_TF0_CNT_cnt(data)                                                   (0x00FFFFFF&(data))
#define  TP_TF0_CNT_get_rvd(data)                                               ((0xFF000000&(data))>>24)
#define  TP_TF0_CNT_get_cnt(data)                                               (0x00FFFFFF&(data))

#define  TP_TF0_DRP_CNT                                                         0x1801401C
#define  TP_TF0_DRP_CNT_reg_addr                                                "0xB801401C"
#define  TP_TF0_DRP_CNT_reg                                                     0xB801401C
#define  TP_TF0_DRP_CNT_inst_addr                                               "0x0007"
#define  TP_TF0_DRP_CNT_inst                                                    0x0007
#define  TP_TF0_DRP_CNT_rvd_shift                                               (16)
#define  TP_TF0_DRP_CNT_drp_cnt_shift                                           (0)
#define  TP_TF0_DRP_CNT_rvd_mask                                                (0xFFFF0000)
#define  TP_TF0_DRP_CNT_drp_cnt_mask                                            (0x0000FFFF)
#define  TP_TF0_DRP_CNT_rvd(data)                                               (0xFFFF0000&((data)<<16))
#define  TP_TF0_DRP_CNT_drp_cnt(data)                                           (0x0000FFFF&(data))
#define  TP_TF0_DRP_CNT_get_rvd(data)                                           ((0xFFFF0000&(data))>>16)
#define  TP_TF0_DRP_CNT_get_drp_cnt(data)                                       (0x0000FFFF&(data))

#define  TP_TF0_ERR_CNT                                                         0x18014020
#define  TP_TF0_ERR_CNT_reg_addr                                                "0xB8014020"
#define  TP_TF0_ERR_CNT_reg                                                     0xB8014020
#define  TP_TF0_ERR_CNT_inst_addr                                               "0x0008"
#define  TP_TF0_ERR_CNT_inst                                                    0x0008
#define  TP_TF0_ERR_CNT_rvd_shift                                               (16)
#define  TP_TF0_ERR_CNT_err_cnt_shift                                           (0)
#define  TP_TF0_ERR_CNT_rvd_mask                                                (0xFFFF0000)
#define  TP_TF0_ERR_CNT_err_cnt_mask                                            (0x0000FFFF)
#define  TP_TF0_ERR_CNT_rvd(data)                                               (0xFFFF0000&((data)<<16))
#define  TP_TF0_ERR_CNT_err_cnt(data)                                           (0x0000FFFF&(data))
#define  TP_TF0_ERR_CNT_get_rvd(data)                                           ((0xFFFF0000&(data))>>16)
#define  TP_TF0_ERR_CNT_get_err_cnt(data)                                       (0x0000FFFF&(data))

#define  TP_TF0_FRMCFG                                                          0x18014024
#define  TP_TF0_FRMCFG_reg_addr                                                 "0xB8014024"
#define  TP_TF0_FRMCFG_reg                                                      0xB8014024
#define  TP_TF0_FRMCFG_inst_addr                                                "0x0009"
#define  TP_TF0_FRMCFG_inst                                                     0x0009
#define  TP_TF0_FRMCFG_sync_byte_shift                                          (24)
#define  TP_TF0_FRMCFG_dropno_shift                                             (20)
#define  TP_TF0_FRMCFG_lockno_shift                                             (16)
#define  TP_TF0_FRMCFG_packet_size_shift                                        (14)
#define  TP_TF0_FRMCFG_data_order_shift                                         (13)
#define  TP_TF0_FRMCFG_frm_en_shift                                             (12)
#define  TP_TF0_FRMCFG_forcedrop_shift                                          (11)
#define  TP_TF0_FRMCFG_syncmode_shift                                           (6)
#define  TP_TF0_FRMCFG_serial_shift                                             (5)
#define  TP_TF0_FRMCFG_datapin_shift                                            (4)
#define  TP_TF0_FRMCFG_err_pol_shift                                            (3)
#define  TP_TF0_FRMCFG_sync_pol_shift                                           (2)
#define  TP_TF0_FRMCFG_val_pol_shift                                            (1)
#define  TP_TF0_FRMCFG_clk_pol_shift                                            (0)
#define  TP_TF0_FRMCFG_sync_byte_mask                                           (0xFF000000)
#define  TP_TF0_FRMCFG_dropno_mask                                              (0x00F00000)
#define  TP_TF0_FRMCFG_lockno_mask                                              (0x000F0000)
#define  TP_TF0_FRMCFG_packet_size_mask                                         (0x0000C000)
#define  TP_TF0_FRMCFG_data_order_mask                                          (0x00002000)
#define  TP_TF0_FRMCFG_frm_en_mask                                              (0x00001000)
#define  TP_TF0_FRMCFG_forcedrop_mask                                           (0x00000800)
#define  TP_TF0_FRMCFG_syncmode_mask                                            (0x000007C0)
#define  TP_TF0_FRMCFG_serial_mask                                              (0x00000020)
#define  TP_TF0_FRMCFG_datapin_mask                                             (0x00000010)
#define  TP_TF0_FRMCFG_err_pol_mask                                             (0x00000008)
#define  TP_TF0_FRMCFG_sync_pol_mask                                            (0x00000004)
#define  TP_TF0_FRMCFG_val_pol_mask                                             (0x00000002)
#define  TP_TF0_FRMCFG_clk_pol_mask                                             (0x00000001)
#define  TP_TF0_FRMCFG_sync_byte(data)                                          (0xFF000000&((data)<<24))
#define  TP_TF0_FRMCFG_dropno(data)                                             (0x00F00000&((data)<<20))
#define  TP_TF0_FRMCFG_lockno(data)                                             (0x000F0000&((data)<<16))
#define  TP_TF0_FRMCFG_packet_size(data)                                        (0x0000C000&((data)<<14))
#define  TP_TF0_FRMCFG_data_order(data)                                         (0x00002000&((data)<<13))
#define  TP_TF0_FRMCFG_frm_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TF0_FRMCFG_forcedrop(data)                                          (0x00000800&((data)<<11))
#define  TP_TF0_FRMCFG_syncmode(data)                                           (0x000007C0&((data)<<6))
#define  TP_TF0_FRMCFG_serial(data)                                             (0x00000020&((data)<<5))
#define  TP_TF0_FRMCFG_datapin(data)                                            (0x00000010&((data)<<4))
#define  TP_TF0_FRMCFG_err_pol(data)                                            (0x00000008&((data)<<3))
#define  TP_TF0_FRMCFG_sync_pol(data)                                           (0x00000004&((data)<<2))
#define  TP_TF0_FRMCFG_val_pol(data)                                            (0x00000002&((data)<<1))
#define  TP_TF0_FRMCFG_clk_pol(data)                                            (0x00000001&(data))
#define  TP_TF0_FRMCFG_get_sync_byte(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TF0_FRMCFG_get_dropno(data)                                         ((0x00F00000&(data))>>20)
#define  TP_TF0_FRMCFG_get_lockno(data)                                         ((0x000F0000&(data))>>16)
#define  TP_TF0_FRMCFG_get_packet_size(data)                                    ((0x0000C000&(data))>>14)
#define  TP_TF0_FRMCFG_get_data_order(data)                                     ((0x00002000&(data))>>13)
#define  TP_TF0_FRMCFG_get_frm_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TF0_FRMCFG_get_forcedrop(data)                                      ((0x00000800&(data))>>11)
#define  TP_TF0_FRMCFG_get_syncmode(data)                                       ((0x000007C0&(data))>>6)
#define  TP_TF0_FRMCFG_get_serial(data)                                         ((0x00000020&(data))>>5)
#define  TP_TF0_FRMCFG_get_datapin(data)                                        ((0x00000010&(data))>>4)
#define  TP_TF0_FRMCFG_get_err_pol(data)                                        ((0x00000008&(data))>>3)
#define  TP_TF0_FRMCFG_get_sync_pol(data)                                       ((0x00000004&(data))>>2)
#define  TP_TF0_FRMCFG_get_val_pol(data)                                        ((0x00000002&(data))>>1)
#define  TP_TF0_FRMCFG_get_clk_pol(data)                                        (0x00000001&(data))

#define  TP_TF0_INT                                                             0x18014028
#define  TP_TF0_INT_reg_addr                                                    "0xB8014028"
#define  TP_TF0_INT_reg                                                         0xB8014028
#define  TP_TF0_INT_inst_addr                                                   "0x000A"
#define  TP_TF0_INT_inst                                                        0x000A
#define  TP_TF0_INT_rvd_shift                                                   (5)
#define  TP_TF0_INT_adf_pcr_in_shift                                            (4)
#define  TP_TF0_INT_overflow_shift                                              (3)
#define  TP_TF0_INT_drop_shift                                                  (2)
#define  TP_TF0_INT_sync_shift                                                  (1)
#define  TP_TF0_INT_write_data_shift                                            (0)
#define  TP_TF0_INT_rvd_mask                                                    (0xFFFFFFE0)
#define  TP_TF0_INT_adf_pcr_in_mask                                             (0x00000010)
#define  TP_TF0_INT_overflow_mask                                               (0x00000008)
#define  TP_TF0_INT_drop_mask                                                   (0x00000004)
#define  TP_TF0_INT_sync_mask                                                   (0x00000002)
#define  TP_TF0_INT_write_data_mask                                             (0x00000001)
#define  TP_TF0_INT_rvd(data)                                                   (0xFFFFFFE0&((data)<<5))
#define  TP_TF0_INT_adf_pcr_in(data)                                            (0x00000010&((data)<<4))
#define  TP_TF0_INT_overflow(data)                                              (0x00000008&((data)<<3))
#define  TP_TF0_INT_drop(data)                                                  (0x00000004&((data)<<2))
#define  TP_TF0_INT_sync(data)                                                  (0x00000002&((data)<<1))
#define  TP_TF0_INT_write_data(data)                                            (0x00000001&(data))
#define  TP_TF0_INT_get_rvd(data)                                               ((0xFFFFFFE0&(data))>>5)
#define  TP_TF0_INT_get_adf_pcr_in(data)                                        ((0x00000010&(data))>>4)
#define  TP_TF0_INT_get_overflow(data)                                          ((0x00000008&(data))>>3)
#define  TP_TF0_INT_get_drop(data)                                              ((0x00000004&(data))>>2)
#define  TP_TF0_INT_get_sync(data)                                              ((0x00000002&(data))>>1)
#define  TP_TF0_INT_get_write_data(data)                                        (0x00000001&(data))

#define  TP_TF0_INT_EN                                                          0x1801402C
#define  TP_TF0_INT_EN_reg_addr                                                 "0xB801402C"
#define  TP_TF0_INT_EN_reg                                                      0xB801402C
#define  TP_TF0_INT_EN_inst_addr                                                "0x000B"
#define  TP_TF0_INT_EN_inst                                                     0x000B
#define  TP_TF0_INT_EN_rvd_shift                                                (5)
#define  TP_TF0_INT_EN_adf_pcr_in_en_shift                                      (4)
#define  TP_TF0_INT_EN_overflow_en_shift                                        (3)
#define  TP_TF0_INT_EN_drop_en_shift                                            (2)
#define  TP_TF0_INT_EN_sync_en_shift                                            (1)
#define  TP_TF0_INT_EN_write_data_shift                                         (0)
#define  TP_TF0_INT_EN_rvd_mask                                                 (0xFFFFFFE0)
#define  TP_TF0_INT_EN_adf_pcr_in_en_mask                                       (0x00000010)
#define  TP_TF0_INT_EN_overflow_en_mask                                         (0x00000008)
#define  TP_TF0_INT_EN_drop_en_mask                                             (0x00000004)
#define  TP_TF0_INT_EN_sync_en_mask                                             (0x00000002)
#define  TP_TF0_INT_EN_write_data_mask                                          (0x00000001)
#define  TP_TF0_INT_EN_rvd(data)                                                (0xFFFFFFE0&((data)<<5))
#define  TP_TF0_INT_EN_adf_pcr_in_en(data)                                      (0x00000010&((data)<<4))
#define  TP_TF0_INT_EN_overflow_en(data)                                        (0x00000008&((data)<<3))
#define  TP_TF0_INT_EN_drop_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TF0_INT_EN_sync_en(data)                                            (0x00000002&((data)<<1))
#define  TP_TF0_INT_EN_write_data(data)                                         (0x00000001&(data))
#define  TP_TF0_INT_EN_get_rvd(data)                                            ((0xFFFFFFE0&(data))>>5)
#define  TP_TF0_INT_EN_get_adf_pcr_in_en(data)                                  ((0x00000010&(data))>>4)
#define  TP_TF0_INT_EN_get_overflow_en(data)                                    ((0x00000008&(data))>>3)
#define  TP_TF0_INT_EN_get_drop_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TF0_INT_EN_get_sync_en(data)                                        ((0x00000002&(data))>>1)
#define  TP_TF0_INT_EN_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TF1_CNTL                                                            0x18014030
#define  TP_TF1_CNTL_reg_addr                                                   "0xB8014030"
#define  TP_TF1_CNTL_reg                                                        0xB8014030
#define  TP_TF1_CNTL_inst_addr                                                  "0x000C"
#define  TP_TF1_CNTL_inst                                                       0x000C
#define  TP_TF1_CNTL_rvd_shift                                                  (18)
#define  TP_TF1_CNTL_tp_err_fix_en_shift                                        (17)
#define  TP_TF1_CNTL_strm_id_en_shift                                           (16)
#define  TP_TF1_CNTL_buf_rdy_ctl_shift                                          (15)
#define  TP_TF1_CNTL_psc_en_shift                                               (14)
#define  TP_TF1_CNTL_pes_en_shift                                               (13)
#define  TP_TF1_CNTL_tsc_en_shift                                               (12)
#define  TP_TF1_CNTL_tb_shift                                                   (11)
#define  TP_TF1_CNTL_busy_shift                                                 (10)
#define  TP_TF1_CNTL_mode_shift                                                 (9)
#define  TP_TF1_CNTL_du_en_shift                                                (8)
#define  TP_TF1_CNTL_de_en_shift                                                (7)
#define  TP_TF1_CNTL_xt_en_shift                                                (6)
#define  TP_TF1_CNTL_pid_en_shift                                               (5)
#define  TP_TF1_CNTL_null_en_shift                                              (4)
#define  TP_TF1_CNTL_trerr_en_shift                                             (3)
#define  TP_TF1_CNTL_sync_en_shift                                              (2)
#define  TP_TF1_CNTL_rst_en_shift                                               (1)
#define  TP_TF1_CNTL_write_data_shift                                           (0)
#define  TP_TF1_CNTL_rvd_mask                                                   (0xFFFC0000)
#define  TP_TF1_CNTL_tp_err_fix_en_mask                                         (0x00020000)
#define  TP_TF1_CNTL_strm_id_en_mask                                            (0x00010000)
#define  TP_TF1_CNTL_buf_rdy_ctl_mask                                           (0x00008000)
#define  TP_TF1_CNTL_psc_en_mask                                                (0x00004000)
#define  TP_TF1_CNTL_pes_en_mask                                                (0x00002000)
#define  TP_TF1_CNTL_tsc_en_mask                                                (0x00001000)
#define  TP_TF1_CNTL_tb_mask                                                    (0x00000800)
#define  TP_TF1_CNTL_busy_mask                                                  (0x00000400)
#define  TP_TF1_CNTL_mode_mask                                                  (0x00000200)
#define  TP_TF1_CNTL_du_en_mask                                                 (0x00000100)
#define  TP_TF1_CNTL_de_en_mask                                                 (0x00000080)
#define  TP_TF1_CNTL_xt_en_mask                                                 (0x00000040)
#define  TP_TF1_CNTL_pid_en_mask                                                (0x00000020)
#define  TP_TF1_CNTL_null_en_mask                                               (0x00000010)
#define  TP_TF1_CNTL_trerr_en_mask                                              (0x00000008)
#define  TP_TF1_CNTL_sync_en_mask                                               (0x00000004)
#define  TP_TF1_CNTL_rst_en_mask                                                (0x00000002)
#define  TP_TF1_CNTL_write_data_mask                                            (0x00000001)
#define  TP_TF1_CNTL_rvd(data)                                                  (0xFFFC0000&((data)<<18))
#define  TP_TF1_CNTL_tp_err_fix_en(data)                                        (0x00020000&((data)<<17))
#define  TP_TF1_CNTL_strm_id_en(data)                                           (0x00010000&((data)<<16))
#define  TP_TF1_CNTL_buf_rdy_ctl(data)                                          (0x00008000&((data)<<15))
#define  TP_TF1_CNTL_psc_en(data)                                               (0x00004000&((data)<<14))
#define  TP_TF1_CNTL_pes_en(data)                                               (0x00002000&((data)<<13))
#define  TP_TF1_CNTL_tsc_en(data)                                               (0x00001000&((data)<<12))
#define  TP_TF1_CNTL_tb(data)                                                   (0x00000800&((data)<<11))
#define  TP_TF1_CNTL_busy(data)                                                 (0x00000400&((data)<<10))
#define  TP_TF1_CNTL_mode(data)                                                 (0x00000200&((data)<<9))
#define  TP_TF1_CNTL_du_en(data)                                                (0x00000100&((data)<<8))
#define  TP_TF1_CNTL_de_en(data)                                                (0x00000080&((data)<<7))
#define  TP_TF1_CNTL_xt_en(data)                                                (0x00000040&((data)<<6))
#define  TP_TF1_CNTL_pid_en(data)                                               (0x00000020&((data)<<5))
#define  TP_TF1_CNTL_null_en(data)                                              (0x00000010&((data)<<4))
#define  TP_TF1_CNTL_trerr_en(data)                                             (0x00000008&((data)<<3))
#define  TP_TF1_CNTL_sync_en(data)                                              (0x00000004&((data)<<2))
#define  TP_TF1_CNTL_rst_en(data)                                               (0x00000002&((data)<<1))
#define  TP_TF1_CNTL_write_data(data)                                           (0x00000001&(data))
#define  TP_TF1_CNTL_get_rvd(data)                                              ((0xFFFC0000&(data))>>18)
#define  TP_TF1_CNTL_get_tp_err_fix_en(data)                                    ((0x00020000&(data))>>17)
#define  TP_TF1_CNTL_get_strm_id_en(data)                                       ((0x00010000&(data))>>16)
#define  TP_TF1_CNTL_get_buf_rdy_ctl(data)                                      ((0x00008000&(data))>>15)
#define  TP_TF1_CNTL_get_psc_en(data)                                           ((0x00004000&(data))>>14)
#define  TP_TF1_CNTL_get_pes_en(data)                                           ((0x00002000&(data))>>13)
#define  TP_TF1_CNTL_get_tsc_en(data)                                           ((0x00001000&(data))>>12)
#define  TP_TF1_CNTL_get_tb(data)                                               ((0x00000800&(data))>>11)
#define  TP_TF1_CNTL_get_busy(data)                                             ((0x00000400&(data))>>10)
#define  TP_TF1_CNTL_get_mode(data)                                             ((0x00000200&(data))>>9)
#define  TP_TF1_CNTL_get_du_en(data)                                            ((0x00000100&(data))>>8)
#define  TP_TF1_CNTL_get_de_en(data)                                            ((0x00000080&(data))>>7)
#define  TP_TF1_CNTL_get_xt_en(data)                                            ((0x00000040&(data))>>6)
#define  TP_TF1_CNTL_get_pid_en(data)                                           ((0x00000020&(data))>>5)
#define  TP_TF1_CNTL_get_null_en(data)                                          ((0x00000010&(data))>>4)
#define  TP_TF1_CNTL_get_trerr_en(data)                                         ((0x00000008&(data))>>3)
#define  TP_TF1_CNTL_get_sync_en(data)                                          ((0x00000004&(data))>>2)
#define  TP_TF1_CNTL_get_rst_en(data)                                           ((0x00000002&(data))>>1)
#define  TP_TF1_CNTL_get_write_data(data)                                       (0x00000001&(data))

#define  TP_TF1_STRM_ID_0                                                       0x18014034
#define  TP_TF1_STRM_ID_0_reg_addr                                              "0xB8014034"
#define  TP_TF1_STRM_ID_0_reg                                                   0xB8014034
#define  TP_TF1_STRM_ID_0_inst_addr                                             "0x000D"
#define  TP_TF1_STRM_ID_0_inst                                                  0x000D
#define  TP_TF1_STRM_ID_0_set3_shift                                            (24)
#define  TP_TF1_STRM_ID_0_set2_shift                                            (16)
#define  TP_TF1_STRM_ID_0_set1_shift                                            (8)
#define  TP_TF1_STRM_ID_0_set0_shift                                            (0)
#define  TP_TF1_STRM_ID_0_set3_mask                                             (0xFF000000)
#define  TP_TF1_STRM_ID_0_set2_mask                                             (0x00FF0000)
#define  TP_TF1_STRM_ID_0_set1_mask                                             (0x0000FF00)
#define  TP_TF1_STRM_ID_0_set0_mask                                             (0x000000FF)
#define  TP_TF1_STRM_ID_0_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF1_STRM_ID_0_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF1_STRM_ID_0_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF1_STRM_ID_0_set0(data)                                            (0x000000FF&(data))
#define  TP_TF1_STRM_ID_0_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF1_STRM_ID_0_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF1_STRM_ID_0_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF1_STRM_ID_0_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF1_STRM_ID_1                                                       0x18014038
#define  TP_TF1_STRM_ID_1_reg_addr                                              "0xB8014038"
#define  TP_TF1_STRM_ID_1_reg                                                   0xB8014038
#define  TP_TF1_STRM_ID_1_inst_addr                                             "0x000E"
#define  TP_TF1_STRM_ID_1_inst                                                  0x000E
#define  TP_TF1_STRM_ID_1_set3_shift                                            (24)
#define  TP_TF1_STRM_ID_1_set2_shift                                            (16)
#define  TP_TF1_STRM_ID_1_set1_shift                                            (8)
#define  TP_TF1_STRM_ID_1_set0_shift                                            (0)
#define  TP_TF1_STRM_ID_1_set3_mask                                             (0xFF000000)
#define  TP_TF1_STRM_ID_1_set2_mask                                             (0x00FF0000)
#define  TP_TF1_STRM_ID_1_set1_mask                                             (0x0000FF00)
#define  TP_TF1_STRM_ID_1_set0_mask                                             (0x000000FF)
#define  TP_TF1_STRM_ID_1_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF1_STRM_ID_1_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF1_STRM_ID_1_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF1_STRM_ID_1_set0(data)                                            (0x000000FF&(data))
#define  TP_TF1_STRM_ID_1_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF1_STRM_ID_1_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF1_STRM_ID_1_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF1_STRM_ID_1_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF1_STRM_ID_2                                                       0x1801403C
#define  TP_TF1_STRM_ID_2_reg_addr                                              "0xB801403C"
#define  TP_TF1_STRM_ID_2_reg                                                   0xB801403C
#define  TP_TF1_STRM_ID_2_inst_addr                                             "0x000F"
#define  TP_TF1_STRM_ID_2_inst                                                  0x000F
#define  TP_TF1_STRM_ID_2_set3_shift                                            (24)
#define  TP_TF1_STRM_ID_2_set2_shift                                            (16)
#define  TP_TF1_STRM_ID_2_set1_shift                                            (8)
#define  TP_TF1_STRM_ID_2_set0_shift                                            (0)
#define  TP_TF1_STRM_ID_2_set3_mask                                             (0xFF000000)
#define  TP_TF1_STRM_ID_2_set2_mask                                             (0x00FF0000)
#define  TP_TF1_STRM_ID_2_set1_mask                                             (0x0000FF00)
#define  TP_TF1_STRM_ID_2_set0_mask                                             (0x000000FF)
#define  TP_TF1_STRM_ID_2_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF1_STRM_ID_2_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF1_STRM_ID_2_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF1_STRM_ID_2_set0(data)                                            (0x000000FF&(data))
#define  TP_TF1_STRM_ID_2_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF1_STRM_ID_2_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF1_STRM_ID_2_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF1_STRM_ID_2_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF1_STRM_ID_3                                                       0x18014040
#define  TP_TF1_STRM_ID_3_reg_addr                                              "0xB8014040"
#define  TP_TF1_STRM_ID_3_reg                                                   0xB8014040
#define  TP_TF1_STRM_ID_3_inst_addr                                             "0x0010"
#define  TP_TF1_STRM_ID_3_inst                                                  0x0010
#define  TP_TF1_STRM_ID_3_set3_shift                                            (24)
#define  TP_TF1_STRM_ID_3_set2_shift                                            (16)
#define  TP_TF1_STRM_ID_3_set1_shift                                            (8)
#define  TP_TF1_STRM_ID_3_set0_shift                                            (0)
#define  TP_TF1_STRM_ID_3_set3_mask                                             (0xFF000000)
#define  TP_TF1_STRM_ID_3_set2_mask                                             (0x00FF0000)
#define  TP_TF1_STRM_ID_3_set1_mask                                             (0x0000FF00)
#define  TP_TF1_STRM_ID_3_set0_mask                                             (0x000000FF)
#define  TP_TF1_STRM_ID_3_set3(data)                                            (0xFF000000&((data)<<24))
#define  TP_TF1_STRM_ID_3_set2(data)                                            (0x00FF0000&((data)<<16))
#define  TP_TF1_STRM_ID_3_set1(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TF1_STRM_ID_3_set0(data)                                            (0x000000FF&(data))
#define  TP_TF1_STRM_ID_3_get_set3(data)                                        ((0xFF000000&(data))>>24)
#define  TP_TF1_STRM_ID_3_get_set2(data)                                        ((0x00FF0000&(data))>>16)
#define  TP_TF1_STRM_ID_3_get_set1(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TF1_STRM_ID_3_get_set0(data)                                        (0x000000FF&(data))

#define  TP_TF1_STRM_VAL                                                        0x18014044
#define  TP_TF1_STRM_VAL_reg_addr                                               "0xB8014044"
#define  TP_TF1_STRM_VAL_reg                                                    0xB8014044
#define  TP_TF1_STRM_VAL_inst_addr                                              "0x0011"
#define  TP_TF1_STRM_VAL_inst                                                   0x0011
#define  TP_TF1_STRM_VAL_rvd_shift                                              (16)
#define  TP_TF1_STRM_VAL_val_set33_shift                                        (15)
#define  TP_TF1_STRM_VAL_val_set32_shift                                        (14)
#define  TP_TF1_STRM_VAL_val_set31_shift                                        (13)
#define  TP_TF1_STRM_VAL_val_set30_shift                                        (12)
#define  TP_TF1_STRM_VAL_val_set23_shift                                        (11)
#define  TP_TF1_STRM_VAL_val_set22_shift                                        (10)
#define  TP_TF1_STRM_VAL_val_set21_shift                                        (9)
#define  TP_TF1_STRM_VAL_val_set20_shift                                        (8)
#define  TP_TF1_STRM_VAL_val_set13_shift                                        (7)
#define  TP_TF1_STRM_VAL_val_set12_shift                                        (6)
#define  TP_TF1_STRM_VAL_val_set11_shift                                        (5)
#define  TP_TF1_STRM_VAL_val_set10_shift                                        (4)
#define  TP_TF1_STRM_VAL_val_set03_shift                                        (3)
#define  TP_TF1_STRM_VAL_val_set02_shift                                        (2)
#define  TP_TF1_STRM_VAL_val_set01_shift                                        (1)
#define  TP_TF1_STRM_VAL_val_set00_shift                                        (0)
#define  TP_TF1_STRM_VAL_rvd_mask                                               (0xFFFF0000)
#define  TP_TF1_STRM_VAL_val_set33_mask                                         (0x00008000)
#define  TP_TF1_STRM_VAL_val_set32_mask                                         (0x00004000)
#define  TP_TF1_STRM_VAL_val_set31_mask                                         (0x00002000)
#define  TP_TF1_STRM_VAL_val_set30_mask                                         (0x00001000)
#define  TP_TF1_STRM_VAL_val_set23_mask                                         (0x00000800)
#define  TP_TF1_STRM_VAL_val_set22_mask                                         (0x00000400)
#define  TP_TF1_STRM_VAL_val_set21_mask                                         (0x00000200)
#define  TP_TF1_STRM_VAL_val_set20_mask                                         (0x00000100)
#define  TP_TF1_STRM_VAL_val_set13_mask                                         (0x00000080)
#define  TP_TF1_STRM_VAL_val_set12_mask                                         (0x00000040)
#define  TP_TF1_STRM_VAL_val_set11_mask                                         (0x00000020)
#define  TP_TF1_STRM_VAL_val_set10_mask                                         (0x00000010)
#define  TP_TF1_STRM_VAL_val_set03_mask                                         (0x00000008)
#define  TP_TF1_STRM_VAL_val_set02_mask                                         (0x00000004)
#define  TP_TF1_STRM_VAL_val_set01_mask                                         (0x00000002)
#define  TP_TF1_STRM_VAL_val_set00_mask                                         (0x00000001)
#define  TP_TF1_STRM_VAL_rvd(data)                                              (0xFFFF0000&((data)<<16))
#define  TP_TF1_STRM_VAL_val_set33(data)                                        (0x00008000&((data)<<15))
#define  TP_TF1_STRM_VAL_val_set32(data)                                        (0x00004000&((data)<<14))
#define  TP_TF1_STRM_VAL_val_set31(data)                                        (0x00002000&((data)<<13))
#define  TP_TF1_STRM_VAL_val_set30(data)                                        (0x00001000&((data)<<12))
#define  TP_TF1_STRM_VAL_val_set23(data)                                        (0x00000800&((data)<<11))
#define  TP_TF1_STRM_VAL_val_set22(data)                                        (0x00000400&((data)<<10))
#define  TP_TF1_STRM_VAL_val_set21(data)                                        (0x00000200&((data)<<9))
#define  TP_TF1_STRM_VAL_val_set20(data)                                        (0x00000100&((data)<<8))
#define  TP_TF1_STRM_VAL_val_set13(data)                                        (0x00000080&((data)<<7))
#define  TP_TF1_STRM_VAL_val_set12(data)                                        (0x00000040&((data)<<6))
#define  TP_TF1_STRM_VAL_val_set11(data)                                        (0x00000020&((data)<<5))
#define  TP_TF1_STRM_VAL_val_set10(data)                                        (0x00000010&((data)<<4))
#define  TP_TF1_STRM_VAL_val_set03(data)                                        (0x00000008&((data)<<3))
#define  TP_TF1_STRM_VAL_val_set02(data)                                        (0x00000004&((data)<<2))
#define  TP_TF1_STRM_VAL_val_set01(data)                                        (0x00000002&((data)<<1))
#define  TP_TF1_STRM_VAL_val_set00(data)                                        (0x00000001&(data))
#define  TP_TF1_STRM_VAL_get_rvd(data)                                          ((0xFFFF0000&(data))>>16)
#define  TP_TF1_STRM_VAL_get_val_set33(data)                                    ((0x00008000&(data))>>15)
#define  TP_TF1_STRM_VAL_get_val_set32(data)                                    ((0x00004000&(data))>>14)
#define  TP_TF1_STRM_VAL_get_val_set31(data)                                    ((0x00002000&(data))>>13)
#define  TP_TF1_STRM_VAL_get_val_set30(data)                                    ((0x00001000&(data))>>12)
#define  TP_TF1_STRM_VAL_get_val_set23(data)                                    ((0x00000800&(data))>>11)
#define  TP_TF1_STRM_VAL_get_val_set22(data)                                    ((0x00000400&(data))>>10)
#define  TP_TF1_STRM_VAL_get_val_set21(data)                                    ((0x00000200&(data))>>9)
#define  TP_TF1_STRM_VAL_get_val_set20(data)                                    ((0x00000100&(data))>>8)
#define  TP_TF1_STRM_VAL_get_val_set13(data)                                    ((0x00000080&(data))>>7)
#define  TP_TF1_STRM_VAL_get_val_set12(data)                                    ((0x00000040&(data))>>6)
#define  TP_TF1_STRM_VAL_get_val_set11(data)                                    ((0x00000020&(data))>>5)
#define  TP_TF1_STRM_VAL_get_val_set10(data)                                    ((0x00000010&(data))>>4)
#define  TP_TF1_STRM_VAL_get_val_set03(data)                                    ((0x00000008&(data))>>3)
#define  TP_TF1_STRM_VAL_get_val_set02(data)                                    ((0x00000004&(data))>>2)
#define  TP_TF1_STRM_VAL_get_val_set01(data)                                    ((0x00000002&(data))>>1)
#define  TP_TF1_STRM_VAL_get_val_set00(data)                                    (0x00000001&(data))

#define  TP_TF1_CNT                                                             0x18014048
#define  TP_TF1_CNT_reg_addr                                                    "0xB8014048"
#define  TP_TF1_CNT_reg                                                         0xB8014048
#define  TP_TF1_CNT_inst_addr                                                   "0x0012"
#define  TP_TF1_CNT_inst                                                        0x0012
#define  TP_TF1_CNT_rvd_shift                                                   (24)
#define  TP_TF1_CNT_cnt_shift                                                   (0)
#define  TP_TF1_CNT_rvd_mask                                                    (0xFF000000)
#define  TP_TF1_CNT_cnt_mask                                                    (0x00FFFFFF)
#define  TP_TF1_CNT_rvd(data)                                                   (0xFF000000&((data)<<24))
#define  TP_TF1_CNT_cnt(data)                                                   (0x00FFFFFF&(data))
#define  TP_TF1_CNT_get_rvd(data)                                               ((0xFF000000&(data))>>24)
#define  TP_TF1_CNT_get_cnt(data)                                               (0x00FFFFFF&(data))

#define  TP_TF1_DRP_CNT                                                         0x1801404C
#define  TP_TF1_DRP_CNT_reg_addr                                                "0xB801404C"
#define  TP_TF1_DRP_CNT_reg                                                     0xB801404C
#define  TP_TF1_DRP_CNT_inst_addr                                               "0x0013"
#define  TP_TF1_DRP_CNT_inst                                                    0x0013
#define  TP_TF1_DRP_CNT_rvd_shift                                               (16)
#define  TP_TF1_DRP_CNT_drp_cnt_shift                                           (0)
#define  TP_TF1_DRP_CNT_rvd_mask                                                (0xFFFF0000)
#define  TP_TF1_DRP_CNT_drp_cnt_mask                                            (0x0000FFFF)
#define  TP_TF1_DRP_CNT_rvd(data)                                               (0xFFFF0000&((data)<<16))
#define  TP_TF1_DRP_CNT_drp_cnt(data)                                           (0x0000FFFF&(data))
#define  TP_TF1_DRP_CNT_get_rvd(data)                                           ((0xFFFF0000&(data))>>16)
#define  TP_TF1_DRP_CNT_get_drp_cnt(data)                                       (0x0000FFFF&(data))

#define  TP_TF1_ERR_CNT                                                         0x18014050
#define  TP_TF1_ERR_CNT_reg_addr                                                "0xB8014050"
#define  TP_TF1_ERR_CNT_reg                                                     0xB8014050
#define  TP_TF1_ERR_CNT_inst_addr                                               "0x0014"
#define  TP_TF1_ERR_CNT_inst                                                    0x0014
#define  TP_TF1_ERR_CNT_rvd_shift                                               (16)
#define  TP_TF1_ERR_CNT_err_cnt_shift                                           (0)
#define  TP_TF1_ERR_CNT_rvd_mask                                                (0xFFFF0000)
#define  TP_TF1_ERR_CNT_err_cnt_mask                                            (0x0000FFFF)
#define  TP_TF1_ERR_CNT_rvd(data)                                               (0xFFFF0000&((data)<<16))
#define  TP_TF1_ERR_CNT_err_cnt(data)                                           (0x0000FFFF&(data))
#define  TP_TF1_ERR_CNT_get_rvd(data)                                           ((0xFFFF0000&(data))>>16)
#define  TP_TF1_ERR_CNT_get_err_cnt(data)                                       (0x0000FFFF&(data))

#define  TP_TF1_FRMCFG                                                          0x18014054
#define  TP_TF1_FRMCFG_reg_addr                                                 "0xB8014054"
#define  TP_TF1_FRMCFG_reg                                                      0xB8014054
#define  TP_TF1_FRMCFG_inst_addr                                                "0x0015"
#define  TP_TF1_FRMCFG_inst                                                     0x0015
#define  TP_TF1_FRMCFG_sync_byte_shift                                          (24)
#define  TP_TF1_FRMCFG_dropno_shift                                             (20)
#define  TP_TF1_FRMCFG_lockno_shift                                             (16)
#define  TP_TF1_FRMCFG_packet_size_shift                                        (14)
#define  TP_TF1_FRMCFG_data_order_shift                                         (13)
#define  TP_TF1_FRMCFG_frm_en_shift                                             (12)
#define  TP_TF1_FRMCFG_forcedrop_shift                                          (11)
#define  TP_TF1_FRMCFG_syncmode_shift                                           (6)
#define  TP_TF1_FRMCFG_serial_shift                                             (5)
#define  TP_TF1_FRMCFG_datapin_shift                                            (4)
#define  TP_TF1_FRMCFG_err_pol_shift                                            (3)
#define  TP_TF1_FRMCFG_sync_pol_shift                                           (2)
#define  TP_TF1_FRMCFG_val_pol_shift                                            (1)
#define  TP_TF1_FRMCFG_clk_pol_shift                                            (0)
#define  TP_TF1_FRMCFG_sync_byte_mask                                           (0xFF000000)
#define  TP_TF1_FRMCFG_dropno_mask                                              (0x00F00000)
#define  TP_TF1_FRMCFG_lockno_mask                                              (0x000F0000)
#define  TP_TF1_FRMCFG_packet_size_mask                                         (0x0000C000)
#define  TP_TF1_FRMCFG_data_order_mask                                          (0x00002000)
#define  TP_TF1_FRMCFG_frm_en_mask                                              (0x00001000)
#define  TP_TF1_FRMCFG_forcedrop_mask                                           (0x00000800)
#define  TP_TF1_FRMCFG_syncmode_mask                                            (0x000007C0)
#define  TP_TF1_FRMCFG_serial_mask                                              (0x00000020)
#define  TP_TF1_FRMCFG_datapin_mask                                             (0x00000010)
#define  TP_TF1_FRMCFG_err_pol_mask                                             (0x00000008)
#define  TP_TF1_FRMCFG_sync_pol_mask                                            (0x00000004)
#define  TP_TF1_FRMCFG_val_pol_mask                                             (0x00000002)
#define  TP_TF1_FRMCFG_clk_pol_mask                                             (0x00000001)
#define  TP_TF1_FRMCFG_sync_byte(data)                                          (0xFF000000&((data)<<24))
#define  TP_TF1_FRMCFG_dropno(data)                                             (0x00F00000&((data)<<20))
#define  TP_TF1_FRMCFG_lockno(data)                                             (0x000F0000&((data)<<16))
#define  TP_TF1_FRMCFG_packet_size(data)                                        (0x0000C000&((data)<<14))
#define  TP_TF1_FRMCFG_data_order(data)                                         (0x00002000&((data)<<13))
#define  TP_TF1_FRMCFG_frm_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TF1_FRMCFG_forcedrop(data)                                          (0x00000800&((data)<<11))
#define  TP_TF1_FRMCFG_syncmode(data)                                           (0x000007C0&((data)<<6))
#define  TP_TF1_FRMCFG_serial(data)                                             (0x00000020&((data)<<5))
#define  TP_TF1_FRMCFG_datapin(data)                                            (0x00000010&((data)<<4))
#define  TP_TF1_FRMCFG_err_pol(data)                                            (0x00000008&((data)<<3))
#define  TP_TF1_FRMCFG_sync_pol(data)                                           (0x00000004&((data)<<2))
#define  TP_TF1_FRMCFG_val_pol(data)                                            (0x00000002&((data)<<1))
#define  TP_TF1_FRMCFG_clk_pol(data)                                            (0x00000001&(data))
#define  TP_TF1_FRMCFG_get_sync_byte(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TF1_FRMCFG_get_dropno(data)                                         ((0x00F00000&(data))>>20)
#define  TP_TF1_FRMCFG_get_lockno(data)                                         ((0x000F0000&(data))>>16)
#define  TP_TF1_FRMCFG_get_packet_size(data)                                    ((0x0000C000&(data))>>14)
#define  TP_TF1_FRMCFG_get_data_order(data)                                     ((0x00002000&(data))>>13)
#define  TP_TF1_FRMCFG_get_frm_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TF1_FRMCFG_get_forcedrop(data)                                      ((0x00000800&(data))>>11)
#define  TP_TF1_FRMCFG_get_syncmode(data)                                       ((0x000007C0&(data))>>6)
#define  TP_TF1_FRMCFG_get_serial(data)                                         ((0x00000020&(data))>>5)
#define  TP_TF1_FRMCFG_get_datapin(data)                                        ((0x00000010&(data))>>4)
#define  TP_TF1_FRMCFG_get_err_pol(data)                                        ((0x00000008&(data))>>3)
#define  TP_TF1_FRMCFG_get_sync_pol(data)                                       ((0x00000004&(data))>>2)
#define  TP_TF1_FRMCFG_get_val_pol(data)                                        ((0x00000002&(data))>>1)
#define  TP_TF1_FRMCFG_get_clk_pol(data)                                        (0x00000001&(data))

#define  TP_TF1_INT                                                             0x18014058
#define  TP_TF1_INT_reg_addr                                                    "0xB8014058"
#define  TP_TF1_INT_reg                                                         0xB8014058
#define  TP_TF1_INT_inst_addr                                                   "0x0016"
#define  TP_TF1_INT_inst                                                        0x0016
#define  TP_TF1_INT_rvd_shift                                                   (5)
#define  TP_TF1_INT_adf_pcr_in_shift                                            (4)
#define  TP_TF1_INT_overflow_shift                                              (3)
#define  TP_TF1_INT_drop_shift                                                  (2)
#define  TP_TF1_INT_sync_shift                                                  (1)
#define  TP_TF1_INT_write_data_shift                                            (0)
#define  TP_TF1_INT_rvd_mask                                                    (0xFFFFFFE0)
#define  TP_TF1_INT_adf_pcr_in_mask                                             (0x00000010)
#define  TP_TF1_INT_overflow_mask                                               (0x00000008)
#define  TP_TF1_INT_drop_mask                                                   (0x00000004)
#define  TP_TF1_INT_sync_mask                                                   (0x00000002)
#define  TP_TF1_INT_write_data_mask                                             (0x00000001)
#define  TP_TF1_INT_rvd(data)                                                   (0xFFFFFFE0&((data)<<5))
#define  TP_TF1_INT_adf_pcr_in(data)                                            (0x00000010&((data)<<4))
#define  TP_TF1_INT_overflow(data)                                              (0x00000008&((data)<<3))
#define  TP_TF1_INT_drop(data)                                                  (0x00000004&((data)<<2))
#define  TP_TF1_INT_sync(data)                                                  (0x00000002&((data)<<1))
#define  TP_TF1_INT_write_data(data)                                            (0x00000001&(data))
#define  TP_TF1_INT_get_rvd(data)                                               ((0xFFFFFFE0&(data))>>5)
#define  TP_TF1_INT_get_adf_pcr_in(data)                                        ((0x00000010&(data))>>4)
#define  TP_TF1_INT_get_overflow(data)                                          ((0x00000008&(data))>>3)
#define  TP_TF1_INT_get_drop(data)                                              ((0x00000004&(data))>>2)
#define  TP_TF1_INT_get_sync(data)                                              ((0x00000002&(data))>>1)
#define  TP_TF1_INT_get_write_data(data)                                        (0x00000001&(data))

#define  TP_TF1_INT_EN                                                          0x1801405C
#define  TP_TF1_INT_EN_reg_addr                                                 "0xB801405C"
#define  TP_TF1_INT_EN_reg                                                      0xB801405C
#define  TP_TF1_INT_EN_inst_addr                                                "0x0017"
#define  TP_TF1_INT_EN_inst                                                     0x0017
#define  TP_TF1_INT_EN_rvd_shift                                                (5)
#define  TP_TF1_INT_EN_adf_pcr_in_en_shift                                      (4)
#define  TP_TF1_INT_EN_overflow_en_shift                                        (3)
#define  TP_TF1_INT_EN_drop_en_shift                                            (2)
#define  TP_TF1_INT_EN_sync_en_shift                                            (1)
#define  TP_TF1_INT_EN_write_data_shift                                         (0)
#define  TP_TF1_INT_EN_rvd_mask                                                 (0xFFFFFFE0)
#define  TP_TF1_INT_EN_adf_pcr_in_en_mask                                       (0x00000010)
#define  TP_TF1_INT_EN_overflow_en_mask                                         (0x00000008)
#define  TP_TF1_INT_EN_drop_en_mask                                             (0x00000004)
#define  TP_TF1_INT_EN_sync_en_mask                                             (0x00000002)
#define  TP_TF1_INT_EN_write_data_mask                                          (0x00000001)
#define  TP_TF1_INT_EN_rvd(data)                                                (0xFFFFFFE0&((data)<<5))
#define  TP_TF1_INT_EN_adf_pcr_in_en(data)                                      (0x00000010&((data)<<4))
#define  TP_TF1_INT_EN_overflow_en(data)                                        (0x00000008&((data)<<3))
#define  TP_TF1_INT_EN_drop_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TF1_INT_EN_sync_en(data)                                            (0x00000002&((data)<<1))
#define  TP_TF1_INT_EN_write_data(data)                                         (0x00000001&(data))
#define  TP_TF1_INT_EN_get_rvd(data)                                            ((0xFFFFFFE0&(data))>>5)
#define  TP_TF1_INT_EN_get_adf_pcr_in_en(data)                                  ((0x00000010&(data))>>4)
#define  TP_TF1_INT_EN_get_overflow_en(data)                                    ((0x00000008&(data))>>3)
#define  TP_TF1_INT_EN_get_drop_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TF1_INT_EN_get_sync_en(data)                                        ((0x00000002&(data))>>1)
#define  TP_TF1_INT_EN_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TF_OUT_FRMCFG                                                       0x18014060
#define  TP_TF_OUT_FRMCFG_reg_addr                                              "0xB8014060"
#define  TP_TF_OUT_FRMCFG_reg                                                   0xB8014060
#define  TP_TF_OUT_FRMCFG_inst_addr                                             "0x0018"
#define  TP_TF_OUT_FRMCFG_inst                                                  0x0018
#define  TP_TF_OUT_FRMCFG_rvd_shift                                             (22)
#define  TP_TF_OUT_FRMCFG_byps_tperr_en_shift                                   (21)
#define  TP_TF_OUT_FRMCFG_tperr_bit_sel_shift                                   (20)
#define  TP_TF_OUT_FRMCFG_in_tp_out_en_shift                                    (19)
#define  TP_TF_OUT_FRMCFG_in_tp_rst_shift                                       (18)
#define  TP_TF_OUT_FRMCFG_data_src_shift                                        (16)
#define  TP_TF_OUT_FRMCFG_rvd_shift                                             (15)
#define  TP_TF_OUT_FRMCFG_in_data_order_shift                                   (14)
#define  TP_TF_OUT_FRMCFG_in_serial_shift                                       (13)
#define  TP_TF_OUT_FRMCFG_in_datapin_shift                                      (12)
#define  TP_TF_OUT_FRMCFG_in_err_pol_shift                                      (11)
#define  TP_TF_OUT_FRMCFG_in_sync_pol_shift                                     (10)
#define  TP_TF_OUT_FRMCFG_in_val_pol_shift                                      (9)
#define  TP_TF_OUT_FRMCFG_in_clk_pol_shift                                      (8)
#define  TP_TF_OUT_FRMCFG_rvd_shift                                             (7)
#define  TP_TF_OUT_FRMCFG_out_data_order_shift                                  (6)
#define  TP_TF_OUT_FRMCFG_out_serial_shift                                      (5)
#define  TP_TF_OUT_FRMCFG_rvd_shift                                             (4)
#define  TP_TF_OUT_FRMCFG_out_err_pol_shift                                     (3)
#define  TP_TF_OUT_FRMCFG_out_sync_pol_shift                                    (2)
#define  TP_TF_OUT_FRMCFG_out_val_pol_shift                                     (1)
#define  TP_TF_OUT_FRMCFG_out_clk_pol_shift                                     (0)
#define  TP_TF_OUT_FRMCFG_rvd_mask                                              (0xFFC00000)
#define  TP_TF_OUT_FRMCFG_byps_tperr_en_mask                                    (0x00200000)
#define  TP_TF_OUT_FRMCFG_tperr_bit_sel_mask                                    (0x00100000)
#define  TP_TF_OUT_FRMCFG_in_tp_out_en_mask                                     (0x00080000)
#define  TP_TF_OUT_FRMCFG_in_tp_rst_mask                                        (0x00040000)
#define  TP_TF_OUT_FRMCFG_data_src_mask                                         (0x00030000)
#define  TP_TF_OUT_FRMCFG_rvd_mask                                              (0x00008000)
#define  TP_TF_OUT_FRMCFG_in_data_order_mask                                    (0x00004000)
#define  TP_TF_OUT_FRMCFG_in_serial_mask                                        (0x00002000)
#define  TP_TF_OUT_FRMCFG_in_datapin_mask                                       (0x00001000)
#define  TP_TF_OUT_FRMCFG_in_err_pol_mask                                       (0x00000800)
#define  TP_TF_OUT_FRMCFG_in_sync_pol_mask                                      (0x00000400)
#define  TP_TF_OUT_FRMCFG_in_val_pol_mask                                       (0x00000200)
#define  TP_TF_OUT_FRMCFG_in_clk_pol_mask                                       (0x00000100)
#define  TP_TF_OUT_FRMCFG_rvd_mask                                              (0x00000080)
#define  TP_TF_OUT_FRMCFG_out_data_order_mask                                   (0x00000040)
#define  TP_TF_OUT_FRMCFG_out_serial_mask                                       (0x00000020)
#define  TP_TF_OUT_FRMCFG_rvd_mask                                              (0x00000010)
#define  TP_TF_OUT_FRMCFG_out_err_pol_mask                                      (0x00000008)
#define  TP_TF_OUT_FRMCFG_out_sync_pol_mask                                     (0x00000004)
#define  TP_TF_OUT_FRMCFG_out_val_pol_mask                                      (0x00000002)
#define  TP_TF_OUT_FRMCFG_out_clk_pol_mask                                      (0x00000001)
#define  TP_TF_OUT_FRMCFG_rvd(data)                                             (0xFFC00000&((data)<<22))
#define  TP_TF_OUT_FRMCFG_byps_tperr_en(data)                                   (0x00200000&((data)<<21))
#define  TP_TF_OUT_FRMCFG_tperr_bit_sel(data)                                   (0x00100000&((data)<<20))
#define  TP_TF_OUT_FRMCFG_in_tp_out_en(data)                                    (0x00080000&((data)<<19))
#define  TP_TF_OUT_FRMCFG_in_tp_rst(data)                                       (0x00040000&((data)<<18))
#define  TP_TF_OUT_FRMCFG_data_src(data)                                        (0x00030000&((data)<<16))
#define  TP_TF_OUT_FRMCFG_rvd(data)                                             (0x00008000&((data)<<15))
#define  TP_TF_OUT_FRMCFG_in_data_order(data)                                   (0x00004000&((data)<<14))
#define  TP_TF_OUT_FRMCFG_in_serial(data)                                       (0x00002000&((data)<<13))
#define  TP_TF_OUT_FRMCFG_in_datapin(data)                                      (0x00001000&((data)<<12))
#define  TP_TF_OUT_FRMCFG_in_err_pol(data)                                      (0x00000800&((data)<<11))
#define  TP_TF_OUT_FRMCFG_in_sync_pol(data)                                     (0x00000400&((data)<<10))
#define  TP_TF_OUT_FRMCFG_in_val_pol(data)                                      (0x00000200&((data)<<9))
#define  TP_TF_OUT_FRMCFG_in_clk_pol(data)                                      (0x00000100&((data)<<8))
#define  TP_TF_OUT_FRMCFG_rvd(data)                                             (0x00000080&((data)<<7))
#define  TP_TF_OUT_FRMCFG_out_data_order(data)                                  (0x00000040&((data)<<6))
#define  TP_TF_OUT_FRMCFG_out_serial(data)                                      (0x00000020&((data)<<5))
#define  TP_TF_OUT_FRMCFG_rvd(data)                                             (0x00000010&((data)<<4))
#define  TP_TF_OUT_FRMCFG_out_err_pol(data)                                     (0x00000008&((data)<<3))
#define  TP_TF_OUT_FRMCFG_out_sync_pol(data)                                    (0x00000004&((data)<<2))
#define  TP_TF_OUT_FRMCFG_out_val_pol(data)                                     (0x00000002&((data)<<1))
#define  TP_TF_OUT_FRMCFG_out_clk_pol(data)                                     (0x00000001&(data))
#define  TP_TF_OUT_FRMCFG_get_rvd(data)                                         ((0xFFC00000&(data))>>22)
#define  TP_TF_OUT_FRMCFG_get_byps_tperr_en(data)                               ((0x00200000&(data))>>21)
#define  TP_TF_OUT_FRMCFG_get_tperr_bit_sel(data)                               ((0x00100000&(data))>>20)
#define  TP_TF_OUT_FRMCFG_get_in_tp_out_en(data)                                ((0x00080000&(data))>>19)
#define  TP_TF_OUT_FRMCFG_get_in_tp_rst(data)                                   ((0x00040000&(data))>>18)
#define  TP_TF_OUT_FRMCFG_get_data_src(data)                                    ((0x00030000&(data))>>16)
#define  TP_TF_OUT_FRMCFG_get_rvd(data)                                         ((0x00008000&(data))>>15)
#define  TP_TF_OUT_FRMCFG_get_in_data_order(data)                               ((0x00004000&(data))>>14)
#define  TP_TF_OUT_FRMCFG_get_in_serial(data)                                   ((0x00002000&(data))>>13)
#define  TP_TF_OUT_FRMCFG_get_in_datapin(data)                                  ((0x00001000&(data))>>12)
#define  TP_TF_OUT_FRMCFG_get_in_err_pol(data)                                  ((0x00000800&(data))>>11)
#define  TP_TF_OUT_FRMCFG_get_in_sync_pol(data)                                 ((0x00000400&(data))>>10)
#define  TP_TF_OUT_FRMCFG_get_in_val_pol(data)                                  ((0x00000200&(data))>>9)
#define  TP_TF_OUT_FRMCFG_get_in_clk_pol(data)                                  ((0x00000100&(data))>>8)
#define  TP_TF_OUT_FRMCFG_get_rvd(data)                                         ((0x00000080&(data))>>7)
#define  TP_TF_OUT_FRMCFG_get_out_data_order(data)                              ((0x00000040&(data))>>6)
#define  TP_TF_OUT_FRMCFG_get_out_serial(data)                                  ((0x00000020&(data))>>5)
#define  TP_TF_OUT_FRMCFG_get_rvd(data)                                         ((0x00000010&(data))>>4)
#define  TP_TF_OUT_FRMCFG_get_out_err_pol(data)                                 ((0x00000008&(data))>>3)
#define  TP_TF_OUT_FRMCFG_get_out_sync_pol(data)                                ((0x00000004&(data))>>2)
#define  TP_TF_OUT_FRMCFG_get_out_val_pol(data)                                 ((0x00000002&(data))>>1)
#define  TP_TF_OUT_FRMCFG_get_out_clk_pol(data)                                 (0x00000001&(data))

#define  TP_OUT_CTRL                                                            0x18014064
#define  TP_OUT_CTRL_reg_addr                                                   "0xB8014064"
#define  TP_OUT_CTRL_reg                                                        0xB8014064
#define  TP_OUT_CTRL_inst_addr                                                  "0x0019"
#define  TP_OUT_CTRL_inst                                                       0x0019
#define  TP_OUT_CTRL_rvd_shift                                                  (20)
#define  TP_OUT_CTRL_sync_dur_shift                                             (19)
#define  TP_OUT_CTRL_ck_gate_shift                                              (18)
#define  TP_OUT_CTRL_tp_frame_rate_shift                                        (5)
#define  TP_OUT_CTRL_tp_clk_div_shift                                           (0)
#define  TP_OUT_CTRL_rvd_mask                                                   (0xFFF00000)
#define  TP_OUT_CTRL_sync_dur_mask                                              (0x00080000)
#define  TP_OUT_CTRL_ck_gate_mask                                               (0x00040000)
#define  TP_OUT_CTRL_tp_frame_rate_mask                                         (0x0003FFE0)
#define  TP_OUT_CTRL_tp_clk_div_mask                                            (0x0000001F)
#define  TP_OUT_CTRL_rvd(data)                                                  (0xFFF00000&((data)<<20))
#define  TP_OUT_CTRL_sync_dur(data)                                             (0x00080000&((data)<<19))
#define  TP_OUT_CTRL_ck_gate(data)                                              (0x00040000&((data)<<18))
#define  TP_OUT_CTRL_tp_frame_rate(data)                                        (0x0003FFE0&((data)<<5))
#define  TP_OUT_CTRL_tp_clk_div(data)                                           (0x0000001F&(data))
#define  TP_OUT_CTRL_get_rvd(data)                                              ((0xFFF00000&(data))>>20)
#define  TP_OUT_CTRL_get_sync_dur(data)                                         ((0x00080000&(data))>>19)
#define  TP_OUT_CTRL_get_ck_gate(data)                                          ((0x00040000&(data))>>18)
#define  TP_OUT_CTRL_get_tp_frame_rate(data)                                    ((0x0003FFE0&(data))>>5)
#define  TP_OUT_CTRL_get_tp_clk_div(data)                                       (0x0000001F&(data))

#define  TP_TF2_CNTL                                                            0x18014068
#define  TP_TF2_CNTL_reg_addr                                                   "0xB8014068"
#define  TP_TF2_CNTL_reg                                                        0xB8014068
#define  TP_TF2_CNTL_inst_addr                                                  "0x001A"
#define  TP_TF2_CNTL_inst                                                       0x001A
#define  TP_TF2_CNTL_rvd_shift                                                  (2)
#define  TP_TF2_CNTL_tp_err_fix_en_shift                                        (1)
#define  TP_TF2_CNTL_write_data_shift                                           (0)
#define  TP_TF2_CNTL_rvd_mask                                                   (0xFFFFFFFC)
#define  TP_TF2_CNTL_tp_err_fix_en_mask                                         (0x00000002)
#define  TP_TF2_CNTL_write_data_mask                                            (0x00000001)
#define  TP_TF2_CNTL_rvd(data)                                                  (0xFFFFFFFC&((data)<<2))
#define  TP_TF2_CNTL_tp_err_fix_en(data)                                        (0x00000002&((data)<<1))
#define  TP_TF2_CNTL_write_data(data)                                           (0x00000001&(data))
#define  TP_TF2_CNTL_get_rvd(data)                                              ((0xFFFFFFFC&(data))>>2)
#define  TP_TF2_CNTL_get_tp_err_fix_en(data)                                    ((0x00000002&(data))>>1)
#define  TP_TF2_CNTL_get_write_data(data)                                       (0x00000001&(data))

#define  TP_TF2_FRMCFG                                                          0x180140CC
#define  TP_TF2_FRMCFG_reg_addr                                                 "0xB80140CC"
#define  TP_TF2_FRMCFG_reg                                                      0xB80140CC
#define  TP_TF2_FRMCFG_inst_addr                                                "0x001B"
#define  TP_TF2_FRMCFG_inst                                                     0x001B
#define  TP_TF2_FRMCFG_rvd_shift                                                (11)
#define  TP_TF2_FRMCFG_syncmode_shift                                           (6)
#define  TP_TF2_FRMCFG_rvd_shift                                                (0)
#define  TP_TF2_FRMCFG_rvd_mask                                                 (0xFFFFF800)
#define  TP_TF2_FRMCFG_syncmode_mask                                            (0x000007C0)
#define  TP_TF2_FRMCFG_rvd_mask                                                 (0x0000003F)
#define  TP_TF2_FRMCFG_rvd(data)                                                (0xFFFFF800&((data)<<11))
#define  TP_TF2_FRMCFG_syncmode(data)                                           (0x000007C0&((data)<<6))
#define  TP_TF2_FRMCFG_rvd(data)                                                (0x0000003F&(data))
#define  TP_TF2_FRMCFG_get_rvd(data)                                            ((0xFFFFF800&(data))>>11)
#define  TP_TF2_FRMCFG_get_syncmode(data)                                       ((0x000007C0&(data))>>6)
#define  TP_TF2_FRMCFG_get_rvd(data)                                            (0x0000003F&(data))

#define  TP_PCR_90K_CNT_HIGH                                                    0x1801406C
#define  TP_PCR_90K_CNT_HIGH_reg_addr                                           "0xB801406C"
#define  TP_PCR_90K_CNT_HIGH_reg                                                0xB801406C
#define  TP_PCR_90K_CNT_HIGH_inst_addr                                          "0x001C"
#define  TP_PCR_90K_CNT_HIGH_inst                                               0x001C
#define  TP_PCR_90K_CNT_HIGH_pcr_90k_cnt_high_shift                             (0)
#define  TP_PCR_90K_CNT_HIGH_pcr_90k_cnt_high_mask                              (0xFFFFFFFF)
#define  TP_PCR_90K_CNT_HIGH_pcr_90k_cnt_high(data)                             (0xFFFFFFFF&(data))
#define  TP_PCR_90K_CNT_HIGH_get_pcr_90k_cnt_high(data)                         (0xFFFFFFFF&(data))

#define  TP_PCR_90K_CNT                                                         0x18014070
#define  TP_PCR_90K_CNT_reg_addr                                                "0xB8014070"
#define  TP_PCR_90K_CNT_reg                                                     0xB8014070
#define  TP_PCR_90K_CNT_inst_addr                                               "0x001D"
#define  TP_PCR_90K_CNT_inst                                                    0x001D
#define  TP_PCR_90K_CNT_pcr_90k_cnt_shift                                       (0)
#define  TP_PCR_90K_CNT_pcr_90k_cnt_mask                                        (0xFFFFFFFF)
#define  TP_PCR_90K_CNT_pcr_90k_cnt(data)                                       (0xFFFFFFFF&(data))
#define  TP_PCR_90K_CNT_get_pcr_90k_cnt(data)                                   (0xFFFFFFFF&(data))

#define  TP0_PCR_CTL                                                            0x18014074
#define  TP0_PCR_CTL_reg_addr                                                   "0xB8014074"
#define  TP0_PCR_CTL_reg                                                        0xB8014074
#define  TP0_PCR_CTL_inst_addr                                                  "0x001E"
#define  TP0_PCR_CTL_inst                                                       0x001E
#define  TP0_PCR_CTL_rvd_shift                                                  (11)
#define  TP0_PCR_CTL_stc_cnt_sel_shift                                          (10)
#define  TP0_PCR_CTL_stc_64bit_en_shift                                         (9)
#define  TP0_PCR_CTL_extra_func_ena_shift                                       (8)
#define  TP0_PCR_CTL_rvd_shift                                                  (7)
#define  TP0_PCR_CTL_extra_pid_addr_shift                                       (0)
#define  TP0_PCR_CTL_rvd_mask                                                   (0xFFFFF800)
#define  TP0_PCR_CTL_stc_cnt_sel_mask                                           (0x00000400)
#define  TP0_PCR_CTL_stc_64bit_en_mask                                          (0x00000200)
#define  TP0_PCR_CTL_extra_func_ena_mask                                        (0x00000100)
#define  TP0_PCR_CTL_rvd_mask                                                   (0x00000080)
#define  TP0_PCR_CTL_extra_pid_addr_mask                                        (0x0000007F)
#define  TP0_PCR_CTL_rvd(data)                                                  (0xFFFFF800&((data)<<11))
#define  TP0_PCR_CTL_stc_cnt_sel(data)                                          (0x00000400&((data)<<10))
#define  TP0_PCR_CTL_stc_64bit_en(data)                                         (0x00000200&((data)<<9))
#define  TP0_PCR_CTL_extra_func_ena(data)                                       (0x00000100&((data)<<8))
#define  TP0_PCR_CTL_rvd(data)                                                  (0x00000080&((data)<<7))
#define  TP0_PCR_CTL_extra_pid_addr(data)                                       (0x0000007F&(data))
#define  TP0_PCR_CTL_get_rvd(data)                                              ((0xFFFFF800&(data))>>11)
#define  TP0_PCR_CTL_get_stc_cnt_sel(data)                                      ((0x00000400&(data))>>10)
#define  TP0_PCR_CTL_get_stc_64bit_en(data)                                     ((0x00000200&(data))>>9)
#define  TP0_PCR_CTL_get_extra_func_ena(data)                                   ((0x00000100&(data))>>8)
#define  TP0_PCR_CTL_get_rvd(data)                                              ((0x00000080&(data))>>7)
#define  TP0_PCR_CTL_get_extra_pid_addr(data)                                   (0x0000007F&(data))

#define  TP1_PCR_CTL                                                            0x18014078
#define  TP1_PCR_CTL_reg_addr                                                   "0xB8014078"
#define  TP1_PCR_CTL_reg                                                        0xB8014078
#define  TP1_PCR_CTL_inst_addr                                                  "0x001F"
#define  TP1_PCR_CTL_inst                                                       0x001F
#define  TP1_PCR_CTL_rvd_shift                                                  (9)
#define  TP1_PCR_CTL_extra_func_ena_shift                                       (8)
#define  TP1_PCR_CTL_rvd_shift                                                  (7)
#define  TP1_PCR_CTL_extra_pid_addr_shift                                       (0)
#define  TP1_PCR_CTL_rvd_mask                                                   (0xFFFFFE00)
#define  TP1_PCR_CTL_extra_func_ena_mask                                        (0x00000100)
#define  TP1_PCR_CTL_rvd_mask                                                   (0x00000080)
#define  TP1_PCR_CTL_extra_pid_addr_mask                                        (0x0000007F)
#define  TP1_PCR_CTL_rvd(data)                                                  (0xFFFFFE00&((data)<<9))
#define  TP1_PCR_CTL_extra_func_ena(data)                                       (0x00000100&((data)<<8))
#define  TP1_PCR_CTL_rvd(data)                                                  (0x00000080&((data)<<7))
#define  TP1_PCR_CTL_extra_pid_addr(data)                                       (0x0000007F&(data))
#define  TP1_PCR_CTL_get_rvd(data)                                              ((0xFFFFFE00&(data))>>9)
#define  TP1_PCR_CTL_get_extra_func_ena(data)                                   ((0x00000100&(data))>>8)
#define  TP1_PCR_CTL_get_rvd(data)                                              ((0x00000080&(data))>>7)
#define  TP1_PCR_CTL_get_extra_pid_addr(data)                                   (0x0000007F&(data))

#define  TP_PCR_LATCH                                                           0x1801407C
#define  TP_PCR_LATCH_reg_addr                                                  "0xB801407C"
#define  TP_PCR_LATCH_reg                                                       0xB801407C
#define  TP_PCR_LATCH_inst_addr                                                 "0x0020"
#define  TP_PCR_LATCH_inst                                                      0x0020
#define  TP_PCR_LATCH_rvd_shift                                                 (9)
#define  TP_PCR_LATCH_latch_ena_shift                                           (8)
#define  TP_PCR_LATCH_rvd_shift                                                 (2)
#define  TP_PCR_LATCH_latch_sel_shift                                           (0)
#define  TP_PCR_LATCH_rvd_mask                                                  (0xFFFFFE00)
#define  TP_PCR_LATCH_latch_ena_mask                                            (0x00000100)
#define  TP_PCR_LATCH_rvd_mask                                                  (0x000000FC)
#define  TP_PCR_LATCH_latch_sel_mask                                            (0x00000003)
#define  TP_PCR_LATCH_rvd(data)                                                 (0xFFFFFE00&((data)<<9))
#define  TP_PCR_LATCH_latch_ena(data)                                           (0x00000100&((data)<<8))
#define  TP_PCR_LATCH_rvd(data)                                                 (0x000000FC&((data)<<2))
#define  TP_PCR_LATCH_latch_sel(data)                                           (0x00000003&(data))
#define  TP_PCR_LATCH_get_rvd(data)                                             ((0xFFFFFE00&(data))>>9)
#define  TP_PCR_LATCH_get_latch_ena(data)                                       ((0x00000100&(data))>>8)
#define  TP_PCR_LATCH_get_rvd(data)                                             ((0x000000FC&(data))>>2)
#define  TP_PCR_LATCH_get_latch_sel(data)                                       (0x00000003&(data))

#define  TP_PCR_BASE                                                            0x18014080
#define  TP_PCR_BASE_reg_addr                                                   "0xB8014080"
#define  TP_PCR_BASE_reg                                                        0xB8014080
#define  TP_PCR_BASE_inst_addr                                                  "0x0021"
#define  TP_PCR_BASE_inst                                                       0x0021
#define  TP_PCR_BASE_pcr_base_lo_shift                                          (0)
#define  TP_PCR_BASE_pcr_base_lo_mask                                           (0xFFFFFFFF)
#define  TP_PCR_BASE_pcr_base_lo(data)                                          (0xFFFFFFFF&(data))
#define  TP_PCR_BASE_get_pcr_base_lo(data)                                      (0xFFFFFFFF&(data))

#define  TP_PCR_EXT                                                             0x18014084
#define  TP_PCR_EXT_reg_addr                                                    "0xB8014084"
#define  TP_PCR_EXT_reg                                                         0xB8014084
#define  TP_PCR_EXT_inst_addr                                                   "0x0022"
#define  TP_PCR_EXT_inst                                                        0x0022
#define  TP_PCR_EXT_rvd_shift                                                   (17)
#define  TP_PCR_EXT_pcr_base_hi_shift                                           (16)
#define  TP_PCR_EXT_rvd_shift                                                   (9)
#define  TP_PCR_EXT_pcr_ext_shift                                               (0)
#define  TP_PCR_EXT_rvd_mask                                                    (0xFFFE0000)
#define  TP_PCR_EXT_pcr_base_hi_mask                                            (0x00010000)
#define  TP_PCR_EXT_rvd_mask                                                    (0x0000FE00)
#define  TP_PCR_EXT_pcr_ext_mask                                                (0x000001FF)
#define  TP_PCR_EXT_rvd(data)                                                   (0xFFFE0000&((data)<<17))
#define  TP_PCR_EXT_pcr_base_hi(data)                                           (0x00010000&((data)<<16))
#define  TP_PCR_EXT_rvd(data)                                                   (0x0000FE00&((data)<<9))
#define  TP_PCR_EXT_pcr_ext(data)                                               (0x000001FF&(data))
#define  TP_PCR_EXT_get_rvd(data)                                               ((0xFFFE0000&(data))>>17)
#define  TP_PCR_EXT_get_pcr_base_hi(data)                                       ((0x00010000&(data))>>16)
#define  TP_PCR_EXT_get_rvd(data)                                               ((0x0000FE00&(data))>>9)
#define  TP_PCR_EXT_get_pcr_ext(data)                                           (0x000001FF&(data))

#define  TP_PCR_SYSTEM                                                          0x18014088
#define  TP_PCR_SYSTEM_reg_addr                                                 "0xB8014088"
#define  TP_PCR_SYSTEM_reg                                                      0xB8014088
#define  TP_PCR_SYSTEM_inst_addr                                                "0x0023"
#define  TP_PCR_SYSTEM_inst                                                     0x0023
#define  TP_PCR_SYSTEM_system_ts_shift                                          (0)
#define  TP_PCR_SYSTEM_system_ts_mask                                           (0xFFFFFFFF)
#define  TP_PCR_SYSTEM_system_ts(data)                                          (0xFFFFFFFF&(data))
#define  TP_PCR_SYSTEM_get_system_ts(data)                                      (0xFFFFFFFF&(data))

#define  TP_PID_PART                                                            0x18014090
#define  TP_PID_PART_reg_addr                                                   "0xB8014090"
#define  TP_PID_PART_reg                                                        0xB8014090
#define  TP_PID_PART_inst_addr                                                  "0x0024"
#define  TP_PID_PART_inst                                                       0x0024
#define  TP_PID_PART_rvd_shift                                                  (7)
#define  TP_PID_PART_partition1_shift                                           (0)
#define  TP_PID_PART_rvd_mask                                                   (0xFFFFFF80)
#define  TP_PID_PART_partition1_mask                                            (0x0000007F)
#define  TP_PID_PART_rvd(data)                                                  (0xFFFFFF80&((data)<<7))
#define  TP_PID_PART_partition1(data)                                           (0x0000007F&(data))
#define  TP_PID_PART_get_rvd(data)                                              ((0xFFFFFF80&(data))>>7)
#define  TP_PID_PART_get_partition1(data)                                       (0x0000007F&(data))

#define  TP_PID_CTRL                                                            0x18014094
#define  TP_PID_CTRL_reg_addr                                                   "0xB8014094"
#define  TP_PID_CTRL_reg                                                        0xB8014094
#define  TP_PID_CTRL_inst_addr                                                  "0x0025"
#define  TP_PID_CTRL_inst                                                       0x0025
#define  TP_PID_CTRL_rvd_shift                                                  (8)
#define  TP_PID_CTRL_r_w_shift                                                  (7)
#define  TP_PID_CTRL_idx_shift                                                  (0)
#define  TP_PID_CTRL_rvd_mask                                                   (0xFFFFFF00)
#define  TP_PID_CTRL_r_w_mask                                                   (0x00000080)
#define  TP_PID_CTRL_idx_mask                                                   (0x0000007F)
#define  TP_PID_CTRL_rvd(data)                                                  (0xFFFFFF00&((data)<<8))
#define  TP_PID_CTRL_r_w(data)                                                  (0x00000080&((data)<<7))
#define  TP_PID_CTRL_idx(data)                                                  (0x0000007F&(data))
#define  TP_PID_CTRL_get_rvd(data)                                              ((0xFFFFFF00&(data))>>8)
#define  TP_PID_CTRL_get_r_w(data)                                              ((0x00000080&(data))>>7)
#define  TP_PID_CTRL_get_idx(data)                                              (0x0000007F&(data))

#define  TP_PID_DATA                                                            0x18014098
#define  TP_PID_DATA_reg_addr                                                   "0xB8014098"
#define  TP_PID_DATA_reg                                                        0xB8014098
#define  TP_PID_DATA_inst_addr                                                  "0x0026"
#define  TP_PID_DATA_inst                                                       0x0026
#define  TP_PID_DATA_si_en_shift                                                (31)
#define  TP_PID_DATA_pid_ini_shift                                              (30)
#define  TP_PID_DATA_ai_en_shift                                                (29)
#define  TP_PID_DATA_ti_en_shift                                                (28)
#define  TP_PID_DATA_sec_idx_shift                                              (22)
#define  TP_PID_DATA_sec_en_shift                                               (21)
#define  TP_PID_DATA_ddr_q_en_shift                                             (20)
#define  TP_PID_DATA_ddr_q_shift                                                (15)
#define  TP_PID_DATA_cc_en_shift                                                (14)
#define  TP_PID_DATA_v_shift                                                    (13)
#define  TP_PID_DATA_pid_shift                                                  (0)
#define  TP_PID_DATA_si_en_mask                                                 (0x80000000)
#define  TP_PID_DATA_pid_ini_mask                                               (0x40000000)
#define  TP_PID_DATA_ai_en_mask                                                 (0x20000000)
#define  TP_PID_DATA_ti_en_mask                                                 (0x10000000)
#define  TP_PID_DATA_sec_idx_mask                                               (0x0FC00000)
#define  TP_PID_DATA_sec_en_mask                                                (0x00200000)
#define  TP_PID_DATA_ddr_q_en_mask                                              (0x00100000)
#define  TP_PID_DATA_ddr_q_mask                                                 (0x000F8000)
#define  TP_PID_DATA_cc_en_mask                                                 (0x00004000)
#define  TP_PID_DATA_v_mask                                                     (0x00002000)
#define  TP_PID_DATA_pid_mask                                                   (0x00001FFF)
#define  TP_PID_DATA_si_en(data)                                                (0x80000000&((data)<<31))
#define  TP_PID_DATA_pid_ini(data)                                              (0x40000000&((data)<<30))
#define  TP_PID_DATA_ai_en(data)                                                (0x20000000&((data)<<29))
#define  TP_PID_DATA_ti_en(data)                                                (0x10000000&((data)<<28))
#define  TP_PID_DATA_sec_idx(data)                                              (0x0FC00000&((data)<<22))
#define  TP_PID_DATA_sec_en(data)                                               (0x00200000&((data)<<21))
#define  TP_PID_DATA_ddr_q_en(data)                                             (0x00100000&((data)<<20))
#define  TP_PID_DATA_ddr_q(data)                                                (0x000F8000&((data)<<15))
#define  TP_PID_DATA_cc_en(data)                                                (0x00004000&((data)<<14))
#define  TP_PID_DATA_v(data)                                                    (0x00002000&((data)<<13))
#define  TP_PID_DATA_pid(data)                                                  (0x00001FFF&(data))
#define  TP_PID_DATA_get_si_en(data)                                            ((0x80000000&(data))>>31)
#define  TP_PID_DATA_get_pid_ini(data)                                          ((0x40000000&(data))>>30)
#define  TP_PID_DATA_get_ai_en(data)                                            ((0x20000000&(data))>>29)
#define  TP_PID_DATA_get_ti_en(data)                                            ((0x10000000&(data))>>28)
#define  TP_PID_DATA_get_sec_idx(data)                                          ((0x0FC00000&(data))>>22)
#define  TP_PID_DATA_get_sec_en(data)                                           ((0x00200000&(data))>>21)
#define  TP_PID_DATA_get_ddr_q_en(data)                                         ((0x00100000&(data))>>20)
#define  TP_PID_DATA_get_ddr_q(data)                                            ((0x000F8000&(data))>>15)
#define  TP_PID_DATA_get_cc_en(data)                                            ((0x00004000&(data))>>14)
#define  TP_PID_DATA_get_v(data)                                                ((0x00002000&(data))>>13)
#define  TP_PID_DATA_get_pid(data)                                              (0x00001FFF&(data))

#define  TP_PID_DATA2                                                           0x1801409C
#define  TP_PID_DATA2_reg_addr                                                  "0xB801409C"
#define  TP_PID_DATA2_reg                                                       0xB801409C
#define  TP_PID_DATA2_inst_addr                                                 "0x0027"
#define  TP_PID_DATA2_inst                                                      0x0027
#define  TP_PID_DATA2_rvd_shift                                                 (14)
#define  TP_PID_DATA2_info_q_en_shift                                           (13)
#define  TP_PID_DATA2_pre_des_shift                                             (12)
#define  TP_PID_DATA2_key_shift                                                 (7)
#define  TP_PID_DATA2_reversed_shift                                            (5)
#define  TP_PID_DATA2_info_q_shift                                              (0)
#define  TP_PID_DATA2_rvd_mask                                                  (0xFFFFC000)
#define  TP_PID_DATA2_info_q_en_mask                                            (0x00002000)
#define  TP_PID_DATA2_pre_des_mask                                              (0x00001000)
#define  TP_PID_DATA2_key_mask                                                  (0x00000F80)
#define  TP_PID_DATA2_reversed_mask                                             (0x00000060)
#define  TP_PID_DATA2_info_q_mask                                               (0x0000001F)
#define  TP_PID_DATA2_rvd(data)                                                 (0xFFFFC000&((data)<<14))
#define  TP_PID_DATA2_info_q_en(data)                                           (0x00002000&((data)<<13))
#define  TP_PID_DATA2_pre_des(data)                                             (0x00001000&((data)<<12))
#define  TP_PID_DATA2_key(data)                                                 (0x00000F80&((data)<<7))
#define  TP_PID_DATA2_reversed(data)                                            (0x00000060&((data)<<5))
#define  TP_PID_DATA2_info_q(data)                                              (0x0000001F&(data))
#define  TP_PID_DATA2_get_rvd(data)                                             ((0xFFFFC000&(data))>>14)
#define  TP_PID_DATA2_get_info_q_en(data)                                       ((0x00002000&(data))>>13)
#define  TP_PID_DATA2_get_pre_des(data)                                         ((0x00001000&(data))>>12)
#define  TP_PID_DATA2_get_key(data)                                             ((0x00000F80&(data))>>7)
#define  TP_PID_DATA2_get_reversed(data)                                        ((0x00000060&(data))>>5)
#define  TP_PID_DATA2_get_info_q(data)                                          (0x0000001F&(data))

#define  TP_SEC_CTRL                                                            0x180140A0
#define  TP_SEC_CTRL_reg_addr                                                   "0xB80140A0"
#define  TP_SEC_CTRL_reg                                                        0xB80140A0
#define  TP_SEC_CTRL_inst_addr                                                  "0x0028"
#define  TP_SEC_CTRL_inst                                                       0x0028
#define  TP_SEC_CTRL_rvd_shift                                                  (7)
#define  TP_SEC_CTRL_r_w_shift                                                  (6)
#define  TP_SEC_CTRL_idx_shift                                                  (0)
#define  TP_SEC_CTRL_rvd_mask                                                   (0xFFFFFF80)
#define  TP_SEC_CTRL_r_w_mask                                                   (0x00000040)
#define  TP_SEC_CTRL_idx_mask                                                   (0x0000003F)
#define  TP_SEC_CTRL_rvd(data)                                                  (0xFFFFFF80&((data)<<7))
#define  TP_SEC_CTRL_r_w(data)                                                  (0x00000040&((data)<<6))
#define  TP_SEC_CTRL_idx(data)                                                  (0x0000003F&(data))
#define  TP_SEC_CTRL_get_rvd(data)                                              ((0xFFFFFF80&(data))>>7)
#define  TP_SEC_CTRL_get_r_w(data)                                              ((0x00000040&(data))>>6)
#define  TP_SEC_CTRL_get_idx(data)                                              (0x0000003F&(data))

#define  TP_SEC_DATA0                                                           0x180140A4
#define  TP_SEC_DATA0_reg_addr                                                  "0xB80140A4"
#define  TP_SEC_DATA0_reg                                                       0xB80140A4
#define  TP_SEC_DATA0_inst_addr                                                 "0x0029"
#define  TP_SEC_DATA0_inst                                                      0x0029
#define  TP_SEC_DATA0_filter_value_msb_shift                                    (0)
#define  TP_SEC_DATA0_filter_value_msb_mask                                     (0xFFFFFFFF)
#define  TP_SEC_DATA0_filter_value_msb(data)                                    (0xFFFFFFFF&(data))
#define  TP_SEC_DATA0_get_filter_value_msb(data)                                (0xFFFFFFFF&(data))

#define  TP_SEC_DATA1                                                           0x180140A8
#define  TP_SEC_DATA1_reg_addr                                                  "0xB80140A8"
#define  TP_SEC_DATA1_reg                                                       0xB80140A8
#define  TP_SEC_DATA1_inst_addr                                                 "0x002A"
#define  TP_SEC_DATA1_inst                                                      0x002A
#define  TP_SEC_DATA1_filter_value_lsb_shift                                    (0)
#define  TP_SEC_DATA1_filter_value_lsb_mask                                     (0xFFFFFFFF)
#define  TP_SEC_DATA1_filter_value_lsb(data)                                    (0xFFFFFFFF&(data))
#define  TP_SEC_DATA1_get_filter_value_lsb(data)                                (0xFFFFFFFF&(data))

#define  TP_SEC_DATA2                                                           0x180140AC
#define  TP_SEC_DATA2_reg_addr                                                  "0xB80140AC"
#define  TP_SEC_DATA2_reg                                                       0xB80140AC
#define  TP_SEC_DATA2_inst_addr                                                 "0x002B"
#define  TP_SEC_DATA2_inst                                                      0x002B
#define  TP_SEC_DATA2_mask_value_msb_shift                                      (0)
#define  TP_SEC_DATA2_mask_value_msb_mask                                       (0xFFFFFFFF)
#define  TP_SEC_DATA2_mask_value_msb(data)                                      (0xFFFFFFFF&(data))
#define  TP_SEC_DATA2_get_mask_value_msb(data)                                  (0xFFFFFFFF&(data))

#define  TP_SEC_DATA3                                                           0x180140B0
#define  TP_SEC_DATA3_reg_addr                                                  "0xB80140B0"
#define  TP_SEC_DATA3_reg                                                       0xB80140B0
#define  TP_SEC_DATA3_inst_addr                                                 "0x002C"
#define  TP_SEC_DATA3_inst                                                      0x002C
#define  TP_SEC_DATA3_mask_value_lsb_shift                                      (0)
#define  TP_SEC_DATA3_mask_value_lsb_mask                                       (0xFFFFFFFF)
#define  TP_SEC_DATA3_mask_value_lsb(data)                                      (0xFFFFFFFF&(data))
#define  TP_SEC_DATA3_get_mask_value_lsb(data)                                  (0xFFFFFFFF&(data))

#define  TP_SEC_DATA4                                                           0x180140B4
#define  TP_SEC_DATA4_reg_addr                                                  "0xB80140B4"
#define  TP_SEC_DATA4_reg                                                       0xB80140B4
#define  TP_SEC_DATA4_inst_addr                                                 "0x002D"
#define  TP_SEC_DATA4_inst                                                      0x002D
#define  TP_SEC_DATA4_rvd_shift                                                 (14)
#define  TP_SEC_DATA4_sp_filter_shift                                           (12)
#define  TP_SEC_DATA4_sp_mask_shift                                             (10)
#define  TP_SEC_DATA4_crc_en_shift                                              (9)
#define  TP_SEC_DATA4_p_d_shift                                                 (8)
#define  TP_SEC_DATA4_p_n_shift                                                 (7)
#define  TP_SEC_DATA4_last_shift                                                (6)
#define  TP_SEC_DATA4_next_sec_shift                                            (0)
#define  TP_SEC_DATA4_rvd_mask                                                  (0xFFFFC000)
#define  TP_SEC_DATA4_sp_filter_mask                                            (0x00003000)
#define  TP_SEC_DATA4_sp_mask_mask                                              (0x00000C00)
#define  TP_SEC_DATA4_crc_en_mask                                               (0x00000200)
#define  TP_SEC_DATA4_p_d_mask                                                  (0x00000100)
#define  TP_SEC_DATA4_p_n_mask                                                  (0x00000080)
#define  TP_SEC_DATA4_last_mask                                                 (0x00000040)
#define  TP_SEC_DATA4_next_sec_mask                                             (0x0000003F)
#define  TP_SEC_DATA4_rvd(data)                                                 (0xFFFFC000&((data)<<14))
#define  TP_SEC_DATA4_sp_filter(data)                                           (0x00003000&((data)<<12))
#define  TP_SEC_DATA4_sp_mask(data)                                             (0x00000C00&((data)<<10))
#define  TP_SEC_DATA4_crc_en(data)                                              (0x00000200&((data)<<9))
#define  TP_SEC_DATA4_p_d(data)                                                 (0x00000100&((data)<<8))
#define  TP_SEC_DATA4_p_n(data)                                                 (0x00000080&((data)<<7))
#define  TP_SEC_DATA4_last(data)                                                (0x00000040&((data)<<6))
#define  TP_SEC_DATA4_next_sec(data)                                            (0x0000003F&(data))
#define  TP_SEC_DATA4_get_rvd(data)                                             ((0xFFFFC000&(data))>>14)
#define  TP_SEC_DATA4_get_sp_filter(data)                                       ((0x00003000&(data))>>12)
#define  TP_SEC_DATA4_get_sp_mask(data)                                         ((0x00000C00&(data))>>10)
#define  TP_SEC_DATA4_get_crc_en(data)                                          ((0x00000200&(data))>>9)
#define  TP_SEC_DATA4_get_p_d(data)                                             ((0x00000100&(data))>>8)
#define  TP_SEC_DATA4_get_p_n(data)                                             ((0x00000080&(data))>>7)
#define  TP_SEC_DATA4_get_last(data)                                            ((0x00000040&(data))>>6)
#define  TP_SEC_DATA4_get_next_sec(data)                                        (0x0000003F&(data))

#define  TP_SEC_DATA5                                                           0x180140B8
#define  TP_SEC_DATA5_reg_addr                                                  "0xB80140B8"
#define  TP_SEC_DATA5_reg                                                       0xB80140B8
#define  TP_SEC_DATA5_inst_addr                                                 "0x002E"
#define  TP_SEC_DATA5_inst                                                      0x002E
#define  TP_SEC_DATA5_neg_filter_value_msb_shift                                (0)
#define  TP_SEC_DATA5_neg_filter_value_msb_mask                                 (0xFFFFFFFF)
#define  TP_SEC_DATA5_neg_filter_value_msb(data)                                (0xFFFFFFFF&(data))
#define  TP_SEC_DATA5_get_neg_filter_value_msb(data)                            (0xFFFFFFFF&(data))

#define  TP_SEC_DATA6                                                           0x180140BC
#define  TP_SEC_DATA6_reg_addr                                                  "0xB80140BC"
#define  TP_SEC_DATA6_reg                                                       0xB80140BC
#define  TP_SEC_DATA6_inst_addr                                                 "0x002F"
#define  TP_SEC_DATA6_inst                                                      0x002F
#define  TP_SEC_DATA6_neg_filter_value_lsb_shift                                (0)
#define  TP_SEC_DATA6_neg_filter_value_lsb_mask                                 (0xFFFFFFFF)
#define  TP_SEC_DATA6_neg_filter_value_lsb(data)                                (0xFFFFFFFF&(data))
#define  TP_SEC_DATA6_get_neg_filter_value_lsb(data)                            (0xFFFFFFFF&(data))

#define  TP_SEC_DATA7                                                           0x180140C0
#define  TP_SEC_DATA7_reg_addr                                                  "0xB80140C0"
#define  TP_SEC_DATA7_reg                                                       0xB80140C0
#define  TP_SEC_DATA7_inst_addr                                                 "0x0030"
#define  TP_SEC_DATA7_inst                                                      0x0030
#define  TP_SEC_DATA7_neg_mask_value_msb_shift                                  (0)
#define  TP_SEC_DATA7_neg_mask_value_msb_mask                                   (0xFFFFFFFF)
#define  TP_SEC_DATA7_neg_mask_value_msb(data)                                  (0xFFFFFFFF&(data))
#define  TP_SEC_DATA7_get_neg_mask_value_msb(data)                              (0xFFFFFFFF&(data))

#define  TP_SEC_DATA8                                                           0x180140C4
#define  TP_SEC_DATA8_reg_addr                                                  "0xB80140C4"
#define  TP_SEC_DATA8_reg                                                       0xB80140C4
#define  TP_SEC_DATA8_inst_addr                                                 "0x0031"
#define  TP_SEC_DATA8_inst                                                      0x0031
#define  TP_SEC_DATA8_neg_mask_value_lsb_shift                                  (0)
#define  TP_SEC_DATA8_neg_mask_value_lsb_mask                                   (0xFFFFFFFF)
#define  TP_SEC_DATA8_neg_mask_value_lsb(data)                                  (0xFFFFFFFF&(data))
#define  TP_SEC_DATA8_get_neg_mask_value_lsb(data)                              (0xFFFFFFFF&(data))

#define  TP_SEC_DATA9                                                           0x180140C8
#define  TP_SEC_DATA9_reg_addr                                                  "0xB80140C8"
#define  TP_SEC_DATA9_reg                                                       0xB80140C8
#define  TP_SEC_DATA9_inst_addr                                                 "0x0032"
#define  TP_SEC_DATA9_inst                                                      0x0032
#define  TP_SEC_DATA9_rvd_shift                                                 (14)
#define  TP_SEC_DATA9_neg_sp_filter_shift                                       (12)
#define  TP_SEC_DATA9_neg_sp_mask_shift                                         (10)
#define  TP_SEC_DATA9_rvd_shift                                                 (2)
#define  TP_SEC_DATA9_filter_sel_shift                                          (0)
#define  TP_SEC_DATA9_rvd_mask                                                  (0xFFFFC000)
#define  TP_SEC_DATA9_neg_sp_filter_mask                                        (0x00003000)
#define  TP_SEC_DATA9_neg_sp_mask_mask                                          (0x00000C00)
#define  TP_SEC_DATA9_rvd_mask                                                  (0x000003FC)
#define  TP_SEC_DATA9_filter_sel_mask                                           (0x00000003)
#define  TP_SEC_DATA9_rvd(data)                                                 (0xFFFFC000&((data)<<14))
#define  TP_SEC_DATA9_neg_sp_filter(data)                                       (0x00003000&((data)<<12))
#define  TP_SEC_DATA9_neg_sp_mask(data)                                         (0x00000C00&((data)<<10))
#define  TP_SEC_DATA9_rvd(data)                                                 (0x000003FC&((data)<<2))
#define  TP_SEC_DATA9_filter_sel(data)                                          (0x00000003&(data))
#define  TP_SEC_DATA9_get_rvd(data)                                             ((0xFFFFC000&(data))>>14)
#define  TP_SEC_DATA9_get_neg_sp_filter(data)                                   ((0x00003000&(data))>>12)
#define  TP_SEC_DATA9_get_neg_sp_mask(data)                                     ((0x00000C00&(data))>>10)
#define  TP_SEC_DATA9_get_rvd(data)                                             ((0x000003FC&(data))>>2)
#define  TP_SEC_DATA9_get_filter_sel(data)                                      (0x00000003&(data))

#define  TP_TP0_DES_CNTL                                                        0x180140D0
#define  TP_TP0_DES_CNTL_reg_addr                                               "0xB80140D0"
#define  TP_TP0_DES_CNTL_reg                                                    0xB80140D0
#define  TP_TP0_DES_CNTL_inst_addr                                              "0x0033"
#define  TP_TP0_DES_CNTL_inst                                                   0x0033
#define  TP_TP0_DES_CNTL_rvd_shift                                              (20)
#define  TP_TP0_DES_CNTL_ofb_mode_shift                                         (18)
#define  TP_TP0_DES_CNTL_csa_mode_shift                                         (16)
#define  TP_TP0_DES_CNTL_round_shift                                            (8)
#define  TP_TP0_DES_CNTL_multi2_mode_shift                                      (7)
#define  TP_TP0_DES_CNTL_map_11_shift                                           (6)
#define  TP_TP0_DES_CNTL_map_10_shift                                           (5)
#define  TP_TP0_DES_CNTL_map_01_shift                                           (4)
#define  TP_TP0_DES_CNTL_des_mode_shift                                         (3)
#define  TP_TP0_DES_CNTL_mode_shift                                             (0)
#define  TP_TP0_DES_CNTL_rvd_mask                                               (0xFFF00000)
#define  TP_TP0_DES_CNTL_ofb_mode_mask                                          (0x000C0000)
#define  TP_TP0_DES_CNTL_csa_mode_mask                                          (0x00030000)
#define  TP_TP0_DES_CNTL_round_mask                                             (0x0000FF00)
#define  TP_TP0_DES_CNTL_multi2_mode_mask                                       (0x00000080)
#define  TP_TP0_DES_CNTL_map_11_mask                                            (0x00000040)
#define  TP_TP0_DES_CNTL_map_10_mask                                            (0x00000020)
#define  TP_TP0_DES_CNTL_map_01_mask                                            (0x00000010)
#define  TP_TP0_DES_CNTL_des_mode_mask                                          (0x00000008)
#define  TP_TP0_DES_CNTL_mode_mask                                              (0x00000007)
#define  TP_TP0_DES_CNTL_rvd(data)                                              (0xFFF00000&((data)<<20))
#define  TP_TP0_DES_CNTL_ofb_mode(data)                                         (0x000C0000&((data)<<18))
#define  TP_TP0_DES_CNTL_csa_mode(data)                                         (0x00030000&((data)<<16))
#define  TP_TP0_DES_CNTL_round(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TP0_DES_CNTL_multi2_mode(data)                                      (0x00000080&((data)<<7))
#define  TP_TP0_DES_CNTL_map_11(data)                                           (0x00000040&((data)<<6))
#define  TP_TP0_DES_CNTL_map_10(data)                                           (0x00000020&((data)<<5))
#define  TP_TP0_DES_CNTL_map_01(data)                                           (0x00000010&((data)<<4))
#define  TP_TP0_DES_CNTL_des_mode(data)                                         (0x00000008&((data)<<3))
#define  TP_TP0_DES_CNTL_mode(data)                                             (0x00000007&(data))
#define  TP_TP0_DES_CNTL_get_rvd(data)                                          ((0xFFF00000&(data))>>20)
#define  TP_TP0_DES_CNTL_get_ofb_mode(data)                                     ((0x000C0000&(data))>>18)
#define  TP_TP0_DES_CNTL_get_csa_mode(data)                                     ((0x00030000&(data))>>16)
#define  TP_TP0_DES_CNTL_get_round(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TP0_DES_CNTL_get_multi2_mode(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP0_DES_CNTL_get_map_11(data)                                       ((0x00000040&(data))>>6)
#define  TP_TP0_DES_CNTL_get_map_10(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP0_DES_CNTL_get_map_01(data)                                       ((0x00000010&(data))>>4)
#define  TP_TP0_DES_CNTL_get_des_mode(data)                                     ((0x00000008&(data))>>3)
#define  TP_TP0_DES_CNTL_get_mode(data)                                         (0x00000007&(data))

#define  TP_KEY_INFO                                                            0x180140D4
#define  TP_KEY_INFO_reg_addr                                                   "0xB80140D4"
#define  TP_KEY_INFO_reg                                                        0xB80140D4
#define  TP_KEY_INFO_inst_addr                                                  "0x0034"
#define  TP_KEY_INFO_inst                                                       0x0034
#define  TP_KEY_INFO_key_info_shift                                             (0)
#define  TP_KEY_INFO_key_info_mask                                              (0xFFFFFFFF)
#define  TP_KEY_INFO_key_info(data)                                             (0xFFFFFFFF&(data))
#define  TP_KEY_INFO_get_key_info(data)                                         (0xFFFFFFFF&(data))

#define  TP_KEY_CTRL                                                            0x180140DC
#define  TP_KEY_CTRL_reg_addr                                                   "0xB80140DC"
#define  TP_KEY_CTRL_reg                                                        0xB80140DC
#define  TP_KEY_CTRL_inst_addr                                                  "0x0035"
#define  TP_KEY_CTRL_inst                                                       0x0035
#define  TP_KEY_CTRL_rvd_shift                                                  (8)
#define  TP_KEY_CTRL_r_w_shift                                                  (7)
#define  TP_KEY_CTRL_idx_shift                                                  (0)
#define  TP_KEY_CTRL_rvd_mask                                                   (0xFFFFFF00)
#define  TP_KEY_CTRL_r_w_mask                                                   (0x00000080)
#define  TP_KEY_CTRL_idx_mask                                                   (0x0000007F)
#define  TP_KEY_CTRL_rvd(data)                                                  (0xFFFFFF00&((data)<<8))
#define  TP_KEY_CTRL_r_w(data)                                                  (0x00000080&((data)<<7))
#define  TP_KEY_CTRL_idx(data)                                                  (0x0000007F&(data))
#define  TP_KEY_CTRL_get_rvd(data)                                              ((0xFFFFFF00&(data))>>8)
#define  TP_KEY_CTRL_get_r_w(data)                                              ((0x00000080&(data))>>7)
#define  TP_KEY_CTRL_get_idx(data)                                              (0x0000007F&(data))

#define  TP_TP1_DES_CNTL                                                        0x180140E0
#define  TP_TP1_DES_CNTL_reg_addr                                               "0xB80140E0"
#define  TP_TP1_DES_CNTL_reg                                                    0xB80140E0
#define  TP_TP1_DES_CNTL_inst_addr                                              "0x0036"
#define  TP_TP1_DES_CNTL_inst                                                   0x0036
#define  TP_TP1_DES_CNTL_rvd_shift                                              (20)
#define  TP_TP1_DES_CNTL_ofb_mode_shift                                         (18)
#define  TP_TP1_DES_CNTL_csa_mode_shift                                         (16)
#define  TP_TP1_DES_CNTL_round_shift                                            (8)
#define  TP_TP1_DES_CNTL_multi2_mode_shift                                      (7)
#define  TP_TP1_DES_CNTL_map_11_shift                                           (6)
#define  TP_TP1_DES_CNTL_map_10_shift                                           (5)
#define  TP_TP1_DES_CNTL_map_01_shift                                           (4)
#define  TP_TP1_DES_CNTL_des_mode_shift                                         (3)
#define  TP_TP1_DES_CNTL_mode_shift                                             (0)
#define  TP_TP1_DES_CNTL_rvd_mask                                               (0xFFF00000)
#define  TP_TP1_DES_CNTL_ofb_mode_mask                                          (0x000C0000)
#define  TP_TP1_DES_CNTL_csa_mode_mask                                          (0x00030000)
#define  TP_TP1_DES_CNTL_round_mask                                             (0x0000FF00)
#define  TP_TP1_DES_CNTL_multi2_mode_mask                                       (0x00000080)
#define  TP_TP1_DES_CNTL_map_11_mask                                            (0x00000040)
#define  TP_TP1_DES_CNTL_map_10_mask                                            (0x00000020)
#define  TP_TP1_DES_CNTL_map_01_mask                                            (0x00000010)
#define  TP_TP1_DES_CNTL_des_mode_mask                                          (0x00000008)
#define  TP_TP1_DES_CNTL_mode_mask                                              (0x00000007)
#define  TP_TP1_DES_CNTL_rvd(data)                                              (0xFFF00000&((data)<<20))
#define  TP_TP1_DES_CNTL_ofb_mode(data)                                         (0x000C0000&((data)<<18))
#define  TP_TP1_DES_CNTL_csa_mode(data)                                         (0x00030000&((data)<<16))
#define  TP_TP1_DES_CNTL_round(data)                                            (0x0000FF00&((data)<<8))
#define  TP_TP1_DES_CNTL_multi2_mode(data)                                      (0x00000080&((data)<<7))
#define  TP_TP1_DES_CNTL_map_11(data)                                           (0x00000040&((data)<<6))
#define  TP_TP1_DES_CNTL_map_10(data)                                           (0x00000020&((data)<<5))
#define  TP_TP1_DES_CNTL_map_01(data)                                           (0x00000010&((data)<<4))
#define  TP_TP1_DES_CNTL_des_mode(data)                                         (0x00000008&((data)<<3))
#define  TP_TP1_DES_CNTL_mode(data)                                             (0x00000007&(data))
#define  TP_TP1_DES_CNTL_get_rvd(data)                                          ((0xFFF00000&(data))>>20)
#define  TP_TP1_DES_CNTL_get_ofb_mode(data)                                     ((0x000C0000&(data))>>18)
#define  TP_TP1_DES_CNTL_get_csa_mode(data)                                     ((0x00030000&(data))>>16)
#define  TP_TP1_DES_CNTL_get_round(data)                                        ((0x0000FF00&(data))>>8)
#define  TP_TP1_DES_CNTL_get_multi2_mode(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP1_DES_CNTL_get_map_11(data)                                       ((0x00000040&(data))>>6)
#define  TP_TP1_DES_CNTL_get_map_10(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP1_DES_CNTL_get_map_01(data)                                       ((0x00000010&(data))>>4)
#define  TP_TP1_DES_CNTL_get_des_mode(data)                                     ((0x00000008&(data))>>3)
#define  TP_TP1_DES_CNTL_get_mode(data)                                         (0x00000007&(data))

#define  TP_CRC_INIT                                                            0x180140E8
#define  TP_CRC_INIT_reg_addr                                                   "0xB80140E8"
#define  TP_CRC_INIT_reg                                                        0xB80140E8
#define  TP_CRC_INIT_inst_addr                                                  "0x0037"
#define  TP_CRC_INIT_inst                                                       0x0037
#define  TP_CRC_INIT_crc_init_shift                                             (0)
#define  TP_CRC_INIT_crc_init_mask                                              (0xFFFFFFFF)
#define  TP_CRC_INIT_crc_init(data)                                             (0xFFFFFFFF&(data))
#define  TP_CRC_INIT_get_crc_init(data)                                         (0xFFFFFFFF&(data))

#define  TP_THRESHOLD                                                           0x180140F0
#define  TP_THRESHOLD_reg_addr                                                  "0xB80140F0"
#define  TP_THRESHOLD_reg                                                       0xB80140F0
#define  TP_THRESHOLD_inst_addr                                                 "0x0038"
#define  TP_THRESHOLD_inst                                                      0x0038
#define  TP_THRESHOLD_rvd_shift                                                 (27)
#define  TP_THRESHOLD_threshold_shift                                           (0)
#define  TP_THRESHOLD_rvd_mask                                                  (0xF8000000)
#define  TP_THRESHOLD_threshold_mask                                            (0x07FFFFFF)
#define  TP_THRESHOLD_rvd(data)                                                 (0xF8000000&((data)<<27))
#define  TP_THRESHOLD_threshold(data)                                           (0x07FFFFFF&(data))
#define  TP_THRESHOLD_get_rvd(data)                                             ((0xF8000000&(data))>>27)
#define  TP_THRESHOLD_get_threshold(data)                                       (0x07FFFFFF&(data))

#define  TP_FULLNESS                                                            0x180140F4
#define  TP_FULLNESS_reg_addr                                                   "0xB80140F4"
#define  TP_FULLNESS_reg                                                        0xB80140F4
#define  TP_FULLNESS_inst_addr                                                  "0x0039"
#define  TP_FULLNESS_inst                                                       0x0039
#define  TP_FULLNESS_rvd_shift                                                  (27)
#define  TP_FULLNESS_fullness_shift                                             (0)
#define  TP_FULLNESS_rvd_mask                                                   (0xF8000000)
#define  TP_FULLNESS_fullness_mask                                              (0x07FFFFFF)
#define  TP_FULLNESS_rvd(data)                                                  (0xF8000000&((data)<<27))
#define  TP_FULLNESS_fullness(data)                                             (0x07FFFFFF&(data))
#define  TP_FULLNESS_get_rvd(data)                                              ((0xF8000000&(data))>>27)
#define  TP_FULLNESS_get_fullness(data)                                         (0x07FFFFFF&(data))

#define  TP_RING_CTRL                                                           0x180140FC
#define  TP_RING_CTRL_reg_addr                                                  "0xB80140FC"
#define  TP_RING_CTRL_reg                                                       0xB80140FC
#define  TP_RING_CTRL_inst_addr                                                 "0x003A"
#define  TP_RING_CTRL_inst                                                      0x003A
#define  TP_RING_CTRL_rvd_shift                                                 (11)
#define  TP_RING_CTRL_wm_shift                                                  (7)
#define  TP_RING_CTRL_r_w_shift                                                 (6)
#define  TP_RING_CTRL_rvd_shift                                                 (5)
#define  TP_RING_CTRL_idx_shift                                                 (0)
#define  TP_RING_CTRL_rvd_mask                                                  (0xFFFFF800)
#define  TP_RING_CTRL_wm_mask                                                   (0x00000780)
#define  TP_RING_CTRL_r_w_mask                                                  (0x00000040)
#define  TP_RING_CTRL_rvd_mask                                                  (0x00000020)
#define  TP_RING_CTRL_idx_mask                                                  (0x0000001F)
#define  TP_RING_CTRL_rvd(data)                                                 (0xFFFFF800&((data)<<11))
#define  TP_RING_CTRL_wm(data)                                                  (0x00000780&((data)<<7))
#define  TP_RING_CTRL_r_w(data)                                                 (0x00000040&((data)<<6))
#define  TP_RING_CTRL_rvd(data)                                                 (0x00000020&((data)<<5))
#define  TP_RING_CTRL_idx(data)                                                 (0x0000001F&(data))
#define  TP_RING_CTRL_get_rvd(data)                                             ((0xFFFFF800&(data))>>11)
#define  TP_RING_CTRL_get_wm(data)                                              ((0x00000780&(data))>>7)
#define  TP_RING_CTRL_get_r_w(data)                                             ((0x00000040&(data))>>6)
#define  TP_RING_CTRL_get_rvd(data)                                             ((0x00000020&(data))>>5)
#define  TP_RING_CTRL_get_idx(data)                                             (0x0000001F&(data))

#define  TP_RING_LIMIT                                                          0x18014100
#define  TP_RING_LIMIT_reg_addr                                                 "0xB8014100"
#define  TP_RING_LIMIT_reg                                                      0xB8014100
#define  TP_RING_LIMIT_inst_addr                                                "0x003B"
#define  TP_RING_LIMIT_inst                                                     0x003B
#define  TP_RING_LIMIT_rvd_shift                                                (30)
#define  TP_RING_LIMIT_ring_limit_shift                                         (3)
#define  TP_RING_LIMIT_rvd_shift                                                (0)
#define  TP_RING_LIMIT_rvd_mask                                                 (0xC0000000)
#define  TP_RING_LIMIT_ring_limit_mask                                          (0x3FFFFFF8)
#define  TP_RING_LIMIT_rvd_mask                                                 (0x00000007)
#define  TP_RING_LIMIT_rvd(data)                                                (0xC0000000&((data)<<30))
#define  TP_RING_LIMIT_ring_limit(data)                                         (0x3FFFFFF8&((data)<<3))
#define  TP_RING_LIMIT_rvd(data)                                                (0x00000007&(data))
#define  TP_RING_LIMIT_get_rvd(data)                                            ((0xC0000000&(data))>>30)
#define  TP_RING_LIMIT_get_ring_limit(data)                                     ((0x3FFFFFF8&(data))>>3)
#define  TP_RING_LIMIT_get_rvd(data)                                            (0x00000007&(data))

#define  TP_RING_BASE                                                           0x18014104
#define  TP_RING_BASE_reg_addr                                                  "0xB8014104"
#define  TP_RING_BASE_reg                                                       0xB8014104
#define  TP_RING_BASE_inst_addr                                                 "0x003C"
#define  TP_RING_BASE_inst                                                      0x003C
#define  TP_RING_BASE_rvd_shift                                                 (30)
#define  TP_RING_BASE_ring_base_shift                                           (3)
#define  TP_RING_BASE_rvd_shift                                                 (0)
#define  TP_RING_BASE_rvd_mask                                                  (0xC0000000)
#define  TP_RING_BASE_ring_base_mask                                            (0x3FFFFFF8)
#define  TP_RING_BASE_rvd_mask                                                  (0x00000007)
#define  TP_RING_BASE_rvd(data)                                                 (0xC0000000&((data)<<30))
#define  TP_RING_BASE_ring_base(data)                                           (0x3FFFFFF8&((data)<<3))
#define  TP_RING_BASE_rvd(data)                                                 (0x00000007&(data))
#define  TP_RING_BASE_get_rvd(data)                                             ((0xC0000000&(data))>>30)
#define  TP_RING_BASE_get_ring_base(data)                                       ((0x3FFFFFF8&(data))>>3)
#define  TP_RING_BASE_get_rvd(data)                                             (0x00000007&(data))

#define  TP_RING_RP                                                             0x18014108
#define  TP_RING_RP_reg_addr                                                    "0xB8014108"
#define  TP_RING_RP_reg                                                         0xB8014108
#define  TP_RING_RP_inst_addr                                                   "0x003D"
#define  TP_RING_RP_inst                                                        0x003D
#define  TP_RING_RP_rvd_shift                                                   (30)
#define  TP_RING_RP_ring_rp_shift                                               (0)
#define  TP_RING_RP_rvd_mask                                                    (0xC0000000)
#define  TP_RING_RP_ring_rp_mask                                                (0x3FFFFFFF)
#define  TP_RING_RP_rvd(data)                                                   (0xC0000000&((data)<<30))
#define  TP_RING_RP_ring_rp(data)                                               (0x3FFFFFFF&(data))
#define  TP_RING_RP_get_rvd(data)                                               ((0xC0000000&(data))>>30)
#define  TP_RING_RP_get_ring_rp(data)                                           (0x3FFFFFFF&(data))

#define  TP_RING_WP                                                             0x1801410C
#define  TP_RING_WP_reg_addr                                                    "0xB801410C"
#define  TP_RING_WP_reg                                                         0xB801410C
#define  TP_RING_WP_inst_addr                                                   "0x003E"
#define  TP_RING_WP_inst                                                        0x003E
#define  TP_RING_WP_rvd_shift                                                   (30)
#define  TP_RING_WP_ring_wp_shift                                               (0)
#define  TP_RING_WP_rvd_mask                                                    (0xC0000000)
#define  TP_RING_WP_ring_wp_mask                                                (0x3FFFFFFF)
#define  TP_RING_WP_rvd(data)                                                   (0xC0000000&((data)<<30))
#define  TP_RING_WP_ring_wp(data)                                               (0x3FFFFFFF&(data))
#define  TP_RING_WP_get_rvd(data)                                               ((0xC0000000&(data))>>30)
#define  TP_RING_WP_get_ring_wp(data)                                           (0x3FFFFFFF&(data))

#define  TP_RING_AVAIL_INT                                                      0x18014110
#define  TP_RING_AVAIL_INT_reg_addr                                             "0xB8014110"
#define  TP_RING_AVAIL_INT_reg                                                  0xB8014110
#define  TP_RING_AVAIL_INT_inst_addr                                            "0x003F"
#define  TP_RING_AVAIL_INT_inst                                                 0x003F
#define  TP_RING_AVAIL_INT_rvd_shift                                            (17)
#define  TP_RING_AVAIL_INT_ring_avail_15_shift                                  (16)
#define  TP_RING_AVAIL_INT_ring_avail_14_shift                                  (15)
#define  TP_RING_AVAIL_INT_ring_avail_13_shift                                  (14)
#define  TP_RING_AVAIL_INT_ring_avail_12_shift                                  (13)
#define  TP_RING_AVAIL_INT_ring_avail_11_shift                                  (12)
#define  TP_RING_AVAIL_INT_ring_avail_10_shift                                  (11)
#define  TP_RING_AVAIL_INT_ring_avail_9_shift                                   (10)
#define  TP_RING_AVAIL_INT_ring_avail_8_shift                                   (9)
#define  TP_RING_AVAIL_INT_ring_avail_7_shift                                   (8)
#define  TP_RING_AVAIL_INT_ring_avail_6_shift                                   (7)
#define  TP_RING_AVAIL_INT_ring_avail_5_shift                                   (6)
#define  TP_RING_AVAIL_INT_ring_avail_4_shift                                   (5)
#define  TP_RING_AVAIL_INT_ring_avail_3_shift                                   (4)
#define  TP_RING_AVAIL_INT_ring_avail_2_shift                                   (3)
#define  TP_RING_AVAIL_INT_ring_avail_1_shift                                   (2)
#define  TP_RING_AVAIL_INT_ring_avail_0_shift                                   (1)
#define  TP_RING_AVAIL_INT_write_data_shift                                     (0)
#define  TP_RING_AVAIL_INT_rvd_mask                                             (0xFFFE0000)
#define  TP_RING_AVAIL_INT_ring_avail_15_mask                                   (0x00010000)
#define  TP_RING_AVAIL_INT_ring_avail_14_mask                                   (0x00008000)
#define  TP_RING_AVAIL_INT_ring_avail_13_mask                                   (0x00004000)
#define  TP_RING_AVAIL_INT_ring_avail_12_mask                                   (0x00002000)
#define  TP_RING_AVAIL_INT_ring_avail_11_mask                                   (0x00001000)
#define  TP_RING_AVAIL_INT_ring_avail_10_mask                                   (0x00000800)
#define  TP_RING_AVAIL_INT_ring_avail_9_mask                                    (0x00000400)
#define  TP_RING_AVAIL_INT_ring_avail_8_mask                                    (0x00000200)
#define  TP_RING_AVAIL_INT_ring_avail_7_mask                                    (0x00000100)
#define  TP_RING_AVAIL_INT_ring_avail_6_mask                                    (0x00000080)
#define  TP_RING_AVAIL_INT_ring_avail_5_mask                                    (0x00000040)
#define  TP_RING_AVAIL_INT_ring_avail_4_mask                                    (0x00000020)
#define  TP_RING_AVAIL_INT_ring_avail_3_mask                                    (0x00000010)
#define  TP_RING_AVAIL_INT_ring_avail_2_mask                                    (0x00000008)
#define  TP_RING_AVAIL_INT_ring_avail_1_mask                                    (0x00000004)
#define  TP_RING_AVAIL_INT_ring_avail_0_mask                                    (0x00000002)
#define  TP_RING_AVAIL_INT_write_data_mask                                      (0x00000001)
#define  TP_RING_AVAIL_INT_rvd(data)                                            (0xFFFE0000&((data)<<17))
#define  TP_RING_AVAIL_INT_ring_avail_15(data)                                  (0x00010000&((data)<<16))
#define  TP_RING_AVAIL_INT_ring_avail_14(data)                                  (0x00008000&((data)<<15))
#define  TP_RING_AVAIL_INT_ring_avail_13(data)                                  (0x00004000&((data)<<14))
#define  TP_RING_AVAIL_INT_ring_avail_12(data)                                  (0x00002000&((data)<<13))
#define  TP_RING_AVAIL_INT_ring_avail_11(data)                                  (0x00001000&((data)<<12))
#define  TP_RING_AVAIL_INT_ring_avail_10(data)                                  (0x00000800&((data)<<11))
#define  TP_RING_AVAIL_INT_ring_avail_9(data)                                   (0x00000400&((data)<<10))
#define  TP_RING_AVAIL_INT_ring_avail_8(data)                                   (0x00000200&((data)<<9))
#define  TP_RING_AVAIL_INT_ring_avail_7(data)                                   (0x00000100&((data)<<8))
#define  TP_RING_AVAIL_INT_ring_avail_6(data)                                   (0x00000080&((data)<<7))
#define  TP_RING_AVAIL_INT_ring_avail_5(data)                                   (0x00000040&((data)<<6))
#define  TP_RING_AVAIL_INT_ring_avail_4(data)                                   (0x00000020&((data)<<5))
#define  TP_RING_AVAIL_INT_ring_avail_3(data)                                   (0x00000010&((data)<<4))
#define  TP_RING_AVAIL_INT_ring_avail_2(data)                                   (0x00000008&((data)<<3))
#define  TP_RING_AVAIL_INT_ring_avail_1(data)                                   (0x00000004&((data)<<2))
#define  TP_RING_AVAIL_INT_ring_avail_0(data)                                   (0x00000002&((data)<<1))
#define  TP_RING_AVAIL_INT_write_data(data)                                     (0x00000001&(data))
#define  TP_RING_AVAIL_INT_get_rvd(data)                                        ((0xFFFE0000&(data))>>17)
#define  TP_RING_AVAIL_INT_get_ring_avail_15(data)                              ((0x00010000&(data))>>16)
#define  TP_RING_AVAIL_INT_get_ring_avail_14(data)                              ((0x00008000&(data))>>15)
#define  TP_RING_AVAIL_INT_get_ring_avail_13(data)                              ((0x00004000&(data))>>14)
#define  TP_RING_AVAIL_INT_get_ring_avail_12(data)                              ((0x00002000&(data))>>13)
#define  TP_RING_AVAIL_INT_get_ring_avail_11(data)                              ((0x00001000&(data))>>12)
#define  TP_RING_AVAIL_INT_get_ring_avail_10(data)                              ((0x00000800&(data))>>11)
#define  TP_RING_AVAIL_INT_get_ring_avail_9(data)                               ((0x00000400&(data))>>10)
#define  TP_RING_AVAIL_INT_get_ring_avail_8(data)                               ((0x00000200&(data))>>9)
#define  TP_RING_AVAIL_INT_get_ring_avail_7(data)                               ((0x00000100&(data))>>8)
#define  TP_RING_AVAIL_INT_get_ring_avail_6(data)                               ((0x00000080&(data))>>7)
#define  TP_RING_AVAIL_INT_get_ring_avail_5(data)                               ((0x00000040&(data))>>6)
#define  TP_RING_AVAIL_INT_get_ring_avail_4(data)                               ((0x00000020&(data))>>5)
#define  TP_RING_AVAIL_INT_get_ring_avail_3(data)                               ((0x00000010&(data))>>4)
#define  TP_RING_AVAIL_INT_get_ring_avail_2(data)                               ((0x00000008&(data))>>3)
#define  TP_RING_AVAIL_INT_get_ring_avail_1(data)                               ((0x00000004&(data))>>2)
#define  TP_RING_AVAIL_INT_get_ring_avail_0(data)                               ((0x00000002&(data))>>1)
#define  TP_RING_AVAIL_INT_get_write_data(data)                                 (0x00000001&(data))

#define  TP_RING_FULL_INT                                                       0x18014120
#define  TP_RING_FULL_INT_reg_addr                                              "0xB8014120"
#define  TP_RING_FULL_INT_reg                                                   0xB8014120
#define  TP_RING_FULL_INT_inst_addr                                             "0x0040"
#define  TP_RING_FULL_INT_inst                                                  0x0040
#define  TP_RING_FULL_INT_rvd_shift                                             (17)
#define  TP_RING_FULL_INT_ring_full_15_shift                                    (16)
#define  TP_RING_FULL_INT_ring_full_14_shift                                    (15)
#define  TP_RING_FULL_INT_ring_full_13_shift                                    (14)
#define  TP_RING_FULL_INT_ring_full_12_shift                                    (13)
#define  TP_RING_FULL_INT_ring_full_11_shift                                    (12)
#define  TP_RING_FULL_INT_ring_full_10_shift                                    (11)
#define  TP_RING_FULL_INT_ring_full_9_shift                                     (10)
#define  TP_RING_FULL_INT_ring_full_8_shift                                     (9)
#define  TP_RING_FULL_INT_ring_full_7_shift                                     (8)
#define  TP_RING_FULL_INT_ring_full_6_shift                                     (7)
#define  TP_RING_FULL_INT_ring_full_5_shift                                     (6)
#define  TP_RING_FULL_INT_ring_full_4_shift                                     (5)
#define  TP_RING_FULL_INT_ring_full_3_shift                                     (4)
#define  TP_RING_FULL_INT_ring_full_2_shift                                     (3)
#define  TP_RING_FULL_INT_ring_full_1_shift                                     (2)
#define  TP_RING_FULL_INT_ring_full_0_shift                                     (1)
#define  TP_RING_FULL_INT_write_data_shift                                      (0)
#define  TP_RING_FULL_INT_rvd_mask                                              (0xFFFE0000)
#define  TP_RING_FULL_INT_ring_full_15_mask                                     (0x00010000)
#define  TP_RING_FULL_INT_ring_full_14_mask                                     (0x00008000)
#define  TP_RING_FULL_INT_ring_full_13_mask                                     (0x00004000)
#define  TP_RING_FULL_INT_ring_full_12_mask                                     (0x00002000)
#define  TP_RING_FULL_INT_ring_full_11_mask                                     (0x00001000)
#define  TP_RING_FULL_INT_ring_full_10_mask                                     (0x00000800)
#define  TP_RING_FULL_INT_ring_full_9_mask                                      (0x00000400)
#define  TP_RING_FULL_INT_ring_full_8_mask                                      (0x00000200)
#define  TP_RING_FULL_INT_ring_full_7_mask                                      (0x00000100)
#define  TP_RING_FULL_INT_ring_full_6_mask                                      (0x00000080)
#define  TP_RING_FULL_INT_ring_full_5_mask                                      (0x00000040)
#define  TP_RING_FULL_INT_ring_full_4_mask                                      (0x00000020)
#define  TP_RING_FULL_INT_ring_full_3_mask                                      (0x00000010)
#define  TP_RING_FULL_INT_ring_full_2_mask                                      (0x00000008)
#define  TP_RING_FULL_INT_ring_full_1_mask                                      (0x00000004)
#define  TP_RING_FULL_INT_ring_full_0_mask                                      (0x00000002)
#define  TP_RING_FULL_INT_write_data_mask                                       (0x00000001)
#define  TP_RING_FULL_INT_rvd(data)                                             (0xFFFE0000&((data)<<17))
#define  TP_RING_FULL_INT_ring_full_15(data)                                    (0x00010000&((data)<<16))
#define  TP_RING_FULL_INT_ring_full_14(data)                                    (0x00008000&((data)<<15))
#define  TP_RING_FULL_INT_ring_full_13(data)                                    (0x00004000&((data)<<14))
#define  TP_RING_FULL_INT_ring_full_12(data)                                    (0x00002000&((data)<<13))
#define  TP_RING_FULL_INT_ring_full_11(data)                                    (0x00001000&((data)<<12))
#define  TP_RING_FULL_INT_ring_full_10(data)                                    (0x00000800&((data)<<11))
#define  TP_RING_FULL_INT_ring_full_9(data)                                     (0x00000400&((data)<<10))
#define  TP_RING_FULL_INT_ring_full_8(data)                                     (0x00000200&((data)<<9))
#define  TP_RING_FULL_INT_ring_full_7(data)                                     (0x00000100&((data)<<8))
#define  TP_RING_FULL_INT_ring_full_6(data)                                     (0x00000080&((data)<<7))
#define  TP_RING_FULL_INT_ring_full_5(data)                                     (0x00000040&((data)<<6))
#define  TP_RING_FULL_INT_ring_full_4(data)                                     (0x00000020&((data)<<5))
#define  TP_RING_FULL_INT_ring_full_3(data)                                     (0x00000010&((data)<<4))
#define  TP_RING_FULL_INT_ring_full_2(data)                                     (0x00000008&((data)<<3))
#define  TP_RING_FULL_INT_ring_full_1(data)                                     (0x00000004&((data)<<2))
#define  TP_RING_FULL_INT_ring_full_0(data)                                     (0x00000002&((data)<<1))
#define  TP_RING_FULL_INT_write_data(data)                                      (0x00000001&(data))
#define  TP_RING_FULL_INT_get_rvd(data)                                         ((0xFFFE0000&(data))>>17)
#define  TP_RING_FULL_INT_get_ring_full_15(data)                                ((0x00010000&(data))>>16)
#define  TP_RING_FULL_INT_get_ring_full_14(data)                                ((0x00008000&(data))>>15)
#define  TP_RING_FULL_INT_get_ring_full_13(data)                                ((0x00004000&(data))>>14)
#define  TP_RING_FULL_INT_get_ring_full_12(data)                                ((0x00002000&(data))>>13)
#define  TP_RING_FULL_INT_get_ring_full_11(data)                                ((0x00001000&(data))>>12)
#define  TP_RING_FULL_INT_get_ring_full_10(data)                                ((0x00000800&(data))>>11)
#define  TP_RING_FULL_INT_get_ring_full_9(data)                                 ((0x00000400&(data))>>10)
#define  TP_RING_FULL_INT_get_ring_full_8(data)                                 ((0x00000200&(data))>>9)
#define  TP_RING_FULL_INT_get_ring_full_7(data)                                 ((0x00000100&(data))>>8)
#define  TP_RING_FULL_INT_get_ring_full_6(data)                                 ((0x00000080&(data))>>7)
#define  TP_RING_FULL_INT_get_ring_full_5(data)                                 ((0x00000040&(data))>>6)
#define  TP_RING_FULL_INT_get_ring_full_4(data)                                 ((0x00000020&(data))>>5)
#define  TP_RING_FULL_INT_get_ring_full_3(data)                                 ((0x00000010&(data))>>4)
#define  TP_RING_FULL_INT_get_ring_full_2(data)                                 ((0x00000008&(data))>>3)
#define  TP_RING_FULL_INT_get_ring_full_1(data)                                 ((0x00000004&(data))>>2)
#define  TP_RING_FULL_INT_get_ring_full_0(data)                                 ((0x00000002&(data))>>1)
#define  TP_RING_FULL_INT_get_write_data(data)                                  (0x00000001&(data))

#define  TP_RING_AVAIL_INT_EN                                                   0x18014204
#define  TP_RING_AVAIL_INT_EN_reg_addr                                          "0xB8014204"
#define  TP_RING_AVAIL_INT_EN_reg                                               0xB8014204
#define  TP_RING_AVAIL_INT_EN_inst_addr                                         "0x0041"
#define  TP_RING_AVAIL_INT_EN_inst                                              0x0041
#define  TP_RING_AVAIL_INT_EN_rvd_shift                                         (17)
#define  TP_RING_AVAIL_INT_EN_ring_avail_15_en_shift                            (16)
#define  TP_RING_AVAIL_INT_EN_ring_avail_14_en_shift                            (15)
#define  TP_RING_AVAIL_INT_EN_ring_avail_13_en_shift                            (14)
#define  TP_RING_AVAIL_INT_EN_ring_avail_12_en_shift                            (13)
#define  TP_RING_AVAIL_INT_EN_ring_avail_11_en_shift                            (12)
#define  TP_RING_AVAIL_INT_EN_ring_avail_10_en_shift                            (11)
#define  TP_RING_AVAIL_INT_EN_ring_avail_9_en_shift                             (10)
#define  TP_RING_AVAIL_INT_EN_ring_avail_8_en_shift                             (9)
#define  TP_RING_AVAIL_INT_EN_ring_avail_7_en_shift                             (8)
#define  TP_RING_AVAIL_INT_EN_ring_avail_6_en_shift                             (7)
#define  TP_RING_AVAIL_INT_EN_ring_avail_5_en_shift                             (6)
#define  TP_RING_AVAIL_INT_EN_ring_avail_4_en_shift                             (5)
#define  TP_RING_AVAIL_INT_EN_ring_avail_3_en_shift                             (4)
#define  TP_RING_AVAIL_INT_EN_ring_avail_2_en_shift                             (3)
#define  TP_RING_AVAIL_INT_EN_ring_avail_1_en_shift                             (2)
#define  TP_RING_AVAIL_INT_EN_ring_avail_0_en_shift                             (1)
#define  TP_RING_AVAIL_INT_EN_write_data_shift                                  (0)
#define  TP_RING_AVAIL_INT_EN_rvd_mask                                          (0xFFFE0000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_15_en_mask                             (0x00010000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_14_en_mask                             (0x00008000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_13_en_mask                             (0x00004000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_12_en_mask                             (0x00002000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_11_en_mask                             (0x00001000)
#define  TP_RING_AVAIL_INT_EN_ring_avail_10_en_mask                             (0x00000800)
#define  TP_RING_AVAIL_INT_EN_ring_avail_9_en_mask                              (0x00000400)
#define  TP_RING_AVAIL_INT_EN_ring_avail_8_en_mask                              (0x00000200)
#define  TP_RING_AVAIL_INT_EN_ring_avail_7_en_mask                              (0x00000100)
#define  TP_RING_AVAIL_INT_EN_ring_avail_6_en_mask                              (0x00000080)
#define  TP_RING_AVAIL_INT_EN_ring_avail_5_en_mask                              (0x00000040)
#define  TP_RING_AVAIL_INT_EN_ring_avail_4_en_mask                              (0x00000020)
#define  TP_RING_AVAIL_INT_EN_ring_avail_3_en_mask                              (0x00000010)
#define  TP_RING_AVAIL_INT_EN_ring_avail_2_en_mask                              (0x00000008)
#define  TP_RING_AVAIL_INT_EN_ring_avail_1_en_mask                              (0x00000004)
#define  TP_RING_AVAIL_INT_EN_ring_avail_0_en_mask                              (0x00000002)
#define  TP_RING_AVAIL_INT_EN_write_data_mask                                   (0x00000001)
#define  TP_RING_AVAIL_INT_EN_rvd(data)                                         (0xFFFE0000&((data)<<17))
#define  TP_RING_AVAIL_INT_EN_ring_avail_15_en(data)                            (0x00010000&((data)<<16))
#define  TP_RING_AVAIL_INT_EN_ring_avail_14_en(data)                            (0x00008000&((data)<<15))
#define  TP_RING_AVAIL_INT_EN_ring_avail_13_en(data)                            (0x00004000&((data)<<14))
#define  TP_RING_AVAIL_INT_EN_ring_avail_12_en(data)                            (0x00002000&((data)<<13))
#define  TP_RING_AVAIL_INT_EN_ring_avail_11_en(data)                            (0x00001000&((data)<<12))
#define  TP_RING_AVAIL_INT_EN_ring_avail_10_en(data)                            (0x00000800&((data)<<11))
#define  TP_RING_AVAIL_INT_EN_ring_avail_9_en(data)                             (0x00000400&((data)<<10))
#define  TP_RING_AVAIL_INT_EN_ring_avail_8_en(data)                             (0x00000200&((data)<<9))
#define  TP_RING_AVAIL_INT_EN_ring_avail_7_en(data)                             (0x00000100&((data)<<8))
#define  TP_RING_AVAIL_INT_EN_ring_avail_6_en(data)                             (0x00000080&((data)<<7))
#define  TP_RING_AVAIL_INT_EN_ring_avail_5_en(data)                             (0x00000040&((data)<<6))
#define  TP_RING_AVAIL_INT_EN_ring_avail_4_en(data)                             (0x00000020&((data)<<5))
#define  TP_RING_AVAIL_INT_EN_ring_avail_3_en(data)                             (0x00000010&((data)<<4))
#define  TP_RING_AVAIL_INT_EN_ring_avail_2_en(data)                             (0x00000008&((data)<<3))
#define  TP_RING_AVAIL_INT_EN_ring_avail_1_en(data)                             (0x00000004&((data)<<2))
#define  TP_RING_AVAIL_INT_EN_ring_avail_0_en(data)                             (0x00000002&((data)<<1))
#define  TP_RING_AVAIL_INT_EN_write_data(data)                                  (0x00000001&(data))
#define  TP_RING_AVAIL_INT_EN_get_rvd(data)                                     ((0xFFFE0000&(data))>>17)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_15_en(data)                        ((0x00010000&(data))>>16)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_14_en(data)                        ((0x00008000&(data))>>15)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_13_en(data)                        ((0x00004000&(data))>>14)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_12_en(data)                        ((0x00002000&(data))>>13)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_11_en(data)                        ((0x00001000&(data))>>12)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_10_en(data)                        ((0x00000800&(data))>>11)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_9_en(data)                         ((0x00000400&(data))>>10)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_8_en(data)                         ((0x00000200&(data))>>9)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_7_en(data)                         ((0x00000100&(data))>>8)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_6_en(data)                         ((0x00000080&(data))>>7)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_5_en(data)                         ((0x00000040&(data))>>6)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_4_en(data)                         ((0x00000020&(data))>>5)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_3_en(data)                         ((0x00000010&(data))>>4)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_2_en(data)                         ((0x00000008&(data))>>3)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_1_en(data)                         ((0x00000004&(data))>>2)
#define  TP_RING_AVAIL_INT_EN_get_ring_avail_0_en(data)                         ((0x00000002&(data))>>1)
#define  TP_RING_AVAIL_INT_EN_get_write_data(data)                              (0x00000001&(data))

#define  TP_RING_FULL_INT_EN                                                    0x18014214
#define  TP_RING_FULL_INT_EN_reg_addr                                           "0xB8014214"
#define  TP_RING_FULL_INT_EN_reg                                                0xB8014214
#define  TP_RING_FULL_INT_EN_inst_addr                                          "0x0042"
#define  TP_RING_FULL_INT_EN_inst                                               0x0042
#define  TP_RING_FULL_INT_EN_rvd_shift                                          (17)
#define  TP_RING_FULL_INT_EN_ring_full_15_en_shift                              (16)
#define  TP_RING_FULL_INT_EN_ring_full_14_en_shift                              (15)
#define  TP_RING_FULL_INT_EN_ring_full_13_en_shift                              (14)
#define  TP_RING_FULL_INT_EN_ring_full_12_en_shift                              (13)
#define  TP_RING_FULL_INT_EN_ring_full_11_en_shift                              (12)
#define  TP_RING_FULL_INT_EN_ring_full_10_en_shift                              (11)
#define  TP_RING_FULL_INT_EN_ring_full_9_en_shift                               (10)
#define  TP_RING_FULL_INT_EN_ring_full_8_en_shift                               (9)
#define  TP_RING_FULL_INT_EN_ring_full_7_en_shift                               (8)
#define  TP_RING_FULL_INT_EN_ring_full_6_en_shift                               (7)
#define  TP_RING_FULL_INT_EN_ring_full_5_en_shift                               (6)
#define  TP_RING_FULL_INT_EN_ring_full_4_en_shift                               (5)
#define  TP_RING_FULL_INT_EN_ring_full_3_en_shift                               (4)
#define  TP_RING_FULL_INT_EN_ring_full_2_en_shift                               (3)
#define  TP_RING_FULL_INT_EN_ring_full_1_en_shift                               (2)
#define  TP_RING_FULL_INT_EN_ring_full_0_en_shift                               (1)
#define  TP_RING_FULL_INT_EN_write_data_shift                                   (0)
#define  TP_RING_FULL_INT_EN_rvd_mask                                           (0xFFFE0000)
#define  TP_RING_FULL_INT_EN_ring_full_15_en_mask                               (0x00010000)
#define  TP_RING_FULL_INT_EN_ring_full_14_en_mask                               (0x00008000)
#define  TP_RING_FULL_INT_EN_ring_full_13_en_mask                               (0x00004000)
#define  TP_RING_FULL_INT_EN_ring_full_12_en_mask                               (0x00002000)
#define  TP_RING_FULL_INT_EN_ring_full_11_en_mask                               (0x00001000)
#define  TP_RING_FULL_INT_EN_ring_full_10_en_mask                               (0x00000800)
#define  TP_RING_FULL_INT_EN_ring_full_9_en_mask                                (0x00000400)
#define  TP_RING_FULL_INT_EN_ring_full_8_en_mask                                (0x00000200)
#define  TP_RING_FULL_INT_EN_ring_full_7_en_mask                                (0x00000100)
#define  TP_RING_FULL_INT_EN_ring_full_6_en_mask                                (0x00000080)
#define  TP_RING_FULL_INT_EN_ring_full_5_en_mask                                (0x00000040)
#define  TP_RING_FULL_INT_EN_ring_full_4_en_mask                                (0x00000020)
#define  TP_RING_FULL_INT_EN_ring_full_3_en_mask                                (0x00000010)
#define  TP_RING_FULL_INT_EN_ring_full_2_en_mask                                (0x00000008)
#define  TP_RING_FULL_INT_EN_ring_full_1_en_mask                                (0x00000004)
#define  TP_RING_FULL_INT_EN_ring_full_0_en_mask                                (0x00000002)
#define  TP_RING_FULL_INT_EN_write_data_mask                                    (0x00000001)
#define  TP_RING_FULL_INT_EN_rvd(data)                                          (0xFFFE0000&((data)<<17))
#define  TP_RING_FULL_INT_EN_ring_full_15_en(data)                              (0x00010000&((data)<<16))
#define  TP_RING_FULL_INT_EN_ring_full_14_en(data)                              (0x00008000&((data)<<15))
#define  TP_RING_FULL_INT_EN_ring_full_13_en(data)                              (0x00004000&((data)<<14))
#define  TP_RING_FULL_INT_EN_ring_full_12_en(data)                              (0x00002000&((data)<<13))
#define  TP_RING_FULL_INT_EN_ring_full_11_en(data)                              (0x00001000&((data)<<12))
#define  TP_RING_FULL_INT_EN_ring_full_10_en(data)                              (0x00000800&((data)<<11))
#define  TP_RING_FULL_INT_EN_ring_full_9_en(data)                               (0x00000400&((data)<<10))
#define  TP_RING_FULL_INT_EN_ring_full_8_en(data)                               (0x00000200&((data)<<9))
#define  TP_RING_FULL_INT_EN_ring_full_7_en(data)                               (0x00000100&((data)<<8))
#define  TP_RING_FULL_INT_EN_ring_full_6_en(data)                               (0x00000080&((data)<<7))
#define  TP_RING_FULL_INT_EN_ring_full_5_en(data)                               (0x00000040&((data)<<6))
#define  TP_RING_FULL_INT_EN_ring_full_4_en(data)                               (0x00000020&((data)<<5))
#define  TP_RING_FULL_INT_EN_ring_full_3_en(data)                               (0x00000010&((data)<<4))
#define  TP_RING_FULL_INT_EN_ring_full_2_en(data)                               (0x00000008&((data)<<3))
#define  TP_RING_FULL_INT_EN_ring_full_1_en(data)                               (0x00000004&((data)<<2))
#define  TP_RING_FULL_INT_EN_ring_full_0_en(data)                               (0x00000002&((data)<<1))
#define  TP_RING_FULL_INT_EN_write_data(data)                                   (0x00000001&(data))
#define  TP_RING_FULL_INT_EN_get_rvd(data)                                      ((0xFFFE0000&(data))>>17)
#define  TP_RING_FULL_INT_EN_get_ring_full_15_en(data)                          ((0x00010000&(data))>>16)
#define  TP_RING_FULL_INT_EN_get_ring_full_14_en(data)                          ((0x00008000&(data))>>15)
#define  TP_RING_FULL_INT_EN_get_ring_full_13_en(data)                          ((0x00004000&(data))>>14)
#define  TP_RING_FULL_INT_EN_get_ring_full_12_en(data)                          ((0x00002000&(data))>>13)
#define  TP_RING_FULL_INT_EN_get_ring_full_11_en(data)                          ((0x00001000&(data))>>12)
#define  TP_RING_FULL_INT_EN_get_ring_full_10_en(data)                          ((0x00000800&(data))>>11)
#define  TP_RING_FULL_INT_EN_get_ring_full_9_en(data)                           ((0x00000400&(data))>>10)
#define  TP_RING_FULL_INT_EN_get_ring_full_8_en(data)                           ((0x00000200&(data))>>9)
#define  TP_RING_FULL_INT_EN_get_ring_full_7_en(data)                           ((0x00000100&(data))>>8)
#define  TP_RING_FULL_INT_EN_get_ring_full_6_en(data)                           ((0x00000080&(data))>>7)
#define  TP_RING_FULL_INT_EN_get_ring_full_5_en(data)                           ((0x00000040&(data))>>6)
#define  TP_RING_FULL_INT_EN_get_ring_full_4_en(data)                           ((0x00000020&(data))>>5)
#define  TP_RING_FULL_INT_EN_get_ring_full_3_en(data)                           ((0x00000010&(data))>>4)
#define  TP_RING_FULL_INT_EN_get_ring_full_2_en(data)                           ((0x00000008&(data))>>3)
#define  TP_RING_FULL_INT_EN_get_ring_full_1_en(data)                           ((0x00000004&(data))>>2)
#define  TP_RING_FULL_INT_EN_get_ring_full_0_en(data)                           ((0x00000002&(data))>>1)
#define  TP_RING_FULL_INT_EN_get_write_data(data)                               (0x00000001&(data))

#define  TP_M2M_RING_LIMIT                                                      0x18014224
#define  TP_M2M_RING_LIMIT_reg_addr                                             "0xB8014224"
#define  TP_M2M_RING_LIMIT_reg                                                  0xB8014224
#define  TP_M2M_RING_LIMIT_inst_addr                                            "0x0043"
#define  TP_M2M_RING_LIMIT_inst                                                 0x0043
#define  TP_M2M_RING_LIMIT_rvd_shift                                            (30)
#define  TP_M2M_RING_LIMIT_ring_limit_shift                                     (3)
#define  TP_M2M_RING_LIMIT_rvd_shift                                            (0)
#define  TP_M2M_RING_LIMIT_rvd_mask                                             (0xC0000000)
#define  TP_M2M_RING_LIMIT_ring_limit_mask                                      (0x3FFFFFF8)
#define  TP_M2M_RING_LIMIT_rvd_mask                                             (0x00000007)
#define  TP_M2M_RING_LIMIT_rvd(data)                                            (0xC0000000&((data)<<30))
#define  TP_M2M_RING_LIMIT_ring_limit(data)                                     (0x3FFFFFF8&((data)<<3))
#define  TP_M2M_RING_LIMIT_rvd(data)                                            (0x00000007&(data))
#define  TP_M2M_RING_LIMIT_get_rvd(data)                                        ((0xC0000000&(data))>>30)
#define  TP_M2M_RING_LIMIT_get_ring_limit(data)                                 ((0x3FFFFFF8&(data))>>3)
#define  TP_M2M_RING_LIMIT_get_rvd(data)                                        (0x00000007&(data))

#define  TP_M2M_RING_BASE                                                       0x18014130
#define  TP_M2M_RING_BASE_reg_addr                                              "0xB8014130"
#define  TP_M2M_RING_BASE_reg                                                   0xB8014130
#define  TP_M2M_RING_BASE_inst_addr                                             "0x0044"
#define  TP_M2M_RING_BASE_inst                                                  0x0044
#define  TP_M2M_RING_BASE_rvd_shift                                             (30)
#define  TP_M2M_RING_BASE_ring_base_shift                                       (3)
#define  TP_M2M_RING_BASE_rvd_shift                                             (0)
#define  TP_M2M_RING_BASE_rvd_mask                                              (0xC0000000)
#define  TP_M2M_RING_BASE_ring_base_mask                                        (0x3FFFFFF8)
#define  TP_M2M_RING_BASE_rvd_mask                                              (0x00000007)
#define  TP_M2M_RING_BASE_rvd(data)                                             (0xC0000000&((data)<<30))
#define  TP_M2M_RING_BASE_ring_base(data)                                       (0x3FFFFFF8&((data)<<3))
#define  TP_M2M_RING_BASE_rvd(data)                                             (0x00000007&(data))
#define  TP_M2M_RING_BASE_get_rvd(data)                                         ((0xC0000000&(data))>>30)
#define  TP_M2M_RING_BASE_get_ring_base(data)                                   ((0x3FFFFFF8&(data))>>3)
#define  TP_M2M_RING_BASE_get_rvd(data)                                         (0x00000007&(data))

#define  TP_M2M_RING_RP                                                         0x18014134
#define  TP_M2M_RING_RP_reg_addr                                                "0xB8014134"
#define  TP_M2M_RING_RP_reg                                                     0xB8014134
#define  TP_M2M_RING_RP_inst_addr                                               "0x0045"
#define  TP_M2M_RING_RP_inst                                                    0x0045
#define  TP_M2M_RING_RP_rvd_shift                                               (30)
#define  TP_M2M_RING_RP_ring_rp_shift                                           (0)
#define  TP_M2M_RING_RP_rvd_mask                                                (0xC0000000)
#define  TP_M2M_RING_RP_ring_rp_mask                                            (0x3FFFFFFF)
#define  TP_M2M_RING_RP_rvd(data)                                               (0xC0000000&((data)<<30))
#define  TP_M2M_RING_RP_ring_rp(data)                                           (0x3FFFFFFF&(data))
#define  TP_M2M_RING_RP_get_rvd(data)                                           ((0xC0000000&(data))>>30)
#define  TP_M2M_RING_RP_get_ring_rp(data)                                       (0x3FFFFFFF&(data))

#define  TP_M2M_RING_WP                                                         0x18014138
#define  TP_M2M_RING_WP_reg_addr                                                "0xB8014138"
#define  TP_M2M_RING_WP_reg                                                     0xB8014138
#define  TP_M2M_RING_WP_inst_addr                                               "0x0046"
#define  TP_M2M_RING_WP_inst                                                    0x0046
#define  TP_M2M_RING_WP_rvd_shift                                               (30)
#define  TP_M2M_RING_WP_ring_wp_shift                                           (0)
#define  TP_M2M_RING_WP_rvd_mask                                                (0xC0000000)
#define  TP_M2M_RING_WP_ring_wp_mask                                            (0x3FFFFFFF)
#define  TP_M2M_RING_WP_rvd(data)                                               (0xC0000000&((data)<<30))
#define  TP_M2M_RING_WP_ring_wp(data)                                           (0x3FFFFFFF&(data))
#define  TP_M2M_RING_WP_get_rvd(data)                                           ((0xC0000000&(data))>>30)
#define  TP_M2M_RING_WP_get_ring_wp(data)                                       (0x3FFFFFFF&(data))

#define  TP_M2M_RING_CTRL                                                       0x1801413C
#define  TP_M2M_RING_CTRL_reg_addr                                              "0xB801413C"
#define  TP_M2M_RING_CTRL_reg                                                   0xB801413C
#define  TP_M2M_RING_CTRL_inst_addr                                             "0x0047"
#define  TP_M2M_RING_CTRL_inst                                                  0x0047
#define  TP_M2M_RING_CTRL_rvd_shift                                             (5)
#define  TP_M2M_RING_CTRL_empty_shift                                           (4)
#define  TP_M2M_RING_CTRL_empty_en_shift                                        (3)
#define  TP_M2M_RING_CTRL_stop_shift                                            (2)
#define  TP_M2M_RING_CTRL_go_shift                                              (1)
#define  TP_M2M_RING_CTRL_write_data_shift                                      (0)
#define  TP_M2M_RING_CTRL_rvd_mask                                              (0xFFFFFFE0)
#define  TP_M2M_RING_CTRL_empty_mask                                            (0x00000010)
#define  TP_M2M_RING_CTRL_empty_en_mask                                         (0x00000008)
#define  TP_M2M_RING_CTRL_stop_mask                                             (0x00000004)
#define  TP_M2M_RING_CTRL_go_mask                                               (0x00000002)
#define  TP_M2M_RING_CTRL_write_data_mask                                       (0x00000001)
#define  TP_M2M_RING_CTRL_rvd(data)                                             (0xFFFFFFE0&((data)<<5))
#define  TP_M2M_RING_CTRL_empty(data)                                           (0x00000010&((data)<<4))
#define  TP_M2M_RING_CTRL_empty_en(data)                                        (0x00000008&((data)<<3))
#define  TP_M2M_RING_CTRL_stop(data)                                            (0x00000004&((data)<<2))
#define  TP_M2M_RING_CTRL_go(data)                                              (0x00000002&((data)<<1))
#define  TP_M2M_RING_CTRL_write_data(data)                                      (0x00000001&(data))
#define  TP_M2M_RING_CTRL_get_rvd(data)                                         ((0xFFFFFFE0&(data))>>5)
#define  TP_M2M_RING_CTRL_get_empty(data)                                       ((0x00000010&(data))>>4)
#define  TP_M2M_RING_CTRL_get_empty_en(data)                                    ((0x00000008&(data))>>3)
#define  TP_M2M_RING_CTRL_get_stop(data)                                        ((0x00000004&(data))>>2)
#define  TP_M2M_RING_CTRL_get_go(data)                                          ((0x00000002&(data))>>1)
#define  TP_M2M_RING_CTRL_get_write_data(data)                                  (0x00000001&(data))

#define  TP_SYNC_POS                                                            0x18014140
#define  TP_SYNC_POS_reg_addr                                                   "0xB8014140"
#define  TP_SYNC_POS_reg                                                        0xB8014140
#define  TP_SYNC_POS_inst_addr                                                  "0x0048"
#define  TP_SYNC_POS_inst                                                       0x0048
#define  TP_SYNC_POS_rvd_shift                                                  (30)
#define  TP_SYNC_POS_sync_pos_shift                                             (0)
#define  TP_SYNC_POS_rvd_mask                                                   (0xC0000000)
#define  TP_SYNC_POS_sync_pos_mask                                              (0x3FFFFFFF)
#define  TP_SYNC_POS_rvd(data)                                                  (0xC0000000&((data)<<30))
#define  TP_SYNC_POS_sync_pos(data)                                             (0x3FFFFFFF&(data))
#define  TP_SYNC_POS_get_rvd(data)                                              ((0xC0000000&(data))>>30)
#define  TP_SYNC_POS_get_sync_pos(data)                                         (0x3FFFFFFF&(data))

#define  TP_DMY_A                                                               0x18014144
#define  TP_DMY_A_reg_addr                                                      "0xB8014144"
#define  TP_DMY_A_reg                                                           0xB8014144
#define  TP_DMY_A_inst_addr                                                     "0x0049"
#define  TP_DMY_A_inst                                                          0x0049
#define  TP_DMY_A_dmy_shift                                                     (0)
#define  TP_DMY_A_dmy_mask                                                      (0xFFFFFFFF)
#define  TP_DMY_A_dmy(data)                                                     (0xFFFFFFFF&(data))
#define  TP_DMY_A_get_dmy(data)                                                 (0xFFFFFFFF&(data))

#define  TP_DMY_B                                                               0x18014148
#define  TP_DMY_B_reg_addr                                                      "0xB8014148"
#define  TP_DMY_B_reg                                                           0xB8014148
#define  TP_DMY_B_inst_addr                                                     "0x004A"
#define  TP_DMY_B_inst                                                          0x004A
#define  TP_DMY_B_dmy_shift                                                     (0)
#define  TP_DMY_B_dmy_mask                                                      (0xFFFFFFFF)
#define  TP_DMY_B_dmy(data)                                                     (0xFFFFFFFF&(data))
#define  TP_DMY_B_get_dmy(data)                                                 (0xFFFFFFFF&(data))

#define  BIST_MODE                                                              0x18014150
#define  BIST_MODE_reg_addr                                                     "0xB8014150"
#define  BIST_MODE_reg                                                          0xB8014150
#define  BIST_MODE_inst_addr                                                    "0x004B"
#define  BIST_MODE_inst                                                         0x004B
#define  BIST_MODE_rvd_shift                                                    (2)
#define  BIST_MODE_ls_shift                                                     (1)
#define  BIST_MODE_bist_mode_tp_shift                                           (0)
#define  BIST_MODE_rvd_mask                                                     (0xFFFFFFFC)
#define  BIST_MODE_ls_mask                                                      (0x00000002)
#define  BIST_MODE_bist_mode_tp_mask                                            (0x00000001)
#define  BIST_MODE_rvd(data)                                                    (0xFFFFFFFC&((data)<<2))
#define  BIST_MODE_ls(data)                                                     (0x00000002&((data)<<1))
#define  BIST_MODE_bist_mode_tp(data)                                           (0x00000001&(data))
#define  BIST_MODE_get_rvd(data)                                                ((0xFFFFFFFC&(data))>>2)
#define  BIST_MODE_get_ls(data)                                                 ((0x00000002&(data))>>1)
#define  BIST_MODE_get_bist_mode_tp(data)                                       (0x00000001&(data))

#define  bist_done                                                              0x18014154
#define  bist_done_reg_addr                                                     "0xB8014154"
#define  bist_done_reg                                                          0xB8014154
#define  bist_done_inst_addr                                                    "0x004C"
#define  bist_done_inst                                                         0x004C
#define  bist_done_rvd_shift                                                    (1)
#define  bist_done_bist_done_tp_shift                                           (0)
#define  bist_done_rvd_mask                                                     (0xFFFFFFFE)
#define  bist_done_bist_done_tp_mask                                            (0x00000001)
#define  bist_done_rvd(data)                                                    (0xFFFFFFFE&((data)<<1))
#define  bist_done_bist_done_tp(data)                                           (0x00000001&(data))
#define  bist_done_get_rvd(data)                                                ((0xFFFFFFFE&(data))>>1)
#define  bist_done_get_bist_done_tp(data)                                       (0x00000001&(data))

#define  bist_fail_group                                                        0x18014158
#define  bist_fail_group_reg_addr                                               "0xB8014158"
#define  bist_fail_group_reg                                                    0xB8014158
#define  bist_fail_group_inst_addr                                              "0x004D"
#define  bist_fail_group_inst                                                   0x004D
#define  bist_fail_group_rvd_shift                                              (1)
#define  bist_fail_group_tp_bist_fail_group_tp_shift                            (0)
#define  bist_fail_group_rvd_mask                                               (0xFFFFFFFE)
#define  bist_fail_group_tp_bist_fail_group_tp_mask                             (0x00000001)
#define  bist_fail_group_rvd(data)                                              (0xFFFFFFFE&((data)<<1))
#define  bist_fail_group_tp_bist_fail_group_tp(data)                            (0x00000001&(data))
#define  bist_fail_group_get_rvd(data)                                          ((0xFFFFFFFE&(data))>>1)
#define  bist_fail_group_get_tp_bist_fail_group_tp(data)                        (0x00000001&(data))

#define  bist_fail                                                              0x1801415C
#define  bist_fail_reg_addr                                                     "0xB801415C"
#define  bist_fail_reg                                                          0xB801415C
#define  bist_fail_inst_addr                                                    "0x004E"
#define  bist_fail_inst                                                         0x004E
#define  bist_fail_rvd_shift                                                    (5)
#define  bist_fail_tp_bist_dma_fail_0_shift                                     (4)
#define  bist_fail_tp_bist_ri_sram_shift                                        (3)
#define  bist_fail_tp_bist_reg_crc_sram_fail_2_shift                            (2)
#define  bist_fail_tp_bist_reg_crc_sram_fail_1_shift                            (1)
#define  bist_fail_tp_bist_reg_crc_sram_fail_0_shift                            (0)
#define  bist_fail_rvd_mask                                                     (0xFFFFFFE0)
#define  bist_fail_tp_bist_dma_fail_0_mask                                      (0x00000010)
#define  bist_fail_tp_bist_ri_sram_mask                                         (0x00000008)
#define  bist_fail_tp_bist_reg_crc_sram_fail_2_mask                             (0x00000004)
#define  bist_fail_tp_bist_reg_crc_sram_fail_1_mask                             (0x00000002)
#define  bist_fail_tp_bist_reg_crc_sram_fail_0_mask                             (0x00000001)
#define  bist_fail_rvd(data)                                                    (0xFFFFFFE0&((data)<<5))
#define  bist_fail_tp_bist_dma_fail_0(data)                                     (0x00000010&((data)<<4))
#define  bist_fail_tp_bist_ri_sram(data)                                        (0x00000008&((data)<<3))
#define  bist_fail_tp_bist_reg_crc_sram_fail_2(data)                            (0x00000004&((data)<<2))
#define  bist_fail_tp_bist_reg_crc_sram_fail_1(data)                            (0x00000002&((data)<<1))
#define  bist_fail_tp_bist_reg_crc_sram_fail_0(data)                            (0x00000001&(data))
#define  bist_fail_get_rvd(data)                                                ((0xFFFFFFE0&(data))>>5)
#define  bist_fail_get_tp_bist_dma_fail_0(data)                                 ((0x00000010&(data))>>4)
#define  bist_fail_get_tp_bist_ri_sram(data)                                    ((0x00000008&(data))>>3)
#define  bist_fail_get_tp_bist_reg_crc_sram_fail_2(data)                        ((0x00000004&(data))>>2)
#define  bist_fail_get_tp_bist_reg_crc_sram_fail_1(data)                        ((0x00000002&(data))>>1)
#define  bist_fail_get_tp_bist_reg_crc_sram_fail_0(data)                        (0x00000001&(data))

#define  DRF_MODE                                                               0x18014164
#define  DRF_MODE_reg_addr                                                      "0xB8014164"
#define  DRF_MODE_reg                                                           0xB8014164
#define  DRF_MODE_inst_addr                                                     "0x004F"
#define  DRF_MODE_inst                                                          0x004F
#define  DRF_MODE_rvd_shift                                                     (1)
#define  DRF_MODE_drf_mode_tp_shift                                             (0)
#define  DRF_MODE_rvd_mask                                                      (0xFFFFFFFE)
#define  DRF_MODE_drf_mode_tp_mask                                              (0x00000001)
#define  DRF_MODE_rvd(data)                                                     (0xFFFFFFFE&((data)<<1))
#define  DRF_MODE_drf_mode_tp(data)                                             (0x00000001&(data))
#define  DRF_MODE_get_rvd(data)                                                 ((0xFFFFFFFE&(data))>>1)
#define  DRF_MODE_get_drf_mode_tp(data)                                         (0x00000001&(data))

#define  drf_resume                                                             0x18014168
#define  drf_resume_reg_addr                                                    "0xB8014168"
#define  drf_resume_reg                                                         0xB8014168
#define  drf_resume_inst_addr                                                   "0x0050"
#define  drf_resume_inst                                                        0x0050
#define  drf_resume_rvd_shift                                                   (1)
#define  drf_resume_drf_resume_tp_shift                                         (0)
#define  drf_resume_rvd_mask                                                    (0xFFFFFFFE)
#define  drf_resume_drf_resume_tp_mask                                          (0x00000001)
#define  drf_resume_rvd(data)                                                   (0xFFFFFFFE&((data)<<1))
#define  drf_resume_drf_resume_tp(data)                                         (0x00000001&(data))
#define  drf_resume_get_rvd(data)                                               ((0xFFFFFFFE&(data))>>1)
#define  drf_resume_get_drf_resume_tp(data)                                     (0x00000001&(data))

#define  drf_done                                                               0x1801416C
#define  drf_done_reg_addr                                                      "0xB801416C"
#define  drf_done_reg                                                           0xB801416C
#define  drf_done_inst_addr                                                     "0x0051"
#define  drf_done_inst                                                          0x0051
#define  drf_done_rvd_shift                                                     (1)
#define  drf_done_drf_done_tp_shift                                             (0)
#define  drf_done_rvd_mask                                                      (0xFFFFFFFE)
#define  drf_done_drf_done_tp_mask                                              (0x00000001)
#define  drf_done_rvd(data)                                                     (0xFFFFFFFE&((data)<<1))
#define  drf_done_drf_done_tp(data)                                             (0x00000001&(data))
#define  drf_done_get_rvd(data)                                                 ((0xFFFFFFFE&(data))>>1)
#define  drf_done_get_drf_done_tp(data)                                         (0x00000001&(data))

#define  drf_pause                                                              0x18014170
#define  drf_pause_reg_addr                                                     "0xB8014170"
#define  drf_pause_reg                                                          0xB8014170
#define  drf_pause_inst_addr                                                    "0x0052"
#define  drf_pause_inst                                                         0x0052
#define  drf_pause_rvd_shift                                                    (1)
#define  drf_pause_drf_pause_tp_shift                                           (0)
#define  drf_pause_rvd_mask                                                     (0xFFFFFFFE)
#define  drf_pause_drf_pause_tp_mask                                            (0x00000001)
#define  drf_pause_rvd(data)                                                    (0xFFFFFFFE&((data)<<1))
#define  drf_pause_drf_pause_tp(data)                                           (0x00000001&(data))
#define  drf_pause_get_rvd(data)                                                ((0xFFFFFFFE&(data))>>1)
#define  drf_pause_get_drf_pause_tp(data)                                       (0x00000001&(data))

#define  drf_fail_group                                                         0x18014174
#define  drf_fail_group_reg_addr                                                "0xB8014174"
#define  drf_fail_group_reg                                                     0xB8014174
#define  drf_fail_group_inst_addr                                               "0x0053"
#define  drf_fail_group_inst                                                    0x0053
#define  drf_fail_group_rvd_shift                                               (1)
#define  drf_fail_group_drf_fail_group_tp_shift                                 (0)
#define  drf_fail_group_rvd_mask                                                (0xFFFFFFFE)
#define  drf_fail_group_drf_fail_group_tp_mask                                  (0x00000001)
#define  drf_fail_group_rvd(data)                                               (0xFFFFFFFE&((data)<<1))
#define  drf_fail_group_drf_fail_group_tp(data)                                 (0x00000001&(data))
#define  drf_fail_group_get_rvd(data)                                           ((0xFFFFFFFE&(data))>>1)
#define  drf_fail_group_get_drf_fail_group_tp(data)                             (0x00000001&(data))

#define  drf_fail                                                               0x18014178
#define  drf_fail_reg_addr                                                      "0xB8014178"
#define  drf_fail_reg                                                           0xB8014178
#define  drf_fail_inst_addr                                                     "0x0054"
#define  drf_fail_inst                                                          0x0054
#define  drf_fail_rvd_shift                                                     (5)
#define  drf_fail_tp_drf_dma_fail_0_shift                                       (4)
#define  drf_fail_tp_drf_ri_sram_fail_shift                                     (3)
#define  drf_fail_tp_drf_reg_crc_sram_fail_2_shift                              (2)
#define  drf_fail_tp_drf_reg_crc_sram_fail_1_shift                              (1)
#define  drf_fail_tp_drf_reg_crc_sram_fail_0_shift                              (0)
#define  drf_fail_rvd_mask                                                      (0xFFFFFFE0)
#define  drf_fail_tp_drf_dma_fail_0_mask                                        (0x00000010)
#define  drf_fail_tp_drf_ri_sram_fail_mask                                      (0x00000008)
#define  drf_fail_tp_drf_reg_crc_sram_fail_2_mask                               (0x00000004)
#define  drf_fail_tp_drf_reg_crc_sram_fail_1_mask                               (0x00000002)
#define  drf_fail_tp_drf_reg_crc_sram_fail_0_mask                               (0x00000001)
#define  drf_fail_rvd(data)                                                     (0xFFFFFFE0&((data)<<5))
#define  drf_fail_tp_drf_dma_fail_0(data)                                       (0x00000010&((data)<<4))
#define  drf_fail_tp_drf_ri_sram_fail(data)                                     (0x00000008&((data)<<3))
#define  drf_fail_tp_drf_reg_crc_sram_fail_2(data)                              (0x00000004&((data)<<2))
#define  drf_fail_tp_drf_reg_crc_sram_fail_1(data)                              (0x00000002&((data)<<1))
#define  drf_fail_tp_drf_reg_crc_sram_fail_0(data)                              (0x00000001&(data))
#define  drf_fail_get_rvd(data)                                                 ((0xFFFFFFE0&(data))>>5)
#define  drf_fail_get_tp_drf_dma_fail_0(data)                                   ((0x00000010&(data))>>4)
#define  drf_fail_get_tp_drf_ri_sram_fail(data)                                 ((0x00000008&(data))>>3)
#define  drf_fail_get_tp_drf_reg_crc_sram_fail_2(data)                          ((0x00000004&(data))>>2)
#define  drf_fail_get_tp_drf_reg_crc_sram_fail_1(data)                          ((0x00000002&(data))>>1)
#define  drf_fail_get_tp_drf_reg_crc_sram_fail_0(data)                          (0x00000001&(data))

#define  bist_dvse                                                              0x18014180
#define  bist_dvse_reg_addr                                                     "0xB8014180"
#define  bist_dvse_reg                                                          0xB8014180
#define  bist_dvse_inst_addr                                                    "0x0055"
#define  bist_dvse_inst                                                         0x0055
#define  bist_dvse_rvd_shift                                                    (5)
#define  bist_dvse_tp_dvse_dma0_shift                                           (4)
#define  bist_dvse_tp_dvse_ri_sram_shift                                        (3)
#define  bist_dvse_tp_dvse_reg_crc_sram2_shift                                  (2)
#define  bist_dvse_tp_dvse_reg_crc_sram1_shift                                  (1)
#define  bist_dvse_tp_dvse_reg_crc_sram0_shift                                  (0)
#define  bist_dvse_rvd_mask                                                     (0xFFFFFFE0)
#define  bist_dvse_tp_dvse_dma0_mask                                            (0x00000010)
#define  bist_dvse_tp_dvse_ri_sram_mask                                         (0x00000008)
#define  bist_dvse_tp_dvse_reg_crc_sram2_mask                                   (0x00000004)
#define  bist_dvse_tp_dvse_reg_crc_sram1_mask                                   (0x00000002)
#define  bist_dvse_tp_dvse_reg_crc_sram0_mask                                   (0x00000001)
#define  bist_dvse_rvd(data)                                                    (0xFFFFFFE0&((data)<<5))
#define  bist_dvse_tp_dvse_dma0(data)                                           (0x00000010&((data)<<4))
#define  bist_dvse_tp_dvse_ri_sram(data)                                        (0x00000008&((data)<<3))
#define  bist_dvse_tp_dvse_reg_crc_sram2(data)                                  (0x00000004&((data)<<2))
#define  bist_dvse_tp_dvse_reg_crc_sram1(data)                                  (0x00000002&((data)<<1))
#define  bist_dvse_tp_dvse_reg_crc_sram0(data)                                  (0x00000001&(data))
#define  bist_dvse_get_rvd(data)                                                ((0xFFFFFFE0&(data))>>5)
#define  bist_dvse_get_tp_dvse_dma0(data)                                       ((0x00000010&(data))>>4)
#define  bist_dvse_get_tp_dvse_ri_sram(data)                                    ((0x00000008&(data))>>3)
#define  bist_dvse_get_tp_dvse_reg_crc_sram2(data)                              ((0x00000004&(data))>>2)
#define  bist_dvse_get_tp_dvse_reg_crc_sram1(data)                              ((0x00000002&(data))>>1)
#define  bist_dvse_get_tp_dvse_reg_crc_sram0(data)                              (0x00000001&(data))

#define  bist_dvs                                                               0x18014184
#define  bist_dvs_reg_addr                                                      "0xB8014184"
#define  bist_dvs_reg                                                           0xB8014184
#define  bist_dvs_inst_addr                                                     "0x0056"
#define  bist_dvs_inst                                                          0x0056
#define  bist_dvs_rvd_shift                                                     (20)
#define  bist_dvs_tp_dvs_dma0_shift                                             (16)
#define  bist_dvs_tp_dvs_ri_sram_shift                                          (12)
#define  bist_dvs_tp_dvs_reg_crc_sram2_shift                                    (8)
#define  bist_dvs_tp_dvs_reg_crc_sram1_shift                                    (4)
#define  bist_dvs_tp_dvs_reg_crc_sram0_shift                                    (0)
#define  bist_dvs_rvd_mask                                                      (0xFFF00000)
#define  bist_dvs_tp_dvs_dma0_mask                                              (0x000F0000)
#define  bist_dvs_tp_dvs_ri_sram_mask                                           (0x0000F000)
#define  bist_dvs_tp_dvs_reg_crc_sram2_mask                                     (0x00000F00)
#define  bist_dvs_tp_dvs_reg_crc_sram1_mask                                     (0x000000F0)
#define  bist_dvs_tp_dvs_reg_crc_sram0_mask                                     (0x0000000F)
#define  bist_dvs_rvd(data)                                                     (0xFFF00000&((data)<<20))
#define  bist_dvs_tp_dvs_dma0(data)                                             (0x000F0000&((data)<<16))
#define  bist_dvs_tp_dvs_ri_sram(data)                                          (0x0000F000&((data)<<12))
#define  bist_dvs_tp_dvs_reg_crc_sram2(data)                                    (0x00000F00&((data)<<8))
#define  bist_dvs_tp_dvs_reg_crc_sram1(data)                                    (0x000000F0&((data)<<4))
#define  bist_dvs_tp_dvs_reg_crc_sram0(data)                                    (0x0000000F&(data))
#define  bist_dvs_get_rvd(data)                                                 ((0xFFF00000&(data))>>20)
#define  bist_dvs_get_tp_dvs_dma0(data)                                         ((0x000F0000&(data))>>16)
#define  bist_dvs_get_tp_dvs_ri_sram(data)                                      ((0x0000F000&(data))>>12)
#define  bist_dvs_get_tp_dvs_reg_crc_sram2(data)                                ((0x00000F00&(data))>>8)
#define  bist_dvs_get_tp_dvs_reg_crc_sram1(data)                                ((0x000000F0&(data))>>4)
#define  bist_dvs_get_tp_dvs_reg_crc_sram0(data)                                (0x0000000F&(data))

#define  TP_TF0_DETECT_1                                                        0x18014188
#define  TP_TF0_DETECT_1_reg_addr                                               "0xB8014188"
#define  TP_TF0_DETECT_1_reg                                                    0xB8014188
#define  TP_TF0_DETECT_1_inst_addr                                              "0x0057"
#define  TP_TF0_DETECT_1_inst                                                   0x0057
#define  TP_TF0_DETECT_1_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_1_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_1_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_1_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_2                                                        0x1801418C
#define  TP_TF0_DETECT_2_reg_addr                                               "0xB801418C"
#define  TP_TF0_DETECT_2_reg                                                    0xB801418C
#define  TP_TF0_DETECT_2_inst_addr                                              "0x0058"
#define  TP_TF0_DETECT_2_inst                                                   0x0058
#define  TP_TF0_DETECT_2_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_2_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_2_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_2_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_3                                                        0x18014190
#define  TP_TF0_DETECT_3_reg_addr                                               "0xB8014190"
#define  TP_TF0_DETECT_3_reg                                                    0xB8014190
#define  TP_TF0_DETECT_3_inst_addr                                              "0x0059"
#define  TP_TF0_DETECT_3_inst                                                   0x0059
#define  TP_TF0_DETECT_3_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_3_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_3_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_3_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_4                                                        0x18014194
#define  TP_TF0_DETECT_4_reg_addr                                               "0xB8014194"
#define  TP_TF0_DETECT_4_reg                                                    0xB8014194
#define  TP_TF0_DETECT_4_inst_addr                                              "0x005A"
#define  TP_TF0_DETECT_4_inst                                                   0x005A
#define  TP_TF0_DETECT_4_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_4_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_4_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_4_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_5                                                        0x18014198
#define  TP_TF0_DETECT_5_reg_addr                                               "0xB8014198"
#define  TP_TF0_DETECT_5_reg                                                    0xB8014198
#define  TP_TF0_DETECT_5_inst_addr                                              "0x005B"
#define  TP_TF0_DETECT_5_inst                                                   0x005B
#define  TP_TF0_DETECT_5_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_5_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_5_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_5_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_6                                                        0x1801419C
#define  TP_TF0_DETECT_6_reg_addr                                               "0xB801419C"
#define  TP_TF0_DETECT_6_reg                                                    0xB801419C
#define  TP_TF0_DETECT_6_inst_addr                                              "0x005C"
#define  TP_TF0_DETECT_6_inst                                                   0x005C
#define  TP_TF0_DETECT_6_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_6_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_6_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_6_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_7                                                        0x180141A0
#define  TP_TF0_DETECT_7_reg_addr                                               "0xB80141A0"
#define  TP_TF0_DETECT_7_reg                                                    0xB80141A0
#define  TP_TF0_DETECT_7_inst_addr                                              "0x005D"
#define  TP_TF0_DETECT_7_inst                                                   0x005D
#define  TP_TF0_DETECT_7_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_7_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_7_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_7_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_8                                                        0x180141A4
#define  TP_TF0_DETECT_8_reg_addr                                               "0xB80141A4"
#define  TP_TF0_DETECT_8_reg                                                    0xB80141A4
#define  TP_TF0_DETECT_8_inst_addr                                              "0x005E"
#define  TP_TF0_DETECT_8_inst                                                   0x005E
#define  TP_TF0_DETECT_8_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_8_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_8_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_8_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_9                                                        0x180141A8
#define  TP_TF0_DETECT_9_reg_addr                                               "0xB80141A8"
#define  TP_TF0_DETECT_9_reg                                                    0xB80141A8
#define  TP_TF0_DETECT_9_inst_addr                                              "0x005F"
#define  TP_TF0_DETECT_9_inst                                                   0x005F
#define  TP_TF0_DETECT_9_delay_cnt_status_shift                                 (0)
#define  TP_TF0_DETECT_9_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF0_DETECT_9_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_9_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_10                                                       0x180141AC
#define  TP_TF0_DETECT_10_reg_addr                                              "0xB80141AC"
#define  TP_TF0_DETECT_10_reg                                                   0xB80141AC
#define  TP_TF0_DETECT_10_inst_addr                                             "0x0060"
#define  TP_TF0_DETECT_10_inst                                                  0x0060
#define  TP_TF0_DETECT_10_delay_cnt_status_shift                                (0)
#define  TP_TF0_DETECT_10_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF0_DETECT_10_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_10_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_11                                                       0x180141B0
#define  TP_TF0_DETECT_11_reg_addr                                              "0xB80141B0"
#define  TP_TF0_DETECT_11_reg                                                   0xB80141B0
#define  TP_TF0_DETECT_11_inst_addr                                             "0x0061"
#define  TP_TF0_DETECT_11_inst                                                  0x0061
#define  TP_TF0_DETECT_11_delay_cnt_status_shift                                (0)
#define  TP_TF0_DETECT_11_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF0_DETECT_11_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_11_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_12                                                       0x180141B4
#define  TP_TF0_DETECT_12_reg_addr                                              "0xB80141B4"
#define  TP_TF0_DETECT_12_reg                                                   0xB80141B4
#define  TP_TF0_DETECT_12_inst_addr                                             "0x0062"
#define  TP_TF0_DETECT_12_inst                                                  0x0062
#define  TP_TF0_DETECT_12_delay_cnt_status_shift                                (0)
#define  TP_TF0_DETECT_12_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF0_DETECT_12_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF0_DETECT_12_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF0_DETECT_13                                                       0x180141B8
#define  TP_TF0_DETECT_13_reg_addr                                              "0xB80141B8"
#define  TP_TF0_DETECT_13_reg                                                   0xB80141B8
#define  TP_TF0_DETECT_13_inst_addr                                             "0x0063"
#define  TP_TF0_DETECT_13_inst                                                  0x0063
#define  TP_TF0_DETECT_13_rvd_shift                                             (24)
#define  TP_TF0_DETECT_13_delay_cnt_status_shift                                (0)
#define  TP_TF0_DETECT_13_rvd_mask                                              (0xFF000000)
#define  TP_TF0_DETECT_13_delay_cnt_status_mask                                 (0x00FFFFFF)
#define  TP_TF0_DETECT_13_rvd(data)                                             (0xFF000000&((data)<<24))
#define  TP_TF0_DETECT_13_delay_cnt_status(data)                                (0x00FFFFFF&(data))
#define  TP_TF0_DETECT_13_get_rvd(data)                                         ((0xFF000000&(data))>>24)
#define  TP_TF0_DETECT_13_get_delay_cnt_status(data)                            (0x00FFFFFF&(data))

#define  TP_TF0_DETECT_CTRL                                                     0x180141BC
#define  TP_TF0_DETECT_CTRL_reg_addr                                            "0xB80141BC"
#define  TP_TF0_DETECT_CTRL_reg                                                 0xB80141BC
#define  TP_TF0_DETECT_CTRL_inst_addr                                           "0x0064"
#define  TP_TF0_DETECT_CTRL_inst                                                0x0064
#define  TP_TF0_DETECT_CTRL_rvd_shift                                           (10)
#define  TP_TF0_DETECT_CTRL_detect_delay_shift                                  (2)
#define  TP_TF0_DETECT_CTRL_detect_en_shift                                     (1)
#define  TP_TF0_DETECT_CTRL_detect_start_shift                                  (0)
#define  TP_TF0_DETECT_CTRL_rvd_mask                                            (0xFFFFFC00)
#define  TP_TF0_DETECT_CTRL_detect_delay_mask                                   (0x000003FC)
#define  TP_TF0_DETECT_CTRL_detect_en_mask                                      (0x00000002)
#define  TP_TF0_DETECT_CTRL_detect_start_mask                                   (0x00000001)
#define  TP_TF0_DETECT_CTRL_rvd(data)                                           (0xFFFFFC00&((data)<<10))
#define  TP_TF0_DETECT_CTRL_detect_delay(data)                                  (0x000003FC&((data)<<2))
#define  TP_TF0_DETECT_CTRL_detect_en(data)                                     (0x00000002&((data)<<1))
#define  TP_TF0_DETECT_CTRL_detect_start(data)                                  (0x00000001&(data))
#define  TP_TF0_DETECT_CTRL_get_rvd(data)                                       ((0xFFFFFC00&(data))>>10)
#define  TP_TF0_DETECT_CTRL_get_detect_delay(data)                              ((0x000003FC&(data))>>2)
#define  TP_TF0_DETECT_CTRL_get_detect_en(data)                                 ((0x00000002&(data))>>1)
#define  TP_TF0_DETECT_CTRL_get_detect_start(data)                              (0x00000001&(data))

#define  TP_TF1_DETECT_1                                                        0x180141C0
#define  TP_TF1_DETECT_1_reg_addr                                               "0xB80141C0"
#define  TP_TF1_DETECT_1_reg                                                    0xB80141C0
#define  TP_TF1_DETECT_1_inst_addr                                              "0x0065"
#define  TP_TF1_DETECT_1_inst                                                   0x0065
#define  TP_TF1_DETECT_1_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_1_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_1_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_1_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_2                                                        0x180141C4
#define  TP_TF1_DETECT_2_reg_addr                                               "0xB80141C4"
#define  TP_TF1_DETECT_2_reg                                                    0xB80141C4
#define  TP_TF1_DETECT_2_inst_addr                                              "0x0066"
#define  TP_TF1_DETECT_2_inst                                                   0x0066
#define  TP_TF1_DETECT_2_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_2_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_2_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_2_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_3                                                        0x180141C8
#define  TP_TF1_DETECT_3_reg_addr                                               "0xB80141C8"
#define  TP_TF1_DETECT_3_reg                                                    0xB80141C8
#define  TP_TF1_DETECT_3_inst_addr                                              "0x0067"
#define  TP_TF1_DETECT_3_inst                                                   0x0067
#define  TP_TF1_DETECT_3_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_3_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_3_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_3_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_4                                                        0x180141CC
#define  TP_TF1_DETECT_4_reg_addr                                               "0xB80141CC"
#define  TP_TF1_DETECT_4_reg                                                    0xB80141CC
#define  TP_TF1_DETECT_4_inst_addr                                              "0x0068"
#define  TP_TF1_DETECT_4_inst                                                   0x0068
#define  TP_TF1_DETECT_4_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_4_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_4_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_4_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_5                                                        0x180141D0
#define  TP_TF1_DETECT_5_reg_addr                                               "0xB80141D0"
#define  TP_TF1_DETECT_5_reg                                                    0xB80141D0
#define  TP_TF1_DETECT_5_inst_addr                                              "0x0069"
#define  TP_TF1_DETECT_5_inst                                                   0x0069
#define  TP_TF1_DETECT_5_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_5_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_5_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_5_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_6                                                        0x180141D4
#define  TP_TF1_DETECT_6_reg_addr                                               "0xB80141D4"
#define  TP_TF1_DETECT_6_reg                                                    0xB80141D4
#define  TP_TF1_DETECT_6_inst_addr                                              "0x006A"
#define  TP_TF1_DETECT_6_inst                                                   0x006A
#define  TP_TF1_DETECT_6_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_6_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_6_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_6_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_7                                                        0x180141D8
#define  TP_TF1_DETECT_7_reg_addr                                               "0xB80141D8"
#define  TP_TF1_DETECT_7_reg                                                    0xB80141D8
#define  TP_TF1_DETECT_7_inst_addr                                              "0x006B"
#define  TP_TF1_DETECT_7_inst                                                   0x006B
#define  TP_TF1_DETECT_7_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_7_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_7_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_7_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_8                                                        0x180141DC
#define  TP_TF1_DETECT_8_reg_addr                                               "0xB80141DC"
#define  TP_TF1_DETECT_8_reg                                                    0xB80141DC
#define  TP_TF1_DETECT_8_inst_addr                                              "0x006C"
#define  TP_TF1_DETECT_8_inst                                                   0x006C
#define  TP_TF1_DETECT_8_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_8_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_8_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_8_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_9                                                        0x180141E0
#define  TP_TF1_DETECT_9_reg_addr                                               "0xB80141E0"
#define  TP_TF1_DETECT_9_reg                                                    0xB80141E0
#define  TP_TF1_DETECT_9_inst_addr                                              "0x006D"
#define  TP_TF1_DETECT_9_inst                                                   0x006D
#define  TP_TF1_DETECT_9_delay_cnt_status_shift                                 (0)
#define  TP_TF1_DETECT_9_delay_cnt_status_mask                                  (0xFFFFFFFF)
#define  TP_TF1_DETECT_9_delay_cnt_status(data)                                 (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_9_get_delay_cnt_status(data)                             (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_10                                                       0x180141E4
#define  TP_TF1_DETECT_10_reg_addr                                              "0xB80141E4"
#define  TP_TF1_DETECT_10_reg                                                   0xB80141E4
#define  TP_TF1_DETECT_10_inst_addr                                             "0x006E"
#define  TP_TF1_DETECT_10_inst                                                  0x006E
#define  TP_TF1_DETECT_10_delay_cnt_status_shift                                (0)
#define  TP_TF1_DETECT_10_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF1_DETECT_10_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_10_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_11                                                       0x180141E8
#define  TP_TF1_DETECT_11_reg_addr                                              "0xB80141E8"
#define  TP_TF1_DETECT_11_reg                                                   0xB80141E8
#define  TP_TF1_DETECT_11_inst_addr                                             "0x006F"
#define  TP_TF1_DETECT_11_inst                                                  0x006F
#define  TP_TF1_DETECT_11_delay_cnt_status_shift                                (0)
#define  TP_TF1_DETECT_11_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF1_DETECT_11_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_11_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_12                                                       0x180141EC
#define  TP_TF1_DETECT_12_reg_addr                                              "0xB80141EC"
#define  TP_TF1_DETECT_12_reg                                                   0xB80141EC
#define  TP_TF1_DETECT_12_inst_addr                                             "0x0070"
#define  TP_TF1_DETECT_12_inst                                                  0x0070
#define  TP_TF1_DETECT_12_delay_cnt_status_shift                                (0)
#define  TP_TF1_DETECT_12_delay_cnt_status_mask                                 (0xFFFFFFFF)
#define  TP_TF1_DETECT_12_delay_cnt_status(data)                                (0xFFFFFFFF&(data))
#define  TP_TF1_DETECT_12_get_delay_cnt_status(data)                            (0xFFFFFFFF&(data))

#define  TP_TF1_DETECT_13                                                       0x180141F0
#define  TP_TF1_DETECT_13_reg_addr                                              "0xB80141F0"
#define  TP_TF1_DETECT_13_reg                                                   0xB80141F0
#define  TP_TF1_DETECT_13_inst_addr                                             "0x0071"
#define  TP_TF1_DETECT_13_inst                                                  0x0071
#define  TP_TF1_DETECT_13_rvd_shift                                             (24)
#define  TP_TF1_DETECT_13_delay_cnt_status_shift                                (0)
#define  TP_TF1_DETECT_13_rvd_mask                                              (0xFF000000)
#define  TP_TF1_DETECT_13_delay_cnt_status_mask                                 (0x00FFFFFF)
#define  TP_TF1_DETECT_13_rvd(data)                                             (0xFF000000&((data)<<24))
#define  TP_TF1_DETECT_13_delay_cnt_status(data)                                (0x00FFFFFF&(data))
#define  TP_TF1_DETECT_13_get_rvd(data)                                         ((0xFF000000&(data))>>24)
#define  TP_TF1_DETECT_13_get_delay_cnt_status(data)                            (0x00FFFFFF&(data))

#define  TP_TF1_DETECT_CTRL                                                     0x180141F4
#define  TP_TF1_DETECT_CTRL_reg_addr                                            "0xB80141F4"
#define  TP_TF1_DETECT_CTRL_reg                                                 0xB80141F4
#define  TP_TF1_DETECT_CTRL_inst_addr                                           "0x0072"
#define  TP_TF1_DETECT_CTRL_inst                                                0x0072
#define  TP_TF1_DETECT_CTRL_rvd_shift                                           (10)
#define  TP_TF1_DETECT_CTRL_detect_delay_shift                                  (2)
#define  TP_TF1_DETECT_CTRL_detect_en_shift                                     (1)
#define  TP_TF1_DETECT_CTRL_detect_start_shift                                  (0)
#define  TP_TF1_DETECT_CTRL_rvd_mask                                            (0xFFFFFC00)
#define  TP_TF1_DETECT_CTRL_detect_delay_mask                                   (0x000003FC)
#define  TP_TF1_DETECT_CTRL_detect_en_mask                                      (0x00000002)
#define  TP_TF1_DETECT_CTRL_detect_start_mask                                   (0x00000001)
#define  TP_TF1_DETECT_CTRL_rvd(data)                                           (0xFFFFFC00&((data)<<10))
#define  TP_TF1_DETECT_CTRL_detect_delay(data)                                  (0x000003FC&((data)<<2))
#define  TP_TF1_DETECT_CTRL_detect_en(data)                                     (0x00000002&((data)<<1))
#define  TP_TF1_DETECT_CTRL_detect_start(data)                                  (0x00000001&(data))
#define  TP_TF1_DETECT_CTRL_get_rvd(data)                                       ((0xFFFFFC00&(data))>>10)
#define  TP_TF1_DETECT_CTRL_get_detect_delay(data)                              ((0x000003FC&(data))>>2)
#define  TP_TF1_DETECT_CTRL_get_detect_en(data)                                 ((0x00000002&(data))>>1)
#define  TP_TF1_DETECT_CTRL_get_detect_start(data)                              (0x00000001&(data))

#define  TP_dummy_1                                                             0x180141F8
#define  TP_dummy_1_reg_addr                                                    "0xB80141F8"
#define  TP_dummy_1_reg                                                         0xB80141F8
#define  TP_dummy_1_inst_addr                                                   "0x0073"
#define  TP_dummy_1_inst                                                        0x0073
#define  TP_dummy_1_dummy_shift                                                 (0)
#define  TP_dummy_1_dummy_mask                                                  (0xFFFFFFFF)
#define  TP_dummy_1_dummy(data)                                                 (0xFFFFFFFF&(data))
#define  TP_dummy_1_get_dummy(data)                                             (0xFFFFFFFF&(data))

#define  TP_dummy_2                                                             0x180141FC
#define  TP_dummy_2_reg_addr                                                    "0xB80141FC"
#define  TP_dummy_2_reg                                                         0xB80141FC
#define  TP_dummy_2_inst_addr                                                   "0x0074"
#define  TP_dummy_2_inst                                                        0x0074
#define  TP_dummy_2_dummy_shift                                                 (0)
#define  TP_dummy_2_dummy_mask                                                  (0xFFFFFFFF)
#define  TP_dummy_2_dummy(data)                                                 (0xFFFFFFFF&(data))
#define  TP_dummy_2_get_dummy(data)                                             (0xFFFFFFFF&(data))

#define  TP_DEBUG                                                               0x18014200
#define  TP_DEBUG_reg_addr                                                      "0xB8014200"
#define  TP_DEBUG_reg                                                           0xB8014200
#define  TP_DEBUG_inst_addr                                                     "0x0075"
#define  TP_DEBUG_inst                                                          0x0075
#define  TP_DEBUG_rvd_shift                                                     (8)
#define  TP_DEBUG_dv_verify_only_shift                                          (7)
#define  TP_DEBUG_tp_sram_sleep_off_shift                                       (6)
#define  TP_DEBUG_tp_pkt_sram_addr_rst_sel_shift                                (5)
#define  TP_DEBUG_dbg_mode_shift                                                (0)
#define  TP_DEBUG_rvd_mask                                                      (0xFFFFFF00)
#define  TP_DEBUG_dv_verify_only_mask                                           (0x00000080)
#define  TP_DEBUG_tp_sram_sleep_off_mask                                        (0x00000040)
#define  TP_DEBUG_tp_pkt_sram_addr_rst_sel_mask                                 (0x00000020)
#define  TP_DEBUG_dbg_mode_mask                                                 (0x0000001F)
#define  TP_DEBUG_rvd(data)                                                     (0xFFFFFF00&((data)<<8))
#define  TP_DEBUG_dv_verify_only(data)                                          (0x00000080&((data)<<7))
#define  TP_DEBUG_tp_sram_sleep_off(data)                                       (0x00000040&((data)<<6))
#define  TP_DEBUG_tp_pkt_sram_addr_rst_sel(data)                                (0x00000020&((data)<<5))
#define  TP_DEBUG_dbg_mode(data)                                                (0x0000001F&(data))
#define  TP_DEBUG_get_rvd(data)                                                 ((0xFFFFFF00&(data))>>8)
#define  TP_DEBUG_get_dv_verify_only(data)                                      ((0x00000080&(data))>>7)
#define  TP_DEBUG_get_tp_sram_sleep_off(data)                                   ((0x00000040&(data))>>6)
#define  TP_DEBUG_get_tp_pkt_sram_addr_rst_sel(data)                            ((0x00000020&(data))>>5)
#define  TP_DEBUG_get_dbg_mode(data)                                            (0x0000001F&(data))

#endif 
