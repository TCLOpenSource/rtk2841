/* Kernel Header file */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/semaphore.h>

/* RBUS Header file */
//#include <rbus/crt_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/adc_reg.h>
#include <rbus/adc_smartfit_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/sync_processor_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/stb_reg.h>
#include <scalercommon/scalerCommon.h>

/* Tvscalercontrol Header file */
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/adcsource/adcctrl.h>
#include <tvscalercontrol/adcsource/ypbpr.h>
#include <tvscalercontrol/adcsource/vga.h>
#include "tvscalercontrol/scalerdrv/inprocvga.h"
#include <tvscalercontrol/pcbsource/pcbSource.h>
#include <tvscalercontrol/vip/ypbpr_auto.h>
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
#include <tvscalercontrol/scalerdrv/auto.h>/* For ADC calibration temp add*/
#include <rtk_kdriver/rtk_crt.h>
#include <mach/rtk_log.h>
#define TAG_NAME_ADC "ADC"

/*=================== Hardware semaphore =============== */
/*
#define SB2_HD_SEM_NEW_5_reg 0xB801A634

extern char moduleName[32];

#define SB2_HD_SEM_NEW_5_reg 0xB801A634
#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){printk("#@# %s wait SB2_HD_SEM_NEW_5_reg ready\n", moduleName); msleep(20);}
#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);

//#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){;}


#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);
*/


/* #define ADCCTRL_SHOW_COSTTIME //To show ADC API cost time */

#ifndef _ENABLE
#define _ENABLE			1
#endif

#ifndef _DISABLE
#define _DISABLE		0
#endif

#ifndef ON
#define ON				1
#endif

#ifndef OFF
#define OFF				0
#endif

extern unsigned char vga_good_timing_ready;

static StructDisplayInfo ADC_dispinfo;
static ModeInformationType ADC_timinginfo;

static unsigned short ADC_PhaseValue;
static unsigned int *ADC_Register_Backup;

void ADC_Initial(void)
{
#ifdef ADCCTRL_SHOW_COSTTIME
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif

	memset(&ADC_dispinfo, 0, sizeof(StructDisplayInfo));
	memset(&ADC_timinginfo, 0, sizeof(ModeInformationType));
	ADC_PhaseValue = 0;

#ifdef ADCCTRL_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\r\n#####func:%s code time=%d ms######\r\n", __FUNCTION__, (after_time-before_time));
#endif

}


void ADC_Open(void)
{/* Do ADC initial setting */
#ifdef NEED_SELFAWB
	static unsigned char calibration_done = FALSE;
#endif
#ifdef ADCCTRL_SHOW_COSTTIME
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif
#ifdef NEED_SELFAWB
	if (calibration_done == FALSE) {
		Internal_ADC_Calibration_proc (_SRC_YPBPR);
		calibration_done = TRUE;
	}
#endif
	ADC_CRT_Setting(_ENABLE);/* Will add. Enable ADC CRT */
	ADC_Power_Control(ON); /* ADC,APLL power should be turn on at init   ADC RGB power off for save power */
	ADC_Initial_Setting();
	ADC_ABL_Setting_Off();
	/* DO SOY Calibration */
#ifdef AutoSOY_Calibration_Fast_Flow /* If define run soy calibration fast flow */
	YPbPr_AutoSOY_Calibration_Fast();
#else
	YPbPr_AutoSOY_Calibration();
#endif

#ifdef ADCCTRL_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\r\n#####func:%s code time=%d ms######\r\n", __FUNCTION__, (after_time-before_time));
#endif

}

void ADC_Close(void)
{/* Do ADC close setting */
#ifdef ADCCTRL_SHOW_COSTTIME
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif

	YPbPr_ADCPowerControl(OFF);
	SyncProcessFunctionPowerDown(_SRC_YPBPR);

#ifdef ADCCTRL_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\r\n#####func:%s code time=%d ms######\r\n", __FUNCTION__, (after_time-before_time));
#endif

}

unsigned char ADC_Connect(int srcType, unsigned short srcinput)
{
	StructSourceInput *srcinput_pt;
	unsigned char i = 0, size;

#ifdef ADCCTRL_SHOW_COSTTIME
	unsigned int before_time = 0;
	unsigned int after_time = 0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif
	srcinput_pt = PcbSource_GetTable();
	size = PcbSource_GetTableSize();
	for (i = 0; i < size; i++) {
		if (srcinput_pt->src_index == srcinput) {
			break;
		}
		srcinput_pt++;
	}

	if (i == size) {
		return false;
	}
	ADC_dispinfo.input_src = i;
	ADC_dispinfo.data_array_index = i;
	ADC_dispinfo.osd_input_src = i;

	if (srcType == _SRC_YPBPR) {
		YPbPr_SetInput(srcinput_pt);
		YPbPr_Connect_Setting();
	} else if (srcType == _SRC_VGA) {
		vga_good_timing_ready = FALSE;
		VGA_SetInput(srcinput_pt);
		VGA_Connect_Setting();

	} else if (srcType == _SRC_SCART_RGB) {

	}
#ifdef ADCCTRL_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\r\n#####func:%s code time=%d ms######\r\n", __FUNCTION__, (after_time-before_time));
#endif

	return true;
}



