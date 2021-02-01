/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_DISEQC_RTD284X_REG_H__
#define __RTK_DISEQC_RTD284X_REG_H__

//#include "rtk_cec_rtd284x.h"


#define DISEQC_MODEL_NAME		        "diseqc_model"
#define DISEQC_DRIVE_NAME			    ("diseqc")

/*
// Interrupt Configurations
#include <mach/irqs.h>
#include <rbus/sys_reg_reg.h>
#define ISO_IRQ                         IRQ_CEC
#define CEC_INT_EN		                SYS_REG_INT_CTRL_SCPU_reg
#define CEC_INT_EN_MASK		            SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask
#define CEC_INT_EN_VAL		            SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask

// Device Registers

#include <rbus/diseqc_reg.h>
*/
#include <rbus/diseqc_reg.h>
#define ISO_IRQ                     IRQ_CEC
//Register:DSCUL_CTL
#define DSCU_CTL							DISEQC_DSCU_CTL_reg
#define	TX_ENV_MODE_MASK					DISEQC_DSCU_CTL_tx_env_mode_mask
#define	TV_ENV_MODE_EN_SET(x)				DISEQC_DSCU_CTL_tx_env_mode(x)
#define DSC_POL_OPEN_DRAIN_CTRL_MASK		DISEQC_DSCU_CTL_dsc_pol_od_ctrl_mask
#define DSC_POL_OPEN_DRAIN_CTRL_EN(x)		DISEQC_DSCU_CTL_dsc_pol_od_ctrl(x)
#define DSC_22K_OPEN_DRAIN_CTRL_MASK		DISEQC_DSCU_CTL_dsc_22k_od_ctrl_mask
#define DSC_22K_OPEN_DRAIN_CTRL_EN(x)       DISEQC_DSCU_CTL_dsc_22k_od_ctrl(x)
#define	EORM_TIMEOUT_REG_MASK				DISEQC_DSCU_CTL_eorm_timeout_reg_mask
#define EORM_TIMEOUT_REG(x)					DISEQC_DSCU_CTL_get_eorm_timeout_reg(x)
#define	MILI_SEC_DEF_MASK					DISEQC_DSCU_CTL_mili_second_define_mask
#define	MILI_SEC_DEF(x)						DISEQC_DSCU_CTL_get_eorm_timeout_reg(x)
#define	LNB_POL_MASK						DISEQC_DSCU_CTL_lnb_pol_mask
#define	LNB_POL(x)							DISEQC_DSCU_CTL_lnb_pol(x)
#define	INT_EN_MASK							DISEQC_DSCU_CTL_int_en_mask
#define	INT_EN(x)							DISEQC_DSCU_CTL_int_en(x)
#define	LEVEL_MASK							DISEQC_DSCU_CTL_level_mask
#define	LEVEL_SET(x)						DISEQC_DSCU_CTL_level(x)

//Register:DSCU_TX_CTL
#define DSCU_TX_CTL							DISEQC_DSCU_TX_CTL_reg
#define	LOOP_BACK_MODE_MASK					DISEQC_DSCU_TX_CTL_loop_back_mode_mask
#define LOOP_BACK_MODE(x)					DISEQC_DSCU_TX_CTL_loop_back_mode(x)
#define LISTEN_DELAY_MASK					DISEQC_DSCU_TX_CTL_listen_dly_mask
#define LISTEN_DELAY(x)						DISEQC_DSCU_TX_CTL_listen_dly(x)
#define	THIRD_BIT_MASK						DISEQC_DSCU_TX_CTL_third_bit_mask
#define	THIRD_BIT(x)						DISEQC_DSCU_TX_CTL_third_bit(x)
#define	EOT_LEN_MASK						DISEQC_DSCU_TX_CTL_eot_len_mask
#define	EOT_LEN(x)							DISEQC_DSCU_TX_CTL_eot_len(x)
#define	TX_PARITY_MASK						DISEQC_DSCU_TX_CTL_tx_pty_mask
#define TX_PARITY(x)						DISEQC_DSCU_TX_CTL_tx_pty(x)
#define	XMT_MODE_MASK						DISEQC_DSCU_TX_CTL_xmt_mode_mask
#define	XMT_MODE(x)							DISEQC_DSCU_TX_CTL_xmt_mode(x)
#define	MSG_LEN_MASKE						DISEQC_DSCU_TX_CTL_msg_len_mask
#define	MSG_LEN(x)							DISEQC_DSCU_TX_CTL_msg_len(x)
#define	TX_GO_MASK							DISEQC_DSCU_TX_CTL_tx_go_mask
#define	TX_GO(x)							DISEQC_DSCU_TX_CTL_tx_go(x)
#define	TONE_DIV_MASK						DISEQC_DSCU_TX_CTL_tone_div_mask
#define	TONE_DIV(x)							DISEQC_DSCU_TX_CTL_tone_div(x)

