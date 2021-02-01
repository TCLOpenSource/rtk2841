/**************************************************************
// Spec Version                  : 0.0.5
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2016/6/1 11:13:58
***************************************************************/


#ifndef _USB_REG_H_INCLUDED_
#define _USB_REG_H_INCLUDED_

/*---------------------------------------------------------
 * Type : XHCI Host Control Registers
 * Register Base : 0xb8050000  
 * Document : xHCI_Specification_for_USB.pdf
 *---------------------------------------------------------*/
#define HMAC_HOST_xhci_ctrl_start_reg	        0xb8050000              // Base Register of the XHCI controller
#define HMAC_HOST_xhci_ctrl_end_reg		        0xb805005F
#define HMAC_HOST_xhci_portsc_usb2_start_reg	0xB8050420
#define HMAC_HOST_xhci_portsc_end_reg		    0xB80504FF
#define HMAC_HOST_xhci_portsc_usb3_start_reg	0xB8050460
#define HMAC_HOST_xhci_ctrl_USBCMD_reg	        0xb8050020
#define HMAC_HOST_xhci_ctrl_USBSTS_reg	        0xb8050024
#define HMAC_HOST_xhci_ctrl_CONFIG_reg	        0xb8050058
#define HMAC_HOST_xhci_portsc_PORTPMSC_reg      0xb8050424

/*---------------------------------------------------------
 * Registers below are defined in DWC_usb3_host_databook_2.70a.pdf
 * Provider : Snopsys
 *---------------------------------------------------------*/
#define HMAC_HOST_xhci_Regbase  		(0xb8058100 - 0xC100)
#define HMAC_HOST_xhci_GTXTHRCFG		(HMAC_HOST_xhci_Regbase + 0xC108)
#define HMAC_HOST_xhci_GRXTHRCFG		(HMAC_HOST_xhci_Regbase + 0xC10C)
#define HMAC_PHY_setting_start_reg		(HMAC_HOST_xhci_Regbase + 0xC200)
#define HMAC_HOST_xhci_USB2PHYCFG0		(HMAC_HOST_xhci_Regbase + 0xC200)
#define HMAC_HOST_xhci_USB2PHYCFG1		(HMAC_HOST_xhci_Regbase + 0xC204)
#define HMAC_HOST_xhci_USB2PHYCFG2		(HMAC_HOST_xhci_Regbase + 0xC208)
#define HMAC_HOST_xhci_USB2PHYCFG3		(HMAC_HOST_xhci_Regbase + 0xC20C)
#define HMAC_HOST_xhci_GUSB2PHYACC0		(HMAC_HOST_xhci_Regbase + 0xC280)
#define HMAC_HOST_xhci_GUSB2PHYACC1		(HMAC_HOST_xhci_Regbase + 0xC284)
#define HMAC_HOST_xhci_GUSB2PHYACC2		(HMAC_HOST_xhci_Regbase + 0xC288)
#define HMAC_HOST_xhci_GUSB2PHYACC3		(HMAC_HOST_xhci_Regbase + 0xC28C)



/*---------------------------------------------------------
 * Registers below are defined in Merlin2_DesignSpec-USB.doc
 *---------------------------------------------------------*/
#ifdef  _USB_USE_STRUCT
typedef struct
{
unsigned int     reserved_0:28;
unsigned int     sram_debug_sel:1;
unsigned int     sram_debug_mode:1;
unsigned int     dbus_multi_req_disable:1;
unsigned int     dev_mode:1;
}WRAP_CTR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     host_int:1;
}GNR_INT;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     reset_utmi_p3:1;
unsigned int     reset_utmi_p2:1;
unsigned int     reset_utmi_p1:1;
unsigned int     reset_utmi_p0:1;
}USB2_PHY_UTMI;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     reset_pipe3_p0:1;
}USB3_PHY_PIPE;

typedef struct 
{
unsigned int     data:16;
unsigned int     phy_addr:3;
unsigned int     phy_reg_addr:5;
unsigned int     mdio_busy:1;
unsigned int     mdio_st:2;
unsigned int     mdio_rdy:1;
unsigned int     mclk_rate:2;
unsigned int     mdio_srst:1;
unsigned int     mdio_rdwr:1;
}MDIO_CTR;

typedef struct 
{
unsigned int     p3_vstatus_out:8;
unsigned int     p2_vstatus_out:8;
unsigned int     p1_vstatus_out:8;
unsigned int     p0_vstatus_out:8;
}VSTATUS0_OUT;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     simulation_mode_p3:1;
unsigned int     force_hs_mode_p3:1;
unsigned int     test_rst_p3:1;
unsigned int     test_en_p3:1;
unsigned int     simulation_mode_p2:1;
unsigned int     force_hs_mode_p2:1;
unsigned int     test_rst_p2:1;
unsigned int     test_en_p2:1;
unsigned int     simulation_mode_p1:1;
unsigned int     force_hs_mode_p1:1;
unsigned int     test_rst_p1:1;
unsigned int     test_en_p1:1;
unsigned int     simulation_mode_p0:1;
unsigned int     force_hs_mode_p0:1;
unsigned int     test_rst_p0:1;
unsigned int     test_en_p0:1;
}SLP_BACK0_EN;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     test_speed_p0:2;
unsigned int     test_seed_p0:8;
unsigned int     test_psl_p0:2;
}SLP_BACK0_CTR;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     test_fail_p0:1;
unsigned int     test_done_p0:1;
}SLP_BACK0_ST;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p0_usb2phy_slb_hs:1;
unsigned int     p0_usb2phy_force_slb:1;
}PHY2_SLB0_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p0_usb2phy_slb_fail:1;
unsigned int     p0_usb2phy_slb_done:1;
}PHY2_SLB0_ST;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     test_speed_p1:2;
unsigned int     test_seed_p1:8;
unsigned int     test_psl_p1:2;
}SLP_BACK1_CTR;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     test_fail_p1:1;
unsigned int     test_done_p1:1;
}SLP_BACK1_ST;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p1_usb2phy_slb_hs:1;
unsigned int     p1_usb2phy_force_slb:1;
}PHY2_SLB1_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p1_usb2phy_slb_fail:1;
unsigned int     p1_usb2phy_slb_done:1;
}PHY2_SLB1_ST;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     test_speed_p2:2;
unsigned int     test_seed_p2:8;
unsigned int     test_psl_p2:2;
}SLP_BACK2_CTR;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     test_fail_p2:1;
unsigned int     test_done_p2:1;
}SLP_BACK2_ST;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p2_usb2phy_slb_hs:1;
unsigned int     p2_usb2phy_force_slb:1;
}PHY2_SLB2_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p2_usb2phy_slb_fail:1;
unsigned int     p2_usb2phy_slb_done:1;
}PHY2_SLB2_ST;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     test_speed_p3:2;
unsigned int     test_seed_p3:8;
unsigned int     test_psl_p3:2;
}SLP_BACK3_CTR;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     test_fail_p3:1;
unsigned int     test_done_p3:1;
}SLP_BACK3_ST;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p3_usb2phy_slb_hs:1;
unsigned int     p3_usb2phy_force_slb:1;
}PHY2_SLB3_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p3_usb2phy_slb_fail:1;
unsigned int     p3_usb2phy_slb_done:1;
}PHY2_SLB3_ST;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     p3_suspend_r:1;
unsigned int     p2_suspend_r:1;
unsigned int     p1_suspend_r:1;
unsigned int     p0_suspend_r:1;
}USB2_SPD_CTR;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     p0_pipe_bist_sel:2;
unsigned int     p0_pipe_bist_en:1;
}PHY3_SLB_EN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     p0_usb3phy_slb_go:1;
}PHY3_SLB_CT;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     p0_usb3phy_slb_fail:1;
unsigned int     p0_usb3phy_slb_done:1;
}PHY3_SLB_ST;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     dbg_sel1:6;
unsigned int     dbg_sel0:6;
unsigned int     dbg_en:1;
}USB_DBG;

typedef struct 
{
unsigned int     reg1:16;
unsigned int     reg0:16;
}USB_SCTCH;

typedef struct 
{
unsigned int     test_sp_reg_0:30;
unsigned int     int_loop_status:1;
unsigned int     int_comp_status:1;
}USB_TMP_SP_0;

typedef struct 
{
unsigned int     test_sp_reg_1:32;
}USB_TMP_SP_1;

typedef struct 
{
unsigned int     test_reg_0:32;
}USB_TMP_0;

typedef struct 
{
unsigned int     test_reg_1:32;
}USB_TMP_1;

typedef struct 
{
unsigned int     test_reg_2:30;
unsigned int     usb3_eco_option2:1;
unsigned int     usb3_eco_option1:1;
}USB_TMP_2;

typedef struct 
{
unsigned int     test_reg_3:29;
unsigned int     int_loop_en:1;
unsigned int     int_comp_en:1;
unsigned int     reserved_0:1;
}USB_TMP_3;

typedef struct 
{
unsigned int     xhci_revision:1;
unsigned int     host_fladj_30mhz:6;
unsigned int     host_ppc_present:1;
unsigned int     host_msi_enable:1;
unsigned int     host_pm_pw_state_req:2;
unsigned int     hub_port_perm_attach:5;
unsigned int     reserved_0:3;
unsigned int     host_u2_port_disable:4;
unsigned int     host_u3_port_disable:1;
unsigned int     host_num_u2_port:4;
unsigned int     host_num_u3_port:4;
}HMAC_CTR0;

typedef struct 
{
unsigned int     host_utmiotg_vbusvalid:4;
unsigned int     host_mac_vbus_inv:4;
unsigned int     host_vbus_value:4;
unsigned int     host_vbus_sel:4;
unsigned int     reserved_0:4;
unsigned int     hub_port_over_cur_inv:4;
unsigned int     host_over_cur_value:4;
unsigned int     host_over_cur_sel:4;
}HMAC_CTR1;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     host_current_belt:12;
unsigned int     host_current_power_state:2;
unsigned int     host_hub_vbus_ctrl:5;
}MAC3_HST_ST;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     p0_DmPulldown:1;
unsigned int     p0_DpPulldown:1;
unsigned int     p0_IDPULLUP:1;
unsigned int     reserved_1:5;
unsigned int     p0_DmPulldown_sel:1;
unsigned int     p0_DpPulldown_sel:1;
unsigned int     p0_IDPULLUP_sel:1;
}USB2_PHY0;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     p1_DmPulldown:1;
unsigned int     p1_DpPulldown:1;
unsigned int     p1_IDPULLUP:1;
unsigned int     reserved_1:5;
unsigned int     p1_DmPulldown_sel:1;
unsigned int     p1_DpPulldown_sel:1;
unsigned int     p1_IDPULLUP_sel:1;
}USB2_PHY1;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     p2_DmPulldown:1;
unsigned int     p2_DpPulldown:1;
unsigned int     p2_IDPULLUP:1;
unsigned int     reserved_1:5;
unsigned int     p2_DmPulldown_sel:1;
unsigned int     p2_DpPulldown_sel:1;
unsigned int     p2_IDPULLUP_sel:1;
}USB2_PHY2;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     p3_DmPulldown:1;
unsigned int     p3_DpPulldown:1;
unsigned int     p3_IDPULLUP:1;
unsigned int     reserved_1:5;
unsigned int     p3_DmPulldown_sel:1;
unsigned int     p3_DpPulldown_sel:1;
unsigned int     p3_IDPULLUP_sel:1;
}USB2_PHY3;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     done_st:1;
unsigned int     reserved_1:15;
unsigned int     go_ct:1;
}RAM_CTR;

typedef struct 
{
unsigned int     sram_addr:32;
}RAM_ADDR;

typedef struct 
{
unsigned int     ram_wdata:32;
}RAM_WDATA;

typedef struct 
{
unsigned int     ram_rdata:32;
}RAM_RDATA;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     p0_count_num:19;
}PHY0_ST;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     phy3_lperiod:3;
unsigned int     phy3_hperiod:3;
unsigned int     phy3_last:2;
unsigned int     host_ovr_current_value:1;
unsigned int     host_ovr_current_sel:1;
}USB3_OVR_CT;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb3_mbias_en_p0:1;
unsigned int     usb3_bg_en_p0:1;
unsigned int     usb3_pow_gating_p0:1;
unsigned int     usb3_isolate_p0:1;
}ANA_PHY0;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb2_pow_gating_p3:1;
unsigned int     usb2_pow_gating_p2:1;
unsigned int     usb2_pow_gating_p1:1;
unsigned int     usb2_pow_gating_p0:1;
}ANA_PHY1;

typedef struct 
{
unsigned int     usb_mac_ctrl:32;
}GBL_USB_CT;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_bist_mode_host_ram_1:1;
unsigned int     usb_bist_mode_host_ram_2:1;
unsigned int     usb_bist_mode_wrap:1;
}BIST0;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_bist_done_host_ram_1:1;
unsigned int     usb_bist_done_host_ram_2:1;
unsigned int     usb_bist_done_wrap:1;
}BIST1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_bist_fail_group_host_ram_1:1;
unsigned int     usb_bist_fail_group_host_ram_2:1;
unsigned int     usb_bist_fail_group_wrap:1;
}BIST2;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb_bist_host_ram_1_fail_3:1;
unsigned int     usb_bist_host_ram_1_fail_2:1;
unsigned int     usb_bist_host_ram_1_fail_1:1;
unsigned int     usb_bist_host_ram_1_fail_0:1;
}BIST3;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb_bist_host_ram_2_fail_3:1;
unsigned int     usb_bist_host_ram_2_fail_2:1;
unsigned int     usb_bist_host_ram_2_fail_1:1;
unsigned int     usb_bist_host_ram_2_fail_0:1;
}BIST4;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     usb_bist_wrap_fail_1:1;
unsigned int     usb_bist_wrap_fail_0:1;
}BIST5;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_drf_mode_host_ram_1:1;
unsigned int     usb_drf_mode_host_ram_2:1;
unsigned int     usb_drf_mode_wrap:1;
}DRF0;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_drf_resume_host_ram_1:1;
unsigned int     usb_drf_resume_host_ram_2:1;
unsigned int     usb_drf_resume_wrap:1;
}DRF1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_drf_done_host_ram_1:1;
unsigned int     usb_drf_done_host_ram_2:1;
unsigned int     usb_drf_done_wrap:1;
}DRF2;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_drf_pause_host_ram_1:1;
unsigned int     usb_drf_pause_host_ram_2:1;
unsigned int     usb_drf_pause_wrap:1;
}DRF3;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     usb_drf_fail_group_host_ram_1:1;
unsigned int     usb_drf_fail_group_host_ram_2:1;
unsigned int     usb_drf_fail_group_wrap:1;
}DRF4;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb_drf_host_ram_1_fail_3:1;
unsigned int     usb_drf_host_ram_1_fail_2:1;
unsigned int     usb_drf_host_ram_1_fail_1:1;
unsigned int     usb_drf_host_ram_1_fail_0:1;
}DRF5;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     usb_drf_host_ram_2_fail_3:1;
unsigned int     usb_drf_host_ram_2_fail_2:1;
unsigned int     usb_drf_host_ram_2_fail_1:1;
unsigned int     usb_drf_host_ram_2_fail_0:1;
}DRF6;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     usb_drf_wrap_fail_1:1;
unsigned int     usb_drf_wrap_fail_0:1;
}DRF7;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     usb_bist_wrap_ls1:1;
unsigned int     usb_bist_wrap_rme1:1;
unsigned int     usb_bist_wrap_rm1:4;
unsigned int     usb_bist_wrap_ls0:1;
unsigned int     usb_bist_wrap_rme0:1;
unsigned int     usb_bist_wrap_rm0:4;
}BIST_OP0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     usb_usb_host_ram_1_ls3:1;
unsigned int     usb_usb_host_ram_1_rme3:1;
unsigned int     usb_usb_host_ram_1_rm3:4;
unsigned int     usb_usb_host_ram_1_ls2:1;
unsigned int     usb_usb_host_ram_1_rme2:1;
unsigned int     usb_usb_host_ram_1_rm2:4;
unsigned int     usb_usb_host_ram_1_ls1:1;
unsigned int     usb_usb_host_ram_1_rme1:1;
unsigned int     usb_usb_host_ram_1_rm1:4;
unsigned int     usb_usb_host_ram_1_ls0:1;
unsigned int     usb_usb_host_ram_1_rme0:1;
unsigned int     usb_usb_host_ram_1_rm0:4;
}BIST_OP1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     usb_usb_host_ram_2_ls3:1;
unsigned int     usb_usb_host_ram_2_rme3:1;
unsigned int     usb_usb_host_ram_2_rm3:4;
unsigned int     usb_usb_host_ram_2_ls2:1;
unsigned int     usb_usb_host_ram_2_rme2:1;
unsigned int     usb_usb_host_ram_2_rm2:4;
unsigned int     usb_usb_host_ram_2_ls1:1;
unsigned int     usb_usb_host_ram_2_rme1:1;
unsigned int     usb_usb_host_ram_2_rm1:4;
unsigned int     usb_usb_host_ram_2_ls0:1;
unsigned int     usb_usb_host_ram_2_rme0:1;
unsigned int     usb_usb_host_ram_2_rm0:4;
}BIST_OP2;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     EN_CC2_RP4P7K:1;
unsigned int     EN_CC2_RP36K:1;
unsigned int     EN_CC2_RP12K:1;
unsigned int     EN_CC2_RD:1;
unsigned int     EN_CC2_DET:1;
unsigned int     Cc2_det20:3;
unsigned int     EN_CC1_RP4P7K:1;
unsigned int     EN_CC1_RP36K:1;
unsigned int     EN_CC1_RP12K:1;
unsigned int     EN_CC1_RD:1;
unsigned int     EN_CC1_DET:1;
unsigned int     cc1_det20:3;
unsigned int     EN_SWITCH:1;
unsigned int     RXIN_SEL:1;
unsigned int     TXOUT_SEL:1;
}TC_MUX;

typedef struct 
{
unsigned int     CC2_flag:1;
unsigned int     CC1_flag:1;
unsigned int     CC2_debounce_cnt:4;
unsigned int     CC2_debounce_scale:3;
unsigned int     CC1_debounce_cnt:4;
unsigned int     CC1_debounce_scale:3;
unsigned int     CC_debounce_en:1;
unsigned int     CC2_force_val:3;
unsigned int     CC2_force_en:1;
unsigned int     CC1_force_val:3;
unsigned int     CC1_force_en:1;
unsigned int     CC_det_irq_en:1;
unsigned int     CC2_det_de_val:3;
unsigned int     CC1_det_de_val:3;
}TC_CCDET;

typedef struct 
{
unsigned int     u2_p3_suspend:1;
unsigned int     u2_p2_suspend:1;
unsigned int     u2_p1_suspend:1;
unsigned int     u2_p0_suspend:1;
unsigned int     u2_p3_portstate:5;
unsigned int     u2_p2_portstate:5;
unsigned int     u2_p1_portstate:5;
unsigned int     u2_p0_portstate:5;
unsigned int     usb30_ltdb_link_state:4;
unsigned int     usb30_ltdb_sub_state:4;
}LTSSM_REG;

typedef struct 
{
unsigned int     test_reg_4:32;
}USB_TMP_4;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     Crc_err_cnt:24;
unsigned int     Crc_cnt_sel:3;
unsigned int     Crc_cnt_rst:1;
unsigned int     Crc_cnt_en:1;
}CRC_CNT_1;

typedef struct 
{
unsigned int     Package_cnt:32;
}CRC_CNT_2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     Usb2_p3disconindic:1;
unsigned int     Usb2_p3chripindic:1;
unsigned int     Usb2_p3resetindic:1;
unsigned int     Usb2_p3resumeindic:1;
unsigned int     Usb2_p3suspendindic:1;
unsigned int     Usb2_p2disconindic:1;
unsigned int     Usb2_p2chripindic:1;
unsigned int     Usb2_p2resetindic:1;
unsigned int     Usb2_p2resumeindic:1;
unsigned int     Usb2_p2suspendindic:1;
unsigned int     Usb2_p1disconindic:1;
unsigned int     Usb2_p1chripindic:1;
unsigned int     Usb2_p1resetindic:1;
unsigned int     Usb2_p1resumeindic:1;
unsigned int     Usb2_p1suspendindic:1;
unsigned int     Usb2_p0disconindic:1;
unsigned int     Usb2_p0chripindic:1;
unsigned int     Usb2_p0resetindic:1;
unsigned int     Usb2_p0resumeindic:1;
unsigned int     Usb2_p0suspendindic:1;
unsigned int     usb3_ltssm_rdet_indic:1;
unsigned int     usb3_ltssm_ssinact_indic:1;
unsigned int     usb3_ltssm_ssdis_indic:1;
unsigned int     usb3_ltssm_hreset_indic:1;
unsigned int     usb3_ltssm_poll_indic:1;
unsigned int     usb3_ltssm_recov_indic:1;
unsigned int     usb3_ltssm_u3_indic:1;
unsigned int     usb3_ltssm_u2_indic:1;
unsigned int     usb3_ltssm_u1_indic:1;
unsigned int     usb3_indicator_clear:1;
}USB_STATE_INDICATE;

#endif


#define WRAP_CTR                                                                     0x1805A000
#define WRAP_CTR_reg_addr                                                            "0xB805A000"
#define WRAP_CTR_reg                                                                 0xB805A000
#define set_WRAP_CTR_reg(data)   (*((volatile unsigned int*) WRAP_CTR_reg)=data)
#define get_WRAP_CTR_reg   (*((volatile unsigned int*) WRAP_CTR_reg))
#define WRAP_CTR_inst_adr                                                            "0x0000"
#define WRAP_CTR_inst                                                                0x0000
#define WRAP_CTR_sram_debug_sel_shift                                                (3)
#define WRAP_CTR_sram_debug_sel_mask                                                 (0x00000008)
#define WRAP_CTR_sram_debug_sel(data)                                                (0x00000008&((data)<<3))
#define WRAP_CTR_sram_debug_sel_src(data)                                            ((0x00000008&(data))>>3)
#define WRAP_CTR_get_sram_debug_sel(data)                                            ((0x00000008&(data))>>3)
#define WRAP_CTR_sram_debug_mode_shift                                               (2)
#define WRAP_CTR_sram_debug_mode_mask                                                (0x00000004)
#define WRAP_CTR_sram_debug_mode(data)                                               (0x00000004&((data)<<2))
#define WRAP_CTR_sram_debug_mode_src(data)                                           ((0x00000004&(data))>>2)
#define WRAP_CTR_get_sram_debug_mode(data)                                           ((0x00000004&(data))>>2)
#define WRAP_CTR_dbus_multi_req_disable_shift                                        (1)
#define WRAP_CTR_dbus_multi_req_disable_mask                                         (0x00000002)
#define WRAP_CTR_dbus_multi_req_disable(data)                                        (0x00000002&((data)<<1))
#define WRAP_CTR_dbus_multi_req_disable_src(data)                                    ((0x00000002&(data))>>1)
#define WRAP_CTR_get_dbus_multi_req_disable(data)                                    ((0x00000002&(data))>>1)
#define WRAP_CTR_dev_mode_shift                                                      (0)
#define WRAP_CTR_dev_mode_mask                                                       (0x00000001)
#define WRAP_CTR_dev_mode(data)                                                      (0x00000001&((data)<<0))
#define WRAP_CTR_dev_mode_src(data)                                                  ((0x00000001&(data))>>0)
#define WRAP_CTR_get_dev_mode(data)                                                  ((0x00000001&(data))>>0)


#define GNR_INT                                                                      0x1805A004
#define GNR_INT_reg_addr                                                             "0xB805A004"
#define GNR_INT_reg                                                                  0xB805A004
#define set_GNR_INT_reg(data)   (*((volatile unsigned int*) GNR_INT_reg)=data)
#define get_GNR_INT_reg   (*((volatile unsigned int*) GNR_INT_reg))
#define GNR_INT_inst_adr                                                             "0x0001"
#define GNR_INT_inst                                                                 0x0001
#define GNR_INT_host_int_shift                                                       (0)
#define GNR_INT_host_int_mask                                                        (0x00000001)
#define GNR_INT_host_int(data)                                                       (0x00000001&((data)<<0))
#define GNR_INT_host_int_src(data)                                                   ((0x00000001&(data))>>0)
#define GNR_INT_get_host_int(data)                                                   ((0x00000001&(data))>>0)


#define USB2_PHY_UTMI                                                                0x1805A008
#define USB2_PHY_UTMI_reg_addr                                                       "0xB805A008"
#define USB2_PHY_UTMI_reg                                                            0xB805A008
#define set_USB2_PHY_UTMI_reg(data)   (*((volatile unsigned int*) USB2_PHY_UTMI_reg)=data)
#define get_USB2_PHY_UTMI_reg   (*((volatile unsigned int*) USB2_PHY_UTMI_reg))
#define USB2_PHY_UTMI_inst_adr                                                       "0x0002"
#define USB2_PHY_UTMI_inst                                                           0x0002
#define USB2_PHY_UTMI_reset_utmi_p3_shift                                            (3)
#define USB2_PHY_UTMI_reset_utmi_p3_mask                                             (0x00000008)
#define USB2_PHY_UTMI_reset_utmi_p3(data)                                            (0x00000008&((data)<<3))
#define USB2_PHY_UTMI_reset_utmi_p3_src(data)                                        ((0x00000008&(data))>>3)
#define USB2_PHY_UTMI_get_reset_utmi_p3(data)                                        ((0x00000008&(data))>>3)
#define USB2_PHY_UTMI_reset_utmi_p2_shift                                            (2)
#define USB2_PHY_UTMI_reset_utmi_p2_mask                                             (0x00000004)
#define USB2_PHY_UTMI_reset_utmi_p2(data)                                            (0x00000004&((data)<<2))
#define USB2_PHY_UTMI_reset_utmi_p2_src(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY_UTMI_get_reset_utmi_p2(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY_UTMI_reset_utmi_p1_shift                                            (1)
#define USB2_PHY_UTMI_reset_utmi_p1_mask                                             (0x00000002)
#define USB2_PHY_UTMI_reset_utmi_p1(data)                                            (0x00000002&((data)<<1))
#define USB2_PHY_UTMI_reset_utmi_p1_src(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY_UTMI_get_reset_utmi_p1(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY_UTMI_reset_utmi_p0_shift                                            (0)
#define USB2_PHY_UTMI_reset_utmi_p0_mask                                             (0x00000001)
#define USB2_PHY_UTMI_reset_utmi_p0(data)                                            (0x00000001&((data)<<0))
#define USB2_PHY_UTMI_reset_utmi_p0_src(data)                                        ((0x00000001&(data))>>0)
#define USB2_PHY_UTMI_get_reset_utmi_p0(data)                                        ((0x00000001&(data))>>0)