StructDisplayInfo *Get_ADC_Dispinfo(void)
{
	return &ADC_dispinfo;
}

ModeInformationType *Get_ADC_Timinginfo(void)
{
	return &ADC_timinginfo;
}

void ADC_ABL_Setting_Off(void)
{
	abl_abl_ctrl_RBUS abl_abl_ctrl_reg;
	abl_abl_ctrl_reg.regValue = IoReg_Read32(ABL_ABL_CTRL_reg);
	abl_abl_ctrl_reg.abl_en = 0;
	abl_abl_ctrl_reg.abl_red_en = 0;
	abl_abl_ctrl_reg.abl_grn_en = 0;
	abl_abl_ctrl_reg.abl_blu_en = 0;
	IoReg_Write32(ABL_ABL_CTRL_reg, abl_abl_ctrl_reg.regValue);
}

void ADC_CRT_Setting(unsigned char enable)
{
	enum CRT_CLK clken;
	if(!enable) 
		return;//Does not disable CRT
	clken = enable ? CLK_ON : CLK_OFF;
	CRT_CLK_OnOff(SCALER_ADC_CLK_1, clken, NULL );
}


void ADC_Power_Control(unsigned char on_off)
{
//	adc_power_RBUS adc_adc_power_reg;
	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[TV]: %s:%s(%d) ST\n", __FILE__, __func__, __LINE__);
	if (on_off) {
		/* APLL LDO power on, PLL Power Down */
		dds_pll_pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		dds_pll_pll_ctrl_reg.pllpwdn = 1;		/* PLL power down */
		dds_pll_pll_ctrl_reg.apllldosel = 1;	/* LDO 1.05V */
		dds_pll_pll_ctrl_reg.apll_reg = 1;   	/* LDO 1.68V */
		dds_pll_pll_ctrl_reg.hs_dds2synp_sel = 0;/* hs latch falling edge */
		dds_pll_pll_ctrl_reg.apllldopow = 1;	/* LDO power on */
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);

		/* ADC Power */
		down(get_adc_power_semaphore());
		#if 1
		drvif_adc_power_control(ADC_POWER_YPP_ONLY_DETECT_CONTROL);
		#else
		drvif_adc_power_control(ADC_POWER_VGA_ONLY_DETECT_CONTROL);
		#endif
		up(get_adc_power_semaphore());

	} else {
		/* APLL LDO power on, PLL Power Down */
		dds_pll_pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		dds_pll_pll_ctrl_reg.pllpwdn = 1;		/* PLL power down */
		dds_pll_pll_ctrl_reg.apllldosel = 1;	/* LDO 1V */
		dds_pll_pll_ctrl_reg.apll_reg = 1;   	/* LDO 2V */
		dds_pll_pll_ctrl_reg.hs_dds2synp_sel = 0;/* hs latch falling edge */
		dds_pll_pll_ctrl_reg.apllldopow = 0; /* LDO power down */
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);

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

void ADC_Disable_AHS_SMT_Power(void)
{
	adc_ahs_smt_ctrl_RBUS ahs_smt_ctrl_reg;
	/*0xB8020064 bit7=0 bit9=1 power saving. Only VGA need to set*/
	ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
	ahs_smt_ctrl_reg.hsync0_pwdn = 1; /* HSYNC Power Down */
	ahs_smt_ctrl_reg.hsync0_3ven = 0; /* 0: Power down */
	IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
}

