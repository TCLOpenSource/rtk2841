/**
* @file rbusVDTopReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VDTOP_REG_H_
#define _RBUS_VDTOP_REG_H_

#include "rbusTypes.h"



//  VDTOP Register Address



#define  VDTOP_VIDEO_CONTROL0_VADDR 		(0xb8019000)
#define  VDTOP_VIDEO_CONTROL1_VADDR 		(0xb8019004)
#define  VDTOP_VIDEO_STATUS_REG1_VADDR 		(0xb8019008)
#define  VDTOP_VIDEO_STATUS_REG2_VADDR 		(0xb801900c)
#define  VDTOP_VIDEO_STATUS_REG3_VADDR 		(0xb8019010)
#define  VDTOP_HDTO_INC_STATUS_VADDR 		(0xb8019014)
#define  VDTOP_CDTO_INC_STATUS_VADDR 		(0xb8019018)
#define  VDTOP_AVG_BURST_MAG_STATUS_VADDR 		(0xb801901c)
#define  VDTOP_AGC_DGAIN_STATUS_VADDR 		(0xb8019020)
#define  VDTOP_CMAG_STATUS_VADDR 		(0xb8019024)
#define  VDTOP_CGAIN_STATUS_VADDR 		(0xb8019028)
#define  VDTOP_CORDIC_FREQ_STATUS_VADDR 		(0xb801902c)
#define  VDTOP_MEASURE_FIRST_V_VADDR 		(0xb8019030)
#define  VDTOP_MEASURE_SECOND_V_VADDR 		(0xb8019034)
#define  VDTOP_PORCH_HEIGHT_M_VADDR 		(0xb8019038)
#define  VDTOP_NOISE_STATUS_VADDR 		(0xb801903c)
#define  VDTOP_NOISE_THRESHOLD_VADDR 		(0xb8019040)
#define  VDTOP_HSYNC_DTO_INC_VADDR 		(0xb8019050)
#define  VDTOP_CHROMA_DTO_INC_VADDR 		(0xb8019054)
#define  VDTOP_CHIP_VER_VADDR 		(0xb8019058)
#define  VDTOP_BLANK_VID_OFFSET_VALUE_VADDR 		(0xb801905c)
#define  VDTOP_LUMA_CONTRAST_ADJ_VADDR 		(0xb8019060)
#define  VDTOP_LUMA_BRIGHTNESS_ADJ_VADDR 		(0xb8019064)
#define  VDTOP_CHROMA_SATURATION_ADJ_VADDR 		(0xb8019068)
#define  VDTOP_CHROMA_HUE_PHASE_ADJ_VADDR 		(0xb801906c)
#define  VDTOP_BLUE_SCREEN_Y_VADDR 		(0xb8019070)
#define  VDTOP_BLUE_SCREEN_CB_VADDR 		(0xb8019074)
#define  VDTOP_BLUE_SCREEN_CR_VADDR 		(0xb8019078)
#define  VDTOP_OUTPUT_CONTROL_VADDR 		(0xb801907c)
#define  VDTOP_INOUT_CTRL_VADDR 		(0xb8019080)
#define  VDTOP_AVOUT_FIFO_STATUS_VADDR 		(0xb8019084)
#define  VDTOP_AVOUT_IFDEBUG_VADDR 		(0xb8019088)
#define  VDTOP_AVOUT1_IFDEBUG_1_VADDR 		(0xb801908c)
#define  VDTOP_AGC_PEAK_NOMINAL_VADDR 		(0xb8019090)
#define  VDTOP_AGC_PEAK_AND_GATE_CTRL_VADDR 		(0xb8019094)
#define  VDTOP_AGC_PEAK_CTRL_VADDR 		(0xb8019098)
#define  VDTOP_VIDEO_CONTROL2_VADDR 		(0xb801909c)
#define  VDTOP_LUMA_AGC_VALUE_VADDR 		(0xb80190a0)
#define  VDTOP_AGC_GATE_START_VADDR 		(0xb80190a4)
#define  VDTOP_AGC_GATE_WIDTH_VADDR 		(0xb80190a8)
#define  VDTOP_AGC_BP_DELAY_VADDR 		(0xb80190ac)
#define  VDTOP_CLAMPAGC_COMPLUMA_NEW_THRESHOLD2_VADDR 		(0xb80190b0)
#define  VDTOP_CLAMPAGC_COMPLUMA_NEW_THRESHOLD1_VADDR 		(0xb80190b4)
#define  VDTOP_CLAMPAGC_COMPLUMA_NEW_CONTROL_VADDR 		(0xb80190b8)
#define  VDTOP_VSYNC_AGC_MIN_VADDR 		(0xb80190bc)
#define  VDTOP_VSYNC_AGC_LOCKOUT_END_VADDR 		(0xb80190c0)
#define  VDTOP_CHARGE_PUMP_DELAY_CONTROL_VADDR 		(0xb80190c4)
#define  VDTOP_CHARGE_PUMP_ADJUSTMENT_VADDR 		(0xb80190c8)
#define  VDTOP_CHARGE_PUMP_DELAY_VADDR 		(0xb80190cc)
#define  VDTOP_AGC_GATE_TH_SWAP_VADDR 		(0xb80190d0)
#define  VDTOP_NEW_CLAMPAGC_CTRL_VADDR 		(0xb80190d4)
#define  VDTOP_MEASURE_DC_ROUGH_DN_VADDR 		(0xb80190d8)
#define  VDTOP_MEASURE_DC_ROUGH_UP_VADDR 		(0xb80190dc)
#define  VDTOP_MEASURE_DC_TH_DN_VADDR 		(0xb80190e0)
#define  VDTOP_MEASURE_DC_TH_UP_VADDR 		(0xb80190e4)
#define  VDTOP_VSAG_CNTL_1_VADDR 		(0xb80190e8)
#define  VDTOP_PEAK_VSAG_VADDR 		(0xb80190ec)
#define  VDTOP_KILL_FIELD_VADDR 		(0xb80190f0)
#define  VDTOP_FIELD_KILL_MUN_VADDR 		(0xb80190f4)
#define  VDTOP_KILL_GATE_UP_VADDR 		(0xb80190f8)
#define  VDTOP_KILL_GATE_DN_VADDR 		(0xb80190fc)
#define  VDTOP_SYNCMIDPT_VADDR 		(0xb8019100)
#define  VDTOP_SYNCMIDPT_FIX_ADD_VALUE_VADDR 		(0xb8019104)
#define  VDTOP_LPFSYNC_VADDR 		(0xb8019108)
#define  VDTOP_SPIKE_MIN_VADDR 		(0xb801910c)
#define  VDTOP_SPIKE_MAX_VADDR 		(0xb8019110)
#define  VDTOP_SPIKE_DETECTED_UP_VADDR 		(0xb8019114)
#define  VDTOP_SPIKE_DETECTED_DN_VADDR 		(0xb8019118)
#define  VDTOP_LPFSYNC_PLUS_DC_VADDR 		(0xb801911c)
#define  VDTOP_HDETECT_ERR_VAR_CTRL_VADDR 		(0xb8019128)
#define  VDTOP_HDETECT_ERR_VAR_STATUS_VADDR 		(0xb801912c)
#define  VDTOP_LOCK_COUNT_VADDR 		(0xb8019130)
#define  VDTOP_H_LOOP_MAXSTATE_VADDR 		(0xb8019134)
#define  VDTOP_CLAMPAGC_CTRL0_VADDR 		(0xb8019138)
#define  VDTOP_CLAMPAGC_NEW_SYNC_START_VADDR 		(0xb801913c)
#define  VDTOP_CLAMPAGC_NEW_SYNC_END_VADDR 		(0xb8019140)
#define  VDTOP_CLAMPAGC_NEW_BACKPORCH_START_VADDR 		(0xb8019144)
#define  VDTOP_CLAMPAGC_NEW_BACKPORCH_END_VADDR 		(0xb8019148)
#define  VDTOP_HDETECT_PHASE_SEL_VADDR 		(0xb801914c)
#define  VDTOP_HDETECT_COUNTER_TIP_START_VADDR 		(0xb8019150)
#define  VDTOP_HDETECT_COUNTER_TIP_END_VADDR 		(0xb8019154)
#define  VDTOP_HDETECT_COUNTER_BACKPORCH_START_VADDR 		(0xb8019158)
#define  VDTOP_HDETECT_COUNTER_BACKPORCH_END_VADDR 		(0xb801915c)
#define  VDTOP_HPLL_INTEGRAL_CTRL_VADDR 		(0xb8019160)
#define  VDTOP_HDETECT_LOOPFILTER_SW_VADDR 		(0xb8019164)
#define  VDTOP_HDETECT_LOOPFILTER_DCTRL_VADDR 		(0xb8019168)
#define  VDTOP_HSYNC_PULSE_START_VADDR 		(0xb801916c)
#define  VDTOP_HSYNC_PULSE_WIDTH_VADDR 		(0xb8019170)
#define  VDTOP_CHROMA_HRESAMPLER_CONTROL_VADDR 		(0xb8019174)
#define  VDTOP_HPLL_KP_0_VADDR 		(0xb8019178)
#define  VDTOP_HPLL_KP_1_VADDR 		(0xb801917c)
#define  VDTOP_HPLL_KP_2_VADDR 		(0xb8019180)
#define  VDTOP_HPLL_KP_3_VADDR 		(0xb8019184)
#define  VDTOP_HPLL_KP_4_VADDR 		(0xb8019188)
#define  VDTOP_HPLL_KP_5_VADDR 		(0xb801918c)
#define  VDTOP_HPLL_KI_0_VADDR 		(0xb8019190)
#define  VDTOP_HPLL_KI_1_VADDR 		(0xb8019194)
#define  VDTOP_HPLL_KI_2_VADDR 		(0xb8019198)
#define  VDTOP_HPLL_KI_3_VADDR 		(0xb801919c)
#define  VDTOP_HPLL_KI_4_VADDR 		(0xb80191a0)
#define  VDTOP_HPLL_KI_5_VADDR 		(0xb80191a4)
#define  VDTOP_SECOND_PLL_GAIN_VADDR 		(0xb80191a8)
#define  VDTOP_SECOND_PLL_GAIN1_VADDR 		(0xb80191ac)
#define  VDTOP_SECOND_PLL_GAIN2_VADDR 		(0xb80191b0)
#define  VDTOP_SECOND_PLL_GAIN3_VADDR 		(0xb80191b4)
#define  VDTOP_SECOND_PLL_GAIN4_VADDR 		(0xb80191b8)
#define  VDTOP_UNDER_NEW_TH1_VADDR 		(0xb80191bc)
#define  VDTOP_UNDER_NEW_TH2_VADDR 		(0xb80191c0)
#define  VDTOP_UNDER_NEW_TH3_VADDR 		(0xb80191c4)
#define  VDTOP_DC_COCH_SEPERATE_1_VADDR 		(0xb80191c8)
#define  VDTOP_DC_COCH_SEPERATE_2_VADDR 		(0xb80191cc)
#define  VDTOP_HSYNC_RISING_VADDR 		(0xb80191d0)
#define  VDTOP_HSYNC_PHASE_OFFSET_VADDR 		(0xb80191d4)
#define  VDTOP_HSYNC_GATE_START_VADDR 		(0xb80191d8)
#define  VDTOP_HSYNC_GATE_END_VADDR 		(0xb80191dc)
#define  VDTOP_HSYNC_TIP_START_VADDR 		(0xb80191e0)
#define  VDTOP_HSYNC_TIP_END_VADDR 		(0xb80191e4)
#define  VDTOP_HSYNC_RISING_START_VADDR 		(0xb80191e8)
#define  VDTOP_HSYNC_RISING_END_VADDR 		(0xb80191ec)
#define  VDTOP_BACKPROCH_START_VADDR 		(0xb80191f0)
#define  VDTOP_BACKPORCH_END_VADDR 		(0xb80191f4)
#define  VDTOP_HBLANK_START_VADDR 		(0xb80191f8)
#define  VDTOP_HBLANK_END_VADDR 		(0xb80191fc)
#define  VDTOP_BURST_GATE_START_VADDR 		(0xb8019200)
#define  VDTOP_BURST_GATE_END_VADDR 		(0xb8019204)
#define  VDTOP_HACTIVE_START_VADDR 		(0xb8019208)
#define  VDTOP_HACTIVE_WIDTH_VADDR 		(0xb801920c)
#define  VDTOP_HDETECT_ERR_TH1_VADDR 		(0xb8019210)
#define  VDTOP_HDETECT_ERR_TH2_VADDR 		(0xb8019214)
#define  VDTOP_CSTATE_STATUS_VADDR 		(0xb8019218)
#define  VDTOP_HDETECT_GATE_CTRL_VADDR 		(0xb801921c)
#define  VDTOP_HDETECT_GATE_COEF1_VADDR 		(0xb8019220)
#define  VDTOP_HDETECT_GATE_COEF2_VADDR 		(0xb8019224)
#define  VDTOP_HDETECT_VPHASE_STATUS_VADDR 		(0xb8019228)
#define  VDTOP_HDETECT_VPHASEDIFF_STATUS_VADDR 		(0xb801922c)
#define  VDTOP_NOISE_VBI_THRESHOLD_VADDR 		(0xb8019230)
#define  VDTOP_VBI_CO_CH_CTRL0_VADDR 		(0xb8019234)
#define  VDTOP_VBI_CO_CH_CTRL1_VADDR 		(0xb8019238)
#define  VDTOP_VBI_CO_CH_CTRL2_VADDR 		(0xb801923c)
#define  VDTOP_MV_DETECT_WINDOW_VADDR 		(0xb8019240)
#define  VDTOP_MV_BURSTGATE_START_VADDR 		(0xb8019244)
#define  VDTOP_MV_BURSTGATE_END_VADDR 		(0xb8019248)
#define  VDTOP_COLOR_INVERSE_CONTROL_VADDR 		(0xb801924c)
#define  VDTOP_H_ERR_CONSTRAINT_1_VADDR 		(0xb8019250)
#define  VDTOP_H_ERR_CONSTRAINT_2_VADDR 		(0xb8019254)
#define  VDTOP_H_RESTORE_HDTO_1_VADDR 		(0xb8019258)
#define  VDTOP_H_RESTORE_HDTO_2_VADDR 		(0xb801925c)
#define  VDTOP_IF_WRONG_PC_VADDR 		(0xb8019260)
#define  VDTOP_CPLL_STABILITY_OBSERVE_1_VADDR 		(0xb8019264)
#define  VDTOP_CPLL_STABILITY_OBSERVE_2_VADDR 		(0xb8019268)
#define  VDTOP_CPLL_STABILITY_OBSERVE_3_VADDR 		(0xb801926c)
#define  VDTOP_HPLL_STABILITY_OBSERVE_1_VADDR 		(0xb8019270)
#define  VDTOP_HPLL_STABILITY_OBSERVE_2_VADDR 		(0xb8019274)
#define  VDTOP_HPLL_STABILITY_OBSERVE_3_VADDR 		(0xb8019278)
#define  VDTOP_H_PHASE_DIFF_STATISTICS_SET_1_VADDR 		(0xb801927c)
#define  VDTOP_H_PHASE_DIFF_STATISTICS_SET_2_VADDR 		(0xb8019280)
#define  VDTOP_H_PHASE_DIFF_STATISTICS_SET_3_VADDR 		(0xb8019284)
#define  VDTOP_H_PHASE_DIFF_STATISTICS_SET_4_VADDR 		(0xb8019288)
#define  VDTOP_H_PHASE_DIFF_STATISTICS_SET_5_VADDR 		(0xb801928c)
#define  VDTOP_H_PHASE_DIFF_SEC1_HISTOGRAM_1_VADDR 		(0xb8019290)
#define  VDTOP_H_PHASE_DIFF_SEC1_HISTOGRAM_2_VADDR 		(0xb8019294)
#define  VDTOP_H_PHASE_DIFF_SEC2_HISTOGRAM_1_VADDR 		(0xb8019298)
#define  VDTOP_H_PHASE_DIFF_SEC2_HISTOGRAM_2_VADDR 		(0xb801929c)
#define  VDTOP_DATA_LEVEL_STATISTICS_SET_1_VADDR 		(0xb80192a0)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC1_VADDR 		(0xb80192a4)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC2_VADDR 		(0xb80192a8)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC3_VADDR 		(0xb80192ac)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC4_VADDR 		(0xb80192b0)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC5_VADDR 		(0xb80192b4)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC6_VADDR 		(0xb80192b8)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC7_VADDR 		(0xb80192bc)
#define  VDTOP_DATA_LEVEL_STATISTICS_SEC8_VADDR 		(0xb80192c0)
#define  VDTOP_HLOCK_TIME_POLLING_VADDR 		(0xb80192d0)
#define  VDTOP_VLOCK_TIME_POLLING_VADDR 		(0xb80192d4)
#define  VDTOP_VSTATELOCK_TIME_POLLING_VADDR 		(0xb80192d8)
#define  VDTOP_NO_SIGNAL_FALL_TIME_POLLING_VADDR 		(0xb80192dc)
#define  VDTOP_VSYNC_CNTL_VADDR 		(0xb8019300)
#define  VDTOP_VSYNC_TIME_CONST_VADDR 		(0xb8019304)
#define  VDTOP_VSYNC_TIME_CONST2_VADDR 		(0xb8019308)
#define  VDTOP_VSYNC_TIME_CONST1_VADDR 		(0xb801930c)
#define  VDTOP_SERRATION_TH_VADDR 		(0xb8019310)
#define  VDTOP_NO_SIGNAL_DEC_VADDR 		(0xb8019314)
#define  VDTOP_VACTIVE_START_VADDR 		(0xb8019318)
#define  VDTOP_VACTIVE_HEIGHT_VADDR 		(0xb801931c)
#define  VDTOP_VSYNC_H_MIN_VADDR 		(0xb8019320)
#define  VDTOP_VSYNC_H_MAX_VADDR 		(0xb8019324)
#define  VDTOP_VSYNC_VBI_MIN_VADDR 		(0xb8019328)
#define  VDTOP_VSYNC_VBI_LOCKOUT_END_VADDR 		(0xb801932c)
#define  VDTOP_MIDPT_CTRL_VADDR 		(0xb8019330)
#define  VDTOP_MIDPT_FIX_ADD_VALUE_VADDR 		(0xb8019334)
#define  VDTOP_MIDPT_625_DC_TH_VADDR 		(0xb8019338)
#define  VDTOP_SYNC_DC_OFFSET_TH1_VADDR 		(0xb801933c)
#define  VDTOP_SYNC_DC_OFFSET_TH_VADDR 		(0xb8019340)
#define  VDTOP_SYNC_MIDPT_H_VADDR 		(0xb8019344)
#define  VDTOP_SYNC_MIDPT_V_VADDR 		(0xb8019348)
#define  VDTOP_SYNC_MIDPT_V2_VADDR 		(0xb801934c)
#define  VDTOP_ADC_27_LPF_COEF_1_VADDR 		(0xb8019350)
#define  VDTOP_ADC_27_LPF_COEF_2_VADDR 		(0xb8019354)
#define  VDTOP_ADC_27_LPF_COEF_3_VADDR 		(0xb8019358)
#define  VDTOP_ADC_27_LPF_COEF_4_VADDR 		(0xb801935c)
#define  VDTOP_ADC_27_LPF_COEF_5_VADDR 		(0xb8019360)
#define  VDTOP_ADC_27_LPF_COEF_6_VADDR 		(0xb8019364)
#define  VDTOP_VDETECT_LINE_LENGHT_VADDR 		(0xb8019368)
#define  VDTOP_VDETECT_WINDOW_CTRL_VADDR 		(0xb801936c)
#define  VDTOP_VDETECT_WINDOW_TH_VADDR 		(0xb8019370)
#define  VDTOP_NEW_VDETECT_CTRL_VADDR 		(0xb8019374)
#define  VDTOP_NEW_VDETECT_LOOP_TH2_VADDR 		(0xb8019378)
#define  VDTOP_NEW_VDETECT_LOOP_TH1_VADDR 		(0xb801937c)
#define  VDTOP_NEW_VDETECT_DIFF_OFFSET_VADDR 		(0xb8019380)
#define  VDTOP_VSYNC_FINE_START_VADDR 		(0xb8019384)
#define  VDTOP_VSYNC_FINE_END_VADDR 		(0xb8019388)
#define  VDTOP_NO_VSYNC_TH_VADDR 		(0xb801938c)
#define  VDTOP_NEW_VDETECT_VPHASE_TH_VADDR 		(0xb8019390)
#define  VDTOP_NEW_VDETECT_TH1_VADDR 		(0xb8019394)
#define  VDTOP_NEW_VDETECT_TH2_VADDR 		(0xb8019398)
#define  VDTOP_NEW_VDETECT_TH3_VADDR 		(0xb801939c)
#define  VDTOP_NEW_VDETECT_TH4_VADDR 		(0xb80193a0)
#define  VDTOP_VSTATE_CTRL0_VADDR 		(0xb80193b0)
#define  VDTOP_VSTATE_CTRL1_VADDR 		(0xb80193b4)
#define  VDTOP_VSTATE_CTRL2_VADDR 		(0xb80193b8)
#define  VDTOP_VSTATE_CTRL3_VADDR 		(0xb80193bc)
#define  VDTOP_VLOOP0_TC1_VADDR 		(0xb80193c0)
#define  VDTOP_VLOOP0_TC2_VADDR 		(0xb80193c4)
#define  VDTOP_VLOOP2_TC1_VADDR 		(0xb80193c8)
#define  VDTOP_VLOOP2_TC2_VADDR 		(0xb80193cc)
#define  VDTOP_VLOOP3_TC1_VADDR 		(0xb80193d0)
#define  VDTOP_VLOOP3_TC2_VADDR 		(0xb80193d4)
#define  VDTOP_VLOOP_TC3_VADDR 		(0xb80193d8)
#define  VDTOP_VLOCK_COUNT_VADDR 		(0xb80193dc)
#define  VDTOP_VLOCK_WINDOW_VADDR 		(0xb80193e0)
#define  VDTOP_VLOCK_PHASE_PLUS_VADDR 		(0xb80193e4)
#define  VDTOP_VLINE_ADJ_CNT_A_VADDR 		(0xb80193e8)
#define  VDTOP_VLINE_ADJ_CNT_B_VADDR 		(0xb80193ec)
#define  VDTOP_TABLE_HACTIVE_WIDTH_VADDR 		(0xb80193f0)
#define  VDTOP_VSYNC_PLL_FREERUN_MUX_VADDR 		(0xb80193f4)
#define  VDTOP_CHROMA_AGC_VADDR 		(0xb8019400)
#define  VDTOP_CHROMA_KILL_VADDR 		(0xb8019404)
#define  VDTOP_CHROMA_LOCK_CONFIG_VADDR 		(0xb8019408)
#define  VDTOP_CHROMA_LOOPFILTER_GAIN_VADDR 		(0xb801940c)
#define  VDTOP_CHROMA_LOOPFILTER_STATE_VADDR 		(0xb8019410)
#define  VDTOP_CHROMA_AUTOPOS_VADDR 		(0xb8019414)
#define  VDTOP_CKILL_LB_SEL_VADDR 		(0xb8019418)
#define  VDTOP_CKILL_GAIN_KILL_THL_VADDR 		(0xb801941c)
#define  VDTOP_CSTATE_CTRL_VADDR 		(0xb8019420)
#define  VDTOP_BADEDIT_TH_VADDR 		(0xb8019424)
#define  VDTOP_BADPHASE_TH_VADDR 		(0xb8019428)
#define  VDTOP_CSTATE_LINE_NUM_VADDR 		(0xb801942c)
#define  VDTOP_CHROMA_AGC_PEAK_CTRL_VADDR 		(0xb8019430)
#define  VDTOP_CHROMA_AGC_PEAK_NOMINAL_VADDR 		(0xb8019434)
#define  VDTOP_CLOSE_CKILL_LOOPFILTER_VADDR 		(0xb8019438)
#define  VDTOP_CAGC_PEAK_CTRL1_VADDR 		(0xb801943c)
#define  VDTOP_CAGC_PEAK_CTRL2_VADDR 		(0xb8019440)
#define  VDTOP_CAGC_PEAK_CTRL3_VADDR 		(0xb8019444)
#define  VDTOP_CHROMA_DELAY_CTRL_VADDR 		(0xb8019448)
#define  VDTOP_BURST_CGAIN_CTRL_VADDR 		(0xb801944c)
#define  VDTOP_BURST_CGAIN_MAG_TH_VADDR 		(0xb8019450)
#define  VDTOP_FLAG358_CDTO_INC4_VADDR 		(0xb8019454)
#define  VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_VADDR 		(0xb8019458)
#define  VDTOP_SEPARATE_443_358_NEW_FUNCTION_2_VADDR 		(0xb801945c)
#define  VDTOP_SEPARATE_443_358_NEW_FUNCTION_3_VADDR 		(0xb8019460)
#define  VDTOP_BURST_LOCATION_STATUS_1_VADDR 		(0xb8019464)
#define  VDTOP_BURST_LOCATION_STATUS_2_VADDR 		(0xb8019468)
#define  VDTOP_BURST_LOCATION_HSYNC_VADDR 		(0xb801946c)
#define  VDTOP_BURST_LOCATION_FW_CNTL_VADDR 		(0xb8019470)
#define  VDTOP_Y_PATH_EQ_FILTER_VADDR 		(0xb8019474)
#define  VDTOP_Y_PATH_EQ_FILTER_R_VADDR 		(0xb8019478)
#define  VDTOP_PALM_FLAG_COMPENSATION1_VADDR 		(0xb8019490)
#define  VDTOP_PALM_FLAG_COMPENSATION2_VADDR 		(0xb8019494)
#define  VDTOP_MANUAL_MODE_VADDR 		(0xb80194a0)
#define  VDTOP_MODE_DETECTION_STATUS_VADDR 		(0xb80194a4)
#define  VDTOP_STATISTIC_AND_DISABLE_MODE_VADDR 		(0xb80194a8)
#define  VDTOP_PREFER_MODE_VADDR 		(0xb80194ac)
#define  VDTOP_STATE_MACHINE_FIX_MODE_VADDR 		(0xb80194b0)
#define  VDTOP_VD_BASIC_REGISTER_ENABLE_VADDR 		(0xb80194b4)
#define  VDTOP_AUTO_MODE_S_M_STATISTIC_VADDR 		(0xb80194b8)
#define  VDTOP_AUTO_POS_CTRL_3_VADDR                        	(0xb80194bc)
#define  VDTOP_AUTO_POS_CTRL_VADDR 		(0xb80194c0)
#define  VDTOP_AUTO_POS_CTRL_2_VADDR 		(0xb80194c4)
#define  VDTOP_FLAG358_CTRL_VADDR 		(0xb80194c8)
#define  VDTOP_NO_BURST_MAG_TH_VADDR 		(0xb80194cc)
#define  VDTOP_NO_BURST_MAG_FILTER_TH_VADDR 		(0xb80194d0)
#define  VDTOP_NO_BURST_443_CTRL_VADDR 		(0xb80194d4)
#define  VDTOP_FLAG358_SECAM_HCOUNT_RESET_CTRL_VADDR 		(0xb80194d8)
#define  VDTOP_FLAG358_SECAM_PHASE_DIFF_DR_VADDR 		(0xb80194dc)
#define  VDTOP_FLAG358_SECAM_PHASE_DIFF_DB_VADDR 		(0xb80194e0)
#define  VDTOP_BURST_MAG_TH_358_VADDR 		(0xb80194e4)
#define  VDTOP_AUTO_MODE_TABLE1_VADDR 		(0xb80194f0)
#define  VDTOP_AUTO_MODE_TABLE2_VADDR 		(0xb80194f4)
#define  VDTOP_AUTO_MODE_TABLE3_VADDR 		(0xb80194f8)
#define  VDTOP_AUTO_MODE_TABLE4_VADDR 		(0xb80194fc)
#define  VDTOP_AUTO_MODE_TABLE5_VADDR 		(0xb8019500)
#define  VDTOP_AUTO_MODE_TABLE6_VADDR 		(0xb8019504)
#define  VDTOP_FLAG_625_COUNTER_VADDR 		(0xb8019508)
#define  VDTOP_FLAG_443_COUNTER_VADDR 		(0xb801950c)
#define  VDTOP_SECAM_FLAG_COUNTER_VADDR 		(0xb8019510)
#define  VDTOP_PALM_FLAG_COUNTER_VADDR 		(0xb8019514)
#define  VDTOP_BURST_VALID_COUNTER_VADDR 		(0xb8019518)
#define  VDTOP_MIDPOINT_ADJ_VADDR 		(0xb801951c)
#define  VDTOP_FREQ_FLAG_THRESHOLD_VADDR 		(0xb8019520)
#define  VDTOP_FREQ_VALID_MAX_VADDR 		(0xb8019524)
#define  VDTOP_FREQ_VALID_INNER_VADDR 		(0xb8019528)
#define  VDTOP_FREQ_VALID_MIN_VADDR 		(0xb801952c)
#define  VDTOP_SECAM_FLAG_COUNTER_MAX_VADDR 		(0xb8019530)
#define  VDTOP_SECAM_FLAG_COUNTER_MIN_VADDR 		(0xb8019534)
#define  VDTOP_PALM_FLAG_PHASE_ADJ_VADDR 		(0xb8019538)
#define  VDTOP_BURST_LOWER_LIMIT_VADDR 		(0xb801953c)
#define  VDTOP_BURST_MAG_CHOICE_VADDR 		(0xb8019540)
#define  VDTOP_NEW_358_CTRL_VADDR 		(0xb8019550)
#define  VDTOP_NEW_358_CNT_UP_VADDR 		(0xb8019554)
#define  VDTOP_NEW_358_CNT_DN_VADDR 		(0xb8019558)
#define  VDTOP_SEP_COUNT_TH_VADDR 		(0xb801955c)
#define  VDTOP_SEP_BURST_START0_VADDR 		(0xb8019560)
#define  VDTOP_SEP_BURST_END0_VADDR 		(0xb8019564)
#define  VDTOP_SEP_BURST_RO_1_VADDR 		(0xb8019568)
#define  VDTOP_SEP_BURST_RO_2_VADDR 		(0xb801956c)
#define  VDTOP_SEP_BURST_RO3_VADDR 		(0xb8019570)
#define  VDTOP_SEP_BURST_TH1_VADDR 		(0xb8019574)
#define  VDTOP_SEP_BURST_FLAG1_VADDR 		(0xb8019578)
#define  VDTOP_AUTOMODE_443358PK_CTRL_VADDR 		(0xb801957c)
#define  VDTOP_DARK_CPLL_CDETECT_1_VADDR 		(0xb8019580)
#define  VDTOP_DARK_CPLL_CDETECT_2_VADDR 		(0xb8019584)
#define  VDTOP_DARK_CPLL_PAL_VADDR 		(0xb8019588)
#define  VDTOP_DARK_CPLL_CHROMALOCK_VADDR 		(0xb801958c)
#define  VDTOP_DARK_CPLL_CONTROLL_VADDR 		(0xb8019590)
#define  VDTOP_DARK_CPLL_RESULT_VADDR 		(0xb8019594)
#define  VDTOP_DARK_CPLL_BURSTMAG_VADDR                     	(0xb8019598)
#define  VDTOP_IRQ_MASK1_VADDR 		(0xb80195a0)
#define  VDTOP_IRQ_MASK2_VADDR 		(0xb80195a4)
#define  VDTOP_IRQ_MASK3_VADDR 		(0xb80195a8)
#define  VDTOP_IRQ_STATUS1_VADDR 		(0xb80195ac)
#define  VDTOP_IRQ_STATUS2_VADDR 		(0xb80195b0)
#define  VDTOP_IRQ_STATUS3_VADDR 		(0xb80195b4)
#define  VDTOP_ADC_LIMIT_THRESHOLD_VADDR 		(0xb80195b8)
#define  VDTOP_ADC_OVER_UNDER_FLAG_VADDR 		(0xb80195bc)
#define  VDTOP_DGAIN_OUT_OVER_UNDER_FLAG_VADDR 		(0xb80195c0)
#define  VDTOP_DGAIN_OUT_OVER_UNDER_CNTL_VADDR 		(0xb80195c4)
#define  VDTOP_LDPAUSE_CTRL_VADDR 		(0xb80195e0)
#define  VDTOP_VCR_OPTION_VADDR 		(0xb80195e4)
#define  VDTOP_CENABLE_LINE_COUNT_VADDR 		(0xb80195e8)
#define  VDTOP_SIGNAL_STM_CONTROL_VADDR 		(0xb80195ec)
#define  VDTOP_CDETECT_PHASE_ERR_STATUS_VADDR 		(0xb80195f0)
#define  VDTOP_AD_SW_CTRL0_VADDR 		(0xb8019608)
#define  VDTOP_CLAMP_UPDN_EN_VADDR 		(0xb801960c)
#define  VDTOP_CLAMP_RGB_UPDN_EN_VADDR 		(0xb8019610)
#define  VDTOP_FSW_CTRL0_VADDR 		(0xb8019618)
#define  VDTOP_FSW_CTRL1_VADDR 		(0xb801961c)
#define  VDTOP_FSW_CTRL2_VADDR 		(0xb8019620)
#define  VDTOP_FSW_CTRL3_VADDR 		(0xb8019624)
#define  VDTOP_LUMA_CONTRAST2_ADJ_VADDR 		(0xb8019628)
#define  VDTOP_LUMA_BRIGHTNESS2_ADJ_VADDR 		(0xb801962c)
#define  VDTOP_CHROMA_SATURATION2_ADJ_VADDR 		(0xb8019630)
#define  VDTOP_CB_SAT_ADJ_VADDR 		(0xb8019634)
#define  VDTOP_LUMA_PEAKING2_VADDR 		(0xb8019638)
#define  VDTOP_FSW_GAIN_CTRL_VADDR 		(0xb801963c)
#define  VDTOP_FSW_INPUT_STATUS_VADDR 		(0xb8019640)
#define  VDTOP_CHROMA_REDUCE_CNTL1_VADDR 		(0xb8019644)
#define  VDTOP_CHROMA_REDUCE_CNTL2_VADDR 		(0xb8019648)
#define  VDTOP_ADCR_CALI_STATUS_VADDR                       	(0xb801964c)
#define  VDTOP_ADCG_CALI_STATUS_VADDR                       	(0xb8019650)
#define  VDTOP_ADCB_CALI_STATUS_VADDR                       	(0xb8019654)
#define  VDTOP_ADC_GAIN_R1_VADDR                            	(0xb8019658)
#define  VDTOP_ADC_GAIN_R_VADDR                             	(0xb801965c)
#define  VDTOP_ADC_GAIN_G_VADDR                             	(0xb8019660)
#define  VDTOP_ADC_GAIN_B_VADDR                             	(0xb8019664)
#define  VDTOP_COLOR_MATRIX_R_VADDR                         	(0xb8019668)
#define  VDTOP_COLOR_MATRIX_RG_VADDR                        	(0xb801966c)
#define  VDTOP_COLOR_MATRIX_G_VADDR                         	(0xb8019670)
#define  VDTOP_COLOR_MATRIX_B_VADDR                         	(0xb8019674)
#define  VDTOP_COLOR_MATRIX_B3_VADDR                        	(0xb8019678)
#define  VDTOP_CLAMP_TEST_REG0_VADDR 		(0xb8019680)
#define  VDTOP_CLAMP_TEST_REG2_VADDR 		(0xb8019684)
#define  VDTOP_CLAMP_TEST_REG4_VADDR 		(0xb8019688)
#define  VDTOP_CLAMP_TEST_REG6_VADDR 		(0xb801968c)
#define  VDTOP_CLAMP_TEST_REG8_VADDR 		(0xb8019690)
#define  VDTOP_CLAMP_TEST_REG11_VADDR 		(0xb8019694)
#define  VDTOP_HDETECT_PHASE_ERR_STATUS2_VADDR 		(0xb8019698)
#define  VDTOP_AVOUT_FIFO_RD_PTR_VADDR 		(0xb801969c)
#define  VDTOP_BLANK_LEVEL_MANU_COMP_VALUE_VADDR 		(0xb80196a0)
#define  VDTOP_BLANK_LEVEL_MANU_C_R_VALUE_VADDR 		(0xb80196a4)
#define  VDTOP_BLANK_LEVEL_MANU_G_B_VALUE_VADDR 		(0xb80196a8)
#define  VDTOP_FPGA_TEST_REG1_VADDR 		(0xb80196b0)
#define  VDTOP_FPGA_TEST_REG2_VADDR 		(0xb80196b4)
#define  VDTOP_FPGA_TEST_REG3_VADDR 		(0xb80196b8)
#define  VDTOP_FPGA_TEST_REG4_VADDR 		(0xb80196bc)
#define  VDTOP_FPGA_TEST_REG5_VADDR 		(0xb80196c0)
#define  VDTOP_FPGA_TEST_REG6_VADDR 		(0xb80196c4)
#define  VDTOP_FPGA_TEST_REG7_VADDR 		(0xb80196c8)
#define  VDTOP_FPGA_TEST_REG8_VADDR 		(0xb80196cc)
#define  VDTOP_SECAM_CTRL_VADDR 		(0xb8019700)
#define  VDTOP_SECAM_DRFREQ_OFFSET_VADDR 		(0xb8019704)
#define  VDTOP_SECAM_DBFREQ_OFFSET_VADDR 		(0xb8019708)
#define  VDTOP_SECAM_HCOUNT_RESET_CTRL_VADDR 		(0xb801970c)
#define  VDTOP_PHASE_DIFF_DR_RST_VADDR 		(0xb8019710)
#define  VDTOP_PHASE_DIFF_DB_RST_VADDR 		(0xb8019714)
#define  VDTOP_DRDB_GAIN_TABLE_CTRL_VADDR 		(0xb8019718)
#define  VDTOP_Y_GAIN_TABLE_CTRL_VADDR 		(0xb801971c)
#define  VDTOP_SECAM_GAIN_DLY_VADDR 		(0xb8019720)
#define  VDTOP_SECAM_GAIN_TABLE_DEBUG_VADDR 		(0xb8019724)
#define  VDTOP_NEW_SECAM_HCOUNT_RESET_CTRL_VADDR 		(0xb8019734)
#define  VDTOP_NEW_SECAM_PHASE_DIFF_DR_VADDR 		(0xb8019738)
#define  VDTOP_NEW_SECAM_PHASE_DIFF_DB_VADDR 		(0xb801973c)
#define  VDTOP_NEW_SECAM_CDTO_INC_VADDR 		(0xb8019740)
#define  VDTOP_SECAM_GP_RM_VADDR 		(0xb8019744)
#define  VDTOP_FIFO_CTRL_VADDR 		(0xb8019758)
#define  VDTOP_FIFO_STATUS_VADDR 		(0xb801975c)
#define  VDTOP_I_GAIN_CONTROL_VADDR 		(0xb8019760)
#define  VDTOP_MISC_CONTROL_VADDR 		(0xb8019764)
#define  VDTOP_FIFO_DEPTH_MIN_STATUS_VADDR 		(0xb8019768)
#define  VDTOP_FIFO_DEPTH_MAX_STATUS_VADDR 		(0xb801976c)
#define  VDTOP_PLL_DEBUG_CTRL1_VADDR 		(0xb8019770)
#define  VDTOP_PLL_DEBUG_CTRL2_VADDR 		(0xb8019774)
#define  VDTOP_DISP_FSYNC_CONTROL_VADDR 		(0xb8019778)
#define  VDTOP_FIFO_WO_PS_FUNC_VADDR 		(0xb801977c)
#define  VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_VADDR 		(0xb8019780)
#define  VDTOP_FIFO_STATUS_NO_PLL_VADDR 		(0xb8019784)
#define  VDTOP_DEBUG_MUX_VADDR 		(0xb8019788)
#define  VDTOP_VIDEO_DEBUG_ANALOG_VADDR 		(0xb801978c)
#define  VDTOP_VIDEO_DEBUG_DIGITAL_VADDR 		(0xb8019790)
#define  VDTOP_PATTERN_CONTROL_VADDR 		(0xb8019794)
#define  VDTOP_CRC_RESULT3_VADDR 		(0xb8019798)
#define  VDTOP_PATGEN_CTRL_VADDR 		(0xb801979c)
#define  VDTOP_BIST_MODE_VADDR 		(0xb80197a0)
#define  VDTOP_BIST_DONE_VADDR 		(0xb80197a4)
#define  VDTOP_BIST_FAIL_VADDR 		(0xb80197a8)
#define  VDTOP_BIST_DRF_MODE_VADDR 		(0xb80197ac)
#define  VDTOP_BIST_DRF_RESUME_VADDR 		(0xb80197b0)
#define  VDTOP_BIST_DRF_DONE_VADDR 		(0xb80197b4)
#define  VDTOP_BIST_DRF_PAUSE_VADDR 		(0xb80197b8)
#define  VDTOP_BIST_DRF_FAIL_VADDR 		(0xb80197bc)
#define  VDTOP_BIST_FAIL_27_1_VADDR 		(0xb80197c0)
#define  VDTOP_BIST_FAIL_27_2_VADDR 		(0xb80197c4)
#define  VDTOP_BIST_FAIL_DMA_VADDR 		(0xb80197c8)
#define  VDTOP_BIST_FAIL_FIFO_VADDR 		(0xb80197cc)
#define  VDTOP_BIST_FAIL_OUT_VADDR 		(0xb80197d0)
#define  VDTOP_BIST_DRF_FAIL_27_1_VADDR 		(0xb80197d4)
#define  VDTOP_BIST_DRF_FAIL_27_2_VADDR 		(0xb80197d8)
#define  VDTOP_BIST_DRF_FAIL_DMA_VADDR 		(0xb80197dc)
#define  VDTOP_BIST_DRF_FAIL_FIFO_VADDR 		(0xb80197e0)
#define  VDTOP_BIST_DRF_FAIL_OUT_VADDR 		(0xb80197e4)
#define  VDTOP_BIST_DVSE_DVS_VADDR 		(0xb80197e8)
#define  VDTOP_BIST_DVSE_DVS2_VADDR 		(0xb80197ec)
#define  VDTOP_YCBCR_MONITER_CTRL_VADDR 		(0xb80197f0)
#define  VDTOP_YCBCR_MONITER_VALUE_Y_VADDR 		(0xb80197f4)
#define  VDTOP_YCBCR_MONITER_VALUE_CBCR_VADDR 		(0xb80197f8)
#define  VDTOP_ADC_UPDN_CTRL_VADDR 		(0xb80197fc)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VDTOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hv_delay:1;
        RBus_UInt32  hpixel:2;
        RBus_UInt32  vline_625:1;
        RBus_UInt32  colour_mode:3;
        RBus_UInt32  res2:1;
    };
}vdtop_video_control0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ycsep_power_on:1;
        RBus_UInt32  smixer_ycadjust_power_on:1;
        RBus_UInt32  sv_power_on_en:1;
        RBus_UInt32  scart_power_on_en:1;
        RBus_UInt32  secam_power_on_en:1;
        RBus_UInt32  avout_power_on_en:1;
        RBus_UInt32  dark_cpll_power_on_en:1;
        RBus_UInt32  patterngen_power_on_en:1;
        RBus_UInt32  ycsepdata_burstin_en:1;
        RBus_UInt32  vd_pq_bypass_en:1;
        RBus_UInt32  cv_inv:1;
        RBus_UInt32  cv_src:1;
        RBus_UInt32  yc_src:1;
        RBus_UInt32  dark_yc_src:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ped:1;
    };
}vdtop_video_control1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  hvlock_longtime:1;
        RBus_UInt32  vlock_longtime:1;
        RBus_UInt32  hlock_longtime:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  chromalock_acc:1;
        RBus_UInt32  h_fine_lock:1;
        RBus_UInt32  mv_colour_inverse:3;
        RBus_UInt32  mv_vbi_detected:1;
        RBus_UInt32  chomalock:1;
        RBus_UInt32  vlock:1;
        RBus_UInt32  hlock:1;
        RBus_UInt32  no_signal:1;
    };
}vdtop_video_status_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  new_vdetect_stable:1;
        RBus_UInt32  old_vdetect_stable:1;
        RBus_UInt32  firtst_vsync_detected:1;
        RBus_UInt32  v_detect_flag:1;
        RBus_UInt32  detect358_flag:1;
        RBus_UInt32  vlock_new:1;
        RBus_UInt32  noisy_vbi:1;
        RBus_UInt32  detect443_flag:1;
        RBus_UInt32  burst_detect:1;
        RBus_UInt32  palor_flag:1;
        RBus_UInt32  palm_flag:1;
        RBus_UInt32  proscan_detected:1;
    };
}vdtop_video_status_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vcr_rew:1;
        RBus_UInt32  vcr_ff:1;
        RBus_UInt32  vcr_trick:1;
        RBus_UInt32  vcr:1;
        RBus_UInt32  noisy:1;
        RBus_UInt32  lines_625_detected:1;
        RBus_UInt32  secam_detected:1;
        RBus_UInt32  pal_detected:1;
    };
}vdtop_video_status_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hdto_inc_status:30;
    };
}vdtop_hdto_inc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cdto_inc_status:30;
    };
}vdtop_cdto_inc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_magnitude:8;
    };
}vdtop_avg_burst_mag_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_dgain:12;
    };
}vdtop_agc_dgain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  status_cmag:8;
    };
}vdtop_cmag_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  status_cgain_data:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  status_cgain:14;
    };
}vdtop_cgain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  status_cordiq_freq:8;
    };
}vdtop_cordic_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  v_1st_line:10;
    };
}vdtop_measure_first_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  v_2nd_line:10;
    };
}vdtop_measure_second_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  porch_h:13;
    };
}vdtop_porch_height_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  status_noise:8;
    };
}vdtop_noise_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  noise_thresh:8;
    };
}vdtop_noise_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdto_fixed:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdto_inc:30;
    };
}vdtop_hsync_dto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdto_fixed:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cdto_inc:30;
    };
}vdtop_chroma_dto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  chip_ver:16;
    };
}vdtop_chip_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  blank_vid_offset_manu_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  blank_vid_offset_value:11;
    };
}vdtop_blank_vid_offset_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  contrast:8;
    };
}vdtop_luma_contrast_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  brightness:8;
    };
}vdtop_luma_brightness_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  saturation:8;
    };
}vdtop_chroma_saturation_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hue:8;
    };
}vdtop_chroma_hue_phase_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  blue_screen_y:8;
    };
}vdtop_blue_screen_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  blue_screen_cb:8;
    };
}vdtop_blue_screen_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  blue_screen_cr:8;
    };
}vdtop_blue_screen_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  motion_delay:4;
        RBus_UInt32  snow_freerun_en:1;
        RBus_UInt32  cbcr_swap:1;
        RBus_UInt32  blue_mode:2;
        RBus_UInt32  yc_delay:4;
    };
}vdtop_output_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  avout_hsync_start:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  avout_hsync_end:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  fe_bypass_sel:1;
        RBus_UInt32  sw_tu_cvbs:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clamp_if_up_en:1;
        RBus_UInt32  clamp_if_dn_en:1;
    };
}vdtop_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  output_fifo_full:1;
        RBus_UInt32  output_fifo_empty:1;
        RBus_UInt32  output_delay_0_180_sw:1;
        RBus_UInt32  avout_test_in:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  avout_mixer_sel:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  avout_fifo_status_full:1;
        RBus_UInt32  avout_fifo_status_empty:1;
    };
}vdtop_avout_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avout_ifdebug_inv:12;
        RBus_UInt32  avout_ifdebug_mask:12;
        RBus_UInt32  avout_ifdebug_shift:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  avout_ifdebug_sel:1;
    };
}vdtop_avout_ifdebug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ramp_en:1;
        RBus_UInt32  ramp_updn_sel:1;
        RBus_UInt32  ramp_counter_num:24;
    };
}vdtop_avout1_ifdebug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peak_deb_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  peak_diff_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  peak_data_sel:1;
        RBus_UInt32  peak_deb_limit:9;
        RBus_UInt32  peak_deb_thl:8;
        RBus_UInt32  hagc_err_coring_en:1;
        RBus_UInt32  agc_peak_nominal:7;
    };
}vdtop_agc_peak_nominal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dgain_i_cntl_without_trunc_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  chroma_path_dgain_after_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ycsep_data_decrease_en:1;
        RBus_UInt32  ycsep_data_decrease_ratio:3;
        RBus_UInt32  agc_peak_nominal_ycsep:12;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_gate_kill_mode_sel:2;
        RBus_UInt32  agc_gate_kill_w_hlock:1;
        RBus_UInt32  agc_gate_vsync_coarse:1;
        RBus_UInt32  agc_gate_vsync_stip:1;
        RBus_UInt32  agc_gate_kill_mode:2;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  agc_peak_cntl:3;
    };
}vdtop_agc_peak_and_gate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peak_gain:12;
        RBus_UInt32  diff_level:12;
        RBus_UInt32  unlock_peakrst_en:1;
        RBus_UInt32  hagc_err_coring_th:5;
        RBus_UInt32  agc_peak_loop_gain:2;
    };
}vdtop_agc_peak_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  mv_detect_sel:1;
        RBus_UInt32  fix_dgain:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  dgain_state:2;
        RBus_UInt32  under_gain:12;
        RBus_UInt32  hagc_field_mode:1;
        RBus_UInt32  mv_hagc_mode:1;
        RBus_UInt32  dc_clamp_mode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  bgate_raw_sel:1;
        RBus_UInt32  cagc_en:1;
        RBus_UInt32  hagc_en:1;
    };
}vdtop_video_control2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dgain_status_triger:1;
        RBus_UInt32  peak_under_round_en:1;
        RBus_UInt32  peak_under_round_thl:8;
        RBus_UInt32  dgain_status_counter:12;
        RBus_UInt32  hagc:8;
    };
}vdtop_luma_agc_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  dgain_kp:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dgain_ki:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  diff_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  agc_gate_start:11;
    };
}vdtop_agc_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_path_dgain_limit_up:12;
        RBus_UInt32  data_path_dgain_limit_low:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_gate_width:7;
    };
}vdtop_agc_gate_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  agc_bp_delay:8;
    };
}vdtop_agc_bp_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  clampagc_under_th2:6;
    };
}vdtop_clampagc_compluma_new_threshold2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ypeak_wide_iir_in_coef:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  ypeak_wide_iir_en:1;
        RBus_UInt32  data_path_dgain_div2_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_under_loop_gain:3;
        RBus_UInt32  under_flag:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  clampagc_under_th1:4;
    };
}vdtop_clampagc_compluma_new_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_deb_en:1;
        RBus_UInt32  under_gate_en:1;
        RBus_UInt32  under_diff_sel:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  under_deb_limit:9;
        RBus_UInt32  under_deb_thl:8;
        RBus_UInt32  clampagc_under_cntl:6;
        RBus_UInt32  clampagc_under_en:1;
        RBus_UInt32  blank_vid_offset:1;
    };
}vdtop_clampagc_compluma_new_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  under_gate_end:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  under_gate_st:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  vsync_agc_min:7;
    };
}vdtop_vsync_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peak_gate_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  peak_gate_end:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  peak_gate_st:10;
        RBus_UInt32  vsync_clamp_mode:2;
        RBus_UInt32  vsync_agc_max:6;
    };
}vdtop_vsync_agc_lockout_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  auto_dc_restore_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_dc_restore_en2:1;
        RBus_UInt32  auto_dc_restore_en1:1;
        RBus_UInt32  auto_dc_restore_en0:1;
        RBus_UInt32  auto_dc_restore_disable_ad4_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad3_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad2_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad1_updn:1;
        RBus_UInt32  cpump_adjust_delay:6;
        RBus_UInt32  cpump_adjust_polarity:1;
        RBus_UInt32  cpump_delay_en:1;
    };
}vdtop_charge_pump_delay_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cpump_adjust:8;
    };
}vdtop_charge_pump_adjustment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cpump_delay:8;
    };
}vdtop_charge_pump_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sv_rgb_clamp_length_limit_en:1;
        RBus_UInt32  cvbs_clamp_length_limit_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sv_rgb_clamp_length_max:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  cvbs_clamp_length_max:7;
        RBus_UInt32  adc_updn_swap:1;
        RBus_UInt32  adc_input_swap:1;
        RBus_UInt32  adc_cbcr_pump_swap:1;
        RBus_UInt32  agc_gate_thresh:5;
    };
}vdtop_agc_gate_th_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  first_dgain_integral_value:20;
        RBus_UInt32  res1:3;
        RBus_UInt32  first_dgain_integral_fw_mode_en:1;
        RBus_UInt32  measure_dc_128_64_sel:1;
        RBus_UInt32  dgain_ignore_fine_lock:1;
        RBus_UInt32  measure_dc_rough:1;
        RBus_UInt32  new_clamp_rc_rate_en:1;
        RBus_UInt32  clampagc_rc_rate:4;
    };
}vdtop_new_clampagc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  first_dgain_int_value_status:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  measure_dc_rough_dn:8;
    };
}vdtop_measure_dc_rough_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_dgain_integral_value:20;
        RBus_UInt32  res1:3;
        RBus_UInt32  second_dgain_integral_fw_mode_en:1;
        RBus_UInt32  measure_dc_rough_up:8;
    };
}vdtop_measure_dc_rough_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_dgain_int_value_status:20;
        RBus_UInt32  measure_dc_th_dn:12;
    };
}vdtop_measure_dc_th_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  measure_dc_th_up:12;
    };
}vdtop_measure_dc_th_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vsag_rc_input:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vsag_agc_peak_cntl:6;
    };
}vdtop_vsag_cntl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  peak_vsag:13;
    };
}vdtop_peak_vsag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  new_total_under_en:1;
        RBus_UInt32  new_under_gain_en:1;
        RBus_UInt32  new_under_th2_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  lose_sgate_flag:1;
        RBus_UInt32  lose_bgate_flag:1;
        RBus_UInt32  field_kill_rst:1;
    };
}vdtop_kill_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  field_kill_num:10;
    };
}vdtop_field_kill_mun_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kill_gate_up:11;
    };
}vdtop_kill_gate_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kill_gate_dn:11;
    };
}vdtop_kill_gate_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  syncmidpt_add_level_h:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  sync_midpt_lowest_en:1;
        RBus_UInt32  res3:1;
    };
}vdtop_syncmidpt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  syncmidpt_fix_add_value_h:8;
    };
}vdtop_syncmidpt_fix_add_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  lpfsync_plus_w_hlock:2;
        RBus_UInt32  lpfsync_plus_rm:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  lpfsync_plus_diff:6;
    };
}vdtop_lpfsync_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  spike_min_thresh:8;
    };
}vdtop_spike_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  spike_max_thresh:8;
    };
}vdtop_spike_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  spike_detected:1;
        RBus_UInt32  spike_detected_up:10;
    };
}vdtop_spike_detected_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  spike_detected_dn:10;
    };
}vdtop_spike_detected_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lpfsync_plus_dc:8;
    };
}vdtop_lpfsync_plus_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hstate_error_thl:8;
        RBus_UInt32  hstate_error_dn_count:8;
        RBus_UInt32  hstate_error_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdetect_error_avg_interval:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  hdetect_error_avg_length:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdetect_error_avg_sel:1;
    };
}vdtop_hdetect_err_var_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_error_var:16;
        RBus_UInt32  hdetect_error_mean:16;
    };
}vdtop_hdetect_err_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hstate_vsync_error_num_thr:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_vsync_error_end:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  hstate_vsync_error_start:7;
        RBus_UInt32  locked_count_vcrtrick_max:4;
        RBus_UInt32  locked_count_noisy_max:4;
        RBus_UInt32  locked_count_clean_max:4;
    };
}vdtop_lock_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  hstate_vsync_error_unbalance_status:1;
        RBus_UInt32  hstate_vsync_error_unbalance_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  hstate_vsync_error_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  hstate_vsync_error_value_en:1;
        RBus_UInt32  hstate_vsync_error_num_en:1;
        RBus_UInt32  hstate_vsync_error_noisy_en:1;
        RBus_UInt32  hstate_vsync_error_vlock_en:1;
        RBus_UInt32  hstate_vsync_error_hlock_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  hstate_vsync_error_unbalance:3;
        RBus_UInt32  hlock_vsync_mode:2;
        RBus_UInt32  hstate_fixed:1;
        RBus_UInt32  disable_hfine:1;
        RBus_UInt32  hstate_unlocked:1;
        RBus_UInt32  hstate_max:3;
    };
}vdtop_h_loop_maxstate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  fine_phase_error_thl:10;
        RBus_UInt32  cpll_hpll_use_front_vactive:1;
        RBus_UInt32  hstate_hlock_sel:1;
        RBus_UInt32  hstate_ignore_err:1;
        RBus_UInt32  auto_fine_phase_sel:1;
        RBus_UInt32  fine_hstate_to_5:1;
        RBus_UInt32  auto_fine_phase_sel_en:1;
        RBus_UInt32  hpll_fine_lock_data_sel:1;
        RBus_UInt32  coarse_phase_rising_en:1;
        RBus_UInt32  fine_src_sel:1;
        RBus_UInt32  coarse_src_sel:1;
        RBus_UInt32  fine_gate_sel:1;
        RBus_UInt32  gate_end_thresh:5;
    };
}vdtop_clampagc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hstate_vsync_error_noisy_lower_th:8;
        RBus_UInt32  hstate_vsync_error_noisy_upper_th:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  coarse_sync_start:7;
    };
}vdtop_clampagc_new_sync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hstate_vsync_error_value_thr:8;
        RBus_UInt32  hstate_vsync_error_abs_thr:8;
        RBus_UInt32  coarse_sync_end:8;
    };
}vdtop_clampagc_new_sync_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  hstate_err:14;
        RBus_UInt32  agc_trailing_sel:1;
        RBus_UInt32  coarse_backporch_start:7;
    };
}vdtop_clampagc_new_backporch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  hstate_err_in_vcount:10;
        RBus_UInt32  coarse_backporch_end:8;
    };
}vdtop_clampagc_new_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  lpfsync_force_blank_en:1;
        RBus_UInt32  nosignal_hlock_check_en:1;
        RBus_UInt32  agc_clamping_trailing_sel:1;
        RBus_UInt32  killgate_sel:1;
        RBus_UInt32  coarse_phase_sel:1;
        RBus_UInt32  fine_phase_sel:1;
    };
}vdtop_hdetect_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lsync_tip_start:8;
    };
}vdtop_hdetect_counter_tip_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lsync_tip_end:8;
    };
}vdtop_hdetect_counter_tip_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lporch_start:8;
    };
}vdtop_hdetect_counter_backporch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lporch_end:8;
    };
}vdtop_hdetect_counter_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  hpll_integral_rst:1;
        RBus_UInt32  hpll_integral_ext:1;
    };
}vdtop_hpll_integral_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gate_kill_mode_status:2;
        RBus_UInt32  new_hpll_lpf_sel_status:1;
        RBus_UInt32  gate_iir_h_sel_status:1;
        RBus_UInt32  gate_iir_v_sel_status:1;
        RBus_UInt32  dgain_ignore_fine_lock_status:1;
        RBus_UInt32  second_pll_en_status:1;
        RBus_UInt32  vsync_freerun_when_unstable_en_status:1;
        RBus_UInt32  agc_gate_kill_mode_vcr:2;
        RBus_UInt32  new_hpll_lpf_sel_vcr:1;
        RBus_UInt32  gate_iir_h_sel_vcr:1;
        RBus_UInt32  gate_iir_v_sel_vcr:1;
        RBus_UInt32  dgain_ignore_fine_lock_vcr:1;
        RBus_UInt32  second_pll_en_vcr:1;
        RBus_UInt32  vsync_freerun_when_unstable_en_vcr:1;
        RBus_UInt32  impulsive_noise_disable_pll_en:1;
        RBus_UInt32  cstate_impn_max:3;
        RBus_UInt32  mode_vcr_setting_change_en:1;
        RBus_UInt32  hstate_impn_max:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_vcr_max:3;
        RBus_UInt32  hstate_loopfilter_sw:1;
        RBus_UInt32  hstate_status:3;
    };
}vdtop_hdetect_loopfilter_sw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hdetect_loopfilter_dctrl1:4;
        RBus_UInt32  hdetect_loopfilter_dctrl2:4;
    };
}vdtop_hdetect_loopfilter_dctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hsync_start:8;
    };
}vdtop_hsync_pulse_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hsync_width:8;
    };
}vdtop_hsync_pulse_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  hresampler_app_alpha_sel:1;
        RBus_UInt32  hresampler_app_sel:1;
        RBus_UInt32  hresampler_2up:1;
    };
}vdtop_chroma_hresampler_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_manu_mode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpll_kp_coef_0:6;
    };
}vdtop_hpll_kp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hpll_kp_coef_1:6;
    };
}vdtop_hpll_kp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hpll_kp_coef_2:6;
    };
}vdtop_hpll_kp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hpll_kp_coef_3:6;
    };
}vdtop_hpll_kp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hpll_kp_coef_4:6;
    };
}vdtop_hpll_kp_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hpll_kp_coef_5:6;
    };
}vdtop_hpll_kp_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_0:8;
    };
}vdtop_hpll_ki_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_1:8;
    };
}vdtop_hpll_ki_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_2:8;
    };
}vdtop_hpll_ki_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_3:8;
    };
}vdtop_hpll_ki_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_4:8;
    };
}vdtop_hpll_ki_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hpll_ki_coef_5:8;
    };
}vdtop_hpll_ki_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  second_pll_level_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  second_pll_gain_sel:2;
        RBus_UInt32  second_pll_clampgate_sel:1;
        RBus_UInt32  second_pll_phase_sel:1;
        RBus_UInt32  second_pll_w_hlock:1;
        RBus_UInt32  second_pll_en:1;
    };
}vdtop_second_pll_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_pll_sync_level:8;
        RBus_UInt32  second_pll_dc_add:12;
        RBus_UInt32  second_pll_dc_rm:12;
    };
}vdtop_second_pll_gain1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  second_comp_blevel:12;
        RBus_UInt32  second_comp_slevel:12;
    };
}vdtop_second_pll_gain2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  second_trailing:8;
        RBus_UInt32  second_dgain:12;
    };
}vdtop_second_pll_gain3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_backporch_start:8;
        RBus_UInt32  second_backporch_end:8;
        RBus_UInt32  second_hsync_tip_start:8;
        RBus_UInt32  second_hsync_tip_end:8;
    };
}vdtop_second_pll_gain4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  headswitch_debounce_en:1;
        RBus_UInt32  second_pll_kill_en:1;
        RBus_UInt32  under_detected_flag:1;
        RBus_UInt32  under_count_reset:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  under_line_err_thl:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  under_min_err_thl:10;
    };
}vdtop_under_new_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  under_field_err_thl:10;
    };
}vdtop_under_new_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  under_debounce_thl:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  under_debounce_max:10;
    };
}vdtop_under_new_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_detected_by_check_dc:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  coch_avg_line1_diff_thre_up:12;
        RBus_UInt32  coch_avg_line1_diff_thre_lo:12;
    };
}vdtop_dc_coch_seperate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_detect_lpf_reset:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  coch_detect_counter_up_thre:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  coch_detect_counter_lo_thre:10;
    };
}vdtop_dc_coch_seperate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hsync_rising:8;
    };
}vdtop_hsync_rising_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hsync_phase_offset:8;
    };
}vdtop_hsync_phase_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_hcount_start:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_gate_start:8;
    };
}vdtop_hsync_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_hcount_end:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_gate_end:8;
    };
}vdtop_hsync_gate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_vcount_start_o:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_tip_start:8;
    };
}vdtop_hsync_tip_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_vcount_end_o:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_tip_end:8;
    };
}vdtop_hsync_tip_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_vcount_start_e:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_rising_start:8;
    };
}vdtop_hsync_rising_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_gp_vcount_end_e:10;
        RBus_UInt32  res2:4;
        RBus_UInt32  hsync_rising_end:8;
    };
}vdtop_hsync_rising_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  backporch_start:8;
    };
}vdtop_backproch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  backporch_end:8;
    };
}vdtop_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hblank_start:8;
    };
}vdtop_hblank_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hblank_end:8;
    };
}vdtop_hblank_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_gate_start:8;
    };
}vdtop_burst_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_gate_end:8;
    };
}vdtop_burst_gate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hactive_start:8;
    };
}vdtop_hactive_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hactive_width:8;
    };
}vdtop_hactive_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_hstate_phase_max_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hdetect_hstate_3_phase_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdetect_hstate_4_phase_max:13;
    };
}vdtop_hdetect_err_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hdetect_hstate_5_phase_max:13;
        RBus_UInt32  hdetect_err04_th:8;
        RBus_UInt32  hdetect_err00_th:8;
    };
}vdtop_hdetect_err_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cpll_cgain_reset_en:1;
        RBus_UInt32  cpll_use_fine_or_final_hlock:1;
        RBus_UInt32  new_c_state_i:1;
        RBus_UInt32  new_cstate:1;
        RBus_UInt32  cstate_cntl:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cstate_status:3;
    };
}vdtop_cstate_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  s_b_level_fir_en:1;
        RBus_UInt32  level_fir_num_32_64_blevel:1;
        RBus_UInt32  level_fir_num_32_64_slevel:1;
        RBus_UInt32  coef_syncmidpt_fir_in:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  new_hpll_lpf_sel:1;
        RBus_UInt32  gate_iir_h_sel:1;
        RBus_UInt32  gate_iir_v_sel:1;
    };
}vdtop_hdetect_gate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  headswitch_err_sel:2;
        RBus_UInt32  hsync_refind_mask_err:1;
        RBus_UInt32  hsync_refind:1;
        RBus_UInt32  gate_iir_coef1:8;
    };
}vdtop_hdetect_gate_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hdetect_err07_th:8;
        RBus_UInt32  gate_iir_coef2:8;
    };
}vdtop_hdetect_gate_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hstate_err_thl:14;
        RBus_UInt32  res2:6;
        RBus_UInt32  hstate_err_counter:2;
        RBus_UInt32  vphase_status:8;
    };
}vdtop_hdetect_vphase_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_err05_th:8;
        RBus_UInt32  hdetect_err10_th:8;
        RBus_UInt32  hdetect_err01_th:8;
        RBus_UInt32  vphasediff_status:8;
    };
}vdtop_hdetect_vphasediff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  noise_vbi_thresh:8;
    };
}vdtop_noise_vbi_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coch_detected_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  coch_detected_frame:6;
    };
}vdtop_vbi_co_ch_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  coch_bp_diff_th:4;
    };
}vdtop_vbi_co_ch_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coch_line_count_th:8;
    };
}vdtop_vbi_co_ch_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  mv_window2_value:8;
    };
}vdtop_mv_detect_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ad_burst_gate_start:8;
    };
}vdtop_mv_burstgate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ad_burst_gate_end:8;
    };
}vdtop_mv_burstgate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cinverse_detect_control:3;
    };
}vdtop_color_inverse_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_err_constraint_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  h_err_constraint_high_th:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  h_err_constraint_low_th:14;
    };
}vdtop_h_err_constraint_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  h_err_constraint_hstate:3;
        RBus_UInt32  h_err_constraint_val:13;
    };
}vdtop_h_err_constraint_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_restore_hdto_en:1;
        RBus_UInt32  hdetect_set_new_hdto_n:3;
        RBus_UInt32  hdetect_restore_hdto_status:1;
        RBus_UInt32  hdetect_force_hdto_en:1;
        RBus_UInt32  hdetect_set_hdto_start:10;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdetect_restore_vcr_enable:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdetect_save_stable_hdto_start:10;
    };
}vdtop_h_restore_hdto_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hdetect_set_hdto_phase_err_th:14;
    };
}vdtop_h_restore_hdto_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrong_if_pc_detect_th:8;
        RBus_UInt32  sync_level_manu:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  sync_level_manu_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  wrong_if_pc_detect:1;
    };
}vdtop_if_wrong_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cpll_phase_thr_up:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cpll_phase_thr_dn:14;
    };
}vdtop_cpll_stability_observe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cpll_ampl_thr:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cerror_continune_same_sign_thr:6;
        RBus_UInt32  res3:13;
        RBus_UInt32  cpll_ampl_neg_flag:1;
        RBus_UInt32  cpll_phase_small_flag:1;
        RBus_UInt32  cpll_stable_flag:1;
    };
}vdtop_cpll_stability_observe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ampl_out_line_iir:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  phase_out_line_iir:14;
    };
}vdtop_cpll_stability_observe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  herror_pos_neg_value_diff_thr:16;
        RBus_UInt32  res1:2;
        RBus_UInt32  herror_continune_same_sign_thr:6;
        RBus_UInt32  herror_neg_pos_num_total_thr:4;
        RBus_UInt32  herror_neg_pos_value_total_thr:4;
    };
}vdtop_hpll_stability_observe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  herror_neg_value:16;
        RBus_UInt32  herror_pos_value:16;
    };
}vdtop_hpll_stability_observe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  herror_neg_pos_err_th:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  herror_neg_pos_num_win_thr:7;
        RBus_UInt32  res3:5;
        RBus_UInt32  herror_pos_neg_num_even:1;
        RBus_UInt32  herror_pos_neg_value_even:1;
        RBus_UInt32  herror_stable_state_hold_en:1;
    };
}vdtop_hpll_stability_observe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_h_phase_diff_sec1_end:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  statistic_h_phase_diff_sec1_start:9;
    };
}vdtop_h_phase_diff_statistics_set_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_h_phase_diff_sec2_end:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  statistic_h_phase_diff_sec2_start:9;
    };
}vdtop_h_phase_diff_statistics_set_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level1:13;
    };
}vdtop_h_phase_diff_statistics_set_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level3:13;
    };
}vdtop_h_phase_diff_statistics_set_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  statistic_h_phase_diff_hitso_level5:13;
    };
}vdtop_h_phase_diff_statistics_set_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_ready:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_2:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_1:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_0:10;
    };
}vdtop_h_phase_diff_sec1_histogram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_5:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_4:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_3:10;
    };
}vdtop_h_phase_diff_sec1_histogram_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_ready:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_2:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_1:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_0:10;
    };
}vdtop_h_phase_diff_sec2_histogram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_5:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_4:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_3:10;
    };
}vdtop_h_phase_diff_sec2_histogram_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iir_up_speed_on:1;
        RBus_UInt32  data_level_diff_iir_en:1;
        RBus_UInt32  statistic_data_level_diff_th:14;
        RBus_UInt32  res1:10;
        RBus_UInt32  statistic_data_level_line_num:6;
    };
}vdtop_data_level_statistics_set_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_ready:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_data_level_sec1_min:12;
        RBus_UInt32  statistic_data_level_sec1_max:12;
    };
}vdtop_data_level_statistics_sec1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec2_min:12;
        RBus_UInt32  statistic_data_level_sec2_max:12;
    };
}vdtop_data_level_statistics_sec2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec3_min:12;
        RBus_UInt32  statistic_data_level_sec3_max:12;
    };
}vdtop_data_level_statistics_sec3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec4_min:12;
        RBus_UInt32  statistic_data_level_sec4_max:12;
    };
}vdtop_data_level_statistics_sec4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec5_min:12;
        RBus_UInt32  statistic_data_level_sec5_max:12;
    };
}vdtop_data_level_statistics_sec5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec6_min:12;
        RBus_UInt32  statistic_data_level_sec6_max:12;
    };
}vdtop_data_level_statistics_sec6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec7_min:12;
        RBus_UInt32  statistic_data_level_sec7_max:12;
    };
}vdtop_data_level_statistics_sec7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  statistic_data_level_sec8_min:12;
        RBus_UInt32  statistic_data_level_sec8_max:12;
    };
}vdtop_data_level_statistics_sec8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  hlock_time:22;
    };
}vdtop_hlock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vlock_time:22;
    };
}vdtop_vlock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vstate_eq3_time:22;
    };
}vdtop_vstatelock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  no_signal_fall_time:22;
    };
}vdtop_no_signal_fall_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  old_vdetect_line_count_max:10;
        RBus_UInt32  num_old_vdetect_stable_fields:8;
        RBus_UInt32  vsync_cntl:2;
        RBus_UInt32  vsync_threshold:6;
    };
}vdtop_vsync_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  num_new_vdetect_stable_fields:8;
        RBus_UInt32  field_polarity:1;
        RBus_UInt32  flip_field:1;
        RBus_UInt32  veven_delayed:1;
        RBus_UInt32  vodd_delayed:1;
        RBus_UInt32  field_detect_mode:2;
        RBus_UInt32  vloop_tc3:2;
    };
}vdtop_vsync_time_const_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vloop_tc2:7;
    };
}vdtop_vsync_time_const2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vloop_tc1:8;
    };
}vdtop_vsync_time_const1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  serration_threshold:8;
    };
}vdtop_serration_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hvlock_field_cnt:4;
        RBus_UInt32  vlock_field_cnt:4;
        RBus_UInt32  hlock_field_cnt:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_delay_sel:1;
        RBus_UInt32  vsync_delay_en:1;
        RBus_UInt32  vsync_delay_1d:4;
        RBus_UInt32  vsync_delay_2d:4;
        RBus_UInt32  vsync_delay_2d_delta:4;
        RBus_UInt32  vsync_delay_2d_delta_en:1;
        RBus_UInt32  no_signal_dec:3;
    };
}vdtop_no_signal_dec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vactive_start:8;
    };
}vdtop_vactive_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vactive_height:8;
    };
}vdtop_vactive_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vsync_h_min:7;
    };
}vdtop_vsync_h_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vsync_h_max:7;
    };
}vdtop_vsync_h_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vsync_vbi_min:7;
    };
}vdtop_vsync_vbi_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vlock_wide_range:1;
        RBus_UInt32  vsync_vbi_max:7;
    };
}vdtop_vsync_vbi_lockout_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  vsync_ser_num_bigger_10_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_ser_num_max_def:6;
        RBus_UInt32  syncmidpt_dc_rough:1;
        RBus_UInt32  midpt_625_dc_th_en:1;
        RBus_UInt32  midpt_rough_vdetect_en:1;
        RBus_UInt32  vsync_625_midpt_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  syncmidpt_add_level:2;
    };
}vdtop_midpt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  syncmidpt_fix_add_value:8;
    };
}vdtop_midpt_fix_add_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  midpt_625_dc_th:8;
    };
}vdtop_midpt_625_dc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sync_dc_offset_th:12;
    };
}vdtop_sync_dc_offset_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sync_midpt_625:12;
    };
}vdtop_sync_dc_offset_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sync_midpt_h:12;
    };
}vdtop_sync_midpt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  sync_midpt_v:12;
    };
}vdtop_sync_midpt_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  new_vdetect_feature_max_core:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  raw_vdetect_max_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  no_signal_hpll_out:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  no_signal_to_0_sel:1;
        RBus_UInt32  hpll_no_signal_sel:1;
        RBus_UInt32  vlock_sel:1;
        RBus_UInt32  vdetect_pattern_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  adc_lpf_sel:3;
        RBus_UInt32  new_vdetect_line_length_en:1;
    };
}vdtop_sync_midpt_v2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coef2:10;
    };
}vdtop_adc_27_lpf_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coef4:10;
    };
}vdtop_adc_27_lpf_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef5:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coef6:10;
    };
}vdtop_adc_27_lpf_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef7:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coef8:10;
    };
}vdtop_adc_27_lpf_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef9:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coefa:10;
    };
}vdtop_adc_27_lpf_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coefb:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  adc_lpf_coefc:10;
    };
}vdtop_adc_27_lpf_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_vdetect_line_length:8;
    };
}vdtop_vdetect_line_lenght_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  new_vdetect_force_en:1;
        RBus_UInt32  no_vsync_flag_en:1;
        RBus_UInt32  new_vdetect_window_en:1;
        RBus_UInt32  new_vdetect_window_manu_en:1;
    };
}vdtop_vdetect_window_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  new_vdetect_window:12;
    };
}vdtop_vdetect_window_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_maxmin_data_rc_rate:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  new_vdetect_maxmin_data_rc_en:1;
        RBus_UInt32  new_vdetect_max_limit_value:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  new_vdetect_first_vsync_sel:1;
        RBus_UInt32  new_vdetect_max_limit_en:1;
        RBus_UInt32  new_vdetect_coch_en:1;
        RBus_UInt32  new_vdetect_en:1;
        RBus_UInt32  gate_sel:1;
        RBus_UInt32  vloss_detect_en:1;
        RBus_UInt32  new_vdetect_vcount_window_en:1;
        RBus_UInt32  new_vsync_offset_manul_mode_en:1;
        RBus_UInt32  new_vsync_offset_manul:3;
    };
}vdtop_new_vdetect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  old_hdetect_lpf_en:1;
        RBus_UInt32  new_vdetect_feature_th_manul_en:1;
        RBus_UInt32  no_vsync_flag:1;
        RBus_UInt32  new_vloss_flag:1;
        RBus_UInt32  force_new_vdetect_fine_window:1;
        RBus_UInt32  vsync_fine_window_state1_en:1;
        RBus_UInt32  res2:2;
    };
}vdtop_new_vdetect_loop_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  new_vdetect_loop_core_th:10;
    };
}vdtop_new_vdetect_loop_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  new_vdetect_diff_offset:12;
    };
}vdtop_new_vdetect_diff_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_fine_start1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  new_vdetect_loss_max:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  vsync_fine_start:10;
    };
}vdtop_vsync_fine_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_fine_end1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  new_vdetect_loss_up:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  vsync_fine_end:10;
    };
}vdtop_vsync_fine_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  no_vsync_th_hi:4;
        RBus_UInt32  no_vsync_th_lo:4;
    };
}vdtop_no_vsync_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  new_vdetect_loss_dn:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  new_vdetect_fine_vphase_th:10;
    };
}vdtop_new_vdetect_vphase_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_vdetect_feature_th1:8;
    };
}vdtop_new_vdetect_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_vdetect_feature_th2:8;
    };
}vdtop_new_vdetect_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_vdetect_feature_th3:8;
    };
}vdtop_new_vdetect_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_feature_th7:8;
        RBus_UInt32  new_vdetect_feature_th6:8;
        RBus_UInt32  new_vdetect_feature_th5:8;
        RBus_UInt32  new_vdetect_feature_th4:8;
    };
}vdtop_new_vdetect_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_refind_sel:2;
        RBus_UInt32  vsync_refind_toggle:1;
        RBus_UInt32  vstate0_direct_vsync:1;
        RBus_UInt32  vstate0_counter_num:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  vsync_stable_en:1;
        RBus_UInt32  vstate_reset:2;
        RBus_UInt32  vsync_refind_con_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  vsync_refind:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  vstate_2to3_er:4;
    };
}vdtop_vstate_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstate_2to3_th:8;
        RBus_UInt32  vstate_new2to3_en:1;
        RBus_UInt32  hsync_refind_min:7;
        RBus_UInt32  vstate1_err_sel:1;
        RBus_UInt32  hsync_refind_max:7;
        RBus_UInt32  vstate_1to2_er:4;
        RBus_UInt32  vstate_back1_er:4;
    };
}vdtop_vstate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hsync_reset_for_vsync:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  hsync_reset_for_data:10;
        RBus_UInt32  vstate_counter_num:8;
    };
}vdtop_vstate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vphase_error_window:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  vstate3_err_adjust_en:1;
        RBus_UInt32  vstate3_err_adjust_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  vsync_vertical_sum_num:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  vstate_status:2;
        RBus_UInt32  vstate_sw_en:1;
        RBus_UInt32  vstate_sw:2;
        RBus_UInt32  vcr_back_en:1;
    };
}vdtop_vstate_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  vstate3_counter_num:8;
        RBus_UInt32  vloop0_tc1:8;
    };
}vdtop_vloop0_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vloop0_tc2:7;
    };
}vdtop_vloop0_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vloop2_tc1:8;
    };
}vdtop_vloop2_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vloop2_tc2:7;
    };
}vdtop_vloop2_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vloop3_tc1:8;
    };
}vdtop_vloop3_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  vloop3_tc2:7;
    };
}vdtop_vloop3_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vloop0_tc3:2;
        RBus_UInt32  vloop2_tc3:2;
        RBus_UInt32  vloop3_tc3:2;
    };
}vdtop_vloop_tc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  flag_chrmaunlock_kill:1;
        RBus_UInt32  flag_user_kill:1;
        RBus_UInt32  flag_cgain_too_big_kill:1;
        RBus_UInt32  new_vdetect_lock_en:1;
        RBus_UInt32  vlock_count:3;
    };
}vdtop_vlock_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_detect_rst:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_detect_crlock_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_detect_count_thl:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  vsync_detect_core_thl:11;
        RBus_UInt32  vlock_window:8;
    };
}vdtop_vlock_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vlock_phase_plus:8;
    };
}vdtop_vlock_phase_plus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vline_adj_cnt_a:8;
    };
}vdtop_vline_adj_cnt_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vline_adj_cnt_b:8;
    };
}vdtop_vline_adj_cnt_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_hactive_width:8;
    };
}vdtop_table_hactive_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  vlines_the_same_cnt_thr:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  vsync_freerun_when_unstable_en:1;
        RBus_UInt32  vlines_the_same_flag:1;
        RBus_UInt32  vlines_diff_flag:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  vlines_freerun:10;
    };
}vdtop_vsync_pll_freerun_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fix_cgain:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  cagc_pll_input_sel:2;
        RBus_UInt32  cagc_data_input_sel:2;
        RBus_UInt32  cagc:8;
    };
}vdtop_chroma_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  ckill_sel:1;
        RBus_UInt32  user_ckill_mode:2;
        RBus_UInt32  vbi_ckill:1;
        RBus_UInt32  hlock_ckill:1;
        RBus_UInt32  chroma_kill:4;
    };
}vdtop_chroma_kill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  lose_acc_chromalock_level:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  chromalock_input_acc_en:1;
        RBus_UInt32  chromalock_input_acc_num:2;
        RBus_UInt32  lose_chromalock_count:4;
        RBus_UInt32  lose_chromalock_level:3;
        RBus_UInt32  lose_chromalock_ckill:1;
    };
}vdtop_chroma_lock_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cnew_gate_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  flag358_cresample_lpf_sel:2;
        RBus_UInt32  cagc_igain:2;
    };
}vdtop_chroma_loopfilter_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cresample_signed_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cloop_freq_offset_limit_en:1;
        RBus_UInt32  cloop_freq_offset_limit:12;
        RBus_UInt32  secam_cresample_lpf_sel:2;
        RBus_UInt32  cresample_lpf_sel:2;
        RBus_UInt32  cstate:3;
        RBus_UInt32  fixed_cstate:1;
    };
}vdtop_chroma_loopfilter_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  chroma_burst5or10:1;
        RBus_UInt32  fixed_burstgate:1;
        RBus_UInt32  cautopos:5;
    };
}vdtop_chroma_autopos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chromalock_cstate_en:1;
        RBus_UInt32  chromalock_cstate:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  ckill_vsync_delay_en:1;
        RBus_UInt32  ckill_lb_sel:1;
    };
}vdtop_ckill_lb_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ckill_level_user_offset_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ckill_level_user_offset:14;
        RBus_UInt32  ckill_level_user_mode_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ckill_level_user_mode_value:14;
    };
}vdtop_ckill_gain_kill_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  badedit_noisy_off_en:1;
        RBus_UInt32  badedit_in_noise_thr:8;
        RBus_UInt32  badedit_out_noise_thr:8;
        RBus_UInt32  fast_lock_en:1;
        RBus_UInt32  phase_fast_lock_en:1;
        RBus_UInt32  badedit_phase_lock_en:1;
        RBus_UInt32  badedit_pulse_detect:1;
        RBus_UInt32  bad_phase_detect:1;
        RBus_UInt32  badedit_line_num:3;
    };
}vdtop_cstate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  badedit_th:8;
    };
}vdtop_badedit_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  badphase_th:8;
    };
}vdtop_badphase_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cstate_line_num:8;
    };
}vdtop_cstate_line_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cpeak_gain_no_trunc_en:1;
        RBus_UInt32  cpeak_noisy_act_en_pll:1;
        RBus_UInt32  cpeak_noisy_act_en:1;
        RBus_UInt32  cpeak_noise_thr2:8;
        RBus_UInt32  cpeak_noise_thr1:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  chroma_peak_en_pll:1;
        RBus_UInt32  new_cgain_level_en:1;
        RBus_UInt32  chroma_peak_en:1;
        RBus_UInt32  chroma_agc_peak_cnt:6;
    };
}vdtop_chroma_agc_peak_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  chroma_agc_peak_nominal:8;
    };
}vdtop_chroma_agc_peak_nominal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  close_ckill_loopfilter:1;
        RBus_UInt32  cagc_upper_xroot2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cagc_upper:14;
    };
}vdtop_close_ckill_loopfilter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cagc_peak_err_adj_en:1;
        RBus_UInt32  cagc_burst_err_adj_en:1;
        RBus_UInt32  cagc_peak_err_diff_sel:6;
    };
}vdtop_cagc_peak_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cagc_burst_err_diff_sel:6;
    };
}vdtop_cagc_peak_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cdata_measure_keep_line_num:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  cdata_measure_thr:9;
        RBus_UInt32  cdata_measure_big:1;
        RBus_UInt32  cdata_measure_lpf_en:1;
        RBus_UInt32  cagc_peak_luma_ratio:6;
    };
}vdtop_cagc_peak_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  cb_delay:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_delay:3;
    };
}vdtop_chroma_delay_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  flag_burst_x4:1;
        RBus_UInt32  burst_cgain_x4_en:1;
    };
}vdtop_burst_cgain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_cgain_mag_th:8;
    };
}vdtop_burst_cgain_mag_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag358_iir_en:1;
        RBus_UInt32  flag358_iir_cunlock_en:1;
        RBus_UInt32  flag358_cdto_inc:30;
    };
}vdtop_flag358_cdto_inc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_location_fix_en:1;
        RBus_UInt32  burst_location_sel_clock:1;
        RBus_UInt32  burst_location_selreg_en:1;
        RBus_UInt32  normal_burst_locationreg_en:1;
        RBus_UInt32  burst_location_sel_modify_sel:3;
        RBus_UInt32  burst_location_sel_modify_en:1;
        RBus_UInt32  burst_location_center_modify_sel:3;
        RBus_UInt32  burst_location_center_modify_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  burst_location_fix:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  burst_location_sel:2;
        RBus_UInt32  burst_location_lpf_reset:1;
        RBus_UInt32  burst_location_rst_en:1;
        RBus_UInt32  auto_burst_location_en:1;
        RBus_UInt32  new_coef_sel:1;
    };
}vdtop_separate_443_358_new_function_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  burst_location_result:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  normal_burst_location:11;
    };
}vdtop_separate_443_358_new_function_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wide_burst_location_modify_sel:3;
        RBus_UInt32  wide_burst_location_modify_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  wide_burst_location_end:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  wide_burst_location_endreg_en:1;
        RBus_UInt32  wide_burst_location_startreg_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  wide_burst_location_start:11;
    };
}vdtop_separate_443_358_new_function_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  burst_location_sel_status:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  normal_burst_location_status:11;
    };
}vdtop_burst_location_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  wide_burst_location_end_status:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  wide_burst_location_start_status:11;
    };
}vdtop_burst_location_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sep_hsync_start:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  sep_hsync_end:11;
    };
}vdtop_burst_location_hsync_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  burst_location_auto_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  burst_location_enable_mode:8;
        RBus_UInt32  burst_location_magnitude_thr:8;
        RBus_UInt32  burst_location_auto_thr:8;
    };
}vdtop_burst_location_fw_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_path_eq_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  y_path_coef_num:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  y_path_coef_value:11;
    };
}vdtop_y_path_eq_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  y_path_coef_num_r:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  y_path_coef_value_r:11;
    };
}vdtop_y_path_eq_filter_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  flag625_vsync_l_sel:1;
        RBus_UInt32  flag625_vsync_l_th:1;
        RBus_UInt32  palm_atone_counter:6;
    };
}vdtop_palm_flag_compensation1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  palm_atone_threshold:8;
    };
}vdtop_palm_flag_compensation2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  colour_mode_dark_check:1;
        RBus_UInt32  colour_mode_dark_set:3;
        RBus_UInt32  auto_mode_en:1;
        RBus_UInt32  auto_625only_en:1;
        RBus_UInt32  auto_burst_switch_625only:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  state_machine_reset:1;
        RBus_UInt32  manual_mode_select:3;
    };
}vdtop_manual_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  set_mode_status:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  decision_mode_status:3;
    };
}vdtop_mode_detection_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  disable_mode_en:1;
        RBus_UInt32  disable_mode:1;
        RBus_UInt32  statistic_number:6;
    };
}vdtop_statistic_and_disable_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  prefer_ntsc50_paln:1;
        RBus_UInt32  prefer_ntsc443_pal60:1;
        RBus_UInt32  prefer_secam_pali:1;
        RBus_UInt32  prefer_ntsc_palm:1;
        RBus_UInt32  prefer_ntsc50_paln_en:1;
        RBus_UInt32  prefer_ntsc443_pal60_en:1;
        RBus_UInt32  prefer_secam_pali_en:1;
        RBus_UInt32  prefer_ntsc_palm_en:1;
    };
}vdtop_prefer_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fix_625flag_en:1;
        RBus_UInt32  fix_443flag_en:1;
        RBus_UInt32  fix_palorflag_en:1;
        RBus_UInt32  fix_secamflag_en:1;
        RBus_UInt32  fix_625_h:1;
        RBus_UInt32  fix_443_h:1;
        RBus_UInt32  fix_palor_h:1;
        RBus_UInt32  fix_secam_h:1;
    };
}vdtop_state_machine_fix_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hactivestartreg_en:1;
        RBus_UInt32  hpixelreg_en:1;
        RBus_UInt32  colourmodereg_en:1;
        RBus_UInt32  hagcreg_en:1;
        RBus_UInt32  vline625reg_en:1;
        RBus_UInt32  cdtomem_reg_en:1;
        RBus_UInt32  vsyncreg_en:1;
        RBus_UInt32  ped_reg_en:1;
    };
}vdtop_vd_basic_register_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  switch_palo_palm_method:2;
        RBus_UInt32  auto_secam_pali_method:2;
        RBus_UInt32  secam_flag_freq_disable:1;
        RBus_UInt32  statistic_multiplier:3;
    };
}vdtop_auto_mode_s_m_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sv_cr1delayreg_en:1;
        RBus_UInt32  sv_cb1delayreg_en:1;
        RBus_UInt32  sv_y1delayreg_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  sv_cr1delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  sv_cb1delay:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  sv_y1delay:6;
    };
}vdtop_auto_pos_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  new_cr1delay_en:1;
        RBus_UInt32  new_cb1delay_en:1;
        RBus_UInt32  new_y1delay_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr1delayreg_en:1;
        RBus_UInt32  cb1delayreg_en:1;
        RBus_UInt32  y1delayreg_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr1delay:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  cb1delay:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  y1delay:6;
    };
}vdtop_auto_pos_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_pos_modify_en:1;
        RBus_UInt32  auto_pos_mode_sel:3;
        RBus_UInt32  auto_ycdelay_modify_en:1;
        RBus_UInt32  auto_ycdelay_mode_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ckill_cr1delayreg_en:1;
        RBus_UInt32  ckill_cb1delayreg_en:1;
        RBus_UInt32  ckill_y1delayreg_en:1;
        RBus_UInt32  ckill_cr1delay:6;
        RBus_UInt32  ckill_cb1delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ckill_y1delay:6;
    };
}vdtop_auto_pos_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fix_358flag_en:1;
        RBus_UInt32  fix_358_h:1;
        RBus_UInt32  auto_443_358_method_625:2;
        RBus_UInt32  auto_443_358_method_525:2;
        RBus_UInt32  auto_sel_no_burst_625:2;
    };
}vdtop_flag358_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  no_burst_mag_th:8;
    };
}vdtop_no_burst_mag_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  no_burst_mag_filter_th:8;
    };
}vdtop_no_burst_mag_filter_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_mag_trig_offset:4;
        RBus_UInt32  no_burst_flag:1;
        RBus_UInt32  paln_flag_new:1;
        RBus_UInt32  burst_win_error:1;
        RBus_UInt32  no_burst_443_en:1;
    };
}vdtop_no_burst_443_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  flag358_secam_phase_diff_hcount_en:1;
        RBus_UInt32  flag358_phase_diff_hcount:7;
    };
}vdtop_flag358_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  flag358_secam_phase_diff_dr:8;
    };
}vdtop_flag358_secam_phase_diff_dr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  flag358_secam_phase_diff_db:8;
    };
}vdtop_flag358_secam_phase_diff_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_mag_th_358:8;
    };
}vdtop_burst_mag_th_358_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_cagc_en:1;
        RBus_UInt32  table_vline_625:1;
        RBus_UInt32  table_hpixel:2;
        RBus_UInt32  table_ped:1;
        RBus_UInt32  table_colour_mode:3;
    };
}vdtop_auto_mode_table1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_hagc:8;
    };
}vdtop_auto_mode_table2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_hactive_start:8;
    };
}vdtop_auto_mode_table3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_vactive_start:8;
    };
}vdtop_auto_mode_table4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  table_vactive_height:8;
    };
}vdtop_auto_mode_table5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  table_cdto:30;
    };
}vdtop_auto_mode_table6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vline_625_vloop_clr_en:1;
        RBus_UInt32  vline_625_src_sel:1;
        RBus_UInt32  new_625flag_window:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_625flag_div_thr:10;
        RBus_UInt32  flag_625_counter:8;
    };
}vdtop_flag_625_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  flag_443_counter:8;
    };
}vdtop_flag_443_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_flag_counter:8;
    };
}vdtop_secam_flag_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  palm_flag_counter:8;
    };
}vdtop_palm_flag_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_valid_counter:8;
    };
}vdtop_burst_valid_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  midpoint_adjustment:8;
    };
}vdtop_midpoint_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  freq_flag_threshold_tune:8;
    };
}vdtop_freq_flag_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  frequency_valid_upper_limit:8;
    };
}vdtop_freq_valid_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  condition_enable:1;
        RBus_UInt32  frequency_valid_inner_limit:7;
    };
}vdtop_freq_valid_inner_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  frequency_valid_lower_limit:8;
    };
}vdtop_freq_valid_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_flag_frequency_upper_limit:8;
    };
}vdtop_secam_flag_counter_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_flag_frequency_lower_limit:8;
    };
}vdtop_secam_flag_counter_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  palm_flag_limit_en:1;
        RBus_UInt32  pal_sw_acc_input_polar:1;
        RBus_UInt32  pal_sw_input_sel:1;
        RBus_UInt32  palm_sw_acc_input_polar:1;
        RBus_UInt32  palm_sw_input_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pal_flag_threshold:13;
        RBus_UInt32  palm_flag_phase_adjust:8;
    };
}vdtop_palm_flag_phase_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  burst_mag_trigger:4;
        RBus_UInt32  burst_mag_threshold:4;
    };
}vdtop_burst_lower_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vsync_select:1;
        RBus_UInt32  secam_frequency_valid_enable:1;
        RBus_UInt32  auto_noburst_palflag_off:1;
        RBus_UInt32  burst_noise_weighting_auto:1;
        RBus_UInt32  burst_noise_weighting:4;
    };
}vdtop_burst_mag_choice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  agc_gate_kill_sync_white_en:1;
        RBus_UInt32  new_358_flag_cordic:1;
        RBus_UInt32  new_358_flag_cos_sin:1;
        RBus_UInt32  res2:5;
    };
}vdtop_new_358_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  new_dto_358_cnt_up:11;
    };
}vdtop_new_358_cnt_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  new_dto_358_cnt_dn:11;
    };
}vdtop_new_358_cnt_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  sep_count_th:10;
    };
}vdtop_sep_count_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sep_burst_start:11;
    };
}vdtop_sep_burst_start0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sep_burst_end:11;
    };
}vdtop_sep_burst_end0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  sep_core_burst_rst:1;
        RBus_UInt32  sep_core_burst_rst_en:1;
        RBus_UInt32  res2:8;
    };
}vdtop_sep_burst_ro_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_443_core_burst_hsync:8;
        RBus_UInt32  sep_358_core_burst_hsync:8;
        RBus_UInt32  sep_443_core_burst:8;
        RBus_UInt32  sep_358_core_burst:8;
    };
}vdtop_sep_burst_ro_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  sep_pal_secam_core_burst_rst:1;
        RBus_UInt32  sep_pal_secam_core_burst_rst_en:1;
        RBus_UInt32  sep_pal_secam_core_burst:8;
    };
}vdtop_sep_burst_ro3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sep_443_thl:8;
        RBus_UInt32  sep_358_thl:8;
    };
}vdtop_sep_burst_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  secam_new_condition:1;
        RBus_UInt32  sep_secam_f_sel:1;
        RBus_UInt32  sep_secam_thl:8;
        RBus_UInt32  sep_secam_thl_ratio:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  power_secam_flag:1;
        RBus_UInt32  power_443_flag:1;
        RBus_UInt32  power_358_flag:1;
    };
}vdtop_sep_burst_flag1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pk_foraudio:1;
        RBus_UInt32  mode_secam2_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mode_443358pk_sel:2;
    };
}vdtop_automode_443358pk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_badedit_noisy_off_en:1;
        RBus_UInt32  dark_badedit_phase_lock_en:1;
        RBus_UInt32  dark_fast_lock_en:1;
        RBus_UInt32  dark_phase_fast_lock_en:1;
        RBus_UInt32  dark_fixed_cstate:1;
        RBus_UInt32  dark_cstate:3;
        RBus_UInt32  dark_chromalock_cstate_en:1;
        RBus_UInt32  dark_chromalock_cstate:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  dark_cresample_signed_en:1;
        RBus_UInt32  dark_cagc:8;
        RBus_UInt32  dark_cagc_pll_input_sel:2;
        RBus_UInt32  dark_cagc_en:1;
        RBus_UInt32  dark_fix_cgain:1;
        RBus_UInt32  dark_cpll_cdto_change_en:1;
        RBus_UInt32  dark_cpll_cdto_change_mode:3;
    };
}vdtop_dark_cpll_cdetect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dark_cpll_cdto_change_value:30;
    };
}vdtop_dark_cpll_cdetect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dark_palm_flag_counter:8;
        RBus_UInt32  dark_palm_flag_phase_adjust:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_palsw_level:2;
        RBus_UInt32  dark_palm_flag_limit_en:1;
        RBus_UInt32  dark_pal_sw_acc_input_polar:1;
        RBus_UInt32  dark_pal_sw_input_sel:1;
        RBus_UInt32  dark_palm_sw_acc_input_polar:1;
        RBus_UInt32  dark_palm_sw_input_sel:1;
    };
}vdtop_dark_cpll_pal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dark_pal_flag_threshold:13;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_chromalock_input_acc_en:1;
        RBus_UInt32  dark_chromalock_input_acc_num:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  dark_lose_acc_chromalock_level:3;
        RBus_UInt32  dark_lose_chromalock_count:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  dark_lose_chromalock_level:3;
    };
}vdtop_dark_cpll_chromalock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dark_cpll_decide_mode_error:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_cpll_decide_mode:3;
        RBus_UInt32  dark_cpll_vsync_num:8;
        RBus_UInt32  dark_cpll_chromalock_sel:1;
        RBus_UInt32  dark_cpll_mode_en_pali:1;
        RBus_UInt32  dark_cpll_mode_en_pal60:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc443:1;
        RBus_UInt32  dark_cpll_mode_en_paln:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc50:1;
        RBus_UInt32  dark_cpll_mode_en_palm:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc:1;
        RBus_UInt32  dark_cpll_fix_mode_en:1;
        RBus_UInt32  dark_cpll_user_mode:3;
        RBus_UInt32  dark_cpll_mode:2;
        RBus_UInt32  dark_cpll_auto_run:1;
        RBus_UInt32  dark_cpll_start:1;
    };
}vdtop_dark_cpll_controll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chromalock_acc_dark:1;
        RBus_UInt32  chromalock_dark:1;
        RBus_UInt32  pal_flag_dark:1;
        RBus_UInt32  palm_flag_dark:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dark_cpll_loop_done:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_cpll_pali_palm_flag:1;
        RBus_UInt32  dark_cpll_pal60_palm_flag:1;
        RBus_UInt32  dark_cpll_ntsc443_palm_flag:1;
        RBus_UInt32  dark_cpll_paln_palm_flag:1;
        RBus_UInt32  dark_cpll_ntsc50_palm_flag:1;
        RBus_UInt32  dark_cpll_palm_palm_flag:1;
        RBus_UInt32  dark_cpll_ntsc_palm_flag:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dark_cpll_pali_pal_flag:1;
        RBus_UInt32  dark_cpll_pal60_pal_flag:1;
        RBus_UInt32  dark_cpll_ntsc443_pal_flag:1;
        RBus_UInt32  dark_cpll_paln_pal_flag:1;
        RBus_UInt32  dark_cpll_ntsc50_pal_flag:1;
        RBus_UInt32  dark_cpll_palm_pal_flag:1;
        RBus_UInt32  dark_cpll_ntsc_pal_flag:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dark_cpll_pali_lock:1;
        RBus_UInt32  dark_cpll_pal60_lock:1;
        RBus_UInt32  dark_cpll_ntsc443_lock:1;
        RBus_UInt32  dark_cpll_paln_lock:1;
        RBus_UInt32  dark_cpll_ntsc50_lock:1;
        RBus_UInt32  dark_cpll_palm_lock:1;
        RBus_UInt32  dark_cpll_ntsc_lock:1;
    };
}vdtop_dark_cpll_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dark_cpll_burst_magnitude:8;
    };
}vdtop_dark_cpll_burstmag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  hstate_err_irq_en:1;
        RBus_UInt32  vd_irq_en:1;
        RBus_UInt32  vcr_irq_en:1;
        RBus_UInt32  nosig_irq_en:1;
        RBus_UInt32  mode_irq_en:1;
        RBus_UInt32  proscan_irq_en:1;
        RBus_UInt32  noisy_irq_en:1;
        RBus_UInt32  chromalock_irq_en:1;
        RBus_UInt32  vlock_irq_en:1;
        RBus_UInt32  hlock_irq_en:1;
    };
}vdtop_irq_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vd_scene_change_irq_en:1;
        RBus_UInt32  ddr_addr_irq_en:1;
        RBus_UInt32  noisy_vbi_irq_en:1;
        RBus_UInt32  coch_irq_en:1;
        RBus_UInt32  mv_irq_en:1;
        RBus_UInt32  field_irq_en:1;
    };
}vdtop_irq_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ad1_irq_sel:1;
        RBus_UInt32  ad2_irq_sel:1;
        RBus_UInt32  ad3_irq_sel:1;
        RBus_UInt32  ad4_irq_sel:1;
        RBus_UInt32  ad1_over_irq_en:1;
        RBus_UInt32  ad1_under_irq_en:1;
        RBus_UInt32  ad2_over_irq_en:1;
        RBus_UInt32  ad2_under_irq_en:1;
        RBus_UInt32  ad3_over_irq_en:1;
        RBus_UInt32  ad3_under_irq_en:1;
        RBus_UInt32  ad4_over_irq_en:1;
        RBus_UInt32  ad4_under_irq_en:1;
    };
}vdtop_irq_mask3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vcr_irq:1;
        RBus_UInt32  nosig_irq:1;
        RBus_UInt32  mode_irq:1;
        RBus_UInt32  proscan_irq:1;
        RBus_UInt32  noisy_irq:1;
        RBus_UInt32  chromalock_irq:1;
        RBus_UInt32  vlock_irq:1;
        RBus_UInt32  hlock_irq:1;
    };
}vdtop_irq_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  hstate_err_irq:1;
        RBus_UInt32  vd_scene_change_irq:1;
        RBus_UInt32  ddr_addr_irq:1;
        RBus_UInt32  noisy_vbi_irq:1;
        RBus_UInt32  coch_irq:1;
        RBus_UInt32  mv_irq:1;
        RBus_UInt32  field_irq:1;
    };
}vdtop_irq_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ad1_overflow_irq:1;
        RBus_UInt32  ad1_underflow_irq:1;
        RBus_UInt32  ad2_overflow_irq:1;
        RBus_UInt32  ad2_underflow_irq:1;
        RBus_UInt32  ad3_overflow_irq:1;
        RBus_UInt32  ad3_underflow_irq:1;
        RBus_UInt32  ad4_overflow_irq:1;
        RBus_UInt32  ad4_underflow_irq:1;
    };
}vdtop_irq_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  adc_over_threh:4;
        RBus_UInt32  adc_under_threh:4;
    };
}vdtop_adc_limit_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value_max_thr:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_value_min_thr:10;
        RBus_UInt32  ad1_value_small:1;
        RBus_UInt32  ad1_value_big:1;
        RBus_UInt32  ad2_value_small:1;
        RBus_UInt32  ad2_value_big:1;
        RBus_UInt32  ad3_value_small:1;
        RBus_UInt32  ad3_value_big:1;
        RBus_UInt32  ad4_value_small:1;
        RBus_UInt32  ad4_value_big:1;
    };
}vdtop_adc_over_under_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  clampagc_md_y_small:1;
        RBus_UInt32  clampagc_md_y_big:1;
        RBus_UInt32  clampagc_md_c_small:1;
        RBus_UInt32  clampagc_md_c_big:1;
        RBus_UInt32  clampagc_md_r_small:1;
        RBus_UInt32  clampagc_md_r_big:1;
        RBus_UInt32  clampagc_md_g_small:1;
        RBus_UInt32  clampagc_md_g_big:1;
        RBus_UInt32  clampagc_md_b_small:1;
        RBus_UInt32  clampagc_md_b_big:1;
    };
}vdtop_dgain_out_over_under_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dgain_out_data_max_thr:12;
        RBus_UInt32  dgain_out_data_min_thr:12;
    };
}vdtop_dgain_out_over_under_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ld_pause_detect:1;
        RBus_UInt32  ldp_det_en:1;
        RBus_UInt32  ldp_switch_en:1;
        RBus_UInt32  ldpaus_th:5;
    };
}vdtop_ldpause_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coch_en:1;
        RBus_UInt32  disp_freerun_sel:1;
        RBus_UInt32  vd_out_dvalid_sel_d1:1;
        RBus_UInt32  vcr_disable:1;
        RBus_UInt32  freerun_sel:1;
        RBus_UInt32  lock_h_on_no_signal:1;
        RBus_UInt32  disable_blue_screen_when_vcr:1;
        RBus_UInt32  detect_vcr_when_h_unlock:1;
    };
}vdtop_vcr_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cenable_line_count:8;
    };
}vdtop_cenable_line_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  auto_3dchange_vcr:1;
        RBus_UInt32  auto_3dchange_noisy:1;
        RBus_UInt32  field_toggle_en:1;
        RBus_UInt32  cbcr_ini_mux:1;
        RBus_UInt32  res2:2;
    };
}vdtop_signal_stm_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  cdet_phase_err_status:14;
    };
}vdtop_cdetect_phase_err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sw_comp:2;
        RBus_UInt32  sw_pr_r:2;
        RBus_UInt32  sw_pb_b:2;
        RBus_UInt32  sw_g:2;
    };
}vdtop_ad_sw_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  clamp_ad1:2;
        RBus_UInt32  clamp_ad2:2;
        RBus_UInt32  clamp_ad3:2;
        RBus_UInt32  clamp_ad4:2;
    };
}vdtop_clamp_updn_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  clamp_a_up_en:1;
        RBus_UInt32  clamp_a_dn_en:1;
        RBus_UInt32  clamp_b_up_en:1;
        RBus_UInt32  clamp_b_dn_en:1;
        RBus_UInt32  clamp_c_up_en:1;
        RBus_UInt32  clamp_c_dn_en:1;
        RBus_UInt32  clamp_d_up_en:1;
        RBus_UInt32  clamp_d_dn_en:1;
    };
}vdtop_clamp_rgb_updn_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  aa3_en:1;
        RBus_UInt32  fb_th:3;
        RBus_UInt32  fb_delay:4;
    };
}vdtop_fsw_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  fb2rgb_dly:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  rgb2cvbs_dly:6;
    };
}vdtop_fsw_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  outfifo_444_sel:1;
        RBus_UInt32  scart_en:1;
        RBus_UInt32  yout_limit:1;
        RBus_UInt32  fb_inv:1;
        RBus_UInt32  cout_limit:1;
        RBus_UInt32  out444_sel:1;
        RBus_UInt32  aa422_en:1;
        RBus_UInt32  fb_sw:1;
        RBus_UInt32  fb_en:1;
    };
}vdtop_fsw_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fb_thmax:4;
        RBus_UInt32  fb_thmin:4;
    };
}vdtop_fsw_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  contrast2:10;
    };
}vdtop_luma_contrast2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  brightness2:10;
    };
}vdtop_luma_brightness2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cr_saturation:10;
    };
}vdtop_chroma_saturation2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cb_saturation:10;
    };
}vdtop_cb_sat_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  peak_range2:2;
        RBus_UInt32  peak_gain2:3;
        RBus_UInt32  peak_en2:1;
    };
}vdtop_luma_peaking2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fbgain_en:1;
        RBus_UInt32  fbgain:7;
    };
}vdtop_fsw_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  scart_vbi_rgb_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  fb_status:3;
    };
}vdtop_fsw_input_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_reduce_ratio_c:8;
        RBus_UInt32  chroma_gain_reduce_ratio_r:8;
        RBus_UInt32  chroma_gain_reduce_ratio_g:8;
        RBus_UInt32  chroma_gain_reduce_ratio_b:8;
    };
}vdtop_chroma_reduce_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  chroma_gain_reduce_c_en:1;
        RBus_UInt32  chroma_gain_reduce_r_en:1;
        RBus_UInt32  chroma_gain_reduce_g_en:1;
        RBus_UInt32  chroma_gain_reduce_b_en:1;
    };
}vdtop_chroma_reduce_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  yorr_in_offset_status:12;
    };
}vdtop_adcr_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  uorg_in_offset_status:12;
    };
}vdtop_adcg_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vorb_in_offset_status:12;
    };
}vdtop_adcb_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rgb_output_en:1;
        RBus_UInt32  res2:7;
    };
}vdtop_adc_gain_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  offset_r:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  gain_r:10;
    };
}vdtop_adc_gain_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  offset_g:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  gain_g:10;
    };
}vdtop_adc_gain_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  offset_b:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  gain_b:10;
    };
}vdtop_adc_gain_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_r1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  component_color_matrix_r2:11;
    };
}vdtop_color_matrix_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_r3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  component_color_matrix_g1:11;
    };
}vdtop_color_matrix_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_g2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  component_color_matrix_g3:11;
    };
}vdtop_color_matrix_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_b1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  component_color_matrix_b2:11;
    };
}vdtop_color_matrix_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  component_color_matrix_b3:11;
    };
}vdtop_color_matrix_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  r_prblevel:12;
    };
}vdtop_clamp_test_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  g_blevel:12;
    };
}vdtop_clamp_test_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  b_pbblevel:12;
    };
}vdtop_clamp_test_reg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  comp_blevel:12;
    };
}vdtop_clamp_test_reg6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  comp_slevel:12;
    };
}vdtop_clamp_test_reg8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vbi_blevel:12;
    };
}vdtop_clamp_test_reg11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hphase_err_status:14;
    };
}vdtop_hdetect_phase_err_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  avout_fifo_sel:1;
        RBus_UInt32  avout_fifo_rd_ptr:11;
    };
}vdtop_avout_fifo_rd_ptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_comp_manu_add:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  blank_level_comp_manu:12;
    };
}vdtop_blank_level_manu_comp_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_c_manu:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  blank_level_r_manu:12;
    };
}vdtop_blank_level_manu_c_r_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_g_manu:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  blank_level_b_manu:12;
    };
}vdtop_blank_level_manu_g_b_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test1:31;
        RBus_UInt32  factory_flag:1;
    };
}vdtop_fpga_test_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}vdtop_fpga_test_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}vdtop_fpga_test_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test4:32;
    };
}vdtop_fpga_test_reg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test5:32;
    };
}vdtop_fpga_test_reg5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test6:32;
    };
}vdtop_fpga_test_reg6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test7:32;
    };
}vdtop_fpga_test_reg7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test8:32;
    };
}vdtop_fpga_test_reg8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  secam_y_fir_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  secam_y_hpf_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  secam_y_lpf_sel:3;
        RBus_UInt32  drdb_freq_const:1;
        RBus_UInt32  drdb_vlpf_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  secam_flag_sel:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  secam_notch_filter:2;
    };
}vdtop_secam_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dr_offset:8;
    };
}vdtop_secam_drfreq_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  db_offset:8;
    };
}vdtop_secam_dbfreq_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_phase_diff_hcount_en:1;
        RBus_UInt32  secam_phase_diff_hcount:7;
    };
}vdtop_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_phase_diff_dr:8;
    };
}vdtop_phase_diff_dr_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_phase_diff_db:8;
    };
}vdtop_phase_diff_db_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_gain_drdb_en:1;
        RBus_UInt32  secam_gain_drdb:7;
    };
}vdtop_drdb_gain_table_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_gain_y_en:1;
        RBus_UInt32  secam_gain_y:7;
    };
}vdtop_y_gain_table_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  secam_gain_delay:5;
    };
}vdtop_secam_gain_dly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  secam_gain_debug_en:1;
        RBus_UInt32  secam_gain_debug:7;
    };
}vdtop_secam_gain_table_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_secam_phase_diff_hcount_en:1;
        RBus_UInt32  new_secam_phase_diff_hcount:7;
    };
}vdtop_new_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_secam_phase_diff_dr:8;
    };
}vdtop_new_secam_phase_diff_dr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  new_secam_phase_diff_db:8;
    };
}vdtop_new_secam_phase_diff_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  new_secam_cdto_inc:30;
    };
}vdtop_new_secam_cdto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gp_en:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  secam_gp_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_gp_thl:10;
    };
}vdtop_secam_gp_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdec_ps_disp_27_en:1;
        RBus_UInt32  hresampler_combi_delay:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  vd_output_135_sel:1;
        RBus_UInt32  vd_output_27_repeat_sel:1;
        RBus_UInt32  vd_output_27_repeat_en:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  v8format_sel:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  ps_updn_swap:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  fifo_initialization:1;
    };
}vdtop_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ps_540_coe_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ps_540_select_tap:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  ps_540_coe_modify:7;
        RBus_UInt32  res4:6;
        RBus_UInt32  fifo_full_status:1;
        RBus_UInt32  fifo_empty_status:1;
    };
}vdtop_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ps_psel_status:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  ps_dn_status:1;
        RBus_UInt32  ps_up_status:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  ps_ndiv_status:5;
        RBus_UInt32  pll_i_gain:8;
    };
}vdtop_i_gain_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  fifo_wo_ps:1;
        RBus_UInt32  fifo_depth_wo_ps:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  swallow_freq_sel:3;
        RBus_UInt32  swallow_on_vsync:1;
        RBus_UInt32  ndivload_en:1;
        RBus_UInt32  ps_up_en:1;
        RBus_UInt32  ps_dn_en:1;
        RBus_UInt32  pll_div:4;
    };
}vdtop_misc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  fifo_depth_min_clr:1;
        RBus_UInt32  fifo_depth_min_status:8;
    };
}vdtop_fifo_depth_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  fifo_depth_max_clr:1;
        RBus_UInt32  fifo_depth_max_status:8;
    };
}vdtop_fifo_depth_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ps_up_i:1;
        RBus_UInt32  ps_dn_i:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ps_divload:1;
        RBus_UInt32  ps_pselload:1;
    };
}vdtop_pll_debug_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pll_debug_en:1;
        RBus_UInt32  ps_psel:3;
        RBus_UInt32  ps_ndiv:4;
    };
}vdtop_pll_debug_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  ps_fix_en:1;
        RBus_UInt32  ps_fix_value:8;
        RBus_UInt32  ps_new_kikp:1;
        RBus_UInt32  ps_new_kp:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  cnt_en:1;
        RBus_UInt32  period_sel:2;
        RBus_UInt32  lpf_en:1;
        RBus_UInt32  k_sel:2;
    };
}vdtop_disp_fsync_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_wo_ps_read_repeat_en:1;
        RBus_UInt32  fifo_wo_ps_clk_jump:1;
        RBus_UInt32  fifo_wo_ps_err_act:1;
        RBus_UInt32  fifo_wo_ps_adapt:1;
        RBus_UInt32  fifo_wo_ps_hlen_min:12;
        RBus_UInt32  fifo_depth_wo_ps_min:8;
        RBus_UInt32  fifo_depth_wo_ps_max:8;
    };
}vdtop_fifo_wo_ps_func_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fifo_wo_ps_ps_up_i1:1;
        RBus_UInt32  fifo_wo_ps_ps_dn_i1:1;
        RBus_UInt32  fifo_wo_ps_ps_pselload1:1;
        RBus_UInt32  fifo_wo_ps_ps_divload1:1;
        RBus_UInt32  fifo_wo_ps_ps_psel1:3;
        RBus_UInt32  fifo_wo_ps_ps_ndiv1:5;
        RBus_UInt32  fifo_wo_ps_ps_up_i0:1;
        RBus_UInt32  fifo_wo_ps_ps_dn_i0:1;
        RBus_UInt32  fifo_wo_ps_ps_pselload0:1;
        RBus_UInt32  fifo_wo_ps_ps_divload0:1;
        RBus_UInt32  fifo_wo_ps_ps_psel0:3;
        RBus_UInt32  fifo_wo_ps_ps_ndiv0:5;
    };
}vdtop_fifo_wo_ps_clk_state_parameter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  stable_fifo_depth:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  fifo_clk_state:1;
        RBus_UInt32  fifo_out_line_len:12;
    };
}vdtop_fifo_status_no_pll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  debug_test_enable:1;
        RBus_UInt32  debug_test:7;
    };
}vdtop_debug_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  muxanalogb:4;
        RBus_UInt32  muxanaloga:4;
    };
}vdtop_video_debug_analog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  clk_dac_polarity:1;
        RBus_UInt32  clk_sct_polarity:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_test_dac_en:1;
        RBus_UInt32  muxdigital:4;
    };
}vdtop_video_debug_digital_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  patgen_vline_vactive_end:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_vline:10;
        RBus_UInt32  patgen_vline_en:1;
        RBus_UInt32  fifo_out_pattern_gen_en:1;
        RBus_UInt32  pattern_gen_scart_en:1;
        RBus_UInt32  crc_chk_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pattern_gen_input_mode_sel:1;
        RBus_UInt32  pattern_gen_cvbs_mode:1;
        RBus_UInt32  pattern_generator_enable:1;
    };
}vdtop_pattern_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vdtop_crc_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  clk_vdadc_polarity:1;
        RBus_UInt32  clk_polarity:1;
        RBus_UInt32  patgen_sync_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  patgen_burst_gain:3;
    };
}vdtop_patgen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_mode_out:1;
        RBus_UInt32  bist_mode_fifo:1;
        RBus_UInt32  bist_mode_dma:1;
        RBus_UInt32  bist_mode_27_2:1;
        RBus_UInt32  bist_mode_27_1:1;
    };
}vdtop_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_done_out:1;
        RBus_UInt32  bist_done_fifo:1;
        RBus_UInt32  bist_done_dma:1;
        RBus_UInt32  bist_done_27_2:1;
        RBus_UInt32  bist_done_27_1:1;
    };
}vdtop_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_fail_out:1;
        RBus_UInt32  bist_fail_fifo:1;
        RBus_UInt32  bist_fail_dma:1;
        RBus_UInt32  bist_fail_27_2:1;
        RBus_UInt32  bist_fail_27_1:1;
    };
}vdtop_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_mode_out:1;
        RBus_UInt32  bist_drf_mode_fifo:1;
        RBus_UInt32  bist_drf_mode_dma:1;
        RBus_UInt32  bist_drf_mode_27_2:1;
        RBus_UInt32  bist_drf_mode_27_1:1;
    };
}vdtop_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_resume_out:1;
        RBus_UInt32  bist_drf_resume_fifo:1;
        RBus_UInt32  bist_drf_resume_dma:1;
        RBus_UInt32  bist_drf_resume_27_2:1;
        RBus_UInt32  bist_drf_resume_27_1:1;
    };
}vdtop_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_done_out:1;
        RBus_UInt32  bist_drf_done_fifo:1;
        RBus_UInt32  bist_drf_done_dma:1;
        RBus_UInt32  bist_drf_done_27_2:1;
        RBus_UInt32  bist_drf_done_27_1:1;
    };
}vdtop_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_pause_out:1;
        RBus_UInt32  bist_drf_pause_fifo:1;
        RBus_UInt32  bist_drf_pause_dma:1;
        RBus_UInt32  bist_drf_pause_27_2:1;
        RBus_UInt32  bist_drf_pause_27_1:1;
    };
}vdtop_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_fail_out:1;
        RBus_UInt32  bist_drf_fail_fifo:1;
        RBus_UInt32  bist_drf_fail_dma:1;
        RBus_UInt32  bist_drf_fail_27_2:1;
        RBus_UInt32  bist_drf_fail_27_1:1;
    };
}vdtop_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_mem_fail_27_1:6;
    };
}vdtop_bist_fail_27_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  bist_mem_fail_27_2:10;
    };
}vdtop_bist_fail_27_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_mem_fail_dma:5;
    };
}vdtop_bist_fail_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mem_fail_fifo:1;
    };
}vdtop_bist_fail_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bist_mem_fail_out:4;
    };
}vdtop_bist_fail_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_drf_mem_fail_27_1:6;
    };
}vdtop_bist_drf_fail_27_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  bist_drf_mem_fail_27_2:10;
    };
}vdtop_bist_drf_fail_27_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bist_drf_mem_fail_dma:5;
    };
}vdtop_bist_drf_fail_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_drf_mem_fail_fifo:1;
    };
}vdtop_bist_drf_fail_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bist_drf_mem_fail_out:4;
    };
}vdtop_bist_drf_fail_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  mbist_dvs_out:4;
        RBus_UInt32  mbist_dvse_out:1;
        RBus_UInt32  mbist_dvs_fifo:4;
        RBus_UInt32  mbist_dvse_fifo:1;
        RBus_UInt32  mbist_dvs_dma:4;
        RBus_UInt32  mbist_dvse_dma:1;
        RBus_UInt32  mbist_dvs_27_2:4;
        RBus_UInt32  mbist_dvse_27_2:1;
        RBus_UInt32  mbist_dvs_27_1:4;
        RBus_UInt32  mbist_dvse_27_1:1;
    };
}vdtop_bist_dvse_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mbist_ls_cntl:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mbist_dvs_fifo_2:4;
        RBus_UInt32  mbist_dvse_fifo_2:1;
        RBus_UInt32  mbist_dvs_dma_2:4;
        RBus_UInt32  mbist_dvse_dma_2:1;
    };
}vdtop_bist_dvse_dvs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ycbcr_moniter_en:1;
        RBus_UInt32  moniter_field:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  moniter_size:4;
        RBus_UInt32  moniter_v_addr:9;
        RBus_UInt32  res2:5;
        RBus_UInt32  moniter_h_addr:11;
    };
}vdtop_ycbcr_moniter_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  vd_yout_moniter:10;
    };
}vdtop_ycbcr_moniter_value_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vd_crout_moniter:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vd_cbout_moniter:10;
    };
}vdtop_ycbcr_moniter_value_cbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  moniter_y_value:8;
        RBus_UInt32  moniter_cb_value:8;
        RBus_UInt32  moniter_cr_value:8;
        RBus_UInt32  res1:5;
        RBus_UInt32  adc_updn_debug_en:1;
        RBus_UInt32  adc_updn_debug_up:1;
        RBus_UInt32  adc_updn_debug_dn:1;
    };
}vdtop_adc_updn_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======VDTOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  colour_mode:3;
        RBus_UInt32  vline_625:1;
        RBus_UInt32  hpixel:2;
        RBus_UInt32  hv_delay:1;
        RBus_UInt32  res2:24;
    };
}vdtop_video_control0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ped:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dark_yc_src:1;
        RBus_UInt32  yc_src:1;
        RBus_UInt32  cv_src:1;
        RBus_UInt32  cv_inv:1;
        RBus_UInt32  vd_pq_bypass_en:1;
        RBus_UInt32  ycsepdata_burstin_en:1;
        RBus_UInt32  patterngen_power_on_en:1;
        RBus_UInt32  dark_cpll_power_on_en:1;
        RBus_UInt32  avout_power_on_en:1;
        RBus_UInt32  secam_power_on_en:1;
        RBus_UInt32  scart_power_on_en:1;
        RBus_UInt32  sv_power_on_en:1;
        RBus_UInt32  smixer_ycadjust_power_on:1;
        RBus_UInt32  ycsep_power_on:1;
        RBus_UInt32  res2:14;
    };
}vdtop_video_control1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_signal:1;
        RBus_UInt32  hlock:1;
        RBus_UInt32  vlock:1;
        RBus_UInt32  chomalock:1;
        RBus_UInt32  mv_vbi_detected:1;
        RBus_UInt32  mv_colour_inverse:3;
        RBus_UInt32  h_fine_lock:1;
        RBus_UInt32  chromalock_acc:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hlock_longtime:1;
        RBus_UInt32  vlock_longtime:1;
        RBus_UInt32  hvlock_longtime:1;
        RBus_UInt32  res2:17;
    };
}vdtop_video_status_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  proscan_detected:1;
        RBus_UInt32  palm_flag:1;
        RBus_UInt32  palor_flag:1;
        RBus_UInt32  burst_detect:1;
        RBus_UInt32  detect443_flag:1;
        RBus_UInt32  noisy_vbi:1;
        RBus_UInt32  vlock_new:1;
        RBus_UInt32  detect358_flag:1;
        RBus_UInt32  v_detect_flag:1;
        RBus_UInt32  firtst_vsync_detected:1;
        RBus_UInt32  old_vdetect_stable:1;
        RBus_UInt32  new_vdetect_stable:1;
        RBus_UInt32  res1:20;
    };
}vdtop_video_status_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pal_detected:1;
        RBus_UInt32  secam_detected:1;
        RBus_UInt32  lines_625_detected:1;
        RBus_UInt32  noisy:1;
        RBus_UInt32  vcr:1;
        RBus_UInt32  vcr_trick:1;
        RBus_UInt32  vcr_ff:1;
        RBus_UInt32  vcr_rew:1;
        RBus_UInt32  res1:24;
    };
}vdtop_video_status_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdto_inc_status:30;
        RBus_UInt32  res1:2;
    };
}vdtop_hdto_inc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdto_inc_status:30;
        RBus_UInt32  res1:2;
    };
}vdtop_cdto_inc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_magnitude:8;
        RBus_UInt32  res1:24;
    };
}vdtop_avg_burst_mag_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain:12;
        RBus_UInt32  res1:20;
    };
}vdtop_agc_dgain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status_cmag:8;
        RBus_UInt32  res1:24;
    };
}vdtop_cmag_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status_cgain:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  status_cgain_data:14;
        RBus_UInt32  res2:2;
    };
}vdtop_cgain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status_cordiq_freq:8;
        RBus_UInt32  res1:24;
    };
}vdtop_cordic_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_1st_line:10;
        RBus_UInt32  res1:22;
    };
}vdtop_measure_first_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_2nd_line:10;
        RBus_UInt32  res1:22;
    };
}vdtop_measure_second_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  porch_h:13;
        RBus_UInt32  res1:19;
    };
}vdtop_porch_height_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status_noise:8;
        RBus_UInt32  res1:24;
    };
}vdtop_noise_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise_thresh:8;
        RBus_UInt32  res1:24;
    };
}vdtop_noise_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdto_inc:30;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdto_fixed:1;
    };
}vdtop_hsync_dto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdto_inc:30;
        RBus_UInt32  res1:1;
        RBus_UInt32  cdto_fixed:1;
    };
}vdtop_chroma_dto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chip_ver:16;
        RBus_UInt32  res1:16;
    };
}vdtop_chip_ver_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_vid_offset_value:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  blank_vid_offset_manu_en:1;
        RBus_UInt32  res2:19;
    };
}vdtop_blank_vid_offset_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  contrast:8;
        RBus_UInt32  res1:24;
    };
}vdtop_luma_contrast_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  brightness:8;
        RBus_UInt32  res1:24;
    };
}vdtop_luma_brightness_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  saturation:8;
        RBus_UInt32  res1:24;
    };
}vdtop_chroma_saturation_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hue:8;
        RBus_UInt32  res1:24;
    };
}vdtop_chroma_hue_phase_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blue_screen_y:8;
        RBus_UInt32  res1:24;
    };
}vdtop_blue_screen_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blue_screen_cb:8;
        RBus_UInt32  res1:24;
    };
}vdtop_blue_screen_cb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blue_screen_cr:8;
        RBus_UInt32  res1:24;
    };
}vdtop_blue_screen_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yc_delay:4;
        RBus_UInt32  blue_mode:2;
        RBus_UInt32  cbcr_swap:1;
        RBus_UInt32  snow_freerun_en:1;
        RBus_UInt32  motion_delay:4;
        RBus_UInt32  res1:20;
    };
}vdtop_output_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamp_if_dn_en:1;
        RBus_UInt32  clamp_if_up_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sw_tu_cvbs:1;
        RBus_UInt32  fe_bypass_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  avout_hsync_end:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  avout_hsync_start:10;
        RBus_UInt32  res4:2;
    };
}vdtop_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avout_fifo_status_empty:1;
        RBus_UInt32  avout_fifo_status_full:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  avout_mixer_sel:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  avout_test_in:12;
        RBus_UInt32  output_delay_0_180_sw:1;
        RBus_UInt32  output_fifo_empty:1;
        RBus_UInt32  output_fifo_full:1;
        RBus_UInt32  res3:5;
    };
}vdtop_avout_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avout_ifdebug_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  avout_ifdebug_shift:4;
        RBus_UInt32  avout_ifdebug_mask:12;
        RBus_UInt32  avout_ifdebug_inv:12;
    };
}vdtop_avout_ifdebug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ramp_counter_num:24;
        RBus_UInt32  ramp_updn_sel:1;
        RBus_UInt32  ramp_en:1;
        RBus_UInt32  res1:6;
    };
}vdtop_avout1_ifdebug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_nominal:7;
        RBus_UInt32  hagc_err_coring_en:1;
        RBus_UInt32  peak_deb_thl:8;
        RBus_UInt32  peak_deb_limit:9;
        RBus_UInt32  peak_data_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  peak_diff_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  peak_deb_en:1;
    };
}vdtop_agc_peak_nominal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_cntl:3;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  agc_gate_kill_mode:2;
        RBus_UInt32  agc_gate_vsync_stip:1;
        RBus_UInt32  agc_gate_vsync_coarse:1;
        RBus_UInt32  agc_gate_kill_w_hlock:1;
        RBus_UInt32  agc_gate_kill_mode_sel:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc_peak_nominal_ycsep:12;
        RBus_UInt32  ycsep_data_decrease_ratio:3;
        RBus_UInt32  ycsep_data_decrease_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_path_dgain_after_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dgain_i_cntl_without_trunc_en:1;
    };
}vdtop_agc_peak_and_gate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_loop_gain:2;
        RBus_UInt32  hagc_err_coring_th:5;
        RBus_UInt32  unlock_peakrst_en:1;
        RBus_UInt32  diff_level:12;
        RBus_UInt32  peak_gain:12;
    };
}vdtop_agc_peak_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hagc_en:1;
        RBus_UInt32  cagc_en:1;
        RBus_UInt32  bgate_raw_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_clamp_mode:2;
        RBus_UInt32  mv_hagc_mode:1;
        RBus_UInt32  hagc_field_mode:1;
        RBus_UInt32  under_gain:12;
        RBus_UInt32  dgain_state:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  fix_dgain:1;
        RBus_UInt32  mv_detect_sel:1;
        RBus_UInt32  res3:2;
    };
}vdtop_video_control2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hagc:8;
        RBus_UInt32  dgain_status_counter:12;
        RBus_UInt32  peak_under_round_thl:8;
        RBus_UInt32  peak_under_round_en:1;
        RBus_UInt32  dgain_status_triger:1;
        RBus_UInt32  res1:2;
    };
}vdtop_luma_agc_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gate_start:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  diff_gain_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dgain_ki:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dgain_kp:3;
        RBus_UInt32  res4:9;
    };
}vdtop_agc_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gate_width:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  data_path_dgain_limit_low:12;
        RBus_UInt32  data_path_dgain_limit_up:12;
    };
}vdtop_agc_gate_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_bp_delay:8;
        RBus_UInt32  res1:24;
    };
}vdtop_agc_bp_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clampagc_under_th2:6;
        RBus_UInt32  res1:26;
    };
}vdtop_clampagc_compluma_new_threshold2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clampagc_under_th1:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  under_flag:1;
        RBus_UInt32  agc_under_loop_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  data_path_dgain_div2_en:1;
        RBus_UInt32  ypeak_wide_iir_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ypeak_wide_iir_in_coef:8;
        RBus_UInt32  res4:8;
    };
}vdtop_clampagc_compluma_new_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_vid_offset:1;
        RBus_UInt32  clampagc_under_en:1;
        RBus_UInt32  clampagc_under_cntl:6;
        RBus_UInt32  under_deb_thl:8;
        RBus_UInt32  under_deb_limit:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  under_diff_sel:2;
        RBus_UInt32  under_gate_en:1;
        RBus_UInt32  under_deb_en:1;
    };
}vdtop_clampagc_compluma_new_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_agc_min:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  under_gate_st:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  under_gate_end:10;
        RBus_UInt32  res3:2;
    };
}vdtop_vsync_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_agc_max:6;
        RBus_UInt32  vsync_clamp_mode:2;
        RBus_UInt32  peak_gate_st:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  peak_gate_end:10;
        RBus_UInt32  res2:1;
        RBus_UInt32  peak_gate_en:1;
    };
}vdtop_vsync_agc_lockout_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpump_delay_en:1;
        RBus_UInt32  cpump_adjust_polarity:1;
        RBus_UInt32  cpump_adjust_delay:6;
        RBus_UInt32  auto_dc_restore_disable_ad1_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad2_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad3_updn:1;
        RBus_UInt32  auto_dc_restore_disable_ad4_updn:1;
        RBus_UInt32  auto_dc_restore_en0:1;
        RBus_UInt32  auto_dc_restore_en1:1;
        RBus_UInt32  auto_dc_restore_en2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  auto_dc_restore_sel:3;
        RBus_UInt32  res2:13;
    };
}vdtop_charge_pump_delay_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpump_adjust:8;
        RBus_UInt32  res1:24;
    };
}vdtop_charge_pump_adjustment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpump_delay:8;
        RBus_UInt32  res1:24;
    };
}vdtop_charge_pump_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gate_thresh:5;
        RBus_UInt32  adc_cbcr_pump_swap:1;
        RBus_UInt32  adc_input_swap:1;
        RBus_UInt32  adc_updn_swap:1;
        RBus_UInt32  cvbs_clamp_length_max:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  sv_rgb_clamp_length_max:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cvbs_clamp_length_limit_en:1;
        RBus_UInt32  sv_rgb_clamp_length_limit_en:1;
        RBus_UInt32  res3:6;
    };
}vdtop_agc_gate_th_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clampagc_rc_rate:4;
        RBus_UInt32  new_clamp_rc_rate_en:1;
        RBus_UInt32  measure_dc_rough:1;
        RBus_UInt32  dgain_ignore_fine_lock:1;
        RBus_UInt32  measure_dc_128_64_sel:1;
        RBus_UInt32  first_dgain_integral_fw_mode_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  first_dgain_integral_value:20;
    };
}vdtop_new_clampagc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_dc_rough_dn:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  first_dgain_int_value_status:20;
    };
}vdtop_measure_dc_rough_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_dc_rough_up:8;
        RBus_UInt32  second_dgain_integral_fw_mode_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  second_dgain_integral_value:20;
    };
}vdtop_measure_dc_rough_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_dc_th_dn:12;
        RBus_UInt32  second_dgain_int_value_status:20;
    };
}vdtop_measure_dc_th_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_dc_th_up:12;
        RBus_UInt32  res1:20;
    };
}vdtop_measure_dc_th_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsag_agc_peak_cntl:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  vsag_rc_input:1;
        RBus_UInt32  res2:24;
    };
}vdtop_vsag_cntl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peak_vsag:13;
        RBus_UInt32  res1:19;
    };
}vdtop_peak_vsag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_kill_rst:1;
        RBus_UInt32  lose_bgate_flag:1;
        RBus_UInt32  lose_sgate_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  new_under_th2_en:1;
        RBus_UInt32  new_under_gain_en:1;
        RBus_UInt32  new_total_under_en:1;
        RBus_UInt32  res2:25;
    };
}vdtop_kill_field_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_kill_num:10;
        RBus_UInt32  res1:22;
    };
}vdtop_field_kill_mun_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kill_gate_up:11;
        RBus_UInt32  res1:21;
    };
}vdtop_kill_gate_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kill_gate_dn:11;
        RBus_UInt32  res1:21;
    };
}vdtop_kill_gate_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  sync_midpt_lowest_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  syncmidpt_add_level_h:2;
        RBus_UInt32  res3:26;
    };
}vdtop_syncmidpt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  syncmidpt_fix_add_value_h:8;
        RBus_UInt32  res1:24;
    };
}vdtop_syncmidpt_fix_add_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpfsync_plus_diff:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  lpfsync_plus_rm:1;
        RBus_UInt32  lpfsync_plus_w_hlock:2;
        RBus_UInt32  res2:22;
    };
}vdtop_lpfsync_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spike_min_thresh:8;
        RBus_UInt32  res1:24;
    };
}vdtop_spike_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spike_max_thresh:8;
        RBus_UInt32  res1:24;
    };
}vdtop_spike_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spike_detected_up:10;
        RBus_UInt32  spike_detected:1;
        RBus_UInt32  res1:21;
    };
}vdtop_spike_detected_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spike_detected_dn:10;
        RBus_UInt32  res1:22;
    };
}vdtop_spike_detected_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpfsync_plus_dc:8;
        RBus_UInt32  res1:24;
    };
}vdtop_lpfsync_plus_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_error_avg_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdetect_error_avg_length:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdetect_error_avg_interval:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  hstate_error_rst:1;
        RBus_UInt32  hstate_error_dn_count:8;
        RBus_UInt32  hstate_error_thl:8;
        RBus_UInt32  res4:4;
    };
}vdtop_hdetect_err_var_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_error_mean:16;
        RBus_UInt32  hdetect_error_var:16;
    };
}vdtop_hdetect_err_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locked_count_clean_max:4;
        RBus_UInt32  locked_count_noisy_max:4;
        RBus_UInt32  locked_count_vcrtrick_max:4;
        RBus_UInt32  hstate_vsync_error_start:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_vsync_error_end:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  hstate_vsync_error_num_thr:4;
    };
}vdtop_lock_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hstate_max:3;
        RBus_UInt32  hstate_unlocked:1;
        RBus_UInt32  disable_hfine:1;
        RBus_UInt32  hstate_fixed:1;
        RBus_UInt32  hlock_vsync_mode:2;
        RBus_UInt32  hstate_vsync_error_unbalance:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_vsync_error_hlock_en:1;
        RBus_UInt32  hstate_vsync_error_vlock_en:1;
        RBus_UInt32  hstate_vsync_error_noisy_en:1;
        RBus_UInt32  hstate_vsync_error_num_en:1;
        RBus_UInt32  hstate_vsync_error_value_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  hstate_vsync_error_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  hstate_vsync_error_unbalance_en:1;
        RBus_UInt32  hstate_vsync_error_unbalance_status:1;
        RBus_UInt32  res4:6;
    };
}vdtop_h_loop_maxstate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gate_end_thresh:5;
        RBus_UInt32  fine_gate_sel:1;
        RBus_UInt32  coarse_src_sel:1;
        RBus_UInt32  fine_src_sel:1;
        RBus_UInt32  coarse_phase_rising_en:1;
        RBus_UInt32  hpll_fine_lock_data_sel:1;
        RBus_UInt32  auto_fine_phase_sel_en:1;
        RBus_UInt32  fine_hstate_to_5:1;
        RBus_UInt32  auto_fine_phase_sel:1;
        RBus_UInt32  hstate_ignore_err:1;
        RBus_UInt32  hstate_hlock_sel:1;
        RBus_UInt32  cpll_hpll_use_front_vactive:1;
        RBus_UInt32  fine_phase_error_thl:10;
        RBus_UInt32  res1:6;
    };
}vdtop_clampagc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coarse_sync_start:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_vsync_error_noisy_upper_th:8;
        RBus_UInt32  hstate_vsync_error_noisy_lower_th:8;
        RBus_UInt32  res2:8;
    };
}vdtop_clampagc_new_sync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coarse_sync_end:8;
        RBus_UInt32  hstate_vsync_error_abs_thr:8;
        RBus_UInt32  hstate_vsync_error_value_thr:8;
        RBus_UInt32  res1:8;
    };
}vdtop_clampagc_new_sync_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coarse_backporch_start:7;
        RBus_UInt32  agc_trailing_sel:1;
        RBus_UInt32  hstate_err:14;
        RBus_UInt32  res1:10;
    };
}vdtop_clampagc_new_backporch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coarse_backporch_end:8;
        RBus_UInt32  hstate_err_in_vcount:10;
        RBus_UInt32  res1:14;
    };
}vdtop_clampagc_new_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fine_phase_sel:1;
        RBus_UInt32  coarse_phase_sel:1;
        RBus_UInt32  killgate_sel:1;
        RBus_UInt32  agc_clamping_trailing_sel:1;
        RBus_UInt32  nosignal_hlock_check_en:1;
        RBus_UInt32  lpfsync_force_blank_en:1;
        RBus_UInt32  res1:26;
    };
}vdtop_hdetect_phase_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsync_tip_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hdetect_counter_tip_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsync_tip_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hdetect_counter_tip_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lporch_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hdetect_counter_backporch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lporch_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hdetect_counter_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_integral_ext:1;
        RBus_UInt32  hpll_integral_rst:1;
        RBus_UInt32  res1:30;
    };
}vdtop_hpll_integral_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hstate_status:3;
        RBus_UInt32  hstate_loopfilter_sw:1;
        RBus_UInt32  hstate_vcr_max:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hstate_impn_max:3;
        RBus_UInt32  mode_vcr_setting_change_en:1;
        RBus_UInt32  cstate_impn_max:3;
        RBus_UInt32  impulsive_noise_disable_pll_en:1;
        RBus_UInt32  vsync_freerun_when_unstable_en_vcr:1;
        RBus_UInt32  second_pll_en_vcr:1;
        RBus_UInt32  dgain_ignore_fine_lock_vcr:1;
        RBus_UInt32  gate_iir_v_sel_vcr:1;
        RBus_UInt32  gate_iir_h_sel_vcr:1;
        RBus_UInt32  new_hpll_lpf_sel_vcr:1;
        RBus_UInt32  agc_gate_kill_mode_vcr:2;
        RBus_UInt32  vsync_freerun_when_unstable_en_status:1;
        RBus_UInt32  second_pll_en_status:1;
        RBus_UInt32  dgain_ignore_fine_lock_status:1;
        RBus_UInt32  gate_iir_v_sel_status:1;
        RBus_UInt32  gate_iir_h_sel_status:1;
        RBus_UInt32  new_hpll_lpf_sel_status:1;
        RBus_UInt32  agc_gate_kill_mode_status:2;
    };
}vdtop_hdetect_loopfilter_sw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_loopfilter_dctrl2:4;
        RBus_UInt32  hdetect_loopfilter_dctrl1:4;
        RBus_UInt32  res1:24;
    };
}vdtop_hdetect_loopfilter_dctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hsync_pulse_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_width:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hsync_pulse_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hresampler_2up:1;
        RBus_UInt32  hresampler_app_sel:1;
        RBus_UInt32  hresampler_app_alpha_sel:1;
        RBus_UInt32  res1:29;
    };
}vdtop_chroma_hresampler_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_0:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpll_manu_mode_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_hpll_kp_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_1:6;
        RBus_UInt32  res1:26;
    };
}vdtop_hpll_kp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_2:6;
        RBus_UInt32  res1:26;
    };
}vdtop_hpll_kp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_3:6;
        RBus_UInt32  res1:26;
    };
}vdtop_hpll_kp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_4:6;
        RBus_UInt32  res1:26;
    };
}vdtop_hpll_kp_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_kp_coef_5:6;
        RBus_UInt32  res1:26;
    };
}vdtop_hpll_kp_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_0:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_1:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_2:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_3:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_4:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hpll_ki_coef_5:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hpll_ki_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_pll_en:1;
        RBus_UInt32  second_pll_w_hlock:1;
        RBus_UInt32  second_pll_phase_sel:1;
        RBus_UInt32  second_pll_clampgate_sel:1;
        RBus_UInt32  second_pll_gain_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  second_pll_level_sel:2;
        RBus_UInt32  res2:22;
    };
}vdtop_second_pll_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_pll_dc_rm:12;
        RBus_UInt32  second_pll_dc_add:12;
        RBus_UInt32  second_pll_sync_level:8;
    };
}vdtop_second_pll_gain1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_comp_slevel:12;
        RBus_UInt32  second_comp_blevel:12;
        RBus_UInt32  res1:8;
    };
}vdtop_second_pll_gain2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_dgain:12;
        RBus_UInt32  second_trailing:8;
        RBus_UInt32  res1:12;
    };
}vdtop_second_pll_gain3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_hsync_tip_end:8;
        RBus_UInt32  second_hsync_tip_start:8;
        RBus_UInt32  second_backporch_end:8;
        RBus_UInt32  second_backporch_start:8;
    };
}vdtop_second_pll_gain4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_min_err_thl:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  under_line_err_thl:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  under_count_reset:1;
        RBus_UInt32  under_detected_flag:1;
        RBus_UInt32  second_pll_kill_en:1;
        RBus_UInt32  headswitch_debounce_en:1;
        RBus_UInt32  res3:4;
    };
}vdtop_under_new_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_field_err_thl:10;
        RBus_UInt32  res1:22;
    };
}vdtop_under_new_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_debounce_max:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  under_debounce_thl:10;
        RBus_UInt32  res2:10;
    };
}vdtop_under_new_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_avg_line1_diff_thre_lo:12;
        RBus_UInt32  coch_avg_line1_diff_thre_up:12;
        RBus_UInt32  res1:7;
        RBus_UInt32  coch_detected_by_check_dc:1;
    };
}vdtop_dc_coch_seperate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_detect_counter_lo_thre:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  coch_detect_counter_up_thre:10;
        RBus_UInt32  res2:9;
        RBus_UInt32  coch_detect_lpf_reset:1;
    };
}vdtop_dc_coch_seperate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_rising:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hsync_rising_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_phase_offset:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hsync_phase_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_gate_start:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_hcount_start:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_gate_end:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_hcount_end:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_gate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_tip_start:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_vcount_start_o:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_tip_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_tip_end:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_vcount_end_o:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_tip_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_rising_start:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_vcount_start_e:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_rising_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_rising_end:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  secam_gp_vcount_end_e:10;
        RBus_UInt32  res2:10;
    };
}vdtop_hsync_rising_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  backporch_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_backproch_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  backporch_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_backporch_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hblank_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hblank_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hblank_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hblank_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_gate_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_gate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_gate_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_gate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hactive_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hactive_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hactive_width:8;
        RBus_UInt32  res1:24;
    };
}vdtop_hactive_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_hstate_4_phase_max:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdetect_hstate_3_phase_max:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdetect_hstate_phase_max_en:1;
    };
}vdtop_hdetect_err_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_err00_th:8;
        RBus_UInt32  hdetect_err04_th:8;
        RBus_UInt32  hdetect_hstate_5_phase_max:13;
        RBus_UInt32  res1:3;
    };
}vdtop_hdetect_err_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cstate_status:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cstate_cntl:2;
        RBus_UInt32  new_cstate:1;
        RBus_UInt32  new_c_state_i:1;
        RBus_UInt32  cpll_use_fine_or_final_hlock:1;
        RBus_UInt32  cpll_cgain_reset_en:1;
        RBus_UInt32  res2:22;
    };
}vdtop_cstate_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gate_iir_v_sel:1;
        RBus_UInt32  gate_iir_h_sel:1;
        RBus_UInt32  new_hpll_lpf_sel:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  coef_syncmidpt_fir_in:8;
        RBus_UInt32  level_fir_num_32_64_slevel:1;
        RBus_UInt32  level_fir_num_32_64_blevel:1;
        RBus_UInt32  s_b_level_fir_en:1;
        RBus_UInt32  res2:13;
    };
}vdtop_hdetect_gate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gate_iir_coef1:8;
        RBus_UInt32  hsync_refind:1;
        RBus_UInt32  hsync_refind_mask_err:1;
        RBus_UInt32  headswitch_err_sel:2;
        RBus_UInt32  res1:20;
    };
}vdtop_hdetect_gate_coef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gate_iir_coef2:8;
        RBus_UInt32  hdetect_err07_th:8;
        RBus_UInt32  res1:16;
    };
}vdtop_hdetect_gate_coef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vphase_status:8;
        RBus_UInt32  hstate_err_counter:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  hstate_err_thl:14;
        RBus_UInt32  res2:2;
    };
}vdtop_hdetect_vphase_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vphasediff_status:8;
        RBus_UInt32  hdetect_err01_th:8;
        RBus_UInt32  hdetect_err10_th:8;
        RBus_UInt32  hdetect_err05_th:8;
    };
}vdtop_hdetect_vphasediff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise_vbi_thresh:8;
        RBus_UInt32  res1:24;
    };
}vdtop_noise_vbi_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_detected_frame:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  coch_detected_status:1;
        RBus_UInt32  res2:24;
    };
}vdtop_vbi_co_ch_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_bp_diff_th:4;
        RBus_UInt32  res1:28;
    };
}vdtop_vbi_co_ch_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coch_line_count_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vbi_co_ch_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_window2_value:8;
        RBus_UInt32  res1:24;
    };
}vdtop_mv_detect_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad_burst_gate_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_mv_burstgate_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad_burst_gate_end:8;
        RBus_UInt32  res1:24;
    };
}vdtop_mv_burstgate_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cinverse_detect_control:3;
        RBus_UInt32  res1:29;
    };
}vdtop_color_inverse_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_err_constraint_low_th:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  h_err_constraint_high_th:14;
        RBus_UInt32  res2:1;
        RBus_UInt32  h_err_constraint_en:1;
    };
}vdtop_h_err_constraint_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_err_constraint_val:13;
        RBus_UInt32  h_err_constraint_hstate:3;
        RBus_UInt32  res1:16;
    };
}vdtop_h_err_constraint_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_save_stable_hdto_start:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  hdetect_restore_vcr_enable:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdetect_set_hdto_start:10;
        RBus_UInt32  hdetect_force_hdto_en:1;
        RBus_UInt32  hdetect_restore_hdto_status:1;
        RBus_UInt32  hdetect_set_new_hdto_n:3;
        RBus_UInt32  hdetect_restore_hdto_en:1;
    };
}vdtop_h_restore_hdto_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdetect_set_hdto_phase_err_th:14;
        RBus_UInt32  res1:18;
    };
}vdtop_h_restore_hdto_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wrong_if_pc_detect:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  sync_level_manu_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  sync_level_manu:8;
        RBus_UInt32  wrong_if_pc_detect_th:8;
    };
}vdtop_if_wrong_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpll_phase_thr_dn:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cpll_phase_thr_up:14;
        RBus_UInt32  res2:2;
    };
}vdtop_cpll_stability_observe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cpll_stable_flag:1;
        RBus_UInt32  cpll_phase_small_flag:1;
        RBus_UInt32  cpll_ampl_neg_flag:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  cerror_continune_same_sign_thr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cpll_ampl_thr:7;
        RBus_UInt32  res3:1;
    };
}vdtop_cpll_stability_observe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_out_line_iir:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  ampl_out_line_iir:14;
        RBus_UInt32  res2:2;
    };
}vdtop_cpll_stability_observe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  herror_neg_pos_value_total_thr:4;
        RBus_UInt32  herror_neg_pos_num_total_thr:4;
        RBus_UInt32  herror_continune_same_sign_thr:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  herror_pos_neg_value_diff_thr:16;
    };
}vdtop_hpll_stability_observe_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  herror_pos_value:16;
        RBus_UInt32  herror_neg_value:16;
    };
}vdtop_hpll_stability_observe_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  herror_stable_state_hold_en:1;
        RBus_UInt32  herror_pos_neg_value_even:1;
        RBus_UInt32  herror_pos_neg_num_even:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  herror_neg_pos_num_win_thr:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  herror_neg_pos_err_th:13;
        RBus_UInt32  res3:3;
    };
}vdtop_hpll_stability_observe_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec1_start:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_h_phase_diff_sec1_end:9;
        RBus_UInt32  res2:7;
    };
}vdtop_h_phase_diff_statistics_set_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec2_start:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_h_phase_diff_sec2_end:9;
        RBus_UInt32  res2:7;
    };
}vdtop_h_phase_diff_statistics_set_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_hitso_level1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level2:13;
        RBus_UInt32  res2:3;
    };
}vdtop_h_phase_diff_statistics_set_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_hitso_level3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  statistic_h_phase_diff_hitso_level4:13;
        RBus_UInt32  res2:3;
    };
}vdtop_h_phase_diff_statistics_set_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_hitso_level5:13;
        RBus_UInt32  res1:19;
    };
}vdtop_h_phase_diff_statistics_set_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_0:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_1:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_2:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_ready:1;
    };
}vdtop_h_phase_diff_sec1_histogram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_3:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_4:10;
        RBus_UInt32  statistic_h_phase_diff_sec1_histo_5:10;
        RBus_UInt32  res1:2;
    };
}vdtop_h_phase_diff_sec1_histogram_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_0:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_1:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_2:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_ready:1;
    };
}vdtop_h_phase_diff_sec2_histogram_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_3:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_4:10;
        RBus_UInt32  statistic_h_phase_diff_sec2_histo_5:10;
        RBus_UInt32  res1:2;
    };
}vdtop_h_phase_diff_sec2_histogram_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_line_num:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  statistic_data_level_diff_th:14;
        RBus_UInt32  data_level_diff_iir_en:1;
        RBus_UInt32  iir_up_speed_on:1;
    };
}vdtop_data_level_statistics_set_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec1_max:12;
        RBus_UInt32  statistic_data_level_sec1_min:12;
        RBus_UInt32  res1:7;
        RBus_UInt32  statistic_data_level_ready:1;
    };
}vdtop_data_level_statistics_sec1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec2_max:12;
        RBus_UInt32  statistic_data_level_sec2_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec3_max:12;
        RBus_UInt32  statistic_data_level_sec3_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec4_max:12;
        RBus_UInt32  statistic_data_level_sec4_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec5_max:12;
        RBus_UInt32  statistic_data_level_sec5_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec6_max:12;
        RBus_UInt32  statistic_data_level_sec6_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec7_max:12;
        RBus_UInt32  statistic_data_level_sec7_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_data_level_sec8_max:12;
        RBus_UInt32  statistic_data_level_sec8_min:12;
        RBus_UInt32  res1:8;
    };
}vdtop_data_level_statistics_sec8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlock_time:22;
        RBus_UInt32  res1:10;
    };
}vdtop_hlock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlock_time:22;
        RBus_UInt32  res1:10;
    };
}vdtop_vlock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstate_eq3_time:22;
        RBus_UInt32  res1:10;
    };
}vdtop_vstatelock_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_signal_fall_time:22;
        RBus_UInt32  res1:10;
    };
}vdtop_no_signal_fall_time_polling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_threshold:6;
        RBus_UInt32  vsync_cntl:2;
        RBus_UInt32  num_old_vdetect_stable_fields:8;
        RBus_UInt32  old_vdetect_line_count_max:10;
        RBus_UInt32  res1:6;
    };
}vdtop_vsync_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop_tc3:2;
        RBus_UInt32  field_detect_mode:2;
        RBus_UInt32  vodd_delayed:1;
        RBus_UInt32  veven_delayed:1;
        RBus_UInt32  flip_field:1;
        RBus_UInt32  field_polarity:1;
        RBus_UInt32  num_new_vdetect_stable_fields:8;
        RBus_UInt32  res1:16;
    };
}vdtop_vsync_time_const_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop_tc2:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vsync_time_const2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop_tc1:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vsync_time_const1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  serration_threshold:8;
        RBus_UInt32  res1:24;
    };
}vdtop_serration_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_signal_dec:3;
        RBus_UInt32  vsync_delay_2d_delta_en:1;
        RBus_UInt32  vsync_delay_2d_delta:4;
        RBus_UInt32  vsync_delay_2d:4;
        RBus_UInt32  vsync_delay_1d:4;
        RBus_UInt32  vsync_delay_en:1;
        RBus_UInt32  vsync_delay_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hlock_field_cnt:4;
        RBus_UInt32  vlock_field_cnt:4;
        RBus_UInt32  hvlock_field_cnt:4;
    };
}vdtop_no_signal_dec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vactive_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_height:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vactive_height_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_h_min:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vsync_h_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_h_max:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vsync_h_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_vbi_min:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vsync_vbi_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_vbi_max:7;
        RBus_UInt32  vlock_wide_range:1;
        RBus_UInt32  res1:24;
    };
}vdtop_vsync_vbi_lockout_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  syncmidpt_add_level:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_625_midpt_en:1;
        RBus_UInt32  midpt_rough_vdetect_en:1;
        RBus_UInt32  midpt_625_dc_th_en:1;
        RBus_UInt32  syncmidpt_dc_rough:1;
        RBus_UInt32  vsync_ser_num_max_def:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_ser_num_bigger_10_en:1;
        RBus_UInt32  res3:15;
    };
}vdtop_midpt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  syncmidpt_fix_add_value:8;
        RBus_UInt32  res1:24;
    };
}vdtop_midpt_fix_add_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  midpt_625_dc_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_midpt_625_dc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_dc_offset_th:12;
        RBus_UInt32  res1:20;
    };
}vdtop_sync_dc_offset_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_midpt_625:12;
        RBus_UInt32  res1:20;
    };
}vdtop_sync_dc_offset_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_midpt_h:12;
        RBus_UInt32  res1:20;
    };
}vdtop_sync_midpt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_midpt_v:12;
        RBus_UInt32  res1:20;
    };
}vdtop_sync_midpt_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_line_length_en:1;
        RBus_UInt32  adc_lpf_sel:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  vdetect_pattern_sel:2;
        RBus_UInt32  vlock_sel:1;
        RBus_UInt32  hpll_no_signal_sel:1;
        RBus_UInt32  no_signal_to_0_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  no_signal_hpll_out:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  raw_vdetect_max_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  new_vdetect_feature_max_core:11;
        RBus_UInt32  res5:1;
    };
}vdtop_sync_midpt_v2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coef2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef1:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coef4:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef3:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coef6:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef5:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coef8:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef7:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coefa:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coef9:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_lpf_coefc:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  adc_lpf_coefb:10;
        RBus_UInt32  res2:6;
    };
}vdtop_adc_27_lpf_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_line_length:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vdetect_line_lenght_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_window_manu_en:1;
        RBus_UInt32  new_vdetect_window_en:1;
        RBus_UInt32  no_vsync_flag_en:1;
        RBus_UInt32  new_vdetect_force_en:1;
        RBus_UInt32  res1:28;
    };
}vdtop_vdetect_window_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_window:12;
        RBus_UInt32  res1:20;
    };
}vdtop_vdetect_window_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vsync_offset_manul:3;
        RBus_UInt32  new_vsync_offset_manul_mode_en:1;
        RBus_UInt32  new_vdetect_vcount_window_en:1;
        RBus_UInt32  vloss_detect_en:1;
        RBus_UInt32  gate_sel:1;
        RBus_UInt32  new_vdetect_en:1;
        RBus_UInt32  new_vdetect_coch_en:1;
        RBus_UInt32  new_vdetect_max_limit_en:1;
        RBus_UInt32  new_vdetect_first_vsync_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  new_vdetect_max_limit_value:12;
        RBus_UInt32  new_vdetect_maxmin_data_rc_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  new_vdetect_maxmin_data_rc_rate:4;
    };
}vdtop_new_vdetect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_fine_window_state1_en:1;
        RBus_UInt32  force_new_vdetect_fine_window:1;
        RBus_UInt32  new_vloss_flag:1;
        RBus_UInt32  no_vsync_flag:1;
        RBus_UInt32  new_vdetect_feature_th_manul_en:1;
        RBus_UInt32  old_hdetect_lpf_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_new_vdetect_loop_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_loop_core_th:10;
        RBus_UInt32  res1:22;
    };
}vdtop_new_vdetect_loop_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_diff_offset:12;
        RBus_UInt32  res1:20;
    };
}vdtop_new_vdetect_diff_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_fine_start:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_vdetect_loss_max:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_fine_start1:10;
        RBus_UInt32  res3:2;
    };
}vdtop_vsync_fine_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_fine_end:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_vdetect_loss_up:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_fine_end1:10;
        RBus_UInt32  res3:2;
    };
}vdtop_vsync_fine_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_vsync_th_lo:4;
        RBus_UInt32  no_vsync_th_hi:4;
        RBus_UInt32  res1:24;
    };
}vdtop_no_vsync_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_fine_vphase_th:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_vdetect_loss_dn:6;
        RBus_UInt32  res2:14;
    };
}vdtop_new_vdetect_vphase_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_feature_th1:8;
        RBus_UInt32  res1:24;
    };
}vdtop_new_vdetect_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_feature_th2:8;
        RBus_UInt32  res1:24;
    };
}vdtop_new_vdetect_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_feature_th3:8;
        RBus_UInt32  res1:24;
    };
}vdtop_new_vdetect_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_vdetect_feature_th4:8;
        RBus_UInt32  new_vdetect_feature_th5:8;
        RBus_UInt32  new_vdetect_feature_th6:8;
        RBus_UInt32  new_vdetect_feature_th7:8;
    };
}vdtop_new_vdetect_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstate_2to3_er:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  vsync_refind:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  vsync_refind_con_sel:2;
        RBus_UInt32  vstate_reset:2;
        RBus_UInt32  vsync_stable_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  vstate0_counter_num:8;
        RBus_UInt32  vstate0_direct_vsync:1;
        RBus_UInt32  vsync_refind_toggle:1;
        RBus_UInt32  vsync_refind_sel:2;
    };
}vdtop_vstate_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstate_back1_er:4;
        RBus_UInt32  vstate_1to2_er:4;
        RBus_UInt32  hsync_refind_max:7;
        RBus_UInt32  vstate1_err_sel:1;
        RBus_UInt32  hsync_refind_min:7;
        RBus_UInt32  vstate_new2to3_en:1;
        RBus_UInt32  vstate_2to3_th:8;
    };
}vdtop_vstate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstate_counter_num:8;
        RBus_UInt32  hsync_reset_for_data:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  hsync_reset_for_vsync:10;
        RBus_UInt32  res2:2;
    };
}vdtop_vstate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcr_back_en:1;
        RBus_UInt32  vstate_sw:2;
        RBus_UInt32  vstate_sw_en:1;
        RBus_UInt32  vstate_status:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  vsync_vertical_sum_num:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vstate3_err_adjust_th:4;
        RBus_UInt32  vstate3_err_adjust_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  vphase_error_window:8;
    };
}vdtop_vstate_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop0_tc1:8;
        RBus_UInt32  vstate3_counter_num:8;
        RBus_UInt32  res1:16;
    };
}vdtop_vloop0_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop0_tc2:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vloop0_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop2_tc1:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vloop2_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop2_tc2:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vloop2_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop3_tc1:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vloop3_tc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop3_tc2:7;
        RBus_UInt32  res1:25;
    };
}vdtop_vloop3_tc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vloop3_tc3:2;
        RBus_UInt32  vloop2_tc3:2;
        RBus_UInt32  vloop0_tc3:2;
        RBus_UInt32  res1:26;
    };
}vdtop_vloop_tc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlock_count:3;
        RBus_UInt32  new_vdetect_lock_en:1;
        RBus_UInt32  flag_cgain_too_big_kill:1;
        RBus_UInt32  flag_user_kill:1;
        RBus_UInt32  flag_chrmaunlock_kill:1;
        RBus_UInt32  res1:25;
    };
}vdtop_vlock_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlock_window:8;
        RBus_UInt32  vsync_detect_core_thl:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  vsync_detect_count_thl:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  vsync_detect_crlock_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  vsync_detect_rst:1;
    };
}vdtop_vlock_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlock_phase_plus:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vlock_phase_plus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vline_adj_cnt_a:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vline_adj_cnt_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vline_adj_cnt_b:8;
        RBus_UInt32  res1:24;
    };
}vdtop_vline_adj_cnt_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_hactive_width:8;
        RBus_UInt32  res1:24;
    };
}vdtop_table_hactive_width_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vlines_freerun:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  vlines_diff_flag:1;
        RBus_UInt32  vlines_the_same_flag:1;
        RBus_UInt32  vsync_freerun_when_unstable_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vlines_the_same_cnt_thr:4;
        RBus_UInt32  res3:12;
    };
}vdtop_vsync_pll_freerun_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc:8;
        RBus_UInt32  cagc_data_input_sel:2;
        RBus_UInt32  cagc_pll_input_sel:2;
        RBus_UInt32  res1:16;
        RBus_UInt32  fix_cgain:1;
        RBus_UInt32  res2:3;
    };
}vdtop_chroma_agc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_kill:4;
        RBus_UInt32  hlock_ckill:1;
        RBus_UInt32  vbi_ckill:1;
        RBus_UInt32  user_ckill_mode:2;
        RBus_UInt32  ckill_sel:1;
        RBus_UInt32  res1:23;
    };
}vdtop_chroma_kill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lose_chromalock_ckill:1;
        RBus_UInt32  lose_chromalock_level:3;
        RBus_UInt32  lose_chromalock_count:4;
        RBus_UInt32  chromalock_input_acc_num:2;
        RBus_UInt32  chromalock_input_acc_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  lose_acc_chromalock_level:3;
        RBus_UInt32  res2:17;
    };
}vdtop_chroma_lock_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc_igain:2;
        RBus_UInt32  flag358_cresample_lpf_sel:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  cnew_gate_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_chroma_loopfilter_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fixed_cstate:1;
        RBus_UInt32  cstate:3;
        RBus_UInt32  cresample_lpf_sel:2;
        RBus_UInt32  secam_cresample_lpf_sel:2;
        RBus_UInt32  cloop_freq_offset_limit:12;
        RBus_UInt32  cloop_freq_offset_limit_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cresample_signed_en:1;
        RBus_UInt32  res2:7;
    };
}vdtop_chroma_loopfilter_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cautopos:5;
        RBus_UInt32  fixed_burstgate:1;
        RBus_UInt32  chroma_burst5or10:1;
        RBus_UInt32  res1:25;
    };
}vdtop_chroma_autopos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ckill_lb_sel:1;
        RBus_UInt32  ckill_vsync_delay_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  chromalock_cstate:3;
        RBus_UInt32  chromalock_cstate_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_ckill_lb_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ckill_level_user_mode_value:14;
        RBus_UInt32  res1:1;
        RBus_UInt32  ckill_level_user_mode_en:1;
        RBus_UInt32  ckill_level_user_offset:14;
        RBus_UInt32  res2:1;
        RBus_UInt32  ckill_level_user_offset_en:1;
    };
}vdtop_ckill_gain_kill_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  badedit_line_num:3;
        RBus_UInt32  bad_phase_detect:1;
        RBus_UInt32  badedit_pulse_detect:1;
        RBus_UInt32  badedit_phase_lock_en:1;
        RBus_UInt32  phase_fast_lock_en:1;
        RBus_UInt32  fast_lock_en:1;
        RBus_UInt32  badedit_out_noise_thr:8;
        RBus_UInt32  badedit_in_noise_thr:8;
        RBus_UInt32  badedit_noisy_off_en:1;
        RBus_UInt32  res1:7;
    };
}vdtop_cstate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  badedit_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_badedit_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  badphase_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_badphase_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cstate_line_num:8;
        RBus_UInt32  res1:24;
    };
}vdtop_cstate_line_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_agc_peak_cnt:6;
        RBus_UInt32  chroma_peak_en:1;
        RBus_UInt32  new_cgain_level_en:1;
        RBus_UInt32  chroma_peak_en_pll:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cpeak_noise_thr1:8;
        RBus_UInt32  cpeak_noise_thr2:8;
        RBus_UInt32  cpeak_noisy_act_en:1;
        RBus_UInt32  cpeak_noisy_act_en_pll:1;
        RBus_UInt32  cpeak_gain_no_trunc_en:1;
        RBus_UInt32  res2:1;
    };
}vdtop_chroma_agc_peak_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_agc_peak_nominal:8;
        RBus_UInt32  res1:24;
    };
}vdtop_chroma_agc_peak_nominal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc_upper:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cagc_upper_xroot2_en:1;
        RBus_UInt32  close_ckill_loopfilter:1;
        RBus_UInt32  res2:14;
    };
}vdtop_close_ckill_loopfilter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc_peak_err_diff_sel:6;
        RBus_UInt32  cagc_burst_err_adj_en:1;
        RBus_UInt32  cagc_peak_err_adj_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_cagc_peak_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc_burst_err_diff_sel:6;
        RBus_UInt32  res1:26;
    };
}vdtop_cagc_peak_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cagc_peak_luma_ratio:6;
        RBus_UInt32  cdata_measure_lpf_en:1;
        RBus_UInt32  cdata_measure_big:1;
        RBus_UInt32  cdata_measure_thr:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  cdata_measure_keep_line_num:10;
        RBus_UInt32  res2:2;
    };
}vdtop_cagc_peak_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_delay:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cb_delay:3;
        RBus_UInt32  res2:25;
    };
}vdtop_chroma_delay_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_cgain_x4_en:1;
        RBus_UInt32  flag_burst_x4:1;
        RBus_UInt32  res1:30;
    };
}vdtop_burst_cgain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_cgain_mag_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_cgain_mag_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag358_cdto_inc:30;
        RBus_UInt32  flag358_iir_cunlock_en:1;
        RBus_UInt32  flag358_iir_en:1;
    };
}vdtop_flag358_cdto_inc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_coef_sel:1;
        RBus_UInt32  auto_burst_location_en:1;
        RBus_UInt32  burst_location_rst_en:1;
        RBus_UInt32  burst_location_lpf_reset:1;
        RBus_UInt32  burst_location_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  burst_location_fix:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  burst_location_center_modify_en:1;
        RBus_UInt32  burst_location_center_modify_sel:3;
        RBus_UInt32  burst_location_sel_modify_en:1;
        RBus_UInt32  burst_location_sel_modify_sel:3;
        RBus_UInt32  normal_burst_locationreg_en:1;
        RBus_UInt32  burst_location_selreg_en:1;
        RBus_UInt32  burst_location_sel_clock:1;
        RBus_UInt32  burst_location_fix_en:1;
    };
}vdtop_separate_443_358_new_function_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  normal_burst_location:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  burst_location_result:11;
        RBus_UInt32  res2:5;
    };
}vdtop_separate_443_358_new_function_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wide_burst_location_start:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  wide_burst_location_startreg_en:1;
        RBus_UInt32  wide_burst_location_endreg_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  wide_burst_location_end:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  wide_burst_location_modify_en:1;
        RBus_UInt32  wide_burst_location_modify_sel:3;
    };
}vdtop_separate_443_358_new_function_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  normal_burst_location_status:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  burst_location_sel_status:2;
        RBus_UInt32  res2:18;
    };
}vdtop_burst_location_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wide_burst_location_start_status:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  wide_burst_location_end_status:11;
        RBus_UInt32  res2:5;
    };
}vdtop_burst_location_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_hsync_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  sep_hsync_start:11;
        RBus_UInt32  res2:5;
    };
}vdtop_burst_location_hsync_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_location_auto_thr:8;
        RBus_UInt32  burst_location_magnitude_thr:8;
        RBus_UInt32  burst_location_enable_mode:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  burst_location_auto_en:1;
        RBus_UInt32  res2:3;
    };
}vdtop_burst_location_fw_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_path_coef_value:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_path_coef_num:7;
        RBus_UInt32  res2:12;
        RBus_UInt32  y_path_eq_en:1;
    };
}vdtop_y_path_eq_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_path_coef_value_r:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_path_coef_num_r:7;
        RBus_UInt32  res2:13;
    };
}vdtop_y_path_eq_filter_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palm_atone_counter:6;
        RBus_UInt32  flag625_vsync_l_th:1;
        RBus_UInt32  flag625_vsync_l_sel:1;
        RBus_UInt32  res1:24;
    };
}vdtop_palm_flag_compensation1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palm_atone_threshold:8;
        RBus_UInt32  res1:24;
    };
}vdtop_palm_flag_compensation2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  manual_mode_select:3;
        RBus_UInt32  state_machine_reset:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  auto_burst_switch_625only:1;
        RBus_UInt32  auto_625only_en:1;
        RBus_UInt32  auto_mode_en:1;
        RBus_UInt32  colour_mode_dark_set:3;
        RBus_UInt32  colour_mode_dark_check:1;
        RBus_UInt32  res2:20;
    };
}vdtop_manual_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decision_mode_status:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  set_mode_status:3;
        RBus_UInt32  res2:25;
    };
}vdtop_mode_detection_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_number:6;
        RBus_UInt32  disable_mode:1;
        RBus_UInt32  disable_mode_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_statistic_and_disable_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prefer_ntsc_palm_en:1;
        RBus_UInt32  prefer_secam_pali_en:1;
        RBus_UInt32  prefer_ntsc443_pal60_en:1;
        RBus_UInt32  prefer_ntsc50_paln_en:1;
        RBus_UInt32  prefer_ntsc_palm:1;
        RBus_UInt32  prefer_secam_pali:1;
        RBus_UInt32  prefer_ntsc443_pal60:1;
        RBus_UInt32  prefer_ntsc50_paln:1;
        RBus_UInt32  res1:24;
    };
}vdtop_prefer_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fix_secam_h:1;
        RBus_UInt32  fix_palor_h:1;
        RBus_UInt32  fix_443_h:1;
        RBus_UInt32  fix_625_h:1;
        RBus_UInt32  fix_secamflag_en:1;
        RBus_UInt32  fix_palorflag_en:1;
        RBus_UInt32  fix_443flag_en:1;
        RBus_UInt32  fix_625flag_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_state_machine_fix_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ped_reg_en:1;
        RBus_UInt32  vsyncreg_en:1;
        RBus_UInt32  cdtomem_reg_en:1;
        RBus_UInt32  vline625reg_en:1;
        RBus_UInt32  hagcreg_en:1;
        RBus_UInt32  colourmodereg_en:1;
        RBus_UInt32  hpixelreg_en:1;
        RBus_UInt32  hactivestartreg_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_vd_basic_register_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  statistic_multiplier:3;
        RBus_UInt32  secam_flag_freq_disable:1;
        RBus_UInt32  auto_secam_pali_method:2;
        RBus_UInt32  switch_palo_palm_method:2;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_s_m_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_y1delay:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  sv_cb1delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  sv_cr1delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  sv_y1delayreg_en:1;
        RBus_UInt32  sv_cb1delayreg_en:1;
        RBus_UInt32  sv_cr1delayreg_en:1;
        RBus_UInt32  res4:5;
    };
}vdtop_auto_pos_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y1delay:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cb1delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cr1delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  y1delayreg_en:1;
        RBus_UInt32  cb1delayreg_en:1;
        RBus_UInt32  cr1delayreg_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  new_y1delay_en:1;
        RBus_UInt32  new_cb1delay_en:1;
        RBus_UInt32  new_cr1delay_en:1;
        RBus_UInt32  res5:1;
    };
}vdtop_auto_pos_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ckill_y1delay:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ckill_cb1delay:6;
        RBus_UInt32  ckill_cr1delay:6;
        RBus_UInt32  ckill_y1delayreg_en:1;
        RBus_UInt32  ckill_cb1delayreg_en:1;
        RBus_UInt32  ckill_cr1delayreg_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  auto_ycdelay_mode_sel:3;
        RBus_UInt32  auto_ycdelay_modify_en:1;
        RBus_UInt32  auto_pos_mode_sel:3;
        RBus_UInt32  auto_pos_modify_en:1;
    };
}vdtop_auto_pos_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_sel_no_burst_625:2;
        RBus_UInt32  auto_443_358_method_525:2;
        RBus_UInt32  auto_443_358_method_625:2;
        RBus_UInt32  fix_358_h:1;
        RBus_UInt32  fix_358flag_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_flag358_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_burst_mag_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_no_burst_mag_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_burst_mag_filter_th:8;
        RBus_UInt32  res1:24;
    };
}vdtop_no_burst_mag_filter_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  no_burst_443_en:1;
        RBus_UInt32  burst_win_error:1;
        RBus_UInt32  paln_flag_new:1;
        RBus_UInt32  no_burst_flag:1;
        RBus_UInt32  burst_mag_trig_offset:4;
        RBus_UInt32  res1:24;
    };
}vdtop_no_burst_443_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag358_phase_diff_hcount:7;
        RBus_UInt32  flag358_secam_phase_diff_hcount_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_flag358_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag358_secam_phase_diff_dr:8;
        RBus_UInt32  res1:24;
    };
}vdtop_flag358_secam_phase_diff_dr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag358_secam_phase_diff_db:8;
        RBus_UInt32  res1:24;
    };
}vdtop_flag358_secam_phase_diff_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_mag_th_358:8;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_mag_th_358_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_colour_mode:3;
        RBus_UInt32  table_ped:1;
        RBus_UInt32  table_hpixel:2;
        RBus_UInt32  table_vline_625:1;
        RBus_UInt32  table_cagc_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_table1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_hagc:8;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_table2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_hactive_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_table3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_vactive_start:8;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_table4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_vactive_height:8;
        RBus_UInt32  res1:24;
    };
}vdtop_auto_mode_table5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  table_cdto:30;
        RBus_UInt32  res1:2;
    };
}vdtop_auto_mode_table6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_625_counter:8;
        RBus_UInt32  new_625flag_div_thr:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  new_625flag_window:10;
        RBus_UInt32  vline_625_src_sel:1;
        RBus_UInt32  vline_625_vloop_clr_en:1;
    };
}vdtop_flag_625_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_443_counter:8;
        RBus_UInt32  res1:24;
    };
}vdtop_flag_443_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_flag_counter:8;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_flag_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palm_flag_counter:8;
        RBus_UInt32  res1:24;
    };
}vdtop_palm_flag_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_valid_counter:8;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_valid_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  midpoint_adjustment:8;
        RBus_UInt32  res1:24;
    };
}vdtop_midpoint_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  freq_flag_threshold_tune:8;
        RBus_UInt32  res1:24;
    };
}vdtop_freq_flag_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frequency_valid_upper_limit:8;
        RBus_UInt32  res1:24;
    };
}vdtop_freq_valid_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frequency_valid_inner_limit:7;
        RBus_UInt32  condition_enable:1;
        RBus_UInt32  res1:24;
    };
}vdtop_freq_valid_inner_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frequency_valid_lower_limit:8;
        RBus_UInt32  res1:24;
    };
}vdtop_freq_valid_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_flag_frequency_upper_limit:8;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_flag_counter_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_flag_frequency_lower_limit:8;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_flag_counter_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palm_flag_phase_adjust:8;
        RBus_UInt32  pal_flag_threshold:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  palm_sw_input_sel:1;
        RBus_UInt32  palm_sw_acc_input_polar:1;
        RBus_UInt32  pal_sw_input_sel:1;
        RBus_UInt32  pal_sw_acc_input_polar:1;
        RBus_UInt32  palm_flag_limit_en:1;
        RBus_UInt32  res2:3;
    };
}vdtop_palm_flag_phase_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_mag_threshold:4;
        RBus_UInt32  burst_mag_trigger:4;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_lower_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  burst_noise_weighting:4;
        RBus_UInt32  burst_noise_weighting_auto:1;
        RBus_UInt32  auto_noburst_palflag_off:1;
        RBus_UInt32  secam_frequency_valid_enable:1;
        RBus_UInt32  vsync_select:1;
        RBus_UInt32  res1:24;
    };
}vdtop_burst_mag_choice_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  new_358_flag_cos_sin:1;
        RBus_UInt32  new_358_flag_cordic:1;
        RBus_UInt32  agc_gate_kill_sync_white_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_new_358_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_dto_358_cnt_up:11;
        RBus_UInt32  res1:21;
    };
}vdtop_new_358_cnt_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_dto_358_cnt_dn:11;
        RBus_UInt32  res1:21;
    };
}vdtop_new_358_cnt_dn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_count_th:10;
        RBus_UInt32  res1:22;
    };
}vdtop_sep_count_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_burst_start:11;
        RBus_UInt32  res1:21;
    };
}vdtop_sep_burst_start0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_burst_end:11;
        RBus_UInt32  res1:21;
    };
}vdtop_sep_burst_end0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sep_core_burst_rst_en:1;
        RBus_UInt32  sep_core_burst_rst:1;
        RBus_UInt32  res2:22;
    };
}vdtop_sep_burst_ro_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_358_core_burst:8;
        RBus_UInt32  sep_443_core_burst:8;
        RBus_UInt32  sep_358_core_burst_hsync:8;
        RBus_UInt32  sep_443_core_burst_hsync:8;
    };
}vdtop_sep_burst_ro_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_pal_secam_core_burst:8;
        RBus_UInt32  sep_pal_secam_core_burst_rst_en:1;
        RBus_UInt32  sep_pal_secam_core_burst_rst:1;
        RBus_UInt32  res1:22;
    };
}vdtop_sep_burst_ro3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sep_358_thl:8;
        RBus_UInt32  sep_443_thl:8;
        RBus_UInt32  res1:16;
    };
}vdtop_sep_burst_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_358_flag:1;
        RBus_UInt32  power_443_flag:1;
        RBus_UInt32  power_secam_flag:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sep_secam_thl_ratio:8;
        RBus_UInt32  sep_secam_thl:8;
        RBus_UInt32  sep_secam_f_sel:1;
        RBus_UInt32  secam_new_condition:1;
        RBus_UInt32  res2:6;
    };
}vdtop_sep_burst_flag1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_443358pk_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  mode_secam2_sel:2;
        RBus_UInt32  pk_foraudio:1;
        RBus_UInt32  res2:25;
    };
}vdtop_automode_443358pk_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_cpll_cdto_change_mode:3;
        RBus_UInt32  dark_cpll_cdto_change_en:1;
        RBus_UInt32  dark_fix_cgain:1;
        RBus_UInt32  dark_cagc_en:1;
        RBus_UInt32  dark_cagc_pll_input_sel:2;
        RBus_UInt32  dark_cagc:8;
        RBus_UInt32  dark_cresample_signed_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dark_chromalock_cstate:3;
        RBus_UInt32  dark_chromalock_cstate_en:1;
        RBus_UInt32  dark_cstate:3;
        RBus_UInt32  dark_fixed_cstate:1;
        RBus_UInt32  dark_phase_fast_lock_en:1;
        RBus_UInt32  dark_fast_lock_en:1;
        RBus_UInt32  dark_badedit_phase_lock_en:1;
        RBus_UInt32  dark_badedit_noisy_off_en:1;
    };
}vdtop_dark_cpll_cdetect_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_cpll_cdto_change_value:30;
        RBus_UInt32  res1:2;
    };
}vdtop_dark_cpll_cdetect_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_palm_sw_input_sel:1;
        RBus_UInt32  dark_palm_sw_acc_input_polar:1;
        RBus_UInt32  dark_pal_sw_input_sel:1;
        RBus_UInt32  dark_pal_sw_acc_input_polar:1;
        RBus_UInt32  dark_palm_flag_limit_en:1;
        RBus_UInt32  dark_palsw_level:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  dark_palm_flag_phase_adjust:8;
        RBus_UInt32  dark_palm_flag_counter:8;
        RBus_UInt32  res2:8;
    };
}vdtop_dark_cpll_pal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_lose_chromalock_level:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dark_lose_chromalock_count:4;
        RBus_UInt32  dark_lose_acc_chromalock_level:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_chromalock_input_acc_num:2;
        RBus_UInt32  dark_chromalock_input_acc_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dark_pal_flag_threshold:13;
        RBus_UInt32  res4:3;
    };
}vdtop_dark_cpll_chromalock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_cpll_start:1;
        RBus_UInt32  dark_cpll_auto_run:1;
        RBus_UInt32  dark_cpll_mode:2;
        RBus_UInt32  dark_cpll_user_mode:3;
        RBus_UInt32  dark_cpll_fix_mode_en:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc:1;
        RBus_UInt32  dark_cpll_mode_en_palm:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc50:1;
        RBus_UInt32  dark_cpll_mode_en_paln:1;
        RBus_UInt32  dark_cpll_mode_en_ntsc443:1;
        RBus_UInt32  dark_cpll_mode_en_pal60:1;
        RBus_UInt32  dark_cpll_mode_en_pali:1;
        RBus_UInt32  dark_cpll_chromalock_sel:1;
        RBus_UInt32  dark_cpll_vsync_num:8;
        RBus_UInt32  dark_cpll_decide_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dark_cpll_decide_mode_error:2;
        RBus_UInt32  res2:2;
    };
}vdtop_dark_cpll_controll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_cpll_ntsc_lock:1;
        RBus_UInt32  dark_cpll_palm_lock:1;
        RBus_UInt32  dark_cpll_ntsc50_lock:1;
        RBus_UInt32  dark_cpll_paln_lock:1;
        RBus_UInt32  dark_cpll_ntsc443_lock:1;
        RBus_UInt32  dark_cpll_pal60_lock:1;
        RBus_UInt32  dark_cpll_pali_lock:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dark_cpll_ntsc_pal_flag:1;
        RBus_UInt32  dark_cpll_palm_pal_flag:1;
        RBus_UInt32  dark_cpll_ntsc50_pal_flag:1;
        RBus_UInt32  dark_cpll_paln_pal_flag:1;
        RBus_UInt32  dark_cpll_ntsc443_pal_flag:1;
        RBus_UInt32  dark_cpll_pal60_pal_flag:1;
        RBus_UInt32  dark_cpll_pali_pal_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dark_cpll_ntsc_palm_flag:1;
        RBus_UInt32  dark_cpll_palm_palm_flag:1;
        RBus_UInt32  dark_cpll_ntsc50_palm_flag:1;
        RBus_UInt32  dark_cpll_paln_palm_flag:1;
        RBus_UInt32  dark_cpll_ntsc443_palm_flag:1;
        RBus_UInt32  dark_cpll_pal60_palm_flag:1;
        RBus_UInt32  dark_cpll_pali_palm_flag:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dark_cpll_loop_done:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  palm_flag_dark:1;
        RBus_UInt32  pal_flag_dark:1;
        RBus_UInt32  chromalock_dark:1;
        RBus_UInt32  chromalock_acc_dark:1;
    };
}vdtop_dark_cpll_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dark_cpll_burst_magnitude:8;
        RBus_UInt32  res1:24;
    };
}vdtop_dark_cpll_burstmag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlock_irq_en:1;
        RBus_UInt32  vlock_irq_en:1;
        RBus_UInt32  chromalock_irq_en:1;
        RBus_UInt32  noisy_irq_en:1;
        RBus_UInt32  proscan_irq_en:1;
        RBus_UInt32  mode_irq_en:1;
        RBus_UInt32  nosig_irq_en:1;
        RBus_UInt32  vcr_irq_en:1;
        RBus_UInt32  vd_irq_en:1;
        RBus_UInt32  hstate_err_irq_en:1;
        RBus_UInt32  res1:22;
    };
}vdtop_irq_mask1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_irq_en:1;
        RBus_UInt32  mv_irq_en:1;
        RBus_UInt32  coch_irq_en:1;
        RBus_UInt32  noisy_vbi_irq_en:1;
        RBus_UInt32  ddr_addr_irq_en:1;
        RBus_UInt32  vd_scene_change_irq_en:1;
        RBus_UInt32  res1:26;
    };
}vdtop_irq_mask2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_under_irq_en:1;
        RBus_UInt32  ad4_over_irq_en:1;
        RBus_UInt32  ad3_under_irq_en:1;
        RBus_UInt32  ad3_over_irq_en:1;
        RBus_UInt32  ad2_under_irq_en:1;
        RBus_UInt32  ad2_over_irq_en:1;
        RBus_UInt32  ad1_under_irq_en:1;
        RBus_UInt32  ad1_over_irq_en:1;
        RBus_UInt32  ad4_irq_sel:1;
        RBus_UInt32  ad3_irq_sel:1;
        RBus_UInt32  ad2_irq_sel:1;
        RBus_UInt32  ad1_irq_sel:1;
        RBus_UInt32  res1:20;
    };
}vdtop_irq_mask3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hlock_irq:1;
        RBus_UInt32  vlock_irq:1;
        RBus_UInt32  chromalock_irq:1;
        RBus_UInt32  noisy_irq:1;
        RBus_UInt32  proscan_irq:1;
        RBus_UInt32  mode_irq:1;
        RBus_UInt32  nosig_irq:1;
        RBus_UInt32  vcr_irq:1;
        RBus_UInt32  res1:24;
    };
}vdtop_irq_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_irq:1;
        RBus_UInt32  mv_irq:1;
        RBus_UInt32  coch_irq:1;
        RBus_UInt32  noisy_vbi_irq:1;
        RBus_UInt32  ddr_addr_irq:1;
        RBus_UInt32  vd_scene_change_irq:1;
        RBus_UInt32  hstate_err_irq:1;
        RBus_UInt32  res1:25;
    };
}vdtop_irq_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_underflow_irq:1;
        RBus_UInt32  ad4_overflow_irq:1;
        RBus_UInt32  ad3_underflow_irq:1;
        RBus_UInt32  ad3_overflow_irq:1;
        RBus_UInt32  ad2_underflow_irq:1;
        RBus_UInt32  ad2_overflow_irq:1;
        RBus_UInt32  ad1_underflow_irq:1;
        RBus_UInt32  ad1_overflow_irq:1;
        RBus_UInt32  res1:24;
    };
}vdtop_irq_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_under_threh:4;
        RBus_UInt32  adc_over_threh:4;
        RBus_UInt32  res1:24;
    };
}vdtop_adc_limit_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_value_big:1;
        RBus_UInt32  ad4_value_small:1;
        RBus_UInt32  ad3_value_big:1;
        RBus_UInt32  ad3_value_small:1;
        RBus_UInt32  ad2_value_big:1;
        RBus_UInt32  ad2_value_small:1;
        RBus_UInt32  ad1_value_big:1;
        RBus_UInt32  ad1_value_small:1;
        RBus_UInt32  adc_value_min_thr:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  adc_value_max_thr:10;
        RBus_UInt32  res2:2;
    };
}vdtop_adc_over_under_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clampagc_md_b_big:1;
        RBus_UInt32  clampagc_md_b_small:1;
        RBus_UInt32  clampagc_md_g_big:1;
        RBus_UInt32  clampagc_md_g_small:1;
        RBus_UInt32  clampagc_md_r_big:1;
        RBus_UInt32  clampagc_md_r_small:1;
        RBus_UInt32  clampagc_md_c_big:1;
        RBus_UInt32  clampagc_md_c_small:1;
        RBus_UInt32  clampagc_md_y_big:1;
        RBus_UInt32  clampagc_md_y_small:1;
        RBus_UInt32  res1:22;
    };
}vdtop_dgain_out_over_under_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dgain_out_data_min_thr:12;
        RBus_UInt32  dgain_out_data_max_thr:12;
        RBus_UInt32  res1:8;
    };
}vdtop_dgain_out_over_under_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldpaus_th:5;
        RBus_UInt32  ldp_switch_en:1;
        RBus_UInt32  ldp_det_en:1;
        RBus_UInt32  ld_pause_detect:1;
        RBus_UInt32  res1:24;
    };
}vdtop_ldpause_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  detect_vcr_when_h_unlock:1;
        RBus_UInt32  disable_blue_screen_when_vcr:1;
        RBus_UInt32  lock_h_on_no_signal:1;
        RBus_UInt32  freerun_sel:1;
        RBus_UInt32  vcr_disable:1;
        RBus_UInt32  vd_out_dvalid_sel_d1:1;
        RBus_UInt32  disp_freerun_sel:1;
        RBus_UInt32  coch_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_vcr_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cenable_line_count:8;
        RBus_UInt32  res1:24;
    };
}vdtop_cenable_line_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cbcr_ini_mux:1;
        RBus_UInt32  field_toggle_en:1;
        RBus_UInt32  auto_3dchange_noisy:1;
        RBus_UInt32  auto_3dchange_vcr:1;
        RBus_UInt32  res2:26;
    };
}vdtop_signal_stm_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdet_phase_err_status:14;
        RBus_UInt32  res1:18;
    };
}vdtop_cdetect_phase_err_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_g:2;
        RBus_UInt32  sw_pb_b:2;
        RBus_UInt32  sw_pr_r:2;
        RBus_UInt32  sw_comp:2;
        RBus_UInt32  res1:24;
    };
}vdtop_ad_sw_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamp_ad4:2;
        RBus_UInt32  clamp_ad3:2;
        RBus_UInt32  clamp_ad2:2;
        RBus_UInt32  clamp_ad1:2;
        RBus_UInt32  res1:24;
    };
}vdtop_clamp_updn_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clamp_d_dn_en:1;
        RBus_UInt32  clamp_d_up_en:1;
        RBus_UInt32  clamp_c_dn_en:1;
        RBus_UInt32  clamp_c_up_en:1;
        RBus_UInt32  clamp_b_dn_en:1;
        RBus_UInt32  clamp_b_up_en:1;
        RBus_UInt32  clamp_a_dn_en:1;
        RBus_UInt32  clamp_a_up_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_clamp_rgb_updn_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fb_delay:4;
        RBus_UInt32  fb_th:3;
        RBus_UInt32  aa3_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_fsw_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rgb2cvbs_dly:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  fb2rgb_dly:3;
        RBus_UInt32  res2:21;
    };
}vdtop_fsw_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fb_en:1;
        RBus_UInt32  fb_sw:1;
        RBus_UInt32  aa422_en:1;
        RBus_UInt32  out444_sel:1;
        RBus_UInt32  cout_limit:1;
        RBus_UInt32  fb_inv:1;
        RBus_UInt32  yout_limit:1;
        RBus_UInt32  scart_en:1;
        RBus_UInt32  outfifo_444_sel:1;
        RBus_UInt32  res1:23;
    };
}vdtop_fsw_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fb_thmin:4;
        RBus_UInt32  fb_thmax:4;
        RBus_UInt32  res1:24;
    };
}vdtop_fsw_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  contrast2:10;
        RBus_UInt32  res1:22;
    };
}vdtop_luma_contrast2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  brightness2:10;
        RBus_UInt32  res1:22;
    };
}vdtop_luma_brightness2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_saturation:10;
        RBus_UInt32  res1:22;
    };
}vdtop_chroma_saturation2_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_saturation:10;
        RBus_UInt32  res1:22;
    };
}vdtop_cb_sat_adj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peak_en2:1;
        RBus_UInt32  peak_gain2:3;
        RBus_UInt32  peak_range2:2;
        RBus_UInt32  res1:26;
    };
}vdtop_luma_peaking2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fbgain:7;
        RBus_UInt32  fbgain_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_fsw_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fb_status:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  scart_vbi_rgb_sel:2;
        RBus_UInt32  res2:26;
    };
}vdtop_fsw_input_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_reduce_ratio_b:8;
        RBus_UInt32  chroma_gain_reduce_ratio_g:8;
        RBus_UInt32  chroma_gain_reduce_ratio_r:8;
        RBus_UInt32  chroma_gain_reduce_ratio_c:8;
    };
}vdtop_chroma_reduce_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_gain_reduce_b_en:1;
        RBus_UInt32  chroma_gain_reduce_g_en:1;
        RBus_UInt32  chroma_gain_reduce_r_en:1;
        RBus_UInt32  chroma_gain_reduce_c_en:1;
        RBus_UInt32  res1:28;
    };
}vdtop_chroma_reduce_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yorr_in_offset_status:12;
        RBus_UInt32  res1:20;
    };
}vdtop_adcr_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uorg_in_offset_status:12;
        RBus_UInt32  res1:20;
    };
}vdtop_adcg_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vorb_in_offset_status:12;
        RBus_UInt32  res1:20;
    };
}vdtop_adcb_cali_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rgb_output_en:1;
        RBus_UInt32  res2:24;
    };
}vdtop_adc_gain_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_r:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  offset_r:8;
        RBus_UInt32  res2:8;
    };
}vdtop_adc_gain_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_g:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  offset_g:8;
        RBus_UInt32  res2:8;
    };
}vdtop_adc_gain_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_b:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  offset_b:8;
        RBus_UInt32  res2:8;
    };
}vdtop_adc_gain_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  component_color_matrix_r2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_r1:11;
        RBus_UInt32  res2:5;
    };
}vdtop_color_matrix_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  component_color_matrix_g1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_r3:11;
        RBus_UInt32  res2:5;
    };
}vdtop_color_matrix_rg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  component_color_matrix_g3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_g2:11;
        RBus_UInt32  res2:5;
    };
}vdtop_color_matrix_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  component_color_matrix_b2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  component_color_matrix_b1:11;
        RBus_UInt32  res2:5;
    };
}vdtop_color_matrix_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  component_color_matrix_b3:11;
        RBus_UInt32  res1:21;
    };
}vdtop_color_matrix_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_prblevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_blevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_pbblevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_blevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_slevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vbi_blevel:12;
        RBus_UInt32  res1:20;
    };
}vdtop_clamp_test_reg11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hphase_err_status:14;
        RBus_UInt32  res1:18;
    };
}vdtop_hdetect_phase_err_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avout_fifo_rd_ptr:11;
        RBus_UInt32  avout_fifo_sel:1;
        RBus_UInt32  res1:20;
    };
}vdtop_avout_fifo_rd_ptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_level_comp_manu:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_comp_manu_add:12;
        RBus_UInt32  res2:4;
    };
}vdtop_blank_level_manu_comp_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_level_r_manu:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_c_manu:12;
        RBus_UInt32  res2:4;
    };
}vdtop_blank_level_manu_c_r_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blank_level_b_manu:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  blank_level_g_manu:12;
        RBus_UInt32  res2:4;
    };
}vdtop_blank_level_manu_g_b_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  factory_flag:1;
        RBus_UInt32  fpga_test1:31;
    };
}vdtop_fpga_test_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}vdtop_fpga_test_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}vdtop_fpga_test_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test4:32;
    };
}vdtop_fpga_test_reg4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test5:32;
    };
}vdtop_fpga_test_reg5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test6:32;
    };
}vdtop_fpga_test_reg6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test7:32;
    };
}vdtop_fpga_test_reg7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test8:32;
    };
}vdtop_fpga_test_reg8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_notch_filter:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_flag_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  drdb_vlpf_en:1;
        RBus_UInt32  drdb_freq_const:1;
        RBus_UInt32  secam_y_lpf_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  secam_y_hpf_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  secam_y_fir_en:1;
        RBus_UInt32  res5:15;
    };
}vdtop_secam_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dr_offset:8;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_drfreq_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_offset:8;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_dbfreq_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_phase_diff_hcount:7;
        RBus_UInt32  secam_phase_diff_hcount_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_phase_diff_dr:8;
        RBus_UInt32  res1:24;
    };
}vdtop_phase_diff_dr_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_phase_diff_db:8;
        RBus_UInt32  res1:24;
    };
}vdtop_phase_diff_db_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gain_drdb:7;
        RBus_UInt32  secam_gain_drdb_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_drdb_gain_table_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gain_y:7;
        RBus_UInt32  secam_gain_y_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_y_gain_table_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gain_delay:5;
        RBus_UInt32  res1:27;
    };
}vdtop_secam_gain_dly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gain_debug:7;
        RBus_UInt32  secam_gain_debug_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_secam_gain_table_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_secam_phase_diff_hcount:7;
        RBus_UInt32  new_secam_phase_diff_hcount_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_new_secam_hcount_reset_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_secam_phase_diff_dr:8;
        RBus_UInt32  res1:24;
    };
}vdtop_new_secam_phase_diff_dr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_secam_phase_diff_db:8;
        RBus_UInt32  res1:24;
    };
}vdtop_new_secam_phase_diff_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_secam_cdto_inc:30;
        RBus_UInt32  res1:2;
    };
}vdtop_new_secam_cdto_inc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_gp_thl:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_gp_step:10;
        RBus_UInt32  res2:9;
        RBus_UInt32  secam_gp_en:1;
    };
}vdtop_secam_gp_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_initialization:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ps_updn_swap:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  v8format_sel:1;
        RBus_UInt32  res3:16;
        RBus_UInt32  vd_output_27_repeat_en:1;
        RBus_UInt32  vd_output_27_repeat_sel:1;
        RBus_UInt32  vd_output_135_sel:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  hresampler_combi_delay:3;
        RBus_UInt32  vdec_ps_disp_27_en:1;
    };
}vdtop_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_empty_status:1;
        RBus_UInt32  fifo_full_status:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  ps_540_coe_modify:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ps_540_select_tap:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ps_540_coe_en:1;
        RBus_UInt32  res4:7;
    };
}vdtop_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_i_gain:8;
        RBus_UInt32  ps_ndiv_status:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ps_up_status:1;
        RBus_UInt32  ps_dn_status:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ps_psel_status:3;
        RBus_UInt32  res3:9;
    };
}vdtop_i_gain_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_div:4;
        RBus_UInt32  ps_dn_en:1;
        RBus_UInt32  ps_up_en:1;
        RBus_UInt32  ndivload_en:1;
        RBus_UInt32  swallow_on_vsync:1;
        RBus_UInt32  swallow_freq_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  fifo_depth_wo_ps:8;
        RBus_UInt32  fifo_wo_ps:1;
        RBus_UInt32  res2:11;
    };
}vdtop_misc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_depth_min_status:8;
        RBus_UInt32  fifo_depth_min_clr:1;
        RBus_UInt32  res1:23;
    };
}vdtop_fifo_depth_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_depth_max_status:8;
        RBus_UInt32  fifo_depth_max_clr:1;
        RBus_UInt32  res1:23;
    };
}vdtop_fifo_depth_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ps_pselload:1;
        RBus_UInt32  ps_divload:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ps_dn_i:1;
        RBus_UInt32  ps_up_i:1;
        RBus_UInt32  res2:24;
    };
}vdtop_pll_debug_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ps_ndiv:4;
        RBus_UInt32  ps_psel:3;
        RBus_UInt32  pll_debug_en:1;
        RBus_UInt32  res1:24;
    };
}vdtop_pll_debug_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  k_sel:2;
        RBus_UInt32  lpf_en:1;
        RBus_UInt32  period_sel:2;
        RBus_UInt32  cnt_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ps_new_kp:3;
        RBus_UInt32  ps_new_kikp:1;
        RBus_UInt32  ps_fix_value:8;
        RBus_UInt32  ps_fix_en:1;
        RBus_UInt32  res2:11;
    };
}vdtop_disp_fsync_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_depth_wo_ps_max:8;
        RBus_UInt32  fifo_depth_wo_ps_min:8;
        RBus_UInt32  fifo_wo_ps_hlen_min:12;
        RBus_UInt32  fifo_wo_ps_adapt:1;
        RBus_UInt32  fifo_wo_ps_err_act:1;
        RBus_UInt32  fifo_wo_ps_clk_jump:1;
        RBus_UInt32  fifo_wo_ps_read_repeat_en:1;
    };
}vdtop_fifo_wo_ps_func_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_wo_ps_ps_ndiv0:5;
        RBus_UInt32  fifo_wo_ps_ps_psel0:3;
        RBus_UInt32  fifo_wo_ps_ps_divload0:1;
        RBus_UInt32  fifo_wo_ps_ps_pselload0:1;
        RBus_UInt32  fifo_wo_ps_ps_dn_i0:1;
        RBus_UInt32  fifo_wo_ps_ps_up_i0:1;
        RBus_UInt32  fifo_wo_ps_ps_ndiv1:5;
        RBus_UInt32  fifo_wo_ps_ps_psel1:3;
        RBus_UInt32  fifo_wo_ps_ps_divload1:1;
        RBus_UInt32  fifo_wo_ps_ps_pselload1:1;
        RBus_UInt32  fifo_wo_ps_ps_dn_i1:1;
        RBus_UInt32  fifo_wo_ps_ps_up_i1:1;
        RBus_UInt32  res1:8;
    };
}vdtop_fifo_wo_ps_clk_state_parameter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_out_line_len:12;
        RBus_UInt32  fifo_clk_state:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  stable_fifo_depth:8;
        RBus_UInt32  res2:8;
    };
}vdtop_fifo_status_no_pll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_test:7;
        RBus_UInt32  debug_test_enable:1;
        RBus_UInt32  res1:24;
    };
}vdtop_debug_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  muxanaloga:4;
        RBus_UInt32  muxanalogb:4;
        RBus_UInt32  res1:24;
    };
}vdtop_video_debug_analog_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  muxdigital:4;
        RBus_UInt32  debug_test_dac_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clk_sct_polarity:1;
        RBus_UInt32  clk_dac_polarity:1;
        RBus_UInt32  res2:24;
    };
}vdtop_video_debug_digital_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern_generator_enable:1;
        RBus_UInt32  pattern_gen_cvbs_mode:1;
        RBus_UInt32  pattern_gen_input_mode_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  crc_chk_sel:1;
        RBus_UInt32  pattern_gen_scart_en:1;
        RBus_UInt32  fifo_out_pattern_gen_en:1;
        RBus_UInt32  patgen_vline_en:1;
        RBus_UInt32  patgen_vline:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  patgen_vline_vactive_end:10;
        RBus_UInt32  res3:2;
    };
}vdtop_pattern_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vdtop_crc_result3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  patgen_burst_gain:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  patgen_sync_gain:3;
        RBus_UInt32  clk_polarity:1;
        RBus_UInt32  clk_vdadc_polarity:1;
        RBus_UInt32  res2:23;
    };
}vdtop_patgen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_27_1:1;
        RBus_UInt32  bist_mode_27_2:1;
        RBus_UInt32  bist_mode_dma:1;
        RBus_UInt32  bist_mode_fifo:1;
        RBus_UInt32  bist_mode_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_27_1:1;
        RBus_UInt32  bist_done_27_2:1;
        RBus_UInt32  bist_done_dma:1;
        RBus_UInt32  bist_done_fifo:1;
        RBus_UInt32  bist_done_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_27_1:1;
        RBus_UInt32  bist_fail_27_2:1;
        RBus_UInt32  bist_fail_dma:1;
        RBus_UInt32  bist_fail_fifo:1;
        RBus_UInt32  bist_fail_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mode_27_1:1;
        RBus_UInt32  bist_drf_mode_27_2:1;
        RBus_UInt32  bist_drf_mode_dma:1;
        RBus_UInt32  bist_drf_mode_fifo:1;
        RBus_UInt32  bist_drf_mode_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_resume_27_1:1;
        RBus_UInt32  bist_drf_resume_27_2:1;
        RBus_UInt32  bist_drf_resume_dma:1;
        RBus_UInt32  bist_drf_resume_fifo:1;
        RBus_UInt32  bist_drf_resume_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_done_27_1:1;
        RBus_UInt32  bist_drf_done_27_2:1;
        RBus_UInt32  bist_drf_done_dma:1;
        RBus_UInt32  bist_drf_done_fifo:1;
        RBus_UInt32  bist_drf_done_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_pause_27_1:1;
        RBus_UInt32  bist_drf_pause_27_2:1;
        RBus_UInt32  bist_drf_pause_dma:1;
        RBus_UInt32  bist_drf_pause_fifo:1;
        RBus_UInt32  bist_drf_pause_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_fail_27_1:1;
        RBus_UInt32  bist_drf_fail_27_2:1;
        RBus_UInt32  bist_drf_fail_dma:1;
        RBus_UInt32  bist_drf_fail_fifo:1;
        RBus_UInt32  bist_drf_fail_out:1;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mem_fail_27_1:6;
        RBus_UInt32  res1:26;
    };
}vdtop_bist_fail_27_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mem_fail_27_2:10;
        RBus_UInt32  res1:22;
    };
}vdtop_bist_fail_27_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mem_fail_dma:5;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_fail_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mem_fail_fifo:1;
        RBus_UInt32  res1:31;
    };
}vdtop_bist_fail_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mem_fail_out:4;
        RBus_UInt32  res1:28;
    };
}vdtop_bist_fail_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mem_fail_27_1:6;
        RBus_UInt32  res1:26;
    };
}vdtop_bist_drf_fail_27_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mem_fail_27_2:10;
        RBus_UInt32  res1:22;
    };
}vdtop_bist_drf_fail_27_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mem_fail_dma:5;
        RBus_UInt32  res1:27;
    };
}vdtop_bist_drf_fail_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mem_fail_fifo:1;
        RBus_UInt32  res1:31;
    };
}vdtop_bist_drf_fail_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_drf_mem_fail_out:4;
        RBus_UInt32  res1:28;
    };
}vdtop_bist_drf_fail_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_dvse_27_1:1;
        RBus_UInt32  mbist_dvs_27_1:4;
        RBus_UInt32  mbist_dvse_27_2:1;
        RBus_UInt32  mbist_dvs_27_2:4;
        RBus_UInt32  mbist_dvse_dma:1;
        RBus_UInt32  mbist_dvs_dma:4;
        RBus_UInt32  mbist_dvse_fifo:1;
        RBus_UInt32  mbist_dvs_fifo:4;
        RBus_UInt32  mbist_dvse_out:1;
        RBus_UInt32  mbist_dvs_out:4;
        RBus_UInt32  res1:7;
    };
}vdtop_bist_dvse_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_dvse_dma_2:1;
        RBus_UInt32  mbist_dvs_dma_2:4;
        RBus_UInt32  mbist_dvse_fifo_2:1;
        RBus_UInt32  mbist_dvs_fifo_2:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  mbist_ls_cntl:1;
        RBus_UInt32  res2:19;
    };
}vdtop_bist_dvse_dvs2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  moniter_h_addr:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  moniter_v_addr:9;
        RBus_UInt32  moniter_size:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  moniter_field:1;
        RBus_UInt32  ycbcr_moniter_en:1;
    };
}vdtop_ycbcr_moniter_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vd_yout_moniter:10;
        RBus_UInt32  res1:22;
    };
}vdtop_ycbcr_moniter_value_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vd_cbout_moniter:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vd_crout_moniter:10;
        RBus_UInt32  res2:6;
    };
}vdtop_ycbcr_moniter_value_cbcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_updn_debug_dn:1;
        RBus_UInt32  adc_updn_debug_up:1;
        RBus_UInt32  adc_updn_debug_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  moniter_cr_value:8;
        RBus_UInt32  moniter_cb_value:8;
        RBus_UInt32  moniter_y_value:8;
    };
}vdtop_adc_updn_ctrl_RBUS;




#endif 


#endif 
