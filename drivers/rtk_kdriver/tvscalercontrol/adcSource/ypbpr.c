/* Kernel Header file */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/string.h>/*memset*/
#include <linux/semaphore.h>

/* RBUS Header file*/
#include <rbus/adc_reg.h>
#include <rbus/smartfit_reg.h>
#include <rbus/adc_smartfit_reg.h>
#include <rbus/sync_processor_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/auto_soy_reg.h>
#include <scalercommon/scalerCommon.h>
#include <scalercommon/scalerDrvCommon.h>

/* Tvscalercontrol Header file */
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/auto.h>
#include <tvscalercontrol/adcsource/ypbpr.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
#include <mach/rtk_platform.h>

#ifdef ENABLE_DRIVER_I3DDMA
#include <tvscalercontrol/scaler/modestate.h>
#include "tvscalercontrol/i3ddma/i3ddma.h"
#include "tvscalercontrol/i3ddma/i3ddma_drv.h"
#endif

#include <mach/rtk_log.h>
#define TAG_NAME_ADC "ADC"

/*==================== Definitions ================ */
/* #define YPBPR_SHOW_COSTTIME *//* To show Ypbpr.c API cost time */

#define MEASURE_HSTART_OFFSET_SD		0
#define MEASURE_HSTART_OFFSET_HD		10
#define AUTOSOY_STEP		3

typedef struct _MODE_USER_DATA_TYPE {
    unsigned char	FirstAuto;                 /* First Auto */
    unsigned short	HPosition;                 /* Horizontal Position */
    unsigned short	VPosition;                 /* Vertical Position */
    unsigned short	Clock;                     /* Clock Adjust */
    unsigned char	Phase;                     /* Phase Adjust */
} MODE_USER_DATA_TYPE;

/*==================== Global Variable================ */
unsigned char CLAMP_START_TABLE[] = {
	0x29,	/* 480i */
	0x2B,	/* 576i */
	0x29,	/* 480p */
	0x2B,	/* 576p */
	0x4D,	/* 720px50 */
	0x4D,	/* 720px60 */
	0x45,	/* 1080ix25 */
	0x45,	/* 1080ix30 */
	0x45,	/* 1080px50 */
	0x45,	/* 1080px60 */
	0x45,	/* 1080px23 */
	0x45,	/* 1080px24 */
	0x45,	/* 1080px25 */
	0x45,	/* 1080px29 */
	0x45	/* 1080px30 */
};

unsigned char CLAMP_END_TABLE[] = {
	0x33,	/* 480i */
	0x36,	/* 576i */
	0x33,	/* 480p */
	0x36,	/* 576p */
	0x72,	/* 720px50 */
	0x72,	/* 720px60 */
	0x5D,	/* 1080ix25 */
	0x5D,	/* 1080ix30 */
	0x5D,	/* 1080px50 */
	0x5D,	/* 1080px60 */
	0x5D,	/* 1080px23 */
	0x5D,	/* 1080px24 */
	0x5D,	/* 1080px25 */
	0x5D,	/* 1080px30 */
	0x5D	/* 1080px30 */
};

unsigned int Select_CurAdcValue(unsigned int val1, unsigned int val2, unsigned int val3);
void Print_DAC_result(void);
unsigned char DAC_result[64];
int avgOffset = 0;

static unsigned char bypass_auto_phase_flow = FALSE;//If true, means no need auto phase flow again. 
static StructSourceInput *YPbPr_input_pt;
extern StructDisplayInfo *Get_ADC_Dispinfo(void);
extern ModeInformationType *Get_ADC_Timinginfo(void);
extern void drvif_mode_print_mode_ID(unsigned char mode);
extern void Set_ADC_PhaseValue(unsigned short phasevalue);
unsigned char YPbPr_TimingDetectStage = YPBPR_SOY_STATE;/* 0: Auto soy 1:sync type detect 2:offline measure */

static unsigned char YPbPr_Auto_SOY_Enable = _ENABLE;
/*========================================================================
				YPbPr Auto SOY Aux Function Start
==========================================================================*/
static UINT8 AutoSOY_Aux_Detect_Enable = _DISABLE;
static UINT8 AutoSOY_Aux_Compare_Level_Min = 0x10;
static UINT8 AutoSOY_Aux_Max_Level_Min = 0x20;

/*======================================================================= */
void YPbPr_Connect_Setting(void)
{/* Do YPbPr coneect initial setting */
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	ADC_INITIAL_OPTIONS  *ptOptions = YPbPr_input_pt->InitOptions;

	/* SOG Path select Vin4p */
	adc_adc_clamp_ctrl2_reg.regValue = 0;
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_3_0 = 1;/* SOG1 input MUX select (offline) 001:VIN4P */
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = 1;/* SOG0 input MUX select (online) 0001:VIN4P */
	IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

	YPbPr_Negative_Clamp_DACSource();

	/* initial SyncP,ADC mux select */
	ADCSelectInput(_SRC_YPBPR, (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT), (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT),
	(((YPBPR_ADC_DATA_PATH *)ptOptions->path)->SWAP_PATH));

	YPbPr_SyncProc(); /* SyncProcessor source select,cap,window,deb  WILL 2014 for LG */

	YPbPr_TimingDetectStage = YPBPR_SOY_STATE;/* 0: Auto soy 1:sync type detect 2:offline measure */
}



unsigned char YPbPr_DetectTiming(void)
{
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clock_RBUS adc_adc_clock_reg;
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;
	auto_soy_soych0_a0_RBUS auto_soy_soych0_a0_reg;
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_dds_mix_w2_RBUS dds_pll_dds_mix_w2_reg;
	sync_processor_mv_ctrl_RBUS mv_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	sync_processor_sp1_clmpmsk_RBUS sync_processor_sp1_clmpmsk_reg;
	sync_processor_sp1_stbctrl_RBUS sync_processor_sp1_stbctrl_reg;
	unsigned char ret;
	StructDisplayInfo *p_dispinfo;
	ModeInformationType *p_timinginfo;
	unsigned short timingmodeindex;
	ADC_INITIAL_OPTIONS  *ptOptions;

#ifdef YPBPR_SHOW_COSTTIME
	static unsigned int before_time;
	static unsigned int after_time;
	if (YPbPr_TimingDetectStage == YPBPR_SOY_STATE) {
		before_time = IoReg_Read32(0xB801B690)/90;
	}
#endif
	if(YPbPr_TimingDetectStage != YPBPR_OFFLINE_STATE) {
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg,  sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_clmpmsk_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CLMPMSK_reg);
		sync_processor_sp1_clmpmsk_reg.s1_mask_clamp_en = _ENABLE;
		sync_processor_sp1_clmpmsk_reg.s1_mask_front = 2;
		sync_processor_sp1_clmpmsk_reg.s1_mask_back = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, sync_processor_sp1_clmpmsk_reg.regValue);
	}
	mv_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_Mv_CTRL_reg);
	mv_ctrl_reg.s1_mv_enable = 0;//disable macrovision
	IoReg_Write32(SYNC_PROCESSOR_Mv_CTRL_reg,  mv_ctrl_reg.regValue);
	
	mv_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_Mv_CTRL_reg);
	mv_ctrl_reg.s1_mv_occur = 0;//clear macrovision status
	IoReg_Write32(SYNC_PROCESSOR_Mv_CTRL_reg,  mv_ctrl_reg.regValue);
	
	#if 1
	adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
	adc_adc_clkgen_rgb_capture_reg.hs_catch_edge = 0;
	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg,  adc_adc_clkgen_rgb_capture_reg.regValue);
	#else
	adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
	adc_adc_clkgen_rgb_capture_reg.adc_clk_inv_en = 0;
	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg,  adc_adc_clkgen_rgb_capture_reg.regValue);
	#endif

	dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
	dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*disable new mode tracking*/
	dds_pll_dds_mix_w1_reg.lock_th = 6;
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

	adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_6 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_5 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

	/* prevent HSFB Dead Lock start    brandon 2015 */
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	sync_processor_sp1_ctrl_reg.s1_hs_fb_plswid_md = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
	sync_processor_sp1_ctrl_reg.s1_hs_fb_plswid_md = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
	/* prevent HSFB Dead Lock end    brandon 2015 */

	ptOptions = YPbPr_input_pt->InitOptions;
	p_timinginfo = Get_ADC_Timinginfo();
	p_dispinfo = Get_ADC_Dispinfo();
	YPbPr_DCRestore_Ctrl(_ENABLE, (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT));/* rerun detect turn on dcrestore */

	YPbPr_Clamp_Ctrl(_DISABLE, (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT), (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT));

	if (YPbPr_TimingDetectStage == YPBPR_SOY_STATE) {/* Around 90ms */
		p_dispinfo->ucMode_Table_Index = Mode_Table_Init_Index;/* For print timing info */
		if (YPbPr_DetectTiming_PadCheck() == FALSE) {
			/* Pad No Signal. Brandon */
			//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			YPbPr_DetectFail_NoSignal_Handler();
			return _MODE_NOSIGNAL;
		}

		if (_ENABLE == Scaler_Get_YPbPr_Auto_Soy_Enable()) {
			if (FALSE == YPbPr_AutoSOY_Detect()) {/* Auto restart setting (AutoSOY()) */
				/* lewis 20090216, if auto soy fail, re-run again */
				auto_soy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
				auto_soy_soych0_a0_reg.reg_auto_mode = _DISABLE;
				IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, auto_soy_soych0_a0_reg.regValue);
				YPbPr_DetectFail_NoSignal_Handler();/* Detect error */
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
				return _MODE_NOSIGNAL;
			} else {
				/* disable force APLL to free run state */
				dds_pll_dds_mix_w2_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W2_reg);
				dds_pll_dds_mix_w2_reg.apll_free_run = 0;
				IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, dds_pll_dds_mix_w2_reg.regValue);
				YPbPr_TimingDetectStage = YPBPR_SIGNALTYPE_STATE;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
				return _MODE_SUCCESS;
			}

		} else {/* ManualSOY */
			/* set calibration for manual mode and set manual compare level 0x12 for atlantic dac */
			YPbPr_SetSOYCompareLevel(YPBPR_SOY_PATH_SELECT, SOY_CH0_MANUAL_COMPARE_LEVEL);
			YPbPr_TimingDetectStage = YPBPR_SIGNALTYPE_STATE;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			return _MODE_SUCCESS;
		}
	} else if (YPbPr_TimingDetectStage == YPBPR_SIGNALTYPE_STATE) {/* Around 140ms */
		ret = SyncProc_SyncHandler(_SRC_YPBPR);
		if (ret == _MODE_SUCCESS) {
			YPbPr_TimingDetectStage = YPBPR_OFFLINE_STATE;/* To do offline measure */
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			return _MODE_SUCCESS;
		} else {
			if(ret == _MODE_NOSUPPORT) {
				YPbPr_DetectFail_Invalid_Handler();
			} else {
				YPbPr_DetectFail_NoSignal_Handler();
			}
			SyncProc_FunctionDisable(_SRC_YPBPR);
			YPbPr_TimingDetectStage = YPBPR_SOY_STATE;/* To do Auto SOY */
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			return ret;
		}
	} else {/* Around 70ms */

		timingmodeindex = p_dispinfo->ucMode_Table_Index;
		ret = SyncProc_TimingModeHandler(_SRC_YPBPR, YPbPr_input_pt); /* offlinemeasure check timing mode */

		if (ret != _MODE_SUCCESS) {
			if (ret == _MODE_NOSUPPORT) {
				YPbPr_DetectFail_Invalid_Handler();
			} else {
				YPbPr_DetectFail_NoSignal_Handler();
			}
			SyncProc_FunctionDisable(_SRC_YPBPR);
			YPbPr_TimingDetectStage = YPBPR_SOY_STATE;/* To do Auto SOY */
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			return ret;
		} else if (timingmodeindex != p_dispinfo->ucMode_Table_Index) {
#ifdef YPBPR_SHOW_COSTTIME
			after_time = IoReg_Read32(0xB801B690)/90;/* Detect success to get after time */
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####func:%s code time=%d ms######\r\n", __FUNCTION__, (after_time-before_time));
#endif
			//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "YPbpr ANALOG_MODE_MEASUREMENT\n");
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "HSYNCPULSECOUNT:%d\n", p_timinginfo->IHSyncPulseCount);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "IHCount:%d,IVCount:%d\n", p_timinginfo->IHCount, p_timinginfo->IVCount);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "IHFreq:%d,IVFreq:%d\n", p_timinginfo->IHFreq, p_timinginfo->IVFreq);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "**HS=%d,HW=%d,VS=%d,VW=%d\n",
				p_dispinfo->IPH_ACT_STA,
				p_dispinfo->IPH_ACT_WID,
				p_dispinfo->IPV_ACT_STA,
				p_dispinfo->IPV_ACT_LEN);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "**IHFreq=%d,IVFreq=%d,IHTotal=%d,IVTotal=%d,ADC_CLOCK:%d\n",
				p_dispinfo->IHFreq,
				p_dispinfo->IVFreq,
				p_dispinfo->IHTotal,
				p_dispinfo->IVTotal,
				p_dispinfo->INPUT_ADC_CLOCK);
			//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "YPbPr mode table index = %d\n", p_dispinfo->ucMode_Table_Index);
			drvif_mode_print_mode_ID(p_timinginfo->ModeCurr);

			drvif_clock_pfd_calibration();

		#ifndef ADC_UP_DOWN_CLAMP
			/* Timingmode syncprocessor clamp pulse set */
			YPbPr_SetClampPulse(YPBPR_SP_PATH,
				CLAMP_START_TABLE[p_dispinfo->ucMode_Table_Index % 15],
				CLAMP_END_TABLE[p_dispinfo->ucMode_Table_Index % 15],
				CLAMP_START_TABLE[p_dispinfo->ucMode_Table_Index % 15],
				CLAMP_END_TABLE[p_dispinfo->ucMode_Table_Index % 15],
				CLAMP_ALL);
		#endif

			YPbPr_SetSOY_ADC_ClockSel(p_dispinfo, SP_AUTO_SOY_CLK_SEL_NORMAL_STATE);

			YPbPr_SyncProc_TimingModeSetting(p_dispinfo->ucMode_Curr); /* SyncP mode setting */

			drvif_clock_select_VCO_div(p_dispinfo);

			drvif_clock_set_aclk(p_dispinfo, _SRC_YPBPR,  p_dispinfo->INPUT_ADC_CLOCK, FALSE);

			drvif_set_gain_from_table(_SRC_YPBPR);

		#ifdef ADC_UP_DOWN_CLAMP
			// set adc rgb offset to zero for up/dn clamp, rzhen@2017-06-22
			drvif_set_offset_from_table(_SRC_YPBPR);
		#endif
		}
