// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:802                    Version flow no.:1.1.71
#ifndef _CRT_REG_H_INCLUDED_
#define _CRT_REG_H_INCLUDED_

//#define  _CRT_USE_STRUCT
#ifdef _CRT_USE_STRUCT

typedef struct
{
    unsigned int    rstn_diseqc:1;
    unsigned int    rstn_cablerx:1;
    unsigned int    rstn_hdmi_common:1;
    unsigned int    rstn_hdmi_pre3:1;
    unsigned int    rstn_hdmi_pre2:1;
    unsigned int    rstn_hdmi_pre1:1;
    unsigned int    rstn_hdmi_pre0:1;
    unsigned int    rstn_img_demod:1;
    unsigned int    rstn_img_demod_wrap:1;
    unsigned int    rstn_hdic_apb:1;
    unsigned int    rstn_hdic_axi:1;
    unsigned int    rstn_hdic:1;
    unsigned int    rstn_dtv_frontend:1;
    unsigned int    rstn_kcpu:1;
    unsigned int    rstn_vde2:1;
    unsigned int    rstn_ve2_p2:1;
    unsigned int    rstn_ve2:1;
    unsigned int    rstn_vcpu2:1;
    unsigned int    dummy18000100_13:1;
    unsigned int    rstn_acpu:1;
    unsigned int    rstn_acpu2:1;
    unsigned int    rstn_ae2:1;
    unsigned int    rstn_ve_lgcy_p2:1;
    unsigned int    rstn_ve_lgcy:1;
    unsigned int    rstn_scpu_wrap:1;
    unsigned int    rstn_vde:1;
    unsigned int    rstn_ve_p2:1;
    unsigned int    rstn_ve:1;
    unsigned int    rstn_vcpu:1;
    unsigned int    rstn_ae:1;
    unsigned int    rstn_scpu:1;
    unsigned int    write_data:1;
}SYS_srst0;

typedef struct
{
    unsigned int    rstn_tvsb1:1;
    unsigned int    rstn_tvsb2:1;
    unsigned int    rstn_tvsb3:1;
    unsigned int    rstn_tvsb4:1;
    unsigned int    rstn_tvsb5:1;
    unsigned int    rstn_tve:1;
    unsigned int    rstn_dcphy:1;
    unsigned int    rstn_dcu:1;
    unsigned int    rstn_if_demod:1;
    unsigned int    rstn_vdec:1;
    unsigned int    rstn_vdec2:1;
    unsigned int    rstn_vbis0:1;
    unsigned int    rstn_audio2_dac:1;
    unsigned int    rstn_audio_adc:1;
    unsigned int    rstn_audio_dac:1;
    unsigned int    rstn_audio:1;
    unsigned int    rstn_ifadc:1;
    unsigned int    rstn_cbus:1;
    unsigned int    rstn_offms:1;
    unsigned int    rstn_me:1;
    unsigned int    rstn_apll_adc:1;
    unsigned int    rstn_hdmi:1;
    unsigned int    rstn_dispd:1;
    unsigned int    rstn_tp:1;
    unsigned int    rstn_cp:1;
    unsigned int    rstn_md:1;
    unsigned int    rstn_se:1;
    unsigned int    dummy18000104_4:1;
    unsigned int    rstn_3d_gde:1;
    unsigned int    rstn_vodma:1;
    unsigned int    rstn_dispi:1;
    unsigned int    write_data:1;
}SYS_srst1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    rstn_usb2_ex:1;
    unsigned int    rstn_tm:1;
    unsigned int    rstn_atvin2:1;
    unsigned int    rstn_atvin:1;
    unsigned int    rstn_dispm_cap:1;
    unsigned int    rstn_dispm_disp:1;
    unsigned int    rstn_emmc:1;
    unsigned int    rstn_if_demod_logic:1;
    unsigned int    rstn_bistreg:1;
    unsigned int    rstn_i2c4:1;
    unsigned int    rstn_pllreg:1;
    unsigned int    rstn_usb3:1;
    unsigned int    rstn_usb2:1;
    unsigned int    rstn_pcmcia:1;
    unsigned int    dummy18000108_15:1;
    unsigned int    rstn_i2c3:1;
    unsigned int    rstn_irtx:1;
    unsigned int    dummy18000108_12:1;
    unsigned int    rstn_dtv_demod:1;
    unsigned int    rstn_misc:1;
    unsigned int    rstn_pwm:1;
    unsigned int    rstn_uart1:1;
    unsigned int    rstn_uart2:1;
    unsigned int    dummy18000108_6:1;
    unsigned int    rstn_gpio:1;
    unsigned int    rstn_i2c1:1;
    unsigned int    rstn_i2c2:1;
    unsigned int    rstn_nf:1;
    unsigned int    rstn_sc:1;
    unsigned int    write_data:1;
}SYS_srst2;

typedef struct
{
    unsigned int    rstn_memc:1;
    unsigned int    rstn_memc_me:1;
    unsigned int    rstn_memc_rbus:1;
    unsigned int    reserved_0:3;
    unsigned int    rstn_dcphy2:1;
    unsigned int    rstn_dcu2:1;
    unsigned int    rstn_dcphy_mc:1;
    unsigned int    rstn_disp_lg_hcic:1;
    unsigned int    rstn_disp_lg_mplus:1;
    unsigned int    rstn_d_boe_rgbw_pxl:1;
    unsigned int    rstn_d_boe_rgbw_apb:1;
    unsigned int    rstn_d_boe_rgbw_mcu:1;
    unsigned int    rstn_ddc:1;
    unsigned int    rstn_sd:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:2;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:4;
    unsigned int    rstn_usb2_phy_p3:1;
    unsigned int    rstn_usb2_phy_p2:1;
    unsigned int    rstn_usb2_phy_p1:1;
    unsigned int    rstn_usb2_phy_p0:1;
    unsigned int    reserved_5:1;
    unsigned int    rstn_usb3_phy_p0:1;
    unsigned int    rstn_usb3_mdio_p0:1;
    unsigned int    write_data:1;
}SYS_srst3;

typedef struct
{
    unsigned int    clken_diseqc:1;
    unsigned int    clken_cablerx:1;
    unsigned int    clken_hdmi_common:1;
    unsigned int    clken_hdmi_pre3:1;
    unsigned int    clken_hdmi_pre2:1;
    unsigned int    clken_hdmi_pre1:1;
    unsigned int    clken_hdmi_pre0:1;
    unsigned int    clken_img_demod:1;
    unsigned int    clken_img_demod_wrap:1;
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    clken_hdic:1;
    unsigned int    clken_dtv_frontend:1;
    unsigned int    clken_kcpu:1;
    unsigned int    reserved_2:1;
    unsigned int    clken_ve2_p2:1;
    unsigned int    clken_ve2:1;
    unsigned int    clken_vcpu2:1;
    unsigned int    dummy18000110_13:1;
    unsigned int    clken_acpu:1;
    unsigned int    clken_acpu2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:2;
    unsigned int    clken_ve_lgcy_p2:1;
    unsigned int    clken_ve_lgcy:1;
    unsigned int    clken_ve_p2:1;
    unsigned int    clken_ve:1;
    unsigned int    clken_vcpu:1;
    unsigned int    clken_scpu_wrap:1;
    unsigned int    clken_scpu:1;
    unsigned int    write_data:1;
}SYS_clken0;

typedef struct
{
    unsigned int    clken_tvsb1:1;
    unsigned int    clken_tvsb2:1;
    unsigned int    clken_tvsb3:1;
    unsigned int    clken_tvsb4:1;
    unsigned int    clken_tvsb5:1;
    unsigned int    clken_tve:1;
    unsigned int    clken_dcphy:1;
    unsigned int    clken_dcu:1;
    unsigned int    clken_if_demod:1;
    unsigned int    clken_vdec:1;
    unsigned int    clken_se2:1;
    unsigned int    clken_vbis0:1;
    unsigned int    clken_dolby_comp:1;
    unsigned int    clken_dolby_dm:1;
    unsigned int    clken_audio_pre512fs:1;
    unsigned int    clken_audio:1;
    unsigned int    clken_ifadc:1;
    unsigned int    clken_cbus:1;
    unsigned int    clken_offms:1;
    unsigned int    clken_me:1;
    unsigned int    clken_apll_adc:1;
    unsigned int    clken_hdmi:1;
    unsigned int    clken_dispd:1;
    unsigned int    clken_tp:1;
    unsigned int    clken_cp:1;
    unsigned int    clken_md:1;
    unsigned int    clken_se:1;
    unsigned int    clken_tp_div:1;
    unsigned int    clken_3d_gde:1;
    unsigned int    clken_vodma:1;
    unsigned int    clken_dispi:1;
    unsigned int    write_data:1;
}SYS_clken1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    clken_usb2_ex:1;
    unsigned int    clken_tm:1;
    unsigned int    clken_atvin_vd:1;
    unsigned int    clken_atvin_ifd:1;
    unsigned int    clken_dispm_cap:1;
    unsigned int    clken_dispm_disp:1;
    unsigned int    clken_emmc:1;
    unsigned int    clken_efuse:1;
    unsigned int    clken_bistreg:1;
    unsigned int    clken_i2c4:1;
    unsigned int    clken_pllreg:1;
    unsigned int    clken_usb3:1;
    unsigned int    clken_usb2:1;
    unsigned int    clken_pcmcia:1;
    unsigned int    clken_audio2_512fs:1;
    unsigned int    clken_i2c3:1;
    unsigned int    clken_irtx:1;
    unsigned int    dummy18000118_12:1;
    unsigned int    clken_dtv_demod:1;
    unsigned int    clken_misc:1;
    unsigned int    clken_pwm:1;
    unsigned int    clken_uart1:1;
    unsigned int    clken_uart2:1;
    unsigned int    dummy18000118_6:1;
    unsigned int    clken_gpio:1;
    unsigned int    clken_i2c1:1;
    unsigned int    clken_i2c2:1;
    unsigned int    clken_nf:1;
    unsigned int    clken_sc:1;
    unsigned int    write_data:1;
}SYS_clken2;

typedef struct
{
    unsigned int    clken_memc:1;
    unsigned int    clken_memc_me:1;
    unsigned int    clken_memc_rbus:1;
    unsigned int    reserved_0:2;
    unsigned int    clken_dcphy_mc_mck:1;
    unsigned int    clken_dcphy2:1;
    unsigned int    clken_dcu2:1;
    unsigned int    clken_dcphy_mc:1;
    unsigned int    clken_disp_lg_hcic:1;
    unsigned int    clken_disp_lg_mplus:1;
    unsigned int    clken_d_boe_rgbw_pxl:1;
    unsigned int    clken_d_boe_rgbw_apb:1;
    unsigned int    clken_d_boe_rgbw_mcu:1;
    unsigned int    clken_ddc:1;
    unsigned int    clken_sd:1;
    unsigned int    clken_dss:1;
    unsigned int    reserved_1:5;
    unsigned int    clken_audio_ad_128fs:1;
    unsigned int    clken_audio_arc_dma_r_512fs:1;
    unsigned int    clken_audio2_dma_r_512fs:1;
    unsigned int    clken_audio_dma_r_512fs:1;
    unsigned int    clken_audio_da1_256fs:1;
    unsigned int    clken_audio_da1_128fs:1;
    unsigned int    clken_audio_da0_256fs:1;
    unsigned int    clken_audio_da0_128fs:1;
    unsigned int    clken_audio_ad_256fs:1;
    unsigned int    write_data:1;
}SYS_clken3;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    ejtag_demod_sel:1;
    unsigned int    ejtag_demod_en:1;
    unsigned int    ejtag_mode:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:2;
    unsigned int    kcpu_clksel:1;
}SYS_cpusel;

typedef struct
{
    unsigned int    pll_bypass_ref_clk_mode:1;
    unsigned int    mc_clk_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    ve_sel:1;
    unsigned int    sd_emmc_clk_sel:1;
    unsigned int    pcr108_clksel:1;
    unsigned int    dummy18000204_25:1;
    unsigned int    dpll_clksel:2;
    unsigned int    sd_clk_div:3;
    unsigned int    ve_rif_use_p2clk:1;
    unsigned int    ve2_rif_use_p2clk:1;
    unsigned int    atvin_clk_sel:1;
    unsigned int    atvin_vd_clk_sel:1;
    unsigned int    atvin_vdadc_tve_clk_sel:1;
    unsigned int    reserved_1:1;
    unsigned int    tve_108m_clk_sel:1;
    unsigned int    cbus_clksel:1;
    unsigned int    tp_post_div:4;
    unsigned int    tp_pre_div:4;
    unsigned int    vdec_x27_clksel:1;
    unsigned int    vbis0_yppsel:1;
    unsigned int    inv_vbis0_sel:1;
    unsigned int    uart_clksel:1;
}SYS_clksel;

typedef struct
{
    unsigned int    dispd_osd_div:2;
    unsigned int    reserved_0:2;
    unsigned int    memc_me_div:2;
    unsigned int    dclk_fract_b:6;
    unsigned int    dclk_fract_a:5;
    unsigned int    dispd_gdma_clk_sel:1;
    unsigned int    reserved_1:1;
    unsigned int    dispd_memc_out_sel:1;
    unsigned int    dummy18000208_11:1;
    unsigned int    dummy18000208_10:1;
    unsigned int    clken_disp_lg_avcom:1;
    unsigned int    dummy18000208_8:1;
    unsigned int    dummy18000208_7:1;
    unsigned int    clken_disp_memc_in:1;
    unsigned int    clken_disp_memc_out:1;
    unsigned int    clken_disp_sfg:1;
    unsigned int    clken_disp_gdma:1;
    unsigned int    clken_disp_stage1:1;
    unsigned int    clken_disp_osd:1;
    unsigned int    dummy18000208_0:1;
}SYS_dispclksel;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    clken_ext_15_en:1;
    unsigned int    clken_ext_14_en:1;
    unsigned int    clken_ext_13_en:1;
    unsigned int    clken_ext_12_en:1;
    unsigned int    clken_ext_11_en:1;
    unsigned int    clken_ext_10_en:1;
    unsigned int    clken_ext_9_en:1;
    unsigned int    clken_ext_8_en:1;
    unsigned int    clken_ext_7_en:1;
    unsigned int    clken_ext_6_en:1;
    unsigned int    clken_ext_5_en:1;
    unsigned int    clken_ext_4_en:1;
    unsigned int    clken_ext_3_en:1;
    unsigned int    clken_ext_2_en:1;
    unsigned int    clken_ext_1_en:1;
    unsigned int    clken_ext_0_en:1;
}SYS_extclk_en;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    dtv_demod_sel:1;
    unsigned int    i2c2_clksel:1;
    unsigned int    i2c1_clksel:1;
    unsigned int    reserved_1:1;
    unsigned int    nf_clksel:3;
    unsigned int    dummy18000214_7:1;
    unsigned int    aud_dtv2_freq_sel:3;
    unsigned int    dummy18000214_3:1;
    unsigned int    aud_dtv_freq_sel:3;
}SYS_clkdiv;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:4;
    unsigned int    reserved_3:12;
}SYS_arm_wd;

typedef struct
{
    unsigned int    dummy1800021c_31_29:3;
    unsigned int    ib_rst_gck_memc:1;
    unsigned int    ib_rst_gck_gpu:1;
    unsigned int    ib_rst_gck_se2:1;
    unsigned int    ib_rst_gck_ve2:1;
    unsigned int    ib_rst_gck_ve:1;
    unsigned int    ib_rst_gck_tvsb5:1;
    unsigned int    ib_rst_gck_tvsb4:1;
    unsigned int    ib_rst_gck_tvsb3:1;
    unsigned int    ib_rst_gck_tvsb2:1;
    unsigned int    ib_rst_gck_tvsb1:1;
    unsigned int    ib_rst_gck_sb3:1;
    unsigned int    ib_rst_gck_sb2:1;
    unsigned int    ib_rst_gck_sb1:1;
    unsigned int    dummy1800021c_15_13:3;
    unsigned int    ib_clk_gck_memc:1;
    unsigned int    ib_clk_gck_gpu:1;
    unsigned int    ib_clk_gck_se2:1;
    unsigned int    ib_clk_gck_ve2:1;
    unsigned int    ib_clk_gck_ve:1;
    unsigned int    ib_clk_gck_tvsb5:1;
    unsigned int    ib_clk_gck_tvsb4:1;
    unsigned int    ib_clk_gck_tvsb3:1;
    unsigned int    ib_clk_gck_tvsb2:1;
    unsigned int    ib_clk_gck_tvsb1:1;
    unsigned int    ib_clk_gck_sb3:1;
    unsigned int    ib_clk_gck_sb2:1;
    unsigned int    ib_clk_gck_sb1:1;
}SYS_ib;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    clkratio_vcpu:5;
    unsigned int    reserved_1:2;
    unsigned int    clkratio_vcpu_active:1;
    unsigned int    clkratio_acpu:5;
    unsigned int    reserved_2:2;
    unsigned int    clkratio_acpu_active:1;
    unsigned int    clkratio_acpu2:5;
    unsigned int    reserved_3:2;
    unsigned int    clkratio_acpu2_active:1;
}SYS_dyn_sw_cpu;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    efuse_ready:1;
}EFUSE_ctrl0;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:1;
    unsigned int    reserved_9:1;
    unsigned int    reserved_10:1;
    unsigned int    reserved_11:1;
    unsigned int    reserved_12:3;
    unsigned int    atv_iso_en:1;
    unsigned int    reserved_13:1;
    unsigned int    atv_str_status:1;
    unsigned int    reserved_14:1;
    unsigned int    atv_str_pow:1;
    unsigned int    reserved_15:3;
    unsigned int    dtv_iso_en:1;
    unsigned int    reserved_16:1;
    unsigned int    dtv_str_status:1;
    unsigned int    reserved_17:1;
    unsigned int    dtv_str_pow:1;
}POWER_ctrl0;

typedef struct
{
    unsigned int    smartcard_int_scpu_routing_en:1;
    unsigned int    dummy18000290_30:1;
    unsigned int    ddc_int_scpu_routing_en:1;
    unsigned int    standby_syncp_int_scpu_routing_en:1;
    unsigned int    standby_hdmi_clk_det_int_scpu_routing_en:1;
    unsigned int    standby_wdog_int_scpu_routing_en:1;
    unsigned int    standby_iso_misc_off_int_scpu_routing_en:1;
    unsigned int    standby_cbus_int_scpu_routing_en:1;
    unsigned int    standby_iso_misc_int_scpu_routing_en:1;
    unsigned int    standby_cec_int_scpu_routing_en:1;
    unsigned int    standby_rtc_int_scpu_routing_en:1;
    unsigned int    gpu_int_scpu_routing_en:1;
    unsigned int    usb3_int_scpu_routing_en:1;
    unsigned int    usb2_int_scpu_routing_en:1;
    unsigned int    etn_int_scpu_routing_en:1;
    unsigned int    sd_int_scpu_routing_en:1;
    unsigned int    audio_dma_irq_scpu_routing_en:1;
    unsigned int    audio_irq_scpu_routing_en:1;
    unsigned int    tv_sb_dc_int_scpu_routing_en:1;
    unsigned int    dcphy_int_scpu_routing_en:1;
    unsigned int    dc_int_scpu_routing_en:1;
    unsigned int    tve_int_scpu_routing_en:1;
    unsigned int    osd_int_scpu_routing_en:1;
    unsigned int    ultra_zoom_int_scpu_routing_en:1;
    unsigned int    dctl_int_scpu_routing_en:1;
    unsigned int    vbi_int_scpu_routing_en:1;
    unsigned int    vdec_int_scpu_routing_en:1;
    unsigned int    if_demod_int_scpu_routing_en:1;
    unsigned int    dispm_int_scpu_routing_en:1;
    unsigned int    dispi_int_scpu_routing_en:1;
    unsigned int    apll_dds_int_scpu_routing_en:1;
    unsigned int    write_data:1;
}INT_ctrl_scpu;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    disp2tve_int_vcpu_routing_en:1;
    unsigned int    vodma_int_vcpu_routing_en:1;
    unsigned int    dummy18000294_28:1;
    unsigned int    dc_int_vcpu2_routing_en:1;
    unsigned int    dummy18000294_26:1;
    unsigned int    dummy18000294_25:1;
    unsigned int    dummy18000294_24:1;
    unsigned int    dummy18000294_23:1;
    unsigned int    dummy18000294_22:1;
    unsigned int    dummy18000294_21:1;
    unsigned int    dummy18000294_20:1;
    unsigned int    dummy18000294_19:1;
    unsigned int    dummy18000294_18:1;
    unsigned int    dummy18000294_17:1;
    unsigned int    dummy18000294_16:1;
    unsigned int    me_int_vcpu_routing_en:1;
    unsigned int    ddc_int_vcpu_routing_en:1;
    unsigned int    tv_sb_dc_int_vcpu_routing_en:1;
    unsigned int    dcphy_int_vcpu_routing_en:1;
    unsigned int    dc_int_vcpu_routing_en:1;
    unsigned int    tve_int_vcpu_routing_en:1;
    unsigned int    osd_int_vcpu_routing_en:1;
    unsigned int    ultra_zoom_int_vcpu_routing_en:1;
    unsigned int    dctl_int_vcpu_routing_en:1;
    unsigned int    vbi_int_vcpu_routing_en:1;
    unsigned int    vdec_int_vcpu_routing_en:1;
    unsigned int    if_demod_int_vcpu_routing_en:1;
    unsigned int    dispm_int_vcpu_routing_en:1;
    unsigned int    dispi_int_vcpu_routing_en:1;
    unsigned int    apll_dds_int_vcpu_routing_en:1;
    unsigned int    write_data:1;
}INT_ctrl_vcpu;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:1;
    unsigned int    reserved_9:1;
    unsigned int    reserved_10:1;
    unsigned int    reserved_11:1;
    unsigned int    reserved_12:1;
    unsigned int    reserved_13:1;
    unsigned int    reserved_14:1;
    unsigned int    me_int_acpu_routing_en:1;
    unsigned int    audio_dma_irq_acpu_routing_en:1;
    unsigned int    audio_irq_acpu_routing_en:1;
    unsigned int    tv_sb_dc_int_acpu_routing_en:1;
    unsigned int    dcphy_int_acpu_routing_en:1;
    unsigned int    dc_int_acpu_routing_en:1;
    unsigned int    dummy18000298_10:1;
    unsigned int    dummy18000298_9:1;
    unsigned int    dummy18000298_8:1;
    unsigned int    audio_dma_irq_acpu2_routing_en:1;
    unsigned int    audio_irq_acpu2_routing_en:1;
    unsigned int    dummy18000298_5:1;
    unsigned int    dummy18000298_4:1;
    unsigned int    dc_int_acpu2_routing_en:1;
    unsigned int    dummy18000298_2:1;
    unsigned int    dummy18000298_1:1;
    unsigned int    write_data:1;
}INT_ctrl_acpu;

typedef struct
{
    unsigned int    smartcard_int_kcpu_routing_en:1;
    unsigned int    disp2tve_int_kcpu_routing_en:1;
    unsigned int    vodma_int_kcpu_routing_en:1;
    unsigned int    standby_syncp_int_kcpu_routing_en:1;
    unsigned int    standby_hdmi_clk_det_int_kcpu_routing_en:1;
    unsigned int    standby_wdog_int_kcpu_routing_en:1;
    unsigned int    standby_iso_misc_off_int_kcpu_routing_en:1;
    unsigned int    standby_cbus_int_kcpu_routing_en:1;
    unsigned int    standby_iso_misc_int_kcpu_routing_en:1;
    unsigned int    standby_cec_int_kcpu_routing_en:1;
    unsigned int    standby_rtc_int_kcpu_routing_en:1;
    unsigned int    gpu_int_kcpu_routing_en:1;
    unsigned int    usb3_int_kcpu_routing_en:1;
    unsigned int    usb2_int_kcpu_routing_en:1;
    unsigned int    etn_int_kcpu_routing_en:1;
    unsigned int    sd_int_kcpu_routing_en:1;
    unsigned int    dummy1800029c_15:1;
    unsigned int    ddc_int_kcpu_routing_en:1;
    unsigned int    tv_sb_dc_int_kcpu_routing_en:1;
    unsigned int    dcphy_int_kcpu_routing_en:1;
    unsigned int    dc_int_kcpu_routing_en:1;
    unsigned int    tve_int_kcpu_routing_en:1;
    unsigned int    osd_int_kcpu_routing_en:1;
    unsigned int    ultra_zoom_int_kcpu_routing_en:1;
    unsigned int    dctl_int_kcpu_routing_en:1;
    unsigned int    vbi_int_kcpu_routing_en:1;
    unsigned int    vdec_int_kcpu_routing_en:1;
    unsigned int    if_demod_int_kcpu_routing_en:1;
    unsigned int    dispm_int_kcpu_routing_en:1;
    unsigned int    dispi_int_kcpu_routing_en:1;
    unsigned int    apll_dds_int_kcpu_routing_en:1;
    unsigned int    write_data:1;
}INT_ctrl_kcpu;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    memc_int_vcpu_routing_en:1;
    unsigned int    dummy180002a0_27:1;
    unsigned int    dummy180002a0_26:1;
    unsigned int    dummy180002a0_25:1;
    unsigned int    memc_int_vcpu2_routing_en:1;
    unsigned int    dummy180002a0_23:1;
    unsigned int    dummy180002a0_22:1;
    unsigned int    dummy180002a0_21:1;
    unsigned int    memc_int_scpu_routing_en:1;
    unsigned int    reserved_3:2;
    unsigned int    hdmi_irq_vcpu_routing_en:1;
    unsigned int    hdmi_irq_scpu_routing_en:1;
    unsigned int    reserved_4:15;
    unsigned int    write_data:1;
}INT_ctrl_memc;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    dc_security_int_scpu_routing_en:1;
    unsigned int    reserved_1:3;
    unsigned int    tm_security_int_scpu_routing_en:1;
    unsigned int    tp_security_int_scpu_routing_en:1;
    unsigned int    nf_security_int_scpu_routing_en:1;
    unsigned int    emmc_security_int_scpu_routing_en:1;
    unsigned int    md_security_int_scpu_routing_en:1;
    unsigned int    mcp_security_int_scpu_routing_en:1;
    unsigned int    sb2_security_int_scpu_routing_en:1;
    unsigned int    mis_security_int_scpu_routing_en:1;
    unsigned int    se_security_int_scpu_routing_en:1;
    unsigned int    dc2_security_int_scpu_routing_en:1;
    unsigned int    write_data:1;
}INT_ctrl_scpu_2;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    dc_security_int_kcpu_routing_en:1;
    unsigned int    reserved_1:3;
    unsigned int    tm_security_int_kcpu_routing_en:1;
    unsigned int    tp_security_int_kcpu_routing_en:1;
    unsigned int    nf_security_int_kcpu_routing_en:1;
    unsigned int    emmc_security_int_kcpu_routing_en:1;
    unsigned int    md_security_int_kcpu_routing_en:1;
    unsigned int    mcp_security_int_kcpu_routing_en:1;
    unsigned int    sb2_security_int_kcpu_routing_en:1;
    unsigned int    mis_security_int_kcpu_routing_en:1;
    unsigned int    se_security_int_kcpu_routing_en:1;
    unsigned int    dc2_security_int_kcpu_routing_en:1;
    unsigned int    write_data:1;
}INT_ctrl_kcpu_2;

typedef struct
{
    unsigned int    dss_main_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    dss_main_ro_sel:3;
    unsigned int    dss_main_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    dss_main_ready:1;
    unsigned int    dss_main_count_out:20;
}SS_main_rhvt_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dss_main_speed_en:1;
    unsigned int    dss_main_wsort_go:1;
    unsigned int    dss_main_data_in:20;
}SS_main_rhvt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dss_main_dbgo:16;
}SS_main_rhvt_2;

typedef struct
{
    unsigned int    dss_vcpu_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    dss_vcpu_ro_sel:3;
    unsigned int    dss_vcpu_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    dss_vcpu_ready:1;
    unsigned int    dss_vcpu_count_out:20;
}SS_vcpu_rhvt_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dss_vcpu_speed_en:1;
    unsigned int    dss_vcpu_wsort_go:1;
    unsigned int    dss_vcpu_data_in:20;
}SS_vcpu_rhvt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dss_vcpu_dbgo:16;
}SS_vcpu_rhvt_2;

typedef struct
{
    unsigned int    dss_acpu_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    dss_acpu_ro_sel:3;
    unsigned int    dss_acpu_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    dss_acpu_ready:1;
    unsigned int    dss_acpu_count_out:20;
}SS_acpu_rhvt_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dss_acpu_speed_en:1;
    unsigned int    dss_acpu_wsort_go:1;
    unsigned int    dss_acpu_data_in:20;
}SS_acpu_rhvt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dss_acpu_dbgo:16;
}SS_acpu_rhvt_2;

typedef struct
{
    unsigned int    dss_tvsb2_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    dss_tvsb2_ro_sel:3;
    unsigned int    dss_tvsb2_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    dss_tvsb2_ready:1;
    unsigned int    dss_tvsb2_count_out:20;
}SS_tvsb2_rhvt_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dss_tvsb2_speed_en:1;
    unsigned int    dss_tvsb2_wsort_go:1;
    unsigned int    dss_tvsb2_data_in:20;
}SS_tvsb2_rhvt_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dss_tvsb2_dbgo:16;
}SS_tvsb2_rhvt_2;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    vcpu_voltage_strobe_en:1;
    unsigned int    reserved_1:3;
    unsigned int    main_voltage_strobe_en:1;
    unsigned int    reserved_2:3;
    unsigned int    tvsb2_voltage_strobe_en:1;
}VOLTAGE_strobe_ctrl;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pll_dbg_en:1;
    unsigned int    reserved_1:10;
    unsigned int    dbg0_div_sel:2;
    unsigned int    reserved_2:4;
    unsigned int    top_ssc_dbg_sel:4;
    unsigned int    crt_dbg_sel:8;
}SC_debug_0;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    tm_a:29;
}TEMP_sensor_1;

typedef struct
{
    unsigned int    tm_b:22;
    unsigned int    tm_adccksel:3;
    unsigned int    tm_cal_en:1;
    unsigned int    tm_biaschop:1;
    unsigned int    tm_chopen:1;
    unsigned int    tm_cksourcesel:1;
    unsigned int    tm_dsr:3;
}TEMP_sensor_2;

typedef struct
{
    unsigned int    dummy18000388_31:1;
    unsigned int    tm_filteredgesel:1;
    unsigned int    tm_hold_en:1;
    unsigned int    tm_order3:1;
    unsigned int    tm_offset:22;
    unsigned int    tm_pow:1;
    unsigned int    reserved_0:5;
}TEMP_sensor_3;

typedef struct
{
    unsigned int    tm_r:24;
    unsigned int    tm_opcursel:2;
    unsigned int    tm_hold_dly:2;
    unsigned int    tm_osccursel:2;
    unsigned int    tm_resol:2;
}TEMP_sensor_4;

typedef struct
{
    unsigned int    tm_rstb:1;
    unsigned int    tm_sdm_test:1;
    unsigned int    tm_sdm_test_en:1;
    unsigned int    tm_test_en:1;
    unsigned int    tm_vcmsel:3;
    unsigned int    tm_vbe_biassel:2;
    unsigned int    tm_chopfreqsel:11;
    unsigned int    reserved_0:3;
    unsigned int    dummy18000390_8_4:5;
    unsigned int    reserved_1:3;
    unsigned int    dummy18000390_0:1;
}TEMP_sensor_5;

typedef struct
{
    unsigned int    dummy18000394_31_16:16;
    unsigned int    dummy18000394_15_0:16;
}TEMP_sensor_6;

typedef struct
{
    unsigned int    dummy18000398_31_16:16;
    unsigned int    dummy18000398_15:1;
    unsigned int    dummy18000398_14_12:3;
    unsigned int    dummy18000398_11_10:2;
    unsigned int    dummy18000398_9_7:3;
    unsigned int    dummy18000398_6:1;
    unsigned int    dummy18000398_5:1;
    unsigned int    dummy18000398_4:1;
    unsigned int    tm_biasdem_sel:1;
    unsigned int    reserved_0:1;
    unsigned int    td_wrep_edge_sel:1;
    unsigned int    dummy18000398_0:1;
}TEMP_sensor_7;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    tm_s:23;
}TEMP_sensor_8;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    dummy180003a0_30_24:7;
    unsigned int    reserved_1:5;
    unsigned int    ct_out_o_tm:19;
}THERMAL_result_1;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    u_out_tm:22;
}THERMAL_result_2;

typedef struct
{
    unsigned int    thermal_sensor_ie:1;
    unsigned int    thermal_sensor_irq_status:2;
    unsigned int    reserved_0:1;
    unsigned int    thermal_sensor_kcpu_ie:1;
    unsigned int    thermal_sensor_irq_kcpu_status:2;
    unsigned int    reserved_1:6;
    unsigned int    thermal_sensor_thh:19;
}THERMAL_irq_threshold_1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    thermal_sensor_thl:19;
}THERMAL_irq_threshold_2;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllkcpu_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pllkcpu_n:2;
    unsigned int    pllkcpu_m:8;
    unsigned int    pllkcpu_ip:3;
    unsigned int    pllkcpu_o:2;
    unsigned int    pllkcpu_wdset:1;
    unsigned int    pllkcpu_wdrst:1;
    unsigned int    pllkcpu_cs:2;
    unsigned int    pllkcpu_rs:3;
}SYS_pll_kcpu1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    pllkcpu_reserve:6;
    unsigned int    reserved_1:1;
    unsigned int    pllkcpu_oeb:1;
    unsigned int    pllkcpu_rstb:1;
    unsigned int    pllkcpu_pow:1;
}SYS_pll_kcpu2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pllbus_gran_auto_rst:1;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_dot_gran:3;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_gran_est:19;
    unsigned int    reserved_3:3;
    unsigned int    pllbus_en_ssc:1;
}PLL_ssc_bus;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllbus_ncode_ssc:8;
    unsigned int    reserved_1:5;
    unsigned int    pllbus_fcode_ssc:11;
}PLL_ssc_bus_2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pllbus_gran_auto_rst_h:1;
    unsigned int    reserved_1:1;
    unsigned int    pllbus_dot_gran_h:3;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_gran_est_h:19;
    unsigned int    reserved_3:3;
    unsigned int    pllbus_en_ssc_h:1;
}PLL_ssc_bush;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllbus_ncode_ssc_h:8;
    unsigned int    reserved_1:5;
    unsigned int    pllbus_fcode_ssc_h:11;
}PLL_ssc_bush_2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pllddsa_gran_auto_rst:1;
    unsigned int    reserved_1:1;
    unsigned int    pllddsa_dot_gran:3;
    unsigned int    reserved_2:1;
    unsigned int    pllddsa_gran_est:19;
    unsigned int    reserved_3:3;
    unsigned int    pllddsa_en_ssc:1;
}PLL_ssc_ddsa;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllddsa_ncode_ssc:8;
    unsigned int    reserved_1:5;
    unsigned int    pllddsa_fcode_ssc:11;
}PLL_ssc_ddsa_2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:19;
    unsigned int    reserved_6:3;
    unsigned int    reserved_7:1;
}PLL_ssc_ddsb;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    reserved_1:8;
    unsigned int    reserved_2:5;
    unsigned int    reserved_3:11;
}PLL_ssc_ddsb_2;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    psaud2b_ssc_ckinv:1;
    unsigned int    psaud2a_ssc_ckinv:1;
    unsigned int    psaud1b_ssc_ckinv:1;
    unsigned int    psaud1a_ssc_ckinv:1;
    unsigned int    reserved_1:3;
    unsigned int    dds_ssc_ckinv:1;
    unsigned int    gpu_ssc_ckinv:1;
    unsigned int    reserved_2:1;
    unsigned int    bush_ssc_ckinv:1;
    unsigned int    bus_ssc_ckinv:1;
}PLL_ssc_inv;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    pow_ldo1v:1;
    unsigned int    ldo1v_sel:2;
    unsigned int    reserved_1:2;
    unsigned int    pllcpu_reg:2;
}SYS_pll_cpu;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllacpu_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pllacpu_n:2;
    unsigned int    pllacpu_m:8;
    unsigned int    pllacpu_ip:3;
    unsigned int    pllacpu_o:2;
    unsigned int    pllacpu_wdset:1;
    unsigned int    pllacpu_wdrst:1;
    unsigned int    pllacpu_cs:2;
    unsigned int    pllacpu_rs:3;
}SYS_pll_acpu1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    pllacpu_reserve:6;
    unsigned int    reserved_1:1;
    unsigned int    pllacpu_oeb:1;
    unsigned int    pllacpu_rstb:1;
    unsigned int    pllacpu_pow:1;
}SYS_pll_acpu2;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllvcpu_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    pllvcpu_n:2;
    unsigned int    pllvcpu_m:8;
    unsigned int    pllvcpu_ip:3;
    unsigned int    pllvcpu_o:2;
    unsigned int    pllvcpu_wdset:1;
    unsigned int    pllvcpu_wdrst:1;
    unsigned int    pllvcpu_cs:2;
    unsigned int    pllvcpu_rs:3;
}SYS_pll_vcpu_1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    pllvcpu_reserve:6;
    unsigned int    reserved_1:1;
    unsigned int    pllvcpu_oeb:1;
    unsigned int    pllvcpu_rstb:1;
    unsigned int    pllvcpu_pow:1;
}SYS_pll_vcpu_2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reserved_1:2;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:2;
    unsigned int    pllbus_wdset:1;
    unsigned int    pllbus_wdrst:1;
    unsigned int    reserved_5:2;
    unsigned int    pllbus_lpf_cs:2;
    unsigned int    reserved_6:2;
    unsigned int    pllbus_testsel:1;
    unsigned int    pllbus_sel_cco:1;
    unsigned int    pllbus_icp:4;
    unsigned int    pllbus_dbug_en:1;
    unsigned int    pllbus_pdiv_bps:1;
    unsigned int    pllbus_pdiv:2;
    unsigned int    reserved_7:1;
    unsigned int    pllbus_lpf_rs:3;
}SYS_pll_bus1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_fcode:11;
    unsigned int    pllbus_ncode:8;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_oeb:1;
    unsigned int    pllbus_rstb:1;
    unsigned int    pllbus_pow:1;
}SYS_pll_bus2;

typedef struct
{
    unsigned int    pllbus_bypass_pi:1;
    unsigned int    pllbus_en_pi_debug:1;
    unsigned int    pllbus_hs_oc_stop:2;
    unsigned int    pllbus_pi_cur_sel:2;
    unsigned int    pllbus_sel_oc_mode:2;
    unsigned int    reserved_0:2;
    unsigned int    pllbus_oc_done_delay:6;
    unsigned int    reserved_1:2;
    unsigned int    pllbus_oc_step:10;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_sdm_order:1;
    unsigned int    pllbus_oc_done:1;
    unsigned int    pllbus_oc_en:1;
}SYS_dvfs_bus;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_fcode_dbg:11;
    unsigned int    pllbus_ncode_dbg:8;
    unsigned int    reserved_1:8;
}SYS_dvfs_bus2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reserved_1:2;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:2;
    unsigned int    pllbus_wdset_h:1;
    unsigned int    pllbus_wdrst_h:1;
    unsigned int    reserved_5:2;
    unsigned int    pllbus_lpf_cs_h:2;
    unsigned int    reserved_6:2;
    unsigned int    pllbus_testsel_h:1;
    unsigned int    pllbus_sel_cco_h:1;
    unsigned int    pllbus_icp_h:4;
    unsigned int    pllbus_dbug_en_h:1;
    unsigned int    pllbus_pdiv_bps_h:1;
    unsigned int    pllbus_pdiv_h:2;
    unsigned int    reserved_7:1;
    unsigned int    pllbus_lpf_rs_h:3;
}SYS_pll_bush1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_fcode_h:11;
    unsigned int    pllbus_ncode_h:8;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_oeb_h:1;
    unsigned int    pllbus_rstb_h:1;
    unsigned int    pllbus_pow_h:1;
}SYS_pll_bush2;

typedef struct
{
    unsigned int    pllbus_bypass_pi_h:1;
    unsigned int    pllbus_en_pi_debug_h:1;
    unsigned int    pllbus_hs_oc_stop_h:2;
    unsigned int    pllbus_pi_cur_sel_h:2;
    unsigned int    pllbus_sel_oc_mode_h:2;
    unsigned int    reserved_0:2;
    unsigned int    pllbus_oc_done_delay_h:6;
    unsigned int    reserved_1:2;
    unsigned int    pllbus_oc_step_h:10;
    unsigned int    reserved_2:1;
    unsigned int    pllbus_sdm_order_h:1;
    unsigned int    pllbus_oc_done_h:1;
    unsigned int    pllbus_oc_en_h:1;
}SYS_dvfs_bush;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllbus_fcode_dbg_h:11;
    unsigned int    pllbus_ncode_dbg_h:8;
    unsigned int    reserved_1:8;
}SYS_dvfs_bush2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    reserved_1:2;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:2;
    unsigned int    pllgpu_wdset:1;
    unsigned int    pllgpu_wdrst:1;
    unsigned int    reserved_5:2;
    unsigned int    pllgpu_lpf_cs:2;
    unsigned int    reserved_6:2;
    unsigned int    pllgpu_testsel:1;
    unsigned int    pllgpu_sel_cco:1;
    unsigned int    pllgpu_icp:4;
    unsigned int    pllgpu_dbug_en:1;
    unsigned int    pllgpu_pdiv_bps:1;
    unsigned int    pllgpu_pdiv:2;
    unsigned int    reserved_7:1;
    unsigned int    pllgpu_lpf_rs:3;
}SYS_pll_gpu1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllgpu_fcode:11;
    unsigned int    pllgpu_ncode:8;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:1;
    unsigned int    pllgpu_oeb:1;
    unsigned int    pllgpu_rstb:1;
    unsigned int    pllgpu_pow:1;
}SYS_pll_gpu2;

typedef struct
{
    unsigned int    pllgpu_bypass_pi:1;
    unsigned int    pllgpu_en_pi_debug:1;
    unsigned int    pllgpu_hs_oc_stop:2;
    unsigned int    pllgpu_pi_cur_sel:2;
    unsigned int    pllgpu_sel_oc_mode:2;
    unsigned int    reserved_0:2;
    unsigned int    pllgpu_oc_done_delay:6;
    unsigned int    reserved_1:2;
    unsigned int    pllgpu_oc_step:10;
    unsigned int    reserved_2:1;
    unsigned int    pllgpu_sdm_order:1;
    unsigned int    pllgpu_oc_done:1;
    unsigned int    pllgpu_oc_en:1;
}SYS_dvfs_gpu;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllgpu_fcode_dbg:11;
    unsigned int    pllgpu_ncode_dbg:8;
    unsigned int    reserved_1:8;
}SYS_dvfs_gpu2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    pllvodma_n:2;
    unsigned int    pllvodma_m:8;
    unsigned int    pllvodma_ip:3;
    unsigned int    pllvodma_o:2;
    unsigned int    pllvodma_wdset:1;
    unsigned int    pllvodma_wdrst:1;
    unsigned int    pllvodma_cs:2;
    unsigned int    pllvodma_rs:3;
}SYS_pll_vodma1;

typedef struct
{
    unsigned int    reserved_0:22;
    unsigned int    pllvodma_reserve:6;
    unsigned int    pllvodma_tst:1;
    unsigned int    pllvodma_oeb:1;
    unsigned int    pllvodma_rstb:1;
    unsigned int    pllvodma_pow:1;
}SYS_pll_vodma2;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllbus_reser:8;
    unsigned int    reserved_1:2;
    unsigned int    pllbus_reg:2;
    unsigned int    reserved_2:2;
    unsigned int    pllbustst_div:2;
    unsigned int    reserved_3:3;
    unsigned int    pllbustst_sel:5;
}SYS_pllbus_tst;

typedef struct
{
    unsigned int    pllddsa_n:2;
    unsigned int    reserved_0:6;
    unsigned int    pllddsa_ip:4;
    unsigned int    pllddsa_rs:3;
    unsigned int    pllddsa_cs:2;
    unsigned int    pllddsa_cp:2;
    unsigned int    reserved_1:5;
    unsigned int    reserved_2:2;
    unsigned int    pllddsa_o:2;
    unsigned int    reserved_3:2;
    unsigned int    pllddsa_wdmode:2;
}SYS_pll_dispa_sd1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllddsa_fcode:11;
    unsigned int    pllddsa_ncode:8;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:1;
    unsigned int    pllddsa_oeb:1;
    unsigned int    pllddsa_rstb:1;
    unsigned int    pllddsa_pow:1;
}SYS_pll_dispa_sd2;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    dummy18000478_28_25:4;
    unsigned int    dummy18000478_24:1;
    unsigned int    dummy18000478_23:1;
    unsigned int    dummy18000478_22:1;
    unsigned int    dummy18000478_21:1;
    unsigned int    dummy18000478_20:1;
    unsigned int    dummy18000478_19:1;
    unsigned int    dummy18000478_18:1;
    unsigned int    dummy18000478_17:1;
    unsigned int    dummy18000478_16:1;
    unsigned int    dummy18000478_15:1;
    unsigned int    pllddsa_vcorb:1;
    unsigned int    dummy18000478_13:1;
    unsigned int    pllddsa_tst:1;
    unsigned int    pllddsa_pstst:1;
    unsigned int    dummy18000478_10:1;
    unsigned int    reserved_1:10;
}SYS_pll_dispa_sd3;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    dummy1800047c_30:1;
    unsigned int    psaud1a_fupdn:1;
    unsigned int    psaud1a_div:1;
    unsigned int    dummy1800047c_27:1;
    unsigned int    psaud1a_tst:1;
    unsigned int    psaud1a_psen:1;
    unsigned int    dummy1800047c_24:1;
    unsigned int    psaud2a_fupdn:1;
    unsigned int    psaud2a_div:1;
    unsigned int    psaud2a_tst:1;
    unsigned int    psaud2a_psen:1;
    unsigned int    reserved_1:16;
    unsigned int    psaud1a_oeb:1;
    unsigned int    psaud1a_rstb:1;
    unsigned int    psaud2a_oeb:1;
    unsigned int    psaud2a_rstb:1;
}SYS_pll_dispa_sd4;

typedef struct
{
    unsigned int    pllddsa_bypass_pi:1;
    unsigned int    pllddsa_en_pi_debug:1;
    unsigned int    pllddsa_hs_oc_stop:2;
    unsigned int    pllddsa_pi_cur_sel:2;
    unsigned int    pllddsa_sel_oc_mode:2;
    unsigned int    reserved_0:2;
    unsigned int    pllddsa_oc_done_delay:6;
    unsigned int    reserved_1:2;
    unsigned int    pllddsa_oc_step:10;
    unsigned int    reserved_2:1;
    unsigned int    pllddsa_sdm_order:1;
    unsigned int    pllddsa_oc_done:1;
    unsigned int    pllddsa_oc_en:1;
}SYS_dvfs_ddsa;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllddsa_fcode_dbg:11;
    unsigned int    pllddsa_ncode_dbg:8;
    unsigned int    reserved_1:8;
}SYS_dvfs_ddsa2;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    swsce:1;
    unsigned int    reserved_1:1;
    unsigned int    tme:1;
    unsigned int    reserved_2:2;
    unsigned int    tmps:1;
    unsigned int    psc:1;
    unsigned int    reserved_3:3;
    unsigned int    swcs:7;
    unsigned int    reserved_4:7;
    unsigned int    sd:1;
    unsigned int    su:1;
}AI_clkcr;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    swsce_2:1;
    unsigned int    reserved_1:1;
    unsigned int    tme_2:1;
    unsigned int    reserved_2:2;
    unsigned int    tmps_2:1;
    unsigned int    psc_2:1;
    unsigned int    reserved_3:3;
    unsigned int    swcs_2:7;
    unsigned int    reserved_4:7;
    unsigned int    sd_2:1;
    unsigned int    su_2:1;
}AI2_clkcr;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    pllifadc_wdout:1;
    unsigned int    pll27x_wdout:1;
    unsigned int    pllvodma_wdout:1;
    unsigned int    pllkcpu_wdout:1;
    unsigned int    reserved_1:1;
    unsigned int    pllaud_status:1;
    unsigned int    pll512fs_wdout:1;
    unsigned int    pllbush_wdout:1;
    unsigned int    pllgpu_wdout:1;
    unsigned int    plldif_wdout:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    pllbus_wdout:1;
    unsigned int    plldisp_wdout:1;
    unsigned int    reserved_5:1;
    unsigned int    pllddsa_wdout:1;
    unsigned int    pllvcpu_wdout:1;
    unsigned int    pllacpu_wdout:1;
    unsigned int    reserved_6:1;
}SYS_pll_wd_out;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    pll512fs_n:3;
    unsigned int    reserved_1:1;
    unsigned int    pll512fs_m:7;
    unsigned int    pll512fs_bpn:1;
    unsigned int    pll512fs_bps:1;
    unsigned int    pll512fs_cs:2;
    unsigned int    reserved_2:1;
    unsigned int    pll512fs_ip:3;
    unsigned int    pll512fs_s:3;
    unsigned int    pll512fs_q:3;
    unsigned int    pll512fs_rs:3;
    unsigned int    pll512fs_tst:1;
    unsigned int    pll512fs_wdrst:1;
    unsigned int    pll512fs_wdset:1;
}SYS_pll_512fs_1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pll512fs_oeb:1;
    unsigned int    pll512fs_rstb:1;
    unsigned int    pll512fs_pow:1;
}SYS_pll_512fs_2;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:3;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:2;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:3;
    unsigned int    reserved_9:3;
    unsigned int    reserved_10:3;
    unsigned int    reserved_11:3;
    unsigned int    reserved_12:1;
    unsigned int    reserved_13:1;
    unsigned int    reserved_14:1;
}SYS_pll_512fs2_1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
}SYS_pll_512fs2_2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    plldif_n:2;
    unsigned int    reserved_1:1;
    unsigned int    plldif_m:7;
    unsigned int    reserved_2:1;
    unsigned int    plldif_ip:3;
    unsigned int    plldif_lf_rs:2;
    unsigned int    plldif_lf_cp:2;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:11;
}SYS_pll_dif1;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    plldif_dvbs2_en:1;
    unsigned int    reserved_1:2;
    unsigned int    plldif_wdmode:2;
    unsigned int    reserved_2:1;
    unsigned int    plldif_divdig_sel:3;
    unsigned int    reserved_3:1;
    unsigned int    plldif_divadc_sel:3;
}SYS_pll_dif2;

typedef struct
{
    unsigned int    dtvsysclk_sync_sel:1;
    unsigned int    plldif_tst:1;
    unsigned int    reserved_0:27;
    unsigned int    plldif_vco_rstb:1;
    unsigned int    plldif_rstb:1;
    unsigned int    plldif_pow:1;
}SYS_pll_dif3;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pll27x_wdmode:2;
    unsigned int    reserved_1:2;
    unsigned int    pll27x_lf_cp:2;
    unsigned int    reserved_2:2;
    unsigned int    pll27x_lf_rs:2;
    unsigned int    reserved_3:1;
    unsigned int    pll27x_ip:3;
    unsigned int    reserved_4:4;
    unsigned int    reserved_5:2;
    unsigned int    pll27x_n:2;
    unsigned int    reserved_6:1;
    unsigned int    pll27x_m:7;
}SYS_pll_27x1;

typedef struct
{
    unsigned int    xi_cap:4;
    unsigned int    xo_cap:4;
    unsigned int    vdd11_pad_sel:3;
    unsigned int    pll_ldo_xtal_sel:2;
    unsigned int    pll_xixo_load:1;
    unsigned int    pll_xixo_drive_sel:2;
    unsigned int    pad_sel_en:1;
    unsigned int    pll_pow_ldo11v:1;
    unsigned int    pll_ldo11v_sel:2;
    unsigned int    reserved_0:1;
    unsigned int    pll_pow_ldo:1;
    unsigned int    pll_ldo_sel:2;
    unsigned int    reserved_1:2;
    unsigned int    pll27x_ps_54m_delay:2;
    unsigned int    reserved_2:2;
    unsigned int    pll27x_ps_psel_pulse_w:1;
    unsigned int    pll27x_ps_duty_sel:1;
}SYS_pll_27x2;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pll_reserve:8;
    unsigned int    reserved_1:3;
    unsigned int    pll27x_ps_en:1;
    unsigned int    pll27x_ps_div2:1;
    unsigned int    pll27x_vcorstb:1;
    unsigned int    pll27x_rstb:1;
    unsigned int    pll27x_pow:1;
}SYS_pll_27x3;

typedef struct
{
    unsigned int    dummy180004dc_31:1;
    unsigned int    pll27x_ifadc_duty:2;
    unsigned int    reserved_0:1;
    unsigned int    pll_yppadc_cko_polar:1;
    unsigned int    pll_ifadc_cko_polar:1;
    unsigned int    pll_l2h_cml_pow:1;
    unsigned int    pll27x_d16_en:1;
    unsigned int    pll27x_pll_tst:3;
    unsigned int    pll27x_en_tst:1;
    unsigned int    pll_rssi_cko_en:1;
    unsigned int    pll27x_ck108m_en:1;
    unsigned int    pll27x_ck108m_div:2;
    unsigned int    pll27x_yppadc_cko_sel:2;
    unsigned int    pll27x_yppadc_cko_en:1;
    unsigned int    pll27x_yppadc_ck54m_en:1;
    unsigned int    pll27x_ifadc_cko_sel:2;
    unsigned int    pll27x_ifadc_div:1;
    unsigned int    pll27x_ifadc_cko_en:1;
    unsigned int    reserved_1:1;
    unsigned int    xtal_tst:1;
    unsigned int    ps27m_tst:1;
    unsigned int    pllaud_ckin_mux:1;
    unsigned int    pll_xtalwd_rst:1;
    unsigned int    pll_xtalwd_set:1;
    unsigned int    reserved_2:1;
    unsigned int    pll_ck_ifadc_mux:1;
}SYS_pll_27x4;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    pllaud_ip:3;
    unsigned int    reserved_1:2;
    unsigned int    pllaud_rs:2;
    unsigned int    reserved_2:1;
    unsigned int    pllaud_cp:2;
    unsigned int    reserved_3:3;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    pllaud_wdrst:1;
    unsigned int    pllaud_wdset:1;
    unsigned int    pllaud_tst:1;
}SYS_pll_aud1;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    pllaud_vcorstb:1;
    unsigned int    pllaud_rstb:1;
    unsigned int    pllaud_oeb1:1;
    unsigned int    pllaud_oeb2:1;
    unsigned int    pllaud_pow:1;
}SYS_pll_aud3;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    reserved_1:2;
}SYS_pll_aud4;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    psaud_adder_mode:1;
    unsigned int    psaud_psen:1;
    unsigned int    psaud_en:1;
    unsigned int    psaud_tst:1;
    unsigned int    psaud_ctrl:1;
}SYS_pll_psaud1;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    psaud_div:4;
}SYS_pll_psaud2;

typedef struct
{
    unsigned int    dss_adtv_dss_rst_n:1;
    unsigned int    reserved_0:3;
    unsigned int    dss_adtv_ro_sel:3;
    unsigned int    dss_adtv_wire_sel:1;
    unsigned int    reserved_1:3;
    unsigned int    dss_adtv_ready:1;
    unsigned int    dss_adtv_count_out:20;
}SS_adtv_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    dss_adtv_speed_en:1;
    unsigned int    dss_adtv_wsort_go:1;
    unsigned int    dss_adtv_data_in:20;
}SS_adtv_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    dss_adtv_dbgo:16;
}SS_adtv_2;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    ifadc_dtv_cko_tst:1;
    unsigned int    ifadc_atv_cko_tst:1;
    unsigned int    reserved_1:2;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    pll27x_ifadc_dtv_cko_sel:3;
    unsigned int    pll27x_ifadc_dtv_cko_en:1;
    unsigned int    pll27x_ifadc_atv_cko_sel:2;
    unsigned int    reserved_4:1;
    unsigned int    pip_ifadc_atv_cko_sel:1;
}IFADC_1;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    pll27x_ifadc_n:2;
    unsigned int    reserved_1:1;
    unsigned int    pll27x_ifadc_m:7;
    unsigned int    reserved_2:6;
    unsigned int    pll27x_ifadc_lf_rs:2;
    unsigned int    reserved_3:2;
    unsigned int    pll27x_ifadc_lf_cp:2;
    unsigned int    reserved_4:1;
    unsigned int    pll27x_ifadc_ip:3;
}IFADC_2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    pll27x_ifadc_wdmode:2;
    unsigned int    reserved_1:1;
    unsigned int    pll27x_ifadc_vcorstb:1;
    unsigned int    pll27x_ifadc_rstb:1;
    unsigned int    pll27x_ifadc_pow:1;
}IFADC_3;

typedef struct
{
    unsigned int    dclk_field_flag_mode_en:1;
    unsigned int    dclk_filed_flag_slt:3;
    unsigned int    reserved_0:12;
    unsigned int    dclk_new_en:1;
    unsigned int    reserved_1:11;
    unsigned int    dummy18000640_3:1;
    unsigned int    dclk_ss_load:1;
    unsigned int    dummy18000640_1:1;
    unsigned int    dclk_ss_en:1;
}SYS_dclkss;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    dclk_freq_syn_slt:14;
    unsigned int    reserved_1:11;
    unsigned int    fll_tracking_en:1;
    unsigned int    in_frame_tracking_offset_inverse:1;
    unsigned int    in_frame_tracking_ypbpr_en:1;
    unsigned int    in_frame_tracking_vd_dec_en:1;
    unsigned int    in_frame_tracking_general_en:1;
}DPLL_in_fsync_tracking_ctrl;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    in_frame_tracking_mul:19;
}DPLL_in_fsync_tracking_ctrl2;

typedef struct
{
    unsigned int    in_frame_tracking_neg_th:16;
    unsigned int    in_frame_tracking_pos_th:16;
}DPLL_in_fsync_tracking_ctrl3;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    frc2fsync_speed_dir:1;
    unsigned int    reserved_1:3;
    unsigned int    frc2fsync_speedup_offset:13;
}DCLK_frc2fsync_speedup;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    final_profile:18;
}DPLL_status_ro;

typedef struct
{
    unsigned int    dummy18000658_31_12:20;
    unsigned int    dclk_profile_remap_cnt:8;
    unsigned int    reserved_0:3;
    unsigned int    dclk_profile_remap_en:1;
}DCLKSS_profile_ctl;

typedef struct
{
    unsigned int    dclk_profile_remap_1:16;
    unsigned int    dclk_profile_remap_0:16;
}DCLKSS_profile0;

typedef struct
{
    unsigned int    dclk_profile_remap_3:16;
    unsigned int    dclk_profile_remap_2:16;
}DCLKSS_profile1;

typedef struct
{
    unsigned int    dclk_profile_remap_5:16;
    unsigned int    dclk_profile_remap_4:16;
}DCLKSS_profile2;

typedef struct
{
    unsigned int    dclk_profile_remap_7:16;
    unsigned int    dclk_profile_remap_6:16;
}DCLKSS_profile3;

typedef struct
{
    unsigned int    dclk_profile_remap_9:16;
    unsigned int    dclk_profile_remap_8:16;
}DCLKSS_profile4;

typedef struct
{
    unsigned int    dclk_profile_remap_11:16;
    unsigned int    dclk_profile_remap_10:16;
}DCLKSS_profile5;

typedef struct
{
    unsigned int    dclk_profile_remap_13:16;
    unsigned int    dclk_profile_remap_12:16;
}DCLKSS_profile6;

typedef struct
{
    unsigned int    dclk_profile_remap_15:16;
    unsigned int    dclk_profile_remap_14:16;
}DCLKSS_profile7;

typedef struct
{
    unsigned int    dclk_profile_remap_17:16;
    unsigned int    dclk_profile_remap_16:16;
}DCLKSS_profile8;

typedef struct
{
    unsigned int    dclk_profile_remap_19:16;
    unsigned int    dclk_profile_remap_18:16;
}DCLKSS_profile9;

typedef struct
{
    unsigned int    dclk_profile_remap_21:16;
    unsigned int    dclk_profile_remap_20:16;
}DCLKSS_profile10;

typedef struct
{
    unsigned int    dclk_profile_remap_23:16;
    unsigned int    dclk_profile_remap_22:16;
}DCLKSS_profile11;

typedef struct
{
    unsigned int    dclk_profile_remap_25:16;
    unsigned int    dclk_profile_remap_24:16;
}DCLKSS_profile12;

typedef struct
{
    unsigned int    dclk_profile_remap_27:16;
    unsigned int    dclk_profile_remap_26:16;
}DCLKSS_profile13;

typedef struct
{
    unsigned int    dclk_profile_remap_29:16;
    unsigned int    dclk_profile_remap_28:16;
}DCLKSS_profile14;

typedef struct
{
    unsigned int    dclk_profile_remap_31:16;
    unsigned int    dclk_profile_remap_30:16;
}DCLKSS_profile15;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    double_buf_en:1;
    unsigned int    double_buf_read_sel:1;
    unsigned int    double_buf_apply:1;
}DPLL_double_buffer_ctrl;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    fcode_t_ssc:11;
    unsigned int    reserved_1:2;
    unsigned int    oc_step_set:10;
    unsigned int    reserved_2:3;
    unsigned int    oc_en:1;
}PLL_ssc0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    oc_done_delay:6;
    unsigned int    reserved_1:2;
    unsigned int    hs_oc_stop_diff:2;
    unsigned int    reserved_2:2;
    unsigned int    sel_oc_mode:2;
    unsigned int    reserved_3:8;
}PLL_ssc1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    en_pi_debug:1;
    unsigned int    sdm_order:1;
    unsigned int    bypass_pi:1;
}PLL_ssc2;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    ncode_ssc:8;
    unsigned int    reserved_1:5;
    unsigned int    fcode_ssc:11;
}PLL_ssc3;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    gran_auto_rst:1;
    unsigned int    reserved_1:1;
    unsigned int    dot_gran:3;
    unsigned int    reserved_2:1;
    unsigned int    gran_est:19;
    unsigned int    reserved_3:3;
    unsigned int    en_ssc:1;
}PLL_ssc4;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    fcode_debug:11;
    unsigned int    ncode_debug:8;
    unsigned int    reserved_1:3;
    unsigned int    oc_done:1;
    unsigned int    reserved_2:2;
    unsigned int    load_fcw:1;
    unsigned int    fmod:1;
}PLL_ssc5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dpll_m:8;
    unsigned int    reserved_1:5;
    unsigned int    dpll_n:3;
    unsigned int    reserved_2:1;
    unsigned int    dpll_ip:3;
    unsigned int    dpll_ssc_inv:1;
    unsigned int    dpll_rs:3;
    unsigned int    dpll_cp:2;
    unsigned int    dpll_cs:2;
}SYS_pll_disp1;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    dpll_x_bpspi:1;
    unsigned int    dpll_x_bpsin:1;
}SYS_pll_disp2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    dpll_ldosel:2;
    unsigned int    reserved_1:1;
    unsigned int    dpll_dummy:7;
    unsigned int    reserved_2:1;
    unsigned int    dpll_picap:1;
    unsigned int    dpll_prescaler:1;
    unsigned int    dpll_test_en:1;
    unsigned int    reserved_3:2;
    unsigned int    dpll_o:2;
    unsigned int    dpll_reser:4;
    unsigned int    reserved_4:1;
    unsigned int    dpll_rstb:1;
    unsigned int    dpll_wdrst:1;
    unsigned int    dpll_wdset:1;
    unsigned int    reserved_5:1;
    unsigned int    dpll_freeze:1;
    unsigned int    dpll_vcorstb:1;
    unsigned int    dpll_pow:1;
}SYS_pll_disp3;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    dpll_ldodpll_pow:1;
    unsigned int    dpll_pi_ibsel:2;
}SYS_pll_disp4;

typedef struct
{
    unsigned int    sscg_offset_over_flag:1;
    unsigned int    reserved_0:14;
    unsigned int    sscg_offset_over_th_value:17;
}DPLL_in_fsync_tracking_debug0;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    sscg_offset_over_th_max:17;
}DPLL_in_fsync_tracking_debug1;

typedef struct
{
    unsigned int    new_fll_offset_over_flag:1;
    unsigned int    reserved_0:14;
    unsigned int    new_fll_offset_over_th_value:17;
}DPLL_in_fsync_tracking_debug2;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    new_fll_offset_over_th_max:17;
}DPLL_in_fsync_tracking_debug3;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    new_fll_tracking_offset_inverse:1;
    unsigned int    reserved_1:1;
    unsigned int    new_fll_tracking_mul:19;
}DPLL_in_fsync_tracking_ctrl4;

typedef struct
{
    unsigned int    new_fll_tracking_neg_th:16;
    unsigned int    new_fll_tracking_pos_th:16;
}DPLL_in_fsync_tracking_ctrl5;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    pll_emmc_ckssc_inv:1;
    unsigned int    pllscp:1;
    unsigned int    pllscs:2;
    unsigned int    pllsrs:3;
    unsigned int    reserved_1:6;
    unsigned int    pllsdiv2:1;
    unsigned int    pllssi:5;
    unsigned int    pllsnbp:1;
    unsigned int    pllsn:3;
    unsigned int    reserved_2:7;
    unsigned int    pllallrstb:1;
}EMMC_pll_set;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pllemmc_freeze:1;
    unsigned int    reg_pllemmc_bpspi:1;
    unsigned int    reg_pll_tp2_mux:3;
    unsigned int    reg_pll_tp1_mux:3;
    unsigned int    reserved_1:1;
    unsigned int    pllemmc_rsvd:8;
    unsigned int    reserved_2:1;
    unsigned int    pllsstatus:1;
    unsigned int    pllswdrst:1;
    unsigned int    pllswdset:1;
    unsigned int    pllemmc_reg:2;
    unsigned int    pllemmcldopow:1;
    unsigned int    pllemmcpwdn:1;
}EMMC_pll_ctrl;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    pll_pi_autoset:1;
    unsigned int    pllsd2x_3:1;
    unsigned int    pllsd2y_3:1;
    unsigned int    pllsx_3:1;
    unsigned int    pllsy_3:1;
    unsigned int    pllssck_3:6;
    unsigned int    pllsd2x_2:1;
    unsigned int    pllsd2y_2:1;
    unsigned int    pllsx_2:1;
    unsigned int    pllsy_2:1;
    unsigned int    pllssck_2:6;
    unsigned int    pllsd2x:1;
    unsigned int    pllsd2y:1;
    unsigned int    pllsx:1;
    unsigned int    pllsy:1;
    unsigned int    pllssck:6;
}EMMC_pllphase_ctrl;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    pllsd2x_4:1;
    unsigned int    pllsd2y_4:1;
    unsigned int    pllsx_4:1;
    unsigned int    pllsy_4:1;
    unsigned int    pllssck_4:6;
    unsigned int    reserved_1:4;
    unsigned int    pllsphrl:2;
    unsigned int    reserved_2:1;
    unsigned int    pllsphrs:3;
}EMMC_pll_phase_interpolation;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    pllemmc_oc_step_set:10;
    unsigned int    reserved_1:3;
    unsigned int    pllemmc_oc_en:1;
}EMMC_pll_ssc0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    pllemmc_oc_done_delay:6;
    unsigned int    reserved_1:2;
    unsigned int    pllemmc_hs_oc_stop_diff:2;
    unsigned int    pllemmc_pi_cur_sel:2;
    unsigned int    pllemmc_sel_oc_mode:2;
    unsigned int    reserved_2:8;
}EMMC_pll_ssc1;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    pllemmc_en_pi_debug:1;
    unsigned int    pllemmc_sdm_order:1;
    unsigned int    pllemmc_bypass_pi:1;
}EMMC_pll_ssc2;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllemmc_ncode_ssc:8;
    unsigned int    reserved_1:5;
    unsigned int    pllemmc_fcode_ssc:11;
}EMMC_pll_ssc3;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pllemmc_ncode_t:8;
    unsigned int    reserved_1:5;
    unsigned int    pllemmc_fcode_t:11;
}EMMC_pll_ssc4;

typedef struct
{
    unsigned int    reserved_0:3;
    unsigned int    pllemmc_gran_auto_rst:1;
    unsigned int    reserved_1:1;
    unsigned int    pllemmc_dot_gran:3;
    unsigned int    reserved_2:1;
    unsigned int    pllemmc_gran_est:19;
    unsigned int    reserved_3:3;
    unsigned int    pllemmc_en_ssc:1;
}EMMC_pll_ssc5;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pllemmc_fcode_debug:11;
    unsigned int    pllemmc_ncode_debug:8;
    unsigned int    reserved_1:3;
    unsigned int    pllemmc_oc_done:1;
    unsigned int    reserved_2:3;
    unsigned int    pllemmc_fmod:1;
}EMMC_pll_ssc6;
#endif


#define SYS_SRST0                                                     0x18000100
#define SYS_SRST0_reg_addr                                            "0xb8000100"
#define SYS_SRST0_reg                                                 0xb8000100
#define SYS_SRST0_inst_addr                                           "0x0040"
#define SYS_SRST0_inst                                                0x0040
#define set_SYS_SRST0_reg(data)                                       (*((volatile unsigned int*)SYS_SRST0_reg)=data)
#define get_SYS_SRST0_reg                                             (*((volatile unsigned int*)SYS_SRST0_reg))
#define SYS_SRST0_rstn_diseqc_shift                                   (31)
#define SYS_SRST0_rstn_cablerx_shift                                  (30)
#define SYS_SRST0_rstn_hdmi_common_shift                              (29)
#define SYS_SRST0_rstn_hdmi_pre3_shift                                (28)
#define SYS_SRST0_rstn_hdmi_pre2_shift                                (27)
#define SYS_SRST0_rstn_hdmi_pre1_shift                                (26)
#define SYS_SRST0_rstn_hdmi_pre0_shift                                (25)
#define SYS_SRST0_rstn_img_demod_shift                                (24)
#define SYS_SRST0_rstn_img_demod_wrap_shift                           (23)
#define SYS_SRST0_rstn_hdic_apb_shift                                 (22)
#define SYS_SRST0_rstn_hdic_axi_shift                                 (21)
#define SYS_SRST0_rstn_hdic_shift                                     (20)
#define SYS_SRST0_rstn_dtv_frontend_shift                             (19)
#define SYS_SRST0_rstn_kcpu_shift                                     (18)
#define SYS_SRST0_rstn_vde2_shift                                     (17)
#define SYS_SRST0_rstn_ve2_p2_shift                                   (16)
#define SYS_SRST0_rstn_ve2_shift                                      (15)
#define SYS_SRST0_rstn_vcpu2_shift                                    (14)
#define SYS_SRST0_dummy18000100_13_shift                              (13)
#define SYS_SRST0_rstn_acpu_shift                                     (12)
#define SYS_SRST0_rstn_acpu2_shift                                    (11)
#define SYS_SRST0_rstn_ae2_shift                                      (10)
#define SYS_SRST0_rstn_ve_lgcy_p2_shift                               (9)
#define SYS_SRST0_rstn_ve_lgcy_shift                                  (8)
#define SYS_SRST0_rstn_scpu_wrap_shift                                (7)
#define SYS_SRST0_rstn_vde_shift                                      (6)
#define SYS_SRST0_rstn_ve_p2_shift                                    (5)
#define SYS_SRST0_rstn_ve_shift                                       (4)
#define SYS_SRST0_rstn_vcpu_shift                                     (3)
#define SYS_SRST0_rstn_ae_shift                                       (2)
#define SYS_SRST0_rstn_scpu_shift                                     (1)
#define SYS_SRST0_write_data_shift                                    (0)
#define SYS_SRST0_rstn_diseqc_mask                                    (0x80000000)
#define SYS_SRST0_rstn_cablerx_mask                                   (0x40000000)
#define SYS_SRST0_rstn_hdmi_common_mask                               (0x20000000)
#define SYS_SRST0_rstn_hdmi_pre3_mask                                 (0x10000000)
#define SYS_SRST0_rstn_hdmi_pre2_mask                                 (0x08000000)
#define SYS_SRST0_rstn_hdmi_pre1_mask                                 (0x04000000)
#define SYS_SRST0_rstn_hdmi_pre0_mask                                 (0x02000000)
#define SYS_SRST0_rstn_img_demod_mask                                 (0x01000000)
#define SYS_SRST0_rstn_img_demod_wrap_mask                            (0x00800000)
#define SYS_SRST0_rstn_hdic_apb_mask                                  (0x00400000)
#define SYS_SRST0_rstn_hdic_axi_mask                                  (0x00200000)
#define SYS_SRST0_rstn_hdic_mask                                      (0x00100000)
#define SYS_SRST0_rstn_dtv_frontend_mask                              (0x00080000)
#define SYS_SRST0_rstn_kcpu_mask                                      (0x00040000)
#define SYS_SRST0_rstn_vde2_mask                                      (0x00020000)
#define SYS_SRST0_rstn_ve2_p2_mask                                    (0x00010000)
#define SYS_SRST0_rstn_ve2_mask                                       (0x00008000)
#define SYS_SRST0_rstn_vcpu2_mask                                     (0x00004000)
#define SYS_SRST0_dummy18000100_13_mask                               (0x00002000)
#define SYS_SRST0_rstn_acpu_mask                                      (0x00001000)
#define SYS_SRST0_rstn_acpu2_mask                                     (0x00000800)
#define SYS_SRST0_rstn_ae2_mask                                       (0x00000400)
#define SYS_SRST0_rstn_ve_lgcy_p2_mask                                (0x00000200)
#define SYS_SRST0_rstn_ve_lgcy_mask                                   (0x00000100)
#define SYS_SRST0_rstn_scpu_wrap_mask                                 (0x00000080)
#define SYS_SRST0_rstn_vde_mask                                       (0x00000040)
#define SYS_SRST0_rstn_ve_p2_mask                                     (0x00000020)
#define SYS_SRST0_rstn_ve_mask                                        (0x00000010)
#define SYS_SRST0_rstn_vcpu_mask                                      (0x00000008)
#define SYS_SRST0_rstn_ae_mask                                        (0x00000004)
#define SYS_SRST0_rstn_scpu_mask                                      (0x00000002)
#define SYS_SRST0_write_data_mask                                     (0x00000001)
#define SYS_SRST0_rstn_diseqc(data)                                   (0x80000000&((data)<<31))
#define SYS_SRST0_rstn_cablerx(data)                                  (0x40000000&((data)<<30))
#define SYS_SRST0_rstn_hdmi_common(data)                              (0x20000000&((data)<<29))
#define SYS_SRST0_rstn_hdmi_pre3(data)                                (0x10000000&((data)<<28))
#define SYS_SRST0_rstn_hdmi_pre2(data)                                (0x08000000&((data)<<27))
#define SYS_SRST0_rstn_hdmi_pre1(data)                                (0x04000000&((data)<<26))
#define SYS_SRST0_rstn_hdmi_pre0(data)                                (0x02000000&((data)<<25))
#define SYS_SRST0_rstn_img_demod(data)                                (0x01000000&((data)<<24))
#define SYS_SRST0_rstn_img_demod_wrap(data)                           (0x00800000&((data)<<23))
#define SYS_SRST0_rstn_hdic_apb(data)                                 (0x00400000&((data)<<22))
#define SYS_SRST0_rstn_hdic_axi(data)                                 (0x00200000&((data)<<21))
#define SYS_SRST0_rstn_hdic(data)                                     (0x00100000&((data)<<20))
#define SYS_SRST0_rstn_dtv_frontend(data)                             (0x00080000&((data)<<19))
#define SYS_SRST0_rstn_kcpu(data)                                     (0x00040000&((data)<<18))
#define SYS_SRST0_rstn_vde2(data)                                     (0x00020000&((data)<<17))
#define SYS_SRST0_rstn_ve2_p2(data)                                   (0x00010000&((data)<<16))
#define SYS_SRST0_rstn_ve2(data)                                      (0x00008000&((data)<<15))
#define SYS_SRST0_rstn_vcpu2(data)                                    (0x00004000&((data)<<14))
#define SYS_SRST0_dummy18000100_13(data)                              (0x00002000&((data)<<13))
#define SYS_SRST0_rstn_acpu(data)                                     (0x00001000&((data)<<12))
#define SYS_SRST0_rstn_acpu2(data)                                    (0x00000800&((data)<<11))
#define SYS_SRST0_rstn_ae2(data)                                      (0x00000400&((data)<<10))
#define SYS_SRST0_rstn_ve_lgcy_p2(data)                               (0x00000200&((data)<<9))
#define SYS_SRST0_rstn_ve_lgcy(data)                                  (0x00000100&((data)<<8))
#define SYS_SRST0_rstn_scpu_wrap(data)                                (0x00000080&((data)<<7))
#define SYS_SRST0_rstn_vde(data)                                      (0x00000040&((data)<<6))
#define SYS_SRST0_rstn_ve_p2(data)                                    (0x00000020&((data)<<5))
#define SYS_SRST0_rstn_ve(data)                                       (0x00000010&((data)<<4))
#define SYS_SRST0_rstn_vcpu(data)                                     (0x00000008&((data)<<3))
#define SYS_SRST0_rstn_ae(data)                                       (0x00000004&((data)<<2))
#define SYS_SRST0_rstn_scpu(data)                                     (0x00000002&((data)<<1))
#define SYS_SRST0_write_data(data)                                    (0x00000001&(data))
#define SYS_SRST0_get_rstn_diseqc(data)                               ((0x80000000&(data))>>31)
#define SYS_SRST0_get_rstn_cablerx(data)                              ((0x40000000&(data))>>30)
#define SYS_SRST0_get_rstn_hdmi_common(data)                          ((0x20000000&(data))>>29)
#define SYS_SRST0_get_rstn_hdmi_pre3(data)                            ((0x10000000&(data))>>28)
#define SYS_SRST0_get_rstn_hdmi_pre2(data)                            ((0x08000000&(data))>>27)
#define SYS_SRST0_get_rstn_hdmi_pre1(data)                            ((0x04000000&(data))>>26)
#define SYS_SRST0_get_rstn_hdmi_pre0(data)                            ((0x02000000&(data))>>25)
#define SYS_SRST0_get_rstn_img_demod(data)                            ((0x01000000&(data))>>24)
#define SYS_SRST0_get_rstn_img_demod_wrap(data)                       ((0x00800000&(data))>>23)
#define SYS_SRST0_get_rstn_hdic_apb(data)                             ((0x00400000&(data))>>22)
#define SYS_SRST0_get_rstn_hdic_axi(data)                             ((0x00200000&(data))>>21)
#define SYS_SRST0_get_rstn_hdic(data)                                 ((0x00100000&(data))>>20)
#define SYS_SRST0_get_rstn_dtv_frontend(data)                         ((0x00080000&(data))>>19)
#define SYS_SRST0_get_rstn_kcpu(data)                                 ((0x00040000&(data))>>18)
#define SYS_SRST0_get_rstn_vde2(data)                                 ((0x00020000&(data))>>17)
#define SYS_SRST0_get_rstn_ve2_p2(data)                               ((0x00010000&(data))>>16)
#define SYS_SRST0_get_rstn_ve2(data)                                  ((0x00008000&(data))>>15)
#define SYS_SRST0_get_rstn_vcpu2(data)                                ((0x00004000&(data))>>14)
#define SYS_SRST0_get_dummy18000100_13(data)                          ((0x00002000&(data))>>13)
#define SYS_SRST0_get_rstn_acpu(data)                                 ((0x00001000&(data))>>12)
#define SYS_SRST0_get_rstn_acpu2(data)                                ((0x00000800&(data))>>11)
#define SYS_SRST0_get_rstn_ae2(data)                                  ((0x00000400&(data))>>10)
#define SYS_SRST0_get_rstn_ve_lgcy_p2(data)                           ((0x00000200&(data))>>9)
#define SYS_SRST0_get_rstn_ve_lgcy(data)                              ((0x00000100&(data))>>8)
#define SYS_SRST0_get_rstn_scpu_wrap(data)                            ((0x00000080&(data))>>7)
#define SYS_SRST0_get_rstn_vde(data)                                  ((0x00000040&(data))>>6)
#define SYS_SRST0_get_rstn_ve_p2(data)                                ((0x00000020&(data))>>5)
#define SYS_SRST0_get_rstn_ve(data)                                   ((0x00000010&(data))>>4)
#define SYS_SRST0_get_rstn_vcpu(data)                                 ((0x00000008&(data))>>3)
#define SYS_SRST0_get_rstn_ae(data)                                   ((0x00000004&(data))>>2)
#define SYS_SRST0_get_rstn_scpu(data)                                 ((0x00000002&(data))>>1)
#define SYS_SRST0_get_write_data(data)                                (0x00000001&(data))


#define SYS_SRST1                                                     0x18000104
#define SYS_SRST1_reg_addr                                            "0xb8000104"
#define SYS_SRST1_reg                                                 0xb8000104
#define SYS_SRST1_inst_addr                                           "0x0041"
#define SYS_SRST1_inst                                                0x0041
#define set_SYS_SRST1_reg(data)                                       (*((volatile unsigned int*)SYS_SRST1_reg)=data)
#define get_SYS_SRST1_reg                                             (*((volatile unsigned int*)SYS_SRST1_reg))
#define SYS_SRST1_rstn_tvsb1_shift                                    (31)
#define SYS_SRST1_rstn_tvsb2_shift                                    (30)
#define SYS_SRST1_rstn_tvsb3_shift                                    (29)
#define SYS_SRST1_rstn_tvsb4_shift                                    (28)
#define SYS_SRST1_rstn_tvsb5_shift                                    (27)
#define SYS_SRST1_rstn_tve_shift                                      (26)
#define SYS_SRST1_rstn_dcphy_shift                                    (25)
#define SYS_SRST1_rstn_dcu_shift                                      (24)
#define SYS_SRST1_rstn_if_demod_shift                                 (23)
#define SYS_SRST1_rstn_vdec_shift                                     (22)
#define SYS_SRST1_rstn_vdec2_shift                                    (21)
#define SYS_SRST1_rstn_vbis0_shift                                    (20)
#define SYS_SRST1_rstn_audio2_dac_shift                               (19)
#define SYS_SRST1_rstn_audio_adc_shift                                (18)
#define SYS_SRST1_rstn_audio_dac_shift                                (17)
#define SYS_SRST1_rstn_audio_shift                                    (16)
#define SYS_SRST1_rstn_ifadc_shift                                    (15)
#define SYS_SRST1_rstn_cbus_shift                                     (14)
#define SYS_SRST1_rstn_offms_shift                                    (13)
#define SYS_SRST1_rstn_me_shift                                       (12)
#define SYS_SRST1_rstn_apll_adc_shift                                 (11)
#define SYS_SRST1_rstn_hdmi_shift                                     (10)
#define SYS_SRST1_rstn_dispd_shift                                    (9)
#define SYS_SRST1_rstn_tp_shift                                       (8)
#define SYS_SRST1_rstn_cp_shift                                       (7)
#define SYS_SRST1_rstn_md_shift                                       (6)
#define SYS_SRST1_rstn_se_shift                                       (5)
#define SYS_SRST1_dummy18000104_4_shift                               (4)
#define SYS_SRST1_rstn_3d_gde_shift                                   (3)
#define SYS_SRST1_rstn_vodma_shift                                    (2)
#define SYS_SRST1_rstn_dispi_shift                                    (1)
#define SYS_SRST1_write_data_shift                                    (0)
#define SYS_SRST1_rstn_tvsb1_mask                                     (0x80000000)
#define SYS_SRST1_rstn_tvsb2_mask                                     (0x40000000)
#define SYS_SRST1_rstn_tvsb3_mask                                     (0x20000000)
#define SYS_SRST1_rstn_tvsb4_mask                                     (0x10000000)
#define SYS_SRST1_rstn_tvsb5_mask                                     (0x08000000)
#define SYS_SRST1_rstn_tve_mask                                       (0x04000000)
#define SYS_SRST1_rstn_dcphy_mask                                     (0x02000000)
#define SYS_SRST1_rstn_dcu_mask                                       (0x01000000)
#define SYS_SRST1_rstn_if_demod_mask                                  (0x00800000)
#define SYS_SRST1_rstn_vdec_mask                                      (0x00400000)
#define SYS_SRST1_rstn_vdec2_mask                                     (0x00200000)
#define SYS_SRST1_rstn_vbis0_mask                                     (0x00100000)
#define SYS_SRST1_rstn_audio2_dac_mask                                (0x00080000)
#define SYS_SRST1_rstn_audio_adc_mask                                 (0x00040000)
#define SYS_SRST1_rstn_audio_dac_mask                                 (0x00020000)
#define SYS_SRST1_rstn_audio_mask                                     (0x00010000)
#define SYS_SRST1_rstn_ifadc_mask                                     (0x00008000)
#define SYS_SRST1_rstn_cbus_mask                                      (0x00004000)
#define SYS_SRST1_rstn_offms_mask                                     (0x00002000)
#define SYS_SRST1_rstn_me_mask                                        (0x00001000)
#define SYS_SRST1_rstn_apll_adc_mask                                  (0x00000800)
#define SYS_SRST1_rstn_hdmi_mask                                      (0x00000400)
#define SYS_SRST1_rstn_dispd_mask                                     (0x00000200)
#define SYS_SRST1_rstn_tp_mask                                        (0x00000100)
#define SYS_SRST1_rstn_cp_mask                                        (0x00000080)
#define SYS_SRST1_rstn_md_mask                                        (0x00000040)
#define SYS_SRST1_rstn_se_mask                                        (0x00000020)
#define SYS_SRST1_dummy18000104_4_mask                                (0x00000010)
#define SYS_SRST1_rstn_3d_gde_mask                                    (0x00000008)
#define SYS_SRST1_rstn_vodma_mask                                     (0x00000004)
#define SYS_SRST1_rstn_dispi_mask                                     (0x00000002)
#define SYS_SRST1_write_data_mask                                     (0x00000001)
#define SYS_SRST1_rstn_tvsb1(data)                                    (0x80000000&((data)<<31))
#define SYS_SRST1_rstn_tvsb2(data)                                    (0x40000000&((data)<<30))
#define SYS_SRST1_rstn_tvsb3(data)                                    (0x20000000&((data)<<29))
#define SYS_SRST1_rstn_tvsb4(data)                                    (0x10000000&((data)<<28))
#define SYS_SRST1_rstn_tvsb5(data)                                    (0x08000000&((data)<<27))
#define SYS_SRST1_rstn_tve(data)                                      (0x04000000&((data)<<26))
#define SYS_SRST1_rstn_dcphy(data)                                    (0x02000000&((data)<<25))
#define SYS_SRST1_rstn_dcu(data)                                      (0x01000000&((data)<<24))
#define SYS_SRST1_rstn_if_demod(data)                                 (0x00800000&((data)<<23))
#define SYS_SRST1_rstn_vdec(data)                                     (0x00400000&((data)<<22))
#define SYS_SRST1_rstn_vdec2(data)                                    (0x00200000&((data)<<21))
#define SYS_SRST1_rstn_vbis0(data)                                    (0x00100000&((data)<<20))
#define SYS_SRST1_rstn_audio2_dac(data)                               (0x00080000&((data)<<19))
#define SYS_SRST1_rstn_audio_adc(data)                                (0x00040000&((data)<<18))
#define SYS_SRST1_rstn_audio_dac(data)                                (0x00020000&((data)<<17))
#define SYS_SRST1_rstn_audio(data)                                    (0x00010000&((data)<<16))
#define SYS_SRST1_rstn_ifadc(data)                                    (0x00008000&((data)<<15))
#define SYS_SRST1_rstn_cbus(data)                                     (0x00004000&((data)<<14))
#define SYS_SRST1_rstn_offms(data)                                    (0x00002000&((data)<<13))
#define SYS_SRST1_rstn_me(data)                                       (0x00001000&((data)<<12))
#define SYS_SRST1_rstn_apll_adc(data)                                 (0x00000800&((data)<<11))
#define SYS_SRST1_rstn_hdmi(data)                                     (0x00000400&((data)<<10))
#define SYS_SRST1_rstn_dispd(data)                                    (0x00000200&((data)<<9))
#define SYS_SRST1_rstn_tp(data)                                       (0x00000100&((data)<<8))
#define SYS_SRST1_rstn_cp(data)                                       (0x00000080&((data)<<7))
#define SYS_SRST1_rstn_md(data)                                       (0x00000040&((data)<<6))
#define SYS_SRST1_rstn_se(data)                                       (0x00000020&((data)<<5))
#define SYS_SRST1_dummy18000104_4(data)                               (0x00000010&((data)<<4))
#define SYS_SRST1_rstn_3d_gde(data)                                   (0x00000008&((data)<<3))
#define SYS_SRST1_rstn_vodma(data)                                    (0x00000004&((data)<<2))
#define SYS_SRST1_rstn_dispi(data)                                    (0x00000002&((data)<<1))
#define SYS_SRST1_write_data(data)                                    (0x00000001&(data))
#define SYS_SRST1_get_rstn_tvsb1(data)                                ((0x80000000&(data))>>31)
#define SYS_SRST1_get_rstn_tvsb2(data)                                ((0x40000000&(data))>>30)
#define SYS_SRST1_get_rstn_tvsb3(data)                                ((0x20000000&(data))>>29)
#define SYS_SRST1_get_rstn_tvsb4(data)                                ((0x10000000&(data))>>28)
#define SYS_SRST1_get_rstn_tvsb5(data)                                ((0x08000000&(data))>>27)
#define SYS_SRST1_get_rstn_tve(data)                                  ((0x04000000&(data))>>26)
#define SYS_SRST1_get_rstn_dcphy(data)                                ((0x02000000&(data))>>25)
#define SYS_SRST1_get_rstn_dcu(data)                                  ((0x01000000&(data))>>24)
#define SYS_SRST1_get_rstn_if_demod(data)                             ((0x00800000&(data))>>23)
#define SYS_SRST1_get_rstn_vdec(data)                                 ((0x00400000&(data))>>22)
#define SYS_SRST1_get_rstn_vdec2(data)                                ((0x00200000&(data))>>21)
#define SYS_SRST1_get_rstn_vbis0(data)                                ((0x00100000&(data))>>20)
#define SYS_SRST1_get_rstn_audio2_dac(data)                           ((0x00080000&(data))>>19)
#define SYS_SRST1_get_rstn_audio_adc(data)                            ((0x00040000&(data))>>18)
#define SYS_SRST1_get_rstn_audio_dac(data)                            ((0x00020000&(data))>>17)
#define SYS_SRST1_get_rstn_audio(data)                                ((0x00010000&(data))>>16)
#define SYS_SRST1_get_rstn_ifadc(data)                                ((0x00008000&(data))>>15)
#define SYS_SRST1_get_rstn_cbus(data)                                 ((0x00004000&(data))>>14)
#define SYS_SRST1_get_rstn_offms(data)                                ((0x00002000&(data))>>13)
#define SYS_SRST1_get_rstn_me(data)                                   ((0x00001000&(data))>>12)
#define SYS_SRST1_get_rstn_apll_adc(data)                             ((0x00000800&(data))>>11)
#define SYS_SRST1_get_rstn_hdmi(data)                                 ((0x00000400&(data))>>10)
#define SYS_SRST1_get_rstn_dispd(data)                                ((0x00000200&(data))>>9)
#define SYS_SRST1_get_rstn_tp(data)                                   ((0x00000100&(data))>>8)
#define SYS_SRST1_get_rstn_cp(data)                                   ((0x00000080&(data))>>7)
#define SYS_SRST1_get_rstn_md(data)                                   ((0x00000040&(data))>>6)
#define SYS_SRST1_get_rstn_se(data)                                   ((0x00000020&(data))>>5)
#define SYS_SRST1_get_dummy18000104_4(data)                           ((0x00000010&(data))>>4)
#define SYS_SRST1_get_rstn_3d_gde(data)                               ((0x00000008&(data))>>3)
#define SYS_SRST1_get_rstn_vodma(data)                                ((0x00000004&(data))>>2)
#define SYS_SRST1_get_rstn_dispi(data)                                ((0x00000002&(data))>>1)
#define SYS_SRST1_get_write_data(data)                                (0x00000001&(data))


#define SYS_SRST2                                                     0x18000108
#define SYS_SRST2_reg_addr                                            "0xb8000108"
#define SYS_SRST2_reg                                                 0xb8000108
#define SYS_SRST2_inst_addr                                           "0x0042"
#define SYS_SRST2_inst                                                0x0042
#define set_SYS_SRST2_reg(data)                                       (*((volatile unsigned int*)SYS_SRST2_reg)=data)
#define get_SYS_SRST2_reg                                             (*((volatile unsigned int*)SYS_SRST2_reg))
#define SYS_SRST2_rstn_usb2_ex_shift                                  (29)
#define SYS_SRST2_rstn_tm_shift                                       (28)
#define SYS_SRST2_rstn_atvin2_shift                                   (27)
#define SYS_SRST2_rstn_atvin_shift                                    (26)
#define SYS_SRST2_rstn_dispm_cap_shift                                (25)
#define SYS_SRST2_rstn_dispm_disp_shift                               (24)
#define SYS_SRST2_rstn_emmc_shift                                     (23)
#define SYS_SRST2_rstn_if_demod_logic_shift                           (22)
#define SYS_SRST2_rstn_bistreg_shift                                  (21)
#define SYS_SRST2_rstn_i2c4_shift                                     (20)
#define SYS_SRST2_rstn_pllreg_shift                                   (19)
#define SYS_SRST2_rstn_usb3_shift                                     (18)
#define SYS_SRST2_rstn_usb2_shift                                     (17)
#define SYS_SRST2_rstn_pcmcia_shift                                   (16)
#define SYS_SRST2_dummy18000108_15_shift                              (15)
#define SYS_SRST2_rstn_i2c3_shift                                     (14)
#define SYS_SRST2_rstn_irtx_shift                                     (13)
#define SYS_SRST2_dummy18000108_12_shift                              (12)
#define SYS_SRST2_rstn_dtv_demod_shift                                (11)
#define SYS_SRST2_rstn_misc_shift                                     (10)
#define SYS_SRST2_rstn_pwm_shift                                      (9)
#define SYS_SRST2_rstn_uart1_shift                                    (8)
#define SYS_SRST2_rstn_uart2_shift                                    (7)
#define SYS_SRST2_dummy18000108_6_shift                               (6)
#define SYS_SRST2_rstn_gpio_shift                                     (5)
#define SYS_SRST2_rstn_i2c1_shift                                     (4)
#define SYS_SRST2_rstn_i2c2_shift                                     (3)
#define SYS_SRST2_rstn_nf_shift                                       (2)
#define SYS_SRST2_rstn_sc_shift                                       (1)
#define SYS_SRST2_write_data_shift                                    (0)
#define SYS_SRST2_rstn_usb2_ex_mask                                   (0x20000000)
#define SYS_SRST2_rstn_tm_mask                                        (0x10000000)
#define SYS_SRST2_rstn_atvin2_mask                                    (0x08000000)
#define SYS_SRST2_rstn_atvin_mask                                     (0x04000000)
#define SYS_SRST2_rstn_dispm_cap_mask                                 (0x02000000)
#define SYS_SRST2_rstn_dispm_disp_mask                                (0x01000000)
#define SYS_SRST2_rstn_emmc_mask                                      (0x00800000)
#define SYS_SRST2_rstn_if_demod_logic_mask                            (0x00400000)
#define SYS_SRST2_rstn_bistreg_mask                                   (0x00200000)
#define SYS_SRST2_rstn_i2c4_mask                                      (0x00100000)
#define SYS_SRST2_rstn_pllreg_mask                                    (0x00080000)
#define SYS_SRST2_rstn_usb3_mask                                      (0x00040000)
#define SYS_SRST2_rstn_usb2_mask                                      (0x00020000)
#define SYS_SRST2_rstn_pcmcia_mask                                    (0x00010000)
#define SYS_SRST2_dummy18000108_15_mask                               (0x00008000)
#define SYS_SRST2_rstn_i2c3_mask                                      (0x00004000)
#define SYS_SRST2_rstn_irtx_mask                                      (0x00002000)
#define SYS_SRST2_dummy18000108_12_mask                               (0x00001000)
#define SYS_SRST2_rstn_dtv_demod_mask                                 (0x00000800)
#define SYS_SRST2_rstn_misc_mask                                      (0x00000400)
#define SYS_SRST2_rstn_pwm_mask                                       (0x00000200)
#define SYS_SRST2_rstn_uart1_mask                                     (0x00000100)
#define SYS_SRST2_rstn_uart2_mask                                     (0x00000080)
#define SYS_SRST2_dummy18000108_6_mask                                (0x00000040)
#define SYS_SRST2_rstn_gpio_mask                                      (0x00000020)
#define SYS_SRST2_rstn_i2c1_mask                                      (0x00000010)
#define SYS_SRST2_rstn_i2c2_mask                                      (0x00000008)
#define SYS_SRST2_rstn_nf_mask                                        (0x00000004)
#define SYS_SRST2_rstn_sc_mask                                        (0x00000002)
#define SYS_SRST2_write_data_mask                                     (0x00000001)
#define SYS_SRST2_rstn_usb2_ex(data)                                  (0x20000000&((data)<<29))
#define SYS_SRST2_rstn_tm(data)                                       (0x10000000&((data)<<28))
#define SYS_SRST2_rstn_atvin2(data)                                   (0x08000000&((data)<<27))
#define SYS_SRST2_rstn_atvin(data)                                    (0x04000000&((data)<<26))
#define SYS_SRST2_rstn_dispm_cap(data)                                (0x02000000&((data)<<25))
#define SYS_SRST2_rstn_dispm_disp(data)                               (0x01000000&((data)<<24))
#define SYS_SRST2_rstn_emmc(data)                                     (0x00800000&((data)<<23))
#define SYS_SRST2_rstn_if_demod_logic(data)                           (0x00400000&((data)<<22))
#define SYS_SRST2_rstn_bistreg(data)                                  (0x00200000&((data)<<21))
#define SYS_SRST2_rstn_i2c4(data)                                     (0x00100000&((data)<<20))
#define SYS_SRST2_rstn_pllreg(data)                                   (0x00080000&((data)<<19))
#define SYS_SRST2_rstn_usb3(data)                                     (0x00040000&((data)<<18))
#define SYS_SRST2_rstn_usb2(data)                                     (0x00020000&((data)<<17))
#define SYS_SRST2_rstn_pcmcia(data)                                   (0x00010000&((data)<<16))
#define SYS_SRST2_dummy18000108_15(data)                              (0x00008000&((data)<<15))
#define SYS_SRST2_rstn_i2c3(data)                                     (0x00004000&((data)<<14))
#define SYS_SRST2_rstn_irtx(data)                                     (0x00002000&((data)<<13))
#define SYS_SRST2_dummy18000108_12(data)                              (0x00001000&((data)<<12))
#define SYS_SRST2_rstn_dtv_demod(data)                                (0x00000800&((data)<<11))
#define SYS_SRST2_rstn_misc(data)                                     (0x00000400&((data)<<10))
#define SYS_SRST2_rstn_pwm(data)                                      (0x00000200&((data)<<9))
#define SYS_SRST2_rstn_uart1(data)                                    (0x00000100&((data)<<8))
#define SYS_SRST2_rstn_uart2(data)                                    (0x00000080&((data)<<7))
#define SYS_SRST2_dummy18000108_6(data)                               (0x00000040&((data)<<6))
#define SYS_SRST2_rstn_gpio(data)                                     (0x00000020&((data)<<5))
#define SYS_SRST2_rstn_i2c1(data)                                     (0x00000010&((data)<<4))
#define SYS_SRST2_rstn_i2c2(data)                                     (0x00000008&((data)<<3))
#define SYS_SRST2_rstn_nf(data)                                       (0x00000004&((data)<<2))
#define SYS_SRST2_rstn_sc(data)                                       (0x00000002&((data)<<1))
#define SYS_SRST2_write_data(data)                                    (0x00000001&(data))
#define SYS_SRST2_get_rstn_usb2_ex(data)                              ((0x20000000&(data))>>29)
#define SYS_SRST2_get_rstn_tm(data)                                   ((0x10000000&(data))>>28)
#define SYS_SRST2_get_rstn_atvin2(data)                               ((0x08000000&(data))>>27)
#define SYS_SRST2_get_rstn_atvin(data)                                ((0x04000000&(data))>>26)
#define SYS_SRST2_get_rstn_dispm_cap(data)                            ((0x02000000&(data))>>25)
#define SYS_SRST2_get_rstn_dispm_disp(data)                           ((0x01000000&(data))>>24)
#define SYS_SRST2_get_rstn_emmc(data)                                 ((0x00800000&(data))>>23)
#define SYS_SRST2_get_rstn_if_demod_logic(data)                       ((0x00400000&(data))>>22)
#define SYS_SRST2_get_rstn_bistreg(data)                              ((0x00200000&(data))>>21)
#define SYS_SRST2_get_rstn_i2c4(data)                                 ((0x00100000&(data))>>20)
#define SYS_SRST2_get_rstn_pllreg(data)                               ((0x00080000&(data))>>19)
#define SYS_SRST2_get_rstn_usb3(data)                                 ((0x00040000&(data))>>18)
#define SYS_SRST2_get_rstn_usb2(data)                                 ((0x00020000&(data))>>17)
#define SYS_SRST2_get_rstn_pcmcia(data)                               ((0x00010000&(data))>>16)
#define SYS_SRST2_get_dummy18000108_15(data)                          ((0x00008000&(data))>>15)
#define SYS_SRST2_get_rstn_i2c3(data)                                 ((0x00004000&(data))>>14)
#define SYS_SRST2_get_rstn_irtx(data)                                 ((0x00002000&(data))>>13)
#define SYS_SRST2_get_dummy18000108_12(data)                          ((0x00001000&(data))>>12)
#define SYS_SRST2_get_rstn_dtv_demod(data)                            ((0x00000800&(data))>>11)
#define SYS_SRST2_get_rstn_misc(data)                                 ((0x00000400&(data))>>10)
#define SYS_SRST2_get_rstn_pwm(data)                                  ((0x00000200&(data))>>9)
#define SYS_SRST2_get_rstn_uart1(data)                                ((0x00000100&(data))>>8)
#define SYS_SRST2_get_rstn_uart2(data)                                ((0x00000080&(data))>>7)
#define SYS_SRST2_get_dummy18000108_6(data)                           ((0x00000040&(data))>>6)
#define SYS_SRST2_get_rstn_gpio(data)                                 ((0x00000020&(data))>>5)
#define SYS_SRST2_get_rstn_i2c1(data)                                 ((0x00000010&(data))>>4)
#define SYS_SRST2_get_rstn_i2c2(data)                                 ((0x00000008&(data))>>3)
#define SYS_SRST2_get_rstn_nf(data)                                   ((0x00000004&(data))>>2)
#define SYS_SRST2_get_rstn_sc(data)                                   ((0x00000002&(data))>>1)
#define SYS_SRST2_get_write_data(data)                                (0x00000001&(data))


#define SYS_SRST3                                                     0x1800010c
#define SYS_SRST3_reg_addr                                            "0xb800010c"
#define SYS_SRST3_reg                                                 0xb800010c
#define SYS_SRST3_inst_addr                                           "0x0043"
#define SYS_SRST3_inst                                                0x0043
#define set_SYS_SRST3_reg(data)                                       (*((volatile unsigned int*)SYS_SRST3_reg)=data)
#define get_SYS_SRST3_reg                                             (*((volatile unsigned int*)SYS_SRST3_reg))
#define SYS_SRST3_rstn_memc_shift                                     (31)
#define SYS_SRST3_rstn_memc_me_shift                                  (30)
#define SYS_SRST3_rstn_memc_rbus_shift                                (29)
#define SYS_SRST3_rstn_dcphy2_shift                                   (25)
#define SYS_SRST3_rstn_dcu2_shift                                     (24)
#define SYS_SRST3_rstn_dcphy_mc_shift                                 (23)
#define SYS_SRST3_rstn_disp_lg_hcic_shift                             (22)
#define SYS_SRST3_rstn_disp_lg_mplus_shift                            (21)
#define SYS_SRST3_rstn_d_boe_rgbw_pxl_shift                           (20)
#define SYS_SRST3_rstn_d_boe_rgbw_apb_shift                           (19)
#define SYS_SRST3_rstn_d_boe_rgbw_mcu_shift                           (18)
#define SYS_SRST3_rstn_ddc_shift                                      (17)
#define SYS_SRST3_rstn_sd_shift                                       (16)
#define SYS_SRST3_rstn_usb2_phy_p3_shift                              (7)
#define SYS_SRST3_rstn_usb2_phy_p2_shift                              (6)
#define SYS_SRST3_rstn_usb2_phy_p1_shift                              (5)
#define SYS_SRST3_rstn_usb2_phy_p0_shift                              (4)
#define SYS_SRST3_rstn_usb3_phy_p0_shift                              (2)
#define SYS_SRST3_rstn_usb3_mdio_p0_shift                             (1)
#define SYS_SRST3_write_data_shift                                    (0)
#define SYS_SRST3_rstn_memc_mask                                      (0x80000000)
#define SYS_SRST3_rstn_memc_me_mask                                   (0x40000000)
#define SYS_SRST3_rstn_memc_rbus_mask                                 (0x20000000)
#define SYS_SRST3_rstn_dcphy2_mask                                    (0x02000000)
#define SYS_SRST3_rstn_dcu2_mask                                      (0x01000000)
#define SYS_SRST3_rstn_dcphy_mc_mask                                  (0x00800000)
#define SYS_SRST3_rstn_disp_lg_hcic_mask                              (0x00400000)
#define SYS_SRST3_rstn_disp_lg_mplus_mask                             (0x00200000)
#define SYS_SRST3_rstn_d_boe_rgbw_pxl_mask                            (0x00100000)
#define SYS_SRST3_rstn_d_boe_rgbw_apb_mask                            (0x00080000)
#define SYS_SRST3_rstn_d_boe_rgbw_mcu_mask                            (0x00040000)
#define SYS_SRST3_rstn_ddc_mask                                       (0x00020000)
#define SYS_SRST3_rstn_sd_mask                                        (0x00010000)
#define SYS_SRST3_rstn_usb2_phy_p3_mask                               (0x00000080)
#define SYS_SRST3_rstn_usb2_phy_p2_mask                               (0x00000040)
#define SYS_SRST3_rstn_usb2_phy_p1_mask                               (0x00000020)
#define SYS_SRST3_rstn_usb2_phy_p0_mask                               (0x00000010)
#define SYS_SRST3_rstn_usb3_phy_p0_mask                               (0x00000004)
#define SYS_SRST3_rstn_usb3_mdio_p0_mask                              (0x00000002)
#define SYS_SRST3_write_data_mask                                     (0x00000001)
#define SYS_SRST3_rstn_memc(data)                                     (0x80000000&((data)<<31))
#define SYS_SRST3_rstn_memc_me(data)                                  (0x40000000&((data)<<30))
#define SYS_SRST3_rstn_memc_rbus(data)                                (0x20000000&((data)<<29))
#define SYS_SRST3_rstn_dcphy2(data)                                   (0x02000000&((data)<<25))
#define SYS_SRST3_rstn_dcu2(data)                                     (0x01000000&((data)<<24))
#define SYS_SRST3_rstn_dcphy_mc(data)                                 (0x00800000&((data)<<23))
#define SYS_SRST3_rstn_disp_lg_hcic(data)                             (0x00400000&((data)<<22))
#define SYS_SRST3_rstn_disp_lg_mplus(data)                            (0x00200000&((data)<<21))
#define SYS_SRST3_rstn_d_boe_rgbw_pxl(data)                           (0x00100000&((data)<<20))
#define SYS_SRST3_rstn_d_boe_rgbw_apb(data)                           (0x00080000&((data)<<19))
#define SYS_SRST3_rstn_d_boe_rgbw_mcu(data)                           (0x00040000&((data)<<18))
#define SYS_SRST3_rstn_ddc(data)                                      (0x00020000&((data)<<17))
#define SYS_SRST3_rstn_sd(data)                                       (0x00010000&((data)<<16))
#define SYS_SRST3_rstn_usb2_phy_p3(data)                              (0x00000080&((data)<<7))
#define SYS_SRST3_rstn_usb2_phy_p2(data)                              (0x00000040&((data)<<6))
#define SYS_SRST3_rstn_usb2_phy_p1(data)                              (0x00000020&((data)<<5))
#define SYS_SRST3_rstn_usb2_phy_p0(data)                              (0x00000010&((data)<<4))
#define SYS_SRST3_rstn_usb3_phy_p0(data)                              (0x00000004&((data)<<2))
#define SYS_SRST3_rstn_usb3_mdio_p0(data)                             (0x00000002&((data)<<1))
#define SYS_SRST3_write_data(data)                                    (0x00000001&(data))
#define SYS_SRST3_get_rstn_memc(data)                                 ((0x80000000&(data))>>31)
#define SYS_SRST3_get_rstn_memc_me(data)                              ((0x40000000&(data))>>30)
#define SYS_SRST3_get_rstn_memc_rbus(data)                            ((0x20000000&(data))>>29)
#define SYS_SRST3_get_rstn_dcphy2(data)                               ((0x02000000&(data))>>25)
#define SYS_SRST3_get_rstn_dcu2(data)                                 ((0x01000000&(data))>>24)
#define SYS_SRST3_get_rstn_dcphy_mc(data)                             ((0x00800000&(data))>>23)
#define SYS_SRST3_get_rstn_disp_lg_hcic(data)                         ((0x00400000&(data))>>22)
#define SYS_SRST3_get_rstn_disp_lg_mplus(data)                        ((0x00200000&(data))>>21)
#define SYS_SRST3_get_rstn_d_boe_rgbw_pxl(data)                       ((0x00100000&(data))>>20)
#define SYS_SRST3_get_rstn_d_boe_rgbw_apb(data)                       ((0x00080000&(data))>>19)
#define SYS_SRST3_get_rstn_d_boe_rgbw_mcu(data)                       ((0x00040000&(data))>>18)
#define SYS_SRST3_get_rstn_ddc(data)                                  ((0x00020000&(data))>>17)
#define SYS_SRST3_get_rstn_sd(data)                                   ((0x00010000&(data))>>16)
#define SYS_SRST3_get_rstn_usb2_phy_p3(data)                          ((0x00000080&(data))>>7)
#define SYS_SRST3_get_rstn_usb2_phy_p2(data)                          ((0x00000040&(data))>>6)
#define SYS_SRST3_get_rstn_usb2_phy_p1(data)                          ((0x00000020&(data))>>5)
#define SYS_SRST3_get_rstn_usb2_phy_p0(data)                          ((0x00000010&(data))>>4)
#define SYS_SRST3_get_rstn_usb3_phy_p0(data)                          ((0x00000004&(data))>>2)
#define SYS_SRST3_get_rstn_usb3_mdio_p0(data)                         ((0x00000002&(data))>>1)
#define SYS_SRST3_get_write_data(data)                                (0x00000001&(data))


#define SYS_CLKEN0                                                    0x18000110
#define SYS_CLKEN0_reg_addr                                           "0xb8000110"
#define SYS_CLKEN0_reg                                                0xb8000110
#define SYS_CLKEN0_inst_addr                                          "0x0044"
#define SYS_CLKEN0_inst                                               0x0044
#define set_SYS_CLKEN0_reg(data)                                      (*((volatile unsigned int*)SYS_CLKEN0_reg)=data)
#define get_SYS_CLKEN0_reg                                            (*((volatile unsigned int*)SYS_CLKEN0_reg))
#define SYS_CLKEN0_clken_diseqc_shift                                 (31)
#define SYS_CLKEN0_clken_cablerx_shift                                (30)
#define SYS_CLKEN0_clken_hdmi_common_shift                            (29)
#define SYS_CLKEN0_clken_hdmi_pre3_shift                              (28)
#define SYS_CLKEN0_clken_hdmi_pre2_shift                              (27)
#define SYS_CLKEN0_clken_hdmi_pre1_shift                              (26)
#define SYS_CLKEN0_clken_hdmi_pre0_shift                              (25)
#define SYS_CLKEN0_clken_img_demod_shift                              (24)
#define SYS_CLKEN0_clken_img_demod_wrap_shift                         (23)
#define SYS_CLKEN0_clken_hdic_shift                                   (20)
#define SYS_CLKEN0_clken_dtv_frontend_shift                           (19)
#define SYS_CLKEN0_clken_kcpu_shift                                   (18)
#define SYS_CLKEN0_clken_ve2_p2_shift                                 (16)
#define SYS_CLKEN0_clken_ve2_shift                                    (15)
#define SYS_CLKEN0_clken_vcpu2_shift                                  (14)
#define SYS_CLKEN0_dummy18000110_13_shift                             (13)
#define SYS_CLKEN0_clken_acpu_shift                                   (12)
#define SYS_CLKEN0_clken_acpu2_shift                                  (11)
#define SYS_CLKEN0_clken_ve_lgcy_p2_shift                             (7)
#define SYS_CLKEN0_clken_ve_lgcy_shift                                (6)
#define SYS_CLKEN0_clken_ve_p2_shift                                  (5)
#define SYS_CLKEN0_clken_ve_shift                                     (4)
#define SYS_CLKEN0_clken_vcpu_shift                                   (3)
#define SYS_CLKEN0_clken_scpu_wrap_shift                              (2)
#define SYS_CLKEN0_clken_scpu_shift                                   (1)
#define SYS_CLKEN0_write_data_shift                                   (0)
#define SYS_CLKEN0_clken_diseqc_mask                                  (0x80000000)
#define SYS_CLKEN0_clken_cablerx_mask                                 (0x40000000)
#define SYS_CLKEN0_clken_hdmi_common_mask                             (0x20000000)
#define SYS_CLKEN0_clken_hdmi_pre3_mask                               (0x10000000)
#define SYS_CLKEN0_clken_hdmi_pre2_mask                               (0x08000000)
#define SYS_CLKEN0_clken_hdmi_pre1_mask                               (0x04000000)
#define SYS_CLKEN0_clken_hdmi_pre0_mask                               (0x02000000)
#define SYS_CLKEN0_clken_img_demod_mask                               (0x01000000)
#define SYS_CLKEN0_clken_img_demod_wrap_mask                          (0x00800000)
#define SYS_CLKEN0_clken_hdic_mask                                    (0x00100000)
#define SYS_CLKEN0_clken_dtv_frontend_mask                            (0x00080000)
#define SYS_CLKEN0_clken_kcpu_mask                                    (0x00040000)
#define SYS_CLKEN0_clken_ve2_p2_mask                                  (0x00010000)
#define SYS_CLKEN0_clken_ve2_mask                                     (0x00008000)
#define SYS_CLKEN0_clken_vcpu2_mask                                   (0x00004000)
#define SYS_CLKEN0_dummy18000110_13_mask                              (0x00002000)
#define SYS_CLKEN0_clken_acpu_mask                                    (0x00001000)
#define SYS_CLKEN0_clken_acpu2_mask                                   (0x00000800)
#define SYS_CLKEN0_clken_ve_lgcy_p2_mask                              (0x00000080)
#define SYS_CLKEN0_clken_ve_lgcy_mask                                 (0x00000040)
#define SYS_CLKEN0_clken_ve_p2_mask                                   (0x00000020)
#define SYS_CLKEN0_clken_ve_mask                                      (0x00000010)
#define SYS_CLKEN0_clken_vcpu_mask                                    (0x00000008)
#define SYS_CLKEN0_clken_scpu_wrap_mask                               (0x00000004)
#define SYS_CLKEN0_clken_scpu_mask                                    (0x00000002)
#define SYS_CLKEN0_write_data_mask                                    (0x00000001)
#define SYS_CLKEN0_clken_diseqc(data)                                 (0x80000000&((data)<<31))
#define SYS_CLKEN0_clken_cablerx(data)                                (0x40000000&((data)<<30))
#define SYS_CLKEN0_clken_hdmi_common(data)                            (0x20000000&((data)<<29))
#define SYS_CLKEN0_clken_hdmi_pre3(data)                              (0x10000000&((data)<<28))
#define SYS_CLKEN0_clken_hdmi_pre2(data)                              (0x08000000&((data)<<27))
#define SYS_CLKEN0_clken_hdmi_pre1(data)                              (0x04000000&((data)<<26))
#define SYS_CLKEN0_clken_hdmi_pre0(data)                              (0x02000000&((data)<<25))
#define SYS_CLKEN0_clken_img_demod(data)                              (0x01000000&((data)<<24))
#define SYS_CLKEN0_clken_img_demod_wrap(data)                         (0x00800000&((data)<<23))
#define SYS_CLKEN0_clken_hdic(data)                                   (0x00100000&((data)<<20))
#define SYS_CLKEN0_clken_dtv_frontend(data)                           (0x00080000&((data)<<19))
#define SYS_CLKEN0_clken_kcpu(data)                                   (0x00040000&((data)<<18))
#define SYS_CLKEN0_clken_ve2_p2(data)                                 (0x00010000&((data)<<16))
#define SYS_CLKEN0_clken_ve2(data)                                    (0x00008000&((data)<<15))
#define SYS_CLKEN0_clken_vcpu2(data)                                  (0x00004000&((data)<<14))
#define SYS_CLKEN0_dummy18000110_13(data)                             (0x00002000&((data)<<13))
#define SYS_CLKEN0_clken_acpu(data)                                   (0x00001000&((data)<<12))
#define SYS_CLKEN0_clken_acpu2(data)                                  (0x00000800&((data)<<11))
#define SYS_CLKEN0_clken_ve_lgcy_p2(data)                             (0x00000080&((data)<<7))
#define SYS_CLKEN0_clken_ve_lgcy(data)                                (0x00000040&((data)<<6))
#define SYS_CLKEN0_clken_ve_p2(data)                                  (0x00000020&((data)<<5))
#define SYS_CLKEN0_clken_ve(data)                                     (0x00000010&((data)<<4))
#define SYS_CLKEN0_clken_vcpu(data)                                   (0x00000008&((data)<<3))
#define SYS_CLKEN0_clken_scpu_wrap(data)                              (0x00000004&((data)<<2))
#define SYS_CLKEN0_clken_scpu(data)                                   (0x00000002&((data)<<1))
#define SYS_CLKEN0_write_data(data)                                   (0x00000001&(data))
#define SYS_CLKEN0_get_clken_diseqc(data)                             ((0x80000000&(data))>>31)
#define SYS_CLKEN0_get_clken_cablerx(data)                            ((0x40000000&(data))>>30)
#define SYS_CLKEN0_get_clken_hdmi_common(data)                        ((0x20000000&(data))>>29)
#define SYS_CLKEN0_get_clken_hdmi_pre3(data)                          ((0x10000000&(data))>>28)
#define SYS_CLKEN0_get_clken_hdmi_pre2(data)                          ((0x08000000&(data))>>27)
#define SYS_CLKEN0_get_clken_hdmi_pre1(data)                          ((0x04000000&(data))>>26)
#define SYS_CLKEN0_get_clken_hdmi_pre0(data)                          ((0x02000000&(data))>>25)
#define SYS_CLKEN0_get_clken_img_demod(data)                          ((0x01000000&(data))>>24)
#define SYS_CLKEN0_get_clken_img_demod_wrap(data)                     ((0x00800000&(data))>>23)
#define SYS_CLKEN0_get_clken_hdic(data)                               ((0x00100000&(data))>>20)
#define SYS_CLKEN0_get_clken_dtv_frontend(data)                       ((0x00080000&(data))>>19)
#define SYS_CLKEN0_get_clken_kcpu(data)                               ((0x00040000&(data))>>18)
#define SYS_CLKEN0_get_clken_ve2_p2(data)                             ((0x00010000&(data))>>16)
#define SYS_CLKEN0_get_clken_ve2(data)                                ((0x00008000&(data))>>15)
#define SYS_CLKEN0_get_clken_vcpu2(data)                              ((0x00004000&(data))>>14)
#define SYS_CLKEN0_get_dummy18000110_13(data)                         ((0x00002000&(data))>>13)
#define SYS_CLKEN0_get_clken_acpu(data)                               ((0x00001000&(data))>>12)
#define SYS_CLKEN0_get_clken_acpu2(data)                              ((0x00000800&(data))>>11)
#define SYS_CLKEN0_get_clken_ve_lgcy_p2(data)                         ((0x00000080&(data))>>7)
#define SYS_CLKEN0_get_clken_ve_lgcy(data)                            ((0x00000040&(data))>>6)
#define SYS_CLKEN0_get_clken_ve_p2(data)                              ((0x00000020&(data))>>5)
#define SYS_CLKEN0_get_clken_ve(data)                                 ((0x00000010&(data))>>4)
#define SYS_CLKEN0_get_clken_vcpu(data)                               ((0x00000008&(data))>>3)
#define SYS_CLKEN0_get_clken_scpu_wrap(data)                          ((0x00000004&(data))>>2)
#define SYS_CLKEN0_get_clken_scpu(data)                               ((0x00000002&(data))>>1)
#define SYS_CLKEN0_get_write_data(data)                               (0x00000001&(data))


#define SYS_CLKEN1                                                    0x18000114
#define SYS_CLKEN1_reg_addr                                           "0xb8000114"
#define SYS_CLKEN1_reg                                                0xb8000114
#define SYS_CLKEN1_inst_addr                                          "0x0045"
#define SYS_CLKEN1_inst                                               0x0045
#define set_SYS_CLKEN1_reg(data)                                      (*((volatile unsigned int*)SYS_CLKEN1_reg)=data)
#define get_SYS_CLKEN1_reg                                            (*((volatile unsigned int*)SYS_CLKEN1_reg))
#define SYS_CLKEN1_clken_tvsb1_shift                                  (31)
#define SYS_CLKEN1_clken_tvsb2_shift                                  (30)
#define SYS_CLKEN1_clken_tvsb3_shift                                  (29)
#define SYS_CLKEN1_clken_tvsb4_shift                                  (28)
#define SYS_CLKEN1_clken_tvsb5_shift                                  (27)
#define SYS_CLKEN1_clken_tve_shift                                    (26)
#define SYS_CLKEN1_clken_dcphy_shift                                  (25)
#define SYS_CLKEN1_clken_dcu_shift                                    (24)
#define SYS_CLKEN1_clken_if_demod_shift                               (23)
#define SYS_CLKEN1_clken_vdec_shift                                   (22)
#define SYS_CLKEN1_clken_se2_shift                                    (21)
#define SYS_CLKEN1_clken_vbis0_shift                                  (20)
#define SYS_CLKEN1_clken_dolby_comp_shift                             (19)
#define SYS_CLKEN1_clken_dolby_dm_shift                               (18)
#define SYS_CLKEN1_clken_audio_pre512fs_shift                         (17)
#define SYS_CLKEN1_clken_audio_shift                                  (16)
#define SYS_CLKEN1_clken_ifadc_shift                                  (15)
#define SYS_CLKEN1_clken_cbus_shift                                   (14)
#define SYS_CLKEN1_clken_offms_shift                                  (13)
#define SYS_CLKEN1_clken_me_shift                                     (12)
#define SYS_CLKEN1_clken_apll_adc_shift                               (11)
#define SYS_CLKEN1_clken_hdmi_shift                                   (10)
#define SYS_CLKEN1_clken_dispd_shift                                  (9)
#define SYS_CLKEN1_clken_tp_shift                                     (8)
#define SYS_CLKEN1_clken_cp_shift                                     (7)
#define SYS_CLKEN1_clken_md_shift                                     (6)
#define SYS_CLKEN1_clken_se_shift                                     (5)
#define SYS_CLKEN1_clken_tp_div_shift                                 (4)
#define SYS_CLKEN1_clken_3d_gde_shift                                 (3)
#define SYS_CLKEN1_clken_vodma_shift                                  (2)
#define SYS_CLKEN1_clken_dispi_shift                                  (1)
#define SYS_CLKEN1_write_data_shift                                   (0)
#define SYS_CLKEN1_clken_tvsb1_mask                                   (0x80000000)
#define SYS_CLKEN1_clken_tvsb2_mask                                   (0x40000000)
#define SYS_CLKEN1_clken_tvsb3_mask                                   (0x20000000)
#define SYS_CLKEN1_clken_tvsb4_mask                                   (0x10000000)
#define SYS_CLKEN1_clken_tvsb5_mask                                   (0x08000000)
#define SYS_CLKEN1_clken_tve_mask                                     (0x04000000)
#define SYS_CLKEN1_clken_dcphy_mask                                   (0x02000000)
#define SYS_CLKEN1_clken_dcu_mask                                     (0x01000000)
#define SYS_CLKEN1_clken_if_demod_mask                                (0x00800000)
#define SYS_CLKEN1_clken_vdec_mask                                    (0x00400000)
#define SYS_CLKEN1_clken_se2_mask                                     (0x00200000)
#define SYS_CLKEN1_clken_vbis0_mask                                   (0x00100000)
#define SYS_CLKEN1_clken_dolby_comp_mask                              (0x00080000)
#define SYS_CLKEN1_clken_dolby_dm_mask                                (0x00040000)
#define SYS_CLKEN1_clken_audio_pre512fs_mask                          (0x00020000)
#define SYS_CLKEN1_clken_audio_mask                                   (0x00010000)
#define SYS_CLKEN1_clken_ifadc_mask                                   (0x00008000)
#define SYS_CLKEN1_clken_cbus_mask                                    (0x00004000)
#define SYS_CLKEN1_clken_offms_mask                                   (0x00002000)
#define SYS_CLKEN1_clken_me_mask                                      (0x00001000)
#define SYS_CLKEN1_clken_apll_adc_mask                                (0x00000800)
#define SYS_CLKEN1_clken_hdmi_mask                                    (0x00000400)
#define SYS_CLKEN1_clken_dispd_mask                                   (0x00000200)
#define SYS_CLKEN1_clken_tp_mask                                      (0x00000100)
#define SYS_CLKEN1_clken_cp_mask                                      (0x00000080)
#define SYS_CLKEN1_clken_md_mask                                      (0x00000040)
#define SYS_CLKEN1_clken_se_mask                                      (0x00000020)
#define SYS_CLKEN1_clken_tp_div_mask                                  (0x00000010)
#define SYS_CLKEN1_clken_3d_gde_mask                                  (0x00000008)
#define SYS_CLKEN1_clken_vodma_mask                                   (0x00000004)
#define SYS_CLKEN1_clken_dispi_mask                                   (0x00000002)
#define SYS_CLKEN1_write_data_mask                                    (0x00000001)
#define SYS_CLKEN1_clken_tvsb1(data)                                  (0x80000000&((data)<<31))
#define SYS_CLKEN1_clken_tvsb2(data)                                  (0x40000000&((data)<<30))
#define SYS_CLKEN1_clken_tvsb3(data)                                  (0x20000000&((data)<<29))
#define SYS_CLKEN1_clken_tvsb4(data)                                  (0x10000000&((data)<<28))
#define SYS_CLKEN1_clken_tvsb5(data)                                  (0x08000000&((data)<<27))
#define SYS_CLKEN1_clken_tve(data)                                    (0x04000000&((data)<<26))
#define SYS_CLKEN1_clken_dcphy(data)                                  (0x02000000&((data)<<25))
#define SYS_CLKEN1_clken_dcu(data)                                    (0x01000000&((data)<<24))
#define SYS_CLKEN1_clken_if_demod(data)                               (0x00800000&((data)<<23))
#define SYS_CLKEN1_clken_vdec(data)                                   (0x00400000&((data)<<22))
#define SYS_CLKEN1_clken_se2(data)                                    (0x00200000&((data)<<21))
#define SYS_CLKEN1_clken_vbis0(data)                                  (0x00100000&((data)<<20))
#define SYS_CLKEN1_clken_dolby_comp(data)                             (0x00080000&((data)<<19))
#define SYS_CLKEN1_clken_dolby_dm(data)                               (0x00040000&((data)<<18))
#define SYS_CLKEN1_clken_audio_pre512fs(data)                         (0x00020000&((data)<<17))
#define SYS_CLKEN1_clken_audio(data)                                  (0x00010000&((data)<<16))
#define SYS_CLKEN1_clken_ifadc(data)                                  (0x00008000&((data)<<15))
#define SYS_CLKEN1_clken_cbus(data)                                   (0x00004000&((data)<<14))
#define SYS_CLKEN1_clken_offms(data)                                  (0x00002000&((data)<<13))
#define SYS_CLKEN1_clken_me(data)                                     (0x00001000&((data)<<12))
#define SYS_CLKEN1_clken_apll_adc(data)                               (0x00000800&((data)<<11))
#define SYS_CLKEN1_clken_hdmi(data)                                   (0x00000400&((data)<<10))
#define SYS_CLKEN1_clken_dispd(data)                                  (0x00000200&((data)<<9))
#define SYS_CLKEN1_clken_tp(data)                                     (0x00000100&((data)<<8))
#define SYS_CLKEN1_clken_cp(data)                                     (0x00000080&((data)<<7))
#define SYS_CLKEN1_clken_md(data)                                     (0x00000040&((data)<<6))
#define SYS_CLKEN1_clken_se(data)                                     (0x00000020&((data)<<5))
#define SYS_CLKEN1_clken_tp_div(data)                                 (0x00000010&((data)<<4))
#define SYS_CLKEN1_clken_3d_gde(data)                                 (0x00000008&((data)<<3))
#define SYS_CLKEN1_clken_vodma(data)                                  (0x00000004&((data)<<2))
#define SYS_CLKEN1_clken_dispi(data)                                  (0x00000002&((data)<<1))
#define SYS_CLKEN1_write_data(data)                                   (0x00000001&(data))
#define SYS_CLKEN1_get_clken_tvsb1(data)                              ((0x80000000&(data))>>31)
#define SYS_CLKEN1_get_clken_tvsb2(data)                              ((0x40000000&(data))>>30)
#define SYS_CLKEN1_get_clken_tvsb3(data)                              ((0x20000000&(data))>>29)
#define SYS_CLKEN1_get_clken_tvsb4(data)                              ((0x10000000&(data))>>28)
#define SYS_CLKEN1_get_clken_tvsb5(data)                              ((0x08000000&(data))>>27)
#define SYS_CLKEN1_get_clken_tve(data)                                ((0x04000000&(data))>>26)
#define SYS_CLKEN1_get_clken_dcphy(data)                              ((0x02000000&(data))>>25)
#define SYS_CLKEN1_get_clken_dcu(data)                                ((0x01000000&(data))>>24)
#define SYS_CLKEN1_get_clken_if_demod(data)                           ((0x00800000&(data))>>23)
#define SYS_CLKEN1_get_clken_vdec(data)                               ((0x00400000&(data))>>22)
#define SYS_CLKEN1_get_clken_se2(data)                                ((0x00200000&(data))>>21)
#define SYS_CLKEN1_get_clken_vbis0(data)                              ((0x00100000&(data))>>20)
#define SYS_CLKEN1_get_clken_dolby_comp(data)                         ((0x00080000&(data))>>19)
#define SYS_CLKEN1_get_clken_dolby_dm(data)                           ((0x00040000&(data))>>18)
#define SYS_CLKEN1_get_clken_audio_pre512fs(data)                     ((0x00020000&(data))>>17)
#define SYS_CLKEN1_get_clken_audio(data)                              ((0x00010000&(data))>>16)
#define SYS_CLKEN1_get_clken_ifadc(data)                              ((0x00008000&(data))>>15)
#define SYS_CLKEN1_get_clken_cbus(data)                               ((0x00004000&(data))>>14)
#define SYS_CLKEN1_get_clken_offms(data)                              ((0x00002000&(data))>>13)
#define SYS_CLKEN1_get_clken_me(data)                                 ((0x00001000&(data))>>12)
#define SYS_CLKEN1_get_clken_apll_adc(data)                           ((0x00000800&(data))>>11)
#define SYS_CLKEN1_get_clken_hdmi(data)                               ((0x00000400&(data))>>10)
#define SYS_CLKEN1_get_clken_dispd(data)                              ((0x00000200&(data))>>9)
#define SYS_CLKEN1_get_clken_tp(data)                                 ((0x00000100&(data))>>8)
#define SYS_CLKEN1_get_clken_cp(data)                                 ((0x00000080&(data))>>7)
#define SYS_CLKEN1_get_clken_md(data)                                 ((0x00000040&(data))>>6)
#define SYS_CLKEN1_get_clken_se(data)                                 ((0x00000020&(data))>>5)
#define SYS_CLKEN1_get_clken_tp_div(data)                             ((0x00000010&(data))>>4)
#define SYS_CLKEN1_get_clken_3d_gde(data)                             ((0x00000008&(data))>>3)
#define SYS_CLKEN1_get_clken_vodma(data)                              ((0x00000004&(data))>>2)
#define SYS_CLKEN1_get_clken_dispi(data)                              ((0x00000002&(data))>>1)
#define SYS_CLKEN1_get_write_data(data)                               (0x00000001&(data))


#define SYS_CLKEN2                                                    0x18000118
#define SYS_CLKEN2_reg_addr                                           "0xb8000118"
#define SYS_CLKEN2_reg                                                0xb8000118
#define SYS_CLKEN2_inst_addr                                          "0x0046"
#define SYS_CLKEN2_inst                                               0x0046
#define set_SYS_CLKEN2_reg(data)                                      (*((volatile unsigned int*)SYS_CLKEN2_reg)=data)
#define get_SYS_CLKEN2_reg                                            (*((volatile unsigned int*)SYS_CLKEN2_reg))
#define SYS_CLKEN2_clken_usb2_ex_shift                                (29)
#define SYS_CLKEN2_clken_tm_shift                                     (28)
#define SYS_CLKEN2_clken_atvin_vd_shift                               (27)
#define SYS_CLKEN2_clken_atvin_ifd_shift                              (26)
#define SYS_CLKEN2_clken_dispm_cap_shift                              (25)
#define SYS_CLKEN2_clken_dispm_disp_shift                             (24)
#define SYS_CLKEN2_clken_emmc_shift                                   (23)
#define SYS_CLKEN2_clken_efuse_shift                                  (22)
#define SYS_CLKEN2_clken_bistreg_shift                                (21)
#define SYS_CLKEN2_clken_i2c4_shift                                   (20)
#define SYS_CLKEN2_clken_pllreg_shift                                 (19)
#define SYS_CLKEN2_clken_usb3_shift                                   (18)
#define SYS_CLKEN2_clken_usb2_shift                                   (17)
#define SYS_CLKEN2_clken_pcmcia_shift                                 (16)
#define SYS_CLKEN2_clken_audio2_512fs_shift                           (15)
#define SYS_CLKEN2_clken_i2c3_shift                                   (14)
#define SYS_CLKEN2_clken_irtx_shift                                   (13)
#define SYS_CLKEN2_dummy18000118_12_shift                             (12)
#define SYS_CLKEN2_clken_dtv_demod_shift                              (11)
#define SYS_CLKEN2_clken_misc_shift                                   (10)
#define SYS_CLKEN2_clken_pwm_shift                                    (9)
#define SYS_CLKEN2_clken_uart1_shift                                  (8)
#define SYS_CLKEN2_clken_uart2_shift                                  (7)
#define SYS_CLKEN2_dummy18000118_6_shift                              (6)
#define SYS_CLKEN2_clken_gpio_shift                                   (5)
#define SYS_CLKEN2_clken_i2c1_shift                                   (4)
#define SYS_CLKEN2_clken_i2c2_shift                                   (3)
#define SYS_CLKEN2_clken_nf_shift                                     (2)
#define SYS_CLKEN2_clken_sc_shift                                     (1)
#define SYS_CLKEN2_write_data_shift                                   (0)
#define SYS_CLKEN2_clken_usb2_ex_mask                                 (0x20000000)
#define SYS_CLKEN2_clken_tm_mask                                      (0x10000000)
#define SYS_CLKEN2_clken_atvin_vd_mask                                (0x08000000)
#define SYS_CLKEN2_clken_atvin_ifd_mask                               (0x04000000)
#define SYS_CLKEN2_clken_dispm_cap_mask                               (0x02000000)
#define SYS_CLKEN2_clken_dispm_disp_mask                              (0x01000000)
#define SYS_CLKEN2_clken_emmc_mask                                    (0x00800000)
#define SYS_CLKEN2_clken_efuse_mask                                   (0x00400000)
#define SYS_CLKEN2_clken_bistreg_mask                                 (0x00200000)
#define SYS_CLKEN2_clken_i2c4_mask                                    (0x00100000)
#define SYS_CLKEN2_clken_pllreg_mask                                  (0x00080000)
#define SYS_CLKEN2_clken_usb3_mask                                    (0x00040000)
#define SYS_CLKEN2_clken_usb2_mask                                    (0x00020000)
#define SYS_CLKEN2_clken_pcmcia_mask                                  (0x00010000)
#define SYS_CLKEN2_clken_audio2_512fs_mask                            (0x00008000)
#define SYS_CLKEN2_clken_i2c3_mask                                    (0x00004000)
#define SYS_CLKEN2_clken_irtx_mask                                    (0x00002000)
#define SYS_CLKEN2_dummy18000118_12_mask                              (0x00001000)
#define SYS_CLKEN2_clken_dtv_demod_mask                               (0x00000800)
#define SYS_CLKEN2_clken_misc_mask                                    (0x00000400)
#define SYS_CLKEN2_clken_pwm_mask                                     (0x00000200)
#define SYS_CLKEN2_clken_uart1_mask                                   (0x00000100)
#define SYS_CLKEN2_clken_uart2_mask                                   (0x00000080)
#define SYS_CLKEN2_dummy18000118_6_mask                               (0x00000040)
#define SYS_CLKEN2_clken_gpio_mask                                    (0x00000020)
#define SYS_CLKEN2_clken_i2c1_mask                                    (0x00000010)
#define SYS_CLKEN2_clken_i2c2_mask                                    (0x00000008)
#define SYS_CLKEN2_clken_nf_mask                                      (0x00000004)
#define SYS_CLKEN2_clken_sc_mask                                      (0x00000002)
#define SYS_CLKEN2_write_data_mask                                    (0x00000001)
#define SYS_CLKEN2_clken_usb2_ex(data)                                (0x20000000&((data)<<29))
#define SYS_CLKEN2_clken_tm(data)                                     (0x10000000&((data)<<28))
#define SYS_CLKEN2_clken_atvin_vd(data)                               (0x08000000&((data)<<27))
#define SYS_CLKEN2_clken_atvin_ifd(data)                              (0x04000000&((data)<<26))
#define SYS_CLKEN2_clken_dispm_cap(data)                              (0x02000000&((data)<<25))
#define SYS_CLKEN2_clken_dispm_disp(data)                             (0x01000000&((data)<<24))
#define SYS_CLKEN2_clken_emmc(data)                                   (0x00800000&((data)<<23))
#define SYS_CLKEN2_clken_efuse(data)                                  (0x00400000&((data)<<22))
#define SYS_CLKEN2_clken_bistreg(data)                                (0x00200000&((data)<<21))
#define SYS_CLKEN2_clken_i2c4(data)                                   (0x00100000&((data)<<20))
#define SYS_CLKEN2_clken_pllreg(data)                                 (0x00080000&((data)<<19))
#define SYS_CLKEN2_clken_usb3(data)                                   (0x00040000&((data)<<18))
#define SYS_CLKEN2_clken_usb2(data)                                   (0x00020000&((data)<<17))
#define SYS_CLKEN2_clken_pcmcia(data)                                 (0x00010000&((data)<<16))
#define SYS_CLKEN2_clken_audio2_512fs(data)                           (0x00008000&((data)<<15))
#define SYS_CLKEN2_clken_i2c3(data)                                   (0x00004000&((data)<<14))
#define SYS_CLKEN2_clken_irtx(data)                                   (0x00002000&((data)<<13))
#define SYS_CLKEN2_dummy18000118_12(data)                             (0x00001000&((data)<<12))
#define SYS_CLKEN2_clken_dtv_demod(data)                              (0x00000800&((data)<<11))
#define SYS_CLKEN2_clken_misc(data)                                   (0x00000400&((data)<<10))
#define SYS_CLKEN2_clken_pwm(data)                                    (0x00000200&((data)<<9))
#define SYS_CLKEN2_clken_uart1(data)                                  (0x00000100&((data)<<8))
#define SYS_CLKEN2_clken_uart2(data)                                  (0x00000080&((data)<<7))
#define SYS_CLKEN2_dummy18000118_6(data)                              (0x00000040&((data)<<6))
#define SYS_CLKEN2_clken_gpio(data)                                   (0x00000020&((data)<<5))
#define SYS_CLKEN2_clken_i2c1(data)                                   (0x00000010&((data)<<4))
#define SYS_CLKEN2_clken_i2c2(data)                                   (0x00000008&((data)<<3))
#define SYS_CLKEN2_clken_nf(data)                                     (0x00000004&((data)<<2))
#define SYS_CLKEN2_clken_sc(data)                                     (0x00000002&((data)<<1))
#define SYS_CLKEN2_write_data(data)                                   (0x00000001&(data))
#define SYS_CLKEN2_get_clken_usb2_ex(data)                            ((0x20000000&(data))>>29)
#define SYS_CLKEN2_get_clken_tm(data)                                 ((0x10000000&(data))>>28)
#define SYS_CLKEN2_get_clken_atvin_vd(data)                           ((0x08000000&(data))>>27)
#define SYS_CLKEN2_get_clken_atvin_ifd(data)                          ((0x04000000&(data))>>26)
#define SYS_CLKEN2_get_clken_dispm_cap(data)                          ((0x02000000&(data))>>25)
#define SYS_CLKEN2_get_clken_dispm_disp(data)                         ((0x01000000&(data))>>24)
#define SYS_CLKEN2_get_clken_emmc(data)                               ((0x00800000&(data))>>23)
#define SYS_CLKEN2_get_clken_efuse(data)                              ((0x00400000&(data))>>22)
#define SYS_CLKEN2_get_clken_bistreg(data)                            ((0x00200000&(data))>>21)
#define SYS_CLKEN2_get_clken_i2c4(data)                               ((0x00100000&(data))>>20)
#define SYS_CLKEN2_get_clken_pllreg(data)                             ((0x00080000&(data))>>19)
#define SYS_CLKEN2_get_clken_usb3(data)                               ((0x00040000&(data))>>18)
#define SYS_CLKEN2_get_clken_usb2(data)                               ((0x00020000&(data))>>17)
#define SYS_CLKEN2_get_clken_pcmcia(data)                             ((0x00010000&(data))>>16)
#define SYS_CLKEN2_get_clken_audio2_512fs(data)                       ((0x00008000&(data))>>15)
#define SYS_CLKEN2_get_clken_i2c3(data)                               ((0x00004000&(data))>>14)
#define SYS_CLKEN2_get_clken_irtx(data)                               ((0x00002000&(data))>>13)
#define SYS_CLKEN2_get_dummy18000118_12(data)                         ((0x00001000&(data))>>12)
#define SYS_CLKEN2_get_clken_dtv_demod(data)                          ((0x00000800&(data))>>11)
#define SYS_CLKEN2_get_clken_misc(data)                               ((0x00000400&(data))>>10)
#define SYS_CLKEN2_get_clken_pwm(data)                                ((0x00000200&(data))>>9)
#define SYS_CLKEN2_get_clken_uart1(data)                              ((0x00000100&(data))>>8)
#define SYS_CLKEN2_get_clken_uart2(data)                              ((0x00000080&(data))>>7)
#define SYS_CLKEN2_get_dummy18000118_6(data)                          ((0x00000040&(data))>>6)
#define SYS_CLKEN2_get_clken_gpio(data)                               ((0x00000020&(data))>>5)
#define SYS_CLKEN2_get_clken_i2c1(data)                               ((0x00000010&(data))>>4)
#define SYS_CLKEN2_get_clken_i2c2(data)                               ((0x00000008&(data))>>3)
#define SYS_CLKEN2_get_clken_nf(data)                                 ((0x00000004&(data))>>2)
#define SYS_CLKEN2_get_clken_sc(data)                                 ((0x00000002&(data))>>1)
#define SYS_CLKEN2_get_write_data(data)                               (0x00000001&(data))


#define SYS_CLKEN3                                                    0x1800011c
#define SYS_CLKEN3_reg_addr                                           "0xb800011c"
#define SYS_CLKEN3_reg                                                0xb800011c
#define SYS_CLKEN3_inst_addr                                          "0x0047"
#define SYS_CLKEN3_inst                                               0x0047
#define set_SYS_CLKEN3_reg(data)                                      (*((volatile unsigned int*)SYS_CLKEN3_reg)=data)
#define get_SYS_CLKEN3_reg                                            (*((volatile unsigned int*)SYS_CLKEN3_reg))
#define SYS_CLKEN3_clken_memc_shift                                   (31)
#define SYS_CLKEN3_clken_memc_me_shift                                (30)
#define SYS_CLKEN3_clken_memc_rbus_shift                              (29)
#define SYS_CLKEN3_clken_dcphy_mc_mck_shift                           (26)
#define SYS_CLKEN3_clken_dcphy2_shift                                 (25)
#define SYS_CLKEN3_clken_dcu2_shift                                   (24)
#define SYS_CLKEN3_clken_dcphy_mc_shift                               (23)
#define SYS_CLKEN3_clken_disp_lg_hcic_shift                           (22)
#define SYS_CLKEN3_clken_disp_lg_mplus_shift                          (21)
#define SYS_CLKEN3_clken_d_boe_rgbw_pxl_shift                         (20)
#define SYS_CLKEN3_clken_d_boe_rgbw_apb_shift                         (19)
#define SYS_CLKEN3_clken_d_boe_rgbw_mcu_shift                         (18)
#define SYS_CLKEN3_clken_ddc_shift                                    (17)
#define SYS_CLKEN3_clken_sd_shift                                     (16)
#define SYS_CLKEN3_clken_dss_shift                                    (15)
#define SYS_CLKEN3_clken_audio_ad_128fs_shift                         (9)
#define SYS_CLKEN3_clken_audio_arc_dma_r_512fs_shift                  (8)
#define SYS_CLKEN3_clken_audio2_dma_r_512fs_shift                     (7)
#define SYS_CLKEN3_clken_audio_dma_r_512fs_shift                      (6)
#define SYS_CLKEN3_clken_audio_da1_256fs_shift                        (5)
#define SYS_CLKEN3_clken_audio_da1_128fs_shift                        (4)
#define SYS_CLKEN3_clken_audio_da0_256fs_shift                        (3)
#define SYS_CLKEN3_clken_audio_da0_128fs_shift                        (2)
#define SYS_CLKEN3_clken_audio_ad_256fs_shift                         (1)
#define SYS_CLKEN3_write_data_shift                                   (0)
#define SYS_CLKEN3_clken_memc_mask                                    (0x80000000)
#define SYS_CLKEN3_clken_memc_me_mask                                 (0x40000000)
#define SYS_CLKEN3_clken_memc_rbus_mask                               (0x20000000)
#define SYS_CLKEN3_clken_dcphy_mc_mck_mask                            (0x04000000)
#define SYS_CLKEN3_clken_dcphy2_mask                                  (0x02000000)
#define SYS_CLKEN3_clken_dcu2_mask                                    (0x01000000)
#define SYS_CLKEN3_clken_dcphy_mc_mask                                (0x00800000)
#define SYS_CLKEN3_clken_disp_lg_hcic_mask                            (0x00400000)
#define SYS_CLKEN3_clken_disp_lg_mplus_mask                           (0x00200000)
#define SYS_CLKEN3_clken_d_boe_rgbw_pxl_mask                          (0x00100000)
#define SYS_CLKEN3_clken_d_boe_rgbw_apb_mask                          (0x00080000)
#define SYS_CLKEN3_clken_d_boe_rgbw_mcu_mask                          (0x00040000)
#define SYS_CLKEN3_clken_ddc_mask                                     (0x00020000)
#define SYS_CLKEN3_clken_sd_mask                                      (0x00010000)
#define SYS_CLKEN3_clken_dss_mask                                     (0x00008000)
#define SYS_CLKEN3_clken_audio_ad_128fs_mask                          (0x00000200)
#define SYS_CLKEN3_clken_audio_arc_dma_r_512fs_mask                   (0x00000100)
#define SYS_CLKEN3_clken_audio2_dma_r_512fs_mask                      (0x00000080)
#define SYS_CLKEN3_clken_audio_dma_r_512fs_mask                       (0x00000040)
#define SYS_CLKEN3_clken_audio_da1_256fs_mask                         (0x00000020)
#define SYS_CLKEN3_clken_audio_da1_128fs_mask                         (0x00000010)
#define SYS_CLKEN3_clken_audio_da0_256fs_mask                         (0x00000008)
#define SYS_CLKEN3_clken_audio_da0_128fs_mask                         (0x00000004)
#define SYS_CLKEN3_clken_audio_ad_256fs_mask                          (0x00000002)
#define SYS_CLKEN3_write_data_mask                                    (0x00000001)
#define SYS_CLKEN3_clken_memc(data)                                   (0x80000000&((data)<<31))
#define SYS_CLKEN3_clken_memc_me(data)                                (0x40000000&((data)<<30))
#define SYS_CLKEN3_clken_memc_rbus(data)                              (0x20000000&((data)<<29))
#define SYS_CLKEN3_clken_dcphy_mc_mck(data)                           (0x04000000&((data)<<26))
#define SYS_CLKEN3_clken_dcphy2(data)                                 (0x02000000&((data)<<25))
#define SYS_CLKEN3_clken_dcu2(data)                                   (0x01000000&((data)<<24))
#define SYS_CLKEN3_clken_dcphy_mc(data)                               (0x00800000&((data)<<23))
#define SYS_CLKEN3_clken_disp_lg_hcic(data)                           (0x00400000&((data)<<22))
#define SYS_CLKEN3_clken_disp_lg_mplus(data)                          (0x00200000&((data)<<21))
#define SYS_CLKEN3_clken_d_boe_rgbw_pxl(data)                         (0x00100000&((data)<<20))
#define SYS_CLKEN3_clken_d_boe_rgbw_apb(data)                         (0x00080000&((data)<<19))
#define SYS_CLKEN3_clken_d_boe_rgbw_mcu(data)                         (0x00040000&((data)<<18))
#define SYS_CLKEN3_clken_ddc(data)                                    (0x00020000&((data)<<17))
#define SYS_CLKEN3_clken_sd(data)                                     (0x00010000&((data)<<16))
#define SYS_CLKEN3_clken_dss(data)                                    (0x00008000&((data)<<15))
#define SYS_CLKEN3_clken_audio_ad_128fs(data)                         (0x00000200&((data)<<9))
#define SYS_CLKEN3_clken_audio_arc_dma_r_512fs(data)                  (0x00000100&((data)<<8))
#define SYS_CLKEN3_clken_audio2_dma_r_512fs(data)                     (0x00000080&((data)<<7))
#define SYS_CLKEN3_clken_audio_dma_r_512fs(data)                      (0x00000040&((data)<<6))
#define SYS_CLKEN3_clken_audio_da1_256fs(data)                        (0x00000020&((data)<<5))
#define SYS_CLKEN3_clken_audio_da1_128fs(data)                        (0x00000010&((data)<<4))
#define SYS_CLKEN3_clken_audio_da0_256fs(data)                        (0x00000008&((data)<<3))
#define SYS_CLKEN3_clken_audio_da0_128fs(data)                        (0x00000004&((data)<<2))
#define SYS_CLKEN3_clken_audio_ad_256fs(data)                         (0x00000002&((data)<<1))
#define SYS_CLKEN3_write_data(data)                                   (0x00000001&(data))
#define SYS_CLKEN3_get_clken_memc(data)                               ((0x80000000&(data))>>31)
#define SYS_CLKEN3_get_clken_memc_me(data)                            ((0x40000000&(data))>>30)
#define SYS_CLKEN3_get_clken_memc_rbus(data)                          ((0x20000000&(data))>>29)
#define SYS_CLKEN3_get_clken_dcphy_mc_mck(data)                       ((0x04000000&(data))>>26)
#define SYS_CLKEN3_get_clken_dcphy2(data)                             ((0x02000000&(data))>>25)
#define SYS_CLKEN3_get_clken_dcu2(data)                               ((0x01000000&(data))>>24)
#define SYS_CLKEN3_get_clken_dcphy_mc(data)                           ((0x00800000&(data))>>23)
#define SYS_CLKEN3_get_clken_disp_lg_hcic(data)                       ((0x00400000&(data))>>22)
#define SYS_CLKEN3_get_clken_disp_lg_mplus(data)                      ((0x00200000&(data))>>21)
#define SYS_CLKEN3_get_clken_d_boe_rgbw_pxl(data)                     ((0x00100000&(data))>>20)
#define SYS_CLKEN3_get_clken_d_boe_rgbw_apb(data)                     ((0x00080000&(data))>>19)
#define SYS_CLKEN3_get_clken_d_boe_rgbw_mcu(data)                     ((0x00040000&(data))>>18)
#define SYS_CLKEN3_get_clken_ddc(data)                                ((0x00020000&(data))>>17)
#define SYS_CLKEN3_get_clken_sd(data)                                 ((0x00010000&(data))>>16)
#define SYS_CLKEN3_get_clken_dss(data)                                ((0x00008000&(data))>>15)
#define SYS_CLKEN3_get_clken_audio_ad_128fs(data)                     ((0x00000200&(data))>>9)
#define SYS_CLKEN3_get_clken_audio_arc_dma_r_512fs(data)              ((0x00000100&(data))>>8)
#define SYS_CLKEN3_get_clken_audio2_dma_r_512fs(data)                 ((0x00000080&(data))>>7)
#define SYS_CLKEN3_get_clken_audio_dma_r_512fs(data)                  ((0x00000040&(data))>>6)
#define SYS_CLKEN3_get_clken_audio_da1_256fs(data)                    ((0x00000020&(data))>>5)
#define SYS_CLKEN3_get_clken_audio_da1_128fs(data)                    ((0x00000010&(data))>>4)
#define SYS_CLKEN3_get_clken_audio_da0_256fs(data)                    ((0x00000008&(data))>>3)
#define SYS_CLKEN3_get_clken_audio_da0_128fs(data)                    ((0x00000004&(data))>>2)
#define SYS_CLKEN3_get_clken_audio_ad_256fs(data)                     ((0x00000002&(data))>>1)
#define SYS_CLKEN3_get_write_data(data)                               (0x00000001&(data))


#define SYS_CPUSEL                                                    0x18000200
#define SYS_CPUSEL_reg_addr                                           "0xb8000200"
#define SYS_CPUSEL_reg                                                0xb8000200
#define SYS_CPUSEL_inst_addr                                          "0x0080"
#define SYS_CPUSEL_inst                                               0x0080
#define set_SYS_CPUSEL_reg(data)                                      (*((volatile unsigned int*)SYS_CPUSEL_reg)=data)
#define get_SYS_CPUSEL_reg                                            (*((volatile unsigned int*)SYS_CPUSEL_reg))
#define SYS_CPUSEL_ejtag_demod_sel_shift                              (6)
#define SYS_CPUSEL_ejtag_demod_en_shift                               (5)
#define SYS_CPUSEL_ejtag_mode_shift                                   (4)
#define SYS_CPUSEL_kcpu_clksel_shift                                  (0)
#define SYS_CPUSEL_ejtag_demod_sel_mask                               (0x00000040)
#define SYS_CPUSEL_ejtag_demod_en_mask                                (0x00000020)
#define SYS_CPUSEL_ejtag_mode_mask                                    (0x00000010)
#define SYS_CPUSEL_kcpu_clksel_mask                                   (0x00000001)
#define SYS_CPUSEL_ejtag_demod_sel(data)                              (0x00000040&((data)<<6))
#define SYS_CPUSEL_ejtag_demod_en(data)                               (0x00000020&((data)<<5))
#define SYS_CPUSEL_ejtag_mode(data)                                   (0x00000010&((data)<<4))
#define SYS_CPUSEL_kcpu_clksel(data)                                  (0x00000001&(data))
#define SYS_CPUSEL_get_ejtag_demod_sel(data)                          ((0x00000040&(data))>>6)
#define SYS_CPUSEL_get_ejtag_demod_en(data)                           ((0x00000020&(data))>>5)
#define SYS_CPUSEL_get_ejtag_mode(data)                               ((0x00000010&(data))>>4)
#define SYS_CPUSEL_get_kcpu_clksel(data)                              (0x00000001&(data))


#define SYS_CLKSEL                                                    0x18000204
#define SYS_CLKSEL_reg_addr                                           "0xb8000204"
#define SYS_CLKSEL_reg                                                0xb8000204
#define SYS_CLKSEL_inst_addr                                          "0x0081"
#define SYS_CLKSEL_inst                                               0x0081
#define set_SYS_CLKSEL_reg(data)                                      (*((volatile unsigned int*)SYS_CLKSEL_reg)=data)
#define get_SYS_CLKSEL_reg                                            (*((volatile unsigned int*)SYS_CLKSEL_reg))
#define SYS_CLKSEL_pll_bypass_ref_clk_mode_shift                      (31)
#define SYS_CLKSEL_mc_clk_sel_shift                                   (30)
#define SYS_CLKSEL_ve_sel_shift                                       (28)
#define SYS_CLKSEL_sd_emmc_clk_sel_shift                              (27)
#define SYS_CLKSEL_pcr108_clksel_shift                                (26)
#define SYS_CLKSEL_dummy18000204_25_shift                             (25)
#define SYS_CLKSEL_dpll_clksel_shift                                  (23)
#define SYS_CLKSEL_sd_clk_div_shift                                   (20)
#define SYS_CLKSEL_ve_rif_use_p2clk_shift                             (19)
#define SYS_CLKSEL_ve2_rif_use_p2clk_shift                            (18)
#define SYS_CLKSEL_atvin_clk_sel_shift                                (17)
#define SYS_CLKSEL_atvin_vd_clk_sel_shift                             (16)
#define SYS_CLKSEL_atvin_vdadc_tve_clk_sel_shift                      (15)
#define SYS_CLKSEL_tve_108m_clk_sel_shift                             (13)
#define SYS_CLKSEL_cbus_clksel_shift                                  (12)
#define SYS_CLKSEL_tp_post_div_shift                                  (8)
#define SYS_CLKSEL_tp_pre_div_shift                                   (4)
#define SYS_CLKSEL_vdec_x27_clksel_shift                              (3)
#define SYS_CLKSEL_vbis0_yppsel_shift                                 (2)
#define SYS_CLKSEL_inv_vbis0_sel_shift                                (1)
#define SYS_CLKSEL_uart_clksel_shift                                  (0)
#define SYS_CLKSEL_pll_bypass_ref_clk_mode_mask                       (0x80000000)
#define SYS_CLKSEL_mc_clk_sel_mask                                    (0x40000000)
#define SYS_CLKSEL_ve_sel_mask                                        (0x10000000)
#define SYS_CLKSEL_sd_emmc_clk_sel_mask                               (0x08000000)
#define SYS_CLKSEL_pcr108_clksel_mask                                 (0x04000000)
#define SYS_CLKSEL_dummy18000204_25_mask                              (0x02000000)
#define SYS_CLKSEL_dpll_clksel_mask                                   (0x01800000)
#define SYS_CLKSEL_sd_clk_div_mask                                    (0x00700000)
#define SYS_CLKSEL_ve_rif_use_p2clk_mask                              (0x00080000)
#define SYS_CLKSEL_ve2_rif_use_p2clk_mask                             (0x00040000)
#define SYS_CLKSEL_atvin_clk_sel_mask                                 (0x00020000)
#define SYS_CLKSEL_atvin_vd_clk_sel_mask                              (0x00010000)
#define SYS_CLKSEL_atvin_vdadc_tve_clk_sel_mask                       (0x00008000)
#define SYS_CLKSEL_tve_108m_clk_sel_mask                              (0x00002000)
#define SYS_CLKSEL_cbus_clksel_mask                                   (0x00001000)
#define SYS_CLKSEL_tp_post_div_mask                                   (0x00000F00)
#define SYS_CLKSEL_tp_pre_div_mask                                    (0x000000F0)
#define SYS_CLKSEL_vdec_x27_clksel_mask                               (0x00000008)
#define SYS_CLKSEL_vbis0_yppsel_mask                                  (0x00000004)
#define SYS_CLKSEL_inv_vbis0_sel_mask                                 (0x00000002)
#define SYS_CLKSEL_uart_clksel_mask                                   (0x00000001)
#define SYS_CLKSEL_pll_bypass_ref_clk_mode(data)                      (0x80000000&((data)<<31))
#define SYS_CLKSEL_mc_clk_sel(data)                                   (0x40000000&((data)<<30))
#define SYS_CLKSEL_ve_sel(data)                                       (0x10000000&((data)<<28))
#define SYS_CLKSEL_sd_emmc_clk_sel(data)                              (0x08000000&((data)<<27))
#define SYS_CLKSEL_pcr108_clksel(data)                                (0x04000000&((data)<<26))
#define SYS_CLKSEL_dummy18000204_25(data)                             (0x02000000&((data)<<25))
#define SYS_CLKSEL_dpll_clksel(data)                                  (0x01800000&((data)<<23))
#define SYS_CLKSEL_sd_clk_div(data)                                   (0x00700000&((data)<<20))
#define SYS_CLKSEL_ve_rif_use_p2clk(data)                             (0x00080000&((data)<<19))
#define SYS_CLKSEL_ve2_rif_use_p2clk(data)                            (0x00040000&((data)<<18))
#define SYS_CLKSEL_atvin_clk_sel(data)                                (0x00020000&((data)<<17))
#define SYS_CLKSEL_atvin_vd_clk_sel(data)                             (0x00010000&((data)<<16))
#define SYS_CLKSEL_atvin_vdadc_tve_clk_sel(data)                      (0x00008000&((data)<<15))
#define SYS_CLKSEL_tve_108m_clk_sel(data)                             (0x00002000&((data)<<13))
#define SYS_CLKSEL_cbus_clksel(data)                                  (0x00001000&((data)<<12))
#define SYS_CLKSEL_tp_post_div(data)                                  (0x00000F00&((data)<<8))
#define SYS_CLKSEL_tp_pre_div(data)                                   (0x000000F0&((data)<<4))
#define SYS_CLKSEL_vdec_x27_clksel(data)                              (0x00000008&((data)<<3))
#define SYS_CLKSEL_vbis0_yppsel(data)                                 (0x00000004&((data)<<2))
#define SYS_CLKSEL_inv_vbis0_sel(data)                                (0x00000002&((data)<<1))
#define SYS_CLKSEL_uart_clksel(data)                                  (0x00000001&(data))
#define SYS_CLKSEL_get_pll_bypass_ref_clk_mode(data)                  ((0x80000000&(data))>>31)
#define SYS_CLKSEL_get_mc_clk_sel(data)                               ((0x40000000&(data))>>30)
#define SYS_CLKSEL_get_ve_sel(data)                                   ((0x10000000&(data))>>28)
#define SYS_CLKSEL_get_sd_emmc_clk_sel(data)                          ((0x08000000&(data))>>27)
#define SYS_CLKSEL_get_pcr108_clksel(data)                            ((0x04000000&(data))>>26)
#define SYS_CLKSEL_get_dummy18000204_25(data)                         ((0x02000000&(data))>>25)
#define SYS_CLKSEL_get_dpll_clksel(data)                              ((0x01800000&(data))>>23)
#define SYS_CLKSEL_get_sd_clk_div(data)                               ((0x00700000&(data))>>20)
#define SYS_CLKSEL_get_ve_rif_use_p2clk(data)                         ((0x00080000&(data))>>19)
#define SYS_CLKSEL_get_ve2_rif_use_p2clk(data)                        ((0x00040000&(data))>>18)
#define SYS_CLKSEL_get_atvin_clk_sel(data)                            ((0x00020000&(data))>>17)
#define SYS_CLKSEL_get_atvin_vd_clk_sel(data)                         ((0x00010000&(data))>>16)
#define SYS_CLKSEL_get_atvin_vdadc_tve_clk_sel(data)                  ((0x00008000&(data))>>15)
#define SYS_CLKSEL_get_tve_108m_clk_sel(data)                         ((0x00002000&(data))>>13)
#define SYS_CLKSEL_get_cbus_clksel(data)                              ((0x00001000&(data))>>12)
#define SYS_CLKSEL_get_tp_post_div(data)                              ((0x00000F00&(data))>>8)
#define SYS_CLKSEL_get_tp_pre_div(data)                               ((0x000000F0&(data))>>4)
#define SYS_CLKSEL_get_vdec_x27_clksel(data)                          ((0x00000008&(data))>>3)
#define SYS_CLKSEL_get_vbis0_yppsel(data)                             ((0x00000004&(data))>>2)
#define SYS_CLKSEL_get_inv_vbis0_sel(data)                            ((0x00000002&(data))>>1)
#define SYS_CLKSEL_get_uart_clksel(data)                              (0x00000001&(data))


#define SYS_DISPCLKSEL                                                0x18000208
#define SYS_DISPCLKSEL_reg_addr                                       "0xb8000208"
#define SYS_DISPCLKSEL_reg                                            0xb8000208
#define SYS_DISPCLKSEL_inst_addr                                      "0x0082"
#define SYS_DISPCLKSEL_inst                                           0x0082
#define set_SYS_DISPCLKSEL_reg(data)                                  (*((volatile unsigned int*)SYS_DISPCLKSEL_reg)=data)
#define get_SYS_DISPCLKSEL_reg                                        (*((volatile unsigned int*)SYS_DISPCLKSEL_reg))
#define SYS_DISPCLKSEL_dispd_osd_div_shift                            (30)
#define SYS_DISPCLKSEL_memc_me_div_shift                              (26)
#define SYS_DISPCLKSEL_dclk_fract_b_shift                             (20)
#define SYS_DISPCLKSEL_dclk_fract_a_shift                             (15)
#define SYS_DISPCLKSEL_dispd_gdma_clk_sel_shift                       (14)
#define SYS_DISPCLKSEL_dispd_memc_out_sel_shift                       (12)
#define SYS_DISPCLKSEL_dummy18000208_11_shift                         (11)
#define SYS_DISPCLKSEL_dummy18000208_10_shift                         (10)
#define SYS_DISPCLKSEL_clken_disp_lg_avcom_shift                      (9)
#define SYS_DISPCLKSEL_dummy18000208_8_shift                          (8)
#define SYS_DISPCLKSEL_dummy18000208_7_shift                          (7)
#define SYS_DISPCLKSEL_clken_disp_memc_in_shift                       (6)
#define SYS_DISPCLKSEL_clken_disp_memc_out_shift                      (5)
#define SYS_DISPCLKSEL_clken_disp_sfg_shift                           (4)
#define SYS_DISPCLKSEL_clken_disp_gdma_shift                          (3)
#define SYS_DISPCLKSEL_clken_disp_stage1_shift                        (2)
#define SYS_DISPCLKSEL_clken_disp_osd_shift                           (1)
#define SYS_DISPCLKSEL_dummy18000208_0_shift                          (0)
#define SYS_DISPCLKSEL_dispd_osd_div_mask                             (0xC0000000)
#define SYS_DISPCLKSEL_memc_me_div_mask                               (0x0C000000)
#define SYS_DISPCLKSEL_dclk_fract_b_mask                              (0x03F00000)
#define SYS_DISPCLKSEL_dclk_fract_a_mask                              (0x000F8000)
#define SYS_DISPCLKSEL_dispd_gdma_clk_sel_mask                        (0x00004000)
#define SYS_DISPCLKSEL_dispd_memc_out_sel_mask                        (0x00001000)
#define SYS_DISPCLKSEL_dummy18000208_11_mask                          (0x00000800)
#define SYS_DISPCLKSEL_dummy18000208_10_mask                          (0x00000400)
#define SYS_DISPCLKSEL_clken_disp_lg_avcom_mask                       (0x00000200)
#define SYS_DISPCLKSEL_dummy18000208_8_mask                           (0x00000100)
#define SYS_DISPCLKSEL_dummy18000208_7_mask                           (0x00000080)
#define SYS_DISPCLKSEL_clken_disp_memc_in_mask                        (0x00000040)
#define SYS_DISPCLKSEL_clken_disp_memc_out_mask                       (0x00000020)
#define SYS_DISPCLKSEL_clken_disp_sfg_mask                            (0x00000010)
#define SYS_DISPCLKSEL_clken_disp_gdma_mask                           (0x00000008)
#define SYS_DISPCLKSEL_clken_disp_stage1_mask                         (0x00000004)
#define SYS_DISPCLKSEL_clken_disp_osd_mask                            (0x00000002)
#define SYS_DISPCLKSEL_dummy18000208_0_mask                           (0x00000001)
#define SYS_DISPCLKSEL_dispd_osd_div(data)                            (0xC0000000&((data)<<30))
#define SYS_DISPCLKSEL_memc_me_div(data)                              (0x0C000000&((data)<<26))
#define SYS_DISPCLKSEL_dclk_fract_b(data)                             (0x03F00000&((data)<<20))
#define SYS_DISPCLKSEL_dclk_fract_a(data)                             (0x000F8000&((data)<<15))
#define SYS_DISPCLKSEL_dispd_gdma_clk_sel(data)                       (0x00004000&((data)<<14))
#define SYS_DISPCLKSEL_dispd_memc_out_sel(data)                       (0x00001000&((data)<<12))
#define SYS_DISPCLKSEL_dummy18000208_11(data)                         (0x00000800&((data)<<11))
#define SYS_DISPCLKSEL_dummy18000208_10(data)                         (0x00000400&((data)<<10))
#define SYS_DISPCLKSEL_clken_disp_lg_avcom(data)                      (0x00000200&((data)<<9))
#define SYS_DISPCLKSEL_dummy18000208_8(data)                          (0x00000100&((data)<<8))
#define SYS_DISPCLKSEL_dummy18000208_7(data)                          (0x00000080&((data)<<7))
#define SYS_DISPCLKSEL_clken_disp_memc_in(data)                       (0x00000040&((data)<<6))
#define SYS_DISPCLKSEL_clken_disp_memc_out(data)                      (0x00000020&((data)<<5))
#define SYS_DISPCLKSEL_clken_disp_sfg(data)                           (0x00000010&((data)<<4))
#define SYS_DISPCLKSEL_clken_disp_gdma(data)                          (0x00000008&((data)<<3))
#define SYS_DISPCLKSEL_clken_disp_stage1(data)                        (0x00000004&((data)<<2))
#define SYS_DISPCLKSEL_clken_disp_osd(data)                           (0x00000002&((data)<<1))
#define SYS_DISPCLKSEL_dummy18000208_0(data)                          (0x00000001&(data))
#define SYS_DISPCLKSEL_get_dispd_osd_div(data)                        ((0xC0000000&(data))>>30)
#define SYS_DISPCLKSEL_get_memc_me_div(data)                          ((0x0C000000&(data))>>26)
#define SYS_DISPCLKSEL_get_dclk_fract_b(data)                         ((0x03F00000&(data))>>20)
#define SYS_DISPCLKSEL_get_dclk_fract_a(data)                         ((0x000F8000&(data))>>15)
#define SYS_DISPCLKSEL_get_dispd_gdma_clk_sel(data)                   ((0x00004000&(data))>>14)
#define SYS_DISPCLKSEL_get_dispd_memc_out_sel(data)                   ((0x00001000&(data))>>12)
#define SYS_DISPCLKSEL_get_dummy18000208_11(data)                     ((0x00000800&(data))>>11)
#define SYS_DISPCLKSEL_get_dummy18000208_10(data)                     ((0x00000400&(data))>>10)
#define SYS_DISPCLKSEL_get_clken_disp_lg_avcom(data)                  ((0x00000200&(data))>>9)
#define SYS_DISPCLKSEL_get_dummy18000208_8(data)                      ((0x00000100&(data))>>8)
#define SYS_DISPCLKSEL_get_dummy18000208_7(data)                      ((0x00000080&(data))>>7)
#define SYS_DISPCLKSEL_get_clken_disp_memc_in(data)                   ((0x00000040&(data))>>6)
#define SYS_DISPCLKSEL_get_clken_disp_memc_out(data)                  ((0x00000020&(data))>>5)
#define SYS_DISPCLKSEL_get_clken_disp_sfg(data)                       ((0x00000010&(data))>>4)
#define SYS_DISPCLKSEL_get_clken_disp_gdma(data)                      ((0x00000008&(data))>>3)
#define SYS_DISPCLKSEL_get_clken_disp_stage1(data)                    ((0x00000004&(data))>>2)
#define SYS_DISPCLKSEL_get_clken_disp_osd(data)                       ((0x00000002&(data))>>1)
#define SYS_DISPCLKSEL_get_dummy18000208_0(data)                      (0x00000001&(data))


#define SYS_EXTCLK_EN                                                 0x18000210
#define SYS_EXTCLK_EN_reg_addr                                        "0xb8000210"
#define SYS_EXTCLK_EN_reg                                             0xb8000210
#define SYS_EXTCLK_EN_inst_addr                                       "0x0084"
#define SYS_EXTCLK_EN_inst                                            0x0084
#define set_SYS_EXTCLK_EN_reg(data)                                   (*((volatile unsigned int*)SYS_EXTCLK_EN_reg)=data)
#define get_SYS_EXTCLK_EN_reg                                         (*((volatile unsigned int*)SYS_EXTCLK_EN_reg))
#define SYS_EXTCLK_EN_clken_ext_15_en_shift                           (15)
#define SYS_EXTCLK_EN_clken_ext_14_en_shift                           (14)
#define SYS_EXTCLK_EN_clken_ext_13_en_shift                           (13)
#define SYS_EXTCLK_EN_clken_ext_12_en_shift                           (12)
#define SYS_EXTCLK_EN_clken_ext_11_en_shift                           (11)
#define SYS_EXTCLK_EN_clken_ext_10_en_shift                           (10)
#define SYS_EXTCLK_EN_clken_ext_9_en_shift                            (9)
#define SYS_EXTCLK_EN_clken_ext_8_en_shift                            (8)
#define SYS_EXTCLK_EN_clken_ext_7_en_shift                            (7)
#define SYS_EXTCLK_EN_clken_ext_6_en_shift                            (6)
#define SYS_EXTCLK_EN_clken_ext_5_en_shift                            (5)
#define SYS_EXTCLK_EN_clken_ext_4_en_shift                            (4)
#define SYS_EXTCLK_EN_clken_ext_3_en_shift                            (3)
#define SYS_EXTCLK_EN_clken_ext_2_en_shift                            (2)
#define SYS_EXTCLK_EN_clken_ext_1_en_shift                            (1)
#define SYS_EXTCLK_EN_clken_ext_0_en_shift                            (0)
#define SYS_EXTCLK_EN_clken_ext_15_en_mask                            (0x00008000)
#define SYS_EXTCLK_EN_clken_ext_14_en_mask                            (0x00004000)
#define SYS_EXTCLK_EN_clken_ext_13_en_mask                            (0x00002000)
#define SYS_EXTCLK_EN_clken_ext_12_en_mask                            (0x00001000)
#define SYS_EXTCLK_EN_clken_ext_11_en_mask                            (0x00000800)
#define SYS_EXTCLK_EN_clken_ext_10_en_mask                            (0x00000400)
#define SYS_EXTCLK_EN_clken_ext_9_en_mask                             (0x00000200)
#define SYS_EXTCLK_EN_clken_ext_8_en_mask                             (0x00000100)
#define SYS_EXTCLK_EN_clken_ext_7_en_mask                             (0x00000080)
#define SYS_EXTCLK_EN_clken_ext_6_en_mask                             (0x00000040)
#define SYS_EXTCLK_EN_clken_ext_5_en_mask                             (0x00000020)
#define SYS_EXTCLK_EN_clken_ext_4_en_mask                             (0x00000010)
#define SYS_EXTCLK_EN_clken_ext_3_en_mask                             (0x00000008)
#define SYS_EXTCLK_EN_clken_ext_2_en_mask                             (0x00000004)
#define SYS_EXTCLK_EN_clken_ext_1_en_mask                             (0x00000002)
#define SYS_EXTCLK_EN_clken_ext_0_en_mask                             (0x00000001)
#define SYS_EXTCLK_EN_clken_ext_15_en(data)                           (0x00008000&((data)<<15))
#define SYS_EXTCLK_EN_clken_ext_14_en(data)                           (0x00004000&((data)<<14))
#define SYS_EXTCLK_EN_clken_ext_13_en(data)                           (0x00002000&((data)<<13))
#define SYS_EXTCLK_EN_clken_ext_12_en(data)                           (0x00001000&((data)<<12))
#define SYS_EXTCLK_EN_clken_ext_11_en(data)                           (0x00000800&((data)<<11))
#define SYS_EXTCLK_EN_clken_ext_10_en(data)                           (0x00000400&((data)<<10))
#define SYS_EXTCLK_EN_clken_ext_9_en(data)                            (0x00000200&((data)<<9))
#define SYS_EXTCLK_EN_clken_ext_8_en(data)                            (0x00000100&((data)<<8))
#define SYS_EXTCLK_EN_clken_ext_7_en(data)                            (0x00000080&((data)<<7))
#define SYS_EXTCLK_EN_clken_ext_6_en(data)                            (0x00000040&((data)<<6))
#define SYS_EXTCLK_EN_clken_ext_5_en(data)                            (0x00000020&((data)<<5))
#define SYS_EXTCLK_EN_clken_ext_4_en(data)                            (0x00000010&((data)<<4))
#define SYS_EXTCLK_EN_clken_ext_3_en(data)                            (0x00000008&((data)<<3))
#define SYS_EXTCLK_EN_clken_ext_2_en(data)                            (0x00000004&((data)<<2))
#define SYS_EXTCLK_EN_clken_ext_1_en(data)                            (0x00000002&((data)<<1))
#define SYS_EXTCLK_EN_clken_ext_0_en(data)                            (0x00000001&(data))
#define SYS_EXTCLK_EN_get_clken_ext_15_en(data)                       ((0x00008000&(data))>>15)
#define SYS_EXTCLK_EN_get_clken_ext_14_en(data)                       ((0x00004000&(data))>>14)
#define SYS_EXTCLK_EN_get_clken_ext_13_en(data)                       ((0x00002000&(data))>>13)
#define SYS_EXTCLK_EN_get_clken_ext_12_en(data)                       ((0x00001000&(data))>>12)
#define SYS_EXTCLK_EN_get_clken_ext_11_en(data)                       ((0x00000800&(data))>>11)
#define SYS_EXTCLK_EN_get_clken_ext_10_en(data)                       ((0x00000400&(data))>>10)
#define SYS_EXTCLK_EN_get_clken_ext_9_en(data)                        ((0x00000200&(data))>>9)
#define SYS_EXTCLK_EN_get_clken_ext_8_en(data)                        ((0x00000100&(data))>>8)
#define SYS_EXTCLK_EN_get_clken_ext_7_en(data)                        ((0x00000080&(data))>>7)
#define SYS_EXTCLK_EN_get_clken_ext_6_en(data)                        ((0x00000040&(data))>>6)
#define SYS_EXTCLK_EN_get_clken_ext_5_en(data)                        ((0x00000020&(data))>>5)
#define SYS_EXTCLK_EN_get_clken_ext_4_en(data)                        ((0x00000010&(data))>>4)
#define SYS_EXTCLK_EN_get_clken_ext_3_en(data)                        ((0x00000008&(data))>>3)
#define SYS_EXTCLK_EN_get_clken_ext_2_en(data)                        ((0x00000004&(data))>>2)
#define SYS_EXTCLK_EN_get_clken_ext_1_en(data)                        ((0x00000002&(data))>>1)
#define SYS_EXTCLK_EN_get_clken_ext_0_en(data)                        (0x00000001&(data))


#define SYS_CLKDIV                                                    0x18000214
#define SYS_CLKDIV_reg_addr                                           "0xb8000214"
#define SYS_CLKDIV_reg                                                0xb8000214
#define SYS_CLKDIV_inst_addr                                          "0x0085"
#define SYS_CLKDIV_inst                                               0x0085
#define set_SYS_CLKDIV_reg(data)                                      (*((volatile unsigned int*)SYS_CLKDIV_reg)=data)
#define get_SYS_CLKDIV_reg                                            (*((volatile unsigned int*)SYS_CLKDIV_reg))
#define SYS_CLKDIV_dtv_demod_sel_shift                                (14)
#define SYS_CLKDIV_i2c2_clksel_shift                                  (13)
#define SYS_CLKDIV_i2c1_clksel_shift                                  (12)
#define SYS_CLKDIV_nf_clksel_shift                                    (8)
#define SYS_CLKDIV_dummy18000214_7_shift                              (7)
#define SYS_CLKDIV_aud_dtv2_freq_sel_shift                            (4)
#define SYS_CLKDIV_dummy18000214_3_shift                              (3)
#define SYS_CLKDIV_aud_dtv_freq_sel_shift                             (0)
#define SYS_CLKDIV_dtv_demod_sel_mask                                 (0x00004000)
#define SYS_CLKDIV_i2c2_clksel_mask                                   (0x00002000)
#define SYS_CLKDIV_i2c1_clksel_mask                                   (0x00001000)
#define SYS_CLKDIV_nf_clksel_mask                                     (0x00000700)
#define SYS_CLKDIV_dummy18000214_7_mask                               (0x00000080)
#define SYS_CLKDIV_aud_dtv2_freq_sel_mask                             (0x00000070)
#define SYS_CLKDIV_dummy18000214_3_mask                               (0x00000008)
#define SYS_CLKDIV_aud_dtv_freq_sel_mask                              (0x00000007)
#define SYS_CLKDIV_dtv_demod_sel(data)                                (0x00004000&((data)<<14))
#define SYS_CLKDIV_i2c2_clksel(data)                                  (0x00002000&((data)<<13))
#define SYS_CLKDIV_i2c1_clksel(data)                                  (0x00001000&((data)<<12))
#define SYS_CLKDIV_nf_clksel(data)                                    (0x00000700&((data)<<8))
#define SYS_CLKDIV_dummy18000214_7(data)                              (0x00000080&((data)<<7))
#define SYS_CLKDIV_aud_dtv2_freq_sel(data)                            (0x00000070&((data)<<4))
#define SYS_CLKDIV_dummy18000214_3(data)                              (0x00000008&((data)<<3))
#define SYS_CLKDIV_aud_dtv_freq_sel(data)                             (0x00000007&(data))
#define SYS_CLKDIV_get_dtv_demod_sel(data)                            ((0x00004000&(data))>>14)
#define SYS_CLKDIV_get_i2c2_clksel(data)                              ((0x00002000&(data))>>13)
#define SYS_CLKDIV_get_i2c1_clksel(data)                              ((0x00001000&(data))>>12)
#define SYS_CLKDIV_get_nf_clksel(data)                                ((0x00000700&(data))>>8)
#define SYS_CLKDIV_get_dummy18000214_7(data)                          ((0x00000080&(data))>>7)
#define SYS_CLKDIV_get_aud_dtv2_freq_sel(data)                        ((0x00000070&(data))>>4)
#define SYS_CLKDIV_get_dummy18000214_3(data)                          ((0x00000008&(data))>>3)
#define SYS_CLKDIV_get_aud_dtv_freq_sel(data)                         (0x00000007&(data))


#define SYS_ARM_WD                                                    0x18000218
#define SYS_ARM_WD_reg_addr                                           "0xb8000218"
#define SYS_ARM_WD_reg                                                0xb8000218
#define SYS_ARM_WD_inst_addr                                          "0x0086"
#define SYS_ARM_WD_inst                                               0x0086
#define set_SYS_ARM_WD_reg(data)                                      (*((volatile unsigned int*)SYS_ARM_WD_reg)=data)
#define get_SYS_ARM_WD_reg                                            (*((volatile unsigned int*)SYS_ARM_WD_reg))


#define SYS_IB                                                        0x1800021c
#define SYS_IB_reg_addr                                               "0xb800021c"
#define SYS_IB_reg                                                    0xb800021c
#define SYS_IB_inst_addr                                              "0x0087"
#define SYS_IB_inst                                                   0x0087
#define set_SYS_IB_reg(data)                                          (*((volatile unsigned int*)SYS_IB_reg)=data)
#define get_SYS_IB_reg                                                (*((volatile unsigned int*)SYS_IB_reg))
#define SYS_IB_dummy1800021c_31_29_shift                              (29)
#define SYS_IB_ib_rst_gck_memc_shift                                  (28)
#define SYS_IB_ib_rst_gck_gpu_shift                                   (27)
#define SYS_IB_ib_rst_gck_se2_shift                                   (26)
#define SYS_IB_ib_rst_gck_ve2_shift                                   (25)
#define SYS_IB_ib_rst_gck_ve_shift                                    (24)
#define SYS_IB_ib_rst_gck_tvsb5_shift                                 (23)
#define SYS_IB_ib_rst_gck_tvsb4_shift                                 (22)
#define SYS_IB_ib_rst_gck_tvsb3_shift                                 (21)
#define SYS_IB_ib_rst_gck_tvsb2_shift                                 (20)
#define SYS_IB_ib_rst_gck_tvsb1_shift                                 (19)
#define SYS_IB_ib_rst_gck_sb3_shift                                   (18)
#define SYS_IB_ib_rst_gck_sb2_shift                                   (17)
#define SYS_IB_ib_rst_gck_sb1_shift                                   (16)
#define SYS_IB_dummy1800021c_15_13_shift                              (13)
#define SYS_IB_ib_clk_gck_memc_shift                                  (12)
#define SYS_IB_ib_clk_gck_gpu_shift                                   (11)
#define SYS_IB_ib_clk_gck_se2_shift                                   (10)
#define SYS_IB_ib_clk_gck_ve2_shift                                   (9)
#define SYS_IB_ib_clk_gck_ve_shift                                    (8)
#define SYS_IB_ib_clk_gck_tvsb5_shift                                 (7)
#define SYS_IB_ib_clk_gck_tvsb4_shift                                 (6)
#define SYS_IB_ib_clk_gck_tvsb3_shift                                 (5)
#define SYS_IB_ib_clk_gck_tvsb2_shift                                 (4)
#define SYS_IB_ib_clk_gck_tvsb1_shift                                 (3)
#define SYS_IB_ib_clk_gck_sb3_shift                                   (2)
#define SYS_IB_ib_clk_gck_sb2_shift                                   (1)
#define SYS_IB_ib_clk_gck_sb1_shift                                   (0)
#define SYS_IB_dummy1800021c_31_29_mask                               (0xE0000000)
#define SYS_IB_ib_rst_gck_memc_mask                                   (0x10000000)
#define SYS_IB_ib_rst_gck_gpu_mask                                    (0x08000000)
#define SYS_IB_ib_rst_gck_se2_mask                                    (0x04000000)
#define SYS_IB_ib_rst_gck_ve2_mask                                    (0x02000000)
#define SYS_IB_ib_rst_gck_ve_mask                                     (0x01000000)
#define SYS_IB_ib_rst_gck_tvsb5_mask                                  (0x00800000)
#define SYS_IB_ib_rst_gck_tvsb4_mask                                  (0x00400000)
#define SYS_IB_ib_rst_gck_tvsb3_mask                                  (0x00200000)
#define SYS_IB_ib_rst_gck_tvsb2_mask                                  (0x00100000)
#define SYS_IB_ib_rst_gck_tvsb1_mask                                  (0x00080000)
#define SYS_IB_ib_rst_gck_sb3_mask                                    (0x00040000)
#define SYS_IB_ib_rst_gck_sb2_mask                                    (0x00020000)
#define SYS_IB_ib_rst_gck_sb1_mask                                    (0x00010000)
#define SYS_IB_dummy1800021c_15_13_mask                               (0x0000E000)
#define SYS_IB_ib_clk_gck_memc_mask                                   (0x00001000)
#define SYS_IB_ib_clk_gck_gpu_mask                                    (0x00000800)
#define SYS_IB_ib_clk_gck_se2_mask                                    (0x00000400)
#define SYS_IB_ib_clk_gck_ve2_mask                                    (0x00000200)
#define SYS_IB_ib_clk_gck_ve_mask                                     (0x00000100)
#define SYS_IB_ib_clk_gck_tvsb5_mask                                  (0x00000080)
#define SYS_IB_ib_clk_gck_tvsb4_mask                                  (0x00000040)
#define SYS_IB_ib_clk_gck_tvsb3_mask                                  (0x00000020)
#define SYS_IB_ib_clk_gck_tvsb2_mask                                  (0x00000010)
#define SYS_IB_ib_clk_gck_tvsb1_mask                                  (0x00000008)
#define SYS_IB_ib_clk_gck_sb3_mask                                    (0x00000004)
#define SYS_IB_ib_clk_gck_sb2_mask                                    (0x00000002)
#define SYS_IB_ib_clk_gck_sb1_mask                                    (0x00000001)
#define SYS_IB_dummy1800021c_31_29(data)                              (0xE0000000&((data)<<29))
#define SYS_IB_ib_rst_gck_memc(data)                                  (0x10000000&((data)<<28))
#define SYS_IB_ib_rst_gck_gpu(data)                                   (0x08000000&((data)<<27))
#define SYS_IB_ib_rst_gck_se2(data)                                   (0x04000000&((data)<<26))
#define SYS_IB_ib_rst_gck_ve2(data)                                   (0x02000000&((data)<<25))
#define SYS_IB_ib_rst_gck_ve(data)                                    (0x01000000&((data)<<24))
#define SYS_IB_ib_rst_gck_tvsb5(data)                                 (0x00800000&((data)<<23))
#define SYS_IB_ib_rst_gck_tvsb4(data)                                 (0x00400000&((data)<<22))
#define SYS_IB_ib_rst_gck_tvsb3(data)                                 (0x00200000&((data)<<21))
#define SYS_IB_ib_rst_gck_tvsb2(data)                                 (0x00100000&((data)<<20))
#define SYS_IB_ib_rst_gck_tvsb1(data)                                 (0x00080000&((data)<<19))
#define SYS_IB_ib_rst_gck_sb3(data)                                   (0x00040000&((data)<<18))
#define SYS_IB_ib_rst_gck_sb2(data)                                   (0x00020000&((data)<<17))
#define SYS_IB_ib_rst_gck_sb1(data)                                   (0x00010000&((data)<<16))
#define SYS_IB_dummy1800021c_15_13(data)                              (0x0000E000&((data)<<13))
#define SYS_IB_ib_clk_gck_memc(data)                                  (0x00001000&((data)<<12))
#define SYS_IB_ib_clk_gck_gpu(data)                                   (0x00000800&((data)<<11))
#define SYS_IB_ib_clk_gck_se2(data)                                   (0x00000400&((data)<<10))
#define SYS_IB_ib_clk_gck_ve2(data)                                   (0x00000200&((data)<<9))
#define SYS_IB_ib_clk_gck_ve(data)                                    (0x00000100&((data)<<8))
#define SYS_IB_ib_clk_gck_tvsb5(data)                                 (0x00000080&((data)<<7))
#define SYS_IB_ib_clk_gck_tvsb4(data)                                 (0x00000040&((data)<<6))
#define SYS_IB_ib_clk_gck_tvsb3(data)                                 (0x00000020&((data)<<5))
#define SYS_IB_ib_clk_gck_tvsb2(data)                                 (0x00000010&((data)<<4))
#define SYS_IB_ib_clk_gck_tvsb1(data)                                 (0x00000008&((data)<<3))
#define SYS_IB_ib_clk_gck_sb3(data)                                   (0x00000004&((data)<<2))
#define SYS_IB_ib_clk_gck_sb2(data)                                   (0x00000002&((data)<<1))
#define SYS_IB_ib_clk_gck_sb1(data)                                   (0x00000001&(data))
#define SYS_IB_get_dummy1800021c_31_29(data)                          ((0xE0000000&(data))>>29)
#define SYS_IB_get_ib_rst_gck_memc(data)                              ((0x10000000&(data))>>28)
#define SYS_IB_get_ib_rst_gck_gpu(data)                               ((0x08000000&(data))>>27)
#define SYS_IB_get_ib_rst_gck_se2(data)                               ((0x04000000&(data))>>26)
#define SYS_IB_get_ib_rst_gck_ve2(data)                               ((0x02000000&(data))>>25)
#define SYS_IB_get_ib_rst_gck_ve(data)                                ((0x01000000&(data))>>24)
#define SYS_IB_get_ib_rst_gck_tvsb5(data)                             ((0x00800000&(data))>>23)
#define SYS_IB_get_ib_rst_gck_tvsb4(data)                             ((0x00400000&(data))>>22)
#define SYS_IB_get_ib_rst_gck_tvsb3(data)                             ((0x00200000&(data))>>21)
#define SYS_IB_get_ib_rst_gck_tvsb2(data)                             ((0x00100000&(data))>>20)
#define SYS_IB_get_ib_rst_gck_tvsb1(data)                             ((0x00080000&(data))>>19)
#define SYS_IB_get_ib_rst_gck_sb3(data)                               ((0x00040000&(data))>>18)
#define SYS_IB_get_ib_rst_gck_sb2(data)                               ((0x00020000&(data))>>17)
#define SYS_IB_get_ib_rst_gck_sb1(data)                               ((0x00010000&(data))>>16)
#define SYS_IB_get_dummy1800021c_15_13(data)                          ((0x0000E000&(data))>>13)
#define SYS_IB_get_ib_clk_gck_memc(data)                              ((0x00001000&(data))>>12)
#define SYS_IB_get_ib_clk_gck_gpu(data)                               ((0x00000800&(data))>>11)
#define SYS_IB_get_ib_clk_gck_se2(data)                               ((0x00000400&(data))>>10)
#define SYS_IB_get_ib_clk_gck_ve2(data)                               ((0x00000200&(data))>>9)
#define SYS_IB_get_ib_clk_gck_ve(data)                                ((0x00000100&(data))>>8)
#define SYS_IB_get_ib_clk_gck_tvsb5(data)                             ((0x00000080&(data))>>7)
#define SYS_IB_get_ib_clk_gck_tvsb4(data)                             ((0x00000040&(data))>>6)
#define SYS_IB_get_ib_clk_gck_tvsb3(data)                             ((0x00000020&(data))>>5)
#define SYS_IB_get_ib_clk_gck_tvsb2(data)                             ((0x00000010&(data))>>4)
#define SYS_IB_get_ib_clk_gck_tvsb1(data)                             ((0x00000008&(data))>>3)
#define SYS_IB_get_ib_clk_gck_sb3(data)                               ((0x00000004&(data))>>2)
#define SYS_IB_get_ib_clk_gck_sb2(data)                               ((0x00000002&(data))>>1)
#define SYS_IB_get_ib_clk_gck_sb1(data)                               (0x00000001&(data))


#define SYS_DYN_SW_CPU                                                0x18000220
#define SYS_DYN_SW_CPU_reg_addr                                       "0xb8000220"
#define SYS_DYN_SW_CPU_reg                                            0xb8000220
#define SYS_DYN_SW_CPU_inst_addr                                      "0x0088"
#define SYS_DYN_SW_CPU_inst                                           0x0088
#define set_SYS_DYN_SW_CPU_reg(data)                                  (*((volatile unsigned int*)SYS_DYN_SW_CPU_reg)=data)
#define get_SYS_DYN_SW_CPU_reg                                        (*((volatile unsigned int*)SYS_DYN_SW_CPU_reg))
#define SYS_DYN_SW_CPU_clkratio_vcpu_shift                            (19)
#define SYS_DYN_SW_CPU_clkratio_vcpu_active_shift                     (16)
#define SYS_DYN_SW_CPU_clkratio_acpu_shift                            (11)
#define SYS_DYN_SW_CPU_clkratio_acpu_active_shift                     (8)
#define SYS_DYN_SW_CPU_clkratio_acpu2_shift                           (3)
#define SYS_DYN_SW_CPU_clkratio_acpu2_active_shift                    (0)
#define SYS_DYN_SW_CPU_clkratio_vcpu_mask                             (0x00F80000)
#define SYS_DYN_SW_CPU_clkratio_vcpu_active_mask                      (0x00010000)
#define SYS_DYN_SW_CPU_clkratio_acpu_mask                             (0x0000F800)
#define SYS_DYN_SW_CPU_clkratio_acpu_active_mask                      (0x00000100)
#define SYS_DYN_SW_CPU_clkratio_acpu2_mask                            (0x000000F8)
#define SYS_DYN_SW_CPU_clkratio_acpu2_active_mask                     (0x00000001)
#define SYS_DYN_SW_CPU_clkratio_vcpu(data)                            (0x00F80000&((data)<<19))
#define SYS_DYN_SW_CPU_clkratio_vcpu_active(data)                     (0x00010000&((data)<<16))
#define SYS_DYN_SW_CPU_clkratio_acpu(data)                            (0x0000F800&((data)<<11))
#define SYS_DYN_SW_CPU_clkratio_acpu_active(data)                     (0x00000100&((data)<<8))
#define SYS_DYN_SW_CPU_clkratio_acpu2(data)                           (0x000000F8&((data)<<3))
#define SYS_DYN_SW_CPU_clkratio_acpu2_active(data)                    (0x00000001&(data))
#define SYS_DYN_SW_CPU_get_clkratio_vcpu(data)                        ((0x00F80000&(data))>>19)
#define SYS_DYN_SW_CPU_get_clkratio_vcpu_active(data)                 ((0x00010000&(data))>>16)
#define SYS_DYN_SW_CPU_get_clkratio_acpu(data)                        ((0x0000F800&(data))>>11)
#define SYS_DYN_SW_CPU_get_clkratio_acpu_active(data)                 ((0x00000100&(data))>>8)
#define SYS_DYN_SW_CPU_get_clkratio_acpu2(data)                       ((0x000000F8&(data))>>3)
#define SYS_DYN_SW_CPU_get_clkratio_acpu2_active(data)                (0x00000001&(data))


#define EFUSE_CTRL0                                                   0x18000240
#define EFUSE_CTRL0_reg_addr                                          "0xb8000240"
#define EFUSE_CTRL0_reg                                               0xb8000240
#define EFUSE_CTRL0_inst_addr                                         "0x0090"
#define EFUSE_CTRL0_inst                                              0x0090
#define set_EFUSE_CTRL0_reg(data)                                     (*((volatile unsigned int*)EFUSE_CTRL0_reg)=data)
#define get_EFUSE_CTRL0_reg                                           (*((volatile unsigned int*)EFUSE_CTRL0_reg))
#define EFUSE_CTRL0_efuse_ready_shift                                 (0)
#define EFUSE_CTRL0_efuse_ready_mask                                  (0x00000001)
#define EFUSE_CTRL0_efuse_ready(data)                                 (0x00000001&(data))
#define EFUSE_CTRL0_get_efuse_ready(data)                             (0x00000001&(data))


#define POWER_CTRL0                                                   0x18000260
#define POWER_CTRL0_reg_addr                                          "0xb8000260"
#define POWER_CTRL0_reg                                               0xb8000260
#define POWER_CTRL0_inst_addr                                         "0x0098"
#define POWER_CTRL0_inst                                              0x0098
#define set_POWER_CTRL0_reg(data)                                     (*((volatile unsigned int*)POWER_CTRL0_reg)=data)
#define get_POWER_CTRL0_reg                                           (*((volatile unsigned int*)POWER_CTRL0_reg))
#define POWER_CTRL0_atv_iso_en_shift                                  (12)
#define POWER_CTRL0_atv_str_status_shift                              (10)
#define POWER_CTRL0_atv_str_pow_shift                                 (8)
#define POWER_CTRL0_dtv_iso_en_shift                                  (4)
#define POWER_CTRL0_dtv_str_status_shift                              (2)
#define POWER_CTRL0_dtv_str_pow_shift                                 (0)
#define POWER_CTRL0_atv_iso_en_mask                                   (0x00001000)
#define POWER_CTRL0_atv_str_status_mask                               (0x00000400)
#define POWER_CTRL0_atv_str_pow_mask                                  (0x00000100)
#define POWER_CTRL0_dtv_iso_en_mask                                   (0x00000010)
#define POWER_CTRL0_dtv_str_status_mask                               (0x00000004)
#define POWER_CTRL0_dtv_str_pow_mask                                  (0x00000001)
#define POWER_CTRL0_atv_iso_en(data)                                  (0x00001000&((data)<<12))
#define POWER_CTRL0_atv_str_status(data)                              (0x00000400&((data)<<10))
#define POWER_CTRL0_atv_str_pow(data)                                 (0x00000100&((data)<<8))
#define POWER_CTRL0_dtv_iso_en(data)                                  (0x00000010&((data)<<4))
#define POWER_CTRL0_dtv_str_status(data)                              (0x00000004&((data)<<2))
#define POWER_CTRL0_dtv_str_pow(data)                                 (0x00000001&(data))
#define POWER_CTRL0_get_atv_iso_en(data)                              ((0x00001000&(data))>>12)
#define POWER_CTRL0_get_atv_str_status(data)                          ((0x00000400&(data))>>10)
#define POWER_CTRL0_get_atv_str_pow(data)                             ((0x00000100&(data))>>8)
#define POWER_CTRL0_get_dtv_iso_en(data)                              ((0x00000010&(data))>>4)
#define POWER_CTRL0_get_dtv_str_status(data)                          ((0x00000004&(data))>>2)
#define POWER_CTRL0_get_dtv_str_pow(data)                             (0x00000001&(data))


#define INT_CTRL_SCPU                                                 0x18000290
#define INT_CTRL_SCPU_reg_addr                                        "0xb8000290"
#define INT_CTRL_SCPU_reg                                             0xb8000290
#define INT_CTRL_SCPU_inst_addr                                       "0x00A4"
#define INT_CTRL_SCPU_inst                                            0x00A4
#define set_INT_CTRL_SCPU_reg(data)                                   (*((volatile unsigned int*)INT_CTRL_SCPU_reg)=data)
#define get_INT_CTRL_SCPU_reg                                         (*((volatile unsigned int*)INT_CTRL_SCPU_reg))
#define INT_CTRL_SCPU_smartcard_int_scpu_routing_en_shift             (31)
#define INT_CTRL_SCPU_dummy18000290_30_shift                          (30)
#define INT_CTRL_SCPU_ddc_int_scpu_routing_en_shift                   (29)
#define INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_shift         (28)
#define INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_shift  (27)
#define INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_shift          (26)
#define INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_shift  (25)
#define INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_shift          (24)
#define INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_shift      (23)
#define INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_shift           (22)
#define INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_shift           (21)
#define INT_CTRL_SCPU_gpu_int_scpu_routing_en_shift                   (20)
#define INT_CTRL_SCPU_usb3_int_scpu_routing_en_shift                  (19)
#define INT_CTRL_SCPU_usb2_int_scpu_routing_en_shift                  (18)
#define INT_CTRL_SCPU_etn_int_scpu_routing_en_shift                   (17)
#define INT_CTRL_SCPU_sd_int_scpu_routing_en_shift                    (16)
#define INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_shift             (15)
#define INT_CTRL_SCPU_audio_irq_scpu_routing_en_shift                 (14)
#define INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_shift              (13)
#define INT_CTRL_SCPU_dcphy_int_scpu_routing_en_shift                 (12)
#define INT_CTRL_SCPU_dc_int_scpu_routing_en_shift                    (11)
#define INT_CTRL_SCPU_tve_int_scpu_routing_en_shift                   (10)
#define INT_CTRL_SCPU_osd_int_scpu_routing_en_shift                   (9)
#define INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_shift            (8)
#define INT_CTRL_SCPU_dctl_int_scpu_routing_en_shift                  (7)
#define INT_CTRL_SCPU_vbi_int_scpu_routing_en_shift                   (6)
#define INT_CTRL_SCPU_vdec_int_scpu_routing_en_shift                  (5)
#define INT_CTRL_SCPU_if_demod_int_scpu_routing_en_shift              (4)
#define INT_CTRL_SCPU_dispm_int_scpu_routing_en_shift                 (3)
#define INT_CTRL_SCPU_dispi_int_scpu_routing_en_shift                 (2)
#define INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_shift              (1)
#define INT_CTRL_SCPU_write_data_shift                                (0)
#define INT_CTRL_SCPU_smartcard_int_scpu_routing_en_mask              (0x80000000)
#define INT_CTRL_SCPU_dummy18000290_30_mask                           (0x40000000)
#define INT_CTRL_SCPU_ddc_int_scpu_routing_en_mask                    (0x20000000)
#define INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_mask          (0x10000000)
#define INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_mask   (0x08000000)
#define INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_mask           (0x04000000)
#define INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_mask   (0x02000000)
#define INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask           (0x01000000)
#define INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_mask       (0x00800000)
#define INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask            (0x00400000)
#define INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_mask            (0x00200000)
#define INT_CTRL_SCPU_gpu_int_scpu_routing_en_mask                    (0x00100000)
#define INT_CTRL_SCPU_usb3_int_scpu_routing_en_mask                   (0x00080000)
#define INT_CTRL_SCPU_usb2_int_scpu_routing_en_mask                   (0x00040000)
#define INT_CTRL_SCPU_etn_int_scpu_routing_en_mask                    (0x00020000)
#define INT_CTRL_SCPU_sd_int_scpu_routing_en_mask                     (0x00010000)
#define INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_mask              (0x00008000)
#define INT_CTRL_SCPU_audio_irq_scpu_routing_en_mask                  (0x00004000)
#define INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_mask               (0x00002000)
#define INT_CTRL_SCPU_dcphy_int_scpu_routing_en_mask                  (0x00001000)
#define INT_CTRL_SCPU_dc_int_scpu_routing_en_mask                     (0x00000800)
#define INT_CTRL_SCPU_tve_int_scpu_routing_en_mask                    (0x00000400)
#define INT_CTRL_SCPU_osd_int_scpu_routing_en_mask                    (0x00000200)
#define INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_mask             (0x00000100)
#define INT_CTRL_SCPU_dctl_int_scpu_routing_en_mask                   (0x00000080)
#define INT_CTRL_SCPU_vbi_int_scpu_routing_en_mask                    (0x00000040)
#define INT_CTRL_SCPU_vdec_int_scpu_routing_en_mask                   (0x00000020)
#define INT_CTRL_SCPU_if_demod_int_scpu_routing_en_mask               (0x00000010)
#define INT_CTRL_SCPU_dispm_int_scpu_routing_en_mask                  (0x00000008)
#define INT_CTRL_SCPU_dispi_int_scpu_routing_en_mask                  (0x00000004)
#define INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_mask               (0x00000002)
#define INT_CTRL_SCPU_write_data_mask                                 (0x00000001)
#define INT_CTRL_SCPU_smartcard_int_scpu_routing_en(data)             (0x80000000&((data)<<31))
#define INT_CTRL_SCPU_dummy18000290_30(data)                          (0x40000000&((data)<<30))
#define INT_CTRL_SCPU_ddc_int_scpu_routing_en(data)                   (0x20000000&((data)<<29))
#define INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en(data)         (0x10000000&((data)<<28))
#define INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en(data)  (0x08000000&((data)<<27))
#define INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en(data)          (0x04000000&((data)<<26))
#define INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en(data)  (0x02000000&((data)<<25))
#define INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en(data)          (0x01000000&((data)<<24))
#define INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en(data)      (0x00800000&((data)<<23))
#define INT_CTRL_SCPU_standby_cec_int_scpu_routing_en(data)           (0x00400000&((data)<<22))
#define INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en(data)           (0x00200000&((data)<<21))
#define INT_CTRL_SCPU_gpu_int_scpu_routing_en(data)                   (0x00100000&((data)<<20))
#define INT_CTRL_SCPU_usb3_int_scpu_routing_en(data)                  (0x00080000&((data)<<19))
#define INT_CTRL_SCPU_usb2_int_scpu_routing_en(data)                  (0x00040000&((data)<<18))
#define INT_CTRL_SCPU_etn_int_scpu_routing_en(data)                   (0x00020000&((data)<<17))
#define INT_CTRL_SCPU_sd_int_scpu_routing_en(data)                    (0x00010000&((data)<<16))
#define INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en(data)             (0x00008000&((data)<<15))
#define INT_CTRL_SCPU_audio_irq_scpu_routing_en(data)                 (0x00004000&((data)<<14))
#define INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en(data)              (0x00002000&((data)<<13))
#define INT_CTRL_SCPU_dcphy_int_scpu_routing_en(data)                 (0x00001000&((data)<<12))
#define INT_CTRL_SCPU_dc_int_scpu_routing_en(data)                    (0x00000800&((data)<<11))
#define INT_CTRL_SCPU_tve_int_scpu_routing_en(data)                   (0x00000400&((data)<<10))
#define INT_CTRL_SCPU_osd_int_scpu_routing_en(data)                   (0x00000200&((data)<<9))
#define INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en(data)            (0x00000100&((data)<<8))
#define INT_CTRL_SCPU_dctl_int_scpu_routing_en(data)                  (0x00000080&((data)<<7))
#define INT_CTRL_SCPU_vbi_int_scpu_routing_en(data)                   (0x00000040&((data)<<6))
#define INT_CTRL_SCPU_vdec_int_scpu_routing_en(data)                  (0x00000020&((data)<<5))
#define INT_CTRL_SCPU_if_demod_int_scpu_routing_en(data)              (0x00000010&((data)<<4))
#define INT_CTRL_SCPU_dispm_int_scpu_routing_en(data)                 (0x00000008&((data)<<3))
#define INT_CTRL_SCPU_dispi_int_scpu_routing_en(data)                 (0x00000004&((data)<<2))
#define INT_CTRL_SCPU_apll_dds_int_scpu_routing_en(data)              (0x00000002&((data)<<1))
#define INT_CTRL_SCPU_write_data(data)                                (0x00000001&(data))
#define INT_CTRL_SCPU_get_smartcard_int_scpu_routing_en(data)         ((0x80000000&(data))>>31)
#define INT_CTRL_SCPU_get_dummy18000290_30(data)                      ((0x40000000&(data))>>30)
#define INT_CTRL_SCPU_get_ddc_int_scpu_routing_en(data)               ((0x20000000&(data))>>29)
#define INT_CTRL_SCPU_get_standby_syncp_int_scpu_routing_en(data)     ((0x10000000&(data))>>28)
#define INT_CTRL_SCPU_get_standby_hdmi_clk_det_int_scpu_routing_en(data)  ((0x08000000&(data))>>27)
#define INT_CTRL_SCPU_get_standby_wdog_int_scpu_routing_en(data)      ((0x04000000&(data))>>26)
#define INT_CTRL_SCPU_get_standby_iso_misc_off_int_scpu_routing_en(data)  ((0x02000000&(data))>>25)
#define INT_CTRL_SCPU_get_standby_cbus_int_scpu_routing_en(data)      ((0x01000000&(data))>>24)
#define INT_CTRL_SCPU_get_standby_iso_misc_int_scpu_routing_en(data)  ((0x00800000&(data))>>23)
#define INT_CTRL_SCPU_get_standby_cec_int_scpu_routing_en(data)       ((0x00400000&(data))>>22)
#define INT_CTRL_SCPU_get_standby_rtc_int_scpu_routing_en(data)       ((0x00200000&(data))>>21)
#define INT_CTRL_SCPU_get_gpu_int_scpu_routing_en(data)               ((0x00100000&(data))>>20)
#define INT_CTRL_SCPU_get_usb3_int_scpu_routing_en(data)              ((0x00080000&(data))>>19)
#define INT_CTRL_SCPU_get_usb2_int_scpu_routing_en(data)              ((0x00040000&(data))>>18)
#define INT_CTRL_SCPU_get_etn_int_scpu_routing_en(data)               ((0x00020000&(data))>>17)
#define INT_CTRL_SCPU_get_sd_int_scpu_routing_en(data)                ((0x00010000&(data))>>16)
#define INT_CTRL_SCPU_get_audio_dma_irq_scpu_routing_en(data)         ((0x00008000&(data))>>15)
#define INT_CTRL_SCPU_get_audio_irq_scpu_routing_en(data)             ((0x00004000&(data))>>14)
#define INT_CTRL_SCPU_get_tv_sb_dc_int_scpu_routing_en(data)          ((0x00002000&(data))>>13)
#define INT_CTRL_SCPU_get_dcphy_int_scpu_routing_en(data)             ((0x00001000&(data))>>12)
#define INT_CTRL_SCPU_get_dc_int_scpu_routing_en(data)                ((0x00000800&(data))>>11)
#define INT_CTRL_SCPU_get_tve_int_scpu_routing_en(data)               ((0x00000400&(data))>>10)
#define INT_CTRL_SCPU_get_osd_int_scpu_routing_en(data)               ((0x00000200&(data))>>9)
#define INT_CTRL_SCPU_get_ultra_zoom_int_scpu_routing_en(data)        ((0x00000100&(data))>>8)
#define INT_CTRL_SCPU_get_dctl_int_scpu_routing_en(data)              ((0x00000080&(data))>>7)
#define INT_CTRL_SCPU_get_vbi_int_scpu_routing_en(data)               ((0x00000040&(data))>>6)
#define INT_CTRL_SCPU_get_vdec_int_scpu_routing_en(data)              ((0x00000020&(data))>>5)
#define INT_CTRL_SCPU_get_if_demod_int_scpu_routing_en(data)          ((0x00000010&(data))>>4)
#define INT_CTRL_SCPU_get_dispm_int_scpu_routing_en(data)             ((0x00000008&(data))>>3)
#define INT_CTRL_SCPU_get_dispi_int_scpu_routing_en(data)             ((0x00000004&(data))>>2)
#define INT_CTRL_SCPU_get_apll_dds_int_scpu_routing_en(data)          ((0x00000002&(data))>>1)
#define INT_CTRL_SCPU_get_write_data(data)                            (0x00000001&(data))


#define INT_CTRL_VCPU                                                 0x18000294
#define INT_CTRL_VCPU_reg_addr                                        "0xb8000294"
#define INT_CTRL_VCPU_reg                                             0xb8000294
#define INT_CTRL_VCPU_inst_addr                                       "0x00A5"
#define INT_CTRL_VCPU_inst                                            0x00A5
#define set_INT_CTRL_VCPU_reg(data)                                   (*((volatile unsigned int*)INT_CTRL_VCPU_reg)=data)
#define get_INT_CTRL_VCPU_reg                                         (*((volatile unsigned int*)INT_CTRL_VCPU_reg))
#define INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_shift              (30)
#define INT_CTRL_VCPU_vodma_int_vcpu_routing_en_shift                 (29)
#define INT_CTRL_VCPU_dummy18000294_28_shift                          (28)
#define INT_CTRL_VCPU_dc_int_vcpu2_routing_en_shift                   (27)
#define INT_CTRL_VCPU_dummy18000294_26_shift                          (26)
#define INT_CTRL_VCPU_dummy18000294_25_shift                          (25)
#define INT_CTRL_VCPU_dummy18000294_24_shift                          (24)
#define INT_CTRL_VCPU_dummy18000294_23_shift                          (23)
#define INT_CTRL_VCPU_dummy18000294_22_shift                          (22)
#define INT_CTRL_VCPU_dummy18000294_21_shift                          (21)
#define INT_CTRL_VCPU_dummy18000294_20_shift                          (20)
#define INT_CTRL_VCPU_dummy18000294_19_shift                          (19)
#define INT_CTRL_VCPU_dummy18000294_18_shift                          (18)
#define INT_CTRL_VCPU_dummy18000294_17_shift                          (17)
#define INT_CTRL_VCPU_dummy18000294_16_shift                          (16)
#define INT_CTRL_VCPU_me_int_vcpu_routing_en_shift                    (15)
#define INT_CTRL_VCPU_ddc_int_vcpu_routing_en_shift                   (14)
#define INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_shift              (13)
#define INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_shift                 (12)
#define INT_CTRL_VCPU_dc_int_vcpu_routing_en_shift                    (11)
#define INT_CTRL_VCPU_tve_int_vcpu_routing_en_shift                   (10)
#define INT_CTRL_VCPU_osd_int_vcpu_routing_en_shift                   (9)
#define INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_shift            (8)
#define INT_CTRL_VCPU_dctl_int_vcpu_routing_en_shift                  (7)
#define INT_CTRL_VCPU_vbi_int_vcpu_routing_en_shift                   (6)
#define INT_CTRL_VCPU_vdec_int_vcpu_routing_en_shift                  (5)
#define INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_shift              (4)
#define INT_CTRL_VCPU_dispm_int_vcpu_routing_en_shift                 (3)
#define INT_CTRL_VCPU_dispi_int_vcpu_routing_en_shift                 (2)
#define INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_shift              (1)
#define INT_CTRL_VCPU_write_data_shift                                (0)
#define INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_mask               (0x40000000)
#define INT_CTRL_VCPU_vodma_int_vcpu_routing_en_mask                  (0x20000000)
#define INT_CTRL_VCPU_dummy18000294_28_mask                           (0x10000000)
#define INT_CTRL_VCPU_dc_int_vcpu2_routing_en_mask                    (0x08000000)
#define INT_CTRL_VCPU_dummy18000294_26_mask                           (0x04000000)
#define INT_CTRL_VCPU_dummy18000294_25_mask                           (0x02000000)
#define INT_CTRL_VCPU_dummy18000294_24_mask                           (0x01000000)
#define INT_CTRL_VCPU_dummy18000294_23_mask                           (0x00800000)
#define INT_CTRL_VCPU_dummy18000294_22_mask                           (0x00400000)
#define INT_CTRL_VCPU_dummy18000294_21_mask                           (0x00200000)
#define INT_CTRL_VCPU_dummy18000294_20_mask                           (0x00100000)
#define INT_CTRL_VCPU_dummy18000294_19_mask                           (0x00080000)
#define INT_CTRL_VCPU_dummy18000294_18_mask                           (0x00040000)
#define INT_CTRL_VCPU_dummy18000294_17_mask                           (0x00020000)
#define INT_CTRL_VCPU_dummy18000294_16_mask                           (0x00010000)
#define INT_CTRL_VCPU_me_int_vcpu_routing_en_mask                     (0x00008000)
#define INT_CTRL_VCPU_ddc_int_vcpu_routing_en_mask                    (0x00004000)
#define INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_mask               (0x00002000)
#define INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_mask                  (0x00001000)
#define INT_CTRL_VCPU_dc_int_vcpu_routing_en_mask                     (0x00000800)
#define INT_CTRL_VCPU_tve_int_vcpu_routing_en_mask                    (0x00000400)
#define INT_CTRL_VCPU_osd_int_vcpu_routing_en_mask                    (0x00000200)
#define INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_mask             (0x00000100)
#define INT_CTRL_VCPU_dctl_int_vcpu_routing_en_mask                   (0x00000080)
#define INT_CTRL_VCPU_vbi_int_vcpu_routing_en_mask                    (0x00000040)
#define INT_CTRL_VCPU_vdec_int_vcpu_routing_en_mask                   (0x00000020)
#define INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_mask               (0x00000010)
#define INT_CTRL_VCPU_dispm_int_vcpu_routing_en_mask                  (0x00000008)
#define INT_CTRL_VCPU_dispi_int_vcpu_routing_en_mask                  (0x00000004)
#define INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_mask               (0x00000002)
#define INT_CTRL_VCPU_write_data_mask                                 (0x00000001)
#define INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en(data)              (0x40000000&((data)<<30))
#define INT_CTRL_VCPU_vodma_int_vcpu_routing_en(data)                 (0x20000000&((data)<<29))
#define INT_CTRL_VCPU_dummy18000294_28(data)                          (0x10000000&((data)<<28))
#define INT_CTRL_VCPU_dc_int_vcpu2_routing_en(data)                   (0x08000000&((data)<<27))
#define INT_CTRL_VCPU_dummy18000294_26(data)                          (0x04000000&((data)<<26))
#define INT_CTRL_VCPU_dummy18000294_25(data)                          (0x02000000&((data)<<25))
#define INT_CTRL_VCPU_dummy18000294_24(data)                          (0x01000000&((data)<<24))
#define INT_CTRL_VCPU_dummy18000294_23(data)                          (0x00800000&((data)<<23))
#define INT_CTRL_VCPU_dummy18000294_22(data)                          (0x00400000&((data)<<22))
#define INT_CTRL_VCPU_dummy18000294_21(data)                          (0x00200000&((data)<<21))
#define INT_CTRL_VCPU_dummy18000294_20(data)                          (0x00100000&((data)<<20))
#define INT_CTRL_VCPU_dummy18000294_19(data)                          (0x00080000&((data)<<19))
#define INT_CTRL_VCPU_dummy18000294_18(data)                          (0x00040000&((data)<<18))
#define INT_CTRL_VCPU_dummy18000294_17(data)                          (0x00020000&((data)<<17))
#define INT_CTRL_VCPU_dummy18000294_16(data)                          (0x00010000&((data)<<16))
#define INT_CTRL_VCPU_me_int_vcpu_routing_en(data)                    (0x00008000&((data)<<15))
#define INT_CTRL_VCPU_ddc_int_vcpu_routing_en(data)                   (0x00004000&((data)<<14))
#define INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en(data)              (0x00002000&((data)<<13))
#define INT_CTRL_VCPU_dcphy_int_vcpu_routing_en(data)                 (0x00001000&((data)<<12))
#define INT_CTRL_VCPU_dc_int_vcpu_routing_en(data)                    (0x00000800&((data)<<11))
#define INT_CTRL_VCPU_tve_int_vcpu_routing_en(data)                   (0x00000400&((data)<<10))
#define INT_CTRL_VCPU_osd_int_vcpu_routing_en(data)                   (0x00000200&((data)<<9))
#define INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en(data)            (0x00000100&((data)<<8))
#define INT_CTRL_VCPU_dctl_int_vcpu_routing_en(data)                  (0x00000080&((data)<<7))
#define INT_CTRL_VCPU_vbi_int_vcpu_routing_en(data)                   (0x00000040&((data)<<6))
#define INT_CTRL_VCPU_vdec_int_vcpu_routing_en(data)                  (0x00000020&((data)<<5))
#define INT_CTRL_VCPU_if_demod_int_vcpu_routing_en(data)              (0x00000010&((data)<<4))
#define INT_CTRL_VCPU_dispm_int_vcpu_routing_en(data)                 (0x00000008&((data)<<3))
#define INT_CTRL_VCPU_dispi_int_vcpu_routing_en(data)                 (0x00000004&((data)<<2))
#define INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en(data)              (0x00000002&((data)<<1))
#define INT_CTRL_VCPU_write_data(data)                                (0x00000001&(data))
#define INT_CTRL_VCPU_get_disp2tve_int_vcpu_routing_en(data)          ((0x40000000&(data))>>30)
#define INT_CTRL_VCPU_get_vodma_int_vcpu_routing_en(data)             ((0x20000000&(data))>>29)
#define INT_CTRL_VCPU_get_dummy18000294_28(data)                      ((0x10000000&(data))>>28)
#define INT_CTRL_VCPU_get_dc_int_vcpu2_routing_en(data)               ((0x08000000&(data))>>27)
#define INT_CTRL_VCPU_get_dummy18000294_26(data)                      ((0x04000000&(data))>>26)
#define INT_CTRL_VCPU_get_dummy18000294_25(data)                      ((0x02000000&(data))>>25)
#define INT_CTRL_VCPU_get_dummy18000294_24(data)                      ((0x01000000&(data))>>24)
#define INT_CTRL_VCPU_get_dummy18000294_23(data)                      ((0x00800000&(data))>>23)
#define INT_CTRL_VCPU_get_dummy18000294_22(data)                      ((0x00400000&(data))>>22)
#define INT_CTRL_VCPU_get_dummy18000294_21(data)                      ((0x00200000&(data))>>21)
#define INT_CTRL_VCPU_get_dummy18000294_20(data)                      ((0x00100000&(data))>>20)
#define INT_CTRL_VCPU_get_dummy18000294_19(data)                      ((0x00080000&(data))>>19)
#define INT_CTRL_VCPU_get_dummy18000294_18(data)                      ((0x00040000&(data))>>18)
#define INT_CTRL_VCPU_get_dummy18000294_17(data)                      ((0x00020000&(data))>>17)
#define INT_CTRL_VCPU_get_dummy18000294_16(data)                      ((0x00010000&(data))>>16)
#define INT_CTRL_VCPU_get_me_int_vcpu_routing_en(data)                ((0x00008000&(data))>>15)
#define INT_CTRL_VCPU_get_ddc_int_vcpu_routing_en(data)               ((0x00004000&(data))>>14)
#define INT_CTRL_VCPU_get_tv_sb_dc_int_vcpu_routing_en(data)          ((0x00002000&(data))>>13)
#define INT_CTRL_VCPU_get_dcphy_int_vcpu_routing_en(data)             ((0x00001000&(data))>>12)
#define INT_CTRL_VCPU_get_dc_int_vcpu_routing_en(data)                ((0x00000800&(data))>>11)
#define INT_CTRL_VCPU_get_tve_int_vcpu_routing_en(data)               ((0x00000400&(data))>>10)
#define INT_CTRL_VCPU_get_osd_int_vcpu_routing_en(data)               ((0x00000200&(data))>>9)
#define INT_CTRL_VCPU_get_ultra_zoom_int_vcpu_routing_en(data)        ((0x00000100&(data))>>8)
#define INT_CTRL_VCPU_get_dctl_int_vcpu_routing_en(data)              ((0x00000080&(data))>>7)
#define INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(data)               ((0x00000040&(data))>>6)
#define INT_CTRL_VCPU_get_vdec_int_vcpu_routing_en(data)              ((0x00000020&(data))>>5)
#define INT_CTRL_VCPU_get_if_demod_int_vcpu_routing_en(data)          ((0x00000010&(data))>>4)
#define INT_CTRL_VCPU_get_dispm_int_vcpu_routing_en(data)             ((0x00000008&(data))>>3)
#define INT_CTRL_VCPU_get_dispi_int_vcpu_routing_en(data)             ((0x00000004&(data))>>2)
#define INT_CTRL_VCPU_get_apll_dds_int_vcpu_routing_en(data)          ((0x00000002&(data))>>1)
#define INT_CTRL_VCPU_get_write_data(data)                            (0x00000001&(data))


#define INT_CTRL_ACPU                                                 0x18000298
#define INT_CTRL_ACPU_reg_addr                                        "0xb8000298"
#define INT_CTRL_ACPU_reg                                             0xb8000298
#define INT_CTRL_ACPU_inst_addr                                       "0x00A6"
#define INT_CTRL_ACPU_inst                                            0x00A6
#define set_INT_CTRL_ACPU_reg(data)                                   (*((volatile unsigned int*)INT_CTRL_ACPU_reg)=data)
#define get_INT_CTRL_ACPU_reg                                         (*((volatile unsigned int*)INT_CTRL_ACPU_reg))
#define INT_CTRL_ACPU_me_int_acpu_routing_en_shift                    (16)
#define INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_shift             (15)
#define INT_CTRL_ACPU_audio_irq_acpu_routing_en_shift                 (14)
#define INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_shift              (13)
#define INT_CTRL_ACPU_dcphy_int_acpu_routing_en_shift                 (12)
#define INT_CTRL_ACPU_dc_int_acpu_routing_en_shift                    (11)
#define INT_CTRL_ACPU_dummy18000298_10_shift                          (10)
#define INT_CTRL_ACPU_dummy18000298_9_shift                           (9)
#define INT_CTRL_ACPU_dummy18000298_8_shift                           (8)
#define INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en_shift            (7)
#define INT_CTRL_ACPU_audio_irq_acpu2_routing_en_shift                (6)
#define INT_CTRL_ACPU_dummy18000298_5_shift                           (5)
#define INT_CTRL_ACPU_dummy18000298_4_shift                           (4)
#define INT_CTRL_ACPU_dc_int_acpu2_routing_en_shift                   (3)
#define INT_CTRL_ACPU_dummy18000298_2_shift                           (2)
#define INT_CTRL_ACPU_dummy18000298_1_shift                           (1)
#define INT_CTRL_ACPU_write_data_shift                                (0)
#define INT_CTRL_ACPU_me_int_acpu_routing_en_mask                     (0x00010000)
#define INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_mask              (0x00008000)
#define INT_CTRL_ACPU_audio_irq_acpu_routing_en_mask                  (0x00004000)
#define INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_mask               (0x00002000)
#define INT_CTRL_ACPU_dcphy_int_acpu_routing_en_mask                  (0x00001000)
#define INT_CTRL_ACPU_dc_int_acpu_routing_en_mask                     (0x00000800)
#define INT_CTRL_ACPU_dummy18000298_10_mask                           (0x00000400)
#define INT_CTRL_ACPU_dummy18000298_9_mask                            (0x00000200)
#define INT_CTRL_ACPU_dummy18000298_8_mask                            (0x00000100)
#define INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en_mask             (0x00000080)
#define INT_CTRL_ACPU_audio_irq_acpu2_routing_en_mask                 (0x00000040)
#define INT_CTRL_ACPU_dummy18000298_5_mask                            (0x00000020)
#define INT_CTRL_ACPU_dummy18000298_4_mask                            (0x00000010)
#define INT_CTRL_ACPU_dc_int_acpu2_routing_en_mask                    (0x00000008)
#define INT_CTRL_ACPU_dummy18000298_2_mask                            (0x00000004)
#define INT_CTRL_ACPU_dummy18000298_1_mask                            (0x00000002)
#define INT_CTRL_ACPU_write_data_mask                                 (0x00000001)
#define INT_CTRL_ACPU_me_int_acpu_routing_en(data)                    (0x00010000&((data)<<16))
#define INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en(data)             (0x00008000&((data)<<15))
#define INT_CTRL_ACPU_audio_irq_acpu_routing_en(data)                 (0x00004000&((data)<<14))
#define INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en(data)              (0x00002000&((data)<<13))
#define INT_CTRL_ACPU_dcphy_int_acpu_routing_en(data)                 (0x00001000&((data)<<12))
#define INT_CTRL_ACPU_dc_int_acpu_routing_en(data)                    (0x00000800&((data)<<11))
#define INT_CTRL_ACPU_dummy18000298_10(data)                          (0x00000400&((data)<<10))
#define INT_CTRL_ACPU_dummy18000298_9(data)                           (0x00000200&((data)<<9))
#define INT_CTRL_ACPU_dummy18000298_8(data)                           (0x00000100&((data)<<8))
#define INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en(data)            (0x00000080&((data)<<7))
#define INT_CTRL_ACPU_audio_irq_acpu2_routing_en(data)                (0x00000040&((data)<<6))
#define INT_CTRL_ACPU_dummy18000298_5(data)                           (0x00000020&((data)<<5))
#define INT_CTRL_ACPU_dummy18000298_4(data)                           (0x00000010&((data)<<4))
#define INT_CTRL_ACPU_dc_int_acpu2_routing_en(data)                   (0x00000008&((data)<<3))
#define INT_CTRL_ACPU_dummy18000298_2(data)                           (0x00000004&((data)<<2))
#define INT_CTRL_ACPU_dummy18000298_1(data)                           (0x00000002&((data)<<1))
#define INT_CTRL_ACPU_write_data(data)                                (0x00000001&(data))
#define INT_CTRL_ACPU_get_me_int_acpu_routing_en(data)                ((0x00010000&(data))>>16)
#define INT_CTRL_ACPU_get_audio_dma_irq_acpu_routing_en(data)         ((0x00008000&(data))>>15)
#define INT_CTRL_ACPU_get_audio_irq_acpu_routing_en(data)             ((0x00004000&(data))>>14)
#define INT_CTRL_ACPU_get_tv_sb_dc_int_acpu_routing_en(data)          ((0x00002000&(data))>>13)
#define INT_CTRL_ACPU_get_dcphy_int_acpu_routing_en(data)             ((0x00001000&(data))>>12)
#define INT_CTRL_ACPU_get_dc_int_acpu_routing_en(data)                ((0x00000800&(data))>>11)
#define INT_CTRL_ACPU_get_dummy18000298_10(data)                      ((0x00000400&(data))>>10)
#define INT_CTRL_ACPU_get_dummy18000298_9(data)                       ((0x00000200&(data))>>9)
#define INT_CTRL_ACPU_get_dummy18000298_8(data)                       ((0x00000100&(data))>>8)
#define INT_CTRL_ACPU_get_audio_dma_irq_acpu2_routing_en(data)        ((0x00000080&(data))>>7)
#define INT_CTRL_ACPU_get_audio_irq_acpu2_routing_en(data)            ((0x00000040&(data))>>6)
#define INT_CTRL_ACPU_get_dummy18000298_5(data)                       ((0x00000020&(data))>>5)
#define INT_CTRL_ACPU_get_dummy18000298_4(data)                       ((0x00000010&(data))>>4)
#define INT_CTRL_ACPU_get_dc_int_acpu2_routing_en(data)               ((0x00000008&(data))>>3)
#define INT_CTRL_ACPU_get_dummy18000298_2(data)                       ((0x00000004&(data))>>2)
#define INT_CTRL_ACPU_get_dummy18000298_1(data)                       ((0x00000002&(data))>>1)
#define INT_CTRL_ACPU_get_write_data(data)                            (0x00000001&(data))


#define INT_CTRL_KCPU                                                 0x1800029c
#define INT_CTRL_KCPU_reg_addr                                        "0xb800029c"
#define INT_CTRL_KCPU_reg                                             0xb800029c
#define INT_CTRL_KCPU_inst_addr                                       "0x00A7"
#define INT_CTRL_KCPU_inst                                            0x00A7
#define set_INT_CTRL_KCPU_reg(data)                                   (*((volatile unsigned int*)INT_CTRL_KCPU_reg)=data)
#define get_INT_CTRL_KCPU_reg                                         (*((volatile unsigned int*)INT_CTRL_KCPU_reg))
#define INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_shift             (31)
#define INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_shift              (30)
#define INT_CTRL_KCPU_vodma_int_kcpu_routing_en_shift                 (29)
#define INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_shift         (28)
#define INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_shift  (27)
#define INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_shift          (26)
#define INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_shift  (25)
#define INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_shift          (24)
#define INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_shift      (23)
#define INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_shift           (22)
#define INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_shift           (21)
#define INT_CTRL_KCPU_gpu_int_kcpu_routing_en_shift                   (20)
#define INT_CTRL_KCPU_usb3_int_kcpu_routing_en_shift                  (19)
#define INT_CTRL_KCPU_usb2_int_kcpu_routing_en_shift                  (18)
#define INT_CTRL_KCPU_etn_int_kcpu_routing_en_shift                   (17)
#define INT_CTRL_KCPU_sd_int_kcpu_routing_en_shift                    (16)
#define INT_CTRL_KCPU_dummy1800029c_15_shift                          (15)
#define INT_CTRL_KCPU_ddc_int_kcpu_routing_en_shift                   (14)
#define INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_shift              (13)
#define INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_shift                 (12)
#define INT_CTRL_KCPU_dc_int_kcpu_routing_en_shift                    (11)
#define INT_CTRL_KCPU_tve_int_kcpu_routing_en_shift                   (10)
#define INT_CTRL_KCPU_osd_int_kcpu_routing_en_shift                   (9)
#define INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_shift            (8)
#define INT_CTRL_KCPU_dctl_int_kcpu_routing_en_shift                  (7)
#define INT_CTRL_KCPU_vbi_int_kcpu_routing_en_shift                   (6)
#define INT_CTRL_KCPU_vdec_int_kcpu_routing_en_shift                  (5)
#define INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_shift              (4)
#define INT_CTRL_KCPU_dispm_int_kcpu_routing_en_shift                 (3)
#define INT_CTRL_KCPU_dispi_int_kcpu_routing_en_shift                 (2)
#define INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_shift              (1)
#define INT_CTRL_KCPU_write_data_shift                                (0)
#define INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_mask              (0x80000000)
#define INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_mask               (0x40000000)
#define INT_CTRL_KCPU_vodma_int_kcpu_routing_en_mask                  (0x20000000)
#define INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_mask          (0x10000000)
#define INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_mask   (0x08000000)
#define INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_mask           (0x04000000)
#define INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_mask   (0x02000000)
#define INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_mask           (0x01000000)
#define INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_mask       (0x00800000)
#define INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_mask            (0x00400000)
#define INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_mask            (0x00200000)
#define INT_CTRL_KCPU_gpu_int_kcpu_routing_en_mask                    (0x00100000)
#define INT_CTRL_KCPU_usb3_int_kcpu_routing_en_mask                   (0x00080000)
#define INT_CTRL_KCPU_usb2_int_kcpu_routing_en_mask                   (0x00040000)
#define INT_CTRL_KCPU_etn_int_kcpu_routing_en_mask                    (0x00020000)
#define INT_CTRL_KCPU_sd_int_kcpu_routing_en_mask                     (0x00010000)
#define INT_CTRL_KCPU_dummy1800029c_15_mask                           (0x00008000)
#define INT_CTRL_KCPU_ddc_int_kcpu_routing_en_mask                    (0x00004000)
#define INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_mask               (0x00002000)
#define INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_mask                  (0x00001000)
#define INT_CTRL_KCPU_dc_int_kcpu_routing_en_mask                     (0x00000800)
#define INT_CTRL_KCPU_tve_int_kcpu_routing_en_mask                    (0x00000400)
#define INT_CTRL_KCPU_osd_int_kcpu_routing_en_mask                    (0x00000200)
#define INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_mask             (0x00000100)
#define INT_CTRL_KCPU_dctl_int_kcpu_routing_en_mask                   (0x00000080)
#define INT_CTRL_KCPU_vbi_int_kcpu_routing_en_mask                    (0x00000040)
#define INT_CTRL_KCPU_vdec_int_kcpu_routing_en_mask                   (0x00000020)
#define INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_mask               (0x00000010)
#define INT_CTRL_KCPU_dispm_int_kcpu_routing_en_mask                  (0x00000008)
#define INT_CTRL_KCPU_dispi_int_kcpu_routing_en_mask                  (0x00000004)
#define INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_mask               (0x00000002)
#define INT_CTRL_KCPU_write_data_mask                                 (0x00000001)
#define INT_CTRL_KCPU_smartcard_int_kcpu_routing_en(data)             (0x80000000&((data)<<31))
#define INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en(data)              (0x40000000&((data)<<30))
#define INT_CTRL_KCPU_vodma_int_kcpu_routing_en(data)                 (0x20000000&((data)<<29))
#define INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en(data)         (0x10000000&((data)<<28))
#define INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en(data)  (0x08000000&((data)<<27))
#define INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en(data)          (0x04000000&((data)<<26))
#define INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en(data)  (0x02000000&((data)<<25))
#define INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en(data)          (0x01000000&((data)<<24))
#define INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en(data)      (0x00800000&((data)<<23))
#define INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en(data)           (0x00400000&((data)<<22))
#define INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en(data)           (0x00200000&((data)<<21))
#define INT_CTRL_KCPU_gpu_int_kcpu_routing_en(data)                   (0x00100000&((data)<<20))
#define INT_CTRL_KCPU_usb3_int_kcpu_routing_en(data)                  (0x00080000&((data)<<19))
#define INT_CTRL_KCPU_usb2_int_kcpu_routing_en(data)                  (0x00040000&((data)<<18))
#define INT_CTRL_KCPU_etn_int_kcpu_routing_en(data)                   (0x00020000&((data)<<17))
#define INT_CTRL_KCPU_sd_int_kcpu_routing_en(data)                    (0x00010000&((data)<<16))
#define INT_CTRL_KCPU_dummy1800029c_15(data)                          (0x00008000&((data)<<15))
#define INT_CTRL_KCPU_ddc_int_kcpu_routing_en(data)                   (0x00004000&((data)<<14))
#define INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en(data)              (0x00002000&((data)<<13))
#define INT_CTRL_KCPU_dcphy_int_kcpu_routing_en(data)                 (0x00001000&((data)<<12))
#define INT_CTRL_KCPU_dc_int_kcpu_routing_en(data)                    (0x00000800&((data)<<11))
#define INT_CTRL_KCPU_tve_int_kcpu_routing_en(data)                   (0x00000400&((data)<<10))
#define INT_CTRL_KCPU_osd_int_kcpu_routing_en(data)                   (0x00000200&((data)<<9))
#define INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en(data)            (0x00000100&((data)<<8))
#define INT_CTRL_KCPU_dctl_int_kcpu_routing_en(data)                  (0x00000080&((data)<<7))
#define INT_CTRL_KCPU_vbi_int_kcpu_routing_en(data)                   (0x00000040&((data)<<6))
#define INT_CTRL_KCPU_vdec_int_kcpu_routing_en(data)                  (0x00000020&((data)<<5))
#define INT_CTRL_KCPU_if_demod_int_kcpu_routing_en(data)              (0x00000010&((data)<<4))
#define INT_CTRL_KCPU_dispm_int_kcpu_routing_en(data)                 (0x00000008&((data)<<3))
#define INT_CTRL_KCPU_dispi_int_kcpu_routing_en(data)                 (0x00000004&((data)<<2))
#define INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en(data)              (0x00000002&((data)<<1))
#define INT_CTRL_KCPU_write_data(data)                                (0x00000001&(data))
#define INT_CTRL_KCPU_get_smartcard_int_kcpu_routing_en(data)         ((0x80000000&(data))>>31)
#define INT_CTRL_KCPU_get_disp2tve_int_kcpu_routing_en(data)          ((0x40000000&(data))>>30)
#define INT_CTRL_KCPU_get_vodma_int_kcpu_routing_en(data)             ((0x20000000&(data))>>29)
#define INT_CTRL_KCPU_get_standby_syncp_int_kcpu_routing_en(data)     ((0x10000000&(data))>>28)
#define INT_CTRL_KCPU_get_standby_hdmi_clk_det_int_kcpu_routing_en(data)  ((0x08000000&(data))>>27)
#define INT_CTRL_KCPU_get_standby_wdog_int_kcpu_routing_en(data)      ((0x04000000&(data))>>26)
#define INT_CTRL_KCPU_get_standby_iso_misc_off_int_kcpu_routing_en(data)  ((0x02000000&(data))>>25)
#define INT_CTRL_KCPU_get_standby_cbus_int_kcpu_routing_en(data)      ((0x01000000&(data))>>24)
#define INT_CTRL_KCPU_get_standby_iso_misc_int_kcpu_routing_en(data)  ((0x00800000&(data))>>23)
#define INT_CTRL_KCPU_get_standby_cec_int_kcpu_routing_en(data)       ((0x00400000&(data))>>22)
#define INT_CTRL_KCPU_get_standby_rtc_int_kcpu_routing_en(data)       ((0x00200000&(data))>>21)
#define INT_CTRL_KCPU_get_gpu_int_kcpu_routing_en(data)               ((0x00100000&(data))>>20)
#define INT_CTRL_KCPU_get_usb3_int_kcpu_routing_en(data)              ((0x00080000&(data))>>19)
#define INT_CTRL_KCPU_get_usb2_int_kcpu_routing_en(data)              ((0x00040000&(data))>>18)
#define INT_CTRL_KCPU_get_etn_int_kcpu_routing_en(data)               ((0x00020000&(data))>>17)
#define INT_CTRL_KCPU_get_sd_int_kcpu_routing_en(data)                ((0x00010000&(data))>>16)
#define INT_CTRL_KCPU_get_dummy1800029c_15(data)                      ((0x00008000&(data))>>15)
#define INT_CTRL_KCPU_get_ddc_int_kcpu_routing_en(data)               ((0x00004000&(data))>>14)
#define INT_CTRL_KCPU_get_tv_sb_dc_int_kcpu_routing_en(data)          ((0x00002000&(data))>>13)
#define INT_CTRL_KCPU_get_dcphy_int_kcpu_routing_en(data)             ((0x00001000&(data))>>12)
#define INT_CTRL_KCPU_get_dc_int_kcpu_routing_en(data)                ((0x00000800&(data))>>11)
#define INT_CTRL_KCPU_get_tve_int_kcpu_routing_en(data)               ((0x00000400&(data))>>10)
#define INT_CTRL_KCPU_get_osd_int_kcpu_routing_en(data)               ((0x00000200&(data))>>9)
#define INT_CTRL_KCPU_get_ultra_zoom_int_kcpu_routing_en(data)        ((0x00000100&(data))>>8)
#define INT_CTRL_KCPU_get_dctl_int_kcpu_routing_en(data)              ((0x00000080&(data))>>7)
#define INT_CTRL_KCPU_get_vbi_int_kcpu_routing_en(data)               ((0x00000040&(data))>>6)
#define INT_CTRL_KCPU_get_vdec_int_kcpu_routing_en(data)              ((0x00000020&(data))>>5)
#define INT_CTRL_KCPU_get_if_demod_int_kcpu_routing_en(data)          ((0x00000010&(data))>>4)
#define INT_CTRL_KCPU_get_dispm_int_kcpu_routing_en(data)             ((0x00000008&(data))>>3)
#define INT_CTRL_KCPU_get_dispi_int_kcpu_routing_en(data)             ((0x00000004&(data))>>2)
#define INT_CTRL_KCPU_get_apll_dds_int_kcpu_routing_en(data)          ((0x00000002&(data))>>1)
#define INT_CTRL_KCPU_get_write_data(data)                            (0x00000001&(data))


#define INT_CTRL_MEMC                                                 0x180002a0
#define INT_CTRL_MEMC_reg_addr                                        "0xb80002a0"
#define INT_CTRL_MEMC_reg                                             0xb80002a0
#define INT_CTRL_MEMC_inst_addr                                       "0x00A8"
#define INT_CTRL_MEMC_inst                                            0x00A8
#define set_INT_CTRL_MEMC_reg(data)                                   (*((volatile unsigned int*)INT_CTRL_MEMC_reg)=data)
#define get_INT_CTRL_MEMC_reg                                         (*((volatile unsigned int*)INT_CTRL_MEMC_reg))
#define INT_CTRL_MEMC_memc_int_vcpu_routing_en_shift                  (28)
#define INT_CTRL_MEMC_dummy180002a0_27_shift                          (27)
#define INT_CTRL_MEMC_dummy180002a0_26_shift                          (26)
#define INT_CTRL_MEMC_dummy180002a0_25_shift                          (25)
#define INT_CTRL_MEMC_memc_int_vcpu2_routing_en_shift                 (24)
#define INT_CTRL_MEMC_dummy180002a0_23_shift                          (23)
#define INT_CTRL_MEMC_dummy180002a0_22_shift                          (22)
#define INT_CTRL_MEMC_dummy180002a0_21_shift                          (21)
#define INT_CTRL_MEMC_memc_int_scpu_routing_en_shift                  (20)
#define INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en_shift                  (17)
#define INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_shift                  (16)
#define INT_CTRL_MEMC_write_data_shift                                (0)
#define INT_CTRL_MEMC_memc_int_vcpu_routing_en_mask                   (0x10000000)
#define INT_CTRL_MEMC_dummy180002a0_27_mask                           (0x08000000)
#define INT_CTRL_MEMC_dummy180002a0_26_mask                           (0x04000000)
#define INT_CTRL_MEMC_dummy180002a0_25_mask                           (0x02000000)
#define INT_CTRL_MEMC_memc_int_vcpu2_routing_en_mask                  (0x01000000)
#define INT_CTRL_MEMC_dummy180002a0_23_mask                           (0x00800000)
#define INT_CTRL_MEMC_dummy180002a0_22_mask                           (0x00400000)
#define INT_CTRL_MEMC_dummy180002a0_21_mask                           (0x00200000)
#define INT_CTRL_MEMC_memc_int_scpu_routing_en_mask                   (0x00100000)
#define INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en_mask                   (0x00020000)
#define INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_mask                   (0x00010000)
#define INT_CTRL_MEMC_write_data_mask                                 (0x00000001)
#define INT_CTRL_MEMC_memc_int_vcpu_routing_en(data)                  (0x10000000&((data)<<28))
#define INT_CTRL_MEMC_dummy180002a0_27(data)                          (0x08000000&((data)<<27))
#define INT_CTRL_MEMC_dummy180002a0_26(data)                          (0x04000000&((data)<<26))
#define INT_CTRL_MEMC_dummy180002a0_25(data)                          (0x02000000&((data)<<25))
#define INT_CTRL_MEMC_memc_int_vcpu2_routing_en(data)                 (0x01000000&((data)<<24))
#define INT_CTRL_MEMC_dummy180002a0_23(data)                          (0x00800000&((data)<<23))
#define INT_CTRL_MEMC_dummy180002a0_22(data)                          (0x00400000&((data)<<22))
#define INT_CTRL_MEMC_dummy180002a0_21(data)                          (0x00200000&((data)<<21))
#define INT_CTRL_MEMC_memc_int_scpu_routing_en(data)                  (0x00100000&((data)<<20))
#define INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en(data)                  (0x00020000&((data)<<17))
#define INT_CTRL_MEMC_hdmi_irq_scpu_routing_en(data)                  (0x00010000&((data)<<16))
#define INT_CTRL_MEMC_write_data(data)                                (0x00000001&(data))
#define INT_CTRL_MEMC_get_memc_int_vcpu_routing_en(data)              ((0x10000000&(data))>>28)
#define INT_CTRL_MEMC_get_dummy180002a0_27(data)                      ((0x08000000&(data))>>27)
#define INT_CTRL_MEMC_get_dummy180002a0_26(data)                      ((0x04000000&(data))>>26)
#define INT_CTRL_MEMC_get_dummy180002a0_25(data)                      ((0x02000000&(data))>>25)
#define INT_CTRL_MEMC_get_memc_int_vcpu2_routing_en(data)             ((0x01000000&(data))>>24)
#define INT_CTRL_MEMC_get_dummy180002a0_23(data)                      ((0x00800000&(data))>>23)
#define INT_CTRL_MEMC_get_dummy180002a0_22(data)                      ((0x00400000&(data))>>22)
#define INT_CTRL_MEMC_get_dummy180002a0_21(data)                      ((0x00200000&(data))>>21)
#define INT_CTRL_MEMC_get_memc_int_scpu_routing_en(data)              ((0x00100000&(data))>>20)
#define INT_CTRL_MEMC_get_hdmi_irq_vcpu_routing_en(data)              ((0x00020000&(data))>>17)
#define INT_CTRL_MEMC_get_hdmi_irq_scpu_routing_en(data)              ((0x00010000&(data))>>16)
#define INT_CTRL_MEMC_get_write_data(data)                            (0x00000001&(data))


#define INT_CTRL_SCPU_2                                               0x180002a4
#define INT_CTRL_SCPU_2_reg_addr                                      "0xb80002a4"
#define INT_CTRL_SCPU_2_reg                                           0xb80002a4
#define INT_CTRL_SCPU_2_inst_addr                                     "0x00A9"
#define INT_CTRL_SCPU_2_inst                                          0x00A9
#define set_INT_CTRL_SCPU_2_reg(data)                                 (*((volatile unsigned int*)INT_CTRL_SCPU_2_reg)=data)
#define get_INT_CTRL_SCPU_2_reg                                       (*((volatile unsigned int*)INT_CTRL_SCPU_2_reg))
#define INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en_shift         (14)
#define INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en_shift         (10)
#define INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en_shift         (9)
#define INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en_shift         (8)
#define INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en_shift       (7)
#define INT_CTRL_SCPU_2_md_security_int_scpu_routing_en_shift         (6)
#define INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en_shift        (5)
#define INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en_shift        (4)
#define INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en_shift        (3)
#define INT_CTRL_SCPU_2_se_security_int_scpu_routing_en_shift         (2)
#define INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en_shift        (1)
#define INT_CTRL_SCPU_2_write_data_shift                              (0)
#define INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en_mask          (0x00004000)
#define INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en_mask          (0x00000400)
#define INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en_mask          (0x00000200)
#define INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en_mask          (0x00000100)
#define INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en_mask        (0x00000080)
#define INT_CTRL_SCPU_2_md_security_int_scpu_routing_en_mask          (0x00000040)
#define INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en_mask         (0x00000020)
#define INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en_mask         (0x00000010)
#define INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en_mask         (0x00000008)
#define INT_CTRL_SCPU_2_se_security_int_scpu_routing_en_mask          (0x00000004)
#define INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en_mask         (0x00000002)
#define INT_CTRL_SCPU_2_write_data_mask                               (0x00000001)
#define INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en(data)         (0x00004000&((data)<<14))
#define INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en(data)         (0x00000400&((data)<<10))
#define INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en(data)         (0x00000200&((data)<<9))
#define INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en(data)         (0x00000100&((data)<<8))
#define INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en(data)       (0x00000080&((data)<<7))
#define INT_CTRL_SCPU_2_md_security_int_scpu_routing_en(data)         (0x00000040&((data)<<6))
#define INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en(data)        (0x00000020&((data)<<5))
#define INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en(data)        (0x00000010&((data)<<4))
#define INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en(data)        (0x00000008&((data)<<3))
#define INT_CTRL_SCPU_2_se_security_int_scpu_routing_en(data)         (0x00000004&((data)<<2))
#define INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en(data)        (0x00000002&((data)<<1))
#define INT_CTRL_SCPU_2_write_data(data)                              (0x00000001&(data))
#define INT_CTRL_SCPU_2_get_dc_security_int_scpu_routing_en(data)     ((0x00004000&(data))>>14)
#define INT_CTRL_SCPU_2_get_tm_security_int_scpu_routing_en(data)     ((0x00000400&(data))>>10)
#define INT_CTRL_SCPU_2_get_tp_security_int_scpu_routing_en(data)     ((0x00000200&(data))>>9)
#define INT_CTRL_SCPU_2_get_nf_security_int_scpu_routing_en(data)     ((0x00000100&(data))>>8)
#define INT_CTRL_SCPU_2_get_emmc_security_int_scpu_routing_en(data)   ((0x00000080&(data))>>7)
#define INT_CTRL_SCPU_2_get_md_security_int_scpu_routing_en(data)     ((0x00000040&(data))>>6)
#define INT_CTRL_SCPU_2_get_mcp_security_int_scpu_routing_en(data)    ((0x00000020&(data))>>5)
#define INT_CTRL_SCPU_2_get_sb2_security_int_scpu_routing_en(data)    ((0x00000010&(data))>>4)
#define INT_CTRL_SCPU_2_get_mis_security_int_scpu_routing_en(data)    ((0x00000008&(data))>>3)
#define INT_CTRL_SCPU_2_get_se_security_int_scpu_routing_en(data)     ((0x00000004&(data))>>2)
#define INT_CTRL_SCPU_2_get_dc2_security_int_scpu_routing_en(data)    ((0x00000002&(data))>>1)
#define INT_CTRL_SCPU_2_get_write_data(data)                          (0x00000001&(data))


#define INT_CTRL_KCPU_2                                               0x180002a8
#define INT_CTRL_KCPU_2_reg_addr                                      "0xb80002a8"
#define INT_CTRL_KCPU_2_reg                                           0xb80002a8
#define INT_CTRL_KCPU_2_inst_addr                                     "0x00AA"
#define INT_CTRL_KCPU_2_inst                                          0x00AA
#define set_INT_CTRL_KCPU_2_reg(data)                                 (*((volatile unsigned int*)INT_CTRL_KCPU_2_reg)=data)
#define get_INT_CTRL_KCPU_2_reg                                       (*((volatile unsigned int*)INT_CTRL_KCPU_2_reg))
#define INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en_shift         (14)
#define INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en_shift         (10)
#define INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en_shift         (9)
#define INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en_shift         (8)
#define INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en_shift       (7)
#define INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en_shift         (6)
#define INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en_shift        (5)
#define INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en_shift        (4)
#define INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en_shift        (3)
#define INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en_shift         (2)
#define INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en_shift        (1)
#define INT_CTRL_KCPU_2_write_data_shift                              (0)
#define INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en_mask          (0x00004000)
#define INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en_mask          (0x00000400)
#define INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en_mask          (0x00000200)
#define INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en_mask          (0x00000100)
#define INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en_mask        (0x00000080)
#define INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en_mask          (0x00000040)
#define INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en_mask         (0x00000020)
#define INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en_mask         (0x00000010)
#define INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en_mask         (0x00000008)
#define INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en_mask          (0x00000004)
#define INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en_mask         (0x00000002)
#define INT_CTRL_KCPU_2_write_data_mask                               (0x00000001)
#define INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en(data)         (0x00004000&((data)<<14))
#define INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en(data)         (0x00000400&((data)<<10))
#define INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en(data)         (0x00000200&((data)<<9))
#define INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en(data)         (0x00000100&((data)<<8))
#define INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en(data)       (0x00000080&((data)<<7))
#define INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en(data)         (0x00000040&((data)<<6))
#define INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en(data)        (0x00000020&((data)<<5))
#define INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en(data)        (0x00000010&((data)<<4))
#define INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en(data)        (0x00000008&((data)<<3))
#define INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en(data)         (0x00000004&((data)<<2))
#define INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en(data)        (0x00000002&((data)<<1))
#define INT_CTRL_KCPU_2_write_data(data)                              (0x00000001&(data))
#define INT_CTRL_KCPU_2_get_dc_security_int_kcpu_routing_en(data)     ((0x00004000&(data))>>14)
#define INT_CTRL_KCPU_2_get_tm_security_int_kcpu_routing_en(data)     ((0x00000400&(data))>>10)
#define INT_CTRL_KCPU_2_get_tp_security_int_kcpu_routing_en(data)     ((0x00000200&(data))>>9)
#define INT_CTRL_KCPU_2_get_nf_security_int_kcpu_routing_en(data)     ((0x00000100&(data))>>8)
#define INT_CTRL_KCPU_2_get_emmc_security_int_kcpu_routing_en(data)   ((0x00000080&(data))>>7)
#define INT_CTRL_KCPU_2_get_md_security_int_kcpu_routing_en(data)     ((0x00000040&(data))>>6)
#define INT_CTRL_KCPU_2_get_mcp_security_int_kcpu_routing_en(data)    ((0x00000020&(data))>>5)
#define INT_CTRL_KCPU_2_get_sb2_security_int_kcpu_routing_en(data)    ((0x00000010&(data))>>4)
#define INT_CTRL_KCPU_2_get_mis_security_int_kcpu_routing_en(data)    ((0x00000008&(data))>>3)
#define INT_CTRL_KCPU_2_get_se_security_int_kcpu_routing_en(data)     ((0x00000004&(data))>>2)
#define INT_CTRL_KCPU_2_get_dc2_security_int_kcpu_routing_en(data)    ((0x00000002&(data))>>1)
#define INT_CTRL_KCPU_2_get_write_data(data)                          (0x00000001&(data))


#define SS_MAIN_RHVT_0                                                0x180002b0
#define SS_MAIN_RHVT_0_reg_addr                                       "0xb80002b0"
#define SS_MAIN_RHVT_0_reg                                            0xb80002b0
#define SS_MAIN_RHVT_0_inst_addr                                      "0x00AC"
#define SS_MAIN_RHVT_0_inst                                           0x00AC
#define set_SS_MAIN_RHVT_0_reg(data)                                  (*((volatile unsigned int*)SS_MAIN_RHVT_0_reg)=data)
#define get_SS_MAIN_RHVT_0_reg                                        (*((volatile unsigned int*)SS_MAIN_RHVT_0_reg))
#define SS_MAIN_RHVT_0_dss_main_dss_rst_n_shift                       (31)
#define SS_MAIN_RHVT_0_dss_main_ro_sel_shift                          (25)
#define SS_MAIN_RHVT_0_dss_main_wire_sel_shift                        (24)
#define SS_MAIN_RHVT_0_dss_main_ready_shift                           (20)
#define SS_MAIN_RHVT_0_dss_main_count_out_shift                       (0)
#define SS_MAIN_RHVT_0_dss_main_dss_rst_n_mask                        (0x80000000)
#define SS_MAIN_RHVT_0_dss_main_ro_sel_mask                           (0x0E000000)
#define SS_MAIN_RHVT_0_dss_main_wire_sel_mask                         (0x01000000)
#define SS_MAIN_RHVT_0_dss_main_ready_mask                            (0x00100000)
#define SS_MAIN_RHVT_0_dss_main_count_out_mask                        (0x000FFFFF)
#define SS_MAIN_RHVT_0_dss_main_dss_rst_n(data)                       (0x80000000&((data)<<31))
#define SS_MAIN_RHVT_0_dss_main_ro_sel(data)                          (0x0E000000&((data)<<25))
#define SS_MAIN_RHVT_0_dss_main_wire_sel(data)                        (0x01000000&((data)<<24))
#define SS_MAIN_RHVT_0_dss_main_ready(data)                           (0x00100000&((data)<<20))
#define SS_MAIN_RHVT_0_dss_main_count_out(data)                       (0x000FFFFF&(data))
#define SS_MAIN_RHVT_0_get_dss_main_dss_rst_n(data)                   ((0x80000000&(data))>>31)
#define SS_MAIN_RHVT_0_get_dss_main_ro_sel(data)                      ((0x0E000000&(data))>>25)
#define SS_MAIN_RHVT_0_get_dss_main_wire_sel(data)                    ((0x01000000&(data))>>24)
#define SS_MAIN_RHVT_0_get_dss_main_ready(data)                       ((0x00100000&(data))>>20)
#define SS_MAIN_RHVT_0_get_dss_main_count_out(data)                   (0x000FFFFF&(data))


#define SS_MAIN_RHVT_1                                                0x180002b4
#define SS_MAIN_RHVT_1_reg_addr                                       "0xb80002b4"
#define SS_MAIN_RHVT_1_reg                                            0xb80002b4
#define SS_MAIN_RHVT_1_inst_addr                                      "0x00AD"
#define SS_MAIN_RHVT_1_inst                                           0x00AD
#define set_SS_MAIN_RHVT_1_reg(data)                                  (*((volatile unsigned int*)SS_MAIN_RHVT_1_reg)=data)
#define get_SS_MAIN_RHVT_1_reg                                        (*((volatile unsigned int*)SS_MAIN_RHVT_1_reg))
#define SS_MAIN_RHVT_1_dss_main_speed_en_shift                        (21)
#define SS_MAIN_RHVT_1_dss_main_wsort_go_shift                        (20)
#define SS_MAIN_RHVT_1_dss_main_data_in_shift                         (0)
#define SS_MAIN_RHVT_1_dss_main_speed_en_mask                         (0x00200000)
#define SS_MAIN_RHVT_1_dss_main_wsort_go_mask                         (0x00100000)
#define SS_MAIN_RHVT_1_dss_main_data_in_mask                          (0x000FFFFF)
#define SS_MAIN_RHVT_1_dss_main_speed_en(data)                        (0x00200000&((data)<<21))
#define SS_MAIN_RHVT_1_dss_main_wsort_go(data)                        (0x00100000&((data)<<20))
#define SS_MAIN_RHVT_1_dss_main_data_in(data)                         (0x000FFFFF&(data))
#define SS_MAIN_RHVT_1_get_dss_main_speed_en(data)                    ((0x00200000&(data))>>21)
#define SS_MAIN_RHVT_1_get_dss_main_wsort_go(data)                    ((0x00100000&(data))>>20)
#define SS_MAIN_RHVT_1_get_dss_main_data_in(data)                     (0x000FFFFF&(data))


#define SS_MAIN_RHVT_2                                                0x180002b8
#define SS_MAIN_RHVT_2_reg_addr                                       "0xb80002b8"
#define SS_MAIN_RHVT_2_reg                                            0xb80002b8
#define SS_MAIN_RHVT_2_inst_addr                                      "0x00AE"
#define SS_MAIN_RHVT_2_inst                                           0x00AE
#define set_SS_MAIN_RHVT_2_reg(data)                                  (*((volatile unsigned int*)SS_MAIN_RHVT_2_reg)=data)
#define get_SS_MAIN_RHVT_2_reg                                        (*((volatile unsigned int*)SS_MAIN_RHVT_2_reg))
#define SS_MAIN_RHVT_2_dss_main_dbgo_shift                            (0)
#define SS_MAIN_RHVT_2_dss_main_dbgo_mask                             (0x0000FFFF)
#define SS_MAIN_RHVT_2_dss_main_dbgo(data)                            (0x0000FFFF&(data))
#define SS_MAIN_RHVT_2_get_dss_main_dbgo(data)                        (0x0000FFFF&(data))


#define SS_VCPU_RHVT_0                                                0x180002d0
#define SS_VCPU_RHVT_0_reg_addr                                       "0xb80002d0"
#define SS_VCPU_RHVT_0_reg                                            0xb80002d0
#define SS_VCPU_RHVT_0_inst_addr                                      "0x00B4"
#define SS_VCPU_RHVT_0_inst                                           0x00B4
#define set_SS_VCPU_RHVT_0_reg(data)                                  (*((volatile unsigned int*)SS_VCPU_RHVT_0_reg)=data)
#define get_SS_VCPU_RHVT_0_reg                                        (*((volatile unsigned int*)SS_VCPU_RHVT_0_reg))
#define SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n_shift                       (31)
#define SS_VCPU_RHVT_0_dss_vcpu_ro_sel_shift                          (25)
#define SS_VCPU_RHVT_0_dss_vcpu_wire_sel_shift                        (24)
#define SS_VCPU_RHVT_0_dss_vcpu_ready_shift                           (20)
#define SS_VCPU_RHVT_0_dss_vcpu_count_out_shift                       (0)
#define SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n_mask                        (0x80000000)
#define SS_VCPU_RHVT_0_dss_vcpu_ro_sel_mask                           (0x0E000000)
#define SS_VCPU_RHVT_0_dss_vcpu_wire_sel_mask                         (0x01000000)
#define SS_VCPU_RHVT_0_dss_vcpu_ready_mask                            (0x00100000)
#define SS_VCPU_RHVT_0_dss_vcpu_count_out_mask                        (0x000FFFFF)
#define SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n(data)                       (0x80000000&((data)<<31))
#define SS_VCPU_RHVT_0_dss_vcpu_ro_sel(data)                          (0x0E000000&((data)<<25))
#define SS_VCPU_RHVT_0_dss_vcpu_wire_sel(data)                        (0x01000000&((data)<<24))
#define SS_VCPU_RHVT_0_dss_vcpu_ready(data)                           (0x00100000&((data)<<20))
#define SS_VCPU_RHVT_0_dss_vcpu_count_out(data)                       (0x000FFFFF&(data))
#define SS_VCPU_RHVT_0_get_dss_vcpu_dss_rst_n(data)                   ((0x80000000&(data))>>31)
#define SS_VCPU_RHVT_0_get_dss_vcpu_ro_sel(data)                      ((0x0E000000&(data))>>25)
#define SS_VCPU_RHVT_0_get_dss_vcpu_wire_sel(data)                    ((0x01000000&(data))>>24)
#define SS_VCPU_RHVT_0_get_dss_vcpu_ready(data)                       ((0x00100000&(data))>>20)
#define SS_VCPU_RHVT_0_get_dss_vcpu_count_out(data)                   (0x000FFFFF&(data))


#define SS_VCPU_RHVT_1                                                0x180002d4
#define SS_VCPU_RHVT_1_reg_addr                                       "0xb80002d4"
#define SS_VCPU_RHVT_1_reg                                            0xb80002d4
#define SS_VCPU_RHVT_1_inst_addr                                      "0x00B5"
#define SS_VCPU_RHVT_1_inst                                           0x00B5
#define set_SS_VCPU_RHVT_1_reg(data)                                  (*((volatile unsigned int*)SS_VCPU_RHVT_1_reg)=data)
#define get_SS_VCPU_RHVT_1_reg                                        (*((volatile unsigned int*)SS_VCPU_RHVT_1_reg))
#define SS_VCPU_RHVT_1_dss_vcpu_speed_en_shift                        (21)
#define SS_VCPU_RHVT_1_dss_vcpu_wsort_go_shift                        (20)
#define SS_VCPU_RHVT_1_dss_vcpu_data_in_shift                         (0)
#define SS_VCPU_RHVT_1_dss_vcpu_speed_en_mask                         (0x00200000)
#define SS_VCPU_RHVT_1_dss_vcpu_wsort_go_mask                         (0x00100000)
#define SS_VCPU_RHVT_1_dss_vcpu_data_in_mask                          (0x000FFFFF)
#define SS_VCPU_RHVT_1_dss_vcpu_speed_en(data)                        (0x00200000&((data)<<21))
#define SS_VCPU_RHVT_1_dss_vcpu_wsort_go(data)                        (0x00100000&((data)<<20))
#define SS_VCPU_RHVT_1_dss_vcpu_data_in(data)                         (0x000FFFFF&(data))
#define SS_VCPU_RHVT_1_get_dss_vcpu_speed_en(data)                    ((0x00200000&(data))>>21)
#define SS_VCPU_RHVT_1_get_dss_vcpu_wsort_go(data)                    ((0x00100000&(data))>>20)
#define SS_VCPU_RHVT_1_get_dss_vcpu_data_in(data)                     (0x000FFFFF&(data))


#define SS_VCPU_RHVT_2                                                0x180002d8
#define SS_VCPU_RHVT_2_reg_addr                                       "0xb80002d8"
#define SS_VCPU_RHVT_2_reg                                            0xb80002d8
#define SS_VCPU_RHVT_2_inst_addr                                      "0x00B6"
#define SS_VCPU_RHVT_2_inst                                           0x00B6
#define set_SS_VCPU_RHVT_2_reg(data)                                  (*((volatile unsigned int*)SS_VCPU_RHVT_2_reg)=data)
#define get_SS_VCPU_RHVT_2_reg                                        (*((volatile unsigned int*)SS_VCPU_RHVT_2_reg))
#define SS_VCPU_RHVT_2_dss_vcpu_dbgo_shift                            (0)
#define SS_VCPU_RHVT_2_dss_vcpu_dbgo_mask                             (0x0000FFFF)
#define SS_VCPU_RHVT_2_dss_vcpu_dbgo(data)                            (0x0000FFFF&(data))
#define SS_VCPU_RHVT_2_get_dss_vcpu_dbgo(data)                        (0x0000FFFF&(data))


#define SS_ACPU_RHVT_0                                                0x180002e0
#define SS_ACPU_RHVT_0_reg_addr                                       "0xb80002e0"
#define SS_ACPU_RHVT_0_reg                                            0xb80002e0
#define SS_ACPU_RHVT_0_inst_addr                                      "0x00B8"
#define SS_ACPU_RHVT_0_inst                                           0x00B8
#define set_SS_ACPU_RHVT_0_reg(data)                                  (*((volatile unsigned int*)SS_ACPU_RHVT_0_reg)=data)
#define get_SS_ACPU_RHVT_0_reg                                        (*((volatile unsigned int*)SS_ACPU_RHVT_0_reg))
#define SS_ACPU_RHVT_0_dss_acpu_dss_rst_n_shift                       (31)
#define SS_ACPU_RHVT_0_dss_acpu_ro_sel_shift                          (25)
#define SS_ACPU_RHVT_0_dss_acpu_wire_sel_shift                        (24)
#define SS_ACPU_RHVT_0_dss_acpu_ready_shift                           (20)
#define SS_ACPU_RHVT_0_dss_acpu_count_out_shift                       (0)
#define SS_ACPU_RHVT_0_dss_acpu_dss_rst_n_mask                        (0x80000000)
#define SS_ACPU_RHVT_0_dss_acpu_ro_sel_mask                           (0x0E000000)
#define SS_ACPU_RHVT_0_dss_acpu_wire_sel_mask                         (0x01000000)
#define SS_ACPU_RHVT_0_dss_acpu_ready_mask                            (0x00100000)
#define SS_ACPU_RHVT_0_dss_acpu_count_out_mask                        (0x000FFFFF)
#define SS_ACPU_RHVT_0_dss_acpu_dss_rst_n(data)                       (0x80000000&((data)<<31))
#define SS_ACPU_RHVT_0_dss_acpu_ro_sel(data)                          (0x0E000000&((data)<<25))
#define SS_ACPU_RHVT_0_dss_acpu_wire_sel(data)                        (0x01000000&((data)<<24))
#define SS_ACPU_RHVT_0_dss_acpu_ready(data)                           (0x00100000&((data)<<20))
#define SS_ACPU_RHVT_0_dss_acpu_count_out(data)                       (0x000FFFFF&(data))
#define SS_ACPU_RHVT_0_get_dss_acpu_dss_rst_n(data)                   ((0x80000000&(data))>>31)
#define SS_ACPU_RHVT_0_get_dss_acpu_ro_sel(data)                      ((0x0E000000&(data))>>25)
#define SS_ACPU_RHVT_0_get_dss_acpu_wire_sel(data)                    ((0x01000000&(data))>>24)
#define SS_ACPU_RHVT_0_get_dss_acpu_ready(data)                       ((0x00100000&(data))>>20)
#define SS_ACPU_RHVT_0_get_dss_acpu_count_out(data)                   (0x000FFFFF&(data))


#define SS_ACPU_RHVT_1                                                0x180002e4
#define SS_ACPU_RHVT_1_reg_addr                                       "0xb80002e4"
#define SS_ACPU_RHVT_1_reg                                            0xb80002e4
#define SS_ACPU_RHVT_1_inst_addr                                      "0x00B9"
#define SS_ACPU_RHVT_1_inst                                           0x00B9
#define set_SS_ACPU_RHVT_1_reg(data)                                  (*((volatile unsigned int*)SS_ACPU_RHVT_1_reg)=data)
#define get_SS_ACPU_RHVT_1_reg                                        (*((volatile unsigned int*)SS_ACPU_RHVT_1_reg))
#define SS_ACPU_RHVT_1_dss_acpu_speed_en_shift                        (21)
#define SS_ACPU_RHVT_1_dss_acpu_wsort_go_shift                        (20)
#define SS_ACPU_RHVT_1_dss_acpu_data_in_shift                         (0)
#define SS_ACPU_RHVT_1_dss_acpu_speed_en_mask                         (0x00200000)
#define SS_ACPU_RHVT_1_dss_acpu_wsort_go_mask                         (0x00100000)
#define SS_ACPU_RHVT_1_dss_acpu_data_in_mask                          (0x000FFFFF)
#define SS_ACPU_RHVT_1_dss_acpu_speed_en(data)                        (0x00200000&((data)<<21))
#define SS_ACPU_RHVT_1_dss_acpu_wsort_go(data)                        (0x00100000&((data)<<20))
#define SS_ACPU_RHVT_1_dss_acpu_data_in(data)                         (0x000FFFFF&(data))
#define SS_ACPU_RHVT_1_get_dss_acpu_speed_en(data)                    ((0x00200000&(data))>>21)
#define SS_ACPU_RHVT_1_get_dss_acpu_wsort_go(data)                    ((0x00100000&(data))>>20)
#define SS_ACPU_RHVT_1_get_dss_acpu_data_in(data)                     (0x000FFFFF&(data))


#define SS_ACPU_RHVT_2                                                0x180002e8
#define SS_ACPU_RHVT_2_reg_addr                                       "0xb80002e8"
#define SS_ACPU_RHVT_2_reg                                            0xb80002e8
#define SS_ACPU_RHVT_2_inst_addr                                      "0x00BA"
#define SS_ACPU_RHVT_2_inst                                           0x00BA
#define set_SS_ACPU_RHVT_2_reg(data)                                  (*((volatile unsigned int*)SS_ACPU_RHVT_2_reg)=data)
#define get_SS_ACPU_RHVT_2_reg                                        (*((volatile unsigned int*)SS_ACPU_RHVT_2_reg))
#define SS_ACPU_RHVT_2_dss_acpu_dbgo_shift                            (0)
#define SS_ACPU_RHVT_2_dss_acpu_dbgo_mask                             (0x0000FFFF)
#define SS_ACPU_RHVT_2_dss_acpu_dbgo(data)                            (0x0000FFFF&(data))
#define SS_ACPU_RHVT_2_get_dss_acpu_dbgo(data)                        (0x0000FFFF&(data))


#define SS_TVSB2_RHVT_0                                               0x180002f0
#define SS_TVSB2_RHVT_0_reg_addr                                      "0xb80002f0"
#define SS_TVSB2_RHVT_0_reg                                           0xb80002f0
#define SS_TVSB2_RHVT_0_inst_addr                                     "0x00BC"
#define SS_TVSB2_RHVT_0_inst                                          0x00BC
#define set_SS_TVSB2_RHVT_0_reg(data)                                 (*((volatile unsigned int*)SS_TVSB2_RHVT_0_reg)=data)
#define get_SS_TVSB2_RHVT_0_reg                                       (*((volatile unsigned int*)SS_TVSB2_RHVT_0_reg))
#define SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n_shift                     (31)
#define SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel_shift                        (25)
#define SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel_shift                      (24)
#define SS_TVSB2_RHVT_0_dss_tvsb2_ready_shift                         (20)
#define SS_TVSB2_RHVT_0_dss_tvsb2_count_out_shift                     (0)
#define SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n_mask                      (0x80000000)
#define SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel_mask                         (0x0E000000)
#define SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel_mask                       (0x01000000)
#define SS_TVSB2_RHVT_0_dss_tvsb2_ready_mask                          (0x00100000)
#define SS_TVSB2_RHVT_0_dss_tvsb2_count_out_mask                      (0x000FFFFF)
#define SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n(data)                     (0x80000000&((data)<<31))
#define SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel(data)                        (0x0E000000&((data)<<25))
#define SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel(data)                      (0x01000000&((data)<<24))
#define SS_TVSB2_RHVT_0_dss_tvsb2_ready(data)                         (0x00100000&((data)<<20))
#define SS_TVSB2_RHVT_0_dss_tvsb2_count_out(data)                     (0x000FFFFF&(data))
#define SS_TVSB2_RHVT_0_get_dss_tvsb2_dss_rst_n(data)                 ((0x80000000&(data))>>31)
#define SS_TVSB2_RHVT_0_get_dss_tvsb2_ro_sel(data)                    ((0x0E000000&(data))>>25)
#define SS_TVSB2_RHVT_0_get_dss_tvsb2_wire_sel(data)                  ((0x01000000&(data))>>24)
#define SS_TVSB2_RHVT_0_get_dss_tvsb2_ready(data)                     ((0x00100000&(data))>>20)
#define SS_TVSB2_RHVT_0_get_dss_tvsb2_count_out(data)                 (0x000FFFFF&(data))


#define SS_TVSB2_RHVT_1                                               0x180002f4
#define SS_TVSB2_RHVT_1_reg_addr                                      "0xb80002f4"
#define SS_TVSB2_RHVT_1_reg                                           0xb80002f4
#define SS_TVSB2_RHVT_1_inst_addr                                     "0x00BD"
#define SS_TVSB2_RHVT_1_inst                                          0x00BD
#define set_SS_TVSB2_RHVT_1_reg(data)                                 (*((volatile unsigned int*)SS_TVSB2_RHVT_1_reg)=data)
#define get_SS_TVSB2_RHVT_1_reg                                       (*((volatile unsigned int*)SS_TVSB2_RHVT_1_reg))
#define SS_TVSB2_RHVT_1_dss_tvsb2_speed_en_shift                      (21)
#define SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go_shift                      (20)
#define SS_TVSB2_RHVT_1_dss_tvsb2_data_in_shift                       (0)
#define SS_TVSB2_RHVT_1_dss_tvsb2_speed_en_mask                       (0x00200000)
#define SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go_mask                       (0x00100000)
#define SS_TVSB2_RHVT_1_dss_tvsb2_data_in_mask                        (0x000FFFFF)
#define SS_TVSB2_RHVT_1_dss_tvsb2_speed_en(data)                      (0x00200000&((data)<<21))
#define SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go(data)                      (0x00100000&((data)<<20))
#define SS_TVSB2_RHVT_1_dss_tvsb2_data_in(data)                       (0x000FFFFF&(data))
#define SS_TVSB2_RHVT_1_get_dss_tvsb2_speed_en(data)                  ((0x00200000&(data))>>21)
#define SS_TVSB2_RHVT_1_get_dss_tvsb2_wsort_go(data)                  ((0x00100000&(data))>>20)
#define SS_TVSB2_RHVT_1_get_dss_tvsb2_data_in(data)                   (0x000FFFFF&(data))


#define SS_TVSB2_RHVT_2                                               0x180002f8
#define SS_TVSB2_RHVT_2_reg_addr                                      "0xb80002f8"
#define SS_TVSB2_RHVT_2_reg                                           0xb80002f8
#define SS_TVSB2_RHVT_2_inst_addr                                     "0x00BE"
#define SS_TVSB2_RHVT_2_inst                                          0x00BE
#define set_SS_TVSB2_RHVT_2_reg(data)                                 (*((volatile unsigned int*)SS_TVSB2_RHVT_2_reg)=data)
#define get_SS_TVSB2_RHVT_2_reg                                       (*((volatile unsigned int*)SS_TVSB2_RHVT_2_reg))
#define SS_TVSB2_RHVT_2_dss_tvsb2_dbgo_shift                          (0)
#define SS_TVSB2_RHVT_2_dss_tvsb2_dbgo_mask                           (0x0000FFFF)
#define SS_TVSB2_RHVT_2_dss_tvsb2_dbgo(data)                          (0x0000FFFF&(data))
#define SS_TVSB2_RHVT_2_get_dss_tvsb2_dbgo(data)                      (0x0000FFFF&(data))


#define VOLTAGE_STROBE_CTRL                                           0x18000300
#define VOLTAGE_STROBE_CTRL_reg_addr                                  "0xb8000300"
#define VOLTAGE_STROBE_CTRL_reg                                       0xb8000300
#define VOLTAGE_STROBE_CTRL_inst_addr                                 "0x00C0"
#define VOLTAGE_STROBE_CTRL_inst                                      0x00C0
#define set_VOLTAGE_STROBE_CTRL_reg(data)                             (*((volatile unsigned int*)VOLTAGE_STROBE_CTRL_reg)=data)
#define get_VOLTAGE_STROBE_CTRL_reg                                   (*((volatile unsigned int*)VOLTAGE_STROBE_CTRL_reg))
#define VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en_shift              (8)
#define VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_shift              (4)
#define VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en_shift             (0)
#define VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en_mask               (0x00000100)
#define VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_mask               (0x00000010)
#define VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en_mask              (0x00000001)
#define VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en(data)              (0x00000100&((data)<<8))
#define VOLTAGE_STROBE_CTRL_main_voltage_strobe_en(data)              (0x00000010&((data)<<4))
#define VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en(data)             (0x00000001&(data))
#define VOLTAGE_STROBE_CTRL_get_vcpu_voltage_strobe_en(data)          ((0x00000100&(data))>>8)
#define VOLTAGE_STROBE_CTRL_get_main_voltage_strobe_en(data)          ((0x00000010&(data))>>4)
#define VOLTAGE_STROBE_CTRL_get_tvsb2_voltage_strobe_en(data)         (0x00000001&(data))


#define SC_DEBUG_0                                                    0x18000310
#define SC_DEBUG_0_reg_addr                                           "0xb8000310"
#define SC_DEBUG_0_reg                                                0xb8000310
#define SC_DEBUG_0_inst_addr                                          "0x00C4"
#define SC_DEBUG_0_inst                                               0x00C4
#define set_SC_DEBUG_0_reg(data)                                      (*((volatile unsigned int*)SC_DEBUG_0_reg)=data)
#define get_SC_DEBUG_0_reg                                            (*((volatile unsigned int*)SC_DEBUG_0_reg))
#define SC_DEBUG_0_pll_dbg_en_shift                                   (28)
#define SC_DEBUG_0_dbg0_div_sel_shift                                 (16)
#define SC_DEBUG_0_top_ssc_dbg_sel_shift                              (8)
#define SC_DEBUG_0_crt_dbg_sel_shift                                  (0)
#define SC_DEBUG_0_pll_dbg_en_mask                                    (0x10000000)
#define SC_DEBUG_0_dbg0_div_sel_mask                                  (0x00030000)
#define SC_DEBUG_0_top_ssc_dbg_sel_mask                               (0x00000F00)
#define SC_DEBUG_0_crt_dbg_sel_mask                                   (0x000000FF)
#define SC_DEBUG_0_pll_dbg_en(data)                                   (0x10000000&((data)<<28))
#define SC_DEBUG_0_dbg0_div_sel(data)                                 (0x00030000&((data)<<16))
#define SC_DEBUG_0_top_ssc_dbg_sel(data)                              (0x00000F00&((data)<<8))
#define SC_DEBUG_0_crt_dbg_sel(data)                                  (0x000000FF&(data))
#define SC_DEBUG_0_get_pll_dbg_en(data)                               ((0x10000000&(data))>>28)
#define SC_DEBUG_0_get_dbg0_div_sel(data)                             ((0x00030000&(data))>>16)
#define SC_DEBUG_0_get_top_ssc_dbg_sel(data)                          ((0x00000F00&(data))>>8)
#define SC_DEBUG_0_get_crt_dbg_sel(data)                              (0x000000FF&(data))


#define TEMP_SENSOR_1                                                 0x18000380
#define TEMP_SENSOR_1_reg_addr                                        "0xb8000380"
#define TEMP_SENSOR_1_reg                                             0xb8000380
#define TEMP_SENSOR_1_inst_addr                                       "0x00E0"
#define TEMP_SENSOR_1_inst                                            0x00E0
#define set_TEMP_SENSOR_1_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_1_reg)=data)
#define get_TEMP_SENSOR_1_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_1_reg))
#define TEMP_SENSOR_1_tm_a_shift                                      (0)
#define TEMP_SENSOR_1_tm_a_mask                                       (0x1FFFFFFF)
#define TEMP_SENSOR_1_tm_a(data)                                      (0x1FFFFFFF&(data))
#define TEMP_SENSOR_1_get_tm_a(data)                                  (0x1FFFFFFF&(data))


#define TEMP_SENSOR_2                                                 0x18000384
#define TEMP_SENSOR_2_reg_addr                                        "0xb8000384"
#define TEMP_SENSOR_2_reg                                             0xb8000384
#define TEMP_SENSOR_2_inst_addr                                       "0x00E1"
#define TEMP_SENSOR_2_inst                                            0x00E1
#define set_TEMP_SENSOR_2_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_2_reg)=data)
#define get_TEMP_SENSOR_2_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_2_reg))
#define TEMP_SENSOR_2_tm_b_shift                                      (10)
#define TEMP_SENSOR_2_tm_adccksel_shift                               (7)
#define TEMP_SENSOR_2_tm_cal_en_shift                                 (6)
#define TEMP_SENSOR_2_tm_biaschop_shift                               (5)
#define TEMP_SENSOR_2_tm_chopen_shift                                 (4)
#define TEMP_SENSOR_2_tm_cksourcesel_shift                            (3)
#define TEMP_SENSOR_2_tm_dsr_shift                                    (0)
#define TEMP_SENSOR_2_tm_b_mask                                       (0xFFFFFC00)
#define TEMP_SENSOR_2_tm_adccksel_mask                                (0x00000380)
#define TEMP_SENSOR_2_tm_cal_en_mask                                  (0x00000040)
#define TEMP_SENSOR_2_tm_biaschop_mask                                (0x00000020)
#define TEMP_SENSOR_2_tm_chopen_mask                                  (0x00000010)
#define TEMP_SENSOR_2_tm_cksourcesel_mask                             (0x00000008)
#define TEMP_SENSOR_2_tm_dsr_mask                                     (0x00000007)
#define TEMP_SENSOR_2_tm_b(data)                                      (0xFFFFFC00&((data)<<10))
#define TEMP_SENSOR_2_tm_adccksel(data)                               (0x00000380&((data)<<7))
#define TEMP_SENSOR_2_tm_cal_en(data)                                 (0x00000040&((data)<<6))
#define TEMP_SENSOR_2_tm_biaschop(data)                               (0x00000020&((data)<<5))
#define TEMP_SENSOR_2_tm_chopen(data)                                 (0x00000010&((data)<<4))
#define TEMP_SENSOR_2_tm_cksourcesel(data)                            (0x00000008&((data)<<3))
#define TEMP_SENSOR_2_tm_dsr(data)                                    (0x00000007&(data))
#define TEMP_SENSOR_2_get_tm_b(data)                                  ((0xFFFFFC00&(data))>>10)
#define TEMP_SENSOR_2_get_tm_adccksel(data)                           ((0x00000380&(data))>>7)
#define TEMP_SENSOR_2_get_tm_cal_en(data)                             ((0x00000040&(data))>>6)
#define TEMP_SENSOR_2_get_tm_biaschop(data)                           ((0x00000020&(data))>>5)
#define TEMP_SENSOR_2_get_tm_chopen(data)                             ((0x00000010&(data))>>4)
#define TEMP_SENSOR_2_get_tm_cksourcesel(data)                        ((0x00000008&(data))>>3)
#define TEMP_SENSOR_2_get_tm_dsr(data)                                (0x00000007&(data))


#define TEMP_SENSOR_3                                                 0x18000388
#define TEMP_SENSOR_3_reg_addr                                        "0xb8000388"
#define TEMP_SENSOR_3_reg                                             0xb8000388
#define TEMP_SENSOR_3_inst_addr                                       "0x00E2"
#define TEMP_SENSOR_3_inst                                            0x00E2
#define set_TEMP_SENSOR_3_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_3_reg)=data)
#define get_TEMP_SENSOR_3_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_3_reg))
#define TEMP_SENSOR_3_dummy18000388_31_shift                          (31)
#define TEMP_SENSOR_3_tm_filteredgesel_shift                          (30)
#define TEMP_SENSOR_3_tm_hold_en_shift                                (29)
#define TEMP_SENSOR_3_tm_order3_shift                                 (28)
#define TEMP_SENSOR_3_tm_offset_shift                                 (6)
#define TEMP_SENSOR_3_tm_pow_shift                                    (5)
#define TEMP_SENSOR_3_dummy18000388_31_mask                           (0x80000000)
#define TEMP_SENSOR_3_tm_filteredgesel_mask                           (0x40000000)
#define TEMP_SENSOR_3_tm_hold_en_mask                                 (0x20000000)
#define TEMP_SENSOR_3_tm_order3_mask                                  (0x10000000)
#define TEMP_SENSOR_3_tm_offset_mask                                  (0x0FFFFFC0)
#define TEMP_SENSOR_3_tm_pow_mask                                     (0x00000020)
#define TEMP_SENSOR_3_dummy18000388_31(data)                          (0x80000000&((data)<<31))
#define TEMP_SENSOR_3_tm_filteredgesel(data)                          (0x40000000&((data)<<30))
#define TEMP_SENSOR_3_tm_hold_en(data)                                (0x20000000&((data)<<29))
#define TEMP_SENSOR_3_tm_order3(data)                                 (0x10000000&((data)<<28))
#define TEMP_SENSOR_3_tm_offset(data)                                 (0x0FFFFFC0&((data)<<6))
#define TEMP_SENSOR_3_tm_pow(data)                                    (0x00000020&((data)<<5))
#define TEMP_SENSOR_3_get_dummy18000388_31(data)                      ((0x80000000&(data))>>31)
#define TEMP_SENSOR_3_get_tm_filteredgesel(data)                      ((0x40000000&(data))>>30)
#define TEMP_SENSOR_3_get_tm_hold_en(data)                            ((0x20000000&(data))>>29)
#define TEMP_SENSOR_3_get_tm_order3(data)                             ((0x10000000&(data))>>28)
#define TEMP_SENSOR_3_get_tm_offset(data)                             ((0x0FFFFFC0&(data))>>6)
#define TEMP_SENSOR_3_get_tm_pow(data)                                ((0x00000020&(data))>>5)


#define TEMP_SENSOR_4                                                 0x1800038c
#define TEMP_SENSOR_4_reg_addr                                        "0xb800038c"
#define TEMP_SENSOR_4_reg                                             0xb800038c
#define TEMP_SENSOR_4_inst_addr                                       "0x00E3"
#define TEMP_SENSOR_4_inst                                            0x00E3
#define set_TEMP_SENSOR_4_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_4_reg)=data)
#define get_TEMP_SENSOR_4_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_4_reg))
#define TEMP_SENSOR_4_tm_r_shift                                      (8)
#define TEMP_SENSOR_4_tm_opcursel_shift                               (6)
#define TEMP_SENSOR_4_tm_hold_dly_shift                               (4)
#define TEMP_SENSOR_4_tm_osccursel_shift                              (2)
#define TEMP_SENSOR_4_tm_resol_shift                                  (0)
#define TEMP_SENSOR_4_tm_r_mask                                       (0xFFFFFF00)
#define TEMP_SENSOR_4_tm_opcursel_mask                                (0x000000C0)
#define TEMP_SENSOR_4_tm_hold_dly_mask                                (0x00000030)
#define TEMP_SENSOR_4_tm_osccursel_mask                               (0x0000000C)
#define TEMP_SENSOR_4_tm_resol_mask                                   (0x00000003)
#define TEMP_SENSOR_4_tm_r(data)                                      (0xFFFFFF00&((data)<<8))
#define TEMP_SENSOR_4_tm_opcursel(data)                               (0x000000C0&((data)<<6))
#define TEMP_SENSOR_4_tm_hold_dly(data)                               (0x00000030&((data)<<4))
#define TEMP_SENSOR_4_tm_osccursel(data)                              (0x0000000C&((data)<<2))
#define TEMP_SENSOR_4_tm_resol(data)                                  (0x00000003&(data))
#define TEMP_SENSOR_4_get_tm_r(data)                                  ((0xFFFFFF00&(data))>>8)
#define TEMP_SENSOR_4_get_tm_opcursel(data)                           ((0x000000C0&(data))>>6)
#define TEMP_SENSOR_4_get_tm_hold_dly(data)                           ((0x00000030&(data))>>4)
#define TEMP_SENSOR_4_get_tm_osccursel(data)                          ((0x0000000C&(data))>>2)
#define TEMP_SENSOR_4_get_tm_resol(data)                              (0x00000003&(data))


#define TEMP_SENSOR_5                                                 0x18000390
#define TEMP_SENSOR_5_reg_addr                                        "0xb8000390"
#define TEMP_SENSOR_5_reg                                             0xb8000390
#define TEMP_SENSOR_5_inst_addr                                       "0x00E4"
#define TEMP_SENSOR_5_inst                                            0x00E4
#define set_TEMP_SENSOR_5_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_5_reg)=data)
#define get_TEMP_SENSOR_5_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_5_reg))
#define TEMP_SENSOR_5_tm_rstb_shift                                   (31)
#define TEMP_SENSOR_5_tm_sdm_test_shift                               (30)
#define TEMP_SENSOR_5_tm_sdm_test_en_shift                            (29)
#define TEMP_SENSOR_5_tm_test_en_shift                                (28)
#define TEMP_SENSOR_5_tm_vcmsel_shift                                 (25)
#define TEMP_SENSOR_5_tm_vbe_biassel_shift                            (23)
#define TEMP_SENSOR_5_tm_chopfreqsel_shift                            (12)
#define TEMP_SENSOR_5_dummy18000390_8_4_shift                         (4)
#define TEMP_SENSOR_5_dummy18000390_0_shift                           (0)
#define TEMP_SENSOR_5_tm_rstb_mask                                    (0x80000000)
#define TEMP_SENSOR_5_tm_sdm_test_mask                                (0x40000000)
#define TEMP_SENSOR_5_tm_sdm_test_en_mask                             (0x20000000)
#define TEMP_SENSOR_5_tm_test_en_mask                                 (0x10000000)
#define TEMP_SENSOR_5_tm_vcmsel_mask                                  (0x0E000000)
#define TEMP_SENSOR_5_tm_vbe_biassel_mask                             (0x01800000)
#define TEMP_SENSOR_5_tm_chopfreqsel_mask                             (0x007FF000)
#define TEMP_SENSOR_5_dummy18000390_8_4_mask                          (0x000001F0)
#define TEMP_SENSOR_5_dummy18000390_0_mask                            (0x00000001)
#define TEMP_SENSOR_5_tm_rstb(data)                                   (0x80000000&((data)<<31))
#define TEMP_SENSOR_5_tm_sdm_test(data)                               (0x40000000&((data)<<30))
#define TEMP_SENSOR_5_tm_sdm_test_en(data)                            (0x20000000&((data)<<29))
#define TEMP_SENSOR_5_tm_test_en(data)                                (0x10000000&((data)<<28))
#define TEMP_SENSOR_5_tm_vcmsel(data)                                 (0x0E000000&((data)<<25))
#define TEMP_SENSOR_5_tm_vbe_biassel(data)                            (0x01800000&((data)<<23))
#define TEMP_SENSOR_5_tm_chopfreqsel(data)                            (0x007FF000&((data)<<12))
#define TEMP_SENSOR_5_dummy18000390_8_4(data)                         (0x000001F0&((data)<<4))
#define TEMP_SENSOR_5_dummy18000390_0(data)                           (0x00000001&(data))
#define TEMP_SENSOR_5_get_tm_rstb(data)                               ((0x80000000&(data))>>31)
#define TEMP_SENSOR_5_get_tm_sdm_test(data)                           ((0x40000000&(data))>>30)
#define TEMP_SENSOR_5_get_tm_sdm_test_en(data)                        ((0x20000000&(data))>>29)
#define TEMP_SENSOR_5_get_tm_test_en(data)                            ((0x10000000&(data))>>28)
#define TEMP_SENSOR_5_get_tm_vcmsel(data)                             ((0x0E000000&(data))>>25)
#define TEMP_SENSOR_5_get_tm_vbe_biassel(data)                        ((0x01800000&(data))>>23)
#define TEMP_SENSOR_5_get_tm_chopfreqsel(data)                        ((0x007FF000&(data))>>12)
#define TEMP_SENSOR_5_get_dummy18000390_8_4(data)                     ((0x000001F0&(data))>>4)
#define TEMP_SENSOR_5_get_dummy18000390_0(data)                       (0x00000001&(data))


#define TEMP_SENSOR_6                                                 0x18000394
#define TEMP_SENSOR_6_reg_addr                                        "0xb8000394"
#define TEMP_SENSOR_6_reg                                             0xb8000394
#define TEMP_SENSOR_6_inst_addr                                       "0x00E5"
#define TEMP_SENSOR_6_inst                                            0x00E5
#define set_TEMP_SENSOR_6_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_6_reg)=data)
#define get_TEMP_SENSOR_6_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_6_reg))
#define TEMP_SENSOR_6_dummy18000394_31_16_shift                       (16)
#define TEMP_SENSOR_6_dummy18000394_15_0_shift                        (0)
#define TEMP_SENSOR_6_dummy18000394_31_16_mask                        (0xFFFF0000)
#define TEMP_SENSOR_6_dummy18000394_15_0_mask                         (0x0000FFFF)
#define TEMP_SENSOR_6_dummy18000394_31_16(data)                       (0xFFFF0000&((data)<<16))
#define TEMP_SENSOR_6_dummy18000394_15_0(data)                        (0x0000FFFF&(data))
#define TEMP_SENSOR_6_get_dummy18000394_31_16(data)                   ((0xFFFF0000&(data))>>16)
#define TEMP_SENSOR_6_get_dummy18000394_15_0(data)                    (0x0000FFFF&(data))


#define TEMP_SENSOR_7                                                 0x18000398
#define TEMP_SENSOR_7_reg_addr                                        "0xb8000398"
#define TEMP_SENSOR_7_reg                                             0xb8000398
#define TEMP_SENSOR_7_inst_addr                                       "0x00E6"
#define TEMP_SENSOR_7_inst                                            0x00E6
#define set_TEMP_SENSOR_7_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_7_reg)=data)
#define get_TEMP_SENSOR_7_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_7_reg))
#define TEMP_SENSOR_7_dummy18000398_31_16_shift                       (16)
#define TEMP_SENSOR_7_dummy18000398_15_shift                          (15)
#define TEMP_SENSOR_7_dummy18000398_14_12_shift                       (12)
#define TEMP_SENSOR_7_dummy18000398_11_10_shift                       (10)
#define TEMP_SENSOR_7_dummy18000398_9_7_shift                         (7)
#define TEMP_SENSOR_7_dummy18000398_6_shift                           (6)
#define TEMP_SENSOR_7_dummy18000398_5_shift                           (5)
#define TEMP_SENSOR_7_dummy18000398_4_shift                           (4)
#define TEMP_SENSOR_7_tm_biasdem_sel_shift                            (3)
#define TEMP_SENSOR_7_td_wrep_edge_sel_shift                          (1)
#define TEMP_SENSOR_7_dummy18000398_0_shift                           (0)
#define TEMP_SENSOR_7_dummy18000398_31_16_mask                        (0xFFFF0000)
#define TEMP_SENSOR_7_dummy18000398_15_mask                           (0x00008000)
#define TEMP_SENSOR_7_dummy18000398_14_12_mask                        (0x00007000)
#define TEMP_SENSOR_7_dummy18000398_11_10_mask                        (0x00000C00)
#define TEMP_SENSOR_7_dummy18000398_9_7_mask                          (0x00000380)
#define TEMP_SENSOR_7_dummy18000398_6_mask                            (0x00000040)
#define TEMP_SENSOR_7_dummy18000398_5_mask                            (0x00000020)
#define TEMP_SENSOR_7_dummy18000398_4_mask                            (0x00000010)
#define TEMP_SENSOR_7_tm_biasdem_sel_mask                             (0x00000008)
#define TEMP_SENSOR_7_td_wrep_edge_sel_mask                           (0x00000002)
#define TEMP_SENSOR_7_dummy18000398_0_mask                            (0x00000001)
#define TEMP_SENSOR_7_dummy18000398_31_16(data)                       (0xFFFF0000&((data)<<16))
#define TEMP_SENSOR_7_dummy18000398_15(data)                          (0x00008000&((data)<<15))
#define TEMP_SENSOR_7_dummy18000398_14_12(data)                       (0x00007000&((data)<<12))
#define TEMP_SENSOR_7_dummy18000398_11_10(data)                       (0x00000C00&((data)<<10))
#define TEMP_SENSOR_7_dummy18000398_9_7(data)                         (0x00000380&((data)<<7))
#define TEMP_SENSOR_7_dummy18000398_6(data)                           (0x00000040&((data)<<6))
#define TEMP_SENSOR_7_dummy18000398_5(data)                           (0x00000020&((data)<<5))
#define TEMP_SENSOR_7_dummy18000398_4(data)                           (0x00000010&((data)<<4))
#define TEMP_SENSOR_7_tm_biasdem_sel(data)                            (0x00000008&((data)<<3))
#define TEMP_SENSOR_7_td_wrep_edge_sel(data)                          (0x00000002&((data)<<1))
#define TEMP_SENSOR_7_dummy18000398_0(data)                           (0x00000001&(data))
#define TEMP_SENSOR_7_get_dummy18000398_31_16(data)                   ((0xFFFF0000&(data))>>16)
#define TEMP_SENSOR_7_get_dummy18000398_15(data)                      ((0x00008000&(data))>>15)
#define TEMP_SENSOR_7_get_dummy18000398_14_12(data)                   ((0x00007000&(data))>>12)
#define TEMP_SENSOR_7_get_dummy18000398_11_10(data)                   ((0x00000C00&(data))>>10)
#define TEMP_SENSOR_7_get_dummy18000398_9_7(data)                     ((0x00000380&(data))>>7)
#define TEMP_SENSOR_7_get_dummy18000398_6(data)                       ((0x00000040&(data))>>6)
#define TEMP_SENSOR_7_get_dummy18000398_5(data)                       ((0x00000020&(data))>>5)
#define TEMP_SENSOR_7_get_dummy18000398_4(data)                       ((0x00000010&(data))>>4)
#define TEMP_SENSOR_7_get_tm_biasdem_sel(data)                        ((0x00000008&(data))>>3)
#define TEMP_SENSOR_7_get_td_wrep_edge_sel(data)                      ((0x00000002&(data))>>1)
#define TEMP_SENSOR_7_get_dummy18000398_0(data)                       (0x00000001&(data))


#define TEMP_SENSOR_8                                                 0x1800039c
#define TEMP_SENSOR_8_reg_addr                                        "0xb800039c"
#define TEMP_SENSOR_8_reg                                             0xb800039c
#define TEMP_SENSOR_8_inst_addr                                       "0x00E7"
#define TEMP_SENSOR_8_inst                                            0x00E7
#define set_TEMP_SENSOR_8_reg(data)                                   (*((volatile unsigned int*)TEMP_SENSOR_8_reg)=data)
#define get_TEMP_SENSOR_8_reg                                         (*((volatile unsigned int*)TEMP_SENSOR_8_reg))
#define TEMP_SENSOR_8_tm_s_shift                                      (0)
#define TEMP_SENSOR_8_tm_s_mask                                       (0x007FFFFF)
#define TEMP_SENSOR_8_tm_s(data)                                      (0x007FFFFF&(data))
#define TEMP_SENSOR_8_get_tm_s(data)                                  (0x007FFFFF&(data))


#define THERMAL_RESULT_1                                              0x180003a0
#define THERMAL_RESULT_1_reg_addr                                     "0xb80003a0"
#define THERMAL_RESULT_1_reg                                          0xb80003a0
#define THERMAL_RESULT_1_inst_addr                                    "0x00E8"
#define THERMAL_RESULT_1_inst                                         0x00E8
#define set_THERMAL_RESULT_1_reg(data)                                (*((volatile unsigned int*)THERMAL_RESULT_1_reg)=data)
#define get_THERMAL_RESULT_1_reg                                      (*((volatile unsigned int*)THERMAL_RESULT_1_reg))
#define THERMAL_RESULT_1_dummy180003a0_30_24_shift                    (24)
#define THERMAL_RESULT_1_ct_out_o_tm_shift                            (0)
#define THERMAL_RESULT_1_dummy180003a0_30_24_mask                     (0x7F000000)
#define THERMAL_RESULT_1_ct_out_o_tm_mask                             (0x0007FFFF)
#define THERMAL_RESULT_1_dummy180003a0_30_24(data)                    (0x7F000000&((data)<<24))
#define THERMAL_RESULT_1_ct_out_o_tm(data)                            (0x0007FFFF&(data))
#define THERMAL_RESULT_1_get_dummy180003a0_30_24(data)                ((0x7F000000&(data))>>24)
#define THERMAL_RESULT_1_get_ct_out_o_tm(data)                        (0x0007FFFF&(data))


#define THERMAL_RESULT_2                                              0x180003a4
#define THERMAL_RESULT_2_reg_addr                                     "0xb80003a4"
#define THERMAL_RESULT_2_reg                                          0xb80003a4
#define THERMAL_RESULT_2_inst_addr                                    "0x00E9"
#define THERMAL_RESULT_2_inst                                         0x00E9
#define set_THERMAL_RESULT_2_reg(data)                                (*((volatile unsigned int*)THERMAL_RESULT_2_reg)=data)
#define get_THERMAL_RESULT_2_reg                                      (*((volatile unsigned int*)THERMAL_RESULT_2_reg))
#define THERMAL_RESULT_2_u_out_tm_shift                               (0)
#define THERMAL_RESULT_2_u_out_tm_mask                                (0x003FFFFF)
#define THERMAL_RESULT_2_u_out_tm(data)                               (0x003FFFFF&(data))
#define THERMAL_RESULT_2_get_u_out_tm(data)                           (0x003FFFFF&(data))


#define THERMAL_IRQ_THRESHOLD_1                                       0x180003a8
#define THERMAL_IRQ_THRESHOLD_1_reg_addr                              "0xb80003a8"
#define THERMAL_IRQ_THRESHOLD_1_reg                                   0xb80003a8
#define THERMAL_IRQ_THRESHOLD_1_inst_addr                             "0x00EA"
#define THERMAL_IRQ_THRESHOLD_1_inst                                  0x00EA
#define set_THERMAL_IRQ_THRESHOLD_1_reg(data)                         (*((volatile unsigned int*)THERMAL_IRQ_THRESHOLD_1_reg)=data)
#define get_THERMAL_IRQ_THRESHOLD_1_reg                               (*((volatile unsigned int*)THERMAL_IRQ_THRESHOLD_1_reg))
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_ie_shift               (31)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_status_shift       (29)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_kcpu_ie_shift          (27)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_kcpu_status_shift  (25)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_thh_shift              (0)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_ie_mask                (0x80000000)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_status_mask        (0x60000000)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_kcpu_ie_mask           (0x08000000)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_kcpu_status_mask   (0x06000000)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_thh_mask               (0x0007FFFF)
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_ie(data)               (0x80000000&((data)<<31))
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_status(data)       (0x60000000&((data)<<29))
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_kcpu_ie(data)          (0x08000000&((data)<<27))
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_irq_kcpu_status(data)  (0x06000000&((data)<<25))
#define THERMAL_IRQ_THRESHOLD_1_thermal_sensor_thh(data)              (0x0007FFFF&(data))
#define THERMAL_IRQ_THRESHOLD_1_get_thermal_sensor_ie(data)           ((0x80000000&(data))>>31)
#define THERMAL_IRQ_THRESHOLD_1_get_thermal_sensor_irq_status(data)   ((0x60000000&(data))>>29)
#define THERMAL_IRQ_THRESHOLD_1_get_thermal_sensor_kcpu_ie(data)      ((0x08000000&(data))>>27)
#define THERMAL_IRQ_THRESHOLD_1_get_thermal_sensor_irq_kcpu_status(data)  ((0x06000000&(data))>>25)
#define THERMAL_IRQ_THRESHOLD_1_get_thermal_sensor_thh(data)          (0x0007FFFF&(data))


#define THERMAL_IRQ_THRESHOLD_2                                       0x180003ac
#define THERMAL_IRQ_THRESHOLD_2_reg_addr                              "0xb80003ac"
#define THERMAL_IRQ_THRESHOLD_2_reg                                   0xb80003ac
#define THERMAL_IRQ_THRESHOLD_2_inst_addr                             "0x00EB"
#define THERMAL_IRQ_THRESHOLD_2_inst                                  0x00EB
#define set_THERMAL_IRQ_THRESHOLD_2_reg(data)                         (*((volatile unsigned int*)THERMAL_IRQ_THRESHOLD_2_reg)=data)
#define get_THERMAL_IRQ_THRESHOLD_2_reg                               (*((volatile unsigned int*)THERMAL_IRQ_THRESHOLD_2_reg))
#define THERMAL_IRQ_THRESHOLD_2_thermal_sensor_thl_shift              (0)
#define THERMAL_IRQ_THRESHOLD_2_thermal_sensor_thl_mask               (0x0007FFFF)
#define THERMAL_IRQ_THRESHOLD_2_thermal_sensor_thl(data)              (0x0007FFFF&(data))
#define THERMAL_IRQ_THRESHOLD_2_get_thermal_sensor_thl(data)          (0x0007FFFF&(data))


#define SYS_PLL_KCPU1                                                 0x180003b0
#define SYS_PLL_KCPU1_reg_addr                                        "0xb80003b0"
#define SYS_PLL_KCPU1_reg                                             0xb80003b0
#define SYS_PLL_KCPU1_inst_addr                                       "0x00EC"
#define SYS_PLL_KCPU1_inst                                            0x00EC
#define set_SYS_PLL_KCPU1_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_KCPU1_reg)=data)
#define get_SYS_PLL_KCPU1_reg                                         (*((volatile unsigned int*)SYS_PLL_KCPU1_reg))
#define SYS_PLL_KCPU1_pllkcpu_tst_shift                               (24)
#define SYS_PLL_KCPU1_pllkcpu_n_shift                                 (20)
#define SYS_PLL_KCPU1_pllkcpu_m_shift                                 (12)
#define SYS_PLL_KCPU1_pllkcpu_ip_shift                                (9)
#define SYS_PLL_KCPU1_pllkcpu_o_shift                                 (7)
#define SYS_PLL_KCPU1_pllkcpu_wdset_shift                             (6)
#define SYS_PLL_KCPU1_pllkcpu_wdrst_shift                             (5)
#define SYS_PLL_KCPU1_pllkcpu_cs_shift                                (3)
#define SYS_PLL_KCPU1_pllkcpu_rs_shift                                (0)
#define SYS_PLL_KCPU1_pllkcpu_tst_mask                                (0x01000000)
#define SYS_PLL_KCPU1_pllkcpu_n_mask                                  (0x00300000)
#define SYS_PLL_KCPU1_pllkcpu_m_mask                                  (0x000FF000)
#define SYS_PLL_KCPU1_pllkcpu_ip_mask                                 (0x00000E00)
#define SYS_PLL_KCPU1_pllkcpu_o_mask                                  (0x00000180)
#define SYS_PLL_KCPU1_pllkcpu_wdset_mask                              (0x00000040)
#define SYS_PLL_KCPU1_pllkcpu_wdrst_mask                              (0x00000020)
#define SYS_PLL_KCPU1_pllkcpu_cs_mask                                 (0x00000018)
#define SYS_PLL_KCPU1_pllkcpu_rs_mask                                 (0x00000007)
#define SYS_PLL_KCPU1_pllkcpu_tst(data)                               (0x01000000&((data)<<24))
#define SYS_PLL_KCPU1_pllkcpu_n(data)                                 (0x00300000&((data)<<20))
#define SYS_PLL_KCPU1_pllkcpu_m(data)                                 (0x000FF000&((data)<<12))
#define SYS_PLL_KCPU1_pllkcpu_ip(data)                                (0x00000E00&((data)<<9))
#define SYS_PLL_KCPU1_pllkcpu_o(data)                                 (0x00000180&((data)<<7))
#define SYS_PLL_KCPU1_pllkcpu_wdset(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_KCPU1_pllkcpu_wdrst(data)                             (0x00000020&((data)<<5))
#define SYS_PLL_KCPU1_pllkcpu_cs(data)                                (0x00000018&((data)<<3))
#define SYS_PLL_KCPU1_pllkcpu_rs(data)                                (0x00000007&(data))
#define SYS_PLL_KCPU1_get_pllkcpu_tst(data)                           ((0x01000000&(data))>>24)
#define SYS_PLL_KCPU1_get_pllkcpu_n(data)                             ((0x00300000&(data))>>20)
#define SYS_PLL_KCPU1_get_pllkcpu_m(data)                             ((0x000FF000&(data))>>12)
#define SYS_PLL_KCPU1_get_pllkcpu_ip(data)                            ((0x00000E00&(data))>>9)
#define SYS_PLL_KCPU1_get_pllkcpu_o(data)                             ((0x00000180&(data))>>7)
#define SYS_PLL_KCPU1_get_pllkcpu_wdset(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_KCPU1_get_pllkcpu_wdrst(data)                         ((0x00000020&(data))>>5)
#define SYS_PLL_KCPU1_get_pllkcpu_cs(data)                            ((0x00000018&(data))>>3)
#define SYS_PLL_KCPU1_get_pllkcpu_rs(data)                            (0x00000007&(data))


#define SYS_PLL_KCPU2                                                 0x180003b4
#define SYS_PLL_KCPU2_reg_addr                                        "0xb80003b4"
#define SYS_PLL_KCPU2_reg                                             0xb80003b4
#define SYS_PLL_KCPU2_inst_addr                                       "0x00ED"
#define SYS_PLL_KCPU2_inst                                            0x00ED
#define set_SYS_PLL_KCPU2_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_KCPU2_reg)=data)
#define get_SYS_PLL_KCPU2_reg                                         (*((volatile unsigned int*)SYS_PLL_KCPU2_reg))
#define SYS_PLL_KCPU2_pllkcpu_reserve_shift                           (4)
#define SYS_PLL_KCPU2_pllkcpu_oeb_shift                               (2)
#define SYS_PLL_KCPU2_pllkcpu_rstb_shift                              (1)
#define SYS_PLL_KCPU2_pllkcpu_pow_shift                               (0)
#define SYS_PLL_KCPU2_pllkcpu_reserve_mask                            (0x000003F0)
#define SYS_PLL_KCPU2_pllkcpu_oeb_mask                                (0x00000004)
#define SYS_PLL_KCPU2_pllkcpu_rstb_mask                               (0x00000002)
#define SYS_PLL_KCPU2_pllkcpu_pow_mask                                (0x00000001)
#define SYS_PLL_KCPU2_pllkcpu_reserve(data)                           (0x000003F0&((data)<<4))
#define SYS_PLL_KCPU2_pllkcpu_oeb(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_KCPU2_pllkcpu_rstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_KCPU2_pllkcpu_pow(data)                               (0x00000001&(data))
#define SYS_PLL_KCPU2_get_pllkcpu_reserve(data)                       ((0x000003F0&(data))>>4)
#define SYS_PLL_KCPU2_get_pllkcpu_oeb(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_KCPU2_get_pllkcpu_rstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_KCPU2_get_pllkcpu_pow(data)                           (0x00000001&(data))


#define PLL_SSC_BUS                                                   0x180003c0
#define PLL_SSC_BUS_reg_addr                                          "0xb80003c0"
#define PLL_SSC_BUS_reg                                               0xb80003c0
#define PLL_SSC_BUS_inst_addr                                         "0x00F0"
#define PLL_SSC_BUS_inst                                              0x00F0
#define set_PLL_SSC_BUS_reg(data)                                     (*((volatile unsigned int*)PLL_SSC_BUS_reg)=data)
#define get_PLL_SSC_BUS_reg                                           (*((volatile unsigned int*)PLL_SSC_BUS_reg))
#define PLL_SSC_BUS_pllbus_gran_auto_rst_shift                        (28)
#define PLL_SSC_BUS_pllbus_dot_gran_shift                             (24)
#define PLL_SSC_BUS_pllbus_gran_est_shift                             (4)
#define PLL_SSC_BUS_pllbus_en_ssc_shift                               (0)
#define PLL_SSC_BUS_pllbus_gran_auto_rst_mask                         (0x10000000)
#define PLL_SSC_BUS_pllbus_dot_gran_mask                              (0x07000000)
#define PLL_SSC_BUS_pllbus_gran_est_mask                              (0x007FFFF0)
#define PLL_SSC_BUS_pllbus_en_ssc_mask                                (0x00000001)
#define PLL_SSC_BUS_pllbus_gran_auto_rst(data)                        (0x10000000&((data)<<28))
#define PLL_SSC_BUS_pllbus_dot_gran(data)                             (0x07000000&((data)<<24))
#define PLL_SSC_BUS_pllbus_gran_est(data)                             (0x007FFFF0&((data)<<4))
#define PLL_SSC_BUS_pllbus_en_ssc(data)                               (0x00000001&(data))
#define PLL_SSC_BUS_get_pllbus_gran_auto_rst(data)                    ((0x10000000&(data))>>28)
#define PLL_SSC_BUS_get_pllbus_dot_gran(data)                         ((0x07000000&(data))>>24)
#define PLL_SSC_BUS_get_pllbus_gran_est(data)                         ((0x007FFFF0&(data))>>4)
#define PLL_SSC_BUS_get_pllbus_en_ssc(data)                           (0x00000001&(data))


#define PLL_SSC_BUS_2                                                 0x180003c4
#define PLL_SSC_BUS_2_reg_addr                                        "0xb80003c4"
#define PLL_SSC_BUS_2_reg                                             0xb80003c4
#define PLL_SSC_BUS_2_inst_addr                                       "0x00F1"
#define PLL_SSC_BUS_2_inst                                            0x00F1
#define set_PLL_SSC_BUS_2_reg(data)                                   (*((volatile unsigned int*)PLL_SSC_BUS_2_reg)=data)
#define get_PLL_SSC_BUS_2_reg                                         (*((volatile unsigned int*)PLL_SSC_BUS_2_reg))
#define PLL_SSC_BUS_2_pllbus_ncode_ssc_shift                          (16)
#define PLL_SSC_BUS_2_pllbus_fcode_ssc_shift                          (0)
#define PLL_SSC_BUS_2_pllbus_ncode_ssc_mask                           (0x00FF0000)
#define PLL_SSC_BUS_2_pllbus_fcode_ssc_mask                           (0x000007FF)
#define PLL_SSC_BUS_2_pllbus_ncode_ssc(data)                          (0x00FF0000&((data)<<16))
#define PLL_SSC_BUS_2_pllbus_fcode_ssc(data)                          (0x000007FF&(data))
#define PLL_SSC_BUS_2_get_pllbus_ncode_ssc(data)                      ((0x00FF0000&(data))>>16)
#define PLL_SSC_BUS_2_get_pllbus_fcode_ssc(data)                      (0x000007FF&(data))


#define PLL_SSC_BUSH                                                  0x180003d0
#define PLL_SSC_BUSH_reg_addr                                         "0xb80003d0"
#define PLL_SSC_BUSH_reg                                              0xb80003d0
#define PLL_SSC_BUSH_inst_addr                                        "0x00F4"
#define PLL_SSC_BUSH_inst                                             0x00F4
#define set_PLL_SSC_BUSH_reg(data)                                    (*((volatile unsigned int*)PLL_SSC_BUSH_reg)=data)
#define get_PLL_SSC_BUSH_reg                                          (*((volatile unsigned int*)PLL_SSC_BUSH_reg))
#define PLL_SSC_BUSH_pllbus_gran_auto_rst_h_shift                     (28)
#define PLL_SSC_BUSH_pllbus_dot_gran_h_shift                          (24)
#define PLL_SSC_BUSH_pllbus_gran_est_h_shift                          (4)
#define PLL_SSC_BUSH_pllbus_en_ssc_h_shift                            (0)
#define PLL_SSC_BUSH_pllbus_gran_auto_rst_h_mask                      (0x10000000)
#define PLL_SSC_BUSH_pllbus_dot_gran_h_mask                           (0x07000000)
#define PLL_SSC_BUSH_pllbus_gran_est_h_mask                           (0x007FFFF0)
#define PLL_SSC_BUSH_pllbus_en_ssc_h_mask                             (0x00000001)
#define PLL_SSC_BUSH_pllbus_gran_auto_rst_h(data)                     (0x10000000&((data)<<28))
#define PLL_SSC_BUSH_pllbus_dot_gran_h(data)                          (0x07000000&((data)<<24))
#define PLL_SSC_BUSH_pllbus_gran_est_h(data)                          (0x007FFFF0&((data)<<4))
#define PLL_SSC_BUSH_pllbus_en_ssc_h(data)                            (0x00000001&(data))
#define PLL_SSC_BUSH_get_pllbus_gran_auto_rst_h(data)                 ((0x10000000&(data))>>28)
#define PLL_SSC_BUSH_get_pllbus_dot_gran_h(data)                      ((0x07000000&(data))>>24)
#define PLL_SSC_BUSH_get_pllbus_gran_est_h(data)                      ((0x007FFFF0&(data))>>4)
#define PLL_SSC_BUSH_get_pllbus_en_ssc_h(data)                        (0x00000001&(data))


#define PLL_SSC_BUSH_2                                                0x180003d4
#define PLL_SSC_BUSH_2_reg_addr                                       "0xb80003d4"
#define PLL_SSC_BUSH_2_reg                                            0xb80003d4
#define PLL_SSC_BUSH_2_inst_addr                                      "0x00F5"
#define PLL_SSC_BUSH_2_inst                                           0x00F5
#define set_PLL_SSC_BUSH_2_reg(data)                                  (*((volatile unsigned int*)PLL_SSC_BUSH_2_reg)=data)
#define get_PLL_SSC_BUSH_2_reg                                        (*((volatile unsigned int*)PLL_SSC_BUSH_2_reg))
#define PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_shift                       (16)
#define PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_shift                       (0)
#define PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_mask                        (0x00FF0000)
#define PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_mask                        (0x000007FF)
#define PLL_SSC_BUSH_2_pllbus_ncode_ssc_h(data)                       (0x00FF0000&((data)<<16))
#define PLL_SSC_BUSH_2_pllbus_fcode_ssc_h(data)                       (0x000007FF&(data))
#define PLL_SSC_BUSH_2_get_pllbus_ncode_ssc_h(data)                   ((0x00FF0000&(data))>>16)
#define PLL_SSC_BUSH_2_get_pllbus_fcode_ssc_h(data)                   (0x000007FF&(data))


#define PLL_SSC_DDSA                                                  0x180003e0
#define PLL_SSC_DDSA_reg_addr                                         "0xb80003e0"
#define PLL_SSC_DDSA_reg                                              0xb80003e0
#define PLL_SSC_DDSA_inst_addr                                        "0x00F8"
#define PLL_SSC_DDSA_inst                                             0x00F8
#define set_PLL_SSC_DDSA_reg(data)                                    (*((volatile unsigned int*)PLL_SSC_DDSA_reg)=data)
#define get_PLL_SSC_DDSA_reg                                          (*((volatile unsigned int*)PLL_SSC_DDSA_reg))
#define PLL_SSC_DDSA_pllddsa_gran_auto_rst_shift                      (28)
#define PLL_SSC_DDSA_pllddsa_dot_gran_shift                           (24)
#define PLL_SSC_DDSA_pllddsa_gran_est_shift                           (4)
#define PLL_SSC_DDSA_pllddsa_en_ssc_shift                             (0)
#define PLL_SSC_DDSA_pllddsa_gran_auto_rst_mask                       (0x10000000)
#define PLL_SSC_DDSA_pllddsa_dot_gran_mask                            (0x07000000)
#define PLL_SSC_DDSA_pllddsa_gran_est_mask                            (0x007FFFF0)
#define PLL_SSC_DDSA_pllddsa_en_ssc_mask                              (0x00000001)
#define PLL_SSC_DDSA_pllddsa_gran_auto_rst(data)                      (0x10000000&((data)<<28))
#define PLL_SSC_DDSA_pllddsa_dot_gran(data)                           (0x07000000&((data)<<24))
#define PLL_SSC_DDSA_pllddsa_gran_est(data)                           (0x007FFFF0&((data)<<4))
#define PLL_SSC_DDSA_pllddsa_en_ssc(data)                             (0x00000001&(data))
#define PLL_SSC_DDSA_get_pllddsa_gran_auto_rst(data)                  ((0x10000000&(data))>>28)
#define PLL_SSC_DDSA_get_pllddsa_dot_gran(data)                       ((0x07000000&(data))>>24)
#define PLL_SSC_DDSA_get_pllddsa_gran_est(data)                       ((0x007FFFF0&(data))>>4)
#define PLL_SSC_DDSA_get_pllddsa_en_ssc(data)                         (0x00000001&(data))


#define PLL_SSC_DDSA_2                                                0x180003e4
#define PLL_SSC_DDSA_2_reg_addr                                       "0xb80003e4"
#define PLL_SSC_DDSA_2_reg                                            0xb80003e4
#define PLL_SSC_DDSA_2_inst_addr                                      "0x00F9"
#define PLL_SSC_DDSA_2_inst                                           0x00F9
#define set_PLL_SSC_DDSA_2_reg(data)                                  (*((volatile unsigned int*)PLL_SSC_DDSA_2_reg)=data)
#define get_PLL_SSC_DDSA_2_reg                                        (*((volatile unsigned int*)PLL_SSC_DDSA_2_reg))
#define PLL_SSC_DDSA_2_pllddsa_ncode_ssc_shift                        (16)
#define PLL_SSC_DDSA_2_pllddsa_fcode_ssc_shift                        (0)
#define PLL_SSC_DDSA_2_pllddsa_ncode_ssc_mask                         (0x00FF0000)
#define PLL_SSC_DDSA_2_pllddsa_fcode_ssc_mask                         (0x000007FF)
#define PLL_SSC_DDSA_2_pllddsa_ncode_ssc(data)                        (0x00FF0000&((data)<<16))
#define PLL_SSC_DDSA_2_pllddsa_fcode_ssc(data)                        (0x000007FF&(data))
#define PLL_SSC_DDSA_2_get_pllddsa_ncode_ssc(data)                    ((0x00FF0000&(data))>>16)
#define PLL_SSC_DDSA_2_get_pllddsa_fcode_ssc(data)                    (0x000007FF&(data))


#define PLL_SSC_DDSB                                                  0x180003e8
#define PLL_SSC_DDSB_reg_addr                                         "0xb80003e8"
#define PLL_SSC_DDSB_reg                                              0xb80003e8
#define PLL_SSC_DDSB_inst_addr                                        "0x00FA"
#define PLL_SSC_DDSB_inst                                             0x00FA
#define set_PLL_SSC_DDSB_reg(data)                                    (*((volatile unsigned int*)PLL_SSC_DDSB_reg)=data)
#define get_PLL_SSC_DDSB_reg                                          (*((volatile unsigned int*)PLL_SSC_DDSB_reg))


#define PLL_SSC_DDSB_2                                                0x180003ec
#define PLL_SSC_DDSB_2_reg_addr                                       "0xb80003ec"
#define PLL_SSC_DDSB_2_reg                                            0xb80003ec
#define PLL_SSC_DDSB_2_inst_addr                                      "0x00FB"
#define PLL_SSC_DDSB_2_inst                                           0x00FB
#define set_PLL_SSC_DDSB_2_reg(data)                                  (*((volatile unsigned int*)PLL_SSC_DDSB_2_reg)=data)
#define get_PLL_SSC_DDSB_2_reg                                        (*((volatile unsigned int*)PLL_SSC_DDSB_2_reg))


#define PLL_SSC_INV                                                   0x180003f0
#define PLL_SSC_INV_reg_addr                                          "0xb80003f0"
#define PLL_SSC_INV_reg                                               0xb80003f0
#define PLL_SSC_INV_inst_addr                                         "0x00FC"
#define PLL_SSC_INV_inst                                              0x00FC
#define set_PLL_SSC_INV_reg(data)                                     (*((volatile unsigned int*)PLL_SSC_INV_reg)=data)
#define get_PLL_SSC_INV_reg                                           (*((volatile unsigned int*)PLL_SSC_INV_reg))
#define PLL_SSC_INV_psaud2b_ssc_ckinv_shift                           (11)
#define PLL_SSC_INV_psaud2a_ssc_ckinv_shift                           (10)
#define PLL_SSC_INV_psaud1b_ssc_ckinv_shift                           (9)
#define PLL_SSC_INV_psaud1a_ssc_ckinv_shift                           (8)
#define PLL_SSC_INV_dds_ssc_ckinv_shift                               (4)
#define PLL_SSC_INV_gpu_ssc_ckinv_shift                               (3)
#define PLL_SSC_INV_bush_ssc_ckinv_shift                              (1)
#define PLL_SSC_INV_bus_ssc_ckinv_shift                               (0)
#define PLL_SSC_INV_psaud2b_ssc_ckinv_mask                            (0x00000800)
#define PLL_SSC_INV_psaud2a_ssc_ckinv_mask                            (0x00000400)
#define PLL_SSC_INV_psaud1b_ssc_ckinv_mask                            (0x00000200)
#define PLL_SSC_INV_psaud1a_ssc_ckinv_mask                            (0x00000100)
#define PLL_SSC_INV_dds_ssc_ckinv_mask                                (0x00000010)
#define PLL_SSC_INV_gpu_ssc_ckinv_mask                                (0x00000008)
#define PLL_SSC_INV_bush_ssc_ckinv_mask                               (0x00000002)
#define PLL_SSC_INV_bus_ssc_ckinv_mask                                (0x00000001)
#define PLL_SSC_INV_psaud2b_ssc_ckinv(data)                           (0x00000800&((data)<<11))
#define PLL_SSC_INV_psaud2a_ssc_ckinv(data)                           (0x00000400&((data)<<10))
#define PLL_SSC_INV_psaud1b_ssc_ckinv(data)                           (0x00000200&((data)<<9))
#define PLL_SSC_INV_psaud1a_ssc_ckinv(data)                           (0x00000100&((data)<<8))
#define PLL_SSC_INV_dds_ssc_ckinv(data)                               (0x00000010&((data)<<4))
#define PLL_SSC_INV_gpu_ssc_ckinv(data)                               (0x00000008&((data)<<3))
#define PLL_SSC_INV_bush_ssc_ckinv(data)                              (0x00000002&((data)<<1))
#define PLL_SSC_INV_bus_ssc_ckinv(data)                               (0x00000001&(data))
#define PLL_SSC_INV_get_psaud2b_ssc_ckinv(data)                       ((0x00000800&(data))>>11)
#define PLL_SSC_INV_get_psaud2a_ssc_ckinv(data)                       ((0x00000400&(data))>>10)
#define PLL_SSC_INV_get_psaud1b_ssc_ckinv(data)                       ((0x00000200&(data))>>9)
#define PLL_SSC_INV_get_psaud1a_ssc_ckinv(data)                       ((0x00000100&(data))>>8)
#define PLL_SSC_INV_get_dds_ssc_ckinv(data)                           ((0x00000010&(data))>>4)
#define PLL_SSC_INV_get_gpu_ssc_ckinv(data)                           ((0x00000008&(data))>>3)
#define PLL_SSC_INV_get_bush_ssc_ckinv(data)                          ((0x00000002&(data))>>1)
#define PLL_SSC_INV_get_bus_ssc_ckinv(data)                           (0x00000001&(data))


#define SYS_PLL_CPU                                                   0x180003f4
#define SYS_PLL_CPU_reg_addr                                          "0xb80003f4"
#define SYS_PLL_CPU_reg                                               0xb80003f4
#define SYS_PLL_CPU_inst_addr                                         "0x00FD"
#define SYS_PLL_CPU_inst                                              0x00FD
#define set_SYS_PLL_CPU_reg(data)                                     (*((volatile unsigned int*)SYS_PLL_CPU_reg)=data)
#define get_SYS_PLL_CPU_reg                                           (*((volatile unsigned int*)SYS_PLL_CPU_reg))
#define SYS_PLL_CPU_pow_ldo1v_shift                                   (6)
#define SYS_PLL_CPU_ldo1v_sel_shift                                   (4)
#define SYS_PLL_CPU_pllcpu_reg_shift                                  (0)
#define SYS_PLL_CPU_pow_ldo1v_mask                                    (0x00000040)
#define SYS_PLL_CPU_ldo1v_sel_mask                                    (0x00000030)
#define SYS_PLL_CPU_pllcpu_reg_mask                                   (0x00000003)
#define SYS_PLL_CPU_pow_ldo1v(data)                                   (0x00000040&((data)<<6))
#define SYS_PLL_CPU_ldo1v_sel(data)                                   (0x00000030&((data)<<4))
#define SYS_PLL_CPU_pllcpu_reg(data)                                  (0x00000003&(data))
#define SYS_PLL_CPU_get_pow_ldo1v(data)                               ((0x00000040&(data))>>6)
#define SYS_PLL_CPU_get_ldo1v_sel(data)                               ((0x00000030&(data))>>4)
#define SYS_PLL_CPU_get_pllcpu_reg(data)                              (0x00000003&(data))


#define SYS_PLL_ACPU1                                                 0x18000408
#define SYS_PLL_ACPU1_reg_addr                                        "0xb8000408"
#define SYS_PLL_ACPU1_reg                                             0xb8000408
#define SYS_PLL_ACPU1_inst_addr                                       "0x0102"
#define SYS_PLL_ACPU1_inst                                            0x0102
#define set_SYS_PLL_ACPU1_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_ACPU1_reg)=data)
#define get_SYS_PLL_ACPU1_reg                                         (*((volatile unsigned int*)SYS_PLL_ACPU1_reg))
#define SYS_PLL_ACPU1_pllacpu_tst_shift                               (24)
#define SYS_PLL_ACPU1_pllacpu_n_shift                                 (20)
#define SYS_PLL_ACPU1_pllacpu_m_shift                                 (12)
#define SYS_PLL_ACPU1_pllacpu_ip_shift                                (9)
#define SYS_PLL_ACPU1_pllacpu_o_shift                                 (7)
#define SYS_PLL_ACPU1_pllacpu_wdset_shift                             (6)
#define SYS_PLL_ACPU1_pllacpu_wdrst_shift                             (5)
#define SYS_PLL_ACPU1_pllacpu_cs_shift                                (3)
#define SYS_PLL_ACPU1_pllacpu_rs_shift                                (0)
#define SYS_PLL_ACPU1_pllacpu_tst_mask                                (0x01000000)
#define SYS_PLL_ACPU1_pllacpu_n_mask                                  (0x00300000)
#define SYS_PLL_ACPU1_pllacpu_m_mask                                  (0x000FF000)
#define SYS_PLL_ACPU1_pllacpu_ip_mask                                 (0x00000E00)
#define SYS_PLL_ACPU1_pllacpu_o_mask                                  (0x00000180)
#define SYS_PLL_ACPU1_pllacpu_wdset_mask                              (0x00000040)
#define SYS_PLL_ACPU1_pllacpu_wdrst_mask                              (0x00000020)
#define SYS_PLL_ACPU1_pllacpu_cs_mask                                 (0x00000018)
#define SYS_PLL_ACPU1_pllacpu_rs_mask                                 (0x00000007)
#define SYS_PLL_ACPU1_pllacpu_tst(data)                               (0x01000000&((data)<<24))
#define SYS_PLL_ACPU1_pllacpu_n(data)                                 (0x00300000&((data)<<20))
#define SYS_PLL_ACPU1_pllacpu_m(data)                                 (0x000FF000&((data)<<12))
#define SYS_PLL_ACPU1_pllacpu_ip(data)                                (0x00000E00&((data)<<9))
#define SYS_PLL_ACPU1_pllacpu_o(data)                                 (0x00000180&((data)<<7))
#define SYS_PLL_ACPU1_pllacpu_wdset(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_ACPU1_pllacpu_wdrst(data)                             (0x00000020&((data)<<5))
#define SYS_PLL_ACPU1_pllacpu_cs(data)                                (0x00000018&((data)<<3))
#define SYS_PLL_ACPU1_pllacpu_rs(data)                                (0x00000007&(data))
#define SYS_PLL_ACPU1_get_pllacpu_tst(data)                           ((0x01000000&(data))>>24)
#define SYS_PLL_ACPU1_get_pllacpu_n(data)                             ((0x00300000&(data))>>20)
#define SYS_PLL_ACPU1_get_pllacpu_m(data)                             ((0x000FF000&(data))>>12)
#define SYS_PLL_ACPU1_get_pllacpu_ip(data)                            ((0x00000E00&(data))>>9)
#define SYS_PLL_ACPU1_get_pllacpu_o(data)                             ((0x00000180&(data))>>7)
#define SYS_PLL_ACPU1_get_pllacpu_wdset(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_ACPU1_get_pllacpu_wdrst(data)                         ((0x00000020&(data))>>5)
#define SYS_PLL_ACPU1_get_pllacpu_cs(data)                            ((0x00000018&(data))>>3)
#define SYS_PLL_ACPU1_get_pllacpu_rs(data)                            (0x00000007&(data))


#define SYS_PLL_ACPU2                                                 0x1800040c
#define SYS_PLL_ACPU2_reg_addr                                        "0xb800040c"
#define SYS_PLL_ACPU2_reg                                             0xb800040c
#define SYS_PLL_ACPU2_inst_addr                                       "0x0103"
#define SYS_PLL_ACPU2_inst                                            0x0103
#define set_SYS_PLL_ACPU2_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_ACPU2_reg)=data)
#define get_SYS_PLL_ACPU2_reg                                         (*((volatile unsigned int*)SYS_PLL_ACPU2_reg))
#define SYS_PLL_ACPU2_pllacpu_reserve_shift                           (4)
#define SYS_PLL_ACPU2_pllacpu_oeb_shift                               (2)
#define SYS_PLL_ACPU2_pllacpu_rstb_shift                              (1)
#define SYS_PLL_ACPU2_pllacpu_pow_shift                               (0)
#define SYS_PLL_ACPU2_pllacpu_reserve_mask                            (0x000003F0)
#define SYS_PLL_ACPU2_pllacpu_oeb_mask                                (0x00000004)
#define SYS_PLL_ACPU2_pllacpu_rstb_mask                               (0x00000002)
#define SYS_PLL_ACPU2_pllacpu_pow_mask                                (0x00000001)
#define SYS_PLL_ACPU2_pllacpu_reserve(data)                           (0x000003F0&((data)<<4))
#define SYS_PLL_ACPU2_pllacpu_oeb(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_ACPU2_pllacpu_rstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_ACPU2_pllacpu_pow(data)                               (0x00000001&(data))
#define SYS_PLL_ACPU2_get_pllacpu_reserve(data)                       ((0x000003F0&(data))>>4)
#define SYS_PLL_ACPU2_get_pllacpu_oeb(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_ACPU2_get_pllacpu_rstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_ACPU2_get_pllacpu_pow(data)                           (0x00000001&(data))


#define SYS_PLL_VCPU_1                                                0x18000410
#define SYS_PLL_VCPU_1_reg_addr                                       "0xb8000410"
#define SYS_PLL_VCPU_1_reg                                            0xb8000410
#define SYS_PLL_VCPU_1_inst_addr                                      "0x0104"
#define SYS_PLL_VCPU_1_inst                                           0x0104
#define set_SYS_PLL_VCPU_1_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_VCPU_1_reg)=data)
#define get_SYS_PLL_VCPU_1_reg                                        (*((volatile unsigned int*)SYS_PLL_VCPU_1_reg))
#define SYS_PLL_VCPU_1_pllvcpu_tst_shift                              (24)
#define SYS_PLL_VCPU_1_pllvcpu_n_shift                                (20)
#define SYS_PLL_VCPU_1_pllvcpu_m_shift                                (12)
#define SYS_PLL_VCPU_1_pllvcpu_ip_shift                               (9)
#define SYS_PLL_VCPU_1_pllvcpu_o_shift                                (7)
#define SYS_PLL_VCPU_1_pllvcpu_wdset_shift                            (6)
#define SYS_PLL_VCPU_1_pllvcpu_wdrst_shift                            (5)
#define SYS_PLL_VCPU_1_pllvcpu_cs_shift                               (3)
#define SYS_PLL_VCPU_1_pllvcpu_rs_shift                               (0)
#define SYS_PLL_VCPU_1_pllvcpu_tst_mask                               (0x01000000)
#define SYS_PLL_VCPU_1_pllvcpu_n_mask                                 (0x00300000)
#define SYS_PLL_VCPU_1_pllvcpu_m_mask                                 (0x000FF000)
#define SYS_PLL_VCPU_1_pllvcpu_ip_mask                                (0x00000E00)
#define SYS_PLL_VCPU_1_pllvcpu_o_mask                                 (0x00000180)
#define SYS_PLL_VCPU_1_pllvcpu_wdset_mask                             (0x00000040)
#define SYS_PLL_VCPU_1_pllvcpu_wdrst_mask                             (0x00000020)
#define SYS_PLL_VCPU_1_pllvcpu_cs_mask                                (0x00000018)
#define SYS_PLL_VCPU_1_pllvcpu_rs_mask                                (0x00000007)
#define SYS_PLL_VCPU_1_pllvcpu_tst(data)                              (0x01000000&((data)<<24))
#define SYS_PLL_VCPU_1_pllvcpu_n(data)                                (0x00300000&((data)<<20))
#define SYS_PLL_VCPU_1_pllvcpu_m(data)                                (0x000FF000&((data)<<12))
#define SYS_PLL_VCPU_1_pllvcpu_ip(data)                               (0x00000E00&((data)<<9))
#define SYS_PLL_VCPU_1_pllvcpu_o(data)                                (0x00000180&((data)<<7))
#define SYS_PLL_VCPU_1_pllvcpu_wdset(data)                            (0x00000040&((data)<<6))
#define SYS_PLL_VCPU_1_pllvcpu_wdrst(data)                            (0x00000020&((data)<<5))
#define SYS_PLL_VCPU_1_pllvcpu_cs(data)                               (0x00000018&((data)<<3))
#define SYS_PLL_VCPU_1_pllvcpu_rs(data)                               (0x00000007&(data))
#define SYS_PLL_VCPU_1_get_pllvcpu_tst(data)                          ((0x01000000&(data))>>24)
#define SYS_PLL_VCPU_1_get_pllvcpu_n(data)                            ((0x00300000&(data))>>20)
#define SYS_PLL_VCPU_1_get_pllvcpu_m(data)                            ((0x000FF000&(data))>>12)
#define SYS_PLL_VCPU_1_get_pllvcpu_ip(data)                           ((0x00000E00&(data))>>9)
#define SYS_PLL_VCPU_1_get_pllvcpu_o(data)                            ((0x00000180&(data))>>7)
#define SYS_PLL_VCPU_1_get_pllvcpu_wdset(data)                        ((0x00000040&(data))>>6)
#define SYS_PLL_VCPU_1_get_pllvcpu_wdrst(data)                        ((0x00000020&(data))>>5)
#define SYS_PLL_VCPU_1_get_pllvcpu_cs(data)                           ((0x00000018&(data))>>3)
#define SYS_PLL_VCPU_1_get_pllvcpu_rs(data)                           (0x00000007&(data))


#define SYS_PLL_VCPU_2                                                0x18000414
#define SYS_PLL_VCPU_2_reg_addr                                       "0xb8000414"
#define SYS_PLL_VCPU_2_reg                                            0xb8000414
#define SYS_PLL_VCPU_2_inst_addr                                      "0x0105"
#define SYS_PLL_VCPU_2_inst                                           0x0105
#define set_SYS_PLL_VCPU_2_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_VCPU_2_reg)=data)
#define get_SYS_PLL_VCPU_2_reg                                        (*((volatile unsigned int*)SYS_PLL_VCPU_2_reg))
#define SYS_PLL_VCPU_2_pllvcpu_reserve_shift                          (4)
#define SYS_PLL_VCPU_2_pllvcpu_oeb_shift                              (2)
#define SYS_PLL_VCPU_2_pllvcpu_rstb_shift                             (1)
#define SYS_PLL_VCPU_2_pllvcpu_pow_shift                              (0)
#define SYS_PLL_VCPU_2_pllvcpu_reserve_mask                           (0x000003F0)
#define SYS_PLL_VCPU_2_pllvcpu_oeb_mask                               (0x00000004)
#define SYS_PLL_VCPU_2_pllvcpu_rstb_mask                              (0x00000002)
#define SYS_PLL_VCPU_2_pllvcpu_pow_mask                               (0x00000001)
#define SYS_PLL_VCPU_2_pllvcpu_reserve(data)                          (0x000003F0&((data)<<4))
#define SYS_PLL_VCPU_2_pllvcpu_oeb(data)                              (0x00000004&((data)<<2))
#define SYS_PLL_VCPU_2_pllvcpu_rstb(data)                             (0x00000002&((data)<<1))
#define SYS_PLL_VCPU_2_pllvcpu_pow(data)                              (0x00000001&(data))
#define SYS_PLL_VCPU_2_get_pllvcpu_reserve(data)                      ((0x000003F0&(data))>>4)
#define SYS_PLL_VCPU_2_get_pllvcpu_oeb(data)                          ((0x00000004&(data))>>2)
#define SYS_PLL_VCPU_2_get_pllvcpu_rstb(data)                         ((0x00000002&(data))>>1)
#define SYS_PLL_VCPU_2_get_pllvcpu_pow(data)                          (0x00000001&(data))


#define SYS_PLL_BUS1                                                  0x18000420
#define SYS_PLL_BUS1_reg_addr                                         "0xb8000420"
#define SYS_PLL_BUS1_reg                                              0xb8000420
#define SYS_PLL_BUS1_inst_addr                                        "0x0108"
#define SYS_PLL_BUS1_inst                                             0x0108
#define set_SYS_PLL_BUS1_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_BUS1_reg)=data)
#define get_SYS_PLL_BUS1_reg                                          (*((volatile unsigned int*)SYS_PLL_BUS1_reg))
#define SYS_PLL_BUS1_pllbus_wdset_shift                               (21)
#define SYS_PLL_BUS1_pllbus_wdrst_shift                               (20)
#define SYS_PLL_BUS1_pllbus_lpf_cs_shift                              (16)
#define SYS_PLL_BUS1_pllbus_testsel_shift                             (13)
#define SYS_PLL_BUS1_pllbus_sel_cco_shift                             (12)
#define SYS_PLL_BUS1_pllbus_icp_shift                                 (8)
#define SYS_PLL_BUS1_pllbus_dbug_en_shift                             (7)
#define SYS_PLL_BUS1_pllbus_pdiv_bps_shift                            (6)
#define SYS_PLL_BUS1_pllbus_pdiv_shift                                (4)
#define SYS_PLL_BUS1_pllbus_lpf_rs_shift                              (0)
#define SYS_PLL_BUS1_pllbus_wdset_mask                                (0x00200000)
#define SYS_PLL_BUS1_pllbus_wdrst_mask                                (0x00100000)
#define SYS_PLL_BUS1_pllbus_lpf_cs_mask                               (0x00030000)
#define SYS_PLL_BUS1_pllbus_testsel_mask                              (0x00002000)
#define SYS_PLL_BUS1_pllbus_sel_cco_mask                              (0x00001000)
#define SYS_PLL_BUS1_pllbus_icp_mask                                  (0x00000F00)
#define SYS_PLL_BUS1_pllbus_dbug_en_mask                              (0x00000080)
#define SYS_PLL_BUS1_pllbus_pdiv_bps_mask                             (0x00000040)
#define SYS_PLL_BUS1_pllbus_pdiv_mask                                 (0x00000030)
#define SYS_PLL_BUS1_pllbus_lpf_rs_mask                               (0x00000007)
#define SYS_PLL_BUS1_pllbus_wdset(data)                               (0x00200000&((data)<<21))
#define SYS_PLL_BUS1_pllbus_wdrst(data)                               (0x00100000&((data)<<20))
#define SYS_PLL_BUS1_pllbus_lpf_cs(data)                              (0x00030000&((data)<<16))
#define SYS_PLL_BUS1_pllbus_testsel(data)                             (0x00002000&((data)<<13))
#define SYS_PLL_BUS1_pllbus_sel_cco(data)                             (0x00001000&((data)<<12))
#define SYS_PLL_BUS1_pllbus_icp(data)                                 (0x00000F00&((data)<<8))
#define SYS_PLL_BUS1_pllbus_dbug_en(data)                             (0x00000080&((data)<<7))
#define SYS_PLL_BUS1_pllbus_pdiv_bps(data)                            (0x00000040&((data)<<6))
#define SYS_PLL_BUS1_pllbus_pdiv(data)                                (0x00000030&((data)<<4))
#define SYS_PLL_BUS1_pllbus_lpf_rs(data)                              (0x00000007&(data))
#define SYS_PLL_BUS1_get_pllbus_wdset(data)                           ((0x00200000&(data))>>21)
#define SYS_PLL_BUS1_get_pllbus_wdrst(data)                           ((0x00100000&(data))>>20)
#define SYS_PLL_BUS1_get_pllbus_lpf_cs(data)                          ((0x00030000&(data))>>16)
#define SYS_PLL_BUS1_get_pllbus_testsel(data)                         ((0x00002000&(data))>>13)
#define SYS_PLL_BUS1_get_pllbus_sel_cco(data)                         ((0x00001000&(data))>>12)
#define SYS_PLL_BUS1_get_pllbus_icp(data)                             ((0x00000F00&(data))>>8)
#define SYS_PLL_BUS1_get_pllbus_dbug_en(data)                         ((0x00000080&(data))>>7)
#define SYS_PLL_BUS1_get_pllbus_pdiv_bps(data)                        ((0x00000040&(data))>>6)
#define SYS_PLL_BUS1_get_pllbus_pdiv(data)                            ((0x00000030&(data))>>4)
#define SYS_PLL_BUS1_get_pllbus_lpf_rs(data)                          (0x00000007&(data))


#define SYS_PLL_BUS2                                                  0x18000424
#define SYS_PLL_BUS2_reg_addr                                         "0xb8000424"
#define SYS_PLL_BUS2_reg                                              0xb8000424
#define SYS_PLL_BUS2_inst_addr                                        "0x0109"
#define SYS_PLL_BUS2_inst                                             0x0109
#define set_SYS_PLL_BUS2_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_BUS2_reg)=data)
#define get_SYS_PLL_BUS2_reg                                          (*((volatile unsigned int*)SYS_PLL_BUS2_reg))
#define SYS_PLL_BUS2_pllbus_fcode_shift                               (16)
#define SYS_PLL_BUS2_pllbus_ncode_shift                               (8)
#define SYS_PLL_BUS2_pllbus_oeb_shift                                 (2)
#define SYS_PLL_BUS2_pllbus_rstb_shift                                (1)
#define SYS_PLL_BUS2_pllbus_pow_shift                                 (0)
#define SYS_PLL_BUS2_pllbus_fcode_mask                                (0x07FF0000)
#define SYS_PLL_BUS2_pllbus_ncode_mask                                (0x0000FF00)
#define SYS_PLL_BUS2_pllbus_oeb_mask                                  (0x00000004)
#define SYS_PLL_BUS2_pllbus_rstb_mask                                 (0x00000002)
#define SYS_PLL_BUS2_pllbus_pow_mask                                  (0x00000001)
#define SYS_PLL_BUS2_pllbus_fcode(data)                               (0x07FF0000&((data)<<16))
#define SYS_PLL_BUS2_pllbus_ncode(data)                               (0x0000FF00&((data)<<8))
#define SYS_PLL_BUS2_pllbus_oeb(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_BUS2_pllbus_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_BUS2_pllbus_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_BUS2_get_pllbus_fcode(data)                           ((0x07FF0000&(data))>>16)
#define SYS_PLL_BUS2_get_pllbus_ncode(data)                           ((0x0000FF00&(data))>>8)
#define SYS_PLL_BUS2_get_pllbus_oeb(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_BUS2_get_pllbus_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_BUS2_get_pllbus_pow(data)                             (0x00000001&(data))


#define SYS_DVFS_BUS                                                  0x18000428
#define SYS_DVFS_BUS_reg_addr                                         "0xb8000428"
#define SYS_DVFS_BUS_reg                                              0xb8000428
#define SYS_DVFS_BUS_inst_addr                                        "0x010A"
#define SYS_DVFS_BUS_inst                                             0x010A
#define set_SYS_DVFS_BUS_reg(data)                                    (*((volatile unsigned int*)SYS_DVFS_BUS_reg)=data)
#define get_SYS_DVFS_BUS_reg                                          (*((volatile unsigned int*)SYS_DVFS_BUS_reg))
#define SYS_DVFS_BUS_pllbus_bypass_pi_shift                           (31)
#define SYS_DVFS_BUS_pllbus_en_pi_debug_shift                         (30)
#define SYS_DVFS_BUS_pllbus_hs_oc_stop_shift                          (28)
#define SYS_DVFS_BUS_pllbus_pi_cur_sel_shift                          (26)
#define SYS_DVFS_BUS_pllbus_sel_oc_mode_shift                         (24)
#define SYS_DVFS_BUS_pllbus_oc_done_delay_shift                       (16)
#define SYS_DVFS_BUS_pllbus_oc_step_shift                             (4)
#define SYS_DVFS_BUS_pllbus_sdm_order_shift                           (2)
#define SYS_DVFS_BUS_pllbus_oc_done_shift                             (1)
#define SYS_DVFS_BUS_pllbus_oc_en_shift                               (0)
#define SYS_DVFS_BUS_pllbus_bypass_pi_mask                            (0x80000000)
#define SYS_DVFS_BUS_pllbus_en_pi_debug_mask                          (0x40000000)
#define SYS_DVFS_BUS_pllbus_hs_oc_stop_mask                           (0x30000000)
#define SYS_DVFS_BUS_pllbus_pi_cur_sel_mask                           (0x0C000000)
#define SYS_DVFS_BUS_pllbus_sel_oc_mode_mask                          (0x03000000)
#define SYS_DVFS_BUS_pllbus_oc_done_delay_mask                        (0x003F0000)
#define SYS_DVFS_BUS_pllbus_oc_step_mask                              (0x00003FF0)
#define SYS_DVFS_BUS_pllbus_sdm_order_mask                            (0x00000004)
#define SYS_DVFS_BUS_pllbus_oc_done_mask                              (0x00000002)
#define SYS_DVFS_BUS_pllbus_oc_en_mask                                (0x00000001)
#define SYS_DVFS_BUS_pllbus_bypass_pi(data)                           (0x80000000&((data)<<31))
#define SYS_DVFS_BUS_pllbus_en_pi_debug(data)                         (0x40000000&((data)<<30))
#define SYS_DVFS_BUS_pllbus_hs_oc_stop(data)                          (0x30000000&((data)<<28))
#define SYS_DVFS_BUS_pllbus_pi_cur_sel(data)                          (0x0C000000&((data)<<26))
#define SYS_DVFS_BUS_pllbus_sel_oc_mode(data)                         (0x03000000&((data)<<24))
#define SYS_DVFS_BUS_pllbus_oc_done_delay(data)                       (0x003F0000&((data)<<16))
#define SYS_DVFS_BUS_pllbus_oc_step(data)                             (0x00003FF0&((data)<<4))
#define SYS_DVFS_BUS_pllbus_sdm_order(data)                           (0x00000004&((data)<<2))
#define SYS_DVFS_BUS_pllbus_oc_done(data)                             (0x00000002&((data)<<1))
#define SYS_DVFS_BUS_pllbus_oc_en(data)                               (0x00000001&(data))
#define SYS_DVFS_BUS_get_pllbus_bypass_pi(data)                       ((0x80000000&(data))>>31)
#define SYS_DVFS_BUS_get_pllbus_en_pi_debug(data)                     ((0x40000000&(data))>>30)
#define SYS_DVFS_BUS_get_pllbus_hs_oc_stop(data)                      ((0x30000000&(data))>>28)
#define SYS_DVFS_BUS_get_pllbus_pi_cur_sel(data)                      ((0x0C000000&(data))>>26)
#define SYS_DVFS_BUS_get_pllbus_sel_oc_mode(data)                     ((0x03000000&(data))>>24)
#define SYS_DVFS_BUS_get_pllbus_oc_done_delay(data)                   ((0x003F0000&(data))>>16)
#define SYS_DVFS_BUS_get_pllbus_oc_step(data)                         ((0x00003FF0&(data))>>4)
#define SYS_DVFS_BUS_get_pllbus_sdm_order(data)                       ((0x00000004&(data))>>2)
#define SYS_DVFS_BUS_get_pllbus_oc_done(data)                         ((0x00000002&(data))>>1)
#define SYS_DVFS_BUS_get_pllbus_oc_en(data)                           (0x00000001&(data))


#define SYS_DVFS_BUS2                                                 0x1800042c
#define SYS_DVFS_BUS2_reg_addr                                        "0xb800042c"
#define SYS_DVFS_BUS2_reg                                             0xb800042c
#define SYS_DVFS_BUS2_inst_addr                                       "0x010B"
#define SYS_DVFS_BUS2_inst                                            0x010B
#define set_SYS_DVFS_BUS2_reg(data)                                   (*((volatile unsigned int*)SYS_DVFS_BUS2_reg)=data)
#define get_SYS_DVFS_BUS2_reg                                         (*((volatile unsigned int*)SYS_DVFS_BUS2_reg))
#define SYS_DVFS_BUS2_pllbus_fcode_dbg_shift                          (16)
#define SYS_DVFS_BUS2_pllbus_ncode_dbg_shift                          (8)
#define SYS_DVFS_BUS2_pllbus_fcode_dbg_mask                           (0x07FF0000)
#define SYS_DVFS_BUS2_pllbus_ncode_dbg_mask                           (0x0000FF00)
#define SYS_DVFS_BUS2_pllbus_fcode_dbg(data)                          (0x07FF0000&((data)<<16))
#define SYS_DVFS_BUS2_pllbus_ncode_dbg(data)                          (0x0000FF00&((data)<<8))
#define SYS_DVFS_BUS2_get_pllbus_fcode_dbg(data)                      ((0x07FF0000&(data))>>16)
#define SYS_DVFS_BUS2_get_pllbus_ncode_dbg(data)                      ((0x0000FF00&(data))>>8)


#define SYS_PLL_BUSH1                                                 0x18000430
#define SYS_PLL_BUSH1_reg_addr                                        "0xb8000430"
#define SYS_PLL_BUSH1_reg                                             0xb8000430
#define SYS_PLL_BUSH1_inst_addr                                       "0x010C"
#define SYS_PLL_BUSH1_inst                                            0x010C
#define set_SYS_PLL_BUSH1_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_BUSH1_reg)=data)
#define get_SYS_PLL_BUSH1_reg                                         (*((volatile unsigned int*)SYS_PLL_BUSH1_reg))
#define SYS_PLL_BUSH1_pllbus_wdset_h_shift                            (21)
#define SYS_PLL_BUSH1_pllbus_wdrst_h_shift                            (20)
#define SYS_PLL_BUSH1_pllbus_lpf_cs_h_shift                           (16)
#define SYS_PLL_BUSH1_pllbus_testsel_h_shift                          (13)
#define SYS_PLL_BUSH1_pllbus_sel_cco_h_shift                          (12)
#define SYS_PLL_BUSH1_pllbus_icp_h_shift                              (8)
#define SYS_PLL_BUSH1_pllbus_dbug_en_h_shift                          (7)
#define SYS_PLL_BUSH1_pllbus_pdiv_bps_h_shift                         (6)
#define SYS_PLL_BUSH1_pllbus_pdiv_h_shift                             (4)
#define SYS_PLL_BUSH1_pllbus_lpf_rs_h_shift                           (0)
#define SYS_PLL_BUSH1_pllbus_wdset_h_mask                             (0x00200000)
#define SYS_PLL_BUSH1_pllbus_wdrst_h_mask                             (0x00100000)
#define SYS_PLL_BUSH1_pllbus_lpf_cs_h_mask                            (0x00030000)
#define SYS_PLL_BUSH1_pllbus_testsel_h_mask                           (0x00002000)
#define SYS_PLL_BUSH1_pllbus_sel_cco_h_mask                           (0x00001000)
#define SYS_PLL_BUSH1_pllbus_icp_h_mask                               (0x00000F00)
#define SYS_PLL_BUSH1_pllbus_dbug_en_h_mask                           (0x00000080)
#define SYS_PLL_BUSH1_pllbus_pdiv_bps_h_mask                          (0x00000040)
#define SYS_PLL_BUSH1_pllbus_pdiv_h_mask                              (0x00000030)
#define SYS_PLL_BUSH1_pllbus_lpf_rs_h_mask                            (0x00000007)
#define SYS_PLL_BUSH1_pllbus_wdset_h(data)                            (0x00200000&((data)<<21))
#define SYS_PLL_BUSH1_pllbus_wdrst_h(data)                            (0x00100000&((data)<<20))
#define SYS_PLL_BUSH1_pllbus_lpf_cs_h(data)                           (0x00030000&((data)<<16))
#define SYS_PLL_BUSH1_pllbus_testsel_h(data)                          (0x00002000&((data)<<13))
#define SYS_PLL_BUSH1_pllbus_sel_cco_h(data)                          (0x00001000&((data)<<12))
#define SYS_PLL_BUSH1_pllbus_icp_h(data)                              (0x00000F00&((data)<<8))
#define SYS_PLL_BUSH1_pllbus_dbug_en_h(data)                          (0x00000080&((data)<<7))
#define SYS_PLL_BUSH1_pllbus_pdiv_bps_h(data)                         (0x00000040&((data)<<6))
#define SYS_PLL_BUSH1_pllbus_pdiv_h(data)                             (0x00000030&((data)<<4))
#define SYS_PLL_BUSH1_pllbus_lpf_rs_h(data)                           (0x00000007&(data))
#define SYS_PLL_BUSH1_get_pllbus_wdset_h(data)                        ((0x00200000&(data))>>21)
#define SYS_PLL_BUSH1_get_pllbus_wdrst_h(data)                        ((0x00100000&(data))>>20)
#define SYS_PLL_BUSH1_get_pllbus_lpf_cs_h(data)                       ((0x00030000&(data))>>16)
#define SYS_PLL_BUSH1_get_pllbus_testsel_h(data)                      ((0x00002000&(data))>>13)
#define SYS_PLL_BUSH1_get_pllbus_sel_cco_h(data)                      ((0x00001000&(data))>>12)
#define SYS_PLL_BUSH1_get_pllbus_icp_h(data)                          ((0x00000F00&(data))>>8)
#define SYS_PLL_BUSH1_get_pllbus_dbug_en_h(data)                      ((0x00000080&(data))>>7)
#define SYS_PLL_BUSH1_get_pllbus_pdiv_bps_h(data)                     ((0x00000040&(data))>>6)
#define SYS_PLL_BUSH1_get_pllbus_pdiv_h(data)                         ((0x00000030&(data))>>4)
#define SYS_PLL_BUSH1_get_pllbus_lpf_rs_h(data)                       (0x00000007&(data))


#define SYS_PLL_BUSH2                                                 0x18000434
#define SYS_PLL_BUSH2_reg_addr                                        "0xb8000434"
#define SYS_PLL_BUSH2_reg                                             0xb8000434
#define SYS_PLL_BUSH2_inst_addr                                       "0x010D"
#define SYS_PLL_BUSH2_inst                                            0x010D
#define set_SYS_PLL_BUSH2_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_BUSH2_reg)=data)
#define get_SYS_PLL_BUSH2_reg                                         (*((volatile unsigned int*)SYS_PLL_BUSH2_reg))
#define SYS_PLL_BUSH2_pllbus_fcode_h_shift                            (16)
#define SYS_PLL_BUSH2_pllbus_ncode_h_shift                            (8)
#define SYS_PLL_BUSH2_pllbus_oeb_h_shift                              (2)
#define SYS_PLL_BUSH2_pllbus_rstb_h_shift                             (1)
#define SYS_PLL_BUSH2_pllbus_pow_h_shift                              (0)
#define SYS_PLL_BUSH2_pllbus_fcode_h_mask                             (0x07FF0000)
#define SYS_PLL_BUSH2_pllbus_ncode_h_mask                             (0x0000FF00)
#define SYS_PLL_BUSH2_pllbus_oeb_h_mask                               (0x00000004)
#define SYS_PLL_BUSH2_pllbus_rstb_h_mask                              (0x00000002)
#define SYS_PLL_BUSH2_pllbus_pow_h_mask                               (0x00000001)
#define SYS_PLL_BUSH2_pllbus_fcode_h(data)                            (0x07FF0000&((data)<<16))
#define SYS_PLL_BUSH2_pllbus_ncode_h(data)                            (0x0000FF00&((data)<<8))
#define SYS_PLL_BUSH2_pllbus_oeb_h(data)                              (0x00000004&((data)<<2))
#define SYS_PLL_BUSH2_pllbus_rstb_h(data)                             (0x00000002&((data)<<1))
#define SYS_PLL_BUSH2_pllbus_pow_h(data)                              (0x00000001&(data))
#define SYS_PLL_BUSH2_get_pllbus_fcode_h(data)                        ((0x07FF0000&(data))>>16)
#define SYS_PLL_BUSH2_get_pllbus_ncode_h(data)                        ((0x0000FF00&(data))>>8)
#define SYS_PLL_BUSH2_get_pllbus_oeb_h(data)                          ((0x00000004&(data))>>2)
#define SYS_PLL_BUSH2_get_pllbus_rstb_h(data)                         ((0x00000002&(data))>>1)
#define SYS_PLL_BUSH2_get_pllbus_pow_h(data)                          (0x00000001&(data))


#define SYS_DVFS_BUSH                                                 0x18000438
#define SYS_DVFS_BUSH_reg_addr                                        "0xb8000438"
#define SYS_DVFS_BUSH_reg                                             0xb8000438
#define SYS_DVFS_BUSH_inst_addr                                       "0x010E"
#define SYS_DVFS_BUSH_inst                                            0x010E
#define set_SYS_DVFS_BUSH_reg(data)                                   (*((volatile unsigned int*)SYS_DVFS_BUSH_reg)=data)
#define get_SYS_DVFS_BUSH_reg                                         (*((volatile unsigned int*)SYS_DVFS_BUSH_reg))
#define SYS_DVFS_BUSH_pllbus_bypass_pi_h_shift                        (31)
#define SYS_DVFS_BUSH_pllbus_en_pi_debug_h_shift                      (30)
#define SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_shift                       (28)
#define SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_shift                       (26)
#define SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_shift                      (24)
#define SYS_DVFS_BUSH_pllbus_oc_done_delay_h_shift                    (16)
#define SYS_DVFS_BUSH_pllbus_oc_step_h_shift                          (4)
#define SYS_DVFS_BUSH_pllbus_sdm_order_h_shift                        (2)
#define SYS_DVFS_BUSH_pllbus_oc_done_h_shift                          (1)
#define SYS_DVFS_BUSH_pllbus_oc_en_h_shift                            (0)
#define SYS_DVFS_BUSH_pllbus_bypass_pi_h_mask                         (0x80000000)
#define SYS_DVFS_BUSH_pllbus_en_pi_debug_h_mask                       (0x40000000)
#define SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_mask                        (0x30000000)
#define SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_mask                        (0x0C000000)
#define SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_mask                       (0x03000000)
#define SYS_DVFS_BUSH_pllbus_oc_done_delay_h_mask                     (0x003F0000)
#define SYS_DVFS_BUSH_pllbus_oc_step_h_mask                           (0x00003FF0)
#define SYS_DVFS_BUSH_pllbus_sdm_order_h_mask                         (0x00000004)
#define SYS_DVFS_BUSH_pllbus_oc_done_h_mask                           (0x00000002)
#define SYS_DVFS_BUSH_pllbus_oc_en_h_mask                             (0x00000001)
#define SYS_DVFS_BUSH_pllbus_bypass_pi_h(data)                        (0x80000000&((data)<<31))
#define SYS_DVFS_BUSH_pllbus_en_pi_debug_h(data)                      (0x40000000&((data)<<30))
#define SYS_DVFS_BUSH_pllbus_hs_oc_stop_h(data)                       (0x30000000&((data)<<28))
#define SYS_DVFS_BUSH_pllbus_pi_cur_sel_h(data)                       (0x0C000000&((data)<<26))
#define SYS_DVFS_BUSH_pllbus_sel_oc_mode_h(data)                      (0x03000000&((data)<<24))
#define SYS_DVFS_BUSH_pllbus_oc_done_delay_h(data)                    (0x003F0000&((data)<<16))
#define SYS_DVFS_BUSH_pllbus_oc_step_h(data)                          (0x00003FF0&((data)<<4))
#define SYS_DVFS_BUSH_pllbus_sdm_order_h(data)                        (0x00000004&((data)<<2))
#define SYS_DVFS_BUSH_pllbus_oc_done_h(data)                          (0x00000002&((data)<<1))
#define SYS_DVFS_BUSH_pllbus_oc_en_h(data)                            (0x00000001&(data))
#define SYS_DVFS_BUSH_get_pllbus_bypass_pi_h(data)                    ((0x80000000&(data))>>31)
#define SYS_DVFS_BUSH_get_pllbus_en_pi_debug_h(data)                  ((0x40000000&(data))>>30)
#define SYS_DVFS_BUSH_get_pllbus_hs_oc_stop_h(data)                   ((0x30000000&(data))>>28)
#define SYS_DVFS_BUSH_get_pllbus_pi_cur_sel_h(data)                   ((0x0C000000&(data))>>26)
#define SYS_DVFS_BUSH_get_pllbus_sel_oc_mode_h(data)                  ((0x03000000&(data))>>24)
#define SYS_DVFS_BUSH_get_pllbus_oc_done_delay_h(data)                ((0x003F0000&(data))>>16)
#define SYS_DVFS_BUSH_get_pllbus_oc_step_h(data)                      ((0x00003FF0&(data))>>4)
#define SYS_DVFS_BUSH_get_pllbus_sdm_order_h(data)                    ((0x00000004&(data))>>2)
#define SYS_DVFS_BUSH_get_pllbus_oc_done_h(data)                      ((0x00000002&(data))>>1)
#define SYS_DVFS_BUSH_get_pllbus_oc_en_h(data)                        (0x00000001&(data))


#define SYS_DVFS_BUSH2                                                0x1800043c
#define SYS_DVFS_BUSH2_reg_addr                                       "0xb800043c"
#define SYS_DVFS_BUSH2_reg                                            0xb800043c
#define SYS_DVFS_BUSH2_inst_addr                                      "0x010F"
#define SYS_DVFS_BUSH2_inst                                           0x010F
#define set_SYS_DVFS_BUSH2_reg(data)                                  (*((volatile unsigned int*)SYS_DVFS_BUSH2_reg)=data)
#define get_SYS_DVFS_BUSH2_reg                                        (*((volatile unsigned int*)SYS_DVFS_BUSH2_reg))
#define SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_shift                       (16)
#define SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_shift                       (8)
#define SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_mask                        (0x07FF0000)
#define SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_mask                        (0x0000FF00)
#define SYS_DVFS_BUSH2_pllbus_fcode_dbg_h(data)                       (0x07FF0000&((data)<<16))
#define SYS_DVFS_BUSH2_pllbus_ncode_dbg_h(data)                       (0x0000FF00&((data)<<8))
#define SYS_DVFS_BUSH2_get_pllbus_fcode_dbg_h(data)                   ((0x07FF0000&(data))>>16)
#define SYS_DVFS_BUSH2_get_pllbus_ncode_dbg_h(data)                   ((0x0000FF00&(data))>>8)


#define SYS_PLL_GPU1                                                  0x18000450
#define SYS_PLL_GPU1_reg_addr                                         "0xb8000450"
#define SYS_PLL_GPU1_reg                                              0xb8000450
#define SYS_PLL_GPU1_inst_addr                                        "0x0114"
#define SYS_PLL_GPU1_inst                                             0x0114
#define set_SYS_PLL_GPU1_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_GPU1_reg)=data)
#define get_SYS_PLL_GPU1_reg                                          (*((volatile unsigned int*)SYS_PLL_GPU1_reg))
#define SYS_PLL_GPU1_pllgpu_wdset_shift                               (21)
#define SYS_PLL_GPU1_pllgpu_wdrst_shift                               (20)
#define SYS_PLL_GPU1_pllgpu_lpf_cs_shift                              (16)
#define SYS_PLL_GPU1_pllgpu_testsel_shift                             (13)
#define SYS_PLL_GPU1_pllgpu_sel_cco_shift                             (12)
#define SYS_PLL_GPU1_pllgpu_icp_shift                                 (8)
#define SYS_PLL_GPU1_pllgpu_dbug_en_shift                             (7)
#define SYS_PLL_GPU1_pllgpu_pdiv_bps_shift                            (6)
#define SYS_PLL_GPU1_pllgpu_pdiv_shift                                (4)
#define SYS_PLL_GPU1_pllgpu_lpf_rs_shift                              (0)
#define SYS_PLL_GPU1_pllgpu_wdset_mask                                (0x00200000)
#define SYS_PLL_GPU1_pllgpu_wdrst_mask                                (0x00100000)
#define SYS_PLL_GPU1_pllgpu_lpf_cs_mask                               (0x00030000)
#define SYS_PLL_GPU1_pllgpu_testsel_mask                              (0x00002000)
#define SYS_PLL_GPU1_pllgpu_sel_cco_mask                              (0x00001000)
#define SYS_PLL_GPU1_pllgpu_icp_mask                                  (0x00000F00)
#define SYS_PLL_GPU1_pllgpu_dbug_en_mask                              (0x00000080)
#define SYS_PLL_GPU1_pllgpu_pdiv_bps_mask                             (0x00000040)
#define SYS_PLL_GPU1_pllgpu_pdiv_mask                                 (0x00000030)
#define SYS_PLL_GPU1_pllgpu_lpf_rs_mask                               (0x00000007)
#define SYS_PLL_GPU1_pllgpu_wdset(data)                               (0x00200000&((data)<<21))
#define SYS_PLL_GPU1_pllgpu_wdrst(data)                               (0x00100000&((data)<<20))
#define SYS_PLL_GPU1_pllgpu_lpf_cs(data)                              (0x00030000&((data)<<16))
#define SYS_PLL_GPU1_pllgpu_testsel(data)                             (0x00002000&((data)<<13))
#define SYS_PLL_GPU1_pllgpu_sel_cco(data)                             (0x00001000&((data)<<12))
#define SYS_PLL_GPU1_pllgpu_icp(data)                                 (0x00000F00&((data)<<8))
#define SYS_PLL_GPU1_pllgpu_dbug_en(data)                             (0x00000080&((data)<<7))
#define SYS_PLL_GPU1_pllgpu_pdiv_bps(data)                            (0x00000040&((data)<<6))
#define SYS_PLL_GPU1_pllgpu_pdiv(data)                                (0x00000030&((data)<<4))
#define SYS_PLL_GPU1_pllgpu_lpf_rs(data)                              (0x00000007&(data))
#define SYS_PLL_GPU1_get_pllgpu_wdset(data)                           ((0x00200000&(data))>>21)
#define SYS_PLL_GPU1_get_pllgpu_wdrst(data)                           ((0x00100000&(data))>>20)
#define SYS_PLL_GPU1_get_pllgpu_lpf_cs(data)                          ((0x00030000&(data))>>16)
#define SYS_PLL_GPU1_get_pllgpu_testsel(data)                         ((0x00002000&(data))>>13)
#define SYS_PLL_GPU1_get_pllgpu_sel_cco(data)                         ((0x00001000&(data))>>12)
#define SYS_PLL_GPU1_get_pllgpu_icp(data)                             ((0x00000F00&(data))>>8)
#define SYS_PLL_GPU1_get_pllgpu_dbug_en(data)                         ((0x00000080&(data))>>7)
#define SYS_PLL_GPU1_get_pllgpu_pdiv_bps(data)                        ((0x00000040&(data))>>6)
#define SYS_PLL_GPU1_get_pllgpu_pdiv(data)                            ((0x00000030&(data))>>4)
#define SYS_PLL_GPU1_get_pllgpu_lpf_rs(data)                          (0x00000007&(data))


#define SYS_PLL_GPU2                                                  0x18000454
#define SYS_PLL_GPU2_reg_addr                                         "0xb8000454"
#define SYS_PLL_GPU2_reg                                              0xb8000454
#define SYS_PLL_GPU2_inst_addr                                        "0x0115"
#define SYS_PLL_GPU2_inst                                             0x0115
#define set_SYS_PLL_GPU2_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_GPU2_reg)=data)
#define get_SYS_PLL_GPU2_reg                                          (*((volatile unsigned int*)SYS_PLL_GPU2_reg))
#define SYS_PLL_GPU2_pllgpu_fcode_shift                               (16)
#define SYS_PLL_GPU2_pllgpu_ncode_shift                               (8)
#define SYS_PLL_GPU2_pllgpu_oeb_shift                                 (2)
#define SYS_PLL_GPU2_pllgpu_rstb_shift                                (1)
#define SYS_PLL_GPU2_pllgpu_pow_shift                                 (0)
#define SYS_PLL_GPU2_pllgpu_fcode_mask                                (0x07FF0000)
#define SYS_PLL_GPU2_pllgpu_ncode_mask                                (0x0000FF00)
#define SYS_PLL_GPU2_pllgpu_oeb_mask                                  (0x00000004)
#define SYS_PLL_GPU2_pllgpu_rstb_mask                                 (0x00000002)
#define SYS_PLL_GPU2_pllgpu_pow_mask                                  (0x00000001)
#define SYS_PLL_GPU2_pllgpu_fcode(data)                               (0x07FF0000&((data)<<16))
#define SYS_PLL_GPU2_pllgpu_ncode(data)                               (0x0000FF00&((data)<<8))
#define SYS_PLL_GPU2_pllgpu_oeb(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_GPU2_pllgpu_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_GPU2_pllgpu_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_GPU2_get_pllgpu_fcode(data)                           ((0x07FF0000&(data))>>16)
#define SYS_PLL_GPU2_get_pllgpu_ncode(data)                           ((0x0000FF00&(data))>>8)
#define SYS_PLL_GPU2_get_pllgpu_oeb(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_GPU2_get_pllgpu_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_GPU2_get_pllgpu_pow(data)                             (0x00000001&(data))


#define SYS_DVFS_GPU                                                  0x18000448
#define SYS_DVFS_GPU_reg_addr                                         "0xb8000448"
#define SYS_DVFS_GPU_reg                                              0xb8000448
#define SYS_DVFS_GPU_inst_addr                                        "0x0112"
#define SYS_DVFS_GPU_inst                                             0x0112
#define set_SYS_DVFS_GPU_reg(data)                                    (*((volatile unsigned int*)SYS_DVFS_GPU_reg)=data)
#define get_SYS_DVFS_GPU_reg                                          (*((volatile unsigned int*)SYS_DVFS_GPU_reg))
#define SYS_DVFS_GPU_pllgpu_bypass_pi_shift                           (31)
#define SYS_DVFS_GPU_pllgpu_en_pi_debug_shift                         (30)
#define SYS_DVFS_GPU_pllgpu_hs_oc_stop_shift                          (28)
#define SYS_DVFS_GPU_pllgpu_pi_cur_sel_shift                          (26)
#define SYS_DVFS_GPU_pllgpu_sel_oc_mode_shift                         (24)
#define SYS_DVFS_GPU_pllgpu_oc_done_delay_shift                       (16)
#define SYS_DVFS_GPU_pllgpu_oc_step_shift                             (4)
#define SYS_DVFS_GPU_pllgpu_sdm_order_shift                           (2)
#define SYS_DVFS_GPU_pllgpu_oc_done_shift                             (1)
#define SYS_DVFS_GPU_pllgpu_oc_en_shift                               (0)
#define SYS_DVFS_GPU_pllgpu_bypass_pi_mask                            (0x80000000)
#define SYS_DVFS_GPU_pllgpu_en_pi_debug_mask                          (0x40000000)
#define SYS_DVFS_GPU_pllgpu_hs_oc_stop_mask                           (0x30000000)
#define SYS_DVFS_GPU_pllgpu_pi_cur_sel_mask                           (0x0C000000)
#define SYS_DVFS_GPU_pllgpu_sel_oc_mode_mask                          (0x03000000)
#define SYS_DVFS_GPU_pllgpu_oc_done_delay_mask                        (0x003F0000)
#define SYS_DVFS_GPU_pllgpu_oc_step_mask                              (0x00003FF0)
#define SYS_DVFS_GPU_pllgpu_sdm_order_mask                            (0x00000004)
#define SYS_DVFS_GPU_pllgpu_oc_done_mask                              (0x00000002)
#define SYS_DVFS_GPU_pllgpu_oc_en_mask                                (0x00000001)
#define SYS_DVFS_GPU_pllgpu_bypass_pi(data)                           (0x80000000&((data)<<31))
#define SYS_DVFS_GPU_pllgpu_en_pi_debug(data)                         (0x40000000&((data)<<30))
#define SYS_DVFS_GPU_pllgpu_hs_oc_stop(data)                          (0x30000000&((data)<<28))
#define SYS_DVFS_GPU_pllgpu_pi_cur_sel(data)                          (0x0C000000&((data)<<26))
#define SYS_DVFS_GPU_pllgpu_sel_oc_mode(data)                         (0x03000000&((data)<<24))
#define SYS_DVFS_GPU_pllgpu_oc_done_delay(data)                       (0x003F0000&((data)<<16))
#define SYS_DVFS_GPU_pllgpu_oc_step(data)                             (0x00003FF0&((data)<<4))
#define SYS_DVFS_GPU_pllgpu_sdm_order(data)                           (0x00000004&((data)<<2))
#define SYS_DVFS_GPU_pllgpu_oc_done(data)                             (0x00000002&((data)<<1))
#define SYS_DVFS_GPU_pllgpu_oc_en(data)                               (0x00000001&(data))
#define SYS_DVFS_GPU_get_pllgpu_bypass_pi(data)                       ((0x80000000&(data))>>31)
#define SYS_DVFS_GPU_get_pllgpu_en_pi_debug(data)                     ((0x40000000&(data))>>30)
#define SYS_DVFS_GPU_get_pllgpu_hs_oc_stop(data)                      ((0x30000000&(data))>>28)
#define SYS_DVFS_GPU_get_pllgpu_pi_cur_sel(data)                      ((0x0C000000&(data))>>26)
#define SYS_DVFS_GPU_get_pllgpu_sel_oc_mode(data)                     ((0x03000000&(data))>>24)
#define SYS_DVFS_GPU_get_pllgpu_oc_done_delay(data)                   ((0x003F0000&(data))>>16)
#define SYS_DVFS_GPU_get_pllgpu_oc_step(data)                         ((0x00003FF0&(data))>>4)
#define SYS_DVFS_GPU_get_pllgpu_sdm_order(data)                       ((0x00000004&(data))>>2)
#define SYS_DVFS_GPU_get_pllgpu_oc_done(data)                         ((0x00000002&(data))>>1)
#define SYS_DVFS_GPU_get_pllgpu_oc_en(data)                           (0x00000001&(data))


#define SYS_DVFS_GPU2                                                 0x1800044c
#define SYS_DVFS_GPU2_reg_addr                                        "0xb800044c"
#define SYS_DVFS_GPU2_reg                                             0xb800044c
#define SYS_DVFS_GPU2_inst_addr                                       "0x0113"
#define SYS_DVFS_GPU2_inst                                            0x0113
#define set_SYS_DVFS_GPU2_reg(data)                                   (*((volatile unsigned int*)SYS_DVFS_GPU2_reg)=data)
#define get_SYS_DVFS_GPU2_reg                                         (*((volatile unsigned int*)SYS_DVFS_GPU2_reg))
#define SYS_DVFS_GPU2_pllgpu_fcode_dbg_shift                          (16)
#define SYS_DVFS_GPU2_pllgpu_ncode_dbg_shift                          (8)
#define SYS_DVFS_GPU2_pllgpu_fcode_dbg_mask                           (0x07FF0000)
#define SYS_DVFS_GPU2_pllgpu_ncode_dbg_mask                           (0x0000FF00)
#define SYS_DVFS_GPU2_pllgpu_fcode_dbg(data)                          (0x07FF0000&((data)<<16))
#define SYS_DVFS_GPU2_pllgpu_ncode_dbg(data)                          (0x0000FF00&((data)<<8))
#define SYS_DVFS_GPU2_get_pllgpu_fcode_dbg(data)                      ((0x07FF0000&(data))>>16)
#define SYS_DVFS_GPU2_get_pllgpu_ncode_dbg(data)                      ((0x0000FF00&(data))>>8)


#define SYS_PLL_VODMA1                                                0x18000460
#define SYS_PLL_VODMA1_reg_addr                                       "0xb8000460"
#define SYS_PLL_VODMA1_reg                                            0xb8000460
#define SYS_PLL_VODMA1_inst_addr                                      "0x0118"
#define SYS_PLL_VODMA1_inst                                           0x0118
#define set_SYS_PLL_VODMA1_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_VODMA1_reg)=data)
#define get_SYS_PLL_VODMA1_reg                                        (*((volatile unsigned int*)SYS_PLL_VODMA1_reg))
#define SYS_PLL_VODMA1_pllvodma_n_shift                               (20)
#define SYS_PLL_VODMA1_pllvodma_m_shift                               (12)
#define SYS_PLL_VODMA1_pllvodma_ip_shift                              (9)
#define SYS_PLL_VODMA1_pllvodma_o_shift                               (7)
#define SYS_PLL_VODMA1_pllvodma_wdset_shift                           (6)
#define SYS_PLL_VODMA1_pllvodma_wdrst_shift                           (5)
#define SYS_PLL_VODMA1_pllvodma_cs_shift                              (3)
#define SYS_PLL_VODMA1_pllvodma_rs_shift                              (0)
#define SYS_PLL_VODMA1_pllvodma_n_mask                                (0x00300000)
#define SYS_PLL_VODMA1_pllvodma_m_mask                                (0x000FF000)
#define SYS_PLL_VODMA1_pllvodma_ip_mask                               (0x00000E00)
#define SYS_PLL_VODMA1_pllvodma_o_mask                                (0x00000180)
#define SYS_PLL_VODMA1_pllvodma_wdset_mask                            (0x00000040)
#define SYS_PLL_VODMA1_pllvodma_wdrst_mask                            (0x00000020)
#define SYS_PLL_VODMA1_pllvodma_cs_mask                               (0x00000018)
#define SYS_PLL_VODMA1_pllvodma_rs_mask                               (0x00000007)
#define SYS_PLL_VODMA1_pllvodma_n(data)                               (0x00300000&((data)<<20))
#define SYS_PLL_VODMA1_pllvodma_m(data)                               (0x000FF000&((data)<<12))
#define SYS_PLL_VODMA1_pllvodma_ip(data)                              (0x00000E00&((data)<<9))
#define SYS_PLL_VODMA1_pllvodma_o(data)                               (0x00000180&((data)<<7))
#define SYS_PLL_VODMA1_pllvodma_wdset(data)                           (0x00000040&((data)<<6))
#define SYS_PLL_VODMA1_pllvodma_wdrst(data)                           (0x00000020&((data)<<5))
#define SYS_PLL_VODMA1_pllvodma_cs(data)                              (0x00000018&((data)<<3))
#define SYS_PLL_VODMA1_pllvodma_rs(data)                              (0x00000007&(data))
#define SYS_PLL_VODMA1_get_pllvodma_n(data)                           ((0x00300000&(data))>>20)
#define SYS_PLL_VODMA1_get_pllvodma_m(data)                           ((0x000FF000&(data))>>12)
#define SYS_PLL_VODMA1_get_pllvodma_ip(data)                          ((0x00000E00&(data))>>9)
#define SYS_PLL_VODMA1_get_pllvodma_o(data)                           ((0x00000180&(data))>>7)
#define SYS_PLL_VODMA1_get_pllvodma_wdset(data)                       ((0x00000040&(data))>>6)
#define SYS_PLL_VODMA1_get_pllvodma_wdrst(data)                       ((0x00000020&(data))>>5)
#define SYS_PLL_VODMA1_get_pllvodma_cs(data)                          ((0x00000018&(data))>>3)
#define SYS_PLL_VODMA1_get_pllvodma_rs(data)                          (0x00000007&(data))


#define SYS_PLL_VODMA2                                                0x18000464
#define SYS_PLL_VODMA2_reg_addr                                       "0xb8000464"
#define SYS_PLL_VODMA2_reg                                            0xb8000464
#define SYS_PLL_VODMA2_inst_addr                                      "0x0119"
#define SYS_PLL_VODMA2_inst                                           0x0119
#define set_SYS_PLL_VODMA2_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_VODMA2_reg)=data)
#define get_SYS_PLL_VODMA2_reg                                        (*((volatile unsigned int*)SYS_PLL_VODMA2_reg))
#define SYS_PLL_VODMA2_pllvodma_reserve_shift                         (4)
#define SYS_PLL_VODMA2_pllvodma_tst_shift                             (3)
#define SYS_PLL_VODMA2_pllvodma_oeb_shift                             (2)
#define SYS_PLL_VODMA2_pllvodma_rstb_shift                            (1)
#define SYS_PLL_VODMA2_pllvodma_pow_shift                             (0)
#define SYS_PLL_VODMA2_pllvodma_reserve_mask                          (0x000003F0)
#define SYS_PLL_VODMA2_pllvodma_tst_mask                              (0x00000008)
#define SYS_PLL_VODMA2_pllvodma_oeb_mask                              (0x00000004)
#define SYS_PLL_VODMA2_pllvodma_rstb_mask                             (0x00000002)
#define SYS_PLL_VODMA2_pllvodma_pow_mask                              (0x00000001)
#define SYS_PLL_VODMA2_pllvodma_reserve(data)                         (0x000003F0&((data)<<4))
#define SYS_PLL_VODMA2_pllvodma_tst(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_VODMA2_pllvodma_oeb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_VODMA2_pllvodma_rstb(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_VODMA2_pllvodma_pow(data)                             (0x00000001&(data))
#define SYS_PLL_VODMA2_get_pllvodma_reserve(data)                     ((0x000003F0&(data))>>4)
#define SYS_PLL_VODMA2_get_pllvodma_tst(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_VODMA2_get_pllvodma_oeb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_VODMA2_get_pllvodma_rstb(data)                        ((0x00000002&(data))>>1)
#define SYS_PLL_VODMA2_get_pllvodma_pow(data)                         (0x00000001&(data))


#define SYS_PLLBUS_TST                                                0x18000468
#define SYS_PLLBUS_TST_reg_addr                                       "0xb8000468"
#define SYS_PLLBUS_TST_reg                                            0xb8000468
#define SYS_PLLBUS_TST_inst_addr                                      "0x011A"
#define SYS_PLLBUS_TST_inst                                           0x011A
#define set_SYS_PLLBUS_TST_reg(data)                                  (*((volatile unsigned int*)SYS_PLLBUS_TST_reg)=data)
#define get_SYS_PLLBUS_TST_reg                                        (*((volatile unsigned int*)SYS_PLLBUS_TST_reg))
#define SYS_PLLBUS_TST_pllbus_reser_shift                             (16)
#define SYS_PLLBUS_TST_pllbus_reg_shift                               (12)
#define SYS_PLLBUS_TST_pllbustst_div_shift                            (8)
#define SYS_PLLBUS_TST_pllbustst_sel_shift                            (0)
#define SYS_PLLBUS_TST_pllbus_reser_mask                              (0x00FF0000)
#define SYS_PLLBUS_TST_pllbus_reg_mask                                (0x00003000)
#define SYS_PLLBUS_TST_pllbustst_div_mask                             (0x00000300)
#define SYS_PLLBUS_TST_pllbustst_sel_mask                             (0x0000001F)
#define SYS_PLLBUS_TST_pllbus_reser(data)                             (0x00FF0000&((data)<<16))
#define SYS_PLLBUS_TST_pllbus_reg(data)                               (0x00003000&((data)<<12))
#define SYS_PLLBUS_TST_pllbustst_div(data)                            (0x00000300&((data)<<8))
#define SYS_PLLBUS_TST_pllbustst_sel(data)                            (0x0000001F&(data))
#define SYS_PLLBUS_TST_get_pllbus_reser(data)                         ((0x00FF0000&(data))>>16)
#define SYS_PLLBUS_TST_get_pllbus_reg(data)                           ((0x00003000&(data))>>12)
#define SYS_PLLBUS_TST_get_pllbustst_div(data)                        ((0x00000300&(data))>>8)
#define SYS_PLLBUS_TST_get_pllbustst_sel(data)                        (0x0000001F&(data))


#define SYS_PLL_DISPA_SD1                                             0x18000470
#define SYS_PLL_DISPA_SD1_reg_addr                                    "0xb8000470"
#define SYS_PLL_DISPA_SD1_reg                                         0xb8000470
#define SYS_PLL_DISPA_SD1_inst_addr                                   "0x011C"
#define SYS_PLL_DISPA_SD1_inst                                        0x011C
#define set_SYS_PLL_DISPA_SD1_reg(data)                               (*((volatile unsigned int*)SYS_PLL_DISPA_SD1_reg)=data)
#define get_SYS_PLL_DISPA_SD1_reg                                     (*((volatile unsigned int*)SYS_PLL_DISPA_SD1_reg))
#define SYS_PLL_DISPA_SD1_pllddsa_n_shift                             (30)
#define SYS_PLL_DISPA_SD1_pllddsa_ip_shift                            (20)
#define SYS_PLL_DISPA_SD1_pllddsa_rs_shift                            (17)
#define SYS_PLL_DISPA_SD1_pllddsa_cs_shift                            (15)
#define SYS_PLL_DISPA_SD1_pllddsa_cp_shift                            (13)
#define SYS_PLL_DISPA_SD1_pllddsa_o_shift                             (4)
#define SYS_PLL_DISPA_SD1_pllddsa_wdmode_shift                        (0)
#define SYS_PLL_DISPA_SD1_pllddsa_n_mask                              (0xC0000000)
#define SYS_PLL_DISPA_SD1_pllddsa_ip_mask                             (0x00F00000)
#define SYS_PLL_DISPA_SD1_pllddsa_rs_mask                             (0x000E0000)
#define SYS_PLL_DISPA_SD1_pllddsa_cs_mask                             (0x00018000)
#define SYS_PLL_DISPA_SD1_pllddsa_cp_mask                             (0x00006000)
#define SYS_PLL_DISPA_SD1_pllddsa_o_mask                              (0x00000030)
#define SYS_PLL_DISPA_SD1_pllddsa_wdmode_mask                         (0x00000003)
#define SYS_PLL_DISPA_SD1_pllddsa_n(data)                             (0xC0000000&((data)<<30))
#define SYS_PLL_DISPA_SD1_pllddsa_ip(data)                            (0x00F00000&((data)<<20))
#define SYS_PLL_DISPA_SD1_pllddsa_rs(data)                            (0x000E0000&((data)<<17))
#define SYS_PLL_DISPA_SD1_pllddsa_cs(data)                            (0x00018000&((data)<<15))
#define SYS_PLL_DISPA_SD1_pllddsa_cp(data)                            (0x00006000&((data)<<13))
#define SYS_PLL_DISPA_SD1_pllddsa_o(data)                             (0x00000030&((data)<<4))
#define SYS_PLL_DISPA_SD1_pllddsa_wdmode(data)                        (0x00000003&(data))
#define SYS_PLL_DISPA_SD1_get_pllddsa_n(data)                         ((0xC0000000&(data))>>30)
#define SYS_PLL_DISPA_SD1_get_pllddsa_ip(data)                        ((0x00F00000&(data))>>20)
#define SYS_PLL_DISPA_SD1_get_pllddsa_rs(data)                        ((0x000E0000&(data))>>17)
#define SYS_PLL_DISPA_SD1_get_pllddsa_cs(data)                        ((0x00018000&(data))>>15)
#define SYS_PLL_DISPA_SD1_get_pllddsa_cp(data)                        ((0x00006000&(data))>>13)
#define SYS_PLL_DISPA_SD1_get_pllddsa_o(data)                         ((0x00000030&(data))>>4)
#define SYS_PLL_DISPA_SD1_get_pllddsa_wdmode(data)                    (0x00000003&(data))


#define SYS_PLL_DISPA_SD2                                             0x18000474
#define SYS_PLL_DISPA_SD2_reg_addr                                    "0xb8000474"
#define SYS_PLL_DISPA_SD2_reg                                         0xb8000474
#define SYS_PLL_DISPA_SD2_inst_addr                                   "0x011D"
#define SYS_PLL_DISPA_SD2_inst                                        0x011D
#define set_SYS_PLL_DISPA_SD2_reg(data)                               (*((volatile unsigned int*)SYS_PLL_DISPA_SD2_reg)=data)
#define get_SYS_PLL_DISPA_SD2_reg                                     (*((volatile unsigned int*)SYS_PLL_DISPA_SD2_reg))
#define SYS_PLL_DISPA_SD2_pllddsa_fcode_shift                         (16)
#define SYS_PLL_DISPA_SD2_pllddsa_ncode_shift                         (8)
#define SYS_PLL_DISPA_SD2_pllddsa_oeb_shift                           (2)
#define SYS_PLL_DISPA_SD2_pllddsa_rstb_shift                          (1)
#define SYS_PLL_DISPA_SD2_pllddsa_pow_shift                           (0)
#define SYS_PLL_DISPA_SD2_pllddsa_fcode_mask                          (0x07FF0000)
#define SYS_PLL_DISPA_SD2_pllddsa_ncode_mask                          (0x0000FF00)
#define SYS_PLL_DISPA_SD2_pllddsa_oeb_mask                            (0x00000004)
#define SYS_PLL_DISPA_SD2_pllddsa_rstb_mask                           (0x00000002)
#define SYS_PLL_DISPA_SD2_pllddsa_pow_mask                            (0x00000001)
#define SYS_PLL_DISPA_SD2_pllddsa_fcode(data)                         (0x07FF0000&((data)<<16))
#define SYS_PLL_DISPA_SD2_pllddsa_ncode(data)                         (0x0000FF00&((data)<<8))
#define SYS_PLL_DISPA_SD2_pllddsa_oeb(data)                           (0x00000004&((data)<<2))
#define SYS_PLL_DISPA_SD2_pllddsa_rstb(data)                          (0x00000002&((data)<<1))
#define SYS_PLL_DISPA_SD2_pllddsa_pow(data)                           (0x00000001&(data))
#define SYS_PLL_DISPA_SD2_get_pllddsa_fcode(data)                     ((0x07FF0000&(data))>>16)
#define SYS_PLL_DISPA_SD2_get_pllddsa_ncode(data)                     ((0x0000FF00&(data))>>8)
#define SYS_PLL_DISPA_SD2_get_pllddsa_oeb(data)                       ((0x00000004&(data))>>2)
#define SYS_PLL_DISPA_SD2_get_pllddsa_rstb(data)                      ((0x00000002&(data))>>1)
#define SYS_PLL_DISPA_SD2_get_pllddsa_pow(data)                       (0x00000001&(data))


#define SYS_PLL_DISPA_SD3                                             0x18000478
#define SYS_PLL_DISPA_SD3_reg_addr                                    "0xb8000478"
#define SYS_PLL_DISPA_SD3_reg                                         0xb8000478
#define SYS_PLL_DISPA_SD3_inst_addr                                   "0x011E"
#define SYS_PLL_DISPA_SD3_inst                                        0x011E
#define set_SYS_PLL_DISPA_SD3_reg(data)                               (*((volatile unsigned int*)SYS_PLL_DISPA_SD3_reg)=data)
#define get_SYS_PLL_DISPA_SD3_reg                                     (*((volatile unsigned int*)SYS_PLL_DISPA_SD3_reg))
#define SYS_PLL_DISPA_SD3_dummy18000478_28_25_shift                   (25)
#define SYS_PLL_DISPA_SD3_dummy18000478_24_shift                      (24)
#define SYS_PLL_DISPA_SD3_dummy18000478_23_shift                      (23)
#define SYS_PLL_DISPA_SD3_dummy18000478_22_shift                      (22)
#define SYS_PLL_DISPA_SD3_dummy18000478_21_shift                      (21)
#define SYS_PLL_DISPA_SD3_dummy18000478_20_shift                      (20)
#define SYS_PLL_DISPA_SD3_dummy18000478_19_shift                      (19)
#define SYS_PLL_DISPA_SD3_dummy18000478_18_shift                      (18)
#define SYS_PLL_DISPA_SD3_dummy18000478_17_shift                      (17)
#define SYS_PLL_DISPA_SD3_dummy18000478_16_shift                      (16)
#define SYS_PLL_DISPA_SD3_dummy18000478_15_shift                      (15)
#define SYS_PLL_DISPA_SD3_pllddsa_vcorb_shift                         (14)
#define SYS_PLL_DISPA_SD3_dummy18000478_13_shift                      (13)
#define SYS_PLL_DISPA_SD3_pllddsa_tst_shift                           (12)
#define SYS_PLL_DISPA_SD3_pllddsa_pstst_shift                         (11)
#define SYS_PLL_DISPA_SD3_dummy18000478_10_shift                      (10)
#define SYS_PLL_DISPA_SD3_dummy18000478_28_25_mask                    (0x1E000000)
#define SYS_PLL_DISPA_SD3_dummy18000478_24_mask                       (0x01000000)
#define SYS_PLL_DISPA_SD3_dummy18000478_23_mask                       (0x00800000)
#define SYS_PLL_DISPA_SD3_dummy18000478_22_mask                       (0x00400000)
#define SYS_PLL_DISPA_SD3_dummy18000478_21_mask                       (0x00200000)
#define SYS_PLL_DISPA_SD3_dummy18000478_20_mask                       (0x00100000)
#define SYS_PLL_DISPA_SD3_dummy18000478_19_mask                       (0x00080000)
#define SYS_PLL_DISPA_SD3_dummy18000478_18_mask                       (0x00040000)
#define SYS_PLL_DISPA_SD3_dummy18000478_17_mask                       (0x00020000)
#define SYS_PLL_DISPA_SD3_dummy18000478_16_mask                       (0x00010000)
#define SYS_PLL_DISPA_SD3_dummy18000478_15_mask                       (0x00008000)
#define SYS_PLL_DISPA_SD3_pllddsa_vcorb_mask                          (0x00004000)
#define SYS_PLL_DISPA_SD3_dummy18000478_13_mask                       (0x00002000)
#define SYS_PLL_DISPA_SD3_pllddsa_tst_mask                            (0x00001000)
#define SYS_PLL_DISPA_SD3_pllddsa_pstst_mask                          (0x00000800)
#define SYS_PLL_DISPA_SD3_dummy18000478_10_mask                       (0x00000400)
#define SYS_PLL_DISPA_SD3_dummy18000478_28_25(data)                   (0x1E000000&((data)<<25))
#define SYS_PLL_DISPA_SD3_dummy18000478_24(data)                      (0x01000000&((data)<<24))
#define SYS_PLL_DISPA_SD3_dummy18000478_23(data)                      (0x00800000&((data)<<23))
#define SYS_PLL_DISPA_SD3_dummy18000478_22(data)                      (0x00400000&((data)<<22))
#define SYS_PLL_DISPA_SD3_dummy18000478_21(data)                      (0x00200000&((data)<<21))
#define SYS_PLL_DISPA_SD3_dummy18000478_20(data)                      (0x00100000&((data)<<20))
#define SYS_PLL_DISPA_SD3_dummy18000478_19(data)                      (0x00080000&((data)<<19))
#define SYS_PLL_DISPA_SD3_dummy18000478_18(data)                      (0x00040000&((data)<<18))
#define SYS_PLL_DISPA_SD3_dummy18000478_17(data)                      (0x00020000&((data)<<17))
#define SYS_PLL_DISPA_SD3_dummy18000478_16(data)                      (0x00010000&((data)<<16))
#define SYS_PLL_DISPA_SD3_dummy18000478_15(data)                      (0x00008000&((data)<<15))
#define SYS_PLL_DISPA_SD3_pllddsa_vcorb(data)                         (0x00004000&((data)<<14))
#define SYS_PLL_DISPA_SD3_dummy18000478_13(data)                      (0x00002000&((data)<<13))
#define SYS_PLL_DISPA_SD3_pllddsa_tst(data)                           (0x00001000&((data)<<12))
#define SYS_PLL_DISPA_SD3_pllddsa_pstst(data)                         (0x00000800&((data)<<11))
#define SYS_PLL_DISPA_SD3_dummy18000478_10(data)                      (0x00000400&((data)<<10))
#define SYS_PLL_DISPA_SD3_get_dummy18000478_28_25(data)               ((0x1E000000&(data))>>25)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_24(data)                  ((0x01000000&(data))>>24)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_23(data)                  ((0x00800000&(data))>>23)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_22(data)                  ((0x00400000&(data))>>22)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_21(data)                  ((0x00200000&(data))>>21)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_20(data)                  ((0x00100000&(data))>>20)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_19(data)                  ((0x00080000&(data))>>19)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_18(data)                  ((0x00040000&(data))>>18)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_17(data)                  ((0x00020000&(data))>>17)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_16(data)                  ((0x00010000&(data))>>16)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_15(data)                  ((0x00008000&(data))>>15)
#define SYS_PLL_DISPA_SD3_get_pllddsa_vcorb(data)                     ((0x00004000&(data))>>14)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_13(data)                  ((0x00002000&(data))>>13)
#define SYS_PLL_DISPA_SD3_get_pllddsa_tst(data)                       ((0x00001000&(data))>>12)
#define SYS_PLL_DISPA_SD3_get_pllddsa_pstst(data)                     ((0x00000800&(data))>>11)
#define SYS_PLL_DISPA_SD3_get_dummy18000478_10(data)                  ((0x00000400&(data))>>10)


#define SYS_PLL_DISPA_SD4                                             0x1800047c
#define SYS_PLL_DISPA_SD4_reg_addr                                    "0xb800047c"
#define SYS_PLL_DISPA_SD4_reg                                         0xb800047c
#define SYS_PLL_DISPA_SD4_inst_addr                                   "0x011F"
#define SYS_PLL_DISPA_SD4_inst                                        0x011F
#define set_SYS_PLL_DISPA_SD4_reg(data)                               (*((volatile unsigned int*)SYS_PLL_DISPA_SD4_reg)=data)
#define get_SYS_PLL_DISPA_SD4_reg                                     (*((volatile unsigned int*)SYS_PLL_DISPA_SD4_reg))
#define SYS_PLL_DISPA_SD4_dummy1800047c_30_shift                      (30)
#define SYS_PLL_DISPA_SD4_psaud1a_fupdn_shift                         (29)
#define SYS_PLL_DISPA_SD4_psaud1a_div_shift                           (28)
#define SYS_PLL_DISPA_SD4_dummy1800047c_27_shift                      (27)
#define SYS_PLL_DISPA_SD4_psaud1a_tst_shift                           (26)
#define SYS_PLL_DISPA_SD4_psaud1a_psen_shift                          (25)
#define SYS_PLL_DISPA_SD4_dummy1800047c_24_shift                      (24)
#define SYS_PLL_DISPA_SD4_psaud2a_fupdn_shift                         (23)
#define SYS_PLL_DISPA_SD4_psaud2a_div_shift                           (22)
#define SYS_PLL_DISPA_SD4_psaud2a_tst_shift                           (21)
#define SYS_PLL_DISPA_SD4_psaud2a_psen_shift                          (20)
#define SYS_PLL_DISPA_SD4_psaud1a_oeb_shift                           (3)
#define SYS_PLL_DISPA_SD4_psaud1a_rstb_shift                          (2)
#define SYS_PLL_DISPA_SD4_psaud2a_oeb_shift                           (1)
#define SYS_PLL_DISPA_SD4_psaud2a_rstb_shift                          (0)
#define SYS_PLL_DISPA_SD4_dummy1800047c_30_mask                       (0x40000000)
#define SYS_PLL_DISPA_SD4_psaud1a_fupdn_mask                          (0x20000000)
#define SYS_PLL_DISPA_SD4_psaud1a_div_mask                            (0x10000000)
#define SYS_PLL_DISPA_SD4_dummy1800047c_27_mask                       (0x08000000)
#define SYS_PLL_DISPA_SD4_psaud1a_tst_mask                            (0x04000000)
#define SYS_PLL_DISPA_SD4_psaud1a_psen_mask                           (0x02000000)
#define SYS_PLL_DISPA_SD4_dummy1800047c_24_mask                       (0x01000000)
#define SYS_PLL_DISPA_SD4_psaud2a_fupdn_mask                          (0x00800000)
#define SYS_PLL_DISPA_SD4_psaud2a_div_mask                            (0x00400000)
#define SYS_PLL_DISPA_SD4_psaud2a_tst_mask                            (0x00200000)
#define SYS_PLL_DISPA_SD4_psaud2a_psen_mask                           (0x00100000)
#define SYS_PLL_DISPA_SD4_psaud1a_oeb_mask                            (0x00000008)
#define SYS_PLL_DISPA_SD4_psaud1a_rstb_mask                           (0x00000004)
#define SYS_PLL_DISPA_SD4_psaud2a_oeb_mask                            (0x00000002)
#define SYS_PLL_DISPA_SD4_psaud2a_rstb_mask                           (0x00000001)
#define SYS_PLL_DISPA_SD4_dummy1800047c_30(data)                      (0x40000000&((data)<<30))
#define SYS_PLL_DISPA_SD4_psaud1a_fupdn(data)                         (0x20000000&((data)<<29))
#define SYS_PLL_DISPA_SD4_psaud1a_div(data)                           (0x10000000&((data)<<28))
#define SYS_PLL_DISPA_SD4_dummy1800047c_27(data)                      (0x08000000&((data)<<27))
#define SYS_PLL_DISPA_SD4_psaud1a_tst(data)                           (0x04000000&((data)<<26))
#define SYS_PLL_DISPA_SD4_psaud1a_psen(data)                          (0x02000000&((data)<<25))
#define SYS_PLL_DISPA_SD4_dummy1800047c_24(data)                      (0x01000000&((data)<<24))
#define SYS_PLL_DISPA_SD4_psaud2a_fupdn(data)                         (0x00800000&((data)<<23))
#define SYS_PLL_DISPA_SD4_psaud2a_div(data)                           (0x00400000&((data)<<22))
#define SYS_PLL_DISPA_SD4_psaud2a_tst(data)                           (0x00200000&((data)<<21))
#define SYS_PLL_DISPA_SD4_psaud2a_psen(data)                          (0x00100000&((data)<<20))
#define SYS_PLL_DISPA_SD4_psaud1a_oeb(data)                           (0x00000008&((data)<<3))
#define SYS_PLL_DISPA_SD4_psaud1a_rstb(data)                          (0x00000004&((data)<<2))
#define SYS_PLL_DISPA_SD4_psaud2a_oeb(data)                           (0x00000002&((data)<<1))
#define SYS_PLL_DISPA_SD4_psaud2a_rstb(data)                          (0x00000001&(data))
#define SYS_PLL_DISPA_SD4_get_dummy1800047c_30(data)                  ((0x40000000&(data))>>30)
#define SYS_PLL_DISPA_SD4_get_psaud1a_fupdn(data)                     ((0x20000000&(data))>>29)
#define SYS_PLL_DISPA_SD4_get_psaud1a_div(data)                       ((0x10000000&(data))>>28)
#define SYS_PLL_DISPA_SD4_get_dummy1800047c_27(data)                  ((0x08000000&(data))>>27)
#define SYS_PLL_DISPA_SD4_get_psaud1a_tst(data)                       ((0x04000000&(data))>>26)
#define SYS_PLL_DISPA_SD4_get_psaud1a_psen(data)                      ((0x02000000&(data))>>25)
#define SYS_PLL_DISPA_SD4_get_dummy1800047c_24(data)                  ((0x01000000&(data))>>24)
#define SYS_PLL_DISPA_SD4_get_psaud2a_fupdn(data)                     ((0x00800000&(data))>>23)
#define SYS_PLL_DISPA_SD4_get_psaud2a_div(data)                       ((0x00400000&(data))>>22)
#define SYS_PLL_DISPA_SD4_get_psaud2a_tst(data)                       ((0x00200000&(data))>>21)
#define SYS_PLL_DISPA_SD4_get_psaud2a_psen(data)                      ((0x00100000&(data))>>20)
#define SYS_PLL_DISPA_SD4_get_psaud1a_oeb(data)                       ((0x00000008&(data))>>3)
#define SYS_PLL_DISPA_SD4_get_psaud1a_rstb(data)                      ((0x00000004&(data))>>2)
#define SYS_PLL_DISPA_SD4_get_psaud2a_oeb(data)                       ((0x00000002&(data))>>1)
#define SYS_PLL_DISPA_SD4_get_psaud2a_rstb(data)                      (0x00000001&(data))


#define SYS_DVFS_DDSA                                                 0x18000480
#define SYS_DVFS_DDSA_reg_addr                                        "0xb8000480"
#define SYS_DVFS_DDSA_reg                                             0xb8000480
#define SYS_DVFS_DDSA_inst_addr                                       "0x0120"
#define SYS_DVFS_DDSA_inst                                            0x0120
#define set_SYS_DVFS_DDSA_reg(data)                                   (*((volatile unsigned int*)SYS_DVFS_DDSA_reg)=data)
#define get_SYS_DVFS_DDSA_reg                                         (*((volatile unsigned int*)SYS_DVFS_DDSA_reg))
#define SYS_DVFS_DDSA_pllddsa_bypass_pi_shift                         (31)
#define SYS_DVFS_DDSA_pllddsa_en_pi_debug_shift                       (30)
#define SYS_DVFS_DDSA_pllddsa_hs_oc_stop_shift                        (28)
#define SYS_DVFS_DDSA_pllddsa_pi_cur_sel_shift                        (26)
#define SYS_DVFS_DDSA_pllddsa_sel_oc_mode_shift                       (24)
#define SYS_DVFS_DDSA_pllddsa_oc_done_delay_shift                     (16)
#define SYS_DVFS_DDSA_pllddsa_oc_step_shift                           (4)
#define SYS_DVFS_DDSA_pllddsa_sdm_order_shift                         (2)
#define SYS_DVFS_DDSA_pllddsa_oc_done_shift                           (1)
#define SYS_DVFS_DDSA_pllddsa_oc_en_shift                             (0)
#define SYS_DVFS_DDSA_pllddsa_bypass_pi_mask                          (0x80000000)
#define SYS_DVFS_DDSA_pllddsa_en_pi_debug_mask                        (0x40000000)
#define SYS_DVFS_DDSA_pllddsa_hs_oc_stop_mask                         (0x30000000)
#define SYS_DVFS_DDSA_pllddsa_pi_cur_sel_mask                         (0x0C000000)
#define SYS_DVFS_DDSA_pllddsa_sel_oc_mode_mask                        (0x03000000)
#define SYS_DVFS_DDSA_pllddsa_oc_done_delay_mask                      (0x003F0000)
#define SYS_DVFS_DDSA_pllddsa_oc_step_mask                            (0x00003FF0)
#define SYS_DVFS_DDSA_pllddsa_sdm_order_mask                          (0x00000004)
#define SYS_DVFS_DDSA_pllddsa_oc_done_mask                            (0x00000002)
#define SYS_DVFS_DDSA_pllddsa_oc_en_mask                              (0x00000001)
#define SYS_DVFS_DDSA_pllddsa_bypass_pi(data)                         (0x80000000&((data)<<31))
#define SYS_DVFS_DDSA_pllddsa_en_pi_debug(data)                       (0x40000000&((data)<<30))
#define SYS_DVFS_DDSA_pllddsa_hs_oc_stop(data)                        (0x30000000&((data)<<28))
#define SYS_DVFS_DDSA_pllddsa_pi_cur_sel(data)                        (0x0C000000&((data)<<26))
#define SYS_DVFS_DDSA_pllddsa_sel_oc_mode(data)                       (0x03000000&((data)<<24))
#define SYS_DVFS_DDSA_pllddsa_oc_done_delay(data)                     (0x003F0000&((data)<<16))
#define SYS_DVFS_DDSA_pllddsa_oc_step(data)                           (0x00003FF0&((data)<<4))
#define SYS_DVFS_DDSA_pllddsa_sdm_order(data)                         (0x00000004&((data)<<2))
#define SYS_DVFS_DDSA_pllddsa_oc_done(data)                           (0x00000002&((data)<<1))
#define SYS_DVFS_DDSA_pllddsa_oc_en(data)                             (0x00000001&(data))
#define SYS_DVFS_DDSA_get_pllddsa_bypass_pi(data)                     ((0x80000000&(data))>>31)
#define SYS_DVFS_DDSA_get_pllddsa_en_pi_debug(data)                   ((0x40000000&(data))>>30)
#define SYS_DVFS_DDSA_get_pllddsa_hs_oc_stop(data)                    ((0x30000000&(data))>>28)
#define SYS_DVFS_DDSA_get_pllddsa_pi_cur_sel(data)                    ((0x0C000000&(data))>>26)
#define SYS_DVFS_DDSA_get_pllddsa_sel_oc_mode(data)                   ((0x03000000&(data))>>24)
#define SYS_DVFS_DDSA_get_pllddsa_oc_done_delay(data)                 ((0x003F0000&(data))>>16)
#define SYS_DVFS_DDSA_get_pllddsa_oc_step(data)                       ((0x00003FF0&(data))>>4)
#define SYS_DVFS_DDSA_get_pllddsa_sdm_order(data)                     ((0x00000004&(data))>>2)
#define SYS_DVFS_DDSA_get_pllddsa_oc_done(data)                       ((0x00000002&(data))>>1)
#define SYS_DVFS_DDSA_get_pllddsa_oc_en(data)                         (0x00000001&(data))


#define SYS_DVFS_DDSA2                                                0x18000484
#define SYS_DVFS_DDSA2_reg_addr                                       "0xb8000484"
#define SYS_DVFS_DDSA2_reg                                            0xb8000484
#define SYS_DVFS_DDSA2_inst_addr                                      "0x0121"
#define SYS_DVFS_DDSA2_inst                                           0x0121
#define set_SYS_DVFS_DDSA2_reg(data)                                  (*((volatile unsigned int*)SYS_DVFS_DDSA2_reg)=data)
#define get_SYS_DVFS_DDSA2_reg                                        (*((volatile unsigned int*)SYS_DVFS_DDSA2_reg))
#define SYS_DVFS_DDSA2_pllddsa_fcode_dbg_shift                        (16)
#define SYS_DVFS_DDSA2_pllddsa_ncode_dbg_shift                        (8)
#define SYS_DVFS_DDSA2_pllddsa_fcode_dbg_mask                         (0x07FF0000)
#define SYS_DVFS_DDSA2_pllddsa_ncode_dbg_mask                         (0x0000FF00)
#define SYS_DVFS_DDSA2_pllddsa_fcode_dbg(data)                        (0x07FF0000&((data)<<16))
#define SYS_DVFS_DDSA2_pllddsa_ncode_dbg(data)                        (0x0000FF00&((data)<<8))
#define SYS_DVFS_DDSA2_get_pllddsa_fcode_dbg(data)                    ((0x07FF0000&(data))>>16)
#define SYS_DVFS_DDSA2_get_pllddsa_ncode_dbg(data)                    ((0x0000FF00&(data))>>8)


#define AI_CLKCR                                                      0x18000490
#define AI_CLKCR_reg_addr                                             "0xb8000490"
#define AI_CLKCR_reg                                                  0xb8000490
#define AI_CLKCR_inst_addr                                            "0x0124"
#define AI_CLKCR_inst                                                 0x0124
#define set_AI_CLKCR_reg(data)                                        (*((volatile unsigned int*)AI_CLKCR_reg)=data)
#define get_AI_CLKCR_reg                                              (*((volatile unsigned int*)AI_CLKCR_reg))
#define AI_CLKCR_swsce_shift                                          (25)
#define AI_CLKCR_tme_shift                                            (23)
#define AI_CLKCR_tmps_shift                                           (20)
#define AI_CLKCR_psc_shift                                            (19)
#define AI_CLKCR_swcs_shift                                           (9)
#define AI_CLKCR_sd_shift                                             (1)
#define AI_CLKCR_su_shift                                             (0)
#define AI_CLKCR_swsce_mask                                           (0x02000000)
#define AI_CLKCR_tme_mask                                             (0x00800000)
#define AI_CLKCR_tmps_mask                                            (0x00100000)
#define AI_CLKCR_psc_mask                                             (0x00080000)
#define AI_CLKCR_swcs_mask                                            (0x0000FE00)
#define AI_CLKCR_sd_mask                                              (0x00000002)
#define AI_CLKCR_su_mask                                              (0x00000001)
#define AI_CLKCR_swsce(data)                                          (0x02000000&((data)<<25))
#define AI_CLKCR_tme(data)                                            (0x00800000&((data)<<23))
#define AI_CLKCR_tmps(data)                                           (0x00100000&((data)<<20))
#define AI_CLKCR_psc(data)                                            (0x00080000&((data)<<19))
#define AI_CLKCR_swcs(data)                                           (0x0000FE00&((data)<<9))
#define AI_CLKCR_sd(data)                                             (0x00000002&((data)<<1))
#define AI_CLKCR_su(data)                                             (0x00000001&(data))
#define AI_CLKCR_get_swsce(data)                                      ((0x02000000&(data))>>25)
#define AI_CLKCR_get_tme(data)                                        ((0x00800000&(data))>>23)
#define AI_CLKCR_get_tmps(data)                                       ((0x00100000&(data))>>20)
#define AI_CLKCR_get_psc(data)                                        ((0x00080000&(data))>>19)
#define AI_CLKCR_get_swcs(data)                                       ((0x0000FE00&(data))>>9)
#define AI_CLKCR_get_sd(data)                                         ((0x00000002&(data))>>1)
#define AI_CLKCR_get_su(data)                                         (0x00000001&(data))


#define AI2_CLKCR                                                     0x18000494
#define AI2_CLKCR_reg_addr                                            "0xb8000494"
#define AI2_CLKCR_reg                                                 0xb8000494
#define AI2_CLKCR_inst_addr                                           "0x0125"
#define AI2_CLKCR_inst                                                0x0125
#define set_AI2_CLKCR_reg(data)                                       (*((volatile unsigned int*)AI2_CLKCR_reg)=data)
#define get_AI2_CLKCR_reg                                             (*((volatile unsigned int*)AI2_CLKCR_reg))
#define AI2_CLKCR_swsce_2_shift                                       (25)
#define AI2_CLKCR_tme_2_shift                                         (23)
#define AI2_CLKCR_tmps_2_shift                                        (20)
#define AI2_CLKCR_psc_2_shift                                         (19)
#define AI2_CLKCR_swcs_2_shift                                        (9)
#define AI2_CLKCR_sd_2_shift                                          (1)
#define AI2_CLKCR_su_2_shift                                          (0)
#define AI2_CLKCR_swsce_2_mask                                        (0x02000000)
#define AI2_CLKCR_tme_2_mask                                          (0x00800000)
#define AI2_CLKCR_tmps_2_mask                                         (0x00100000)
#define AI2_CLKCR_psc_2_mask                                          (0x00080000)
#define AI2_CLKCR_swcs_2_mask                                         (0x0000FE00)
#define AI2_CLKCR_sd_2_mask                                           (0x00000002)
#define AI2_CLKCR_su_2_mask                                           (0x00000001)
#define AI2_CLKCR_swsce_2(data)                                       (0x02000000&((data)<<25))
#define AI2_CLKCR_tme_2(data)                                         (0x00800000&((data)<<23))
#define AI2_CLKCR_tmps_2(data)                                        (0x00100000&((data)<<20))
#define AI2_CLKCR_psc_2(data)                                         (0x00080000&((data)<<19))
#define AI2_CLKCR_swcs_2(data)                                        (0x0000FE00&((data)<<9))
#define AI2_CLKCR_sd_2(data)                                          (0x00000002&((data)<<1))
#define AI2_CLKCR_su_2(data)                                          (0x00000001&(data))
#define AI2_CLKCR_get_swsce_2(data)                                   ((0x02000000&(data))>>25)
#define AI2_CLKCR_get_tme_2(data)                                     ((0x00800000&(data))>>23)
#define AI2_CLKCR_get_tmps_2(data)                                    ((0x00100000&(data))>>20)
#define AI2_CLKCR_get_psc_2(data)                                     ((0x00080000&(data))>>19)
#define AI2_CLKCR_get_swcs_2(data)                                    ((0x0000FE00&(data))>>9)
#define AI2_CLKCR_get_sd_2(data)                                      ((0x00000002&(data))>>1)
#define AI2_CLKCR_get_su_2(data)                                      (0x00000001&(data))


#define SYS_PLL_WD_OUT                                                0x180004ac
#define SYS_PLL_WD_OUT_reg_addr                                       "0xb80004ac"
#define SYS_PLL_WD_OUT_reg                                            0xb80004ac
#define SYS_PLL_WD_OUT_inst_addr                                      "0x012B"
#define SYS_PLL_WD_OUT_inst                                           0x012B
#define set_SYS_PLL_WD_OUT_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_WD_OUT_reg)=data)
#define get_SYS_PLL_WD_OUT_reg                                        (*((volatile unsigned int*)SYS_PLL_WD_OUT_reg))
#define SYS_PLL_WD_OUT_pllifadc_wdout_shift                           (19)
#define SYS_PLL_WD_OUT_pll27x_wdout_shift                             (18)
#define SYS_PLL_WD_OUT_pllvodma_wdout_shift                           (17)
#define SYS_PLL_WD_OUT_pllkcpu_wdout_shift                            (16)
#define SYS_PLL_WD_OUT_pllaud_status_shift                            (14)
#define SYS_PLL_WD_OUT_pll512fs_wdout_shift                           (13)
#define SYS_PLL_WD_OUT_pllbush_wdout_shift                            (12)
#define SYS_PLL_WD_OUT_pllgpu_wdout_shift                             (11)
#define SYS_PLL_WD_OUT_plldif_wdout_shift                             (10)
#define SYS_PLL_WD_OUT_pllbus_wdout_shift                             (6)
#define SYS_PLL_WD_OUT_plldisp_wdout_shift                            (5)
#define SYS_PLL_WD_OUT_pllddsa_wdout_shift                            (3)
#define SYS_PLL_WD_OUT_pllvcpu_wdout_shift                            (2)
#define SYS_PLL_WD_OUT_pllacpu_wdout_shift                            (1)
#define SYS_PLL_WD_OUT_pllifadc_wdout_mask                            (0x00080000)
#define SYS_PLL_WD_OUT_pll27x_wdout_mask                              (0x00040000)
#define SYS_PLL_WD_OUT_pllvodma_wdout_mask                            (0x00020000)
#define SYS_PLL_WD_OUT_pllkcpu_wdout_mask                             (0x00010000)
#define SYS_PLL_WD_OUT_pllaud_status_mask                             (0x00004000)
#define SYS_PLL_WD_OUT_pll512fs_wdout_mask                            (0x00002000)
#define SYS_PLL_WD_OUT_pllbush_wdout_mask                             (0x00001000)
#define SYS_PLL_WD_OUT_pllgpu_wdout_mask                              (0x00000800)
#define SYS_PLL_WD_OUT_plldif_wdout_mask                              (0x00000400)
#define SYS_PLL_WD_OUT_pllbus_wdout_mask                              (0x00000040)
#define SYS_PLL_WD_OUT_plldisp_wdout_mask                             (0x00000020)
#define SYS_PLL_WD_OUT_pllddsa_wdout_mask                             (0x00000008)
#define SYS_PLL_WD_OUT_pllvcpu_wdout_mask                             (0x00000004)
#define SYS_PLL_WD_OUT_pllacpu_wdout_mask                             (0x00000002)
#define SYS_PLL_WD_OUT_pllifadc_wdout(data)                           (0x00080000&((data)<<19))
#define SYS_PLL_WD_OUT_pll27x_wdout(data)                             (0x00040000&((data)<<18))
#define SYS_PLL_WD_OUT_pllvodma_wdout(data)                           (0x00020000&((data)<<17))
#define SYS_PLL_WD_OUT_pllkcpu_wdout(data)                            (0x00010000&((data)<<16))
#define SYS_PLL_WD_OUT_pllaud_status(data)                            (0x00004000&((data)<<14))
#define SYS_PLL_WD_OUT_pll512fs_wdout(data)                           (0x00002000&((data)<<13))
#define SYS_PLL_WD_OUT_pllbush_wdout(data)                            (0x00001000&((data)<<12))
#define SYS_PLL_WD_OUT_pllgpu_wdout(data)                             (0x00000800&((data)<<11))
#define SYS_PLL_WD_OUT_plldif_wdout(data)                             (0x00000400&((data)<<10))
#define SYS_PLL_WD_OUT_pllbus_wdout(data)                             (0x00000040&((data)<<6))
#define SYS_PLL_WD_OUT_plldisp_wdout(data)                            (0x00000020&((data)<<5))
#define SYS_PLL_WD_OUT_pllddsa_wdout(data)                            (0x00000008&((data)<<3))
#define SYS_PLL_WD_OUT_pllvcpu_wdout(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_WD_OUT_pllacpu_wdout(data)                            (0x00000002&((data)<<1))
#define SYS_PLL_WD_OUT_get_pllifadc_wdout(data)                       ((0x00080000&(data))>>19)
#define SYS_PLL_WD_OUT_get_pll27x_wdout(data)                         ((0x00040000&(data))>>18)
#define SYS_PLL_WD_OUT_get_pllvodma_wdout(data)                       ((0x00020000&(data))>>17)
#define SYS_PLL_WD_OUT_get_pllkcpu_wdout(data)                        ((0x00010000&(data))>>16)
#define SYS_PLL_WD_OUT_get_pllaud_status(data)                        ((0x00004000&(data))>>14)
#define SYS_PLL_WD_OUT_get_pll512fs_wdout(data)                       ((0x00002000&(data))>>13)
#define SYS_PLL_WD_OUT_get_pllbush_wdout(data)                        ((0x00001000&(data))>>12)
#define SYS_PLL_WD_OUT_get_pllgpu_wdout(data)                         ((0x00000800&(data))>>11)
#define SYS_PLL_WD_OUT_get_plldif_wdout(data)                         ((0x00000400&(data))>>10)
#define SYS_PLL_WD_OUT_get_pllbus_wdout(data)                         ((0x00000040&(data))>>6)
#define SYS_PLL_WD_OUT_get_plldisp_wdout(data)                        ((0x00000020&(data))>>5)
#define SYS_PLL_WD_OUT_get_pllddsa_wdout(data)                        ((0x00000008&(data))>>3)
#define SYS_PLL_WD_OUT_get_pllvcpu_wdout(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_WD_OUT_get_pllacpu_wdout(data)                        ((0x00000002&(data))>>1)


#define SYS_PLL_512FS_1                                               0x180004b0
#define SYS_PLL_512FS_1_reg_addr                                      "0xb80004b0"
#define SYS_PLL_512FS_1_reg                                           0xb80004b0
#define SYS_PLL_512FS_1_inst_addr                                     "0x012C"
#define SYS_PLL_512FS_1_inst                                          0x012C
#define set_SYS_PLL_512FS_1_reg(data)                                 (*((volatile unsigned int*)SYS_PLL_512FS_1_reg)=data)
#define get_SYS_PLL_512FS_1_reg                                       (*((volatile unsigned int*)SYS_PLL_512FS_1_reg))
#define SYS_PLL_512FS_1_pll512fs_n_shift                              (28)
#define SYS_PLL_512FS_1_pll512fs_m_shift                              (20)
#define SYS_PLL_512FS_1_pll512fs_bpn_shift                            (19)
#define SYS_PLL_512FS_1_pll512fs_bps_shift                            (18)
#define SYS_PLL_512FS_1_pll512fs_cs_shift                             (16)
#define SYS_PLL_512FS_1_pll512fs_ip_shift                             (12)
#define SYS_PLL_512FS_1_pll512fs_s_shift                              (9)
#define SYS_PLL_512FS_1_pll512fs_q_shift                              (6)
#define SYS_PLL_512FS_1_pll512fs_rs_shift                             (3)
#define SYS_PLL_512FS_1_pll512fs_tst_shift                            (2)
#define SYS_PLL_512FS_1_pll512fs_wdrst_shift                          (1)
#define SYS_PLL_512FS_1_pll512fs_wdset_shift                          (0)
#define SYS_PLL_512FS_1_pll512fs_n_mask                               (0x70000000)
#define SYS_PLL_512FS_1_pll512fs_m_mask                               (0x07F00000)
#define SYS_PLL_512FS_1_pll512fs_bpn_mask                             (0x00080000)
#define SYS_PLL_512FS_1_pll512fs_bps_mask                             (0x00040000)
#define SYS_PLL_512FS_1_pll512fs_cs_mask                              (0x00030000)
#define SYS_PLL_512FS_1_pll512fs_ip_mask                              (0x00007000)
#define SYS_PLL_512FS_1_pll512fs_s_mask                               (0x00000E00)
#define SYS_PLL_512FS_1_pll512fs_q_mask                               (0x000001C0)
#define SYS_PLL_512FS_1_pll512fs_rs_mask                              (0x00000038)
#define SYS_PLL_512FS_1_pll512fs_tst_mask                             (0x00000004)
#define SYS_PLL_512FS_1_pll512fs_wdrst_mask                           (0x00000002)
#define SYS_PLL_512FS_1_pll512fs_wdset_mask                           (0x00000001)
#define SYS_PLL_512FS_1_pll512fs_n(data)                              (0x70000000&((data)<<28))
#define SYS_PLL_512FS_1_pll512fs_m(data)                              (0x07F00000&((data)<<20))
#define SYS_PLL_512FS_1_pll512fs_bpn(data)                            (0x00080000&((data)<<19))
#define SYS_PLL_512FS_1_pll512fs_bps(data)                            (0x00040000&((data)<<18))
#define SYS_PLL_512FS_1_pll512fs_cs(data)                             (0x00030000&((data)<<16))
#define SYS_PLL_512FS_1_pll512fs_ip(data)                             (0x00007000&((data)<<12))
#define SYS_PLL_512FS_1_pll512fs_s(data)                              (0x00000E00&((data)<<9))
#define SYS_PLL_512FS_1_pll512fs_q(data)                              (0x000001C0&((data)<<6))
#define SYS_PLL_512FS_1_pll512fs_rs(data)                             (0x00000038&((data)<<3))
#define SYS_PLL_512FS_1_pll512fs_tst(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_512FS_1_pll512fs_wdrst(data)                          (0x00000002&((data)<<1))
#define SYS_PLL_512FS_1_pll512fs_wdset(data)                          (0x00000001&(data))
#define SYS_PLL_512FS_1_get_pll512fs_n(data)                          ((0x70000000&(data))>>28)
#define SYS_PLL_512FS_1_get_pll512fs_m(data)                          ((0x07F00000&(data))>>20)
#define SYS_PLL_512FS_1_get_pll512fs_bpn(data)                        ((0x00080000&(data))>>19)
#define SYS_PLL_512FS_1_get_pll512fs_bps(data)                        ((0x00040000&(data))>>18)
#define SYS_PLL_512FS_1_get_pll512fs_cs(data)                         ((0x00030000&(data))>>16)
#define SYS_PLL_512FS_1_get_pll512fs_ip(data)                         ((0x00007000&(data))>>12)
#define SYS_PLL_512FS_1_get_pll512fs_s(data)                          ((0x00000E00&(data))>>9)
#define SYS_PLL_512FS_1_get_pll512fs_q(data)                          ((0x000001C0&(data))>>6)
#define SYS_PLL_512FS_1_get_pll512fs_rs(data)                         ((0x00000038&(data))>>3)
#define SYS_PLL_512FS_1_get_pll512fs_tst(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_512FS_1_get_pll512fs_wdrst(data)                      ((0x00000002&(data))>>1)
#define SYS_PLL_512FS_1_get_pll512fs_wdset(data)                      (0x00000001&(data))


#define SYS_PLL_512FS_2                                               0x180004b4
#define SYS_PLL_512FS_2_reg_addr                                      "0xb80004b4"
#define SYS_PLL_512FS_2_reg                                           0xb80004b4
#define SYS_PLL_512FS_2_inst_addr                                     "0x012D"
#define SYS_PLL_512FS_2_inst                                          0x012D
#define set_SYS_PLL_512FS_2_reg(data)                                 (*((volatile unsigned int*)SYS_PLL_512FS_2_reg)=data)
#define get_SYS_PLL_512FS_2_reg                                       (*((volatile unsigned int*)SYS_PLL_512FS_2_reg))
#define SYS_PLL_512FS_2_pll512fs_oeb_shift                            (2)
#define SYS_PLL_512FS_2_pll512fs_rstb_shift                           (1)
#define SYS_PLL_512FS_2_pll512fs_pow_shift                            (0)
#define SYS_PLL_512FS_2_pll512fs_oeb_mask                             (0x00000004)
#define SYS_PLL_512FS_2_pll512fs_rstb_mask                            (0x00000002)
#define SYS_PLL_512FS_2_pll512fs_pow_mask                             (0x00000001)
#define SYS_PLL_512FS_2_pll512fs_oeb(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_512FS_2_pll512fs_rstb(data)                           (0x00000002&((data)<<1))
#define SYS_PLL_512FS_2_pll512fs_pow(data)                            (0x00000001&(data))
#define SYS_PLL_512FS_2_get_pll512fs_oeb(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_512FS_2_get_pll512fs_rstb(data)                       ((0x00000002&(data))>>1)
#define SYS_PLL_512FS_2_get_pll512fs_pow(data)                        (0x00000001&(data))


#define SYS_PLL_512FS2_1                                              0x180004b8
#define SYS_PLL_512FS2_1_reg_addr                                     "0xb80004b8"
#define SYS_PLL_512FS2_1_reg                                          0xb80004b8
#define SYS_PLL_512FS2_1_inst_addr                                    "0x012E"
#define SYS_PLL_512FS2_1_inst                                         0x012E
#define set_SYS_PLL_512FS2_1_reg(data)                                (*((volatile unsigned int*)SYS_PLL_512FS2_1_reg)=data)
#define get_SYS_PLL_512FS2_1_reg                                      (*((volatile unsigned int*)SYS_PLL_512FS2_1_reg))


#define SYS_PLL_512FS2_2                                              0x180004bc
#define SYS_PLL_512FS2_2_reg_addr                                     "0xb80004bc"
#define SYS_PLL_512FS2_2_reg                                          0xb80004bc
#define SYS_PLL_512FS2_2_inst_addr                                    "0x012F"
#define SYS_PLL_512FS2_2_inst                                         0x012F
#define set_SYS_PLL_512FS2_2_reg(data)                                (*((volatile unsigned int*)SYS_PLL_512FS2_2_reg)=data)
#define get_SYS_PLL_512FS2_2_reg                                      (*((volatile unsigned int*)SYS_PLL_512FS2_2_reg))


#define SYS_PLL_DIF1                                                  0x180004c0
#define SYS_PLL_DIF1_reg_addr                                         "0xb80004c0"
#define SYS_PLL_DIF1_reg                                              0xb80004c0
#define SYS_PLL_DIF1_inst_addr                                        "0x0130"
#define SYS_PLL_DIF1_inst                                             0x0130
#define set_SYS_PLL_DIF1_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_DIF1_reg)=data)
#define get_SYS_PLL_DIF1_reg                                          (*((volatile unsigned int*)SYS_PLL_DIF1_reg))
#define SYS_PLL_DIF1_plldif_n_shift                                   (28)
#define SYS_PLL_DIF1_plldif_m_shift                                   (20)
#define SYS_PLL_DIF1_plldif_ip_shift                                  (16)
#define SYS_PLL_DIF1_plldif_lf_rs_shift                               (14)
#define SYS_PLL_DIF1_plldif_lf_cp_shift                               (12)
#define SYS_PLL_DIF1_plldif_n_mask                                    (0x30000000)
#define SYS_PLL_DIF1_plldif_m_mask                                    (0x07F00000)
#define SYS_PLL_DIF1_plldif_ip_mask                                   (0x00070000)
#define SYS_PLL_DIF1_plldif_lf_rs_mask                                (0x0000C000)
#define SYS_PLL_DIF1_plldif_lf_cp_mask                                (0x00003000)
#define SYS_PLL_DIF1_plldif_n(data)                                   (0x30000000&((data)<<28))
#define SYS_PLL_DIF1_plldif_m(data)                                   (0x07F00000&((data)<<20))
#define SYS_PLL_DIF1_plldif_ip(data)                                  (0x00070000&((data)<<16))
#define SYS_PLL_DIF1_plldif_lf_rs(data)                               (0x0000C000&((data)<<14))
#define SYS_PLL_DIF1_plldif_lf_cp(data)                               (0x00003000&((data)<<12))
#define SYS_PLL_DIF1_get_plldif_n(data)                               ((0x30000000&(data))>>28)
#define SYS_PLL_DIF1_get_plldif_m(data)                               ((0x07F00000&(data))>>20)
#define SYS_PLL_DIF1_get_plldif_ip(data)                              ((0x00070000&(data))>>16)
#define SYS_PLL_DIF1_get_plldif_lf_rs(data)                           ((0x0000C000&(data))>>14)
#define SYS_PLL_DIF1_get_plldif_lf_cp(data)                           ((0x00003000&(data))>>12)


#define SYS_PLL_DIF2                                                  0x180004c4
#define SYS_PLL_DIF2_reg_addr                                         "0xb80004c4"
#define SYS_PLL_DIF2_reg                                              0xb80004c4
#define SYS_PLL_DIF2_inst_addr                                        "0x0131"
#define SYS_PLL_DIF2_inst                                             0x0131
#define set_SYS_PLL_DIF2_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_DIF2_reg)=data)
#define get_SYS_PLL_DIF2_reg                                          (*((volatile unsigned int*)SYS_PLL_DIF2_reg))
#define SYS_PLL_DIF2_plldif_dvbs2_en_shift                            (12)
#define SYS_PLL_DIF2_plldif_wdmode_shift                              (8)
#define SYS_PLL_DIF2_plldif_divdig_sel_shift                          (4)
#define SYS_PLL_DIF2_plldif_divadc_sel_shift                          (0)
#define SYS_PLL_DIF2_plldif_dvbs2_en_mask                             (0x00001000)
#define SYS_PLL_DIF2_plldif_wdmode_mask                               (0x00000300)
#define SYS_PLL_DIF2_plldif_divdig_sel_mask                           (0x00000070)
#define SYS_PLL_DIF2_plldif_divadc_sel_mask                           (0x00000007)
#define SYS_PLL_DIF2_plldif_dvbs2_en(data)                            (0x00001000&((data)<<12))
#define SYS_PLL_DIF2_plldif_wdmode(data)                              (0x00000300&((data)<<8))
#define SYS_PLL_DIF2_plldif_divdig_sel(data)                          (0x00000070&((data)<<4))
#define SYS_PLL_DIF2_plldif_divadc_sel(data)                          (0x00000007&(data))
#define SYS_PLL_DIF2_get_plldif_dvbs2_en(data)                        ((0x00001000&(data))>>12)
#define SYS_PLL_DIF2_get_plldif_wdmode(data)                          ((0x00000300&(data))>>8)
#define SYS_PLL_DIF2_get_plldif_divdig_sel(data)                      ((0x00000070&(data))>>4)
#define SYS_PLL_DIF2_get_plldif_divadc_sel(data)                      (0x00000007&(data))


#define SYS_PLL_DIF3                                                  0x180004c8
#define SYS_PLL_DIF3_reg_addr                                         "0xb80004c8"
#define SYS_PLL_DIF3_reg                                              0xb80004c8
#define SYS_PLL_DIF3_inst_addr                                        "0x0132"
#define SYS_PLL_DIF3_inst                                             0x0132
#define set_SYS_PLL_DIF3_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_DIF3_reg)=data)
#define get_SYS_PLL_DIF3_reg                                          (*((volatile unsigned int*)SYS_PLL_DIF3_reg))
#define SYS_PLL_DIF3_dtvsysclk_sync_sel_shift                         (31)
#define SYS_PLL_DIF3_plldif_tst_shift                                 (30)
#define SYS_PLL_DIF3_plldif_vco_rstb_shift                            (2)
#define SYS_PLL_DIF3_plldif_rstb_shift                                (1)
#define SYS_PLL_DIF3_plldif_pow_shift                                 (0)
#define SYS_PLL_DIF3_dtvsysclk_sync_sel_mask                          (0x80000000)
#define SYS_PLL_DIF3_plldif_tst_mask                                  (0x40000000)
#define SYS_PLL_DIF3_plldif_vco_rstb_mask                             (0x00000004)
#define SYS_PLL_DIF3_plldif_rstb_mask                                 (0x00000002)
#define SYS_PLL_DIF3_plldif_pow_mask                                  (0x00000001)
#define SYS_PLL_DIF3_dtvsysclk_sync_sel(data)                         (0x80000000&((data)<<31))
#define SYS_PLL_DIF3_plldif_tst(data)                                 (0x40000000&((data)<<30))
#define SYS_PLL_DIF3_plldif_vco_rstb(data)                            (0x00000004&((data)<<2))
#define SYS_PLL_DIF3_plldif_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_DIF3_plldif_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_DIF3_get_dtvsysclk_sync_sel(data)                     ((0x80000000&(data))>>31)
#define SYS_PLL_DIF3_get_plldif_tst(data)                             ((0x40000000&(data))>>30)
#define SYS_PLL_DIF3_get_plldif_vco_rstb(data)                        ((0x00000004&(data))>>2)
#define SYS_PLL_DIF3_get_plldif_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_DIF3_get_plldif_pow(data)                             (0x00000001&(data))


#define SYS_PLL_27X1                                                  0x180004d0
#define SYS_PLL_27X1_reg_addr                                         "0xb80004d0"
#define SYS_PLL_27X1_reg                                              0xb80004d0
#define SYS_PLL_27X1_inst_addr                                        "0x0134"
#define SYS_PLL_27X1_inst                                             0x0134
#define set_SYS_PLL_27X1_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_27X1_reg)=data)
#define get_SYS_PLL_27X1_reg                                          (*((volatile unsigned int*)SYS_PLL_27X1_reg))
#define SYS_PLL_27X1_pll27x_wdmode_shift                              (28)
#define SYS_PLL_27X1_pll27x_lf_cp_shift                               (24)
#define SYS_PLL_27X1_pll27x_lf_rs_shift                               (20)
#define SYS_PLL_27X1_pll27x_ip_shift                                  (16)
#define SYS_PLL_27X1_pll27x_n_shift                                   (8)
#define SYS_PLL_27X1_pll27x_m_shift                                   (0)
#define SYS_PLL_27X1_pll27x_wdmode_mask                               (0x30000000)
#define SYS_PLL_27X1_pll27x_lf_cp_mask                                (0x03000000)
#define SYS_PLL_27X1_pll27x_lf_rs_mask                                (0x00300000)
#define SYS_PLL_27X1_pll27x_ip_mask                                   (0x00070000)
#define SYS_PLL_27X1_pll27x_n_mask                                    (0x00000300)
#define SYS_PLL_27X1_pll27x_m_mask                                    (0x0000007F)
#define SYS_PLL_27X1_pll27x_wdmode(data)                              (0x30000000&((data)<<28))
#define SYS_PLL_27X1_pll27x_lf_cp(data)                               (0x03000000&((data)<<24))
#define SYS_PLL_27X1_pll27x_lf_rs(data)                               (0x00300000&((data)<<20))
#define SYS_PLL_27X1_pll27x_ip(data)                                  (0x00070000&((data)<<16))
#define SYS_PLL_27X1_pll27x_n(data)                                   (0x00000300&((data)<<8))
#define SYS_PLL_27X1_pll27x_m(data)                                   (0x0000007F&(data))
#define SYS_PLL_27X1_get_pll27x_wdmode(data)                          ((0x30000000&(data))>>28)
#define SYS_PLL_27X1_get_pll27x_lf_cp(data)                           ((0x03000000&(data))>>24)
#define SYS_PLL_27X1_get_pll27x_lf_rs(data)                           ((0x00300000&(data))>>20)
#define SYS_PLL_27X1_get_pll27x_ip(data)                              ((0x00070000&(data))>>16)
#define SYS_PLL_27X1_get_pll27x_n(data)                               ((0x00000300&(data))>>8)
#define SYS_PLL_27X1_get_pll27x_m(data)                               (0x0000007F&(data))


#define SYS_PLL_27X2                                                  0x180004d4
#define SYS_PLL_27X2_reg_addr                                         "0xb80004d4"
#define SYS_PLL_27X2_reg                                              0xb80004d4
#define SYS_PLL_27X2_inst_addr                                        "0x0135"
#define SYS_PLL_27X2_inst                                             0x0135
#define set_SYS_PLL_27X2_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_27X2_reg)=data)
#define get_SYS_PLL_27X2_reg                                          (*((volatile unsigned int*)SYS_PLL_27X2_reg))
#define SYS_PLL_27X2_xi_cap_shift                                     (28)
#define SYS_PLL_27X2_xo_cap_shift                                     (24)
#define SYS_PLL_27X2_vdd11_pad_sel_shift                              (21)
#define SYS_PLL_27X2_pll_ldo_xtal_sel_shift                           (19)
#define SYS_PLL_27X2_pll_xixo_load_shift                              (18)
#define SYS_PLL_27X2_pll_xixo_drive_sel_shift                         (16)
#define SYS_PLL_27X2_pad_sel_en_shift                                 (15)
#define SYS_PLL_27X2_pll_pow_ldo11v_shift                             (14)
#define SYS_PLL_27X2_pll_ldo11v_sel_shift                             (12)
#define SYS_PLL_27X2_pll_pow_ldo_shift                                (10)
#define SYS_PLL_27X2_pll_ldo_sel_shift                                (8)
#define SYS_PLL_27X2_pll27x_ps_54m_delay_shift                        (4)
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w_shift                     (1)
#define SYS_PLL_27X2_pll27x_ps_duty_sel_shift                         (0)
#define SYS_PLL_27X2_xi_cap_mask                                      (0xF0000000)
#define SYS_PLL_27X2_xo_cap_mask                                      (0x0F000000)
#define SYS_PLL_27X2_vdd11_pad_sel_mask                               (0x00E00000)
#define SYS_PLL_27X2_pll_ldo_xtal_sel_mask                            (0x00180000)
#define SYS_PLL_27X2_pll_xixo_load_mask                               (0x00040000)
#define SYS_PLL_27X2_pll_xixo_drive_sel_mask                          (0x00030000)
#define SYS_PLL_27X2_pad_sel_en_mask                                  (0x00008000)
#define SYS_PLL_27X2_pll_pow_ldo11v_mask                              (0x00004000)
#define SYS_PLL_27X2_pll_ldo11v_sel_mask                              (0x00003000)
#define SYS_PLL_27X2_pll_pow_ldo_mask                                 (0x00000400)
#define SYS_PLL_27X2_pll_ldo_sel_mask                                 (0x00000300)
#define SYS_PLL_27X2_pll27x_ps_54m_delay_mask                         (0x00000030)
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w_mask                      (0x00000002)
#define SYS_PLL_27X2_pll27x_ps_duty_sel_mask                          (0x00000001)
#define SYS_PLL_27X2_xi_cap(data)                                     (0xF0000000&((data)<<28))
#define SYS_PLL_27X2_xo_cap(data)                                     (0x0F000000&((data)<<24))
#define SYS_PLL_27X2_vdd11_pad_sel(data)                              (0x00E00000&((data)<<21))
#define SYS_PLL_27X2_pll_ldo_xtal_sel(data)                           (0x00180000&((data)<<19))
#define SYS_PLL_27X2_pll_xixo_load(data)                              (0x00040000&((data)<<18))
#define SYS_PLL_27X2_pll_xixo_drive_sel(data)                         (0x00030000&((data)<<16))
#define SYS_PLL_27X2_pad_sel_en(data)                                 (0x00008000&((data)<<15))
#define SYS_PLL_27X2_pll_pow_ldo11v(data)                             (0x00004000&((data)<<14))
#define SYS_PLL_27X2_pll_ldo11v_sel(data)                             (0x00003000&((data)<<12))
#define SYS_PLL_27X2_pll_pow_ldo(data)                                (0x00000400&((data)<<10))
#define SYS_PLL_27X2_pll_ldo_sel(data)                                (0x00000300&((data)<<8))
#define SYS_PLL_27X2_pll27x_ps_54m_delay(data)                        (0x00000030&((data)<<4))
#define SYS_PLL_27X2_pll27x_ps_psel_pulse_w(data)                     (0x00000002&((data)<<1))
#define SYS_PLL_27X2_pll27x_ps_duty_sel(data)                         (0x00000001&(data))
#define SYS_PLL_27X2_get_xi_cap(data)                                 ((0xF0000000&(data))>>28)
#define SYS_PLL_27X2_get_xo_cap(data)                                 ((0x0F000000&(data))>>24)
#define SYS_PLL_27X2_get_vdd11_pad_sel(data)                          ((0x00E00000&(data))>>21)
#define SYS_PLL_27X2_get_pll_ldo_xtal_sel(data)                       ((0x00180000&(data))>>19)
#define SYS_PLL_27X2_get_pll_xixo_load(data)                          ((0x00040000&(data))>>18)
#define SYS_PLL_27X2_get_pll_xixo_drive_sel(data)                     ((0x00030000&(data))>>16)
#define SYS_PLL_27X2_get_pad_sel_en(data)                             ((0x00008000&(data))>>15)
#define SYS_PLL_27X2_get_pll_pow_ldo11v(data)                         ((0x00004000&(data))>>14)
#define SYS_PLL_27X2_get_pll_ldo11v_sel(data)                         ((0x00003000&(data))>>12)
#define SYS_PLL_27X2_get_pll_pow_ldo(data)                            ((0x00000400&(data))>>10)
#define SYS_PLL_27X2_get_pll_ldo_sel(data)                            ((0x00000300&(data))>>8)
#define SYS_PLL_27X2_get_pll27x_ps_54m_delay(data)                    ((0x00000030&(data))>>4)
#define SYS_PLL_27X2_get_pll27x_ps_psel_pulse_w(data)                 ((0x00000002&(data))>>1)
#define SYS_PLL_27X2_get_pll27x_ps_duty_sel(data)                     (0x00000001&(data))


#define SYS_PLL_27X3                                                  0x180004d8
#define SYS_PLL_27X3_reg_addr                                         "0xb80004d8"
#define SYS_PLL_27X3_reg                                              0xb80004d8
#define SYS_PLL_27X3_inst_addr                                        "0x0136"
#define SYS_PLL_27X3_inst                                             0x0136
#define set_SYS_PLL_27X3_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_27X3_reg)=data)
#define get_SYS_PLL_27X3_reg                                          (*((volatile unsigned int*)SYS_PLL_27X3_reg))
#define SYS_PLL_27X3_pll_reserve_shift                                (8)
#define SYS_PLL_27X3_pll27x_ps_en_shift                               (4)
#define SYS_PLL_27X3_pll27x_ps_div2_shift                             (3)
#define SYS_PLL_27X3_pll27x_vcorstb_shift                             (2)
#define SYS_PLL_27X3_pll27x_rstb_shift                                (1)
#define SYS_PLL_27X3_pll27x_pow_shift                                 (0)
#define SYS_PLL_27X3_pll_reserve_mask                                 (0x0000FF00)
#define SYS_PLL_27X3_pll27x_ps_en_mask                                (0x00000010)
#define SYS_PLL_27X3_pll27x_ps_div2_mask                              (0x00000008)
#define SYS_PLL_27X3_pll27x_vcorstb_mask                              (0x00000004)
#define SYS_PLL_27X3_pll27x_rstb_mask                                 (0x00000002)
#define SYS_PLL_27X3_pll27x_pow_mask                                  (0x00000001)
#define SYS_PLL_27X3_pll_reserve(data)                                (0x0000FF00&((data)<<8))
#define SYS_PLL_27X3_pll27x_ps_en(data)                               (0x00000010&((data)<<4))
#define SYS_PLL_27X3_pll27x_ps_div2(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_27X3_pll27x_vcorstb(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_27X3_pll27x_rstb(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_27X3_pll27x_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_27X3_get_pll_reserve(data)                            ((0x0000FF00&(data))>>8)
#define SYS_PLL_27X3_get_pll27x_ps_en(data)                           ((0x00000010&(data))>>4)
#define SYS_PLL_27X3_get_pll27x_ps_div2(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_27X3_get_pll27x_vcorstb(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_27X3_get_pll27x_rstb(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_27X3_get_pll27x_pow(data)                             (0x00000001&(data))


#define SYS_PLL_27X4                                                  0x180004dc
#define SYS_PLL_27X4_reg_addr                                         "0xb80004dc"
#define SYS_PLL_27X4_reg                                              0xb80004dc
#define SYS_PLL_27X4_inst_addr                                        "0x0137"
#define SYS_PLL_27X4_inst                                             0x0137
#define set_SYS_PLL_27X4_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_27X4_reg)=data)
#define get_SYS_PLL_27X4_reg                                          (*((volatile unsigned int*)SYS_PLL_27X4_reg))
#define SYS_PLL_27X4_dummy180004dc_31_shift                           (31)
#define SYS_PLL_27X4_pll27x_ifadc_duty_shift                          (29)
#define SYS_PLL_27X4_pll_yppadc_cko_polar_shift                       (27)
#define SYS_PLL_27X4_pll_ifadc_cko_polar_shift                        (26)
#define SYS_PLL_27X4_pll_l2h_cml_pow_shift                            (25)
#define SYS_PLL_27X4_pll27x_d16_en_shift                              (24)
#define SYS_PLL_27X4_pll27x_pll_tst_shift                             (21)
#define SYS_PLL_27X4_pll27x_en_tst_shift                              (20)
#define SYS_PLL_27X4_pll_rssi_cko_en_shift                            (19)
#define SYS_PLL_27X4_pll27x_ck108m_en_shift                           (18)
#define SYS_PLL_27X4_pll27x_ck108m_div_shift                          (16)
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel_shift                      (14)
#define SYS_PLL_27X4_pll27x_yppadc_cko_en_shift                       (13)
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en_shift                     (12)
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel_shift                       (10)
#define SYS_PLL_27X4_pll27x_ifadc_div_shift                           (9)
#define SYS_PLL_27X4_pll27x_ifadc_cko_en_shift                        (8)
#define SYS_PLL_27X4_xtal_tst_shift                                   (6)
#define SYS_PLL_27X4_ps27m_tst_shift                                  (5)
#define SYS_PLL_27X4_pllaud_ckin_mux_shift                            (4)
#define SYS_PLL_27X4_pll_xtalwd_rst_shift                             (3)
#define SYS_PLL_27X4_pll_xtalwd_set_shift                             (2)
#define SYS_PLL_27X4_pll_ck_ifadc_mux_shift                           (0)
#define SYS_PLL_27X4_dummy180004dc_31_mask                            (0x80000000)
#define SYS_PLL_27X4_pll27x_ifadc_duty_mask                           (0x60000000)
#define SYS_PLL_27X4_pll_yppadc_cko_polar_mask                        (0x08000000)
#define SYS_PLL_27X4_pll_ifadc_cko_polar_mask                         (0x04000000)
#define SYS_PLL_27X4_pll_l2h_cml_pow_mask                             (0x02000000)
#define SYS_PLL_27X4_pll27x_d16_en_mask                               (0x01000000)
#define SYS_PLL_27X4_pll27x_pll_tst_mask                              (0x00E00000)
#define SYS_PLL_27X4_pll27x_en_tst_mask                               (0x00100000)
#define SYS_PLL_27X4_pll_rssi_cko_en_mask                             (0x00080000)
#define SYS_PLL_27X4_pll27x_ck108m_en_mask                            (0x00040000)
#define SYS_PLL_27X4_pll27x_ck108m_div_mask                           (0x00030000)
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel_mask                       (0x0000C000)
#define SYS_PLL_27X4_pll27x_yppadc_cko_en_mask                        (0x00002000)
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en_mask                      (0x00001000)
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel_mask                        (0x00000C00)
#define SYS_PLL_27X4_pll27x_ifadc_div_mask                            (0x00000200)
#define SYS_PLL_27X4_pll27x_ifadc_cko_en_mask                         (0x00000100)
#define SYS_PLL_27X4_xtal_tst_mask                                    (0x00000040)
#define SYS_PLL_27X4_ps27m_tst_mask                                   (0x00000020)
#define SYS_PLL_27X4_pllaud_ckin_mux_mask                             (0x00000010)
#define SYS_PLL_27X4_pll_xtalwd_rst_mask                              (0x00000008)
#define SYS_PLL_27X4_pll_xtalwd_set_mask                              (0x00000004)
#define SYS_PLL_27X4_pll_ck_ifadc_mux_mask                            (0x00000001)
#define SYS_PLL_27X4_dummy180004dc_31(data)                           (0x80000000&((data)<<31))
#define SYS_PLL_27X4_pll27x_ifadc_duty(data)                          (0x60000000&((data)<<29))
#define SYS_PLL_27X4_pll_yppadc_cko_polar(data)                       (0x08000000&((data)<<27))
#define SYS_PLL_27X4_pll_ifadc_cko_polar(data)                        (0x04000000&((data)<<26))
#define SYS_PLL_27X4_pll_l2h_cml_pow(data)                            (0x02000000&((data)<<25))
#define SYS_PLL_27X4_pll27x_d16_en(data)                              (0x01000000&((data)<<24))
#define SYS_PLL_27X4_pll27x_pll_tst(data)                             (0x00E00000&((data)<<21))
#define SYS_PLL_27X4_pll27x_en_tst(data)                              (0x00100000&((data)<<20))
#define SYS_PLL_27X4_pll_rssi_cko_en(data)                            (0x00080000&((data)<<19))
#define SYS_PLL_27X4_pll27x_ck108m_en(data)                           (0x00040000&((data)<<18))
#define SYS_PLL_27X4_pll27x_ck108m_div(data)                          (0x00030000&((data)<<16))
#define SYS_PLL_27X4_pll27x_yppadc_cko_sel(data)                      (0x0000C000&((data)<<14))
#define SYS_PLL_27X4_pll27x_yppadc_cko_en(data)                       (0x00002000&((data)<<13))
#define SYS_PLL_27X4_pll27x_yppadc_ck54m_en(data)                     (0x00001000&((data)<<12))
#define SYS_PLL_27X4_pll27x_ifadc_cko_sel(data)                       (0x00000C00&((data)<<10))
#define SYS_PLL_27X4_pll27x_ifadc_div(data)                           (0x00000200&((data)<<9))
#define SYS_PLL_27X4_pll27x_ifadc_cko_en(data)                        (0x00000100&((data)<<8))
#define SYS_PLL_27X4_xtal_tst(data)                                   (0x00000040&((data)<<6))
#define SYS_PLL_27X4_ps27m_tst(data)                                  (0x00000020&((data)<<5))
#define SYS_PLL_27X4_pllaud_ckin_mux(data)                            (0x00000010&((data)<<4))
#define SYS_PLL_27X4_pll_xtalwd_rst(data)                             (0x00000008&((data)<<3))
#define SYS_PLL_27X4_pll_xtalwd_set(data)                             (0x00000004&((data)<<2))
#define SYS_PLL_27X4_pll_ck_ifadc_mux(data)                           (0x00000001&(data))
#define SYS_PLL_27X4_get_dummy180004dc_31(data)                       ((0x80000000&(data))>>31)
#define SYS_PLL_27X4_get_pll27x_ifadc_duty(data)                      ((0x60000000&(data))>>29)
#define SYS_PLL_27X4_get_pll_yppadc_cko_polar(data)                   ((0x08000000&(data))>>27)
#define SYS_PLL_27X4_get_pll_ifadc_cko_polar(data)                    ((0x04000000&(data))>>26)
#define SYS_PLL_27X4_get_pll_l2h_cml_pow(data)                        ((0x02000000&(data))>>25)
#define SYS_PLL_27X4_get_pll27x_d16_en(data)                          ((0x01000000&(data))>>24)
#define SYS_PLL_27X4_get_pll27x_pll_tst(data)                         ((0x00E00000&(data))>>21)
#define SYS_PLL_27X4_get_pll27x_en_tst(data)                          ((0x00100000&(data))>>20)
#define SYS_PLL_27X4_get_pll_rssi_cko_en(data)                        ((0x00080000&(data))>>19)
#define SYS_PLL_27X4_get_pll27x_ck108m_en(data)                       ((0x00040000&(data))>>18)
#define SYS_PLL_27X4_get_pll27x_ck108m_div(data)                      ((0x00030000&(data))>>16)
#define SYS_PLL_27X4_get_pll27x_yppadc_cko_sel(data)                  ((0x0000C000&(data))>>14)
#define SYS_PLL_27X4_get_pll27x_yppadc_cko_en(data)                   ((0x00002000&(data))>>13)
#define SYS_PLL_27X4_get_pll27x_yppadc_ck54m_en(data)                 ((0x00001000&(data))>>12)
#define SYS_PLL_27X4_get_pll27x_ifadc_cko_sel(data)                   ((0x00000C00&(data))>>10)
#define SYS_PLL_27X4_get_pll27x_ifadc_div(data)                       ((0x00000200&(data))>>9)
#define SYS_PLL_27X4_get_pll27x_ifadc_cko_en(data)                    ((0x00000100&(data))>>8)
#define SYS_PLL_27X4_get_xtal_tst(data)                               ((0x00000040&(data))>>6)
#define SYS_PLL_27X4_get_ps27m_tst(data)                              ((0x00000020&(data))>>5)
#define SYS_PLL_27X4_get_pllaud_ckin_mux(data)                        ((0x00000010&(data))>>4)
#define SYS_PLL_27X4_get_pll_xtalwd_rst(data)                         ((0x00000008&(data))>>3)
#define SYS_PLL_27X4_get_pll_xtalwd_set(data)                         ((0x00000004&(data))>>2)
#define SYS_PLL_27X4_get_pll_ck_ifadc_mux(data)                       (0x00000001&(data))


#define SYS_PLL_AUD1                                                  0x180004e0
#define SYS_PLL_AUD1_reg_addr                                         "0xb80004e0"
#define SYS_PLL_AUD1_reg                                              0xb80004e0
#define SYS_PLL_AUD1_inst_addr                                        "0x0138"
#define SYS_PLL_AUD1_inst                                             0x0138
#define set_SYS_PLL_AUD1_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_AUD1_reg)=data)
#define get_SYS_PLL_AUD1_reg                                          (*((volatile unsigned int*)SYS_PLL_AUD1_reg))
#define SYS_PLL_AUD1_pllaud_ip_shift                                  (15)
#define SYS_PLL_AUD1_pllaud_rs_shift                                  (11)
#define SYS_PLL_AUD1_pllaud_cp_shift                                  (8)
#define SYS_PLL_AUD1_pllaud_wdrst_shift                               (2)
#define SYS_PLL_AUD1_pllaud_wdset_shift                               (1)
#define SYS_PLL_AUD1_pllaud_tst_shift                                 (0)
#define SYS_PLL_AUD1_pllaud_ip_mask                                   (0x00038000)
#define SYS_PLL_AUD1_pllaud_rs_mask                                   (0x00001800)
#define SYS_PLL_AUD1_pllaud_cp_mask                                   (0x00000300)
#define SYS_PLL_AUD1_pllaud_wdrst_mask                                (0x00000004)
#define SYS_PLL_AUD1_pllaud_wdset_mask                                (0x00000002)
#define SYS_PLL_AUD1_pllaud_tst_mask                                  (0x00000001)
#define SYS_PLL_AUD1_pllaud_ip(data)                                  (0x00038000&((data)<<15))
#define SYS_PLL_AUD1_pllaud_rs(data)                                  (0x00001800&((data)<<11))
#define SYS_PLL_AUD1_pllaud_cp(data)                                  (0x00000300&((data)<<8))
#define SYS_PLL_AUD1_pllaud_wdrst(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_AUD1_pllaud_wdset(data)                               (0x00000002&((data)<<1))
#define SYS_PLL_AUD1_pllaud_tst(data)                                 (0x00000001&(data))
#define SYS_PLL_AUD1_get_pllaud_ip(data)                              ((0x00038000&(data))>>15)
#define SYS_PLL_AUD1_get_pllaud_rs(data)                              ((0x00001800&(data))>>11)
#define SYS_PLL_AUD1_get_pllaud_cp(data)                              ((0x00000300&(data))>>8)
#define SYS_PLL_AUD1_get_pllaud_wdrst(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_AUD1_get_pllaud_wdset(data)                           ((0x00000002&(data))>>1)
#define SYS_PLL_AUD1_get_pllaud_tst(data)                             (0x00000001&(data))


#define SYS_PLL_AUD3                                                  0x180004e4
#define SYS_PLL_AUD3_reg_addr                                         "0xb80004e4"
#define SYS_PLL_AUD3_reg                                              0xb80004e4
#define SYS_PLL_AUD3_inst_addr                                        "0x0139"
#define SYS_PLL_AUD3_inst                                             0x0139
#define set_SYS_PLL_AUD3_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_AUD3_reg)=data)
#define get_SYS_PLL_AUD3_reg                                          (*((volatile unsigned int*)SYS_PLL_AUD3_reg))
#define SYS_PLL_AUD3_pllaud_vcorstb_shift                             (4)
#define SYS_PLL_AUD3_pllaud_rstb_shift                                (3)
#define SYS_PLL_AUD3_pllaud_oeb1_shift                                (2)
#define SYS_PLL_AUD3_pllaud_oeb2_shift                                (1)
#define SYS_PLL_AUD3_pllaud_pow_shift                                 (0)
#define SYS_PLL_AUD3_pllaud_vcorstb_mask                              (0x00000010)
#define SYS_PLL_AUD3_pllaud_rstb_mask                                 (0x00000008)
#define SYS_PLL_AUD3_pllaud_oeb1_mask                                 (0x00000004)
#define SYS_PLL_AUD3_pllaud_oeb2_mask                                 (0x00000002)
#define SYS_PLL_AUD3_pllaud_pow_mask                                  (0x00000001)
#define SYS_PLL_AUD3_pllaud_vcorstb(data)                             (0x00000010&((data)<<4))
#define SYS_PLL_AUD3_pllaud_rstb(data)                                (0x00000008&((data)<<3))
#define SYS_PLL_AUD3_pllaud_oeb1(data)                                (0x00000004&((data)<<2))
#define SYS_PLL_AUD3_pllaud_oeb2(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_AUD3_pllaud_pow(data)                                 (0x00000001&(data))
#define SYS_PLL_AUD3_get_pllaud_vcorstb(data)                         ((0x00000010&(data))>>4)
#define SYS_PLL_AUD3_get_pllaud_rstb(data)                            ((0x00000008&(data))>>3)
#define SYS_PLL_AUD3_get_pllaud_oeb1(data)                            ((0x00000004&(data))>>2)
#define SYS_PLL_AUD3_get_pllaud_oeb2(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_AUD3_get_pllaud_pow(data)                             (0x00000001&(data))


#define SYS_PLL_AUD4                                                  0x180004e8
#define SYS_PLL_AUD4_reg_addr                                         "0xb80004e8"
#define SYS_PLL_AUD4_reg                                              0xb80004e8
#define SYS_PLL_AUD4_inst_addr                                        "0x013A"
#define SYS_PLL_AUD4_inst                                             0x013A
#define set_SYS_PLL_AUD4_reg(data)                                    (*((volatile unsigned int*)SYS_PLL_AUD4_reg)=data)
#define get_SYS_PLL_AUD4_reg                                          (*((volatile unsigned int*)SYS_PLL_AUD4_reg))


#define SYS_PLL_PSAUD1                                                0x180004ec
#define SYS_PLL_PSAUD1_reg_addr                                       "0xb80004ec"
#define SYS_PLL_PSAUD1_reg                                            0xb80004ec
#define SYS_PLL_PSAUD1_inst_addr                                      "0x013B"
#define SYS_PLL_PSAUD1_inst                                           0x013B
#define set_SYS_PLL_PSAUD1_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_PSAUD1_reg)=data)
#define get_SYS_PLL_PSAUD1_reg                                        (*((volatile unsigned int*)SYS_PLL_PSAUD1_reg))
#define SYS_PLL_PSAUD1_psaud_adder_mode_shift                         (4)
#define SYS_PLL_PSAUD1_psaud_psen_shift                               (3)
#define SYS_PLL_PSAUD1_psaud_en_shift                                 (2)
#define SYS_PLL_PSAUD1_psaud_tst_shift                                (1)
#define SYS_PLL_PSAUD1_psaud_ctrl_shift                               (0)
#define SYS_PLL_PSAUD1_psaud_adder_mode_mask                          (0x00000010)
#define SYS_PLL_PSAUD1_psaud_psen_mask                                (0x00000008)
#define SYS_PLL_PSAUD1_psaud_en_mask                                  (0x00000004)
#define SYS_PLL_PSAUD1_psaud_tst_mask                                 (0x00000002)
#define SYS_PLL_PSAUD1_psaud_ctrl_mask                                (0x00000001)
#define SYS_PLL_PSAUD1_psaud_adder_mode(data)                         (0x00000010&((data)<<4))
#define SYS_PLL_PSAUD1_psaud_psen(data)                               (0x00000008&((data)<<3))
#define SYS_PLL_PSAUD1_psaud_en(data)                                 (0x00000004&((data)<<2))
#define SYS_PLL_PSAUD1_psaud_tst(data)                                (0x00000002&((data)<<1))
#define SYS_PLL_PSAUD1_psaud_ctrl(data)                               (0x00000001&(data))
#define SYS_PLL_PSAUD1_get_psaud_adder_mode(data)                     ((0x00000010&(data))>>4)
#define SYS_PLL_PSAUD1_get_psaud_psen(data)                           ((0x00000008&(data))>>3)
#define SYS_PLL_PSAUD1_get_psaud_en(data)                             ((0x00000004&(data))>>2)
#define SYS_PLL_PSAUD1_get_psaud_tst(data)                            ((0x00000002&(data))>>1)
#define SYS_PLL_PSAUD1_get_psaud_ctrl(data)                           (0x00000001&(data))


#define SYS_PLL_PSAUD2                                                0x180004f0
#define SYS_PLL_PSAUD2_reg_addr                                       "0xb80004f0"
#define SYS_PLL_PSAUD2_reg                                            0xb80004f0
#define SYS_PLL_PSAUD2_inst_addr                                      "0x013C"
#define SYS_PLL_PSAUD2_inst                                           0x013C
#define set_SYS_PLL_PSAUD2_reg(data)                                  (*((volatile unsigned int*)SYS_PLL_PSAUD2_reg)=data)
#define get_SYS_PLL_PSAUD2_reg                                        (*((volatile unsigned int*)SYS_PLL_PSAUD2_reg))
#define SYS_PLL_PSAUD2_psaud_div_shift                                (0)
#define SYS_PLL_PSAUD2_psaud_div_mask                                 (0x0000000F)
#define SYS_PLL_PSAUD2_psaud_div(data)                                (0x0000000F&(data))
#define SYS_PLL_PSAUD2_get_psaud_div(data)                            (0x0000000F&(data))


#define SS_ADTV_0                                                     0x180004f4
#define SS_ADTV_0_reg_addr                                            "0xb80004f4"
#define SS_ADTV_0_reg                                                 0xb80004f4
#define SS_ADTV_0_inst_addr                                           "0x013D"
#define SS_ADTV_0_inst                                                0x013D
#define set_SS_ADTV_0_reg(data)                                       (*((volatile unsigned int*)SS_ADTV_0_reg)=data)
#define get_SS_ADTV_0_reg                                             (*((volatile unsigned int*)SS_ADTV_0_reg))
#define SS_ADTV_0_dss_adtv_dss_rst_n_shift                            (31)
#define SS_ADTV_0_dss_adtv_ro_sel_shift                               (25)
#define SS_ADTV_0_dss_adtv_wire_sel_shift                             (24)
#define SS_ADTV_0_dss_adtv_ready_shift                                (20)
#define SS_ADTV_0_dss_adtv_count_out_shift                            (0)
#define SS_ADTV_0_dss_adtv_dss_rst_n_mask                             (0x80000000)
#define SS_ADTV_0_dss_adtv_ro_sel_mask                                (0x0E000000)
#define SS_ADTV_0_dss_adtv_wire_sel_mask                              (0x01000000)
#define SS_ADTV_0_dss_adtv_ready_mask                                 (0x00100000)
#define SS_ADTV_0_dss_adtv_count_out_mask                             (0x000FFFFF)
#define SS_ADTV_0_dss_adtv_dss_rst_n(data)                            (0x80000000&((data)<<31))
#define SS_ADTV_0_dss_adtv_ro_sel(data)                               (0x0E000000&((data)<<25))
#define SS_ADTV_0_dss_adtv_wire_sel(data)                             (0x01000000&((data)<<24))
#define SS_ADTV_0_dss_adtv_ready(data)                                (0x00100000&((data)<<20))
#define SS_ADTV_0_dss_adtv_count_out(data)                            (0x000FFFFF&(data))
#define SS_ADTV_0_get_dss_adtv_dss_rst_n(data)                        ((0x80000000&(data))>>31)
#define SS_ADTV_0_get_dss_adtv_ro_sel(data)                           ((0x0E000000&(data))>>25)
#define SS_ADTV_0_get_dss_adtv_wire_sel(data)                         ((0x01000000&(data))>>24)
#define SS_ADTV_0_get_dss_adtv_ready(data)                            ((0x00100000&(data))>>20)
#define SS_ADTV_0_get_dss_adtv_count_out(data)                        (0x000FFFFF&(data))


#define SS_ADTV_1                                                     0x180004f8
#define SS_ADTV_1_reg_addr                                            "0xb80004f8"
#define SS_ADTV_1_reg                                                 0xb80004f8
#define SS_ADTV_1_inst_addr                                           "0x013E"
#define SS_ADTV_1_inst                                                0x013E
#define set_SS_ADTV_1_reg(data)                                       (*((volatile unsigned int*)SS_ADTV_1_reg)=data)
#define get_SS_ADTV_1_reg                                             (*((volatile unsigned int*)SS_ADTV_1_reg))
#define SS_ADTV_1_dss_adtv_speed_en_shift                             (21)
#define SS_ADTV_1_dss_adtv_wsort_go_shift                             (20)
#define SS_ADTV_1_dss_adtv_data_in_shift                              (0)
#define SS_ADTV_1_dss_adtv_speed_en_mask                              (0x00200000)
#define SS_ADTV_1_dss_adtv_wsort_go_mask                              (0x00100000)
#define SS_ADTV_1_dss_adtv_data_in_mask                               (0x000FFFFF)
#define SS_ADTV_1_dss_adtv_speed_en(data)                             (0x00200000&((data)<<21))
#define SS_ADTV_1_dss_adtv_wsort_go(data)                             (0x00100000&((data)<<20))
#define SS_ADTV_1_dss_adtv_data_in(data)                              (0x000FFFFF&(data))
#define SS_ADTV_1_get_dss_adtv_speed_en(data)                         ((0x00200000&(data))>>21)
#define SS_ADTV_1_get_dss_adtv_wsort_go(data)                         ((0x00100000&(data))>>20)
#define SS_ADTV_1_get_dss_adtv_data_in(data)                          (0x000FFFFF&(data))


#define SS_ADTV_2                                                     0x180004fc
#define SS_ADTV_2_reg_addr                                            "0xb80004fc"
#define SS_ADTV_2_reg                                                 0xb80004fc
#define SS_ADTV_2_inst_addr                                           "0x013F"
#define SS_ADTV_2_inst                                                0x013F
#define set_SS_ADTV_2_reg(data)                                       (*((volatile unsigned int*)SS_ADTV_2_reg)=data)
#define get_SS_ADTV_2_reg                                             (*((volatile unsigned int*)SS_ADTV_2_reg))
#define SS_ADTV_2_dss_adtv_dbgo_shift                                 (0)
#define SS_ADTV_2_dss_adtv_dbgo_mask                                  (0x0000FFFF)
#define SS_ADTV_2_dss_adtv_dbgo(data)                                 (0x0000FFFF&(data))
#define SS_ADTV_2_get_dss_adtv_dbgo(data)                             (0x0000FFFF&(data))


#define IFADC_1                                                       0x18000500
#define IFADC_1_reg_addr                                              "0xb8000500"
#define IFADC_1_reg                                                   0xb8000500
#define IFADC_1_inst_addr                                             "0x0140"
#define IFADC_1_inst                                                  0x0140
#define set_IFADC_1_reg(data)                                         (*((volatile unsigned int*)IFADC_1_reg)=data)
#define get_IFADC_1_reg                                               (*((volatile unsigned int*)IFADC_1_reg))
#define IFADC_1_ifadc_dtv_cko_tst_shift                               (13)
#define IFADC_1_ifadc_atv_cko_tst_shift                               (12)
#define IFADC_1_pll27x_ifadc_dtv_cko_sel_shift                        (5)
#define IFADC_1_pll27x_ifadc_dtv_cko_en_shift                         (4)
#define IFADC_1_pll27x_ifadc_atv_cko_sel_shift                        (2)
#define IFADC_1_pip_ifadc_atv_cko_sel_shift                           (0)
#define IFADC_1_ifadc_dtv_cko_tst_mask                                (0x00002000)
#define IFADC_1_ifadc_atv_cko_tst_mask                                (0x00001000)
#define IFADC_1_pll27x_ifadc_dtv_cko_sel_mask                         (0x000000E0)
#define IFADC_1_pll27x_ifadc_dtv_cko_en_mask                          (0x00000010)
#define IFADC_1_pll27x_ifadc_atv_cko_sel_mask                         (0x0000000C)
#define IFADC_1_pip_ifadc_atv_cko_sel_mask                            (0x00000001)
#define IFADC_1_ifadc_dtv_cko_tst(data)                               (0x00002000&((data)<<13))
#define IFADC_1_ifadc_atv_cko_tst(data)                               (0x00001000&((data)<<12))
#define IFADC_1_pll27x_ifadc_dtv_cko_sel(data)                        (0x000000E0&((data)<<5))
#define IFADC_1_pll27x_ifadc_dtv_cko_en(data)                         (0x00000010&((data)<<4))
#define IFADC_1_pll27x_ifadc_atv_cko_sel(data)                        (0x0000000C&((data)<<2))
#define IFADC_1_pip_ifadc_atv_cko_sel(data)                           (0x00000001&(data))
#define IFADC_1_get_ifadc_dtv_cko_tst(data)                           ((0x00002000&(data))>>13)
#define IFADC_1_get_ifadc_atv_cko_tst(data)                           ((0x00001000&(data))>>12)
#define IFADC_1_get_pll27x_ifadc_dtv_cko_sel(data)                    ((0x000000E0&(data))>>5)
#define IFADC_1_get_pll27x_ifadc_dtv_cko_en(data)                     ((0x00000010&(data))>>4)
#define IFADC_1_get_pll27x_ifadc_atv_cko_sel(data)                    ((0x0000000C&(data))>>2)
#define IFADC_1_get_pip_ifadc_atv_cko_sel(data)                       (0x00000001&(data))


#define IFADC_2                                                       0x18000504
#define IFADC_2_reg_addr                                              "0xb8000504"
#define IFADC_2_reg                                                   0xb8000504
#define IFADC_2_inst_addr                                             "0x0141"
#define IFADC_2_inst                                                  0x0141
#define set_IFADC_2_reg(data)                                         (*((volatile unsigned int*)IFADC_2_reg)=data)
#define get_IFADC_2_reg                                               (*((volatile unsigned int*)IFADC_2_reg))
#define IFADC_2_pll27x_ifadc_n_shift                                  (24)
#define IFADC_2_pll27x_ifadc_m_shift                                  (16)
#define IFADC_2_pll27x_ifadc_lf_rs_shift                              (8)
#define IFADC_2_pll27x_ifadc_lf_cp_shift                              (4)
#define IFADC_2_pll27x_ifadc_ip_shift                                 (0)
#define IFADC_2_pll27x_ifadc_n_mask                                   (0x03000000)
#define IFADC_2_pll27x_ifadc_m_mask                                   (0x007F0000)
#define IFADC_2_pll27x_ifadc_lf_rs_mask                               (0x00000300)
#define IFADC_2_pll27x_ifadc_lf_cp_mask                               (0x00000030)
#define IFADC_2_pll27x_ifadc_ip_mask                                  (0x00000007)
#define IFADC_2_pll27x_ifadc_n(data)                                  (0x03000000&((data)<<24))
#define IFADC_2_pll27x_ifadc_m(data)                                  (0x007F0000&((data)<<16))
#define IFADC_2_pll27x_ifadc_lf_rs(data)                              (0x00000300&((data)<<8))
#define IFADC_2_pll27x_ifadc_lf_cp(data)                              (0x00000030&((data)<<4))
#define IFADC_2_pll27x_ifadc_ip(data)                                 (0x00000007&(data))
#define IFADC_2_get_pll27x_ifadc_n(data)                              ((0x03000000&(data))>>24)
#define IFADC_2_get_pll27x_ifadc_m(data)                              ((0x007F0000&(data))>>16)
#define IFADC_2_get_pll27x_ifadc_lf_rs(data)                          ((0x00000300&(data))>>8)
#define IFADC_2_get_pll27x_ifadc_lf_cp(data)                          ((0x00000030&(data))>>4)
#define IFADC_2_get_pll27x_ifadc_ip(data)                             (0x00000007&(data))


#define IFADC_3                                                       0x18000508
#define IFADC_3_reg_addr                                              "0xb8000508"
#define IFADC_3_reg                                                   0xb8000508
#define IFADC_3_inst_addr                                             "0x0142"
#define IFADC_3_inst                                                  0x0142
#define set_IFADC_3_reg(data)                                         (*((volatile unsigned int*)IFADC_3_reg)=data)
#define get_IFADC_3_reg                                               (*((volatile unsigned int*)IFADC_3_reg))
#define IFADC_3_pll27x_ifadc_wdmode_shift                             (4)
#define IFADC_3_pll27x_ifadc_vcorstb_shift                            (2)
#define IFADC_3_pll27x_ifadc_rstb_shift                               (1)
#define IFADC_3_pll27x_ifadc_pow_shift                                (0)
#define IFADC_3_pll27x_ifadc_wdmode_mask                              (0x00000030)
#define IFADC_3_pll27x_ifadc_vcorstb_mask                             (0x00000004)
#define IFADC_3_pll27x_ifadc_rstb_mask                                (0x00000002)
#define IFADC_3_pll27x_ifadc_pow_mask                                 (0x00000001)
#define IFADC_3_pll27x_ifadc_wdmode(data)                             (0x00000030&((data)<<4))
#define IFADC_3_pll27x_ifadc_vcorstb(data)                            (0x00000004&((data)<<2))
#define IFADC_3_pll27x_ifadc_rstb(data)                               (0x00000002&((data)<<1))
#define IFADC_3_pll27x_ifadc_pow(data)                                (0x00000001&(data))
#define IFADC_3_get_pll27x_ifadc_wdmode(data)                         ((0x00000030&(data))>>4)
#define IFADC_3_get_pll27x_ifadc_vcorstb(data)                        ((0x00000004&(data))>>2)
#define IFADC_3_get_pll27x_ifadc_rstb(data)                           ((0x00000002&(data))>>1)
#define IFADC_3_get_pll27x_ifadc_pow(data)                            (0x00000001&(data))


#define SYS_DCLKSS                                                    0x18000640
#define SYS_DCLKSS_reg_addr                                           "0xb8000640"
#define SYS_DCLKSS_reg                                                0xb8000640
#define SYS_DCLKSS_inst_addr                                          "0x0190"
#define SYS_DCLKSS_inst                                               0x0190
#define set_SYS_DCLKSS_reg(data)                                      (*((volatile unsigned int*)SYS_DCLKSS_reg)=data)
#define get_SYS_DCLKSS_reg                                            (*((volatile unsigned int*)SYS_DCLKSS_reg))
#define SYS_DCLKSS_dclk_field_flag_mode_en_shift                      (31)
#define SYS_DCLKSS_dclk_filed_flag_slt_shift                          (28)
#define SYS_DCLKSS_dclk_new_en_shift                                  (15)
#define SYS_DCLKSS_dummy18000640_3_shift                              (3)
#define SYS_DCLKSS_dclk_ss_load_shift                                 (2)
#define SYS_DCLKSS_dummy18000640_1_shift                              (1)
#define SYS_DCLKSS_dclk_ss_en_shift                                   (0)
#define SYS_DCLKSS_dclk_field_flag_mode_en_mask                       (0x80000000)
#define SYS_DCLKSS_dclk_filed_flag_slt_mask                           (0x70000000)
#define SYS_DCLKSS_dclk_new_en_mask                                   (0x00008000)
#define SYS_DCLKSS_dummy18000640_3_mask                               (0x00000008)
#define SYS_DCLKSS_dclk_ss_load_mask                                  (0x00000004)
#define SYS_DCLKSS_dummy18000640_1_mask                               (0x00000002)
#define SYS_DCLKSS_dclk_ss_en_mask                                    (0x00000001)
#define SYS_DCLKSS_dclk_field_flag_mode_en(data)                      (0x80000000&((data)<<31))
#define SYS_DCLKSS_dclk_filed_flag_slt(data)                          (0x70000000&((data)<<28))
#define SYS_DCLKSS_dclk_new_en(data)                                  (0x00008000&((data)<<15))
#define SYS_DCLKSS_dummy18000640_3(data)                              (0x00000008&((data)<<3))
#define SYS_DCLKSS_dclk_ss_load(data)                                 (0x00000004&((data)<<2))
#define SYS_DCLKSS_dummy18000640_1(data)                              (0x00000002&((data)<<1))
#define SYS_DCLKSS_dclk_ss_en(data)                                   (0x00000001&(data))
#define SYS_DCLKSS_get_dclk_field_flag_mode_en(data)                  ((0x80000000&(data))>>31)
#define SYS_DCLKSS_get_dclk_filed_flag_slt(data)                      ((0x70000000&(data))>>28)
#define SYS_DCLKSS_get_dclk_new_en(data)                              ((0x00008000&(data))>>15)
#define SYS_DCLKSS_get_dummy18000640_3(data)                          ((0x00000008&(data))>>3)
#define SYS_DCLKSS_get_dclk_ss_load(data)                             ((0x00000004&(data))>>2)
#define SYS_DCLKSS_get_dummy18000640_1(data)                          ((0x00000002&(data))>>1)
#define SYS_DCLKSS_get_dclk_ss_en(data)                               (0x00000001&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL                                   0x18000644
#define DPLL_IN_FSYNC_TRACKING_CTRL_reg_addr                          "0xb8000644"
#define DPLL_IN_FSYNC_TRACKING_CTRL_reg                               0xb8000644
#define DPLL_IN_FSYNC_TRACKING_CTRL_inst_addr                         "0x0191"
#define DPLL_IN_FSYNC_TRACKING_CTRL_inst                              0x0191
#define set_DPLL_IN_FSYNC_TRACKING_CTRL_reg(data)                     (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_CTRL_reg                           (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL_reg))
#define DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_shift           (16)
#define DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_shift             (4)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_shift  (3)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_shift  (2)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_shift (1)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_shift  (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_mask            (0x3FFF0000)
#define DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_mask              (0x00000010)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_mask  (0x00000008)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_mask   (0x00000004)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_mask  (0x00000002)
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_mask (0x00000001)
#define DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt(data)           (0x3FFF0000&((data)<<16))
#define DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en(data)             (0x00000010&((data)<<4))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse(data)  (0x00000008&((data)<<3))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en(data)  (0x00000004&((data)<<2))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en(data) (0x00000002&((data)<<1))
#define DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en(data)  (0x00000001&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_dclk_freq_syn_slt(data)       ((0x3FFF0000&(data))>>16)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_fll_tracking_en(data)         ((0x00000010&(data))>>4)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_offset_inverse(data)  ((0x00000008&(data))>>3)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_ypbpr_en(data)  ((0x00000004&(data))>>2)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_vd_dec_en(data)  ((0x00000002&(data))>>1)
#define DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_general_en(data)  (0x00000001&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL2                                  0x18000648
#define DPLL_IN_FSYNC_TRACKING_CTRL2_reg_addr                         "0xb8000648"
#define DPLL_IN_FSYNC_TRACKING_CTRL2_reg                              0xb8000648
#define DPLL_IN_FSYNC_TRACKING_CTRL2_inst_addr                        "0x0192"
#define DPLL_IN_FSYNC_TRACKING_CTRL2_inst                             0x0192
#define set_DPLL_IN_FSYNC_TRACKING_CTRL2_reg(data)                    (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL2_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_CTRL2_reg                          (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL2_reg))
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_shift      (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_mask       (0x0007FFFF)
#define DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul(data)      (0x0007FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_mul(data)  (0x0007FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL3                                  0x1800064c
#define DPLL_IN_FSYNC_TRACKING_CTRL3_reg_addr                         "0xb800064c"
#define DPLL_IN_FSYNC_TRACKING_CTRL3_reg                              0xb800064c
#define DPLL_IN_FSYNC_TRACKING_CTRL3_inst_addr                        "0x0193"
#define DPLL_IN_FSYNC_TRACKING_CTRL3_inst                             0x0193
#define set_DPLL_IN_FSYNC_TRACKING_CTRL3_reg(data)                    (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL3_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_CTRL3_reg                          (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL3_reg))
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_shift   (16)
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_shift   (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_mask    (0xFFFF0000)
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_mask    (0x0000FFFF)
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th(data)   (0xFFFF0000&((data)<<16))
#define DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th(data)   (0x0000FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_neg_th(data)  ((0xFFFF0000&(data))>>16)
#define DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_pos_th(data)  (0x0000FFFF&(data))


#define DCLK_FRC2FSYNC_SPEEDUP                                        0x18000650
#define DCLK_FRC2FSYNC_SPEEDUP_reg_addr                               "0xb8000650"
#define DCLK_FRC2FSYNC_SPEEDUP_reg                                    0xb8000650
#define DCLK_FRC2FSYNC_SPEEDUP_inst_addr                              "0x0194"
#define DCLK_FRC2FSYNC_SPEEDUP_inst                                   0x0194
#define set_DCLK_FRC2FSYNC_SPEEDUP_reg(data)                          (*((volatile unsigned int*)DCLK_FRC2FSYNC_SPEEDUP_reg)=data)
#define get_DCLK_FRC2FSYNC_SPEEDUP_reg                                (*((volatile unsigned int*)DCLK_FRC2FSYNC_SPEEDUP_reg))
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_shift              (16)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_shift         (0)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_mask               (0x00010000)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_mask          (0x00001FFF)
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir(data)              (0x00010000&((data)<<16))
#define DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset(data)         (0x00001FFF&(data))
#define DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speed_dir(data)          ((0x00010000&(data))>>16)
#define DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speedup_offset(data)     (0x00001FFF&(data))


#define DPLL_STATUS_RO                                                0x18000654
#define DPLL_STATUS_RO_reg_addr                                       "0xb8000654"
#define DPLL_STATUS_RO_reg                                            0xb8000654
#define DPLL_STATUS_RO_inst_addr                                      "0x0195"
#define DPLL_STATUS_RO_inst                                           0x0195
#define set_DPLL_STATUS_RO_reg(data)                                  (*((volatile unsigned int*)DPLL_STATUS_RO_reg)=data)
#define get_DPLL_STATUS_RO_reg                                        (*((volatile unsigned int*)DPLL_STATUS_RO_reg))
#define DPLL_STATUS_RO_final_profile_shift                            (0)
#define DPLL_STATUS_RO_final_profile_mask                             (0x0003FFFF)
#define DPLL_STATUS_RO_final_profile(data)                            (0x0003FFFF&(data))
#define DPLL_STATUS_RO_get_final_profile(data)                        (0x0003FFFF&(data))


#define DCLKSS_PROFILE_CTL                                            0x18000658
#define DCLKSS_PROFILE_CTL_reg_addr                                   "0xb8000658"
#define DCLKSS_PROFILE_CTL_reg                                        0xb8000658
#define DCLKSS_PROFILE_CTL_inst_addr                                  "0x0196"
#define DCLKSS_PROFILE_CTL_inst                                       0x0196
#define set_DCLKSS_PROFILE_CTL_reg(data)                              (*((volatile unsigned int*)DCLKSS_PROFILE_CTL_reg)=data)
#define get_DCLKSS_PROFILE_CTL_reg                                    (*((volatile unsigned int*)DCLKSS_PROFILE_CTL_reg))
#define DCLKSS_PROFILE_CTL_dummy18000658_31_12_shift                  (12)
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_shift               (4)
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_en_shift                (0)
#define DCLKSS_PROFILE_CTL_dummy18000658_31_12_mask                   (0xFFFFF000)
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_mask                (0x00000FF0)
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_en_mask                 (0x00000001)
#define DCLKSS_PROFILE_CTL_dummy18000658_31_12(data)                  (0xFFFFF000&((data)<<12))
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt(data)               (0x00000FF0&((data)<<4))
#define DCLKSS_PROFILE_CTL_dclk_profile_remap_en(data)                (0x00000001&(data))
#define DCLKSS_PROFILE_CTL_get_dummy18000658_31_12(data)              ((0xFFFFF000&(data))>>12)
#define DCLKSS_PROFILE_CTL_get_dclk_profile_remap_cnt(data)           ((0x00000FF0&(data))>>4)
#define DCLKSS_PROFILE_CTL_get_dclk_profile_remap_en(data)            (0x00000001&(data))


#define DCLKSS_PROFILE0                                               0x1800065c
#define DCLKSS_PROFILE0_reg_addr                                      "0xb800065c"
#define DCLKSS_PROFILE0_reg                                           0xb800065c
#define DCLKSS_PROFILE0_inst_addr                                     "0x0197"
#define DCLKSS_PROFILE0_inst                                          0x0197
#define set_DCLKSS_PROFILE0_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE0_reg)=data)
#define get_DCLKSS_PROFILE0_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE0_reg))
#define DCLKSS_PROFILE0_dclk_profile_remap_1_shift                    (16)
#define DCLKSS_PROFILE0_dclk_profile_remap_0_shift                    (0)
#define DCLKSS_PROFILE0_dclk_profile_remap_1_mask                     (0xFFFF0000)
#define DCLKSS_PROFILE0_dclk_profile_remap_0_mask                     (0x0000FFFF)
#define DCLKSS_PROFILE0_dclk_profile_remap_1(data)                    (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE0_dclk_profile_remap_0(data)                    (0x0000FFFF&(data))
#define DCLKSS_PROFILE0_get_dclk_profile_remap_1(data)                ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE0_get_dclk_profile_remap_0(data)                (0x0000FFFF&(data))


#define DCLKSS_PROFILE1                                               0x18000660
#define DCLKSS_PROFILE1_reg_addr                                      "0xb8000660"
#define DCLKSS_PROFILE1_reg                                           0xb8000660
#define DCLKSS_PROFILE1_inst_addr                                     "0x0198"
#define DCLKSS_PROFILE1_inst                                          0x0198
#define set_DCLKSS_PROFILE1_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE1_reg)=data)
#define get_DCLKSS_PROFILE1_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE1_reg))
#define DCLKSS_PROFILE1_dclk_profile_remap_3_shift                    (16)
#define DCLKSS_PROFILE1_dclk_profile_remap_2_shift                    (0)
#define DCLKSS_PROFILE1_dclk_profile_remap_3_mask                     (0xFFFF0000)
#define DCLKSS_PROFILE1_dclk_profile_remap_2_mask                     (0x0000FFFF)
#define DCLKSS_PROFILE1_dclk_profile_remap_3(data)                    (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE1_dclk_profile_remap_2(data)                    (0x0000FFFF&(data))
#define DCLKSS_PROFILE1_get_dclk_profile_remap_3(data)                ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE1_get_dclk_profile_remap_2(data)                (0x0000FFFF&(data))


#define DCLKSS_PROFILE2                                               0x18000664
#define DCLKSS_PROFILE2_reg_addr                                      "0xb8000664"
#define DCLKSS_PROFILE2_reg                                           0xb8000664
#define DCLKSS_PROFILE2_inst_addr                                     "0x0199"
#define DCLKSS_PROFILE2_inst                                          0x0199
#define set_DCLKSS_PROFILE2_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE2_reg)=data)
#define get_DCLKSS_PROFILE2_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE2_reg))
#define DCLKSS_PROFILE2_dclk_profile_remap_5_shift                    (16)
#define DCLKSS_PROFILE2_dclk_profile_remap_4_shift                    (0)
#define DCLKSS_PROFILE2_dclk_profile_remap_5_mask                     (0xFFFF0000)
#define DCLKSS_PROFILE2_dclk_profile_remap_4_mask                     (0x0000FFFF)
#define DCLKSS_PROFILE2_dclk_profile_remap_5(data)                    (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE2_dclk_profile_remap_4(data)                    (0x0000FFFF&(data))
#define DCLKSS_PROFILE2_get_dclk_profile_remap_5(data)                ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE2_get_dclk_profile_remap_4(data)                (0x0000FFFF&(data))


#define DCLKSS_PROFILE3                                               0x18000668
#define DCLKSS_PROFILE3_reg_addr                                      "0xb8000668"
#define DCLKSS_PROFILE3_reg                                           0xb8000668
#define DCLKSS_PROFILE3_inst_addr                                     "0x019A"
#define DCLKSS_PROFILE3_inst                                          0x019A
#define set_DCLKSS_PROFILE3_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE3_reg)=data)
#define get_DCLKSS_PROFILE3_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE3_reg))
#define DCLKSS_PROFILE3_dclk_profile_remap_7_shift                    (16)
#define DCLKSS_PROFILE3_dclk_profile_remap_6_shift                    (0)
#define DCLKSS_PROFILE3_dclk_profile_remap_7_mask                     (0xFFFF0000)
#define DCLKSS_PROFILE3_dclk_profile_remap_6_mask                     (0x0000FFFF)
#define DCLKSS_PROFILE3_dclk_profile_remap_7(data)                    (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE3_dclk_profile_remap_6(data)                    (0x0000FFFF&(data))
#define DCLKSS_PROFILE3_get_dclk_profile_remap_7(data)                ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE3_get_dclk_profile_remap_6(data)                (0x0000FFFF&(data))


#define DCLKSS_PROFILE4                                               0x1800066c
#define DCLKSS_PROFILE4_reg_addr                                      "0xb800066c"
#define DCLKSS_PROFILE4_reg                                           0xb800066c
#define DCLKSS_PROFILE4_inst_addr                                     "0x019B"
#define DCLKSS_PROFILE4_inst                                          0x019B
#define set_DCLKSS_PROFILE4_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE4_reg)=data)
#define get_DCLKSS_PROFILE4_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE4_reg))
#define DCLKSS_PROFILE4_dclk_profile_remap_9_shift                    (16)
#define DCLKSS_PROFILE4_dclk_profile_remap_8_shift                    (0)
#define DCLKSS_PROFILE4_dclk_profile_remap_9_mask                     (0xFFFF0000)
#define DCLKSS_PROFILE4_dclk_profile_remap_8_mask                     (0x0000FFFF)
#define DCLKSS_PROFILE4_dclk_profile_remap_9(data)                    (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE4_dclk_profile_remap_8(data)                    (0x0000FFFF&(data))
#define DCLKSS_PROFILE4_get_dclk_profile_remap_9(data)                ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE4_get_dclk_profile_remap_8(data)                (0x0000FFFF&(data))


#define DCLKSS_PROFILE5                                               0x18000670
#define DCLKSS_PROFILE5_reg_addr                                      "0xb8000670"
#define DCLKSS_PROFILE5_reg                                           0xb8000670
#define DCLKSS_PROFILE5_inst_addr                                     "0x019C"
#define DCLKSS_PROFILE5_inst                                          0x019C
#define set_DCLKSS_PROFILE5_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE5_reg)=data)
#define get_DCLKSS_PROFILE5_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE5_reg))
#define DCLKSS_PROFILE5_dclk_profile_remap_11_shift                   (16)
#define DCLKSS_PROFILE5_dclk_profile_remap_10_shift                   (0)
#define DCLKSS_PROFILE5_dclk_profile_remap_11_mask                    (0xFFFF0000)
#define DCLKSS_PROFILE5_dclk_profile_remap_10_mask                    (0x0000FFFF)
#define DCLKSS_PROFILE5_dclk_profile_remap_11(data)                   (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE5_dclk_profile_remap_10(data)                   (0x0000FFFF&(data))
#define DCLKSS_PROFILE5_get_dclk_profile_remap_11(data)               ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE5_get_dclk_profile_remap_10(data)               (0x0000FFFF&(data))


#define DCLKSS_PROFILE6                                               0x18000674
#define DCLKSS_PROFILE6_reg_addr                                      "0xb8000674"
#define DCLKSS_PROFILE6_reg                                           0xb8000674
#define DCLKSS_PROFILE6_inst_addr                                     "0x019D"
#define DCLKSS_PROFILE6_inst                                          0x019D
#define set_DCLKSS_PROFILE6_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE6_reg)=data)
#define get_DCLKSS_PROFILE6_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE6_reg))
#define DCLKSS_PROFILE6_dclk_profile_remap_13_shift                   (16)
#define DCLKSS_PROFILE6_dclk_profile_remap_12_shift                   (0)
#define DCLKSS_PROFILE6_dclk_profile_remap_13_mask                    (0xFFFF0000)
#define DCLKSS_PROFILE6_dclk_profile_remap_12_mask                    (0x0000FFFF)
#define DCLKSS_PROFILE6_dclk_profile_remap_13(data)                   (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE6_dclk_profile_remap_12(data)                   (0x0000FFFF&(data))
#define DCLKSS_PROFILE6_get_dclk_profile_remap_13(data)               ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE6_get_dclk_profile_remap_12(data)               (0x0000FFFF&(data))


#define DCLKSS_PROFILE7                                               0x18000678
#define DCLKSS_PROFILE7_reg_addr                                      "0xb8000678"
#define DCLKSS_PROFILE7_reg                                           0xb8000678
#define DCLKSS_PROFILE7_inst_addr                                     "0x019E"
#define DCLKSS_PROFILE7_inst                                          0x019E
#define set_DCLKSS_PROFILE7_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE7_reg)=data)
#define get_DCLKSS_PROFILE7_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE7_reg))
#define DCLKSS_PROFILE7_dclk_profile_remap_15_shift                   (16)
#define DCLKSS_PROFILE7_dclk_profile_remap_14_shift                   (0)
#define DCLKSS_PROFILE7_dclk_profile_remap_15_mask                    (0xFFFF0000)
#define DCLKSS_PROFILE7_dclk_profile_remap_14_mask                    (0x0000FFFF)
#define DCLKSS_PROFILE7_dclk_profile_remap_15(data)                   (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE7_dclk_profile_remap_14(data)                   (0x0000FFFF&(data))
#define DCLKSS_PROFILE7_get_dclk_profile_remap_15(data)               ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE7_get_dclk_profile_remap_14(data)               (0x0000FFFF&(data))


#define DCLKSS_PROFILE8                                               0x1800067c
#define DCLKSS_PROFILE8_reg_addr                                      "0xb800067c"
#define DCLKSS_PROFILE8_reg                                           0xb800067c
#define DCLKSS_PROFILE8_inst_addr                                     "0x019F"
#define DCLKSS_PROFILE8_inst                                          0x019F
#define set_DCLKSS_PROFILE8_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE8_reg)=data)
#define get_DCLKSS_PROFILE8_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE8_reg))
#define DCLKSS_PROFILE8_dclk_profile_remap_17_shift                   (16)
#define DCLKSS_PROFILE8_dclk_profile_remap_16_shift                   (0)
#define DCLKSS_PROFILE8_dclk_profile_remap_17_mask                    (0xFFFF0000)
#define DCLKSS_PROFILE8_dclk_profile_remap_16_mask                    (0x0000FFFF)
#define DCLKSS_PROFILE8_dclk_profile_remap_17(data)                   (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE8_dclk_profile_remap_16(data)                   (0x0000FFFF&(data))
#define DCLKSS_PROFILE8_get_dclk_profile_remap_17(data)               ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE8_get_dclk_profile_remap_16(data)               (0x0000FFFF&(data))


#define DCLKSS_PROFILE9                                               0x18000680
#define DCLKSS_PROFILE9_reg_addr                                      "0xb8000680"
#define DCLKSS_PROFILE9_reg                                           0xb8000680
#define DCLKSS_PROFILE9_inst_addr                                     "0x01A0"
#define DCLKSS_PROFILE9_inst                                          0x01A0
#define set_DCLKSS_PROFILE9_reg(data)                                 (*((volatile unsigned int*)DCLKSS_PROFILE9_reg)=data)
#define get_DCLKSS_PROFILE9_reg                                       (*((volatile unsigned int*)DCLKSS_PROFILE9_reg))
#define DCLKSS_PROFILE9_dclk_profile_remap_19_shift                   (16)
#define DCLKSS_PROFILE9_dclk_profile_remap_18_shift                   (0)
#define DCLKSS_PROFILE9_dclk_profile_remap_19_mask                    (0xFFFF0000)
#define DCLKSS_PROFILE9_dclk_profile_remap_18_mask                    (0x0000FFFF)
#define DCLKSS_PROFILE9_dclk_profile_remap_19(data)                   (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE9_dclk_profile_remap_18(data)                   (0x0000FFFF&(data))
#define DCLKSS_PROFILE9_get_dclk_profile_remap_19(data)               ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE9_get_dclk_profile_remap_18(data)               (0x0000FFFF&(data))


#define DCLKSS_PROFILE10                                              0x18000684
#define DCLKSS_PROFILE10_reg_addr                                     "0xb8000684"
#define DCLKSS_PROFILE10_reg                                          0xb8000684
#define DCLKSS_PROFILE10_inst_addr                                    "0x01A1"
#define DCLKSS_PROFILE10_inst                                         0x01A1
#define set_DCLKSS_PROFILE10_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE10_reg)=data)
#define get_DCLKSS_PROFILE10_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE10_reg))
#define DCLKSS_PROFILE10_dclk_profile_remap_21_shift                  (16)
#define DCLKSS_PROFILE10_dclk_profile_remap_20_shift                  (0)
#define DCLKSS_PROFILE10_dclk_profile_remap_21_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE10_dclk_profile_remap_20_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE10_dclk_profile_remap_21(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE10_dclk_profile_remap_20(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE10_get_dclk_profile_remap_21(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE10_get_dclk_profile_remap_20(data)              (0x0000FFFF&(data))


#define DCLKSS_PROFILE11                                              0x18000688
#define DCLKSS_PROFILE11_reg_addr                                     "0xb8000688"
#define DCLKSS_PROFILE11_reg                                          0xb8000688
#define DCLKSS_PROFILE11_inst_addr                                    "0x01A2"
#define DCLKSS_PROFILE11_inst                                         0x01A2
#define set_DCLKSS_PROFILE11_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE11_reg)=data)
#define get_DCLKSS_PROFILE11_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE11_reg))
#define DCLKSS_PROFILE11_dclk_profile_remap_23_shift                  (16)
#define DCLKSS_PROFILE11_dclk_profile_remap_22_shift                  (0)
#define DCLKSS_PROFILE11_dclk_profile_remap_23_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE11_dclk_profile_remap_22_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE11_dclk_profile_remap_23(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE11_dclk_profile_remap_22(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE11_get_dclk_profile_remap_23(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE11_get_dclk_profile_remap_22(data)              (0x0000FFFF&(data))


#define DCLKSS_PROFILE12                                              0x1800068c
#define DCLKSS_PROFILE12_reg_addr                                     "0xb800068c"
#define DCLKSS_PROFILE12_reg                                          0xb800068c
#define DCLKSS_PROFILE12_inst_addr                                    "0x01A3"
#define DCLKSS_PROFILE12_inst                                         0x01A3
#define set_DCLKSS_PROFILE12_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE12_reg)=data)
#define get_DCLKSS_PROFILE12_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE12_reg))
#define DCLKSS_PROFILE12_dclk_profile_remap_25_shift                  (16)
#define DCLKSS_PROFILE12_dclk_profile_remap_24_shift                  (0)
#define DCLKSS_PROFILE12_dclk_profile_remap_25_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE12_dclk_profile_remap_24_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE12_dclk_profile_remap_25(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE12_dclk_profile_remap_24(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE12_get_dclk_profile_remap_25(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE12_get_dclk_profile_remap_24(data)              (0x0000FFFF&(data))


#define DCLKSS_PROFILE13                                              0x18000690
#define DCLKSS_PROFILE13_reg_addr                                     "0xb8000690"
#define DCLKSS_PROFILE13_reg                                          0xb8000690
#define DCLKSS_PROFILE13_inst_addr                                    "0x01A4"
#define DCLKSS_PROFILE13_inst                                         0x01A4
#define set_DCLKSS_PROFILE13_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE13_reg)=data)
#define get_DCLKSS_PROFILE13_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE13_reg))
#define DCLKSS_PROFILE13_dclk_profile_remap_27_shift                  (16)
#define DCLKSS_PROFILE13_dclk_profile_remap_26_shift                  (0)
#define DCLKSS_PROFILE13_dclk_profile_remap_27_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE13_dclk_profile_remap_26_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE13_dclk_profile_remap_27(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE13_dclk_profile_remap_26(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE13_get_dclk_profile_remap_27(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE13_get_dclk_profile_remap_26(data)              (0x0000FFFF&(data))


#define DCLKSS_PROFILE14                                              0x18000694
#define DCLKSS_PROFILE14_reg_addr                                     "0xb8000694"
#define DCLKSS_PROFILE14_reg                                          0xb8000694
#define DCLKSS_PROFILE14_inst_addr                                    "0x01A5"
#define DCLKSS_PROFILE14_inst                                         0x01A5
#define set_DCLKSS_PROFILE14_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE14_reg)=data)
#define get_DCLKSS_PROFILE14_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE14_reg))
#define DCLKSS_PROFILE14_dclk_profile_remap_29_shift                  (16)
#define DCLKSS_PROFILE14_dclk_profile_remap_28_shift                  (0)
#define DCLKSS_PROFILE14_dclk_profile_remap_29_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE14_dclk_profile_remap_28_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE14_dclk_profile_remap_29(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE14_dclk_profile_remap_28(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE14_get_dclk_profile_remap_29(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE14_get_dclk_profile_remap_28(data)              (0x0000FFFF&(data))


#define DCLKSS_PROFILE15                                              0x18000698
#define DCLKSS_PROFILE15_reg_addr                                     "0xb8000698"
#define DCLKSS_PROFILE15_reg                                          0xb8000698
#define DCLKSS_PROFILE15_inst_addr                                    "0x01A6"
#define DCLKSS_PROFILE15_inst                                         0x01A6
#define set_DCLKSS_PROFILE15_reg(data)                                (*((volatile unsigned int*)DCLKSS_PROFILE15_reg)=data)
#define get_DCLKSS_PROFILE15_reg                                      (*((volatile unsigned int*)DCLKSS_PROFILE15_reg))
#define DCLKSS_PROFILE15_dclk_profile_remap_31_shift                  (16)
#define DCLKSS_PROFILE15_dclk_profile_remap_30_shift                  (0)
#define DCLKSS_PROFILE15_dclk_profile_remap_31_mask                   (0xFFFF0000)
#define DCLKSS_PROFILE15_dclk_profile_remap_30_mask                   (0x0000FFFF)
#define DCLKSS_PROFILE15_dclk_profile_remap_31(data)                  (0xFFFF0000&((data)<<16))
#define DCLKSS_PROFILE15_dclk_profile_remap_30(data)                  (0x0000FFFF&(data))
#define DCLKSS_PROFILE15_get_dclk_profile_remap_31(data)              ((0xFFFF0000&(data))>>16)
#define DCLKSS_PROFILE15_get_dclk_profile_remap_30(data)              (0x0000FFFF&(data))


#define DPLL_DOUBLE_BUFFER_CTRL                                       0x1800069c
#define DPLL_DOUBLE_BUFFER_CTRL_reg_addr                              "0xb800069c"
#define DPLL_DOUBLE_BUFFER_CTRL_reg                                   0xb800069c
#define DPLL_DOUBLE_BUFFER_CTRL_inst_addr                             "0x01A7"
#define DPLL_DOUBLE_BUFFER_CTRL_inst                                  0x01A7
#define set_DPLL_DOUBLE_BUFFER_CTRL_reg(data)                         (*((volatile unsigned int*)DPLL_DOUBLE_BUFFER_CTRL_reg)=data)
#define get_DPLL_DOUBLE_BUFFER_CTRL_reg                               (*((volatile unsigned int*)DPLL_DOUBLE_BUFFER_CTRL_reg))
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_en_shift                   (2)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_read_sel_shift             (1)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_apply_shift                (0)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_en_mask                    (0x00000004)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_read_sel_mask              (0x00000002)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_apply_mask                 (0x00000001)
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_en(data)                   (0x00000004&((data)<<2))
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_read_sel(data)             (0x00000002&((data)<<1))
#define DPLL_DOUBLE_BUFFER_CTRL_double_buf_apply(data)                (0x00000001&(data))
#define DPLL_DOUBLE_BUFFER_CTRL_get_double_buf_en(data)               ((0x00000004&(data))>>2)
#define DPLL_DOUBLE_BUFFER_CTRL_get_double_buf_read_sel(data)         ((0x00000002&(data))>>1)
#define DPLL_DOUBLE_BUFFER_CTRL_get_double_buf_apply(data)            (0x00000001&(data))


#define PLL_SSC0                                                      0x180006a0
#define PLL_SSC0_reg_addr                                             "0xb80006a0"
#define PLL_SSC0_reg                                                  0xb80006a0
#define PLL_SSC0_inst_addr                                            "0x01A8"
#define PLL_SSC0_inst                                                 0x01A8
#define set_PLL_SSC0_reg(data)                                        (*((volatile unsigned int*)PLL_SSC0_reg)=data)
#define get_PLL_SSC0_reg                                              (*((volatile unsigned int*)PLL_SSC0_reg))
#define PLL_SSC0_fcode_t_ssc_shift                                    (16)
#define PLL_SSC0_oc_step_set_shift                                    (4)
#define PLL_SSC0_oc_en_shift                                          (0)
#define PLL_SSC0_fcode_t_ssc_mask                                     (0x07FF0000)
#define PLL_SSC0_oc_step_set_mask                                     (0x00003FF0)
#define PLL_SSC0_oc_en_mask                                           (0x00000001)
#define PLL_SSC0_fcode_t_ssc(data)                                    (0x07FF0000&((data)<<16))
#define PLL_SSC0_oc_step_set(data)                                    (0x00003FF0&((data)<<4))
#define PLL_SSC0_oc_en(data)                                          (0x00000001&(data))
#define PLL_SSC0_get_fcode_t_ssc(data)                                ((0x07FF0000&(data))>>16)
#define PLL_SSC0_get_oc_step_set(data)                                ((0x00003FF0&(data))>>4)
#define PLL_SSC0_get_oc_en(data)                                      (0x00000001&(data))


#define PLL_SSC1                                                      0x180006a4
#define PLL_SSC1_reg_addr                                             "0xb80006a4"
#define PLL_SSC1_reg                                                  0xb80006a4
#define PLL_SSC1_inst_addr                                            "0x01A9"
#define PLL_SSC1_inst                                                 0x01A9
#define set_PLL_SSC1_reg(data)                                        (*((volatile unsigned int*)PLL_SSC1_reg)=data)
#define get_PLL_SSC1_reg                                              (*((volatile unsigned int*)PLL_SSC1_reg))
#define PLL_SSC1_oc_done_delay_shift                                  (16)
#define PLL_SSC1_hs_oc_stop_diff_shift                                (12)
#define PLL_SSC1_sel_oc_mode_shift                                    (8)
#define PLL_SSC1_oc_done_delay_mask                                   (0x003F0000)
#define PLL_SSC1_hs_oc_stop_diff_mask                                 (0x00003000)
#define PLL_SSC1_sel_oc_mode_mask                                     (0x00000300)
#define PLL_SSC1_oc_done_delay(data)                                  (0x003F0000&((data)<<16))
#define PLL_SSC1_hs_oc_stop_diff(data)                                (0x00003000&((data)<<12))
#define PLL_SSC1_sel_oc_mode(data)                                    (0x00000300&((data)<<8))
#define PLL_SSC1_get_oc_done_delay(data)                              ((0x003F0000&(data))>>16)
#define PLL_SSC1_get_hs_oc_stop_diff(data)                            ((0x00003000&(data))>>12)
#define PLL_SSC1_get_sel_oc_mode(data)                                ((0x00000300&(data))>>8)


#define PLL_SSC2                                                      0x180006a8
#define PLL_SSC2_reg_addr                                             "0xb80006a8"
#define PLL_SSC2_reg                                                  0xb80006a8
#define PLL_SSC2_inst_addr                                            "0x01AA"
#define PLL_SSC2_inst                                                 0x01AA
#define set_PLL_SSC2_reg(data)                                        (*((volatile unsigned int*)PLL_SSC2_reg)=data)
#define get_PLL_SSC2_reg                                              (*((volatile unsigned int*)PLL_SSC2_reg))
#define PLL_SSC2_en_pi_debug_shift                                    (2)
#define PLL_SSC2_sdm_order_shift                                      (1)
#define PLL_SSC2_bypass_pi_shift                                      (0)
#define PLL_SSC2_en_pi_debug_mask                                     (0x00000004)
#define PLL_SSC2_sdm_order_mask                                       (0x00000002)
#define PLL_SSC2_bypass_pi_mask                                       (0x00000001)
#define PLL_SSC2_en_pi_debug(data)                                    (0x00000004&((data)<<2))
#define PLL_SSC2_sdm_order(data)                                      (0x00000002&((data)<<1))
#define PLL_SSC2_bypass_pi(data)                                      (0x00000001&(data))
#define PLL_SSC2_get_en_pi_debug(data)                                ((0x00000004&(data))>>2)
#define PLL_SSC2_get_sdm_order(data)                                  ((0x00000002&(data))>>1)
#define PLL_SSC2_get_bypass_pi(data)                                  (0x00000001&(data))


#define PLL_SSC3                                                      0x180006ac
#define PLL_SSC3_reg_addr                                             "0xb80006ac"
#define PLL_SSC3_reg                                                  0xb80006ac
#define PLL_SSC3_inst_addr                                            "0x01AB"
#define PLL_SSC3_inst                                                 0x01AB
#define set_PLL_SSC3_reg(data)                                        (*((volatile unsigned int*)PLL_SSC3_reg)=data)
#define get_PLL_SSC3_reg                                              (*((volatile unsigned int*)PLL_SSC3_reg))
#define PLL_SSC3_ncode_ssc_shift                                      (16)
#define PLL_SSC3_fcode_ssc_shift                                      (0)
#define PLL_SSC3_ncode_ssc_mask                                       (0x00FF0000)
#define PLL_SSC3_fcode_ssc_mask                                       (0x000007FF)
#define PLL_SSC3_ncode_ssc(data)                                      (0x00FF0000&((data)<<16))
#define PLL_SSC3_fcode_ssc(data)                                      (0x000007FF&(data))
#define PLL_SSC3_get_ncode_ssc(data)                                  ((0x00FF0000&(data))>>16)
#define PLL_SSC3_get_fcode_ssc(data)                                  (0x000007FF&(data))


#define PLL_SSC4                                                      0x180006b0
#define PLL_SSC4_reg_addr                                             "0xb80006b0"
#define PLL_SSC4_reg                                                  0xb80006b0
#define PLL_SSC4_inst_addr                                            "0x01AC"
#define PLL_SSC4_inst                                                 0x01AC
#define set_PLL_SSC4_reg(data)                                        (*((volatile unsigned int*)PLL_SSC4_reg)=data)
#define get_PLL_SSC4_reg                                              (*((volatile unsigned int*)PLL_SSC4_reg))
#define PLL_SSC4_gran_auto_rst_shift                                  (28)
#define PLL_SSC4_dot_gran_shift                                       (24)
#define PLL_SSC4_gran_est_shift                                       (4)
#define PLL_SSC4_en_ssc_shift                                         (0)
#define PLL_SSC4_gran_auto_rst_mask                                   (0x10000000)
#define PLL_SSC4_dot_gran_mask                                        (0x07000000)
#define PLL_SSC4_gran_est_mask                                        (0x007FFFF0)
#define PLL_SSC4_en_ssc_mask                                          (0x00000001)
#define PLL_SSC4_gran_auto_rst(data)                                  (0x10000000&((data)<<28))
#define PLL_SSC4_dot_gran(data)                                       (0x07000000&((data)<<24))
#define PLL_SSC4_gran_est(data)                                       (0x007FFFF0&((data)<<4))
#define PLL_SSC4_en_ssc(data)                                         (0x00000001&(data))
#define PLL_SSC4_get_gran_auto_rst(data)                              ((0x10000000&(data))>>28)
#define PLL_SSC4_get_dot_gran(data)                                   ((0x07000000&(data))>>24)
#define PLL_SSC4_get_gran_est(data)                                   ((0x007FFFF0&(data))>>4)
#define PLL_SSC4_get_en_ssc(data)                                     (0x00000001&(data))


#define PLL_SSC5                                                      0x180006b4
#define PLL_SSC5_reg_addr                                             "0xb80006b4"
#define PLL_SSC5_reg                                                  0xb80006b4
#define PLL_SSC5_inst_addr                                            "0x01AD"
#define PLL_SSC5_inst                                                 0x01AD
#define set_PLL_SSC5_reg(data)                                        (*((volatile unsigned int*)PLL_SSC5_reg)=data)
#define get_PLL_SSC5_reg                                              (*((volatile unsigned int*)PLL_SSC5_reg))
#define PLL_SSC5_fcode_debug_shift                                    (16)
#define PLL_SSC5_ncode_debug_shift                                    (8)
#define PLL_SSC5_oc_done_shift                                        (4)
#define PLL_SSC5_load_fcw_shift                                       (1)
#define PLL_SSC5_fmod_shift                                           (0)
#define PLL_SSC5_fcode_debug_mask                                     (0x07FF0000)
#define PLL_SSC5_ncode_debug_mask                                     (0x0000FF00)
#define PLL_SSC5_oc_done_mask                                         (0x00000010)
#define PLL_SSC5_load_fcw_mask                                        (0x00000002)
#define PLL_SSC5_fmod_mask                                            (0x00000001)
#define PLL_SSC5_fcode_debug(data)                                    (0x07FF0000&((data)<<16))
#define PLL_SSC5_ncode_debug(data)                                    (0x0000FF00&((data)<<8))
#define PLL_SSC5_oc_done(data)                                        (0x00000010&((data)<<4))
#define PLL_SSC5_load_fcw(data)                                       (0x00000002&((data)<<1))
#define PLL_SSC5_fmod(data)                                           (0x00000001&(data))
#define PLL_SSC5_get_fcode_debug(data)                                ((0x07FF0000&(data))>>16)
#define PLL_SSC5_get_ncode_debug(data)                                ((0x0000FF00&(data))>>8)
#define PLL_SSC5_get_oc_done(data)                                    ((0x00000010&(data))>>4)
#define PLL_SSC5_get_load_fcw(data)                                   ((0x00000002&(data))>>1)
#define PLL_SSC5_get_fmod(data)                                       (0x00000001&(data))


#define SYS_PLL_DISP1                                                 0x180006c0
#define SYS_PLL_DISP1_reg_addr                                        "0xb80006c0"
#define SYS_PLL_DISP1_reg                                             0xb80006c0
#define SYS_PLL_DISP1_inst_addr                                       "0x01B0"
#define SYS_PLL_DISP1_inst                                            0x01B0
#define set_SYS_PLL_DISP1_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_DISP1_reg)=data)
#define get_SYS_PLL_DISP1_reg                                         (*((volatile unsigned int*)SYS_PLL_DISP1_reg))
#define SYS_PLL_DISP1_dpll_m_shift                                    (20)
#define SYS_PLL_DISP1_dpll_n_shift                                    (12)
#define SYS_PLL_DISP1_dpll_ip_shift                                   (8)
#define SYS_PLL_DISP1_dpll_ssc_inv_shift                              (7)
#define SYS_PLL_DISP1_dpll_rs_shift                                   (4)
#define SYS_PLL_DISP1_dpll_cp_shift                                   (2)
#define SYS_PLL_DISP1_dpll_cs_shift                                   (0)
#define SYS_PLL_DISP1_dpll_m_mask                                     (0x0FF00000)
#define SYS_PLL_DISP1_dpll_n_mask                                     (0x00007000)
#define SYS_PLL_DISP1_dpll_ip_mask                                    (0x00000700)
#define SYS_PLL_DISP1_dpll_ssc_inv_mask                               (0x00000080)
#define SYS_PLL_DISP1_dpll_rs_mask                                    (0x00000070)
#define SYS_PLL_DISP1_dpll_cp_mask                                    (0x0000000C)
#define SYS_PLL_DISP1_dpll_cs_mask                                    (0x00000003)
#define SYS_PLL_DISP1_dpll_m(data)                                    (0x0FF00000&((data)<<20))
#define SYS_PLL_DISP1_dpll_n(data)                                    (0x00007000&((data)<<12))
#define SYS_PLL_DISP1_dpll_ip(data)                                   (0x00000700&((data)<<8))
#define SYS_PLL_DISP1_dpll_ssc_inv(data)                              (0x00000080&((data)<<7))
#define SYS_PLL_DISP1_dpll_rs(data)                                   (0x00000070&((data)<<4))
#define SYS_PLL_DISP1_dpll_cp(data)                                   (0x0000000C&((data)<<2))
#define SYS_PLL_DISP1_dpll_cs(data)                                   (0x00000003&(data))
#define SYS_PLL_DISP1_get_dpll_m(data)                                ((0x0FF00000&(data))>>20)
#define SYS_PLL_DISP1_get_dpll_n(data)                                ((0x00007000&(data))>>12)
#define SYS_PLL_DISP1_get_dpll_ip(data)                               ((0x00000700&(data))>>8)
#define SYS_PLL_DISP1_get_dpll_ssc_inv(data)                          ((0x00000080&(data))>>7)
#define SYS_PLL_DISP1_get_dpll_rs(data)                               ((0x00000070&(data))>>4)
#define SYS_PLL_DISP1_get_dpll_cp(data)                               ((0x0000000C&(data))>>2)
#define SYS_PLL_DISP1_get_dpll_cs(data)                               (0x00000003&(data))


#define SYS_PLL_DISP2                                                 0x180006c4
#define SYS_PLL_DISP2_reg_addr                                        "0xb80006c4"
#define SYS_PLL_DISP2_reg                                             0xb80006c4
#define SYS_PLL_DISP2_inst_addr                                       "0x01B1"
#define SYS_PLL_DISP2_inst                                            0x01B1
#define set_SYS_PLL_DISP2_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_DISP2_reg)=data)
#define get_SYS_PLL_DISP2_reg                                         (*((volatile unsigned int*)SYS_PLL_DISP2_reg))
#define SYS_PLL_DISP2_dpll_x_bpspi_shift                              (1)
#define SYS_PLL_DISP2_dpll_x_bpsin_shift                              (0)
#define SYS_PLL_DISP2_dpll_x_bpspi_mask                               (0x00000002)
#define SYS_PLL_DISP2_dpll_x_bpsin_mask                               (0x00000001)
#define SYS_PLL_DISP2_dpll_x_bpspi(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_DISP2_dpll_x_bpsin(data)                              (0x00000001&(data))
#define SYS_PLL_DISP2_get_dpll_x_bpspi(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_DISP2_get_dpll_x_bpsin(data)                          (0x00000001&(data))


#define SYS_PLL_DISP3                                                 0x180006c8
#define SYS_PLL_DISP3_reg_addr                                        "0xb80006c8"
#define SYS_PLL_DISP3_reg                                             0xb80006c8
#define SYS_PLL_DISP3_inst_addr                                       "0x01B2"
#define SYS_PLL_DISP3_inst                                            0x01B2
#define set_SYS_PLL_DISP3_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_DISP3_reg)=data)
#define get_SYS_PLL_DISP3_reg                                         (*((volatile unsigned int*)SYS_PLL_DISP3_reg))
#define SYS_PLL_DISP3_dpll_ldosel_shift                               (28)
#define SYS_PLL_DISP3_dpll_dummy_shift                                (20)
#define SYS_PLL_DISP3_dpll_picap_shift                                (18)
#define SYS_PLL_DISP3_dpll_prescaler_shift                            (17)
#define SYS_PLL_DISP3_dpll_test_en_shift                              (16)
#define SYS_PLL_DISP3_dpll_o_shift                                    (12)
#define SYS_PLL_DISP3_dpll_reser_shift                                (8)
#define SYS_PLL_DISP3_dpll_rstb_shift                                 (6)
#define SYS_PLL_DISP3_dpll_wdrst_shift                                (5)
#define SYS_PLL_DISP3_dpll_wdset_shift                                (4)
#define SYS_PLL_DISP3_dpll_freeze_shift                               (2)
#define SYS_PLL_DISP3_dpll_vcorstb_shift                              (1)
#define SYS_PLL_DISP3_dpll_pow_shift                                  (0)
#define SYS_PLL_DISP3_dpll_ldosel_mask                                (0x30000000)
#define SYS_PLL_DISP3_dpll_dummy_mask                                 (0x07F00000)
#define SYS_PLL_DISP3_dpll_picap_mask                                 (0x00040000)
#define SYS_PLL_DISP3_dpll_prescaler_mask                             (0x00020000)
#define SYS_PLL_DISP3_dpll_test_en_mask                               (0x00010000)
#define SYS_PLL_DISP3_dpll_o_mask                                     (0x00003000)
#define SYS_PLL_DISP3_dpll_reser_mask                                 (0x00000F00)
#define SYS_PLL_DISP3_dpll_rstb_mask                                  (0x00000040)
#define SYS_PLL_DISP3_dpll_wdrst_mask                                 (0x00000020)
#define SYS_PLL_DISP3_dpll_wdset_mask                                 (0x00000010)
#define SYS_PLL_DISP3_dpll_freeze_mask                                (0x00000004)
#define SYS_PLL_DISP3_dpll_vcorstb_mask                               (0x00000002)
#define SYS_PLL_DISP3_dpll_pow_mask                                   (0x00000001)
#define SYS_PLL_DISP3_dpll_ldosel(data)                               (0x30000000&((data)<<28))
#define SYS_PLL_DISP3_dpll_dummy(data)                                (0x07F00000&((data)<<20))
#define SYS_PLL_DISP3_dpll_picap(data)                                (0x00040000&((data)<<18))
#define SYS_PLL_DISP3_dpll_prescaler(data)                            (0x00020000&((data)<<17))
#define SYS_PLL_DISP3_dpll_test_en(data)                              (0x00010000&((data)<<16))
#define SYS_PLL_DISP3_dpll_o(data)                                    (0x00003000&((data)<<12))
#define SYS_PLL_DISP3_dpll_reser(data)                                (0x00000F00&((data)<<8))
#define SYS_PLL_DISP3_dpll_rstb(data)                                 (0x00000040&((data)<<6))
#define SYS_PLL_DISP3_dpll_wdrst(data)                                (0x00000020&((data)<<5))
#define SYS_PLL_DISP3_dpll_wdset(data)                                (0x00000010&((data)<<4))
#define SYS_PLL_DISP3_dpll_freeze(data)                               (0x00000004&((data)<<2))
#define SYS_PLL_DISP3_dpll_vcorstb(data)                              (0x00000002&((data)<<1))
#define SYS_PLL_DISP3_dpll_pow(data)                                  (0x00000001&(data))
#define SYS_PLL_DISP3_get_dpll_ldosel(data)                           ((0x30000000&(data))>>28)
#define SYS_PLL_DISP3_get_dpll_dummy(data)                            ((0x07F00000&(data))>>20)
#define SYS_PLL_DISP3_get_dpll_picap(data)                            ((0x00040000&(data))>>18)
#define SYS_PLL_DISP3_get_dpll_prescaler(data)                        ((0x00020000&(data))>>17)
#define SYS_PLL_DISP3_get_dpll_test_en(data)                          ((0x00010000&(data))>>16)
#define SYS_PLL_DISP3_get_dpll_o(data)                                ((0x00003000&(data))>>12)
#define SYS_PLL_DISP3_get_dpll_reser(data)                            ((0x00000F00&(data))>>8)
#define SYS_PLL_DISP3_get_dpll_rstb(data)                             ((0x00000040&(data))>>6)
#define SYS_PLL_DISP3_get_dpll_wdrst(data)                            ((0x00000020&(data))>>5)
#define SYS_PLL_DISP3_get_dpll_wdset(data)                            ((0x00000010&(data))>>4)
#define SYS_PLL_DISP3_get_dpll_freeze(data)                           ((0x00000004&(data))>>2)
#define SYS_PLL_DISP3_get_dpll_vcorstb(data)                          ((0x00000002&(data))>>1)
#define SYS_PLL_DISP3_get_dpll_pow(data)                              (0x00000001&(data))


#define SYS_PLL_DISP4                                                 0x180006cc
#define SYS_PLL_DISP4_reg_addr                                        "0xb80006cc"
#define SYS_PLL_DISP4_reg                                             0xb80006cc
#define SYS_PLL_DISP4_inst_addr                                       "0x01B3"
#define SYS_PLL_DISP4_inst                                            0x01B3
#define set_SYS_PLL_DISP4_reg(data)                                   (*((volatile unsigned int*)SYS_PLL_DISP4_reg)=data)
#define get_SYS_PLL_DISP4_reg                                         (*((volatile unsigned int*)SYS_PLL_DISP4_reg))
#define SYS_PLL_DISP4_dpll_ldodpll_pow_shift                          (2)
#define SYS_PLL_DISP4_dpll_pi_ibsel_shift                             (0)
#define SYS_PLL_DISP4_dpll_ldodpll_pow_mask                           (0x00000004)
#define SYS_PLL_DISP4_dpll_pi_ibsel_mask                              (0x00000003)
#define SYS_PLL_DISP4_dpll_ldodpll_pow(data)                          (0x00000004&((data)<<2))
#define SYS_PLL_DISP4_dpll_pi_ibsel(data)                             (0x00000003&(data))
#define SYS_PLL_DISP4_get_dpll_ldodpll_pow(data)                      ((0x00000004&(data))>>2)
#define SYS_PLL_DISP4_get_dpll_pi_ibsel(data)                         (0x00000003&(data))


#define DPLL_IN_FSYNC_TRACKING_DEBUG0                                 0x180006d0
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_reg_addr                        "0xb80006d0"
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_reg                             0xb80006d0
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_inst_addr                       "0x01B4"
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_inst                            0x01B4
#define set_DPLL_IN_FSYNC_TRACKING_DEBUG0_reg(data)                   (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG0_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_DEBUG0_reg                         (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG0_reg))
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_flag_shift     (31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_th_value_shift (0)
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_flag_mask      (0x80000000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_th_value_mask  (0x0001FFFF)
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_flag(data)     (0x80000000&((data)<<31))
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_sscg_offset_over_th_value(data) (0x0001FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_get_sscg_offset_over_flag(data) ((0x80000000&(data))>>31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG0_get_sscg_offset_over_th_value(data)  (0x0001FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_DEBUG1                                 0x180006d4
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_reg_addr                        "0xb80006d4"
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_reg                             0xb80006d4
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_inst_addr                       "0x01B5"
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_inst                            0x01B5
#define set_DPLL_IN_FSYNC_TRACKING_DEBUG1_reg(data)                   (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG1_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_DEBUG1_reg                         (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG1_reg))
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_sscg_offset_over_th_max_shift   (0)
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_sscg_offset_over_th_max_mask    (0x0001FFFF)
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_sscg_offset_over_th_max(data)   (0x0001FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_DEBUG1_get_sscg_offset_over_th_max(data)  (0x0001FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_DEBUG2                                 0x180006d8
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_reg_addr                        "0xb80006d8"
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_reg                             0xb80006d8
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_inst_addr                       "0x01B6"
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_inst                            0x01B6
#define set_DPLL_IN_FSYNC_TRACKING_DEBUG2_reg(data)                   (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG2_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_DEBUG2_reg                         (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG2_reg))
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_flag_shift  (31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_th_value_shift  (0)
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_flag_mask   (0x80000000)
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_th_value_mask  (0x0001FFFF)
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_flag(data)  (0x80000000&((data)<<31))
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_new_fll_offset_over_th_value(data)  (0x0001FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_get_new_fll_offset_over_flag(data)  ((0x80000000&(data))>>31)
#define DPLL_IN_FSYNC_TRACKING_DEBUG2_get_new_fll_offset_over_th_value(data)  (0x0001FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_DEBUG3                                 0x180006dc
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_reg_addr                        "0xb80006dc"
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_reg                             0xb80006dc
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_inst_addr                       "0x01B7"
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_inst                            0x01B7
#define set_DPLL_IN_FSYNC_TRACKING_DEBUG3_reg(data)                   (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG3_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_DEBUG3_reg                         (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_DEBUG3_reg))
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_new_fll_offset_over_th_max_shift  (0)
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_new_fll_offset_over_th_max_mask (0x0001FFFF)
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_new_fll_offset_over_th_max(data)  (0x0001FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_DEBUG3_get_new_fll_offset_over_th_max(data)  (0x0001FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL4                                  0x180006e0
#define DPLL_IN_FSYNC_TRACKING_CTRL4_reg_addr                         "0xb80006e0"
#define DPLL_IN_FSYNC_TRACKING_CTRL4_reg                              0xb80006e0
#define DPLL_IN_FSYNC_TRACKING_CTRL4_inst_addr                        "0x01B8"
#define DPLL_IN_FSYNC_TRACKING_CTRL4_inst                             0x01B8
#define set_DPLL_IN_FSYNC_TRACKING_CTRL4_reg(data)                    (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL4_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_CTRL4_reg                          (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL4_reg))
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_shift  (20)
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_shift       (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_mask  (0x00100000)
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_mask        (0x0007FFFF)
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse(data)  (0x00100000&((data)<<20))
#define DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul(data)       (0x0007FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_offset_inverse(data)  ((0x00100000&(data))>>20)
#define DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_mul(data)   (0x0007FFFF&(data))


#define DPLL_IN_FSYNC_TRACKING_CTRL5                                  0x180006e4
#define DPLL_IN_FSYNC_TRACKING_CTRL5_reg_addr                         "0xb80006e4"
#define DPLL_IN_FSYNC_TRACKING_CTRL5_reg                              0xb80006e4
#define DPLL_IN_FSYNC_TRACKING_CTRL5_inst_addr                        "0x01B9"
#define DPLL_IN_FSYNC_TRACKING_CTRL5_inst                             0x01B9
#define set_DPLL_IN_FSYNC_TRACKING_CTRL5_reg(data)                    (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL5_reg)=data)
#define get_DPLL_IN_FSYNC_TRACKING_CTRL5_reg                          (*((volatile unsigned int*)DPLL_IN_FSYNC_TRACKING_CTRL5_reg))
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_shift    (16)
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_shift    (0)
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_mask     (0xFFFF0000)
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_mask     (0x0000FFFF)
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th(data)    (0xFFFF0000&((data)<<16))
#define DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th(data)    (0x0000FFFF&(data))
#define DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_neg_th(data)  ((0xFFFF0000&(data))>>16)
#define DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_pos_th(data)  (0x0000FFFF&(data))


#define EMMC_PLL_SET                                                  0x18000700
#define EMMC_PLL_SET_reg_addr                                         "0xb8000700"
#define EMMC_PLL_SET_reg                                              0xb8000700
#define EMMC_PLL_SET_inst_addr                                        "0x01C0"
#define EMMC_PLL_SET_inst                                             0x01C0
#define set_EMMC_PLL_SET_reg(data)                                    (*((volatile unsigned int*)EMMC_PLL_SET_reg)=data)
#define get_EMMC_PLL_SET_reg                                          (*((volatile unsigned int*)EMMC_PLL_SET_reg))
#define EMMC_PLL_SET_pll_emmc_ckssc_inv_shift                         (30)
#define EMMC_PLL_SET_pllscp_shift                                     (29)
#define EMMC_PLL_SET_pllscs_shift                                     (27)
#define EMMC_PLL_SET_pllsrs_shift                                     (24)
#define EMMC_PLL_SET_pllsdiv2_shift                                   (17)
#define EMMC_PLL_SET_pllssi_shift                                     (12)
#define EMMC_PLL_SET_pllsnbp_shift                                    (11)
#define EMMC_PLL_SET_pllsn_shift                                      (8)
#define EMMC_PLL_SET_pllallrstb_shift                                 (0)
#define EMMC_PLL_SET_pll_emmc_ckssc_inv_mask                          (0x40000000)
#define EMMC_PLL_SET_pllscp_mask                                      (0x20000000)
#define EMMC_PLL_SET_pllscs_mask                                      (0x18000000)
#define EMMC_PLL_SET_pllsrs_mask                                      (0x07000000)
#define EMMC_PLL_SET_pllsdiv2_mask                                    (0x00020000)
#define EMMC_PLL_SET_pllssi_mask                                      (0x0001F000)
#define EMMC_PLL_SET_pllsnbp_mask                                     (0x00000800)
#define EMMC_PLL_SET_pllsn_mask                                       (0x00000700)
#define EMMC_PLL_SET_pllallrstb_mask                                  (0x00000001)
#define EMMC_PLL_SET_pll_emmc_ckssc_inv(data)                         (0x40000000&((data)<<30))
#define EMMC_PLL_SET_pllscp(data)                                     (0x20000000&((data)<<29))
#define EMMC_PLL_SET_pllscs(data)                                     (0x18000000&((data)<<27))
#define EMMC_PLL_SET_pllsrs(data)                                     (0x07000000&((data)<<24))
#define EMMC_PLL_SET_pllsdiv2(data)                                   (0x00020000&((data)<<17))
#define EMMC_PLL_SET_pllssi(data)                                     (0x0001F000&((data)<<12))
#define EMMC_PLL_SET_pllsnbp(data)                                    (0x00000800&((data)<<11))
#define EMMC_PLL_SET_pllsn(data)                                      (0x00000700&((data)<<8))
#define EMMC_PLL_SET_pllallrstb(data)                                 (0x00000001&(data))
#define EMMC_PLL_SET_get_pll_emmc_ckssc_inv(data)                     ((0x40000000&(data))>>30)
#define EMMC_PLL_SET_get_pllscp(data)                                 ((0x20000000&(data))>>29)
#define EMMC_PLL_SET_get_pllscs(data)                                 ((0x18000000&(data))>>27)
#define EMMC_PLL_SET_get_pllsrs(data)                                 ((0x07000000&(data))>>24)
#define EMMC_PLL_SET_get_pllsdiv2(data)                               ((0x00020000&(data))>>17)
#define EMMC_PLL_SET_get_pllssi(data)                                 ((0x0001F000&(data))>>12)
#define EMMC_PLL_SET_get_pllsnbp(data)                                ((0x00000800&(data))>>11)
#define EMMC_PLL_SET_get_pllsn(data)                                  ((0x00000700&(data))>>8)
#define EMMC_PLL_SET_get_pllallrstb(data)                             (0x00000001&(data))


#define EMMC_PLL_CTRL                                                 0x18000704
#define EMMC_PLL_CTRL_reg_addr                                        "0xb8000704"
#define EMMC_PLL_CTRL_reg                                             0xb8000704
#define EMMC_PLL_CTRL_inst_addr                                       "0x01C1"
#define EMMC_PLL_CTRL_inst                                            0x01C1
#define set_EMMC_PLL_CTRL_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_CTRL_reg)=data)
#define get_EMMC_PLL_CTRL_reg                                         (*((volatile unsigned int*)EMMC_PLL_CTRL_reg))
#define EMMC_PLL_CTRL_pllemmc_freeze_shift                            (24)
#define EMMC_PLL_CTRL_reg_pllemmc_bpspi_shift                         (23)
#define EMMC_PLL_CTRL_reg_pll_tp2_mux_shift                           (20)
#define EMMC_PLL_CTRL_reg_pll_tp1_mux_shift                           (17)
#define EMMC_PLL_CTRL_pllemmc_rsvd_shift                              (8)
#define EMMC_PLL_CTRL_pllsstatus_shift                                (6)
#define EMMC_PLL_CTRL_pllswdrst_shift                                 (5)
#define EMMC_PLL_CTRL_pllswdset_shift                                 (4)
#define EMMC_PLL_CTRL_pllemmc_reg_shift                               (2)
#define EMMC_PLL_CTRL_pllemmcldopow_shift                             (1)
#define EMMC_PLL_CTRL_pllemmcpwdn_shift                               (0)
#define EMMC_PLL_CTRL_pllemmc_freeze_mask                             (0x01000000)
#define EMMC_PLL_CTRL_reg_pllemmc_bpspi_mask                          (0x00800000)
#define EMMC_PLL_CTRL_reg_pll_tp2_mux_mask                            (0x00700000)
#define EMMC_PLL_CTRL_reg_pll_tp1_mux_mask                            (0x000E0000)
#define EMMC_PLL_CTRL_pllemmc_rsvd_mask                               (0x0000FF00)
#define EMMC_PLL_CTRL_pllsstatus_mask                                 (0x00000040)
#define EMMC_PLL_CTRL_pllswdrst_mask                                  (0x00000020)
#define EMMC_PLL_CTRL_pllswdset_mask                                  (0x00000010)
#define EMMC_PLL_CTRL_pllemmc_reg_mask                                (0x0000000C)
#define EMMC_PLL_CTRL_pllemmcldopow_mask                              (0x00000002)
#define EMMC_PLL_CTRL_pllemmcpwdn_mask                                (0x00000001)
#define EMMC_PLL_CTRL_pllemmc_freeze(data)                            (0x01000000&((data)<<24))
#define EMMC_PLL_CTRL_reg_pllemmc_bpspi(data)                         (0x00800000&((data)<<23))
#define EMMC_PLL_CTRL_reg_pll_tp2_mux(data)                           (0x00700000&((data)<<20))
#define EMMC_PLL_CTRL_reg_pll_tp1_mux(data)                           (0x000E0000&((data)<<17))
#define EMMC_PLL_CTRL_pllemmc_rsvd(data)                              (0x0000FF00&((data)<<8))
#define EMMC_PLL_CTRL_pllsstatus(data)                                (0x00000040&((data)<<6))
#define EMMC_PLL_CTRL_pllswdrst(data)                                 (0x00000020&((data)<<5))
#define EMMC_PLL_CTRL_pllswdset(data)                                 (0x00000010&((data)<<4))
#define EMMC_PLL_CTRL_pllemmc_reg(data)                               (0x0000000C&((data)<<2))
#define EMMC_PLL_CTRL_pllemmcldopow(data)                             (0x00000002&((data)<<1))
#define EMMC_PLL_CTRL_pllemmcpwdn(data)                               (0x00000001&(data))
#define EMMC_PLL_CTRL_get_pllemmc_freeze(data)                        ((0x01000000&(data))>>24)
#define EMMC_PLL_CTRL_get_reg_pllemmc_bpspi(data)                     ((0x00800000&(data))>>23)
#define EMMC_PLL_CTRL_get_reg_pll_tp2_mux(data)                       ((0x00700000&(data))>>20)
#define EMMC_PLL_CTRL_get_reg_pll_tp1_mux(data)                       ((0x000E0000&(data))>>17)
#define EMMC_PLL_CTRL_get_pllemmc_rsvd(data)                          ((0x0000FF00&(data))>>8)
#define EMMC_PLL_CTRL_get_pllsstatus(data)                            ((0x00000040&(data))>>6)
#define EMMC_PLL_CTRL_get_pllswdrst(data)                             ((0x00000020&(data))>>5)
#define EMMC_PLL_CTRL_get_pllswdset(data)                             ((0x00000010&(data))>>4)
#define EMMC_PLL_CTRL_get_pllemmc_reg(data)                           ((0x0000000C&(data))>>2)
#define EMMC_PLL_CTRL_get_pllemmcldopow(data)                         ((0x00000002&(data))>>1)
#define EMMC_PLL_CTRL_get_pllemmcpwdn(data)                           (0x00000001&(data))


#define EMMC_PLLPHASE_CTRL                                            0x18000708
#define EMMC_PLLPHASE_CTRL_reg_addr                                   "0xb8000708"
#define EMMC_PLLPHASE_CTRL_reg                                        0xb8000708
#define EMMC_PLLPHASE_CTRL_inst_addr                                  "0x01C2"
#define EMMC_PLLPHASE_CTRL_inst                                       0x01C2
#define set_EMMC_PLLPHASE_CTRL_reg(data)                              (*((volatile unsigned int*)EMMC_PLLPHASE_CTRL_reg)=data)
#define get_EMMC_PLLPHASE_CTRL_reg                                    (*((volatile unsigned int*)EMMC_PLLPHASE_CTRL_reg))
#define EMMC_PLLPHASE_CTRL_pll_pi_autoset_shift                       (30)
#define EMMC_PLLPHASE_CTRL_pllsd2x_3_shift                            (29)
#define EMMC_PLLPHASE_CTRL_pllsd2y_3_shift                            (28)
#define EMMC_PLLPHASE_CTRL_pllsx_3_shift                              (27)
#define EMMC_PLLPHASE_CTRL_pllsy_3_shift                              (26)
#define EMMC_PLLPHASE_CTRL_pllssck_3_shift                            (20)
#define EMMC_PLLPHASE_CTRL_pllsd2x_2_shift                            (19)
#define EMMC_PLLPHASE_CTRL_pllsd2y_2_shift                            (18)
#define EMMC_PLLPHASE_CTRL_pllsx_2_shift                              (17)
#define EMMC_PLLPHASE_CTRL_pllsy_2_shift                              (16)
#define EMMC_PLLPHASE_CTRL_pllssck_2_shift                            (10)
#define EMMC_PLLPHASE_CTRL_pllsd2x_shift                              (9)
#define EMMC_PLLPHASE_CTRL_pllsd2y_shift                              (8)
#define EMMC_PLLPHASE_CTRL_pllsx_shift                                (7)
#define EMMC_PLLPHASE_CTRL_pllsy_shift                                (6)
#define EMMC_PLLPHASE_CTRL_pllssck_shift                              (0)
#define EMMC_PLLPHASE_CTRL_pll_pi_autoset_mask                        (0x40000000)
#define EMMC_PLLPHASE_CTRL_pllsd2x_3_mask                             (0x20000000)
#define EMMC_PLLPHASE_CTRL_pllsd2y_3_mask                             (0x10000000)
#define EMMC_PLLPHASE_CTRL_pllsx_3_mask                               (0x08000000)
#define EMMC_PLLPHASE_CTRL_pllsy_3_mask                               (0x04000000)
#define EMMC_PLLPHASE_CTRL_pllssck_3_mask                             (0x03F00000)
#define EMMC_PLLPHASE_CTRL_pllsd2x_2_mask                             (0x00080000)
#define EMMC_PLLPHASE_CTRL_pllsd2y_2_mask                             (0x00040000)
#define EMMC_PLLPHASE_CTRL_pllsx_2_mask                               (0x00020000)
#define EMMC_PLLPHASE_CTRL_pllsy_2_mask                               (0x00010000)
#define EMMC_PLLPHASE_CTRL_pllssck_2_mask                             (0x0000FC00)
#define EMMC_PLLPHASE_CTRL_pllsd2x_mask                               (0x00000200)
#define EMMC_PLLPHASE_CTRL_pllsd2y_mask                               (0x00000100)
#define EMMC_PLLPHASE_CTRL_pllsx_mask                                 (0x00000080)
#define EMMC_PLLPHASE_CTRL_pllsy_mask                                 (0x00000040)
#define EMMC_PLLPHASE_CTRL_pllssck_mask                               (0x0000003F)
#define EMMC_PLLPHASE_CTRL_pll_pi_autoset(data)                       (0x40000000&((data)<<30))
#define EMMC_PLLPHASE_CTRL_pllsd2x_3(data)                            (0x20000000&((data)<<29))
#define EMMC_PLLPHASE_CTRL_pllsd2y_3(data)                            (0x10000000&((data)<<28))
#define EMMC_PLLPHASE_CTRL_pllsx_3(data)                              (0x08000000&((data)<<27))
#define EMMC_PLLPHASE_CTRL_pllsy_3(data)                              (0x04000000&((data)<<26))
#define EMMC_PLLPHASE_CTRL_pllssck_3(data)                            (0x03F00000&((data)<<20))
#define EMMC_PLLPHASE_CTRL_pllsd2x_2(data)                            (0x00080000&((data)<<19))
#define EMMC_PLLPHASE_CTRL_pllsd2y_2(data)                            (0x00040000&((data)<<18))
#define EMMC_PLLPHASE_CTRL_pllsx_2(data)                              (0x00020000&((data)<<17))
#define EMMC_PLLPHASE_CTRL_pllsy_2(data)                              (0x00010000&((data)<<16))
#define EMMC_PLLPHASE_CTRL_pllssck_2(data)                            (0x0000FC00&((data)<<10))
#define EMMC_PLLPHASE_CTRL_pllsd2x(data)                              (0x00000200&((data)<<9))
#define EMMC_PLLPHASE_CTRL_pllsd2y(data)                              (0x00000100&((data)<<8))
#define EMMC_PLLPHASE_CTRL_pllsx(data)                                (0x00000080&((data)<<7))
#define EMMC_PLLPHASE_CTRL_pllsy(data)                                (0x00000040&((data)<<6))
#define EMMC_PLLPHASE_CTRL_pllssck(data)                              (0x0000003F&(data))
#define EMMC_PLLPHASE_CTRL_get_pll_pi_autoset(data)                   ((0x40000000&(data))>>30)
#define EMMC_PLLPHASE_CTRL_get_pllsd2x_3(data)                        ((0x20000000&(data))>>29)
#define EMMC_PLLPHASE_CTRL_get_pllsd2y_3(data)                        ((0x10000000&(data))>>28)
#define EMMC_PLLPHASE_CTRL_get_pllsx_3(data)                          ((0x08000000&(data))>>27)
#define EMMC_PLLPHASE_CTRL_get_pllsy_3(data)                          ((0x04000000&(data))>>26)
#define EMMC_PLLPHASE_CTRL_get_pllssck_3(data)                        ((0x03F00000&(data))>>20)
#define EMMC_PLLPHASE_CTRL_get_pllsd2x_2(data)                        ((0x00080000&(data))>>19)
#define EMMC_PLLPHASE_CTRL_get_pllsd2y_2(data)                        ((0x00040000&(data))>>18)
#define EMMC_PLLPHASE_CTRL_get_pllsx_2(data)                          ((0x00020000&(data))>>17)
#define EMMC_PLLPHASE_CTRL_get_pllsy_2(data)                          ((0x00010000&(data))>>16)
#define EMMC_PLLPHASE_CTRL_get_pllssck_2(data)                        ((0x0000FC00&(data))>>10)
#define EMMC_PLLPHASE_CTRL_get_pllsd2x(data)                          ((0x00000200&(data))>>9)
#define EMMC_PLLPHASE_CTRL_get_pllsd2y(data)                          ((0x00000100&(data))>>8)
#define EMMC_PLLPHASE_CTRL_get_pllsx(data)                            ((0x00000080&(data))>>7)
#define EMMC_PLLPHASE_CTRL_get_pllsy(data)                            ((0x00000040&(data))>>6)
#define EMMC_PLLPHASE_CTRL_get_pllssck(data)                          (0x0000003F&(data))


#define EMMC_PLL_PHASE_INTERPOLATION                                  0x1800070c
#define EMMC_PLL_PHASE_INTERPOLATION_reg_addr                         "0xb800070c"
#define EMMC_PLL_PHASE_INTERPOLATION_reg                              0xb800070c
#define EMMC_PLL_PHASE_INTERPOLATION_inst_addr                        "0x01C3"
#define EMMC_PLL_PHASE_INTERPOLATION_inst                             0x01C3
#define set_EMMC_PLL_PHASE_INTERPOLATION_reg(data)                    (*((volatile unsigned int*)EMMC_PLL_PHASE_INTERPOLATION_reg)=data)
#define get_EMMC_PLL_PHASE_INTERPOLATION_reg                          (*((volatile unsigned int*)EMMC_PLL_PHASE_INTERPOLATION_reg))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4_shift                  (19)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4_shift                  (18)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsx_4_shift                    (17)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsy_4_shift                    (16)
#define EMMC_PLL_PHASE_INTERPOLATION_pllssck_4_shift                  (10)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_shift                   (4)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_shift                   (0)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4_mask                   (0x00080000)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4_mask                   (0x00040000)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsx_4_mask                     (0x00020000)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsy_4_mask                     (0x00010000)
#define EMMC_PLL_PHASE_INTERPOLATION_pllssck_4_mask                   (0x0000FC00)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_mask                    (0x00000030)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_mask                    (0x00000007)
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2x_4(data)                  (0x00080000&((data)<<19))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsd2y_4(data)                  (0x00040000&((data)<<18))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsx_4(data)                    (0x00020000&((data)<<17))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsy_4(data)                    (0x00010000&((data)<<16))
#define EMMC_PLL_PHASE_INTERPOLATION_pllssck_4(data)                  (0x0000FC00&((data)<<10))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrl(data)                   (0x00000030&((data)<<4))
#define EMMC_PLL_PHASE_INTERPOLATION_pllsphrs(data)                   (0x00000007&(data))
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsd2x_4(data)              ((0x00080000&(data))>>19)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsd2y_4(data)              ((0x00040000&(data))>>18)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsx_4(data)                ((0x00020000&(data))>>17)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsy_4(data)                ((0x00010000&(data))>>16)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllssck_4(data)              ((0x0000FC00&(data))>>10)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrl(data)               ((0x00000030&(data))>>4)
#define EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrs(data)               (0x00000007&(data))


#define EMMC_PLL_SSC0                                                 0x18000710
#define EMMC_PLL_SSC0_reg_addr                                        "0xb8000710"
#define EMMC_PLL_SSC0_reg                                             0xb8000710
#define EMMC_PLL_SSC0_inst_addr                                       "0x01C4"
#define EMMC_PLL_SSC0_inst                                            0x01C4
#define set_EMMC_PLL_SSC0_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC0_reg)=data)
#define get_EMMC_PLL_SSC0_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC0_reg))
#define EMMC_PLL_SSC0_pllemmc_oc_step_set_shift                       (4)
#define EMMC_PLL_SSC0_pllemmc_oc_en_shift                             (0)
#define EMMC_PLL_SSC0_pllemmc_oc_step_set_mask                        (0x00003FF0)
#define EMMC_PLL_SSC0_pllemmc_oc_en_mask                              (0x00000001)
#define EMMC_PLL_SSC0_pllemmc_oc_step_set(data)                       (0x00003FF0&((data)<<4))
#define EMMC_PLL_SSC0_pllemmc_oc_en(data)                             (0x00000001&(data))
#define EMMC_PLL_SSC0_get_pllemmc_oc_step_set(data)                   ((0x00003FF0&(data))>>4)
#define EMMC_PLL_SSC0_get_pllemmc_oc_en(data)                         (0x00000001&(data))


#define EMMC_PLL_SSC1                                                 0x18000714
#define EMMC_PLL_SSC1_reg_addr                                        "0xb8000714"
#define EMMC_PLL_SSC1_reg                                             0xb8000714
#define EMMC_PLL_SSC1_inst_addr                                       "0x01C5"
#define EMMC_PLL_SSC1_inst                                            0x01C5
#define set_EMMC_PLL_SSC1_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC1_reg)=data)
#define get_EMMC_PLL_SSC1_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC1_reg))
#define EMMC_PLL_SSC1_pllemmc_oc_done_delay_shift                     (16)
#define EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_shift                   (12)
#define EMMC_PLL_SSC1_pllemmc_pi_cur_sel_shift                        (10)
#define EMMC_PLL_SSC1_pllemmc_sel_oc_mode_shift                       (8)
#define EMMC_PLL_SSC1_pllemmc_oc_done_delay_mask                      (0x003F0000)
#define EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_mask                    (0x00003000)
#define EMMC_PLL_SSC1_pllemmc_pi_cur_sel_mask                         (0x00000C00)
#define EMMC_PLL_SSC1_pllemmc_sel_oc_mode_mask                        (0x00000300)
#define EMMC_PLL_SSC1_pllemmc_oc_done_delay(data)                     (0x003F0000&((data)<<16))
#define EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff(data)                   (0x00003000&((data)<<12))
#define EMMC_PLL_SSC1_pllemmc_pi_cur_sel(data)                        (0x00000C00&((data)<<10))
#define EMMC_PLL_SSC1_pllemmc_sel_oc_mode(data)                       (0x00000300&((data)<<8))
#define EMMC_PLL_SSC1_get_pllemmc_oc_done_delay(data)                 ((0x003F0000&(data))>>16)
#define EMMC_PLL_SSC1_get_pllemmc_hs_oc_stop_diff(data)               ((0x00003000&(data))>>12)
#define EMMC_PLL_SSC1_get_pllemmc_pi_cur_sel(data)                    ((0x00000C00&(data))>>10)
#define EMMC_PLL_SSC1_get_pllemmc_sel_oc_mode(data)                   ((0x00000300&(data))>>8)


#define EMMC_PLL_SSC2                                                 0x18000718
#define EMMC_PLL_SSC2_reg_addr                                        "0xb8000718"
#define EMMC_PLL_SSC2_reg                                             0xb8000718
#define EMMC_PLL_SSC2_inst_addr                                       "0x01C6"
#define EMMC_PLL_SSC2_inst                                            0x01C6
#define set_EMMC_PLL_SSC2_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC2_reg)=data)
#define get_EMMC_PLL_SSC2_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC2_reg))
#define EMMC_PLL_SSC2_pllemmc_en_pi_debug_shift                       (2)
#define EMMC_PLL_SSC2_pllemmc_sdm_order_shift                         (1)
#define EMMC_PLL_SSC2_pllemmc_bypass_pi_shift                         (0)
#define EMMC_PLL_SSC2_pllemmc_en_pi_debug_mask                        (0x00000004)
#define EMMC_PLL_SSC2_pllemmc_sdm_order_mask                          (0x00000002)
#define EMMC_PLL_SSC2_pllemmc_bypass_pi_mask                          (0x00000001)
#define EMMC_PLL_SSC2_pllemmc_en_pi_debug(data)                       (0x00000004&((data)<<2))
#define EMMC_PLL_SSC2_pllemmc_sdm_order(data)                         (0x00000002&((data)<<1))
#define EMMC_PLL_SSC2_pllemmc_bypass_pi(data)                         (0x00000001&(data))
#define EMMC_PLL_SSC2_get_pllemmc_en_pi_debug(data)                   ((0x00000004&(data))>>2)
#define EMMC_PLL_SSC2_get_pllemmc_sdm_order(data)                     ((0x00000002&(data))>>1)
#define EMMC_PLL_SSC2_get_pllemmc_bypass_pi(data)                     (0x00000001&(data))


#define EMMC_PLL_SSC3                                                 0x1800071c
#define EMMC_PLL_SSC3_reg_addr                                        "0xb800071c"
#define EMMC_PLL_SSC3_reg                                             0xb800071c
#define EMMC_PLL_SSC3_inst_addr                                       "0x01C7"
#define EMMC_PLL_SSC3_inst                                            0x01C7
#define set_EMMC_PLL_SSC3_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC3_reg)=data)
#define get_EMMC_PLL_SSC3_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC3_reg))
#define EMMC_PLL_SSC3_pllemmc_ncode_ssc_shift                         (16)
#define EMMC_PLL_SSC3_pllemmc_fcode_ssc_shift                         (0)
#define EMMC_PLL_SSC3_pllemmc_ncode_ssc_mask                          (0x00FF0000)
#define EMMC_PLL_SSC3_pllemmc_fcode_ssc_mask                          (0x000007FF)
#define EMMC_PLL_SSC3_pllemmc_ncode_ssc(data)                         (0x00FF0000&((data)<<16))
#define EMMC_PLL_SSC3_pllemmc_fcode_ssc(data)                         (0x000007FF&(data))
#define EMMC_PLL_SSC3_get_pllemmc_ncode_ssc(data)                     ((0x00FF0000&(data))>>16)
#define EMMC_PLL_SSC3_get_pllemmc_fcode_ssc(data)                     (0x000007FF&(data))


#define EMMC_PLL_SSC4                                                 0x18000720
#define EMMC_PLL_SSC4_reg_addr                                        "0xb8000720"
#define EMMC_PLL_SSC4_reg                                             0xb8000720
#define EMMC_PLL_SSC4_inst_addr                                       "0x01C8"
#define EMMC_PLL_SSC4_inst                                            0x01C8
#define set_EMMC_PLL_SSC4_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC4_reg)=data)
#define get_EMMC_PLL_SSC4_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC4_reg))
#define EMMC_PLL_SSC4_pllemmc_ncode_t_shift                           (16)
#define EMMC_PLL_SSC4_pllemmc_fcode_t_shift                           (0)
#define EMMC_PLL_SSC4_pllemmc_ncode_t_mask                            (0x00FF0000)
#define EMMC_PLL_SSC4_pllemmc_fcode_t_mask                            (0x000007FF)
#define EMMC_PLL_SSC4_pllemmc_ncode_t(data)                           (0x00FF0000&((data)<<16))
#define EMMC_PLL_SSC4_pllemmc_fcode_t(data)                           (0x000007FF&(data))
#define EMMC_PLL_SSC4_get_pllemmc_ncode_t(data)                       ((0x00FF0000&(data))>>16)
#define EMMC_PLL_SSC4_get_pllemmc_fcode_t(data)                       (0x000007FF&(data))


#define EMMC_PLL_SSC5                                                 0x18000724
#define EMMC_PLL_SSC5_reg_addr                                        "0xb8000724"
#define EMMC_PLL_SSC5_reg                                             0xb8000724
#define EMMC_PLL_SSC5_inst_addr                                       "0x01C9"
#define EMMC_PLL_SSC5_inst                                            0x01C9
#define set_EMMC_PLL_SSC5_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC5_reg)=data)
#define get_EMMC_PLL_SSC5_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC5_reg))
#define EMMC_PLL_SSC5_pllemmc_gran_auto_rst_shift                     (28)
#define EMMC_PLL_SSC5_pllemmc_dot_gran_shift                          (24)
#define EMMC_PLL_SSC5_pllemmc_gran_est_shift                          (4)
#define EMMC_PLL_SSC5_pllemmc_en_ssc_shift                            (0)
#define EMMC_PLL_SSC5_pllemmc_gran_auto_rst_mask                      (0x10000000)
#define EMMC_PLL_SSC5_pllemmc_dot_gran_mask                           (0x07000000)
#define EMMC_PLL_SSC5_pllemmc_gran_est_mask                           (0x007FFFF0)
#define EMMC_PLL_SSC5_pllemmc_en_ssc_mask                             (0x00000001)
#define EMMC_PLL_SSC5_pllemmc_gran_auto_rst(data)                     (0x10000000&((data)<<28))
#define EMMC_PLL_SSC5_pllemmc_dot_gran(data)                          (0x07000000&((data)<<24))
#define EMMC_PLL_SSC5_pllemmc_gran_est(data)                          (0x007FFFF0&((data)<<4))
#define EMMC_PLL_SSC5_pllemmc_en_ssc(data)                            (0x00000001&(data))
#define EMMC_PLL_SSC5_get_pllemmc_gran_auto_rst(data)                 ((0x10000000&(data))>>28)
#define EMMC_PLL_SSC5_get_pllemmc_dot_gran(data)                      ((0x07000000&(data))>>24)
#define EMMC_PLL_SSC5_get_pllemmc_gran_est(data)                      ((0x007FFFF0&(data))>>4)
#define EMMC_PLL_SSC5_get_pllemmc_en_ssc(data)                        (0x00000001&(data))


#define EMMC_PLL_SSC6                                                 0x18000728
#define EMMC_PLL_SSC6_reg_addr                                        "0xb8000728"
#define EMMC_PLL_SSC6_reg                                             0xb8000728
#define EMMC_PLL_SSC6_inst_addr                                       "0x01CA"
#define EMMC_PLL_SSC6_inst                                            0x01CA
#define set_EMMC_PLL_SSC6_reg(data)                                   (*((volatile unsigned int*)EMMC_PLL_SSC6_reg)=data)
#define get_EMMC_PLL_SSC6_reg                                         (*((volatile unsigned int*)EMMC_PLL_SSC6_reg))
#define EMMC_PLL_SSC6_pllemmc_fcode_debug_shift                       (16)
#define EMMC_PLL_SSC6_pllemmc_ncode_debug_shift                       (8)
#define EMMC_PLL_SSC6_pllemmc_oc_done_shift                           (4)
#define EMMC_PLL_SSC6_pllemmc_fmod_shift                              (0)
#define EMMC_PLL_SSC6_pllemmc_fcode_debug_mask                        (0x07FF0000)
#define EMMC_PLL_SSC6_pllemmc_ncode_debug_mask                        (0x0000FF00)
#define EMMC_PLL_SSC6_pllemmc_oc_done_mask                            (0x00000010)
#define EMMC_PLL_SSC6_pllemmc_fmod_mask                               (0x00000001)
#define EMMC_PLL_SSC6_pllemmc_fcode_debug(data)                       (0x07FF0000&((data)<<16))
#define EMMC_PLL_SSC6_pllemmc_ncode_debug(data)                       (0x0000FF00&((data)<<8))
#define EMMC_PLL_SSC6_pllemmc_oc_done(data)                           (0x00000010&((data)<<4))
#define EMMC_PLL_SSC6_pllemmc_fmod(data)                              (0x00000001&(data))
#define EMMC_PLL_SSC6_get_pllemmc_fcode_debug(data)                   ((0x07FF0000&(data))>>16)
#define EMMC_PLL_SSC6_get_pllemmc_ncode_debug(data)                   ((0x0000FF00&(data))>>8)
#define EMMC_PLL_SSC6_get_pllemmc_oc_done(data)                       ((0x00000010&(data))>>4)
#define EMMC_PLL_SSC6_get_pllemmc_fmod(data)                          (0x00000001&(data))
#endif