#define USB3_PHY_PIPE                                                                0x1805A00c
#define USB3_PHY_PIPE_reg_addr                                                       "0xB805A00C"
#define USB3_PHY_PIPE_reg                                                            0xB805A00C
#define set_USB3_PHY_PIPE_reg(data)   (*((volatile unsigned int*) USB3_PHY_PIPE_reg)=data)
#define get_USB3_PHY_PIPE_reg   (*((volatile unsigned int*) USB3_PHY_PIPE_reg))
#define USB3_PHY_PIPE_inst_adr                                                       "0x0003"
#define USB3_PHY_PIPE_inst                                                           0x0003
#define USB3_PHY_PIPE_reset_pipe3_p0_shift                                           (0)
#define USB3_PHY_PIPE_reset_pipe3_p0_mask                                            (0x00000001)
#define USB3_PHY_PIPE_reset_pipe3_p0(data)                                           (0x00000001&((data)<<0))
#define USB3_PHY_PIPE_reset_pipe3_p0_src(data)                                       ((0x00000001&(data))>>0)
#define USB3_PHY_PIPE_get_reset_pipe3_p0(data)                                       ((0x00000001&(data))>>0)


#define MDIO_CTR                                                                     0x1805A010
#define MDIO_CTR_reg_addr                                                            "0xB805A010"
#define MDIO_CTR_reg                                                                 0xB805A010
#define set_MDIO_CTR_reg(data)   (*((volatile unsigned int*) MDIO_CTR_reg)=data)
#define get_MDIO_CTR_reg   (*((volatile unsigned int*) MDIO_CTR_reg))
#define MDIO_CTR_inst_adr                                                            "0x0004"
#define MDIO_CTR_inst                                                                0x0004
#define MDIO_CTR_data_shift                                                          (16)
#define MDIO_CTR_data_mask                                                           (0xFFFF0000)
#define MDIO_CTR_data(data)                                                          (0xFFFF0000&((data)<<16))
#define MDIO_CTR_data_src(data)                                                      ((0xFFFF0000&(data))>>16)
#define MDIO_CTR_get_data(data)                                                      ((0xFFFF0000&(data))>>16)
#define MDIO_CTR_phy_addr_shift                                                      (13)
#define MDIO_CTR_phy_addr_mask                                                       (0x0000E000)
#define MDIO_CTR_phy_addr(data)                                                      (0x0000E000&((data)<<13))
#define MDIO_CTR_phy_addr_src(data)                                                  ((0x0000E000&(data))>>13)
#define MDIO_CTR_get_phy_addr(data)                                                  ((0x0000E000&(data))>>13)
#define MDIO_CTR_phy_reg_addr_shift                                                  (8)
#define MDIO_CTR_phy_reg_addr_mask                                                   (0x00001F00)
#define MDIO_CTR_phy_reg_addr(data)                                                  (0x00001F00&((data)<<8))
#define MDIO_CTR_phy_reg_addr_src(data)                                              ((0x00001F00&(data))>>8)
#define MDIO_CTR_get_phy_reg_addr(data)                                              ((0x00001F00&(data))>>8)
#define MDIO_CTR_mdio_busy_shift                                                     (7)
#define MDIO_CTR_mdio_busy_mask                                                      (0x00000080)
#define MDIO_CTR_mdio_busy(data)                                                     (0x00000080&((data)<<7))
#define MDIO_CTR_mdio_busy_src(data)                                                 ((0x00000080&(data))>>7)
#define MDIO_CTR_get_mdio_busy(data)                                                 ((0x00000080&(data))>>7)
#define MDIO_CTR_mdio_st_shift                                                       (5)
#define MDIO_CTR_mdio_st_mask                                                        (0x00000060)
#define MDIO_CTR_mdio_st(data)                                                       (0x00000060&((data)<<5))
#define MDIO_CTR_mdio_st_src(data)                                                   ((0x00000060&(data))>>5)
#define MDIO_CTR_get_mdio_st(data)                                                   ((0x00000060&(data))>>5)
#define MDIO_CTR_mdio_rdy_shift                                                      (4)
#define MDIO_CTR_mdio_rdy_mask                                                       (0x00000010)
#define MDIO_CTR_mdio_rdy(data)                                                      (0x00000010&((data)<<4))
#define MDIO_CTR_mdio_rdy_src(data)                                                  ((0x00000010&(data))>>4)
#define MDIO_CTR_get_mdio_rdy(data)                                                  ((0x00000010&(data))>>4)
#define MDIO_CTR_mclk_rate_shift                                                     (2)
#define MDIO_CTR_mclk_rate_mask                                                      (0x0000000C)
#define MDIO_CTR_mclk_rate(data)                                                     (0x0000000C&((data)<<2))
#define MDIO_CTR_mclk_rate_src(data)                                                 ((0x0000000C&(data))>>2)
#define MDIO_CTR_get_mclk_rate(data)                                                 ((0x0000000C&(data))>>2)
#define MDIO_CTR_mdio_srst_shift                                                     (1)
#define MDIO_CTR_mdio_srst_mask                                                      (0x00000002)
#define MDIO_CTR_mdio_srst(data)                                                     (0x00000002&((data)<<1))
#define MDIO_CTR_mdio_srst_src(data)                                                 ((0x00000002&(data))>>1)
#define MDIO_CTR_get_mdio_srst(data)                                                 ((0x00000002&(data))>>1)
#define MDIO_CTR_mdio_rdwr_shift                                                     (0)
#define MDIO_CTR_mdio_rdwr_mask                                                      (0x00000001)
#define MDIO_CTR_mdio_rdwr(data)                                                     (0x00000001&((data)<<0))
#define MDIO_CTR_mdio_rdwr_src(data)                                                 ((0x00000001&(data))>>0)
#define MDIO_CTR_get_mdio_rdwr(data)                                                 ((0x00000001&(data))>>0)


#define VSTATUS0_OUT                                                                 0x1805A014
#define VSTATUS0_OUT_reg_addr                                                        "0xB805A014"
#define VSTATUS0_OUT_reg                                                             0xB805A014
#define set_VSTATUS0_OUT_reg(data)   (*((volatile unsigned int*) VSTATUS0_OUT_reg)=data)
#define get_VSTATUS0_OUT_reg   (*((volatile unsigned int*) VSTATUS0_OUT_reg))
#define VSTATUS0_OUT_inst_adr                                                        "0x0005"
#define VSTATUS0_OUT_inst                                                            0x0005
#define VSTATUS0_OUT_p3_vstatus_out_shift                                            (24)
#define VSTATUS0_OUT_p3_vstatus_out_mask                                             (0xFF000000)
#define VSTATUS0_OUT_p3_vstatus_out(data)                                            (0xFF000000&((data)<<24))
#define VSTATUS0_OUT_p3_vstatus_out_src(data)                                        ((0xFF000000&(data))>>24)
#define VSTATUS0_OUT_get_p3_vstatus_out(data)                                        ((0xFF000000&(data))>>24)
#define VSTATUS0_OUT_p2_vstatus_out_shift                                            (16)
#define VSTATUS0_OUT_p2_vstatus_out_mask                                             (0x00FF0000)
#define VSTATUS0_OUT_p2_vstatus_out(data)                                            (0x00FF0000&((data)<<16))
#define VSTATUS0_OUT_p2_vstatus_out_src(data)                                        ((0x00FF0000&(data))>>16)
#define VSTATUS0_OUT_get_p2_vstatus_out(data)                                        ((0x00FF0000&(data))>>16)
#define VSTATUS0_OUT_p1_vstatus_out_shift                                            (8)
#define VSTATUS0_OUT_p1_vstatus_out_mask                                             (0x0000FF00)
#define VSTATUS0_OUT_p1_vstatus_out(data)                                            (0x0000FF00&((data)<<8))
#define VSTATUS0_OUT_p1_vstatus_out_src(data)                                        ((0x0000FF00&(data))>>8)
#define VSTATUS0_OUT_get_p1_vstatus_out(data)                                        ((0x0000FF00&(data))>>8)
#define VSTATUS0_OUT_p0_vstatus_out_shift                                            (0)
#define VSTATUS0_OUT_p0_vstatus_out_mask                                             (0x000000FF)
#define VSTATUS0_OUT_p0_vstatus_out(data)                                            (0x000000FF&((data)<<0))
#define VSTATUS0_OUT_p0_vstatus_out_src(data)                                        ((0x000000FF&(data))>>0)
#define VSTATUS0_OUT_get_p0_vstatus_out(data)                                        ((0x000000FF&(data))>>0)


#define SLP_BACK0_EN                                                                 0x1805A018
#define SLP_BACK0_EN_reg_addr                                                        "0xB805A018"
#define SLP_BACK0_EN_reg                                                             0xB805A018
#define set_SLP_BACK0_EN_reg(data)   (*((volatile unsigned int*) SLP_BACK0_EN_reg)=data)
#define get_SLP_BACK0_EN_reg   (*((volatile unsigned int*) SLP_BACK0_EN_reg))
#define SLP_BACK0_EN_inst_adr                                                        "0x0006"
#define SLP_BACK0_EN_inst                                                            0x0006
#define SLP_BACK0_EN_simulation_mode_p3_shift                                        (15)
#define SLP_BACK0_EN_simulation_mode_p3_mask                                         (0x00008000)
#define SLP_BACK0_EN_simulation_mode_p3(data)                                        (0x00008000&((data)<<15))
#define SLP_BACK0_EN_simulation_mode_p3_src(data)                                    ((0x00008000&(data))>>15)
#define SLP_BACK0_EN_get_simulation_mode_p3(data)                                    ((0x00008000&(data))>>15)
#define SLP_BACK0_EN_force_hs_mode_p3_shift                                          (14)
#define SLP_BACK0_EN_force_hs_mode_p3_mask                                           (0x00004000)
#define SLP_BACK0_EN_force_hs_mode_p3(data)                                          (0x00004000&((data)<<14))
#define SLP_BACK0_EN_force_hs_mode_p3_src(data)                                      ((0x00004000&(data))>>14)
#define SLP_BACK0_EN_get_force_hs_mode_p3(data)                                      ((0x00004000&(data))>>14)
#define SLP_BACK0_EN_test_rst_p3_shift                                               (13)
#define SLP_BACK0_EN_test_rst_p3_mask                                                (0x00002000)
#define SLP_BACK0_EN_test_rst_p3(data)                                               (0x00002000&((data)<<13))
#define SLP_BACK0_EN_test_rst_p3_src(data)                                           ((0x00002000&(data))>>13)
#define SLP_BACK0_EN_get_test_rst_p3(data)                                           ((0x00002000&(data))>>13)
#define SLP_BACK0_EN_test_en_p3_shift                                                (12)
#define SLP_BACK0_EN_test_en_p3_mask                                                 (0x00001000)
#define SLP_BACK0_EN_test_en_p3(data)                                                (0x00001000&((data)<<12))
#define SLP_BACK0_EN_test_en_p3_src(data)                                            ((0x00001000&(data))>>12)
#define SLP_BACK0_EN_get_test_en_p3(data)                                            ((0x00001000&(data))>>12)
#define SLP_BACK0_EN_simulation_mode_p2_shift                                        (11)
#define SLP_BACK0_EN_simulation_mode_p2_mask                                         (0x00000800)
#define SLP_BACK0_EN_simulation_mode_p2(data)                                        (0x00000800&((data)<<11))
#define SLP_BACK0_EN_simulation_mode_p2_src(data)                                    ((0x00000800&(data))>>11)
#define SLP_BACK0_EN_get_simulation_mode_p2(data)                                    ((0x00000800&(data))>>11)
#define SLP_BACK0_EN_force_hs_mode_p2_shift                                          (10)
#define SLP_BACK0_EN_force_hs_mode_p2_mask                                           (0x00000400)
#define SLP_BACK0_EN_force_hs_mode_p2(data)                                          (0x00000400&((data)<<10))
#define SLP_BACK0_EN_force_hs_mode_p2_src(data)                                      ((0x00000400&(data))>>10)
#define SLP_BACK0_EN_get_force_hs_mode_p2(data)                                      ((0x00000400&(data))>>10)
#define SLP_BACK0_EN_test_rst_p2_shift                                               (9)
#define SLP_BACK0_EN_test_rst_p2_mask                                                (0x00000200)
#define SLP_BACK0_EN_test_rst_p2(data)                                               (0x00000200&((data)<<9))
#define SLP_BACK0_EN_test_rst_p2_src(data)                                           ((0x00000200&(data))>>9)
#define SLP_BACK0_EN_get_test_rst_p2(data)                                           ((0x00000200&(data))>>9)
#define SLP_BACK0_EN_test_en_p2_shift                                                (8)
#define SLP_BACK0_EN_test_en_p2_mask                                                 (0x00000100)
#define SLP_BACK0_EN_test_en_p2(data)                                                (0x00000100&((data)<<8))
#define SLP_BACK0_EN_test_en_p2_src(data)                                            ((0x00000100&(data))>>8)
#define SLP_BACK0_EN_get_test_en_p2(data)                                            ((0x00000100&(data))>>8)
#define SLP_BACK0_EN_simulation_mode_p1_shift                                        (7)
#define SLP_BACK0_EN_simulation_mode_p1_mask                                         (0x00000080)
#define SLP_BACK0_EN_simulation_mode_p1(data)                                        (0x00000080&((data)<<7))
#define SLP_BACK0_EN_simulation_mode_p1_src(data)                                    ((0x00000080&(data))>>7)
#define SLP_BACK0_EN_get_simulation_mode_p1(data)                                    ((0x00000080&(data))>>7)
#define SLP_BACK0_EN_force_hs_mode_p1_shift                                          (6)
#define SLP_BACK0_EN_force_hs_mode_p1_mask                                           (0x00000040)
#define SLP_BACK0_EN_force_hs_mode_p1(data)                                          (0x00000040&((data)<<6))
#define SLP_BACK0_EN_force_hs_mode_p1_src(data)                                      ((0x00000040&(data))>>6)
#define SLP_BACK0_EN_get_force_hs_mode_p1(data)                                      ((0x00000040&(data))>>6)
#define SLP_BACK0_EN_test_rst_p1_shift                                               (5)
#define SLP_BACK0_EN_test_rst_p1_mask                                                (0x00000020)
#define SLP_BACK0_EN_test_rst_p1(data)                                               (0x00000020&((data)<<5))
#define SLP_BACK0_EN_test_rst_p1_src(data)                                           ((0x00000020&(data))>>5)
#define SLP_BACK0_EN_get_test_rst_p1(data)                                           ((0x00000020&(data))>>5)
#define SLP_BACK0_EN_test_en_p1_shift                                                (4)
#define SLP_BACK0_EN_test_en_p1_mask                                                 (0x00000010)
#define SLP_BACK0_EN_test_en_p1(data)                                                (0x00000010&((data)<<4))
#define SLP_BACK0_EN_test_en_p1_src(data)                                            ((0x00000010&(data))>>4)
#define SLP_BACK0_EN_get_test_en_p1(data)                                            ((0x00000010&(data))>>4)
#define SLP_BACK0_EN_simulation_mode_p0_shift                                        (3)
#define SLP_BACK0_EN_simulation_mode_p0_mask                                         (0x00000008)
#define SLP_BACK0_EN_simulation_mode_p0(data)                                        (0x00000008&((data)<<3))
#define SLP_BACK0_EN_simulation_mode_p0_src(data)                                    ((0x00000008&(data))>>3)
#define SLP_BACK0_EN_get_simulation_mode_p0(data)                                    ((0x00000008&(data))>>3)
#define SLP_BACK0_EN_force_hs_mode_p0_shift                                          (2)
#define SLP_BACK0_EN_force_hs_mode_p0_mask                                           (0x00000004)
#define SLP_BACK0_EN_force_hs_mode_p0(data)                                          (0x00000004&((data)<<2))
#define SLP_BACK0_EN_force_hs_mode_p0_src(data)                                      ((0x00000004&(data))>>2)
#define SLP_BACK0_EN_get_force_hs_mode_p0(data)                                      ((0x00000004&(data))>>2)
#define SLP_BACK0_EN_test_rst_p0_shift                                               (1)
#define SLP_BACK0_EN_test_rst_p0_mask                                                (0x00000002)
#define SLP_BACK0_EN_test_rst_p0(data)                                               (0x00000002&((data)<<1))
#define SLP_BACK0_EN_test_rst_p0_src(data)                                           ((0x00000002&(data))>>1)
#define SLP_BACK0_EN_get_test_rst_p0(data)                                           ((0x00000002&(data))>>1)
#define SLP_BACK0_EN_test_en_p0_shift                                                (0)
#define SLP_BACK0_EN_test_en_p0_mask                                                 (0x00000001)
#define SLP_BACK0_EN_test_en_p0(data)                                                (0x00000001&((data)<<0))
#define SLP_BACK0_EN_test_en_p0_src(data)                                            ((0x00000001&(data))>>0)
#define SLP_BACK0_EN_get_test_en_p0(data)                                            ((0x00000001&(data))>>0)


#define SLP_BACK0_CTR                                                                0x1805A01c
#define SLP_BACK0_CTR_reg_addr                                                       "0xB805A01C"
#define SLP_BACK0_CTR_reg                                                            0xB805A01C
#define set_SLP_BACK0_CTR_reg(data)   (*((volatile unsigned int*) SLP_BACK0_CTR_reg)=data)
#define get_SLP_BACK0_CTR_reg   (*((volatile unsigned int*) SLP_BACK0_CTR_reg))
#define SLP_BACK0_CTR_inst_adr                                                       "0x0007"
#define SLP_BACK0_CTR_inst                                                           0x0007
#define SLP_BACK0_CTR_test_speed_p0_shift                                            (10)
#define SLP_BACK0_CTR_test_speed_p0_mask                                             (0x00000C00)
#define SLP_BACK0_CTR_test_speed_p0(data)                                            (0x00000C00&((data)<<10))
#define SLP_BACK0_CTR_test_speed_p0_src(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK0_CTR_get_test_speed_p0(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK0_CTR_test_seed_p0_shift                                             (2)
#define SLP_BACK0_CTR_test_seed_p0_mask                                              (0x000003FC)
#define SLP_BACK0_CTR_test_seed_p0(data)                                             (0x000003FC&((data)<<2))
#define SLP_BACK0_CTR_test_seed_p0_src(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK0_CTR_get_test_seed_p0(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK0_CTR_test_psl_p0_shift                                              (0)
#define SLP_BACK0_CTR_test_psl_p0_mask                                               (0x00000003)
#define SLP_BACK0_CTR_test_psl_p0(data)                                              (0x00000003&((data)<<0))
#define SLP_BACK0_CTR_test_psl_p0_src(data)                                          ((0x00000003&(data))>>0)
#define SLP_BACK0_CTR_get_test_psl_p0(data)                                          ((0x00000003&(data))>>0)


#define SLP_BACK0_ST                                                                 0x1805A020
#define SLP_BACK0_ST_reg_addr                                                        "0xB805A020"
#define SLP_BACK0_ST_reg                                                             0xB805A020
#define set_SLP_BACK0_ST_reg(data)   (*((volatile unsigned int*) SLP_BACK0_ST_reg)=data)
#define get_SLP_BACK0_ST_reg   (*((volatile unsigned int*) SLP_BACK0_ST_reg))
#define SLP_BACK0_ST_inst_adr                                                        "0x0008"
#define SLP_BACK0_ST_inst                                                            0x0008
#define SLP_BACK0_ST_test_fail_p0_shift                                              (1)
#define SLP_BACK0_ST_test_fail_p0_mask                                               (0x00000002)
#define SLP_BACK0_ST_test_fail_p0(data)                                              (0x00000002&((data)<<1))
#define SLP_BACK0_ST_test_fail_p0_src(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK0_ST_get_test_fail_p0(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK0_ST_test_done_p0_shift                                              (0)
#define SLP_BACK0_ST_test_done_p0_mask                                               (0x00000001)
#define SLP_BACK0_ST_test_done_p0(data)                                              (0x00000001&((data)<<0))
#define SLP_BACK0_ST_test_done_p0_src(data)                                          ((0x00000001&(data))>>0)
#define SLP_BACK0_ST_get_test_done_p0(data)                                          ((0x00000001&(data))>>0)


#define PHY2_SLB0_EN                                                                 0x1805A024
#define PHY2_SLB0_EN_reg_addr                                                        "0xB805A024"
#define PHY2_SLB0_EN_reg                                                             0xB805A024
#define set_PHY2_SLB0_EN_reg(data)   (*((volatile unsigned int*) PHY2_SLB0_EN_reg)=data)
#define get_PHY2_SLB0_EN_reg   (*((volatile unsigned int*) PHY2_SLB0_EN_reg))
#define PHY2_SLB0_EN_inst_adr                                                        "0x0009"
#define PHY2_SLB0_EN_inst                                                            0x0009
#define PHY2_SLB0_EN_p0_usb2phy_slb_hs_shift                                         (1)
#define PHY2_SLB0_EN_p0_usb2phy_slb_hs_mask                                          (0x00000002)
#define PHY2_SLB0_EN_p0_usb2phy_slb_hs(data)                                         (0x00000002&((data)<<1))
#define PHY2_SLB0_EN_p0_usb2phy_slb_hs_src(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB0_EN_get_p0_usb2phy_slb_hs(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB0_EN_p0_usb2phy_force_slb_shift                                      (0)
#define PHY2_SLB0_EN_p0_usb2phy_force_slb_mask                                       (0x00000001)
#define PHY2_SLB0_EN_p0_usb2phy_force_slb(data)                                      (0x00000001&((data)<<0))
#define PHY2_SLB0_EN_p0_usb2phy_force_slb_src(data)                                  ((0x00000001&(data))>>0)
#define PHY2_SLB0_EN_get_p0_usb2phy_force_slb(data)                                  ((0x00000001&(data))>>0)


#define PHY2_SLB0_ST                                                                 0x1805A028
#define PHY2_SLB0_ST_reg_addr                                                        "0xB805A028"
#define PHY2_SLB0_ST_reg                                                             0xB805A028
#define set_PHY2_SLB0_ST_reg(data)   (*((volatile unsigned int*) PHY2_SLB0_ST_reg)=data)
#define get_PHY2_SLB0_ST_reg   (*((volatile unsigned int*) PHY2_SLB0_ST_reg))
#define PHY2_SLB0_ST_inst_adr                                                        "0x000A"
#define PHY2_SLB0_ST_inst                                                            0x000A
#define PHY2_SLB0_ST_p0_usb2phy_slb_fail_shift                                       (1)
#define PHY2_SLB0_ST_p0_usb2phy_slb_fail_mask                                        (0x00000002)
#define PHY2_SLB0_ST_p0_usb2phy_slb_fail(data)                                       (0x00000002&((data)<<1))
#define PHY2_SLB0_ST_p0_usb2phy_slb_fail_src(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB0_ST_get_p0_usb2phy_slb_fail(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB0_ST_p0_usb2phy_slb_done_shift                                       (0)
#define PHY2_SLB0_ST_p0_usb2phy_slb_done_mask                                        (0x00000001)
#define PHY2_SLB0_ST_p0_usb2phy_slb_done(data)                                       (0x00000001&((data)<<0))
#define PHY2_SLB0_ST_p0_usb2phy_slb_done_src(data)                                   ((0x00000001&(data))>>0)
#define PHY2_SLB0_ST_get_p0_usb2phy_slb_done(data)                                   ((0x00000001&(data))>>0)


#define SLP_BACK1_CTR                                                                0x1805A02c
#define SLP_BACK1_CTR_reg_addr                                                       "0xB805A02C"
#define SLP_BACK1_CTR_reg                                                            0xB805A02C
#define set_SLP_BACK1_CTR_reg(data)   (*((volatile unsigned int*) SLP_BACK1_CTR_reg)=data)
#define get_SLP_BACK1_CTR_reg   (*((volatile unsigned int*) SLP_BACK1_CTR_reg))
#define SLP_BACK1_CTR_inst_adr                                                       "0x000B"
#define SLP_BACK1_CTR_inst                                                           0x000B
#define SLP_BACK1_CTR_test_speed_p1_shift                                            (10)
#define SLP_BACK1_CTR_test_speed_p1_mask                                             (0x00000C00)
#define SLP_BACK1_CTR_test_speed_p1(data)                                            (0x00000C00&((data)<<10))
#define SLP_BACK1_CTR_test_speed_p1_src(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK1_CTR_get_test_speed_p1(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK1_CTR_test_seed_p1_shift                                             (2)
#define SLP_BACK1_CTR_test_seed_p1_mask                                              (0x000003FC)
#define SLP_BACK1_CTR_test_seed_p1(data)                                             (0x000003FC&((data)<<2))
#define SLP_BACK1_CTR_test_seed_p1_src(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK1_CTR_get_test_seed_p1(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK1_CTR_test_psl_p1_shift                                              (0)
#define SLP_BACK1_CTR_test_psl_p1_mask                                               (0x00000003)
#define SLP_BACK1_CTR_test_psl_p1(data)                                              (0x00000003&((data)<<0))
#define SLP_BACK1_CTR_test_psl_p1_src(data)                                          ((0x00000003&(data))>>0)
#define SLP_BACK1_CTR_get_test_psl_p1(data)                                          ((0x00000003&(data))>>0)


#define SLP_BACK1_ST                                                                 0x1805A030
#define SLP_BACK1_ST_reg_addr                                                        "0xB805A030"
#define SLP_BACK1_ST_reg                                                             0xB805A030
#define set_SLP_BACK1_ST_reg(data)   (*((volatile unsigned int*) SLP_BACK1_ST_reg)=data)
#define get_SLP_BACK1_ST_reg   (*((volatile unsigned int*) SLP_BACK1_ST_reg))
#define SLP_BACK1_ST_inst_adr                                                        "0x000C"
#define SLP_BACK1_ST_inst                                                            0x000C
#define SLP_BACK1_ST_test_fail_p1_shift                                              (1)
#define SLP_BACK1_ST_test_fail_p1_mask                                               (0x00000002)
#define SLP_BACK1_ST_test_fail_p1(data)                                              (0x00000002&((data)<<1))
#define SLP_BACK1_ST_test_fail_p1_src(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK1_ST_get_test_fail_p1(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK1_ST_test_done_p1_shift                                              (0)
#define SLP_BACK1_ST_test_done_p1_mask                                               (0x00000001)
#define SLP_BACK1_ST_test_done_p1(data)                                              (0x00000001&((data)<<0))
#define SLP_BACK1_ST_test_done_p1_src(data)                                          ((0x00000001&(data))>>0)
#define SLP_BACK1_ST_get_test_done_p1(data)                                          ((0x00000001&(data))>>0)


