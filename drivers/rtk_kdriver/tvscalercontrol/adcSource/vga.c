/* Kernel Header file */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
/* RBUS Header file */
#include <rbus/adc_reg.h>
#include <rbus/adc_smartfit_reg.h>
#include <rbus/sync_processor_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/auto_soy_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/onms_reg.h>

#include <scalercommon/scalerCommon.h>

/* Tvscalercontrol Header file */
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>
#include <tvscalercontrol/scalerdrv/auto.h>
#include <tvscalercontrol/adcsource/ypbpr.h>
#include <tvscalercontrol/adcsource/vga.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
#include "tvscalercontrol/scalerdrv/inprocvga.h"
#include "tvscalercontrol/scalerdrv/mode.h"
#include <tvscalercontrol/scaler/scalerstruct.h>

#include <mach/rtk_log.h>

#define TAG_NAME_ADC "ADC"

/*==================== Definitions ================ */
#define ScalerTimer_DelayXms(mSec)	msleep(mSec)
#define rtdf_outl(offset, val)		IoReg_Write32(offset, val)
#define rtdf_inl(offset)			IoReg_Read32(offset)
#define rtdf_maskl(offset, andMask, orMask)	IoReg_Mask32(offset, andMask, orMask)
/*==================== Variables ================== */
static unsigned char VGADetecSyncTypeMode = SEPARATE_MODE;
static unsigned char VGA_Enable_Asjudt_ClampPulse_In_SS_Type = _DISABLE;
static unsigned char VGA_SUPPORT_SOG_MODE = _ENABLE;
static unsigned char VGA_SUPPORT_COMPOSITE_SYNC_MODE = _ENABLE;

unsigned char VGA_TimingDetectStage = VGA_HVSYNC_STATE;
unsigned char vga_good_timing_ready = FALSE;

/*
 * Add for VGA, rzhen @2017-02-23, START
 */

static StructSourceInput *VGA_input_pt;
extern StructDisplayInfo *Get_ADC_Dispinfo(void);
extern ModeInformationType *Get_ADC_Timinginfo(void);
extern void drvif_mode_print_mode_ID(unsigned char mode);
//extern void drvif_I3DDMA_freeze_enable(unsigned char enable);

static StructScreenModeInfo vga_auto_data[_MODE_PC_TIMING_END + 1] = {0};

#define GET_USER_INPUT_SRC() (Scaler_GetUserInputSrc(SLR_MAIN_DISPLAY))
#define HS_SYNC_SOURCE_CHANGE_MODIFY	1
/*
 * Add for VGA, rzhen @2017-09-20, END
 */

StructScreenModeInfo* get_vga_auto_data(unsigned int timing_index)
{
	 if(timing_index > _MODE_PC_TIMING_END)
	  	return NULL;
	 else
	  return (vga_auto_data + timing_index);
}


unsigned char Scaler_Get_VGA_Support_SOG(void)
{
	return VGA_SUPPORT_SOG_MODE;
}

void Scaler_Set_VGA_Support_SOG(unsigned char ucEnable)
{
	VGA_SUPPORT_SOG_MODE = ucEnable;
}

unsigned char Scaler_Get_VGA_Support_Composite_Sync(void)
{
	return VGA_SUPPORT_COMPOSITE_SYNC_MODE;
}

void  Scaler_Set_VGA_Support_Composite_Sync(unsigned char ucEnable)
{
	VGA_SUPPORT_COMPOSITE_SYNC_MODE = ucEnable;
}


void VGA_DCRestore_Ctrl(unsigned char enable, ADC_DATA_PATH adc_path)
{
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;

	if (enable) {

		adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);

		switch(adc_path){
			case ADC_DATA_INPUT0:
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6= 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3= 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2  = 1; //B channel DC restore enable (0:disable	1:enable)
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0= 3; //B channel DC restore select (00: VIN0P, 01: VIN3P, 10: VIN6P, 11: X)
				break;

			case ADC_DATA_INPUT1:
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6= 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5  = 1; //G channel DC restore enable (0:disable	1:enable)
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3= 3; //G channel DC restore select (00: VIN1P, 01: VIN4P, 10: VIN7P, 11: X)
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0= 0;
				break;

			case ADC_DATA_INPUT2:
			default:
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8  = 1; //R channel DC restore enable (0:disable	1:enable)
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6= 3; //R channel DC restore select (00: VIN2P, 01: VIN5P, 10: VIN8P, 11: X)
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3= 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2  = 0;
				adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0= 0;
				break;
		}

		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
	} else {

		adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);

		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8  = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6= 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5  = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3= 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2  = 0;
		adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0= 0;

		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
	}
}

void VGA_Clamp_Ctrl(unsigned char output_enable, ADC_DATA_PATH adc_path, ADC_SOY_PATH soy_path)
{
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;

	adc_adc_clamp_ctrl2_reg.regValue = 0;
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_7_4 = soy_path;
	adc_adc_clamp_ctrl2_reg.adc_sog_cmp_3_0 = soy_path;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

#ifdef ADC_UP_DOWN_CLAMP
	if(output_enable){
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);

		SyncProc_Updw_Clamp_Ctrl(_SRC_VGA);

		SyncProc_Updw_Clamp_Enable(_ENABLE);

		/* VDC UP/DN 0: disable  1:enable */
		/* [8:0]=R,R,G,G,B,B */
		adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 1;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
		adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

		/* Voltage clamp negative G channel enable */
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 0;//VINGN
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
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8   = 1; //R channel voltage clamp enable (0:disable  1:enable)
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0; //R channel voltage clamp select (00: VIN2P, 01: VIN5P, 10: VIN8P, 11: X)
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5   = 1; //G channel voltage clamp enable (0:disable  1:enable)
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0; //G channel voltage clamp select (00: VIN1P, 01: VIN4P, 10: VIN7P, 11: X)
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2   = 1; //B channel voltage clamp enable (0:disable  1:enable)
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0; //B channel voltage clamp select (00: VIN0P, 01: VIN3P, 10: VIN6P, 11: X)
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);
	} else {

		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.regValue &= 0xfffffe00;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);
	}
#endif
}

void drvif_vga_init_table(void)
{
	sync_processor_sp_adc_out_sel_RBUS sync_processor_sp_adc_out_sel_reg;
	sync_processor_sp1_clmpmsk_RBUS sync_processor_sp1_clmpmsk_reg;
	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	abl_abl_ctrl_RBUS abl_abl_ctrl_reg;
	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;
	dds_pll_plldiv_RBUS dds_pll_plldiv_reg;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_dds_mix_w2_RBUS dds_pll_dds_mix_w2_reg;
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	sync_processor_sp1_dcnt_RBUS sync_processor_sp1_dcnt_reg;
	sync_processor_sp1_clmpctrl_RBUS sync_processor_sp1_clmpctrl_reg;
	sync_processor_sp1_clmp_RBUS sync_processor_sp1_clmp_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
	adc_adc_clock_RBUS adc_adc_clock_reg;
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	adc_smartfit_adc_auto_field_RBUS adc_smartfit_adc_auto_field_reg;

	sync_processor_sp_adc_out_sel_reg.regValue = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg,sync_processor_sp_adc_out_sel_reg.regValue);


	sync_processor_sp1_clmpmsk_reg.regValue = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg,sync_processor_sp1_clmpmsk_reg.regValue);// CSW+ 0961204 for clamp mask disable

	/* MSB delay turn on */
	adc_adc_vbias_reg.regValue = 0;
	adc_adc_vbias_reg.adc_vbias0_0 = 1;/*ADC Sample 011 */
	adc_adc_vbias_reg.adc_vbias0_1 = 0;/* LDO voltage select 011:1.1v bit[7:5]=101 bit[4:2]=010 bit0=1*/
	adc_adc_vbias_reg.adc_vbias0_4_2 = 2;
	adc_adc_vbias_reg.adc_vbias0_7_5 = 5;
	adc_adc_vbias_reg.adc_vbias1_0= 0;
	adc_adc_vbias_reg.adc_vbias1_1= 0;
	adc_adc_vbias_reg.adc_vbias1_3_2= 0;
	adc_adc_vbias_reg.adc_vbias1_5_4 = 0;/*SAR_ADC_Gain 1.7 bit15 and bit14 = 1*/
	adc_adc_vbias_reg.adc_vbias1_6 = 1;
	adc_adc_vbias_reg.adc_vbias1_7 = 1;
	adc_adc_vbias_reg.adc_vbias2_2_0 = 3;/* ADC Gain Calibration Gain_Cal_DAC3B Voltage, 011:0.7V */
	adc_adc_vbias_reg.adc_vbias3_1_0 = 1;/* bandgap voltage select */
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	dds_pll_pll_set_reg.regValue = 0;
	dds_pll_pll_set_reg.pll_m = 21;//[To DDS] PLLM [7:0] (PLL DPM value - 3)
	dds_pll_pll_set_reg.pll_n = 1;// REG_PLLSN in APLL (PLL DPN value - 2)
	dds_pll_pll_set_reg.pllssi = 3;//PLL Charger Pump Current IchDpll
	dds_pll_pll_set_reg.pllsrs = 3;//10K
	IoReg_Write32(DDS_PLL_PLL_SET_reg,dds_pll_pll_set_reg.regValue);//forster modified 071116

	abl_abl_ctrl_reg.regValue = 0;
	IoReg_Write32(ABL_ABL_CTRL_reg,abl_abl_ctrl_reg.regValue);//Disable ABL first