#ifdef YPBPR_SHOW_COSTTIME
		else {
			before_time = IoReg_Read32(0xB801B690)/90;/* Reset before time */
		}
#endif

		if((p_dispinfo->ucMode_Curr == _MODE_480I) || (p_dispinfo->ucMode_Curr == _MODE_576I))
		{
			check_macrovision(p_dispinfo->ucMode_Curr);
		}

	}
	return ret;
}

void YPbPr_DetectFail_NoSignal_Handler(void)
{
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();
	p_dispinfo->IPH_ACT_WID_PRE = 0;
	p_dispinfo->IPV_ACT_LEN_PRE = 0;
	p_dispinfo->ucMode_Table_Index = Mode_Table_Init_Index;
}

void YPbPr_DetectFail_Invalid_Handler(void)
{
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();
	p_dispinfo->IPH_ACT_WID_PRE = 4095;
	p_dispinfo->IPV_ACT_LEN_PRE = 4095;
	p_dispinfo->ucMode_Table_Index = Mode_Table_Init_Index;
}


unsigned char  Scaler_Get_YPbPr_Auto_Soy_Enable(void)
{
	return YPbPr_Auto_SOY_Enable;
}

void  Scaler_Set_YPbPr_Auto_Soy_Enable(unsigned char ucEnable)
{
	YPbPr_Auto_SOY_Enable = ucEnable;
}

UINT8  Scaler_Get_AutoSOY_Aux_Detect_Enable(void)
{
	return AutoSOY_Aux_Detect_Enable;
}

void  Scaler_Set_AutoSOY_Aux_Detect_Enable(UINT8 ucEnable)
{
	AutoSOY_Aux_Detect_Enable = ucEnable;
}

UINT8  Scaler_Get_AutoSOY_Aux_Compare_Level_Min(void)
{
	return AutoSOY_Aux_Compare_Level_Min;
}

void  Scaler_Set_AutoSOY_Aux_Compare_Level_Min(UINT8 ucValue)
{
	AutoSOY_Aux_Compare_Level_Min = ucValue;
}

UINT8  Scaler_Get_AutoSOY_Aux_Max_Level_Min(void)
{
	return AutoSOY_Aux_Max_Level_Min;
}

void  Scaler_Set_AutoSOY_Aux_Max_Level_Min(UINT8 ucValue)
{
	AutoSOY_Aux_Max_Level_Min = ucValue;
}

unsigned char YPbPr_SetInput(StructSourceInput *input_pt)
{
	YPbPr_input_pt = input_pt;
	return 0;
}

void YPbPr_Negative_Clamp_DACSource(void)
{
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;

	/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial				   ***********move to Task********* */
	adc_adc_clamp_ctrl0_reg.regValue = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;/*G_channel negative clamp enable on Y0N*/
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

	adc_adc_ctl_1_reg.regValue = 0;
	adc_adc_ctl_1_reg.adc_ctl_grn_2_0 = 0;/* 3b DAC clamp voltage for green channel Voffset 0.4v */
#ifdef ADC_UP_DOWN_CLAMP
	adc_adc_ctl_1_reg.adc_ctl_grn_5_3 = 7;
#else
	adc_adc_ctl_1_reg.adc_ctl_grn_5_3 = 3;/* 3b DAC clamp voltage for green channel Vmid 0.4v */
#endif
	adc_adc_ctl_1_reg.adc_ctl_grn_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_grn_10_9 = 0;
	adc_adc_ctl_1_reg.adc_ctl_red_2_0 = 0;/* 3b DAC clamp voltage for red channel Voffset 0.4v */
#ifdef ADC_UP_DOWN_CLAMP
	adc_adc_ctl_1_reg.adc_ctl_red_5_3 = 7;
#else
	adc_adc_ctl_1_reg.adc_ctl_red_5_3 = 3;/* 3b DAC clamp voltage for red channel Vmid 0.4v */
#endif
	adc_adc_ctl_1_reg.adc_ctl_red_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_red_10_9 = 0;
	IoReg_Write32(ADC_ADC_CTL_1_reg, adc_adc_ctl_1_reg.regValue);

	adc_adc_ctl_2_reg.regValue = 0;
	adc_adc_ctl_2_reg.adc_ctl_blu_2_0 = 0;
#ifdef ADC_UP_DOWN_CLAMP
	adc_adc_ctl_2_reg.adc_ctl_blu_5_3 = 7;
#else
	adc_adc_ctl_2_reg.adc_ctl_blu_5_3 = 3;
#endif
	adc_adc_ctl_2_reg.adc_ctl_blu_8_6 = 3;
	adc_adc_ctl_2_reg.adc_ctl_blu_10_9 = 0;
	IoReg_Write32(ADC_ADC_CTL_2_reg, adc_adc_ctl_2_reg.regValue);
}

void YPbPr_ADCPowerControl(unsigned char on_off)
{
	//adc_adc_power_RBUS adc_adc_power_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;
	dds_pll_pll_phase_interpolation_RBUS dds_pll_pll_phase_interpolation_reg;

	//rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### %s:%s(%d) #####\n", __FILE__, __func__, __LINE__);
	if (TRUE == on_off) {
		down(get_adc_power_semaphore());
		drvif_adc_power_control(ADC_POWER_YPP_SCALER_CONTROL);
		up(get_adc_power_semaphore());
	} else {
		/* APLL LDO power on, PLL Power Down */
		dds_pll_pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		dds_pll_pll_ctrl_reg.pllpwdn = 1;		/* PLL power down */
		dds_pll_pll_ctrl_reg.apllldosel = 1;	/* LDO 1V */
		dds_pll_pll_ctrl_reg.apll_reg = 1;   	/* LDO 2V */
		dds_pll_pll_ctrl_reg.hs_dds2synp_sel = 0;/* hs latch falling edge */
		dds_pll_pll_ctrl_reg.apllldopow = 1;		/* LDO power on */
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);

		/* PLL_Phase_INTERPLOATION */
		dds_pll_pll_phase_interpolation_reg.regValue = IoReg_Read32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg);
		dds_pll_pll_phase_interpolation_reg.pllsphrl = 1;/* default 8k below 25M */
		dds_pll_pll_phase_interpolation_reg.pllsphrs = 4;/* default */
		IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg, dds_pll_pll_phase_interpolation_reg.regValue);

		/* PLL_SET */
		dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
		dds_pll_pll_set_reg.pllscp = 1;
		dds_pll_pll_set_reg.pllscs = 3;
		dds_pll_pll_set_reg.pllsrs = 2;/* default 10k */
		IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);


		/* Clamp disable */

		/* Clamp Enable 0: disable  1:enable */
		/* [8:0]=R2,G2,B2,R1,G1,B1,R0,G0,B0 */
		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

		/* VDC UP/DN disable */

		/* VDC UP/DN 0: disable  1:enable */
		/* [8:0]=R2,G2,B2,R1,G1,B1,R0,G0,B0 */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

		adc_adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
		adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);
	}
}


/*==================== Functions ================== */


void YPbPr_DCRestore_Ctrl(unsigned char enable, ADC_DATA_PATH adc_path)
{
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;

	if (enable) {
		adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0; /* only turn on G channel DC Restore for saving power , brandon add for LG */
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

	} else {
		/* DC restore enable 0:disable  1:enable */
		/* [11:0]=V2,V1,V0,R2,G2,B2,R1,G1,B1,R0,G0,B0 */
		adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

	}
}

void YPbPr_Clamp_Ctrl(unsigned char output_enable, ADC_DATA_PATH adc_path, ADC_SOY_PATH soy_path)
{

	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;

	adc_adc_clamp_ctrl2_reg.regValue =  IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = soy_path;
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_3_0 = soy_path;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);


#ifdef ADC_UP_DOWN_CLAMP
	if(output_enable){

		SyncProc_Updw_Clamp_Ctrl(_SRC_YPBPR);

		SyncProc_Updw_Clamp_Enable(_ENABLE);

		/* VDC UP/DN 0: disable  1:enable */
		/* [8:0]=R,R,G,G,B,B */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

		/* Voltage clamp negative G channel enable */
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);
	}else{

		SyncProc_Updw_Clamp_Enable(_DISABLE);

		/* VDC UP/DN 0: disable  1:enable */
		/* [8:0]=R2,G2,B2,R1,G1,B1,R0,G0,B0 */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);
	}

#else
	if (output_enable) {
			adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);

			adc_adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
			adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 0;
			if (ADC_DATA_INPUT0 == adc_path) {
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0; /* Red[2]- Negative Clamp Enable */
				                                             /* Green[1]- Negative Clamp Enable */
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;
					/* no swap for VMIDI/VOFFSET */
			} else if (ADC_DATA_INPUT1 == adc_path) {/* SOY must be VADC_G */
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 0;

			} else {/* if (ADC_DATA_INPUT2 == adc_path)*/ /*SOY must be VADC_R */
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 2;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 2;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 2;
				adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;
			}

			IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);
			IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);

			/* Clamp Enable 0: disable  1:enable */
			/* [11:0]=V2,V1,V0,R2,G2,B2,R1,G1,B1,R0,G0,B0 */
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 1; //enable clamp
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 1;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 1;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 1;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 1;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 1;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);
	} else {
			/* Clamp Enable 0: disable  1:enable */
			/* [11:0]=V2,V1,V0,R2,G2,B2,R1,G1,B1,R0,G0,B0 */
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);
	}
#endif
}

#define AUTO_SOY_DAC_CALIBTARION_OFFSET_TOLERANCE	6
#define AUTO_SOY_DAC_CALIBTARION_RANGE			8
#define AUTO_SOY_MANUAL_COMPARE_LEVEL_MAX		0x3f
#define AUTO_SOY_MANUAL_COMPARE_LEVEL_MIN		0x00
#define AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX	0x3f
#define AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIDDLE 	40
#define AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN	0x00
#define AUTO_SOY_CALIBRATION_FAST_DO_NUM		3
#define READ_AUTO_SOY_ADC_LUT_RESULT

unsigned long long LUT_ADC_ENTRY64;

unsigned char g_ucSOYCaliLUT[AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX+1];
unsigned int g_ucADDACtable[2];
#ifdef AutoSOY_Calibration_Fast_Flow
void YPbPr_AutoSOY_DAC_LUT_FILL_Fast(int a_lOffset)
{
	int i = 0;
	auto_soy_soych0_b0_RBUS auto_soy_soych0_b0_reg;
	unsigned char ucAdcValue = 0;

	for (i = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX; i >= 0; i--) {
		if (i > a_lOffset) {
			ucAdcValue = i - a_lOffset;
		} else {
			ucAdcValue = 0;
		}
		if (ucAdcValue > AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX) {
			ucAdcValue = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX;
		}

#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "addr=%d, value=%d\n", i, ucAdcValue);
#endif
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_data = ucAdcValue;
		auto_soy_soych0_b0_reg.reg_man_wr_addr = i;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* write enable */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		g_ucSOYCaliLUT[i] = ucAdcValue;
	}
}

