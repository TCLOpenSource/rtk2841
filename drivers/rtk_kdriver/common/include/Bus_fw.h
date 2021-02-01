// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:744                    Version flow no.:1.0.200
#ifndef _BUS_REG_H_INCLUDED_
#define _BUS_REG_H_INCLUDED_

//#define  _BUS_USE_STRUCT
#ifdef _BUS_USE_STRUCT

typedef struct
{
    unsigned int    lx_m2m_pricnt_sta:8;
    unsigned int    lx_m2m_pricnt_end:8;
    unsigned int    lx_avcpu_pricnt_sta:8;
    unsigned int    lx_avcpu_pricnt_end:8;
}LXBUS_priority_count_1;

typedef struct
{
    unsigned int    lx_lxctrl_pricnt_sta:8;
    unsigned int    lx_lxctrl_pricnt_end:8;
    unsigned int    lx_jpeg_pricnt_sta:8;
    unsigned int    lx_jpeg_pricnt_end:8;
}LXBUS_priority_count_2;

typedef struct
{
    unsigned int    lx_usb_pricnt_sta:8;
    unsigned int    lx_usb_pricnt_end:8;
    unsigned int    lx_otg_pricnt_sta:8;
    unsigned int    lx_otg_pricnt_end:8;
}LXBUS_priority_count_3;

typedef struct
{
    unsigned int    lx_cr_pricnt_sta:8;
    unsigned int    lx_cr_pricnt_end:8;
    unsigned int    lx_sfc_pricnt_sta:8;
    unsigned int    lx_sfc_pricnt_end:8;
}LXBUS_priority_count_4;

typedef struct
{
    unsigned int    dummy18044010_31_3:29;
    unsigned int    lx_to_period:3;
}LXBUS_timeout_control;

typedef struct
{
    unsigned int    no_frame_event:1;
    unsigned int    no_idry_event:1;
    unsigned int    invalid_bl_event:1;
    unsigned int    zero_bl_event:1;
    unsigned int    frame_low_late_event:1;
    unsigned int    frame_low_early_event:1;
    unsigned int    irdy_low_early_event:1;
    unsigned int    irdy_high_late_event:1;
    unsigned int    reserved_0:4;
    unsigned int    auto_clear_timeout_en:1;
    unsigned int    no_frame_event_gen_to_pending_en:1;
    unsigned int    no_idry_event_gen_to_pending_en:1;
    unsigned int    invalid_bl_event_gen_to_pending_en:1;
    unsigned int    zero_bl_event_gen_to_pending_en:1;
    unsigned int    frame_low_late_event_gen_to_pending_en:1;
    unsigned int    frame_low_early_event_gen_to_pending_en:1;
    unsigned int    irdy_low_early_event_gen_to_pending_en:1;
    unsigned int    irdy_high_late_event_gen_to_pending_en:1;
    unsigned int    to_stop_gnt_en:1;
    unsigned int    lx_to_intr_en:1;
    unsigned int    lx_to_intr_pending:1;
    unsigned int    lx_to_id:4;
    unsigned int    lx_to_type:4;
}LXBUS_timeout_status;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    lx_sfc_off:1;
    unsigned int    lx_cr_off:1;
    unsigned int    lx_otg_off:1;
    unsigned int    lx_usb_off:1;
    unsigned int    lx_jpeg_off:1;
    unsigned int    lx_lxctrl_off:1;
    unsigned int    lx_avcpu_off:1;
    unsigned int    lx_m2m_off:1;
    unsigned int    reserved_1:8;
    unsigned int    lx_sfc_gnt:1;
    unsigned int    lx_cr_gnt:1;
    unsigned int    lx_otg_gnt:1;
    unsigned int    lx_usb_gnt:1;
    unsigned int    lx_jpeg_gnt:1;
    unsigned int    lx_lxctrl_gnt:1;
    unsigned int    lx_mcpu_gnt:1;
    unsigned int    lx_m2m_gnt:1;
}LXBUS_master_control;

typedef struct
{
    unsigned int    lx_monitor_max_latency:16;
    unsigned int    reserved_0:12;
    unsigned int    lx_monitor_id:4;
}LXBUS_latency_monitor_1;

typedef struct
{
    unsigned int    lx_monitor_req:32;
}LXBUS_latency_monitor_2;

typedef struct
{
    unsigned int    lx_monitor_acc_latency:32;
}LXBUS_latency_monitor_3;

typedef struct
{
    unsigned int    lx_crc_rst:1;
    unsigned int    lx_crc_en:1;
    unsigned int    dummy18044028_29_9:21;
    unsigned int    lx_crc_id:5;
    unsigned int    reserved_0:1;
    unsigned int    lx_crc_sel:3;
}LXBUS_crc_control;

typedef struct
{
    unsigned int    lx_crc_out:32;
}LXBUS_crc_output;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    bus_monitor_en:1;
    unsigned int    pri_cnt_tick_sel:4;
    unsigned int    reserved_1:2;
    unsigned int    lx_debug_sel:6;
}LXBUS_debug_ctl;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    bist_fail:1;
    unsigned int    bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    bist_rstn:1;
    unsigned int    bist_mode:1;
}LXBUS_bist;

typedef struct
{
    unsigned int    avcpu_mqa:31;
    unsigned int    avcpu_itb:1;
}IRC_2av;

typedef struct
{
    unsigned int    mcpu_mqa:31;
    unsigned int    mcpu_itb:1;
}IRC_2main;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    force_spi_boot:1;
    unsigned int    avcpu_enrc:1;
}RISC_enable;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    mcpu_exvoffset:8;
}MCPU_exception_offset;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    avcpu_exvoffset:8;
}AVCPU_exception_offset;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    avdma_dmem_addr:13;
    unsigned int    reserved_1:2;
}RISC_av_dma_dmem_addr;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    avdma_ddr_addr:24;
    unsigned int    reserved_1:2;
}RISC_av_dma_ddr_addr;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    avdma_ie:1;
    unsigned int    avdma_softrst:1;
    unsigned int    avdma_start:1;
    unsigned int    avdma_dir:1;
    unsigned int    reserved_1:2;
    unsigned int    avdma_size:14;
}RISC_av_dma_ctrl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    avdma_ip:1;
}RISC_av_dma_status;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    m2m_dst:24;
    unsigned int    reserved_1:2;
}M2M_dma_dst;

typedef struct
{
    unsigned int    reserved_0:6;
    unsigned int    m2m_src:24;
    unsigned int    reserved_1:2;
}M2M_dma_src;

typedef struct
{
    unsigned int    m2m_pattern:32;
}M2M_dma_pattern;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m2m_ie:1;
    unsigned int    m2m_mode:1;
    unsigned int    reserved_1:1;
    unsigned int    m2m_start:1;
    unsigned int    m2m_size:22;
    unsigned int    reserved_2:2;
}M2M_dma_ctrl;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    m2m_busy:1;
    unsigned int    m2m_ip:1;
}M2M_dma_status;

typedef struct
{
    unsigned int    atomic_debug_mode:1;
    unsigned int    reserved_0:23;
    unsigned int    atomic_value:8;
}ATOMIC_counter;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    rom_bist_mode:1;
    unsigned int    rom_bist_resetn:1;
    unsigned int    rom_bist_done:1;
}RISC_rom_bist_cmd;

typedef struct
{
    unsigned int    rom_bist_cmp_data:32;
}RISC_rom_bist_cmp_data;

typedef struct
{
    unsigned int    dummy18003044_31_7:25;
    unsigned int    mheader_bus_monitor_on:1;
    unsigned int    mheader_monitor_sel_rbus:2;
    unsigned int    mheader_monitor_burst:2;
    unsigned int    mheader_monitor_rw:2;
}MHEADER_monitor_control;

typedef struct
{
    unsigned int    mheader_monitor_req:32;
}MHEADER_monitor_status_1;

typedef struct
{
    unsigned int    dummy1800304c_31_7:25;
    unsigned int    avheader_bus_monitor_on:1;
    unsigned int    avheader_monitor_sel_rbus:2;
    unsigned int    avheader_monitor_burst:2;
    unsigned int    avheader_monitor_rw:2;
}AVHEADER_monitor_control;

typedef struct
{
    unsigned int    avheader_monitor_req:32;
}AVHEADER_monitor_status_1;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    mcpu_bist_mode:1;
    unsigned int    mcpu_bist_rstn:1;
    unsigned int    mcpu_bist_done:1;
    unsigned int    reserved_1:2;
    unsigned int    mcpu_bist_fail:3;
}MCPU_cpu_bist;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    avcpu_bist_mode:1;
    unsigned int    avcpu_bist_rstn:1;
    unsigned int    avcpu_bist_done:1;
    unsigned int    avcpu_bist_fail:8;
    unsigned int    avcpu_bist_done_dma:1;
    unsigned int    avcpu_bist_fail_dma:1;
}AVCPU_cpu_bist;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    m2mdma_bist_mode:1;
    unsigned int    m2mdma_bist_rstn:1;
    unsigned int    m2mdma_bist_done:1;
    unsigned int    m2mdma_bist_fail:1;
}M2M_dma_bist;

typedef struct
{
    unsigned int    avcpu_bisr_pwr_rst:1;
    unsigned int    reserved_0:28;
    unsigned int    avcpu_hold_remap:1;
    unsigned int    avcpu_bisr_soft_rst:1;
    unsigned int    avcpu_bisr_soft_run:1;
}AVCPU_bistr_control;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    avcpu_bisr_so_1:11;
    unsigned int    avcpu_bisr_so_0:9;
    unsigned int    avcpu_bisr_fail_4:1;
    unsigned int    avcpu_bisr_fail_3:1;
    unsigned int    avcpu_bisr_fail_2:1;
    unsigned int    avcpu_bisr_fail_1:1;
    unsigned int    avcpu_bisr_fail_0:1;
    unsigned int    reserved_1:1;
    unsigned int    avcpu_bisr_repaired:1;
    unsigned int    avcpu_bisr_done:1;
}AVCPU_bistr_icache1;

typedef struct
{
    unsigned int    avcpu_bisr_so_4:10;
    unsigned int    avcpu_bisr_so_3:10;
    unsigned int    reserved_0:1;
    unsigned int    avcpu_bisr_so_2:11;
}AVCPU_bistr_icache2;

typedef struct
{
    unsigned int    rbus_to_cyc:16;
    unsigned int    dummy18003100_15_9:7;
    unsigned int    rbus_mcpu_to_int_en:1;
    unsigned int    reserved_0:6;
    unsigned int    rbus_ack_mask_clr:1;
    unsigned int    rbus_softrst:1;
}RBUS_arbiter_ctrl1;

typedef struct
{
    unsigned int    rbus_ack_mask_st:30;
    unsigned int    rbus_to_type:1;
    unsigned int    rbus_mcpu_to:1;
}RBUS_arbiter_ctrl2;

typedef struct
{
    unsigned int    rbus_last_addr:32;
}RBUS_arbiter_ctrl3;

typedef struct
{
    unsigned int    rbus_last_data:32;
}RBUS_arbiter_ctrl4;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    crc_cmp_latch_en:1;
}CRC_cmp_ctrl;

typedef struct
{
    unsigned int    crc_cmp_epv:32;
}CRC_cmp_data;

typedef struct
{
    unsigned int    crc_cmp_rslt:32;
}CRC_cmp_rslt;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    pict_set_num:7;
    unsigned int    pict_width_scale:5;
    unsigned int    pict_init_page:13;
}DC_pict_set;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    pict_set_offset_y:10;
    unsigned int    pict_set_num:7;
    unsigned int    pict_set_offset_x:10;
}DC_pict_set_offset;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    ddr_phy_sel:1;
    unsigned int    pict_offset_en:1;
    unsigned int    page_size:2;
    unsigned int    pre_arb_rd_cnt:8;
    unsigned int    pre_arb_wr_cnt:8;
}DC_sys_misc;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    sb1_pri:3;
    unsigned int    reserved_1:1;
    unsigned int    aio_pri:3;
    unsigned int    reserved_2:1;
    unsigned int    sb0_pri:3;
    unsigned int    reserved_3:5;
    unsigned int    sb3_pri:3;
}DC_hi_priority_ctrl_0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    rotdma_pri:4;
    unsigned int    dmbt_pri:4;
    unsigned int    l2d_pri:4;
    unsigned int    vbippr_pri:4;
    unsigned int    mcpu_pri:4;
    unsigned int    sb2_pri:4;
}DC_lo_priority_ctrl_0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    se_pri:4;
    unsigned int    meblk_pri:4;
    unsigned int    veblk_pri:4;
    unsigned int    l2d1_pri:4;
    unsigned int    meseq_pri:4;
    unsigned int    veseq_pri:4;
}DC_lo_priority_ctrl_1;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    req_pending:1;
    unsigned int    reserved_1:1;
    unsigned int    req_id:15;
}DC_req_status_chk;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    pc_go:1;
    unsigned int    reserved_1:8;
}DC_pc_ctrl;

typedef struct
{
    unsigned int    pc_total_cycl:32;
}DC_pc_total_cycl;

typedef struct
{
    unsigned int    pc_dbus_idle:32;
}DC_pc_dbus_idle;

typedef struct
{
    unsigned int    pc_dbus_ack_num:32;
}DC_pc_dbus_ack;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_0;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_1;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_2;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_3;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_4;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_5;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_6;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_7;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_8;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_9;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_10;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_11;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_12;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_13;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_14;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_15;

typedef struct
{
    unsigned int    pc_acc_latency:32;
}DC_pc_set_acc_16;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_1;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_2;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_3;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_4;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_5;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_6;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_7;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_8;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_9;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_10;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_11;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_12;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_13;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_14;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_15;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    pc_max_latency:16;
}DC_pc_set_max_req_16;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_1;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_2;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_3;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_4;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_5;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_6;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_7;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_8;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_9;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_10;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_11;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_12;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_13;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_14;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_15;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    pc_req_number:24;
}DC_pc_set_req_num_16;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_0;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_1;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_2;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_3;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_4;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_5;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_6;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_7;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_8;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_9;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_10;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_11;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_12;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_13;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_14;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_15;

typedef struct
{
    unsigned int    reserved_0:2;
    unsigned int    pc_ack_number:30;
}DC_pc_set_ack_num_16;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_0;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_1;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_2;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_3;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_4;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_5;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_6;

typedef struct
{
    unsigned int    mem_type:2;
    unsigned int    reserved_0:3;
    unsigned int    saddr:22;
    unsigned int    reserved_1:5;
}DC_mt_saddr_7;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_0;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_2;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_3;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_4;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_5;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_6;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    eaddr:22;
    unsigned int    reserved_1:5;
}DC_mt_eaddr_7;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_0;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_1;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_2;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_3;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_4;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_5;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_6;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    write_enable1:1;
    unsigned int    int1:1;
    unsigned int    write_enable2:1;
    unsigned int    int2:1;
    unsigned int    write_enable3:1;
    unsigned int    int3:1;
    unsigned int    write_enable4:1;
    unsigned int    cpu:2;
    unsigned int    int1_en:1;
    unsigned int    int2_en:1;
    unsigned int    int3_en:1;
    unsigned int    write_enable5:1;
    unsigned int    mode:2;
}DC_mt_mode_7;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_0;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_1;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_2;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_3;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_4;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_5;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_6;

typedef struct
{
    unsigned int    reserved_0:5;
    unsigned int    module_id_0:7;
    unsigned int    access_type_0:2;
    unsigned int    module_id_1:7;
    unsigned int    access_type_1:2;
    unsigned int    module_id_2:7;
    unsigned int    access_type_2:2;
}DC_mt_table_0_7;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_0;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_1;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_2;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_3;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_4;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_5;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_6;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    module_id_3:7;
    unsigned int    access_type_3:2;
}DC_mt_table_1_7;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_0;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_1;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_2;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_3;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_4;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_5;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_6;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    module_id:7;
    unsigned int    addcmd:15;
}DC_mt_addcmd_hi_7;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_0;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_1;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_2;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_3;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_4;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_5;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_6;

typedef struct
{
    unsigned int    addcmd:32;
}DC_mt_addcmd_lo_7;

typedef struct
{
    unsigned int    dec_mode:1;
    unsigned int    reserved_0:12;
    unsigned int    cnt_src_sel:3;
    unsigned int    time_step:4;
    unsigned int    reserved_1:9;
    unsigned int    arb_en:3;
}SB0_arb_cr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vdec_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    vdec_latcnt_beg:12;
}SB0_latcnt_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dispcaps_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    dispcaps_latcnt_beg:12;
}SB0_latcnt_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dispcapm_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    dispcapm_latcnt_beg:12;
}SB0_latcnt_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vdec_credit_val:12;
    unsigned int    vdec_deficit_val:8;
    unsigned int    vdec_elapse_val:8;
}SB0_wdrr_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dispcaps_credit_val:12;
    unsigned int    dispcaps_deficit_val:8;
    unsigned int    dispcaps_elapse_val:8;
}SB0_wdrr_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dispcapm_credit_val:12;
    unsigned int    dispcapm_deficit_val:8;
    unsigned int    dispcapm_elapse_val:8;
}SB0_wdrr_cr3;

typedef struct
{
    unsigned int    vdec_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    vdec_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    vdec_low_lvl_val:12;
}SB0_arb_cntr_set1;

typedef struct
{
    unsigned int    dispcaps_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    dispcaps_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    dispcaps_low_lvl_val:12;
}SB0_arb_cntr_set2;

typedef struct
{
    unsigned int    dispcapm_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    dispcapm_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    dispcapm_low_lvl_val:12;
}SB0_arb_cntr_set3;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    max_count:4;
    unsigned int    reserved_1:8;
    unsigned int    off_time:8;
}SB0_req_cr;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    sb_req:3;
    unsigned int    sb_gnt:3;
    unsigned int    reserved_1:4;
    unsigned int    win_latcnt:12;
}SB0_arb_sr1;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    low_lvl_ie:3;
    unsigned int    reserved_1:13;
    unsigned int    low_lvl_ip:3;
}SB0_arb_sr2;

typedef struct
{
    unsigned int    dec_mode:1;
    unsigned int    reserved_0:6;
    unsigned int    cnt_src_sel:9;
    unsigned int    time_step:4;
    unsigned int    reserved_1:2;
    unsigned int    arb_en:10;
}SB3_arb_cr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    xcdim_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    xcdim_latcnt_beg:12;
}SB3_latcnt_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    bmposd_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    bmposd_latcnt_beg:12;
}SB3_latcnt_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdisps_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    disdisps_latcnt_beg:12;
}SB3_latcnt_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    l2d2_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    l2d2_latcnt_beg:12;
}SB3_latcnt_cr4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdispm_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    disdispm_latcnt_beg:12;
}SB3_latcnt_cr5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    idma_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    idma_latcnt_beg:12;
}SB3_latcnt_cr6;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibiwr_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gibiwr_latcnt_beg:12;
}SB3_latcnt_cr7;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    mvd_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    mvd_latcnt_beg:12;
}SB3_latcnt_cr8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibird_latcnt_end:12;
    unsigned int    reserved_1:4;
    unsigned int    gibird_latcnt_beg:12;
}SB3_latcnt_cr9;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    xcdim_credit_val:12;
    unsigned int    xcdim_deficit_val:8;
    unsigned int    xcdim_elapse_val:8;
}SB3_wdrr_cr1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    bmposd_credit_val:12;
    unsigned int    bmposd_deficit_val:8;
    unsigned int    bmposd_elapse_val:8;
}SB3_wdrr_cr2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdisps_credit_val:12;
    unsigned int    disdisps_deficit_val:8;
    unsigned int    disdisps_elapse_val:8;
}SB3_wdrr_cr3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    l2d2_credit_val:12;
    unsigned int    l2d2_deficit_val:8;
    unsigned int    l2d2_elapse_val:8;
}SB3_wdrr_cr4;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    disdispm_credit_val:12;
    unsigned int    disdispm_deficit_val:8;
    unsigned int    disdispm_elapse_val:8;
}SB3_wdrr_cr5;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    idma_credit_val:12;
    unsigned int    idma_deficit_val:8;
    unsigned int    idma_elapse_val:8;
}SB3_wdrr_cr6;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibiwr_credit_val:12;
    unsigned int    gibiwr_deficit_val:8;
    unsigned int    gibiwr_elapse_val:8;
}SB3_wdrr_cr7;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    mvd_credit_val:12;
    unsigned int    mvd_deficit_val:8;
    unsigned int    mvd_elapse_val:8;
}SB3_wdrr_cr8;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    gibird_credit_val:12;
    unsigned int    gibird_deficit_val:8;
    unsigned int    gibird_elapse_val:8;
}SB3_wdrr_cr9;

typedef struct
{
    unsigned int    xcdim_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    xcdim_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    xcdim_low_lvl_val:12;
}SB3_arb_cntr_set1;

typedef struct
{
    unsigned int    bmposd_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    bmposd_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    bmposd_low_lvl_val:12;
}SB3_arb_cntr_set2;

typedef struct
{
    unsigned int    disdisps_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    disdisps_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    disdisps_low_lvl_val:12;
}SB3_arb_cntr_set3;

typedef struct
{
    unsigned int    l2d2_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    l2d2_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    l2d2_low_lvl_val:12;
}SB3_arb_cntr_set4;

typedef struct
{
    unsigned int    disdispm_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    disdispm_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    disdispm_low_lvl_val:12;
}SB3_arb_cntr_set5;

typedef struct
{
    unsigned int    idma_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    idma_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    idma_low_lvl_val:12;
}SB3_arb_cntr_set6;

typedef struct
{
    unsigned int    gibiwr_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gibiwr_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gibiwr_low_lvl_val:12;
}SB3_arb_cntr_set7;

typedef struct
{
    unsigned int    mvd_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    mvd_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    mvd_low_lvl_val:12;
}SB3_arb_cntr_set8;

typedef struct
{
    unsigned int    gibird_cntr_val_set:1;
    unsigned int    reserved_0:3;
    unsigned int    gibird_cntr_val:12;
    unsigned int    reserved_1:4;
    unsigned int    gibird_low_lvl_val:12;
}SB3_arb_cntr_set9;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    resv_reg:3;
}SB3_arb_cntr_set10;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    max_count:4;
    unsigned int    reserved_1:8;
    unsigned int    off_time:8;
}SB3_req_cr;

typedef struct
{
    unsigned int    sb_req:10;
    unsigned int    sb_gnt:10;
    unsigned int    win_latcnt:12;
}SB3_arb_sr1;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    low_lvl_ie:9;
    unsigned int    reserved_1:7;
    unsigned int    low_lvl_ip:9;
}SB3_arb_sr2;
#endif

#define LXBUS_PRIORITY_COUNT_1                                        0x18044000
#define LXBUS_PRIORITY_COUNT_1_reg_addr                               "0xB8044000"
#define LXBUS_PRIORITY_COUNT_1_reg                                    0xB8044000
#define LXBUS_PRIORITY_COUNT_1_inst_addr                              "0x0000"
#define LXBUS_PRIORITY_COUNT_1_inst                                   0x0000
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_sta_shift                (24)
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_end_shift                (16)
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_sta_shift              (8)
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_end_shift              (0)
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_sta_mask                 (0xFF000000)
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_end_mask                 (0x00FF0000)
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_sta_mask               (0x0000FF00)
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_end_mask               (0x000000FF)
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_sta(data)                (0xFF000000&((data)<<24))
#define LXBUS_PRIORITY_COUNT_1_lx_m2m_pricnt_end(data)                (0x00FF0000&((data)<<16))
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_sta(data)              (0x0000FF00&((data)<<8))
#define LXBUS_PRIORITY_COUNT_1_lx_avcpu_pricnt_end(data)              (0x000000FF&(data))
#define LXBUS_PRIORITY_COUNT_1_get_lx_m2m_pricnt_sta(data)            ((0xFF000000&(data))>>24)
#define LXBUS_PRIORITY_COUNT_1_get_lx_m2m_pricnt_end(data)            ((0x00FF0000&(data))>>16)
#define LXBUS_PRIORITY_COUNT_1_get_lx_avcpu_pricnt_sta(data)          ((0x0000FF00&(data))>>8)
#define LXBUS_PRIORITY_COUNT_1_get_lx_avcpu_pricnt_end(data)          (0x000000FF&(data))

#define LXBUS_PRIORITY_COUNT_2                                        0x18044004
#define LXBUS_PRIORITY_COUNT_2_reg_addr                               "0xB8044004"
#define LXBUS_PRIORITY_COUNT_2_reg                                    0xB8044004
#define LXBUS_PRIORITY_COUNT_2_inst_addr                              "0x0001"
#define LXBUS_PRIORITY_COUNT_2_inst                                   0x0001
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_sta_shift             (24)
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_end_shift             (16)
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_sta_shift               (8)
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_end_shift               (0)
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_sta_mask              (0xFF000000)
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_end_mask              (0x00FF0000)
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_sta_mask                (0x0000FF00)
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_end_mask                (0x000000FF)
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_sta(data)             (0xFF000000&((data)<<24))
#define LXBUS_PRIORITY_COUNT_2_lx_lxctrl_pricnt_end(data)             (0x00FF0000&((data)<<16))
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_sta(data)               (0x0000FF00&((data)<<8))
#define LXBUS_PRIORITY_COUNT_2_lx_jpeg_pricnt_end(data)               (0x000000FF&(data))
#define LXBUS_PRIORITY_COUNT_2_get_lx_lxctrl_pricnt_sta(data)         ((0xFF000000&(data))>>24)
#define LXBUS_PRIORITY_COUNT_2_get_lx_lxctrl_pricnt_end(data)         ((0x00FF0000&(data))>>16)
#define LXBUS_PRIORITY_COUNT_2_get_lx_jpeg_pricnt_sta(data)           ((0x0000FF00&(data))>>8)
#define LXBUS_PRIORITY_COUNT_2_get_lx_jpeg_pricnt_end(data)           (0x000000FF&(data))

#define LXBUS_PRIORITY_COUNT_3                                        0x18044008
#define LXBUS_PRIORITY_COUNT_3_reg_addr                               "0xB8044008"
#define LXBUS_PRIORITY_COUNT_3_reg                                    0xB8044008
#define LXBUS_PRIORITY_COUNT_3_inst_addr                              "0x0002"
#define LXBUS_PRIORITY_COUNT_3_inst                                   0x0002
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_sta_shift                (24)
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_end_shift                (16)
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_sta_shift                (8)
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_end_shift                (0)
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_sta_mask                 (0xFF000000)
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_end_mask                 (0x00FF0000)
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_sta_mask                 (0x0000FF00)
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_end_mask                 (0x000000FF)
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_sta(data)                (0xFF000000&((data)<<24))
#define LXBUS_PRIORITY_COUNT_3_lx_usb_pricnt_end(data)                (0x00FF0000&((data)<<16))
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_sta(data)                (0x0000FF00&((data)<<8))
#define LXBUS_PRIORITY_COUNT_3_lx_otg_pricnt_end(data)                (0x000000FF&(data))
#define LXBUS_PRIORITY_COUNT_3_get_lx_usb_pricnt_sta(data)            ((0xFF000000&(data))>>24)
#define LXBUS_PRIORITY_COUNT_3_get_lx_usb_pricnt_end(data)            ((0x00FF0000&(data))>>16)
#define LXBUS_PRIORITY_COUNT_3_get_lx_otg_pricnt_sta(data)            ((0x0000FF00&(data))>>8)
#define LXBUS_PRIORITY_COUNT_3_get_lx_otg_pricnt_end(data)            (0x000000FF&(data))

#define LXBUS_PRIORITY_COUNT_4                                        0x1804400c
#define LXBUS_PRIORITY_COUNT_4_reg_addr                               "0xB804400C"
#define LXBUS_PRIORITY_COUNT_4_reg                                    0xB804400C
#define LXBUS_PRIORITY_COUNT_4_inst_addr                              "0x0003"
#define LXBUS_PRIORITY_COUNT_4_inst                                   0x0003
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_sta_shift                 (24)
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_end_shift                 (16)
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_sta_shift                (8)
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_end_shift                (0)
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_sta_mask                  (0xFF000000)
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_end_mask                  (0x00FF0000)
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_sta_mask                 (0x0000FF00)
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_end_mask                 (0x000000FF)
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_sta(data)                 (0xFF000000&((data)<<24))
#define LXBUS_PRIORITY_COUNT_4_lx_cr_pricnt_end(data)                 (0x00FF0000&((data)<<16))
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_sta(data)                (0x0000FF00&((data)<<8))
#define LXBUS_PRIORITY_COUNT_4_lx_sfc_pricnt_end(data)                (0x000000FF&(data))
#define LXBUS_PRIORITY_COUNT_4_get_lx_cr_pricnt_sta(data)             ((0xFF000000&(data))>>24)
#define LXBUS_PRIORITY_COUNT_4_get_lx_cr_pricnt_end(data)             ((0x00FF0000&(data))>>16)
#define LXBUS_PRIORITY_COUNT_4_get_lx_sfc_pricnt_sta(data)            ((0x0000FF00&(data))>>8)
#define LXBUS_PRIORITY_COUNT_4_get_lx_sfc_pricnt_end(data)            (0x000000FF&(data))

#define LXBUS_TIMEOUT_CONTROL                                         0x18044010
#define LXBUS_TIMEOUT_CONTROL_reg_addr                                "0xB8044010"
#define LXBUS_TIMEOUT_CONTROL_reg                                     0xB8044010
#define LXBUS_TIMEOUT_CONTROL_inst_addr                               "0x0004"
#define LXBUS_TIMEOUT_CONTROL_inst                                    0x0004
#define LXBUS_TIMEOUT_CONTROL_dummy18044010_31_3_shift                (3)
#define LXBUS_TIMEOUT_CONTROL_lx_to_period_shift                      (0)
#define LXBUS_TIMEOUT_CONTROL_dummy18044010_31_3_mask                 (0xFFFFFFF8)
#define LXBUS_TIMEOUT_CONTROL_lx_to_period_mask                       (0x00000007)
#define LXBUS_TIMEOUT_CONTROL_dummy18044010_31_3(data)                (0xFFFFFFF8&((data)<<3))
#define LXBUS_TIMEOUT_CONTROL_lx_to_period(data)                      (0x00000007&(data))
#define LXBUS_TIMEOUT_CONTROL_get_dummy18044010_31_3(data)            ((0xFFFFFFF8&(data))>>3)
#define LXBUS_TIMEOUT_CONTROL_get_lx_to_period(data)                  (0x00000007&(data))

