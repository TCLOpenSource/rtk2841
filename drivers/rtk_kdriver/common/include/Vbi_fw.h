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

#ifndef _VBI_REG_H_INCLUDED_
#define _VBI_REG_H_INCLUDED_

//#define _VBI_USE_STRUCT
#ifdef _VBI_USE_STRUCT

typedef struct
{
        unsigned int  vbisl_out_mux_manual_en:1;
        unsigned int  vbisl_out_auto_tt_vps_sel:1;
        unsigned int  vbisl_out_mux_sel:2;
        unsigned int  vbi_dma_stop:1;
        unsigned int  vbi_dma_stop_en:1;
        unsigned int  reserved_0:18;
        unsigned int  vbisl0_src_sel:1;
        unsigned int  vbisl0_sys625i:1;
        unsigned int  vbisl0_fieldi_inv:1;
        unsigned int  vbisl2_lcnt_field_inv:1;
        unsigned int  reserved_1:4;
}VBISL0;

typedef struct
{
        unsigned int  tt_vbi_cc_caposc_frun_en:1;
        unsigned int  tt_vbi_cc_vote_en:1;
        unsigned int  tt_vbi_cc_vote_sel:1;
        unsigned int  reserved_0:1;
        unsigned int  tt_vbi_cc_vote_num:4;
        unsigned int  reserved_1:4;
        unsigned int  tt_vbi_cc_data_swing_gain:4;
        unsigned int  tt_vbi_cc_blank_offset:16;
}TT_VBI_CC_CTRL0;

typedef struct
{
        unsigned int  find_start:1;
        unsigned int  reserved_0:6;
        unsigned int  tt_vbi_cc_st_correlation_en:1;
        unsigned int  tt_vbi_cc_st_correlation_thl:8;
        unsigned int  reserved_1:16;
}TT_VBI_CC_CTRL1;

typedef struct
{
        unsigned int  tt_vbi_cc_out_hcount_en:1;
        unsigned int  reserved_0:5;
        unsigned int  tt_vbi_cc_out_hcount_start:10;
        unsigned int  reserved_1:6;
        unsigned int  tt_vbi_cc_out_hcount_end:10;
}TT_VBI_CC_CTRL2;

typedef struct
{
        unsigned int  reserved_0:23;
        unsigned int  cc_pattern_field:1;
        unsigned int  reserved_1:2;
        unsigned int  find_start_num:6;
}VBI_CC_PATTERN_COMPARE_1;

typedef struct
{
        unsigned int  cc_compare_data:32;
}VBI_CC_PATTERN_COMPARE_2;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  vbi_vount_shift_en:1;
        unsigned int  reserved_1:3;
        unsigned int  vbi_vount_shift_field_inv:1;
        unsigned int  reserved_2:1;
        unsigned int  vbi_vount_shift_num:11;
}VBI_VOUNT_SHIFT;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  cgms_c0_debounce_sel:3;
        unsigned int  reserved_1:6;
        unsigned int  cgms_c0_slicer_dcl:10;
        unsigned int  reserved_2:2;
        unsigned int  cgms_c0_lpf_sel:2;
        unsigned int  cgms_c0_slicer_ms:2;
        unsigned int  cgms_c0_adap_slvl_en:1;
        unsigned int  cgms_c0_slicen:1;
}CGMS_C0;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  cgms_c1_actline_t:10;
        unsigned int  reserved_1:6;
        unsigned int  cgms_c1_actline_b:10;
}CGMS_C1;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  cgms_c2_dcdet_st:10;
        unsigned int  reserved_1:6;
        unsigned int  cgms_c2_dcdet_end:10;
}CGMS_C2;

typedef struct
{
        unsigned int  reserved_0:7;
        unsigned int  cgms_auto_period_en:1;
        unsigned int  reserved_1:2;
        unsigned int  cgms_period_cnt:10;
        unsigned int  reserved_2:2;
        unsigned int  cgms_c3_lv_dc_th:10;
}CGMS_C3;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  vbisl16_cgms_int_en:1;
        unsigned int  reserved_1:3;
        unsigned int  cgms_c4_cgms_vld:1;
        unsigned int  reserved_2:4;
        unsigned int  cgms_c4_cgmsdata:20;
}CGMS_C4;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  cgms_c5_min_period:8;
        unsigned int  cgms_c5_max_period:8;
        unsigned int  cgms_c5_period:8;
}CGMS_C5;

typedef struct
{
        unsigned int  reserved_0:16;
        unsigned int  tt_ttdata41:8;
        unsigned int  tt_ttdata40:8;
}TT_VBI_TT_DATA00;

typedef struct
{
        unsigned int  tt_ttdata39:8;
        unsigned int  tt_ttdata38:8;
        unsigned int  tt_ttdata37:8;
        unsigned int  tt_ttdata36:8;
}TT_VBI_TT_DATA01;

typedef struct
{
        unsigned int  tt_ttdata35:8;
        unsigned int  tt_ttdata34:8;
        unsigned int  tt_ttdata33:8;
        unsigned int  tt_ttdata32:8;
}TT_VBI_TT_DATA02;

typedef struct
{
        unsigned int  tt_ttdata31:8;
        unsigned int  tt_ttdata30:8;
        unsigned int  tt_ttdata29:8;
        unsigned int  tt_ttdata28:8;
}TT_VBI_TT_DATA03;

typedef struct
{
        unsigned int  tt_ttdata27:8;
        unsigned int  tt_ttdata26:8;
        unsigned int  tt_ttdata25:8;
        unsigned int  tt_ttdata24:8;
}TT_VBI_TT_DATA04;

typedef struct
{
        unsigned int  tt_ttdata23:8;
        unsigned int  tt_ttdata22:8;
        unsigned int  tt_ttdata21:8;
        unsigned int  tt_ttdata20:8;
}TT_VBI_TT_DATA05;

typedef struct
{
        unsigned int  tt_ttdata19:8;
        unsigned int  tt_ttdata18:8;
        unsigned int  tt_ttdata17:8;
        unsigned int  tt_ttdata16:8;
}TT_VBI_TT_DATA06;

typedef struct
{
        unsigned int  tt_ttdata15:8;
        unsigned int  tt_ttdata14:8;
        unsigned int  tt_ttdata13:8;
        unsigned int  tt_ttdata12:8;
}TT_VBI_TT_DATA07;

typedef struct
{
        unsigned int  tt_ttdata11:8;
        unsigned int  tt_ttdata10:8;
        unsigned int  tt_ttdata9:8;
        unsigned int  tt_ttdata8:8;
}TT_VBI_TT_DATA08;

typedef struct
{
        unsigned int  tt_ttdata7:8;
        unsigned int  tt_ttdata6:8;
        unsigned int  tt_ttdata5:8;
        unsigned int  tt_ttdata4:8;
}TT_VBI_TT_DATA09;

typedef struct
{
        unsigned int  tt_ttdata3:8;
        unsigned int  tt_ttdata2:8;
        unsigned int  tt_ttdata1:8;
        unsigned int  tt_ttdata0:8;
}TT_VBI_TT_DATA10;

typedef struct
{
        unsigned int  tt_vbi_data_hlvl_wss:8;
        unsigned int  tt_vbi_data_hlvl:8;
        unsigned int  tt_start_code:8;
        unsigned int  reserved_0:1;
        unsigned int  tt_adap_slvl_en:2;
        unsigned int  tt_vbi_muxout:1;
        unsigned int  tt_vbi_hsyncout:1;
        unsigned int  tt_vbi_long_st_sel:1;
        unsigned int  tt_vbi_st_err_ignored:1;
        unsigned int  tt_vbi_en:1;
}TT_VBI_Control_Register;

typedef struct
{
        unsigned int  tt_vbil8e:4;
        unsigned int  tt_vbil8o:4;
        unsigned int  tt_vbil7e:4;
        unsigned int  tt_vbil7o:4;
        unsigned int  tt_vbil6e:4;
        unsigned int  tt_vbil6o:4;
        unsigned int  tt_vbil5e:4;
        unsigned int  tt_vbil5o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8;

typedef struct
{
        unsigned int  tt_vbil12e:4;
        unsigned int  tt_vbil12o:4;
        unsigned int  tt_vbil11e:4;
        unsigned int  tt_vbil11o:4;
        unsigned int  tt_vbil10e:4;
        unsigned int  tt_vbil10o:4;
        unsigned int  tt_vbil9e:4;
        unsigned int  tt_vbil9o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12;

typedef struct
{
        unsigned int  tt_vbil16e:4;
        unsigned int  tt_vbil16o:4;
        unsigned int  tt_vbil15e:4;
        unsigned int  tt_vbil15o:4;
        unsigned int  tt_vbil14e:4;
        unsigned int  tt_vbil14o:4;
        unsigned int  tt_vbil13e:4;
        unsigned int  tt_vbil13o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16;

typedef struct
{
        unsigned int  tt_vbil20e:4;
        unsigned int  tt_vbil20o:4;
        unsigned int  tt_vbil19e:4;
        unsigned int  tt_vbil19o:4;
        unsigned int  tt_vbil18e:4;
        unsigned int  tt_vbil18o:4;
        unsigned int  tt_vbil17e:4;
        unsigned int  tt_vbil17o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20;

typedef struct
{
        unsigned int  tt_vbil24e:4;
        unsigned int  tt_vbil24o:4;
        unsigned int  tt_vbil23e:4;
        unsigned int  tt_vbil23o:4;
        unsigned int  tt_vbil22e:4;
        unsigned int  tt_vbil22o:4;
        unsigned int  tt_vbil21e:4;
        unsigned int  tt_vbil21o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24;

typedef struct
{
        unsigned int  reserved_0:8;
        unsigned int  tt_vbivpsl16e:4;
        unsigned int  tt_vbivps16o:4;
        unsigned int  tt_vbil26e:4;
        unsigned int  tt_vbil26o:4;
        unsigned int  tt_vbil25e:4;
        unsigned int  tt_vbil25o:4;
}TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26;

typedef struct
{
        unsigned int  reserved_0:7;
        unsigned int  tt_vbi_slicer_level_iir:9;
        unsigned int  tt_vbi_vps_lpfil_gain:4;
        unsigned int  tt_vbi_wss625_lpfil_gain:4;
        unsigned int  tt_vbi_cc_lpfil_gain:4;
        unsigned int  tt_vbi_tele_lpfil_gain:4;
}TT_VBI_LOOP_FILTER_I_GAIN_REGISTER;

typedef struct
{
        unsigned int  tt_vbi_teletext_dto:16;
        unsigned int  tt_vbi_caption_dto:16;
}TT_VBI_DTO_REGISTER1;

typedef struct
{
        unsigned int  tt_vbi_vps_dto:16;
        unsigned int  tt_vbi_wss625_dto:16;
}TT_VBI_DTO_REGISTER2;

typedef struct
{
        unsigned int  tt_caption_frame_start:8;
        unsigned int  tt_teletext_frame_start:8;
        unsigned int  tt_wss625_frame_start:8;
        unsigned int  tt_vps_frame_start:8;
}TT_VBI_DTO_FRAME_START;

typedef struct
{
        unsigned int  tt_wssdata1:8;
        unsigned int  tt_wssdata0:8;
        unsigned int  tt_ccdata1:8;
        unsigned int  tt_ccdata0:8;
}TT_VBI_CCWSS_DATA;

typedef struct
{
        unsigned int  tt_data_field_ind:1;
        unsigned int  tt_wss_int_en:1;
        unsigned int  tt_cc_int_en:1;
        unsigned int  tt_vps_int_en:1;
        unsigned int  tt_tt_int_en:1;
        unsigned int  reserved_0:3;
        unsigned int  tt_int_clean:1;
        unsigned int  wss_int_clean:1;
        unsigned int  cc_int_clean:1;
        unsigned int  vps_int_clean:1;
        unsigned int  tt_tt_rdy:1;
        unsigned int  tt_wss_rdy:1;
        unsigned int  tt_cc_rdy:1;
        unsigned int  tt_vps_rdy:1;
        unsigned int  tt_vbi_noise_th:8;
        unsigned int  tt_wssdata2:8;
}TT_VBI_DATA_STATUS;

typedef struct
{
        unsigned int  tt_vbi_caption_start:8;
        unsigned int  tt_vbi_teletext_start:8;
        unsigned int  tt_vbi_wss625_start:8;
        unsigned int  tt_vbi_vps_start:8;
}TT_VBI_START;

typedef struct
{
        unsigned int  reserved_0:15;
        unsigned int  tt_vbi_wss_slice_level:9;
        unsigned int  tt_vpsdata3:8;
}TT_VPS_DATA3;

typedef struct
{
        unsigned int  tt_vpsdata2:32;
}TT_VPS_DATA2;

typedef struct
{
        unsigned int  tt_vpsdata1:32;
}TT_VPS_DATA1;

typedef struct
{
        unsigned int  tt_vpsdata0:32;
}TT_VPS_DATA0;

typedef struct
{
        unsigned int  tt_vbi_data_hold_cyc:1;
        unsigned int  reserved_0:1;
        unsigned int  tt_vbi_fe_lpf_sel:2;
        unsigned int  filter_gain_sel:2;
        unsigned int  filter_coe_en:1;
        unsigned int  tt_vbi_st_correlation_en:1;
        unsigned int  tt_vbi_st_correlation_thl:8;
        unsigned int  reserved_1:1;
        unsigned int  filter_select_tap:3;
        unsigned int  reserved_2:1;
        unsigned int  filter_coe_modify:11;
}TT_VBI_NOISY_CTRL1;

typedef struct
{
        unsigned int  tt_vbi_out_hcount_en:1;
        unsigned int  reserved_0:5;
        unsigned int  tt_vbi_out_hcount_start_tt:10;
        unsigned int  reserved_1:6;
        unsigned int  tt_vbi_out_hcount_end_tt:10;
}TT_VBI_NOISY_CTRL2;

typedef struct
{
        unsigned int  tt_vbi_odd_par_err_byte_replace_en:1;
        unsigned int  reserved_0:7;
        unsigned int  tt_vbi_odd_par_err_byte_substitute_data:8;
        unsigned int  reserved_1:7;
        unsigned int  tt_vbi_odd_parity_chk_en:1;
        unsigned int  reserved_2:5;
        unsigned int  tt_vbi_noise_filter_sw:3;
}TT_VBI_NOISY_CTRL3;

typedef struct
{
        unsigned int  tt_coch_auto_compensate_en:2;
        unsigned int  reserved_0:18;
        unsigned int  tt_coch_tran_thl:8;
        unsigned int  reserved_1:3;
        unsigned int  tt_coch_noise_filter_sel:1;
}TT_VBI_CO_CH_CTRL;

typedef struct
{
        unsigned int  tt_vbi_clamp_en:1;
        unsigned int  reserved_0:2;
        unsigned int  tt_vbi_clamp_dc_level_sub:9;
        unsigned int  reserved_1:3;
        unsigned int  tt_vbi_clamp_dc_level_add:9;
        unsigned int  tt_vbi_clamp_dgain:8;
}TT_VBI_CLAMPAGC_CTRL;

typedef struct
{
        unsigned int  tt_vbi_slice_lv_fix_start:8;
        unsigned int  reserved_0:3;
        unsigned int  tt_vbi_slice_lv_fix_start_en:1;
        unsigned int  tt_vbi_data_region_lpfil_gain:4;
        unsigned int  reserved_1:2;
        unsigned int  tt_vbi_data_region_phase_inv_disable:1;
        unsigned int  tt_vbi_phase_inv_en:1;
        unsigned int  reserved_2:3;
        unsigned int  tt_vbi_pd_en2_err_fix_en:1;
        unsigned int  reserved_3:3;
        unsigned int  tt_vbi_resample_filter_sel:1;
        unsigned int  reserved_4:1;
        unsigned int  reserved_5:1;
        unsigned int  tt_vbi_pd_loop_filter_round_sel:2;
}TT_VBI_NOISY_CTRL;

typedef struct
{
        unsigned int  tt_vbi_slice_lv_fix_start_wss:8;
        unsigned int  reserved_0:10;
        unsigned int  tt_vbi_pattern_sel:6;
        unsigned int  tt_vbi_vps_pattern_set1:8;
}TT_VBI_PATTERN_SEL;

typedef struct
{
        unsigned int  tt_vbi_vps_pattern_set2:32;
}TT_VBI_PATTERN_SEL1;

typedef struct
{
        unsigned int  tt_vbi_vps_pattern_set3:32;
}TT_VBI_PATTERN_SEL2;

typedef struct
{
        unsigned int  tt_vbi_vps_pattern_set4:32;
}TT_VBI_PATTERN_SEL3;

typedef struct
{
        unsigned int  tt_vbi_out_hcount_en_vps:1;
        unsigned int  reserved_0:5;
        unsigned int  tt_vbi_out_hcount_start_vps:10;
        unsigned int  reserved_1:6;
        unsigned int  tt_vbi_out_hcount_end_vps:10;
}TT_VBI_NOISY_CTRL4;

typedef struct
{
        unsigned int  tt_vbi_out_hcount_en_wss:1;
        unsigned int  reserved_0:5;
        unsigned int  tt_vbi_out_hcount_start_wss:10;
        unsigned int  reserved_1:6;
        unsigned int  tt_vbi_out_hcount_end_wss:10;
}TT_VBI_NOISY_CTRL5;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  tt_vbi_st_correlation_en_vps:1;
        unsigned int  reserved_1:2;
        unsigned int  tt_vbi_st_correlation_thl_vps:10;
        unsigned int  reserved_2:3;
        unsigned int  tt_vbi_st_correlation_en_wss:1;
        unsigned int  reserved_3:2;
        unsigned int  tt_vbi_st_correlation_thl_wss:10;
}TT_VBI_NOISY_CTRL6;

typedef struct
{
        unsigned int  tt_vbi_slice_data_en:1;
        unsigned int  reserved_0:5;
        unsigned int  tt_vbi_select_line:10;
        unsigned int  reserved_1:6;
        unsigned int  tt_vbi_hcount_st:10;
}TT_VBI_STATUS1;

typedef struct
{
        unsigned int  tt_vbi_slice_data_1:32;
}TT_VBI_STATUS2;

typedef struct
{
        unsigned int  tt_vbi_slice_data_0:32;
}TT_VBI_STATUS3;

typedef struct
{
        unsigned int  reserved_0:12;
        unsigned int  tt_vbi_line_detect:20;
}TT_VBI_STATUS4;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  vbi_dump_rowdata_en:1;
        unsigned int  reserved_1:3;
        unsigned int  vbi_dump_ttdata_en:1;
        unsigned int  vbi_dump_line_num:24;
}TT_VBI_DUMP_DATA1;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  vbi_dump_overhead:1;
        unsigned int  reserved_1:2;
        unsigned int  vbi_dump_tt_det:1;
        unsigned int  vbi_dump_field_sel:1;
        unsigned int  reserved_2:2;
        unsigned int  vbi_dump_byte_num:10;
        unsigned int  reserved_3:2;
        unsigned int  vbi_dump_hcount_st:10;
}TT_VBI_DUMP_DATA2;

typedef struct
{
        unsigned int  reserved_0:24;
        unsigned int  tt_vbi_odd_par_err_bit_correct_en:1;
        unsigned int  tt_vbi_odd_par_dc:3;
        unsigned int  tt_vbi_odd_parity_chk_th:4;
}TT_VBI_ODD_PARIORITY_RECOVERY;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  tt_vbi_odd_par_line_en:26;
}TT_VBI_ODD_PARIORITY_RECOVERY_1;

typedef struct
{
        unsigned int  tt_agc_en:1;
        unsigned int  tt_data_error_filter_sel:1;
        unsigned int  reserved_0:1;
        unsigned int  tt_agc_comp_w_data:1;
        unsigned int  tt_agc_line_start:8;
        unsigned int  tt_agc_diff_th:8;
        unsigned int  tt_agc_line_circle:12;
}TT_VBI_AGC_SLICE_LEVEL;

typedef struct
{
        unsigned int  tt_data_error_ignor:8;
        unsigned int  tt_data_error_count_dn:12;
        unsigned int  tt_data_error_count_up:12;
}TT_VBI_AGC_SLICE_LEVEL1;

typedef struct
{
        unsigned int  reserved_0:7;
        unsigned int  tt_vbi_slicer_level_agc:9;
        unsigned int  reserved_1:12;
        unsigned int  tt_data_error_diff_rat:4;
}TT_VBI_AGC_SLICE_LEVEL2;

typedef struct
{
        unsigned int  tt_start_code_ignor_num:4;
        unsigned int  wss_data_sel:1;
        unsigned int  reserved_0:1;
        unsigned int  vps_vote_en:1;
        unsigned int  wss_vote_en:1;
        unsigned int  vps_vote_thl:8;
        unsigned int  wss_vote_thl:8;
        unsigned int  vps_start_code_ignor_num:4;
        unsigned int  wss_start_code_ignor_num:4;
}TT_VBI_WSS_VPS_VOTE;

typedef struct
{
        unsigned int  wss_vbi_clamp_en:1;
        unsigned int  wss_vbi_clamp_filter:1;
        unsigned int  reserved_0:1;
        unsigned int  wss_vbi_clamp_dc_level_sub:9;
        unsigned int  reserved_1:3;
        unsigned int  wss_vbi_clamp_dc_level_add:9;
        unsigned int  wss_vbi_clamp_dgain:8;
}TT_VBI_WSS_VPS_VOTE2;

typedef struct
{
        unsigned int  page6_en:1;
        unsigned int  reserved_0:11;
        unsigned int  page6_lpfil_gain:4;
        unsigned int  reserved_1:2;
        unsigned int  page6_notrig_disable1:1;
        unsigned int  page6_notrig_disable2:1;
        unsigned int  reserved_2:3;
        unsigned int  page6_sel_priority:1;
        unsigned int  reserved_3:2;
        unsigned int  page6_en_count:6;
}TT_VBI_PAGE6;

typedef struct
{
        unsigned int  vbi_debug_mode_en:1;
        unsigned int  reserved_0:18;
        unsigned int  vbi_data_err:1;
        unsigned int  reserved_1:3;
        unsigned int  pat_gen_en:1;
        unsigned int  vbi_debug_mode:8;
}VBI_DEBUG_MODE;

typedef struct
{
        unsigned int  vbi_fpga_test1:32;
}VBI_FPGA_TEST1;

typedef struct
{
        unsigned int  vbi_fpga_test2:32;
}VBI_FPGA_TEST2;

typedef struct
{
        unsigned int  vbi_fpga_test3:32;
}VBI_FPGA_TEST3;

typedef struct
{
        unsigned int  vbi_fpga_test4:32;
}VBI_FPGA_TEST4;

typedef struct
{
        unsigned int  vbi_fpga_test5:32;
}VBI_FPGA_TEST5;

typedef struct
{
        unsigned int  vbi_fpga_test6:32;
}VBI_FPGA_TEST6;

typedef struct
{
        unsigned int  vbi_fpga_test7:32;
}VBI_FPGA_TEST7;

typedef struct
{
        unsigned int  vbi_fpga_test8:32;
}VBI_FPGA_TEST8;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  vbi_dma_frame_addr:29;
}VBI_DMA_FRAME_ADDR;

typedef struct
{
        unsigned int  reserved_0:3;
        unsigned int  vbi_dma_frame_addr_end:29;
}VBI_DMA_FRAME_ADDR_END;