void ADC_Initial_Setting(void)
{
	sync_processor_sp_adc_out_sel_RBUS  sync_processor_sp_adc_out_sel_reg;
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_clock_RBUS adc_adc_clock_reg;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	adc_adc_test_RBUS adc_adc_test_reg;
	adc_ahs_smt_ctrl_RBUS ahs_smt_ctrl_reg;
	adc_smartfit_adc_auto_field_RBUS adc_smartfit_adc_auto_field_reg;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;
	dds_pll_plldiv_RBUS dds_pll_plldiv_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_dds_mix_w2_RBUS dds_pll_dds_mix_w2_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	dds_pll_pll_phase_interpolation_RBUS dds_pll_pll_phase_interpolation_reg;
	dds_pll_i_code_RBUS dds_pll_i_code_reg;
	dds_pll_p_code_RBUS dds_pll_p_code_reg;
	vgip_vgip_chn1_delay_RBUS vgip_vgip_chn1_delay_reg;

	unsigned short apll_clk = 0;

	sync_processor_sp_adc_out_sel_reg.regValue = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg, sync_processor_sp_adc_out_sel_reg.regValue); /* Source select of SyncProc output => ADC Mod */

	/* ADC intinal Clamp DAC source select */
	adc_adc_ctl_1_reg.regValue = 0;
	adc_adc_ctl_1_reg.adc_ctl_grn_2_0 = 0;/* 3b DAC clamp voltage for green channel Voffset 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_grn_5_3 = 3;/* 3b DAC clamp voltage for green channel Vmid 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_grn_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_grn_10_9 = 0;
	adc_adc_ctl_1_reg.adc_ctl_red_2_0 = 0;/* 3b DAC clamp voltage for red channel Voffset 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_red_5_3 = 3;/* 3b DAC clamp voltage for red channel Vmid 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_red_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_red_10_9 = 0;
	IoReg_Write32(ADC_ADC_CTL_1_reg, adc_adc_ctl_1_reg.regValue);


	adc_adc_ctl_2_reg.regValue = 0;
	adc_adc_ctl_2_reg.adc_ctl_blu_2_0 = 0;
	adc_adc_ctl_2_reg.adc_ctl_blu_5_3 = 3;
	adc_adc_ctl_2_reg.adc_ctl_blu_8_6 = 3;
	adc_adc_ctl_2_reg.adc_ctl_blu_10_9 = 0;
	/* 3b DAC clamp voltage for blue channel Voffset 0.4v */
	/* 3b DAC clamp voltage for blue channel Vmid 0.4v */

	IoReg_Write32(ADC_ADC_CTL_2_reg, adc_adc_ctl_2_reg.regValue);


	adc_adc_offset0_reg.regValue = 0;
	adc_adc_offset0_reg.adc_off_grn = 512;/* Green Channel Offset Adjust 0~0.8V Setting is 0.4V */
	adc_adc_offset0_reg.adc_off_red = 512;/* Red Channel Offset Adjust 0~0.8V Setting is 0.4V */
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_adc_offset0_reg.regValue);


	adc_adc_offset1_reg.regValue = 0;
	adc_adc_offset1_reg.adc_off_blu = 512;/* Blue Channel Offset Adjust 0~0.8V Setting is 0.4V */
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_adc_offset1_reg.regValue);

	/* ADC Negative common current mode on Gchannel setting */
	adc_adc_ctl_rgb12_reg.regValue = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 0; /* G_Share*/
								    			/* B IB_share form G (Voffset Swap to positive) */
												/* R IB_share from G (Voffset swap to positive) */
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_6 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_7 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_8 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_9 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_11_10 = 1;
	IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);


	/* SOG CMP bias current Max */
	adc_adc_clamp_ctrl3_reg.regValue = 0;
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_15 = 0; /* SOG1 DCrestore enable(0:disable,1:enable)*/
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_14_13 = 3;/* SOG_ADC_CMP bias current 11: 100uA */
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 0; /* SOG1 IB selection(0:POR_BG,1:ADC_BG */
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_9_7 = 1; /* BIT [8:7]:SOG_ADC VREF select (00:600mv 01:640mv 10:680mv 11:720mv) */
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_3 = 0; /* SOG0_ADC output clock polarity(0:negative 1:postive) */
	IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);


	/* PLL_Phase_INTERPLOATION */
	dds_pll_pll_phase_interpolation_reg.regValue = 0;
	dds_pll_pll_phase_interpolation_reg.pllsphrl = 1;/* default 8k below 25M */
	dds_pll_pll_phase_interpolation_reg.pllsphrs = 5;/* default */
	IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg, dds_pll_pll_phase_interpolation_reg.regValue);

	/* APLL intinal setting */
	/* PLL_SET */
	dds_pll_pll_set_reg.regValue = 0;
	dds_pll_pll_set_reg.pll_m = 3;/* [To DDS] PLLM [7:0] (PLL DPM value - 3) */
	dds_pll_pll_set_reg.pll_n = 1;/* REG_PLLSN in APLL (PLL DPN value - 2) */
	dds_pll_pll_set_reg.pllssi = 3;/* PLL Charger Pump Current IchDpll */
	dds_pll_pll_set_reg.pllscp = 1;
	dds_pll_pll_set_reg.pllscs = 3;
	dds_pll_pll_set_reg.pllsrs = 2;/* default 10k */
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);

	dds_pll_pll_ctrl_reg.regValue = 0;
	dds_pll_pll_ctrl_reg.pllpwdn = 1;/* REG_APLLPWDN (PLL Power Down) 1: Power Down */
	dds_pll_pll_ctrl_reg.hs_dds2synp_sel = 0;/* HS_dds2synp latch edge 0: ADC Clock falling edge */
	dds_pll_pll_ctrl_reg.apll_reg = 1;/* REG_APLL_REG<1:0> V16 setting 01:1.68V (default) */
	dds_pll_pll_ctrl_reg.pllswdrst = 0;/* REG_PLLSWDRST (PLL WD Reset) 0: Normal 1: Reset */
	dds_pll_pll_ctrl_reg.adckmode = 3;/* ADCKMODE [1:0] (ADC Input Clock Select Mode) 11: Dual Clock Mode (1x and 2x Clock) */
	dds_pll_pll_ctrl_reg.apllldosel = 1;/* LDO reference voltage setting  01:1.1V(default); */
	dds_pll_pll_ctrl_reg.apllldopow = 0;/* LDO Power 1:Power on */
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	dds_pll_pll_ctrl_reg.pllpwdn = 0;/* REG_APLLPWDN (PLL Power Down) 0: Normal Run */
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);


	dds_pll_plldiv_reg.regValue = 0;
	dds_pll_plldiv_reg.apll_reserve = 1; /* default thermal delay ypp 0x3 */
	dds_pll_plldiv_reg.pll_divider = 857;/* Divider=857 = 0x359 */
	IoReg_Write32(DDS_PLL_PLLDIV_reg, dds_pll_plldiv_reg.regValue);

	// ADC_AUTO_FIELD rzhen@2016-06-28
	adc_smartfit_adc_auto_field_reg.regValue = 0;
	adc_smartfit_adc_auto_field_reg.adj_source = 0;//pll_setting mux. 0: from ADC smfit. 1: from I domain smfit.
 	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, adc_smartfit_adc_auto_field_reg.regValue);

	// ADC_PLLPHSE_CTRL rzhen@2016-06-24
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = 1;//MSB of 128 phase (Only for ADC CLK=1/4 VCO CLK)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2x = 1;//[To Smart Fit] PLLX (PLL X Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2y = 1;//[To Smart Fit] PLLY (PLL Y Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 1;//[To Smart Fit] PLLD2 1:ADC CLK=1/4 VCO CLK
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut =1;//Phase_Select_Method 1: Look-Up-Table
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, dds_pll_pllphase_ctrl_reg.regValue);

	dds_pll_pllphase_ctrl_reg.regValue = 0;
	dds_pll_pllphase_ctrl_reg.pllsph0path = 1;/* Long Path */
 	IoReg_Write32(DDS_PLL_PLLPHASE_CTRL_reg, dds_pll_pllphase_ctrl_reg.regValue);

	dds_pll_dds_mix_w1_reg.regValue = 0;
	dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*disable new mode tracking*/
	dds_pll_dds_mix_w1_reg.new_mode_en_th = 1;/* New mode enable threshold 011: 171 */
	dds_pll_dds_mix_w1_reg.new_mode_lock_th = 3;/* New mode lock threshold=> while Q (PE) keep smaller than threshold for 32 HS 011: 11 */
	dds_pll_dds_mix_w1_reg.p_code_max = 2471;/* Set p_code_max value to clamp the GAIN of APLL 2471 = 0x9a7 */
	dds_pll_dds_mix_w1_reg.lock_th = 6;/* Judge threshold lock already => while Q (PE) keep smaller than threshold for 32 HS 011: 11 */
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);/* P code max=316321 and new mode disable */


	dds_pll_dds_mix_w2_reg.regValue = 0;
	dds_pll_dds_mix_w2_reg.sample_period = 2;/* Phase error sample period choose 10: every 3 cycle sample */
	dds_pll_dds_mix_w2_reg.delay_chain_length = 2;/* Delay chain length select  10: cnt= 33 => 209.9ns (default) */
	dds_pll_dds_mix_w2_reg.change_mode_th = 2;/* To judge when to increase a counter for pll_lock judgement 3'b010: change_mode_final = 12'd1571 */
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, dds_pll_dds_mix_w2_reg.regValue);


	/* MSB delay turn on */
	adc_adc_vbias_reg.regValue = 0;
	adc_adc_vbias_reg.adc_vbias0_0 = 1;/*ADC Sample 011 */
									   /* LDO voltage select 011:1.1v bit[7:5]=101 bit[4:2]=010 bit0=1*/
	adc_adc_vbias_reg.adc_vbias0_1 = 0;
	adc_adc_vbias_reg.adc_vbias0_4_2 = 2;
	adc_adc_vbias_reg.adc_vbias0_7_5 = 5;

	adc_adc_vbias_reg.adc_vbias1_3_2 = 0x3;//BIT[3:2]SF driving, 0:840uA,1:960uA,2:1080uA,3:1200uA
	adc_adc_vbias_reg.adc_vbias1_6 = 1;
	adc_adc_vbias_reg.adc_vbias1_7 = 1;
	adc_adc_vbias_reg.adc_vbias2_2_0 = 3;/* ADC Gain Calibration Gain_Cal_DAC3B Voltage, 011:0.7V */
	adc_adc_vbias_reg.adc_vbias3_1_0 = 1;/* bandgap voltage select */

	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	dds_pll_pll_set_reg.regValue = IoReg_Read32(DDS_PLL_PLL_SET_reg);
	apll_clk = 27 * (dds_pll_pll_set_reg.pll_m + 3)/(dds_pll_pll_set_reg.pll_n + 2);
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	apll_clk = adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 ? apll_clk>>2 : apll_clk>>1;

	/* SOY ADC clock select */
	adc_adc_clock_reg.regValue = 0;
	adc_adc_clock_reg.adc_clock_1_0 = 3;/* Duty cycle 11: 52% */
	adc_adc_clock_reg.adc_2x_sample_0 = 1;/* Online Auto SOY ADC clock select 1: CKAPLL<1:0> */
	adc_adc_clock_reg.adc_2x_sample_1 = (apll_clk < 75) ? 1 : 0; // clk < 75MHz, 2x
	adc_adc_clock_reg.adc_2x_sample_5 = 1;/* RGB 1X Output Clock (ADC_CLK_1X) Polarity  1:Positive */
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);


	/* ADC clock 1x,2x,invert, Swap ADC setting */
	adc_adc_clkgen_rgb_capture_reg.regValue = 0;
	adc_adc_clkgen_rgb_capture_reg.hs_err_judge_en = _DISABLE;
	adc_adc_clkgen_rgb_capture_reg.adc_swap = 0;
	adc_adc_clkgen_rgb_capture_reg.vbi_clk_inv = 0;
	adc_adc_clkgen_rgb_capture_reg.adc_clkx2_inv = 0;
	adc_adc_clkgen_rgb_capture_reg.adc_clk_inv = YPBPR_ADC_CLK_INV;
	adc_adc_clkgen_rgb_capture_reg.soy0_clk_inv = 0;
	adc_adc_clkgen_rgb_capture_reg.vbi_clk_en = 1;
	adc_adc_clkgen_rgb_capture_reg.adc_clkx2_en = 1;
	adc_adc_clkgen_rgb_capture_reg.soy0_clk_en = 1;
	adc_adc_clkgen_rgb_capture_reg.vbi_clkx2_sel = 1;
	adc_adc_clkgen_rgb_capture_reg.adc_clk_inv_en = 0;
	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_adc_clkgen_rgb_capture_reg.regValue);

	/* Differential */
	adc_adc_dcrestore_ctrl_reg.regValue = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = 9;/* IB_5k, tie0.67V, connectPad, Diff_Input, LPF_400M */
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);


	vgip_vgip_chn1_delay_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_DELAY_reg);
	vgip_vgip_chn1_delay_reg.ch1_hs_width = 2;/* CH1_hs_width	31:30 need to be 10 */
	IoReg_Write32(VGIP_VGIP_CHN1_DELAY_reg, vgip_vgip_chn1_delay_reg.regValue);

	adc_adc_clamp_ctrl1_reg.regValue = 0; ;