#ifdef CONFIG_APLL_PROTECT
	dds_pll_pll_ctrl_reg.regValue = 0;
	dds_pll_pll_ctrl_reg.pllpwdn = 1;//REG_APLLPWDN (PLL Power Down) 1: Power Down
	dds_pll_pll_ctrl_reg.apll_reg = 1;//REG_APLL_REG<1:0> V16 setting 01:1.68V (default)
	dds_pll_pll_ctrl_reg.pllswdrst = 1;//REG_PLLSWDRST (PLL WD Reset) 1: Reset
	dds_pll_pll_ctrl_reg.adckmode = 1;//ADCKMODE [1:0] (ADC Input Clock Select Mode) 01: Single Inverse-Clock Mode
	dds_pll_pll_ctrl_reg.apllldosel =1;//LDO reference voltage setting  01:1.1V(default);
	dds_pll_pll_ctrl_reg.apllldopow = 1;//LDO Power 1:Power on
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	dds_pll_pll_ctrl_reg.pllpwdn = 0;//REG_APLLPWDN (PLL Power Down) 0: Normal Run
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	msleep(1);
	dds_pll_pll_ctrl_reg.pllswdrst = 0;//REG_PLLSWDRST (PLL WD Reset) 0: Normal
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
#else
	dds_pll_pll_ctrl_reg.regValue = 0;
	dds_pll_pll_ctrl_reg.pllpwdn = 0;//REG_APLLPWDN (PLL Power Down) 0: Normal Run
	dds_pll_pll_ctrl_reg.apll_reg = 1;//REG_APLL_REG<1:0> V16 setting 01:1.68V (default)
	dds_pll_pll_ctrl_reg.pllswdrst = 0;//REG_PLLSWDRST (PLL WD Reset) 0: Normal
	dds_pll_pll_ctrl_reg.adckmode = 1;//ADCKMODE [1:0] (ADC Input Clock Select Mode) 01: Single Inverse-Clock Mode
	dds_pll_pll_ctrl_reg.apllldosel =1;//LDO reference voltage setting  01:1.1V(default);
	dds_pll_pll_ctrl_reg.apllldopow = 1;//LDO Power 1:Power on
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
#endif

	dds_pll_plldiv_reg.regValue = 0;
	dds_pll_plldiv_reg.pll_divider = 1687;//Divider=1687 = 0x697
	dds_pll_plldiv_reg.apll_reserve = 2;//floating input now (reserve) 01: test V11
	IoReg_Write32(DDS_PLL_PLLDIV_reg, dds_pll_plldiv_reg.regValue);

	//[scaler][code sync]
	adc_smartfit_adc_auto_field_reg.regValue = 0;
	adc_smartfit_adc_auto_field_reg.adj_source = 0;//pll_setting mux. 0: from ADC smfit. 1: from I domain smfit.
 	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, adc_smartfit_adc_auto_field_reg.regValue);

	adc_smartfit_adc_pllphase_ctrl_reg.regValue = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut =1;//Phase_Select_Method 1: Look-Up-Table
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	dds_pll_pllphase_ctrl_reg.regValue = 0;
	dds_pll_pllphase_ctrl_reg.pllsph0path =1;//REG_PLLSPH0PATH 1: Long Path (to compensate PLL_ADC path delay)
	IoReg_Write32(DDS_PLL_PLLPHASE_CTRL_reg, dds_pll_pllphase_ctrl_reg.regValue);

	//[scaler][code sync]
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = 1;//MSB of 128 phase (Only for ADC CLK=1/4 VCO CLK)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2x = 1;//[To Smart Fit] PLLX (PLL X Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2y = 1;//[To Smart Fit] PLLY (PLL Y Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 1;//[To Smart Fit] PLLD2 1:ADC CLK=1/4 VCO CLK
	//adc_smartfit_adc_pllphase_ctrl_reg.pllsph0path =1;//REG_PLLSPH0PATH 1: Long Path (to compensate PLL_ADC path delay)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut =1;//Phase_Select_Method 1: Look-Up-Table
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	dds_pll_dds_mix_w1_reg.regValue = 0;
	dds_pll_dds_mix_w1_reg.p_code_max = 65535;//Set p_code_max value to clamp the GAIN of APLL 65535 = 0xffff
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);// P code max=316321 and new mode disable

	dds_pll_dds_mix_w2_reg.regValue = 0;
	dds_pll_dds_mix_w2_reg.sample_period = 2;//Phase error sample period choose 10: every 3 cycle sample
	dds_pll_dds_mix_w2_reg.delay_chain_length =2;//Delay chain length select  10: cnt= 33 => 209.9ns (default)
	dds_pll_dds_mix_w2_reg.change_mode_th = 2;//To judge when to increase a counter for pll_lock judgement 3'b010: change_mode_final = 12'd1571
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, dds_pll_dds_mix_w2_reg.regValue);

#ifdef CONFIG_VGA_HS_FROM_FBHS
	sync_processor_sp1_ctrl_reg.regValue = 0;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel = 2;//Input HS/VS/SOY Source Selection pad_hs1,pad_vs1
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;//Hysnc Type Detection Auto Run 1: automatic (Auto_Run mode)
	sync_processor_sp1_ctrl_reg.s1_hs_sync_source = 1;//HSYNC Synchronize source 1: FBHS - Feedback HS
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
#else //#ifdef CONFIG_VGA_HS_FROM_FBHS
	sync_processor_sp1_ctrl_reg.regValue = 0;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel = 2;//Input HS/VS/SOY Source Selection pad_hs1,pad_vs1
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;//Hysnc Type Detection Auto Run 1: automatic (Auto_Run mode)
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
#endif //#ifdef CONFIG_VGA_HS_FROM_FBHS


	sync_processor_sp1_dcnt_reg.regValue = 0;
	sync_processor_sp1_dcnt_reg.s1_dcnt_level = 384;//Vsync detection counter initial value. 0x180 = 384
	sync_processor_sp1_dcnt_reg.s1_deb_num = 1;//Chroma Canceling debounce length selection 00001: 1 crystal clock
	IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);

	sync_processor_sp1_clmp_reg.regValue = 0;
	sync_processor_sp1_clmp_reg.s1_nyclamp_end = 16;//End of Output Clamp Signal Pulse for Pb/B and Pr/R channel
	sync_processor_sp1_clmp_reg.s1_nyclamp_sta= 4;//Start of Output Clamp Signal Pulse for Pb/B and Pr/R channel
	sync_processor_sp1_clmp_reg.s1_yclamp_end = 16;//End of Output Clamp Signal Pulse for Y/G channel
	sync_processor_sp1_clmp_reg.s1_yclamp_sta= 4;//Start of Output Clamp Signal Pulse for Y/G channel
	IoReg_Write32(SYNC_PROCESSOR_SP1_CLMP_reg, sync_processor_sp1_clmp_reg.regValue);

	adc_adc_clamp_ctrl3_reg.regValue = 0;
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_14_13 =3;//SOG_ADC_CMP bias current 11: 60£gA
	IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);

	adc_adc_clock_reg.regValue = 0;
	adc_adc_clock_reg.adc_clock_1_0 = 3;//Duty cycle 11: 52%
	adc_adc_clock_reg.adc_2x_sample_0 = 1;//Online Auto SOY ADC clock select 1: CKAPLL<1:0>
	adc_adc_clock_reg.adc_2x_sample_5 = 1;//RGB 1X Output Clock (ADC_CLK_1X) Polarity  1:Positive
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);

	adc_adc_ctl_rgb12_reg.regValue = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 0; /*Dac Source Separate Voltage mode*/
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_6 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_7 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_8 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_9 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_11_10 = 0;
	IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);
}