#define PHY2_SLB1_EN                                                                 0x1805A034
#define PHY2_SLB1_EN_reg_addr                                                        "0xB805A034"
#define PHY2_SLB1_EN_reg                                                             0xB805A034
#define set_PHY2_SLB1_EN_reg(data)   (*((volatile unsigned int*) PHY2_SLB1_EN_reg)=data)
#define get_PHY2_SLB1_EN_reg   (*((volatile unsigned int*) PHY2_SLB1_EN_reg))
#define PHY2_SLB1_EN_inst_adr                                                        "0x000D"
#define PHY2_SLB1_EN_inst                                                            0x000D
#define PHY2_SLB1_EN_p1_usb2phy_slb_hs_shift                                         (1)
#define PHY2_SLB1_EN_p1_usb2phy_slb_hs_mask                                          (0x00000002)
#define PHY2_SLB1_EN_p1_usb2phy_slb_hs(data)                                         (0x00000002&((data)<<1))
#define PHY2_SLB1_EN_p1_usb2phy_slb_hs_src(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB1_EN_get_p1_usb2phy_slb_hs(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB1_EN_p1_usb2phy_force_slb_shift                                      (0)
#define PHY2_SLB1_EN_p1_usb2phy_force_slb_mask                                       (0x00000001)
#define PHY2_SLB1_EN_p1_usb2phy_force_slb(data)                                      (0x00000001&((data)<<0))
#define PHY2_SLB1_EN_p1_usb2phy_force_slb_src(data)                                  ((0x00000001&(data))>>0)
#define PHY2_SLB1_EN_get_p1_usb2phy_force_slb(data)                                  ((0x00000001&(data))>>0)


#define PHY2_SLB1_ST                                                                 0x1805A038
#define PHY2_SLB1_ST_reg_addr                                                        "0xB805A038"
#define PHY2_SLB1_ST_reg                                                             0xB805A038
#define set_PHY2_SLB1_ST_reg(data)   (*((volatile unsigned int*) PHY2_SLB1_ST_reg)=data)
#define get_PHY2_SLB1_ST_reg   (*((volatile unsigned int*) PHY2_SLB1_ST_reg))
#define PHY2_SLB1_ST_inst_adr                                                        "0x000E"
#define PHY2_SLB1_ST_inst                                                            0x000E
#define PHY2_SLB1_ST_p1_usb2phy_slb_fail_shift                                       (1)
#define PHY2_SLB1_ST_p1_usb2phy_slb_fail_mask                                        (0x00000002)
#define PHY2_SLB1_ST_p1_usb2phy_slb_fail(data)                                       (0x00000002&((data)<<1))
#define PHY2_SLB1_ST_p1_usb2phy_slb_fail_src(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB1_ST_get_p1_usb2phy_slb_fail(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB1_ST_p1_usb2phy_slb_done_shift                                       (0)
#define PHY2_SLB1_ST_p1_usb2phy_slb_done_mask                                        (0x00000001)
#define PHY2_SLB1_ST_p1_usb2phy_slb_done(data)                                       (0x00000001&((data)<<0))
#define PHY2_SLB1_ST_p1_usb2phy_slb_done_src(data)                                   ((0x00000001&(data))>>0)
#define PHY2_SLB1_ST_get_p1_usb2phy_slb_done(data)                                   ((0x00000001&(data))>>0)


#define SLP_BACK2_CTR                                                                0x1805A03C
#define SLP_BACK2_CTR_reg_addr                                                       "0xB805A03C"
#define SLP_BACK2_CTR_reg                                                            0xB805A03C
#define set_SLP_BACK2_CTR_reg(data)   (*((volatile unsigned int*) SLP_BACK2_CTR_reg)=data)
#define get_SLP_BACK2_CTR_reg   (*((volatile unsigned int*) SLP_BACK2_CTR_reg))
#define SLP_BACK2_CTR_inst_adr                                                       "0x000F"
#define SLP_BACK2_CTR_inst                                                           0x000F
#define SLP_BACK2_CTR_test_speed_p2_shift                                            (10)
#define SLP_BACK2_CTR_test_speed_p2_mask                                             (0x00000C00)
#define SLP_BACK2_CTR_test_speed_p2(data)                                            (0x00000C00&((data)<<10))
#define SLP_BACK2_CTR_test_speed_p2_src(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK2_CTR_get_test_speed_p2(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK2_CTR_test_seed_p2_shift                                             (2)
#define SLP_BACK2_CTR_test_seed_p2_mask                                              (0x000003FC)
#define SLP_BACK2_CTR_test_seed_p2(data)                                             (0x000003FC&((data)<<2))
#define SLP_BACK2_CTR_test_seed_p2_src(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK2_CTR_get_test_seed_p2(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK2_CTR_test_psl_p2_shift                                              (0)
#define SLP_BACK2_CTR_test_psl_p2_mask                                               (0x00000003)
#define SLP_BACK2_CTR_test_psl_p2(data)                                              (0x00000003&((data)<<0))
#define SLP_BACK2_CTR_test_psl_p2_src(data)                                          ((0x00000003&(data))>>0)
#define SLP_BACK2_CTR_get_test_psl_p2(data)                                          ((0x00000003&(data))>>0)


#define SLP_BACK2_ST                                                                 0x1805A040
#define SLP_BACK2_ST_reg_addr                                                        "0xB805A040"
#define SLP_BACK2_ST_reg                                                             0xB805A040
#define set_SLP_BACK2_ST_reg(data)   (*((volatile unsigned int*) SLP_BACK2_ST_reg)=data)
#define get_SLP_BACK2_ST_reg   (*((volatile unsigned int*) SLP_BACK2_ST_reg))
#define SLP_BACK2_ST_inst_adr                                                        "0x0010"
#define SLP_BACK2_ST_inst                                                            0x0010
#define SLP_BACK2_ST_test_fail_p2_shift                                              (1)
#define SLP_BACK2_ST_test_fail_p2_mask                                               (0x00000002)
#define SLP_BACK2_ST_test_fail_p2(data)                                              (0x00000002&((data)<<1))
#define SLP_BACK2_ST_test_fail_p2_src(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK2_ST_get_test_fail_p2(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK2_ST_test_done_p2_shift                                              (0)
#define SLP_BACK2_ST_test_done_p2_mask                                               (0x00000001)
#define SLP_BACK2_ST_test_done_p2(data)                                              (0x00000001&((data)<<0))
#define SLP_BACK2_ST_test_done_p2_src(data)                                          ((0x00000001&(data))>>0)
#define SLP_BACK2_ST_get_test_done_p2(data)                                          ((0x00000001&(data))>>0)


#define PHY2_SLB2_EN                                                                 0x1805A044
#define PHY2_SLB2_EN_reg_addr                                                        "0xB805A044"
#define PHY2_SLB2_EN_reg                                                             0xB805A044
#define set_PHY2_SLB2_EN_reg(data)   (*((volatile unsigned int*) PHY2_SLB2_EN_reg)=data)
#define get_PHY2_SLB2_EN_reg   (*((volatile unsigned int*) PHY2_SLB2_EN_reg))
#define PHY2_SLB2_EN_inst_adr                                                        "0x0011"
#define PHY2_SLB2_EN_inst                                                            0x0011
#define PHY2_SLB2_EN_p2_usb2phy_slb_hs_shift                                         (1)
#define PHY2_SLB2_EN_p2_usb2phy_slb_hs_mask                                          (0x00000002)
#define PHY2_SLB2_EN_p2_usb2phy_slb_hs(data)                                         (0x00000002&((data)<<1))
#define PHY2_SLB2_EN_p2_usb2phy_slb_hs_src(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB2_EN_get_p2_usb2phy_slb_hs(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB2_EN_p2_usb2phy_force_slb_shift                                      (0)
#define PHY2_SLB2_EN_p2_usb2phy_force_slb_mask                                       (0x00000001)
#define PHY2_SLB2_EN_p2_usb2phy_force_slb(data)                                      (0x00000001&((data)<<0))
#define PHY2_SLB2_EN_p2_usb2phy_force_slb_src(data)                                  ((0x00000001&(data))>>0)
#define PHY2_SLB2_EN_get_p2_usb2phy_force_slb(data)                                  ((0x00000001&(data))>>0)


#define PHY2_SLB2_ST                                                                 0x1805A048
#define PHY2_SLB2_ST_reg_addr                                                        "0xB805A048"
#define PHY2_SLB2_ST_reg                                                             0xB805A048
#define set_PHY2_SLB2_ST_reg(data)   (*((volatile unsigned int*) PHY2_SLB2_ST_reg)=data)
#define get_PHY2_SLB2_ST_reg   (*((volatile unsigned int*) PHY2_SLB2_ST_reg))
#define PHY2_SLB2_ST_inst_adr                                                        "0x0012"
#define PHY2_SLB2_ST_inst                                                            0x0012
#define PHY2_SLB2_ST_p2_usb2phy_slb_fail_shift                                       (1)
#define PHY2_SLB2_ST_p2_usb2phy_slb_fail_mask                                        (0x00000002)
#define PHY2_SLB2_ST_p2_usb2phy_slb_fail(data)                                       (0x00000002&((data)<<1))
#define PHY2_SLB2_ST_p2_usb2phy_slb_fail_src(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB2_ST_get_p2_usb2phy_slb_fail(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB2_ST_p2_usb2phy_slb_done_shift                                       (0)
#define PHY2_SLB2_ST_p2_usb2phy_slb_done_mask                                        (0x00000001)
#define PHY2_SLB2_ST_p2_usb2phy_slb_done(data)                                       (0x00000001&((data)<<0))
#define PHY2_SLB2_ST_p2_usb2phy_slb_done_src(data)                                   ((0x00000001&(data))>>0)
#define PHY2_SLB2_ST_get_p2_usb2phy_slb_done(data)                                   ((0x00000001&(data))>>0)


#define SLP_BACK3_CTR                                                                0x1805A050
#define SLP_BACK3_CTR_reg_addr                                                       "0xB805A050"
#define SLP_BACK3_CTR_reg                                                            0xB805A050
#define set_SLP_BACK3_CTR_reg(data)   (*((volatile unsigned int*) SLP_BACK3_CTR_reg)=data)
#define get_SLP_BACK3_CTR_reg   (*((volatile unsigned int*) SLP_BACK3_CTR_reg))
#define SLP_BACK3_CTR_inst_adr                                                       "0x0014"
#define SLP_BACK3_CTR_inst                                                           0x0014
#define SLP_BACK3_CTR_test_speed_p3_shift                                            (10)
#define SLP_BACK3_CTR_test_speed_p3_mask                                             (0x00000C00)
#define SLP_BACK3_CTR_test_speed_p3(data)                                            (0x00000C00&((data)<<10))
#define SLP_BACK3_CTR_test_speed_p3_src(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK3_CTR_get_test_speed_p3(data)                                        ((0x00000C00&(data))>>10)
#define SLP_BACK3_CTR_test_seed_p3_shift                                             (2)
#define SLP_BACK3_CTR_test_seed_p3_mask                                              (0x000003FC)
#define SLP_BACK3_CTR_test_seed_p3(data)                                             (0x000003FC&((data)<<2))
#define SLP_BACK3_CTR_test_seed_p3_src(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK3_CTR_get_test_seed_p3(data)                                         ((0x000003FC&(data))>>2)
#define SLP_BACK3_CTR_test_psl_p3_shift                                              (0)
#define SLP_BACK3_CTR_test_psl_p3_mask                                               (0x00000003)
#define SLP_BACK3_CTR_test_psl_p3(data)                                              (0x00000003&((data)<<0))
#define SLP_BACK3_CTR_test_psl_p3_src(data)                                          ((0x00000003&(data))>>0)
#define SLP_BACK3_CTR_get_test_psl_p3(data)                                          ((0x00000003&(data))>>0)


#define SLP_BACK3_ST                                                                 0x1805A054
#define SLP_BACK3_ST_reg_addr                                                        "0xB805A054"
#define SLP_BACK3_ST_reg                                                             0xB805A054
#define set_SLP_BACK3_ST_reg(data)   (*((volatile unsigned int*) SLP_BACK3_ST_reg)=data)
#define get_SLP_BACK3_ST_reg   (*((volatile unsigned int*) SLP_BACK3_ST_reg))
#define SLP_BACK3_ST_inst_adr                                                        "0x0015"
#define SLP_BACK3_ST_inst                                                            0x0015
#define SLP_BACK3_ST_test_fail_p3_shift                                              (1)
#define SLP_BACK3_ST_test_fail_p3_mask                                               (0x00000002)
#define SLP_BACK3_ST_test_fail_p3(data)                                              (0x00000002&((data)<<1))
#define SLP_BACK3_ST_test_fail_p3_src(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK3_ST_get_test_fail_p3(data)                                          ((0x00000002&(data))>>1)
#define SLP_BACK3_ST_test_done_p3_shift                                              (0)
#define SLP_BACK3_ST_test_done_p3_mask                                               (0x00000001)
#define SLP_BACK3_ST_test_done_p3(data)                                              (0x00000001&((data)<<0))
#define SLP_BACK3_ST_test_done_p3_src(data)                                          ((0x00000001&(data))>>0)
#define SLP_BACK3_ST_get_test_done_p3(data)                                          ((0x00000001&(data))>>0)


#define PHY2_SLB3_EN                                                                 0x1805A058
#define PHY2_SLB3_EN_reg_addr                                                        "0xB805A058"
#define PHY2_SLB3_EN_reg                                                             0xB805A058
#define set_PHY2_SLB3_EN_reg(data)   (*((volatile unsigned int*) PHY2_SLB3_EN_reg)=data)
#define get_PHY2_SLB3_EN_reg   (*((volatile unsigned int*) PHY2_SLB3_EN_reg))
#define PHY2_SLB3_EN_inst_adr                                                        "0x0016"
#define PHY2_SLB3_EN_inst                                                            0x0016
#define PHY2_SLB3_EN_p3_usb2phy_slb_hs_shift                                         (1)
#define PHY2_SLB3_EN_p3_usb2phy_slb_hs_mask                                          (0x00000002)
#define PHY2_SLB3_EN_p3_usb2phy_slb_hs(data)                                         (0x00000002&((data)<<1))
#define PHY2_SLB3_EN_p3_usb2phy_slb_hs_src(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB3_EN_get_p3_usb2phy_slb_hs(data)                                     ((0x00000002&(data))>>1)
#define PHY2_SLB3_EN_p3_usb2phy_force_slb_shift                                      (0)
#define PHY2_SLB3_EN_p3_usb2phy_force_slb_mask                                       (0x00000001)
#define PHY2_SLB3_EN_p3_usb2phy_force_slb(data)                                      (0x00000001&((data)<<0))
#define PHY2_SLB3_EN_p3_usb2phy_force_slb_src(data)                                  ((0x00000001&(data))>>0)
#define PHY2_SLB3_EN_get_p3_usb2phy_force_slb(data)                                  ((0x00000001&(data))>>0)


#define PHY2_SLB3_ST                                                                 0x1805A05c
#define PHY2_SLB3_ST_reg_addr                                                        "0xB805A05C"
#define PHY2_SLB3_ST_reg                                                             0xB805A05C
#define set_PHY2_SLB3_ST_reg(data)   (*((volatile unsigned int*) PHY2_SLB3_ST_reg)=data)
#define get_PHY2_SLB3_ST_reg   (*((volatile unsigned int*) PHY2_SLB3_ST_reg))
#define PHY2_SLB3_ST_inst_adr                                                        "0x0017"
#define PHY2_SLB3_ST_inst                                                            0x0017
#define PHY2_SLB3_ST_p3_usb2phy_slb_fail_shift                                       (1)
#define PHY2_SLB3_ST_p3_usb2phy_slb_fail_mask                                        (0x00000002)
#define PHY2_SLB3_ST_p3_usb2phy_slb_fail(data)                                       (0x00000002&((data)<<1))
#define PHY2_SLB3_ST_p3_usb2phy_slb_fail_src(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB3_ST_get_p3_usb2phy_slb_fail(data)                                   ((0x00000002&(data))>>1)
#define PHY2_SLB3_ST_p3_usb2phy_slb_done_shift                                       (0)
#define PHY2_SLB3_ST_p3_usb2phy_slb_done_mask                                        (0x00000001)
#define PHY2_SLB3_ST_p3_usb2phy_slb_done(data)                                       (0x00000001&((data)<<0))
#define PHY2_SLB3_ST_p3_usb2phy_slb_done_src(data)                                   ((0x00000001&(data))>>0)
#define PHY2_SLB3_ST_get_p3_usb2phy_slb_done(data)                                   ((0x00000001&(data))>>0)


#define USB2_SPD_CTR                                                                 0x1805A060
#define USB2_SPD_CTR_reg_addr                                                        "0xB805A060"
#define USB2_SPD_CTR_reg                                                             0xB805A060
#define set_USB2_SPD_CTR_reg(data)   (*((volatile unsigned int*) USB2_SPD_CTR_reg)=data)
#define get_USB2_SPD_CTR_reg   (*((volatile unsigned int*) USB2_SPD_CTR_reg))
#define USB2_SPD_CTR_inst_adr                                                        "0x0018"
#define USB2_SPD_CTR_inst                                                            0x0018
#define USB2_SPD_CTR_p3_suspend_r_shift                                              (3)
#define USB2_SPD_CTR_p3_suspend_r_mask                                               (0x00000008)
#define USB2_SPD_CTR_p3_suspend_r(data)                                              (0x00000008&((data)<<3))
#define USB2_SPD_CTR_p3_suspend_r_src(data)                                          ((0x00000008&(data))>>3)
#define USB2_SPD_CTR_get_p3_suspend_r(data)                                          ((0x00000008&(data))>>3)
#define USB2_SPD_CTR_p2_suspend_r_shift                                              (2)
#define USB2_SPD_CTR_p2_suspend_r_mask                                               (0x00000004)
#define USB2_SPD_CTR_p2_suspend_r(data)                                              (0x00000004&((data)<<2))
#define USB2_SPD_CTR_p2_suspend_r_src(data)                                          ((0x00000004&(data))>>2)
#define USB2_SPD_CTR_get_p2_suspend_r(data)                                          ((0x00000004&(data))>>2)
#define USB2_SPD_CTR_p1_suspend_r_shift                                              (1)
#define USB2_SPD_CTR_p1_suspend_r_mask                                               (0x00000002)
#define USB2_SPD_CTR_p1_suspend_r(data)                                              (0x00000002&((data)<<1))
#define USB2_SPD_CTR_p1_suspend_r_src(data)                                          ((0x00000002&(data))>>1)
#define USB2_SPD_CTR_get_p1_suspend_r(data)                                          ((0x00000002&(data))>>1)
#define USB2_SPD_CTR_p0_suspend_r_shift                                              (0)
#define USB2_SPD_CTR_p0_suspend_r_mask                                               (0x00000001)
#define USB2_SPD_CTR_p0_suspend_r(data)                                              (0x00000001&((data)<<0))
#define USB2_SPD_CTR_p0_suspend_r_src(data)                                          ((0x00000001&(data))>>0)
#define USB2_SPD_CTR_get_p0_suspend_r(data)                                          ((0x00000001&(data))>>0)


#define PHY3_SLB_EN                                                                  0x1805A064
#define PHY3_SLB_EN_reg_addr                                                         "0xB805A064"
#define PHY3_SLB_EN_reg                                                              0xB805A064
#define set_PHY3_SLB_EN_reg(data)   (*((volatile unsigned int*) PHY3_SLB_EN_reg)=data)
#define get_PHY3_SLB_EN_reg   (*((volatile unsigned int*) PHY3_SLB_EN_reg))
#define PHY3_SLB_EN_inst_adr                                                         "0x0019"
#define PHY3_SLB_EN_inst                                                             0x0019
#define PHY3_SLB_EN_p0_pipe_bist_sel_shift                                           (1)
#define PHY3_SLB_EN_p0_pipe_bist_sel_mask                                            (0x00000006)
#define PHY3_SLB_EN_p0_pipe_bist_sel(data)                                           (0x00000006&((data)<<1))
#define PHY3_SLB_EN_p0_pipe_bist_sel_src(data)                                       ((0x00000006&(data))>>1)
#define PHY3_SLB_EN_get_p0_pipe_bist_sel(data)                                       ((0x00000006&(data))>>1)
#define PHY3_SLB_EN_p0_pipe_bist_en_shift                                            (0)
#define PHY3_SLB_EN_p0_pipe_bist_en_mask                                             (0x00000001)
#define PHY3_SLB_EN_p0_pipe_bist_en(data)                                            (0x00000001&((data)<<0))
#define PHY3_SLB_EN_p0_pipe_bist_en_src(data)                                        ((0x00000001&(data))>>0)
#define PHY3_SLB_EN_get_p0_pipe_bist_en(data)                                        ((0x00000001&(data))>>0)


#define PHY3_SLB_CT                                                                  0x1805A068
#define PHY3_SLB_CT_reg_addr                                                         "0xB805A068"
#define PHY3_SLB_CT_reg                                                              0xB805A068
#define set_PHY3_SLB_CT_reg(data)   (*((volatile unsigned int*) PHY3_SLB_CT_reg)=data)
#define get_PHY3_SLB_CT_reg   (*((volatile unsigned int*) PHY3_SLB_CT_reg))
#define PHY3_SLB_CT_inst_adr                                                         "0x001A"
#define PHY3_SLB_CT_inst                                                             0x001A
#define PHY3_SLB_CT_p0_usb3phy_slb_go_shift                                          (0)
#define PHY3_SLB_CT_p0_usb3phy_slb_go_mask                                           (0x00000001)
#define PHY3_SLB_CT_p0_usb3phy_slb_go(data)                                          (0x00000001&((data)<<0))
#define PHY3_SLB_CT_p0_usb3phy_slb_go_src(data)                                      ((0x00000001&(data))>>0)
#define PHY3_SLB_CT_get_p0_usb3phy_slb_go(data)                                      ((0x00000001&(data))>>0)


#define PHY3_SLB_ST                                                                  0x1805A06c
#define PHY3_SLB_ST_reg_addr                                                         "0xB805A06C"
#define PHY3_SLB_ST_reg                                                              0xB805A06C
#define set_PHY3_SLB_ST_reg(data)   (*((volatile unsigned int*) PHY3_SLB_ST_reg)=data)
#define get_PHY3_SLB_ST_reg   (*((volatile unsigned int*) PHY3_SLB_ST_reg))
#define PHY3_SLB_ST_inst_adr                                                         "0x001B"
#define PHY3_SLB_ST_inst                                                             0x001B
#define PHY3_SLB_ST_p0_usb3phy_slb_fail_shift                                        (1)
#define PHY3_SLB_ST_p0_usb3phy_slb_fail_mask                                         (0x00000002)
#define PHY3_SLB_ST_p0_usb3phy_slb_fail(data)                                        (0x00000002&((data)<<1))
#define PHY3_SLB_ST_p0_usb3phy_slb_fail_src(data)                                    ((0x00000002&(data))>>1)
#define PHY3_SLB_ST_get_p0_usb3phy_slb_fail(data)                                    ((0x00000002&(data))>>1)
#define PHY3_SLB_ST_p0_usb3phy_slb_done_shift                                        (0)
#define PHY3_SLB_ST_p0_usb3phy_slb_done_mask                                         (0x00000001)
#define PHY3_SLB_ST_p0_usb3phy_slb_done(data)                                        (0x00000001&((data)<<0))
#define PHY3_SLB_ST_p0_usb3phy_slb_done_src(data)                                    ((0x00000001&(data))>>0)
#define PHY3_SLB_ST_get_p0_usb3phy_slb_done(data)                                    ((0x00000001&(data))>>0)


#define USB_DBG                                                                      0x1805A070
#define USB_DBG_reg_addr                                                             "0xB805A070"
#define USB_DBG_reg                                                                  0xB805A070
#define set_USB_DBG_reg(data)   (*((volatile unsigned int*) USB_DBG_reg)=data)
#define get_USB_DBG_reg   (*((volatile unsigned int*) USB_DBG_reg))
#define USB_DBG_inst_adr                                                             "0x001C"
#define USB_DBG_inst                                                                 0x001C
#define USB_DBG_dbg_sel1_shift                                                       (7)
#define USB_DBG_dbg_sel1_mask                                                        (0x00001F80)
#define USB_DBG_dbg_sel1(data)                                                       (0x00001F80&((data)<<7))
#define USB_DBG_dbg_sel1_src(data)                                                   ((0x00001F80&(data))>>7)
#define USB_DBG_get_dbg_sel1(data)                                                   ((0x00001F80&(data))>>7)
#define USB_DBG_dbg_sel0_shift                                                       (1)
#define USB_DBG_dbg_sel0_mask                                                        (0x0000007E)
#define USB_DBG_dbg_sel0(data)                                                       (0x0000007E&((data)<<1))
#define USB_DBG_dbg_sel0_src(data)                                                   ((0x0000007E&(data))>>1)
#define USB_DBG_get_dbg_sel0(data)                                                   ((0x0000007E&(data))>>1)
#define USB_DBG_dbg_en_shift                                                         (0)
#define USB_DBG_dbg_en_mask                                                          (0x00000001)
#define USB_DBG_dbg_en(data)                                                         (0x00000001&((data)<<0))
#define USB_DBG_dbg_en_src(data)                                                     ((0x00000001&(data))>>0)
#define USB_DBG_get_dbg_en(data)                                                     ((0x00000001&(data))>>0)


#define USB_SCTCH                                                                    0x1805A074
#define USB_SCTCH_reg_addr                                                           "0xB805A074"
#define USB_SCTCH_reg                                                                0xB805A074
#define set_USB_SCTCH_reg(data)   (*((volatile unsigned int*) USB_SCTCH_reg)=data)
#define get_USB_SCTCH_reg   (*((volatile unsigned int*) USB_SCTCH_reg))
#define USB_SCTCH_inst_adr                                                           "0x001D"
#define USB_SCTCH_inst                                                               0x001D
#define USB_SCTCH_reg1_shift                                                         (16)
#define USB_SCTCH_reg1_mask                                                          (0xFFFF0000)
#define USB_SCTCH_reg1(data)                                                         (0xFFFF0000&((data)<<16))
#define USB_SCTCH_reg1_src(data)                                                     ((0xFFFF0000&(data))>>16)
#define USB_SCTCH_get_reg1(data)                                                     ((0xFFFF0000&(data))>>16)
#define USB_SCTCH_reg0_shift                                                         (0)
#define USB_SCTCH_reg0_mask                                                          (0x0000FFFF)
#define USB_SCTCH_reg0(data)                                                         (0x0000FFFF&((data)<<0))
#define USB_SCTCH_reg0_src(data)                                                     ((0x0000FFFF&(data))>>0)
#define USB_SCTCH_get_reg0(data)                                                     ((0x0000FFFF&(data))>>0)