#ifdef ADC_UP_DOWN_CLAMP
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_7 = 0; //current gain sel(0:x1, 1:x2)
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_6 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_5 = 0;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_4_0 = 0xf;
#else
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_6 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_5 = 0;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl4_4_0 = 16;
#endif
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

#ifdef ADC_UP_DOWN_CLAMP
	adc_adc_test_reg.regValue = 0;
	adc_adc_test_reg.adc_test_2 = 1; //up/dn source selcet from(0:VDC 1:YPP)
	IoReg_Write32(ADC_ADC_TEST_reg, adc_adc_test_reg.regValue);
#endif

	dds_pll_i_code_reg.regValue = 0;
	dds_pll_i_code_reg.i_code = 0xd;
	IoReg_Write32(DDS_PLL_I_CODE_reg, dds_pll_i_code_reg.regValue);

	dds_pll_p_code_reg.regValue = 0;
	dds_pll_p_code_reg.p_code = 0x60;
	IoReg_Write32(DDS_PLL_P_CODE_reg, dds_pll_p_code_reg.regValue);

	/*0xB8020064 bit7=0 bit9=1 power saving. Only VGA need to set*/
	ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
	ahs_smt_ctrl_reg.hsync0_pwdn = 1; /* HSYNC Power Down */
	ahs_smt_ctrl_reg.hsync0_3ven = 0; /* 0: Power down */
	IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
}