//Register:DSCU_RX_CTL
#define DSCU_RX_CTL							DISEQC_DSCU_RX_CTL_reg
#define MEDIAN_FLT_EN_MASK                  DISEQC_DSCU_RX_CTL_median_flt_en_mask
#define MEDIAN_FLT_EN(x)					DISEQC_DSCU_RX_CTL_median_flt_en(x)
#define	DSCU_EXP_WIN_MASK					DISEQC_DSCU_RX_CTL_dscu_exp_win_mask
#define	DSCU_EXP_WIN(x)						DISEQC_DSCU_RX_CTL_dscu_exp_win(x)
#define	SILENCE_THRESHOLD_MAKS				DISEQC_DSCU_RX_CTL_silence_threshold_mask
#define SILENCE_THRESHOLD(x)				DISEQC_DSCU_RX_CTL_silence_threshold(x)
#define TO_VAL_MASK							DISEQC_DSCU_RX_CTL_to_val_mask
#define	TO_VAL(x)							DISEQC_DSCU_RX_CTL_to_val(x)
#define	TO_CHK_MASK							DISEQC_DSCU_RX_CTL_to_chk_mask
#define	TO_CHK(x)							DISEQC_DSCU_RX_CTL_to_chk(x)
#define	RX_PARITY_MASK						DISEQC_DSCU_RX_CTL_rx_pty_mask
#define	RX_PARITY(x)						DISEQC_DSCU_RX_CTL_rx_pty(x)

//Register:DSCU_INTR_ENA
#define DSCU_INTR_ENA                       DISEQC_DSCU_INTR_ENA_reg
#define TO_INT_ENA_MASK                     DISEQC_DSCU_INTR_ENA_to_interrupt_ena_mask
#define TO_INT_ENA                          DISEQC_DSCU_INTR_ENA_to_interrupt_ena(1)
#define TX_MSG_DONE_ENA_MASK                DISEQC_DSCU_INTR_ENA_tx_msg_done_ena_mask
#define TX_MSG_DONE_ENA                     DISEQC_DSCU_INTR_ENA_tx_msg_done_ena(1)
#define TX_DONE_ENA_MASK                    DISEQC_DSCU_INTR_ENA_tx_done_ena_mask
#define TX_DONE_ENA                         DISEQC_DSCU_INTR_ENA_tx_done_ena(1)
#define RX_FULL_ENA_MASK                    DISEQC_DSCU_INTR_ENA_rx_full_ena_mask
#define RX_FULL_ENA                         DISEQC_DSCU_INTR_ENA_rx_full_ena(1)
#define EORM_ENA_MASK                       DISEQC_DSCU_INTR_ENA_eorm_ena_mask
#define EORM_ENA                            DISEQC_DSCU_INTR_ENA_eorm_ena(1)
#define INCOMING_ENA_MASK                   DISEQC_DSCU_INTR_ENA_incoming_ena_mask
#define INCOMING_ENA                        DISEQC_DSCU_INTR_ENA_incoming_ena(1)