typedef struct
{
        unsigned int  reserved_0:10;
        unsigned int  vbi_dma_ctrl_ofifo_thr:6;
        unsigned int  reserved_1:2;
        unsigned int  vbi_dma_ctrl_ceiladr:6;
        unsigned int  reserved_2:5;
        unsigned int  vbi_dma_ctrl_bstlen:3;
}VBI_DMA_FIFO_STAUS;

typedef struct
{
        unsigned int  reserved_0:28;
        unsigned int  vbi_dma_ctrl_ofifo_err_flag:1;
        unsigned int  vbi_dma_mem_off:1;
        unsigned int  vbi_dma_test_mode:1;
        unsigned int  reserved_1:1;
}VBI_DMA_CTRL;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  vbi_dma_vactive_st1:10;
        unsigned int  reserved_1:6;
        unsigned int  vbi_dma_vactive_end1:10;
}VBI_DMA_VACTIVE1;

typedef struct
{
        unsigned int  reserved_0:6;
        unsigned int  vbi_dma_vactive_st2:10;
        unsigned int  reserved_1:6;
        unsigned int  vbi_dma_vactive_end2:10;
}VBI_DMA_VACTIVE2;

typedef struct
{
        unsigned int  reserved_0:29;
        unsigned int  vbi_dump_overflow:1;
        unsigned int  vbi_dump_irq_en:1;
        unsigned int  vbi_dump_irq:1;
}VBI_DUMP_int;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  sram_on_off:1;
}BIST_TEST1;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_mode:1;
}BIST_MODE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_done:1;
}BIST_DONE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_fail:1;
}BIST_FAIL;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_mode_drf:1;
}BIST_DRF_MODE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_drf_test_resume:1;
}BIST_DRF_RESUME;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_done_drf:1;
}BIST_DONE_DRF;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_drf_start_pause:1;
}BIST_DRF_PAUSE;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  bist_fail_drf:1;
}BIST_FAIL_DRF;

typedef struct
{
        unsigned int  reserved_0:18;
        unsigned int  bist_ls:1;
        unsigned int  bist_rmeb:1;
        unsigned int  bist_rmb:4;
        unsigned int  reserved_1:3;
        unsigned int  bist_rmea:1;
        unsigned int  bist_rma:4;
}BIST_DVSE;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  vbippr_lvld_tendl:11;
        unsigned int  reserved_1:5;
        unsigned int  vbippr_lvld_tstl:11;
}VBI_PPR_LVLD1;

typedef struct
{
        unsigned int  reserved_0:5;
        unsigned int  vbippr_lvld_bendl:11;
        unsigned int  reserved_1:5;
        unsigned int  vbippr_lvld_bstl:11;
}VBI_PPR_LVLD2;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  vbippr_data_acqu_en:1;
}VBIPPR_CTRL_REG;

typedef struct
{
        unsigned int  vbippr_pkt_rx_rst:1;
        unsigned int  reserved_0:15;
        unsigned int  vbippr_pkt_rx_cnt:16;
}VBIPPR_PKT_RX_CNT_REG;

typedef struct
{
        unsigned int  vbi_sync_fifo_rd_count:16;
        unsigned int  reserved_0:7;
        unsigned int  vbi_sync_fifo_rx_count_rst:1;
        unsigned int  reserved_1:1;
        unsigned int  vbippr_pg_mode:3;
        unsigned int  reserved_2:2;
        unsigned int  vbippr_pgdebug_en:1;
        unsigned int  vbippr_pg_en:1;
}VBIPPR_PG_MODE_REG;

typedef struct
{
        unsigned int  reserved_0:31;
        unsigned int  vbippr_pg_line_act:1;
}VBIPPR_PG_LINE_ACT_REG;

typedef struct
{
        unsigned int  vbippr_pgdata1:8;
        unsigned int  vbippr_pgdata2:8;
        unsigned int  vbippr_pgdata3:8;
        unsigned int  vbippr_pgdata4:8;
}VBIPPR_PGDATA_B1B4_REG;

typedef struct
{
        unsigned int  vbippr_pgdata5:8;
        unsigned int  vbippr_pgdata6:8;
        unsigned int  vbippr_pgdata7:8;
        unsigned int  vbippr_pgdata8:8;
}VBIPPR_PGDATA_B5B8_REG;

typedef struct
{
        unsigned int  vbippr_pgdata9:8;
        unsigned int  vbippr_pgdata10:8;
        unsigned int  vbippr_pgdata11:8;
        unsigned int  vbippr_pgdata12:8;
}VBIPPR_PGDATA_B9B12_REG;

typedef struct
{
        unsigned int  vbippr_pgdata13:8;
        unsigned int  vbippr_pgdata14:8;
        unsigned int  vbippr_pgdata15:8;
        unsigned int  vbippr_pgdata16:8;
}VBIPPR_PGDATA_B13B16_REG;

typedef struct
{
        unsigned int  vbippr_pgdata17:8;
        unsigned int  vbippr_pgdata18:8;
        unsigned int  vbippr_pgdata19:8;
        unsigned int  vbippr_pgdata20:8;
}VBIPPR_PGDATA_B17B20_REG;

typedef struct
{
        unsigned int  vbippr_pgdata21:8;
        unsigned int  vbippr_pgdata22:8;
        unsigned int  vbippr_pgdata23:8;
        unsigned int  vbippr_pgdata24:8;
}VBIPPR_PGDATA_B21B24_REG;

typedef struct
{
        unsigned int  vbippr_pgdata25:8;
        unsigned int  vbippr_pgdata26:8;
        unsigned int  vbippr_pgdata27:8;
        unsigned int  vbippr_pgdata28:8;
}VBIPPR_PGDATA_B25B28_REG;

typedef struct
{
        unsigned int  vbippr_pgdata29:8;
        unsigned int  vbippr_pgdata30:8;
        unsigned int  vbippr_pgdata31:8;
        unsigned int  vbippr_pgdata32:8;
}VBIPPR_PGDATA_B29B32_REG;

typedef struct
{
        unsigned int  vbippr_pgdata33:8;
        unsigned int  vbippr_pgdata34:8;
        unsigned int  vbippr_pgdata35:8;
        unsigned int  vbippr_pgdata36:8;
}VBIPPR_PGDATA_B33B36_REG;

typedef struct
{
        unsigned int  vbippr_pgdata37:8;
        unsigned int  vbippr_pgdata38:8;
        unsigned int  vbippr_pgdata39:8;
        unsigned int  vbippr_pgdata40:8;
}VBIPPR_PGDATA_B37B40_REG;

typedef struct
{
        unsigned int  vbippr_pgdata41:8;
        unsigned int  vbippr_pgdata42:8;
        unsigned int  vbippr_pgdata43:8;
        unsigned int  vbippr_pgdata44:8;
}VBIPPR_PGDATA_B41B44_REG;

typedef struct
{
        unsigned int  vbippr_pgdata45:8;
        unsigned int  vbippr_pgdata46:8;
        unsigned int  vbippr_pgdata47:8;
        unsigned int  reserved_0:8;
}VBIPPR_PGDATA_B45B47_REG;

#define  VBISL0                                                                 0x18030800
#define  VBISL0_reg_addr                                                        "0xB8030800"
#define  VBISL0_reg                                                             0xB8030800
#define  VBISL0_inst_addr                                                       "0x0000"
#define  VBISL0_inst                                                            0x0000
#define  VBISL0_vbisl_out_mux_manual_en_shift                                   (31)
#define  VBISL0_vbisl_out_auto_tt_vps_sel_shift                                 (30)
#define  VBISL0_vbisl_out_mux_sel_shift                                         (28)
#define  VBISL0_vbi_dma_stop_shift                                              (27)
#define  VBISL0_vbi_dma_stop_en_shift                                           (26)
#define  VBISL0_vbisl0_src_sel_shift                                            (7)
#define  VBISL0_vbisl0_sys625i_shift                                            (6)
#define  VBISL0_vbisl0_fieldi_inv_shift                                         (5)
#define  VBISL0_vbisl2_lcnt_field_inv_shift                                     (4)
#define  VBISL0_vbisl_out_mux_manual_en_mask                                    (0x80000000)
#define  VBISL0_vbisl_out_auto_tt_vps_sel_mask                                  (0x40000000)
#define  VBISL0_vbisl_out_mux_sel_mask                                          (0x30000000)
#define  VBISL0_vbi_dma_stop_mask                                               (0x08000000)
#define  VBISL0_vbi_dma_stop_en_mask                                            (0x04000000)
#define  VBISL0_vbisl0_src_sel_mask                                             (0x00000080)
#define  VBISL0_vbisl0_sys625i_mask                                             (0x00000040)
#define  VBISL0_vbisl0_fieldi_inv_mask                                          (0x00000020)
#define  VBISL0_vbisl2_lcnt_field_inv_mask                                      (0x00000010)
#define  VBISL0_vbisl_out_mux_manual_en(data)                                   (0x80000000&((data)<<31))
#define  VBISL0_vbisl_out_auto_tt_vps_sel(data)                                 (0x40000000&((data)<<30))
#define  VBISL0_vbisl_out_mux_sel(data)                                         (0x30000000&((data)<<28))
#define  VBISL0_vbi_dma_stop(data)                                              (0x08000000&((data)<<27))
#define  VBISL0_vbi_dma_stop_en(data)                                           (0x04000000&((data)<<26))
#define  VBISL0_vbisl0_src_sel(data)                                            (0x00000080&((data)<<7))
#define  VBISL0_vbisl0_sys625i(data)                                            (0x00000040&((data)<<6))
#define  VBISL0_vbisl0_fieldi_inv(data)                                         (0x00000020&((data)<<5))
#define  VBISL0_vbisl2_lcnt_field_inv(data)                                     (0x00000010&((data)<<4))
#define  VBISL0_get_vbisl_out_mux_manual_en(data)                               ((0x80000000&(data))>>31)
#define  VBISL0_get_vbisl_out_auto_tt_vps_sel(data)                             ((0x40000000&(data))>>30)
#define  VBISL0_get_vbisl_out_mux_sel(data)                                     ((0x30000000&(data))>>28)
#define  VBISL0_get_vbi_dma_stop(data)                                          ((0x08000000&(data))>>27)
#define  VBISL0_get_vbi_dma_stop_en(data)                                       ((0x04000000&(data))>>26)
#define  VBISL0_get_vbisl0_src_sel(data)                                        ((0x00000080&(data))>>7)
#define  VBISL0_get_vbisl0_sys625i(data)                                        ((0x00000040&(data))>>6)
#define  VBISL0_get_vbisl0_fieldi_inv(data)                                     ((0x00000020&(data))>>5)
#define  VBISL0_get_vbisl2_lcnt_field_inv(data)                                 ((0x00000010&(data))>>4)

#define  TT_VBI_CC_CTRL0                                                        0x18030804
#define  TT_VBI_CC_CTRL0_reg_addr                                               "0xB8030804"
#define  TT_VBI_CC_CTRL0_reg                                                    0xB8030804
#define  TT_VBI_CC_CTRL0_inst_addr                                              "0x0001"
#define  TT_VBI_CC_CTRL0_inst                                                   0x0001
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_caposc_frun_en_shift                         (31)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_en_shift                                (30)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_sel_shift                               (29)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_num_shift                               (24)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_data_swing_gain_shift                        (16)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_blank_offset_shift                           (0)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_caposc_frun_en_mask                          (0x80000000)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_en_mask                                 (0x40000000)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_sel_mask                                (0x20000000)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_num_mask                                (0x0F000000)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_data_swing_gain_mask                         (0x000F0000)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_blank_offset_mask                            (0x0000FFFF)
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_caposc_frun_en(data)                         (0x80000000&((data)<<31))
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_en(data)                                (0x40000000&((data)<<30))
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_sel(data)                               (0x20000000&((data)<<29))
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_vote_num(data)                               (0x0F000000&((data)<<24))
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_data_swing_gain(data)                        (0x000F0000&((data)<<16))
#define  TT_VBI_CC_CTRL0_tt_vbi_cc_blank_offset(data)                           (0x0000FFFF&(data))
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_caposc_frun_en(data)                     ((0x80000000&(data))>>31)
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_vote_en(data)                            ((0x40000000&(data))>>30)
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_vote_sel(data)                           ((0x20000000&(data))>>29)
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_vote_num(data)                           ((0x0F000000&(data))>>24)
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_data_swing_gain(data)                    ((0x000F0000&(data))>>16)
#define  TT_VBI_CC_CTRL0_get_tt_vbi_cc_blank_offset(data)                       (0x0000FFFF&(data))

#define  TT_VBI_CC_CTRL1                                                        0x18030808
#define  TT_VBI_CC_CTRL1_reg_addr                                               "0xB8030808"
#define  TT_VBI_CC_CTRL1_reg                                                    0xB8030808
#define  TT_VBI_CC_CTRL1_inst_addr                                              "0x0002"
#define  TT_VBI_CC_CTRL1_inst                                                   0x0002
#define  TT_VBI_CC_CTRL1_find_start_shift                                       (31)
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_en_shift                      (24)
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_thl_shift                     (16)
#define  TT_VBI_CC_CTRL1_find_start_mask                                        (0x80000000)
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_en_mask                       (0x01000000)
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_thl_mask                      (0x00FF0000)
#define  TT_VBI_CC_CTRL1_find_start(data)                                       (0x80000000&((data)<<31))
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_en(data)                      (0x01000000&((data)<<24))
#define  TT_VBI_CC_CTRL1_tt_vbi_cc_st_correlation_thl(data)                     (0x00FF0000&((data)<<16))
#define  TT_VBI_CC_CTRL1_get_find_start(data)                                   ((0x80000000&(data))>>31)
#define  TT_VBI_CC_CTRL1_get_tt_vbi_cc_st_correlation_en(data)                  ((0x01000000&(data))>>24)
#define  TT_VBI_CC_CTRL1_get_tt_vbi_cc_st_correlation_thl(data)                 ((0x00FF0000&(data))>>16)

#define  TT_VBI_CC_CTRL2                                                        0x1803080C
#define  TT_VBI_CC_CTRL2_reg_addr                                               "0xB803080C"
#define  TT_VBI_CC_CTRL2_reg                                                    0xB803080C
#define  TT_VBI_CC_CTRL2_inst_addr                                              "0x0003"
#define  TT_VBI_CC_CTRL2_inst                                                   0x0003
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_en_shift                          (31)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_start_shift                       (16)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_end_shift                         (0)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_en_mask                           (0x80000000)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_start_mask                        (0x03FF0000)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_end_mask                          (0x000003FF)
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_en(data)                          (0x80000000&((data)<<31))
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_start(data)                       (0x03FF0000&((data)<<16))
#define  TT_VBI_CC_CTRL2_tt_vbi_cc_out_hcount_end(data)                         (0x000003FF&(data))
#define  TT_VBI_CC_CTRL2_get_tt_vbi_cc_out_hcount_en(data)                      ((0x80000000&(data))>>31)
#define  TT_VBI_CC_CTRL2_get_tt_vbi_cc_out_hcount_start(data)                   ((0x03FF0000&(data))>>16)
#define  TT_VBI_CC_CTRL2_get_tt_vbi_cc_out_hcount_end(data)                     (0x000003FF&(data))

#define  VBI_CC_PATTERN_COMPARE_1                                               0x18030810
#define  VBI_CC_PATTERN_COMPARE_1_reg_addr                                      "0xB8030810"
#define  VBI_CC_PATTERN_COMPARE_1_reg                                           0xB8030810
#define  VBI_CC_PATTERN_COMPARE_1_inst_addr                                     "0x0004"
#define  VBI_CC_PATTERN_COMPARE_1_inst                                          0x0004
#define  VBI_CC_PATTERN_COMPARE_1_cc_pattern_field_shift                        (8)
#define  VBI_CC_PATTERN_COMPARE_1_find_start_num_shift                          (0)
#define  VBI_CC_PATTERN_COMPARE_1_cc_pattern_field_mask                         (0x00000100)
#define  VBI_CC_PATTERN_COMPARE_1_find_start_num_mask                           (0x0000003F)
#define  VBI_CC_PATTERN_COMPARE_1_cc_pattern_field(data)                        (0x00000100&((data)<<8))
#define  VBI_CC_PATTERN_COMPARE_1_find_start_num(data)                          (0x0000003F&(data))
#define  VBI_CC_PATTERN_COMPARE_1_get_cc_pattern_field(data)                    ((0x00000100&(data))>>8)
#define  VBI_CC_PATTERN_COMPARE_1_get_find_start_num(data)                      (0x0000003F&(data))

#define  VBI_CC_PATTERN_COMPARE_2                                               0x18030814
#define  VBI_CC_PATTERN_COMPARE_2_reg_addr                                      "0xB8030814"
#define  VBI_CC_PATTERN_COMPARE_2_reg                                           0xB8030814
#define  VBI_CC_PATTERN_COMPARE_2_inst_addr                                     "0x0005"
#define  VBI_CC_PATTERN_COMPARE_2_inst                                          0x0005
#define  VBI_CC_PATTERN_COMPARE_2_cc_compare_data_shift                         (0)
#define  VBI_CC_PATTERN_COMPARE_2_cc_compare_data_mask                          (0xFFFFFFFF)
#define  VBI_CC_PATTERN_COMPARE_2_cc_compare_data(data)                         (0xFFFFFFFF&(data))
#define  VBI_CC_PATTERN_COMPARE_2_get_cc_compare_data(data)                     (0xFFFFFFFF&(data))

#define  VBI_VOUNT_SHIFT                                                        0x18030820
#define  VBI_VOUNT_SHIFT_reg_addr                                               "0xB8030820"
#define  VBI_VOUNT_SHIFT_reg                                                    0xB8030820
#define  VBI_VOUNT_SHIFT_inst_addr                                              "0x0006"
#define  VBI_VOUNT_SHIFT_inst                                                   0x0006
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_en_shift                               (16)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_field_inv_shift                        (12)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_num_shift                              (0)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_en_mask                                (0x00010000)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_field_inv_mask                         (0x00001000)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_num_mask                               (0x000007FF)
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_en(data)                               (0x00010000&((data)<<16))
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_field_inv(data)                        (0x00001000&((data)<<12))
#define  VBI_VOUNT_SHIFT_vbi_vount_shift_num(data)                              (0x000007FF&(data))
#define  VBI_VOUNT_SHIFT_get_vbi_vount_shift_en(data)                           ((0x00010000&(data))>>16)
#define  VBI_VOUNT_SHIFT_get_vbi_vount_shift_field_inv(data)                    ((0x00001000&(data))>>12)
#define  VBI_VOUNT_SHIFT_get_vbi_vount_shift_num(data)                          (0x000007FF&(data))

#define  CGMS_C0                                                                0x18030900
#define  CGMS_C0_reg_addr                                                       "0xB8030900"
#define  CGMS_C0_reg                                                            0xB8030900
#define  CGMS_C0_inst_addr                                                      "0x0007"
#define  CGMS_C0_inst                                                           0x0007
#define  CGMS_C0_cgms_c0_debounce_sel_shift                                     (24)
#define  CGMS_C0_cgms_c0_slicer_dcl_shift                                       (8)
#define  CGMS_C0_cgms_c0_lpf_sel_shift                                          (4)
#define  CGMS_C0_cgms_c0_slicer_ms_shift                                        (2)
#define  CGMS_C0_cgms_c0_adap_slvl_en_shift                                     (1)
#define  CGMS_C0_cgms_c0_slicen_shift                                           (0)
#define  CGMS_C0_cgms_c0_debounce_sel_mask                                      (0x07000000)
#define  CGMS_C0_cgms_c0_slicer_dcl_mask                                        (0x0003FF00)
#define  CGMS_C0_cgms_c0_lpf_sel_mask                                           (0x00000030)
#define  CGMS_C0_cgms_c0_slicer_ms_mask                                         (0x0000000C)
#define  CGMS_C0_cgms_c0_adap_slvl_en_mask                                      (0x00000002)
#define  CGMS_C0_cgms_c0_slicen_mask                                            (0x00000001)
#define  CGMS_C0_cgms_c0_debounce_sel(data)                                     (0x07000000&((data)<<24))
#define  CGMS_C0_cgms_c0_slicer_dcl(data)                                       (0x0003FF00&((data)<<8))
#define  CGMS_C0_cgms_c0_lpf_sel(data)                                          (0x00000030&((data)<<4))
#define  CGMS_C0_cgms_c0_slicer_ms(data)                                        (0x0000000C&((data)<<2))
#define  CGMS_C0_cgms_c0_adap_slvl_en(data)                                     (0x00000002&((data)<<1))
#define  CGMS_C0_cgms_c0_slicen(data)                                           (0x00000001&(data))
#define  CGMS_C0_get_cgms_c0_debounce_sel(data)                                 ((0x07000000&(data))>>24)
#define  CGMS_C0_get_cgms_c0_slicer_dcl(data)                                   ((0x0003FF00&(data))>>8)
#define  CGMS_C0_get_cgms_c0_lpf_sel(data)                                      ((0x00000030&(data))>>4)
#define  CGMS_C0_get_cgms_c0_slicer_ms(data)                                    ((0x0000000C&(data))>>2)
#define  CGMS_C0_get_cgms_c0_adap_slvl_en(data)                                 ((0x00000002&(data))>>1)
#define  CGMS_C0_get_cgms_c0_slicen(data)                                       (0x00000001&(data))

#define  CGMS_C1                                                                0x18030904
#define  CGMS_C1_reg_addr                                                       "0xB8030904"
#define  CGMS_C1_reg                                                            0xB8030904
#define  CGMS_C1_inst_addr                                                      "0x0008"
#define  CGMS_C1_inst                                                           0x0008
#define  CGMS_C1_cgms_c1_actline_t_shift                                        (16)
#define  CGMS_C1_cgms_c1_actline_b_shift                                        (0)
#define  CGMS_C1_cgms_c1_actline_t_mask                                         (0x03FF0000)
#define  CGMS_C1_cgms_c1_actline_b_mask                                         (0x000003FF)
#define  CGMS_C1_cgms_c1_actline_t(data)                                        (0x03FF0000&((data)<<16))
#define  CGMS_C1_cgms_c1_actline_b(data)                                        (0x000003FF&(data))
#define  CGMS_C1_get_cgms_c1_actline_t(data)                                    ((0x03FF0000&(data))>>16)
#define  CGMS_C1_get_cgms_c1_actline_b(data)                                    (0x000003FF&(data))

#define  CGMS_C2                                                                0x18030908
#define  CGMS_C2_reg_addr                                                       "0xB8030908"
#define  CGMS_C2_reg                                                            0xB8030908
#define  CGMS_C2_inst_addr                                                      "0x0009"
#define  CGMS_C2_inst                                                           0x0009
#define  CGMS_C2_cgms_c2_dcdet_st_shift                                         (16)
#define  CGMS_C2_cgms_c2_dcdet_end_shift                                        (0)
#define  CGMS_C2_cgms_c2_dcdet_st_mask                                          (0x03FF0000)
#define  CGMS_C2_cgms_c2_dcdet_end_mask                                         (0x000003FF)
#define  CGMS_C2_cgms_c2_dcdet_st(data)                                         (0x03FF0000&((data)<<16))
#define  CGMS_C2_cgms_c2_dcdet_end(data)                                        (0x000003FF&(data))
#define  CGMS_C2_get_cgms_c2_dcdet_st(data)                                     ((0x03FF0000&(data))>>16)
#define  CGMS_C2_get_cgms_c2_dcdet_end(data)                                    (0x000003FF&(data))