void ADC_OnlineMeasureError_Handler(int srcType)
{
	extern unsigned char YPbPr_TimingDetectStage;
	extern unsigned char VGA_TimingDetectStage;
	memset(&ADC_dispinfo, 0, sizeof(StructDisplayInfo));
	memset(&ADC_timinginfo, 0, sizeof(ModeInformationType));
	ADC_PhaseValue = 0;
	switch (srcType) {
	case _SRC_YPBPR:
		YPbPr_Power_ADCRGB(FALSE);/* Turn off RGB for saving power on detecting.  brandon add */
		YPbPr_TimingDetectStage = YPBPR_SOY_STATE;
		ADC_dispinfo.ucMode_Table_Index = Mode_Table_Init_Index;
		break;

	case _SRC_VGA:
		down(get_adc_power_semaphore());
		drvif_adc_power_control(ADC_POWER_VGA_ONLY_DETECT_CONTROL);
		up(get_adc_power_semaphore());
		VGA_TimingDetectStage = VGA_HVSYNC_STATE;
		ADC_dispinfo.ucMode_Table_Index = Mode_Table_Init_Index;
		break;

	case _SRC_SCART_RGB:
		break;

	default:
		break;
	}
}

void ADC_Reset_TimingInfo(void)
{
	extern unsigned char YPbPr_TimingDetectStage;
	extern unsigned char VGA_TimingDetectStage;
	memset(&ADC_dispinfo, 0, sizeof(StructDisplayInfo));
	memset(&ADC_timinginfo, 0, sizeof(ModeInformationType));
	ADC_PhaseValue = 0;
	YPbPr_Power_ADCRGB(FALSE);/* Turn off RGB for saving power on detecting.  brandon add */
	YPbPr_TimingDetectStage = YPBPR_SOY_STATE;
	VGA_TimingDetectStage = VGA_HVSYNC_STATE;
	ADC_dispinfo.ucMode_Table_Index = Mode_Table_Init_Index;
}

