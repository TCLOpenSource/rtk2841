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
 * @date 	$Date: 2017/03/16 14:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */

/*================ Module dependency  =============== */
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <mach/io.h>

//#include <rbus/rbusVDTopReg.h>
#include <rbus/vdtop_reg.h>//sunray
//#include <rbus/rbusVDPQReg.h>
#include <rbus/vdpq_reg.h>//sunray
//#include <rbus/rbusVDIFDinReg.h>
#include <rbus/vd_ifd_input_reg.h>//sunray
#include <rbus/adc_reg.h>
//#include <rbus/crt_reg.h>
#include <rbus/sys_reg_reg.h>//sunray
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/vdc/video_table.h>
#include <tvscalercontrol/vdc/video_input.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/scaler/modeState.h>
#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
//#include <rbus/rbusPinmuxReg.h>//sunray
#include <rbus/tv_sb1_ana_reg.h>
#include <tvscalercontrol/vdac/vdac.h>
//#include <mach/rtk_crt.h>
#include <rtk_kdriver/rtk_crt.h>//sunray
#include <mach/rtk_platform.h>

/*==================== Definitions ================ */
#define rtdf_outl(offset, val)		IoReg_Write32(offset,val)
#define rtdf_inl(offset)			IoReg_Read32(offset)

/*=================== Hardware semaphore =============== */
#define SB2_HD_SEM_NEW_5_reg 0xB801A634
extern char moduleName[32];

/*
#define SB2_HD_SEM_NEW_5_reg 0xB801A634
#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){printk("#@# %s wait SB2_HD_SEM_NEW_5_reg ready\n", moduleName); msleep(20);}
#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);
*/

//#define Get_HD_SEM_NEW_5() while(!IoReg_Read32(SB2_HD_SEM_NEW_5_reg)){;}
//#define Set_HD_SEM_NEW_5() IoReg_Write32(SB2_HD_SEM_NEW_5_reg, 0);


/*==================== Variables ================== */
#define AD_YorCVBS      0x0
#define AD_BorPb	          0x1
#define AD_CorRorPr      0x2
#define AD_G                 0x3
unsigned char ucVin = VIDEO_INPUT9;
unsigned char ucVgnd = VIDEO_GNDA0;
unsigned char ucDcRestoreStatus = OFF;

#ifdef scart_vdc_auto_balance_en
static vdc_ADCGainOffset *scart_m_stVGAGainOffset = NULL;
static vdc_ADCGainOffset *scart_m_stYPbPrGainOffsetData = NULL;
#endif


/* ==========  Input path setting functions  ============================= */
void module_vdc_ADC_common_setting(void)
{
	/* === jj check ok 20170316 === */
	adc_adc_ibias0123_RBUS adc_ibias0123_reg;		/* 2_0004 */
	adc_vd_adc_clamp_ctl_1_RBUS vd_adc_clamp_ctl_1_reg;	/* 2_0048 */
	adc_vd_adc_clamp_ctl_2_RBUS vd_adc_clamp_ctl_2_reg;	/* 2_004c */
	adc_vd_adc_updn_ctl_RBUS vd_adc_updn_ctl_reg;		/* 2_0050 */
	adc_vdadc_core_lpf_ctrl_RBUS vdadc_core_lpf_ctrl_rbus_reg;      /* 2_0054 */
	adc_vdadc_ck_ctl_RBUS vdadc_ck_ctl_reg;		/* 2_0058 */
	adc_vdadc_pow_ctl_RBUS vdadc_pow_ctl_reg;	/* 2_005c */
	vd_ifd_input_vd_in_delay_sel2_RBUS vd_in_delay_sel2_reg;	/* 1_80a4 */
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg; /* 90c4 */
	vdtop_pattern_control_RBUS pattern_control_reg;	/* 9794 */

	adc_ibias0123_reg.regValue = rtdf_inl(ADC_ADC_IBIAS0123_reg);
	adc_ibias0123_reg.adc_ibias1_6 = 0x1;
	rtdf_outl(ADC_ADC_IBIAS0123_reg, adc_ibias0123_reg.regValue);

	vd_adc_clamp_ctl_1_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_1_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[0] 2_0048=%x\n", vd_adc_clamp_ctl_1_reg.regValue);
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_15_14 = 0x0;	/* 2_0048[31:30]  V Channel Input- Select */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_13 = 0x0;		/* 2_0048[29] = 0 */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_11_10 = 0x2;	/* 2_0048[27:26] = 10, swap default */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_9_8 = 0;		/* 2_0048[25:24] = 00 */
//	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_7_4 = 0xe;		/* 2_0048[23:20] = 0xe, 1.28v */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_7_4 = ucAdcNeg_Sing;	/* 2_0048[23:20] */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_3_0 = 0x7;		/* 2_0048[19:16] = 0x7, default */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_15 = 0x1;		/* 2_0048[15] = 1, dc restore offset enable(+0.4V) */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_14_13 = 0x0;	/* 2_0048[14:13] = 0x0, dc restore enable */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_12 = 0x0;		/* 2_0048[12] = 0 */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_8 = 0x1;		/* 2_0048[8] = 1, diff. */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_6_5 = 0x0;		/* 2_0048[6:5] = 0x0, clamp en */
	vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_1_0 = 0x0;		/* 2_0048[1:0] = 0, dc restore */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_0048=%x\n", vd_adc_clamp_ctl_1_reg.regValue);
	rtdf_outl(ADC_VD_ADC_CLAMP_CTL_1_reg, vd_adc_clamp_ctl_1_reg.regValue);

	vd_adc_clamp_ctl_2_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_2_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[0] 2_004c=%x\n", vd_adc_clamp_ctl_2_reg.regValue);
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_14_12 = 0x0;	/* 2_004c[14:12] test mode */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_11 = 0x0;		/* 2_004c[11] default */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_10 = 0x0;		/* 2_004c[10] VIN9PP select */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_9_8 = 0x0;		/* 2_004c[9:8] VIN11PP select */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_7 = 0x0;		/* 2_004c[7] = 0, VDC Slelction */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_6 = 0x1;		/* 2_004c[6] = 1, clamp current */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_5 = 0x0;		/* 2_004c[5] = 0, yc swap disable */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_4_2 = 0x0;		/* 2_004c[4:2] Negative clamp enable */
	vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_1_0 = 0x0;		/* 2_004c[1:0] = 0, SF avout enable */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_004c=%x\n", vd_adc_clamp_ctl_2_reg.regValue);
	rtdf_outl(ADC_VD_ADC_CLAMP_CTL_2_reg, vd_adc_clamp_ctl_2_reg.regValue);

	vd_adc_updn_ctl_reg.regValue = rtdf_inl(ADC_VD_ADC_UPDN_CTL_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[0] 2_0050=%x\n", vd_adc_updn_ctl_reg.regValue);
	vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_15_14 = 0x0;	/* 2_0050[15:14]=00, ADC Gain Calibration */
	vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_13_11 = 0x0;	/* 2_0050[13:11]=000, default */
	vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_10_8 = 0x0;	/* 2_0050[10:8]=000, Negative UP/DN NCLAMP_EN Enable */
	vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_7_3 = 0x4;		/* 2_0050[7:3]=00100, clamp current */
	vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_1_0 = 0x1;		/* 2_0050[1:0]=01, AV clamp up/dn enable */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_0050=%x\n", vd_adc_updn_ctl_reg.regValue);
	rtdf_outl(ADC_VD_ADC_UPDN_CTL_reg, vd_adc_updn_ctl_reg.regValue);

	vdadc_pow_ctl_reg.regValue = rtdf_inl(ADC_VDADC_POW_CTL_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_005c=%x\n", vdadc_pow_ctl_reg.regValue);
	vdadc_pow_ctl_reg.vdadc_reserve = 0x4;		/* 2_005c[31:16]=4, default */
	vdadc_pow_ctl_reg.ldo100ma_pow = 0x1;		/* 2_005c[1]=1, LDO100MA_POW */
	vdadc_pow_ctl_reg.vdadc_pow = 0x1;		/* 2_005c[0]=1, power on */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_005c=%x\n", vdadc_pow_ctl_reg.regValue);
	rtdf_outl(ADC_VDADC_POW_CTL_reg, vdadc_pow_ctl_reg.regValue);
	
	vdadc_core_lpf_ctrl_rbus_reg.regValue = rtdf_inl(ADC_VDADC_CORE_LPF_CTRL_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[0] 2_0054=%x\n", vdadc_core_lpf_ctrl_rbus_reg.regValue);
	/*20170316 review OK*/
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_15_13 = 0x2;	/* 2_0054[31:29]=010 */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_12_10 = 0x2;	/* 2_0054[28:26]=010 */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_9_8 = 0x2;	/* 2_0054[25:24]=10 */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_7 = 0x0;		/* 2_0054[23:22]=01, 1.3V LDO Selection */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_6 = 0x1;		/*                            (01:1.30V) */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_5_3 = 0x1;	/* 2_0054[21:19]=001, 1V LDO Selection(001:0.95V) */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_2 = 0x1;		/* 2_0054[18]=0, power on */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_1 = 0x0;		/* 2_0054[17]=0 */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_adc_ctrl_0 = 0x1;		/* 2_0054[16]=1, default */
	vdadc_core_lpf_ctrl_rbus_reg.vdadc_lpf_ctrl_1_0 = 0x1;		/* 2_0054[1:0]=01, LPF 12.6MHz */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_0054=%x\n", vdadc_core_lpf_ctrl_rbus_reg.regValue);
	rtdf_outl(ADC_VDADC_CORE_LPF_CTRL_reg, vdadc_core_lpf_ctrl_rbus_reg.regValue);

	vdadc_ck_ctl_reg.regValue = rtdf_inl(ADC_VDADC_CK_CTL_reg);
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[0] 2_0058=%x\n", vdadc_ck_ctl_reg.regValue);
	vdadc_ck_ctl_reg.vdadc_ckin_sel_6 = 0x0;		/* 2_0058[14]=0, clock selection */
	vdadc_ck_ctl_reg.vdadc_ckin_sel_5 = 0x0;		/* 2_0058[13]=0, 54M clock polarity */
	vdadc_ck_ctl_reg.vdadc_ckin_sel_4_2 = 0x0;	/* 2_0058[12:10]=0x0 */
	vdadc_ck_ctl_reg.vdadc_ckout_sel_6 = 0x1;	/* 2_0058[6]=1, default */
	vdadc_ck_ctl_reg.vdadc_ckout_sel_4 = 0x0;	/* 2_0058[4]=0 */
	vdadc_ck_ctl_reg.vdadc_ckout_sel_3_2 = 0x0;	/* 2_0058[3:2]=00 */
	vdadc_ck_ctl_reg.vdadc_ckout_sel_1_0 = 0x0;	/* 2_0058[1:0]=00, the default should be X1 multiple */
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"[1] 2_0058=%x\n", vdadc_ck_ctl_reg.regValue);
	rtdf_outl(ADC_VDADC_CK_CTL_reg, vdadc_ck_ctl_reg.regValue);

	/* disable sv_yc_switch */
	vd_in_delay_sel2_reg.regValue = rtdf_inl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg);
	vd_in_delay_sel2_reg.sv_sel = 0x0;		/* 1_80a4[3:2] = 00 */
	vd_in_delay_sel2_reg.sv_yc_switch = 0x0;	/* 1_80a4[1] = 0 */
	vd_in_delay_sel2_reg.sv_in_one_adc = 0x0;	/* 1_80a4[0] = 0 */
	rtdf_outl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg, vd_in_delay_sel2_reg.regValue);

	charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
	charge_pump_delay_control_reg.auto_dc_restore_en1 = 0x0;	/* 90c4[13] = 0, enable dc-restore function */
	charge_pump_delay_control_reg.auto_dc_restore_en0 = 0x1;	/* 90c4[12] = 1, enable dc-restore function */
	vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);

	pattern_control_reg.regValue = vdcf_inl(VDTOP_PATTERN_CONTROL_reg);
	pattern_control_reg.pattern_generator_enable = 0x0;	/* 9794[0] = 0 */
	vdcf_outl(VDTOP_PATTERN_CONTROL_reg, pattern_control_reg.regValue);
}


