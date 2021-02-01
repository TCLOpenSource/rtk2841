// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:777                    Version flow no.:1.1.14
#ifndef _HDMI_STBY_REG_H_INCLUDED_
#define _HDMI_STBY_REG_H_INCLUDED_

//#define  _HDMI_STBY_USE_STRUCT
#ifdef _HDMI_STBY_USE_STRUCT

typedef struct
{
    unsigned int    cec_mode:2;
    unsigned int    test_mode_pad_data:1;
    unsigned int    test_mode_pad_en:1;
    unsigned int    logical_addr:4;
    unsigned int    timer_div:8;
    unsigned int    pre_div:8;
    unsigned int    unreg_ack_en:1;
    unsigned int    dummy1800d400_6_5:2;
    unsigned int    pad_rise_time:5;
}CEC_cr0;

typedef struct
{
    unsigned int    cec_pad_in:1;
    unsigned int    reserved_0:20;
    unsigned int    wt_cnt:6;
    unsigned int    lattest:1;
    unsigned int    retry_no:4;
}CEC_rtcr0;

typedef struct
{
    unsigned int    broadcast_addr:1;
    unsigned int    reserved_0:15;
    unsigned int    rx_en:1;
    unsigned int    rx_rst:1;
    unsigned int    rx_continuous:1;
    unsigned int    rx_int_en:1;
    unsigned int    init_addr:4;
    unsigned int    rx_eom:1;
    unsigned int    rx_int:1;
    unsigned int    rx_fifo_ov:1;
    unsigned int    rx_fifo_cnt:5;
}CEC_rxcr0;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    tx_addr_en:1;
    unsigned int    tx_addr:4;
    unsigned int    tx_en:1;
    unsigned int    tx_rst:1;
    unsigned int    tx_continuous:1;
    unsigned int    tx_int_en:1;
    unsigned int    dest_addr:4;
    unsigned int    tx_eom:1;
    unsigned int    tx_int:1;
    unsigned int    tx_fifo_ud:1;
    unsigned int    tx_fifo_cnt:5;
}CEC_txcr0;

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    tx_add_cnt:1;
    unsigned int    rx_sub_cnt:1;
    unsigned int    fifo_cnt:5;
}CEC_txdr0;

typedef struct
{
    unsigned int    tx_fifo_0:8;
    unsigned int    tx_fifo_1:8;
    unsigned int    tx_fifo_2:8;
    unsigned int    tx_fifo_3:8;
}CEC_txdr1;

typedef struct
{
    unsigned int    tx_fifo_4:8;
    unsigned int    tx_fifo_5:8;
    unsigned int    tx_fifo_6:8;
    unsigned int    tx_fifo_7:8;
}CEC_txdr2;

typedef struct
{
    unsigned int    tx_fifo_8:8;
    unsigned int    tx_fifo_9:8;
    unsigned int    tx_fifo_a:8;
    unsigned int    tx_fifo_b:8;
}CEC_txdr3;

typedef struct
{
    unsigned int    tx_fifo_c:8;
    unsigned int    tx_fifo_d:8;
    unsigned int    tx_fifo_e:8;
    unsigned int    tx_fifo_f:8;
}CEC_txdr4;

typedef struct
{
    unsigned int    rx_fifo_0:8;
    unsigned int    rx_fifo_1:8;
    unsigned int    rx_fifo_2:8;
    unsigned int    rx_fifo_3:8;
}CEC_rxdr1;

typedef struct
{
    unsigned int    rx_fifo_4:8;
    unsigned int    rx_fifo_5:8;
    unsigned int    rx_fifo_6:8;
    unsigned int    rx_fifo_7:8;
}CEC_rxdr2;

typedef struct
{
    unsigned int    rx_fifo_8:8;
    unsigned int    rx_fifo_9:8;
    unsigned int    rx_fifo_a:8;
    unsigned int    rx_fifo_b:8;
}CEC_rxdr3;

typedef struct
{
    unsigned int    rx_fifo_c:8;
    unsigned int    rx_fifo_d:8;
    unsigned int    rx_fifo_e:8;
    unsigned int    rx_fifo_f:8;
}CEC_rxdr4;

typedef struct
{
    unsigned int    rx_start_low:8;
    unsigned int    rx_start_period:8;
    unsigned int    rx_data_sample:8;
    unsigned int    rx_data_period:8;
}CEC_rxtcr0;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    tx_start_low:8;
    unsigned int    tx_start_high:8;
}CEC_txtcr0;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    tx_data_low:8;
    unsigned int    tx_data_01:8;
    unsigned int    tx_data_high:8;
}CEC_txtcr1;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_01:8;
}GDI_cec_compare_opcode_01;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    send_opcode_01:8;
}GDI_cec_send_opcode_01;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    reserved_1:6;
    unsigned int    operand_number_01:2;
}GDI_cec_send_operand_number_01;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_01:8;
}GDI_cec_operand_01;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_02:8;
}GDI_cec_operand_02;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_03:8;
}GDI_cec_operand_03;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_02:8;
}GDI_cec_compare_opcode_02;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    send_opcode_02:8;
}GDI_cec_send_opcode_02;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    reserved_1:6;
    unsigned int    operand_number_02:2;
}GDI_cec_send_operand_number_02;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_04:8;
}GDI_cec_operand_04;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_05:8;
}GDI_cec_operand_05;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_06:8;
}GDI_cec_operand_06;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_03:8;
}GDI_cec_compare_opcode_03;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    send_opcode_03:8;
}GDI_cec_send_opcode_03;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    reserved_1:6;
    unsigned int    operand_number_03:2;
}GDI_cec_send_operand_number_03;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_07:8;
}GDI_cec_operand_07;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_08:8;
}GDI_cec_operand_08;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_09:8;
}GDI_cec_operand_09;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_04:8;
}GDI_cec_compare_opcode_04;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    send_opcode_04:8;
}GDI_cec_send_opcode_04;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    reserved_1:6;
    unsigned int    operand_number_04:2;
}GDI_cec_send_operand_number_04;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_10:8;
}GDI_cec_operand_10;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_11:8;
}GDI_cec_operand_11;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    operand_12:8;
}GDI_cec_operand_12;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_05:8;
}GDI_cec_compare_opcode_05;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_06:8;
}GDI_cec_compare_opcode_06;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_07:8;
}GDI_cec_compare_opcode_07;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_08:8;
}GDI_cec_compare_opcode_08;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_09:8;
}GDI_cec_compare_opcode_09;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_10:8;
}GDI_cec_compare_opcode_10;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_11:8;
}GDI_cec_compare_opcode_11;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_12:8;
}GDI_cec_compare_opcode_12;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_13:8;
}GDI_cec_compare_opcode_13;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_14:8;
}GDI_cec_compare_opcode_14;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    compare_opcode_15:8;
}GDI_cec_compare_opcode_15;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    en_compare_opcode_15:1;
    unsigned int    en_compare_opcode_14:1;
    unsigned int    en_compare_opcode_13:1;
    unsigned int    en_compare_opcode_12:1;
    unsigned int    en_compare_opcode_11:1;
    unsigned int    en_compare_opcode_10:1;
    unsigned int    en_compare_opcode_09:1;
    unsigned int    en_compare_opcode_08:1;
    unsigned int    en_compare_opcode_07:1;
    unsigned int    en_compare_opcode_06:1;
    unsigned int    en_compare_opcode_05:1;
    unsigned int    en_compare_opcode_04:1;
    unsigned int    en_compare_opcode_03:1;
    unsigned int    en_compare_opcode_02:1;
    unsigned int    en_compare_opcode_01:1;
}GDI_cec_opcode_enable;

typedef struct
{
    unsigned int    hdmi_dummy_cr0:21;
    unsigned int    debug_select_for_psm:2;
    unsigned int    irq_select:1;
    unsigned int    sram_bist_clock_source_select:1;
    unsigned int    vgip_input_select:1;
    unsigned int    cp_48_mode:1;
    unsigned int    aux_entst:1;
    unsigned int    cec_entst:1;
    unsigned int    reserved_0:1;
    unsigned int    debug_output_select_1_0:2;
}HDMI_dummy_cr0;

typedef struct
{
    unsigned int    hdmi_dummy_cr1:32;
}HDMI_dummy_cr1;

typedef struct
{
    unsigned int    max_cmd_period:8;
    unsigned int    rdata_cnt:8;
    unsigned int    wr_ack_cnt:8;
    unsigned int    rd_ack_cnt:8;
}RBUS_wrap_ctrl0;

typedef struct
{
    unsigned int    mcuwr_start:8;
    unsigned int    mcuwr_end:8;
    unsigned int    mcurd_start:8;
    unsigned int    mcurd_end:8;
}RBUS_wrap_ctrl1;

typedef struct
{
    unsigned int    mcuwr_inc_start:8;
    unsigned int    mcuwr_inc_end:8;
    unsigned int    mcurd_inc_start:8;
    unsigned int    mcurd_inc_end:8;
}RBUS_wrap_ctrl2;

typedef struct
{
    unsigned int    hdmi_dummy_cr2:32;
}HDMI_dummy_cr2;

typedef struct
{
    unsigned int    hdmi_dummy_cr3:32;
}HDMI_dummy_cr3;

typedef struct
{
    unsigned int    reserved_0:23;
    unsigned int    gdi_power_saving_en:1;
    unsigned int    reserved_1:4;
    unsigned int    cec_irq_en:1;
    unsigned int    cec_irq_inv:1;
    unsigned int    reserved_2:2;
}GDI_power_saving_mode;

typedef struct
{
    unsigned int    irq_pending:1;
    unsigned int    tmds_clk_status:1;
    unsigned int    reserved_0:3;
    unsigned int    cec_msg_status_01:1;
    unsigned int    cec_msg_status_02:1;
    unsigned int    reserved_1:10;
    unsigned int    irq_by_tmds_clk:1;
    unsigned int    reserved_2:3;
    unsigned int    irq_by_cec_receive_cmd_01:1;
    unsigned int    irq_by_cec_receive_cmd_02:1;
    unsigned int    irq_by_cec_receivespecial_cmd:1;
    unsigned int    reserved_3:8;
}GDI_intcr_01;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    dclk_cnt_start:12;
    unsigned int    reserved_1:4;
    unsigned int    dclk_cnt_end:12;
}GDI_tmdsclk_setting_00;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    target_for_maximum_clk_counter:12;
    unsigned int    reserved_1:4;
    unsigned int    target_for_minimum_clk_counter:12;
}GDI_tmdsclk_setting_01;

typedef struct
{
    unsigned int    reserved_0:18;
    unsigned int    hdmi_clksel:2;
    unsigned int    clk_counter_err_threshold:4;
    unsigned int    clk_counter_debounce:8;
}GDI_tmdsclk_setting_02;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    cec_driver_en_ctrl:1;
    unsigned int    cec_driver_en_ctrl_by_sw:1;
}GDI_cec_control;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    en_tmds_chg_irq:1;
    unsigned int    tmds_chg_irq:1;
}GDI_tmdsclk_freq_change_irg;
#endif