void ADC_VSC_Setting(int src)
{/* This API for VSC setting at beginning */
	if (src == _SRC_YPBPR) {
		YPbPr_Setup();
	} else if (src == _SRC_VGA) {
		VGA_Setup();
	} else if (src == _SRC_SCART_RGB) {

	}

}

unsigned short Get_ADC_PhaseValue(void)
{
	return ADC_PhaseValue;
}

void Set_ADC_PhaseValue(unsigned short phasevalue)
{
	ADC_PhaseValue = phasevalue;
}

void ADC_Set_GainOffset(ADCGainOffset *adcinfo)
{
	adc_adc_gain0_RBUS adc_adc_gain0_reg;
	adc_adc_gain1_RBUS adc_adc_gain1_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
	adc_adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
	adc_adc_gain0_reg.adc_gain_red = adcinfo->Gain_R;
	adc_adc_gain0_reg.adc_gain_grn = adcinfo->Gain_G;
	adc_adc_gain1_reg.adc_gain_blu = adcinfo->Gain_B;
	adc_adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	adc_adc_offset0_reg.adc_off_red = adcinfo->Offset_R;
	adc_adc_offset0_reg.adc_off_grn = adcinfo->Offset_G;
	adc_adc_offset1_reg.adc_off_blu = adcinfo->Offset_B;
	IoReg_Write32(ADC_ADC_GAIN0_reg, adc_adc_gain0_reg.regValue);
	IoReg_Write32(ADC_ADC_GAIN1_reg, adc_adc_gain1_reg.regValue);
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_adc_offset0_reg.regValue);
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_adc_offset1_reg.regValue);
}