/**
        module_vdc_SetADCPath
        ADC path set, no extern
        @param{ none }
        @return uchar

        Signal :
                VIDEO_INPUT0       0x0
                VIDEO_INPUT1       0x1
                VIDEO_INPUT2       0x2
                VIDEO_INPUT3       0x3
                VIDEO_INPUT4       0x4
                VIDEO_INPUT5       0x5
                VIDEO_INPUT6       0x6
                VIDEO_INPUT7       0x7
                VIDEO_INPUT8       0x8
                VIDEO_INPUT9       0x9
                VIDEO_INPUT10     0xa
                VIDEO_INPUT11     0xb
                VIDEO_INPUT12     0xc
                VIDEO_INPUT13     0xd
                VIDEO_INPUT14     0xe
        GND :
                VIDEO_GNDA0     0
                VIDEO_GNDA1     1
                VIDEO_GNDA2     2
                VIDEO_GNDR       3
                VIDEO_GNDG       4
                VIDEO_GNDB       5
                VIDEO_GNDY0     6
                VIDEO_GNDY1     7

        return 0 : B-ch
        return 1 : G-ch
        return 2 : R-ch
        return 3 : V-ch
*/
unsigned char module_vdc_SetADCPath(unsigned char path_signal, unsigned char path_gnd)
{
	unsigned char ucTemp, ucNClampUpDn;

	adc_adc_ctl_rgb12_RBUS adc_ctl_rgb12_reg;		/* 2_0008 */
	adc_adc_vbias_RBUS adc_adc_vbias_reg;		/* 2_000c */
	adc_vd_adc_clamp_ctl_1_RBUS vd_adc_clamp_ctl_1_reg;	/* 2_0048 */
	adc_vd_adc_clamp_ctl_2_RBUS vd_adc_clamp_ctl_2_reg;	/* 2_004c */
	adc_vd_adc_updn_ctl_RBUS vd_adc_updn_ctl_reg;		/* 2_0050 */

	adc_ctl_rgb12_reg.regValue = rtdf_inl(ADC_ADC_CTL_RGB12_reg);
	adc_adc_vbias_reg.regValue = rtdf_inl(ADC_ADC_VBIAS_reg);
	vd_adc_clamp_ctl_1_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_1_reg);
	vd_adc_clamp_ctl_2_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_2_reg);
	vd_adc_updn_ctl_reg.regValue = rtdf_inl(ADC_VD_ADC_UPDN_CTL_reg);

	ucNClampUpDn = vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_10_8;

	switch (path_signal) {
	/* V Channel Input+ : 1P,4P,7P  */
	/* 2_0008[11:10]=VD Channel Input+ Select VIN_VD_i(00:GND,01:VIN1P,10:VIN4P,11:VIN7P)*/
	case VIDEO_INPUT1:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0x2;	/* 2_0008[11:10]=01:VIN1P */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_7 = 0x0;		/* 2_0008[7]=0:G-ch in VIN1PP floating */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x3;	/* 2_0008[3:2]=11:X */
		goto _VIN_VD_i;
	case VIDEO_INPUT4:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0x2;	/* 2_0008[11:10]=10:VIN4P */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_8 = 0x0;		/* 2_0008[8]=0:G-ch in VIN4P floating */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x3;	/* 2_0008[3:2]=11:X */
		goto _VIN_VD_i;
	case VIDEO_INPUT7:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0x3;	/* 2_0008[11:10]=11:VIN7P */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_9 = 0x0;		/* 2_0008[9]=0:R-ch in VIN7PP floating */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x3;	/* 2_0008[3:2]=11:X */
		goto _VIN_VD_i;
_VIN_VD_i:
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_10_9 = 0x0;	/* 2_0048[10:9]=00, VIN9PP[VIN_VD_i] */
//		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_10 = 0x1;	/* 2_004c[10]=1, VIN13P */
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_9_8 = 0x1;	/* 2_004c[9:8]=01, VIN1P/4P/7P */
		goto _V_Ch_Set;

	case VIDEO_INPUT9:
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_10_9 = 0x0;	/* 2_0048[10:9]=00, VIN9PP[VIN_VD_i] */
//		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_10 = 0x0;	/* 2_004c[10]=0, VIN9P */
		goto _V_Ch_Set;

	case VIDEO_INPUT10:
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_10_9 = 0x1;	/* 2_0048[10:9]=01, VIN10P */
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_9_8 = 0x2;	/* 2_004c[9:8]=10, VIN10P */
		goto _V_Ch_Set;
	/* Passive MUX : VIN11PP=12P, 13P */
	default:
	case VIDEO_INPUT12:
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_9_8 = 0x0;	/* 2_004c[9:8]=00, VIN12P */
		goto _VIN11PP_set;
	case VIDEO_INPUT13:
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_9_8 = 0x3;	/* 2_004c[9:8]=11, VIN13P */
		goto _VIN11PP_set;

_VIN11PP_set:
		vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl1_10_9 = 0x2;	/* 2_0048[10:9]=10, VIN11P */
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_10 = 0x1;	/* 2_004c[10] VIN9PP select */
		goto _V_Ch_Set;

_V_Ch_Set:		/* GND set */
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[Set V channel] %x\n", path_signal);
		switch (path_gnd) {
		default:
		case VIDEO_GNDA0:
			vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_15_14 = 0x0;		/* 2_0048[31:30] = 00, A0N */
			vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_10_8 = (ucNClampUpDn | _BIT0);	/* 2_0050[8]=1 */
			break;
		case VIDEO_GNDA1:	/* A1N from YPP */
			adc_adc_vbias_reg.adc_vbias1_5_4 = 0x2;		/* 2_000c[13:12] = 10, VINN mux to D */
			vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_15_14 = 0x1;	/* 2_0048[31:30] = 01, A1N from YPP */
			vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_10_8 = (ucNClampUpDn | _BIT1);	/* 2_0050[9]=1 */
			break;
		case VIDEO_GNDA2:
			vd_adc_clamp_ctl_1_reg.vdadc_clamp_ctrl0_15_14 = 0x2;	/* 2_0048[31:30] = 10, A2N */
			vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_10_8 = (ucNClampUpDn | _BIT2);	/* 2_0050[10]=1 */
			break;
		}
		ucTemp = 3;
		break;
	}

	rtdf_outl(ADC_ADC_CTL_RGB12_reg, adc_ctl_rgb12_reg.regValue);	/* 2_0008 */
	rtdf_outl(ADC_VD_ADC_CLAMP_CTL_1_reg, vd_adc_clamp_ctl_1_reg.regValue);	/* 2_0048 */
	rtdf_outl(ADC_VD_ADC_CLAMP_CTL_2_reg, vd_adc_clamp_ctl_2_reg.regValue);	/* 2_004c */
	rtdf_outl(ADC_VD_ADC_UPDN_CTL_reg, vd_adc_updn_ctl_reg.regValue);		/* 2_0050 */
	return ucTemp;	/* return ADC number */
}