#define CEC_CR0                                                       0x1800d400
#define CEC_CR0_reg_addr                                              "0xb800d400"
#define CEC_CR0_reg                                                   0xb800d400
#define CEC_CR0_inst_addr                                             "0x0100"
#define CEC_CR0_inst                                                  0x0100
#define CEC_CR0_cec_mode_shift                                        (30)
#define CEC_CR0_test_mode_pad_data_shift                              (29)
#define CEC_CR0_test_mode_pad_en_shift                                (28)
#define CEC_CR0_logical_addr_shift                                    (24)
#define CEC_CR0_timer_div_shift                                       (16)
#define CEC_CR0_pre_div_shift                                         (8)
#define CEC_CR0_unreg_ack_en_shift                                    (7)
#define CEC_CR0_dummy1800d400_6_5_shift                               (5)
#define CEC_CR0_pad_rise_time_shift                                   (0)
#define CEC_CR0_cec_mode_mask                                         (0xC0000000)
#define CEC_CR0_test_mode_pad_data_mask                               (0x20000000)
#define CEC_CR0_test_mode_pad_en_mask                                 (0x10000000)
#define CEC_CR0_logical_addr_mask                                     (0x0F000000)
#define CEC_CR0_timer_div_mask                                        (0x00FF0000)
#define CEC_CR0_pre_div_mask                                          (0x0000FF00)
#define CEC_CR0_unreg_ack_en_mask                                     (0x00000080)
#define CEC_CR0_dummy1800d400_6_5_mask                                (0x00000060)
#define CEC_CR0_pad_rise_time_mask                                    (0x0000001F)
#define CEC_CR0_cec_mode(data)                                        (0xC0000000&((data)<<30))
#define CEC_CR0_test_mode_pad_data(data)                              (0x20000000&((data)<<29))
#define CEC_CR0_test_mode_pad_en(data)                                (0x10000000&((data)<<28))
#define CEC_CR0_logical_addr(data)                                    (0x0F000000&((data)<<24))
#define CEC_CR0_timer_div(data)                                       (0x00FF0000&((data)<<16))
#define CEC_CR0_pre_div(data)                                         (0x0000FF00&((data)<<8))
#define CEC_CR0_unreg_ack_en(data)                                    (0x00000080&((data)<<7))
#define CEC_CR0_dummy1800d400_6_5(data)                               (0x00000060&((data)<<5))
#define CEC_CR0_pad_rise_time(data)                                   (0x0000001F&(data))
#define CEC_CR0_get_cec_mode(data)                                    ((0xC0000000&(data))>>30)
#define CEC_CR0_get_test_mode_pad_data(data)                          ((0x20000000&(data))>>29)
#define CEC_CR0_get_test_mode_pad_en(data)                            ((0x10000000&(data))>>28)
#define CEC_CR0_get_logical_addr(data)                                ((0x0F000000&(data))>>24)
#define CEC_CR0_get_timer_div(data)                                   ((0x00FF0000&(data))>>16)
#define CEC_CR0_get_pre_div(data)                                     ((0x0000FF00&(data))>>8)
#define CEC_CR0_get_unreg_ack_en(data)                                ((0x00000080&(data))>>7)
#define CEC_CR0_get_dummy1800d400_6_5(data)                           ((0x00000060&(data))>>5)
#define CEC_CR0_get_pad_rise_time(data)                               (0x0000001F&(data))


#define CEC_RTCR0                                                     0x1800d404
#define CEC_RTCR0_reg_addr                                            "0xb800d404"
#define CEC_RTCR0_reg                                                 0xb800d404
#define CEC_RTCR0_inst_addr                                           "0x0101"
#define CEC_RTCR0_inst                                                0x0101
#define CEC_RTCR0_cec_pad_in_shift                                    (31)
#define CEC_RTCR0_wt_cnt_shift                                        (5)
#define CEC_RTCR0_lattest_shift                                       (4)
#define CEC_RTCR0_retry_no_shift                                      (0)
#define CEC_RTCR0_cec_pad_in_mask                                     (0x80000000)
#define CEC_RTCR0_wt_cnt_mask                                         (0x000007E0)
#define CEC_RTCR0_lattest_mask                                        (0x00000010)
#define CEC_RTCR0_retry_no_mask                                       (0x0000000F)
#define CEC_RTCR0_cec_pad_in(data)                                    (0x80000000&((data)<<31))
#define CEC_RTCR0_wt_cnt(data)                                        (0x000007E0&((data)<<5))
#define CEC_RTCR0_lattest(data)                                       (0x00000010&((data)<<4))
#define CEC_RTCR0_retry_no(data)                                      (0x0000000F&(data))
#define CEC_RTCR0_get_cec_pad_in(data)                                ((0x80000000&(data))>>31)
#define CEC_RTCR0_get_wt_cnt(data)                                    ((0x000007E0&(data))>>5)
#define CEC_RTCR0_get_lattest(data)                                   ((0x00000010&(data))>>4)
#define CEC_RTCR0_get_retry_no(data)                                  (0x0000000F&(data))


#define CEC_RXCR0                                                     0x1800d408
#define CEC_RXCR0_reg_addr                                            "0xb800d408"
#define CEC_RXCR0_reg                                                 0xb800d408
#define CEC_RXCR0_inst_addr                                           "0x0102"
#define CEC_RXCR0_inst                                                0x0102
#define CEC_RXCR0_broadcast_addr_shift                                (31)
#define CEC_RXCR0_rx_en_shift                                         (15)
#define CEC_RXCR0_rx_rst_shift                                        (14)
#define CEC_RXCR0_rx_continuous_shift                                 (13)
#define CEC_RXCR0_rx_int_en_shift                                     (12)
#define CEC_RXCR0_init_addr_shift                                     (8)
#define CEC_RXCR0_rx_eom_shift                                        (7)
#define CEC_RXCR0_rx_int_shift                                        (6)
#define CEC_RXCR0_rx_fifo_ov_shift                                    (5)
#define CEC_RXCR0_rx_fifo_cnt_shift                                   (0)
#define CEC_RXCR0_broadcast_addr_mask                                 (0x80000000)
#define CEC_RXCR0_rx_en_mask                                          (0x00008000)
#define CEC_RXCR0_rx_rst_mask                                         (0x00004000)
#define CEC_RXCR0_rx_continuous_mask                                  (0x00002000)
#define CEC_RXCR0_rx_int_en_mask                                      (0x00001000)
#define CEC_RXCR0_init_addr_mask                                      (0x00000F00)
#define CEC_RXCR0_rx_eom_mask                                         (0x00000080)
#define CEC_RXCR0_rx_int_mask                                         (0x00000040)
#define CEC_RXCR0_rx_fifo_ov_mask                                     (0x00000020)
#define CEC_RXCR0_rx_fifo_cnt_mask                                    (0x0000001F)
#define CEC_RXCR0_broadcast_addr(data)                                (0x80000000&((data)<<31))
#define CEC_RXCR0_rx_en(data)                                         (0x00008000&((data)<<15))
#define CEC_RXCR0_rx_rst(data)                                        (0x00004000&((data)<<14))
#define CEC_RXCR0_rx_continuous(data)                                 (0x00002000&((data)<<13))
#define CEC_RXCR0_rx_int_en(data)                                     (0x00001000&((data)<<12))
#define CEC_RXCR0_init_addr(data)                                     (0x00000F00&((data)<<8))
#define CEC_RXCR0_rx_eom(data)                                        (0x00000080&((data)<<7))
#define CEC_RXCR0_rx_int(data)                                        (0x00000040&((data)<<6))
#define CEC_RXCR0_rx_fifo_ov(data)                                    (0x00000020&((data)<<5))
#define CEC_RXCR0_rx_fifo_cnt(data)                                   (0x0000001F&(data))
#define CEC_RXCR0_get_broadcast_addr(data)                            ((0x80000000&(data))>>31)
#define CEC_RXCR0_get_rx_en(data)                                     ((0x00008000&(data))>>15)
#define CEC_RXCR0_get_rx_rst(data)                                    ((0x00004000&(data))>>14)
#define CEC_RXCR0_get_rx_continuous(data)                             ((0x00002000&(data))>>13)
#define CEC_RXCR0_get_rx_int_en(data)                                 ((0x00001000&(data))>>12)
#define CEC_RXCR0_get_init_addr(data)                                 ((0x00000F00&(data))>>8)
#define CEC_RXCR0_get_rx_eom(data)                                    ((0x00000080&(data))>>7)
#define CEC_RXCR0_get_rx_int(data)                                    ((0x00000040&(data))>>6)
#define CEC_RXCR0_get_rx_fifo_ov(data)                                ((0x00000020&(data))>>5)
#define CEC_RXCR0_get_rx_fifo_cnt(data)                               (0x0000001F&(data))


#define CEC_TXCR0                                                     0x1800d40c
#define CEC_TXCR0_reg_addr                                            "0xb800d40c"
#define CEC_TXCR0_reg                                                 0xb800d40c
#define CEC_TXCR0_inst_addr                                           "0x0103"
#define CEC_TXCR0_inst                                                0x0103
#define CEC_TXCR0_tx_addr_en_shift                                    (20)
#define CEC_TXCR0_tx_addr_shift                                       (16)
#define CEC_TXCR0_tx_en_shift                                         (15)
#define CEC_TXCR0_tx_rst_shift                                        (14)
#define CEC_TXCR0_tx_continuous_shift                                 (13)
#define CEC_TXCR0_tx_int_en_shift                                     (12)
#define CEC_TXCR0_dest_addr_shift                                     (8)
#define CEC_TXCR0_tx_eom_shift                                        (7)
#define CEC_TXCR0_tx_int_shift                                        (6)
#define CEC_TXCR0_tx_fifo_ud_shift                                    (5)
#define CEC_TXCR0_tx_fifo_cnt_shift                                   (0)
#define CEC_TXCR0_tx_addr_en_mask                                     (0x00100000)
#define CEC_TXCR0_tx_addr_mask                                        (0x000F0000)
#define CEC_TXCR0_tx_en_mask                                          (0x00008000)
#define CEC_TXCR0_tx_rst_mask                                         (0x00004000)
#define CEC_TXCR0_tx_continuous_mask                                  (0x00002000)
#define CEC_TXCR0_tx_int_en_mask                                      (0x00001000)
#define CEC_TXCR0_dest_addr_mask                                      (0x00000F00)
#define CEC_TXCR0_tx_eom_mask                                         (0x00000080)
#define CEC_TXCR0_tx_int_mask                                         (0x00000040)
#define CEC_TXCR0_tx_fifo_ud_mask                                     (0x00000020)
#define CEC_TXCR0_tx_fifo_cnt_mask                                    (0x0000001F)
#define CEC_TXCR0_tx_addr_en(data)                                    (0x00100000&((data)<<20))
#define CEC_TXCR0_tx_addr(data)                                       (0x000F0000&((data)<<16))
#define CEC_TXCR0_tx_en(data)                                         (0x00008000&((data)<<15))
#define CEC_TXCR0_tx_rst(data)                                        (0x00004000&((data)<<14))
#define CEC_TXCR0_tx_continuous(data)                                 (0x00002000&((data)<<13))
#define CEC_TXCR0_tx_int_en(data)                                     (0x00001000&((data)<<12))
#define CEC_TXCR0_dest_addr(data)                                     (0x00000F00&((data)<<8))
#define CEC_TXCR0_tx_eom(data)                                        (0x00000080&((data)<<7))
#define CEC_TXCR0_tx_int(data)                                        (0x00000040&((data)<<6))
#define CEC_TXCR0_tx_fifo_ud(data)                                    (0x00000020&((data)<<5))
#define CEC_TXCR0_tx_fifo_cnt(data)                                   (0x0000001F&(data))
#define CEC_TXCR0_get_tx_addr_en(data)                                ((0x00100000&(data))>>20)
#define CEC_TXCR0_get_tx_addr(data)                                   ((0x000F0000&(data))>>16)
#define CEC_TXCR0_get_tx_en(data)                                     ((0x00008000&(data))>>15)
#define CEC_TXCR0_get_tx_rst(data)                                    ((0x00004000&(data))>>14)
#define CEC_TXCR0_get_tx_continuous(data)                             ((0x00002000&(data))>>13)
#define CEC_TXCR0_get_tx_int_en(data)                                 ((0x00001000&(data))>>12)
#define CEC_TXCR0_get_dest_addr(data)                                 ((0x00000F00&(data))>>8)
#define CEC_TXCR0_get_tx_eom(data)                                    ((0x00000080&(data))>>7)
#define CEC_TXCR0_get_tx_int(data)                                    ((0x00000040&(data))>>6)
#define CEC_TXCR0_get_tx_fifo_ud(data)                                ((0x00000020&(data))>>5)
#define CEC_TXCR0_get_tx_fifo_cnt(data)                               (0x0000001F&(data))