#define LXBUS_TIMEOUT_STATUS                                          0x18044014
#define LXBUS_TIMEOUT_STATUS_reg_addr                                 "0xB8044014"
#define LXBUS_TIMEOUT_STATUS_reg                                      0xB8044014
#define LXBUS_TIMEOUT_STATUS_inst_addr                                "0x0005"
#define LXBUS_TIMEOUT_STATUS_inst                                     0x0005
#define LXBUS_TIMEOUT_STATUS_no_frame_event_shift                     (31)
#define LXBUS_TIMEOUT_STATUS_no_idry_event_shift                      (30)
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event_shift                   (29)
#define LXBUS_TIMEOUT_STATUS_zero_bl_event_shift                      (28)
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event_shift               (27)
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event_shift              (26)
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event_shift               (25)
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event_shift               (24)
#define LXBUS_TIMEOUT_STATUS_auto_clear_timeout_en_shift              (19)
#define LXBUS_TIMEOUT_STATUS_no_frame_event_gen_to_pending_en_shift   (18)
#define LXBUS_TIMEOUT_STATUS_no_idry_event_gen_to_pending_en_shift    (17)
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event_gen_to_pending_en_shift (16)
#define LXBUS_TIMEOUT_STATUS_zero_bl_event_gen_to_pending_en_shift    (15)
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event_gen_to_pending_en_shift (14)
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event_gen_to_pending_en_shift (13)
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event_gen_to_pending_en_shift (12)
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event_gen_to_pending_en_shift (11)
#define LXBUS_TIMEOUT_STATUS_to_stop_gnt_en_shift                     (10)
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_en_shift                      (9)
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_pending_shift                 (8)
#define LXBUS_TIMEOUT_STATUS_lx_to_id_shift                           (4)
#define LXBUS_TIMEOUT_STATUS_lx_to_type_shift                         (0)
#define LXBUS_TIMEOUT_STATUS_no_frame_event_mask                      (0x80000000)
#define LXBUS_TIMEOUT_STATUS_no_idry_event_mask                       (0x40000000)
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event_mask                    (0x20000000)
#define LXBUS_TIMEOUT_STATUS_zero_bl_event_mask                       (0x10000000)
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event_mask                (0x08000000)
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event_mask               (0x04000000)
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event_mask                (0x02000000)
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event_mask                (0x01000000)
#define LXBUS_TIMEOUT_STATUS_auto_clear_timeout_en_mask               (0x00080000)
#define LXBUS_TIMEOUT_STATUS_no_frame_event_gen_to_pending_en_mask    (0x00040000)
#define LXBUS_TIMEOUT_STATUS_no_idry_event_gen_to_pending_en_mask     (0x00020000)
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event_gen_to_pending_en_mask  (0x00010000)
#define LXBUS_TIMEOUT_STATUS_zero_bl_event_gen_to_pending_en_mask     (0x00008000)
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event_gen_to_pending_en_mask (0x00004000)
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event_gen_to_pending_en_mask (0x00002000)
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event_gen_to_pending_en_mask (0x00001000)
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event_gen_to_pending_en_mask (0x00000800)
#define LXBUS_TIMEOUT_STATUS_to_stop_gnt_en_mask                      (0x00000400)
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_en_mask                       (0x00000200)
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_pending_mask                  (0x00000100)
#define LXBUS_TIMEOUT_STATUS_lx_to_id_mask                            (0x000000F0)
#define LXBUS_TIMEOUT_STATUS_lx_to_type_mask                          (0x0000000F)
#define LXBUS_TIMEOUT_STATUS_no_frame_event(data)                     (0x80000000&((data)<<31))
#define LXBUS_TIMEOUT_STATUS_no_idry_event(data)                      (0x40000000&((data)<<30))
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event(data)                   (0x20000000&((data)<<29))
#define LXBUS_TIMEOUT_STATUS_zero_bl_event(data)                      (0x10000000&((data)<<28))
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event(data)               (0x08000000&((data)<<27))
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event(data)              (0x04000000&((data)<<26))
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event(data)               (0x02000000&((data)<<25))
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event(data)               (0x01000000&((data)<<24))
#define LXBUS_TIMEOUT_STATUS_auto_clear_timeout_en(data)              (0x00080000&((data)<<19))
#define LXBUS_TIMEOUT_STATUS_no_frame_event_gen_to_pending_en(data)   (0x00040000&((data)<<18))
#define LXBUS_TIMEOUT_STATUS_no_idry_event_gen_to_pending_en(data)    (0x00020000&((data)<<17))
#define LXBUS_TIMEOUT_STATUS_invalid_bl_event_gen_to_pending_en(data) (0x00010000&((data)<<16))
#define LXBUS_TIMEOUT_STATUS_zero_bl_event_gen_to_pending_en(data)    (0x00008000&((data)<<15))
#define LXBUS_TIMEOUT_STATUS_frame_low_late_event_gen_to_pending_en(data) (0x00004000&((data)<<14))
#define LXBUS_TIMEOUT_STATUS_frame_low_early_event_gen_to_pending_en(data) (0x00002000&((data)<<13))
#define LXBUS_TIMEOUT_STATUS_irdy_low_early_event_gen_to_pending_en(data) (0x00001000&((data)<<12))
#define LXBUS_TIMEOUT_STATUS_irdy_high_late_event_gen_to_pending_en(data) (0x00000800&((data)<<11))
#define LXBUS_TIMEOUT_STATUS_to_stop_gnt_en(data)                     (0x00000400&((data)<<10))
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_en(data)                      (0x00000200&((data)<<9))
#define LXBUS_TIMEOUT_STATUS_lx_to_intr_pending(data)                 (0x00000100&((data)<<8))
#define LXBUS_TIMEOUT_STATUS_lx_to_id(data)                           (0x000000F0&((data)<<4))
#define LXBUS_TIMEOUT_STATUS_lx_to_type(data)                         (0x0000000F&(data))
#define LXBUS_TIMEOUT_STATUS_get_no_frame_event(data)                 ((0x80000000&(data))>>31)
#define LXBUS_TIMEOUT_STATUS_get_no_idry_event(data)                  ((0x40000000&(data))>>30)
#define LXBUS_TIMEOUT_STATUS_get_invalid_bl_event(data)               ((0x20000000&(data))>>29)
#define LXBUS_TIMEOUT_STATUS_get_zero_bl_event(data)                  ((0x10000000&(data))>>28)
#define LXBUS_TIMEOUT_STATUS_get_frame_low_late_event(data)           ((0x08000000&(data))>>27)
#define LXBUS_TIMEOUT_STATUS_get_frame_low_early_event(data)          ((0x04000000&(data))>>26)
#define LXBUS_TIMEOUT_STATUS_get_irdy_low_early_event(data)           ((0x02000000&(data))>>25)
#define LXBUS_TIMEOUT_STATUS_get_irdy_high_late_event(data)           ((0x01000000&(data))>>24)
#define LXBUS_TIMEOUT_STATUS_get_auto_clear_timeout_en(data)          ((0x00080000&(data))>>19)
#define LXBUS_TIMEOUT_STATUS_get_no_frame_event_gen_to_pending_en(data) ((0x00040000&(data))>>18)
#define LXBUS_TIMEOUT_STATUS_get_no_idry_event_gen_to_pending_en(data)((0x00020000&(data))>>17)
#define LXBUS_TIMEOUT_STATUS_get_invalid_bl_event_gen_to_pending_en(data) ((0x00010000&(data))>>16)
#define LXBUS_TIMEOUT_STATUS_get_zero_bl_event_gen_to_pending_en(data)((0x00008000&(data))>>15)
#define LXBUS_TIMEOUT_STATUS_get_frame_low_late_event_gen_to_pending_en(data) ((0x00004000&(data))>>14)
#define LXBUS_TIMEOUT_STATUS_get_frame_low_early_event_gen_to_pending_en(data) ((0x00002000&(data))>>13)
#define LXBUS_TIMEOUT_STATUS_get_irdy_low_early_event_gen_to_pending_en(data) ((0x00001000&(data))>>12)
#define LXBUS_TIMEOUT_STATUS_get_irdy_high_late_event_gen_to_pending_en(data) ((0x00000800&(data))>>11)
#define LXBUS_TIMEOUT_STATUS_get_to_stop_gnt_en(data)                 ((0x00000400&(data))>>10)
#define LXBUS_TIMEOUT_STATUS_get_lx_to_intr_en(data)                  ((0x00000200&(data))>>9)
#define LXBUS_TIMEOUT_STATUS_get_lx_to_intr_pending(data)             ((0x00000100&(data))>>8)
#define LXBUS_TIMEOUT_STATUS_get_lx_to_id(data)                       ((0x000000F0&(data))>>4)
#define LXBUS_TIMEOUT_STATUS_get_lx_to_type(data)                     (0x0000000F&(data))

#define LXBUS_MASTER_CONTROL                                          0x18044018
#define LXBUS_MASTER_CONTROL_reg_addr                                 "0xB8044018"
#define LXBUS_MASTER_CONTROL_reg                                      0xB8044018
#define LXBUS_MASTER_CONTROL_inst_addr                                "0x0006"
#define LXBUS_MASTER_CONTROL_inst                                     0x0006
#define LXBUS_MASTER_CONTROL_lx_sfc_off_shift                         (23)
#define LXBUS_MASTER_CONTROL_lx_cr_off_shift                          (22)
#define LXBUS_MASTER_CONTROL_lx_otg_off_shift                         (21)
#define LXBUS_MASTER_CONTROL_lx_usb_off_shift                         (20)
#define LXBUS_MASTER_CONTROL_lx_jpeg_off_shift                        (19)
#define LXBUS_MASTER_CONTROL_lx_lxctrl_off_shift                      (18)
#define LXBUS_MASTER_CONTROL_lx_avcpu_off_shift                       (17)
#define LXBUS_MASTER_CONTROL_lx_m2m_off_shift                         (16)
#define LXBUS_MASTER_CONTROL_lx_sfc_gnt_shift                         (7)
#define LXBUS_MASTER_CONTROL_lx_cr_gnt_shift                          (6)
#define LXBUS_MASTER_CONTROL_lx_otg_gnt_shift                         (5)
#define LXBUS_MASTER_CONTROL_lx_usb_gnt_shift                         (4)
#define LXBUS_MASTER_CONTROL_lx_jpeg_gnt_shift                        (3)
#define LXBUS_MASTER_CONTROL_lx_lxctrl_gnt_shift                      (2)
#define LXBUS_MASTER_CONTROL_lx_mcpu_gnt_shift                        (1)
#define LXBUS_MASTER_CONTROL_lx_m2m_gnt_shift                         (0)
#define LXBUS_MASTER_CONTROL_lx_sfc_off_mask                          (0x00800000)
#define LXBUS_MASTER_CONTROL_lx_cr_off_mask                           (0x00400000)
#define LXBUS_MASTER_CONTROL_lx_otg_off_mask                          (0x00200000)
#define LXBUS_MASTER_CONTROL_lx_usb_off_mask                          (0x00100000)
#define LXBUS_MASTER_CONTROL_lx_jpeg_off_mask                         (0x00080000)
#define LXBUS_MASTER_CONTROL_lx_lxctrl_off_mask                       (0x00040000)
#define LXBUS_MASTER_CONTROL_lx_avcpu_off_mask                        (0x00020000)
#define LXBUS_MASTER_CONTROL_lx_m2m_off_mask                          (0x00010000)
#define LXBUS_MASTER_CONTROL_lx_sfc_gnt_mask                          (0x00000080)
#define LXBUS_MASTER_CONTROL_lx_cr_gnt_mask                           (0x00000040)
#define LXBUS_MASTER_CONTROL_lx_otg_gnt_mask                          (0x00000020)
#define LXBUS_MASTER_CONTROL_lx_usb_gnt_mask                          (0x00000010)
#define LXBUS_MASTER_CONTROL_lx_jpeg_gnt_mask                         (0x00000008)
#define LXBUS_MASTER_CONTROL_lx_lxctrl_gnt_mask                       (0x00000004)
#define LXBUS_MASTER_CONTROL_lx_mcpu_gnt_mask                         (0x00000002)
#define LXBUS_MASTER_CONTROL_lx_m2m_gnt_mask                          (0x00000001)
#define LXBUS_MASTER_CONTROL_lx_sfc_off(data)                         (0x00800000&((data)<<23))
#define LXBUS_MASTER_CONTROL_lx_cr_off(data)                          (0x00400000&((data)<<22))
#define LXBUS_MASTER_CONTROL_lx_otg_off(data)                         (0x00200000&((data)<<21))
#define LXBUS_MASTER_CONTROL_lx_usb_off(data)                         (0x00100000&((data)<<20))
#define LXBUS_MASTER_CONTROL_lx_jpeg_off(data)                        (0x00080000&((data)<<19))
#define LXBUS_MASTER_CONTROL_lx_lxctrl_off(data)                      (0x00040000&((data)<<18))
#define LXBUS_MASTER_CONTROL_lx_avcpu_off(data)                       (0x00020000&((data)<<17))
#define LXBUS_MASTER_CONTROL_lx_m2m_off(data)                         (0x00010000&((data)<<16))
#define LXBUS_MASTER_CONTROL_lx_sfc_gnt(data)                         (0x00000080&((data)<<7))
#define LXBUS_MASTER_CONTROL_lx_cr_gnt(data)                          (0x00000040&((data)<<6))
#define LXBUS_MASTER_CONTROL_lx_otg_gnt(data)                         (0x00000020&((data)<<5))
#define LXBUS_MASTER_CONTROL_lx_usb_gnt(data)                         (0x00000010&((data)<<4))
#define LXBUS_MASTER_CONTROL_lx_jpeg_gnt(data)                        (0x00000008&((data)<<3))
#define LXBUS_MASTER_CONTROL_lx_lxctrl_gnt(data)                      (0x00000004&((data)<<2))
#define LXBUS_MASTER_CONTROL_lx_mcpu_gnt(data)                        (0x00000002&((data)<<1))
#define LXBUS_MASTER_CONTROL_lx_m2m_gnt(data)                         (0x00000001&(data))
#define LXBUS_MASTER_CONTROL_get_lx_sfc_off(data)                     ((0x00800000&(data))>>23)
#define LXBUS_MASTER_CONTROL_get_lx_cr_off(data)                      ((0x00400000&(data))>>22)
#define LXBUS_MASTER_CONTROL_get_lx_otg_off(data)                     ((0x00200000&(data))>>21)
#define LXBUS_MASTER_CONTROL_get_lx_usb_off(data)                     ((0x00100000&(data))>>20)
#define LXBUS_MASTER_CONTROL_get_lx_jpeg_off(data)                    ((0x00080000&(data))>>19)
#define LXBUS_MASTER_CONTROL_get_lx_lxctrl_off(data)                  ((0x00040000&(data))>>18)
#define LXBUS_MASTER_CONTROL_get_lx_avcpu_off(data)                   ((0x00020000&(data))>>17)
#define LXBUS_MASTER_CONTROL_get_lx_m2m_off(data)                     ((0x00010000&(data))>>16)
#define LXBUS_MASTER_CONTROL_get_lx_sfc_gnt(data)                     ((0x00000080&(data))>>7)
#define LXBUS_MASTER_CONTROL_get_lx_cr_gnt(data)                      ((0x00000040&(data))>>6)
#define LXBUS_MASTER_CONTROL_get_lx_otg_gnt(data)                     ((0x00000020&(data))>>5)
#define LXBUS_MASTER_CONTROL_get_lx_usb_gnt(data)                     ((0x00000010&(data))>>4)
#define LXBUS_MASTER_CONTROL_get_lx_jpeg_gnt(data)                    ((0x00000008&(data))>>3)
#define LXBUS_MASTER_CONTROL_get_lx_lxctrl_gnt(data)                  ((0x00000004&(data))>>2)
#define LXBUS_MASTER_CONTROL_get_lx_mcpu_gnt(data)                    ((0x00000002&(data))>>1)
#define LXBUS_MASTER_CONTROL_get_lx_m2m_gnt(data)                     (0x00000001&(data))

#define LXBUS_LATENCY_MONITOR_1                                       0x1804401c
#define LXBUS_LATENCY_MONITOR_1_reg_addr                              "0xB804401C"
#define LXBUS_LATENCY_MONITOR_1_reg                                   0xB804401C
#define LXBUS_LATENCY_MONITOR_1_inst_addr                             "0x0007"
#define LXBUS_LATENCY_MONITOR_1_inst                                  0x0007
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_max_latency_shift          (16)
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_id_shift                   (0)
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_max_latency_mask           (0xFFFF0000)
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_id_mask                    (0x0000000F)
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_max_latency(data)          (0xFFFF0000&((data)<<16))
#define LXBUS_LATENCY_MONITOR_1_lx_monitor_id(data)                   (0x0000000F&(data))
#define LXBUS_LATENCY_MONITOR_1_get_lx_monitor_max_latency(data)      ((0xFFFF0000&(data))>>16)
#define LXBUS_LATENCY_MONITOR_1_get_lx_monitor_id(data)               (0x0000000F&(data))

#define LXBUS_LATENCY_MONITOR_2                                       0x18044020
#define LXBUS_LATENCY_MONITOR_2_reg_addr                              "0xB8044020"
#define LXBUS_LATENCY_MONITOR_2_reg                                   0xB8044020
#define LXBUS_LATENCY_MONITOR_2_inst_addr                             "0x0008"
#define LXBUS_LATENCY_MONITOR_2_inst                                  0x0008
#define LXBUS_LATENCY_MONITOR_2_lx_monitor_req_shift                  (0)
#define LXBUS_LATENCY_MONITOR_2_lx_monitor_req_mask                   (0xFFFFFFFF)
#define LXBUS_LATENCY_MONITOR_2_lx_monitor_req(data)                  (0xFFFFFFFF&(data))
#define LXBUS_LATENCY_MONITOR_2_get_lx_monitor_req(data)              (0xFFFFFFFF&(data))

#define LXBUS_LATENCY_MONITOR_3                                       0x18044024
#define LXBUS_LATENCY_MONITOR_3_reg_addr                              "0xB8044024"
#define LXBUS_LATENCY_MONITOR_3_reg                                   0xB8044024
#define LXBUS_LATENCY_MONITOR_3_inst_addr                             "0x0009"
#define LXBUS_LATENCY_MONITOR_3_inst                                  0x0009
#define LXBUS_LATENCY_MONITOR_3_lx_monitor_acc_latency_shift          (0)
#define LXBUS_LATENCY_MONITOR_3_lx_monitor_acc_latency_mask           (0xFFFFFFFF)
#define LXBUS_LATENCY_MONITOR_3_lx_monitor_acc_latency(data)          (0xFFFFFFFF&(data))
#define LXBUS_LATENCY_MONITOR_3_get_lx_monitor_acc_latency(data)      (0xFFFFFFFF&(data))

#define LXBUS_CRC_CONTROL                                             0x18044028
#define LXBUS_CRC_CONTROL_reg_addr                                    "0xB8044028"
#define LXBUS_CRC_CONTROL_reg                                         0xB8044028
#define LXBUS_CRC_CONTROL_inst_addr                                   "0x000A"
#define LXBUS_CRC_CONTROL_inst                                        0x000A
#define LXBUS_CRC_CONTROL_lx_crc_rst_shift                            (31)
#define LXBUS_CRC_CONTROL_lx_crc_en_shift                             (30)
#define LXBUS_CRC_CONTROL_dummy18044028_29_9_shift                    (9)
#define LXBUS_CRC_CONTROL_lx_crc_id_shift                             (4)
#define LXBUS_CRC_CONTROL_lx_crc_sel_shift                            (0)
#define LXBUS_CRC_CONTROL_lx_crc_rst_mask                             (0x80000000)
#define LXBUS_CRC_CONTROL_lx_crc_en_mask                              (0x40000000)
#define LXBUS_CRC_CONTROL_dummy18044028_29_9_mask                     (0x3FFFFE00)
#define LXBUS_CRC_CONTROL_lx_crc_id_mask                              (0x000001F0)
#define LXBUS_CRC_CONTROL_lx_crc_sel_mask                             (0x00000007)
#define LXBUS_CRC_CONTROL_lx_crc_rst(data)                            (0x80000000&((data)<<31))
#define LXBUS_CRC_CONTROL_lx_crc_en(data)                             (0x40000000&((data)<<30))
#define LXBUS_CRC_CONTROL_dummy18044028_29_9(data)                    (0x3FFFFE00&((data)<<9))
#define LXBUS_CRC_CONTROL_lx_crc_id(data)                             (0x000001F0&((data)<<4))
#define LXBUS_CRC_CONTROL_lx_crc_sel(data)                            (0x00000007&(data))
#define LXBUS_CRC_CONTROL_get_lx_crc_rst(data)                        ((0x80000000&(data))>>31)
#define LXBUS_CRC_CONTROL_get_lx_crc_en(data)                         ((0x40000000&(data))>>30)
#define LXBUS_CRC_CONTROL_get_dummy18044028_29_9(data)                ((0x3FFFFE00&(data))>>9)
#define LXBUS_CRC_CONTROL_get_lx_crc_id(data)                         ((0x000001F0&(data))>>4)
#define LXBUS_CRC_CONTROL_get_lx_crc_sel(data)                        (0x00000007&(data))

#define LXBUS_CRC_OUTPUT                                              0x1804402c
#define LXBUS_CRC_OUTPUT_reg_addr                                     "0xB804402C"
#define LXBUS_CRC_OUTPUT_reg                                          0xB804402C
#define LXBUS_CRC_OUTPUT_inst_addr                                    "0x000B"
#define LXBUS_CRC_OUTPUT_inst                                         0x000B
#define LXBUS_CRC_OUTPUT_lx_crc_out_shift                             (0)
#define LXBUS_CRC_OUTPUT_lx_crc_out_mask                              (0xFFFFFFFF)
#define LXBUS_CRC_OUTPUT_lx_crc_out(data)                             (0xFFFFFFFF&(data))
#define LXBUS_CRC_OUTPUT_get_lx_crc_out(data)                         (0xFFFFFFFF&(data))

#define LXBUS_DEBUG_CTL                                               0x18044030
#define LXBUS_DEBUG_CTL_reg_addr                                      "0xB8044030"
#define LXBUS_DEBUG_CTL_reg                                           0xB8044030
#define LXBUS_DEBUG_CTL_inst_addr                                     "0x000C"
#define LXBUS_DEBUG_CTL_inst                                          0x000C
#define LXBUS_DEBUG_CTL_bus_monitor_en_shift                          (12)
#define LXBUS_DEBUG_CTL_pri_cnt_tick_sel_shift                        (8)
#define LXBUS_DEBUG_CTL_lx_debug_sel_shift                            (0)
#define LXBUS_DEBUG_CTL_bus_monitor_en_mask                           (0x00001000)
#define LXBUS_DEBUG_CTL_pri_cnt_tick_sel_mask                         (0x00000F00)
#define LXBUS_DEBUG_CTL_lx_debug_sel_mask                             (0x0000003F)
#define LXBUS_DEBUG_CTL_bus_monitor_en(data)                          (0x00001000&((data)<<12))
#define LXBUS_DEBUG_CTL_pri_cnt_tick_sel(data)                        (0x00000F00&((data)<<8))
#define LXBUS_DEBUG_CTL_lx_debug_sel(data)                            (0x0000003F&(data))
#define LXBUS_DEBUG_CTL_get_bus_monitor_en(data)                      ((0x00001000&(data))>>12)
#define LXBUS_DEBUG_CTL_get_pri_cnt_tick_sel(data)                    ((0x00000F00&(data))>>8)
#define LXBUS_DEBUG_CTL_get_lx_debug_sel(data)                        (0x0000003F&(data))

#define LXBUS_BIST                                                    0x18044034
#define LXBUS_BIST_reg_addr                                           "0xB8044034"
#define LXBUS_BIST_reg                                                0xB8044034
#define LXBUS_BIST_inst_addr                                          "0x000D"
#define LXBUS_BIST_inst                                               0x000D
#define LXBUS_BIST_bist_fail_shift                                    (5)
#define LXBUS_BIST_bist_done_shift                                    (4)
#define LXBUS_BIST_bist_rstn_shift                                    (1)
#define LXBUS_BIST_bist_mode_shift                                    (0)
#define LXBUS_BIST_bist_fail_mask                                     (0x00000020)
#define LXBUS_BIST_bist_done_mask                                     (0x00000010)
#define LXBUS_BIST_bist_rstn_mask                                     (0x00000002)
#define LXBUS_BIST_bist_mode_mask                                     (0x00000001)
#define LXBUS_BIST_bist_fail(data)                                    (0x00000020&((data)<<5))
#define LXBUS_BIST_bist_done(data)                                    (0x00000010&((data)<<4))
#define LXBUS_BIST_bist_rstn(data)                                    (0x00000002&((data)<<1))
#define LXBUS_BIST_bist_mode(data)                                    (0x00000001&(data))
#define LXBUS_BIST_get_bist_fail(data)                                ((0x00000020&(data))>>5)
#define LXBUS_BIST_get_bist_done(data)                                ((0x00000010&(data))>>4)
#define LXBUS_BIST_get_bist_rstn(data)                                ((0x00000002&(data))>>1)
#define LXBUS_BIST_get_bist_mode(data)                                (0x00000001&(data))

#define IRC_2AV                                                       0x18003000
#define IRC_2AV_reg_addr                                              "0xB8003000"
#define IRC_2AV_reg                                                   0xB8003000
#define IRC_2AV_inst_addr                                             "0x0000"
#define IRC_2AV_inst                                                  0x0000
#define IRC_2AV_avcpu_mqa_shift                                       (1)
#define IRC_2AV_avcpu_itb_shift                                       (0)
#define IRC_2AV_avcpu_mqa_mask                                        (0xFFFFFFFE)
#define IRC_2AV_avcpu_itb_mask                                        (0x00000001)
#define IRC_2AV_avcpu_mqa(data)                                       (0xFFFFFFFE&((data)<<1))
#define IRC_2AV_avcpu_itb(data)                                       (0x00000001&(data))
#define IRC_2AV_get_avcpu_mqa(data)                                   ((0xFFFFFFFE&(data))>>1)
#define IRC_2AV_get_avcpu_itb(data)                                   (0x00000001&(data))

#define IRC_2MAIN                                                     0x18003004
#define IRC_2MAIN_reg_addr                                            "0xB8003004"
#define IRC_2MAIN_reg                                                 0xB8003004
#define IRC_2MAIN_inst_addr                                           "0x0001"
#define IRC_2MAIN_inst                                                0x0001
#define IRC_2MAIN_mcpu_mqa_shift                                      (1)
#define IRC_2MAIN_mcpu_itb_shift                                      (0)
#define IRC_2MAIN_mcpu_mqa_mask                                       (0xFFFFFFFE)
#define IRC_2MAIN_mcpu_itb_mask                                       (0x00000001)
#define IRC_2MAIN_mcpu_mqa(data)                                      (0xFFFFFFFE&((data)<<1))
#define IRC_2MAIN_mcpu_itb(data)                                      (0x00000001&(data))
#define IRC_2MAIN_get_mcpu_mqa(data)                                  ((0xFFFFFFFE&(data))>>1)
#define IRC_2MAIN_get_mcpu_itb(data)                                  (0x00000001&(data))

#define RISC_ENABLE                                                   0x18003008
#define RISC_ENABLE_reg_addr                                          "0xB8003008"
#define RISC_ENABLE_reg                                               0xB8003008
#define RISC_ENABLE_inst_addr                                         "0x0002"
#define RISC_ENABLE_inst                                              0x0002
#define RISC_ENABLE_force_spi_boot_shift                              (1)
#define RISC_ENABLE_avcpu_enrc_shift                                  (0)
#define RISC_ENABLE_force_spi_boot_mask                               (0x00000002)
#define RISC_ENABLE_avcpu_enrc_mask                                   (0x00000001)
#define RISC_ENABLE_force_spi_boot(data)                              (0x00000002&((data)<<1))
#define RISC_ENABLE_avcpu_enrc(data)                                  (0x00000001&(data))
#define RISC_ENABLE_get_force_spi_boot(data)                          ((0x00000002&(data))>>1)
#define RISC_ENABLE_get_avcpu_enrc(data)                              (0x00000001&(data))

#define MCPU_EXCEPTION_OFFSET                                         0x1800300c
#define MCPU_EXCEPTION_OFFSET_reg_addr                                "0xB800300C"
#define MCPU_EXCEPTION_OFFSET_reg                                     0xB800300C
#define MCPU_EXCEPTION_OFFSET_inst_addr                               "0x0003"
#define MCPU_EXCEPTION_OFFSET_inst                                    0x0003
#define MCPU_EXCEPTION_OFFSET_mcpu_exvoffset_shift                    (0)
#define MCPU_EXCEPTION_OFFSET_mcpu_exvoffset_mask                     (0x000000FF)
#define MCPU_EXCEPTION_OFFSET_mcpu_exvoffset(data)                    (0x000000FF&(data))
#define MCPU_EXCEPTION_OFFSET_get_mcpu_exvoffset(data)                (0x000000FF&(data))

#define AVCPU_EXCEPTION_OFFSET                                        0x18003010
#define AVCPU_EXCEPTION_OFFSET_reg_addr                               "0xB8003010"
#define AVCPU_EXCEPTION_OFFSET_reg                                    0xB8003010
#define AVCPU_EXCEPTION_OFFSET_inst_addr                              "0x0004"
#define AVCPU_EXCEPTION_OFFSET_inst                                   0x0004
#define AVCPU_EXCEPTION_OFFSET_avcpu_exvoffset_shift                  (0)
#define AVCPU_EXCEPTION_OFFSET_avcpu_exvoffset_mask                   (0x000000FF)
#define AVCPU_EXCEPTION_OFFSET_avcpu_exvoffset(data)                  (0x000000FF&(data))
#define AVCPU_EXCEPTION_OFFSET_get_avcpu_exvoffset(data)              (0x000000FF&(data))

#define RISC_AV_DMA_DMEM_ADDR                                         0x18003014
#define RISC_AV_DMA_DMEM_ADDR_reg_addr                                "0xB8003014"
#define RISC_AV_DMA_DMEM_ADDR_reg                                     0xB8003014
#define RISC_AV_DMA_DMEM_ADDR_inst_addr                               "0x0005"
#define RISC_AV_DMA_DMEM_ADDR_inst                                    0x0005
#define RISC_AV_DMA_DMEM_ADDR_avdma_dmem_addr_shift                   (2)
#define RISC_AV_DMA_DMEM_ADDR_avdma_dmem_addr_mask                    (0x00007FFC)
#define RISC_AV_DMA_DMEM_ADDR_avdma_dmem_addr(data)                   (0x00007FFC&((data)<<2))
#define RISC_AV_DMA_DMEM_ADDR_get_avdma_dmem_addr(data)               ((0x00007FFC&(data))>>2)