//Register:DSCU_INTR
#define	DSCU_INTR							DISEQC_DSCU_INTR_reg
#define	TO_INTR_INT_MASK					DISEQC_DSCU_INTR_to_interrupt_int_mask
#define TO_INTR_INT_GET(x)					DISEQC_DSCU_INTR_get_to_interrupt_int(x)
#define	TX_MSG_DONE_INT_MASK				DISEQC_DSCU_INTR_tx_msg_done_int_mask
#define TX_MSG_DONE_INT_GET(x)              DISEQC_DSCU_INTR_get_tx_msg_done_int(x)
#define	TX_DONE_INT_MASK					DISEQC_DSCU_INTR_tx_done_int_mask
#define TX_DONE_INT_GET(x)                  DISEQC_DSCU_INTR_get_tx_done_int(x)
#define RX_FULL_INT_MASK                    DISEQC_DSCU_INTR_rx_full_int_mask
#define RX_FULL_INT_GET(x)                  DISEQC_DSCU_INTR_get_rx_full_int(x)
#define RX_EORM_INT_MASK                    DISEQC_DSCU_INTR_eorm_int_mask
#define RX_EORM_INT_GET(x)                  DISEQC_DSCU_INTR_get_eorm_int(x)
#define RX_INCOMING_INT_MASK                DISEQC_DSCU_INTR_incoming_int
#define RX_INCOMING_INT_GET(x)              DISEQC_DSCU_INTR_get_incoming_int(x)
#define	INTR_CLEAN_ALL						DISEQC_DSCU_INTR_CLEAN_ALL

//Register:DSCU_RX_STATUS
#define DSCU_RX_STATUS                      DISEQC_DSCU_RX_STATUS_reg
#define	RX_TO_INTERRUPT_MASK				DISEQC_DSCU_RX_STATUS_to_interrupt_mask
#define	RX_TO_INTERRUPT_GET(x)				DISEQC_DSCU_RX_STATUS_get_to_interrupt(x)
#define	RX_COUNT_MASK						DISEQC_DSCU_RX_STATUS_rx_count_mask
#define	RX_COUNT_GET(x)						DISEQC_DSCU_RX_STATUS_get_rx_count(x)
#define	RX_FULL_MASK						DISEQC_DSCU_RX_STATUS_rx_full_mask
#define	RX_FULL_GET(x)						DISEQC_DSCU_RX_STATUS_get_rx_full(x)
#define	RX_EROM_MASK						DISEQC_DSCU_RX_STATUS_eorm_mask
#define	RX_EROM_GET(x)						DISEQC_DSCU_RX_STATUS_get_eorm(x)
#define	RX_INCOMING_MASK					DISEQC_DSCU_RX_STATUS_incoming_mask
#define	RX_INCOMING_GET(x)					DISEQC_DSCU_RX_STATUS_get_incoming(x)

//Register:DSCU_TX_STATUS
#define DSCU_TX_STATUS                      DISEQC_DSCU_TX_STATUS_reg
#define TX_COUNT_MASK                       DISEQC_DSCU_TX_STATUS_tx_count_mask
#define	TX_COUNT_GET(x)						DISEQC_DSCU_TX_STATUS_get_tx_count(x)
#define TX_MSG_DONE_MASK					DISEQC_DSCU_TX_STATUS_tx_msg_done_mask
#define	TX_MSG_DONE_GET(x)					DISEQC_DSCU_TX_STATUS_get_tx_msg_done(x)
#define TX_DONE_MASK                        DISEQC_DSCU_TX_STATUS_tx_done_mask
#define	TX_DONE_GET(x)						DISEQC_DSCU_TX_STATUS_get_tx_done(x)
#define TX_BUSY_MASK						DISEQC_DSCU_TX_STATUS_tx_busy_mask
#define	TX_BUSY_GET(x)						DISEQC_DSCU_TX_STATUS_get_tx_busy(x)