#define CEC_TXDR0                                                     0x1800d410
#define CEC_TXDR0_reg_addr                                            "0xb800d410"
#define CEC_TXDR0_reg                                                 0xb800d410
#define CEC_TXDR0_inst_addr                                           "0x0104"
#define CEC_TXDR0_inst                                                0x0104
#define CEC_TXDR0_tx_add_cnt_shift                                    (6)
#define CEC_TXDR0_rx_sub_cnt_shift                                    (5)
#define CEC_TXDR0_fifo_cnt_shift                                      (0)
#define CEC_TXDR0_tx_add_cnt_mask                                     (0x00000040)
#define CEC_TXDR0_rx_sub_cnt_mask                                     (0x00000020)
#define CEC_TXDR0_fifo_cnt_mask                                       (0x0000001F)
#define CEC_TXDR0_tx_add_cnt(data)                                    (0x00000040&((data)<<6))
#define CEC_TXDR0_rx_sub_cnt(data)                                    (0x00000020&((data)<<5))
#define CEC_TXDR0_fifo_cnt(data)                                      (0x0000001F&(data))
#define CEC_TXDR0_get_tx_add_cnt(data)                                ((0x00000040&(data))>>6)
#define CEC_TXDR0_get_rx_sub_cnt(data)                                ((0x00000020&(data))>>5)
#define CEC_TXDR0_get_fifo_cnt(data)                                  (0x0000001F&(data))


#define CEC_TXDR1                                                     0x1800d414
#define CEC_TXDR1_reg_addr                                            "0xb800d414"
#define CEC_TXDR1_reg                                                 0xb800d414
#define CEC_TXDR1_inst_addr                                           "0x0105"
#define CEC_TXDR1_inst                                                0x0105
#define CEC_TXDR1_tx_fifo_0_shift                                     (24)
#define CEC_TXDR1_tx_fifo_1_shift                                     (16)
#define CEC_TXDR1_tx_fifo_2_shift                                     (8)
#define CEC_TXDR1_tx_fifo_3_shift                                     (0)
#define CEC_TXDR1_tx_fifo_0_mask                                      (0xFF000000)
#define CEC_TXDR1_tx_fifo_1_mask                                      (0x00FF0000)
#define CEC_TXDR1_tx_fifo_2_mask                                      (0x0000FF00)
#define CEC_TXDR1_tx_fifo_3_mask                                      (0x000000FF)
#define CEC_TXDR1_tx_fifo_0(data)                                     (0xFF000000&((data)<<24))
#define CEC_TXDR1_tx_fifo_1(data)                                     (0x00FF0000&((data)<<16))
#define CEC_TXDR1_tx_fifo_2(data)                                     (0x0000FF00&((data)<<8))
#define CEC_TXDR1_tx_fifo_3(data)                                     (0x000000FF&(data))
#define CEC_TXDR1_get_tx_fifo_0(data)                                 ((0xFF000000&(data))>>24)
#define CEC_TXDR1_get_tx_fifo_1(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_TXDR1_get_tx_fifo_2(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_TXDR1_get_tx_fifo_3(data)                                 (0x000000FF&(data))


#define CEC_TXDR2                                                     0x1800d418
#define CEC_TXDR2_reg_addr                                            "0xb800d418"
#define CEC_TXDR2_reg                                                 0xb800d418
#define CEC_TXDR2_inst_addr                                           "0x0106"
#define CEC_TXDR2_inst                                                0x0106
#define CEC_TXDR2_tx_fifo_4_shift                                     (24)
#define CEC_TXDR2_tx_fifo_5_shift                                     (16)
#define CEC_TXDR2_tx_fifo_6_shift                                     (8)
#define CEC_TXDR2_tx_fifo_7_shift                                     (0)
#define CEC_TXDR2_tx_fifo_4_mask                                      (0xFF000000)
#define CEC_TXDR2_tx_fifo_5_mask                                      (0x00FF0000)
#define CEC_TXDR2_tx_fifo_6_mask                                      (0x0000FF00)
#define CEC_TXDR2_tx_fifo_7_mask                                      (0x000000FF)
#define CEC_TXDR2_tx_fifo_4(data)                                     (0xFF000000&((data)<<24))
#define CEC_TXDR2_tx_fifo_5(data)                                     (0x00FF0000&((data)<<16))
#define CEC_TXDR2_tx_fifo_6(data)                                     (0x0000FF00&((data)<<8))
#define CEC_TXDR2_tx_fifo_7(data)                                     (0x000000FF&(data))
#define CEC_TXDR2_get_tx_fifo_4(data)                                 ((0xFF000000&(data))>>24)
#define CEC_TXDR2_get_tx_fifo_5(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_TXDR2_get_tx_fifo_6(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_TXDR2_get_tx_fifo_7(data)                                 (0x000000FF&(data))


#define CEC_TXDR3                                                     0x1800d41c
#define CEC_TXDR3_reg_addr                                            "0xb800d41c"
#define CEC_TXDR3_reg                                                 0xb800d41c
#define CEC_TXDR3_inst_addr                                           "0x0107"
#define CEC_TXDR3_inst                                                0x0107
#define CEC_TXDR3_tx_fifo_8_shift                                     (24)
#define CEC_TXDR3_tx_fifo_9_shift                                     (16)
#define CEC_TXDR3_tx_fifo_a_shift                                     (8)
#define CEC_TXDR3_tx_fifo_b_shift                                     (0)
#define CEC_TXDR3_tx_fifo_8_mask                                      (0xFF000000)
#define CEC_TXDR3_tx_fifo_9_mask                                      (0x00FF0000)
#define CEC_TXDR3_tx_fifo_a_mask                                      (0x0000FF00)
#define CEC_TXDR3_tx_fifo_b_mask                                      (0x000000FF)
#define CEC_TXDR3_tx_fifo_8(data)                                     (0xFF000000&((data)<<24))
#define CEC_TXDR3_tx_fifo_9(data)                                     (0x00FF0000&((data)<<16))
#define CEC_TXDR3_tx_fifo_a(data)                                     (0x0000FF00&((data)<<8))
#define CEC_TXDR3_tx_fifo_b(data)                                     (0x000000FF&(data))
#define CEC_TXDR3_get_tx_fifo_8(data)                                 ((0xFF000000&(data))>>24)
#define CEC_TXDR3_get_tx_fifo_9(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_TXDR3_get_tx_fifo_a(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_TXDR3_get_tx_fifo_b(data)                                 (0x000000FF&(data))


#define CEC_TXDR4                                                     0x1800d420
#define CEC_TXDR4_reg_addr                                            "0xb800d420"
#define CEC_TXDR4_reg                                                 0xb800d420
#define CEC_TXDR4_inst_addr                                           "0x0108"
#define CEC_TXDR4_inst                                                0x0108
#define CEC_TXDR4_tx_fifo_c_shift                                     (24)
#define CEC_TXDR4_tx_fifo_d_shift                                     (16)
#define CEC_TXDR4_tx_fifo_e_shift                                     (8)
#define CEC_TXDR4_tx_fifo_f_shift                                     (0)
#define CEC_TXDR4_tx_fifo_c_mask                                      (0xFF000000)
#define CEC_TXDR4_tx_fifo_d_mask                                      (0x00FF0000)
#define CEC_TXDR4_tx_fifo_e_mask                                      (0x0000FF00)
#define CEC_TXDR4_tx_fifo_f_mask                                      (0x000000FF)
#define CEC_TXDR4_tx_fifo_c(data)                                     (0xFF000000&((data)<<24))
#define CEC_TXDR4_tx_fifo_d(data)                                     (0x00FF0000&((data)<<16))
#define CEC_TXDR4_tx_fifo_e(data)                                     (0x0000FF00&((data)<<8))
#define CEC_TXDR4_tx_fifo_f(data)                                     (0x000000FF&(data))
#define CEC_TXDR4_get_tx_fifo_c(data)                                 ((0xFF000000&(data))>>24)
#define CEC_TXDR4_get_tx_fifo_d(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_TXDR4_get_tx_fifo_e(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_TXDR4_get_tx_fifo_f(data)                                 (0x000000FF&(data))


#define CEC_RXDR1                                                     0x1800d424
#define CEC_RXDR1_reg_addr                                            "0xb800d424"
#define CEC_RXDR1_reg                                                 0xb800d424
#define CEC_RXDR1_inst_addr                                           "0x0109"
#define CEC_RXDR1_inst                                                0x0109
#define CEC_RXDR1_rx_fifo_0_shift                                     (24)
#define CEC_RXDR1_rx_fifo_1_shift                                     (16)
#define CEC_RXDR1_rx_fifo_2_shift                                     (8)
#define CEC_RXDR1_rx_fifo_3_shift                                     (0)
#define CEC_RXDR1_rx_fifo_0_mask                                      (0xFF000000)
#define CEC_RXDR1_rx_fifo_1_mask                                      (0x00FF0000)
#define CEC_RXDR1_rx_fifo_2_mask                                      (0x0000FF00)
#define CEC_RXDR1_rx_fifo_3_mask                                      (0x000000FF)
#define CEC_RXDR1_rx_fifo_0(data)                                     (0xFF000000&((data)<<24))
#define CEC_RXDR1_rx_fifo_1(data)                                     (0x00FF0000&((data)<<16))
#define CEC_RXDR1_rx_fifo_2(data)                                     (0x0000FF00&((data)<<8))
#define CEC_RXDR1_rx_fifo_3(data)                                     (0x000000FF&(data))
#define CEC_RXDR1_get_rx_fifo_0(data)                                 ((0xFF000000&(data))>>24)
#define CEC_RXDR1_get_rx_fifo_1(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_RXDR1_get_rx_fifo_2(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_RXDR1_get_rx_fifo_3(data)                                 (0x000000FF&(data))