#define  CGMS_C3                                                                0x1803090C
#define  CGMS_C3_reg_addr                                                       "0xB803090C"
#define  CGMS_C3_reg                                                            0xB803090C
#define  CGMS_C3_inst_addr                                                      "0x000A"
#define  CGMS_C3_inst                                                           0x000A
#define  CGMS_C3_cgms_auto_period_en_shift                                      (24)
#define  CGMS_C3_cgms_period_cnt_shift                                          (12)
#define  CGMS_C3_cgms_c3_lv_dc_th_shift                                         (0)
#define  CGMS_C3_cgms_auto_period_en_mask                                       (0x01000000)
#define  CGMS_C3_cgms_period_cnt_mask                                           (0x003FF000)
#define  CGMS_C3_cgms_c3_lv_dc_th_mask                                          (0x000003FF)
#define  CGMS_C3_cgms_auto_period_en(data)                                      (0x01000000&((data)<<24))
#define  CGMS_C3_cgms_period_cnt(data)                                          (0x003FF000&((data)<<12))
#define  CGMS_C3_cgms_c3_lv_dc_th(data)                                         (0x000003FF&(data))
#define  CGMS_C3_get_cgms_auto_period_en(data)                                  ((0x01000000&(data))>>24)
#define  CGMS_C3_get_cgms_period_cnt(data)                                      ((0x003FF000&(data))>>12)
#define  CGMS_C3_get_cgms_c3_lv_dc_th(data)                                     (0x000003FF&(data))

#define  CGMS_C4                                                                0x18030910
#define  CGMS_C4_reg_addr                                                       "0xB8030910"
#define  CGMS_C4_reg                                                            0xB8030910
#define  CGMS_C4_inst_addr                                                      "0x000B"
#define  CGMS_C4_inst                                                           0x000B
#define  CGMS_C4_vbisl16_cgms_int_en_shift                                      (28)
#define  CGMS_C4_cgms_c4_cgms_vld_shift                                         (24)
#define  CGMS_C4_cgms_c4_cgmsdata_shift                                         (0)
#define  CGMS_C4_vbisl16_cgms_int_en_mask                                       (0x10000000)
#define  CGMS_C4_cgms_c4_cgms_vld_mask                                          (0x01000000)
#define  CGMS_C4_cgms_c4_cgmsdata_mask                                          (0x000FFFFF)
#define  CGMS_C4_vbisl16_cgms_int_en(data)                                      (0x10000000&((data)<<28))
#define  CGMS_C4_cgms_c4_cgms_vld(data)                                         (0x01000000&((data)<<24))
#define  CGMS_C4_cgms_c4_cgmsdata(data)                                         (0x000FFFFF&(data))
#define  CGMS_C4_get_vbisl16_cgms_int_en(data)                                  ((0x10000000&(data))>>28)
#define  CGMS_C4_get_cgms_c4_cgms_vld(data)                                     ((0x01000000&(data))>>24)
#define  CGMS_C4_get_cgms_c4_cgmsdata(data)                                     (0x000FFFFF&(data))

#define  CGMS_C5                                                                0x18030914
#define  CGMS_C5_reg_addr                                                       "0xB8030914"
#define  CGMS_C5_reg                                                            0xB8030914
#define  CGMS_C5_inst_addr                                                      "0x000C"
#define  CGMS_C5_inst                                                           0x000C
#define  CGMS_C5_cgms_c5_min_period_shift                                       (16)
#define  CGMS_C5_cgms_c5_max_period_shift                                       (8)
#define  CGMS_C5_cgms_c5_period_shift                                           (0)
#define  CGMS_C5_cgms_c5_min_period_mask                                        (0x00FF0000)
#define  CGMS_C5_cgms_c5_max_period_mask                                        (0x0000FF00)
#define  CGMS_C5_cgms_c5_period_mask                                            (0x000000FF)
#define  CGMS_C5_cgms_c5_min_period(data)                                       (0x00FF0000&((data)<<16))
#define  CGMS_C5_cgms_c5_max_period(data)                                       (0x0000FF00&((data)<<8))
#define  CGMS_C5_cgms_c5_period(data)                                           (0x000000FF&(data))
#define  CGMS_C5_get_cgms_c5_min_period(data)                                   ((0x00FF0000&(data))>>16)
#define  CGMS_C5_get_cgms_c5_max_period(data)                                   ((0x0000FF00&(data))>>8)
#define  CGMS_C5_get_cgms_c5_period(data)                                       (0x000000FF&(data))

#define  TT_VBI_TT_DATA00                                                       0x18030918
#define  TT_VBI_TT_DATA00_reg_addr                                              "0xB8030918"
#define  TT_VBI_TT_DATA00_reg                                                   0xB8030918
#define  TT_VBI_TT_DATA00_inst_addr                                             "0x000D"
#define  TT_VBI_TT_DATA00_inst                                                  0x000D
#define  TT_VBI_TT_DATA00_tt_ttdata41_shift                                     (8)
#define  TT_VBI_TT_DATA00_tt_ttdata40_shift                                     (0)
#define  TT_VBI_TT_DATA00_tt_ttdata41_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA00_tt_ttdata40_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA00_tt_ttdata41(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA00_tt_ttdata40(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA00_get_tt_ttdata41(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA00_get_tt_ttdata40(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA01                                                       0x1803091C
#define  TT_VBI_TT_DATA01_reg_addr                                              "0xB803091C"
#define  TT_VBI_TT_DATA01_reg                                                   0xB803091C
#define  TT_VBI_TT_DATA01_inst_addr                                             "0x000E"
#define  TT_VBI_TT_DATA01_inst                                                  0x000E
#define  TT_VBI_TT_DATA01_tt_ttdata39_shift                                     (24)
#define  TT_VBI_TT_DATA01_tt_ttdata38_shift                                     (16)
#define  TT_VBI_TT_DATA01_tt_ttdata37_shift                                     (8)
#define  TT_VBI_TT_DATA01_tt_ttdata36_shift                                     (0)
#define  TT_VBI_TT_DATA01_tt_ttdata39_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA01_tt_ttdata38_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA01_tt_ttdata37_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA01_tt_ttdata36_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA01_tt_ttdata39(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA01_tt_ttdata38(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA01_tt_ttdata37(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA01_tt_ttdata36(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA01_get_tt_ttdata39(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA01_get_tt_ttdata38(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA01_get_tt_ttdata37(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA01_get_tt_ttdata36(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA02                                                       0x18030920
#define  TT_VBI_TT_DATA02_reg_addr                                              "0xB8030920"
#define  TT_VBI_TT_DATA02_reg                                                   0xB8030920
#define  TT_VBI_TT_DATA02_inst_addr                                             "0x000F"
#define  TT_VBI_TT_DATA02_inst                                                  0x000F
#define  TT_VBI_TT_DATA02_tt_ttdata35_shift                                     (24)
#define  TT_VBI_TT_DATA02_tt_ttdata34_shift                                     (16)
#define  TT_VBI_TT_DATA02_tt_ttdata33_shift                                     (8)
#define  TT_VBI_TT_DATA02_tt_ttdata32_shift                                     (0)
#define  TT_VBI_TT_DATA02_tt_ttdata35_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA02_tt_ttdata34_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA02_tt_ttdata33_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA02_tt_ttdata32_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA02_tt_ttdata35(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA02_tt_ttdata34(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA02_tt_ttdata33(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA02_tt_ttdata32(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA02_get_tt_ttdata35(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA02_get_tt_ttdata34(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA02_get_tt_ttdata33(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA02_get_tt_ttdata32(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA03                                                       0x18030924
#define  TT_VBI_TT_DATA03_reg_addr                                              "0xB8030924"
#define  TT_VBI_TT_DATA03_reg                                                   0xB8030924
#define  TT_VBI_TT_DATA03_inst_addr                                             "0x0010"
#define  TT_VBI_TT_DATA03_inst                                                  0x0010
#define  TT_VBI_TT_DATA03_tt_ttdata31_shift                                     (24)
#define  TT_VBI_TT_DATA03_tt_ttdata30_shift                                     (16)
#define  TT_VBI_TT_DATA03_tt_ttdata29_shift                                     (8)
#define  TT_VBI_TT_DATA03_tt_ttdata28_shift                                     (0)
#define  TT_VBI_TT_DATA03_tt_ttdata31_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA03_tt_ttdata30_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA03_tt_ttdata29_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA03_tt_ttdata28_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA03_tt_ttdata31(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA03_tt_ttdata30(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA03_tt_ttdata29(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA03_tt_ttdata28(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA03_get_tt_ttdata31(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA03_get_tt_ttdata30(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA03_get_tt_ttdata29(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA03_get_tt_ttdata28(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA04                                                       0x18030928
#define  TT_VBI_TT_DATA04_reg_addr                                              "0xB8030928"
#define  TT_VBI_TT_DATA04_reg                                                   0xB8030928
#define  TT_VBI_TT_DATA04_inst_addr                                             "0x0011"
#define  TT_VBI_TT_DATA04_inst                                                  0x0011
#define  TT_VBI_TT_DATA04_tt_ttdata27_shift                                     (24)
#define  TT_VBI_TT_DATA04_tt_ttdata26_shift                                     (16)
#define  TT_VBI_TT_DATA04_tt_ttdata25_shift                                     (8)
#define  TT_VBI_TT_DATA04_tt_ttdata24_shift                                     (0)
#define  TT_VBI_TT_DATA04_tt_ttdata27_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA04_tt_ttdata26_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA04_tt_ttdata25_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA04_tt_ttdata24_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA04_tt_ttdata27(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA04_tt_ttdata26(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA04_tt_ttdata25(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA04_tt_ttdata24(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA04_get_tt_ttdata27(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA04_get_tt_ttdata26(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA04_get_tt_ttdata25(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA04_get_tt_ttdata24(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA05                                                       0x1803092C
#define  TT_VBI_TT_DATA05_reg_addr                                              "0xB803092C"
#define  TT_VBI_TT_DATA05_reg                                                   0xB803092C
#define  TT_VBI_TT_DATA05_inst_addr                                             "0x0012"
#define  TT_VBI_TT_DATA05_inst                                                  0x0012
#define  TT_VBI_TT_DATA05_tt_ttdata23_shift                                     (24)
#define  TT_VBI_TT_DATA05_tt_ttdata22_shift                                     (16)
#define  TT_VBI_TT_DATA05_tt_ttdata21_shift                                     (8)
#define  TT_VBI_TT_DATA05_tt_ttdata20_shift                                     (0)
#define  TT_VBI_TT_DATA05_tt_ttdata23_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA05_tt_ttdata22_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA05_tt_ttdata21_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA05_tt_ttdata20_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA05_tt_ttdata23(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA05_tt_ttdata22(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA05_tt_ttdata21(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA05_tt_ttdata20(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA05_get_tt_ttdata23(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA05_get_tt_ttdata22(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA05_get_tt_ttdata21(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA05_get_tt_ttdata20(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA06                                                       0x18030930
#define  TT_VBI_TT_DATA06_reg_addr                                              "0xB8030930"
#define  TT_VBI_TT_DATA06_reg                                                   0xB8030930
#define  TT_VBI_TT_DATA06_inst_addr                                             "0x0013"
#define  TT_VBI_TT_DATA06_inst                                                  0x0013
#define  TT_VBI_TT_DATA06_tt_ttdata19_shift                                     (24)
#define  TT_VBI_TT_DATA06_tt_ttdata18_shift                                     (16)
#define  TT_VBI_TT_DATA06_tt_ttdata17_shift                                     (8)
#define  TT_VBI_TT_DATA06_tt_ttdata16_shift                                     (0)
#define  TT_VBI_TT_DATA06_tt_ttdata19_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA06_tt_ttdata18_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA06_tt_ttdata17_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA06_tt_ttdata16_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA06_tt_ttdata19(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA06_tt_ttdata18(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA06_tt_ttdata17(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA06_tt_ttdata16(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA06_get_tt_ttdata19(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA06_get_tt_ttdata18(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA06_get_tt_ttdata17(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA06_get_tt_ttdata16(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA07                                                       0x18030934
#define  TT_VBI_TT_DATA07_reg_addr                                              "0xB8030934"
#define  TT_VBI_TT_DATA07_reg                                                   0xB8030934
#define  TT_VBI_TT_DATA07_inst_addr                                             "0x0014"
#define  TT_VBI_TT_DATA07_inst                                                  0x0014
#define  TT_VBI_TT_DATA07_tt_ttdata15_shift                                     (24)
#define  TT_VBI_TT_DATA07_tt_ttdata14_shift                                     (16)
#define  TT_VBI_TT_DATA07_tt_ttdata13_shift                                     (8)
#define  TT_VBI_TT_DATA07_tt_ttdata12_shift                                     (0)
#define  TT_VBI_TT_DATA07_tt_ttdata15_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA07_tt_ttdata14_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA07_tt_ttdata13_mask                                      (0x0000FF00)
#define  TT_VBI_TT_DATA07_tt_ttdata12_mask                                      (0x000000FF)
#define  TT_VBI_TT_DATA07_tt_ttdata15(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA07_tt_ttdata14(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA07_tt_ttdata13(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA07_tt_ttdata12(data)                                     (0x000000FF&(data))
#define  TT_VBI_TT_DATA07_get_tt_ttdata15(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA07_get_tt_ttdata14(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA07_get_tt_ttdata13(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA07_get_tt_ttdata12(data)                                 (0x000000FF&(data))

#define  TT_VBI_TT_DATA08                                                       0x18030938
#define  TT_VBI_TT_DATA08_reg_addr                                              "0xB8030938"
#define  TT_VBI_TT_DATA08_reg                                                   0xB8030938
#define  TT_VBI_TT_DATA08_inst_addr                                             "0x0015"
#define  TT_VBI_TT_DATA08_inst                                                  0x0015
#define  TT_VBI_TT_DATA08_tt_ttdata11_shift                                     (24)
#define  TT_VBI_TT_DATA08_tt_ttdata10_shift                                     (16)
#define  TT_VBI_TT_DATA08_tt_ttdata9_shift                                      (8)
#define  TT_VBI_TT_DATA08_tt_ttdata8_shift                                      (0)
#define  TT_VBI_TT_DATA08_tt_ttdata11_mask                                      (0xFF000000)
#define  TT_VBI_TT_DATA08_tt_ttdata10_mask                                      (0x00FF0000)
#define  TT_VBI_TT_DATA08_tt_ttdata9_mask                                       (0x0000FF00)
#define  TT_VBI_TT_DATA08_tt_ttdata8_mask                                       (0x000000FF)
#define  TT_VBI_TT_DATA08_tt_ttdata11(data)                                     (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA08_tt_ttdata10(data)                                     (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA08_tt_ttdata9(data)                                      (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA08_tt_ttdata8(data)                                      (0x000000FF&(data))
#define  TT_VBI_TT_DATA08_get_tt_ttdata11(data)                                 ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA08_get_tt_ttdata10(data)                                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA08_get_tt_ttdata9(data)                                  ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA08_get_tt_ttdata8(data)                                  (0x000000FF&(data))

#define  TT_VBI_TT_DATA09                                                       0x1803093C
#define  TT_VBI_TT_DATA09_reg_addr                                              "0xB803093C"
#define  TT_VBI_TT_DATA09_reg                                                   0xB803093C
#define  TT_VBI_TT_DATA09_inst_addr                                             "0x0016"
#define  TT_VBI_TT_DATA09_inst                                                  0x0016
#define  TT_VBI_TT_DATA09_tt_ttdata7_shift                                      (24)
#define  TT_VBI_TT_DATA09_tt_ttdata6_shift                                      (16)
#define  TT_VBI_TT_DATA09_tt_ttdata5_shift                                      (8)
#define  TT_VBI_TT_DATA09_tt_ttdata4_shift                                      (0)
#define  TT_VBI_TT_DATA09_tt_ttdata7_mask                                       (0xFF000000)
#define  TT_VBI_TT_DATA09_tt_ttdata6_mask                                       (0x00FF0000)
#define  TT_VBI_TT_DATA09_tt_ttdata5_mask                                       (0x0000FF00)
#define  TT_VBI_TT_DATA09_tt_ttdata4_mask                                       (0x000000FF)
#define  TT_VBI_TT_DATA09_tt_ttdata7(data)                                      (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA09_tt_ttdata6(data)                                      (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA09_tt_ttdata5(data)                                      (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA09_tt_ttdata4(data)                                      (0x000000FF&(data))
#define  TT_VBI_TT_DATA09_get_tt_ttdata7(data)                                  ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA09_get_tt_ttdata6(data)                                  ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA09_get_tt_ttdata5(data)                                  ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA09_get_tt_ttdata4(data)                                  (0x000000FF&(data))

#define  TT_VBI_TT_DATA10                                                       0x18030940
#define  TT_VBI_TT_DATA10_reg_addr                                              "0xB8030940"
#define  TT_VBI_TT_DATA10_reg                                                   0xB8030940
#define  TT_VBI_TT_DATA10_inst_addr                                             "0x0017"
#define  TT_VBI_TT_DATA10_inst                                                  0x0017
#define  TT_VBI_TT_DATA10_tt_ttdata3_shift                                      (24)
#define  TT_VBI_TT_DATA10_tt_ttdata2_shift                                      (16)
#define  TT_VBI_TT_DATA10_tt_ttdata1_shift                                      (8)
#define  TT_VBI_TT_DATA10_tt_ttdata0_shift                                      (0)
#define  TT_VBI_TT_DATA10_tt_ttdata3_mask                                       (0xFF000000)
#define  TT_VBI_TT_DATA10_tt_ttdata2_mask                                       (0x00FF0000)
#define  TT_VBI_TT_DATA10_tt_ttdata1_mask                                       (0x0000FF00)
#define  TT_VBI_TT_DATA10_tt_ttdata0_mask                                       (0x000000FF)
#define  TT_VBI_TT_DATA10_tt_ttdata3(data)                                      (0xFF000000&((data)<<24))
#define  TT_VBI_TT_DATA10_tt_ttdata2(data)                                      (0x00FF0000&((data)<<16))
#define  TT_VBI_TT_DATA10_tt_ttdata1(data)                                      (0x0000FF00&((data)<<8))
#define  TT_VBI_TT_DATA10_tt_ttdata0(data)                                      (0x000000FF&(data))
#define  TT_VBI_TT_DATA10_get_tt_ttdata3(data)                                  ((0xFF000000&(data))>>24)
#define  TT_VBI_TT_DATA10_get_tt_ttdata2(data)                                  ((0x00FF0000&(data))>>16)
#define  TT_VBI_TT_DATA10_get_tt_ttdata1(data)                                  ((0x0000FF00&(data))>>8)
#define  TT_VBI_TT_DATA10_get_tt_ttdata0(data)                                  (0x000000FF&(data))