void VGA_Negative_Clamp_DACSource(void)
{
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;

	/* ADC negative clamp setting, clamp DAC source select, Vmid/Voffset initial */
	adc_adc_clamp_ctrl0_reg.regValue = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;
	/* UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11 */
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

	/* ADC intinal Clamp DAC source select */
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


/* Because DVI / HDMI source, the data enable is define by smart-fit */
/* not adjust by mode table, so sw need to check front porch */
/* don't smaller than _VGIP_V_FRONT_PORCH_MIN */
void fw_dvi_frc_setting(void)
{
}

void VGA_Detect_SyncType_Init(void)
{
	/* lewis 20090407, initial value set as SOG_MODE, when we first enter VGA_SyncProc_Init() */
	/* it will search SEPARATE_MODE at first */
	if ((_ENABLE == Scaler_Get_VGA_Support_SOG()) || (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync())) {
		VGADetecSyncTypeMode = SOG_MODE;
	} else {
		VGADetecSyncTypeMode = SEPARATE_MODE;
	}
}

unsigned char VGA_Detect_SyncTypeMode(void)
{
	return VGADetecSyncTypeMode;
}


void VGA_SyncProc_Init(void)
{
	sync_processor_sp1_clmpctrl_RBUS SP1_CLMPCTRL_register;
	sync_processor_sp1_clmpmsk_RBUS SP1_CLMPMSK_register;
	sync_processor_sp1_stbctrl_RBUS SP1_StbCtrl_reg;
	sync_processor_sp1_ctrl_RBUS SP1_CTRL_register;

	if ((_ENABLE == Scaler_Get_VGA_Support_SOG()) || (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync())) {
		YPbPr_ABL_SETTING_OFF();
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		if (_ENABLE == Scaler_Get_VGA_Support_SOG()) {
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			if (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync()) {
				VGADetecSyncTypeMode = (VGADetecSyncTypeMode + 1)%VGA_SYNC_DETECT_MODE;
			} else {
				/* only SOG and Separate sync */
				if (SEPARATE_MODE == VGADetecSyncTypeMode) {
					VGADetecSyncTypeMode = SOG_MODE;
				} else {
					VGADetecSyncTypeMode = SEPARATE_MODE;
				}
			}
		} else {
			/* only Composite and Separate sync */
			if (SEPARATE_MODE == VGADetecSyncTypeMode) {
				VGADetecSyncTypeMode = CS_ON_H_MODE;
			} else {
				VGADetecSyncTypeMode = SEPARATE_MODE;
			}
		}

		switch (VGADetecSyncTypeMode) {
		case SOG_MODE:/* SOG sync type */
			YPbPr_SetClampPulse(VGA_SP_PATH, 0x10, 0x15, 0x10, 0x15, CLAMP_ALL);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				/* Lewis, 20090120, it have double buffer, SOG type need disable clamp first */
				/* enable CLAMP signal output and select leading edge of HS for VGA(SOG), XTal_clk */
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
				SP1_CLMPCTRL_register.regValue = 0;
				SP1_CLMPCTRL_register.s1_clamp_dben = 0;
				SP1_CLMPCTRL_register.s1_clamp_cnt_unit = SOG_CLAMP_CNT_UNIT;
				SP1_CLMPCTRL_register.s1_clamp_clksrc = SOG_CLAMP_CLKSRC;
				SP1_CLMPCTRL_register.s1_clamp_en = _DISABLE;
				SP1_CLMPCTRL_register.s1_yclamp_hs_inv = SOG_CLAMP_Y_REF_EDGE;
				SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = SOG_CLAMP_NY_REF_EDGE;
				SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
				SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				/* enable load double buffer */
				SP1_CLMPCTRL_register.s1_clamp_dben = 1;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				SP1_CLMPMSK_register.regValue = 0;
				SP1_CLMPMSK_register.s1_mask_clamp_en = _ENABLE;
				SP1_CLMPMSK_register.s1_mask_front = 2;
				SP1_CLMPMSK_register.s1_mask_back = 1;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, SP1_CLMPMSK_register.regValue);

				/* set capture window size */
				SP1_StbCtrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
				SP1_StbCtrl_reg.s1_cap_win_range_lsb = VGA_CAP_WIN_RANGE_SOG_LSB_INIT;
				SP1_StbCtrl_reg.s1_cap_win_range = VGA_CAP_WIN_RANGE_SOG_INIT;
				IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, SP1_StbCtrl_reg.regValue);

				SP1_CTRL_register.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_register.s1_vhs_source_sel = SP_VHS_SOURCE_SOY_0 + VGA_SOG_PATH_SELECT;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_register.regValue);
			}

			rtd_printk(KERN_INFO, TAG_NAME_ADC, "In VGA_SyncProc_Init, switch to SOG type!\n");
			break;

		case SEPARATE_MODE:/* Seperate type */
		case CS_ON_H_MODE:/* Composite sync type */
			YPbPr_SetClampPulse(VGA_SP_PATH, 0x04, 0x10, 0x04, 0x10, CLAMP_ALL);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				/* Lewis, 20090120, it have double buffer, SOG type need disable clamp first */
				/* enable CLAMP signal output and select leading edge of HS for VGA(SOG), XTal_clk */
				SP1_CLMPCTRL_register.regValue = 0;
				SP1_CLMPCTRL_register.s1_clamp_dben = 0;
				SP1_CLMPCTRL_register.s1_clamp_cnt_unit = VGA_CLAMP_CNT_UNIT;
				SP1_CLMPCTRL_register.s1_clamp_clksrc = VGA_CLAMP_CLKSRC;
				SP1_CLMPCTRL_register.s1_clamp_en = _ENABLE;
				SP1_CLMPCTRL_register.s1_yclamp_hs_inv = VGA_CLAMP_Y_REF_EDGE;
				SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = VGA_CLAMP_NY_REF_EDGE;
				SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
				SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				/* enable load double buffer */
				SP1_CLMPCTRL_register.s1_clamp_dben = 1;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, 0x00);

				/* De-Composite HS out in CS mode, disable coast */
				if (CS_ON_H_MODE == VGADetecSyncTypeMode) {
					/* set capture window size */
					SP1_StbCtrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
					SP1_StbCtrl_reg.s1_cap_win_range_lsb = VGA_CAP_WIN_RANGE_CS_LSB_INIT;
					SP1_StbCtrl_reg.s1_cap_win_range = VGA_CAP_WIN_RANGE_CS_INIT;
					IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, SP1_StbCtrl_reg.regValue);

					SP1_CTRL_register.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
					SP1_CTRL_register.s1_dehs_out_en = 1;
					SP1_CTRL_register.s1_vhs_source_sel = SP_VHS_SOURCE_PAD_HS1VS1; /* Force to seperate type */
					IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_register.regValue);

					rtd_printk(KERN_INFO, TAG_NAME_ADC, "In VGA_SyncProc_Init, switch to Composite Sync type!\n");
				} else {/* if (SEPARATE_MODE == VGADetecSyncTypeMode) */
					/* set capture window size */
					SP1_StbCtrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
					SP1_StbCtrl_reg.s1_cap_win_range_lsb = VGA_CAP_WIN_RANGE_SS_LSB_INIT;
					SP1_StbCtrl_reg.s1_cap_win_range = VGA_CAP_WIN_RANGE_SS_INIT;
					IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, SP1_StbCtrl_reg.regValue);

					SP1_CTRL_register.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
					SP1_CTRL_register.s1_dehs_out_en = 1;
					SP1_CTRL_register.s1_vhs_source_sel = SP_VHS_SOURCE_PAD_HS1VS1; /* Force to seperate type */
					IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_register.regValue);

					rtd_printk(KERN_INFO, TAG_NAME_ADC, "In VGA_SyncProc_Init, switch to Separate Sync type!\n");
				}

			}
			break;

		default:
			break;
		}
	} else {/* if ((_DISABLE == Scaler_Get_VGA_Support_SOG()) && (_DISABLE == Scaler_Get_VGA_Support_Composite_Sync())) */
		/* Issue description		: 0017655: [Video]Strange color is shown on some D-SUB input. */
		/* to prevent SyncProc_FunctionDisable() to disable SYNCPROCESSOR_SP1_CLMPCTRL_VADDR[4], let SS sync type */
		/* with SOG, the color abnormal */
		YPbPr_SetClampPulse(VGA_SP_PATH, 0x04, 0x10, 0x04, 0x10, CLAMP_ALL);
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
			/* Lewis, 20090120, it have double buffer, SOG type need disable clamp first */
			/* enable CLAMP signal output and select leading edge of HS for VGA(SOG), XTal_clk */
			SP1_CLMPCTRL_register.regValue = 0;
			SP1_CLMPCTRL_register.s1_clamp_dben = 0;
			SP1_CLMPCTRL_register.s1_clamp_cnt_unit = VGA_CLAMP_CNT_UNIT;
			SP1_CLMPCTRL_register.s1_clamp_clksrc = VGA_CLAMP_CLKSRC;
			SP1_CLMPCTRL_register.s1_clamp_en = _ENABLE;
			SP1_CLMPCTRL_register.s1_yclamp_hs_inv = VGA_CLAMP_Y_REF_EDGE;
			SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = VGA_CLAMP_NY_REF_EDGE;
			SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
			SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
			IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

			/* enable load double buffer */
			SP1_CLMPCTRL_register.s1_clamp_dben = 1;
			IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

			IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, 0x00);

			/* set capture window size */
			SP1_StbCtrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
			SP1_StbCtrl_reg.s1_cap_win_range_lsb = VGA_CAP_WIN_RANGE_SS_LSB_INIT;
			SP1_StbCtrl_reg.s1_cap_win_range = VGA_CAP_WIN_RANGE_SS_INIT;
			IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, SP1_StbCtrl_reg.regValue);

			SP1_CTRL_register.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
			SP1_CTRL_register.s1_dehs_out_en = 1;
			SP1_CTRL_register.s1_vhs_source_sel = SP_VHS_SOURCE_PAD_HS1VS1; /* Force to seperate type */
			IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_register.regValue);

			rtd_printk(KERN_INFO, TAG_NAME_ADC, "In VGA_SyncProc_Init, switch to Separate Sync type!\n");

		}
	}
}

void VGA_ABL_Enable_Control(unsigned char ctrl)
{
	abl_abl_ctrl_RBUS abl_ctrl_reg;
	abl_ctrl_reg.regValue = IoReg_Read32(ABL_ABL_CTRL_reg);
	abl_ctrl_reg.abl_en = ctrl;
	abl_ctrl_reg.abl_red_en = ctrl;
	abl_ctrl_reg.abl_grn_en = ctrl;
	abl_ctrl_reg.abl_blu_en = ctrl;
	IoReg_Write32(ABL_ABL_CTRL_reg, abl_ctrl_reg.regValue);

}

void VGA_ABL_SETTING_ON(unsigned short Hstart)
{
	abl_abl_window_RBUS abl_window_reg;
	abl_abl_ctrl_RBUS abl_ctrl_reg;
	abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
	abl_abl_mgn_b_RBUS abl_mgn_b_reg;
	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;



	VGA_ABL_Enable_Control(_DISABLE);


	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset0_reg.adc_off_grn = 0x200;
	adc_offset0_reg.adc_off_red = 0x200;
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);

	adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	adc_offset1_reg.adc_off_blu = 0x200;
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);

	abl_window_reg.regValue = 0;
	abl_window_reg.abl_vend = VGA_SOG_ABL_V_END;
	abl_window_reg.abl_wait_line = VGA_SOG_ABL_WAIT_LINE;
	abl_window_reg.abl_vsta = VGA_SOG_ABL_V_START;
	abl_window_reg.abl_line = VGA_SOG_ABL_LINE_AVG;
	abl_window_reg.abl_h_width = VGA_SOG_ABL_H_WIDTH;
	abl_window_reg.abl_start_pos = Hstart;
	IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);

	abl_mgn_rg_reg.regValue = 0;
	abl_mgn_rg_reg.abl_eq_mgn_red = VGA_SOG_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_rg_reg.abl_l_mgn_red = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_red = VGA_SOG_ABL_LOCK_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_grn = VGA_SOG_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_rg_reg.abl_l_mgn_grn = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_grn = VGA_SOG_ABL_LOCK_MARGIN;

	IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);


	abl_mgn_b_reg.regValue = 0;
	abl_mgn_b_reg.abl_eq_mgn_blu = VGA_SOG_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_b_reg.abl_l_mgn_blu = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_b_reg.abl_lock_mgn_blu = VGA_SOG_ABL_LOCK_MARGIN;
	IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);


	abl_ctrl_reg.regValue = 0;
	abl_ctrl_reg.abl_en = _ENABLE;
	abl_ctrl_reg.abl_red_en = _ENABLE;
	abl_ctrl_reg.abl_grn_en = _ENABLE;
	abl_ctrl_reg.abl_blu_en = _ENABLE;
	abl_ctrl_reg.abl_software_mode = 0;
	abl_ctrl_reg.abl_min_measure = 0;
	abl_ctrl_reg.abl_ypbpr_en = 0;
	abl_ctrl_reg.abl_online_mode = 1;
	abl_ctrl_reg.abl_max_frame = 0;
	abl_ctrl_reg.abl_r_dir_inv = 0;
	abl_ctrl_reg.abl_g_dir_inv = 0;
	abl_ctrl_reg.abl_b_dir_inv = 0;
	abl_ctrl_reg.abl_href_sel = 0;
	abl_ctrl_reg.abl_target_value = _ABL_VGA_TARGET_VALUE;
	IoReg_Write32(ABL_ABL_CTRL_reg, abl_ctrl_reg.regValue);

}