unsigned char module_vdc_SetRGBADCPath(unsigned char path_signal, unsigned char path_gnd)
{
	unsigned char ucTemp = 0x0;

	adc_adc_ctl_rgb12_RBUS adc_ctl_rgb12_reg;		/* 2_0008 */
	adc_adc_clock_RBUS adc_clock_reg;			/* 2_0010 */
	adc_adc_dcrestore_ctrl_RBUS adc_dcrestore_ctrl_reg;	/* 2_0018 */
	adc_adc_clamp_ctrl0_RBUS adc_clamp_ctrl0_reg;		/* 2_001c */
	adc_adc_clamp_ctrl1_RBUS adc_clamp_ctrl1_reg;		/* 2_0020 */
	adc_adc_clamp_ctrl2_RBUS adc_clamp_ctrl2_reg;		/* 2_0024 */
	adc_adc_gain0_RBUS adc_gain0_reg;		/* 2_0030 */
	adc_adc_gain1_RBUS adc_gain1_reg;		/* 2_0034 */
	adc_adc_offset0_RBUS adc_offset0_reg;		/* 2_0038 */
	adc_adc_offset1_RBUS adc_offset1_reg;		/* 2_003c */
	adc_ctl_rgb12_reg.regValue = rtdf_inl(ADC_ADC_CTL_RGB12_reg);
	adc_clock_reg.regValue = rtdf_inl(ADC_ADC_CLOCK_reg);
	adc_dcrestore_ctrl_reg.regValue = rtdf_inl(ADC_ADC_DCRESTORE_CTRL_reg);
	adc_clamp_ctrl0_reg.regValue = rtdf_inl(ADC_ADC_CLAMP_CTRL0_reg);
	adc_clamp_ctrl1_reg.regValue = rtdf_inl(ADC_ADC_CLAMP_CTRL1_reg);
	adc_clamp_ctrl2_reg.regValue = rtdf_inl(ADC_ADC_CLAMP_CTRL2_reg);
	adc_gain0_reg.regValue = rtdf_inl(ADC_ADC_GAIN0_reg);
	adc_gain1_reg.regValue = rtdf_inl(ADC_ADC_GAIN1_reg);
	adc_offset0_reg.regValue = rtdf_inl(ADC_ADC_OFFSET0_reg);
	adc_offset1_reg.regValue = rtdf_inl(ADC_ADC_OFFSET1_reg);

	adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0x0;	/* 2_0008[11:10]=00, VIN_VD_i=GND */
	adc_clock_reg.adc_clock_10 = 0x1;		/* 2_0010[10] = 1 : Select clk from VDC: PLL27X */
	adc_clock_reg.adc_clock_1_0 = 0x2;		/* 2_0010[1:0] = 10 : Duty cycle 51% */
	adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 0x1;	/* 2_0018[20]=1, diff */
	adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = 0x00;	/* 2_0018[19:16]=0000, LPF Bandwidth 10M */

	switch (path_signal) {
/* ==========  B channel setting ===================================== */
	/* enable B channel VDC UP/DN select (00: VIN0P, 01: VIN3P, 10: VIN6PP, 11: X) */
	/* enable Nclamp up/dn GND set, VIN0,1,2 = RGB GND, VIN3,4,5 = Y0N, VIN6,7,8 = Y1N */
	case VIDEO_INPUT0:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 0x0;		/* 2_0008[1:0]=00, VIN0P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0x0;	/* 2_0024[1:0]=00, VIN0P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 0x0;	/* 2_001c[1:0]=00, VINBN */
		goto _B_Ch_Set;
	case VIDEO_INPUT3:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 0x1;		/* 2_0008[1:0]=01, VIN3P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0x1;	/* 2_0024[1:0]=01, VIN3P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 0x1;	/* 2_001c[1:0]=01, VINY0N */
		goto _B_Ch_Set;
	case VIDEO_INPUT6:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 0x2;		/* 2_0008[1:0]=10, VIN6P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0x2;	/* 2_0024[1:0]=10, VIN6P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 0x2;	/* 2_001c[1:0]=10, VINY1N */

_B_Ch_Set:
		adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 0x3;	/* 2_0008[17:16]=11, B-:X */
		/* 2_0018[2][1:0] B ch dc restore disable */
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0x0;
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0x3;
		/* 2_001c[21][20:19] B ch negative clamp disable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0x0;
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0x3;
		/* 2_0020[2][1:0] B ch voltage clamp disable */
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0x0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0x3;

		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0x1;	/* 2_001c[2] B ch Negative up/dn Enable */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 0x1;	/* 2_0024[2] B ch VDC UP/DN enable */

		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0x0;	/* 2_001c[16] B ch no swap */
		adc_gain1_reg.adc_gain_blu = 0x180;		/* 2_0034[8:0] Green Channel Gain Adjust */
		adc_offset1_reg.adc_off_blu = 0x1c0;		/* 2_003c[9:0] Blue Channel Offset Adjust */
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[Set Blue channel] %x\n", path_signal);
		ucTemp = 0x0;
		break;
/* ==========  G channel setting ===================================== */
	/* enable G channel VDC UP/DN select (00: VIN1P, 01: VIN4P, 10: VIN7PP, 11: X) */
	/* enable Nclamp up/dn GND set, VIN0,1,2 = RGB GND, VIN3,4,5 = Y0N, VIN6,7,8 = Y1N */
	case VIDEO_INPUT1:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x0;		/* 2_0008[3:2]=00, VIN1P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0x0;	/* 2_0024[4:3]=00, VIN1P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 0x0;	/* 2_001c[4:3]=00, VINGN */
		goto _G_Ch_Set;
	case VIDEO_INPUT4:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_7 = 0x1;		/* 2_0008[7]=1, G ch in VIN4PP */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x1;	/* 2_0008[3:2]=01, VIN4P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0x1;	/* 2_0024[4:3]=01, VIN4P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 0x1;	/* 2_001c[4:3]=00, VINY0N */
		goto _G_Ch_Set;
	case VIDEO_INPUT7:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_8 = 0x1;		/* 2_0008[8]=1, G ch in VIN7PP */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 0x2;		/* 2_0008[3:2]=10, VIN7P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0x2;	/* 2_0024[4:3]=10, VIN7P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 0x2;	/* 2_001c[4:3]=00, VINY1N */

_G_Ch_Set:
		adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 0x3;	/* 2_0008[19:18]=11, G-:X */
		/* 2_0018[5][4:3] G ch dc restore disable */
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0x0;
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0x3;
		/* 2_001c[24][23:22] G ch negative clamp disable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 0x0;
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 0x3;
		/* 2_0020[5][4:3] G ch voltage clamp disable */
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0x0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0x3;

		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0x1;	/* 2_001c[5] G ch Negative up/dn Enable */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 0x1;	/* 2_0024[5] G ch VDC UP/DN enable */

		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0x0;	/* 2_001c[17] G ch no swap */
		adc_gain0_reg.adc_gain_grn = 0x180;		/* 2_0030[24:16] Green Channel Gain Adjust */
		adc_offset0_reg.adc_off_grn = 0x1c0;	/* 2_0038[25:16] Green Channel Offset Adjust */
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[Set Green channel] %x\n", path_signal);
		ucTemp = 0x1;
		break;
/* ==========  R channel setting ===================================== */
	/* enable R channel VDC UP/DN select (00: VIN2P, 01: VIN5P, 10: VIN8PP, 11: X) */
	/* enable Nclamp up/dn GND set, VIN0,1,2 = RGB GND, VIN3,4,5 = Y0N, VIN6,7,8 = Y1N */
	case VIDEO_INPUT2:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 0x0;		/* 2_0008[5:4]=00, VIN2P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0x0;	/* 2_0024[7:6]=00, VIN2P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 0x0;	/* 2_001c[7:6]=00, VINRN */
		goto _R_Ch_Set;
	case VIDEO_INPUT5:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 0x1;		/* 2_0008[5:4]=01, VIN5P */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0x1;	/* 2_0024[7:6]=01, VIN5P up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 0x1;	/* 2_001c[7:6]=01, VINY0N */
		goto _R_Ch_Set;
	case VIDEO_INPUT8:
		adc_ctl_rgb12_reg.adc_ctl_rgb1_9 = 0x1;			/* 2_0008[9]=1, R ch in VIN8P */
		adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 0x2;		/* 2_0008[5:4]=10, VIN8PP */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0x2;	/* 2_0024[7:6]=10, VIN8PP up/dn enable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 0x2;	/* 2_001c[7:6]=10, VINY1N */

_R_Ch_Set:
		adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 0x3;	/* 2_0008[21:20]=11, R-:X */
		/* 2_0018[8][7:6] R ch dc restore disable */
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0x0;
		adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0x3;
		/* 2_001c[27][26:25] R ch negative clamp disable */
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 0x0;
		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0x3;
		/* 2_0020[8][7:6] R ch voltage clamp disable */
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0x0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0x3;

		adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0x1;	/* 2_001c[8] R ch Negative up/dn Enable */
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 0x1;	/* 2_0024[8] R ch VDC UP/DN enable */

		adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0x0;	/* 2_001c[18] R ch no swap */
		adc_gain0_reg.adc_gain_red = 0x180;		/* 2_0030[8:0] Green Channel Gain Adjust */
		adc_offset0_reg.adc_off_red = 0x1c0;	/* 2_0038[9:0] Red Channel Offset Adjust */
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[Set Red channel] %x\n", path_signal);
		ucTemp = 0x2;
		break;
	default:
		ucTemp = 0x0;
		break;
	}

	rtdf_outl(ADC_ADC_CTL_RGB12_reg, adc_ctl_rgb12_reg.regValue);	/* 2_0008 */
	rtdf_outl(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);			/* 2_0010 */
	rtdf_outl(ADC_ADC_DCRESTORE_CTRL_reg, adc_dcrestore_ctrl_reg.regValue);	/* 2_0018 */
	rtdf_outl(ADC_ADC_CLAMP_CTRL0_reg, adc_clamp_ctrl0_reg.regValue);	/* 2_001c */
	rtdf_outl(ADC_ADC_CLAMP_CTRL1_reg, adc_clamp_ctrl1_reg.regValue);	/* 2_0020 */
	rtdf_outl(ADC_ADC_CLAMP_CTRL2_reg, adc_clamp_ctrl2_reg.regValue);	/* 2_0024 */
	rtdf_outl(ADC_ADC_GAIN0_reg, adc_gain0_reg.regValue);		/* 2_0030 */
	rtdf_outl(ADC_ADC_GAIN1_reg, adc_gain1_reg.regValue);		/* 2_0034 */
	rtdf_outl(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);	/* 2_0038 */
	rtdf_outl(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);	/* 2_003c */

	return ucTemp;	/* return ADC number */
}


void module_vdc_ClampType_set(unsigned char ClampTpye, unsigned char ClampADC)
{
	/* set 960c, 9610 */
	vdtop_clamp_updn_en_RBUS clamp_updn_en_reg;		/* 960c */
	vdtop_clamp_rgb_updn_en_RBUS clamp_rgb_updn_en_reg;	/* 9610 */

	clamp_updn_en_reg.regValue = vdcf_inl(VDTOP_CLAMP_UPDN_EN_reg);
	clamp_rgb_updn_en_reg.regValue = vdcf_inl(VDTOP_CLAMP_RGB_UPDN_EN_reg);
	switch (ClampADC) {
	case 0:	/* B-ch ==> */
		clamp_updn_en_reg.clamp_ad1 = ClampTpye;
		clamp_rgb_updn_en_reg.clamp_a_up_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_a_dn_en = 0x1;
		break;
	case 1:	/* G-ch ==> */
		clamp_updn_en_reg.clamp_ad2 = ClampTpye;
		clamp_rgb_updn_en_reg.clamp_b_up_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_b_dn_en = 0x1;
		break;
	case 2:	/* R-ch ==> V-ch */
		clamp_updn_en_reg.clamp_ad3 = ClampTpye;
		clamp_rgb_updn_en_reg.clamp_c_up_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_c_dn_en = 0x1;
		break;
	default:
	case 3:	/* V-ch ==> */
		clamp_updn_en_reg.clamp_ad4 = ClampTpye;
		clamp_rgb_updn_en_reg.clamp_c_up_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_c_dn_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_d_up_en = 0x1;
		clamp_rgb_updn_en_reg.clamp_d_dn_en = 0x1;
		break;
	}

	vdcf_outl(VDTOP_CLAMP_UPDN_EN_reg, clamp_updn_en_reg.regValue);
	vdcf_outl(VDTOP_CLAMP_RGB_UPDN_EN_reg, clamp_rgb_updn_en_reg.regValue);
}