#define USB_TMP_SP_0                                                                 0x1805A078
#define USB_TMP_SP_0_reg_addr                                                        "0xB805A078"
#define USB_TMP_SP_0_reg                                                             0xB805A078
#define set_USB_TMP_SP_0_reg(data)   (*((volatile unsigned int*) USB_TMP_SP_0_reg)=data)
#define get_USB_TMP_SP_0_reg   (*((volatile unsigned int*) USB_TMP_SP_0_reg))
#define USB_TMP_SP_0_inst_adr                                                        "0x001E"
#define USB_TMP_SP_0_inst                                                            0x001E
#define USB_TMP_SP_0_test_sp_reg_0_shift                                             (2)
#define USB_TMP_SP_0_test_sp_reg_0_mask                                              (0xFFFFFFFC)
#define USB_TMP_SP_0_test_sp_reg_0(data)                                             (0xFFFFFFFC&((data)<<2))
#define USB_TMP_SP_0_test_sp_reg_0_src(data)                                         ((0xFFFFFFFC&(data))>>2)
#define USB_TMP_SP_0_get_test_sp_reg_0(data)                                         ((0xFFFFFFFC&(data))>>2)
#define USB_TMP_SP_0_int_loop_status_shift                                           (1)
#define USB_TMP_SP_0_int_loop_status_mask                                            (0x00000002)
#define USB_TMP_SP_0_int_loop_status(data)                                           (0x00000002&((data)<<1))
#define USB_TMP_SP_0_int_loop_status_src(data)                                       ((0x00000002&(data))>>1)
#define USB_TMP_SP_0_get_int_loop_status(data)                                       ((0x00000002&(data))>>1)
#define USB_TMP_SP_0_int_comp_status_shift                                           (0)
#define USB_TMP_SP_0_int_comp_status_mask                                            (0x00000001)
#define USB_TMP_SP_0_int_comp_status(data)                                           (0x00000001&((data)<<0))
#define USB_TMP_SP_0_int_comp_status_src(data)                                       ((0x00000001&(data))>>0)
#define USB_TMP_SP_0_get_int_comp_status(data)                                       ((0x00000001&(data))>>0)


#define USB_TMP_SP_1                                                                 0x1805A07C
#define USB_TMP_SP_1_reg_addr                                                        "0xB805A07C"
#define USB_TMP_SP_1_reg                                                             0xB805A07C
#define set_USB_TMP_SP_1_reg(data)   (*((volatile unsigned int*) USB_TMP_SP_1_reg)=data)
#define get_USB_TMP_SP_1_reg   (*((volatile unsigned int*) USB_TMP_SP_1_reg))
#define USB_TMP_SP_1_inst_adr                                                        "0x001F"
#define USB_TMP_SP_1_inst                                                            0x001F
#define USB_TMP_SP_1_test_sp_reg_1_shift                                             (0)
#define USB_TMP_SP_1_test_sp_reg_1_mask                                              (0xFFFFFFFF)
#define USB_TMP_SP_1_test_sp_reg_1(data)                                             (0xFFFFFFFF&((data)<<0))
#define USB_TMP_SP_1_test_sp_reg_1_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define USB_TMP_SP_1_get_test_sp_reg_1(data)                                         ((0xFFFFFFFF&(data))>>0)


#define USB_TMP_0                                                                    0x1805A080
#define USB_TMP_0_reg_addr                                                           "0xB805A080"
#define USB_TMP_0_reg                                                                0xB805A080
#define set_USB_TMP_0_reg(data)   (*((volatile unsigned int*) USB_TMP_0_reg)=data)
#define get_USB_TMP_0_reg   (*((volatile unsigned int*) USB_TMP_0_reg))
#define USB_TMP_0_inst_adr                                                           "0x0020"
#define USB_TMP_0_inst                                                               0x0020
#define USB_TMP_0_test_reg_0_shift                                                   (0)
#define USB_TMP_0_test_reg_0_mask                                                    (0xFFFFFFFF)
#define USB_TMP_0_test_reg_0(data)                                                   (0xFFFFFFFF&((data)<<0))
#define USB_TMP_0_test_reg_0_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define USB_TMP_0_get_test_reg_0(data)                                               ((0xFFFFFFFF&(data))>>0)


#define USB_TMP_1                                                                    0x1805A084
#define USB_TMP_1_reg_addr                                                           "0xB805A084"
#define USB_TMP_1_reg                                                                0xB805A084
#define set_USB_TMP_1_reg(data)   (*((volatile unsigned int*) USB_TMP_1_reg)=data)
#define get_USB_TMP_1_reg   (*((volatile unsigned int*) USB_TMP_1_reg))
#define USB_TMP_1_inst_adr                                                           "0x0021"
#define USB_TMP_1_inst                                                               0x0021
#define USB_TMP_1_test_reg_1_shift                                                   (0)
#define USB_TMP_1_test_reg_1_mask                                                    (0xFFFFFFFF)
#define USB_TMP_1_test_reg_1(data)                                                   (0xFFFFFFFF&((data)<<0))
#define USB_TMP_1_test_reg_1_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define USB_TMP_1_get_test_reg_1(data)                                               ((0xFFFFFFFF&(data))>>0)


#define USB_TMP_2                                                                    0x1805A088
#define USB_TMP_2_reg_addr                                                           "0xB805A088"
#define USB_TMP_2_reg                                                                0xB805A088
#define set_USB_TMP_2_reg(data)   (*((volatile unsigned int*) USB_TMP_2_reg)=data)
#define get_USB_TMP_2_reg   (*((volatile unsigned int*) USB_TMP_2_reg))
#define USB_TMP_2_inst_adr                                                           "0x0022"
#define USB_TMP_2_inst                                                               0x0022
#define USB_TMP_2_test_reg_2_shift                                                   (2)
#define USB_TMP_2_test_reg_2_mask                                                    (0xFFFFFFFC)
#define USB_TMP_2_test_reg_2(data)                                                   (0xFFFFFFFC&((data)<<2))
#define USB_TMP_2_test_reg_2_src(data)                                               ((0xFFFFFFFC&(data))>>2)
#define USB_TMP_2_get_test_reg_2(data)                                               ((0xFFFFFFFC&(data))>>2)
#define USB_TMP_2_usb3_eco_option2_shift                                             (1)
#define USB_TMP_2_usb3_eco_option2_mask                                              (0x00000002)
#define USB_TMP_2_usb3_eco_option2(data)                                             (0x00000002&((data)<<1))
#define USB_TMP_2_usb3_eco_option2_src(data)                                         ((0x00000002&(data))>>1)
#define USB_TMP_2_get_usb3_eco_option2(data)                                         ((0x00000002&(data))>>1)
#define USB_TMP_2_usb3_eco_option1_shift                                             (0)
#define USB_TMP_2_usb3_eco_option1_mask                                              (0x00000001)
#define USB_TMP_2_usb3_eco_option1(data)                                             (0x00000001&((data)<<0))
#define USB_TMP_2_usb3_eco_option1_src(data)                                         ((0x00000001&(data))>>0)
#define USB_TMP_2_get_usb3_eco_option1(data)                                         ((0x00000001&(data))>>0)


#define USB_TMP_3                                                                    0x1805A08C
#define USB_TMP_3_reg_addr                                                           "0xB805A08C"
#define USB_TMP_3_reg                                                                0xB805A08C
#define set_USB_TMP_3_reg(data)   (*((volatile unsigned int*) USB_TMP_3_reg)=data)
#define get_USB_TMP_3_reg   (*((volatile unsigned int*) USB_TMP_3_reg))
#define USB_TMP_3_inst_adr                                                           "0x0023"
#define USB_TMP_3_inst                                                               0x0023
#define USB_TMP_3_test_reg_3_shift                                                   (3)
#define USB_TMP_3_test_reg_3_mask                                                    (0xFFFFFFF8)
#define USB_TMP_3_test_reg_3(data)                                                   (0xFFFFFFF8&((data)<<3))
#define USB_TMP_3_test_reg_3_src(data)                                               ((0xFFFFFFF8&(data))>>3)
#define USB_TMP_3_get_test_reg_3(data)                                               ((0xFFFFFFF8&(data))>>3)
#define USB_TMP_3_int_loop_en_shift                                                  (2)
#define USB_TMP_3_int_loop_en_mask                                                   (0x00000004)
#define USB_TMP_3_int_loop_en(data)                                                  (0x00000004&((data)<<2))
#define USB_TMP_3_int_loop_en_src(data)                                              ((0x00000004&(data))>>2)
#define USB_TMP_3_get_int_loop_en(data)                                              ((0x00000004&(data))>>2)
#define USB_TMP_3_int_comp_en_shift                                                  (1)
#define USB_TMP_3_int_comp_en_mask                                                   (0x00000002)
#define USB_TMP_3_int_comp_en(data)                                                  (0x00000002&((data)<<1))
#define USB_TMP_3_int_comp_en_src(data)                                              ((0x00000002&(data))>>1)
#define USB_TMP_3_get_int_comp_en(data)                                              ((0x00000002&(data))>>1)


#define HMAC_CTR0                                                                    0x1805A090
#define HMAC_CTR0_reg_addr                                                           "0xB805A090"
#define HMAC_CTR0_reg                                                                0xB805A090
#define set_HMAC_CTR0_reg(data)   (*((volatile unsigned int*) HMAC_CTR0_reg)=data)
#define get_HMAC_CTR0_reg   (*((volatile unsigned int*) HMAC_CTR0_reg))
#define HMAC_CTR0_inst_adr                                                           "0x0024"
#define HMAC_CTR0_inst                                                               0x0024
#define HMAC_CTR0_xhci_revision_shift                                                (31)
#define HMAC_CTR0_xhci_revision_mask                                                 (0x80000000)
#define HMAC_CTR0_xhci_revision(data)                                                (0x80000000&((data)<<31))
#define HMAC_CTR0_xhci_revision_src(data)                                            ((0x80000000&(data))>>31)
#define HMAC_CTR0_get_xhci_revision(data)                                            ((0x80000000&(data))>>31)
#define HMAC_CTR0_host_fladj_30mhz_shift                                             (25)
#define HMAC_CTR0_host_fladj_30mhz_mask                                              (0x7E000000)
#define HMAC_CTR0_host_fladj_30mhz(data)                                             (0x7E000000&((data)<<25))
#define HMAC_CTR0_host_fladj_30mhz_src(data)                                         ((0x7E000000&(data))>>25)
#define HMAC_CTR0_get_host_fladj_30mhz(data)                                         ((0x7E000000&(data))>>25)
#define HMAC_CTR0_host_ppc_present_shift                                             (24)
#define HMAC_CTR0_host_ppc_present_mask                                              (0x01000000)
#define HMAC_CTR0_host_ppc_present(data)                                             (0x01000000&((data)<<24))
#define HMAC_CTR0_host_ppc_present_src(data)                                         ((0x01000000&(data))>>24)
#define HMAC_CTR0_get_host_ppc_present(data)                                         ((0x01000000&(data))>>24)
#define HMAC_CTR0_host_msi_enable_shift                                              (23)
#define HMAC_CTR0_host_msi_enable_mask                                               (0x00800000)
#define HMAC_CTR0_host_msi_enable(data)                                              (0x00800000&((data)<<23))
#define HMAC_CTR0_host_msi_enable_src(data)                                          ((0x00800000&(data))>>23)
#define HMAC_CTR0_get_host_msi_enable(data)                                          ((0x00800000&(data))>>23)
#define HMAC_CTR0_host_pm_pw_state_req_shift                                         (21)
#define HMAC_CTR0_host_pm_pw_state_req_mask                                          (0x00600000)
#define HMAC_CTR0_host_pm_pw_state_req(data)                                         (0x00600000&((data)<<21))
#define HMAC_CTR0_host_pm_pw_state_req_src(data)                                     ((0x00600000&(data))>>21)
#define HMAC_CTR0_get_host_pm_pw_state_req(data)                                     ((0x00600000&(data))>>21)
#define HMAC_CTR0_hub_port_perm_attach_shift                                         (16)
#define HMAC_CTR0_hub_port_perm_attach_mask                                          (0x001F0000)
#define HMAC_CTR0_hub_port_perm_attach(data)                                         (0x001F0000&((data)<<16))
#define HMAC_CTR0_hub_port_perm_attach_src(data)                                     ((0x001F0000&(data))>>16)
#define HMAC_CTR0_get_hub_port_perm_attach(data)                                     ((0x001F0000&(data))>>16)
#define HMAC_CTR0_host_u2_port_disable_shift                                         (9)
#define HMAC_CTR0_host_u2_port_disable_mask                                          (0x00001E00)
#define HMAC_CTR0_host_u2_port_disable(data)                                         (0x00001E00&((data)<<9))
#define HMAC_CTR0_host_u2_port_disable_src(data)                                     ((0x00001E00&(data))>>9)
#define HMAC_CTR0_get_host_u2_port_disable(data)                                     ((0x00001E00&(data))>>9)
#define HMAC_CTR0_host_u3_port_disable_shift                                         (8)
#define HMAC_CTR0_host_u3_port_disable_mask                                          (0x00000100)
#define HMAC_CTR0_host_u3_port_disable(data)                                         (0x00000100&((data)<<8))
#define HMAC_CTR0_host_u3_port_disable_src(data)                                     ((0x00000100&(data))>>8)
#define HMAC_CTR0_get_host_u3_port_disable(data)                                     ((0x00000100&(data))>>8)
#define HMAC_CTR0_host_num_u2_port_shift                                             (4)
#define HMAC_CTR0_host_num_u2_port_mask                                              (0x000000F0)
#define HMAC_CTR0_host_num_u2_port(data)                                             (0x000000F0&((data)<<4))
#define HMAC_CTR0_host_num_u2_port_src(data)                                         ((0x000000F0&(data))>>4)
#define HMAC_CTR0_get_host_num_u2_port(data)                                         ((0x000000F0&(data))>>4)
#define HMAC_CTR0_host_num_u3_port_shift                                             (0)
#define HMAC_CTR0_host_num_u3_port_mask                                              (0x0000000F)
#define HMAC_CTR0_host_num_u3_port(data)                                             (0x0000000F&((data)<<0))
#define HMAC_CTR0_host_num_u3_port_src(data)                                         ((0x0000000F&(data))>>0)
#define HMAC_CTR0_get_host_num_u3_port(data)                                         ((0x0000000F&(data))>>0)


#define HMAC_CTR1                                                                    0x1805A094
#define HMAC_CTR1_reg_addr                                                           "0xB805A094"
#define HMAC_CTR1_reg                                                                0xB805A094
#define set_HMAC_CTR1_reg(data)   (*((volatile unsigned int*) HMAC_CTR1_reg)=data)
#define get_HMAC_CTR1_reg   (*((volatile unsigned int*) HMAC_CTR1_reg))
#define HMAC_CTR1_inst_adr                                                           "0x0025"
#define HMAC_CTR1_inst                                                               0x0025
#define HMAC_CTR1_host_utmiotg_vbusvalid_shift                                       (28)
#define HMAC_CTR1_host_utmiotg_vbusvalid_mask                                        (0xF0000000)
#define HMAC_CTR1_host_utmiotg_vbusvalid(data)                                       (0xF0000000&((data)<<28))
#define HMAC_CTR1_host_utmiotg_vbusvalid_src(data)                                   ((0xF0000000&(data))>>28)
#define HMAC_CTR1_get_host_utmiotg_vbusvalid(data)                                   ((0xF0000000&(data))>>28)
#define HMAC_CTR1_host_mac_vbus_inv_shift                                            (24)
#define HMAC_CTR1_host_mac_vbus_inv_mask                                             (0x0F000000)
#define HMAC_CTR1_host_mac_vbus_inv(data)                                            (0x0F000000&((data)<<24))
#define HMAC_CTR1_host_mac_vbus_inv_src(data)                                        ((0x0F000000&(data))>>24)
#define HMAC_CTR1_get_host_mac_vbus_inv(data)                                        ((0x0F000000&(data))>>24)
#define HMAC_CTR1_host_vbus_value_shift                                              (20)
#define HMAC_CTR1_host_vbus_value_mask                                               (0x00F00000)
#define HMAC_CTR1_host_vbus_value(data)                                              (0x00F00000&((data)<<20))
#define HMAC_CTR1_host_vbus_value_src(data)                                          ((0x00F00000&(data))>>20)
#define HMAC_CTR1_get_host_vbus_value(data)                                          ((0x00F00000&(data))>>20)
#define HMAC_CTR1_host_vbus_sel_shift                                                (16)
#define HMAC_CTR1_host_vbus_sel_mask                                                 (0x000F0000)
#define HMAC_CTR1_host_vbus_sel(data)                                                (0x000F0000&((data)<<16))
#define HMAC_CTR1_host_vbus_sel_src(data)                                            ((0x000F0000&(data))>>16)
#define HMAC_CTR1_get_host_vbus_sel(data)                                            ((0x000F0000&(data))>>16)
#define HMAC_CTR1_hub_port_over_cur_inv_shift                                        (8)
#define HMAC_CTR1_hub_port_over_cur_inv_mask                                         (0x00000F00)
#define HMAC_CTR1_hub_port_over_cur_inv(data)                                        (0x00000F00&((data)<<8))
#define HMAC_CTR1_hub_port_over_cur_inv_src(data)                                    ((0x00000F00&(data))>>8)
#define HMAC_CTR1_get_hub_port_over_cur_inv(data)                                    ((0x00000F00&(data))>>8)
#define HMAC_CTR1_host_over_cur_value_shift                                          (4)
#define HMAC_CTR1_host_over_cur_value_mask                                           (0x000000F0)
#define HMAC_CTR1_host_over_cur_value(data)                                          (0x000000F0&((data)<<4))
#define HMAC_CTR1_host_over_cur_value_src(data)                                      ((0x000000F0&(data))>>4)
#define HMAC_CTR1_get_host_over_cur_value(data)                                      ((0x000000F0&(data))>>4)
#define HMAC_CTR1_host_over_cur_sel_shift                                            (0)
#define HMAC_CTR1_host_over_cur_sel_mask                                             (0x0000000F)
#define HMAC_CTR1_host_over_cur_sel(data)                                            (0x0000000F&((data)<<0))
#define HMAC_CTR1_host_over_cur_sel_src(data)                                        ((0x0000000F&(data))>>0)
#define HMAC_CTR1_get_host_over_cur_sel(data)                                        ((0x0000000F&(data))>>0)


#define MAC3_HST_ST                                                                  0x1805A098
#define MAC3_HST_ST_reg_addr                                                         "0xB805A098"
#define MAC3_HST_ST_reg                                                              0xB805A098
#define set_MAC3_HST_ST_reg(data)   (*((volatile unsigned int*) MAC3_HST_ST_reg)=data)
#define get_MAC3_HST_ST_reg   (*((volatile unsigned int*) MAC3_HST_ST_reg))
#define MAC3_HST_ST_inst_adr                                                         "0x0026"
#define MAC3_HST_ST_inst                                                             0x0026
#define MAC3_HST_ST_host_current_belt_shift                                          (7)
#define MAC3_HST_ST_host_current_belt_mask                                           (0x0007FF80)
#define MAC3_HST_ST_host_current_belt(data)                                          (0x0007FF80&((data)<<7))
#define MAC3_HST_ST_host_current_belt_src(data)                                      ((0x0007FF80&(data))>>7)
#define MAC3_HST_ST_get_host_current_belt(data)                                      ((0x0007FF80&(data))>>7)
#define MAC3_HST_ST_host_current_power_state_shift                                   (5)
#define MAC3_HST_ST_host_current_power_state_mask                                    (0x00000060)
#define MAC3_HST_ST_host_current_power_state(data)                                   (0x00000060&((data)<<5))
#define MAC3_HST_ST_host_current_power_state_src(data)                               ((0x00000060&(data))>>5)
#define MAC3_HST_ST_get_host_current_power_state(data)                               ((0x00000060&(data))>>5)
#define MAC3_HST_ST_host_hub_vbus_ctrl_shift                                         (0)
#define MAC3_HST_ST_host_hub_vbus_ctrl_mask                                          (0x0000001F)
#define MAC3_HST_ST_host_hub_vbus_ctrl(data)                                         (0x0000001F&((data)<<0))
#define MAC3_HST_ST_host_hub_vbus_ctrl_src(data)                                     ((0x0000001F&(data))>>0)
#define MAC3_HST_ST_get_host_hub_vbus_ctrl(data)                                     ((0x0000001F&(data))>>0)


#define USB2_PHY0                                                                    0x1805A09c
#define USB2_PHY0_reg_addr                                                           "0xB805A09C"
#define USB2_PHY0_reg                                                                0xB805A09C
#define set_USB2_PHY0_reg(data)   (*((volatile unsigned int*) USB2_PHY0_reg)=data)
#define get_USB2_PHY0_reg   (*((volatile unsigned int*) USB2_PHY0_reg))
#define USB2_PHY0_inst_adr                                                           "0x0027"
#define USB2_PHY0_inst                                                               0x0027
#define USB2_PHY0_p0_DmPulldown_shift                                                (10)
#define USB2_PHY0_p0_DmPulldown_mask                                                 (0x00000400)
#define USB2_PHY0_p0_DmPulldown(data)                                                (0x00000400&((data)<<10))
#define USB2_PHY0_p0_DmPulldown_src(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY0_get_p0_DmPulldown(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY0_p0_DpPulldown_shift                                                (9)
#define USB2_PHY0_p0_DpPulldown_mask                                                 (0x00000200)
#define USB2_PHY0_p0_DpPulldown(data)                                                (0x00000200&((data)<<9))
#define USB2_PHY0_p0_DpPulldown_src(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY0_get_p0_DpPulldown(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY0_p0_IDPULLUP_shift                                                  (8)
#define USB2_PHY0_p0_IDPULLUP_mask                                                   (0x00000100)
#define USB2_PHY0_p0_IDPULLUP(data)                                                  (0x00000100&((data)<<8))
#define USB2_PHY0_p0_IDPULLUP_src(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY0_get_p0_IDPULLUP(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY0_p0_DmPulldown_sel_shift                                            (2)
#define USB2_PHY0_p0_DmPulldown_sel_mask                                             (0x00000004)
#define USB2_PHY0_p0_DmPulldown_sel(data)                                            (0x00000004&((data)<<2))
#define USB2_PHY0_p0_DmPulldown_sel_src(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY0_get_p0_DmPulldown_sel(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY0_p0_DpPulldown_sel_shift                                            (1)
#define USB2_PHY0_p0_DpPulldown_sel_mask                                             (0x00000002)
#define USB2_PHY0_p0_DpPulldown_sel(data)                                            (0x00000002&((data)<<1))
#define USB2_PHY0_p0_DpPulldown_sel_src(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY0_get_p0_DpPulldown_sel(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY0_p0_IDPULLUP_sel_shift                                              (0)
#define USB2_PHY0_p0_IDPULLUP_sel_mask                                               (0x00000001)
#define USB2_PHY0_p0_IDPULLUP_sel(data)                                              (0x00000001&((data)<<0))
#define USB2_PHY0_p0_IDPULLUP_sel_src(data)                                          ((0x00000001&(data))>>0)
#define USB2_PHY0_get_p0_IDPULLUP_sel(data)                                          ((0x00000001&(data))>>0)


#define USB2_PHY1                                                                    0x1805A0a0
#define USB2_PHY1_reg_addr                                                           "0xB805A0A0"
#define USB2_PHY1_reg                                                                0xB805A0A0
#define set_USB2_PHY1_reg(data)   (*((volatile unsigned int*) USB2_PHY1_reg)=data)
#define get_USB2_PHY1_reg   (*((volatile unsigned int*) USB2_PHY1_reg))
#define USB2_PHY1_inst_adr                                                           "0x0028"
#define USB2_PHY1_inst                                                               0x0028
#define USB2_PHY1_p1_DmPulldown_shift                                                (10)
#define USB2_PHY1_p1_DmPulldown_mask                                                 (0x00000400)
#define USB2_PHY1_p1_DmPulldown(data)                                                (0x00000400&((data)<<10))
#define USB2_PHY1_p1_DmPulldown_src(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY1_get_p1_DmPulldown(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY1_p1_DpPulldown_shift                                                (9)
#define USB2_PHY1_p1_DpPulldown_mask                                                 (0x00000200)
#define USB2_PHY1_p1_DpPulldown(data)                                                (0x00000200&((data)<<9))
#define USB2_PHY1_p1_DpPulldown_src(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY1_get_p1_DpPulldown(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY1_p1_IDPULLUP_shift                                                  (8)
#define USB2_PHY1_p1_IDPULLUP_mask                                                   (0x00000100)
#define USB2_PHY1_p1_IDPULLUP(data)                                                  (0x00000100&((data)<<8))
#define USB2_PHY1_p1_IDPULLUP_src(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY1_get_p1_IDPULLUP(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY1_p1_DmPulldown_sel_shift                                            (2)
#define USB2_PHY1_p1_DmPulldown_sel_mask                                             (0x00000004)
#define USB2_PHY1_p1_DmPulldown_sel(data)                                            (0x00000004&((data)<<2))
#define USB2_PHY1_p1_DmPulldown_sel_src(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY1_get_p1_DmPulldown_sel(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY1_p1_DpPulldown_sel_shift                                            (1)
#define USB2_PHY1_p1_DpPulldown_sel_mask                                             (0x00000002)
#define USB2_PHY1_p1_DpPulldown_sel(data)                                            (0x00000002&((data)<<1))
#define USB2_PHY1_p1_DpPulldown_sel_src(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY1_get_p1_DpPulldown_sel(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY1_p1_IDPULLUP_sel_shift                                              (0)
#define USB2_PHY1_p1_IDPULLUP_sel_mask                                               (0x00000001)
#define USB2_PHY1_p1_IDPULLUP_sel(data)                                              (0x00000001&((data)<<0))
#define USB2_PHY1_p1_IDPULLUP_sel_src(data)                                          ((0x00000001&(data))>>0)
#define USB2_PHY1_get_p1_IDPULLUP_sel(data)                                          ((0x00000001&(data))>>0)