/* set ABL margin setting at later, let picture more stable */
void VGA_ABL_Margin_Setting(void)
{
	abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
	abl_abl_mgn_b_RBUS abl_mgn_b_reg;
	abl_mgn_rg_reg.regValue = IoReg_Read32(ABL_ABL_MGN_RG_reg);
	abl_mgn_rg_reg.abl_eq_mgn_red = VGA_SOG_ABL_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_l_mgn_red = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_red = VGA_SOG_ABL_LOCK_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_grn = VGA_SOG_ABL_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_l_mgn_grn = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_grn = VGA_SOG_ABL_LOCK_MARGIN;
	IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);
	abl_mgn_b_reg.regValue = IoReg_Read32(ABL_ABL_MGN_B_reg);
	abl_mgn_b_reg.abl_eq_mgn_blu = VGA_SOG_ABL_EQUAL_MARGIN;
	abl_mgn_b_reg.abl_l_mgn_blu = VGA_SOG_ABL_LARGE_MARGIN;
	abl_mgn_b_reg.abl_lock_mgn_blu = VGA_SOG_ABL_LOCK_MARGIN;
	IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);
}

void VGA_ADCPowerControl(unsigned char on_off)
{
	adc_adc_power_RBUS adc_power_reg;
	adc_ahs_smt_ctrl_RBUS ahs_smt_ctrl_reg;
	adc_adc_clamp_ctrl1_RBUS adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_clamp_ctrl3_reg;
	dds_pll_pll_ctrl_RBUS pll_ctrl_reg;
	
#ifdef CONFIG_DUAL_CHANNEL
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	ppoverlay_mp_layout_force_to_background_RBUS mp_layout_force_to_background_reg;

	mp_layout_force_to_background_reg.regValue = IoReg_Read32(PPOVERLAY_MP_Layout_Force_to_Background_reg);
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
#endif /* #ifdef CONFIG_DUAL_CHANNEL */

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####[%s(%d)]\n", __func__, __LINE__);
	if (TRUE == on_off) {
#ifdef CONFIG_DUAL_CHANNEL
		adc_power_reg.regValue = IoReg_Read32(ADC_ADC_POWER_reg);
	#ifdef VGA_ENABLE_AUTO_SOY
		/* lewis 20091030 modify, for VGA water noise */
		if ((_ENABLE == Scaler_Get_VGA_Support_SOG()) || (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync())) {
			if (SEPARATE_MODE == VGA_Detect_SyncTypeMode()) {
				adc_power_reg.adc_power_7 = 0;
			} else {
				adc_power_reg.adc_power_7 = 1;
			}
		} else {
			adc_power_reg.adc_power_7 = 0;
		}
	#else /* #ifdef VGA_ENABLE_AUTO_SOY */
		adc_power_reg.adc_power_7 = 0;
	#endif /* #ifdef VGA_ENABLE_AUTO_SOY */

		adc_power_reg.adc_power_6 = 1;
		if (VGA_SOG_PATH_SELECT == SP_VHS_SOURCE_SOY0) {
			adc_power_reg.adc_power_5 = 1;
			adc_power_reg.adc_power_4 = 0;
		} else if (VGA_SOG_PATH_SELECT == SP_VHS_SOURCE_SOY1) {
			adc_power_reg.adc_power_5 = 0;
			adc_power_reg.adc_power_4 = 1;
		}
		adc_power_reg.adc_power_3 = 1;
		adc_power_reg.adc_power_2 = 1; /* Red Channel ADC Power On */
		adc_power_reg.adc_power_1 = 1; /* Green Channel ADC Power On */
		adc_power_reg.adc_power_0 = 1; /* Blue Channel ADC Power On */
		IoReg_Write32(ADC_ADC_POWER_reg, adc_power_reg.regValue);
		adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
		adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_clamp_ctrl3_reg.regValue);

#else /* #ifdef CONFIG_DUAL_CHANNEL */
		adc_power_reg.regValue = IoReg_Read32(ADC_ADC_POWER_reg);

	#ifdef VGA_ENABLE_AUTO_SOY
		/* lewis 20091030 modify, for VGA water noise */
		if ((_ENABLE == Scaler_Get_VGA_Support_SOG()) || (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync())) {
			if (SEPARATE_MODE == VGA_Detect_SyncTypeMode()) {
				adc_power_reg.adc_power_7 = 0;
			} else {
				adc_power_reg.adc_power_7 = 1;
			}
		} else {
			adc_power_reg.adc_power_7 = 0;
		}
	#else /* #ifdef VGA_ENABLE_AUTO_SOY */
		adc_power_reg.adc_power_7 = 0;
	#endif /* #ifdef VGA_ENABLE_AUTO_SOY */

		adc_power_reg.adc_power_6 = 1;
		if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY0) {
			adc_power_reg.adc_power_5 = 1;
			adc_power_reg.adc_power_4 = 0;
		} else if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY1) {
			adc_power_reg.adc_power_5 = 0;
			adc_power_reg.adc_power_4 = 1;
		}
		adc_power_reg.adc_power_3 = 1;
		adc_power_reg.adc_power_2 = 1; /* Red Channel ADC Power On */
		adc_power_reg.adc_power_1 = 1; /* Green Channel ADC Power On */
		adc_power_reg.adc_power_0 = 1; /* Blue Channel ADC Power On */
		IoReg_Write32(ADC_ADC_POWER_reg, adc_power_reg.regValue);
		adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
		adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 1;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_clamp_ctrl3_reg.regValue);
#endif /* #ifdef CONFIG_DUAL_CHANNEL */
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####[%s(%d)] HSYNC PAD power on\n", __func__, __LINE__);
		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_pwdn = 0; /* HSYNC Power On */
		ahs_smt_ctrl_reg.hsync0_3ven = 1; /* 1: Power on */
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
	} else {
#ifdef CONFIG_DUAL_CHANNEL
		if (0 == mp_layout_force_to_background_reg.s_disp_en) {/* it means PIP OFF */
			adc_power_reg.regValue = 0;
			adc_power_reg.adc_power_3 = 1;
			IoReg_Write32(ADC_ADC_POWER_reg, adc_power_reg.regValue);
		} else {
			adc_power_reg.regValue = IoReg_Read32(ADC_ADC_POWER_reg);
			adc_power_reg.adc_power_7 = 0;
			adc_power_reg.adc_power_5 = 0;
			adc_power_reg.adc_power_4 = 0;
			adc_power_reg.adc_power_3 = 1;
			adc_power_reg.adc_power_2 = 0;
			adc_power_reg.adc_power_1 = 0;
			adc_power_reg.adc_power_0 = 0;
			IoReg_Write32(ADC_ADC_POWER_reg, adc_power_reg.regValue);
		}
#else /* #ifdef CONFIG_DUAL_CHANNEL */
		adc_power_reg.regValue = 0;
		adc_power_reg.adc_power_3 = 1;
		IoReg_Write32(ADC_ADC_POWER_reg, adc_power_reg.regValue);
#endif /* #ifdef CONFIG_DUAL_CHANNEL */
		/* APLL power down */
		pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
		pll_ctrl_reg.pllpwdn = 1;	/* PLL power down */
		IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);

		/* Clamp disable */
		/* Clamp Enable 0: disable	1:enable */
		adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8   = 0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5   = 0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2   = 0;
		adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_clamp_ctrl1_reg.regValue);

		/* VDC UP/DN disable */
		/* VDC UP/DN 0: disable  1:enable */
		adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8   = 0;
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5   = 0;
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2   = 0;
		adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_clamp_ctrl2_reg.regValue);

		adc_clamp_ctrl3_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
		adc_clamp_ctrl3_reg.adc_clamp_ctrl5_12 = 0;		/* david add */
		IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_clamp_ctrl3_reg.regValue);

		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####[%s(%d)] HSYNC PAD power down\n", __func__, __LINE__);

		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_pwdn = 1; /* HSYNC Power Down */
		ahs_smt_ctrl_reg.hsync0_3ven = 0; /* 0: Power down */
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
	}
	
}

/* fix SOG type, the G channel have sync, let clamp pulse error */
/* the picture have little green, modify clamp pulse */
unsigned char  Scaler_Get_VGA_Enable_Asjudt_ClampPulse_In_SS_Type(void)
{
	return VGA_Enable_Asjudt_ClampPulse_In_SS_Type;
}

void  Scaler_Set_VGA_Enable_Asjudt_ClampPulse_In_SS_Type(unsigned char ucEnable)
{
	VGA_Enable_Asjudt_ClampPulse_In_SS_Type = ucEnable;
}


/**
 * This API is used to set the VGA mode related setting
 * enable ABL¡Benable ADC
 * @param [input] : None
 * @param [output] : None
 *
 *
 * @return None
 *
 */
void VGA_SP_ModeSetting(void)
{
#if 1
	sync_processor_sp1_clmpctrl_RBUS SP1_CLMPCTRL_register;

	if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
		/* enable CLAMP signal output */
		SP1_CLMPCTRL_register.regValue = 0;
		SP1_CLMPCTRL_register.s1_clamp_dben = _DISABLE;
		SP1_CLMPCTRL_register.s1_clamp_cnt_unit = VGA_CLAMP_CNT_UNIT;
		SP1_CLMPCTRL_register.s1_clamp_clksrc = VGA_CLAMP_CLKSRC;
		SP1_CLMPCTRL_register.s1_clamp_en = _ENABLE;
		SP1_CLMPCTRL_register.s1_yclamp_hs_inv = VGA_CLAMP_Y_REF_EDGE;
		SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = VGA_CLAMP_NY_REF_EDGE;
		SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
		SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

		/* enable load double buffer */
		SP1_CLMPCTRL_register.s1_clamp_dben = _ENABLE;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);
	}