int YPbPr_AutoSOY_DAC_LUT_Fast(int CurDacValue)
{
	auto_soy_soych0_a3_RBUS auto_soy_soych0_a3_reg;
	auto_soy_soych0_b0_RBUS auto_soy_soych0_b0_reg;
	auto_soy_no_trigger_flag_RBUS auto_soy_no_trigger_flag_reg;
	sync_processor_sp_pad_status_RBUS sync_processor_sp_pad_status_reg;
	unsigned int CurAdcValue = 0;
	unsigned int CurAdcValue1;
	unsigned int CurAdcValue2;
	unsigned int CurAdcValue3;
	int ManualCompLevelStart = 0, ManualCompLevelEnd = 0;
	int i = 0, j = 0, k = 0, CurDacShift = 0;
	unsigned char maxrange;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Input DAC level : Y=%d\n", CurDacValue);

	if (CurDacValue >= AUTO_SOY_DAC_CALIBTARION_RANGE) {
		ManualCompLevelStart = CurDacValue - AUTO_SOY_DAC_CALIBTARION_RANGE;
	} else {
		ManualCompLevelStart = AUTO_SOY_MANUAL_COMPARE_LEVEL_MIN;
	}
	if ((CurDacValue + AUTO_SOY_DAC_CALIBTARION_RANGE) <= AUTO_SOY_MANUAL_COMPARE_LEVEL_MAX) {
		ManualCompLevelEnd = CurDacValue + AUTO_SOY_DAC_CALIBTARION_RANGE;
	} else {
		ManualCompLevelEnd = AUTO_SOY_MANUAL_COMPARE_LEVEL_MAX;
	}

	if ((ManualCompLevelEnd - CurDacValue) > (CurDacValue - ManualCompLevelStart)) {
		maxrange = ManualCompLevelEnd - CurDacValue;
	} else {
		maxrange = CurDacValue - ManualCompLevelStart;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "CurDacValue=%d, ManualCompLevelStart=%d, ManualCompLevelEnd=%d, maxrange=%d\n", CurDacValue, ManualCompLevelStart, ManualCompLevelEnd, maxrange);

	for (i = CurDacValue; CurDacShift <= maxrange; CurDacShift++) {
		if (CurDacShift == 0) {
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);

			j = 20;
			while (j) {
				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0)
					break;

				j--;

			}

			if (0 == j) {
				/* this compare level no toggle */
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ADC Compare Level Toggle fail at : %x \n", i); 
				continue;
			}

			goto WRITE_LUT;
		}

		if ((i + CurDacShift) <= ManualCompLevelEnd) {
			/* printk(KERN_DEBUG "%d %d %d\n",i, i+CurDacShift,ManualCompLevelEnd); */

			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i + CurDacShift;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);

			j = 20;
			while (j) {
				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0)
					break;

				j--;
			}

			if (0 == j) {
				/* this compare level no toggle */
				/* then do lower bound */
			} else {
				i = i + CurDacShift;
				goto WRITE_LUT;
			}

		}

		if ((i - CurDacShift) >= ManualCompLevelStart) {
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "%d %d %d\n",i, i-CurDacShift,ManualCompLevelStart); 
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);


			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i - CurDacShift;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "%d %d\n",i , i -CurDacShift);

			j = 20;
			while (j) {

				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0) {
					break;
				}
				j--;
			}

			if (0 == j) {
				/* this compare level no toggle */
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "##ADC Compare Level Toggle fail at : 0x%x=%d \n", i,i); 
				continue;
			}

			i = i - CurDacShift;
			goto WRITE_LUT;

		}


WRITE_LUT:
		/* get 6bit ADC output (1st tap) */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue1 = auto_soy_no_trigger_flag_reg.tap_01_r;
		msleep(1);/* msec */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue2 = auto_soy_no_trigger_flag_reg.tap_01_r;
		msleep(1);/* msec */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue3 = auto_soy_no_trigger_flag_reg.tap_01_r;

		CurAdcValue = Select_CurAdcValue(CurAdcValue1, CurAdcValue2, CurAdcValue3);
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "i=%d CurAdcValue[%d %d %d] => %d\n", i, CurAdcValue1, CurAdcValue2, CurAdcValue3, CurAdcValue);
#endif

		/* software patch for ic bug, Adc value may read zero (chengying) */
		if ((CurAdcValue == 0) && (i > 5)) {
			for (k = 0; k < 5; ++k) {
				auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
				CurAdcValue = auto_soy_no_trigger_flag_reg.tap_01_r;
				if (CurAdcValue != 0) {
					break;
				}
			}
		}

		if (k == 5) { /*timeout adc value no write in LUT , get adc value throuth inpolation */
			break;
		}
		/* printk(KERN_DEBUG "Y: %d  Z : %d \n", i, CurAdcValue); */

		if ((ABS(i,CurAdcValue)>AUTO_SOY_DAC_CALIBTARION_OFFSET_TOLERANCE )&&(i>0))
		   break;
		
		g_ucADDACtable[1]=i;
		g_ucADDACtable[0]=CurAdcValue;
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", g_ucADDACtable[0], g_ucADDACtable[1]);

#if 0
		/* 6. write LUT */
		/* write Current LUT */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_data = i;
		auto_soy_soych0_b0_reg.reg_man_wr_addr = CurAdcValue;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		if (auto_soy_soych0_b0_reg.reg_man_wr_addr)
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", auto_soy_soych0_b0_reg.reg_man_wr_addr, auto_soy_soych0_b0_reg.reg_man_wr_data);
#endif
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* write enable */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		LUT_ADC_ENTRY64 = LUT_ADC_ENTRY64 | (((unsigned long long) 1) << CurAdcValue);
#endif
		/* printk(KERN_DEBUG "table = %llx\n",LUT_ADC_ENTRY64); */

		break;


	}
	return CurAdcValue;
}

void YPbPr_AutoSOY_Calibration_Fast(void)
{
	static unsigned char YPbPr_Need_SOY_Calibration = 1;
	unsigned int original_sog_path = 0;
	int i = 0;
	auto_soy_soych0_a0_RBUS auto_soy_soych0_a0_reg;
	auto_soy_soych0_b0_RBUS auto_soy_soych0_b0_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	sync_processor_sp_pad_status_RBUS sync_processor_sp_pad_status_reg;
	int lCurAdcValue = 0;
	int alCurAdcValue[AUTO_SOY_CALIBRATION_FAST_DO_NUM + 1][2];
	unsigned char ucCurAdcValueIndex = 0;
	//unsigned char addroffset, bitoffset;
	int MinManualCompLevel = 0;
	int lAdcValueOffset = 0;
	//LUT_ADC_ENTRY64 =  0;
	if (YPbPr_Need_SOY_Calibration == 1) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Do fast AutoSOY_DAC_Calibration\n");

		YPbPr_Power_ADCRGB(TRUE);/* Need ADC full power */

		/* 1. Disable Auto SOY function */
		auto_soy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
		auto_soy_soych0_a0_reg.reg_auto_mode = _DISABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, auto_soy_soych0_a0_reg.regValue);
		/* 2. Select SOG0 MUX from Calibration 6bit DAC input */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		original_sog_path = adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = ADC_SOY_MUX_CMP4_7_VSOG_CAL;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_7 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

		/* 3. look up table bypass (avoid to occur compare level conflict, if repeat run) */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_ch0_calibrate_bypass = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		//memset(DAC_result, 0, AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX);
		memset(alCurAdcValue, 0, AUTO_SOY_CALIBRATION_FAST_DO_NUM);
		/* Print_DAC_result(); */

		/* set SOG calibration DAC6B input level from 0x3f */
		for (i = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIDDLE; i >= 0; i--) {
			/* 4. set calibration DC level input */
			adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
			adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_5_0 = i;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

			/* 5. adjust manual compare level, until trigger tog_adc_sog0 */
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			lCurAdcValue = YPbPr_AutoSOY_DAC_LUT_Fast(i);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "i=%d, lCurAdcValue=%d (line:%d)\n", i, lCurAdcValue, __LINE__);
			if (0 == ucCurAdcValueIndex) {
				alCurAdcValue[ucCurAdcValueIndex][0] = g_ucADDACtable[0];
				alCurAdcValue[ucCurAdcValueIndex][1] = g_ucADDACtable[1];
				ucCurAdcValueIndex++;
			} else {
				if (lCurAdcValue == alCurAdcValue[ucCurAdcValueIndex-1][0]) {
					ucCurAdcValueIndex--;
					continue;
				} else {
					alCurAdcValue[ucCurAdcValueIndex][0] = g_ucADDACtable[0];
					alCurAdcValue[ucCurAdcValueIndex][1] = g_ucADDACtable[1];
					ucCurAdcValueIndex++;
				}
			}

			if (ucCurAdcValueIndex > AUTO_SOY_CALIBRATION_FAST_DO_NUM) {
				break;
			}

		}


		/* Get average offset */
		for (i = 0; i < AUTO_SOY_CALIBRATION_FAST_DO_NUM; i++) {
			#if 0	//update algorithm, rzhen@20161101
			lCurAdcValue = alCurAdcValue[i];

			addroffset = (lCurAdcValue >> 2) << 2;
			bitoffset = (lCurAdcValue - addroffset) << 3;
			MinManualCompLevel = (IoReg_Read32(AUTO_SOY_SOYCH0_D0_reg + addroffset) >> bitoffset) & 0x3f;
			#endif
			MinManualCompLevel = alCurAdcValue[i][1];
			lAdcValueOffset += alCurAdcValue[i][0]- MinManualCompLevel;
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "alCurAdcValue[%d][0]=%d, MinManualCompLevel=%d\n", i, alCurAdcValue[i][0], MinManualCompLevel);
		}

		avgOffset = lAdcValueOffset / AUTO_SOY_CALIBRATION_FAST_DO_NUM;
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Average offset = %d\n", avgOffset);

#if 0 //mark for bypass LUT, rzhen@20161101
		/* Print_DAC_result(); */
		YPbPr_AutoSOY_DAC_LUT_FILL_Fast(lAdcValueOffset / AUTO_SOY_CALIBRATION_FAST_DO_NUM);

		/* 7. disable look up table bypass */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_ch0_calibrate_bypass = _DISABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);
#endif
		/* 8. Select SOG0 MUX to original source */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = original_sog_path;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_7 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);
		YPbPr_Power_ADCRGB(FALSE);/* Disable ADC power to Save power */
		YPbPr_Need_SOY_Calibration = 0;
	} /* end of if first bootup */

}

#else
/* fill 64 level of adc lookup table */
void YPbPr_AutoSOY_DAC_LUT_FILL(void)
{
	char i = 0, j = 0;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
	unsigned char MinManualCompLevel = 0;
#endif
	unsigned int UpperManualCompLevel = 0;
	unsigned int LowerManualCompLevel = 0;
	char UpperAdcIndex = 0;
	char LowerAdcIndex = 0;
	unsigned char addroffset, bitoffset;
	soych0_b0_RBUS auto_soy_soych0_b0_reg;
	unsigned int CompareLevelRange = 0;

#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "======No hit list and fill it by interpolation========\n");
#endif
	/* if the first entry adc value & the last entry adc value is empty , fill max value & min manual compare level */
	if (((LUT_ADC_ENTRY64 >> AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX) & _BIT0) == 0) {
			/* write Current LUT */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_data = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX;
		auto_soy_soych0_b0_reg.reg_man_wr_addr = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", auto_soy_soych0_b0_reg.reg_man_wr_addr, auto_soy_soych0_b0_reg.reg_man_wr_data);
#endif
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* write enable */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* record adc entry */

		LUT_ADC_ENTRY64 = LUT_ADC_ENTRY64 | (((unsigned long long) 1) << AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX);
	}

	/* if the first entry adc value & the last entry adc value is empty , fill max value & min manual compare level */
	if (((LUT_ADC_ENTRY64 >> AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN) & _BIT0) == 0) {
			/* write Current LUT */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_data = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN;
		auto_soy_soych0_b0_reg.reg_man_wr_addr = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		if (auto_soy_soych0_b0_reg.reg_man_wr_addr) {
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", auto_soy_soych0_b0_reg.reg_man_wr_addr, auto_soy_soych0_b0_reg.reg_man_wr_data);
		}
#endif
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* write enable */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		LUT_ADC_ENTRY64 = LUT_ADC_ENTRY64 |  (((unsigned long long) 1) << AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN);
	}

	/* from max - 1 ~ min + 1 */
	for (i = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX - 1; i >= 1; i--) {
		if (((LUT_ADC_ENTRY64 >> i) & _BIT0) == 0) {
			/* get upper bound */
			for (j = i + 1; j <= AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX; j++) {
				if ((LUT_ADC_ENTRY64 >> j) & _BIT0) {
					addroffset = (j >> 2) << 2;
					bitoffset = (j - addroffset) << 3;
					UpperManualCompLevel = ((IoReg_Read32(AUTO_SOY_SOYCH0_D0_reg + addroffset) >> bitoffset) & 0x3f);
					UpperAdcIndex = j;
					break;
				}
			}

			/* get lower bound */
			for (j = i - 1; j >= AUTO_SOY_CALIBRATION_INPUT_LEVEL_MIN; j--) {
				if ((LUT_ADC_ENTRY64 >> j) & _BIT0) {
					addroffset = (j >> 2) << 2;
					bitoffset = (j - addroffset) << 3;
					LowerManualCompLevel =  ((IoReg_Read32(AUTO_SOY_SOYCH0_D0_reg + addroffset) >> bitoffset) & 0x3f);
					LowerAdcIndex = j;
					break;
				}
			}

			if ((UpperAdcIndex - LowerAdcIndex) == 0) {
				rtd_printk(KERN_ERR, TAG_NAME_ADC, "error !!! div 0 \n");
				return;
			}

			CompareLevelRange = (UpperManualCompLevel - LowerManualCompLevel) /  (UpperAdcIndex - LowerAdcIndex);

			for (j = UpperAdcIndex - 1; j > LowerAdcIndex; j--) {
				auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
				auto_soy_soych0_b0_reg.reg_man_wr_data = (unsigned int) (UpperManualCompLevel - (UpperAdcIndex  - j) * CompareLevelRange);
				auto_soy_soych0_b0_reg.reg_man_wr_addr = j;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
				if (auto_soy_soych0_b0_reg.reg_man_wr_addr) {
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", auto_soy_soych0_b0_reg.reg_man_wr_addr, auto_soy_soych0_b0_reg.reg_man_wr_data);
				}
#endif
				IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);


				/* write enable */
				auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
				auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
				IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

				/* record adc entry */
				LUT_ADC_ENTRY64 = LUT_ADC_ENTRY64 | (((unsigned long long)1) << j);
			}

			/* i = LowerAdcIndex - 1; */
		}

	}