//register:DSCU_TX_BUF
#define	TX_BUF0								DISEQC_DSCU_TX_BUF0_reg
#define	TX_BUF0_MASK						DISEQC_DSCU_TX_BUF0_dscu_tx_buf_0_mask
#define	TX_BUF0_SET(x)						DISEQC_DSCU_TX_BUF0_dscu_tx_buf_0(x)
#define	TX_BUF0_GET(x)						DISEQC_DSCU_TX_BUF0_get_dscu_tx_buf_0(x)

#define TX_BUF1                             DISEQC_DSCU_TX_BUF1_reg
#define TX_BUF1_MASK                        DISEQC_DSCU_TX_BUF1_dscu_tx_buf_1_mask
#define TX_BUF1_SET(x)                      DISEQC_DSCU_TX_BUF1_dscu_tx_buf_1(x)
#define TX_BUF1_GET(x)                      DISEQC_DSCU_TX_BUF1_get_dscu_tx_buf_1(x)

#define TX_BUF2                             DISEQC_DSCU_TX_BUF2_reg
#define TX_BUF2_MASK                        DISEQC_DSCU_TX_BUF2_dscu_tx_buf_2_mask
#define TX_BUF2_SET(x)                      DISEQC_DSCU_TX_BUF2_dscu_tx_buf_2(x)
#define TX_BUF2_GET(x)                      DISEQC_DSCU_TX_BUF2_get_dscu_tx_buf_2(x)

#define TX_BUF3                             DISEQC_DSCU_TX_BUF3_reg
#define TX_BUF3_MASK                        DISEQC_DSCU_TX_BUF3_dscu_tx_buf_3_mask
#define TX_BUF3_SET(x)                      DISEQC_DSCU_TX_BUF3_dscu_tx_buf_3(x)
#define TX_BUF3_GET(x)                      DISEQC_DSCU_TX_BUF3_get_dscu_tx_buf_3(x)

#define TX_BUF4                             DISEQC_DSCU_TX_BUF4_reg
#define TX_BUF4_MASK                        DISEQC_DSCU_TX_BUF4_dscu_tx_buf_4_mask
#define TX_BUF4_SET(x)                      DISEQC_DSCU_TX_BUF4_dscu_tx_buf_4(x)
#define TX_BUF4_GET(x)                      DISEQC_DSCU_TX_BUF4_get_dscu_tx_buf_4(x)

#define TX_BUF5                             DISEQC_DSCU_TX_BUF5_reg
#define TX_BUF5_MASK                        DISEQC_DSCU_TX_BUF5_dscu_tx_buf_5_mask
#define TX_BUF5_SET(x)                      DISEQC_DSCU_TX_BUF5_dscu_tx_buf_5(x)
#define TX_BUF5_GET(x)                      DISEQC_DSCU_TX_BUF5_get_dscu_tx_buf_5(x)

#define TX_BUF6                             DISEQC_DSCU_TX_BUF6_reg
#define TX_BUF6_MASK                        DISEQC_DSCU_TX_BUF6_dscu_tx_buf_6_mask
#define TX_BUF6_SET(x)                      DISEQC_DSCU_TX_BUF6_dscu_tx_buf_6(x)
#define TX_BUF6_GET(x)                      DISEQC_DSCU_TX_BUF6_get_dscu_tx_buf_6(x)

#define TX_BUF7                             DISEQC_DSCU_TX_BUF7_reg
#define TX_BUF7_MASK                        DISEQC_DSCU_TX_BUF7_dscu_tx_buf_7_mask
#define TX_BUF7_SET(x)                      DISEQC_DSCU_TX_BUF7_dscu_tx_buf_7(x)
#define TX_BUF7_GET(x)                      DISEQC_DSCU_TX_BUF7_get_dscu_tx_buf_7(x)

//register:DSCU_RX_BUF
#define RX_BUF0                             DISEQC_DSCU_RX_BUF0_reg
#define	RX_BUF0_MASK						DISEQC_DSCU_RX_BUF0_byte0_mask
#define	RX_BUF0_GET(x)						DISEQC_DSCU_RX_BUF0_get_byte0(x)