#else
	ADC_INITIAL_OPTIONS  *ptOptions;
	unsigned int usHighPulsePeriod = 0, usStablePeriod = 0;
	unsigned short usClampHStart = 0, usClampHEnd = 0;
	unsigned int usADCClock = 0;
	unsigned short usABL_Hstart = 0;
	auto_soy_soych1_a0_RBUS auto_soy_soych1_a0_reg;
	auto_soy_soych0_a3_RBUS auto_soy_soych0_a3_reg;
	adc_adc_vbias_RBUS adc_vbias_reg;
	sync_processor_sp1_stbrst1_RBUS SP1_StbRst1_reg;
	sync_processor_sp1_clmpctrl_RBUS SP1_CLMPCTRL_register;

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####[%s(%d)]\n", __func__, __LINE__);
	if (_ENABLE == Scaler_Get_VGA_Support_SOG()) {
		/* only SOG timing need apply */
		if (SOG_MODE == VGADetecSyncTypeMode) {
			ptOptions = (ADC_INITIAL_OPTIONS  *)srcinput_pt->InitOptions;

			/* Get H sync high pulse period */
			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				SP1_StbRst1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst1_reg);
				usStablePeriod = SP1_StbRst1_reg.s1_stable_period_out;
				usHighPulsePeriod = SP1_StbRst1_reg.s1_stable_plswid_out;
			}

			if (usStablePeriod < usHighPulsePeriod) {
				usHighPulsePeriod = usStablePeriod;
			}
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]usHighPulsePeriod Pre= 0x%08x\n", __func__, __LINE__, usHighPulsePeriod);

			/* 500 ns ~= 13.5 crystal clock */
			usClampHStart = usHighPulsePeriod + 5;
			usClampHEnd = usClampHStart + 13;

	#if (SOG_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
			/* fix clamp pulse error */
			usClampHStart = usClampHStart>>1;
			usClampHEnd = usClampHEnd>>1;
	#endif /* #if (SOG_CLAMP_CNT_UNIT == CLAMP_CNT_UNIT_2CLK) */

			/* Set Clamp ctrl voltage level 100 => 400 mV */
			adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
			adc_vbias_reg.adc_vbias3_1_0 = 1;
			IoReg_Write32(ADC_ADC_VBIAS_reg, adc_vbias_reg.regValue);

			YPbPr_SetClampPulse(VGA_SP_PATH, usClampHStart, usClampHEnd,
				usClampHStart, usClampHEnd, CLAMP_ALL);

			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				/* enable CLAMP signal output */
				SP1_CLMPCTRL_register.regValue = 0;
				SP1_CLMPCTRL_register.s1_clamp_dben = _DISABLE;
				SP1_CLMPCTRL_register.s1_clamp_cnt_unit = SOG_CLAMP_CNT_UNIT;
				SP1_CLMPCTRL_register.s1_clamp_clksrc = SOG_CLAMP_CLKSRC;
				SP1_CLMPCTRL_register.s1_clamp_en = _ENABLE;
				SP1_CLMPCTRL_register.s1_yclamp_hs_inv = SOG_CLAMP_Y_REF_EDGE;
				SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = SOG_CLAMP_NY_REF_EDGE;
				SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
				SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				/* enable load double buffer */
				SP1_CLMPCTRL_register.s1_clamp_dben = _ENABLE;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);
			}

			//VGA_Clamp_Ctrl(_ENABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT), (((VGA_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT));

			if (VGA_SOG_PATH_SELECT) {
				auto_soy_soych1_a0_reg.regValue = 0;
				auto_soy_soych1_a0_reg.reg_off_manu_comp = SOY_CH1_COMPARE_LEVEL;
				IoReg_Write32(AUTO_SOY_SOYCH1_A0_reg, auto_soy_soych1_a0_reg.regValue);
			} else {
				auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
				auto_soy_soych0_a3_reg.reg_manu_comp = SOY_CH0_COMPARE_LEVEL;
				IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
			}

			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "%s dv restore ctrl disable\n", __FUNCTION__);
			//VGA_DCRestore_Ctrl(_DISABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT));
		}
	}

	/* fix SOG type, the G channel have sync, let clamp pulse error */
	/* the picture have little green, modify clamp pulse */
	if (_ENABLE == Scaler_Get_VGA_Enable_Asjudt_ClampPulse_In_SS_Type()) {
		/* To Fix SS sync type, the G path have sync too, let picture have a little green */
		if (SEPARATE_MODE == VGADetecSyncTypeMode) {
			/* Get H sync high pulse period */
			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				SP1_StbRst1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst1_reg);
				usStablePeriod = SP1_StbRst1_reg.s1_stable_period_out;
				usHighPulsePeriod = SP1_StbRst1_reg.s1_stable_plswid_out;
			}

			if (usStablePeriod < usHighPulsePeriod) {
				usHighPulsePeriod = usStablePeriod;
			}
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]usHighPulsePeriod Pre= 0x%08x\n", __func__, __LINE__, usHighPulsePeriod);

			/* 500 ns ~= 13.5 crystal clock */
			usClampHStart = usHighPulsePeriod + 5;
			usClampHEnd = usClampHStart + 13;

			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "VGA SS Type, Clamp Pulse Start : 0x%08x, End : 0x%08x\n", usClampHStart, usClampHEnd);

	#if (VGA_CLAMP_CNT_UNIT	== CLAMP_CNT_UNIT_2CLK)
			/* fix clamp pulse error */
			usClampHStart = usClampHStart>>1;
			usClampHEnd = usClampHEnd>>1;
	#endif /* #if (VGA_CLAMP_CNT_UNIT == CLAMP_CNT_UNIT_2CLK) */

			/* Set Clamp ctrl voltage level 100 => 400 mV */
			adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
			adc_vbias_reg.adc_vbias3_1_0 = 1;
			IoReg_Write32(ADC_ADC_VBIAS_reg, adc_vbias_reg.regValue);

			YPbPr_SetClampPulse(VGA_SP_PATH, usClampHStart, usClampHEnd, usClampHStart, usClampHEnd, CLAMP_ALL);

			if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
				/* enable CLAMP signal output */
				SP1_CLMPCTRL_register.regValue = 0;
				SP1_CLMPCTRL_register.s1_clamp_dben = _DISABLE;
				SP1_CLMPCTRL_register.s1_clamp_cnt_unit = VGA_CLAMP_CNT_UNIT;
				SP1_CLMPCTRL_register.s1_clamp_clksrc = VGA_CLAMP_CLKSRC;
				SP1_CLMPCTRL_register.s1_clamp_en = _ENABLE;
				SP1_CLMPCTRL_register.s1_yclamp_hs_inv = VGA_CLAMP_Y_REF_EDGE;
				SP1_CLMPCTRL_register.s1_nyclamp_hs_inv = VGA_CLAMP_NY_REF_EDGE;
				SP1_CLMPCTRL_register.s1_clamp_test_en = _DISABLE;
				SP1_CLMPCTRL_register.s1_adc_hs_syncedge = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);

				/* enable load double buffer */
				SP1_CLMPCTRL_register.s1_clamp_dben = _ENABLE;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, SP1_CLMPCTRL_register.regValue);
			}
		}
	}
#endif
}

void VGA_SetSOGCompareLevel(unsigned char soy_path, unsigned char value)
{
	auto_soy_soych1_a0_RBUS auto_soy_soych1_a0_reg;
	auto_soy_soych0_a3_RBUS auto_soy_soych0_a3_reg;

	if (SP_VHS_SOURCE_SOY0 == soy_path) {
		auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
		auto_soy_soych0_a3_reg.reg_manu_comp = value;
		IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);
	} else {/* if (SP_VHS_SOURCE_SOY1 == soy_path) */
		auto_soy_soych1_a0_reg.regValue = 0;
		auto_soy_soych1_a0_reg.reg_off_manu_comp = value;
		IoReg_Write32(AUTO_SOY_SOYCH1_A0_reg, auto_soy_soych1_a0_reg.regValue);
	}
}

/*
 * Add for VGA, rzhen @2017-02-23, START
 */

 
unsigned char VGA_SetInput(StructSourceInput *input_pt)
{
	VGA_input_pt = input_pt;
	return 0;
}

void VGA_Connect_Setting(void)
{
	//Do VGA coneect initial setting
	adc_adc_clock_RBUS adc_clock_reg;
	sync_processor_sp1_ctrl_RBUS SP1_CTRL_reg;
	sync_processor_sp1_dcnt_RBUS  SP1_dcnt_reg;

	ADC_INITIAL_OPTIONS  *ptOptions = VGA_input_pt->InitOptions;

	VGA_ADCPowerControl(TRUE);

	drvif_vga_init_table();

	VGA_Negative_Clamp_DACSource();

	adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_clock_reg.adc_clock_10 = 0;
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);

	adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_clock_reg.adc_2x_sample_0 = 1;
	adc_clock_reg.adc_clock_9_8 = 0; // 108MHz, 1.2V
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);

	SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	//De-Composite HS out in CS mode
	SP1_CTRL_reg.s1_dehs_out_en = 1;
	SP1_CTRL_reg.s1_hsraw_inv = 0;
	SP1_CTRL_reg.s1_hs_sync_source = VGA_HSYNC_SRC;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);

	SP1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
	SP1_dcnt_reg.s1_deb_num = VGA_CHROMA_DEBOUNCE_NUM_INIT;
	IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, SP1_dcnt_reg.regValue);

	
	
	drvif_inprocvga_init();
	
	
	VGA_Detect_SyncType_Init();

	VGA_SyncProc_Init();

	ADCSelectInput(_SRC_VGA, (((VGA_ADC_DATA_PATH*)ptOptions->path)->DATA_INPUT), (((VGA_ADC_DATA_PATH*)ptOptions->path)->SOY_INPUT)
		, (((VGA_ADC_DATA_PATH*)ptOptions->path)->SWAP_PATH));

	VGA_SyncProc();

	VGA_TimingDetectStage = VGA_HVSYNC_STATE;
}

unsigned char VGA_DetectTiming_PadCheck(void)
{
	unsigned char cnt;
	sync_processor_sp_pad_status_RBUS sync_processor_sp_pad_status_reg;

	sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
	sync_processor_sp_pad_status_reg.tog_pad_avs1 = 1;
	sync_processor_sp_pad_status_reg.tog_pad_ahs1 = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP_PAD_STATUS_reg, sync_processor_sp_pad_status_reg.regValue);
	msleep(2);/*pad detect check brandon*/

	for (cnt = 0; cnt < 5; cnt++) {
		sync_processor_sp_pad_status_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_PAD_STATUS_reg);
		if (sync_processor_sp_pad_status_reg.tog_pad_avs1 == 1 && sync_processor_sp_pad_status_reg.tog_pad_ahs1 == 1){
			return TRUE;
		}
	}

	return FALSE;
}