#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
	for (i = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX; i >= 0; i--) {
			addroffset = (i >> 2) << 2;
			bitoffset = (i - addroffset) << 3;
			MinManualCompLevel = (IoReg_Read32(AUTO_SOY_SOYCH0_D0_reg + addroffset) >> bitoffset) & 0x3f;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Z : %d,  Y : %d\n", i, MinManualCompLevel);
			g_ucSOYCaliLUT[i] = MinManualCompLevel;

	}
#endif

}


void YPbPr_AutoSOY_DAC_LUT(int CurDacValue)
{
	soych0_a3_RBUS auto_soy_soych0_a3_reg;
	sp_pad_status_RBUS sync_processor_sp_pad_status_reg;
	no_trigger_flag_RBUS auto_soy_no_trigger_flag_reg;
	soych0_b0_RBUS auto_soy_soych0_b0_reg;
	unsigned int CurAdcValue = 0;
	unsigned int CurAdcValue1;
	unsigned int CurAdcValue2;
	unsigned int CurAdcValue3;
	int ManualCompLevelStart = 0, ManualCompLevelEnd = 0;
	int i = 0, j = 0, k = 0, CurDacShift = 0;
	unsigned char maxrange;

	/* printk(KERN_DEBUG "\nInput DAC level : Y=%d\n", CurDacValue); */

	if (CurDacValue >= AUTO_SOY_DAC_CALIBTARION_RANGE) {
		ManualCompLevelStart = CurDacValue - AUTO_SOY_DAC_CALIBTARION_RANGE;
	} else {
		ManualCompLevelStart = AUTO_SOY_MANUAL_COMPARE_LEVEL_MIN;
	}
	if ((CurDacValue + AUTO_SOY_DAC_CALIBTARION_RANGE) <= AUTO_SOY_MANUAL_COMPARE_LEVEL_MAX) {
		ManualCompLevelEnd = CurDacValue + AUTO_SOY_DAC_CALIBTARION_RANGE;
	} else {
		ManualCompLevelEnd = AUTO_SOY_MANUAL_COMPARE_LEVEL_MAX;
	}

	if ((ManualCompLevelEnd - CurDacValue) > (CurDacValue - ManualCompLevelStart)) {
		maxrange = ManualCompLevelEnd - CurDacValue;
	} else {
		maxrange = CurDacValue - ManualCompLevelStart;
	}

	/* printk(KERN_DEBUG "CurDacValue=%d, ManualCompLevelStart=%d, ManualCompLevelEnd=%d, maxrange=%d\n", CurDacValue, ManualCompLevelStart, ManualCompLevelEnd, maxrange); */

	for (i = CurDacValue; CurDacShift <= maxrange; CurDacShift++) {
		/* printk(KERN_DEBUG "i=%d, CurDacShift=%d\n", i, CurDacShift); */

		if (CurDacShift == 0) {
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);

			j = 20;
			while (j) {
				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0) {
					break;
				}
				j--;

			}

			if (0 == j) {
				/* this compare level no toggle */
				/*printk(KERN_DEBUG "ADC Compare Level Toggle fail at : %x \n", i); */
				continue;
			}

			goto WRITE_LUT;
		}

		if ((i + CurDacShift) <= ManualCompLevelEnd) {
			/* printk(KERN_DEBUG "%d %d %d\n",i, i+CurDacShift,ManualCompLevelEnd); */

			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i + CurDacShift;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);

			j = 20;
			while (j) {

				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0) {
					break;
				}
				j--;
			}

			if (0 == j) {
				/* this compare level no toggle */
				/* then do lower bound */
			} else {
				i = i + CurDacShift;
				goto WRITE_LUT;
			}

		}

		if ((i - CurDacShift) >= ManualCompLevelStart) {

			/* printk(KERN_DEBUG "%d %d %d\n",i, i-CurDacShift,ManualCompLevelStart); */
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);


			/* set manual compare level */
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = i - CurDacShift;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
			/* printk(KERN_DEBUG "%d %d\n",i , i -CurDacShift); */

			j = 20;

			while (j) {

				/* Polling tog_adc_sog0, check the ADC toggle */
				sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
				if (TRUE == sync_processor_sp_pad_status_reg.tog_adc_sog0) {
					break;
				}
				j--;
			}

			if (0 == j) {
				/* this compare level no toggle */
				/* printk(KERN_DEBUG "##ADC Compare Level Toggle fail at : 0x%x=%d \n", i,i); */
				continue;
			}

			i = i - CurDacShift;
			goto WRITE_LUT;

		}


WRITE_LUT:
		/* get 6bit ADC output (1st tap) */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue1 = auto_soy_no_trigger_flag_reg.tap_01_r;
		msleep(1);			/* msec */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue2 = auto_soy_no_trigger_flag_reg.tap_01_r;
		msleep(1);			/* msec */
		auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		CurAdcValue3 = auto_soy_no_trigger_flag_reg.tap_01_r;

		CurAdcValue = Select_CurAdcValue(CurAdcValue1, CurAdcValue2, CurAdcValue3);
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "i=%d CurAdcValue[%d %d %d] => %d\n", i, CurAdcValue1, CurAdcValue2, CurAdcValue3, CurAdcValue);
#endif

		/* software patch for ic bug, Adc value may read zero (chengying) */
		if ((CurAdcValue == 0) && (i > 5)) {
			for (k = 0; k < 5; ++k) {
				auto_soy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
				CurAdcValue = auto_soy_no_trigger_flag_reg.tap_01_r;
				if (CurAdcValue != 0) {
					break;
				}
			}
		}

		if (k == 5) { /* timeout adc value no write in LUT , get adc value throuth inpolation */
			break;
		}
		/* printk(KERN_DEBUG "Y: %d  Z : %d \n", i, CurAdcValue); */

		/* 6. write LUT */


		/* write Current LUT */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_data = i;
		auto_soy_soych0_b0_reg.reg_man_wr_addr = CurAdcValue;
#ifdef READ_AUTO_SOY_ADC_LUT_RESULT
		if (auto_soy_soych0_b0_reg.reg_man_wr_addr) {
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ww_addr(%d)=%d;\n", auto_soy_soych0_b0_reg.reg_man_wr_addr, auto_soy_soych0_b0_reg.reg_man_wr_data);
		}
#endif
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* write enable */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_man_wr_1t = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		LUT_ADC_ENTRY64 = LUT_ADC_ENTRY64 | (((unsigned long long) 1) << CurAdcValue);

		/* printk(KERN_DEBUG "table = %llx\n",LUT_ADC_ENTRY64); */

		break;


	}


}

void YPbPr_AutoSOY_Calibration(void)
{
	static unsigned char YPbPr_Need_SOY_Calibration = 1;
	if (YPbPr_Need_SOY_Calibration == 1) {
		unsigned int original_sog_path = 0;
		int i = 0;
		soych0_b0_RBUS auto_soy_soych0_b0_reg;
		soych0_a0_RBUS auto_soy_soych0_a0_reg;
		adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
		sp_pad_status_RBUS sync_processor_sp_pad_status_reg;
		LUT_ADC_ENTRY64 =  0;
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Do AutoSOY_Calibration\n");
		YPbPr_Power_ADCRGB(TRUE);/* Need ADC full power */
		/* 1. Disable Auto SOY function */
		auto_soy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
		auto_soy_soych0_a0_reg.reg_auto_mode = _DISABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, auto_soy_soych0_a0_reg.regValue);

		/* 2. Select SOG0 MUX from Calibration 6bit DAC input */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		original_sog_path = adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = ADC_SOY_MUX_CMP4_7_VSOG_CAL;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_7 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

		/* 3. look up table bypass (avoid to occur compare level conflict, if repeat run) */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_ch0_calibrate_bypass = _ENABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		memset(DAC_result, 0, AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX+1);
		/* Print_DAC_result(); */

		/* set SOG calibration DAC6B input level from 0x3f */
		for (i = AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX; i >= 0; i--) {
			/* 4. set calibration DC level input */
			adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
			adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_5_0 = i;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

			/* 5. adjust manual compare level, until trigger tog_adc_sog0 */
			/* write clear Tog_adc_sog0 */
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);

			YPbPr_AutoSOY_DAC_LUT(i);
		}

		/* Print_DAC_result(); */
		YPbPr_AutoSOY_DAC_LUT_FILL();

		/* 7. disable look up table bypass */
		auto_soy_soych0_b0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_B0_reg);
		auto_soy_soych0_b0_reg.reg_ch0_calibrate_bypass = _DISABLE;
		IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, auto_soy_soych0_b0_reg.regValue);

		/* 8. Select SOG0 MUX to original source */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = original_sog_path;
		adc_adc_clamp_ctrl2_reg.adc_sog_cmp1_7 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);
		YPbPr_Power_ADCRGB(FALSE);/* Disable ADC power to Save power */
		YPbPr_Need_SOY_Calibration = 0;
	} /* end of if first bootup */
}
#endif

/* The YPbPr_DetectTiming_PadCheck api is used to check no signal fast*/
unsigned char YPbPr_DetectTiming_PadCheck(void)
{
	auto_soy_soych0_a3_RBUS auto_soy_soych0_a3_reg;
	sync_processor_sp_pad_status_RBUS sync_processor_sp_pad_status_reg;
	int i;
	auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
	auto_soy_soych0_a3_reg.reg_manu_comp = 0x1;
	IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
	sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
	sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);
	msleep(2);/*pad detect check brandon*/
	for (i = 0; i < 4; i++) {
		sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
		if (sync_processor_sp_pad_status_reg.tog_adc_sog0 == 1) {
			return TRUE;
		} else if (i == 3) {
			return FALSE;
		} else {
			auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			auto_soy_soych0_a3_reg.reg_manu_comp = 0xb + i*10;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
			sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
			sync_processor_sp_pad_status_reg.tog_adc_sog0 = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);
			msleep(2);/*pad detect check brandon*/
		}
	}
	return FALSE;
}

void YPbPr_AutoSOY(void)
{
	adc_adc_clock_RBUS adc_adc_clock_reg;
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	auto_soy_soych0_a1_RBUS autosoy_soych0_a1_reg;
	auto_soy_soych0_a2_RBUS autosoy_soych0_a2_reg;
	auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
	dds_pll_dds_mix_w2_RBUS dds_pll_dds_mix_w2_reg;

	unsigned short apll_clk = 0;

	/* calibration do not enable */
	IoReg_Write32(AUTO_SOY_SOYCH0_B0_reg, 0x08);	//set to bypass LUT, rzhen@20161101

	/* set the boundary of max and min */
	autosoy_soych0_a1_reg.regValue = 0;
	autosoy_soych0_a1_reg.reg_max_hb = AUTO_SOY_MAX_LEVEL_HB;
	autosoy_soych0_a1_reg.reg_max_lb = AUTO_SOY_MAX_LEVEL_LB;
	autosoy_soych0_a1_reg.reg_min_hb = AUTO_SOY_MIN_LEVEL_HB;
	autosoy_soych0_a1_reg.reg_min_lb = AUTO_SOY_MIN_LEVEL_LB;
	IoReg_Write32(AUTO_SOY_SOYCH0_A1_reg, autosoy_soych0_a1_reg.regValue);

	/* seek max and seek min window */
	autosoy_soych0_a2_reg.regValue = 0;
	autosoy_soych0_a2_reg.reg_max_window = COMPARE_LEVEL_SEEK_MAX_WINDOW;
	autosoy_soych0_a2_reg.reg_min_window = COMPARE_LEVEL_SEEK_MIN_WINDOW;
	/* egger20120912 modify for compare level more sensitive in detect timing mode */
	autosoy_soych0_a2_reg.reg_min_diff = 0;/* COMPARE_LEVEL_SEEK_MIN_DIFF */
	/* soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_SEEK_MIN_DIFF; */
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, autosoy_soych0_a2_reg.regValue);

	/* set manual mode initial DC level & offset */
	autosoy_soych0_a3_reg.regValue = 0;
	autosoy_soych0_a3_reg.reg_dc_out_offset = 0x00;
	autosoy_soych0_a3_reg.reg_manu_comp = 0x10;
	autosoy_soych0_a3_reg.reg_dc_out_mode = 0;/*Will modify 0 for magellan2*//* DC_OUT_MODE_SEL; SD Suggestion */
	IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);

	/* Write clear Status read register */
	IoReg_Write32(AUTO_SOY_SOYCH0_A4_reg, 0x00000000);

	/* Enable Auto SOY */
	/* When the first DC level is not triggered, no Sync can be extracted. */
	/* if this happens that we need to change the First trigger DC level, let it can be trigger */
	autosoy_soych0_a0_reg.regValue = 0;
	autosoy_soych0_a0_reg.reg_auto_ini_dc = AUTO_SOY_COMPARE_LEVEL;
	autosoy_soych0_a0_reg.reg_deb_valid = AUTO_SOY_DEB_VALID;
	autosoy_soych0_a0_reg.reg_deb_update = AUTO_SOY_DEB_UPDATE;
	autosoy_soych0_a0_reg.dummy18020300_7 = 0;
	autosoy_soych0_a0_reg.reg_diff_sel_dclevel = COMPARE_LEVEL_UPDATE_OPTION;
	autosoy_soych0_a0_reg.reg_update_mode = 0;
	autosoy_soych0_a0_reg.reg_ma_mode = COMPARE_LEVEL_MA_MODE;
	autosoy_soych0_a0_reg.reg_auto_mode = _ENABLE;
	IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);


	/* Auto SOY Clock setting */
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pll_m = 0x1e;
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);

	// ADC_PLLPHSE_CTRL rzhen@2016-06-24
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2x = 1;//[To Smart Fit] PLLX (PLL X Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2y = 1;//[To Smart Fit] PLLY (PLL Y Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 1;//[To Smart Fit] PLLD2 1:ADC CLK=1/4 VCO CLK
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut =1;//Phase_Select_Method 1: Look-Up-Table
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	apll_clk = 27 * (dds_pll_pll_set_reg.pll_m + 3)/(dds_pll_pll_set_reg.pll_n + 2);
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	apll_clk = adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 ? apll_clk>>2 : apll_clk>>1;

	/* SOY ADC clock select */
	adc_adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_adc_clock_reg.adc_2x_sample_1 = (apll_clk < 75) ? 1 : 0; // clk < 75MHz, 2x
	adc_adc_clock_reg.adc_2x_sample_0 = SP_AUTO_SOY_CLK_INIT_SRC;
	adc_adc_clock_reg.adc_clock_10 = 0;/* RGB clock APLL */
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);

	/* APLL */
	dds_pll_dds_mix_w2_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W2_reg);
	dds_pll_dds_mix_w2_reg.apll_free_run = 1;
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, dds_pll_dds_mix_w2_reg.regValue);
	/* Auto SOY initial */

}