#define  TT_VBI_Control_Register                                                0x18030A00
#define  TT_VBI_Control_Register_reg_addr                                       "0xB8030A00"
#define  TT_VBI_Control_Register_reg                                            0xB8030A00
#define  TT_VBI_Control_Register_inst_addr                                      "0x0018"
#define  TT_VBI_Control_Register_inst                                           0x0018
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl_wss_shift                     (24)
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl_shift                         (16)
#define  TT_VBI_Control_Register_tt_start_code_shift                            (8)
#define  TT_VBI_Control_Register_tt_adap_slvl_en_shift                          (5)
#define  TT_VBI_Control_Register_tt_vbi_muxout_shift                            (4)
#define  TT_VBI_Control_Register_tt_vbi_hsyncout_shift                          (3)
#define  TT_VBI_Control_Register_tt_vbi_long_st_sel_shift                       (2)
#define  TT_VBI_Control_Register_tt_vbi_st_err_ignored_shift                    (1)
#define  TT_VBI_Control_Register_tt_vbi_en_shift                                (0)
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl_wss_mask                      (0xFF000000)
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl_mask                          (0x00FF0000)
#define  TT_VBI_Control_Register_tt_start_code_mask                             (0x0000FF00)
#define  TT_VBI_Control_Register_tt_adap_slvl_en_mask                           (0x00000060)
#define  TT_VBI_Control_Register_tt_vbi_muxout_mask                             (0x00000010)
#define  TT_VBI_Control_Register_tt_vbi_hsyncout_mask                           (0x00000008)
#define  TT_VBI_Control_Register_tt_vbi_long_st_sel_mask                        (0x00000004)
#define  TT_VBI_Control_Register_tt_vbi_st_err_ignored_mask                     (0x00000002)
#define  TT_VBI_Control_Register_tt_vbi_en_mask                                 (0x00000001)
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl_wss(data)                     (0xFF000000&((data)<<24))
#define  TT_VBI_Control_Register_tt_vbi_data_hlvl(data)                         (0x00FF0000&((data)<<16))
#define  TT_VBI_Control_Register_tt_start_code(data)                            (0x0000FF00&((data)<<8))
#define  TT_VBI_Control_Register_tt_adap_slvl_en(data)                          (0x00000060&((data)<<5))
#define  TT_VBI_Control_Register_tt_vbi_muxout(data)                            (0x00000010&((data)<<4))
#define  TT_VBI_Control_Register_tt_vbi_hsyncout(data)                          (0x00000008&((data)<<3))
#define  TT_VBI_Control_Register_tt_vbi_long_st_sel(data)                       (0x00000004&((data)<<2))
#define  TT_VBI_Control_Register_tt_vbi_st_err_ignored(data)                    (0x00000002&((data)<<1))
#define  TT_VBI_Control_Register_tt_vbi_en(data)                                (0x00000001&(data))
#define  TT_VBI_Control_Register_get_tt_vbi_data_hlvl_wss(data)                 ((0xFF000000&(data))>>24)
#define  TT_VBI_Control_Register_get_tt_vbi_data_hlvl(data)                     ((0x00FF0000&(data))>>16)
#define  TT_VBI_Control_Register_get_tt_start_code(data)                        ((0x0000FF00&(data))>>8)
#define  TT_VBI_Control_Register_get_tt_adap_slvl_en(data)                      ((0x00000060&(data))>>5)
#define  TT_VBI_Control_Register_get_tt_vbi_muxout(data)                        ((0x00000010&(data))>>4)
#define  TT_VBI_Control_Register_get_tt_vbi_hsyncout(data)                      ((0x00000008&(data))>>3)
#define  TT_VBI_Control_Register_get_tt_vbi_long_st_sel(data)                   ((0x00000004&(data))>>2)
#define  TT_VBI_Control_Register_get_tt_vbi_st_err_ignored(data)                ((0x00000002&(data))>>1)
#define  TT_VBI_Control_Register_get_tt_vbi_en(data)                            (0x00000001&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8                               0x18030A04
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_reg_addr                      "0xB8030A04"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_reg                           0xB8030A04
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_inst_addr                     "0x0019"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_inst                          0x0019
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8e_shift               (28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8o_shift               (24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7e_shift               (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7o_shift               (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6e_shift               (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6o_shift               (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5e_shift               (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5o_shift               (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8e_mask                (0xF0000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8o_mask                (0x0F000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7e_mask                (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7o_mask                (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6e_mask                (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6o_mask                (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5e_mask                (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5o_mask                (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8e(data)               (0xF0000000&((data)<<28))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil8o(data)               (0x0F000000&((data)<<24))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7e(data)               (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil7o(data)               (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6e(data)               (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil6o(data)               (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5e(data)               (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_tt_vbil5o(data)               (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil8e(data)           ((0xF0000000&(data))>>28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil8o(data)           ((0x0F000000&(data))>>24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil7e(data)           ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil7o(data)           ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil6e(data)           ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil6o(data)           ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil5e(data)           ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_5_8_get_tt_vbil5o(data)           (0x0000000F&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12                              0x18030A08
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_reg_addr                     "0xB8030A08"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_reg                          0xB8030A08
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_inst_addr                    "0x001A"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_inst                         0x001A
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12e_shift             (28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12o_shift             (24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11e_shift             (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11o_shift             (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10e_shift             (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10o_shift             (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9e_shift              (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9o_shift              (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12e_mask              (0xF0000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12o_mask              (0x0F000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11e_mask              (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11o_mask              (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10e_mask              (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10o_mask              (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9e_mask               (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9o_mask               (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12e(data)             (0xF0000000&((data)<<28))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil12o(data)             (0x0F000000&((data)<<24))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11e(data)             (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil11o(data)             (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10e(data)             (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil10o(data)             (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9e(data)              (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_tt_vbil9o(data)              (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil12e(data)         ((0xF0000000&(data))>>28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil12o(data)         ((0x0F000000&(data))>>24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil11e(data)         ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil11o(data)         ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil10e(data)         ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil10o(data)         ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil9e(data)          ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_9_12_get_tt_vbil9o(data)          (0x0000000F&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16                             0x18030A0C
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_reg_addr                    "0xB8030A0C"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_reg                         0xB8030A0C
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_inst_addr                   "0x001B"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_inst                        0x001B
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16e_shift            (28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16o_shift            (24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15e_shift            (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15o_shift            (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14e_shift            (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14o_shift            (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13e_shift            (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13o_shift            (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16e_mask             (0xF0000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16o_mask             (0x0F000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15e_mask             (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15o_mask             (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14e_mask             (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14o_mask             (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13e_mask             (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13o_mask             (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16e(data)            (0xF0000000&((data)<<28))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil16o(data)            (0x0F000000&((data)<<24))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15e(data)            (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil15o(data)            (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14e(data)            (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil14o(data)            (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13e(data)            (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_tt_vbil13o(data)            (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil16e(data)        ((0xF0000000&(data))>>28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil16o(data)        ((0x0F000000&(data))>>24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil15e(data)        ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil15o(data)        ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil14e(data)        ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil14o(data)        ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil13e(data)        ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_get_tt_vbil13o(data)        (0x0000000F&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20                             0x18030A10
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg_addr                    "0xB8030A10"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg                         0xB8030A10
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_inst_addr                   "0x001C"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_inst                        0x001C
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20e_shift            (28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20o_shift            (24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19e_shift            (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19o_shift            (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18e_shift            (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18o_shift            (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17e_shift            (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17o_shift            (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20e_mask             (0xF0000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20o_mask             (0x0F000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19e_mask             (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19o_mask             (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18e_mask             (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18o_mask             (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17e_mask             (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17o_mask             (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20e(data)            (0xF0000000&((data)<<28))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil20o(data)            (0x0F000000&((data)<<24))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19e(data)            (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil19o(data)            (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18e(data)            (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil18o(data)            (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17e(data)            (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_tt_vbil17o(data)            (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil20e(data)        ((0xF0000000&(data))>>28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil20o(data)        ((0x0F000000&(data))>>24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil19e(data)        ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil19o(data)        ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil18e(data)        ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil18o(data)        ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil17e(data)        ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_get_tt_vbil17o(data)        (0x0000000F&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24                             0x18030A14
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_reg_addr                    "0xB8030A14"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_reg                         0xB8030A14
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_inst_addr                   "0x001D"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_inst                        0x001D
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24e_shift            (28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24o_shift            (24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23e_shift            (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23o_shift            (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22e_shift            (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22o_shift            (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21e_shift            (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21o_shift            (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24e_mask             (0xF0000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24o_mask             (0x0F000000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23e_mask             (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23o_mask             (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22e_mask             (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22o_mask             (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21e_mask             (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21o_mask             (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24e(data)            (0xF0000000&((data)<<28))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil24o(data)            (0x0F000000&((data)<<24))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23e(data)            (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil23o(data)            (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22e(data)            (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil22o(data)            (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21e(data)            (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_tt_vbil21o(data)            (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil24e(data)        ((0xF0000000&(data))>>28)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil24o(data)        ((0x0F000000&(data))>>24)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil23e(data)        ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil23o(data)        ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil22e(data)        ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil22o(data)        ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil21e(data)        ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_get_tt_vbil21o(data)        (0x0000000F&(data))

#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26                             0x18030A18
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_reg_addr                    "0xB8030A18"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_reg                         0xB8030A18
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_inst_addr                   "0x001E"
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_inst                        0x001E
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivpsl16e_shift         (20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivps16o_shift          (16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26e_shift            (12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26o_shift            (8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25e_shift            (4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25o_shift            (0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivpsl16e_mask          (0x00F00000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivps16o_mask           (0x000F0000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26e_mask             (0x0000F000)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26o_mask             (0x00000F00)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25e_mask             (0x000000F0)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25o_mask             (0x0000000F)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivpsl16e(data)         (0x00F00000&((data)<<20))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbivps16o(data)          (0x000F0000&((data)<<16))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26e(data)            (0x0000F000&((data)<<12))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil26o(data)            (0x00000F00&((data)<<8))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25e(data)            (0x000000F0&((data)<<4))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_tt_vbil25o(data)            (0x0000000F&(data))
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbivpsl16e(data)     ((0x00F00000&(data))>>20)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbivps16o(data)      ((0x000F0000&(data))>>16)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbil26e(data)        ((0x0000F000&(data))>>12)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbil26o(data)        ((0x00000F00&(data))>>8)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbil25e(data)        ((0x000000F0&(data))>>4)
#define  TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_25_26_get_tt_vbil25o(data)        (0x0000000F&(data))

#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER                                     0x18030A1C
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_reg_addr                            "0xB8030A1C"
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_reg                                 0xB8030A1C
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_inst_addr                           "0x001F"
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_inst                                0x001F
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_slicer_level_iir_shift       (16)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_vps_lpfil_gain_shift         (12)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_wss625_lpfil_gain_shift      (8)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_cc_lpfil_gain_shift          (4)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_tele_lpfil_gain_shift        (0)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_slicer_level_iir_mask        (0x01FF0000)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_vps_lpfil_gain_mask          (0x0000F000)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_wss625_lpfil_gain_mask       (0x00000F00)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_cc_lpfil_gain_mask           (0x000000F0)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_tele_lpfil_gain_mask         (0x0000000F)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_slicer_level_iir(data)       (0x01FF0000&((data)<<16))
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_vps_lpfil_gain(data)         (0x0000F000&((data)<<12))
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_wss625_lpfil_gain(data)      (0x00000F00&((data)<<8))
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_cc_lpfil_gain(data)          (0x000000F0&((data)<<4))
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_tt_vbi_tele_lpfil_gain(data)        (0x0000000F&(data))
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_get_tt_vbi_slicer_level_iir(data)   ((0x01FF0000&(data))>>16)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_get_tt_vbi_vps_lpfil_gain(data)     ((0x0000F000&(data))>>12)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_get_tt_vbi_wss625_lpfil_gain(data)  ((0x00000F00&(data))>>8)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_get_tt_vbi_cc_lpfil_gain(data)      ((0x000000F0&(data))>>4)
#define  TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_get_tt_vbi_tele_lpfil_gain(data)    (0x0000000F&(data))

#define  TT_VBI_DTO_REGISTER1                                                   0x18030A20
#define  TT_VBI_DTO_REGISTER1_reg_addr                                          "0xB8030A20"
#define  TT_VBI_DTO_REGISTER1_reg                                               0xB8030A20
#define  TT_VBI_DTO_REGISTER1_inst_addr                                         "0x0020"
#define  TT_VBI_DTO_REGISTER1_inst                                              0x0020
#define  TT_VBI_DTO_REGISTER1_tt_vbi_teletext_dto_shift                         (16)
#define  TT_VBI_DTO_REGISTER1_tt_vbi_caption_dto_shift                          (0)
#define  TT_VBI_DTO_REGISTER1_tt_vbi_teletext_dto_mask                          (0xFFFF0000)
#define  TT_VBI_DTO_REGISTER1_tt_vbi_caption_dto_mask                           (0x0000FFFF)
#define  TT_VBI_DTO_REGISTER1_tt_vbi_teletext_dto(data)                         (0xFFFF0000&((data)<<16))
#define  TT_VBI_DTO_REGISTER1_tt_vbi_caption_dto(data)                          (0x0000FFFF&(data))
#define  TT_VBI_DTO_REGISTER1_get_tt_vbi_teletext_dto(data)                     ((0xFFFF0000&(data))>>16)
#define  TT_VBI_DTO_REGISTER1_get_tt_vbi_caption_dto(data)                      (0x0000FFFF&(data))

#define  TT_VBI_DTO_REGISTER2                                                   0x18030A24
#define  TT_VBI_DTO_REGISTER2_reg_addr                                          "0xB8030A24"
#define  TT_VBI_DTO_REGISTER2_reg                                               0xB8030A24
#define  TT_VBI_DTO_REGISTER2_inst_addr                                         "0x0021"
#define  TT_VBI_DTO_REGISTER2_inst                                              0x0021
#define  TT_VBI_DTO_REGISTER2_tt_vbi_vps_dto_shift                              (16)
#define  TT_VBI_DTO_REGISTER2_tt_vbi_wss625_dto_shift                           (0)
#define  TT_VBI_DTO_REGISTER2_tt_vbi_vps_dto_mask                               (0xFFFF0000)
#define  TT_VBI_DTO_REGISTER2_tt_vbi_wss625_dto_mask                            (0x0000FFFF)
#define  TT_VBI_DTO_REGISTER2_tt_vbi_vps_dto(data)                              (0xFFFF0000&((data)<<16))
#define  TT_VBI_DTO_REGISTER2_tt_vbi_wss625_dto(data)                           (0x0000FFFF&(data))
#define  TT_VBI_DTO_REGISTER2_get_tt_vbi_vps_dto(data)                          ((0xFFFF0000&(data))>>16)
#define  TT_VBI_DTO_REGISTER2_get_tt_vbi_wss625_dto(data)                       (0x0000FFFF&(data))

#define  TT_VBI_DTO_FRAME_START                                                 0x18030A28
#define  TT_VBI_DTO_FRAME_START_reg_addr                                        "0xB8030A28"
#define  TT_VBI_DTO_FRAME_START_reg                                             0xB8030A28
#define  TT_VBI_DTO_FRAME_START_inst_addr                                       "0x0022"
#define  TT_VBI_DTO_FRAME_START_inst                                            0x0022
#define  TT_VBI_DTO_FRAME_START_tt_caption_frame_start_shift                    (24)
#define  TT_VBI_DTO_FRAME_START_tt_teletext_frame_start_shift                   (16)
#define  TT_VBI_DTO_FRAME_START_tt_wss625_frame_start_shift                     (8)
#define  TT_VBI_DTO_FRAME_START_tt_vps_frame_start_shift                        (0)
#define  TT_VBI_DTO_FRAME_START_tt_caption_frame_start_mask                     (0xFF000000)
#define  TT_VBI_DTO_FRAME_START_tt_teletext_frame_start_mask                    (0x00FF0000)
#define  TT_VBI_DTO_FRAME_START_tt_wss625_frame_start_mask                      (0x0000FF00)
#define  TT_VBI_DTO_FRAME_START_tt_vps_frame_start_mask                         (0x000000FF)
#define  TT_VBI_DTO_FRAME_START_tt_caption_frame_start(data)                    (0xFF000000&((data)<<24))
#define  TT_VBI_DTO_FRAME_START_tt_teletext_frame_start(data)                   (0x00FF0000&((data)<<16))
#define  TT_VBI_DTO_FRAME_START_tt_wss625_frame_start(data)                     (0x0000FF00&((data)<<8))
#define  TT_VBI_DTO_FRAME_START_tt_vps_frame_start(data)                        (0x000000FF&(data))
#define  TT_VBI_DTO_FRAME_START_get_tt_caption_frame_start(data)                ((0xFF000000&(data))>>24)
#define  TT_VBI_DTO_FRAME_START_get_tt_teletext_frame_start(data)               ((0x00FF0000&(data))>>16)
#define  TT_VBI_DTO_FRAME_START_get_tt_wss625_frame_start(data)                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_DTO_FRAME_START_get_tt_vps_frame_start(data)                    (0x000000FF&(data))

#define  TT_VBI_CCWSS_DATA                                                      0x18030A2C
#define  TT_VBI_CCWSS_DATA_reg_addr                                             "0xB8030A2C"
#define  TT_VBI_CCWSS_DATA_reg                                                  0xB8030A2C
#define  TT_VBI_CCWSS_DATA_inst_addr                                            "0x0023"
#define  TT_VBI_CCWSS_DATA_inst                                                 0x0023
#define  TT_VBI_CCWSS_DATA_tt_wssdata1_shift                                    (24)
#define  TT_VBI_CCWSS_DATA_tt_wssdata0_shift                                    (16)
#define  TT_VBI_CCWSS_DATA_tt_ccdata1_shift                                     (8)
#define  TT_VBI_CCWSS_DATA_tt_ccdata0_shift                                     (0)
#define  TT_VBI_CCWSS_DATA_tt_wssdata1_mask                                     (0xFF000000)
#define  TT_VBI_CCWSS_DATA_tt_wssdata0_mask                                     (0x00FF0000)
#define  TT_VBI_CCWSS_DATA_tt_ccdata1_mask                                      (0x0000FF00)
#define  TT_VBI_CCWSS_DATA_tt_ccdata0_mask                                      (0x000000FF)
#define  TT_VBI_CCWSS_DATA_tt_wssdata1(data)                                    (0xFF000000&((data)<<24))
#define  TT_VBI_CCWSS_DATA_tt_wssdata0(data)                                    (0x00FF0000&((data)<<16))
#define  TT_VBI_CCWSS_DATA_tt_ccdata1(data)                                     (0x0000FF00&((data)<<8))
#define  TT_VBI_CCWSS_DATA_tt_ccdata0(data)                                     (0x000000FF&(data))
#define  TT_VBI_CCWSS_DATA_get_tt_wssdata1(data)                                ((0xFF000000&(data))>>24)
#define  TT_VBI_CCWSS_DATA_get_tt_wssdata0(data)                                ((0x00FF0000&(data))>>16)
#define  TT_VBI_CCWSS_DATA_get_tt_ccdata1(data)                                 ((0x0000FF00&(data))>>8)
#define  TT_VBI_CCWSS_DATA_get_tt_ccdata0(data)                                 (0x000000FF&(data))

#define  TT_VBI_DATA_STATUS                                                     0x18030A30
#define  TT_VBI_DATA_STATUS_reg_addr                                            "0xB8030A30"
#define  TT_VBI_DATA_STATUS_reg                                                 0xB8030A30
#define  TT_VBI_DATA_STATUS_inst_addr                                           "0x0024"
#define  TT_VBI_DATA_STATUS_inst                                                0x0024
#define  TT_VBI_DATA_STATUS_tt_data_field_ind_shift                             (31)
#define  TT_VBI_DATA_STATUS_tt_wss_int_en_shift                                 (30)
#define  TT_VBI_DATA_STATUS_tt_cc_int_en_shift                                  (29)
#define  TT_VBI_DATA_STATUS_tt_vps_int_en_shift                                 (28)
#define  TT_VBI_DATA_STATUS_tt_tt_int_en_shift                                  (27)
#define  TT_VBI_DATA_STATUS_tt_int_clean_shift                                  (23)
#define  TT_VBI_DATA_STATUS_wss_int_clean_shift                                 (22)
#define  TT_VBI_DATA_STATUS_cc_int_clean_shift                                  (21)
#define  TT_VBI_DATA_STATUS_vps_int_clean_shift                                 (20)
#define  TT_VBI_DATA_STATUS_tt_tt_rdy_shift                                     (19)
#define  TT_VBI_DATA_STATUS_tt_wss_rdy_shift                                    (18)
#define  TT_VBI_DATA_STATUS_tt_cc_rdy_shift                                     (17)
#define  TT_VBI_DATA_STATUS_tt_vps_rdy_shift                                    (16)
#define  TT_VBI_DATA_STATUS_tt_vbi_noise_th_shift                               (8)
#define  TT_VBI_DATA_STATUS_tt_wssdata2_shift                                   (0)
#define  TT_VBI_DATA_STATUS_tt_data_field_ind_mask                              (0x80000000)
#define  TT_VBI_DATA_STATUS_tt_wss_int_en_mask                                  (0x40000000)
#define  TT_VBI_DATA_STATUS_tt_cc_int_en_mask                                   (0x20000000)
#define  TT_VBI_DATA_STATUS_tt_vps_int_en_mask                                  (0x10000000)
#define  TT_VBI_DATA_STATUS_tt_tt_int_en_mask                                   (0x08000000)
#define  TT_VBI_DATA_STATUS_tt_int_clean_mask                                   (0x00800000)
#define  TT_VBI_DATA_STATUS_wss_int_clean_mask                                  (0x00400000)
#define  TT_VBI_DATA_STATUS_cc_int_clean_mask                                   (0x00200000)
#define  TT_VBI_DATA_STATUS_vps_int_clean_mask                                  (0x00100000)
#define  TT_VBI_DATA_STATUS_tt_tt_rdy_mask                                      (0x00080000)
#define  TT_VBI_DATA_STATUS_tt_wss_rdy_mask                                     (0x00040000)
#define  TT_VBI_DATA_STATUS_tt_cc_rdy_mask                                      (0x00020000)
#define  TT_VBI_DATA_STATUS_tt_vps_rdy_mask                                     (0x00010000)
#define  TT_VBI_DATA_STATUS_tt_vbi_noise_th_mask                                (0x0000FF00)
#define  TT_VBI_DATA_STATUS_tt_wssdata2_mask                                    (0x000000FF)
#define  TT_VBI_DATA_STATUS_tt_data_field_ind(data)                             (0x80000000&((data)<<31))
#define  TT_VBI_DATA_STATUS_tt_wss_int_en(data)                                 (0x40000000&((data)<<30))
#define  TT_VBI_DATA_STATUS_tt_cc_int_en(data)                                  (0x20000000&((data)<<29))
#define  TT_VBI_DATA_STATUS_tt_vps_int_en(data)                                 (0x10000000&((data)<<28))
#define  TT_VBI_DATA_STATUS_tt_tt_int_en(data)                                  (0x08000000&((data)<<27))
#define  TT_VBI_DATA_STATUS_tt_int_clean(data)                                  (0x00800000&((data)<<23))
#define  TT_VBI_DATA_STATUS_wss_int_clean(data)                                 (0x00400000&((data)<<22))
#define  TT_VBI_DATA_STATUS_cc_int_clean(data)                                  (0x00200000&((data)<<21))
#define  TT_VBI_DATA_STATUS_vps_int_clean(data)                                 (0x00100000&((data)<<20))
#define  TT_VBI_DATA_STATUS_tt_tt_rdy(data)                                     (0x00080000&((data)<<19))
#define  TT_VBI_DATA_STATUS_tt_wss_rdy(data)                                    (0x00040000&((data)<<18))
#define  TT_VBI_DATA_STATUS_tt_cc_rdy(data)                                     (0x00020000&((data)<<17))
#define  TT_VBI_DATA_STATUS_tt_vps_rdy(data)                                    (0x00010000&((data)<<16))
#define  TT_VBI_DATA_STATUS_tt_vbi_noise_th(data)                               (0x0000FF00&((data)<<8))
#define  TT_VBI_DATA_STATUS_tt_wssdata2(data)                                   (0x000000FF&(data))
#define  TT_VBI_DATA_STATUS_get_tt_data_field_ind(data)                         ((0x80000000&(data))>>31)
#define  TT_VBI_DATA_STATUS_get_tt_wss_int_en(data)                             ((0x40000000&(data))>>30)
#define  TT_VBI_DATA_STATUS_get_tt_cc_int_en(data)                              ((0x20000000&(data))>>29)
#define  TT_VBI_DATA_STATUS_get_tt_vps_int_en(data)                             ((0x10000000&(data))>>28)
#define  TT_VBI_DATA_STATUS_get_tt_tt_int_en(data)                              ((0x08000000&(data))>>27)
#define  TT_VBI_DATA_STATUS_get_tt_int_clean(data)                              ((0x00800000&(data))>>23)
#define  TT_VBI_DATA_STATUS_get_wss_int_clean(data)                             ((0x00400000&(data))>>22)
#define  TT_VBI_DATA_STATUS_get_cc_int_clean(data)                              ((0x00200000&(data))>>21)
#define  TT_VBI_DATA_STATUS_get_vps_int_clean(data)                             ((0x00100000&(data))>>20)
#define  TT_VBI_DATA_STATUS_get_tt_tt_rdy(data)                                 ((0x00080000&(data))>>19)
#define  TT_VBI_DATA_STATUS_get_tt_wss_rdy(data)                                ((0x00040000&(data))>>18)
#define  TT_VBI_DATA_STATUS_get_tt_cc_rdy(data)                                 ((0x00020000&(data))>>17)
#define  TT_VBI_DATA_STATUS_get_tt_vps_rdy(data)                                ((0x00010000&(data))>>16)
#define  TT_VBI_DATA_STATUS_get_tt_vbi_noise_th(data)                           ((0x0000FF00&(data))>>8)
#define  TT_VBI_DATA_STATUS_get_tt_wssdata2(data)                               (0x000000FF&(data))

#define  TT_VBI_START                                                           0x18030A3C
#define  TT_VBI_START_reg_addr                                                  "0xB8030A3C"
#define  TT_VBI_START_reg                                                       0xB8030A3C
#define  TT_VBI_START_inst_addr                                                 "0x0025"
#define  TT_VBI_START_inst                                                      0x0025
#define  TT_VBI_START_tt_vbi_caption_start_shift                                (24)
#define  TT_VBI_START_tt_vbi_teletext_start_shift                               (16)
#define  TT_VBI_START_tt_vbi_wss625_start_shift                                 (8)
#define  TT_VBI_START_tt_vbi_vps_start_shift                                    (0)
#define  TT_VBI_START_tt_vbi_caption_start_mask                                 (0xFF000000)
#define  TT_VBI_START_tt_vbi_teletext_start_mask                                (0x00FF0000)
#define  TT_VBI_START_tt_vbi_wss625_start_mask                                  (0x0000FF00)
#define  TT_VBI_START_tt_vbi_vps_start_mask                                     (0x000000FF)
#define  TT_VBI_START_tt_vbi_caption_start(data)                                (0xFF000000&((data)<<24))
#define  TT_VBI_START_tt_vbi_teletext_start(data)                               (0x00FF0000&((data)<<16))
#define  TT_VBI_START_tt_vbi_wss625_start(data)                                 (0x0000FF00&((data)<<8))
#define  TT_VBI_START_tt_vbi_vps_start(data)                                    (0x000000FF&(data))
#define  TT_VBI_START_get_tt_vbi_caption_start(data)                            ((0xFF000000&(data))>>24)
#define  TT_VBI_START_get_tt_vbi_teletext_start(data)                           ((0x00FF0000&(data))>>16)
#define  TT_VBI_START_get_tt_vbi_wss625_start(data)                             ((0x0000FF00&(data))>>8)
#define  TT_VBI_START_get_tt_vbi_vps_start(data)                                (0x000000FF&(data))

#define  TT_VPS_DATA3                                                           0x18030A40
#define  TT_VPS_DATA3_reg_addr                                                  "0xB8030A40"
#define  TT_VPS_DATA3_reg                                                       0xB8030A40
#define  TT_VPS_DATA3_inst_addr                                                 "0x0026"
#define  TT_VPS_DATA3_inst                                                      0x0026
#define  TT_VPS_DATA3_tt_vbi_wss_slice_level_shift                              (8)
#define  TT_VPS_DATA3_tt_vpsdata3_shift                                         (0)
#define  TT_VPS_DATA3_tt_vbi_wss_slice_level_mask                               (0x0001FF00)
#define  TT_VPS_DATA3_tt_vpsdata3_mask                                          (0x000000FF)
#define  TT_VPS_DATA3_tt_vbi_wss_slice_level(data)                              (0x0001FF00&((data)<<8))
#define  TT_VPS_DATA3_tt_vpsdata3(data)                                         (0x000000FF&(data))
#define  TT_VPS_DATA3_get_tt_vbi_wss_slice_level(data)                          ((0x0001FF00&(data))>>8)
#define  TT_VPS_DATA3_get_tt_vpsdata3(data)                                     (0x000000FF&(data))

#define  TT_VPS_DATA2                                                           0x18030A44
#define  TT_VPS_DATA2_reg_addr                                                  "0xB8030A44"
#define  TT_VPS_DATA2_reg                                                       0xB8030A44
#define  TT_VPS_DATA2_inst_addr                                                 "0x0027"
#define  TT_VPS_DATA2_inst                                                      0x0027
#define  TT_VPS_DATA2_tt_vpsdata2_shift                                         (0)
#define  TT_VPS_DATA2_tt_vpsdata2_mask                                          (0xFFFFFFFF)
#define  TT_VPS_DATA2_tt_vpsdata2(data)                                         (0xFFFFFFFF&(data))
#define  TT_VPS_DATA2_get_tt_vpsdata2(data)                                     (0xFFFFFFFF&(data))

#define  TT_VPS_DATA1                                                           0x18030A48
#define  TT_VPS_DATA1_reg_addr                                                  "0xB8030A48"
#define  TT_VPS_DATA1_reg                                                       0xB8030A48
#define  TT_VPS_DATA1_inst_addr                                                 "0x0028"
#define  TT_VPS_DATA1_inst                                                      0x0028
#define  TT_VPS_DATA1_tt_vpsdata1_shift                                         (0)
#define  TT_VPS_DATA1_tt_vpsdata1_mask                                          (0xFFFFFFFF)
#define  TT_VPS_DATA1_tt_vpsdata1(data)                                         (0xFFFFFFFF&(data))
#define  TT_VPS_DATA1_get_tt_vpsdata1(data)                                     (0xFFFFFFFF&(data))

#define  TT_VPS_DATA0                                                           0x18030A4C
#define  TT_VPS_DATA0_reg_addr                                                  "0xB8030A4C"
#define  TT_VPS_DATA0_reg                                                       0xB8030A4C
#define  TT_VPS_DATA0_inst_addr                                                 "0x0029"
#define  TT_VPS_DATA0_inst                                                      0x0029
#define  TT_VPS_DATA0_tt_vpsdata0_shift                                         (0)
#define  TT_VPS_DATA0_tt_vpsdata0_mask                                          (0xFFFFFFFF)
#define  TT_VPS_DATA0_tt_vpsdata0(data)                                         (0xFFFFFFFF&(data))
#define  TT_VPS_DATA0_get_tt_vpsdata0(data)                                     (0xFFFFFFFF&(data))

#define  TT_VBI_NOISY_CTRL1                                                     0x18030A60
#define  TT_VBI_NOISY_CTRL1_reg_addr                                            "0xB8030A60"
#define  TT_VBI_NOISY_CTRL1_reg                                                 0xB8030A60
#define  TT_VBI_NOISY_CTRL1_inst_addr                                           "0x002A"
#define  TT_VBI_NOISY_CTRL1_inst                                                0x002A
#define  TT_VBI_NOISY_CTRL1_tt_vbi_data_hold_cyc_shift                          (31)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_fe_lpf_sel_shift                             (28)
#define  TT_VBI_NOISY_CTRL1_filter_gain_sel_shift                               (26)
#define  TT_VBI_NOISY_CTRL1_filter_coe_en_shift                                 (25)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_en_shift                      (24)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_thl_shift                     (16)
#define  TT_VBI_NOISY_CTRL1_filter_select_tap_shift                             (12)
#define  TT_VBI_NOISY_CTRL1_filter_coe_modify_shift                             (0)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_data_hold_cyc_mask                           (0x80000000)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_fe_lpf_sel_mask                              (0x30000000)
#define  TT_VBI_NOISY_CTRL1_filter_gain_sel_mask                                (0x0C000000)
#define  TT_VBI_NOISY_CTRL1_filter_coe_en_mask                                  (0x02000000)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_en_mask                       (0x01000000)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_thl_mask                      (0x00FF0000)
#define  TT_VBI_NOISY_CTRL1_filter_select_tap_mask                              (0x00007000)
#define  TT_VBI_NOISY_CTRL1_filter_coe_modify_mask                              (0x000007FF)
#define  TT_VBI_NOISY_CTRL1_tt_vbi_data_hold_cyc(data)                          (0x80000000&((data)<<31))
#define  TT_VBI_NOISY_CTRL1_tt_vbi_fe_lpf_sel(data)                             (0x30000000&((data)<<28))
#define  TT_VBI_NOISY_CTRL1_filter_gain_sel(data)                               (0x0C000000&((data)<<26))
#define  TT_VBI_NOISY_CTRL1_filter_coe_en(data)                                 (0x02000000&((data)<<25))
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_en(data)                      (0x01000000&((data)<<24))
#define  TT_VBI_NOISY_CTRL1_tt_vbi_st_correlation_thl(data)                     (0x00FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL1_filter_select_tap(data)                             (0x00007000&((data)<<12))
#define  TT_VBI_NOISY_CTRL1_filter_coe_modify(data)                             (0x000007FF&(data))
#define  TT_VBI_NOISY_CTRL1_get_tt_vbi_data_hold_cyc(data)                      ((0x80000000&(data))>>31)
#define  TT_VBI_NOISY_CTRL1_get_tt_vbi_fe_lpf_sel(data)                         ((0x30000000&(data))>>28)
#define  TT_VBI_NOISY_CTRL1_get_filter_gain_sel(data)                           ((0x0C000000&(data))>>26)
#define  TT_VBI_NOISY_CTRL1_get_filter_coe_en(data)                             ((0x02000000&(data))>>25)
#define  TT_VBI_NOISY_CTRL1_get_tt_vbi_st_correlation_en(data)                  ((0x01000000&(data))>>24)
#define  TT_VBI_NOISY_CTRL1_get_tt_vbi_st_correlation_thl(data)                 ((0x00FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL1_get_filter_select_tap(data)                         ((0x00007000&(data))>>12)
#define  TT_VBI_NOISY_CTRL1_get_filter_coe_modify(data)                         (0x000007FF&(data))

#define  TT_VBI_NOISY_CTRL2                                                     0x18030A64
#define  TT_VBI_NOISY_CTRL2_reg_addr                                            "0xB8030A64"
#define  TT_VBI_NOISY_CTRL2_reg                                                 0xB8030A64
#define  TT_VBI_NOISY_CTRL2_inst_addr                                           "0x002B"
#define  TT_VBI_NOISY_CTRL2_inst                                                0x002B
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_en_shift                          (31)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_start_tt_shift                    (16)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_end_tt_shift                      (0)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_en_mask                           (0x80000000)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_start_tt_mask                     (0x03FF0000)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_end_tt_mask                       (0x000003FF)
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_en(data)                          (0x80000000&((data)<<31))
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_start_tt(data)                    (0x03FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL2_tt_vbi_out_hcount_end_tt(data)                      (0x000003FF&(data))
#define  TT_VBI_NOISY_CTRL2_get_tt_vbi_out_hcount_en(data)                      ((0x80000000&(data))>>31)
#define  TT_VBI_NOISY_CTRL2_get_tt_vbi_out_hcount_start_tt(data)                ((0x03FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL2_get_tt_vbi_out_hcount_end_tt(data)                  (0x000003FF&(data))

#define  TT_VBI_NOISY_CTRL3                                                     0x18030A68
#define  TT_VBI_NOISY_CTRL3_reg_addr                                            "0xB8030A68"
#define  TT_VBI_NOISY_CTRL3_reg                                                 0xB8030A68
#define  TT_VBI_NOISY_CTRL3_inst_addr                                           "0x002C"
#define  TT_VBI_NOISY_CTRL3_inst                                                0x002C
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_replace_en_shift            (31)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_substitute_data_shift       (16)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_parity_chk_en_shift                      (8)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_noise_filter_sw_shift                        (0)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_replace_en_mask             (0x80000000)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_substitute_data_mask        (0x00FF0000)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_parity_chk_en_mask                       (0x00000100)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_noise_filter_sw_mask                         (0x00000007)
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_replace_en(data)            (0x80000000&((data)<<31))
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_par_err_byte_substitute_data(data)       (0x00FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL3_tt_vbi_odd_parity_chk_en(data)                      (0x00000100&((data)<<8))
#define  TT_VBI_NOISY_CTRL3_tt_vbi_noise_filter_sw(data)                        (0x00000007&(data))
#define  TT_VBI_NOISY_CTRL3_get_tt_vbi_odd_par_err_byte_replace_en(data)        ((0x80000000&(data))>>31)
#define  TT_VBI_NOISY_CTRL3_get_tt_vbi_odd_par_err_byte_substitute_data(data)   ((0x00FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL3_get_tt_vbi_odd_parity_chk_en(data)                  ((0x00000100&(data))>>8)
#define  TT_VBI_NOISY_CTRL3_get_tt_vbi_noise_filter_sw(data)                    (0x00000007&(data))

#define  TT_VBI_CO_CH_CTRL                                                      0x18030A6C
#define  TT_VBI_CO_CH_CTRL_reg_addr                                             "0xB8030A6C"
#define  TT_VBI_CO_CH_CTRL_reg                                                  0xB8030A6C
#define  TT_VBI_CO_CH_CTRL_inst_addr                                            "0x002D"
#define  TT_VBI_CO_CH_CTRL_inst                                                 0x002D
#define  TT_VBI_CO_CH_CTRL_tt_coch_auto_compensate_en_shift                     (30)
#define  TT_VBI_CO_CH_CTRL_tt_coch_tran_thl_shift                               (4)
#define  TT_VBI_CO_CH_CTRL_tt_coch_noise_filter_sel_shift                       (0)
#define  TT_VBI_CO_CH_CTRL_tt_coch_auto_compensate_en_mask                      (0xC0000000)
#define  TT_VBI_CO_CH_CTRL_tt_coch_tran_thl_mask                                (0x00000FF0)
#define  TT_VBI_CO_CH_CTRL_tt_coch_noise_filter_sel_mask                        (0x00000001)
#define  TT_VBI_CO_CH_CTRL_tt_coch_auto_compensate_en(data)                     (0xC0000000&((data)<<30))
#define  TT_VBI_CO_CH_CTRL_tt_coch_tran_thl(data)                               (0x00000FF0&((data)<<4))
#define  TT_VBI_CO_CH_CTRL_tt_coch_noise_filter_sel(data)                       (0x00000001&(data))
#define  TT_VBI_CO_CH_CTRL_get_tt_coch_auto_compensate_en(data)                 ((0xC0000000&(data))>>30)
#define  TT_VBI_CO_CH_CTRL_get_tt_coch_tran_thl(data)                           ((0x00000FF0&(data))>>4)
#define  TT_VBI_CO_CH_CTRL_get_tt_coch_noise_filter_sel(data)                   (0x00000001&(data))

#define  TT_VBI_CLAMPAGC_CTRL                                                   0x18030A70
#define  TT_VBI_CLAMPAGC_CTRL_reg_addr                                          "0xB8030A70"
#define  TT_VBI_CLAMPAGC_CTRL_reg                                               0xB8030A70
#define  TT_VBI_CLAMPAGC_CTRL_inst_addr                                         "0x002E"
#define  TT_VBI_CLAMPAGC_CTRL_inst                                              0x002E
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_en_shift                             (31)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_sub_shift                   (20)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_add_shift                   (8)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dgain_shift                          (0)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_en_mask                              (0x80000000)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_sub_mask                    (0x1FF00000)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_add_mask                    (0x0001FF00)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dgain_mask                           (0x000000FF)
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_en(data)                             (0x80000000&((data)<<31))
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_sub(data)                   (0x1FF00000&((data)<<20))
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dc_level_add(data)                   (0x0001FF00&((data)<<8))
#define  TT_VBI_CLAMPAGC_CTRL_tt_vbi_clamp_dgain(data)                          (0x000000FF&(data))
#define  TT_VBI_CLAMPAGC_CTRL_get_tt_vbi_clamp_en(data)                         ((0x80000000&(data))>>31)
#define  TT_VBI_CLAMPAGC_CTRL_get_tt_vbi_clamp_dc_level_sub(data)               ((0x1FF00000&(data))>>20)
#define  TT_VBI_CLAMPAGC_CTRL_get_tt_vbi_clamp_dc_level_add(data)               ((0x0001FF00&(data))>>8)
#define  TT_VBI_CLAMPAGC_CTRL_get_tt_vbi_clamp_dgain(data)                      (0x000000FF&(data))

#define  TT_VBI_NOISY_CTRL                                                      0x18030A74
#define  TT_VBI_NOISY_CTRL_reg_addr                                             "0xB8030A74"
#define  TT_VBI_NOISY_CTRL_reg                                                  0xB8030A74
#define  TT_VBI_NOISY_CTRL_inst_addr                                            "0x002F"
#define  TT_VBI_NOISY_CTRL_inst                                                 0x002F
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start_shift                      (24)
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start_en_shift                   (20)
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_lpfil_gain_shift                  (16)
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_phase_inv_disable_shift           (13)
#define  TT_VBI_NOISY_CTRL_tt_vbi_phase_inv_en_shift                            (12)
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_en2_err_fix_en_shift                       (8)
#define  TT_VBI_NOISY_CTRL_tt_vbi_resample_filter_sel_shift                     (4)
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_loop_filter_round_sel_shift                (0)
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start_mask                       (0xFF000000)
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start_en_mask                    (0x00100000)
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_lpfil_gain_mask                   (0x000F0000)
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_phase_inv_disable_mask            (0x00002000)
#define  TT_VBI_NOISY_CTRL_tt_vbi_phase_inv_en_mask                             (0x00001000)
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_en2_err_fix_en_mask                        (0x00000100)
#define  TT_VBI_NOISY_CTRL_tt_vbi_resample_filter_sel_mask                      (0x00000010)
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_loop_filter_round_sel_mask                 (0x00000003)
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start(data)                      (0xFF000000&((data)<<24))
#define  TT_VBI_NOISY_CTRL_tt_vbi_slice_lv_fix_start_en(data)                   (0x00100000&((data)<<20))
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_lpfil_gain(data)                  (0x000F0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL_tt_vbi_data_region_phase_inv_disable(data)           (0x00002000&((data)<<13))
#define  TT_VBI_NOISY_CTRL_tt_vbi_phase_inv_en(data)                            (0x00001000&((data)<<12))
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_en2_err_fix_en(data)                       (0x00000100&((data)<<8))
#define  TT_VBI_NOISY_CTRL_tt_vbi_resample_filter_sel(data)                     (0x00000010&((data)<<4))
#define  TT_VBI_NOISY_CTRL_tt_vbi_pd_loop_filter_round_sel(data)                (0x00000003&(data))
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_slice_lv_fix_start(data)                  ((0xFF000000&(data))>>24)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_slice_lv_fix_start_en(data)               ((0x00100000&(data))>>20)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_data_region_lpfil_gain(data)              ((0x000F0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_data_region_phase_inv_disable(data)       ((0x00002000&(data))>>13)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_phase_inv_en(data)                        ((0x00001000&(data))>>12)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_pd_en2_err_fix_en(data)                   ((0x00000100&(data))>>8)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_resample_filter_sel(data)                 ((0x00000010&(data))>>4)
#define  TT_VBI_NOISY_CTRL_get_tt_vbi_pd_loop_filter_round_sel(data)            (0x00000003&(data))

#define  TT_VBI_PATTERN_SEL                                                     0x18030A78
#define  TT_VBI_PATTERN_SEL_reg_addr                                            "0xB8030A78"
#define  TT_VBI_PATTERN_SEL_reg                                                 0xB8030A78
#define  TT_VBI_PATTERN_SEL_inst_addr                                           "0x0030"
#define  TT_VBI_PATTERN_SEL_inst                                                0x0030
#define  TT_VBI_PATTERN_SEL_tt_vbi_slice_lv_fix_start_wss_shift                 (24)
#define  TT_VBI_PATTERN_SEL_tt_vbi_pattern_sel_shift                            (8)
#define  TT_VBI_PATTERN_SEL_tt_vbi_vps_pattern_set1_shift                       (0)
#define  TT_VBI_PATTERN_SEL_tt_vbi_slice_lv_fix_start_wss_mask                  (0xFF000000)
#define  TT_VBI_PATTERN_SEL_tt_vbi_pattern_sel_mask                             (0x00003F00)
#define  TT_VBI_PATTERN_SEL_tt_vbi_vps_pattern_set1_mask                        (0x000000FF)
#define  TT_VBI_PATTERN_SEL_tt_vbi_slice_lv_fix_start_wss(data)                 (0xFF000000&((data)<<24))
#define  TT_VBI_PATTERN_SEL_tt_vbi_pattern_sel(data)                            (0x00003F00&((data)<<8))
#define  TT_VBI_PATTERN_SEL_tt_vbi_vps_pattern_set1(data)                       (0x000000FF&(data))
#define  TT_VBI_PATTERN_SEL_get_tt_vbi_slice_lv_fix_start_wss(data)             ((0xFF000000&(data))>>24)
#define  TT_VBI_PATTERN_SEL_get_tt_vbi_pattern_sel(data)                        ((0x00003F00&(data))>>8)
#define  TT_VBI_PATTERN_SEL_get_tt_vbi_vps_pattern_set1(data)                   (0x000000FF&(data))

#define  TT_VBI_PATTERN_SEL1                                                    0x18030A7C
#define  TT_VBI_PATTERN_SEL1_reg_addr                                           "0xB8030A7C"
#define  TT_VBI_PATTERN_SEL1_reg                                                0xB8030A7C
#define  TT_VBI_PATTERN_SEL1_inst_addr                                          "0x0031"
#define  TT_VBI_PATTERN_SEL1_inst                                               0x0031
#define  TT_VBI_PATTERN_SEL1_tt_vbi_vps_pattern_set2_shift                      (0)
#define  TT_VBI_PATTERN_SEL1_tt_vbi_vps_pattern_set2_mask                       (0xFFFFFFFF)
#define  TT_VBI_PATTERN_SEL1_tt_vbi_vps_pattern_set2(data)                      (0xFFFFFFFF&(data))
#define  TT_VBI_PATTERN_SEL1_get_tt_vbi_vps_pattern_set2(data)                  (0xFFFFFFFF&(data))

#define  TT_VBI_PATTERN_SEL2                                                    0x18030A80
#define  TT_VBI_PATTERN_SEL2_reg_addr                                           "0xB8030A80"
#define  TT_VBI_PATTERN_SEL2_reg                                                0xB8030A80
#define  TT_VBI_PATTERN_SEL2_inst_addr                                          "0x0032"
#define  TT_VBI_PATTERN_SEL2_inst                                               0x0032
#define  TT_VBI_PATTERN_SEL2_tt_vbi_vps_pattern_set3_shift                      (0)
#define  TT_VBI_PATTERN_SEL2_tt_vbi_vps_pattern_set3_mask                       (0xFFFFFFFF)
#define  TT_VBI_PATTERN_SEL2_tt_vbi_vps_pattern_set3(data)                      (0xFFFFFFFF&(data))
#define  TT_VBI_PATTERN_SEL2_get_tt_vbi_vps_pattern_set3(data)                  (0xFFFFFFFF&(data))

#define  TT_VBI_PATTERN_SEL3                                                    0x18030A84
#define  TT_VBI_PATTERN_SEL3_reg_addr                                           "0xB8030A84"
#define  TT_VBI_PATTERN_SEL3_reg                                                0xB8030A84
#define  TT_VBI_PATTERN_SEL3_inst_addr                                          "0x0033"
#define  TT_VBI_PATTERN_SEL3_inst                                               0x0033
#define  TT_VBI_PATTERN_SEL3_tt_vbi_vps_pattern_set4_shift                      (0)
#define  TT_VBI_PATTERN_SEL3_tt_vbi_vps_pattern_set4_mask                       (0xFFFFFFFF)
#define  TT_VBI_PATTERN_SEL3_tt_vbi_vps_pattern_set4(data)                      (0xFFFFFFFF&(data))
#define  TT_VBI_PATTERN_SEL3_get_tt_vbi_vps_pattern_set4(data)                  (0xFFFFFFFF&(data))

#define  TT_VBI_NOISY_CTRL4                                                     0x18030A88
#define  TT_VBI_NOISY_CTRL4_reg_addr                                            "0xB8030A88"
#define  TT_VBI_NOISY_CTRL4_reg                                                 0xB8030A88
#define  TT_VBI_NOISY_CTRL4_inst_addr                                           "0x0034"
#define  TT_VBI_NOISY_CTRL4_inst                                                0x0034
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_en_vps_shift                      (31)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_start_vps_shift                   (16)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_end_vps_shift                     (0)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_en_vps_mask                       (0x80000000)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_start_vps_mask                    (0x03FF0000)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_end_vps_mask                      (0x000003FF)
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_en_vps(data)                      (0x80000000&((data)<<31))
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_start_vps(data)                   (0x03FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_end_vps(data)                     (0x000003FF&(data))
#define  TT_VBI_NOISY_CTRL4_get_tt_vbi_out_hcount_en_vps(data)                  ((0x80000000&(data))>>31)
#define  TT_VBI_NOISY_CTRL4_get_tt_vbi_out_hcount_start_vps(data)               ((0x03FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL4_get_tt_vbi_out_hcount_end_vps(data)                 (0x000003FF&(data))

#define  TT_VBI_NOISY_CTRL5                                                     0x18030A8C
#define  TT_VBI_NOISY_CTRL5_reg_addr                                            "0xB8030A8C"
#define  TT_VBI_NOISY_CTRL5_reg                                                 0xB8030A8C
#define  TT_VBI_NOISY_CTRL5_inst_addr                                           "0x0035"
#define  TT_VBI_NOISY_CTRL5_inst                                                0x0035
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_en_wss_shift                      (31)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_start_wss_shift                   (16)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_end_wss_shift                     (0)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_en_wss_mask                       (0x80000000)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_start_wss_mask                    (0x03FF0000)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_end_wss_mask                      (0x000003FF)
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_en_wss(data)                      (0x80000000&((data)<<31))
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_start_wss(data)                   (0x03FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL5_tt_vbi_out_hcount_end_wss(data)                     (0x000003FF&(data))
#define  TT_VBI_NOISY_CTRL5_get_tt_vbi_out_hcount_en_wss(data)                  ((0x80000000&(data))>>31)
#define  TT_VBI_NOISY_CTRL5_get_tt_vbi_out_hcount_start_wss(data)               ((0x03FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL5_get_tt_vbi_out_hcount_end_wss(data)                 (0x000003FF&(data))

#define  TT_VBI_NOISY_CTRL6                                                     0x18030A90
#define  TT_VBI_NOISY_CTRL6_reg_addr                                            "0xB8030A90"
#define  TT_VBI_NOISY_CTRL6_reg                                                 0xB8030A90
#define  TT_VBI_NOISY_CTRL6_inst_addr                                           "0x0036"
#define  TT_VBI_NOISY_CTRL6_inst                                                0x0036
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_vps_shift                  (28)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_vps_shift                 (16)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_wss_shift                  (12)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_wss_shift                 (0)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_vps_mask                   (0x10000000)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_vps_mask                  (0x03FF0000)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_wss_mask                   (0x00001000)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_wss_mask                  (0x000003FF)
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_vps(data)                  (0x10000000&((data)<<28))
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_vps(data)                 (0x03FF0000&((data)<<16))
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_en_wss(data)                  (0x00001000&((data)<<12))
#define  TT_VBI_NOISY_CTRL6_tt_vbi_st_correlation_thl_wss(data)                 (0x000003FF&(data))
#define  TT_VBI_NOISY_CTRL6_get_tt_vbi_st_correlation_en_vps(data)              ((0x10000000&(data))>>28)
#define  TT_VBI_NOISY_CTRL6_get_tt_vbi_st_correlation_thl_vps(data)             ((0x03FF0000&(data))>>16)
#define  TT_VBI_NOISY_CTRL6_get_tt_vbi_st_correlation_en_wss(data)              ((0x00001000&(data))>>12)
#define  TT_VBI_NOISY_CTRL6_get_tt_vbi_st_correlation_thl_wss(data)             (0x000003FF&(data))

#define  TT_VBI_STATUS1                                                         0x18030A94
#define  TT_VBI_STATUS1_reg_addr                                                "0xB8030A94"
#define  TT_VBI_STATUS1_reg                                                     0xB8030A94
#define  TT_VBI_STATUS1_inst_addr                                               "0x0037"
#define  TT_VBI_STATUS1_inst                                                    0x0037
#define  TT_VBI_STATUS1_tt_vbi_slice_data_en_shift                              (31)
#define  TT_VBI_STATUS1_tt_vbi_select_line_shift                                (16)
#define  TT_VBI_STATUS1_tt_vbi_hcount_st_shift                                  (0)
#define  TT_VBI_STATUS1_tt_vbi_slice_data_en_mask                               (0x80000000)
#define  TT_VBI_STATUS1_tt_vbi_select_line_mask                                 (0x03FF0000)
#define  TT_VBI_STATUS1_tt_vbi_hcount_st_mask                                   (0x000003FF)
#define  TT_VBI_STATUS1_tt_vbi_slice_data_en(data)                              (0x80000000&((data)<<31))
#define  TT_VBI_STATUS1_tt_vbi_select_line(data)                                (0x03FF0000&((data)<<16))
#define  TT_VBI_STATUS1_tt_vbi_hcount_st(data)                                  (0x000003FF&(data))
#define  TT_VBI_STATUS1_get_tt_vbi_slice_data_en(data)                          ((0x80000000&(data))>>31)
#define  TT_VBI_STATUS1_get_tt_vbi_select_line(data)                            ((0x03FF0000&(data))>>16)
#define  TT_VBI_STATUS1_get_tt_vbi_hcount_st(data)                              (0x000003FF&(data))

#define  TT_VBI_STATUS2                                                         0x18030A98
#define  TT_VBI_STATUS2_reg_addr                                                "0xB8030A98"
#define  TT_VBI_STATUS2_reg                                                     0xB8030A98
#define  TT_VBI_STATUS2_inst_addr                                               "0x0038"
#define  TT_VBI_STATUS2_inst                                                    0x0038
#define  TT_VBI_STATUS2_tt_vbi_slice_data_1_shift                               (0)
#define  TT_VBI_STATUS2_tt_vbi_slice_data_1_mask                                (0xFFFFFFFF)
#define  TT_VBI_STATUS2_tt_vbi_slice_data_1(data)                               (0xFFFFFFFF&(data))
#define  TT_VBI_STATUS2_get_tt_vbi_slice_data_1(data)                           (0xFFFFFFFF&(data))

#define  TT_VBI_STATUS3                                                         0x18030A9C
#define  TT_VBI_STATUS3_reg_addr                                                "0xB8030A9C"
#define  TT_VBI_STATUS3_reg                                                     0xB8030A9C
#define  TT_VBI_STATUS3_inst_addr                                               "0x0039"
#define  TT_VBI_STATUS3_inst                                                    0x0039
#define  TT_VBI_STATUS3_tt_vbi_slice_data_0_shift                               (0)
#define  TT_VBI_STATUS3_tt_vbi_slice_data_0_mask                                (0xFFFFFFFF)
#define  TT_VBI_STATUS3_tt_vbi_slice_data_0(data)                               (0xFFFFFFFF&(data))
#define  TT_VBI_STATUS3_get_tt_vbi_slice_data_0(data)                           (0xFFFFFFFF&(data))

#define  TT_VBI_STATUS4                                                         0x18030AA0
#define  TT_VBI_STATUS4_reg_addr                                                "0xB8030AA0"
#define  TT_VBI_STATUS4_reg                                                     0xB8030AA0
#define  TT_VBI_STATUS4_inst_addr                                               "0x003A"
#define  TT_VBI_STATUS4_inst                                                    0x003A
#define  TT_VBI_STATUS4_tt_vbi_line_detect_shift                                (0)
#define  TT_VBI_STATUS4_tt_vbi_line_detect_mask                                 (0x000FFFFF)
#define  TT_VBI_STATUS4_tt_vbi_line_detect(data)                                (0x000FFFFF&(data))
#define  TT_VBI_STATUS4_get_tt_vbi_line_detect(data)                            (0x000FFFFF&(data))

#define  TT_VBI_DUMP_DATA1                                                      0x18030AA4
#define  TT_VBI_DUMP_DATA1_reg_addr                                             "0xB8030AA4"
#define  TT_VBI_DUMP_DATA1_reg                                                  0xB8030AA4
#define  TT_VBI_DUMP_DATA1_inst_addr                                            "0x003B"
#define  TT_VBI_DUMP_DATA1_inst                                                 0x003B
#define  TT_VBI_DUMP_DATA1_vbi_dump_rowdata_en_shift                            (28)
#define  TT_VBI_DUMP_DATA1_vbi_dump_ttdata_en_shift                             (24)
#define  TT_VBI_DUMP_DATA1_vbi_dump_line_num_shift                              (0)
#define  TT_VBI_DUMP_DATA1_vbi_dump_rowdata_en_mask                             (0x10000000)
#define  TT_VBI_DUMP_DATA1_vbi_dump_ttdata_en_mask                              (0x01000000)
#define  TT_VBI_DUMP_DATA1_vbi_dump_line_num_mask                               (0x00FFFFFF)
#define  TT_VBI_DUMP_DATA1_vbi_dump_rowdata_en(data)                            (0x10000000&((data)<<28))
#define  TT_VBI_DUMP_DATA1_vbi_dump_ttdata_en(data)                             (0x01000000&((data)<<24))
#define  TT_VBI_DUMP_DATA1_vbi_dump_line_num(data)                              (0x00FFFFFF&(data))
#define  TT_VBI_DUMP_DATA1_get_vbi_dump_rowdata_en(data)                        ((0x10000000&(data))>>28)
#define  TT_VBI_DUMP_DATA1_get_vbi_dump_ttdata_en(data)                         ((0x01000000&(data))>>24)
#define  TT_VBI_DUMP_DATA1_get_vbi_dump_line_num(data)                          (0x00FFFFFF&(data))

#define  TT_VBI_DUMP_DATA2                                                      0x18030AA8
#define  TT_VBI_DUMP_DATA2_reg_addr                                             "0xB8030AA8"
#define  TT_VBI_DUMP_DATA2_reg                                                  0xB8030AA8
#define  TT_VBI_DUMP_DATA2_inst_addr                                            "0x003C"
#define  TT_VBI_DUMP_DATA2_inst                                                 0x003C
#define  TT_VBI_DUMP_DATA2_vbi_dump_overhead_shift                              (28)
#define  TT_VBI_DUMP_DATA2_vbi_dump_tt_det_shift                                (25)
#define  TT_VBI_DUMP_DATA2_vbi_dump_field_sel_shift                             (24)
#define  TT_VBI_DUMP_DATA2_vbi_dump_byte_num_shift                              (12)
#define  TT_VBI_DUMP_DATA2_vbi_dump_hcount_st_shift                             (0)
#define  TT_VBI_DUMP_DATA2_vbi_dump_overhead_mask                               (0x10000000)
#define  TT_VBI_DUMP_DATA2_vbi_dump_tt_det_mask                                 (0x02000000)
#define  TT_VBI_DUMP_DATA2_vbi_dump_field_sel_mask                              (0x01000000)
#define  TT_VBI_DUMP_DATA2_vbi_dump_byte_num_mask                               (0x003FF000)
#define  TT_VBI_DUMP_DATA2_vbi_dump_hcount_st_mask                              (0x000003FF)
#define  TT_VBI_DUMP_DATA2_vbi_dump_overhead(data)                              (0x10000000&((data)<<28))
#define  TT_VBI_DUMP_DATA2_vbi_dump_tt_det(data)                                (0x02000000&((data)<<25))
#define  TT_VBI_DUMP_DATA2_vbi_dump_field_sel(data)                             (0x01000000&((data)<<24))
#define  TT_VBI_DUMP_DATA2_vbi_dump_byte_num(data)                              (0x003FF000&((data)<<12))
#define  TT_VBI_DUMP_DATA2_vbi_dump_hcount_st(data)                             (0x000003FF&(data))
#define  TT_VBI_DUMP_DATA2_get_vbi_dump_overhead(data)                          ((0x10000000&(data))>>28)
#define  TT_VBI_DUMP_DATA2_get_vbi_dump_tt_det(data)                            ((0x02000000&(data))>>25)
#define  TT_VBI_DUMP_DATA2_get_vbi_dump_field_sel(data)                         ((0x01000000&(data))>>24)
#define  TT_VBI_DUMP_DATA2_get_vbi_dump_byte_num(data)                          ((0x003FF000&(data))>>12)
#define  TT_VBI_DUMP_DATA2_get_vbi_dump_hcount_st(data)                         (0x000003FF&(data))

#define  TT_VBI_ODD_PARIORITY_RECOVERY                                          0x18030AAC
#define  TT_VBI_ODD_PARIORITY_RECOVERY_reg_addr                                 "0xB8030AAC"
#define  TT_VBI_ODD_PARIORITY_RECOVERY_reg                                      0xB8030AAC
#define  TT_VBI_ODD_PARIORITY_RECOVERY_inst_addr                                "0x003D"
#define  TT_VBI_ODD_PARIORITY_RECOVERY_inst                                     0x003D
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_err_bit_correct_en_shift  (7)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_dc_shift                  (4)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_parity_chk_th_shift           (0)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_err_bit_correct_en_mask   (0x00000080)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_dc_mask                   (0x00000070)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_parity_chk_th_mask            (0x0000000F)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_err_bit_correct_en(data)  (0x00000080&((data)<<7))
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_par_dc(data)                  (0x00000070&((data)<<4))
#define  TT_VBI_ODD_PARIORITY_RECOVERY_tt_vbi_odd_parity_chk_th(data)           (0x0000000F&(data))
#define  TT_VBI_ODD_PARIORITY_RECOVERY_get_tt_vbi_odd_par_err_bit_correct_en(data)((0x00000080&(data))>>7)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_get_tt_vbi_odd_par_dc(data)              ((0x00000070&(data))>>4)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_get_tt_vbi_odd_parity_chk_th(data)       (0x0000000F&(data))

#define  TT_VBI_ODD_PARIORITY_RECOVERY_1                                        0x18030AB0
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_reg_addr                               "0xB8030AB0"
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_reg                                    0xB8030AB0
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_inst_addr                              "0x003E"
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_inst                                   0x003E
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_tt_vbi_odd_par_line_en_shift           (0)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_tt_vbi_odd_par_line_en_mask            (0x03FFFFFF)
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_tt_vbi_odd_par_line_en(data)           (0x03FFFFFF&(data))
#define  TT_VBI_ODD_PARIORITY_RECOVERY_1_get_tt_vbi_odd_par_line_en(data)       (0x03FFFFFF&(data))

#define  TT_VBI_AGC_SLICE_LEVEL                                                 0x18030AB4
#define  TT_VBI_AGC_SLICE_LEVEL_reg_addr                                        "0xB8030AB4"
#define  TT_VBI_AGC_SLICE_LEVEL_reg                                             0xB8030AB4
#define  TT_VBI_AGC_SLICE_LEVEL_inst_addr                                       "0x003F"
#define  TT_VBI_AGC_SLICE_LEVEL_inst                                            0x003F
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_en_shift                                 (31)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_data_error_filter_sel_shift                  (30)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_comp_w_data_shift                        (28)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_start_shift                         (20)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_diff_th_shift                            (12)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_circle_shift                        (0)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_en_mask                                  (0x80000000)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_data_error_filter_sel_mask                   (0x40000000)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_comp_w_data_mask                         (0x10000000)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_start_mask                          (0x0FF00000)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_diff_th_mask                             (0x000FF000)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_circle_mask                         (0x00000FFF)
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_en(data)                                 (0x80000000&((data)<<31))
#define  TT_VBI_AGC_SLICE_LEVEL_tt_data_error_filter_sel(data)                  (0x40000000&((data)<<30))
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_comp_w_data(data)                        (0x10000000&((data)<<28))
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_start(data)                         (0x0FF00000&((data)<<20))
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_diff_th(data)                            (0x000FF000&((data)<<12))
#define  TT_VBI_AGC_SLICE_LEVEL_tt_agc_line_circle(data)                        (0x00000FFF&(data))
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_agc_en(data)                             ((0x80000000&(data))>>31)
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_data_error_filter_sel(data)              ((0x40000000&(data))>>30)
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_agc_comp_w_data(data)                    ((0x10000000&(data))>>28)
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_agc_line_start(data)                     ((0x0FF00000&(data))>>20)
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_agc_diff_th(data)                        ((0x000FF000&(data))>>12)
#define  TT_VBI_AGC_SLICE_LEVEL_get_tt_agc_line_circle(data)                    (0x00000FFF&(data))

#define  TT_VBI_AGC_SLICE_LEVEL1                                                0x18030AB8
#define  TT_VBI_AGC_SLICE_LEVEL1_reg_addr                                       "0xB8030AB8"
#define  TT_VBI_AGC_SLICE_LEVEL1_reg                                            0xB8030AB8
#define  TT_VBI_AGC_SLICE_LEVEL1_inst_addr                                      "0x0040"
#define  TT_VBI_AGC_SLICE_LEVEL1_inst                                           0x0040
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_ignor_shift                      (24)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_dn_shift                   (12)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_up_shift                   (0)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_ignor_mask                       (0xFF000000)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_dn_mask                    (0x00FFF000)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_up_mask                    (0x00000FFF)
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_ignor(data)                      (0xFF000000&((data)<<24))
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_dn(data)                   (0x00FFF000&((data)<<12))
#define  TT_VBI_AGC_SLICE_LEVEL1_tt_data_error_count_up(data)                   (0x00000FFF&(data))
#define  TT_VBI_AGC_SLICE_LEVEL1_get_tt_data_error_ignor(data)                  ((0xFF000000&(data))>>24)
#define  TT_VBI_AGC_SLICE_LEVEL1_get_tt_data_error_count_dn(data)               ((0x00FFF000&(data))>>12)
#define  TT_VBI_AGC_SLICE_LEVEL1_get_tt_data_error_count_up(data)               (0x00000FFF&(data))

#define  TT_VBI_AGC_SLICE_LEVEL2                                                0x18030ABC
#define  TT_VBI_AGC_SLICE_LEVEL2_reg_addr                                       "0xB8030ABC"
#define  TT_VBI_AGC_SLICE_LEVEL2_reg                                            0xB8030ABC
#define  TT_VBI_AGC_SLICE_LEVEL2_inst_addr                                      "0x0041"
#define  TT_VBI_AGC_SLICE_LEVEL2_inst                                           0x0041
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_vbi_slicer_level_agc_shift                  (16)
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_data_error_diff_rat_shift                   (0)
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_vbi_slicer_level_agc_mask                   (0x01FF0000)
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_data_error_diff_rat_mask                    (0x0000000F)
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_vbi_slicer_level_agc(data)                  (0x01FF0000&((data)<<16))
#define  TT_VBI_AGC_SLICE_LEVEL2_tt_data_error_diff_rat(data)                   (0x0000000F&(data))
#define  TT_VBI_AGC_SLICE_LEVEL2_get_tt_vbi_slicer_level_agc(data)              ((0x01FF0000&(data))>>16)
#define  TT_VBI_AGC_SLICE_LEVEL2_get_tt_data_error_diff_rat(data)               (0x0000000F&(data))

#define  TT_VBI_WSS_VPS_VOTE                                                    0x18030AC0
#define  TT_VBI_WSS_VPS_VOTE_reg_addr                                           "0xB8030AC0"
#define  TT_VBI_WSS_VPS_VOTE_reg                                                0xB8030AC0
#define  TT_VBI_WSS_VPS_VOTE_inst_addr                                          "0x0042"
#define  TT_VBI_WSS_VPS_VOTE_inst                                               0x0042
#define  TT_VBI_WSS_VPS_VOTE_tt_start_code_ignor_num_shift                      (28)
#define  TT_VBI_WSS_VPS_VOTE_wss_data_sel_shift                                 (27)
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_en_shift                                  (25)
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_en_shift                                  (24)
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_thl_shift                                 (16)
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_thl_shift                                 (8)
#define  TT_VBI_WSS_VPS_VOTE_vps_start_code_ignor_num_shift                     (4)
#define  TT_VBI_WSS_VPS_VOTE_wss_start_code_ignor_num_shift                     (0)
#define  TT_VBI_WSS_VPS_VOTE_tt_start_code_ignor_num_mask                       (0xF0000000)
#define  TT_VBI_WSS_VPS_VOTE_wss_data_sel_mask                                  (0x08000000)
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_en_mask                                   (0x02000000)
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_en_mask                                   (0x01000000)
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_thl_mask                                  (0x00FF0000)
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_thl_mask                                  (0x0000FF00)
#define  TT_VBI_WSS_VPS_VOTE_vps_start_code_ignor_num_mask                      (0x000000F0)
#define  TT_VBI_WSS_VPS_VOTE_wss_start_code_ignor_num_mask                      (0x0000000F)
#define  TT_VBI_WSS_VPS_VOTE_tt_start_code_ignor_num(data)                      (0xF0000000&((data)<<28))
#define  TT_VBI_WSS_VPS_VOTE_wss_data_sel(data)                                 (0x08000000&((data)<<27))
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_en(data)                                  (0x02000000&((data)<<25))
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_en(data)                                  (0x01000000&((data)<<24))
#define  TT_VBI_WSS_VPS_VOTE_vps_vote_thl(data)                                 (0x00FF0000&((data)<<16))
#define  TT_VBI_WSS_VPS_VOTE_wss_vote_thl(data)                                 (0x0000FF00&((data)<<8))
#define  TT_VBI_WSS_VPS_VOTE_vps_start_code_ignor_num(data)                     (0x000000F0&((data)<<4))
#define  TT_VBI_WSS_VPS_VOTE_wss_start_code_ignor_num(data)                     (0x0000000F&(data))
#define  TT_VBI_WSS_VPS_VOTE_get_tt_start_code_ignor_num(data)                  ((0xF0000000&(data))>>28)
#define  TT_VBI_WSS_VPS_VOTE_get_wss_data_sel(data)                             ((0x08000000&(data))>>27)
#define  TT_VBI_WSS_VPS_VOTE_get_vps_vote_en(data)                              ((0x02000000&(data))>>25)
#define  TT_VBI_WSS_VPS_VOTE_get_wss_vote_en(data)                              ((0x01000000&(data))>>24)
#define  TT_VBI_WSS_VPS_VOTE_get_vps_vote_thl(data)                             ((0x00FF0000&(data))>>16)
#define  TT_VBI_WSS_VPS_VOTE_get_wss_vote_thl(data)                             ((0x0000FF00&(data))>>8)
#define  TT_VBI_WSS_VPS_VOTE_get_vps_start_code_ignor_num(data)                 ((0x000000F0&(data))>>4)
#define  TT_VBI_WSS_VPS_VOTE_get_wss_start_code_ignor_num(data)                 (0x0000000F&(data))

#define  TT_VBI_WSS_VPS_VOTE2                                                   0x18030AC4
#define  TT_VBI_WSS_VPS_VOTE2_reg_addr                                          "0xB8030AC4"
#define  TT_VBI_WSS_VPS_VOTE2_reg                                               0xB8030AC4
#define  TT_VBI_WSS_VPS_VOTE2_inst_addr                                         "0x0043"
#define  TT_VBI_WSS_VPS_VOTE2_inst                                              0x0043
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_en_shift                            (31)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_filter_shift                        (30)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_sub_shift                  (20)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_add_shift                  (8)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dgain_shift                         (0)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_en_mask                             (0x80000000)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_filter_mask                         (0x40000000)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_sub_mask                   (0x1FF00000)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_add_mask                   (0x0001FF00)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dgain_mask                          (0x000000FF)
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_en(data)                            (0x80000000&((data)<<31))
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_filter(data)                        (0x40000000&((data)<<30))
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_sub(data)                  (0x1FF00000&((data)<<20))
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dc_level_add(data)                  (0x0001FF00&((data)<<8))
#define  TT_VBI_WSS_VPS_VOTE2_wss_vbi_clamp_dgain(data)                         (0x000000FF&(data))
#define  TT_VBI_WSS_VPS_VOTE2_get_wss_vbi_clamp_en(data)                        ((0x80000000&(data))>>31)
#define  TT_VBI_WSS_VPS_VOTE2_get_wss_vbi_clamp_filter(data)                    ((0x40000000&(data))>>30)
#define  TT_VBI_WSS_VPS_VOTE2_get_wss_vbi_clamp_dc_level_sub(data)              ((0x1FF00000&(data))>>20)
#define  TT_VBI_WSS_VPS_VOTE2_get_wss_vbi_clamp_dc_level_add(data)              ((0x0001FF00&(data))>>8)
#define  TT_VBI_WSS_VPS_VOTE2_get_wss_vbi_clamp_dgain(data)                     (0x000000FF&(data))

#define  TT_VBI_PAGE6                                                           0x18030AC8
#define  TT_VBI_PAGE6_reg_addr                                                  "0xB8030AC8"
#define  TT_VBI_PAGE6_reg                                                       0xB8030AC8
#define  TT_VBI_PAGE6_inst_addr                                                 "0x0044"
#define  TT_VBI_PAGE6_inst                                                      0x0044
#define  TT_VBI_PAGE6_page6_en_shift                                            (31)
#define  TT_VBI_PAGE6_page6_lpfil_gain_shift                                    (16)
#define  TT_VBI_PAGE6_page6_notrig_disable1_shift                               (13)
#define  TT_VBI_PAGE6_page6_notrig_disable2_shift                               (12)
#define  TT_VBI_PAGE6_page6_sel_priority_shift                                  (8)
#define  TT_VBI_PAGE6_page6_en_count_shift                                      (0)
#define  TT_VBI_PAGE6_page6_en_mask                                             (0x80000000)
#define  TT_VBI_PAGE6_page6_lpfil_gain_mask                                     (0x000F0000)
#define  TT_VBI_PAGE6_page6_notrig_disable1_mask                                (0x00002000)
#define  TT_VBI_PAGE6_page6_notrig_disable2_mask                                (0x00001000)
#define  TT_VBI_PAGE6_page6_sel_priority_mask                                   (0x00000100)
#define  TT_VBI_PAGE6_page6_en_count_mask                                       (0x0000003F)
#define  TT_VBI_PAGE6_page6_en(data)                                            (0x80000000&((data)<<31))
#define  TT_VBI_PAGE6_page6_lpfil_gain(data)                                    (0x000F0000&((data)<<16))
#define  TT_VBI_PAGE6_page6_notrig_disable1(data)                               (0x00002000&((data)<<13))
#define  TT_VBI_PAGE6_page6_notrig_disable2(data)                               (0x00001000&((data)<<12))
#define  TT_VBI_PAGE6_page6_sel_priority(data)                                  (0x00000100&((data)<<8))
#define  TT_VBI_PAGE6_page6_en_count(data)                                      (0x0000003F&(data))
#define  TT_VBI_PAGE6_get_page6_en(data)                                        ((0x80000000&(data))>>31)
#define  TT_VBI_PAGE6_get_page6_lpfil_gain(data)                                ((0x000F0000&(data))>>16)
#define  TT_VBI_PAGE6_get_page6_notrig_disable1(data)                           ((0x00002000&(data))>>13)
#define  TT_VBI_PAGE6_get_page6_notrig_disable2(data)                           ((0x00001000&(data))>>12)
#define  TT_VBI_PAGE6_get_page6_sel_priority(data)                              ((0x00000100&(data))>>8)
#define  TT_VBI_PAGE6_get_page6_en_count(data)                                  (0x0000003F&(data))

#define  VBI_DEBUG_MODE                                                         0x18030BC0
#define  VBI_DEBUG_MODE_reg_addr                                                "0xB8030BC0"
#define  VBI_DEBUG_MODE_reg                                                     0xB8030BC0
#define  VBI_DEBUG_MODE_inst_addr                                               "0x0045"
#define  VBI_DEBUG_MODE_inst                                                    0x0045
#define  VBI_DEBUG_MODE_vbi_debug_mode_en_shift                                 (31)
#define  VBI_DEBUG_MODE_vbi_data_err_shift                                      (12)
#define  VBI_DEBUG_MODE_pat_gen_en_shift                                        (8)
#define  VBI_DEBUG_MODE_vbi_debug_mode_shift                                    (0)
#define  VBI_DEBUG_MODE_vbi_debug_mode_en_mask                                  (0x80000000)
#define  VBI_DEBUG_MODE_vbi_data_err_mask                                       (0x00001000)
#define  VBI_DEBUG_MODE_pat_gen_en_mask                                         (0x00000100)
#define  VBI_DEBUG_MODE_vbi_debug_mode_mask                                     (0x000000FF)
#define  VBI_DEBUG_MODE_vbi_debug_mode_en(data)                                 (0x80000000&((data)<<31))
#define  VBI_DEBUG_MODE_vbi_data_err(data)                                      (0x00001000&((data)<<12))
#define  VBI_DEBUG_MODE_pat_gen_en(data)                                        (0x00000100&((data)<<8))
#define  VBI_DEBUG_MODE_vbi_debug_mode(data)                                    (0x000000FF&(data))
#define  VBI_DEBUG_MODE_get_vbi_debug_mode_en(data)                             ((0x80000000&(data))>>31)
#define  VBI_DEBUG_MODE_get_vbi_data_err(data)                                  ((0x00001000&(data))>>12)
#define  VBI_DEBUG_MODE_get_pat_gen_en(data)                                    ((0x00000100&(data))>>8)
#define  VBI_DEBUG_MODE_get_vbi_debug_mode(data)                                (0x000000FF&(data))

#define  VBI_FPGA_TEST1                                                         0x18030BC4
#define  VBI_FPGA_TEST1_reg_addr                                                "0xB8030BC4"
#define  VBI_FPGA_TEST1_reg                                                     0xB8030BC4
#define  VBI_FPGA_TEST1_inst_addr                                               "0x0046"
#define  VBI_FPGA_TEST1_inst                                                    0x0046
#define  VBI_FPGA_TEST1_vbi_fpga_test1_shift                                    (0)
#define  VBI_FPGA_TEST1_vbi_fpga_test1_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST1_vbi_fpga_test1(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST1_get_vbi_fpga_test1(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST2                                                         0x18030BC8
#define  VBI_FPGA_TEST2_reg_addr                                                "0xB8030BC8"
#define  VBI_FPGA_TEST2_reg                                                     0xB8030BC8
#define  VBI_FPGA_TEST2_inst_addr                                               "0x0047"
#define  VBI_FPGA_TEST2_inst                                                    0x0047
#define  VBI_FPGA_TEST2_vbi_fpga_test2_shift                                    (0)
#define  VBI_FPGA_TEST2_vbi_fpga_test2_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST2_vbi_fpga_test2(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST2_get_vbi_fpga_test2(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST3                                                         0x18030BCC
#define  VBI_FPGA_TEST3_reg_addr                                                "0xB8030BCC"
#define  VBI_FPGA_TEST3_reg                                                     0xB8030BCC
#define  VBI_FPGA_TEST3_inst_addr                                               "0x0048"
#define  VBI_FPGA_TEST3_inst                                                    0x0048
#define  VBI_FPGA_TEST3_vbi_fpga_test3_shift                                    (0)
#define  VBI_FPGA_TEST3_vbi_fpga_test3_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST3_vbi_fpga_test3(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST3_get_vbi_fpga_test3(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST4                                                         0x18030BD0
#define  VBI_FPGA_TEST4_reg_addr                                                "0xB8030BD0"
#define  VBI_FPGA_TEST4_reg                                                     0xB8030BD0
#define  VBI_FPGA_TEST4_inst_addr                                               "0x0049"
#define  VBI_FPGA_TEST4_inst                                                    0x0049
#define  VBI_FPGA_TEST4_vbi_fpga_test4_shift                                    (0)
#define  VBI_FPGA_TEST4_vbi_fpga_test4_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST4_vbi_fpga_test4(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST4_get_vbi_fpga_test4(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST5                                                         0x18030BD4
#define  VBI_FPGA_TEST5_reg_addr                                                "0xB8030BD4"
#define  VBI_FPGA_TEST5_reg                                                     0xB8030BD4
#define  VBI_FPGA_TEST5_inst_addr                                               "0x004A"
#define  VBI_FPGA_TEST5_inst                                                    0x004A
#define  VBI_FPGA_TEST5_vbi_fpga_test5_shift                                    (0)
#define  VBI_FPGA_TEST5_vbi_fpga_test5_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST5_vbi_fpga_test5(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST5_get_vbi_fpga_test5(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST6                                                         0x18030BD8
#define  VBI_FPGA_TEST6_reg_addr                                                "0xB8030BD8"
#define  VBI_FPGA_TEST6_reg                                                     0xB8030BD8
#define  VBI_FPGA_TEST6_inst_addr                                               "0x004B"
#define  VBI_FPGA_TEST6_inst                                                    0x004B
#define  VBI_FPGA_TEST6_vbi_fpga_test6_shift                                    (0)
#define  VBI_FPGA_TEST6_vbi_fpga_test6_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST6_vbi_fpga_test6(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST6_get_vbi_fpga_test6(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST7                                                         0x18030BDC
#define  VBI_FPGA_TEST7_reg_addr                                                "0xB8030BDC"
#define  VBI_FPGA_TEST7_reg                                                     0xB8030BDC
#define  VBI_FPGA_TEST7_inst_addr                                               "0x004C"
#define  VBI_FPGA_TEST7_inst                                                    0x004C
#define  VBI_FPGA_TEST7_vbi_fpga_test7_shift                                    (0)
#define  VBI_FPGA_TEST7_vbi_fpga_test7_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST7_vbi_fpga_test7(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST7_get_vbi_fpga_test7(data)                                (0xFFFFFFFF&(data))

#define  VBI_FPGA_TEST8                                                         0x18030BE0
#define  VBI_FPGA_TEST8_reg_addr                                                "0xB8030BE0"
#define  VBI_FPGA_TEST8_reg                                                     0xB8030BE0
#define  VBI_FPGA_TEST8_inst_addr                                               "0x004D"
#define  VBI_FPGA_TEST8_inst                                                    0x004D
#define  VBI_FPGA_TEST8_vbi_fpga_test8_shift                                    (0)
#define  VBI_FPGA_TEST8_vbi_fpga_test8_mask                                     (0xFFFFFFFF)
#define  VBI_FPGA_TEST8_vbi_fpga_test8(data)                                    (0xFFFFFFFF&(data))
#define  VBI_FPGA_TEST8_get_vbi_fpga_test8(data)                                (0xFFFFFFFF&(data))

#define  VBI_DMA_FRAME_ADDR                                                     0x18030C00
#define  VBI_DMA_FRAME_ADDR_reg_addr                                            "0xB8030C00"
#define  VBI_DMA_FRAME_ADDR_reg                                                 0xB8030C00
#define  VBI_DMA_FRAME_ADDR_inst_addr                                           "0x004E"
#define  VBI_DMA_FRAME_ADDR_inst                                                0x004E
#define  VBI_DMA_FRAME_ADDR_vbi_dma_frame_addr_shift                            (0)
#define  VBI_DMA_FRAME_ADDR_vbi_dma_frame_addr_mask                             (0x1FFFFFFF)
#define  VBI_DMA_FRAME_ADDR_vbi_dma_frame_addr(data)                            (0x1FFFFFFF&(data))
#define  VBI_DMA_FRAME_ADDR_get_vbi_dma_frame_addr(data)                        (0x1FFFFFFF&(data))

#define  VBI_DMA_FRAME_ADDR_END                                                 0x18030C04
#define  VBI_DMA_FRAME_ADDR_END_reg_addr                                        "0xB8030C04"
#define  VBI_DMA_FRAME_ADDR_END_reg                                             0xB8030C04
#define  VBI_DMA_FRAME_ADDR_END_inst_addr                                       "0x004F"
#define  VBI_DMA_FRAME_ADDR_END_inst                                            0x004F
#define  VBI_DMA_FRAME_ADDR_END_vbi_dma_frame_addr_end_shift                    (0)
#define  VBI_DMA_FRAME_ADDR_END_vbi_dma_frame_addr_end_mask                     (0x1FFFFFFF)
#define  VBI_DMA_FRAME_ADDR_END_vbi_dma_frame_addr_end(data)                    (0x1FFFFFFF&(data))
#define  VBI_DMA_FRAME_ADDR_END_get_vbi_dma_frame_addr_end(data)                (0x1FFFFFFF&(data))

#define  VBI_DMA_FIFO_STAUS                                                     0x18030C08
#define  VBI_DMA_FIFO_STAUS_reg_addr                                            "0xB8030C08"
#define  VBI_DMA_FIFO_STAUS_reg                                                 0xB8030C08
#define  VBI_DMA_FIFO_STAUS_inst_addr                                           "0x0050"
#define  VBI_DMA_FIFO_STAUS_inst                                                0x0050
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ofifo_thr_shift                        (16)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ceiladr_shift                          (8)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_bstlen_shift                           (0)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ofifo_thr_mask                         (0x003F0000)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ceiladr_mask                           (0x00003F00)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_bstlen_mask                            (0x00000007)
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ofifo_thr(data)                        (0x003F0000&((data)<<16))
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_ceiladr(data)                          (0x00003F00&((data)<<8))
#define  VBI_DMA_FIFO_STAUS_vbi_dma_ctrl_bstlen(data)                           (0x00000007&(data))
#define  VBI_DMA_FIFO_STAUS_get_vbi_dma_ctrl_ofifo_thr(data)                    ((0x003F0000&(data))>>16)
#define  VBI_DMA_FIFO_STAUS_get_vbi_dma_ctrl_ceiladr(data)                      ((0x00003F00&(data))>>8)
#define  VBI_DMA_FIFO_STAUS_get_vbi_dma_ctrl_bstlen(data)                       (0x00000007&(data))

#define  VBI_DMA_CTRL                                                           0x18030C0C
#define  VBI_DMA_CTRL_reg_addr                                                  "0xB8030C0C"
#define  VBI_DMA_CTRL_reg                                                       0xB8030C0C
#define  VBI_DMA_CTRL_inst_addr                                                 "0x0051"
#define  VBI_DMA_CTRL_inst                                                      0x0051
#define  VBI_DMA_CTRL_vbi_dma_ctrl_ofifo_err_flag_shift                         (3)
#define  VBI_DMA_CTRL_vbi_dma_mem_off_shift                                     (2)
#define  VBI_DMA_CTRL_vbi_dma_test_mode_shift                                   (1)
#define  VBI_DMA_CTRL_vbi_dma_ctrl_ofifo_err_flag_mask                          (0x00000008)
#define  VBI_DMA_CTRL_vbi_dma_mem_off_mask                                      (0x00000004)
#define  VBI_DMA_CTRL_vbi_dma_test_mode_mask                                    (0x00000002)
#define  VBI_DMA_CTRL_vbi_dma_ctrl_ofifo_err_flag(data)                         (0x00000008&((data)<<3))
#define  VBI_DMA_CTRL_vbi_dma_mem_off(data)                                     (0x00000004&((data)<<2))
#define  VBI_DMA_CTRL_vbi_dma_test_mode(data)                                   (0x00000002&((data)<<1))
#define  VBI_DMA_CTRL_get_vbi_dma_ctrl_ofifo_err_flag(data)                     ((0x00000008&(data))>>3)
#define  VBI_DMA_CTRL_get_vbi_dma_mem_off(data)                                 ((0x00000004&(data))>>2)
#define  VBI_DMA_CTRL_get_vbi_dma_test_mode(data)                               ((0x00000002&(data))>>1)

#define  VBI_DMA_VACTIVE1                                                       0x18030C10
#define  VBI_DMA_VACTIVE1_reg_addr                                              "0xB8030C10"
#define  VBI_DMA_VACTIVE1_reg                                                   0xB8030C10
#define  VBI_DMA_VACTIVE1_inst_addr                                             "0x0052"
#define  VBI_DMA_VACTIVE1_inst                                                  0x0052
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_st1_shift                             (16)
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_end1_shift                            (0)
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_st1_mask                              (0x03FF0000)
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_end1_mask                             (0x000003FF)
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_st1(data)                             (0x03FF0000&((data)<<16))
#define  VBI_DMA_VACTIVE1_vbi_dma_vactive_end1(data)                            (0x000003FF&(data))
#define  VBI_DMA_VACTIVE1_get_vbi_dma_vactive_st1(data)                         ((0x03FF0000&(data))>>16)
#define  VBI_DMA_VACTIVE1_get_vbi_dma_vactive_end1(data)                        (0x000003FF&(data))

#define  VBI_DMA_VACTIVE2                                                       0x18030C14
#define  VBI_DMA_VACTIVE2_reg_addr                                              "0xB8030C14"
#define  VBI_DMA_VACTIVE2_reg                                                   0xB8030C14
#define  VBI_DMA_VACTIVE2_inst_addr                                             "0x0053"
#define  VBI_DMA_VACTIVE2_inst                                                  0x0053
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_st2_shift                             (16)
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_end2_shift                            (0)
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_st2_mask                              (0x03FF0000)
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_end2_mask                             (0x000003FF)
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_st2(data)                             (0x03FF0000&((data)<<16))
#define  VBI_DMA_VACTIVE2_vbi_dma_vactive_end2(data)                            (0x000003FF&(data))
#define  VBI_DMA_VACTIVE2_get_vbi_dma_vactive_st2(data)                         ((0x03FF0000&(data))>>16)
#define  VBI_DMA_VACTIVE2_get_vbi_dma_vactive_end2(data)                        (0x000003FF&(data))

#define  VBI_DUMP_int                                                           0x18030C18
#define  VBI_DUMP_int_reg_addr                                                  "0xB8030C18"
#define  VBI_DUMP_int_reg                                                       0xB8030C18
#define  VBI_DUMP_int_inst_addr                                                 "0x0054"
#define  VBI_DUMP_int_inst                                                      0x0054
#define  VBI_DUMP_int_vbi_dump_overflow_shift                                   (2)
#define  VBI_DUMP_int_vbi_dump_irq_en_shift                                     (1)
#define  VBI_DUMP_int_vbi_dump_irq_shift                                        (0)
#define  VBI_DUMP_int_vbi_dump_overflow_mask                                    (0x00000004)
#define  VBI_DUMP_int_vbi_dump_irq_en_mask                                      (0x00000002)
#define  VBI_DUMP_int_vbi_dump_irq_mask                                         (0x00000001)
#define  VBI_DUMP_int_vbi_dump_overflow(data)                                   (0x00000004&((data)<<2))
#define  VBI_DUMP_int_vbi_dump_irq_en(data)                                     (0x00000002&((data)<<1))
#define  VBI_DUMP_int_vbi_dump_irq(data)                                        (0x00000001&(data))
#define  VBI_DUMP_int_get_vbi_dump_overflow(data)                               ((0x00000004&(data))>>2)
#define  VBI_DUMP_int_get_vbi_dump_irq_en(data)                                 ((0x00000002&(data))>>1)
#define  VBI_DUMP_int_get_vbi_dump_irq(data)                                    (0x00000001&(data))

#define  BIST_TEST1                                                             0x18030C1C
#define  BIST_TEST1_reg_addr                                                    "0xB8030C1C"
#define  BIST_TEST1_reg                                                         0xB8030C1C
#define  BIST_TEST1_inst_addr                                                   "0x0055"
#define  BIST_TEST1_inst                                                        0x0055
#define  BIST_TEST1_sram_on_off_shift                                           (0)
#define  BIST_TEST1_sram_on_off_mask                                            (0x00000001)
#define  BIST_TEST1_sram_on_off(data)                                           (0x00000001&(data))
#define  BIST_TEST1_get_sram_on_off(data)                                       (0x00000001&(data))

#define  BIST_MODE                                                              0x18030C20
#define  BIST_MODE_reg_addr                                                     "0xB8030C20"
#define  BIST_MODE_reg                                                          0xB8030C20
#define  BIST_MODE_inst_addr                                                    "0x0056"
#define  BIST_MODE_inst                                                         0x0056
#define  BIST_MODE_bist_mode_shift                                              (0)
#define  BIST_MODE_bist_mode_mask                                               (0x00000001)
#define  BIST_MODE_bist_mode(data)                                              (0x00000001&(data))
#define  BIST_MODE_get_bist_mode(data)                                          (0x00000001&(data))

#define  BIST_DONE                                                              0x18030C24
#define  BIST_DONE_reg_addr                                                     "0xB8030C24"
#define  BIST_DONE_reg                                                          0xB8030C24
#define  BIST_DONE_inst_addr                                                    "0x0057"
#define  BIST_DONE_inst                                                         0x0057
#define  BIST_DONE_bist_done_shift                                              (0)
#define  BIST_DONE_bist_done_mask                                               (0x00000001)
#define  BIST_DONE_bist_done(data)                                              (0x00000001&(data))
#define  BIST_DONE_get_bist_done(data)                                          (0x00000001&(data))

#define  BIST_FAIL                                                              0x18030C28
#define  BIST_FAIL_reg_addr                                                     "0xB8030C28"
#define  BIST_FAIL_reg                                                          0xB8030C28
#define  BIST_FAIL_inst_addr                                                    "0x0058"
#define  BIST_FAIL_inst                                                         0x0058
#define  BIST_FAIL_bist_fail_shift                                              (0)
#define  BIST_FAIL_bist_fail_mask                                               (0x00000001)
#define  BIST_FAIL_bist_fail(data)                                              (0x00000001&(data))
#define  BIST_FAIL_get_bist_fail(data)                                          (0x00000001&(data))

#define  BIST_DRF_MODE                                                          0x18030C2C
#define  BIST_DRF_MODE_reg_addr                                                 "0xB8030C2C"
#define  BIST_DRF_MODE_reg                                                      0xB8030C2C
#define  BIST_DRF_MODE_inst_addr                                                "0x0059"
#define  BIST_DRF_MODE_inst                                                     0x0059
#define  BIST_DRF_MODE_bist_mode_drf_shift                                      (0)
#define  BIST_DRF_MODE_bist_mode_drf_mask                                       (0x00000001)
#define  BIST_DRF_MODE_bist_mode_drf(data)                                      (0x00000001&(data))
#define  BIST_DRF_MODE_get_bist_mode_drf(data)                                  (0x00000001&(data))

#define  BIST_DRF_RESUME                                                        0x18030C30
#define  BIST_DRF_RESUME_reg_addr                                               "0xB8030C30"
#define  BIST_DRF_RESUME_reg                                                    0xB8030C30
#define  BIST_DRF_RESUME_inst_addr                                              "0x005A"
#define  BIST_DRF_RESUME_inst                                                   0x005A
#define  BIST_DRF_RESUME_bist_drf_test_resume_shift                             (0)
#define  BIST_DRF_RESUME_bist_drf_test_resume_mask                              (0x00000001)
#define  BIST_DRF_RESUME_bist_drf_test_resume(data)                             (0x00000001&(data))
#define  BIST_DRF_RESUME_get_bist_drf_test_resume(data)                         (0x00000001&(data))

#define  BIST_DONE_DRF                                                          0x18030C34
#define  BIST_DONE_DRF_reg_addr                                                 "0xB8030C34"
#define  BIST_DONE_DRF_reg                                                      0xB8030C34
#define  BIST_DONE_DRF_inst_addr                                                "0x005B"
#define  BIST_DONE_DRF_inst                                                     0x005B
#define  BIST_DONE_DRF_bist_done_drf_shift                                      (0)
#define  BIST_DONE_DRF_bist_done_drf_mask                                       (0x00000001)
#define  BIST_DONE_DRF_bist_done_drf(data)                                      (0x00000001&(data))
#define  BIST_DONE_DRF_get_bist_done_drf(data)                                  (0x00000001&(data))

#define  BIST_DRF_PAUSE                                                         0x18030C38
#define  BIST_DRF_PAUSE_reg_addr                                                "0xB8030C38"
#define  BIST_DRF_PAUSE_reg                                                     0xB8030C38
#define  BIST_DRF_PAUSE_inst_addr                                               "0x005C"
#define  BIST_DRF_PAUSE_inst                                                    0x005C
#define  BIST_DRF_PAUSE_bist_drf_start_pause_shift                              (0)
#define  BIST_DRF_PAUSE_bist_drf_start_pause_mask                               (0x00000001)
#define  BIST_DRF_PAUSE_bist_drf_start_pause(data)                              (0x00000001&(data))
#define  BIST_DRF_PAUSE_get_bist_drf_start_pause(data)                          (0x00000001&(data))

#define  BIST_FAIL_DRF                                                          0x18030C3C
#define  BIST_FAIL_DRF_reg_addr                                                 "0xB8030C3C"
#define  BIST_FAIL_DRF_reg                                                      0xB8030C3C
#define  BIST_FAIL_DRF_inst_addr                                                "0x005D"
#define  BIST_FAIL_DRF_inst                                                     0x005D
#define  BIST_FAIL_DRF_bist_fail_drf_shift                                      (0)
#define  BIST_FAIL_DRF_bist_fail_drf_mask                                       (0x00000001)
#define  BIST_FAIL_DRF_bist_fail_drf(data)                                      (0x00000001&(data))
#define  BIST_FAIL_DRF_get_bist_fail_drf(data)                                  (0x00000001&(data))

#define  BIST_DVSE                                                              0x18030C40
#define  BIST_DVSE_reg_addr                                                     "0xB8030C40"
#define  BIST_DVSE_reg                                                          0xB8030C40
#define  BIST_DVSE_inst_addr                                                    "0x005E"
#define  BIST_DVSE_inst                                                         0x005E
#define  BIST_DVSE_bist_ls_shift                                                (13)
#define  BIST_DVSE_bist_rmeb_shift                                              (12)
#define  BIST_DVSE_bist_rmb_shift                                               (8)
#define  BIST_DVSE_bist_rmea_shift                                              (4)
#define  BIST_DVSE_bist_rma_shift                                               (0)
#define  BIST_DVSE_bist_ls_mask                                                 (0x00002000)
#define  BIST_DVSE_bist_rmeb_mask                                               (0x00001000)
#define  BIST_DVSE_bist_rmb_mask                                                (0x00000F00)
#define  BIST_DVSE_bist_rmea_mask                                               (0x00000010)
#define  BIST_DVSE_bist_rma_mask                                                (0x0000000F)
#define  BIST_DVSE_bist_ls(data)                                                (0x00002000&((data)<<13))
#define  BIST_DVSE_bist_rmeb(data)                                              (0x00001000&((data)<<12))
#define  BIST_DVSE_bist_rmb(data)                                               (0x00000F00&((data)<<8))
#define  BIST_DVSE_bist_rmea(data)                                              (0x00000010&((data)<<4))
#define  BIST_DVSE_bist_rma(data)                                               (0x0000000F&(data))
#define  BIST_DVSE_get_bist_ls(data)                                            ((0x00002000&(data))>>13)
#define  BIST_DVSE_get_bist_rmeb(data)                                          ((0x00001000&(data))>>12)
#define  BIST_DVSE_get_bist_rmb(data)                                           ((0x00000F00&(data))>>8)
#define  BIST_DVSE_get_bist_rmea(data)                                          ((0x00000010&(data))>>4)
#define  BIST_DVSE_get_bist_rma(data)                                           (0x0000000F&(data))

#define  VBI_PPR_LVLD1                                                          0x18030C50
#define  VBI_PPR_LVLD1_reg_addr                                                 "0xB8030C50"
#define  VBI_PPR_LVLD1_reg                                                      0xB8030C50
#define  VBI_PPR_LVLD1_inst_addr                                                "0x005F"
#define  VBI_PPR_LVLD1_inst                                                     0x005F
#define  VBI_PPR_LVLD1_vbippr_lvld_tendl_shift                                  (16)
#define  VBI_PPR_LVLD1_vbippr_lvld_tstl_shift                                   (0)
#define  VBI_PPR_LVLD1_vbippr_lvld_tendl_mask                                   (0x07FF0000)
#define  VBI_PPR_LVLD1_vbippr_lvld_tstl_mask                                    (0x000007FF)
#define  VBI_PPR_LVLD1_vbippr_lvld_tendl(data)                                  (0x07FF0000&((data)<<16))
#define  VBI_PPR_LVLD1_vbippr_lvld_tstl(data)                                   (0x000007FF&(data))
#define  VBI_PPR_LVLD1_get_vbippr_lvld_tendl(data)                              ((0x07FF0000&(data))>>16)
#define  VBI_PPR_LVLD1_get_vbippr_lvld_tstl(data)                               (0x000007FF&(data))

#define  VBI_PPR_LVLD2                                                          0x18030C54
#define  VBI_PPR_LVLD2_reg_addr                                                 "0xB8030C54"
#define  VBI_PPR_LVLD2_reg                                                      0xB8030C54
#define  VBI_PPR_LVLD2_inst_addr                                                "0x0060"
#define  VBI_PPR_LVLD2_inst                                                     0x0060
#define  VBI_PPR_LVLD2_vbippr_lvld_bendl_shift                                  (16)
#define  VBI_PPR_LVLD2_vbippr_lvld_bstl_shift                                   (0)
#define  VBI_PPR_LVLD2_vbippr_lvld_bendl_mask                                   (0x07FF0000)
#define  VBI_PPR_LVLD2_vbippr_lvld_bstl_mask                                    (0x000007FF)
#define  VBI_PPR_LVLD2_vbippr_lvld_bendl(data)                                  (0x07FF0000&((data)<<16))
#define  VBI_PPR_LVLD2_vbippr_lvld_bstl(data)                                   (0x000007FF&(data))
#define  VBI_PPR_LVLD2_get_vbippr_lvld_bendl(data)                              ((0x07FF0000&(data))>>16)
#define  VBI_PPR_LVLD2_get_vbippr_lvld_bstl(data)                               (0x000007FF&(data))

#define  VBIPPR_CTRL_REG                                                        0x18030C58
#define  VBIPPR_CTRL_REG_reg_addr                                               "0xB8030C58"
#define  VBIPPR_CTRL_REG_reg                                                    0xB8030C58
#define  VBIPPR_CTRL_REG_inst_addr                                              "0x0061"
#define  VBIPPR_CTRL_REG_inst                                                   0x0061
#define  VBIPPR_CTRL_REG_vbippr_data_acqu_en_shift                              (0)
#define  VBIPPR_CTRL_REG_vbippr_data_acqu_en_mask                               (0x00000001)
#define  VBIPPR_CTRL_REG_vbippr_data_acqu_en(data)                              (0x00000001&(data))
#define  VBIPPR_CTRL_REG_get_vbippr_data_acqu_en(data)                          (0x00000001&(data))

#define  VBIPPR_PKT_RX_CNT_REG                                                  0x18030C5C
#define  VBIPPR_PKT_RX_CNT_REG_reg_addr                                         "0xB8030C5C"
#define  VBIPPR_PKT_RX_CNT_REG_reg                                              0xB8030C5C
#define  VBIPPR_PKT_RX_CNT_REG_inst_addr                                        "0x0062"
#define  VBIPPR_PKT_RX_CNT_REG_inst                                             0x0062
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_rst_shift                          (31)
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_cnt_shift                          (0)
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_rst_mask                           (0x80000000)
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_cnt_mask                           (0x0000FFFF)
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_rst(data)                          (0x80000000&((data)<<31))
#define  VBIPPR_PKT_RX_CNT_REG_vbippr_pkt_rx_cnt(data)                          (0x0000FFFF&(data))
#define  VBIPPR_PKT_RX_CNT_REG_get_vbippr_pkt_rx_rst(data)                      ((0x80000000&(data))>>31)
#define  VBIPPR_PKT_RX_CNT_REG_get_vbippr_pkt_rx_cnt(data)                      (0x0000FFFF&(data))

#define  VBIPPR_PG_MODE_REG                                                     0x18030C60
#define  VBIPPR_PG_MODE_REG_reg_addr                                            "0xB8030C60"
#define  VBIPPR_PG_MODE_REG_reg                                                 0xB8030C60
#define  VBIPPR_PG_MODE_REG_inst_addr                                           "0x0063"
#define  VBIPPR_PG_MODE_REG_inst                                                0x0063
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rd_count_shift                        (16)
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rx_count_rst_shift                    (8)
#define  VBIPPR_PG_MODE_REG_vbippr_pg_mode_shift                                (4)
#define  VBIPPR_PG_MODE_REG_vbippr_pgdebug_en_shift                             (1)
#define  VBIPPR_PG_MODE_REG_vbippr_pg_en_shift                                  (0)
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rd_count_mask                         (0xFFFF0000)
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rx_count_rst_mask                     (0x00000100)
#define  VBIPPR_PG_MODE_REG_vbippr_pg_mode_mask                                 (0x00000070)
#define  VBIPPR_PG_MODE_REG_vbippr_pgdebug_en_mask                              (0x00000002)
#define  VBIPPR_PG_MODE_REG_vbippr_pg_en_mask                                   (0x00000001)
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rd_count(data)                        (0xFFFF0000&((data)<<16))
#define  VBIPPR_PG_MODE_REG_vbi_sync_fifo_rx_count_rst(data)                    (0x00000100&((data)<<8))
#define  VBIPPR_PG_MODE_REG_vbippr_pg_mode(data)                                (0x00000070&((data)<<4))
#define  VBIPPR_PG_MODE_REG_vbippr_pgdebug_en(data)                             (0x00000002&((data)<<1))
#define  VBIPPR_PG_MODE_REG_vbippr_pg_en(data)                                  (0x00000001&(data))
#define  VBIPPR_PG_MODE_REG_get_vbi_sync_fifo_rd_count(data)                    ((0xFFFF0000&(data))>>16)
#define  VBIPPR_PG_MODE_REG_get_vbi_sync_fifo_rx_count_rst(data)                ((0x00000100&(data))>>8)
#define  VBIPPR_PG_MODE_REG_get_vbippr_pg_mode(data)                            ((0x00000070&(data))>>4)
#define  VBIPPR_PG_MODE_REG_get_vbippr_pgdebug_en(data)                         ((0x00000002&(data))>>1)
#define  VBIPPR_PG_MODE_REG_get_vbippr_pg_en(data)                              (0x00000001&(data))

#define  VBIPPR_PG_LINE_ACT_REG                                                 0x18030C64
#define  VBIPPR_PG_LINE_ACT_REG_reg_addr                                        "0xB8030C64"
#define  VBIPPR_PG_LINE_ACT_REG_reg                                             0xB8030C64
#define  VBIPPR_PG_LINE_ACT_REG_inst_addr                                       "0x0064"
#define  VBIPPR_PG_LINE_ACT_REG_inst                                            0x0064
#define  VBIPPR_PG_LINE_ACT_REG_vbippr_pg_line_act_shift                        (0)
#define  VBIPPR_PG_LINE_ACT_REG_vbippr_pg_line_act_mask                         (0x00000001)
#define  VBIPPR_PG_LINE_ACT_REG_vbippr_pg_line_act(data)                        (0x00000001&(data))
#define  VBIPPR_PG_LINE_ACT_REG_get_vbippr_pg_line_act(data)                    (0x00000001&(data))

#define  VBIPPR_PGDATA_B1B4_REG                                                 0x18030C68
#define  VBIPPR_PGDATA_B1B4_REG_reg_addr                                        "0xB8030C68"
#define  VBIPPR_PGDATA_B1B4_REG_reg                                             0xB8030C68
#define  VBIPPR_PGDATA_B1B4_REG_inst_addr                                       "0x0065"
#define  VBIPPR_PGDATA_B1B4_REG_inst                                            0x0065
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata1_shift                            (24)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata2_shift                            (16)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata3_shift                            (8)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata4_shift                            (0)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata1_mask                             (0xFF000000)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata2_mask                             (0x00FF0000)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata3_mask                             (0x0000FF00)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata4_mask                             (0x000000FF)
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata1(data)                            (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata2(data)                            (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata3(data)                            (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B1B4_REG_vbippr_pgdata4(data)                            (0x000000FF&(data))
#define  VBIPPR_PGDATA_B1B4_REG_get_vbippr_pgdata1(data)                        ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B1B4_REG_get_vbippr_pgdata2(data)                        ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B1B4_REG_get_vbippr_pgdata3(data)                        ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B1B4_REG_get_vbippr_pgdata4(data)                        (0x000000FF&(data))

#define  VBIPPR_PGDATA_B5B8_REG                                                 0x18030C6C
#define  VBIPPR_PGDATA_B5B8_REG_reg_addr                                        "0xB8030C6C"
#define  VBIPPR_PGDATA_B5B8_REG_reg                                             0xB8030C6C
#define  VBIPPR_PGDATA_B5B8_REG_inst_addr                                       "0x0066"
#define  VBIPPR_PGDATA_B5B8_REG_inst                                            0x0066
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata5_shift                            (24)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata6_shift                            (16)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata7_shift                            (8)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata8_shift                            (0)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata5_mask                             (0xFF000000)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata6_mask                             (0x00FF0000)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata7_mask                             (0x0000FF00)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata8_mask                             (0x000000FF)
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata5(data)                            (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata6(data)                            (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata7(data)                            (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B5B8_REG_vbippr_pgdata8(data)                            (0x000000FF&(data))
#define  VBIPPR_PGDATA_B5B8_REG_get_vbippr_pgdata5(data)                        ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B5B8_REG_get_vbippr_pgdata6(data)                        ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B5B8_REG_get_vbippr_pgdata7(data)                        ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B5B8_REG_get_vbippr_pgdata8(data)                        (0x000000FF&(data))

#define  VBIPPR_PGDATA_B9B12_REG                                                0x18030C70
#define  VBIPPR_PGDATA_B9B12_REG_reg_addr                                       "0xB8030C70"
#define  VBIPPR_PGDATA_B9B12_REG_reg                                            0xB8030C70
#define  VBIPPR_PGDATA_B9B12_REG_inst_addr                                      "0x0067"
#define  VBIPPR_PGDATA_B9B12_REG_inst                                           0x0067
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata9_shift                           (24)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata10_shift                          (16)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata11_shift                          (8)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata12_shift                          (0)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata9_mask                            (0xFF000000)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata10_mask                           (0x00FF0000)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata11_mask                           (0x0000FF00)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata12_mask                           (0x000000FF)
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata9(data)                           (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata10(data)                          (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata11(data)                          (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B9B12_REG_vbippr_pgdata12(data)                          (0x000000FF&(data))
#define  VBIPPR_PGDATA_B9B12_REG_get_vbippr_pgdata9(data)                       ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B9B12_REG_get_vbippr_pgdata10(data)                      ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B9B12_REG_get_vbippr_pgdata11(data)                      ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B9B12_REG_get_vbippr_pgdata12(data)                      (0x000000FF&(data))

#define  VBIPPR_PGDATA_B13B16_REG                                               0x18030C74
#define  VBIPPR_PGDATA_B13B16_REG_reg_addr                                      "0xB8030C74"
#define  VBIPPR_PGDATA_B13B16_REG_reg                                           0xB8030C74
#define  VBIPPR_PGDATA_B13B16_REG_inst_addr                                     "0x0068"
#define  VBIPPR_PGDATA_B13B16_REG_inst                                          0x0068
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata13_shift                         (24)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata14_shift                         (16)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata15_shift                         (8)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata16_shift                         (0)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata13_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata14_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata15_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata16_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata13(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata14(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata15(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B13B16_REG_vbippr_pgdata16(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B13B16_REG_get_vbippr_pgdata13(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B13B16_REG_get_vbippr_pgdata14(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B13B16_REG_get_vbippr_pgdata15(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B13B16_REG_get_vbippr_pgdata16(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B17B20_REG                                               0x18030C78
#define  VBIPPR_PGDATA_B17B20_REG_reg_addr                                      "0xB8030C78"
#define  VBIPPR_PGDATA_B17B20_REG_reg                                           0xB8030C78
#define  VBIPPR_PGDATA_B17B20_REG_inst_addr                                     "0x0069"
#define  VBIPPR_PGDATA_B17B20_REG_inst                                          0x0069
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata17_shift                         (24)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata18_shift                         (16)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata19_shift                         (8)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata20_shift                         (0)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata17_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata18_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata19_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata20_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata17(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata18(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata19(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B17B20_REG_vbippr_pgdata20(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B17B20_REG_get_vbippr_pgdata17(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B17B20_REG_get_vbippr_pgdata18(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B17B20_REG_get_vbippr_pgdata19(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B17B20_REG_get_vbippr_pgdata20(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B21B24_REG                                               0x18030C7C
#define  VBIPPR_PGDATA_B21B24_REG_reg_addr                                      "0xB8030C7C"
#define  VBIPPR_PGDATA_B21B24_REG_reg                                           0xB8030C7C
#define  VBIPPR_PGDATA_B21B24_REG_inst_addr                                     "0x006A"
#define  VBIPPR_PGDATA_B21B24_REG_inst                                          0x006A
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata21_shift                         (24)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata22_shift                         (16)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata23_shift                         (8)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata24_shift                         (0)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata21_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata22_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata23_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata24_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata21(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata22(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata23(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B21B24_REG_vbippr_pgdata24(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B21B24_REG_get_vbippr_pgdata21(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B21B24_REG_get_vbippr_pgdata22(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B21B24_REG_get_vbippr_pgdata23(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B21B24_REG_get_vbippr_pgdata24(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B25B28_REG                                               0x18030C80
#define  VBIPPR_PGDATA_B25B28_REG_reg_addr                                      "0xB8030C80"
#define  VBIPPR_PGDATA_B25B28_REG_reg                                           0xB8030C80
#define  VBIPPR_PGDATA_B25B28_REG_inst_addr                                     "0x006B"
#define  VBIPPR_PGDATA_B25B28_REG_inst                                          0x006B
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata25_shift                         (24)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata26_shift                         (16)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata27_shift                         (8)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata28_shift                         (0)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata25_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata26_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata27_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata28_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata25(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata26(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata27(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B25B28_REG_vbippr_pgdata28(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B25B28_REG_get_vbippr_pgdata25(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B25B28_REG_get_vbippr_pgdata26(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B25B28_REG_get_vbippr_pgdata27(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B25B28_REG_get_vbippr_pgdata28(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B29B32_REG                                               0x18030C84
#define  VBIPPR_PGDATA_B29B32_REG_reg_addr                                      "0xB8030C84"
#define  VBIPPR_PGDATA_B29B32_REG_reg                                           0xB8030C84
#define  VBIPPR_PGDATA_B29B32_REG_inst_addr                                     "0x006C"
#define  VBIPPR_PGDATA_B29B32_REG_inst                                          0x006C
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata29_shift                         (24)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata30_shift                         (16)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata31_shift                         (8)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata32_shift                         (0)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata29_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata30_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata31_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata32_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata29(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata30(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata31(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B29B32_REG_vbippr_pgdata32(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B29B32_REG_get_vbippr_pgdata29(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B29B32_REG_get_vbippr_pgdata30(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B29B32_REG_get_vbippr_pgdata31(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B29B32_REG_get_vbippr_pgdata32(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B33B36_REG                                               0x18030C88
#define  VBIPPR_PGDATA_B33B36_REG_reg_addr                                      "0xB8030C88"
#define  VBIPPR_PGDATA_B33B36_REG_reg                                           0xB8030C88
#define  VBIPPR_PGDATA_B33B36_REG_inst_addr                                     "0x006D"
#define  VBIPPR_PGDATA_B33B36_REG_inst                                          0x006D
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata33_shift                         (24)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata34_shift                         (16)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata35_shift                         (8)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata36_shift                         (0)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata33_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata34_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata35_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata36_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata33(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata34(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata35(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B33B36_REG_vbippr_pgdata36(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B33B36_REG_get_vbippr_pgdata33(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B33B36_REG_get_vbippr_pgdata34(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B33B36_REG_get_vbippr_pgdata35(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B33B36_REG_get_vbippr_pgdata36(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B37B40_REG                                               0x18030C8C
#define  VBIPPR_PGDATA_B37B40_REG_reg_addr                                      "0xB8030C8C"
#define  VBIPPR_PGDATA_B37B40_REG_reg                                           0xB8030C8C
#define  VBIPPR_PGDATA_B37B40_REG_inst_addr                                     "0x006E"
#define  VBIPPR_PGDATA_B37B40_REG_inst                                          0x006E
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata37_shift                         (24)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata38_shift                         (16)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata39_shift                         (8)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata40_shift                         (0)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata37_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata38_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata39_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata40_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata37(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata38(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata39(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B37B40_REG_vbippr_pgdata40(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B37B40_REG_get_vbippr_pgdata37(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B37B40_REG_get_vbippr_pgdata38(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B37B40_REG_get_vbippr_pgdata39(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B37B40_REG_get_vbippr_pgdata40(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B41B44_REG                                               0x18030C90
#define  VBIPPR_PGDATA_B41B44_REG_reg_addr                                      "0xB8030C90"
#define  VBIPPR_PGDATA_B41B44_REG_reg                                           0xB8030C90
#define  VBIPPR_PGDATA_B41B44_REG_inst_addr                                     "0x006F"
#define  VBIPPR_PGDATA_B41B44_REG_inst                                          0x006F
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata41_shift                         (24)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata42_shift                         (16)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata43_shift                         (8)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata44_shift                         (0)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata41_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata42_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata43_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata44_mask                          (0x000000FF)
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata41(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata42(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata43(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B41B44_REG_vbippr_pgdata44(data)                         (0x000000FF&(data))
#define  VBIPPR_PGDATA_B41B44_REG_get_vbippr_pgdata41(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B41B44_REG_get_vbippr_pgdata42(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B41B44_REG_get_vbippr_pgdata43(data)                     ((0x0000FF00&(data))>>8)
#define  VBIPPR_PGDATA_B41B44_REG_get_vbippr_pgdata44(data)                     (0x000000FF&(data))

#define  VBIPPR_PGDATA_B45B47_REG                                               0x18030C94
#define  VBIPPR_PGDATA_B45B47_REG_reg_addr                                      "0xB8030C94"
#define  VBIPPR_PGDATA_B45B47_REG_reg                                           0xB8030C94
#define  VBIPPR_PGDATA_B45B47_REG_inst_addr                                     "0x0070"
#define  VBIPPR_PGDATA_B45B47_REG_inst                                          0x0070
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata45_shift                         (24)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata46_shift                         (16)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata47_shift                         (8)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata45_mask                          (0xFF000000)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata46_mask                          (0x00FF0000)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata47_mask                          (0x0000FF00)
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata45(data)                         (0xFF000000&((data)<<24))
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata46(data)                         (0x00FF0000&((data)<<16))
#define  VBIPPR_PGDATA_B45B47_REG_vbippr_pgdata47(data)                         (0x0000FF00&((data)<<8))
#define  VBIPPR_PGDATA_B45B47_REG_get_vbippr_pgdata45(data)                     ((0xFF000000&(data))>>24)
#define  VBIPPR_PGDATA_B45B47_REG_get_vbippr_pgdata46(data)                     ((0x00FF0000&(data))>>16)
#define  VBIPPR_PGDATA_B45B47_REG_get_vbippr_pgdata47(data)                     ((0x0000FF00&(data))>>8)

#endif 