#define RISC_AV_DMA_DDR_ADDR                                          0x18003018
#define RISC_AV_DMA_DDR_ADDR_reg_addr                                 "0xB8003018"
#define RISC_AV_DMA_DDR_ADDR_reg                                      0xB8003018
#define RISC_AV_DMA_DDR_ADDR_inst_addr                                "0x0006"
#define RISC_AV_DMA_DDR_ADDR_inst                                     0x0006
#define RISC_AV_DMA_DDR_ADDR_avdma_ddr_addr_shift                     (2)
#define RISC_AV_DMA_DDR_ADDR_avdma_ddr_addr_mask                      (0x03FFFFFC)
#define RISC_AV_DMA_DDR_ADDR_avdma_ddr_addr(data)                     (0x03FFFFFC&((data)<<2))
#define RISC_AV_DMA_DDR_ADDR_get_avdma_ddr_addr(data)                 ((0x03FFFFFC&(data))>>2)

#define RISC_AV_DMA_CTRL                                              0x1800301c
#define RISC_AV_DMA_CTRL_reg_addr                                     "0xB800301C"
#define RISC_AV_DMA_CTRL_reg                                          0xB800301C
#define RISC_AV_DMA_CTRL_inst_addr                                    "0x0007"
#define RISC_AV_DMA_CTRL_inst                                         0x0007
#define RISC_AV_DMA_CTRL_avdma_ie_shift                               (19)
#define RISC_AV_DMA_CTRL_avdma_softrst_shift                          (18)
#define RISC_AV_DMA_CTRL_avdma_start_shift                            (17)
#define RISC_AV_DMA_CTRL_avdma_dir_shift                              (16)
#define RISC_AV_DMA_CTRL_avdma_size_shift                             (0)
#define RISC_AV_DMA_CTRL_avdma_ie_mask                                (0x00080000)
#define RISC_AV_DMA_CTRL_avdma_softrst_mask                           (0x00040000)
#define RISC_AV_DMA_CTRL_avdma_start_mask                             (0x00020000)
#define RISC_AV_DMA_CTRL_avdma_dir_mask                               (0x00010000)
#define RISC_AV_DMA_CTRL_avdma_size_mask                              (0x00003FFF)
#define RISC_AV_DMA_CTRL_avdma_ie(data)                               (0x00080000&((data)<<19))
#define RISC_AV_DMA_CTRL_avdma_softrst(data)                          (0x00040000&((data)<<18))
#define RISC_AV_DMA_CTRL_avdma_start(data)                            (0x00020000&((data)<<17))
#define RISC_AV_DMA_CTRL_avdma_dir(data)                              (0x00010000&((data)<<16))
#define RISC_AV_DMA_CTRL_avdma_size(data)                             (0x00003FFF&(data))
#define RISC_AV_DMA_CTRL_get_avdma_ie(data)                           ((0x00080000&(data))>>19)
#define RISC_AV_DMA_CTRL_get_avdma_softrst(data)                      ((0x00040000&(data))>>18)
#define RISC_AV_DMA_CTRL_get_avdma_start(data)                        ((0x00020000&(data))>>17)
#define RISC_AV_DMA_CTRL_get_avdma_dir(data)                          ((0x00010000&(data))>>16)
#define RISC_AV_DMA_CTRL_get_avdma_size(data)                         (0x00003FFF&(data))

#define RISC_AV_DMA_STATUS                                            0x18003020
#define RISC_AV_DMA_STATUS_reg_addr                                   "0xB8003020"
#define RISC_AV_DMA_STATUS_reg                                        0xB8003020
#define RISC_AV_DMA_STATUS_inst_addr                                  "0x0008"
#define RISC_AV_DMA_STATUS_inst                                       0x0008
#define RISC_AV_DMA_STATUS_avdma_ip_shift                             (0)
#define RISC_AV_DMA_STATUS_avdma_ip_mask                              (0x00000001)
#define RISC_AV_DMA_STATUS_avdma_ip(data)                             (0x00000001&(data))
#define RISC_AV_DMA_STATUS_get_avdma_ip(data)                         (0x00000001&(data))

#define M2M_DMA_DST                                                   0x18003024
#define M2M_DMA_DST_reg_addr                                          "0xB8003024"
#define M2M_DMA_DST_reg                                               0xB8003024
#define M2M_DMA_DST_inst_addr                                         "0x0009"
#define M2M_DMA_DST_inst                                              0x0009
#define M2M_DMA_DST_m2m_dst_shift                                     (2)
#define M2M_DMA_DST_m2m_dst_mask                                      (0x03FFFFFC)
#define M2M_DMA_DST_m2m_dst(data)                                     (0x03FFFFFC&((data)<<2))
#define M2M_DMA_DST_get_m2m_dst(data)                                 ((0x03FFFFFC&(data))>>2)

#define M2M_DMA_SRC                                                   0x18003028
#define M2M_DMA_SRC_reg_addr                                          "0xB8003028"
#define M2M_DMA_SRC_reg                                               0xB8003028
#define M2M_DMA_SRC_inst_addr                                         "0x000A"
#define M2M_DMA_SRC_inst                                              0x000A
#define M2M_DMA_SRC_m2m_src_shift                                     (2)
#define M2M_DMA_SRC_m2m_src_mask                                      (0x03FFFFFC)
#define M2M_DMA_SRC_m2m_src(data)                                     (0x03FFFFFC&((data)<<2))
#define M2M_DMA_SRC_get_m2m_src(data)                                 ((0x03FFFFFC&(data))>>2)

#define M2M_DMA_PATTERN                                               0x1800302c
#define M2M_DMA_PATTERN_reg_addr                                      "0xB800302C"
#define M2M_DMA_PATTERN_reg                                           0xB800302C
#define M2M_DMA_PATTERN_inst_addr                                     "0x000B"
#define M2M_DMA_PATTERN_inst                                          0x000B
#define M2M_DMA_PATTERN_m2m_pattern_shift                             (0)
#define M2M_DMA_PATTERN_m2m_pattern_mask                              (0xFFFFFFFF)
#define M2M_DMA_PATTERN_m2m_pattern(data)                             (0xFFFFFFFF&(data))
#define M2M_DMA_PATTERN_get_m2m_pattern(data)                         (0xFFFFFFFF&(data))

#define M2M_DMA_CTRL                                                  0x18003030
#define M2M_DMA_CTRL_reg_addr                                         "0xB8003030"
#define M2M_DMA_CTRL_reg                                              0xB8003030
#define M2M_DMA_CTRL_inst_addr                                        "0x000C"
#define M2M_DMA_CTRL_inst                                             0x000C
#define M2M_DMA_CTRL_m2m_ie_shift                                     (27)
#define M2M_DMA_CTRL_m2m_mode_shift                                   (26)
#define M2M_DMA_CTRL_m2m_start_shift                                  (24)
#define M2M_DMA_CTRL_m2m_size_shift                                   (2)
#define M2M_DMA_CTRL_m2m_ie_mask                                      (0x08000000)
#define M2M_DMA_CTRL_m2m_mode_mask                                    (0x04000000)
#define M2M_DMA_CTRL_m2m_start_mask                                   (0x01000000)
#define M2M_DMA_CTRL_m2m_size_mask                                    (0x00FFFFFC)
#define M2M_DMA_CTRL_m2m_ie(data)                                     (0x08000000&((data)<<27))
#define M2M_DMA_CTRL_m2m_mode(data)                                   (0x04000000&((data)<<26))
#define M2M_DMA_CTRL_m2m_start(data)                                  (0x01000000&((data)<<24))
#define M2M_DMA_CTRL_m2m_size(data)                                   (0x00FFFFFC&((data)<<2))
#define M2M_DMA_CTRL_get_m2m_ie(data)                                 ((0x08000000&(data))>>27)
#define M2M_DMA_CTRL_get_m2m_mode(data)                               ((0x04000000&(data))>>26)
#define M2M_DMA_CTRL_get_m2m_start(data)                              ((0x01000000&(data))>>24)
#define M2M_DMA_CTRL_get_m2m_size(data)                               ((0x00FFFFFC&(data))>>2)

#define M2M_DMA_STATUS                                                0x18003034
#define M2M_DMA_STATUS_reg_addr                                       "0xB8003034"
#define M2M_DMA_STATUS_reg                                            0xB8003034
#define M2M_DMA_STATUS_inst_addr                                      "0x000D"
#define M2M_DMA_STATUS_inst                                           0x000D
#define M2M_DMA_STATUS_m2m_busy_shift                                 (1)
#define M2M_DMA_STATUS_m2m_ip_shift                                   (0)
#define M2M_DMA_STATUS_m2m_busy_mask                                  (0x00000002)
#define M2M_DMA_STATUS_m2m_ip_mask                                    (0x00000001)
#define M2M_DMA_STATUS_m2m_busy(data)                                 (0x00000002&((data)<<1))
#define M2M_DMA_STATUS_m2m_ip(data)                                   (0x00000001&(data))
#define M2M_DMA_STATUS_get_m2m_busy(data)                             ((0x00000002&(data))>>1)
#define M2M_DMA_STATUS_get_m2m_ip(data)                               (0x00000001&(data))

#define ATOMIC_COUNTER                                                0x18003038
#define ATOMIC_COUNTER_reg_addr                                       "0xB8003038"
#define ATOMIC_COUNTER_reg                                            0xB8003038
#define ATOMIC_COUNTER_inst_addr                                      "0x000E"
#define ATOMIC_COUNTER_inst                                           0x000E
#define ATOMIC_COUNTER_atomic_debug_mode_shift                        (31)
#define ATOMIC_COUNTER_atomic_value_shift                             (0)
#define ATOMIC_COUNTER_atomic_debug_mode_mask                         (0x80000000)
#define ATOMIC_COUNTER_atomic_value_mask                              (0x000000FF)
#define ATOMIC_COUNTER_atomic_debug_mode(data)                        (0x80000000&((data)<<31))
#define ATOMIC_COUNTER_atomic_value(data)                             (0x000000FF&(data))
#define ATOMIC_COUNTER_get_atomic_debug_mode(data)                    ((0x80000000&(data))>>31)
#define ATOMIC_COUNTER_get_atomic_value(data)                         (0x000000FF&(data))

#define RISC_ROM_BIST_CMD                                             0x1800303c
#define RISC_ROM_BIST_CMD_reg_addr                                    "0xB800303C"
#define RISC_ROM_BIST_CMD_reg                                         0xB800303C
#define RISC_ROM_BIST_CMD_inst_addr                                   "0x000F"
#define RISC_ROM_BIST_CMD_inst                                        0x000F
#define RISC_ROM_BIST_CMD_rom_bist_mode_shift                         (2)
#define RISC_ROM_BIST_CMD_rom_bist_resetn_shift                       (1)
#define RISC_ROM_BIST_CMD_rom_bist_done_shift                         (0)
#define RISC_ROM_BIST_CMD_rom_bist_mode_mask                          (0x00000004)
#define RISC_ROM_BIST_CMD_rom_bist_resetn_mask                        (0x00000002)
#define RISC_ROM_BIST_CMD_rom_bist_done_mask                          (0x00000001)
#define RISC_ROM_BIST_CMD_rom_bist_mode(data)                         (0x00000004&((data)<<2))
#define RISC_ROM_BIST_CMD_rom_bist_resetn(data)                       (0x00000002&((data)<<1))
#define RISC_ROM_BIST_CMD_rom_bist_done(data)                         (0x00000001&(data))
#define RISC_ROM_BIST_CMD_get_rom_bist_mode(data)                     ((0x00000004&(data))>>2)
#define RISC_ROM_BIST_CMD_get_rom_bist_resetn(data)                   ((0x00000002&(data))>>1)
#define RISC_ROM_BIST_CMD_get_rom_bist_done(data)                     (0x00000001&(data))

#define RISC_ROM_BIST_CMP_DATA                                        0x18003040
#define RISC_ROM_BIST_CMP_DATA_reg_addr                               "0xB8003040"
#define RISC_ROM_BIST_CMP_DATA_reg                                    0xB8003040
#define RISC_ROM_BIST_CMP_DATA_inst_addr                              "0x0010"
#define RISC_ROM_BIST_CMP_DATA_inst                                   0x0010
#define RISC_ROM_BIST_CMP_DATA_rom_bist_cmp_data_shift                (0)
#define RISC_ROM_BIST_CMP_DATA_rom_bist_cmp_data_mask                 (0xFFFFFFFF)
#define RISC_ROM_BIST_CMP_DATA_rom_bist_cmp_data(data)                (0xFFFFFFFF&(data))
#define RISC_ROM_BIST_CMP_DATA_get_rom_bist_cmp_data(data)            (0xFFFFFFFF&(data))

#define MHEADER_MONITOR_CONTROL                                       0x18003044
#define MHEADER_MONITOR_CONTROL_reg_addr                              "0xB8003044"
#define MHEADER_MONITOR_CONTROL_reg                                   0xB8003044
#define MHEADER_MONITOR_CONTROL_inst_addr                             "0x0011"
#define MHEADER_MONITOR_CONTROL_inst                                  0x0011
#define MHEADER_MONITOR_CONTROL_dummy18003044_31_7_shift              (7)
#define MHEADER_MONITOR_CONTROL_mheader_bus_monitor_on_shift          (6)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_sel_rbus_shift        (4)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_burst_shift           (2)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_rw_shift              (0)
#define MHEADER_MONITOR_CONTROL_dummy18003044_31_7_mask               (0xFFFFFF80)
#define MHEADER_MONITOR_CONTROL_mheader_bus_monitor_on_mask           (0x00000040)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_sel_rbus_mask         (0x00000030)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_burst_mask            (0x0000000C)
#define MHEADER_MONITOR_CONTROL_mheader_monitor_rw_mask               (0x00000003)
#define MHEADER_MONITOR_CONTROL_dummy18003044_31_7(data)              (0xFFFFFF80&((data)<<7))
#define MHEADER_MONITOR_CONTROL_mheader_bus_monitor_on(data)          (0x00000040&((data)<<6))
#define MHEADER_MONITOR_CONTROL_mheader_monitor_sel_rbus(data)        (0x00000030&((data)<<4))
#define MHEADER_MONITOR_CONTROL_mheader_monitor_burst(data)           (0x0000000C&((data)<<2))
#define MHEADER_MONITOR_CONTROL_mheader_monitor_rw(data)              (0x00000003&(data))
#define MHEADER_MONITOR_CONTROL_get_dummy18003044_31_7(data)          ((0xFFFFFF80&(data))>>7)
#define MHEADER_MONITOR_CONTROL_get_mheader_bus_monitor_on(data)      ((0x00000040&(data))>>6)
#define MHEADER_MONITOR_CONTROL_get_mheader_monitor_sel_rbus(data)    ((0x00000030&(data))>>4)
#define MHEADER_MONITOR_CONTROL_get_mheader_monitor_burst(data)       ((0x0000000C&(data))>>2)
#define MHEADER_MONITOR_CONTROL_get_mheader_monitor_rw(data)          (0x00000003&(data))

#define MHEADER_MONITOR_STATUS_1                                      0x18003048
#define MHEADER_MONITOR_STATUS_1_reg_addr                             "0xB8003048"
#define MHEADER_MONITOR_STATUS_1_reg                                  0xB8003048
#define MHEADER_MONITOR_STATUS_1_inst_addr                            "0x0012"
#define MHEADER_MONITOR_STATUS_1_inst                                 0x0012
#define MHEADER_MONITOR_STATUS_1_mheader_monitor_req_shift            (0)
#define MHEADER_MONITOR_STATUS_1_mheader_monitor_req_mask             (0xFFFFFFFF)
#define MHEADER_MONITOR_STATUS_1_mheader_monitor_req(data)            (0xFFFFFFFF&(data))
#define MHEADER_MONITOR_STATUS_1_get_mheader_monitor_req(data)        (0xFFFFFFFF&(data))

#define AVHEADER_MONITOR_CONTROL                                      0x1800304c
#define AVHEADER_MONITOR_CONTROL_reg_addr                             "0xB800304C"
#define AVHEADER_MONITOR_CONTROL_reg                                  0xB800304C
#define AVHEADER_MONITOR_CONTROL_inst_addr                            "0x0013"
#define AVHEADER_MONITOR_CONTROL_inst                                 0x0013
#define AVHEADER_MONITOR_CONTROL_dummy1800304c_31_7_shift             (7)
#define AVHEADER_MONITOR_CONTROL_avheader_bus_monitor_on_shift        (6)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_sel_rbus_shift      (4)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_burst_shift         (2)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_rw_shift            (0)
#define AVHEADER_MONITOR_CONTROL_dummy1800304c_31_7_mask              (0xFFFFFF80)
#define AVHEADER_MONITOR_CONTROL_avheader_bus_monitor_on_mask         (0x00000040)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_sel_rbus_mask       (0x00000030)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_burst_mask          (0x0000000C)
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_rw_mask             (0x00000003)
#define AVHEADER_MONITOR_CONTROL_dummy1800304c_31_7(data)             (0xFFFFFF80&((data)<<7))
#define AVHEADER_MONITOR_CONTROL_avheader_bus_monitor_on(data)        (0x00000040&((data)<<6))
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_sel_rbus(data)      (0x00000030&((data)<<4))
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_burst(data)         (0x0000000C&((data)<<2))
#define AVHEADER_MONITOR_CONTROL_avheader_monitor_rw(data)            (0x00000003&(data))
#define AVHEADER_MONITOR_CONTROL_get_dummy1800304c_31_7(data)         ((0xFFFFFF80&(data))>>7)
#define AVHEADER_MONITOR_CONTROL_get_avheader_bus_monitor_on(data)    ((0x00000040&(data))>>6)
#define AVHEADER_MONITOR_CONTROL_get_avheader_monitor_sel_rbus(data)  ((0x00000030&(data))>>4)
#define AVHEADER_MONITOR_CONTROL_get_avheader_monitor_burst(data)     ((0x0000000C&(data))>>2)
#define AVHEADER_MONITOR_CONTROL_get_avheader_monitor_rw(data)        (0x00000003&(data))

#define AVHEADER_MONITOR_STATUS_1                                     0x18003050
#define AVHEADER_MONITOR_STATUS_1_reg_addr                            "0xB8003050"
#define AVHEADER_MONITOR_STATUS_1_reg                                 0xB8003050
#define AVHEADER_MONITOR_STATUS_1_inst_addr                           "0x0014"
#define AVHEADER_MONITOR_STATUS_1_inst                                0x0014
#define AVHEADER_MONITOR_STATUS_1_avheader_monitor_req_shift          (0)
#define AVHEADER_MONITOR_STATUS_1_avheader_monitor_req_mask           (0xFFFFFFFF)
#define AVHEADER_MONITOR_STATUS_1_avheader_monitor_req(data)          (0xFFFFFFFF&(data))
#define AVHEADER_MONITOR_STATUS_1_get_avheader_monitor_req(data)      (0xFFFFFFFF&(data))

#define MCPU_CPU_BIST                                                 0x18003054
#define MCPU_CPU_BIST_reg_addr                                        "0xB8003054"
#define MCPU_CPU_BIST_reg                                             0xB8003054
#define MCPU_CPU_BIST_inst_addr                                       "0x0015"
#define MCPU_CPU_BIST_inst                                            0x0015
#define MCPU_CPU_BIST_mcpu_bist_mode_shift                            (7)
#define MCPU_CPU_BIST_mcpu_bist_rstn_shift                            (6)
#define MCPU_CPU_BIST_mcpu_bist_done_shift                            (5)
#define MCPU_CPU_BIST_mcpu_bist_fail_shift                            (0)
#define MCPU_CPU_BIST_mcpu_bist_mode_mask                             (0x00000080)
#define MCPU_CPU_BIST_mcpu_bist_rstn_mask                             (0x00000040)
#define MCPU_CPU_BIST_mcpu_bist_done_mask                             (0x00000020)
#define MCPU_CPU_BIST_mcpu_bist_fail_mask                             (0x00000007)
#define MCPU_CPU_BIST_mcpu_bist_mode(data)                            (0x00000080&((data)<<7))
#define MCPU_CPU_BIST_mcpu_bist_rstn(data)                            (0x00000040&((data)<<6))
#define MCPU_CPU_BIST_mcpu_bist_done(data)                            (0x00000020&((data)<<5))
#define MCPU_CPU_BIST_mcpu_bist_fail(data)                            (0x00000007&(data))
#define MCPU_CPU_BIST_get_mcpu_bist_mode(data)                        ((0x00000080&(data))>>7)
#define MCPU_CPU_BIST_get_mcpu_bist_rstn(data)                        ((0x00000040&(data))>>6)
#define MCPU_CPU_BIST_get_mcpu_bist_done(data)                        ((0x00000020&(data))>>5)
#define MCPU_CPU_BIST_get_mcpu_bist_fail(data)                        (0x00000007&(data))

#define AVCPU_CPU_BIST                                                0x18003058
#define AVCPU_CPU_BIST_reg_addr                                       "0xB8003058"
#define AVCPU_CPU_BIST_reg                                            0xB8003058
#define AVCPU_CPU_BIST_inst_addr                                      "0x0016"
#define AVCPU_CPU_BIST_inst                                           0x0016
#define AVCPU_CPU_BIST_avcpu_bist_mode_shift                          (12)
#define AVCPU_CPU_BIST_avcpu_bist_rstn_shift                          (11)
#define AVCPU_CPU_BIST_avcpu_bist_done_shift                          (10)
#define AVCPU_CPU_BIST_avcpu_bist_fail_shift                          (2)
#define AVCPU_CPU_BIST_avcpu_bist_done_dma_shift                      (1)
#define AVCPU_CPU_BIST_avcpu_bist_fail_dma_shift                      (0)
#define AVCPU_CPU_BIST_avcpu_bist_mode_mask                           (0x00001000)
#define AVCPU_CPU_BIST_avcpu_bist_rstn_mask                           (0x00000800)
#define AVCPU_CPU_BIST_avcpu_bist_done_mask                           (0x00000400)
#define AVCPU_CPU_BIST_avcpu_bist_fail_mask                           (0x000003FC)
#define AVCPU_CPU_BIST_avcpu_bist_done_dma_mask                       (0x00000002)
#define AVCPU_CPU_BIST_avcpu_bist_fail_dma_mask                       (0x00000001)
#define AVCPU_CPU_BIST_avcpu_bist_mode(data)                          (0x00001000&((data)<<12))
#define AVCPU_CPU_BIST_avcpu_bist_rstn(data)                          (0x00000800&((data)<<11))
#define AVCPU_CPU_BIST_avcpu_bist_done(data)                          (0x00000400&((data)<<10))
#define AVCPU_CPU_BIST_avcpu_bist_fail(data)                          (0x000003FC&((data)<<2))
#define AVCPU_CPU_BIST_avcpu_bist_done_dma(data)                      (0x00000002&((data)<<1))
#define AVCPU_CPU_BIST_avcpu_bist_fail_dma(data)                      (0x00000001&(data))
#define AVCPU_CPU_BIST_get_avcpu_bist_mode(data)                      ((0x00001000&(data))>>12)
#define AVCPU_CPU_BIST_get_avcpu_bist_rstn(data)                      ((0x00000800&(data))>>11)
#define AVCPU_CPU_BIST_get_avcpu_bist_done(data)                      ((0x00000400&(data))>>10)
#define AVCPU_CPU_BIST_get_avcpu_bist_fail(data)                      ((0x000003FC&(data))>>2)
#define AVCPU_CPU_BIST_get_avcpu_bist_done_dma(data)                  ((0x00000002&(data))>>1)
#define AVCPU_CPU_BIST_get_avcpu_bist_fail_dma(data)                  (0x00000001&(data))

#define M2M_DMA_BIST                                                  0x1800305c
#define M2M_DMA_BIST_reg_addr                                         "0xB800305C"
#define M2M_DMA_BIST_reg                                              0xB800305C
#define M2M_DMA_BIST_inst_addr                                        "0x0017"
#define M2M_DMA_BIST_inst                                             0x0017
#define M2M_DMA_BIST_m2mdma_bist_mode_shift                           (3)
#define M2M_DMA_BIST_m2mdma_bist_rstn_shift                           (2)
#define M2M_DMA_BIST_m2mdma_bist_done_shift                           (1)
#define M2M_DMA_BIST_m2mdma_bist_fail_shift                           (0)
#define M2M_DMA_BIST_m2mdma_bist_mode_mask                            (0x00000008)
#define M2M_DMA_BIST_m2mdma_bist_rstn_mask                            (0x00000004)
#define M2M_DMA_BIST_m2mdma_bist_done_mask                            (0x00000002)
#define M2M_DMA_BIST_m2mdma_bist_fail_mask                            (0x00000001)
#define M2M_DMA_BIST_m2mdma_bist_mode(data)                           (0x00000008&((data)<<3))
#define M2M_DMA_BIST_m2mdma_bist_rstn(data)                           (0x00000004&((data)<<2))
#define M2M_DMA_BIST_m2mdma_bist_done(data)                           (0x00000002&((data)<<1))
#define M2M_DMA_BIST_m2mdma_bist_fail(data)                           (0x00000001&(data))
#define M2M_DMA_BIST_get_m2mdma_bist_mode(data)                       ((0x00000008&(data))>>3)
#define M2M_DMA_BIST_get_m2mdma_bist_rstn(data)                       ((0x00000004&(data))>>2)
#define M2M_DMA_BIST_get_m2mdma_bist_done(data)                       ((0x00000002&(data))>>1)
#define M2M_DMA_BIST_get_m2mdma_bist_fail(data)                       (0x00000001&(data))

#define AVCPU_BISTR_CONTROL                                           0x18003060
#define AVCPU_BISTR_CONTROL_reg_addr                                  "0xB8003060"
#define AVCPU_BISTR_CONTROL_reg                                       0xB8003060
#define AVCPU_BISTR_CONTROL_inst_addr                                 "0x0018"
#define AVCPU_BISTR_CONTROL_inst                                      0x0018
#define AVCPU_BISTR_CONTROL_avcpu_bisr_pwr_rst_shift                  (31)
#define AVCPU_BISTR_CONTROL_avcpu_hold_remap_shift                    (2)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_rst_shift                 (1)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_run_shift                 (0)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_pwr_rst_mask                   (0x80000000)
#define AVCPU_BISTR_CONTROL_avcpu_hold_remap_mask                     (0x00000004)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_rst_mask                  (0x00000002)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_run_mask                  (0x00000001)
#define AVCPU_BISTR_CONTROL_avcpu_bisr_pwr_rst(data)                  (0x80000000&((data)<<31))
#define AVCPU_BISTR_CONTROL_avcpu_hold_remap(data)                    (0x00000004&((data)<<2))
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_rst(data)                 (0x00000002&((data)<<1))
#define AVCPU_BISTR_CONTROL_avcpu_bisr_soft_run(data)                 (0x00000001&(data))
#define AVCPU_BISTR_CONTROL_get_avcpu_bisr_pwr_rst(data)              ((0x80000000&(data))>>31)
#define AVCPU_BISTR_CONTROL_get_avcpu_hold_remap(data)                ((0x00000004&(data))>>2)
#define AVCPU_BISTR_CONTROL_get_avcpu_bisr_soft_rst(data)             ((0x00000002&(data))>>1)
#define AVCPU_BISTR_CONTROL_get_avcpu_bisr_soft_run(data)             (0x00000001&(data))

#define AVCPU_BISTR_ICACHE1                                           0x18003064
#define AVCPU_BISTR_ICACHE1_reg_addr                                  "0xB8003064"
#define AVCPU_BISTR_ICACHE1_reg                                       0xB8003064
#define AVCPU_BISTR_ICACHE1_inst_addr                                 "0x0019"
#define AVCPU_BISTR_ICACHE1_inst                                      0x0019
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_1_shift                     (17)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_0_shift                     (8)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_4_shift                   (7)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_3_shift                   (6)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_2_shift                   (5)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_1_shift                   (4)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_0_shift                   (3)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_repaired_shift                 (1)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_done_shift                     (0)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_1_mask                      (0x0FFE0000)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_0_mask                      (0x0001FF00)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_4_mask                    (0x00000080)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_3_mask                    (0x00000040)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_2_mask                    (0x00000020)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_1_mask                    (0x00000010)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_0_mask                    (0x00000008)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_repaired_mask                  (0x00000002)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_done_mask                      (0x00000001)
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_1(data)                     (0x0FFE0000&((data)<<17))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_so_0(data)                     (0x0001FF00&((data)<<8))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_4(data)                   (0x00000080&((data)<<7))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_3(data)                   (0x00000040&((data)<<6))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_2(data)                   (0x00000020&((data)<<5))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_1(data)                   (0x00000010&((data)<<4))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_fail_0(data)                   (0x00000008&((data)<<3))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_repaired(data)                 (0x00000002&((data)<<1))
#define AVCPU_BISTR_ICACHE1_avcpu_bisr_done(data)                     (0x00000001&(data))
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_so_1(data)                 ((0x0FFE0000&(data))>>17)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_so_0(data)                 ((0x0001FF00&(data))>>8)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_fail_4(data)               ((0x00000080&(data))>>7)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_fail_3(data)               ((0x00000040&(data))>>6)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_fail_2(data)               ((0x00000020&(data))>>5)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_fail_1(data)               ((0x00000010&(data))>>4)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_fail_0(data)               ((0x00000008&(data))>>3)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_repaired(data)             ((0x00000002&(data))>>1)
#define AVCPU_BISTR_ICACHE1_get_avcpu_bisr_done(data)                 (0x00000001&(data))

#define AVCPU_BISTR_ICACHE2                                           0x18003068
#define AVCPU_BISTR_ICACHE2_reg_addr                                  "0xB8003068"
#define AVCPU_BISTR_ICACHE2_reg                                       0xB8003068
#define AVCPU_BISTR_ICACHE2_inst_addr                                 "0x001A"
#define AVCPU_BISTR_ICACHE2_inst                                      0x001A
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_4_shift                     (22)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_3_shift                     (12)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_2_shift                     (0)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_4_mask                      (0xFFC00000)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_3_mask                      (0x003FF000)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_2_mask                      (0x000007FF)
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_4(data)                     (0xFFC00000&((data)<<22))
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_3(data)                     (0x003FF000&((data)<<12))
#define AVCPU_BISTR_ICACHE2_avcpu_bisr_so_2(data)                     (0x000007FF&(data))
#define AVCPU_BISTR_ICACHE2_get_avcpu_bisr_so_4(data)                 ((0xFFC00000&(data))>>22)
#define AVCPU_BISTR_ICACHE2_get_avcpu_bisr_so_3(data)                 ((0x003FF000&(data))>>12)
#define AVCPU_BISTR_ICACHE2_get_avcpu_bisr_so_2(data)                 (0x000007FF&(data))