void YPbPr_AutoSOY_ReStart(unsigned char ReStart, unsigned int CompareLevel)/* input First DC Level */
{
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	auto_soy_no_trigger_flag_RBUS autosoy_no_trigger_flag_reg;
	/* printk(KERN_DEBUG "CompareLevel=%x\n",CompareLevel); */
	if (TRUE == ReStart) {
		/* Disable Auto SOY */
		autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
		autosoy_soych0_a0_reg.reg_auto_mode = 0;
		IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);

		/* disable no trigger watcher */
		autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		autosoy_no_trigger_flag_reg.reg_no_trig_win_size = AUTO_SOY_TRIGGER_DETECT_WIN;
		autosoy_no_trigger_flag_reg.reg_no_trig_watch_en = _DISABLE;
		IoReg_Write32(AUTO_SOY_NO_TRIGGER_FLAG_reg, autosoy_no_trigger_flag_reg.regValue);

		/* set new compare level, and enable Auto SOY */
		autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
		autosoy_soych0_a0_reg.reg_auto_ini_dc = CompareLevel; /* input First DC Level */
		autosoy_soych0_a0_reg.reg_auto_mode = 1;
		IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);

		autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		autosoy_no_trigger_flag_reg.no_trig_r = 1;/* write clear */
		IoReg_Write32(AUTO_SOY_NO_TRIGGER_FLAG_reg, autosoy_no_trigger_flag_reg.regValue);

		/* enable no trigger watcher */
		autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		autosoy_no_trigger_flag_reg.reg_no_trig_watch_en = _ENABLE;
		IoReg_Write32(AUTO_SOY_NO_TRIGGER_FLAG_reg, autosoy_no_trigger_flag_reg.regValue);
	} else {/* False */
		/* disable no trigger watcher */
		autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		autosoy_no_trigger_flag_reg.reg_no_trig_win_size = AUTO_SOY_TRIGGER_DETECT_WIN;
		autosoy_no_trigger_flag_reg.no_trig_r = 1;
		autosoy_no_trigger_flag_reg.reg_no_trig_watch_en = _DISABLE;
		IoReg_Write32(AUTO_SOY_NO_TRIGGER_FLAG_reg, autosoy_no_trigger_flag_reg.regValue);

		/* enable no trigger watcher */
		autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		autosoy_no_trigger_flag_reg.reg_no_trig_watch_en = _ENABLE;
		IoReg_Write32(AUTO_SOY_NO_TRIGGER_FLAG_reg, autosoy_no_trigger_flag_reg.regValue);
	}
}

/*#define ENABLE_AUTO_SOY_COMPARE_LEVEL_MSG*/

unsigned char YPbPr_AutoSOY_Detect(void)
{
	unsigned char i = 0, AutoSOYRestart = FALSE, AuxReStart = FALSE;
	auto_soy_no_trigger_flag_RBUS autosoy_no_trigger_flag_reg;
	auto_soy_soych0_a4_RBUS autosoy_soych0_a4_reg;
	unsigned int	CompareLevel = 0;
	unsigned int   CompareLevelMax = 0;
	unsigned int   DCLevel = 0;

	YPbPr_AutoSOY();

	YPbPr_AutoSOY_ReStart(FALSE, 0);

	RESTART_AUTO_SOY:

	msleep(1);

    /* 6bit ADC Max is 63, 63/3=21 */
	for (i = 0; i < 21; i++) {
		  autosoy_no_trigger_flag_reg.regValue = IoReg_Read32(AUTO_SOY_NO_TRIGGER_FLAG_reg);
		  if (autosoy_no_trigger_flag_reg.no_trig_r) {/* check notrig flag */
				/* the compare level have detected, but "no_trig_r" always is 1 */
				/* let Auto SOY always fail */
				if (_ENABLE == Scaler_Get_AutoSOY_Aux_Detect_Enable()) {
						autosoy_soych0_a4_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A4_reg);

						if ((autosoy_soych0_a4_reg.cmp_level_r > Scaler_Get_AutoSOY_Aux_Compare_Level_Min())
							&& (autosoy_soych0_a4_reg.max_r > Scaler_Get_AutoSOY_Aux_Max_Level_Min())) {
							DCLevel = autosoy_soych0_a4_reg.dc_level_r;

							if (FALSE == AuxReStart) {
								/* printk(KERN_DEBUG "special case AutoSOY detect success 1st, time:%x, val:%x\n", i, CompareLevel); */
								YPbPr_AutoSOY_ReStart(TRUE, DCLevel + AUTO_SOY_COMPARE_LEVEL_OFFSET);
								rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "AutoSOY-AUX DCLevel level = %x, trigger i = %d\n", DCLevel + AUTO_SOY_COMPARE_LEVEL_OFFSET, i);
								AuxReStart = TRUE;
								goto RESTART_AUTO_SOY;
							} else {/* if (TRUE == AuxReStart) */
								rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "AutoSOY-AUX detect success, time : %x, CompareLevel : %x, DCLevel : %x, CompareLevelMax : %x, Min_r : %x\n", i, CompareLevel, DCLevel, CompareLevelMax, autosoy_soych0_a4_reg.min_r);
								return TRUE;
							}
						} else {
							/* not able to detect the sync tip, compare level not updated, update DC level, 30mv/fail */
							YPbPr_AutoSOY_ReStart(TRUE, (AUTOSOY_STEP*i + 1));
							msleep(5);/* Fine tune by Will 2*/
							AuxReStart = FALSE;
#ifdef ENABLE_AUTO_SOY_COMPARE_LEVEL_MSG
							rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "auto soy level i =%x,AUTO_SOY_COMPARE_LEVEL=%x\n", i, (AUTO_SOY_COMPARE_LEVEL + AUTOSOY_STEP*i + 1));
#endif
						}
				} else {/* if (_DISABLE == Scaler_Get_AutoSOY_Aux_Detect_Enable()) */
						/* not able to detect the sync tip, compare level not updated, update DC level, 30mv/fail */
						YPbPr_AutoSOY_ReStart(TRUE, (AUTOSOY_STEP*i + 1));   /* change First DC Level (b8020300[29:24]) */
						msleep(5);/* Fine tune by Will 2*/
#ifdef ENABLE_AUTO_SOY_COMPARE_LEVEL_MSG
						rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "auto soy level i =%x,AUTO_SOY_COMPARE_LEVEL=%x\n", i, (AUTO_SOY_COMPARE_LEVEL + AUTOSOY_STEP*i + 1));
#endif
				}
		  } else { /* Current compare level setting by auto detection mechanism */
				autosoy_soych0_a4_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A4_reg);

				CompareLevel = autosoy_soych0_a4_reg.cmp_level_r;
				CompareLevelMax = autosoy_soych0_a4_reg.max_r;
				DCLevel = autosoy_soych0_a4_reg.dc_level_r;

				if (FALSE == AutoSOYRestart) {/* Run (False Restart) if notriger=0 in the first time */
					/* printk(KERN_DEBUG  "AutoSOY detect success 1st, time:%x, val:%x\n", i, CompareLevel); */
					YPbPr_AutoSOY_ReStart(TRUE, DCLevel + AUTO_SOY_COMPARE_LEVEL_OFFSET); /* first auto's comparelevel+0x5 Run AutoSOY restart again */
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "setting DCLevel level=0x%x,trigger i=%d\n", DCLevel + AUTO_SOY_COMPARE_LEVEL_OFFSET, i);
					AutoSOYRestart = TRUE;  /* change to TRUE */
					goto RESTART_AUTO_SOY;
				} else {
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "AutoSOY detect success, time:%d, CompareLevel:0x%x,DCLevel:0x%x,CompareLevelMax:0x%x,Min_r:0x%x\n", i, CompareLevel, DCLevel, CompareLevelMax, autosoy_soych0_a4_reg.min_r);
					return TRUE;
				}

		  }
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "AutoSOY detect fail, CompareLevel:%d,DCLevel=%x\n", CompareLevel, DCLevel);
	return FALSE;
}



/**
 * This function is used for the clamp circuit power control
 * Which clamp you want to use depend on the YPbPr signal path
 *
 * @param path: [input] There are totally 16 clamp path, and this parameter indicate which one you want to use.
 * @param enable: [input] You want to enable or disable this clamp.
 *
 * @Note
 *   When you want to output the clamp signal, you have to call this function and enable the corresponding clamp circuit.
 *
 * @return None
 *
 */
void YPbPr_SetClampPulse(unsigned char sync_indicator, unsigned char Yclamp_start, unsigned char Yclamp_end, unsigned char nYclamp_start, unsigned char nYclamp_end, unsigned char select)
{
	/* if call this function, need remenber to enable double buffer */
	sync_processor_sp1_clmp_RBUS sync_processor_sp1_clmp_reg;

	if (SYNC_PROCESSOR1 == sync_indicator) {
		sync_processor_sp1_clmp_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CLMP_reg);
		if (CLAMP_Y == select) {
			sync_processor_sp1_clmp_reg.s1_yclamp_sta = Yclamp_start;
			sync_processor_sp1_clmp_reg.s1_yclamp_end = Yclamp_end;
		} else if (CLAMP_NY == select) {
			sync_processor_sp1_clmp_reg.s1_nyclamp_sta = nYclamp_start;
			sync_processor_sp1_clmp_reg.s1_nyclamp_end = nYclamp_end;
		} else {/* if (CLAMP_ALL == select) */
			sync_processor_sp1_clmp_reg.s1_yclamp_sta = Yclamp_start;
			sync_processor_sp1_clmp_reg.s1_yclamp_end = Yclamp_end;
			sync_processor_sp1_clmp_reg.s1_nyclamp_sta = nYclamp_start;
			sync_processor_sp1_clmp_reg.s1_nyclamp_end = nYclamp_end;
		}
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMP_reg, sync_processor_sp1_clmp_reg.regValue);
	}
}


 /**
 * This function is used for setting the ADC phase
 *
 * @param phase: [input] Set the selected phase
 *
 * @return None
 *
 */
void YPbPr_SetPhase(unsigned char display, unsigned char phase, unsigned char uc64phase_limited)
{
	enum PLAFTORM_TYPE platform = PLATFORM_KXL;
	unsigned char fix_phase_value = 0;
	unsigned int M_VALUE = 0;
	unsigned int L_VALUE = 0;
	unsigned int A_temp1 = 0;
	unsigned int A_temp2 = 0;
	unsigned char ucDanger_distance, ucVCO_Divider4 = 0, ucDanger_tolerance = 6, ctrl, ucDanger_position =0;
	unsigned int ulRate;
	unsigned char PhaseMax = 0;
	unsigned int pixelclock;
	adc_adc_clock_RBUS adc_clock_reg;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
#ifdef ADC_JUMP_PHASE_METHOD2
	adc_adc_clkgen_rgb_capture_RBUS adc_clkgen_rgb_capture_reg;
#endif /* #ifdef ADC_JUMP_PHASE_METHOD2 */
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "phase=%d uc64phase_limited:%d\n", phase, uc64phase_limited);
#if 0
	if (p_dispinfo->IHCount_PRE) {
		ulRate = (unsigned int) CONFIG_CPU_XTAL_FREQ / 1000 * p_dispinfo->INPUT_ADC_CLOCK / p_dispinfo->IHCount_PRE;/* Standard pixel clock in kHz */
	} else {
		return;
	}
#endif
	//platform = get_platform();//Get platform