/**
     module_vdc_SetInput_Y
    if the input is the av ,the function is setting the y registers
    @param<SrcType> {uchar_t Y_path, uchar_t Y_Gnd_path}
    return { none }
    @ingroup dragon_video
*/
void module_vdc_SetInput_Y(unsigned char Y_path, unsigned char Y_Gnd_path)
{
	vdtop_ad_sw_ctrl0_RBUS ad_sw_ctrl0_reg;		/* 9608 */

	unsigned char ADCselect;
	ucVin = Y_path;
	ucVgnd = Y_Gnd_path;

	/* V Channel Input+ : 1P,4P,7P,9P, 10P, 12P, 13P */
	if ((Y_path == VIDEO_INPUT0) || (Y_path == VIDEO_INPUT2)
		|| (Y_path == VIDEO_INPUT3) || (Y_path == VIDEO_INPUT5)
		|| (Y_path == VIDEO_INPUT6) || (Y_path == VIDEO_INPUT8)
		|| (Y_path == VIDEO_INPUT11) || (Y_path == VIDEO_INPUT14)) {
		VDC_DEBUG_MSG(VDC_MSG_INIT," Does not support input paht: %x/%x, return~~\n", Y_path, Y_Gnd_path);
		return;
	}

	VDC_DEBUG_MSG(VDC_MSG_INIT,"[Y_path] %x, [Y_Gnd_path] %x\n", Y_path, Y_Gnd_path);
	ADCselect = (module_vdc_SetADCPath(Y_path, Y_Gnd_path) & 0x03);

	ad_sw_ctrl0_reg.regValue = vdcf_inl(VDTOP_AD_SW_CTRL0_reg);
	ad_sw_ctrl0_reg.sw_comp = ADCselect;	/* set VD AD switch */
	vdcf_outl(VDTOP_AD_SW_CTRL0_reg, ad_sw_ctrl0_reg.regValue);
	module_vdc_ClampType_set(AD_YorCVBS, ADCselect);	/* set Y */

	drvif_video_set_control_reg(VDC_set_src_AV);
}

/**
     module_vdc_SetInput_YC
    if the input is the  s-video ,the function is setting the y and c path registers
    @param<SrcType> { uchar_t Y_path, uchar_t Y_Gnd_path, uchar_t C_path, uchar_t C_Gnd_path }
    @return { none }
    @ingroup dragon_video
*/
void module_vdc_SetInput_YC(unsigned char Y_path, unsigned char Y_Gnd_path, unsigned char C_path, unsigned char C_Gnd_path, unsigned char SV_Type)
{
	unsigned char Y_ADCselect;
	unsigned char C_ADCselect;

	adc_vd_adc_clamp_ctl_2_RBUS vd_adc_clamp_ctl_2_reg;	/* 2_004c */
	adc_vd_adc_updn_ctl_RBUS vd_adc_updn_ctl_reg;		/* 2_0050 */
	adc_vdadc_ck_ctl_RBUS vdadc_ck_ctl_reg;				/* 2_0058 */
	vd_ifd_input_vd_in_delay_sel1_RBUS vd_in_delay_sel1_reg;		/* 1_80a0*/
	vd_ifd_input_vd_in_delay_sel2_RBUS vd_in_delay_sel2_reg;		/* 1_80a4 */
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg; /* 90c4 */
	vdtop_ad_sw_ctrl0_RBUS ad_sw_ctrl0_reg;				/* 9608 */
	vdtop_clamp_updn_en_RBUS clamp_updn_en_reg;			/* 960c */
	vdtop_clamp_rgb_updn_en_RBUS clamp_rgb_updn_en_reg;	/* 9610*/

	VDC_DEBUG_MSG(VDC_MSG_INIT,"[Y_path] %x, [Y_Gnd_path] %x\n", Y_path, Y_Gnd_path);
	Y_ADCselect = module_vdc_SetADCPath(Y_path, Y_Gnd_path);

	vd_in_delay_sel1_reg.regValue = rtdf_inl(VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg);
	vd_in_delay_sel1_reg.regValue = 0x00000000;	/* 1_80a0 set adc delay = 0 */
	vd_in_delay_sel1_reg.ad2_input_delay = 0x09;	/* 1_80ac[12:8] = 0x0e, set ad2 delay = 0x08 */
	rtdf_outl(VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg, vd_in_delay_sel1_reg.regValue);

	if (SV_Type == VIDEO_SV_SWAP) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[C_path][swap] %x, [C_Gnd_path] %x\n", C_path, C_Gnd_path);
		C_ADCselect = module_vdc_SetADCPath(C_path, C_Gnd_path);

		/* ADC setting */
		enum CRT_CLK clken = CLK_ON;
		CRT_CLK_OnOff(SCALER_VDC_INPUT_2, clken , NULL);

		vd_adc_clamp_ctl_2_reg.regValue = rtdf_inl(ADC_VD_ADC_CLAMP_CTL_2_reg);
		vd_adc_clamp_ctl_2_reg.vdadc_clamp_ctrl2_5 = 0x1;	/* 2_004c[5] = 1, yc swap enable */
		rtdf_outl(ADC_VD_ADC_CLAMP_CTL_2_reg, vd_adc_clamp_ctl_2_reg.regValue);

		vd_adc_updn_ctl_reg.regValue = rtdf_inl(ADC_VD_ADC_UPDN_CTL_reg);
		vd_adc_updn_ctl_reg.vdadc_updn_ctrl0_1_0 = 0x3;	/* 2_0050[1:0]=11, SV */
		rtdf_outl(ADC_VD_ADC_UPDN_CTL_reg, vd_adc_updn_ctl_reg.regValue);

		vdadc_ck_ctl_reg.regValue = rtdf_inl(ADC_VDADC_CK_CTL_reg);
		vdadc_ck_ctl_reg.vdadc_ckin_sel_7 = 0x1;	/* 2_0058[15]=1, PLL27X_CK54MHz clock enable */
		rtdf_outl(ADC_VDADC_CK_CTL_reg, vdadc_ck_ctl_reg.regValue);

		/* enable sv_yc_switch */
		vd_in_delay_sel2_reg.regValue = rtdf_inl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg);
		vd_in_delay_sel2_reg.sv_sel = 0x3;			/* 1_80a4[3:2] = 11, AD4 */
		vd_in_delay_sel2_reg.sv_yc_switch = 0x1;		/* 1_80a4[1] = 1 */
		vd_in_delay_sel2_reg.sv_in_one_adc = 0x1;	/* 1_80a4[0] = 1 */
		rtdf_outl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg, vd_in_delay_sel2_reg.regValue);

		charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
		charge_pump_delay_control_reg.auto_dc_restore_en1 = 0x1;	/* 90c4[13] = 1, enable dc-restore function */
		charge_pump_delay_control_reg.auto_dc_restore_en0 = 0x1;	/* 90c4[12] = 1, enable dc-restore function */
		vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);

		ad_sw_ctrl0_reg.regValue = vdcf_inl(VDTOP_AD_SW_CTRL0_reg);
		ad_sw_ctrl0_reg.sw_comp = 0x1;	/* set VD AD switch : Y */
		ad_sw_ctrl0_reg.sw_pr_r = 0x0;		/* set VD AD switch : C */
		ad_sw_ctrl0_reg.sw_pb_b = 0x2;		/* others */
		ad_sw_ctrl0_reg.sw_g = 0x3;		/* others */
		vdcf_outl(VDTOP_AD_SW_CTRL0_reg, ad_sw_ctrl0_reg.regValue);
	}else {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"[C_path][2 ADCs] %x, [C_Gnd_path] %x\n", C_path, C_Gnd_path);
		C_ADCselect = module_vdc_SetRGBADCPath(C_path, C_Gnd_path);

		ad_sw_ctrl0_reg.regValue = vdcf_inl(VDTOP_AD_SW_CTRL0_reg);
		ad_sw_ctrl0_reg.sw_comp = 0x1;	/* set VD AD switch : Y */
		ad_sw_ctrl0_reg.sw_pr_r = 0x2;		/* set VD AD switch : C */
		ad_sw_ctrl0_reg.sw_pb_b = 0x3;		/* others */
		ad_sw_ctrl0_reg.sw_g = 0x0;		/* others */
		vdcf_outl(VDTOP_AD_SW_CTRL0_reg, ad_sw_ctrl0_reg.regValue);
	}

	clamp_updn_en_reg.regValue = vdcf_inl(VDTOP_CLAMP_UPDN_EN_reg);
	clamp_updn_en_reg.clamp_ad4 = 0x0;		/* 960c set Y*/
	clamp_updn_en_reg.clamp_ad3 = 0x2;		/* 960c set C*/
	clamp_updn_en_reg.clamp_ad2 = 0x1;		/* 960c others*/
	clamp_updn_en_reg.clamp_ad1 = 0x3;		/* 960c others*/
	vdcf_outl(VDTOP_CLAMP_UPDN_EN_reg, clamp_updn_en_reg.regValue);

	clamp_rgb_updn_en_reg.regValue = vdcf_inl(VDTOP_CLAMP_RGB_UPDN_EN_reg);
	clamp_rgb_updn_en_reg.clamp_c_up_en = 0x1;	/* 9610 enable cleamp up*/
	clamp_rgb_updn_en_reg.clamp_c_dn_en = 0x1;	/* 9610 enable cleamp dn*/
	clamp_rgb_updn_en_reg.clamp_d_up_en = 0x1;	/* 9610 enable cleamp up*/
	clamp_rgb_updn_en_reg.clamp_d_dn_en = 0x1;	/* 9610 enable cleamp dn*/
	vdcf_outl(VDTOP_CLAMP_RGB_UPDN_EN_reg, clamp_rgb_updn_en_reg.regValue);

	drvif_video_set_control_reg(VDC_set_src_SV);
}