#define RBUS_ARBITER_CTRL1                                            0x18003100
#define RBUS_ARBITER_CTRL1_reg_addr                                   "0xB8003100"
#define RBUS_ARBITER_CTRL1_reg                                        0xB8003100
#define RBUS_ARBITER_CTRL1_inst_addr                                  "0x0040"
#define RBUS_ARBITER_CTRL1_inst                                       0x0040
#define RBUS_ARBITER_CTRL1_rbus_to_cyc_shift                          (16)
#define RBUS_ARBITER_CTRL1_dummy18003100_15_9_shift                   (9)
#define RBUS_ARBITER_CTRL1_rbus_mcpu_to_int_en_shift                  (8)
#define RBUS_ARBITER_CTRL1_rbus_ack_mask_clr_shift                    (1)
#define RBUS_ARBITER_CTRL1_rbus_softrst_shift                         (0)
#define RBUS_ARBITER_CTRL1_rbus_to_cyc_mask                           (0xFFFF0000)
#define RBUS_ARBITER_CTRL1_dummy18003100_15_9_mask                    (0x0000FE00)
#define RBUS_ARBITER_CTRL1_rbus_mcpu_to_int_en_mask                   (0x00000100)
#define RBUS_ARBITER_CTRL1_rbus_ack_mask_clr_mask                     (0x00000002)
#define RBUS_ARBITER_CTRL1_rbus_softrst_mask                          (0x00000001)
#define RBUS_ARBITER_CTRL1_rbus_to_cyc(data)                          (0xFFFF0000&((data)<<16))
#define RBUS_ARBITER_CTRL1_dummy18003100_15_9(data)                   (0x0000FE00&((data)<<9))
#define RBUS_ARBITER_CTRL1_rbus_mcpu_to_int_en(data)                  (0x00000100&((data)<<8))
#define RBUS_ARBITER_CTRL1_rbus_ack_mask_clr(data)                    (0x00000002&((data)<<1))
#define RBUS_ARBITER_CTRL1_rbus_softrst(data)                         (0x00000001&(data))
#define RBUS_ARBITER_CTRL1_get_rbus_to_cyc(data)                      ((0xFFFF0000&(data))>>16)
#define RBUS_ARBITER_CTRL1_get_dummy18003100_15_9(data)               ((0x0000FE00&(data))>>9)
#define RBUS_ARBITER_CTRL1_get_rbus_mcpu_to_int_en(data)              ((0x00000100&(data))>>8)
#define RBUS_ARBITER_CTRL1_get_rbus_ack_mask_clr(data)                ((0x00000002&(data))>>1)
#define RBUS_ARBITER_CTRL1_get_rbus_softrst(data)                     (0x00000001&(data))

#define RBUS_ARBITER_CTRL2                                            0x18003104
#define RBUS_ARBITER_CTRL2_reg_addr                                   "0xB8003104"
#define RBUS_ARBITER_CTRL2_reg                                        0xB8003104
#define RBUS_ARBITER_CTRL2_inst_addr                                  "0x0041"
#define RBUS_ARBITER_CTRL2_inst                                       0x0041
#define RBUS_ARBITER_CTRL2_rbus_ack_mask_st_shift                     (2)
#define RBUS_ARBITER_CTRL2_rbus_to_type_shift                         (1)
#define RBUS_ARBITER_CTRL2_rbus_mcpu_to_shift                         (0)
#define RBUS_ARBITER_CTRL2_rbus_ack_mask_st_mask                      (0xFFFFFFFC)
#define RBUS_ARBITER_CTRL2_rbus_to_type_mask                          (0x00000002)
#define RBUS_ARBITER_CTRL2_rbus_mcpu_to_mask                          (0x00000001)
#define RBUS_ARBITER_CTRL2_rbus_ack_mask_st(data)                     (0xFFFFFFFC&((data)<<2))
#define RBUS_ARBITER_CTRL2_rbus_to_type(data)                         (0x00000002&((data)<<1))
#define RBUS_ARBITER_CTRL2_rbus_mcpu_to(data)                         (0x00000001&(data))
#define RBUS_ARBITER_CTRL2_get_rbus_ack_mask_st(data)                 ((0xFFFFFFFC&(data))>>2)
#define RBUS_ARBITER_CTRL2_get_rbus_to_type(data)                     ((0x00000002&(data))>>1)
#define RBUS_ARBITER_CTRL2_get_rbus_mcpu_to(data)                     (0x00000001&(data))

#define RBUS_ARBITER_CTRL3                                            0x18003108
#define RBUS_ARBITER_CTRL3_reg_addr                                   "0xB8003108"
#define RBUS_ARBITER_CTRL3_reg                                        0xB8003108
#define RBUS_ARBITER_CTRL3_inst_addr                                  "0x0042"
#define RBUS_ARBITER_CTRL3_inst                                       0x0042
#define RBUS_ARBITER_CTRL3_rbus_last_addr_shift                       (0)
#define RBUS_ARBITER_CTRL3_rbus_last_addr_mask                        (0xFFFFFFFF)
#define RBUS_ARBITER_CTRL3_rbus_last_addr(data)                       (0xFFFFFFFF&(data))
#define RBUS_ARBITER_CTRL3_get_rbus_last_addr(data)                   (0xFFFFFFFF&(data))

#define RBUS_ARBITER_CTRL4                                            0x1800310c
#define RBUS_ARBITER_CTRL4_reg_addr                                   "0xB800310C"
#define RBUS_ARBITER_CTRL4_reg                                        0xB800310C
#define RBUS_ARBITER_CTRL4_inst_addr                                  "0x0043"
#define RBUS_ARBITER_CTRL4_inst                                       0x0043
#define RBUS_ARBITER_CTRL4_rbus_last_data_shift                       (0)
#define RBUS_ARBITER_CTRL4_rbus_last_data_mask                        (0xFFFFFFFF)
#define RBUS_ARBITER_CTRL4_rbus_last_data(data)                       (0xFFFFFFFF&(data))
#define RBUS_ARBITER_CTRL4_get_rbus_last_data(data)                   (0xFFFFFFFF&(data))

#define CRC_CMP_CTRL                                                  0x18003110
#define CRC_CMP_CTRL_reg_addr                                         "0xB8003110"
#define CRC_CMP_CTRL_reg                                              0xB8003110
#define CRC_CMP_CTRL_inst_addr                                        "0x0044"
#define CRC_CMP_CTRL_inst                                             0x0044
#define CRC_CMP_CTRL_crc_cmp_latch_en_shift                           (0)
#define CRC_CMP_CTRL_crc_cmp_latch_en_mask                            (0x00000001)
#define CRC_CMP_CTRL_crc_cmp_latch_en(data)                           (0x00000001&(data))
#define CRC_CMP_CTRL_get_crc_cmp_latch_en(data)                       (0x00000001&(data))

#define CRC_CMP_DATA                                                  0x18003114
#define CRC_CMP_DATA_reg_addr                                         "0xB8003114"
#define CRC_CMP_DATA_reg                                              0xB8003114
#define CRC_CMP_DATA_inst_addr                                        "0x0045"
#define CRC_CMP_DATA_inst                                             0x0045
#define CRC_CMP_DATA_crc_cmp_epv_shift                                (0)
#define CRC_CMP_DATA_crc_cmp_epv_mask                                 (0xFFFFFFFF)
#define CRC_CMP_DATA_crc_cmp_epv(data)                                (0xFFFFFFFF&(data))
#define CRC_CMP_DATA_get_crc_cmp_epv(data)                            (0xFFFFFFFF&(data))

#define CRC_CMP_RSLT                                                  0x18003118
#define CRC_CMP_RSLT_reg_addr                                         "0xB8003118"
#define CRC_CMP_RSLT_reg                                              0xB8003118
#define CRC_CMP_RSLT_inst_addr                                        "0x0046"
#define CRC_CMP_RSLT_inst                                             0x0046
#define CRC_CMP_RSLT_crc_cmp_rslt_shift                               (0)
#define CRC_CMP_RSLT_crc_cmp_rslt_mask                                (0xFFFFFFFF)
#define CRC_CMP_RSLT_crc_cmp_rslt(data)                               (0xFFFFFFFF&(data))
#define CRC_CMP_RSLT_get_crc_cmp_rslt(data)                           (0xFFFFFFFF&(data))

#define DC_PICT_SET                                                   0x18008000
#define DC_PICT_SET_reg_addr                                          "0xB8008000"
#define DC_PICT_SET_reg                                               0xB8008000
#define DC_PICT_SET_inst_addr                                         "0x0000"
#define DC_PICT_SET_inst                                              0x0000
#define DC_PICT_SET_pict_set_num_shift                                (18)
#define DC_PICT_SET_pict_width_scale_shift                            (13)
#define DC_PICT_SET_pict_init_page_shift                              (0)
#define DC_PICT_SET_pict_set_num_mask                                 (0x01FC0000)
#define DC_PICT_SET_pict_width_scale_mask                             (0x0003E000)
#define DC_PICT_SET_pict_init_page_mask                               (0x00001FFF)
#define DC_PICT_SET_pict_set_num(data)                                (0x01FC0000&((data)<<18))
#define DC_PICT_SET_pict_width_scale(data)                            (0x0003E000&((data)<<13))
#define DC_PICT_SET_pict_init_page(data)                              (0x00001FFF&(data))
#define DC_PICT_SET_get_pict_set_num(data)                            ((0x01FC0000&(data))>>18)
#define DC_PICT_SET_get_pict_width_scale(data)                        ((0x0003E000&(data))>>13)
#define DC_PICT_SET_get_pict_init_page(data)                          (0x00001FFF&(data))

#define DC_PICT_SET_OFFSET                                            0x18008034
#define DC_PICT_SET_OFFSET_reg_addr                                   "0xB8008034"
#define DC_PICT_SET_OFFSET_reg                                        0xB8008034
#define DC_PICT_SET_OFFSET_inst_addr                                  "0x000D"
#define DC_PICT_SET_OFFSET_inst                                       0x000D
#define DC_PICT_SET_OFFSET_pict_set_offset_y_shift                    (17)
#define DC_PICT_SET_OFFSET_pict_set_num_shift                         (10)
#define DC_PICT_SET_OFFSET_pict_set_offset_x_shift                    (0)
#define DC_PICT_SET_OFFSET_pict_set_offset_y_mask                     (0x07FE0000)
#define DC_PICT_SET_OFFSET_pict_set_num_mask                          (0x0001FC00)
#define DC_PICT_SET_OFFSET_pict_set_offset_x_mask                     (0x000003FF)
#define DC_PICT_SET_OFFSET_pict_set_offset_y(data)                    (0x07FE0000&((data)<<17))
#define DC_PICT_SET_OFFSET_pict_set_num(data)                         (0x0001FC00&((data)<<10))
#define DC_PICT_SET_OFFSET_pict_set_offset_x(data)                    (0x000003FF&(data))
#define DC_PICT_SET_OFFSET_get_pict_set_offset_y(data)                ((0x07FE0000&(data))>>17)
#define DC_PICT_SET_OFFSET_get_pict_set_num(data)                     ((0x0001FC00&(data))>>10)
#define DC_PICT_SET_OFFSET_get_pict_set_offset_x(data)                (0x000003FF&(data))

#define DC_SYS_MISC                                                   0x18008004
#define DC_SYS_MISC_reg_addr                                          "0xB8008004"
#define DC_SYS_MISC_reg                                               0xB8008004
#define DC_SYS_MISC_inst_addr                                         "0x0001"
#define DC_SYS_MISC_inst                                              0x0001
#define DC_SYS_MISC_ddr_phy_sel_shift                                 (19)
#define DC_SYS_MISC_pict_offset_en_shift                              (18)
#define DC_SYS_MISC_page_size_shift                                   (16)
#define DC_SYS_MISC_pre_arb_rd_cnt_shift                              (8)
#define DC_SYS_MISC_pre_arb_wr_cnt_shift                              (0)
#define DC_SYS_MISC_ddr_phy_sel_mask                                  (0x00080000)
#define DC_SYS_MISC_pict_offset_en_mask                               (0x00040000)
#define DC_SYS_MISC_page_size_mask                                    (0x00030000)
#define DC_SYS_MISC_pre_arb_rd_cnt_mask                               (0x0000FF00)
#define DC_SYS_MISC_pre_arb_wr_cnt_mask                               (0x000000FF)
#define DC_SYS_MISC_ddr_phy_sel(data)                                 (0x00080000&((data)<<19))
#define DC_SYS_MISC_pict_offset_en(data)                              (0x00040000&((data)<<18))
#define DC_SYS_MISC_page_size(data)                                   (0x00030000&((data)<<16))
#define DC_SYS_MISC_pre_arb_rd_cnt(data)                              (0x0000FF00&((data)<<8))
#define DC_SYS_MISC_pre_arb_wr_cnt(data)                              (0x000000FF&(data))
#define DC_SYS_MISC_get_ddr_phy_sel(data)                             ((0x00080000&(data))>>19)
#define DC_SYS_MISC_get_pict_offset_en(data)                          ((0x00040000&(data))>>18)
#define DC_SYS_MISC_get_page_size(data)                               ((0x00030000&(data))>>16)
#define DC_SYS_MISC_get_pre_arb_rd_cnt(data)                          ((0x0000FF00&(data))>>8)
#define DC_SYS_MISC_get_pre_arb_wr_cnt(data)                          (0x000000FF&(data))

#define DC_HI_PRIORITY_CTRL_0                                         0x18008008
#define DC_HI_PRIORITY_CTRL_0_reg_addr                                "0xB8008008"
#define DC_HI_PRIORITY_CTRL_0_reg                                     0xB8008008
#define DC_HI_PRIORITY_CTRL_0_inst_addr                               "0x0002"
#define DC_HI_PRIORITY_CTRL_0_inst                                    0x0002
#define DC_HI_PRIORITY_CTRL_0_sb1_pri_shift                           (16)
#define DC_HI_PRIORITY_CTRL_0_aio_pri_shift                           (12)
#define DC_HI_PRIORITY_CTRL_0_sb0_pri_shift                           (8)
#define DC_HI_PRIORITY_CTRL_0_sb3_pri_shift                           (0)
#define DC_HI_PRIORITY_CTRL_0_sb1_pri_mask                            (0x00070000)
#define DC_HI_PRIORITY_CTRL_0_aio_pri_mask                            (0x00007000)
#define DC_HI_PRIORITY_CTRL_0_sb0_pri_mask                            (0x00000700)
#define DC_HI_PRIORITY_CTRL_0_sb3_pri_mask                            (0x00000007)
#define DC_HI_PRIORITY_CTRL_0_sb1_pri(data)                           (0x00070000&((data)<<16))
#define DC_HI_PRIORITY_CTRL_0_aio_pri(data)                           (0x00007000&((data)<<12))
#define DC_HI_PRIORITY_CTRL_0_sb0_pri(data)                           (0x00000700&((data)<<8))
#define DC_HI_PRIORITY_CTRL_0_sb3_pri(data)                           (0x00000007&(data))
#define DC_HI_PRIORITY_CTRL_0_get_sb1_pri(data)                       ((0x00070000&(data))>>16)
#define DC_HI_PRIORITY_CTRL_0_get_aio_pri(data)                       ((0x00007000&(data))>>12)
#define DC_HI_PRIORITY_CTRL_0_get_sb0_pri(data)                       ((0x00000700&(data))>>8)
#define DC_HI_PRIORITY_CTRL_0_get_sb3_pri(data)                       (0x00000007&(data))

#define DC_LO_PRIORITY_CTRL_0                                         0x1800800c
#define DC_LO_PRIORITY_CTRL_0_reg_addr                                "0xB800800C"
#define DC_LO_PRIORITY_CTRL_0_reg                                     0xB800800C
#define DC_LO_PRIORITY_CTRL_0_inst_addr                               "0x0003"
#define DC_LO_PRIORITY_CTRL_0_inst                                    0x0003
#define DC_LO_PRIORITY_CTRL_0_rotdma_pri_shift                        (20)
#define DC_LO_PRIORITY_CTRL_0_dmbt_pri_shift                          (16)
#define DC_LO_PRIORITY_CTRL_0_l2d_pri_shift                           (12)
#define DC_LO_PRIORITY_CTRL_0_vbippr_pri_shift                        (8)
#define DC_LO_PRIORITY_CTRL_0_mcpu_pri_shift                          (4)
#define DC_LO_PRIORITY_CTRL_0_sb2_pri_shift                           (0)
#define DC_LO_PRIORITY_CTRL_0_rotdma_pri_mask                         (0x00F00000)
#define DC_LO_PRIORITY_CTRL_0_dmbt_pri_mask                           (0x000F0000)
#define DC_LO_PRIORITY_CTRL_0_l2d_pri_mask                            (0x0000F000)
#define DC_LO_PRIORITY_CTRL_0_vbippr_pri_mask                         (0x00000F00)
#define DC_LO_PRIORITY_CTRL_0_mcpu_pri_mask                           (0x000000F0)
#define DC_LO_PRIORITY_CTRL_0_sb2_pri_mask                            (0x0000000F)
#define DC_LO_PRIORITY_CTRL_0_rotdma_pri(data)                        (0x00F00000&((data)<<20))
#define DC_LO_PRIORITY_CTRL_0_dmbt_pri(data)                          (0x000F0000&((data)<<16))
#define DC_LO_PRIORITY_CTRL_0_l2d_pri(data)                           (0x0000F000&((data)<<12))
#define DC_LO_PRIORITY_CTRL_0_vbippr_pri(data)                        (0x00000F00&((data)<<8))
#define DC_LO_PRIORITY_CTRL_0_mcpu_pri(data)                          (0x000000F0&((data)<<4))
#define DC_LO_PRIORITY_CTRL_0_sb2_pri(data)                           (0x0000000F&(data))
#define DC_LO_PRIORITY_CTRL_0_get_rotdma_pri(data)                    ((0x00F00000&(data))>>20)
#define DC_LO_PRIORITY_CTRL_0_get_dmbt_pri(data)                      ((0x000F0000&(data))>>16)
#define DC_LO_PRIORITY_CTRL_0_get_l2d_pri(data)                       ((0x0000F000&(data))>>12)
#define DC_LO_PRIORITY_CTRL_0_get_vbippr_pri(data)                    ((0x00000F00&(data))>>8)
#define DC_LO_PRIORITY_CTRL_0_get_mcpu_pri(data)                      ((0x000000F0&(data))>>4)
#define DC_LO_PRIORITY_CTRL_0_get_sb2_pri(data)                       (0x0000000F&(data))

#define DC_LO_PRIORITY_CTRL_1                                         0x18008010
#define DC_LO_PRIORITY_CTRL_1_reg_addr                                "0xB8008010"
#define DC_LO_PRIORITY_CTRL_1_reg                                     0xB8008010
#define DC_LO_PRIORITY_CTRL_1_inst_addr                               "0x0004"
#define DC_LO_PRIORITY_CTRL_1_inst                                    0x0004
#define DC_LO_PRIORITY_CTRL_1_se_pri_shift                            (20)
#define DC_LO_PRIORITY_CTRL_1_meblk_pri_shift                         (16)
#define DC_LO_PRIORITY_CTRL_1_veblk_pri_shift                         (12)
#define DC_LO_PRIORITY_CTRL_1_l2d1_pri_shift                          (8)
#define DC_LO_PRIORITY_CTRL_1_meseq_pri_shift                         (4)
#define DC_LO_PRIORITY_CTRL_1_veseq_pri_shift                         (0)
#define DC_LO_PRIORITY_CTRL_1_se_pri_mask                             (0x00F00000)
#define DC_LO_PRIORITY_CTRL_1_meblk_pri_mask                          (0x000F0000)
#define DC_LO_PRIORITY_CTRL_1_veblk_pri_mask                          (0x0000F000)
#define DC_LO_PRIORITY_CTRL_1_l2d1_pri_mask                           (0x00000F00)
#define DC_LO_PRIORITY_CTRL_1_meseq_pri_mask                          (0x000000F0)
#define DC_LO_PRIORITY_CTRL_1_veseq_pri_mask                          (0x0000000F)
#define DC_LO_PRIORITY_CTRL_1_se_pri(data)                            (0x00F00000&((data)<<20))
#define DC_LO_PRIORITY_CTRL_1_meblk_pri(data)                         (0x000F0000&((data)<<16))
#define DC_LO_PRIORITY_CTRL_1_veblk_pri(data)                         (0x0000F000&((data)<<12))
#define DC_LO_PRIORITY_CTRL_1_l2d1_pri(data)                          (0x00000F00&((data)<<8))
#define DC_LO_PRIORITY_CTRL_1_meseq_pri(data)                         (0x000000F0&((data)<<4))
#define DC_LO_PRIORITY_CTRL_1_veseq_pri(data)                         (0x0000000F&(data))
#define DC_LO_PRIORITY_CTRL_1_get_se_pri(data)                        ((0x00F00000&(data))>>20)
#define DC_LO_PRIORITY_CTRL_1_get_meblk_pri(data)                     ((0x000F0000&(data))>>16)
#define DC_LO_PRIORITY_CTRL_1_get_veblk_pri(data)                     ((0x0000F000&(data))>>12)
#define DC_LO_PRIORITY_CTRL_1_get_l2d1_pri(data)                      ((0x00000F00&(data))>>8)
#define DC_LO_PRIORITY_CTRL_1_get_meseq_pri(data)                     ((0x000000F0&(data))>>4)
#define DC_LO_PRIORITY_CTRL_1_get_veseq_pri(data)                     (0x0000000F&(data))

#define DC_REQ_STATUS_CHK                                             0x18008038
#define DC_REQ_STATUS_CHK_reg_addr                                    "0xB8008038"
#define DC_REQ_STATUS_CHK_reg                                         0xB8008038
#define DC_REQ_STATUS_CHK_inst_addr                                   "0x000E"
#define DC_REQ_STATUS_CHK_inst                                        0x000E
#define DC_REQ_STATUS_CHK_req_pending_shift                           (16)
#define DC_REQ_STATUS_CHK_req_id_shift                                (0)
#define DC_REQ_STATUS_CHK_req_pending_mask                            (0x00010000)
#define DC_REQ_STATUS_CHK_req_id_mask                                 (0x00007FFF)
#define DC_REQ_STATUS_CHK_req_pending(data)                           (0x00010000&((data)<<16))
#define DC_REQ_STATUS_CHK_req_id(data)                                (0x00007FFF&(data))
#define DC_REQ_STATUS_CHK_get_req_pending(data)                       ((0x00010000&(data))>>16)
#define DC_REQ_STATUS_CHK_get_req_id(data)                            (0x00007FFF&(data))

#define DC_PC_CTRL                                                    0x18008040
#define DC_PC_CTRL_reg_addr                                           "0xB8008040"
#define DC_PC_CTRL_reg                                                0xB8008040
#define DC_PC_CTRL_inst_addr                                          "0x0010"
#define DC_PC_CTRL_inst                                               0x0010
#define DC_PC_CTRL_pc_go_shift                                        (8)
#define DC_PC_CTRL_pc_go_mask                                         (0x00000100)
#define DC_PC_CTRL_pc_go(data)                                        (0x00000100&((data)<<8))
#define DC_PC_CTRL_get_pc_go(data)                                    ((0x00000100&(data))>>8)

#define DC_PC_TOTAL_CYCL                                              0x18008044
#define DC_PC_TOTAL_CYCL_reg_addr                                     "0xB8008044"
#define DC_PC_TOTAL_CYCL_reg                                          0xB8008044
#define DC_PC_TOTAL_CYCL_inst_addr                                    "0x0011"
#define DC_PC_TOTAL_CYCL_inst                                         0x0011
#define DC_PC_TOTAL_CYCL_pc_total_cycl_shift                          (0)
#define DC_PC_TOTAL_CYCL_pc_total_cycl_mask                           (0xFFFFFFFF)
#define DC_PC_TOTAL_CYCL_pc_total_cycl(data)                          (0xFFFFFFFF&(data))
#define DC_PC_TOTAL_CYCL_get_pc_total_cycl(data)                      (0xFFFFFFFF&(data))

#define DC_PC_DBUS_IDLE                                               0x18008048
#define DC_PC_DBUS_IDLE_reg_addr                                      "0xB8008048"
#define DC_PC_DBUS_IDLE_reg                                           0xB8008048
#define DC_PC_DBUS_IDLE_inst_addr                                     "0x0012"
#define DC_PC_DBUS_IDLE_inst                                          0x0012
#define DC_PC_DBUS_IDLE_pc_dbus_idle_shift                            (0)
#define DC_PC_DBUS_IDLE_pc_dbus_idle_mask                             (0xFFFFFFFF)
#define DC_PC_DBUS_IDLE_pc_dbus_idle(data)                            (0xFFFFFFFF&(data))
#define DC_PC_DBUS_IDLE_get_pc_dbus_idle(data)                        (0xFFFFFFFF&(data))

#define DC_PC_DBUS_ACK                                                0x1800804c
#define DC_PC_DBUS_ACK_reg_addr                                       "0xB800804C"
#define DC_PC_DBUS_ACK_reg                                            0xB800804C
#define DC_PC_DBUS_ACK_inst_addr                                      "0x0013"
#define DC_PC_DBUS_ACK_inst                                           0x0013
#define DC_PC_DBUS_ACK_pc_dbus_ack_num_shift                          (0)
#define DC_PC_DBUS_ACK_pc_dbus_ack_num_mask                           (0xFFFFFFFF)
#define DC_PC_DBUS_ACK_pc_dbus_ack_num(data)                          (0xFFFFFFFF&(data))
#define DC_PC_DBUS_ACK_get_pc_dbus_ack_num(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_0                                               0x18008050
#define DC_PC_SET_ACC_0_reg_addr                                      "0xB8008050"
#define DC_PC_SET_ACC_0_reg                                           0xB8008050
#define DC_PC_SET_ACC_0_inst_addr                                     "0x0014"
#define DC_PC_SET_ACC_0_inst                                          0x0014
#define DC_PC_SET_ACC_0_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_0_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_0_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_0_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_1                                               0x18008060
#define DC_PC_SET_ACC_1_reg_addr                                      "0xB8008060"
#define DC_PC_SET_ACC_1_reg                                           0xB8008060
#define DC_PC_SET_ACC_1_inst_addr                                     "0x0018"
#define DC_PC_SET_ACC_1_inst                                          0x0018
#define DC_PC_SET_ACC_1_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_1_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_1_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_1_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_2                                               0x18008070
#define DC_PC_SET_ACC_2_reg_addr                                      "0xB8008070"
#define DC_PC_SET_ACC_2_reg                                           0xB8008070
#define DC_PC_SET_ACC_2_inst_addr                                     "0x001C"
#define DC_PC_SET_ACC_2_inst                                          0x001C
#define DC_PC_SET_ACC_2_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_2_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_2_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_2_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_3                                               0x18008080
#define DC_PC_SET_ACC_3_reg_addr                                      "0xB8008080"
#define DC_PC_SET_ACC_3_reg                                           0xB8008080
#define DC_PC_SET_ACC_3_inst_addr                                     "0x0020"
#define DC_PC_SET_ACC_3_inst                                          0x0020
#define DC_PC_SET_ACC_3_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_3_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_3_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_3_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_4                                               0x18008090
#define DC_PC_SET_ACC_4_reg_addr                                      "0xB8008090"
#define DC_PC_SET_ACC_4_reg                                           0xB8008090
#define DC_PC_SET_ACC_4_inst_addr                                     "0x0024"
#define DC_PC_SET_ACC_4_inst                                          0x0024
#define DC_PC_SET_ACC_4_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_4_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_4_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_4_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_5                                               0x180080a0
#define DC_PC_SET_ACC_5_reg_addr                                      "0xB80080A0"
#define DC_PC_SET_ACC_5_reg                                           0xB80080A0
#define DC_PC_SET_ACC_5_inst_addr                                     "0x0028"
#define DC_PC_SET_ACC_5_inst                                          0x0028
#define DC_PC_SET_ACC_5_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_5_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_5_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_5_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_6                                               0x180080b0
#define DC_PC_SET_ACC_6_reg_addr                                      "0xB80080B0"
#define DC_PC_SET_ACC_6_reg                                           0xB80080B0
#define DC_PC_SET_ACC_6_inst_addr                                     "0x002C"
#define DC_PC_SET_ACC_6_inst                                          0x002C
#define DC_PC_SET_ACC_6_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_6_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_6_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_6_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_7                                               0x180080c0
#define DC_PC_SET_ACC_7_reg_addr                                      "0xB80080C0"
#define DC_PC_SET_ACC_7_reg                                           0xB80080C0
#define DC_PC_SET_ACC_7_inst_addr                                     "0x0030"
#define DC_PC_SET_ACC_7_inst                                          0x0030
#define DC_PC_SET_ACC_7_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_7_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_7_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_7_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_8                                               0x180080d0
#define DC_PC_SET_ACC_8_reg_addr                                      "0xB80080D0"
#define DC_PC_SET_ACC_8_reg                                           0xB80080D0
#define DC_PC_SET_ACC_8_inst_addr                                     "0x0034"
#define DC_PC_SET_ACC_8_inst                                          0x0034
#define DC_PC_SET_ACC_8_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_8_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_8_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_8_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_9                                               0x180080e0
#define DC_PC_SET_ACC_9_reg_addr                                      "0xB80080E0"
#define DC_PC_SET_ACC_9_reg                                           0xB80080E0
#define DC_PC_SET_ACC_9_inst_addr                                     "0x0038"
#define DC_PC_SET_ACC_9_inst                                          0x0038
#define DC_PC_SET_ACC_9_pc_acc_latency_shift                          (0)
#define DC_PC_SET_ACC_9_pc_acc_latency_mask                           (0xFFFFFFFF)
#define DC_PC_SET_ACC_9_pc_acc_latency(data)                          (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_9_get_pc_acc_latency(data)                      (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_10                                              0x180080f0
#define DC_PC_SET_ACC_10_reg_addr                                     "0xB80080F0"
#define DC_PC_SET_ACC_10_reg                                          0xB80080F0
#define DC_PC_SET_ACC_10_inst_addr                                    "0x003C"
#define DC_PC_SET_ACC_10_inst                                         0x003C
#define DC_PC_SET_ACC_10_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_10_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_10_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_10_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_11                                              0x18008100
#define DC_PC_SET_ACC_11_reg_addr                                     "0xB8008100"
#define DC_PC_SET_ACC_11_reg                                          0xB8008100
#define DC_PC_SET_ACC_11_inst_addr                                    "0x0040"
#define DC_PC_SET_ACC_11_inst                                         0x0040
#define DC_PC_SET_ACC_11_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_11_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_11_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_11_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_12                                              0x18008110
#define DC_PC_SET_ACC_12_reg_addr                                     "0xB8008110"
#define DC_PC_SET_ACC_12_reg                                          0xB8008110
#define DC_PC_SET_ACC_12_inst_addr                                    "0x0044"
#define DC_PC_SET_ACC_12_inst                                         0x0044
#define DC_PC_SET_ACC_12_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_12_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_12_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_12_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_13                                              0x18008120
#define DC_PC_SET_ACC_13_reg_addr                                     "0xB8008120"
#define DC_PC_SET_ACC_13_reg                                          0xB8008120
#define DC_PC_SET_ACC_13_inst_addr                                    "0x0048"
#define DC_PC_SET_ACC_13_inst                                         0x0048
#define DC_PC_SET_ACC_13_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_13_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_13_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_13_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_14                                              0x18008130
#define DC_PC_SET_ACC_14_reg_addr                                     "0xB8008130"
#define DC_PC_SET_ACC_14_reg                                          0xB8008130
#define DC_PC_SET_ACC_14_inst_addr                                    "0x004C"
#define DC_PC_SET_ACC_14_inst                                         0x004C
#define DC_PC_SET_ACC_14_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_14_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_14_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_14_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_15                                              0x18008140
#define DC_PC_SET_ACC_15_reg_addr                                     "0xB8008140"
#define DC_PC_SET_ACC_15_reg                                          0xB8008140
#define DC_PC_SET_ACC_15_inst_addr                                    "0x0050"
#define DC_PC_SET_ACC_15_inst                                         0x0050
#define DC_PC_SET_ACC_15_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_15_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_15_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_15_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_ACC_16                                              0x18008150
#define DC_PC_SET_ACC_16_reg_addr                                     "0xB8008150"
#define DC_PC_SET_ACC_16_reg                                          0xB8008150
#define DC_PC_SET_ACC_16_inst_addr                                    "0x0054"
#define DC_PC_SET_ACC_16_inst                                         0x0054
#define DC_PC_SET_ACC_16_pc_acc_latency_shift                         (0)
#define DC_PC_SET_ACC_16_pc_acc_latency_mask                          (0xFFFFFFFF)
#define DC_PC_SET_ACC_16_pc_acc_latency(data)                         (0xFFFFFFFF&(data))
#define DC_PC_SET_ACC_16_get_pc_acc_latency(data)                     (0xFFFFFFFF&(data))