#define USB2_PHY2                                                                    0x1805A0a4
#define USB2_PHY2_reg_addr                                                           "0xB805A0A4"
#define USB2_PHY2_reg                                                                0xB805A0A4
#define set_USB2_PHY2_reg(data)   (*((volatile unsigned int*) USB2_PHY2_reg)=data)
#define get_USB2_PHY2_reg   (*((volatile unsigned int*) USB2_PHY2_reg))
#define USB2_PHY2_inst_adr                                                           "0x0029"
#define USB2_PHY2_inst                                                               0x0029
#define USB2_PHY2_p2_DmPulldown_shift                                                (10)
#define USB2_PHY2_p2_DmPulldown_mask                                                 (0x00000400)
#define USB2_PHY2_p2_DmPulldown(data)                                                (0x00000400&((data)<<10))
#define USB2_PHY2_p2_DmPulldown_src(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY2_get_p2_DmPulldown(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY2_p2_DpPulldown_shift                                                (9)
#define USB2_PHY2_p2_DpPulldown_mask                                                 (0x00000200)
#define USB2_PHY2_p2_DpPulldown(data)                                                (0x00000200&((data)<<9))
#define USB2_PHY2_p2_DpPulldown_src(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY2_get_p2_DpPulldown(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY2_p2_IDPULLUP_shift                                                  (8)
#define USB2_PHY2_p2_IDPULLUP_mask                                                   (0x00000100)
#define USB2_PHY2_p2_IDPULLUP(data)                                                  (0x00000100&((data)<<8))
#define USB2_PHY2_p2_IDPULLUP_src(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY2_get_p2_IDPULLUP(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY2_p2_DmPulldown_sel_shift                                            (2)
#define USB2_PHY2_p2_DmPulldown_sel_mask                                             (0x00000004)
#define USB2_PHY2_p2_DmPulldown_sel(data)                                            (0x00000004&((data)<<2))
#define USB2_PHY2_p2_DmPulldown_sel_src(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY2_get_p2_DmPulldown_sel(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY2_p2_DpPulldown_sel_shift                                            (1)
#define USB2_PHY2_p2_DpPulldown_sel_mask                                             (0x00000002)
#define USB2_PHY2_p2_DpPulldown_sel(data)                                            (0x00000002&((data)<<1))
#define USB2_PHY2_p2_DpPulldown_sel_src(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY2_get_p2_DpPulldown_sel(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY2_p2_IDPULLUP_sel_shift                                              (0)
#define USB2_PHY2_p2_IDPULLUP_sel_mask                                               (0x00000001)
#define USB2_PHY2_p2_IDPULLUP_sel(data)                                              (0x00000001&((data)<<0))
#define USB2_PHY2_p2_IDPULLUP_sel_src(data)                                          ((0x00000001&(data))>>0)
#define USB2_PHY2_get_p2_IDPULLUP_sel(data)                                          ((0x00000001&(data))>>0)


#define USB2_PHY3                                                                    0x1805A0a8
#define USB2_PHY3_reg_addr                                                           "0xB805A0A8"
#define USB2_PHY3_reg                                                                0xB805A0A8
#define set_USB2_PHY3_reg(data)   (*((volatile unsigned int*) USB2_PHY3_reg)=data)
#define get_USB2_PHY3_reg   (*((volatile unsigned int*) USB2_PHY3_reg))
#define USB2_PHY3_inst_adr                                                           "0x002A"
#define USB2_PHY3_inst                                                               0x002A
#define USB2_PHY3_p3_DmPulldown_shift                                                (10)
#define USB2_PHY3_p3_DmPulldown_mask                                                 (0x00000400)
#define USB2_PHY3_p3_DmPulldown(data)                                                (0x00000400&((data)<<10))
#define USB2_PHY3_p3_DmPulldown_src(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY3_get_p3_DmPulldown(data)                                            ((0x00000400&(data))>>10)
#define USB2_PHY3_p3_DpPulldown_shift                                                (9)
#define USB2_PHY3_p3_DpPulldown_mask                                                 (0x00000200)
#define USB2_PHY3_p3_DpPulldown(data)                                                (0x00000200&((data)<<9))
#define USB2_PHY3_p3_DpPulldown_src(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY3_get_p3_DpPulldown(data)                                            ((0x00000200&(data))>>9)
#define USB2_PHY3_p3_IDPULLUP_shift                                                  (8)
#define USB2_PHY3_p3_IDPULLUP_mask                                                   (0x00000100)
#define USB2_PHY3_p3_IDPULLUP(data)                                                  (0x00000100&((data)<<8))
#define USB2_PHY3_p3_IDPULLUP_src(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY3_get_p3_IDPULLUP(data)                                              ((0x00000100&(data))>>8)
#define USB2_PHY3_p3_DmPulldown_sel_shift                                            (2)
#define USB2_PHY3_p3_DmPulldown_sel_mask                                             (0x00000004)
#define USB2_PHY3_p3_DmPulldown_sel(data)                                            (0x00000004&((data)<<2))
#define USB2_PHY3_p3_DmPulldown_sel_src(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY3_get_p3_DmPulldown_sel(data)                                        ((0x00000004&(data))>>2)
#define USB2_PHY3_p3_DpPulldown_sel_shift                                            (1)
#define USB2_PHY3_p3_DpPulldown_sel_mask                                             (0x00000002)
#define USB2_PHY3_p3_DpPulldown_sel(data)                                            (0x00000002&((data)<<1))
#define USB2_PHY3_p3_DpPulldown_sel_src(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY3_get_p3_DpPulldown_sel(data)                                        ((0x00000002&(data))>>1)
#define USB2_PHY3_p3_IDPULLUP_sel_shift                                              (0)
#define USB2_PHY3_p3_IDPULLUP_sel_mask                                               (0x00000001)
#define USB2_PHY3_p3_IDPULLUP_sel(data)                                              (0x00000001&((data)<<0))
#define USB2_PHY3_p3_IDPULLUP_sel_src(data)                                          ((0x00000001&(data))>>0)
#define USB2_PHY3_get_p3_IDPULLUP_sel(data)                                          ((0x00000001&(data))>>0)


#define RAM_CTR                                                                      0x1805A0ac
#define RAM_CTR_reg_addr                                                             "0xB805A0AC"
#define RAM_CTR_reg                                                                  0xB805A0AC
#define set_RAM_CTR_reg(data)   (*((volatile unsigned int*) RAM_CTR_reg)=data)
#define get_RAM_CTR_reg   (*((volatile unsigned int*) RAM_CTR_reg))
#define RAM_CTR_inst_adr                                                             "0x002B"
#define RAM_CTR_inst                                                                 0x002B
#define RAM_CTR_done_st_shift                                                        (16)
#define RAM_CTR_done_st_mask                                                         (0x00010000)
#define RAM_CTR_done_st(data)                                                        (0x00010000&((data)<<16))
#define RAM_CTR_done_st_src(data)                                                    ((0x00010000&(data))>>16)
#define RAM_CTR_get_done_st(data)                                                    ((0x00010000&(data))>>16)
#define RAM_CTR_go_ct_shift                                                          (0)
#define RAM_CTR_go_ct_mask                                                           (0x00000001)
#define RAM_CTR_go_ct(data)                                                          (0x00000001&((data)<<0))
#define RAM_CTR_go_ct_src(data)                                                      ((0x00000001&(data))>>0)
#define RAM_CTR_get_go_ct(data)                                                      ((0x00000001&(data))>>0)


#define RAM_ADDR                                                                     0x1805A0b0
#define RAM_ADDR_reg_addr                                                            "0xB805A0B0"
#define RAM_ADDR_reg                                                                 0xB805A0B0
#define set_RAM_ADDR_reg(data)   (*((volatile unsigned int*) RAM_ADDR_reg)=data)
#define get_RAM_ADDR_reg   (*((volatile unsigned int*) RAM_ADDR_reg))
#define RAM_ADDR_inst_adr                                                            "0x002C"
#define RAM_ADDR_inst                                                                0x002C
#define RAM_ADDR_sram_addr_shift                                                     (0)
#define RAM_ADDR_sram_addr_mask                                                      (0xFFFFFFFF)
#define RAM_ADDR_sram_addr(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RAM_ADDR_sram_addr_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RAM_ADDR_get_sram_addr(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define RAM_WDATA                                                                    0x1805A0b4
#define RAM_WDATA_reg_addr                                                           "0xB805A0B4"
#define RAM_WDATA_reg                                                                0xB805A0B4
#define set_RAM_WDATA_reg(data)   (*((volatile unsigned int*) RAM_WDATA_reg)=data)
#define get_RAM_WDATA_reg   (*((volatile unsigned int*) RAM_WDATA_reg))
#define RAM_WDATA_inst_adr                                                           "0x002D"
#define RAM_WDATA_inst                                                               0x002D
#define RAM_WDATA_ram_wdata_shift                                                    (0)
#define RAM_WDATA_ram_wdata_mask                                                     (0xFFFFFFFF)
#define RAM_WDATA_ram_wdata(data)                                                    (0xFFFFFFFF&((data)<<0))
#define RAM_WDATA_ram_wdata_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define RAM_WDATA_get_ram_wdata(data)                                                ((0xFFFFFFFF&(data))>>0)


#define RAM_RDATA                                                                    0x1805A0b8
#define RAM_RDATA_reg_addr                                                           "0xB805A0B8"
#define RAM_RDATA_reg                                                                0xB805A0B8
#define set_RAM_RDATA_reg(data)   (*((volatile unsigned int*) RAM_RDATA_reg)=data)
#define get_RAM_RDATA_reg   (*((volatile unsigned int*) RAM_RDATA_reg))
#define RAM_RDATA_inst_adr                                                           "0x002E"
#define RAM_RDATA_inst                                                               0x002E
#define RAM_RDATA_ram_rdata_shift                                                    (0)
#define RAM_RDATA_ram_rdata_mask                                                     (0xFFFFFFFF)
#define RAM_RDATA_ram_rdata(data)                                                    (0xFFFFFFFF&((data)<<0))
#define RAM_RDATA_ram_rdata_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define RAM_RDATA_get_ram_rdata(data)                                                ((0xFFFFFFFF&(data))>>0)


#define PHY0_ST                                                                      0x1805A0bc
#define PHY0_ST_reg_addr                                                             "0xB805A0BC"
#define PHY0_ST_reg                                                                  0xB805A0BC
#define set_PHY0_ST_reg(data)   (*((volatile unsigned int*) PHY0_ST_reg)=data)
#define get_PHY0_ST_reg   (*((volatile unsigned int*) PHY0_ST_reg))
#define PHY0_ST_inst_adr                                                             "0x002F"
#define PHY0_ST_inst                                                                 0x002F
#define PHY0_ST_p0_count_num_shift                                                   (0)
#define PHY0_ST_p0_count_num_mask                                                    (0x0007FFFF)
#define PHY0_ST_p0_count_num(data)                                                   (0x0007FFFF&((data)<<0))
#define PHY0_ST_p0_count_num_src(data)                                               ((0x0007FFFF&(data))>>0)
#define PHY0_ST_get_p0_count_num(data)                                               ((0x0007FFFF&(data))>>0)


#define USB3_OVR_CT                                                                  0x1805A0c0
#define USB3_OVR_CT_reg_addr                                                         "0xB805A0C0"
#define USB3_OVR_CT_reg                                                              0xB805A0C0
#define set_USB3_OVR_CT_reg(data)   (*((volatile unsigned int*) USB3_OVR_CT_reg)=data)
#define get_USB3_OVR_CT_reg   (*((volatile unsigned int*) USB3_OVR_CT_reg))
#define USB3_OVR_CT_inst_adr                                                         "0x0030"
#define USB3_OVR_CT_inst                                                             0x0030
#define USB3_OVR_CT_phy3_lperiod_shift                                               (7)
#define USB3_OVR_CT_phy3_lperiod_mask                                                (0x00000380)
#define USB3_OVR_CT_phy3_lperiod(data)                                               (0x00000380&((data)<<7))
#define USB3_OVR_CT_phy3_lperiod_src(data)                                           ((0x00000380&(data))>>7)
#define USB3_OVR_CT_get_phy3_lperiod(data)                                           ((0x00000380&(data))>>7)
#define USB3_OVR_CT_phy3_hperiod_shift                                               (4)
#define USB3_OVR_CT_phy3_hperiod_mask                                                (0x00000070)
#define USB3_OVR_CT_phy3_hperiod(data)                                               (0x00000070&((data)<<4))
#define USB3_OVR_CT_phy3_hperiod_src(data)                                           ((0x00000070&(data))>>4)
#define USB3_OVR_CT_get_phy3_hperiod(data)                                           ((0x00000070&(data))>>4)
#define USB3_OVR_CT_phy3_last_shift                                                  (2)
#define USB3_OVR_CT_phy3_last_mask                                                   (0x0000000C)
#define USB3_OVR_CT_phy3_last(data)                                                  (0x0000000C&((data)<<2))
#define USB3_OVR_CT_phy3_last_src(data)                                              ((0x0000000C&(data))>>2)
#define USB3_OVR_CT_get_phy3_last(data)                                              ((0x0000000C&(data))>>2)
#define USB3_OVR_CT_host_ovr_current_value_shift                                     (1)
#define USB3_OVR_CT_host_ovr_current_value_mask                                      (0x00000002)
#define USB3_OVR_CT_host_ovr_current_value(data)                                     (0x00000002&((data)<<1))
#define USB3_OVR_CT_host_ovr_current_value_src(data)                                 ((0x00000002&(data))>>1)
#define USB3_OVR_CT_get_host_ovr_current_value(data)                                 ((0x00000002&(data))>>1)
#define USB3_OVR_CT_host_ovr_current_sel_shift                                       (0)
#define USB3_OVR_CT_host_ovr_current_sel_mask                                        (0x00000001)
#define USB3_OVR_CT_host_ovr_current_sel(data)                                       (0x00000001&((data)<<0))
#define USB3_OVR_CT_host_ovr_current_sel_src(data)                                   ((0x00000001&(data))>>0)
#define USB3_OVR_CT_get_host_ovr_current_sel(data)                                   ((0x00000001&(data))>>0)


#define ANA_PHY0                                                                     0x1805A0c4
#define ANA_PHY0_reg_addr                                                            "0xB805A0C4"
#define ANA_PHY0_reg                                                                 0xB805A0C4
#define set_ANA_PHY0_reg(data)   (*((volatile unsigned int*) ANA_PHY0_reg)=data)
#define get_ANA_PHY0_reg   (*((volatile unsigned int*) ANA_PHY0_reg))
#define ANA_PHY0_inst_adr                                                            "0x0031"
#define ANA_PHY0_inst                                                                0x0031
#define ANA_PHY0_usb3_mbias_en_p0_shift                                              (3)
#define ANA_PHY0_usb3_mbias_en_p0_mask                                               (0x00000008)
#define ANA_PHY0_usb3_mbias_en_p0(data)                                              (0x00000008&((data)<<3))
#define ANA_PHY0_usb3_mbias_en_p0_src(data)                                          ((0x00000008&(data))>>3)
#define ANA_PHY0_get_usb3_mbias_en_p0(data)                                          ((0x00000008&(data))>>3)
#define ANA_PHY0_usb3_bg_en_p0_shift                                                 (2)
#define ANA_PHY0_usb3_bg_en_p0_mask                                                  (0x00000004)
#define ANA_PHY0_usb3_bg_en_p0(data)                                                 (0x00000004&((data)<<2))
#define ANA_PHY0_usb3_bg_en_p0_src(data)                                             ((0x00000004&(data))>>2)
#define ANA_PHY0_get_usb3_bg_en_p0(data)                                             ((0x00000004&(data))>>2)
#define ANA_PHY0_usb3_pow_gating_p0_shift                                            (1)
#define ANA_PHY0_usb3_pow_gating_p0_mask                                             (0x00000002)
#define ANA_PHY0_usb3_pow_gating_p0(data)                                            (0x00000002&((data)<<1))
#define ANA_PHY0_usb3_pow_gating_p0_src(data)                                        ((0x00000002&(data))>>1)
#define ANA_PHY0_get_usb3_pow_gating_p0(data)                                        ((0x00000002&(data))>>1)
#define ANA_PHY0_usb3_isolate_p0_shift                                               (0)
#define ANA_PHY0_usb3_isolate_p0_mask                                                (0x00000001)
#define ANA_PHY0_usb3_isolate_p0(data)                                               (0x00000001&((data)<<0))
#define ANA_PHY0_usb3_isolate_p0_src(data)                                           ((0x00000001&(data))>>0)
#define ANA_PHY0_get_usb3_isolate_p0(data)                                           ((0x00000001&(data))>>0)


#define ANA_PHY1                                                                     0x1805A0c8
#define ANA_PHY1_reg_addr                                                            "0xB805A0C8"
#define ANA_PHY1_reg                                                                 0xB805A0C8
#define set_ANA_PHY1_reg(data)   (*((volatile unsigned int*) ANA_PHY1_reg)=data)
#define get_ANA_PHY1_reg   (*((volatile unsigned int*) ANA_PHY1_reg))
#define ANA_PHY1_inst_adr                                                            "0x0032"
#define ANA_PHY1_inst                                                                0x0032
#define ANA_PHY1_usb2_pow_gating_p3_shift                                            (3)
#define ANA_PHY1_usb2_pow_gating_p3_mask                                             (0x00000008)
#define ANA_PHY1_usb2_pow_gating_p3(data)                                            (0x00000008&((data)<<3))
#define ANA_PHY1_usb2_pow_gating_p3_src(data)                                        ((0x00000008&(data))>>3)
#define ANA_PHY1_get_usb2_pow_gating_p3(data)                                        ((0x00000008&(data))>>3)
#define ANA_PHY1_usb2_pow_gating_p2_shift                                            (2)
#define ANA_PHY1_usb2_pow_gating_p2_mask                                             (0x00000004)
#define ANA_PHY1_usb2_pow_gating_p2(data)                                            (0x00000004&((data)<<2))
#define ANA_PHY1_usb2_pow_gating_p2_src(data)                                        ((0x00000004&(data))>>2)
#define ANA_PHY1_get_usb2_pow_gating_p2(data)                                        ((0x00000004&(data))>>2)
#define ANA_PHY1_usb2_pow_gating_p1_shift                                            (1)
#define ANA_PHY1_usb2_pow_gating_p1_mask                                             (0x00000002)
#define ANA_PHY1_usb2_pow_gating_p1(data)                                            (0x00000002&((data)<<1))
#define ANA_PHY1_usb2_pow_gating_p1_src(data)                                        ((0x00000002&(data))>>1)
#define ANA_PHY1_get_usb2_pow_gating_p1(data)                                        ((0x00000002&(data))>>1)
#define ANA_PHY1_usb2_pow_gating_p0_shift                                            (0)
#define ANA_PHY1_usb2_pow_gating_p0_mask                                             (0x00000001)
#define ANA_PHY1_usb2_pow_gating_p0(data)                                            (0x00000001&((data)<<0))
#define ANA_PHY1_usb2_pow_gating_p0_src(data)                                        ((0x00000001&(data))>>0)
#define ANA_PHY1_get_usb2_pow_gating_p0(data)                                        ((0x00000001&(data))>>0)


#define GBL_USB_CT                                                                   0x1805A0cc
#define GBL_USB_CT_reg_addr                                                          "0xB805A0CC"
#define GBL_USB_CT_reg                                                               0xB805A0CC
#define set_GBL_USB_CT_reg(data)   (*((volatile unsigned int*) GBL_USB_CT_reg)=data)
#define get_GBL_USB_CT_reg   (*((volatile unsigned int*) GBL_USB_CT_reg))
#define GBL_USB_CT_inst_adr                                                          "0x0033"
#define GBL_USB_CT_inst                                                              0x0033
#define GBL_USB_CT_usb_mac_ctrl_shift                                                (0)
#define GBL_USB_CT_usb_mac_ctrl_mask                                                 (0xFFFFFFFF)
#define GBL_USB_CT_usb_mac_ctrl(data)                                                (0xFFFFFFFF&((data)<<0))
#define GBL_USB_CT_usb_mac_ctrl_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define GBL_USB_CT_get_usb_mac_ctrl(data)                                            ((0xFFFFFFFF&(data))>>0)


#define BIST0                                                                        0x1805A100
#define BIST0_reg_addr                                                               "0xB805A100"
#define BIST0_reg                                                                    0xB805A100
#define set_BIST0_reg(data)   (*((volatile unsigned int*) BIST0_reg)=data)
#define get_BIST0_reg   (*((volatile unsigned int*) BIST0_reg))
#define BIST0_inst_adr                                                               "0x0040"
#define BIST0_inst                                                                   0x0040
#define BIST0_usb_bist_mode_host_ram_1_shift                                         (2)
#define BIST0_usb_bist_mode_host_ram_1_mask                                          (0x00000004)
#define BIST0_usb_bist_mode_host_ram_1(data)                                         (0x00000004&((data)<<2))
#define BIST0_usb_bist_mode_host_ram_1_src(data)                                     ((0x00000004&(data))>>2)
#define BIST0_get_usb_bist_mode_host_ram_1(data)                                     ((0x00000004&(data))>>2)
#define BIST0_usb_bist_mode_host_ram_2_shift                                         (1)
#define BIST0_usb_bist_mode_host_ram_2_mask                                          (0x00000002)
#define BIST0_usb_bist_mode_host_ram_2(data)                                         (0x00000002&((data)<<1))
#define BIST0_usb_bist_mode_host_ram_2_src(data)                                     ((0x00000002&(data))>>1)
#define BIST0_get_usb_bist_mode_host_ram_2(data)                                     ((0x00000002&(data))>>1)
#define BIST0_usb_bist_mode_wrap_shift                                               (0)
#define BIST0_usb_bist_mode_wrap_mask                                                (0x00000001)
#define BIST0_usb_bist_mode_wrap(data)                                               (0x00000001&((data)<<0))
#define BIST0_usb_bist_mode_wrap_src(data)                                           ((0x00000001&(data))>>0)
#define BIST0_get_usb_bist_mode_wrap(data)                                           ((0x00000001&(data))>>0)


#define BIST1                                                                        0x1805A104
#define BIST1_reg_addr                                                               "0xB805A104"
#define BIST1_reg                                                                    0xB805A104
#define set_BIST1_reg(data)   (*((volatile unsigned int*) BIST1_reg)=data)
#define get_BIST1_reg   (*((volatile unsigned int*) BIST1_reg))
#define BIST1_inst_adr                                                               "0x0041"
#define BIST1_inst                                                                   0x0041
#define BIST1_usb_bist_done_host_ram_1_shift                                         (2)
#define BIST1_usb_bist_done_host_ram_1_mask                                          (0x00000004)
#define BIST1_usb_bist_done_host_ram_1(data)                                         (0x00000004&((data)<<2))
#define BIST1_usb_bist_done_host_ram_1_src(data)                                     ((0x00000004&(data))>>2)
#define BIST1_get_usb_bist_done_host_ram_1(data)                                     ((0x00000004&(data))>>2)
#define BIST1_usb_bist_done_host_ram_2_shift                                         (1)
#define BIST1_usb_bist_done_host_ram_2_mask                                          (0x00000002)
#define BIST1_usb_bist_done_host_ram_2(data)                                         (0x00000002&((data)<<1))
#define BIST1_usb_bist_done_host_ram_2_src(data)                                     ((0x00000002&(data))>>1)
#define BIST1_get_usb_bist_done_host_ram_2(data)                                     ((0x00000002&(data))>>1)
#define BIST1_usb_bist_done_wrap_shift                                               (0)
#define BIST1_usb_bist_done_wrap_mask                                                (0x00000001)
#define BIST1_usb_bist_done_wrap(data)                                               (0x00000001&((data)<<0))
#define BIST1_usb_bist_done_wrap_src(data)                                           ((0x00000001&(data))>>0)
#define BIST1_get_usb_bist_done_wrap(data)                                           ((0x00000001&(data))>>0)


#define BIST2                                                                        0x1805A108
#define BIST2_reg_addr                                                               "0xB805A108"
#define BIST2_reg                                                                    0xB805A108
#define set_BIST2_reg(data)   (*((volatile unsigned int*) BIST2_reg)=data)
#define get_BIST2_reg   (*((volatile unsigned int*) BIST2_reg))
#define BIST2_inst_adr                                                               "0x0042"
#define BIST2_inst                                                                   0x0042
#define BIST2_usb_bist_fail_group_host_ram_1_shift                                   (2)
#define BIST2_usb_bist_fail_group_host_ram_1_mask                                    (0x00000004)
#define BIST2_usb_bist_fail_group_host_ram_1(data)                                   (0x00000004&((data)<<2))
#define BIST2_usb_bist_fail_group_host_ram_1_src(data)                               ((0x00000004&(data))>>2)
#define BIST2_get_usb_bist_fail_group_host_ram_1(data)                               ((0x00000004&(data))>>2)
#define BIST2_usb_bist_fail_group_host_ram_2_shift                                   (1)
#define BIST2_usb_bist_fail_group_host_ram_2_mask                                    (0x00000002)
#define BIST2_usb_bist_fail_group_host_ram_2(data)                                   (0x00000002&((data)<<1))
#define BIST2_usb_bist_fail_group_host_ram_2_src(data)                               ((0x00000002&(data))>>1)
#define BIST2_get_usb_bist_fail_group_host_ram_2(data)                               ((0x00000002&(data))>>1)
#define BIST2_usb_bist_fail_group_wrap_shift                                         (0)
#define BIST2_usb_bist_fail_group_wrap_mask                                          (0x00000001)
#define BIST2_usb_bist_fail_group_wrap(data)                                         (0x00000001&((data)<<0))
#define BIST2_usb_bist_fail_group_wrap_src(data)                                     ((0x00000001&(data))>>0)
#define BIST2_get_usb_bist_fail_group_wrap(data)                                     ((0x00000001&(data))>>0)


#define BIST3                                                                        0x1805A10c
#define BIST3_reg_addr                                                               "0xB805A10C"
#define BIST3_reg                                                                    0xB805A10C
#define set_BIST3_reg(data)   (*((volatile unsigned int*) BIST3_reg)=data)
#define get_BIST3_reg   (*((volatile unsigned int*) BIST3_reg))
#define BIST3_inst_adr                                                               "0x0043"
#define BIST3_inst                                                                   0x0043
#define BIST3_usb_bist_host_ram_1_fail_3_shift                                       (3)
#define BIST3_usb_bist_host_ram_1_fail_3_mask                                        (0x00000008)
#define BIST3_usb_bist_host_ram_1_fail_3(data)                                       (0x00000008&((data)<<3))
#define BIST3_usb_bist_host_ram_1_fail_3_src(data)                                   ((0x00000008&(data))>>3)
#define BIST3_get_usb_bist_host_ram_1_fail_3(data)                                   ((0x00000008&(data))>>3)
#define BIST3_usb_bist_host_ram_1_fail_2_shift                                       (2)
#define BIST3_usb_bist_host_ram_1_fail_2_mask                                        (0x00000004)
#define BIST3_usb_bist_host_ram_1_fail_2(data)                                       (0x00000004&((data)<<2))
#define BIST3_usb_bist_host_ram_1_fail_2_src(data)                                   ((0x00000004&(data))>>2)
#define BIST3_get_usb_bist_host_ram_1_fail_2(data)                                   ((0x00000004&(data))>>2)
#define BIST3_usb_bist_host_ram_1_fail_1_shift                                       (1)
#define BIST3_usb_bist_host_ram_1_fail_1_mask                                        (0x00000002)
#define BIST3_usb_bist_host_ram_1_fail_1(data)                                       (0x00000002&((data)<<1))
#define BIST3_usb_bist_host_ram_1_fail_1_src(data)                                   ((0x00000002&(data))>>1)
#define BIST3_get_usb_bist_host_ram_1_fail_1(data)                                   ((0x00000002&(data))>>1)
#define BIST3_usb_bist_host_ram_1_fail_0_shift                                       (0)
#define BIST3_usb_bist_host_ram_1_fail_0_mask                                        (0x00000001)
#define BIST3_usb_bist_host_ram_1_fail_0(data)                                       (0x00000001&((data)<<0))
#define BIST3_usb_bist_host_ram_1_fail_0_src(data)                                   ((0x00000001&(data))>>0)
#define BIST3_get_usb_bist_host_ram_1_fail_0(data)                                   ((0x00000001&(data))>>0)


