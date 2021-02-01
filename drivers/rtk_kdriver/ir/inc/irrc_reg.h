#ifndef __IRRC_REG_H
#define  __IRRC_REG_H

#include <rbus/stb_reg.h>
#include <rbus/iso_misc_reg.h>
#include <rbus/iso_misc_off_reg.h>
#include <rbus/irda_reg.h>
#include <rbus/misc_off_irda_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pinmux_reg.h>

#define PINMUX_ST_ST_CFG_1_REG				PINMUX_ST_GPIO_ST_CFG_1_reg
#define PINMUX_ST_ST_CFG_1_IRRX_MASK			PINMUX_ST_GPIO_ST_CFG_1_st_gpio_04_ps_mask 
#define PINMUX_ST_ST_CFG_1_IRRX_DATA			PINMUX_ST_GPIO_ST_CFG_1_st_gpio_04_ps(0x8)
 
#define INT_CTRL_SCPU_REG				SYS_REG_INT_CTRL_SCPU_reg
#define INT_CTRL_SCPU_ISO_INT_EN_SHIFT			SYS_REG_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_shift
#define INT_CTRL_SCPU_MISC_INT_EN_SHIFT			SYS_REG_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_shift
#define INT_CTRL_SCPU_INT_EN_WRITE_DATA			SYS_REG_INT_CTRL_SCPU_write_data_shift

#define  REG_ISR			ISO_MISC_ISR_reg
#define  REG_OFF_ISR			ISO_MISC_OFF_ISR_reg
#define  REG_IR_PSR			IRDA_IR_PSR_reg 
#define  REG_IR_PER			IRDA_IR_PER_reg
#define  REG_IR_SF			IRDA_IR_SF_reg
#define  REG_IR_DPIR			IRDA_IR_DPIR_reg
#define  REG_IR_CR			IRDA_IR_CR_reg
#define  REG_IR_RP			IRDA_IR_RP_reg 
#define  REG_IR_SR			IRDA_IR_SR_reg
#define  REG_IR_PSR_UP			IRDA_IR_PSR_UP_reg
#define  REG_IR_PER_UP			IRDA_IR_PER_UP_reg	
#define  REG_IR_CTRL_RC6		IRDA_IR_CTRL_RC6_reg
#define  REG_IR_RP2			IRDA_IR_RP2_reg
#define  REG_IR_EXT_RP_CF		IRDA_IR_EXT_RP_CF_reg
#define  REG_IR_EXT_RP_TIMING		IRDA_IR_EXT_RP_TIMING_reg
#define  REG_IR_EXT_RP_TIMING_UP	IRDA_IR_EXT_RP_TIMING_UP_reg
#define  REG_IR_PSR_RC5_RC6		IRDA_IR_PSR_RC5_RC6_reg
#define  REG_IR_PER_RC5_RC6		IRDA_IR_PER_RC5_RC6_reg
#define  REG_IR_PSR_UP_RC5_RC6		IRDA_IR_PSR_UP_RC5_RC6_reg
#define  REG_IR_PER_UP_RC5_RC6		IRDA_IR_PER_UP_RC5_RC6_reg
#define  REG_IR_CR_RC5_RC6		IRDA_IR_CR_RC5_RC6_reg
#define  REG_IR_DPIR_RC5_RC6		IRDA_IR_DPIR_RC5_RC6_reg
#define  REG_IR_RPT_CTRL_RC5_RC6	IRDA_IR_RPT_CTRL_RC5_RC6_reg
#define  REG_IR_RAW_CR			MISC_OFF_IRDA_IR_CR_reg
#define  REG_IR_RAW_SR			MISC_OFF_IRDA_IR_SR_reg
#define  REG_IR_RAW_FF   		MISC_OFF_IRDA_IR_RAW_FF_reg  
#define  REG_IR_RAW_SAMPLE_TIME  	MISC_OFF_IRDA_IR_RAW_SAMPLE_TIME_reg  
#define  REG_IR_RAW_WL   		MISC_OFF_IRDA_IR_RAW_WL_reg  
#define  REG_IR_RAW_CTRL		MISC_OFF_IRDA_IR_RAW_CTRL_reg
#define  REG_IR_RAW_DEB			MISC_OFF_IRDA_IR_RAW_DEB_reg
#define  REG_IR_RAW_SF			MISC_OFF_IRDA_IR_RAW_SF_reg

#define  REG_ISR_IR_IN_SHIFT		ISO_MISC_ISR_irda_int_shift
#define  REG_OFF_ISR_IR_IN_SHIFT	ISO_MISC_OFF_ISR_irda1_int_shift
#define	 REG_IR_CR_MAIN0_EN_MASK	IRDA_IR_CR_main0_en_mask
#define  REG_IR_CR_MAIN1_EN_MASK	IRDA_IR_CR_RC5_RC6_main1_en_mask
#define  REG_IR_CR_MAIN0_EN(data)	IRDA_IR_CR_main0_en(data)
#define  REG_IR_CR_MAIN1_EN(data)	IRDA_IR_CR_RC5_RC6_main1_en(data)
#define  REG_IR_CR_HW_INT_SHIFT		IRDA_IR_CR_ir_hwval_ie_shift
#define  REG_IR_CR_RAW_FIFO_OV_EN_SHIFT		MISC_OFF_IRDA_IR_CR_raw_fifo_ov_en_shift
#define  REG_IR_CR_RAW_FIFO_VAL_EN_SHIFT	MISC_OFF_IRDA_IR_CR_raw_fifo_val_en_shift
#define  REG_IR_CR_RAW_EN_SHIFT				MISC_OFF_IRDA_IR_CR_raw_en_shift
#define  REG_IR_RAW_SR_FIFO_OV_SHIFT		MISC_OFF_IRDA_IR_SR_raw_fifo_ov_shift
#define  REG_IR_RAW_SR_FIFO_VAL_SHIFT		MISC_OFF_IRDA_IR_SR_raw_fifo_val_shift

#ifdef CONFIG_IRDA_POWER_SAVING_MODE
#define IRDA_HW_MODE_RX_DECTECT_REG		ISO_MISC_SYSTEM_reg
#define IRDA_HW_MODE_RX_DECTECT_ON		BIT(ISO_MISC_SYSTEM_irdarxdetec_shift)

#define IRDA_RAW_MODE_RX_DECTECT_REG		ISO_MISC_OFF_SYSTEM_reg
#define IRDA_RAW_MODE_RX_DECTECT_ON		BIT(ISO_MISC_OFF_SYSTEM_irdarxdetec_shift)
#endif

#endif