#define DC_PC_SET_MAX_REQ_0                                           0x18008054
#define DC_PC_SET_MAX_REQ_0_reg_addr                                  "0xB8008054"
#define DC_PC_SET_MAX_REQ_0_reg                                       0xB8008054
#define DC_PC_SET_MAX_REQ_0_inst_addr                                 "0x0015"
#define DC_PC_SET_MAX_REQ_0_inst                                      0x0015
#define DC_PC_SET_MAX_REQ_0_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_0_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_0_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_0_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_1                                           0x18008064
#define DC_PC_SET_MAX_REQ_1_reg_addr                                  "0xB8008064"
#define DC_PC_SET_MAX_REQ_1_reg                                       0xB8008064
#define DC_PC_SET_MAX_REQ_1_inst_addr                                 "0x0019"
#define DC_PC_SET_MAX_REQ_1_inst                                      0x0019
#define DC_PC_SET_MAX_REQ_1_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_1_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_1_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_1_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_2                                           0x18008074
#define DC_PC_SET_MAX_REQ_2_reg_addr                                  "0xB8008074"
#define DC_PC_SET_MAX_REQ_2_reg                                       0xB8008074
#define DC_PC_SET_MAX_REQ_2_inst_addr                                 "0x001D"
#define DC_PC_SET_MAX_REQ_2_inst                                      0x001D
#define DC_PC_SET_MAX_REQ_2_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_2_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_2_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_2_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_3                                           0x18008084
#define DC_PC_SET_MAX_REQ_3_reg_addr                                  "0xB8008084"
#define DC_PC_SET_MAX_REQ_3_reg                                       0xB8008084
#define DC_PC_SET_MAX_REQ_3_inst_addr                                 "0x0021"
#define DC_PC_SET_MAX_REQ_3_inst                                      0x0021
#define DC_PC_SET_MAX_REQ_3_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_3_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_3_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_3_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_4                                           0x18008094
#define DC_PC_SET_MAX_REQ_4_reg_addr                                  "0xB8008094"
#define DC_PC_SET_MAX_REQ_4_reg                                       0xB8008094
#define DC_PC_SET_MAX_REQ_4_inst_addr                                 "0x0025"
#define DC_PC_SET_MAX_REQ_4_inst                                      0x0025
#define DC_PC_SET_MAX_REQ_4_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_4_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_4_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_4_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_5                                           0x180080a4
#define DC_PC_SET_MAX_REQ_5_reg_addr                                  "0xB80080A4"
#define DC_PC_SET_MAX_REQ_5_reg                                       0xB80080A4
#define DC_PC_SET_MAX_REQ_5_inst_addr                                 "0x0029"
#define DC_PC_SET_MAX_REQ_5_inst                                      0x0029
#define DC_PC_SET_MAX_REQ_5_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_5_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_5_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_5_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_6                                           0x180080b4
#define DC_PC_SET_MAX_REQ_6_reg_addr                                  "0xB80080B4"
#define DC_PC_SET_MAX_REQ_6_reg                                       0xB80080B4
#define DC_PC_SET_MAX_REQ_6_inst_addr                                 "0x002D"
#define DC_PC_SET_MAX_REQ_6_inst                                      0x002D
#define DC_PC_SET_MAX_REQ_6_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_6_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_6_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_6_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_7                                           0x180080c4
#define DC_PC_SET_MAX_REQ_7_reg_addr                                  "0xB80080C4"
#define DC_PC_SET_MAX_REQ_7_reg                                       0xB80080C4
#define DC_PC_SET_MAX_REQ_7_inst_addr                                 "0x0031"
#define DC_PC_SET_MAX_REQ_7_inst                                      0x0031
#define DC_PC_SET_MAX_REQ_7_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_7_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_7_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_7_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_8                                           0x180080d4
#define DC_PC_SET_MAX_REQ_8_reg_addr                                  "0xB80080D4"
#define DC_PC_SET_MAX_REQ_8_reg                                       0xB80080D4
#define DC_PC_SET_MAX_REQ_8_inst_addr                                 "0x0035"
#define DC_PC_SET_MAX_REQ_8_inst                                      0x0035
#define DC_PC_SET_MAX_REQ_8_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_8_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_8_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_8_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_9                                           0x180080e4
#define DC_PC_SET_MAX_REQ_9_reg_addr                                  "0xB80080E4"
#define DC_PC_SET_MAX_REQ_9_reg                                       0xB80080E4
#define DC_PC_SET_MAX_REQ_9_inst_addr                                 "0x0039"
#define DC_PC_SET_MAX_REQ_9_inst                                      0x0039
#define DC_PC_SET_MAX_REQ_9_pc_max_latency_shift                      (0)
#define DC_PC_SET_MAX_REQ_9_pc_max_latency_mask                       (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_9_pc_max_latency(data)                      (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_9_get_pc_max_latency(data)                  (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_10                                          0x180080f4
#define DC_PC_SET_MAX_REQ_10_reg_addr                                 "0xB80080F4"
#define DC_PC_SET_MAX_REQ_10_reg                                      0xB80080F4
#define DC_PC_SET_MAX_REQ_10_inst_addr                                "0x003D"
#define DC_PC_SET_MAX_REQ_10_inst                                     0x003D
#define DC_PC_SET_MAX_REQ_10_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_10_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_10_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_10_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_11                                          0x18008104
#define DC_PC_SET_MAX_REQ_11_reg_addr                                 "0xB8008104"
#define DC_PC_SET_MAX_REQ_11_reg                                      0xB8008104
#define DC_PC_SET_MAX_REQ_11_inst_addr                                "0x0041"
#define DC_PC_SET_MAX_REQ_11_inst                                     0x0041
#define DC_PC_SET_MAX_REQ_11_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_11_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_11_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_11_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_12                                          0x18008114
#define DC_PC_SET_MAX_REQ_12_reg_addr                                 "0xB8008114"
#define DC_PC_SET_MAX_REQ_12_reg                                      0xB8008114
#define DC_PC_SET_MAX_REQ_12_inst_addr                                "0x0045"
#define DC_PC_SET_MAX_REQ_12_inst                                     0x0045
#define DC_PC_SET_MAX_REQ_12_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_12_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_12_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_12_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_13                                          0x18008124
#define DC_PC_SET_MAX_REQ_13_reg_addr                                 "0xB8008124"
#define DC_PC_SET_MAX_REQ_13_reg                                      0xB8008124
#define DC_PC_SET_MAX_REQ_13_inst_addr                                "0x0049"
#define DC_PC_SET_MAX_REQ_13_inst                                     0x0049
#define DC_PC_SET_MAX_REQ_13_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_13_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_13_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_13_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_14                                          0x18008134
#define DC_PC_SET_MAX_REQ_14_reg_addr                                 "0xB8008134"
#define DC_PC_SET_MAX_REQ_14_reg                                      0xB8008134
#define DC_PC_SET_MAX_REQ_14_inst_addr                                "0x004D"
#define DC_PC_SET_MAX_REQ_14_inst                                     0x004D
#define DC_PC_SET_MAX_REQ_14_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_14_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_14_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_14_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_15                                          0x18008144
#define DC_PC_SET_MAX_REQ_15_reg_addr                                 "0xB8008144"
#define DC_PC_SET_MAX_REQ_15_reg                                      0xB8008144
#define DC_PC_SET_MAX_REQ_15_inst_addr                                "0x0051"
#define DC_PC_SET_MAX_REQ_15_inst                                     0x0051
#define DC_PC_SET_MAX_REQ_15_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_15_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_15_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_15_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_MAX_REQ_16                                          0x18008154
#define DC_PC_SET_MAX_REQ_16_reg_addr                                 "0xB8008154"
#define DC_PC_SET_MAX_REQ_16_reg                                      0xB8008154
#define DC_PC_SET_MAX_REQ_16_inst_addr                                "0x0055"
#define DC_PC_SET_MAX_REQ_16_inst                                     0x0055
#define DC_PC_SET_MAX_REQ_16_pc_max_latency_shift                     (0)
#define DC_PC_SET_MAX_REQ_16_pc_max_latency_mask                      (0x0000FFFF)
#define DC_PC_SET_MAX_REQ_16_pc_max_latency(data)                     (0x0000FFFF&(data))
#define DC_PC_SET_MAX_REQ_16_get_pc_max_latency(data)                 (0x0000FFFF&(data))

#define DC_PC_SET_REQ_NUM_0                                           0x18008058
#define DC_PC_SET_REQ_NUM_0_reg_addr                                  "0xB8008058"
#define DC_PC_SET_REQ_NUM_0_reg                                       0xB8008058
#define DC_PC_SET_REQ_NUM_0_inst_addr                                 "0x0016"
#define DC_PC_SET_REQ_NUM_0_inst                                      0x0016
#define DC_PC_SET_REQ_NUM_0_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_0_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_0_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_0_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_1                                           0x18008068
#define DC_PC_SET_REQ_NUM_1_reg_addr                                  "0xB8008068"
#define DC_PC_SET_REQ_NUM_1_reg                                       0xB8008068
#define DC_PC_SET_REQ_NUM_1_inst_addr                                 "0x001A"
#define DC_PC_SET_REQ_NUM_1_inst                                      0x001A
#define DC_PC_SET_REQ_NUM_1_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_1_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_1_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_1_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_2                                           0x18008078
#define DC_PC_SET_REQ_NUM_2_reg_addr                                  "0xB8008078"
#define DC_PC_SET_REQ_NUM_2_reg                                       0xB8008078
#define DC_PC_SET_REQ_NUM_2_inst_addr                                 "0x001E"
#define DC_PC_SET_REQ_NUM_2_inst                                      0x001E
#define DC_PC_SET_REQ_NUM_2_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_2_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_2_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_2_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_3                                           0x18008088
#define DC_PC_SET_REQ_NUM_3_reg_addr                                  "0xB8008088"
#define DC_PC_SET_REQ_NUM_3_reg                                       0xB8008088
#define DC_PC_SET_REQ_NUM_3_inst_addr                                 "0x0022"
#define DC_PC_SET_REQ_NUM_3_inst                                      0x0022
#define DC_PC_SET_REQ_NUM_3_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_3_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_3_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_3_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_4                                           0x18008098
#define DC_PC_SET_REQ_NUM_4_reg_addr                                  "0xB8008098"
#define DC_PC_SET_REQ_NUM_4_reg                                       0xB8008098
#define DC_PC_SET_REQ_NUM_4_inst_addr                                 "0x0026"
#define DC_PC_SET_REQ_NUM_4_inst                                      0x0026
#define DC_PC_SET_REQ_NUM_4_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_4_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_4_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_4_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_5                                           0x180080a8
#define DC_PC_SET_REQ_NUM_5_reg_addr                                  "0xB80080A8"
#define DC_PC_SET_REQ_NUM_5_reg                                       0xB80080A8
#define DC_PC_SET_REQ_NUM_5_inst_addr                                 "0x002A"
#define DC_PC_SET_REQ_NUM_5_inst                                      0x002A
#define DC_PC_SET_REQ_NUM_5_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_5_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_5_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_5_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_6                                           0x180080b8
#define DC_PC_SET_REQ_NUM_6_reg_addr                                  "0xB80080B8"
#define DC_PC_SET_REQ_NUM_6_reg                                       0xB80080B8
#define DC_PC_SET_REQ_NUM_6_inst_addr                                 "0x002E"
#define DC_PC_SET_REQ_NUM_6_inst                                      0x002E
#define DC_PC_SET_REQ_NUM_6_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_6_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_6_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_6_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_7                                           0x180080c8
#define DC_PC_SET_REQ_NUM_7_reg_addr                                  "0xB80080C8"
#define DC_PC_SET_REQ_NUM_7_reg                                       0xB80080C8
#define DC_PC_SET_REQ_NUM_7_inst_addr                                 "0x0032"
#define DC_PC_SET_REQ_NUM_7_inst                                      0x0032
#define DC_PC_SET_REQ_NUM_7_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_7_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_7_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_7_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_8                                           0x180080d8
#define DC_PC_SET_REQ_NUM_8_reg_addr                                  "0xB80080D8"
#define DC_PC_SET_REQ_NUM_8_reg                                       0xB80080D8
#define DC_PC_SET_REQ_NUM_8_inst_addr                                 "0x0036"
#define DC_PC_SET_REQ_NUM_8_inst                                      0x0036
#define DC_PC_SET_REQ_NUM_8_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_8_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_8_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_8_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_9                                           0x180080e8
#define DC_PC_SET_REQ_NUM_9_reg_addr                                  "0xB80080E8"
#define DC_PC_SET_REQ_NUM_9_reg                                       0xB80080E8
#define DC_PC_SET_REQ_NUM_9_inst_addr                                 "0x003A"
#define DC_PC_SET_REQ_NUM_9_inst                                      0x003A
#define DC_PC_SET_REQ_NUM_9_pc_req_number_shift                       (0)
#define DC_PC_SET_REQ_NUM_9_pc_req_number_mask                        (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_9_pc_req_number(data)                       (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_9_get_pc_req_number(data)                   (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_10                                          0x180080f8
#define DC_PC_SET_REQ_NUM_10_reg_addr                                 "0xB80080F8"
#define DC_PC_SET_REQ_NUM_10_reg                                      0xB80080F8
#define DC_PC_SET_REQ_NUM_10_inst_addr                                "0x003E"
#define DC_PC_SET_REQ_NUM_10_inst                                     0x003E
#define DC_PC_SET_REQ_NUM_10_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_10_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_10_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_10_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_11                                          0x18008108
#define DC_PC_SET_REQ_NUM_11_reg_addr                                 "0xB8008108"
#define DC_PC_SET_REQ_NUM_11_reg                                      0xB8008108
#define DC_PC_SET_REQ_NUM_11_inst_addr                                "0x0042"
#define DC_PC_SET_REQ_NUM_11_inst                                     0x0042
#define DC_PC_SET_REQ_NUM_11_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_11_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_11_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_11_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_12                                          0x18008118
#define DC_PC_SET_REQ_NUM_12_reg_addr                                 "0xB8008118"
#define DC_PC_SET_REQ_NUM_12_reg                                      0xB8008118
#define DC_PC_SET_REQ_NUM_12_inst_addr                                "0x0046"
#define DC_PC_SET_REQ_NUM_12_inst                                     0x0046
#define DC_PC_SET_REQ_NUM_12_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_12_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_12_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_12_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_13                                          0x18008128
#define DC_PC_SET_REQ_NUM_13_reg_addr                                 "0xB8008128"
#define DC_PC_SET_REQ_NUM_13_reg                                      0xB8008128
#define DC_PC_SET_REQ_NUM_13_inst_addr                                "0x004A"
#define DC_PC_SET_REQ_NUM_13_inst                                     0x004A
#define DC_PC_SET_REQ_NUM_13_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_13_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_13_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_13_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_14                                          0x18008138
#define DC_PC_SET_REQ_NUM_14_reg_addr                                 "0xB8008138"
#define DC_PC_SET_REQ_NUM_14_reg                                      0xB8008138
#define DC_PC_SET_REQ_NUM_14_inst_addr                                "0x004E"
#define DC_PC_SET_REQ_NUM_14_inst                                     0x004E
#define DC_PC_SET_REQ_NUM_14_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_14_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_14_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_14_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_15                                          0x18008148
#define DC_PC_SET_REQ_NUM_15_reg_addr                                 "0xB8008148"
#define DC_PC_SET_REQ_NUM_15_reg                                      0xB8008148
#define DC_PC_SET_REQ_NUM_15_inst_addr                                "0x0052"
#define DC_PC_SET_REQ_NUM_15_inst                                     0x0052
#define DC_PC_SET_REQ_NUM_15_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_15_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_15_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_15_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_REQ_NUM_16                                          0x18008158
#define DC_PC_SET_REQ_NUM_16_reg_addr                                 "0xB8008158"
#define DC_PC_SET_REQ_NUM_16_reg                                      0xB8008158
#define DC_PC_SET_REQ_NUM_16_inst_addr                                "0x0056"
#define DC_PC_SET_REQ_NUM_16_inst                                     0x0056
#define DC_PC_SET_REQ_NUM_16_pc_req_number_shift                      (0)
#define DC_PC_SET_REQ_NUM_16_pc_req_number_mask                       (0x00FFFFFF)
#define DC_PC_SET_REQ_NUM_16_pc_req_number(data)                      (0x00FFFFFF&(data))
#define DC_PC_SET_REQ_NUM_16_get_pc_req_number(data)                  (0x00FFFFFF&(data))

#define DC_PC_SET_ACK_NUM_0                                           0x1800805c
#define DC_PC_SET_ACK_NUM_0_reg_addr                                  "0xB800805C"
#define DC_PC_SET_ACK_NUM_0_reg                                       0xB800805C
#define DC_PC_SET_ACK_NUM_0_inst_addr                                 "0x0017"
#define DC_PC_SET_ACK_NUM_0_inst                                      0x0017
#define DC_PC_SET_ACK_NUM_0_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_0_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_0_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_0_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_1                                           0x1800806c
#define DC_PC_SET_ACK_NUM_1_reg_addr                                  "0xB800806C"
#define DC_PC_SET_ACK_NUM_1_reg                                       0xB800806C
#define DC_PC_SET_ACK_NUM_1_inst_addr                                 "0x001B"
#define DC_PC_SET_ACK_NUM_1_inst                                      0x001B
#define DC_PC_SET_ACK_NUM_1_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_1_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_1_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_1_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_2                                           0x1800807c
#define DC_PC_SET_ACK_NUM_2_reg_addr                                  "0xB800807C"
#define DC_PC_SET_ACK_NUM_2_reg                                       0xB800807C
#define DC_PC_SET_ACK_NUM_2_inst_addr                                 "0x001F"
#define DC_PC_SET_ACK_NUM_2_inst                                      0x001F
#define DC_PC_SET_ACK_NUM_2_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_2_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_2_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_2_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_3                                           0x1800808c
#define DC_PC_SET_ACK_NUM_3_reg_addr                                  "0xB800808C"
#define DC_PC_SET_ACK_NUM_3_reg                                       0xB800808C
#define DC_PC_SET_ACK_NUM_3_inst_addr                                 "0x0023"
#define DC_PC_SET_ACK_NUM_3_inst                                      0x0023
#define DC_PC_SET_ACK_NUM_3_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_3_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_3_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_3_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_4                                           0x1800809c
#define DC_PC_SET_ACK_NUM_4_reg_addr                                  "0xB800809C"
#define DC_PC_SET_ACK_NUM_4_reg                                       0xB800809C
#define DC_PC_SET_ACK_NUM_4_inst_addr                                 "0x0027"
#define DC_PC_SET_ACK_NUM_4_inst                                      0x0027
#define DC_PC_SET_ACK_NUM_4_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_4_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_4_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_4_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_5                                           0x180080ac
#define DC_PC_SET_ACK_NUM_5_reg_addr                                  "0xB80080AC"
#define DC_PC_SET_ACK_NUM_5_reg                                       0xB80080AC
#define DC_PC_SET_ACK_NUM_5_inst_addr                                 "0x002B"
#define DC_PC_SET_ACK_NUM_5_inst                                      0x002B
#define DC_PC_SET_ACK_NUM_5_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_5_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_5_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_5_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_6                                           0x180080bc
#define DC_PC_SET_ACK_NUM_6_reg_addr                                  "0xB80080BC"
#define DC_PC_SET_ACK_NUM_6_reg                                       0xB80080BC
#define DC_PC_SET_ACK_NUM_6_inst_addr                                 "0x002F"
#define DC_PC_SET_ACK_NUM_6_inst                                      0x002F
#define DC_PC_SET_ACK_NUM_6_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_6_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_6_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_6_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_7                                           0x180080cc
#define DC_PC_SET_ACK_NUM_7_reg_addr                                  "0xB80080CC"
#define DC_PC_SET_ACK_NUM_7_reg                                       0xB80080CC
#define DC_PC_SET_ACK_NUM_7_inst_addr                                 "0x0033"
#define DC_PC_SET_ACK_NUM_7_inst                                      0x0033
#define DC_PC_SET_ACK_NUM_7_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_7_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_7_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_7_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_8                                           0x180080dc
#define DC_PC_SET_ACK_NUM_8_reg_addr                                  "0xB80080DC"
#define DC_PC_SET_ACK_NUM_8_reg                                       0xB80080DC
#define DC_PC_SET_ACK_NUM_8_inst_addr                                 "0x0037"
#define DC_PC_SET_ACK_NUM_8_inst                                      0x0037
#define DC_PC_SET_ACK_NUM_8_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_8_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_8_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_8_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_9                                           0x180080ec
#define DC_PC_SET_ACK_NUM_9_reg_addr                                  "0xB80080EC"
#define DC_PC_SET_ACK_NUM_9_reg                                       0xB80080EC
#define DC_PC_SET_ACK_NUM_9_inst_addr                                 "0x003B"
#define DC_PC_SET_ACK_NUM_9_inst                                      0x003B
#define DC_PC_SET_ACK_NUM_9_pc_ack_number_shift                       (0)
#define DC_PC_SET_ACK_NUM_9_pc_ack_number_mask                        (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_9_pc_ack_number(data)                       (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_9_get_pc_ack_number(data)                   (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_10                                          0x180080fc
#define DC_PC_SET_ACK_NUM_10_reg_addr                                 "0xB80080FC"
#define DC_PC_SET_ACK_NUM_10_reg                                      0xB80080FC
#define DC_PC_SET_ACK_NUM_10_inst_addr                                "0x003F"
#define DC_PC_SET_ACK_NUM_10_inst                                     0x003F
#define DC_PC_SET_ACK_NUM_10_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_10_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_10_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_10_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_11                                          0x1800810c
#define DC_PC_SET_ACK_NUM_11_reg_addr                                 "0xB800810C"
#define DC_PC_SET_ACK_NUM_11_reg                                      0xB800810C
#define DC_PC_SET_ACK_NUM_11_inst_addr                                "0x0043"
#define DC_PC_SET_ACK_NUM_11_inst                                     0x0043
#define DC_PC_SET_ACK_NUM_11_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_11_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_11_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_11_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_12                                          0x1800811c
#define DC_PC_SET_ACK_NUM_12_reg_addr                                 "0xB800811C"
#define DC_PC_SET_ACK_NUM_12_reg                                      0xB800811C
#define DC_PC_SET_ACK_NUM_12_inst_addr                                "0x0047"
#define DC_PC_SET_ACK_NUM_12_inst                                     0x0047
#define DC_PC_SET_ACK_NUM_12_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_12_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_12_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_12_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_13                                          0x1800812c
#define DC_PC_SET_ACK_NUM_13_reg_addr                                 "0xB800812C"
#define DC_PC_SET_ACK_NUM_13_reg                                      0xB800812C
#define DC_PC_SET_ACK_NUM_13_inst_addr                                "0x004B"
#define DC_PC_SET_ACK_NUM_13_inst                                     0x004B
#define DC_PC_SET_ACK_NUM_13_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_13_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_13_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_13_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_14                                          0x1800813c
#define DC_PC_SET_ACK_NUM_14_reg_addr                                 "0xB800813C"
#define DC_PC_SET_ACK_NUM_14_reg                                      0xB800813C
#define DC_PC_SET_ACK_NUM_14_inst_addr                                "0x004F"
#define DC_PC_SET_ACK_NUM_14_inst                                     0x004F
#define DC_PC_SET_ACK_NUM_14_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_14_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_14_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_14_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_15                                          0x1800814c
#define DC_PC_SET_ACK_NUM_15_reg_addr                                 "0xB800814C"
#define DC_PC_SET_ACK_NUM_15_reg                                      0xB800814C
#define DC_PC_SET_ACK_NUM_15_inst_addr                                "0x0053"
#define DC_PC_SET_ACK_NUM_15_inst                                     0x0053
#define DC_PC_SET_ACK_NUM_15_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_15_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_15_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_15_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_PC_SET_ACK_NUM_16                                          0x1800815c
#define DC_PC_SET_ACK_NUM_16_reg_addr                                 "0xB800815C"
#define DC_PC_SET_ACK_NUM_16_reg                                      0xB800815C
#define DC_PC_SET_ACK_NUM_16_inst_addr                                "0x0057"
#define DC_PC_SET_ACK_NUM_16_inst                                     0x0057
#define DC_PC_SET_ACK_NUM_16_pc_ack_number_shift                      (0)
#define DC_PC_SET_ACK_NUM_16_pc_ack_number_mask                       (0x3FFFFFFF)
#define DC_PC_SET_ACK_NUM_16_pc_ack_number(data)                      (0x3FFFFFFF&(data))
#define DC_PC_SET_ACK_NUM_16_get_pc_ack_number(data)                  (0x3FFFFFFF&(data))