#define BIST4                                                                        0x1805A110
#define BIST4_reg_addr                                                               "0xB805A110"
#define BIST4_reg                                                                    0xB805A110
#define set_BIST4_reg(data)   (*((volatile unsigned int*) BIST4_reg)=data)
#define get_BIST4_reg   (*((volatile unsigned int*) BIST4_reg))
#define BIST4_inst_adr                                                               "0x0044"
#define BIST4_inst                                                                   0x0044
#define BIST4_usb_bist_host_ram_2_fail_3_shift                                       (3)
#define BIST4_usb_bist_host_ram_2_fail_3_mask                                        (0x00000008)
#define BIST4_usb_bist_host_ram_2_fail_3(data)                                       (0x00000008&((data)<<3))
#define BIST4_usb_bist_host_ram_2_fail_3_src(data)                                   ((0x00000008&(data))>>3)
#define BIST4_get_usb_bist_host_ram_2_fail_3(data)                                   ((0x00000008&(data))>>3)
#define BIST4_usb_bist_host_ram_2_fail_2_shift                                       (2)
#define BIST4_usb_bist_host_ram_2_fail_2_mask                                        (0x00000004)
#define BIST4_usb_bist_host_ram_2_fail_2(data)                                       (0x00000004&((data)<<2))
#define BIST4_usb_bist_host_ram_2_fail_2_src(data)                                   ((0x00000004&(data))>>2)
#define BIST4_get_usb_bist_host_ram_2_fail_2(data)                                   ((0x00000004&(data))>>2)
#define BIST4_usb_bist_host_ram_2_fail_1_shift                                       (1)
#define BIST4_usb_bist_host_ram_2_fail_1_mask                                        (0x00000002)
#define BIST4_usb_bist_host_ram_2_fail_1(data)                                       (0x00000002&((data)<<1))
#define BIST4_usb_bist_host_ram_2_fail_1_src(data)                                   ((0x00000002&(data))>>1)
#define BIST4_get_usb_bist_host_ram_2_fail_1(data)                                   ((0x00000002&(data))>>1)
#define BIST4_usb_bist_host_ram_2_fail_0_shift                                       (0)
#define BIST4_usb_bist_host_ram_2_fail_0_mask                                        (0x00000001)
#define BIST4_usb_bist_host_ram_2_fail_0(data)                                       (0x00000001&((data)<<0))
#define BIST4_usb_bist_host_ram_2_fail_0_src(data)                                   ((0x00000001&(data))>>0)
#define BIST4_get_usb_bist_host_ram_2_fail_0(data)                                   ((0x00000001&(data))>>0)


#define BIST5                                                                        0x1805A114
#define BIST5_reg_addr                                                               "0xB805A114"
#define BIST5_reg                                                                    0xB805A114
#define set_BIST5_reg(data)   (*((volatile unsigned int*) BIST5_reg)=data)
#define get_BIST5_reg   (*((volatile unsigned int*) BIST5_reg))
#define BIST5_inst_adr                                                               "0x0045"
#define BIST5_inst                                                                   0x0045
#define BIST5_usb_bist_wrap_fail_1_shift                                             (1)
#define BIST5_usb_bist_wrap_fail_1_mask                                              (0x00000002)
#define BIST5_usb_bist_wrap_fail_1(data)                                             (0x00000002&((data)<<1))
#define BIST5_usb_bist_wrap_fail_1_src(data)                                         ((0x00000002&(data))>>1)
#define BIST5_get_usb_bist_wrap_fail_1(data)                                         ((0x00000002&(data))>>1)
#define BIST5_usb_bist_wrap_fail_0_shift                                             (0)
#define BIST5_usb_bist_wrap_fail_0_mask                                              (0x00000001)
#define BIST5_usb_bist_wrap_fail_0(data)                                             (0x00000001&((data)<<0))
#define BIST5_usb_bist_wrap_fail_0_src(data)                                         ((0x00000001&(data))>>0)
#define BIST5_get_usb_bist_wrap_fail_0(data)                                         ((0x00000001&(data))>>0)


#define DRF0                                                                         0x1805A118
#define DRF0_reg_addr                                                                "0xB805A118"
#define DRF0_reg                                                                     0xB805A118
#define set_DRF0_reg(data)   (*((volatile unsigned int*) DRF0_reg)=data)
#define get_DRF0_reg   (*((volatile unsigned int*) DRF0_reg))
#define DRF0_inst_adr                                                                "0x0046"
#define DRF0_inst                                                                    0x0046
#define DRF0_usb_drf_mode_host_ram_1_shift                                           (2)
#define DRF0_usb_drf_mode_host_ram_1_mask                                            (0x00000004)
#define DRF0_usb_drf_mode_host_ram_1(data)                                           (0x00000004&((data)<<2))
#define DRF0_usb_drf_mode_host_ram_1_src(data)                                       ((0x00000004&(data))>>2)
#define DRF0_get_usb_drf_mode_host_ram_1(data)                                       ((0x00000004&(data))>>2)
#define DRF0_usb_drf_mode_host_ram_2_shift                                           (1)
#define DRF0_usb_drf_mode_host_ram_2_mask                                            (0x00000002)
#define DRF0_usb_drf_mode_host_ram_2(data)                                           (0x00000002&((data)<<1))
#define DRF0_usb_drf_mode_host_ram_2_src(data)                                       ((0x00000002&(data))>>1)
#define DRF0_get_usb_drf_mode_host_ram_2(data)                                       ((0x00000002&(data))>>1)
#define DRF0_usb_drf_mode_wrap_shift                                                 (0)
#define DRF0_usb_drf_mode_wrap_mask                                                  (0x00000001)
#define DRF0_usb_drf_mode_wrap(data)                                                 (0x00000001&((data)<<0))
#define DRF0_usb_drf_mode_wrap_src(data)                                             ((0x00000001&(data))>>0)
#define DRF0_get_usb_drf_mode_wrap(data)                                             ((0x00000001&(data))>>0)


#define DRF1                                                                         0x1805A11c
#define DRF1_reg_addr                                                                "0xB805A11C"
#define DRF1_reg                                                                     0xB805A11C
#define set_DRF1_reg(data)   (*((volatile unsigned int*) DRF1_reg)=data)
#define get_DRF1_reg   (*((volatile unsigned int*) DRF1_reg))
#define DRF1_inst_adr                                                                "0x0047"
#define DRF1_inst                                                                    0x0047
#define DRF1_usb_drf_resume_host_ram_1_shift                                         (2)
#define DRF1_usb_drf_resume_host_ram_1_mask                                          (0x00000004)
#define DRF1_usb_drf_resume_host_ram_1(data)                                         (0x00000004&((data)<<2))
#define DRF1_usb_drf_resume_host_ram_1_src(data)                                     ((0x00000004&(data))>>2)
#define DRF1_get_usb_drf_resume_host_ram_1(data)                                     ((0x00000004&(data))>>2)
#define DRF1_usb_drf_resume_host_ram_2_shift                                         (1)
#define DRF1_usb_drf_resume_host_ram_2_mask                                          (0x00000002)
#define DRF1_usb_drf_resume_host_ram_2(data)                                         (0x00000002&((data)<<1))
#define DRF1_usb_drf_resume_host_ram_2_src(data)                                     ((0x00000002&(data))>>1)
#define DRF1_get_usb_drf_resume_host_ram_2(data)                                     ((0x00000002&(data))>>1)
#define DRF1_usb_drf_resume_wrap_shift                                               (0)
#define DRF1_usb_drf_resume_wrap_mask                                                (0x00000001)
#define DRF1_usb_drf_resume_wrap(data)                                               (0x00000001&((data)<<0))
#define DRF1_usb_drf_resume_wrap_src(data)                                           ((0x00000001&(data))>>0)
#define DRF1_get_usb_drf_resume_wrap(data)                                           ((0x00000001&(data))>>0)


#define DRF2                                                                         0x1805A120
#define DRF2_reg_addr                                                                "0xB805A120"
#define DRF2_reg                                                                     0xB805A120
#define set_DRF2_reg(data)   (*((volatile unsigned int*) DRF2_reg)=data)
#define get_DRF2_reg   (*((volatile unsigned int*) DRF2_reg))
#define DRF2_inst_adr                                                                "0x0048"
#define DRF2_inst                                                                    0x0048
#define DRF2_usb_drf_done_host_ram_1_shift                                           (2)
#define DRF2_usb_drf_done_host_ram_1_mask                                            (0x00000004)
#define DRF2_usb_drf_done_host_ram_1(data)                                           (0x00000004&((data)<<2))
#define DRF2_usb_drf_done_host_ram_1_src(data)                                       ((0x00000004&(data))>>2)
#define DRF2_get_usb_drf_done_host_ram_1(data)                                       ((0x00000004&(data))>>2)
#define DRF2_usb_drf_done_host_ram_2_shift                                           (1)
#define DRF2_usb_drf_done_host_ram_2_mask                                            (0x00000002)
#define DRF2_usb_drf_done_host_ram_2(data)                                           (0x00000002&((data)<<1))
#define DRF2_usb_drf_done_host_ram_2_src(data)                                       ((0x00000002&(data))>>1)
#define DRF2_get_usb_drf_done_host_ram_2(data)                                       ((0x00000002&(data))>>1)
#define DRF2_usb_drf_done_wrap_shift                                                 (0)
#define DRF2_usb_drf_done_wrap_mask                                                  (0x00000001)
#define DRF2_usb_drf_done_wrap(data)                                                 (0x00000001&((data)<<0))
#define DRF2_usb_drf_done_wrap_src(data)                                             ((0x00000001&(data))>>0)
#define DRF2_get_usb_drf_done_wrap(data)                                             ((0x00000001&(data))>>0)


#define DRF3                                                                         0x1805A124
#define DRF3_reg_addr                                                                "0xB805A124"
#define DRF3_reg                                                                     0xB805A124
#define set_DRF3_reg(data)   (*((volatile unsigned int*) DRF3_reg)=data)
#define get_DRF3_reg   (*((volatile unsigned int*) DRF3_reg))
#define DRF3_inst_adr                                                                "0x0049"
#define DRF3_inst                                                                    0x0049
#define DRF3_usb_drf_pause_host_ram_1_shift                                          (2)
#define DRF3_usb_drf_pause_host_ram_1_mask                                           (0x00000004)
#define DRF3_usb_drf_pause_host_ram_1(data)                                          (0x00000004&((data)<<2))
#define DRF3_usb_drf_pause_host_ram_1_src(data)                                      ((0x00000004&(data))>>2)
#define DRF3_get_usb_drf_pause_host_ram_1(data)                                      ((0x00000004&(data))>>2)
#define DRF3_usb_drf_pause_host_ram_2_shift                                          (1)
#define DRF3_usb_drf_pause_host_ram_2_mask                                           (0x00000002)
#define DRF3_usb_drf_pause_host_ram_2(data)                                          (0x00000002&((data)<<1))
#define DRF3_usb_drf_pause_host_ram_2_src(data)                                      ((0x00000002&(data))>>1)
#define DRF3_get_usb_drf_pause_host_ram_2(data)                                      ((0x00000002&(data))>>1)
#define DRF3_usb_drf_pause_wrap_shift                                                (0)
#define DRF3_usb_drf_pause_wrap_mask                                                 (0x00000001)
#define DRF3_usb_drf_pause_wrap(data)                                                (0x00000001&((data)<<0))
#define DRF3_usb_drf_pause_wrap_src(data)                                            ((0x00000001&(data))>>0)
#define DRF3_get_usb_drf_pause_wrap(data)                                            ((0x00000001&(data))>>0)


#define DRF4                                                                         0x1805A128
#define DRF4_reg_addr                                                                "0xB805A128"
#define DRF4_reg                                                                     0xB805A128
#define set_DRF4_reg(data)   (*((volatile unsigned int*) DRF4_reg)=data)
#define get_DRF4_reg   (*((volatile unsigned int*) DRF4_reg))
#define DRF4_inst_adr                                                                "0x004A"
#define DRF4_inst                                                                    0x004A
#define DRF4_usb_drf_fail_group_host_ram_1_shift                                     (2)
#define DRF4_usb_drf_fail_group_host_ram_1_mask                                      (0x00000004)
#define DRF4_usb_drf_fail_group_host_ram_1(data)                                     (0x00000004&((data)<<2))
#define DRF4_usb_drf_fail_group_host_ram_1_src(data)                                 ((0x00000004&(data))>>2)
#define DRF4_get_usb_drf_fail_group_host_ram_1(data)                                 ((0x00000004&(data))>>2)
#define DRF4_usb_drf_fail_group_host_ram_2_shift                                     (1)
#define DRF4_usb_drf_fail_group_host_ram_2_mask                                      (0x00000002)
#define DRF4_usb_drf_fail_group_host_ram_2(data)                                     (0x00000002&((data)<<1))
#define DRF4_usb_drf_fail_group_host_ram_2_src(data)                                 ((0x00000002&(data))>>1)
#define DRF4_get_usb_drf_fail_group_host_ram_2(data)                                 ((0x00000002&(data))>>1)
#define DRF4_usb_drf_fail_group_wrap_shift                                           (0)
#define DRF4_usb_drf_fail_group_wrap_mask                                            (0x00000001)
#define DRF4_usb_drf_fail_group_wrap(data)                                           (0x00000001&((data)<<0))
#define DRF4_usb_drf_fail_group_wrap_src(data)                                       ((0x00000001&(data))>>0)
#define DRF4_get_usb_drf_fail_group_wrap(data)                                       ((0x00000001&(data))>>0)


#define DRF5                                                                         0x1805A12c
#define DRF5_reg_addr                                                                "0xB805A12C"
#define DRF5_reg                                                                     0xB805A12C
#define set_DRF5_reg(data)   (*((volatile unsigned int*) DRF5_reg)=data)
#define get_DRF5_reg   (*((volatile unsigned int*) DRF5_reg))
#define DRF5_inst_adr                                                                "0x004B"
#define DRF5_inst                                                                    0x004B
#define DRF5_usb_drf_host_ram_1_fail_3_shift                                         (3)
#define DRF5_usb_drf_host_ram_1_fail_3_mask                                          (0x00000008)
#define DRF5_usb_drf_host_ram_1_fail_3(data)                                         (0x00000008&((data)<<3))
#define DRF5_usb_drf_host_ram_1_fail_3_src(data)                                     ((0x00000008&(data))>>3)
#define DRF5_get_usb_drf_host_ram_1_fail_3(data)                                     ((0x00000008&(data))>>3)
#define DRF5_usb_drf_host_ram_1_fail_2_shift                                         (2)
#define DRF5_usb_drf_host_ram_1_fail_2_mask                                          (0x00000004)
#define DRF5_usb_drf_host_ram_1_fail_2(data)                                         (0x00000004&((data)<<2))
#define DRF5_usb_drf_host_ram_1_fail_2_src(data)                                     ((0x00000004&(data))>>2)
#define DRF5_get_usb_drf_host_ram_1_fail_2(data)                                     ((0x00000004&(data))>>2)
#define DRF5_usb_drf_host_ram_1_fail_1_shift                                         (1)
#define DRF5_usb_drf_host_ram_1_fail_1_mask                                          (0x00000002)
#define DRF5_usb_drf_host_ram_1_fail_1(data)                                         (0x00000002&((data)<<1))
#define DRF5_usb_drf_host_ram_1_fail_1_src(data)                                     ((0x00000002&(data))>>1)
#define DRF5_get_usb_drf_host_ram_1_fail_1(data)                                     ((0x00000002&(data))>>1)
#define DRF5_usb_drf_host_ram_1_fail_0_shift                                         (0)
#define DRF5_usb_drf_host_ram_1_fail_0_mask                                          (0x00000001)
#define DRF5_usb_drf_host_ram_1_fail_0(data)                                         (0x00000001&((data)<<0))
#define DRF5_usb_drf_host_ram_1_fail_0_src(data)                                     ((0x00000001&(data))>>0)
#define DRF5_get_usb_drf_host_ram_1_fail_0(data)                                     ((0x00000001&(data))>>0)


#define DRF6                                                                         0x1805A130
#define DRF6_reg_addr                                                                "0xB805A130"
#define DRF6_reg                                                                     0xB805A130
#define set_DRF6_reg(data)   (*((volatile unsigned int*) DRF6_reg)=data)
#define get_DRF6_reg   (*((volatile unsigned int*) DRF6_reg))
#define DRF6_inst_adr                                                                "0x004C"
#define DRF6_inst                                                                    0x004C
#define DRF6_usb_drf_host_ram_2_fail_3_shift                                         (3)
#define DRF6_usb_drf_host_ram_2_fail_3_mask                                          (0x00000008)
#define DRF6_usb_drf_host_ram_2_fail_3(data)                                         (0x00000008&((data)<<3))
#define DRF6_usb_drf_host_ram_2_fail_3_src(data)                                     ((0x00000008&(data))>>3)
#define DRF6_get_usb_drf_host_ram_2_fail_3(data)                                     ((0x00000008&(data))>>3)
#define DRF6_usb_drf_host_ram_2_fail_2_shift                                         (2)
#define DRF6_usb_drf_host_ram_2_fail_2_mask                                          (0x00000004)
#define DRF6_usb_drf_host_ram_2_fail_2(data)                                         (0x00000004&((data)<<2))
#define DRF6_usb_drf_host_ram_2_fail_2_src(data)                                     ((0x00000004&(data))>>2)
#define DRF6_get_usb_drf_host_ram_2_fail_2(data)                                     ((0x00000004&(data))>>2)
#define DRF6_usb_drf_host_ram_2_fail_1_shift                                         (1)
#define DRF6_usb_drf_host_ram_2_fail_1_mask                                          (0x00000002)
#define DRF6_usb_drf_host_ram_2_fail_1(data)                                         (0x00000002&((data)<<1))
#define DRF6_usb_drf_host_ram_2_fail_1_src(data)                                     ((0x00000002&(data))>>1)
#define DRF6_get_usb_drf_host_ram_2_fail_1(data)                                     ((0x00000002&(data))>>1)
#define DRF6_usb_drf_host_ram_2_fail_0_shift                                         (0)
#define DRF6_usb_drf_host_ram_2_fail_0_mask                                          (0x00000001)
#define DRF6_usb_drf_host_ram_2_fail_0(data)                                         (0x00000001&((data)<<0))
#define DRF6_usb_drf_host_ram_2_fail_0_src(data)                                     ((0x00000001&(data))>>0)
#define DRF6_get_usb_drf_host_ram_2_fail_0(data)                                     ((0x00000001&(data))>>0)


#define DRF7                                                                         0x1805A134
#define DRF7_reg_addr                                                                "0xB805A134"
#define DRF7_reg                                                                     0xB805A134
#define set_DRF7_reg(data)   (*((volatile unsigned int*) DRF7_reg)=data)
#define get_DRF7_reg   (*((volatile unsigned int*) DRF7_reg))
#define DRF7_inst_adr                                                                "0x004D"
#define DRF7_inst                                                                    0x004D
#define DRF7_usb_drf_wrap_fail_1_shift                                               (1)
#define DRF7_usb_drf_wrap_fail_1_mask                                                (0x00000002)
#define DRF7_usb_drf_wrap_fail_1(data)                                               (0x00000002&((data)<<1))
#define DRF7_usb_drf_wrap_fail_1_src(data)                                           ((0x00000002&(data))>>1)
#define DRF7_get_usb_drf_wrap_fail_1(data)                                           ((0x00000002&(data))>>1)
#define DRF7_usb_drf_wrap_fail_0_shift                                               (0)
#define DRF7_usb_drf_wrap_fail_0_mask                                                (0x00000001)
#define DRF7_usb_drf_wrap_fail_0(data)                                               (0x00000001&((data)<<0))
#define DRF7_usb_drf_wrap_fail_0_src(data)                                           ((0x00000001&(data))>>0)
#define DRF7_get_usb_drf_wrap_fail_0(data)                                           ((0x00000001&(data))>>0)


#define BIST_OP0                                                                     0x1805A138
#define BIST_OP0_reg_addr                                                            "0xB805A138"
#define BIST_OP0_reg                                                                 0xB805A138
#define set_BIST_OP0_reg(data)   (*((volatile unsigned int*) BIST_OP0_reg)=data)
#define get_BIST_OP0_reg   (*((volatile unsigned int*) BIST_OP0_reg))
#define BIST_OP0_inst_adr                                                            "0x004E"
#define BIST_OP0_inst                                                                0x004E
#define BIST_OP0_usb_bist_wrap_ls1_shift                                             (11)
#define BIST_OP0_usb_bist_wrap_ls1_mask                                              (0x00000800)
#define BIST_OP0_usb_bist_wrap_ls1(data)                                             (0x00000800&((data)<<11))
#define BIST_OP0_usb_bist_wrap_ls1_src(data)                                         ((0x00000800&(data))>>11)
#define BIST_OP0_get_usb_bist_wrap_ls1(data)                                         ((0x00000800&(data))>>11)
#define BIST_OP0_usb_bist_wrap_rme1_shift                                            (10)
#define BIST_OP0_usb_bist_wrap_rme1_mask                                             (0x00000400)
#define BIST_OP0_usb_bist_wrap_rme1(data)                                            (0x00000400&((data)<<10))
#define BIST_OP0_usb_bist_wrap_rme1_src(data)                                        ((0x00000400&(data))>>10)
#define BIST_OP0_get_usb_bist_wrap_rme1(data)                                        ((0x00000400&(data))>>10)
#define BIST_OP0_usb_bist_wrap_rm1_shift                                             (6)
#define BIST_OP0_usb_bist_wrap_rm1_mask                                              (0x000003C0)
#define BIST_OP0_usb_bist_wrap_rm1(data)                                             (0x000003C0&((data)<<6))
#define BIST_OP0_usb_bist_wrap_rm1_src(data)                                         ((0x000003C0&(data))>>6)
#define BIST_OP0_get_usb_bist_wrap_rm1(data)                                         ((0x000003C0&(data))>>6)
#define BIST_OP0_usb_bist_wrap_ls0_shift                                             (5)
#define BIST_OP0_usb_bist_wrap_ls0_mask                                              (0x00000020)
#define BIST_OP0_usb_bist_wrap_ls0(data)                                             (0x00000020&((data)<<5))
#define BIST_OP0_usb_bist_wrap_ls0_src(data)                                         ((0x00000020&(data))>>5)
#define BIST_OP0_get_usb_bist_wrap_ls0(data)                                         ((0x00000020&(data))>>5)
#define BIST_OP0_usb_bist_wrap_rme0_shift                                            (4)
#define BIST_OP0_usb_bist_wrap_rme0_mask                                             (0x00000010)
#define BIST_OP0_usb_bist_wrap_rme0(data)                                            (0x00000010&((data)<<4))
#define BIST_OP0_usb_bist_wrap_rme0_src(data)                                        ((0x00000010&(data))>>4)
#define BIST_OP0_get_usb_bist_wrap_rme0(data)                                        ((0x00000010&(data))>>4)
#define BIST_OP0_usb_bist_wrap_rm0_shift                                             (0)
#define BIST_OP0_usb_bist_wrap_rm0_mask                                              (0x0000000F)
#define BIST_OP0_usb_bist_wrap_rm0(data)                                             (0x0000000F&((data)<<0))
#define BIST_OP0_usb_bist_wrap_rm0_src(data)                                         ((0x0000000F&(data))>>0)
#define BIST_OP0_get_usb_bist_wrap_rm0(data)                                         ((0x0000000F&(data))>>0)