unsigned char VGA_DetectTiming(void)
{
	unsigned char result=0, SignalMode;
	ADC_INITIAL_OPTIONS *ptOptions;
	ModeInformationType *p_timinginfo;
	StructDisplayInfo *p_dispinfo;
	unsigned short timingmodeindex;

	dds_pll_pll_ctrl_RBUS pll_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	sync_processor_sp1_ctrl_reg.s1_hs_fb_plswid_md = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
	sync_processor_sp1_ctrl_reg.s1_hs_fb_plswid_md = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);

#ifdef CONFIG_APLL_PROTECT
	pll_ctrl_reg.regValue   = 0;
	pll_ctrl_reg.pllpwdn    = 1; ///REG_APLLPWDN (PLL Power Down) 1: Power Down
	pll_ctrl_reg.apll_reg   = 1; ///REG_APLL_REG<1:0> V16 setting 01:1.68V (default)
	pll_ctrl_reg.pllswdrst  = 1; ///REG_PLLSWDRST (PLL WD Reset) 1: Reset
	pll_ctrl_reg.adckmode   = 1; ///ADCKMODE [1:0] (ADC Input Clock Select Mode) 01: Single Inverse-Clock Mode
	pll_ctrl_reg.apllldosel = 1; ///LDO reference voltage setting  01:1.1V(default);
	pll_ctrl_reg.apllldopow = 1; ///LDO Power 1:Power on
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
	pll_ctrl_reg.pllpwdn    = 0; ///REG_APLLPWDN (PLL Power Down) 0: Normal Run
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
	msleep(1);
	pll_ctrl_reg.pllswdrst  = 0; ///REG_PLLSWDRST (PLL WD Reset) 0: Normal
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
#else
	pll_ctrl_reg.regValue   = 0;
	pll_ctrl_reg.pllpwdn    = 0; ///REG_APLLPWDN (PLL Power Down) 0: Normal Run
	pll_ctrl_reg.apll_reg   = 1; ///REG_APLL_REG<1:0> V16 setting 01:1.68V (default)
	pll_ctrl_reg.pllswdrst  = 0; ///REG_PLLSWDRST (PLL WD Reset) 0: Normal
	pll_ctrl_reg.adckmode   = 1; ///ADCKMODE [1:0] (ADC Input Clock Select Mode) 01: Single Inverse-Clock Mode
	pll_ctrl_reg.apllldosel = 1; ///LDO reference voltage setting  01:1.1V(default);
	pll_ctrl_reg.apllldopow = 1; ///LDO Power 1:Power on
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);
#endif

	ptOptions = VGA_input_pt->InitOptions;
	p_timinginfo = Get_ADC_Timinginfo();
	p_dispinfo = Get_ADC_Dispinfo();

	VGA_DCRestore_Ctrl(_ENABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT));

	VGA_Clamp_Ctrl(_DISABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT), (((YPBPR_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT));

	if(VGA_TimingDetectStage == VGA_HVSYNC_STATE){

		if (VGA_DetectTiming_PadCheck() == FALSE) {
			/* Pad No Signal. Brandon */
			//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			YPbPr_DetectFail_NoSignal_Handler();
			return _MODE_NOSIGNAL;
		}

		p_dispinfo->ucMode_Table_Index = Mode_Table_Init_Index;
		VGA_TimingDetectStage = VGA_SIGNALTYPE_STATE;
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] VGA_HVSYNC_STATE success\n", __FUNCTION__, __LINE__);
		return _MODE_SUCCESS;
	}else if(VGA_TimingDetectStage == VGA_SIGNALTYPE_STATE){

		result = SyncProc_SyncHandler(_SRC_VGA);

		if (result == _MODE_SUCCESS) {

			VGA_TimingDetectStage = VGA_OFFLINE_STATE;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] VGA_SIGNALTYPE_STATE success\n", __FUNCTION__, __LINE__);
			return _MODE_SUCCESS;
		} else {
			if(result == _MODE_NOSUPPORT) {
				YPbPr_DetectFail_Invalid_Handler();
			} else {
				YPbPr_DetectFail_NoSignal_Handler();
			}

			VGA_TimingDetectStage = VGA_HVSYNC_STATE;
			SyncProc_FunctionDisable(_SRC_VGA);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] VGA_SIGNALTYPE_STATE fail \n", __FUNCTION__, __LINE__);
			return result;
		}
	}else{
		reset_sp_status();//reset cap lock status
		timingmodeindex = p_dispinfo->ucMode_Table_Index;
		SignalMode = SyncProc_TimingModeHandler(_SRC_VGA, VGA_input_pt); /* offlinemeasure check timing mode */
		if (SignalMode != _MODE_SUCCESS) {
			if (SignalMode == _MODE_NOSUPPORT){
				YPbPr_DetectFail_Invalid_Handler();
			} else {
				YPbPr_DetectFail_NoSignal_Handler();
			}

			VGA_TimingDetectStage = VGA_HVSYNC_STATE;
			vga_good_timing_ready = FALSE;
			SyncProc_FunctionDisable(_SRC_VGA);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### [%s(%d)] VGA_OFFLINE_STATE fail ##\n", __func__, __LINE__);
			return SignalMode;

		}
		else if(check_sp_cap_unlock())//sp unlock
		{
			YPbPr_DetectFail_NoSignal_Handler();
			VGA_TimingDetectStage = VGA_HVSYNC_STATE;
			vga_good_timing_ready = FALSE;
			SyncProc_FunctionDisable(_SRC_VGA);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### [%s(%d)] check_sp_cap_unlock fail ##\n", __func__, __LINE__);

			return _MODE_NOSIGNAL;
			
		}
		else if (timingmodeindex != p_dispinfo->ucMode_Table_Index) {

			if(timingmodeindex != Mode_Table_Init_Index)//offline different result and this is not first time. need detect at beginning
			{
				YPbPr_DetectFail_NoSignal_Handler();
				VGA_TimingDetectStage = VGA_HVSYNC_STATE;
				vga_good_timing_ready = FALSE;
				SyncProc_FunctionDisable(_SRC_VGA);
				return _MODE_NOSIGNAL;
			}
			vga_good_timing_ready = TRUE;
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "###### [%s(%d)] timingmodeindex:0x%08x ucMode_Table_Index:0x%08x#####\n", __func__, __LINE__, timingmodeindex, p_dispinfo->ucMode_Table_Index);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "HSYNCPULSECOUNT:%d IHCount:%d,IVCount:%d\n", p_timinginfo->IHSyncPulseCount, p_timinginfo->IHCount, p_timinginfo->IVCount);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "IHFreq:%d,IVFreq:%d\n", p_timinginfo->IHFreq, p_timinginfo->IVFreq);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "**HS=%d,HW=%d,VS=%d,VW=%d\n",
				p_dispinfo->IPH_ACT_STA,
				p_dispinfo->IPH_ACT_WID,
				p_dispinfo->IPV_ACT_STA,
				p_dispinfo->IPV_ACT_LEN);
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "**IHFreq=%d,IVFreq=%d,IHTotal=%d,IVTotal=%d,ADC_CLOCK:%d\n",
				p_dispinfo->IHFreq,
				p_dispinfo->IVFreq,
				p_dispinfo->IHTotal,
				p_dispinfo->IVTotal,
				p_dispinfo->INPUT_ADC_CLOCK);
			
			drvif_mode_print_mode_ID(p_timinginfo->ModeCurr);

			drvif_clock_pfd_calibration();

			VGA_SP_ModeSetting();

			drvif_clock_select_VCO_div(p_dispinfo);

			drvif_clock_set_aclk(p_dispinfo, _SRC_VGA,	p_dispinfo->INPUT_ADC_CLOCK, FALSE);

			//Adjust_ADC_Clock(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);

			drvif_set_gain_from_table(_SRC_VGA);
		#ifdef ADC_UP_DOWN_CLAMP
			drvif_set_offset_from_table(_SRC_VGA);
		#endif
		}else{
			if(vga_good_timing_ready == FALSE){
				vga_good_timing_ready = TRUE;
			}
		}
	}

	return result;
}

void VGA_ADC_LPF_BW_Setting(StructDisplayInfo *p_dispinfo)
{
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	
	unsigned short pixelclock;
	

	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);

	// Calculate pixel clock rate (round to MHz)
	pixelclock  = (((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_H_FREQ) * (unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)) * 2 / (1000 * 10));
	pixelclock  = (pixelclock >> 1) + (pixelclock & 0x01);

	if(pixelclock < 38)
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_75M;
	else if(pixelclock < 68)
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_150M;
	else if(pixelclock < 160)
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_300M;

	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 0;

	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
	return;
}


void VGA_Setup(void)
{/* This api is setting after detect timing success  mode setting */
	unsigned int usHighPulsePeriod = 0;
	unsigned int usADCClock = 0;
	unsigned short usABL_Hstart = 0;

	unsigned long long ulparam1 =0;
	unsigned long long ulparam2 =0;

	sync_processor_sp1_stbrst1_RBUS SP1_StbRst1_reg;

	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;

	ADC_INITIAL_OPTIONS  *ptOptions;
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();
    ptOptions = VGA_input_pt->InitOptions;

    VGA_ADC_LPF_BW_Setting(p_dispinfo);

	drvif_adc_power_control(ADC_POWER_VGA_ONLY_DETECT_CONTROL);

	VGA_Clamp_Ctrl(_ENABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT),     /* enable clamp */
	(((VGA_ADC_DATA_PATH *)ptOptions->path)->SOY_INPUT));

	VGA_DCRestore_Ctrl(_DISABLE, (((VGA_ADC_DATA_PATH *)ptOptions->path)->DATA_INPUT));   /* disable DC_restore */

