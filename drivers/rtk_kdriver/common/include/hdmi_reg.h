// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.71
//--#ifndef _HDMI_REG_H_INCLUDED_
//--#define _HDMI_REG_H_INCLUDED_
//--
//--//#define  _HDMI_USE_STRUCT
//--#ifdef _HDMI_USE_STRUCT
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    tmm:1;
//--    unsigned int    mt:3;
//--    unsigned int    ncp:4;
//--}TMDS_msr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:19;
//--    unsigned int    tms:1;
//--    unsigned int    mrs:2;
//--    unsigned int    ms:2;
//--    unsigned int    ctc:1;
//--    unsigned int    vmr:7;
//--}TMDS_msr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    crc_done:1;
//--    unsigned int    crc_nonstable:1;
//--    unsigned int    crcts:2;
//--    unsigned int    crcc:1;
//--}TMDS_crcc;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    crcob2_3:8;
//--    unsigned int    crcob2_2:8;
//--    unsigned int    crcob2_1:8;
//--}TMDS_crco0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    crcob2_6:8;
//--    unsigned int    crcob2_5:8;
//--    unsigned int    crcob2_4:8;
//--}TMDS_crco1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    bcd:1;
//--    unsigned int    gcd:1;
//--    unsigned int    rcd:1;
//--    unsigned int    ho:1;
//--    unsigned int    yo:1;
//--    unsigned int    dummy1800d014_2_0:3;
//--}TMDS_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:18;
//--    unsigned int    trcoe_r:1;
//--    unsigned int    tgcoe_r:1;
//--    unsigned int    tbcoe_r:1;
//--    unsigned int    ocke_r:1;
//--    unsigned int    aoe:1;
//--    unsigned int    trcoe:1;
//--    unsigned int    tgcoe:1;
//--    unsigned int    tbcoe:1;
//--    unsigned int    ocke:1;
//--    unsigned int    ockie:1;
//--    unsigned int    dummy1800d018_3:1;
//--    unsigned int    dummy1800d018_2:1;
//--    unsigned int    dummy1800d018_1:1;
//--    unsigned int    dummy1800d018_0:1;
//--}TMDS_outctl;
//--
//--typedef struct
//--{
//--    unsigned int    ecc_r:1;
//--    unsigned int    erip_r:1;
//--    unsigned int    egip_r:1;
//--    unsigned int    ebip_r:1;
//--    unsigned int    dummy1800d01c_27_10:18;
//--    unsigned int    video_preamble_off_en:1;
//--    unsigned int    hs_width_sel:1;
//--    unsigned int    deo:1;
//--    unsigned int    brcw:1;
//--    unsigned int    pnsw:1;
//--    unsigned int    iccaf:1;
//--    unsigned int    ecc:1;
//--    unsigned int    erip:1;
//--    unsigned int    egip:1;
//--    unsigned int    ebip:1;
//--}TMDS_pwdctl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:31;
//--    unsigned int    hde:1;
//--}TMDS_z0cc;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:22;
//--    unsigned int    pll_div2_en:1;
//--    unsigned int    no_clk_in:1;
//--    unsigned int    clkv_meas_sel:2;
//--    unsigned int    de_inv_disable:1;
//--    unsigned int    de_err_pulse_en:1;
//--    unsigned int    clr_infoframe_dvi:1;
//--    unsigned int    auto_dvi2hdmi:1;
//--    unsigned int    dummy1800d024_1_0:2;
//--}TMDS_cps;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:22;
//--    unsigned int    debug_sel:6;
//--    unsigned int    dummy1800d028_3:1;
//--    unsigned int    cptest:1;
//--    unsigned int    hmtm:2;
//--}TMDS_udc;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:29;
//--    unsigned int    nl:3;
//--}TMDS_errc;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    tmds_bypass:1;
//--    unsigned int    dummy1800d030_6_0:7;
//--}TMDS_out_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    tmds_rout_h:8;
//--    unsigned int    tmds_rout_l:8;
//--}TMDS_rout;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    tmds_gout_h:8;
//--    unsigned int    tmds_gout_l:8;
//--}TMDS_gout;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    tmds_bout_h:8;
//--    unsigned int    tmds_bout_l:8;
//--}TMDS_bout;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:22;
//--    unsigned int    dpc_pp_valid:1;
//--    unsigned int    dpc_default_ph:1;
//--    unsigned int    dpc_pp:4;
//--    unsigned int    dpc_cd:4;
//--}TMDS_dpc0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:13;
//--    unsigned int    dpc_cd_chg_flag:1;
//--    unsigned int    dpc_cd_chg_wd_en:1;
//--    unsigned int    dpc_cd_chg_int_en:1;
//--    unsigned int    dummy1800d044_15_11:5;
//--    unsigned int    dpc_auto:1;
//--    unsigned int    dpc_pp_valid_fw:1;
//--    unsigned int    dpc_default_ph_fw:1;
//--    unsigned int    dpc_pp_fw:4;
//--    unsigned int    dpc_cd_fw:4;
//--}TMDS_dpc1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:23;
//--    unsigned int    dpc_bypass_dis:1;
//--    unsigned int    dpc_en:1;
//--    unsigned int    phase_errcnt_in:3;
//--    unsigned int    phase_clrcnt_in:3;
//--    unsigned int    phase_clr_sel:1;
//--}TMDS_dpc_set0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    set_full_noti:4;
//--    unsigned int    set_empty_noti:4;
//--}TMDS_dpc_set1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    fifo_errcnt_in:3;
//--    unsigned int    clr_phase_flag:1;
//--    unsigned int    clr_fifo_flag:1;
//--    unsigned int    dpc_phase_ok:1;
//--    unsigned int    dpc_phase_err_flag:1;
//--    unsigned int    dpc_fifo_err_flag:1;
//--}TMDS_dpc_set2;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dpc_fifo_over_flag:1;
//--    unsigned int    dpc_fifo_under_flag:1;
//--    unsigned int    dpc_fifo_over_xflag:1;
//--    unsigned int    dpc_fifo_under_xflag:1;
//--    unsigned int    reserved_1:4;
//--}TMDS_dpc_set3;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:3;
//--    unsigned int    de_sel:1;
//--    unsigned int    tran_err_thrd:4;
//--    unsigned int    neg_de_err_thrd:4;
//--    unsigned int    pos_de_err_thrd:4;
//--    unsigned int    dummy1800d058_15:1;
//--    unsigned int    neg_de_lowbd:7;
//--    unsigned int    dummy1800d058_7_6:2;
//--    unsigned int    pos_de_lowbd:6;
//--}TMDS_det_ctl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:23;
//--    unsigned int    red_tran_err_flag:1;
//--    unsigned int    grn_tran_err_flag:1;
//--    unsigned int    blu_tran_err_flag:1;
//--    unsigned int    red_pos_de_err_flag:1;
//--    unsigned int    grn_pos_de_err_flag:1;
//--    unsigned int    blu_pos_de_err_flag:1;
//--    unsigned int    red_neg_de_err_flag:1;
//--    unsigned int    grn_neg_de_err_flag:1;
//--    unsigned int    blu_neg_de_err_flag:1;
//--}TMDS_det_sts;
//--
//--typedef struct
//--{
//--    unsigned int    thd:16;
//--    unsigned int    reserved_0:4;
//--    unsigned int    irq_en:1;
//--    unsigned int    reset:1;
//--    unsigned int    period:6;
//--    unsigned int    ch_sel:2;
//--    unsigned int    mode:1;
//--    unsigned int    en:1;
//--}VIDEO_bit_err_det;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:2;
//--    unsigned int    ad_max:5;
//--    unsigned int    ad_min:5;
//--    unsigned int    no_dis_reset:1;
//--    unsigned int    bit_err_thd:1;
//--    unsigned int    bit_err:1;
//--    unsigned int    bit_err_cnt_of:1;
//--    unsigned int    bit_err_cnt:16;
//--}VIDEO_bit_err_status;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:9;
//--    unsigned int    rsel:1;
//--    unsigned int    gsel:1;
//--    unsigned int    bsel:1;
//--    unsigned int    dummy1800d068_19_17:3;
//--    unsigned int    rden_thr:5;
//--    unsigned int    dummy1800d068_11_9:3;
//--    unsigned int    udwater_thr:5;
//--    unsigned int    dummy1800d068_3_2:2;
//--    unsigned int    flush:1;
//--    unsigned int    flag_clear:1;
//--}CH_cr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:2;
//--    unsigned int    r_rwclk_det_timeout_flag:1;
//--    unsigned int    r_wrclk_det_timeout_flag:1;
//--    unsigned int    g_rwclk_det_timeout_flag:1;
//--    unsigned int    g_wrclk_det_timeout_flag:1;
//--    unsigned int    b_rwclk_det_timeout_flag:1;
//--    unsigned int    b_wrclk_det_timeout_flag:1;
//--    unsigned int    r_rudflow_flag:1;
//--    unsigned int    r_wovflow_flag:1;
//--    unsigned int    r_rflush_flag:1;
//--    unsigned int    r_rw_water_lv:5;
//--    unsigned int    g_rudflow_flag:1;
//--    unsigned int    g_wovflow_flag:1;
//--    unsigned int    g_rflush_flag:1;
//--    unsigned int    g_rw_water_lv:5;
//--    unsigned int    b_rudflow_flag:1;
//--    unsigned int    b_wovflow_flag:1;
//--    unsigned int    b_rflush_flag:1;
//--    unsigned int    b_rw_water_lv:5;
//--}CH_sr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    avmute_bg:1;
//--    unsigned int    avmute:1;
//--    unsigned int    vic:1;
//--    unsigned int    spdiftype:1;
//--    unsigned int    pllsts:1;
//--    unsigned int    afifoof:1;
//--    unsigned int    afifouf:1;
//--    unsigned int    mode:1;
//--}HDMI_sr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:18;
//--    unsigned int    gmps_v:1;
//--    unsigned int    vsps_v:1;
//--    unsigned int    gmps:1;
//--    unsigned int    vsps:1;
//--    unsigned int    nps:1;
//--    unsigned int    dummy1800d084_8:1;
//--    unsigned int    dummy1800d084_7:1;
//--    unsigned int    pis_6:1;
//--    unsigned int    pis_5:1;
//--    unsigned int    pvs_4:1;
//--    unsigned int    pvs_3:1;
//--    unsigned int    pvs_2:1;
//--    unsigned int    pvs_1:1;
//--    unsigned int    pvs_0:1;
//--}HDMI_gpvs;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    apss:8;
//--}HDMI_psap;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dpss:8;
//--}HDMI_psdp;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    nval:8;
//--    unsigned int    reserved_1:2;
//--    unsigned int    dvi_reset_ds_cm_en:1;
//--    unsigned int    packet_ignore:1;
//--    unsigned int    mode:1;
//--    unsigned int    msmode:1;
//--    unsigned int    cabs:1;
//--    unsigned int    fcddip:1;
//--}HDMI_scr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    reserved_1:2;
//--    unsigned int    spcss:1;
//--    unsigned int    enrwe:1;
//--    unsigned int    bche:1;
//--    unsigned int    bches:1;
//--    unsigned int    bches2:1;
//--    unsigned int    pe:1;
//--}HDMI_bchcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:21;
//--    unsigned int    wd_ptg_en:1;
//--    unsigned int    wd_vclk_en:1;
//--    unsigned int    avmute_flag:1;
//--    unsigned int    avmute_win_en:1;
//--    unsigned int    aoc:1;
//--    unsigned int    aomc:1;
//--    unsigned int    awd:1;
//--    unsigned int    ve:1;
//--    unsigned int    ampic:1;
//--    unsigned int    vdpic:1;
//--    unsigned int    nfpss:1;
//--}HDMI_avmcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    vwdap:1;
//--    unsigned int    vwdlf:1;
//--    unsigned int    vwdafo:1;
//--    unsigned int    vwdafu:1;
//--    unsigned int    yv:4;
//--    unsigned int    awdck:1;
//--    unsigned int    awdlf:1;
//--    unsigned int    ch_st_sel:1;
//--    unsigned int    vwdact:1;
//--    unsigned int    xv:4;
//--    unsigned int    asmfe:1;
//--    unsigned int    load_d:1;
//--    unsigned int    bt_track_en:1;
//--    unsigned int    awdct:1;
//--    unsigned int    awdap:1;
//--    unsigned int    awdfo:1;
//--    unsigned int    awdfu:1;
//--    unsigned int    ct:1;
//--}HDMI_wdcr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    aldbfv:1;
//--    unsigned int    aldbfo:1;
//--    unsigned int    aldbfu:1;
//--    unsigned int    aldbpn:1;
//--}HDMI_dbcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    awdpvsb:7;
//--}HDMI_awdsr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    vwdpvsb:7;
//--}HDMI_vwdsr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    icpvsb:7;
//--}HDMI_pamicr;
//--
//--typedef struct
//--{
//--    unsigned int    dummy1800d0b0_31_24:8;
//--    unsigned int    dummy1800d0b0_23_16:8;
//--    unsigned int    pt2:8;
//--    unsigned int    pt1:8;
//--}HDMI_ptrsv1;
//--
//--typedef struct
//--{
//--    unsigned int    pvsef:32;
//--}HDMI_pvgcr0;
//--
//--typedef struct
//--{
//--    unsigned int    pvs:32;
//--}HDMI_pvsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:3;
//--    unsigned int    cbus_ddc_chsel:1;
//--    unsigned int    hdmi_field:1;
//--    unsigned int    int_pro_chg_flag:1;
//--    unsigned int    int_pro_chg_wd_en:1;
//--    unsigned int    int_pro_chg_int_en:1;
//--    unsigned int    hdcp_ddc_chsel:2;
//--    unsigned int    iclk_sel:2;
//--    unsigned int    csc_r:2;
//--    unsigned int    hdirq:1;
//--    unsigned int    csam:1;
//--    unsigned int    csc:2;
//--    unsigned int    field_decide_sel:1;
//--    unsigned int    prdsam:1;
//--    unsigned int    dsc_r:4;
//--    unsigned int    eoi:1;
//--    unsigned int    eot:1;
//--    unsigned int    se:1;
//--    unsigned int    rs:1;
//--    unsigned int    dsc:4;
//--}HDMI_vcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:30;
//--    unsigned int    pucnr:1;
//--    unsigned int    pucsr:1;
//--}HDMI_acrcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:12;
//--    unsigned int    cts:20;
//--}HDMI_acrsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:12;
//--    unsigned int    n:20;
//--}HDMI_acrsr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    cs:16;
//--}HDMI_acs0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    cs:24;
//--}HDMI_acs1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    pending:1;
//--    unsigned int    avmute:1;
//--    unsigned int    fifod:1;
//--    unsigned int    act:1;
//--    unsigned int    apll:1;
//--    unsigned int    afifoo:1;
//--    unsigned int    afifou:1;
//--    unsigned int    vc:1;
//--}HDMI_intcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    lo1:2;
//--    unsigned int    lo2:2;
//--    unsigned int    lo3:2;
//--    unsigned int    lo4:2;
//--}HDMI_alcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:23;
//--    unsigned int    i2s_clk_en_dvi:1;
//--    unsigned int    spdifo1:1;
//--    unsigned int    spdifo2:1;
//--    unsigned int    spdifo3:1;
//--    unsigned int    spdifo4:1;
//--    unsigned int    i2so1:1;
//--    unsigned int    i2so2:1;
//--    unsigned int    i2so3:1;
//--    unsigned int    i2so4:1;
//--}HDMI_aocr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:26;
//--    unsigned int    nvlgb:1;
//--    unsigned int    nalgb:1;
//--    unsigned int    natgb:1;
//--    unsigned int    ngb:1;
//--    unsigned int    pe:1;
//--    unsigned int    gcp:1;
//--}HDMI_bcsr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:29;
//--    unsigned int    fsre:1;
//--    unsigned int    fsif:1;
//--    unsigned int    fscs:1;
//--}HDMI_asr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    fbif:3;
//--    unsigned int    fbcs:4;
//--}HDMI_asr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:21;
//--    unsigned int    hvf:3;
//--    unsigned int    hdmi_vic:8;
//--}HDMI_video_format;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    hdmi_3d_ext_data:4;
//--    unsigned int    hdmi_3d_metadata_type:3;
//--    unsigned int    reserved_1:1;
//--    unsigned int    hdmi_3d_structure:4;
//--    unsigned int    hdmi_3d_meta_present:1;
//--    unsigned int    reserved_2:3;
//--}HDMI_3d_format;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    en_ncts_chg_irq:1;
//--    unsigned int    ncts_chg_irq:1;
//--    unsigned int    en_ch_status_chg_irq:1;
//--    unsigned int    ch_status_chg_irq:1;
//--}AUDIO_sample_rate_change_irq;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:29;
//--    unsigned int    hbr_audio_mode_manual:1;
//--    unsigned int    hbr_audio_mode_fw:1;
//--    unsigned int    hbr_audio_mode:1;
//--}HIGH_bit_rate_audio_packet;
//--
//--typedef struct
//--{
//--    unsigned int    dummy1800d108_31_14:18;
//--    unsigned int    gain_bypass_en:1;
//--    unsigned int    afifof:1;
//--    unsigned int    afifoe:1;
//--    unsigned int    afifowe_r:1;
//--    unsigned int    afifore_r:2;
//--    unsigned int    tst_i2s_sw:1;
//--    unsigned int    aoem:1;
//--    unsigned int    aoc:1;
//--    unsigned int    audio_test_enable:1;
//--    unsigned int    mgc:1;
//--    unsigned int    afifowe:1;
//--    unsigned int    afifore:2;
//--}HDMI_afcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:31;
//--    unsigned int    audio_bist_clksel:1;
//--}HDMI_afsr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    agi:3;
//--    unsigned int    agd:5;
//--    unsigned int    mg:8;
//--}HDMI_magcr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:1;
//--    unsigned int    ldp_time:10;
//--    unsigned int    ldp_time_mode:1;
//--    unsigned int    fg_r:8;
//--    unsigned int    fg_l:8;
//--    unsigned int    auto_dly_mod:1;
//--    unsigned int    fg_en:1;
//--    unsigned int    ffg_l:1;
//--    unsigned int    ffg_r:1;
//--}HDMI_mag_m_final;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    zcd_ch7_done:1;
//--    unsigned int    zcd_ch6_done:1;
//--    unsigned int    zcd_ch5_done:1;
//--    unsigned int    zcd_ch4_done:1;
//--    unsigned int    zcd_ch3_done:1;
//--    unsigned int    zcd_ch2_done:1;
//--    unsigned int    zcd_ch1_done:1;
//--    unsigned int    zcd_ch0_done:1;
//--    unsigned int    reserved_1:1;
//--    unsigned int    zcd_timeout:7;
//--    unsigned int    zcd_en:1;
//--    unsigned int    zcd_sep_8ch:1;
//--    unsigned int    zcd_sep_st:1;
//--    unsigned int    dummy1800d118_4_0:5;
//--}ZCD_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    xtal_div:8;
//--    unsigned int    afreq_meas_result:12;
//--    unsigned int    afreq_meas_range:3;
//--    unsigned int    popup_afreq_meas_result:1;
//--    unsigned int    audio_freq_detect:1;
//--    unsigned int    auto_load_scode:1;
//--    unsigned int    awd_by_freqchange:1;
//--    unsigned int    awd_by_noaudio:1;
//--    unsigned int    irq_by_freqchange:1;
//--    unsigned int    irq_by_noaudio:1;
//--    unsigned int    freqchange:1;
//--    unsigned int    noaudio:1;
//--}AUDIO_freqdet;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    range0_th:12;
//--    unsigned int    range1_th:12;
//--}RANGE0_1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    range2_th:12;
//--    unsigned int    range3_th:12;
//--}RANGE2_3;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    range4_th:12;
//--    unsigned int    range5_th:12;
//--}RANGE4_5;
//--
//--typedef struct
//--{
//--    unsigned int    pre_set_s1_code3:1;
//--    unsigned int    pre_set_s_code3:7;
//--    unsigned int    pre_set_s1_code2:1;
//--    unsigned int    pre_set_s_code2:7;
//--    unsigned int    pre_set_s1_code1:1;
//--    unsigned int    pre_set_s_code1:7;
//--    unsigned int    pre_set_s1_code0:1;
//--    unsigned int    pre_set_s_code0:7;
//--}PRESET_s_code0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:8;
//--    unsigned int    dp_abuf_wr_mod_en:1;
//--    unsigned int    auto_stop_trk_en:1;
//--    unsigned int    trk_mod_en:1;
//--    unsigned int    afsm_mod_en:1;
//--    unsigned int    reserved_1:4;
//--    unsigned int    pre_set_sm_code0:1;
//--    unsigned int    pre_set_sm_code1:1;
//--    unsigned int    pre_set_sm_code2:1;
//--    unsigned int    pre_set_sm_code3:1;
//--    unsigned int    pre_set_sm_code4:1;
//--    unsigned int    reserved_2:3;
//--    unsigned int    pre_set_s1_code4:1;
//--    unsigned int    pre_set_s_code4:7;
//--}PRESET_s_code1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:4;
//--    unsigned int    prbs7_rxbist_err_cnt:8;
//--    unsigned int    prbs7_err_cnt:4;
//--    unsigned int    reserved_1:2;
//--    unsigned int    prbs7_bit_err:10;
//--    unsigned int    prbs7_lock:1;
//--    unsigned int    prbs7_err_cnt_clr:1;
//--    unsigned int    prbs7_reverse:1;
//--    unsigned int    prbs7_rxen:1;
//--}PRBS7_r_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:4;
//--    unsigned int    prbs7_rxbist_err_cnt:8;
//--    unsigned int    prbs7_err_cnt:4;
//--    unsigned int    reserved_1:2;
//--    unsigned int    prbs7_bit_err:10;
//--    unsigned int    prbs7_lock:1;
//--    unsigned int    prbs7_err_cnt_clr:1;
//--    unsigned int    prbs7_reverse:1;
//--    unsigned int    prbs7_rxen:1;
//--}PRBS7_g_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:4;
//--    unsigned int    prbs7_rxbist_err_cnt:8;
//--    unsigned int    prbs7_err_cnt:4;
//--    unsigned int    reserved_1:2;
//--    unsigned int    prbs7_bit_err:10;
//--    unsigned int    prbs7_lock:1;
//--    unsigned int    prbs7_err_cnt_clr:1;
//--    unsigned int    prbs7_reverse:1;
//--    unsigned int    prbs7_rxen:1;
//--}PRBS7_b_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:1;
//--    unsigned int    cmp_err_flag:1;
//--    unsigned int    cmp_err_wd_en:1;
//--    unsigned int    cmp_err_int_en:1;
//--    unsigned int    preamble:4;
//--    unsigned int    reserved_1:6;
//--    unsigned int    cmp_value:10;
//--    unsigned int    reserved_2:3;
//--    unsigned int    dvi_mode_sel:1;
//--    unsigned int    channel_sel:2;
//--    unsigned int    lgb_cal_conti:1;
//--    unsigned int    lgb_cal_en:1;
//--}HDMI_leading_gb_cmp_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    cmp_err_cnt:16;
//--    unsigned int    cmp_times:16;
//--}HDMI_leading_gb_cmp_times;
//--
//--typedef struct
//--{
//--    unsigned int    preamble_cmp_cnt:16;
//--    unsigned int    preamble_cmp_cnt_by_frame:16;
//--}HDMI_leading_gb_cmp_cnt;
//--
//--typedef struct
//--{
//--    unsigned int    cts_over_flag:1;
//--    unsigned int    reserved_0:10;
//--    unsigned int    cts_clip_en:1;
//--    unsigned int    cts_up_bound:20;
//--}AUDIO_cts_up_bound;
//--
//--typedef struct
//--{
//--    unsigned int    cts_under_flag:1;
//--    unsigned int    reserved_0:11;
//--    unsigned int    cts_low_bound:20;
//--}AUDIO_cts_low_bound;
//--
//--typedef struct
//--{
//--    unsigned int    n_over_flag:1;
//--    unsigned int    reserved_0:10;
//--    unsigned int    n_clip_en:1;
//--    unsigned int    n_up_bound:20;
//--}AUDIO_n_up_bound;
//--
//--typedef struct
//--{
//--    unsigned int    n_under_flag:1;
//--    unsigned int    reserved_0:11;
//--    unsigned int    n_low_bound:20;
//--}AUDIO_n_low_bound;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:19;
//--    unsigned int    pp_mode_output:1;
//--    unsigned int    reserved_1:3;
//--    unsigned int    packet_mhl_en:1;
//--    unsigned int    xor_pixel_sel:3;
//--    unsigned int    cal_pixel_sel:1;
//--    unsigned int    reserved_2:3;
//--    unsigned int    ch_dec_pp_mode_en:1;
//--}MHL_hdmi_mac_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:2;
//--    unsigned int    mhl_3d_fmt:4;
//--    unsigned int    mhl_vid:2;
//--    unsigned int    oui:24;
//--}MHL_3d_format;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    hdcp_2p2_ls1:1;
//--    unsigned int    hdcp_2p2_ls0:1;
//--    unsigned int    hdcp_ksvfifo_ls:1;
//--    unsigned int    hdcp_ls:1;
//--    unsigned int    audio_ls:1;
//--}LIGHT_sleep;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:30;
//--    unsigned int    hdcp_ds:1;
//--    unsigned int    audio_ds:1;
//--}DEEP_sleep;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:30;
//--    unsigned int    hdcp_sd:1;
//--    unsigned int    audio_sd:1;
//--}SHOT_down;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    hdcp_2p2_rme1:1;
//--    unsigned int    hdcp_2p2_rme0:1;
//--    unsigned int    hdcp_ksvfifo_rme:1;
//--    unsigned int    hdcp_rme:1;
//--    unsigned int    audio_rme:1;
//--}READ_margin_enable;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:12;
//--    unsigned int    hdcp_2p2_rm1:4;
//--    unsigned int    hdcp_2p2_rm0:4;
//--    unsigned int    hdcp_ksvfifo_rm:4;
//--    unsigned int    hdcp_rm:4;
//--    unsigned int    audio_rm:4;
//--}READ_margin;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_bist_en:1;
//--    unsigned int    hdcp_ksvfifo_bist_en:1;
//--    unsigned int    hdcp_bist_en:1;
//--    unsigned int    audio_bist_en:1;
//--}BIST_mode;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_bist_done:1;
//--    unsigned int    hdcp_ksvfifo_bist_done:1;
//--    unsigned int    hdcp_bist_done:1;
//--    unsigned int    audio_bist_done:1;
//--}BIST_done;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_bist_fail:1;
//--    unsigned int    hdcp_ksvfifo_bist_fail:1;
//--    unsigned int    hdcp_bist_fail:1;
//--    unsigned int    audio_bist_fail:1;
//--}BIST_fail;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_drf_mode:1;
//--    unsigned int    hdcp_ksvfifo_drf_mode:1;
//--    unsigned int    hdcp_drf_mode:1;
//--    unsigned int    audio_drf_mode:1;
//--}DRF_mode;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_drf_resume:1;
//--    unsigned int    hdcp_ksvfifo_drf_resume:1;
//--    unsigned int    hdcp_drf_resume:1;
//--    unsigned int    audio_drf_resume:1;
//--}DRF_resume;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_drf_done:1;
//--    unsigned int    hdcp_ksvfifo_drf_done:1;
//--    unsigned int    hdcp_drf_done:1;
//--    unsigned int    audio_drf_done:1;
//--}DRF_done;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_drf_pause:1;
//--    unsigned int    hdcp_ksvfifo_drf_pause:1;
//--    unsigned int    hdcp_drf_pause:1;
//--    unsigned int    audio_drf_pause:1;
//--}DRF_pause;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:28;
//--    unsigned int    hdcp_2p2_drf_fail:1;
//--    unsigned int    hdcp_ksvfifo_drf_fail:1;
//--    unsigned int    hdcp_drf_fail:1;
//--    unsigned int    audio_drf_fail:1;
//--}DRF_fail;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    hdcp_dvs:4;
//--    unsigned int    audio_dvs:4;
//--}DVS;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:30;
//--    unsigned int    hdcp_dvse:1;
//--    unsigned int    audio_dvse:1;
//--}DVSE;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    hdmi_test_sel:4;
//--    unsigned int    hdmi_out_sel:1;
//--    unsigned int    force_ctsfifo_rstn_hdmi:1;
//--    unsigned int    en_ctsfifo_vsrst_hdmi:1;
//--    unsigned int    en_ctsfifo_bypass_hdmi:1;
//--}CTS_fifo_ctl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    sys_clk_div:3;
//--    unsigned int    reserved_1:2;
//--    unsigned int    cbus_core_pwdn:1;
//--    unsigned int    sys_clk_en:1;
//--}CBUS_clk_ctl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:32;
//--}HDCP_bist;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    namfe:1;
//--    unsigned int    rpt:1;
//--    unsigned int    ivsp:1;
//--    unsigned int    invvs:1;
//--    unsigned int    ivspm:1;
//--    unsigned int    maddf:1;
//--    unsigned int    dkapde:1;
//--    unsigned int    hdcp_en:1;
//--}HDCP_cr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dkap:8;
//--}HDCP_dkap;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:4;
//--    unsigned int    i2c_scl_dly_sel:4;
//--    unsigned int    i2c_sda_dly_sel:4;
//--    unsigned int    reserved_1:2;
//--    unsigned int    tune_up_down:1;
//--    unsigned int    tune_range:7;
//--    unsigned int    ddcdbnc:1;
//--    unsigned int    km_clk_sel_eco:1;
//--    unsigned int    dbnc_level_sel:1;
//--    unsigned int    km_clk_sel:1;
//--    unsigned int    hdcp_vs_sel:1;
//--    unsigned int    enc_tog:1;
//--    unsigned int    avmute_dis:1;
//--    unsigned int    dummy1800d20c_2:1;
//--    unsigned int    apai_type:1;
//--    unsigned int    apai:1;
//--}HDCP_pcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    wr_aksv_flag:1;
//--    unsigned int    rd_ri_flag:1;
//--    unsigned int    rd_bksv_flag:1;
//--    unsigned int    dummy1800d210_1_0:2;
//--}HDCP_flag1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    irq_aksv_en:1;
//--    unsigned int    irq_ri_en:1;
//--    unsigned int    irq_bksv_en:1;
//--    unsigned int    dummy1800d214_1_0:2;
//--}HDCP_flag2;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:13;
//--    unsigned int    ksvfifo_status:1;
//--    unsigned int    dp_ksvfifo_ptr:10;
//--    unsigned int    ap1:8;
//--}HDCP_ap;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dp1:8;
//--}HDCP_dp;
//--
//--typedef struct
//--{
//--    unsigned int    dummy1800d220_31_25:7;
//--    unsigned int    ks_encoded:1;
//--    unsigned int    switch_state:12;
//--    unsigned int    rpt_thr_unauth:1;
//--    unsigned int    fw_mode_riv:1;
//--    unsigned int    apply_state:1;
//--    unsigned int    mspai:1;
//--    unsigned int    new_auth_device:1;
//--    unsigned int    verify_id_pass:1;
//--    unsigned int    verify_id_done:1;
//--    unsigned int    assemble_id_fail:1;
//--    unsigned int    downstream_done:1;
//--    unsigned int    ks_done:1;
//--    unsigned int    switch_unauth:1;
//--    unsigned int    hdcp_2p2_en:1;
//--}HDCP_2p2_cr;
//--
//--typedef struct
//--{
//--    unsigned int    ks:32;
//--}HDCP_2p2_ks0;
//--
//--typedef struct
//--{
//--    unsigned int    ks:32;
//--}HDCP_2p2_ks1;
//--
//--typedef struct
//--{
//--    unsigned int    ks:32;
//--}HDCP_2p2_ks2;
//--
//--typedef struct
//--{
//--    unsigned int    ks:32;
//--}HDCP_2p2_ks3;
//--
//--typedef struct
//--{
//--    unsigned int    lc:32;
//--}HDCP_2p2_lc0;
//--
//--typedef struct
//--{
//--    unsigned int    lc:32;
//--}HDCP_2p2_lc1;
//--
//--typedef struct
//--{
//--    unsigned int    lc:32;
//--}HDCP_2p2_lc2;
//--
//--typedef struct
//--{
//--    unsigned int    lc:32;
//--}HDCP_2p2_lc3;
//--
//--typedef struct
//--{
//--    unsigned int    riv:32;
//--}HDCP_2p2_riv0;
//--
//--typedef struct
//--{
//--    unsigned int    riv:32;
//--}HDCP_2p2_riv1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:15;
//--    unsigned int    irq_msg_overwrite:1;
//--    unsigned int    irq_unauth_chg:1;
//--    unsigned int    irq_state_chg:1;
//--    unsigned int    irq_rd_msg_done:1;
//--    unsigned int    irq_wr_msg_done:1;
//--    unsigned int    state:12;
//--}HDCP_2p2_sr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    irq_msg_overwrite_en:1;
//--    unsigned int    irq_unauth_chg_en:1;
//--    unsigned int    irq_state_chg_en:1;
//--    unsigned int    irq_rd_msg_done_en:1;
//--    unsigned int    irq_wr_msg_done_en:1;
//--}HDCP_2p2_sr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:22;
//--    unsigned int    ap1:10;
//--}HDCP_msap;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dp1:8;
//--}HDCP_msdp;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    icmux:1;
//--    unsigned int    ocs:2;
//--    unsigned int    dbdcb:1;
//--    unsigned int    dummy1800d300_3_0:4;
//--}HDMI_cmcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dummy1800d304_7_0:8;
//--}HDMI_mcapr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:14;
//--    unsigned int    s1_code_msb_r:1;
//--    unsigned int    slc_r:1;
//--    unsigned int    sc_r:7;
//--    unsigned int    s1_code_msb:1;
//--    unsigned int    slc:1;
//--    unsigned int    sc:7;
//--}HDMI_scapr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    dcaprh:8;
//--    unsigned int    dcaprl:8;
//--}HDMI_dcapr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    fdint:3;
//--    unsigned int    etcn:1;
//--    unsigned int    etfd:1;
//--    unsigned int    etfbc:1;
//--    unsigned int    pecs:2;
//--}HDMI_pscr;
//--
//--typedef struct
//--{
//--    unsigned int    mfddf:8;
//--    unsigned int    mfddr:8;
//--    unsigned int    fddf:8;
//--    unsigned int    fddr:8;
//--}HDMI_afdd;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    tl2der:2;
//--    unsigned int    tl2def:2;
//--    unsigned int    tt:4;
//--}HDMI_ftr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    tfd:5;
//--    unsigned int    bad:3;
//--}HDMI_fbr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    ich:8;
//--    unsigned int    icl:8;
//--}HDMI_icpsncr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    pch:8;
//--    unsigned int    pcl:8;
//--}HDMI_pcpsncr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    icth:8;
//--    unsigned int    ictl:8;
//--}HDMI_ictpsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    pcth:8;
//--    unsigned int    pctl:8;
//--}HDMI_pctpsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    icbh:8;
//--    unsigned int    icbl:8;
//--}HDMI_icbpsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    pcbh:8;
//--    unsigned int    pcbl:8;
//--}HDMI_pcbpsr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:19;
//--    unsigned int    rm:1;
//--    unsigned int    nt:12;
//--}HDMI_ntx1024tr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    ftb:8;
//--}HDMI_stbpr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    ncper:8;
//--}HDMI_ncper;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    petr:8;
//--}HDMI_petr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    cmvtc:1;
//--    unsigned int    cmvbc:1;
//--    unsigned int    ssdmou:1;
//--    unsigned int    tef:1;
//--    unsigned int    w1c5:1;
//--    unsigned int    pem:1;
//--    unsigned int    esdm:1;
//--    unsigned int    dummy1800d350_0:1;
//--}HDMI_aapnr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    dummy1800d354_7:1;
//--    unsigned int    dummy1800d354_6:1;
//--    unsigned int    edm:1;
//--    unsigned int    pst:1;
//--    unsigned int    psc:4;
//--}HDMI_apdmcr;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    fps:4;
//--    unsigned int    sps:4;
//--}HDMI_aptmcr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:25;
//--    unsigned int    plltm:1;
//--    unsigned int    fpsd:1;
//--    unsigned int    spsd:1;
//--    unsigned int    nfpss:4;
//--}HDMI_aptmcr1;
//--
//--typedef struct
//--{
//--    unsigned int    ncts_disable_pe_check_en:1;
//--    unsigned int    ncts_re_enable_off_en:1;
//--    unsigned int    ncts_disable_pe_check_status:1;
//--    unsigned int    ncts_disable_pe_check_irq_en:1;
//--    unsigned int    dummy1800d360_27_20:8;
//--    unsigned int    ncts_disable_pe_check_cnt:20;
//--}HDMI_npecr;
//--
//--typedef struct
//--{
//--    unsigned int    ncts_re_enable_off_start:16;
//--    unsigned int    ncts_re_enable_off_end:16;
//--}HDMI_nror;
//--
//--typedef struct
//--{
//--    unsigned int    over_threshold:1;
//--    unsigned int    under_threshold:1;
//--    unsigned int    wd_by_tmds_clk:1;
//--    unsigned int    irq_by_tmds_clk:1;
//--    unsigned int    nt_up_threshold:12;
//--    unsigned int    reserved_0:4;
//--    unsigned int    nt_low_threshold:12;
//--}HDMI_ntx1024tr0_threshold;
//--
//--typedef struct
//--{
//--    unsigned int    dpll_reg:2;
//--    unsigned int    dpll_m:8;
//--    unsigned int    reserved_0:1;
//--    unsigned int    dpll_reser:4;
//--    unsigned int    dpll_bpn:1;
//--    unsigned int    dpll_o:2;
//--    unsigned int    reserved_1:5;
//--    unsigned int    dpll_n:3;
//--    unsigned int    dpll_rs:3;
//--    unsigned int    dpll_ip:3;
//--}HDMI_apllcr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:9;
//--    unsigned int    dpll_cp:2;
//--    unsigned int    dpll_seltst:2;
//--    unsigned int    dpll_cs:2;
//--    unsigned int    reserved_1:2;
//--    unsigned int    reserved_2:1;
//--    unsigned int    reserved_3:1;
//--    unsigned int    reserved_4:1;
//--    unsigned int    reserved_5:1;
//--    unsigned int    reserved_6:1;
//--    unsigned int    dpll_reserve:1;
//--    unsigned int    dpll_bpphs:1;
//--    unsigned int    dpll_wdo:1;
//--    unsigned int    dpll_wdrst:1;
//--    unsigned int    dpll_wdset:1;
//--    unsigned int    dummy1800d384_4:1;
//--    unsigned int    dpll_stop:1;
//--    unsigned int    dpll_freeze:1;
//--    unsigned int    dpll_vcorstb:1;
//--    unsigned int    dpll_pwdn:1;
//--}HDMI_apllcr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    reserved_1:1;
//--    unsigned int    reserved_2:1;
//--    unsigned int    reserved_3:2;
//--    unsigned int    dpll_rloadm:1;
//--}HDMI_apllcr2;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:16;
//--    unsigned int    sum_c_samp:16;
//--}HDMI_apllcr3;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:2;
//--    unsigned int    dpll_m_test:8;
//--    unsigned int    reserved_1:20;
//--    unsigned int    dpll_m_db:1;
//--    unsigned int    dpll_m_sel:1;
//--}HDMI_apll_testm;
//--
//--typedef struct
//--{
//--    unsigned int    dpll_reg:2;
//--    unsigned int    dpll_m:8;
//--    unsigned int    reserved_0:1;
//--    unsigned int    dpll_reser:4;
//--    unsigned int    dpll_bpn:1;
//--    unsigned int    dpll_o:2;
//--    unsigned int    reserved_1:5;
//--    unsigned int    dpll_n:3;
//--    unsigned int    dpll_rs:3;
//--    unsigned int    dpll_ip:3;
//--}HDMI_vpllcr0;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:9;
//--    unsigned int    dpll_cp:2;
//--    unsigned int    dpll_seltst:2;
//--    unsigned int    dpll_cs:2;
//--    unsigned int    reserved_1:2;
//--    unsigned int    reserved_2:1;
//--    unsigned int    reserved_3:1;
//--    unsigned int    reserved_4:1;
//--    unsigned int    reserved_5:1;
//--    unsigned int    reserved_6:1;
//--    unsigned int    dpll_reserve:1;
//--    unsigned int    dpll_bpphs:1;
//--    unsigned int    dpll_wdo:1;
//--    unsigned int    dpll_wdrst:1;
//--    unsigned int    dpll_wdset:1;
//--    unsigned int    dummy1800d404_4:1;
//--    unsigned int    dpll_stop:1;
//--    unsigned int    dpll_freeze:1;
//--    unsigned int    dpll_vcorstb:1;
//--    unsigned int    dpll_pwdn:1;
//--}HDMI_vpllcr1;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:27;
//--    unsigned int    reserved_1:1;
//--    unsigned int    reserved_2:1;
//--    unsigned int    reserved_3:2;
//--    unsigned int    dpll_rloadm:1;
//--}HDMI_vpllcr2;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    sclkg_pll_in_sel:1;
//--    unsigned int    sclkg_oclk_sel:2;
//--    unsigned int    sclkg_dbuf:1;
//--    unsigned int    dummy1800d410_3_0:4;
//--}MN_sclkg_ctrl;
//--
//--typedef struct
//--{
//--    unsigned int    reserved_0:24;
//--    unsigned int    sclkg_pll_div2_en:1;
//--    unsigned int    sclkg_pll_divs:7;
//--}MN_sclkg_divs;
//--#endif
//--
//--
//--#define TMDS_MSR0                                                     0x1800d000
//--#define TMDS_MSR0_reg_addr                                            "0xb800d000"
//--#define TMDS_MSR0_reg                                                 0xb800d000
//--#define TMDS_MSR0_inst_addr                                           "0x0000"
//--#define TMDS_MSR0_inst                                                0x0000
//--#define set_TMDS_MSR0_reg(data)                                       (*((volatile unsigned int*)TMDS_MSR0_reg)=data)
//--#define get_TMDS_MSR0_reg                                             (*((volatile unsigned int*)TMDS_MSR0_reg))
//--#define TMDS_MSR0_tmm_shift                                           (7)
//--#define TMDS_MSR0_mt_shift                                            (4)
//--#define TMDS_MSR0_ncp_shift                                           (0)
//--#define TMDS_MSR0_tmm_mask                                            (0x00000080)
//--#define TMDS_MSR0_mt_mask                                             (0x00000070)
//--#define TMDS_MSR0_ncp_mask                                            (0x0000000F)
//--#define TMDS_MSR0_tmm(data)                                           (0x00000080&((data)<<7))
//--#define TMDS_MSR0_mt(data)                                            (0x00000070&((data)<<4))
//--#define TMDS_MSR0_ncp(data)                                           (0x0000000F&(data))
//--#define TMDS_MSR0_get_tmm(data)                                       ((0x00000080&(data))>>7)
//--#define TMDS_MSR0_get_mt(data)                                        ((0x00000070&(data))>>4)
//--#define TMDS_MSR0_get_ncp(data)                                       (0x0000000F&(data))
//--
//--
//--#define TMDS_MSR1                                                     0x1800d004
//--#define TMDS_MSR1_reg_addr                                            "0xb800d004"
//--#define TMDS_MSR1_reg                                                 0xb800d004
//--#define TMDS_MSR1_inst_addr                                           "0x0001"
//--#define TMDS_MSR1_inst                                                0x0001
//--#define set_TMDS_MSR1_reg(data)                                       (*((volatile unsigned int*)TMDS_MSR1_reg)=data)
//--#define get_TMDS_MSR1_reg                                             (*((volatile unsigned int*)TMDS_MSR1_reg))
//--#define TMDS_MSR1_tms_shift                                           (12)
//--#define TMDS_MSR1_mrs_shift                                           (10)
//--#define TMDS_MSR1_ms_shift                                            (8)
//--#define TMDS_MSR1_ctc_shift                                           (7)
//--#define TMDS_MSR1_vmr_shift                                           (0)
//--#define TMDS_MSR1_tms_mask                                            (0x00001000)
//--#define TMDS_MSR1_mrs_mask                                            (0x00000C00)
//--#define TMDS_MSR1_ms_mask                                             (0x00000300)
//--#define TMDS_MSR1_ctc_mask                                            (0x00000080)
//--#define TMDS_MSR1_vmr_mask                                            (0x0000007F)
//--#define TMDS_MSR1_tms(data)                                           (0x00001000&((data)<<12))
//--#define TMDS_MSR1_mrs(data)                                           (0x00000C00&((data)<<10))
//--#define TMDS_MSR1_ms(data)                                            (0x00000300&((data)<<8))
//--#define TMDS_MSR1_ctc(data)                                           (0x00000080&((data)<<7))
//--#define TMDS_MSR1_vmr(data)                                           (0x0000007F&(data))
//--#define TMDS_MSR1_get_tms(data)                                       ((0x00001000&(data))>>12)
//--#define TMDS_MSR1_get_mrs(data)                                       ((0x00000C00&(data))>>10)
//--#define TMDS_MSR1_get_ms(data)                                        ((0x00000300&(data))>>8)
//--#define TMDS_MSR1_get_ctc(data)                                       ((0x00000080&(data))>>7)
//--#define TMDS_MSR1_get_vmr(data)                                       (0x0000007F&(data))
//--
//--
//--#define TMDS_CRCC                                                     0x1800d008
//--#define TMDS_CRCC_reg_addr                                            "0xb800d008"
//--#define TMDS_CRCC_reg                                                 0xb800d008
//--#define TMDS_CRCC_inst_addr                                           "0x0002"
//--#define TMDS_CRCC_inst                                                0x0002
//--#define set_TMDS_CRCC_reg(data)                                       (*((volatile unsigned int*)TMDS_CRCC_reg)=data)
//--#define get_TMDS_CRCC_reg                                             (*((volatile unsigned int*)TMDS_CRCC_reg))
//--#define TMDS_CRCC_crc_done_shift                                      (4)
//--#define TMDS_CRCC_crc_nonstable_shift                                 (3)
//--#define TMDS_CRCC_crcts_shift                                         (1)
//--#define TMDS_CRCC_crcc_shift                                          (0)
//--#define TMDS_CRCC_crc_done_mask                                       (0x00000010)
//--#define TMDS_CRCC_crc_nonstable_mask                                  (0x00000008)
//--#define TMDS_CRCC_crcts_mask                                          (0x00000006)
//--#define TMDS_CRCC_crcc_mask                                           (0x00000001)
//--#define TMDS_CRCC_crc_done(data)                                      (0x00000010&((data)<<4))
//--#define TMDS_CRCC_crc_nonstable(data)                                 (0x00000008&((data)<<3))
//--#define TMDS_CRCC_crcts(data)                                         (0x00000006&((data)<<1))
//--#define TMDS_CRCC_crcc(data)                                          (0x00000001&(data))
//--#define TMDS_CRCC_get_crc_done(data)                                  ((0x00000010&(data))>>4)
//--#define TMDS_CRCC_get_crc_nonstable(data)                             ((0x00000008&(data))>>3)
//--#define TMDS_CRCC_get_crcts(data)                                     ((0x00000006&(data))>>1)
//--#define TMDS_CRCC_get_crcc(data)                                      (0x00000001&(data))
//--
//--
//--#define TMDS_CRCO0                                                    0x1800d00c
//--#define TMDS_CRCO0_reg_addr                                           "0xb800d00c"
//--#define TMDS_CRCO0_reg                                                0xb800d00c
//--#define TMDS_CRCO0_inst_addr                                          "0x0003"
//--#define TMDS_CRCO0_inst                                               0x0003
//--#define set_TMDS_CRCO0_reg(data)                                      (*((volatile unsigned int*)TMDS_CRCO0_reg)=data)
//--#define get_TMDS_CRCO0_reg                                            (*((volatile unsigned int*)TMDS_CRCO0_reg))
//--#define TMDS_CRCO0_crcob2_3_shift                                     (16)
//--#define TMDS_CRCO0_crcob2_2_shift                                     (8)
//--#define TMDS_CRCO0_crcob2_1_shift                                     (0)
//--#define TMDS_CRCO0_crcob2_3_mask                                      (0x00FF0000)
//--#define TMDS_CRCO0_crcob2_2_mask                                      (0x0000FF00)
//--#define TMDS_CRCO0_crcob2_1_mask                                      (0x000000FF)
//--#define TMDS_CRCO0_crcob2_3(data)                                     (0x00FF0000&((data)<<16))
//--#define TMDS_CRCO0_crcob2_2(data)                                     (0x0000FF00&((data)<<8))
//--#define TMDS_CRCO0_crcob2_1(data)                                     (0x000000FF&(data))
//--#define TMDS_CRCO0_get_crcob2_3(data)                                 ((0x00FF0000&(data))>>16)
//--#define TMDS_CRCO0_get_crcob2_2(data)                                 ((0x0000FF00&(data))>>8)
//--#define TMDS_CRCO0_get_crcob2_1(data)                                 (0x000000FF&(data))
//--
//--
//--#define TMDS_CRCO1                                                    0x1800d010
//--#define TMDS_CRCO1_reg_addr                                           "0xb800d010"
//--#define TMDS_CRCO1_reg                                                0xb800d010
//--#define TMDS_CRCO1_inst_addr                                          "0x0004"
//--#define TMDS_CRCO1_inst                                               0x0004
//--#define set_TMDS_CRCO1_reg(data)                                      (*((volatile unsigned int*)TMDS_CRCO1_reg)=data)
//--#define get_TMDS_CRCO1_reg                                            (*((volatile unsigned int*)TMDS_CRCO1_reg))
//--#define TMDS_CRCO1_crcob2_6_shift                                     (16)
//--#define TMDS_CRCO1_crcob2_5_shift                                     (8)
//--#define TMDS_CRCO1_crcob2_4_shift                                     (0)
//--#define TMDS_CRCO1_crcob2_6_mask                                      (0x00FF0000)
//--#define TMDS_CRCO1_crcob2_5_mask                                      (0x0000FF00)
//--#define TMDS_CRCO1_crcob2_4_mask                                      (0x000000FF)
//--#define TMDS_CRCO1_crcob2_6(data)                                     (0x00FF0000&((data)<<16))
//--#define TMDS_CRCO1_crcob2_5(data)                                     (0x0000FF00&((data)<<8))
//--#define TMDS_CRCO1_crcob2_4(data)                                     (0x000000FF&(data))
//--#define TMDS_CRCO1_get_crcob2_6(data)                                 ((0x00FF0000&(data))>>16)
//--#define TMDS_CRCO1_get_crcob2_5(data)                                 ((0x0000FF00&(data))>>8)
//--#define TMDS_CRCO1_get_crcob2_4(data)                                 (0x000000FF&(data))
//--
//--
//--#define TMDS_CTRL                                                     0x1800d014
//--#define TMDS_CTRL_reg_addr                                            "0xb800d014"
//--#define TMDS_CTRL_reg                                                 0xb800d014
//--#define TMDS_CTRL_inst_addr                                           "0x0005"
//--#define TMDS_CTRL_inst                                                0x0005
//--#define set_TMDS_CTRL_reg(data)                                       (*((volatile unsigned int*)TMDS_CTRL_reg)=data)
//--#define get_TMDS_CTRL_reg                                             (*((volatile unsigned int*)TMDS_CTRL_reg))
//--#define TMDS_CTRL_bcd_shift                                           (7)
//--#define TMDS_CTRL_gcd_shift                                           (6)
//--#define TMDS_CTRL_rcd_shift                                           (5)
//--#define TMDS_CTRL_ho_shift                                            (4)
//--#define TMDS_CTRL_yo_shift                                            (3)
//--#define TMDS_CTRL_dummy1800d014_2_0_shift                             (0)
//--#define TMDS_CTRL_bcd_mask                                            (0x00000080)
//--#define TMDS_CTRL_gcd_mask                                            (0x00000040)
//--#define TMDS_CTRL_rcd_mask                                            (0x00000020)
//--#define TMDS_CTRL_ho_mask                                             (0x00000010)
//--#define TMDS_CTRL_yo_mask                                             (0x00000008)
//--#define TMDS_CTRL_dummy1800d014_2_0_mask                              (0x00000007)
//--#define TMDS_CTRL_bcd(data)                                           (0x00000080&((data)<<7))
//--#define TMDS_CTRL_gcd(data)                                           (0x00000040&((data)<<6))
//--#define TMDS_CTRL_rcd(data)                                           (0x00000020&((data)<<5))
//--#define TMDS_CTRL_ho(data)                                            (0x00000010&((data)<<4))
//--#define TMDS_CTRL_yo(data)                                            (0x00000008&((data)<<3))
//--#define TMDS_CTRL_dummy1800d014_2_0(data)                             (0x00000007&(data))
//--#define TMDS_CTRL_get_bcd(data)                                       ((0x00000080&(data))>>7)
//--#define TMDS_CTRL_get_gcd(data)                                       ((0x00000040&(data))>>6)
//--#define TMDS_CTRL_get_rcd(data)                                       ((0x00000020&(data))>>5)
//--#define TMDS_CTRL_get_ho(data)                                        ((0x00000010&(data))>>4)
//--#define TMDS_CTRL_get_yo(data)                                        ((0x00000008&(data))>>3)
//--#define TMDS_CTRL_get_dummy1800d014_2_0(data)                         (0x00000007&(data))
//--
//--
//--#define TMDS_OUTCTL                                                   0x1800d018
//--#define TMDS_OUTCTL_reg_addr                                          "0xb800d018"
//--#define TMDS_OUTCTL_reg                                               0xb800d018
//--#define TMDS_OUTCTL_inst_addr                                         "0x0006"
//--#define TMDS_OUTCTL_inst                                              0x0006
//--#define set_TMDS_OUTCTL_reg(data)                                     (*((volatile unsigned int*)TMDS_OUTCTL_reg)=data)
//--#define get_TMDS_OUTCTL_reg                                           (*((volatile unsigned int*)TMDS_OUTCTL_reg))
//--#define TMDS_OUTCTL_trcoe_r_shift                                     (13)
//--#define TMDS_OUTCTL_tgcoe_r_shift                                     (12)
//--#define TMDS_OUTCTL_tbcoe_r_shift                                     (11)
//--#define TMDS_OUTCTL_ocke_r_shift                                      (10)
//--#define TMDS_OUTCTL_aoe_shift                                         (9)
//--#define TMDS_OUTCTL_trcoe_shift                                       (8)
//--#define TMDS_OUTCTL_tgcoe_shift                                       (7)
//--#define TMDS_OUTCTL_tbcoe_shift                                       (6)
//--#define TMDS_OUTCTL_ocke_shift                                        (5)
//--#define TMDS_OUTCTL_ockie_shift                                       (4)
//--#define TMDS_OUTCTL_dummy1800d018_3_shift                             (3)
//--#define TMDS_OUTCTL_dummy1800d018_2_shift                             (2)
//--#define TMDS_OUTCTL_dummy1800d018_1_shift                             (1)
//--#define TMDS_OUTCTL_dummy1800d018_0_shift                             (0)
//--#define TMDS_OUTCTL_trcoe_r_mask                                      (0x00002000)
//--#define TMDS_OUTCTL_tgcoe_r_mask                                      (0x00001000)
//--#define TMDS_OUTCTL_tbcoe_r_mask                                      (0x00000800)
//--#define TMDS_OUTCTL_ocke_r_mask                                       (0x00000400)
//--#define TMDS_OUTCTL_aoe_mask                                          (0x00000200)
//--#define TMDS_OUTCTL_trcoe_mask                                        (0x00000100)
//--#define TMDS_OUTCTL_tgcoe_mask                                        (0x00000080)
//--#define TMDS_OUTCTL_tbcoe_mask                                        (0x00000040)
//--#define TMDS_OUTCTL_ocke_mask                                         (0x00000020)
//--#define TMDS_OUTCTL_ockie_mask                                        (0x00000010)
//--#define TMDS_OUTCTL_dummy1800d018_3_mask                              (0x00000008)
//--#define TMDS_OUTCTL_dummy1800d018_2_mask                              (0x00000004)
//--#define TMDS_OUTCTL_dummy1800d018_1_mask                              (0x00000002)
//--#define TMDS_OUTCTL_dummy1800d018_0_mask                              (0x00000001)
//--#define TMDS_OUTCTL_trcoe_r(data)                                     (0x00002000&((data)<<13))
//--#define TMDS_OUTCTL_tgcoe_r(data)                                     (0x00001000&((data)<<12))
//--#define TMDS_OUTCTL_tbcoe_r(data)                                     (0x00000800&((data)<<11))
//--#define TMDS_OUTCTL_ocke_r(data)                                      (0x00000400&((data)<<10))
//--#define TMDS_OUTCTL_aoe(data)                                         (0x00000200&((data)<<9))
//--#define TMDS_OUTCTL_trcoe(data)                                       (0x00000100&((data)<<8))
//--#define TMDS_OUTCTL_tgcoe(data)                                       (0x00000080&((data)<<7))
//--#define TMDS_OUTCTL_tbcoe(data)                                       (0x00000040&((data)<<6))
//--#define TMDS_OUTCTL_ocke(data)                                        (0x00000020&((data)<<5))
//--#define TMDS_OUTCTL_ockie(data)                                       (0x00000010&((data)<<4))
//--#define TMDS_OUTCTL_dummy1800d018_3(data)                             (0x00000008&((data)<<3))
//--#define TMDS_OUTCTL_dummy1800d018_2(data)                             (0x00000004&((data)<<2))
//--#define TMDS_OUTCTL_dummy1800d018_1(data)                             (0x00000002&((data)<<1))
//--#define TMDS_OUTCTL_dummy1800d018_0(data)                             (0x00000001&(data))
//--#define TMDS_OUTCTL_get_trcoe_r(data)                                 ((0x00002000&(data))>>13)
//--#define TMDS_OUTCTL_get_tgcoe_r(data)                                 ((0x00001000&(data))>>12)
//--#define TMDS_OUTCTL_get_tbcoe_r(data)                                 ((0x00000800&(data))>>11)
//--#define TMDS_OUTCTL_get_ocke_r(data)                                  ((0x00000400&(data))>>10)
//--#define TMDS_OUTCTL_get_aoe(data)                                     ((0x00000200&(data))>>9)
//--#define TMDS_OUTCTL_get_trcoe(data)                                   ((0x00000100&(data))>>8)
//--#define TMDS_OUTCTL_get_tgcoe(data)                                   ((0x00000080&(data))>>7)
//--#define TMDS_OUTCTL_get_tbcoe(data)                                   ((0x00000040&(data))>>6)
//--#define TMDS_OUTCTL_get_ocke(data)                                    ((0x00000020&(data))>>5)
//--#define TMDS_OUTCTL_get_ockie(data)                                   ((0x00000010&(data))>>4)
//--#define TMDS_OUTCTL_get_dummy1800d018_3(data)                         ((0x00000008&(data))>>3)
//--#define TMDS_OUTCTL_get_dummy1800d018_2(data)                         ((0x00000004&(data))>>2)
//--#define TMDS_OUTCTL_get_dummy1800d018_1(data)                         ((0x00000002&(data))>>1)
//--#define TMDS_OUTCTL_get_dummy1800d018_0(data)                         (0x00000001&(data))
//--
//--
//--#define TMDS_PWDCTL                                                   0x1800d01c
//--#define TMDS_PWDCTL_reg_addr                                          "0xb800d01c"
//--#define TMDS_PWDCTL_reg                                               0xb800d01c
//--#define TMDS_PWDCTL_inst_addr                                         "0x0007"
//--#define TMDS_PWDCTL_inst                                              0x0007
//--#define set_TMDS_PWDCTL_reg(data)                                     (*((volatile unsigned int*)TMDS_PWDCTL_reg)=data)
//--#define get_TMDS_PWDCTL_reg                                           (*((volatile unsigned int*)TMDS_PWDCTL_reg))
//--#define TMDS_PWDCTL_ecc_r_shift                                       (31)
//--#define TMDS_PWDCTL_erip_r_shift                                      (30)
//--#define TMDS_PWDCTL_egip_r_shift                                      (29)
//--#define TMDS_PWDCTL_ebip_r_shift                                      (28)
//--#define TMDS_PWDCTL_dummy1800d01c_27_10_shift                         (10)
//--#define TMDS_PWDCTL_video_preamble_off_en_shift                       (9)
//--#define TMDS_PWDCTL_hs_width_sel_shift                                (8)
//--#define TMDS_PWDCTL_deo_shift                                         (7)
//--#define TMDS_PWDCTL_brcw_shift                                        (6)
//--#define TMDS_PWDCTL_pnsw_shift                                        (5)
//--#define TMDS_PWDCTL_iccaf_shift                                       (4)
//--#define TMDS_PWDCTL_ecc_shift                                         (3)
//--#define TMDS_PWDCTL_erip_shift                                        (2)
//--#define TMDS_PWDCTL_egip_shift                                        (1)
//--#define TMDS_PWDCTL_ebip_shift                                        (0)
//--#define TMDS_PWDCTL_ecc_r_mask                                        (0x80000000)
//--#define TMDS_PWDCTL_erip_r_mask                                       (0x40000000)
//--#define TMDS_PWDCTL_egip_r_mask                                       (0x20000000)
//--#define TMDS_PWDCTL_ebip_r_mask                                       (0x10000000)
//--#define TMDS_PWDCTL_dummy1800d01c_27_10_mask                          (0x0FFFFC00)
//--#define TMDS_PWDCTL_video_preamble_off_en_mask                        (0x00000200)
//--#define TMDS_PWDCTL_hs_width_sel_mask                                 (0x00000100)
//--#define TMDS_PWDCTL_deo_mask                                          (0x00000080)
//--#define TMDS_PWDCTL_brcw_mask                                         (0x00000040)
//--#define TMDS_PWDCTL_pnsw_mask                                         (0x00000020)
//--#define TMDS_PWDCTL_iccaf_mask                                        (0x00000010)
//--#define TMDS_PWDCTL_ecc_mask                                          (0x00000008)
//--#define TMDS_PWDCTL_erip_mask                                         (0x00000004)
//--#define TMDS_PWDCTL_egip_mask                                         (0x00000002)
//--#define TMDS_PWDCTL_ebip_mask                                         (0x00000001)
//--#define TMDS_PWDCTL_ecc_r(data)                                       (0x80000000&((data)<<31))
//--#define TMDS_PWDCTL_erip_r(data)                                      (0x40000000&((data)<<30))
//--#define TMDS_PWDCTL_egip_r(data)                                      (0x20000000&((data)<<29))
//--#define TMDS_PWDCTL_ebip_r(data)                                      (0x10000000&((data)<<28))
//--#define TMDS_PWDCTL_dummy1800d01c_27_10(data)                         (0x0FFFFC00&((data)<<10))
//--#define TMDS_PWDCTL_video_preamble_off_en(data)                       (0x00000200&((data)<<9))
//--#define TMDS_PWDCTL_hs_width_sel(data)                                (0x00000100&((data)<<8))
//--#define TMDS_PWDCTL_deo(data)                                         (0x00000080&((data)<<7))
//--#define TMDS_PWDCTL_brcw(data)                                        (0x00000040&((data)<<6))
//--#define TMDS_PWDCTL_pnsw(data)                                        (0x00000020&((data)<<5))
//--#define TMDS_PWDCTL_iccaf(data)                                       (0x00000010&((data)<<4))
//--#define TMDS_PWDCTL_ecc(data)                                         (0x00000008&((data)<<3))
//--#define TMDS_PWDCTL_erip(data)                                        (0x00000004&((data)<<2))
//--#define TMDS_PWDCTL_egip(data)                                        (0x00000002&((data)<<1))
//--#define TMDS_PWDCTL_ebip(data)                                        (0x00000001&(data))
//--#define TMDS_PWDCTL_get_ecc_r(data)                                   ((0x80000000&(data))>>31)
//--#define TMDS_PWDCTL_get_erip_r(data)                                  ((0x40000000&(data))>>30)
//--#define TMDS_PWDCTL_get_egip_r(data)                                  ((0x20000000&(data))>>29)
//--#define TMDS_PWDCTL_get_ebip_r(data)                                  ((0x10000000&(data))>>28)
//--#define TMDS_PWDCTL_get_dummy1800d01c_27_10(data)                     ((0x0FFFFC00&(data))>>10)
//--#define TMDS_PWDCTL_get_video_preamble_off_en(data)                   ((0x00000200&(data))>>9)
//--#define TMDS_PWDCTL_get_hs_width_sel(data)                            ((0x00000100&(data))>>8)
//--#define TMDS_PWDCTL_get_deo(data)                                     ((0x00000080&(data))>>7)
//--#define TMDS_PWDCTL_get_brcw(data)                                    ((0x00000040&(data))>>6)
//--#define TMDS_PWDCTL_get_pnsw(data)                                    ((0x00000020&(data))>>5)
//--#define TMDS_PWDCTL_get_iccaf(data)                                   ((0x00000010&(data))>>4)
//--#define TMDS_PWDCTL_get_ecc(data)                                     ((0x00000008&(data))>>3)
//--#define TMDS_PWDCTL_get_erip(data)                                    ((0x00000004&(data))>>2)
//--#define TMDS_PWDCTL_get_egip(data)                                    ((0x00000002&(data))>>1)
//--#define TMDS_PWDCTL_get_ebip(data)                                    (0x00000001&(data))
//--
//--
//--#define TMDS_Z0CC                                                     0x1800d020
//--#define TMDS_Z0CC_reg_addr                                            "0xb800d020"
//--#define TMDS_Z0CC_reg                                                 0xb800d020
//--#define TMDS_Z0CC_inst_addr                                           "0x0008"
//--#define TMDS_Z0CC_inst                                                0x0008
//--#define set_TMDS_Z0CC_reg(data)                                       (*((volatile unsigned int*)TMDS_Z0CC_reg)=data)
//--#define get_TMDS_Z0CC_reg                                             (*((volatile unsigned int*)TMDS_Z0CC_reg))
//--#define TMDS_Z0CC_hde_shift                                           (0)
//--#define TMDS_Z0CC_hde_mask                                            (0x00000001)
//--#define TMDS_Z0CC_hde(data)                                           (0x00000001&(data))
//--#define TMDS_Z0CC_get_hde(data)                                       (0x00000001&(data))
//--
//--
//--#define TMDS_CPS                                                      0x1800d024
//--#define TMDS_CPS_reg_addr                                             "0xb800d024"
//--#define TMDS_CPS_reg                                                  0xb800d024
//--#define TMDS_CPS_inst_addr                                            "0x0009"
//--#define TMDS_CPS_inst                                                 0x0009
//--#define set_TMDS_CPS_reg(data)                                        (*((volatile unsigned int*)TMDS_CPS_reg)=data)
//--#define get_TMDS_CPS_reg                                              (*((volatile unsigned int*)TMDS_CPS_reg))
//--#define TMDS_CPS_pll_div2_en_shift                                    (9)
//--#define TMDS_CPS_no_clk_in_shift                                      (8)
//--#define TMDS_CPS_clkv_meas_sel_shift                                  (6)
//--#define TMDS_CPS_de_inv_disable_shift                                 (5)
//--#define TMDS_CPS_de_err_pulse_en_shift                                (4)
//--#define TMDS_CPS_clr_infoframe_dvi_shift                              (3)
//--#define TMDS_CPS_auto_dvi2hdmi_shift                                  (2)
//--#define TMDS_CPS_dummy1800d024_1_0_shift                              (0)
//--#define TMDS_CPS_pll_div2_en_mask                                     (0x00000200)
//--#define TMDS_CPS_no_clk_in_mask                                       (0x00000100)
//--#define TMDS_CPS_clkv_meas_sel_mask                                   (0x000000C0)
//--#define TMDS_CPS_de_inv_disable_mask                                  (0x00000020)
//--#define TMDS_CPS_de_err_pulse_en_mask                                 (0x00000010)
//--#define TMDS_CPS_clr_infoframe_dvi_mask                               (0x00000008)
//--#define TMDS_CPS_auto_dvi2hdmi_mask                                   (0x00000004)
//--#define TMDS_CPS_dummy1800d024_1_0_mask                               (0x00000003)
//--#define TMDS_CPS_pll_div2_en(data)                                    (0x00000200&((data)<<9))
//--#define TMDS_CPS_no_clk_in(data)                                      (0x00000100&((data)<<8))
//--#define TMDS_CPS_clkv_meas_sel(data)                                  (0x000000C0&((data)<<6))
//--#define TMDS_CPS_de_inv_disable(data)                                 (0x00000020&((data)<<5))
//--#define TMDS_CPS_de_err_pulse_en(data)                                (0x00000010&((data)<<4))
//--#define TMDS_CPS_clr_infoframe_dvi(data)                              (0x00000008&((data)<<3))
//--#define TMDS_CPS_auto_dvi2hdmi(data)                                  (0x00000004&((data)<<2))
//--#define TMDS_CPS_dummy1800d024_1_0(data)                              (0x00000003&(data))
//--#define TMDS_CPS_get_pll_div2_en(data)                                ((0x00000200&(data))>>9)
//--#define TMDS_CPS_get_no_clk_in(data)                                  ((0x00000100&(data))>>8)
//--#define TMDS_CPS_get_clkv_meas_sel(data)                              ((0x000000C0&(data))>>6)
//--#define TMDS_CPS_get_de_inv_disable(data)                             ((0x00000020&(data))>>5)
//--#define TMDS_CPS_get_de_err_pulse_en(data)                            ((0x00000010&(data))>>4)
//--#define TMDS_CPS_get_clr_infoframe_dvi(data)                          ((0x00000008&(data))>>3)
//--#define TMDS_CPS_get_auto_dvi2hdmi(data)                              ((0x00000004&(data))>>2)
//--#define TMDS_CPS_get_dummy1800d024_1_0(data)                          (0x00000003&(data))
//--
//--
//--#define TMDS_UDC                                                      0x1800d028
//--#define TMDS_UDC_reg_addr                                             "0xb800d028"
//--#define TMDS_UDC_reg                                                  0xb800d028
//--#define TMDS_UDC_inst_addr                                            "0x000A"
//--#define TMDS_UDC_inst                                                 0x000A
//--#define set_TMDS_UDC_reg(data)                                        (*((volatile unsigned int*)TMDS_UDC_reg)=data)
//--#define get_TMDS_UDC_reg                                              (*((volatile unsigned int*)TMDS_UDC_reg))
//--#define TMDS_UDC_debug_sel_shift                                      (4)
//--#define TMDS_UDC_dummy1800d028_3_shift                                (3)
//--#define TMDS_UDC_cptest_shift                                         (2)
//--#define TMDS_UDC_hmtm_shift                                           (0)
//--#define TMDS_UDC_debug_sel_mask                                       (0x000003F0)
//--#define TMDS_UDC_dummy1800d028_3_mask                                 (0x00000008)
//--#define TMDS_UDC_cptest_mask                                          (0x00000004)
//--#define TMDS_UDC_hmtm_mask                                            (0x00000003)
//--#define TMDS_UDC_debug_sel(data)                                      (0x000003F0&((data)<<4))
//--#define TMDS_UDC_dummy1800d028_3(data)                                (0x00000008&((data)<<3))
//--#define TMDS_UDC_cptest(data)                                         (0x00000004&((data)<<2))
//--#define TMDS_UDC_hmtm(data)                                           (0x00000003&(data))
//--#define TMDS_UDC_get_debug_sel(data)                                  ((0x000003F0&(data))>>4)
//--#define TMDS_UDC_get_dummy1800d028_3(data)                            ((0x00000008&(data))>>3)
//--#define TMDS_UDC_get_cptest(data)                                     ((0x00000004&(data))>>2)
//--#define TMDS_UDC_get_hmtm(data)                                       (0x00000003&(data))
//--
//--
//--#define TMDS_ERRC                                                     0x1800d02c
//--#define TMDS_ERRC_reg_addr                                            "0xb800d02c"
//--#define TMDS_ERRC_reg                                                 0xb800d02c
//--#define TMDS_ERRC_inst_addr                                           "0x000B"
//--#define TMDS_ERRC_inst                                                0x000B
//--#define set_TMDS_ERRC_reg(data)                                       (*((volatile unsigned int*)TMDS_ERRC_reg)=data)
//--#define get_TMDS_ERRC_reg                                             (*((volatile unsigned int*)TMDS_ERRC_reg))
//--#define TMDS_ERRC_nl_shift                                            (0)
//--#define TMDS_ERRC_nl_mask                                             (0x00000007)
//--#define TMDS_ERRC_nl(data)                                            (0x00000007&(data))
//--#define TMDS_ERRC_get_nl(data)                                        (0x00000007&(data))
//--
//--
//--#define TMDS_OUT_CTRL                                                 0x1800d030
//--#define TMDS_OUT_CTRL_reg_addr                                        "0xb800d030"
//--#define TMDS_OUT_CTRL_reg                                             0xb800d030
//--#define TMDS_OUT_CTRL_inst_addr                                       "0x000C"
//--#define TMDS_OUT_CTRL_inst                                            0x000C
//--#define set_TMDS_OUT_CTRL_reg(data)                                   (*((volatile unsigned int*)TMDS_OUT_CTRL_reg)=data)
//--#define get_TMDS_OUT_CTRL_reg                                         (*((volatile unsigned int*)TMDS_OUT_CTRL_reg))
//--#define TMDS_OUT_CTRL_tmds_bypass_shift                               (7)
//--#define TMDS_OUT_CTRL_dummy1800d030_6_0_shift                         (0)
//--#define TMDS_OUT_CTRL_tmds_bypass_mask                                (0x00000080)
//--#define TMDS_OUT_CTRL_dummy1800d030_6_0_mask                          (0x0000007F)
//--#define TMDS_OUT_CTRL_tmds_bypass(data)                               (0x00000080&((data)<<7))
//--#define TMDS_OUT_CTRL_dummy1800d030_6_0(data)                         (0x0000007F&(data))
//--#define TMDS_OUT_CTRL_get_tmds_bypass(data)                           ((0x00000080&(data))>>7)
//--#define TMDS_OUT_CTRL_get_dummy1800d030_6_0(data)                     (0x0000007F&(data))
//--
//--
//--#define TMDS_ROUT                                                     0x1800d034
//--#define TMDS_ROUT_reg_addr                                            "0xb800d034"
//--#define TMDS_ROUT_reg                                                 0xb800d034
//--#define TMDS_ROUT_inst_addr                                           "0x000D"
//--#define TMDS_ROUT_inst                                                0x000D
//--#define set_TMDS_ROUT_reg(data)                                       (*((volatile unsigned int*)TMDS_ROUT_reg)=data)
//--#define get_TMDS_ROUT_reg                                             (*((volatile unsigned int*)TMDS_ROUT_reg))
//--#define TMDS_ROUT_tmds_rout_h_shift                                   (8)
//--#define TMDS_ROUT_tmds_rout_l_shift                                   (0)
//--#define TMDS_ROUT_tmds_rout_h_mask                                    (0x0000FF00)
//--#define TMDS_ROUT_tmds_rout_l_mask                                    (0x000000FF)
//--#define TMDS_ROUT_tmds_rout_h(data)                                   (0x0000FF00&((data)<<8))
//--#define TMDS_ROUT_tmds_rout_l(data)                                   (0x000000FF&(data))
//--#define TMDS_ROUT_get_tmds_rout_h(data)                               ((0x0000FF00&(data))>>8)
//--#define TMDS_ROUT_get_tmds_rout_l(data)                               (0x000000FF&(data))
//--
//--
//--#define TMDS_GOUT                                                     0x1800d038
//--#define TMDS_GOUT_reg_addr                                            "0xb800d038"
//--#define TMDS_GOUT_reg                                                 0xb800d038
//--#define TMDS_GOUT_inst_addr                                           "0x000E"
//--#define TMDS_GOUT_inst                                                0x000E
//--#define set_TMDS_GOUT_reg(data)                                       (*((volatile unsigned int*)TMDS_GOUT_reg)=data)
//--#define get_TMDS_GOUT_reg                                             (*((volatile unsigned int*)TMDS_GOUT_reg))
//--#define TMDS_GOUT_tmds_gout_h_shift                                   (8)
//--#define TMDS_GOUT_tmds_gout_l_shift                                   (0)
//--#define TMDS_GOUT_tmds_gout_h_mask                                    (0x0000FF00)
//--#define TMDS_GOUT_tmds_gout_l_mask                                    (0x000000FF)
//--#define TMDS_GOUT_tmds_gout_h(data)                                   (0x0000FF00&((data)<<8))
//--#define TMDS_GOUT_tmds_gout_l(data)                                   (0x000000FF&(data))
//--#define TMDS_GOUT_get_tmds_gout_h(data)                               ((0x0000FF00&(data))>>8)
//--#define TMDS_GOUT_get_tmds_gout_l(data)                               (0x000000FF&(data))
//--
//--
//--#define TMDS_BOUT                                                     0x1800d03c
//--#define TMDS_BOUT_reg_addr                                            "0xb800d03c"
//--#define TMDS_BOUT_reg                                                 0xb800d03c
//--#define TMDS_BOUT_inst_addr                                           "0x000F"
//--#define TMDS_BOUT_inst                                                0x000F
//--#define set_TMDS_BOUT_reg(data)                                       (*((volatile unsigned int*)TMDS_BOUT_reg)=data)
//--#define get_TMDS_BOUT_reg                                             (*((volatile unsigned int*)TMDS_BOUT_reg))
//--#define TMDS_BOUT_tmds_bout_h_shift                                   (8)
//--#define TMDS_BOUT_tmds_bout_l_shift                                   (0)
//--#define TMDS_BOUT_tmds_bout_h_mask                                    (0x0000FF00)
//--#define TMDS_BOUT_tmds_bout_l_mask                                    (0x000000FF)
//--#define TMDS_BOUT_tmds_bout_h(data)                                   (0x0000FF00&((data)<<8))
//--#define TMDS_BOUT_tmds_bout_l(data)                                   (0x000000FF&(data))
//--#define TMDS_BOUT_get_tmds_bout_h(data)                               ((0x0000FF00&(data))>>8)
//--#define TMDS_BOUT_get_tmds_bout_l(data)                               (0x000000FF&(data))
//--
//--
//--#define TMDS_DPC0                                                     0x1800d040
//--#define TMDS_DPC0_reg_addr                                            "0xb800d040"
//--#define TMDS_DPC0_reg                                                 0xb800d040
//--#define TMDS_DPC0_inst_addr                                           "0x0010"
//--#define TMDS_DPC0_inst                                                0x0010
//--#define set_TMDS_DPC0_reg(data)                                       (*((volatile unsigned int*)TMDS_DPC0_reg)=data)
//--#define get_TMDS_DPC0_reg                                             (*((volatile unsigned int*)TMDS_DPC0_reg))
//--#define TMDS_DPC0_dpc_pp_valid_shift                                  (9)
//--#define TMDS_DPC0_dpc_default_ph_shift                                (8)
//--#define TMDS_DPC0_dpc_pp_shift                                        (4)
//--#define TMDS_DPC0_dpc_cd_shift                                        (0)
//--#define TMDS_DPC0_dpc_pp_valid_mask                                   (0x00000200)
//--#define TMDS_DPC0_dpc_default_ph_mask                                 (0x00000100)
//--#define TMDS_DPC0_dpc_pp_mask                                         (0x000000F0)
//--#define TMDS_DPC0_dpc_cd_mask                                         (0x0000000F)
//--#define TMDS_DPC0_dpc_pp_valid(data)                                  (0x00000200&((data)<<9))
//--#define TMDS_DPC0_dpc_default_ph(data)                                (0x00000100&((data)<<8))
//--#define TMDS_DPC0_dpc_pp(data)                                        (0x000000F0&((data)<<4))
//--#define TMDS_DPC0_dpc_cd(data)                                        (0x0000000F&(data))
//--#define TMDS_DPC0_get_dpc_pp_valid(data)                              ((0x00000200&(data))>>9)
//--#define TMDS_DPC0_get_dpc_default_ph(data)                            ((0x00000100&(data))>>8)
//--#define TMDS_DPC0_get_dpc_pp(data)                                    ((0x000000F0&(data))>>4)
//--#define TMDS_DPC0_get_dpc_cd(data)                                    (0x0000000F&(data))
//--
//--
//--#define TMDS_DPC1                                                     0x1800d044
//--#define TMDS_DPC1_reg_addr                                            "0xb800d044"
//--#define TMDS_DPC1_reg                                                 0xb800d044
//--#define TMDS_DPC1_inst_addr                                           "0x0011"
//--#define TMDS_DPC1_inst                                                0x0011
//--#define set_TMDS_DPC1_reg(data)                                       (*((volatile unsigned int*)TMDS_DPC1_reg)=data)
//--#define get_TMDS_DPC1_reg                                             (*((volatile unsigned int*)TMDS_DPC1_reg))
//--#define TMDS_DPC1_dpc_cd_chg_flag_shift                               (18)
//--#define TMDS_DPC1_dpc_cd_chg_wd_en_shift                              (17)
//--#define TMDS_DPC1_dpc_cd_chg_int_en_shift                             (16)
//--#define TMDS_DPC1_dummy1800d044_15_11_shift                           (11)
//--#define TMDS_DPC1_dpc_auto_shift                                      (10)
//--#define TMDS_DPC1_dpc_pp_valid_fw_shift                               (9)
//--#define TMDS_DPC1_dpc_default_ph_fw_shift                             (8)
//--#define TMDS_DPC1_dpc_pp_fw_shift                                     (4)
//--#define TMDS_DPC1_dpc_cd_fw_shift                                     (0)
//--#define TMDS_DPC1_dpc_cd_chg_flag_mask                                (0x00040000)
//--#define TMDS_DPC1_dpc_cd_chg_wd_en_mask                               (0x00020000)
//--#define TMDS_DPC1_dpc_cd_chg_int_en_mask                              (0x00010000)
//--#define TMDS_DPC1_dummy1800d044_15_11_mask                            (0x0000F800)
//--#define TMDS_DPC1_dpc_auto_mask                                       (0x00000400)
//--#define TMDS_DPC1_dpc_pp_valid_fw_mask                                (0x00000200)
//--#define TMDS_DPC1_dpc_default_ph_fw_mask                              (0x00000100)
//--#define TMDS_DPC1_dpc_pp_fw_mask                                      (0x000000F0)
//--#define TMDS_DPC1_dpc_cd_fw_mask                                      (0x0000000F)
//--#define TMDS_DPC1_dpc_cd_chg_flag(data)                               (0x00040000&((data)<<18))
//--#define TMDS_DPC1_dpc_cd_chg_wd_en(data)                              (0x00020000&((data)<<17))
//--#define TMDS_DPC1_dpc_cd_chg_int_en(data)                             (0x00010000&((data)<<16))
//--#define TMDS_DPC1_dummy1800d044_15_11(data)                           (0x0000F800&((data)<<11))
//--#define TMDS_DPC1_dpc_auto(data)                                      (0x00000400&((data)<<10))
//--#define TMDS_DPC1_dpc_pp_valid_fw(data)                               (0x00000200&((data)<<9))
//--#define TMDS_DPC1_dpc_default_ph_fw(data)                             (0x00000100&((data)<<8))
//--#define TMDS_DPC1_dpc_pp_fw(data)                                     (0x000000F0&((data)<<4))
//--#define TMDS_DPC1_dpc_cd_fw(data)                                     (0x0000000F&(data))
//--#define TMDS_DPC1_get_dpc_cd_chg_flag(data)                           ((0x00040000&(data))>>18)
//--#define TMDS_DPC1_get_dpc_cd_chg_wd_en(data)                          ((0x00020000&(data))>>17)
//--#define TMDS_DPC1_get_dpc_cd_chg_int_en(data)                         ((0x00010000&(data))>>16)
//--#define TMDS_DPC1_get_dummy1800d044_15_11(data)                       ((0x0000F800&(data))>>11)
//--#define TMDS_DPC1_get_dpc_auto(data)                                  ((0x00000400&(data))>>10)
//--#define TMDS_DPC1_get_dpc_pp_valid_fw(data)                           ((0x00000200&(data))>>9)
//--#define TMDS_DPC1_get_dpc_default_ph_fw(data)                         ((0x00000100&(data))>>8)
//--#define TMDS_DPC1_get_dpc_pp_fw(data)                                 ((0x000000F0&(data))>>4)
//--#define TMDS_DPC1_get_dpc_cd_fw(data)                                 (0x0000000F&(data))
//--
//--
//--#define TMDS_DPC_SET0                                                 0x1800d048
//--#define TMDS_DPC_SET0_reg_addr                                        "0xb800d048"
//--#define TMDS_DPC_SET0_reg                                             0xb800d048
//--#define TMDS_DPC_SET0_inst_addr                                       "0x0012"
//--#define TMDS_DPC_SET0_inst                                            0x0012
//--#define set_TMDS_DPC_SET0_reg(data)                                   (*((volatile unsigned int*)TMDS_DPC_SET0_reg)=data)
//--#define get_TMDS_DPC_SET0_reg                                         (*((volatile unsigned int*)TMDS_DPC_SET0_reg))
//--#define TMDS_DPC_SET0_dpc_bypass_dis_shift                            (8)
//--#define TMDS_DPC_SET0_dpc_en_shift                                    (7)
//--#define TMDS_DPC_SET0_phase_errcnt_in_shift                           (4)
//--#define TMDS_DPC_SET0_phase_clrcnt_in_shift                           (1)
//--#define TMDS_DPC_SET0_phase_clr_sel_shift                             (0)
//--#define TMDS_DPC_SET0_dpc_bypass_dis_mask                             (0x00000100)
//--#define TMDS_DPC_SET0_dpc_en_mask                                     (0x00000080)
//--#define TMDS_DPC_SET0_phase_errcnt_in_mask                            (0x00000070)
//--#define TMDS_DPC_SET0_phase_clrcnt_in_mask                            (0x0000000E)
//--#define TMDS_DPC_SET0_phase_clr_sel_mask                              (0x00000001)
//--#define TMDS_DPC_SET0_dpc_bypass_dis(data)                            (0x00000100&((data)<<8))
//--#define TMDS_DPC_SET0_dpc_en(data)                                    (0x00000080&((data)<<7))
//--#define TMDS_DPC_SET0_phase_errcnt_in(data)                           (0x00000070&((data)<<4))
//--#define TMDS_DPC_SET0_phase_clrcnt_in(data)                           (0x0000000E&((data)<<1))
//--#define TMDS_DPC_SET0_phase_clr_sel(data)                             (0x00000001&(data))
//--#define TMDS_DPC_SET0_get_dpc_bypass_dis(data)                        ((0x00000100&(data))>>8)
//--#define TMDS_DPC_SET0_get_dpc_en(data)                                ((0x00000080&(data))>>7)
//--#define TMDS_DPC_SET0_get_phase_errcnt_in(data)                       ((0x00000070&(data))>>4)
//--#define TMDS_DPC_SET0_get_phase_clrcnt_in(data)                       ((0x0000000E&(data))>>1)
//--#define TMDS_DPC_SET0_get_phase_clr_sel(data)                         (0x00000001&(data))
//--
//--
//--#define TMDS_DPC_SET1                                                 0x1800d04c
//--#define TMDS_DPC_SET1_reg_addr                                        "0xb800d04c"
//--#define TMDS_DPC_SET1_reg                                             0xb800d04c
//--#define TMDS_DPC_SET1_inst_addr                                       "0x0013"
//--#define TMDS_DPC_SET1_inst                                            0x0013
//--#define set_TMDS_DPC_SET1_reg(data)                                   (*((volatile unsigned int*)TMDS_DPC_SET1_reg)=data)
//--#define get_TMDS_DPC_SET1_reg                                         (*((volatile unsigned int*)TMDS_DPC_SET1_reg))
//--#define TMDS_DPC_SET1_set_full_noti_shift                             (4)
//--#define TMDS_DPC_SET1_set_empty_noti_shift                            (0)
//--#define TMDS_DPC_SET1_set_full_noti_mask                              (0x000000F0)
//--#define TMDS_DPC_SET1_set_empty_noti_mask                             (0x0000000F)
//--#define TMDS_DPC_SET1_set_full_noti(data)                             (0x000000F0&((data)<<4))
//--#define TMDS_DPC_SET1_set_empty_noti(data)                            (0x0000000F&(data))
//--#define TMDS_DPC_SET1_get_set_full_noti(data)                         ((0x000000F0&(data))>>4)
//--#define TMDS_DPC_SET1_get_set_empty_noti(data)                        (0x0000000F&(data))
//--
//--
//--#define TMDS_DPC_SET2                                                 0x1800d050
//--#define TMDS_DPC_SET2_reg_addr                                        "0xb800d050"
//--#define TMDS_DPC_SET2_reg                                             0xb800d050
//--#define TMDS_DPC_SET2_inst_addr                                       "0x0014"
//--#define TMDS_DPC_SET2_inst                                            0x0014
//--#define set_TMDS_DPC_SET2_reg(data)                                   (*((volatile unsigned int*)TMDS_DPC_SET2_reg)=data)
//--#define get_TMDS_DPC_SET2_reg                                         (*((volatile unsigned int*)TMDS_DPC_SET2_reg))
//--#define TMDS_DPC_SET2_fifo_errcnt_in_shift                            (5)
//--#define TMDS_DPC_SET2_clr_phase_flag_shift                            (4)
//--#define TMDS_DPC_SET2_clr_fifo_flag_shift                             (3)
//--#define TMDS_DPC_SET2_dpc_phase_ok_shift                              (2)
//--#define TMDS_DPC_SET2_dpc_phase_err_flag_shift                        (1)
//--#define TMDS_DPC_SET2_dpc_fifo_err_flag_shift                         (0)
//--#define TMDS_DPC_SET2_fifo_errcnt_in_mask                             (0x000000E0)
//--#define TMDS_DPC_SET2_clr_phase_flag_mask                             (0x00000010)
//--#define TMDS_DPC_SET2_clr_fifo_flag_mask                              (0x00000008)
//--#define TMDS_DPC_SET2_dpc_phase_ok_mask                               (0x00000004)
//--#define TMDS_DPC_SET2_dpc_phase_err_flag_mask                         (0x00000002)
//--#define TMDS_DPC_SET2_dpc_fifo_err_flag_mask                          (0x00000001)
//--#define TMDS_DPC_SET2_fifo_errcnt_in(data)                            (0x000000E0&((data)<<5))
//--#define TMDS_DPC_SET2_clr_phase_flag(data)                            (0x00000010&((data)<<4))
//--#define TMDS_DPC_SET2_clr_fifo_flag(data)                             (0x00000008&((data)<<3))
//--#define TMDS_DPC_SET2_dpc_phase_ok(data)                              (0x00000004&((data)<<2))
//--#define TMDS_DPC_SET2_dpc_phase_err_flag(data)                        (0x00000002&((data)<<1))
//--#define TMDS_DPC_SET2_dpc_fifo_err_flag(data)                         (0x00000001&(data))
//--#define TMDS_DPC_SET2_get_fifo_errcnt_in(data)                        ((0x000000E0&(data))>>5)
//--#define TMDS_DPC_SET2_get_clr_phase_flag(data)                        ((0x00000010&(data))>>4)
//--#define TMDS_DPC_SET2_get_clr_fifo_flag(data)                         ((0x00000008&(data))>>3)
//--#define TMDS_DPC_SET2_get_dpc_phase_ok(data)                          ((0x00000004&(data))>>2)
//--#define TMDS_DPC_SET2_get_dpc_phase_err_flag(data)                    ((0x00000002&(data))>>1)
//--#define TMDS_DPC_SET2_get_dpc_fifo_err_flag(data)                     (0x00000001&(data))
//--
//--
//--#define TMDS_DPC_SET3                                                 0x1800d054
//--#define TMDS_DPC_SET3_reg_addr                                        "0xb800d054"
//--#define TMDS_DPC_SET3_reg                                             0xb800d054
//--#define TMDS_DPC_SET3_inst_addr                                       "0x0015"
//--#define TMDS_DPC_SET3_inst                                            0x0015
//--#define set_TMDS_DPC_SET3_reg(data)                                   (*((volatile unsigned int*)TMDS_DPC_SET3_reg)=data)
//--#define get_TMDS_DPC_SET3_reg                                         (*((volatile unsigned int*)TMDS_DPC_SET3_reg))
//--#define TMDS_DPC_SET3_dpc_fifo_over_flag_shift                        (7)
//--#define TMDS_DPC_SET3_dpc_fifo_under_flag_shift                       (6)
//--#define TMDS_DPC_SET3_dpc_fifo_over_xflag_shift                       (5)
//--#define TMDS_DPC_SET3_dpc_fifo_under_xflag_shift                      (4)
//--#define TMDS_DPC_SET3_dpc_fifo_over_flag_mask                         (0x00000080)
//--#define TMDS_DPC_SET3_dpc_fifo_under_flag_mask                        (0x00000040)
//--#define TMDS_DPC_SET3_dpc_fifo_over_xflag_mask                        (0x00000020)
//--#define TMDS_DPC_SET3_dpc_fifo_under_xflag_mask                       (0x00000010)
//--#define TMDS_DPC_SET3_dpc_fifo_over_flag(data)                        (0x00000080&((data)<<7))
//--#define TMDS_DPC_SET3_dpc_fifo_under_flag(data)                       (0x00000040&((data)<<6))
//--#define TMDS_DPC_SET3_dpc_fifo_over_xflag(data)                       (0x00000020&((data)<<5))
//--#define TMDS_DPC_SET3_dpc_fifo_under_xflag(data)                      (0x00000010&((data)<<4))
//--#define TMDS_DPC_SET3_get_dpc_fifo_over_flag(data)                    ((0x00000080&(data))>>7)
//--#define TMDS_DPC_SET3_get_dpc_fifo_under_flag(data)                   ((0x00000040&(data))>>6)
//--#define TMDS_DPC_SET3_get_dpc_fifo_over_xflag(data)                   ((0x00000020&(data))>>5)
//--#define TMDS_DPC_SET3_get_dpc_fifo_under_xflag(data)                  ((0x00000010&(data))>>4)
//--
//--
//--#define TMDS_DET_CTL                                                  0x1800d058
//--#define TMDS_DET_CTL_reg_addr                                         "0xb800d058"
//--#define TMDS_DET_CTL_reg                                              0xb800d058
//--#define TMDS_DET_CTL_inst_addr                                        "0x0016"
//--#define TMDS_DET_CTL_inst                                             0x0016
//--#define set_TMDS_DET_CTL_reg(data)                                    (*((volatile unsigned int*)TMDS_DET_CTL_reg)=data)
//--#define get_TMDS_DET_CTL_reg                                          (*((volatile unsigned int*)TMDS_DET_CTL_reg))
//--#define TMDS_DET_CTL_de_sel_shift                                     (28)
//--#define TMDS_DET_CTL_tran_err_thrd_shift                              (24)
//--#define TMDS_DET_CTL_neg_de_err_thrd_shift                            (20)
//--#define TMDS_DET_CTL_pos_de_err_thrd_shift                            (16)
//--#define TMDS_DET_CTL_dummy1800d058_15_shift                           (15)
//--#define TMDS_DET_CTL_neg_de_lowbd_shift                               (8)
//--#define TMDS_DET_CTL_dummy1800d058_7_6_shift                          (6)
//--#define TMDS_DET_CTL_pos_de_lowbd_shift                               (0)
//--#define TMDS_DET_CTL_de_sel_mask                                      (0x10000000)
//--#define TMDS_DET_CTL_tran_err_thrd_mask                               (0x0F000000)
//--#define TMDS_DET_CTL_neg_de_err_thrd_mask                             (0x00F00000)
//--#define TMDS_DET_CTL_pos_de_err_thrd_mask                             (0x000F0000)
//--#define TMDS_DET_CTL_dummy1800d058_15_mask                            (0x00008000)
//--#define TMDS_DET_CTL_neg_de_lowbd_mask                                (0x00007F00)
//--#define TMDS_DET_CTL_dummy1800d058_7_6_mask                           (0x000000C0)
//--#define TMDS_DET_CTL_pos_de_lowbd_mask                                (0x0000003F)
//--#define TMDS_DET_CTL_de_sel(data)                                     (0x10000000&((data)<<28))
//--#define TMDS_DET_CTL_tran_err_thrd(data)                              (0x0F000000&((data)<<24))
//--#define TMDS_DET_CTL_neg_de_err_thrd(data)                            (0x00F00000&((data)<<20))
//--#define TMDS_DET_CTL_pos_de_err_thrd(data)                            (0x000F0000&((data)<<16))
//--#define TMDS_DET_CTL_dummy1800d058_15(data)                           (0x00008000&((data)<<15))
//--#define TMDS_DET_CTL_neg_de_lowbd(data)                               (0x00007F00&((data)<<8))
//--#define TMDS_DET_CTL_dummy1800d058_7_6(data)                          (0x000000C0&((data)<<6))
//--#define TMDS_DET_CTL_pos_de_lowbd(data)                               (0x0000003F&(data))
//--#define TMDS_DET_CTL_get_de_sel(data)                                 ((0x10000000&(data))>>28)
//--#define TMDS_DET_CTL_get_tran_err_thrd(data)                          ((0x0F000000&(data))>>24)
//--#define TMDS_DET_CTL_get_neg_de_err_thrd(data)                        ((0x00F00000&(data))>>20)
//--#define TMDS_DET_CTL_get_pos_de_err_thrd(data)                        ((0x000F0000&(data))>>16)
//--#define TMDS_DET_CTL_get_dummy1800d058_15(data)                       ((0x00008000&(data))>>15)
//--#define TMDS_DET_CTL_get_neg_de_lowbd(data)                           ((0x00007F00&(data))>>8)
//--#define TMDS_DET_CTL_get_dummy1800d058_7_6(data)                      ((0x000000C0&(data))>>6)
//--#define TMDS_DET_CTL_get_pos_de_lowbd(data)                           (0x0000003F&(data))
//--
//--
//--#define TMDS_DET_STS                                                  0x1800d05c
//--#define TMDS_DET_STS_reg_addr                                         "0xb800d05c"
//--#define TMDS_DET_STS_reg                                              0xb800d05c
//--#define TMDS_DET_STS_inst_addr                                        "0x0017"
//--#define TMDS_DET_STS_inst                                             0x0017
//--#define set_TMDS_DET_STS_reg(data)                                    (*((volatile unsigned int*)TMDS_DET_STS_reg)=data)
//--#define get_TMDS_DET_STS_reg                                          (*((volatile unsigned int*)TMDS_DET_STS_reg))
//--#define TMDS_DET_STS_red_tran_err_flag_shift                          (8)
//--#define TMDS_DET_STS_grn_tran_err_flag_shift                          (7)
//--#define TMDS_DET_STS_blu_tran_err_flag_shift                          (6)
//--#define TMDS_DET_STS_red_pos_de_err_flag_shift                        (5)
//--#define TMDS_DET_STS_grn_pos_de_err_flag_shift                        (4)
//--#define TMDS_DET_STS_blu_pos_de_err_flag_shift                        (3)
//--#define TMDS_DET_STS_red_neg_de_err_flag_shift                        (2)
//--#define TMDS_DET_STS_grn_neg_de_err_flag_shift                        (1)
//--#define TMDS_DET_STS_blu_neg_de_err_flag_shift                        (0)
//--#define TMDS_DET_STS_red_tran_err_flag_mask                           (0x00000100)
//--#define TMDS_DET_STS_grn_tran_err_flag_mask                           (0x00000080)
//--#define TMDS_DET_STS_blu_tran_err_flag_mask                           (0x00000040)
//--#define TMDS_DET_STS_red_pos_de_err_flag_mask                         (0x00000020)
//--#define TMDS_DET_STS_grn_pos_de_err_flag_mask                         (0x00000010)
//--#define TMDS_DET_STS_blu_pos_de_err_flag_mask                         (0x00000008)
//--#define TMDS_DET_STS_red_neg_de_err_flag_mask                         (0x00000004)
//--#define TMDS_DET_STS_grn_neg_de_err_flag_mask                         (0x00000002)
//--#define TMDS_DET_STS_blu_neg_de_err_flag_mask                         (0x00000001)
//--#define TMDS_DET_STS_red_tran_err_flag(data)                          (0x00000100&((data)<<8))
//--#define TMDS_DET_STS_grn_tran_err_flag(data)                          (0x00000080&((data)<<7))
//--#define TMDS_DET_STS_blu_tran_err_flag(data)                          (0x00000040&((data)<<6))
//--#define TMDS_DET_STS_red_pos_de_err_flag(data)                        (0x00000020&((data)<<5))
//--#define TMDS_DET_STS_grn_pos_de_err_flag(data)                        (0x00000010&((data)<<4))
//--#define TMDS_DET_STS_blu_pos_de_err_flag(data)                        (0x00000008&((data)<<3))
//--#define TMDS_DET_STS_red_neg_de_err_flag(data)                        (0x00000004&((data)<<2))
//--#define TMDS_DET_STS_grn_neg_de_err_flag(data)                        (0x00000002&((data)<<1))
//--#define TMDS_DET_STS_blu_neg_de_err_flag(data)                        (0x00000001&(data))
//--#define TMDS_DET_STS_get_red_tran_err_flag(data)                      ((0x00000100&(data))>>8)
//--#define TMDS_DET_STS_get_grn_tran_err_flag(data)                      ((0x00000080&(data))>>7)
//--#define TMDS_DET_STS_get_blu_tran_err_flag(data)                      ((0x00000040&(data))>>6)
//--#define TMDS_DET_STS_get_red_pos_de_err_flag(data)                    ((0x00000020&(data))>>5)
//--#define TMDS_DET_STS_get_grn_pos_de_err_flag(data)                    ((0x00000010&(data))>>4)
//--#define TMDS_DET_STS_get_blu_pos_de_err_flag(data)                    ((0x00000008&(data))>>3)
//--#define TMDS_DET_STS_get_red_neg_de_err_flag(data)                    ((0x00000004&(data))>>2)
//--#define TMDS_DET_STS_get_grn_neg_de_err_flag(data)                    ((0x00000002&(data))>>1)
//--#define TMDS_DET_STS_get_blu_neg_de_err_flag(data)                    (0x00000001&(data))
//--
//--
//--#define VIDEO_BIT_ERR_DET                                             0x1800d060
//--#define VIDEO_BIT_ERR_DET_reg_addr                                    "0xb800d060"
//--#define VIDEO_BIT_ERR_DET_reg                                         0xb800d060
//--#define VIDEO_BIT_ERR_DET_inst_addr                                   "0x0018"
//--#define VIDEO_BIT_ERR_DET_inst                                        0x0018
//--#define set_VIDEO_BIT_ERR_DET_reg(data)                               (*((volatile unsigned int*)VIDEO_BIT_ERR_DET_reg)=data)
//--#define get_VIDEO_BIT_ERR_DET_reg                                     (*((volatile unsigned int*)VIDEO_BIT_ERR_DET_reg))
//--#define VIDEO_BIT_ERR_DET_thd_shift                                   (16)
//--#define VIDEO_BIT_ERR_DET_irq_en_shift                                (11)
//--#define VIDEO_BIT_ERR_DET_reset_shift                                 (10)
//--#define VIDEO_BIT_ERR_DET_period_shift                                (4)
//--#define VIDEO_BIT_ERR_DET_ch_sel_shift                                (2)
//--#define VIDEO_BIT_ERR_DET_mode_shift                                  (1)
//--#define VIDEO_BIT_ERR_DET_en_shift                                    (0)
//--#define VIDEO_BIT_ERR_DET_thd_mask                                    (0xFFFF0000)
//--#define VIDEO_BIT_ERR_DET_irq_en_mask                                 (0x00000800)
//--#define VIDEO_BIT_ERR_DET_reset_mask                                  (0x00000400)
//--#define VIDEO_BIT_ERR_DET_period_mask                                 (0x000003F0)
//--#define VIDEO_BIT_ERR_DET_ch_sel_mask                                 (0x0000000C)
//--#define VIDEO_BIT_ERR_DET_mode_mask                                   (0x00000002)
//--#define VIDEO_BIT_ERR_DET_en_mask                                     (0x00000001)
//--#define VIDEO_BIT_ERR_DET_thd(data)                                   (0xFFFF0000&((data)<<16))
//--#define VIDEO_BIT_ERR_DET_irq_en(data)                                (0x00000800&((data)<<11))
//--#define VIDEO_BIT_ERR_DET_reset(data)                                 (0x00000400&((data)<<10))
//--#define VIDEO_BIT_ERR_DET_period(data)                                (0x000003F0&((data)<<4))
//--#define VIDEO_BIT_ERR_DET_ch_sel(data)                                (0x0000000C&((data)<<2))
//--#define VIDEO_BIT_ERR_DET_mode(data)                                  (0x00000002&((data)<<1))
//--#define VIDEO_BIT_ERR_DET_en(data)                                    (0x00000001&(data))
//--#define VIDEO_BIT_ERR_DET_get_thd(data)                               ((0xFFFF0000&(data))>>16)
//--#define VIDEO_BIT_ERR_DET_get_irq_en(data)                            ((0x00000800&(data))>>11)
//--#define VIDEO_BIT_ERR_DET_get_reset(data)                             ((0x00000400&(data))>>10)
//--#define VIDEO_BIT_ERR_DET_get_period(data)                            ((0x000003F0&(data))>>4)
//--#define VIDEO_BIT_ERR_DET_get_ch_sel(data)                            ((0x0000000C&(data))>>2)
//--#define VIDEO_BIT_ERR_DET_get_mode(data)                              ((0x00000002&(data))>>1)
//--#define VIDEO_BIT_ERR_DET_get_en(data)                                (0x00000001&(data))
//--
//--
//--#define VIDEO_BIT_ERR_STATUS                                          0x1800d064
//--#define VIDEO_BIT_ERR_STATUS_reg_addr                                 "0xb800d064"
//--#define VIDEO_BIT_ERR_STATUS_reg                                      0xb800d064
//--#define VIDEO_BIT_ERR_STATUS_inst_addr                                "0x0019"
//--#define VIDEO_BIT_ERR_STATUS_inst                                     0x0019
//--#define set_VIDEO_BIT_ERR_STATUS_reg(data)                            (*((volatile unsigned int*)VIDEO_BIT_ERR_STATUS_reg)=data)
//--#define get_VIDEO_BIT_ERR_STATUS_reg                                  (*((volatile unsigned int*)VIDEO_BIT_ERR_STATUS_reg))
//--#define VIDEO_BIT_ERR_STATUS_ad_max_shift                             (25)
//--#define VIDEO_BIT_ERR_STATUS_ad_min_shift                             (20)
//--#define VIDEO_BIT_ERR_STATUS_no_dis_reset_shift                       (19)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_thd_shift                        (18)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_shift                            (17)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt_of_shift                     (16)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt_shift                        (0)
//--#define VIDEO_BIT_ERR_STATUS_ad_max_mask                              (0x3E000000)
//--#define VIDEO_BIT_ERR_STATUS_ad_min_mask                              (0x01F00000)
//--#define VIDEO_BIT_ERR_STATUS_no_dis_reset_mask                        (0x00080000)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_thd_mask                         (0x00040000)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_mask                             (0x00020000)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt_of_mask                      (0x00010000)
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt_mask                         (0x0000FFFF)
//--#define VIDEO_BIT_ERR_STATUS_ad_max(data)                             (0x3E000000&((data)<<25))
//--#define VIDEO_BIT_ERR_STATUS_ad_min(data)                             (0x01F00000&((data)<<20))
//--#define VIDEO_BIT_ERR_STATUS_no_dis_reset(data)                       (0x00080000&((data)<<19))
//--#define VIDEO_BIT_ERR_STATUS_bit_err_thd(data)                        (0x00040000&((data)<<18))
//--#define VIDEO_BIT_ERR_STATUS_bit_err(data)                            (0x00020000&((data)<<17))
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt_of(data)                     (0x00010000&((data)<<16))
//--#define VIDEO_BIT_ERR_STATUS_bit_err_cnt(data)                        (0x0000FFFF&(data))
//--#define VIDEO_BIT_ERR_STATUS_get_ad_max(data)                         ((0x3E000000&(data))>>25)
//--#define VIDEO_BIT_ERR_STATUS_get_ad_min(data)                         ((0x01F00000&(data))>>20)
//--#define VIDEO_BIT_ERR_STATUS_get_no_dis_reset(data)                   ((0x00080000&(data))>>19)
//--#define VIDEO_BIT_ERR_STATUS_get_bit_err_thd(data)                    ((0x00040000&(data))>>18)
//--#define VIDEO_BIT_ERR_STATUS_get_bit_err(data)                        ((0x00020000&(data))>>17)
//--#define VIDEO_BIT_ERR_STATUS_get_bit_err_cnt_of(data)                 ((0x00010000&(data))>>16)
//--#define VIDEO_BIT_ERR_STATUS_get_bit_err_cnt(data)                    (0x0000FFFF&(data))
//--
//--
//--#define CH_CR                                                         0x1800d068
//--#define CH_CR_reg_addr                                                "0xb800d068"
//--#define CH_CR_reg                                                     0xb800d068
//--#define CH_CR_inst_addr                                               "0x001A"
//--#define CH_CR_inst                                                    0x001A
//--#define set_CH_CR_reg(data)                                           (*((volatile unsigned int*)CH_CR_reg)=data)
//--#define get_CH_CR_reg                                                 (*((volatile unsigned int*)CH_CR_reg))
//--#define CH_CR_rsel_shift                                              (22)
//--#define CH_CR_gsel_shift                                              (21)
//--#define CH_CR_bsel_shift                                              (20)
//--#define CH_CR_dummy1800d068_19_17_shift                               (17)
//--#define CH_CR_rden_thr_shift                                          (12)
//--#define CH_CR_dummy1800d068_11_9_shift                                (9)
//--#define CH_CR_udwater_thr_shift                                       (4)
//--#define CH_CR_dummy1800d068_3_2_shift                                 (2)
//--#define CH_CR_flush_shift                                             (1)
//--#define CH_CR_flag_clear_shift                                        (0)
//--#define CH_CR_rsel_mask                                               (0x00400000)
//--#define CH_CR_gsel_mask                                               (0x00200000)
//--#define CH_CR_bsel_mask                                               (0x00100000)
//--#define CH_CR_dummy1800d068_19_17_mask                                (0x000E0000)
//--#define CH_CR_rden_thr_mask                                           (0x0001F000)
//--#define CH_CR_dummy1800d068_11_9_mask                                 (0x00000E00)
//--#define CH_CR_udwater_thr_mask                                        (0x000001F0)
//--#define CH_CR_dummy1800d068_3_2_mask                                  (0x0000000C)
//--#define CH_CR_flush_mask                                              (0x00000002)
//--#define CH_CR_flag_clear_mask                                         (0x00000001)
//--#define CH_CR_rsel(data)                                              (0x00400000&((data)<<22))
//--#define CH_CR_gsel(data)                                              (0x00200000&((data)<<21))
//--#define CH_CR_bsel(data)                                              (0x00100000&((data)<<20))
//--#define CH_CR_dummy1800d068_19_17(data)                               (0x000E0000&((data)<<17))
//--#define CH_CR_rden_thr(data)                                          (0x0001F000&((data)<<12))
//--#define CH_CR_dummy1800d068_11_9(data)                                (0x00000E00&((data)<<9))
//--#define CH_CR_udwater_thr(data)                                       (0x000001F0&((data)<<4))
//--#define CH_CR_dummy1800d068_3_2(data)                                 (0x0000000C&((data)<<2))
//--#define CH_CR_flush(data)                                             (0x00000002&((data)<<1))
//--#define CH_CR_flag_clear(data)                                        (0x00000001&(data))
//--#define CH_CR_get_rsel(data)                                          ((0x00400000&(data))>>22)
//--#define CH_CR_get_gsel(data)                                          ((0x00200000&(data))>>21)
//--#define CH_CR_get_bsel(data)                                          ((0x00100000&(data))>>20)
//--#define CH_CR_get_dummy1800d068_19_17(data)                           ((0x000E0000&(data))>>17)
//--#define CH_CR_get_rden_thr(data)                                      ((0x0001F000&(data))>>12)
//--#define CH_CR_get_dummy1800d068_11_9(data)                            ((0x00000E00&(data))>>9)
//--#define CH_CR_get_udwater_thr(data)                                   ((0x000001F0&(data))>>4)
//--#define CH_CR_get_dummy1800d068_3_2(data)                             ((0x0000000C&(data))>>2)
//--#define CH_CR_get_flush(data)                                         ((0x00000002&(data))>>1)
//--#define CH_CR_get_flag_clear(data)                                    (0x00000001&(data))
//--
//--
//--#define CH_SR                                                         0x1800d06c
//--#define CH_SR_reg_addr                                                "0xb800d06c"
//--#define CH_SR_reg                                                     0xb800d06c
//--#define CH_SR_inst_addr                                               "0x001B"
//--#define CH_SR_inst                                                    0x001B
//--#define set_CH_SR_reg(data)                                           (*((volatile unsigned int*)CH_SR_reg)=data)
//--#define get_CH_SR_reg                                                 (*((volatile unsigned int*)CH_SR_reg))
//--#define CH_SR_r_rwclk_det_timeout_flag_shift                          (29)
//--#define CH_SR_r_wrclk_det_timeout_flag_shift                          (28)
//--#define CH_SR_g_rwclk_det_timeout_flag_shift                          (27)
//--#define CH_SR_g_wrclk_det_timeout_flag_shift                          (26)
//--#define CH_SR_b_rwclk_det_timeout_flag_shift                          (25)
//--#define CH_SR_b_wrclk_det_timeout_flag_shift                          (24)
//--#define CH_SR_r_rudflow_flag_shift                                    (23)
//--#define CH_SR_r_wovflow_flag_shift                                    (22)
//--#define CH_SR_r_rflush_flag_shift                                     (21)
//--#define CH_SR_r_rw_water_lv_shift                                     (16)
//--#define CH_SR_g_rudflow_flag_shift                                    (15)
//--#define CH_SR_g_wovflow_flag_shift                                    (14)
//--#define CH_SR_g_rflush_flag_shift                                     (13)
//--#define CH_SR_g_rw_water_lv_shift                                     (8)
//--#define CH_SR_b_rudflow_flag_shift                                    (7)
//--#define CH_SR_b_wovflow_flag_shift                                    (6)
//--#define CH_SR_b_rflush_flag_shift                                     (5)
//--#define CH_SR_b_rw_water_lv_shift                                     (0)
//--#define CH_SR_r_rwclk_det_timeout_flag_mask                           (0x20000000)
//--#define CH_SR_r_wrclk_det_timeout_flag_mask                           (0x10000000)
//--#define CH_SR_g_rwclk_det_timeout_flag_mask                           (0x08000000)
//--#define CH_SR_g_wrclk_det_timeout_flag_mask                           (0x04000000)
//--#define CH_SR_b_rwclk_det_timeout_flag_mask                           (0x02000000)
//--#define CH_SR_b_wrclk_det_timeout_flag_mask                           (0x01000000)
//--#define CH_SR_r_rudflow_flag_mask                                     (0x00800000)
//--#define CH_SR_r_wovflow_flag_mask                                     (0x00400000)
//--#define CH_SR_r_rflush_flag_mask                                      (0x00200000)
//--#define CH_SR_r_rw_water_lv_mask                                      (0x001F0000)
//--#define CH_SR_g_rudflow_flag_mask                                     (0x00008000)
//--#define CH_SR_g_wovflow_flag_mask                                     (0x00004000)
//--#define CH_SR_g_rflush_flag_mask                                      (0x00002000)
//--#define CH_SR_g_rw_water_lv_mask                                      (0x00001F00)
//--#define CH_SR_b_rudflow_flag_mask                                     (0x00000080)
//--#define CH_SR_b_wovflow_flag_mask                                     (0x00000040)
//--#define CH_SR_b_rflush_flag_mask                                      (0x00000020)
//--#define CH_SR_b_rw_water_lv_mask                                      (0x0000001F)
//--#define CH_SR_r_rwclk_det_timeout_flag(data)                          (0x20000000&((data)<<29))
//--#define CH_SR_r_wrclk_det_timeout_flag(data)                          (0x10000000&((data)<<28))
//--#define CH_SR_g_rwclk_det_timeout_flag(data)                          (0x08000000&((data)<<27))
//--#define CH_SR_g_wrclk_det_timeout_flag(data)                          (0x04000000&((data)<<26))
//--#define CH_SR_b_rwclk_det_timeout_flag(data)                          (0x02000000&((data)<<25))
//--#define CH_SR_b_wrclk_det_timeout_flag(data)                          (0x01000000&((data)<<24))
//--#define CH_SR_r_rudflow_flag(data)                                    (0x00800000&((data)<<23))
//--#define CH_SR_r_wovflow_flag(data)                                    (0x00400000&((data)<<22))
//--#define CH_SR_r_rflush_flag(data)                                     (0x00200000&((data)<<21))
//--#define CH_SR_r_rw_water_lv(data)                                     (0x001F0000&((data)<<16))
//--#define CH_SR_g_rudflow_flag(data)                                    (0x00008000&((data)<<15))
//--#define CH_SR_g_wovflow_flag(data)                                    (0x00004000&((data)<<14))
//--#define CH_SR_g_rflush_flag(data)                                     (0x00002000&((data)<<13))
//--#define CH_SR_g_rw_water_lv(data)                                     (0x00001F00&((data)<<8))
//--#define CH_SR_b_rudflow_flag(data)                                    (0x00000080&((data)<<7))
//--#define CH_SR_b_wovflow_flag(data)                                    (0x00000040&((data)<<6))
//--#define CH_SR_b_rflush_flag(data)                                     (0x00000020&((data)<<5))
//--#define CH_SR_b_rw_water_lv(data)                                     (0x0000001F&(data))
//--#define CH_SR_get_r_rwclk_det_timeout_flag(data)                      ((0x20000000&(data))>>29)
//--#define CH_SR_get_r_wrclk_det_timeout_flag(data)                      ((0x10000000&(data))>>28)
//--#define CH_SR_get_g_rwclk_det_timeout_flag(data)                      ((0x08000000&(data))>>27)
//--#define CH_SR_get_g_wrclk_det_timeout_flag(data)                      ((0x04000000&(data))>>26)
//--#define CH_SR_get_b_rwclk_det_timeout_flag(data)                      ((0x02000000&(data))>>25)
//--#define CH_SR_get_b_wrclk_det_timeout_flag(data)                      ((0x01000000&(data))>>24)
//--#define CH_SR_get_r_rudflow_flag(data)                                ((0x00800000&(data))>>23)
//--#define CH_SR_get_r_wovflow_flag(data)                                ((0x00400000&(data))>>22)
//--#define CH_SR_get_r_rflush_flag(data)                                 ((0x00200000&(data))>>21)
//--#define CH_SR_get_r_rw_water_lv(data)                                 ((0x001F0000&(data))>>16)
//--#define CH_SR_get_g_rudflow_flag(data)                                ((0x00008000&(data))>>15)
//--#define CH_SR_get_g_wovflow_flag(data)                                ((0x00004000&(data))>>14)
//--#define CH_SR_get_g_rflush_flag(data)                                 ((0x00002000&(data))>>13)
//--#define CH_SR_get_g_rw_water_lv(data)                                 ((0x00001F00&(data))>>8)
//--#define CH_SR_get_b_rudflow_flag(data)                                ((0x00000080&(data))>>7)
//--#define CH_SR_get_b_wovflow_flag(data)                                ((0x00000040&(data))>>6)
//--#define CH_SR_get_b_rflush_flag(data)                                 ((0x00000020&(data))>>5)
//--#define CH_SR_get_b_rw_water_lv(data)                                 (0x0000001F&(data))
//--
//--
//--#define HDMI_SR                                                       0x1800d080
//--#define HDMI_SR_reg_addr                                              "0xb800d080"
//--#define HDMI_SR_reg                                                   0xb800d080
//--#define HDMI_SR_inst_addr                                             "0x0020"
//--#define HDMI_SR_inst                                                  0x0020
//--#define set_HDMI_SR_reg(data)                                         (*((volatile unsigned int*)HDMI_SR_reg)=data)
//--#define get_HDMI_SR_reg                                               (*((volatile unsigned int*)HDMI_SR_reg))
//--#define HDMI_SR_avmute_bg_shift                                       (7)
//--#define HDMI_SR_avmute_shift                                          (6)
//--#define HDMI_SR_vic_shift                                             (5)
//--#define HDMI_SR_spdiftype_shift                                       (4)
//--#define HDMI_SR_pllsts_shift                                          (3)
//--#define HDMI_SR_afifoof_shift                                         (2)
//--#define HDMI_SR_afifouf_shift                                         (1)
//--#define HDMI_SR_mode_shift                                            (0)
//--#define HDMI_SR_avmute_bg_mask                                        (0x00000080)
//--#define HDMI_SR_avmute_mask                                           (0x00000040)
//--#define HDMI_SR_vic_mask                                              (0x00000020)
//--#define HDMI_SR_spdiftype_mask                                        (0x00000010)
//--#define HDMI_SR_pllsts_mask                                           (0x00000008)
//--#define HDMI_SR_afifoof_mask                                          (0x00000004)
//--#define HDMI_SR_afifouf_mask                                          (0x00000002)
//--#define HDMI_SR_mode_mask                                             (0x00000001)
//--#define HDMI_SR_avmute_bg(data)                                       (0x00000080&((data)<<7))
//--#define HDMI_SR_avmute(data)                                          (0x00000040&((data)<<6))
//--#define HDMI_SR_vic(data)                                             (0x00000020&((data)<<5))
//--#define HDMI_SR_spdiftype(data)                                       (0x00000010&((data)<<4))
//--#define HDMI_SR_pllsts(data)                                          (0x00000008&((data)<<3))
//--#define HDMI_SR_afifoof(data)                                         (0x00000004&((data)<<2))
//--#define HDMI_SR_afifouf(data)                                         (0x00000002&((data)<<1))
//--#define HDMI_SR_mode(data)                                            (0x00000001&(data))
//--#define HDMI_SR_get_avmute_bg(data)                                   ((0x00000080&(data))>>7)
//--#define HDMI_SR_get_avmute(data)                                      ((0x00000040&(data))>>6)
//--#define HDMI_SR_get_vic(data)                                         ((0x00000020&(data))>>5)
//--#define HDMI_SR_get_spdiftype(data)                                   ((0x00000010&(data))>>4)
//--#define HDMI_SR_get_pllsts(data)                                      ((0x00000008&(data))>>3)
//--#define HDMI_SR_get_afifoof(data)                                     ((0x00000004&(data))>>2)
//--#define HDMI_SR_get_afifouf(data)                                     ((0x00000002&(data))>>1)
//--#define HDMI_SR_get_mode(data)                                        (0x00000001&(data))
//--
//--
//--#define HDMI_GPVS                                                     0x1800d084
//--#define HDMI_GPVS_reg_addr                                            "0xb800d084"
//--#define HDMI_GPVS_reg                                                 0xb800d084
//--#define HDMI_GPVS_inst_addr                                           "0x0021"
//--#define HDMI_GPVS_inst                                                0x0021
//--#define set_HDMI_GPVS_reg(data)                                       (*((volatile unsigned int*)HDMI_GPVS_reg)=data)
//--#define get_HDMI_GPVS_reg                                             (*((volatile unsigned int*)HDMI_GPVS_reg))
//--#define HDMI_GPVS_gmps_v_shift                                        (13)
//--#define HDMI_GPVS_vsps_v_shift                                        (12)
//--#define HDMI_GPVS_gmps_shift                                          (11)
//--#define HDMI_GPVS_vsps_shift                                          (10)
//--#define HDMI_GPVS_nps_shift                                           (9)
//--#define HDMI_GPVS_dummy1800d084_8_shift                               (8)
//--#define HDMI_GPVS_dummy1800d084_7_shift                               (7)
//--#define HDMI_GPVS_pis_6_shift                                         (6)
//--#define HDMI_GPVS_pis_5_shift                                         (5)
//--#define HDMI_GPVS_pvs_4_shift                                         (4)
//--#define HDMI_GPVS_pvs_3_shift                                         (3)
//--#define HDMI_GPVS_pvs_2_shift                                         (2)
//--#define HDMI_GPVS_pvs_1_shift                                         (1)
//--#define HDMI_GPVS_pvs_0_shift                                         (0)
//--#define HDMI_GPVS_gmps_v_mask                                         (0x00002000)
//--#define HDMI_GPVS_vsps_v_mask                                         (0x00001000)
//--#define HDMI_GPVS_gmps_mask                                           (0x00000800)
//--#define HDMI_GPVS_vsps_mask                                           (0x00000400)
//--#define HDMI_GPVS_nps_mask                                            (0x00000200)
//--#define HDMI_GPVS_dummy1800d084_8_mask                                (0x00000100)
//--#define HDMI_GPVS_dummy1800d084_7_mask                                (0x00000080)
//--#define HDMI_GPVS_pis_6_mask                                          (0x00000040)
//--#define HDMI_GPVS_pis_5_mask                                          (0x00000020)
//--#define HDMI_GPVS_pvs_4_mask                                          (0x00000010)
//--#define HDMI_GPVS_pvs_3_mask                                          (0x00000008)
//--#define HDMI_GPVS_pvs_2_mask                                          (0x00000004)
//--#define HDMI_GPVS_pvs_1_mask                                          (0x00000002)
//--#define HDMI_GPVS_pvs_0_mask                                          (0x00000001)
//--#define HDMI_GPVS_gmps_v(data)                                        (0x00002000&((data)<<13))
//--#define HDMI_GPVS_vsps_v(data)                                        (0x00001000&((data)<<12))
//--#define HDMI_GPVS_gmps(data)                                          (0x00000800&((data)<<11))
//--#define HDMI_GPVS_vsps(data)                                          (0x00000400&((data)<<10))
//--#define HDMI_GPVS_nps(data)                                           (0x00000200&((data)<<9))
//--#define HDMI_GPVS_dummy1800d084_8(data)                               (0x00000100&((data)<<8))
//--#define HDMI_GPVS_dummy1800d084_7(data)                               (0x00000080&((data)<<7))
//--#define HDMI_GPVS_pis_6(data)                                         (0x00000040&((data)<<6))
//--#define HDMI_GPVS_pis_5(data)                                         (0x00000020&((data)<<5))
//--#define HDMI_GPVS_pvs_4(data)                                         (0x00000010&((data)<<4))
//--#define HDMI_GPVS_pvs_3(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_GPVS_pvs_2(data)                                         (0x00000004&((data)<<2))
//--#define HDMI_GPVS_pvs_1(data)                                         (0x00000002&((data)<<1))
//--#define HDMI_GPVS_pvs_0(data)                                         (0x00000001&(data))
//--#define HDMI_GPVS_get_gmps_v(data)                                    ((0x00002000&(data))>>13)
//--#define HDMI_GPVS_get_vsps_v(data)                                    ((0x00001000&(data))>>12)
//--#define HDMI_GPVS_get_gmps(data)                                      ((0x00000800&(data))>>11)
//--#define HDMI_GPVS_get_vsps(data)                                      ((0x00000400&(data))>>10)
//--#define HDMI_GPVS_get_nps(data)                                       ((0x00000200&(data))>>9)
//--#define HDMI_GPVS_get_dummy1800d084_8(data)                           ((0x00000100&(data))>>8)
//--#define HDMI_GPVS_get_dummy1800d084_7(data)                           ((0x00000080&(data))>>7)
//--#define HDMI_GPVS_get_pis_6(data)                                     ((0x00000040&(data))>>6)
//--#define HDMI_GPVS_get_pis_5(data)                                     ((0x00000020&(data))>>5)
//--#define HDMI_GPVS_get_pvs_4(data)                                     ((0x00000010&(data))>>4)
//--#define HDMI_GPVS_get_pvs_3(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_GPVS_get_pvs_2(data)                                     ((0x00000004&(data))>>2)
//--#define HDMI_GPVS_get_pvs_1(data)                                     ((0x00000002&(data))>>1)
//--#define HDMI_GPVS_get_pvs_0(data)                                     (0x00000001&(data))
//--
//--
//--#define HDMI_PSAP                                                     0x1800d088
//--#define HDMI_PSAP_reg_addr                                            "0xb800d088"
//--#define HDMI_PSAP_reg                                                 0xb800d088
//--#define HDMI_PSAP_inst_addr                                           "0x0022"
//--#define HDMI_PSAP_inst                                                0x0022
//--#define set_HDMI_PSAP_reg(data)                                       (*((volatile unsigned int*)HDMI_PSAP_reg)=data)
//--#define get_HDMI_PSAP_reg                                             (*((volatile unsigned int*)HDMI_PSAP_reg))
//--#define HDMI_PSAP_apss_shift                                          (0)
//--#define HDMI_PSAP_apss_mask                                           (0x000000FF)
//--#define HDMI_PSAP_apss(data)                                          (0x000000FF&(data))
//--#define HDMI_PSAP_get_apss(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_PSDP                                                     0x1800d08c
//--#define HDMI_PSDP_reg_addr                                            "0xb800d08c"
//--#define HDMI_PSDP_reg                                                 0xb800d08c
//--#define HDMI_PSDP_inst_addr                                           "0x0023"
//--#define HDMI_PSDP_inst                                                0x0023
//--#define set_HDMI_PSDP_reg(data)                                       (*((volatile unsigned int*)HDMI_PSDP_reg)=data)
//--#define get_HDMI_PSDP_reg                                             (*((volatile unsigned int*)HDMI_PSDP_reg))
//--#define HDMI_PSDP_dpss_shift                                          (0)
//--#define HDMI_PSDP_dpss_mask                                           (0x000000FF)
//--#define HDMI_PSDP_dpss(data)                                          (0x000000FF&(data))
//--#define HDMI_PSDP_get_dpss(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_SCR                                                      0x1800d090
//--#define HDMI_SCR_reg_addr                                             "0xb800d090"
//--#define HDMI_SCR_reg                                                  0xb800d090
//--#define HDMI_SCR_inst_addr                                            "0x0024"
//--#define HDMI_SCR_inst                                                 0x0024
//--#define set_HDMI_SCR_reg(data)                                        (*((volatile unsigned int*)HDMI_SCR_reg)=data)
//--#define get_HDMI_SCR_reg                                              (*((volatile unsigned int*)HDMI_SCR_reg))
//--#define HDMI_SCR_nval_shift                                           (8)
//--#define HDMI_SCR_dvi_reset_ds_cm_en_shift                             (5)
//--#define HDMI_SCR_packet_ignore_shift                                  (4)
//--#define HDMI_SCR_mode_shift                                           (3)
//--#define HDMI_SCR_msmode_shift                                         (2)
//--#define HDMI_SCR_cabs_shift                                           (1)
//--#define HDMI_SCR_fcddip_shift                                         (0)
//--#define HDMI_SCR_nval_mask                                            (0x0000FF00)
//--#define HDMI_SCR_dvi_reset_ds_cm_en_mask                              (0x00000020)
//--#define HDMI_SCR_packet_ignore_mask                                   (0x00000010)
//--#define HDMI_SCR_mode_mask                                            (0x00000008)
//--#define HDMI_SCR_msmode_mask                                          (0x00000004)
//--#define HDMI_SCR_cabs_mask                                            (0x00000002)
//--#define HDMI_SCR_fcddip_mask                                          (0x00000001)
//--#define HDMI_SCR_nval(data)                                           (0x0000FF00&((data)<<8))
//--#define HDMI_SCR_dvi_reset_ds_cm_en(data)                             (0x00000020&((data)<<5))
//--#define HDMI_SCR_packet_ignore(data)                                  (0x00000010&((data)<<4))
//--#define HDMI_SCR_mode(data)                                           (0x00000008&((data)<<3))
//--#define HDMI_SCR_msmode(data)                                         (0x00000004&((data)<<2))
//--#define HDMI_SCR_cabs(data)                                           (0x00000002&((data)<<1))
//--#define HDMI_SCR_fcddip(data)                                         (0x00000001&(data))
//--#define HDMI_SCR_get_nval(data)                                       ((0x0000FF00&(data))>>8)
//--#define HDMI_SCR_get_dvi_reset_ds_cm_en(data)                         ((0x00000020&(data))>>5)
//--#define HDMI_SCR_get_packet_ignore(data)                              ((0x00000010&(data))>>4)
//--#define HDMI_SCR_get_mode(data)                                       ((0x00000008&(data))>>3)
//--#define HDMI_SCR_get_msmode(data)                                     ((0x00000004&(data))>>2)
//--#define HDMI_SCR_get_cabs(data)                                       ((0x00000002&(data))>>1)
//--#define HDMI_SCR_get_fcddip(data)                                     (0x00000001&(data))
//--
//--
//--#define HDMI_BCHCR                                                    0x1800d094
//--#define HDMI_BCHCR_reg_addr                                           "0xb800d094"
//--#define HDMI_BCHCR_reg                                                0xb800d094
//--#define HDMI_BCHCR_inst_addr                                          "0x0025"
//--#define HDMI_BCHCR_inst                                               0x0025
//--#define set_HDMI_BCHCR_reg(data)                                      (*((volatile unsigned int*)HDMI_BCHCR_reg)=data)
//--#define get_HDMI_BCHCR_reg                                            (*((volatile unsigned int*)HDMI_BCHCR_reg))
//--#define HDMI_BCHCR_spcss_shift                                        (5)
//--#define HDMI_BCHCR_enrwe_shift                                        (4)
//--#define HDMI_BCHCR_bche_shift                                         (3)
//--#define HDMI_BCHCR_bches_shift                                        (2)
//--#define HDMI_BCHCR_bches2_shift                                       (1)
//--#define HDMI_BCHCR_pe_shift                                           (0)
//--#define HDMI_BCHCR_spcss_mask                                         (0x00000020)
//--#define HDMI_BCHCR_enrwe_mask                                         (0x00000010)
//--#define HDMI_BCHCR_bche_mask                                          (0x00000008)
//--#define HDMI_BCHCR_bches_mask                                         (0x00000004)
//--#define HDMI_BCHCR_bches2_mask                                        (0x00000002)
//--#define HDMI_BCHCR_pe_mask                                            (0x00000001)
//--#define HDMI_BCHCR_spcss(data)                                        (0x00000020&((data)<<5))
//--#define HDMI_BCHCR_enrwe(data)                                        (0x00000010&((data)<<4))
//--#define HDMI_BCHCR_bche(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_BCHCR_bches(data)                                        (0x00000004&((data)<<2))
//--#define HDMI_BCHCR_bches2(data)                                       (0x00000002&((data)<<1))
//--#define HDMI_BCHCR_pe(data)                                           (0x00000001&(data))
//--#define HDMI_BCHCR_get_spcss(data)                                    ((0x00000020&(data))>>5)
//--#define HDMI_BCHCR_get_enrwe(data)                                    ((0x00000010&(data))>>4)
//--#define HDMI_BCHCR_get_bche(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_BCHCR_get_bches(data)                                    ((0x00000004&(data))>>2)
//--#define HDMI_BCHCR_get_bches2(data)                                   ((0x00000002&(data))>>1)
//--#define HDMI_BCHCR_get_pe(data)                                       (0x00000001&(data))
//--
//--
//--#define HDMI_AVMCR                                                    0x1800d098
//--#define HDMI_AVMCR_reg_addr                                           "0xb800d098"
//--#define HDMI_AVMCR_reg                                                0xb800d098
//--#define HDMI_AVMCR_inst_addr                                          "0x0026"
//--#define HDMI_AVMCR_inst                                               0x0026
//--#define set_HDMI_AVMCR_reg(data)                                      (*((volatile unsigned int*)HDMI_AVMCR_reg)=data)
//--#define get_HDMI_AVMCR_reg                                            (*((volatile unsigned int*)HDMI_AVMCR_reg))
//--#define HDMI_AVMCR_wd_ptg_en_shift                                    (10)
//--#define HDMI_AVMCR_wd_vclk_en_shift                                   (9)
//--#define HDMI_AVMCR_avmute_flag_shift                                  (8)
//--#define HDMI_AVMCR_avmute_win_en_shift                                (7)
//--#define HDMI_AVMCR_aoc_shift                                          (6)
//--#define HDMI_AVMCR_aomc_shift                                         (5)
//--#define HDMI_AVMCR_awd_shift                                          (4)
//--#define HDMI_AVMCR_ve_shift                                           (3)
//--#define HDMI_AVMCR_ampic_shift                                        (2)
//--#define HDMI_AVMCR_vdpic_shift                                        (1)
//--#define HDMI_AVMCR_nfpss_shift                                        (0)
//--#define HDMI_AVMCR_wd_ptg_en_mask                                     (0x00000400)
//--#define HDMI_AVMCR_wd_vclk_en_mask                                    (0x00000200)
//--#define HDMI_AVMCR_avmute_flag_mask                                   (0x00000100)
//--#define HDMI_AVMCR_avmute_win_en_mask                                 (0x00000080)
//--#define HDMI_AVMCR_aoc_mask                                           (0x00000040)
//--#define HDMI_AVMCR_aomc_mask                                          (0x00000020)
//--#define HDMI_AVMCR_awd_mask                                           (0x00000010)
//--#define HDMI_AVMCR_ve_mask                                            (0x00000008)
//--#define HDMI_AVMCR_ampic_mask                                         (0x00000004)
//--#define HDMI_AVMCR_vdpic_mask                                         (0x00000002)
//--#define HDMI_AVMCR_nfpss_mask                                         (0x00000001)
//--#define HDMI_AVMCR_wd_ptg_en(data)                                    (0x00000400&((data)<<10))
//--#define HDMI_AVMCR_wd_vclk_en(data)                                   (0x00000200&((data)<<9))
//--#define HDMI_AVMCR_avmute_flag(data)                                  (0x00000100&((data)<<8))
//--#define HDMI_AVMCR_avmute_win_en(data)                                (0x00000080&((data)<<7))
//--#define HDMI_AVMCR_aoc(data)                                          (0x00000040&((data)<<6))
//--#define HDMI_AVMCR_aomc(data)                                         (0x00000020&((data)<<5))
//--#define HDMI_AVMCR_awd(data)                                          (0x00000010&((data)<<4))
//--#define HDMI_AVMCR_ve(data)                                           (0x00000008&((data)<<3))
//--#define HDMI_AVMCR_ampic(data)                                        (0x00000004&((data)<<2))
//--#define HDMI_AVMCR_vdpic(data)                                        (0x00000002&((data)<<1))
//--#define HDMI_AVMCR_nfpss(data)                                        (0x00000001&(data))
//--#define HDMI_AVMCR_get_wd_ptg_en(data)                                ((0x00000400&(data))>>10)
//--#define HDMI_AVMCR_get_wd_vclk_en(data)                               ((0x00000200&(data))>>9)
//--#define HDMI_AVMCR_get_avmute_flag(data)                              ((0x00000100&(data))>>8)
//--#define HDMI_AVMCR_get_avmute_win_en(data)                            ((0x00000080&(data))>>7)
//--#define HDMI_AVMCR_get_aoc(data)                                      ((0x00000040&(data))>>6)
//--#define HDMI_AVMCR_get_aomc(data)                                     ((0x00000020&(data))>>5)
//--#define HDMI_AVMCR_get_awd(data)                                      ((0x00000010&(data))>>4)
//--#define HDMI_AVMCR_get_ve(data)                                       ((0x00000008&(data))>>3)
//--#define HDMI_AVMCR_get_ampic(data)                                    ((0x00000004&(data))>>2)
//--#define HDMI_AVMCR_get_vdpic(data)                                    ((0x00000002&(data))>>1)
//--#define HDMI_AVMCR_get_nfpss(data)                                    (0x00000001&(data))
//--
//--
//--#define HDMI_WDCR0                                                    0x1800d09c
//--#define HDMI_WDCR0_reg_addr                                           "0xb800d09c"
//--#define HDMI_WDCR0_reg                                                0xb800d09c
//--#define HDMI_WDCR0_inst_addr                                          "0x0027"
//--#define HDMI_WDCR0_inst                                               0x0027
//--#define set_HDMI_WDCR0_reg(data)                                      (*((volatile unsigned int*)HDMI_WDCR0_reg)=data)
//--#define get_HDMI_WDCR0_reg                                            (*((volatile unsigned int*)HDMI_WDCR0_reg))
//--#define HDMI_WDCR0_vwdap_shift                                        (23)
//--#define HDMI_WDCR0_vwdlf_shift                                        (22)
//--#define HDMI_WDCR0_vwdafo_shift                                       (21)
//--#define HDMI_WDCR0_vwdafu_shift                                       (20)
//--#define HDMI_WDCR0_yv_shift                                           (16)
//--#define HDMI_WDCR0_awdck_shift                                        (15)
//--#define HDMI_WDCR0_awdlf_shift                                        (14)
//--#define HDMI_WDCR0_ch_st_sel_shift                                    (13)
//--#define HDMI_WDCR0_vwdact_shift                                       (12)
//--#define HDMI_WDCR0_xv_shift                                           (8)
//--#define HDMI_WDCR0_asmfe_shift                                        (7)
//--#define HDMI_WDCR0_load_d_shift                                       (6)
//--#define HDMI_WDCR0_bt_track_en_shift                                  (5)
//--#define HDMI_WDCR0_awdct_shift                                        (4)
//--#define HDMI_WDCR0_awdap_shift                                        (3)
//--#define HDMI_WDCR0_awdfo_shift                                        (2)
//--#define HDMI_WDCR0_awdfu_shift                                        (1)
//--#define HDMI_WDCR0_ct_shift                                           (0)
//--#define HDMI_WDCR0_vwdap_mask                                         (0x00800000)
//--#define HDMI_WDCR0_vwdlf_mask                                         (0x00400000)
//--#define HDMI_WDCR0_vwdafo_mask                                        (0x00200000)
//--#define HDMI_WDCR0_vwdafu_mask                                        (0x00100000)
//--#define HDMI_WDCR0_yv_mask                                            (0x000F0000)
//--#define HDMI_WDCR0_awdck_mask                                         (0x00008000)
//--#define HDMI_WDCR0_awdlf_mask                                         (0x00004000)
//--#define HDMI_WDCR0_ch_st_sel_mask                                     (0x00002000)
//--#define HDMI_WDCR0_vwdact_mask                                        (0x00001000)
//--#define HDMI_WDCR0_xv_mask                                            (0x00000F00)
//--#define HDMI_WDCR0_asmfe_mask                                         (0x00000080)
//--#define HDMI_WDCR0_load_d_mask                                        (0x00000040)
//--#define HDMI_WDCR0_bt_track_en_mask                                   (0x00000020)
//--#define HDMI_WDCR0_awdct_mask                                         (0x00000010)
//--#define HDMI_WDCR0_awdap_mask                                         (0x00000008)
//--#define HDMI_WDCR0_awdfo_mask                                         (0x00000004)
//--#define HDMI_WDCR0_awdfu_mask                                         (0x00000002)
//--#define HDMI_WDCR0_ct_mask                                            (0x00000001)
//--#define HDMI_WDCR0_vwdap(data)                                        (0x00800000&((data)<<23))
//--#define HDMI_WDCR0_vwdlf(data)                                        (0x00400000&((data)<<22))
//--#define HDMI_WDCR0_vwdafo(data)                                       (0x00200000&((data)<<21))
//--#define HDMI_WDCR0_vwdafu(data)                                       (0x00100000&((data)<<20))
//--#define HDMI_WDCR0_yv(data)                                           (0x000F0000&((data)<<16))
//--#define HDMI_WDCR0_awdck(data)                                        (0x00008000&((data)<<15))
//--#define HDMI_WDCR0_awdlf(data)                                        (0x00004000&((data)<<14))
//--#define HDMI_WDCR0_ch_st_sel(data)                                    (0x00002000&((data)<<13))
//--#define HDMI_WDCR0_vwdact(data)                                       (0x00001000&((data)<<12))
//--#define HDMI_WDCR0_xv(data)                                           (0x00000F00&((data)<<8))
//--#define HDMI_WDCR0_asmfe(data)                                        (0x00000080&((data)<<7))
//--#define HDMI_WDCR0_load_d(data)                                       (0x00000040&((data)<<6))
//--#define HDMI_WDCR0_bt_track_en(data)                                  (0x00000020&((data)<<5))
//--#define HDMI_WDCR0_awdct(data)                                        (0x00000010&((data)<<4))
//--#define HDMI_WDCR0_awdap(data)                                        (0x00000008&((data)<<3))
//--#define HDMI_WDCR0_awdfo(data)                                        (0x00000004&((data)<<2))
//--#define HDMI_WDCR0_awdfu(data)                                        (0x00000002&((data)<<1))
//--#define HDMI_WDCR0_ct(data)                                           (0x00000001&(data))
//--#define HDMI_WDCR0_get_vwdap(data)                                    ((0x00800000&(data))>>23)
//--#define HDMI_WDCR0_get_vwdlf(data)                                    ((0x00400000&(data))>>22)
//--#define HDMI_WDCR0_get_vwdafo(data)                                   ((0x00200000&(data))>>21)
//--#define HDMI_WDCR0_get_vwdafu(data)                                   ((0x00100000&(data))>>20)
//--#define HDMI_WDCR0_get_yv(data)                                       ((0x000F0000&(data))>>16)
//--#define HDMI_WDCR0_get_awdck(data)                                    ((0x00008000&(data))>>15)
//--#define HDMI_WDCR0_get_awdlf(data)                                    ((0x00004000&(data))>>14)
//--#define HDMI_WDCR0_get_ch_st_sel(data)                                ((0x00002000&(data))>>13)
//--#define HDMI_WDCR0_get_vwdact(data)                                   ((0x00001000&(data))>>12)
//--#define HDMI_WDCR0_get_xv(data)                                       ((0x00000F00&(data))>>8)
//--#define HDMI_WDCR0_get_asmfe(data)                                    ((0x00000080&(data))>>7)
//--#define HDMI_WDCR0_get_load_d(data)                                   ((0x00000040&(data))>>6)
//--#define HDMI_WDCR0_get_bt_track_en(data)                              ((0x00000020&(data))>>5)
//--#define HDMI_WDCR0_get_awdct(data)                                    ((0x00000010&(data))>>4)
//--#define HDMI_WDCR0_get_awdap(data)                                    ((0x00000008&(data))>>3)
//--#define HDMI_WDCR0_get_awdfo(data)                                    ((0x00000004&(data))>>2)
//--#define HDMI_WDCR0_get_awdfu(data)                                    ((0x00000002&(data))>>1)
//--#define HDMI_WDCR0_get_ct(data)                                       (0x00000001&(data))
//--
//--
//--#define HDMI_DBCR                                                     0x1800d0a0
//--#define HDMI_DBCR_reg_addr                                            "0xb800d0a0"
//--#define HDMI_DBCR_reg                                                 0xb800d0a0
//--#define HDMI_DBCR_inst_addr                                           "0x0028"
//--#define HDMI_DBCR_inst                                                0x0028
//--#define set_HDMI_DBCR_reg(data)                                       (*((volatile unsigned int*)HDMI_DBCR_reg)=data)
//--#define get_HDMI_DBCR_reg                                             (*((volatile unsigned int*)HDMI_DBCR_reg))
//--#define HDMI_DBCR_aldbfv_shift                                        (3)
//--#define HDMI_DBCR_aldbfo_shift                                        (2)
//--#define HDMI_DBCR_aldbfu_shift                                        (1)
//--#define HDMI_DBCR_aldbpn_shift                                        (0)
//--#define HDMI_DBCR_aldbfv_mask                                         (0x00000008)
//--#define HDMI_DBCR_aldbfo_mask                                         (0x00000004)
//--#define HDMI_DBCR_aldbfu_mask                                         (0x00000002)
//--#define HDMI_DBCR_aldbpn_mask                                         (0x00000001)
//--#define HDMI_DBCR_aldbfv(data)                                        (0x00000008&((data)<<3))
//--#define HDMI_DBCR_aldbfo(data)                                        (0x00000004&((data)<<2))
//--#define HDMI_DBCR_aldbfu(data)                                        (0x00000002&((data)<<1))
//--#define HDMI_DBCR_aldbpn(data)                                        (0x00000001&(data))
//--#define HDMI_DBCR_get_aldbfv(data)                                    ((0x00000008&(data))>>3)
//--#define HDMI_DBCR_get_aldbfo(data)                                    ((0x00000004&(data))>>2)
//--#define HDMI_DBCR_get_aldbfu(data)                                    ((0x00000002&(data))>>1)
//--#define HDMI_DBCR_get_aldbpn(data)                                    (0x00000001&(data))
//--
//--
//--#define HDMI_AWDSR                                                    0x1800d0a4
//--#define HDMI_AWDSR_reg_addr                                           "0xb800d0a4"
//--#define HDMI_AWDSR_reg                                                0xb800d0a4
//--#define HDMI_AWDSR_inst_addr                                          "0x0029"
//--#define HDMI_AWDSR_inst                                               0x0029
//--#define set_HDMI_AWDSR_reg(data)                                      (*((volatile unsigned int*)HDMI_AWDSR_reg)=data)
//--#define get_HDMI_AWDSR_reg                                            (*((volatile unsigned int*)HDMI_AWDSR_reg))
//--#define HDMI_AWDSR_awdpvsb_shift                                      (0)
//--#define HDMI_AWDSR_awdpvsb_mask                                       (0x0000007F)
//--#define HDMI_AWDSR_awdpvsb(data)                                      (0x0000007F&(data))
//--#define HDMI_AWDSR_get_awdpvsb(data)                                  (0x0000007F&(data))
//--
//--
//--#define HDMI_VWDSR                                                    0x1800d0a8
//--#define HDMI_VWDSR_reg_addr                                           "0xb800d0a8"
//--#define HDMI_VWDSR_reg                                                0xb800d0a8
//--#define HDMI_VWDSR_inst_addr                                          "0x002A"
//--#define HDMI_VWDSR_inst                                               0x002A
//--#define set_HDMI_VWDSR_reg(data)                                      (*((volatile unsigned int*)HDMI_VWDSR_reg)=data)
//--#define get_HDMI_VWDSR_reg                                            (*((volatile unsigned int*)HDMI_VWDSR_reg))
//--#define HDMI_VWDSR_vwdpvsb_shift                                      (0)
//--#define HDMI_VWDSR_vwdpvsb_mask                                       (0x0000007F)
//--#define HDMI_VWDSR_vwdpvsb(data)                                      (0x0000007F&(data))
//--#define HDMI_VWDSR_get_vwdpvsb(data)                                  (0x0000007F&(data))
//--
//--
//--#define HDMI_PAMICR                                                   0x1800d0ac
//--#define HDMI_PAMICR_reg_addr                                          "0xb800d0ac"
//--#define HDMI_PAMICR_reg                                               0xb800d0ac
//--#define HDMI_PAMICR_inst_addr                                         "0x002B"
//--#define HDMI_PAMICR_inst                                              0x002B
//--#define set_HDMI_PAMICR_reg(data)                                     (*((volatile unsigned int*)HDMI_PAMICR_reg)=data)
//--#define get_HDMI_PAMICR_reg                                           (*((volatile unsigned int*)HDMI_PAMICR_reg))
//--#define HDMI_PAMICR_icpvsb_shift                                      (0)
//--#define HDMI_PAMICR_icpvsb_mask                                       (0x0000007F)
//--#define HDMI_PAMICR_icpvsb(data)                                      (0x0000007F&(data))
//--#define HDMI_PAMICR_get_icpvsb(data)                                  (0x0000007F&(data))
//--
//--
//--#define HDMI_PTRSV1                                                   0x1800d0b0
//--#define HDMI_PTRSV1_reg_addr                                          "0xb800d0b0"
//--#define HDMI_PTRSV1_reg                                               0xb800d0b0
//--#define HDMI_PTRSV1_inst_addr                                         "0x002C"
//--#define HDMI_PTRSV1_inst                                              0x002C
//--#define set_HDMI_PTRSV1_reg(data)                                     (*((volatile unsigned int*)HDMI_PTRSV1_reg)=data)
//--#define get_HDMI_PTRSV1_reg                                           (*((volatile unsigned int*)HDMI_PTRSV1_reg))
//--#define HDMI_PTRSV1_dummy1800d0b0_31_24_shift                         (24)
//--#define HDMI_PTRSV1_dummy1800d0b0_23_16_shift                         (16)
//--#define HDMI_PTRSV1_pt2_shift                                         (8)
//--#define HDMI_PTRSV1_pt1_shift                                         (0)
//--#define HDMI_PTRSV1_dummy1800d0b0_31_24_mask                          (0xFF000000)
//--#define HDMI_PTRSV1_dummy1800d0b0_23_16_mask                          (0x00FF0000)
//--#define HDMI_PTRSV1_pt2_mask                                          (0x0000FF00)
//--#define HDMI_PTRSV1_pt1_mask                                          (0x000000FF)
//--#define HDMI_PTRSV1_dummy1800d0b0_31_24(data)                         (0xFF000000&((data)<<24))
//--#define HDMI_PTRSV1_dummy1800d0b0_23_16(data)                         (0x00FF0000&((data)<<16))
//--#define HDMI_PTRSV1_pt2(data)                                         (0x0000FF00&((data)<<8))
//--#define HDMI_PTRSV1_pt1(data)                                         (0x000000FF&(data))
//--#define HDMI_PTRSV1_get_dummy1800d0b0_31_24(data)                     ((0xFF000000&(data))>>24)
//--#define HDMI_PTRSV1_get_dummy1800d0b0_23_16(data)                     ((0x00FF0000&(data))>>16)
//--#define HDMI_PTRSV1_get_pt2(data)                                     ((0x0000FF00&(data))>>8)
//--#define HDMI_PTRSV1_get_pt1(data)                                     (0x000000FF&(data))
//--
//--
//--#define HDMI_PVGCR0                                                   0x1800d0b4
//--#define HDMI_PVGCR0_reg_addr                                          "0xb800d0b4"
//--#define HDMI_PVGCR0_reg                                               0xb800d0b4
//--#define HDMI_PVGCR0_inst_addr                                         "0x002D"
//--#define HDMI_PVGCR0_inst                                              0x002D
//--#define set_HDMI_PVGCR0_reg(data)                                     (*((volatile unsigned int*)HDMI_PVGCR0_reg)=data)
//--#define get_HDMI_PVGCR0_reg                                           (*((volatile unsigned int*)HDMI_PVGCR0_reg))
//--#define HDMI_PVGCR0_pvsef_shift                                       (0)
//--#define HDMI_PVGCR0_pvsef_mask                                        (0xFFFFFFFF)
//--#define HDMI_PVGCR0_pvsef(data)                                       (0xFFFFFFFF&(data))
//--#define HDMI_PVGCR0_get_pvsef(data)                                   (0xFFFFFFFF&(data))
//--
//--
//--#define HDMI_PVSR0                                                    0x1800d0b8
//--#define HDMI_PVSR0_reg_addr                                           "0xb800d0b8"
//--#define HDMI_PVSR0_reg                                                0xb800d0b8
//--#define HDMI_PVSR0_inst_addr                                          "0x002E"
//--#define HDMI_PVSR0_inst                                               0x002E
//--#define set_HDMI_PVSR0_reg(data)                                      (*((volatile unsigned int*)HDMI_PVSR0_reg)=data)
//--#define get_HDMI_PVSR0_reg                                            (*((volatile unsigned int*)HDMI_PVSR0_reg))
//--#define HDMI_PVSR0_pvs_shift                                          (0)
//--#define HDMI_PVSR0_pvs_mask                                           (0xFFFFFFFF)
//--#define HDMI_PVSR0_pvs(data)                                          (0xFFFFFFFF&(data))
//--#define HDMI_PVSR0_get_pvs(data)                                      (0xFFFFFFFF&(data))
//--
//--
//--#define HDMI_VCR                                                      0x1800d0bc
//--#define HDMI_VCR_reg_addr                                             "0xb800d0bc"
//--#define HDMI_VCR_reg                                                  0xb800d0bc
//--#define HDMI_VCR_inst_addr                                            "0x002F"
//--#define HDMI_VCR_inst                                                 0x002F
//--#define set_HDMI_VCR_reg(data)                                        (*((volatile unsigned int*)HDMI_VCR_reg)=data)
//--#define get_HDMI_VCR_reg                                              (*((volatile unsigned int*)HDMI_VCR_reg))
//--#define HDMI_VCR_cbus_ddc_chsel_shift                                 (28)
//--#define HDMI_VCR_hdmi_field_shift                                     (27)
//--#define HDMI_VCR_int_pro_chg_flag_shift                               (26)
//--#define HDMI_VCR_int_pro_chg_wd_en_shift                              (25)
//--#define HDMI_VCR_int_pro_chg_int_en_shift                             (24)
//--#define HDMI_VCR_hdcp_ddc_chsel_shift                                 (22)
//--#define HDMI_VCR_iclk_sel_shift                                       (20)
//--#define HDMI_VCR_csc_r_shift                                          (18)
//--#define HDMI_VCR_hdirq_shift                                          (17)
//--#define HDMI_VCR_csam_shift                                           (16)
//--#define HDMI_VCR_csc_shift                                            (14)
//--#define HDMI_VCR_field_decide_sel_shift                               (13)
//--#define HDMI_VCR_prdsam_shift                                         (12)
//--#define HDMI_VCR_dsc_r_shift                                          (8)
//--#define HDMI_VCR_eoi_shift                                            (7)
//--#define HDMI_VCR_eot_shift                                            (6)
//--#define HDMI_VCR_se_shift                                             (5)
//--#define HDMI_VCR_rs_shift                                             (4)
//--#define HDMI_VCR_dsc_shift                                            (0)
//--#define HDMI_VCR_cbus_ddc_chsel_mask                                  (0x10000000)
//--#define HDMI_VCR_hdmi_field_mask                                      (0x08000000)
//--#define HDMI_VCR_int_pro_chg_flag_mask                                (0x04000000)
//--#define HDMI_VCR_int_pro_chg_wd_en_mask                               (0x02000000)
//--#define HDMI_VCR_int_pro_chg_int_en_mask                              (0x01000000)
//--#define HDMI_VCR_hdcp_ddc_chsel_mask                                  (0x00C00000)
//--#define HDMI_VCR_iclk_sel_mask                                        (0x00300000)
//--#define HDMI_VCR_csc_r_mask                                           (0x000C0000)
//--#define HDMI_VCR_hdirq_mask                                           (0x00020000)
//--#define HDMI_VCR_csam_mask                                            (0x00010000)
//--#define HDMI_VCR_csc_mask                                             (0x0000C000)
//--#define HDMI_VCR_field_decide_sel_mask                                (0x00002000)
//--#define HDMI_VCR_prdsam_mask                                          (0x00001000)
//--#define HDMI_VCR_dsc_r_mask                                           (0x00000F00)
//--#define HDMI_VCR_eoi_mask                                             (0x00000080)
//--#define HDMI_VCR_eot_mask                                             (0x00000040)
//--#define HDMI_VCR_se_mask                                              (0x00000020)
//--#define HDMI_VCR_rs_mask                                              (0x00000010)
//--#define HDMI_VCR_dsc_mask                                             (0x0000000F)
//--#define HDMI_VCR_cbus_ddc_chsel(data)                                 (0x10000000&((data)<<28))
//--#define HDMI_VCR_hdmi_field(data)                                     (0x08000000&((data)<<27))
//--#define HDMI_VCR_int_pro_chg_flag(data)                               (0x04000000&((data)<<26))
//--#define HDMI_VCR_int_pro_chg_wd_en(data)                              (0x02000000&((data)<<25))
//--#define HDMI_VCR_int_pro_chg_int_en(data)                             (0x01000000&((data)<<24))
//--#define HDMI_VCR_hdcp_ddc_chsel(data)                                 (0x00C00000&((data)<<22))
//--#define HDMI_VCR_iclk_sel(data)                                       (0x00300000&((data)<<20))
//--#define HDMI_VCR_csc_r(data)                                          (0x000C0000&((data)<<18))
//--#define HDMI_VCR_hdirq(data)                                          (0x00020000&((data)<<17))
//--#define HDMI_VCR_csam(data)                                           (0x00010000&((data)<<16))
//--#define HDMI_VCR_csc(data)                                            (0x0000C000&((data)<<14))
//--#define HDMI_VCR_field_decide_sel(data)                               (0x00002000&((data)<<13))
//--#define HDMI_VCR_prdsam(data)                                         (0x00001000&((data)<<12))
//--#define HDMI_VCR_dsc_r(data)                                          (0x00000F00&((data)<<8))
//--#define HDMI_VCR_eoi(data)                                            (0x00000080&((data)<<7))
//--#define HDMI_VCR_eot(data)                                            (0x00000040&((data)<<6))
//--#define HDMI_VCR_se(data)                                             (0x00000020&((data)<<5))
//--#define HDMI_VCR_rs(data)                                             (0x00000010&((data)<<4))
//--#define HDMI_VCR_dsc(data)                                            (0x0000000F&(data))
//--#define HDMI_VCR_get_cbus_ddc_chsel(data)                             ((0x10000000&(data))>>28)
//--#define HDMI_VCR_get_hdmi_field(data)                                 ((0x08000000&(data))>>27)
//--#define HDMI_VCR_get_int_pro_chg_flag(data)                           ((0x04000000&(data))>>26)
//--#define HDMI_VCR_get_int_pro_chg_wd_en(data)                          ((0x02000000&(data))>>25)
//--#define HDMI_VCR_get_int_pro_chg_int_en(data)                         ((0x01000000&(data))>>24)
//--#define HDMI_VCR_get_hdcp_ddc_chsel(data)                             ((0x00C00000&(data))>>22)
//--#define HDMI_VCR_get_iclk_sel(data)                                   ((0x00300000&(data))>>20)
//--#define HDMI_VCR_get_csc_r(data)                                      ((0x000C0000&(data))>>18)
//--#define HDMI_VCR_get_hdirq(data)                                      ((0x00020000&(data))>>17)
//--#define HDMI_VCR_get_csam(data)                                       ((0x00010000&(data))>>16)
//--#define HDMI_VCR_get_csc(data)                                        ((0x0000C000&(data))>>14)
//--#define HDMI_VCR_get_field_decide_sel(data)                           ((0x00002000&(data))>>13)
//--#define HDMI_VCR_get_prdsam(data)                                     ((0x00001000&(data))>>12)
//--#define HDMI_VCR_get_dsc_r(data)                                      ((0x00000F00&(data))>>8)
//--#define HDMI_VCR_get_eoi(data)                                        ((0x00000080&(data))>>7)
//--#define HDMI_VCR_get_eot(data)                                        ((0x00000040&(data))>>6)
//--#define HDMI_VCR_get_se(data)                                         ((0x00000020&(data))>>5)
//--#define HDMI_VCR_get_rs(data)                                         ((0x00000010&(data))>>4)
//--#define HDMI_VCR_get_dsc(data)                                        (0x0000000F&(data))
//--
//--
//--#define HDMI_ACRCR                                                    0x1800d0c0
//--#define HDMI_ACRCR_reg_addr                                           "0xb800d0c0"
//--#define HDMI_ACRCR_reg                                                0xb800d0c0
//--#define HDMI_ACRCR_inst_addr                                          "0x0030"
//--#define HDMI_ACRCR_inst                                               0x0030
//--#define set_HDMI_ACRCR_reg(data)                                      (*((volatile unsigned int*)HDMI_ACRCR_reg)=data)
//--#define get_HDMI_ACRCR_reg                                            (*((volatile unsigned int*)HDMI_ACRCR_reg))
//--#define HDMI_ACRCR_pucnr_shift                                        (1)
//--#define HDMI_ACRCR_pucsr_shift                                        (0)
//--#define HDMI_ACRCR_pucnr_mask                                         (0x00000002)
//--#define HDMI_ACRCR_pucsr_mask                                         (0x00000001)
//--#define HDMI_ACRCR_pucnr(data)                                        (0x00000002&((data)<<1))
//--#define HDMI_ACRCR_pucsr(data)                                        (0x00000001&(data))
//--#define HDMI_ACRCR_get_pucnr(data)                                    ((0x00000002&(data))>>1)
//--#define HDMI_ACRCR_get_pucsr(data)                                    (0x00000001&(data))
//--
//--
//--#define HDMI_ACRSR0                                                   0x1800d0c4
//--#define HDMI_ACRSR0_reg_addr                                          "0xb800d0c4"
//--#define HDMI_ACRSR0_reg                                               0xb800d0c4
//--#define HDMI_ACRSR0_inst_addr                                         "0x0031"
//--#define HDMI_ACRSR0_inst                                              0x0031
//--#define set_HDMI_ACRSR0_reg(data)                                     (*((volatile unsigned int*)HDMI_ACRSR0_reg)=data)
//--#define get_HDMI_ACRSR0_reg                                           (*((volatile unsigned int*)HDMI_ACRSR0_reg))
//--#define HDMI_ACRSR0_cts_shift                                         (0)
//--#define HDMI_ACRSR0_cts_mask                                          (0x000FFFFF)
//--#define HDMI_ACRSR0_cts(data)                                         (0x000FFFFF&(data))
//--#define HDMI_ACRSR0_get_cts(data)                                     (0x000FFFFF&(data))
//--
//--
//--#define HDMI_ACRSR1                                                   0x1800d0c8
//--#define HDMI_ACRSR1_reg_addr                                          "0xb800d0c8"
//--#define HDMI_ACRSR1_reg                                               0xb800d0c8
//--#define HDMI_ACRSR1_inst_addr                                         "0x0032"
//--#define HDMI_ACRSR1_inst                                              0x0032
//--#define set_HDMI_ACRSR1_reg(data)                                     (*((volatile unsigned int*)HDMI_ACRSR1_reg)=data)
//--#define get_HDMI_ACRSR1_reg                                           (*((volatile unsigned int*)HDMI_ACRSR1_reg))
//--#define HDMI_ACRSR1_n_shift                                           (0)
//--#define HDMI_ACRSR1_n_mask                                            (0x000FFFFF)
//--#define HDMI_ACRSR1_n(data)                                           (0x000FFFFF&(data))
//--#define HDMI_ACRSR1_get_n(data)                                       (0x000FFFFF&(data))
//--
//--
//--#define HDMI_ACS0                                                     0x1800d0cc
//--#define HDMI_ACS0_reg_addr                                            "0xb800d0cc"
//--#define HDMI_ACS0_reg                                                 0xb800d0cc
//--#define HDMI_ACS0_inst_addr                                           "0x0033"
//--#define HDMI_ACS0_inst                                                0x0033
//--#define set_HDMI_ACS0_reg(data)                                       (*((volatile unsigned int*)HDMI_ACS0_reg)=data)
//--#define get_HDMI_ACS0_reg                                             (*((volatile unsigned int*)HDMI_ACS0_reg))
//--#define HDMI_ACS0_cs_shift                                            (0)
//--#define HDMI_ACS0_cs_mask                                             (0x0000FFFF)
//--#define HDMI_ACS0_cs(data)                                            (0x0000FFFF&(data))
//--#define HDMI_ACS0_get_cs(data)                                        (0x0000FFFF&(data))
//--
//--
//--#define HDMI_ACS1                                                     0x1800d0d0
//--#define HDMI_ACS1_reg_addr                                            "0xb800d0d0"
//--#define HDMI_ACS1_reg                                                 0xb800d0d0
//--#define HDMI_ACS1_inst_addr                                           "0x0034"
//--#define HDMI_ACS1_inst                                                0x0034
//--#define set_HDMI_ACS1_reg(data)                                       (*((volatile unsigned int*)HDMI_ACS1_reg)=data)
//--#define get_HDMI_ACS1_reg                                             (*((volatile unsigned int*)HDMI_ACS1_reg))
//--#define HDMI_ACS1_cs_shift                                            (0)
//--#define HDMI_ACS1_cs_mask                                             (0x00FFFFFF)
//--#define HDMI_ACS1_cs(data)                                            (0x00FFFFFF&(data))
//--#define HDMI_ACS1_get_cs(data)                                        (0x00FFFFFF&(data))
//--
//--
//--#define HDMI_INTCR                                                    0x1800d0d4
//--#define HDMI_INTCR_reg_addr                                           "0xb800d0d4"
//--#define HDMI_INTCR_reg                                                0xb800d0d4
//--#define HDMI_INTCR_inst_addr                                          "0x0035"
//--#define HDMI_INTCR_inst                                               0x0035
//--#define set_HDMI_INTCR_reg(data)                                      (*((volatile unsigned int*)HDMI_INTCR_reg)=data)
//--#define get_HDMI_INTCR_reg                                            (*((volatile unsigned int*)HDMI_INTCR_reg))
//--#define HDMI_INTCR_pending_shift                                      (7)
//--#define HDMI_INTCR_avmute_shift                                       (6)
//--#define HDMI_INTCR_fifod_shift                                        (5)
//--#define HDMI_INTCR_act_shift                                          (4)
//--#define HDMI_INTCR_apll_shift                                         (3)
//--#define HDMI_INTCR_afifoo_shift                                       (2)
//--#define HDMI_INTCR_afifou_shift                                       (1)
//--#define HDMI_INTCR_vc_shift                                           (0)
//--#define HDMI_INTCR_pending_mask                                       (0x00000080)
//--#define HDMI_INTCR_avmute_mask                                        (0x00000040)
//--#define HDMI_INTCR_fifod_mask                                         (0x00000020)
//--#define HDMI_INTCR_act_mask                                           (0x00000010)
//--#define HDMI_INTCR_apll_mask                                          (0x00000008)
//--#define HDMI_INTCR_afifoo_mask                                        (0x00000004)
//--#define HDMI_INTCR_afifou_mask                                        (0x00000002)
//--#define HDMI_INTCR_vc_mask                                            (0x00000001)
//--#define HDMI_INTCR_pending(data)                                      (0x00000080&((data)<<7))
//--#define HDMI_INTCR_avmute(data)                                       (0x00000040&((data)<<6))
//--#define HDMI_INTCR_fifod(data)                                        (0x00000020&((data)<<5))
//--#define HDMI_INTCR_act(data)                                          (0x00000010&((data)<<4))
//--#define HDMI_INTCR_apll(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_INTCR_afifoo(data)                                       (0x00000004&((data)<<2))
//--#define HDMI_INTCR_afifou(data)                                       (0x00000002&((data)<<1))
//--#define HDMI_INTCR_vc(data)                                           (0x00000001&(data))
//--#define HDMI_INTCR_get_pending(data)                                  ((0x00000080&(data))>>7)
//--#define HDMI_INTCR_get_avmute(data)                                   ((0x00000040&(data))>>6)
//--#define HDMI_INTCR_get_fifod(data)                                    ((0x00000020&(data))>>5)
//--#define HDMI_INTCR_get_act(data)                                      ((0x00000010&(data))>>4)
//--#define HDMI_INTCR_get_apll(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_INTCR_get_afifoo(data)                                   ((0x00000004&(data))>>2)
//--#define HDMI_INTCR_get_afifou(data)                                   ((0x00000002&(data))>>1)
//--#define HDMI_INTCR_get_vc(data)                                       (0x00000001&(data))
//--
//--
//--#define HDMI_ALCR                                                     0x1800d0d8
//--#define HDMI_ALCR_reg_addr                                            "0xb800d0d8"
//--#define HDMI_ALCR_reg                                                 0xb800d0d8
//--#define HDMI_ALCR_inst_addr                                           "0x0036"
//--#define HDMI_ALCR_inst                                                0x0036
//--#define set_HDMI_ALCR_reg(data)                                       (*((volatile unsigned int*)HDMI_ALCR_reg)=data)
//--#define get_HDMI_ALCR_reg                                             (*((volatile unsigned int*)HDMI_ALCR_reg))
//--#define HDMI_ALCR_lo1_shift                                           (6)
//--#define HDMI_ALCR_lo2_shift                                           (4)
//--#define HDMI_ALCR_lo3_shift                                           (2)
//--#define HDMI_ALCR_lo4_shift                                           (0)
//--#define HDMI_ALCR_lo1_mask                                            (0x000000C0)
//--#define HDMI_ALCR_lo2_mask                                            (0x00000030)
//--#define HDMI_ALCR_lo3_mask                                            (0x0000000C)
//--#define HDMI_ALCR_lo4_mask                                            (0x00000003)
//--#define HDMI_ALCR_lo1(data)                                           (0x000000C0&((data)<<6))
//--#define HDMI_ALCR_lo2(data)                                           (0x00000030&((data)<<4))
//--#define HDMI_ALCR_lo3(data)                                           (0x0000000C&((data)<<2))
//--#define HDMI_ALCR_lo4(data)                                           (0x00000003&(data))
//--#define HDMI_ALCR_get_lo1(data)                                       ((0x000000C0&(data))>>6)
//--#define HDMI_ALCR_get_lo2(data)                                       ((0x00000030&(data))>>4)
//--#define HDMI_ALCR_get_lo3(data)                                       ((0x0000000C&(data))>>2)
//--#define HDMI_ALCR_get_lo4(data)                                       (0x00000003&(data))
//--
//--
//--#define HDMI_AOCR                                                     0x1800d0dc
//--#define HDMI_AOCR_reg_addr                                            "0xb800d0dc"
//--#define HDMI_AOCR_reg                                                 0xb800d0dc
//--#define HDMI_AOCR_inst_addr                                           "0x0037"
//--#define HDMI_AOCR_inst                                                0x0037
//--#define set_HDMI_AOCR_reg(data)                                       (*((volatile unsigned int*)HDMI_AOCR_reg)=data)
//--#define get_HDMI_AOCR_reg                                             (*((volatile unsigned int*)HDMI_AOCR_reg))
//--#define HDMI_AOCR_i2s_clk_en_dvi_shift                                (8)
//--#define HDMI_AOCR_spdifo1_shift                                       (7)
//--#define HDMI_AOCR_spdifo2_shift                                       (6)
//--#define HDMI_AOCR_spdifo3_shift                                       (5)
//--#define HDMI_AOCR_spdifo4_shift                                       (4)
//--#define HDMI_AOCR_i2so1_shift                                         (3)
//--#define HDMI_AOCR_i2so2_shift                                         (2)
//--#define HDMI_AOCR_i2so3_shift                                         (1)
//--#define HDMI_AOCR_i2so4_shift                                         (0)
//--#define HDMI_AOCR_i2s_clk_en_dvi_mask                                 (0x00000100)
//--#define HDMI_AOCR_spdifo1_mask                                        (0x00000080)
//--#define HDMI_AOCR_spdifo2_mask                                        (0x00000040)
//--#define HDMI_AOCR_spdifo3_mask                                        (0x00000020)
//--#define HDMI_AOCR_spdifo4_mask                                        (0x00000010)
//--#define HDMI_AOCR_i2so1_mask                                          (0x00000008)
//--#define HDMI_AOCR_i2so2_mask                                          (0x00000004)
//--#define HDMI_AOCR_i2so3_mask                                          (0x00000002)
//--#define HDMI_AOCR_i2so4_mask                                          (0x00000001)
//--#define HDMI_AOCR_i2s_clk_en_dvi(data)                                (0x00000100&((data)<<8))
//--#define HDMI_AOCR_spdifo1(data)                                       (0x00000080&((data)<<7))
//--#define HDMI_AOCR_spdifo2(data)                                       (0x00000040&((data)<<6))
//--#define HDMI_AOCR_spdifo3(data)                                       (0x00000020&((data)<<5))
//--#define HDMI_AOCR_spdifo4(data)                                       (0x00000010&((data)<<4))
//--#define HDMI_AOCR_i2so1(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_AOCR_i2so2(data)                                         (0x00000004&((data)<<2))
//--#define HDMI_AOCR_i2so3(data)                                         (0x00000002&((data)<<1))
//--#define HDMI_AOCR_i2so4(data)                                         (0x00000001&(data))
//--#define HDMI_AOCR_get_i2s_clk_en_dvi(data)                            ((0x00000100&(data))>>8)
//--#define HDMI_AOCR_get_spdifo1(data)                                   ((0x00000080&(data))>>7)
//--#define HDMI_AOCR_get_spdifo2(data)                                   ((0x00000040&(data))>>6)
//--#define HDMI_AOCR_get_spdifo3(data)                                   ((0x00000020&(data))>>5)
//--#define HDMI_AOCR_get_spdifo4(data)                                   ((0x00000010&(data))>>4)
//--#define HDMI_AOCR_get_i2so1(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_AOCR_get_i2so2(data)                                     ((0x00000004&(data))>>2)
//--#define HDMI_AOCR_get_i2so3(data)                                     ((0x00000002&(data))>>1)
//--#define HDMI_AOCR_get_i2so4(data)                                     (0x00000001&(data))
//--
//--
//--#define HDMI_BCSR                                                     0x1800d0e0
//--#define HDMI_BCSR_reg_addr                                            "0xb800d0e0"
//--#define HDMI_BCSR_reg                                                 0xb800d0e0
//--#define HDMI_BCSR_inst_addr                                           "0x0038"
//--#define HDMI_BCSR_inst                                                0x0038
//--#define set_HDMI_BCSR_reg(data)                                       (*((volatile unsigned int*)HDMI_BCSR_reg)=data)
//--#define get_HDMI_BCSR_reg                                             (*((volatile unsigned int*)HDMI_BCSR_reg))
//--#define HDMI_BCSR_nvlgb_shift                                         (5)
//--#define HDMI_BCSR_nalgb_shift                                         (4)
//--#define HDMI_BCSR_natgb_shift                                         (3)
//--#define HDMI_BCSR_ngb_shift                                           (2)
//--#define HDMI_BCSR_pe_shift                                            (1)
//--#define HDMI_BCSR_gcp_shift                                           (0)
//--#define HDMI_BCSR_nvlgb_mask                                          (0x00000020)
//--#define HDMI_BCSR_nalgb_mask                                          (0x00000010)
//--#define HDMI_BCSR_natgb_mask                                          (0x00000008)
//--#define HDMI_BCSR_ngb_mask                                            (0x00000004)
//--#define HDMI_BCSR_pe_mask                                             (0x00000002)
//--#define HDMI_BCSR_gcp_mask                                            (0x00000001)
//--#define HDMI_BCSR_nvlgb(data)                                         (0x00000020&((data)<<5))
//--#define HDMI_BCSR_nalgb(data)                                         (0x00000010&((data)<<4))
//--#define HDMI_BCSR_natgb(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_BCSR_ngb(data)                                           (0x00000004&((data)<<2))
//--#define HDMI_BCSR_pe(data)                                            (0x00000002&((data)<<1))
//--#define HDMI_BCSR_gcp(data)                                           (0x00000001&(data))
//--#define HDMI_BCSR_get_nvlgb(data)                                     ((0x00000020&(data))>>5)
//--#define HDMI_BCSR_get_nalgb(data)                                     ((0x00000010&(data))>>4)
//--#define HDMI_BCSR_get_natgb(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_BCSR_get_ngb(data)                                       ((0x00000004&(data))>>2)
//--#define HDMI_BCSR_get_pe(data)                                        ((0x00000002&(data))>>1)
//--#define HDMI_BCSR_get_gcp(data)                                       (0x00000001&(data))
//--
//--
//--#define HDMI_ASR0                                                     0x1800d0e4
//--#define HDMI_ASR0_reg_addr                                            "0xb800d0e4"
//--#define HDMI_ASR0_reg                                                 0xb800d0e4
//--#define HDMI_ASR0_inst_addr                                           "0x0039"
//--#define HDMI_ASR0_inst                                                0x0039
//--#define set_HDMI_ASR0_reg(data)                                       (*((volatile unsigned int*)HDMI_ASR0_reg)=data)
//--#define get_HDMI_ASR0_reg                                             (*((volatile unsigned int*)HDMI_ASR0_reg))
//--#define HDMI_ASR0_fsre_shift                                          (2)
//--#define HDMI_ASR0_fsif_shift                                          (1)
//--#define HDMI_ASR0_fscs_shift                                          (0)
//--#define HDMI_ASR0_fsre_mask                                           (0x00000004)
//--#define HDMI_ASR0_fsif_mask                                           (0x00000002)
//--#define HDMI_ASR0_fscs_mask                                           (0x00000001)
//--#define HDMI_ASR0_fsre(data)                                          (0x00000004&((data)<<2))
//--#define HDMI_ASR0_fsif(data)                                          (0x00000002&((data)<<1))
//--#define HDMI_ASR0_fscs(data)                                          (0x00000001&(data))
//--#define HDMI_ASR0_get_fsre(data)                                      ((0x00000004&(data))>>2)
//--#define HDMI_ASR0_get_fsif(data)                                      ((0x00000002&(data))>>1)
//--#define HDMI_ASR0_get_fscs(data)                                      (0x00000001&(data))
//--
//--
//--#define HDMI_ASR1                                                     0x1800d0e8
//--#define HDMI_ASR1_reg_addr                                            "0xb800d0e8"
//--#define HDMI_ASR1_reg                                                 0xb800d0e8
//--#define HDMI_ASR1_inst_addr                                           "0x003A"
//--#define HDMI_ASR1_inst                                                0x003A
//--#define set_HDMI_ASR1_reg(data)                                       (*((volatile unsigned int*)HDMI_ASR1_reg)=data)
//--#define get_HDMI_ASR1_reg                                             (*((volatile unsigned int*)HDMI_ASR1_reg))
//--#define HDMI_ASR1_fbif_shift                                          (4)
//--#define HDMI_ASR1_fbcs_shift                                          (0)
//--#define HDMI_ASR1_fbif_mask                                           (0x00000070)
//--#define HDMI_ASR1_fbcs_mask                                           (0x0000000F)
//--#define HDMI_ASR1_fbif(data)                                          (0x00000070&((data)<<4))
//--#define HDMI_ASR1_fbcs(data)                                          (0x0000000F&(data))
//--#define HDMI_ASR1_get_fbif(data)                                      ((0x00000070&(data))>>4)
//--#define HDMI_ASR1_get_fbcs(data)                                      (0x0000000F&(data))
//--
//--
//--#define HDMI_VIDEO_FORMAT                                             0x1800d0ec
//--#define HDMI_VIDEO_FORMAT_reg_addr                                    "0xb800d0ec"
//--#define HDMI_VIDEO_FORMAT_reg                                         0xb800d0ec
//--#define HDMI_VIDEO_FORMAT_inst_addr                                   "0x003B"
//--#define HDMI_VIDEO_FORMAT_inst                                        0x003B
//--#define set_HDMI_VIDEO_FORMAT_reg(data)                               (*((volatile unsigned int*)HDMI_VIDEO_FORMAT_reg)=data)
//--#define get_HDMI_VIDEO_FORMAT_reg                                     (*((volatile unsigned int*)HDMI_VIDEO_FORMAT_reg))
//--#define HDMI_VIDEO_FORMAT_hvf_shift                                   (8)
//--#define HDMI_VIDEO_FORMAT_hdmi_vic_shift                              (0)
//--#define HDMI_VIDEO_FORMAT_hvf_mask                                    (0x00000700)
//--#define HDMI_VIDEO_FORMAT_hdmi_vic_mask                               (0x000000FF)
//--#define HDMI_VIDEO_FORMAT_hvf(data)                                   (0x00000700&((data)<<8))
//--#define HDMI_VIDEO_FORMAT_hdmi_vic(data)                              (0x000000FF&(data))
//--#define HDMI_VIDEO_FORMAT_get_hvf(data)                               ((0x00000700&(data))>>8)
//--#define HDMI_VIDEO_FORMAT_get_hdmi_vic(data)                          (0x000000FF&(data))
//--
//--
//--#define HDMI_3D_FORMAT                                                0x1800d0f0
//--#define HDMI_3D_FORMAT_reg_addr                                       "0xb800d0f0"
//--#define HDMI_3D_FORMAT_reg                                            0xb800d0f0
//--#define HDMI_3D_FORMAT_inst_addr                                      "0x003C"
//--#define HDMI_3D_FORMAT_inst                                           0x003C
//--#define set_HDMI_3D_FORMAT_reg(data)                                  (*((volatile unsigned int*)HDMI_3D_FORMAT_reg)=data)
//--#define get_HDMI_3D_FORMAT_reg                                        (*((volatile unsigned int*)HDMI_3D_FORMAT_reg))
//--#define HDMI_3D_FORMAT_hdmi_3d_ext_data_shift                         (12)
//--#define HDMI_3D_FORMAT_hdmi_3d_metadata_type_shift                    (9)
//--#define HDMI_3D_FORMAT_hdmi_3d_structure_shift                        (4)
//--#define HDMI_3D_FORMAT_hdmi_3d_meta_present_shift                     (3)
//--#define HDMI_3D_FORMAT_hdmi_3d_ext_data_mask                          (0x0000F000)
//--#define HDMI_3D_FORMAT_hdmi_3d_metadata_type_mask                     (0x00000E00)
//--#define HDMI_3D_FORMAT_hdmi_3d_structure_mask                         (0x000000F0)
//--#define HDMI_3D_FORMAT_hdmi_3d_meta_present_mask                      (0x00000008)
//--#define HDMI_3D_FORMAT_hdmi_3d_ext_data(data)                         (0x0000F000&((data)<<12))
//--#define HDMI_3D_FORMAT_hdmi_3d_metadata_type(data)                    (0x00000E00&((data)<<9))
//--#define HDMI_3D_FORMAT_hdmi_3d_structure(data)                        (0x000000F0&((data)<<4))
//--#define HDMI_3D_FORMAT_hdmi_3d_meta_present(data)                     (0x00000008&((data)<<3))
//--#define HDMI_3D_FORMAT_get_hdmi_3d_ext_data(data)                     ((0x0000F000&(data))>>12)
//--#define HDMI_3D_FORMAT_get_hdmi_3d_metadata_type(data)                ((0x00000E00&(data))>>9)
//--#define HDMI_3D_FORMAT_get_hdmi_3d_structure(data)                    ((0x000000F0&(data))>>4)
//--#define HDMI_3D_FORMAT_get_hdmi_3d_meta_present(data)                 ((0x00000008&(data))>>3)
//--
//--
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ                                  0x1800d100
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg_addr                         "0xb800d100"
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg                              0xb800d100
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_inst_addr                        "0x0040"
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_inst                             0x0040
//--#define set_AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg(data)                    (*((volatile unsigned int*)AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg)=data)
//--#define get_AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg                          (*((volatile unsigned int*)AUDIO_SAMPLE_RATE_CHANGE_IRQ_reg))
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ncts_chg_irq_shift            (3)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ncts_chg_irq_shift               (2)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ch_status_chg_irq_shift       (1)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ch_status_chg_irq_shift          (0)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ncts_chg_irq_mask             (0x00000008)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ncts_chg_irq_mask                (0x00000004)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ch_status_chg_irq_mask        (0x00000002)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ch_status_chg_irq_mask           (0x00000001)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ncts_chg_irq(data)            (0x00000008&((data)<<3))
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ncts_chg_irq(data)               (0x00000004&((data)<<2))
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_en_ch_status_chg_irq(data)       (0x00000002&((data)<<1))
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_ch_status_chg_irq(data)          (0x00000001&(data))
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_get_en_ncts_chg_irq(data)        ((0x00000008&(data))>>3)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_get_ncts_chg_irq(data)           ((0x00000004&(data))>>2)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_get_en_ch_status_chg_irq(data)   ((0x00000002&(data))>>1)
//--#define AUDIO_SAMPLE_RATE_CHANGE_IRQ_get_ch_status_chg_irq(data)      (0x00000001&(data))
//--
//--
//--#define HIGH_BIT_RATE_AUDIO_PACKET                                    0x1800d104
//--#define HIGH_BIT_RATE_AUDIO_PACKET_reg_addr                           "0xb800d104"
//--#define HIGH_BIT_RATE_AUDIO_PACKET_reg                                0xb800d104
//--#define HIGH_BIT_RATE_AUDIO_PACKET_inst_addr                          "0x0041"
//--#define HIGH_BIT_RATE_AUDIO_PACKET_inst                               0x0041
//--#define set_HIGH_BIT_RATE_AUDIO_PACKET_reg(data)                      (*((volatile unsigned int*)HIGH_BIT_RATE_AUDIO_PACKET_reg)=data)
//--#define get_HIGH_BIT_RATE_AUDIO_PACKET_reg                            (*((volatile unsigned int*)HIGH_BIT_RATE_AUDIO_PACKET_reg))
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_manual_shift        (2)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_fw_shift            (1)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_shift               (0)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_manual_mask         (0x00000004)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_fw_mask             (0x00000002)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_mask                (0x00000001)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_manual(data)        (0x00000004&((data)<<2))
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode_fw(data)            (0x00000002&((data)<<1))
//--#define HIGH_BIT_RATE_AUDIO_PACKET_hbr_audio_mode(data)               (0x00000001&(data))
//--#define HIGH_BIT_RATE_AUDIO_PACKET_get_hbr_audio_mode_manual(data)    ((0x00000004&(data))>>2)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_get_hbr_audio_mode_fw(data)        ((0x00000002&(data))>>1)
//--#define HIGH_BIT_RATE_AUDIO_PACKET_get_hbr_audio_mode(data)           (0x00000001&(data))
//--
//--
//--#define HDMI_AFCR                                                     0x1800d108
//--#define HDMI_AFCR_reg_addr                                            "0xb800d108"
//--#define HDMI_AFCR_reg                                                 0xb800d108
//--#define HDMI_AFCR_inst_addr                                           "0x0042"
//--#define HDMI_AFCR_inst                                                0x0042
//--#define set_HDMI_AFCR_reg(data)                                       (*((volatile unsigned int*)HDMI_AFCR_reg)=data)
//--#define get_HDMI_AFCR_reg                                             (*((volatile unsigned int*)HDMI_AFCR_reg))
//--#define HDMI_AFCR_dummy1800d108_31_14_shift                           (14)
//--#define HDMI_AFCR_gain_bypass_en_shift                                (13)
//--#define HDMI_AFCR_afifof_shift                                        (12)
//--#define HDMI_AFCR_afifoe_shift                                        (11)
//--#define HDMI_AFCR_afifowe_r_shift                                     (10)
//--#define HDMI_AFCR_afifore_r_shift                                     (8)
//--#define HDMI_AFCR_tst_i2s_sw_shift                                    (7)
//--#define HDMI_AFCR_aoem_shift                                          (6)
//--#define HDMI_AFCR_aoc_shift                                           (5)
//--#define HDMI_AFCR_audio_test_enable_shift                             (4)
//--#define HDMI_AFCR_mgc_shift                                           (3)
//--#define HDMI_AFCR_afifowe_shift                                       (2)
//--#define HDMI_AFCR_afifore_shift                                       (0)
//--#define HDMI_AFCR_dummy1800d108_31_14_mask                            (0xFFFFC000)
//--#define HDMI_AFCR_gain_bypass_en_mask                                 (0x00002000)
//--#define HDMI_AFCR_afifof_mask                                         (0x00001000)
//--#define HDMI_AFCR_afifoe_mask                                         (0x00000800)
//--#define HDMI_AFCR_afifowe_r_mask                                      (0x00000400)
//--#define HDMI_AFCR_afifore_r_mask                                      (0x00000300)
//--#define HDMI_AFCR_tst_i2s_sw_mask                                     (0x00000080)
//--#define HDMI_AFCR_aoem_mask                                           (0x00000040)
//--#define HDMI_AFCR_aoc_mask                                            (0x00000020)
//--#define HDMI_AFCR_audio_test_enable_mask                              (0x00000010)
//--#define HDMI_AFCR_mgc_mask                                            (0x00000008)
//--#define HDMI_AFCR_afifowe_mask                                        (0x00000004)
//--#define HDMI_AFCR_afifore_mask                                        (0x00000003)
//--#define HDMI_AFCR_dummy1800d108_31_14(data)                           (0xFFFFC000&((data)<<14))
//--#define HDMI_AFCR_gain_bypass_en(data)                                (0x00002000&((data)<<13))
//--#define HDMI_AFCR_afifof(data)                                        (0x00001000&((data)<<12))
//--#define HDMI_AFCR_afifoe(data)                                        (0x00000800&((data)<<11))
//--#define HDMI_AFCR_afifowe_r(data)                                     (0x00000400&((data)<<10))
//--#define HDMI_AFCR_afifore_r(data)                                     (0x00000300&((data)<<8))
//--#define HDMI_AFCR_tst_i2s_sw(data)                                    (0x00000080&((data)<<7))
//--#define HDMI_AFCR_aoem(data)                                          (0x00000040&((data)<<6))
//--#define HDMI_AFCR_aoc(data)                                           (0x00000020&((data)<<5))
//--#define HDMI_AFCR_audio_test_enable(data)                             (0x00000010&((data)<<4))
//--#define HDMI_AFCR_mgc(data)                                           (0x00000008&((data)<<3))
//--#define HDMI_AFCR_afifowe(data)                                       (0x00000004&((data)<<2))
//--#define HDMI_AFCR_afifore(data)                                       (0x00000003&(data))
//--#define HDMI_AFCR_get_dummy1800d108_31_14(data)                       ((0xFFFFC000&(data))>>14)
//--#define HDMI_AFCR_get_gain_bypass_en(data)                            ((0x00002000&(data))>>13)
//--#define HDMI_AFCR_get_afifof(data)                                    ((0x00001000&(data))>>12)
//--#define HDMI_AFCR_get_afifoe(data)                                    ((0x00000800&(data))>>11)
//--#define HDMI_AFCR_get_afifowe_r(data)                                 ((0x00000400&(data))>>10)
//--#define HDMI_AFCR_get_afifore_r(data)                                 ((0x00000300&(data))>>8)
//--#define HDMI_AFCR_get_tst_i2s_sw(data)                                ((0x00000080&(data))>>7)
//--#define HDMI_AFCR_get_aoem(data)                                      ((0x00000040&(data))>>6)
//--#define HDMI_AFCR_get_aoc(data)                                       ((0x00000020&(data))>>5)
//--#define HDMI_AFCR_get_audio_test_enable(data)                         ((0x00000010&(data))>>4)
//--#define HDMI_AFCR_get_mgc(data)                                       ((0x00000008&(data))>>3)
//--#define HDMI_AFCR_get_afifowe(data)                                   ((0x00000004&(data))>>2)
//--#define HDMI_AFCR_get_afifore(data)                                   (0x00000003&(data))
//--
//--
//--#define HDMI_AFSR                                                     0x1800d10c
//--#define HDMI_AFSR_reg_addr                                            "0xb800d10c"
//--#define HDMI_AFSR_reg                                                 0xb800d10c
//--#define HDMI_AFSR_inst_addr                                           "0x0043"
//--#define HDMI_AFSR_inst                                                0x0043
//--#define set_HDMI_AFSR_reg(data)                                       (*((volatile unsigned int*)HDMI_AFSR_reg)=data)
//--#define get_HDMI_AFSR_reg                                             (*((volatile unsigned int*)HDMI_AFSR_reg))
//--#define HDMI_AFSR_audio_bist_clksel_shift                             (0)
//--#define HDMI_AFSR_audio_bist_clksel_mask                              (0x00000001)
//--#define HDMI_AFSR_audio_bist_clksel(data)                             (0x00000001&(data))
//--#define HDMI_AFSR_get_audio_bist_clksel(data)                         (0x00000001&(data))
//--
//--
//--#define HDMI_MAGCR0                                                   0x1800d110
//--#define HDMI_MAGCR0_reg_addr                                          "0xb800d110"
//--#define HDMI_MAGCR0_reg                                               0xb800d110
//--#define HDMI_MAGCR0_inst_addr                                         "0x0044"
//--#define HDMI_MAGCR0_inst                                              0x0044
//--#define set_HDMI_MAGCR0_reg(data)                                     (*((volatile unsigned int*)HDMI_MAGCR0_reg)=data)
//--#define get_HDMI_MAGCR0_reg                                           (*((volatile unsigned int*)HDMI_MAGCR0_reg))
//--#define HDMI_MAGCR0_agi_shift                                         (13)
//--#define HDMI_MAGCR0_agd_shift                                         (8)
//--#define HDMI_MAGCR0_mg_shift                                          (0)
//--#define HDMI_MAGCR0_agi_mask                                          (0x0000E000)
//--#define HDMI_MAGCR0_agd_mask                                          (0x00001F00)
//--#define HDMI_MAGCR0_mg_mask                                           (0x000000FF)
//--#define HDMI_MAGCR0_agi(data)                                         (0x0000E000&((data)<<13))
//--#define HDMI_MAGCR0_agd(data)                                         (0x00001F00&((data)<<8))
//--#define HDMI_MAGCR0_mg(data)                                          (0x000000FF&(data))
//--#define HDMI_MAGCR0_get_agi(data)                                     ((0x0000E000&(data))>>13)
//--#define HDMI_MAGCR0_get_agd(data)                                     ((0x00001F00&(data))>>8)
//--#define HDMI_MAGCR0_get_mg(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_MAG_M_FINAL                                              0x1800d114
//--#define HDMI_MAG_M_FINAL_reg_addr                                     "0xb800d114"
//--#define HDMI_MAG_M_FINAL_reg                                          0xb800d114
//--#define HDMI_MAG_M_FINAL_inst_addr                                    "0x0045"
//--#define HDMI_MAG_M_FINAL_inst                                         0x0045
//--#define set_HDMI_MAG_M_FINAL_reg(data)                                (*((volatile unsigned int*)HDMI_MAG_M_FINAL_reg)=data)
//--#define get_HDMI_MAG_M_FINAL_reg                                      (*((volatile unsigned int*)HDMI_MAG_M_FINAL_reg))
//--#define HDMI_MAG_M_FINAL_ldp_time_shift                               (21)
//--#define HDMI_MAG_M_FINAL_ldp_time_mode_shift                          (20)
//--#define HDMI_MAG_M_FINAL_fg_r_shift                                   (12)
//--#define HDMI_MAG_M_FINAL_fg_l_shift                                   (4)
//--#define HDMI_MAG_M_FINAL_auto_dly_mod_shift                           (3)
//--#define HDMI_MAG_M_FINAL_fg_en_shift                                  (2)
//--#define HDMI_MAG_M_FINAL_ffg_l_shift                                  (1)
//--#define HDMI_MAG_M_FINAL_ffg_r_shift                                  (0)
//--#define HDMI_MAG_M_FINAL_ldp_time_mask                                (0x7FE00000)
//--#define HDMI_MAG_M_FINAL_ldp_time_mode_mask                           (0x00100000)
//--#define HDMI_MAG_M_FINAL_fg_r_mask                                    (0x000FF000)
//--#define HDMI_MAG_M_FINAL_fg_l_mask                                    (0x00000FF0)
//--#define HDMI_MAG_M_FINAL_auto_dly_mod_mask                            (0x00000008)
//--#define HDMI_MAG_M_FINAL_fg_en_mask                                   (0x00000004)
//--#define HDMI_MAG_M_FINAL_ffg_l_mask                                   (0x00000002)
//--#define HDMI_MAG_M_FINAL_ffg_r_mask                                   (0x00000001)
//--#define HDMI_MAG_M_FINAL_ldp_time(data)                               (0x7FE00000&((data)<<21))
//--#define HDMI_MAG_M_FINAL_ldp_time_mode(data)                          (0x00100000&((data)<<20))
//--#define HDMI_MAG_M_FINAL_fg_r(data)                                   (0x000FF000&((data)<<12))
//--#define HDMI_MAG_M_FINAL_fg_l(data)                                   (0x00000FF0&((data)<<4))
//--#define HDMI_MAG_M_FINAL_auto_dly_mod(data)                           (0x00000008&((data)<<3))
//--#define HDMI_MAG_M_FINAL_fg_en(data)                                  (0x00000004&((data)<<2))
//--#define HDMI_MAG_M_FINAL_ffg_l(data)                                  (0x00000002&((data)<<1))
//--#define HDMI_MAG_M_FINAL_ffg_r(data)                                  (0x00000001&(data))
//--#define HDMI_MAG_M_FINAL_get_ldp_time(data)                           ((0x7FE00000&(data))>>21)
//--#define HDMI_MAG_M_FINAL_get_ldp_time_mode(data)                      ((0x00100000&(data))>>20)
//--#define HDMI_MAG_M_FINAL_get_fg_r(data)                               ((0x000FF000&(data))>>12)
//--#define HDMI_MAG_M_FINAL_get_fg_l(data)                               ((0x00000FF0&(data))>>4)
//--#define HDMI_MAG_M_FINAL_get_auto_dly_mod(data)                       ((0x00000008&(data))>>3)
//--#define HDMI_MAG_M_FINAL_get_fg_en(data)                              ((0x00000004&(data))>>2)
//--#define HDMI_MAG_M_FINAL_get_ffg_l(data)                              ((0x00000002&(data))>>1)
//--#define HDMI_MAG_M_FINAL_get_ffg_r(data)                              (0x00000001&(data))
//--
//--
//--#define ZCD_CTRL                                                      0x1800d118
//--#define ZCD_CTRL_reg_addr                                             "0xb800d118"
//--#define ZCD_CTRL_reg                                                  0xb800d118
//--#define ZCD_CTRL_inst_addr                                            "0x0046"
//--#define ZCD_CTRL_inst                                                 0x0046
//--#define set_ZCD_CTRL_reg(data)                                        (*((volatile unsigned int*)ZCD_CTRL_reg)=data)
//--#define get_ZCD_CTRL_reg                                              (*((volatile unsigned int*)ZCD_CTRL_reg))
//--#define ZCD_CTRL_zcd_ch7_done_shift                                   (23)
//--#define ZCD_CTRL_zcd_ch6_done_shift                                   (22)
//--#define ZCD_CTRL_zcd_ch5_done_shift                                   (21)
//--#define ZCD_CTRL_zcd_ch4_done_shift                                   (20)
//--#define ZCD_CTRL_zcd_ch3_done_shift                                   (19)
//--#define ZCD_CTRL_zcd_ch2_done_shift                                   (18)
//--#define ZCD_CTRL_zcd_ch1_done_shift                                   (17)
//--#define ZCD_CTRL_zcd_ch0_done_shift                                   (16)
//--#define ZCD_CTRL_zcd_timeout_shift                                    (8)
//--#define ZCD_CTRL_zcd_en_shift                                         (7)
//--#define ZCD_CTRL_zcd_sep_8ch_shift                                    (6)
//--#define ZCD_CTRL_zcd_sep_st_shift                                     (5)
//--#define ZCD_CTRL_dummy1800d118_4_0_shift                              (0)
//--#define ZCD_CTRL_zcd_ch7_done_mask                                    (0x00800000)
//--#define ZCD_CTRL_zcd_ch6_done_mask                                    (0x00400000)
//--#define ZCD_CTRL_zcd_ch5_done_mask                                    (0x00200000)
//--#define ZCD_CTRL_zcd_ch4_done_mask                                    (0x00100000)
//--#define ZCD_CTRL_zcd_ch3_done_mask                                    (0x00080000)
//--#define ZCD_CTRL_zcd_ch2_done_mask                                    (0x00040000)
//--#define ZCD_CTRL_zcd_ch1_done_mask                                    (0x00020000)
//--#define ZCD_CTRL_zcd_ch0_done_mask                                    (0x00010000)
//--#define ZCD_CTRL_zcd_timeout_mask                                     (0x00007F00)
//--#define ZCD_CTRL_zcd_en_mask                                          (0x00000080)
//--#define ZCD_CTRL_zcd_sep_8ch_mask                                     (0x00000040)
//--#define ZCD_CTRL_zcd_sep_st_mask                                      (0x00000020)
//--#define ZCD_CTRL_dummy1800d118_4_0_mask                               (0x0000001F)
//--#define ZCD_CTRL_zcd_ch7_done(data)                                   (0x00800000&((data)<<23))
//--#define ZCD_CTRL_zcd_ch6_done(data)                                   (0x00400000&((data)<<22))
//--#define ZCD_CTRL_zcd_ch5_done(data)                                   (0x00200000&((data)<<21))
//--#define ZCD_CTRL_zcd_ch4_done(data)                                   (0x00100000&((data)<<20))
//--#define ZCD_CTRL_zcd_ch3_done(data)                                   (0x00080000&((data)<<19))
//--#define ZCD_CTRL_zcd_ch2_done(data)                                   (0x00040000&((data)<<18))
//--#define ZCD_CTRL_zcd_ch1_done(data)                                   (0x00020000&((data)<<17))
//--#define ZCD_CTRL_zcd_ch0_done(data)                                   (0x00010000&((data)<<16))
//--#define ZCD_CTRL_zcd_timeout(data)                                    (0x00007F00&((data)<<8))
//--#define ZCD_CTRL_zcd_en(data)                                         (0x00000080&((data)<<7))
//--#define ZCD_CTRL_zcd_sep_8ch(data)                                    (0x00000040&((data)<<6))
//--#define ZCD_CTRL_zcd_sep_st(data)                                     (0x00000020&((data)<<5))
//--#define ZCD_CTRL_dummy1800d118_4_0(data)                              (0x0000001F&(data))
//--#define ZCD_CTRL_get_zcd_ch7_done(data)                               ((0x00800000&(data))>>23)
//--#define ZCD_CTRL_get_zcd_ch6_done(data)                               ((0x00400000&(data))>>22)
//--#define ZCD_CTRL_get_zcd_ch5_done(data)                               ((0x00200000&(data))>>21)
//--#define ZCD_CTRL_get_zcd_ch4_done(data)                               ((0x00100000&(data))>>20)
//--#define ZCD_CTRL_get_zcd_ch3_done(data)                               ((0x00080000&(data))>>19)
//--#define ZCD_CTRL_get_zcd_ch2_done(data)                               ((0x00040000&(data))>>18)
//--#define ZCD_CTRL_get_zcd_ch1_done(data)                               ((0x00020000&(data))>>17)
//--#define ZCD_CTRL_get_zcd_ch0_done(data)                               ((0x00010000&(data))>>16)
//--#define ZCD_CTRL_get_zcd_timeout(data)                                ((0x00007F00&(data))>>8)
//--#define ZCD_CTRL_get_zcd_en(data)                                     ((0x00000080&(data))>>7)
//--#define ZCD_CTRL_get_zcd_sep_8ch(data)                                ((0x00000040&(data))>>6)
//--#define ZCD_CTRL_get_zcd_sep_st(data)                                 ((0x00000020&(data))>>5)
//--#define ZCD_CTRL_get_dummy1800d118_4_0(data)                          (0x0000001F&(data))
//--
//--
//--#define AUDIO_FREQDET                                                 0x1800d11c
//--#define AUDIO_FREQDET_reg_addr                                        "0xb800d11c"
//--#define AUDIO_FREQDET_reg                                             0xb800d11c
//--#define AUDIO_FREQDET_inst_addr                                       "0x0047"
//--#define AUDIO_FREQDET_inst                                            0x0047
//--#define set_AUDIO_FREQDET_reg(data)                                   (*((volatile unsigned int*)AUDIO_FREQDET_reg)=data)
//--#define get_AUDIO_FREQDET_reg                                         (*((volatile unsigned int*)AUDIO_FREQDET_reg))
//--#define AUDIO_FREQDET_xtal_div_shift                                  (24)
//--#define AUDIO_FREQDET_afreq_meas_result_shift                         (12)
//--#define AUDIO_FREQDET_afreq_meas_range_shift                          (9)
//--#define AUDIO_FREQDET_popup_afreq_meas_result_shift                   (8)
//--#define AUDIO_FREQDET_audio_freq_detect_shift                         (7)
//--#define AUDIO_FREQDET_auto_load_scode_shift                           (6)
//--#define AUDIO_FREQDET_awd_by_freqchange_shift                         (5)
//--#define AUDIO_FREQDET_awd_by_noaudio_shift                            (4)
//--#define AUDIO_FREQDET_irq_by_freqchange_shift                         (3)
//--#define AUDIO_FREQDET_irq_by_noaudio_shift                            (2)
//--#define AUDIO_FREQDET_freqchange_shift                                (1)
//--#define AUDIO_FREQDET_noaudio_shift                                   (0)
//--#define AUDIO_FREQDET_xtal_div_mask                                   (0xFF000000)
//--#define AUDIO_FREQDET_afreq_meas_result_mask                          (0x00FFF000)
//--#define AUDIO_FREQDET_afreq_meas_range_mask                           (0x00000E00)
//--#define AUDIO_FREQDET_popup_afreq_meas_result_mask                    (0x00000100)
//--#define AUDIO_FREQDET_audio_freq_detect_mask                          (0x00000080)
//--#define AUDIO_FREQDET_auto_load_scode_mask                            (0x00000040)
//--#define AUDIO_FREQDET_awd_by_freqchange_mask                          (0x00000020)
//--#define AUDIO_FREQDET_awd_by_noaudio_mask                             (0x00000010)
//--#define AUDIO_FREQDET_irq_by_freqchange_mask                          (0x00000008)
//--#define AUDIO_FREQDET_irq_by_noaudio_mask                             (0x00000004)
//--#define AUDIO_FREQDET_freqchange_mask                                 (0x00000002)
//--#define AUDIO_FREQDET_noaudio_mask                                    (0x00000001)
//--#define AUDIO_FREQDET_xtal_div(data)                                  (0xFF000000&((data)<<24))
//--#define AUDIO_FREQDET_afreq_meas_result(data)                         (0x00FFF000&((data)<<12))
//--#define AUDIO_FREQDET_afreq_meas_range(data)                          (0x00000E00&((data)<<9))
//--#define AUDIO_FREQDET_popup_afreq_meas_result(data)                   (0x00000100&((data)<<8))
//--#define AUDIO_FREQDET_audio_freq_detect(data)                         (0x00000080&((data)<<7))
//--#define AUDIO_FREQDET_auto_load_scode(data)                           (0x00000040&((data)<<6))
//--#define AUDIO_FREQDET_awd_by_freqchange(data)                         (0x00000020&((data)<<5))
//--#define AUDIO_FREQDET_awd_by_noaudio(data)                            (0x00000010&((data)<<4))
//--#define AUDIO_FREQDET_irq_by_freqchange(data)                         (0x00000008&((data)<<3))
//--#define AUDIO_FREQDET_irq_by_noaudio(data)                            (0x00000004&((data)<<2))
//--#define AUDIO_FREQDET_freqchange(data)                                (0x00000002&((data)<<1))
//--#define AUDIO_FREQDET_noaudio(data)                                   (0x00000001&(data))
//--#define AUDIO_FREQDET_get_xtal_div(data)                              ((0xFF000000&(data))>>24)
//--#define AUDIO_FREQDET_get_afreq_meas_result(data)                     ((0x00FFF000&(data))>>12)
//--#define AUDIO_FREQDET_get_afreq_meas_range(data)                      ((0x00000E00&(data))>>9)
//--#define AUDIO_FREQDET_get_popup_afreq_meas_result(data)               ((0x00000100&(data))>>8)
//--#define AUDIO_FREQDET_get_audio_freq_detect(data)                     ((0x00000080&(data))>>7)
//--#define AUDIO_FREQDET_get_auto_load_scode(data)                       ((0x00000040&(data))>>6)
//--#define AUDIO_FREQDET_get_awd_by_freqchange(data)                     ((0x00000020&(data))>>5)
//--#define AUDIO_FREQDET_get_awd_by_noaudio(data)                        ((0x00000010&(data))>>4)
//--#define AUDIO_FREQDET_get_irq_by_freqchange(data)                     ((0x00000008&(data))>>3)
//--#define AUDIO_FREQDET_get_irq_by_noaudio(data)                        ((0x00000004&(data))>>2)
//--#define AUDIO_FREQDET_get_freqchange(data)                            ((0x00000002&(data))>>1)
//--#define AUDIO_FREQDET_get_noaudio(data)                               (0x00000001&(data))
//--
//--
//--#define RANGE0_1                                                      0x1800d120
//--#define RANGE0_1_reg_addr                                             "0xb800d120"
//--#define RANGE0_1_reg                                                  0xb800d120
//--#define RANGE0_1_inst_addr                                            "0x0048"
//--#define RANGE0_1_inst                                                 0x0048
//--#define set_RANGE0_1_reg(data)                                        (*((volatile unsigned int*)RANGE0_1_reg)=data)
//--#define get_RANGE0_1_reg                                              (*((volatile unsigned int*)RANGE0_1_reg))
//--#define RANGE0_1_range0_th_shift                                      (12)
//--#define RANGE0_1_range1_th_shift                                      (0)
//--#define RANGE0_1_range0_th_mask                                       (0x00FFF000)
//--#define RANGE0_1_range1_th_mask                                       (0x00000FFF)
//--#define RANGE0_1_range0_th(data)                                      (0x00FFF000&((data)<<12))
//--#define RANGE0_1_range1_th(data)                                      (0x00000FFF&(data))
//--#define RANGE0_1_get_range0_th(data)                                  ((0x00FFF000&(data))>>12)
//--#define RANGE0_1_get_range1_th(data)                                  (0x00000FFF&(data))
//--
//--
//--#define RANGE2_3                                                      0x1800d124
//--#define RANGE2_3_reg_addr                                             "0xb800d124"
//--#define RANGE2_3_reg                                                  0xb800d124
//--#define RANGE2_3_inst_addr                                            "0x0049"
//--#define RANGE2_3_inst                                                 0x0049
//--#define set_RANGE2_3_reg(data)                                        (*((volatile unsigned int*)RANGE2_3_reg)=data)
//--#define get_RANGE2_3_reg                                              (*((volatile unsigned int*)RANGE2_3_reg))
//--#define RANGE2_3_range2_th_shift                                      (12)
//--#define RANGE2_3_range3_th_shift                                      (0)
//--#define RANGE2_3_range2_th_mask                                       (0x00FFF000)
//--#define RANGE2_3_range3_th_mask                                       (0x00000FFF)
//--#define RANGE2_3_range2_th(data)                                      (0x00FFF000&((data)<<12))
//--#define RANGE2_3_range3_th(data)                                      (0x00000FFF&(data))
//--#define RANGE2_3_get_range2_th(data)                                  ((0x00FFF000&(data))>>12)
//--#define RANGE2_3_get_range3_th(data)                                  (0x00000FFF&(data))
//--
//--
//--#define RANGE4_5                                                      0x1800d128
//--#define RANGE4_5_reg_addr                                             "0xb800d128"
//--#define RANGE4_5_reg                                                  0xb800d128
//--#define RANGE4_5_inst_addr                                            "0x004A"
//--#define RANGE4_5_inst                                                 0x004A
//--#define set_RANGE4_5_reg(data)                                        (*((volatile unsigned int*)RANGE4_5_reg)=data)
//--#define get_RANGE4_5_reg                                              (*((volatile unsigned int*)RANGE4_5_reg))
//--#define RANGE4_5_range4_th_shift                                      (12)
//--#define RANGE4_5_range5_th_shift                                      (0)
//--#define RANGE4_5_range4_th_mask                                       (0x00FFF000)
//--#define RANGE4_5_range5_th_mask                                       (0x00000FFF)
//--#define RANGE4_5_range4_th(data)                                      (0x00FFF000&((data)<<12))
//--#define RANGE4_5_range5_th(data)                                      (0x00000FFF&(data))
//--#define RANGE4_5_get_range4_th(data)                                  ((0x00FFF000&(data))>>12)
//--#define RANGE4_5_get_range5_th(data)                                  (0x00000FFF&(data))
//--
//--
//--#define PRESET_S_CODE0                                                0x1800d12c
//--#define PRESET_S_CODE0_reg_addr                                       "0xb800d12c"
//--#define PRESET_S_CODE0_reg                                            0xb800d12c
//--#define PRESET_S_CODE0_inst_addr                                      "0x004B"
//--#define PRESET_S_CODE0_inst                                           0x004B
//--#define set_PRESET_S_CODE0_reg(data)                                  (*((volatile unsigned int*)PRESET_S_CODE0_reg)=data)
//--#define get_PRESET_S_CODE0_reg                                        (*((volatile unsigned int*)PRESET_S_CODE0_reg))
//--#define PRESET_S_CODE0_pre_set_s1_code3_shift                         (31)
//--#define PRESET_S_CODE0_pre_set_s_code3_shift                          (24)
//--#define PRESET_S_CODE0_pre_set_s1_code2_shift                         (23)
//--#define PRESET_S_CODE0_pre_set_s_code2_shift                          (16)
//--#define PRESET_S_CODE0_pre_set_s1_code1_shift                         (15)
//--#define PRESET_S_CODE0_pre_set_s_code1_shift                          (8)
//--#define PRESET_S_CODE0_pre_set_s1_code0_shift                         (7)
//--#define PRESET_S_CODE0_pre_set_s_code0_shift                          (0)
//--#define PRESET_S_CODE0_pre_set_s1_code3_mask                          (0x80000000)
//--#define PRESET_S_CODE0_pre_set_s_code3_mask                           (0x7F000000)
//--#define PRESET_S_CODE0_pre_set_s1_code2_mask                          (0x00800000)
//--#define PRESET_S_CODE0_pre_set_s_code2_mask                           (0x007F0000)
//--#define PRESET_S_CODE0_pre_set_s1_code1_mask                          (0x00008000)
//--#define PRESET_S_CODE0_pre_set_s_code1_mask                           (0x00007F00)
//--#define PRESET_S_CODE0_pre_set_s1_code0_mask                          (0x00000080)
//--#define PRESET_S_CODE0_pre_set_s_code0_mask                           (0x0000007F)
//--#define PRESET_S_CODE0_pre_set_s1_code3(data)                         (0x80000000&((data)<<31))
//--#define PRESET_S_CODE0_pre_set_s_code3(data)                          (0x7F000000&((data)<<24))
//--#define PRESET_S_CODE0_pre_set_s1_code2(data)                         (0x00800000&((data)<<23))
//--#define PRESET_S_CODE0_pre_set_s_code2(data)                          (0x007F0000&((data)<<16))
//--#define PRESET_S_CODE0_pre_set_s1_code1(data)                         (0x00008000&((data)<<15))
//--#define PRESET_S_CODE0_pre_set_s_code1(data)                          (0x00007F00&((data)<<8))
//--#define PRESET_S_CODE0_pre_set_s1_code0(data)                         (0x00000080&((data)<<7))
//--#define PRESET_S_CODE0_pre_set_s_code0(data)                          (0x0000007F&(data))
//--#define PRESET_S_CODE0_get_pre_set_s1_code3(data)                     ((0x80000000&(data))>>31)
//--#define PRESET_S_CODE0_get_pre_set_s_code3(data)                      ((0x7F000000&(data))>>24)
//--#define PRESET_S_CODE0_get_pre_set_s1_code2(data)                     ((0x00800000&(data))>>23)
//--#define PRESET_S_CODE0_get_pre_set_s_code2(data)                      ((0x007F0000&(data))>>16)
//--#define PRESET_S_CODE0_get_pre_set_s1_code1(data)                     ((0x00008000&(data))>>15)
//--#define PRESET_S_CODE0_get_pre_set_s_code1(data)                      ((0x00007F00&(data))>>8)
//--#define PRESET_S_CODE0_get_pre_set_s1_code0(data)                     ((0x00000080&(data))>>7)
//--#define PRESET_S_CODE0_get_pre_set_s_code0(data)                      (0x0000007F&(data))
//--
//--
//--#define PRESET_S_CODE1                                                0x1800d130
//--#define PRESET_S_CODE1_reg_addr                                       "0xb800d130"
//--#define PRESET_S_CODE1_reg                                            0xb800d130
//--#define PRESET_S_CODE1_inst_addr                                      "0x004C"
//--#define PRESET_S_CODE1_inst                                           0x004C
//--#define set_PRESET_S_CODE1_reg(data)                                  (*((volatile unsigned int*)PRESET_S_CODE1_reg)=data)
//--#define get_PRESET_S_CODE1_reg                                        (*((volatile unsigned int*)PRESET_S_CODE1_reg))
//--#define PRESET_S_CODE1_dp_abuf_wr_mod_en_shift                        (23)
//--#define PRESET_S_CODE1_auto_stop_trk_en_shift                         (22)
//--#define PRESET_S_CODE1_trk_mod_en_shift                               (21)
//--#define PRESET_S_CODE1_afsm_mod_en_shift                              (20)
//--#define PRESET_S_CODE1_pre_set_sm_code0_shift                         (15)
//--#define PRESET_S_CODE1_pre_set_sm_code1_shift                         (14)
//--#define PRESET_S_CODE1_pre_set_sm_code2_shift                         (13)
//--#define PRESET_S_CODE1_pre_set_sm_code3_shift                         (12)
//--#define PRESET_S_CODE1_pre_set_sm_code4_shift                         (11)
//--#define PRESET_S_CODE1_pre_set_s1_code4_shift                         (7)
//--#define PRESET_S_CODE1_pre_set_s_code4_shift                          (0)
//--#define PRESET_S_CODE1_dp_abuf_wr_mod_en_mask                         (0x00800000)
//--#define PRESET_S_CODE1_auto_stop_trk_en_mask                          (0x00400000)
//--#define PRESET_S_CODE1_trk_mod_en_mask                                (0x00200000)
//--#define PRESET_S_CODE1_afsm_mod_en_mask                               (0x00100000)
//--#define PRESET_S_CODE1_pre_set_sm_code0_mask                          (0x00008000)
//--#define PRESET_S_CODE1_pre_set_sm_code1_mask                          (0x00004000)
//--#define PRESET_S_CODE1_pre_set_sm_code2_mask                          (0x00002000)
//--#define PRESET_S_CODE1_pre_set_sm_code3_mask                          (0x00001000)
//--#define PRESET_S_CODE1_pre_set_sm_code4_mask                          (0x00000800)
//--#define PRESET_S_CODE1_pre_set_s1_code4_mask                          (0x00000080)
//--#define PRESET_S_CODE1_pre_set_s_code4_mask                           (0x0000007F)
//--#define PRESET_S_CODE1_dp_abuf_wr_mod_en(data)                        (0x00800000&((data)<<23))
//--#define PRESET_S_CODE1_auto_stop_trk_en(data)                         (0x00400000&((data)<<22))
//--#define PRESET_S_CODE1_trk_mod_en(data)                               (0x00200000&((data)<<21))
//--#define PRESET_S_CODE1_afsm_mod_en(data)                              (0x00100000&((data)<<20))
//--#define PRESET_S_CODE1_pre_set_sm_code0(data)                         (0x00008000&((data)<<15))
//--#define PRESET_S_CODE1_pre_set_sm_code1(data)                         (0x00004000&((data)<<14))
//--#define PRESET_S_CODE1_pre_set_sm_code2(data)                         (0x00002000&((data)<<13))
//--#define PRESET_S_CODE1_pre_set_sm_code3(data)                         (0x00001000&((data)<<12))
//--#define PRESET_S_CODE1_pre_set_sm_code4(data)                         (0x00000800&((data)<<11))
//--#define PRESET_S_CODE1_pre_set_s1_code4(data)                         (0x00000080&((data)<<7))
//--#define PRESET_S_CODE1_pre_set_s_code4(data)                          (0x0000007F&(data))
//--#define PRESET_S_CODE1_get_dp_abuf_wr_mod_en(data)                    ((0x00800000&(data))>>23)
//--#define PRESET_S_CODE1_get_auto_stop_trk_en(data)                     ((0x00400000&(data))>>22)
//--#define PRESET_S_CODE1_get_trk_mod_en(data)                           ((0x00200000&(data))>>21)
//--#define PRESET_S_CODE1_get_afsm_mod_en(data)                          ((0x00100000&(data))>>20)
//--#define PRESET_S_CODE1_get_pre_set_sm_code0(data)                     ((0x00008000&(data))>>15)
//--#define PRESET_S_CODE1_get_pre_set_sm_code1(data)                     ((0x00004000&(data))>>14)
//--#define PRESET_S_CODE1_get_pre_set_sm_code2(data)                     ((0x00002000&(data))>>13)
//--#define PRESET_S_CODE1_get_pre_set_sm_code3(data)                     ((0x00001000&(data))>>12)
//--#define PRESET_S_CODE1_get_pre_set_sm_code4(data)                     ((0x00000800&(data))>>11)
//--#define PRESET_S_CODE1_get_pre_set_s1_code4(data)                     ((0x00000080&(data))>>7)
//--#define PRESET_S_CODE1_get_pre_set_s_code4(data)                      (0x0000007F&(data))
//--
//--
//--#define PRBS7_R_CTRL                                                  0x1800d134
//--#define PRBS7_R_CTRL_reg_addr                                         "0xb800d134"
//--#define PRBS7_R_CTRL_reg                                              0xb800d134
//--#define PRBS7_R_CTRL_inst_addr                                        "0x004D"
//--#define PRBS7_R_CTRL_inst                                             0x004D
//--#define set_PRBS7_R_CTRL_reg(data)                                    (*((volatile unsigned int*)PRBS7_R_CTRL_reg)=data)
//--#define get_PRBS7_R_CTRL_reg                                          (*((volatile unsigned int*)PRBS7_R_CTRL_reg))
//--#define PRBS7_R_CTRL_prbs7_rxbist_err_cnt_shift                       (20)
//--#define PRBS7_R_CTRL_prbs7_err_cnt_shift                              (16)
//--#define PRBS7_R_CTRL_prbs7_bit_err_shift                              (4)
//--#define PRBS7_R_CTRL_prbs7_lock_shift                                 (3)
//--#define PRBS7_R_CTRL_prbs7_err_cnt_clr_shift                          (2)
//--#define PRBS7_R_CTRL_prbs7_reverse_shift                              (1)
//--#define PRBS7_R_CTRL_prbs7_rxen_shift                                 (0)
//--#define PRBS7_R_CTRL_prbs7_rxbist_err_cnt_mask                        (0x0FF00000)
//--#define PRBS7_R_CTRL_prbs7_err_cnt_mask                               (0x000F0000)
//--#define PRBS7_R_CTRL_prbs7_bit_err_mask                               (0x00003FF0)
//--#define PRBS7_R_CTRL_prbs7_lock_mask                                  (0x00000008)
//--#define PRBS7_R_CTRL_prbs7_err_cnt_clr_mask                           (0x00000004)
//--#define PRBS7_R_CTRL_prbs7_reverse_mask                               (0x00000002)
//--#define PRBS7_R_CTRL_prbs7_rxen_mask                                  (0x00000001)
//--#define PRBS7_R_CTRL_prbs7_rxbist_err_cnt(data)                       (0x0FF00000&((data)<<20))
//--#define PRBS7_R_CTRL_prbs7_err_cnt(data)                              (0x000F0000&((data)<<16))
//--#define PRBS7_R_CTRL_prbs7_bit_err(data)                              (0x00003FF0&((data)<<4))
//--#define PRBS7_R_CTRL_prbs7_lock(data)                                 (0x00000008&((data)<<3))
//--#define PRBS7_R_CTRL_prbs7_err_cnt_clr(data)                          (0x00000004&((data)<<2))
//--#define PRBS7_R_CTRL_prbs7_reverse(data)                              (0x00000002&((data)<<1))
//--#define PRBS7_R_CTRL_prbs7_rxen(data)                                 (0x00000001&(data))
//--#define PRBS7_R_CTRL_get_prbs7_rxbist_err_cnt(data)                   ((0x0FF00000&(data))>>20)
//--#define PRBS7_R_CTRL_get_prbs7_err_cnt(data)                          ((0x000F0000&(data))>>16)
//--#define PRBS7_R_CTRL_get_prbs7_bit_err(data)                          ((0x00003FF0&(data))>>4)
//--#define PRBS7_R_CTRL_get_prbs7_lock(data)                             ((0x00000008&(data))>>3)
//--#define PRBS7_R_CTRL_get_prbs7_err_cnt_clr(data)                      ((0x00000004&(data))>>2)
//--#define PRBS7_R_CTRL_get_prbs7_reverse(data)                          ((0x00000002&(data))>>1)
//--#define PRBS7_R_CTRL_get_prbs7_rxen(data)                             (0x00000001&(data))
//--
//--
//--#define PRBS7_G_CTRL                                                  0x1800d138
//--#define PRBS7_G_CTRL_reg_addr                                         "0xb800d138"
//--#define PRBS7_G_CTRL_reg                                              0xb800d138
//--#define PRBS7_G_CTRL_inst_addr                                        "0x004E"
//--#define PRBS7_G_CTRL_inst                                             0x004E
//--#define set_PRBS7_G_CTRL_reg(data)                                    (*((volatile unsigned int*)PRBS7_G_CTRL_reg)=data)
//--#define get_PRBS7_G_CTRL_reg                                          (*((volatile unsigned int*)PRBS7_G_CTRL_reg))
//--#define PRBS7_G_CTRL_prbs7_rxbist_err_cnt_shift                       (20)
//--#define PRBS7_G_CTRL_prbs7_err_cnt_shift                              (16)
//--#define PRBS7_G_CTRL_prbs7_bit_err_shift                              (4)
//--#define PRBS7_G_CTRL_prbs7_lock_shift                                 (3)
//--#define PRBS7_G_CTRL_prbs7_err_cnt_clr_shift                          (2)
//--#define PRBS7_G_CTRL_prbs7_reverse_shift                              (1)
//--#define PRBS7_G_CTRL_prbs7_rxen_shift                                 (0)
//--#define PRBS7_G_CTRL_prbs7_rxbist_err_cnt_mask                        (0x0FF00000)
//--#define PRBS7_G_CTRL_prbs7_err_cnt_mask                               (0x000F0000)
//--#define PRBS7_G_CTRL_prbs7_bit_err_mask                               (0x00003FF0)
//--#define PRBS7_G_CTRL_prbs7_lock_mask                                  (0x00000008)
//--#define PRBS7_G_CTRL_prbs7_err_cnt_clr_mask                           (0x00000004)
//--#define PRBS7_G_CTRL_prbs7_reverse_mask                               (0x00000002)
//--#define PRBS7_G_CTRL_prbs7_rxen_mask                                  (0x00000001)
//--#define PRBS7_G_CTRL_prbs7_rxbist_err_cnt(data)                       (0x0FF00000&((data)<<20))
//--#define PRBS7_G_CTRL_prbs7_err_cnt(data)                              (0x000F0000&((data)<<16))
//--#define PRBS7_G_CTRL_prbs7_bit_err(data)                              (0x00003FF0&((data)<<4))
//--#define PRBS7_G_CTRL_prbs7_lock(data)                                 (0x00000008&((data)<<3))
//--#define PRBS7_G_CTRL_prbs7_err_cnt_clr(data)                          (0x00000004&((data)<<2))
//--#define PRBS7_G_CTRL_prbs7_reverse(data)                              (0x00000002&((data)<<1))
//--#define PRBS7_G_CTRL_prbs7_rxen(data)                                 (0x00000001&(data))
//--#define PRBS7_G_CTRL_get_prbs7_rxbist_err_cnt(data)                   ((0x0FF00000&(data))>>20)
//--#define PRBS7_G_CTRL_get_prbs7_err_cnt(data)                          ((0x000F0000&(data))>>16)
//--#define PRBS7_G_CTRL_get_prbs7_bit_err(data)                          ((0x00003FF0&(data))>>4)
//--#define PRBS7_G_CTRL_get_prbs7_lock(data)                             ((0x00000008&(data))>>3)
//--#define PRBS7_G_CTRL_get_prbs7_err_cnt_clr(data)                      ((0x00000004&(data))>>2)
//--#define PRBS7_G_CTRL_get_prbs7_reverse(data)                          ((0x00000002&(data))>>1)
//--#define PRBS7_G_CTRL_get_prbs7_rxen(data)                             (0x00000001&(data))
//--
//--
//--#define PRBS7_B_CTRL                                                  0x1800d13c
//--#define PRBS7_B_CTRL_reg_addr                                         "0xb800d13c"
//--#define PRBS7_B_CTRL_reg                                              0xb800d13c
//--#define PRBS7_B_CTRL_inst_addr                                        "0x004F"
//--#define PRBS7_B_CTRL_inst                                             0x004F
//--#define set_PRBS7_B_CTRL_reg(data)                                    (*((volatile unsigned int*)PRBS7_B_CTRL_reg)=data)
//--#define get_PRBS7_B_CTRL_reg                                          (*((volatile unsigned int*)PRBS7_B_CTRL_reg))
//--#define PRBS7_B_CTRL_prbs7_rxbist_err_cnt_shift                       (20)
//--#define PRBS7_B_CTRL_prbs7_err_cnt_shift                              (16)
//--#define PRBS7_B_CTRL_prbs7_bit_err_shift                              (4)
//--#define PRBS7_B_CTRL_prbs7_lock_shift                                 (3)
//--#define PRBS7_B_CTRL_prbs7_err_cnt_clr_shift                          (2)
//--#define PRBS7_B_CTRL_prbs7_reverse_shift                              (1)
//--#define PRBS7_B_CTRL_prbs7_rxen_shift                                 (0)
//--#define PRBS7_B_CTRL_prbs7_rxbist_err_cnt_mask                        (0x0FF00000)
//--#define PRBS7_B_CTRL_prbs7_err_cnt_mask                               (0x000F0000)
//--#define PRBS7_B_CTRL_prbs7_bit_err_mask                               (0x00003FF0)
//--#define PRBS7_B_CTRL_prbs7_lock_mask                                  (0x00000008)
//--#define PRBS7_B_CTRL_prbs7_err_cnt_clr_mask                           (0x00000004)
//--#define PRBS7_B_CTRL_prbs7_reverse_mask                               (0x00000002)
//--#define PRBS7_B_CTRL_prbs7_rxen_mask                                  (0x00000001)
//--#define PRBS7_B_CTRL_prbs7_rxbist_err_cnt(data)                       (0x0FF00000&((data)<<20))
//--#define PRBS7_B_CTRL_prbs7_err_cnt(data)                              (0x000F0000&((data)<<16))
//--#define PRBS7_B_CTRL_prbs7_bit_err(data)                              (0x00003FF0&((data)<<4))
//--#define PRBS7_B_CTRL_prbs7_lock(data)                                 (0x00000008&((data)<<3))
//--#define PRBS7_B_CTRL_prbs7_err_cnt_clr(data)                          (0x00000004&((data)<<2))
//--#define PRBS7_B_CTRL_prbs7_reverse(data)                              (0x00000002&((data)<<1))
//--#define PRBS7_B_CTRL_prbs7_rxen(data)                                 (0x00000001&(data))
//--#define PRBS7_B_CTRL_get_prbs7_rxbist_err_cnt(data)                   ((0x0FF00000&(data))>>20)
//--#define PRBS7_B_CTRL_get_prbs7_err_cnt(data)                          ((0x000F0000&(data))>>16)
//--#define PRBS7_B_CTRL_get_prbs7_bit_err(data)                          ((0x00003FF0&(data))>>4)
//--#define PRBS7_B_CTRL_get_prbs7_lock(data)                             ((0x00000008&(data))>>3)
//--#define PRBS7_B_CTRL_get_prbs7_err_cnt_clr(data)                      ((0x00000004&(data))>>2)
//--#define PRBS7_B_CTRL_get_prbs7_reverse(data)                          ((0x00000002&(data))>>1)
//--#define PRBS7_B_CTRL_get_prbs7_rxen(data)                             (0x00000001&(data))
//--
//--
//--#define HDMI_LEADING_GB_CMP_CTRL                                      0x1800d140
//--#define HDMI_LEADING_GB_CMP_CTRL_reg_addr                             "0xb800d140"
//--#define HDMI_LEADING_GB_CMP_CTRL_reg                                  0xb800d140
//--#define HDMI_LEADING_GB_CMP_CTRL_inst_addr                            "0x0050"
//--#define HDMI_LEADING_GB_CMP_CTRL_inst                                 0x0050
//--#define set_HDMI_LEADING_GB_CMP_CTRL_reg(data)                        (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_CTRL_reg)=data)
//--#define get_HDMI_LEADING_GB_CMP_CTRL_reg                              (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_CTRL_reg))
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_flag_shift                   (30)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_wd_en_shift                  (29)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_int_en_shift                 (28)
//--#define HDMI_LEADING_GB_CMP_CTRL_preamble_shift                       (24)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_value_shift                      (8)
//--#define HDMI_LEADING_GB_CMP_CTRL_dvi_mode_sel_shift                   (4)
//--#define HDMI_LEADING_GB_CMP_CTRL_channel_sel_shift                    (2)
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_conti_shift                  (1)
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_en_shift                     (0)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_flag_mask                    (0x40000000)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_wd_en_mask                   (0x20000000)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_int_en_mask                  (0x10000000)
//--#define HDMI_LEADING_GB_CMP_CTRL_preamble_mask                        (0x0F000000)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_value_mask                       (0x0003FF00)
//--#define HDMI_LEADING_GB_CMP_CTRL_dvi_mode_sel_mask                    (0x00000010)
//--#define HDMI_LEADING_GB_CMP_CTRL_channel_sel_mask                     (0x0000000C)
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_conti_mask                   (0x00000002)
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_en_mask                      (0x00000001)
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_flag(data)                   (0x40000000&((data)<<30))
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_wd_en(data)                  (0x20000000&((data)<<29))
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_err_int_en(data)                 (0x10000000&((data)<<28))
//--#define HDMI_LEADING_GB_CMP_CTRL_preamble(data)                       (0x0F000000&((data)<<24))
//--#define HDMI_LEADING_GB_CMP_CTRL_cmp_value(data)                      (0x0003FF00&((data)<<8))
//--#define HDMI_LEADING_GB_CMP_CTRL_dvi_mode_sel(data)                   (0x00000010&((data)<<4))
//--#define HDMI_LEADING_GB_CMP_CTRL_channel_sel(data)                    (0x0000000C&((data)<<2))
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_conti(data)                  (0x00000002&((data)<<1))
//--#define HDMI_LEADING_GB_CMP_CTRL_lgb_cal_en(data)                     (0x00000001&(data))
//--#define HDMI_LEADING_GB_CMP_CTRL_get_cmp_err_flag(data)               ((0x40000000&(data))>>30)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_cmp_err_wd_en(data)              ((0x20000000&(data))>>29)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_cmp_err_int_en(data)             ((0x10000000&(data))>>28)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_preamble(data)                   ((0x0F000000&(data))>>24)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_cmp_value(data)                  ((0x0003FF00&(data))>>8)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_dvi_mode_sel(data)               ((0x00000010&(data))>>4)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_channel_sel(data)                ((0x0000000C&(data))>>2)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_lgb_cal_conti(data)              ((0x00000002&(data))>>1)
//--#define HDMI_LEADING_GB_CMP_CTRL_get_lgb_cal_en(data)                 (0x00000001&(data))
//--
//--
//--#define HDMI_LEADING_GB_CMP_TIMES                                     0x1800d144
//--#define HDMI_LEADING_GB_CMP_TIMES_reg_addr                            "0xb800d144"
//--#define HDMI_LEADING_GB_CMP_TIMES_reg                                 0xb800d144
//--#define HDMI_LEADING_GB_CMP_TIMES_inst_addr                           "0x0051"
//--#define HDMI_LEADING_GB_CMP_TIMES_inst                                0x0051
//--#define set_HDMI_LEADING_GB_CMP_TIMES_reg(data)                       (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_TIMES_reg)=data)
//--#define get_HDMI_LEADING_GB_CMP_TIMES_reg                             (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_TIMES_reg))
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_err_cnt_shift                   (16)
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_times_shift                     (0)
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_err_cnt_mask                    (0xFFFF0000)
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_times_mask                      (0x0000FFFF)
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_err_cnt(data)                   (0xFFFF0000&((data)<<16))
//--#define HDMI_LEADING_GB_CMP_TIMES_cmp_times(data)                     (0x0000FFFF&(data))
//--#define HDMI_LEADING_GB_CMP_TIMES_get_cmp_err_cnt(data)               ((0xFFFF0000&(data))>>16)
//--#define HDMI_LEADING_GB_CMP_TIMES_get_cmp_times(data)                 (0x0000FFFF&(data))
//--
//--
//--#define HDMI_LEADING_GB_CMP_CNT                                       0x1800d148
//--#define HDMI_LEADING_GB_CMP_CNT_reg_addr                              "0xb800d148"
//--#define HDMI_LEADING_GB_CMP_CNT_reg                                   0xb800d148
//--#define HDMI_LEADING_GB_CMP_CNT_inst_addr                             "0x0052"
//--#define HDMI_LEADING_GB_CMP_CNT_inst                                  0x0052
//--#define set_HDMI_LEADING_GB_CMP_CNT_reg(data)                         (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_CNT_reg)=data)
//--#define get_HDMI_LEADING_GB_CMP_CNT_reg                               (*((volatile unsigned int*)HDMI_LEADING_GB_CMP_CNT_reg))
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt_shift                (16)
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt_by_frame_shift       (0)
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt_mask                 (0xFFFF0000)
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt_by_frame_mask        (0x0000FFFF)
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt(data)                (0xFFFF0000&((data)<<16))
//--#define HDMI_LEADING_GB_CMP_CNT_preamble_cmp_cnt_by_frame(data)       (0x0000FFFF&(data))
//--#define HDMI_LEADING_GB_CMP_CNT_get_preamble_cmp_cnt(data)            ((0xFFFF0000&(data))>>16)
//--#define HDMI_LEADING_GB_CMP_CNT_get_preamble_cmp_cnt_by_frame(data)   (0x0000FFFF&(data))
//--
//--
//--#define AUDIO_CTS_UP_BOUND                                            0x1800d14c
//--#define AUDIO_CTS_UP_BOUND_reg_addr                                   "0xb800d14c"
//--#define AUDIO_CTS_UP_BOUND_reg                                        0xb800d14c
//--#define AUDIO_CTS_UP_BOUND_inst_addr                                  "0x0053"
//--#define AUDIO_CTS_UP_BOUND_inst                                       0x0053
//--#define set_AUDIO_CTS_UP_BOUND_reg(data)                              (*((volatile unsigned int*)AUDIO_CTS_UP_BOUND_reg)=data)
//--#define get_AUDIO_CTS_UP_BOUND_reg                                    (*((volatile unsigned int*)AUDIO_CTS_UP_BOUND_reg))
//--#define AUDIO_CTS_UP_BOUND_cts_over_flag_shift                        (31)
//--#define AUDIO_CTS_UP_BOUND_cts_clip_en_shift                          (20)
//--#define AUDIO_CTS_UP_BOUND_cts_up_bound_shift                         (0)
//--#define AUDIO_CTS_UP_BOUND_cts_over_flag_mask                         (0x80000000)
//--#define AUDIO_CTS_UP_BOUND_cts_clip_en_mask                           (0x00100000)
//--#define AUDIO_CTS_UP_BOUND_cts_up_bound_mask                          (0x000FFFFF)
//--#define AUDIO_CTS_UP_BOUND_cts_over_flag(data)                        (0x80000000&((data)<<31))
//--#define AUDIO_CTS_UP_BOUND_cts_clip_en(data)                          (0x00100000&((data)<<20))
//--#define AUDIO_CTS_UP_BOUND_cts_up_bound(data)                         (0x000FFFFF&(data))
//--#define AUDIO_CTS_UP_BOUND_get_cts_over_flag(data)                    ((0x80000000&(data))>>31)
//--#define AUDIO_CTS_UP_BOUND_get_cts_clip_en(data)                      ((0x00100000&(data))>>20)
//--#define AUDIO_CTS_UP_BOUND_get_cts_up_bound(data)                     (0x000FFFFF&(data))
//--
//--
//--#define AUDIO_CTS_LOW_BOUND                                           0x1800d150
//--#define AUDIO_CTS_LOW_BOUND_reg_addr                                  "0xb800d150"
//--#define AUDIO_CTS_LOW_BOUND_reg                                       0xb800d150
//--#define AUDIO_CTS_LOW_BOUND_inst_addr                                 "0x0054"
//--#define AUDIO_CTS_LOW_BOUND_inst                                      0x0054
//--#define set_AUDIO_CTS_LOW_BOUND_reg(data)                             (*((volatile unsigned int*)AUDIO_CTS_LOW_BOUND_reg)=data)
//--#define get_AUDIO_CTS_LOW_BOUND_reg                                   (*((volatile unsigned int*)AUDIO_CTS_LOW_BOUND_reg))
//--#define AUDIO_CTS_LOW_BOUND_cts_under_flag_shift                      (31)
//--#define AUDIO_CTS_LOW_BOUND_cts_low_bound_shift                       (0)
//--#define AUDIO_CTS_LOW_BOUND_cts_under_flag_mask                       (0x80000000)
//--#define AUDIO_CTS_LOW_BOUND_cts_low_bound_mask                        (0x000FFFFF)
//--#define AUDIO_CTS_LOW_BOUND_cts_under_flag(data)                      (0x80000000&((data)<<31))
//--#define AUDIO_CTS_LOW_BOUND_cts_low_bound(data)                       (0x000FFFFF&(data))
//--#define AUDIO_CTS_LOW_BOUND_get_cts_under_flag(data)                  ((0x80000000&(data))>>31)
//--#define AUDIO_CTS_LOW_BOUND_get_cts_low_bound(data)                   (0x000FFFFF&(data))
//--
//--
//--#define AUDIO_N_UP_BOUND                                              0x1800d154
//--#define AUDIO_N_UP_BOUND_reg_addr                                     "0xb800d154"
//--#define AUDIO_N_UP_BOUND_reg                                          0xb800d154
//--#define AUDIO_N_UP_BOUND_inst_addr                                    "0x0055"
//--#define AUDIO_N_UP_BOUND_inst                                         0x0055
//--#define set_AUDIO_N_UP_BOUND_reg(data)                                (*((volatile unsigned int*)AUDIO_N_UP_BOUND_reg)=data)
//--#define get_AUDIO_N_UP_BOUND_reg                                      (*((volatile unsigned int*)AUDIO_N_UP_BOUND_reg))
//--#define AUDIO_N_UP_BOUND_n_over_flag_shift                            (31)
//--#define AUDIO_N_UP_BOUND_n_clip_en_shift                              (20)
//--#define AUDIO_N_UP_BOUND_n_up_bound_shift                             (0)
//--#define AUDIO_N_UP_BOUND_n_over_flag_mask                             (0x80000000)
//--#define AUDIO_N_UP_BOUND_n_clip_en_mask                               (0x00100000)
//--#define AUDIO_N_UP_BOUND_n_up_bound_mask                              (0x000FFFFF)
//--#define AUDIO_N_UP_BOUND_n_over_flag(data)                            (0x80000000&((data)<<31))
//--#define AUDIO_N_UP_BOUND_n_clip_en(data)                              (0x00100000&((data)<<20))
//--#define AUDIO_N_UP_BOUND_n_up_bound(data)                             (0x000FFFFF&(data))
//--#define AUDIO_N_UP_BOUND_get_n_over_flag(data)                        ((0x80000000&(data))>>31)
//--#define AUDIO_N_UP_BOUND_get_n_clip_en(data)                          ((0x00100000&(data))>>20)
//--#define AUDIO_N_UP_BOUND_get_n_up_bound(data)                         (0x000FFFFF&(data))
//--
//--
//--#define AUDIO_N_LOW_BOUND                                             0x1800d158
//--#define AUDIO_N_LOW_BOUND_reg_addr                                    "0xb800d158"
//--#define AUDIO_N_LOW_BOUND_reg                                         0xb800d158
//--#define AUDIO_N_LOW_BOUND_inst_addr                                   "0x0056"
//--#define AUDIO_N_LOW_BOUND_inst                                        0x0056
//--#define set_AUDIO_N_LOW_BOUND_reg(data)                               (*((volatile unsigned int*)AUDIO_N_LOW_BOUND_reg)=data)
//--#define get_AUDIO_N_LOW_BOUND_reg                                     (*((volatile unsigned int*)AUDIO_N_LOW_BOUND_reg))
//--#define AUDIO_N_LOW_BOUND_n_under_flag_shift                          (31)
//--#define AUDIO_N_LOW_BOUND_n_low_bound_shift                           (0)
//--#define AUDIO_N_LOW_BOUND_n_under_flag_mask                           (0x80000000)
//--#define AUDIO_N_LOW_BOUND_n_low_bound_mask                            (0x000FFFFF)
//--#define AUDIO_N_LOW_BOUND_n_under_flag(data)                          (0x80000000&((data)<<31))
//--#define AUDIO_N_LOW_BOUND_n_low_bound(data)                           (0x000FFFFF&(data))
//--#define AUDIO_N_LOW_BOUND_get_n_under_flag(data)                      ((0x80000000&(data))>>31)
//--#define AUDIO_N_LOW_BOUND_get_n_low_bound(data)                       (0x000FFFFF&(data))
//--
//--
//--#define MHL_HDMI_MAC_CTRL                                             0x1800d15c
//--#define MHL_HDMI_MAC_CTRL_reg_addr                                    "0xb800d15c"
//--#define MHL_HDMI_MAC_CTRL_reg                                         0xb800d15c
//--#define MHL_HDMI_MAC_CTRL_inst_addr                                   "0x0057"
//--#define MHL_HDMI_MAC_CTRL_inst                                        0x0057
//--#define set_MHL_HDMI_MAC_CTRL_reg(data)                               (*((volatile unsigned int*)MHL_HDMI_MAC_CTRL_reg)=data)
//--#define get_MHL_HDMI_MAC_CTRL_reg                                     (*((volatile unsigned int*)MHL_HDMI_MAC_CTRL_reg))
//--#define MHL_HDMI_MAC_CTRL_pp_mode_output_shift                        (12)
//--#define MHL_HDMI_MAC_CTRL_packet_mhl_en_shift                         (8)
//--#define MHL_HDMI_MAC_CTRL_xor_pixel_sel_shift                         (5)
//--#define MHL_HDMI_MAC_CTRL_cal_pixel_sel_shift                         (4)
//--#define MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_shift                     (0)
//--#define MHL_HDMI_MAC_CTRL_pp_mode_output_mask                         (0x00001000)
//--#define MHL_HDMI_MAC_CTRL_packet_mhl_en_mask                          (0x00000100)
//--#define MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask                          (0x000000E0)
//--#define MHL_HDMI_MAC_CTRL_cal_pixel_sel_mask                          (0x00000010)
//--#define MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask                      (0x00000001)
//--#define MHL_HDMI_MAC_CTRL_pp_mode_output(data)                        (0x00001000&((data)<<12))
//--#define MHL_HDMI_MAC_CTRL_packet_mhl_en(data)                         (0x00000100&((data)<<8))
//--#define MHL_HDMI_MAC_CTRL_xor_pixel_sel(data)                         (0x000000E0&((data)<<5))
//--#define MHL_HDMI_MAC_CTRL_cal_pixel_sel(data)                         (0x00000010&((data)<<4))
//--#define MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en(data)                     (0x00000001&(data))
//--#define MHL_HDMI_MAC_CTRL_get_pp_mode_output(data)                    ((0x00001000&(data))>>12)
//--#define MHL_HDMI_MAC_CTRL_get_packet_mhl_en(data)                     ((0x00000100&(data))>>8)
//--#define MHL_HDMI_MAC_CTRL_get_xor_pixel_sel(data)                     ((0x000000E0&(data))>>5)
//--#define MHL_HDMI_MAC_CTRL_get_cal_pixel_sel(data)                     ((0x00000010&(data))>>4)
//--#define MHL_HDMI_MAC_CTRL_get_ch_dec_pp_mode_en(data)                 (0x00000001&(data))
//--
//--
//--#define MHL_3D_FORMAT                                                 0x1800d160
//--#define MHL_3D_FORMAT_reg_addr                                        "0xb800d160"
//--#define MHL_3D_FORMAT_reg                                             0xb800d160
//--#define MHL_3D_FORMAT_inst_addr                                       "0x0058"
//--#define MHL_3D_FORMAT_inst                                            0x0058
//--#define set_MHL_3D_FORMAT_reg(data)                                   (*((volatile unsigned int*)MHL_3D_FORMAT_reg)=data)
//--#define get_MHL_3D_FORMAT_reg                                         (*((volatile unsigned int*)MHL_3D_FORMAT_reg))
//--#define MHL_3D_FORMAT_mhl_3d_fmt_shift                                (26)
//--#define MHL_3D_FORMAT_mhl_vid_shift                                   (24)
//--#define MHL_3D_FORMAT_oui_shift                                       (0)
//--#define MHL_3D_FORMAT_mhl_3d_fmt_mask                                 (0x3C000000)
//--#define MHL_3D_FORMAT_mhl_vid_mask                                    (0x03000000)
//--#define MHL_3D_FORMAT_oui_mask                                        (0x00FFFFFF)
//--#define MHL_3D_FORMAT_mhl_3d_fmt(data)                                (0x3C000000&((data)<<26))
//--#define MHL_3D_FORMAT_mhl_vid(data)                                   (0x03000000&((data)<<24))
//--#define MHL_3D_FORMAT_oui(data)                                       (0x00FFFFFF&(data))
//--#define MHL_3D_FORMAT_get_mhl_3d_fmt(data)                            ((0x3C000000&(data))>>26)
//--#define MHL_3D_FORMAT_get_mhl_vid(data)                               ((0x03000000&(data))>>24)
//--#define MHL_3D_FORMAT_get_oui(data)                                   (0x00FFFFFF&(data))
//--
//--
//--#define LIGHT_SLEEP                                                   0x1800d170
//--#define LIGHT_SLEEP_reg_addr                                          "0xb800d170"
//--#define LIGHT_SLEEP_reg                                               0xb800d170
//--#define LIGHT_SLEEP_inst_addr                                         "0x005C"
//--#define LIGHT_SLEEP_inst                                              0x005C
//--#define set_LIGHT_SLEEP_reg(data)                                     (*((volatile unsigned int*)LIGHT_SLEEP_reg)=data)
//--#define get_LIGHT_SLEEP_reg                                           (*((volatile unsigned int*)LIGHT_SLEEP_reg))
//--#define LIGHT_SLEEP_hdcp_2p2_ls1_shift                                (4)
//--#define LIGHT_SLEEP_hdcp_2p2_ls0_shift                                (3)
//--#define LIGHT_SLEEP_hdcp_ksvfifo_ls_shift                             (2)
//--#define LIGHT_SLEEP_hdcp_ls_shift                                     (1)
//--#define LIGHT_SLEEP_audio_ls_shift                                    (0)
//--#define LIGHT_SLEEP_hdcp_2p2_ls1_mask                                 (0x00000010)
//--#define LIGHT_SLEEP_hdcp_2p2_ls0_mask                                 (0x00000008)
//--#define LIGHT_SLEEP_hdcp_ksvfifo_ls_mask                              (0x00000004)
//--#define LIGHT_SLEEP_hdcp_ls_mask                                      (0x00000002)
//--#define LIGHT_SLEEP_audio_ls_mask                                     (0x00000001)
//--#define LIGHT_SLEEP_hdcp_2p2_ls1(data)                                (0x00000010&((data)<<4))
//--#define LIGHT_SLEEP_hdcp_2p2_ls0(data)                                (0x00000008&((data)<<3))
//--#define LIGHT_SLEEP_hdcp_ksvfifo_ls(data)                             (0x00000004&((data)<<2))
//--#define LIGHT_SLEEP_hdcp_ls(data)                                     (0x00000002&((data)<<1))
//--#define LIGHT_SLEEP_audio_ls(data)                                    (0x00000001&(data))
//--#define LIGHT_SLEEP_get_hdcp_2p2_ls1(data)                            ((0x00000010&(data))>>4)
//--#define LIGHT_SLEEP_get_hdcp_2p2_ls0(data)                            ((0x00000008&(data))>>3)
//--#define LIGHT_SLEEP_get_hdcp_ksvfifo_ls(data)                         ((0x00000004&(data))>>2)
//--#define LIGHT_SLEEP_get_hdcp_ls(data)                                 ((0x00000002&(data))>>1)
//--#define LIGHT_SLEEP_get_audio_ls(data)                                (0x00000001&(data))
//--
//--
//--#define DEEP_SLEEP                                                    0x1800d174
//--#define DEEP_SLEEP_reg_addr                                           "0xb800d174"
//--#define DEEP_SLEEP_reg                                                0xb800d174
//--#define DEEP_SLEEP_inst_addr                                          "0x005D"
//--#define DEEP_SLEEP_inst                                               0x005D
//--#define set_DEEP_SLEEP_reg(data)                                      (*((volatile unsigned int*)DEEP_SLEEP_reg)=data)
//--#define get_DEEP_SLEEP_reg                                            (*((volatile unsigned int*)DEEP_SLEEP_reg))
//--#define DEEP_SLEEP_hdcp_ds_shift                                      (1)
//--#define DEEP_SLEEP_audio_ds_shift                                     (0)
//--#define DEEP_SLEEP_hdcp_ds_mask                                       (0x00000002)
//--#define DEEP_SLEEP_audio_ds_mask                                      (0x00000001)
//--#define DEEP_SLEEP_hdcp_ds(data)                                      (0x00000002&((data)<<1))
//--#define DEEP_SLEEP_audio_ds(data)                                     (0x00000001&(data))
//--#define DEEP_SLEEP_get_hdcp_ds(data)                                  ((0x00000002&(data))>>1)
//--#define DEEP_SLEEP_get_audio_ds(data)                                 (0x00000001&(data))
//--
//--
//--#define SHOT_DOWN                                                     0x1800d178
//--#define SHOT_DOWN_reg_addr                                            "0xb800d178"
//--#define SHOT_DOWN_reg                                                 0xb800d178
//--#define SHOT_DOWN_inst_addr                                           "0x005E"
//--#define SHOT_DOWN_inst                                                0x005E
//--#define set_SHOT_DOWN_reg(data)                                       (*((volatile unsigned int*)SHOT_DOWN_reg)=data)
//--#define get_SHOT_DOWN_reg                                             (*((volatile unsigned int*)SHOT_DOWN_reg))
//--#define SHOT_DOWN_hdcp_sd_shift                                       (1)
//--#define SHOT_DOWN_audio_sd_shift                                      (0)
//--#define SHOT_DOWN_hdcp_sd_mask                                        (0x00000002)
//--#define SHOT_DOWN_audio_sd_mask                                       (0x00000001)
//--#define SHOT_DOWN_hdcp_sd(data)                                       (0x00000002&((data)<<1))
//--#define SHOT_DOWN_audio_sd(data)                                      (0x00000001&(data))
//--#define SHOT_DOWN_get_hdcp_sd(data)                                   ((0x00000002&(data))>>1)
//--#define SHOT_DOWN_get_audio_sd(data)                                  (0x00000001&(data))
//--
//--
//--#define READ_MARGIN_ENABLE                                            0x1800d17c
//--#define READ_MARGIN_ENABLE_reg_addr                                   "0xb800d17c"
//--#define READ_MARGIN_ENABLE_reg                                        0xb800d17c
//--#define READ_MARGIN_ENABLE_inst_addr                                  "0x005F"
//--#define READ_MARGIN_ENABLE_inst                                       0x005F
//--#define set_READ_MARGIN_ENABLE_reg(data)                              (*((volatile unsigned int*)READ_MARGIN_ENABLE_reg)=data)
//--#define get_READ_MARGIN_ENABLE_reg                                    (*((volatile unsigned int*)READ_MARGIN_ENABLE_reg))
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme1_shift                        (4)
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme0_shift                        (3)
//--#define READ_MARGIN_ENABLE_hdcp_ksvfifo_rme_shift                     (2)
//--#define READ_MARGIN_ENABLE_hdcp_rme_shift                             (1)
//--#define READ_MARGIN_ENABLE_audio_rme_shift                            (0)
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme1_mask                         (0x00000010)
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme0_mask                         (0x00000008)
//--#define READ_MARGIN_ENABLE_hdcp_ksvfifo_rme_mask                      (0x00000004)
//--#define READ_MARGIN_ENABLE_hdcp_rme_mask                              (0x00000002)
//--#define READ_MARGIN_ENABLE_audio_rme_mask                             (0x00000001)
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme1(data)                        (0x00000010&((data)<<4))
//--#define READ_MARGIN_ENABLE_hdcp_2p2_rme0(data)                        (0x00000008&((data)<<3))
//--#define READ_MARGIN_ENABLE_hdcp_ksvfifo_rme(data)                     (0x00000004&((data)<<2))
//--#define READ_MARGIN_ENABLE_hdcp_rme(data)                             (0x00000002&((data)<<1))
//--#define READ_MARGIN_ENABLE_audio_rme(data)                            (0x00000001&(data))
//--#define READ_MARGIN_ENABLE_get_hdcp_2p2_rme1(data)                    ((0x00000010&(data))>>4)
//--#define READ_MARGIN_ENABLE_get_hdcp_2p2_rme0(data)                    ((0x00000008&(data))>>3)
//--#define READ_MARGIN_ENABLE_get_hdcp_ksvfifo_rme(data)                 ((0x00000004&(data))>>2)
//--#define READ_MARGIN_ENABLE_get_hdcp_rme(data)                         ((0x00000002&(data))>>1)
//--#define READ_MARGIN_ENABLE_get_audio_rme(data)                        (0x00000001&(data))
//--
//--
//--#define READ_MARGIN                                                   0x1800d180
//--#define READ_MARGIN_reg_addr                                          "0xb800d180"
//--#define READ_MARGIN_reg                                               0xb800d180
//--#define READ_MARGIN_inst_addr                                         "0x0060"
//--#define READ_MARGIN_inst                                              0x0060
//--#define set_READ_MARGIN_reg(data)                                     (*((volatile unsigned int*)READ_MARGIN_reg)=data)
//--#define get_READ_MARGIN_reg                                           (*((volatile unsigned int*)READ_MARGIN_reg))
//--#define READ_MARGIN_hdcp_2p2_rm1_shift                                (16)
//--#define READ_MARGIN_hdcp_2p2_rm0_shift                                (12)
//--#define READ_MARGIN_hdcp_ksvfifo_rm_shift                             (8)
//--#define READ_MARGIN_hdcp_rm_shift                                     (4)
//--#define READ_MARGIN_audio_rm_shift                                    (0)
//--#define READ_MARGIN_hdcp_2p2_rm1_mask                                 (0x000F0000)
//--#define READ_MARGIN_hdcp_2p2_rm0_mask                                 (0x0000F000)
//--#define READ_MARGIN_hdcp_ksvfifo_rm_mask                              (0x00000F00)
//--#define READ_MARGIN_hdcp_rm_mask                                      (0x000000F0)
//--#define READ_MARGIN_audio_rm_mask                                     (0x0000000F)
//--#define READ_MARGIN_hdcp_2p2_rm1(data)                                (0x000F0000&((data)<<16))
//--#define READ_MARGIN_hdcp_2p2_rm0(data)                                (0x0000F000&((data)<<12))
//--#define READ_MARGIN_hdcp_ksvfifo_rm(data)                             (0x00000F00&((data)<<8))
//--#define READ_MARGIN_hdcp_rm(data)                                     (0x000000F0&((data)<<4))
//--#define READ_MARGIN_audio_rm(data)                                    (0x0000000F&(data))
//--#define READ_MARGIN_get_hdcp_2p2_rm1(data)                            ((0x000F0000&(data))>>16)
//--#define READ_MARGIN_get_hdcp_2p2_rm0(data)                            ((0x0000F000&(data))>>12)
//--#define READ_MARGIN_get_hdcp_ksvfifo_rm(data)                         ((0x00000F00&(data))>>8)
//--#define READ_MARGIN_get_hdcp_rm(data)                                 ((0x000000F0&(data))>>4)
//--#define READ_MARGIN_get_audio_rm(data)                                (0x0000000F&(data))
//--
//--
//--#define BIST_MODE                                                     0x1800d184
//--#define BIST_MODE_reg_addr                                            "0xb800d184"
//--#define BIST_MODE_reg                                                 0xb800d184
//--#define BIST_MODE_inst_addr                                           "0x0061"
//--#define BIST_MODE_inst                                                0x0061
//--#define set_BIST_MODE_reg(data)                                       (*((volatile unsigned int*)BIST_MODE_reg)=data)
//--#define get_BIST_MODE_reg                                             (*((volatile unsigned int*)BIST_MODE_reg))
//--#define BIST_MODE_hdcp_2p2_bist_en_shift                              (3)
//--#define BIST_MODE_hdcp_ksvfifo_bist_en_shift                          (2)
//--#define BIST_MODE_hdcp_bist_en_shift                                  (1)
//--#define BIST_MODE_audio_bist_en_shift                                 (0)
//--#define BIST_MODE_hdcp_2p2_bist_en_mask                               (0x00000008)
//--#define BIST_MODE_hdcp_ksvfifo_bist_en_mask                           (0x00000004)
//--#define BIST_MODE_hdcp_bist_en_mask                                   (0x00000002)
//--#define BIST_MODE_audio_bist_en_mask                                  (0x00000001)
//--#define BIST_MODE_hdcp_2p2_bist_en(data)                              (0x00000008&((data)<<3))
//--#define BIST_MODE_hdcp_ksvfifo_bist_en(data)                          (0x00000004&((data)<<2))
//--#define BIST_MODE_hdcp_bist_en(data)                                  (0x00000002&((data)<<1))
//--#define BIST_MODE_audio_bist_en(data)                                 (0x00000001&(data))
//--#define BIST_MODE_get_hdcp_2p2_bist_en(data)                          ((0x00000008&(data))>>3)
//--#define BIST_MODE_get_hdcp_ksvfifo_bist_en(data)                      ((0x00000004&(data))>>2)
//--#define BIST_MODE_get_hdcp_bist_en(data)                              ((0x00000002&(data))>>1)
//--#define BIST_MODE_get_audio_bist_en(data)                             (0x00000001&(data))
//--
//--
//--#define BIST_DONE                                                     0x1800d188
//--#define BIST_DONE_reg_addr                                            "0xb800d188"
//--#define BIST_DONE_reg                                                 0xb800d188
//--#define BIST_DONE_inst_addr                                           "0x0062"
//--#define BIST_DONE_inst                                                0x0062
//--#define set_BIST_DONE_reg(data)                                       (*((volatile unsigned int*)BIST_DONE_reg)=data)
//--#define get_BIST_DONE_reg                                             (*((volatile unsigned int*)BIST_DONE_reg))
//--#define BIST_DONE_hdcp_2p2_bist_done_shift                            (3)
//--#define BIST_DONE_hdcp_ksvfifo_bist_done_shift                        (2)
//--#define BIST_DONE_hdcp_bist_done_shift                                (1)
//--#define BIST_DONE_audio_bist_done_shift                               (0)
//--#define BIST_DONE_hdcp_2p2_bist_done_mask                             (0x00000008)
//--#define BIST_DONE_hdcp_ksvfifo_bist_done_mask                         (0x00000004)
//--#define BIST_DONE_hdcp_bist_done_mask                                 (0x00000002)
//--#define BIST_DONE_audio_bist_done_mask                                (0x00000001)
//--#define BIST_DONE_hdcp_2p2_bist_done(data)                            (0x00000008&((data)<<3))
//--#define BIST_DONE_hdcp_ksvfifo_bist_done(data)                        (0x00000004&((data)<<2))
//--#define BIST_DONE_hdcp_bist_done(data)                                (0x00000002&((data)<<1))
//--#define BIST_DONE_audio_bist_done(data)                               (0x00000001&(data))
//--#define BIST_DONE_get_hdcp_2p2_bist_done(data)                        ((0x00000008&(data))>>3)
//--#define BIST_DONE_get_hdcp_ksvfifo_bist_done(data)                    ((0x00000004&(data))>>2)
//--#define BIST_DONE_get_hdcp_bist_done(data)                            ((0x00000002&(data))>>1)
//--#define BIST_DONE_get_audio_bist_done(data)                           (0x00000001&(data))
//--
//--
//--#define BIST_FAIL                                                     0x1800d18c
//--#define BIST_FAIL_reg_addr                                            "0xb800d18c"
//--#define BIST_FAIL_reg                                                 0xb800d18c
//--#define BIST_FAIL_inst_addr                                           "0x0063"
//--#define BIST_FAIL_inst                                                0x0063
//--#define set_BIST_FAIL_reg(data)                                       (*((volatile unsigned int*)BIST_FAIL_reg)=data)
//--#define get_BIST_FAIL_reg                                             (*((volatile unsigned int*)BIST_FAIL_reg))
//--#define BIST_FAIL_hdcp_2p2_bist_fail_shift                            (3)
//--#define BIST_FAIL_hdcp_ksvfifo_bist_fail_shift                        (2)
//--#define BIST_FAIL_hdcp_bist_fail_shift                                (1)
//--#define BIST_FAIL_audio_bist_fail_shift                               (0)
//--#define BIST_FAIL_hdcp_2p2_bist_fail_mask                             (0x00000008)
//--#define BIST_FAIL_hdcp_ksvfifo_bist_fail_mask                         (0x00000004)
//--#define BIST_FAIL_hdcp_bist_fail_mask                                 (0x00000002)
//--#define BIST_FAIL_audio_bist_fail_mask                                (0x00000001)
//--#define BIST_FAIL_hdcp_2p2_bist_fail(data)                            (0x00000008&((data)<<3))
//--#define BIST_FAIL_hdcp_ksvfifo_bist_fail(data)                        (0x00000004&((data)<<2))
//--#define BIST_FAIL_hdcp_bist_fail(data)                                (0x00000002&((data)<<1))
//--#define BIST_FAIL_audio_bist_fail(data)                               (0x00000001&(data))
//--#define BIST_FAIL_get_hdcp_2p2_bist_fail(data)                        ((0x00000008&(data))>>3)
//--#define BIST_FAIL_get_hdcp_ksvfifo_bist_fail(data)                    ((0x00000004&(data))>>2)
//--#define BIST_FAIL_get_hdcp_bist_fail(data)                            ((0x00000002&(data))>>1)
//--#define BIST_FAIL_get_audio_bist_fail(data)                           (0x00000001&(data))
//--
//--
//--#define DRF_MODE                                                      0x1800d190
//--#define DRF_MODE_reg_addr                                             "0xb800d190"
//--#define DRF_MODE_reg                                                  0xb800d190
//--#define DRF_MODE_inst_addr                                            "0x0064"
//--#define DRF_MODE_inst                                                 0x0064
//--#define set_DRF_MODE_reg(data)                                        (*((volatile unsigned int*)DRF_MODE_reg)=data)
//--#define get_DRF_MODE_reg                                              (*((volatile unsigned int*)DRF_MODE_reg))
//--#define DRF_MODE_hdcp_2p2_drf_mode_shift                              (3)
//--#define DRF_MODE_hdcp_ksvfifo_drf_mode_shift                          (2)
//--#define DRF_MODE_hdcp_drf_mode_shift                                  (1)
//--#define DRF_MODE_audio_drf_mode_shift                                 (0)
//--#define DRF_MODE_hdcp_2p2_drf_mode_mask                               (0x00000008)
//--#define DRF_MODE_hdcp_ksvfifo_drf_mode_mask                           (0x00000004)
//--#define DRF_MODE_hdcp_drf_mode_mask                                   (0x00000002)
//--#define DRF_MODE_audio_drf_mode_mask                                  (0x00000001)
//--#define DRF_MODE_hdcp_2p2_drf_mode(data)                              (0x00000008&((data)<<3))
//--#define DRF_MODE_hdcp_ksvfifo_drf_mode(data)                          (0x00000004&((data)<<2))
//--#define DRF_MODE_hdcp_drf_mode(data)                                  (0x00000002&((data)<<1))
//--#define DRF_MODE_audio_drf_mode(data)                                 (0x00000001&(data))
//--#define DRF_MODE_get_hdcp_2p2_drf_mode(data)                          ((0x00000008&(data))>>3)
//--#define DRF_MODE_get_hdcp_ksvfifo_drf_mode(data)                      ((0x00000004&(data))>>2)
//--#define DRF_MODE_get_hdcp_drf_mode(data)                              ((0x00000002&(data))>>1)
//--#define DRF_MODE_get_audio_drf_mode(data)                             (0x00000001&(data))
//--
//--
//--#define DRF_RESUME                                                    0x1800d194
//--#define DRF_RESUME_reg_addr                                           "0xb800d194"
//--#define DRF_RESUME_reg                                                0xb800d194
//--#define DRF_RESUME_inst_addr                                          "0x0065"
//--#define DRF_RESUME_inst                                               0x0065
//--#define set_DRF_RESUME_reg(data)                                      (*((volatile unsigned int*)DRF_RESUME_reg)=data)
//--#define get_DRF_RESUME_reg                                            (*((volatile unsigned int*)DRF_RESUME_reg))
//--#define DRF_RESUME_hdcp_2p2_drf_resume_shift                          (3)
//--#define DRF_RESUME_hdcp_ksvfifo_drf_resume_shift                      (2)
//--#define DRF_RESUME_hdcp_drf_resume_shift                              (1)
//--#define DRF_RESUME_audio_drf_resume_shift                             (0)
//--#define DRF_RESUME_hdcp_2p2_drf_resume_mask                           (0x00000008)
//--#define DRF_RESUME_hdcp_ksvfifo_drf_resume_mask                       (0x00000004)
//--#define DRF_RESUME_hdcp_drf_resume_mask                               (0x00000002)
//--#define DRF_RESUME_audio_drf_resume_mask                              (0x00000001)
//--#define DRF_RESUME_hdcp_2p2_drf_resume(data)                          (0x00000008&((data)<<3))
//--#define DRF_RESUME_hdcp_ksvfifo_drf_resume(data)                      (0x00000004&((data)<<2))
//--#define DRF_RESUME_hdcp_drf_resume(data)                              (0x00000002&((data)<<1))
//--#define DRF_RESUME_audio_drf_resume(data)                             (0x00000001&(data))
//--#define DRF_RESUME_get_hdcp_2p2_drf_resume(data)                      ((0x00000008&(data))>>3)
//--#define DRF_RESUME_get_hdcp_ksvfifo_drf_resume(data)                  ((0x00000004&(data))>>2)
//--#define DRF_RESUME_get_hdcp_drf_resume(data)                          ((0x00000002&(data))>>1)
//--#define DRF_RESUME_get_audio_drf_resume(data)                         (0x00000001&(data))
//--
//--
//--#define DRF_DONE                                                      0x1800d198
//--#define DRF_DONE_reg_addr                                             "0xb800d198"
//--#define DRF_DONE_reg                                                  0xb800d198
//--#define DRF_DONE_inst_addr                                            "0x0066"
//--#define DRF_DONE_inst                                                 0x0066
//--#define set_DRF_DONE_reg(data)                                        (*((volatile unsigned int*)DRF_DONE_reg)=data)
//--#define get_DRF_DONE_reg                                              (*((volatile unsigned int*)DRF_DONE_reg))
//--#define DRF_DONE_hdcp_2p2_drf_done_shift                              (3)
//--#define DRF_DONE_hdcp_ksvfifo_drf_done_shift                          (2)
//--#define DRF_DONE_hdcp_drf_done_shift                                  (1)
//--#define DRF_DONE_audio_drf_done_shift                                 (0)
//--#define DRF_DONE_hdcp_2p2_drf_done_mask                               (0x00000008)
//--#define DRF_DONE_hdcp_ksvfifo_drf_done_mask                           (0x00000004)
//--#define DRF_DONE_hdcp_drf_done_mask                                   (0x00000002)
//--#define DRF_DONE_audio_drf_done_mask                                  (0x00000001)
//--#define DRF_DONE_hdcp_2p2_drf_done(data)                              (0x00000008&((data)<<3))
//--#define DRF_DONE_hdcp_ksvfifo_drf_done(data)                          (0x00000004&((data)<<2))
//--#define DRF_DONE_hdcp_drf_done(data)                                  (0x00000002&((data)<<1))
//--#define DRF_DONE_audio_drf_done(data)                                 (0x00000001&(data))
//--#define DRF_DONE_get_hdcp_2p2_drf_done(data)                          ((0x00000008&(data))>>3)
//--#define DRF_DONE_get_hdcp_ksvfifo_drf_done(data)                      ((0x00000004&(data))>>2)
//--#define DRF_DONE_get_hdcp_drf_done(data)                              ((0x00000002&(data))>>1)
//--#define DRF_DONE_get_audio_drf_done(data)                             (0x00000001&(data))
//--
//--
//--#define DRF_PAUSE                                                     0x1800d19c
//--#define DRF_PAUSE_reg_addr                                            "0xb800d19c"
//--#define DRF_PAUSE_reg                                                 0xb800d19c
//--#define DRF_PAUSE_inst_addr                                           "0x0067"
//--#define DRF_PAUSE_inst                                                0x0067
//--#define set_DRF_PAUSE_reg(data)                                       (*((volatile unsigned int*)DRF_PAUSE_reg)=data)
//--#define get_DRF_PAUSE_reg                                             (*((volatile unsigned int*)DRF_PAUSE_reg))
//--#define DRF_PAUSE_hdcp_2p2_drf_pause_shift                            (3)
//--#define DRF_PAUSE_hdcp_ksvfifo_drf_pause_shift                        (2)
//--#define DRF_PAUSE_hdcp_drf_pause_shift                                (1)
//--#define DRF_PAUSE_audio_drf_pause_shift                               (0)
//--#define DRF_PAUSE_hdcp_2p2_drf_pause_mask                             (0x00000008)
//--#define DRF_PAUSE_hdcp_ksvfifo_drf_pause_mask                         (0x00000004)
//--#define DRF_PAUSE_hdcp_drf_pause_mask                                 (0x00000002)
//--#define DRF_PAUSE_audio_drf_pause_mask                                (0x00000001)
//--#define DRF_PAUSE_hdcp_2p2_drf_pause(data)                            (0x00000008&((data)<<3))
//--#define DRF_PAUSE_hdcp_ksvfifo_drf_pause(data)                        (0x00000004&((data)<<2))
//--#define DRF_PAUSE_hdcp_drf_pause(data)                                (0x00000002&((data)<<1))
//--#define DRF_PAUSE_audio_drf_pause(data)                               (0x00000001&(data))
//--#define DRF_PAUSE_get_hdcp_2p2_drf_pause(data)                        ((0x00000008&(data))>>3)
//--#define DRF_PAUSE_get_hdcp_ksvfifo_drf_pause(data)                    ((0x00000004&(data))>>2)
//--#define DRF_PAUSE_get_hdcp_drf_pause(data)                            ((0x00000002&(data))>>1)
//--#define DRF_PAUSE_get_audio_drf_pause(data)                           (0x00000001&(data))
//--
//--
//--#define DRF_FAIL                                                      0x1800d1a0
//--#define DRF_FAIL_reg_addr                                             "0xb800d1a0"
//--#define DRF_FAIL_reg                                                  0xb800d1a0
//--#define DRF_FAIL_inst_addr                                            "0x0068"
//--#define DRF_FAIL_inst                                                 0x0068
//--#define set_DRF_FAIL_reg(data)                                        (*((volatile unsigned int*)DRF_FAIL_reg)=data)
//--#define get_DRF_FAIL_reg                                              (*((volatile unsigned int*)DRF_FAIL_reg))
//--#define DRF_FAIL_hdcp_2p2_drf_fail_shift                              (3)
//--#define DRF_FAIL_hdcp_ksvfifo_drf_fail_shift                          (2)
//--#define DRF_FAIL_hdcp_drf_fail_shift                                  (1)
//--#define DRF_FAIL_audio_drf_fail_shift                                 (0)
//--#define DRF_FAIL_hdcp_2p2_drf_fail_mask                               (0x00000008)
//--#define DRF_FAIL_hdcp_ksvfifo_drf_fail_mask                           (0x00000004)
//--#define DRF_FAIL_hdcp_drf_fail_mask                                   (0x00000002)
//--#define DRF_FAIL_audio_drf_fail_mask                                  (0x00000001)
//--#define DRF_FAIL_hdcp_2p2_drf_fail(data)                              (0x00000008&((data)<<3))
//--#define DRF_FAIL_hdcp_ksvfifo_drf_fail(data)                          (0x00000004&((data)<<2))
//--#define DRF_FAIL_hdcp_drf_fail(data)                                  (0x00000002&((data)<<1))
//--#define DRF_FAIL_audio_drf_fail(data)                                 (0x00000001&(data))
//--#define DRF_FAIL_get_hdcp_2p2_drf_fail(data)                          ((0x00000008&(data))>>3)
//--#define DRF_FAIL_get_hdcp_ksvfifo_drf_fail(data)                      ((0x00000004&(data))>>2)
//--#define DRF_FAIL_get_hdcp_drf_fail(data)                              ((0x00000002&(data))>>1)
//--#define DRF_FAIL_get_audio_drf_fail(data)                             (0x00000001&(data))
//--
//--
//--#define DVS                                                           0x1800d1a4
//--#define DVS_reg_addr                                                  "0xb800d1a4"
//--#define DVS_reg                                                       0xb800d1a4
//--#define DVS_inst_addr                                                 "0x0069"
//--#define DVS_inst                                                      0x0069
//--#define set_DVS_reg(data)                                             (*((volatile unsigned int*)DVS_reg)=data)
//--#define get_DVS_reg                                                   (*((volatile unsigned int*)DVS_reg))
//--#define DVS_hdcp_dvs_shift                                            (4)
//--#define DVS_audio_dvs_shift                                           (0)
//--#define DVS_hdcp_dvs_mask                                             (0x000000F0)
//--#define DVS_audio_dvs_mask                                            (0x0000000F)
//--#define DVS_hdcp_dvs(data)                                            (0x000000F0&((data)<<4))
//--#define DVS_audio_dvs(data)                                           (0x0000000F&(data))
//--#define DVS_get_hdcp_dvs(data)                                        ((0x000000F0&(data))>>4)
//--#define DVS_get_audio_dvs(data)                                       (0x0000000F&(data))
//--
//--
//--#define DVSE                                                          0x1800d1a8
//--#define DVSE_reg_addr                                                 "0xb800d1a8"
//--#define DVSE_reg                                                      0xb800d1a8
//--#define DVSE_inst_addr                                                "0x006A"
//--#define DVSE_inst                                                     0x006A
//--#define set_DVSE_reg(data)                                            (*((volatile unsigned int*)DVSE_reg)=data)
//--#define get_DVSE_reg                                                  (*((volatile unsigned int*)DVSE_reg))
//--#define DVSE_hdcp_dvse_shift                                          (1)
//--#define DVSE_audio_dvse_shift                                         (0)
//--#define DVSE_hdcp_dvse_mask                                           (0x00000002)
//--#define DVSE_audio_dvse_mask                                          (0x00000001)
//--#define DVSE_hdcp_dvse(data)                                          (0x00000002&((data)<<1))
//--#define DVSE_audio_dvse(data)                                         (0x00000001&(data))
//--#define DVSE_get_hdcp_dvse(data)                                      ((0x00000002&(data))>>1)
//--#define DVSE_get_audio_dvse(data)                                     (0x00000001&(data))
//--
//--
//--#define CTS_FIFO_CTL                                                  0x1800d1ac
//--#define CTS_FIFO_CTL_reg_addr                                         "0xb800d1ac"
//--#define CTS_FIFO_CTL_reg                                              0xb800d1ac
//--#define CTS_FIFO_CTL_inst_addr                                        "0x006B"
//--#define CTS_FIFO_CTL_inst                                             0x006B
//--#define set_CTS_FIFO_CTL_reg(data)                                    (*((volatile unsigned int*)CTS_FIFO_CTL_reg)=data)
//--#define get_CTS_FIFO_CTL_reg                                          (*((volatile unsigned int*)CTS_FIFO_CTL_reg))
//--#define CTS_FIFO_CTL_hdmi_test_sel_shift                              (4)
//--#define CTS_FIFO_CTL_hdmi_out_sel_shift                               (3)
//--#define CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_shift                    (2)
//--#define CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_shift                      (1)
//--#define CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_shift                     (0)
//--#define CTS_FIFO_CTL_hdmi_test_sel_mask                               (0x000000F0)
//--#define CTS_FIFO_CTL_hdmi_out_sel_mask                                (0x00000008)
//--#define CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi_mask                     (0x00000004)
//--#define CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi_mask                       (0x00000002)
//--#define CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi_mask                      (0x00000001)
//--#define CTS_FIFO_CTL_hdmi_test_sel(data)                              (0x000000F0&((data)<<4))
//--#define CTS_FIFO_CTL_hdmi_out_sel(data)                               (0x00000008&((data)<<3))
//--#define CTS_FIFO_CTL_force_ctsfifo_rstn_hdmi(data)                    (0x00000004&((data)<<2))
//--#define CTS_FIFO_CTL_en_ctsfifo_vsrst_hdmi(data)                      (0x00000002&((data)<<1))
//--#define CTS_FIFO_CTL_en_ctsfifo_bypass_hdmi(data)                     (0x00000001&(data))
//--#define CTS_FIFO_CTL_get_hdmi_test_sel(data)                          ((0x000000F0&(data))>>4)
//--#define CTS_FIFO_CTL_get_hdmi_out_sel(data)                           ((0x00000008&(data))>>3)
//--#define CTS_FIFO_CTL_get_force_ctsfifo_rstn_hdmi(data)                ((0x00000004&(data))>>2)
//--#define CTS_FIFO_CTL_get_en_ctsfifo_vsrst_hdmi(data)                  ((0x00000002&(data))>>1)
//--#define CTS_FIFO_CTL_get_en_ctsfifo_bypass_hdmi(data)                 (0x00000001&(data))
//--
//--
//--#define CBUS_CLK_CTL                                                  0x1800d1b0
//--#define CBUS_CLK_CTL_reg_addr                                         "0xb800d1b0"
//--#define CBUS_CLK_CTL_reg                                              0xb800d1b0
//--#define CBUS_CLK_CTL_inst_addr                                        "0x006C"
//--#define CBUS_CLK_CTL_inst                                             0x006C
//--#define set_CBUS_CLK_CTL_reg(data)                                    (*((volatile unsigned int*)CBUS_CLK_CTL_reg)=data)
//--#define get_CBUS_CLK_CTL_reg                                          (*((volatile unsigned int*)CBUS_CLK_CTL_reg))
//--#define CBUS_CLK_CTL_sys_clk_div_shift                                (4)
//--#define CBUS_CLK_CTL_cbus_core_pwdn_shift                             (1)
//--#define CBUS_CLK_CTL_sys_clk_en_shift                                 (0)
//--#define CBUS_CLK_CTL_sys_clk_div_mask                                 (0x00000070)
//--#define CBUS_CLK_CTL_cbus_core_pwdn_mask                              (0x00000002)
//--#define CBUS_CLK_CTL_sys_clk_en_mask                                  (0x00000001)
//--#define CBUS_CLK_CTL_sys_clk_div(data)                                (0x00000070&((data)<<4))
//--#define CBUS_CLK_CTL_cbus_core_pwdn(data)                             (0x00000002&((data)<<1))
//--#define CBUS_CLK_CTL_sys_clk_en(data)                                 (0x00000001&(data))
//--#define CBUS_CLK_CTL_get_sys_clk_div(data)                            ((0x00000070&(data))>>4)
//--#define CBUS_CLK_CTL_get_cbus_core_pwdn(data)                         ((0x00000002&(data))>>1)
//--#define CBUS_CLK_CTL_get_sys_clk_en(data)                             (0x00000001&(data))
//--
//--
//--#define HDCP_BIST                                                     0x1800d200
//--#define HDCP_BIST_reg_addr                                            "0xb800d200"
//--#define HDCP_BIST_reg                                                 0xb800d200
//--#define HDCP_BIST_inst_addr                                           "0x0080"
//--#define HDCP_BIST_inst                                                0x0080
//--#define set_HDCP_BIST_reg(data)                                       (*((volatile unsigned int*)HDCP_BIST_reg)=data)
//--#define get_HDCP_BIST_reg                                             (*((volatile unsigned int*)HDCP_BIST_reg))
//--
//--
//--#define HDCP_CR                                                       0x1800d204
//--#define HDCP_CR_reg_addr                                              "0xb800d204"
//--#define HDCP_CR_reg                                                   0xb800d204
//--#define HDCP_CR_inst_addr                                             "0x0081"
//--#define HDCP_CR_inst                                                  0x0081
//--#define set_HDCP_CR_reg(data)                                         (*((volatile unsigned int*)HDCP_CR_reg)=data)
//--#define get_HDCP_CR_reg                                               (*((volatile unsigned int*)HDCP_CR_reg))
//--#define HDCP_CR_namfe_shift                                           (7)
//--#define HDCP_CR_rpt_shift                                             (6)
//--#define HDCP_CR_ivsp_shift                                            (5)
//--#define HDCP_CR_invvs_shift                                           (4)
//--#define HDCP_CR_ivspm_shift                                           (3)
//--#define HDCP_CR_maddf_shift                                           (2)
//--#define HDCP_CR_dkapde_shift                                          (1)
//--#define HDCP_CR_hdcp_en_shift                                         (0)
//--#define HDCP_CR_namfe_mask                                            (0x00000080)
//--#define HDCP_CR_rpt_mask                                              (0x00000040)
//--#define HDCP_CR_ivsp_mask                                             (0x00000020)
//--#define HDCP_CR_invvs_mask                                            (0x00000010)
//--#define HDCP_CR_ivspm_mask                                            (0x00000008)
//--#define HDCP_CR_maddf_mask                                            (0x00000004)
//--#define HDCP_CR_dkapde_mask                                           (0x00000002)
//--#define HDCP_CR_hdcp_en_mask                                          (0x00000001)
//--#define HDCP_CR_namfe(data)                                           (0x00000080&((data)<<7))
//--#define HDCP_CR_rpt(data)                                             (0x00000040&((data)<<6))
//--#define HDCP_CR_ivsp(data)                                            (0x00000020&((data)<<5))
//--#define HDCP_CR_invvs(data)                                           (0x00000010&((data)<<4))
//--#define HDCP_CR_ivspm(data)                                           (0x00000008&((data)<<3))
//--#define HDCP_CR_maddf(data)                                           (0x00000004&((data)<<2))
//--#define HDCP_CR_dkapde(data)                                          (0x00000002&((data)<<1))
//--#define HDCP_CR_hdcp_en(data)                                         (0x00000001&(data))
//--#define HDCP_CR_get_namfe(data)                                       ((0x00000080&(data))>>7)
//--#define HDCP_CR_get_rpt(data)                                         ((0x00000040&(data))>>6)
//--#define HDCP_CR_get_ivsp(data)                                        ((0x00000020&(data))>>5)
//--#define HDCP_CR_get_invvs(data)                                       ((0x00000010&(data))>>4)
//--#define HDCP_CR_get_ivspm(data)                                       ((0x00000008&(data))>>3)
//--#define HDCP_CR_get_maddf(data)                                       ((0x00000004&(data))>>2)
//--#define HDCP_CR_get_dkapde(data)                                      ((0x00000002&(data))>>1)
//--#define HDCP_CR_get_hdcp_en(data)                                     (0x00000001&(data))
//--
//--
//--#define HDCP_DKAP                                                     0x1800d208
//--#define HDCP_DKAP_reg_addr                                            "0xb800d208"
//--#define HDCP_DKAP_reg                                                 0xb800d208
//--#define HDCP_DKAP_inst_addr                                           "0x0082"
//--#define HDCP_DKAP_inst                                                0x0082
//--#define set_HDCP_DKAP_reg(data)                                       (*((volatile unsigned int*)HDCP_DKAP_reg)=data)
//--#define get_HDCP_DKAP_reg                                             (*((volatile unsigned int*)HDCP_DKAP_reg))
//--#define HDCP_DKAP_dkap_shift                                          (0)
//--#define HDCP_DKAP_dkap_mask                                           (0x000000FF)
//--#define HDCP_DKAP_dkap(data)                                          (0x000000FF&(data))
//--#define HDCP_DKAP_get_dkap(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDCP_PCR                                                      0x1800d20c
//--#define HDCP_PCR_reg_addr                                             "0xb800d20c"
//--#define HDCP_PCR_reg                                                  0xb800d20c
//--#define HDCP_PCR_inst_addr                                            "0x0083"
//--#define HDCP_PCR_inst                                                 0x0083
//--#define set_HDCP_PCR_reg(data)                                        (*((volatile unsigned int*)HDCP_PCR_reg)=data)
//--#define get_HDCP_PCR_reg                                              (*((volatile unsigned int*)HDCP_PCR_reg))
//--#define HDCP_PCR_i2c_scl_dly_sel_shift                                (24)
//--#define HDCP_PCR_i2c_sda_dly_sel_shift                                (20)
//--#define HDCP_PCR_tune_up_down_shift                                   (17)
//--#define HDCP_PCR_tune_range_shift                                     (10)
//--#define HDCP_PCR_ddcdbnc_shift                                        (9)
//--#define HDCP_PCR_km_clk_sel_eco_shift                                 (8)
//--#define HDCP_PCR_dbnc_level_sel_shift                                 (7)
//--#define HDCP_PCR_km_clk_sel_shift                                     (6)
//--#define HDCP_PCR_hdcp_vs_sel_shift                                    (5)
//--#define HDCP_PCR_enc_tog_shift                                        (4)
//--#define HDCP_PCR_avmute_dis_shift                                     (3)
//--#define HDCP_PCR_dummy1800d20c_2_shift                                (2)
//--#define HDCP_PCR_apai_type_shift                                      (1)
//--#define HDCP_PCR_apai_shift                                           (0)
//--#define HDCP_PCR_i2c_scl_dly_sel_mask                                 (0x0F000000)
//--#define HDCP_PCR_i2c_sda_dly_sel_mask                                 (0x00F00000)
//--#define HDCP_PCR_tune_up_down_mask                                    (0x00020000)
//--#define HDCP_PCR_tune_range_mask                                      (0x0001FC00)
//--#define HDCP_PCR_ddcdbnc_mask                                         (0x00000200)
//--#define HDCP_PCR_km_clk_sel_eco_mask                                  (0x00000100)
//--#define HDCP_PCR_dbnc_level_sel_mask                                  (0x00000080)
//--#define HDCP_PCR_km_clk_sel_mask                                      (0x00000040)
//--#define HDCP_PCR_hdcp_vs_sel_mask                                     (0x00000020)
//--#define HDCP_PCR_enc_tog_mask                                         (0x00000010)
//--#define HDCP_PCR_avmute_dis_mask                                      (0x00000008)
//--#define HDCP_PCR_dummy1800d20c_2_mask                                 (0x00000004)
//--#define HDCP_PCR_apai_type_mask                                       (0x00000002)
//--#define HDCP_PCR_apai_mask                                            (0x00000001)
//--#define HDCP_PCR_i2c_scl_dly_sel(data)                                (0x0F000000&((data)<<24))
//--#define HDCP_PCR_i2c_sda_dly_sel(data)                                (0x00F00000&((data)<<20))
//--#define HDCP_PCR_tune_up_down(data)                                   (0x00020000&((data)<<17))
//--#define HDCP_PCR_tune_range(data)                                     (0x0001FC00&((data)<<10))
//--#define HDCP_PCR_ddcdbnc(data)                                        (0x00000200&((data)<<9))
//--#define HDCP_PCR_km_clk_sel_eco(data)                                 (0x00000100&((data)<<8))
//--#define HDCP_PCR_dbnc_level_sel(data)                                 (0x00000080&((data)<<7))
//--#define HDCP_PCR_km_clk_sel(data)                                     (0x00000040&((data)<<6))
//--#define HDCP_PCR_hdcp_vs_sel(data)                                    (0x00000020&((data)<<5))
//--#define HDCP_PCR_enc_tog(data)                                        (0x00000010&((data)<<4))
//--#define HDCP_PCR_avmute_dis(data)                                     (0x00000008&((data)<<3))
//--#define HDCP_PCR_dummy1800d20c_2(data)                                (0x00000004&((data)<<2))
//--#define HDCP_PCR_apai_type(data)                                      (0x00000002&((data)<<1))
//--#define HDCP_PCR_apai(data)                                           (0x00000001&(data))
//--#define HDCP_PCR_get_i2c_scl_dly_sel(data)                            ((0x0F000000&(data))>>24)
//--#define HDCP_PCR_get_i2c_sda_dly_sel(data)                            ((0x00F00000&(data))>>20)
//--#define HDCP_PCR_get_tune_up_down(data)                               ((0x00020000&(data))>>17)
//--#define HDCP_PCR_get_tune_range(data)                                 ((0x0001FC00&(data))>>10)
//--#define HDCP_PCR_get_ddcdbnc(data)                                    ((0x00000200&(data))>>9)
//--#define HDCP_PCR_get_km_clk_sel_eco(data)                             ((0x00000100&(data))>>8)
//--#define HDCP_PCR_get_dbnc_level_sel(data)                             ((0x00000080&(data))>>7)
//--#define HDCP_PCR_get_km_clk_sel(data)                                 ((0x00000040&(data))>>6)
//--#define HDCP_PCR_get_hdcp_vs_sel(data)                                ((0x00000020&(data))>>5)
//--#define HDCP_PCR_get_enc_tog(data)                                    ((0x00000010&(data))>>4)
//--#define HDCP_PCR_get_avmute_dis(data)                                 ((0x00000008&(data))>>3)
//--#define HDCP_PCR_get_dummy1800d20c_2(data)                            ((0x00000004&(data))>>2)
//--#define HDCP_PCR_get_apai_type(data)                                  ((0x00000002&(data))>>1)
//--#define HDCP_PCR_get_apai(data)                                       (0x00000001&(data))
//--
//--
//--#define HDCP_FLAG1                                                    0x1800d210
//--#define HDCP_FLAG1_reg_addr                                           "0xb800d210"
//--#define HDCP_FLAG1_reg                                                0xb800d210
//--#define HDCP_FLAG1_inst_addr                                          "0x0084"
//--#define HDCP_FLAG1_inst                                               0x0084
//--#define set_HDCP_FLAG1_reg(data)                                      (*((volatile unsigned int*)HDCP_FLAG1_reg)=data)
//--#define get_HDCP_FLAG1_reg                                            (*((volatile unsigned int*)HDCP_FLAG1_reg))
//--#define HDCP_FLAG1_wr_aksv_flag_shift                                 (4)
//--#define HDCP_FLAG1_rd_ri_flag_shift                                   (3)
//--#define HDCP_FLAG1_rd_bksv_flag_shift                                 (2)
//--#define HDCP_FLAG1_dummy1800d210_1_0_shift                            (0)
//--#define HDCP_FLAG1_wr_aksv_flag_mask                                  (0x00000010)
//--#define HDCP_FLAG1_rd_ri_flag_mask                                    (0x00000008)
//--#define HDCP_FLAG1_rd_bksv_flag_mask                                  (0x00000004)
//--#define HDCP_FLAG1_dummy1800d210_1_0_mask                             (0x00000003)
//--#define HDCP_FLAG1_wr_aksv_flag(data)                                 (0x00000010&((data)<<4))
//--#define HDCP_FLAG1_rd_ri_flag(data)                                   (0x00000008&((data)<<3))
//--#define HDCP_FLAG1_rd_bksv_flag(data)                                 (0x00000004&((data)<<2))
//--#define HDCP_FLAG1_dummy1800d210_1_0(data)                            (0x00000003&(data))
//--#define HDCP_FLAG1_get_wr_aksv_flag(data)                             ((0x00000010&(data))>>4)
//--#define HDCP_FLAG1_get_rd_ri_flag(data)                               ((0x00000008&(data))>>3)
//--#define HDCP_FLAG1_get_rd_bksv_flag(data)                             ((0x00000004&(data))>>2)
//--#define HDCP_FLAG1_get_dummy1800d210_1_0(data)                        (0x00000003&(data))
//--
//--
//--#define HDCP_FLAG2                                                    0x1800d214
//--#define HDCP_FLAG2_reg_addr                                           "0xb800d214"
//--#define HDCP_FLAG2_reg                                                0xb800d214
//--#define HDCP_FLAG2_inst_addr                                          "0x0085"
//--#define HDCP_FLAG2_inst                                               0x0085
//--#define set_HDCP_FLAG2_reg(data)                                      (*((volatile unsigned int*)HDCP_FLAG2_reg)=data)
//--#define get_HDCP_FLAG2_reg                                            (*((volatile unsigned int*)HDCP_FLAG2_reg))
//--#define HDCP_FLAG2_irq_aksv_en_shift                                  (4)
//--#define HDCP_FLAG2_irq_ri_en_shift                                    (3)
//--#define HDCP_FLAG2_irq_bksv_en_shift                                  (2)
//--#define HDCP_FLAG2_dummy1800d214_1_0_shift                            (0)
//--#define HDCP_FLAG2_irq_aksv_en_mask                                   (0x00000010)
//--#define HDCP_FLAG2_irq_ri_en_mask                                     (0x00000008)
//--#define HDCP_FLAG2_irq_bksv_en_mask                                   (0x00000004)
//--#define HDCP_FLAG2_dummy1800d214_1_0_mask                             (0x00000003)
//--#define HDCP_FLAG2_irq_aksv_en(data)                                  (0x00000010&((data)<<4))
//--#define HDCP_FLAG2_irq_ri_en(data)                                    (0x00000008&((data)<<3))
//--#define HDCP_FLAG2_irq_bksv_en(data)                                  (0x00000004&((data)<<2))
//--#define HDCP_FLAG2_dummy1800d214_1_0(data)                            (0x00000003&(data))
//--#define HDCP_FLAG2_get_irq_aksv_en(data)                              ((0x00000010&(data))>>4)
//--#define HDCP_FLAG2_get_irq_ri_en(data)                                ((0x00000008&(data))>>3)
//--#define HDCP_FLAG2_get_irq_bksv_en(data)                              ((0x00000004&(data))>>2)
//--#define HDCP_FLAG2_get_dummy1800d214_1_0(data)                        (0x00000003&(data))
//--
//--
//--#define HDCP_AP                                                       0x1800d218
//--#define HDCP_AP_reg_addr                                              "0xb800d218"
//--#define HDCP_AP_reg                                                   0xb800d218
//--#define HDCP_AP_inst_addr                                             "0x0086"
//--#define HDCP_AP_inst                                                  0x0086
//--#define set_HDCP_AP_reg(data)                                         (*((volatile unsigned int*)HDCP_AP_reg)=data)
//--#define get_HDCP_AP_reg                                               (*((volatile unsigned int*)HDCP_AP_reg))
//--#define HDCP_AP_ksvfifo_status_shift                                  (18)
//--#define HDCP_AP_dp_ksvfifo_ptr_shift                                  (8)
//--#define HDCP_AP_ap1_shift                                             (0)
//--#define HDCP_AP_ksvfifo_status_mask                                   (0x00040000)
//--#define HDCP_AP_dp_ksvfifo_ptr_mask                                   (0x0003FF00)
//--#define HDCP_AP_ap1_mask                                              (0x000000FF)
//--#define HDCP_AP_ksvfifo_status(data)                                  (0x00040000&((data)<<18))
//--#define HDCP_AP_dp_ksvfifo_ptr(data)                                  (0x0003FF00&((data)<<8))
//--#define HDCP_AP_ap1(data)                                             (0x000000FF&(data))
//--#define HDCP_AP_get_ksvfifo_status(data)                              ((0x00040000&(data))>>18)
//--#define HDCP_AP_get_dp_ksvfifo_ptr(data)                              ((0x0003FF00&(data))>>8)
//--#define HDCP_AP_get_ap1(data)                                         (0x000000FF&(data))
//--
//--
//--#define HDCP_DP                                                       0x1800d21c
//--#define HDCP_DP_reg_addr                                              "0xb800d21c"
//--#define HDCP_DP_reg                                                   0xb800d21c
//--#define HDCP_DP_inst_addr                                             "0x0087"
//--#define HDCP_DP_inst                                                  0x0087
//--#define set_HDCP_DP_reg(data)                                         (*((volatile unsigned int*)HDCP_DP_reg)=data)
//--#define get_HDCP_DP_reg                                               (*((volatile unsigned int*)HDCP_DP_reg))
//--#define HDCP_DP_dp1_shift                                             (0)
//--#define HDCP_DP_dp1_mask                                              (0x000000FF)
//--#define HDCP_DP_dp1(data)                                             (0x000000FF&(data))
//--#define HDCP_DP_get_dp1(data)                                         (0x000000FF&(data))
//--
//--
//--#define HDCP_2P2_CR                                                   0x1800d220
//--#define HDCP_2P2_CR_reg_addr                                          "0xb800d220"
//--#define HDCP_2P2_CR_reg                                               0xb800d220
//--#define HDCP_2P2_CR_inst_addr                                         "0x0088"
//--#define HDCP_2P2_CR_inst                                              0x0088
//--#define set_HDCP_2P2_CR_reg(data)                                     (*((volatile unsigned int*)HDCP_2P2_CR_reg)=data)
//--#define get_HDCP_2P2_CR_reg                                           (*((volatile unsigned int*)HDCP_2P2_CR_reg))
//--#define HDCP_2P2_CR_dummy1800d220_31_25_shift                         (25)
//--#define HDCP_2P2_CR_ks_encoded_shift                                  (24)
//--#define HDCP_2P2_CR_switch_state_shift                                (12)
//--#define HDCP_2P2_CR_rpt_thr_unauth_shift                              (11)
//--#define HDCP_2P2_CR_fw_mode_riv_shift                                 (10)
//--#define HDCP_2P2_CR_apply_state_shift                                 (9)
//--#define HDCP_2P2_CR_mspai_shift                                       (8)
//--#define HDCP_2P2_CR_new_auth_device_shift                             (7)
//--#define HDCP_2P2_CR_verify_id_pass_shift                              (6)
//--#define HDCP_2P2_CR_verify_id_done_shift                              (5)
//--#define HDCP_2P2_CR_assemble_id_fail_shift                            (4)
//--#define HDCP_2P2_CR_downstream_done_shift                             (3)
//--#define HDCP_2P2_CR_ks_done_shift                                     (2)
//--#define HDCP_2P2_CR_switch_unauth_shift                               (1)
//--#define HDCP_2P2_CR_hdcp_2p2_en_shift                                 (0)
//--#define HDCP_2P2_CR_dummy1800d220_31_25_mask                          (0xFE000000)
//--#define HDCP_2P2_CR_ks_encoded_mask                                   (0x01000000)
//--#define HDCP_2P2_CR_switch_state_mask                                 (0x00FFF000)
//--#define HDCP_2P2_CR_rpt_thr_unauth_mask                               (0x00000800)
//--#define HDCP_2P2_CR_fw_mode_riv_mask                                  (0x00000400)
//--#define HDCP_2P2_CR_apply_state_mask                                  (0x00000200)
//--#define HDCP_2P2_CR_mspai_mask                                        (0x00000100)
//--#define HDCP_2P2_CR_new_auth_device_mask                              (0x00000080)
//--#define HDCP_2P2_CR_verify_id_pass_mask                               (0x00000040)
//--#define HDCP_2P2_CR_verify_id_done_mask                               (0x00000020)
//--#define HDCP_2P2_CR_assemble_id_fail_mask                             (0x00000010)
//--#define HDCP_2P2_CR_downstream_done_mask                              (0x00000008)
//--#define HDCP_2P2_CR_ks_done_mask                                      (0x00000004)
//--#define HDCP_2P2_CR_switch_unauth_mask                                (0x00000002)
//--#define HDCP_2P2_CR_hdcp_2p2_en_mask                                  (0x00000001)
//--#define HDCP_2P2_CR_dummy1800d220_31_25(data)                         (0xFE000000&((data)<<25))
//--#define HDCP_2P2_CR_ks_encoded(data)                                  (0x01000000&((data)<<24))
//--#define HDCP_2P2_CR_switch_state(data)                                (0x00FFF000&((data)<<12))
//--#define HDCP_2P2_CR_rpt_thr_unauth(data)                              (0x00000800&((data)<<11))
//--#define HDCP_2P2_CR_fw_mode_riv(data)                                 (0x00000400&((data)<<10))
//--#define HDCP_2P2_CR_apply_state(data)                                 (0x00000200&((data)<<9))
//--#define HDCP_2P2_CR_mspai(data)                                       (0x00000100&((data)<<8))
//--#define HDCP_2P2_CR_new_auth_device(data)                             (0x00000080&((data)<<7))
//--#define HDCP_2P2_CR_verify_id_pass(data)                              (0x00000040&((data)<<6))
//--#define HDCP_2P2_CR_verify_id_done(data)                              (0x00000020&((data)<<5))
//--#define HDCP_2P2_CR_assemble_id_fail(data)                            (0x00000010&((data)<<4))
//--#define HDCP_2P2_CR_downstream_done(data)                             (0x00000008&((data)<<3))
//--#define HDCP_2P2_CR_ks_done(data)                                     (0x00000004&((data)<<2))
//--#define HDCP_2P2_CR_switch_unauth(data)                               (0x00000002&((data)<<1))
//--#define HDCP_2P2_CR_hdcp_2p2_en(data)                                 (0x00000001&(data))
//--#define HDCP_2P2_CR_get_dummy1800d220_31_25(data)                     ((0xFE000000&(data))>>25)
//--#define HDCP_2P2_CR_get_ks_encoded(data)                              ((0x01000000&(data))>>24)
//--#define HDCP_2P2_CR_get_switch_state(data)                            ((0x00FFF000&(data))>>12)
//--#define HDCP_2P2_CR_get_rpt_thr_unauth(data)                          ((0x00000800&(data))>>11)
//--#define HDCP_2P2_CR_get_fw_mode_riv(data)                             ((0x00000400&(data))>>10)
//--#define HDCP_2P2_CR_get_apply_state(data)                             ((0x00000200&(data))>>9)
//--#define HDCP_2P2_CR_get_mspai(data)                                   ((0x00000100&(data))>>8)
//--#define HDCP_2P2_CR_get_new_auth_device(data)                         ((0x00000080&(data))>>7)
//--#define HDCP_2P2_CR_get_verify_id_pass(data)                          ((0x00000040&(data))>>6)
//--#define HDCP_2P2_CR_get_verify_id_done(data)                          ((0x00000020&(data))>>5)
//--#define HDCP_2P2_CR_get_assemble_id_fail(data)                        ((0x00000010&(data))>>4)
//--#define HDCP_2P2_CR_get_downstream_done(data)                         ((0x00000008&(data))>>3)
//--#define HDCP_2P2_CR_get_ks_done(data)                                 ((0x00000004&(data))>>2)
//--#define HDCP_2P2_CR_get_switch_unauth(data)                           ((0x00000002&(data))>>1)
//--#define HDCP_2P2_CR_get_hdcp_2p2_en(data)                             (0x00000001&(data))
//--
//--
//--#define HDCP_2P2_KS0                                                  0x1800d224
//--#define HDCP_2P2_KS0_reg_addr                                         "0xb800d224"
//--#define HDCP_2P2_KS0_reg                                              0xb800d224
//--#define HDCP_2P2_KS0_inst_addr                                        "0x0089"
//--#define HDCP_2P2_KS0_inst                                             0x0089
//--#define set_HDCP_2P2_KS0_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_KS0_reg)=data)
//--#define get_HDCP_2P2_KS0_reg                                          (*((volatile unsigned int*)HDCP_2P2_KS0_reg))
//--#define HDCP_2P2_KS0_ks_shift                                         (0)
//--#define HDCP_2P2_KS0_ks_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_KS0_ks(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_KS0_get_ks(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_KS1                                                  0x1800d228
//--#define HDCP_2P2_KS1_reg_addr                                         "0xb800d228"
//--#define HDCP_2P2_KS1_reg                                              0xb800d228
//--#define HDCP_2P2_KS1_inst_addr                                        "0x008A"
//--#define HDCP_2P2_KS1_inst                                             0x008A
//--#define set_HDCP_2P2_KS1_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_KS1_reg)=data)
//--#define get_HDCP_2P2_KS1_reg                                          (*((volatile unsigned int*)HDCP_2P2_KS1_reg))
//--#define HDCP_2P2_KS1_ks_shift                                         (0)
//--#define HDCP_2P2_KS1_ks_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_KS1_ks(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_KS1_get_ks(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_KS2                                                  0x1800d22c
//--#define HDCP_2P2_KS2_reg_addr                                         "0xb800d22c"
//--#define HDCP_2P2_KS2_reg                                              0xb800d22c
//--#define HDCP_2P2_KS2_inst_addr                                        "0x008B"
//--#define HDCP_2P2_KS2_inst                                             0x008B
//--#define set_HDCP_2P2_KS2_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_KS2_reg)=data)
//--#define get_HDCP_2P2_KS2_reg                                          (*((volatile unsigned int*)HDCP_2P2_KS2_reg))
//--#define HDCP_2P2_KS2_ks_shift                                         (0)
//--#define HDCP_2P2_KS2_ks_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_KS2_ks(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_KS2_get_ks(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_KS3                                                  0x1800d230
//--#define HDCP_2P2_KS3_reg_addr                                         "0xb800d230"
//--#define HDCP_2P2_KS3_reg                                              0xb800d230
//--#define HDCP_2P2_KS3_inst_addr                                        "0x008C"
//--#define HDCP_2P2_KS3_inst                                             0x008C
//--#define set_HDCP_2P2_KS3_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_KS3_reg)=data)
//--#define get_HDCP_2P2_KS3_reg                                          (*((volatile unsigned int*)HDCP_2P2_KS3_reg))
//--#define HDCP_2P2_KS3_ks_shift                                         (0)
//--#define HDCP_2P2_KS3_ks_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_KS3_ks(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_KS3_get_ks(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_LC0                                                  0x1800d234
//--#define HDCP_2P2_LC0_reg_addr                                         "0xb800d234"
//--#define HDCP_2P2_LC0_reg                                              0xb800d234
//--#define HDCP_2P2_LC0_inst_addr                                        "0x008D"
//--#define HDCP_2P2_LC0_inst                                             0x008D
//--#define set_HDCP_2P2_LC0_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_LC0_reg)=data)
//--#define get_HDCP_2P2_LC0_reg                                          (*((volatile unsigned int*)HDCP_2P2_LC0_reg))
//--#define HDCP_2P2_LC0_lc_shift                                         (0)
//--#define HDCP_2P2_LC0_lc_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_LC0_lc(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_LC0_get_lc(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_LC1                                                  0x1800d238
//--#define HDCP_2P2_LC1_reg_addr                                         "0xb800d238"
//--#define HDCP_2P2_LC1_reg                                              0xb800d238
//--#define HDCP_2P2_LC1_inst_addr                                        "0x008E"
//--#define HDCP_2P2_LC1_inst                                             0x008E
//--#define set_HDCP_2P2_LC1_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_LC1_reg)=data)
//--#define get_HDCP_2P2_LC1_reg                                          (*((volatile unsigned int*)HDCP_2P2_LC1_reg))
//--#define HDCP_2P2_LC1_lc_shift                                         (0)
//--#define HDCP_2P2_LC1_lc_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_LC1_lc(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_LC1_get_lc(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_LC2                                                  0x1800d23c
//--#define HDCP_2P2_LC2_reg_addr                                         "0xb800d23c"
//--#define HDCP_2P2_LC2_reg                                              0xb800d23c
//--#define HDCP_2P2_LC2_inst_addr                                        "0x008F"
//--#define HDCP_2P2_LC2_inst                                             0x008F
//--#define set_HDCP_2P2_LC2_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_LC2_reg)=data)
//--#define get_HDCP_2P2_LC2_reg                                          (*((volatile unsigned int*)HDCP_2P2_LC2_reg))
//--#define HDCP_2P2_LC2_lc_shift                                         (0)
//--#define HDCP_2P2_LC2_lc_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_LC2_lc(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_LC2_get_lc(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_LC3                                                  0x1800d240
//--#define HDCP_2P2_LC3_reg_addr                                         "0xb800d240"
//--#define HDCP_2P2_LC3_reg                                              0xb800d240
//--#define HDCP_2P2_LC3_inst_addr                                        "0x0090"
//--#define HDCP_2P2_LC3_inst                                             0x0090
//--#define set_HDCP_2P2_LC3_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_LC3_reg)=data)
//--#define get_HDCP_2P2_LC3_reg                                          (*((volatile unsigned int*)HDCP_2P2_LC3_reg))
//--#define HDCP_2P2_LC3_lc_shift                                         (0)
//--#define HDCP_2P2_LC3_lc_mask                                          (0xFFFFFFFF)
//--#define HDCP_2P2_LC3_lc(data)                                         (0xFFFFFFFF&(data))
//--#define HDCP_2P2_LC3_get_lc(data)                                     (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_RIV0                                                 0x1800d244
//--#define HDCP_2P2_RIV0_reg_addr                                        "0xb800d244"
//--#define HDCP_2P2_RIV0_reg                                             0xb800d244
//--#define HDCP_2P2_RIV0_inst_addr                                       "0x0091"
//--#define HDCP_2P2_RIV0_inst                                            0x0091
//--#define set_HDCP_2P2_RIV0_reg(data)                                   (*((volatile unsigned int*)HDCP_2P2_RIV0_reg)=data)
//--#define get_HDCP_2P2_RIV0_reg                                         (*((volatile unsigned int*)HDCP_2P2_RIV0_reg))
//--#define HDCP_2P2_RIV0_riv_shift                                       (0)
//--#define HDCP_2P2_RIV0_riv_mask                                        (0xFFFFFFFF)
//--#define HDCP_2P2_RIV0_riv(data)                                       (0xFFFFFFFF&(data))
//--#define HDCP_2P2_RIV0_get_riv(data)                                   (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_RIV1                                                 0x1800d248
//--#define HDCP_2P2_RIV1_reg_addr                                        "0xb800d248"
//--#define HDCP_2P2_RIV1_reg                                             0xb800d248
//--#define HDCP_2P2_RIV1_inst_addr                                       "0x0092"
//--#define HDCP_2P2_RIV1_inst                                            0x0092
//--#define set_HDCP_2P2_RIV1_reg(data)                                   (*((volatile unsigned int*)HDCP_2P2_RIV1_reg)=data)
//--#define get_HDCP_2P2_RIV1_reg                                         (*((volatile unsigned int*)HDCP_2P2_RIV1_reg))
//--#define HDCP_2P2_RIV1_riv_shift                                       (0)
//--#define HDCP_2P2_RIV1_riv_mask                                        (0xFFFFFFFF)
//--#define HDCP_2P2_RIV1_riv(data)                                       (0xFFFFFFFF&(data))
//--#define HDCP_2P2_RIV1_get_riv(data)                                   (0xFFFFFFFF&(data))
//--
//--
//--#define HDCP_2P2_SR0                                                  0x1800d24c
//--#define HDCP_2P2_SR0_reg_addr                                         "0xb800d24c"
//--#define HDCP_2P2_SR0_reg                                              0xb800d24c
//--#define HDCP_2P2_SR0_inst_addr                                        "0x0093"
//--#define HDCP_2P2_SR0_inst                                             0x0093
//--#define set_HDCP_2P2_SR0_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_SR0_reg)=data)
//--#define get_HDCP_2P2_SR0_reg                                          (*((volatile unsigned int*)HDCP_2P2_SR0_reg))
//--#define HDCP_2P2_SR0_irq_msg_overwrite_shift                          (16)
//--#define HDCP_2P2_SR0_irq_unauth_chg_shift                             (15)
//--#define HDCP_2P2_SR0_irq_state_chg_shift                              (14)
//--#define HDCP_2P2_SR0_irq_rd_msg_done_shift                            (13)
//--#define HDCP_2P2_SR0_irq_wr_msg_done_shift                            (12)
//--#define HDCP_2P2_SR0_state_shift                                      (0)
//--#define HDCP_2P2_SR0_irq_msg_overwrite_mask                           (0x00010000)
//--#define HDCP_2P2_SR0_irq_unauth_chg_mask                              (0x00008000)
//--#define HDCP_2P2_SR0_irq_state_chg_mask                               (0x00004000)
//--#define HDCP_2P2_SR0_irq_rd_msg_done_mask                             (0x00002000)
//--#define HDCP_2P2_SR0_irq_wr_msg_done_mask                             (0x00001000)
//--#define HDCP_2P2_SR0_state_mask                                       (0x00000FFF)
//--#define HDCP_2P2_SR0_irq_msg_overwrite(data)                          (0x00010000&((data)<<16))
//--#define HDCP_2P2_SR0_irq_unauth_chg(data)                             (0x00008000&((data)<<15))
//--#define HDCP_2P2_SR0_irq_state_chg(data)                              (0x00004000&((data)<<14))
//--#define HDCP_2P2_SR0_irq_rd_msg_done(data)                            (0x00002000&((data)<<13))
//--#define HDCP_2P2_SR0_irq_wr_msg_done(data)                            (0x00001000&((data)<<12))
//--#define HDCP_2P2_SR0_state(data)                                      (0x00000FFF&(data))
//--#define HDCP_2P2_SR0_get_irq_msg_overwrite(data)                      ((0x00010000&(data))>>16)
//--#define HDCP_2P2_SR0_get_irq_unauth_chg(data)                         ((0x00008000&(data))>>15)
//--#define HDCP_2P2_SR0_get_irq_state_chg(data)                          ((0x00004000&(data))>>14)
//--#define HDCP_2P2_SR0_get_irq_rd_msg_done(data)                        ((0x00002000&(data))>>13)
//--#define HDCP_2P2_SR0_get_irq_wr_msg_done(data)                        ((0x00001000&(data))>>12)
//--#define HDCP_2P2_SR0_get_state(data)                                  (0x00000FFF&(data))
//--
//--
//--#define HDCP_2P2_SR1                                                  0x1800d250
//--#define HDCP_2P2_SR1_reg_addr                                         "0xb800d250"
//--#define HDCP_2P2_SR1_reg                                              0xb800d250
//--#define HDCP_2P2_SR1_inst_addr                                        "0x0094"
//--#define HDCP_2P2_SR1_inst                                             0x0094
//--#define set_HDCP_2P2_SR1_reg(data)                                    (*((volatile unsigned int*)HDCP_2P2_SR1_reg)=data)
//--#define get_HDCP_2P2_SR1_reg                                          (*((volatile unsigned int*)HDCP_2P2_SR1_reg))
//--#define HDCP_2P2_SR1_irq_msg_overwrite_en_shift                       (4)
//--#define HDCP_2P2_SR1_irq_unauth_chg_en_shift                          (3)
//--#define HDCP_2P2_SR1_irq_state_chg_en_shift                           (2)
//--#define HDCP_2P2_SR1_irq_rd_msg_done_en_shift                         (1)
//--#define HDCP_2P2_SR1_irq_wr_msg_done_en_shift                         (0)
//--#define HDCP_2P2_SR1_irq_msg_overwrite_en_mask                        (0x00000010)
//--#define HDCP_2P2_SR1_irq_unauth_chg_en_mask                           (0x00000008)
//--#define HDCP_2P2_SR1_irq_state_chg_en_mask                            (0x00000004)
//--#define HDCP_2P2_SR1_irq_rd_msg_done_en_mask                          (0x00000002)
//--#define HDCP_2P2_SR1_irq_wr_msg_done_en_mask                          (0x00000001)
//--#define HDCP_2P2_SR1_irq_msg_overwrite_en(data)                       (0x00000010&((data)<<4))
//--#define HDCP_2P2_SR1_irq_unauth_chg_en(data)                          (0x00000008&((data)<<3))
//--#define HDCP_2P2_SR1_irq_state_chg_en(data)                           (0x00000004&((data)<<2))
//--#define HDCP_2P2_SR1_irq_rd_msg_done_en(data)                         (0x00000002&((data)<<1))
//--#define HDCP_2P2_SR1_irq_wr_msg_done_en(data)                         (0x00000001&(data))
//--#define HDCP_2P2_SR1_get_irq_msg_overwrite_en(data)                   ((0x00000010&(data))>>4)
//--#define HDCP_2P2_SR1_get_irq_unauth_chg_en(data)                      ((0x00000008&(data))>>3)
//--#define HDCP_2P2_SR1_get_irq_state_chg_en(data)                       ((0x00000004&(data))>>2)
//--#define HDCP_2P2_SR1_get_irq_rd_msg_done_en(data)                     ((0x00000002&(data))>>1)
//--#define HDCP_2P2_SR1_get_irq_wr_msg_done_en(data)                     (0x00000001&(data))
//--
//--
//--#define HDCP_MSAP                                                     0x1800d254
//--#define HDCP_MSAP_reg_addr                                            "0xb800d254"
//--#define HDCP_MSAP_reg                                                 0xb800d254
//--#define HDCP_MSAP_inst_addr                                           "0x0095"
//--#define HDCP_MSAP_inst                                                0x0095
//--#define set_HDCP_MSAP_reg(data)                                       (*((volatile unsigned int*)HDCP_MSAP_reg)=data)
//--#define get_HDCP_MSAP_reg                                             (*((volatile unsigned int*)HDCP_MSAP_reg))
//--#define HDCP_MSAP_ap1_shift                                           (0)
//--#define HDCP_MSAP_ap1_mask                                            (0x000003FF)
//--#define HDCP_MSAP_ap1(data)                                           (0x000003FF&(data))
//--#define HDCP_MSAP_get_ap1(data)                                       (0x000003FF&(data))
//--
//--
//--#define HDCP_MSDP                                                     0x1800d258
//--#define HDCP_MSDP_reg_addr                                            "0xb800d258"
//--#define HDCP_MSDP_reg                                                 0xb800d258
//--#define HDCP_MSDP_inst_addr                                           "0x0096"
//--#define HDCP_MSDP_inst                                                0x0096
//--#define set_HDCP_MSDP_reg(data)                                       (*((volatile unsigned int*)HDCP_MSDP_reg)=data)
//--#define get_HDCP_MSDP_reg                                             (*((volatile unsigned int*)HDCP_MSDP_reg))
//--#define HDCP_MSDP_dp1_shift                                           (0)
//--#define HDCP_MSDP_dp1_mask                                            (0x000000FF)
//--#define HDCP_MSDP_dp1(data)                                           (0x000000FF&(data))
//--#define HDCP_MSDP_get_dp1(data)                                       (0x000000FF&(data))
//--
//--
//--#define HDMI_CMCR                                                     0x1800d300
//--#define HDMI_CMCR_reg_addr                                            "0xb800d300"
//--#define HDMI_CMCR_reg                                                 0xb800d300
//--#define HDMI_CMCR_inst_addr                                           "0x00C0"
//--#define HDMI_CMCR_inst                                                0x00C0
//--#define set_HDMI_CMCR_reg(data)                                       (*((volatile unsigned int*)HDMI_CMCR_reg)=data)
//--#define get_HDMI_CMCR_reg                                             (*((volatile unsigned int*)HDMI_CMCR_reg))
//--#define HDMI_CMCR_icmux_shift                                         (7)
//--#define HDMI_CMCR_ocs_shift                                           (5)
//--#define HDMI_CMCR_dbdcb_shift                                         (4)
//--#define HDMI_CMCR_dummy1800d300_3_0_shift                             (0)
//--#define HDMI_CMCR_icmux_mask                                          (0x00000080)
//--#define HDMI_CMCR_ocs_mask                                            (0x00000060)
//--#define HDMI_CMCR_dbdcb_mask                                          (0x00000010)
//--#define HDMI_CMCR_dummy1800d300_3_0_mask                              (0x0000000F)
//--#define HDMI_CMCR_icmux(data)                                         (0x00000080&((data)<<7))
//--#define HDMI_CMCR_ocs(data)                                           (0x00000060&((data)<<5))
//--#define HDMI_CMCR_dbdcb(data)                                         (0x00000010&((data)<<4))
//--#define HDMI_CMCR_dummy1800d300_3_0(data)                             (0x0000000F&(data))
//--#define HDMI_CMCR_get_icmux(data)                                     ((0x00000080&(data))>>7)
//--#define HDMI_CMCR_get_ocs(data)                                       ((0x00000060&(data))>>5)
//--#define HDMI_CMCR_get_dbdcb(data)                                     ((0x00000010&(data))>>4)
//--#define HDMI_CMCR_get_dummy1800d300_3_0(data)                         (0x0000000F&(data))
//--
//--
//--#define HDMI_MCAPR                                                    0x1800d304
//--#define HDMI_MCAPR_reg_addr                                           "0xb800d304"
//--#define HDMI_MCAPR_reg                                                0xb800d304
//--#define HDMI_MCAPR_inst_addr                                          "0x00C1"
//--#define HDMI_MCAPR_inst                                               0x00C1
//--#define set_HDMI_MCAPR_reg(data)                                      (*((volatile unsigned int*)HDMI_MCAPR_reg)=data)
//--#define get_HDMI_MCAPR_reg                                            (*((volatile unsigned int*)HDMI_MCAPR_reg))
//--#define HDMI_MCAPR_dummy1800d304_7_0_shift                            (0)
//--#define HDMI_MCAPR_dummy1800d304_7_0_mask                             (0x000000FF)
//--#define HDMI_MCAPR_dummy1800d304_7_0(data)                            (0x000000FF&(data))
//--#define HDMI_MCAPR_get_dummy1800d304_7_0(data)                        (0x000000FF&(data))
//--
//--
//--#define HDMI_SCAPR                                                    0x1800d308
//--#define HDMI_SCAPR_reg_addr                                           "0xb800d308"
//--#define HDMI_SCAPR_reg                                                0xb800d308
//--#define HDMI_SCAPR_inst_addr                                          "0x00C2"
//--#define HDMI_SCAPR_inst                                               0x00C2
//--#define set_HDMI_SCAPR_reg(data)                                      (*((volatile unsigned int*)HDMI_SCAPR_reg)=data)
//--#define get_HDMI_SCAPR_reg                                            (*((volatile unsigned int*)HDMI_SCAPR_reg))
//--#define HDMI_SCAPR_s1_code_msb_r_shift                                (17)
//--#define HDMI_SCAPR_slc_r_shift                                        (16)
//--#define HDMI_SCAPR_sc_r_shift                                         (9)
//--#define HDMI_SCAPR_s1_code_msb_shift                                  (8)
//--#define HDMI_SCAPR_slc_shift                                          (7)
//--#define HDMI_SCAPR_sc_shift                                           (0)
//--#define HDMI_SCAPR_s1_code_msb_r_mask                                 (0x00020000)
//--#define HDMI_SCAPR_slc_r_mask                                         (0x00010000)
//--#define HDMI_SCAPR_sc_r_mask                                          (0x0000FE00)
//--#define HDMI_SCAPR_s1_code_msb_mask                                   (0x00000100)
//--#define HDMI_SCAPR_slc_mask                                           (0x00000080)
//--#define HDMI_SCAPR_sc_mask                                            (0x0000007F)
//--#define HDMI_SCAPR_s1_code_msb_r(data)                                (0x00020000&((data)<<17))
//--#define HDMI_SCAPR_slc_r(data)                                        (0x00010000&((data)<<16))
//--#define HDMI_SCAPR_sc_r(data)                                         (0x0000FE00&((data)<<9))
//--#define HDMI_SCAPR_s1_code_msb(data)                                  (0x00000100&((data)<<8))
//--#define HDMI_SCAPR_slc(data)                                          (0x00000080&((data)<<7))
//--#define HDMI_SCAPR_sc(data)                                           (0x0000007F&(data))
//--#define HDMI_SCAPR_get_s1_code_msb_r(data)                            ((0x00020000&(data))>>17)
//--#define HDMI_SCAPR_get_slc_r(data)                                    ((0x00010000&(data))>>16)
//--#define HDMI_SCAPR_get_sc_r(data)                                     ((0x0000FE00&(data))>>9)
//--#define HDMI_SCAPR_get_s1_code_msb(data)                              ((0x00000100&(data))>>8)
//--#define HDMI_SCAPR_get_slc(data)                                      ((0x00000080&(data))>>7)
//--#define HDMI_SCAPR_get_sc(data)                                       (0x0000007F&(data))
//--
//--
//--#define HDMI_DCAPR0                                                   0x1800d30c
//--#define HDMI_DCAPR0_reg_addr                                          "0xb800d30c"
//--#define HDMI_DCAPR0_reg                                               0xb800d30c
//--#define HDMI_DCAPR0_inst_addr                                         "0x00C3"
//--#define HDMI_DCAPR0_inst                                              0x00C3
//--#define set_HDMI_DCAPR0_reg(data)                                     (*((volatile unsigned int*)HDMI_DCAPR0_reg)=data)
//--#define get_HDMI_DCAPR0_reg                                           (*((volatile unsigned int*)HDMI_DCAPR0_reg))
//--#define HDMI_DCAPR0_dcaprh_shift                                      (8)
//--#define HDMI_DCAPR0_dcaprl_shift                                      (0)
//--#define HDMI_DCAPR0_dcaprh_mask                                       (0x0000FF00)
//--#define HDMI_DCAPR0_dcaprl_mask                                       (0x000000FF)
//--#define HDMI_DCAPR0_dcaprh(data)                                      (0x0000FF00&((data)<<8))
//--#define HDMI_DCAPR0_dcaprl(data)                                      (0x000000FF&(data))
//--#define HDMI_DCAPR0_get_dcaprh(data)                                  ((0x0000FF00&(data))>>8)
//--#define HDMI_DCAPR0_get_dcaprl(data)                                  (0x000000FF&(data))
//--
//--
//--#define HDMI_PSCR                                                     0x1800d310
//--#define HDMI_PSCR_reg_addr                                            "0xb800d310"
//--#define HDMI_PSCR_reg                                                 0xb800d310
//--#define HDMI_PSCR_inst_addr                                           "0x00C4"
//--#define HDMI_PSCR_inst                                                0x00C4
//--#define set_HDMI_PSCR_reg(data)                                       (*((volatile unsigned int*)HDMI_PSCR_reg)=data)
//--#define get_HDMI_PSCR_reg                                             (*((volatile unsigned int*)HDMI_PSCR_reg))
//--#define HDMI_PSCR_fdint_shift                                         (5)
//--#define HDMI_PSCR_etcn_shift                                          (4)
//--#define HDMI_PSCR_etfd_shift                                          (3)
//--#define HDMI_PSCR_etfbc_shift                                         (2)
//--#define HDMI_PSCR_pecs_shift                                          (0)
//--#define HDMI_PSCR_fdint_mask                                          (0x000000E0)
//--#define HDMI_PSCR_etcn_mask                                           (0x00000010)
//--#define HDMI_PSCR_etfd_mask                                           (0x00000008)
//--#define HDMI_PSCR_etfbc_mask                                          (0x00000004)
//--#define HDMI_PSCR_pecs_mask                                           (0x00000003)
//--#define HDMI_PSCR_fdint(data)                                         (0x000000E0&((data)<<5))
//--#define HDMI_PSCR_etcn(data)                                          (0x00000010&((data)<<4))
//--#define HDMI_PSCR_etfd(data)                                          (0x00000008&((data)<<3))
//--#define HDMI_PSCR_etfbc(data)                                         (0x00000004&((data)<<2))
//--#define HDMI_PSCR_pecs(data)                                          (0x00000003&(data))
//--#define HDMI_PSCR_get_fdint(data)                                     ((0x000000E0&(data))>>5)
//--#define HDMI_PSCR_get_etcn(data)                                      ((0x00000010&(data))>>4)
//--#define HDMI_PSCR_get_etfd(data)                                      ((0x00000008&(data))>>3)
//--#define HDMI_PSCR_get_etfbc(data)                                     ((0x00000004&(data))>>2)
//--#define HDMI_PSCR_get_pecs(data)                                      (0x00000003&(data))
//--
//--
//--#define HDMI_AFDD                                                     0x1800d31c
//--#define HDMI_AFDD_reg_addr                                            "0xb800d31c"
//--#define HDMI_AFDD_reg                                                 0xb800d31c
//--#define HDMI_AFDD_inst_addr                                           "0x00C7"
//--#define HDMI_AFDD_inst                                                0x00C7
//--#define set_HDMI_AFDD_reg(data)                                       (*((volatile unsigned int*)HDMI_AFDD_reg)=data)
//--#define get_HDMI_AFDD_reg                                             (*((volatile unsigned int*)HDMI_AFDD_reg))
//--#define HDMI_AFDD_mfddf_shift                                         (24)
//--#define HDMI_AFDD_mfddr_shift                                         (16)
//--#define HDMI_AFDD_fddf_shift                                          (8)
//--#define HDMI_AFDD_fddr_shift                                          (0)
//--#define HDMI_AFDD_mfddf_mask                                          (0xFF000000)
//--#define HDMI_AFDD_mfddr_mask                                          (0x00FF0000)
//--#define HDMI_AFDD_fddf_mask                                           (0x0000FF00)
//--#define HDMI_AFDD_fddr_mask                                           (0x000000FF)
//--#define HDMI_AFDD_mfddf(data)                                         (0xFF000000&((data)<<24))
//--#define HDMI_AFDD_mfddr(data)                                         (0x00FF0000&((data)<<16))
//--#define HDMI_AFDD_fddf(data)                                          (0x0000FF00&((data)<<8))
//--#define HDMI_AFDD_fddr(data)                                          (0x000000FF&(data))
//--#define HDMI_AFDD_get_mfddf(data)                                     ((0xFF000000&(data))>>24)
//--#define HDMI_AFDD_get_mfddr(data)                                     ((0x00FF0000&(data))>>16)
//--#define HDMI_AFDD_get_fddf(data)                                      ((0x0000FF00&(data))>>8)
//--#define HDMI_AFDD_get_fddr(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_FTR                                                      0x1800d320
//--#define HDMI_FTR_reg_addr                                             "0xb800d320"
//--#define HDMI_FTR_reg                                                  0xb800d320
//--#define HDMI_FTR_inst_addr                                            "0x00C8"
//--#define HDMI_FTR_inst                                                 0x00C8
//--#define set_HDMI_FTR_reg(data)                                        (*((volatile unsigned int*)HDMI_FTR_reg)=data)
//--#define get_HDMI_FTR_reg                                              (*((volatile unsigned int*)HDMI_FTR_reg))
//--#define HDMI_FTR_tl2der_shift                                         (6)
//--#define HDMI_FTR_tl2def_shift                                         (4)
//--#define HDMI_FTR_tt_shift                                             (0)
//--#define HDMI_FTR_tl2der_mask                                          (0x000000C0)
//--#define HDMI_FTR_tl2def_mask                                          (0x00000030)
//--#define HDMI_FTR_tt_mask                                              (0x0000000F)
//--#define HDMI_FTR_tl2der(data)                                         (0x000000C0&((data)<<6))
//--#define HDMI_FTR_tl2def(data)                                         (0x00000030&((data)<<4))
//--#define HDMI_FTR_tt(data)                                             (0x0000000F&(data))
//--#define HDMI_FTR_get_tl2der(data)                                     ((0x000000C0&(data))>>6)
//--#define HDMI_FTR_get_tl2def(data)                                     ((0x00000030&(data))>>4)
//--#define HDMI_FTR_get_tt(data)                                         (0x0000000F&(data))
//--
//--
//--#define HDMI_FBR                                                      0x1800d324
//--#define HDMI_FBR_reg_addr                                             "0xb800d324"
//--#define HDMI_FBR_reg                                                  0xb800d324
//--#define HDMI_FBR_inst_addr                                            "0x00C9"
//--#define HDMI_FBR_inst                                                 0x00C9
//--#define set_HDMI_FBR_reg(data)                                        (*((volatile unsigned int*)HDMI_FBR_reg)=data)
//--#define get_HDMI_FBR_reg                                              (*((volatile unsigned int*)HDMI_FBR_reg))
//--#define HDMI_FBR_tfd_shift                                            (3)
//--#define HDMI_FBR_bad_shift                                            (0)
//--#define HDMI_FBR_tfd_mask                                             (0x000000F8)
//--#define HDMI_FBR_bad_mask                                             (0x00000007)
//--#define HDMI_FBR_tfd(data)                                            (0x000000F8&((data)<<3))
//--#define HDMI_FBR_bad(data)                                            (0x00000007&(data))
//--#define HDMI_FBR_get_tfd(data)                                        ((0x000000F8&(data))>>3)
//--#define HDMI_FBR_get_bad(data)                                        (0x00000007&(data))
//--
//--
//--#define HDMI_ICPSNCR0                                                 0x1800d328
//--#define HDMI_ICPSNCR0_reg_addr                                        "0xb800d328"
//--#define HDMI_ICPSNCR0_reg                                             0xb800d328
//--#define HDMI_ICPSNCR0_inst_addr                                       "0x00CA"
//--#define HDMI_ICPSNCR0_inst                                            0x00CA
//--#define set_HDMI_ICPSNCR0_reg(data)                                   (*((volatile unsigned int*)HDMI_ICPSNCR0_reg)=data)
//--#define get_HDMI_ICPSNCR0_reg                                         (*((volatile unsigned int*)HDMI_ICPSNCR0_reg))
//--#define HDMI_ICPSNCR0_ich_shift                                       (8)
//--#define HDMI_ICPSNCR0_icl_shift                                       (0)
//--#define HDMI_ICPSNCR0_ich_mask                                        (0x0000FF00)
//--#define HDMI_ICPSNCR0_icl_mask                                        (0x000000FF)
//--#define HDMI_ICPSNCR0_ich(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_ICPSNCR0_icl(data)                                       (0x000000FF&(data))
//--#define HDMI_ICPSNCR0_get_ich(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_ICPSNCR0_get_icl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_PCPSNCR0                                                 0x1800d32c
//--#define HDMI_PCPSNCR0_reg_addr                                        "0xb800d32c"
//--#define HDMI_PCPSNCR0_reg                                             0xb800d32c
//--#define HDMI_PCPSNCR0_inst_addr                                       "0x00CB"
//--#define HDMI_PCPSNCR0_inst                                            0x00CB
//--#define set_HDMI_PCPSNCR0_reg(data)                                   (*((volatile unsigned int*)HDMI_PCPSNCR0_reg)=data)
//--#define get_HDMI_PCPSNCR0_reg                                         (*((volatile unsigned int*)HDMI_PCPSNCR0_reg))
//--#define HDMI_PCPSNCR0_pch_shift                                       (8)
//--#define HDMI_PCPSNCR0_pcl_shift                                       (0)
//--#define HDMI_PCPSNCR0_pch_mask                                        (0x0000FF00)
//--#define HDMI_PCPSNCR0_pcl_mask                                        (0x000000FF)
//--#define HDMI_PCPSNCR0_pch(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_PCPSNCR0_pcl(data)                                       (0x000000FF&(data))
//--#define HDMI_PCPSNCR0_get_pch(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_PCPSNCR0_get_pcl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_ICTPSR0                                                  0x1800d330
//--#define HDMI_ICTPSR0_reg_addr                                         "0xb800d330"
//--#define HDMI_ICTPSR0_reg                                              0xb800d330
//--#define HDMI_ICTPSR0_inst_addr                                        "0x00CC"
//--#define HDMI_ICTPSR0_inst                                             0x00CC
//--#define set_HDMI_ICTPSR0_reg(data)                                    (*((volatile unsigned int*)HDMI_ICTPSR0_reg)=data)
//--#define get_HDMI_ICTPSR0_reg                                          (*((volatile unsigned int*)HDMI_ICTPSR0_reg))
//--#define HDMI_ICTPSR0_icth_shift                                       (8)
//--#define HDMI_ICTPSR0_ictl_shift                                       (0)
//--#define HDMI_ICTPSR0_icth_mask                                        (0x0000FF00)
//--#define HDMI_ICTPSR0_ictl_mask                                        (0x000000FF)
//--#define HDMI_ICTPSR0_icth(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_ICTPSR0_ictl(data)                                       (0x000000FF&(data))
//--#define HDMI_ICTPSR0_get_icth(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_ICTPSR0_get_ictl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_PCTPSR0                                                  0x1800d334
//--#define HDMI_PCTPSR0_reg_addr                                         "0xb800d334"
//--#define HDMI_PCTPSR0_reg                                              0xb800d334
//--#define HDMI_PCTPSR0_inst_addr                                        "0x00CD"
//--#define HDMI_PCTPSR0_inst                                             0x00CD
//--#define set_HDMI_PCTPSR0_reg(data)                                    (*((volatile unsigned int*)HDMI_PCTPSR0_reg)=data)
//--#define get_HDMI_PCTPSR0_reg                                          (*((volatile unsigned int*)HDMI_PCTPSR0_reg))
//--#define HDMI_PCTPSR0_pcth_shift                                       (8)
//--#define HDMI_PCTPSR0_pctl_shift                                       (0)
//--#define HDMI_PCTPSR0_pcth_mask                                        (0x0000FF00)
//--#define HDMI_PCTPSR0_pctl_mask                                        (0x000000FF)
//--#define HDMI_PCTPSR0_pcth(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_PCTPSR0_pctl(data)                                       (0x000000FF&(data))
//--#define HDMI_PCTPSR0_get_pcth(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_PCTPSR0_get_pctl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_ICBPSR0                                                  0x1800d338
//--#define HDMI_ICBPSR0_reg_addr                                         "0xb800d338"
//--#define HDMI_ICBPSR0_reg                                              0xb800d338
//--#define HDMI_ICBPSR0_inst_addr                                        "0x00CE"
//--#define HDMI_ICBPSR0_inst                                             0x00CE
//--#define set_HDMI_ICBPSR0_reg(data)                                    (*((volatile unsigned int*)HDMI_ICBPSR0_reg)=data)
//--#define get_HDMI_ICBPSR0_reg                                          (*((volatile unsigned int*)HDMI_ICBPSR0_reg))
//--#define HDMI_ICBPSR0_icbh_shift                                       (8)
//--#define HDMI_ICBPSR0_icbl_shift                                       (0)
//--#define HDMI_ICBPSR0_icbh_mask                                        (0x0000FF00)
//--#define HDMI_ICBPSR0_icbl_mask                                        (0x000000FF)
//--#define HDMI_ICBPSR0_icbh(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_ICBPSR0_icbl(data)                                       (0x000000FF&(data))
//--#define HDMI_ICBPSR0_get_icbh(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_ICBPSR0_get_icbl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_PCBPSR0                                                  0x1800d33c
//--#define HDMI_PCBPSR0_reg_addr                                         "0xb800d33c"
//--#define HDMI_PCBPSR0_reg                                              0xb800d33c
//--#define HDMI_PCBPSR0_inst_addr                                        "0x00CF"
//--#define HDMI_PCBPSR0_inst                                             0x00CF
//--#define set_HDMI_PCBPSR0_reg(data)                                    (*((volatile unsigned int*)HDMI_PCBPSR0_reg)=data)
//--#define get_HDMI_PCBPSR0_reg                                          (*((volatile unsigned int*)HDMI_PCBPSR0_reg))
//--#define HDMI_PCBPSR0_pcbh_shift                                       (8)
//--#define HDMI_PCBPSR0_pcbl_shift                                       (0)
//--#define HDMI_PCBPSR0_pcbh_mask                                        (0x0000FF00)
//--#define HDMI_PCBPSR0_pcbl_mask                                        (0x000000FF)
//--#define HDMI_PCBPSR0_pcbh(data)                                       (0x0000FF00&((data)<<8))
//--#define HDMI_PCBPSR0_pcbl(data)                                       (0x000000FF&(data))
//--#define HDMI_PCBPSR0_get_pcbh(data)                                   ((0x0000FF00&(data))>>8)
//--#define HDMI_PCBPSR0_get_pcbl(data)                                   (0x000000FF&(data))
//--
//--
//--#define HDMI_NTX1024TR0                                               0x1800d340
//--#define HDMI_NTX1024TR0_reg_addr                                      "0xb800d340"
//--#define HDMI_NTX1024TR0_reg                                           0xb800d340
//--#define HDMI_NTX1024TR0_inst_addr                                     "0x00D0"
//--#define HDMI_NTX1024TR0_inst                                          0x00D0
//--#define set_HDMI_NTX1024TR0_reg(data)                                 (*((volatile unsigned int*)HDMI_NTX1024TR0_reg)=data)
//--#define get_HDMI_NTX1024TR0_reg                                       (*((volatile unsigned int*)HDMI_NTX1024TR0_reg))
//--#define HDMI_NTX1024TR0_rm_shift                                      (12)
//--#define HDMI_NTX1024TR0_nt_shift                                      (0)
//--#define HDMI_NTX1024TR0_rm_mask                                       (0x00001000)
//--#define HDMI_NTX1024TR0_nt_mask                                       (0x00000FFF)
//--#define HDMI_NTX1024TR0_rm(data)                                      (0x00001000&((data)<<12))
//--#define HDMI_NTX1024TR0_nt(data)                                      (0x00000FFF&(data))
//--#define HDMI_NTX1024TR0_get_rm(data)                                  ((0x00001000&(data))>>12)
//--#define HDMI_NTX1024TR0_get_nt(data)                                  (0x00000FFF&(data))
//--
//--
//--#define HDMI_STBPR                                                    0x1800d344
//--#define HDMI_STBPR_reg_addr                                           "0xb800d344"
//--#define HDMI_STBPR_reg                                                0xb800d344
//--#define HDMI_STBPR_inst_addr                                          "0x00D1"
//--#define HDMI_STBPR_inst                                               0x00D1
//--#define set_HDMI_STBPR_reg(data)                                      (*((volatile unsigned int*)HDMI_STBPR_reg)=data)
//--#define get_HDMI_STBPR_reg                                            (*((volatile unsigned int*)HDMI_STBPR_reg))
//--#define HDMI_STBPR_ftb_shift                                          (0)
//--#define HDMI_STBPR_ftb_mask                                           (0x000000FF)
//--#define HDMI_STBPR_ftb(data)                                          (0x000000FF&(data))
//--#define HDMI_STBPR_get_ftb(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_NCPER                                                    0x1800d348
//--#define HDMI_NCPER_reg_addr                                           "0xb800d348"
//--#define HDMI_NCPER_reg                                                0xb800d348
//--#define HDMI_NCPER_inst_addr                                          "0x00D2"
//--#define HDMI_NCPER_inst                                               0x00D2
//--#define set_HDMI_NCPER_reg(data)                                      (*((volatile unsigned int*)HDMI_NCPER_reg)=data)
//--#define get_HDMI_NCPER_reg                                            (*((volatile unsigned int*)HDMI_NCPER_reg))
//--#define HDMI_NCPER_ncper_shift                                        (0)
//--#define HDMI_NCPER_ncper_mask                                         (0x000000FF)
//--#define HDMI_NCPER_ncper(data)                                        (0x000000FF&(data))
//--#define HDMI_NCPER_get_ncper(data)                                    (0x000000FF&(data))
//--
//--
//--#define HDMI_PETR                                                     0x1800d34c
//--#define HDMI_PETR_reg_addr                                            "0xb800d34c"
//--#define HDMI_PETR_reg                                                 0xb800d34c
//--#define HDMI_PETR_inst_addr                                           "0x00D3"
//--#define HDMI_PETR_inst                                                0x00D3
//--#define set_HDMI_PETR_reg(data)                                       (*((volatile unsigned int*)HDMI_PETR_reg)=data)
//--#define get_HDMI_PETR_reg                                             (*((volatile unsigned int*)HDMI_PETR_reg))
//--#define HDMI_PETR_petr_shift                                          (0)
//--#define HDMI_PETR_petr_mask                                           (0x000000FF)
//--#define HDMI_PETR_petr(data)                                          (0x000000FF&(data))
//--#define HDMI_PETR_get_petr(data)                                      (0x000000FF&(data))
//--
//--
//--#define HDMI_AAPNR                                                    0x1800d350
//--#define HDMI_AAPNR_reg_addr                                           "0xb800d350"
//--#define HDMI_AAPNR_reg                                                0xb800d350
//--#define HDMI_AAPNR_inst_addr                                          "0x00D4"
//--#define HDMI_AAPNR_inst                                               0x00D4
//--#define set_HDMI_AAPNR_reg(data)                                      (*((volatile unsigned int*)HDMI_AAPNR_reg)=data)
//--#define get_HDMI_AAPNR_reg                                            (*((volatile unsigned int*)HDMI_AAPNR_reg))
//--#define HDMI_AAPNR_cmvtc_shift                                        (7)
//--#define HDMI_AAPNR_cmvbc_shift                                        (6)
//--#define HDMI_AAPNR_ssdmou_shift                                       (5)
//--#define HDMI_AAPNR_tef_shift                                          (4)
//--#define HDMI_AAPNR_w1c5_shift                                         (3)
//--#define HDMI_AAPNR_pem_shift                                          (2)
//--#define HDMI_AAPNR_esdm_shift                                         (1)
//--#define HDMI_AAPNR_dummy1800d350_0_shift                              (0)
//--#define HDMI_AAPNR_cmvtc_mask                                         (0x00000080)
//--#define HDMI_AAPNR_cmvbc_mask                                         (0x00000040)
//--#define HDMI_AAPNR_ssdmou_mask                                        (0x00000020)
//--#define HDMI_AAPNR_tef_mask                                           (0x00000010)
//--#define HDMI_AAPNR_w1c5_mask                                          (0x00000008)
//--#define HDMI_AAPNR_pem_mask                                           (0x00000004)
//--#define HDMI_AAPNR_esdm_mask                                          (0x00000002)
//--#define HDMI_AAPNR_dummy1800d350_0_mask                               (0x00000001)
//--#define HDMI_AAPNR_cmvtc(data)                                        (0x00000080&((data)<<7))
//--#define HDMI_AAPNR_cmvbc(data)                                        (0x00000040&((data)<<6))
//--#define HDMI_AAPNR_ssdmou(data)                                       (0x00000020&((data)<<5))
//--#define HDMI_AAPNR_tef(data)                                          (0x00000010&((data)<<4))
//--#define HDMI_AAPNR_w1c5(data)                                         (0x00000008&((data)<<3))
//--#define HDMI_AAPNR_pem(data)                                          (0x00000004&((data)<<2))
//--#define HDMI_AAPNR_esdm(data)                                         (0x00000002&((data)<<1))
//--#define HDMI_AAPNR_dummy1800d350_0(data)                              (0x00000001&(data))
//--#define HDMI_AAPNR_get_cmvtc(data)                                    ((0x00000080&(data))>>7)
//--#define HDMI_AAPNR_get_cmvbc(data)                                    ((0x00000040&(data))>>6)
//--#define HDMI_AAPNR_get_ssdmou(data)                                   ((0x00000020&(data))>>5)
//--#define HDMI_AAPNR_get_tef(data)                                      ((0x00000010&(data))>>4)
//--#define HDMI_AAPNR_get_w1c5(data)                                     ((0x00000008&(data))>>3)
//--#define HDMI_AAPNR_get_pem(data)                                      ((0x00000004&(data))>>2)
//--#define HDMI_AAPNR_get_esdm(data)                                     ((0x00000002&(data))>>1)
//--#define HDMI_AAPNR_get_dummy1800d350_0(data)                          (0x00000001&(data))
//--
//--
//--#define HDMI_APDMCR                                                   0x1800d354
//--#define HDMI_APDMCR_reg_addr                                          "0xb800d354"
//--#define HDMI_APDMCR_reg                                               0xb800d354
//--#define HDMI_APDMCR_inst_addr                                         "0x00D5"
//--#define HDMI_APDMCR_inst                                              0x00D5
//--#define set_HDMI_APDMCR_reg(data)                                     (*((volatile unsigned int*)HDMI_APDMCR_reg)=data)
//--#define get_HDMI_APDMCR_reg                                           (*((volatile unsigned int*)HDMI_APDMCR_reg))
//--#define HDMI_APDMCR_dummy1800d354_7_shift                             (7)
//--#define HDMI_APDMCR_dummy1800d354_6_shift                             (6)
//--#define HDMI_APDMCR_edm_shift                                         (5)
//--#define HDMI_APDMCR_pst_shift                                         (4)
//--#define HDMI_APDMCR_psc_shift                                         (0)
//--#define HDMI_APDMCR_dummy1800d354_7_mask                              (0x00000080)
//--#define HDMI_APDMCR_dummy1800d354_6_mask                              (0x00000040)
//--#define HDMI_APDMCR_edm_mask                                          (0x00000020)
//--#define HDMI_APDMCR_pst_mask                                          (0x00000010)
//--#define HDMI_APDMCR_psc_mask                                          (0x0000000F)
//--#define HDMI_APDMCR_dummy1800d354_7(data)                             (0x00000080&((data)<<7))
//--#define HDMI_APDMCR_dummy1800d354_6(data)                             (0x00000040&((data)<<6))
//--#define HDMI_APDMCR_edm(data)                                         (0x00000020&((data)<<5))
//--#define HDMI_APDMCR_pst(data)                                         (0x00000010&((data)<<4))
//--#define HDMI_APDMCR_psc(data)                                         (0x0000000F&(data))
//--#define HDMI_APDMCR_get_dummy1800d354_7(data)                         ((0x00000080&(data))>>7)
//--#define HDMI_APDMCR_get_dummy1800d354_6(data)                         ((0x00000040&(data))>>6)
//--#define HDMI_APDMCR_get_edm(data)                                     ((0x00000020&(data))>>5)
//--#define HDMI_APDMCR_get_pst(data)                                     ((0x00000010&(data))>>4)
//--#define HDMI_APDMCR_get_psc(data)                                     (0x0000000F&(data))
//--
//--
//--#define HDMI_APTMCR0                                                  0x1800d358
//--#define HDMI_APTMCR0_reg_addr                                         "0xb800d358"
//--#define HDMI_APTMCR0_reg                                              0xb800d358
//--#define HDMI_APTMCR0_inst_addr                                        "0x00D6"
//--#define HDMI_APTMCR0_inst                                             0x00D6
//--#define set_HDMI_APTMCR0_reg(data)                                    (*((volatile unsigned int*)HDMI_APTMCR0_reg)=data)
//--#define get_HDMI_APTMCR0_reg                                          (*((volatile unsigned int*)HDMI_APTMCR0_reg))
//--#define HDMI_APTMCR0_fps_shift                                        (4)
//--#define HDMI_APTMCR0_sps_shift                                        (0)
//--#define HDMI_APTMCR0_fps_mask                                         (0x000000F0)
//--#define HDMI_APTMCR0_sps_mask                                         (0x0000000F)
//--#define HDMI_APTMCR0_fps(data)                                        (0x000000F0&((data)<<4))
//--#define HDMI_APTMCR0_sps(data)                                        (0x0000000F&(data))
//--#define HDMI_APTMCR0_get_fps(data)                                    ((0x000000F0&(data))>>4)
//--#define HDMI_APTMCR0_get_sps(data)                                    (0x0000000F&(data))
//--
//--
//--#define HDMI_APTMCR1                                                  0x1800d35c
//--#define HDMI_APTMCR1_reg_addr                                         "0xb800d35c"
//--#define HDMI_APTMCR1_reg                                              0xb800d35c
//--#define HDMI_APTMCR1_inst_addr                                        "0x00D7"
//--#define HDMI_APTMCR1_inst                                             0x00D7
//--#define set_HDMI_APTMCR1_reg(data)                                    (*((volatile unsigned int*)HDMI_APTMCR1_reg)=data)
//--#define get_HDMI_APTMCR1_reg                                          (*((volatile unsigned int*)HDMI_APTMCR1_reg))
//--#define HDMI_APTMCR1_plltm_shift                                      (6)
//--#define HDMI_APTMCR1_fpsd_shift                                       (5)
//--#define HDMI_APTMCR1_spsd_shift                                       (4)
//--#define HDMI_APTMCR1_nfpss_shift                                      (0)
//--#define HDMI_APTMCR1_plltm_mask                                       (0x00000040)
//--#define HDMI_APTMCR1_fpsd_mask                                        (0x00000020)
//--#define HDMI_APTMCR1_spsd_mask                                        (0x00000010)
//--#define HDMI_APTMCR1_nfpss_mask                                       (0x0000000F)
//--#define HDMI_APTMCR1_plltm(data)                                      (0x00000040&((data)<<6))
//--#define HDMI_APTMCR1_fpsd(data)                                       (0x00000020&((data)<<5))
//--#define HDMI_APTMCR1_spsd(data)                                       (0x00000010&((data)<<4))
//--#define HDMI_APTMCR1_nfpss(data)                                      (0x0000000F&(data))
//--#define HDMI_APTMCR1_get_plltm(data)                                  ((0x00000040&(data))>>6)
//--#define HDMI_APTMCR1_get_fpsd(data)                                   ((0x00000020&(data))>>5)
//--#define HDMI_APTMCR1_get_spsd(data)                                   ((0x00000010&(data))>>4)
//--#define HDMI_APTMCR1_get_nfpss(data)                                  (0x0000000F&(data))
//--
//--
//--#define HDMI_NPECR                                                    0x1800d360
//--#define HDMI_NPECR_reg_addr                                           "0xb800d360"
//--#define HDMI_NPECR_reg                                                0xb800d360
//--#define HDMI_NPECR_inst_addr                                          "0x00D8"
//--#define HDMI_NPECR_inst                                               0x00D8
//--#define set_HDMI_NPECR_reg(data)                                      (*((volatile unsigned int*)HDMI_NPECR_reg)=data)
//--#define get_HDMI_NPECR_reg                                            (*((volatile unsigned int*)HDMI_NPECR_reg))
//--#define HDMI_NPECR_ncts_disable_pe_check_en_shift                     (31)
//--#define HDMI_NPECR_ncts_re_enable_off_en_shift                        (30)
//--#define HDMI_NPECR_ncts_disable_pe_check_status_shift                 (29)
//--#define HDMI_NPECR_ncts_disable_pe_check_irq_en_shift                 (28)
//--#define HDMI_NPECR_dummy1800d360_27_20_shift                          (20)
//--#define HDMI_NPECR_ncts_disable_pe_check_cnt_shift                    (0)
//--#define HDMI_NPECR_ncts_disable_pe_check_en_mask                      (0x80000000)
//--#define HDMI_NPECR_ncts_re_enable_off_en_mask                         (0x40000000)
//--#define HDMI_NPECR_ncts_disable_pe_check_status_mask                  (0x20000000)
//--#define HDMI_NPECR_ncts_disable_pe_check_irq_en_mask                  (0x10000000)
//--#define HDMI_NPECR_dummy1800d360_27_20_mask                           (0x0FF00000)
//--#define HDMI_NPECR_ncts_disable_pe_check_cnt_mask                     (0x000FFFFF)
//--#define HDMI_NPECR_ncts_disable_pe_check_en(data)                     (0x80000000&((data)<<31))
//--#define HDMI_NPECR_ncts_re_enable_off_en(data)                        (0x40000000&((data)<<30))
//--#define HDMI_NPECR_ncts_disable_pe_check_status(data)                 (0x20000000&((data)<<29))
//--#define HDMI_NPECR_ncts_disable_pe_check_irq_en(data)                 (0x10000000&((data)<<28))
//--#define HDMI_NPECR_dummy1800d360_27_20(data)                          (0x0FF00000&((data)<<20))
//--#define HDMI_NPECR_ncts_disable_pe_check_cnt(data)                    (0x000FFFFF&(data))
//--#define HDMI_NPECR_get_ncts_disable_pe_check_en(data)                 ((0x80000000&(data))>>31)
//--#define HDMI_NPECR_get_ncts_re_enable_off_en(data)                    ((0x40000000&(data))>>30)
//--#define HDMI_NPECR_get_ncts_disable_pe_check_status(data)             ((0x20000000&(data))>>29)
//--#define HDMI_NPECR_get_ncts_disable_pe_check_irq_en(data)             ((0x10000000&(data))>>28)
//--#define HDMI_NPECR_get_dummy1800d360_27_20(data)                      ((0x0FF00000&(data))>>20)
//--#define HDMI_NPECR_get_ncts_disable_pe_check_cnt(data)                (0x000FFFFF&(data))
//--
//--
//--#define HDMI_NROR                                                     0x1800d364
//--#define HDMI_NROR_reg_addr                                            "0xb800d364"
//--#define HDMI_NROR_reg                                                 0xb800d364
//--#define HDMI_NROR_inst_addr                                           "0x00D9"
//--#define HDMI_NROR_inst                                                0x00D9
//--#define set_HDMI_NROR_reg(data)                                       (*((volatile unsigned int*)HDMI_NROR_reg)=data)
//--#define get_HDMI_NROR_reg                                             (*((volatile unsigned int*)HDMI_NROR_reg))
//--#define HDMI_NROR_ncts_re_enable_off_start_shift                      (16)
//--#define HDMI_NROR_ncts_re_enable_off_end_shift                        (0)
//--#define HDMI_NROR_ncts_re_enable_off_start_mask                       (0xFFFF0000)
//--#define HDMI_NROR_ncts_re_enable_off_end_mask                         (0x0000FFFF)
//--#define HDMI_NROR_ncts_re_enable_off_start(data)                      (0xFFFF0000&((data)<<16))
//--#define HDMI_NROR_ncts_re_enable_off_end(data)                        (0x0000FFFF&(data))
//--#define HDMI_NROR_get_ncts_re_enable_off_start(data)                  ((0xFFFF0000&(data))>>16)
//--#define HDMI_NROR_get_ncts_re_enable_off_end(data)                    (0x0000FFFF&(data))
//--
//--
//--#define HDMI_NTX1024TR0_THRESHOLD                                     0x1800d368
//--#define HDMI_NTX1024TR0_THRESHOLD_reg_addr                            "0xb800d368"
//--#define HDMI_NTX1024TR0_THRESHOLD_reg                                 0xb800d368
//--#define HDMI_NTX1024TR0_THRESHOLD_inst_addr                           "0x00DA"
//--#define HDMI_NTX1024TR0_THRESHOLD_inst                                0x00DA
//--#define set_HDMI_NTX1024TR0_THRESHOLD_reg(data)                       (*((volatile unsigned int*)HDMI_NTX1024TR0_THRESHOLD_reg)=data)
//--#define get_HDMI_NTX1024TR0_THRESHOLD_reg                             (*((volatile unsigned int*)HDMI_NTX1024TR0_THRESHOLD_reg))
//--#define HDMI_NTX1024TR0_THRESHOLD_over_threshold_shift                (31)
//--#define HDMI_NTX1024TR0_THRESHOLD_under_threshold_shift               (30)
//--#define HDMI_NTX1024TR0_THRESHOLD_wd_by_tmds_clk_shift                (29)
//--#define HDMI_NTX1024TR0_THRESHOLD_irq_by_tmds_clk_shift               (28)
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_up_threshold_shift               (16)
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_low_threshold_shift              (0)
//--#define HDMI_NTX1024TR0_THRESHOLD_over_threshold_mask                 (0x80000000)
//--#define HDMI_NTX1024TR0_THRESHOLD_under_threshold_mask                (0x40000000)
//--#define HDMI_NTX1024TR0_THRESHOLD_wd_by_tmds_clk_mask                 (0x20000000)
//--#define HDMI_NTX1024TR0_THRESHOLD_irq_by_tmds_clk_mask                (0x10000000)
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_up_threshold_mask                (0x0FFF0000)
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_low_threshold_mask               (0x00000FFF)
//--#define HDMI_NTX1024TR0_THRESHOLD_over_threshold(data)                (0x80000000&((data)<<31))
//--#define HDMI_NTX1024TR0_THRESHOLD_under_threshold(data)               (0x40000000&((data)<<30))
//--#define HDMI_NTX1024TR0_THRESHOLD_wd_by_tmds_clk(data)                (0x20000000&((data)<<29))
//--#define HDMI_NTX1024TR0_THRESHOLD_irq_by_tmds_clk(data)               (0x10000000&((data)<<28))
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_up_threshold(data)               (0x0FFF0000&((data)<<16))
//--#define HDMI_NTX1024TR0_THRESHOLD_nt_low_threshold(data)              (0x00000FFF&(data))
//--#define HDMI_NTX1024TR0_THRESHOLD_get_over_threshold(data)            ((0x80000000&(data))>>31)
//--#define HDMI_NTX1024TR0_THRESHOLD_get_under_threshold(data)           ((0x40000000&(data))>>30)
//--#define HDMI_NTX1024TR0_THRESHOLD_get_wd_by_tmds_clk(data)            ((0x20000000&(data))>>29)
//--#define HDMI_NTX1024TR0_THRESHOLD_get_irq_by_tmds_clk(data)           ((0x10000000&(data))>>28)
//--#define HDMI_NTX1024TR0_THRESHOLD_get_nt_up_threshold(data)           ((0x0FFF0000&(data))>>16)
//--#define HDMI_NTX1024TR0_THRESHOLD_get_nt_low_threshold(data)          (0x00000FFF&(data))
//--
//--
//--#define HDMI_APLLCR0                                                  0x1800d380
//--#define HDMI_APLLCR0_reg_addr                                         "0xb800d380"
//--#define HDMI_APLLCR0_reg                                              0xb800d380
//--#define HDMI_APLLCR0_inst_addr                                        "0x00E0"
//--#define HDMI_APLLCR0_inst                                             0x00E0
//--#define set_HDMI_APLLCR0_reg(data)                                    (*((volatile unsigned int*)HDMI_APLLCR0_reg)=data)
//--#define get_HDMI_APLLCR0_reg                                          (*((volatile unsigned int*)HDMI_APLLCR0_reg))
//--#define HDMI_APLLCR0_dpll_reg_shift                                   (30)
//--#define HDMI_APLLCR0_dpll_m_shift                                     (22)
//--#define HDMI_APLLCR0_dpll_reser_shift                                 (17)
//--#define HDMI_APLLCR0_dpll_bpn_shift                                   (16)
//--#define HDMI_APLLCR0_dpll_o_shift                                     (14)
//--#define HDMI_APLLCR0_dpll_n_shift                                     (6)
//--#define HDMI_APLLCR0_dpll_rs_shift                                    (3)
//--#define HDMI_APLLCR0_dpll_ip_shift                                    (0)
//--#define HDMI_APLLCR0_dpll_reg_mask                                    (0xC0000000)
//--#define HDMI_APLLCR0_dpll_m_mask                                      (0x3FC00000)
//--#define HDMI_APLLCR0_dpll_reser_mask                                  (0x001E0000)
//--#define HDMI_APLLCR0_dpll_bpn_mask                                    (0x00010000)
//--#define HDMI_APLLCR0_dpll_o_mask                                      (0x0000C000)
//--#define HDMI_APLLCR0_dpll_n_mask                                      (0x000001C0)
//--#define HDMI_APLLCR0_dpll_rs_mask                                     (0x00000038)
//--#define HDMI_APLLCR0_dpll_ip_mask                                     (0x00000007)
//--#define HDMI_APLLCR0_dpll_reg(data)                                   (0xC0000000&((data)<<30))
//--#define HDMI_APLLCR0_dpll_m(data)                                     (0x3FC00000&((data)<<22))
//--#define HDMI_APLLCR0_dpll_reser(data)                                 (0x001E0000&((data)<<17))
//--#define HDMI_APLLCR0_dpll_bpn(data)                                   (0x00010000&((data)<<16))
//--#define HDMI_APLLCR0_dpll_o(data)                                     (0x0000C000&((data)<<14))
//--#define HDMI_APLLCR0_dpll_n(data)                                     (0x000001C0&((data)<<6))
//--#define HDMI_APLLCR0_dpll_rs(data)                                    (0x00000038&((data)<<3))
//--#define HDMI_APLLCR0_dpll_ip(data)                                    (0x00000007&(data))
//--#define HDMI_APLLCR0_get_dpll_reg(data)                               ((0xC0000000&(data))>>30)
//--#define HDMI_APLLCR0_get_dpll_m(data)                                 ((0x3FC00000&(data))>>22)
//--#define HDMI_APLLCR0_get_dpll_reser(data)                             ((0x001E0000&(data))>>17)
//--#define HDMI_APLLCR0_get_dpll_bpn(data)                               ((0x00010000&(data))>>16)
//--#define HDMI_APLLCR0_get_dpll_o(data)                                 ((0x0000C000&(data))>>14)
//--#define HDMI_APLLCR0_get_dpll_n(data)                                 ((0x000001C0&(data))>>6)
//--#define HDMI_APLLCR0_get_dpll_rs(data)                                ((0x00000038&(data))>>3)
//--#define HDMI_APLLCR0_get_dpll_ip(data)                                (0x00000007&(data))
//--
//--
//--#define HDMI_APLLCR1                                                  0x1800d384
//--#define HDMI_APLLCR1_reg_addr                                         "0xb800d384"
//--#define HDMI_APLLCR1_reg                                              0xb800d384
//--#define HDMI_APLLCR1_inst_addr                                        "0x00E1"
//--#define HDMI_APLLCR1_inst                                             0x00E1
//--#define set_HDMI_APLLCR1_reg(data)                                    (*((volatile unsigned int*)HDMI_APLLCR1_reg)=data)
//--#define get_HDMI_APLLCR1_reg                                          (*((volatile unsigned int*)HDMI_APLLCR1_reg))
//--#define HDMI_APLLCR1_dpll_cp_shift                                    (21)
//--#define HDMI_APLLCR1_dpll_seltst_shift                                (19)
//--#define HDMI_APLLCR1_dpll_cs_shift                                    (17)
//--#define HDMI_APLLCR1_dpll_reserve_shift                               (9)
//--#define HDMI_APLLCR1_dpll_bpphs_shift                                 (8)
//--#define HDMI_APLLCR1_dpll_wdo_shift                                   (7)
//--#define HDMI_APLLCR1_dpll_wdrst_shift                                 (6)
//--#define HDMI_APLLCR1_dpll_wdset_shift                                 (5)
//--#define HDMI_APLLCR1_dummy1800d384_4_shift                            (4)
//--#define HDMI_APLLCR1_dpll_stop_shift                                  (3)
//--#define HDMI_APLLCR1_dpll_freeze_shift                                (2)
//--#define HDMI_APLLCR1_dpll_vcorstb_shift                               (1)
//--#define HDMI_APLLCR1_dpll_pwdn_shift                                  (0)
//--#define HDMI_APLLCR1_dpll_cp_mask                                     (0x00600000)
//--#define HDMI_APLLCR1_dpll_seltst_mask                                 (0x00180000)
//--#define HDMI_APLLCR1_dpll_cs_mask                                     (0x00060000)
//--#define HDMI_APLLCR1_dpll_reserve_mask                                (0x00000200)
//--#define HDMI_APLLCR1_dpll_bpphs_mask                                  (0x00000100)
//--#define HDMI_APLLCR1_dpll_wdo_mask                                    (0x00000080)
//--#define HDMI_APLLCR1_dpll_wdrst_mask                                  (0x00000040)
//--#define HDMI_APLLCR1_dpll_wdset_mask                                  (0x00000020)
//--#define HDMI_APLLCR1_dummy1800d384_4_mask                             (0x00000010)
//--#define HDMI_APLLCR1_dpll_stop_mask                                   (0x00000008)
//--#define HDMI_APLLCR1_dpll_freeze_mask                                 (0x00000004)
//--#define HDMI_APLLCR1_dpll_vcorstb_mask                                (0x00000002)
//--#define HDMI_APLLCR1_dpll_pwdn_mask                                   (0x00000001)
//--#define HDMI_APLLCR1_dpll_cp(data)                                    (0x00600000&((data)<<21))
//--#define HDMI_APLLCR1_dpll_seltst(data)                                (0x00180000&((data)<<19))
//--#define HDMI_APLLCR1_dpll_cs(data)                                    (0x00060000&((data)<<17))
//--#define HDMI_APLLCR1_dpll_reserve(data)                               (0x00000200&((data)<<9))
//--#define HDMI_APLLCR1_dpll_bpphs(data)                                 (0x00000100&((data)<<8))
//--#define HDMI_APLLCR1_dpll_wdo(data)                                   (0x00000080&((data)<<7))
//--#define HDMI_APLLCR1_dpll_wdrst(data)                                 (0x00000040&((data)<<6))
//--#define HDMI_APLLCR1_dpll_wdset(data)                                 (0x00000020&((data)<<5))
//--#define HDMI_APLLCR1_dummy1800d384_4(data)                            (0x00000010&((data)<<4))
//--#define HDMI_APLLCR1_dpll_stop(data)                                  (0x00000008&((data)<<3))
//--#define HDMI_APLLCR1_dpll_freeze(data)                                (0x00000004&((data)<<2))
//--#define HDMI_APLLCR1_dpll_vcorstb(data)                               (0x00000002&((data)<<1))
//--#define HDMI_APLLCR1_dpll_pwdn(data)                                  (0x00000001&(data))
//--#define HDMI_APLLCR1_get_dpll_cp(data)                                ((0x00600000&(data))>>21)
//--#define HDMI_APLLCR1_get_dpll_seltst(data)                            ((0x00180000&(data))>>19)
//--#define HDMI_APLLCR1_get_dpll_cs(data)                                ((0x00060000&(data))>>17)
//--#define HDMI_APLLCR1_get_dpll_reserve(data)                           ((0x00000200&(data))>>9)
//--#define HDMI_APLLCR1_get_dpll_bpphs(data)                             ((0x00000100&(data))>>8)
//--#define HDMI_APLLCR1_get_dpll_wdo(data)                               ((0x00000080&(data))>>7)
//--#define HDMI_APLLCR1_get_dpll_wdrst(data)                             ((0x00000040&(data))>>6)
//--#define HDMI_APLLCR1_get_dpll_wdset(data)                             ((0x00000020&(data))>>5)
//--#define HDMI_APLLCR1_get_dummy1800d384_4(data)                        ((0x00000010&(data))>>4)
//--#define HDMI_APLLCR1_get_dpll_stop(data)                              ((0x00000008&(data))>>3)
//--#define HDMI_APLLCR1_get_dpll_freeze(data)                            ((0x00000004&(data))>>2)
//--#define HDMI_APLLCR1_get_dpll_vcorstb(data)                           ((0x00000002&(data))>>1)
//--#define HDMI_APLLCR1_get_dpll_pwdn(data)                              (0x00000001&(data))
//--
//--
//--#define HDMI_APLLCR2                                                  0x1800d388
//--#define HDMI_APLLCR2_reg_addr                                         "0xb800d388"
//--#define HDMI_APLLCR2_reg                                              0xb800d388
//--#define HDMI_APLLCR2_inst_addr                                        "0x00E2"
//--#define HDMI_APLLCR2_inst                                             0x00E2
//--#define set_HDMI_APLLCR2_reg(data)                                    (*((volatile unsigned int*)HDMI_APLLCR2_reg)=data)
//--#define get_HDMI_APLLCR2_reg                                          (*((volatile unsigned int*)HDMI_APLLCR2_reg))
//--#define HDMI_APLLCR2_dpll_rloadm_shift                                (0)
//--#define HDMI_APLLCR2_dpll_rloadm_mask                                 (0x00000001)
//--#define HDMI_APLLCR2_dpll_rloadm(data)                                (0x00000001&(data))
//--#define HDMI_APLLCR2_get_dpll_rloadm(data)                            (0x00000001&(data))
//--
//--
//--#define HDMI_APLLCR3                                                  0x1800d38c
//--#define HDMI_APLLCR3_reg_addr                                         "0xb800d38c"
//--#define HDMI_APLLCR3_reg                                              0xb800d38c
//--#define HDMI_APLLCR3_inst_addr                                        "0x00E3"
//--#define HDMI_APLLCR3_inst                                             0x00E3
//--#define set_HDMI_APLLCR3_reg(data)                                    (*((volatile unsigned int*)HDMI_APLLCR3_reg)=data)
//--#define get_HDMI_APLLCR3_reg                                          (*((volatile unsigned int*)HDMI_APLLCR3_reg))
//--#define HDMI_APLLCR3_sum_c_samp_shift                                 (0)
//--#define HDMI_APLLCR3_sum_c_samp_mask                                  (0x0000FFFF)
//--#define HDMI_APLLCR3_sum_c_samp(data)                                 (0x0000FFFF&(data))
//--#define HDMI_APLLCR3_get_sum_c_samp(data)                             (0x0000FFFF&(data))
//--
//--
//--#define HDMI_APLL_TESTM                                               0x1800d390
//--#define HDMI_APLL_TESTM_reg_addr                                      "0xb800d390"
//--#define HDMI_APLL_TESTM_reg                                           0xb800d390
//--#define HDMI_APLL_TESTM_inst_addr                                     "0x00E4"
//--#define HDMI_APLL_TESTM_inst                                          0x00E4
//--#define set_HDMI_APLL_TESTM_reg(data)                                 (*((volatile unsigned int*)HDMI_APLL_TESTM_reg)=data)
//--#define get_HDMI_APLL_TESTM_reg                                       (*((volatile unsigned int*)HDMI_APLL_TESTM_reg))
//--#define HDMI_APLL_TESTM_dpll_m_test_shift                             (22)
//--#define HDMI_APLL_TESTM_dpll_m_db_shift                               (1)
//--#define HDMI_APLL_TESTM_dpll_m_sel_shift                              (0)
//--#define HDMI_APLL_TESTM_dpll_m_test_mask                              (0x3FC00000)
//--#define HDMI_APLL_TESTM_dpll_m_db_mask                                (0x00000002)
//--#define HDMI_APLL_TESTM_dpll_m_sel_mask                               (0x00000001)
//--#define HDMI_APLL_TESTM_dpll_m_test(data)                             (0x3FC00000&((data)<<22))
//--#define HDMI_APLL_TESTM_dpll_m_db(data)                               (0x00000002&((data)<<1))
//--#define HDMI_APLL_TESTM_dpll_m_sel(data)                              (0x00000001&(data))
//--#define HDMI_APLL_TESTM_get_dpll_m_test(data)                         ((0x3FC00000&(data))>>22)
//--#define HDMI_APLL_TESTM_get_dpll_m_db(data)                           ((0x00000002&(data))>>1)
//--#define HDMI_APLL_TESTM_get_dpll_m_sel(data)                          (0x00000001&(data))
//--
//--
//--#define HDMI_VPLLCR0                                                  0x1800d400
//--#define HDMI_VPLLCR0_reg_addr                                         "0xb800d400"
//--#define HDMI_VPLLCR0_reg                                              0xb800d400
//--#define HDMI_VPLLCR0_inst_addr                                        "0x0100"
//--#define HDMI_VPLLCR0_inst                                             0x0100
//--#define set_HDMI_VPLLCR0_reg(data)                                    (*((volatile unsigned int*)HDMI_VPLLCR0_reg)=data)
//--#define get_HDMI_VPLLCR0_reg                                          (*((volatile unsigned int*)HDMI_VPLLCR0_reg))
//--#define HDMI_VPLLCR0_dpll_reg_shift                                   (30)
//--#define HDMI_VPLLCR0_dpll_m_shift                                     (22)
//--#define HDMI_VPLLCR0_dpll_reser_shift                                 (17)
//--#define HDMI_VPLLCR0_dpll_bpn_shift                                   (16)
//--#define HDMI_VPLLCR0_dpll_o_shift                                     (14)
//--#define HDMI_VPLLCR0_dpll_n_shift                                     (6)
//--#define HDMI_VPLLCR0_dpll_rs_shift                                    (3)
//--#define HDMI_VPLLCR0_dpll_ip_shift                                    (0)
//--#define HDMI_VPLLCR0_dpll_reg_mask                                    (0xC0000000)
//--#define HDMI_VPLLCR0_dpll_m_mask                                      (0x3FC00000)
//--#define HDMI_VPLLCR0_dpll_reser_mask                                  (0x001E0000)
//--#define HDMI_VPLLCR0_dpll_bpn_mask                                    (0x00010000)
//--#define HDMI_VPLLCR0_dpll_o_mask                                      (0x0000C000)
//--#define HDMI_VPLLCR0_dpll_n_mask                                      (0x000001C0)
//--#define HDMI_VPLLCR0_dpll_rs_mask                                     (0x00000038)
//--#define HDMI_VPLLCR0_dpll_ip_mask                                     (0x00000007)
//--#define HDMI_VPLLCR0_dpll_reg(data)                                   (0xC0000000&((data)<<30))
//--#define HDMI_VPLLCR0_dpll_m(data)                                     (0x3FC00000&((data)<<22))
//--#define HDMI_VPLLCR0_dpll_reser(data)                                 (0x001E0000&((data)<<17))
//--#define HDMI_VPLLCR0_dpll_bpn(data)                                   (0x00010000&((data)<<16))
//--#define HDMI_VPLLCR0_dpll_o(data)                                     (0x0000C000&((data)<<14))
//--#define HDMI_VPLLCR0_dpll_n(data)                                     (0x000001C0&((data)<<6))
//--#define HDMI_VPLLCR0_dpll_rs(data)                                    (0x00000038&((data)<<3))
//--#define HDMI_VPLLCR0_dpll_ip(data)                                    (0x00000007&(data))
//--#define HDMI_VPLLCR0_get_dpll_reg(data)                               ((0xC0000000&(data))>>30)
//--#define HDMI_VPLLCR0_get_dpll_m(data)                                 ((0x3FC00000&(data))>>22)
//--#define HDMI_VPLLCR0_get_dpll_reser(data)                             ((0x001E0000&(data))>>17)
//--#define HDMI_VPLLCR0_get_dpll_bpn(data)                               ((0x00010000&(data))>>16)
//--#define HDMI_VPLLCR0_get_dpll_o(data)                                 ((0x0000C000&(data))>>14)
//--#define HDMI_VPLLCR0_get_dpll_n(data)                                 ((0x000001C0&(data))>>6)
//--#define HDMI_VPLLCR0_get_dpll_rs(data)                                ((0x00000038&(data))>>3)
//--#define HDMI_VPLLCR0_get_dpll_ip(data)                                (0x00000007&(data))
//--
//--
//--#define HDMI_VPLLCR1                                                  0x1800d404
//--#define HDMI_VPLLCR1_reg_addr                                         "0xb800d404"
//--#define HDMI_VPLLCR1_reg                                              0xb800d404
//--#define HDMI_VPLLCR1_inst_addr                                        "0x0101"
//--#define HDMI_VPLLCR1_inst                                             0x0101
//--#define set_HDMI_VPLLCR1_reg(data)                                    (*((volatile unsigned int*)HDMI_VPLLCR1_reg)=data)
//--#define get_HDMI_VPLLCR1_reg                                          (*((volatile unsigned int*)HDMI_VPLLCR1_reg))
//--#define HDMI_VPLLCR1_dpll_cp_shift                                    (21)
//--#define HDMI_VPLLCR1_dpll_seltst_shift                                (19)
//--#define HDMI_VPLLCR1_dpll_cs_shift                                    (17)
//--#define HDMI_VPLLCR1_dpll_reserve_shift                               (9)
//--#define HDMI_VPLLCR1_dpll_bpphs_shift                                 (8)
//--#define HDMI_VPLLCR1_dpll_wdo_shift                                   (7)
//--#define HDMI_VPLLCR1_dpll_wdrst_shift                                 (6)
//--#define HDMI_VPLLCR1_dpll_wdset_shift                                 (5)
//--#define HDMI_VPLLCR1_dummy1800d404_4_shift                            (4)
//--#define HDMI_VPLLCR1_dpll_stop_shift                                  (3)
//--#define HDMI_VPLLCR1_dpll_freeze_shift                                (2)
//--#define HDMI_VPLLCR1_dpll_vcorstb_shift                               (1)
//--#define HDMI_VPLLCR1_dpll_pwdn_shift                                  (0)
//--#define HDMI_VPLLCR1_dpll_cp_mask                                     (0x00600000)
//--#define HDMI_VPLLCR1_dpll_seltst_mask                                 (0x00180000)
//--#define HDMI_VPLLCR1_dpll_cs_mask                                     (0x00060000)
//--#define HDMI_VPLLCR1_dpll_reserve_mask                                (0x00000200)
//--#define HDMI_VPLLCR1_dpll_bpphs_mask                                  (0x00000100)
//--#define HDMI_VPLLCR1_dpll_wdo_mask                                    (0x00000080)
//--#define HDMI_VPLLCR1_dpll_wdrst_mask                                  (0x00000040)
//--#define HDMI_VPLLCR1_dpll_wdset_mask                                  (0x00000020)
//--#define HDMI_VPLLCR1_dummy1800d404_4_mask                             (0x00000010)
//--#define HDMI_VPLLCR1_dpll_stop_mask                                   (0x00000008)
//--#define HDMI_VPLLCR1_dpll_freeze_mask                                 (0x00000004)
//--#define HDMI_VPLLCR1_dpll_vcorstb_mask                                (0x00000002)
//--#define HDMI_VPLLCR1_dpll_pwdn_mask                                   (0x00000001)
//--#define HDMI_VPLLCR1_dpll_cp(data)                                    (0x00600000&((data)<<21))
//--#define HDMI_VPLLCR1_dpll_seltst(data)                                (0x00180000&((data)<<19))
//--#define HDMI_VPLLCR1_dpll_cs(data)                                    (0x00060000&((data)<<17))
//--#define HDMI_VPLLCR1_dpll_reserve(data)                               (0x00000200&((data)<<9))
//--#define HDMI_VPLLCR1_dpll_bpphs(data)                                 (0x00000100&((data)<<8))
//--#define HDMI_VPLLCR1_dpll_wdo(data)                                   (0x00000080&((data)<<7))
//--#define HDMI_VPLLCR1_dpll_wdrst(data)                                 (0x00000040&((data)<<6))
//--#define HDMI_VPLLCR1_dpll_wdset(data)                                 (0x00000020&((data)<<5))
//--#define HDMI_VPLLCR1_dummy1800d404_4(data)                            (0x00000010&((data)<<4))
//--#define HDMI_VPLLCR1_dpll_stop(data)                                  (0x00000008&((data)<<3))
//--#define HDMI_VPLLCR1_dpll_freeze(data)                                (0x00000004&((data)<<2))
//--#define HDMI_VPLLCR1_dpll_vcorstb(data)                               (0x00000002&((data)<<1))
//--#define HDMI_VPLLCR1_dpll_pwdn(data)                                  (0x00000001&(data))
//--#define HDMI_VPLLCR1_get_dpll_cp(data)                                ((0x00600000&(data))>>21)
//--#define HDMI_VPLLCR1_get_dpll_seltst(data)                            ((0x00180000&(data))>>19)
//--#define HDMI_VPLLCR1_get_dpll_cs(data)                                ((0x00060000&(data))>>17)
//--#define HDMI_VPLLCR1_get_dpll_reserve(data)                           ((0x00000200&(data))>>9)
//--#define HDMI_VPLLCR1_get_dpll_bpphs(data)                             ((0x00000100&(data))>>8)
//--#define HDMI_VPLLCR1_get_dpll_wdo(data)                               ((0x00000080&(data))>>7)
//--#define HDMI_VPLLCR1_get_dpll_wdrst(data)                             ((0x00000040&(data))>>6)
//--#define HDMI_VPLLCR1_get_dpll_wdset(data)                             ((0x00000020&(data))>>5)
//--#define HDMI_VPLLCR1_get_dummy1800d404_4(data)                        ((0x00000010&(data))>>4)
//--#define HDMI_VPLLCR1_get_dpll_stop(data)                              ((0x00000008&(data))>>3)
//--#define HDMI_VPLLCR1_get_dpll_freeze(data)                            ((0x00000004&(data))>>2)
//--#define HDMI_VPLLCR1_get_dpll_vcorstb(data)                           ((0x00000002&(data))>>1)
//--#define HDMI_VPLLCR1_get_dpll_pwdn(data)                              (0x00000001&(data))
//--
//--
//--#define HDMI_VPLLCR2                                                  0x1800d408
//--#define HDMI_VPLLCR2_reg_addr                                         "0xb800d408"
//--#define HDMI_VPLLCR2_reg                                              0xb800d408
//--#define HDMI_VPLLCR2_inst_addr                                        "0x0102"
//--#define HDMI_VPLLCR2_inst                                             0x0102
//--#define set_HDMI_VPLLCR2_reg(data)                                    (*((volatile unsigned int*)HDMI_VPLLCR2_reg)=data)
//--#define get_HDMI_VPLLCR2_reg                                          (*((volatile unsigned int*)HDMI_VPLLCR2_reg))
//--#define HDMI_VPLLCR2_dpll_rloadm_shift                                (0)
//--#define HDMI_VPLLCR2_dpll_rloadm_mask                                 (0x00000001)
//--#define HDMI_VPLLCR2_dpll_rloadm(data)                                (0x00000001&(data))
//--#define HDMI_VPLLCR2_get_dpll_rloadm(data)                            (0x00000001&(data))
//--
//--
//--#define MN_SCLKG_CTRL                                                 0x1800d410
//--#define MN_SCLKG_CTRL_reg_addr                                        "0xb800d410"
//--#define MN_SCLKG_CTRL_reg                                             0xb800d410
//--#define MN_SCLKG_CTRL_inst_addr                                       "0x0104"
//--#define MN_SCLKG_CTRL_inst                                            0x0104
//--#define set_MN_SCLKG_CTRL_reg(data)                                   (*((volatile unsigned int*)MN_SCLKG_CTRL_reg)=data)
//--#define get_MN_SCLKG_CTRL_reg                                         (*((volatile unsigned int*)MN_SCLKG_CTRL_reg))
//--#define MN_SCLKG_CTRL_sclkg_pll_in_sel_shift                          (7)
//--#define MN_SCLKG_CTRL_sclkg_oclk_sel_shift                            (5)
//--#define MN_SCLKG_CTRL_sclkg_dbuf_shift                                (4)
//--#define MN_SCLKG_CTRL_dummy1800d410_3_0_shift                         (0)
//--#define MN_SCLKG_CTRL_sclkg_pll_in_sel_mask                           (0x00000080)
//--#define MN_SCLKG_CTRL_sclkg_oclk_sel_mask                             (0x00000060)
//--#define MN_SCLKG_CTRL_sclkg_dbuf_mask                                 (0x00000010)
//--#define MN_SCLKG_CTRL_dummy1800d410_3_0_mask                          (0x0000000F)
//--#define MN_SCLKG_CTRL_sclkg_pll_in_sel(data)                          (0x00000080&((data)<<7))
//--#define MN_SCLKG_CTRL_sclkg_oclk_sel(data)                            (0x00000060&((data)<<5))
//--#define MN_SCLKG_CTRL_sclkg_dbuf(data)                                (0x00000010&((data)<<4))
//--#define MN_SCLKG_CTRL_dummy1800d410_3_0(data)                         (0x0000000F&(data))
//--#define MN_SCLKG_CTRL_get_sclkg_pll_in_sel(data)                      ((0x00000080&(data))>>7)
//--#define MN_SCLKG_CTRL_get_sclkg_oclk_sel(data)                        ((0x00000060&(data))>>5)
//--#define MN_SCLKG_CTRL_get_sclkg_dbuf(data)                            ((0x00000010&(data))>>4)
//--#define MN_SCLKG_CTRL_get_dummy1800d410_3_0(data)                     (0x0000000F&(data))
//--
//--
//--#define MN_SCLKG_DIVS                                                 0x1800d414
//--#define MN_SCLKG_DIVS_reg_addr                                        "0xb800d414"
//--#define MN_SCLKG_DIVS_reg                                             0xb800d414
//--#define MN_SCLKG_DIVS_inst_addr                                       "0x0105"
//--#define MN_SCLKG_DIVS_inst                                            0x0105
//--#define set_MN_SCLKG_DIVS_reg(data)                                   (*((volatile unsigned int*)MN_SCLKG_DIVS_reg)=data)
//--#define get_MN_SCLKG_DIVS_reg                                         (*((volatile unsigned int*)MN_SCLKG_DIVS_reg))
//--#define MN_SCLKG_DIVS_sclkg_pll_div2_en_shift                         (7)
//--#define MN_SCLKG_DIVS_sclkg_pll_divs_shift                            (0)
//--#define MN_SCLKG_DIVS_sclkg_pll_div2_en_mask                          (0x00000080)
//--#define MN_SCLKG_DIVS_sclkg_pll_divs_mask                             (0x0000007F)
//--#define MN_SCLKG_DIVS_sclkg_pll_div2_en(data)                         (0x00000080&((data)<<7))
//--#define MN_SCLKG_DIVS_sclkg_pll_divs(data)                            (0x0000007F&(data))
//--#define MN_SCLKG_DIVS_get_sclkg_pll_div2_en(data)                     ((0x00000080&(data))>>7)
//--#define MN_SCLKG_DIVS_get_sclkg_pll_divs(data)                        (0x0000007F&(data))
//--#endif
//--
//--