#define CEC_RXDR2                                                     0x1800d428
#define CEC_RXDR2_reg_addr                                            "0xb800d428"
#define CEC_RXDR2_reg                                                 0xb800d428
#define CEC_RXDR2_inst_addr                                           "0x010A"
#define CEC_RXDR2_inst                                                0x010A
#define CEC_RXDR2_rx_fifo_4_shift                                     (24)
#define CEC_RXDR2_rx_fifo_5_shift                                     (16)
#define CEC_RXDR2_rx_fifo_6_shift                                     (8)
#define CEC_RXDR2_rx_fifo_7_shift                                     (0)
#define CEC_RXDR2_rx_fifo_4_mask                                      (0xFF000000)
#define CEC_RXDR2_rx_fifo_5_mask                                      (0x00FF0000)
#define CEC_RXDR2_rx_fifo_6_mask                                      (0x0000FF00)
#define CEC_RXDR2_rx_fifo_7_mask                                      (0x000000FF)
#define CEC_RXDR2_rx_fifo_4(data)                                     (0xFF000000&((data)<<24))
#define CEC_RXDR2_rx_fifo_5(data)                                     (0x00FF0000&((data)<<16))
#define CEC_RXDR2_rx_fifo_6(data)                                     (0x0000FF00&((data)<<8))
#define CEC_RXDR2_rx_fifo_7(data)                                     (0x000000FF&(data))
#define CEC_RXDR2_get_rx_fifo_4(data)                                 ((0xFF000000&(data))>>24)
#define CEC_RXDR2_get_rx_fifo_5(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_RXDR2_get_rx_fifo_6(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_RXDR2_get_rx_fifo_7(data)                                 (0x000000FF&(data))


#define CEC_RXDR3                                                     0x1800d42c
#define CEC_RXDR3_reg_addr                                            "0xb800d42c"
#define CEC_RXDR3_reg                                                 0xb800d42c
#define CEC_RXDR3_inst_addr                                           "0x010B"
#define CEC_RXDR3_inst                                                0x010B
#define CEC_RXDR3_rx_fifo_8_shift                                     (24)
#define CEC_RXDR3_rx_fifo_9_shift                                     (16)
#define CEC_RXDR3_rx_fifo_a_shift                                     (8)
#define CEC_RXDR3_rx_fifo_b_shift                                     (0)
#define CEC_RXDR3_rx_fifo_8_mask                                      (0xFF000000)
#define CEC_RXDR3_rx_fifo_9_mask                                      (0x00FF0000)
#define CEC_RXDR3_rx_fifo_a_mask                                      (0x0000FF00)
#define CEC_RXDR3_rx_fifo_b_mask                                      (0x000000FF)
#define CEC_RXDR3_rx_fifo_8(data)                                     (0xFF000000&((data)<<24))
#define CEC_RXDR3_rx_fifo_9(data)                                     (0x00FF0000&((data)<<16))
#define CEC_RXDR3_rx_fifo_a(data)                                     (0x0000FF00&((data)<<8))
#define CEC_RXDR3_rx_fifo_b(data)                                     (0x000000FF&(data))
#define CEC_RXDR3_get_rx_fifo_8(data)                                 ((0xFF000000&(data))>>24)
#define CEC_RXDR3_get_rx_fifo_9(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_RXDR3_get_rx_fifo_a(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_RXDR3_get_rx_fifo_b(data)                                 (0x000000FF&(data))


#define CEC_RXDR4                                                     0x1800d430
#define CEC_RXDR4_reg_addr                                            "0xb800d430"
#define CEC_RXDR4_reg                                                 0xb800d430
#define CEC_RXDR4_inst_addr                                           "0x010C"
#define CEC_RXDR4_inst                                                0x010C
#define CEC_RXDR4_rx_fifo_c_shift                                     (24)
#define CEC_RXDR4_rx_fifo_d_shift                                     (16)
#define CEC_RXDR4_rx_fifo_e_shift                                     (8)
#define CEC_RXDR4_rx_fifo_f_shift                                     (0)
#define CEC_RXDR4_rx_fifo_c_mask                                      (0xFF000000)
#define CEC_RXDR4_rx_fifo_d_mask                                      (0x00FF0000)
#define CEC_RXDR4_rx_fifo_e_mask                                      (0x0000FF00)
#define CEC_RXDR4_rx_fifo_f_mask                                      (0x000000FF)
#define CEC_RXDR4_rx_fifo_c(data)                                     (0xFF000000&((data)<<24))
#define CEC_RXDR4_rx_fifo_d(data)                                     (0x00FF0000&((data)<<16))
#define CEC_RXDR4_rx_fifo_e(data)                                     (0x0000FF00&((data)<<8))
#define CEC_RXDR4_rx_fifo_f(data)                                     (0x000000FF&(data))
#define CEC_RXDR4_get_rx_fifo_c(data)                                 ((0xFF000000&(data))>>24)
#define CEC_RXDR4_get_rx_fifo_d(data)                                 ((0x00FF0000&(data))>>16)
#define CEC_RXDR4_get_rx_fifo_e(data)                                 ((0x0000FF00&(data))>>8)
#define CEC_RXDR4_get_rx_fifo_f(data)                                 (0x000000FF&(data))


#define CEC_RXTCR0                                                    0x1800d434
#define CEC_RXTCR0_reg_addr                                           "0xb800d434"
#define CEC_RXTCR0_reg                                                0xb800d434
#define CEC_RXTCR0_inst_addr                                          "0x010D"
#define CEC_RXTCR0_inst                                               0x010D
#define CEC_RXTCR0_rx_start_low_shift                                 (24)
#define CEC_RXTCR0_rx_start_period_shift                              (16)
#define CEC_RXTCR0_rx_data_sample_shift                               (8)
#define CEC_RXTCR0_rx_data_period_shift                               (0)
#define CEC_RXTCR0_rx_start_low_mask                                  (0xFF000000)
#define CEC_RXTCR0_rx_start_period_mask                               (0x00FF0000)
#define CEC_RXTCR0_rx_data_sample_mask                                (0x0000FF00)
#define CEC_RXTCR0_rx_data_period_mask                                (0x000000FF)
#define CEC_RXTCR0_rx_start_low(data)                                 (0xFF000000&((data)<<24))
#define CEC_RXTCR0_rx_start_period(data)                              (0x00FF0000&((data)<<16))
#define CEC_RXTCR0_rx_data_sample(data)                               (0x0000FF00&((data)<<8))
#define CEC_RXTCR0_rx_data_period(data)                               (0x000000FF&(data))
#define CEC_RXTCR0_get_rx_start_low(data)                             ((0xFF000000&(data))>>24)
#define CEC_RXTCR0_get_rx_start_period(data)                          ((0x00FF0000&(data))>>16)
#define CEC_RXTCR0_get_rx_data_sample(data)                           ((0x0000FF00&(data))>>8)
#define CEC_RXTCR0_get_rx_data_period(data)                           (0x000000FF&(data))


#define CEC_TXTCR0                                                    0x1800d438
#define CEC_TXTCR0_reg_addr                                           "0xb800d438"
#define CEC_TXTCR0_reg                                                0xb800d438
#define CEC_TXTCR0_inst_addr                                          "0x010E"
#define CEC_TXTCR0_inst                                               0x010E
#define CEC_TXTCR0_tx_start_low_shift                                 (8)
#define CEC_TXTCR0_tx_start_high_shift                                (0)
#define CEC_TXTCR0_tx_start_low_mask                                  (0x0000FF00)
#define CEC_TXTCR0_tx_start_high_mask                                 (0x000000FF)
#define CEC_TXTCR0_tx_start_low(data)                                 (0x0000FF00&((data)<<8))
#define CEC_TXTCR0_tx_start_high(data)                                (0x000000FF&(data))
#define CEC_TXTCR0_get_tx_start_low(data)                             ((0x0000FF00&(data))>>8)
#define CEC_TXTCR0_get_tx_start_high(data)                            (0x000000FF&(data))


#define CEC_TXTCR1                                                    0x1800d43c
#define CEC_TXTCR1_reg_addr                                           "0xb800d43c"
#define CEC_TXTCR1_reg                                                0xb800d43c
#define CEC_TXTCR1_inst_addr                                          "0x010F"
#define CEC_TXTCR1_inst                                               0x010F
#define CEC_TXTCR1_tx_data_low_shift                                  (16)
#define CEC_TXTCR1_tx_data_01_shift                                   (8)
#define CEC_TXTCR1_tx_data_high_shift                                 (0)
#define CEC_TXTCR1_tx_data_low_mask                                   (0x00FF0000)
#define CEC_TXTCR1_tx_data_01_mask                                    (0x0000FF00)
#define CEC_TXTCR1_tx_data_high_mask                                  (0x000000FF)
#define CEC_TXTCR1_tx_data_low(data)                                  (0x00FF0000&((data)<<16))
#define CEC_TXTCR1_tx_data_01(data)                                   (0x0000FF00&((data)<<8))
#define CEC_TXTCR1_tx_data_high(data)                                 (0x000000FF&(data))
#define CEC_TXTCR1_get_tx_data_low(data)                              ((0x00FF0000&(data))>>16)
#define CEC_TXTCR1_get_tx_data_01(data)                               ((0x0000FF00&(data))>>8)
#define CEC_TXTCR1_get_tx_data_high(data)                             (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_01                                     0x1800d440
#define GDI_CEC_COMPARE_OPCODE_01_reg_addr                            "0xb800d440"
#define GDI_CEC_COMPARE_OPCODE_01_reg                                 0xb800d440
#define GDI_CEC_COMPARE_OPCODE_01_inst_addr                           "0x0110"
#define GDI_CEC_COMPARE_OPCODE_01_inst                                0x0110
#define GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_01_compare_opcode_01(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_01_get_compare_opcode_01(data)         (0x000000FF&(data))


#define GDI_CEC_SEND_OPCODE_01                                        0x1800d444
#define GDI_CEC_SEND_OPCODE_01_reg_addr                               "0xb800d444"
#define GDI_CEC_SEND_OPCODE_01_reg                                    0xb800d444
#define GDI_CEC_SEND_OPCODE_01_inst_addr                              "0x0111"
#define GDI_CEC_SEND_OPCODE_01_inst                                   0x0111
#define GDI_CEC_SEND_OPCODE_01_send_opcode_01_shift                   (0)
#define GDI_CEC_SEND_OPCODE_01_send_opcode_01_mask                    (0x000000FF)
#define GDI_CEC_SEND_OPCODE_01_send_opcode_01(data)                   (0x000000FF&(data))
#define GDI_CEC_SEND_OPCODE_01_get_send_opcode_01(data)               (0x000000FF&(data))


#define GDI_CEC_SEND_OPERAND_NUMBER_01                                0x1800d448
#define GDI_CEC_SEND_OPERAND_NUMBER_01_reg_addr                       "0xb800d448"
#define GDI_CEC_SEND_OPERAND_NUMBER_01_reg                            0xb800d448
#define GDI_CEC_SEND_OPERAND_NUMBER_01_inst_addr                      "0x0112"
#define GDI_CEC_SEND_OPERAND_NUMBER_01_inst                           0x0112
#define GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01_shift        (0)
#define GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01_mask         (0x00000003)
#define GDI_CEC_SEND_OPERAND_NUMBER_01_operand_number_01(data)        (0x00000003&(data))
#define GDI_CEC_SEND_OPERAND_NUMBER_01_get_operand_number_01(data)    (0x00000003&(data))


