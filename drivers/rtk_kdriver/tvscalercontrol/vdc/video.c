/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2017/09/12 17:00 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */

/*================ Module dependency  =============== */
#define __VIDEO_DRAGON__

/* linux lib */
#include <linux/compiler.h>		/* support unlikely() macro */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/freezer.h>
#include <linux/hardirq.h>
#include <rbus/vdtop_reg.h>
#include <rbus/vdpq_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/adc_reg.h>
#include <rbus/sb2_reg.h>
#include <mach/io.h>
#include <generated/autoconf.h>
#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/avd/avdctrl.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/vdc/video_table.h>
#include <tvscalercontrol/vdc/video_input.h>
#include <tvscalercontrol/vdc/video_factory.h>
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/scaler/scaleratv.h>
#include <tvscalercontrol/scaler/scalervideo.h>
#include <tvscalercontrol/frontend/ifd_new.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
#include <rbus/tv_sb1_ana_reg.h>
#include <rbus/vd_ifd_input_reg.h>
#include <rbus/vd_ifd_input_108_reg.h>
#ifdef CONFIG_SCART_ENABLE
#include <rbus/pinmux_lvdsphy_reg.h>
//#include <rbus/rbus_DesignSpec_MISC_LSADCReg.h>
#endif
#include <tvscalercontrol/vip/scalerColor.h>
#include <rtk_kdriver/rtk_crt.h>
#include <tvscalercontrol/scaler_vfedev.h>

#define VIDEO_LOG "VDC"
#include "video_log.h"
#include "video_debug.h"
#include "video_sb2dbg.h"

#define _SUCCESS		1
#define _FAIL			0
#define _ENABLE 		1
#define _DISABLE		0
#define _TRUE			1
#define _FALSE			0

#define HDTO_Default		0x20000000
#define CDTO_Def_NTSC		0x21f07c1f
#define CDTO_Def_PALM		0x21e6efa4
#define CDTO_Def_NTSC50		0x21f07c1f
#define CDTO_Def_PALN		0x21f69446
#define CDTO_Def_NTSC443	0x2a098acb
#define CDTO_Def_PAL60		0x2a098acb
#define CDTO_Def_PAL		0x2a098acb
#define CDTO_Def_SECAM		0x28a33bb2

#define usHstate_err_thl_AVsetting	0x060
#define usHstate_err_thl_Default	0x400
#define ucTV_NTSC_Ckill_thl	0x3a00	/* 20150814, for tuner TDJN-H203F */
#define ucTV_PAL_Ckill_thl	0x1800
#define ucAV_NTSC_Ckill_thl	0x2500
#define ucAV_PAL_Ckill_thl	0x3000


/*==================== Definitions ================ */
#define Rt_Delay(mSec)					msleep(mSec)

#define rtdf_outl(offset, val)					IoReg_Write32(offset,val)
#define rtdf_inl(offset)						IoReg_Read32(offset)
#define rtdf_maskl(offset, andMask, orMask)	IoReg_Mask32(offset,andMask,orMask)

VDC_MSG_LEVEL VDC_XDATA g_vdc_msg_level = (VDC_MSG_LEVEL)(VDC_MSG_INIT);
//#define VDC_weak_signal 1	/* weak signal for PAL / SECAM */
#define VDC_Error_case1 1	/* ATSC_081202_0925_337.00M_-37.18_20M_-32.77_LAN_FieldSignal(ch3)*/
#define VDC_Error_case2 0
#define VDC_Error_case3 1	/* over modulation issue */
#define VDC_Error_case4 1	/* ATSC_110225_0925_196.50M_-38.86_20M_-35.42_NON_FieldSignal(ch11)*/
#define VDC_Error_case5 1	/* sync reduction to 20% */
#define VDC_Error_case6 1	/* ATSC_081202_0925_337.00M_-37.18_20M_-32.77_LAN_FieldSignal(ch2)*/
#define VDC_Error_case7 1	/* ntsc_070615_1512_201 */
#define VDC_Error_case8 1	/* atsc_080922_1518_5790 */

#define AV_FastBlack	1

extern VFE_AVD_DEMOD_TYPE Scaler_AVD_GetDemodType(void);
extern unsigned char Scaler_AVD_GetAvdSource(void);
extern unsigned char g_ucVDMode;
/*==================== Variables ================== */
static unsigned char ucVdc_Curr_Mode = 0x00;
static unsigned char ucVdc_Pre_Mode = 0x11;

/*====================global  Variables ================== */
unsigned char vdc_108M_lpf = VDC_108M_FDF_85MHZ;
unsigned char cvideo_tv_channel_scan_is_running = OFF;
unsigned short FieldVTotal = 263;
#ifdef CONFIG_SCART_ENABLE
unsigned char SCART_Type = _SCART_AV;	/* 0: is scart av, 2: is scart sv, 1: is scart rgb */
unsigned char pre_SCART_Type = 0xff;
unsigned char SCART_Counter = 0x00;
unsigned char SvNoBurstMark = 1;
#define cSCART_constant     0x0a
#endif

unsigned char vdc_power_status = OFF;
unsigned char vdc_set_hactive_flag = 0;
unsigned char vdc_TV_dctieh_table_value = 0x00;
unsigned char vdc_factory_mod_enable = OFF;
unsigned char tvAutoScanFlag = FALSE;
bool vdc_autoMode_without_secam = FALSE; /* 20121015, for shanghai tvbox issue*/
unsigned char cvideo_fh_set_1d = OFF;
/* ====== 20150119 for loop check without delay ====== */
bool vdc_AV_modech = FALSE;
bool vdc_LockStatus = 0x0;
bool vdc_ChromaLockStatus = 0x0;
bool vdc_BurstLockStatus = 0x0;
bool vdc_AnyVCRStatus = 0x0;
bool vdc_625flag = 0x0;
unsigned char vdc_NoiseStatus = 0x00;
unsigned char ucNoiseTmp[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned int vdc_ucLockCounter = 0x0;
unsigned int vdc_ucNoSignalCounter = 0x0;
static unsigned char vdc_LoopCount = 0x00;
static unsigned char vdc_ucLockCount = 10;
static unsigned char vdc_ucChromaLockCount = 10;
static unsigned char vdc_ucBurstLockCount = 10;
static unsigned char vdc_ucAnyVCRCount = 10;
static unsigned char vdc_uc625flagCount = 10;
unsigned char vlock_status = VDC_V_LOCK_DEF;
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
static bool vdc_MvFlag = 0x0;
static unsigned char vdc_ucMvCount = 10;
#endif
bool vdc_OldVLockStatus = 0x0;
static unsigned char vdc_ucOldVLockCount = 10;

#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
#define vd_cpeak_disable		0x0
#define vd_cpeak_enable		0x1
#define vd_cpeak_thesame	0xf
static unsigned char color_count = 0x0;
static unsigned char normal_count = 0x0;
static unsigned char VDC_CpeakSet = vd_cpeak_disable;
#endif

#ifdef scart_vdc_auto_balance_en
vdc_ADCGainOffset g_scart_ADCGainOffset;
VDBrConSat g_scart_VDBrConSat;
#endif

static int g_hstate_vsync_error_unbalance_status_cnt  = 0 ;
static unsigned int g_hstate_vsync_error_unbalance_status_result = 0;
static int g_Hdetect_error_cnt  = 0;

static unsigned short g_Hdetect_error_avg = 0, g_Hdetect_error_var_status_max = 0;

VDC_FRAME_RATE field = VDC_FRAME_RATE_50HZ;
unsigned short gVideoTableInputInfo[][5] = {
	/* IHTotal, IHStart, IHWidth, IVStart, IVHeight */
	{   864,    0,      720,    0,  288     },  /* 50HZ */
	{   858,    0,      720,    0,  240     },  /* 60HZ */
};

static unsigned char g_ucFixCKillMode;

extern void module_vdc_Clear_SECAM_Setting(void);
extern void module_vdc_Set_SECAM_Setting(void);

/*============= Local Functions' Phototype ============== */
unsigned int vdcf_inl(unsigned int offset)
{
	unsigned int ret;

#ifdef VIDEO_DEBUG_ENABLE_RECROD
	ret = module_video_debug_record_read(offset);
#else
	ret = IoReg_Read32(offset);
#endif /* VIDEO_DEBUG_ENABLE_RECROD */

 	return ret;
}

void vdcf_outl(unsigned int offset, unsigned int val)
{
 #ifdef VIDEO_DEBUG_ENABLE_RECROD
	module_video_debug_record_write(offset, val);
#else
	IoReg_Write32(offset, val);
#endif /* VIDEO_DEBUG_ENABLE_RECROD */
}

void vdcf_maskl(unsigned int offset, unsigned int andMask, unsigned int orMask)
{
	vdcf_outl(offset, ((vdcf_inl(offset) & (andMask)) | (orMask)));
}

void drv_module_vdc_SetInterrupt(VDC_IRQ_SWITCH on_off)
{
	vdtop_irq_mask1_RBUS irq_mask1_reg;
	vdtop_irq_mask2_RBUS irq_mask2_reg;
	irq_mask1_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK1_reg);
	irq_mask2_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK2_reg);

	switch (on_off) {
	case VDC_vcr_irq_enable:
		irq_mask1_reg.vcr_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_vcr_irq_disable:
		irq_mask1_reg.vcr_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_Nosig_irq_enable:
		irq_mask1_reg.nosig_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_Nosig_irq_disable:
		irq_mask1_reg.nosig_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_Mode_irq_enable:
		irq_mask1_reg.mode_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_Mode_irq_disable:
		irq_mask1_reg.mode_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_Proscan_irq_enable:
		irq_mask1_reg.proscan_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_Proscan_irq_disable:
		irq_mask1_reg.proscan_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_Noisy_irq_enable:
		irq_mask1_reg.noisy_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_Noisy_irq_disable:
		irq_mask1_reg.noisy_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_chromalock_irq_enable:
		irq_mask1_reg.chromalock_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_chromalock_irq_disable:
		irq_mask1_reg.chromalock_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_vlock_irq_enable:
		irq_mask1_reg.vlock_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_vlock_irq_disable:
		irq_mask1_reg.vlock_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_hlock_irq_enable:
		irq_mask1_reg.hlock_irq_en = 1;
		goto _Set_IRQ_MASK1;
	case VDC_hlock_irq_disable:
		irq_mask1_reg.hlock_irq_en = 0;
		goto _Set_IRQ_MASK1;
	case VDC_vd_scene_change_irq_enable:
		irq_mask2_reg.vd_scene_change_irq_en = 1;
		goto _Set_IRQ_MASK2;
	case VDC_vd_scene_change_irq_disable:
		irq_mask2_reg.vd_scene_change_irq_en = 0;
		goto _Set_IRQ_MASK2;
	case VDC_ddr_addr_irq_enable:
		irq_mask2_reg.ddr_addr_irq_en = 1;
		goto _Set_IRQ_MASK2;
	case VDC_ddr_addr_irq_disable:
		irq_mask2_reg.ddr_addr_irq_en = 0;
		goto _Set_IRQ_MASK2;
	case VDC_Noisy_vbi_irq_enable:
		irq_mask2_reg.noisy_vbi_irq_en = 1;
		goto _Set_IRQ_MASK2;
	case VDC_Noisy_vbi_irq_disable:
		irq_mask2_reg.noisy_vbi_irq_en = 0;
		goto _Set_IRQ_MASK2;
	case VDC_Coch_irq_enable:
		irq_mask2_reg.coch_irq_en = 1;
		goto _Set_IRQ_MASK2;
	case VDC_Coch_irq_disable:
		irq_mask2_reg.coch_irq_en = 0;
		goto _Set_IRQ_MASK2;
	case VDC_Field_irq_enable:
		irq_mask2_reg.field_irq_en = 1;
		goto _Set_IRQ_MASK2;
	case VDC_Field_irq_disable:
		irq_mask2_reg.field_irq_en = 0;
		goto _Set_IRQ_MASK2;
	case VDC_All_irq_disable:
		irq_mask1_reg.regValue = 0x00000000;
		irq_mask2_reg.regValue = 0x00000000;
		vdcf_outl(VDTOP_IRQ_MASK1_reg, irq_mask1_reg.regValue);
		vdcf_outl(VDTOP_IRQ_MASK2_reg, irq_mask2_reg.regValue);
		break;
_Set_IRQ_MASK1:
		vdcf_outl(VDTOP_IRQ_MASK1_reg, irq_mask1_reg.regValue);
		break;
_Set_IRQ_MASK2:
		vdcf_outl(VDTOP_IRQ_MASK2_reg, irq_mask2_reg.regValue);
	default:
		break;
	}
}


/**
   drvif_module_vdc_ClockOn
   Enable VDC clock and reset

   @return                  { void }
*/
void drvif_module_vdc_ClockOn(void)
{
#if 0
	IoReg_Mask32(0xb8022284, 0xffffffff, _BIT12 | _BIT13);
	rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"0xb8022284=%x\n", IoReg_Read32(0xb8022284));
	IoReg_Write32(0xb8000118, _BIT24 | _BIT25 | _BIT0);
	IoReg_Write32(0xb8000108, _BIT24 | _BIT25 | _BIT0);
	IoReg_Write32(0xb8000114, _BIT2 | _BIT0);
	IoReg_Write32(0xb8000104, _BIT2 | _BIT0);
#endif

	enum CRT_CLK clken = CLK_ON;
	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_ClockOn\n");
	CRT_CLK_OnOff(SCALER_VDC_1, clken , NULL);
	//drvif_module_Set_pll27x_source(VDC_PLL27x_CLK_324M);
}

/**
   drvif_module_vdc_PowerCtrl
   Power on/off vdc module (Only for AV/SV/SCART)

   @param <on_off>   { _ON/_OFF }
   @param <a_ucInputSrc>   { _SRC_TV, _SRC_CVBS, .... }
   @return                  { void }
*/
void drvif_module_vdc_PowerCtrl(unsigned char on_off, unsigned char a_ucInputSrc)
{
	VDC_POWER_SETTING ucPowerMode = VDC_Power_off;
	sys_reg_sys_clksel_RBUS sys_clksel_reg;		/* 0_0204 */

	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_PowerCtrl = %x\n", on_off);
	/*=== vdc power on ===*/
	if (on_off == ON) {
		/* input clock select */
		sys_clksel_reg.regValue = rtdf_inl(SYS_REG_SYS_CLKSEL_reg);	/* 0_0204 */
		/* 0_0204: [16]ATVIN_VD_CLK_SEL */
		sys_clksel_reg.atvin_clk_sel = 1;		/* [17] ATV Input clcok select, 0: IFD, 1:VD */
		sys_clksel_reg.atvin_vd_clk_sel = 0;	/* [16] ATV Input clcok select, 0: 108M, 1: 27M */
		rtdf_outl(SYS_REG_SYS_CLKSEL_reg, sys_clksel_reg.regValue);
	} else {
		fwif_color_SetAutoMAFlag(0);
	}
//	drvif_module_vd_ADC_PowerCtrl(on_off, a_ucInputSrc);
//	drvif_module_vdc_digital_PowerCtrl(on_off, _ENABLE);
//	drvif_module_vdc_SoftReset();
#if 0
	if(on_off)
		ucPowerMode = VDC_Power_on;
	else
		ucPowerMode = VDC_Power_off;
	drvif_module_vdc_Power_Setting(ucPowerMode, a_ucInputSrc);
#endif
	vdc_power_status = on_off;
	drvif_module_vdc_set_AVD_connect_flag(on_off);
}


bool module_vdc_check_vd_clock(void)
{
	enum CRT_CLK clken = CLK_ON;
	unsigned char ucRet = _TRUE;

	CRT_CLK_OnOff(SCALER_VDC_9, clken , (void *)&ucRet);

	if (!ucRet) {
		VDC_DEBUG_MSG(VDC_MSG_ERROR, "VD clock is not setted, set it !\n");
	}

	return ucRet;
}

bool module_vdc_check_pll27x_setting(void)
{
	enum CRT_CLK clken = CLK_ON;
	unsigned char ucRet = _TRUE;

	CRT_CLK_OnOff(SCALER_VDC_3, clken , (void *)&ucRet);
	return ucRet;
}

void drvif_module_Set_pll27x_source(VDC_PLL27x_CLK_REG freq)
{
	enum CRT_CLK clken = CLK_ON;
	/* === jj check ok 20150320 === */
	VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_Set_pll27x_source = %x\n", freq);

	CRT_CLK_OnOff(SCALER_VDC_4, clken , (void *)&freq);
}

VDC_PLL27x_CLK_REG drvif_module_Read_pll27x_vco_setting(void)
{
	VDC_PLL27x_CLK_REG tPLL27xClkReg;
	pll27x_reg_sys_pll_27x1_RBUS sys_pll_27x1_reg;	/* 0_04d0 */

	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_VDC_5, clken , (void *)&sys_pll_27x1_reg.regValue);

	switch (sys_pll_27x1_reg.pll27x_m) {
	case 0x16:
		tPLL27xClkReg = VDC_PLL27x_CLK_648M;
		break;
	case 0x12:
		tPLL27xClkReg = VDC_PLL27x_CLK_540M;
		break;
	default:
	case 0x0e:
		tPLL27xClkReg = VDC_PLL27x_CLK_432M;
		break;
	case 0x0a:
		tPLL27xClkReg = VDC_PLL27x_CLK_324M;
		break;
	}
	return tPLL27xClkReg;
}

void drvif_module_vdc_FIFO_CLK_setting(void)
{
	/* === jj check ok 20150320 === */
	/* 9764[9:8], 0_04d8[3] */
#ifdef VD_Digital_FIFO		/* digital FIFO */
	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_FIFO_CLK_setting : Digital\n");
	module_vdc_set_new_fifo_parameter();
#else
	VDC_PLL27x_CLK_REG tPLL27xClkReg = drvif_module_Read_pll27x_vco_setting();

	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_VDC_6, clken , (void *)&tPLL27xClkReg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_FIFO_CLK_setting : Analog [CLK_ON] SCALER_VDC_6\n");
#endif
#if 0
	if (tvAutoScanFlag == FALSE) {
		/* not to set at autoscan to save time */
		mdelay(2);
		drvif_module_vdc_Analog_FIFO_Reset();
	}
#endif
}

void drvif_module_vdc_Power_Setting(VDC_POWER_SETTING mode, unsigned char a_ucInputSrc)
{
	switch(mode)
	{
		default:
		case VDC_Power_off:
			drvif_module_vdc_digital_PowerCtrl(OFF, _DISABLE);
			drvif_module_vd_ADC_PowerCtrl(OFF, a_ucInputSrc);
			break;
		case VDC_Power_on:
			drvif_module_vd_ADC_PowerCtrl(ON, a_ucInputSrc);
			drvif_module_vdc_digital_PowerCtrl(ON, _ENABLE);
			drvif_module_vdc_SoftReset();
			break;
		case VDC_Power_saving:	// can detect input signal
			drvif_module_vd_ADC_PowerCtrl(ON, a_ucInputSrc);
			drvif_module_vdc_digital_PowerCtrl(OFF, _ENABLE);
			drvif_module_vdc_SoftReset();
			break;
	}
	//rtd_printk(KERN_INFO, TAG_NAME_VDC,"drvif_module_vdc_Power_Setting vdc_needopenpowerflag=%d\n",vdc_needopenpowerflag);
}

void drvif_module_vd_ADC_PowerCtrl(unsigned char on_off, unsigned char a_ucInputSrc)
{	/* 2_0048, 2_0050, 2_0054, 2_005c */
	adc_vd_adc_clamp_ctl_1_RBUS vd_adc_clamp_ctl_1_reg;	/* 2_0048 */
	adc_vd_adc_updn_ctl_RBUS vd_adc_updn_ctl_reg;		/* 2_0050 */
	adc_vdadc_core_lpf_ctrl_RBUS vdadc_core_lpf_ctrl_reg;	/* 2_0054 */
	adc_vdadc_pow_ctl_RBUS vdadc_pow_ctl_reg;			/* 2_005c */
	vd_adc_clamp_ctl_1_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_1_reg);
	vd_adc_updn_ctl_reg.regValue = rtdf_inl(ADC_VD_ADC_UPDN_CTL_reg);
	vdadc_core_lpf_ctrl_reg.regValue = rtdf_inl(ADC_VDADC_CORE_LPF_CTRL_reg);
	vdadc_pow_ctl_reg.regValue = rtdf_inl(ADC_VDADC_POW_CTL_reg);

	if (on_off == ON) {
		/*=== ADC power on/off ===*/
		down(get_adc_power_semaphore());
		drvif_adc_power_control(ADC_POWER_VDC_ENABLE_CONTROL);
		up(get_adc_power_semaphore());

		/* ATV source don't need to open these clock */
		if (_SRC_TV != a_ucInputSrc) {
			/* VD ADC power on: PGA on-->SAR ADC on*/
			vdadc_pow_ctl_reg.vdadc_pow = 1;	/* 2_005c[0] VDADC Power */
			vdadc_core_lpf_ctrl_reg.vdadc_adc_ctrl_2 = 1;	/*Clayton: Fix error 2_0054[18] SAR ADC Power On*/
			//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_PowerCtrl [Set VD-1]\n");
		}
		vdadc_pow_ctl_reg.ldo100ma_pow = 1;	/* the major power of vdadc */
		rtdf_outl(ADC_VDADC_POW_CTL_reg, vdadc_pow_ctl_reg.regValue);	//Clayton note [1/2]: PGA on first
		rtdf_outl(ADC_VDADC_CORE_LPF_CTRL_reg, vdadc_core_lpf_ctrl_reg.regValue);	//Clayton note [2/2]: ADC on later
	} else {
		if ((SRC_NOTHING == get_ADC_Global_Status()) || (SRC_INIT_DONE == get_ADC_Global_Status())) {
			down(get_adc_power_semaphore());
			drvif_adc_power_control(ADC_POWER_ALL_DISABLE_CONTROL);
			up(get_adc_power_semaphore());
		} else {
			down(get_adc_power_semaphore());
			drvif_adc_power_control(ADC_POWER_VDC_DISABLE_ADC_ALIVE_CONTROL);
			up(get_adc_power_semaphore());
		}
		/* VD ADC power off: SAR ADC off --> PGA off*/
		vdadc_core_lpf_ctrl_reg.vdadc_adc_ctrl_2= 0;	/*Clayton: Fix error 2_0054[18] SAR ADC Power On*/
#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH_DETECT_BY_PIN
		vdadc_pow_ctl_reg.vdadc_pow = 1;	/* 2_005c[0] VDADC Power */
#else
		vdadc_pow_ctl_reg.vdadc_pow = 0;	/* 2_005c[0] VDADC Power */
#ifdef ENABLE_PWR_IP_CLOSE_SIRIUS
		vdadc_pow_ctl_reg.ldo100ma_pow = 0;	/* 2_005c[1]=1, enable LDO power */
#endif
#endif
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_14_13 = 0x0;
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_15 = 0x0;
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_7 = 0;
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_6_5 = 0x0;
		vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_2 = 0x0;	/* 2_0050[2:0] = 0, clamp up/dn vin9~14 */
		rtdf_maskl(ADC_SCART_CTRL1_reg, ~(_BIT0), _ZERO);
	

	rtdf_outl(ADC_VD_ADC_CLAMP_CTL_1_reg, vd_adc_clamp_ctl_1_reg.regValue);
	rtdf_outl(ADC_VD_ADC_UPDN_CTL_reg, vd_adc_updn_ctl_reg.regValue);
	rtdf_outl(ADC_VDADC_CORE_LPF_CTRL_reg, vdadc_core_lpf_ctrl_reg.regValue);	//Clayton note [1/2]: ADC off first
	rtdf_outl(ADC_VDADC_POW_CTL_reg, vdadc_pow_ctl_reg.regValue);	//Clayton note [2/2]: PGA off later
	}
}

void drvif_module_vdc_digital_PowerCtrl(unsigned char on_off, unsigned char detect_on)
{	/* 9004[17:10], 9794[30] */
	vdtop_video_control1_RBUS vdtop_video_control1_reg;
	vdtop_pattern_control_RBUS vdtop_pattern_control_reg;
	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_digital_PowerCtrl = %x\n", on_off);
	vdtop_video_control1_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL1_reg);
	vdtop_video_control1_reg.ycsep_power_on = on_off;
	vdtop_video_control1_reg.smixer_ycadjust_power_on = on_off;
	vdtop_video_control1_reg.sv_power_on_en = on_off;
	vdtop_video_control1_reg.scart_power_on_en = on_off;
	vdtop_video_control1_reg.secam_power_on_en = on_off;
	vdtop_video_control1_reg.avout_power_on_en = on_off;
	vdtop_video_control1_reg.dark_cpll_power_on_en = on_off;
	vdtop_video_control1_reg.patterngen_power_on_en = on_off;
	vdcf_outl(VDTOP_VIDEO_CONTROL1_reg, vdtop_video_control1_reg.regValue);
	vdtop_pattern_control_reg.regValue = vdcf_inl(VDTOP_PATTERN_CONTROL_reg);
	if (detect_on == 1) {
		vdtop_pattern_control_reg.vd_on = 1;
	} else {
		vdtop_pattern_control_reg.vd_on = on_off;
	}
	vdcf_outl(VDTOP_PATTERN_CONTROL_reg, vdtop_pattern_control_reg.regValue);
}

/**
   drvif_module_vdc_SoftReset
   Reset video parameter

   @param <void>       { void }
   @return                  { void }

*/
void drvif_module_vdc_SoftReset(void)
{	/* b800_0104[21] or b801_9160[1],9218[9],93bc[3][2:1] */
#ifdef VD_Digital_FIFO
	vdtop_fifo_wo_ps_clk_state_parameter_RBUS fifo_wo_ps_clk_state_parameter_reg;
#endif

#if 1
	vdtop_hpll_integral_ctrl_RBUS vdtop_hpll_integral_ctrl_reg;
	vdtop_hpll_integral_ctrl_reg.regValue = vdcf_inl(VDTOP_HPLL_INTEGRAL_CTRL_reg);
	vdtop_hpll_integral_ctrl_reg.hpll_integral_rst = 1;
	vdcf_outl(VDTOP_HPLL_INTEGRAL_CTRL_reg, vdtop_hpll_integral_ctrl_reg.regValue);
	vdtop_hpll_integral_ctrl_reg.hpll_integral_rst = 0;
	vdcf_outl(VDTOP_HPLL_INTEGRAL_CTRL_reg, vdtop_hpll_integral_ctrl_reg.regValue);
	drvif_module_vdc_cpll_reset();
	drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE1);
	drvif_module_vdc_Set_Vstate(VDC_FIX_VSTATE0);
	drvif_module_vdc_Set_Vstate(VDC_VSTATE_RESET);
	rtd_printk(KERN_INFO, TAG_NAME_VDC, "vdc_SoftReset\n");
#else
	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_VDC_10, clken , NULL);
	mdelay(1);
#endif

#ifdef VD_Digital_FIFO
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 0;
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 1;
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
#endif
	//VDC_DEBUG_MSG(VDC_MSG_RESET, "vdc_SoftReset !!\n");
	drvif_module_vdc_reset_Status();
}

/**
   drvif_module_vdc_SoftReset
   Reset video parameter

   @param <void>       { void }
   @return                  { void }

*/
void drvif_module_vdc_SoftReset_New(void)
{	/* b800_0104[21] or b801_9160[1],9218[9],93bc[3][2:1] */
#ifdef VD_Digital_FIFO
	vdtop_fifo_wo_ps_clk_state_parameter_RBUS fifo_wo_ps_clk_state_parameter_reg;
#endif

	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_VDC_10, clken , NULL);
	mdelay(1);

#ifdef VD_Digital_FIFO
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 0;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 0;
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 1;
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
#endif
	//VDC_DEBUG_MSG(VDC_MSG_RESET, "vdc_SoftReset !!\n");
	drvif_module_vdc_reset_Status();
}


/**
   drvif_module_vdc_108M_FrontDigitalFilterEnable
   Video funtion set, extern

   @param <void>       { void }
   @return                  { void }
*/
void drvif_module_vdc_108M_FrontDigitalFilterEnable(VDC_VIDEO_108M_FrontDigitalFilter mode)
{
	/* 1_80ac, 1_8000~1_8040, 1_80d4 */
	vd_ifd_input_vd_inout_ctrl_RBUS vd_inout_ctrl_reg;//sunray
	sys_reg_sys_clksel_RBUS sys_clksel_reg;		/* 0_0204 */

	if (drvif_module_vdc_read_Clamping_path()) {
		//VDC_DEBUG_MSG(VDC_MSG_INIT, " Is TV source, do not set it !\n");
		return;
	}

	sys_clksel_reg.regValue = rtdf_inl(SYS_REG_SYS_CLKSEL_reg);	/* 0_0204 */
	if (sys_clksel_reg.atvin_clk_sel != 1) {
		sys_clksel_reg.atvin_clk_sel = 1;		/* [17] ATV Input clcok select, 0: IFD, 1:VD */
		rtdf_outl(SYS_REG_SYS_CLKSEL_reg, sys_clksel_reg.regValue);
	}

	vd_inout_ctrl_reg.regValue = vdcf_inl(VD_IFD_INPUT_VD_INOUT_CTRL_reg);
	vd_inout_ctrl_reg.adc27_mod = 0;		/* 1_80ac[0]=0 : Data from decimation filter and dnsample x4 */
	//VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_108M_FrontDigitalFilterEnable\n");

	switch (mode) {
	case VDC_108M_FDF_BYPASS:
		vd_inout_ctrl_reg.fe_fil_sel = 0; /* through decimation filter */
		break;
	case VDC_108M_FDF_55MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_55MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_60MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_60MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_65MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_65MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_70MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_70MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_75MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_75MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_80MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_80MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	case VDC_108M_FDF_85MHZ:
		drvif_module_vdc_input_filter_sel(0, INPUT_FILTER_85MHZ);
		vd_inout_ctrl_reg.fe_fil_sel = 1;
		break;
	}
	vdcf_outl(VD_IFD_INPUT_VD_INOUT_CTRL_reg, vd_inout_ctrl_reg.regValue);

}

unsigned char drvif_module_vdc_Read_108M_FrontDigitalFilter_info(void)
{
	/* 1_80ac, 1_8000~1_8040, 1_80d4 */
	//fein_vd_inout_ctrl_RBUS vd_inout_ctrl_reg;
	vd_ifd_input_vd_inout_ctrl_RBUS vd_inout_ctrl_reg;//sunray
	vd_ifd_input_108_input_flt_tap_0_1_RBUS input_flt_tap_0_1_reg;
	sys_reg_sys_clksel_RBUS sys_clksel_reg;		/* 0_0204 */

	if (drvif_module_vdc_read_Clamping_path()) {
		VDC_DEBUG_MSG(VDC_MSG_INIT, " Is TV source, do not set it !\n");
		return VDC_108M_FDF_BYPASS;//coverity ID 16273
	}

	sys_clksel_reg.regValue = rtdf_inl(SYS_REG_SYS_CLKSEL_reg);	/* 0_0204 */
	if (sys_clksel_reg.atvin_clk_sel != 1) {
		sys_clksel_reg.atvin_clk_sel = 1;		/* [17] ATV Input clcok select, 0: IFD, 1:VD */
		rtdf_outl(SYS_REG_SYS_CLKSEL_reg, sys_clksel_reg.regValue);
	}

	vd_inout_ctrl_reg.regValue = vdcf_inl(VD_IFD_INPUT_VD_INOUT_CTRL_reg);
	input_flt_tap_0_1_reg.regValue = vdcf_inl(VD_IFD_INPUT_108_input_flt_tap_0_1_reg);

	if (vd_inout_ctrl_reg.fe_fil_sel != 0) {
		if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_55MHZ[1])
			return VDC_108M_FDF_55MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_60MHZ[1])
			return VDC_108M_FDF_60MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_65MHZ[1])
			return VDC_108M_FDF_65MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_70MHZ[1])
			return VDC_108M_FDF_70MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_75MHZ[1])
			return VDC_108M_FDF_75MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_80MHZ[1])
			return VDC_108M_FDF_80MHZ;
		else if (input_flt_tap_0_1_reg.input_flt_tap1 == INPUT_FILTER_85MHZ[1])
			return VDC_108M_FDF_85MHZ;
		else
			return VDC_108M_FDF_BYPASS;
	} else {
		return VDC_108M_FDF_BYPASS;
	}
}


void module_vdc_adcNegativeAdjustment(unsigned char ucValue)
{	
	adc_vd_adc_clamp_ctl_1_RBUS adc_vd_adc_clamp_ctl_1_reg;
	/* 2_0048 */
	if (drvif_module_vdc_CheckFactoryModEnable(ON))
		return;
	adc_vd_adc_clamp_ctl_1_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_1_reg);
	if (adc_vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_7_4 != ucValue) {
		adc_vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_7_4 = ucValue;
		rtdf_outl(ADC_VD_ADC_CLAMP_CTL_1_reg, adc_vd_adc_clamp_ctl_1_reg.regValue);
	}
}

unsigned int drvif_video_control_reg(VDC_CONTROL_REG status)
{
	/* 9000, 9004 */
	unsigned int result = 0xffffffff;
	vdtop_video_control0_RBUS video_control0_reg;
	vdtop_video_control1_RBUS video_control1_reg;
	video_control0_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL0_reg);
	video_control1_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL1_reg);

	switch (status) {
	/*VIDEO_STATUS_REG1 0x1801_9000 */
	case VDC_hv_delay:
		result = video_control0_reg.hv_delay;
		break;
	case VDC_hpixel:
		result = video_control0_reg.hpixel;
		break;
	case VDC_Vline_625:
		result = video_control0_reg.vline_625;
		break;
	case VDC_Colour_mode:
		result = video_control0_reg.colour_mode;
		break;
	case VDC_CONTROL_REG0:
		result = video_control0_reg.regValue;
		break;
	/*VIDEO_STATUS_REG2 0x1801_9004 */
	case VDC_cv_inv:
		result = video_control1_reg.cv_inv;
		break;
	case VDC_cv_src:
		result = video_control1_reg.cv_src;
		break;
	case VDC_yc_src:
		result = video_control1_reg.yc_src;
		break;
	case VDC_ped:
		result = video_control1_reg.ped;
		break;
	case VDC_CONTROL_REG1:
		result = video_control1_reg.regValue;
		break;
	default:
		break;
	}
	return result;
}

void drvif_video_set_control_reg(VDC_SET_CONTROL_REG status)
{
	/* 9000, 9004 */
	vdtop_video_control0_RBUS video_control0_reg;
	vdtop_video_control1_RBUS video_control1_reg;
	video_control0_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL0_reg);
	video_control1_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL1_reg);
	switch (status) {
	/* VIDEO_STATUS_REG1 0xb800_9000[4] */
	case VDC_set_Vline_625:
		if (video_control0_reg.vline_625 != 1) {
			video_control0_reg.vline_625 = 1;
			vdcf_outl(VDTOP_VIDEO_CONTROL0_reg, video_control0_reg.regValue);
		}
		break;
	case VDC_set_Vline_525:
		if (video_control0_reg.vline_625 != 0) {
			video_control0_reg.vline_625 = 0;
			vdcf_outl(VDTOP_VIDEO_CONTROL0_reg, video_control0_reg.regValue);
		}
		break;
	/* VIDEO_STATUS_REG1 0x1800_3000[3:1] */
	case VDC_set_Colour_mode_NTSC:
		video_control0_reg.colour_mode = 0;
		goto _write_to_control0_reg;
	case VDC_set_Colour_mode_NTSC443:
		video_control0_reg.colour_mode = 5;
		goto _write_to_control0_reg;
	case VDC_set_Colour_mode_PAL60:
		video_control0_reg.colour_mode = 7;
		goto _write_to_control0_reg;
_write_to_control0_reg:
		vdcf_outl(VDTOP_VIDEO_CONTROL0_reg, video_control0_reg.regValue);
		break;

	case VDC_set_src_AV:
		video_control1_reg.cv_src = 0;
		video_control1_reg.yc_src = 0;
		goto _write_to_control1_reg;
	case VDC_set_src_YPP:
		video_control1_reg.cv_src = 1;
		video_control1_reg.yc_src = 0;
		goto _write_to_control1_reg;
	case VDC_set_src_SV:
		video_control1_reg.cv_src = 0;
		video_control1_reg.yc_src = 1;
		goto _write_to_control1_reg;
	case VDC_ped_on:
		video_control1_reg.ped = 1;
		goto _write_to_control1_reg;
	case VDC_ped_off:
		video_control1_reg.ped = 0;
		goto _write_to_control1_reg;
_write_to_control1_reg:
		vdcf_outl(VDTOP_VIDEO_CONTROL1_reg, video_control1_reg.regValue);
		break;

	default:
		break;
	}
}

unsigned char drvif_video_check_AV_stable(void)
{
	vdtop_video_status_reg1_RBUS video_status_reg1_reg;
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;
	video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
	video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
#if 1
	if (((video_status_reg1_reg.regValue & 0x07) == 0x06)
		|| ((video_status_reg1_reg.hlock))) {
		return _SUCCESS;
	} else {
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		if (((video_status_reg1_reg.regValue & 0x07) == 0x06)
			|| ((video_status_reg1_reg.hlock))) {
			return _SUCCESS;
		} else {
			VDC_DEBUG_MSG(VDC_MSG_DEBUG3, "AV not stable !!!");
			return _FAIL;
		}
	}
#else
	if ((video_status_reg2_reg.old_vdetect_stable == 0) ||
		(video_status_reg2_reg.new_vdetect_stable == 0)) {
		VDC_DEBUG_MSG(VDC_MSG_DEBUG3, "no v lock !!!");
		return _FAIL;
	} else
		return _SUCCESS;
#endif
}

/*USER:LewisLee DATE:2012/12/26 */
/*add this flag, for speed up */
#define GET_VIDEO_STATUS_SPEED_UP

static bool debug_dump_hvlocked = false;

static inline void debug_set_dump_hvlocked(bool is_dump)
{
	debug_dump_hvlocked = is_dump;
}

static inline bool debug_get_dump_hvlocked(void)
{
	return debug_dump_hvlocked;
}

unsigned int drvif_video_status_reg(VDC_STATUS_REG status)
{
	/* 9008, 900c, 9010 */
	unsigned int result = 0xffffffff;
	unsigned char i = 0, j = 0, k = 0, m = 1;
	unsigned char uclock = 10;
	unsigned int history[3*2][4*2] = {{0}}; /* history[m][k], multiple 2 for memory safe */
	vdtop_video_status_reg1_RBUS video_status_reg1_reg;
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;
	vdtop_video_status_reg3_RBUS video_status_reg3_reg;

	switch (status) {
		/* VIDEO_STATUS_REG1 0x1801_9008 */
	case VDC_STATUS_REG1:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.regValue;
		break;
	case VDC_chomalock:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.chomalock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(5);
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.chomalock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(5);
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.chomalock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(5);
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.chomalock;
		break;
	case VDC_vlock:
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.vlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(10);
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.vlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(10);
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.vlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(10);
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.vlock;
		if (debug_get_dump_hvlocked() && !result) {
			video_logk("STATUS::VDC_vlock\n");
			video_logk("--- start ---\n");
			for (i = 0, m = 1; i < k; ++i) {
				for (j = 0; j < m; ++j) {
					video_logk("[%d][%d]%08x(%*pbl)\n", j, i, history[j][i], 32, &(history[j][i]));
				}
			}
			video_logk("---- end ----\n");
		}
		break;
	case VDC_hlock:
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.hlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.hlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.hlock;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result |= video_status_reg1_reg.hlock;
		if (debug_get_dump_hvlocked() && !result) {
			video_logk("STATUS::VDC_hlock\n");
			video_logk("--- start ---\n");
			for (i = 0, m = 1; i < k; ++i) {
				for (j = 0; j < m; ++j) {
					video_logk("[%d][%d]%08x(%*pbl)\n", j, i, history[j][i], 32, &(history[j][i]));
				}
			}
			video_logk("---- end ----\n");
		}
		break;
	case VDC_no_signal:
		video_status_reg1_reg.regValue = history[0][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.no_signal;
		if (debug_get_dump_hvlocked() && !result) {
			video_logk("STATUS::VDC_no_signal\n");
			video_logk("--- start ---\n");
			for (i = 0, m = 1; i < k; ++i) {
				for (j = 0; j < m; ++j) {
					video_logk("[%d][%d]%08x(%*pbl)\n", j, i, history[j][i], 32, &(history[j][i]));
				}
			}
			video_logk("---- end ----\n");
		}
		break;
	case VDC_not_no_signal:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = ~(video_status_reg1_reg.no_signal);
		break;
	case VDC_hv_lock:	/* need more than 20mS */
		for (i = 0; i < 4; i++) {
			video_status_reg1_reg.regValue = history[0][k] = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
			video_status_reg2_reg.regValue = history[1][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (((video_status_reg1_reg.regValue & 0x07) == 0x06)
				|| ((video_status_reg1_reg.hlock) && (video_status_reg2_reg.vlock_new))) {
				uclock++;
			} else {
				uclock--;
			}
			Rt_Delay(5);
		}

		if (uclock < 8)
			result = 0;
		else
			result = 1;

		if (debug_get_dump_hvlocked() && !result) {
			video_logk("STATUS::VDC_hv_lock: clock %d\n", uclock);
			video_logk("--- start ---\n");
			for (i = 0, m = 2; i < k; ++i) {
				for (j = 0; j < m; ++j) {
					video_logk("[%d][%d]%08x(%*pbl)\n", j, i, history[j][i], 32, &(history[j][i]));
				}
			}
			video_logk("---- end ----\n");
		}
		break;
	case VDC_all_lock:
		for (i = 0; i < 4; i++) {
			video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
			if ((video_status_reg1_reg.regValue & 0x0f) == 0x0e)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 8)
			result = 0;
		else
			result = 1;
		break;
	case VDC_mv_detect:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.mv_vbi_detected;
		break;
	case VDC_cid_detect:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.mv_colour_inverse;
		break;
	case VDC_h_fine_lock:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.h_fine_lock;
		break;
	case VDC_chromalock_acc:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.chromalock_acc;
		break;
	case VDC_hlock_longtime:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.hlock_longtime;
		break;
	case VDC_vlock_longtime:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.vlock_longtime;
		break;
	case VDC_hvlock_longtime:
		video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
		result = video_status_reg1_reg.hvlock_longtime;
		break;
	/* VIDEO_STATUS_REG2 0x1801_900C */
	case VDC_STATUS_REG2:
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result = video_status_reg2_reg.regValue;
		break;
	case VDC_V_detect_flag:
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result = video_status_reg2_reg.v_detect_flag;
		break;
	case VDC_Detect358_flag:
		for (i = 0; i < 4; i++) {
			video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (video_status_reg2_reg.detect358_flag)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 12)
			result = 0;
		else
			result = 1;
		break;
	case VDC_vlock_new:
		for (i = 0; i < 4; i++) {
			video_status_reg2_reg.regValue = history[1][k++] = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (video_status_reg2_reg.vlock_new) {
				uclock++;
			} else {
				uclock--;
			}
			Rt_Delay(2);
		}

		if (uclock < 12)
			result = 0;
		else
			result = 1;

		if (debug_get_dump_hvlocked() && !result) {
			video_logk("STATUS::VDC_vlock_new clock %d\n", uclock);
			video_logk("--- start ---\n");
			for (i = 0, m = 2; i < k; ++i) {
				for (j = 1; j < m; ++j) {
					video_logk("[%d][%d]%08x(%*pbl)\n", j, i, history[j][i], 32, &(history[j][i]));
				}
			}
			video_logk("---- end ----\n");
		}
		break;
	case VDC_noisy_vbi:
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result = video_status_reg2_reg.noisy_vbi;
		break;
	case VDC_Detect443_flag:
		for (i = 0; i < 4; i++) {
			video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (video_status_reg2_reg.detect443_flag)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 12)
			result = 0;
		else
			result = 1;
		break;
	case VDC_Burst_detect:
		for (i = 0; i < 4; i++) {
			video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (video_status_reg2_reg.burst_detect)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 12)
			result = 0;
		else
			result = 1;
		break;
	case VDC_PALor_flag:
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result = video_status_reg2_reg.palor_flag;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(2);

		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result |= video_status_reg2_reg.palor_flag;
		break;
	case VDC_PALm_flag:
		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result = video_status_reg2_reg.palm_flag;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(2);

		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		result |= video_status_reg2_reg.palm_flag;
		break;
	case VDC_proscan_detected:
		for (i = 0; i < 4; i++) {
			video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (video_status_reg2_reg.proscan_detected)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	/* VIDEO_STATUS_REG3 0x1801_9010 */
	case VDC_STATUS_REG3:
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result = video_status_reg3_reg.regValue;
		break;
	case VDC_vcr_rew:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if (video_status_reg3_reg.vcr_rew)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_vcr_ff:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if (video_status_reg3_reg.vcr_ff)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_vcr_trick:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if (video_status_reg3_reg.vcr_trick)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_vcr:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if (video_status_reg3_reg.vcr)
				uclock++;
			else
				uclock--;

			Rt_Delay(2);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_vcr_any:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if ((video_status_reg3_reg.regValue & 0xf0) > 0)
				uclock++;
			else
				uclock--;

			Rt_Delay(10);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_noisy:
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result = video_status_reg3_reg.noisy;
		break;
	case VDC_Lines_625_detected:
		for (i = 0; i < 4; i++) {
			video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
			if (video_status_reg3_reg.lines_625_detected)
				uclock++;
			else
				uclock--;

			Rt_Delay(5);
		}
		if (uclock < 13)
			result = 0;
		else
			result = 1;
		break;
	case VDC_SECAM_detected:
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result = video_status_reg3_reg.secam_detected;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(5);

		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result |= video_status_reg3_reg.secam_detected;
		break;
	case VDC_PAL_detected:
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result = video_status_reg3_reg.pal_detected;
#ifdef GET_VIDEO_STATUS_SPEED_UP
		if (result)
			break;
#endif
		Rt_Delay(5);

		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		result |= video_status_reg3_reg.pal_detected;
		break;
	default:
		break;
	}
	return result;
}

bool drvif_video_status_reg_noScaler(VDC_STATUS_REG status)
{
	/* 9008, 900c, 9010 */
	unsigned char result = 0xff;
	unsigned char i;
	unsigned char uclock = 10;
	vdtop_video_status_reg1_RBUS video_status_reg1_reg;
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;

	if (status == VDC_hv_lock) {
		/* need more than 20mS */
		for (i = 0; i < 4; i++) {
			video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
			video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
			if (((video_status_reg1_reg.regValue & 0x07) == 0x06)
				|| ((video_status_reg1_reg.hlock) && (video_status_reg2_reg.vlock_new))) {
				uclock++;
			} else
				uclock--;
#if 0
			Rt_Delay(5);
#endif
		}
		if (uclock < 8)
			result = 0;
		else
			result = 1;
	} else
		result = 0;

	return result;
}

/* ========================================================================= */
unsigned char drvif_module_vdc_NoiseFlag(void)
{
	/* 900c[3] */
	return drvif_video_status_reg(VDC_noisy);
}

unsigned int drvif_module_vdc_Hdto_status(void)
{
	/* 9014[29:0] */
	vdtop_hdto_inc_status_RBUS hdto_inc_status_reg;
	hdto_inc_status_reg.regValue = vdcf_inl(VDTOP_HDTO_INC_STATUS_reg);
	return hdto_inc_status_reg.hdto_inc_status;
}

unsigned int drvif_module_vdc_Cdto_status(void)
{
	/* 9018[29:0] */
	vdtop_cdto_inc_status_RBUS cdto_inc_status_reg;
	cdto_inc_status_reg.regValue = vdcf_inl(VDTOP_CDTO_INC_STATUS_reg);
	return cdto_inc_status_reg.cdto_inc_status;
}

unsigned char drvif_module_vdc_burst_mag_status(void)
{
	/* 901c[7:0] */
	vdtop_avg_burst_mag_status_RBUS avg_burst_mag_status_reg;
	avg_burst_mag_status_reg.regValue =  vdcf_inl(VDTOP_AVG_BURST_MAG_STATUS_reg);
	return avg_burst_mag_status_reg.burst_magnitude;
}

unsigned int drvif_module_vdc_read_Dgain(void)
{
	/* 9020[11:0] */
	vdtop_agc_dgain_status_RBUS agc_dgain_status_reg;
	agc_dgain_status_reg.regValue =  vdcf_inl(VDTOP_AGC_DGAIN_STATUS_reg);
	return agc_dgain_status_reg.agc_dgain;
}

unsigned int drvif_module_vdc_read_Cgain(void)
{
	/* 9028[13:0] */
	vdtop_cgain_status_RBUS cgain_status_reg;
	cgain_status_reg.regValue =  vdcf_inl(VDTOP_CGAIN_STATUS_reg);
	return cgain_status_reg.status_cgain;
}

unsigned int drvif_module_vdc_read_V_1st_line(void)
{
	/* 9030[9:0] */
	vdtop_measure_first_v_RBUS measure_first_v_reg;
	measure_first_v_reg.regValue =  vdcf_inl(VDTOP_MEASURE_FIRST_V_reg);
	return measure_first_v_reg.v_1st_line;
}

unsigned int drvif_module_vdc_read_V_2nd_line(void)
{
	/* 9034[9:0] */
	vdtop_measure_second_v_RBUS measure_second_v_reg;
	measure_second_v_reg.regValue =  vdcf_inl(VDTOP_MEASURE_SECOND_V_reg);
	return measure_second_v_reg.v_2nd_line;
}

/**
    drvif_module_vdc_NoiseStatus
    Read noise status
    @param              { void }
    @return              { noise status }
*/
unsigned char drvif_module_vdc_NoiseStatus(void)
{
	/* 903c[7:0] */
	vdtop_noise_status_RBUS noise_status_reg;
	unsigned char noise_status, noise_status_max = 0, i;
	for (i = 0; i < 10; i++) {
		noise_status_reg.regValue = vdcf_inl(VDTOP_NOISE_STATUS_reg);
		noise_status = noise_status_reg.status_noise;
		if (noise_status > noise_status_max)
			noise_status_max = noise_status;
	}
	return noise_status_max;
}

void module_vdc_set_noise_thresh(unsigned char value)
{
	/* 9040[7:0] */
	vdtop_noise_threshold_RBUS noise_thresh_reg;
	noise_thresh_reg.regValue = vdcf_inl(VDTOP_NOISE_THRESHOLD_reg);
	if (noise_thresh_reg.noise_thresh != value) {
		noise_thresh_reg.noise_thresh = value;
		vdcf_outl(VDTOP_NOISE_THRESHOLD_reg, noise_thresh_reg.regValue);
	}
}

#ifdef VD_hdto_adjust
void module_vdc_set_hdto_inc(unsigned int value)
{
	/* 9050[29:0] */
	vdtop_hsync_dto_inc_RBUS HSYNC_DTO_INC_reg;
	HSYNC_DTO_INC_reg.regValue = vdcf_inl(VDTOP_HSYNC_DTO_INC_reg);
	if (HSYNC_DTO_INC_reg.hdto_inc != value) {
		HSYNC_DTO_INC_reg.hdto_inc = value;
		vdcf_outl(VDTOP_HSYNC_DTO_INC_reg, HSYNC_DTO_INC_reg.regValue);
	}
}

unsigned int module_vdc_read_hdto_inc(void)
{
	/* 9050[29:0] */
	vdtop_hsync_dto_inc_RBUS HSYNC_DTO_INC_reg;
	HSYNC_DTO_INC_reg.regValue = vdcf_inl(VDTOP_HSYNC_DTO_INC_reg);
	return HSYNC_DTO_INC_reg.hdto_inc;
}
#endif

/**
   drvif_module_vdc_SetContrast
   Set contrast

   @param <ucValue>  { Set contrast }
   @return                  { void }

*/
void drvif_module_vdc_SetContrast(unsigned char ucValue)
{
	/* 9060[7:0] */
	vdtop_luma_contrast_adj_RBUS luma_contrast_adj_reg;
	luma_contrast_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_CONTRAST_ADJ_reg);
	if (luma_contrast_adj_reg.contrast != ucValue) {
		luma_contrast_adj_reg.contrast = ucValue;
		vdcf_outl(VDTOP_LUMA_CONTRAST_ADJ_reg, luma_contrast_adj_reg.regValue);
	}
}

/**
   drvif_module_vdc_SetBrightness
   Set contrast

   @param <ucValue>  { Set contrast }
   @return                  { void }

*/
void drvif_module_vdc_SetBrightness(unsigned char ucValue)
{
	/* 9064[7:0] */
	vdtop_luma_brightness_adj_RBUS luma_brightness_adj_reg;
	luma_brightness_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_BRIGHTNESS_ADJ_reg);
	if (luma_brightness_adj_reg.brightness != ucValue) {
		luma_brightness_adj_reg.brightness = ucValue;
		vdcf_outl(VDTOP_LUMA_BRIGHTNESS_ADJ_reg, luma_brightness_adj_reg.regValue);
	}
}

/*
   drvif_module_vdc_SetSaturation
   Set saturation

   @param <ucValue>  { Set saturation }
   @return                  { void }

*/
void drvif_module_vdc_SetSaturation(unsigned char ucValue)
{
	/* 9068[7:0] */
	vdtop_chroma_saturation_adj_RBUS chroma_saturation_adj_reg;
	chroma_saturation_adj_reg.regValue = vdcf_inl(VDTOP_CHROMA_SATURATION_ADJ_reg);
	if (chroma_saturation_adj_reg.saturation != ucValue) {
		chroma_saturation_adj_reg.saturation = ucValue;
		vdcf_outl(VDTOP_CHROMA_SATURATION_ADJ_reg, chroma_saturation_adj_reg.regValue);
	}
}

/**
  drvif_module_vdc_SetHue
   Set hue
   @param <ucValue>  { Set hue }
  @return                  { void }
*/
void drvif_module_vdc_SetHue(unsigned char ucValue)
{
	/* 906c[7:0] */
	vdtop_chroma_hue_phase_adj_RBUS chroma_hue_phase_adj_reg;
	chroma_hue_phase_adj_reg.regValue = vdcf_inl(VDTOP_CHROMA_HUE_PHASE_ADJ_reg);
	if (chroma_hue_phase_adj_reg.hue != ucValue) {
		chroma_hue_phase_adj_reg.hue = ucValue;
		vdcf_outl(VDTOP_CHROMA_HUE_PHASE_ADJ_reg, chroma_hue_phase_adj_reg.regValue);
	}
}

void module_vdc_SetBlueScreenColor(unsigned int ucY, unsigned int ucCb, unsigned int ucCr)
{
	/* 9070[7:0], 9074[7:0], 9078[7:0] */
	vdtop_blue_screen_y_RBUS blue_screen_y_reg;
	vdtop_blue_screen_cb_RBUS blue_screen_cb_reg;
	vdtop_blue_screen_cr_RBUS blue_screen_cr_reg;

	blue_screen_y_reg.regValue = vdcf_inl(VDTOP_BLUE_SCREEN_Y_reg);
	blue_screen_cb_reg.regValue = vdcf_inl(VDTOP_BLUE_SCREEN_CB_reg);
	blue_screen_cr_reg.regValue = vdcf_inl(VDTOP_BLUE_SCREEN_CR_reg);

	if ((blue_screen_y_reg.blue_screen_y != ucY) ||
		(blue_screen_cb_reg.blue_screen_cb != ucCb) ||
		(blue_screen_cr_reg.blue_screen_cr != ucCr)) {
		blue_screen_y_reg.blue_screen_y = ucY;
		blue_screen_cb_reg.blue_screen_cb = ucCb;
		blue_screen_cr_reg.blue_screen_cr = ucCr;
		vdcf_outl(VDTOP_BLUE_SCREEN_Y_reg, blue_screen_y_reg.regValue);
		vdcf_outl(VDTOP_BLUE_SCREEN_CB_reg, blue_screen_cb_reg.regValue);
		vdcf_outl(VDTOP_BLUE_SCREEN_CR_reg, blue_screen_cr_reg.regValue);
	}
}
unsigned char drvif_module_vdc_YcDelay_Get_info(void)
{
	/* 907c[3:0] */
	vdtop_output_control_RBUS output_control_reg;
	output_control_reg.regValue = vdcf_inl(VDTOP_OUTPUT_CONTROL_reg);
	return output_control_reg.yc_delay;
}

/**
   module_vdc_BlueScreenEnable
   enable/disable blue screen

   @param <uselect> { _ENABLE/_DISABLE /_AUTO}
   @return                 { void }

*/
void module_vdc_BlueScreenEnable(VDC_BLUE_SCREEN_MODE uselect)
{
	/* 907c[5:4] */
	vdtop_output_control_RBUS output_control_reg;
	output_control_reg.regValue = vdcf_inl(VDTOP_OUTPUT_CONTROL_reg);
	if (output_control_reg.blue_mode != uselect) {
		output_control_reg.blue_mode = uselect;
		vdcf_outl(VDTOP_OUTPUT_CONTROL_reg, output_control_reg.regValue);
	}
}

bool drvif_module_vdc_read_Clamping_path(void)
{
	/* 9080[3]=1 is ifd, =0 is vd */
	vdtop_inout_ctrl_RBUS vdtop_inout_ctrl_reg;
	vdtop_inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);
	return vdtop_inout_ctrl_reg.sw_tu_cvbs;
}

void drvif_module_vdc_AVout_mode_set(VDC_VIDEO_AVout_Mode mode)
{
	/* 9084[7:5] */
	vdtop_avout_fifo_status_RBUS avout_fifo_status_reg;
	avout_fifo_status_reg.regValue = vdcf_inl(VDTOP_AVOUT_FIFO_STATUS_reg);
	if (avout_fifo_status_reg.avout_mixer_sel != mode) {
		avout_fifo_status_reg.avout_mixer_sel = mode;
		vdcf_outl(VDTOP_AVOUT_FIFO_STATUS_reg, avout_fifo_status_reg.regValue);
	}
}

void drvif_module_vdc_set_PeakWhite(unsigned char on_off)
{
	/* 9094[3] */
	vdtop_agc_peak_and_gate_ctrl_RBUS agc_peak_and_gate_ctrl_reg;
	agc_peak_and_gate_ctrl_reg.regValue = vdcf_inl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg);
	if (agc_peak_and_gate_ctrl_reg.agc_peak_en != on_off) {
		agc_peak_and_gate_ctrl_reg.agc_peak_en = on_off;
		vdcf_outl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg, agc_peak_and_gate_ctrl_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "set peak white : %x", on_off);
	}
}

unsigned int drvif_module_vdc_read_PeakWhite(void)
{
	/* 9094[3] */
	vdtop_agc_peak_and_gate_ctrl_RBUS agc_peak_and_gate_ctrl_reg;
	agc_peak_and_gate_ctrl_reg.regValue = vdcf_inl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg);
	return agc_peak_and_gate_ctrl_reg.agc_peak_en;
}

void drvif_module_vdc_set_Killgate(VDC_KillGate_Control ucKGmode)
{
	/* 9094[4:5] */
	vdtop_agc_peak_and_gate_ctrl_RBUS agc_peak_and_gate_ctrl_reg;
	agc_peak_and_gate_ctrl_reg.regValue =  vdcf_inl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg);
	if (agc_peak_and_gate_ctrl_reg.agc_gate_kill_mode != ucKGmode) {
		agc_peak_and_gate_ctrl_reg.agc_gate_kill_mode = ucKGmode;
		vdcf_outl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg, agc_peak_and_gate_ctrl_reg.regValue);
	}
}

unsigned char drvif_module_vdc_read_Killgate(void)
{
	/* 9094[4:5] */
	vdtop_agc_peak_and_gate_ctrl_RBUS agc_peak_and_gate_ctrl_reg;
	agc_peak_and_gate_ctrl_reg.regValue =  vdcf_inl(VDTOP_AGC_PEAK_AND_GATE_CTRL_reg);
	return agc_peak_and_gate_ctrl_reg.agc_gate_kill_mode;
}

void drvif_module_vdc_set_Control2_Register(VDC_VIDEO_CONTROL2 mode)
{
	/* 909c */
	vdtop_video_control2_RBUS video_control2_reg;
	video_control2_reg.regValue = vdcf_inl(VDTOP_VIDEO_CONTROL2_reg);
	switch (mode) {
	case VDC_CONTROL2_ClearAll:
		video_control2_reg.regValue = 0x00000000;
		break;
	case VDC_hagc_enable:
		video_control2_reg.hagc_en = 1;
		break;
	case VDC_hagc_disable:
		video_control2_reg.hagc_en = 0;
		break;
	case VDC_cagc_enable:
		video_control2_reg.cagc_en = 1;
		break;
	case VDC_cagc_disable:
		video_control2_reg.cagc_en = 0;
		break;
	case VDC_bgate_raw_sel_enable:
		video_control2_reg.bgate_raw_sel = 1;
		break;
	case VDC_bgate_raw_sel_disable:
		video_control2_reg.bgate_raw_sel = 0;
		break;
	case VDC_dc_clamp_mode_auto:
		video_control2_reg.dc_clamp_mode = 0x00;
		break;
	case VDC_dc_clamp_mode_bk_porch:
		video_control2_reg.dc_clamp_mode = 0x01;
		break;
	case VDC_dc_clamp_mode_synctip:
		video_control2_reg.dc_clamp_mode = 0x02;
		break;
	case VDC_dc_clamp_mode_off:
		video_control2_reg.dc_clamp_mode = 0x03;
		break;
	case VDC_mv_hagc_mode_on:
		video_control2_reg.mv_hagc_mode = 1;
		break;
	case VDC_mv_hagc_mode_off:
		video_control2_reg.mv_hagc_mode = 0;
		break;
	case VDC_hagc_field_mode_on:
		video_control2_reg.hagc_field_mode = 1;
		break;
	case VDC_hagc_field_mode_off:
		video_control2_reg.hagc_field_mode = 0;
		break;
	case VDC_fix_dgain_enable:
		video_control2_reg.fix_dgain = 1;
		break;
	case VDC_fix_dgain_disable:
		video_control2_reg.fix_dgain = 0;
		break;
	case VDC_mv_detect_sel_hpll:
		video_control2_reg.mv_detect_sel = 0;
		break;
	case VDC_mv_detect_sel_vpll:
		video_control2_reg.mv_detect_sel = 1;
		break;
	}
	vdcf_outl(VDTOP_VIDEO_CONTROL2_reg, video_control2_reg.regValue);
}

void drvif_module_vdc_Write_Dgain_value(unsigned char value)
{
	/* 90a0[7:0] */
	vdtop_luma_agc_value_RBUS luma_agc_value_reg;
	luma_agc_value_reg.regValue = vdcf_inl(VDTOP_LUMA_AGC_VALUE_reg);
	if (luma_agc_value_reg.hagc != value) {
		luma_agc_value_reg.hagc = value;
		vdcf_outl(VDTOP_LUMA_AGC_VALUE_reg, luma_agc_value_reg.regValue);
	}
}

void module_vdc_Set_Vsync_clamp_mode(VDC_VSYNC_CLAMP_MODE mode)
{
	/* 90c0[7:6] */
	vdtop_vsync_agc_lockout_end_RBUS vsync_agc_lockout_end_reg;
	vsync_agc_lockout_end_reg.regValue = vdcf_inl(VDTOP_VSYNC_AGC_LOCKOUT_END_reg);
	if (vsync_agc_lockout_end_reg.vsync_clamp_mode != mode) {
		vsync_agc_lockout_end_reg.vsync_clamp_mode = mode;
		vdcf_outl(VDTOP_VSYNC_AGC_LOCKOUT_END_reg, vsync_agc_lockout_end_reg.regValue);
	}
}

void module_vdc_Set_clamp_delay(unsigned char on_off, unsigned char ucValue)
{
	/* 90c4[0], 90cc[7:0] */
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg;
	vdtop_charge_pump_delay_RBUS charge_pump_delay_reg;
	charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
	charge_pump_delay_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_reg);

	if ((on_off != charge_pump_delay_control_reg.cpump_delay_en) ||
		(ucValue != charge_pump_delay_reg.cpump_delay)) {
		charge_pump_delay_control_reg.cpump_delay_en = on_off;
		charge_pump_delay_reg.cpump_delay = ucValue;
		vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);
		vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_reg, charge_pump_delay_reg.regValue);
	}
}

void module_vdc_Set_cpump_adjust_delay(unsigned char ucValue)
{
	/* 90c4[7:2]	PAL=0x1a, NTSC=0x27 */
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg;
	charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
	if (charge_pump_delay_control_reg.cpump_adjust_delay != ucValue) {
		charge_pump_delay_control_reg.cpump_adjust_delay = ucValue;
		vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);
	}
}

void module_vdc_Set_cpump_adjustment(unsigned char ucValue)
{
	/* 90c8[7:2]	PAL=0x1a, NTSC=0x27 */
	vdtop_charge_pump_adjustment_RBUS charge_pump_adjustment_reg;
	charge_pump_adjustment_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_ADJUSTMENT_reg);
	if (charge_pump_adjustment_reg.cpump_adjust != ucValue) {
		charge_pump_adjustment_reg.cpump_adjust = ucValue;
		vdcf_outl(VDTOP_CHARGE_PUMP_ADJUSTMENT_reg, charge_pump_adjustment_reg.regValue);
	}
}

void drvif_module_vdc_clamp_rc_rate_function(unsigned char on_off)
{
	/* 90d4[4], enable when co-ch 1/12 */
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	if (new_clampagc_ctrl_reg.new_clamp_rc_rate_en != on_off) {
		new_clampagc_ctrl_reg.new_clamp_rc_rate_en = on_off;
		vdcf_outl(VDTOP_NEW_CLAMPAGC_CTRL_reg, new_clampagc_ctrl_reg.regValue);
	}
}

unsigned char drvif_module_vdc_measure_dc_rough(void)
{
	/* 90d4[5] */
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	return new_clampagc_ctrl_reg.measure_dc_rough;
}

void drvif_module_vdc_Set_Hstate(VDC_VIDEO_FIXHSTATE_MODE value)
{
	/* 9134[5][2:0] */
	vdtop_h_loop_maxstate_RBUS h_loop_maxstate_reg;
	h_loop_maxstate_reg.regValue = vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg);
	h_loop_maxstate_reg.hstate_max = (value & 0x07);
	if ((value & 0x10) == 0x10)
		h_loop_maxstate_reg.hstate_fixed = 1;
	else
		h_loop_maxstate_reg.hstate_fixed = 0;
	vdcf_outl(VDTOP_H_LOOP_MAXSTATE_reg, h_loop_maxstate_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "Set_Hstate : %x, 9134: %x", value, h_loop_maxstate_reg.regValue);
}

VDC_VIDEO_FIXHSTATE_MODE drvif_module_vdc_Read_Hstate_set(void)
{
	/* 9134[5][2:0] */
	unsigned char ucHstate;
	vdtop_h_loop_maxstate_RBUS h_loop_maxstate_reg;
	h_loop_maxstate_reg.regValue = vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg);
	if (h_loop_maxstate_reg.hstate_fixed == 1)
		ucHstate = 0x10;
	else
		ucHstate = 0x00;
	ucHstate = ((ucHstate & 0xf0) | h_loop_maxstate_reg.hstate_max);

	return (VDC_VIDEO_FIXHSTATE_MODE)ucHstate;
}

void module_vdc_set_fine_src_sel(VDC_FINE_SRC_SEL_REG on_off)
{
	/* 9138[7] */
	vdtop_clampagc_ctrl0_RBUS clampagc_ctrl0_reg;
	clampagc_ctrl0_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_CTRL0_reg);
	if (clampagc_ctrl0_reg.fine_src_sel != on_off) {
		clampagc_ctrl0_reg.fine_src_sel = on_off;
		vdcf_outl(VDTOP_CLAMPAGC_CTRL0_reg, clampagc_ctrl0_reg.regValue);
	}
}

void module_vdc_set_Hpll_fine_lock_data_sel(VDC_HPLL_FINE_LOCK_DATA_SEL_REG on_off)
{
	/* 9138[9] */
	vdtop_clampagc_ctrl0_RBUS clampagc_ctrl0_reg;
	clampagc_ctrl0_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_CTRL0_reg);
	if (clampagc_ctrl0_reg.hpll_fine_lock_data_sel != on_off) {
		clampagc_ctrl0_reg.hpll_fine_lock_data_sel = on_off;
		vdcf_outl(VDTOP_CLAMPAGC_CTRL0_reg, clampagc_ctrl0_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "module_vdc_set_Hpll_fine_lock_data_sel = %x\n", on_off);
	}
}

VDC_HPLL_FINE_LOCK_DATA_SEL_REG module_vdc_read_Hpll_fine_lock_data_sel(void)
{
	/* 9138[9] */
	vdtop_clampagc_ctrl0_RBUS clampagc_ctrl0_reg;
	clampagc_ctrl0_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_CTRL0_reg);
	return (VDC_HPLL_FINE_LOCK_DATA_SEL_REG) clampagc_ctrl0_reg.hpll_fine_lock_data_sel;
}

void module_vdc_set_hstate_error_method(VDC_HSTATE_ERROR_METHOD_REG on_off)
{
	/* 9138[13] */
	vdtop_clampagc_ctrl0_RBUS clampagc_ctrl0_reg;
	clampagc_ctrl0_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_CTRL0_reg);
	if (clampagc_ctrl0_reg.hstate_ignore_err != on_off) {
		clampagc_ctrl0_reg.hstate_ignore_err = on_off;
		vdcf_outl(VDTOP_CLAMPAGC_CTRL0_reg, clampagc_ctrl0_reg.regValue);
	}
}

void drvif_module_vdc_clampagc_new_sync_start(unsigned char ucstart)
{
	/* 913c[6:0] */
	vdtop_clampagc_new_sync_start_RBUS CLAMPAGC_NEW_SYNC_START_reg;
	CLAMPAGC_NEW_SYNC_START_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_NEW_SYNC_START_reg);
	if (CLAMPAGC_NEW_SYNC_START_reg.coarse_sync_start != (ucstart & 0x7f)) {
		CLAMPAGC_NEW_SYNC_START_reg.coarse_sync_start = ucstart & 0x7f;
		vdcf_outl(VDTOP_CLAMPAGC_NEW_SYNC_START_reg, CLAMPAGC_NEW_SYNC_START_reg.regValue);
	}
}

void drvif_module_vdc_clampagc_new_sync_end(unsigned char ucend)
{
	/* 9140[7:0] */
	vdtop_clampagc_new_sync_end_RBUS CLAMPAGC_NEW_SYNC_END_reg;
	CLAMPAGC_NEW_SYNC_END_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_NEW_SYNC_END_reg);
	if (CLAMPAGC_NEW_SYNC_END_reg.coarse_sync_end != (ucend & 0xff)) {
		CLAMPAGC_NEW_SYNC_END_reg.coarse_sync_end = ucend & 0xff;
		vdcf_outl(VDTOP_CLAMPAGC_NEW_SYNC_END_reg, CLAMPAGC_NEW_SYNC_END_reg.regValue);
	}
}

unsigned char drvif_module_vdc_read_Hsync_start(void)
{
	/* 916c[7:0] */
	vdtop_hsync_pulse_start_RBUS hsync_pulse_start_reg;
	hsync_pulse_start_reg.regValue = vdcf_inl(VDTOP_HSYNC_PULSE_START_reg);
	return hsync_pulse_start_reg.hsync_start;
}

void drvif_module_vdc_set_Hsync_start(unsigned char value)
{
	/* 916c[7:0] */
	vdtop_hsync_pulse_start_RBUS hsync_pulse_start_reg;
	hsync_pulse_start_reg.regValue = vdcf_inl(VDTOP_HSYNC_PULSE_START_reg);
	if (hsync_pulse_start_reg.hsync_start != value) {
		hsync_pulse_start_reg.hsync_start = value;
		vdcf_outl(VDTOP_HSYNC_PULSE_START_reg, hsync_pulse_start_reg.regValue);
	}
}

VDC_SECOND_PLL_ENABLE_REG drvif_module_vdc_read_second_pll_status(void)
{
	/* 91a8[0] */
	vdtop_second_pll_gain_RBUS second_pll_gain_reg;
	second_pll_gain_reg.regValue = vdcf_inl(VDTOP_Second_pll_gain_reg);
	return (VDC_SECOND_PLL_ENABLE_REG)second_pll_gain_reg.second_pll_en;
}

void drvif_module_vdc_set_second_pll(VDC_SECOND_PLL_ENABLE_REG on_off)
{
	/* 91a8[0][9:8], 90d4[6] */
	vdtop_second_pll_gain_RBUS second_pll_gain_reg;
	vdtop_new_clampagc_ctrl_RBUS new_clampagc_ctrl_reg;
	second_pll_gain_reg.regValue = vdcf_inl(VDTOP_Second_pll_gain_reg);
	new_clampagc_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_CLAMPAGC_CTRL_reg);
	if (second_pll_gain_reg.second_pll_en != on_off) {
		second_pll_gain_reg.second_pll_en = on_off;
		second_pll_gain_reg.second_pll_level_sel = 2;
		new_clampagc_ctrl_reg.dgain_ignore_fine_lock = on_off;
		vdcf_outl(VDTOP_Second_pll_gain_reg, second_pll_gain_reg.regValue);
		vdcf_outl(VDTOP_NEW_CLAMPAGC_CTRL_reg, new_clampagc_ctrl_reg.regValue);
	}
}

unsigned int module_vdc_read_Second_Dgain(void)
{
	/* 91b4[11:0] */
	vdtop_second_pll_gain3_RBUS second_pll_gain3_reg;
	second_pll_gain3_reg.regValue =  vdcf_inl(VDTOP_Second_pll_gain3_reg);
	return second_pll_gain3_reg.second_dgain;
}

void drvif_module_vdc_hsync_rising_start(unsigned char ucstart)
{
	/* 91e8[7:0] */
	vdtop_hsync_rising_start_RBUS HSYNC_RISING_START_reg;
	HSYNC_RISING_START_reg.regValue = vdcf_inl(VDTOP_HSYNC_RISING_START_reg);
	if (HSYNC_RISING_START_reg.hsync_rising_start != ucstart) {
		HSYNC_RISING_START_reg.hsync_rising_start = ucstart;
		vdcf_outl(VDTOP_HSYNC_RISING_START_reg, HSYNC_RISING_START_reg.regValue);
	}
}

void drvif_module_vdc_hsync_rising_end(unsigned char ucend)
{
	/* 91ec[7:0] */
	vdtop_hsync_rising_end_RBUS HSYNC_RISING_END_reg;
	HSYNC_RISING_END_reg.regValue = vdcf_inl(VDTOP_HSYNC_RISING_END_reg);
	if (HSYNC_RISING_END_reg.hsync_rising_end != ucend) {
		HSYNC_RISING_END_reg.hsync_rising_end = ucend;
		vdcf_outl(VDTOP_HSYNC_RISING_END_reg, HSYNC_RISING_END_reg.regValue);
	}
}

void module_vdc_set_Hblank_start(unsigned char value)
{
	/* 91f8[7:0] */
	vdtop_hblank_start_RBUS hblank_start_reg;
	hblank_start_reg.regValue = vdcf_inl(VDTOP_HBLANK_START_reg);
	if (hblank_start_reg.hblank_start != value) {
		hblank_start_reg.hblank_start = value;
		vdcf_outl(VDTOP_HBLANK_START_reg, hblank_start_reg.regValue);
	}
}

#if 0//merage from mac5p
void drvif_module_vdc_set_burst_gate_position(unsigned char mode)
{
	/* 9200[7:0], 9204[7:0] */
	vdtop_burst_gate_start_RBUS burst_gate_start_reg;
	vdtop_burst_gate_end_RBUS    burst_gate_end_reg;
	burst_gate_start_reg.regValue = vdcf_inl(VDTOP_BURST_GATE_START_reg);
	burst_gate_end_reg.regValue = vdcf_inl(VDTOP_BURST_GATE_END_reg);

	switch (mode) {
	default:
		if ((burst_gate_start_reg.burst_gate_start != 0x32) ||
			(burst_gate_end_reg.burst_gate_end != 0x46)) {
			burst_gate_start_reg.burst_gate_start = 0x32;
			burst_gate_end_reg.burst_gate_end = 0x46;
			vdcf_outl(VDTOP_BURST_GATE_START_reg, burst_gate_start_reg.regValue);
			vdcf_outl(VDTOP_BURST_GATE_END_reg, burst_gate_end_reg.regValue);
		}
		break;
	case VDC_MODE_SECAM:
		if ((burst_gate_start_reg.burst_gate_start != 0x50) ||
			(burst_gate_end_reg.burst_gate_end != 0x64)) {
			burst_gate_start_reg.burst_gate_start = 0x50;
			burst_gate_end_reg.burst_gate_end = 0x64;
			vdcf_outl(VDTOP_BURST_GATE_START_reg, burst_gate_start_reg.regValue);
			vdcf_outl(VDTOP_BURST_GATE_END_reg, burst_gate_end_reg.regValue);
		}
		break;
	}
}
#endif//merage from mac5p

void drvif_module_vdc_cpll_reset(void)
{
	/* 9218[9] */
	vdtop_cstate_status_RBUS vdtop_cstate_status_reg;
	vdtop_cstate_status_reg.regValue = vdcf_inl(VDTOP_CSTATE_STATUS_reg);
	vdtop_cstate_status_reg.cpll_cgain_reset_en = 1;
	vdcf_outl(VDTOP_CSTATE_STATUS_reg, vdtop_cstate_status_reg.regValue);
	mdelay(1);
	vdtop_cstate_status_reg.cpll_cgain_reset_en = 0;
	vdcf_outl(VDTOP_CSTATE_STATUS_reg, vdtop_cstate_status_reg.regValue);
}

void module_vdc_set_gate_hv_iir(unsigned char mode)
{
	/* 921c = 0x04 default: enable new_hpll_lpf_sel */
	vdtop_hdetect_gate_ctrl_RBUS hdetect_gate_ctrl_reg;
	hdetect_gate_ctrl_reg.regValue = vdcf_inl(VDTOP_HDETECT_GATE_CTRL_reg);
	hdetect_gate_ctrl_reg.new_hpll_lpf_sel = (mode & _BIT2) >> 2;
	hdetect_gate_ctrl_reg.gate_iir_h_sel = (mode & _BIT1) >> 1;;
	hdetect_gate_ctrl_reg.gate_iir_v_sel = mode & _BIT0;
	vdcf_outl(VDTOP_HDETECT_GATE_CTRL_reg, hdetect_gate_ctrl_reg.regValue);
}

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
unsigned char drvif_module_vdc_read_vphasediff_status(void)
{
	/* 922c[7:0] */
	vdtop_hdetect_vphasediff_status_RBUS hdetect_vphasediff_status_reg;
	hdetect_vphasediff_status_reg.regValue = vdcf_inl(VDTOP_HDETECT_VPHASEDIFF_STATUS_reg);
	return hdetect_vphasediff_status_reg.vphasediff_status;
}
#endif

void module_vdc_set_hstate_error01_thl(unsigned char value)
{
	/* 922c[15:8] */
	vdtop_hdetect_vphasediff_status_RBUS hdetect_vphasediff_status_reg;
	hdetect_vphasediff_status_reg.regValue = vdcf_inl(VDTOP_HDETECT_VPHASEDIFF_STATUS_reg);
	if (hdetect_vphasediff_status_reg.hdetect_err01_th != value) {
		hdetect_vphasediff_status_reg.hdetect_err01_th = value;
		vdcf_outl(VDTOP_HDETECT_VPHASEDIFF_STATUS_reg, hdetect_vphasediff_status_reg.regValue);
	}
}

bool drvif_module_vdc_read_coch_detect_status(void)
{
	/* 9234[7] */
	vdtop_vbi_co_ch_ctrl0_RBUS vbi_co_ch_ctrl0_reg;
	vbi_co_ch_ctrl0_reg.regValue = vdcf_inl(VDTOP_VBI_CO_CH_CTRL0_reg);
	return vbi_co_ch_ctrl0_reg.coch_detected_status;
}

bool module_vdc_read_Wrong_if_pc_detect_flag(void)
{
	/* 9260[0] */
	vdtop_if_wrong_pc_RBUS vdtop_if_wrong_pc_reg;
	vdtop_if_wrong_pc_reg.regValue = vdcf_inl(VDTOP_IF_WRONG_PC_reg);
	return vdtop_if_wrong_pc_reg.wrong_if_pc_detect;
}

void drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_Vsync_Output_Mode mode)
{
	/* 9300[7:6] */
	vdtop_vsync_cntl_RBUS vsync_cntl_reg;
	vsync_cntl_reg.regValue = vdcf_inl(VDTOP_VSYNC_CNTL_reg);
	if (vsync_cntl_reg.vsync_cntl != mode) {
		vsync_cntl_reg.vsync_cntl = mode;
		vdcf_outl(VDTOP_VSYNC_CNTL_reg, vsync_cntl_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "Vsync_Cntl_Mode : %x\n", mode);
	}
}

VDC_Vsync_Output_Mode drvif_module_vdc_read_Vsync_Cntl_Mode(void)
{
	/* 9300[7:6] */
	vdtop_vsync_cntl_RBUS vsync_cntl_reg;
	vsync_cntl_reg.regValue = vdcf_inl(VDTOP_VSYNC_CNTL_reg);
	return (VDC_Vsync_Output_Mode)vsync_cntl_reg.vsync_cntl;
}

/**
   drvif_module_vdc_vloop_conrtol
   control the vloop speed
   @param <void>       { mode =speed 0(slow)~~5(fast)}
   @return                  { void }

*/
void  drvif_module_vdc_vloop_control_set(VDC_Vloop_Control value)
{
	/* 9304[1:0], 9308[6:0], 930c[7:0], 93bc[3] */
	vdtop_vsync_time_const_RBUS vsync_time_cont_reg;
	vdtop_vsync_time_const1_RBUS vsync_time_cont1_reg;
	vdtop_vsync_time_const2_RBUS vsync_time_cont2_reg;
	vdtop_vloop0_tc1_RBUS vloop0_tc1_reg;
	vdtop_vloop0_tc2_RBUS vloop0_tc2_reg;
	vdtop_vloop2_tc1_RBUS vloop2_tc1_reg;
	vdtop_vloop2_tc2_RBUS vloop2_tc2_reg;
	vdtop_vloop_tc3_RBUS vloop_tc3_reg;
	vdtop_vloop3_tc1_RBUS vloop3_tc1_reg;
	vdtop_vloop3_tc2_RBUS vloop3_tc2_reg;
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vdtop_vstate_ctrl1_RBUS vstate_ctrl1_reg;

	vsync_time_cont_reg.regValue = vdcf_inl(VDTOP_VSYNC_TIME_CONST_reg);
	vsync_time_cont1_reg.regValue = vdcf_inl(VDTOP_VSYNC_TIME_CONST1_reg);
	vsync_time_cont2_reg.regValue = vdcf_inl(VDTOP_VSYNC_TIME_CONST2_reg);
	vloop0_tc1_reg.regValue = vdcf_inl(VDTOP_VLOOP0_TC1_reg);
	vloop0_tc2_reg.regValue = vdcf_inl(VDTOP_VLOOP0_TC2_reg);
	vloop2_tc1_reg.regValue = vdcf_inl(VDTOP_VLOOP2_TC1_reg);
	vloop2_tc2_reg.regValue = vdcf_inl(VDTOP_VLOOP2_TC2_reg);
	vloop_tc3_reg.regValue = vdcf_inl(VDTOP_VLOOP_TC3_reg);
	vloop3_tc1_reg.regValue = vdcf_inl(VDTOP_VLOOP3_TC1_reg);
	vloop3_tc2_reg.regValue = vdcf_inl(VDTOP_VLOOP3_TC2_reg);
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	vstate_ctrl1_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL1_reg);

	switch (value) {
	case VDC_vloop_DEFAULT:
	case VDC_vloop_speed0:
		/* default setting */
		vsync_time_cont1_reg.vloop_tc1 = 0x80;	// 930C[7:0]
		vsync_time_cont2_reg.vloop_tc2 = 0x10;	// 9308[6:0]
		vsync_time_cont_reg.vloop_tc3 = 0x02;	// 9304[1:0]

		vloop2_tc1_reg.vloop2_tc1 = 0x10;	// 93c8[7:0]
		vloop2_tc2_reg.vloop2_tc2 = 0x02;	// 93cc[6:0]
		vloop_tc3_reg.vloop2_tc3 = 0x02;	// 93d8[3:2]

		vloop0_tc1_reg.vloop0_tc1 = 0x80;	// 93c0[7:0]
		vloop0_tc2_reg.vloop0_tc2 = 0x08;	// 93c4[6:0]
		vloop_tc3_reg.vloop0_tc3 = 0x02;	// 93d8[5:4]

		vloop_tc3_reg.vloop3_tc3 = 0x02;	// 93d8[1:0]
		vloop3_tc1_reg.vloop3_tc1 = 0x00;	// 93d0[7:0]
		vloop3_tc2_reg.vloop3_tc2= 0x00;	// 93d4[15:8]

		vloop0_tc1_reg.vstate3_counter_num = 0x0f;	// 93c0[7:0]

		vstate_ctrl1_reg.vstate_2to3_th = 0x04;	/* 93b4[31:24] = 0x1f=>0x4 */
		vstate_ctrl1_reg.vstate_back1_er = 0x0e;	/* 93b4[3:0] = 0xe */
		vstate_ctrl0_reg.vstate_2to3_er = 0x01;	/* 93b0[3:0] = 0x5=>0x3=>0x1 */
		break;
	case VDC_vloop_speed1:	/* for TV source */
		/* clifferd modify 20130918 : state1&2 should set same otherwise state2 maybe back to state1 */
		vsync_time_cont1_reg.vloop_tc1 = 0x60;	// 930C[7:0]	/*state1 */
		vsync_time_cont2_reg.vloop_tc2 = 0x10;	// 9308[6:0]
		vsync_time_cont_reg.vloop_tc3 = 0x02;	// 9304[1:0]

		vloop2_tc1_reg.vloop2_tc1 = 0x60;	// 93c8[7:0]	/*state2 */
		vloop2_tc2_reg.vloop2_tc2 = 0x10;	// 93cc[6:0]
		vloop_tc3_reg.vloop2_tc3 = 0x02;	// 93d8[3:2]

		vloop0_tc1_reg.vloop0_tc1 = 0x80;	// 93c0[7:0]
		vloop0_tc2_reg.vloop0_tc2 = 0x08;	// 93c4[6:0]
		vloop_tc3_reg.vloop0_tc3 = 0x00;	// 93d8[5:4]

		vloop_tc3_reg.vloop3_tc3 = 0x02;	// 93d8[1:0]
		vloop3_tc1_reg.vloop3_tc1 = 0x00;	// 93d0[7:0]
		vloop3_tc2_reg.vloop3_tc2= 0x00;	// 93d4[6:0]

		vloop0_tc1_reg.vstate3_counter_num = 0x0f;	// 93c0[7:0]

		vstate_ctrl1_reg.vstate_2to3_th = 0x04;	/* 93b4[31:24] = 0x1f=>0x4 */
		vstate_ctrl1_reg.vstate_back1_er = 0x0e;	/* 93b4[3:0] = 0xe */
		vstate_ctrl0_reg.vstate_2to3_er = 0x01;	/* 93b0[3:0] = 0x5=>0x3=>0x1 */
		break;
	case VDC_vloop_FAST:		/* for AV source */
		vsync_time_cont1_reg.vloop_tc1 = 0xb0;	// 930C[7:0]
		vsync_time_cont2_reg.vloop_tc2 = 0x70;	// 9308[6:0]
		vsync_time_cont_reg.vloop_tc3 = 0x02;	// 9304[1:0]

		vloop2_tc1_reg.vloop2_tc1 = 0x50;	// 93c8[7:0]
		vloop2_tc2_reg.vloop2_tc2 = 0x32;	// 93cc[6:0]
		vloop_tc3_reg.vloop2_tc3 = 0x02;	// 93d8[3:2]

		vloop0_tc1_reg.vloop0_tc1 = 0xa0;	// 93c0[7:0]
		vloop0_tc2_reg.vloop0_tc2 = 0x00;	// 93c4[6:0]
		vloop_tc3_reg.vloop0_tc3 = 0x02;	// 93d8[5:4]

		vloop_tc3_reg.vloop3_tc3 = 0x02;	// 93d8[1:0]
		vloop3_tc1_reg.vloop3_tc1 = 0x00;	// 93d0[7:0]
		vloop3_tc2_reg.vloop3_tc2= 0x00;	// 93d4[6:0]

		vloop0_tc1_reg.vstate3_counter_num = 0x0a;	// 93c0[7:0]

		vstate_ctrl1_reg.vstate_2to3_th = 0x1f;	/* 93b4[31:24] = 0x1f */
		vstate_ctrl1_reg.vstate_back1_er = 0x03;	/* 93b4[3:0] = 0x3 */
		vstate_ctrl0_reg.vstate_2to3_er = 0x05;		/* 93b0[3:0] = 0x5 */
		break;
	}

	vdcf_outl(VDTOP_VSYNC_TIME_CONST_reg, vsync_time_cont_reg.regValue);
	vdcf_outl(VDTOP_VSYNC_TIME_CONST1_reg, vsync_time_cont1_reg.regValue);
	vdcf_outl(VDTOP_VSYNC_TIME_CONST2_reg, vsync_time_cont2_reg.regValue);
	vdcf_outl(VDTOP_VLOOP0_TC1_reg, vloop0_tc1_reg.regValue);
	vdcf_outl(VDTOP_VLOOP0_TC2_reg, vloop0_tc2_reg.regValue);
	vdcf_outl(VDTOP_VLOOP2_TC1_reg, vloop2_tc1_reg.regValue);
	vdcf_outl(VDTOP_VLOOP2_TC2_reg, vloop2_tc2_reg.regValue);
	vdcf_outl(VDTOP_VLOOP_TC3_reg, vloop_tc3_reg.regValue);
	vdcf_outl(VDTOP_VLOOP3_TC1_reg, vloop3_tc1_reg.regValue);
	vdcf_outl(VDTOP_VLOOP3_TC2_reg, vloop3_tc2_reg.regValue);
	vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	vdcf_outl(VDTOP_VSTATE_CTRL1_reg, vstate_ctrl1_reg.regValue);
}

void drvif_module_vdc_set_noSignalCounter_Value(unsigned char value)
{
	/* 9314[2:0] */
	vdtop_no_signal_dec_RBUS no_signal_dec_reg;
	no_signal_dec_reg.regValue = vdcf_inl(VDTOP_NO_SIGNAL_DEC_reg);
	if (no_signal_dec_reg.no_signal_dec != (value & 0x07)) {
		no_signal_dec_reg.no_signal_dec = value & 0x07;
		vdcf_outl(VDTOP_NO_SIGNAL_DEC_reg, no_signal_dec_reg.regValue);
	}
}

void drvif_module_vdc_set_hlock_field_cnt_Value(unsigned char value)
{
	/* 9314[23:20] */
	vdtop_no_signal_dec_RBUS no_signal_dec_reg;
	no_signal_dec_reg.regValue = vdcf_inl(VDTOP_NO_SIGNAL_DEC_reg);
	if (no_signal_dec_reg.hlock_field_cnt != (value & 0x0f)) {
		no_signal_dec_reg.hlock_field_cnt = value & 0x0f;
		vdcf_outl(VDTOP_NO_SIGNAL_DEC_reg, no_signal_dec_reg.regValue);
	}
}


void module_vdc_set_Vactive_position(unsigned char ucStart, unsigned char ucHeight)
{
	/* 9318[7:0], 931c[7:0] */
	vdtop_vactive_start_RBUS vactive_start_reg;
	vdtop_vactive_height_RBUS vactive_hight_reg;
	vactive_start_reg.regValue = vdcf_inl(VDTOP_VACTIVE_START_reg);
	vactive_hight_reg.regValue = vdcf_inl(VDTOP_VACTIVE_HEIGHT_reg);
	if ((vactive_start_reg.vactive_start != ucStart) ||
		(vactive_hight_reg.vactive_height != ucHeight))

	{
		vactive_start_reg.vactive_start = ucStart;
		vactive_hight_reg.vactive_height = ucHeight;
		vdcf_outl(VDTOP_VACTIVE_START_reg, vactive_start_reg.regValue);
		vdcf_outl(VDTOP_VACTIVE_HEIGHT_reg, vactive_hight_reg.regValue);
	}
}

void module_vdc_set_vsync_h_max(unsigned char ucValue)
{
	/* 9324[6:0] */
	vdtop_vsync_h_max_RBUS vsync_h_max_reg;
	vsync_h_max_reg.regValue = vdcf_inl(VDTOP_VSYNC_H_MAX_reg);
	if (vsync_h_max_reg.vsync_h_max != ucValue) {
		vsync_h_max_reg.vsync_h_max = ucValue;
		vdcf_outl(VDTOP_VSYNC_H_MAX_reg, vsync_h_max_reg.regValue);
	}
}

void drvif_module_vdc_27M_FrontDigitalFilterEnable(VDC_VIDEO_27M_FrontDigitalFilter mode)
{
	/* 934c[3:1] */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	if (sync_midpt_v2_reg.adc_lpf_sel != mode) {
		sync_midpt_v2_reg.adc_lpf_sel = mode;
		vdcf_outl(VDTOP_SYNC_MIDPT_V2_reg, sync_midpt_v2_reg.regValue);
	}
}

unsigned char drvif_module_vdc_Read_27M_FrontDigitalFilter_info(void)
{
	/* 934c[3:1] */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	return sync_midpt_v2_reg.adc_lpf_sel;
}

void drvif_module_vdc_Vdetcet_pattern_sel(unsigned char pattern)
{
	/* 934c[7:6] */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	if (sync_midpt_v2_reg.vdetect_pattern_sel != pattern) {
		sync_midpt_v2_reg.vdetect_pattern_sel = pattern;
		vdcf_outl(VDTOP_SYNC_MIDPT_V2_reg, sync_midpt_v2_reg.regValue);
	}
}

bool drvif_module_vdc_read_Vlock_sel_status(void)
{
	/* 934c[8] */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	return sync_midpt_v2_reg.vlock_sel;
}

void drvif_module_vdc_Raw_vdetect_max_sel(unsigned char mode)
{
	/* 934c[17:16], vdetect set to blank level and sync level */
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	if (sync_midpt_v2_reg.raw_vdetect_max_sel != mode) {
		sync_midpt_v2_reg.raw_vdetect_max_sel = mode;
		vdcf_outl(VDTOP_SYNC_MIDPT_V2_reg, sync_midpt_v2_reg.regValue);
	}
}

void drvif_module_vdc_adc_27M_LPF_coef_Table(VDC_VIDEO_27M_LPF_COEF mode)
{
	/* 9350 ~ 9364 */
	vdtop_adc_27_lpf_coef_1_RBUS adc_27_lpf_coef_1_reg;
	vdtop_adc_27_lpf_coef_2_RBUS adc_27_lpf_coef_2_reg;
	vdtop_adc_27_lpf_coef_3_RBUS adc_27_lpf_coef_3_reg;
	vdtop_adc_27_lpf_coef_4_RBUS adc_27_lpf_coef_4_reg;
	vdtop_adc_27_lpf_coef_5_RBUS adc_27_lpf_coef_5_reg;
	vdtop_adc_27_lpf_coef_6_RBUS adc_27_lpf_coef_6_reg;
	adc_27_lpf_coef_1_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_1_reg);
	adc_27_lpf_coef_2_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_2_reg);
	adc_27_lpf_coef_3_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_3_reg);
	adc_27_lpf_coef_4_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_4_reg);
	adc_27_lpf_coef_5_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_5_reg);
	adc_27_lpf_coef_6_reg.regValue = vdcf_inl(VDTOP_ADC_27_LPF_COEF_6_reg);

	switch (mode) {
	case VDC_27M_LPF_43MHz:
		adc_27_lpf_coef_1_reg.adc_lpf_coef1 = 0x3f9;
		adc_27_lpf_coef_1_reg.adc_lpf_coef2 = 0x010;
		adc_27_lpf_coef_2_reg.adc_lpf_coef3 = 0x00c;
		adc_27_lpf_coef_2_reg.adc_lpf_coef4 = 0x005;
		adc_27_lpf_coef_3_reg.adc_lpf_coef5 = 0x3fb;
		adc_27_lpf_coef_3_reg.adc_lpf_coef6 = 0x3f7;
		adc_27_lpf_coef_4_reg.adc_lpf_coef7 = 0x3fd;
		adc_27_lpf_coef_4_reg.adc_lpf_coef8 = 0x007;
		adc_27_lpf_coef_5_reg.adc_lpf_coef9 = 0x00c;
		adc_27_lpf_coef_5_reg.adc_lpf_coefa = 0x006;
		adc_27_lpf_coef_6_reg.adc_lpf_coefb = 0x3fb;
		adc_27_lpf_coef_6_reg.adc_lpf_coefc = 0x1d0;
		break;
	case VDC_27M_LPF_40MHz:
		adc_27_lpf_coef_1_reg.adc_lpf_coef1 = 0x005;
		adc_27_lpf_coef_1_reg.adc_lpf_coef2 = 0x008;
		adc_27_lpf_coef_2_reg.adc_lpf_coef3 = 0x007;
		adc_27_lpf_coef_2_reg.adc_lpf_coef4 = 0x3fe;
		adc_27_lpf_coef_3_reg.adc_lpf_coef5 = 0x3f1;
		adc_27_lpf_coef_3_reg.adc_lpf_coef6 = 0x3e6;
		adc_27_lpf_coef_4_reg.adc_lpf_coef7 = 0x3e7;
		adc_27_lpf_coef_4_reg.adc_lpf_coef8 = 0x3fc;
		adc_27_lpf_coef_5_reg.adc_lpf_coef9 = 0x024;
		adc_27_lpf_coef_5_reg.adc_lpf_coefa = 0x053;
		adc_27_lpf_coef_6_reg.adc_lpf_coefb = 0x079;
		adc_27_lpf_coef_6_reg.adc_lpf_coefc = 0x088;
		break;
	default:
	case VDC_27M_LPF_Default:
		adc_27_lpf_coef_1_reg.adc_lpf_coef1 = 0x002;
		adc_27_lpf_coef_1_reg.adc_lpf_coef2 = 0x001;
		adc_27_lpf_coef_2_reg.adc_lpf_coef3 = 0x3fb;
		adc_27_lpf_coef_2_reg.adc_lpf_coef4 = 0x3f7;
		adc_27_lpf_coef_3_reg.adc_lpf_coef5 = 0x001;
		adc_27_lpf_coef_3_reg.adc_lpf_coef6 = 0x011;
		adc_27_lpf_coef_4_reg.adc_lpf_coef7 = 0x009;
		adc_27_lpf_coef_4_reg.adc_lpf_coef8 = 0x3e5;
		adc_27_lpf_coef_5_reg.adc_lpf_coef9 = 0x3db;
		adc_27_lpf_coef_5_reg.adc_lpf_coefa = 0x023;
		adc_27_lpf_coef_6_reg.adc_lpf_coefb = 0x09f;
		adc_27_lpf_coef_6_reg.adc_lpf_coefc = 0x0dc;
		break;
	}

	vdcf_outl(VDTOP_ADC_27_LPF_COEF_1_reg, adc_27_lpf_coef_1_reg.regValue);
	vdcf_outl(VDTOP_ADC_27_LPF_COEF_2_reg, adc_27_lpf_coef_2_reg.regValue);
	vdcf_outl(VDTOP_ADC_27_LPF_COEF_3_reg, adc_27_lpf_coef_3_reg.regValue);
	vdcf_outl(VDTOP_ADC_27_LPF_COEF_4_reg, adc_27_lpf_coef_4_reg.regValue);
	vdcf_outl(VDTOP_ADC_27_LPF_COEF_5_reg, adc_27_lpf_coef_5_reg.regValue);
	vdcf_outl(VDTOP_ADC_27_LPF_COEF_6_reg, adc_27_lpf_coef_6_reg.regValue);
}

void module_vdc_set_no_vsyncflag_back1(unsigned char on_off)
{
	/* 936c[2] */
	vdtop_vdetect_window_ctrl_RBUS vdetect_window_ctrl_reg;
	vdetect_window_ctrl_reg.regValue = vdcf_inl(VDTOP_VDETECT_WINDOW_CTRL_reg);
	if (vdetect_window_ctrl_reg.no_vsync_flag_en != on_off) {
		vdetect_window_ctrl_reg.no_vsync_flag_en = on_off;       /*936c[2]= disable fix Vstate=1 while new Vdetect fail. */
		vdcf_outl(VDTOP_VDETECT_WINDOW_CTRL_reg, vdetect_window_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_new_vdetect_Enable(VDC_NEW_VDETECT_ENABLE_REG mode)
{
	/* 9374[7] */
	vdtop_new_vdetect_ctrl_RBUS new_vdetect_ctrl_reg;
	new_vdetect_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_VDETECT_CTRL_reg);
	if (new_vdetect_ctrl_reg.new_vdetect_en != mode) {
		new_vdetect_ctrl_reg.new_vdetect_en = mode;
		vdcf_outl(VDTOP_NEW_VDETECT_CTRL_reg, new_vdetect_ctrl_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "new v set %x\n ", mode);
	}
}

void module_vdc_set_vsync_refind_enable(unsigned char on_off)
{
	/* 93b0[8][13:12] */
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	if ((vstate_ctrl0_reg.vsync_refind != on_off) ||
		(vstate_ctrl0_reg.vsync_refind_con_sel != 3)) {
		vstate_ctrl0_reg.vsync_refind_con_sel = 3;
		vstate_ctrl0_reg.vsync_refind = on_off;
		vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	}
}

void module_vdc_set_vstate0_direct_vsync_enable(unsigned char on_off)
{
	/* 93b0[28] */
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	if (on_off != vstate_ctrl0_reg.vstate0_direct_vsync) {
		vstate_ctrl0_reg.vstate0_direct_vsync = on_off;
		vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	}
}

void module_vdc_set_vsync_refind_sel(unsigned char mode)
{
	/* 93b0[31:30] */
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	if (vstate_ctrl0_reg.vsync_refind_sel != mode) {
		vstate_ctrl0_reg.vsync_refind_sel = mode;
		vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	}
}

void drvif_module_vdc_set_vstate_new2to3_en(unsigned char on_off)
{
	/* 93b4[23] */
	vdtop_vstate_ctrl1_RBUS vstate_ctrl1_reg;
	vstate_ctrl1_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL1_reg);
	if (vstate_ctrl1_reg.vstate_new2to3_en != on_off) {
		vstate_ctrl1_reg.vstate_new2to3_en = on_off;
		vdcf_outl(VDTOP_VSTATE_CTRL1_reg, vstate_ctrl1_reg.regValue);
	}
}

void drvif_module_vdc_Set_Vstate(VDC_VIDEO_FIXVSTATE_MODE value)
{
	/*93bc[3][2:1] */
	vdtop_vstate_ctrl3_RBUS vstate_ctrl3_reg;
	vstate_ctrl3_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL3_reg);
	vstate_ctrl3_reg.vstate_sw = value&0x0f;
	vstate_ctrl3_reg.vstate_sw_en = (value&0x10)>>4;
	vdcf_outl(VDTOP_VSTATE_CTRL3_reg, vstate_ctrl3_reg.regValue);
}

unsigned char drvif_module_vdc_Read_Vstate(void)
{
	/*93bc[5:4] */
	vdtop_vstate_ctrl3_RBUS vstate_ctrl3_reg;
	vstate_ctrl3_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL3_reg);
	return vstate_ctrl3_reg.vstate_status;
}

unsigned char drvif_module_vdc_CKill_status(void)
{
	/* 93dc[6],[5],[4] */
	unsigned char ucStatus;
	vdtop_vlock_count_RBUS vlock_count_reg;
	vlock_count_reg.regValue = vdcf_inl(VDTOP_VLOCK_COUNT_reg);
	ucStatus = (vlock_count_reg.flag_cgain_too_big_kill) || (vlock_count_reg.flag_chrmaunlock_kill)
			   || (vlock_count_reg.flag_user_kill);
	return ucStatus;
}

unsigned short drvif_module_vdc_Read_Vline_out(void)
{
	/* 93f4[9:0] freerun vlines */
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	return vsync_pll_freerun_mux_reg.vlines_freerun;
}

bool drvif_module_vdc_Read_Vline_freerun_status(void)
{
	/* 93f4[12]=1 : Vlines_diff_flag = 0, vsync from input = 1, vsync is freerun */
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	return vsync_pll_freerun_mux_reg.vlines_diff_flag;
}

void drvif_module_vdc_set_vsync_freerun_enable(unsigned char on_off)
{
	/* 93f4[14] */
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	if (vsync_pll_freerun_mux_reg.vsync_freerun_when_unstable_en != on_off) {
		vsync_pll_freerun_mux_reg.vsync_freerun_when_unstable_en = on_off;
		vdcf_outl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg, vsync_pll_freerun_mux_reg.regValue);
	}
}

bool drvif_module_vdc_read_vsync_freerun_enable(void)
{
	/* 93f4[14] */
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	return vsync_pll_freerun_mux_reg.vsync_freerun_when_unstable_en;
}

/*
   drvif_module_vdc_Set_CKill_Value
   drv_module_vdc_ReadCKillValue
   Set / read saturation

   @param <ucValue>  { Set chroma kill value }
   @return                   { chroma kill value }

*/
void drvif_module_vdc_Set_CKill_Value(unsigned char ucValue)
{
	/* 9404[3:0]=0x8 */
	vdtop_chroma_kill_RBUS chroma_kill_reg;
	chroma_kill_reg.regValue = vdcf_inl(VDTOP_CHROMA_KILL_reg);
	if (chroma_kill_reg.chroma_kill != ucValue) {
		chroma_kill_reg.chroma_kill = ucValue;
		vdcf_outl(VDTOP_CHROMA_KILL_reg, chroma_kill_reg.regValue);
	}
}

unsigned char drvif_module_vdc_Read_CKill_Value(void)
{
	/* 9404[3:0] */
	vdtop_chroma_kill_RBUS chroma_kill_reg;
	chroma_kill_reg.regValue = vdcf_inl(VDTOP_CHROMA_KILL_reg);
	return chroma_kill_reg.chroma_kill;
}

void drvif_module_vdc_Set_CKill_Mode(VDC_CKill_MODE ucMode)
{
	vdtop_chroma_kill_RBUS chroma_kill_reg;
	/* 9404[7:6] */
	if (drvif_module_vdc_CheckFactoryModEnable(ON))
		return;

	if (ucMode == CKill_AUTO) {
		unsigned char vd_mode = drvif_module_vdc_ReadMode(VDC_SET);
		unsigned char average_burst = drvif_module_vdc_burst_mag_status();
		if ((vd_mode == VDC_MODE_SECAM) && (average_burst > 0x05)) {
			ucMode = CKill_OFF;
		}
	}
	chroma_kill_reg.regValue = vdcf_inl(VDTOP_CHROMA_KILL_reg);
#ifdef CONFIG_ENABLE_VDC_CKILL_CONTROL
	chroma_kill_reg.ckill_sel = 1; /* Cgain reference pll , data is to slow and reference result after Cpeak */
#else
	chroma_kill_reg.ckill_sel = 0;
#endif
	if (chroma_kill_reg.user_ckill_mode != ucMode) {
		chroma_kill_reg.user_ckill_mode = ucMode;
	}
	vdcf_outl(VDTOP_CHROMA_KILL_reg, chroma_kill_reg.regValue);
}

unsigned char drvif_module_vdc_Get_CKill_Mode(void)
{
	/* 9404[7:6] */
	vdtop_chroma_kill_RBUS chroma_kill_reg;
	chroma_kill_reg.regValue = vdcf_inl(VDTOP_CHROMA_KILL_reg);
	return chroma_kill_reg.user_ckill_mode;
}

void drvif_module_vdc_Set_lose_chromalock_count(unsigned char ucValue)
{
	/* 9408[7:4]=0xb */
	vdtop_chroma_lock_config_RBUS vdtop_chroma_lock_config_reg;
	vdtop_chroma_lock_config_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOCK_CONFIG_reg);
	if (vdtop_chroma_lock_config_reg.lose_chromalock_count != ucValue) {
		vdtop_chroma_lock_config_reg.lose_chromalock_count = ucValue;
		vdcf_outl(VDTOP_CHROMA_LOCK_CONFIG_reg, vdtop_chroma_lock_config_reg.regValue);
	}
}

void drvif_module_vdc_Set_lose_chromalock_level(unsigned char ucValue)
{
	/* 9408[3:1]=0x5 */
	vdtop_chroma_lock_config_RBUS vdtop_chroma_lock_config_reg;
	vdtop_chroma_lock_config_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOCK_CONFIG_reg);
	if (vdtop_chroma_lock_config_reg.lose_chromalock_level !=  ucValue) {
		vdtop_chroma_lock_config_reg.lose_chromalock_level = ucValue;
		vdcf_outl(VDTOP_CHROMA_LOCK_CONFIG_reg, vdtop_chroma_lock_config_reg.regValue);
	}

}

unsigned char drvif_module_vdc_Get_CKill_Auto(void)
{
	/* 94c0[31:24] & 94c4[23:20]*/
	vdtop_auto_pos_ctrl_RBUS auto_pos_ctrl_reg;
	vdtop_auto_pos_ctrl_2_RBUS auto_pos_ctrl_2_reg;
	auto_pos_ctrl_reg.regValue = vdcf_inl(VDTOP_AUTO_POS_CTRL_reg);
	auto_pos_ctrl_2_reg.regValue = vdcf_inl(VDTOP_AUTO_POS_CTRL_2_reg);
	if ((auto_pos_ctrl_reg.regValue >> 24 == 0x77) && ((auto_pos_ctrl_2_reg.regValue >> 20) & 0xf) == 0x7) {
		return CKill_ON;
	} else {
		return CKill_OFF;
	}
}

VDC_VIDEO_FIXCSTATE_MODE drvif_module_vdc_Read_Cstate_set(void)
{
	/* 9410[3:1] */
	unsigned char ucCstate;
	vdtop_chroma_loopfilter_state_RBUS chroma_loopfilter_state_reg;
	chroma_loopfilter_state_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOOPFILTER_STATE_reg);
	if (chroma_loopfilter_state_reg.fixed_cstate == 1)
		ucCstate = 0x10;
	else
		ucCstate = 0x00;
	ucCstate = ((ucCstate & 0xf0) | chroma_loopfilter_state_reg.cstate);
	return (VDC_VIDEO_FIXCSTATE_MODE)ucCstate;
}

void drvif_module_vdc_Set_Cstate(VDC_VIDEO_FIXCSTATE_MODE value)
{
	/* 9410[3:1][0] */
	vdtop_chroma_loopfilter_state_RBUS chroma_loopfilter_state_reg;
	chroma_loopfilter_state_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOOPFILTER_STATE_reg);
	chroma_loopfilter_state_reg.cstate = (value & 0x07);
	if ((value & 0x10) == 0x10)
		chroma_loopfilter_state_reg.fixed_cstate = 1;
	else
		chroma_loopfilter_state_reg.fixed_cstate = 0;
	vdcf_outl(VDTOP_CHROMA_LOOPFILTER_STATE_reg, chroma_loopfilter_state_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "Set_Cstate : %x, 9410: %x\n", value, chroma_loopfilter_state_reg.regValue);
}

void module_vdc_Set_CKill_Gain_Kill_Thl_Value(unsigned char  ucOnOff, unsigned int ucOffset, unsigned int ucGainValue)
{
	/* 941c[31:0] */
#ifdef CONFIG_ENABLE_VDC_CKILL_CONTROL
	unsigned int temp;
	vdtop_ckill_gain_kill_thl_RBUS Ckill_Gain_Kill_THLl_reg;
	Ckill_Gain_Kill_THLl_reg.regValue = vdcf_inl(VDTOP_CKILL_GAIN_KILL_THL_reg);
	temp = Ckill_Gain_Kill_THLl_reg.regValue;

	if ((ucOnOff != Ckill_Gain_Kill_THLl_reg.ckill_level_user_offset_en) || (ucOnOff != Ckill_Gain_Kill_THLl_reg.ckill_level_user_mode_en)) {
		Ckill_Gain_Kill_THLl_reg.ckill_level_user_mode_en = ucOnOff;
		Ckill_Gain_Kill_THLl_reg.ckill_level_user_offset_en = ucOnOff;
	}
	if (ucOffset != Ckill_Gain_Kill_THLl_reg.ckill_level_user_offset) {
		Ckill_Gain_Kill_THLl_reg.ckill_level_user_offset = ucOffset;
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[ckill] Ckill_Gain_Kill_THLl_reg offset=%x\n", ucOffset);
	}
	if (ucGainValue != Ckill_Gain_Kill_THLl_reg.ckill_level_user_mode_value) {
		Ckill_Gain_Kill_THLl_reg.ckill_level_user_mode_value = ucGainValue;
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[ckill] Ckill_Gain_Kill_THLl_reg value=%x\n", ucGainValue);
	}
	if (temp != Ckill_Gain_Kill_THLl_reg.regValue) {
		vdcf_outl(VDTOP_CKILL_GAIN_KILL_THL_reg, Ckill_Gain_Kill_THLl_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[ckill] Ckill_Gain_Kill_THLl_reg value=%x\n", Ckill_Gain_Kill_THLl_reg.regValue);
	}
#else
	return;
#endif
}

void drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FAST_LOCK value)
{
	/* 9420[7:5] */
	vdtop_cstate_ctrl_RBUS cstate_ctrl_reg;
	cstate_ctrl_reg.regValue = vdcf_inl(VDTOP_CSTATE_CTRL_reg);
	switch (value) {
	case VDC_CSTATE_FastLock_DISABLE:
		cstate_ctrl_reg.fast_lock_en = 0;
		cstate_ctrl_reg.phase_fast_lock_en = 0;
		cstate_ctrl_reg.badedit_phase_lock_en = 0;
		break;
	case VDC_CSTATE_FastLock_ENABLE:
		cstate_ctrl_reg.fast_lock_en = 1;
		cstate_ctrl_reg.phase_fast_lock_en = 1;
		cstate_ctrl_reg.badedit_phase_lock_en = 1;
		break;
	case VDC_CSTATE_FastLock_ENABLE_1:
		cstate_ctrl_reg.fast_lock_en = 1;
		cstate_ctrl_reg.phase_fast_lock_en = 1;
		cstate_ctrl_reg.badedit_phase_lock_en = 0;
		break;
	case VDC_CSTATE_FastLock_ENABLE_2:
		cstate_ctrl_reg.fast_lock_en = 1;
		cstate_ctrl_reg.phase_fast_lock_en = 0;
		cstate_ctrl_reg.badedit_phase_lock_en = 1;
		break;
	case VDC_CSTATE_FastLock_ENABLE_3:
		cstate_ctrl_reg.fast_lock_en = 1;
		cstate_ctrl_reg.phase_fast_lock_en = 0;
		cstate_ctrl_reg.badedit_phase_lock_en = 0;
		break;
	}
	vdcf_outl(VDTOP_CSTATE_CTRL_reg, cstate_ctrl_reg.regValue);
}

void drvif_module_vdc_Cpeak_set(unsigned char on_off)
{
	/* 9430[6] (scart: [8]) */
	vdtop_chroma_agc_peak_ctrl_RBUS chroma_agc_peak_ctrl_reg;
	chroma_agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg);
	if (on_off != chroma_agc_peak_ctrl_reg.chroma_peak_en) {
		chroma_agc_peak_ctrl_reg.chroma_peak_en = on_off;
#ifdef CONFIG_SCART_ENABLE
		chroma_agc_peak_ctrl_reg.chroma_peak_en_pll = on_off;
#endif
		vdcf_outl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg, chroma_agc_peak_ctrl_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[cpeak] =====  cpeak = %x ===== ", on_off);
	}
}

bool module_vdc_Cpeak_read(void)
{
	/* 9430[6] */
	vdtop_chroma_agc_peak_ctrl_RBUS chroma_agc_peak_ctrl_reg;
	chroma_agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg);
	return chroma_agc_peak_ctrl_reg.chroma_peak_en;
}

void drvif_module_vdc_Cpeak_noise_thr1_set(unsigned char value)
{
	/* 9430[19:12] */
	vdtop_chroma_agc_peak_ctrl_RBUS chroma_agc_peak_ctrl_reg;
	chroma_agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg);
	if (value != chroma_agc_peak_ctrl_reg.cpeak_noise_thr1) {
		chroma_agc_peak_ctrl_reg.cpeak_noise_thr1 = value;
		vdcf_outl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg, chroma_agc_peak_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_Cpeak_noise_thr2_set(unsigned char value)
{
	/* 9430[27:20] */
	vdtop_chroma_agc_peak_ctrl_RBUS chroma_agc_peak_ctrl_reg;
	chroma_agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg);
	if (value != chroma_agc_peak_ctrl_reg.cpeak_noise_thr2) {
		chroma_agc_peak_ctrl_reg.cpeak_noise_thr2 = value;
		vdcf_outl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg, chroma_agc_peak_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_Cpeak_noise_act_set(unsigned char on_off)
{
	/* 9430[28] */
	vdtop_chroma_agc_peak_ctrl_RBUS chroma_agc_peak_ctrl_reg;
	chroma_agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg);
	if (on_off != chroma_agc_peak_ctrl_reg.cpeak_noisy_act_en) {
		chroma_agc_peak_ctrl_reg.cpeak_noisy_act_en = on_off;
		vdcf_outl(VDTOP_CHROMA_AGC_PEAK_CTRL_reg, chroma_agc_peak_ctrl_reg.regValue);
	}
}
void drvif_module_vdc_Disable_Auto_Burst_position(void)
{
	/* 9458[1] */
	vdtop_separate_443_358_new_function_1_RBUS separate_443_358_new_function_1_reg;
	separate_443_358_new_function_1_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg);
	if (separate_443_358_new_function_1_reg.auto_burst_location_en == 1) {
		separate_443_358_new_function_1_reg.auto_burst_location_en = 0;
		vdcf_outl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg, separate_443_358_new_function_1_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "Disable_Auto_Burst_position !! ");
	}
}

#ifdef VD_BURST_LOCATION_AUTO
void drvif_module_vdc_Enable_Auto_Burst_position(void)
{
	/* 9458[1] */
	vdtop_separate_443_358_new_function_1_RBUS separate_443_358_new_function_1_reg;
	separate_443_358_new_function_1_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg);
	if (separate_443_358_new_function_1_reg.auto_burst_location_en == 0) {
		separate_443_358_new_function_1_reg.auto_burst_location_en = 1;
		vdcf_outl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg, separate_443_358_new_function_1_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "enable_Auto_Burst_position !! ");
	}
}

void drvif_module_vdc_disable_burst_location_auto(void)
{
	/* 9470[15:8] */
	vdtop_burst_location_fw_cntl_RBUS BURST_LOCATION_FW_CNTL_RBUS_reg;
	BURST_LOCATION_FW_CNTL_RBUS_reg.regValue = vdcf_inl(VDTOP_BURST_LOCATION_FW_CNTL_reg);
	if (BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_auto_en == 0x1) {
		BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_auto_en = 0x0;
		vdcf_outl(VDTOP_BURST_LOCATION_FW_CNTL_reg, BURST_LOCATION_FW_CNTL_RBUS_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "disable_burst_location_auto !! ");
	}
}

void drvif_module_vdc_enable_burst_location_auto(void)
{
	/* 9470[15:8] */
	vdtop_burst_location_fw_cntl_RBUS BURST_LOCATION_FW_CNTL_RBUS_reg;
	BURST_LOCATION_FW_CNTL_RBUS_reg.regValue = vdcf_inl(VDTOP_BURST_LOCATION_FW_CNTL_reg);
	if (BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_auto_en == 0x0) {
		BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_auto_en = 0x1;
		vdcf_outl(VDTOP_BURST_LOCATION_FW_CNTL_reg, BURST_LOCATION_FW_CNTL_RBUS_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "enable_burst_location_auto !! ");
	}
}
#endif

void drvif_module_vdc_set_burst_location_magnitude_thr(unsigned char ucValue)
{
	/* 9470[15:8] */
	vdtop_burst_location_fw_cntl_RBUS BURST_LOCATION_FW_CNTL_RBUS_reg;
	BURST_LOCATION_FW_CNTL_RBUS_reg.regValue = vdcf_inl(VDTOP_BURST_LOCATION_FW_CNTL_reg);
	if (BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_magnitude_thr != (ucValue & 0x7f)) {
		BURST_LOCATION_FW_CNTL_RBUS_reg.burst_location_magnitude_thr = ucValue & 0x7f;
		vdcf_outl(VDTOP_BURST_LOCATION_FW_CNTL_reg, BURST_LOCATION_FW_CNTL_RBUS_reg.regValue);
	}
}

void drvif_module_vdc_StateMachineReset(void)
{
	/* 94a0[3] */
	vdtop_manual_mode_RBUS manual_mode_reg;
	manual_mode_reg.regValue = vdcf_inl(VDTOP_MANUAL_MODE_reg);
	manual_mode_reg.state_machine_reset = 1;
	vdcf_outl(VDTOP_MANUAL_MODE_reg, manual_mode_reg.regValue);
	mdelay(10);
	manual_mode_reg.state_machine_reset = 0;
	vdcf_outl(VDTOP_MANUAL_MODE_reg, manual_mode_reg.regValue);
}

bool drvif_module_vdc_ReadAutomode(void)
{
	/* 94a0[7] */
	vdtop_manual_mode_RBUS manual_mode_reg;
	manual_mode_reg.regValue = vdcf_inl(VDTOP_MANUAL_MODE_reg);
	return manual_mode_reg.auto_mode_en;
}

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
void drvif_module_vdc_clear_state_machine_fix625mode(void)
{
	/* 94b0[7] = 0, 94b0[3] = 0 */
	vdtop_state_machine_fix_mode_RBUS state_machine_fix_mode_reg;
	state_machine_fix_mode_reg.regValue = vdcf_inl(VDTOP_STATE_MACHINE_FIX_MODE_reg);
	if ((state_machine_fix_mode_reg.fix_625flag_en != 0) ||
		(state_machine_fix_mode_reg.fix_625_h != 0)) {
		state_machine_fix_mode_reg.fix_625flag_en = 0;
		state_machine_fix_mode_reg.fix_625_h = 0;
		vdcf_outl(VDTOP_STATE_MACHINE_FIX_MODE_reg, state_machine_fix_mode_reg.regValue);
	}
}
#endif

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
void drvif_module_vdc_set_state_machine_fix625mode(void)
{
	/* 94b0[7] = 1, 94b0[3] = 1 */
	vdtop_state_machine_fix_mode_RBUS state_machine_fix_mode_reg;
	state_machine_fix_mode_reg.regValue = vdcf_inl(VDTOP_STATE_MACHINE_FIX_MODE_reg);
	if ((state_machine_fix_mode_reg.fix_625flag_en != 1) ||
		(state_machine_fix_mode_reg.fix_625_h != 1)) {
		state_machine_fix_mode_reg.fix_625flag_en = 1;
		state_machine_fix_mode_reg.fix_625_h = 1;
		vdcf_outl(VDTOP_STATE_MACHINE_FIX_MODE_reg, state_machine_fix_mode_reg.regValue);
	}
}
#endif

void drvif_module_vdc_set_Basic_Register(VDC_VIDEO_BASIC_REGISTER mode)
{
	/* 94b4 */
	vdtop_vd_basic_register_enable_RBUS vd_basic_register_enable_reg;
	vd_basic_register_enable_reg.regValue = vdcf_inl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg);
	switch (mode) {
	default:
	case VDC_BASIC_REG_ClearAll:
		vd_basic_register_enable_reg.regValue = vd_basic_register_enable_reg.regValue & 0x80; //except 94b4[7]
		break;
	case VDC_ped_reg_enable:
		vd_basic_register_enable_reg.ped_reg_en = 1;
		break;
	case VDC_ped_reg_disable:
		vd_basic_register_enable_reg.ped_reg_en = 0;
		break;
	case VDC_vsyncreg_enable:
		vd_basic_register_enable_reg.vsyncreg_en = 1;
		break;
	case VDC_vsyncreg_disable:
		vd_basic_register_enable_reg.vsyncreg_en = 0;
		break;
	case VDC_cdtomem_reg_enable:
		vd_basic_register_enable_reg.cdtomem_reg_en = 1;
		break;
	case VDC_cdtomem_reg_disable:
		vd_basic_register_enable_reg.cdtomem_reg_en = 0;
		break;
	case VDC_vline625reg_enable:
		vd_basic_register_enable_reg.vline625reg_en = 1;
		break;
	case VDC_vline625reg_disable:
		vd_basic_register_enable_reg.vline625reg_en = 0;
		break;
	case VDC_hagcreg_enable:
		vd_basic_register_enable_reg.hagcreg_en = 1;
		break;
	case VDC_hagcreg_disable:
		vd_basic_register_enable_reg.hagcreg_en = 0;
		break;
	case VDC_colourmodereg_enable:
		vd_basic_register_enable_reg.colourmodereg_en = 1;
		break;
	case VDC_colourmodereg_disable:
		vd_basic_register_enable_reg.colourmodereg_en = 0;
		break;
	case VDC_hpixelreg_enable:
		vd_basic_register_enable_reg.hpixelreg_en = 1;
		break;
	case VDC_hpixelreg_disable:
		vd_basic_register_enable_reg.hpixelreg_en = 0;
		break;
	case VDC_hactivestartreg_enable:
		vd_basic_register_enable_reg.hactivestartreg_en = 1;
		break;
	case VDC_hactivestartreg_disable:
		vd_basic_register_enable_reg.hactivestartreg_en = 0;
		break;
	}
	vdcf_outl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg, vd_basic_register_enable_reg.regValue);
}

void drvif_module_vdc_auto_secamFlag_select(VDC_ATUO_SECAM_FLAG_SEL uselect)
{
	/* 94b8[5:4] */
	vdtop_auto_mode_s_m_statistic_RBUS auto_mode_s_m_statistic_reg;
	auto_mode_s_m_statistic_reg.regValue = vdcf_inl(VDTOP_AUTO_MODE_S_M_STATISTIC_reg);
	if (auto_mode_s_m_statistic_reg.auto_secam_pali_method != uselect) {
		auto_mode_s_m_statistic_reg.auto_secam_pali_method = uselect;
		vdcf_outl(VDTOP_AUTO_MODE_S_M_STATISTIC_reg, auto_mode_s_m_statistic_reg.regValue);
	}
}

void drvif_module_vdc_PreferModeSetting(unsigned char mode)
{
	/* 94b8[7:0] */
	vdtop_auto_mode_s_m_statistic_RBUS auto_mode_s_m_statistic_reg;
	auto_mode_s_m_statistic_reg.regValue = vdcf_inl(VDTOP_AUTO_MODE_S_M_STATISTIC_reg);

	if (mode == VDC_MODE_SECAM) {
		auto_mode_s_m_statistic_reg.auto_secam_pali_method = 0x00;
		auto_mode_s_m_statistic_reg.secam_flag_freq_disable = 0;
		auto_mode_s_m_statistic_reg.statistic_multiplier = 0x04;
		module_vdc_set_noBurstMagFilterTh(0x00);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "Prefer SECAM \n");
	} else {
		auto_mode_s_m_statistic_reg.auto_secam_pali_method = 0x00;
		auto_mode_s_m_statistic_reg.secam_flag_freq_disable = 1;
		auto_mode_s_m_statistic_reg.statistic_multiplier = 0x03;
		module_vdc_set_noBurstMagFilterTh(0x12);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "Prefer default \n");
	}
	vdcf_outl(VDTOP_AUTO_MODE_S_M_STATISTIC_reg, auto_mode_s_m_statistic_reg.regValue);
}

void module_vdc_set_noBurstMagFilterTh(unsigned char value)
{
	/* 94d0[7:0] */
	vdtop_no_burst_mag_filter_th_RBUS no_burst_mag_filter_th_reg;
	no_burst_mag_filter_th_reg.regValue = vdcf_inl(VDTOP_NO_BURST_MAG_FILTER_TH_reg);
	if (no_burst_mag_filter_th_reg.no_burst_mag_filter_th != value) {
		no_burst_mag_filter_th_reg.no_burst_mag_filter_th = value;
		vdcf_outl(VDTOP_NO_BURST_MAG_FILTER_TH_reg, no_burst_mag_filter_th_reg.regValue);
	}
}

void module_vdc_noBurs443_enable(unsigned char on_off)
{
	/* 94d4[0] */
	vdtop_no_burst_443_ctrl_RBUS no_burst_443_ctrl_reg;
	no_burst_443_ctrl_reg.regValue = vdcf_inl(VDTOP_NO_BURST_443_CTRL_reg);
	if (no_burst_443_ctrl_reg.no_burst_443_en != on_off) {
		no_burst_443_ctrl_reg.no_burst_443_en = on_off;
		vdcf_outl(VDTOP_NO_BURST_443_CTRL_reg, no_burst_443_ctrl_reg.regValue);
	}
}

unsigned char module_vdc_read_burst_win_error_flag(void)
{
	/* 94d4[1] */
	unsigned char result = 0;
	vdtop_no_burst_443_ctrl_RBUS no_burst_443_ctrl_reg;
	no_burst_443_ctrl_reg.regValue = vdcf_inl(VDTOP_NO_BURST_443_CTRL_reg);
	result = no_burst_443_ctrl_reg.burst_win_error;
	no_burst_443_ctrl_reg.regValue = vdcf_inl(VDTOP_NO_BURST_443_CTRL_reg);
	result |= no_burst_443_ctrl_reg.burst_win_error;
	no_burst_443_ctrl_reg.regValue = vdcf_inl(VDTOP_NO_BURST_443_CTRL_reg);
	result |= no_burst_443_ctrl_reg.burst_win_error;
	return result;
}

void drvif_module_vdc_old_secam_flag_setting(VDC_SECAM_FLAG_SETTING setting)
{
	/* 9528[7], 9530[7:0], 9534[7:0] */
	vdtop_secam_flag_counter_min_RBUS secam_flag_counter_min_reg;
	vdtop_secam_flag_counter_max_RBUS secam_flag_counter_max_reg;
	secam_flag_counter_max_reg.regValue = vdcf_inl(VDTOP_SECAM_FLAG_COUNTER_MAX_reg);
	secam_flag_counter_min_reg.regValue = vdcf_inl(VDTOP_SECAM_FLAG_COUNTER_MIN_reg);

	switch (setting) {
	case SETTING_CONDITION_OFF:
		secam_flag_counter_max_reg.secam_flag_frequency_upper_limit = 0xa0;
		secam_flag_counter_min_reg.secam_flag_frequency_lower_limit = 0x0d;
		break;
	case SETTING_CONDITION_ON:
		secam_flag_counter_max_reg.secam_flag_frequency_upper_limit = 0xe0;
		secam_flag_counter_min_reg.secam_flag_frequency_lower_limit = 0x25;
		break;
	}
	vdcf_outl(VDTOP_SECAM_FLAG_COUNTER_MAX_reg, secam_flag_counter_max_reg.regValue);
	vdcf_outl(VDTOP_SECAM_FLAG_COUNTER_MIN_reg, secam_flag_counter_min_reg.regValue);
}

void drvif_module_vdc_palm_flag_phase_adjust(unsigned char value)
{
	/* 9538[7:0] */
	vdtop_palm_flag_phase_adj_RBUS palm_flag_phase_adj_reg;
	palm_flag_phase_adj_reg.regValue = vdcf_inl(VDTOP_PALM_FLAG_PHASE_ADJ_reg);
	if (palm_flag_phase_adj_reg.palm_flag_phase_adjust != value) {
		palm_flag_phase_adj_reg.palm_flag_phase_adjust = value;
		vdcf_outl(VDTOP_PALM_FLAG_PHASE_ADJ_reg, palm_flag_phase_adj_reg.regValue);
	}
}

unsigned char drvif_video_read_358_cos_sin_flag(void)
{
	/* 9550[5] */
	unsigned char result = 0x00;
	vdtop_new_358_ctrl_RBUS new_358_ctrl_reg;
	new_358_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_358_CTRL_reg);
	result = new_358_ctrl_reg.new_358_flag_cos_sin;
	mdelay(5);
	new_358_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_358_CTRL_reg);
	result |= new_358_ctrl_reg.new_358_flag_cos_sin;
	mdelay(5);
	new_358_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_358_CTRL_reg);
	result |= new_358_ctrl_reg.new_358_flag_cos_sin;
	mdelay(5);
	new_358_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_358_CTRL_reg);
	result |= new_358_ctrl_reg.new_358_flag_cos_sin;
	return result;
}

void drvif_module_vdc_BurstGate_set(unsigned short usStart, unsigned short usEnd)
{
	/* 9560[10:0], 9564[10:0] */
	vdtop_sep_burst_start0_RBUS sep_burst_start0_reg;
	vdtop_sep_burst_end0_RBUS sep_burst_end0_reg;
	sep_burst_start0_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_START0_reg);
	sep_burst_end0_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_END0_reg);
	if ((sep_burst_start0_reg.sep_burst_start != usStart) ||
		(sep_burst_end0_reg.sep_burst_end != usEnd)) {
		sep_burst_start0_reg.sep_burst_start = usStart;
		sep_burst_end0_reg.sep_burst_end = usEnd;
		vdcf_outl(VDTOP_SEP_BURST_START0_reg, sep_burst_start0_reg.regValue);
		vdcf_outl(VDTOP_SEP_BURST_END0_reg, sep_burst_end0_reg.regValue);
	}
}

#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
unsigned char module_video_read_Sep_443_core_burst_hsync(void)
{
	/* 956c[31:24] */
	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
	return sep_burst_ro2_reg.sep_443_core_burst_hsync;
}

unsigned char module_video_read_Sep_358_core_burst_hsync(void)
{
	/* 956c[23:16] */
	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
	return sep_burst_ro2_reg.sep_358_core_burst_hsync;
}
#endif

unsigned char drvif_video_read_Sep_443_core_burst(void)
{
	/* 9356c[15:8] */
	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
	return sep_burst_ro2_reg.sep_443_core_burst;
}

unsigned char drvif_video_read_Sep_358_core_burst(void)
{
	/* 956c[7:0] */
	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
	return sep_burst_ro2_reg.sep_358_core_burst;
}

void drvif_module_vdc_set_Sep_358_thl(unsigned char ucValue)
{
	/* 9574[7:0] */
	vdtop_sep_burst_th1_RBUS sep_burst_th1_reg;
	sep_burst_th1_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_TH1_reg);
	if (sep_burst_th1_reg.sep_358_thl != ucValue) {
		sep_burst_th1_reg.sep_358_thl = ucValue;
		vdcf_outl(VDTOP_SEP_BURST_TH1_reg, sep_burst_th1_reg.regValue);
	}
}

void drvif_module_vdc_set_Sep_443_thl(unsigned char ucValue)
{
	/* 9574[15:8] */
	vdtop_sep_burst_th1_RBUS sep_burst_th1_reg;
	sep_burst_th1_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_TH1_reg);
	if (sep_burst_th1_reg.sep_443_thl != ucValue) {
		sep_burst_th1_reg.sep_443_thl = ucValue;
		vdcf_outl(VDTOP_SEP_BURST_TH1_reg, sep_burst_th1_reg.regValue);
	}
}

unsigned char drvif_video_sep_burst_flag1(VDC_SEP_BURST_FLAG status)
{
	/* 9578[2],[1],[0] */
	vdtop_sep_burst_flag1_RBUS sep_burst_flag1_reg;
	sep_burst_flag1_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_FLAG1_reg);
	switch (status) {
	case VDC_new_358_flag:
		return sep_burst_flag1_reg.power_358_flag;
		break;
	case VDC_new_443_flag:
		return sep_burst_flag1_reg.power_443_flag;
		break;
	case VDC_new_secam_flag:
		return sep_burst_flag1_reg.power_secam_flag;
		break;
	case VDC_new_burst_flag:
		return sep_burst_flag1_reg.regValue;
		break;
	}
	return true;
}

void module_vdc_set_Mode_443358pk_sel(VDC_Mode_443358pk ucValue)
{
	vdtop_automode_443358pk_ctrl_RBUS automode_443358pk_ctrl_reg;
	/* 957c[1:0] */
	if (drvif_module_vdc_CheckFactoryModEnable(ON))
		return;
	automode_443358pk_ctrl_reg.regValue = vdcf_inl(VDTOP_AUTOMODE_443358PK_CTRL_reg);
	if (automode_443358pk_ctrl_reg.mode_443358pk_sel != ucValue) {
		automode_443358pk_ctrl_reg.mode_443358pk_sel = ucValue;
		vdcf_outl(VDTOP_AUTOMODE_443358PK_CTRL_reg, automode_443358pk_ctrl_reg.regValue);
	}
}

void module_vdc_set_Mode_secam2_sel(VDC_Mode_secam2 ucValue)
{
	/* 957c[5:4] */
	vdtop_automode_443358pk_ctrl_RBUS automode_443358pk_ctrl_reg;
	automode_443358pk_ctrl_reg.regValue = vdcf_inl(VDTOP_AUTOMODE_443358PK_CTRL_reg);
	if (automode_443358pk_ctrl_reg.mode_secam2_sel != ucValue) {
		automode_443358pk_ctrl_reg.mode_secam2_sel = ucValue;
		vdcf_outl(VDTOP_AUTOMODE_443358PK_CTRL_reg, automode_443358pk_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_lock_h_on_no_signal(unsigned char on_off)
{
	/* 95e4[2] */
	vdtop_vcr_option_RBUS vcr_option_reg;
	vcr_option_reg.regValue = vdcf_inl(VDTOP_VCR_OPTION_reg);
	if (vcr_option_reg.lock_h_on_no_signal != on_off) {
		vcr_option_reg.lock_h_on_no_signal = on_off;
		vdcf_outl(VDTOP_VCR_OPTION_reg, vcr_option_reg.regValue);
	}
}

void module_vdc_hv_freerun_sel(unsigned char on_off)
{
	/* 95e4[3] */
	vdtop_vcr_option_RBUS vcr_option_reg;
	vcr_option_reg.regValue = vdcf_inl(VDTOP_VCR_OPTION_reg);
	if (vcr_option_reg.freerun_sel != on_off) {
		vcr_option_reg.freerun_sel = on_off;
		vdcf_outl(VDTOP_VCR_OPTION_reg, vcr_option_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "on/off: %x, freerun : %x !!!!!!!!!!!!!!!!!!!!!!!!!!!", on_off, vdcf_inl(VDTOP_VCR_OPTION_reg));
	}
}

bool drvif_module_vdc_read_hv_freerun_sel(void)
{
	/* 95e4[3] */
	vdtop_vcr_option_RBUS vcr_option_reg;
	vcr_option_reg.regValue = vdcf_inl(VDTOP_VCR_OPTION_reg);
	return vcr_option_reg.freerun_sel;
}

void module_vdc_set_Out444_sel(VDC_OUT444_sel value)
{
	/* 9620[3] */
	vdtop_fsw_ctrl2_RBUS fsw_ctrl2_reg;
	fsw_ctrl2_reg.regValue = vdcf_inl(VDTOP_FSW_CTRL2_reg);
	fsw_ctrl2_reg.outfifo_444_sel = 1;
	fsw_ctrl2_reg.out444_sel = value;
	vdcf_outl(VDTOP_FSW_CTRL2_reg, fsw_ctrl2_reg.regValue);
}

#ifdef CONFIG_SCART_ENABLE
void drvif_video_SCART_RGB_set(unsigned char on_off)
{
	/* 9620[7] */
	vdtop_fsw_ctrl2_RBUS fsw_ctrl2_reg;
	fsw_ctrl2_reg.regValue = vdcf_inl(VDTOP_FSW_CTRL2_reg);
	if (fsw_ctrl2_reg.scart_en != on_off) {
		fsw_ctrl2_reg.scart_en = on_off;

		if (on_off)
			module_vdc_SetSaturation_SCART(0x96, 0x60);	/* Cb, Cr default setting */
		else
			module_vdc_SetSaturation_SCART(0x00, 0x00);	/* output black screan */

		vdcf_outl(VDTOP_FSW_CTRL2_reg, fsw_ctrl2_reg.regValue);
	}
}

bool drvif_video_read_SCART_RGB_set(void)
{
	/* 9620[7] */
	vdtop_fsw_ctrl2_RBUS fsw_ctrl2_reg;
	fsw_ctrl2_reg.regValue = vdcf_inl(VDTOP_FSW_CTRL2_reg);
	return fsw_ctrl2_reg.scart_en;
}
#endif

#ifdef CONFIG_SCART_ENABLE
void drvif_module_vdc_SetContrast_SCART(unsigned char ucValue)
{
	/* 9628[7:0] */
	vdtop_luma_contrast2_adj_RBUS luma_contrast2_adj_reg;
	luma_contrast2_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_CONTRAST2_ADJ_reg);
	if (luma_contrast2_adj_reg.contrast2 != ucValue) {
		luma_contrast2_adj_reg.contrast2 = ucValue;
		vdcf_outl(VDTOP_LUMA_CONTRAST2_ADJ_reg, luma_contrast2_adj_reg.regValue);
	}
}
#endif

#ifdef CONFIG_SCART_ENABLE
void drvif_module_vdc_SetBrightness_SCART(unsigned char ucValue)
{
	/* 962c[7:0] */
	vdtop_luma_brightness2_adj_RBUS luma_brightness2_adj_reg;
	luma_brightness2_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_BRIGHTNESS2_ADJ_reg);
	if (luma_brightness2_adj_reg.brightness2 != ucValue) {
		luma_brightness2_adj_reg.brightness2 = ucValue;
		vdcf_outl(VDTOP_LUMA_BRIGHTNESS2_ADJ_reg, luma_brightness2_adj_reg.regValue);
	}
}
#endif

#ifdef CONFIG_SCART_ENABLE
void module_vdc_SetSaturation_SCART(unsigned char ucCrValue, unsigned char ucCbValue)
{
	/* 9630[7:0], 9634[7:0] */
	vdtop_chroma_saturation2_adj_RBUS chroma_saturation2_adj_reg;
	vdtop_cb_sat_adj_RBUS cb_sat_adj_reg;
	chroma_saturation2_adj_reg.regValue = vdcf_inl(VDTOP_CHROMA_SATURATION2_ADJ_reg);
	cb_sat_adj_reg.regValue = vdcf_inl(VDTOP_CB_SAT_ADJ_reg);
	if ((chroma_saturation2_adj_reg.cr_saturation != ucCrValue)) {
		chroma_saturation2_adj_reg.cr_saturation = ucCrValue;	/* Cr default setting = 0x96 */
		cb_sat_adj_reg.cb_saturation = ucCbValue;	/* Cb default setting = 0x60 */
		vdcf_outl(VDTOP_CHROMA_SATURATION2_ADJ_reg, chroma_saturation2_adj_reg.regValue);
		vdcf_outl(VDTOP_CB_SAT_ADJ_reg, cb_sat_adj_reg.cb_saturation);
	}
}
#endif

#ifdef CONFIG_SCART_ENABLE
unsigned char drvif_module_vdc_read_FSW_value(void)
{
	/* 9640[2:0] FSW 3bit ADC input value */
	vdtop_fsw_input_status_RBUS fsw_input_status_reg;
	fsw_input_status_reg.regValue = vdcf_inl(VDTOP_FSW_INPUT_STATUS_reg);
	return fsw_input_status_reg.fb_status;
}
#endif

unsigned short drvif_module_vdc_read_blevel(void)
{
	/* 968c[11:0] */
	vdtop_clamp_test_reg6_RBUS clamp_test_reg6_reg;
	clamp_test_reg6_reg.regValue = vdcf_inl(VDTOP_CLAMP_TEST_REG6_reg);
	return clamp_test_reg6_reg.comp_blevel;
}

unsigned short drvif_module_vdc_read_slevel(void)
{
	/* 9690[11:0] */
	vdtop_clamp_test_reg8_RBUS clamp_test_reg8_reg;
	clamp_test_reg8_reg.regValue = vdcf_inl(VDTOP_CLAMP_TEST_REG8_reg);
	return clamp_test_reg8_reg.comp_slevel;
}

/* ========================================================================= */
bool drvif_module_vdc_read_factory_flag(void)
{
	/* 96b0[0] */
	vdtop_fpga_test_reg1_RBUS fpga_test_reg1_reg;
	fpga_test_reg1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	return fpga_test_reg1_reg.factory_flag;
}

void drvif_module_vdc_clean_factory_flag(void)
{
	/* 96b0[0] */
	vdtop_fpga_test_reg1_RBUS fpga_test_reg1_reg;
	fpga_test_reg1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	fpga_test_reg1_reg.factory_flag = 0;
	vdcf_outl(VDTOP_FPGA_TEST_REG1_reg, fpga_test_reg1_reg.regValue);
}

unsigned int drvif_module_vdc_read_fpga_test1(void)
{
	/* 96b0[31:1] */
	vdtop_fpga_test_reg1_RBUS fpga_test_reg1_reg;
	fpga_test_reg1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	return fpga_test_reg1_reg.fpga_test1;
}

VDC_MSG_LEVEL drvif_module_vdc_read_fpga_test2(void)
{
	/* 96b4[31:0] */
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	return (VDC_MSG_LEVEL)fpga_test_reg2_reg.fpga_test2;
}

#if 1
unsigned char drvif_module_vdc_read_int_auto_scan_flag(void)
{
	/* 96b4[27], for internal demod auto scan do softreset */
	unsigned char result = 0;
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (fpga_test_reg2_reg.fpga_test2 & VDC_MSG_INT_SCAN_FLAG)
		result = 1;

	return result;
}

void drvif_module_vdc_set_int_auto_scan_flag(unsigned char on_off)
{
	/* 96b4[27], for internal demod auto scan do softreset */
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (on_off)
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue | VDC_MSG_INT_SCAN_FLAG;
	else
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue & ~VDC_MSG_INT_SCAN_FLAG;
	vdcf_outl(VDTOP_FPGA_TEST_REG2_reg, fpga_test_reg2_reg.regValue);
}

bool drvif_module_vdc_read_scan_flag(void)
{
	/* 96b4[29], for freerun not to do softreset.*/
	bool bValue = 0;
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (fpga_test_reg2_reg.fpga_test2 & VDC_MSG_SCAN_FLAG)
		bValue = 1;
	return bValue;
}

void drvif_module_vdc_set_scan_flag(unsigned char on_off)
{
	/* 96b4[29], for freerun not to do softreset.*/
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (on_off)
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue | VDC_MSG_SCAN_FLAG;
	else
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue & ~VDC_MSG_SCAN_FLAG;
	vdcf_outl(VDTOP_FPGA_TEST_REG2_reg, fpga_test_reg2_reg.regValue);
}

bool drvif_module_vdc_read_ch_change_flag(void)
{
	/* 96b4[30] */
	bool bValue = 0;
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (fpga_test_reg2_reg.fpga_test2 & VDC_MSG_CH_CHANGE)
		bValue = 1;
	return bValue;
}

void drvif_module_vdc_set_ch_change_flag(unsigned char on_off)
{
	/* 96b4[30] */
	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	if (on_off)
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue | VDC_MSG_CH_CHANGE;
	else
		fpga_test_reg2_reg.regValue = fpga_test_reg2_reg.regValue & ~VDC_MSG_CH_CHANGE;
	vdcf_outl(VDTOP_FPGA_TEST_REG2_reg, fpga_test_reg2_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "ATV channel change: %x\n", on_off);
}

unsigned char drvif_module_vdc_read_external_ch_change_flag(void)
{
	/* ch_change_flag, 0xb801a604[1] */
	return (unsigned char)(rtdf_inl(SB2_DUMMY_1_reg) & _BIT1);
}

unsigned char drvif_module_vdc_read_external_autoscan_flag(void)
{
	/* autoscan_flag, 0xb801a604[2] */
	return (unsigned char)(rtdf_inl(SB2_DUMMY_1_reg) & _BIT2);
}

void drvif_module_vdc_set_external_ch_change_flag(unsigned char on_off)
{
	/* ch_change_flag, 0xb801a604[1] */
	if (on_off)
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT1, _BIT1);
	else
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT1, _ZERO);
}

void drvif_module_vdc_set_external_auto_scan_flag(unsigned char on_off)
{
	/* external auto_scan_flag, 0xb801a604[2] */
	if (on_off)
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT2, _BIT2);
	else
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT2, _ZERO);
}

void drvif_module_vdc_set_AVD_connect_flag(unsigned char on_off)
{
	/* set when AVD connect, 0xb801a604[6] */
	if (on_off)
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT6, _BIT6);
	else
		rtdf_maskl(SB2_DUMMY_1_reg, ~_BIT6, _ZERO);
}
#endif

/* ========================================================================= */
void drvif_module_vdc_SECAM_y_fir_adj(VDC_SECAM_Y_FIR_EN on_off,
	VDC_SECAM_HPF_SEL y_hpf_sel, VDC_SECAM_Y_LPF_SEL y_lpf_sel)
{
	vdtop_secam_ctrl_RBUS r;	/* 9700[16][14:12][10:8] */
	bool force_notch_fir;		/* 9700[1:0] */

	r.regValue = vdcf_inl(VDTOP_SECAM_CTRL_reg);

	/*
	 * Checking to keep old setting or not
	 */
	if (r.secam_y_fir_en == on_off && r.secam_y_hpf_sel == y_hpf_sel &&
	    r.secam_y_lpf_sel == y_lpf_sel) {
		return;
	}

	/*
	 * When secam_y_lpf_sel >= 0x4 (VDC_y_lpf_L1p5_H7p0_MHz),
	 * there are limitations as below.
	 * Limit 1: secam_y_hpf_sel must be 0 (VDC_hpf_bypass)
	 * Limit 2: secam_notch_filter must be 0 (VDC_SECAM_FIR)
	 */
	force_notch_fir = false;	/* Disable force notch FIR as default */
	if (unlikely(y_lpf_sel >= VDC_y_lpf_L1p5_H7p0_MHz)) {
		if (y_hpf_sel != VDC_hpf_bypass) {	/* Limit 1 */
			y_hpf_sel = VDC_hpf_bypass;
		}

		if (r.secam_notch_filter != VDC_SECAM_FIR)	/* Limit 2 */
			force_notch_fir = true;
	}

	/*
	 * Write settings to hw register (0xb801_9700)
	 */
	r.secam_y_fir_en = on_off;
	r.secam_y_hpf_sel = y_hpf_sel;
	r.secam_y_lpf_sel = y_lpf_sel;
	r.drdb_freq_const = 1;

	vdcf_outl(VDTOP_SECAM_CTRL_reg, r.regValue);

	if (force_notch_fir) {
		module_vdc_SECAM_notch_filter_sel(VDC_SECAM_FIR);
	}
}

void module_vdc_SECAM_flag_select(unsigned char value)
{
	/* 9700[4]: 1: fix new dto for secam(AV/TV),  0: original(SV) */
	vdtop_secam_ctrl_RBUS secam_ctrl_reg;
	secam_ctrl_reg.regValue = vdcf_inl(VDTOP_SECAM_CTRL_reg);
	if (secam_ctrl_reg.secam_flag_sel != value) {
		secam_ctrl_reg.secam_flag_sel = value;
		vdcf_outl(VDTOP_SECAM_CTRL_reg, secam_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_SECAM_Drdb_vlpf_en(unsigned char on_off)
{
	/* 9700[6] */
	vdtop_secam_ctrl_RBUS secam_ctrl_reg;
	secam_ctrl_reg.regValue = vdcf_inl(VDTOP_SECAM_CTRL_reg);
	if (secam_ctrl_reg.drdb_vlpf_en != on_off) {
		secam_ctrl_reg.drdb_vlpf_en = on_off;
		vdcf_outl(VDTOP_SECAM_CTRL_reg, secam_ctrl_reg.regValue);
	}
}

void drvif_module_vdc_SECAM_ColorReduction(unsigned char on_off)
{	/* 9f70, 9f74, 9f78 */
	/* 	Purpose: Multiburst Wrong Color
		Merlin jyyang 20150617			*/
	vdpq_postp_secam_fix_ctrl_RBUS postp_secam_fix_ctrl_reg;
	vdpq_postp_secam_fix_y_detect0_RBUS postp_secam_fix_y_detect0_reg;
	vdpq_postp_secam_fix_y_detect1_RBUS postp_secam_fix_y_detect1_reg;
	postp_secam_fix_ctrl_reg.regValue = vdcf_inl(VDPQ_POSTP_SECAM_FIX_CTRL_reg);
	postp_secam_fix_y_detect0_reg.regValue = vdcf_inl(VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg);
	postp_secam_fix_y_detect1_reg.regValue = vdcf_inl(VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg);

	postp_secam_fix_ctrl_reg.secam_fix_color_reduce_en = 1;	/*patch for HW issue 20160105*/

	if ((postp_secam_fix_ctrl_reg.secam_fix_uv_flag_en != on_off) ||
		(postp_secam_fix_y_detect0_reg.secam_fix_y_flag_en != on_off)) {
		postp_secam_fix_ctrl_reg.secam_fix_uv_flag_en = on_off; /* jyyang 20150707 */
		postp_secam_fix_y_detect0_reg.secam_fix_y_flag_en = on_off;
		vdcf_outl(VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg, postp_secam_fix_y_detect0_reg.regValue);
		vdcf_outl(VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg, postp_secam_fix_y_detect1_reg.regValue);
	}
	vdcf_outl(VDPQ_POSTP_SECAM_FIX_CTRL_reg, postp_secam_fix_ctrl_reg.regValue);
}

void drvif_module_vdc_SECAM_gp_enable(unsigned char on_off, unsigned int gp_step, unsigned int gp_thl)
{	/* 9744[31],[21:12],[9:0] */
	vdtop_secam_gp_rm_RBUS secam_gp_rm_reg;
	secam_gp_rm_reg.regValue = vdcf_inl(VDTOP_Secam_gp_rm_reg);
	if ((secam_gp_rm_reg.secam_gp_en != on_off) ||
		(secam_gp_rm_reg.secam_gp_step != gp_step) ||
		(secam_gp_rm_reg.secam_gp_thl != gp_thl)) {
		secam_gp_rm_reg.secam_gp_en = on_off;
		secam_gp_rm_reg.secam_gp_step = gp_step;
		secam_gp_rm_reg.secam_gp_thl = gp_thl;
		vdcf_outl(VDTOP_Secam_gp_rm_reg, secam_gp_rm_reg.regValue);
	}
}

void drvif_module_vdc_set_Output_mode(VDC_OUTPUT_MODE value)
{
	/* 9758[31] */
	vdtop_fifo_ctrl_RBUS fifo_ctrl_reg;
	fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
	if (fifo_ctrl_reg.vdec_ps_disp_27_en != value) {
		fifo_ctrl_reg.vdec_ps_disp_27_en = value;
		vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);
	}
}

VDC_OUTPUT_MODE drvif_module_vdc_get_Output_mode(void)
{
	/* 9758[31] */
	vdtop_fifo_ctrl_RBUS fifo_ctrl_reg;
	fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
	return (VDC_OUTPUT_MODE)fifo_ctrl_reg.vdec_ps_disp_27_en;
}

void drvif_module_vdc_clear_FIFO_status(void)
{
	/* 975c[1:0] */
	vdtop_fifo_status_RBUS fifo_status_reg;
	fifo_status_reg.regValue = vdcf_inl(VDTOP_FIFO_STATUS_reg);
	fifo_status_reg.fifo_empty_status = 1;
	fifo_status_reg.fifo_full_status = 1;
	vdcf_outl(VDTOP_FIFO_STATUS_reg, fifo_status_reg.regValue);
}

void drvif_module_vdc_Swallow_on_Vsyng(unsigned char on_off)
{
	/* 9764[7] */
	vdtop_misc_control_RBUS misc_control_reg;
	misc_control_reg.regValue = vdcf_inl(VDTOP_MISC_CONTROL_reg);
	if (misc_control_reg.swallow_on_vsync != on_off) {
		misc_control_reg.swallow_on_vsync = on_off;
		vdcf_outl(VDTOP_MISC_CONTROL_reg, misc_control_reg.regValue);
	}
}


/* ========================================================================= */
/* === VD Initial and reset functions ================================================ */
/**
   drvif_module_vdc_Initial
   Initial video decoder module

 In this fuction, write VDC's specific initial setting table to VDC.
 We also set the rtd2620 for specific VDC here, because it is
 more convenience to put the specific table in the same file.

 This function need to execute only one time when power on.

   @param <void>       { void }
   @return                  { void }

*/
void drvif_module_vdc_Initial(unsigned int mem_addr)
{
	VDC_DEBUG_MSG(VDC_MSG_INIT, "initial\n");
	drvif_module_vpq_3D_mem_Initial(mem_addr);
	module_vdc_set_Out444_sel(VDC_444output);
	drvif_module_vdc_27M_FrontDigitalFilterEnable(VDC_27M_FDF_BYPASS);
	module_vdc_Reset();

	//disable auto change for 3D to 2D when signal is noisy.
	vdcf_maskl(VDTOP_SIGNAL_STM_CONTROL_reg, ~_BIT4, _ZERO);
}

/**
   module_vdc_Reset
   Reset video decoder module

 This function need to execute when source is changed.

   @param <void>       { void }
   @return                  { void }
*/
void module_vdc_Reset(void)
{
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
	vdtop_burst_location_hsync_RBUS burst_location_hsync_reg;
#endif
	vdtop_agc_peak_ctrl_RBUS agc_peak_ctrl_reg;
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg;
	vdtop_charge_pump_adjustment_RBUS charge_pump_adjustment_reg;
	vdtop_burst_mag_th_358_RBUS burst_mag_th_358_reg;
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vdtop_lock_count_RBUS lock_count_reg;
	vdtop_sync_midpt_v2_RBUS sync_midpt_v2_reg;
	vdtop_cagc_peak_ctrl3_RBUS cagc_peak_ctrl3_reg;
	vdtop_lpfsync_plus_dc_RBUS lpfsync_plus_dc_reg;
	vdtop_no_signal_dec_RBUS no_signal_dec_reg;
	vdtop_fifo_ctrl_RBUS fifo_ctrl_reg;
	vdtop_clampagc_compluma_new_control_RBUS clampagc_compluma_new_control_reg;
	vdtop_ckill_lb_sel_RBUS ckill_lb_sel_reg;
#if VDC_Error_case3
	vdtop_vsync_h_min_RBUS vdtop_vsync_h_min_reg;
#endif
	vdtop_patgen_ctrl_RBUS vdtop_patgen_ctrl_reg;
	vdtop_secam_dbfreq_offset_RBUS vdtop_secam_dbfreq_offset_reg;

	vdtop_patgen_ctrl_reg.regValue = vdcf_inl(VDTOP_PATGEN_CTRL_reg);
	vdtop_patgen_ctrl_reg.clk_vdadc_polarity = 1;	/* 979c[8]=1 */
	vdcf_outl(VDTOP_PATGEN_CTRL_reg, vdtop_patgen_ctrl_reg.regValue);
//	drvif_module_vdc_Set_Vstate(VDC_VSTATE_RESET);

	drvif_module_vdc_SetFactoryModEnable(OFF);
//	vdcf_outl(VDTOP_FPGA_TEST_REG1_reg, 0x00000000);
//	vdcf_outl(VDTOP_FPGA_TEST_REG2_reg, 0x00000000);
	module_vdc_Set_Vsync_clamp_mode(VDC_vsync_clamp_disable);
	drvif_module_vdc_Swallow_on_Vsyng(_DISABLE);

	clampagc_compluma_new_control_reg.regValue = vdcf_inl(VDTOP_CLAMPAGC_COMPLUMA_NEW_CONTROL_reg);
	clampagc_compluma_new_control_reg.clampagc_under_en = 0;	/* 90b8[1]=0, disable under gain */
	vdcf_outl(VDTOP_CLAMPAGC_COMPLUMA_NEW_CONTROL_reg, clampagc_compluma_new_control_reg.regValue);
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
	drvif_module_vdc_Cpeak_set(_DISABLE);
	burst_location_hsync_reg.regValue = vdcf_inl(VDTOP_BURST_LOCATION_HSYNC_reg);
	burst_location_hsync_reg.sep_hsync_start = 0x0321;
	burst_location_hsync_reg.sep_hsync_end = 0x037a;
	vdcf_outl(VDTOP_BURST_LOCATION_HSYNC_reg, burst_location_hsync_reg.regValue);
#else
	drvif_module_vdc_Cpeak_set(_ENABLE);
#endif
	drvif_module_vdc_set_second_pll(Second_pll_enable);
	module_vdc_set_cstate_parameter();
	module_vdc_set_hstate_error_method(ignore_error_on);
	module_vdc_set_hstate_error01_thl(0x24);
	module_vdc_set_vsync_refind_enable(_ENABLE);
	module_vdc_set_vstate_parameter();
	drvif_module_vdc_set_vsync_freerun_enable(_ENABLE);
//	module_vdc_set_vstate0_direct_vsync_enable(_ENABLE);
//	drvif_module_vdc_Set_CKill_Value(0x08);
	drvif_module_vdc_set_Killgate(VDC_kg_off);
	drvif_video_set_control_reg(VDC_ped_off);
#if 1//def CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	drvif_module_vdc_Vdetcet_pattern_sel(0);
#endif
	agc_peak_ctrl_reg.regValue = vdcf_inl(VDTOP_AGC_PEAK_CTRL_reg);
	agc_peak_ctrl_reg.hagc_err_coring_th	= 0x01;	/* 9098 set peak speed */
	agc_peak_ctrl_reg.agc_peak_loop_gain = 0x01;
	vdcf_outl(VDTOP_AGC_PEAK_CTRL_reg, agc_peak_ctrl_reg.regValue);

	/* enable auto dc-restore function */
	charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
	charge_pump_delay_control_reg.auto_dc_restore_disable_ad4_updn = 1;	/* 90c4[11] = 1, enable auto on ad4 */
	charge_pump_delay_control_reg.auto_dc_restore_disable_ad3_updn = 1;	/* 90c4[10] = 1, enable auto on ad3 */
	charge_pump_delay_control_reg.auto_dc_restore_disable_ad2_updn = 1;	/* 90c4[9] = 1, enable auto on ad2 */
	charge_pump_delay_control_reg.auto_dc_restore_disable_ad1_updn = 1;	/* 90c4[8] = 1, enable auto on ad1 */

	/* clamp adjust setting */
	charge_pump_delay_control_reg.cpump_adjust_polarity = 1;	/* 90c4[1] = 1 */
	vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);
	charge_pump_adjustment_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_ADJUSTMENT_reg);
	charge_pump_adjustment_reg.cpump_adjust = 0x10;	/* 90c8[7:0] = 0x10 */
	vdcf_outl(VDTOP_CHARGE_PUMP_ADJUSTMENT_reg, charge_pump_adjustment_reg.regValue);

	ckill_lb_sel_reg.regValue = vdcf_inl(VDTOP_CKILL_LB_SEL_reg);
	ckill_lb_sel_reg.ckill_lb_sel = 0;		/*9418[0]=0, default */
	vdcf_outl(VDTOP_CKILL_LB_SEL_reg, ckill_lb_sel_reg.regValue);

	burst_mag_th_358_reg.regValue = vdcf_inl(VDTOP_BURST_MAG_TH_358_reg);
	burst_mag_th_358_reg.burst_mag_th_358 = 0x70;	/* 94e4 */
	vdcf_outl(VDTOP_BURST_MAG_TH_358_reg, burst_mag_th_358_reg.regValue);

	drvif_module_vdc_set_burst_location_magnitude_thr(0x12);
	/* AV out setting */
	drvif_module_vdc_AVout_mode_set(VDC_CVBS_Mode3);
	drvif_module_vdc_AVout_Delay(0x5ae);

	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	vsync_pll_freerun_mux_reg.vlines_the_same_cnt_thr = 0x05;	/* 93f4[19:16] = 0x03, for diff flag */
	vdcf_outl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg, vsync_pll_freerun_mux_reg.regValue);

	/* non standard setting start */
	module_vdc_set_secam_443358_flag_parameter();
	module_vdc_set_Hblank_start(0xda);

	lock_count_reg.regValue = vdcf_inl(VDTOP_LOCK_COUNT_reg);
	lock_count_reg.locked_count_clean_max = 0x0f;	/* 9130 = 0xff */
	lock_count_reg.locked_count_noisy_max = 0x0f;
	vdcf_outl(VDTOP_LOCK_COUNT_reg, lock_count_reg.regValue);

	sync_midpt_v2_reg.regValue = vdcf_inl(VDTOP_SYNC_MIDPT_V2_reg);
	sync_midpt_v2_reg.no_signal_to_0_sel = 1;	/* 934c[10] = 1 */
	sync_midpt_v2_reg.hpll_no_signal_sel = 1;		/* 934c[9] = 1 */
	vdcf_outl(VDTOP_SYNC_MIDPT_V2_reg, sync_midpt_v2_reg.regValue);

	cagc_peak_ctrl3_reg.regValue = vdcf_inl(VDTOP_CAGC_PEAK_CTRL3_reg);
	cagc_peak_ctrl3_reg.cagc_peak_luma_ratio = 0x00;	/* 9444 = 0x00 */
	vdcf_outl(VDTOP_CAGC_PEAK_CTRL3_reg, cagc_peak_ctrl3_reg.regValue);

	lpfsync_plus_dc_reg.regValue = vdcf_inl(VDTOP_lpfsync_plus_dc_reg);
	lpfsync_plus_dc_reg.lpfsync_plus_dc = 0x00;	/* 911c[7:0] = 0x00 xftv */
	vdcf_outl(VDTOP_lpfsync_plus_dc_reg, lpfsync_plus_dc_reg.regValue);

#if VDC_Error_case3
	vdtop_vsync_h_min_reg.regValue = vdcf_inl(VDTOP_VSYNC_H_MIN_reg);
	vdtop_vsync_h_min_reg.vsync_h_min = 0x6d;	/* 9320[7:0] = 0x6d for over modulation */
	vdcf_outl(VDTOP_VSYNC_H_MIN_reg, vdtop_vsync_h_min_reg.regValue);
#endif

	/* non standard setting end */
	/*	drvif_module_vdc_PreferModeSetting(PREFER_DEFAULT); */

	/* SECAM PQ SETTING start */
	/*	drvif_module_vdc_SECAM_y_fir_adj(VDC_secam_y_fir_enable,VDC_hpf_bypass,VDC_y_lpf_L1p5_H7p0_MHz); */
	/*	drvif_module_vdc_SECAM_y_fir_adj(VDC_secam_y_fir_enable, VDC_hpf_5p7_MHz, VDC_y_lpf_L2p0_H6p4_MHz);*/ /*move to drvif_module_vdc_tv_Reset() and  drvif_module_vdc_ResetReg(), CSFC 20160116*/
	/*	drvif_module_vdc_SECAM_gp_enable(_DISABLE,0x19,0x3e); */
	drvif_module_vdc_SECAM_gp_enable(_ENABLE, 0x9d, 0x6e);
	/* SECAM PQ SETTING end */

	/* set 1D,2D,3D position the same */
	no_signal_dec_reg.regValue = vdcf_inl(VDTOP_NO_SIGNAL_DEC_reg);
	no_signal_dec_reg.vsync_delay_2d = 0x3;	/* 9314[11:8] = 3 (2) */
//	no_signal_dec_reg.vsync_delay_1d = 0x1;	/* 9314[15:12] = 1 */   effect secam v position
	no_signal_dec_reg.vsync_delay_en = 1;	/* 9314[16] = 1 */
	vdcf_outl(VDTOP_NO_SIGNAL_DEC_reg, no_signal_dec_reg.regValue);
#ifdef CONFIG_ENABLE_3D_SETTING
	drvif_module_vpq_DisableMemory();
	drvif_module_vpq_SetYcSep(VDC_YCSEPARATE_DEFAULT);
#endif

//	Scaler_SetYcSep(VDC_YCSEPARATE_DEFAULT);


//#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
#if 0
	if (VD_27M_OFF == fw_video_get_27mhz_mode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))) {
		fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
		fifo_ctrl_reg.vdec_ps_disp_27_en = 0;
		fifo_ctrl_reg.ps_updn_swap = 1;	/* 9758[2] ps swap */
		vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);

	} else {
		fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
		fifo_ctrl_reg.vdec_ps_disp_27_en = 1;
		fifo_ctrl_reg.ps_updn_swap = 1;	/* 9758[2] ps swap */
		vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);
	}
#else
	fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
	fifo_ctrl_reg.vdec_ps_disp_27_en = 0;
	fifo_ctrl_reg.ps_updn_swap = 1;	/* 9758[2] ps swap */
	vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);
#endif

	vdtop_secam_dbfreq_offset_reg.regValue = vdcf_inl(VDTOP_SECAM_DBFREQ_OFFSET_reg);
	vdtop_secam_dbfreq_offset_reg.db_offset = 0x17;	/* 20161003 for cyan */
	vdcf_outl(VDTOP_SECAM_DBFREQ_OFFSET_reg, vdtop_secam_dbfreq_offset_reg.regValue);

#ifdef VDC_print_mag
	vdcf_maskl(VDTOP_FPGA_TEST_REG2_reg, ~VDC_MSG_ALL_MSG, VDC_MSG_ALL_MSG);
#endif
	drvif_module_vdc_ResetReg();
	//VDC_DEBUG_MSG(VDC_MSG_RESET, "module_vdc_Reset\n");
}

#ifdef CONFIG_ENABLE_VD_27MHZ_MODE
void drvif_module_vdc_set_27M_mode(unsigned char mode)
{
	vdtop_fifo_ctrl_RBUS fifo_ctrl_reg;

	if (TRUE == mode) {
		fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
		fifo_ctrl_reg.vdec_ps_disp_27_en = 1;
		fifo_ctrl_reg.ps_updn_swap = 1;	/* 9758[2] ps swap */
		vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);
	} else {
		fifo_ctrl_reg.regValue = vdcf_inl(VDTOP_FIFO_CTRL_reg);
		fifo_ctrl_reg.vdec_ps_disp_27_en = 0;
		fifo_ctrl_reg.ps_updn_swap = 1;	/* 9758[2] ps swap */
		vdcf_outl(VDTOP_FIFO_CTRL_reg, fifo_ctrl_reg.regValue);
	}
	VDC_DEBUG_MSG(VDC_MSG_INIT, "drvif_module_vdc_set_27M_mode\n");
}
#endif

/**
   drvif_module_vdc_ResetReg
   Reset video registers for TV channel change

 This function only execute when TV channel change

   @param <void>       { void }
   @return                  { void }

*/
void drvif_module_vdc_ResetReg(void)
{
	vdtop_inout_ctrl_RBUS inout_ctrl_reg;
	vdtop_hdetect_vphase_status_RBUS hdetect_vphase_status_reg;
	vdtop_under_new_th1_RBUS under_new_th1_reg;

	drvif_module_vdc_SetFactoryModEnable(OFF);
	vdc_set_hactive_flag = 0;
	vlock_status = VDC_V_LOCK_DEF;

#if VDC_Error_case1
	VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 1] reset dgain: ResetReg\n");
	drvif_module_vdc_Write_Dgain_value(0xdd);
	drvif_module_vdc_set_Control2_Register(VDC_fix_dgain_disable);
	module_vdc_set_vsync_refind_sel(0x01);
#endif
#if VDC_Error_case2
	VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] reset dgain: ResetReg\n");
	module_vdc_set_fine_src_sel(Fine_ORG);
#endif
#ifdef VD_hdto_adjust
	module_vdc_set_hdto_inc(HDTO_Default);
#endif
	module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_LPF);	/* error case 5*/
	drvif_module_vdc_Disable_Auto_Burst_position();
	drvif_module_vdc_Set_Hstate(VDC_HSTATE_RESET);
	drvif_module_vdc_Set_Cstate(VDC_CSTATE_RESET);
	drvif_module_vdc_BurstGate_set(0x04a, 0x0a3);	/* set to default */
	drvif_module_vdc_set_Sep_358_thl(0x32);
	drvif_module_vdc_set_Sep_443_thl(0x32);
	module_vdc_set_gate_hv_iir(0x04);	/* 921c = 0x04 default: enable new_hpll_lpf_sel */
	drvif_module_vdc_Set_lose_chromalock_count(0x0b);	/* set to default */
	drvif_module_vdc_Set_lose_chromalock_level(0x05);		/* set to default */

	inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);
	inout_ctrl_reg.fe_bypass_sel = 0;		/* 9080[4] TV enable, AV disable */
	vdcf_outl(VDTOP_INOUT_CTRL_reg, inout_ctrl_reg.regValue);

	under_new_th1_reg.regValue = vdcf_inl(VDTOP_under_new_th1_reg);
	under_new_th1_reg.headswitch_debounce_en = 1;	/* 91bc[27]=1, set to default */
	vdcf_outl(VDTOP_under_new_th1_reg, under_new_th1_reg.regValue);

	drvif_module_vdc_Raw_vdetect_max_sel(0); /* while noisy tv max_sel=3, but ch switch lag, need back tp 0 */
	/*vloop setting */
//	drvif_module_vdc_vloop_control_set(VDC_vloop_DEFAULT);
	drvif_module_vdc_vloop_control_set(VDC_vloop_FAST);
	drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_org_vsync);

	/*secam flag setting */
	drvif_module_vdc_old_secam_flag_setting(SETTING_CONDITION_ON);

	drvif_module_vdc_SECAM_y_fir_adj(VDC_secam_y_fir_enable, VDC_hpf_bypass, VDC_y_lpf_L2p0_H6p4_MHz);

	module_vdc_SECAM_flag_select(1);

	/*443flag th*/
	hdetect_vphase_status_reg.regValue = vdcf_inl(VDTOP_HDETECT_VPHASE_STATUS_reg);
	hdetect_vphase_status_reg.hstate_err_thl = usHstate_err_thl_AVsetting;	/* 9228[29:16] = 0x060 */
	vdcf_outl(VDTOP_HDETECT_VPHASE_STATUS_reg, hdetect_vphase_status_reg.regValue);

	drvif_module_vdc_Set_CKill_Mode(CKill_AUTO);
	drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_auto);
	drvif_module_vdc_lock_h_on_no_signal(_DISABLE);
	drvif_module_vdc_ResetCVideoFH1D();//cvideo_fh_set_1d = OFF;
	drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_DISABLE);
	drvif_module_vdc_palm_flag_phase_adjust(0x80);	/* set to default */

//	Scaler_SetYcSep(VDC_YCSEPARATE_DEFAULT);

#if 0// def CONFIG_ENABLE_3D_SETTING
	Scaler_Set3DEnable(_ENABLE);
	VDC_DEBUG_MSG(VDC_MSG_YCSEP, "b3DEnablable=_ENABLE\n");
#ifdef memory_check
	Cennum_Counter = 0x00;
#endif
#endif
#ifdef CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL
	/*don't modified this func. If there has error of this funciton, please connect to jj. */
	drvif_module_vdc_set_PeakWhite(_DISABLE);
#else
	drvif_module_vdc_set_PeakWhite(_ENABLE);
#endif
	drvif_module_vdc_set_Basic_Register(VDC_BASIC_REG_ClearAll);
	drvif_module_vdc_set_Basic_Register(VDC_ped_reg_enable);
	drvif_module_vdc_clamp_rc_rate_function(_DISABLE);	/* default disable, when co-ch 1/12 enable */
	drvif_module_vdc_clear_FIFO_status();	/* clear FIFO status */
	drvif_module_vdc_set_hlock_field_cnt_Value(0x0a);		/* set to default */
	drvif_module_vdc_set_vstate_new2to3_en(_DISABLE);	/* set to default */

#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
	drvif_module_vdc_Cpeak_set(_DISABLE);
#else
	drvif_module_vdc_Cpeak_set(_ENABLE);
#endif

#ifdef CONFIG_ENABLE_VDC_MV_CHECK
	drvif_module_vdc_set_Basic_Register(VDC_hagcreg_disable);
	drvif_module_vdc_set_Control2_Register(VDC_mv_hagc_mode_off);	/* 909c[6]=0 for mv detect */
	drvif_module_vdc_Write_Dgain_value(0xdd);
	module_vdc_set_vsync_h_max(0x11);	/* 9324[6:0] for mv checked @AV source */
#endif
	drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);
	/*drvif_module_vdc_reset_Status(); */	/* cannot reset status here, AV will no signal */
#ifdef VDC_SyncReduction_test
	module_vdc_adcNegativeAdjustment(ucAdcNeg_Sing);	/* 2_0048[23:20] = 0x0e, default */
#endif
	//VDC_DEBUG_MSG(VDC_MSG_RESET, "drvif_module_vdc_ResetReg\n");
}

/**
   drvif_module_vdc_tv_Reset
   Initial video decoder module in tv

   @param <void>       { void }
   @return                  { void }

*/
void drvif_module_vdc_tv_Reset(void)
{
	vdtop_inout_ctrl_RBUS inout_ctrl_reg;
	vdtop_secam_ctrl_RBUS secam_ctrl_reg;
	vdtop_hdetect_vphase_status_RBUS hdetect_vphase_status_reg;
	vdtop_under_new_th1_RBUS under_new_th1_reg;

	drvif_module_vdc_SetFactoryModEnable(OFF);
	vdc_set_hactive_flag = 0;
	vlock_status = VDC_V_LOCK_DEF;

#if VDC_Error_case1
	VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 1] reset dgain: tv_Reset\n");
	drvif_module_vdc_Write_Dgain_value(0xdd);
	drvif_module_vdc_set_Control2_Register(VDC_fix_dgain_disable);
	module_vdc_set_vsync_refind_sel(0x01);
#endif
#if VDC_Error_case2
	VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] reset dgain: tv_Reset\n");
	module_vdc_set_fine_src_sel(Fine_ORG);
#endif
#if VDC_Error_case6
	module_vdc_set_secam_443358_flag_parameter();
#endif
#if VDC_Error_case7
	drv_module_vdc_hstate_vsync_error_init();
#endif
#if VDC_Error_case8
	module_vdc_set_fine_src_sel(Fine_ORG);
	drvif_module_vdc_set_backporch_end(0x45);
#endif
	drvif_module_vdc_Disable_Auto_Burst_position();
#ifdef VD_hdto_adjust
	module_vdc_set_hdto_inc(HDTO_Default);
#endif
	module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_LPF);	/* error case 5*/
	drvif_module_vdc_Set_Hstate(VDC_HSTATE_RESET);
	drvif_module_vdc_Set_Cstate(VDC_CSTATE_RESET);
	drvif_module_vdc_BurstGate_set(0x04a, 0x0a3);	/* set to default */
	drvif_module_vdc_set_Sep_358_thl(0x32);
	drvif_module_vdc_set_Sep_443_thl(0x32);
	drvif_module_vdc_27M_FrontDigitalFilterEnable(VDC_27M_FDF_BYPASS);
	module_vdc_set_gate_hv_iir(0x04);	/* 921c = 0x04 default: enable new_hpll_lpf_sel */

	inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);
	inout_ctrl_reg.fe_bypass_sel = 1;		/* 9080[4] TV enable, AV disable */
	vdcf_outl(VDTOP_INOUT_CTRL_reg, inout_ctrl_reg.regValue);

	under_new_th1_reg.regValue = vdcf_inl(VDTOP_under_new_th1_reg);
	under_new_th1_reg.headswitch_debounce_en = 1;	/* 91bc[27]=1, set to default */
	vdcf_outl(VDTOP_under_new_th1_reg, under_new_th1_reg.regValue);

	drvif_module_vdc_Raw_vdetect_max_sel(0); /* while noisy tv max_sel=3, but ch switch lag, need back tp 0 */
	/*vloop setting */
	drvif_module_vdc_vloop_control_set(VDC_vloop_speed1);
	drvif_module_vdc_set_Vsync_Cntl_Mode(VDC_org_vsync);

#if 1
	drvif_module_vdc_new_vdetect_Enable(Old_vedetect);
	drvif_module_vdc_set_vstate_speedup(vstate_count_fast);
#else
	drvif_module_vdc_new_vdetect_Enable(New_vedetect);
	drvif_module_vdc_set_vstate_speedup(vstate_count_default);
#endif
	/*secam flag setting */
	drvif_module_vdc_old_secam_flag_setting(SETTING_CONDITION_ON);
	/*move from module_vdc_Reset()*/
	drvif_module_vdc_SECAM_y_fir_adj(VDC_secam_y_fir_enable, VDC_hpf_bypass, VDC_y_lpf_L2p0_H6p4_MHz);

#if 1
	secam_ctrl_reg.regValue = vdcf_inl(VDTOP_SECAM_CTRL_reg);
#ifdef CONFIG_EUROPE_AUTO_SCAN_FLOW
	secam_ctrl_reg.secam_flag_sel = 1;
#else
	secam_ctrl_reg.secam_flag_sel = 0;
#endif
	vdcf_outl(VDTOP_SECAM_CTRL_reg, secam_ctrl_reg.regValue);
#endif

	/*443flag th*/
	/* 	drvif_module_vdc_PreferModeSetting(PREFER_DEFAULT); */
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
	drvif_module_vdc_Cpeak_set(_DISABLE);
#else
	drvif_module_vdc_Cpeak_set(_ENABLE);
#endif
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
	drvif_module_vdc_set_Basic_Register(VDC_hagcreg_disable);
	drvif_module_vdc_set_Control2_Register(VDC_mv_hagc_mode_on);	/* 909c[6]=1  set default @TV source */
	drvif_module_vdc_Write_Dgain_value(0xdd);	/* 90a0[7:0] set to default */
	module_vdc_set_vsync_h_max(0x0e);	/* 9324[6:0] set default @TV source */
#endif

	/* vcr threshold setting : TV => default (0x400) */
	hdetect_vphase_status_reg.regValue = vdcf_inl(VDTOP_HDETECT_VPHASE_STATUS_reg);
	hdetect_vphase_status_reg.hstate_err_thl = usHstate_err_thl_Default;	/* 9228[29:16] = 0x400 */
	vdcf_outl(VDTOP_HDETECT_VPHASE_STATUS_reg, hdetect_vphase_status_reg.regValue);

	drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_auto);
	drvif_module_vdc_lock_h_on_no_signal(_DISABLE);
	drvif_module_vdc_ResetCVideoFH1D();//cvideo_fh_set_1d = OFF;
	drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_DISABLE);
	drvif_module_vdc_palm_flag_phase_adjust(0x80);	/* set to default */

	drvif_module_vdc_clamp_rc_rate_function(_DISABLE);	/* default disable, when co-ch 1/12 enable */
	drvif_module_vdc_Set_lose_chromalock_count(0x0b);	/* set to default */
	drvif_module_vdc_set_vstate_new2to3_en(_DISABLE);	/* set to default */
	drvif_module_vdc_Set_lose_chromalock_level(0x04);
	drvif_module_vdc_mode_speedup(mode_count_default);
	drvif_module_vdc_clear_FIFO_status();	/* clear FIFO status */
	if (tvAutoScanFlag) {
		drvif_module_vdc_set_PeakWhite(_DISABLE);
		drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
		drvif_module_vdc_set_hlock_field_cnt_Value(0x0a);		/* set to default */
		//VDC_DEBUG_MSG(VDC_MSG_RESET, "TV auto scan........\n");
	} else {
#ifdef CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL
		/*don't modified this func. If there has error of this funciton, please connect to jj. */
		drvif_module_vdc_set_PeakWhite(_DISABLE);
#else
		drvif_module_vdc_set_PeakWhite(_ENABLE);
#endif
		drvif_module_vdc_set_vsync_freerun_enable(_ENABLE);
#ifdef CONFIG_ENABLE_VDC_OVER_MODULATION
		drvif_module_vdc_set_hlock_field_cnt_Value(0x05);
#else
		drvif_module_vdc_set_hlock_field_cnt_Value(0x02);
#endif
		//VDC_DEBUG_MSG(VDC_MSG_RESET, "TV channel play \n ");
	}
	drvif_module_vdc_reset_Status();
	//VDC_DEBUG_MSG(VDC_MSG_RESET, "drvif_module_vdc_tv_Reset \n");
}

/* ========================================================================= */
/* === VD check h / v / c locked functions ========================================== */
/**
   drvif_module_vdc_Exist
   Check VDC signal is the same or not

   @param <ucInputSrc>   { Input source }
   @return <unsigned char>          { return TRUE if mode is stable,
                                         return FALSE if mode changed }

*/
unsigned char drvif_module_vdc_Exist(unsigned char ucInputSrc)
{
	unsigned char firstIN = 1;

#ifdef _jj_change_lock_function
	while (vdc_LockStatus)
#else
	while (drvif_video_status_reg(VDC_hv_lock))
#endif
	{
		/*              if (_MODE_576I == CTVGetVideoResolutin()) */
		/* Turn off VDC free run, output 525 line */
		drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);

		drvif_module_vdc_IdentifyColorStandard(ucInputSrc);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "VDC exist, mode : %x\n", ucVdc_Curr_Mode);

		if (firstIN) {
			ucVdc_Pre_Mode = ucVdc_Curr_Mode;
			firstIN = 0;
			continue;
		}

		if (ucVdc_Pre_Mode == ucVdc_Curr_Mode) {

			Scaler_ModeSetModeInfo(SLR_MODE_MODECURR, ucVdc_Curr_Mode);
			Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode);

			/* nosignal should return false, then switch to free run */
			if (ucVdc_Curr_Mode == _MODE_NOSIGNAL) {
				return FALSE;
			}
			return TRUE;
		} else {
			ucVdc_Pre_Mode = ucVdc_Curr_Mode;
			drvif_module_vdc_IdentifyColorStandard(ucInputSrc);
			if (ucVdc_Pre_Mode == ucVdc_Curr_Mode) {
				Scaler_ModeSetModeInfo(SLR_MODE_MODECURR, ucVdc_Curr_Mode);
				Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode);

				/* nosignal should return false, then switch to free run */
				if (ucVdc_Curr_Mode == _MODE_NOSIGNAL) {
					return FALSE;
				}
				return TRUE;
			}

			Scaler_ModeSetModeInfo(SLR_MODE_MODECURR, ucVdc_Curr_Mode);
			Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode);

			VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "exist --False 1 -- pre_mode=%x, cur_mode=%x\n", ucVdc_Pre_Mode, ucVdc_Curr_Mode);
			return FALSE;
		}
	}

	Scaler_ModeSetModeInfo(SLR_MODE_MODECURR, _MODE_NOSIGNAL);
	Scaler_DispInfoSetModeCurr(_MODE_NOSIGNAL);
	return FALSE;
}

unsigned char drvif_module_vdc_Exist_noScaler(unsigned char ucInputSrc)
{
	unsigned char firstIN = 1;

#ifdef _jj_change_lock_function
	while (vdc_LockStatus)
#else
	while (drvif_video_status_reg(VDC_hv_lock))
#endif
	{

		/*              if (_MODE_576I == CTVGetVideoResolutin()) */
		/* Turn off VDC free run, output 525 line */
		drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);

		drvif_module_vdc_IdentifyColorStandard(ucInputSrc);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "VDC exist[noScaler], mode : %x\n", ucVdc_Curr_Mode);

		if (firstIN) {
			ucVdc_Pre_Mode = ucVdc_Curr_Mode;
			firstIN = 0;
			continue;
		}

		if (ucVdc_Pre_Mode == ucVdc_Curr_Mode) {
			/*Scaler_ModeSetModeInfo(SLR_MODE_MODECURR,ucVdc_Curr_Mode); */
			/*Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode); */
			/* nosignal should return false, then switch to free run */
			if (ucVdc_Curr_Mode == _MODE_NOSIGNAL) {
				return FALSE;
			}
			return TRUE;
		} else {
			ucVdc_Pre_Mode = ucVdc_Curr_Mode;
			drvif_module_vdc_IdentifyColorStandard(ucInputSrc);
			if (ucVdc_Pre_Mode == ucVdc_Curr_Mode) {
				/*Scaler_ModeSetModeInfo(SLR_MODE_MODECURR,ucVdc_Curr_Mode); */
				/*Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode); */
				/* nosignal should return false, then switch to free run */
				if (ucVdc_Curr_Mode == _MODE_NOSIGNAL) {
					return FALSE;
				}
				return TRUE;
			}
			/*Scaler_ModeSetModeInfo(SLR_MODE_MODECURR,ucVdc_Curr_Mode); */
			/*Scaler_DispInfoSetModeCurr(ucVdc_Curr_Mode); */
			VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "--False 1 -- pre_mode=%x, cur_mode=%x\n", ucVdc_Pre_Mode, ucVdc_Curr_Mode);
			return FALSE;
		}
	}

	/*Scaler_ModeSetModeInfo(SLR_MODE_MODECURR,_MODE_NOSIGNAL); */
	/*Scaler_DispInfoSetModeCurr(_MODE_NOSIGNAL); */
	return FALSE;
}


/**
	drvif_module_vdc_CheckHVisLocked
	Check whether signal locked or not
	Check video decoder's if input signal stable when TV input.
	This function will query the video decoder's status register.
	If TV input is stable return _SUCCESS, else return _FAIL.

	@param <void>		{ void }
	@return <unsigned char>		{ return _SUCCESS if mode is stable,
						   return _FAIL if mode changed }

*/
#define CHANNEL_CHANGE_TIMEOUT	25
static unsigned char g_ucChChangeCount = 0;

void drvif_module_vdc_ResetChChangeCount(void)
{
	g_ucChChangeCount = 0;
}

#ifdef VIDEO_DEBUG_ENABLE_RECROD
static inline void debug_record_prepare_hvlocked(void)
{
	debug_set_dump_hvlocked(true);
	module_video_debug_record_start();
}

static inline void debug_record_handle_hvlocked(bool is_debug)
{
	module_video_debug_record_stop();
	debug_set_dump_hvlocked(false);

	if (is_debug) {
		module_video_debug_record_show(VDTOP_VIDEO_STATUS_REG1_reg);
		module_video_debug_record_show(VDTOP_VIDEO_STATUS_REG2_reg);
		module_video_debug_record_show(VDTOP_VIDEO_STATUS_REG3_reg);
	} else {
		module_video_debug_record_clear(VDTOP_VIDEO_STATUS_REG1_reg);
		module_video_debug_record_clear(VDTOP_VIDEO_STATUS_REG2_reg);
		module_video_debug_record_clear(VDTOP_VIDEO_STATUS_REG3_reg);
	}
}
#else
#define debug_record_prepare_hvlocked() \
	do { debug_set_dump_hvlocked(true); } while (0)
#define debug_record_handle_hvlocked(is_debug) \
	do { debug_set_dump_hvlocked(false); } while (0)
#endif /* VIDEO_DEBUG_ENABLE_RECROD */

#ifdef CONFIG_CUSTOMER_TV010
/* for ATV scanning */
unsigned char drvif_module_vdc_CheckHVisLocked_TVScan(void)
{
	unsigned char result = 0;

	debug_record_prepare_hvlocked();

	if (module_vdc_read_Wrong_if_pc_detect_flag() == 0) {
		result = drvif_video_status_reg(VDC_hlock);
		VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan] Is good pc carry, h lock :%x\n", result);
		video_logk("WPC:0->HLOCK:%d->RET:%x\n", (result ? 1 : 0), result);
		debug_record_handle_hvlocked(result == 0);
		return result;
	} else {
		VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan] if lock not on pc carry ! check more\n");
		result = drvif_video_status_reg(VDC_no_signal);
		if (result == 0) {
			unsigned int vdc_hlock = drvif_video_status_reg(VDC_hlock);
			if (vdc_hlock == 1) {
				unsigned int vdc_vlock = drvif_video_status_reg(VDC_vlock);
				unsigned int vdc_vlock_new = drvif_video_status_reg(VDC_vlock_new);

				VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan] oV:%x, nV:%x\n", vdc_vlock, vdc_vlock_new);
				video_logk("OV:%x NV:%x\n", vdc_vlock, vdc_vlock_new);
				if (vdc_vlock == 1) {
					unsigned int line_1 = drvif_module_vdc_read_V_1st_line();
					unsigned int line_2 = drvif_module_vdc_read_V_2nd_line();
					unsigned int line_diff = ABS(line_1, line_2);

					video_logk("L1:%x L2:%x LDIFF:%x\n", line_1, line_2, line_diff);
					if ((line_1 > 0x0100) && (line_2 > 0x0100)) {
						VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan]L1:%x, L2:%x, diff:%x\n", line_1, line_2, line_diff);
						if (line_diff < 20)
							result = 1;
					}
					video_logk("WPC:1->NOSIG:0->HLOCK:1->VLOCK:1->RET:%x\n", result);
				} else {
					video_logk("WPC:1->NOSIG:0->HLOCK:1->VLOCK:0->RET:%x\n", result);
				}
			} else {
				video_logk("WPC:1->NOSIG:0->HLOCK:0->RET:x\n", result);
			}
			VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan] result:%x\n", result);
			debug_record_handle_hvlocked(result == 0);
			return result;
		} else {	/* no signal */
			VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "[TVScan] no signal \n");
			video_logk("WPC:1->NOSIG:1->RET:0\n");
			debug_record_handle_hvlocked(true);
			return 0;
		}
	}
}
#endif

unsigned char drvif_module_vdc_CheckHVisLocked(void)
{
	unsigned char result = 0;

#ifdef _jj_change_lock_function
	if (drvif_module_vdc_read_Clamping_path()) { /* is TV */
		/* For ATV auto scan */
		if (drvif_module_vdc_read_scan_flag()) {
			debug_record_prepare_hvlocked();

			g_ucChChangeCount = 0;

			if (module_vdc_read_Wrong_if_pc_detect_flag() == 0) {
				result = drvif_video_status_reg(VDC_hlock);
				VDC_DEBUG_MSG(VDC_MSG_TVSCAN, " Is good pc carry, h lock :%x\n", result);
				video_logk("SCAN:1->WPC:0->HLOCK:%d->RET:%x\n", (result ? 1 : 0), result);
				debug_record_handle_hvlocked(result == 0);
				return result;
			} else {
				VDC_DEBUG_MSG(VDC_MSG_TVSCAN, " if lock not on pc carry ! check more\n");
				result = drvif_video_status_reg(VDC_no_signal);
				if (result == 0) {
					unsigned int vdc_hlock = drvif_video_status_reg(VDC_hlock);
					if (vdc_hlock == 1) {
						unsigned int vdc_vlock = drvif_video_status_reg(VDC_vlock);
						unsigned int vdc_vlock_new = drvif_video_status_reg(VDC_vlock_new);
						unsigned int vdc_dgain = drvif_module_vdc_read_Dgain();
						unsigned int vdc_noise_status = vdcf_inl(VDTOP_NOISE_STATUS_reg);

						video_logk("OV:%x NV:%x DG:%x NS:%x\n", 
							   vdc_vlock, vdc_vlock_new,
							   vdc_dgain, vdc_noise_status);

						VDC_DEBUG_MSG(VDC_MSG_TVSCAN, " oV:%x, nV:%x, dg:%x, ns:%x\n",
									  vdc_vlock, vdc_vlock_new,
									  vdc_dgain, vdc_noise_status);
						if ((vdc_vlock == 1) && (vdc_noise_status <= 0xff)) {
							unsigned int line_1 = drvif_module_vdc_read_V_1st_line();
							unsigned int line_2 = drvif_module_vdc_read_V_2nd_line();
							unsigned int line_diff = ABS(line_1, line_2);

							video_logk("L1:%x L2:%x LDIFF:%x\n", line_1, line_2, line_diff);
							if ((line_1 > 0x0100) && (line_2 > 0x0100)) {
								VDC_DEBUG_MSG(VDC_MSG_TVSCAN, "L1:%x, L2:%x, diff:%x\n", line_1, line_2, line_diff);
								if (line_diff < 50)
									result = 1;
							}
							video_logk("SCAN:1->WPC:1->NOSIG:0->HLOCK:1->VLOCK:1->RET:%x\n", result);
						} else {
							if (vdc_vlock == 0) {
								video_logk("SCAN:1->WPC:1->NOSIG:0->HLOCK:1->VLOCK:0->RET:%x\n", result);
							} else {
								video_logk("SCAN:1->WPC:1->NOSIG:0->HLOCK:1->VLOCK:1->RET:%x\n", result);
							}
						}
					} else {
						video_logk("SCAN:1->WPC:1->NOSIG:0->HLOCK:0->RET:x\n", result);
					}

					debug_record_handle_hvlocked(result == 0);
					VDC_DEBUG_MSG(VDC_MSG_TVSCAN, " result:%x\n", result);
					return result;
				} else {	/* no signal */
					VDC_DEBUG_MSG(VDC_MSG_TVSCAN, " no signal \n");
					video_logk("SCAN:1->WPC:1->NOSIG:1->RET:0\n");
					debug_record_handle_hvlocked(true);
					return 0;
				}
			}
			/* For ATV channel change */
		} else if (drvif_module_vdc_read_ch_change_flag()) {
			VDC_DEBUG_MSG(VDC_MSG_TVCHCH_DETAIL, "ATV channel change\n");

			if (vdc_LockStatus == 1) {
				g_ucChChangeCount++;
				if (drvif_module_vdc_OutputStable() == TRUE) {
					g_ucChChangeCount = 0;
					return _SUCCESS;
				} else if (g_ucChChangeCount >= CHANNEL_CHANGE_TIMEOUT) {
					g_ucChChangeCount = CHANNEL_CHANGE_TIMEOUT;
					drvif_module_vdc_set_vstate_new2to3_en(_ENABLE);	/* vstate != 3, set */
					return _SUCCESS;
				} else
					return _FAIL;
			} else {
				g_ucChChangeCount = 0;
				return _FAIL;
			}
		} else {
			return vdc_LockStatus;
		}
	} else {	/* is AV */
		return vdc_LockStatus;
	}
#else
	if (drvif_video_status_reg(VDC_hv_lock))
		return _SUCCESS;
	else
		return _FAIL;
#endif
}

unsigned char drvif_video_BurstLockStatus(void)
{
	return vdc_BurstLockStatus;
}

void drvif_module_vdc_reset_Status(void)
{
	vdc_LockStatus = 0x0;
	vdc_ChromaLockStatus = 0x0;
	vdc_BurstLockStatus = 0x0;
	vdc_AnyVCRStatus = 0x0;
//	vdc_625flag = 0x0;
	vdc_NoiseStatus = 0x00;
	vdc_ucLockCounter = 0x0;
	vdc_ucNoSignalCounter = 0x0;
	vdc_LoopCount = 0x00;
	vdc_ucLockCount = 10;
	vdc_ucChromaLockCount = 10;
	vdc_ucBurstLockCount = 10;
	vdc_ucAnyVCRCount = 10;
	vdc_uc625flagCount = 10;
	vlock_status = VDC_V_LOCK_DEF;
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
	vdc_MvFlag = 0x0;
	vdc_ucMvCount = 10;
#endif
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	vdc_OldVLockStatus = 0x0;
	vdc_ucOldVLockCount = 10;
#endif
}

#define VDreg_NoAck (0xdeaddead)
/**
	drvif_module_vdc_CheckInputStatus
	Check video decoder's if input signal is standard or nonstandard.
	This function will modify the settings of video decoder to make sure the
	output is Okey.

	@param <void>		{ void }
	@return <status>		{ vdc_LockStatus / vdc_ChromaLockStatus
						vdc_BurstLockStatus / vdc_AnyVCRStatus
						vdc_OldVLockStatus / vdc_MvFlag
						vdc_NoiseStatus
*/
void drvif_module_vdc_Status_Loop(void)
{
	vdtop_video_status_reg1_RBUS video_status_reg1_reg;
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;
	vdtop_video_status_reg3_RBUS video_status_reg3_reg;
	vdtop_noise_status_RBUS noise_status_reg;
	unsigned int usTemp = 0x00;
	
	video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
	video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
	video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
	noise_status_reg.regValue = vdcf_inl(VDTOP_NOISE_STATUS_reg);
	if ((video_status_reg1_reg.regValue == VDreg_NoAck) ||
		(video_status_reg2_reg.regValue == VDreg_NoAck) ||
		(video_status_reg3_reg.regValue == VDreg_NoAck) ||
		(noise_status_reg.regValue == VDreg_NoAck))
		return;

	vdc_LoopCount++;
	if ((vdc_LoopCount & 0x03) == 0x00) {
		/* get h/v lock status */
		if (vdc_ucLockCount < 9)
			vdc_LockStatus = 0;
		else
			vdc_LockStatus = 1;
		vdc_ucLockCount = 10;
		/* get c lock status */
		if (vdc_ucChromaLockCount < 9)
			vdc_ChromaLockStatus = 0;
		else
			vdc_ChromaLockStatus = 1;
		vdc_ucChromaLockCount = 10;
		/* get burst status */
		if (vdc_ucBurstLockCount < 9)
			vdc_BurstLockStatus = 0;
		else
			vdc_BurstLockStatus = 1;
		vdc_ucBurstLockCount = 10;
		/* get any vcr (vcr||vcr_trick||vcr_ff||vcr_rew) status */
		if (vdc_ucAnyVCRCount < 11)
			vdc_AnyVCRStatus = 0;
		else
			vdc_AnyVCRStatus = 1;
		vdc_ucAnyVCRCount = 10;
		/* get 625 flag */
		if (vdc_uc625flagCount < 11)
			vdc_625flag = 0;
		else
			vdc_625flag = 1;
		vdc_uc625flagCount = 10;
		/* get mv flag */
		if (vdc_ucMvCount < 9)
			vdc_MvFlag = 0;
		else
			vdc_MvFlag = 1;
		vdc_ucMvCount = 10;
#if	1//def CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
		/* get old V lock flag */
		if (vdc_ucOldVLockCount < 9)
			vdc_OldVLockStatus = 0;
		else
			vdc_OldVLockStatus = 1;
		vdc_ucOldVLockCount = 10;
#endif
		VDC_DEBUG_MSG(VDC_MSG_STATUS, "[loop][LK] vdc_LockStatus = %x\n", vdc_LockStatus);
		VDC_DEBUG_MSG(VDC_MSG_STATUS, "[loop][CLK] vdc_ChromaLockStatus = %x\n", vdc_ChromaLockStatus);
		VDC_DEBUG_MSG(VDC_MSG_STATUS, "[loop][VCR] vdc_AnyVCRStatus = %x\n", vdc_AnyVCRStatus);
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
		VDC_DEBUG_MSG(VDC_MSG_STATUS, "[loop][MV] vdc_MvFlag = %x\n", vdc_MvFlag);
#endif
		VDC_DEBUG_MSG(VDC_MSG_STATUS, "[loop][NS] vdc_NoiseStatus = %x\n", vdc_NoiseStatus);
	} else {
		/* get h/v lock status */
		if (((video_status_reg1_reg.regValue & 0x07) == 0x06)
			|| ((video_status_reg1_reg.hlock) && (video_status_reg2_reg.vlock_new))) {
			vdc_ucLockCount++;
		} else {
			vdc_ucLockCount--;
		}
		/* get c lock status */
		if (video_status_reg1_reg.chomalock) {
			vdc_ucChromaLockCount++;
		} else {
			vdc_ucChromaLockCount--;
		}
		/* get burst status */
		if (video_status_reg2_reg.burst_detect) {
			vdc_ucBurstLockCount++;
		} else {
			vdc_ucBurstLockCount--;
		}
		/* get any vcr (vcr||vcr_trick||vcr_ff||vcr_rew) status */
		if ((video_status_reg3_reg.regValue & 0xf0) != 0x00) {
			vdc_ucAnyVCRCount++;
		} else {
			vdc_ucAnyVCRCount--;
		}
		/* get 625 flag */
		if (video_status_reg3_reg.lines_625_detected) {
			vdc_uc625flagCount++;
		} else {
			vdc_uc625flagCount--;
		}
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
		/* get mv flag */
		if (drvif_video_status_reg(VDC_mv_detect)) {
			vdc_ucMvCount++;
		} else {
			vdc_ucMvCount--;
		}
#endif
#if	1//def CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
		/* get old V lock flag */
		if (video_status_reg1_reg.vlock) {
			vdc_ucOldVLockCount++;
		} else {
			vdc_ucOldVLockCount--;
		}
#endif
	}

	/* read noise_status for 8 times(100~120mS), and take the average */
	/*don't modified this func. If there has error of this funciton, please connect to jj. */
	if ((vdc_LockStatus == 1) && (vdc_ucLockCounter > 10)) {
		ucNoiseTmp[(vdc_LoopCount & 0x07)] = noise_status_reg.status_noise;
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "[%d] ns=%x\n", (vdc_LoopCount & 0x7), noise_status_reg.status_noise);
#if 0
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "[%d] NT[0]=%x, NT[1]=%x, NT[2]=%x, NT[3]=%x",
					  (vdc_LoopCount & 0x7), ucNoiseTmp[0], ucNoiseTmp[1], ucNoiseTmp[2], ucNoiseTmp[3]);
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "[%d] NT[4]=%x, NT[5]=%x, NT[6]=%x, NT[7]=%x",
					  (vdc_LoopCount & 0x7), ucNoiseTmp[4], ucNoiseTmp[5], ucNoiseTmp[6], ucNoiseTmp[7]);
#endif
		usTemp = (ucNoiseTmp[0] + ucNoiseTmp[1] + ucNoiseTmp[2] + ucNoiseTmp[3] +
				  ucNoiseTmp[4] + ucNoiseTmp[5] + ucNoiseTmp[6] + ucNoiseTmp[7]) >> 3;
#if 0
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "[%x] usTemp=%x", vdc_LoopCount, usTemp);
#endif
		vdc_NoiseStatus = usTemp & 0x000000ff;
		VDC_DEBUG_MSG(VDC_MSG_DGAIN, "NS=%x\n", vdc_NoiseStatus);
	}
}

/**
	drvif_module_vdc_CheckInputStatus
	Check video decoder's if input signal is standard or nonstandard.
	This function will modify the settings of video decoder to make sure the
	output is Okey.

	@param <void>		{ void }
	@return <void>		{ void }
*/
void drvif_module_vdc_CheckInputStatus(unsigned char ucInputSrc, unsigned char ucCheckStart)
{

	vdtop_fpga_test_reg1_RBUS fpga_test_reg1_reg;
	unsigned int ui_9008 ;
	bool unBalance_flag ;
	unsigned short Hdetect_err ;
	unsigned char HState ;
#if 0
	if (module_vdc_check_pll27x_setting() == FALSE) {
		VDC_DEBUG_MSG(VDC_MSG_ERROR, "PLL27x did not setting good! \n");
		return;
	}
#endif

	vdtop_fpga_test_reg2_RBUS fpga_test_reg2_reg;
	fpga_test_reg2_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG2_reg);
	rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"VDTOP_FPGA_TEST_REG2_reg==%x\n", fpga_test_reg2_reg.regValue);
	if (fpga_test_reg2_reg.regValue != VDreg_NoAck)
	{
		g_vdc_msg_level = fpga_test_reg2_reg.fpga_test2;
	} else {
		rtd_printk(KERN_INFO, TAG_NAME_VDC,"(dead==>)VDTOP_FPGA_TEST_REG2_reg==%x\n", fpga_test_reg2_reg.regValue);
		return;
	}

	//drvif_module_vdc_Status_Loop();

	/* ========================================================================= */
	fpga_test_reg1_reg.regValue = vdcf_inl(VDTOP_FPGA_TEST_REG1_reg);
	if (fpga_test_reg1_reg.regValue != VDreg_NoAck)
	{
		if (fpga_test_reg1_reg.factory_flag)
		{
			UINT32 ucTestDmaLength = ((fpga_test_reg1_reg.fw_dma_size & 0x00000007) << 23);
			rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"VDTOP_FPGA_TEST_REG1_reg==%x\n", fpga_test_reg1_reg.regValue);
			/* memory size=>96b0[7:5] = 100(bit7,32M); 010(bit6,16M); 001(bit5,8M) */
			/* mode=>96b0[4:1], enable=>96b0[0] */
//			UINT8 ucTestDmaMode = (fpga_test_reg1_reg.fw_dma_mode & 0x0f);
			drvif_module_vdc_factory_TestDMA_mode_select(fpga_test_reg1_reg.fw_dma_mode);
			drvif_module_vdc_factory_TestDMA_Enable(ucTestDmaLength);
			drvif_module_vdc_clean_factory_flag();
		}
	} else {
		rtd_printk(KERN_INFO, TAG_NAME_VDC,"(dead==>)VDTOP_FPGA_TEST_REG1_reg==%x\n", fpga_test_reg1_reg.regValue);
//		return;
	}

	drvif_module_vdc_SetFactoryModEnable((g_vdc_msg_level & VDC_Factory_Mode_debug) >> 31);
	/* 96b4[31]=factory mode flag */
	if (drvif_module_vdc_CheckFactoryModEnable(ON)) {
		return;
	}
	/* ========================================================================= */
	if (vdc_LockStatus & ucCheckStart) {
		vdc_ucNoSignalCounter = 0x0;
		if (vdc_ucLockCounter == 0) {
			VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "Signal in !!\n");
			VDC_DEBUG_MSG(VDC_MSG_DGAIN, " signal in !!\n");
			if ((ucInputSrc == _SRC_TV) && (drvif_module_vdc_read_Clamping_path() == 0)) {
				drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);
#ifdef VDC_SyncReduction_test
				module_vdc_adcNegativeAdjustment(ucAdcNeg_Sing);
#endif
			}
#ifdef VDC_SyncReduction_test
			else if (ucInputSrc == _SRC_CVBS) {
				module_vdc_adcNegativeAdjustment(ucAdcNeg_Sing);
			}
#endif
		}
#if 0
		if (ucInputSrc == _SRC_TV) {
			if ((vdc_ucLockCounter > 0x30) && (vdc_ucLockCounter < 0x35)) {
				drvif_module_vdc_Set_CKill_Value(0x08);	// set to default
			}
		}
#endif
#ifdef CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL
		/*don't modified this func. If there has error of this funciton, please connect to jj. */
		/* All source */
		if (vdc_ucLockCounter == 5) {
			if (drvif_module_vdc_read_PeakWhite() == 0) {
				VDC_DEBUG_MSG(VDC_MSG_DGAIN, "Enable pw. Signal !!\n");
				drvif_module_vdc_set_PeakWhite(_ENABLE);
			}
		}
#endif
		if (vdc_ucLockCounter == 150) {
			drvif_module_vdc_Set_lose_chromalock_count(0x0b);	/* set to default */
			drvif_module_DMA_CHK3D_ENABLE_control(VDC_CHANEL_DISPLAY_MODE);/*set DMA_CHK3D_ENABLE control*/
		}
		if (((ucInputSrc == _SRC_TV) & ucCheckStart) && (vdc_ucLockCounter > 6)) {
			if (drvif_video_status_reg(VDC_noisy)) {
				drvif_module_vdc_Raw_vdetect_max_sel(3);
				drvif_module_vdc_set_vsync_freerun_enable(_ENABLE);
			} else {
				drvif_module_vdc_Raw_vdetect_max_sel(0);
				drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
			}
		}
		if (vdc_ucLockCounter == 0xfffffff0)
			vdc_ucLockCounter = 201;
		vdc_ucLockCounter ++;

		if ((g_vdc_msg_level & VDC_MSG_DEBUG_P) == VDC_MSG_DEBUG_P) {
			unsigned char ucMode_S = drvif_module_vdc_ReadMode(VDC_SET);
			unsigned char ucMode_D = drvif_module_vdc_ReadMode(VDC_DETECT);
			unsigned int uiDgain = drvif_module_vdc_read_Dgain();
			unsigned int uiCgain = vdcf_inl(VDTOP_CGAIN_STATUS_reg);
			unsigned int ui_9008 = drvif_video_status_reg(VDC_STATUS_REG1);
			unsigned char ucVCRflag = drvif_video_status_reg(VDC_vcr_any);
			unsigned char ucBurstMag = drvif_module_vdc_burst_mag_status();
			unsigned char noisy_vbi = drvif_video_status_reg(VDC_noisy_vbi);
			unsigned char coch_flag_1 = vdcf_inl(VDTOP_DC_COCH_SEPERATE_1_reg)&_BIT31;
			unsigned char coch_flag_2 = vdcf_inl(VDTOP_DC_COCH_SEPERATE_1_reg)&_BIT7;
			VDC_DEBUG_MSG(VDC_MSG_DEBUG_P, "set_M=%x, Det_M=%x\n", ucMode_S, ucMode_D);
			VDC_DEBUG_MSG(VDC_MSG_DEBUG_P, "Dgain=%x, Cgian=%x\n", uiDgain, uiCgain);
			VDC_DEBUG_MSG(VDC_MSG_DEBUG_P, "9008=%x, vcr=%x\n", ui_9008, ucVCRflag);
			VDC_DEBUG_MSG(VDC_MSG_DEBUG_P, "NS=%x, BurstM=%x\n", vdc_NoiseStatus, ucBurstMag);
			VDC_DEBUG_MSG(VDC_MSG_DEBUG_P, "NoisyVBI=%x, coch1=%x, coch2=%x\n", noisy_vbi, coch_flag_1, coch_flag_2);
		}
		drvif_module_vpq_YcSeparation(ucInputSrc, g_ucVDMode, _ENABLE);

#ifdef CONFIG_VD_AUTO_BURST_POS_ENABLE
		module_vdc_set_Burst_position(drvif_module_vdc_ReadMode(VDC_SET));
#endif
		drvif_module_vdc_Chroma_control(ucInputSrc);

#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
		drvif_module_vdc_Cpeak_control(ucInputSrc);
#endif

		if (ucInputSrc == _SRC_CVBS) {
			if (vdc_AnyVCRStatus) {
				drvif_module_vdc_Set_VCR_mode();
			}
#ifdef CONFIG_ENABLE_VDC_MV_CHECK
			if (vdc_MvFlag) {
				if (vlock_status == VDC_V_LOCK_DEF) {
					drvif_module_vdc_set_mv_function();
					vlock_status = VDC_V_MV_SIGNAL;	/* set old v detect */
				}
			}
#endif
		} else if (ucInputSrc == _SRC_TV) {
			if (vdc_ucLockCounter == 80)
				VDC_DEBUG_MSG(VDC_MSG_DGAIN, " 80 !!!!! \n");
			if (drvif_module_vdc_read_PeakWhite() == 1) {
				if ((vdc_ucLockCounter > 80) && (vdc_NoiseStatus >= 0xb0)) {
					VDC_DEBUG_MSG(VDC_MSG_DGAIN, "[%d] pw disable, ns=%x\n", vdc_ucLockCounter, vdc_NoiseStatus);
					drvif_module_vdc_set_PeakWhite(_DISABLE);
				}
			}
#ifdef VDC_weak_signal
			/* weak signal for PAL / SECAM */
			if (drvif_video_status_reg(VDC_Lines_625_detected)) {
				if (vdc_NoiseStatus < 0x5a) {
					if (!drvif_module_vdc_ReadAutomode()) {
						VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV] set auto mode\n");
					}
				} else {
					if (drvif_module_vdc_ReadAutomode()) {
						unsigned char ucMode = drvif_module_vdc_ReadMode(VDC_DETECT);
						if ((vdc_NoiseStatus > 0x6a) && (ucMode == VDC_MODE_PALI)) {
							VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV] fix PAL\n");
							drvif_module_vdc_SetMode(VDC_MODE_PALI);
						} else if ((vdc_NoiseStatus > 0x65) && (ucMode == VDC_MODE_SECAM)) {
							VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV] fix SECAM\n");
							drvif_module_vdc_SetMode(VDC_MODE_SECAM);
						}
					}
				}
			}
#endif
			if (drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_NTSC) {
#if VDC_Error_case1
				/* case 1: ATSC_081202_0925_337.00M_-37.18_20M_-32.77_LAN_FieldSignal(ch3)*/
				unsigned int ui_Dgain = drvif_module_vdc_read_Dgain();
				if ((vdc_NoiseStatus >= 0x95) && (ui_Dgain < 0x250)) {
					unsigned int ui_9008 ;
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 1] vdc_NoiseStatus=%x, dgain=%x\n", vdc_NoiseStatus, ui_Dgain);
					ui_9008 = drvif_video_status_reg(VDC_STATUS_REG1) & 0x00000fff;
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 1] 9008[11:0]=%x\n", ui_9008);
					if (ui_9008 == 0x031a) {
						VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 1] Fix Dgain !!!!\n");
						drvif_module_vdc_Write_Dgain_value(0xc0);
						drvif_module_vdc_set_Control2_Register(VDC_fix_dgain_enable);
						module_vdc_set_vsync_refind_sel(0x00);
						module_vdc_set_gate_hv_iir(0x05);
					}
				}
#endif
#if VDC_Error_case2
				/* f1-14 */
				unsigned int noisy_vbi = drvif_video_status_reg(VDC_noisy_vbi);
				if ((vdc_NoiseStatus > 0x10) && (noisy_vbi == 1)) {
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] noisy_vbi=%x\n", noisy_vbi);
					unsigned int ui_9008 = drvif_video_status_reg(VDC_STATUS_REG1);
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] 9008=%x\n", ui_9008);
//					if (ui_9008 == 0x00007106) {
					unsigned char ucBurstMag = drvif_module_vdc_burst_mag_status();
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] ucBurstMag=%x\n", ucBurstMag);
					if (ucBurstMag >= 0x2a) {
						module_vdc_set_fine_src_sel(Fine_LPS);
					}
//					}
				}
#endif
#if VDC_Error_case7
				unBalance_flag = (bool)drvif_module_vdc_read_hstate_vsync_error_unbalance();
				Hdetect_err = drvif_module_vdc_Hdetect_err_var_status();
				HState = drvif_module_vdc_Read_Hstate_Factory_Mode_Get_info();
				//printf("drv_module_vdc_Hstate_control!! Hstate=%d,err=%x,flag=%d \n",HState,Hdetect_err,unBalance_flag);
				if ((g_hstate_vsync_error_unbalance_status_cnt == 2) && (g_Hdetect_error_cnt == 8)) {
					g_hstate_vsync_error_unbalance_status_cnt = 0;	// Reset flag
					g_hstate_vsync_error_unbalance_status_result = 0;
					g_Hdetect_error_cnt = 0;
					g_Hdetect_error_avg = 0;
					if ((5 == HState) && (2 <= drvif_module_vdc_Read_Vstate())) {	// make sure signal stable
						if ((_TRUE == unBalance_flag) && (0xa0 < Hdetect_err))
							// just one time achieve then go fix hstate
						{
							VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 7] drv_module_vdc_Hstate_control fix Hstate=1!! Hstate=%d,err=%x,flag=%d \n", HState, Hdetect_err, unBalance_flag);
							drvif_module_vdc_Set_Hstate(VDC_NOT_FIX_HSTATE3);
						}
					}
				}
#endif
			}
#if VDC_Error_case4
			/*ATSC_110225_0925_196.50M_-38.86_20M_-35.42_NON_FieldSignal(ch11)*/
			if (drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_PALN) {
				if ((drvif_module_vdc_read_coch_detect_status() == 1) &&
					(drvif_video_status_reg(VDC_noisy_vbi) == 1)) {
					drvif_module_vdc_Set_Hstate(VDC_NOT_FIX_HSTATE3);
					module_vdc_set_gate_hv_iir(0x00);	// jj 20151120
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 4] hstate set to 3 !!\n");
				}
			}
#endif
#if VDC_Error_case6
			/* case 6: ATSC_081202_0925_337.00M_-37.18_20M_-32.77_LAN_FieldSignal(ch2)*/
			/* is mode change issue, for red noise. */
			if (module_vdc_read_burst_win_error_flag() == 1) {
				VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 6]mode=%x, ns=%x\n",
							  drvif_module_vdc_ReadMode(VDC_DETECT), vdc_NoiseStatus);
#if 0
				if (vdc_NoiseStatus > 0xf0) {
					module_vdc_set_Mode_443358pk_sel(VDC_and443358_flag);
				}
#else
				if (vdc_NoiseStatus > 0x70) {
					module_vdc_set_Mode_443358pk_sel(VDC_old443358);
				}
#endif
			}
#endif
		}
#if VDC_Error_case5
		/* sync reduction to 20% */
		ui_9008 = drvif_video_status_reg(VDC_STATUS_REG1);
		//VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5] 9008=%x\n", ui_9008);
		if ((ui_9008 == 0x0000730e) && (vdc_NoiseStatus <= 0x03)) {
			unsigned int usDgain = drvif_module_vdc_read_Dgain();
			VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5] dgain=%x\n", usDgain);
			if ((usDgain > 0x350) && (usDgain < 0x400)) {
				unsigned int usSeDgain = module_vdc_read_Second_Dgain();
				VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5] usSeDgain=%x\n", usSeDgain);
				if (usSeDgain > 0xbf0) {
					if (module_vdc_read_Hpll_fine_lock_data_sel() != HPLL_FINE_LOCK_REAL) {
						VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5] Set 9138[9]=1 ....!!!\n");
						module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_REAL);
					}
				} else if (usSeDgain < 0xad0) {
					if (module_vdc_read_Hpll_fine_lock_data_sel() != HPLL_FINE_LOCK_LPF) {
						VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5][0] reset 9138[9]=0\n");
						module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_LPF);
					}
				}
			} else {
				if (module_vdc_read_Hpll_fine_lock_data_sel() != HPLL_FINE_LOCK_LPF) {
					VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5][1] reset 9138[9]=0\n");
					module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_LPF);
				}
			}
		} else {
			if (module_vdc_read_Hpll_fine_lock_data_sel() != HPLL_FINE_LOCK_LPF) {
				VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 5][2] reset 9138[9]=0\n");
				module_vdc_set_Hpll_fine_lock_data_sel(HPLL_FINE_LOCK_LPF);
			}
		}
#endif
	} else if ((!vdc_LockStatus) & ucCheckStart) {
		vdc_ucLockCounter = 0x0;
		if (vdc_ucNoSignalCounter == 0) {
			ucNoiseTmp[0] = 0x00;
			ucNoiseTmp[1] = 0x00;
			ucNoiseTmp[2] = 0x00;
			ucNoiseTmp[3] = 0x00;
			ucNoiseTmp[4] = 0x00;
			ucNoiseTmp[5] = 0x00;
			ucNoiseTmp[6] = 0x00;
			ucNoiseTmp[7] = 0x00;
			VDC_DEBUG_MSG(VDC_MSG_TVCHCH, " no signal !\n");
			VDC_DEBUG_MSG(VDC_MSG_DGAIN, " no signal !\n");
#if 0//def CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL
			/*don't modified this func. If there has error of this funciton, please connect to jj. */
			/* All source */
			if (drvif_module_vdc_read_PeakWhite() == 1) {
				VDC_DEBUG_MSG(VDC_MSG_DGAIN, "disable pw. No signal !\n");
				drvif_module_vdc_set_PeakWhite(_DISABLE);
			}
#endif
		}

#ifdef CONFIG_ENABLE_VDC_PEAKWHITE_CONTROL
		/*don't modified this func. If there has error of this funciton, please connect to jj. */
		/* All source */
		if (vdc_ucNoSignalCounter == 5) {
			if (drvif_module_vdc_read_PeakWhite() == 1) {
				VDC_DEBUG_MSG(VDC_MSG_DGAIN, "disable pw. No signal !\n");
				drvif_module_vdc_set_PeakWhite(_DISABLE);
			}
		}
#endif
		vdc_ucNoSignalCounter ++;
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
		color_count = 0;
		normal_count = 0;
#endif
#ifdef CONFIG_VD_AUTO_BURST_POS_ENABLE
		drvif_module_vdc_Disable_Auto_Burst_position();
#endif
#if VDC_Error_case2
		if (vdc_ucNoSignalCounter == 0x200) {
			VDC_DEBUG_MSG(VDC_MSG_DEBUG2, "[ATV 2] release fine src sel 9138[7]=1\n");
			module_vdc_set_fine_src_sel(Fine_ORG);
		}
#endif
#ifdef VDC_SyncReduction_test
		if (ucInputSrc == _SRC_CVBS) {
			module_vdc_adcNegativeAdjustment(ucAdcNeg_Nosig);
		}
//			else if ((ucInputSrc == _SRC_TV)&&(drvif_module_vdc_read_Clamping_path() == 0))
//			{
//				module_vdc_adcNegativeAdjustment(ucAdcNeg_Nosig);
//			}
#endif
	}
	/* ========================================================================= */
	if ((ucInputSrc == _SRC_CVBS) & ucCheckStart) {
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
		drvif_module_vdc_serration_check();
#endif
	}

	if ((ucInputSrc == _SRC_TV) & ucCheckStart) {
#ifdef VD_hdto_adjust
		drvif_module_vdc_hpll_extend_detect();
#endif
	}
}

UINT8 dma_3d_ON_count = 0;
bool drvif_module_vdc_OutputStable(void)
{
	unsigned char ucVstate, uc3dready;
	vdpq_dma_ctrl4_RBUS vdpq_dma_ctrl4_reg;
	static unsigned char ucVstate2Cnt =0;
	unsigned char uc3dNoSupport = 0;
	if ((drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_SECAM)
		||(drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_NTSC50)
		||(drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_PAL60)) {
		uc3dNoSupport = 1;
	}
	if ((drvif_module_vpq_GetYcSep() == VDC_YCSEPARATE_3D) 	&& (uc3dNoSupport == 0)){
		ucVstate = drvif_module_vdc_Read_Vstate();
		if(ucVstate == 3)
			VDC_DEBUG_MSG(VDC_MSG_TVCHCH, "[3D check] VD ready !! Vstate=3\n")

		vdpq_dma_ctrl4_reg.regValue = vdcf_inl(VDPQ_DMA_CTRL4_reg);
		uc3dready = vdpq_dma_ctrl4_reg.dma_3d_on_off;
		if ((ucVstate == 3) && (uc3dready == 1))
		{
			if ((dma_3d_ON_count < 15)&&(drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_PALN))
			{
				dma_3d_ON_count++;
				return FALSE;
			}
			else
			return TRUE;
		}
		else
			return FALSE;
	} else {
		//rtd_printk(KERN_EMERG, "alanli", "Vstate!:%d\n",drvif_module_vdc_Read_Vstate());
		ucVstate=drvif_module_vdc_Read_Vstate();
		if(ucVstate == 3) {
			//rtd_printk(KERN_EMERG, "alanli", "VD ready !! Vstate=3!\n");
			ucVstate2Cnt =0;
			return TRUE;
		}
#if 1
		else if(ucVstate == 2)
		{
			ucVstate2Cnt++;
			if(ucVstate2Cnt>3)
			{
				rtd_printk(KERN_EMERG, "alanli", "Vstate=2!\n");
				ucVstate2Cnt =0;
				return TRUE;
			}
		}
#endif
		return FALSE;
	}
}


/**
   drvif_module_vdc_SelectInput
   Select signal source

 Depending on the VDC's different input source, set the corresponding setting.
 For different input source of VDC, we need to config the correct
 setting, for example the data path select for TV, AV or SV. Beside
 the VDC's setting, we also put the corresponding rtd2620 setting here
 just for convenience. Because for different input source, mabye we
 need to tune the suitable color setting.

   @param <src>        { Select signal to show }
   @return                  { void }

*/
void drvif_module_vdc_SelectInput(unsigned char ucInputSrc, VDC_INITIAL_OPTIONS  *ptOptions)
{
	module_vdc_PathSelect(ucInputSrc, ptOptions->path);

#if 1
	/*#ifdef CONFIG_TV_ENABLE */
	if (ucInputSrc == _SRC_TV) {
		drvif_module_vdc_tv_Reset();
		module_vdc_BlueScreenEnable(BLUE_SCREEN_DISABLE);
		drvif_module_vdc_set_noSignalCounter_Value(0x03);	/* speed up no-signal status */
		/*blue screen --> black */
		module_vdc_SetBlueScreenColor(0x00, 0x88, 0x88);
		module_vdc_Set_clamp_delay(_DISABLE, 0xb9);

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
		drvif_module_vdc_hsync_rising_start(0x2D);
		drvif_module_vdc_hsync_rising_end(0x50);
#endif
	} else
#endif
	{
		drvif_module_vdc_FIFO_CLK_setting();
		drvif_module_vdc_set_noSignalCounter_Value(0x01);	/* set to default */
		module_vdc_BlueScreenEnable(BLUE_SCREEN_AUTO);
		module_vdc_Set_clamp_delay(_DISABLE, 0xae);

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
		drvif_module_vdc_hsync_rising_start(0x28);
		drvif_module_vdc_hsync_rising_end(0x50);
#endif
	}
	//vdcf_outl(VDTOP_CHROMA_LOCK_CONFIG_reg, 0xbb);
}

/* ========================================================================= */
/* === VD state machine functions ================================================= */
void module_vdc_set_vstate_parameter(void)
{
	/* 93b0[27:20], 93b4[7:4][3:0], 93b8[7:0], 9374[27:12] */
	/* 93b0[3:0], 93b4[31:24][23], 9508[31] */
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vdtop_vstate_ctrl1_RBUS vstate_ctrl1_reg;
	vdtop_vstate_ctrl2_RBUS vstate_ctrl2_reg;
	vdtop_new_vdetect_ctrl_RBUS new_vdetect_ctrl_reg;
	vdtop_flag_625_counter_RBUS vdtop_flag_625_counter_reg;
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	vstate_ctrl1_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL1_reg);
	vstate_ctrl2_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL2_reg);
	new_vdetect_ctrl_reg.regValue = vdcf_inl(VDTOP_NEW_VDETECT_CTRL_reg);
	vdtop_flag_625_counter_reg.regValue = vdcf_inl(VDTOP_FLAG_625_COUNTER_reg);

#ifdef _vdc_adjust_v_parameter
//	vstate_ctrl0_reg.vstate_2to3_er = 0x01;		/* 93b0[3:0] = 0x5=>0x3=>0x1 */
//	vstate_ctrl0_reg.vstate0_counter_num = 0x0f;	/* 93b0[27:20] = 0x5=>0xf */
//	vstate_ctrl1_reg.vstate_2to3_th = 0x04;	/* 93b4[31:24] = 0x1f=>0x4 */
	vstate_ctrl1_reg.vstate_new2to3_en = 0x0;	/* 93b4[23] = 0 */
//	vstate_ctrl2_reg.vstate_counter_num = 0x05;	/* 93b8[7:0] = 0xa=>0x5 */
	vdtop_flag_625_counter_reg.vline_625_vloop_clr_en = 0x1;	/* 9508[31] = 0=>1 */
	vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	vdcf_outl(VDTOP_VSTATE_CTRL2_reg, vstate_ctrl2_reg.regValue);
	vdcf_outl(VDTOP_FLAG_625_COUNTER_reg, vdtop_flag_625_counter_reg.regValue);
#endif

//	vstate_ctrl1_reg.vstate_back1_er = 0x0e;		/* 93b4[3:0] = 0xe */
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	vstate_ctrl1_reg.vstate_1to2_er = 0x03;		/* 93b4[7:4] = 0x5=>0x3 */
#else
	vstate_ctrl1_reg.vstate_1to2_er = 0x05;		/* 93b4[7:4] = 0x5, default */
#endif
	vdcf_outl(VDTOP_VSTATE_CTRL1_reg, vstate_ctrl1_reg.regValue);

	new_vdetect_ctrl_reg.new_vdetect_max_limit_value = 0x003;	/*9374[27:12]=0x003 */
	vdcf_outl(VDTOP_NEW_VDETECT_CTRL_reg, new_vdetect_ctrl_reg.regValue);

	drvif_module_vdc_set_vstate_speedup(vstate_count_default);
}

void drvif_module_vdc_set_vstate_speedup(VDC_VSTATE_COUNT_REG value)
{
	/* 93b0[27:20], 93b8[7:0] */
	vdtop_vstate_ctrl0_RBUS vstate_ctrl0_reg;
	vdtop_vstate_ctrl2_RBUS vstate_ctrl2_reg;
	vstate_ctrl0_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL0_reg);
	vstate_ctrl2_reg.regValue = vdcf_inl(VDTOP_VSTATE_CTRL2_reg);

	if (value == vstate_count_default) {
		vstate_ctrl0_reg.vstate0_counter_num = 0x0f;		/* 93b0[27:20] */
//		vstate_ctrl2_reg.vstate_counter_num = 0x0f;		/* 93b8[7:0] */
		vstate_ctrl2_reg.vstate_counter_num = 0x05;		/* 93b8[7:0] */
	} else {
		/* vstate_count_fast */
#ifdef _vdc_adjust_v_parameter
		vstate_ctrl0_reg.vstate0_counter_num = 0x0f;		/* 93b0[27:20] */
		vstate_ctrl2_reg.vstate_counter_num = 0x05;		/* 93b8[7:0] */
#else
		vstate_ctrl0_reg.vstate0_counter_num = 0x0a;		/* 93b0[27:20] */
		vstate_ctrl2_reg.vstate_counter_num = 0x0a;		/* 93b8[7:0] */
#endif
	}
	vdcf_outl(VDTOP_VSTATE_CTRL0_reg, vstate_ctrl0_reg.regValue);
	vdcf_outl(VDTOP_VSTATE_CTRL2_reg, vstate_ctrl2_reg.regValue);
}

void module_vdc_set_cstate_parameter(void)
{
	/* 9410[3:1], 9418[7], 9418[6:4] */
	vdtop_ckill_lb_sel_RBUS ckill_lb_sel_reg;
	vdtop_chroma_loopfilter_state_RBUS chroma_loopfilter_state_reg;
	ckill_lb_sel_reg.regValue = vdcf_inl(VDTOP_CKILL_LB_SEL_reg);
	chroma_loopfilter_state_reg.regValue = vdcf_inl(VDTOP_CHROMA_LOOPFILTER_STATE_reg);
	ckill_lb_sel_reg.chromalock_cstate_en = 1;		/*9418[7]=1 */
	ckill_lb_sel_reg.chromalock_cstate = 0;		/*9418[6:4]=0 */
	chroma_loopfilter_state_reg.cstate = 5;		/*9410[3:1]=5 */
	vdcf_outl(VDTOP_CKILL_LB_SEL_reg, ckill_lb_sel_reg.regValue);
	vdcf_outl(VDTOP_CHROMA_LOOPFILTER_STATE_reg, chroma_loopfilter_state_reg.regValue);

	drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_DISABLE);
}

void drvif_module_vdc_mode_speedup(VDC_MODE_COUNT_REG value)
{
	/* 9040[7:0], 94a8[5:0] */
	vdtop_statistic_and_disable_mode_RBUS vdtop_statistic_and_disable_mode_reg;
	vdtop_statistic_and_disable_mode_reg.regValue = vdcf_inl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg);
	if (value == mode_count_default) {
		module_vdc_set_noise_thresh(0x32);
		vdtop_statistic_and_disable_mode_reg.statistic_number = 0x4;
	} else {	// mode_count_fast
		module_vdc_set_noise_thresh(0x00);
		vdtop_statistic_and_disable_mode_reg.statistic_number = 0x1;
	}
	vdcf_outl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg, vdtop_statistic_and_disable_mode_reg.regValue);
}

/* ========================================================================= */
/* === VD mode functions ======================================================= */
/**
   drvif_module_vdc_set_ColorMode
   color mode setting

   @param <void>       { mode = NTSC443 / PAL 60 need to set}
   @return                  { void }

*/
void drvif_module_vdc_set_ColorMode(unsigned char mode)
{
	if (mode == VDC_MODE_NTSC443) {
		drvif_video_set_control_reg(VDC_set_Colour_mode_NTSC443);
		drvif_module_vdc_set_Basic_Register(VDC_colourmodereg_enable);
	} else if (mode == VDC_MODE_PAL60) {
		drvif_video_set_control_reg(VDC_set_Colour_mode_PAL60);
		drvif_module_vdc_set_Basic_Register(VDC_colourmodereg_enable);
	} else {
		drvif_video_set_control_reg(VDC_set_Colour_mode_NTSC);
		drvif_module_vdc_set_Basic_Register(VDC_colourmodereg_disable);
	}
}

/*USER:LewisLee DATE:2012/09/13 */
/*to disable VDC unUsed mode */
/*to prevent VD / VGIP setting is diff, let picture abnormal */
void drvif_module_vdc_disable_mode(VDC_DISABLE_MODE result)
{
	/* 94a8[7][6] */
	vdtop_statistic_and_disable_mode_RBUS STATISTIC_AND_DISABLE_MODE_reg;

	switch (result) {
	case _VDC_DISABLE_MODE_525:
		STATISTIC_AND_DISABLE_MODE_reg.regValue = vdcf_inl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg);
		if ((_DISABLE == STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en)
			|| (_VDC_DISABLE_625_INPUT == STATISTIC_AND_DISABLE_MODE_reg.disable_mode)) {
			STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en = _ENABLE;
			STATISTIC_AND_DISABLE_MODE_reg.disable_mode = _VDC_DISABLE_525_INPUT;
			vdcf_outl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg, STATISTIC_AND_DISABLE_MODE_reg.regValue);
		}
		break;

	case _VDC_DISABLE_MODE_625:
		STATISTIC_AND_DISABLE_MODE_reg.regValue = vdcf_inl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg);
		if ((_DISABLE == STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en)
			|| (_VDC_DISABLE_525_INPUT == STATISTIC_AND_DISABLE_MODE_reg.disable_mode)) {
			STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en = _ENABLE;
			STATISTIC_AND_DISABLE_MODE_reg.disable_mode = _VDC_DISABLE_625_INPUT;
			vdcf_outl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg, STATISTIC_AND_DISABLE_MODE_reg.regValue);
		}
		break;

	default:
	case _VDC_DISABLE_MODE_DIDABLE:
		STATISTIC_AND_DISABLE_MODE_reg.regValue = vdcf_inl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg);
		if (_ENABLE == STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en) {
			STATISTIC_AND_DISABLE_MODE_reg.disable_mode_en = _DISABLE;
			vdcf_outl(VDTOP_STATISTIC_AND_DISABLE_MODE_reg, STATISTIC_AND_DISABLE_MODE_reg.regValue);
		}
		break;
	}
}

/* *****************************************************************************
*
* FUNCTION       :  void drvif_module_vdc_SetMode(unsigned char ucMode)
*
* USAGE          	:  Set Video Mode
*
* INPUT         	 	:  	< ucMode > :
*                                { 0 : ntsc
*                                   1 : palm
*                                   2 : ntsc50
*                                   3 : paln
*                                   4 : ntsc443
*                                   5 : pal60
*                                   6 : pali
*                                   7 : secam
*                                   8 : auto mode }
*
* OUTPUT         	:	{ none }
*
* GLOBALS        	:
*
* USED_REGS      :
*
* ****************************************************************************** */
void drvif_module_vdc_SetMode(unsigned char ucMode)
{
//	unsigned char mode;
	vdtop_manual_mode_RBUS manual_mode_reg;
	vdtop_state_machine_fix_mode_RBUS state_machine_fix_mode_reg;

	if (drvif_module_vdc_CheckFactoryModEnable(ON))
		return;

	manual_mode_reg.regValue = vdcf_inl(VDTOP_MANUAL_MODE_reg);
	state_machine_fix_mode_reg.regValue = vdcf_inl(VDTOP_STATE_MACHINE_FIX_MODE_reg);

	ucMode = ucMode & 0x0f;
	if (ucMode == VDC_MODE_AUTO) {
		/* ============================
		* 	No Signal
		============================= */
		manual_mode_reg.auto_mode_en = 1;
		manual_mode_reg.manual_mode_select = 0x00;
	} else {
		manual_mode_reg.auto_mode_en = 0;
		manual_mode_reg.manual_mode_select = ucMode;
	}
	/* clear mode flag */
	state_machine_fix_mode_reg.fix_secam_h = 0;
	state_machine_fix_mode_reg.fix_secam_h = 0;
	state_machine_fix_mode_reg.fix_palor_h = 0;
	state_machine_fix_mode_reg.fix_443_h = 0;
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	/*set it later */
#else
	state_machine_fix_mode_reg.fix_625_h = 0;
#endif

	/* 20121015, for shanghai tvbox issue */
	if ((ucMode == VDC_MODE_AUTO) && (vdc_autoMode_without_secam == true))
		state_machine_fix_mode_reg.fix_secamflag_en = 1;
	else
		state_machine_fix_mode_reg.fix_secamflag_en = 0;
	state_machine_fix_mode_reg.fix_palorflag_en = 0;
	state_machine_fix_mode_reg.fix_443flag_en = 0;
#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	/*set it later */
#else
	state_machine_fix_mode_reg.fix_625flag_en = 0;
#endif

	vdcf_outl(VDTOP_MANUAL_MODE_reg, manual_mode_reg.regValue);
	vdcf_outl(VDTOP_STATE_MACHINE_FIX_MODE_reg, state_machine_fix_mode_reg.regValue);
	drvif_module_vdc_PreferModeSetting(ucMode);
//	drvif_module_vdc_set_burst_gate_position(ucMode);//merage from mac5p
	module_vdc_Clear_SECAM_Setting();

	switch (ucMode) {
	default:
	case VDC_MODE_AUTO:
		drvif_module_vdc_set_ColorMode(VDC_MODE_AUTO);
#if 0
		Rt_Delay(100);
		mode = drvif_module_vdc_ReadMode(VDC_DETECT);
		if ((mode == VDC_MODE_NTSC) || (mode == VDC_MODE_PALM)
			|| (mode == VDC_MODE_NTSC443) || (mode == VDC_MODE_PAL60))
			FieldVTotal = 263;
		else

			FieldVTotal = 313;
		if (mode == VDC_MODE_NTSC443)
			drvif_module_vdc_set_ColorMode(VDC_MODE_NTSC443);
		else if (mode == VDC_MODE_PAL60)
			drvif_module_vdc_set_ColorMode(VDC_MODE_PAL60);

//		VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"set AUTO");
#else
		if (vdc_625flag)
			FieldVTotal = 313;
		else
			FieldVTotal = 263;
#endif
		break;
	case VDC_MODE_NTSC:
	case VDC_MODE_PALM:
		drvif_module_vdc_set_ColorMode(VDC_MODE_NTSC);
		FieldVTotal = 263;
//		VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"set NTSC / PALM : %x", ucMode);
		break;
	case VDC_MODE_SECAM:
		drvif_module_vdc_set_ColorMode(VDC_MODE_PALI);
		FieldVTotal = 313;
		module_vdc_Set_SECAM_Setting();
		break;
	case VDC_MODE_PALI:
	case VDC_MODE_NTSC50:
	case VDC_MODE_PALN:
		drvif_module_vdc_set_ColorMode(VDC_MODE_PALI);
		FieldVTotal = 313;
//		VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"set PALI / PALN / SECAM / NTSC50 : %x", ucMode);
		break;
	case VDC_MODE_NTSC443:
		drvif_module_vdc_set_ColorMode(VDC_MODE_NTSC443);
		FieldVTotal = 263;
//		VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"set NTSC443");
		break;
	case VDC_MODE_PAL60:
		drvif_module_vdc_set_ColorMode(VDC_MODE_PAL60);
		FieldVTotal = 263;
//		VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"set PAL60");
		break;
	}
}

/**
   drvif_module_vdc_ReadMode

   Read VD setting mode or auto mode detection result

   @param                 { result
						VDC_SET / VDC_DETECT }
   @return   Mode       {  0 : ntsc
					1 : palm
					2 : ntsc50
					3 : paln
					4 : ntsc443
					5 : pal60
					6 : pali
					7 : secam }
*/
unsigned char drvif_module_vdc_ReadMode(GET_VIDEO_MODE_METHOD result)
{
	/* 94a4 */
	unsigned char mode;
	vdtop_mode_detection_status_RBUS mode_detection_status_reg;
	mode_detection_status_reg.regValue = vdcf_inl(VDTOP_MODE_DETECTION_STATUS_reg);

	if (result == VDC_SET) {
		mode = mode_detection_status_reg.set_mode_status;
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "vd set mode: %x", mode);
		return mode;
	} else {	/* VDC_DETECT */
		mode = mode_detection_status_reg.decision_mode_status;
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "vd detect mode: %x", mode);
		return mode;
	}
}

#ifdef CONFIG_ENABLE_VDC_MV_CHECK
void drvif_module_vdc_set_mv_function(void)
{
	drvif_module_vdc_Write_Dgain_value(0xa5);	/* 90a0[7:0] set x0.75 */
	drvif_module_vdc_set_Basic_Register(VDC_hagcreg_enable);
	drvif_module_vdc_new_vdetect_Enable(Old_vedetect);
}
#endif
unsigned char vdc_mode_detect;

/**
 Check the video mode type.
 This function will query the video decoder's mode type register.
 Differ which type it is now.
   @param <ucInputSrc>  { Input source }
   @return <ucVdc_Curr_Mode> { The result it detected }

	BIT 0~1
		: 1 60 Hz
		: 2 50 Hz
	BIT 4~7
		: 00 PAL B,G,H,I
		: 10 NTSC M
		: 20 SECAM
		: 30 NTSC 443
		: 40 PAL M
		: 50 PAL N
		: 60 PAL 60
*/
unsigned char drvif_module_vdc_IdentifyColorStandard(unsigned char ucInputSrc)
{
	unsigned char VD_mode = VDC_MODE_NTSC;
	unsigned char VD_mode_try = VDC_MODE_NTSC;
	unsigned char check_mode_count = 3;
	unsigned char check_mode_threshold = 1;
	unsigned char Flag_NoSignal = 0;
	unsigned char Flag_NoBurstDetect = 0;
	unsigned char Flag_NTSC = 0;
	unsigned char Flag_PAL_M = 0;
	unsigned char Flag_NTSC_443 = 0;
	unsigned char Flag_PAL_60 = 0;
	unsigned char Flag_PAL_I = 0;
	unsigned char Flag_PAL_N = 0;
	unsigned char Flag_SECAM = 0;
	unsigned char Flag_NTSC_50 = 0;
	unsigned char i = 0;
	unsigned char k = 0, count = 2;

	for (k = 0 ; k < count ; ++k) { /*check 2 times for PAL I */
		Flag_NTSC = Flag_PAL_M = Flag_NTSC_443 = Flag_PAL_60 = Flag_PAL_I = Flag_PAL_N = Flag_SECAM = Flag_NTSC_50 = 0;
		for (i = 0; i < check_mode_count; i++) {
			if (0 == vdc_LockStatus) {
				return _MODE_NOSIGNAL;
			}

			Rt_Delay(10);
			set_freezable();
			if (drvif_video_status_reg(VDC_no_signal)) {
				VD_mode = VDC_MODE_NO_SIGNAL;
			} else {
				if ((_SRC_TV != ucInputSrc) || (TRUE == tvAutoScanFlag)) {
					VD_mode_try = drvif_module_vdc_ReadMode(VDC_DETECT);
				} else {
					VD_mode_try = drvif_module_vdc_ReadMode(VDC_SET);
				}
			}

			set_freezable();
#if 0//def _jj_change_lock_function
			if (!vdc_BurstLockStatus)
#else
			if (!drvif_video_status_reg(VDC_Burst_detect))
#endif
				Flag_NoBurstDetect++;

			switch (VD_mode_try) {
			default:
			case VDC_MODE_NO_SIGNAL:
				Flag_NoSignal++;
				break;
			case VDC_MODE_NTSC:
				Flag_NTSC++;
				break;
			case VDC_MODE_PALM:
				Flag_PAL_M++;
				break;
			case VDC_MODE_NTSC443:
				Flag_NTSC_443++;
				break;
			case VDC_MODE_PAL60:
				Flag_PAL_60++;
				break;
			case VDC_MODE_PALI:
				Flag_PAL_I++;
				break;
			case VDC_MODE_PALN:
				Flag_PAL_N++;
				break;
			case VDC_MODE_SECAM:
				Flag_SECAM++;
				break;
			case VDC_MODE_NTSC50:
				Flag_NTSC_50++;
				break;
			}
		}

		if ((Flag_NTSC == check_mode_count) || (Flag_PAL_M == check_mode_count) || (Flag_NTSC_443 == check_mode_count) || (Flag_PAL_60 == check_mode_count) ||
			(Flag_PAL_I == check_mode_count) || (Flag_PAL_N == check_mode_count) || (Flag_SECAM == check_mode_count) || (Flag_NTSC_50 == check_mode_count))
			break;
	}
#if 0
	if (0 == vdc_LockStatus) {
		return _MODE_NOSIGNAL;
	}
#endif
	if (((Flag_NoSignal << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_NO_SIGNAL;
	else if (((Flag_NTSC << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_NTSC;
	else if (((Flag_PAL_M << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_PALM;
	else if (((Flag_NTSC_443 << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_NTSC443;
	else if (((Flag_PAL_60 << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_PAL60;
	else if (((Flag_PAL_I << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_PALI;
	else if (((Flag_PAL_N << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_PALN;
	else if (((Flag_SECAM << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_SECAM;
	else if (((Flag_NTSC_50 << 1) - check_mode_count) >= check_mode_threshold)
		VD_mode = VDC_MODE_NTSC50;
	else
		return  ucVdc_Curr_Mode;

	/*frank@0617 mark below code to speed up */
	/*if(drvif_video_status_reg(VDC_no_signal)) */
	/*	VD_mode = VDC_MODE_NO_SIGNAL;	*/

	switch (VD_mode) {
	case VDC_MODE_NO_SIGNAL:
		ucVdc_Curr_Mode = _MODE_NOSIGNAL;
		/*leo 20101102 set no signal to PAL */
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
		module_vdc_set_Vactive_position(0x27, 0xc1);
#endif
		field = VDC_FRAME_RATE_50HZ;
		break;
	case VDC_MODE_NTSC:
		ucVdc_Curr_Mode = ZNTSC;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x22, 0x61);
#endif
		field = VDC_FRAME_RATE_60HZ;
		break;
	case VDC_MODE_PALM:
		ucVdc_Curr_Mode = ZPAL_M;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x22, 0x61);
#endif
		field = VDC_FRAME_RATE_60HZ;
		break;
	case VDC_MODE_NTSC443:
		ucVdc_Curr_Mode = ZNTSC_443;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x22, 0x61);
#endif
		field = VDC_FRAME_RATE_60HZ;
		break;
	case VDC_MODE_PAL60:
		ucVdc_Curr_Mode = ZPAL_60;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x22, 0x61);
#endif
		field = VDC_FRAME_RATE_60HZ;
		break;
	case VDC_MODE_PALI:
		ucVdc_Curr_Mode = ZPAL_I;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
		module_vdc_set_Vactive_position(0x27, 0xc1);
#endif
		field = VDC_FRAME_RATE_50HZ;
		break;
	case VDC_MODE_PALN:
		ucVdc_Curr_Mode = ZPAL_N;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
		module_vdc_set_Vactive_position(0x27, 0xc1);
#endif
		field = VDC_FRAME_RATE_50HZ;
		break;
	case VDC_MODE_SECAM:
		ucVdc_Curr_Mode = ZSECAM;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x2a, 0xc1);
#endif
		field = VDC_FRAME_RATE_50HZ;
		break;
	case VDC_MODE_NTSC50:
		ucVdc_Curr_Mode = ZNTSC_50;
#ifdef _VDC_Vactive_set
		drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
		module_vdc_set_Vactive_position(0x2a, 0xc1);
#endif
		field = VDC_FRAME_RATE_50HZ;
		break;
	}

	if (Flag_NoBurstDetect != 0) {	/*jj 20120510 for no burst detect change output mode */
		if (VD_mode == VDC_MODE_NTSC443)
			ucVdc_Curr_Mode = ZNTSC;
		if (VD_mode == VDC_MODE_NTSC50)
			ucVdc_Curr_Mode = ZPAL_I;
	}
	vdc_mode_detect = VD_mode;

	drvif_module_vdc_PreferModeSetting(VD_mode);
//	drvif_module_vdc_set_burst_gate_position(VD_mode);//merage from mac5p
	return  ucVdc_Curr_Mode;
}

#if 1
unsigned char g_ucICSStage = ICS_STAGE_INIT;
unsigned char g_ucICSCount = 0x0;
unsigned char g_ucICSCheckMode = 0x0;
unsigned char g_ucICECheckVDCNoSignalCount = 0x0;
unsigned char g_ucICEVDCNoSignalStatus = 0x0;
unsigned char g_ucICECheckVDCBURSTCount = 0x0;
unsigned char g_ucICEVDCBURSTStatus = 0x0;

#if 0
static unsigned char VD_mode = VDC_MODE_NTSC;
static unsigned char VD_mode_try = VDC_MODE_NTSC;
static unsigned char check_mode_count = 3;
static unsigned char check_mode_threshold = 1;
static unsigned char Flag_NoSignal = 0x0;
static unsigned char Flag_NoBurstDetect = 0x0;
static unsigned char Flag_NTSC = 0x0;
static unsigned char Flag_PAL_M = 0x0;
static unsigned char Flag_NTSC_443 = 0x0;
static unsigned char Flag_PAL_60 = 0x0;
static unsigned char Flag_PAL_I = 0x0;
static unsigned char Flag_PAL_N = 0x0;
static unsigned char Flag_SECAM = 0x0;
static unsigned char Flag_NTSC_50 = 0x0;
static unsigned char secam_flag, flag625;
#endif

void drvif_module_vdc_IdentifyColorStandard_ResetStage(void)
{
	g_ucICSStage = ICS_STAGE_INIT;
	g_ucICSCount = 0x0;
	g_ucICSCheckMode = 0;
	g_ucICECheckVDCNoSignalCount = 0;
	g_ucICEVDCNoSignalStatus = 0;
	g_ucICECheckVDCBURSTCount = 0;
	g_ucICEVDCBURSTStatus = 0;
}

unsigned char drvif_module_vdc_IdentifyColorStandard_GetStage(void)
{
	return g_ucICSStage;
}


unsigned char drvif_module_vdc_IdentifyColorStandard_NoDelay(unsigned char ucInputSrc)
{
#if 1
	static unsigned char VD_mode = VDC_MODE_NTSC;
	static unsigned char VD_mode_try = VDC_MODE_NTSC;
	static unsigned char check_mode_count = 3;
	static unsigned char check_mode_threshold = 1;
	static unsigned char Flag_NoSignal = 0x0;
	static unsigned char Flag_NoBurstDetect = 0x0;
	static unsigned char Flag_NTSC = 0x0;
	static unsigned char Flag_PAL_M = 0x0;
	static unsigned char Flag_NTSC_443 = 0x0;
	static unsigned char Flag_PAL_60 = 0x0;
	static unsigned char Flag_PAL_I = 0x0;
	static unsigned char Flag_PAL_N = 0x0;
	static unsigned char Flag_SECAM = 0x0;
	static unsigned char Flag_NTSC_50 = 0x0;
	static unsigned char count = 2;
#endif

	switch (g_ucICSStage)
	{
	case ICS_STAGE_INIT:
		if (g_ucICSCount < count)
		{
			Flag_NTSC = Flag_PAL_M = Flag_NTSC_443 = Flag_PAL_60 = Flag_PAL_I = Flag_PAL_N = Flag_SECAM = Flag_NTSC_50 = 0;
			g_ucICSStage = ICS_STAGE_CHECK_VDC_NO_SIGNAL;
			g_ucICSCheckMode = 0;
		} else
		{
			g_ucICSStage = ICS_STAGE_FIANL;
		}

		break;

	case ICS_STAGE_CHECK_VDC_NO_SIGNAL:
		if (0 == g_ucICECheckVDCNoSignalCount)
		{
#if 0
			g_ucICEVDCNoSignalStatus = drvif_video_status_reg_NoDelay(VDC_no_signal);
#else
			g_ucICEVDCNoSignalStatus = !vdc_LockStatus;
#endif
		} else if (1 == g_ucICECheckVDCNoSignalCount) {
#if 0
			g_ucICEVDCNoSignalStatus &= drvif_video_status_reg_NoDelay(VDC_no_signal);
#else
			g_ucICEVDCNoSignalStatus &= !vdc_LockStatus;
#endif
			if (g_ucICEVDCNoSignalStatus) {
				VD_mode = VDC_MODE_NO_SIGNAL;
			} else {
				if ((_SRC_TV != ucInputSrc) || (TRUE == tvAutoScanFlag)) {
					VD_mode_try = drvif_module_vdc_ReadMode(VDC_DETECT);
//					VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"[VDC] mode detect:%x", VD_mode_try);
				} else {
					VD_mode_try = drvif_module_vdc_ReadMode(VDC_SET);
//					VDC_DEBUG_MSG(VDC_MSG_DEBUG1,"[VDC] mode set:%x", VD_mode_try);
				}
			}

			g_ucICSStage = ICS_STAGE_CHECK_VDC_BURST_DETECT;
			g_ucICECheckVDCNoSignalCount = 0;
		}
		g_ucICECheckVDCNoSignalCount++;

		break;

	case ICS_STAGE_CHECK_VDC_BURST_DETECT:

		if (0 == g_ucICECheckVDCBURSTCount) {
#if 0
			g_ucICEVDCBURSTStatus = drvif_video_status_reg_NoDelay(VDC_Burst_detect);
#else
			g_ucICEVDCBURSTStatus = vdc_BurstLockStatus;
#endif
		} else if (1 == g_ucICECheckVDCBURSTCount) {
#if 0
			g_ucICEVDCBURSTStatus &= drvif_video_status_reg_NoDelay(VDC_Burst_detect);
#else
			g_ucICEVDCBURSTStatus &= vdc_BurstLockStatus;
#endif

			if (!g_ucICEVDCBURSTStatus)	/* for no burst detect change output mode */
				Flag_NoBurstDetect ++;

			g_ucICSStage = ICS_STAGE_CHECK_MODE;

			g_ucICECheckVDCBURSTCount = 0;

		}

		g_ucICECheckVDCBURSTCount++;

		break;


	case ICS_STAGE_CHECK_MODE:

		if (g_ucICSCheckMode < check_mode_count) {

			switch (VD_mode_try) {
			default:
			case VDC_MODE_NO_SIGNAL:
				Flag_NoSignal++;
				break;
			case VDC_MODE_NTSC:
				Flag_NTSC++;
				break;
			case VDC_MODE_PALM:
				Flag_PAL_M++;
				break;
			case VDC_MODE_NTSC443:
				Flag_NTSC_443++;
				break;
			case VDC_MODE_PAL60:
				Flag_PAL_60++;
				break;
			case VDC_MODE_PALI:
				Flag_PAL_I++;
				break;
			case VDC_MODE_PALN:
				Flag_PAL_N++;
				break;
			case VDC_MODE_SECAM:
				Flag_SECAM++;
				break;
			case VDC_MODE_NTSC50:
				Flag_NTSC_50++;
				break;
			}

		} else {
			g_ucICSStage = ICS_STAGE_COUNT;
		}

		g_ucICSCheckMode++;

		break;

	case ICS_STAGE_COUNT:

		if (g_ucICSCount < count) {
			if ((Flag_NTSC == check_mode_count) || (Flag_PAL_M == check_mode_count) || (Flag_NTSC_443 == check_mode_count) || (Flag_PAL_60 == check_mode_count) ||
				(Flag_PAL_I == check_mode_count) || (Flag_PAL_N == check_mode_count) || (Flag_SECAM == check_mode_count) || (Flag_NTSC_50 == check_mode_count)) {
				g_ucICSStage = ICS_STAGE_FIANL;
			} else {
				g_ucICSStage = ICS_STAGE_INIT;
			}
		} else {
			g_ucICSStage = ICS_STAGE_FIANL;
		}

		g_ucICSCount++;

		break;

	case ICS_STAGE_FIANL:
		if (((Flag_NoSignal << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_NO_SIGNAL;
		else if (((Flag_NTSC << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_NTSC;
		else if (((Flag_PAL_M << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_PALM;
		else if (((Flag_NTSC_443 << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_NTSC443;
		else if (((Flag_PAL_60 << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_PAL60;
		else if (((Flag_PAL_I << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_PALI;
		else if (((Flag_PAL_N << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_PALN;
		else if (((Flag_SECAM << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_SECAM;
		else if (((Flag_NTSC_50 << 1) - check_mode_count) >= check_mode_threshold)
			VD_mode = VDC_MODE_NTSC50;
		else
			return  ucVdc_Curr_Mode;

		/*frank@0617 mark below code to speed up */
		/*if(drvif_video_status_reg(VDC_no_signal)) */
		/*	VD_mode = VDC_MODE_NO_SIGNAL;    */

		switch (VD_mode) {
		case VDC_MODE_NO_SIGNAL:
			ucVdc_Curr_Mode = _MODE_NOSIGNAL;
			/*leo 20101102 set no signal to PAL */
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
			module_vdc_set_Vactive_position(0x27, 0xc1);
			field = VDC_FRAME_RATE_50HZ;
			break;
		case VDC_MODE_NTSC:
			ucVdc_Curr_Mode = ZNTSC;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x22, 0x61);
			field = VDC_FRAME_RATE_60HZ;
			break;
		case VDC_MODE_PALM:
			ucVdc_Curr_Mode = ZPAL_M;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x22, 0x61);
			field = VDC_FRAME_RATE_60HZ;
			break;
		case VDC_MODE_NTSC443:
			ucVdc_Curr_Mode = ZNTSC_443;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x22, 0x61);
			field = VDC_FRAME_RATE_60HZ;
			break;
		case VDC_MODE_PAL60:
			ucVdc_Curr_Mode = ZPAL_60;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x22, 0x61);
			field = VDC_FRAME_RATE_60HZ;
			break;
		case VDC_MODE_PALI:
			ucVdc_Curr_Mode = ZPAL_I;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
			module_vdc_set_Vactive_position(0x27, 0xc1);
			field = VDC_FRAME_RATE_50HZ;
			break;
		case VDC_MODE_PALN:
			ucVdc_Curr_Mode = ZPAL_N;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_enable);
			module_vdc_set_Vactive_position(0x27, 0xc1);
			field = VDC_FRAME_RATE_50HZ;
			break;
		case VDC_MODE_SECAM:
			ucVdc_Curr_Mode = ZSECAM;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x2a, 0xc1);
			field = VDC_FRAME_RATE_50HZ;
			break;
		case VDC_MODE_NTSC50:
			ucVdc_Curr_Mode = ZNTSC_50;
			drvif_module_vdc_set_Basic_Register(VDC_vsyncreg_disable);
			module_vdc_set_Vactive_position(0x2a, 0xc1);
			field = VDC_FRAME_RATE_50HZ;
			break;
		}

		if (Flag_NoBurstDetect != 0) {	/*jj 20120510 for no burst detect change output mode */
			if (VD_mode == VDC_MODE_NTSC443)
				ucVdc_Curr_Mode = ZNTSC;
			if (VD_mode == VDC_MODE_NTSC50)
				ucVdc_Curr_Mode = ZPAL_I;
		}

		drvif_module_vdc_PreferModeSetting(VD_mode);
//		drvif_module_vdc_set_burst_gate_position(VD_mode);//merage from mac5p

		g_ucICSStage = ICS_STAGE_READY;
		return  ucVdc_Curr_Mode;
		break;
	}
	return  ucVdc_Curr_Mode;
}
#endif

void module_vdc_set_secam_443358_flag_parameter(void)
{
	/* 9578, 957c */
	vdtop_sep_burst_flag1_RBUS sep_burst_flag1_reg;

	module_vdc_set_Mode_secam2_sel(VDC_orSecam_flag);	/* for Fluke 5418  cross hatch pattern */
	module_vdc_set_Mode_443358pk_sel(VDC_new443358_flag);

	sep_burst_flag1_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_FLAG1_reg);
	sep_burst_flag1_reg.sep_secam_f_sel = 1;		/* 9578 = 0x01800900 */
	sep_burst_flag1_reg.sep_secam_thl = 0x80;
	vdcf_outl(VDTOP_SEP_BURST_FLAG1_reg, sep_burst_flag1_reg.regValue);
}

/* ========================================================================= */
/**
   drvif_module_vdc_FreeRun
   enable/disable free run mode

   @param <on_off>   { _ENABLE/_DISABLE }
   @return                  { void }
*/
void drvif_module_vdc_FreeRun(VDC_FREERUN_LINE result)
{
//	unsigned char ucFreeRunStatus = drvif_module_vdc_read_hv_freerun_sel();
	/*Set Freerun_sel flag and mode is PAL */
	/*check freerun line: 0xb8021200[2:0]=3, read b8021230=line*/

	if (result == VDC_FREERUN_DISABLE) {
		if (drvif_module_vdc_read_hv_freerun_sel() != _DISABLE) {
			if (FALSE == g_ucFixCKillMode) {
				drvif_module_vdc_Set_CKill_Mode(CKill_AUTO);
			}
			drvif_module_vdc_disable_mode(_VDC_DISABLE_MODE_DIDABLE);
			drvif_video_set_control_reg(VDC_set_Vline_525);
			module_vdc_hv_freerun_sel(_DISABLE);
			module_vdc_adcNegativeAdjustment(ucAdcNeg_Sing);//add for WOSQRTK-8849
		}
	} else {
		if (drvif_module_vdc_read_hv_freerun_sel() != _ENABLE) {
			drvif_module_vdc_Set_CKill_Mode(CKill_ON);
			if (result == VDC_FREERUN_625) {
				drvif_module_vdc_disable_mode(_VDC_DISABLE_MODE_525);
				drvif_video_set_control_reg(VDC_set_Vline_625);
			} else {
				drvif_module_vdc_disable_mode(_VDC_DISABLE_MODE_625);
				drvif_video_set_control_reg(VDC_set_Vline_525);
			}
			module_vdc_hv_freerun_sel(_ENABLE);
			module_vdc_adcNegativeAdjustment(0xe);//add for WOSQRTK-8849

			if (!drvif_module_vdc_read_scan_flag())
				drvif_module_vdc_SoftReset();
		}
	}
}

/* =========================================================================
*
* 1. move clamp on front porch  & falling sync edge
* 2. enable clamp compensate to eliminate clamp pulse & effect black level measure & sync
*
========================================================================= */
void module_vdc_set_Clamp_position(unsigned char ucMode)
{
	switch (ucMode) {
	case VDC_MODE_NTSC:
	case VDC_MODE_PALM:
	case VDC_MODE_PAL60:
		module_vdc_Set_clamp_delay(_ENABLE, 0xb3);
		module_vdc_Set_cpump_adjust_delay(0x2A);
		module_vdc_Set_cpump_adjustment(0x30);
		break;
	case VDC_MODE_NTSC443:
		module_vdc_Set_clamp_delay(_ENABLE, 0xb4);
		module_vdc_Set_cpump_adjust_delay(0x1E);
		module_vdc_Set_cpump_adjustment(0x28);
		break;
	case VDC_MODE_PALN:
	case VDC_MODE_PALI:
		module_vdc_Set_clamp_delay(_ENABLE, 0xb4);
		module_vdc_Set_cpump_adjust_delay(0x2A);
		module_vdc_Set_cpump_adjustment(0x28);
		break;
	case VDC_MODE_NTSC50:
	case VDC_MODE_SECAM:
		module_vdc_Set_clamp_delay(_ENABLE, 0xb6);
		module_vdc_Set_cpump_adjust_delay(0x1e);
		module_vdc_Set_cpump_adjustment(0x2e);
		break;
	case  VDC_MODE_NO_SIGNAL:
		module_vdc_Set_clamp_delay(_DISABLE, 0xAE);
		break;
	}
}

void module_vdc_set_Burst_position(unsigned char ucMode)
{
	vdtop_separate_443_358_new_function_1_RBUS separate_443_358_new_function_1_reg;
	vdtop_separate_443_358_new_function_2_RBUS separate_443_358_new_function_2_reg;
	vdtop_separate_443_358_new_function_3_RBUS separate_443_358_new_function_3_reg;
#ifdef VD_AUTO_BURST_POS_AUTOMODE
	unsigned char ucNoiseTh = 0x03;
	unsigned short usLocation_result, usLocation_set;
	separate_443_358_new_function_2_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_2_reg);
	usLocation_result = separate_443_358_new_function_2_reg.burst_location_result;
	usLocation_set = separate_443_358_new_function_2_reg.normal_burst_location;
	if (usLocation_result < usLocation_set) {
		if (drvif_module_vdc_read_Clamping_path()) {
			switch (ucMode) {
			default:
				break;
			case VDC_MODE_NTSC:
				ucNoiseTh = 0x16;
				break;
			case VDC_MODE_PALI:
				ucNoiseTh = 0x10;
				break;
			}
		} else {
			switch (ucMode) {
			default:
				break;
			case VDC_MODE_NTSC:
				ucNoiseTh = 0x0f;
				break;
			case VDC_MODE_PALI:
				ucNoiseTh = 0x08;
				break;
			}
		}
	}
#endif

#ifdef VD_BURST_LOCATION_AUTO
	/* fix me  */
	if (VDC_MODE_PALI == ucMode) {
#if 0
		if ((usLocation_result > 0xb0)
			&& (drvif_video_status_reg(VDC_hv_lock))
			&& (drvif_module_vdc_burst_mag_status() < 0x10))
#else
		if ((usLocation_result > 0xb0)
			&& vdc_LockStatus
			&& (drvif_module_vdc_burst_mag_status() < 0x10))
#endif
		{
			drvif_module_vdc_Enable_Auto_Burst_position();
			drvif_module_vdc_disable_burst_location_auto();

		}
	}
#endif

	if ((tvAutoScanFlag == TRUE)
#ifdef VD_AUTO_BURST_POS_AUTOMODE
		|| (drvif_module_vdc_ReadAutomode() && (vdc_NoiseStatus > ucNoiseTh))	/* is auto mode enable */
#else
		|| (!drvif_module_vdc_ReadAutomode())
#endif
		|| (drvif_video_control_reg(VDC_cv_src))
		|| (drvif_video_control_reg(VDC_yc_src))
#ifdef _jj_change_lock_function
		|| (!vdc_ChromaLockStatus)
		|| (!vdc_BurstLockStatus)
#else
		|| (!drvif_video_status_reg(VDC_chomalock))
		|| (!drvif_video_status_reg(VDC_Burst_detect))
#endif
		|| (drvif_module_vdc_burst_mag_status() < 0x10)) {
		drvif_module_vdc_Disable_Auto_Burst_position();
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "Auto bp return!!NoiseStatus=%x ", vdc_NoiseStatus);
		return;
	} else if (drvif_module_vdc_burst_mag_status() > 0x12) {
		separate_443_358_new_function_1_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg);
		separate_443_358_new_function_2_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_2_reg);
		separate_443_358_new_function_3_reg.regValue = vdcf_inl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_3_reg);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "Auto bp ucMode=%x!! ", ucMode);

		switch (ucMode) {
		default:	/* auto postion disable */
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x0;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x0;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x0;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x0;
			break;
		case VDC_MODE_NTSC:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x0;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x092;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0bd;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x04a;
			break;
		case VDC_MODE_PALI:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x1;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x097;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0d7;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x05c;
			break;
#ifdef VD_AUTO_BURST_POS_MODE2
		case VDC_MODE_PALM:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x0;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x09f;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0de;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x060;
			break;
		case VDC_MODE_PALN:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x0;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x09d;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0dd;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x05e;
			break;
		case VDC_MODE_NTSC443:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x1;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x08e;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0cc;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x050;
			break;
		case VDC_MODE_PAL60:
			separate_443_358_new_function_1_reg.burst_location_sel = 0x1;
			separate_443_358_new_function_1_reg.auto_burst_location_en = 0x1;
			separate_443_358_new_function_1_reg.normal_burst_locationreg_en = 0x1;
			separate_443_358_new_function_2_reg.normal_burst_location = 0x094;
			separate_443_358_new_function_3_reg.wide_burst_location_endreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_startreg_en = 0x1;
			separate_443_358_new_function_3_reg.wide_burst_location_end = 0x0d3;
			separate_443_358_new_function_3_reg.wide_burst_location_start = 0x055;
			break;
#endif
		}
		vdcf_outl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_3_reg, separate_443_358_new_function_3_reg.regValue);
		vdcf_outl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_2_reg, separate_443_358_new_function_2_reg.regValue);
		vdcf_outl(VDTOP_SEPARATE_443_358_NEW_FUNCTION_1_reg, separate_443_358_new_function_1_reg.regValue);
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "Set auto burst position, mode:%x ", ucMode);
#ifdef VD_BURST_LOCATION_AUTO
		drvif_module_vdc_enable_burst_location_auto();
#endif
	}
}

void drvif_module_vdc_Analog_FIFO_Reset(void)
{
	/* 1_80d4 */
	vd_ifd_input_vd_input_fifo_status1_RBUS vd_input_fifo_status1_data;//sunray
	//vd_input_fifo_status1_data.regValue = vdcf_inl(FEIN_VD_INPUT_FIFO_STATUS1_reg);
	vd_input_fifo_status1_data.regValue = vdcf_inl(VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg);//sunray
	vd_input_fifo_status1_data.adc_sync_fifo_clr = 1;
	vd_input_fifo_status1_data.vd_fifo_clr = 1;
	//vdcf_outl(FEIN_VD_INPUT_FIFO_STATUS1_reg, vd_input_fifo_status1_data.regValue);
	vdcf_outl(VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg, vd_input_fifo_status1_data.regValue);//sunray
	mdelay(10);
	vd_input_fifo_status1_data.adc_sync_fifo_clr = 0;
	vd_input_fifo_status1_data.vd_fifo_clr = 0;
	//vdcf_outl(FEIN_VD_INPUT_FIFO_STATUS1_reg, vd_input_fifo_status1_data.regValue);
	vdcf_outl(VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg, vd_input_fifo_status1_data.regValue);//sunray
	VDC_DEBUG_MSG(VDC_MSG_RESET, "drvif_module_vdc_Analog_FIFO_Reset\n");
}

#ifdef VD_Digital_FIFO
void module_vdc_set_new_fifo_parameter(void)
{
	/* 9764, 977c, 9780 */
	vdtop_misc_control_RBUS misc_control_reg;
	misc_control_reg.regValue = vdcf_inl(VDTOP_MISC_CONTROL_reg);
	misc_control_reg.fifo_wo_ps = 1;	/*9764[20]= 1 */
	vdcf_outl(VDTOP_MISC_CONTROL_reg, misc_control_reg.regValue);

	vdtop_fifo_wo_ps_func_RBUS fifo_wo_pa_func_reg;
	fifo_wo_pa_func_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_FUNC_reg);
	fifo_wo_pa_func_reg.fifo_wo_ps_read_repeat_en = 1;
	fifo_wo_pa_func_reg.fifo_wo_ps_clk_jump = 1;
	fifo_wo_pa_func_reg.fifo_wo_ps_err_act = 1;
	fifo_wo_pa_func_reg.fifo_wo_ps_adapt = 1;
	fifo_wo_pa_func_reg.fifo_wo_ps_hlen_min = 0x334;
	fifo_wo_pa_func_reg.fifo_depth_wo_ps_min = 0x06;
	fifo_wo_pa_func_reg.fifo_depth_wo_ps_max = 0xfa;
	vdcf_outl(VDTOP_FIFO_WO_PS_FUNC_reg, fifo_wo_pa_func_reg.regValue);

	vdtop_fifo_wo_ps_clk_state_parameter_RBUS fifo_wo_ps_clk_state_parameter_reg;
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);

	/* read freq and set VD PS frequency */
	switch (drvif_module_Read_pll27x_vco_setting()) {
	default:
	case VDC_PLL27x_CLK_540M:
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i1 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel1 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv1 = 0x10;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i0 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel0 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv0 = 0x10;
		VDC_DEBUG_MSG(VDC_MSG_INIT, "[FIFO] Set 540M");
		break;
	case VDC_PLL27x_CLK_432M:
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i1 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel1 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv1 = 0x0e;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i0 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel0 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv0 = 0x0e;
		VDC_DEBUG_MSG(VDC_MSG_INIT, "[FIFO] Set 432M");
		break;
	case VDC_PLL27x_CLK_324M:
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i1 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel1 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv1 = 0x09;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_up_i0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_dn_i0 = 1;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 0;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_psel0 = 0x07;
		fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_ndiv0 = 0x09;
		VDC_DEBUG_MSG(VDC_MSG_INIT, "[FIFO] Set 324M");
		break;
	}
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
	fifo_wo_ps_clk_state_parameter_reg.regValue = vdcf_inl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg);
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload1 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_pselload0 = 1;
	fifo_wo_ps_clk_state_parameter_reg.fifo_wo_ps_ps_divload0 = 1;
	vdcf_outl(VDTOP_FIFO_WO_PS_CLK_STATE_PARAMETER_reg, fifo_wo_ps_clk_state_parameter_reg.regValue);
}
#endif

#ifdef VD_hdto_adjust
#define HDTO_ch_count1	20
#define HDTO_ch_count2	(HDTO_ch_count1+HDTO_ch_count1)
#define HDTO_ch_count3	(HDTO_ch_count2+HDTO_ch_count1)

#define HDTO_NTSC	0
#define HDTO_PAL	1
#define HDTO_PALM	2
#define HDTO_PALN	3

#define HDTO_P200	0
#define HDTO_P800	1
#define HDTO_P1400	2
#define HDTO_N200	3
#define HDTO_N800	4
#define HDTO_N1600	5

#define HDTO_P1K	0x22a00000
#define HDTO_N1K	0x1c000000

static unsigned char ucVdc_hdto_count = 0x00;
void drvif_module_vdc_nosignal_hdto_check(void)
{
	unsigned char ucVdc_locked = 0x00;
	ucVdc_hdto_count++;
	VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns]drvif_module_vdc_nosignal_hdto_check [ucVdc_hdto_count] = %d", ucVdc_hdto_count);
#if 0
	if ((ucVdc_hdto_count > 5) && (ucVdc_hdto_count <= 50)) {
		if (module_vdc_read_hdto_inc() != HDTO_N1K)
			module_vdc_set_hdto_inc(HDTO_N1K);
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns] hdto=%x, hv locked=%x ~~ (%d)", module_vdc_read_hdto_inc(),
					  drvif_video_status_reg(VDC_STATUS_REG1), ucVdc_hdto_count);
		/*		if(drvif_video_status_reg(VDC_hv_lock))*/
		if (vdc_LockStatus) {
			VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][1] h/v locked ! hdto=%x (%d)", module_vdc_read_hdto_inc(), ucVdc_hdto_count);
			return;
		}
	}
#else
	if ((ucVdc_hdto_count > 0) && (ucVdc_hdto_count <= HDTO_ch_count1)) {
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][1] reset hdto and checked ~~ (%d)", ucVdc_hdto_count);
		if (module_vdc_read_hdto_inc() != HDTO_Default)
			module_vdc_set_hdto_inc(HDTO_Default);
		/* if(drvif_video_status_reg(VDC_hv_lock)) */
		if (vdc_LockStatus) {
			VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][1] h/v locked ! hdto=%x (%d)", module_vdc_read_hdto_inc(), ucVdc_hdto_count);
			return;
		}
	} else if ((ucVdc_hdto_count > HDTO_ch_count1) && (ucVdc_hdto_count <= HDTO_ch_count2)) {
		/* check H + 1KHz */
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][2] reset hdto and checked ~~ (%d)", ucVdc_hdto_count);
		if (module_vdc_read_hdto_inc() != HDTO_P1K)
			module_vdc_set_hdto_inc(HDTO_P1K);
		/* if(drvif_video_status_reg(VDC_hv_lock)) */
		if (vdc_LockStatus) {
			VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][2] h/v locked ! hdto=%x (%d)", module_vdc_read_hdto_inc(), ucVdc_hdto_count);
			return;
		}
	} else if ((ucVdc_hdto_count > HDTO_ch_count2) && (ucVdc_hdto_count <= HDTO_ch_count3)) {
		/* check H + 1KHz */
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][3] reset hdto and checked ~~ (%d)", ucVdc_hdto_count);
		if (module_vdc_read_hdto_inc() != HDTO_N1K)
			module_vdc_set_hdto_inc(HDTO_N1K);
		/* if(drvif_video_status_reg(VDC_hv_lock)) */
		if (vdc_LockStatus) {
			VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns][3] h/v locked ! hdto=%x (%d)", module_vdc_read_hdto_inc(), ucVdc_hdto_count);
			return;
		}
	}
#endif
	else if (ucVdc_hdto_count > HDTO_ch_count3) {
		ucVdc_hdto_count = 0;
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[ns]drvif_module_vdc_nosignal_hdto_check done!");
	}
}

void drvif_module_vdc_hpll_extend_detect(void)
{
	UINT8 VD_mode;
	UINT32 vd_hdto;

	if (vdc_NoiseStatus > 0x08) {
		if (module_vdc_read_hdto_inc() != HDTO_Default)
			module_vdc_set_hdto_inc(HDTO_Default);
		VDC_DEBUG_MSG(VDC_MSG_HDTO, "[VDC][HDTO] too noisy return !!");
		return;
	}

	VD_mode = drvif_module_vdc_ReadMode(VDC_SET);
	VDC_DEBUG_MSG(VDC_MSG_HDTO, "[HDTO] ====== drvif_module_vdc_hpll_extend_detect ====== mode:%x", VD_mode);
	/* if(drvif_video_status_reg(VDC_hv_lock)) */
	if (vdc_LockStatus) {
		ucVdc_hdto_count = 0;
		if ((VD_mode == VDC_MODE_NTSC) || (VD_mode == VDC_MODE_NTSC50)) {
			vd_hdto = drvif_module_vdc_Hdto_status();
			VDC_DEBUG_MSG(VDC_MSG_HDTO, "%x, set= %x,           lock:%x", vd_hdto, module_vdc_read_hdto_inc(), drvif_video_status_reg(VDC_STATUS_REG1));

			if ((vd_hdto < VDC_HDTO_table[HDTO_NTSC][HDTO_P200])
				&& (vd_hdto > VDC_HDTO_table[HDTO_NTSC][HDTO_N200])) {
				if (module_vdc_read_hdto_inc() != HDTO_Default) {
					module_vdc_set_hdto_inc(HDTO_Default);
					VDC_DEBUG_MSG(VDC_MSG_HDTO, "-200Hz < NTSC < +200Hz, set to default, HDTO to: %x ", module_vdc_read_hdto_inc());
				}
			} else if (vd_hdto > VDC_HDTO_table[HDTO_NTSC][HDTO_P800]) {
				if (vd_hdto > VDC_HDTO_table[HDTO_NTSC][HDTO_P1400]) {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_NTSC][HDTO_P1400])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_NTSC][HDTO_P1400]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "NTSC > +1.4KHz, set HDTO to: %x ", module_vdc_read_hdto_inc());
					}
				} else {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_NTSC][HDTO_P800])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_NTSC][HDTO_P800]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "NTSC > +800Hz, set HDTO to: %x ", module_vdc_read_hdto_inc());
					}
				}
			} else if (vd_hdto < VDC_HDTO_table[HDTO_NTSC][HDTO_N800]) {
				if (vd_hdto < VDC_HDTO_table[HDTO_NTSC][HDTO_N1600]) {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_NTSC][HDTO_N1600])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_NTSC][HDTO_N1600]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "NTSC > -1.6KHz, set HDTO to: %x ~~~", module_vdc_read_hdto_inc());
					}
				} else {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_NTSC][HDTO_N800])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_NTSC][HDTO_N800]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "NTSC > -800Hz, set HDTO to: %x ~~~", module_vdc_read_hdto_inc());
					}
				}
			}
		}

		else if (VD_mode == VDC_MODE_PALI) {
			vd_hdto = drvif_module_vdc_Hdto_status();
			VDC_DEBUG_MSG(VDC_MSG_HDTO, " %x, set= %x,           lock:%x", vd_hdto, module_vdc_read_hdto_inc(), drvif_video_status_reg(VDC_STATUS_REG1));
			if ((vd_hdto < VDC_HDTO_table[HDTO_PAL][HDTO_P200])
				&& (vd_hdto > VDC_HDTO_table[HDTO_PAL][HDTO_N200])) {
				if (module_vdc_read_hdto_inc() != HDTO_Default) {
					module_vdc_set_hdto_inc(HDTO_Default);
					VDC_DEBUG_MSG(VDC_MSG_HDTO, " -200Hz < PAL < +200Hz, set to default, HDTO to: %x ", module_vdc_read_hdto_inc());
				}
			} else if (vd_hdto > VDC_HDTO_table[HDTO_PAL][HDTO_P800]) {
				if (vd_hdto > VDC_HDTO_table[HDTO_PAL][HDTO_P1400]) {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_PAL][HDTO_P1400])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_PAL][HDTO_P1400]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "PAL > +1.4KHz, set HDTO to: %x ", module_vdc_read_hdto_inc());
					}
				} else {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_PAL][HDTO_P800])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_PAL][HDTO_P800]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "PAL > +800Hz, set HDTO to: %x ", module_vdc_read_hdto_inc());
					}
				}
			} else if (vd_hdto < VDC_HDTO_table[HDTO_PAL][HDTO_N800]) {
				if (vd_hdto < VDC_HDTO_table[HDTO_PAL][HDTO_N1600]) {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_PAL][HDTO_N1600])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_PAL][HDTO_N1600]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "PAL > -1.6KHz, set HDTO to: %x ~~~", module_vdc_read_hdto_inc());
					}
				} else {
					if (module_vdc_read_hdto_inc() != (VDC_HDTO_table[HDTO_PAL][HDTO_N800])) {
						module_vdc_set_hdto_inc(VDC_HDTO_table[HDTO_PAL][HDTO_N800]);
						VDC_DEBUG_MSG(VDC_MSG_HDTO, "PAL > -800Hz, set HDTO to: %x ~~~", module_vdc_read_hdto_inc());
					}
				}
			}
		}
	} else {
		drvif_module_vdc_nosignal_hdto_check();
	}
}
#endif

/**
   Get status of drv_module_vdc_GetVideoScaleInfo

   @param <enableTvScan>   { ENABLE/DISABLE }
   @return                  { true/false }
    add by josh@2008/10/21
*/
unsigned short drv_module_vdc_GetVideoScaleInfo(VDC_VIDEO_SCALE_INFO info)
{
	if (info < VDC_VIDEO_SCALE_IHTOTAL || info > VDC_VIDEO_SCALE_IVHEIGHT)
		return 0;

	return gVideoTableInputInfo[field][info];
}

unsigned char drv_module_vdc_GetVdcPreMode(void)
{
	return ucVdc_Pre_Mode;
}

void drv_module_vdc_SetVdcCurrMode(unsigned char value)
{
	ucVdc_Curr_Mode = value;
}

unsigned char drv_module_vdc_GetVdcCurrMode(void)
{
	return ucVdc_Curr_Mode;
}

unsigned char drv_module_vdc_SetVarFieldVTotal(unsigned short vTotal)
{
	FieldVTotal = vTotal;
	return TRUE;
}

unsigned short drv_module_vdc_GetVarFieldVTotal(void)
{
	return FieldVTotal;
}

/**
 *   drvif_module_vdc_GetVHalfTotalLen
 *   Read VDC output lines of one field
 *
 *   @param	<unsigned short*>	{ output lines of one field }
 *   @return	<unsigned char>		{ SUCCESS(TRUE) / FAIL(FALSE) }
 */
unsigned char drvif_module_vdc_GetVHalfTotalLen(unsigned short *VActLen)
{
	unsigned short val1, val2, vrange1, vrange2, Vline;
	unsigned char real_standard;
	vdtop_vsync_vbi_lockout_end_RBUS vsync_vbi_lockout_end_reg;

	val1 = drvif_module_vdc_read_V_1st_line();
	val2 = drvif_module_vdc_read_V_2nd_line();

	Vline = ABS(val1, val2);
	if (Vline > 1)		/* only accept 0 or 1 */
		return FALSE;

#ifndef CONFIG_FV_CHECK_ByMode
	if (((val2 + val1) < 425) || ((val2 + val1) > 725)) {
		/* avoid non-standard signal error working.. */
		return FALSE;
	}
#endif

	real_standard = drvif_module_vdc_ReadMode(VDC_DETECT);
	if ((real_standard == VDC_MODE_NTSC) || (real_standard == VDC_MODE_PALM)) {
		/*input lines = 525 */
		vrange1 = 0x0119;		/*(564 / 2) lines */
		vrange2 = 0x00f7;		/*(496 / 2) lines */
#ifdef CONFIG_FV_CHECK_ByMode
		if (((val2 + val1) < 485) || ((val2 + val1) > 565)) {
			/* avoid signal out of range, NTSC:485~565 */
			return FALSE;
		}
#endif
	} else {	/*input lines = 625 */
		vrange1 = 0x014c;	/*(664 / 2) lines */
		vrange2 = 0x012a;	/*(596 / 2) lines */
#ifdef CONFIG_FV_CHECK_ByMode
		if (((val2 + val1) < 585) || ((val2 + val1) > 665)) {
			/* avoid signal out of range, PAL:585~665 */
			return FALSE;
		}
#endif
	}

	*VActLen = ((val1 > val2) ? val1 : val2);
	/*vdtop_vsync_vbi_lockout_end_RBUS vsync_vbi_lockout_end_reg; */
	vsync_vbi_lockout_end_reg.regValue = vdcf_inl(VDTOP_VSYNC_VBI_LOCKOUT_END_reg);

	if ((*VActLen) > vrange1 || (*VActLen < vrange2)) {
		/*set VDC_VSYNC_VBI_LOCKOUT_END_reg bit7:1 */
		if (vsync_vbi_lockout_end_reg.vlock_wide_range == 0) {
			vsync_vbi_lockout_end_reg.vlock_wide_range = 1;
			vdcf_outl(VDTOP_VSYNC_VBI_LOCKOUT_END_reg, vsync_vbi_lockout_end_reg.regValue);
		}
	} else {
		/*set VDC_VSYNC_VBI_LOCKOUT_END_reg bit7:0 */
		if (vsync_vbi_lockout_end_reg.vlock_wide_range == 1) {
			vsync_vbi_lockout_end_reg.vlock_wide_range = 0;
			vdcf_outl(VDTOP_VSYNC_VBI_LOCKOUT_END_reg, vsync_vbi_lockout_end_reg.regValue);
		}
	}
	return TRUE;
}

#ifdef CONFIG_ENABLE_VDC_BURST_CHECK
void module_vdc_Burst_check(unsigned char ucMode, unsigned char ucNoiseStatus, unsigned char BurstMag)
{
	if (ucMode == VDC_MODE_PALI) {
		if (drvif_module_vdc_Read_27M_FrontDigitalFilter_info() != VDC_27M_FDF_Table) {
			if ((ucNoiseStatus < 0x20) && (BurstMag > 0x80)) {
				drvif_module_vdc_adc_27M_LPF_coef_Table(VDC_27M_LPF_43MHz);
				drvif_module_vdc_27M_FrontDigitalFilterEnable(VDC_27M_FDF_Table);
				VDC_DEBUG_MSG(VDC_MSG_CHROMA, "Burst is too Big !!");
			}
		}
	}
}
#endif

void drvif_module_vdc_FixCKillMode(unsigned char a_ucFixed)
{
	/*rtd_printk(KERN_DEBUG, TAG_NAME_VDC,"[vdc]drvif_module_vdc_FixCKillMode a_ucFixed=%x\n", a_ucFixed);*/
	g_ucFixCKillMode = a_ucFixed;
}

void drvif_module_vdc_Chroma_control(unsigned char ucInputSrc)
{
	unsigned char vd_mode;
	unsigned char average_burst;
	vd_mode = drvif_module_vdc_ReadMode(VDC_SET);
	average_burst = drvif_module_vdc_burst_mag_status();
#ifdef CONFIG_ENABLE_VDC_BURST_CHECK
	module_vdc_Burst_check(vd_mode, vdc_NoiseStatus, average_burst);
#endif

	VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[NM_PAL_Chroma_control] vdc_NoiseStatus=%x,average_burst=%x,Cgain=%x", vdc_NoiseStatus, average_burst, drvif_module_vdc_read_Cgain());
	if (vd_mode == VDC_MODE_SECAM) {
		if (_SRC_TV == ucInputSrc) {
			module_vdc_Set_CKill_Gain_Kill_Thl_Value(_DISABLE, 0x100, 0x2000);	/*disable  using Ckill judge by CPll Cgain */
			average_burst = drvif_module_vdc_burst_mag_status();
			if (average_burst > 0x05) {
				/* ckill off */
				if (drvif_module_vdc_Get_CKill_Mode() != CKill_OFF)
					drvif_module_vdc_Set_CKill_Mode(CKill_OFF);
			} else {
				/* auto hardware ckill */
				if (drvif_module_vdc_Get_CKill_Mode() != CKill_AUTO)
					drvif_module_vdc_Set_CKill_Mode(CKill_AUTO);
			}
		}
	}
#ifdef CONFIG_ENABLE_VDC_CKILL_CONTROL
	else if (vd_mode == VDC_MODE_NTSC) {
		if (ucInputSrc == _SRC_TV) {
			if (vdc_NoiseStatus <= 0x6) {
				module_vdc_Set_CKill_Gain_Kill_Thl_Value(_ENABLE, 0x100, ucTV_NTSC_Ckill_thl);
			} else {
				module_vdc_Set_CKill_Gain_Kill_Thl_Value(_DISABLE, 0x100, 0x2000);
			}
		} else if ((ucInputSrc == _SRC_CVBS) && (vdc_NoiseStatus < 0x5))
			module_vdc_Set_CKill_Gain_Kill_Thl_Value(_ENABLE, 0x100, ucAV_NTSC_Ckill_thl);
		else
			module_vdc_Set_CKill_Gain_Kill_Thl_Value(_DISABLE, 0x100, 0x2000);
	} else if (vd_mode == VDC_MODE_PALI) {
		if (ucInputSrc == _SRC_TV) {
			if (vdc_NoiseStatus <= 0x6) {
				module_vdc_Set_CKill_Gain_Kill_Thl_Value(_ENABLE, 0x100, ucTV_PAL_Ckill_thl);
			} else {
				module_vdc_Set_CKill_Gain_Kill_Thl_Value(_DISABLE, 0x100, 0x2000);
			}
		} else if ((ucInputSrc == _SRC_CVBS) && (vdc_NoiseStatus < 0x12)) {
			module_vdc_Set_CKill_Gain_Kill_Thl_Value(_ENABLE, 0x100, ucAV_PAL_Ckill_thl);
		} else {
			module_vdc_Set_CKill_Gain_Kill_Thl_Value(_DISABLE, 0x100, 0x2000);
		}
	}
#endif
	else {
		if (drvif_module_vdc_Get_CKill_Mode() != CKill_AUTO)
			drvif_module_vdc_Set_CKill_Mode(CKill_AUTO);
	}
}

#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
unsigned char module_video_check_Hsync_power(unsigned char mode)
{
	/* 956c[31:24][23:16] */
#if 1
	unsigned char uc443power, uc358power;
	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
	uc443power = sep_burst_ro2_reg.sep_443_core_burst_hsync;
	uc358power = sep_burst_ro2_reg.sep_358_core_burst_hsync;

	if (mode == VDC_MODE_NTSC) {
		if ((uc443power < 0x0a) && (uc358power > 0xfa))
			color_count++;
		if ((uc443power < 0x0a) && (uc358power < 0xc0))
			normal_count++;

		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[cpeak] NTSC 443_p=%x, 358_p=%x, c(%d) n(%d) ", uc443power, uc358power, color_count, normal_count);
	} else if (mode == VDC_MODE_PALI) {
		if ((uc358power < 0x2a) && (uc443power > 0xfa))
			color_count++;
		if ((uc358power < 0x2a) && (uc443power < 0xc0))
			normal_count++;

		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[cpeak] PAL 443_p=%x, 358_p=%x, c(%d) n(%d) ", uc443power, uc358power, color_count, normal_count);
	}

	if ((vdc_LoopCount & 0x0f) == 0) {
		if ((color_count > 8) && (normal_count < 5)) {
			VDC_CpeakSet = vd_cpeak_enable;
		} else if ((normal_count > 8) && (color_count < 5)) {
			VDC_CpeakSet = vd_cpeak_disable;
		} else {
			VDC_CpeakSet = vd_cpeak_thesame;
		}
		color_count = 0;
		normal_count = 0;
	}
	VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[cpeak] VDC_CpeakSet :%x ", VDC_CpeakSet);
	return VDC_CpeakSet;
#else
	unsigned char uc443power, uc358power;
	unsigned char i = 0;
	unsigned char color_count = 0, normal_count = 0;

	vdtop_sep_burst_ro_2_RBUS sep_burst_ro2_reg;
	for (i = 0; i < 10; i++) {
		sep_burst_ro2_reg.regValue = vdcf_inl(VDTOP_SEP_BURST_RO_2_reg);
		uc443power = sep_burst_ro2_reg.sep_443_core_burst_hsync;
		uc358power = sep_burst_ro2_reg.sep_358_core_burst_hsync;
		if (mode == VDC_MODE_NTSC) {
			if ((uc443power < 0x0a) && (uc358power > 0xfa))
				color_count++;
			if ((uc443power < 0x0a) && (uc358power < 0xc0))
				normal_count++;
			VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] NTSC 443_p=%x, 358_p=%x, c(%d) n(%d) ", uc443power, uc358power, color_count, normal_count);
		} else if (mode == VDC_MODE_PALI) {
			if ((uc358power < 0x2a) && (uc443power > 0xfa))
				color_count++;
			if ((uc358power < 0x2a) && (uc443power < 0xc0))
				normal_count++;
			VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] PAL 443_p=%x, 358_p=%x, c(%d) n(%d) ", uc443power, uc358power, color_count, normal_count);
		}
		Rt_Delay(1);
	}
	if ((color_count > 5) && (normal_count < 2))
		return vd_cpeak_enable;
	else if ((normal_count > 5) && (color_count < 2))
		return vd_cpeak_disable;
	else
		return vd_cpeak_thesame;
#endif
}

void drvif_module_vdc_Cpeak_control(unsigned char ucInputSrc)
{
#if 1
#ifdef CONFIG_SCART_ENABLE
	if ((ucInputSrc == _SRC_SV) || (ucInputSrc == _SRC_SCART) || (ucInputSrc == _SRC_SCART_RGB)) {
#else
	if (ucInputSrc == _SRC_SV) {
#endif
		drvif_module_vdc_Cpeak_set(_ENABLE);
	} else {
		drvif_module_vdc_Cpeak_set(_DISABLE);
	}
#else
	if (drvif_module_vdc_CheckFactoryModEnable(ON))
		return;

	unsigned char average_burst;
	unsigned char vd_mode;
	unsigned char vd_power;

	if (vdc_NoiseStatus < 0x0a) {
		/* > 55db, cpeak enable check flow */
		if (ucInputSrc == _SRC_CVBS) {
			/* is AV source */
			vd_mode = drvif_module_vdc_ReadMode(VDC_DETECT);
		} else {
			/* is TV source */
			if (drvif_module_vdc_ReadMode(VDC_DETECT) != drvif_module_vdc_ReadMode(VDC_SET))
				vd_mode = VDC_MODE_ERROR;
			else
				vd_mode = drvif_module_vdc_ReadMode(VDC_DETECT);
		}

		vd_power = module_video_check_Hsync_power(vd_mode);
#ifdef VDC_CPeak_Debug_Print
		VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] cpeak check power = %x ", vd_power);
#endif
		if (vd_power == vd_cpeak_enable) {
			if (!module_vdc_Cpeak_read())
				VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] cpeak on !!!! ");
			drvif_module_vdc_Cpeak_set(_ENABLE);
		} else if (vd_power == vd_cpeak_disable) {
			if (module_vdc_Cpeak_read())
				VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] cpeak off ~~~~");
			drvif_module_vdc_Cpeak_set(_DISABLE);
		}
	} else if (vdc_NoiseStatus > 0x15) {
		/* < 50db, cpeak disable */
		if (module_vdc_Cpeak_read())
			VDC_DEBUG_MSG(VDC_MSG_CHROMA, "[VDC] too noise %x, cpeak off ", vdc_NoiseStatus);
		drvif_module_vdc_Cpeak_set(_DISABLE);
	}
#endif
}
#endif

VDC_FRAME_RATE drv_module_vdc_GetFrameRate(void)
{
	return field;
}

void drvif_video_color_burst_check_power(unsigned char ucEnable)
{
	/*lewis, if turn on PIP mode, need careful */
#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
	adc_power_RBUS adc_power_reg;
	adc_clamp_ctrl2_RBUS adc_clamp_ctrl2_reg;

	if (_ENABLE == ucEnable) {
		adc_power_reg.regValue = rtdf_inl(ADC_ADC_POWER_reg);
		adc_power_reg.adc_power_8 = 1;
		rtdf_outl(ADC_ADC_POWER_reg, adc_power_reg.regValue);

#ifdef CONFIG_DUAL_CHANNEL
		adc_clamp_ctrl2_reg.regValue = rtdf_inl(ADC_ADC_CLAMP_CTRL2_reg);
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_11_0 = 0xfff;
		rtdf_outl(ADC_ADC_CLAMP_CTRL2_reg, adc_clamp_ctrl2_reg.regValue);
#endif
	} else {
		adc_clamp_ctrl2_reg.regValue = rtdf_inl(ADC_ADC_CLAMP_CTRL2_reg);
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_11_0 = 0;
		rtdf_outl(ADC_ADC_CLAMP_CTRL2_reg, adc_clamp_ctrl2_reg.regValue);
		adc_power_reg.regValue = rtdf_inl(ADC_ADC_POWER_reg);
		adc_power_reg.adc_power_8 = 0;
		rtdf_outl(ADC_ADC_POWER_reg, adc_power_reg.regValue);
	}
#endif
}

unsigned char drvif_video_color_burst_check(unsigned char threshold, unsigned char checkcnt)
{
#ifdef CONFIG_ENABLE_YPBPR_AND_AV_USE_SAME_PATH
	/*lewis 20100107, double check color burst, to prevent color burst magnitude unstable */
	vdtop_avg_burst_mag_status_RBUS avg_burst_mag_status_reg;
	unsigned char i = 0;

	for (i = 0; i < checkcnt; i++) {
		Rt_Delay(100);
		VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "[VDC] VDC_VIDEO_STATUS_REG1_reg :%x", VIDEO_STATUS_REG1_reg.regValue);
		/* if(drvif_video_status_reg(VDC_hv_lock)) */
		if (vdc_LockStatus) {
			avg_burst_mag_status_reg.regValue = drvif_module_vdc_burst_mag_status();
			VDC_DEBUG_MSG(VDC_MSG_DEBUG1, " Color Burst :%x", AVG_BURST_MAG_STATUS_reg.burst_magnitude);

			if (avg_burst_mag_status_reg.burst_magnitude >= threshold)
				return _TRUE;
		}
	}
	return _FALSE;
#else
	return _FALSE;
#endif
}

#if 0
void drvif_video_set_secam_setting(void)
{
	drvif_module_vdc_PreferModeSetting(VDC_MODE_SECAM);
	drvif_module_vdc_SetMode(VDC_MODE_SECAM);
//	drvif_module_vdc_set_burst_gate_position(VDC_MODE_PALI);
	drvif_module_vdc_set_burst_gate_position(VDC_MODE_SECAM);
//	module_vdc_Fixed_burstgate();
}
#endif

#ifdef CONFIG_SCART_ENABLE
#if 0
static unsigned char scart_pin8_type = SCART_PIN8_LEVEL_NONE;
#endif
unsigned char drvif_video_get_SCART_type(void)
{
	return SCART_Type;
}

void drvif_video_FullSCART_func_initial(void)
{
	vdtop_fsw_ctrl2_RBUS fsw_ctrl2_reg;
	vdtop_fsw_gain_ctrl_RBUS fsw_gain_ctrl_reg;

	SCART_Type = _SCART_AV;
	pre_SCART_Type = 0xff;
	SCART_Counter = 0x00;
	SvNoBurstMark = 1;

	fsw_ctrl2_reg.regValue = vdcf_inl(VDTOP_FSW_CTRL2_reg);
	fsw_ctrl2_reg.fb_en = 1;	/* set SCART display depends on FSW */
	vdcf_outl(VDTOP_FSW_CTRL2_reg, fsw_ctrl2_reg.regValue);
#if 0
	module_vdc_SetSaturation_SCART(0x96, 0x60);	/* Cb, Cr default setting */
#endif
	fsw_gain_ctrl_reg.regValue = vdcf_inl(VDTOP_FSW_GAIN_CTRL_reg);
	fsw_gain_ctrl_reg.fbgain_en = 1;	/* Enable FSW full swing */
	vdcf_outl(VDTOP_FSW_GAIN_CTRL_reg, fsw_gain_ctrl_reg.regValue);
	VDC_DEBUG_MSG(VDC_MSG_SCART, "Full SCART initial");
}

#define ROS_ENTER_CRITICAL()
#define ROS_EXIT_CRITICAL()
void drvif_video_SCART_func_check(void)
{
	/* Check AV or RGB */
	if (drvif_module_vdc_read_FSW_value() >= cSCART_FSW_Level) {	/* is RGB */
#if 1
		if (SCART_Type != _SCART_RGB) {
#else
		if (drvif_video_read_SCART_RGB_set() == 0) {
#endif
			VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] set SCART RGB");
			drvif_video_SCART_RGB_set(_ENABLE);	/* Enable SCART function */
			SCART_Type = _SCART_RGB;
		}
	} else {	/*AV */
		VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] set SCART RGB");
		VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SCART][SCART_Type:%x] ", (unsigned int)SCART_Type);
		VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SCART][pre_SCART_Type:%x] ", (unsigned int)pre_SCART_Type);
		VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SCART][SCART_Counter:%x] ", (unsigned int)SCART_Counter);
		VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SCART][SvNoBurstMark:%x] ", (unsigned int)SvNoBurstMark);
#if 1
		if (SCART_Type == _SCART_RGB) {
#else
		if (drvif_video_read_SCART_RGB_set() == 1) {
#endif
			drvif_video_SCART_RGB_set(_DISABLE);		/* Disable SCART function */
		}

		if (SCART_Type != pre_SCART_Type)
			SCART_Counter = 0x00;

		if ((SCART_Type == _SCART_AV) && (pre_SCART_Type == _SCART_AV)) {
			VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] check is AV and C is locked");
			if (drvif_module_vdc_burst_mag_status() < 4) {	/* burst unlocked */
				SCART_Counter++;
				VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV]SCART_Counter:%x", (unsigned int)SCART_Counter);
			}
		}

		if (drvif_video_control_reg(VDC_yc_src)) {	/*now is set SV */
			VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] Is SV, burst mag.:%x", drvif_module_vdc_burst_mag_status());
			if (drvif_module_vdc_burst_mag_status() > 4) {	/* burst locked */
				SvNoBurstMark = 0;
				SCART_Counter = 0x00;
				SCART_Type = _SCART_SV;
				VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SV] Is SV ");
			} else {
				SvNoBurstMark = 1;
				SCART_Type = _SCART_AV;
				drvif_video_set_control_reg(VDC_set_src_AV);
				VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SV --> AV] reset");
			}
		} else { /*now is set AV */
			VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] Is AV, burst mag.:%x", drvif_module_vdc_burst_mag_status());
			if (drvif_module_vdc_burst_mag_status() > 4) {	/* burst locked */
				if (SvNoBurstMark == 0) {
					VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV] change mode, SvNoBurstMark:%x", (unsigned int)SvNoBurstMark);
					pre_SCART_Type = 0xff;      /* need to change mode */
				}
				SvNoBurstMark = 1;
				SCART_Counter = 0x00;
				SCART_Type = _SCART_AV;
				VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV], c locked, SvNoBurstMark:%x", (unsigned int)SvNoBurstMark);
			} else {
				VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV], c Un locked !!!! SvNoBurstMark:%x", (unsigned int)SvNoBurstMark);
				if (SCART_Counter >= cSCART_constant) {
					SCART_Counter = 0x00;

					ROS_ENTER_CRITICAL();
					WaitFor_DEN_STOP();
					ROS_EXIT_CRITICAL();

					drvif_video_set_control_reg(VDC_set_src_SV);
					VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV --> SV] check 1, reg.9004:%x", drvif_video_control_reg(VDC_CONTROL_REG1));
					Rt_Delay(10);
					if (drvif_module_vdc_burst_mag_status() > 4) {
						SCART_Type = _SCART_SV;
						if (drvif_video_read_SCART_RGB_set() == 1) {
							drvif_video_SCART_RGB_set(_DISABLE);
							VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [AV --> SV]");
						}
					} else {
						ROS_ENTER_CRITICAL();
						WaitFor_DEN_STOP();
						ROS_EXIT_CRITICAL();

						Rt_Delay(10);
						drvif_video_set_control_reg(VDC_set_src_AV);
						VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] reset to AV, reg.9004:%x", drvif_video_control_reg(VDC_CONTROL_REG1));
					}
				}

				if (SvNoBurstMark == 1) {
					SCART_Type = _SCART_AV;
					VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] Still set to AV");
				} else {
					if (drvif_video_read_SCART_RGB_set() == 1) {
						drvif_video_SCART_RGB_set(_DISABLE);
					}
					SCART_Type = _SCART_SV;
					VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [1][AV --> SV]");
				}
			}
		}
	}

	switch (SCART_Type) {
	case _SCART_AV:
	default:
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
		drvif_module_vdc_Cpeak_set(_DISABLE);
#endif
		drvif_module_vdc_auto_secamFlag_select(SEL_PAL);
		module_vdc_SECAM_flag_select(1);
		break;
	case _SCART_SV:
	case _SCART_RGB:
		if ((SCART_Type == _SCART_SV) &&
			(drvif_module_vdc_ReadMode(VDC_DETECT) == VDC_MODE_PALI))
			drvif_module_vdc_set_Hsync_start(cHsync_start_SV_PAL);
		else
			drvif_module_vdc_set_Hsync_start(cHsync_start_1D);
#ifdef CONFIG_ENABLE_VDC_CPEAK_CONTROL
		drvif_module_vdc_Cpeak_set(_ENABLE);
#endif
		drvif_module_vdc_auto_secamFlag_select(SEL_PALh_SECAMl);
		module_vdc_SECAM_flag_select(0);
		break;
	}

	VDC_DEBUG_MSG(VDC_MSG_SCART, "[VDC] [SCART_Type]%x, preset:%x", (unsigned int)SCART_Type, (unsigned int)pre_SCART_Type);
}
#endif

void drv_module_vdc_SetAutoScanFlag(unsigned char a_ucFlag)
{
	tvAutoScanFlag = a_ucFlag;
}
/*
unsigned char drv_module_vdc_GetAutoScanFlag()
{
        return tvAutoScanFlag;
}
*/
/* 20121015, for shanghai tvbox issue */
void drv_module_vdc_setAutoModeWithoutSecam(bool isEnable)
{
	vdc_autoMode_without_secam = isEnable;
}

void drvif_module_vdc_Set_VCR_mode(void)
{
	/* 91bc[27] = 0, 921c[2:0]=000
	VCR mode disble FreeRunn
	VCR mode disable SecondPLL
	VCR mode Killgate=11 */

	vdtop_under_new_th1_RBUS under_new_th1_reg;

	//under_new_th1_reg.regValue = vdcf_inl(VDTOP_UNDER_NEW_TH1_reg);
	under_new_th1_reg.regValue = vdcf_inl(VDTOP_under_new_th1_reg);//sunray

	if (under_new_th1_reg.headswitch_debounce_en) {
		under_new_th1_reg.headswitch_debounce_en = 0;
		//vdcf_outl(VDTOP_UNDER_NEW_TH1_reg, under_new_th1_reg.regValue);
		vdcf_outl(VDTOP_under_new_th1_reg, under_new_th1_reg.regValue);//sunray
		VDC_DEBUG_MSG(VDC_MSG_ERROR, "drvif_module_vdc_Set_VCR_mode");
		drvif_module_vdc_set_vsync_freerun_enable(_DISABLE);
		drvif_module_vdc_set_second_pll(Second_pll_disable);
		drvif_module_vdc_set_Killgate(VDC_kg_mode3);
#if 0
		hdetect_gate_ctrl_reg.regValue = vdcf_inl(VDTOP_HDETECT_GATE_CTRL_reg);
		hdetect_gate_ctrl_reg.new_hpll_lpf_sel = 0;
		hdetect_gate_ctrl_reg.gate_iir_v_sel = 0;
		hdetect_gate_ctrl_reg.gate_iir_h_sel = 0;
		vdcf_outl(VDTOP_HDETECT_GATE_CTRL_reg, hdetect_gate_ctrl_reg.regValue);
#else
		module_vdc_set_gate_hv_iir(0x00);
#endif
	}
}

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
unsigned char vd_lock_status(void)
{
	/* 9008[3:0] */
	vdtop_video_status_reg1_RBUS video_status_reg1_reg;
	video_status_reg1_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG1_reg);
	return (video_status_reg1_reg.regValue & 0x0F);
}
unsigned char vd_newVlock_status(void)
{
	/* 900c[6] */
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;
	video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
	return video_status_reg2_reg.vlock_new;
}
unsigned char vdc_read_Vlines_the_same_flag(void)
{
	/* 93f4[13] */
	vdtop_vsync_pll_freerun_mux_RBUS vsync_pll_freerun_mux_reg;
	vsync_pll_freerun_mux_reg.regValue = vdcf_inl(VDTOP_VSYNC_PLL_FREERUN_MUX_reg);
	return vsync_pll_freerun_mux_reg.vlines_the_same_flag;
}

unsigned char drvif_module_vdc_serration_check(void)
{
	UINT8 i = 0;
	UINT8 vd_Vstate = 0;
	UINT8 vstate1_count = 0;
	UINT8 vstate2_count = 0;
	UINT8 vstate3_count = 0;

	UINT8 ucMode = 0xff;

	vdtop_video_status_reg2_RBUS video_status_reg2_reg;

	/*	if(VDC_SERRATION_DEF == serration_status) */
	if (vlock_status == VDC_V_LOCK_DEF) {
		/*		if(!drvif_video_status_reg(VDC_vlock)) */
		if (!vdc_OldVLockStatus) {
			VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] old v unlocked, return !");
			return _FAIL;
		}

		/* Pass, need to check */
		ucMode = drvif_module_vdc_ReadMode(VDC_DETECT);
		VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] mode = %x ", ucMode);
		if ((ucMode == VDC_MODE_PALI) || (ucMode == VDC_MODE_NTSC) || (ucMode == VDC_MODE_NTSC443) || (ucMode == VDC_MODE_PAL60)) {
			VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] check Vstate go ~~");
#if 0
			for (i = 0; i < 25; i++)
				for (i = 0; i < 250; i++) {
#endif
					for (i = 0; i < 80; i++) {
						vd_Vstate = drvif_module_vdc_Read_Vstate();
						if (vd_Vstate == 1) {
							vstate1_count++;
						} else if (vd_Vstate == 2) {
							vstate2_count++;
						} else if (vd_Vstate == 3) {
							vstate3_count++;
							if ((vstate3_count > 3) || (video_status_reg2_reg.new_vdetect_stable)) {
								VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] Vstate or V stable okay, break num=%d", i);
								return _TRUE;	/* vstate = 3, return */
							}
						}
						VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] the_same_flag[13]=%x, vstate=%x, hvlock=%x, new vlock=%x [%d]",
									  vdc_read_Vlines_the_same_flag(), vd_Vstate, vd_lock_status(), vd_newVlock_status(), i);
						Rt_Delay(10);
					}
					VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] vstate1_count=%d, vstate2_count=%d, vstate3_count=%d ",
								  vstate1_count, vstate2_count, vstate3_count);

					if (vstate1_count >= 23) {
						drvif_module_vdc_new_vdetect_Enable(Old_vedetect);
						vlock_status = VDC_V_LOCK_OLD;
						VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] vstate is always 1, set to Old_vedetect");
						return _TRUE;
					}
					VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] mode = %x,  ====== START ====== ", ucMode);
					VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] v detect = %x", drvif_module_vdc_Read_New_Vdetect_Factory_Get_info());
				}
			else {
				/* do nothing */
				VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] this mode(%x) no need to checked, return !!!", ucMode);
				return _TRUE;
			}
		} else {
			/* do nothing */
			VDC_DEBUG_MSG(VDC_MSG_ERROR, "[serration test] Check done, bypass  !!! serration_status=%d", vlock_status);
			return _TRUE;
		}
		return _TRUE;
	}
#endif

#if 0
unsigned char Scaler_WaitVDCStable(void)
{
	UINT32 ulCount = 0, vline_count = 0;

#ifdef _jj_change_lock_function
	if (vdc_LockStatus)
#else
	if (drvif_video_status_reg(VDC_hv_lock))
#endif
	{
		for (ulCount = 0; ulCount <= 150; ulCount++) {

			/* to speed up channel switch rika@20131112 */
			if (3 == drvif_module_vdc_Read_Vstate()) {
				VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "[ATV][VDC] V-state=3,clear force BG,ulCount=%d", ulCount);
				break;
			}
			/* end of speedup */


			/* Make sure V-sync stable */
			if (!drvif_module_vdc_Read_Vline_freerun_status()) {
				vline_count++;
				if (vline_count == 30) {
					VDC_DEBUG_MSG(VDC_MSG_DEBUG1, "[ATV][VDC] DisplayReady: %d, vline freerun V state : %x", ulCount, drvif_module_vdc_Read_Vstate());
					break;
				}
			} else {
				vline_count = 0;
			}

			Rt_Delay(12);
		}
	}
	return drvif_module_vdc_Read_Vstate();
}
#endif

void drvif_module_vdc_input_filter_sel(bool enable, UINT16 * table)
{
	drv_module_vdc_input_filter_sel(enable, &table[0]);
}


/*=================================================================
* Input FIFO
================================================================= */
void drv_module_vdc_input_filter_sel(bool enable, UINT16 * table)
{	// 8090[0], 8000~808C
	UINT8 i;
	vd_ifd_input_108_input_flt_en_RBUS input_flt_en_rbus_data;

	/* modified input filter coef. */
	UINT32 addr_base = VD_IFD_INPUT_108_input_flt_tap_0_1_reg;

	for (i = 0; i < (INPUT_FILTER_TABLE_SIZE >> 1); i++) {
		vdcf_outl(addr_base + i * 4, table[2 * i] << 16 | table[2 * i + 1]);
	}

	/* enable input filter */
	input_flt_en_rbus_data.regValue = 0x0;
	input_flt_en_rbus_data.input_flt_en = enable;
	vdcf_outl(VD_IFD_INPUT_108_input_flt_en_reg, input_flt_en_rbus_data.regValue);

}

void drv_module_vdc_adc_clk_sel(VD_IFD_CLK_RATE clk_rate, VD_IFD_INPUT_DN_FILTER input_dn_filter)
{
	//fein_input_filter_set_RBUS input_filter_set_data;
	vd_ifd_input_input_filter_set_RBUS input_filter_set_data;//sunray
	//input_filter_set_data.regValue = vdcf_inl(FEIN_INPUT_FILTER_SET_reg);
	input_filter_set_data.regValue = vdcf_inl(VD_IFD_INPUT_input_filter_set_reg);//sunray

	switch (clk_rate) {
	case VD_IFD_CLK_RATE_108M:
		input_filter_set_data.adc_clk_sel = 1;
		input_filter_set_data.input_dn_filter_sel = input_dn_filter;
		break;
	case VD_IFD_CLK_RATE_54M:
		input_filter_set_data.adc_clk_sel = 0;
		input_filter_set_data.input_dn_filter_sel = 0;
		break;
	case VD_IFD_CLK_RATE_135M:
		input_filter_set_data.adc_clk_sel = 2;
		input_filter_set_data.input_dn_filter_sel = (0x1 << 1 | input_dn_filter);
		break;
	case VD_IFD_CLK_RATE_162M:
		input_filter_set_data.adc_clk_sel = 3;
		input_filter_set_data.input_dn_filter_sel = (0x1 << 2 | input_dn_filter);
		break;
	default:
		break;
	}

	//vdcf_outl(FEIN_INPUT_FILTER_SET_reg, input_filter_set_data.regValue);
	vdcf_outl(VD_IFD_INPUT_input_filter_set_reg, input_filter_set_data.regValue);//sunray
}

void drvif_module_vdc_for_demod_external(unsigned char ucInputSrc, VDC_INITIAL_OPTIONS  * ptOptions)
{
	module_vdc_PathSelect(ucInputSrc, ptOptions->path);

	drvif_module_vdc_FIFO_CLK_setting();
	module_vdc_BlueScreenEnable(BLUE_SCREEN_DISABLE);
	drvif_module_vdc_set_noSignalCounter_Value(0x03);	/* speed up no-signal status */

	module_vdc_Set_clamp_delay(_DISABLE, 0xae);

#ifdef CONFIG_ENABLE_VDC_SUPPORT_SERRATION_SYNC_TYPE
	drvif_module_vdc_hsync_rising_start(0x28);
	drvif_module_vdc_hsync_rising_end(0x50);
#endif

	//vdcf_outl(VDTOP_CHROMA_LOCK_CONFIG_reg, 0xbb);
}

unsigned char drvif_video_get_625_flag(void)
{
	vdtop_video_status_reg3_RBUS video_status_reg3_reg;
	unsigned char uc625_flag = 0xff;

	if (drvif_module_vdc_Read_Vstate() >= 1) {
#if	0//def _jj_change_lock_function
		uc625_flag = vdc_625flag;
#else
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);
		uc625_flag = video_status_reg3_reg.lines_625_detected;
#endif
	}

	return uc625_flag;
}

unsigned char drvif_video_get_pal_flag(void)
{
	vdtop_video_status_reg2_RBUS video_status_reg2_reg;
	vdtop_video_status_reg3_RBUS video_status_reg3_reg;
	unsigned char ucpal_flag = 0xff;

	if (drvif_module_vdc_Read_Vstate() >= 1) {

		video_status_reg2_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG2_reg);
		video_status_reg3_reg.regValue = vdcf_inl(VDTOP_VIDEO_STATUS_REG3_reg);

		ucpal_flag = video_status_reg2_reg.palor_flag | video_status_reg2_reg.palm_flag | video_status_reg3_reg.pal_detected;
	}
	return ucpal_flag;
}

#if VDC_Error_case7
void drv_module_vdc_hstate_vsync_error_init(void)
{
	vdtop_lock_count_RBUS vdtop_lock_count_reg;
	vdtop_h_loop_maxstate_RBUS vdtop_h_loop_maxstate_reg;

	vdtop_lock_count_reg.regValue =  vdcf_inl(VDTOP_LOCK_COUNT_reg);
	vdtop_lock_count_reg.hstate_vsync_error_num_thr = 0xa; //10 lines
	vdtop_lock_count_reg.hstate_vsync_error_start = 0x78; //(sign) detect start at  6 line in front of Vsync
	vdtop_lock_count_reg.hstate_vsync_error_end = 0x0F; // end at 16 line in back of Vsync
	vdcf_outl(VDTOP_LOCK_COUNT_reg, vdtop_lock_count_reg.regValue);

	vdtop_h_loop_maxstate_reg.regValue = vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg);
	vdtop_h_loop_maxstate_reg.hstate_vsync_error_noisy_en = 0x0; //disable this bit in order to avoid effecting the status of hstate error
	vdcf_outl(VDTOP_H_LOOP_MAXSTATE_reg, vdtop_h_loop_maxstate_reg.regValue);
}

unsigned int drvif_module_vdc_read_hstate_vsync_error_unbalance(void)
{
	// 9134[25]
	vdtop_h_loop_maxstate_RBUS vdtop_h_loop_maxstate_reg;

	vdtop_h_loop_maxstate_reg.regValue =  vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg);

	g_hstate_vsync_error_unbalance_status_cnt++;
	if (g_hstate_vsync_error_unbalance_status_cnt > 2) {
		g_hstate_vsync_error_unbalance_status_cnt = 2;
		return g_hstate_vsync_error_unbalance_status_result;
	}

	if (g_hstate_vsync_error_unbalance_status_cnt == 1) {
		vdtop_h_loop_maxstate_reg.hstate_vsync_error_unbalance_status = 1; // Wclr
		vdcf_outl(VDTOP_H_LOOP_MAXSTATE_reg, vdtop_h_loop_maxstate_reg.regValue);
		// need to delay us ?
	}

	vdtop_h_loop_maxstate_reg.regValue =  vdcf_inl(VDTOP_H_LOOP_MAXSTATE_reg);
	g_hstate_vsync_error_unbalance_status_result = vdtop_h_loop_maxstate_reg.hstate_vsync_error_unbalance_status;

	return g_hstate_vsync_error_unbalance_status_result;
}

unsigned short drvif_module_vdc_Hdetect_err_var_status(void)
{
	/* 912c[31:16] */
	vdtop_hdetect_err_var_status_RBUS vdtop_hdetect_err_var_status_reg;
	unsigned short Hdetect_error_var;

	g_Hdetect_error_cnt++;
	if (g_Hdetect_error_cnt > 8) {
		g_Hdetect_error_cnt = 8;
		return g_Hdetect_error_avg;
	}

	vdtop_hdetect_err_var_status_reg.regValue = vdcf_inl(VDTOP_HDETECT_ERR_VAR_STATUS_reg);
	Hdetect_error_var = vdtop_hdetect_err_var_status_reg.hdetect_error_var;
	g_Hdetect_error_avg = g_Hdetect_error_avg + Hdetect_error_var;
	if (Hdetect_error_var > g_Hdetect_error_var_status_max)
		g_Hdetect_error_var_status_max = Hdetect_error_var;

	if (g_Hdetect_error_cnt == 8) {
		g_Hdetect_error_avg = g_Hdetect_error_avg >> 3;
	}
	return g_Hdetect_error_avg;
}
#endif

#if VDC_Error_case8
void drvif_module_vdc_set_backporch_end(unsigned char end)
{
	vdtop_backporch_end_RBUS vdtop_backporch_end_reg;

	vdtop_backporch_end_reg.regValue = vdcf_inl(VDTOP_BACKPORCH_END_reg);
	vdtop_backporch_end_reg.backporch_end = (0xff & end);
	vdcf_outl(VDTOP_BACKPORCH_END_reg, vdtop_backporch_end_reg.regValue);
}
#endif


static unsigned char bias_freq_lsb_to_vdc_fsc(unsigned int lsb)
{
	struct {
		VDC_FSC_DETECT_REG type;
		unsigned int max;
		unsigned int min;
	} const tbl[] = {
		{ _FSC_0hz, F0_max, F0_min },
		{ _FSC_p1hz, Fp1_max, Fp1_min },
		{ _FSC_p2hz, Fp2_max, Fp2_min },
		{ _FSC_p3hz, Fp3_max, Fp3_min },
		{ _FSC_p4hz, Fp4_max, Fp4_min },
		{ _FSC_p5hz, Fp5_max, Fp5_min },
		{ _FSC_n1hz, Fn1_max, Fn1_min },
		{ _FSC_n2hz, Fn2_max, Fn2_min },
		{ _FSC_n3hz, Fn3_max, Fn3_min },
		{ _FSC_n4hz, Fn4_max, Fn4_min },
		{ _FSC_n5hz, Fn5_max, Fn5_min },
	};
	const int tbl_len = sizeof(tbl)/sizeof(tbl[0]);
	int i;

	for (i = 0; i < tbl_len; ++i) {
		if (lsb >= (unsigned int)tbl[i].min && lsb < (unsigned int)tbl[i].max)
		    return (unsigned char)tbl[i].type;
	}
	return (unsigned char)_FSC_overflow;
}

unsigned char dvrif_module_vdc_get_frequency_bias( unsigned int frm_num )
{
	static unsigned long long sum_cdto = 0;
	static unsigned long long sum_hdto = 0;
	unsigned int cdto = 0, hdto = 0;
	static unsigned int pre_cdto = 0;
	static unsigned int pre_hdto = 0;
	int counter = 0;
	int timeout = 30000;
	static unsigned char FSC_status = _FSC_overflow;
	extern unsigned short stopUpdateFrequencyOffset;

	if(!vdc_LockStatus)
		return FSC_status;//coverity id 16142
	if (drvif_module_vdc_ReadMode(VDC_DETECT) != VDC_MODE_PALI)
		return FSC_status;//coverity id 16142

	if( frm_num == 0 )
	{
		sum_cdto = 0;
		sum_hdto = 0;
		pre_cdto = 0;
		pre_hdto = 0;
	}

	while( counter < 128 && stopUpdateFrequencyOffset == 0)
	{
		cdto = drvif_module_vdc_Cdto_status(); // ideal value = 0x2a098acb
		hdto = drvif_module_vdc_Hdto_status(); // ideal value = 0x20000000
		if( cdto != pre_cdto && hdto != pre_hdto )
		{
			counter++;
			sum_cdto = sum_cdto + cdto;
			sum_hdto = sum_hdto + hdto;
			pre_cdto = cdto;
			pre_hdto = hdto;
		}
		timeout--;

		if( timeout <= 0 )
		{
			printk( "[scalerVideo] %s TIMEOUT\n", __func__ );
			break;
		}
	}
	//printk( "[scalerVideo] timeout left = %d\n", timeout );

	if (stopUpdateFrequencyOffset != 0) {
		stopUpdateFrequencyOffset--;
		return FSC_status;
	}

	if( frm_num == 7 )
	{

		unsigned long long DiffResult = 0;
		unsigned long long TmpHDTO = (sum_hdto*1135);
		unsigned long long TmpCDTO = (sum_cdto*864);
		unsigned int MSB_Result;
		unsigned int LSB_Result ;

		if( TmpHDTO > TmpCDTO )
			DiffResult = TmpHDTO - TmpCDTO;
		else
			DiffResult = TmpCDTO - TmpHDTO;

		MSB_Result = ( DiffResult >> 32 );
		LSB_Result = ( DiffResult & 0xffffffff );
		//unsigned int temp = IoReg_Read32(0xb80003A0);

		if (MSB_Result == 0)
			FSC_status = bias_freq_lsb_to_vdc_fsc(LSB_Result);
		else
			FSC_status = _FSC_overflow;
	}

	return FSC_status;

}

bool drvif_module_vdc_GetLockStatus(void)
{
	return vdc_LockStatus;
}

void drvif_module_vdc_ResetLockStatus(void)
{
	vdc_LockStatus = false;
}

bool drvif_module_vdc_GetChromaLockStatus(void)
{
	return vdc_ChromaLockStatus;
}

void drvif_module_vdc_ResetChromaLockStatus(void)
{
	vdc_ChromaLockStatus = false;
}

bool drvif_module_vdc_GetBurstLockStatus(void)
{
	return vdc_BurstLockStatus;
}

bool drvif_module_vdc_Get625flag(void)
{
	return vdc_625flag;
}

unsigned char drvif_module_GetNoiseStatus(void)
{
	return vdc_NoiseStatus;
}

#ifdef CONFIG_SCART_ENABLE
void drvif_module_vdc_SetSCARTType(unsigned char type)
{
	SCART_Type = type;
}
#endif

#ifdef scart_vdc_auto_balance_en
void drvif_module_vdc_SetADCGainOffset(const vdc_ADCGainOffset offset)
{
	g_scart_ADCGainOffset = offset;
}

vdc_ADCGainOffset drvif_module_vdc_GetADCGainOffset(void)
{
	return g_scart_ADCGainOffset;
}

void drvif_module_vdc_SetSCARTVDBrConSat(const VDBrConSat sat)
{
	g_scart_VDBrConSat = sat;
}

VDBrConSat drvif_module_vdc_GetSCARTVDBrConSat(void)
{
	return g_scart_VDBrConSat;
}
#endif

#ifdef scart_vdc_auto_balance_en
/* bypass the output of YUV */
void drvif_module_vdc_scart_rgb_output_disable(void)
{
	vdtop_adc_gain_r1_RBUS vdtop_adc_gain_r1_reg;
	vdtop_adc_gain_r1_reg.regValue = vdcf_inl(VDTOP_ADC_GAIN_R1_reg);
	vdtop_adc_gain_r1_reg.rgb_output_en = 0x0;
	vdcf_outl(VDTOP_ADC_GAIN_R1_reg, vdtop_adc_gain_r1_reg.regValue);
}

/* bypass the output of RGB in order to measure the value of peak in the smartfit */
void drvif_module_vdc_scart_rgb_output_enable(void)
{
	vdtop_adc_gain_r1_RBUS vdtop_adc_gain_r1_reg;
	vdtop_adc_gain_r1_reg.regValue = vdcf_inl(VDTOP_ADC_GAIN_R1_reg);
	vdtop_adc_gain_r1_reg.rgb_output_en = 0x1;
	vdcf_outl(VDTOP_ADC_GAIN_R1_reg, vdtop_adc_gain_r1_reg.regValue);
}

void drvif_module_vdc_scart_auto_setadcgainoffset(void)
{
	drvif_module_vdc_Set_scart_gain();
#if 0 /* becasue algorithm don't tune the offset, we don't use it */
	drvif_module_vdc_Set_scart_offset();
#endif
}

void drvif_module_vdc_Set_scart_gain(void)
{
	vdc_ADCGainOffset *ptADCGainOffset = NULL;

	ptADCGainOffset = &g_scart_ADCGainOffset;

	drvif_module_vdc_Set_scart_gain_offset(_SCART_GAIN_R, ptADCGainOffset->Gain_R);
	drvif_module_vdc_Set_scart_gain_offset(_SCART_GAIN_G, ptADCGainOffset->Gain_G);
	drvif_module_vdc_Set_scart_gain_offset(_SCART_GAIN_B, ptADCGainOffset->Gain_B);
}

void drvif_module_vdc_Set_scart_offset(void)
{
	vdc_ADCGainOffset *ptADCGainOffset = NULL;

	ptADCGainOffset = &g_scart_ADCGainOffset;

	drvif_module_vdc_Set_scart_gain_offset(_SCART_OFFSET_R, ptADCGainOffset->Offset_R);
	drvif_module_vdc_Set_scart_gain_offset(_SCART_OFFSET_G, ptADCGainOffset->Offset_G);
	drvif_module_vdc_Set_scart_gain_offset(_SCART_OFFSET_B, ptADCGainOffset->Offset_B);
}

void drvif_module_vdc_Set_scart_gain_offset(SCACT_RGB_GAIN_OFFSET_TYPE addr, unsigned short parameter)
{
	vdtop_adc_gain_r_RBUS vdtop_adc_gain_r_reg;
	vdtop_adc_gain_g_RBUS vdtop_adc_gain_g_reg;
	vdtop_adc_gain_b_RBUS vdtop_adc_gain_b_reg;
	vdtop_adc_offset_r_RBUS vdtop_adc_offset_r_reg;
	vdtop_adc_offset_g_RBUS vdtop_adc_offset_g_reg;
	vdtop_adc_offset_b_RBUS vdtop_adc_offset_b_reg;

	switch (addr) {
	case _SCART_GAIN_R:
		vdtop_adc_gain_r_reg.regValue = vdcf_inl(VDTOP_ADC_GAIN_R_reg);/* 9660 */
		vdtop_adc_gain_r_reg.gain_r = (0x3ff & parameter); /* only 10-bits */
		vdcf_outl(VDTOP_ADC_GAIN_R_reg, vdtop_adc_gain_r_reg.regValue);
		break;
	case _SCART_GAIN_G:
		vdtop_adc_gain_g_reg.regValue = vdcf_inl(VDTOP_ADC_GAIN_G_reg);/* 9664 */
		vdtop_adc_gain_g_reg.gain_g = (0x3ff & parameter); /* only 10-bits */
		vdcf_outl(VDTOP_ADC_GAIN_G_reg, vdtop_adc_gain_g_reg.regValue);
		break;
	case _SCART_GAIN_B:
		vdtop_adc_gain_b_reg.regValue = vdcf_inl(VDTOP_ADC_GAIN_B_reg);/* 9668 */
		vdtop_adc_gain_b_reg.gain_b = (0x3ff & parameter); /* only 10-bits */
		vdcf_outl(VDTOP_ADC_GAIN_B_reg, vdtop_adc_gain_b_reg.regValue);
		break;
	case _SCART_OFFSET_R:
		vdtop_adc_offset_r_reg.regValue = vdcf_inl(VDTOP_ADC_OFFSET_R_reg);/* 966c */
		vdtop_adc_offset_r_reg.offset_r = (0xff & parameter); /* only 8-bits */
		vdcf_outl(VDTOP_ADC_GAIN_B_reg, vdtop_adc_offset_r_reg.regValue);
		break;
	case _SCART_OFFSET_G:
		vdtop_adc_offset_g_reg.regValue = vdcf_inl(VDTOP_ADC_OFFSET_G_reg);/* 9670 */
		vdtop_adc_offset_g_reg.offset_g = (0xff & parameter); /* only 8-bits */
		vdcf_outl(VDTOP_ADC_OFFSET_G_reg, vdtop_adc_offset_g_reg.regValue);
		break;
	case _SCART_OFFSET_B:
		vdtop_adc_offset_b_reg.regValue = vdcf_inl(VDTOP_ADC_OFFSET_B_reg);/* 9674 */
		vdtop_adc_offset_b_reg.offset_b = (0xff & parameter); /* only 8-bits */
		vdcf_outl(VDTOP_ADC_OFFSET_B_reg, vdtop_adc_offset_b_reg.regValue);
		break;
	}
}

void drvif_module_vdc_Set_scart_Brightness_Saturation(void)
{
	VDBrConSat *ptVDBrConSat = NULL;

	ptVDBrConSat = &g_scart_VDBrConSat;

	drvif_module_vdc_Set_scart_brightness_saturation(_SCART_Brightness2, ptVDBrConSat->Brightness2);
	drvif_module_vdc_Set_scart_brightness_saturation(_SCART_Contrast2, ptVDBrConSat->Contrast2);
	drvif_module_vdc_Set_scart_brightness_saturation(_SCART_Cb_saturation, ptVDBrConSat->Cb_saturation);
	drvif_module_vdc_Set_scart_brightness_saturation(_SCART_Cr_saturation, ptVDBrConSat->Cr_saturation);
}

void drvif_module_vdc_Set_scart_brightness_saturation(SCACT_RGB_GAIN_OFFSET_TYPE addr, unsigned short parameter)
{
	vdtop_luma_contrast2_adj_RBUS vdtop_luma_contrast2_adj_reg;
	vdtop_luma_brightness2_adj_RBUS vdtop_luma_brightness2_adj_reg;
	vdtop_chroma_saturation2_adj_RBUS vdtop_chroma_saturation2_adj_reg;
	vdtop_cb_sat_adj_RBUS vdtop_cb_sat_adj_reg;

	switch (addr) {
	case _SCART_Contrast2:
		vdtop_luma_contrast2_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_CONTRAST2_ADJ_reg); /* 9628 */
		vdtop_luma_contrast2_adj_reg.contrast2 = (0xff & parameter);
		vdcf_outl(VDTOP_LUMA_CONTRAST2_ADJ_reg, vdtop_luma_contrast2_adj_reg.regValue);
		break;
	case _SCART_Brightness2:
		vdtop_luma_brightness2_adj_reg.regValue = vdcf_inl(VDTOP_LUMA_BRIGHTNESS2_ADJ_reg);/* 962c */
		vdtop_luma_brightness2_adj_reg.brightness2 = (0xff & parameter);
		vdcf_outl(VDTOP_LUMA_BRIGHTNESS2_ADJ_reg, vdtop_luma_brightness2_adj_reg.regValue);
		break;
	case _SCART_Cb_saturation:
		vdtop_cb_sat_adj_reg.regValue = vdcf_inl(VDTOP_CB_SAT_ADJ_reg);/* 9634 */
		vdtop_cb_sat_adj_reg.cb_saturation = (0xff & parameter);
		vdcf_outl(VDTOP_CB_SAT_ADJ_reg, vdtop_cb_sat_adj_reg.regValue);
		break;
	case _SCART_Cr_saturation:
		vdtop_chroma_saturation2_adj_reg.regValue = vdcf_inl(VDTOP_CHROMA_SATURATION2_ADJ_reg);/* 9630 */
		vdtop_chroma_saturation2_adj_reg.cr_saturation = (0xff & parameter);
		vdcf_outl(VDTOP_CHROMA_SATURATION2_ADJ_reg, vdtop_chroma_saturation2_adj_reg.regValue);
		break;
	}
}
#endif /* scart_vdc_auto_balance_en */

void drvif_module_DMA_CHK3D_ENABLE_control(VDC_DMA_CHK3D_ENABLE_MODE value)
{
	VDC_DMA_CHK3D_TABLE DMA_CHK3D_TABLE;

	if(value == VDC_CHANEL_DISPLAY_MODE) {
		DMA_CHK3D_TABLE.chk_3d_sel = 0x3;
		DMA_CHK3D_TABLE.open_3d_cnt = 0x8;
		DMA_CHK3D_TABLE.close_3d_cnt = 0x8;
		DMA_CHK3D_TABLE.dma_3d_on_vcnt = 0xf;

	} else {
		DMA_CHK3D_TABLE.chk_3d_sel = 0x3;
		DMA_CHK3D_TABLE.open_3d_cnt = 0x3;
		DMA_CHK3D_TABLE.close_3d_cnt = 0x2;
		DMA_CHK3D_TABLE.dma_3d_on_vcnt = 0x2;
	}

	drvif_module_vpq_FRAME_BUF_CHK3D_control(DMA_CHK3D_TABLE.chk_3d_sel, DMA_CHK3D_TABLE.open_3d_cnt, DMA_CHK3D_TABLE.close_3d_cnt);
	drvif_module_vpq_DMA_CHK3D_VCNT_control(DMA_CHK3D_TABLE.dma_3d_on_vcnt);
}

void module_vdc_SECAM_notch_filter_sel(VDC_SECAM_Notch_Filter_MODE mode)
{	// 9700[1:0]
	vdtop_secam_ctrl_RBUS secam_ctrl_reg;
	secam_ctrl_reg.regValue = vdcf_inl(VDTOP_SECAM_CTRL_reg);
	secam_ctrl_reg.secam_notch_filter = mode;
	vdcf_outl(VDTOP_SECAM_CTRL_reg, secam_ctrl_reg.regValue);
}

void module_vdc_Clear_SECAM_Setting(void)
{	// SECAM notch filter sel to VDC_SECAM_FIR
	vdtop_y_gain_table_ctrl_RBUS y_gain_table_ctrl_reg;
	y_gain_table_ctrl_reg.regValue = vdcf_inl(VDTOP_Y_GAIN_TABLE_CTRL_reg);
	y_gain_table_ctrl_reg.secam_gain_y_en = 0;
	y_gain_table_ctrl_reg.secam_gain_y = 0x08;
	vdcf_outl(VDTOP_Y_GAIN_TABLE_CTRL_reg,y_gain_table_ctrl_reg.regValue);
	module_vdc_SECAM_notch_filter_sel(VDC_SECAM_FIR);
	drvif_module_vdc_SECAM_Drdb_vlpf_en(_DISABLE);
	//drvif_module_vdc_SECAM_ColorReduction(_DISABLE); // Merlin jyyang 20150617, removed by willy 20160921
}

void module_vdc_Set_SECAM_Setting(void)
{	// SECAM notch filter sel to VDC_SECAM_FIR
	vdtop_y_gain_table_ctrl_RBUS y_gain_table_ctrl_reg;
	y_gain_table_ctrl_reg.regValue = vdcf_inl(VDTOP_Y_GAIN_TABLE_CTRL_reg);
	y_gain_table_ctrl_reg.secam_gain_y_en = 0;
	y_gain_table_ctrl_reg.secam_gain_y = 0x00;
	vdcf_outl(VDTOP_Y_GAIN_TABLE_CTRL_reg,y_gain_table_ctrl_reg.regValue);
	drvif_module_vdc_SECAM_Drdb_vlpf_en(_ENABLE);
	//drvif_module_vdc_SECAM_ColorReduction(_DISABLE); // Merlin jyyang disable for bug 20150819, removed by willy 20160921
}

void module_vdc_Hactive_Start(Hactive_Mode a_ucHactiveMode,unsigned int a_uiHactiveStart)
{
	/*1_94B4[7]*/
	if (HwMode  == a_ucHactiveMode)
	{
		vdtop_vd_basic_register_enable_RBUS vd_basic_register_reg; 
		vd_basic_register_reg.regValue = vdcf_inl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg);
		vd_basic_register_reg.hactivestartreg_en= 0;
		vdcf_outl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg, vd_basic_register_reg.regValue);
	}
	else
	{
		vdtop_vd_basic_register_enable_RBUS vd_basic_register_reg; 
		vd_basic_register_reg.regValue = vdcf_inl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg);
		vd_basic_register_reg.hactivestartreg_en= 1;
		vdcf_outl(VDTOP_VD_BASIC_REGISTER_ENABLE_reg, vd_basic_register_reg.regValue);
	}

	if (a_uiHactiveStart > 0xff) 
	{
		rtd_printk(KERN_INFO, TAG_NAME_VDC, "a_uiHactiveStart > 0xff\n");
		a_uiHactiveStart = 0xff;
	}
	
	/*1_9208[7:0]*/
	vdtop_hactive_start_RBUS hactive_start_reg; 
	hactive_start_reg.regValue = vdcf_inl(VDTOP_HACTIVE_START_reg);
	hactive_start_reg.hactive_start= a_uiHactiveStart;
	vdcf_outl(VDTOP_HACTIVE_START_reg, hactive_start_reg.regValue);
}

unsigned char drvif_module_vdc_YC1D_Check(void)
{
	unsigned char SV_set = 0;
  	unsigned char ucFhStatus = 0;
	//unsigned char ucStatusBackup = 0;
  	unsigned char ucCkillStatus = 0;
 	unsigned char SCART_set = 0;

#ifdef CONFIG_FIRMWARE_IN_KERNEL//CHECK_CKILL_BURST_STATUS_ENABLE
	unsigned char ucChromaStatus = 0;
	unsigned char ucBurstDetect = 0;
#endif
	SV_set = (drvif_video_control_reg(VDC_cv_src)|drvif_video_control_reg(VDC_yc_src));
	#ifdef _jj_change_lock_function
		ucChromaStatus = vdc_ChromaLockStatus;
		ucBurstDetect = vdc_BurstLockStatus;
	#else
		ucChromaStatus = drvif_video_status_reg(VDC_chomalock);
		ucBurstDetect = drvif_video_status_reg(VDC_Burst_detect);
	#endif
	ucFhStatus = module_vdc_FhAdjust();
	ucCkillStatus = drvif_module_vdc_CKill_status();
	SCART_set = vdcf_inl(VDTOP_FSW_CTRL2_reg)&_BIT7;    // is SCART in

#if CONFIG_FIRMWARE_IN_KERNEL
	#if 1	//jj_test_flow_b
		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucFhStatus == ON)||(!ucChromaStatus)|| (ucCkillStatus)||(!ucBurstDetect))
	#else
//		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucFhStatus == ON))
		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucChromaStatus == 0x00)||(ucFhStatus == ON)||(ucCkillStatus))
//		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucChromaStatus == 0x00)||(ucBurstDetect == 0x00)||(ucFhStatus == ON))
//		if((SV_set != 0x00)||(ucChromaStatus == 0x00)||(ucBurstDetect == 0x00)||(ucFhStatus == ON))
//		if((SV_set != 0x00)||(ucChromaStatus == 0x00)||(ucFhStatus == ON))	//shangmeng_xu mark ucburstdetect because don't need.2012_07_10
//		if((SV_set != 0x00)||(ucChromaStatus == 0x00)||(ucFhStatus == ON)||(ucCkillStatus)) // add ckill status set to 1D
	#endif
#else
	#ifdef CHECK_CKILL_BURST_STATUS_ENABLE
		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucFhStatus == ON)||(ucCkillStatus)||(!ucBurstDetect)||(!ucChromaStatus))
	#else
		if((SV_set != 0x00)||(SCART_set != 0x00)||(ucFhStatus == ON)||(ucCkillStatus))
	#endif
#endif
		{
			return TRUE;
		} else {
			return FALSE;
		}

}

/**
   module_vdc_FhAdjust

   For  H /V frequency offset adjust +- 6%, please
   call this function every 20mSec

   @param <ucInputSrc>  { Input source }
   @return  <void>      { void }

*/
unsigned char module_vdc_FhAdjust(void)
{
	static UINT8 ucFhBug_Counter = 5;
	unsigned char VD_mode, noise_status;
	unsigned int vd_hdto,  vd_cdto, Temp_diff, vd_temp_diff_max, vd_temp_diff_min;
	vdpq_yc_post2dbpf_ctrl_RBUS YC_Post2DBPF_Ctrl;
	vdtop_hsync_pulse_start_RBUS HSYNC_PULSE_START;
#if 0 //fix me frank@0614 mark below code to speed up
	Temp_diff = drvif_video_status_reg(VDC_hv_lock);
	if(!Temp_diff)
	{
		pr_debug( "[Fh] h/v unlock return : %x\n",Temp_diff);
		return cvideo_fh_set_1d;
	}
#endif
	VD_mode = drvif_module_vdc_ReadMode(VDC_SET);
#ifdef _jj_change_lock_function
	noise_status = vdc_NoiseStatus;
#else
	noise_status = drvif_module_vdc_NoiseStatus();
#endif
	if((noise_status < 0x12)&&((VD_mode == VDC_MODE_NTSC)||(VD_mode == VDC_MODE_PALI)
		||(VD_mode == VDC_MODE_PALM)||(VD_mode == VDC_MODE_PALN)))
	{
		switch(VD_mode)
		{
			case VDC_MODE_NTSC:	// NTSC : 1f0782b
			default:
				vd_temp_diff_max = 0x020f6000;
				vd_temp_diff_min = 0x01d18000;
				break;
			case VDC_MODE_PALM:	// PAL_M : 1e6e7a9
				vd_temp_diff_max = 0x02062a00;
				vd_temp_diff_min = 0x01c79f00;
				break;
			case VDC_MODE_PALN:	// PAL_N : 1f689f9
				vd_temp_diff_max = 0x0210d000;
				vd_temp_diff_min = 0x01dd0000;
				break;
			case VDC_MODE_PALI:		// PAL_I : a096703
				vd_temp_diff_max = 0x0A208000;
				vd_temp_diff_min = 0x09F08EAC;
				break;
		}

		vd_hdto = drvif_module_vdc_Hdto_status();
		vd_cdto = drvif_module_vdc_Cdto_status();
		Temp_diff = vd_cdto - vd_hdto;
		if ( (Temp_diff<=vd_temp_diff_min) || (Temp_diff>=vd_temp_diff_max) )
		{
			ucFhBug_Counter++;
//			printk("[1]ucFhBug_Counter: %x\n", ucFhBug_Counter);
			if ( ucFhBug_Counter >= 3 )	// 10
			{
				ucFhBug_Counter = 2;	// 8
				if(cvideo_fh_set_1d != ON)
				{
					pr_debug("Fh 1D 1D 1D 1D 1D .....!\n");
					drvif_module_vdc_Swallow_on_Vsyng(_ENABLE);
					drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_ENABLE);	//enable Fast lock for color bar
//					drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_synctip);
					cvideo_fh_set_1d = ON;

					//vdpq_yc_post2dbpf_ctrl_RBUS YC_Post2DBPF_Ctrl;
					YC_Post2DBPF_Ctrl.regValue = vdcf_inl(VDPQ_YC_Post2DBPF_Ctrl_reg);
					YC_Post2DBPF_Ctrl.post2dbpf_c_en = 0;
					YC_Post2DBPF_Ctrl.post2dbpf_y_en = 0;
					vdcf_outl(VDPQ_YC_Post2DBPF_Ctrl_reg,YC_Post2DBPF_Ctrl.regValue);
					pr_debug( "Fh 3db0 = %x\n",YC_Post2DBPF_Ctrl.regValue);

					/* to compensate the delay when post2dbpf_y or post2dbpf_c is enabled  */
					//vdtop_hsync_pulse_start_RBUS HSYNC_PULSE_START;
					HSYNC_PULSE_START.regValue = vdcf_inl(VDTOP_HSYNC_PULSE_START_reg);
					if(HSYNC_PULSE_START.hsync_start != 0)
					{
						//HSYNC_PULSE_START.hsync_start = 0x16;	//20150630  jenniferchang mark
						vdcf_outl(VDTOP_HSYNC_PULSE_START_reg,HSYNC_PULSE_START.regValue);
					}
				}
			}
		}
		else
		{
			ucFhBug_Counter--;
//			printk("[2]ucFhBug_Counter: %x\n", ucFhBug_Counter);
			if ( ucFhBug_Counter == 0 )
			{
				ucFhBug_Counter = 1;	// 3
				if(cvideo_fh_set_1d != OFF)
				{
					pr_debug("Fh 3D~~~~~\n");
					drvif_module_vdc_Swallow_on_Vsyng(_DISABLE);
					drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_DISABLE);	//disable Fast lock
//					drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_auto);
					cvideo_fh_set_1d = OFF;
				}
			}
		}
	}
	else
	{
		if(cvideo_fh_set_1d != OFF)
		{
			pr_debug("Fh 3D~~~~~\n");
			drvif_module_vdc_Swallow_on_Vsyng(_DISABLE);
			drvif_module_vdc_Cstate_fast_locked(VDC_CSTATE_FastLock_DISABLE);	//disable Fast lock
//			drvif_module_vdc_set_Control2_Register(VDC_dc_clamp_mode_auto);
			cvideo_fh_set_1d = OFF;
		}
	}
	return cvideo_fh_set_1d;
}

void drvif_module_vdc_ResetCVideoFH1D(void)
{
	cvideo_fh_set_1d = OFF;
}

static int __init video_module_init(void)
{
	int ret;

	module_video_register_sb2_timeout_callback();

	ret = module_video_debug_init();
	if (ret < 0)
		return -EIO;

	return 0;
}

static void __exit video_module_exit(void)
{
	module_video_debug_exit();
	module_video_unregister_sb2_timeout_callback();
}

module_init(video_module_init);
module_exit(video_module_exit);
