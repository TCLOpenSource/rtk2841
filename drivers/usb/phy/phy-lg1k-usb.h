/*
 * SIC LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 * Copyright(c) 2013 by LG Electronics Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef _USB_TOP_REGS_H_
#define _USB_TOP_REGS_H_

#include <linux/types.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/usb/phy.h>
#include <linux/of.h>


struct usb2_host_reset_type {
	unsigned int
	usb2_host_utmi_reset		:1,
	usb2_host_core_reset		:1,
	usb2_host_bus_reset		:1,
	reserved_0			:29;
};

union usb2_host_reset_union {
	unsigned int val;
	struct usb2_host_reset_type reg;
};

struct usb2_host_param_0_type {
	unsigned int
	ss_hubsetup_min_		:1,
	endian_ahbms_ohci_bufacc	:1,
	endian_ahbms_ehci_bufacc	:1,
	endian_ahbms_ohci		:1,
	endian_ahbms_ehci		:1,
	endian_ahbsl			:1,
	app_prt_ovrcur_i		:1,
	ss_ena_incrx_align_i		:1,
	ss_ena_incr4_i			:1,
	ss_ena_incr8_i			:1,
	ss_ena_incr16_			:1,
	ss_autoppd_on_overcur_en_i	:1,
	ss_resume_utmi_pls_dis_i	:1,
	ss_utmi_backward_enb_i		:1,
	ss_word_if_i			:1,
	ss_fladj_val_i			:6,
	ss_fladj_val_host_i		:6,
	ss_simulation_mode_i		:1,
	ohci_susp_lgcy_i		:1,
	app_start_clk_i			:1,
	reserved_0			:2;
};

union usb2_host_param_0_union {
	unsigned int val;
	struct usb2_host_param_0_type reg;
};

struct usb2_host_param_1_type {
	unsigned int
	ehci_xfer_cnt_o			:11,
	echi_prt_pwr_o			:1,
	ochi_0_bufacc_o			:1,
	ohci_0_sof_o_n			:1,
	ohci_0_smi_o_n			:1,
	ohci_0_rmtwkp_o			:1,
	ohci_0_rwe_o			:1,
	ohci_0_drwe_o			:1,
	ohci_0_globalsuspend_o		:1,
	ehci_xfer_prdc_o		:1,
	ehci_usbsts_o			:6,
	ehci_lpsmc_state_o		:4,
	ehci_pme_status_o		:1,
	ehci_bufacc_o			:1;
};

union usb2_host_param_1_union {
	unsigned int val;
	struct usb2_host_param_1_type reg;
};

struct usb2_host_param_2_type {
	unsigned int
	ohci_0_ccs_o			:1,
	ehci_power_stat_ack_o		:1,
	reserved_0			:30;
};

union usb2_host_param_2_union {
	unsigned int val;
	struct usb2_host_param_2_type reg;
};

struct usb2_host_param_3_type {
	unsigned int	tc_from_hsusb0_mon;
};

union usb2_host_param_3_union {
	unsigned int val;
	struct usb2_host_param_3_type reg;
};

struct usb2_phy_reset_type {
	unsigned int
	usb2_phy_reset			:1,
	reserved_0			:31;
};

union usb2_phy_reset_union {
	unsigned int val;
	struct usb2_phy_reset_type reg;
};

struct usb2_phy_param_0_type {
	unsigned int
	reserved_0			:2,
	phy_fsel			:3,
	phy_txrestune			:2,
	phy_txhsxvtune			:2,
	phy_txvreftune			:4,
	phy_txrisetune			:2,
	phy_txpreemppulsetune		:1,
	phy_txpreempamptune		:2,
	phy_txfslstune			:4,
	phy_sqrxtune			:3,
	phy_compdistune			:3,
	phy_commononn			:1,
	phy_refclksel			:2,
	port_reset			:1;
};

union usb2_phy_param_0_union {
	unsigned int val;
	struct usb2_phy_param_0_type reg;
};

struct usb2_bt_phy_param_0_type {
	unsigned int
	reserved_0			:1,
	phy_bt_por			:1,
	phy_fsel			:3,
	phy_txrestune			:2,
	phy_txhsxvtune			:2,
	phy_txvreftune			:4,
	phy_txrisetune			:2,
	phy_txpreemppulsetune		:1,
	phy_txpreempamptune		:2,
	phy_txfslstune			:4,
	phy_sqrxtune			:3,
	phy_compdistune			:3,
	phy_commononn			:1,
	phy_refclksel			:2,
	port_reset			:1;
};

union usb2_bt_phy_param_0_union {
	unsigned int val;
	struct usb2_bt_phy_param_0_type reg;
};


struct usb2_phy_param_1_type {
	unsigned int
	phy_bypasssel			:1,
	phy_bypassdmen			:1,
	phy_bypassdpen			:1,
	phy_bypassdmdata		:1,
	phy_bypassdpdata		:1,
	phy_otgdisable			:1,
	phy_vatestenb			:2,
	loopbackenb			:1,
	phy_siddq			:1,
	phy_testclk			:1,
	reserved_0			:5,
	phy_testdatain			:8,
	phy_testaddr			:4,
	phy_testdataoutsel		:1,
	reserved_1			:2,
	phy_atereset			:1;
};

union usb2_phy_param_1_union {
	unsigned int val;
	struct usb2_phy_param_1_type reg;
};

struct usb2_phy_param_2_type {
	unsigned int
	phy_testdataout			:4,
	reserved_0			:28;
};

union usb2_phy_param_2_union {
	unsigned int val;
	struct usb2_phy_param_2_type reg;
};

struct usb3_host_reset_type {
	unsigned int
	usb3_host_core_reset		:1,
	usb3_host_bus_reset		:1,
	reserved_0			:30;
};

union usb3_host_reset_union {
	unsigned int val;
	struct usb3_host_reset_type reg;
};

struct usb3_host_param_0_type {
	unsigned int
	fladj_30mhz_reg			:6,
	xhci_revision			:1,
	xhc_bme				:1,
	hub_vbus_inv			:1,
	hub_port_perm_attach		:2,
	hub_oc_inv			:1,
	host_u3_port_disable		:1,
	host_u2_port_disable		:1,
	host_post_power_control_present	:1,
	host_msi_enable			:1,
	bigendian_gs			:1,
	reserved_0			:15;
};

union usb3_host_param_0_union {
	unsigned int val;
	struct usb3_host_param_0_type reg;
};

struct usb3_host_param_1_type {
	unsigned int	debug_info;
};

union usb3_host_param_1_union {
	unsigned int val;
	struct usb3_host_param_1_type reg;
};

struct usb3_host_param_2_type {
	unsigned int debug_info;
};

union usb3_host_param_2_union {
	unsigned int val;
	struct usb3_host_param_2_type reg;
};

struct usb3_host_param_3_type {
	unsigned int logic_trace;
};

union usb3_host_param_3_union {
	unsigned int val;
	struct usb3_host_param_3_type reg;
};

struct usb3_host_param_4_type {
	unsigned int logic_trace;
};

union usb3_host_param_4_union {
	unsigned int val;
	struct usb3_host_param_4_type reg;
};

struct usb3_host_param_5_type {
	unsigned int
	host_current_belt		:12,
	reserved_0			:20;
};

union usb3_host_param_5_union {
	unsigned int val;
	struct usb3_host_param_5_type reg;
};

struct usb3_host_param_6_type {
	unsigned int
	awuser				:4,
	aruwer				:4,
	reserved_0			:24;
};

union usb3_host_param_6_union {
	unsigned int val;
	struct usb3_host_param_6_type reg;
};

struct usb3_phy_reset_type {
	unsigned int
	usb3_phy_reset			:1,
	reserved_0			:30,
	usb3_phy_ref_clk_sel		:1;
};

union usb3_phy_reset_union {
	unsigned int val;
	struct usb3_phy_reset_type reg;
};

struct usb3_phy_param_0_type {
	unsigned int
	reserved_0			:1,
	phy_mpll_refssc_clk_en		:1,
	phy_fsel			:6,
	phy_retenablen			:1,
	phy_commononn			:1,
	phy_lane0_tx2rx_loopbk		:1,
	phy_lane0_ext_pclk_req		:1,
	reserved_1			:5,
	phy_bypasssel			:1,
	phy_bypassdmen			:1,
	phy_bypassdpen			:1,
	phy_bypassdmdata		:1,
	phy_bypassdpdata		:1,
	phy_adpprbenb			:1,
	phy_adpdischrg			:1,
	phy_adpchrg			:1,
	phy_otgdisable			:1,
	phy_vatestenb			:2,
	phy_test_powerdown_ssp		:1,
	phy_test_powerdown_hsp		:1,
	phy_loopbkenb			:1,
	phy_atereset			:1;
};

union usb3_phy_param_0_union {
	unsigned int val;
	struct usb3_phy_param_0_type reg;
};

struct usb3_phy_param_1_type {
	unsigned int
	phy_sqrxtune			:3,
	phy_otgtune			:3,
	phy_compdistune			:3,
	phy_ssc_ref_clk_sel		:9,
	phy_ssc_range			:3,
	phy_ssc_en			:1,
	phy_ref_use_pad			:1,
	phy_ref_ssp_en			:1,
	phy_ref_clkdiv2			:1,
	phy_mpll_multiplier		:7;
};

union usb3_phy_param_1_union {
	unsigned int val;
	struct usb3_phy_param_1_type reg;
};

struct usb3_phy_param_2_type {
	unsigned int
	phy_tx_vboost_lvl		:3,
	reserved_0			:1,
	phy_pcs_tx_deemph_3p5db		:6,
	phy_los_level			:5,
	phy_txvreftune			:4,
	phy_txrisetune			:2,
	phy_txrestune			:2,
	phy_txpreemppulsetune		:1,
	phy_txpreempamptune		:2,
	phy_txhsxvtune			:2,
	phy_txfslstune			:4;
};

union usb3_phy_param_2_union {
	unsigned int val;
	struct usb3_phy_param_2_type reg;
};

struct usb3_phy_param_3_type {
	unsigned int
	phy_rtune_req			:1,
	phy_los_bias			:3,
	phy_lane0_tx_term_offset	:5,
	phy_pcs_tx_swing_full		:7,
	phy_pcs_tx_deemph_6db		:6,
	reserved_0			:10;
};

union usb3_phy_param_3_union {
	unsigned int val;
	struct usb3_phy_param_3_type reg;
};

struct usb3_phy_param_4_type {
	unsigned int
	phy_cr_data_in			:16,
	phy_cr_write			:1,
	phy_cr_read			:1,
	phy_cr_cap_data			:1,
	phy_cr_cap_addr			:1,
	reserved_0			:12;
};

union usb3_phy_param_4_union {
	unsigned int val;
	struct usb3_phy_param_4_type reg;
};

struct usb3_phy_param_5_type {
	unsigned int
	phy_cr_data_out			:16,
	phy_cr_ack			:1,
	reserved_0			:14,
	phy_rtune_ack			:1;
};

union usb3_phy_param_5_union {
	unsigned int val;
	struct usb3_phy_param_5_type reg;
};

struct usb3_phy_param_6_type {
	unsigned int
	phy_pcs_rx_los_mask_val		:10,
	Reserved_0			:22;
};

union usb3_phy_param_6_union {
	unsigned int val;
	struct usb3_phy_param_6_type reg;
};

struct usb2_host_ctrl {
	union usb2_host_reset_union	usb2_host_reset;
	union usb2_host_param_0_union	usb2_host_param0;
	union usb2_host_param_1_union	usb2_host_param1;
	union usb2_host_param_2_union	usb2_host_param2;
	union usb2_host_param_3_union	usb2_host_param3;
};

struct usb2_phy_ctrl {
	union usb2_phy_reset_union	usb2_phy_reset;
	union usb2_phy_param_0_union	usb2_phy_param0;
	union usb2_phy_param_1_union	usb2_phy_param1;
	union usb2_phy_param_2_union	usb2_phy_param2;
};
struct usb2_bt_phy_ctrl {
	union usb2_bt_phy_param_0_union	usb2_phy_param0;
	union usb2_phy_param_1_union	usb2_phy_param1;
};

union usb2_mix_phy_ctrl {
	struct usb2_phy_ctrl usb2_phy;
	struct usb2_bt_phy_ctrl bt_phy;
};


struct usb3_host_ctrl {
	union usb3_host_reset_union	usb3_host_reset;
	union usb3_host_param_0_union	usb3_host_param0;
	union usb3_host_param_1_union	usb3_host_param1;
	union usb3_host_param_2_union	usb3_host_param2;
	union usb3_host_param_3_union	usb3_host_param3;
	union usb3_host_param_4_union	usb3_host_param4;
	union usb3_host_param_5_union	usb3_host_param5;
	union usb3_host_param_6_union	usb3_host_param6;
};

struct usb3_phy_ctrl {
	union usb3_phy_reset_union	usb3_phy_reset;
	union usb3_phy_param_0_union	usb3_phy_param0;
	union usb3_phy_param_1_union	usb3_phy_param1;
	union usb3_phy_param_2_union	usb3_phy_param2;
	union usb3_phy_param_3_union	usb3_phy_param3;
	union usb3_phy_param_4_union	usb3_phy_param4;
	union usb3_phy_param_5_union	usb3_phy_param5;
	union usb3_phy_param_6_union	usb3_phy_param6;
};


struct usb2_ctrl_reg {
	struct usb2_host_ctrl		*host;
	union usb2_mix_phy_ctrl		*phy;
};

struct usb3_ctrl_reg {
	struct usb3_host_ctrl		*host;
	struct usb3_phy_ctrl		*phy;
};

struct lg1k_usbphy {
	int id;
	struct usb_phy phy;
	struct device *dev;
	char *parent_name;
	void __iomem *base_addr;
	void __iomem *host_reg;
	void __iomem *phy_reg;
	void __iomem *pin_mux;
	void __iomem *gbl_reg;
	void __iomem *syntop;
	int ctl_gpio;
	int ocd_gpio;
	int rst_gpio;
	int rx_eq_val;
	int syntop_val;
	int utmi_val;
	int hw_initialized;
};

struct usb_lg1k_data {
	char const *name;
	int *id;
	void *pdata;
};

#define phy_to_lgphy(x)		container_of((x), struct lg1k_usbphy, phy)

#define phy_offset(n, m) offsetof(struct usb##n##_phy_ctrl, usb##n##_phy_##m)
#define bt_phy_offset(m) offsetof(struct usb2_bt_phy_ctrl, usb2_phy_##m)
#define host_offset(n, m) offsetof(struct usb##n##_host_ctrl, usb##n##_host_##m)

extern int lg1k_usbphy_parse_dt(struct lg1k_usbphy *lgphy);
extern int lg1k_usbphy_set_type(struct usb_phy *phy, enum usb_phy_type type);
extern int lg1k_usbphy_set_vbus(struct usb_phy *phy, int on);
extern void lg1k_usbphy_shutdown(struct usb_phy *phy);
extern int lg1k_usbphy_set_wakeup(struct usb_phy *phy, bool enabled);
extern int lg1k_usbphy_set_suspend(struct usb_phy *phy, int suspend);
extern void lg1k_usbphy_remove(struct lg1k_usbphy *lgphy);
#endif	/* _USB_TOP_REGS_H_*/