#ifndef ADC_UP_DOWN_CLAMP
	if (_ENABLE == get_adc_abl_function()) {

		if (SYNC_PROCESSOR1 == VGA_SP_PATH) {
			SP1_StbRst1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst1_reg);
			usHighPulsePeriod = SP1_StbRst1_reg.s1_stable_plswid_out;
		}

		//ADC sampling clock, UNIT in KHz
		ulparam1 = (unsigned long long)p_dispinfo->INPUT_ADC_CLOCK;
		ulparam2 = (unsigned long long)p_dispinfo->IHCount_PRE;
		do_div(ulparam1, ulparam2);

		usADCClock = (unsigned int)ulparam1;

		/* ABL initial start position at high pulse + offset */
		usABL_Hstart = VGA_SOG_ABL_H_START_OFFSET + (usHighPulsePeriod * usADCClock);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]usABL_Hstart = %d\n", __func__, __LINE__, usABL_Hstart);

		VGA_ABL_SETTING_ON(usABL_Hstart);
	} else {

		VGA_ABL_Enable_Control(_DISABLE);
		drvif_set_offset_from_table(_SRC_VGA);
	}
#endif

	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo){
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return;
	}else
		return;

	if((stScreenModeCurrInfo->Clock != 50)  || (stScreenModeCurrInfo->ClockShift_After_auto != 128))
		Scaler_SetClock(stScreenModeCurrInfo->Clock);
	else
	{
		if(drv_auto_get_phase_flag()){
			YPbPr_SetPhase(_MAIN_DISPLAY, stScreenModeCurrInfo->Phase, TRUE);
		}else{//1/2 vco clk, phase range [0~63]
			YPbPr_SetPhase(_MAIN_DISPLAY, stScreenModeCurrInfo->Phase>>1, TRUE);
		}
	}
}


/*
 * Add for VGA, rzhen @2017-02-24, END
 */
void drvif_vga_auto_table_init(void)
{
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	unsigned char index;

	stScreenModeCurrInfo = get_vga_auto_data(0);

	if(stScreenModeCurrInfo){
		for(index=0; index<=_MODE_PC_TIMING_END; index++){
			stScreenModeCurrInfo->H_Position = 0x32;
			stScreenModeCurrInfo->V_Position = 0x32;
			stScreenModeCurrInfo->Phase = 0;
			stScreenModeCurrInfo->Clock = 0x32;
			stScreenModeCurrInfo->ClockShift_After_auto = 128;//reset calibration value
			stScreenModeCurrInfo++;
		}
	}
}

unsigned char check_vga_auto_calib_status(void)
{//check vga current timing already run auto config or not. return FALSE: need calibration 
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return FALSE;

		return stScreenModeCurrInfo->Open_Count;
	}
	else
		return FALSE;

}

unsigned char Scaler_AdjustPCAuto(unsigned char display)
{
	extern void vga_auto_config_error_handler(void);
	extern struct semaphore* get_adc_detectsemaphore(void);
	UINT8 usResult=0;
	unsigned char HsizeValue,VsizeValue;
	
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	StructDisplayInfo *p_dispinfo = NULL;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]VGA auto adjust begin!!!#####\n", __func__, __LINE__);
	rtd_printk(KERN_EMERG, TAG_NAME_ADC, "#####[%s(%d)]display=%d #####\n", __func__, __LINE__, display);

	p_dispinfo = Get_ADC_Dispinfo();
	if(p_dispinfo){
		if(((p_dispinfo->IPH_ACT_WID_PRE == 4095)&&(p_dispinfo->IPV_ACT_LEN_PRE == 4095))
			||((p_dispinfo->IPH_ACT_WID_PRE == 0)&&(p_dispinfo->IPV_ACT_LEN_PRE == 0))){
			rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]NoSignal and Unsupport no need auto adjust!!!#####\n", __func__, __LINE__);
			return FALSE;
		}
	}else
		return FALSE;

	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return FALSE;
	}
	else
		return FALSE;



	down(get_adc_detectsemaphore());
	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
	{
		
		vga_clock_online_setting(display);//chnage online watch dog and interrupt setting only check v timeout 

		drvif_scalerdisplay_set_freeze(SLR_MAIN_DISPLAY, TRUE);//freeze
		
		usResult = drvif_adc_auto_config(stScreenModeCurrInfo, display);


		if (usResult == ERROR_INPUT){
			if (VGA_HSYNC_SRC != _HSYNC_AHS){
				SyncProc_hs_sync_source(_SRC_VGA, VGA_HSYNC_SRC);
			}
		}
		drvif_scalerdisplay_set_freeze(SLR_MAIN_DISPLAY, FALSE);//un-freeze
		vga_clock_clear_online_status(display);//clease clock adjust online error status 
		if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
		{
			if(vga_clock_check_onlinemeasure_status(display) == FALSE)
			{
				vga_auto_config_error_handler();
				up(get_adc_detectsemaphore());
				rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]VGA auto adjust fail!!!#####\n", __func__, __LINE__);
				return FALSE;
			}

			if(display == SLR_MAIN_DISPLAY)
			{//enable online measure 
#ifdef CONFIG_FORCE_RUN_I3DDMA
				drvif_mode_dma_onlinemeasure_setting( TRUE, TRUE);//ADC verify mode
#else
				drvif_mode_onlinemeasure_setting(SLR_MAIN_DISPLAY, _SRC_VGA, TRUE, TRUE);
#endif
			}
			else
			{
#ifdef CONFIG_DUAL_CHANNEL
				drvif_mode_onlinemeasure_setting(SLR_SUB_DISPLAY, _SRC_VGA, TRUE, TRUE);
#endif
			}
		}

		if(usResult==ERROR_SUCCEED){
			up(get_adc_detectsemaphore());
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]VGA auto adjust success!!!#####\n", __func__, __LINE__);
			stScreenModeCurrInfo->Open_Count = 1;
			return TRUE;
		}else{
			up(get_adc_detectsemaphore());
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]VGA auto adjust fail!!!#####\n", __func__, __LINE__);
			return FALSE;
		}
	}
	up(get_adc_detectsemaphore());
}

unsigned char Scaler_GetHPosition(void)
{
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust] #####\n", __func__, __LINE__);
			return 0;
		}
	}
	else{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust] #####\n", __func__, __LINE__);
		return 0;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]H_Position=%d #####\n", __func__, __LINE__, stScreenModeCurrInfo->H_Position);
	return stScreenModeCurrInfo->H_Position;
}

//range 0~100
unsigned char Scaler_SetHPosition(unsigned char value)
{
#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_act_hsta_width_reg;
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_dma_vgip_delay_reg;
#else
	vgip_vgip_chn1_delay_RBUS vgip_chn1_delay_reg;
	vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_reg;
#endif

	unsigned short h_start;
	unsigned short h_delay;
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;

	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();

	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return FALSE;
	}
	else
		return FALSE;

	stScreenModeCurrInfo->H_Position = value < 100 ? (value < 0 ? 0 : value) : 100;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s] value=%d  hpos=%d #####\n", __func__, value, stScreenModeCurrInfo->H_Position);

	if(p_dispinfo->IPH_ACT_STA >=  (FIX_VGIP_H_DELAY + MIN_H_BACK_PORCH))
	{
		h_start = p_dispinfo->IPH_ACT_STA - FIX_VGIP_H_DELAY;
		h_delay = FIX_VGIP_H_DELAY;
	}
	else
	{
		h_start = MIN_H_BACK_PORCH;
		h_delay = p_dispinfo->IPH_ACT_STA - MIN_H_BACK_PORCH;
	}		

	if(0x32 >= stScreenModeCurrInfo->H_Position)
	{
		
		h_delay = h_delay + (0x32 - stScreenModeCurrInfo->H_Position);
	}
	else
	{
		if((h_delay + 0x32) >= stScreenModeCurrInfo->H_Position)
			h_delay = h_delay + 0x32 - stScreenModeCurrInfo->H_Position;
		else
			h_delay = 0;
	}

#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_act_hsta_width_reg.dma_ih_act_sta = h_start;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg,dma_vgip_act_hsta_width_reg.regValue );

	dma_vgip_dma_vgip_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_dma_vgip_delay_reg.dma_ihs_dly = h_delay;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg,dma_vgip_dma_vgip_delay_reg.regValue );

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022418[29:16]=0x%04x#####\n", __func__, __LINE__,dma_vgip_act_hsta_width_reg.dma_ih_act_sta);
#else
	vgip_chn1_act_hsta_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	vgip_chn1_act_hsta_reg.ch1_ih_act_sta = h_start;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg,vgip_chn1_act_hsta_reg.regValue );

	vgip_chn1_delay_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_DELAY_reg);
	vgip_chn1_delay_reg.ch1_ihs_dly = h_delay;
	IoReg_Write32(VGIP_VGIP_CHN1_DELAY_reg,vgip_chn1_delay_reg.regValue );

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022218[29:16]=0x%04x#####\n", __func__, __LINE__,vgip_chn1_act_hsta_reg.ch1_ih_act_sta);
#endif

	return TRUE;
}

unsigned char Scaler_GetVPosition(void)
{
	//unsigned short temp;
	//char VPositionTemp = 0;//VPOSITION

	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]#####\n", __func__, __LINE__);
			return 0;
		}
	}
	else{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]#####\n", __func__, __LINE__);
		return 0;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]V_Position=%d #####\n", __func__, __LINE__, stScreenModeCurrInfo->V_Position);
	return stScreenModeCurrInfo->V_Position;
}

//range 0~100
unsigned char Scaler_SetVPosition(unsigned char value)
{
#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_dma_vgip_delay_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_dma_vgip_act_vsta_length_reg;
#else
	vgip_vgip_chn1_delay_RBUS vgip_chn1_delay_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_chn1_act_vsta_reg;
#endif


	unsigned short v_start;
	unsigned char v_delay;

	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;

	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();

	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return FALSE;
	}
	else
		return FALSE;
	

	stScreenModeCurrInfo->V_Position = value < 100 ? (value < 0 ? 0 : value) : 100;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s] value=%d vpos:%d#####\n", __func__, value, stScreenModeCurrInfo->V_Position);

	v_start = FIX_VGIP_V_START;
	v_delay = p_dispinfo->IPV_ACT_STA - v_start;
	if(0x32 >= stScreenModeCurrInfo->V_Position)
	{
		v_delay = v_delay + (0x32 - stScreenModeCurrInfo->V_Position);
	}
	else
	{
		if((v_delay + 0x32) >= stScreenModeCurrInfo->V_Position)
			v_delay = v_delay + 0x32 - stScreenModeCurrInfo->V_Position;
		else
			v_delay = 0;
	}