#define BIST_OP1                                                                     0x1805A13c
#define BIST_OP1_reg_addr                                                            "0xB805A13C"
#define BIST_OP1_reg                                                                 0xB805A13C
#define set_BIST_OP1_reg(data)   (*((volatile unsigned int*) BIST_OP1_reg)=data)
#define get_BIST_OP1_reg   (*((volatile unsigned int*) BIST_OP1_reg))
#define BIST_OP1_inst_adr                                                            "0x004F"
#define BIST_OP1_inst                                                                0x004F
#define BIST_OP1_usb_usb_host_ram_1_ls3_shift                                        (23)
#define BIST_OP1_usb_usb_host_ram_1_ls3_mask                                         (0x00800000)
#define BIST_OP1_usb_usb_host_ram_1_ls3(data)                                        (0x00800000&((data)<<23))
#define BIST_OP1_usb_usb_host_ram_1_ls3_src(data)                                    ((0x00800000&(data))>>23)
#define BIST_OP1_get_usb_usb_host_ram_1_ls3(data)                                    ((0x00800000&(data))>>23)
#define BIST_OP1_usb_usb_host_ram_1_rme3_shift                                       (22)
#define BIST_OP1_usb_usb_host_ram_1_rme3_mask                                        (0x00400000)
#define BIST_OP1_usb_usb_host_ram_1_rme3(data)                                       (0x00400000&((data)<<22))
#define BIST_OP1_usb_usb_host_ram_1_rme3_src(data)                                   ((0x00400000&(data))>>22)
#define BIST_OP1_get_usb_usb_host_ram_1_rme3(data)                                   ((0x00400000&(data))>>22)
#define BIST_OP1_usb_usb_host_ram_1_rm3_shift                                        (18)
#define BIST_OP1_usb_usb_host_ram_1_rm3_mask                                         (0x003C0000)
#define BIST_OP1_usb_usb_host_ram_1_rm3(data)                                        (0x003C0000&((data)<<18))
#define BIST_OP1_usb_usb_host_ram_1_rm3_src(data)                                    ((0x003C0000&(data))>>18)
#define BIST_OP1_get_usb_usb_host_ram_1_rm3(data)                                    ((0x003C0000&(data))>>18)
#define BIST_OP1_usb_usb_host_ram_1_ls2_shift                                        (17)
#define BIST_OP1_usb_usb_host_ram_1_ls2_mask                                         (0x00020000)
#define BIST_OP1_usb_usb_host_ram_1_ls2(data)                                        (0x00020000&((data)<<17))
#define BIST_OP1_usb_usb_host_ram_1_ls2_src(data)                                    ((0x00020000&(data))>>17)
#define BIST_OP1_get_usb_usb_host_ram_1_ls2(data)                                    ((0x00020000&(data))>>17)
#define BIST_OP1_usb_usb_host_ram_1_rme2_shift                                       (16)
#define BIST_OP1_usb_usb_host_ram_1_rme2_mask                                        (0x00010000)
#define BIST_OP1_usb_usb_host_ram_1_rme2(data)                                       (0x00010000&((data)<<16))
#define BIST_OP1_usb_usb_host_ram_1_rme2_src(data)                                   ((0x00010000&(data))>>16)
#define BIST_OP1_get_usb_usb_host_ram_1_rme2(data)                                   ((0x00010000&(data))>>16)
#define BIST_OP1_usb_usb_host_ram_1_rm2_shift                                        (12)
#define BIST_OP1_usb_usb_host_ram_1_rm2_mask                                         (0x0000F000)
#define BIST_OP1_usb_usb_host_ram_1_rm2(data)                                        (0x0000F000&((data)<<12))
#define BIST_OP1_usb_usb_host_ram_1_rm2_src(data)                                    ((0x0000F000&(data))>>12)
#define BIST_OP1_get_usb_usb_host_ram_1_rm2(data)                                    ((0x0000F000&(data))>>12)
#define BIST_OP1_usb_usb_host_ram_1_ls1_shift                                        (11)
#define BIST_OP1_usb_usb_host_ram_1_ls1_mask                                         (0x00000800)
#define BIST_OP1_usb_usb_host_ram_1_ls1(data)                                        (0x00000800&((data)<<11))
#define BIST_OP1_usb_usb_host_ram_1_ls1_src(data)                                    ((0x00000800&(data))>>11)
#define BIST_OP1_get_usb_usb_host_ram_1_ls1(data)                                    ((0x00000800&(data))>>11)
#define BIST_OP1_usb_usb_host_ram_1_rme1_shift                                       (10)
#define BIST_OP1_usb_usb_host_ram_1_rme1_mask                                        (0x00000400)
#define BIST_OP1_usb_usb_host_ram_1_rme1(data)                                       (0x00000400&((data)<<10))
#define BIST_OP1_usb_usb_host_ram_1_rme1_src(data)                                   ((0x00000400&(data))>>10)
#define BIST_OP1_get_usb_usb_host_ram_1_rme1(data)                                   ((0x00000400&(data))>>10)
#define BIST_OP1_usb_usb_host_ram_1_rm1_shift                                        (6)
#define BIST_OP1_usb_usb_host_ram_1_rm1_mask                                         (0x000003C0)
#define BIST_OP1_usb_usb_host_ram_1_rm1(data)                                        (0x000003C0&((data)<<6))
#define BIST_OP1_usb_usb_host_ram_1_rm1_src(data)                                    ((0x000003C0&(data))>>6)
#define BIST_OP1_get_usb_usb_host_ram_1_rm1(data)                                    ((0x000003C0&(data))>>6)
#define BIST_OP1_usb_usb_host_ram_1_ls0_shift                                        (5)
#define BIST_OP1_usb_usb_host_ram_1_ls0_mask                                         (0x00000020)
#define BIST_OP1_usb_usb_host_ram_1_ls0(data)                                        (0x00000020&((data)<<5))
#define BIST_OP1_usb_usb_host_ram_1_ls0_src(data)                                    ((0x00000020&(data))>>5)
#define BIST_OP1_get_usb_usb_host_ram_1_ls0(data)                                    ((0x00000020&(data))>>5)
#define BIST_OP1_usb_usb_host_ram_1_rme0_shift                                       (4)
#define BIST_OP1_usb_usb_host_ram_1_rme0_mask                                        (0x00000010)
#define BIST_OP1_usb_usb_host_ram_1_rme0(data)                                       (0x00000010&((data)<<4))
#define BIST_OP1_usb_usb_host_ram_1_rme0_src(data)                                   ((0x00000010&(data))>>4)
#define BIST_OP1_get_usb_usb_host_ram_1_rme0(data)                                   ((0x00000010&(data))>>4)
#define BIST_OP1_usb_usb_host_ram_1_rm0_shift                                        (0)
#define BIST_OP1_usb_usb_host_ram_1_rm0_mask                                         (0x0000000F)
#define BIST_OP1_usb_usb_host_ram_1_rm0(data)                                        (0x0000000F&((data)<<0))
#define BIST_OP1_usb_usb_host_ram_1_rm0_src(data)                                    ((0x0000000F&(data))>>0)
#define BIST_OP1_get_usb_usb_host_ram_1_rm0(data)                                    ((0x0000000F&(data))>>0)


#define BIST_OP2                                                                     0x1805A140
#define BIST_OP2_reg_addr                                                            "0xB805A140"
#define BIST_OP2_reg                                                                 0xB805A140
#define set_BIST_OP2_reg(data)   (*((volatile unsigned int*) BIST_OP2_reg)=data)
#define get_BIST_OP2_reg   (*((volatile unsigned int*) BIST_OP2_reg))
#define BIST_OP2_inst_adr                                                            "0x0050"
#define BIST_OP2_inst                                                                0x0050
#define BIST_OP2_usb_usb_host_ram_2_ls3_shift                                        (23)
#define BIST_OP2_usb_usb_host_ram_2_ls3_mask                                         (0x00800000)
#define BIST_OP2_usb_usb_host_ram_2_ls3(data)                                        (0x00800000&((data)<<23))
#define BIST_OP2_usb_usb_host_ram_2_ls3_src(data)                                    ((0x00800000&(data))>>23)
#define BIST_OP2_get_usb_usb_host_ram_2_ls3(data)                                    ((0x00800000&(data))>>23)
#define BIST_OP2_usb_usb_host_ram_2_rme3_shift                                       (22)
#define BIST_OP2_usb_usb_host_ram_2_rme3_mask                                        (0x00400000)
#define BIST_OP2_usb_usb_host_ram_2_rme3(data)                                       (0x00400000&((data)<<22))
#define BIST_OP2_usb_usb_host_ram_2_rme3_src(data)                                   ((0x00400000&(data))>>22)
#define BIST_OP2_get_usb_usb_host_ram_2_rme3(data)                                   ((0x00400000&(data))>>22)
#define BIST_OP2_usb_usb_host_ram_2_rm3_shift                                        (18)
#define BIST_OP2_usb_usb_host_ram_2_rm3_mask                                         (0x003C0000)
#define BIST_OP2_usb_usb_host_ram_2_rm3(data)                                        (0x003C0000&((data)<<18))
#define BIST_OP2_usb_usb_host_ram_2_rm3_src(data)                                    ((0x003C0000&(data))>>18)
#define BIST_OP2_get_usb_usb_host_ram_2_rm3(data)                                    ((0x003C0000&(data))>>18)
#define BIST_OP2_usb_usb_host_ram_2_ls2_shift                                        (17)
#define BIST_OP2_usb_usb_host_ram_2_ls2_mask                                         (0x00020000)
#define BIST_OP2_usb_usb_host_ram_2_ls2(data)                                        (0x00020000&((data)<<17))
#define BIST_OP2_usb_usb_host_ram_2_ls2_src(data)                                    ((0x00020000&(data))>>17)
#define BIST_OP2_get_usb_usb_host_ram_2_ls2(data)                                    ((0x00020000&(data))>>17)
#define BIST_OP2_usb_usb_host_ram_2_rme2_shift                                       (16)
#define BIST_OP2_usb_usb_host_ram_2_rme2_mask                                        (0x00010000)
#define BIST_OP2_usb_usb_host_ram_2_rme2(data)                                       (0x00010000&((data)<<16))
#define BIST_OP2_usb_usb_host_ram_2_rme2_src(data)                                   ((0x00010000&(data))>>16)
#define BIST_OP2_get_usb_usb_host_ram_2_rme2(data)                                   ((0x00010000&(data))>>16)
#define BIST_OP2_usb_usb_host_ram_2_rm2_shift                                        (12)
#define BIST_OP2_usb_usb_host_ram_2_rm2_mask                                         (0x0000F000)
#define BIST_OP2_usb_usb_host_ram_2_rm2(data)                                        (0x0000F000&((data)<<12))
#define BIST_OP2_usb_usb_host_ram_2_rm2_src(data)                                    ((0x0000F000&(data))>>12)
#define BIST_OP2_get_usb_usb_host_ram_2_rm2(data)                                    ((0x0000F000&(data))>>12)
#define BIST_OP2_usb_usb_host_ram_2_ls1_shift                                        (11)
#define BIST_OP2_usb_usb_host_ram_2_ls1_mask                                         (0x00000800)
#define BIST_OP2_usb_usb_host_ram_2_ls1(data)                                        (0x00000800&((data)<<11))
#define BIST_OP2_usb_usb_host_ram_2_ls1_src(data)                                    ((0x00000800&(data))>>11)
#define BIST_OP2_get_usb_usb_host_ram_2_ls1(data)                                    ((0x00000800&(data))>>11)
#define BIST_OP2_usb_usb_host_ram_2_rme1_shift                                       (10)
#define BIST_OP2_usb_usb_host_ram_2_rme1_mask                                        (0x00000400)
#define BIST_OP2_usb_usb_host_ram_2_rme1(data)                                       (0x00000400&((data)<<10))
#define BIST_OP2_usb_usb_host_ram_2_rme1_src(data)                                   ((0x00000400&(data))>>10)
#define BIST_OP2_get_usb_usb_host_ram_2_rme1(data)                                   ((0x00000400&(data))>>10)
#define BIST_OP2_usb_usb_host_ram_2_rm1_shift                                        (6)
#define BIST_OP2_usb_usb_host_ram_2_rm1_mask                                         (0x000003C0)
#define BIST_OP2_usb_usb_host_ram_2_rm1(data)                                        (0x000003C0&((data)<<6))
#define BIST_OP2_usb_usb_host_ram_2_rm1_src(data)                                    ((0x000003C0&(data))>>6)
#define BIST_OP2_get_usb_usb_host_ram_2_rm1(data)                                    ((0x000003C0&(data))>>6)
#define BIST_OP2_usb_usb_host_ram_2_ls0_shift                                        (5)
#define BIST_OP2_usb_usb_host_ram_2_ls0_mask                                         (0x00000020)
#define BIST_OP2_usb_usb_host_ram_2_ls0(data)                                        (0x00000020&((data)<<5))
#define BIST_OP2_usb_usb_host_ram_2_ls0_src(data)                                    ((0x00000020&(data))>>5)
#define BIST_OP2_get_usb_usb_host_ram_2_ls0(data)                                    ((0x00000020&(data))>>5)
#define BIST_OP2_usb_usb_host_ram_2_rme0_shift                                       (4)
#define BIST_OP2_usb_usb_host_ram_2_rme0_mask                                        (0x00000010)
#define BIST_OP2_usb_usb_host_ram_2_rme0(data)                                       (0x00000010&((data)<<4))
#define BIST_OP2_usb_usb_host_ram_2_rme0_src(data)                                   ((0x00000010&(data))>>4)
#define BIST_OP2_get_usb_usb_host_ram_2_rme0(data)                                   ((0x00000010&(data))>>4)
#define BIST_OP2_usb_usb_host_ram_2_rm0_shift                                        (0)
#define BIST_OP2_usb_usb_host_ram_2_rm0_mask                                         (0x0000000F)
#define BIST_OP2_usb_usb_host_ram_2_rm0(data)                                        (0x0000000F&((data)<<0))
#define BIST_OP2_usb_usb_host_ram_2_rm0_src(data)                                    ((0x0000000F&(data))>>0)
#define BIST_OP2_get_usb_usb_host_ram_2_rm0(data)                                    ((0x0000000F&(data))>>0)


#define TC_MUX                                                                       0x1805A144
#define TC_MUX_reg_addr                                                              "0xB805A144"
#define TC_MUX_reg                                                                   0xB805A144
#define set_TC_MUX_reg(data)   (*((volatile unsigned int*) TC_MUX_reg)=data)
#define get_TC_MUX_reg   (*((volatile unsigned int*) TC_MUX_reg))
#define TC_MUX_inst_adr                                                              "0x0051"
#define TC_MUX_inst                                                                  0x0051
#define TC_MUX_EN_CC2_RP4P7K_shift                                                   (18)
#define TC_MUX_EN_CC2_RP4P7K_mask                                                    (0x00040000)
#define TC_MUX_EN_CC2_RP4P7K(data)                                                   (0x00040000&((data)<<18))
#define TC_MUX_EN_CC2_RP4P7K_src(data)                                               ((0x00040000&(data))>>18)
#define TC_MUX_get_EN_CC2_RP4P7K(data)                                               ((0x00040000&(data))>>18)
#define TC_MUX_EN_CC2_RP36K_shift                                                    (17)
#define TC_MUX_EN_CC2_RP36K_mask                                                     (0x00020000)
#define TC_MUX_EN_CC2_RP36K(data)                                                    (0x00020000&((data)<<17))
#define TC_MUX_EN_CC2_RP36K_src(data)                                                ((0x00020000&(data))>>17)
#define TC_MUX_get_EN_CC2_RP36K(data)                                                ((0x00020000&(data))>>17)
#define TC_MUX_EN_CC2_RP12K_shift                                                    (16)
#define TC_MUX_EN_CC2_RP12K_mask                                                     (0x00010000)
#define TC_MUX_EN_CC2_RP12K(data)                                                    (0x00010000&((data)<<16))
#define TC_MUX_EN_CC2_RP12K_src(data)                                                ((0x00010000&(data))>>16)
#define TC_MUX_get_EN_CC2_RP12K(data)                                                ((0x00010000&(data))>>16)
#define TC_MUX_EN_CC2_RD_shift                                                       (15)
#define TC_MUX_EN_CC2_RD_mask                                                        (0x00008000)
#define TC_MUX_EN_CC2_RD(data)                                                       (0x00008000&((data)<<15))
#define TC_MUX_EN_CC2_RD_src(data)                                                   ((0x00008000&(data))>>15)
#define TC_MUX_get_EN_CC2_RD(data)                                                   ((0x00008000&(data))>>15)
#define TC_MUX_EN_CC2_DET_shift                                                      (14)
#define TC_MUX_EN_CC2_DET_mask                                                       (0x00004000)
#define TC_MUX_EN_CC2_DET(data)                                                      (0x00004000&((data)<<14))
#define TC_MUX_EN_CC2_DET_src(data)                                                  ((0x00004000&(data))>>14)
#define TC_MUX_get_EN_CC2_DET(data)                                                  ((0x00004000&(data))>>14)
#define TC_MUX_Cc2_det20_shift                                                       (11)
#define TC_MUX_Cc2_det20_mask                                                        (0x00003800)
#define TC_MUX_Cc2_det20(data)                                                       (0x00003800&((data)<<11))
#define TC_MUX_Cc2_det20_src(data)                                                   ((0x00003800&(data))>>11)
#define TC_MUX_get_Cc2_det20(data)                                                   ((0x00003800&(data))>>11)
#define TC_MUX_EN_CC1_RP4P7K_shift                                                   (10)
#define TC_MUX_EN_CC1_RP4P7K_mask                                                    (0x00000400)
#define TC_MUX_EN_CC1_RP4P7K(data)                                                   (0x00000400&((data)<<10))
#define TC_MUX_EN_CC1_RP4P7K_src(data)                                               ((0x00000400&(data))>>10)
#define TC_MUX_get_EN_CC1_RP4P7K(data)                                               ((0x00000400&(data))>>10)
#define TC_MUX_EN_CC1_RP36K_shift                                                    (9)
#define TC_MUX_EN_CC1_RP36K_mask                                                     (0x00000200)
#define TC_MUX_EN_CC1_RP36K(data)                                                    (0x00000200&((data)<<9))
#define TC_MUX_EN_CC1_RP36K_src(data)                                                ((0x00000200&(data))>>9)
#define TC_MUX_get_EN_CC1_RP36K(data)                                                ((0x00000200&(data))>>9)
#define TC_MUX_EN_CC1_RP12K_shift                                                    (8)
#define TC_MUX_EN_CC1_RP12K_mask                                                     (0x00000100)
#define TC_MUX_EN_CC1_RP12K(data)                                                    (0x00000100&((data)<<8))
#define TC_MUX_EN_CC1_RP12K_src(data)                                                ((0x00000100&(data))>>8)
#define TC_MUX_get_EN_CC1_RP12K(data)                                                ((0x00000100&(data))>>8)
#define TC_MUX_EN_CC1_RD_shift                                                       (7)
#define TC_MUX_EN_CC1_RD_mask                                                        (0x00000080)
#define TC_MUX_EN_CC1_RD(data)                                                       (0x00000080&((data)<<7))
#define TC_MUX_EN_CC1_RD_src(data)                                                   ((0x00000080&(data))>>7)
#define TC_MUX_get_EN_CC1_RD(data)                                                   ((0x00000080&(data))>>7)
#define TC_MUX_EN_CC1_DET_shift                                                      (6)
#define TC_MUX_EN_CC1_DET_mask                                                       (0x00000040)
#define TC_MUX_EN_CC1_DET(data)                                                      (0x00000040&((data)<<6))
#define TC_MUX_EN_CC1_DET_src(data)                                                  ((0x00000040&(data))>>6)
#define TC_MUX_get_EN_CC1_DET(data)                                                  ((0x00000040&(data))>>6)
#define TC_MUX_cc1_det20_shift                                                       (3)
#define TC_MUX_cc1_det20_mask                                                        (0x00000038)
#define TC_MUX_cc1_det20(data)                                                       (0x00000038&((data)<<3))
#define TC_MUX_cc1_det20_src(data)                                                   ((0x00000038&(data))>>3)
#define TC_MUX_get_cc1_det20(data)                                                   ((0x00000038&(data))>>3)
#define TC_MUX_EN_SWITCH_shift                                                       (2)
#define TC_MUX_EN_SWITCH_mask                                                        (0x00000004)
#define TC_MUX_EN_SWITCH(data)                                                       (0x00000004&((data)<<2))
#define TC_MUX_EN_SWITCH_src(data)                                                   ((0x00000004&(data))>>2)
#define TC_MUX_get_EN_SWITCH(data)                                                   ((0x00000004&(data))>>2)
#define TC_MUX_RXIN_SEL_shift                                                        (1)
#define TC_MUX_RXIN_SEL_mask                                                         (0x00000002)
#define TC_MUX_RXIN_SEL(data)                                                        (0x00000002&((data)<<1))
#define TC_MUX_RXIN_SEL_src(data)                                                    ((0x00000002&(data))>>1)
#define TC_MUX_get_RXIN_SEL(data)                                                    ((0x00000002&(data))>>1)
#define TC_MUX_TXOUT_SEL_shift                                                       (0)
#define TC_MUX_TXOUT_SEL_mask                                                        (0x00000001)
#define TC_MUX_TXOUT_SEL(data)                                                       (0x00000001&((data)<<0))
#define TC_MUX_TXOUT_SEL_src(data)                                                   ((0x00000001&(data))>>0)
#define TC_MUX_get_TXOUT_SEL(data)                                                   ((0x00000001&(data))>>0)


#define TC_CCDET                                                                     0x1805A148
#define TC_CCDET_reg_addr                                                            "0xB805A148"
#define TC_CCDET_reg                                                                 0xB805A148
#define set_TC_CCDET_reg(data)   (*((volatile unsigned int*) TC_CCDET_reg)=data)
#define get_TC_CCDET_reg   (*((volatile unsigned int*) TC_CCDET_reg))
#define TC_CCDET_inst_adr                                                            "0x0052"
#define TC_CCDET_inst                                                                0x0052
#define TC_CCDET_CC2_flag_shift                                                      (31)
#define TC_CCDET_CC2_flag_mask                                                       (0x80000000)
#define TC_CCDET_CC2_flag(data)                                                      (0x80000000&((data)<<31))
#define TC_CCDET_CC2_flag_src(data)                                                  ((0x80000000&(data))>>31)
#define TC_CCDET_get_CC2_flag(data)                                                  ((0x80000000&(data))>>31)
#define TC_CCDET_CC1_flag_shift                                                      (30)
#define TC_CCDET_CC1_flag_mask                                                       (0x40000000)
#define TC_CCDET_CC1_flag(data)                                                      (0x40000000&((data)<<30))
#define TC_CCDET_CC1_flag_src(data)                                                  ((0x40000000&(data))>>30)
#define TC_CCDET_get_CC1_flag(data)                                                  ((0x40000000&(data))>>30)
#define TC_CCDET_CC2_debounce_cnt_shift                                              (26)
#define TC_CCDET_CC2_debounce_cnt_mask                                               (0x3C000000)
#define TC_CCDET_CC2_debounce_cnt(data)                                              (0x3C000000&((data)<<26))
#define TC_CCDET_CC2_debounce_cnt_src(data)                                          ((0x3C000000&(data))>>26)
#define TC_CCDET_get_CC2_debounce_cnt(data)                                          ((0x3C000000&(data))>>26)
#define TC_CCDET_CC2_debounce_scale_shift                                            (23)
#define TC_CCDET_CC2_debounce_scale_mask                                             (0x03800000)
#define TC_CCDET_CC2_debounce_scale(data)                                            (0x03800000&((data)<<23))
#define TC_CCDET_CC2_debounce_scale_src(data)                                        ((0x03800000&(data))>>23)
#define TC_CCDET_get_CC2_debounce_scale(data)                                        ((0x03800000&(data))>>23)
#define TC_CCDET_CC1_debounce_cnt_shift                                              (19)
#define TC_CCDET_CC1_debounce_cnt_mask                                               (0x00780000)
#define TC_CCDET_CC1_debounce_cnt(data)                                              (0x00780000&((data)<<19))
#define TC_CCDET_CC1_debounce_cnt_src(data)                                          ((0x00780000&(data))>>19)
#define TC_CCDET_get_CC1_debounce_cnt(data)                                          ((0x00780000&(data))>>19)
#define TC_CCDET_CC1_debounce_scale_shift                                            (16)
#define TC_CCDET_CC1_debounce_scale_mask                                             (0x00070000)
#define TC_CCDET_CC1_debounce_scale(data)                                            (0x00070000&((data)<<16))
#define TC_CCDET_CC1_debounce_scale_src(data)                                        ((0x00070000&(data))>>16)
#define TC_CCDET_get_CC1_debounce_scale(data)                                        ((0x00070000&(data))>>16)
#define TC_CCDET_CC_debounce_en_shift                                                (15)
#define TC_CCDET_CC_debounce_en_mask                                                 (0x00008000)
#define TC_CCDET_CC_debounce_en(data)                                                (0x00008000&((data)<<15))
#define TC_CCDET_CC_debounce_en_src(data)                                            ((0x00008000&(data))>>15)
#define TC_CCDET_get_CC_debounce_en(data)                                            ((0x00008000&(data))>>15)
#define TC_CCDET_CC2_force_val_shift                                                 (12)
#define TC_CCDET_CC2_force_val_mask                                                  (0x00007000)
#define TC_CCDET_CC2_force_val(data)                                                 (0x00007000&((data)<<12))
#define TC_CCDET_CC2_force_val_src(data)                                             ((0x00007000&(data))>>12)
#define TC_CCDET_get_CC2_force_val(data)                                             ((0x00007000&(data))>>12)
#define TC_CCDET_CC2_force_en_shift                                                  (11)
#define TC_CCDET_CC2_force_en_mask                                                   (0x00000800)
#define TC_CCDET_CC2_force_en(data)                                                  (0x00000800&((data)<<11))
#define TC_CCDET_CC2_force_en_src(data)                                              ((0x00000800&(data))>>11)
#define TC_CCDET_get_CC2_force_en(data)                                              ((0x00000800&(data))>>11)
#define TC_CCDET_CC1_force_val_shift                                                 (8)
#define TC_CCDET_CC1_force_val_mask                                                  (0x00000700)
#define TC_CCDET_CC1_force_val(data)                                                 (0x00000700&((data)<<8))
#define TC_CCDET_CC1_force_val_src(data)                                             ((0x00000700&(data))>>8)
#define TC_CCDET_get_CC1_force_val(data)                                             ((0x00000700&(data))>>8)
#define TC_CCDET_CC1_force_en_shift                                                  (7)
#define TC_CCDET_CC1_force_en_mask                                                   (0x00000080)
#define TC_CCDET_CC1_force_en(data)                                                  (0x00000080&((data)<<7))
#define TC_CCDET_CC1_force_en_src(data)                                              ((0x00000080&(data))>>7)
#define TC_CCDET_get_CC1_force_en(data)                                              ((0x00000080&(data))>>7)
#define TC_CCDET_CC_det_irq_en_shift                                                 (6)
#define TC_CCDET_CC_det_irq_en_mask                                                  (0x00000040)
#define TC_CCDET_CC_det_irq_en(data)                                                 (0x00000040&((data)<<6))
#define TC_CCDET_CC_det_irq_en_src(data)                                             ((0x00000040&(data))>>6)
#define TC_CCDET_get_CC_det_irq_en(data)                                             ((0x00000040&(data))>>6)
#define TC_CCDET_CC2_det_de_val_shift                                                (3)
#define TC_CCDET_CC2_det_de_val_mask                                                 (0x00000038)
#define TC_CCDET_CC2_det_de_val(data)                                                (0x00000038&((data)<<3))
#define TC_CCDET_CC2_det_de_val_src(data)                                            ((0x00000038&(data))>>3)
#define TC_CCDET_get_CC2_det_de_val(data)                                            ((0x00000038&(data))>>3)
#define TC_CCDET_CC1_det_de_val_shift                                                (0)
#define TC_CCDET_CC1_det_de_val_mask                                                 (0x00000007)
#define TC_CCDET_CC1_det_de_val(data)                                                (0x00000007&((data)<<0))
#define TC_CCDET_CC1_det_de_val_src(data)                                            ((0x00000007&(data))>>0)
#define TC_CCDET_get_CC1_det_de_val(data)                                            ((0x00000007&(data))>>0)


