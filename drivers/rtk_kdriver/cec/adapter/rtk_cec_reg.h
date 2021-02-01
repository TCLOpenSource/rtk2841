/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_CEC_REG_H__
#define __RTK_CEC_REG_H__

#include "rtk_cec_priv.h"


#define CEC_MODEL_NAME		        "RTD"
#define CEC_DRIVE_NAME			    ("rtd_cec")


// Interrupt Configurations
#include <mach/irqs.h>
#include <rbus/sys_reg_reg.h>
#define ISO_IRQ						IRQ_CEC
#define CEC_INT_EN					SYS_REG_INT_CTRL_SCPU_reg
#define CEC_INT_EN_MASK			SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask
#define CEC_INT_EN_VAL				SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask
#define CEC_INT_EN_WRITE_DATA		SYS_REG_INT_CTRL_SCPU_write_data_mask	
// Device Registers

#include <rbus/cec_reg.h>
#define CEC_CR0			                CEC_CEC_CR0_reg
#define CEC_RTCR0		                CEC_CEC_RTCR0_reg
#define CEC_RXCR0		                CEC_CEC_RxCR0_reg
#define CEC_TXCR0		                CEC_CEC_TxCR0_reg
#define CEC_TXDR0		                CEC_CEC_TxDR0_reg
#define CEC_TXDR1		                CEC_CEC_TxDR1_reg
#define CEC_TXDR2		                CEC_CEC_TxDR2_reg
#define CEC_TXDR3		                CEC_CEC_TxDR3_reg
#define CEC_TXDR4		                CEC_CEC_TxDR4_reg
#define CEC_RXDR1		                CEC_CEC_RxDR1_reg
#define CEC_RXDR2		                CEC_CEC_RxDR2_reg
#define CEC_RXDR3		                CEC_CEC_RxDR3_reg
#define CEC_RXDR4		                CEC_CEC_RxDR4_reg
#define CEC_RXTCR0		                CEC_CEC_RxTCR0_reg
#define CEC_TXTCR0		                CEC_CEC_TxTCR0_reg
#define CEC_TXTCR1		                CEC_CEC_TxTCR1_reg
#define CEC_RxACKTCR0		            CEC_CEC_RxACKTCR0_reg
#define CEC_RxACKTCR1		            CEC_CEC_RxACKTCR1_reg
#define GDI_CEC_COMPARE_OPCODE_01	    CEC_GDI_CEC_COMPARE_OPCODE_01_reg
#define GDI_CEC_SEND_OPCODE_01		    CEC_GDI_CEC_SEND_OPCODE_01_reg
#define GDI_CEC_SEND_OPERAND_NUMBER_01	CEC_GDI_CEC_SEND_OPERAND_NUMBER_01_reg
#define GDI_CEC_OPERAND_01		        CEC_GDI_CEC_OPERAND_01_reg
#define GDI_CEC_OPERAND_02		        CEC_GDI_CEC_OPERAND_02_reg
#define GDI_CEC_OPERAND_03		        CEC_GDI_CEC_OPERAND_03_reg
#define GDI_CEC_COMPARE_OPCODE_02	    CEC_GDI_CEC_COMPARE_OPCODE_02_reg
#define GDI_CEC_SEND_OPCODE_02		    CEC_GDI_CEC_SEND_OPCODE_02_reg
#define GDI_CEC_SEND_OPERAND_NUMBER_02	CEC_GDI_CEC_SEND_OPERAND_NUMBER_02_reg
#define GDI_CEC_OPERAND_04		        CEC_GDI_CEC_OPERAND_04_reg
#define GDI_CEC_OPERAND_05		        CEC_GDI_CEC_OPERAND_05_reg
#define GDI_CEC_OPERAND_06		        CEC_GDI_CEC_OPERAND_06_reg
#define GDI_CEC_COMPARE_OPCODE_03	    CEC_GDI_CEC_COMPARE_OPCODE_03_reg
#define GDI_CEC_SEND_OPCODE_03		    CEC_GDI_CEC_SEND_OPCODE_03_reg
#define GDI_CEC_SEND_OPERAND_NUMBER_03	CEC_GDI_CEC_SEND_OPERAND_NUMBER_03_reg
#define GDI_CEC_OPERAND_07		        CEC_GDI_CEC_OPERAND_07_reg
#define GDI_CEC_OPERAND_08		        CEC_GDI_CEC_OPERAND_08_reg
#define GDI_CEC_OPERAND_09		        CEC_GDI_CEC_OPERAND_09_reg
#define GDI_CEC_COMPARE_OPCODE_04	    CEC_GDI_CEC_COMPARE_OPCODE_04_reg
#define GDI_CEC_SEND_OPCODE_04		    CEC_GDI_CEC_SEND_OPCODE_04_reg
#define GDI_CEC_SEND_OPERAND_NUMBER_04	CEC_GDI_CEC_SEND_OPERAND_NUMBER_04_reg
#define GDI_CEC_OPERAND_10		        CEC_GDI_CEC_OPERAND_10_reg
#define GDI_CEC_OPERAND_11		        CEC_GDI_CEC_OPERAND_11_reg
#define GDI_CEC_OPERAND_12		        CEC_GDI_CEC_OPERAND_12_reg
#define GDI_CEC_COMPARE_OPCODE_05	    CEC_GDI_CEC_COMPARE_OPCODE_05_reg
#define GDI_CEC_COMPARE_OPCODE_06	    CEC_GDI_CEC_COMPARE_OPCODE_06_reg
#define GDI_CEC_COMPARE_OPCODE_07	    CEC_GDI_CEC_COMPARE_OPCODE_07_reg
#define GDI_CEC_COMPARE_OPCODE_08	    CEC_GDI_CEC_COMPARE_OPCODE_08_reg
#define GDI_CEC_COMPARE_OPCODE_09	    CEC_GDI_CEC_COMPARE_OPCODE_09_reg
#define GDI_CEC_COMPARE_OPCODE_10	    CEC_GDI_CEC_COMPARE_OPCODE_10_reg
#define GDI_CEC_COMPARE_OPCODE_11	    CEC_GDI_CEC_COMPARE_OPCODE_11_reg
#define GDI_CEC_COMPARE_OPCODE_12	    CEC_GDI_CEC_COMPARE_OPCODE_12_reg
#define GDI_CEC_COMPARE_OPCODE_13	    CEC_GDI_CEC_COMPARE_OPCODE_13_reg
#define GDI_CEC_COMPARE_OPCODE_14	    CEC_GDI_CEC_COMPARE_OPCODE_14_reg
#define GDI_CEC_COMPARE_OPCODE_15	    CEC_GDI_CEC_COMPARE_OPCODE_15_reg
#define GDI_CEC_OPCODE_ENABLE		    CEC_GDI_CEC_OPCODE_ENABLE_reg
#define GDI_POWER_SAVING_MODE		    CEC_GDI_POWER_SAVING_MODE_reg
#define CEC_TxRxACKOPTION		        CEC_CEC_TxRxACKOPTION_reg