#define DC_MT_SADDR_0                                                 0x18008200
#define DC_MT_SADDR_0_reg_addr                                        "0xB8008200"
#define DC_MT_SADDR_0_reg                                             0xB8008200
#define DC_MT_SADDR_0_inst_addr                                       "0x0080"
#define DC_MT_SADDR_0_inst                                            0x0080
#define DC_MT_SADDR_0_mem_type_shift                                  (30)
#define DC_MT_SADDR_0_saddr_shift                                     (5)
#define DC_MT_SADDR_0_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_0_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_0_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_0_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_0_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_0_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_1                                                 0x18008204
#define DC_MT_SADDR_1_reg_addr                                        "0xB8008204"
#define DC_MT_SADDR_1_reg                                             0xB8008204
#define DC_MT_SADDR_1_inst_addr                                       "0x0081"
#define DC_MT_SADDR_1_inst                                            0x0081
#define DC_MT_SADDR_1_mem_type_shift                                  (30)
#define DC_MT_SADDR_1_saddr_shift                                     (5)
#define DC_MT_SADDR_1_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_1_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_1_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_1_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_1_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_1_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_2                                                 0x18008208
#define DC_MT_SADDR_2_reg_addr                                        "0xB8008208"
#define DC_MT_SADDR_2_reg                                             0xB8008208
#define DC_MT_SADDR_2_inst_addr                                       "0x0082"
#define DC_MT_SADDR_2_inst                                            0x0082
#define DC_MT_SADDR_2_mem_type_shift                                  (30)
#define DC_MT_SADDR_2_saddr_shift                                     (5)
#define DC_MT_SADDR_2_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_2_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_2_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_2_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_2_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_2_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_3                                                 0x1800820c
#define DC_MT_SADDR_3_reg_addr                                        "0xB800820C"
#define DC_MT_SADDR_3_reg                                             0xB800820C
#define DC_MT_SADDR_3_inst_addr                                       "0x0083"
#define DC_MT_SADDR_3_inst                                            0x0083
#define DC_MT_SADDR_3_mem_type_shift                                  (30)
#define DC_MT_SADDR_3_saddr_shift                                     (5)
#define DC_MT_SADDR_3_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_3_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_3_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_3_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_3_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_3_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_4                                                 0x18008210
#define DC_MT_SADDR_4_reg_addr                                        "0xB8008210"
#define DC_MT_SADDR_4_reg                                             0xB8008210
#define DC_MT_SADDR_4_inst_addr                                       "0x0084"
#define DC_MT_SADDR_4_inst                                            0x0084
#define DC_MT_SADDR_4_mem_type_shift                                  (30)
#define DC_MT_SADDR_4_saddr_shift                                     (5)
#define DC_MT_SADDR_4_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_4_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_4_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_4_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_4_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_4_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_5                                                 0x18008214
#define DC_MT_SADDR_5_reg_addr                                        "0xB8008214"
#define DC_MT_SADDR_5_reg                                             0xB8008214
#define DC_MT_SADDR_5_inst_addr                                       "0x0085"
#define DC_MT_SADDR_5_inst                                            0x0085
#define DC_MT_SADDR_5_mem_type_shift                                  (30)
#define DC_MT_SADDR_5_saddr_shift                                     (5)
#define DC_MT_SADDR_5_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_5_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_5_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_5_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_5_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_5_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_6                                                 0x18008218
#define DC_MT_SADDR_6_reg_addr                                        "0xB8008218"
#define DC_MT_SADDR_6_reg                                             0xB8008218
#define DC_MT_SADDR_6_inst_addr                                       "0x0086"
#define DC_MT_SADDR_6_inst                                            0x0086
#define DC_MT_SADDR_6_mem_type_shift                                  (30)
#define DC_MT_SADDR_6_saddr_shift                                     (5)
#define DC_MT_SADDR_6_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_6_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_6_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_6_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_6_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_6_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_SADDR_7                                                 0x1800821c
#define DC_MT_SADDR_7_reg_addr                                        "0xB800821C"
#define DC_MT_SADDR_7_reg                                             0xB800821C
#define DC_MT_SADDR_7_inst_addr                                       "0x0087"
#define DC_MT_SADDR_7_inst                                            0x0087
#define DC_MT_SADDR_7_mem_type_shift                                  (30)
#define DC_MT_SADDR_7_saddr_shift                                     (5)
#define DC_MT_SADDR_7_mem_type_mask                                   (0xC0000000)
#define DC_MT_SADDR_7_saddr_mask                                      (0x07FFFFE0)
#define DC_MT_SADDR_7_mem_type(data)                                  (0xC0000000&((data)<<30))
#define DC_MT_SADDR_7_saddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_SADDR_7_get_mem_type(data)                              ((0xC0000000&(data))>>30)
#define DC_MT_SADDR_7_get_saddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_0                                                 0x18008220
#define DC_MT_EADDR_0_reg_addr                                        "0xB8008220"
#define DC_MT_EADDR_0_reg                                             0xB8008220
#define DC_MT_EADDR_0_inst_addr                                       "0x0088"
#define DC_MT_EADDR_0_inst                                            0x0088
#define DC_MT_EADDR_0_eaddr_shift                                     (5)
#define DC_MT_EADDR_0_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_0_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_0_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_1                                                 0x18008224
#define DC_MT_EADDR_1_reg_addr                                        "0xB8008224"
#define DC_MT_EADDR_1_reg                                             0xB8008224
#define DC_MT_EADDR_1_inst_addr                                       "0x0089"
#define DC_MT_EADDR_1_inst                                            0x0089
#define DC_MT_EADDR_1_eaddr_shift                                     (5)
#define DC_MT_EADDR_1_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_1_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_1_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_2                                                 0x18008228
#define DC_MT_EADDR_2_reg_addr                                        "0xB8008228"
#define DC_MT_EADDR_2_reg                                             0xB8008228
#define DC_MT_EADDR_2_inst_addr                                       "0x008A"
#define DC_MT_EADDR_2_inst                                            0x008A
#define DC_MT_EADDR_2_eaddr_shift                                     (5)
#define DC_MT_EADDR_2_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_2_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_2_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_3                                                 0x1800822c
#define DC_MT_EADDR_3_reg_addr                                        "0xB800822C"
#define DC_MT_EADDR_3_reg                                             0xB800822C
#define DC_MT_EADDR_3_inst_addr                                       "0x008B"
#define DC_MT_EADDR_3_inst                                            0x008B
#define DC_MT_EADDR_3_eaddr_shift                                     (5)
#define DC_MT_EADDR_3_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_3_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_3_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_4                                                 0x18008230
#define DC_MT_EADDR_4_reg_addr                                        "0xB8008230"
#define DC_MT_EADDR_4_reg                                             0xB8008230
#define DC_MT_EADDR_4_inst_addr                                       "0x008C"
#define DC_MT_EADDR_4_inst                                            0x008C
#define DC_MT_EADDR_4_eaddr_shift                                     (5)
#define DC_MT_EADDR_4_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_4_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_4_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_5                                                 0x18008234
#define DC_MT_EADDR_5_reg_addr                                        "0xB8008234"
#define DC_MT_EADDR_5_reg                                             0xB8008234
#define DC_MT_EADDR_5_inst_addr                                       "0x008D"
#define DC_MT_EADDR_5_inst                                            0x008D
#define DC_MT_EADDR_5_eaddr_shift                                     (5)
#define DC_MT_EADDR_5_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_5_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_5_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_6                                                 0x18008238
#define DC_MT_EADDR_6_reg_addr                                        "0xB8008238"
#define DC_MT_EADDR_6_reg                                             0xB8008238
#define DC_MT_EADDR_6_inst_addr                                       "0x008E"
#define DC_MT_EADDR_6_inst                                            0x008E
#define DC_MT_EADDR_6_eaddr_shift                                     (5)
#define DC_MT_EADDR_6_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_6_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_6_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_EADDR_7                                                 0x1800823c
#define DC_MT_EADDR_7_reg_addr                                        "0xB800823C"
#define DC_MT_EADDR_7_reg                                             0xB800823C
#define DC_MT_EADDR_7_inst_addr                                       "0x008F"
#define DC_MT_EADDR_7_inst                                            0x008F
#define DC_MT_EADDR_7_eaddr_shift                                     (5)
#define DC_MT_EADDR_7_eaddr_mask                                      (0x07FFFFE0)
#define DC_MT_EADDR_7_eaddr(data)                                     (0x07FFFFE0&((data)<<5))
#define DC_MT_EADDR_7_get_eaddr(data)                                 ((0x07FFFFE0&(data))>>5)

#define DC_MT_MODE_0                                                  0x18008240
#define DC_MT_MODE_0_reg_addr                                         "0xB8008240"
#define DC_MT_MODE_0_reg                                              0xB8008240
#define DC_MT_MODE_0_inst_addr                                        "0x0090"
#define DC_MT_MODE_0_inst                                             0x0090
#define DC_MT_MODE_0_write_enable1_shift                              (14)
#define DC_MT_MODE_0_int1_shift                                       (13)
#define DC_MT_MODE_0_write_enable2_shift                              (12)
#define DC_MT_MODE_0_int2_shift                                       (11)
#define DC_MT_MODE_0_write_enable3_shift                              (10)
#define DC_MT_MODE_0_int3_shift                                       (9)
#define DC_MT_MODE_0_write_enable4_shift                              (8)
#define DC_MT_MODE_0_cpu_shift                                        (6)
#define DC_MT_MODE_0_int1_en_shift                                    (5)
#define DC_MT_MODE_0_int2_en_shift                                    (4)
#define DC_MT_MODE_0_int3_en_shift                                    (3)
#define DC_MT_MODE_0_write_enable5_shift                              (2)
#define DC_MT_MODE_0_mode_shift                                       (0)
#define DC_MT_MODE_0_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_0_int1_mask                                        (0x00002000)
#define DC_MT_MODE_0_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_0_int2_mask                                        (0x00000800)
#define DC_MT_MODE_0_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_0_int3_mask                                        (0x00000200)
#define DC_MT_MODE_0_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_0_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_0_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_0_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_0_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_0_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_0_mode_mask                                        (0x00000003)
#define DC_MT_MODE_0_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_0_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_0_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_0_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_0_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_0_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_0_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_0_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_0_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_0_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_0_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_0_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_0_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_0_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_0_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_0_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_0_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_0_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_0_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_0_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_0_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_0_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_0_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_0_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_0_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_0_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_1                                                  0x18008244
#define DC_MT_MODE_1_reg_addr                                         "0xB8008244"
#define DC_MT_MODE_1_reg                                              0xB8008244
#define DC_MT_MODE_1_inst_addr                                        "0x0091"
#define DC_MT_MODE_1_inst                                             0x0091
#define DC_MT_MODE_1_write_enable1_shift                              (14)
#define DC_MT_MODE_1_int1_shift                                       (13)
#define DC_MT_MODE_1_write_enable2_shift                              (12)
#define DC_MT_MODE_1_int2_shift                                       (11)
#define DC_MT_MODE_1_write_enable3_shift                              (10)
#define DC_MT_MODE_1_int3_shift                                       (9)
#define DC_MT_MODE_1_write_enable4_shift                              (8)
#define DC_MT_MODE_1_cpu_shift                                        (6)
#define DC_MT_MODE_1_int1_en_shift                                    (5)
#define DC_MT_MODE_1_int2_en_shift                                    (4)
#define DC_MT_MODE_1_int3_en_shift                                    (3)
#define DC_MT_MODE_1_write_enable5_shift                              (2)
#define DC_MT_MODE_1_mode_shift                                       (0)
#define DC_MT_MODE_1_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_1_int1_mask                                        (0x00002000)
#define DC_MT_MODE_1_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_1_int2_mask                                        (0x00000800)
#define DC_MT_MODE_1_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_1_int3_mask                                        (0x00000200)
#define DC_MT_MODE_1_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_1_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_1_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_1_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_1_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_1_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_1_mode_mask                                        (0x00000003)
#define DC_MT_MODE_1_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_1_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_1_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_1_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_1_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_1_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_1_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_1_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_1_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_1_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_1_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_1_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_1_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_1_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_1_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_1_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_1_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_1_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_1_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_1_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_1_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_1_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_1_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_1_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_1_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_1_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_2                                                  0x18008248
#define DC_MT_MODE_2_reg_addr                                         "0xB8008248"
#define DC_MT_MODE_2_reg                                              0xB8008248
#define DC_MT_MODE_2_inst_addr                                        "0x0092"
#define DC_MT_MODE_2_inst                                             0x0092
#define DC_MT_MODE_2_write_enable1_shift                              (14)
#define DC_MT_MODE_2_int1_shift                                       (13)
#define DC_MT_MODE_2_write_enable2_shift                              (12)
#define DC_MT_MODE_2_int2_shift                                       (11)
#define DC_MT_MODE_2_write_enable3_shift                              (10)
#define DC_MT_MODE_2_int3_shift                                       (9)
#define DC_MT_MODE_2_write_enable4_shift                              (8)
#define DC_MT_MODE_2_cpu_shift                                        (6)
#define DC_MT_MODE_2_int1_en_shift                                    (5)
#define DC_MT_MODE_2_int2_en_shift                                    (4)
#define DC_MT_MODE_2_int3_en_shift                                    (3)
#define DC_MT_MODE_2_write_enable5_shift                              (2)
#define DC_MT_MODE_2_mode_shift                                       (0)
#define DC_MT_MODE_2_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_2_int1_mask                                        (0x00002000)
#define DC_MT_MODE_2_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_2_int2_mask                                        (0x00000800)
#define DC_MT_MODE_2_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_2_int3_mask                                        (0x00000200)
#define DC_MT_MODE_2_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_2_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_2_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_2_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_2_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_2_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_2_mode_mask                                        (0x00000003)
#define DC_MT_MODE_2_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_2_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_2_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_2_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_2_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_2_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_2_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_2_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_2_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_2_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_2_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_2_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_2_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_2_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_2_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_2_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_2_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_2_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_2_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_2_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_2_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_2_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_2_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_2_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_2_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_2_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_3                                                  0x1800824c
#define DC_MT_MODE_3_reg_addr                                         "0xB800824C"
#define DC_MT_MODE_3_reg                                              0xB800824C
#define DC_MT_MODE_3_inst_addr                                        "0x0093"
#define DC_MT_MODE_3_inst                                             0x0093
#define DC_MT_MODE_3_write_enable1_shift                              (14)
#define DC_MT_MODE_3_int1_shift                                       (13)
#define DC_MT_MODE_3_write_enable2_shift                              (12)
#define DC_MT_MODE_3_int2_shift                                       (11)
#define DC_MT_MODE_3_write_enable3_shift                              (10)
#define DC_MT_MODE_3_int3_shift                                       (9)
#define DC_MT_MODE_3_write_enable4_shift                              (8)
#define DC_MT_MODE_3_cpu_shift                                        (6)
#define DC_MT_MODE_3_int1_en_shift                                    (5)
#define DC_MT_MODE_3_int2_en_shift                                    (4)
#define DC_MT_MODE_3_int3_en_shift                                    (3)
#define DC_MT_MODE_3_write_enable5_shift                              (2)
#define DC_MT_MODE_3_mode_shift                                       (0)
#define DC_MT_MODE_3_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_3_int1_mask                                        (0x00002000)
#define DC_MT_MODE_3_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_3_int2_mask                                        (0x00000800)
#define DC_MT_MODE_3_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_3_int3_mask                                        (0x00000200)
#define DC_MT_MODE_3_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_3_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_3_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_3_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_3_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_3_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_3_mode_mask                                        (0x00000003)
#define DC_MT_MODE_3_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_3_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_3_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_3_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_3_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_3_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_3_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_3_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_3_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_3_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_3_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_3_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_3_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_3_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_3_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_3_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_3_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_3_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_3_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_3_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_3_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_3_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_3_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_3_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_3_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_3_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_4                                                  0x18008250
#define DC_MT_MODE_4_reg_addr                                         "0xB8008250"
#define DC_MT_MODE_4_reg                                              0xB8008250
#define DC_MT_MODE_4_inst_addr                                        "0x0094"
#define DC_MT_MODE_4_inst                                             0x0094
#define DC_MT_MODE_4_write_enable1_shift                              (14)
#define DC_MT_MODE_4_int1_shift                                       (13)
#define DC_MT_MODE_4_write_enable2_shift                              (12)
#define DC_MT_MODE_4_int2_shift                                       (11)
#define DC_MT_MODE_4_write_enable3_shift                              (10)
#define DC_MT_MODE_4_int3_shift                                       (9)
#define DC_MT_MODE_4_write_enable4_shift                              (8)
#define DC_MT_MODE_4_cpu_shift                                        (6)
#define DC_MT_MODE_4_int1_en_shift                                    (5)
#define DC_MT_MODE_4_int2_en_shift                                    (4)
#define DC_MT_MODE_4_int3_en_shift                                    (3)
#define DC_MT_MODE_4_write_enable5_shift                              (2)
#define DC_MT_MODE_4_mode_shift                                       (0)
#define DC_MT_MODE_4_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_4_int1_mask                                        (0x00002000)
#define DC_MT_MODE_4_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_4_int2_mask                                        (0x00000800)
#define DC_MT_MODE_4_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_4_int3_mask                                        (0x00000200)
#define DC_MT_MODE_4_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_4_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_4_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_4_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_4_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_4_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_4_mode_mask                                        (0x00000003)
#define DC_MT_MODE_4_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_4_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_4_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_4_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_4_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_4_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_4_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_4_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_4_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_4_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_4_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_4_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_4_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_4_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_4_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_4_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_4_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_4_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_4_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_4_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_4_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_4_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_4_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_4_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_4_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_4_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_5                                                  0x18008254
#define DC_MT_MODE_5_reg_addr                                         "0xB8008254"
#define DC_MT_MODE_5_reg                                              0xB8008254
#define DC_MT_MODE_5_inst_addr                                        "0x0095"
#define DC_MT_MODE_5_inst                                             0x0095
#define DC_MT_MODE_5_write_enable1_shift                              (14)
#define DC_MT_MODE_5_int1_shift                                       (13)
#define DC_MT_MODE_5_write_enable2_shift                              (12)
#define DC_MT_MODE_5_int2_shift                                       (11)
#define DC_MT_MODE_5_write_enable3_shift                              (10)
#define DC_MT_MODE_5_int3_shift                                       (9)
#define DC_MT_MODE_5_write_enable4_shift                              (8)
#define DC_MT_MODE_5_cpu_shift                                        (6)
#define DC_MT_MODE_5_int1_en_shift                                    (5)
#define DC_MT_MODE_5_int2_en_shift                                    (4)
#define DC_MT_MODE_5_int3_en_shift                                    (3)
#define DC_MT_MODE_5_write_enable5_shift                              (2)
#define DC_MT_MODE_5_mode_shift                                       (0)
#define DC_MT_MODE_5_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_5_int1_mask                                        (0x00002000)
#define DC_MT_MODE_5_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_5_int2_mask                                        (0x00000800)
#define DC_MT_MODE_5_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_5_int3_mask                                        (0x00000200)
#define DC_MT_MODE_5_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_5_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_5_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_5_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_5_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_5_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_5_mode_mask                                        (0x00000003)
#define DC_MT_MODE_5_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_5_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_5_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_5_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_5_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_5_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_5_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_5_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_5_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_5_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_5_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_5_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_5_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_5_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_5_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_5_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_5_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_5_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_5_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_5_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_5_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_5_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_5_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_5_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_5_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_5_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_6                                                  0x18008258
#define DC_MT_MODE_6_reg_addr                                         "0xB8008258"
#define DC_MT_MODE_6_reg                                              0xB8008258
#define DC_MT_MODE_6_inst_addr                                        "0x0096"
#define DC_MT_MODE_6_inst                                             0x0096
#define DC_MT_MODE_6_write_enable1_shift                              (14)
#define DC_MT_MODE_6_int1_shift                                       (13)
#define DC_MT_MODE_6_write_enable2_shift                              (12)
#define DC_MT_MODE_6_int2_shift                                       (11)
#define DC_MT_MODE_6_write_enable3_shift                              (10)
#define DC_MT_MODE_6_int3_shift                                       (9)
#define DC_MT_MODE_6_write_enable4_shift                              (8)
#define DC_MT_MODE_6_cpu_shift                                        (6)
#define DC_MT_MODE_6_int1_en_shift                                    (5)
#define DC_MT_MODE_6_int2_en_shift                                    (4)
#define DC_MT_MODE_6_int3_en_shift                                    (3)
#define DC_MT_MODE_6_write_enable5_shift                              (2)
#define DC_MT_MODE_6_mode_shift                                       (0)
#define DC_MT_MODE_6_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_6_int1_mask                                        (0x00002000)
#define DC_MT_MODE_6_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_6_int2_mask                                        (0x00000800)
#define DC_MT_MODE_6_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_6_int3_mask                                        (0x00000200)
#define DC_MT_MODE_6_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_6_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_6_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_6_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_6_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_6_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_6_mode_mask                                        (0x00000003)
#define DC_MT_MODE_6_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_6_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_6_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_6_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_6_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_6_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_6_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_6_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_6_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_6_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_6_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_6_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_6_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_6_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_6_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_6_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_6_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_6_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_6_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_6_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_6_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_6_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_6_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_6_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_6_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_6_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_MODE_7                                                  0x1800825c
#define DC_MT_MODE_7_reg_addr                                         "0xB800825C"
#define DC_MT_MODE_7_reg                                              0xB800825C
#define DC_MT_MODE_7_inst_addr                                        "0x0097"
#define DC_MT_MODE_7_inst                                             0x0097
#define DC_MT_MODE_7_write_enable1_shift                              (14)
#define DC_MT_MODE_7_int1_shift                                       (13)
#define DC_MT_MODE_7_write_enable2_shift                              (12)
#define DC_MT_MODE_7_int2_shift                                       (11)
#define DC_MT_MODE_7_write_enable3_shift                              (10)
#define DC_MT_MODE_7_int3_shift                                       (9)
#define DC_MT_MODE_7_write_enable4_shift                              (8)
#define DC_MT_MODE_7_cpu_shift                                        (6)
#define DC_MT_MODE_7_int1_en_shift                                    (5)
#define DC_MT_MODE_7_int2_en_shift                                    (4)
#define DC_MT_MODE_7_int3_en_shift                                    (3)
#define DC_MT_MODE_7_write_enable5_shift                              (2)
#define DC_MT_MODE_7_mode_shift                                       (0)
#define DC_MT_MODE_7_write_enable1_mask                               (0x00004000)
#define DC_MT_MODE_7_int1_mask                                        (0x00002000)
#define DC_MT_MODE_7_write_enable2_mask                               (0x00001000)
#define DC_MT_MODE_7_int2_mask                                        (0x00000800)
#define DC_MT_MODE_7_write_enable3_mask                               (0x00000400)
#define DC_MT_MODE_7_int3_mask                                        (0x00000200)
#define DC_MT_MODE_7_write_enable4_mask                               (0x00000100)
#define DC_MT_MODE_7_cpu_mask                                         (0x000000C0)
#define DC_MT_MODE_7_int1_en_mask                                     (0x00000020)
#define DC_MT_MODE_7_int2_en_mask                                     (0x00000010)
#define DC_MT_MODE_7_int3_en_mask                                     (0x00000008)
#define DC_MT_MODE_7_write_enable5_mask                               (0x00000004)
#define DC_MT_MODE_7_mode_mask                                        (0x00000003)
#define DC_MT_MODE_7_write_enable1(data)                              (0x00004000&((data)<<14))
#define DC_MT_MODE_7_int1(data)                                       (0x00002000&((data)<<13))
#define DC_MT_MODE_7_write_enable2(data)                              (0x00001000&((data)<<12))
#define DC_MT_MODE_7_int2(data)                                       (0x00000800&((data)<<11))
#define DC_MT_MODE_7_write_enable3(data)                              (0x00000400&((data)<<10))
#define DC_MT_MODE_7_int3(data)                                       (0x00000200&((data)<<9))
#define DC_MT_MODE_7_write_enable4(data)                              (0x00000100&((data)<<8))
#define DC_MT_MODE_7_cpu(data)                                        (0x000000C0&((data)<<6))
#define DC_MT_MODE_7_int1_en(data)                                    (0x00000020&((data)<<5))
#define DC_MT_MODE_7_int2_en(data)                                    (0x00000010&((data)<<4))
#define DC_MT_MODE_7_int3_en(data)                                    (0x00000008&((data)<<3))
#define DC_MT_MODE_7_write_enable5(data)                              (0x00000004&((data)<<2))
#define DC_MT_MODE_7_mode(data)                                       (0x00000003&(data))
#define DC_MT_MODE_7_get_write_enable1(data)                          ((0x00004000&(data))>>14)
#define DC_MT_MODE_7_get_int1(data)                                   ((0x00002000&(data))>>13)
#define DC_MT_MODE_7_get_write_enable2(data)                          ((0x00001000&(data))>>12)
#define DC_MT_MODE_7_get_int2(data)                                   ((0x00000800&(data))>>11)
#define DC_MT_MODE_7_get_write_enable3(data)                          ((0x00000400&(data))>>10)
#define DC_MT_MODE_7_get_int3(data)                                   ((0x00000200&(data))>>9)
#define DC_MT_MODE_7_get_write_enable4(data)                          ((0x00000100&(data))>>8)
#define DC_MT_MODE_7_get_cpu(data)                                    ((0x000000C0&(data))>>6)
#define DC_MT_MODE_7_get_int1_en(data)                                ((0x00000020&(data))>>5)
#define DC_MT_MODE_7_get_int2_en(data)                                ((0x00000010&(data))>>4)
#define DC_MT_MODE_7_get_int3_en(data)                                ((0x00000008&(data))>>3)
#define DC_MT_MODE_7_get_write_enable5(data)                          ((0x00000004&(data))>>2)
#define DC_MT_MODE_7_get_mode(data)                                   (0x00000003&(data))

#define DC_MT_TABLE_0_0                                               0x18008260
#define DC_MT_TABLE_0_0_reg_addr                                      "0xB8008260"
#define DC_MT_TABLE_0_0_reg                                           0xB8008260
#define DC_MT_TABLE_0_0_inst_addr                                     "0x0098"
#define DC_MT_TABLE_0_0_inst                                          0x0098
#define DC_MT_TABLE_0_0_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_0_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_0_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_0_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_0_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_0_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_0_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_0_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_0_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_0_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_0_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_0_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_0_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_0_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_0_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_0_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_0_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_0_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_0_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_0_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_0_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_0_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_0_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_0_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_1                                               0x18008264
#define DC_MT_TABLE_0_1_reg_addr                                      "0xB8008264"
#define DC_MT_TABLE_0_1_reg                                           0xB8008264
#define DC_MT_TABLE_0_1_inst_addr                                     "0x0099"
#define DC_MT_TABLE_0_1_inst                                          0x0099
#define DC_MT_TABLE_0_1_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_1_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_1_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_1_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_1_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_1_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_1_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_1_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_1_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_1_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_1_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_1_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_1_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_1_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_1_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_1_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_1_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_1_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_1_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_1_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_1_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_1_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_1_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_1_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_2                                               0x18008268
#define DC_MT_TABLE_0_2_reg_addr                                      "0xB8008268"
#define DC_MT_TABLE_0_2_reg                                           0xB8008268
#define DC_MT_TABLE_0_2_inst_addr                                     "0x009A"
#define DC_MT_TABLE_0_2_inst                                          0x009A
#define DC_MT_TABLE_0_2_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_2_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_2_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_2_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_2_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_2_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_2_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_2_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_2_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_2_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_2_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_2_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_2_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_2_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_2_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_2_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_2_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_2_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_2_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_2_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_2_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_2_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_2_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_2_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_3                                               0x1800826c
#define DC_MT_TABLE_0_3_reg_addr                                      "0xB800826C"
#define DC_MT_TABLE_0_3_reg                                           0xB800826C
#define DC_MT_TABLE_0_3_inst_addr                                     "0x009B"
#define DC_MT_TABLE_0_3_inst                                          0x009B
#define DC_MT_TABLE_0_3_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_3_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_3_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_3_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_3_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_3_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_3_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_3_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_3_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_3_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_3_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_3_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_3_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_3_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_3_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_3_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_3_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_3_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_3_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_3_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_3_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_3_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_3_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_3_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_4                                               0x18008270
#define DC_MT_TABLE_0_4_reg_addr                                      "0xB8008270"
#define DC_MT_TABLE_0_4_reg                                           0xB8008270
#define DC_MT_TABLE_0_4_inst_addr                                     "0x009C"
#define DC_MT_TABLE_0_4_inst                                          0x009C
#define DC_MT_TABLE_0_4_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_4_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_4_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_4_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_4_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_4_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_4_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_4_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_4_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_4_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_4_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_4_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_4_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_4_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_4_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_4_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_4_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_4_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_4_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_4_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_4_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_4_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_4_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_4_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_5                                               0x18008274
#define DC_MT_TABLE_0_5_reg_addr                                      "0xB8008274"
#define DC_MT_TABLE_0_5_reg                                           0xB8008274
#define DC_MT_TABLE_0_5_inst_addr                                     "0x009D"
#define DC_MT_TABLE_0_5_inst                                          0x009D
#define DC_MT_TABLE_0_5_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_5_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_5_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_5_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_5_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_5_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_5_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_5_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_5_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_5_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_5_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_5_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_5_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_5_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_5_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_5_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_5_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_5_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_5_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_5_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_5_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_5_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_5_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_5_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_6                                               0x18008278
#define DC_MT_TABLE_0_6_reg_addr                                      "0xB8008278"
#define DC_MT_TABLE_0_6_reg                                           0xB8008278
#define DC_MT_TABLE_0_6_inst_addr                                     "0x009E"
#define DC_MT_TABLE_0_6_inst                                          0x009E
#define DC_MT_TABLE_0_6_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_6_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_6_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_6_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_6_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_6_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_6_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_6_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_6_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_6_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_6_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_6_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_6_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_6_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_6_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_6_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_6_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_6_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_6_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_6_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_6_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_6_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_6_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_6_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_0_7                                               0x1800827c
#define DC_MT_TABLE_0_7_reg_addr                                      "0xB800827C"
#define DC_MT_TABLE_0_7_reg                                           0xB800827C
#define DC_MT_TABLE_0_7_inst_addr                                     "0x009F"
#define DC_MT_TABLE_0_7_inst                                          0x009F
#define DC_MT_TABLE_0_7_module_id_0_shift                             (20)
#define DC_MT_TABLE_0_7_access_type_0_shift                           (18)
#define DC_MT_TABLE_0_7_module_id_1_shift                             (11)
#define DC_MT_TABLE_0_7_access_type_1_shift                           (9)
#define DC_MT_TABLE_0_7_module_id_2_shift                             (2)
#define DC_MT_TABLE_0_7_access_type_2_shift                           (0)
#define DC_MT_TABLE_0_7_module_id_0_mask                              (0x07F00000)
#define DC_MT_TABLE_0_7_access_type_0_mask                            (0x000C0000)
#define DC_MT_TABLE_0_7_module_id_1_mask                              (0x0003F800)
#define DC_MT_TABLE_0_7_access_type_1_mask                            (0x00000600)
#define DC_MT_TABLE_0_7_module_id_2_mask                              (0x000001FC)
#define DC_MT_TABLE_0_7_access_type_2_mask                            (0x00000003)
#define DC_MT_TABLE_0_7_module_id_0(data)                             (0x07F00000&((data)<<20))
#define DC_MT_TABLE_0_7_access_type_0(data)                           (0x000C0000&((data)<<18))
#define DC_MT_TABLE_0_7_module_id_1(data)                             (0x0003F800&((data)<<11))
#define DC_MT_TABLE_0_7_access_type_1(data)                           (0x00000600&((data)<<9))
#define DC_MT_TABLE_0_7_module_id_2(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_0_7_access_type_2(data)                           (0x00000003&(data))
#define DC_MT_TABLE_0_7_get_module_id_0(data)                         ((0x07F00000&(data))>>20)
#define DC_MT_TABLE_0_7_get_access_type_0(data)                       ((0x000C0000&(data))>>18)
#define DC_MT_TABLE_0_7_get_module_id_1(data)                         ((0x0003F800&(data))>>11)
#define DC_MT_TABLE_0_7_get_access_type_1(data)                       ((0x00000600&(data))>>9)
#define DC_MT_TABLE_0_7_get_module_id_2(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_0_7_get_access_type_2(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_0                                               0x18008280
#define DC_MT_TABLE_1_0_reg_addr                                      "0xB8008280"
#define DC_MT_TABLE_1_0_reg                                           0xB8008280
#define DC_MT_TABLE_1_0_inst_addr                                     "0x00A0"
#define DC_MT_TABLE_1_0_inst                                          0x00A0
#define DC_MT_TABLE_1_0_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_0_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_0_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_0_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_0_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_0_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_0_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_0_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_1                                               0x18008284
#define DC_MT_TABLE_1_1_reg_addr                                      "0xB8008284"
#define DC_MT_TABLE_1_1_reg                                           0xB8008284
#define DC_MT_TABLE_1_1_inst_addr                                     "0x00A1"
#define DC_MT_TABLE_1_1_inst                                          0x00A1
#define DC_MT_TABLE_1_1_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_1_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_1_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_1_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_1_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_1_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_1_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_1_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_2                                               0x18008288
#define DC_MT_TABLE_1_2_reg_addr                                      "0xB8008288"
#define DC_MT_TABLE_1_2_reg                                           0xB8008288
#define DC_MT_TABLE_1_2_inst_addr                                     "0x00A2"
#define DC_MT_TABLE_1_2_inst                                          0x00A2
#define DC_MT_TABLE_1_2_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_2_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_2_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_2_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_2_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_2_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_2_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_2_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_3                                               0x1800828c
#define DC_MT_TABLE_1_3_reg_addr                                      "0xB800828C"
#define DC_MT_TABLE_1_3_reg                                           0xB800828C
#define DC_MT_TABLE_1_3_inst_addr                                     "0x00A3"
#define DC_MT_TABLE_1_3_inst                                          0x00A3
#define DC_MT_TABLE_1_3_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_3_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_3_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_3_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_3_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_3_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_3_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_3_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_4                                               0x18008290
#define DC_MT_TABLE_1_4_reg_addr                                      "0xB8008290"
#define DC_MT_TABLE_1_4_reg                                           0xB8008290
#define DC_MT_TABLE_1_4_inst_addr                                     "0x00A4"
#define DC_MT_TABLE_1_4_inst                                          0x00A4
#define DC_MT_TABLE_1_4_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_4_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_4_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_4_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_4_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_4_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_4_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_4_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_5                                               0x18008294
#define DC_MT_TABLE_1_5_reg_addr                                      "0xB8008294"
#define DC_MT_TABLE_1_5_reg                                           0xB8008294
#define DC_MT_TABLE_1_5_inst_addr                                     "0x00A5"
#define DC_MT_TABLE_1_5_inst                                          0x00A5
#define DC_MT_TABLE_1_5_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_5_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_5_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_5_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_5_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_5_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_5_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_5_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_6                                               0x18008298
#define DC_MT_TABLE_1_6_reg_addr                                      "0xB8008298"
#define DC_MT_TABLE_1_6_reg                                           0xB8008298
#define DC_MT_TABLE_1_6_inst_addr                                     "0x00A6"
#define DC_MT_TABLE_1_6_inst                                          0x00A6
#define DC_MT_TABLE_1_6_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_6_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_6_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_6_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_6_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_6_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_6_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_6_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_TABLE_1_7                                               0x1800829c
#define DC_MT_TABLE_1_7_reg_addr                                      "0xB800829C"
#define DC_MT_TABLE_1_7_reg                                           0xB800829C
#define DC_MT_TABLE_1_7_inst_addr                                     "0x00A7"
#define DC_MT_TABLE_1_7_inst                                          0x00A7
#define DC_MT_TABLE_1_7_module_id_3_shift                             (2)
#define DC_MT_TABLE_1_7_access_type_3_shift                           (0)
#define DC_MT_TABLE_1_7_module_id_3_mask                              (0x000001FC)
#define DC_MT_TABLE_1_7_access_type_3_mask                            (0x00000003)
#define DC_MT_TABLE_1_7_module_id_3(data)                             (0x000001FC&((data)<<2))
#define DC_MT_TABLE_1_7_access_type_3(data)                           (0x00000003&(data))
#define DC_MT_TABLE_1_7_get_module_id_3(data)                         ((0x000001FC&(data))>>2)
#define DC_MT_TABLE_1_7_get_access_type_3(data)                       (0x00000003&(data))