#ifdef CONFIG_SCART_ENABLE
/**
	module_vdc_SetInput_YRGB
	if the input is the  SCART ,the function is setting the y/r/g/b path registers
	@param<SrcType> { uchar_t Y_path, uchar_t Y_Gnd_path, uchar_t R_path, uchar_t R_Gnd_path }
					 { uchar_t G_path, uchar_t G_Gnd_path, uchar_t B_path, uchar_t B_Gnd_path }
	@return { none }
	@ingroup dragon_video
*/
void module_vdc_SetInput_YRGB(unsigned char Y_path, unsigned char B_path, unsigned char G_path, unsigned char R_path, unsigned char YRGB_Gnd_path)
{
	unsigned char Y_ADCselect;
	unsigned char R_ADCselect;
	unsigned char G_ADCselect;
	unsigned char B_ADCselect;

	vd_ifd_input_vd_in_delay_sel2_RBUS vd_in_delay_sel2_reg;
	vdtop_ad_sw_ctrl0_RBUS ad_sw_ctrl0_reg;		/* 9608 */
	vdtop_clamp_rgb_updn_en_RBUS clamp_rgb_updn_en_reg;	/* 9610 */
	adc_scart_ctrl1_RBUS scart_ctrl1_reg;
	vdtop_charge_pump_delay_control_RBUS charge_pump_delay_control_reg;

#if 0//fix me sunray
	rtd_maskl(PINMUX_MAIN_VD_ADC_0_reg,0x0FFFFFFF,0xD0000000);	/* make sure SCART_FSW0 is used as vd input (SCART_FSW_CFG PinMux.doc) */
#endif
	down(get_adc_power_semaphore());
	drvif_adc_power_control(ADC_POWER_ALL_ENABLE_CONTROL);/* enable all ADC power */
	up(get_adc_power_semaphore());

	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_VDC_INPUT_3, clken , NULL);


	charge_pump_delay_control_reg.regValue = vdcf_inl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg);
	charge_pump_delay_control_reg.auto_dc_restore_en0 = 0x1;	/* 90c4[12] = 1, enable dc-restore function */
	vdcf_outl(VDTOP_CHARGE_PUMP_DELAY_CONTROL_reg, charge_pump_delay_control_reg.regValue);

	/* disable sv_yc_switch */
	vd_in_delay_sel2_reg.regValue = rtdf_inl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg);
	vd_in_delay_sel2_reg.sv_sel = 0x0;			/* 1_80a4[3:2] = 00 */
	vd_in_delay_sel2_reg.sv_yc_switch = 0x0;		/* 1_80a4[1] = 0 */
	vd_in_delay_sel2_reg.sv_in_one_adc = 0x0;	/* 1_80a4[0] = 0 */
	rtdf_outl(VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg, vd_in_delay_sel2_reg.regValue);

	VDC_DEBUG_MSG(VDC_MSG_INIT,"[Y_path] %d\n", Y_path);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"[R_path] %d\n", R_path);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"[G_path] %d\n", G_path);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"[B_path] %d\n", B_path);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"[YRGB_Gnd_path] %d\n", YRGB_Gnd_path);

	Y_ADCselect = (module_vdc_SetADCPath(Y_path, YRGB_Gnd_path) & 0x03);		/* 3 */
	R_ADCselect = (module_vdc_SetRGBADCPath(R_path, YRGB_Gnd_path) & 0x03);	/* 2 */
	G_ADCselect = (module_vdc_SetRGBADCPath(G_path, YRGB_Gnd_path) & 0x03);	/* 1 */
	B_ADCselect = (module_vdc_SetRGBADCPath(B_path, YRGB_Gnd_path) & 0x03);	/* 0 */

	ad_sw_ctrl0_reg.regValue = vdcf_inl(VDTOP_AD_SW_CTRL0_reg);

	ad_sw_ctrl0_reg.sw_comp = Y_ADCselect;	/* set VD AD switch : Y */
	ad_sw_ctrl0_reg.sw_pr_r = R_ADCselect;	/* set VD AD switch : R */
	ad_sw_ctrl0_reg.sw_pb_b = B_ADCselect;	/* set VD AD switch : B */
	ad_sw_ctrl0_reg.sw_g = G_ADCselect;	/* set VD AD switch : G */

	module_vdc_ClampType_set(AD_YorCVBS, Y_ADCselect);		/* set Y */
	module_vdc_ClampType_set(AD_CorRorPr, R_ADCselect);		/* set R */
	module_vdc_ClampType_set(AD_G, G_ADCselect);			/* set G */
	module_vdc_ClampType_set(AD_BorPb, B_ADCselect);		/* set B */

	clamp_rgb_updn_en_reg.regValue = vdcf_inl(VDTOP_CLAMP_RGB_UPDN_EN_reg);
	clamp_rgb_updn_en_reg.regValue = 0xff;	/* enable cleamp up/dn */

	vdcf_outl(VDTOP_AD_SW_CTRL0_reg, ad_sw_ctrl0_reg.regValue);
	vdcf_outl(VDTOP_CLAMP_RGB_UPDN_EN_reg, clamp_rgb_updn_en_reg.regValue);

	scart_ctrl1_reg.regValue = rtdf_inl(ADC_SCART_CTRL1_reg);
	scart_ctrl1_reg.vdadc_sct_ctrl = 0x47;
	rtdf_outl(ADC_SCART_CTRL1_reg, scart_ctrl1_reg.regValue);
}
#endif

/**
  drvif_module_vdc_AVoutEnable

  Selectt AVout enable from AD0[0]~AD3[3]

  @param
             < yes_no >   { _YES : select AVout is displaying source
                                    _No : select AVout is not displaying source }
  @return <void>         { void }

*/
void drvif_module_vdc_AVoutEnable(VDC_VIDEO_AVOUT_ENABLE on_off)
{
	if (on_off == VDC_AVOUT_ENALBE) {
		drvif_vdac_source_sel(VDAC_TV_SRC_SEL_VD);
		drvif_vdac_tvdac_power_on(_ENABLE);
	} else {
		drvif_vdac_tvdac_power_on(_DISABLE);
	}
}

void drvif_module_vdc_AVout_Delay(unsigned short value)
{
	/* 969c[11][10:0] */
	vdtop_avout_fifo_rd_ptr_RBUS avout_fifo_rd_ptr_reg;
	avout_fifo_rd_ptr_reg.regValue = vdcf_inl(VDTOP_AVOUT_FIFO_RD_PTR_reg);
	avout_fifo_rd_ptr_reg.avout_fifo_sel = 1;
	avout_fifo_rd_ptr_reg.avout_fifo_rd_ptr = value;
	vdcf_outl(VDTOP_AVOUT_FIFO_RD_PTR_reg, avout_fifo_rd_ptr_reg.regValue);
}

unsigned short drvif_module_vdc_read_AVout_Delay(void)
{
	/* 969c[10:0] */
	vdtop_avout_fifo_rd_ptr_RBUS avout_fifo_rd_ptr_reg;
	avout_fifo_rd_ptr_reg.regValue = vdcf_inl(VDTOP_AVOUT_FIFO_RD_PTR_reg);
	return avout_fifo_rd_ptr_reg.avout_fifo_rd_ptr;
}

void drvif_module_vdc_AVout_Hsync_Only(void)
{
	/* 9080[29:20][17:8], 9084[8:5][23:12] */
	vdtop_avout_fifo_status_RBUS avout_fifo_status_reg;
	vdtop_inout_ctrl_RBUS inout_ctrl_reg;

	avout_fifo_status_reg.regValue = vdcf_inl(VDTOP_AVOUT_FIFO_STATUS_reg);
	avout_fifo_status_reg.avout_mixer_sel = 0x8;
	avout_fifo_status_reg.avout_test_in = 0x800;
	vdcf_outl(VDTOP_AVOUT_FIFO_STATUS_reg, avout_fifo_status_reg.regValue);

	inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);
	inout_ctrl_reg.avout_hsync_start = 0x11;
	inout_ctrl_reg.avout_hsync_end = 0x00;
	vdcf_outl(VDTOP_INOUT_CTRL_reg, inout_ctrl_reg.regValue);
}

void drvif_module_vdc_AVout_Normal(void)
{
	/* 9080[29:20][17:8], 9084[8:5][23:12] */
	vdtop_avout_fifo_status_RBUS avout_fifo_status_reg;
	vdtop_inout_ctrl_RBUS inout_ctrl_reg;

	avout_fifo_status_reg.regValue = vdcf_inl(VDTOP_AVOUT_FIFO_STATUS_reg);
	avout_fifo_status_reg.avout_mixer_sel = 0x2;
	avout_fifo_status_reg.avout_test_in = 0x000;
	vdcf_outl(VDTOP_AVOUT_FIFO_STATUS_reg, avout_fifo_status_reg.regValue);

	inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);
	inout_ctrl_reg.avout_hsync_start = 0x00;
	inout_ctrl_reg.avout_hsync_end = 0x11;
	vdcf_outl(VDTOP_INOUT_CTRL_reg, inout_ctrl_reg.regValue);
}

void module_vdc_clamp_type(VDC_CLAMP_TYPE ucClamp)
{
	/* 9080[3][1:0] */
	vdtop_inout_ctrl_RBUS vdtop_inout_ctrl_reg;
	vdtop_inout_ctrl_reg.regValue = vdcf_inl(VDTOP_INOUT_CTRL_reg);

	if (ucClamp == CLAMP_IFD) {
		vdtop_inout_ctrl_reg.sw_tu_cvbs = 0x1;
		vdtop_inout_ctrl_reg.clamp_if_up_en = 0x1;
		vdtop_inout_ctrl_reg.clamp_if_dn_en = 0x1;
		VDC_DEBUG_MSG(VDC_MSG_INIT,"path is TV\n");
	} else {
		/* disable IFD setting */
		vdtop_inout_ctrl_reg.sw_tu_cvbs = 0x0;
		vdtop_inout_ctrl_reg.clamp_if_up_en = 0x0;
		vdtop_inout_ctrl_reg.clamp_if_dn_en = 0x0;
		VDC_DEBUG_MSG(VDC_MSG_INIT,"path is VD\n");
	}
	vdcf_outl(VDTOP_INOUT_CTRL_reg, vdtop_inout_ctrl_reg.regValue);
}