#define RX_BUF1                             DISEQC_DSCU_RX_BUF1_reg
#define RX_BUF1_MASK                        DISEQC_DSCU_RX_BUF1_byte1_mask
#define RX_BUF1_GET(x)                      DISEQC_DSCU_RX_BUF1_get_byte1(x)

#define RX_BUF2                             DISEQC_DSCU_RX_BUF2_reg
#define RX_BUF2_MASK                        DISEQC_DSCU_RX_BUF2_byte2_mask
#define RX_BUF2_GET(x)                      DISEQC_DSCU_RX_BUF2_get_byte2(x)

#define RX_BUF3                             DISEQC_DSCU_RX_BUF3_reg
#define RX_BUF3_MASK                        DISEQC_DSCU_RX_BUF3_byte3_mask
#define RX_BUF3_GET(x)                      DISEQC_DSCU_RX_BUF3_get_byte3(x)

#define RX_BUF4                             DISEQC_DSCU_RX_BUF4_reg
#define RX_BUF4_MASK                        DISEQC_DSCU_RX_BUF4_byte4_mask
#define RX_BUF4_GET(x)                      DISEQC_DSCU_RX_BUF4_get_byte4(x)

#define RX_BUF5                             DISEQC_DSCU_RX_BUF5_reg
#define RX_BUF5_MASK                        DISEQC_DSCU_RX_BUF5_byte5_mask
#define RX_BUF5_GET(x)                      DISEQC_DSCU_RX_BUF5_get_byte5(x)

#define RX_BUF6                             DISEQC_DSCU_RX_BUF6_reg
#define RX_BUF6_MASK                        DISEQC_DSCU_RX_BUF6_byte6_mask
#define RX_BUF6_GET(x)                      DISEQC_DSCU_RX_BUF6_get_byte6(x)

#define RX_BUF7                             DISEQC_DSCU_RX_BUF7_reg
#define RX_BUF7_MASK                        DISEQC_DSCU_RX_BUF7_byte7_mask
#define RX_BUF7_GET(x)                      DISEQC_DSCU_RX_BUF7_get_byte7(x)

//Register:DSCU_INIT_EXP_WIN
#define DSCU_INIT_EXP_WIN					DISEQC_DSCU_INIT_EXP_WIN_reg
#define	INITIAL_EXPECT_WIN_MASK				DISEQC_DSCU_INIT_EXP_WIN_initial_expected_window_mask
#define	INITIAL_EXPECT_WIN(x)				DISEQC_DSCU_INIT_EXP_WIN_initial_expected_window(x)

//Register:DSCU_PM_SEL
#define DSCU_PM_SEL							DISEQC_DSCU_PM_SEL_reg
#define	DSC_PM_SEL_MASK						DISEQC_DSCU_PM_SEL_dsc_pm_sel_mask
#define	DSC_PM_SEL(x)						DISEQC_DSCU_PM_SEL_dsc_pm_sel(x)

#define _ZERO		0x00
#define _BIT0		0x01
#define _BIT1		0x02
#define _BIT2		0x04
#define _BIT3		0x08
#define _BIT4		0x10
#define _BIT5		0x20
#define _BIT6		0x40
#define _BIT7		0x80
#define _BIT8		0x0100
#define _BIT9		0x0200
#define _BIT10		0x0400
#define _BIT11		0x0800
#define _BIT12		0x1000
#define _BIT13		0x2000
#define _BIT14		0x4000
#define _BIT15		0x8000
#define _BIT16		0x10000
#define _BIT17		0x20000
#define _BIT18		0x40000
#define _BIT19		0x80000
#define _BIT20		0x100000
#define _BIT21		0x200000
#define _BIT22		0x400000
#define _BIT23		0x800000
#define _BIT24		0x1000000
#define _BIT25		0x2000000
#define _BIT26		0x4000000
#define _BIT27		0x8000000
#define _BIT28		0x10000000
#define _BIT29		0x20000000
#define _BIT30		0x40000000
#define _BIT31		0x80000000

#define write_reg32(addr, val)      rtd_outl(addr, val)
#define read_reg32(addr)            rtd_inl(addr)

#endif