#define DC_MT_ADDCMD_HI_0                                             0x180082a0
#define DC_MT_ADDCMD_HI_0_reg_addr                                    "0xB80082A0"
#define DC_MT_ADDCMD_HI_0_reg                                         0xB80082A0
#define DC_MT_ADDCMD_HI_0_inst_addr                                   "0x00A8"
#define DC_MT_ADDCMD_HI_0_inst                                        0x00A8
#define DC_MT_ADDCMD_HI_0_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_0_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_0_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_0_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_0_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_0_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_0_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_0_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_1                                             0x180082a4
#define DC_MT_ADDCMD_HI_1_reg_addr                                    "0xB80082A4"
#define DC_MT_ADDCMD_HI_1_reg                                         0xB80082A4
#define DC_MT_ADDCMD_HI_1_inst_addr                                   "0x00A9"
#define DC_MT_ADDCMD_HI_1_inst                                        0x00A9
#define DC_MT_ADDCMD_HI_1_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_1_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_1_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_1_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_1_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_1_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_1_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_1_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_2                                             0x180082a8
#define DC_MT_ADDCMD_HI_2_reg_addr                                    "0xB80082A8"
#define DC_MT_ADDCMD_HI_2_reg                                         0xB80082A8
#define DC_MT_ADDCMD_HI_2_inst_addr                                   "0x00AA"
#define DC_MT_ADDCMD_HI_2_inst                                        0x00AA
#define DC_MT_ADDCMD_HI_2_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_2_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_2_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_2_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_2_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_2_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_2_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_2_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_3                                             0x180082ac
#define DC_MT_ADDCMD_HI_3_reg_addr                                    "0xB80082AC"
#define DC_MT_ADDCMD_HI_3_reg                                         0xB80082AC
#define DC_MT_ADDCMD_HI_3_inst_addr                                   "0x00AB"
#define DC_MT_ADDCMD_HI_3_inst                                        0x00AB
#define DC_MT_ADDCMD_HI_3_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_3_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_3_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_3_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_3_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_3_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_3_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_3_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_4                                             0x180082b0
#define DC_MT_ADDCMD_HI_4_reg_addr                                    "0xB80082B0"
#define DC_MT_ADDCMD_HI_4_reg                                         0xB80082B0
#define DC_MT_ADDCMD_HI_4_inst_addr                                   "0x00AC"
#define DC_MT_ADDCMD_HI_4_inst                                        0x00AC
#define DC_MT_ADDCMD_HI_4_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_4_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_4_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_4_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_4_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_4_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_4_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_4_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_5                                             0x180082b4
#define DC_MT_ADDCMD_HI_5_reg_addr                                    "0xB80082B4"
#define DC_MT_ADDCMD_HI_5_reg                                         0xB80082B4
#define DC_MT_ADDCMD_HI_5_inst_addr                                   "0x00AD"
#define DC_MT_ADDCMD_HI_5_inst                                        0x00AD
#define DC_MT_ADDCMD_HI_5_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_5_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_5_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_5_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_5_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_5_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_5_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_5_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_6                                             0x180082b8
#define DC_MT_ADDCMD_HI_6_reg_addr                                    "0xB80082B8"
#define DC_MT_ADDCMD_HI_6_reg                                         0xB80082B8
#define DC_MT_ADDCMD_HI_6_inst_addr                                   "0x00AE"
#define DC_MT_ADDCMD_HI_6_inst                                        0x00AE
#define DC_MT_ADDCMD_HI_6_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_6_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_6_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_6_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_6_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_6_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_6_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_6_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_HI_7                                             0x180082bc
#define DC_MT_ADDCMD_HI_7_reg_addr                                    "0xB80082BC"
#define DC_MT_ADDCMD_HI_7_reg                                         0xB80082BC
#define DC_MT_ADDCMD_HI_7_inst_addr                                   "0x00AF"
#define DC_MT_ADDCMD_HI_7_inst                                        0x00AF
#define DC_MT_ADDCMD_HI_7_module_id_shift                             (15)
#define DC_MT_ADDCMD_HI_7_addcmd_shift                                (0)
#define DC_MT_ADDCMD_HI_7_module_id_mask                              (0x003F8000)
#define DC_MT_ADDCMD_HI_7_addcmd_mask                                 (0x00007FFF)
#define DC_MT_ADDCMD_HI_7_module_id(data)                             (0x003F8000&((data)<<15))
#define DC_MT_ADDCMD_HI_7_addcmd(data)                                (0x00007FFF&(data))
#define DC_MT_ADDCMD_HI_7_get_module_id(data)                         ((0x003F8000&(data))>>15)
#define DC_MT_ADDCMD_HI_7_get_addcmd(data)                            (0x00007FFF&(data))

#define DC_MT_ADDCMD_LO_0                                             0x180082c0
#define DC_MT_ADDCMD_LO_0_reg_addr                                    "0xB80082C0"
#define DC_MT_ADDCMD_LO_0_reg                                         0xB80082C0
#define DC_MT_ADDCMD_LO_0_inst_addr                                   "0x00B0"
#define DC_MT_ADDCMD_LO_0_inst                                        0x00B0
#define DC_MT_ADDCMD_LO_0_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_0_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_0_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_0_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_1                                             0x180082c4
#define DC_MT_ADDCMD_LO_1_reg_addr                                    "0xB80082C4"
#define DC_MT_ADDCMD_LO_1_reg                                         0xB80082C4
#define DC_MT_ADDCMD_LO_1_inst_addr                                   "0x00B1"
#define DC_MT_ADDCMD_LO_1_inst                                        0x00B1
#define DC_MT_ADDCMD_LO_1_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_1_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_1_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_1_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_2                                             0x180082c8
#define DC_MT_ADDCMD_LO_2_reg_addr                                    "0xB80082C8"
#define DC_MT_ADDCMD_LO_2_reg                                         0xB80082C8
#define DC_MT_ADDCMD_LO_2_inst_addr                                   "0x00B2"
#define DC_MT_ADDCMD_LO_2_inst                                        0x00B2
#define DC_MT_ADDCMD_LO_2_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_2_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_2_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_2_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_3                                             0x180082cc
#define DC_MT_ADDCMD_LO_3_reg_addr                                    "0xB80082CC"
#define DC_MT_ADDCMD_LO_3_reg                                         0xB80082CC
#define DC_MT_ADDCMD_LO_3_inst_addr                                   "0x00B3"
#define DC_MT_ADDCMD_LO_3_inst                                        0x00B3
#define DC_MT_ADDCMD_LO_3_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_3_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_3_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_3_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_4                                             0x180082d0
#define DC_MT_ADDCMD_LO_4_reg_addr                                    "0xB80082D0"
#define DC_MT_ADDCMD_LO_4_reg                                         0xB80082D0
#define DC_MT_ADDCMD_LO_4_inst_addr                                   "0x00B4"
#define DC_MT_ADDCMD_LO_4_inst                                        0x00B4
#define DC_MT_ADDCMD_LO_4_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_4_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_4_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_4_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_5                                             0x180082d4
#define DC_MT_ADDCMD_LO_5_reg_addr                                    "0xB80082D4"
#define DC_MT_ADDCMD_LO_5_reg                                         0xB80082D4
#define DC_MT_ADDCMD_LO_5_inst_addr                                   "0x00B5"
#define DC_MT_ADDCMD_LO_5_inst                                        0x00B5
#define DC_MT_ADDCMD_LO_5_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_5_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_5_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_5_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_6                                             0x180082d8
#define DC_MT_ADDCMD_LO_6_reg_addr                                    "0xB80082D8"
#define DC_MT_ADDCMD_LO_6_reg                                         0xB80082D8
#define DC_MT_ADDCMD_LO_6_inst_addr                                   "0x00B6"
#define DC_MT_ADDCMD_LO_6_inst                                        0x00B6
#define DC_MT_ADDCMD_LO_6_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_6_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_6_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_6_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define DC_MT_ADDCMD_LO_7                                             0x180082dc
#define DC_MT_ADDCMD_LO_7_reg_addr                                    "0xB80082DC"
#define DC_MT_ADDCMD_LO_7_reg                                         0xB80082DC
#define DC_MT_ADDCMD_LO_7_inst_addr                                   "0x00B7"
#define DC_MT_ADDCMD_LO_7_inst                                        0x00B7
#define DC_MT_ADDCMD_LO_7_addcmd_shift                                (0)
#define DC_MT_ADDCMD_LO_7_addcmd_mask                                 (0xFFFFFFFF)
#define DC_MT_ADDCMD_LO_7_addcmd(data)                                (0xFFFFFFFF&(data))
#define DC_MT_ADDCMD_LO_7_get_addcmd(data)                            (0xFFFFFFFF&(data))

#define SB0_ARB_CR                                                    0x1801c000
#define SB0_ARB_CR_reg_addr                                           "0xB801C000"
#define SB0_ARB_CR_reg                                                0xB801C000
#define SB0_ARB_CR_inst_addr                                          "0x0000"
#define SB0_ARB_CR_inst                                               0x0000
#define SB0_ARB_CR_dec_mode_shift                                     (31)
#define SB0_ARB_CR_cnt_src_sel_shift                                  (16)
#define SB0_ARB_CR_time_step_shift                                    (12)
#define SB0_ARB_CR_arb_en_shift                                       (0)
#define SB0_ARB_CR_dec_mode_mask                                      (0x80000000)
#define SB0_ARB_CR_cnt_src_sel_mask                                   (0x00070000)
#define SB0_ARB_CR_time_step_mask                                     (0x0000F000)
#define SB0_ARB_CR_arb_en_mask                                        (0x00000007)
#define SB0_ARB_CR_dec_mode(data)                                     (0x80000000&((data)<<31))
#define SB0_ARB_CR_cnt_src_sel(data)                                  (0x00070000&((data)<<16))
#define SB0_ARB_CR_time_step(data)                                    (0x0000F000&((data)<<12))
#define SB0_ARB_CR_arb_en(data)                                       (0x00000007&(data))
#define SB0_ARB_CR_get_dec_mode(data)                                 ((0x80000000&(data))>>31)
#define SB0_ARB_CR_get_cnt_src_sel(data)                              ((0x00070000&(data))>>16)
#define SB0_ARB_CR_get_time_step(data)                                ((0x0000F000&(data))>>12)
#define SB0_ARB_CR_get_arb_en(data)                                   (0x00000007&(data))

#define SB0_LATCNT_CR1                                                0x1801c010
#define SB0_LATCNT_CR1_reg_addr                                       "0xB801C010"
#define SB0_LATCNT_CR1_reg                                            0xB801C010
#define SB0_LATCNT_CR1_inst_addr                                      "0x0004"
#define SB0_LATCNT_CR1_inst                                           0x0004
#define SB0_LATCNT_CR1_vdec_latcnt_end_shift                          (16)
#define SB0_LATCNT_CR1_vdec_latcnt_beg_shift                          (0)
#define SB0_LATCNT_CR1_vdec_latcnt_end_mask                           (0x0FFF0000)
#define SB0_LATCNT_CR1_vdec_latcnt_beg_mask                           (0x00000FFF)
#define SB0_LATCNT_CR1_vdec_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR1_vdec_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB0_LATCNT_CR1_get_vdec_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR1_get_vdec_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB0_LATCNT_CR2                                                0x1801c014
#define SB0_LATCNT_CR2_reg_addr                                       "0xB801C014"
#define SB0_LATCNT_CR2_reg                                            0xB801C014
#define SB0_LATCNT_CR2_inst_addr                                      "0x0005"
#define SB0_LATCNT_CR2_inst                                           0x0005
#define SB0_LATCNT_CR2_dispcaps_latcnt_end_shift                      (16)
#define SB0_LATCNT_CR2_dispcaps_latcnt_beg_shift                      (0)
#define SB0_LATCNT_CR2_dispcaps_latcnt_end_mask                       (0x0FFF0000)
#define SB0_LATCNT_CR2_dispcaps_latcnt_beg_mask                       (0x00000FFF)
#define SB0_LATCNT_CR2_dispcaps_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR2_dispcaps_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB0_LATCNT_CR2_get_dispcaps_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR2_get_dispcaps_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB0_LATCNT_CR3                                                0x1801c018
#define SB0_LATCNT_CR3_reg_addr                                       "0xB801C018"
#define SB0_LATCNT_CR3_reg                                            0xB801C018
#define SB0_LATCNT_CR3_inst_addr                                      "0x0006"
#define SB0_LATCNT_CR3_inst                                           0x0006
#define SB0_LATCNT_CR3_dispcapm_latcnt_end_shift                      (16)
#define SB0_LATCNT_CR3_dispcapm_latcnt_beg_shift                      (0)
#define SB0_LATCNT_CR3_dispcapm_latcnt_end_mask                       (0x0FFF0000)
#define SB0_LATCNT_CR3_dispcapm_latcnt_beg_mask                       (0x00000FFF)
#define SB0_LATCNT_CR3_dispcapm_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB0_LATCNT_CR3_dispcapm_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB0_LATCNT_CR3_get_dispcapm_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB0_LATCNT_CR3_get_dispcapm_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB0_WDRR_CR1                                                  0x1801c01c
#define SB0_WDRR_CR1_reg_addr                                         "0xB801C01C"
#define SB0_WDRR_CR1_reg                                              0xB801C01C
#define SB0_WDRR_CR1_inst_addr                                        "0x0007"
#define SB0_WDRR_CR1_inst                                             0x0007
#define SB0_WDRR_CR1_vdec_credit_val_shift                            (16)
#define SB0_WDRR_CR1_vdec_deficit_val_shift                           (8)
#define SB0_WDRR_CR1_vdec_elapse_val_shift                            (0)
#define SB0_WDRR_CR1_vdec_credit_val_mask                             (0x0FFF0000)
#define SB0_WDRR_CR1_vdec_deficit_val_mask                            (0x0000FF00)
#define SB0_WDRR_CR1_vdec_elapse_val_mask                             (0x000000FF)
#define SB0_WDRR_CR1_vdec_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR1_vdec_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR1_vdec_elapse_val(data)                            (0x000000FF&(data))
#define SB0_WDRR_CR1_get_vdec_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR1_get_vdec_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR1_get_vdec_elapse_val(data)                        (0x000000FF&(data))

#define SB0_WDRR_CR2                                                  0x1801c020
#define SB0_WDRR_CR2_reg_addr                                         "0xB801C020"
#define SB0_WDRR_CR2_reg                                              0xB801C020
#define SB0_WDRR_CR2_inst_addr                                        "0x0008"
#define SB0_WDRR_CR2_inst                                             0x0008
#define SB0_WDRR_CR2_dispcaps_credit_val_shift                        (16)
#define SB0_WDRR_CR2_dispcaps_deficit_val_shift                       (8)
#define SB0_WDRR_CR2_dispcaps_elapse_val_shift                        (0)
#define SB0_WDRR_CR2_dispcaps_credit_val_mask                         (0x0FFF0000)
#define SB0_WDRR_CR2_dispcaps_deficit_val_mask                        (0x0000FF00)
#define SB0_WDRR_CR2_dispcaps_elapse_val_mask                         (0x000000FF)
#define SB0_WDRR_CR2_dispcaps_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR2_dispcaps_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR2_dispcaps_elapse_val(data)                        (0x000000FF&(data))
#define SB0_WDRR_CR2_get_dispcaps_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR2_get_dispcaps_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR2_get_dispcaps_elapse_val(data)                    (0x000000FF&(data))

#define SB0_WDRR_CR3                                                  0x1801c024
#define SB0_WDRR_CR3_reg_addr                                         "0xB801C024"
#define SB0_WDRR_CR3_reg                                              0xB801C024
#define SB0_WDRR_CR3_inst_addr                                        "0x0009"
#define SB0_WDRR_CR3_inst                                             0x0009
#define SB0_WDRR_CR3_dispcapm_credit_val_shift                        (16)
#define SB0_WDRR_CR3_dispcapm_deficit_val_shift                       (8)
#define SB0_WDRR_CR3_dispcapm_elapse_val_shift                        (0)
#define SB0_WDRR_CR3_dispcapm_credit_val_mask                         (0x0FFF0000)
#define SB0_WDRR_CR3_dispcapm_deficit_val_mask                        (0x0000FF00)
#define SB0_WDRR_CR3_dispcapm_elapse_val_mask                         (0x000000FF)
#define SB0_WDRR_CR3_dispcapm_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB0_WDRR_CR3_dispcapm_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB0_WDRR_CR3_dispcapm_elapse_val(data)                        (0x000000FF&(data))
#define SB0_WDRR_CR3_get_dispcapm_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB0_WDRR_CR3_get_dispcapm_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB0_WDRR_CR3_get_dispcapm_elapse_val(data)                    (0x000000FF&(data))

#define SB0_ARB_CNTR_SET1                                             0x1801c028
#define SB0_ARB_CNTR_SET1_reg_addr                                    "0xB801C028"
#define SB0_ARB_CNTR_SET1_reg                                         0xB801C028
#define SB0_ARB_CNTR_SET1_inst_addr                                   "0x000A"
#define SB0_ARB_CNTR_SET1_inst                                        0x000A
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set_shift                     (31)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_shift                         (16)
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val_shift                      (0)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set_mask                      (0x80000000)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_mask                          (0x0FFF0000)
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val_mask                       (0x00000FFF)
#define SB0_ARB_CNTR_SET1_vdec_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET1_vdec_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET1_vdec_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET1_get_vdec_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET1_get_vdec_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET1_get_vdec_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB0_ARB_CNTR_SET2                                             0x1801c02c
#define SB0_ARB_CNTR_SET2_reg_addr                                    "0xB801C02C"
#define SB0_ARB_CNTR_SET2_reg                                         0xB801C02C
#define SB0_ARB_CNTR_SET2_inst_addr                                   "0x000B"
#define SB0_ARB_CNTR_SET2_inst                                        0x000B
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val_set_shift                 (31)
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val_shift                     (16)
#define SB0_ARB_CNTR_SET2_dispcaps_low_lvl_val_shift                  (0)
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val_set_mask                  (0x80000000)
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val_mask                      (0x0FFF0000)
#define SB0_ARB_CNTR_SET2_dispcaps_low_lvl_val_mask                   (0x00000FFF)
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET2_dispcaps_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET2_dispcaps_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET2_get_dispcaps_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET2_get_dispcaps_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET2_get_dispcaps_low_lvl_val(data)              (0x00000FFF&(data))

#define SB0_ARB_CNTR_SET3                                             0x1801c030
#define SB0_ARB_CNTR_SET3_reg_addr                                    "0xB801C030"
#define SB0_ARB_CNTR_SET3_reg                                         0xB801C030
#define SB0_ARB_CNTR_SET3_inst_addr                                   "0x000C"
#define SB0_ARB_CNTR_SET3_inst                                        0x000C
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val_set_shift                 (31)
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val_shift                     (16)
#define SB0_ARB_CNTR_SET3_dispcapm_low_lvl_val_shift                  (0)
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val_set_mask                  (0x80000000)
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val_mask                      (0x0FFF0000)
#define SB0_ARB_CNTR_SET3_dispcapm_low_lvl_val_mask                   (0x00000FFF)
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB0_ARB_CNTR_SET3_dispcapm_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB0_ARB_CNTR_SET3_dispcapm_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB0_ARB_CNTR_SET3_get_dispcapm_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB0_ARB_CNTR_SET3_get_dispcapm_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB0_ARB_CNTR_SET3_get_dispcapm_low_lvl_val(data)              (0x00000FFF&(data))

#define SB0_REQ_CR                                                    0x1801c040
#define SB0_REQ_CR_reg_addr                                           "0xB801C040"
#define SB0_REQ_CR_reg                                                0xB801C040
#define SB0_REQ_CR_inst_addr                                          "0x0010"
#define SB0_REQ_CR_inst                                               0x0010
#define SB0_REQ_CR_max_count_shift                                    (16)
#define SB0_REQ_CR_off_time_shift                                     (0)
#define SB0_REQ_CR_max_count_mask                                     (0x000F0000)
#define SB0_REQ_CR_off_time_mask                                      (0x000000FF)
#define SB0_REQ_CR_max_count(data)                                    (0x000F0000&((data)<<16))
#define SB0_REQ_CR_off_time(data)                                     (0x000000FF&(data))
#define SB0_REQ_CR_get_max_count(data)                                ((0x000F0000&(data))>>16)
#define SB0_REQ_CR_get_off_time(data)                                 (0x000000FF&(data))

#define SB0_ARB_SR1                                                   0x1801c050
#define SB0_ARB_SR1_reg_addr                                          "0xB801C050"
#define SB0_ARB_SR1_reg                                               0xB801C050
#define SB0_ARB_SR1_inst_addr                                         "0x0014"
#define SB0_ARB_SR1_inst                                              0x0014
#define SB0_ARB_SR1_sb_req_shift                                      (19)
#define SB0_ARB_SR1_sb_gnt_shift                                      (16)
#define SB0_ARB_SR1_win_latcnt_shift                                  (0)
#define SB0_ARB_SR1_sb_req_mask                                       (0x00380000)
#define SB0_ARB_SR1_sb_gnt_mask                                       (0x00070000)
#define SB0_ARB_SR1_win_latcnt_mask                                   (0x00000FFF)
#define SB0_ARB_SR1_sb_req(data)                                      (0x00380000&((data)<<19))
#define SB0_ARB_SR1_sb_gnt(data)                                      (0x00070000&((data)<<16))
#define SB0_ARB_SR1_win_latcnt(data)                                  (0x00000FFF&(data))
#define SB0_ARB_SR1_get_sb_req(data)                                  ((0x00380000&(data))>>19)
#define SB0_ARB_SR1_get_sb_gnt(data)                                  ((0x00070000&(data))>>16)
#define SB0_ARB_SR1_get_win_latcnt(data)                              (0x00000FFF&(data))

#define SB0_ARB_SR2                                                   0x1801c054
#define SB0_ARB_SR2_reg_addr                                          "0xB801C054"
#define SB0_ARB_SR2_reg                                               0xB801C054
#define SB0_ARB_SR2_inst_addr                                         "0x0015"
#define SB0_ARB_SR2_inst                                              0x0015
#define SB0_ARB_SR2_low_lvl_ie_shift                                  (16)
#define SB0_ARB_SR2_low_lvl_ip_shift                                  (0)
#define SB0_ARB_SR2_low_lvl_ie_mask                                   (0x00070000)
#define SB0_ARB_SR2_low_lvl_ip_mask                                   (0x00000007)
#define SB0_ARB_SR2_low_lvl_ie(data)                                  (0x00070000&((data)<<16))
#define SB0_ARB_SR2_low_lvl_ip(data)                                  (0x00000007&(data))
#define SB0_ARB_SR2_get_low_lvl_ie(data)                              ((0x00070000&(data))>>16)
#define SB0_ARB_SR2_get_low_lvl_ip(data)                              (0x00000007&(data))

#define SB3_ARB_CR                                                    0x1801c100
#define SB3_ARB_CR_reg_addr                                           "0xB801C100"
#define SB3_ARB_CR_reg                                                0xB801C100
#define SB3_ARB_CR_inst_addr                                          "0x0040"
#define SB3_ARB_CR_inst                                               0x0040
#define SB3_ARB_CR_dec_mode_shift                                     (31)
#define SB3_ARB_CR_cnt_src_sel_shift                                  (16)
#define SB3_ARB_CR_time_step_shift                                    (12)
#define SB3_ARB_CR_arb_en_shift                                       (0)
#define SB3_ARB_CR_dec_mode_mask                                      (0x80000000)
#define SB3_ARB_CR_cnt_src_sel_mask                                   (0x01FF0000)
#define SB3_ARB_CR_time_step_mask                                     (0x0000F000)
#define SB3_ARB_CR_arb_en_mask                                        (0x000003FF)
#define SB3_ARB_CR_dec_mode(data)                                     (0x80000000&((data)<<31))
#define SB3_ARB_CR_cnt_src_sel(data)                                  (0x01FF0000&((data)<<16))
#define SB3_ARB_CR_time_step(data)                                    (0x0000F000&((data)<<12))
#define SB3_ARB_CR_arb_en(data)                                       (0x000003FF&(data))
#define SB3_ARB_CR_get_dec_mode(data)                                 ((0x80000000&(data))>>31)
#define SB3_ARB_CR_get_cnt_src_sel(data)                              ((0x01FF0000&(data))>>16)
#define SB3_ARB_CR_get_time_step(data)                                ((0x0000F000&(data))>>12)
#define SB3_ARB_CR_get_arb_en(data)                                   (0x000003FF&(data))

#define SB3_LATCNT_CR1                                                0x1801c110
#define SB3_LATCNT_CR1_reg_addr                                       "0xB801C110"
#define SB3_LATCNT_CR1_reg                                            0xB801C110
#define SB3_LATCNT_CR1_inst_addr                                      "0x0044"
#define SB3_LATCNT_CR1_inst                                           0x0044
#define SB3_LATCNT_CR1_xcdim_latcnt_end_shift                         (16)
#define SB3_LATCNT_CR1_xcdim_latcnt_beg_shift                         (0)
#define SB3_LATCNT_CR1_xcdim_latcnt_end_mask                          (0x0FFF0000)
#define SB3_LATCNT_CR1_xcdim_latcnt_beg_mask                          (0x00000FFF)
#define SB3_LATCNT_CR1_xcdim_latcnt_end(data)                         (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR1_xcdim_latcnt_beg(data)                         (0x00000FFF&(data))
#define SB3_LATCNT_CR1_get_xcdim_latcnt_end(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR1_get_xcdim_latcnt_beg(data)                     (0x00000FFF&(data))

#define SB3_LATCNT_CR2                                                0x1801c114
#define SB3_LATCNT_CR2_reg_addr                                       "0xB801C114"
#define SB3_LATCNT_CR2_reg                                            0xB801C114
#define SB3_LATCNT_CR2_inst_addr                                      "0x0045"
#define SB3_LATCNT_CR2_inst                                           0x0045
#define SB3_LATCNT_CR2_bmposd_latcnt_end_shift                        (16)
#define SB3_LATCNT_CR2_bmposd_latcnt_beg_shift                        (0)
#define SB3_LATCNT_CR2_bmposd_latcnt_end_mask                         (0x0FFF0000)
#define SB3_LATCNT_CR2_bmposd_latcnt_beg_mask                         (0x00000FFF)
#define SB3_LATCNT_CR2_bmposd_latcnt_end(data)                        (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR2_bmposd_latcnt_beg(data)                        (0x00000FFF&(data))
#define SB3_LATCNT_CR2_get_bmposd_latcnt_end(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR2_get_bmposd_latcnt_beg(data)                    (0x00000FFF&(data))

#define SB3_LATCNT_CR3                                                0x1801c118
#define SB3_LATCNT_CR3_reg_addr                                       "0xB801C118"
#define SB3_LATCNT_CR3_reg                                            0xB801C118
#define SB3_LATCNT_CR3_inst_addr                                      "0x0046"
#define SB3_LATCNT_CR3_inst                                           0x0046
#define SB3_LATCNT_CR3_disdisps_latcnt_end_shift                      (16)
#define SB3_LATCNT_CR3_disdisps_latcnt_beg_shift                      (0)
#define SB3_LATCNT_CR3_disdisps_latcnt_end_mask                       (0x0FFF0000)
#define SB3_LATCNT_CR3_disdisps_latcnt_beg_mask                       (0x00000FFF)
#define SB3_LATCNT_CR3_disdisps_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR3_disdisps_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB3_LATCNT_CR3_get_disdisps_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR3_get_disdisps_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB3_LATCNT_CR4                                                0x1801c11c
#define SB3_LATCNT_CR4_reg_addr                                       "0xB801C11C"
#define SB3_LATCNT_CR4_reg                                            0xB801C11C
#define SB3_LATCNT_CR4_inst_addr                                      "0x0047"
#define SB3_LATCNT_CR4_inst                                           0x0047
#define SB3_LATCNT_CR4_l2d2_latcnt_end_shift                          (16)
#define SB3_LATCNT_CR4_l2d2_latcnt_beg_shift                          (0)
#define SB3_LATCNT_CR4_l2d2_latcnt_end_mask                           (0x0FFF0000)
#define SB3_LATCNT_CR4_l2d2_latcnt_beg_mask                           (0x00000FFF)
#define SB3_LATCNT_CR4_l2d2_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR4_l2d2_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB3_LATCNT_CR4_get_l2d2_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR4_get_l2d2_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB3_LATCNT_CR5                                                0x1801c120
#define SB3_LATCNT_CR5_reg_addr                                       "0xB801C120"
#define SB3_LATCNT_CR5_reg                                            0xB801C120
#define SB3_LATCNT_CR5_inst_addr                                      "0x0048"
#define SB3_LATCNT_CR5_inst                                           0x0048
#define SB3_LATCNT_CR5_disdispm_latcnt_end_shift                      (16)
#define SB3_LATCNT_CR5_disdispm_latcnt_beg_shift                      (0)
#define SB3_LATCNT_CR5_disdispm_latcnt_end_mask                       (0x0FFF0000)
#define SB3_LATCNT_CR5_disdispm_latcnt_beg_mask                       (0x00000FFF)
#define SB3_LATCNT_CR5_disdispm_latcnt_end(data)                      (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR5_disdispm_latcnt_beg(data)                      (0x00000FFF&(data))
#define SB3_LATCNT_CR5_get_disdispm_latcnt_end(data)                  ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR5_get_disdispm_latcnt_beg(data)                  (0x00000FFF&(data))