#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
	dma_vgip_dma_vgip_act_vsta_length_reg.dma_iv_act_sta = v_start;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_dma_vgip_act_vsta_length_reg.regValue);

	dma_vgip_dma_vgip_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	dma_vgip_dma_vgip_delay_reg.dma_ivs_dly = v_delay;
	IoReg_Write32(DMA_VGIP_DMA_VGIP_DELAY_reg, dma_vgip_dma_vgip_delay_reg.regValue);
#else
	vgip_chn1_act_vsta_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
	vgip_chn1_act_vsta_reg.ch1_iv_act_sta = v_start;
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg, vgip_chn1_act_vsta_reg.regValue);

	vgip_chn1_delay_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_DELAY_reg);
	vgip_chn1_delay_reg.ch1_ivs_dly = v_delay;
	IoReg_Write32(VGIP_VGIP_CHN1_DELAY_reg, vgip_chn1_delay_reg.regValue);
#endif

	return TRUE;
}

unsigned char Scaler_GetPhase(void)
{
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return 0;
	}
	else
		return 0;

	return stScreenModeCurrInfo->Phase;
}

//phase range [0~127]
void Scaler_SetPhase(unsigned char value)
{
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return;
	}
	else
		return;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] value=%d #####\n", __func__, __LINE__, value);

	stScreenModeCurrInfo->Phase = value;

	if(drv_auto_get_phase_flag()){
		YPbPr_SetPhase(_MAIN_DISPLAY,value, TRUE);
	}else{//1/2 vco clk, phase range [0~63]
		YPbPr_SetPhase(_MAIN_DISPLAY,value>>1, TRUE);
	}
}

unsigned char Scaler_GetClock(void)
{
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return 0;
	}
	else
		return 0;

	return stScreenModeCurrInfo->Clock;
}

//range 0~100
void Scaler_SetClock(unsigned char value)
{
	unsigned int truth_clk;
	StructScreenModeInfo *stScreenModeCurrInfo = NULL;
	ModeInformationType *p_timinginfo = NULL;
	StructDisplayInfo *p_dispinfo = NULL;

	p_dispinfo = Get_ADC_Dispinfo();
	if(!p_dispinfo) return;

	p_timinginfo = Get_ADC_Timinginfo();
	if(p_timinginfo)
	{
		stScreenModeCurrInfo = get_vga_auto_data(p_timinginfo->ModeCurr);
		if(!stScreenModeCurrInfo)
			return;
	}
	else
		return;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] value=%d #####\n", __func__, __LINE__, value);

	stScreenModeCurrInfo->Clock = value < 100 ? (value < 1 ? 0 : value) : 100;

	truth_clk = p_dispinfo->INPUT_ADC_CLOCK + stScreenModeCurrInfo->ClockShift_After_auto - 128 + stScreenModeCurrInfo->Clock - 50;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] truth_clk=%d #####\n", __func__, __LINE__, truth_clk);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] INPUT_ADC_CLOCK=%d #####\n", __func__, __LINE__, p_dispinfo->INPUT_ADC_CLOCK);

	Scaler_VGASetClockStatus(SLR_MAIN_DISPLAY,TRUE);

#if (CONFIG_VGA_SUPPORT_ABL)
	//VGA_ABL_Enable_Control(_DISABLE);
#endif


	vga_clock_online_setting(_MAIN_DISPLAY);//chnage online measure interrupt and watch dog setting. only monitor bit13
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);

	drvif_scalerdisplay_set_freeze(SLR_MAIN_DISPLAY, TRUE);//freeze

	drvif_clock_set_aclk(p_dispinfo, _SRC_VGA, truth_clk, TRUE);

	msleep(50); //wait adc clock is stable and then set feedback hsyc
	//stVGAModeCurrInfo[Scaler_DispGetInputInfo(SLR_INPUT_MODE_TABLE_INDEX)].Clock=  (0x80 + value - 50);
	//MODE_CLEAR_ONMS_FLAG();

	if(drv_auto_get_phase_flag()){//need to set phase again, becasue set clock will reset phase to 0
		YPbPr_SetPhase(_MAIN_DISPLAY, stScreenModeCurrInfo->Phase, TRUE);
	}else{//1/2 vco clk, phase range [0~63]
		YPbPr_SetPhase(_MAIN_DISPLAY, stScreenModeCurrInfo->Phase>>1, TRUE);
	}

	vga_clock_clear_online_status(SLR_MAIN_DISPLAY);//clease clock online measure status
	drvif_scalerdisplay_set_freeze(SLR_MAIN_DISPLAY, FALSE);//UnFreeze
	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
	{
		//enable online measure 
#ifdef CONFIG_FORCE_RUN_I3DDMA
		drvif_mode_dma_onlinemeasure_setting( TRUE, TRUE);//ADC verify mode
#else
		drvif_mode_onlinemeasure_setting(SLR_MAIN_DISPLAY, _SRC_VGA, TRUE, TRUE);
#endif
	}

#if (CONFIG_VGA_SUPPORT_ABL)
	//VGA_ABL_Enable_Control(_ENABLE);
#endif

	Scaler_VGASetClockStatus(SLR_MAIN_DISPLAY,FALSE);
}

/**
* drvif_adc_auto_config
* This function will measure adc signal h,v position and phase and clock
* @param <display>       { 0:MAIN_DISPLAY;1:SUB_DISPLAY}
* @return <result>  	 { 0:ERROR_SUCCEED;not 0:FAIL}
*/
unsigned char drvif_adc_auto_config(StructScreenModeInfo *p_screenInfo, unsigned char display)
{
//	unsigned short mode = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MODE_TABLE_INDEX);
	//unsigned short displayMode = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_MODE_TABLE_INDEX);
//	unsigned short index = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_DATA_ARRAY_IDX);
	//unsigned short displayIndex = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_DATA_ARRAY_IDX);
//	unsigned short channel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_CHANNEL);

	unsigned char Result, Noise = 0, Curr_PosH, Curr_PosV, Curr_Clock,Curr_Phase,select_color;
//	adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]display = %x#####\n", __func__, __LINE__,display);
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]m_stScreenModeCurrInfo[index].H position = %d#####\n", __func__, __LINE__,m_stScreenModeCurrInfo[index].H_Position));
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]m_stVGAModeCurrInfo[mode].H_Position = %d#####\n", __func__, __LINE__,m_stVGAModeCurrInfo[mode].H_Position);

	if(drv_auto_pre_check(&select_color)!=ERROR_SUCCEED)
		return ERROR_ABORT;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]select_color = %x#####\n", __func__, __LINE__,select_color);

	Curr_PosH = p_screenInfo->H_Position;     // Save current stMUD.H_POSITION
	Curr_PosV = p_screenInfo->V_Position;     // Save current stMUD.V_POSITION
	Curr_Clock = p_screenInfo->Clock;   	   // Save current stMUD.CLOCK
	Curr_Phase = p_screenInfo->Phase;   	   // Save current stMUD.PHASE

	// CSW+ 0961219 Turn off on-line measure watchdog
	//fw_scaler_enable_fs_wdg(display, FALSE);
	//drvif_mode_onlinemeasure_setting(_CHANNEL1, _SRC_VGA, FALSE, FALSE);/*Disable online measure*/
	//drvif_mode_dma_onlinemeasure_setting( FALSE, FALSE);//ADC verify mode
	//p_screenInfo->Open_Count = 0;//reset auto status
	if (VGA_HSYNC_SRC != _HSYNC_AHS)
	{
		SyncProc_hs_sync_source(_SRC_VGA, _HSYNC_AHS);
		msleep(20);
	}
	SET_AUTO_CONFIG_DOING();

	//---------Auto_Clock-----------
	Result = drvif_auto_clockdo(p_screenInfo, display, Noise,select_color);

	if (ERROR_SUCCEED != Result)
	{
		SyncProc_hs_sync_source(_SRC_VGA, VGA_HSYNC_SRC);

		drv_auto_clock_fail_handler(p_screenInfo, display,Curr_PosH,Curr_Clock,Curr_Phase);
		CLR_AUTO_CONFIG_DOING();
		return Result;
	}

	if((vga_clock_check_onlinemeasure_status(display) == FALSE) || (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE))
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)] onine status error#####\n", __func__, __LINE__);
		return ERROR_ABORT;

	}

	//---------Auto_Phase-----------
	Result = drvif_auto_phasedo(p_screenInfo, display, Noise, select_color);

	//auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	//auto_phase_ctrl0_reg.autophase_en = 0;
	//IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);

	if (ERROR_SUCCEED != Result )
	{
		SyncProc_hs_sync_source(_SRC_VGA, VGA_HSYNC_SRC);

		drv_auto_phase_fail_handler(p_screenInfo, display,Curr_Phase);
		if (ERROR_NOTACTIVE == Result)
			Result = ERROR_SUCCEED;
		CLR_AUTO_CONFIG_DOING();
		return Result;
	}

	if((vga_clock_check_onlinemeasure_status(display) == FALSE) || (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE))
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)] onine status error#####\n", __func__, __LINE__);
		return ERROR_ABORT;

	}

	//---------Auto_Position-----------
	Result = drvif_auto_positiondo(p_screenInfo, display, Noise, select_color);

	if (ERROR_SUCCEED != Result)
	{
		SyncProc_hs_sync_source(_SRC_VGA, VGA_HSYNC_SRC);
		drv_auto_position_fail_handler(p_screenInfo, display,Curr_PosH,Curr_PosV,Curr_Phase,Curr_Clock);
		CLR_AUTO_CONFIG_DOING();
		return Result;
	}

	if((vga_clock_check_onlinemeasure_status(display) == FALSE) || (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_STATE) != _MODE_STATE_ACTIVE))
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)] onine status error#####\n", __func__, __LINE__);
		return ERROR_ABORT;

	}
	
	auto_waitivs(display);
	//fw_scaler_enable_fs_wdg(display, TRUE);

	//MODE_CLEAR_ONMS_FLAG();
	CLR_AUTO_CONFIG_DOING();

	p_screenInfo->Open_Count = 1;
	SET_AUTO_FINISH();
	return ERROR_SUCCEED;
}