#define LTSSM_REG                                                                    0x1805A14C
#define LTSSM_REG_reg_addr                                                           "0xB805A14C"
#define LTSSM_REG_reg                                                                0xB805A14C
#define set_LTSSM_REG_reg(data)   (*((volatile unsigned int*) LTSSM_REG_reg)=data)
#define get_LTSSM_REG_reg   (*((volatile unsigned int*) LTSSM_REG_reg))
#define LTSSM_REG_inst_adr                                                           "0x0053"
#define LTSSM_REG_inst                                                               0x0053
#define LTSSM_REG_u2_p3_suspend_shift                                                (31)
#define LTSSM_REG_u2_p3_suspend_mask                                                 (0x80000000)
#define LTSSM_REG_u2_p3_suspend(data)                                                (0x80000000&((data)<<31))
#define LTSSM_REG_u2_p3_suspend_src(data)                                            ((0x80000000&(data))>>31)
#define LTSSM_REG_get_u2_p3_suspend(data)                                            ((0x80000000&(data))>>31)
#define LTSSM_REG_u2_p2_suspend_shift                                                (30)
#define LTSSM_REG_u2_p2_suspend_mask                                                 (0x40000000)
#define LTSSM_REG_u2_p2_suspend(data)                                                (0x40000000&((data)<<30))
#define LTSSM_REG_u2_p2_suspend_src(data)                                            ((0x40000000&(data))>>30)
#define LTSSM_REG_get_u2_p2_suspend(data)                                            ((0x40000000&(data))>>30)
#define LTSSM_REG_u2_p1_suspend_shift                                                (29)
#define LTSSM_REG_u2_p1_suspend_mask                                                 (0x20000000)
#define LTSSM_REG_u2_p1_suspend(data)                                                (0x20000000&((data)<<29))
#define LTSSM_REG_u2_p1_suspend_src(data)                                            ((0x20000000&(data))>>29)
#define LTSSM_REG_get_u2_p1_suspend(data)                                            ((0x20000000&(data))>>29)
#define LTSSM_REG_u2_p0_suspend_shift                                                (28)
#define LTSSM_REG_u2_p0_suspend_mask                                                 (0x10000000)
#define LTSSM_REG_u2_p0_suspend(data)                                                (0x10000000&((data)<<28))
#define LTSSM_REG_u2_p0_suspend_src(data)                                            ((0x10000000&(data))>>28)
#define LTSSM_REG_get_u2_p0_suspend(data)                                            ((0x10000000&(data))>>28)
#define LTSSM_REG_u2_p3_portstate_shift                                              (23)
#define LTSSM_REG_u2_p3_portstate_mask                                               (0x0F800000)
#define LTSSM_REG_u2_p3_portstate(data)                                              (0x0F800000&((data)<<23))
#define LTSSM_REG_u2_p3_portstate_src(data)                                          ((0x0F800000&(data))>>23)
#define LTSSM_REG_get_u2_p3_portstate(data)                                          ((0x0F800000&(data))>>23)
#define LTSSM_REG_u2_p2_portstate_shift                                              (18)
#define LTSSM_REG_u2_p2_portstate_mask                                               (0x007C0000)
#define LTSSM_REG_u2_p2_portstate(data)                                              (0x007C0000&((data)<<18))
#define LTSSM_REG_u2_p2_portstate_src(data)                                          ((0x007C0000&(data))>>18)
#define LTSSM_REG_get_u2_p2_portstate(data)                                          ((0x007C0000&(data))>>18)
#define LTSSM_REG_u2_p1_portstate_shift                                              (13)
#define LTSSM_REG_u2_p1_portstate_mask                                               (0x0003E000)
#define LTSSM_REG_u2_p1_portstate(data)                                              (0x0003E000&((data)<<13))
#define LTSSM_REG_u2_p1_portstate_src(data)                                          ((0x0003E000&(data))>>13)
#define LTSSM_REG_get_u2_p1_portstate(data)                                          ((0x0003E000&(data))>>13)
#define LTSSM_REG_u2_p0_portstate_shift                                              (8)
#define LTSSM_REG_u2_p0_portstate_mask                                               (0x00001F00)
#define LTSSM_REG_u2_p0_portstate(data)                                              (0x00001F00&((data)<<8))
#define LTSSM_REG_u2_p0_portstate_src(data)                                          ((0x00001F00&(data))>>8)
#define LTSSM_REG_get_u2_p0_portstate(data)                                          ((0x00001F00&(data))>>8)
#define LTSSM_REG_usb30_ltdb_link_state_shift                                        (4)
#define LTSSM_REG_usb30_ltdb_link_state_mask                                         (0x000000F0)
#define LTSSM_REG_usb30_ltdb_link_state(data)                                        (0x000000F0&((data)<<4))
#define LTSSM_REG_usb30_ltdb_link_state_src(data)                                    ((0x000000F0&(data))>>4)
#define LTSSM_REG_get_usb30_ltdb_link_state(data)                                    ((0x000000F0&(data))>>4)
#define LTSSM_REG_usb30_ltdb_sub_state_shift                                         (0)
#define LTSSM_REG_usb30_ltdb_sub_state_mask                                          (0x0000000F)
#define LTSSM_REG_usb30_ltdb_sub_state(data)                                         (0x0000000F&((data)<<0))
#define LTSSM_REG_usb30_ltdb_sub_state_src(data)                                     ((0x0000000F&(data))>>0)
#define LTSSM_REG_get_usb30_ltdb_sub_state(data)                                     ((0x0000000F&(data))>>0)


#define USB_TMP_4                                                                    0x1805A150
#define USB_TMP_4_reg_addr                                                           "0xB805A150"
#define USB_TMP_4_reg                                                                0xB805A150
#define set_USB_TMP_4_reg(data)   (*((volatile unsigned int*) USB_TMP_4_reg)=data)
#define get_USB_TMP_4_reg   (*((volatile unsigned int*) USB_TMP_4_reg))
#define USB_TMP_4_inst_adr                                                           "0x0054"
#define USB_TMP_4_inst                                                               0x0054
#define USB_TMP_4_test_reg_4_shift                                                   (0)
#define USB_TMP_4_test_reg_4_mask                                                    (0xFFFFFFFF)
#define USB_TMP_4_test_reg_4(data)                                                   (0xFFFFFFFF&((data)<<0))
#define USB_TMP_4_test_reg_4_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define USB_TMP_4_get_test_reg_4(data)                                               ((0xFFFFFFFF&(data))>>0)


#define CRC_CNT_1                                                                    0x1805A154
#define CRC_CNT_1_reg_addr                                                           "0xB805A154"
#define CRC_CNT_1_reg                                                                0xB805A154
#define set_CRC_CNT_1_reg(data)   (*((volatile unsigned int*) CRC_CNT_1_reg)=data)
#define get_CRC_CNT_1_reg   (*((volatile unsigned int*) CRC_CNT_1_reg))
#define CRC_CNT_1_inst_adr                                                           "0x0055"
#define CRC_CNT_1_inst                                                               0x0055
#define CRC_CNT_1_Crc_err_cnt_shift                                                  (5)
#define CRC_CNT_1_Crc_err_cnt_mask                                                   (0x1FFFFFE0)
#define CRC_CNT_1_Crc_err_cnt(data)                                                  (0x1FFFFFE0&((data)<<5))
#define CRC_CNT_1_Crc_err_cnt_src(data)                                              ((0x1FFFFFE0&(data))>>5)
#define CRC_CNT_1_get_Crc_err_cnt(data)                                              ((0x1FFFFFE0&(data))>>5)
#define CRC_CNT_1_Crc_cnt_sel_shift                                                  (2)
#define CRC_CNT_1_Crc_cnt_sel_mask                                                   (0x0000001C)
#define CRC_CNT_1_Crc_cnt_sel(data)                                                  (0x0000001C&((data)<<2))
#define CRC_CNT_1_Crc_cnt_sel_src(data)                                              ((0x0000001C&(data))>>2)
#define CRC_CNT_1_get_Crc_cnt_sel(data)                                              ((0x0000001C&(data))>>2)
#define CRC_CNT_1_Crc_cnt_rst_shift                                                  (1)
#define CRC_CNT_1_Crc_cnt_rst_mask                                                   (0x00000002)
#define CRC_CNT_1_Crc_cnt_rst(data)                                                  (0x00000002&((data)<<1))
#define CRC_CNT_1_Crc_cnt_rst_src(data)                                              ((0x00000002&(data))>>1)
#define CRC_CNT_1_get_Crc_cnt_rst(data)                                              ((0x00000002&(data))>>1)
#define CRC_CNT_1_Crc_cnt_en_shift                                                   (0)
#define CRC_CNT_1_Crc_cnt_en_mask                                                    (0x00000001)
#define CRC_CNT_1_Crc_cnt_en(data)                                                   (0x00000001&((data)<<0))
#define CRC_CNT_1_Crc_cnt_en_src(data)                                               ((0x00000001&(data))>>0)
#define CRC_CNT_1_get_Crc_cnt_en(data)                                               ((0x00000001&(data))>>0)


#define CRC_CNT_2                                                                    0x1805A158
#define CRC_CNT_2_reg_addr                                                           "0xB805A158"
#define CRC_CNT_2_reg                                                                0xB805A158
#define set_CRC_CNT_2_reg(data)   (*((volatile unsigned int*) CRC_CNT_2_reg)=data)
#define get_CRC_CNT_2_reg   (*((volatile unsigned int*) CRC_CNT_2_reg))
#define CRC_CNT_2_inst_adr                                                           "0x0056"
#define CRC_CNT_2_inst                                                               0x0056
#define CRC_CNT_2_Package_cnt_shift                                                  (0)
#define CRC_CNT_2_Package_cnt_mask                                                   (0xFFFFFFFF)
#define CRC_CNT_2_Package_cnt(data)                                                  (0xFFFFFFFF&((data)<<0))
#define CRC_CNT_2_Package_cnt_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define CRC_CNT_2_get_Package_cnt(data)                                              ((0xFFFFFFFF&(data))>>0)


#define USB_STATE_INDICATE                                                           0x1805A15C
#define USB_STATE_INDICATE_reg_addr                                                  "0xB805A15C"
#define USB_STATE_INDICATE_reg                                                       0xB805A15C
#define set_USB_STATE_INDICATE_reg(data)   (*((volatile unsigned int*) USB_STATE_INDICATE_reg)=data)
#define get_USB_STATE_INDICATE_reg   (*((volatile unsigned int*) USB_STATE_INDICATE_reg))
#define USB_STATE_INDICATE_inst_adr                                                  "0x0057"
#define USB_STATE_INDICATE_inst                                                      0x0057
#define USB_STATE_INDICATE_Usb2_p3disconindic_shift                                  (29)
#define USB_STATE_INDICATE_Usb2_p3disconindic_mask                                   (0x20000000)
#define USB_STATE_INDICATE_Usb2_p3disconindic(data)                                  (0x20000000&((data)<<29))
#define USB_STATE_INDICATE_Usb2_p3disconindic_src(data)                              ((0x20000000&(data))>>29)
#define USB_STATE_INDICATE_get_Usb2_p3disconindic(data)                              ((0x20000000&(data))>>29)
#define USB_STATE_INDICATE_Usb2_p3chripindic_shift                                   (28)
#define USB_STATE_INDICATE_Usb2_p3chripindic_mask                                    (0x10000000)
#define USB_STATE_INDICATE_Usb2_p3chripindic(data)                                   (0x10000000&((data)<<28))
#define USB_STATE_INDICATE_Usb2_p3chripindic_src(data)                               ((0x10000000&(data))>>28)
#define USB_STATE_INDICATE_get_Usb2_p3chripindic(data)                               ((0x10000000&(data))>>28)
#define USB_STATE_INDICATE_Usb2_p3resetindic_shift                                   (27)
#define USB_STATE_INDICATE_Usb2_p3resetindic_mask                                    (0x08000000)
#define USB_STATE_INDICATE_Usb2_p3resetindic(data)                                   (0x08000000&((data)<<27))
#define USB_STATE_INDICATE_Usb2_p3resetindic_src(data)                               ((0x08000000&(data))>>27)
#define USB_STATE_INDICATE_get_Usb2_p3resetindic(data)                               ((0x08000000&(data))>>27)
#define USB_STATE_INDICATE_Usb2_p3resumeindic_shift                                  (26)
#define USB_STATE_INDICATE_Usb2_p3resumeindic_mask                                   (0x04000000)
#define USB_STATE_INDICATE_Usb2_p3resumeindic(data)                                  (0x04000000&((data)<<26))
#define USB_STATE_INDICATE_Usb2_p3resumeindic_src(data)                              ((0x04000000&(data))>>26)
#define USB_STATE_INDICATE_get_Usb2_p3resumeindic(data)                              ((0x04000000&(data))>>26)
#define USB_STATE_INDICATE_Usb2_p3suspendindic_shift                                 (25)
#define USB_STATE_INDICATE_Usb2_p3suspendindic_mask                                  (0x02000000)
#define USB_STATE_INDICATE_Usb2_p3suspendindic(data)                                 (0x02000000&((data)<<25))
#define USB_STATE_INDICATE_Usb2_p3suspendindic_src(data)                             ((0x02000000&(data))>>25)
#define USB_STATE_INDICATE_get_Usb2_p3suspendindic(data)                             ((0x02000000&(data))>>25)
#define USB_STATE_INDICATE_Usb2_p2disconindic_shift                                  (24)
#define USB_STATE_INDICATE_Usb2_p2disconindic_mask                                   (0x01000000)
#define USB_STATE_INDICATE_Usb2_p2disconindic(data)                                  (0x01000000&((data)<<24))
#define USB_STATE_INDICATE_Usb2_p2disconindic_src(data)                              ((0x01000000&(data))>>24)
#define USB_STATE_INDICATE_get_Usb2_p2disconindic(data)                              ((0x01000000&(data))>>24)
#define USB_STATE_INDICATE_Usb2_p2chripindic_shift                                   (23)
#define USB_STATE_INDICATE_Usb2_p2chripindic_mask                                    (0x00800000)
#define USB_STATE_INDICATE_Usb2_p2chripindic(data)                                   (0x00800000&((data)<<23))
#define USB_STATE_INDICATE_Usb2_p2chripindic_src(data)                               ((0x00800000&(data))>>23)
#define USB_STATE_INDICATE_get_Usb2_p2chripindic(data)                               ((0x00800000&(data))>>23)
#define USB_STATE_INDICATE_Usb2_p2resetindic_shift                                   (22)
#define USB_STATE_INDICATE_Usb2_p2resetindic_mask                                    (0x00400000)
#define USB_STATE_INDICATE_Usb2_p2resetindic(data)                                   (0x00400000&((data)<<22))
#define USB_STATE_INDICATE_Usb2_p2resetindic_src(data)                               ((0x00400000&(data))>>22)
#define USB_STATE_INDICATE_get_Usb2_p2resetindic(data)                               ((0x00400000&(data))>>22)
#define USB_STATE_INDICATE_Usb2_p2resumeindic_shift                                  (21)
#define USB_STATE_INDICATE_Usb2_p2resumeindic_mask                                   (0x00200000)
#define USB_STATE_INDICATE_Usb2_p2resumeindic(data)                                  (0x00200000&((data)<<21))
#define USB_STATE_INDICATE_Usb2_p2resumeindic_src(data)                              ((0x00200000&(data))>>21)
#define USB_STATE_INDICATE_get_Usb2_p2resumeindic(data)                              ((0x00200000&(data))>>21)
#define USB_STATE_INDICATE_Usb2_p2suspendindic_shift                                 (20)
#define USB_STATE_INDICATE_Usb2_p2suspendindic_mask                                  (0x00100000)
#define USB_STATE_INDICATE_Usb2_p2suspendindic(data)                                 (0x00100000&((data)<<20))
#define USB_STATE_INDICATE_Usb2_p2suspendindic_src(data)                             ((0x00100000&(data))>>20)
#define USB_STATE_INDICATE_get_Usb2_p2suspendindic(data)                             ((0x00100000&(data))>>20)
#define USB_STATE_INDICATE_Usb2_p1disconindic_shift                                  (19)
#define USB_STATE_INDICATE_Usb2_p1disconindic_mask                                   (0x00080000)
#define USB_STATE_INDICATE_Usb2_p1disconindic(data)                                  (0x00080000&((data)<<19))
#define USB_STATE_INDICATE_Usb2_p1disconindic_src(data)                              ((0x00080000&(data))>>19)
#define USB_STATE_INDICATE_get_Usb2_p1disconindic(data)                              ((0x00080000&(data))>>19)
#define USB_STATE_INDICATE_Usb2_p1chripindic_shift                                   (18)
#define USB_STATE_INDICATE_Usb2_p1chripindic_mask                                    (0x00040000)
#define USB_STATE_INDICATE_Usb2_p1chripindic(data)                                   (0x00040000&((data)<<18))
#define USB_STATE_INDICATE_Usb2_p1chripindic_src(data)                               ((0x00040000&(data))>>18)
#define USB_STATE_INDICATE_get_Usb2_p1chripindic(data)                               ((0x00040000&(data))>>18)
#define USB_STATE_INDICATE_Usb2_p1resetindic_shift                                   (17)
#define USB_STATE_INDICATE_Usb2_p1resetindic_mask                                    (0x00020000)
#define USB_STATE_INDICATE_Usb2_p1resetindic(data)                                   (0x00020000&((data)<<17))
#define USB_STATE_INDICATE_Usb2_p1resetindic_src(data)                               ((0x00020000&(data))>>17)
#define USB_STATE_INDICATE_get_Usb2_p1resetindic(data)                               ((0x00020000&(data))>>17)
#define USB_STATE_INDICATE_Usb2_p1resumeindic_shift                                  (16)
#define USB_STATE_INDICATE_Usb2_p1resumeindic_mask                                   (0x00010000)
#define USB_STATE_INDICATE_Usb2_p1resumeindic(data)                                  (0x00010000&((data)<<16))
#define USB_STATE_INDICATE_Usb2_p1resumeindic_src(data)                              ((0x00010000&(data))>>16)
#define USB_STATE_INDICATE_get_Usb2_p1resumeindic(data)                              ((0x00010000&(data))>>16)
#define USB_STATE_INDICATE_Usb2_p1suspendindic_shift                                 (15)
#define USB_STATE_INDICATE_Usb2_p1suspendindic_mask                                  (0x00008000)
#define USB_STATE_INDICATE_Usb2_p1suspendindic(data)                                 (0x00008000&((data)<<15))
#define USB_STATE_INDICATE_Usb2_p1suspendindic_src(data)                             ((0x00008000&(data))>>15)
#define USB_STATE_INDICATE_get_Usb2_p1suspendindic(data)                             ((0x00008000&(data))>>15)
#define USB_STATE_INDICATE_Usb2_p0disconindic_shift                                  (14)
#define USB_STATE_INDICATE_Usb2_p0disconindic_mask                                   (0x00004000)
#define USB_STATE_INDICATE_Usb2_p0disconindic(data)                                  (0x00004000&((data)<<14))
#define USB_STATE_INDICATE_Usb2_p0disconindic_src(data)                              ((0x00004000&(data))>>14)
#define USB_STATE_INDICATE_get_Usb2_p0disconindic(data)                              ((0x00004000&(data))>>14)
#define USB_STATE_INDICATE_Usb2_p0chripindic_shift                                   (13)
#define USB_STATE_INDICATE_Usb2_p0chripindic_mask                                    (0x00002000)
#define USB_STATE_INDICATE_Usb2_p0chripindic(data)                                   (0x00002000&((data)<<13))
#define USB_STATE_INDICATE_Usb2_p0chripindic_src(data)                               ((0x00002000&(data))>>13)
#define USB_STATE_INDICATE_get_Usb2_p0chripindic(data)                               ((0x00002000&(data))>>13)
#define USB_STATE_INDICATE_Usb2_p0resetindic_shift                                   (12)
#define USB_STATE_INDICATE_Usb2_p0resetindic_mask                                    (0x00001000)
#define USB_STATE_INDICATE_Usb2_p0resetindic(data)                                   (0x00001000&((data)<<12))
#define USB_STATE_INDICATE_Usb2_p0resetindic_src(data)                               ((0x00001000&(data))>>12)
#define USB_STATE_INDICATE_get_Usb2_p0resetindic(data)                               ((0x00001000&(data))>>12)
#define USB_STATE_INDICATE_Usb2_p0resumeindic_shift                                  (11)
#define USB_STATE_INDICATE_Usb2_p0resumeindic_mask                                   (0x00000800)
#define USB_STATE_INDICATE_Usb2_p0resumeindic(data)                                  (0x00000800&((data)<<11))
#define USB_STATE_INDICATE_Usb2_p0resumeindic_src(data)                              ((0x00000800&(data))>>11)
#define USB_STATE_INDICATE_get_Usb2_p0resumeindic(data)                              ((0x00000800&(data))>>11)
#define USB_STATE_INDICATE_Usb2_p0suspendindic_shift                                 (10)
#define USB_STATE_INDICATE_Usb2_p0suspendindic_mask                                  (0x00000400)
#define USB_STATE_INDICATE_Usb2_p0suspendindic(data)                                 (0x00000400&((data)<<10))
#define USB_STATE_INDICATE_Usb2_p0suspendindic_src(data)                             ((0x00000400&(data))>>10)
#define USB_STATE_INDICATE_get_Usb2_p0suspendindic(data)                             ((0x00000400&(data))>>10)
#define USB_STATE_INDICATE_usb3_ltssm_rdet_indic_shift                               (9)
#define USB_STATE_INDICATE_usb3_ltssm_rdet_indic_mask                                (0x00000200)
#define USB_STATE_INDICATE_usb3_ltssm_rdet_indic(data)                               (0x00000200&((data)<<9))
#define USB_STATE_INDICATE_usb3_ltssm_rdet_indic_src(data)                           ((0x00000200&(data))>>9)
#define USB_STATE_INDICATE_get_usb3_ltssm_rdet_indic(data)                           ((0x00000200&(data))>>9)
#define USB_STATE_INDICATE_usb3_ltssm_ssinact_indic_shift                            (8)
#define USB_STATE_INDICATE_usb3_ltssm_ssinact_indic_mask                             (0x00000100)
#define USB_STATE_INDICATE_usb3_ltssm_ssinact_indic(data)                            (0x00000100&((data)<<8))
#define USB_STATE_INDICATE_usb3_ltssm_ssinact_indic_src(data)                        ((0x00000100&(data))>>8)
#define USB_STATE_INDICATE_get_usb3_ltssm_ssinact_indic(data)                        ((0x00000100&(data))>>8)
#define USB_STATE_INDICATE_usb3_ltssm_ssdis_indic_shift                              (7)
#define USB_STATE_INDICATE_usb3_ltssm_ssdis_indic_mask                               (0x00000080)
#define USB_STATE_INDICATE_usb3_ltssm_ssdis_indic(data)                              (0x00000080&((data)<<7))
#define USB_STATE_INDICATE_usb3_ltssm_ssdis_indic_src(data)                          ((0x00000080&(data))>>7)
#define USB_STATE_INDICATE_get_usb3_ltssm_ssdis_indic(data)                          ((0x00000080&(data))>>7)
#define USB_STATE_INDICATE_usb3_ltssm_hreset_indic_shift                             (6)
#define USB_STATE_INDICATE_usb3_ltssm_hreset_indic_mask                              (0x00000040)
#define USB_STATE_INDICATE_usb3_ltssm_hreset_indic(data)                             (0x00000040&((data)<<6))
#define USB_STATE_INDICATE_usb3_ltssm_hreset_indic_src(data)                         ((0x00000040&(data))>>6)
#define USB_STATE_INDICATE_get_usb3_ltssm_hreset_indic(data)                         ((0x00000040&(data))>>6)
#define USB_STATE_INDICATE_usb3_ltssm_poll_indic_shift                               (5)
#define USB_STATE_INDICATE_usb3_ltssm_poll_indic_mask                                (0x00000020)
#define USB_STATE_INDICATE_usb3_ltssm_poll_indic(data)                               (0x00000020&((data)<<5))
#define USB_STATE_INDICATE_usb3_ltssm_poll_indic_src(data)                           ((0x00000020&(data))>>5)
#define USB_STATE_INDICATE_get_usb3_ltssm_poll_indic(data)                           ((0x00000020&(data))>>5)
#define USB_STATE_INDICATE_usb3_ltssm_recov_indic_shift                              (4)
#define USB_STATE_INDICATE_usb3_ltssm_recov_indic_mask                               (0x00000010)
#define USB_STATE_INDICATE_usb3_ltssm_recov_indic(data)                              (0x00000010&((data)<<4))
#define USB_STATE_INDICATE_usb3_ltssm_recov_indic_src(data)                          ((0x00000010&(data))>>4)
#define USB_STATE_INDICATE_get_usb3_ltssm_recov_indic(data)                          ((0x00000010&(data))>>4)
#define USB_STATE_INDICATE_usb3_ltssm_u3_indic_shift                                 (3)
#define USB_STATE_INDICATE_usb3_ltssm_u3_indic_mask                                  (0x00000008)
#define USB_STATE_INDICATE_usb3_ltssm_u3_indic(data)                                 (0x00000008&((data)<<3))
#define USB_STATE_INDICATE_usb3_ltssm_u3_indic_src(data)                             ((0x00000008&(data))>>3)
#define USB_STATE_INDICATE_get_usb3_ltssm_u3_indic(data)                             ((0x00000008&(data))>>3)
#define USB_STATE_INDICATE_usb3_ltssm_u2_indic_shift                                 (2)
#define USB_STATE_INDICATE_usb3_ltssm_u2_indic_mask                                  (0x00000004)
#define USB_STATE_INDICATE_usb3_ltssm_u2_indic(data)                                 (0x00000004&((data)<<2))
#define USB_STATE_INDICATE_usb3_ltssm_u2_indic_src(data)                             ((0x00000004&(data))>>2)
#define USB_STATE_INDICATE_get_usb3_ltssm_u2_indic(data)                             ((0x00000004&(data))>>2)
#define USB_STATE_INDICATE_usb3_ltssm_u1_indic_shift                                 (1)
#define USB_STATE_INDICATE_usb3_ltssm_u1_indic_mask                                  (0x00000002)
#define USB_STATE_INDICATE_usb3_ltssm_u1_indic(data)                                 (0x00000002&((data)<<1))
#define USB_STATE_INDICATE_usb3_ltssm_u1_indic_src(data)                             ((0x00000002&(data))>>1)
#define USB_STATE_INDICATE_get_usb3_ltssm_u1_indic(data)                             ((0x00000002&(data))>>1)
#define USB_STATE_INDICATE_usb3_indicator_clear_shift                                (0)
#define USB_STATE_INDICATE_usb3_indicator_clear_mask                                 (0x00000001)
#define USB_STATE_INDICATE_usb3_indicator_clear(data)                                (0x00000001&((data)<<0))
#define USB_STATE_INDICATE_usb3_indicator_clear_src(data)                            ((0x00000001&(data))>>0)
#define USB_STATE_INDICATE_get_usb3_indicator_clear(data)                            ((0x00000001&(data))>>0)


#endif