/**
   module_vdc_PathSelect
   Video input path set, no extern

   @param <src>        { Select input signal}
   @return                  { void }

*/
void module_vdc_PathSelect(unsigned char ucSourceIndex, void* stPath)
{
	sys_reg_sys_clksel_RBUS sys_clksel_reg;		/* 0_0204 */
	unsigned char ucClampTemp = CLAMP_CVBS;
	vdtop_ad_sw_ctrl0_RBUS ad_sw_ctrl0_reg;
	adc_scart_ctrl1_RBUS scart_ctrl1_reg;
	vdtop_fsw_ctrl2_RBUS fsw_ctrl2_reg;

	if (ucSourceIndex != _SRC_TV) {
		module_vdc_ADC_common_setting();
	}
	//VDC_DEBUG_MSG(VDC_MSG_INIT,"ucSourceIndex=%d\n", ucSourceIndex);

	/* reset VD AD switch */
	ad_sw_ctrl0_reg.regValue = vdcf_inl(VDTOP_AD_SW_CTRL0_reg);
	ad_sw_ctrl0_reg.sw_comp = 0x03;
	ad_sw_ctrl0_reg.sw_pr_r = 0x00;
	ad_sw_ctrl0_reg.sw_pb_b = 0x02;
	ad_sw_ctrl0_reg.sw_g = 0x01;
	vdcf_outl(VDTOP_AD_SW_CTRL0_reg, ad_sw_ctrl0_reg.regValue);

	/* SCART power off */
	scart_ctrl1_reg.regValue = rtdf_inl(ADC_SCART_CTRL1_reg);
	scart_ctrl1_reg.vdadc_sct_ctrl = 0x42;
	rtdf_outl(ADC_SCART_CTRL1_reg, scart_ctrl1_reg.regValue);
	/* Disable SCART function */
	fsw_ctrl2_reg.regValue = vdcf_inl(VDTOP_FSW_CTRL2_reg);
	fsw_ctrl2_reg.scart_en = 0x0;
	fsw_ctrl2_reg.fb_en = 0x0;
	vdcf_outl(VDTOP_FSW_CTRL2_reg, fsw_ctrl2_reg.regValue);

	drvif_video_set_control_reg(VDC_set_src_AV);
	drvif_module_vdc_set_Control2_Register(VDC_bgate_raw_sel_enable);

	sys_clksel_reg.regValue = rtdf_inl(SYS_REG_SYS_CLKSEL_reg);	/* 0_0204 */
	sys_clksel_reg.atvin_clk_sel = 1;		/* 0_0204[17] ATV Input clcok select, 0: IFD, 1:VD */

	switch (ucSourceIndex) {
//#ifdef CONFIG_TV_ENABLE
#if 1
	case  _SRC_TV:
		if ((((TV_VDC_PATH*)stPath)->VideoIn) == TV_INPUT) {
			//VDC_DEBUG_MSG(VDC_MSG_INIT,"path is ifd\n");
			drvif_module_vdc_FIFO_CLK_setting();
			ucClampTemp = CLAMP_IFD;
			sys_clksel_reg.atvin_clk_sel = 0;		/* 0_0204[17] ATV Input clcok select, 0: IFD, 1:VD */
			//VDC_DEBUG_MSG(VDC_MSG_INIT, "0_0204[17] Set from IFD\n");
		} else {
			drvif_module_Set_pll27x_source(VDC_PLL27x_CLK_324M);	/* AV need to set frist */
			module_vdc_SetInput_Y(((TV_VDC_PATH*)stPath)->VideoIn, ((TV_VDC_PATH*)stPath)->GroundIn);
		}
#if 0
		drvif_module_vdc_Set_bottom_gain(_DISABLE);
#endif
		drvif_module_vdc_FreeRun(VDC_FREERUN_DISABLE);
		break;
#endif
	case _SRC_CVBS:
#if 0
		vdcf_outl(VDTOP_AD_SW_CTRL0_reg, 0x00);
		vdcf_outl(VDTOP_CLAMP_RGB_UPDN_EN_reg, 0xff);
		PATTERN_CONTROL_RBUS pattern_control_reg;
		pattern_control_reg.regValue = vdcf_inl(VDTOP_PATTERN_CONTROL_reg);
		pattern_control_reg.pattern_generator_enable = 1;
		vdcf_outl(VDTOP_PATTERN_CONTROL_reg, pattern_control_reg.regValue);
#else
#if 0
		module_vdc_SetInput_Y(VIDEO_INPUT12, VIDEO_GNDA0);
#else
		module_vdc_SetInput_Y(((AV_VDC_PATH*)stPath)->VideoIn, ((AV_VDC_PATH*)stPath)->GroundIn);
#if 0
	vdtop_output_control_RBUS output_control_reg;
	output_control_reg.regValue = vdcf_inl(VDTOP_OUTPUT_CONTROL_reg);

		enum PLAFTORM_TYPE platform = get_platform();
		if (PLATFORM_K3LP == platform) {
			if (output_control_reg.blue_mode == 0x0)
				module_vdc_SetInput_Y(VIDEO_INPUT10, VIDEO_GNDA0);
			else
				module_vdc_SetInput_Y(VIDEO_INPUT4, VIDEO_GNDA0);
		}
		else if (PLATFORM_K3L == platform)
			module_vdc_SetInput_Y(VIDEO_INPUT13, VIDEO_GNDA0);
#endif
#endif
#endif
		break;
	case _SRC_SV:
#if 0
		module_vdc_SetInput_YC(VIDEO_INPUT10, VIDEO_Y1N, VIDEO_INPUT12, VIDEO_Y1N, VIDEO_SV_SWAP);
#else
		module_vdc_SetInput_YC(((SV_VDC_PATH*)stPath)->Y_VideoIn, ((SV_VDC_PATH*)stPath)->Y_GroundIn,
							   ((SV_VDC_PATH*)stPath)->C_VideoIn, ((SV_VDC_PATH*)stPath)->C_GroundIn,
							   ((SV_VDC_PATH*)stPath)->SV_Type);
#endif
		drvif_module_vdc_Cpeak_set(_ENABLE);
		break;
#ifdef CONFIG_SCART_ENABLE
	case _SRC_SCART:
	case _SRC_SCART_RGB:
		drvif_video_FullSCART_func_initial();
		drvif_module_vdc_Cpeak_set(_ENABLE);
#if 0
		module_vdc_SetInput_YRGB(VIDEO_INPUT13, VIDEO_INPUT6, VIDEO_INPUT7, VIDEO_INPUT8, VIDEO_GNDA2);
#else
		module_vdc_SetInput_YRGB(((SCART_VDC_PATH*)stPath)->Y_VideoIn,
								 ((SCART_VDC_PATH*)stPath)->B_VideoIn,
								 ((SCART_VDC_PATH*)stPath)->G_VideoIn,
								 ((SCART_VDC_PATH*)stPath)->R_VideoIn,
								 ((SCART_VDC_PATH*)stPath)->GroundIn);
#endif
		if (drvif_module_vdc_read_FSW_value() >= cSCART_FSW_Level) {	/* is RGB */
			drvif_video_SCART_RGB_set(_ENABLE);
			SCART_Type = _SCART_RGB;
			//VDC_DEBUG_MSG(VDC_MSG_INIT,"_SCART_RGB\n");
		} else {
			drvif_video_SCART_RGB_set(_DISABLE);
			SCART_Type = _SCART_AV;
			//VDC_DEBUG_MSG(VDC_MSG_INIT,"_SCART_AV\n");
		}
		break;
#endif
	default:
		break;
	}
	rtdf_outl(SYS_REG_SYS_CLKSEL_reg, sys_clksel_reg.regValue);
	module_vdc_clamp_type((VDC_CLAMP_TYPE) ucClampTemp);

	drvif_module_vdc_108M_FrontDigitalFilterEnable(VDC_108M_FDF_75MHZ);
	drvif_module_vdc_SoftReset();
}

#ifdef scart_vdc_auto_balance_en

static unsigned char scart_auto_adcgainoffsetadjust(unsigned char color, unsigned short delta,
		unsigned char inc, unsigned char saturate, unsigned short* Gain_Offset)
{
	unsigned short usTemp;

	usTemp = inc ? (0x3fe - *Gain_Offset) : *Gain_Offset;

	//VDC_DEBUG_MSG(VDC_MSG_INIT,"inc:0x%x,Gain_Offset:0x%x,usTemp:0x%x,delta:0x%x\n", inc, *Gain_Offset, usTemp, delta);

	if (!inc) {
		if (usTemp > delta)
			*Gain_Offset -= delta;
		else {
			*Gain_Offset = 0;
			saturate |= color;
		}
	} else {
		if (usTemp > delta)
			*Gain_Offset += delta;
		else {
			*Gain_Offset = 0x3fe;
			saturate |= color;
		}
	}
	return saturate;

}


static unsigned char scart_auto_adcgainchange(unsigned char display, unsigned char color, unsigned short delta,
		unsigned char inc)
{

	vdc_ADCGainOffset *ptADCGainOffset = NULL;
	unsigned char ucTemp = 0;

	ptADCGainOffset = &g_scart_ADCGainOffset;

	//if (color & SELECT_RED) {//forster modified 050728
	//becasue the sequence of red and green in the smartfit is inverse, it has to swap red and green.
	if (color & SELECT_GREEN) {
		ucTemp = scart_auto_adcgainoffsetadjust(SELECT_RED, delta, inc, ucTemp, (unsigned short *)&ptADCGainOffset->Gain_R);  //forster modified 050905
	}

	//if (color & SELECT_GREEN) {//forster modified 050728
	if (color & SELECT_RED) {
		ucTemp |= scart_auto_adcgainoffsetadjust(SELECT_GREEN, delta, inc, ucTemp, (unsigned short*)&ptADCGainOffset->Gain_G);   //forster modified 050905
	}

	if (color & SELECT_BLUE) {//forster modified 050728
		ucTemp |= scart_auto_adcgainoffsetadjust(SELECT_BLUE, delta, inc, ucTemp,	(unsigned short*)&ptADCGainOffset->Gain_B);  //forster modified 050905
	}

	drvif_module_vdc_Set_scart_gain();

	return ucTemp;

}