#ifdef ADC_JUMP_PHASE_METHOD2
	adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_clock_reg.adc_2x_sample_5 = 1;
	adc_clock_reg.adc_clock_6 = 0;
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);
#else /* #ifdef ADC_JUMP_PHASE_METHOD2 */
	adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_clock_reg.adc_2x_sample_5 = 1;
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);
#endif /* #ifdef ADC_JUMP_PHASE_METHOD2 */

	/* Code below is to select stable HSYNC latch edge. */
	/* There is about 2.8 ns delay between input clock into ADC and output from ADC. */
	/* Calculating the corresponding phase delay for 2.8 ns */
	/* Original Formula : Calculate the corresponding phase */
	/* ucSelect = 64 * 2.8 / (1000000 / ulRate); for ver C */

	/* Calculate pixel clock rate (round to MHz) */
	if (Scaler_InputSrcGetMainChType() == _SRC_VGA){
		pixelclock  = (((unsigned int)p_dispinfo->IHFreq * (unsigned int)p_dispinfo->IHTotal) * 2 / (1000 * 10));
		pixelclock  = (pixelclock >> 1) + (pixelclock & 0x01);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "pixelclock=%d", pixelclock);
	}

	/* ucVCO_Divider4 = pixelclock<0x64 ?   1 :  0; */
	/* [Code Sync][AlanLi][0980617][1] */
	ucVCO_Divider4 = select_adc_vco_div == 4 ? 1 : 0;
	/* [Code Sync][AlanLi][0980617][1][end] */

	if (ucVCO_Divider4 == 1) {/* vco divider = 4; */
		//if (uc64phase_limited) {
		//	phase = phase << 1;
		//}
		ucDanger_tolerance = ucDanger_tolerance << 1;
		PhaseMax = 128;

	} else {
		PhaseMax = 64;
	}

	if (Scaler_InputSrcGetMainChType() == _SRC_VGA) {
		if (ucVCO_Divider4 == 1)
			ucDanger_position = (61 - pixelclock/13) * 2;
		else
			ucDanger_position = 50 - ((pixelclock - 100) / 13);
	} else {/* ypbpr */
#if 0 //mark for auto phase flow, rzhen@2017-06-17
		switch(p_dispinfo->ucMode_Curr){
			case _MODE_720P60:
			case _MODE_720P50:
			case _MODE_1080P23:
			case _MODE_1080P24:
			case _MODE_1080P25:
			case _MODE_1080P29:
			case _MODE_1080P30:
				ucDanger_position = 0xe;
				break;

			case _MODE_1080P50:
			case _MODE_1080P60:
				fix_phase_value = 0x8;

				if(phase > 0x1f || phase < 0x8){
					M_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_M_reg)&0x03FF;
					L_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_L_reg);
					if(M_VALUE < 1){
						if((L_VALUE < 0xE00000) && (phase < 0x5 || phase > 0x1f)){
							phase = fix_phase_value;
						}
					}
				}

				if(phase != fix_phase_value) {
					A_temp1 = get_sod_software_auto_phase(phase);
					A_temp2 = get_sod_software_auto_phase(fix_phase_value);
					if(A_temp2 > A_temp1){
						phase = fix_phase_value;
					}
				}

				ucDanger_position = 0xe;
				break;

			case _MODE_1080I25:
			case _MODE_1080I30:
				fix_phase_value = 0x28;

				if(phase > 0x38 || phase < 0x10){
					M_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_M_reg)&0x03FF;
					L_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_L_reg);
					if(M_VALUE < 1){
						if(L_VALUE < 0x1000000){
							phase = fix_phase_value;
						}
					}
				}

				if(phase != fix_phase_value) {
					A_temp1 = get_sod_software_auto_phase(phase);
					A_temp2 = get_sod_software_auto_phase(fix_phase_value);
					if(A_temp2 > A_temp1){
						phase = fix_phase_value;
					}
				}

				ucDanger_position = 0xe;
				break;

			case _MODE_480P:
			case _MODE_576P:
				fix_phase_value = 0x20;

				if(phase > 0x28 && phase < 0x70){
					M_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_M_reg)&0x03FF;
					L_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_L_reg);
					if(M_VALUE < 1){
						if(L_VALUE < 0x1000000){
							phase = fix_phase_value;
						}
					}
				}

				if(phase != fix_phase_value) {
					A_temp1 = get_sod_software_auto_phase(phase);
					A_temp2 = get_sod_software_auto_phase(fix_phase_value);
					if(A_temp2 > A_temp1){
						phase = fix_phase_value;
					}
				}

				ucDanger_position = 0x0;
				break;

			case _MODE_576I:
				fix_phase_value = 0x50;

				if(phase < 0x50){
					M_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_M_reg)&0x03FF;
					L_VALUE = IoReg_Read32(SMARTFIT_AUTO_RESULT_PHASE_L_reg);
					if(M_VALUE < 1){
						if(L_VALUE < 0x1000000){
							phase = fix_phase_value;
						}
					}
				}

				if(phase != fix_phase_value) {
					A_temp1 = get_sod_software_auto_phase(phase);
					A_temp2 = get_sod_software_auto_phase(fix_phase_value);
					if(A_temp2 > A_temp1){
						phase = fix_phase_value;
					}
				}

				ucDanger_position = 0x0;
				break;

			case _MODE_480I:
			default:
				ucDanger_position = 0;
				break;
		}
#endif
	}

	/* Calculate the absolute value from the selected phase to transition */
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "after adjust phase=%d\n", phase);

#ifdef ADC_JUMP_PHASE_METHOD2
	if (ucDanger_position >= ucDanger_tolerance) {
		if (ucDanger_position + ucDanger_tolerance >= PhaseMax) {
			if (phase <= (ucDanger_position + ucDanger_tolerance - PhaseMax)) {
				ctrl = 1;
			} else if (phase >= (ucDanger_position - ucDanger_tolerance)) {
				ctrl = 1;
			} else {
				ctrl = 0;
			}
		} else {
			if ((phase >= (ucDanger_position - ucDanger_tolerance)) && (phase <= (ucDanger_position + ucDanger_tolerance))) {
				ctrl = 1;
			} else {
				ctrl = 0;
			}
		}
	} else {
		if (ucDanger_position == 0){
			ctrl = 0;
		}else{
			if (phase >= (ucDanger_position + PhaseMax - ucDanger_tolerance)) {
				ctrl = 1;
			} else if (phase <= (ucDanger_position + ucDanger_tolerance)) {
				ctrl = 1;
			} else {
				ctrl = 0;
			}
		}
	}
#else
	if (ucDanger_position >= phase) {
		ucDanger_distance = ((ucDanger_position - phase) < (PhaseMax+phase-ucDanger_position)) ? (ucDanger_position - phase) : (PhaseMax+phase-ucDanger_position);
	} else {
		ucDanger_distance = ((phase - ucDanger_position) < (PhaseMax+ucDanger_position-phase)) ? (phase - ucDanger_position) : (PhaseMax+ucDanger_position-phase);
	}

	ctrl = (ucDanger_distance >= ucDanger_tolerance) ? 0x00 : 0x01;
#endif

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,  "Danger_position=%d\n", ucDanger_position);
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC,  "ucDanger_tolerance=%d\n", ucDanger_tolerance);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,  "phase=%d\n", phase);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,  "ctrl=%d\n", ctrl);

#if 1
	adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);

	if (ctrl)  /* jump phasec */
		adc_clkgen_rgb_capture_reg.hs_catch_edge = 1; /* invert */
	else
		adc_clkgen_rgb_capture_reg.hs_catch_edge = 0; /* normal */

	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_clkgen_rgb_capture_reg.regValue);
#else
#ifdef ADC_JUMP_PHASE_METHOD2
	adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);

	if (ctrl)  /* jump phasec */
		adc_clkgen_rgb_capture_reg.adc_clk_inv_en = 1; /* invert */
	else
		adc_clkgen_rgb_capture_reg.adc_clk_inv_en = 0; /* normal */

	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_clkgen_rgb_capture_reg.regValue);
#else /* #ifdef ADC_JUMP_PHASE_METHOD2 */
	adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);

	if (ctrl)  /* jump phase */
		adc_clock_reg.adc_clock_6 = 1; /* invert */
	else
		adc_clock_reg.adc_clock_6 = 0; /* normal */

	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);
#endif /* #ifdef ADC_JUMP_PHASE_METHOD2 */
#endif

	// ADC_PLLPHSE_CTRL rzhen@2016-06-24
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut = 1;/* set phase through Look-Up-Table */
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = (phase>>6) & 0x01;/* set the phase */
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index = phase & 0x0000003f;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[YPbPr_SetPhase]finally phase=%d\n", adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index);
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	if(phase >= 64)
		Set_ADC_PhaseValue(phase>>1);/* Record phase */
	else
		Set_ADC_PhaseValue(phase);/* Record phase */
}

void YPbPr_SetSOY_ADC_ClockSel(StructDisplayInfo *p_dispinfo, unsigned char state)
{
	adc_adc_clock_RBUS adc_adc_clock_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
#if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_YPBPR_ADC_CLK)
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	//auto_soy_soych0_a1_RBUS autosoy_soych0_a1_reg;
	auto_soy_soych0_a2_RBUS autosoy_soych0_a2_reg;
#endif /* #if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_YPBPR_ADC_CLK) */
	auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	//sync_processor_sp1_coastftbk_RBUS sync_processor_sp1_coastftbk_reg;//Need to check

	unsigned int dispCurMode;

	if (SP_AUTO_SOY_CLK_SEL_INIT_STATE == state) {
		adc_adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
		adc_adc_clock_reg.adc_2x_sample_0 = SP_AUTO_SOY_CLK_INIT_SRC;
		IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);
	} else { /* if (SP_AUTO_SOY_CLK_SEL_NORMAL_STATE == state) */
		dispCurMode = p_dispinfo->ucMode_Curr;

#if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_YPBPR_ADC_CLK)
		switch (dispCurMode) {
		case _MODE_480I:
		case _MODE_576I:
		case _MODE_480P:
		case _MODE_576P:
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_6 = 0; // adjust dc level for SD timing Brandon
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

			autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
			if(dispCurMode == _MODE_576I){
				autosoy_soych0_a0_reg.reg_deb_valid = 0x22;//Q8390
			}else{
				autosoy_soych0_a0_reg.reg_deb_valid = 0x1f;
			}
			autosoy_soych0_a0_reg.reg_deb_update = 0x1f;
			autosoy_soych0_a0_reg.reg_update_mode = 0x0;
			IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);

			autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			if(dispCurMode == _MODE_576I){
				autosoy_soych0_a3_reg.reg_dc_out_offset = - avgOffset;
			}else{
				autosoy_soych0_a3_reg.reg_dc_out_offset = 2 - avgOffset;
			}
			autosoy_soych0_a3_reg.reg_dc_out_mode = 0xd;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);

			autosoy_soych0_a2_reg.regValue = 0;
			if(dispCurMode == _MODE_576I)
				autosoy_soych0_a2_reg.reg_max_window = COMPARE_LEVEL_NORMAL_576I_SEEK_MAX_WINDOW;//Patch for MSPG3233
			else
				autosoy_soych0_a2_reg.reg_max_window = COMPARE_LEVEL_NORMAL_SD_SEEK_MAX_WINDOW;
			autosoy_soych0_a2_reg.reg_min_window = COMPARE_LEVEL_NORMAL_SD_SEEK_MIN_WINDOW;
			IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, autosoy_soych0_a2_reg.regValue);
#if 0//Need to check by will
			sync_processor_sp1_coastftbk_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CoastFtBk_reg);
			sync_processor_sp1_coastftbk_reg.s1_coast_back = 5;
			IoReg_Write32(SYNC_PROCESSOR_SP1_CoastFtBk_reg, sync_processor_sp1_coastftbk_reg.regValue);
#endif
		break;

		default:
			autosoy_soych0_a2_reg.regValue = 0;
			autosoy_soych0_a2_reg.reg_max_window = COMPARE_LEVEL_NORMAL_HD_SEEK_MAX_WINDOW;
			autosoy_soych0_a2_reg.reg_min_window = COMPARE_LEVEL_NORMAL_HD_SEEK_MIN_WINDOW;
			IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, autosoy_soych0_a2_reg.regValue);

			autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			autosoy_soych0_a3_reg.reg_dc_out_offset = - avgOffset;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
		
		break;
		}

		adc_adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
		adc_adc_clock_reg.adc_2x_sample_0 = SP_AUTO_SOY_CLK_SRC;
		IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);
#endif /* #if (SP_AUTO_SOY_CLK_SRC == AUTO_SOY_CLK_YPBPR_ADC_CLK) */
	}

}


void YPbPr_SetSOYCompareLevel(unsigned char soy_path, unsigned char value)
{
	auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	auto_soy_soych1_a0_RBUS autosoy_soych1_a0_reg;

	if (SP_VHS_SOURCE_SOY0 == soy_path) {
		autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
		autosoy_soych0_a3_reg.reg_manu_comp = value;
		IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
	} else {/* if (SP_VHS_SOURCE_SOY1 == soy_path) */
		autosoy_soych1_a0_reg.regValue = 0;
		autosoy_soych1_a0_reg.reg_off_manu_comp = value;
		IoReg_Write32(AUTO_SOY_SOYCH1_A0_reg, autosoy_soych1_a0_reg.regValue);
	}
}

