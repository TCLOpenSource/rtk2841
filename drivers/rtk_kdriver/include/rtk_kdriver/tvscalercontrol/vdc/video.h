
/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2017/03/16 14:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */
#ifndef __DRAGON_VIDEO_H__
#define __DRAGON_VIDEO_H__

#ifdef __cplusplus
extern "C" {
#endif

/*================ Module dependency  =============== */
#include <tvscalercontrol/scaler/source.h>
#include <scalercommon/vdcCommon.h>

#include <mach/rtk_log.h>
#define TAG_NAME_VDC "VDC"  //sunray add for log 2016-06-06

#define _jj_change_lock_function
#define _VDC_Vactive_set		/* oliver+, 2012_06_26 */
#define _vdc_adjust_v_parameter
#define wait_3d_ready	1
#define _Reset_Hpll	// 20160902

#ifndef CONFIG_SCART_ENABLE
#define CONFIG_SCART_ENABLE
#endif
#define CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL	/*don't modified this func. If there has error of this funciton, please connect to jj. */
//#define VD_Digital_FIFO

//#define VD_hdto_adjust
#define NoBurstChangMode

#define CONFIG_ENABLE_VDC_CPEAK_CONTROL
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
#define CONFIG_ENABLE_VDC_CKILL_CONTROL
#endif

#define CONFIG_ENABLE_VDC_CKILL_CONTROL

#define CONFIG_VD_AUTO_BURST_POS_ENABLE
#ifdef CONFIG_VD_AUTO_BURST_POS_ENABLE
#define VD_AUTO_BURST_POS_AUTOMODE
//#define VD_AUTO_BURST_POS_MODE2	/* enable PAL-M, PAL-N, NTSC443, PAL-60 */
#endif
#define VD_BURST_LOCATION_AUTO



//#define CONFIG_ENABLE_VDC_BURST_CHECK

#define CONFIG_ENABLE_VDC_MV_CHECK

//#define CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE

#define CONFIG_ENABLE_VDC_OVER_MODULATION
//#define scart_vdc_auto_balance_en

#define VDC_SyncReduction_test	/* AV, external Demod sync reduction no-signal issue */
#define ucAdcNeg_Sing 	0xc
#define ucAdcNeg_Nosig 	0x9

/////////////////////////////////////////////////////////////////////////////////
extern unsigned char vdc_108M_lpf;

#define cHsync_start_3D			0x2c
#define cHsync_start_1D			0x00
#define cHsync_start_1Dnoburst	0x16
#define cHsync_start_SV_PAL		0x0c

#define VDC_V_LOCK_NEW		0x00
#define VDC_V_LOCK_OLD			0x01
#define VDC_V_MV_SIGNAL		0x02
#define VDC_V_LOCK_DEF			VDC_V_LOCK_NEW

#define SCART_RGB_CVBS_THRESHOLD    6

#define AVD_27M_CONTROL_BY_AP 1

/* ********************************************************************
Debug Msg definition
********************************************************************* */
#define VDC_XDATA
// 0xb80196b4 (VDTOP_FPGA_TEST_REG2_reg)
typedef enum {
	VDC_MSG_NONE=_ZERO,
	VDC_MSG_INIT=_BIT0,		/* initial setting */
	VDC_MSG_RESET=_BIT1,		/* reset flow */
	VDC_MSG_STATUS=_BIT2,		/* loop status of VDC */
	VDC_MSG_ERROR=_BIT3,		/* non standard signal */
	VDC_MSG_DGAIN=_BIT4,		/* dgain, under, peak white */
	VDC_MSG_CHROMA=_BIT5,	/* chroma control, cpeak */
	VDC_MSG_HDTO=_BIT6,		/* HDTO funciton */
	VDC_MSG_YCSEP=_BIT7,		/* YC sepatation */
	VDC_MSG_SCART=_BIT8,		/* SCART setting */
	VDC_MSG_FACT=_BIT9,		/* factory menu */
	VDC_MSG_TVSCAN=_BIT10,	/* TV scan */
	VDC_MSG_DEBUG1=_BIT11,	/* others setting */
	VDC_MSG_DEBUG2=_BIT12,	/* others setting */
	VDC_MSG_DEBUG3=_BIT13,	/* others setting */

	VDC_MSG_TVCHCH=_BIT15,	/* TV channel change */
	VDC_MSG_TVCHCH_DETAIL=_BIT16,	/* TV channel change */
	VDC_MSG_DEBUG_P=_BIT17,	/* debug print */

	VDC_MSG_ALL_MSG=0x000FFFFF,

//	VDC_MSG_EXTERNAL_AUTOSCAN_FLAG = _BIT26,  	/* External auto scan flag */

//	VDC_MSG_INTERNAL_CH_FLAG=_BIT27,  	/* internal ch change flag */
//	VDC_MSG_EXTERNAL_CH_FLAG=_BIT28,	/* external ch change flag */
	VDC_MSG_INT_SCAN_FLAG=_BIT27,	/* internal auto scan flag (for 1 channel) */

	VDC_MSG_SCAN_FLAG=_BIT29,	/* auto scan flag (for Start to End, not to do freerun set) */
	VDC_MSG_CH_CHANGE=_BIT30,	/* channel change */

	VDC_Factory_Mode_debug=_BIT31,	/* for Factory mode debug, loop check function return */
}VDC_MSG_LEVEL;

extern VDC_MSG_LEVEL  g_vdc_msg_level;

#define VDC_CALLER(vdc_level)			\
{										\
	if((g_vdc_msg_level&vdc_level)!=0)	\
	{									\
		asm("or $5,$31,$0");				\
		rtd_printk(KERN_EMERG, TAG_NAME_VDC, "###### VDC API called at %x --- ");	\
	}									\
}

#define VDC_DEBUG_MSG(vdc_level,string,args...)	\
{												\
	if(vdc_level==VDC_MSG_INIT)					\
	{											\
		rtd_printk(KERN_DEBUG, TAG_NAME_VDC, "[INIT]" string, ##args);		\
	}											\
	if(vdc_level==VDC_MSG_RESET)				\
	{										\
		rtd_printk(KERN_DEBUG, TAG_NAME_VDC, "[RESET]" string, ##args);		\
	}										\
	if(vdc_level==VDC_MSG_ERROR)				\
	{										\
		rtd_printk(KERN_DEBUG, TAG_NAME_VDC, "[error]" string, ##args);				\
	}										\
	if(((g_vdc_msg_level&vdc_level)!=0)) {		\
		if(vdc_level==VDC_MSG_STATUS)			\
		{										\
			rtd_printk(KERN_DEBUG, TAG_NAME_VDC, "[status]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_DGAIN)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[DG]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_CHROMA)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[C]" string, ##args);			\
		}										\
		if(vdc_level==VDC_MSG_HDTO)				\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[HDTO]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_YCSEP)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[yc]" string, ##args);			\
		}										\
		if(vdc_level==VDC_MSG_SCART)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[SCART]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_FACT)				\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[FACTORY]" string, ##args);	\
		}										\
		if(vdc_level==VDC_MSG_TVSCAN)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[SCAN]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_DEBUG1)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[D1]" string, ##args);			\
		}										\
		if(vdc_level==VDC_MSG_DEBUG2)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[D2]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_DEBUG3)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[D3]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_TVCHCH)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[tch]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_TVCHCH_DETAIL)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[tchD]" string, ##args);		\
		}										\
		if(vdc_level==VDC_MSG_DEBUG_P)			\
		{										\
			rtd_printk(KERN_EMERG, TAG_NAME_VDC, "[Debug]" string, ##args);		\
		}										\
	}											\
}

#define SET_ATV_VDC_DEBUG_MSG_LEVEL(x) (g_vdc_msg_level=x)
#define GET_ATV_VDC_DEBUG_MSG_LEVEL() (g_vdc_msg_level)



/*==================== Definitions ================ */

/* ========== FrequencyOffset Related parameters ========== */
#define	Fn5_min	2782461128	//2782461128
#define	Fn5_max	2904463118	//2891661468
#define	Fn4_min	Fn5_max		//2917264768
#define	Fn4_max	3037679748	//3021366820
#define	Fn3_min	Fn4_max		//3053992676
#define	Fn3_max	3169706334	//3166554564
#define	Fn2_min	Fn3_max		//3172858104
#define	Fn2_max	3314726950	//3292869692
#define	Fn1_min	Fn2_max		//3336584208
#define	Fn1_max	3463100254	//3438580728
#define	F0_min	Fn1_max		//3487619780
#define	F0_max	3595962604	//3559596216
#define	Fp1_min	F0_max		//3632328992
#define	Fp1_max	3726953618	//3697302080
#define	Fp2_min	Fp1_max		//3756605156
#define	Fp2_max	3875779526	//3845372156
#define	Fp3_min	Fp2_max		//3906186896
#define	Fp3_max	4007628186	//4000482488
#define	Fp4_min	Fp3_max		//4014773884
#define	Fp4_max	4166952088	//4146018088
#define	Fp5_min	Fp4_max		//4187886088
#define	Fp5_max	4275799704	//4275799704

typedef enum VDC_FSC_DETECT_REG {
	/* 0  */ _FSC_0hz = 0,
	/* 1  */ _FSC_p1hz,
	/* 2  */ _FSC_p2hz,
	/* 3  */ _FSC_p3hz,
	/* 4  */ _FSC_p4hz,
	/* 5  */ _FSC_p5hz,
	/* 6  */ _FSC_n1hz,
	/* 7  */ _FSC_n2hz,
	/* 8  */ _FSC_n3hz,
	/* 9  */ _FSC_n4hz,
	/* 10 */ _FSC_n5hz,
	/* 11 */ _FSC_overflow,
} VDC_FSC_DETECT_REG;

/* ========== ========== ========== ========== */

// VDC Register Address
#define _VIDEO_INDEX	0xb8010000

// ICS = IdentifyColorStandard
#define ICS_STAGE_INIT  0
#define ICS_STAGE_CHECK_VDC_NO_SIGNAL 1
#define ICS_STAGE_CHECK_VDC_BURST_DETECT 2
#define ICS_STAGE_COUNT  3
#define ICS_STAGE_CHECK_MODE  4
#define ICS_STAGE_FIANL  5
#define ICS_STAGE_READY  0xFF
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
typedef enum VDC_POWER_SETTING {
	VDC_Power_off = 0,
	VDC_Power_on = 1,
	VDC_Power_saving = 2,
} VDC_POWER_SETTING;

typedef enum VDC_IRQ_SWITCH {
	VDC_vcr_irq_enable = 0,
	VDC_vcr_irq_disable,
	VDC_Nosig_irq_enable,
	VDC_Nosig_irq_disable,
	VDC_Mode_irq_enable,
	VDC_Mode_irq_disable,
	VDC_Proscan_irq_enable,
	VDC_Proscan_irq_disable,
	VDC_Noisy_irq_enable,
	VDC_Noisy_irq_disable,
	VDC_chromalock_irq_enable,
	VDC_chromalock_irq_disable,
	VDC_vlock_irq_enable,
	VDC_vlock_irq_disable,
	VDC_hlock_irq_enable,
	VDC_hlock_irq_disable,
	VDC_vd_scene_change_irq_enable,
	VDC_vd_scene_change_irq_disable,
	VDC_ddr_addr_irq_enable,
	VDC_ddr_addr_irq_disable,
	VDC_Noisy_vbi_irq_enable,
	VDC_Noisy_vbi_irq_disable,
	VDC_Coch_irq_enable,
	VDC_Coch_irq_disable,
	VDC_Field_irq_enable,
	VDC_Field_irq_disable,
	VDC_All_irq_disable,
} VDC_IRQ_SWITCH;

typedef enum VDC_Vloop_Control {
	VDC_vloop_speed0 = 0,
	VDC_vloop_speed1,
	VDC_vloop_DEFAULT,
	VDC_vloop_FAST,
} VDC_Vloop_Control;

typedef enum VDC_Vsync_Output_Mode {
	VDC_org_vsync = 0,		// 0: output the vertical PLL sync, except during VCR trick modes when the directly detected vsync is used
	VDC_directly_vsync,		// 1: output the directly detected vsync
	VDC_Vpll_vsync,			// 2: output the vertical PLL derived vsync
	VDC_Vpll2_vsync,		// 3: output the PLL vsync in alternate mode
} VDC_Vsync_Output_Mode;

typedef enum VDC_VSTATE_COUNT_REG {
	vstate_count_default = 0,
	vstate_count_fast,
} VDC_VSTATE_COUNT_REG;

typedef enum VDC_MODE_COUNT_REG {
	mode_count_default = 0,
	mode_count_fast,
} VDC_MODE_COUNT_REG;

typedef enum VDC_KillGate_Control {
	VDC_kg_off = 0,
	VDC_kg_ode1,		// enabled - if sync-tip gate is killed, kill backproch gate
	VDC_kg_mode2,		// enabled - if sync-tip gate is killed, kill backproch gate, except during vsync
	VDC_kg_mode3,		// enabled - if sync-tip gate is killed, don't kill backporch gate
} VDC_KillGate_Control;

typedef enum VDC_Mode_secam2 {
	VDC_oldSecam = 0,		// 0: only output flag
	VDC_newSecam_flag,		// 1: Always replace secam_flag  in Automode decision tree
	VDC_orSecam_flag,		// 2: use (power_secam_flag(new) || secam_flag(origianl)) in automode decision tree
	VDC_andSecam_flag,		// 3: use (power_secam_flag(new) && secam_flag(origianl)) in automode decision tree
} VDC_Mode_secam2;

typedef enum VDC_Mode_443358pk {
	VDC_old443358 = 0,		// 0: only output flag
	VDC_new443358_flag,	// 1: Always replace detect358_flag & detect443_flag in Automode decision tree
	VDC_or443358_flag,		// 2: use (new_358_flag_cos_sin (new) || detect358_flag (origianl)) in automode decision tree
	VDC_and443358_flag,	// 3: use (new_358_flag_cos_sin (new) && detect358_flag (origianl)) in automode decision tree
} VDC_Mode_443358pk;

typedef enum _VDC_SCREEN_BG_COLOR {
	SCREEN_BG_BLUE = 0,
	SCREEN_BG_BLACK = 1,
} VDC_SCREEN_BG_COLOR;

typedef enum _VDC_BLUE_SCREEN_MODE {
	BLUE_SCREEN_DISABLE = 0,
	BLUE_SCREEN_ENABLE,
	BLUE_SCREEN_AUTO,
} VDC_BLUE_SCREEN_MODE;

typedef enum _VDC_ATUO_SECAM_FLAG_SEL {
	SEL_SECAM = 0,		// 0 : secam flag
	SEL_PAL,			// 1 : pal flag
	SEL_PALh_SECAMl,	// 2 : pal flag is high and secam flag is low
	SEL_SECAMh_PALl,	// 3 : secam flag is high and pal flag is low
} VDC_ATUO_SECAM_FLAG_SEL;

typedef enum _VDC_BURST_GATE_MODE {
	MODE_DEFAULT = 0,
	MODE_SECAM,
} VDC_BURST_GATE_MODE;

typedef enum _VDC_SECAM_FLAG_SETTING {
	SETTING_CONDITION_OFF = 0,
	SETTING_CONDITION_ON,
} VDC_SECAM_FLAG_SETTING;

typedef enum _VDC_CKill_MODE {
	CKill_AUTO = 0,
	CKill_ON = 1,
	CKill_OFF = 2,
} VDC_CKill_MODE;

typedef enum _VDC_DCTI_MODE {
	VDC_DCTI_Table_1 = 0,
	VDC_DCTI_Table_2,
	VDC_DCTI_Table_3,
	VDC_DCTI_Table_4,
	VDC_DCTI_Table_5,
} VDC_DCTI_MODE;

typedef enum VDC_VIDEO_Cresample_Lpf_MODE {
	VDC_VIDEO_Cresample_Lpf_DISABLE = 0,
	VDC_VIDEO_Cresample_Lpf_ENABLE,
} VDC_VIDEO_Cresample_Lpf_MODE;

typedef enum VDC_SECAM_Notch_Filter_MODE {
	VDC_SECAM_FIR = 0,
	VDC_SECAM_IIR_0_7,
	VDC_SECAM_IIR_0_5,
	VDC_SECAM_IIR_0_4,
} VDC_SECAM_Notch_Filter_MODE;

typedef enum _VDC_FRAME_RATE {
	VDC_FRAME_RATE_50HZ = 0,
	VDC_FRAME_RATE_60HZ
} VDC_FRAME_RATE;

typedef enum _VDC_FREERUN_LINE {
	VDC_FREERUN_DISABLE = 0,
	VDC_FREERUN_525,
	VDC_FREERUN_625
} VDC_FREERUN_LINE;

typedef enum _VDC_DISABLE_MODE {
	_VDC_DISABLE_MODE_525 = 0,
	_VDC_DISABLE_MODE_625 = 1,
	_VDC_DISABLE_MODE_DIDABLE = 2,
} VDC_DISABLE_MODE;

typedef enum _VDC_DISABLE_MODE_TYPE {
	_VDC_DISABLE_525_INPUT = 0,
	_VDC_DISABLE_625_INPUT,
} _VDC_DISABLE_MODE_TYPE;

typedef enum _VDC_VIDEO_SCALE_INFO {
	VDC_VIDEO_SCALE_IHTOTAL = 0,
	VDC_VIDEO_SCALE_IHSTART,
	VDC_VIDEO_SCALE_IHWIDTH,
	VDC_VIDEO_SCALE_IVSTART,
	VDC_VIDEO_SCALE_IVHEIGHT
} VDC_VIDEO_SCALE_INFO;

typedef enum VDC_VIDEO_AVOUT_ENABLE {
	VDC_AVOUT_DISABLE = 0,
	VDC_AVOUT_ENALBE,
} VDC_VIDEO_AVOUT_ENABLE;

typedef enum VDC_VIDEO_AVOUT_MODE {
	VDC_AVOUT_CVBS_NO_FIL_NO_AGC = 0x0,
	VDC_AVOUT_CVBS_WITH_FIL_NO_AGC = 0x01,
	VDC_AVOUT_CVBS_WITH_FIL_WITH_AGC = 0x02,
	VDC_AVOUT_YC_WITH_FIL_NO_AGC = 0x03,
	VDC_AVOUT_YC_WITH_FIL_WITH_AGC = 0x04,
	VDC_AVOUT_IFD_DATA = 0x05,
	VDC_AVOUT_AudioSIF_DATA = 0x06,
	VDC_AVOUT_test_in = 0x07,	// (1800_3084 bit23~12)
	VDC_AVOUT_hsync = 0x08,	// (18019080[29:8])
	VDC_AVOUT_vbi_lpf_data = 0x09,
	VDC_AVOUT_if_debug = 0x0a,

	VDC_AVOUT_BYPASS_VIN0P = 0x10,
	VDC_AVOUT_BYPASS_VIN1P = 0x11,
	VDC_AVOUT_BYPASS_VIN2P = 0x12,
	VDC_AVOUT_BYPASS_VIN3P = 0x13,
	VDC_AVOUT_BYPASS_VIN4P = 0x14,
	VDC_AVOUT_BYPASS_VIN5P = 0x15,
	VDC_AVOUT_BYPASS_VIN6P = 0x16,
	VDC_AVOUT_BYPASS_VIN7P = 0x17,
	VDC_AVOUT_BYPASS_VIN8P = 0x18,
	VDC_AVOUT_BYPASS_VIN9P = 0x19,
	VDC_AVOUT_BYPASS_VIN10P = 0x1a,
	VDC_AVOUT_BYPASS_VIN11P = 0x1b,
} VDC_VIDEO_AVOUT_MODE;

typedef enum VDC_SCART_sel {
	VDC_CVBS_only = 0,
	VDC_RGB_only,
	VDC_By_FSW,
} VDC_SCART_sel;

typedef enum VDC_OUT444_sel {
	VDC_422output = 0,
	VDC_444output,
} VDC_OUT444_sel;

typedef enum VDC_VIDEO_AVout_Mode {
	VDC_CVBS_Mode1 = 0,		// Clamped CVBS data without fe_fil and agc
	VDC_CVBS_Mode2,			// Clamped CVBS with fe_fil, without agc
	VDC_CVBS_Mode3,			// Clamped CVBS with fe_fil, with agc
	VDC_SV_Mode1,				// Clamped Y+ C with fe_fil, without agc
	VDC_SV_Mode2,				// Clamped Y+ C with fe_fil, with agc
	VDC_IFD_unclamped,		// unclamped IF Demod Data
	VDC_Audio_SIF_out,		// Audio SIF output
#ifdef RFSOURCE_AVOUTPUT_AMP_FINETUNE
	VDC_reserved1,
	VDC_reserved2,
	VDC_reserved3,
#endif
} VDC_VIDEO_AVout_Mode;

typedef enum VDC_VIDEO_108M_FrontDigitalFilter {
	VDC_108M_FDF_85MHZ = 0,
	VDC_108M_FDF_55MHZ,
	VDC_108M_FDF_60MHZ,
	VDC_108M_FDF_65MHZ,
	VDC_108M_FDF_70MHZ,
	VDC_108M_FDF_75MHZ,
	VDC_108M_FDF_80MHZ,
	VDC_108M_FDF_BYPASS,
} VDC_VIDEO_108M_FrontDigitalFilter;

typedef enum VDC_VIDEO_CONTROL2 {
	VDC_CONTROL2_ClearAll = 0,
	VDC_hagc_enable,	/* [0] = 0 */
	VDC_hagc_disable,	/* [0] = 1 */
	VDC_cagc_enable,	/* [1] = 0 */
	VDC_cagc_disable,	/* [1] = 1 */
	VDC_bgate_raw_sel_disable,	/* [2] = 0 */
	VDC_bgate_raw_sel_enable,	/* [2] = 1 */
	VDC_dc_clamp_mode_auto,		/* [5:4] = 00 */
	VDC_dc_clamp_mode_bk_porch,	/* [5:4] = 01 */
	VDC_dc_clamp_mode_synctip,	/* [5:4] = 10 */
	VDC_dc_clamp_mode_off,		/* [5:4] = 11 */
	VDC_mv_hagc_mode_off,	/* [6] = 0 */
	VDC_mv_hagc_mode_on,	/* [6] = 1 */
	VDC_hagc_field_mode_off,	/* [7] = 0 */
	VDC_hagc_field_mode_on,	/* [7] = 1 */
	VDC_fix_dgain_disable,	/* [28] = 0 */
	VDC_fix_dgain_enable,	/* [28] = 1 */
	VDC_mv_detect_sel_hpll,	/* [29] = 0 */
	VDC_mv_detect_sel_vpll,	/* [29] = 1 */
} VDC_VIDEO_CONTROL2;

typedef enum VDC_VIDEO_BASIC_REGISTER {
	VDC_BASIC_REG_ClearAll = 0,
	VDC_ped_reg_enable,	// [0]
	VDC_ped_reg_disable,
	VDC_vsyncreg_enable,	// [1]
	VDC_vsyncreg_disable,
	VDC_cdtomem_reg_enable,	// [2]
	VDC_cdtomem_reg_disable,
	VDC_vline625reg_enable,		// [3]
	VDC_vline625reg_disable,
	VDC_hagcreg_enable,	// [4]
	VDC_hagcreg_disable,
	VDC_colourmodereg_enable,	// [5]
	VDC_colourmodereg_disable,
	VDC_hpixelreg_enable,	// [6]
	VDC_hpixelreg_disable,
	VDC_hactivestartreg_enable,	// [7]
	VDC_hactivestartreg_disable,
} VDC_VIDEO_BASIC_REGISTER;

typedef enum VDC_VSYNC_CLAMP_MODE {
	VDC_vsync_clamp_disable,
	VDC_vsync_clamp_enable,
	VDC_vsync_clamp_mode1,	 // enabled except for noisy signals
	VDC_vsync_clamp_mode2,	 // enabled only for clean VCR signals
} VDC_VSYNC_CLAMP_MODE;

typedef enum VDC_VIDEO_27M_FrontDigitalFilter {
	VDC_27M_FDF_BYPASS = 0,
	VDC_27M_FDF_55MHZ,
	VDC_27M_FDF_60MHZ,
	VDC_27M_FDF_55nMHZ,
	VDC_27M_FDF_65MHZ,
	VDC_27M_FDF_70MHZ,
	VDC_27M_FDF_75MHZ,
	VDC_27M_FDF_Table,
} VDC_VIDEO_27M_FrontDigitalFilter;

typedef enum VDC_VIDEO_27M_LPF_COEF {
	VDC_27M_LPF_Default = 0,
	VDC_27M_LPF_40MHz,
	VDC_27M_LPF_43MHz,
} VDC_VIDEO_27M_LPF_COEF;

typedef enum VDC_VIDEO_FIXCSTATE_MODE {
	VDC_NOT_FIX_CSTATE0 = 0x00,
	VDC_NOT_FIX_CSTATE1 = 0x01,
	VDC_NOT_FIX_CSTATE2 = 0x02,
	VDC_NOT_FIX_CSTATE3 = 0x03,
	VDC_NOT_FIX_CSTATE4 = 0x04,
	VDC_NOT_FIX_CSTATE5 = 0x05,
	VDC_FIX_CSTATE0 = 0x10,
	VDC_FIX_CSTATE1 = 0x11,
	VDC_FIX_CSTATE2 = 0x12,
	VDC_FIX_CSTATE3 = 0x13,
	VDC_FIX_CSTATE4 = 0x14,
	VDC_FIX_CSTATE5 = 0x15,
	VDC_CSTATE_RESET = VDC_NOT_FIX_CSTATE3,
} VDC_VIDEO_FIXCSTATE_MODE;

typedef enum VDC_VIDEO_FIXVSTATE_MODE {
	VDC_NOT_FIX_VSTATE0 = 0x00,
	VDC_NOT_FIX_VSTATE1 = 0x01,
	VDC_NOT_FIX_VSTATE2 = 0x02,
	VDC_NOT_FIX_VSTATE3 = 0x03,
	VDC_FIX_VSTATE0 = 0x10,
	VDC_FIX_VSTATE1 = 0x11,
	VDC_FIX_VSTATE2 = 0x12,
	VDC_FIX_VSTATE3 = 0x13,
	VDC_VSTATE_RESET = VDC_NOT_FIX_VSTATE1,
} VDC_VIDEO_FIXVSTATE_MODE;

typedef enum VDC_VIDEO_FIXHSTATE_MODE {
	VDC_NOT_FIX_HSTATE0 = 0x00,
	VDC_NOT_FIX_HSTATE1 = 0x01,
	VDC_NOT_FIX_HSTATE2 = 0x02,
	VDC_NOT_FIX_HSTATE3 = 0x03,
	VDC_NOT_FIX_HSTATE4 = 0x04,
	VDC_NOT_FIX_HSTATE5 = 0x05,
	VDC_FIX_HSTATE0 = 0x10,
	VDC_FIX_HSTATE1 = 0x11,
	VDC_FIX_HSTATE2 = 0x12,
	VDC_FIX_HSTATE3 = 0x13,
	VDC_FIX_HSTATE4 = 0x14,
	VDC_FIX_HSTATE5 = 0x15,
	VDC_HSTATE_RESET = VDC_NOT_FIX_HSTATE5,
} VDC_VIDEO_FIXHSTATE_MODE;

typedef enum VDC_CSTATE_FAST_LOCK {
	VDC_CSTATE_FastLock_DISABLE = 0,
	VDC_CSTATE_FastLock_ENABLE,	// [7:5] = 111
	VDC_CSTATE_FastLock_ENABLE_1,	// [7:5] = 110
	VDC_CSTATE_FastLock_ENABLE_2,	// [7:5] = 101
	VDC_CSTATE_FastLock_ENABLE_3,	// [7:5] = 100
} VDC_CSTATE_FAST_LOCK;

typedef enum VDC_OUTPUT_MODE {
	VDC_OUTPUT_13_5MHz = 0,
	VDC_OUTPUT_27MHz,
} VDC_OUTPUT_MODE;

typedef enum VDC_SECAM_Y_FIR_EN {
	VDC_secam_y_fir_disable = 0,
	VDC_secam_y_fir_enable,
} VDC_SECAM_Y_FIR_EN;

typedef enum VDC_SECAM_HPF_SEL {
	VDC_hpf_bypass = 0,		// 0: no pass
	VDC_hpf_5p3_MHz = 1,
	VDC_hpf_5p5_MHz = 2,
	VDC_hpf_5p7_MHz = 3,
	VDC_hpf_5p8_MHz = 4,
	VDC_hpf_6p0_MHz = 5,
	VDC_hpf_6p1_MHz = 6,
	VDC_hpf_6p2_MHz = 7,
} VDC_SECAM_HPF_SEL;

typedef enum VDC_SECAM_Y_LPF_SEL {
	VDC_y_lpf_1p5_MHz = 0,
	VDC_y_lpf_1p7_MHz,
	VDC_y_lpf_2p0_MHz,
	VDC_y_lpf_2p2_MHz,
	VDC_y_lpf_L1p5_H7p0_MHz,	// set to default
	VDC_y_lpf_L1p7_H6p8_MHz,
	VDC_y_lpf_L1p8_H6p6_MHz,
	VDC_y_lpf_L2p0_H6p4_MHz,
} VDC_SECAM_Y_LPF_SEL;

typedef enum VDC_SET_DGAIN {
	VDC_set_dgain_normal = 0,	// dgain x 2
	VDC_set_dgain_x05,
	VDC_set_dgain_x06,
} VDC_SET_DGAIN;

#ifdef CONFIG_SCART_ENABLE
typedef enum {
	_SCART_AV = 0,
	_SCART_SV,
	_SCART_RGB,
} SCACT_DATA_TYPE;
extern unsigned char SCART_Type;	// 0: is scart av, 2: is scart sv, 1: is scart rgb

typedef enum _SCART_PIN8_LEVEL {
	SCART_PIN8_LEVEL_NONE,      //(0--2V)
	SCART_PIN8_LEVEL_16_9,      //(5--8V)
	SCART_PIN8_LEVEL_4_3,       //(9.5--12V)
} SCART_PIN8_LEVEL;
#endif

typedef enum _Hactive_Mode{
	HwMode = 0,
	FwMode = 1,
}Hactive_Mode;

////////// reg. status	////////////////////////////////////////////////////////////
typedef enum VDC_PLL27x_CLK_REG {
	VDC_PLL27x_CLK_540M = 0x00,	// 00: divide by 5 (use when VCO=540MHz)
	VDC_PLL27x_CLK_432M,	// 01: divide by 4 (use when VCO=432MHz)
	VDC_PLL27x_CLK_324M,	// 10: divide by 3 (use when VCO=324MHz)
	VDC_PLL27x_CLK_648M,	// 11: divide by 6 (use when VCO=648MHz)
} VDC_PLL27x_CLK_REG;

typedef enum VDC_FIFO_CLK_REG {
	VDC_FIFO_CLK_162M,
	VDC_FIFO_CLK_108M_1,	// default
	VDC_FIFO_CLK_108M_0,
	VDC_FIFO_CLK_135M,
} VDC_FIFO_CLK_REG;

typedef enum VDC_CONTROL_REG {
	//VIDEO_STATUS_REG1 0x1801_9000
	VDC_hv_delay = 0,	// [7]
	VDC_hpixel,			// [6:5]
	VDC_Vline_625,		// [4]
	VDC_Colour_mode,	// [3:1]
	VDC_CONTROL_REG0,
	//VIDEO_STATUS_REG2 0x1801_9004
	VDC_cv_inv,			// [7]
	VDC_cv_src,			// [6]
	VDC_yc_src,			// [5]
	VDC_ped,			// [0]
	VDC_CONTROL_REG1,
} VDC_CONTROL_REG;

typedef enum VDC_SET_CONTROL_REG {
	//VIDEO_STATUS_REG1 0x1801_9000
	VDC_hv_delay_on,	// [7]
	VDC_hv_delay_off,
	VDC_set_Vline_625,	//[4]
	VDC_set_Vline_525,
	VDC_set_Colour_mode_NTSC,		// [3:1]
	VDC_set_Colour_mode_NTSC443,
	VDC_set_Colour_mode_PAL60,
	//VIDEO_STATUS_REG2 0x1801_9004
	VDC_set_src_AV,		// [6:5]
	VDC_set_src_YPP,
	VDC_set_src_SV,
	VDC_ped_on,	// [0]
	VDC_ped_off,
} VDC_SET_CONTROL_REG;

typedef enum VDC_STATUS_REG {
	//VIDEO_STATUS_REG1 0x1801_9008
	VDC_chomalock = 0,		// [3]
	VDC_vlock,			// [2]
	VDC_hlock,			// [1]
	VDC_no_signal,		// [0]
	VDC_not_no_signal,	// ~[0]
	VDC_hv_lock,		// [2:0]
	VDC_all_lock,		// [3:0]
	VDC_mv_detect,		// [4]
	VDC_cid_detect,		// [7:5]
	VDC_h_fine_lock,		// [8]
	VDC_chromalock_acc,	// [9]
	VDC_hlock_longtime,	// [12]
	VDC_vlock_longtime,	// [13]
	VDC_hvlock_longtime,	// [14]
	VDC_STATUS_REG1,
	//VIDEO_STATUS_REG2 0x1801_900C
	VDC_V_detect_flag,	// [8]
	VDC_Detect358_flag,	// [7]
	VDC_vlock_new,		// [6]
	VDC_noisy_vbi,		// [5]
	VDC_Detect443_flag,	// [4]
	VDC_Burst_detect,	// [3]
	VDC_PALor_flag,		// [2]
	VDC_PALm_flag,		// [1]
	VDC_proscan_detected,	// [0]
	VDC_STATUS_REG2,
	//VIDEO_STATUS_REG3 0x1801_9010
	VDC_vcr_rew,	// [7]
	VDC_vcr_ff,		// [6]
	VDC_vcr_trick,	// [5]
	VDC_vcr,		// [4]
	VDC_vcr_any,
	VDC_noisy,		// [3]
	VDC_Lines_625_detected,	// [2]
	VDC_SECAM_detected,	// [1]
	VDC_PAL_detected,		// [0]
	VDC_STATUS_REG3,
} VDC_STATUS_REG;

typedef enum VDC_SEP_BURST_FLAG {
	// New 358/443/secam flag
	VDC_new_358_flag = 0,	// [0]
	VDC_new_443_flag,		// [1]
	VDC_new_secam_flag,	// [2]
	VDC_new_burst_flag,
} VDC_SEP_BURST_FLAG;

typedef enum VDC_DCTIEH_ENABLE_REG {
	DCTIeh_DISABLE	= 0,
	DCTIeh_ENABLE,
} VDC_DCTIEH_ENABLE_REG;

typedef enum VDC_NEW_VDETECT_ENABLE_REG {
	Old_vedetect = 0,
	New_vedetect,
} VDC_NEW_VDETECT_ENABLE_REG;

typedef enum VDC_SECOND_PLL_ENABLE_REG {
	Second_pll_disable = 0,
	Second_pll_enable,
} VDC_SECOND_PLL_ENABLE_REG;

typedef enum VDC_FINE_SRC_SEL_REG {
	Fine_LPS = 0,	/* 0: low pass filter data */
	Fine_ORG,		/* 1: original data (default) */
} VDC_FINE_SRC_SEL_REG;

typedef enum VDC_HPLL_FINE_LOCK_DATA_SEL_REG {
	HPLL_FINE_LOCK_LPF = 0,	/* fine lock will use the hdetect_lpf_sync */
	HPLL_FINE_LOCK_REAL,		/* fine lock will use real data */
} VDC_HPLL_FINE_LOCK_DATA_SEL_REG;

typedef enum VDC_HSTATE_ERROR_METHOD_REG {
	ignore_error_off = 0,
	ignore_error_on,
} VDC_HSTATE_ERROR_METHOD_REG;

typedef enum VDC_DMA_DEBUG_MODE_SEL {
	DMA_VD_MODE = 0,
	DMA_IFD_MODE,
	DMA_VBI_MODE,
	DMA_REG_MODE,
} VDC_DMA_DEBUG_MODE_SEL;

typedef enum VDC_DMA_MODE_SEL {
	DMA_VD_M0 = 0,
	DMA_VD_M1,
	DMA_VD_M2,
	DMA_VD_M3,
	DMA_VD_M4,
	DMA_VD_M5,
	DMA_VD_M6,
	DMA_VD_M7,
	DMA_VD_M8,
	DMA_VD_M9,
	DMA_VD_MA,
	DMA_VD_MB,
	DMA_IFD,
	DMA_VBI,
	DMA_REG
} VDC_DMA_MODE_SEL;

#ifdef scart_vdc_auto_balance_en
typedef enum SCACT_RGB_GAIN_OFFSET_TYPE {
	_SCART_GAIN_R = 0,
	_SCART_GAIN_G,
	_SCART_GAIN_B,
	_SCART_OFFSET_R,
	_SCART_OFFSET_G,
	_SCART_OFFSET_B,
	_SCART_Contrast2,
	_SCART_Brightness2,
	_SCART_Cb_saturation,
	_SCART_Cr_saturation
} SCACT_RGB_GAIN_OFFSET_TYPE;
#endif


#define _VIDEO_NOT_EXIST	_MODE_NOSIGNAL
#define _VIDEO_EXIST		_MODE_EXIST
#define _No_Sig				_BIT0
#define _HSLCK				_BIT1
#define _VLINF				_BIT2

#define ZNTSC				0x10
#define ZPAL_M				0x11
#define ZNTSC_50			0x12
#define ZPAL_N				0x13
#define ZNTSC_443			0x14
#define ZPAL_60				0x15
#define ZPAL_I				0x16
#define ZSECAM				0x17
#define ZSECAML				0x27
#define ZSECAMLA 			0x37
#define ZAUTO				0x18
#define ZMODE_ERROR		0x19
#define ZCR_NOT_LOCK		0x1A
#define ZHV_NOT_LOCK		0x1B
#define ZFRQ_NOT_IN_BAND    0x1C
#define ZMODE_525_STD		0x1D
#define ZPAL_L                       0x1E
#define ZFM_RADIO			0x1F
#define ZPAL_DK_MONO		0x20

// VADC_SIBDAC
#define VDAC_BIAS_CURRENT_FOR_ALL		0x0c
#define VDAC_BIAS_CURRENT_SELECT		0x0c

// VADC_SGAIN
#define VADC_SGAIN_ADC0				0x03
#define VADC_SGAIN_ADC1				0x03

#define _PAL_MotionThreshold		(6)
#define _NTSC_MotionThreshold		(6)

/*==================== Variables ================= */
#define HIGH_BYTE(x)		((x & 0xFF00)>>8)
#define LOW_BYTE(x)		(x & 0x00FF)

/*==================Definitions for vd2638============================*/
//#define _SDRAM_3D_COM_USE		0x362360
/*(1135x625+4)(pixel) x 10 (bit/pixel) /8 (bit/byte) = 886723.75(bytes),
==> 887000(bytes)
4 frames = 887000x4(bytes) = 3548000 (bytes) = 0x362360*/
//#define _SDRAM_3D_ONE_FRAME_USE 	0x1B11B /*887000(bytes)/8bytes = 110875 = 0x1B11B for 8bytes address use*/

/****** New definition since Mag2 ******/
#define _SDRAM_3D_COM_USE       0x700000
#define _SDRAM_3D_COM_OFFSET    0x000000
/*
(1135x625+4)(pixel) x 19 (bit/pixel/Merlin2) /8 (bit/byte) = 1684775.125(bytes) ==> 1688000(bytes)
4 frames = 1688000 x 4(bytes) = 6752000 (bytes) = 0x670700
*/

#define _SDRAM_3D_ONE_FRAME_USE		0x34000
/*1688000(bytes)/8bytes = 211000 = 0x33838 for 8bytes address use*/

#define _VIDEO_INDEX			0xb8010000

////////////////////extern///////////////////////////////////////////////////
extern unsigned short FieldVTotal;
//extern bool vdc_inTV_chch;
//extern bool vdc_exTV_chch;
extern bool vdc_AV_modech;
extern bool vdc_LockStatus;
extern bool vdc_BurstLockStatus;
extern bool vdc_AnyVCRStatus;
extern bool vdc_OldVLockStatus;
extern unsigned char vdc_NoiseStatus;
extern unsigned int vdc_ucNoSignalCounter;

#ifndef _MODE_UNKNOWN
#define _MODE_UNKNOWN 0xff
#endif

#ifdef CONFIG_SCART_ENABLE
#define cSCART_FSW_Level	0x03
extern unsigned char SCART_Type;	// 0: is scart av, 2: is scart sv, 1: is scart rgb
extern unsigned char pre_SCART_Type;
#endif
extern unsigned char vdc_TV_dctieh_table_value;

extern unsigned short tVIDEO_TABLE_INPUT_INFO[][5];
extern VDC_FRAME_RATE field;
extern unsigned char cvideo_tv_channel_scan_is_running;
//extern unsigned char vdc_factory_mod_enable;
extern unsigned char tvAutoScanFlag;
extern unsigned short gVideoTableInputInfo[][5];

#ifdef scart_vdc_auto_balance_en
typedef struct _VDBrConSat {
	unsigned short Contrast2;/*In fact, 8bits */
	unsigned short Brightness2;/*In fact, 8bits */
	unsigned short Cr_saturation;/*In fact, 8bits */
	unsigned short Cb_saturation;/*In fact, 8bits */
} VDBrConSat;

typedef struct _ADCGainOffset_s {
	unsigned short Gain_R;	/*In fact, 11bits */
	unsigned short Gain_G;	/*In fact, 11bits */
	unsigned short Gain_B;	/*In fact, 11bits */
	unsigned short Offset_R;	/*In fact, 11bits */
	unsigned short Offset_G;	/*In fact, 11bits */
	unsigned short Offset_B;	/*In fact, 11bits */
} vdc_ADCGainOffset;


extern vdc_ADCGainOffset g_scart_ADCGainOffset;
extern VDBrConSat g_scart_VDBrConSat;
#endif

typedef enum
{
    VD_IFD_CLK_RATE_108M = 0  ,
    VD_IFD_CLK_RATE_54M,
    VD_IFD_CLK_RATE_135M,
    VD_IFD_CLK_RATE_162M,
} VD_IFD_CLK_RATE;

typedef enum
{
    VD_IFD_INPUT_DN_FILTER_108M_HPF = 0  ,
    VD_IFD_INPUT_DN_FILTER_108M_LPF,
    VD_IFD_INPUT_DN_FILTER_135M_BPF,
    VD_IFD_INPUT_DN_FILTER_135M_LPF,
    VD_IFD_INPUT_DN_FILTER_162M_BPF,
    VD_IFD_INPUT_DN_FILTER_162M_LPF,
} VD_IFD_INPUT_DN_FILTER;

typedef enum VDC_DMA_CHK3D_ENABLE_MODE {
    VDC_CHANEL_SWISH_MODE = 0,
    VDC_CHANEL_DISPLAY_MODE,
}VDC_DMA_CHK3D_ENABLE_MODE;

typedef struct _VDC_DMA_CHK3D_TABLE_s {
	unsigned char chk_3d_sel;
	unsigned char open_3d_cnt;
	unsigned char close_3d_cnt;
	unsigned char dma_3d_on_vcnt;
}VDC_DMA_CHK3D_TABLE;


//==========  APIs  ===========================================//
extern unsigned int vdcf_inl(unsigned int offset);
extern void vdcf_outl(unsigned int offset, unsigned int val);
extern void vdcf_maskl(unsigned int offset, unsigned int andMask, unsigned int orMask);
extern void drv_module_vdc_SetInterrupt(VDC_IRQ_SWITCH on_off);
extern void drvif_module_vdc_ClockOn(void);
extern void drvif_module_vdc_PowerCtrl(unsigned char on_off, unsigned char a_ucInputSrc);
bool module_vdc_check_pll27x_setting(void);
extern void drvif_module_Set_pll27x_source(VDC_PLL27x_CLK_REG freq);
extern VDC_PLL27x_CLK_REG drvif_module_Read_pll27x_vco_setting(void);
extern void drvif_module_vdc_FIFO_CLK_setting(void);
extern void drvif_module_vdc_Power_Setting(VDC_POWER_SETTING mode, unsigned char a_ucInputSrc);
extern void drvif_module_vd_ADC_PowerCtrl(unsigned char on_off, unsigned char a_ucInputSrc);
extern void drvif_module_vdc_digital_PowerCtrl(unsigned char on_off, unsigned char detect_on);
extern void drvif_module_vdc_SoftReset(void);
extern void drvif_module_vdc_SoftReset_New(void);
extern void drvif_module_vdc_108M_FrontDigitalFilterEnable(VDC_VIDEO_108M_FrontDigitalFilter mode);
extern unsigned char drvif_module_vdc_Read_108M_FrontDigitalFilter_info(void);
void module_vdc_adcNegativeAdjustment(unsigned char ucValue);
extern unsigned int drvif_video_control_reg(VDC_CONTROL_REG status);
extern void drvif_video_set_control_reg(VDC_SET_CONTROL_REG status);
extern unsigned char drvif_video_check_AV_stable(void);
extern unsigned int drvif_video_status_reg(VDC_STATUS_REG status);
extern bool drvif_video_status_reg_noScaler(VDC_STATUS_REG status);
/*============================================================================*/
extern unsigned int drvif_module_vdc_Hdto_status(void);
extern unsigned int drvif_module_vdc_Cdto_status(void);
extern unsigned char drvif_module_vdc_burst_mag_status(void);
extern unsigned int drvif_module_vdc_read_Dgain(void);
extern unsigned int drvif_module_vdc_read_Cgain(void);
extern unsigned int drvif_module_vdc_read_V_1st_line(void);
extern unsigned int drvif_module_vdc_read_V_2nd_line(void);
extern unsigned char drvif_module_vdc_NoiseStatus(void);
extern unsigned char drvif_module_vdc_NoiseFlag(void);
void module_vdc_set_noise_thresh(unsigned char value);
#ifdef VD_hdto_adjust
void module_vdc_set_hdto_inc(unsigned int value);
unsigned int module_vdc_read_hdto_inc(void);
#endif
extern void drvif_module_vdc_SetContrast(unsigned char ucValue);
extern void drvif_module_vdc_SetBrightness(unsigned char ucValue);
extern void drvif_module_vdc_SetSaturation(unsigned char ucValue);
extern void drvif_module_vdc_SetHue(unsigned char ucValue);
void module_vdc_SetBlueScreenColor(unsigned int ucY, unsigned int ucCb, unsigned int ucCr);
extern unsigned char drvif_module_vdc_YcDelay_Get_info(void);
void module_vdc_BlueScreenEnable(VDC_BLUE_SCREEN_MODE uselect);
extern bool drvif_module_vdc_read_Clamping_path(void);
extern void drvif_module_vdc_AVout_mode_set(VDC_VIDEO_AVout_Mode mode);
extern unsigned char drvif_module_vdc_Read_PeakNominal(void);
extern void drvif_module_vdc_set_PeakWhite(unsigned char on_off);
extern void drvif_module_vdc_set_Killgate(VDC_KillGate_Control ucKGmode);
extern unsigned char drvif_module_vdc_read_Killgate(void);
extern void drvif_module_vdc_set_Control2_Register(VDC_VIDEO_CONTROL2 mode);
extern void drvif_module_vdc_Write_Dgain_value(unsigned char value);
void module_vdc_Set_Vsync_clamp_mode(VDC_VSYNC_CLAMP_MODE mode);
void module_vdc_Set_clamp_delay(unsigned char on_off, unsigned char ucValue);
void module_vdc_Set_cpump_adjust_delay(unsigned char ucValue);
void module_vdc_Set_cpump_adjustment(unsigned char ucValue);
extern void drvif_module_vdc_clamp_rc_rate_function(unsigned char on_off);
extern unsigned char drvif_module_vdc_measure_dc_rough(void);
extern void drvif_module_vdc_xftv_function(unsigned char on_off);
extern void drvif_module_vdc_Set_Hstate(VDC_VIDEO_FIXHSTATE_MODE value);
extern VDC_VIDEO_FIXHSTATE_MODE drvif_module_vdc_Read_Hstate_set(void);
void module_vdc_set_fine_src_sel(VDC_FINE_SRC_SEL_REG on_off);
void module_vdc_set_hstate_error_method(VDC_HSTATE_ERROR_METHOD_REG on_off);
extern void drvif_module_vdc_clampagc_new_sync_start(unsigned char ucstart);
extern void drvif_module_vdc_clampagc_new_sync_end(unsigned char ucend);
extern void drvif_module_vdc_Hpll_extend(unsigned char on_off);
extern unsigned char drvif_module_vdc_read_Hsync_start(void);
extern void drvif_module_vdc_set_Hsync_start(unsigned char value);
extern VDC_SECOND_PLL_ENABLE_REG drvif_module_vdc_read_second_pll_status(void);
extern void drvif_module_vdc_set_second_pll(VDC_SECOND_PLL_ENABLE_REG on_off);
unsigned int module_vdc_read_Second_Dgain(void);
extern void drvif_module_vdc_hsync_rising_start(unsigned char ucstart);
extern void drvif_module_vdc_hsync_rising_end(unsigned char ucend);
void module_vdc_set_Hblank_start(unsigned char value);
//extern void drvif_module_vdc_set_burst_gate_position(unsigned char mode);//merage form mac5p
extern void drvif_module_vdc_cpll_reset(void);
void module_vdc_set_gate_hv_iir(unsigned char mode);
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
unsigned char drvif_module_vdc_read_vphasediff_status(void);
#endif
void module_vdc_set_hstate_error01_thl(unsigned char value);
extern bool drvif_module_vdc_read_coch_detect_status(void);
bool module_vdc_read_Wrong_if_pc_detect_flag(void);
#ifdef VD_Herror_histo_test
extern unsigned short drvif_module_vdc_Read_histo1_phase_error0(void);
extern unsigned short drvif_module_vdc_Read_histo1_phase_error1(void);
extern unsigned short drvif_module_vdc_Read_histo1_phase_error2(void);
extern void drvif_module_vdc_Clear_histo_ready(void);
extern unsigned char drvif_module_vdc_Read_histo1_ready(void);
extern unsigned short drvif_module_vdc_Read_histo1_phase_error3(void);
extern unsigned short drvif_module_vdc_Read_histo1_phase_error4(void);
extern unsigned short drvif_module_vdc_Read_histo1_phase_error5(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error0(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error1(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error2(void);
extern unsigned char drvif_module_vdc_Read_histo2_ready(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error3(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error4(void);
extern unsigned short drvif_module_vdc_Read_histo2_phase_error5(void);
#endif
extern void drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_Vsync_Output_Mode mode);
extern VDC_Vsync_Output_Mode drvif_module_vdc_read_Vsync_Cntl_Mode(void);
extern void  drvif_module_vdc_vloop_control_set(VDC_Vloop_Control value);
extern unsigned char drvif_module_vdc_vloop_control_read(void);
extern void drvif_module_vdc_set_noSignalCounter_Value(unsigned char value);
extern void drvif_module_vdc_set_hlock_field_cnt_Value(unsigned char value);
void module_vdc_set_Vactive_position(unsigned char ucStart, unsigned char ucHeight);
void module_vdc_set_vsync_h_max(unsigned char ucValue);
extern void drvif_module_vdc_27M_FrontDigitalFilterEnable(VDC_VIDEO_27M_FrontDigitalFilter mode);
extern unsigned char drvif_module_vdc_Read_27M_FrontDigitalFilter_info(void);
extern void drvif_module_vdc_Vdetcet_pattern_sel(unsigned char pattern);
extern bool drvif_module_vdc_read_Vlock_sel_status(void);
extern void drvif_module_vdc_Raw_vdetect_max_sel(unsigned char mode);
extern void drvif_module_vdc_adc_27M_LPF_coef_Table(VDC_VIDEO_27M_LPF_COEF mode);
void module_vdc_set_no_vsyncflag_back1(unsigned char on_off);
void module_vdc_new_vdetect_init(void);
extern void drvif_module_vdc_new_vdetect_Enable(VDC_NEW_VDETECT_ENABLE_REG mode);
extern unsigned char drvif_module_vdc_read_new_vdetect(void);
void module_vdc_set_vsync_refind_enable(unsigned char on_off);
void module_vdc_set_vstate0_direct_vsync_enable(unsigned char on_off);
void module_vdc_set_vsync_refind_sel(unsigned char mode);
extern void drvif_module_vdc_set_vstate_new2to3_en(unsigned char on_off);
extern void drvif_module_vdc_Set_Vstate(VDC_VIDEO_FIXVSTATE_MODE value);
extern VDC_VIDEO_FIXVSTATE_MODE drvif_module_vdc_Read_Vstate_set(void);
extern unsigned char drvif_module_vdc_Read_Vstate(void);
extern unsigned char drvif_module_vdc_CKill_status(void);
extern unsigned short drvif_module_vdc_Read_Vline_out(void);
extern bool drvif_module_vdc_Read_Vline_freerun_status(void);
extern void drvif_module_vdc_set_vsync_freerun_enable(unsigned char on_off);
extern bool drvif_module_vdc_read_vsync_freerun_enable(void);
extern void drvif_module_vdc_Set_CKill_Value(unsigned char ucValue);
extern unsigned char drvif_module_vdc_Read_CKill_Value(void);
extern void drvif_module_vdc_Set_CKill_Mode(VDC_CKill_MODE ucMode);
extern unsigned char drvif_module_vdc_Get_CKill_Mode(void);
extern void drvif_module_vdc_Set_lose_chromalock_count(unsigned char ucValue);
extern void drvif_module_vdc_Set_lose_chromalock_level(unsigned char ucValue);
extern unsigned char drvif_module_vdc_Get_CKill_Auto(void);
extern VDC_VIDEO_FIXCSTATE_MODE drvif_module_vdc_Read_Cstate_set(void);
extern void drvif_module_vdc_Set_Cstate(VDC_VIDEO_FIXCSTATE_MODE value);
void module_vdc_Set_CKill_Gain_Kill_Thl_Value(unsigned char  ucOnOff, unsigned int ucOffset, unsigned int ucGainValue);
extern void drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FAST_LOCK value);
extern void drvif_module_vdc_Cpeak_set(unsigned char on_off);
bool module_vdc_Cpeak_read(void);
extern void drvif_module_vdc_Cpeak_noise_thr1_set(unsigned char value);
extern void drvif_module_vdc_Cpeak_noise_thr2_set(unsigned char value);
extern void drvif_module_vdc_Cpeak_noise_act_set(unsigned char on_off);
extern void drvif_module_vdc_Disable_Auto_Burst_position(void);
extern void drvif_module_vdc_set_burst_location_magnitude_thr(unsigned char ucValue);
extern void drvif_module_vdc_StateMachineReset(void);
extern bool drvif_module_vdc_ReadAutomode(void);
extern void drvif_module_vdc_set_Basic_Register(VDC_VIDEO_BASIC_REGISTER mode);
extern void drvif_module_vdc_auto_secamFlag_select(VDC_ATUO_SECAM_FLAG_SEL uselect);
extern void drvif_module_vdc_PreferModeSetting(unsigned char mode);
void module_vdc_set_noBurstMagFilterTh(unsigned char value);
void module_vdc_noBurs443_enable(unsigned char on_off);
unsigned char module_vdc_read_burst_win_error_flag(void);
extern void drvif_module_vdc_old_secam_flag_setting(VDC_SECAM_FLAG_SETTING setting);
extern void drvif_module_vdc_palm_flag_phase_adjust(unsigned char value);
extern unsigned char drvif_video_read_358_cos_sin_flag(void);
extern void drvif_module_vdc_BurstGate_set(unsigned short usStart, unsigned short usEnd);
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
unsigned char module_video_read_Sep_443_core_burst_hsync(void);
unsigned char module_video_read_Sep_358_core_burst_hsync(void);
#endif
extern unsigned char drvif_video_read_Sep_443_core_burst(void);
extern unsigned char drvif_video_read_Sep_358_core_burst(void);
extern void drvif_module_vdc_set_Sep_358_thl(unsigned char ucValue);
extern void drvif_module_vdc_set_Sep_443_thl(unsigned char ucValue);
extern unsigned char drvif_video_sep_burst_flag1(VDC_SEP_BURST_FLAG status);
void module_vdc_set_Mode_443358pk_sel(VDC_Mode_443358pk ucValue);
void module_vdc_set_Mode_secam2_sel(VDC_Mode_secam2 ucValue);
extern void drvif_module_vdc_set_pk_foraudio(unsigned char on_off);
extern void drvif_module_vdc_lock_h_on_no_signal(unsigned char on_off);
unsigned char module_vdc_read_lock_h_on_no_signal(void);
void module_vdc_hv_freerun_sel(unsigned char on_off);
extern bool drvif_module_vdc_read_hv_freerun_sel(void);
extern unsigned char drvif_module_vdc_read_SCART_fb_en(void);
extern void drvif_module_vdc_set_SCART_fb_en(unsigned char on_off);
extern unsigned char drvif_module_vdc_read_SCART_fb_sw(void);
extern void drvif_module_vdc_set_SCART_fb_sw(unsigned char on_off);
extern void drvif_module_vdc_set_SCART_sel_func(VDC_SCART_sel mode);
void module_vdc_set_Out444_sel(VDC_OUT444_sel value);
extern unsigned char drvif_module_vdc_read_SCART_RGB_en(void);
extern void drvif_module_video_SCART_RGB_set(unsigned char on_off);
extern unsigned char drvif_module_vdc_ReadContrast_SCART(void);
extern void drvif_module_vdc_SetContrast_SCART(unsigned char ucValue);
extern unsigned char drvif_module_vdc_ReadBrightness_SCART(void);
extern void drvif_module_vdc_SetBrightness_SCART(unsigned char ucValue);
extern unsigned char drvif_module_vdc_ReadSaturation_Cr_SCART(void);
extern void drvif_module_vdc_SetSaturation_Cr_SCART(unsigned char ucValue);
extern unsigned char drvif_module_vdc_ReadSaturation_Cb_SCART(void);
extern void drvif_module_vdc_SetSaturation_Cb_SCART(unsigned char ucValue);
extern unsigned char drvif_module_vdc_read_SCART_fbgain_en(void);
extern void drvif_module_vdc_set_SCART_fbgain_en(unsigned char on_off);
extern void module_vdc_SetSaturation_SCART(unsigned char ucCrValue, unsigned char ucCbValue);
extern unsigned char drvif_module_vdc_read_FSW_value(void);
/////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_read_rgb_output_en(void);
extern void drvif_module_vdc_set_rgb_output_en(unsigned char on_off);
extern unsigned short drvif_module_vdc_read_Rgain(void);
extern void drvif_module_vdc_set_Rgain(unsigned short value);
extern unsigned short drvif_module_vdc_read_Ggain(void);
extern void drvif_module_vdc_set_Ggain(unsigned short value);
extern unsigned short drvif_module_vdc_read_Bgain(void);
extern void drvif_module_vdc_set_Bgain(unsigned short value);
extern unsigned char drvif_module_vdc_read_Roffset(void);
extern void drvif_module_vdc_set_Roffset(unsigned char value);
extern unsigned char drvif_module_vdc_read_Goffset(void);
extern void drvif_module_vdc_set_Goffset(unsigned char value);
extern unsigned char drvif_module_vdc_read_Boffset(void);
extern void drvif_module_vdc_set_Boffset(unsigned char value);
extern unsigned short drvif_module_vdc_read_blevel(void);
extern unsigned short drvif_module_vdc_read_slevel(void);
extern bool drvif_module_vdc_read_factory_flag(void);
extern void drvif_module_vdc_clean_factory_flag(void);
extern unsigned int drvif_module_vdc_read_fpga_test1(void);
extern VDC_MSG_LEVEL drvif_module_vdc_read_fpga_test2(void);
extern bool drvif_module_vdc_read_scan_flag(void);
extern void drvif_module_vdc_set_scan_flag(unsigned char on_off);
extern bool drvif_module_vdc_read_ch_change_flag(void);
extern void drvif_module_vdc_set_ch_change_flag(unsigned char on_off);
extern void drvif_module_vdc_SECAM_y_fir_adj(VDC_SECAM_Y_FIR_EN on_off,
	VDC_SECAM_HPF_SEL y_hpf_sel, VDC_SECAM_Y_LPF_SEL y_lpf_sel);
void module_vdc_SECAM_flag_select(unsigned char value);
extern void drvif_module_vdc_SECAM_Drdb_vlpf_en(unsigned char on_off);
extern void drvif_module_vdc_SECAM_ColorReduction(unsigned char on_off); // Merlin jyyang 20150617
extern void drvif_module_vdc_SECAM_gp_enable(unsigned char on_off, unsigned int gp_step, unsigned int gp_thl);
extern void drvif_module_vdc_set_Output_mode(VDC_OUTPUT_MODE value);
extern VDC_OUTPUT_MODE drvif_module_vdc_get_Output_mode(void);
extern void drvif_module_vdc_clear_FIFO_status(void);
extern void drvif_module_vdc_Swallow_on_Vsyng(unsigned char on_off);
void module_vdc_set_f_cennum_range(unsigned char cennum);
extern void drvif_module_vdc_FrameBufferCheck_enable(unsigned char on_off);
void module_vdc_set_f_num_close3d_cnt(unsigned char frame);
extern unsigned short drvif_module_vdc_read_dma_vcnt_diff(void);
///////////////////////////////////////////////////////////////////////////////////////
extern void drvif_module_vdc_Initial(unsigned int mem_addr);
void module_vdc_Reset(void);
extern void drvif_module_vdc_ResetReg(void);
extern void drvif_module_vdc_tv_Reset(void);
///////////////////////////////////////////////////////////////////////////////////////
extern unsigned char drvif_module_vdc_Exist(unsigned char ucInputSrc);
extern unsigned char drvif_module_vdc_Exist_noScaler(unsigned char ucInputSrc);
extern unsigned char drvif_module_vdc_CheckHVisLocked(void);
extern void drvif_module_vdc_reset_Status(void);
extern void drvif_module_vdc_Status_Loop(void);
extern void drvif_module_vdc_CheckInputStatus(unsigned char ucInputSrc, unsigned char ucCheckStart);
extern bool drvif_module_vdc_OutputStable(void);
extern void drvif_module_vdc_SelectInput(unsigned char ucInputSrc, VDC_INITIAL_OPTIONS  *ptOptions);
///////////////////////////////////////////////////////////////////////////////////////
void module_vdc_set_vstate_parameter(void);
extern void drvif_module_vdc_set_vstate_speedup(VDC_VSTATE_COUNT_REG value);
void module_vdc_set_cstate_parameter(void);
extern void drvif_module_vdc_mode_speedup(VDC_MODE_COUNT_REG value);
///////////////////////////////////////////////////////////////////////////////////////
extern void drvif_module_vdc_set_ColorMode(unsigned char mode);
extern void drvif_module_vdc_disable_mode(VDC_DISABLE_MODE result);
extern void drvif_module_vdc_SetMode(unsigned char ucMode);
extern unsigned char drvif_module_vdc_ReadMode(GET_VIDEO_MODE_METHOD result);

#ifdef CONFIG_ENABLE_VDC_MV_CHECK
extern void drvif_module_vdc_set_mv_function(void);
#endif
extern unsigned char drvif_module_vdc_IdentifyColorStandard(unsigned char ucInputSrc);
extern void drvif_module_vdc_IdentifyColorStandard_ResetStage(void);
extern unsigned char drvif_module_vdc_IdentifyColorStandard_GetStage(void);
extern unsigned char drvif_module_vdc_IdentifyColorStandard_NoDelay(unsigned char ucInputSrc);
void module_vdc_set_secam_443358_flag_parameter(void);
///////////////////////////////////////////////////////////////////////////////////////
extern void drvif_module_vdc_FreeRun(VDC_FREERUN_LINE result);
void module_vdc_set_Clamp_position(unsigned char ucMode);
void module_vdc_set_Burst_position(unsigned char ucMode);
extern void drvif_module_vdc_Analog_FIFO_Reset(void);
#ifdef VD_Digital_FIFO
void module_vdc_set_new_fifo_parameter(void);
#endif
#ifdef VD_hdto_adjust
extern void drvif_module_vdc_hpll_extend_detect(void);
#endif
extern unsigned short drv_module_vdc_GetVideoScaleInfo(VDC_VIDEO_SCALE_INFO info);
extern unsigned char drv_module_vdc_GetVdcPreMode(void);
extern void drv_module_vdc_SetVdcCurrMode(unsigned char value);
extern unsigned char drv_module_vdc_GetVdcCurrMode(void);
extern unsigned char drv_module_vdc_SetVarFieldVTotal(unsigned short vTotal);
extern unsigned short drv_module_vdc_GetVarFieldVTotal(void);
extern unsigned char drvif_module_vdc_GetVHalfTotalLen(unsigned short *VActLen);
#ifdef CONFIG_ENABLE_VDC_BURST_CHECK
void module_vdc_Burst_check(unsigned char ucMode, unsigned char ucNoiseStatus, unsigned char BurstMag);
#endif
extern void drvif_module_vdc_Chroma_control(unsigned char ucInputSrc);
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
unsigned char module_video_check_Hsync_power(unsigned char mode);
extern void drvif_module_vdc_Cpeak_control(unsigned char ucInputSrc);
#endif
#ifdef VD_LUMA_CONTROL
extern void drvif_module_vdc_luma_control(unsigned char ucInputSrc);
#endif
extern VDC_FRAME_RATE drv_module_vdc_GetFrameRate(void);
extern void drvif_video_color_burst_check_power(unsigned char ucEnable);
extern unsigned char drvif_video_color_burst_check(unsigned char threshold, unsigned char checkcnt);
#ifdef CONFIG_SCART_ENABLE
extern void drvif_video_SCART_RGB_set(unsigned char on_off);
extern bool drvif_video_read_SCART_RGB_set(void);
extern unsigned char drvif_video_get_SCART_type(void);
extern void drvif_video_FullSCART_func_initial(void);
extern void drvif_video_SCART_func_check(void);
#endif
extern void drv_module_vdc_SetAutoScanFlag(unsigned char a_ucFlag);
extern void drv_module_vdc_setAutoModeWithoutSecam(bool isEnable);
extern void drvif_module_vdc_Set_VCR_mode(void);
extern void drvif_module_vdc_set_AVD_connect_flag(unsigned char on_off);
#ifdef scart_vdc_auto_balance_en
extern void drvif_module_vdc_scart_rgb_output_disable(void);
extern void drvif_module_vdc_scart_rgb_output_enable(void);
extern void drvif_module_vdc_scart_auto_setadcgainoffset(void);
extern void drvif_module_vdc_Set_scart_gain(void);
extern void drvif_module_vdc_Set_scart_offset(void);
extern void drvif_module_vdc_Set_scart_gain_offset(SCACT_RGB_GAIN_OFFSET_TYPE addr, unsigned short parameter);
extern void drvif_module_vdc_Set_scart_Brightness_Saturation(void);
extern void drvif_module_vdc_Set_scart_brightness_saturation(SCACT_RGB_GAIN_OFFSET_TYPE addr, unsigned short parameter);
#endif
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
UINT8 vd_lock_status(void);
UINT8 vd_newVlock_status(void);
unsigned char vdc_read_Vlines_the_same_flag(void);
extern UINT8 drvif_module_vdc_serration_check(void);
#endif

extern unsigned char drvif_module_vdc_Exist_noScaler(unsigned char ucInputSrc);
extern void drvif_module_vdc_input_filter_sel(bool enable, UINT16 * table);
extern void drv_module_vdc_input_filter_sel(bool enable, UINT16 * table);
extern unsigned char drvif_video_BurstLockStatus(void);
extern void drv_module_vdc_adc_clk_sel(VD_IFD_CLK_RATE clk_rate, VD_IFD_INPUT_DN_FILTER input_dn_filter);
extern void drvif_module_vdc_FixCKillMode(unsigned char a_ucFixed);
extern void drvif_module_vdc_set_27M_mode(unsigned char mode);
extern void drvif_module_vdc_ResetChChangeCount(void);
extern void drvif_module_vdc_for_demod_external(unsigned char ucInputSrc, VDC_INITIAL_OPTIONS  *ptOptions);
extern unsigned char drvif_module_vdc_IdentifyColorStandard_detect_fast(unsigned char ucInputSrc);
extern unsigned char drvif_video_get_625_flag(void) ;
extern unsigned char drvif_video_get_pal_flag(void);

extern void drv_module_vdc_hstate_vsync_error_init(void);
extern unsigned int drvif_module_vdc_read_hstate_vsync_error_unbalance(void);
extern unsigned short drvif_module_vdc_Hdetect_err_var_status(void);
extern void drvif_module_vdc_set_backporch_end(unsigned char end);

#ifdef CONFIG_ENABLE_VDC_OVER_MODULATION
extern unsigned int drvif_module_vdc_read_PeakWhite(void);
#endif

#ifdef VD_BURST_LOCATION_AUTO
extern void drvif_module_vdc_Enable_Auto_Burst_position(void);
extern void drvif_module_vdc_enable_burst_location_auto(void);
extern void drvif_module_vdc_disable_burst_location_auto(void);
#endif

bool module_vdc_check_vd_clock(void);

#if 1
extern unsigned char drvif_module_vdc_read_int_auto_scan_flag(void);
extern void drvif_module_vdc_set_int_auto_scan_flag(unsigned char on_off);
extern unsigned char drvif_module_vdc_read_external_ch_change_flag(void);
extern void drvif_module_vdc_set_external_ch_change_flag(unsigned char on_off);
extern unsigned char drvif_module_vdc_read_external_autoscan_flag(void);
extern void drvif_module_vdc_set_int_auto_scan_all_flag(unsigned char on_off);
extern void drvif_module_vdc_set_external_auto_scan_flag(unsigned char on_off);
#endif

extern unsigned char dvrif_module_vdc_get_frequency_bias( unsigned int frm_num );

extern bool drvif_module_vdc_GetLockStatus(void);
extern void drvif_module_vdc_ResetLockStatus(void);
extern bool drvif_module_vdc_GetChromaLockStatus(void);
extern void drvif_module_vdc_ResetChromaLockStatus(void);
extern bool drvif_module_vdc_GetBurstLockStatus(void);
extern bool drvif_module_vdc_Get625flag(void);
extern unsigned char drvif_module_GetNoiseStatus(void);

#ifdef CONFIG_SCART_ENABLE
extern void drvif_module_vdc_SetSCARTType(unsigned char type);
#endif

#ifdef scart_vdc_auto_balance_en
extern void drvif_module_vdc_SetADCGainOffset(const vdc_ADCGainOffset offset);
extern vdc_ADCGainOffset drvif_module_vdc_GetADCGainOffset(void);
extern void drvif_module_vdc_SetSCARTVDBrConSat(const VDBrConSat sat);
extern VDBrConSat drvif_module_vdc_GetSCARTVDBrConSat(void);
#endif

void drvif_module_DMA_CHK3D_ENABLE_control(VDC_DMA_CHK3D_ENABLE_MODE value);
void module_vdc_SECAM_notch_filter_sel(VDC_SECAM_Notch_Filter_MODE mode);
void module_vdc_Clear_SECAM_Setting(void);
void module_vdc_Set_SECAM_Setting(void);
void module_vdc_Hactive_Start(Hactive_Mode a_ucHactiveMode,unsigned int a_uiHactiveStart);
unsigned char drvif_module_vdc_YC1D_Check(void);
unsigned char module_vdc_FhAdjust(void);
void drvif_module_vdc_ResetCVideoFH1D(void);
#ifdef __cplusplus
}
#endif


#endif