static unsigned char scart_auto_adcoffsetchange(unsigned char display, unsigned char color, unsigned short delta,
		unsigned char inc)
{

	vdc_ADCGainOffset *ptADCGainOffset = NULL;
	unsigned char ucTemp = 0;

	ptADCGainOffset = &g_scart_ADCGainOffset;

	if (color & SELECT_RED) {//forster modified 050728
		ucTemp = scart_auto_adcgainoffsetadjust(SELECT_RED, delta, inc, ucTemp, (unsigned short *)&ptADCGainOffset->Offset_R); //forster modified 050905
	}

	if (color & SELECT_GREEN) {//forster modified 050728
		ucTemp |= scart_auto_adcgainoffsetadjust(SELECT_GREEN, delta, inc, ucTemp, (unsigned short *)&ptADCGainOffset->Offset_G);//forster modified 050905
	}

	if (color & SELECT_BLUE) {//forster modified 050728
		ucTemp |= scart_auto_adcgainoffsetadjust(SELECT_BLUE, delta, inc, ucTemp,	(unsigned short *)&ptADCGainOffset->Offset_B);//forster modified 050905
	}

	drvif_module_vdc_Set_scart_offset();

	return ucTemp;

}


//--------------------------------------------------
// Description  : Adjust ADC gain
// Input Value  : Adjusting setting
// Output Value : Measure status
//--------------------------------------------------
unsigned char drvif_scart_auto_tunedevicegain(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMax_Target)
{
	unsigned short temp;

	if (drvif_auto_measurecolor(display, ucColor, _COLOR_MAX, pMargin) != ERROR_SUCCEED) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\nError ABORT 0%c", '!');
		return ERROR_ABORT;
	}

#if 0
	if (*pMargin < VGA_AWB_CHECK_LEVEL) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n*pMargin < VGA_AWB_CHECK_LEVEL");
		return ERROR_ABORT;
	}
#endif

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\nmeasure: 0x%x,max: 0x%x\n", *pMargin, ucMax_Target);

	if (*pMargin > ucMax_Target) {
		temp  = *pMargin - ucMax_Target;
		/*
				#ifdef CONFIG_SELF_AWB_ENABLE
				if(*pMargin == 1023)//leochen
					temp+=100;
				#endif
		*/
		if (scart_auto_adcgainchange(display, ucColor, temp, 0)) {               // Decrease Gain; Decrease Contrast
			// oliver-
			//if(auto_adcoffsetchange(display, ucColor, (( Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VDC) ? 8 : 16), 0))               // Increase Offset; Decrease Brightness
			//	return ERROR_FINISH;
		}
	} else if (*pMargin < ucMax_Target) {
		temp  = ucMax_Target - *pMargin;
		// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
		if (scart_auto_adcgainchange(display, ucColor, temp, 1)) {               // Increase Gain; Increase Contrast
			// oliver-
			//if(auto_adcoffsetchange(display, ucColor, ((Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VDC) ? 8 : 16), 1))               // Increase Offset; Increase Brightness
			//	return ERROR_FINISH;
		}
	}
	return ERROR_SUCCEED;//_ERROR_SUCCESS;
}

//--------------------------------------------------
// Description  : Adjust ADC offset
// Input Value  : Adjusting setting
// Output Value : Measure status
//--------------------------------------------------
#define _CHROMA_BLACK_LEVEL				(0x200)

unsigned char drvif_scart_auto_tunedeviceoffset(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMin_Target)
{
	unsigned short temp;

	if (drvif_auto_measurecolor(display, ucColor, _COLOR_MAX, pMargin) != ERROR_SUCCEED) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\nError ABORT \n");
		return ERROR_ABORT;
	}

	if ((Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display) == _SRC_VGA) || 	// weihao 960308
		((Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display) == _SRC_YPBPR) && (ucColor == SELECT_Y)) ||  	// weihao 960308
		((Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VDC) && (ucColor == SELECT_GREEN))) {

		//forster modified 061002
		if (*pMargin > ucMin_Target) {

			temp = *pMargin - ucMin_Target;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n decrease Color= %x, Offset0 BIOS = %x pMargin=%x  mintarget=%x", ucColor, temp, *pMargin, ucMin_Target);
			scart_auto_adcoffsetchange(display, ucColor, ((temp > 32) ? 32 : temp), 0);

		} else if (*pMargin < ucMin_Target) {

			temp = ucMin_Target - *pMargin;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n increase Color= %x, Offset1 BIOS = %x pMargin=%x mintarget=%x", ucColor, temp, *pMargin, ucMin_Target);

			if (*pMargin == 0)
				scart_auto_adcoffsetchange(display, ucColor, temp + 16, 1);       // Increase Offset; Increase Brightness //Change_Device_Offset(ucColor, temp + 4, 1);       // Increase Offset; Increase Brightness
			else
				scart_auto_adcoffsetchange(display, ucColor, temp, 1);           // Increase Offset; Increase Brightness
		}

	} else {

		if (*pMargin > _CHROMA_BLACK_LEVEL) {
			temp = *pMargin - _CHROMA_BLACK_LEVEL;
			scart_auto_adcoffsetchange(display, ucColor, ((temp > 32) ? 32 : temp), 0);
		} else if (*pMargin < _CHROMA_BLACK_LEVEL) {

			temp = _CHROMA_BLACK_LEVEL - *pMargin;

			if (*pMargin == 0) {
				scart_auto_adcoffsetchange(display, ucColor, temp + 16, 1);
			} else {
				scart_auto_adcoffsetchange(display, ucColor, temp, 1);
			}
		}
	}
	return ERROR_SUCCEED;
}

//Gain => SW adjust, Offset => SW adjust
unsigned char drvif_vdc_scart_adc_autobalance_standard(unsigned char display)
{
	unsigned short rev = 0, result0 = 0, result1 = 0, color = 0, count = 0;
	unsigned short usMax_Value = 0, usMin_Value = 0;
	vdc_ADCGainOffset *ptADCGainOffset = NULL;

	drvif_module_vdc_scart_rgb_output_enable();

	ptADCGainOffset = &g_scart_ADCGainOffset;

	ptADCGainOffset->Gain_B = 512;//0x80;
	ptADCGainOffset->Gain_G = 512;//0x80;
	ptADCGainOffset->Gain_R = 512;//0x80;
#if 0 // don't care offset
	ptADCGainOffset->Offset_B = 512;//0x80;
	ptADCGainOffset->Offset_G = 512;//0x80;
	ptADCGainOffset->Offset_R = 512;//0x80;
#endif

	drvif_module_vdc_scart_auto_setadcgainoffset();

	if (drvif_auto_measurecolor(display, SELECT_GREEN, _COLOR_MAX, &rev) != ERROR_SUCCEED)
		goto PROCESS_ERROR;

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[_SRC_SCART_RGB auto color] VGA_AWB_CHECK_LEVEL=%x", VGA_AWB_CHECK_LEVEL);


	if (rev < VGA_AWB_CHECK_LEVEL) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[_SRC_SCART_RGB auto color] ERROR_ABORT rev : 0x%x < 0x180!", rev);
		goto PROCESS_ERROR;
	}

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[_SRC_SCART_RGB auto color] green check ok!");

	if (Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display) == _SRC_SCART_RGB) {
		if (drvif_auto_measurecolor(display, SELECT_BLUE, _COLOR_MAX, &rev) != ERROR_SUCCEED)
			goto PROCESS_ERROR;

		if (rev < VGA_AWB_CHECK_LEVEL)
			goto PROCESS_ERROR;

		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[_SRC_SCART_RGB auto color] blue check ok!");

		if (drvif_auto_measurecolor(display, SELECT_RED, _COLOR_MAX, &rev) != ERROR_SUCCEED)
			goto PROCESS_ERROR;

		if (rev < VGA_AWB_CHECK_LEVEL)
			goto PROCESS_ERROR;

		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] red check ok!");
	}

	color = SELECT_BLUE;

	//Rt_Sleep(10000);

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] blue measure start!");

	while (TRUE) {
		count = 0x30;

		usMax_Value = scart_rgb_max_target_level;//1016
		usMin_Value = scart_rgb_min_target_level;

		do {
			rev = drvif_scart_auto_tunedevicegain(display, color, &result0, usMax_Value);

			if (rev == ERROR_ABORT)
				goto PROCESS_ERROR;
			if (rev == ERROR_FINISH)
				break;

			if ((ABS(result0, usMax_Value) < 2)) {
				VDC_DEBUG_MSG(VDC_MSG_INIT,"\n 1. result0:%x, usMax_Value:%x\n", result0, usMax_Value);
				break;
			}

			if ((count > 8) && (ABS(result0, usMax_Value) <= 4)) {
				VDC_DEBUG_MSG(VDC_MSG_INIT,"\n 2. result0:%x, usMax_Value:%x\n", result0, usMax_Value);
				count = 8;
			}

		} while (--count);

		if (color == SELECT_BLUE) { //_BLUE)				// 2 : Blue or PB
			color = SELECT_GREEN;//_GREEN;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] green measure start!");
		} else if (color == SELECT_GREEN) { //_GREEN)		// 1: Green or Y
			color = SELECT_RED;//_RED;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] red measure start!");
		} else 					// 0: Red or PR
			break;
	}


	if ((ptADCGainOffset->Gain_R == 0x00) || (ptADCGainOffset->Gain_G == 0x00) || (ptADCGainOffset->Gain_B == 0x00)) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n SCART Auto color fail! standard\n");
		goto PROCESS_ERROR;

	} else {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[AutoColor] Auto Color success for VGA!\t");
		VDC_DEBUG_MSG(VDC_MSG_INIT,"Result: gainR=0x%x=%d  gainG=0x%x=%d  gainB=0x%x=%d\n\n", ptADCGainOffset->Gain_R, ptADCGainOffset->Gain_R, ptADCGainOffset->Gain_G, ptADCGainOffset->Gain_G, ptADCGainOffset->Gain_B, ptADCGainOffset->Gain_B);
	}

	drvif_module_vdc_scart_rgb_output_disable();

	return ERROR_SUCCEED;

PROCESS_ERROR:

#if 0 //sync from pacific , if auto color fail, let it fail, osd show auto color fail
	ptADCGainOffset->Gain_B = 512;//0x80;
	ptADCGainOffset->Gain_G = 512;//0x80;
	ptADCGainOffset->Gain_R = 512;//0x80;
	ptADCGainOffset->Offset_B = 512;//0x80;
	ptADCGainOffset->Offset_G = 512;//0x80;
	ptADCGainOffset->Offset_R = 512;//0x80;

	drvif_auto_setadcgainoffset(display);