void YPbPr_Apll_Mode_Setting(unsigned int CurModeIdx)
{
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_p_code_mapping_methods_RBUS dds_pll_p_code_mapping_methods_reg;
	switch (CurModeIdx) {
	case _MODE_480I:
		dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
		dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*enable new mode tracking*/
		dds_pll_dds_mix_w1_reg.lock_th = 6;
		IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);
	break;

	case _MODE_480P:
		dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
		dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*enable new mode tracking*/
		dds_pll_dds_mix_w1_reg.lock_th = 5;
		IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

		dds_pll_p_code_mapping_methods_reg.regValue = IoReg_Read32(DDS_PLL_P_CODE_mapping_methods_reg);
		dds_pll_p_code_mapping_methods_reg.g_value = 0x3;
		IoReg_Write32(DDS_PLL_P_CODE_mapping_methods_reg, dds_pll_p_code_mapping_methods_reg.regValue);
	break;

	case _MODE_576I:
		dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
		dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*enable new mode tracking*/
		dds_pll_dds_mix_w1_reg.lock_th = 6;
		IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);
	break;

	case _MODE_576P:
		dds_pll_dds_mix_w1_reg.regValue = IoReg_Read32(DDS_PLL_DDS_MIX_W1_reg);
		dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*enable new mode tracking*/
		dds_pll_dds_mix_w1_reg.lock_th = 5;
		IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);

		dds_pll_p_code_mapping_methods_reg.regValue = IoReg_Read32(DDS_PLL_P_CODE_mapping_methods_reg);
		dds_pll_p_code_mapping_methods_reg.g_value = 0x3;
		IoReg_Write32(DDS_PLL_P_CODE_mapping_methods_reg, dds_pll_p_code_mapping_methods_reg.regValue);
	break;

	case _MODE_720P50:
	case _MODE_720P60:
	break;

	case _MODE_1080I25:
	case _MODE_1080I30:
	break;

	case _MODE_1080P60:
	case _MODE_1080P50:
	break;


	case _MODE_1080P23:
	case _MODE_1080P24:
	case _MODE_1080P25:
	case _MODE_1080P29:
	case _MODE_1080P30:
	break;

	default:
	break;
	}
}


void YPbPr_SyncProc_TimingModeSetting(unsigned int CurModeIdx)
{
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
	adc_adc_clock_RBUS adc_adc_clock_reg;
	sync_processor_sp1_stbctrl_RBUS sync_processor_sp1_stbctrl_reg;
	sync_processor_sp1_dcnt_RBUS sync_processor_sp1_dcnt_reg;
	sync_processor_sp1_clmpctrl_RBUS sync_processor_sp1_clmpctrl_reg;
#else
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-02
	 */
	#if 0	//compile error @rzhen
	sp2_stbctrl_RBUS  sync_processor_sp2_stbctrl_reg;
	sp2_dcnt_RBUS sync_processor_sp2_dcnt_reg;
	sp2_clmpctrl_RBUS  sync_processor_sp2_clmpctrl_reg;
	#endif
#endif
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;

	switch (CurModeIdx) {
	case _MODE_480I:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_480I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_480I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_480I;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

#else	/* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
	#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_480I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_480I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_480I;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
	#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_480P:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_480P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_480P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_480P;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

#else	/* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_480P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_480P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_480P;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 1;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_576I:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_576I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_576I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_576I;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

#else	/* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_576I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_576I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_576I;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_576P:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_576P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_576P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_576P;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

#else /* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_576P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_576P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_576P;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 1;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_720P50:
	case _MODE_720P60:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_720P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_720P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_720P;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);
#else	/* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_720P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_720P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_720P;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_1080I25:
	case _MODE_1080I30:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_1080I;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080I;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);
#else	/* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_1080I;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080I;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	case _MODE_1080P60:
	case _MODE_1080P50:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_1080P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080P;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

		adc_adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
		adc_adc_clock_reg.adc_2x_sample_1 = 0;  /* Brandon Merlin 1x SOY APLL clock 1080P */
		IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);

#else   /* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_1080P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080P;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;


	case _MODE_1080P23:
	case _MODE_1080P24:
	case _MODE_1080P25:
	case _MODE_1080P29:
	case _MODE_1080P30:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_1080P;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080P;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);
#else   /* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_1080P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_1080P;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_1080P;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;

	default:
#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_INIT;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_INIT;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);
#else   /* if (SYNC_PROCESSOR2 == YPBPR_SP_PATH) */
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_INIT;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_INIT;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
#endif
	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	break;
	}

#if (SYNC_PROCESSOR1 == YPBPR_SP_PATH)
		sync_processor_sp1_clmpctrl_reg.regValue = 0;
		sync_processor_sp1_clmpctrl_reg.s1_clamp_dben = 0;
		sync_processor_sp1_clmpctrl_reg.s1_clamp_cnt_unit = YPBPR_CLAMP_CNT_UNIT;
		sync_processor_sp1_clmpctrl_reg.s1_clamp_clksrc = YPBPR_CLAMP_CLKSRC;
		sync_processor_sp1_clmpctrl_reg.s1_clamp_en = _ENABLE;
		sync_processor_sp1_clmpctrl_reg.s1_yclamp_hs_inv = YPBPR_CLAMP_Y_REF_EDGE;
		sync_processor_sp1_clmpctrl_reg.s1_nyclamp_hs_inv = YPBPR_CLAMP_NY_REF_EDGE;
		sync_processor_sp1_clmpctrl_reg.s1_clamp_test_en = 0;
		sync_processor_sp1_clmpctrl_reg.s1_adc_hs_syncedge = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, sync_processor_sp1_clmpctrl_reg.regValue);
		sync_processor_sp1_clmpctrl_reg.s1_clamp_dben = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, sync_processor_sp1_clmpctrl_reg.regValue);
#else
		/* enable CLAMP signal output */
		#if 0	//compile error @rzhen
		sync_processor_sp2_clmpctrl_reg.regValue = 0;
		sync_processor_sp2_clmpctrl_reg.s2_clamp_dben = 0;
		sync_processor_sp2_clmpctrl_reg.s2_clamp_cnt_unit = YPBPR_CLAMP_CNT_UNIT;
		sync_processor_sp2_clmpctrl_reg.s2_clamp_clksrc = YPBPR_CLAMP_CLKSRC;
		sync_processor_sp2_clmpctrl_reg.s2_clamp_en = _ENABLE;
		sync_processor_sp2_clmpctrl_reg.s2_yclamp_hs_inv = YPBPR_CLAMP_Y_REF_EDGE;
		sync_processor_sp2_clmpctrl_reg.s2_clamp_test_en = 0;
		sync_processor_sp2_clmpctrl_reg.s2_adc_hs_syncedge = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CLMPCTRL_reg, sync_processor_sp2_clmpctrl_reg.regValue);

		sync_processor_sp2_clmpctrl_reg.s2_clamp_dben = _ENABLE;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CLMPCTRL_reg, sync_processor_sp2_clmpctrl_reg.regValue);
		#endif
#endif

}

void YPbPr_ADC_LPF_BW_Setting(StructDisplayInfo *p_dispinfo)
{
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	smartfit_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;
	unsigned int dispCurMode;
	dispCurMode = p_dispinfo->ucMode_Curr;

	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;

	switch (dispCurMode) {
	case _MODE_480I:
	case _MODE_576I:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_10M;
	break;

	case _MODE_480P:
	case _MODE_576P:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_25M;
	break;

	case _MODE_720P50:
	case _MODE_720P60:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_75M;
	break;

	case _MODE_1080I25:
	case _MODE_1080I30:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_75M;
	break;

	case _MODE_1080P50:
	case _MODE_1080P60:
	case _MODE_1080P23:
	case _MODE_1080P24:
	case _MODE_1080P25:
	case _MODE_1080P29:
	case _MODE_1080P30:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_150M;
	break;

	default:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_75M;
	break;
	}

	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
	return;
}

void YPbPr_Signal_Lock_Check(void)
{
	int count = 5;
	dds_pll_pe_mearsure_RBUS dds_pll_pe_measure_reg;

	dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);
	dds_pll_pe_measure_reg.pe_measure_en = 1;

	IoReg_Write32(DDS_PLL_PE_MEARSURE_reg, dds_pll_pe_measure_reg.regValue);
	mdelay(1);
	dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);
	dds_pll_pe_measure_reg.pe_measure_en = 0;
	IoReg_Write32(DDS_PLL_PE_MEARSURE_reg, dds_pll_pe_measure_reg.regValue);
	dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);


	while ((dds_pll_pe_measure_reg.pe_measure_reg > 100) && count) {
		dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);
		dds_pll_pe_measure_reg.pe_measure_en = 1;
		IoReg_Write32(DDS_PLL_PE_MEARSURE_reg, dds_pll_pe_measure_reg.regValue);
        mdelay(1);
		dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);
		dds_pll_pe_measure_reg.pe_measure_en = 0;
		IoReg_Write32(DDS_PLL_PE_MEARSURE_reg, dds_pll_pe_measure_reg.regValue);
		dds_pll_pe_measure_reg.regValue = IoReg_Read32(DDS_PLL_PE_MEARSURE_reg);
		count--;

	}

}


void YPbPr_Power_ADCRGB(unsigned char enable)
{
	down(get_adc_power_semaphore());
	if (enable) {
		drvif_adc_power_control(ADC_POWER_YPP_SCALER_CONTROL);
	} else {
		drvif_adc_power_control(ADC_POWER_YPP_ONLY_DETECT_CONTROL);
	}
	up(get_adc_power_semaphore());
}

/**
 * This API is used to set the YPbPr mode related setting, like clock¡Bphase¡Bclamp pulse¡Boutput clamp signal¡Benable auto SOY level compare
 * enable ABL¡Benable ADC
 * @param [input] : None
 * @param [output] : None
 *
 *
 * @return None
 *
 */
void YPbPr_Setup(void)
{/* This api is setting after detect timing success  mode setting */
	ADC_INITIAL_OPTIONS  *ptOptions;
	auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	auto_soy_soych1_a0_RBUS autosoy_soych1_a0_reg;
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();
    ptOptions = YPbPr_input_pt->InitOptions;

    YPbPr_ADC_LPF_BW_Setting(p_dispinfo);

	YPbPr_Power_ADCRGB(TRUE); /* Turn RGB power for VSC control display on , brandon */

#if 0//Move to VFE offline state
	drvif_clock_pfd_calibration();

	YPbPr_SetClampPulse(YPBPR_SP_PATH,                       /* Timingmode syncprocessor clamp pulse set */
	CLAMP_START_TABLE[p_dispinfo->ucMode_Table_Index % 15],
	CLAMP_END_TABLE[p_dispinfo->ucMode_Table_Index % 15],
	CLAMP_START_TABLE[p_dispinfo->ucMode_Table_Index % 15],
	CLAMP_END_TABLE[p_dispinfo->ucMode_Table_Index % 15],
	CLAMP_ALL);

	YPbPr_SetSOY_ADC_ClockSel(p_dispinfo, SP_AUTO_SOY_CLK_SEL_NORMAL_STATE);

	YPbPr_SyncProc_TimingModeSetting(p_dispinfo->ucMode_Curr); /* SyncP mode setting */

	drvif_clock_select_VCO_div(p_dispinfo);

	drvif_clock_set_aclk(p_dispinfo, _SRC_YPBPR,  p_dispinfo->INPUT_ADC_CLOCK, FALSE);

	drvif_set_gain_from_table(_SRC_YPBPR);
#endif

	YPbPr_Clamp_Ctrl(_ENABLE, (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT),     /* enable clamp */
	(((YPBPR_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT));

	if (_DISABLE == Scaler_Get_YPbPr_Auto_Soy_Enable()) {
		if (YPBPR_SOY_PATH_SELECT) {
			autosoy_soych1_a0_reg.regValue = 0;
			autosoy_soych1_a0_reg.reg_off_manu_comp = SOY_CH1_MANUAL_COMPARE_LEVEL;
			IoReg_Write32(AUTO_SOY_SOYCH1_A0_reg, autosoy_soych1_a0_reg.regValue);
		} else {
			autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			autosoy_soych0_a3_reg.reg_manu_comp = SOY_CH0_MANUAL_COMPARE_LEVEL;
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
		}
	}

	mdelay(2);

	YPbPr_DCRestore_Ctrl(_DISABLE, (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT));   /* disable DC_restore */

#ifndef ADC_UP_DOWN_CLAMP
	/* CSW+ 0961224 Set ABL after initial gain/offset */
	if (_ENABLE == get_adc_abl_function()) {
		YPbPr_ABL_SETTING_ON(p_dispinfo->ucMode_Curr);
	} else {
		YPbPr_ABL_SETTING_OFF();
		drvif_set_offset_from_table(_SRC_YPBPR);
	}
#endif

	YPbPr_Apll_Mode_Setting(p_dispinfo->ucMode_Curr);

}

void YPbPr_ABL_SETTING_OFF(void)
{
	abl_abl_ctrl_RBUS abl_abl_ctrl_reg;
	abl_abl_ctrl_reg.regValue = IoReg_Read32(ABL_ABL_CTRL_reg);
	abl_abl_ctrl_reg.abl_en = 0;
	abl_abl_ctrl_reg.abl_red_en = 0;
	abl_abl_ctrl_reg.abl_grn_en = 0;
	abl_abl_ctrl_reg.abl_blu_en = 0;
	IoReg_Write32(ABL_ABL_CTRL_reg, abl_abl_ctrl_reg.regValue);
}


/* ABL window reference HS failing edge */
void YPbPr_ABL_SETTING_ON(unsigned int  CurModeIdx)
{
	abl_abl_window_RBUS abl_window_reg;
	abl_abl_ctrl_RBUS abl_ctrl_reg;
	abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
	abl_abl_mgn_b_RBUS abl_mgn_b_reg;
	abl_abl_status_RBUS abl_status_reg;
	YPbPr_ABL_SETTING_OFF();

	abl_window_reg.regValue = 0;

	switch (CurModeIdx) {
	case _MODE_480I:
		abl_window_reg.abl_vend = YPBPR_ABL_480I_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_SD_60HZ_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_SD_60HZ_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_SD_60HZ_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_SD_60HZ_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_SD_60HZ_H_START;
		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;

	case _MODE_480P:
		abl_window_reg.abl_vend = YPBPR_ABL_480P_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_SD_60HZ_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_SD_60HZ_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_SD_60HZ_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_SD_60HZ_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_SD_60HZ_H_START;
		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);
	break;

	case _MODE_576I:
		abl_window_reg.abl_vend = YPBPR_ABL_576I_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_SD_50HZ_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_SD_50HZ_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_SD_50HZ_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_SD_50HZ_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_SD_50HZ_H_START;
		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;

	case _MODE_576P:
		abl_window_reg.abl_vend = YPBPR_ABL_576P_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_SD_50HZ_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_SD_50HZ_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_SD_50HZ_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_SD_50HZ_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_SD_50HZ_H_START;
		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;

	case _MODE_720P50: /* HD timing */
	case _MODE_720P60:
		abl_window_reg.abl_vend = YPBPR_ABL_720P_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_HD_720P_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_HD_720P_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_HD_720P_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_HD_720P_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_HD_720P_H_START;

		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;

	case _MODE_1080I25:
	case _MODE_1080I30:
		abl_window_reg.abl_vend = YPBPR_ABL_1080I_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_HD_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_HD_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_HD_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_HD_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_HD_H_START;
		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;

	case _MODE_1080P50:
	case _MODE_1080P60:
	case _MODE_1080P23:
	case _MODE_1080P24:
	case _MODE_1080P25:
	case _MODE_1080P29:
	case _MODE_1080P30:
	default: /* other HD timing */
		abl_window_reg.abl_vend = YPBPR_ABL_1080P_V_END;
		abl_window_reg.abl_wait_line = YPBPR_ABL_HD_WAIT_LINE;
		abl_window_reg.abl_vsta = YPBPR_ABL_HD_V_START;
		abl_window_reg.abl_line = YPBPR_ABL_HD_LINE_AVG;
		abl_window_reg.abl_h_width = YPBPR_ABL_HD_H_WIDTH;
		abl_window_reg.abl_start_pos = YPBPR_ABL_HD_H_START;

		IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	break;
	}

	abl_mgn_rg_reg.regValue = 0;
	abl_mgn_rg_reg.abl_eq_mgn_red = YPBPR_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_rg_reg.abl_l_mgn_red = 0x8;
	abl_mgn_rg_reg.abl_lock_mgn_red = YPBPR_ABL_LOCK_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_grn = YPBPR_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_rg_reg.abl_l_mgn_grn = YPBPR_ABL_Y_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_grn = YPBPR_ABL_LOCK_MARGIN;

	IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);


	abl_mgn_b_reg.regValue = 0;
	abl_mgn_b_reg.abl_eq_mgn_blu = YPBPR_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_b_reg.abl_l_mgn_blu = 0x8;
	abl_mgn_b_reg.abl_lock_mgn_blu = YPBPR_ABL_LOCK_MARGIN;

	IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);

	abl_ctrl_reg.regValue = 0;
	abl_ctrl_reg.abl_en = _ENABLE;
	abl_ctrl_reg.abl_red_en = _ENABLE;
	abl_ctrl_reg.abl_grn_en = _ENABLE;
	abl_ctrl_reg.abl_blu_en = _ENABLE;
	abl_ctrl_reg.abl_software_mode = 0;
	abl_ctrl_reg.abl_min_measure = 0;
	abl_ctrl_reg.abl_ypbpr_en = 1;
	abl_ctrl_reg.abl_online_mode = 1;
	abl_ctrl_reg.abl_max_frame = 0;



	abl_ctrl_reg.abl_r_dir_inv = 1;	/* 000: RGB all nodes are separate, ABL will adjust negative node dac voltage */
	abl_ctrl_reg.abl_g_dir_inv = 0;	/* 000: RGB all nodes are separate, ABL will adjust negative node dac voltage */
	abl_ctrl_reg.abl_b_dir_inv = 1;	/* 000: RGB all nodes are separate, ABL will adjust negative node dac voltage */


	abl_ctrl_reg.abl_href_sel = 0;
	abl_ctrl_reg.abl_target_value = _ABL_YPP_TARGET_VALUE;
	IoReg_Write32(ABL_ABL_CTRL_reg, abl_ctrl_reg.regValue);

	abl_status_reg.regValue = IoReg_Read32(ABL_ABL_STATUS_reg);
	abl_status_reg.abl_red_equal = 0x1;
	abl_status_reg.abl_grn_equal = 0x1;
	abl_status_reg.abl_blu_equal = 0x1;
	IoReg_Write32(ABL_ABL_STATUS_reg, abl_status_reg.regValue);
	abl_status_reg.regValue = IoReg_Read32(ABL_ABL_STATUS_reg);
	abl_status_reg.abl_red_equal = 0;
	abl_status_reg.abl_grn_equal = 0;
	abl_status_reg.abl_blu_equal = 0;
	IoReg_Write32(ABL_ABL_STATUS_reg, abl_status_reg.regValue);

}