#define GDI_CEC_OPERAND_01                                            0x1800d44c
#define GDI_CEC_OPERAND_01_reg_addr                                   "0xb800d44c"
#define GDI_CEC_OPERAND_01_reg                                        0xb800d44c
#define GDI_CEC_OPERAND_01_inst_addr                                  "0x0113"
#define GDI_CEC_OPERAND_01_inst                                       0x0113
#define GDI_CEC_OPERAND_01_operand_01_shift                           (0)
#define GDI_CEC_OPERAND_01_operand_01_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_01_operand_01(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_01_get_operand_01(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_02                                            0x1800d450
#define GDI_CEC_OPERAND_02_reg_addr                                   "0xb800d450"
#define GDI_CEC_OPERAND_02_reg                                        0xb800d450
#define GDI_CEC_OPERAND_02_inst_addr                                  "0x0114"
#define GDI_CEC_OPERAND_02_inst                                       0x0114
#define GDI_CEC_OPERAND_02_operand_02_shift                           (0)
#define GDI_CEC_OPERAND_02_operand_02_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_02_operand_02(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_02_get_operand_02(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_03                                            0x1800d454
#define GDI_CEC_OPERAND_03_reg_addr                                   "0xb800d454"
#define GDI_CEC_OPERAND_03_reg                                        0xb800d454
#define GDI_CEC_OPERAND_03_inst_addr                                  "0x0115"
#define GDI_CEC_OPERAND_03_inst                                       0x0115
#define GDI_CEC_OPERAND_03_operand_03_shift                           (0)
#define GDI_CEC_OPERAND_03_operand_03_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_03_operand_03(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_03_get_operand_03(data)                       (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_02                                     0x1800d458
#define GDI_CEC_COMPARE_OPCODE_02_reg_addr                            "0xb800d458"
#define GDI_CEC_COMPARE_OPCODE_02_reg                                 0xb800d458
#define GDI_CEC_COMPARE_OPCODE_02_inst_addr                           "0x0116"
#define GDI_CEC_COMPARE_OPCODE_02_inst                                0x0116
#define GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_02_compare_opcode_02(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_02_get_compare_opcode_02(data)         (0x000000FF&(data))


#define GDI_CEC_SEND_OPCODE_02                                        0x1800d45c
#define GDI_CEC_SEND_OPCODE_02_reg_addr                               "0xb800d45c"
#define GDI_CEC_SEND_OPCODE_02_reg                                    0xb800d45c
#define GDI_CEC_SEND_OPCODE_02_inst_addr                              "0x0117"
#define GDI_CEC_SEND_OPCODE_02_inst                                   0x0117
#define GDI_CEC_SEND_OPCODE_02_send_opcode_02_shift                   (0)
#define GDI_CEC_SEND_OPCODE_02_send_opcode_02_mask                    (0x000000FF)
#define GDI_CEC_SEND_OPCODE_02_send_opcode_02(data)                   (0x000000FF&(data))
#define GDI_CEC_SEND_OPCODE_02_get_send_opcode_02(data)               (0x000000FF&(data))


#define GDI_CEC_SEND_OPERAND_NUMBER_02                                0x1800d460
#define GDI_CEC_SEND_OPERAND_NUMBER_02_reg_addr                       "0xb800d460"
#define GDI_CEC_SEND_OPERAND_NUMBER_02_reg                            0xb800d460
#define GDI_CEC_SEND_OPERAND_NUMBER_02_inst_addr                      "0x0118"
#define GDI_CEC_SEND_OPERAND_NUMBER_02_inst                           0x0118
#define GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02_shift        (0)
#define GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02_mask         (0x00000003)
#define GDI_CEC_SEND_OPERAND_NUMBER_02_operand_number_02(data)        (0x00000003&(data))
#define GDI_CEC_SEND_OPERAND_NUMBER_02_get_operand_number_02(data)    (0x00000003&(data))


#define GDI_CEC_OPERAND_04                                            0x1800d464
#define GDI_CEC_OPERAND_04_reg_addr                                   "0xb800d464"
#define GDI_CEC_OPERAND_04_reg                                        0xb800d464
#define GDI_CEC_OPERAND_04_inst_addr                                  "0x0119"
#define GDI_CEC_OPERAND_04_inst                                       0x0119
#define GDI_CEC_OPERAND_04_operand_04_shift                           (0)
#define GDI_CEC_OPERAND_04_operand_04_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_04_operand_04(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_04_get_operand_04(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_05                                            0x1800d468
#define GDI_CEC_OPERAND_05_reg_addr                                   "0xb800d468"
#define GDI_CEC_OPERAND_05_reg                                        0xb800d468
#define GDI_CEC_OPERAND_05_inst_addr                                  "0x011A"
#define GDI_CEC_OPERAND_05_inst                                       0x011A
#define GDI_CEC_OPERAND_05_operand_05_shift                           (0)
#define GDI_CEC_OPERAND_05_operand_05_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_05_operand_05(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_05_get_operand_05(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_06                                            0x1800d46c
#define GDI_CEC_OPERAND_06_reg_addr                                   "0xb800d46c"
#define GDI_CEC_OPERAND_06_reg                                        0xb800d46c
#define GDI_CEC_OPERAND_06_inst_addr                                  "0x011B"
#define GDI_CEC_OPERAND_06_inst                                       0x011B
#define GDI_CEC_OPERAND_06_operand_06_shift                           (0)
#define GDI_CEC_OPERAND_06_operand_06_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_06_operand_06(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_06_get_operand_06(data)                       (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_03                                     0x1800d470
#define GDI_CEC_COMPARE_OPCODE_03_reg_addr                            "0xb800d470"
#define GDI_CEC_COMPARE_OPCODE_03_reg                                 0xb800d470
#define GDI_CEC_COMPARE_OPCODE_03_inst_addr                           "0x011C"
#define GDI_CEC_COMPARE_OPCODE_03_inst                                0x011C
#define GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_03_compare_opcode_03(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_03_get_compare_opcode_03(data)         (0x000000FF&(data))


#define GDI_CEC_SEND_OPCODE_03                                        0x1800d474
#define GDI_CEC_SEND_OPCODE_03_reg_addr                               "0xb800d474"
#define GDI_CEC_SEND_OPCODE_03_reg                                    0xb800d474
#define GDI_CEC_SEND_OPCODE_03_inst_addr                              "0x011D"
#define GDI_CEC_SEND_OPCODE_03_inst                                   0x011D
#define GDI_CEC_SEND_OPCODE_03_send_opcode_03_shift                   (0)
#define GDI_CEC_SEND_OPCODE_03_send_opcode_03_mask                    (0x000000FF)
#define GDI_CEC_SEND_OPCODE_03_send_opcode_03(data)                   (0x000000FF&(data))
#define GDI_CEC_SEND_OPCODE_03_get_send_opcode_03(data)               (0x000000FF&(data))


#define GDI_CEC_SEND_OPERAND_NUMBER_03                                0x1800d478
#define GDI_CEC_SEND_OPERAND_NUMBER_03_reg_addr                       "0xb800d478"
#define GDI_CEC_SEND_OPERAND_NUMBER_03_reg                            0xb800d478
#define GDI_CEC_SEND_OPERAND_NUMBER_03_inst_addr                      "0x011E"
#define GDI_CEC_SEND_OPERAND_NUMBER_03_inst                           0x011E
#define GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03_shift        (0)
#define GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03_mask         (0x00000003)
#define GDI_CEC_SEND_OPERAND_NUMBER_03_operand_number_03(data)        (0x00000003&(data))
#define GDI_CEC_SEND_OPERAND_NUMBER_03_get_operand_number_03(data)    (0x00000003&(data))


#define GDI_CEC_OPERAND_07                                            0x1800d47c
#define GDI_CEC_OPERAND_07_reg_addr                                   "0xb800d47c"
#define GDI_CEC_OPERAND_07_reg                                        0xb800d47c
#define GDI_CEC_OPERAND_07_inst_addr                                  "0x011F"
#define GDI_CEC_OPERAND_07_inst                                       0x011F
#define GDI_CEC_OPERAND_07_operand_07_shift                           (0)
#define GDI_CEC_OPERAND_07_operand_07_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_07_operand_07(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_07_get_operand_07(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_08                                            0x1800d480
#define GDI_CEC_OPERAND_08_reg_addr                                   "0xb800d480"
#define GDI_CEC_OPERAND_08_reg                                        0xb800d480
#define GDI_CEC_OPERAND_08_inst_addr                                  "0x0120"
#define GDI_CEC_OPERAND_08_inst                                       0x0120
#define GDI_CEC_OPERAND_08_operand_08_shift                           (0)
#define GDI_CEC_OPERAND_08_operand_08_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_08_operand_08(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_08_get_operand_08(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_09                                            0x1800d484
#define GDI_CEC_OPERAND_09_reg_addr                                   "0xb800d484"
#define GDI_CEC_OPERAND_09_reg                                        0xb800d484
#define GDI_CEC_OPERAND_09_inst_addr                                  "0x0121"
#define GDI_CEC_OPERAND_09_inst                                       0x0121
#define GDI_CEC_OPERAND_09_operand_09_shift                           (0)
#define GDI_CEC_OPERAND_09_operand_09_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_09_operand_09(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_09_get_operand_09(data)                       (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_04                                     0x1800d488
#define GDI_CEC_COMPARE_OPCODE_04_reg_addr                            "0xb800d488"
#define GDI_CEC_COMPARE_OPCODE_04_reg                                 0xb800d488
#define GDI_CEC_COMPARE_OPCODE_04_inst_addr                           "0x0122"
#define GDI_CEC_COMPARE_OPCODE_04_inst                                0x0122
#define GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_04_compare_opcode_04(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_04_get_compare_opcode_04(data)         (0x000000FF&(data))


#define GDI_CEC_SEND_OPCODE_04                                        0x1800d48c
#define GDI_CEC_SEND_OPCODE_04_reg_addr                               "0xb800d48c"
#define GDI_CEC_SEND_OPCODE_04_reg                                    0xb800d48c
#define GDI_CEC_SEND_OPCODE_04_inst_addr                              "0x0123"
#define GDI_CEC_SEND_OPCODE_04_inst                                   0x0123
#define GDI_CEC_SEND_OPCODE_04_send_opcode_04_shift                   (0)
#define GDI_CEC_SEND_OPCODE_04_send_opcode_04_mask                    (0x000000FF)
#define GDI_CEC_SEND_OPCODE_04_send_opcode_04(data)                   (0x000000FF&(data))
#define GDI_CEC_SEND_OPCODE_04_get_send_opcode_04(data)               (0x000000FF&(data))


#define GDI_CEC_SEND_OPERAND_NUMBER_04                                0x1800d490
#define GDI_CEC_SEND_OPERAND_NUMBER_04_reg_addr                       "0xb800d490"
#define GDI_CEC_SEND_OPERAND_NUMBER_04_reg                            0xb800d490
#define GDI_CEC_SEND_OPERAND_NUMBER_04_inst_addr                      "0x0124"
#define GDI_CEC_SEND_OPERAND_NUMBER_04_inst                           0x0124
#define GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04_shift        (0)
#define GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04_mask         (0x00000003)
#define GDI_CEC_SEND_OPERAND_NUMBER_04_operand_number_04(data)        (0x00000003&(data))
#define GDI_CEC_SEND_OPERAND_NUMBER_04_get_operand_number_04(data)    (0x00000003&(data))