// CLKEN
#define CLKEN_CEC		(0x1<<7)
#define RSTN_CEC		(0x1<<7)

/* CR0 */
#define LOGICAL_ADDR_SHIFT	CEC_CEC_CR0_logical_addr_shift
#define CEC_MODE(x)		    CEC_CEC_CR0_cec_mode(x)
#define TEST_MODE_PAD_EN	CEC_CEC_CR0_test_mode_pad_en(1)
#define LOGICAL_ADDR(x)		CEC_CEC_CR0_logical_addr(x)
#define TIMER_DIV(x)		CEC_CEC_CR0_timer_div(x)
#define PRE_DIV(x)		    CEC_CEC_CR0_pre_div(x)
#define UNREG_ACK_EN		CEC_CEC_CR0_unreg_ack_en(1)
#define CDC_ARBITRATION_EN	CEC_CEC_CR0_cdc_arbitration_en(1)
#define TEST_MODE_DATA(x)	CEC_CEC_CR0_test_mode_pad_data(x)

#define CEC_MODE_MASK		(CEC_MODE(3))
#define LOGICAL_ADDR_MASK	(LOGICAL_ADDR(0xF))
#define CTRL_MASK1		    (CEC_MODE_MASK | LOGICAL_ADDR_MASK)

/* RTCR0 */
#define CEC_PAD_IN		    CEC_CEC_RTCR0_cec_pad_in(1)
#define	CEC_PAD_EN		    CEC_CEC_RTCR0_cec_pad_en(1)
#define	CEC_PAD_EN_MODE		CEC_CEC_RTCR0_cec_pad_en_mode(1)
#define	CEC_HW_RETRY_EN		CEC_CEC_RTCR0_cec_hw_retry_en(1)

#define CLEAR_CEC_INT		CEC_CEC_RTCR0_clear_cec_int(1)
#define WT_CNT(x)		    CEC_CEC_RTCR0_wt_cnt(x)
#define LATTEST			    CEC_CEC_RTCR0_lattest(1)
#define RETRY_NO_MASK		CEC_CEC_RTCR0_retry_no_mask
#define RETRY_NO(x)		    CEC_CEC_RTCR0_get_retry_no(x)