#endif
	VDC_DEBUG_MSG(VDC_MSG_INIT,"\nauto color fail\n");
	return ERROR_ABORT;

}

static unsigned char scart_auto_vdBrSatAdjust(unsigned char color, unsigned short delta, unsigned char inc, unsigned char saturate, unsigned short *BrSat)
{
	unsigned short usTemp, usDeltaTemp;

	usDeltaTemp = ((delta >> 2) & 0xff);

	usTemp = inc ? (0xfe - *BrSat) : *BrSat;

	VDC_DEBUG_MSG(VDC_MSG_INIT,"inc:0x%x,BrSat:0x%x,usTemp:0x%x,delta:0x%x\n", inc, *BrSat, usTemp, delta);

	if (!inc) {
		//if (usTemp > delta)
		if (usTemp > usDeltaTemp)
			//*BrSat -= delta;
			*BrSat -= usDeltaTemp;
		else {
			*BrSat = 0;
			saturate |= color;
		}
	} else {
		//if (usTemp > delta)
		if (usTemp > usDeltaTemp)
			//*BrSat += delta;
			*BrSat += usDeltaTemp;
		else {
			*BrSat = 0xfe;
			saturate |= color;
		}
	}
	return saturate;

}

static unsigned char scart_auto_vdBrSatchange(unsigned char display, unsigned char color, unsigned short delta, unsigned char inc)
{

	VDBrConSat *ptVDBrConSat = NULL;
	unsigned char ucTemp = 0;

	ptVDBrConSat = &g_scart_VDBrConSat;

	//if (color & SELECT_RED) {//forster modified 050728
	//becasue the sequence of red and green in the smartfit is inverse, it has to swap red and green.
	if (color & SELECT_RED) {
		ucTemp = scart_auto_vdBrSatAdjust(SELECT_RED, delta, inc, ucTemp, (unsigned short *)&ptVDBrConSat->Contrast2);  //forster modified 050905
	}

	//if (color & SELECT_GREEN) {//forster modified 050728
	if (color & SELECT_GREEN) {
		ucTemp |= scart_auto_vdBrSatAdjust(SELECT_GREEN, delta, inc, ucTemp, (unsigned short*)&ptVDBrConSat->Cb_saturation);   //forster modified 050905
	}

	if (color & SELECT_BLUE) {//forster modified 050728
		ucTemp |= scart_auto_vdBrSatAdjust(SELECT_BLUE, delta, inc, ucTemp,	(unsigned short*)&ptVDBrConSat->Cr_saturation);  //forster modified 050905
	}

	if (color & SELECT_BLACK) {//forster modified 050728
		ucTemp |= scart_auto_vdBrSatAdjust(SELECT_BLACK, delta, inc, ucTemp,	(unsigned short*)&ptVDBrConSat->Brightness2);  //forster modified 050905
	}


	drvif_module_vdc_Set_scart_Brightness_Saturation();

	return ucTemp;

}

unsigned char drvif_auto_measure_YUV(unsigned char color, unsigned short* rev, unsigned short* pPosition)
{
#if 0

	if ((SELECT_RED == color) || (SELECT_BLACK == color))
		drvif_color_write_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_Y);
	else if (SELECT_GREEN == color)
		drvif_color_write_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_U);
	else// if(SELECT_BLUE== color)
		drvif_color_write_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_V);


	//fix me. don't know if it needs to wait a momont
	if (auto_waitfinish(display)) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\nMeasure Error Abort\n");
		return ERROR_ABORT;
	}
#endif

	//return the max value per unit pixel
	if ((SELECT_RED == color) || (SELECT_BLACK == color))
		*rev = drvif_color_finddominant_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_Y);
	else if (SELECT_GREEN == color)
		*rev = drvif_color_finddominant_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_U);
	else
		*rev = drvif_color_finddominant_smartfit_dragon(pPosition[0], pPosition[1], pPosition[2], pPosition[3], AutoColor_V);

	//VDC_DEBUG_MSG(VDC_MSG_INIT,"\nMeasure Color=%x Margin = 0x%x=%d",color,*rev,*rev);
	return ERROR_SUCCEED;
}

unsigned char drvif_scart_auto_tuneBrSat(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMax_Target, unsigned short *pPosition)
{
	unsigned short temp;

	if (drvif_auto_measure_YUV(ucColor, pMargin, pPosition) != ERROR_SUCCEED) {
		VDC_DEBUG_MSG(VDC_MSG_INIT,"\nError ABORT 0%c", '!');
		return ERROR_ABORT;
	}

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\nmeasure: 0x%x,max: 0x%x\n", *pMargin, ucMax_Target);

	if (*pMargin > ucMax_Target) {
		temp  = *pMargin - ucMax_Target;

		if (scart_auto_vdBrSatchange(display, ucColor, temp, 0)) {               // Decrease Gain; Decrease Contrast
			//....
		}
	} else if (*pMargin < ucMax_Target) {
		temp  = ucMax_Target - *pMargin;

		if (scart_auto_vdBrSatchange(display, ucColor, temp, 1)) {               // Increase Gain; Increase Contrast
			//....
		}
	}
	return ERROR_SUCCEED;//_ERROR_SUCCESS;
}

unsigned short drvif_module_color_scart_adjustment_yuv(unsigned char display)
{
	VDBrConSat *ptVDBrConSat = NULL;
	unsigned short Active_Region[4];
	unsigned short Black_Pos[4], White_Pos[4], Magenta_Pos[4], *ptPos = NULL;
	unsigned short color, result0;
	unsigned short i, count = 0, usMax_Value = 0, rev = 0;

	VDC_DEBUG_MSG(VDC_MSG_INIT,"\n\n==================scart_Adjustment start==================\n\n");

	//initialize the value of br, Sat, cb, and cr
	ptVDBrConSat = &g_scart_VDBrConSat;
	ptVDBrConSat->Brightness2 = 0x80;
	ptVDBrConSat->Contrast2 = 0x80;
	ptVDBrConSat->Cr_saturation = 0x80;
	ptVDBrConSat->Cb_saturation = 0x0;

	//measure the position of Active region for the color bar of black, white, and magenta
	drvif_color_activeregion_dragon(display, &Active_Region[0]);
	drvif_color_smartfit_windows(&Active_Region[0], &Black_Pos[0], &White_Pos[0], &Magenta_Pos[0]);

	for (i = Active_Region[0]; i <= Active_Region[0] + Active_Region[1] - 5; i++)
		VDC_DEBUG_MSG(VDC_MSG_INIT,"%d %d\n", i, drvif_color_finddominant_smartfit_dragon(i, i + 5, White_Pos[2], White_Pos[3], AutoColor_Y));

	//show the info. of position for active region(full screen), white, black, and magenta
	VDC_DEBUG_MSG(VDC_MSG_INIT,"Active_Region=%d,%d,%d,%d\n\n", Active_Region[0], Active_Region[0] + Active_Region[1], Active_Region[2], Active_Region[2] + Active_Region[3]);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"Black_Pos=%d,%d,%d,%d\n", Black_Pos[0], Black_Pos[1], Black_Pos[2], Black_Pos[3]);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"White_Pos=%d,%d,%d,%d\n", White_Pos[0], White_Pos[1], White_Pos[2], White_Pos[3]);
	VDC_DEBUG_MSG(VDC_MSG_INIT,"Magenta_Pos=%d,%d,%d,%d\n\n", Magenta_Pos[0], Magenta_Pos[1], Magenta_Pos[2], Magenta_Pos[3]);

	color = SELECT_BLUE;//SELECT_RED;

	while (TRUE) {
		count = 0x30;

		switch (color) {
		case SELECT_RED:
			usMax_Value = scart_yuv_max_target_level_y;//1016
			ptPos = &White_Pos[0];
			break;
		case SELECT_GREEN:
			usMax_Value = scart_yuv_max_target_level_u;//1016
			ptPos = &Magenta_Pos[0];
			break;
		case SELECT_BLUE:
			usMax_Value = scart_yuv_max_target_level_v;//1016
			ptPos = &Magenta_Pos[0];
			break;
		case SELECT_BLACK:
			usMax_Value = scart_yuv_max_target_level_y_black;
			ptPos = &Black_Pos[0];
			break;
		}

		do {
			rev = drvif_scart_auto_tuneBrSat(display, color, &result0, usMax_Value, ptPos);

			if (rev == ERROR_ABORT)
				goto PROCESS_ERROR;
			if (rev == ERROR_FINISH)
				break;

			if ((ABS(result0, usMax_Value) < 2)) {
				VDC_DEBUG_MSG(VDC_MSG_INIT,"\n 1. result0:%x, usMax_Value:%x\n", result0, usMax_Value);
				break;
			}

			if ((count > 8) && (ABS(result0, usMax_Value) <= 4)) {
				VDC_DEBUG_MSG(VDC_MSG_INIT,"\n 2. result0:%x, usMax_Value:%x\n", result0, usMax_Value);
				count = 8;
			}

		} while (--count);

		if (color == SELECT_BLUE) { //_BLUE)				// 2 : Blue or PB
			color = SELECT_GREEN;//_GREEN;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] green measure start!");
		} else if (color == SELECT_GREEN) { //_GREEN)		// 1: Green or Y
			color = SELECT_RED;//_RED;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] red measure start!");
		} else if (color == SELECT_RED) { // 0: Red or PR
			color = SELECT_BLACK;//_RED;
			VDC_DEBUG_MSG(VDC_MSG_INIT,"\n[SCART auto color] black measure start!");
		} else
			break;
	}

	return ERROR_SUCCEED;

PROCESS_ERROR:

#if 0 //sync from pacific , if auto color fail, let it fail, osd show auto color fail
	ptADCGainOffset->Gain_B = 512;//0x80;
	ptADCGainOffset->Gain_G = 512;//0x80;
	ptADCGainOffset->Gain_R = 512;//0x80;
	ptADCGainOffset->Offset_B = 512;//0x80;
	ptADCGainOffset->Offset_G = 512;//0x80;
	ptADCGainOffset->Offset_R = 512;//0x80;

	drvif_auto_setadcgainoffset(display);
#endif
	VDC_DEBUG_MSG(VDC_MSG_INIT,"\nscart yuv auto color fail\n");
	return ERROR_ABORT;

}

#endif//scart_vdc_auto_balance_en