#define GDI_CEC_OPERAND_10                                            0x1800d494
#define GDI_CEC_OPERAND_10_reg_addr                                   "0xb800d494"
#define GDI_CEC_OPERAND_10_reg                                        0xb800d494
#define GDI_CEC_OPERAND_10_inst_addr                                  "0x0125"
#define GDI_CEC_OPERAND_10_inst                                       0x0125
#define GDI_CEC_OPERAND_10_operand_10_shift                           (0)
#define GDI_CEC_OPERAND_10_operand_10_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_10_operand_10(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_10_get_operand_10(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_11                                            0x1800d498
#define GDI_CEC_OPERAND_11_reg_addr                                   "0xb800d498"
#define GDI_CEC_OPERAND_11_reg                                        0xb800d498
#define GDI_CEC_OPERAND_11_inst_addr                                  "0x0126"
#define GDI_CEC_OPERAND_11_inst                                       0x0126
#define GDI_CEC_OPERAND_11_operand_11_shift                           (0)
#define GDI_CEC_OPERAND_11_operand_11_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_11_operand_11(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_11_get_operand_11(data)                       (0x000000FF&(data))


#define GDI_CEC_OPERAND_12                                            0x1800d49c
#define GDI_CEC_OPERAND_12_reg_addr                                   "0xb800d49c"
#define GDI_CEC_OPERAND_12_reg                                        0xb800d49c
#define GDI_CEC_OPERAND_12_inst_addr                                  "0x0127"
#define GDI_CEC_OPERAND_12_inst                                       0x0127
#define GDI_CEC_OPERAND_12_operand_12_shift                           (0)
#define GDI_CEC_OPERAND_12_operand_12_mask                            (0x000000FF)
#define GDI_CEC_OPERAND_12_operand_12(data)                           (0x000000FF&(data))
#define GDI_CEC_OPERAND_12_get_operand_12(data)                       (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_05                                     0x1800d4a0
#define GDI_CEC_COMPARE_OPCODE_05_reg_addr                            "0xb800d4a0"
#define GDI_CEC_COMPARE_OPCODE_05_reg                                 0xb800d4a0
#define GDI_CEC_COMPARE_OPCODE_05_inst_addr                           "0x0128"
#define GDI_CEC_COMPARE_OPCODE_05_inst                                0x0128
#define GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_05_compare_opcode_05(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_05_get_compare_opcode_05(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_06                                     0x1800d4a4
#define GDI_CEC_COMPARE_OPCODE_06_reg_addr                            "0xb800d4a4"
#define GDI_CEC_COMPARE_OPCODE_06_reg                                 0xb800d4a4
#define GDI_CEC_COMPARE_OPCODE_06_inst_addr                           "0x0129"
#define GDI_CEC_COMPARE_OPCODE_06_inst                                0x0129
#define GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_06_compare_opcode_06(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_06_get_compare_opcode_06(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_07                                     0x1800d4a8
#define GDI_CEC_COMPARE_OPCODE_07_reg_addr                            "0xb800d4a8"
#define GDI_CEC_COMPARE_OPCODE_07_reg                                 0xb800d4a8
#define GDI_CEC_COMPARE_OPCODE_07_inst_addr                           "0x012A"
#define GDI_CEC_COMPARE_OPCODE_07_inst                                0x012A
#define GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_07_compare_opcode_07(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_07_get_compare_opcode_07(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_08                                     0x1800d4ac
#define GDI_CEC_COMPARE_OPCODE_08_reg_addr                            "0xb800d4ac"
#define GDI_CEC_COMPARE_OPCODE_08_reg                                 0xb800d4ac
#define GDI_CEC_COMPARE_OPCODE_08_inst_addr                           "0x012B"
#define GDI_CEC_COMPARE_OPCODE_08_inst                                0x012B
#define GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_08_compare_opcode_08(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_08_get_compare_opcode_08(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_09                                     0x1800d4b0
#define GDI_CEC_COMPARE_OPCODE_09_reg_addr                            "0xb800d4b0"
#define GDI_CEC_COMPARE_OPCODE_09_reg                                 0xb800d4b0
#define GDI_CEC_COMPARE_OPCODE_09_inst_addr                           "0x012C"
#define GDI_CEC_COMPARE_OPCODE_09_inst                                0x012C
#define GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_09_compare_opcode_09(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_09_get_compare_opcode_09(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_10                                     0x1800d4b4
#define GDI_CEC_COMPARE_OPCODE_10_reg_addr                            "0xb800d4b4"
#define GDI_CEC_COMPARE_OPCODE_10_reg                                 0xb800d4b4
#define GDI_CEC_COMPARE_OPCODE_10_inst_addr                           "0x012D"
#define GDI_CEC_COMPARE_OPCODE_10_inst                                0x012D
#define GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_10_compare_opcode_10(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_10_get_compare_opcode_10(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_11                                     0x1800d4b8
#define GDI_CEC_COMPARE_OPCODE_11_reg_addr                            "0xb800d4b8"
#define GDI_CEC_COMPARE_OPCODE_11_reg                                 0xb800d4b8
#define GDI_CEC_COMPARE_OPCODE_11_inst_addr                           "0x012E"
#define GDI_CEC_COMPARE_OPCODE_11_inst                                0x012E
#define GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_11_compare_opcode_11(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_11_get_compare_opcode_11(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_12                                     0x1800d4bc
#define GDI_CEC_COMPARE_OPCODE_12_reg_addr                            "0xb800d4bc"
#define GDI_CEC_COMPARE_OPCODE_12_reg                                 0xb800d4bc
#define GDI_CEC_COMPARE_OPCODE_12_inst_addr                           "0x012F"
#define GDI_CEC_COMPARE_OPCODE_12_inst                                0x012F
#define GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_12_compare_opcode_12(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_12_get_compare_opcode_12(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_13                                     0x1800d4c0
#define GDI_CEC_COMPARE_OPCODE_13_reg_addr                            "0xb800d4c0"
#define GDI_CEC_COMPARE_OPCODE_13_reg                                 0xb800d4c0
#define GDI_CEC_COMPARE_OPCODE_13_inst_addr                           "0x0130"
#define GDI_CEC_COMPARE_OPCODE_13_inst                                0x0130
#define GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_13_compare_opcode_13(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_13_get_compare_opcode_13(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_14                                     0x1800d4c4
#define GDI_CEC_COMPARE_OPCODE_14_reg_addr                            "0xb800d4c4"
#define GDI_CEC_COMPARE_OPCODE_14_reg                                 0xb800d4c4
#define GDI_CEC_COMPARE_OPCODE_14_inst_addr                           "0x0131"
#define GDI_CEC_COMPARE_OPCODE_14_inst                                0x0131
#define GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_14_compare_opcode_14(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_14_get_compare_opcode_14(data)         (0x000000FF&(data))


#define GDI_CEC_COMPARE_OPCODE_15                                     0x1800d4c8
#define GDI_CEC_COMPARE_OPCODE_15_reg_addr                            "0xb800d4c8"
#define GDI_CEC_COMPARE_OPCODE_15_reg                                 0xb800d4c8
#define GDI_CEC_COMPARE_OPCODE_15_inst_addr                           "0x0132"
#define GDI_CEC_COMPARE_OPCODE_15_inst                                0x0132
#define GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15_shift             (0)
#define GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15_mask              (0x000000FF)
#define GDI_CEC_COMPARE_OPCODE_15_compare_opcode_15(data)             (0x000000FF&(data))
#define GDI_CEC_COMPARE_OPCODE_15_get_compare_opcode_15(data)         (0x000000FF&(data))


#define GDI_CEC_OPCODE_ENABLE                                         0x1800d4cc
#define GDI_CEC_OPCODE_ENABLE_reg_addr                                "0xb800d4cc"
#define GDI_CEC_OPCODE_ENABLE_reg                                     0xb800d4cc
#define GDI_CEC_OPCODE_ENABLE_inst_addr                               "0x0133"
#define GDI_CEC_OPCODE_ENABLE_inst                                    0x0133
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15_shift              (14)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14_shift              (13)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13_shift              (12)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12_shift              (11)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11_shift              (10)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10_shift              (9)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09_shift              (8)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08_shift              (7)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07_shift              (6)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06_shift              (5)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05_shift              (4)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04_shift              (3)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03_shift              (2)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02_shift              (1)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01_shift              (0)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15_mask               (0x00004000)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14_mask               (0x00002000)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13_mask               (0x00001000)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12_mask               (0x00000800)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11_mask               (0x00000400)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10_mask               (0x00000200)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09_mask               (0x00000100)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08_mask               (0x00000080)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07_mask               (0x00000040)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06_mask               (0x00000020)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05_mask               (0x00000010)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04_mask               (0x00000008)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03_mask               (0x00000004)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02_mask               (0x00000002)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01_mask               (0x00000001)
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_15(data)              (0x00004000&((data)<<14))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_14(data)              (0x00002000&((data)<<13))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_13(data)              (0x00001000&((data)<<12))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_12(data)              (0x00000800&((data)<<11))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_11(data)              (0x00000400&((data)<<10))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_10(data)              (0x00000200&((data)<<9))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_09(data)              (0x00000100&((data)<<8))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_08(data)              (0x00000080&((data)<<7))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_07(data)              (0x00000040&((data)<<6))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_06(data)              (0x00000020&((data)<<5))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_05(data)              (0x00000010&((data)<<4))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_04(data)              (0x00000008&((data)<<3))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_03(data)              (0x00000004&((data)<<2))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_02(data)              (0x00000002&((data)<<1))
#define GDI_CEC_OPCODE_ENABLE_en_compare_opcode_01(data)              (0x00000001&(data))
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_15(data)          ((0x00004000&(data))>>14)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_14(data)          ((0x00002000&(data))>>13)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_13(data)          ((0x00001000&(data))>>12)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_12(data)          ((0x00000800&(data))>>11)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_11(data)          ((0x00000400&(data))>>10)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_10(data)          ((0x00000200&(data))>>9)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_09(data)          ((0x00000100&(data))>>8)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_08(data)          ((0x00000080&(data))>>7)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_07(data)          ((0x00000040&(data))>>6)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_06(data)          ((0x00000020&(data))>>5)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_05(data)          ((0x00000010&(data))>>4)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_04(data)          ((0x00000008&(data))>>3)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_03(data)          ((0x00000004&(data))>>2)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_02(data)          ((0x00000002&(data))>>1)
#define GDI_CEC_OPCODE_ENABLE_get_en_compare_opcode_01(data)          (0x00000001&(data))