/* RXCR0 */
#define INIT_ADDR_SHIFT		CEC_CEC_RxCR0_init_addr_shift

#define BROADCAST_ADDR		CEC_CEC_RxCR0_broadcast_addr_mask
#define RX_SAME_LA_ACK		CEC_CEC_RxCR0_rx_same_la_ack_mask
#define STB_ADDR_SEL		CEC_CEC_RxCR0_standby_addr_sel_mask
#define STB_INIT_ADDR(x)	CEC_CEC_RxCR0_standby_init_addr(x)
#define RX_EN			    CEC_CEC_RxCR0_rx_en(1)
#define RX_RST			    CEC_CEC_RxCR0_rx_rst(1)
#define RX_CONTINUOUS		CEC_CEC_RxCR0_rx_continuous(1)
#define RX_INT_EN		    CEC_CEC_RxCR0_rx_int_en(1)
#define INIT_ADDR(x)		CEC_CEC_RxCR0_init_addr(x)
#define RX_EOM			    CEC_CEC_RxCR0_rx_eom(1)
#define RX_INT			    CEC_CEC_RxCR0_rx_int(1)
#define RX_FIFO_OV		    CEC_CEC_RxCR0_rx_fifo_ov(0x1)
#define RX_FIFO_CNT(x)		CEC_CEC_RxCR0_rx_fifo_cnt(x)

#define INIT_ADDR_MASK		CEC_CEC_RxCR0_init_addr_mask

/* TXCR0 */
#define TX_ADDR_EN		    CEC_CEC_TxCR0_tx_addr_en(1)
#define TX_ADDR(x)		    CEC_CEC_TxCR0_tx_addr(x)
#define TX_EN			    CEC_CEC_TxCR0_tx_en(1)
#define TX_RST			    CEC_CEC_TxCR0_tx_rst(1)
#define TX_CONTINUOUS		CEC_CEC_TxCR0_tx_continuous(1)
#define TX_INT_EN		    CEC_CEC_TxCR0_tx_int_en(1)
#define DEST_ADDR(x)		CEC_CEC_TxCR0_dest_addr(x)
#define TX_EOM			    CEC_CEC_TxCR0_tx_eom(1)
#define TX_INT			    CEC_CEC_TxCR0_tx_int(1)
#define TX_FIFO_UD		    CEC_CEC_TxCR0_tx_fifo_ud(1)
#define TX_FIFO_CNT(x)		CEC_CEC_TxCR0_tx_fifo_cnt(x)

/* TXDR0 */
#define TX_ADD_CNT		    CEC_CEC_TxDR0_tx_add_cnt(1)
#define RX_SUB_CNT		    CEC_CEC_TxDR0_rx_sub_cnt(1)
#define FIFO_CNT(x)		    CEC_CEC_TxDR0_fifo_cnt(x)

/* RXTCR0 */
#define RX_START_LOW(x)		CEC_CEC_RxTCR0_rx_start_low(x)
#define RX_START_PERIOD(x)	CEC_CEC_RxTCR0_rx_start_period(x)
#define RX_DATA_SAMPLE(x)	CEC_CEC_RxTCR0_rx_data_sample(x)
#define RX_DATA_PERIOD(x)	CEC_CEC_RxTCR0_rx_data_period(x)

/* TXCR0/1 */
#define TX_START_LOW(x)		CEC_CEC_TxTCR0_tx_start_low(x)
#define TX_START_HIGH(x)	CEC_CEC_TxTCR0_tx_start_high(x)

#define TX_DATA_LOW(x)		CEC_CEC_TxTCR1_tx_data_low(x)
#define TX_DATA_01(x)		CEC_CEC_TxTCR1_tx_data_01(x)
#define TX_DATA_HIGH(x)		CEC_CEC_TxTCR1_tx_data_high(x)

// RxACKTCR1
#define RX_ACK_LOW_SEL		CEC_CEC_RxACKTCR0_rx_ack_wait_1_sel(1)
#define RX_ACK_BIT_SEL		CEC_CEC_RxACKTCR0_rx_ack_wait_2_sel(1)
#define RX_ACK_ACK_LINE_ERR_SEL	CEC_CEC_RxACKTCR0_rx_ack_wait_3_sel(1)
#define RX_ACK_LOW(x)		CEC_CEC_RxACKTCR0_rx_ack_wait_1(x)
#define RX_ACK_BIT(x)		CEC_CEC_RxACKTCR0_rx_ack_wait_2(x)
#define RX_ACK_LINE_ERR(x)	CEC_CEC_RxACKTCR0_rx_ack_wait_3(x)


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

#endif // __CEC_RTK_REG_H__
