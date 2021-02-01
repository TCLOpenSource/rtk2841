/* Copyright (C) 2007-2013 Realtek Semiconductor Corporation. */
#ifndef __TP_DRV_H__
#define __TP_DRV_H__

#include <rbus/tp_reg.h>
#include <tp/tp_def.h>

#define TP_DRIVER_NAME "tp"


typedef struct {
        /* tp streming status */
        TPK_TP_STREAM_CTRL_T               tp_streaming_status[MAX_TP_COUNT];

        /* tp */
        tp_tp_tf0_cntl_RBUS                tp_tf_cntl_reg[MAX_TP_COUNT];
        tp_tp_tf0_frmcfg_RBUS              tp_tf_frmcfg_reg[MAX_TP_COUNT];
        tp_tp_tf0_int_RBUS                 tp_tf_int_reg[MAX_TP_COUNT];
        tp_tp_tf0_int_en_RBUS              tp_tf_int_en_reg[MAX_TP_COUNT];

        /* tpout */
        tp_tp_tf_out_frmcfg_RBUS           tp_tf_out_frmcfg_reg;
        tp_tp_out_ctrl_RBUS                tp_out_ctrl_reg;
        tp_tp_out_int_RBUS                 tp_out_int_reg;

        /* tp input control */
        tp_tp_in_pol_RBUS                  tp_in_pol_reg;

        /* pcr */
        tp_tp0_pcr_ctl_RBUS                tp_pcr_ctl_reg[MAX_TP_COUNT];

        /* sync replace */
        tp_tp_sync_rplace_RBUS             tp_sync_rplace_reg;

        /* pid & section */
        tp_tp_pid_part_RBUS                tp_pid_part_reg;

        tp_tp_pid_data_RBUS                tp_pid_data_reg[MAX_PID_FILTER_COUNT];
        tp_tp_pid_data2_RBUS               tp_pid_data2_reg[MAX_PID_FILTER_COUNT];
        tp_tp_pid_data3_RBUS               tp_pid_data3_reg[MAX_PID_FILTER_COUNT];

        tp_tp_sec_data0_RBUS               tp_sec_data0_reg[MAX_SEC_COUNT];
        tp_tp_sec_data1_RBUS               tp_sec_data1_reg[MAX_SEC_COUNT];
        tp_tp_sec_data2_RBUS               tp_sec_data2_reg[MAX_SEC_COUNT];
        tp_tp_sec_data3_RBUS               tp_sec_data3_reg[MAX_SEC_COUNT];
        tp_tp_sec_data4_RBUS               tp_sec_data4_reg[MAX_SEC_COUNT];
        tp_tp_sec_data5_RBUS               tp_sec_data5_reg[MAX_SEC_COUNT];
        tp_tp_sec_data6_RBUS               tp_sec_data6_reg[MAX_SEC_COUNT];
        tp_tp_sec_data7_RBUS               tp_sec_data7_reg[MAX_SEC_COUNT];
        tp_tp_sec_data8_RBUS               tp_sec_data8_reg[MAX_SEC_COUNT];
        tp_tp_sec_data9_RBUS               tp_sec_data9_reg[MAX_SEC_COUNT];

        /* des & tdes */
        tp_tp_tp0_des_cntl_RBUS            tp_tp_des_cntl_reg[MAX_TP_COUNT];
        tp_tp_key_info_RBUS                tp_key_info_reg[MAX_KEY_COUNT];
        tp_tp_key_info_RBUS                tp_key_info2_reg[MAX_KEY_COUNT];

        /* crc */
        tp_tp_crc_init_RBUS                tp_crc_init_reg;

        /* ring buffer */
        tp_tp_threshold_RBUS               tp_threshold_reg;
        tp_tp_fullness_RBUS                tp_fullness_reg;

        tp_tp_ring_limit_RBUS              tp_ring_limit_reg[MAX_TP_BUFFER_COUNT];
        tp_tp_ring_base_RBUS               tp_ring_base_reg[MAX_TP_BUFFER_COUNT];
        tp_tp_ring_rp_RBUS                 tp_ring_rp_reg[MAX_TP_BUFFER_COUNT];
        tp_tp_ring_wp_RBUS                 tp_ring_wp_reg[MAX_TP_BUFFER_COUNT];

        tp_tp_ring_avail_int_RBUS          tp_ring_avail_int_reg;
        tp_tp_ring_avail_int_RBUS          tp_ring_avail_int2_reg;
        tp_tp_ring_full_int_RBUS           tp_ring_full_int_reg;
        tp_tp_ring_full_int_RBUS           tp_ring_full_int2_reg;
        tp_tp_ring_avail_int_en_RBUS       tp_ring_avail_int_en_reg;
        tp_tp_ring_avail_int_en_RBUS       tp_ring_avail_int_en2_reg;
        tp_tp_ring_full_int_en_RBUS        tp_ring_full_int_en_reg;
        tp_tp_ring_full_int_en_RBUS        tp_ring_full_int_en2_reg;

        /* tp dmy_a & dmy_b */
        tp_tp_dmy_a_RBUS                   tp_dmy_a_reg;
        tp_tp_dmy_b_RBUS                   tp_dmy_b_reg;

        /* m2m ring buffer */
        tp_tp0_m2m_ring_limit_RBUS         tp_m2m_ring_limit_reg[MAX_TP_COUNT];
        tp_tp0_m2m_ring_base_RBUS          tp_m2m_ring_base_reg[MAX_TP_COUNT];
        tp_tp0_m2m_ring_rp_RBUS            tp_m2m_ring_rp_reg[MAX_TP_COUNT];
        tp_tp0_m2m_ring_wp_RBUS            tp_m2m_ring_wp_reg[MAX_TP_COUNT];
        tp_tp0_m2m_ring_ctrl_RBUS          tp_m2m_ring_ctrl_reg[MAX_TP_COUNT];

        tp_tp0_p_m2m_ring_limit_RBUS       tp_p_m2m_ring_limit_reg[MAX_TP_P_COUNT];
        tp_tp0_p_m2m_ring_base_RBUS        tp_p_m2m_ring_base_reg[MAX_TP_P_COUNT];
        tp_tp0_p_m2m_ring_rp_RBUS          tp_p_m2m_ring_rp_reg[MAX_TP_P_COUNT];
        tp_tp0_p_m2m_ring_wp_RBUS          tp_p_m2m_ring_wp_reg[MAX_TP_P_COUNT];
        tp_tp0_p_m2m_ring_ctrl_RBUS        tp_p_m2m_ring_ctrl_reg[MAX_TP_P_COUNT];

        /* tp_p */
        tp_tp_tf0_p_cntl_RBUS              tp_tf_p_cntl_reg[MAX_TP_P_COUNT];
        tp_tp_tf0_p_frmcfg_RBUS            tp_tf_p_frmcfg_reg[MAX_TP_P_COUNT];
        tp_tp_tf0_p_int_RBUS               tp_tf_p_int_reg[MAX_TP_P_COUNT];
        tp_tp_tf0_p_int_en_RBUS            tp_tf_p_int_en_reg[MAX_TP_P_COUNT];

        /* tp_p ring buffer */
        tp_tp_p_threshold_RBUS             tp_p_threshold_reg;
        tp_tp_p_fullness_RBUS              tp_p_fullness_reg;

        tp_tp_p_ring_limit_RBUS            tp_p_ring_limit_reg[MAX_TPP_BUFFER_COUNT];
        tp_tp_p_ring_base_RBUS             tp_p_ring_base_reg[MAX_TPP_BUFFER_COUNT];
        tp_tp_p_ring_rp_RBUS               tp_p_ring_rp_reg[MAX_TPP_BUFFER_COUNT];
        tp_tp_p_ring_wp_RBUS               tp_p_ring_wp_reg[MAX_TPP_BUFFER_COUNT];

        tp_tp_p_ring_avail_int_RBUS        tp_p_ring_avail_int_reg;
        tp_tp_p_ring_full_int_RBUS         tp_p_ring_full_int_reg;
        tp_tp_p_ring_avail_int_en_RBUS     tp_p_ring_avail_int_en_reg;
        tp_tp_p_ring_full_int_en_RBUS      tp_p_ring_full_int_en_reg;

        /* tp_p sync replace */
        tp_tp_p_sync_rplace_RBUS           tp_p_sync_rplace_reg;

        /* frame rate control */
        tp_prefix_ctrl_RBUS                prefix_ctrl_reg;
        tp_prefix_data1_RBUS               prefix_data1_reg;
        tp_prefix_data2_RBUS               prefix_data2_reg;
        tp_prefix_data3_RBUS               prefix_data3_reg;
        tp_fr_ctrl_RBUS                    fr_ctrl_reg;

        /* start code search for tp0 & tp1 */
        tp_start_code_tp0_RBUS             start_code_tp0_reg;
        tp_start_code_tp1_RBUS             start_code_tp1_reg;
        tp_start_code_ctrl_tp0_RBUS        start_code_ctrl_tp0_reg;
        tp_start_code_ctrl_tp1_RBUS        start_code_ctrl_tp1_reg;

        /* Others */
        tp_tp0_err_cnt_en_RBUS             tp0_err_cnt_en;
        tp_tp1_err_cnt_en_RBUS             tp1_err_cnt_en;

        /* misc 27m */
        tp_tp_misc_27m_cfg_RBUS            misc_27m_cfg;

        /* TPO CLK */
        UINT32                             tpout_clk_reg;
} TP_REG_INFO;

#endif /* __TP_DRV_H__ */