#define HDMI_DUMMY_CR0                                                0x1800d500
#define HDMI_DUMMY_CR0_reg_addr                                       "0xb800d500"
#define HDMI_DUMMY_CR0_reg                                            0xb800d500
#define HDMI_DUMMY_CR0_inst_addr                                      "0x0140"
#define HDMI_DUMMY_CR0_inst                                           0x0140
#define HDMI_DUMMY_CR0_hdmi_dummy_cr0_shift                           (11)
#define HDMI_DUMMY_CR0_debug_select_for_psm_shift                     (9)
#define HDMI_DUMMY_CR0_irq_select_shift                               (8)
#define HDMI_DUMMY_CR0_sram_bist_clock_source_select_shift            (7)
#define HDMI_DUMMY_CR0_vgip_input_select_shift                        (6)
#define HDMI_DUMMY_CR0_cp_48_mode_shift                               (5)
#define HDMI_DUMMY_CR0_aux_entst_shift                                (4)
#define HDMI_DUMMY_CR0_cec_entst_shift                                (3)
#define HDMI_DUMMY_CR0_debug_output_select_1_0_shift                  (0)
#define HDMI_DUMMY_CR0_hdmi_dummy_cr0_mask                            (0xFFFFF800)
#define HDMI_DUMMY_CR0_debug_select_for_psm_mask                      (0x00000600)
#define HDMI_DUMMY_CR0_irq_select_mask                                (0x00000100)
#define HDMI_DUMMY_CR0_sram_bist_clock_source_select_mask             (0x00000080)
#define HDMI_DUMMY_CR0_vgip_input_select_mask                         (0x00000040)
#define HDMI_DUMMY_CR0_cp_48_mode_mask                                (0x00000020)
#define HDMI_DUMMY_CR0_aux_entst_mask                                 (0x00000010)
#define HDMI_DUMMY_CR0_cec_entst_mask                                 (0x00000008)
#define HDMI_DUMMY_CR0_debug_output_select_1_0_mask                   (0x00000003)
#define HDMI_DUMMY_CR0_hdmi_dummy_cr0(data)                           (0xFFFFF800&((data)<<11))
#define HDMI_DUMMY_CR0_debug_select_for_psm(data)                     (0x00000600&((data)<<9))
#define HDMI_DUMMY_CR0_irq_select(data)                               (0x00000100&((data)<<8))
#define HDMI_DUMMY_CR0_sram_bist_clock_source_select(data)            (0x00000080&((data)<<7))
#define HDMI_DUMMY_CR0_vgip_input_select(data)                        (0x00000040&((data)<<6))
#define HDMI_DUMMY_CR0_cp_48_mode(data)                               (0x00000020&((data)<<5))
#define HDMI_DUMMY_CR0_aux_entst(data)                                (0x00000010&((data)<<4))
#define HDMI_DUMMY_CR0_cec_entst(data)                                (0x00000008&((data)<<3))
#define HDMI_DUMMY_CR0_debug_output_select_1_0(data)                  (0x00000003&(data))
#define HDMI_DUMMY_CR0_get_hdmi_dummy_cr0(data)                       ((0xFFFFF800&(data))>>11)
#define HDMI_DUMMY_CR0_get_debug_select_for_psm(data)                 ((0x00000600&(data))>>9)
#define HDMI_DUMMY_CR0_get_irq_select(data)                           ((0x00000100&(data))>>8)
#define HDMI_DUMMY_CR0_get_sram_bist_clock_source_select(data)        ((0x00000080&(data))>>7)
#define HDMI_DUMMY_CR0_get_vgip_input_select(data)                    ((0x00000040&(data))>>6)
#define HDMI_DUMMY_CR0_get_cp_48_mode(data)                           ((0x00000020&(data))>>5)
#define HDMI_DUMMY_CR0_get_aux_entst(data)                            ((0x00000010&(data))>>4)
#define HDMI_DUMMY_CR0_get_cec_entst(data)                            ((0x00000008&(data))>>3)
#define HDMI_DUMMY_CR0_get_debug_output_select_1_0(data)              (0x00000003&(data))


#define HDMI_DUMMY_CR1                                                0x1800d504
#define HDMI_DUMMY_CR1_reg_addr                                       "0xb800d504"
#define HDMI_DUMMY_CR1_reg                                            0xb800d504
#define HDMI_DUMMY_CR1_inst_addr                                      "0x0141"
#define HDMI_DUMMY_CR1_inst                                           0x0141
#define HDMI_DUMMY_CR1_hdmi_dummy_cr1_shift                           (0)
#define HDMI_DUMMY_CR1_hdmi_dummy_cr1_mask                            (0xFFFFFFFF)
#define HDMI_DUMMY_CR1_hdmi_dummy_cr1(data)                           (0xFFFFFFFF&(data))
#define HDMI_DUMMY_CR1_get_hdmi_dummy_cr1(data)                       (0xFFFFFFFF&(data))


#define RBUS_WRAP_CTRL0                                               0x1800d508
#define RBUS_WRAP_CTRL0_reg_addr                                      "0xb800d508"
#define RBUS_WRAP_CTRL0_reg                                           0xb800d508
#define RBUS_WRAP_CTRL0_inst_addr                                     "0x0142"
#define RBUS_WRAP_CTRL0_inst                                          0x0142
#define RBUS_WRAP_CTRL0_max_cmd_period_shift                          (24)
#define RBUS_WRAP_CTRL0_rdata_cnt_shift                               (16)
#define RBUS_WRAP_CTRL0_wr_ack_cnt_shift                              (8)
#define RBUS_WRAP_CTRL0_rd_ack_cnt_shift                              (0)
#define RBUS_WRAP_CTRL0_max_cmd_period_mask                           (0xFF000000)
#define RBUS_WRAP_CTRL0_rdata_cnt_mask                                (0x00FF0000)
#define RBUS_WRAP_CTRL0_wr_ack_cnt_mask                               (0x0000FF00)
#define RBUS_WRAP_CTRL0_rd_ack_cnt_mask                               (0x000000FF)
#define RBUS_WRAP_CTRL0_max_cmd_period(data)                          (0xFF000000&((data)<<24))
#define RBUS_WRAP_CTRL0_rdata_cnt(data)                               (0x00FF0000&((data)<<16))
#define RBUS_WRAP_CTRL0_wr_ack_cnt(data)                              (0x0000FF00&((data)<<8))
#define RBUS_WRAP_CTRL0_rd_ack_cnt(data)                              (0x000000FF&(data))
#define RBUS_WRAP_CTRL0_get_max_cmd_period(data)                      ((0xFF000000&(data))>>24)
#define RBUS_WRAP_CTRL0_get_rdata_cnt(data)                           ((0x00FF0000&(data))>>16)
#define RBUS_WRAP_CTRL0_get_wr_ack_cnt(data)                          ((0x0000FF00&(data))>>8)
#define RBUS_WRAP_CTRL0_get_rd_ack_cnt(data)                          (0x000000FF&(data))


#define RBUS_WRAP_CTRL1                                               0x1800d50c
#define RBUS_WRAP_CTRL1_reg_addr                                      "0xb800d50c"
#define RBUS_WRAP_CTRL1_reg                                           0xb800d50c
#define RBUS_WRAP_CTRL1_inst_addr                                     "0x0143"
#define RBUS_WRAP_CTRL1_inst                                          0x0143
#define RBUS_WRAP_CTRL1_mcuwr_start_shift                             (24)
#define RBUS_WRAP_CTRL1_mcuwr_end_shift                               (16)
#define RBUS_WRAP_CTRL1_mcurd_start_shift                             (8)
#define RBUS_WRAP_CTRL1_mcurd_end_shift                               (0)
#define RBUS_WRAP_CTRL1_mcuwr_start_mask                              (0xFF000000)
#define RBUS_WRAP_CTRL1_mcuwr_end_mask                                (0x00FF0000)
#define RBUS_WRAP_CTRL1_mcurd_start_mask                              (0x0000FF00)
#define RBUS_WRAP_CTRL1_mcurd_end_mask                                (0x000000FF)
#define RBUS_WRAP_CTRL1_mcuwr_start(data)                             (0xFF000000&((data)<<24))
#define RBUS_WRAP_CTRL1_mcuwr_end(data)                               (0x00FF0000&((data)<<16))
#define RBUS_WRAP_CTRL1_mcurd_start(data)                             (0x0000FF00&((data)<<8))
#define RBUS_WRAP_CTRL1_mcurd_end(data)                               (0x000000FF&(data))
#define RBUS_WRAP_CTRL1_get_mcuwr_start(data)                         ((0xFF000000&(data))>>24)
#define RBUS_WRAP_CTRL1_get_mcuwr_end(data)                           ((0x00FF0000&(data))>>16)
#define RBUS_WRAP_CTRL1_get_mcurd_start(data)                         ((0x0000FF00&(data))>>8)
#define RBUS_WRAP_CTRL1_get_mcurd_end(data)                           (0x000000FF&(data))


#define RBUS_WRAP_CTRL2                                               0x1800d510
#define RBUS_WRAP_CTRL2_reg_addr                                      "0xb800d510"
#define RBUS_WRAP_CTRL2_reg                                           0xb800d510
#define RBUS_WRAP_CTRL2_inst_addr                                     "0x0144"
#define RBUS_WRAP_CTRL2_inst                                          0x0144
#define RBUS_WRAP_CTRL2_mcuwr_inc_start_shift                         (24)
#define RBUS_WRAP_CTRL2_mcuwr_inc_end_shift                           (16)
#define RBUS_WRAP_CTRL2_mcurd_inc_start_shift                         (8)
#define RBUS_WRAP_CTRL2_mcurd_inc_end_shift                           (0)
#define RBUS_WRAP_CTRL2_mcuwr_inc_start_mask                          (0xFF000000)
#define RBUS_WRAP_CTRL2_mcuwr_inc_end_mask                            (0x00FF0000)
#define RBUS_WRAP_CTRL2_mcurd_inc_start_mask                          (0x0000FF00)
#define RBUS_WRAP_CTRL2_mcurd_inc_end_mask                            (0x000000FF)
#define RBUS_WRAP_CTRL2_mcuwr_inc_start(data)                         (0xFF000000&((data)<<24))
#define RBUS_WRAP_CTRL2_mcuwr_inc_end(data)                           (0x00FF0000&((data)<<16))
#define RBUS_WRAP_CTRL2_mcurd_inc_start(data)                         (0x0000FF00&((data)<<8))
#define RBUS_WRAP_CTRL2_mcurd_inc_end(data)                           (0x000000FF&(data))
#define RBUS_WRAP_CTRL2_get_mcuwr_inc_start(data)                     ((0xFF000000&(data))>>24)
#define RBUS_WRAP_CTRL2_get_mcuwr_inc_end(data)                       ((0x00FF0000&(data))>>16)
#define RBUS_WRAP_CTRL2_get_mcurd_inc_start(data)                     ((0x0000FF00&(data))>>8)
#define RBUS_WRAP_CTRL2_get_mcurd_inc_end(data)                       (0x000000FF&(data))


#define HDMI_DUMMY_CR2                                                0x1800d514
#define HDMI_DUMMY_CR2_reg_addr                                       "0xb800d514"
#define HDMI_DUMMY_CR2_reg                                            0xb800d514
#define HDMI_DUMMY_CR2_inst_addr                                      "0x0145"
#define HDMI_DUMMY_CR2_inst                                           0x0145
#define HDMI_DUMMY_CR2_hdmi_dummy_cr2_shift                           (0)
#define HDMI_DUMMY_CR2_hdmi_dummy_cr2_mask                            (0xFFFFFFFF)
#define HDMI_DUMMY_CR2_hdmi_dummy_cr2(data)                           (0xFFFFFFFF&(data))
#define HDMI_DUMMY_CR2_get_hdmi_dummy_cr2(data)                       (0xFFFFFFFF&(data))