void ADC_Get_GainOffset(ADCGainOffset *adcinfo)
{
	adc_adc_gain0_RBUS adc_adc_gain0_reg;
	adc_adc_gain1_RBUS adc_adc_gain1_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
	adc_adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
	adc_adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	adcinfo->Gain_R = adc_adc_gain0_reg.adc_gain_red;
	adcinfo->Gain_G = adc_adc_gain0_reg.adc_gain_grn;
	adcinfo->Gain_B = adc_adc_gain1_reg.adc_gain_blu;
	adcinfo->Offset_R = adc_adc_offset0_reg.adc_off_red;
	adcinfo->Offset_G = adc_adc_offset0_reg.adc_off_grn;
	adcinfo->Offset_B = adc_adc_offset1_reg.adc_off_blu;
}
#define REGISTER_START_ADC_1 (0xb8020000)
#define REGISTER_SIZE_ADC_1 (18)/* b8020000~b8020044 */

#define REGISTER_START_ADC_2 (0xb8020064)
#define REGISTER_SIZE_ADC_2 (2)/* b8020064~b8020068 */

#define REGISTER_START_ADC_3 (0xb8020080)
#define REGISTER_SIZE_ADC_3 (1)/* b8020080 */

#define REGISTER_TOTALSIZE_ADC (REGISTER_SIZE_ADC_1 + REGISTER_SIZE_ADC_2 + REGISTER_SIZE_ADC_3)

#define REGISTER_START_APLL_1 (0xb8020100)
#define REGISTER_SIZE_APLL_1 (17)/* b8020100~b8020140 */

#define REGISTER_TOTALSIZE_APLL (REGISTER_SIZE_APLL_1)

#define REGISTER_START_ABL_1 (0xb8020200)
#define REGISTER_SIZE_ABL_1 (10)/* b8020200~b8020224 */

#define REGISTER_TOTALSIZE_ABL (REGISTER_SIZE_ABL_1)

#define REGISTER_START_SOY_1 (0xb8020300)
#define REGISTER_SIZE_SOY_1 (25)/* b8020300~b8020360 */

#define REGISTER_TOTALSIZE_SOY (REGISTER_SIZE_SOY_1)

#define REGISTER_START_SYNCPROC_1 (0xb8021000)
#define REGISTER_SIZE_SYNCPROC_1 (3)/* b8021000~b8021008 */

#define REGISTER_START_SYNCPROC_2 (0xb8021010)
#define REGISTER_SIZE_SYNCPROC_2 (1)/* b8021010 */

#define REGISTER_START_SYNCPROC_3 (0xb8021028)
#define REGISTER_SIZE_SYNCPROC_3 (1)/* b8021028 */

#define REGISTER_START_SYNCPROC_4 (0xb8021030)
#define REGISTER_SIZE_SYNCPROC_4 (1)/* b8021030 */

#define REGISTER_START_SYNCPROC_5 (0xb8021038)
#define REGISTER_SIZE_SYNCPROC_5 (4)/* b8021038~b8021044 */

#define REGISTER_START_SYNCPROC_6 (0xb8021064)
#define REGISTER_SIZE_SYNCPROC_6 (3)/* b8021064~b802106c */

#define REGISTER_START_SYNCPROC_7 (0xb802107c)
#define REGISTER_SIZE_SYNCPROC_7 (14)/* b802107c~b80210b0 */


#define REGISTER_TOTALSIZE_SYNCPROC (\
REGISTER_SIZE_SYNCPROC_1 + REGISTER_SIZE_SYNCPROC_2 + REGISTER_SIZE_SYNCPROC_3 + \
REGISTER_SIZE_SYNCPROC_4 + REGISTER_SIZE_SYNCPROC_5 + REGISTER_SIZE_SYNCPROC_6 + \
REGISTER_SIZE_SYNCPROC_7)

#define REGISTER_START_VGIP_1 (0xb8022210)
#define REGISTER_SIZE_VGIP_1 (1)/* b8022210 */


#define REGISTER_START_VGIP_2 (0xb8022218)
#define REGISTER_SIZE_VGIP_2 (4)/* b8022218~b8022224 */

#define REGISTER_TOTALSIZE_VGIP (REGISTER_SIZE_VGIP_1 + REGISTER_SIZE_VGIP_2)

#define REGISTER_TOTALSIZE_FORADC ( \
REGISTER_TOTALSIZE_ADC + \
REGISTER_TOTALSIZE_APLL + \
REGISTER_TOTALSIZE_ABL + \
REGISTER_TOTALSIZE_SOY + \
REGISTER_TOTALSIZE_SYNCPROC + \
REGISTER_TOTALSIZE_VGIP)

#define	dvr_malloc(x)	kmalloc(x, GFP_KERNEL)
#define	dvr_free(x)	kfree(x)