/* set ABL margin setting at later, let picture more stable */
void YPbPr_ABL_Margin_Setting(void)
{
	abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
	abl_abl_mgn_b_RBUS abl_mgn_b_reg;
	abl_mgn_rg_reg.regValue = IoReg_Read32(ABL_ABL_MGN_RG_reg);
	abl_mgn_rg_reg.abl_eq_mgn_red = YPBPR_ABL_UV_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_l_mgn_red = YPBPR_ABL_UV_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_red = YPBPR_ABL_LOCK_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_grn = YPBPR_ABL_Y_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_l_mgn_grn = YPBPR_ABL_Y_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_grn = YPBPR_ABL_LOCK_MARGIN;
	IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);

	abl_mgn_b_reg.regValue = IoReg_Read32(ABL_ABL_MGN_B_reg);
	abl_mgn_b_reg.abl_eq_mgn_blu = YPBPR_ABL_UV_EQUAL_MARGIN;
	abl_mgn_b_reg.abl_l_mgn_blu = YPBPR_ABL_UV_LARGE_MARGIN;
	abl_mgn_b_reg.abl_lock_mgn_blu = YPBPR_ABL_LOCK_MARGIN;
	IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);
}

#if 0
void Print_DAC_result(void)
{
	int i;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "[YPbPr]: Content of DAC calibration result:\n");
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "unsigned char dac_result[%d]={\n", AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX);
	for (i = 10; i >= 0; i--) {
		/* printk(KERN_DEBUG "0x%02x,",DAC_result[i]); */
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "%3d,", DAC_result[i]);
	}
	for (i = 0; i <= 63; i++) {
		/* printk(KERN_DEBUG "0x%02x,",DAC_result[i]); */
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "%3d,", DAC_result[i]);
		if (i == AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX) {
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, KERN_DEBUG "\b};\n\n");
			break;
		}
		if ((i % 16) == 15) {
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, KERN_DEBUG "\n");
		}
	}
	for (i = 0; i <= 63; i++) {
		/* printk(KERN_DEBUG "0x%02x,",DAC_result[i]); */
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "%3d,", DAC_result[AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX-i]);
		if (i == AUTO_SOY_CALIBRATION_INPUT_LEVEL_MAX) {
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "\b};\n\n");
			break;
		}
		if ((i%16) == 15) {
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC,  "\n");
		}
	}
	return;
}
#endif

unsigned int Select_CurAdcValue(unsigned int val1, unsigned int val2, unsigned int val3)
{
#if 1	//improved algorithm, rzhen@2017-01-06
	unsigned int max;
	unsigned int min;

	max = val1 >= val2 ? val1 : val2;
	max = max >= val3? max: val3;
	min = val1 <= val2 ? val1 : val2;
	min = min <= val3? min: val3;
	return (val1+val2+val3-max-min);
#else
	/* printk(KERN_DEBUG "Input: %d %d %d\n",val1,val2,val3); */
	if ((val1 >= val2) && (val2 >= val3)) {
		return val2;
	} else if ((val3 >= val2) && (val2 >= val1)) {
		return val2;
	} else if ((val1 >= val3) && (val3 >= val2)) {
		return val3;
	} else if ((val2 >= val3) && (val3 >= val1)) {
		return val3;
	} else if ((val3 >= val1) && (val1 >= val2)) {
		return val1;
	} else if ((val2 >= val1) && (val1 >= val3)) {
		return val1;
	} else {
		rtd_printk(KERN_INFO, TAG_NAME_ADC,  "##### %s:%s(%d) #####\n", __FILE__, __func__, __LINE__);
		return 0;
	}
#endif
}


unsigned char YPbPr_Check_DDS_Status(void)
{//Check DDS status. FALSE: signal not stable. TRUE: signal stable.
	dds_pll_dds_status_RBUS dds_status_reg;
	dds_status_reg.regValue = IoReg_Read32(DDS_PLL_DDS_status_reg);
	return ((dds_status_reg.adc_no_lock_st == 1) && (dds_status_reg.adc_nolock_wd_en == 1)) ? FALSE : TRUE;
}

unsigned char YPbPr_Small_Signal_precheck(void)
{//True : small signal. False : not small signal
//	StructDisplayInfo *p_dispinfo;
//	unsigned char result;
//	soych0_a4_RBUS autosoy_soych0_a4_reg;
	return TRUE;//Means that no need DDS checking
#if 0 //No need currently
	p_dispinfo = Get_ADC_Dispinfo();
	switch (p_dispinfo->ucMode_Curr) {
	case _MODE_480I:/* SD timing */
	case _MODE_480P:
	case _MODE_576I:
	case _MODE_576P:

	case _MODE_720P50: /* HD timing */
	case _MODE_720P60:
	case _MODE_1080I25:
	case _MODE_1080I30:
	case _MODE_1080P50:
	case _MODE_1080P60:
	case _MODE_1080P23:
	case _MODE_1080P24:
	case _MODE_1080P25:
	case _MODE_1080P29:
	case _MODE_1080P30:
	break;

	default:
		return TRUE;  /* This means that HD does not need DDS checking */
	break;
	}

	autosoy_soych0_a4_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A4_reg);
	result = autosoy_soych0_a4_reg.max_r - autosoy_soych0_a4_reg.min_r;
	if (result < 25) {
		return TRUE;
	}
	return FALSE;
#endif
}

unsigned char YPbPr_Small_Signal_Check(void)
{//True : Need DDS checking. False : already disable DDS check
	dds_pll_dds_status_RBUS dds_status_reg;
	//auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	auto_soy_soych0_a4_RBUS autosoy_soych0_a4_reg;
	unsigned char result;
	dds_status_reg.regValue = IoReg_Read32(DDS_PLL_DDS_status_reg);
	if(dds_status_reg.adc_nolock_wd_en == 0 && dds_status_reg.adc_nolock_int_en == 0) {
		return FALSE;
	}
	autosoy_soych0_a4_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A4_reg);
	result = autosoy_soych0_a4_reg.max_r - autosoy_soych0_a4_reg.min_r;
	if (result < 25) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "########Small_signal Disable DDS check########\r\n");
		dds_status_reg.regValue = IoReg_Read32(DDS_PLL_DDS_status_reg);
		dds_status_reg.wd_to_main = _DISABLE;
		dds_status_reg.wd_to_sub = _DISABLE;
		dds_status_reg.adc_nolock_wd_en = _DISABLE;
		dds_status_reg.adc_nolock_int_en = _DISABLE;
		dds_status_reg.adc_no_lock_st = 1;		//write clear error status
		IoReg_Write32(DDS_PLL_DDS_status_reg, dds_status_reg.regValue);

		//autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
		//autosoy_soych0_a3_reg.reg_dc_out_offset = 0;
		//IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
	}
	return TRUE;
}

unsigned char auto_phase_flow_bypass(void)
{//If true, means no need auto phase flow again. Somecase need to run scaler flow no need to run auto phase
	return bypass_auto_phase_flow;
}

void set_auto_phase_flow_bypass_flag(unsigned char flag)
{
	bypass_auto_phase_flow = flag;
}

unsigned char check_macrovision(unsigned int timing)
{
	sync_processor_sp1_clmpmsk_RBUS  sync_processor_sp1_clmpmsk_reg;
	sync_processor_mv_ctrl_RBUS mv_ctrl_reg;
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	auto_soy_soych0_a3_RBUS autosoy_soych0_a3_reg;
	mv_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_Mv_CTRL_reg);
	mv_ctrl_reg.s1_mv_enable = 1;//enable macrovision
	IoReg_Write32(SYNC_PROCESSOR_Mv_CTRL_reg,  mv_ctrl_reg.regValue);

	msleep(10);

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "mv_ctrl_reg.s1_mv_occur = %d\n", mv_ctrl_reg.s1_mv_occur);
	
	mv_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_Mv_CTRL_reg);
	if(mv_ctrl_reg.s1_mv_occur){
		
		if(timing == _MODE_576I){
			sync_processor_sp1_clmpmsk_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CLMPMSK_reg);//Q7511 patch
			sync_processor_sp1_clmpmsk_reg.s1_mask_clamp_en = _ENABLE;
			sync_processor_sp1_clmpmsk_reg.s1_mask_front = 0x8;//Q7511 patch modify the mask
			sync_processor_sp1_clmpmsk_reg.s1_mask_back = 0x18;//Q7511 patch
			IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, sync_processor_sp1_clmpmsk_reg.regValue);
			autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			autosoy_soych0_a3_reg.reg_dc_out_offset = 0;//modify 0 for macrovision 576i
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
		}else{
			autosoy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
			autosoy_soych0_a3_reg.reg_dc_out_mode = 0;//modify 0 for macrovision 480i
			IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, autosoy_soych0_a3_reg.regValue);
			autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
			autosoy_soych0_a0_reg.reg_ma_mode = 3;
			IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);
		}
		
		return TRUE;//macrovision case
	}
	return FALSE;
}