#define HDMI_DUMMY_CR3                                                0x1800d518
#define HDMI_DUMMY_CR3_reg_addr                                       "0xb800d518"
#define HDMI_DUMMY_CR3_reg                                            0xb800d518
#define HDMI_DUMMY_CR3_inst_addr                                      "0x0146"
#define HDMI_DUMMY_CR3_inst                                           0x0146
#define HDMI_DUMMY_CR3_hdmi_dummy_cr3_shift                           (0)
#define HDMI_DUMMY_CR3_hdmi_dummy_cr3_mask                            (0xFFFFFFFF)
#define HDMI_DUMMY_CR3_hdmi_dummy_cr3(data)                           (0xFFFFFFFF&(data))
#define HDMI_DUMMY_CR3_get_hdmi_dummy_cr3(data)                       (0xFFFFFFFF&(data))


#define GDI_POWER_SAVING_MODE                                         0x1800d600
#define GDI_POWER_SAVING_MODE_reg_addr                                "0xb800d600"
#define GDI_POWER_SAVING_MODE_reg                                     0xb800d600
#define GDI_POWER_SAVING_MODE_inst_addr                               "0x0180"
#define GDI_POWER_SAVING_MODE_inst                                    0x0180
#define GDI_POWER_SAVING_MODE_gdi_power_saving_en_shift               (8)
#define GDI_POWER_SAVING_MODE_cec_irq_en_shift                        (3)
#define GDI_POWER_SAVING_MODE_cec_irq_inv_shift                       (2)
#define GDI_POWER_SAVING_MODE_gdi_power_saving_en_mask                (0x00000100)
#define GDI_POWER_SAVING_MODE_cec_irq_en_mask                         (0x00000008)
#define GDI_POWER_SAVING_MODE_cec_irq_inv_mask                        (0x00000004)
#define GDI_POWER_SAVING_MODE_gdi_power_saving_en(data)               (0x00000100&((data)<<8))
#define GDI_POWER_SAVING_MODE_cec_irq_en(data)                        (0x00000008&((data)<<3))
#define GDI_POWER_SAVING_MODE_cec_irq_inv(data)                       (0x00000004&((data)<<2))
#define GDI_POWER_SAVING_MODE_get_gdi_power_saving_en(data)           ((0x00000100&(data))>>8)
#define GDI_POWER_SAVING_MODE_get_cec_irq_en(data)                    ((0x00000008&(data))>>3)
#define GDI_POWER_SAVING_MODE_get_cec_irq_inv(data)                   ((0x00000004&(data))>>2)


#define GDI_INTCR_01                                                  0x1800d604
#define GDI_INTCR_01_reg_addr                                         "0xb800d604"
#define GDI_INTCR_01_reg                                              0xb800d604
#define GDI_INTCR_01_inst_addr                                        "0x0181"
#define GDI_INTCR_01_inst                                             0x0181
#define GDI_INTCR_01_irq_pending_shift                                (31)
#define GDI_INTCR_01_tmds_clk_status_shift                            (30)
#define GDI_INTCR_01_cec_msg_status_01_shift                          (26)
#define GDI_INTCR_01_cec_msg_status_02_shift                          (25)
#define GDI_INTCR_01_irq_by_tmds_clk_shift                            (14)
#define GDI_INTCR_01_irq_by_cec_receive_cmd_01_shift                  (10)
#define GDI_INTCR_01_irq_by_cec_receive_cmd_02_shift                  (9)
#define GDI_INTCR_01_irq_by_cec_receivespecial_cmd_shift              (8)
#define GDI_INTCR_01_irq_pending_mask                                 (0x80000000)
#define GDI_INTCR_01_tmds_clk_status_mask                             (0x40000000)
#define GDI_INTCR_01_cec_msg_status_01_mask                           (0x04000000)
#define GDI_INTCR_01_cec_msg_status_02_mask                           (0x02000000)
#define GDI_INTCR_01_irq_by_tmds_clk_mask                             (0x00004000)
#define GDI_INTCR_01_irq_by_cec_receive_cmd_01_mask                   (0x00000400)
#define GDI_INTCR_01_irq_by_cec_receive_cmd_02_mask                   (0x00000200)
#define GDI_INTCR_01_irq_by_cec_receivespecial_cmd_mask               (0x00000100)
#define GDI_INTCR_01_irq_pending(data)                                (0x80000000&((data)<<31))
#define GDI_INTCR_01_tmds_clk_status(data)                            (0x40000000&((data)<<30))
#define GDI_INTCR_01_cec_msg_status_01(data)                          (0x04000000&((data)<<26))
#define GDI_INTCR_01_cec_msg_status_02(data)                          (0x02000000&((data)<<25))
#define GDI_INTCR_01_irq_by_tmds_clk(data)                            (0x00004000&((data)<<14))
#define GDI_INTCR_01_irq_by_cec_receive_cmd_01(data)                  (0x00000400&((data)<<10))
#define GDI_INTCR_01_irq_by_cec_receive_cmd_02(data)                  (0x00000200&((data)<<9))
#define GDI_INTCR_01_irq_by_cec_receivespecial_cmd(data)              (0x00000100&((data)<<8))
#define GDI_INTCR_01_get_irq_pending(data)                            ((0x80000000&(data))>>31)
#define GDI_INTCR_01_get_tmds_clk_status(data)                        ((0x40000000&(data))>>30)
#define GDI_INTCR_01_get_cec_msg_status_01(data)                      ((0x04000000&(data))>>26)
#define GDI_INTCR_01_get_cec_msg_status_02(data)                      ((0x02000000&(data))>>25)
#define GDI_INTCR_01_get_irq_by_tmds_clk(data)                        ((0x00004000&(data))>>14)
#define GDI_INTCR_01_get_irq_by_cec_receive_cmd_01(data)              ((0x00000400&(data))>>10)
#define GDI_INTCR_01_get_irq_by_cec_receive_cmd_02(data)              ((0x00000200&(data))>>9)
#define GDI_INTCR_01_get_irq_by_cec_receivespecial_cmd(data)          ((0x00000100&(data))>>8)


#define GDI_TMDSCLK_SETTING_00                                        0x1800d608
#define GDI_TMDSCLK_SETTING_00_reg_addr                               "0xb800d608"
#define GDI_TMDSCLK_SETTING_00_reg                                    0xb800d608
#define GDI_TMDSCLK_SETTING_00_inst_addr                              "0x0182"
#define GDI_TMDSCLK_SETTING_00_inst                                   0x0182
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_start_shift                   (16)
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_end_shift                     (0)
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_start_mask                    (0x0FFF0000)
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_end_mask                      (0x00000FFF)
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_start(data)                   (0x0FFF0000&((data)<<16))
#define GDI_TMDSCLK_SETTING_00_dclk_cnt_end(data)                     (0x00000FFF&(data))
#define GDI_TMDSCLK_SETTING_00_get_dclk_cnt_start(data)               ((0x0FFF0000&(data))>>16)
#define GDI_TMDSCLK_SETTING_00_get_dclk_cnt_end(data)                 (0x00000FFF&(data))


#define GDI_TMDSCLK_SETTING_01                                        0x1800d60c
#define GDI_TMDSCLK_SETTING_01_reg_addr                               "0xb800d60c"
#define GDI_TMDSCLK_SETTING_01_reg                                    0xb800d60c
#define GDI_TMDSCLK_SETTING_01_inst_addr                              "0x0183"
#define GDI_TMDSCLK_SETTING_01_inst                                   0x0183
#define GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter_shift   (16)
#define GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter_shift   (0)
#define GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter_mask    (0x0FFF0000)
#define GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter_mask    (0x00000FFF)
#define GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter(data)   (0x0FFF0000&((data)<<16))
#define GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter(data)   (0x00000FFF&(data))
#define GDI_TMDSCLK_SETTING_01_get_target_for_maximum_clk_counter(data)  ((0x0FFF0000&(data))>>16)
#define GDI_TMDSCLK_SETTING_01_get_target_for_minimum_clk_counter(data)  (0x00000FFF&(data))


#define GDI_TMDSCLK_SETTING_02                                        0x1800d610
#define GDI_TMDSCLK_SETTING_02_reg_addr                               "0xb800d610"
#define GDI_TMDSCLK_SETTING_02_reg                                    0xb800d610
#define GDI_TMDSCLK_SETTING_02_inst_addr                              "0x0184"
#define GDI_TMDSCLK_SETTING_02_inst                                   0x0184
#define GDI_TMDSCLK_SETTING_02_hdmi_clksel_shift                      (12)
#define GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold_shift        (8)
#define GDI_TMDSCLK_SETTING_02_clk_counter_debounce_shift             (0)
#define GDI_TMDSCLK_SETTING_02_hdmi_clksel_mask                       (0x00003000)
#define GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold_mask         (0x00000F00)
#define GDI_TMDSCLK_SETTING_02_clk_counter_debounce_mask              (0x000000FF)
#define GDI_TMDSCLK_SETTING_02_hdmi_clksel(data)                      (0x00003000&((data)<<12))
#define GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold(data)        (0x00000F00&((data)<<8))
#define GDI_TMDSCLK_SETTING_02_clk_counter_debounce(data)             (0x000000FF&(data))
#define GDI_TMDSCLK_SETTING_02_get_hdmi_clksel(data)                  ((0x00003000&(data))>>12)
#define GDI_TMDSCLK_SETTING_02_get_clk_counter_err_threshold(data)    ((0x00000F00&(data))>>8)
#define GDI_TMDSCLK_SETTING_02_get_clk_counter_debounce(data)         (0x000000FF&(data))


#define GDI_CEC_CONTROL                                               0x1800d614
#define GDI_CEC_CONTROL_reg_addr                                      "0xb800d614"
#define GDI_CEC_CONTROL_reg                                           0xb800d614
#define GDI_CEC_CONTROL_inst_addr                                     "0x0185"
#define GDI_CEC_CONTROL_inst                                          0x0185
#define GDI_CEC_CONTROL_cec_driver_en_ctrl_shift                      (1)
#define GDI_CEC_CONTROL_cec_driver_en_ctrl_by_sw_shift                (0)
#define GDI_CEC_CONTROL_cec_driver_en_ctrl_mask                       (0x00000002)
#define GDI_CEC_CONTROL_cec_driver_en_ctrl_by_sw_mask                 (0x00000001)
#define GDI_CEC_CONTROL_cec_driver_en_ctrl(data)                      (0x00000002&((data)<<1))
#define GDI_CEC_CONTROL_cec_driver_en_ctrl_by_sw(data)                (0x00000001&(data))
#define GDI_CEC_CONTROL_get_cec_driver_en_ctrl(data)                  ((0x00000002&(data))>>1)
#define GDI_CEC_CONTROL_get_cec_driver_en_ctrl_by_sw(data)            (0x00000001&(data))


#define GDI_TMDSCLK_FREQ_CHANGE_IRG                                   0x1800d618
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_reg_addr                          "0xb800d618"
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_reg                               0xb800d618
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_inst_addr                         "0x0186"
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_inst                              0x0186
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_en_tmds_chg_irq_shift             (1)
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_tmds_chg_irq_shift                (0)
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_en_tmds_chg_irq_mask              (0x00000002)
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_tmds_chg_irq_mask                 (0x00000001)
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_en_tmds_chg_irq(data)             (0x00000002&((data)<<1))
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_tmds_chg_irq(data)                (0x00000001&(data))
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_get_en_tmds_chg_irq(data)         ((0x00000002&(data))>>1)
#define GDI_TMDSCLK_FREQ_CHANGE_IRG_get_tmds_chg_irq(data)            (0x00000001&(data))
#endif