#define SB3_LATCNT_CR6                                                0x1801c124
#define SB3_LATCNT_CR6_reg_addr                                       "0xB801C124"
#define SB3_LATCNT_CR6_reg                                            0xB801C124
#define SB3_LATCNT_CR6_inst_addr                                      "0x0049"
#define SB3_LATCNT_CR6_inst                                           0x0049
#define SB3_LATCNT_CR6_idma_latcnt_end_shift                          (16)
#define SB3_LATCNT_CR6_idma_latcnt_beg_shift                          (0)
#define SB3_LATCNT_CR6_idma_latcnt_end_mask                           (0x0FFF0000)
#define SB3_LATCNT_CR6_idma_latcnt_beg_mask                           (0x00000FFF)
#define SB3_LATCNT_CR6_idma_latcnt_end(data)                          (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR6_idma_latcnt_beg(data)                          (0x00000FFF&(data))
#define SB3_LATCNT_CR6_get_idma_latcnt_end(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR6_get_idma_latcnt_beg(data)                      (0x00000FFF&(data))

#define SB3_LATCNT_CR7                                                0x1801c128
#define SB3_LATCNT_CR7_reg_addr                                       "0xB801C128"
#define SB3_LATCNT_CR7_reg                                            0xB801C128
#define SB3_LATCNT_CR7_inst_addr                                      "0x004A"
#define SB3_LATCNT_CR7_inst                                           0x004A
#define SB3_LATCNT_CR7_gibiwr_latcnt_end_shift                        (16)
#define SB3_LATCNT_CR7_gibiwr_latcnt_beg_shift                        (0)
#define SB3_LATCNT_CR7_gibiwr_latcnt_end_mask                         (0x0FFF0000)
#define SB3_LATCNT_CR7_gibiwr_latcnt_beg_mask                         (0x00000FFF)
#define SB3_LATCNT_CR7_gibiwr_latcnt_end(data)                        (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR7_gibiwr_latcnt_beg(data)                        (0x00000FFF&(data))
#define SB3_LATCNT_CR7_get_gibiwr_latcnt_end(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR7_get_gibiwr_latcnt_beg(data)                    (0x00000FFF&(data))

#define SB3_LATCNT_CR8                                                0x1801c12c
#define SB3_LATCNT_CR8_reg_addr                                       "0xB801C12C"
#define SB3_LATCNT_CR8_reg                                            0xB801C12C
#define SB3_LATCNT_CR8_inst_addr                                      "0x004B"
#define SB3_LATCNT_CR8_inst                                           0x004B
#define SB3_LATCNT_CR8_mvd_latcnt_end_shift                           (16)
#define SB3_LATCNT_CR8_mvd_latcnt_beg_shift                           (0)
#define SB3_LATCNT_CR8_mvd_latcnt_end_mask                            (0x0FFF0000)
#define SB3_LATCNT_CR8_mvd_latcnt_beg_mask                            (0x00000FFF)
#define SB3_LATCNT_CR8_mvd_latcnt_end(data)                           (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR8_mvd_latcnt_beg(data)                           (0x00000FFF&(data))
#define SB3_LATCNT_CR8_get_mvd_latcnt_end(data)                       ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR8_get_mvd_latcnt_beg(data)                       (0x00000FFF&(data))

#define SB3_LATCNT_CR9                                                0x1801c130
#define SB3_LATCNT_CR9_reg_addr                                       "0xB801C130"
#define SB3_LATCNT_CR9_reg                                            0xB801C130
#define SB3_LATCNT_CR9_inst_addr                                      "0x004C"
#define SB3_LATCNT_CR9_inst                                           0x004C
#define SB3_LATCNT_CR9_gibird_latcnt_end_shift                        (16)
#define SB3_LATCNT_CR9_gibird_latcnt_beg_shift                        (0)
#define SB3_LATCNT_CR9_gibird_latcnt_end_mask                         (0x0FFF0000)
#define SB3_LATCNT_CR9_gibird_latcnt_beg_mask                         (0x00000FFF)
#define SB3_LATCNT_CR9_gibird_latcnt_end(data)                        (0x0FFF0000&((data)<<16))
#define SB3_LATCNT_CR9_gibird_latcnt_beg(data)                        (0x00000FFF&(data))
#define SB3_LATCNT_CR9_get_gibird_latcnt_end(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_LATCNT_CR9_get_gibird_latcnt_beg(data)                    (0x00000FFF&(data))

#define SB3_WDRR_CR1                                                  0x1801c140
#define SB3_WDRR_CR1_reg_addr                                         "0xB801C140"
#define SB3_WDRR_CR1_reg                                              0xB801C140
#define SB3_WDRR_CR1_inst_addr                                        "0x0050"
#define SB3_WDRR_CR1_inst                                             0x0050
#define SB3_WDRR_CR1_xcdim_credit_val_shift                           (16)
#define SB3_WDRR_CR1_xcdim_deficit_val_shift                          (8)
#define SB3_WDRR_CR1_xcdim_elapse_val_shift                           (0)
#define SB3_WDRR_CR1_xcdim_credit_val_mask                            (0x0FFF0000)
#define SB3_WDRR_CR1_xcdim_deficit_val_mask                           (0x0000FF00)
#define SB3_WDRR_CR1_xcdim_elapse_val_mask                            (0x000000FF)
#define SB3_WDRR_CR1_xcdim_credit_val(data)                           (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR1_xcdim_deficit_val(data)                          (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR1_xcdim_elapse_val(data)                           (0x000000FF&(data))
#define SB3_WDRR_CR1_get_xcdim_credit_val(data)                       ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR1_get_xcdim_deficit_val(data)                      ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR1_get_xcdim_elapse_val(data)                       (0x000000FF&(data))

#define SB3_WDRR_CR2                                                  0x1801c144
#define SB3_WDRR_CR2_reg_addr                                         "0xB801C144"
#define SB3_WDRR_CR2_reg                                              0xB801C144
#define SB3_WDRR_CR2_inst_addr                                        "0x0051"
#define SB3_WDRR_CR2_inst                                             0x0051
#define SB3_WDRR_CR2_bmposd_credit_val_shift                          (16)
#define SB3_WDRR_CR2_bmposd_deficit_val_shift                         (8)
#define SB3_WDRR_CR2_bmposd_elapse_val_shift                          (0)
#define SB3_WDRR_CR2_bmposd_credit_val_mask                           (0x0FFF0000)
#define SB3_WDRR_CR2_bmposd_deficit_val_mask                          (0x0000FF00)
#define SB3_WDRR_CR2_bmposd_elapse_val_mask                           (0x000000FF)
#define SB3_WDRR_CR2_bmposd_credit_val(data)                          (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR2_bmposd_deficit_val(data)                         (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR2_bmposd_elapse_val(data)                          (0x000000FF&(data))
#define SB3_WDRR_CR2_get_bmposd_credit_val(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR2_get_bmposd_deficit_val(data)                     ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR2_get_bmposd_elapse_val(data)                      (0x000000FF&(data))

#define SB3_WDRR_CR3                                                  0x1801c148
#define SB3_WDRR_CR3_reg_addr                                         "0xB801C148"
#define SB3_WDRR_CR3_reg                                              0xB801C148
#define SB3_WDRR_CR3_inst_addr                                        "0x0052"
#define SB3_WDRR_CR3_inst                                             0x0052
#define SB3_WDRR_CR3_disdisps_credit_val_shift                        (16)
#define SB3_WDRR_CR3_disdisps_deficit_val_shift                       (8)
#define SB3_WDRR_CR3_disdisps_elapse_val_shift                        (0)
#define SB3_WDRR_CR3_disdisps_credit_val_mask                         (0x0FFF0000)
#define SB3_WDRR_CR3_disdisps_deficit_val_mask                        (0x0000FF00)
#define SB3_WDRR_CR3_disdisps_elapse_val_mask                         (0x000000FF)
#define SB3_WDRR_CR3_disdisps_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR3_disdisps_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR3_disdisps_elapse_val(data)                        (0x000000FF&(data))
#define SB3_WDRR_CR3_get_disdisps_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR3_get_disdisps_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR3_get_disdisps_elapse_val(data)                    (0x000000FF&(data))

#define SB3_WDRR_CR4                                                  0x1801c14c
#define SB3_WDRR_CR4_reg_addr                                         "0xB801C14C"
#define SB3_WDRR_CR4_reg                                              0xB801C14C
#define SB3_WDRR_CR4_inst_addr                                        "0x0053"
#define SB3_WDRR_CR4_inst                                             0x0053
#define SB3_WDRR_CR4_l2d2_credit_val_shift                            (16)
#define SB3_WDRR_CR4_l2d2_deficit_val_shift                           (8)
#define SB3_WDRR_CR4_l2d2_elapse_val_shift                            (0)
#define SB3_WDRR_CR4_l2d2_credit_val_mask                             (0x0FFF0000)
#define SB3_WDRR_CR4_l2d2_deficit_val_mask                            (0x0000FF00)
#define SB3_WDRR_CR4_l2d2_elapse_val_mask                             (0x000000FF)
#define SB3_WDRR_CR4_l2d2_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR4_l2d2_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR4_l2d2_elapse_val(data)                            (0x000000FF&(data))
#define SB3_WDRR_CR4_get_l2d2_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR4_get_l2d2_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR4_get_l2d2_elapse_val(data)                        (0x000000FF&(data))

#define SB3_WDRR_CR5                                                  0x1801c150
#define SB3_WDRR_CR5_reg_addr                                         "0xB801C150"
#define SB3_WDRR_CR5_reg                                              0xB801C150
#define SB3_WDRR_CR5_inst_addr                                        "0x0054"
#define SB3_WDRR_CR5_inst                                             0x0054
#define SB3_WDRR_CR5_disdispm_credit_val_shift                        (16)
#define SB3_WDRR_CR5_disdispm_deficit_val_shift                       (8)
#define SB3_WDRR_CR5_disdispm_elapse_val_shift                        (0)
#define SB3_WDRR_CR5_disdispm_credit_val_mask                         (0x0FFF0000)
#define SB3_WDRR_CR5_disdispm_deficit_val_mask                        (0x0000FF00)
#define SB3_WDRR_CR5_disdispm_elapse_val_mask                         (0x000000FF)
#define SB3_WDRR_CR5_disdispm_credit_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR5_disdispm_deficit_val(data)                       (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR5_disdispm_elapse_val(data)                        (0x000000FF&(data))
#define SB3_WDRR_CR5_get_disdispm_credit_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR5_get_disdispm_deficit_val(data)                   ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR5_get_disdispm_elapse_val(data)                    (0x000000FF&(data))

#define SB3_WDRR_CR6                                                  0x1801c154
#define SB3_WDRR_CR6_reg_addr                                         "0xB801C154"
#define SB3_WDRR_CR6_reg                                              0xB801C154
#define SB3_WDRR_CR6_inst_addr                                        "0x0055"
#define SB3_WDRR_CR6_inst                                             0x0055
#define SB3_WDRR_CR6_idma_credit_val_shift                            (16)
#define SB3_WDRR_CR6_idma_deficit_val_shift                           (8)
#define SB3_WDRR_CR6_idma_elapse_val_shift                            (0)
#define SB3_WDRR_CR6_idma_credit_val_mask                             (0x0FFF0000)
#define SB3_WDRR_CR6_idma_deficit_val_mask                            (0x0000FF00)
#define SB3_WDRR_CR6_idma_elapse_val_mask                             (0x000000FF)
#define SB3_WDRR_CR6_idma_credit_val(data)                            (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR6_idma_deficit_val(data)                           (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR6_idma_elapse_val(data)                            (0x000000FF&(data))
#define SB3_WDRR_CR6_get_idma_credit_val(data)                        ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR6_get_idma_deficit_val(data)                       ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR6_get_idma_elapse_val(data)                        (0x000000FF&(data))

#define SB3_WDRR_CR7                                                  0x1801c158
#define SB3_WDRR_CR7_reg_addr                                         "0xB801C158"
#define SB3_WDRR_CR7_reg                                              0xB801C158
#define SB3_WDRR_CR7_inst_addr                                        "0x0056"
#define SB3_WDRR_CR7_inst                                             0x0056
#define SB3_WDRR_CR7_gibiwr_credit_val_shift                          (16)
#define SB3_WDRR_CR7_gibiwr_deficit_val_shift                         (8)
#define SB3_WDRR_CR7_gibiwr_elapse_val_shift                          (0)
#define SB3_WDRR_CR7_gibiwr_credit_val_mask                           (0x0FFF0000)
#define SB3_WDRR_CR7_gibiwr_deficit_val_mask                          (0x0000FF00)
#define SB3_WDRR_CR7_gibiwr_elapse_val_mask                           (0x000000FF)
#define SB3_WDRR_CR7_gibiwr_credit_val(data)                          (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR7_gibiwr_deficit_val(data)                         (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR7_gibiwr_elapse_val(data)                          (0x000000FF&(data))
#define SB3_WDRR_CR7_get_gibiwr_credit_val(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR7_get_gibiwr_deficit_val(data)                     ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR7_get_gibiwr_elapse_val(data)                      (0x000000FF&(data))

#define SB3_WDRR_CR8                                                  0x1801c15c
#define SB3_WDRR_CR8_reg_addr                                         "0xB801C15C"
#define SB3_WDRR_CR8_reg                                              0xB801C15C
#define SB3_WDRR_CR8_inst_addr                                        "0x0057"
#define SB3_WDRR_CR8_inst                                             0x0057
#define SB3_WDRR_CR8_mvd_credit_val_shift                             (16)
#define SB3_WDRR_CR8_mvd_deficit_val_shift                            (8)
#define SB3_WDRR_CR8_mvd_elapse_val_shift                             (0)
#define SB3_WDRR_CR8_mvd_credit_val_mask                              (0x0FFF0000)
#define SB3_WDRR_CR8_mvd_deficit_val_mask                             (0x0000FF00)
#define SB3_WDRR_CR8_mvd_elapse_val_mask                              (0x000000FF)
#define SB3_WDRR_CR8_mvd_credit_val(data)                             (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR8_mvd_deficit_val(data)                            (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR8_mvd_elapse_val(data)                             (0x000000FF&(data))
#define SB3_WDRR_CR8_get_mvd_credit_val(data)                         ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR8_get_mvd_deficit_val(data)                        ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR8_get_mvd_elapse_val(data)                         (0x000000FF&(data))

#define SB3_WDRR_CR9                                                  0x1801c160
#define SB3_WDRR_CR9_reg_addr                                         "0xB801C160"
#define SB3_WDRR_CR9_reg                                              0xB801C160
#define SB3_WDRR_CR9_inst_addr                                        "0x0058"
#define SB3_WDRR_CR9_inst                                             0x0058
#define SB3_WDRR_CR9_gibird_credit_val_shift                          (16)
#define SB3_WDRR_CR9_gibird_deficit_val_shift                         (8)
#define SB3_WDRR_CR9_gibird_elapse_val_shift                          (0)
#define SB3_WDRR_CR9_gibird_credit_val_mask                           (0x0FFF0000)
#define SB3_WDRR_CR9_gibird_deficit_val_mask                          (0x0000FF00)
#define SB3_WDRR_CR9_gibird_elapse_val_mask                           (0x000000FF)
#define SB3_WDRR_CR9_gibird_credit_val(data)                          (0x0FFF0000&((data)<<16))
#define SB3_WDRR_CR9_gibird_deficit_val(data)                         (0x0000FF00&((data)<<8))
#define SB3_WDRR_CR9_gibird_elapse_val(data)                          (0x000000FF&(data))
#define SB3_WDRR_CR9_get_gibird_credit_val(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_WDRR_CR9_get_gibird_deficit_val(data)                     ((0x0000FF00&(data))>>8)
#define SB3_WDRR_CR9_get_gibird_elapse_val(data)                      (0x000000FF&(data))

#define SB3_ARB_CNTR_SET1                                             0x1801c170
#define SB3_ARB_CNTR_SET1_reg_addr                                    "0xB801C170"
#define SB3_ARB_CNTR_SET1_reg                                         0xB801C170
#define SB3_ARB_CNTR_SET1_inst_addr                                   "0x005C"
#define SB3_ARB_CNTR_SET1_inst                                        0x005C
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set_shift                    (31)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_shift                        (16)
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val_shift                     (0)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set_mask                     (0x80000000)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_mask                         (0x0FFF0000)
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val_mask                      (0x00000FFF)
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val_set(data)                    (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET1_xcdim_cntr_val(data)                        (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET1_xcdim_low_lvl_val(data)                     (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET1_get_xcdim_cntr_val_set(data)                ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET1_get_xcdim_cntr_val(data)                    ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET1_get_xcdim_low_lvl_val(data)                 (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET2                                             0x1801c174
#define SB3_ARB_CNTR_SET2_reg_addr                                    "0xB801C174"
#define SB3_ARB_CNTR_SET2_reg                                         0xB801C174
#define SB3_ARB_CNTR_SET2_inst_addr                                   "0x005D"
#define SB3_ARB_CNTR_SET2_inst                                        0x005D
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val_set_shift                   (31)
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val_shift                       (16)
#define SB3_ARB_CNTR_SET2_bmposd_low_lvl_val_shift                    (0)
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val_set_mask                    (0x80000000)
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val_mask                        (0x0FFF0000)
#define SB3_ARB_CNTR_SET2_bmposd_low_lvl_val_mask                     (0x00000FFF)
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val_set(data)                   (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET2_bmposd_cntr_val(data)                       (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET2_bmposd_low_lvl_val(data)                    (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET2_get_bmposd_cntr_val_set(data)               ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET2_get_bmposd_cntr_val(data)                   ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET2_get_bmposd_low_lvl_val(data)                (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET3                                             0x1801c178
#define SB3_ARB_CNTR_SET3_reg_addr                                    "0xB801C178"
#define SB3_ARB_CNTR_SET3_reg                                         0xB801C178
#define SB3_ARB_CNTR_SET3_inst_addr                                   "0x005E"
#define SB3_ARB_CNTR_SET3_inst                                        0x005E
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set_shift                 (31)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_shift                     (16)
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val_shift                  (0)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set_mask                  (0x80000000)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_mask                      (0x0FFF0000)
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val_mask                   (0x00000FFF)
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET3_disdisps_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET3_disdisps_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET3_get_disdisps_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET3_get_disdisps_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET3_get_disdisps_low_lvl_val(data)              (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET4                                             0x1801c17c
#define SB3_ARB_CNTR_SET4_reg_addr                                    "0xB801C17C"
#define SB3_ARB_CNTR_SET4_reg                                         0xB801C17C
#define SB3_ARB_CNTR_SET4_inst_addr                                   "0x005F"
#define SB3_ARB_CNTR_SET4_inst                                        0x005F
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val_set_shift                     (31)
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val_shift                         (16)
#define SB3_ARB_CNTR_SET4_l2d2_low_lvl_val_shift                      (0)
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val_set_mask                      (0x80000000)
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val_mask                          (0x0FFF0000)
#define SB3_ARB_CNTR_SET4_l2d2_low_lvl_val_mask                       (0x00000FFF)
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET4_l2d2_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET4_l2d2_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET4_get_l2d2_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET4_get_l2d2_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET4_get_l2d2_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET5                                             0x1801c180
#define SB3_ARB_CNTR_SET5_reg_addr                                    "0xB801C180"
#define SB3_ARB_CNTR_SET5_reg                                         0xB801C180
#define SB3_ARB_CNTR_SET5_inst_addr                                   "0x0060"
#define SB3_ARB_CNTR_SET5_inst                                        0x0060
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val_set_shift                 (31)
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val_shift                     (16)
#define SB3_ARB_CNTR_SET5_disdispm_low_lvl_val_shift                  (0)
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val_set_mask                  (0x80000000)
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val_mask                      (0x0FFF0000)
#define SB3_ARB_CNTR_SET5_disdispm_low_lvl_val_mask                   (0x00000FFF)
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val_set(data)                 (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET5_disdispm_cntr_val(data)                     (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET5_disdispm_low_lvl_val(data)                  (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET5_get_disdispm_cntr_val_set(data)             ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET5_get_disdispm_cntr_val(data)                 ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET5_get_disdispm_low_lvl_val(data)              (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET6                                             0x1801c184
#define SB3_ARB_CNTR_SET6_reg_addr                                    "0xB801C184"
#define SB3_ARB_CNTR_SET6_reg                                         0xB801C184
#define SB3_ARB_CNTR_SET6_inst_addr                                   "0x0061"
#define SB3_ARB_CNTR_SET6_inst                                        0x0061
#define SB3_ARB_CNTR_SET6_idma_cntr_val_set_shift                     (31)
#define SB3_ARB_CNTR_SET6_idma_cntr_val_shift                         (16)
#define SB3_ARB_CNTR_SET6_idma_low_lvl_val_shift                      (0)
#define SB3_ARB_CNTR_SET6_idma_cntr_val_set_mask                      (0x80000000)
#define SB3_ARB_CNTR_SET6_idma_cntr_val_mask                          (0x0FFF0000)
#define SB3_ARB_CNTR_SET6_idma_low_lvl_val_mask                       (0x00000FFF)
#define SB3_ARB_CNTR_SET6_idma_cntr_val_set(data)                     (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET6_idma_cntr_val(data)                         (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET6_idma_low_lvl_val(data)                      (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET6_get_idma_cntr_val_set(data)                 ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET6_get_idma_cntr_val(data)                     ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET6_get_idma_low_lvl_val(data)                  (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET7                                             0x1801c188
#define SB3_ARB_CNTR_SET7_reg_addr                                    "0xB801C188"
#define SB3_ARB_CNTR_SET7_reg                                         0xB801C188
#define SB3_ARB_CNTR_SET7_inst_addr                                   "0x0062"
#define SB3_ARB_CNTR_SET7_inst                                        0x0062
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val_set_shift                   (31)
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val_shift                       (16)
#define SB3_ARB_CNTR_SET7_gibiwr_low_lvl_val_shift                    (0)
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val_set_mask                    (0x80000000)
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val_mask                        (0x0FFF0000)
#define SB3_ARB_CNTR_SET7_gibiwr_low_lvl_val_mask                     (0x00000FFF)
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val_set(data)                   (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET7_gibiwr_cntr_val(data)                       (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET7_gibiwr_low_lvl_val(data)                    (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET7_get_gibiwr_cntr_val_set(data)               ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET7_get_gibiwr_cntr_val(data)                   ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET7_get_gibiwr_low_lvl_val(data)                (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET8                                             0x1801c18c
#define SB3_ARB_CNTR_SET8_reg_addr                                    "0xB801C18C"
#define SB3_ARB_CNTR_SET8_reg                                         0xB801C18C
#define SB3_ARB_CNTR_SET8_inst_addr                                   "0x0063"
#define SB3_ARB_CNTR_SET8_inst                                        0x0063
#define SB3_ARB_CNTR_SET8_mvd_cntr_val_set_shift                      (31)
#define SB3_ARB_CNTR_SET8_mvd_cntr_val_shift                          (16)
#define SB3_ARB_CNTR_SET8_mvd_low_lvl_val_shift                       (0)
#define SB3_ARB_CNTR_SET8_mvd_cntr_val_set_mask                       (0x80000000)
#define SB3_ARB_CNTR_SET8_mvd_cntr_val_mask                           (0x0FFF0000)
#define SB3_ARB_CNTR_SET8_mvd_low_lvl_val_mask                        (0x00000FFF)
#define SB3_ARB_CNTR_SET8_mvd_cntr_val_set(data)                      (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET8_mvd_cntr_val(data)                          (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET8_mvd_low_lvl_val(data)                       (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET8_get_mvd_cntr_val_set(data)                  ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET8_get_mvd_cntr_val(data)                      ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET8_get_mvd_low_lvl_val(data)                   (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET9                                             0x1801c190
#define SB3_ARB_CNTR_SET9_reg_addr                                    "0xB801C190"
#define SB3_ARB_CNTR_SET9_reg                                         0xB801C190
#define SB3_ARB_CNTR_SET9_inst_addr                                   "0x0064"
#define SB3_ARB_CNTR_SET9_inst                                        0x0064
#define SB3_ARB_CNTR_SET9_gibird_cntr_val_set_shift                   (31)
#define SB3_ARB_CNTR_SET9_gibird_cntr_val_shift                       (16)
#define SB3_ARB_CNTR_SET9_gibird_low_lvl_val_shift                    (0)
#define SB3_ARB_CNTR_SET9_gibird_cntr_val_set_mask                    (0x80000000)
#define SB3_ARB_CNTR_SET9_gibird_cntr_val_mask                        (0x0FFF0000)
#define SB3_ARB_CNTR_SET9_gibird_low_lvl_val_mask                     (0x00000FFF)
#define SB3_ARB_CNTR_SET9_gibird_cntr_val_set(data)                   (0x80000000&((data)<<31))
#define SB3_ARB_CNTR_SET9_gibird_cntr_val(data)                       (0x0FFF0000&((data)<<16))
#define SB3_ARB_CNTR_SET9_gibird_low_lvl_val(data)                    (0x00000FFF&(data))
#define SB3_ARB_CNTR_SET9_get_gibird_cntr_val_set(data)               ((0x80000000&(data))>>31)
#define SB3_ARB_CNTR_SET9_get_gibird_cntr_val(data)                   ((0x0FFF0000&(data))>>16)
#define SB3_ARB_CNTR_SET9_get_gibird_low_lvl_val(data)                (0x00000FFF&(data))

#define SB3_ARB_CNTR_SET10                                            0x1801c194
#define SB3_ARB_CNTR_SET10_reg_addr                                   "0xB801C194"
#define SB3_ARB_CNTR_SET10_reg                                        0xB801C194
#define SB3_ARB_CNTR_SET10_inst_addr                                  "0x0065"
#define SB3_ARB_CNTR_SET10_inst                                       0x0065
#define SB3_ARB_CNTR_SET10_resv_reg_shift                             (0)
#define SB3_ARB_CNTR_SET10_resv_reg_mask                              (0x00000007)
#define SB3_ARB_CNTR_SET10_resv_reg(data)                             (0x00000007&(data))
#define SB3_ARB_CNTR_SET10_get_resv_reg(data)                         (0x00000007&(data))

#define SB3_REQ_CR                                                    0x1801c1a0
#define SB3_REQ_CR_reg_addr                                           "0xB801C1A0"
#define SB3_REQ_CR_reg                                                0xB801C1A0
#define SB3_REQ_CR_inst_addr                                          "0x0068"
#define SB3_REQ_CR_inst                                               0x0068
#define SB3_REQ_CR_max_count_shift                                    (16)
#define SB3_REQ_CR_off_time_shift                                     (0)
#define SB3_REQ_CR_max_count_mask                                     (0x000F0000)
#define SB3_REQ_CR_off_time_mask                                      (0x000000FF)
#define SB3_REQ_CR_max_count(data)                                    (0x000F0000&((data)<<16))
#define SB3_REQ_CR_off_time(data)                                     (0x000000FF&(data))
#define SB3_REQ_CR_get_max_count(data)                                ((0x000F0000&(data))>>16)
#define SB3_REQ_CR_get_off_time(data)                                 (0x000000FF&(data))

#define SB3_ARB_SR1                                                   0x1801c1b0
#define SB3_ARB_SR1_reg_addr                                          "0xB801C1B0"
#define SB3_ARB_SR1_reg                                               0xB801C1B0
#define SB3_ARB_SR1_inst_addr                                         "0x006C"
#define SB3_ARB_SR1_inst                                              0x006C
#define SB3_ARB_SR1_sb_req_shift                                      (22)
#define SB3_ARB_SR1_sb_gnt_shift                                      (12)
#define SB3_ARB_SR1_win_latcnt_shift                                  (0)
#define SB3_ARB_SR1_sb_req_mask                                       (0xFFC00000)
#define SB3_ARB_SR1_sb_gnt_mask                                       (0x003FF000)
#define SB3_ARB_SR1_win_latcnt_mask                                   (0x00000FFF)
#define SB3_ARB_SR1_sb_req(data)                                      (0xFFC00000&((data)<<22))
#define SB3_ARB_SR1_sb_gnt(data)                                      (0x003FF000&((data)<<12))
#define SB3_ARB_SR1_win_latcnt(data)                                  (0x00000FFF&(data))
#define SB3_ARB_SR1_get_sb_req(data)                                  ((0xFFC00000&(data))>>22)
#define SB3_ARB_SR1_get_sb_gnt(data)                                  ((0x003FF000&(data))>>12)
#define SB3_ARB_SR1_get_win_latcnt(data)                              (0x00000FFF&(data))

#define SB3_ARB_SR2                                                   0x1801c1b4
#define SB3_ARB_SR2_reg_addr                                          "0xB801C1B4"
#define SB3_ARB_SR2_reg                                               0xB801C1B4
#define SB3_ARB_SR2_inst_addr                                         "0x006D"
#define SB3_ARB_SR2_inst                                              0x006D
#define SB3_ARB_SR2_low_lvl_ie_shift                                  (16)
#define SB3_ARB_SR2_low_lvl_ip_shift                                  (0)
#define SB3_ARB_SR2_low_lvl_ie_mask                                   (0x01FF0000)
#define SB3_ARB_SR2_low_lvl_ip_mask                                   (0x000001FF)
#define SB3_ARB_SR2_low_lvl_ie(data)                                  (0x01FF0000&((data)<<16))
#define SB3_ARB_SR2_low_lvl_ip(data)                                  (0x000001FF&(data))
#define SB3_ARB_SR2_get_low_lvl_ie(data)                              ((0x01FF0000&(data))>>16)
#define SB3_ARB_SR2_get_low_lvl_ip(data)                              (0x000001FF&(data))
#endif