unsigned char decide_adc_standby_mode(void)
{

	if((IoReg_Read32(0xb8060500) & (_BIT8 | _BIT9 | _BIT10 | _BIT11)) == _BIT8)//0xb8060500 == 1 means maybe vga standby mode
	{
		if(IoReg_Read32(0xb806052c) == 5)//0xb806052c == 5 means vga standby mode
		{
			printk(KERN_EMERG "\r\n#### func:%s enter vga standby mode####\r\n",__FUNCTION__);
			return TRUE;
		}
		else
			return FALSE;
	}
	else
	{
		return FALSE;
	}
}

void adc_standby_mode(unsigned char enable)
{
	adc_adc_clkgen_rgb_capture_RBUS adc_clkgen_rgb_capture_reg;
	adc_adc_ibias0123_RBUS adc_ibias0123_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
	adc_ahs_smt_ctrl_RBUS ahs_smt_ctrl_reg;

	if(enable)
	{		
		if(!(IoReg_Read32(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_apll_adc_mask) || !(IoReg_Read32(SYS_REG_SYS_SRST1_reg) & SYS_REG_SYS_SRST1_rstn_apll_adc_mask))
			ADC_CRT_Setting(_ENABLE);
		adc_ibias0123_reg.regValue = IoReg_Read32(ADC_ADC_IBIAS0123_reg);
		adc_ibias0123_reg.adc_ibias1_7 = 1; //0004[15]=1
		IoReg_Write32(ADC_ADC_IBIAS0123_reg, adc_ibias0123_reg.regValue);

		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_pwdn = 0; //0064[9]=0 power on
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);

		adc_adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
		adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_0 = 1; //0028[0]=1
		IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);

		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_pd_latch = 1; //0064[8]=1
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);

		adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
		adc_clkgen_rgb_capture_reg.st_latch_en = 1; //0080[3]=1
		IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_clkgen_rgb_capture_reg.regValue);

		//IoReg_Write32(STB_ST_SRST1_reg, STB_ST_SRST1_rstn_syncp_mask | STB_ST_SRST1_write_data_mask);//8051 will enable
		//IoReg_Write32(STB_ST_CLKEN1_reg, STB_ST_CLKEN1_clken_syncp_mask | STB_ST_CLKEN1_write_data_mask);//8051 will enable
		
	}
	else
	{
		//currently no need do anything
	}
}

#ifdef CONFIG_PM
void ADC_Suspend(void)
{
	int i = 0, index = 0;
	ADC_Register_Backup = (unsigned int *)dvr_malloc(sizeof(unsigned int) * (REGISTER_TOTALSIZE_FORADC));
	if (ADC_Register_Backup) {
		for (i = 0; i < REGISTER_SIZE_ADC_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_ADC_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_ADC_2; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_ADC_2 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_ADC_3; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_ADC_3 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_APLL_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_APLL_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_ABL_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_ABL_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SOY_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SOY_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_2; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_2 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_3; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_3 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_4; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_4 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_5; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_5 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_6; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_6 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_SYNCPROC_7; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_SYNCPROC_7 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_VGIP_1; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_VGIP_1 + (i<<2));
		}

		for (i = 0; i < REGISTER_SIZE_VGIP_2; i++) {
			ADC_Register_Backup[index++] = IoReg_Read32(REGISTER_START_VGIP_2 + (i<<2));
		}
	}
}

void ADC_Resume(void)
{
	int i = 0, index = 0;
	if (!ADC_Register_Backup) {
		return;
	}
	for (i = 0; i < REGISTER_SIZE_ADC_1; i++) {
		 IoReg_Write32(REGISTER_START_ADC_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_ADC_2; i++) {
		IoReg_Write32(REGISTER_START_ADC_2 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_ADC_3; i++) {
		IoReg_Write32(REGISTER_START_ADC_3 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_APLL_1; i++) {
		IoReg_Write32(REGISTER_START_APLL_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_ABL_1; i++) {
		IoReg_Write32(REGISTER_START_ABL_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SOY_1; i++) {
		IoReg_Write32(REGISTER_START_SOY_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_1; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_2; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_2 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_3; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_3 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_4; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_4 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_5; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_5 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_6; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_6 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_SYNCPROC_7; i++) {
		IoReg_Write32(REGISTER_START_SYNCPROC_7 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_VGIP_1; i++) {
		IoReg_Write32(REGISTER_START_VGIP_1 + (i<<2), ADC_Register_Backup[index++]);
	}

	for (i = 0; i < REGISTER_SIZE_VGIP_2; i++) {
		IoReg_Write32(REGISTER_START_VGIP_2 + (i<<2), ADC_Register_Backup[index++]);
	}

	dvr_free(ADC_Register_Backup);
	ADC_Register_Backup = NULL;
}
#endif

