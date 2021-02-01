#ifndef __HDMI_REG_H_
#define __HDMI_REG_H_


/**************************************************************************************/
//
//     We never lose our demons, we only learn to live above them.
//
//
//
//      - The Ancient One, Doctor Strange (2016)
//
/**************************************************************************************/




#ifdef __cplusplus
extern "C" {
#endif




#if defined(__QC_VERIFY_COMMON_H__)

#include <hdmi_mac5/rbus/dfe_p0_reg.h>
#include <hdmi_mac5/rbus/hdmi_p0_reg.h>
#include <hdmi_mac5/rbus/hdmi_ex_p2_reg.h>
#include <hdmi_mac5/rbus/hdmi_clkdet_reg.h>
#include <hdmi_mac5/rbus/dfe_hdmi_rx_phy_reg_p0.h>
#include <hdmi_mac5/rbus/dfe_hdmi_rx_phy_reg_p1.h>
#include <hdmi_mac5/rbus/dfe_hdmi_rx_phy_reg_p2.h>
#else
#include <rbus/dfe_p0_reg.h>
#include <rbus/hdmi_p0_reg.h>
#include <rbus/hdmi_ex_p2_reg.h>
#include <rbus/hdmi_clkdet_reg.h>
#include <rbus/dfe_hdmi_rx_phy_reg_p0.h>
#include <rbus/dfe_hdmi_rx_phy_reg_p1.h>
#include <rbus/dfe_hdmi_rx_phy_reg_p2.h>

#endif

typedef unsigned int uint32_t;

#ifndef NULL
#define NULL                      (void *)0
#endif


#define HDMI_DFE0_BASE           (0xb800DE00)
#define HDMI_DFE1_BASE           (0xb800DE50)
#define HDMI_DFE2_BASE           (0xb800DEA0)

#define HDMI_APHY0_BASE           (0xb800DA40)
#define HDMI_APHY1_BASE           (0xb800DB40)
#define HDMI_APHY2_BASE           (0xb800DC30)

#define HDMI_MAC0_BASE           (0xb800D000)
#define HDMI_MAC1_BASE           (0xb803B000)
#define HDMI_MAC2_BASE           (0xb803C000)


struct hdmi_dfe_reg_st {
uint32_t en_l0;
uint32_t init0_l0;
uint32_t init1_l0;
uint32_t dummy1;
uint32_t en_l1;
uint32_t init0_l1;
uint32_t init1_l1;
uint32_t dummy2;
uint32_t en_l2;
uint32_t init0_l2;
uint32_t init1_l2;
uint32_t dummy3;
uint32_t mode;
uint32_t gain;
uint32_t limit0;
uint32_t limit1;
uint32_t limit2;
uint32_t readback;
uint32_t flag;
uint32_t debug;
};

struct hdmi_aphy_reg_st {
uint32_t b1;
uint32_t b2;
uint32_t b3;
uint32_t b4;
uint32_t ck1;
uint32_t ck2;
uint32_t ck3;
uint32_t ck4;
uint32_t g1;
uint32_t g2;
uint32_t g3;
uint32_t g4;
uint32_t r1;
uint32_t r2;
uint32_t r3;
uint32_t r4;
};

struct hdmi_mac_reg_st {
uint32_t tmds_msr0;
uint32_t tmds_msr1;
uint32_t tmds_crcc;
uint32_t tmds_crco0;
uint32_t tmds_crco1;
uint32_t tmds_ctrl;
uint32_t tmds_outctl;
uint32_t tmds_pwdctl;
uint32_t tmds_z0cc;
uint32_t tmds_cps;
uint32_t tmds_udc;
uint32_t tmds_errc;
uint32_t tmds_out_ctrl;
uint32_t tmds_rout;
uint32_t tmds_gout;
uint32_t tmds_bout;
uint32_t tmds_dpc0;
uint32_t tmds_dpc1;
uint32_t tmds_dpc_set0;
uint32_t tmds_dpc_set1;
uint32_t tmds_dpc_set2;
uint32_t tmds_dpc_set3;
uint32_t tmds_det_ctl;
uint32_t tmds_det_sts;
uint32_t video_bit_err_det;
uint32_t video_bit_err_status_b;
uint32_t video_bit_err_status_g;
uint32_t video_bit_err_status_r;
uint32_t terc4_err_det;
uint32_t terc4_err_status_b;
uint32_t terc4_err_status_g;
uint32_t terc4_err_status_r;
uint32_t hdmi_sr;
uint32_t hdmi_gpvs;
uint32_t hdmi_psap;
uint32_t hdmi_psdp;
uint32_t hdmi_scr;
uint32_t hdmi_bchcr;
uint32_t hdmi_avmcr;
uint32_t hdmi_wdcr0;
uint32_t hdmi_dbcr;
uint32_t hdmi_awdsr;
uint32_t hdmi_vwdsr;
uint32_t hdmi_pamicr;
uint32_t hdmi_ptrsv1;
uint32_t hdmi_pvgcr0;
uint32_t hdmi_pvsr0;
uint32_t hdmi_vcr;
uint32_t hdmi_acrcr;
uint32_t hdmi_acrsr0;
uint32_t hdmi_acrsr1;
uint32_t hdmi_acs0;
uint32_t hdmi_acs1;
uint32_t hdmi_intcr;
uint32_t hdmi_alcr;
uint32_t hdmi_aocr;
uint32_t hdmi_bcsr;
uint32_t hdmi_asr0;
uint32_t hdmi_asr1;
uint32_t hdmi_video_format;
uint32_t hdmi_3d_format;
uint32_t hdmi_fvs;
uint32_t hdmi_drm;
uint32_t hdmi_pcmc;
uint32_t audio_sample_rate_change_irq;
uint32_t high_bit_rate_audio_packet;
uint32_t hdmi_afcr;
uint32_t hdmi_afsr;
uint32_t hdmi_magcr0;
uint32_t hdmi_mag_m_final;
uint32_t zcd_ctrl;
uint32_t audio_freqdet;
uint32_t range0_1;
uint32_t range2_3;
uint32_t range4_5;
uint32_t preset_s_code0;
uint32_t preset_s_code1;
uint32_t prbs_r_ctrl;
uint32_t prbs_g_ctrl;
uint32_t prbs_b_ctrl;
uint32_t hdmi_leading_gb_cmp_ctrl;
uint32_t hdmi_leading_gb_cmp_times;
uint32_t hdmi_leading_gb_cmp_cnt;
uint32_t audio_cts_up_bound;
uint32_t audio_cts_low_bound;
uint32_t audio_n_up_bound;
uint32_t audio_n_low_bound;
uint32_t mhl_hdmi_mac_ctrl;
uint32_t mhl_3d_format;
uint32_t mhl_3p0_format0;
uint32_t mhl_3p0_format1;
uint32_t light_sleep;
uint32_t read_margin2;
uint32_t read_margin_enable;
uint32_t read_margin;
uint32_t bist_mode;
uint32_t bist_done;
uint32_t bist_fail;
uint32_t drf_mode;
uint32_t drf_resume;
uint32_t drf_done;
uint32_t drf_pause;
uint32_t drf_fail;
uint32_t phy_fifo_cr0;
uint32_t phy_fifo_cr1;
uint32_t phy_fifo_sr0;
uint32_t phy_fifo_sr1;
uint32_t hdmi_cts_fifo_ctl;
uint32_t ch_cr;
uint32_t ch_sr;
uint32_t hdmi_2p0_cr;
uint32_t scr_cr;
uint32_t cercr;
uint32_t cersr0;
uint32_t cersr1;
uint32_t cersr2;
uint32_t cersr3;
uint32_t cersr4;
uint32_t yuv420_cr;
uint32_t scdc_cr;
uint32_t scdc_pcr;
uint32_t scdc_ap;
uint32_t scdc_dp;
uint32_t acdrclkdetcr;
uint32_t acdrclkdetsr;
uint32_t acdrclk_setting_00;
uint32_t acdrclk_setting_01;
uint32_t acdrclk_setting_02;
uint32_t hdcp_bist;
uint32_t hdcp_cr;
uint32_t hdcp_dkap;
uint32_t hdcp_pcr;
uint32_t hdcp_flag1;
uint32_t hdcp_flag2;
uint32_t hdcp_ap;
uint32_t hdcp_dp;
uint32_t hdcp_2p2_cr;
uint32_t hdcp_2p2_ks0;
uint32_t hdcp_2p2_ks1;
uint32_t hdcp_2p2_ks2;
uint32_t hdcp_2p2_ks3;
uint32_t hdcp_2p2_lc0;
uint32_t hdcp_2p2_lc1;
uint32_t hdcp_2p2_lc2;
uint32_t hdcp_2p2_lc3;
uint32_t hdcp_2p2_riv0;
uint32_t hdcp_2p2_riv1;
uint32_t hdcp_2p2_sr0;
uint32_t hdcp_2p2_sr1;
uint32_t hdcp_msap;
uint32_t hdcp_msdp;

/*
uint32_t hdmi_cmcr;
uint32_t hdmi_mcapr;
uint32_t hdmi_scapr;
uint32_t hdmi_dcapr0;
uint32_t hdmi_pscr;
uint32_t hdmi_afdd;
uint32_t hdmi_ftr;
uint32_t hdmi_fbr;
uint32_t hdmi_icpsncr0;
uint32_t hdmi_pcpsncr0;
uint32_t hdmi_ictpsr0;
uint32_t hdmi_pctpsr0;
uint32_t hdmi_icbpsr0;
uint32_t hdmi_pcbpsr0;
uint32_t hdmi_ntx1024tr0;
uint32_t hdmi_stbpr;
uint32_t hdmi_ncper;
uint32_t hdmi_petr;
uint32_t hdmi_aapnr;
uint32_t hdmi_apdmcr;
uint32_t hdmi_aptmcr0;
uint32_t hdmi_aptmcr1;
uint32_t hdmi_npecr;
uint32_t hdmi_nror;
uint32_t hdmi_ntx1024tr0_threshold;
uint32_t hdmi_apllcr0;
uint32_t hdmi_apllcr1;
uint32_t hdmi_apllcr2;
uint32_t hdmi_apllcr3;
uint32_t hdmi_apll_testm;
uint32_t hdmi_vpllcr0;
uint32_t hdmi_vpllcr1;
uint32_t hdmi_vpllcr2;
uint32_t mn_sclkg_ctrl;
uint32_t mn_sclkg_divs;
uint32_t mdd_cr;
uint32_t mdd_sr;
uint32_t fw_func;
uint32_t port_switch;
*/
};



extern struct hdmi_dfe_reg_st *dfe[];
extern struct hdmi_aphy_reg_st *aphy[];
extern struct hdmi_mac_reg_st *mac[];
extern void lib_hdmi_reg_init(void);






#define DFE_REG_DFE_EN_L0_reg                     (unsigned int)(&dfe[nport]->en_l0   )              // 0xB800DE00 DE50 DEA0 DF00
#define DFE_REG_DFE_INIT0_L0_reg                  (unsigned int)(&dfe[nport]->init0_l0)              // 0xB800DE04 DE54 DEA4 DF04
#define DFE_REG_DFE_INIT1_L0_reg                  (unsigned int)(&dfe[nport]->init1_l0)              // 0xB800DE08 DE58 DEA8 DF08
#define DFE_REG_DFE_EN_L1_reg                     (unsigned int)(&dfe[nport]->en_l1   )              // 0xB800DE10 DE60 DEB0 DF10
#define DFE_REG_DFE_INIT0_L1_reg                  (unsigned int)(&dfe[nport]->init0_l1)              // 0xB800DE14 DE64 DEB4 DF14
#define DFE_REG_DFE_INIT1_L1_reg                  (unsigned int)(&dfe[nport]->init1_l1)              // 0xB800DE18 DE68 DEB8 DF18
#define DFE_REG_DFE_EN_L2_reg                     (unsigned int)(&dfe[nport]->en_l2   )              // 0xB800DE20 DE70 DEC0 DF20
#define DFE_REG_DFE_INIT0_L2_reg                  (unsigned int)(&dfe[nport]->init0_l2)              // 0xB800DE24 DE74 DEC4 DF24
#define DFE_REG_DFE_INIT1_L2_reg                  (unsigned int)(&dfe[nport]->init1_l2)              // 0xB800DE28 DE78 DEC8 DF28
#define DFE_REG_DFE_MODE_reg                      (unsigned int)(&dfe[nport]->mode    )              // 0xB800DE30 DE80 DED0 DF30
#define DFE_REG_DFE_GAIN_reg                      (unsigned int)(&dfe[nport]->gain    )              // 0xB800DE34 DE84 DED4 DF34
#define DFE_REG_DFE_LIMIT0_reg                    (unsigned int)(&dfe[nport]->limit0  )              // 0xB800DE38 DE88 DED8 DF38
#define DFE_REG_DFE_LIMIT1_reg                    (unsigned int)(&dfe[nport]->limit1  )              // 0xB800DE3C DE8C DEDC DF3C
#define DFE_REG_DFE_LIMIT2_reg                    (unsigned int)(&dfe[nport]->limit2  )              // 0xB800DE40 DE90 DEE0 DF40
#define DFE_REG_DFE_READBACK_reg                  (unsigned int)(&dfe[nport]->readback)              // 0xB800DE44 DE94 DEE4 DF44
#define DFE_REG_DFE_FLAG_reg                      (unsigned int)(&dfe[nport]->flag    )              // 0xB800DE48 DE98 DEE8 DF48
#define DFE_REG_DFE_DEBUG_reg                     (unsigned int)(&dfe[nport]->debug   )              // 0xB800DE4C DE9C DEEC DF4C


#define RX_PHY_B1_reg     (unsigned int)(&aphy[nport]->b1)    // 0xb800da40 db40 dc30
#define RX_PHY_B2_reg     (unsigned int)(&aphy[nport]->b2)    // 0xb800da44 db44 dc34
#define RX_PHY_B3_reg     (unsigned int)(&aphy[nport]->b3)    // 0xb800da48 db48 dc38
#define RX_PHY_B4_reg     (unsigned int)(&aphy[nport]->b4)    // 0xb800da4c db4c dc3c
#define RX_PHY_CK1_reg    (unsigned int)(&aphy[nport]->ck1)   // 0xb800da50 db50 dc40
#define RX_PHY_CK2_reg    (unsigned int)(&aphy[nport]->ck2)   // 0xb800da54 db54 dc44
#define RX_PHY_CK3_reg    (unsigned int)(&aphy[nport]->ck3)   // 0xb800da58 db58 dc48
#define RX_PHY_CK4_reg    (unsigned int)(&aphy[nport]->ck4)   // 0xb800da5c db5c dc4c
#define RX_PHY_G1_reg     (unsigned int)(&aphy[nport]->g1)    // 0xb800da60 db60 dc50
#define RX_PHY_G2_reg     (unsigned int)(&aphy[nport]->g2)    // 0xb800da64 db64 dc54
#define RX_PHY_G3_reg     (unsigned int)(&aphy[nport]->g3)    // 0xb800da68 db68 dc58
#define RX_PHY_G4_reg     (unsigned int)(&aphy[nport]->g4)    // 0xb800da6c db6c dc5c
#define RX_PHY_R1_reg     (unsigned int)(&aphy[nport]->r1)    // 0xb800da70 db70 dc60
#define RX_PHY_R2_reg     (unsigned int)(&aphy[nport]->r2)    // 0xb800da74 db74 dc64
#define RX_PHY_R3_reg     (unsigned int)(&aphy[nport]->r3)    // 0xb800da78 db78 dc68
#define RX_PHY_R4_reg     (unsigned int)(&aphy[nport]->r4)    // 0xb800da7c db7c dc6c


#define  HDMI_TMDS_MSR0_reg                        (unsigned int)(&mac[nport]->tmds_msr0                    )      // 0xB800D000
#define  HDMI_TMDS_MSR1_reg                        (unsigned int)(&mac[nport]->tmds_msr1                    )      // 0xB800D004
#define  HDMI_TMDS_CRCC_reg                        (unsigned int)(&mac[nport]->tmds_crcc                    )      // 0xB800D008
#define  HDMI_TMDS_CRCO0_reg                       (unsigned int)(&mac[nport]->tmds_crco0                   )      // 0xB800D00C
#define  HDMI_TMDS_CRCO1_reg                       (unsigned int)(&mac[nport]->tmds_crco1                   )      // 0xB800D010
#define  HDMI_TMDS_CTRL_reg                        (unsigned int)(&mac[nport]->tmds_ctrl                    )      // 0xB800D014
#define  HDMI_TMDS_OUTCTL_reg                      (unsigned int)(&mac[nport]->tmds_outctl                  )      // 0xB800D018
#define  HDMI_TMDS_PWDCTL_reg                      (unsigned int)(&mac[nport]->tmds_pwdctl                  )      // 0xB800D01C
#define  HDMI_TMDS_Z0CC_reg                        (unsigned int)(&mac[nport]->tmds_z0cc                    )      // 0xB800D020
#define  HDMI_TMDS_CPS_reg                         (unsigned int)(&mac[nport]->tmds_cps                     )      // 0xB800D024
#define  HDMI_TMDS_UDC_reg                         (unsigned int)(&mac[nport]->tmds_udc                     )      // 0xB800D028
#define  HDMI_TMDS_ERRC_reg                        (unsigned int)(&mac[nport]->tmds_errc                    )      // 0xB800D02C
#define  HDMI_TMDS_OUT_CTRL_reg                    (unsigned int)(&mac[nport]->tmds_out_ctrl                )      // 0xB800D030
#define  HDMI_TMDS_ROUT_reg                        (unsigned int)(&mac[nport]->tmds_rout                    )      // 0xB800D034
#define  HDMI_TMDS_GOUT_reg                        (unsigned int)(&mac[nport]->tmds_gout                    )      // 0xB800D038
#define  HDMI_TMDS_BOUT_reg                        (unsigned int)(&mac[nport]->tmds_bout                    )      // 0xB800D03C
#define  HDMI_TMDS_DPC0_reg                        (unsigned int)(&mac[nport]->tmds_dpc0                    )      // 0xB800D040
#define  HDMI_TMDS_DPC1_reg                        (unsigned int)(&mac[nport]->tmds_dpc1                    )      // 0xB800D044
#define  HDMI_TMDS_DPC_SET0_reg                    (unsigned int)(&mac[nport]->tmds_dpc_set0                )      // 0xB800D048
#define  HDMI_TMDS_DPC_SET1_reg                    (unsigned int)(&mac[nport]->tmds_dpc_set1                )      // 0xB800D04C
#define  HDMI_TMDS_DPC_SET2_reg                    (unsigned int)(&mac[nport]->tmds_dpc_set2                )      // 0xB800D050
#define  HDMI_TMDS_DPC_SET3_reg                    (unsigned int)(&mac[nport]->tmds_dpc_set3                )      // 0xB800D054
#define  HDMI_TMDS_DET_CTL_reg                     (unsigned int)(&mac[nport]->tmds_det_ctl                 )      // 0xB800D058
#define  HDMI_TMDS_DET_STS_reg                     (unsigned int)(&mac[nport]->tmds_det_sts                 )      // 0xB800D05C
#define  HDMI_VIDEO_BIT_ERR_DET_reg                (unsigned int)(&mac[nport]->video_bit_err_det            )      // 0xB800D060
#define  HDMI_VIDEO_BIT_ERR_STATUS_B_reg           (unsigned int)(&mac[nport]->video_bit_err_status_b       )      // 0xB800D064
#define  HDMI_VIDEO_BIT_ERR_STATUS_G_reg           (unsigned int)(&mac[nport]->video_bit_err_status_g       )      // 0xB800D068
#define  HDMI_VIDEO_BIT_ERR_STATUS_R_reg           (unsigned int)(&mac[nport]->video_bit_err_status_r       )      // 0xB800D06C
#define  HDMI_TERC4_ERR_DET_reg                    (unsigned int)(&mac[nport]->terc4_err_det                )      // 0xB800D070
#define  HDMI_TERC4_ERR_STATUS_B_reg               (unsigned int)(&mac[nport]->terc4_err_status_b           )      // 0xB800D074
#define  HDMI_TERC4_ERR_STATUS_G_reg               (unsigned int)(&mac[nport]->terc4_err_status_g           )      // 0xB800D078
#define  HDMI_TERC4_ERR_STATUS_R_reg               (unsigned int)(&mac[nport]->terc4_err_status_r           )      // 0xB800D07C
#define  HDMI_HDMI_SR_reg                          (unsigned int)(&mac[nport]->hdmi_sr                      )      // 0xB800D080
#define  HDMI_HDMI_GPVS_reg                        (unsigned int)(&mac[nport]->hdmi_gpvs                    )      // 0xB800D084
#define  HDMI_HDMI_PSAP_reg                        (unsigned int)(&mac[nport]->hdmi_psap                    )      // 0xB800D088
#define  HDMI_HDMI_PSDP_reg                        (unsigned int)(&mac[nport]->hdmi_psdp                    )      // 0xB800D08C
#define  HDMI_HDMI_SCR_reg                         (unsigned int)(&mac[nport]->hdmi_scr                     )      // 0xB800D090
#define  HDMI_HDMI_BCHCR_reg                       (unsigned int)(&mac[nport]->hdmi_bchcr                   )      // 0xB800D094
#define  HDMI_HDMI_AVMCR_reg                       (unsigned int)(&mac[nport]->hdmi_avmcr                   )      // 0xB800D098
#define  HDMI_HDMI_WDCR0_reg                       (unsigned int)(&mac[nport]->hdmi_wdcr0                   )      // 0xB800D09C
#define  HDMI_HDMI_DBCR_reg                        (unsigned int)(&mac[nport]->hdmi_dbcr                    )      // 0xB800D0A0
#define  HDMI_HDMI_AWDSR_reg                       (unsigned int)(&mac[nport]->hdmi_awdsr                   )      // 0xB800D0A4
#define  HDMI_HDMI_VWDSR_reg                       (unsigned int)(&mac[nport]->hdmi_vwdsr                   )      // 0xB800D0A8
#define  HDMI_HDMI_PAMICR_reg                      (unsigned int)(&mac[nport]->hdmi_pamicr                  )      // 0xB800D0AC
#define  HDMI_HDMI_PTRSV1_reg                      (unsigned int)(&mac[nport]->hdmi_ptrsv1                  )      // 0xB800D0B0
#define  HDMI_HDMI_PVGCR0_reg                      (unsigned int)(&mac[nport]->hdmi_pvgcr0                  )      // 0xB800D0B4
#define  HDMI_HDMI_PVSR0_reg                       (unsigned int)(&mac[nport]->hdmi_pvsr0                   )      // 0xB800D0B8
#define  HDMI_HDMI_VCR_reg                         (unsigned int)(&mac[nport]->hdmi_vcr                     )      // 0xB800D0BC
#define  HDMI_HDMI_ACRCR_reg                       (unsigned int)(&mac[nport]->hdmi_acrcr                   )      // 0xB800D0C0
#define  HDMI_HDMI_ACRSR0_reg                      (unsigned int)(&mac[nport]->hdmi_acrsr0                  )      // 0xB800D0C4
#define  HDMI_HDMI_ACRSR1_reg                      (unsigned int)(&mac[nport]->hdmi_acrsr1                  )      // 0xB800D0C8
#define  HDMI_HDMI_ACS0_reg                        (unsigned int)(&mac[nport]->hdmi_acs0                    )      // 0xB800D0CC
#define  HDMI_HDMI_ACS1_reg                        (unsigned int)(&mac[nport]->hdmi_acs1                    )      // 0xB800D0D0
#define  HDMI_HDMI_INTCR_reg                       (unsigned int)(&mac[nport]->hdmi_intcr                   )      // 0xB800D0D4
#define  HDMI_HDMI_ALCR_reg                        (unsigned int)(&mac[nport]->hdmi_alcr                    )      // 0xB800D0D8
#define  HDMI_HDMI_AOCR_reg                        (unsigned int)(&mac[nport]->hdmi_aocr                    )      // 0xB800D0DC
#define  HDMI_HDMI_BCSR_reg                        (unsigned int)(&mac[nport]->hdmi_bcsr                    )      // 0xB800D0E0
#define  HDMI_HDMI_ASR0_reg                        (unsigned int)(&mac[nport]->hdmi_asr0                    )      // 0xB800D0E4
#define  HDMI_HDMI_ASR1_reg                        (unsigned int)(&mac[nport]->hdmi_asr1                    )      // 0xB800D0E8
#define  HDMI_HDMI_VIDEO_FORMAT_reg                (unsigned int)(&mac[nport]->hdmi_video_format            )      // 0xB800D0EC
#define  HDMI_HDMI_3D_FORMAT_reg                   (unsigned int)(&mac[nport]->hdmi_3d_format               )      // 0xB800D0F0
#define  HDMI_HDMI_FVS_reg                         (unsigned int)(&mac[nport]->hdmi_fvs                     )      // 0xB800D0F4
#define  HDMI_HDMI_DRM_reg                         (unsigned int)(&mac[nport]->hdmi_drm                     )      // 0xB800D0F8
#define  HDMI_HDMI_PCMC_reg						   (unsigned int)(&mac[nport]->hdmi_pcmc                    )      // 0xB800D0FC
#define  HDMI_Audio_Sample_Rate_Change_IRQ_reg     (unsigned int)(&mac[nport]->audio_sample_rate_change_irq )      // 0xB800D100
#define  HDMI_High_Bit_Rate_Audio_Packet_reg       (unsigned int)(&mac[nport]->high_bit_rate_audio_packet   )      // 0xB800D104
#define  HDMI_HDMI_AFCR_reg                        (unsigned int)(&mac[nport]->hdmi_afcr                    )      // 0xB800D108
#define  HDMI_HDMI_AFSR_reg                        (unsigned int)(&mac[nport]->hdmi_afsr                    )      // 0xB800D10C
#define  HDMI_HDMI_MAGCR0_reg                      (unsigned int)(&mac[nport]->hdmi_magcr0                  )      // 0xB800D110
#define  HDMI_HDMI_MAG_M_FINAL_reg                 (unsigned int)(&mac[nport]->hdmi_mag_m_final             )      // 0xB800D114
#define  HDMI_ZCD_CTRL_reg                         (unsigned int)(&mac[nport]->zcd_ctrl                     )      // 0xB800D118
#define  HDMI_AUDIO_FREQDET_reg                    (unsigned int)(&mac[nport]->audio_freqdet                )      // 0xB800D11C
#define  HDMI_RANGE0_1_reg                         (unsigned int)(&mac[nport]->range0_1                     )      // 0xB800D120
#define  HDMI_RANGE2_3_reg                         (unsigned int)(&mac[nport]->range2_3                     )      // 0xB800D124
#define  HDMI_RANGE4_5_reg                         (unsigned int)(&mac[nport]->range4_5                     )      // 0xB800D128
#define  HDMI_PRESET_S_CODE0_reg                   (unsigned int)(&mac[nport]->preset_s_code0               )      // 0xB800D12C
#define  HDMI_PRESET_S_CODE1_reg                   (unsigned int)(&mac[nport]->preset_s_code1               )      // 0xB800D130
#define  HDMI_PRBS_R_CTRL_reg                      (unsigned int)(&mac[nport]->prbs_r_ctrl                  )      // 0xB800D134
#define  HDMI_PRBS_G_CTRL_reg                      (unsigned int)(&mac[nport]->prbs_g_ctrl                  )      // 0xB800D138
#define  HDMI_PRBS_B_CTRL_reg                      (unsigned int)(&mac[nport]->prbs_b_ctrl                  )      // 0xB800D13C
#define  HDMI_HDMI_leading_GB_cmp_ctrl_reg         (unsigned int)(&mac[nport]->hdmi_leading_gb_cmp_ctrl     )      // 0xB800D140
#define  HDMI_HDMI_leading_GB_cmp_times_reg        (unsigned int)(&mac[nport]->hdmi_leading_gb_cmp_times    )      // 0xB800D144
#define  HDMI_HDMI_leading_GB_cmp_cnt_reg          (unsigned int)(&mac[nport]->hdmi_leading_gb_cmp_cnt      )      // 0xB800D148
#define  HDMI_AUDIO_CTS_UP_BOUND_reg               (unsigned int)(&mac[nport]->audio_cts_up_bound           )      // 0xB800D14C
#define  HDMI_AUDIO_CTS_LOW_BOUND_reg              (unsigned int)(&mac[nport]->audio_cts_low_bound          )      // 0xB800D150
#define  HDMI_AUDIO_N_UP_BOUND_reg                 (unsigned int)(&mac[nport]->audio_n_up_bound             )      // 0xB800D154
#define  HDMI_AUDIO_N_LOW_BOUND_reg                (unsigned int)(&mac[nport]->audio_n_low_bound            )      // 0xB800D158
#define  HDMI_MHL_HDMI_MAC_CTRL_reg                (unsigned int)(&mac[nport]->mhl_hdmi_mac_ctrl            )      // 0xB800D15C
#define  HDMI_MHL_3D_FORMAT_reg                    (unsigned int)(&mac[nport]->mhl_3d_format                )      // 0xB800D160
#define  HDMI_MHL_3p0_FORMAT0_reg                  (unsigned int)(&mac[nport]->mhl_3p0_format0              )      // 0xB800D164
#define  HDMI_MHL_3p0_FORMAT1_reg                  (unsigned int)(&mac[nport]->mhl_3p0_format1              )      // 0xB800D168
#define  HDMI_LIGHT_SLEEP_reg                      (unsigned int)(&mac[nport]->light_sleep                  )      // 0xB800D16C
#define  HDMI_READ_MARGIN2_reg                     (unsigned int)(&mac[nport]->read_margin2                 )      // 0xB800D170
#define  HDMI_READ_MARGIN_ENABLE_reg               (unsigned int)(&mac[nport]->read_margin_enable           )      // 0xB800D174
#define  HDMI_READ_MARGIN_reg                      (unsigned int)(&mac[nport]->read_margin                  )      // 0xB800D178
#define  HDMI_BIST_MODE_reg                        (unsigned int)(&mac[nport]->bist_mode                    )      // 0xB800D17C
#define  HDMI_BIST_DONE_reg                        (unsigned int)(&mac[nport]->bist_done                    )      // 0xB800D180
#define  HDMI_BIST_FAIL_reg                        (unsigned int)(&mac[nport]->bist_fail                    )      // 0xB800D184
#define  HDMI_DRF_MODE_reg                         (unsigned int)(&mac[nport]->drf_mode                     )      // 0xB800D188
#define  HDMI_DRF_RESUME_reg                       (unsigned int)(&mac[nport]->drf_resume                   )      // 0xB800D18C
#define  HDMI_DRF_DONE_reg                         (unsigned int)(&mac[nport]->drf_done                     )      // 0xB800D190
#define  HDMI_DRF_PAUSE_reg                        (unsigned int)(&mac[nport]->drf_pause                    )      // 0xB800D194
#define  HDMI_DRF_FAIL_reg                         (unsigned int)(&mac[nport]->drf_fail                     )      // 0xB800D198
#define  HDMI_PHY_FIFO_CR0_reg                     (unsigned int)(&mac[nport]->phy_fifo_cr0                 )      // 0xB800D19C
#define  HDMI_PHY_FIFO_CR1_reg                     (unsigned int)(&mac[nport]->phy_fifo_cr1                 )      // 0xB800D1A0
#define  HDMI_PHY_FIFO_SR0_reg                     (unsigned int)(&mac[nport]->phy_fifo_sr0                 )      // 0xB800D1A4
#define  HDMI_PHY_FIFO_SR1_reg                     (unsigned int)(&mac[nport]->phy_fifo_sr1                 )      // 0xB800D1A8
#define  HDMI_HDMI_CTS_FIFO_CTL_reg                (unsigned int)(&mac[nport]->hdmi_cts_fifo_ctl            )      // 0xB800D1AC
#define  HDMI_CH_CR_reg                            (unsigned int)(&mac[nport]->ch_cr                        )      // 0xB800D1B0
#define  HDMI_CH_SR_reg                            (unsigned int)(&mac[nport]->ch_sr                        )      // 0xB800D1B4
#define  HDMI_HDMI_2p0_CR_reg                      (unsigned int)(&mac[nport]->hdmi_2p0_cr                  )      // 0xB800D1B8
#define  HDMI_SCR_CR_reg                           (unsigned int)(&mac[nport]->scr_cr                       )      // 0xB800D1BC
#define  HDMI_CERCR_reg                            (unsigned int)(&mac[nport]->cercr                        )      // 0xB800D1C0
#define  HDMI_CERSR0_reg                           (unsigned int)(&mac[nport]->cersr0                       )      // 0xB800D1C4
#define  HDMI_CERSR1_reg                           (unsigned int)(&mac[nport]->cersr1                       )      // 0xB800D1C8
#define  HDMI_CERSR2_reg                           (unsigned int)(&mac[nport]->cersr2                       )      // 0xB800D1CC
#define  HDMI_CERSR3_reg                           (unsigned int)(&mac[nport]->cersr3                       )      // 0xB800D1D0
#define  HDMI_CERSR4_reg                           (unsigned int)(&mac[nport]->cersr4                       )      // 0xB800D1D4
#define  HDMI_YUV420_CR_reg                        (unsigned int)(&mac[nport]->yuv420_cr                    )      // 0xB800D1D8
#define  HDMI_SCDC_CR_reg                          (unsigned int)(&mac[nport]->scdc_cr                      )      // 0xB800D1DC
#define  HDMI_SCDC_PCR_reg                         (unsigned int)(&mac[nport]->scdc_pcr                     )      // 0xB800D1E0
#define  HDMI_SCDC_AP_reg                          (unsigned int)(&mac[nport]->scdc_ap                      )      // 0xB800D1E4
#define  HDMI_SCDC_DP_reg                          (unsigned int)(&mac[nport]->scdc_dp                      )      // 0xB800D1E8
#define  HDMI_ACDRCLKDETCR_reg                     (unsigned int)(&mac[nport]->acdrclkdetcr                 )      // 0xB800D1EC
#define  HDMI_ACDRCLKDETSR_reg                     (unsigned int)(&mac[nport]->acdrclkdetsr                 )      // 0xB800D1F0
#define  HDMI_ACDRCLK_SETTING_00_reg               (unsigned int)(&mac[nport]->acdrclk_setting_00           )      // 0xB800D1F4
#define  HDMI_ACDRCLK_SETTING_01_reg               (unsigned int)(&mac[nport]->acdrclk_setting_01           )      // 0xB800D1F8
#define  HDMI_ACDRCLK_SETTING_02_reg               (unsigned int)(&mac[nport]->acdrclk_setting_02           )      // 0xB800D1FC
#define  HDMI_HDCP_CR_reg                          (unsigned int)(&mac[nport]->hdcp_cr                      )      // 0xB800D204
#define  HDMI_HDCP_DKAP_reg                        (unsigned int)(&mac[nport]->hdcp_dkap                    )      // 0xB800D208
#define  HDMI_HDCP_PCR_reg                         (unsigned int)(&mac[nport]->hdcp_pcr                     )      // 0xB800D20C
#define  HDMI_HDCP_FLAG1_reg                       (unsigned int)(&mac[nport]->hdcp_flag1                   )      // 0xB800D210
#define  HDMI_HDCP_FLAG2_reg                       (unsigned int)(&mac[nport]->hdcp_flag2                   )      // 0xB800D214
#define  HDMI_HDCP_AP_reg                          (unsigned int)(&mac[nport]->hdcp_ap                      )      // 0xB800D218
#define  HDMI_HDCP_DP_reg                          (unsigned int)(&mac[nport]->hdcp_dp                      )      // 0xB800D21C

#define  HDMI_HDCP_2p2_CR_reg                              (unsigned int)(&mac[nport]->hdcp_2p2_cr   )                     // 0xB800D220
#define  HDMI_HDCP_2p2_ks0_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_ks0  )                     // 0xB800D224
#define  HDMI_HDCP_2p2_ks1_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_ks1  )                     // 0xB800D228
#define  HDMI_HDCP_2p2_ks2_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_ks2  )                     // 0xB800D22C
#define  HDMI_HDCP_2p2_ks3_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_ks3  )                     // 0xB800D230
#define  HDMI_HDCP_2p2_lc0_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_lc0  )                     // 0xB800D234
#define  HDMI_HDCP_2p2_lc1_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_lc1  )                     // 0xB800D238
#define  HDMI_HDCP_2p2_lc2_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_lc2  )                     // 0xB800D23C
#define  HDMI_HDCP_2p2_lc3_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_lc3  )                     // 0xB800D240
#define  HDMI_HDCP_2p2_riv0_reg                            (unsigned int)(&mac[nport]->hdcp_2p2_riv0 )                     // 0xB800D244
#define  HDMI_HDCP_2p2_riv1_reg                            (unsigned int)(&mac[nport]->hdcp_2p2_riv1 )                     // 0xB800D248
#define  HDMI_HDCP_2p2_SR0_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_sr0  )                     // 0xB800D24C
#define  HDMI_HDCP_2p2_SR1_reg                             (unsigned int)(&mac[nport]->hdcp_2p2_sr1  )                     // 0xB800D250
#define  HDMI_HDCP_MSAP_reg                                (unsigned int)(&mac[nport]->hdcp_msap     )                     // 0xB800D254
#define  HDMI_HDCP_MSDP_reg                                (unsigned int)(&mac[nport]->hdcp_msdp     )                     // 0xB800D258



#define  HDMI_HDMI_CMCR_reg                                HDMI_P0_PORT0_HDMI_CMCR_reg
#define  HDMI_HDMI_MCAPR_reg                               HDMI_P0_PORT0_HDMI_MCAPR_reg
#define  HDMI_HDMI_SCAPR_reg                               HDMI_P0_PORT0_HDMI_SCAPR_reg
#define  HDMI_HDMI_DCAPR0_reg                              HDMI_P0_PORT0_HDMI_DCAPR0_reg
#define  HDMI_HDMI_PSCR_reg                                HDMI_P0_PORT0_HDMI_PSCR_reg
#define  HDMI_HDMI_AFDD_reg                                HDMI_P0_PORT0_HDMI_AFDD_reg
#define  HDMI_HDMI_FTR_reg                                 HDMI_P0_PORT0_HDMI_FTR_reg
#define  HDMI_HDMI_FBR_reg                                 HDMI_P0_PORT0_HDMI_FBR_reg
#define  HDMI_HDMI_ICPSNCR0_reg                            HDMI_P0_PORT0_HDMI_ICPSNCR0_reg
#define  HDMI_HDMI_PCPSNCR0_reg                            HDMI_P0_PORT0_HDMI_PCPSNCR0_reg
#define  HDMI_HDMI_ICTPSR0_reg                             HDMI_P0_PORT0_HDMI_ICTPSR0_reg
#define  HDMI_HDMI_PCTPSR0_reg                             HDMI_P0_PORT0_HDMI_PCTPSR0_reg
#define  HDMI_HDMI_ICBPSR0_reg                             HDMI_P0_PORT0_HDMI_ICBPSR0_reg
#define  HDMI_HDMI_PCBPSR0_reg                             HDMI_P0_PORT0_HDMI_PCBPSR0_reg
#define  HDMI_HDMI_NTx1024TR0_reg                          HDMI_P0_PORT0_HDMI_NTx1024TR0_reg
#define  HDMI_HDMI_STBPR_reg                               HDMI_P0_PORT0_HDMI_STBPR_reg
#define  HDMI_HDMI_NCPER_reg                               HDMI_P0_PORT0_HDMI_NCPER_reg
#define  HDMI_HDMI_PETR_reg                                HDMI_P0_PORT0_HDMI_PETR_reg
#define  HDMI_HDMI_AAPNR_reg                               HDMI_P0_PORT0_HDMI_AAPNR_reg
#define  HDMI_HDMI_APDMCR_reg                              HDMI_P0_PORT0_HDMI_APDMCR_reg
#define  HDMI_HDMI_APTMCR0_reg                             HDMI_P0_PORT0_HDMI_APTMCR0_reg
#define  HDMI_HDMI_APTMCR1_reg                             HDMI_P0_PORT0_HDMI_APTMCR1_reg
#define  HDMI_HDMI_NPECR_reg                               HDMI_P0_PORT0_HDMI_NPECR_reg
#define  HDMI_HDMI_NROR_reg                                HDMI_P0_PORT0_HDMI_NROR_reg
#define  HDMI_HDMI_NTx1024TR0_Threshold_reg                HDMI_P0_PORT0_HDMI_NTx1024TR0_Threshold_reg
#define  HDMI_HDMI_APLLCR0_reg                             HDMI_P0_PORT0_HDMI_APLLCR0_reg
#define  HDMI_HDMI_APLLCR1_reg                             HDMI_P0_PORT0_HDMI_APLLCR1_reg
#define  HDMI_HDMI_APLLCR2_reg                             HDMI_P0_PORT0_HDMI_APLLCR2_reg
#define  HDMI_HDMI_APLLCR3_reg                             HDMI_P0_PORT0_HDMI_APLLCR3_reg
#define  HDMI_HDMI_APLL_TESTM_reg                          HDMI_P0_PORT0_HDMI_APLL_TESTM_reg

#define  HDMI_HDMI_VPLLCR0_reg                             HDMI_P0_PORT0_HDMI_VPLLCR0_reg
#define  HDMI_HDMI_VPLLCR1_reg                             HDMI_P0_PORT0_HDMI_VPLLCR1_reg
#define  HDMI_HDMI_VPLLCR2_reg                             HDMI_P0_PORT0_HDMI_VPLLCR2_reg
#define  HDMI_MN_SCLKG_CTRL_reg                            HDMI_P0_PORT0_MN_SCLKG_CTRL_reg
#define  HDMI_MN_SCLKG_DIVS_reg                            HDMI_P0_PORT0_MN_SCLKG_DIVS_reg
#define  HDMI_MDD_CR_reg                                   HDMI_P0_PORT0_MDD_CR_reg
#define  HDMI_MDD_SR_reg                                   HDMI_P0_PORT0_MDD_SR_reg
#define  HDMI_FW_FUNC_reg                                  HDMI_P0_PORT0_FW_FUNC_reg
#define  HDMI_PORT_SWITCH_reg                              HDMI_P0_PORT0_PORT_SWITCH_reg









#define HDMI_APLLCR1_dpll_CS_MASK                                        ((1<<18)|(1<<17))
#define HDMI_APLLCR1_dpll_CS_20P                                          (0)
#define HDMI_APLLCR1_dpll_CS_25P                                          (1<<17)
#define HDMI_APLLCR1_dpll_CS_30P                                          (2<<17)
#define HDMI_APLLCR1_dpll_CS_35P                                          (3<<17)


#define LOAD_IN_INIT_LE		(_BIT31)
#define LOAD_IN_INIT_VTH	(_BIT30)
#define LOAD_IN_INIT_SERVO	(_BIT29)
#define LOAD_IN_INIT_TAP4	(_BIT28)
#define LOAD_IN_INIT_TAP3	(_BIT27)
#define LOAD_IN_INIT_TAP2	(_BIT26)
#define LOAD_IN_INIT_TAP1	(_BIT25)
#define LOAD_IN_INIT_TAP0	(_BIT24)
#define LOAD_IN_INIT_ALL	(LOAD_IN_INIT_LE|LOAD_IN_INIT_VTH|LOAD_IN_INIT_SERVO|LOAD_IN_INIT_TAP4|LOAD_IN_INIT_TAP3|LOAD_IN_INIT_TAP2|LOAD_IN_INIT_TAP1|LOAD_IN_INIT_TAP0)


#define REG_dfe_adapt_en_lane0_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane0_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane0_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane0_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane0_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane0_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane0_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane0_LE                                              _BIT23
#define REG_dfe_adapt_en_lane1_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane1_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane1_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane1_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane1_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane1_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane1_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane1_LE                                              _BIT23
#define REG_dfe_adapt_en_lane2_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane2_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane2_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane2_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane2_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane2_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane2_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane2_LE                                              _BIT23


#define LIMIT_TAP0_MAX				0
#define LIMIT_TAP0_MIN				1
#define LIMIT_TAP1_MAX				2
#define LIMIT_TAP1_MIN				3
#define LIMIT_LE_MAX				4
#define LIMIT_LE_MIN				5

#define COEF_VTH				0
#define COEF_TAP0				1
#define COEF_TAP1				2
#define COEF_TAP2				3
#define COEF_TAP3				4
#define COEF_TAP4				5
#define COEF_SERVO				6
#define COEF_LE					7


//#define limit_set_lane_mask					(_BIT30|_BIT29)
//#define limit_set_lane_shift					(29)
//#define limit_set_mask						(_BIT28|_BIT27|_BIT26|_BIT25|_BIT24)
//#define limit_sel(data)  						(limit_set_mask&((data)<<24))
//#define get_Tap0_max(data)                          	((0x7F0000&(data))>>16)
//#define get_Tap0_min(data)                          	((0x7F0000&(data))>>16)
//#define get_Tap1_max(data)                          	((0x3F0000&(data))>>16)
//#define get_Tap1_min(data)                          	((0x3F0000&(data))>>16)
//#define get_LEQ_max(data)                          	((0x1F0000&(data))>>16)
//#define get_LEQ_min(data)                          	((0x1F0000&(data))>>16)
//#define coef_set_lane_mask					(_BIT15|_BIT14)
//#define coef_set_lane_shift					(14)
//#define coef_set_mask						(_BIT13|_BIT12|_BIT11|_BIT10|_BIT9|_BIT8)
//#define coef_sel(data)                               		(coef_set_mask&((data)<<8))
//#define get_VTH_coef(data)                          	(0xF&(data))
//#define get_TAP0_coef(data)                          	(0x1F&(data))
//#define get_TAP1_coef(data)                          	(0x3F&(data))
#define get_TAP2_coef_sign(data)                   	(0x20&(data))
#define get_TAP2_coef(data)                          	(0x1F&(data))
//#define get_TAP3_coef_sign(data)                    	(0x20&(data))
//#define get_TAP3_coef(data)                          	(0x1F&(data))
//#define get_TAP4_coef_sign(data)                     (0x20&(data))
//#define get_TAP4_coef(data)                          	(0x1F&(data))
//#define get_SERVO_coef(data)                          	(0x1F&(data))
//#define get_LE1_coef(data)                          	(0x1F&(data))
//#define get_CurrentStep_coef(data) 			((0x30&(data))>>4)
//#define get_BufferMode_coef(data) 			((0xc0&(data))>>6)





#define TOP_IN_REG_IBHN_TUNE		(_BIT21|_BIT20)
#define TOP_IN_CK_TX_3			(_BIT3)
#define TOP_IN_CK_TX_2			(_BIT2)
#define TOP_IN_CK_TX_1			(_BIT1)
#define TOP_IN_CK_TX_0			(_BIT0)



#define  p0_REG_ACDR_CPCVM_EN                     (_BIT26)
#define  p0_REG_ACDR_VCO_TUNER                   (_BIT23|_BIT22)
#define  p0_REG_ACDR_VCOGAIN                       (_BIT21|_BIT20)
#define  p0_REG_ACDR_LFRS_SEL                      (_BIT15|_BIT14|_BIT13)
#define  p0_REG_ACDR_CKFLD_EN                     (_BIT5)
#define  p0_REG_ACDR_HR_PD	                   (_BIT4)
#define  p0_REG_ACDR_EN                                 (_BIT1)
#define  p0_REG_ACDR_TOP_EN                         (_BIT0)




/*************************************************B lane start************************************************/

#define  P0_b_4_FORE_KOFF_AUTOK                                                                    (_BIT28)
#define  P0_b_CLK_PIX2_RATE_SEL						(_BIT26)
#define  P0_b_DEMUX_BBPD_RSTB                                                                       (_BIT25)
#define  P0_b_4_FORE_POW_FORE_KOFF                                                                  (_BIT24)
#define  P0_b_3_FORE_EN_FORE_KOFF                                                                    (_BIT23)
#define  P0_b_1_FORE_KOFF_RANGE                                                                    (_BIT22|_BIT21)
#define  P0_b_1_inputoff_p				       		(_BIT2)
#define  P0_b_1_inputoff_n				       		(_BIT1)
#define  P0_b_1_inputoff                                                                      		(_BIT0)

#define  P0_b_8_DEMUX                                                                                             (_BIT29|_BIT30|_BIT31)
#define  P0_b_8_PR_RATE_SEL                                                                                    (_BIT26|_BIT27|_BIT28)
#define  P0_b_8_POW_PR                                                                                            _BIT25
#define  P0_b_8_BY_PASS_PR                                                                                      _BIT24
//#define  P0_b_7_TAP0_ISEL                                                                                         (_BIT21|_BIT22|_BIT23)
//#define  P0_b_7_TAP0_ISEL_400uA                                                                              (_BIT22|_BIT23)
#define  P0_b_7_LEQ_ISEL                                                                                           (_BIT18)
#define  P0_b_7_LEQ_ISEL_200uA                                                                                (_BIT18)
#define  P0_b_7_LEQ_ISEL_100uA                                                                                (0)
#define  P0_b_7_PI_ISEL                                                                                              (_BIT16|_BIT17)



#define  P0_b_6_TAP0_HBR                                                                              	        (_BIT13)


//#define  P0_b_6_LEQ_PASSIVE_CORNER                                                                      (_BIT12|_BIT11)
#define  P0_b_6_TAP0_LE_ISO							(_BIT8)



#define  P0_b_5_DA_LANE_ISEL												(_BIT7|_BIT6|_BIT5)
#define  P0_b_5_DA_LANE_ISEL_100uA                                                                                (_BIT6| _BIT5)

#define  P0_b_5_LEQ_CURRENT_ADJ                                                                            (_BIT3|_BIT4)
#define  P0_b_5_LEQ_CURRENT_ADJ_1X                                                                            (_BIT3)
#define  P0_b_5_LEQ_CURRENT_ADJ_1p25X                                                                       (_BIT4)


#define  P0_b_5_TAP0_CURRENT_ADJ                                                                            (_BIT2)
#define  P0_b_5_TAP0_CURRENT_ADJ_1X                                                                            (0)
#define  P0_b_5_TAP0_CURRENT_ADJ_1p25X                                                                       (_BIT2)


#define  P0_b_5_EQ_POW                                                                                             (_BIT0)
#define DFE_HDMI_RX_PHY_P0_DFE_PI_ISEL(data)										(0x00030000&((data)<<16))




#define P0_b_12_PI_CURRENT														(_BIT28)
#define P0_b_12_PI_CSEL 														 (_BIT24|_BIT25)
#define P0_b_9_DFE_ADAPTION_POW_EN 								              (_BIT7)
#define P0_b_9_DFE_TAP_EN 								                           (_BIT3|_BIT4|_BIT5|_BIT6)
#define P0_b_9_DFE_TAP1_EN 								                           (_BIT3)
#define DFE_HDMI_RX_PHY_P0_DFE_PI_CSEL(data)										(0x03000000&((data)<<24))
#define DFE_HDMI_RX_PHY_P0_DFE_ADAPTION_EN(data)							(0x00000080&((data)<<7))
#define DFE_HDMI_RX_PHY_P0_b_tap_en(data)								(0x00000078&((data)<<3))
#define P0_b_11_ACDR_RATE_SEL_HALF_RATE 								 (_BIT16)
#define P0_b_10_DFE_SUMAMP_LP_MANUALOFF								 (_BIT15)
#define P0_b_10_DFE_SUMAMP_ISEL_mask 								              (_BIT11|_BIT12|_BIT13)
#define P0_b_10_DFE_SUMAMP_ISEL_400uA 								              (_BIT13)
#define P0_b_10_DFE_PREAMP_ISEL_mask 								                    (_BIT8|_BIT9|_BIT10)
#define P0_b_10_DFE_PREAMP_ISEL_400uA 								                    (_BIT10)
/*************************************************B lane end************************************************/



/*************************************************CK lane start************************************************/


#define  p0_ck_3_CMU_PREDIVN                                                                          (_BIT20|_BIT21|_BIT22|_BIT23)
#define  p0_ck_3_CMU_N_code                                                                          (_BIT18|_BIT19)
#define  p0_ck_3_CMU_SEL_D4						(_BIT16)
#define  p0_ck_2_CMU_CKIN_SEL                                                                   (_BIT15)
#define p0_ck2_2_ACDR_CBUS_REF									(_BIT14|_BIT13)
#define p0_ck2_2_MD_HYSTERESIS_SEL								(_BIT12)
#define  p0_CMU_CKOUT_SEL                                                                             (_BIT11)
#define  p0_ck_2_CMU_CKAFE_ENHANCE_BIAS							  (_BIT10)
#define  p0_ck_2_CK_MD_REF_SEL                                                                  (_BIT9)
#define  p0_CK_2_CKD2S_EN0						(_BIT8)
#define  p0_ck_1_port_bias                                                                              (_BIT2)
#define  p0_ck_1_CKAFE_POW                                                                          (_BIT1)
#define  DFE_HDMI_RX_PHY_P0_get_CMU_SEL_D4(data)                        ((0x00010000&(data))>>16)


#define P0_ck_8_LDO_EN                                                                                  (_BIT25)
#define  P0_ck_8_VSEL_LDO_A_mask                                                                   (_BIT29|_BIT30|_BIT31)
#define  P0_ck_8_CCO_BAND_SEL_mask                                                                   (_BIT26|_BIT27|_BIT28)
#define  P0_ck_8_LDO_EN_mask                                                                          (_BIT25)
									
#define  P0_ck_8_CMU_BPPSR_mask                                                                          (_BIT24)
#define P0_ck_8_CMU_SEL_CP_mask										   (_BIT20|_BIT21)
#define  P0_ck_7_CMU_BYPASS_PI_mask                                                              (_BIT19)
#define  P0_ck_7_CMU_PI_I_SEL_mask                                                                 (_BIT16|_BIT17|_BIT18)
#define  P0_ck_6_CMU_BIG_KVCO_mask                                                                 (_BIT13)
#define  P0_ck_6_CMU_EN_CAP_mask                                                                     (_BIT12)
#define  P0_ck_6_CMU_SEL_CS_mask                                                                     (_BIT8|_BIT9|_BIT10)
#define  P0_ck_5_CMU_SEL_PUMP_I_mask                                                               (_BIT4|_BIT5|_BIT6|_BIT7)
#define  P0_ck_5_CMU_SEL_PUMP_DB_mask				(_BIT3)
#define  P0_ck_5_CMU_SEL_R1_mask                                                                       (_BIT0|_BIT1|_BIT2)

#define  DFE_HDMI_RX_PHY_P0_VSEL_LDO(data)                            (0xe0000000&((data)<<29))
#define  DFE_HDMI_RX_PHY_P0_CCO_BAND_SEL(data)                            (0x1C000000&((data)<<26))
#define  DFE_HDMI_RX_PHY_P0_LDO_EN(data)                            (0x02000000&((data)<<25))
#define  DFE_HDMI_RX_PHY_P0_CMU_BPPSR(data)                            (0x01000000&((data)<<24))
#define  DFE_HDMI_RX_PHY_P0_CMU_EN_CAP(data)				    (0x00001000&((data) << 12))
#define  DFE_HDMI_RX_PHY_P0_CMU_SEL_CS(data)                            (0x00000700&((data)<<8))
#define  DFE_HDMI_RX_PHY_P0_CMU_SEL_PUMP_I(data)                            (0x000000F0&((data)<<4))
#define  DFE_HDMI_RX_PHY_P0_CMU_SEL_R1(data)                            (0x00000007&((data)<<0))
#define  DFE_HDMI_RX_PHY_P0_get_CMU_BPPSR(data)                        ((0x01000000&(data))>>24)


#define  P0_ck_9_CMU_PFD_RSTB                                                                          (_BIT5)
#define  P0_ck_9_CMU_WDRST                                                                          (_BIT2)

/*************************************************CK lane end************************************************/



/*************************************************G lane start************************************************/

#define  P0_g_4_FORE_KOFF_AUTOK                                                                    (_BIT28)
#define  P0_g_CLK_PIX2_RATE_SEL						(_BIT26)
#define  P0_g_DEMUX_BBPD_RSTB                                                                       (_BIT25)
#define  P0_g_4_FORE_POW_FORE_KOFF                                                                  (_BIT24)
#define  P0_g_3_FORE_EN_FORE_KOFF                                                                    (_BIT23)
#define  P0_g_1_FORE_KOFF_RANGE                                                                    (_BIT22|_BIT21)
#define  P0_g_1_inputoff_p				       		(_BIT2)
#define  P0_g_1_inputoff_n				       		(_BIT1)
#define  P0_g_1_inputoff                                                                      		(_BIT0)

#define  P0_g_8_POW_PR                                                                                   (_BIT25)
#define  P0_g_8_EQ_POW                                                                                   (_BIT0)

#define  P0_g_8_DEMUX                                                                                             (_BIT29|_BIT30|_BIT31)
#define  P0_g_8_PR_RATE_SEL                                                                                    (_BIT26|_BIT27|_BIT28)
#define  P0_g_8_POW_PR                                                                                            (_BIT25)
#define  P0_g_8_BY_PASS_PR                                                                                      (_BIT24)
//#define  P0_g_7_TAP0_ISEL                                                                                         (_BIT21|_BIT22|_BIT23)
//#define  P0_g_7_TAP0_ISEL_400uA                                                                              (_BIT22|_BIT23)
#define  P0_g_7_LEQ_ISEL                                                                                           (_BIT18)
#define  P0_g_7_LEQ_ISEL_200uA                                                                                (_BIT18)
#define  P0_g_7_LEQ_ISEL_100uA                                                                                (0)
#define  P0_g_7_PI_ISEL                                                                                              (_BIT16|_BIT17)


#define  P0_g_6_TAP0_HBR                                                                              	        (_BIT13)






//#define  P0_g_6_LEQ_PASSIVE_CORNER                                                                      (_BIT12|_BIT11)

#define  P0_g_5_DA_LANE_ISEL												(_BIT7|_BIT6|_BIT5)
#define  P0_g_5_DA_LANE_ISEL_100uA                                                                                (_BIT6| _BIT5)


#define  P0_g_5_LEQ_CURRENT_ADJ                                                                            (_BIT3|_BIT4)
#define  P0_g_5_LEQ_CURRENT_ADJ_1X                                                                            (_BIT3)
#define  P0_g_5_LEQ_CURRENT_ADJ_1p25X                                                                       (_BIT4)


#define  P0_g_5_TAP0_CURRENT_ADJ                                                                            (_BIT2)
#define  P0_g_5_TAP0_CURRENT_ADJ_1X                                                                            (0)
#define  P0_g_5_TAP0_CURRENT_ADJ_1p25X                                                                       (_BIT2)

#define  P0_g_5_EQ_POW                                                                                             (_BIT0)



#define P0_g_12_PI_CURRENT														(_BIT28)
#define P0_g_12_PI_CSEL 														 (_BIT24|_BIT25)
#define P0_g_9_DFE_ADAPTION_POW_EN 						              (_BIT7)
#define P0_g_9_DFE_TAP_EN 						                           (_BIT3|_BIT4|_BIT5|_BIT6)
#define P0_g_9_DFE_TAP1_EN 						                           (_BIT3)
#define  DFE_HDMI_RX_PHY_P0_g_tap_en(data)                                                           (0x00000078&((data)<<3))
#define P0_g_11_ACDR_RATE_SEL_HALF_RATE 								 (_BIT16)
#define P0_g_10_DFE_SUMAMP_LP_MANUALOFF								 (_BIT15)
#define P0_g_10_DFE_SUMAMP_ISEL_mask 								              (_BIT11|_BIT12|_BIT13)
#define P0_g_10_DFE_SUMAMP_ISEL_400uA 								              (_BIT13)
#define P0_g_10_DFE_PREAMP_ISEL_mask 								                    (_BIT8|_BIT9|_BIT10)
#define P0_g_10_DFE_PREAMP_ISEL_400uA 								                    (_BIT10)


/*************************************************G lane end************************************************/


/*************************************************R lane start************************************************/

#define  P0_r_4_FORE_KOFF_AUTOK                                                                    (_BIT28)
#define  P0_r_CLK_PIX2_RATE_SEL						(_BIT26)
#define  P0_r_DEMUX_BBPD_RSTB                                                                       (_BIT25)
#define  P0_r_4_FORE_POW_FORE_KOFF                                                                  (_BIT24)
#define  P0_r_3_FORE_EN_FORE_KOFF                                                                    (_BIT23)
#define  P0_r_1_FORE_KOFF_RANGE                                                                    (_BIT22|_BIT21)
#define  P0_r_1_inputoff                                                                      		(_BIT0)
#define  P0_r_1_inputoff_n				       		(_BIT1)
#define  P0_r_1_inputoff_p				       		(_BIT2)



#define  P0_r_8_DEMUX                                                                                             (_BIT29|_BIT30|_BIT31)
#define  P0_r_8_PR_RATE_SEL                                                                                    (_BIT26|_BIT27|_BIT28)
#define  P0_r_8_POW_PR                                                                                            (_BIT25)
#define  P0_r_8_BY_PASS_PR                                                                                      (_BIT24)
//#define  P0_r_7_TAP0_ISEL                                                                                         (_BIT21|_BIT22|_BIT23)
//#define  P0_r_7_TAP0_ISEL_400uA                                                                              (_BIT22|_BIT23)
#define  P0_r_7_LEQ_ISEL                                                                                           (_BIT18)
#define  P0_r_7_LEQ_ISEL_200uA                                                                                (_BIT18)
#define  P0_r_7_LEQ_ISEL_100uA                                                                                (0)
#define  P0_r_7_PI_ISEL                                                                                              (_BIT16|_BIT17)

#define  P0_r_6_TAP0_HBR                                                                              	        (_BIT13)


//#define  P0_r_6_LEQ_PASSIVE_CORNER                                                                      (_BIT12|_BIT11)



#define  P0_r_5_DA_LANE_ISEL												(_BIT7|_BIT6|_BIT5)
#define  P0_r_5_DA_LANE_ISEL_100uA                                                                                (_BIT6| _BIT5)

#define  P0_r_5_LEQ_CURRENT_ADJ                                                                            (_BIT3|_BIT4)
#define  P0_r_5_LEQ_CURRENT_ADJ_1X                                                                            (_BIT3)
#define  P0_r_5_LEQ_CURRENT_ADJ_1p25X                                                                       (_BIT4)

#define  P0_r_5_TAP0_CURRENT_ADJ                                                                            (_BIT2)
#define  P0_r_5_TAP0_CURRENT_ADJ_1X                                                                            (0)
#define  P0_r_5_TAP0_CURRENT_ADJ_1p25X                                                                       (_BIT2)

#define  P0_r_5_EQ_POW                                                                                             (_BIT0)




#define P0_r_12_PI_CURRENT														(_BIT28)
#define  P0_r_12_PI_CSEL 														      (_BIT24|_BIT25)
#define P0_r_9_DFE_ADAPTION_POW_EN 								              (_BIT7)
#define P0_r_9_DFE_TAP_EN 								                           (_BIT3|_BIT4|_BIT5|_BIT6)
#define P0_r_9_DFE_TAP1_EN 								                           (_BIT3)
#define  DFE_HDMI_RX_PHY_P0_r_tap_en(data)                                                           (0x00000078&((data)<<3))
#define  P0_r_11_ACDR_RATE_SEL 												(_BIT24|_BIT25)
#define P0_r_11_ACDR_RATE_SEL_HALF_RATE 								             (_BIT16)
#define P0_r_10_DFE_SUMAMP_LP_MANUALOFF								 (_BIT15)
#define P0_r_10_DFE_SUMAMP_ISEL_mask 								              (_BIT11|_BIT12|_BIT13)
#define P0_r_10_DFE_SUMAMP_ISEL_400uA 								              (_BIT13)
#define P0_r_10_DFE_PREAMP_ISEL_mask 								                    (_BIT8|_BIT9|_BIT10)
#define P0_r_10_DFE_PREAMP_ISEL_400uA 								                    (_BIT10)


/*************************************************R lane end************************************************/


#define  P0_b_1_FORE_KOFF_ADJR			(_BIT16|_BIT17|_BIT18|_BIT19|_BIT20)
#define  P0_b_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P0_b_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P0_b_2_LEQ_BIT_RATE_LBR			(0)
#define  P1_b_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P1_b_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P1_b_2_LEQ_BIT_RATE_LBR			(0)
#define  P2_b_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P2_b_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P2_b_2_LEQ_BIT_RATE_LBR			(0)


#define  P0_g_1_FORE_KOFF_ADJR			(_BIT16|_BIT17|_BIT18|_BIT19|_BIT20)
#define  P0_g_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P0_g_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P0_g_2_LEQ_BIT_RATE_LBR			(0)
#define  P1_g_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P1_g_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P1_g_2_LEQ_BIT_RATE_LBR			(0)
#define  P2_g_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P2_g_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P2_g_2_LEQ_BIT_RATE_LBR			(0)


#define  P0_r_1_FORE_KOFF_ADJR			(_BIT16|_BIT17|_BIT18|_BIT19|_BIT20)
#define  P0_r_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P0_r_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P0_r_2_LEQ_BIT_RATE_LBR			(0)
#define  P1_r_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P1_r_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P1_r_2_LEQ_BIT_RATE_LBR			(0)
#define  P2_r_2_LEQ_BIT_RATE_mask			(_BIT8|_BIT9)
#define  P2_r_2_LEQ_BIT_RATE_MBR			(_BIT8|_BIT9)
#define  P2_r_2_LEQ_BIT_RATE_LBR			(0)


#define  P1_b_8_BY_PASS_PR                                                                                      (_BIT24)
#define  P1_g_8_BY_PASS_PR                                                                                      (_BIT24)
#define  P1_r_8_BY_PASS_PR                                                                                      (_BIT24)
#define  P2_b_8_BY_PASS_PR                                                                                     (_BIT24)
#define  P2_g_8_BY_PASS_PR                                                                                     (_BIT24)
#define  P2_r_8_BY_PASS_PR                                                                                      (_BIT24)









#ifdef __cplusplus
}
#endif

#endif