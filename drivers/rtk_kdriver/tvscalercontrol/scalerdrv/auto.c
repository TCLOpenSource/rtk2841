
/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */
//Kernel Header file
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/semaphore.h>

//RBUS Header file
#include <rbus/adc_smartfit_reg.h>
#include <rbus/adc_reg.h>
#include <rbus/smartfit_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/sync_processor_reg.h>
#include <rbus/auto_soy_reg.h>
#include <rbus/color_reg.h>
//#include <rbus/crt_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>

#include <scalercommon/scalerCommon.h>

//Tvscalercontrol Header file
#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
//#include "tvscalercontrol/scaler/scalertype.h"	//leochen
#include <tvscalercontrol/scaler/scalertimer.h>
#include "tvscalercontrol/scalerdrv/auto.h"
#include "tvscalercontrol/scalerdrv/mode.h"
#include "tvscalercontrol/scalerdrv/adjust.h"
#include "tvscalercontrol/scalerdrv/syncproc.h"
#include <tvscalercontrol/scalerdrv/power.h>/*For ADC power control*/
#include "tvscalercontrol/scaler/source.h"
#include "tvscalercontrol/adcsource/ypbpr.h"
#include <tvscalercontrol/adcsource/vga.h>
#include "tvscalercontrol/scalerdrv/scalerclock.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include "tvscalercontrol/vip/ypbpr_auto.h"
#include <tvscalercontrol/adcsource/adcctrl.h>
#include <tvscalercontrol/scaler_vfedev.h>
#include <rtk_kdriver/rtk_crt.h>
//#include <rtk_kdriver/rtk_platform.h>
#include "mach/rtk_platform.h"
#define _RUN_GET_TARGET_AFTER_AUTOCOLOR
/*==================== Definitions ================= */
//forster modified 071023
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


//extern DEBUG_SCALER_VSC_STRUCT  DbgSclrFlgTkr;

//########################Auto color and Self AWB Data ###############################//
#define _AUTO_VGA_MAX_LEVEL				(1016)//242
#define _AUTO_VGA_MIN_LEVEL				(8)// 2
#define _AUTO_COMPONENT_Y_MAX_LEVEL		(1016)//250
#define _AUTO_COMPONENT_Y_MIN_LEVEL		(48)//12
#define _AUTO_COMPONENT_PB_MAX_LEVEL	(960)//240
#define _AUTO_COMPONENT_PR_MAX_LEVEL	(960)//240
#define _AUTO_VIDEO8_Y_MAX_LEVEL		(248)
#define _AUTO_VIDEO8_Y_MIN_LEVEL		(2)//12
#define _AUTO_VIDEO8_C_MAX_LEVEL		(236) //this value can't over 240
#define _CHROMA_BLACK_LEVEL				(0x200)

#define _Y100UV100_COMPONENT_Y_TARGET (940)
#define _Y100UV100_COMPONENT_U_TARGET (856)
#define _Y100UV100_COMPONENT_V_TARGET (920)

#define _Y75UV75_COMPONENT_Y_TARGET (788)///20161006 roger, modify target to 701 for KTASKWBS-5119 /lg target value is 720
#define _Y75UV75_COMPONENT_U_TARGET (772)//lg target value is 772
#define _Y75UV75_COMPONENT_V_TARGET (818)//lg target value is 816

#define _Y100UV75_COMPONENT_Y_TARGET (940)
#define _Y100UV75_COMPONENT_U_TARGET (732)
#define _Y100UV75_COMPONENT_V_TARGET (793)

//////////////////////// self-AWB //////////////////////////
//Peak Level
#define _AUTO_VGA_PEAK_LEVEL			(1016)
#define _AUTO_COMPONENT_Y_PEAK_LEVEL	(1016)
#define _AUTO_COMPONENT_PB_PEAK_LEVEL	(960) //960:blue of HDMI using chroma 2330
#define _AUTO_COMPONENT_PR_PEAK_LEVEL	(959) //959:red  of HDMI using chroma 2330

//VGA
#define _AUTO_VGA_DEFAULT_GAIN_R		(285)
#define _AUTO_VGA_DEFAULT_GAIN_G		(304)
#define _AUTO_VGA_DEFAULT_GAIN_B		(286)

//VGA
#define _AUTO_VGA_DEFAULT_OFFSET_R		(512)
#define _AUTO_VGA_DEFAULT_OFFSET_G		(512)
#define _AUTO_VGA_DEFAULT_OFFSET_B		(512)

//YPP
#define _AUTO_YPP_DEFAULT_GAIN_PR		(507)//rzhen@2017-04-21
#define _AUTO_YPP_DEFAULT_GAIN_Y		(510)//rzhen@2017-04-21
#define _AUTO_YPP_DEFAULT_GAIN_PB		(431)//rzhen@2017-04-21

//YPP
#define _AUTO_YPP_DEFAULT_OFFSET_PR		(512)
#define _AUTO_YPP_DEFAULT_OFFSET_Y		(512)
#define _AUTO_YPP_DEFAULT_OFFSET_PB		(512)


//SCARTRGB
#define _AUTO_SCARTRGB_DEFAULT_GAIN_R	(331)
#define _AUTO_SCARTRGB_DEFAULT_GAIN_G	(343)
#define _AUTO_SCARTRGB_DEFAULT_GAIN_B	(323)

//SCARTRGB
#define _AUTO_SCARTRGB_DEFAULT_OFFSET_R	(423)
#define _AUTO_SCARTRGB_DEFAULT_OFFSET_G	(449)
#define _AUTO_SCARTRGB_DEFAULT_OFFSET_B	(447)


//VGA
#define _AUTO_SELF_VGA_LEVEL_TARGET_R	(430)
#define _AUTO_SELF_VGA_LEVEL_TARGET_G	(433)
#define _AUTO_SELF_VGA_LEVEL_TARGET_B	(430)

//YPP
#define KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR	(343)//rzhen@2017-04-21
#define KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y	(340)//rzhen@2017-04-21
#define KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB	(367)//rzhen@2017-04-21

//YPP
#define KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PR	(343)//rzhen@2017-04-21, with 75% color bar
#define KXLP_AUTO_SELF_YPP_LEVEL_TARGET_Y	(340)//rzhen@2017-04-21, with 75% color bar
#define KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PB	(367)//rzhen@2017-04-21, with 75% color bar

//SCARTRGB
#define _AUTO_SELF_SCARTRGB_LEVEL_TARGET_PR	(300)
#define _AUTO_SELF_SCARTRGB_LEVEL_TARGET_Y	(298)
#define _AUTO_SELF_SCARTRGB_LEVEL_TARGET_PB	(315)
//########################Auto color and Self AWB Data ###############################//





#define _ADC_SWAP_PATH0   (0x00)  //Rin -> Rout ,  Gin -> Gout, Bin -> Bout
#define _ADC_SWAP_PATH1   (0x01)  //Gin -> Rout ,  Rin -> Gout, Bin -> Bout
#define _ADC_SWAP_PATH2   (0x02)  //Bin -> Rout ,  Gin -> Gout, Rin -> Bout
#define _ADC_SWAP_PATH3   (0x03)  //Bin -> Rout ,  Rin -> Gout, Gin -> Bout
#define _ADC_SWAP_PATH4   (0x04)  //Rin -> Rout ,  Bin -> Gout, Gin -> Bout
#define _ADC_SWAP_PATH5   (0x05)  //Gin -> Rout ,  Bin -> Gout, Rin -> Bout
#define _ADC_SWAP_PATH6   (0x06)  //Bin -> Rout ,  Rin -> Gout, Gin -> Bout
#define _ADC_SWAP_PATH7   (0x07)  //Bin -> Rout ,  Gin -> Gout, Rin -> Bout

#define PIXEL_1 			(0x00)
#define PIXEL_2 			(0x01)
#define PIXEL_4 			(0x02)
#define PIXEL_8 			(0x03)

#define _R_GAIN_INDEX			0
#define _G_GAIN_INDEX			1
#define _B_GAIN_INDEX			2
#define _R_OFFSET_INDEX		3
#define _G_OFFSET_INDEX		4
#define _B_OFFSET_INDEX		5
#define _VDC_GAIN_INDEX		6
#define _VDC_OFFSET_INDEX		7
#define OTP_COMPENSATION_THRESHOLD 3
/*==================== Variables ================= */

AUTO_PARAMETER  stAUTO_PARA;

//[Code Sync][AlanLi][0980525][1]
#define _MEASURE_VDELAY  	1//forster modified 041126
#define _MEAS_H_STA_OFFSET   (_MEASURE_HDEALY - _CAPTURE_HDELAY)
#define _MEAS_H_END_OFFSET   (_MEASURE_HDEALY - _CAPTURE_HDELAY + 1)
#define _VERTICAL_MARGIN 	0x100//0x30 //forster modified 060407
#define _HORIZONTAL_MARGIN   0x160//0x58

//sync auto adjust flow
#define Pulse_Detection_Enable 1
#define Pulse_Detection_Disable 0
#define  Difference_Threshold 	0x02

#define Clock_Adjust_Range 		100
#define Low_Pass_Filter_0	0
#define Low_Pass_Filter_1	1
#define Low_Pass_Filter_2	2
#define Low_Pass_Filter_3	3

#define Software_Auto_Phase		0
#define Hardware_Auto_Phase	1

#define Noise_Margin_Offset	4

unsigned char ucAutoControl;

unsigned long long auto_phasesearch(unsigned char HW_SW_sel, unsigned char display, unsigned char Sel_Mode, unsigned char Sel_Color, unsigned char Sel_Step, unsigned char Sel_Step_Num, unsigned char Sel_Step_Start, unsigned char *Phase_Result,unsigned char filter_sel);
unsigned char auto_phasesearch_start(unsigned char HW_SW_sel, unsigned char display, unsigned char Sel_Mode, unsigned char Sel_Color, unsigned char Sel_Step, unsigned char Sel_Step_Num, unsigned char Sel_Step_Start, unsigned char *Phase_Result,unsigned char filter_sel);
unsigned char auto_phasesearch_WaitFinish(unsigned char *a_pucPhaseResult);

static ADCGainOffset ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_MAX+1] =
{
	{_AUTO_YPP_DEFAULT_GAIN_PR, _AUTO_YPP_DEFAULT_GAIN_Y, _AUTO_YPP_DEFAULT_GAIN_PB, _AUTO_YPP_DEFAULT_OFFSET_PR, _AUTO_YPP_DEFAULT_OFFSET_Y, _AUTO_YPP_DEFAULT_OFFSET_PB },
	{_AUTO_SCARTRGB_DEFAULT_GAIN_R, _AUTO_SCARTRGB_DEFAULT_GAIN_G, _AUTO_SCARTRGB_DEFAULT_GAIN_B, _AUTO_SCARTRGB_DEFAULT_OFFSET_R, _AUTO_SCARTRGB_DEFAULT_OFFSET_G, _AUTO_SCARTRGB_DEFAULT_OFFSET_B},
	{_AUTO_VGA_DEFAULT_GAIN_R, _AUTO_VGA_DEFAULT_GAIN_G, _AUTO_VGA_DEFAULT_GAIN_B, _AUTO_VGA_DEFAULT_OFFSET_R, _AUTO_VGA_DEFAULT_OFFSET_G, _AUTO_VGA_DEFAULT_OFFSET_B },
};

static ADCGainOffset ADC_GAIN_OFFSET_DATA[ADCTYPE_SCART_MAX+1] =
{
	{_AUTO_YPP_DEFAULT_GAIN_PR, _AUTO_YPP_DEFAULT_GAIN_Y, _AUTO_YPP_DEFAULT_GAIN_PB, _AUTO_YPP_DEFAULT_OFFSET_PR, _AUTO_YPP_DEFAULT_OFFSET_Y, _AUTO_YPP_DEFAULT_OFFSET_PB },
	{_AUTO_SCARTRGB_DEFAULT_GAIN_R, _AUTO_SCARTRGB_DEFAULT_GAIN_G, _AUTO_SCARTRGB_DEFAULT_GAIN_B, _AUTO_SCARTRGB_DEFAULT_OFFSET_R, _AUTO_SCARTRGB_DEFAULT_OFFSET_G, _AUTO_SCARTRGB_DEFAULT_OFFSET_B},
	{_AUTO_VGA_DEFAULT_GAIN_R, _AUTO_VGA_DEFAULT_GAIN_G, _AUTO_VGA_DEFAULT_GAIN_B, _AUTO_VGA_DEFAULT_OFFSET_R, _AUTO_VGA_DEFAULT_OFFSET_G, _AUTO_VGA_DEFAULT_OFFSET_B },
};
static ADCGainOffset *stVGAGainOffset = &ADC_GAIN_OFFSET_DATA[ADCTYPE_VGA];
static ADCGainOffset *stYPbPrGainOffsetData = &ADC_GAIN_OFFSET_DATA[ADCTYPE_YPBPR];
static ADCGainOffset *stScartRGBGainOffsetData = &ADC_GAIN_OFFSET_DATA[ADCTYPE_SCART_RGB];

static unsigned short R_GainAdjustMax = 511;//Sirius range is 0-511
static unsigned short R_GainAdjustMin = 0;
static unsigned short G_GainAdjustMax = 511;//Sirius range is 0-511
static unsigned short G_GainAdjustMin = 0;
static unsigned short B_GainAdjustMax = 511;//Sirius range is 0-511
static unsigned short B_GainAdjustMin = 0;

static unsigned char ADC_ABL_Function_Ctrl = _ENABLE;
static unsigned char check_v_auto_position_result(unsigned int vstart, unsigned int vend, StructDisplayInfo *adc_dispinfo);
static unsigned char check_h_auto_position_result(unsigned int hstart, unsigned int hend, StructDisplayInfo *adc_dispinfo);
/*============= Local Functions' Phototype ============== */
static void drvif_self_awb_changegain(UINT8 color, UINT16 delta, UINT8 inc, int src, ADCGainOffset * ptADC_info);

void Reset_YPP_Auto_Phase_SmartFit_Setting(void)
{
	adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	//Reset auto phase setting
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);//Reset autophase. Will add
	auto_phase_ctrl0_reg.autophase_en = 0;//Reset autophase. Will add
	auto_phase_ctrl0_reg.new_ap_en = 0;//Reset autophase. rzhen@2017-01-06
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);//Reset autophase. Will add
	smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);//Reset autophase. Will add
	smartfit_auto_adj_reg.now_af = 1;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);//Reset autophase. Will add
	smartfit_auto_adj_reg.now_af = 0;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);//Reset autophase. Will add
}


unsigned char get_adc_abl_function(void)
{
	return ADC_ABL_Function_Ctrl;
}

void set_adc_abl_function(unsigned char enable)
{
	ADC_ABL_Function_Ctrl = enable;
}

void EnableIPTGInSXGA(void)
{
	// Set APLL for SXGA
#if 1
	IoReg_Write32(0xb8020100, 0x03030115);	// M=24,N=3,K=0
	IoReg_Write32(0xb8020108, 0x00000697);	// Divider=1688
	IoReg_Write32(0xb8020428, 0x00430000);	// ADC clk=(1/2)*VCO clk
	IoReg_Write32(0xb8020110, 0x00000220);	// PLL phase interpolation control load
	IoReg_Write32(0xb8020114, 0x00000030);	// G value=16, P code over flow 2 bit
	IoReg_Write32(0xb8020118, 0x00000002);	// Adaptive Tracking (Default value)
	IoReg_Write32(0xb802011c, 0x3026b433);	// P code max=1268252 and new mode disable
	IoReg_Write32(0xb8020120, 0x000002a1);	// Delay chain select , Free Run enable
	IoReg_Write32(0xb8020124, 0x00000008);	// DDS tracking HS positive edge (Default value)
	IoReg_Write32(0xb8020128, 0x00000508);	// I code=1288
	IoReg_Write32(0xb802012c, 0x000000f7);	// P code=126825, over flow 2 bits
	IoReg_Write32(0xb8020130, 0x00000000);	// Calibration disable (Default value)
	IoReg_Write32(0xb8020134, 0x00000000);	// PE measure disable (Default value)
	IoReg_Write32(0xb8020138, 0x00000000);	// PE Max measure disable (Default value)
	IoReg_Write32(0xb802013c, 0x00000040);	// enable double buffer load
	IoReg_Write32(0xb8020104, 0x00050608);	// M=24,N=3,K=0


#else
	rtd_outl(0x0500, 0x03030115);	// M=24,N=3,K=0
	rtd_outl(0x0508, 0x00000697);	// Divider=1688
	rtd_outl(0x050c, 0x00430000);	// ADC clk=(1/2)*VCO clk
	rtd_outl(0x0510, 0x00000120);	// PLL phase interpolation control load
	rtd_outl(0x0514, 0x00000030);	// G value=16, P code over flow 2 bit
	rtd_outl(0x0518, 0x00000002);	// Adaptive Tracking (Default value)
	rtd_outl(0x051c, 0x3026b433);	// P code max=1268252 and new mode disable
	rtd_outl(0x0520, 0x000002a1);	// Delay chain select , Free Run enable
	rtd_outl(0x0524, 0x00000008);	// DDS tracking HS positive edge (Default value)
	rtd_outl(0x0528, 0x00000508);	// I code=1288
	rtd_outl(0x052c, 0x000000f7);	// P code=126825, over flow 2 bits
	rtd_outl(0x0530, 0x00000000);	// Calibration disable (Default value)
	rtd_outl(0x0534, 0x00000000);	// PE measure disable (Default value)
	rtd_outl(0x0538, 0x00000000);	// PE Max measure disable (Default value)

	rtd_outl(0x053c, 0x00000040);	// enable double buffer load
	rtd_outl(0x0504, 0x00000608);	// enable APLL
#endif
	//Set I_PTG for SXGA

	//rtd_outl(0x0400, 0x000001ff);  // global power on
	IoReg_Write32(0xb8020000, 0x000001ff);

	IoReg_Write32(0xb8022100, 0x0698042A);   // Total pixel = 1688*1066
	IoReg_Write32(0xb8022104, 0x01680500);   // Horizontal active start = 204, active width = 1280
	IoReg_Write32(0xb8022108, 0x00290400);   // Vertical active start = 21, active width = 1024
	IoReg_Write32(0xb802210c, 0x00000001);   // Enable timing generator
	IoReg_Write32(0xb8022114, 0x01680500);   // Pattern Gen display Hstart & Hactive
	IoReg_Write32(0xb8022118, 0x00290400);   // Pattern Gen display Vstart & Vactive
	//rtd_outl(0xb802211C, 0x00000003);   // PTG control, select pattern = veritcal color bar
	//rtd_outl(0xb8022120, 0x000000A0);   // Color bar width  =59


	IoReg_Write32(0xb8022210, 0x90000001);	//001:ADC/YPbPr (incluing Pattern Generator),analog mode
	//rtd_outl(0xb8022210, 0x10000001);	//001:ADC/YPbPr (incluing Pattern Generator),digital mode

	IoReg_Write32(0xb8022218, 0x01680500);	//27:16==>Ch1_ih_act_sta/11:0==>Ch1_ih_act_wid
	IoReg_Write32(0xb802221c, 0x00290400);	//27:16==>Ch1_iv_act_sta/11:0==>Ch1_iv_act_len
	IoReg_Write32(0xb8022220, 0x80000000);	//27:16==>Ch1_IHS_DLY/11:0==>Ch1_IVS_DLY      CH1_hs_width	31:30 need to be 10
	IoReg_Write32(0xb8022284, 0x00000008);	//from vgip/ch1/DI bypass


}


void  drvif_set_smartfit_auto_field_ctrl(unsigned char display)
{
	//I-Domain AUTO_FIELD rzhen@2016-06-29
	//Select input data source for auto function
	//0: Channel 1 (MAIN VGIP)
	//1: Channel 2 (SUB VGIP)
	//2: Channel 3 (I3DDMA VGIP)

	smartfit_auto_field_RBUS smartfit_auto_field_reg;
	smartfit_auto_field_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_FIELD_reg);
#ifdef CONFIG_FORCE_RUN_I3DDMA
	smartfit_auto_field_reg.adj_source = (display == SLR_SUB_DISPLAY)? 1:2;
#else
	smartfit_auto_field_reg.adj_source = (display == SLR_SUB_DISPLAY)? 1:0;
#endif
	smartfit_auto_field_reg.smartfit_src_sel = 0; //0 : Select source after VGIP. H delay need to be 2.  1 : Select source before VGIP. H delay need to be 3
	IoReg_Write32(SMARTFIT_AUTO_FIELD_reg, smartfit_auto_field_reg.regValue);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]0xb8022000=0x%08x#####\n", __func__, __LINE__, IoReg_Read32(SMARTFIT_AUTO_FIELD_reg));
}

static void  drvif_set_adc_smartfit_boundary(void)
{
	adc_smartfit_adc_auto_h_boundary_RBUS smartfit_auto_h_boundary_reg;
	adc_smartfit_adc_auto_v_boundary_RBUS smartfit_auto_v_boundary_reg;

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg,stAUTO_PARA.ucFieldControl);

	smartfit_auto_h_boundary_reg.regValue = 0;
	smartfit_auto_h_boundary_reg.hb_sta = stAUTO_PARA.usAutoHStart;
	smartfit_auto_h_boundary_reg.hb_end = stAUTO_PARA.usAutoHEnd;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg, smartfit_auto_h_boundary_reg.regValue);

	smartfit_auto_v_boundary_reg.regValue = 0;
	smartfit_auto_v_boundary_reg.vb_sta = stAUTO_PARA.usAutoVStart;
	smartfit_auto_v_boundary_reg.vb_end = stAUTO_PARA.usAutoVEnd;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg, smartfit_auto_v_boundary_reg.regValue);
	//printk(KERN_INFO "[TV]: HS=0x%3x=%4d HE=0x%3x=%4d VS=0x%3x=%4d VE=0x%3x=%4d\n",smartfit_auto_h_boundary_reg.hb_sta,smartfit_auto_h_boundary_reg.hb_sta,smartfit_auto_h_boundary_reg.hb_end,smartfit_auto_h_boundary_reg.hb_end,smartfit_auto_v_boundary_reg.vb_sta,smartfit_auto_v_boundary_reg.vb_sta,smartfit_auto_v_boundary_reg.vb_end,smartfit_auto_v_boundary_reg.vb_end);
}

static void  drvif_set_smartfit_boundary(void)
{
	smartfit_auto_h_boundary_RBUS smartfit_auto_h_boundary_reg;
	smartfit_auto_v_boundary_RBUS smartfit_auto_v_boundary_reg;

	//IoReg_Write32(SMARTFIT_AUTO_FIELD_reg,stAUTO_PARA.ucFieldControl);

	smartfit_auto_h_boundary_reg.regValue = 0;
	smartfit_auto_h_boundary_reg.hb_sta = stAUTO_PARA.usAutoHStart;
	smartfit_auto_h_boundary_reg.hb_end = stAUTO_PARA.usAutoHEnd;
	IoReg_Write32(SMARTFIT_AUTO_H_BOUNDARY_reg, smartfit_auto_h_boundary_reg.regValue);

	smartfit_auto_v_boundary_reg.regValue = 0;
	smartfit_auto_v_boundary_reg.vb_sta = stAUTO_PARA.usAutoVStart;
	smartfit_auto_v_boundary_reg.vb_end = stAUTO_PARA.usAutoVEnd;
	IoReg_Write32(SMARTFIT_AUTO_V_BOUNDARY_reg, smartfit_auto_v_boundary_reg.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ADC]: HS=0x%3x=%4d HE=0x%3x=%4d VS=0x%3x=%4d VE=0x%3x=%4d\n",smartfit_auto_h_boundary_reg.hb_sta,smartfit_auto_h_boundary_reg.hb_sta,smartfit_auto_h_boundary_reg.hb_end,smartfit_auto_h_boundary_reg.hb_end,smartfit_auto_v_boundary_reg.vb_sta,smartfit_auto_v_boundary_reg.vb_sta,smartfit_auto_v_boundary_reg.vb_end,smartfit_auto_v_boundary_reg.vb_end);
}


static void SelfAWB_setmeasureboundary(void)
{
	adc_smartfit_adc_auto_h_boundary_RBUS smartfit_auto_h_boundary_reg;
	adc_smartfit_adc_auto_v_boundary_RBUS smartfit_auto_v_boundary_reg;

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, stAUTO_PARA.ucFieldControl);

	smartfit_auto_h_boundary_reg.regValue = 0;
	smartfit_auto_h_boundary_reg.hb_sta = 0x300;
	smartfit_auto_h_boundary_reg.hb_end = 0x400;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg, smartfit_auto_h_boundary_reg.regValue);

	smartfit_auto_v_boundary_reg.regValue = 0;
	smartfit_auto_v_boundary_reg.vb_sta = 0x200;
	smartfit_auto_v_boundary_reg.vb_end = 0x300;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg, smartfit_auto_v_boundary_reg.regValue);
}


static void drvif_set_adc_smartfit_nm(void)
{
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);

	smartfit_auto_r_g_b_margin_reg.color_sel = stAUTO_PARA.ucColor & 0x03;
	smartfit_auto_r_g_b_margin_reg.blu_nm = (stAUTO_PARA.ucNMB>>Noise_Margin_Offset); //Mapping from blue->red
	smartfit_auto_r_g_b_margin_reg.vb_th = stAUTO_PARA.ucVBoundSearch & 0x03;
	smartfit_auto_r_g_b_margin_reg.grn_nm = (stAUTO_PARA.ucNMG>>Noise_Margin_Offset); //Mapping from green->blue
	smartfit_auto_r_g_b_margin_reg.adj_even_odd_en = stAUTO_PARA.ucFieldEnable & 0x01;
	smartfit_auto_r_g_b_margin_reg.adj_even_odd = stAUTO_PARA.ucFieldEnable & 0x02;
	smartfit_auto_r_g_b_margin_reg.red_nm = (stAUTO_PARA.ucNMR>>Noise_Margin_Offset); //Mapping from red->green

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);
}

static void drvif_set_smartfit_nm(void)
{
	smartfit_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_R_G_B_MARGIN_reg);

	//smartfit_auto_r_g_b_margin_reg.color_sel = stAUTO_PARA.ucColor & 0x03;
	smartfit_auto_r_g_b_margin_reg.blu_nm = (stAUTO_PARA.ucNMB>>Noise_Margin_Offset); //Mapping from blue->red
	smartfit_auto_r_g_b_margin_reg.vb_th = stAUTO_PARA.ucVBoundSearch & 0x03;
	smartfit_auto_r_g_b_margin_reg.grn_nm = (stAUTO_PARA.ucNMG>>Noise_Margin_Offset); //Mapping from green->blue
	//smartfit_auto_r_g_b_margin_reg.adj_even_odd_en = stAUTO_PARA.ucFieldEnable & 0x01;
	//smartfit_auto_r_g_b_margin_reg.adj_even_odd = stAUTO_PARA.ucFieldEnable & 0x02;
	smartfit_auto_r_g_b_margin_reg.red_nm = (stAUTO_PARA.ucNMR>>Noise_Margin_Offset); //Mapping from red->green

	IoReg_Write32(SMARTFIT_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);
}

static unsigned char drvif_adc_smartfit_waitfinish(unsigned char display)
{
	unsigned short Wait_Time_Cnt;
	vgip_vgip_chn1_status_RBUS vgip_vgip_chn1_status_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	sub_vgip_vgip_chn2_status_RBUS vgip_chn2_status_reg;
#endif
	adc_smartfit_adc_auto_adj_RBUS adc_smartfit_auto_adj_reg;

	// Wait until auto tracking finishes or timeout
	Wait_Time_Cnt = 0x2ff;
	do {
		msleep(1);//frank@0430 Change busy delay to save time
		adc_smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	} while ((adc_smartfit_auto_adj_reg.now_af) && (--Wait_Time_Cnt));

	if(SLR_MAIN_DISPLAY == display)
	{
		vgip_vgip_chn1_status_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg);
		vgip_vgip_chn1_status_reg.ch1_vs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_hs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_field_err = 1;
		vgip_vgip_chn1_status_reg.ch1_vact_start = 0;
		vgip_vgip_chn1_status_reg.ch1_vact_end = 0;
		IoReg_Write32(VGIP_VGIP_CHN1_STATUS_reg, vgip_vgip_chn1_status_reg.regValue);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else// if(SLR_SUB_DISPLAY == display)
	{
		vgip_chn2_status_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_STATUS_reg);
		vgip_chn2_status_reg.ch2_vs_err = 1;
		vgip_chn2_status_reg.ch2_hs_err = 1;
		vgip_chn2_status_reg.ch2_field_err = 1;
		vgip_chn2_status_reg.ch2_vact_start = 0;
		vgip_chn2_status_reg.ch2_vact_end = 0;
		IoReg_Write32(SUB_VGIP_VGIP_CHN2_STATUS_reg, vgip_chn2_status_reg.regValue);
	}
#endif

	return ((0 == Wait_Time_Cnt) ? ERROR_TIMEOUT : ERROR_SUCCEED);
}

static unsigned char auto_waitfinish(unsigned char display)
{
	unsigned short Wait_Time_Cnt;
	vgip_vgip_chn1_status_RBUS vgip_vgip_chn1_status_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	sub_vgip_vgip_chn2_status_RBUS vgip_chn2_status_reg;
#endif
	smartfit_auto_adj_RBUS smartfit_auto_adj_reg;

	// Wait until auto tracking finishes or timeout
	Wait_Time_Cnt = 0x2ff;
	do {
		msleep(1);//frank@0430 Change busy delay to save time
		smartfit_auto_adj_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_ADJ_reg);
	} while ((smartfit_auto_adj_reg.now_af) && (--Wait_Time_Cnt));

	if(SLR_MAIN_DISPLAY == display)
	{
		vgip_vgip_chn1_status_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg);
		vgip_vgip_chn1_status_reg.ch1_vs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_hs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_field_err = 1;
		vgip_vgip_chn1_status_reg.ch1_vact_start = 0;
		vgip_vgip_chn1_status_reg.ch1_vact_end = 0;
		IoReg_Write32(VGIP_VGIP_CHN1_STATUS_reg, vgip_vgip_chn1_status_reg.regValue);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else// if(SLR_SUB_DISPLAY == display)
	{
		vgip_chn2_status_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_STATUS_reg);
		vgip_chn2_status_reg.ch2_vs_err = 1;
		vgip_chn2_status_reg.ch2_hs_err = 1;
		vgip_chn2_status_reg.ch2_field_err = 1;
		vgip_chn2_status_reg.ch2_vact_start = 0;
		vgip_chn2_status_reg.ch2_vact_end = 0;
		IoReg_Write32(SUB_VGIP_VGIP_CHN2_STATUS_reg, vgip_chn2_status_reg.regValue);
	}
#endif

	return ((0 == Wait_Time_Cnt) ? ERROR_TIMEOUT : ERROR_SUCCEED);
}


static void drvif_get_h_boundary(unsigned char display)
{
	unsigned short curr_Hactive_start;
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();

	curr_Hactive_start =  p_dispinfo->IPH_ACT_STA_PRE;
	stAUTO_PARA.usAutoHEnd  =  p_dispinfo->INPUT_ADC_CLOCK;
	stAUTO_PARA.usAutoHStart   = (unsigned int)stAUTO_PARA.usAutoHEnd * (p_dispinfo->IHSyncPulseCount) / p_dispinfo->Hsync + 0x10;   // Clock number in HSYNC pulse

	if(stAUTO_PARA.usAutoHStart > (stAUTO_PARA.usAutoHEnd >> 1)) //the polarity is negtive
		stAUTO_PARA.usAutoHStart = stAUTO_PARA.usAutoHEnd - stAUTO_PARA.usAutoHStart;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Auto H boundary = %d\n",stAUTO_PARA.usAutoHStart);
	stAUTO_PARA.usAutoHEnd  = stAUTO_PARA.usAutoHEnd + _MEASURE_HDEALY;
	stAUTO_PARA.usAutoHStart   = (((stAUTO_PARA.usAutoHStart  + _MEASURE_HDEALY) < curr_Hactive_start)) ? (stAUTO_PARA.usAutoHStart + _MEASURE_HDEALY) : curr_Hactive_start ;
	if(stAUTO_PARA.usAutoHStart == curr_Hactive_start)
	{
		stAUTO_PARA.usAutoHStart = (curr_Hactive_start <= 8) ? 1: curr_Hactive_start-8;//At least 1
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Auto H boundary1 = %d\n",stAUTO_PARA.usAutoHStart);
}

static void drvif_get_v_boundary(unsigned char display)
{
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();

	stAUTO_PARA.usAutoVStart = 0x02;
	stAUTO_PARA.usAutoVEnd =  p_dispinfo->IVTotal;
}

void drvif_auto_ResetOffset(unsigned char ucReset)
{
	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;
 	static unsigned int Ori_offset0 = 0, Ori_offset1 = 0, changeflg = FALSE;

	//lewis 20091201, only for offset abnormal status, need change offset
	//if enable VGA ABL, turn it off
	if(TRUE == ucReset)
	{
//		if(SYNC_PROCESSOR1 == VGA_SP_PATH)
		{
			adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
			adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);

			#ifdef VGA_CLAMP_ON_G	//david modified 0420 enlarge ADC offset tolerance
			if((ABS(adc_offset0_reg.adc_off_red , 0x200) > 0x180)
				|| (ABS(adc_offset0_reg.adc_off_grn , 0x200) > 0x180)
				|| (ABS(adc_offset1_reg.adc_off_blu , 0x200) > 0x180))
			#else
			if((ABS(adc_offset0_reg.adc_off_red , 0x200) > 0x100)
				|| (ABS(adc_offset0_reg.adc_off_grn , 0x200) > 0x100)
				|| (ABS(adc_offset1_reg.adc_off_blu , 0x200) > 0x100))
			#endif
			{
				Ori_offset0 = adc_offset0_reg.regValue;
				Ori_offset1 = adc_offset1_reg.regValue;

				adc_offset0_reg.adc_off_red = 0x200;
				adc_offset0_reg.adc_off_grn = 0x200;
				IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);

				adc_offset1_reg.adc_off_blu = 0x200;
				IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);

				changeflg = TRUE;
			}
			else
			{
				changeflg = FALSE;
			}
 		}
	}
	else// if(FALSE == ucReset)
	{
//		if(SYNC_PROCESSOR1 == VGA_SP_PATH)
		{
			if(TRUE == changeflg)
			{
				IoReg_Write32(ADC_ADC_OFFSET0_reg, Ori_offset0);
				IoReg_Write32(ADC_ADC_OFFSET1_reg, Ori_offset1);
				changeflg = FALSE;
			}
		}
	}
}

unsigned char drv_auto_pre_check(unsigned char *select_result)
{
		unsigned char Result, color_path=0xFF;
		unsigned short ver_start,ver_end,hor_start,hor_end;
	
		adc_adc_clock_RBUS adc_clock_reg;
		adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;

#ifdef ADC_JUMP_PHASE_METHOD2
		adc_adc_clkgen_rgb_capture_RBUS adc_clkgen_rgb_capture_reg;
#endif //#ifdef ADC_JUMP_PHASE_METHOD2

		StructDisplayInfo *p_dispinfo = NULL;
		p_dispinfo = Get_ADC_Dispinfo();
		if(!p_dispinfo)
			return ERROR_ABORT;


		color_path = _COLORS_RED;

		Result = drvif_measure_v_position(SLR_MAIN_DISPLAY, 0xb0, 0xb0, 0xb0, &ver_start, &ver_end,color_path);
	#if 0
		if ((ERROR_SUCCEED != Result)||(ver_start>150)||(ver_end>2500))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT Result=0x%02x, ver_start=%d,ver_end=%d#####\n", __func__, __LINE__, Result, ver_start,ver_end);
			return ERROR_ABORT;
		}
	#else
		if ((ERROR_SUCCEED != Result)||((ver_start + p_dispinfo->IPV_ACT_LEN) > p_dispinfo->IVTotal))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT ver_start=%d\n!!! #####\n", __func__, __LINE__, ver_start);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPV_ACT_LEN=%d\n!!! #####\n", __func__, __LINE__, p_dispinfo->IPV_ACT_LEN);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IVTotal=%d\n!!! #####\n", __func__, __LINE__, p_dispinfo->IVTotal);
			return ERROR_ABORT;
		}
	#endif
		Result = drvif_measure_h_position(SLR_MAIN_DISPLAY, 0xb0, &hor_start, &hor_end,color_path);
	#if 0
		if ((ERROR_SUCCEED != Result)||(hor_start>1000)||(hor_end>4000))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT Result=0x%02x, hor_start=%d,hor_end=%d#####\n", __func__, __LINE__, Result, hor_start,hor_end);
			return ERROR_ABORT;
		}
	#else
		if ((ERROR_SUCCEED != Result)||((hor_start + p_dispinfo->IPH_ACT_WID) > p_dispinfo->IHTotal))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT hor_start=%d\n!!! #####\n", __func__, __LINE__, hor_start);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPH_ACT_WID=%d\n!!! #####\n", __func__, __LINE__, p_dispinfo->IPH_ACT_WID);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IHTotal=%d\n!!! #####\n", __func__, __LINE__, p_dispinfo->IHTotal);
			return ERROR_ABORT;
		}
	#endif

		if((ABS(p_dispinfo->IPH_ACT_STA_PRE, hor_start)>(p_dispinfo->IPH_ACT_WID_PRE>>2))||
			ABS(p_dispinfo->IPV_ACT_STA_PRE, ver_start)>(p_dispinfo->IPV_ACT_LEN_PRE>>2))
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPH_ACT_STA_PRE=%d#####\n", __func__, __LINE__,p_dispinfo->IPH_ACT_STA_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPH_ACT_WID_PRE=%d#####\n", __func__, __LINE__,p_dispinfo->IPH_ACT_WID_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPV_ACT_STA_PRE=%d#####\n", __func__, __LINE__,p_dispinfo->IPV_ACT_STA_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT IPV_ACT_LEN_PRE=%d#####\n", __func__, __LINE__,p_dispinfo->IPV_ACT_LEN_PRE);
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT ABS H=%d#####\n", __func__, __LINE__, ABS(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE), hor_start));
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT ABS V=%d#####\n", __func__, __LINE__, ABS(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE), ver_start));
			return ERROR_ABORT;
		}
	
		//jump phase
#ifdef ADC_JUMP_PHASE_METHOD2
		adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
		adc_clkgen_rgb_capture_reg.hs_catch_edge = 0; //jump phase
		IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_clkgen_rgb_capture_reg.regValue);
	
		adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
		adc_clock_reg.adc_2x_sample_5 = 1;
		IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);
#else //#ifdef ADC_JUMP_PHASE_METHOD2
		adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
		adc_clock_reg.adc_2x_sample_5 = 1;
		adc_clock_reg.adc_clock_6 = 0;
		IoReg_Write32(ADC_ADC_CLOCK_reg, adc_clock_reg.regValue);
#endif //#ifdef ADC_JUMP_PHASE_METHOD2
	
		adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
		adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut = 1; //set phase through Look-Up-Table
		adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = 0;//set the phase
		adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index = 0;
		IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);
	
		*select_result = color_path;

		return ERROR_SUCCEED;
}

unsigned char drvif_measure_v_position(unsigned char display, unsigned char NMR_V, unsigned char NMG_V, unsigned char NMB_V, unsigned short *v_start, unsigned short *v_end, unsigned char color)
{
	unsigned char result;
	//adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	//adc_smartfit_adc_auto_result_vsta_end_RBUS smartfit_auto_result_vsta_end_reg;
	smartfit_auto_adj_RBUS smartfit_auto_adj_reg;
	smartfit_auto_result_vsta_end_RBUS smartfit_auto_result_vsta_end_reg;

	drvif_get_h_boundary(display);
	drvif_get_v_boundary(display);
	drvif_set_smartfit_boundary();

	drvif_set_smartfit_auto_field_ctrl(display);

	//stAUTO_PARA.ucFieldControl = display ? 0x20:0x00;
	stAUTO_PARA.ucFieldEnable = 0;
	stAUTO_PARA.ucVBoundSearch = PIXEL_2;
	stAUTO_PARA.ucColor = color;
	stAUTO_PARA.ucNMR = NMR_V;
	stAUTO_PARA.ucNMG = NMG_V;
	stAUTO_PARA.ucNMB = NMB_V;
	drvif_set_smartfit_nm();

	smartfit_auto_adj_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_ADJ_reg);
	smartfit_auto_adj_reg.now_af = 1;
	IoReg_Write32(SMARTFIT_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);

	result = auto_waitfinish(display);
	if (ERROR_SUCCEED != result)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Error 1 result = 0x%02x#####\n", __func__, __LINE__, result);
		return result;
	}

	smartfit_auto_result_vsta_end_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_RESULT_VSTA_END_reg);
	*v_start = smartfit_auto_result_vsta_end_reg.vx_sta;
	*v_end = smartfit_auto_result_vsta_end_reg.vx_end;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*v_start=%d #####\n", __func__, __LINE__, *v_start);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*v_end=%d #####\n", __func__, __LINE__, *v_end);

	if((*v_end== 0x0000)||(*v_end<=*v_start))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Error 2 usVer_End == 0x0000#####\n", __func__, __LINE__);
		return  ERROR_ABORT;
	}

	stAUTO_PARA.usAutoVStart = *v_start;
	stAUTO_PARA.usAutoVEnd = *v_end;
	drvif_set_smartfit_boundary();

	return ERROR_SUCCEED;
}


unsigned char drvif_ypp_auto_phase_pre_setup(unsigned char display, unsigned char NMR_V, unsigned char NMG_V, unsigned char NMB_V, unsigned char color)
{//This api is for saving time. No need to use smart fit measure
	drvif_get_h_boundary(display);
	drvif_get_v_boundary(display);
	stAUTO_PARA.ucFieldControl = display ? 0x20:0x00;
	stAUTO_PARA.ucFieldEnable = 0;
	stAUTO_PARA.ucVBoundSearch = PIXEL_2;
	stAUTO_PARA.ucColor = color;
	stAUTO_PARA.ucNMR = NMR_V;
	stAUTO_PARA.ucNMG = NMG_V;
	stAUTO_PARA.ucNMB = NMB_V;
	drvif_set_adc_smartfit_nm();
	drvif_set_adc_smartfit_boundary();
	Reset_YPP_Auto_Phase_SmartFit_Setting();//Reset ypp auto phase related setting
	return TRUE;
}
//--------------------Measure Horizontal Position-------------------//
// Return Message => ERROR_SUCCESS   : Success  					//
//  				 ERROR_INPUT	 : 1. IVS or IHS changed		//
//  								   2. underflow or overflow 	//
//  				 ERROR_TIMEOUT   : Measure Time_Out 			//
//  				 ERROR_NOTACTIVE : No Avtive Image  			//
//------------------------------------------------------------------//
#define INTERNAL_H_DELAY     2

unsigned char drvif_measure_h_position(unsigned char display, unsigned short NM_H, unsigned short *h_start, unsigned short *h_end, unsigned char color)
{
	unsigned char result;
	//adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	//adc_smartfit_adc_auto_result_hsta_end_RBUS smartfit_auto_result_hsta_end_reg;
    //adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;
	smartfit_auto_adj_RBUS smartfit_auto_adj_reg;
	smartfit_auto_result_hsta_end_RBUS smartfit_auto_result_hsta_end_reg;


	drvif_get_h_boundary(display);
	drvif_set_smartfit_boundary();
	drvif_set_smartfit_auto_field_ctrl(display);

	//stAUTO_PARA.ucFieldControl = display ? 0x20:0x00;
	stAUTO_PARA.ucFieldEnable = 0;
	stAUTO_PARA.ucVBoundSearch = PIXEL_2;
	stAUTO_PARA.ucColor = color;
	stAUTO_PARA.ucNMR = NM_H;
	stAUTO_PARA.ucNMG = NM_H;
	stAUTO_PARA.ucNMB = NM_H;
	drvif_set_smartfit_nm();

 	smartfit_auto_adj_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_ADJ_reg);
	smartfit_auto_adj_reg.now_af = 1;
	IoReg_Write32(SMARTFIT_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);

	result = auto_waitfinish(display);

	if (ERROR_SUCCEED != result)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Error 1 result=0x%02x#####\n", __func__, __LINE__, result);
		return result;
	}

	smartfit_auto_result_hsta_end_reg.regValue = IoReg_Read32(SMARTFIT_AUTO_RESULT_HSTA_END_reg);
	*h_start = smartfit_auto_result_hsta_end_reg.hx_sta;
	*h_end = smartfit_auto_result_hsta_end_reg.hx_end;

	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]hx_sta=%d, hx_end=%d\n", __func__, __LINE__, smartfit_auto_result_hsta_end_reg.hx_sta, smartfit_auto_result_hsta_end_reg.hx_end);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*h_start=%d, *h_end=%d\n", __func__, __LINE__, *h_start, *h_end);

	if((*h_end == 0x0000)||(*h_end <= *h_start))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Error 2 h_end == 0x0000#####\n", __func__, __LINE__);
		return  ERROR_ABORT;
	}

	stAUTO_PARA.usAutoHStart = *h_start;
	stAUTO_PARA.usAutoHEnd = *h_end;
	drvif_set_smartfit_boundary();

	return ERROR_SUCCEED;
}

static unsigned char check_v_auto_position_result(unsigned int vstart, unsigned int vend, StructDisplayInfo *adc_dispinfo)
{//TRUE:pass  FALSE:NG
	unsigned int v_diff_th = 0;
	unsigned int actsize;
	if(adc_dispinfo)
	{
		if(vstart >= vend)
			return FALSE;
		actsize = vend - vstart;
		v_diff_th = adc_dispinfo->IPV_ACT_LEN_PRE / 5;
		if(adc_dispinfo->IPV_ACT_LEN_PRE >= actsize)
		{
			if((adc_dispinfo->IPV_ACT_LEN_PRE - actsize) >= v_diff_th)
				return FALSE;
		}
		else
		{
			if((actsize - adc_dispinfo->IPV_ACT_LEN_PRE) >= v_diff_th)
				return FALSE;
		}
		if(actsize > adc_dispinfo->IVTotal)
			return FALSE;
		
	}
	return TRUE;
}

static unsigned char check_h_auto_position_result(unsigned int hstart, unsigned int hend, StructDisplayInfo *adc_dispinfo)
{//TRUE:pass  FALSE:NG
	unsigned int h_diff_th = 0;
	unsigned int actsize;
	if(adc_dispinfo)
	{
		if(hstart >= hend)
			return FALSE;
		actsize = hend - hstart;
		h_diff_th = adc_dispinfo->IPH_ACT_WID_PRE / 5;
		if(adc_dispinfo->IPH_ACT_WID_PRE >= actsize)
		{
			if((adc_dispinfo->IPH_ACT_WID_PRE - actsize) >= h_diff_th)
				return FALSE;
		}
		else
		{
			if((actsize - adc_dispinfo->IPH_ACT_WID_PRE) >= h_diff_th)
				return FALSE;
		}
		if(actsize > adc_dispinfo->IHTotal)
			return FALSE;
		
	}
	return TRUE;
}

void auto_AdcGainAdjustReset()
{
	R_GainAdjustMax = 511;//Sirius range is 0-511
	R_GainAdjustMin = 0;
	G_GainAdjustMax = 511;//Sirius range is 0-511
	G_GainAdjustMin = 0;
	B_GainAdjustMax = 511;//Sirius range is 0-511
	B_GainAdjustMin = 0;
}

static void drvif_self_awb_getnewgain(unsigned char color, unsigned short delta,
	unsigned char inc ,unsigned short *pGain)
{
	unsigned short usCurGain = 0, *pGainAdjustMax = &G_GainAdjustMax, *pGainAdjustMin = &G_GainAdjustMin;
	usCurGain = *pGain;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "color=%d, inc=%d, OriGain=%d\n", color, inc, *pGain);
	switch(color)
	{
		case SELECT_RED:
			pGainAdjustMax = &R_GainAdjustMax;
			pGainAdjustMin = &R_GainAdjustMin;
			break;

		case SELECT_GREEN:
			pGainAdjustMax = &G_GainAdjustMax;
			pGainAdjustMin = &G_GainAdjustMin;
			break;

		case SELECT_BLUE:
			pGainAdjustMax = &B_GainAdjustMax;
			pGainAdjustMin = &B_GainAdjustMin;
			break;

		default:
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\r\ndrvif_self_awb_getnewgain Error color\r\n");
			return;
	}


	if (inc) {
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "0  inc=%d\n", inc);
		// delta = the difference with target diff
		//usCurGain  = usCurGain + delta;
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "0   usCurGain=%d\n", usCurGain);
		*pGainAdjustMin = usCurGain;
		usCurGain = ( *pGainAdjustMin + *pGainAdjustMax) / 2;
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "0   min=%d, max=%d newgain=%d\n", *pGainAdjustMin, *pGainAdjustMax, usCurGain);

	}
	else
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "1  inc=%d\n", inc);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "1   usCurGain=%d\n", usCurGain);
		*pGainAdjustMax = usCurGain;
		usCurGain = ( *pGainAdjustMin + *pGainAdjustMax) / 2;
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "1   min=%d, max=%d newgain=%d\n", *pGainAdjustMin, *pGainAdjustMax, usCurGain);
	}


	*pGain = usCurGain;
}



#if 0
static unsigned char auto_adcgainoffsetadjust(unsigned char color, unsigned short delta,
	unsigned char inc, unsigned char saturate, unsigned short* Gain_Offset)
{
       unsigned short usTemp;

	usTemp = inc ? (0x1ff - *Gain_Offset):*Gain_Offset;

	if (inc) {
		if (usTemp > delta)
			*Gain_Offset += delta;
		else {
			*Gain_Offset = 0x1ff;
			saturate |= color;
		}
	} else {
		if (usTemp > delta)
			*Gain_Offset -= delta;
		else {
			*Gain_Offset = 0;
			saturate |= color;
		}
	}
	return saturate;

}
#endif
static void auto_adcgainset(int src, ADCGainOffset * ptADC_info)
{

	UINT8  ucSwap = 0;
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;


	if(src == _SRC_VGA){ 	// weihao 960308
		adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
		ucSwap = adc_adc_clkgen_rgb_capture_reg.adc_swap;

		if((ucSwap == _ADC_SWAP_PATH2) || (ucSwap == _ADC_SWAP_PATH3) ||
			(ucSwap == _ADC_SWAP_PATH6) || (ucSwap == _ADC_SWAP_PATH7))  //Bin -> Rout
			drvif_auto_setcolorgainoffset(_B_GAIN_INDEX, ptADC_info->Gain_R); // BLUE_GAIN
		else if((ucSwap == _ADC_SWAP_PATH1) || (ucSwap == _ADC_SWAP_PATH5)) //Gin -> Rout
			drvif_auto_setcolorgainoffset(_G_GAIN_INDEX, ptADC_info->Gain_R); // GREEN_GAIN
		else
			drvif_auto_setcolorgainoffset(_R_GAIN_INDEX, ptADC_info->Gain_R); // RED_GAIN

		if((ucSwap == _ADC_SWAP_PATH4) || (ucSwap == _ADC_SWAP_PATH5)) //Bin -> Gout
			drvif_auto_setcolorgainoffset(_B_GAIN_INDEX, ptADC_info->Gain_G); // BLUE_GAIN
		else if((ucSwap == _ADC_SWAP_PATH1) || (ucSwap == _ADC_SWAP_PATH3)  ||
			(ucSwap == _ADC_SWAP_PATH6) ) //Rin -> Gout
			drvif_auto_setcolorgainoffset(_R_GAIN_INDEX, ptADC_info->Gain_G); // RED_GAIN
		else
			drvif_auto_setcolorgainoffset(_G_GAIN_INDEX, ptADC_info->Gain_G); // GREEN_GAIN

		if((ucSwap == _ADC_SWAP_PATH3) || (ucSwap == _ADC_SWAP_PATH4) ||
			(ucSwap == _ADC_SWAP_PATH6)) //Gin -> Bout
			drvif_auto_setcolorgainoffset(_G_GAIN_INDEX, ptADC_info->Gain_B); // GREEN_GAIN
		else if((ucSwap == _ADC_SWAP_PATH2) || (ucSwap == _ADC_SWAP_PATH5) ||
			(ucSwap == _ADC_SWAP_PATH7)) //Rin -> Bout
			drvif_auto_setcolorgainoffset(_R_GAIN_INDEX, ptADC_info->Gain_B); // RED_GAIN
		else //Bin -> Bout
		{
			//printk(KERN_INFO "\nSA Blue Gain BIOS = 0x%x=%d",ptADCGainOffset->Gain_B,ptADCGainOffset->Gain_B);
			drvif_auto_setcolorgainoffset(_B_GAIN_INDEX, ptADC_info->Gain_B); // BLUE_GAIN
		}

	}
	else if(src == _SRC_YPBPR) 	// weihao 960308
	{
		drvif_auto_setcolorgainoffset(_R_GAIN_INDEX, ptADC_info->Gain_R); // RED_GAIN
		drvif_auto_setcolorgainoffset(_G_GAIN_INDEX, ptADC_info->Gain_G); // GREEN_GAIN
		drvif_auto_setcolorgainoffset(_B_GAIN_INDEX, ptADC_info->Gain_B); // BLUE_GAIN
	}
}

static void auto_adcoffsetset(int src, ADCGainOffset * ptADC_info)
{
	drvif_auto_setcolorgainoffset(_R_OFFSET_INDEX, ptADC_info->Offset_R);
	drvif_auto_setcolorgainoffset(_G_OFFSET_INDEX, ptADC_info->Offset_G);
	drvif_auto_setcolorgainoffset(_B_OFFSET_INDEX, ptADC_info->Offset_B);

}

static void drvif_self_awb_changegain(UINT8 color, UINT16 delta, UINT8 inc, int src, ADCGainOffset * ptADC_info)
{

	if(delta >= 2)
	{
	    if (color & SELECT_RED) {//forster modified 050728
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "drvif_self_awb_changegain RED delta=%d, inc=%d,  ptADCGainOffset->Gain_R=%d\n", delta, inc, ptADC_info->Gain_R);
			drvif_self_awb_getnewgain(SELECT_RED, delta, inc,  (UINT16 *)&ptADC_info->Gain_R);
			if(src == _SRC_YPBPR) drvif_auto_setcolorgainoffset(_R_GAIN_INDEX, ptADC_info->Gain_R); // RED_GAIN
	    }

	    if (color & SELECT_GREEN) {//forster modified 050728
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "drvif_self_awb_changegain GREEN delta=%d, inc=%d, ptADCGainOffset->Gain_G=%d\n", delta, inc,  ptADC_info->Gain_G);
			drvif_self_awb_getnewgain(SELECT_GREEN, delta, inc,  (UINT16*)&ptADC_info->Gain_G);
			if(src == _SRC_YPBPR) drvif_auto_setcolorgainoffset(_G_GAIN_INDEX, ptADC_info->Gain_G); // GREEN_GAIN
	    }

	    if (color & SELECT_BLUE) {//forster modified 050728
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "drvif_self_awb_changegain BLUE delta=%d, inc=%d, ptADCGainOffset->Gain_B=%d\n", delta, inc,  ptADC_info->Gain_B);
			drvif_self_awb_getnewgain(SELECT_BLUE, delta, inc, (UINT16*)&ptADC_info->Gain_B);
			if(src == _SRC_YPBPR) drvif_auto_setcolorgainoffset(_B_GAIN_INDEX, ptADC_info->Gain_B); // BLUE_GAIN
	    }
	}
	if(src == _SRC_VGA) auto_adcgainset(src, ptADC_info);
}

void drvif_auto_gettargetvalue(unsigned char display, unsigned short* max_value, unsigned short* min_value, unsigned char color)
{
	switch(_SRC_YPBPR)//Fix error by Will//(Scaler_InputSrcGetType((SCALER_DISP_CHANNEL)display)) 	// weihao 960308
	//        switch(info->input_src)
	{
	case _SRC_VGA: 	// weihao 960308
		*max_value = _AUTO_VGA_MAX_LEVEL;
		*min_value = _AUTO_VGA_MIN_LEVEL;
	break;
	case _SRC_YPBPR: 	// weihao 960308
	 	  if(color == SELECT_GREEN)//_GREEN)
	 	  {
	 	      *max_value = _AUTO_COMPONENT_Y_MAX_LEVEL;
			*min_value = _AUTO_COMPONENT_Y_MIN_LEVEL;
	 	  }
		  else
		  {
		      //*max_value = (color == _RED) ? _AUTO_COMPONENT_PR_MAX_LEVEL : _AUTO_COMPONENT_PB_MAX_LEVEL;
		      *max_value = (color == SELECT_RED) ? _AUTO_COMPONENT_PR_MAX_LEVEL : _AUTO_COMPONENT_PB_MAX_LEVEL;
		      *min_value = _CHROMA_BLACK_LEVEL;
		  }
		  break;

#if 0//(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	case _SRC_CVBS: 	// weihao 960308
	case _SRC_SV: 	// weihao 960308
		if(color == SELECT_GREEN)
		{
			*max_value = _AUTO_VIDEO8_Y_MAX_LEVEL;
			*min_value = _AUTO_VIDEO8_Y_MIN_LEVEL;
		}
		else
		{
			*max_value = _AUTO_VIDEO8_C_MAX_LEVEL;
			*min_value = _CHROMA_BLACK_LEVEL;
		}
	         break;
#endif

	}
}
#if 0//Not used, rzhen@2018-01-05
void drvif_SelfAWB_gettargetvalue(UINT16* target, UINT8 color, UINT8 src)
{
	#if 0	//compile error
	abl_reserved_RBUS abl_Reserved_reg;//leochen
	#endif
	enum PLAFTORM_TYPE platform = PLATFORM_KXL;
	UINT16 target_y = KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y, target_pb = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB, target_pr = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR;

#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0);//tick system WD, to avoid system reset
#endif

	switch(src) 	// weihao 960308
	{
		case _SRC_VGA: 	// weihao 960308

			if(color == SELECT_GREEN)
				*target = _AUTO_SELF_VGA_LEVEL_TARGET_G; //_SELF_VGA_LEVEL_IDEAL_TARGET_G + DELTA_V1_TARGET_G_OFFSET1 + DELTA_V2_TARGET_G_OFFSET2;
			else if(color == SELECT_RED)
				*target =  _AUTO_SELF_VGA_LEVEL_TARGET_R; //_SELF_VGA_LEVEL_IDEAL_TARGET_R +  DELTA_V1_TARGET_R_OFFSET1 + DELTA_V2_TARGET_R_OFFSET2;
			else
				*target = _AUTO_SELF_VGA_LEVEL_TARGET_B; //_SELF_VGA_LEVEL_IDEAL_TARGET_B +  DELTA_V1_TARGET_B_OFFSET1 + DELTA_V2_TARGET_B_OFFSET2;
			#if 0	//compile error
			abl_Reserved_reg.regValue = IoReg_Read32(ABL_Reserved_reg);//leochen
			abl_Reserved_reg.self_awb_code_diff_r=_AUTO_SELF_VGA_LEVEL_TARGET_R;//leochen
			abl_Reserved_reg.self_awb_code_diff_g=_AUTO_SELF_VGA_LEVEL_TARGET_G;//leochen
			abl_Reserved_reg.self_awb_code_diff_b=_AUTO_SELF_VGA_LEVEL_TARGET_B;//leochen
			IoReg_Write32(ABL_Reserved_reg, abl_Reserved_reg.regValue);//leochen
			#endif
			//printk(KERN_INFO "@@@@@@@@max_value=0x%x=%d\n",*max_value,*max_value);
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "target=0x%x=%d\n\n",*target,*target);
			break;

		case _SRC_YPBPR: 	// weihao 960308
			platform = get_platform();//Get platform
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "###[%s(line: %d)]platform=%d###\n\n", __func__, __LINE__, platform);
			if(platform == PLATFORM_KXLP) {
				target_y = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_Y;
				target_pb = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PB;
				target_pr = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			}

			if(color == SELECT_GREEN)//_GREEN)
			{
				*target = target_y;
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Y target=0x%x=%d\n\n",*target,*target);
			}
			else if(color == SELECT_RED)
			{
				*target =  target_pr;
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Pr target=0x%x=%d\n\n",*target,*target);
			}
			else
			{
				*target = target_pb;
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Pb target=0x%x=%d\n\n",*target,*target);
			}
			#if 0	//compile error
			abl_Reserved_reg.regValue = IoReg_Read32(ABL_Reserved_reg);//leochen
			abl_Reserved_reg.self_awb_code_diff_r = target_pr;//leochen
			abl_Reserved_reg.self_awb_code_diff_g = target_y;//leochen
			abl_Reserved_reg.self_awb_code_diff_b = target_pb;//leochen
			IoReg_Write32(ABL_Reserved_reg, abl_Reserved_reg.regValue);//leochen
			#endif
			break;
	}
}
#endif
void drvif_get_default_gainvalue(UINT16* gain_value_r, UINT16* gain_value_g, UINT16* gain_value_b ,UINT8 src)
{
	switch(src)
	{
		case _SRC_VGA:
			*gain_value_r = _AUTO_VGA_DEFAULT_GAIN_R;
			*gain_value_g = _AUTO_VGA_DEFAULT_GAIN_G;
			*gain_value_b = _AUTO_VGA_DEFAULT_GAIN_B;
			break;
		case _SRC_YPBPR:
			*gain_value_r = _AUTO_YPP_DEFAULT_GAIN_PR;
			*gain_value_g = _AUTO_YPP_DEFAULT_GAIN_Y;
			*gain_value_b = _AUTO_YPP_DEFAULT_GAIN_PB;
			break;
		default:
			*gain_value_r = _AUTO_VGA_DEFAULT_GAIN_R;
			*gain_value_g = _AUTO_VGA_DEFAULT_GAIN_G;
			*gain_value_b = _AUTO_VGA_DEFAULT_GAIN_B;
			break;
	}
}

UINT8 drvif_SelfAWB_measurecolor(UINT8 color, UINT8 margin, UINT16* voltagevalue)
{
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);

	if(SELECT_RED == color)
		smartfit_auto_r_g_b_margin_reg.color_sel = _COLORS_RED;
	else if(SELECT_GREEN == color)
		smartfit_auto_r_g_b_margin_reg.color_sel = _COLORS_GREEN;
	else// if(SELECT_BLUE== color)
		smartfit_auto_r_g_b_margin_reg.color_sel = _COLORS_BLUE;

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);

	stAUTO_PARA.ucFieldControl = 0;

	if( Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	   	stAUTO_PARA.ucFieldControl |= 0x20;

	SelfAWB_setmeasureboundary();

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	smartfit_auto_field_reg.auto_balance_rgb = 2; //only 1 channel use color_sel 0x1802_040c[9:8] to choose.
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg,smartfit_auto_field_reg.regValue);

	smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	smartfit_auto_adj_reg.m_vgen_en = 0; //add in modestate.c
	smartfit_auto_adj_reg.diff_pixel_sel = 1;
	if (_COLOR_MIN == margin)
		smartfit_auto_adj_reg.force_flip_ = 0;
	else// if (_COLOR_MAX == margin)
		smartfit_auto_adj_reg.force_flip_ = 1;
	smartfit_auto_adj_reg.sum_max = 0;
	smartfit_auto_adj_reg.pulse_det_en = 0;
	smartfit_auto_adj_reg.autophase_sel_tri = 0;
	smartfit_auto_adj_reg.diff_en = 0;
	smartfit_auto_adj_reg.now_af = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);

	//forster modified 041112
	if(drvif_adc_smartfit_waitfinish(SLR_MAIN_DISPLAY))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Measure Error Abort\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]0xB8020420 = 0x%8x\n", __FUNCTION__, __LINE__, IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg));
	*voltagevalue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg) & 0x03ff;

	if(*voltagevalue == 0)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*voltagevalue is 0 Fail. Abort\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	if (_COLOR_MIN == margin)
		*voltagevalue ^= 0x3ff;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SelfAWB measurecolor Measure Color=%x Margin = %d\n", __FUNCTION__, __LINE__, color, *voltagevalue);
	return ERROR_SUCCEED;

}

static UINT16 g_ulAWBTargetDiff_R = 0;
static UINT16 g_ulAWBTargetDiff_G = 0;
static UINT16 g_ulAWBTargetDiff_B = 0;

unsigned char drvif_self_awb_calculate_target_diff(int src , UINT8 ucColor)
{
	UINT16 code_diff;
	UINT16 temp_high;
	UINT16 temp_low;
	UINT16 measureresult;
	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	//abl_reserved_RBUS abl_Reserved_reg;//leochen
	adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	// Change voltage
	adc_adc_vbias_reg.adc_vbias2_2_0 = 4; //0.85V
	//auto_vbias_voltage_reg.adc_vbias2_2_0 = 5; // 1V
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(src == _SRC_VGA){
		if(drvif_auto_measurecolor(SLR_MAIN_DISPLAY, ucColor, _COLOR_MAX, &measureresult) != ERROR_SUCCEED){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Error	Gain ABORT 0 %c", __FUNCTION__, __LINE__, '!');
			return FALSE;
		}
	}else{
		if(drvif_SelfAWB_measurecolor(ucColor, _COLOR_MAX, &measureresult) != ERROR_SUCCEED){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Error  Gain ABORT 0 %c", __FUNCTION__, __LINE__, '!');
			return FALSE;
		}
	}

	temp_high = measureresult;
	//printk(KERN_INFO "[Get Target Diff] HIGH=%3d ",temp_high);

	//Change Low
	adc_adc_vbias_reg.adc_vbias2_2_0 = 2;//0.55V
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(src == _SRC_VGA){
		if(drvif_auto_measurecolor(SLR_MAIN_DISPLAY, ucColor, _COLOR_MAX, &measureresult) != ERROR_SUCCEED){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Error Gain ABORT 1 %c", __FUNCTION__, __LINE__, '!');
			return FALSE;
		}
	}else{
		if(drvif_SelfAWB_measurecolor(ucColor, _COLOR_MAX, &measureresult) != ERROR_SUCCEED){
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Error Gain ABORT 1 %c", __FUNCTION__, __LINE__, '!');
			return FALSE;
		}
	}

	temp_low = measureresult;
	//printk(KERN_INFO "LOW=%3d Diff=%3d\n",temp_low,temp_high-temp_low);

	//printk(KERN_INFO "color=%x temp_high=%x temp_low=%x\n", ucColor,temp_high,temp_low);

	//abl_Reserved_reg.regValue = IoReg_Read32(ABL_Reserved_reg);//leochen
	code_diff = (temp_high-temp_low);

	switch(ucColor)
	{
	case 1:
		if(src == _SRC_VGA)
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Red HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		else
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Pr HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		#if 0	//compile error
		abl_Reserved_reg.self_awb_code_diff_r = code_diff;//leochen
		#endif
		g_ulAWBTargetDiff_R = code_diff;;

		break;
	case 2:
		if(src == _SRC_VGA)
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Grn HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		else
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Y HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		#if 0	//compile error
		abl_Reserved_reg.self_awb_code_diff_g = code_diff;//leochen
		#endif

		g_ulAWBTargetDiff_G = code_diff;;
		break;
	case 4:
		if(src == _SRC_VGA)
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Blu HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		else
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Pb HIGH=%3d LOW=%3d Diff=0x%3x=%3d ", __FUNCTION__, __LINE__, temp_high,temp_low,code_diff,code_diff);
		#if 0	//compile error
		abl_Reserved_reg.self_awb_code_diff_b = code_diff;//leochen
		#endif

		g_ulAWBTargetDiff_B = code_diff;;
		break;
	default:
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] color error!\n", __FUNCTION__, __LINE__);
		break;
	}
	//IoReg_Write32(ABL_Reserved_reg, abl_Reserved_reg.regValue);//leochen
	return TRUE;
}

void drvif_SelfAWB_GetTargetDiff(UINT16 *a_pusDiff_R, UINT16 *a_pusDiff_G, UINT16 *a_pusDiff_B)
{
	*a_pusDiff_R = g_ulAWBTargetDiff_R;
	*a_pusDiff_G = g_ulAWBTargetDiff_G;
	*a_pusDiff_B = g_ulAWBTargetDiff_B;
}


UINT16 drvif_SelfAWB_GetTargetDiff_R(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "g_ulAWBTargetDiff_R=%d\n", g_ulAWBTargetDiff_R);
	return g_ulAWBTargetDiff_R;
}

UINT16 drvif_SelfAWB_GetTargetDiff_G(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "g_ulAWBTargetDiff_G=%d\n", g_ulAWBTargetDiff_G);
	return g_ulAWBTargetDiff_G;
}

UINT16 drvif_SelfAWB_GetTargetDiff_B(void)
{
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "g_ulAWBTargetDiff_B=%d\n", g_ulAWBTargetDiff_B);
	return g_ulAWBTargetDiff_B;
}

UINT8 drvif_SelfAWB_allchannel_measure_voltagevaule(UINT8 margin, unsigned char r_ready,  unsigned char g_ready, unsigned char b_ready, UINT16 *r_voltage_diffresult, UINT16 *g_voltage_diffresult, UINT16 *b_voltage_diffresult)
{
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;

	stAUTO_PARA.ucFieldControl = 0;//smartfit_auto_field_reg.reg_auto_balance_rgb = 1;

	SelfAWB_setmeasureboundary();

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	smartfit_auto_field_reg.auto_balance_rgb = 3;  // speed up Self AWB,measure RGB value togher.  brnadon add for LG
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, smartfit_auto_field_reg.regValue);

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_r_g_b_margin_reg.color_sel = 2;		// speed up Self AWB,measure RGB value togher.  brnadon add for LG
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);

	smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	smartfit_auto_adj_reg.m_vgen_en = 0; //add in modestate.c
	smartfit_auto_adj_reg.diff_pixel_sel = 1;
	if (_COLOR_MIN == margin)
		smartfit_auto_adj_reg.force_flip_ = 0;
	else// if (_COLOR_MAX == margin)
		smartfit_auto_adj_reg.force_flip_ = 1;
	smartfit_auto_adj_reg.sum_max = 0;
	smartfit_auto_adj_reg.pulse_det_en = 0;
	smartfit_auto_adj_reg.autophase_sel_tri = 0;
	smartfit_auto_adj_reg.diff_en = 0;
	smartfit_auto_adj_reg.now_af = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);

	//forster modified 041112
	if(drvif_adc_smartfit_waitfinish(SLR_MAIN_DISPLAY))
	{
	    rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Measure Error Abort\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	if(r_ready == FALSE)
	{
		*r_voltage_diffresult = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg) & 0x03ff;
		if(*r_voltage_diffresult == 0)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*r_voltage_diffresult is 0. Error Abort#######\r\n", __FUNCTION__, __LINE__);
			return ERROR_ABORT;
		}
	}
	if(g_ready == FALSE)
	{
		*g_voltage_diffresult = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg) & 0x03ff;
		if(*g_voltage_diffresult == 0)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*g_voltage_diffresult is 0. Error Abort#######\r\n", __FUNCTION__, __LINE__);
			return ERROR_ABORT;
		}
	}
	if(b_ready == FALSE)
	{
		*b_voltage_diffresult = (IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg)>>16) & 0x03ff;
		if(*b_voltage_diffresult == 0)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]*b_voltage_diffresult is 0. Error Abort#######\r\n", __FUNCTION__, __LINE__);
			return ERROR_ABORT;
		}
	}

	if (_COLOR_MIN == margin)
	{
	   if(r_ready == FALSE) *r_voltage_diffresult ^= 0x3ff;
	   if(g_ready == FALSE) *g_voltage_diffresult ^= 0x3ff;
	   if(b_ready == FALSE) *b_voltage_diffresult ^= 0x3ff;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Measure success!!!\n", __FUNCTION__, __LINE__);
	return ERROR_SUCCEED;

}

UINT8 drvif_self_awb_gain_adjust_allchannel_proc(unsigned char r_ready,  unsigned char g_ready, unsigned char b_ready,
	UINT16 *r_voltage_diffresult, UINT16 *g_voltage_diffresult, UINT16 *b_voltage_diffresult, int src, ADCGainOffset * ptADC_info)
{
	//printk(KERN_INFO "\ndrvif_SelfAWB_tunedevicegain!");
	enum PLAFTORM_TYPE platform = PLATFORM_KXL;
	UINT8 color = SELECT_BLUE;
	UINT16 delta;
    UINT16 temp_r_high =0, temp_g_high=0, temp_b_high=0;
    UINT16 temp_r_low=0, temp_g_low=0, temp_b_low=0;
	UINT16 difftarget_g = KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y, difftarget_r = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR, difftarget_b = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB;
	adc_adc_vbias_RBUS adc_adc_vbias_reg;

    adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	// Change voltage
	adc_adc_vbias_reg.adc_vbias2_2_0 = 4; // 0.85V
    IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(drvif_SelfAWB_allchannel_measure_voltagevaule(_COLOR_MAX, r_ready, g_ready, b_ready, r_voltage_diffresult, g_voltage_diffresult, b_voltage_diffresult) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][SelfAWB] Error  Gain ABORT 0 %c", __FUNCTION__, __LINE__, '!');
		return ERROR_ABORT;
	}
    if(r_ready == FALSE) temp_r_high = *r_voltage_diffresult;
	if(g_ready == FALSE) temp_g_high = *g_voltage_diffresult;
	if(b_ready == FALSE) temp_b_high = *b_voltage_diffresult;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]HIGH=%3d %3d %3d\r\n ", __FUNCTION__, __LINE__, temp_r_high, temp_g_high, temp_b_high);


	//Change Low
    adc_adc_vbias_reg.adc_vbias2_2_0 = 2;//0.55V
    IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(drvif_SelfAWB_allchannel_measure_voltagevaule(_COLOR_MAX, r_ready, g_ready, b_ready, r_voltage_diffresult, g_voltage_diffresult, b_voltage_diffresult) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][SelfAWB] Error Gain ABORT 1 %c", __FUNCTION__, __LINE__, '!');
		return ERROR_ABORT;
	}
    if(r_ready == FALSE) temp_r_low = *r_voltage_diffresult;
	if(g_ready == FALSE) temp_g_low = *g_voltage_diffresult;
	if(b_ready == FALSE) temp_b_low = *b_voltage_diffresult;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]LOW=%3d %3d %3d\n", __FUNCTION__, __LINE__, temp_r_low, temp_g_low, temp_b_low);

    if(r_ready == FALSE) *r_voltage_diffresult = temp_r_high - temp_r_low;
	if(g_ready == FALSE) *g_voltage_diffresult = temp_g_high - temp_g_low;
	if(b_ready == FALSE) *b_voltage_diffresult = temp_b_high - temp_b_low;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Diff=%3d %3d %3d\n", __FUNCTION__, __LINE__, *r_voltage_diffresult, *g_voltage_diffresult, *b_voltage_diffresult);

	if(src ==_SRC_YPBPR)
	{
		platform = get_platform();//Get platform
		if(platform == PLATFORM_KXLP)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __func__, __LINE__);
			difftarget_g = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_Y;
			difftarget_r = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			difftarget_b = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PB;
		}
		else
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __func__, __LINE__);
			difftarget_g = KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y;
			difftarget_r = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			difftarget_b = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB;
		}
	}
	else if(src ==_SRC_VGA)
	{
		difftarget_g = _AUTO_SELF_VGA_LEVEL_TARGET_G;
		difftarget_r = _AUTO_SELF_VGA_LEVEL_TARGET_R;
		difftarget_b = _AUTO_SELF_VGA_LEVEL_TARGET_B;
	}

    rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]R diffresult=%d, ucMax_Target=%d\n", __func__, __LINE__, *r_voltage_diffresult, difftarget_r);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]G diffresult=%d, ucMax_Target=%d\n", __func__, __LINE__, *g_voltage_diffresult, difftarget_g);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]B diffresult=%d, ucMax_Target=%d\n", __func__, __LINE__, *b_voltage_diffresult, difftarget_b);

	color = SELECT_BLUE;
	while(color)
	{
		if((color == SELECT_RED) && (r_ready == FALSE))
		{
		    if(*r_voltage_diffresult > difftarget_r)
		    {
				delta  = *r_voltage_diffresult - difftarget_r;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_RED Increase Gain   temp=%d\n", __func__, __LINE__, delta);
				drvif_self_awb_changegain(color, delta, 1, src, ptADC_info);                 // Increse Gain; Decrease Contrast

			}else if(*r_voltage_diffresult < difftarget_r){
				delta  = difftarget_r - *r_voltage_diffresult;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_RED Decrease Gain  temp=%d\n", __func__, __LINE__, delta);
				// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
				drvif_self_awb_changegain(color, delta, 0, src, ptADC_info);                   // Decrease Gain; Increse Contrast

			}
		}
		else if((color == SELECT_GREEN) && (g_ready == FALSE))
		{
		    if(*g_voltage_diffresult > difftarget_g)
		    {
				delta  = *g_voltage_diffresult - difftarget_g;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_GREEN Increase Gain   temp=%d\n", __func__, __LINE__, delta);
				drvif_self_awb_changegain(color, delta, 1, src, ptADC_info);                 // Increse Gain; Decrease Contrast

			}else if(*g_voltage_diffresult < difftarget_g){
				delta  = difftarget_g - *g_voltage_diffresult;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_GREEN Decrease Gain  temp=%d\n", __func__, __LINE__, delta);
				// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
				drvif_self_awb_changegain(color, delta, 0, src, ptADC_info);                   // Decrease Gain; Increse Contrast

			}
		}
		else if((color == SELECT_BLUE) && (b_ready == FALSE))
		{
		    if(*b_voltage_diffresult > difftarget_b)
		    {
				delta  = *b_voltage_diffresult - difftarget_b;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_BLUE Increase Gain   temp=%d\n", __func__, __LINE__, delta);
				drvif_self_awb_changegain(color, delta, 1, src, ptADC_info);                 // Increse Gain; Decrease Contrast

			}else if(*b_voltage_diffresult < difftarget_b){
				delta  = difftarget_b - *b_voltage_diffresult;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]SELECT_BLUE Decrease Gain  temp=%d\n", __func__, __LINE__, delta);
				// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
				drvif_self_awb_changegain(color, delta, 0, src, ptADC_info);                   // Decrease Gain; Increse Contrast

			}
		}
		color = color>>1;
	}
	return ERROR_SUCCEED;
}


UINT8 drvif_self_awb_gain_adjust_proc(UINT8 ucColor, UINT16 *voltage_diffresult, UINT16 ucMax_Target, int src, ADCGainOffset * ptADC_info)
{
	//printk(KERN_INFO "\ndrvif_SelfAWB_tunedevicegain!");
	UINT16 temp;
    UINT16 temp_high;
    UINT16 temp_low;
    adc_adc_vbias_RBUS adc_adc_vbias_reg;

    adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	// Change voltage
	adc_adc_vbias_reg.adc_vbias2_2_0 = 4; // 0.85V

    IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(drvif_SelfAWB_measurecolor(ucColor, _COLOR_MAX, voltage_diffresult) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n[SelfAWB] Error  Gain ABORT 0 %c",'!');
		return ERROR_ABORT;
	}
    temp_high = *voltage_diffresult;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "HIGH=%3d ",temp_high);


//Change Low
    adc_adc_vbias_reg.adc_vbias2_2_0 = 2;//0.55V
    IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	if(drvif_SelfAWB_measurecolor(ucColor, _COLOR_MAX, voltage_diffresult) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n[SelfAWB] Error Gain ABORT 1 %c",'!');
		return ERROR_ABORT;
	}
    temp_low = *voltage_diffresult;
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "LOW=%3d Diff=%3d\n",temp_low,temp_high-temp_low);


    *voltage_diffresult = temp_high - temp_low;

    //RTD_Log(LOGGER_INFO, "@@@ Rita - temp_high - temp_low @@@ *pMargin =%d\n", *pMargin);

    rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "diffresult=%d, ucMax_Target=%d\n", *voltage_diffresult, ucMax_Target);

    if(*voltage_diffresult > ucMax_Target)
    {
		temp  = *voltage_diffresult - ucMax_Target;
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Increase Gain   temp=%d\n", temp);

		drvif_self_awb_changegain(ucColor, temp, 1, src, ptADC_info);                  // Increse Gain; Decrease Contrast

	}else if(*voltage_diffresult < ucMax_Target){
		temp  = ucMax_Target - *voltage_diffresult;
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Decrease Gain  temp=%d\n", temp);
		// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
		drvif_self_awb_changegain(ucColor, temp, 0, src, ptADC_info);                 // Decrease Gain; Increse Contrast

	}
	return ERROR_SUCCEED;
}

#if 0
static unsigned long long auto_read_phase_sodvalue(void)
{
	return (unsigned long long)IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg);
}
#endif
unsigned char auto_waitivs(unsigned char display)
{
	unsigned char flag, ucTimeout = 5;

	// CSW+ 0961219 Add timeout function
	do {
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		flag =  Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? IoReg_BusyCheckRegBit(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT26,0x1FFFF) : IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
#else
		flag =  IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
		//flag =  /*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? IoReg_BusyCheckRegBit(SUB_VGIP_VGIP_CHN2_STATUS_reg, _BIT26,0x1FFFF) : */IoReg_BusyCheckRegBit(VGIP_VGIP_CHN1_STATUS_reg, _BIT26,0x1FFFF);
#endif
		ucTimeout--;
	}while((!flag) && (ucTimeout));

	if (ucTimeout == 0)
		return FALSE;
	return TRUE;
}

#ifdef USE_AUTO_PHASE_FLAG
static unsigned char auto_checkPhaseEnd(unsigned char display)
{
	unsigned int wait_timeoutcnt = 0x01FFFF;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;

		do{
			auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);

			if(auto_phase_ctrl0_reg.autophase_flg)
				return TRUE;
		}while(--wait_timeoutcnt);

		return FALSE;


}

static void clear_auto_phase_flag()
{
	adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_flg = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg,auto_phase_ctrl0_reg.regValue);
}

#endif //#ifdef USE_AUTO_PHASE_FLAG

unsigned long long autoclock_searchphase(unsigned char display, unsigned char Sel_Mode, unsigned char Sel_Color, unsigned char Sel_Step, unsigned char Sel_Step_Num, unsigned char Sel_Step_Start, unsigned char filter_sel)
{//This API is for Auto clock to run phase check
	return 0;
#if 0//Fix error by Will
	unsigned long long maxsum = 0, maxsum_tmp;
	unsigned char  count, best, Result;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;
	adc_smartfit_adc_auto_adj_RBUS auto_adj_reg;
	auto_soy_soych0_a2_RBUS soych0_a2_reg;

	//Reset auto phase setting
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);//Reset autophase. Will add
    auto_phase_ctrl0_reg.autophase_en = 0;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);//Reset autophase. Will add
	auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);//Reset autophase. Will add
	auto_adj_reg.now_af = 0;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, auto_adj_reg.regValue);//Reset autophase. Will add

	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = 0;//COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);

	adc_smartfit_adc_auto_field_RBUS auto_field_reg;
	auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	auto_field_reg.filter_sel = filter_sel;
	printk(KERN_INFO "\n@@filter_sel_2=%x", filter_sel);


	if(_ENABLE ==Scaler_Get_YPbPr_AutoPhase_Flag())
	{
		auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
		if(GET_AUTO_CONFIG_DOING())
			auto_field_reg.rgb_in_one_en = 1;
		else
			auto_field_reg.rgb_in_one_en = 0;

		printk(KERN_INFO "auto_field_reg.rgb_in_one_en=%x\n", auto_field_reg.rgb_in_one_en);
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, auto_field_reg.regValue);
	}
	else// if(_DISABLE ==Scaler_Get_YPbPr_AutoPhase_Flag())
	{
		auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
		auto_field_reg.rgb_in_one_en = 1;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, auto_field_reg.regValue);
		printk(KERN_INFO "auto_field_reg.rgb_in_one_en=%x\n", auto_field_reg.rgb_in_one_en);
	}


	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, 0x00);  //reset Auto start

	auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	auto_r_g_b_margin_reg.color_sel = Sel_Color;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, auto_r_g_b_margin_reg.regValue);

	auto_phase_ctrl0_reg.regValue = 0;

	auto_phase_ctrl0_reg.autophase_en = Hardware_Auto_Phase;
	auto_phase_ctrl0_reg.autophase_step_2 = 0;
	auto_phase_ctrl0_reg.autophase_step_1_0 = Sel_Step;
	auto_phase_ctrl0_reg.init_phase = Sel_Step_Start;
	auto_phase_ctrl0_reg.autosod_step_num = ( Sel_Step_Num - 1);
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
	if(Sel_Step != 0)
	{
		best = 2;
		for(count = 0;count <Sel_Step-1 ;count++)
		{
			best = best * 2;
		}
	}
	else
		best = 1;

	Sel_Step = best;
	maxsum      = 0;
    best        = 0;
	printk(KERN_INFO "\n@@Auto clock to set Hardware_Auto_Phase");


	//reset Auto start
	auto_adj_reg.regValue = 0;
	if(Sel_Mode)
	{
		auto_adj_reg.m_vgen_en = 0;
		auto_adj_reg.diff_pixel_sel = 1;
		auto_adj_reg.force_flip = 1;
		auto_adj_reg.sum_max = 1;
		auto_adj_reg.pulse_det_en = 1;

		//patch avoid ypbpr hang
		if(Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VGA)
			auto_adj_reg.autophase_sel_tri = 1;
		else
			auto_adj_reg.autophase_sel_tri = 0;
		auto_adj_reg.diff_en = 1;
		auto_adj_reg.now_af = 1;
	}
	else
	{
		auto_adj_reg.m_vgen_en = 0;
		auto_adj_reg.diff_pixel_sel = 1;
		auto_adj_reg.force_flip = 1;
		auto_adj_reg.sum_max = 1;
		auto_adj_reg.pulse_det_en = 0;
		auto_adj_reg.autophase_sel_tri = 1;
		auto_adj_reg.diff_en = 1;
		auto_adj_reg.now_af = 1;
	}
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, auto_adj_reg.regValue);

	if (!auto_waitivs(display))
		goto auto_phasesearch_fail;


	for(count = 0;count <Sel_Step_Num ;count++)
	{

		if (!auto_waitivs(display))
			goto auto_phasesearch_fail;
		maxsum_tmp = auto_read_phase_sodvalue();//Read SOD value

#ifdef ENABLE_PRINT
		printk(KERN_INFO "\n phase[%d]:maxsum = %llx,  SOD=%llx\n", Sel_Step_Start + Sel_Step * count,maxsum, maxsum_tmp);
#endif //#ifdef ENABLE_PRINT
		if(maxsum<maxsum_tmp)
		{
			maxsum = maxsum_tmp;
		}
	}

	printk(KERN_INFO "\r\n#####Max SOD=%llx #####\r\n", maxsum);


//		if (!auto_waitivs(display))
//				goto auto_phasesearch_fail;
	Result = auto_waitfinish(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
	if (ERROR_SUCCEED != Result)
		goto auto_phasesearch_fail;



	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_en = 0;
	auto_phase_ctrl0_reg.autophase_step_2 = 0;
	auto_phase_ctrl0_reg.res1 = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);

// [Code Sync][LewisLee][0990212][1]
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_en = 0; //Hardware / Software Auto Phase Switch
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
// [Code Sync][LewisLee][0990212][1][End]

	//egger 20120822 modify cmp level updating threshold to get right phase and cmp level mapping
	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);

	return maxsum;

	// [Code Sync][LewisLee][0990212][1]
	auto_phasesearch_fail:


	//egger 20120822 modify cmp level updating threshold to get right phase and cmp level mapping
	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);

	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_en = 0; //Hardware / Software Auto Phase Switch
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
	return 0xffffffff ;
// [Code Sync][LewisLee][0990212][1][End]
#endif
}


unsigned long long auto_phasesearch(unsigned char HW_SW_sel, unsigned char display, unsigned char Sel_Mode, unsigned char Sel_Color, unsigned char Sel_Step, unsigned char Sel_Step_Num, unsigned char Sel_Step_Start, unsigned char *Phase_Result,unsigned char filter_sel)
{

	//unsigned long long maxsum = 0, maxsum_tmp;
	//unsigned char  count, best, Result;
	//adc_smartfit_adc_auto_r_g_b_margin_RBUS auto_r_g_b_margin_reg;
	//adc_smartfit_adc_auto_phase_ctrl0_RBUS auto_phase_ctrl0_reg;
	//adc_smartfit_adc_auto_adj_RBUS auto_adj_reg;
	//auto_soy_soych0_a2_RBUS soych0_a2_reg;
	return 0;
#if 0//Fix error by Will
	//Reset auto phase setting
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);//Reset autophase. Will add
    auto_phase_ctrl0_reg.autophase_en = 0;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);//Reset autophase. Will add
	auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);//Reset autophase. Will add
	auto_adj_reg.now_af = 0;//Reset autophase. Will add
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, auto_adj_reg.regValue);//Reset autophase. Will add

	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = 0;//COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);
#ifdef _AUTO_FAST_FLOW
	adc_smartfit_adc_auto_field_RBUS auto_field_reg;
	auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	auto_field_reg.filter_sel = filter_sel;
	printk(KERN_INFO "\n@@filter_sel_2=%x", filter_sel);


	if(_ENABLE ==Scaler_Get_YPbPr_AutoPhase_Flag())
	{
		auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
		if(GET_AUTO_CONFIG_DOING())
			auto_field_reg.rgb_in_one_en = 1;
		else
			auto_field_reg.rgb_in_one_en = 0;

		printk(KERN_INFO "auto_field_reg.rgb_in_one_en=%x\n", auto_field_reg.rgb_in_one_en);
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, auto_field_reg.regValue);
	}
	else// if(_DISABLE ==Scaler_Get_YPbPr_AutoPhase_Flag())
	{
		auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
		auto_field_reg.rgb_in_one_en = 1;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, auto_field_reg.regValue);
		printk(KERN_INFO "auto_field_reg.rgb_in_one_en=%x\n", auto_field_reg.rgb_in_one_en);
	}
#endif //#ifdef _AUTO_FAST_FLOW

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, 0x00);  //reset Auto start

	auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	auto_r_g_b_margin_reg.color_sel = Sel_Color;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, auto_r_g_b_margin_reg.regValue);

	auto_phase_ctrl0_reg.regValue = 0;
	if(HW_SW_sel==Hardware_Auto_Phase)
	{
		auto_phase_ctrl0_reg.autophase_en = HW_SW_sel;
		auto_phase_ctrl0_reg.autophase_step_2 = 0;
		auto_phase_ctrl0_reg.autophase_step_1_0 = Sel_Step;
		auto_phase_ctrl0_reg.init_phase = Sel_Step_Start;
		auto_phase_ctrl0_reg.autosod_step_num = ( Sel_Step_Num - 1);
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
		if(Sel_Step != 0)
		{
			best = 2;
			for(count = 0;count <Sel_Step-1 ;count++)
			{
				best = best * 2;
			}
		}
		else
			best = 1;

		Sel_Step = best;
		maxsum      = 0;
	    best        = 0;
		printk(KERN_INFO "\n@@Hardware_Auto_Phase");
	}
	else if(HW_SW_sel==Software_Auto_Phase)
	{
		auto_phase_ctrl0_reg.autophase_en = HW_SW_sel;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
		printk(KERN_INFO "\n@@Software_Auto_Phase");
	}
	else
		goto auto_phasesearch_fail;

	//reset Auto start
	auto_adj_reg.regValue = 0;
	if(Sel_Mode)
	{
		auto_adj_reg.m_vgen_en = 0;
		auto_adj_reg.diff_pixel_sel = 1;
		auto_adj_reg.force_flip = 1;
		auto_adj_reg.sum_max = 1;
		auto_adj_reg.pulse_det_en = 1;

		//patch avoid ypbpr hang
		if(Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VGA)
			auto_adj_reg.autophase_sel_tri = 1;
		else
			auto_adj_reg.autophase_sel_tri = 0;
		auto_adj_reg.diff_en = 1;
		auto_adj_reg.now_af = 1;
	}
	else
	{
		auto_adj_reg.m_vgen_en = 0;
		auto_adj_reg.diff_pixel_sel = 1;
		auto_adj_reg.force_flip = 1;
		auto_adj_reg.sum_max = 1;
		auto_adj_reg.pulse_det_en = 0;
		auto_adj_reg.autophase_sel_tri = 1;
		auto_adj_reg.diff_en = 1;
		auto_adj_reg.now_af = 1;
	}
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, auto_adj_reg.regValue);

	if (!auto_waitivs(display))
		goto auto_phasesearch_fail;


	if(HW_SW_sel==Software_Auto_Phase)
	{
		for(count = 0;count <Sel_Step_Num ;count++)
		{
#ifdef USE_AUTO_PHASE_FLAG
			if (!auto_checkPhaseEnd(display))
				goto auto_phasesearch_fail;
#else //#ifdef USE_AUTO_PHASE_FLAG
			if (!auto_waitivs(display))
				goto auto_phasesearch_fail;
#endif //#ifdef USE_AUTO_PHASE_FLAG

			maxsum_tmp = auto_read_phase_sodvalue();
			//printk(KERN_INFO "maxsum_tmp=%x\n", maxsum_tmp);
#ifdef USE_AUTO_PHASE_FLAG
			clear_auto_phase_flag();
#endif

#ifdef ENABLE_PRINT
			printk(KERN_INFO "\n phase[%d]:maxsum = %llx,  SOD=%llx\n", Sel_Step_Start + Sel_Step * count,maxsum, maxsum_tmp);
#endif //#ifdef ENABLE_PRINT
			if(maxsum<maxsum_tmp)
			{
				maxsum = maxsum_tmp;
				best = Sel_Step_Start + Sel_Step * count;
#ifdef ENABLE_PRINT
				printk(KERN_INFO "\n^^^^^^^^^best=%x", best);
#endif //#ifdef ENABLE_PRINT
			}
		}

//		if (!auto_waitivs(display))
//				goto auto_phasesearch_fail;
		Result = auto_waitfinish(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
		if (ERROR_SUCCEED != Result)
					goto auto_phasesearch_fail;

	}
	else if(HW_SW_sel==Hardware_Auto_Phase)
	{
		Result = auto_waitfinish(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL));
		if(ERROR_SUCCEED != Result)
		{
			goto auto_phasesearch_fail;
		}

		auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
		best = auto_phase_ctrl0_reg.autophase_max_step;
		maxsum = 1;//HW flow don't has the value. We set 1 for return success
		printk(KERN_INFO "autophase_max_step=%d\n", auto_phase_ctrl0_reg.autophase_max_step);

	}

	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);

	printk(KERN_INFO "autophase_max_step=%d\n", auto_phase_ctrl0_reg.autophase_max_step);

	auto_phase_ctrl0_reg.autophase_en = 0;
	auto_phase_ctrl0_reg.autophase_step_2 = 0;
	auto_phase_ctrl0_reg.res1 = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);

// [Code Sync][LewisLee][0990212][1]
	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_en = 0; //Hardware / Software Auto Phase Switch
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
// [Code Sync][LewisLee][0990212][1][End]

	//egger 20120822 modify cmp level updating threshold to get right phase and cmp level mapping
	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);

	*Phase_Result = best;
	return maxsum;

	// [Code Sync][LewisLee][0990212][1]
	auto_phasesearch_fail:


	//egger 20120822 modify cmp level updating threshold to get right phase and cmp level mapping
	soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_SEEK_MIN_DIFF;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, soych0_a2_reg.regValue);

	auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	auto_phase_ctrl0_reg.autophase_en = 0; //Hardware / Software Auto Phase Switch
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, auto_phase_ctrl0_reg.regValue);
	return 0xffffffff ;
// [Code Sync][LewisLee][0990212][1][End]
#endif
}


unsigned int get_sod_software_auto_phase(unsigned short phase)
{
	int timeout = 10;
	unsigned int SOD_VALUE = 0;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
//	auto_soy_soych0_a2_RBUS autosoy_soych0_a2_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;

	// ADC_PLLPHSE_CTRL rzhen@2016-06-29
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;

	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index = phase & 0x0000003f;
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	if(GET_AUTO_CONFIG_DOING())
		smartfit_auto_field_reg.rgb_in_one_en = 1;
	else
		smartfit_auto_field_reg.rgb_in_one_en = 0;
	smartfit_auto_field_reg.square_en = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, smartfit_auto_field_reg.regValue);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "auto_field_reg.rgb_in_one_en=%x\n", smartfit_auto_field_reg.rgb_in_one_en);

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, 0x00);  //reset Auto start

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_r_g_b_margin_reg.color_sel = _COLORS_GREEN;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);

	smartfit_auto_phase_ctrl0_reg.regValue = 0;
	smartfit_auto_phase_ctrl0_reg.autophase_en = 0;
	smartfit_auto_phase_ctrl0_reg.new_ap_en = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "@@Software_Auto_Phase");


	//reset Auto start
	smartfit_auto_adj_reg.regValue = 0;
	smartfit_auto_adj_reg.m_vgen_en = 0;
	smartfit_auto_adj_reg.diff_pixel_sel = 1;
	smartfit_auto_adj_reg.force_flip_ = 1;
	smartfit_auto_adj_reg.sum_max = 1;
	smartfit_auto_adj_reg.pulse_det_en = 1;
	smartfit_auto_adj_reg.autophase_sel_tri = 0;
	smartfit_auto_adj_reg.diff_en = 1;
	smartfit_auto_adj_reg.now_af = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);


	smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	while(smartfit_auto_adj_reg.now_af && timeout)
	{
		msleep(1);
		timeout --;
		smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	}

	if(timeout == 0)
	{
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "###get_sod_software_auto_phase timeout error####\r\n");

	}
	else
	{
		SOD_VALUE = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg);
	}
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "####func:%s timeout:%d SOD:0x%x####\r\n",__FUNCTION__,timeout, SOD_VALUE);
	Reset_YPP_Auto_Phase_SmartFit_Setting();

	return SOD_VALUE;

}


unsigned char auto_phasesearch_start(unsigned char HW_SW_sel, unsigned char display, unsigned char Sel_Mode, unsigned char Sel_Color, unsigned char Sel_Step, unsigned char Sel_Step_Num, unsigned char Sel_Step_Start, unsigned char *Phase_Result,unsigned char filter_sel)
{
	unsigned int timing;
	unsigned long long maxsum = 0;
	unsigned char  count, best;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	auto_soy_soych0_a2_RBUS autosoy_soych0_a2_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	auto_soy_soych0_a3_RBUS auto_soy_soych0_a3_reg;
	auto_soy_soych0_a4_RBUS autosoy_soych0_a4_reg;
	unsigned int tmp_lvl_value = 0x10;
	unsigned char macrovision_480i_enable = 0;
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();

	timing = p_dispinfo->ucMode_Curr;

	switch(timing){
		case _MODE_720P60:
		case _MODE_720P50:
		case _MODE_1080I30:
		case _MODE_1080I25:
		case _MODE_1080P30:
		case _MODE_1080P29:
		case _MODE_1080P25:
		case _MODE_1080P24:
		case _MODE_1080P23:
		case _MODE_1080P50:
		case _MODE_1080P60:
			tmp_lvl_value = 0x10;
			break;


		case _MODE_480I:
			if(check_macrovision(timing) == TRUE){
				tmp_lvl_value = 0x10;//480i and macrovision case. 20160218.
				macrovision_480i_enable = 1;
				//printk(KERN_EMERG"480i and macrovision case!!\n");
			}else{
				tmp_lvl_value = 0x16;
			}
			break;

		case _MODE_480P:
		case _MODE_576P:
		case _MODE_576I:
		default:
			tmp_lvl_value = 0x16;
			break;
	}

	autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);

	if(macrovision_480i_enable == 0){
		autosoy_soych0_a0_reg.reg_auto_mode = 1;
	}else{
		autosoy_soych0_a0_reg.reg_auto_mode = 0;
	}

	autosoy_soych0_a0_reg.reg_auto_ini_dc = tmp_lvl_value;
	IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);

	auto_soy_soych0_a3_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A3_reg);
	auto_soy_soych0_a3_reg.reg_manu_comp = tmp_lvl_value;
	IoReg_Write32(AUTO_SOY_SOYCH0_A3_reg, auto_soy_soych0_a3_reg.regValue);

#ifdef _AUTO_FAST_FLOW

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	smartfit_auto_field_reg.auto_balance_rgb = 2;

	smartfit_auto_field_reg.square_en= 1;

	if(GET_AUTO_CONFIG_DOING())
		smartfit_auto_field_reg.rgb_in_one_en = 1;
	else
		smartfit_auto_field_reg.rgb_in_one_en = 0;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "auto_field_reg.rgb_in_one_en=%x\n", smartfit_auto_field_reg.rgb_in_one_en);
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg, smartfit_auto_field_reg.regValue);

#endif //#ifdef _AUTO_FAST_FLOW

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, 0x00);  //reset Auto start

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_r_g_b_margin_reg.color_sel = Sel_Color;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);

	smartfit_auto_phase_ctrl0_reg.regValue = 0;
	if(HW_SW_sel == Hardware_Auto_Phase){
		smartfit_auto_phase_ctrl0_reg.autophase_en = HW_SW_sel;	 //Hardware / Software Auto Phase Switch
		smartfit_auto_phase_ctrl0_reg.new_ap_en = 0; //New ap for hardware auto phse mode
		smartfit_auto_phase_ctrl0_reg.autophase_max_step= 0;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);
	#if 1	//remove for mac5p new auto phase algorithm, rzhen@2017-01-06
		smartfit_auto_phase_ctrl0_reg.autophase_step= Sel_Step;
		smartfit_auto_phase_ctrl0_reg.init_phase = Sel_Step_Start;
		smartfit_auto_phase_ctrl0_reg.autosod_step_num = ( Sel_Step_Num - 1);
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);

		if(Sel_Step != 0)
		{
			best = 2;
			for(count = 0;count <Sel_Step-1 ;count++)
			{
				best = best * 2;
			}
		}
		else
			best = 1;

		Sel_Step = best;
		maxsum   = 0;
		best     = 0;
	#endif
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "@@Hardware_Auto_Phase");

	}else if(HW_SW_sel == Software_Auto_Phase){
		smartfit_auto_phase_ctrl0_reg.autophase_en = HW_SW_sel;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "@@Software_Auto_Phase");
	}
	else
		goto auto_phasesearch_fail;

	//reset Auto start
	smartfit_auto_adj_reg.regValue = 0;
	if(Sel_Mode)
	{
		smartfit_auto_adj_reg.m_vgen_en = 0;
		smartfit_auto_adj_reg.diff_pixel_sel = 1;
		smartfit_auto_adj_reg.force_flip_ = 1;
		smartfit_auto_adj_reg.sum_max = 1;
		smartfit_auto_adj_reg.pulse_det_en = 1;

		//patch avoid ypbpr hang
		if(Scaler_InputSrcGetType(SLR_MAIN_DISPLAY) == _SRC_VGA)
			smartfit_auto_adj_reg.autophase_sel_tri = 1;
		else
			smartfit_auto_adj_reg.autophase_sel_tri = 0;
		smartfit_auto_adj_reg.diff_en = 1;
		smartfit_auto_adj_reg.now_af = 1;
	}
	else
	{
		smartfit_auto_adj_reg.m_vgen_en = 0;
		smartfit_auto_adj_reg.diff_pixel_sel = 1;
		smartfit_auto_adj_reg.force_flip_ = 1;
		smartfit_auto_adj_reg.sum_max = 1;
		smartfit_auto_adj_reg.pulse_det_en = 0;
		smartfit_auto_adj_reg.autophase_sel_tri = 1;
		smartfit_auto_adj_reg.diff_en = 1;
		smartfit_auto_adj_reg.now_af = 1;
	}
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);


	if (!auto_waitivs(display))
		goto auto_phasesearch_fail;


	return ERROR_SUCCEED;

	// [Code Sync][LewisLee][0990212][1]
	auto_phasesearch_fail:


	//egger 20120822 modify cmp level updating threshold to get right phase and cmp level mapping
	autosoy_soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);
	autosoy_soych0_a2_reg.reg_min_diff = 0;
	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, autosoy_soych0_a2_reg.regValue);

	smartfit_auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	smartfit_auto_phase_ctrl0_reg.autophase_en = 0; //Hardware / Software Auto Phase Switch
	smartfit_auto_phase_ctrl0_reg.new_ap_en = 0; //New ap for hardware auto phse mode
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_adj_reg.regValue);

	return ERROR_ABORT;
// [Code Sync][LewisLee][0990212][1][End]


}

static unsigned char ypp_auto_phase_waitfinish(unsigned char display)
{
	extern unsigned judge_scaler_break_case(unsigned char display);
	unsigned short Wait_Time_Cnt;
	vgip_vgip_chn1_status_RBUS vgip_vgip_chn1_status_reg;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	sub_vgip_vgip_chn2_status_RBUS vgip_chn2_status_reg;
#endif
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;

	// Wait until auto tracking finishes or timeout
	Wait_Time_Cnt = 75;
	do {
		if(get_ADC_Input_Source() == _SRC_VGA)
		{
			if(vga_clock_check_onlinemeasure_status(display) == FALSE){
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "########ypp_auto_phase_waitfinish VGA ERROR_ABORT##########\r\n");
				return ERROR_ABORT;
			}
		}
		else
		{
			if(judge_scaler_break_case(display)){
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "########ypp_auto_phase_waitfinish ERROR_ABORT##########\r\n");
				return ERROR_ABORT;
			}
		}
		msleep(1);//dont use delay here or it will block system a while. Q-3569
		smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
		Wait_Time_Cnt --;
	} while ((smartfit_auto_adj_reg.now_af) && (Wait_Time_Cnt));

    if(Wait_Time_Cnt == 0)
    {
    	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####ypp_auto_phase_waitfinish timeout#####\r\n");
    }

	if(SLR_MAIN_DISPLAY == display)
	{
		vgip_vgip_chn1_status_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg);
		vgip_vgip_chn1_status_reg.ch1_vs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_hs_err = 1;
		vgip_vgip_chn1_status_reg.ch1_field_err = 1;
		vgip_vgip_chn1_status_reg.ch1_vact_start = 0;
		vgip_vgip_chn1_status_reg.ch1_vact_end = 0;
		IoReg_Write32(VGIP_VGIP_CHN1_STATUS_reg, vgip_vgip_chn1_status_reg.regValue);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else// if(SLR_SUB_DISPLAY == display)
	{
		vgip_chn2_status_reg.regValue = IoReg_Read32(SUB_VGIP_VGIP_CHN2_STATUS_reg);
		vgip_chn2_status_reg.ch2_vs_err = 1;
		vgip_chn2_status_reg.ch2_hs_err = 1;
		vgip_chn2_status_reg.ch2_field_err = 1;
		vgip_chn2_status_reg.ch2_vact_start = 0;
		vgip_chn2_status_reg.ch2_vact_end = 0;
		IoReg_Write32(SUB_VGIP_VGIP_CHN2_STATUS_reg, vgip_chn2_status_reg.regValue);
	}
#endif

	return ((0 == Wait_Time_Cnt) ? ERROR_TIMEOUT : ERROR_SUCCEED);
}



unsigned char auto_phasesearch_WaitFinish(unsigned char *a_pucPhaseResult)
{
	//unsigned long long maxsum = 0, maxsum_tmp;
	unsigned char  Result;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;
	//unsigned char  ucBestPhase = 0;

	// Wait auto phase finish
	Result = ypp_auto_phase_waitfinish(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));

	// Get best phase, 0xb8020424[14:8]
	smartfit_auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	*a_pucPhaseResult = smartfit_auto_phase_ctrl0_reg.autophase_max_step;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "autophase_max_step=%d\n", smartfit_auto_phase_ctrl0_reg.autophase_max_step);

	// Disable auto phase
	//smartfit_auto_phase_ctrl0_reg.autophase_en = 0;
	//smartfit_auto_phase_ctrl0_reg.para_ap_en = 0;
	//IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);

	Reset_YPP_Auto_Phase_SmartFit_Setting();

	if (ERROR_SUCCEED != Result)
		return ERROR_ABORT;

	return ERROR_SUCCEED;

}



//for don't adjust phase, do not execute jump phase action
void drv_adc_clock_adjust(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display, unsigned char fast_lock_enable)
{
	unsigned short usTempClock;
	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();

	//usTempClock = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_ADC_CLOCK) +(GET_CLOCK() - 0x80);
	//usTempClock = p_dispinfo->INPUT_ADC_CLOCK + stScreenModeCurrInfo->Clock - 50;
	//updated the ADC IH_Total or the on-line measure will error
	//Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_H_LEN,  usTempClock);
	usTempClock = p_dispinfo->INPUT_ADC_CLOCK + (unsigned short)stScreenModeCurrInfo->ClockShift_After_auto - 128;
	//drvif_clock_set_aclk(p_dispinfo, _SRC_VGA,	p_dispinfo->INPUT_ADC_CLOCK, FALSE);
	drvif_clock_set_aclk(p_dispinfo, _SRC_VGA, usTempClock, FALSE);
}

//------------------------------------------------------------------//
//  						base on 640x480@60Hz   						//
//------------------------------------------------------------------//
unsigned char drv_auto_few_difference_pattern(unsigned char display, unsigned int difference)
{
	return TRUE;
#if 0//Fix error by Will
	unsigned char factor;

	if(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN)<480)
		factor = 1;
	else
		factor = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN)/480 + ((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN)%480)?1:0);

#ifdef ENABLE_PRINT
	printk(KERN_INFO "\ndifference=%d", difference);
	printk(KERN_INFO "\nfactor=%d\n", factor);
#endif //#ifdef ENABLE_PRINT

	if(difference<(0x00170000*(unsigned int)factor))
		return FALSE;
	else
		return TRUE;
#endif
}

unsigned char drv_auto_SOD_filter_sel(unsigned char display)
{
	return Low_Pass_Filter_0;
#if 0//Fix error by Will
	unsigned short IHFreq= Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_FREQ);
	unsigned short IHTotal = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_H_LEN);
	unsigned int pixelclock;
	pixelclock  = (((unsigned int)IHFreq * (unsigned int)IHTotal) * 2 / (1000 * 10));
	pixelclock  = (pixelclock >> 1) + (pixelclock & 0x01);
	if(pixelclock>=60)
		return Low_Pass_Filter_3;
	else
		return Low_Pass_Filter_0;
#endif

}

void drv_auto_set_difference_threshold(unsigned char difference_threshold)
{
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;

	smartfit_auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_r_g_b_margin_reg.diff_th = difference_threshold;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, smartfit_auto_r_g_b_margin_reg.regValue);
}

void drv_auto_set_phase(unsigned char phase)
{
	// ADC_PLLPHSE_CTRL rzhen@2016-06-29
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;

	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = (phase>>6) & 0x01;//set the phase
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index = phase & 0x0000003f;
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);
}

unsigned char drv_auto_get_phase_flag(void)
{
	// ADC_PLLPHSE_CTRL rzhen@2016-06-29
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;

	adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
	return adc_smartfit_adc_pllphase_ctrl_reg.pll2d2;
}

// [Code Sync][CSW][0980806][1] CSW+ 0980806
#define YPBPR_AUTO_PHASE_DIFF_TH		0x53//Brandon 20151227
#define YPBPR_AUTO_PHASE_THRESHOLD	0x030592fa

unsigned char drvif_ypbpr_auto_phasedo_start(unsigned char display)
{
	unsigned char  Result,phase_tmp;
	//unsigned int maxsum;//, temp0, temp1, temp2,temp_sum;
	unsigned char phase_flag;//64 or 128
//	unsigned short h_start,h_end;
//	unsigned short v_start,v_end;
	unsigned int timing;
#ifdef ADC_JUMP_PHASE_METHOD2
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;
#else //#ifdef ADC_JUMP_PHASE_METHOD2
	adc_adc_clock_RBUS adc_adc_clock_reg;
#endif //#ifdef ADC_JUMP_PHASE_METHOD2
	StructDisplayInfo *p_dispinfo = Get_ADC_Dispinfo();

	//rtd_printk(KERN_INFO, TAG_NAME_ADC, "****drvif_ypbpr_auto_phasedo_start****\n\n");

#if 0//This is using smart fit to measure start
	Result = drvif_auto_measurepositionh(display, 0x80, &h_start, &h_end, _COLORS_GREEN);

	if(ERROR_SUCCEED != Result)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[ypbpr auto phase start]YPbPr AutoPhase E1\n");
		return Result;
	}

	Result = drvif_auto_measurepositionv(display, 0x80, 0x80, 0x80, &v_start, &v_end, _COLORS_GREEN);

	if(ERROR_SUCCEED != Result)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[ypbpr auto phase start]YPbPr AutoPhase E2\n");
		return Result;
	}

	if((h_start == 0) || (h_end == 0))
	{
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[ypbpr auto phase start]YPbPr AutoPhase E3\n");
		return ERROR_ABORT;
	}

	msleep(20);
#else
	drvif_ypp_auto_phase_pre_setup(display, 0x80, 0x80, 0x80, _COLORS_GREEN);//Directly use timing info for auto phase setting
#endif

#if 1
	adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
	adc_adc_clkgen_rgb_capture_reg.hs_catch_edge = 0; //jump phase
	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_adc_clkgen_rgb_capture_reg.regValue);
#else
#ifdef ADC_JUMP_PHASE_METHOD2
	adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
	adc_adc_clkgen_rgb_capture_reg.adc_clk_inv_en = 0; //jump phase
	IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_adc_clkgen_rgb_capture_reg.regValue);
#else //#ifdef ADC_JUMP_PHASE_METHOD2
	adc_adc_clock_reg.regValue = IoReg_Read32(ADC_ADC_CLOCK_reg);
	adc_adc_clock_reg.adc_clock_6 = 0; //jump phase
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);
#endif //#ifdef ADC_JUMP_PHASE_METHOD2
#endif
	phase_flag = drv_auto_get_phase_flag();//64 or 128
	//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ypbpr auto phase start]phase_flag = %x", phase_flag);
	drv_auto_set_phase(0);

	drv_auto_set_difference_threshold(YPBPR_AUTO_PHASE_DIFF_TH);

	#if 0	//mac5p new auto phase algorithm no need setting step,num,start, rzhen@2017-01-06
	Result	= auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_8, HWAUTOSTEPNUM(16), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
	#else	//remove for mac5p new auto phase algorithm, rzhen@2017-01-06
	//search phase by large range
	if(phase_flag)
	{
		timing = p_dispinfo->ucMode_Curr;
		if((timing == _MODE_1080I25) || (timing == _MODE_1080I30) || (timing == _MODE_480I)) {
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_4, HWAUTOSTEPNUM(20), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
		} else if((timing == _MODE_720P50) || (timing == _MODE_720P60)) {//for KTASKWBS-5759
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_4, HWAUTOSTEPNUM(8), HWAUTOSTEPSTART(30), &phase_tmp,Low_Pass_Filter_0);
			rtd_printk(KERN_EMERG, TAG_NAME_ADC, "[ypbpr 720p 50/60 auto phase start]Result = %x", Result);
		} else if(p_dispinfo->IVFreq > 400) {
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_8, HWAUTOSTEPNUM(16), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
		} else {
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_8, HWAUTOSTEPNUM(9), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
		}
	}
	else
	{
		if(p_dispinfo->IVFreq > 400) {
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_4, HWAUTOSTEPNUM(13), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
		} else {
			Result  = auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_8, HWAUTOSTEPNUM(8), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
		}
	}

	//printk(KERN_INFO "\n[ypbpr auto phase]big range search phase result=%x\n", phase_tmp);
	#endif

	//if(ERROR_SUCCEED != Result)
	//	rtd_printk(KERN_INFO, TAG_NAME_ADC, "[ypbpr auto phase start]*******YPbPr AutoPhase auto_phasesearch_start  fail.\n");
	//else
	//	rtd_printk(KERN_INFO, TAG_NAME_ADC, "[ypbpr auto phase start]YPbPr AutoPhase auto_phasesearch_start  success.\n");

	return Result;

}


unsigned char drvif_ypbpr_auto_phasedo_WaitFinish(unsigned char display)
{
	unsigned char  Result, best = 0;
	//unsigned int maxsum;
	unsigned char phase_flag;//64 or 128
	//unsigned short h_start,h_end;
	//unsigned short v_start,v_end;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;

	phase_flag = drv_auto_get_phase_flag();//64 or 128

	Result = auto_phasesearch_WaitFinish(&best);

	if (ERROR_SUCCEED == Result)
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "auto_phasesearch_WaitFinish  success\n");
	else
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "****auto_phasesearch_WaitFinish  fail\n");


	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "2.phase_flag = %x", phase_flag);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "2.best phase = 0x%x=%d\n", best, best);

	if(phase_flag)
	{
		//best = (best >> 1);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "After tune Best phase1 = %x", best);
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ypbpr auto phase]Final Phase=0x%x=%d\n", best, best);
	smartfit_auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	smartfit_auto_phase_ctrl0_reg.autophase_en = 0;
	smartfit_auto_phase_ctrl0_reg.new_ap_en = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg, smartfit_auto_phase_ctrl0_reg.regValue);
	YPbPr_SetPhase(display, best, TRUE); //forster modified 071211

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ypbpr auto phase]YPBPR Adjust Phase SUCCEED=%d!!!!\n",best);

	return ERROR_SUCCEED;
}



void drvif_auto_setcolorgainoffset(unsigned char colorindex, unsigned short parameter)
{
	unsigned short result;
	adc_adc_gain0_RBUS adc_adc_gain0_reg;
	adc_adc_gain1_RBUS adc_adc_gain1_reg;
	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;


	if(colorindex == _R_GAIN_INDEX || colorindex == _G_GAIN_INDEX || colorindex == _B_GAIN_INDEX)//Gain 9bits
		result = parameter >= 0x1ff ? 0x1ff : parameter;
	else//Offset 10 bits
		result = parameter >= 0x3ff ? 0x3ff : parameter;


	switch(colorindex)
	{
		case _R_GAIN_INDEX:
			adc_adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
			adc_adc_gain0_reg.adc_gain_red = result;
			IoReg_Write32(ADC_ADC_GAIN0_reg, adc_adc_gain0_reg.regValue);
		break;

		case _G_GAIN_INDEX:
			adc_adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
			adc_adc_gain0_reg.adc_gain_grn = result;
			IoReg_Write32(ADC_ADC_GAIN0_reg, adc_adc_gain0_reg.regValue);
		break;

		case _B_GAIN_INDEX:
			adc_adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
			adc_adc_gain1_reg.adc_gain_blu = result;
			IoReg_Write32(ADC_ADC_GAIN1_reg, adc_adc_gain1_reg.regValue);
		break;

		case _VDC_GAIN_INDEX:
			adc_adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
			//adc_gain1_reg.adc_gain_vdc = result; spec change
			IoReg_Write32(ADC_ADC_GAIN1_reg, adc_adc_gain1_reg.regValue);
		break;

		case _R_OFFSET_INDEX:
			adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
		#ifdef ADC_UP_DOWN_CLAMP
			adc_offset0_reg.adc_off_red = 0;
		#else
			adc_offset0_reg.adc_off_red = result;
		#endif
			IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);
		break;

		case _G_OFFSET_INDEX:
			adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
		#ifdef ADC_UP_DOWN_CLAMP
			adc_offset0_reg.adc_off_grn = 0;
		#else
			adc_offset0_reg.adc_off_grn = result;
		#endif
			IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);
		break;

		case _B_OFFSET_INDEX:
			adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
		#ifdef ADC_UP_DOWN_CLAMP
			adc_offset1_reg.adc_off_blu = 0;
		#else
			adc_offset1_reg.adc_off_blu = result;
		#endif
			IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);
		break;

		case _VDC_OFFSET_INDEX:
			adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
			//adc_offset1_reg.adc_off_vdc = result;	spec change
			IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);
		break;
	}


}

void drvif_set_gain_from_table(int src)
{
	switch(src){
		case _SRC_YPBPR:
			auto_adcgainset(src, stYPbPrGainOffsetData);
			break;

		case _SRC_VGA:
			auto_adcgainset(src, stVGAGainOffset);
			break;

		default:
			break;
	}
}

void drvif_set_offset_from_table(int src)
{
	switch(src){
		case _SRC_YPBPR:
			auto_adcoffsetset(src, stYPbPrGainOffsetData);
			break;

		case _SRC_VGA:
			auto_adcoffsetset(src, stVGAGainOffset);
			break;

		default:
			break;
	}
}

 /**
 * @}
 */

void Scaler_PrintADCGainInRegister(void)
{
	adc_adc_gain0_RBUS adc_gain0_reg;
	adc_adc_gain1_RBUS adc_gain1_reg;
	adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
	adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ADC Gain   in register]: R=0x%x=%d  G=0x%x=%d  B=0x%x=%d\n",
		adc_gain0_reg.adc_gain_red,adc_gain0_reg.adc_gain_red,
		adc_gain0_reg.adc_gain_grn,adc_gain0_reg.adc_gain_grn,
		adc_gain1_reg.adc_gain_blu,adc_gain1_reg.adc_gain_blu);
	return;
}

void Scaler_PrintADCOffsetInRegister(void)
{
	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;
	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[ADC Offset in register]: R=0x%x=%d  G=0x%x=%d  B=0x%x=%d\n",
		adc_offset0_reg.adc_off_red,adc_offset0_reg.adc_off_red,
		adc_offset0_reg.adc_off_grn,adc_offset0_reg.adc_off_grn,
		adc_offset1_reg.adc_off_blu,adc_offset1_reg.adc_off_blu);
	return;
}

//########################     FIX BY WILL        #######################################//

void drvif_auto_get_activeregion(unsigned short *region)
{
#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_act_vsta_length_reg;
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_delay_reg;

	dma_vgip_act_hsta_width_reg.regValue	= IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	dma_vgip_act_vsta_length_reg.regValue 	= IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);

	dma_vgip_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);

	region[0] = dma_vgip_act_hsta_width_reg.dma_ih_act_sta;//Active_HStart
	region[0] += dma_vgip_delay_reg.dma_ihs_dly;
	region[1] = dma_vgip_act_hsta_width_reg.dma_ih_act_wid;//Active_HWidtht
	region[2] = dma_vgip_act_vsta_length_reg.dma_iv_act_sta;//Active_VStart
	region[2] += dma_vgip_delay_reg.dma_ivs_dly;
	region[3] = dma_vgip_act_vsta_length_reg.dma_iv_act_len;//Active_VLines
#else
	vgip_vgip_chn1_act_hsta_width_RBUS vgip_vgip_chn1_act_hsta_width_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_vgip_chn1_act_vsta_length_reg;
	vgip_vgip_chn1_delay_RBUS vgip_vgip_chn1_delay_reg;

	vgip_vgip_chn1_act_hsta_width_reg.regValue  = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	vgip_vgip_chn1_act_vsta_length_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);

	vgip_vgip_chn1_delay_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_DELAY_reg);

	region[0] = vgip_vgip_chn1_act_hsta_width_reg.ch1_ih_act_sta;//Active_HStart
	region[0] += vgip_vgip_chn1_delay_reg.ch1_ihs_dly;
	region[1] = vgip_vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid;//Active_HWidtht
	region[2] = vgip_vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta;//Active_VStart
	region[2] += vgip_vgip_chn1_delay_reg.ch1_ivs_dly;
	region[3] = vgip_vgip_chn1_act_vsta_length_reg.ch1_iv_act_len;//Active_VLines
#endif
}

void drvif_auto_get_smartfit_windows( unsigned short *Active_Region, unsigned short *Offset_Pos, unsigned short *Y_Gain_Pos, unsigned short *PbPr_Gain_Pos)
{

	unsigned short Active_HStart;
	unsigned short Active_HWidth;
	unsigned short Active_VStart;
	unsigned short Active_VWidth;

	Active_HStart = Active_Region[0];
	Active_HWidth= Active_Region[1];
	Active_VStart = Active_Region[2];
	Active_VWidth= Active_Region[3];

//VideoBook-Chapter#2_colorbar
		//offsetY(Black)
	Offset_Pos[0]	= (Active_HStart+Active_HWidth) - Active_HWidth/16;
	Offset_Pos[1]	= Offset_Pos[0] + Active_HWidth/64;

	//GainY(White)
	Y_Gain_Pos[0]	= Active_HStart + Active_HWidth/32;
	Y_Gain_Pos[1]	= Y_Gain_Pos[0] + Active_HWidth/64;

	//GainPbPr(Magenta)
	PbPr_Gain_Pos[0] = (Active_HStart+Active_HWidth) - 7*Active_HWidth/16;
	PbPr_Gain_Pos[1] = PbPr_Gain_Pos[0] + Active_HWidth/64;


	Offset_Pos[2]	= Active_VStart + Active_VWidth/20;
	Offset_Pos[3]	= Offset_Pos[2] + Active_VWidth/20;
	Y_Gain_Pos[2]  = Offset_Pos[2];
	Y_Gain_Pos[3]  = Offset_Pos[3];
	PbPr_Gain_Pos[2]  = Offset_Pos[2];
	PbPr_Gain_Pos[3]  = Offset_Pos[3];


}

void drvif_write_adc_gainvalue(unsigned short value, unsigned char RGB_ADC)
{
	adc_adc_gain0_RBUS adc_adc_gain0_reg;
	adc_adc_gain1_RBUS adc_adc_gain1_reg;
	adc_adc_gain0_reg.regValue= IoReg_Read32(ADC_ADC_GAIN0_reg);
	adc_adc_gain1_reg.regValue= IoReg_Read32(ADC_ADC_GAIN1_reg);

	switch(RGB_ADC)
	{
		case R_ADC_Dragon://R_ADC
			adc_adc_gain0_reg.adc_gain_red = value;
			IoReg_Write32(ADC_ADC_GAIN0_reg, adc_adc_gain0_reg.regValue);
		break;
		case G_ADC_Dragon://G_ADC
			adc_adc_gain0_reg.adc_gain_grn = value;
			IoReg_Write32(ADC_ADC_GAIN0_reg, adc_adc_gain0_reg.regValue);
		break;
		case B_ADC_Dragon://B_ADC
			adc_adc_gain1_reg.adc_gain_blu = value;
			IoReg_Write32(ADC_ADC_GAIN1_reg, adc_adc_gain1_reg.regValue);
		break;
	}
}

void drvif_write_adc_offsetvalue(unsigned short value, unsigned char RGB_ADC)
{
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;

	adc_adc_offset0_reg.regValue= IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_adc_offset1_reg.regValue= IoReg_Read32(ADC_ADC_OFFSET1_reg);

	switch(RGB_ADC)
	{
		case R_ADC_Dragon://R_ADC
			adc_adc_offset0_reg.adc_off_red = value;
			IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_adc_offset0_reg.regValue);
		break;
		case G_ADC_Dragon://G_ADC
			adc_adc_offset0_reg.adc_off_grn = value;
			IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_adc_offset0_reg.regValue);
		break;
		case B_ADC_Dragon://B_ADC
			adc_adc_offset1_reg.adc_off_blu = value;
			IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_adc_offset1_reg.regValue);
		break;
	}
}

void drvif_auto_write_smartfit( unsigned short Hstart, unsigned short Hend, unsigned short Vstart,unsigned short Vend, unsigned char Ch)
{
	//rtd_printk(KERN_INFO, TAG_NAME_ADC, "=========In Write_SmatFif=========\n");
	adc_smartfit_adc_auto_h_boundary_RBUS smartfit_auto_h_boundary_reg;
	adc_smartfit_adc_auto_v_boundary_RBUS smartfit_auto_v_boundary_reg;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;

	smartfit_auto_h_boundary_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg);
	smartfit_auto_v_boundary_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg);
	smartfit_auto_r_g_b_margin_reg.regValue=IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);

	//H & V boundary setting
		smartfit_auto_h_boundary_reg.hb_sta = Hstart;
		smartfit_auto_h_boundary_reg.hb_end= Hend;
		smartfit_auto_v_boundary_reg.vb_sta=Vstart;
		smartfit_auto_v_boundary_reg.vb_end=Vend;

		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_H_BOUNDARY_reg, smartfit_auto_h_boundary_reg.regValue);
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_V_BOUNDARY_reg, smartfit_auto_v_boundary_reg.regValue);

	//Color Source Select for Detection //20070713 SmartFit YUV definition's wrong on ver.FIB !! Notice whether spec. been changed?
		if(Ch==AutoColor_U)//U BLUE
			smartfit_auto_r_g_b_margin_reg.color_sel=0x01; //auto_r_g_b_margin_reg.color_sel=0x0;
		else if(Ch==AutoColor_Y)//Y GREEN
			smartfit_auto_r_g_b_margin_reg.color_sel=0x02;//auto_r_g_b_margin_reg.color_sel=0x1;
		else if(Ch==AutoColor_V)//V RED
			smartfit_auto_r_g_b_margin_reg.color_sel=0x0;//auto_r_g_b_margin_reg.color_sel=0x2;

		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg,smartfit_auto_r_g_b_margin_reg.regValue);

		//Max color measured, Accumulation Mode, Start Auto-Function Tracking Function
		smartfit_auto_adj_reg.m_vgen_en = 0;//For AWB
		smartfit_auto_adj_reg.diff_pixel_sel = 0;//For AWB
		smartfit_auto_adj_reg.force_flip_ = 1;
		smartfit_auto_adj_reg.sum_max = 1;
		smartfit_auto_adj_reg.now_af	 = 1;
		smartfit_auto_adj_reg.pulse_det_en = 0;//For AWB
		smartfit_auto_adj_reg.diff_en =0;
		IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, smartfit_auto_adj_reg.regValue);

}


unsigned short drvif_auto_smartfit_finddominant( unsigned short HStart, unsigned short HEnd, unsigned short VStart, unsigned short VEnd, unsigned char HistCh)
{
	adc_smartfit_adc_auto_adj_RBUS smartfit_auto_adj_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;
	adc_smartfit_adc_auto_result_phase_m_RBUS smartfit_auto_result_phase_m_reg;
	adc_smartfit_adc_auto_result_phase_l_RBUS smartfit_auto_result_phase_l_reg;
	adc_smartfit_adc_auto_r_g_b_margin_RBUS smartfit_auto_r_g_b_margin_reg;
	unsigned long long SUM;
	unsigned long long PxlNum;
	unsigned long long PEAK = 0;
	unsigned char cnt=0;

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	smartfit_auto_field_reg.auto_balance_rgb = 2; //only 1 channel use color_sel 0x1802_040c[9:8] to choose.
	smartfit_auto_field_reg.adj_source = 0;//from ADC smfit
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg,smartfit_auto_field_reg.regValue);

	smartfit_auto_r_g_b_margin_reg.regValue=IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);
	smartfit_auto_r_g_b_margin_reg.diff_th = 0;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg,smartfit_auto_r_g_b_margin_reg.regValue);

	drvif_auto_write_smartfit(HStart, HEnd, VStart, VEnd, HistCh);

	do{
		#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
		#endif

		smartfit_auto_adj_reg.regValue=IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);

		//rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]smartfit_auto_adj_reg.now_af=%d\n", __FUNCTION__, __LINE__, smartfit_auto_adj_reg.now_af);

		if(smartfit_auto_adj_reg.now_af==0)//if smart-fit done
		{
			smartfit_auto_result_phase_m_reg.regValue =  IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_M_reg);
			smartfit_auto_result_phase_l_reg.regValue =  IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg);
			SUM = ( ( (unsigned long long)(smartfit_auto_result_phase_m_reg.acc_41_32) ) <<32) + (unsigned long long)(smartfit_auto_result_phase_l_reg.acc31_0);//Need check
			PxlNum = (HEnd-HStart+1)*(VEnd-VStart+1);
			do_div(SUM, PxlNum);
			PEAK = SUM;
			#if 0
			printk(KERN_INFO "##%s(line: %d)##HStart=%d, HEnd=%d\n",__func__, __LINE__, HStart,HEnd);
			printk(KERN_INFO "##%s(line: %d)##VStart=%d, VEnd=%d\n",__func__, __LINE__, VStart,VEnd);
			printk(KERN_INFO "##%s(line: %d)##PEAK=%d\n",__func__, __LINE__, (unsigned short)PEAK);
			#endif

			break;
		};

		//printk(KERN_INFO "FindDominant_SmartFit_Dragon cnt = %d\n",cnt);
		msleep(11); // CSW+ 0961023 This delay should not be removed, or the mode
		cnt++;
		if (cnt>50) // CSW+ 0961023 force loop out to avoid infinite looping
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
			return 0;
		}
	}while(cnt<50);

	return((unsigned short)PEAK);

}


unsigned short drvif_adc_gainadjust(unsigned short StartH,unsigned short EndH, unsigned short StartV, unsigned short EndV, unsigned short Target, unsigned short ADC_Data, unsigned char RGB_ADC, unsigned char HistCh)
{

	//unsigned char DCC_status;
	unsigned short counter = 0;
	unsigned short max = 511;//Sirius gain range 0-511
	unsigned short min = 0;//1023; for AWB
	unsigned short PEAK_Level;
	unsigned short diff;
	unsigned short diff_temp = 0;
	unsigned char same_diff=0;

    if(RGB_ADC == G_ADC_Dragon)
    	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Y ADC_gain_adjust:  Beginning Gain=%d\n", ADC_Data);
	else if(RGB_ADC == B_ADC_Dragon)
    	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pb(U) ADC_gain_adjust: Beginning Gain=%d\n", ADC_Data);
	else if(RGB_ADC == R_ADC_Dragon)
    	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pr(V) ADC_gain_adjust: Beginning Gain=%d\n", ADC_Data);

	drvif_write_adc_gainvalue(ADC_Data, RGB_ADC);
	PEAK_Level = drvif_auto_smartfit_finddominant(StartH, EndH, StartV, EndV,HistCh);//This need to check

	do
	{
		#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
		#endif

		PEAK_Level = drvif_auto_smartfit_finddominant(StartH, EndH, StartV, EndV,HistCh);

		if((Target - PEAK_Level)<0)
			diff = PEAK_Level - Target;
		else
			diff = (Target - PEAK_Level);

		if(same_diff>4)
			break;

		//printk(KERN_INFO "#######counter:%d Target=%d,ADC_Data=%d,PEAK_Level=%d,diff=%d######\r\n",counter,Target,ADC_Data,PEAK_Level,diff);

		if(diff == 0)
		{
			break;
		}
		else if(diff != 0 && counter == 20)//for AWB
		{
			break;
		}
		else if (PEAK_Level < Target)
		{
			max = ADC_Data;
			ADC_Data = ( max + min ) / 2;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ADC_adjust:Decrease gain count:%d Tar=%d PEAK=%d NewGain=%d\n",counter, Target, PEAK_Level, ADC_Data);
			drvif_write_adc_gainvalue(ADC_Data, RGB_ADC);
		}
		else if (PEAK_Level >Target)
		{
			min = ADC_Data;
			ADC_Data = ( max + min) / 2;
		    rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "ADC_adjust:Increase gain count:%d Tar=%d PEAK=%d NewGain=%d\n",counter, Target, PEAK_Level, ADC_Data);
			drvif_write_adc_gainvalue(ADC_Data, RGB_ADC);
		}
		if(ABS(diff,diff_temp)<=4)
			same_diff++;
		else
			same_diff = 0;
		counter++;

		diff_temp=diff;
	}while(1);


	return( ADC_Data);
}

unsigned char drvif_auto_autocolor_gain_adjust_loop(ADCGainOffset *pt_info, unsigned short GainTarget, unsigned short *GainPos, unsigned short GainData, unsigned char RGB_idx, unsigned char Channel)
{
	unsigned short Gain_Check;
	unsigned char Check_idx = 0;
	unsigned char diff_gain = 0;
	unsigned char result = TRUE;
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "Adjust_Loop start\n");
	drvif_write_adc_gainvalue(GainData, RGB_idx);//Sirius gain range 0-511

	do{
		#ifdef CONFIG_WATCHDOG_ENABLE
		IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
		IoReg_Write32(TC_WR_TR_VADDR, 0);
		#endif

		//Gain adjustment Begin
		GainData  = drvif_adc_gainadjust(GainPos[0], GainPos[1], GainPos[2], GainPos[3],
			GainTarget, GainData, RGB_idx, Channel);

		Gain_Check   = drvif_auto_smartfit_finddominant(GainPos[0], GainPos[1], GainPos[2], GainPos[3],Channel);

#if 0 //for debugging
		printk(KERN_INFO "Adjust_Loop Check_idx=%d\n", Check_idx);
		printk(KERN_INFO "GainTarget=%d, OffsetTarget=%d\n", GainTarget, OffsetTarget);
		printk(KERN_INFO "Gain_Check  =%d, Offset_Check  =%d\n", Gain_Check, Offset_Check);
#endif
		Check_idx++;

		diff_gain = ABS(Gain_Check, GainTarget);

	}while( (diff_gain > 4) && (Check_idx < 6) );//16 is by the experience, modified to 5 to speed up


	if(GainData < 511 && GainData > 20)//for AWB //Success
	{

		switch(Channel)
		{
			case AutoColor_Y:
				pt_info->Gain_G = GainData;
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_Y success#####\r\n",__FUNCTION__);
			break;

			case AutoColor_U:
				pt_info->Gain_B = GainData;
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_U success#####\r\n",__FUNCTION__);
			break;

			case AutoColor_V:
				pt_info->Gain_R = GainData;
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_V success#####\r\n",__FUNCTION__);
			break;
		}
	}
	else //fail
	{
		result = FALSE;
		switch(Channel)
		{
			case AutoColor_Y:
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_Y fail#####\r\n",__FUNCTION__);
			break;

			case AutoColor_U:
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_U fail#####\r\n",__FUNCTION__);
			break;

			case AutoColor_V:
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "###%s AutoColor_V fail#####\r\n",__FUNCTION__);
			break;
		}
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "diff_gain : %x, Check_idx : %x\n", diff_gain, Check_idx);


	return result;

}


void ypbpr_auto_color_initial_setting(void)//Auto color initial seeting at beginning
{
	extern StructDisplayInfo * Get_ADC_Dispinfo(void);//For Auto color to use
	StructDisplayInfo * p_dispinfo = Get_ADC_Dispinfo();
	if(get_adc_abl_function()==_DISABLE)
	{
		YPbPr_ABL_SETTING_ON(p_dispinfo->ucMode_Curr);
		msleep(100);
	}
}

//#define auto_clr_acitve_Y
unsigned char ypbpr_auto_color_gain_calibration(ADCGainOffset * ptADC_info, unsigned char bartype)//Auto color gian calibration flow
{
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	color_d_vc_global_ctrl_RBUS color_d_vc_global_ctrl_reg;

	unsigned short Active_Region[4];
	unsigned short Black_Pos[4];
	unsigned short White_Pos[4];
	unsigned short Magenta_Pos[4];
	unsigned short Y_Target_Offset=0;
	unsigned short U_Target_Offset=0;
	unsigned short V_Target_Offset=0;
	unsigned short Y_Target_Gain=0;
	unsigned short U_Target_Gain=0;
	unsigned short V_Target_Gain=0;
	YUV_RGB_ADC DRAGON_ADC = {G_ADC_Dragon, B_ADC_Dragon, R_ADC_Dragon};
	unsigned char result;

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "==================YPbPr_Adjustment start==================\n\n");
	//disable VidVid Color
	color_d_vc_global_ctrl_reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
	color_d_vc_global_ctrl_reg.m_vc_en = 0;
	color_d_vc_global_ctrl_reg.write_enable_11 = 1;
	//color_d_vc_global_ctrl_reg.regValue = color_d_vc_global_ctrl_reg.regValue | COLOR_D_VC_Global_CTRL_write_enable_11_mask;
	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, color_d_vc_global_ctrl_reg.regValue);

	Y_Target_Offset	= 64;//4;	//20120419 roger, modify to fit TSB style
	U_Target_Offset	= 512;
	V_Target_Offset = 512;

	if (bartype == _Y100UV100) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Pattern: _Y100UV100\n");
		Y_Target_Gain = _Y100UV100_COMPONENT_Y_TARGET;
		U_Target_Gain = _Y100UV100_COMPONENT_U_TARGET;
		V_Target_Gain = _Y100UV100_COMPONENT_V_TARGET;
	} else if(bartype == _Y75UV75) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Pattern: _Y75UV75\n");
		Y_Target_Gain = _Y75UV75_COMPONENT_Y_TARGET;;
		U_Target_Gain = _Y75UV75_COMPONENT_U_TARGET;
		V_Target_Gain = _Y75UV75_COMPONENT_V_TARGET;
	} else if(bartype == _Y100UV75) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "Pattern: _Y100UV75\n");
		Y_Target_Gain = _Y100UV75_COMPONENT_Y_TARGET;
		U_Target_Gain = _Y100UV75_COMPONENT_U_TARGET;
		V_Target_Gain = _Y100UV75_COMPONENT_V_TARGET;
	} else {
		return FALSE;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "############target:%d %d %d###############\r\n", Y_Target_Gain, U_Target_Gain, V_Target_Gain);

	//Active region
	drvif_auto_get_activeregion(&Active_Region[0]);
	drvif_auto_get_smartfit_windows( &Active_Region[0], &Black_Pos[0], &White_Pos[0], &Magenta_Pos[0]);

#ifdef auto_clr_acitve_Y //for debugging
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Active_Region=%d,%d,%d,%d\n\n",Active_Region[0],Active_Region[0]+Active_Region[1],Active_Region[2],Active_Region[2]+Active_Region[3]);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Black_Pos=%d,%d,%d,%d\n",Black_Pos[0],Black_Pos[1],Black_Pos[2],Black_Pos[3]);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "White_Pos=%d,%d,%d,%d\n",White_Pos[0],White_Pos[1],White_Pos[2],White_Pos[3]);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Magenta_Pos=%d,%d,%d,%d\n\n",Magenta_Pos[0],Magenta_Pos[1],Magenta_Pos[2],Magenta_Pos[3]);
#endif
#ifdef CONFIG_WATCHDOG_ENABLE
	IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
	IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif

	//20070713 VIP/Jason
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "<<< Y adjustment: >>>add\n");
	result = drvif_auto_autocolor_gain_adjust_loop(ptADC_info, Y_Target_Gain, &White_Pos[0],  0xff, DRAGON_ADC.Y_RGB_idx, AutoColor_Y);//For AWB
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] result=%d\n", __FUNCTION__, __LINE__, result);

#ifdef CONFIG_WATCHDOG_ENABLE
	IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
	IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "<<< U adjustment: >>>\n");
	if(result) result = drvif_auto_autocolor_gain_adjust_loop(ptADC_info, U_Target_Gain, &Magenta_Pos[0],  0xff, DRAGON_ADC.U_RGB_idx, AutoColor_U);//For AWB

#ifdef CONFIG_WATCHDOG_ENABLE
	IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
	IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "<<< V adjustment: >>>\n");
	if(result) result = drvif_auto_autocolor_gain_adjust_loop(ptADC_info, V_Target_Gain, &Magenta_Pos[0],  0xff, DRAGON_ADC.V_RGB_idx, AutoColor_V);//For AWB

#ifdef CONFIG_WATCHDOG_ENABLE
	IoReg_Write32(TC_WR_TR_VADDR, 1);//tick system WD, to avoid system reset
	IoReg_Write32(TC_WR_TR_VADDR, 0); //kick watchdog
#endif
	rtd_printk(KERN_INFO, TAG_NAME_ADC, "<<<FINAL CHECK>>>\n\n");


	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Y of White(%d)=%d\n",Y_Target_Gain,drvif_auto_smartfit_finddominant(White_Pos[0], White_Pos[1], White_Pos[2], White_Pos[3],AutoColor_Y));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "U of Magenta(%d)=%d\n",U_Target_Gain,drvif_auto_smartfit_finddominant(Magenta_Pos[0], Magenta_Pos[1], Magenta_Pos[2], Magenta_Pos[3],AutoColor_U));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "V of Magenta(%d)=%d\n",V_Target_Gain,drvif_auto_smartfit_finddominant(Magenta_Pos[0], Magenta_Pos[1], Magenta_Pos[2], Magenta_Pos[3],AutoColor_V));

	//ensable VidVid Color
	color_d_vc_global_ctrl_reg.regValue = IoReg_Read32(COLOR_D_VC_Global_CTRL_reg);
	color_d_vc_global_ctrl_reg.m_vc_en = 1;
	color_d_vc_global_ctrl_reg.write_enable_11 = 1;
	//color_d_vc_global_ctrl_reg.regValue = color_d_vc_global_ctrl_reg.regValue | COLOR_D_VC_Global_CTRL_write_enable_11_mask;
	IoReg_Write32(COLOR_D_VC_Global_CTRL_reg, color_d_vc_global_ctrl_reg.regValue);

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "================== YPbPr_Adjustment end==================\n\n");
	if (result) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "YPbPr auto color success~!\n");
	} else {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "YPbPr auto color Fail!\n");
	}
	return result;

}

unsigned char ypbpr_auto_color_offset_calibration(ADCGainOffset * ptADC_info)//Auto color offset calibration flow
{
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	ptADC_info->Offset_R = adc_adc_offset0_reg.adc_off_red;
	ptADC_info->Offset_G = adc_adc_offset0_reg.adc_off_grn;
	adc_adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	ptADC_info->Offset_B = adc_adc_offset1_reg.adc_off_blu;

	return true;

}

void drvif_self_awb_offset_adjust_proc(ADCGainOffset * ptADC_info)
{
	abl_abl_window_RBUS abl_window_reg;
	abl_abl_ctrl_RBUS abl_ctrl_reg;
	abl_abl_mgn_rg_RBUS abl_mgn_rg_reg;
	abl_abl_mgn_b_RBUS abl_mgn_b_reg;
	//adc_adc_offset0_RBUS adc_offset0_reg;
	//adc_adc_offset1_RBUS adc_offset1_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;

	abl_window_reg.regValue = 0;


	abl_window_reg.abl_vend = YPBPR_ABL_1080P_V_END;
	abl_window_reg.abl_wait_line = YPBPR_ABL_HD_WAIT_LINE;
	abl_window_reg.abl_vsta = YPBPR_ABL_HD_V_START;
	abl_window_reg.abl_line = YPBPR_ABL_HD_LINE_AVG;
	abl_window_reg.abl_h_width = YPBPR_ABL_HD_H_WIDTH;
	abl_window_reg.abl_start_pos = YPBPR_ABL_HD_H_START;

	IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);	//darwin,mag
	//IoReg_Write32(ABL_ABL_WINDOW_reg, abl_window_reg.regValue);	//mac


	abl_mgn_rg_reg.regValue = 0;
	//abl_mgn_rg_reg.abl_eq_mgn_red = YPBPR_ABL_UV_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_red = YPBPR_ABL_EQUAL_MARGIN_INIT;
	abl_mgn_rg_reg.abl_l_mgn_red = YPBPR_ABL_UV_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_red = YPBPR_ABL_LOCK_MARGIN;
	abl_mgn_rg_reg.abl_eq_mgn_grn = YPBPR_ABL_EQUAL_MARGIN_INIT;
//	abl_mgn_rg_reg.abl_eq_mgn_grn = YPBPR_ABL_Y_EQUAL_MARGIN;
	abl_mgn_rg_reg.abl_l_mgn_grn = YPBPR_ABL_Y_LARGE_MARGIN;
	abl_mgn_rg_reg.abl_lock_mgn_grn = YPBPR_ABL_LOCK_MARGIN;

	IoReg_Write32(ABL_ABL_MGN_RG_reg, abl_mgn_rg_reg.regValue);//darwin,mag
	//IoReg_Write32(ABL_ABL_MGN_RG_VADDR, abl_mgn_rg_reg.regValue);	//mac


	abl_mgn_b_reg.regValue = 0;
	abl_mgn_b_reg.abl_eq_mgn_blu = YPBPR_ABL_EQUAL_MARGIN_INIT;
	//abl_mgn_b_reg.abl_eq_mgn_blu = YPBPR_ABL_UV_EQUAL_MARGIN;
	abl_mgn_b_reg.abl_l_mgn_blu = YPBPR_ABL_UV_LARGE_MARGIN;
	abl_mgn_b_reg.abl_lock_mgn_blu = YPBPR_ABL_LOCK_MARGIN;

	IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);	//darwin,mag
	//IoReg_Write32(ABL_ABL_MGN_B_reg, abl_mgn_b_reg.regValue);	//mac


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


	abl_ctrl_reg.abl_r_dir_inv = 1;	//000: RGB all nodes are separate, ABL will adjust negative node dac voltage
	abl_ctrl_reg.abl_g_dir_inv = 0;	//000: RGB all nodes are separate, ABL will adjust negative node dac voltage
	abl_ctrl_reg.abl_b_dir_inv = 1;	//000: RGB all nodes are separate, ABL will adjust negative node dac voltage


	abl_ctrl_reg.abl_href_sel = 0;
	abl_ctrl_reg.abl_target_value = _ABL_YPP_TARGET_VALUE;
	//abl_ctrl_reg.abl_target_value = 0x0F; //_ABL_TARGET_VALUE; // change target value from 8:(1) to 64 (0x0f) Jerry


	IoReg_Write32(ABL_ABL_CTRL_reg, abl_ctrl_reg.regValue);//darwin,mag
	msleep(100);//Need to wait
	adc_adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	ptADC_info->Offset_R = adc_adc_offset0_reg.adc_off_red;
	ptADC_info->Offset_G = adc_adc_offset0_reg.adc_off_grn;
	adc_adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	ptADC_info->Offset_B = adc_adc_offset1_reg.adc_off_blu;
}


void drvif_self_awb_initial_setting(void)//Auto color initial seeting at beginning
{
	sync_processor_sp_adc_out_sel_RBUS  sync_processor_sp_adc_out_sel_reg;
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;
	adc_adc_offset0_RBUS adc_adc_offset0_reg;
	adc_adc_offset1_RBUS adc_adc_offset1_reg;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;
	dds_pll_pll_ctrl_RBUS dds_pll_pll_ctrl_reg;
	dds_pll_plldiv_RBUS dds_pll_plldiv_reg;
	dds_pll_pllphase_ctrl_RBUS dds_pll_pllphase_ctrl_reg;
	dds_pll_dds_mix_w1_RBUS dds_pll_dds_mix_w1_reg;
	dds_pll_dds_mix_w2_RBUS dds_pll_dds_mix_w2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_clock_RBUS adc_adc_clock_reg;
	dds_pll_pll_set_RBUS dds_pll_pll_set_reg;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;
	dds_pll_pll_phase_interpolation_RBUS dds_pll_pll_phase_interpolation_reg;
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;

	//Enable ADC CRT.
	enum CRT_CLK clken = CLK_ON;
	CRT_CLK_OnOff(SCALER_AUTO_CLK_1, clken, NULL );

	sync_processor_sp_adc_out_sel_reg.regValue = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg, sync_processor_sp_adc_out_sel_reg.regValue); // Source select of SyncProc output => ADC Mod
	//IoReg_Write32(SYNC_PROCESSOR_SP_ADC_OUT_SEL_reg, 0x00000000); // Source select of SyncProc output => ADC Mode

	adc_adc_offset0_reg.regValue = 0;
	adc_adc_offset0_reg.adc_off_grn = 512;//Green Channel Offset Adjust 0~0.8V Setting is 0.4V
	adc_adc_offset0_reg.adc_off_red = 512;//Red Channel Offset Adjust 0~0.8V Setting is 0.4V
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_adc_offset0_reg.regValue);
	//IoReg_Write32(ADC_ADC_OFFSET0_reg, 0x02000200);


	adc_adc_offset1_reg.regValue = 0;
	adc_adc_offset1_reg.adc_off_blu = 512;//Blue Channel Offset Adjust 0~0.8V Setting is 0.4V
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_adc_offset1_reg.regValue);
	//IoReg_Write32(ADC_ADC_OFFSET1_reg, 0x00000200);

	adc_adc_ctl_rgb12_reg.regValue = IoReg_Read32(ADC_ADC_CTL_RGB12_reg);
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_6 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_7 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_8 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_9 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_11_10 = 1;

	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_6 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_7 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_8 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_9 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0;
	IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);

	//SOG CMP bias current Max
	adc_adc_clamp_ctrl3_reg.regValue = 0;
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl5_14_13 = 3;//SOG_ADC_CMP bias current 11: 60?A
	IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, adc_adc_clamp_ctrl3_reg.regValue);
	//IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, 0x00006000); // clamp3 default value. SOG_ADC_CMP bias current [14:13] 11: 60?A

	/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial*/
	adc_adc_clamp_ctrl0_reg.regValue = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 1;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;

	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

	/* ADC intinal Clamp DAC source select */
	adc_adc_ctl_1_reg.regValue = 0;
	adc_adc_ctl_1_reg.adc_ctl_grn_2_0 = 0;/* 3b DAC clamp voltage for green channel Voffset 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_grn_5_3 = 3;/* 3b DAC clamp voltage for green channel Vmid 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_grn_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_grn_10_9= 0;
	adc_adc_ctl_1_reg.adc_ctl_red_2_0 = 0;/* 3b DAC clamp voltage for red channel Voffset 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_red_5_3 = 3;/* 3b DAC clamp voltage for red channel Vmid 0.4v */
	adc_adc_ctl_1_reg.adc_ctl_red_8_6 = 3;
	adc_adc_ctl_1_reg.adc_ctl_red_10_9= 0;
	IoReg_Write32(ADC_ADC_CTL_1_reg, adc_adc_ctl_1_reg.regValue);

	adc_adc_ctl_2_reg.regValue = 0;
	adc_adc_ctl_2_reg.adc_ctl_blu_2_0 = 0;
	adc_adc_ctl_2_reg.adc_ctl_blu_5_3 = 3;
	adc_adc_ctl_2_reg.adc_ctl_blu_8_6 = 3;
	adc_adc_ctl_2_reg.adc_ctl_blu_10_9= 0;
	/* 3b DAC clamp voltage for blue channel Voffset 0.4v */
	/* 3b DAC clamp voltage for blue channel Vmid 0.4v */
	IoReg_Write32(ADC_ADC_CTL_2_reg, adc_adc_ctl_2_reg.regValue);

	//PLL_Phase_INTERPLOATION
	dds_pll_pll_phase_interpolation_reg.regValue = 0;
	dds_pll_pll_phase_interpolation_reg.pllsphrl = 1;//default 8k below 25M
	dds_pll_pll_phase_interpolation_reg.pllsphrs = 5;//default
	IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg, dds_pll_pll_phase_interpolation_reg.regValue);

	//APLL initial setting
	//PLL_SET
	dds_pll_pll_set_reg.regValue = 0;
	dds_pll_pll_set_reg.pll_m = 3;//[To DDS] PLLM [7:0] (PLL DPM value - 3)
	dds_pll_pll_set_reg.pll_n = 1;// REG_PLLSN in APLL (PLL DPN value - 2)
	dds_pll_pll_set_reg.pllssi = 3;//PLL Charger Pump Current IchDpll
	dds_pll_pll_set_reg.pllscp = 1;
	dds_pll_pll_set_reg.pllscs = 3;
	dds_pll_pll_set_reg.pllsrs = 3;//default 10k
	IoReg_Write32(DDS_PLL_PLL_SET_reg, dds_pll_pll_set_reg.regValue);
	//IoReg_Write32(DDS_PLL_PLL_SET_reg, 0x03030103); // DDS_PLL_PLL_SET_REGISTER_VADDR // M=6,N=3,K=0

	dds_pll_pll_ctrl_reg.regValue = 0;
	dds_pll_pll_ctrl_reg.pllpwdn = 1;//REG_APLLPWDN (PLL Power Down) 1: Power Down
	dds_pll_pll_ctrl_reg.hs_dds2synp_sel = 0;//HS_dds2synp latch edge 0: ADC Clock falling edge
	dds_pll_pll_ctrl_reg.apll_reg = 1;//REG_APLL_REG<1:0> V16 setting 01:1.68V (default)
	dds_pll_pll_ctrl_reg.pllswdrst = 0;//REG_PLLSWDRST (PLL WD Reset) 0: Normal 1: Reset
	dds_pll_pll_ctrl_reg.adckmode = 3;//ADCKMODE [1:0] (ADC Input Clock Select Mode) 11: Dual Clock Mode (1x and 2x Clock)
	dds_pll_pll_ctrl_reg.apllldosel = 1;//LDO reference voltage setting  01:1.1V(default);
	dds_pll_pll_ctrl_reg.apllldopow = 1;//LDO Power 1:Power on
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	//IoReg_Write32(DDS_PLL_PLL_CTRL_reg,0x0005064d);
	dds_pll_pll_ctrl_reg.pllpwdn = 0;//REG_APLLPWDN (PLL Power Down) 0: Normal Run
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, dds_pll_pll_ctrl_reg.regValue);
	//IoReg_Write32(DDS_PLL_PLL_CTRL_reg,0x00050608);// DDS_PLL_PLL_CTRLPLL_REGISTER_VADDR // enable APLL & dual clk,   //HS_dds2synp latch edge , falling edge latch


	dds_pll_plldiv_reg.regValue = 0;
	dds_pll_plldiv_reg.apll_reserve = 3; //default thermal delay ypp 0x3
	dds_pll_plldiv_reg.pll_divider = 857;//Divider=857 = 0x359
	IoReg_Write32(DDS_PLL_PLLDIV_reg, dds_pll_plldiv_reg.regValue);
	//IoReg_Write32(DDS_PLL_PLLDIV_reg, 0x00020359);

	// ADC_PLLPHSE_CTRL rzhen@2016-06-29
	adc_smartfit_adc_pllphase_ctrl_reg.regValue = 0;
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut_index_msb = 1;//MSB of 128 phase (Only for ADC CLK=1/4 VCO CLK)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2x = 1;//[To Smart Fit] PLLX (PLL X Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2y = 1;//[To Smart Fit] PLLY (PLL Y Phase control)
	adc_smartfit_adc_pllphase_ctrl_reg.pll2d2 = 0;//ADC CLK=1/2 VCO CLK
	adc_smartfit_adc_pllphase_ctrl_reg.pll2_ph_lut =1;//Phase_Select_Method 1: Look-Up-Table
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, adc_smartfit_adc_pllphase_ctrl_reg.regValue);

	dds_pll_pllphase_ctrl_reg.regValue = 0;
	dds_pll_pllphase_ctrl_reg.pllsph0path =1;//Long Path
	IoReg_Write32(DDS_PLL_PLLPHASE_CTRL_reg, dds_pll_pllphase_ctrl_reg.regValue);

	dds_pll_dds_mix_w1_reg.regValue = 0;
	dds_pll_dds_mix_w1_reg.new_mode_en = 0;/*disable new mode tracking*/
	dds_pll_dds_mix_w1_reg.new_mode_en_th = 1;//New mode enable threshold 011: 171
	dds_pll_dds_mix_w1_reg.new_mode_lock_th = 3;//New mode lock threshold=> while Q (PE) keep smaller than threshold for 32 HS 011: 11
	dds_pll_dds_mix_w1_reg.p_code_max = 2471;//Set p_code_max value to clamp the GAIN of APLL 2471 = 0x9a7
	dds_pll_dds_mix_w1_reg.lock_th = 6;//Judge threshold lock already => while Q (PE) keep smaller than threshold for 32 HS 011: 11
	IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, dds_pll_dds_mix_w1_reg.regValue);// P code max=316321 and new mode disable
	//IoReg_Write32(DDS_PLL_DDS_MIX_W1_reg, 0x3009a733);// P code max=316321 and new mode disable


	dds_pll_dds_mix_w2_reg.regValue = 0;
	dds_pll_dds_mix_w2_reg.sample_period = 2;//Phase error sample period choose 10: every 3 cycle sample
	dds_pll_dds_mix_w2_reg.delay_chain_length =2;//Delay chain length select  10: cnt= 33 => 209.9ns (default)
	dds_pll_dds_mix_w2_reg.change_mode_th = 2;//To judge when to increase a counter for pll_lock judgement 3'b010: change_mode_final = 12'd1571
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, dds_pll_dds_mix_w2_reg.regValue);
	//IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, 0x000002a0);// Delay chain select (Default value)


	/* MSB delay turn on */
	adc_adc_vbias_reg.regValue = 0;
	adc_adc_vbias_reg.adc_vbias0_0 = 1;/*ADC Sample 011 */
									   /* LDO voltage select 011:1.1v bit[7:5]=101 bit[4:2]=010 bit0=1*/
	adc_adc_vbias_reg.adc_vbias0_1 = 0;
	adc_adc_vbias_reg.adc_vbias0_4_2 = 2;
	adc_adc_vbias_reg.adc_vbias0_7_5 = 5;
	adc_adc_vbias_reg.adc_vbias1_3_2 = 0x3;//BIT [3:2] SF driving current select (00:840uA 01:960uA 10:1080uA 11:1200uA00uA)  //spec change 20161203
	adc_adc_vbias_reg.adc_vbias1_6 = 1;
	adc_adc_vbias_reg.adc_vbias1_7 = 1;
	adc_adc_vbias_reg.adc_vbias2_2_0 = 3;/* ADC Gain Calibration Gain_Cal_DAC3B Voltage, 011:0.7V */
	adc_adc_vbias_reg.adc_vbias3_1_0 = 1;/* bandgap voltage select */

	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	//
	adc_adc_clock_reg.regValue = 0;
	adc_adc_clock_reg.adc_clock_1_0 = 3;//Duty cycle 11: 52%
	adc_adc_clock_reg.adc_2x_sample_0 = 1;//Online Auto SOY ADC clock select 1: CKAPLL<1:0>
	adc_adc_clock_reg.adc_2x_sample_5 = 1;//RGB 1X Output Clock (ADC_CLK_1X) Polarity  1:Positive
	IoReg_Write32(ADC_ADC_CLOCK_reg, adc_adc_clock_reg.regValue);
	//IoReg_Write32(ADC_ADC_CLOCK_reg, 0x00210003);		// clock polarity, divider APLL clock duty adjust to 52%


	//ADC clock 1x,2x,invert, Swap ADC setting
	adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
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

	YPbPr_ABL_SETTING_OFF();
}



unsigned char ypbpr_self_awb_offset_calibration(ADCGainOffset * ptADC_info)
{
	UINT32 SP1_Ctrl;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
   	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS  sync_processor_sp1_ctrl_reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sync_processor_sp1_clmp_RBUS sync_processor_sp1_clmp_reg;
	sync_processor_sp1_clmpctrl_RBUS  sync_processor_sp1_clmpctrl_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
#if 0/*Fix error by Will Magellan2*/
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;//leochen
	adc_adc_clamp_ctrl0_RBUS adc_clamp_ctrl0_reg;
	UINT16 ADC_BandWidth;//result1
#endif
	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
#if 0/*Fix error by Will Magellan2*/
	ADC_BandWidth = adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = 0;  // 10 M
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 1;  //Self_Offset Connect to input PAD .Brandon Add for LG
#endif
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
#if 0/*Fix error by Will Magellan2*/
	adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
	adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 1;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 1;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 1;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1= 1;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10 = 0;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 0;
	adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_clamp_ctrl0_reg.regValue);

	adc_adc_ctl_rgb12_reg.regValue = IoReg_Read32(ADC_ADC_CTL_RGB12_reg);//Self Offset use YPP input path/DAC1 for adjust
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_7 = 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0= 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2= 1;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4= 1;
	IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);
#endif
	YPbPr_ADCPowerControl(ON);

	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, 0x3ff);

	EnableIPTGInSXGA();    //IPTG,APLL,VGIP setting
#if 0/*Fix error by Will Magellan2*/
	adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	adc_adc_vbias_reg.adc_vbias2_5 = 1; // clamp always enable,Self Offset clmap to H for 10bit DAC adjust for ABL
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
#endif
	//Set Clamp Plus
	sync_processor_sp1_clmp_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CLMP_reg);
	sync_processor_sp1_clmp_reg.s1_yclamp_sta = 0x45;
	sync_processor_sp1_clmp_reg.s1_yclamp_end = 0x5D;
	sync_processor_sp1_clmp_reg.s1_nyclamp_sta = 0x45;
	sync_processor_sp1_clmp_reg.s1_nyclamp_end = 0x5D; //for HD timing
	IoReg_Write32(SYNC_PROCESSOR_SP1_CLMP_reg, sync_processor_sp1_clmp_reg.regValue);

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

	adc_adc_clamp_ctrl3_reg.regValue= IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl6_4 = 1;	//b8020028[20]
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl6_0 = 1;	//b8020028[16]
	IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg,adc_adc_clamp_ctrl3_reg.regValue);

	//enable Hysnc Type Detection Auto Run
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	SP1_Ctrl = sync_processor_sp1_ctrl_reg.regValue ;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel=1;
	sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
	//msleep(33);//frank@0507 hw setting 1ms from 20ms for Automatic reset
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
    msleep(50);//AWB need for Syncprocessor

	vgip_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_vgip_chn1_ctrl_reg.ch1_in_sel = 1;
	IoReg_Write32(VGIP_VGIP_CHN1_CTRL_reg,vgip_vgip_chn1_ctrl_reg.regValue );

	ptADC_info->Offset_B = 0x000;
	ptADC_info->Offset_G = 0x000;
	ptADC_info->Offset_R = 0x000;
	auto_adcgainset(_SRC_YPBPR, ptADC_info);
	auto_adcoffsetset(_SRC_YPBPR, ptADC_info);

	//Star to Self ABL

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "[SelfAWB_Offset] Self ABL start!\t");

	adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0; //enable clamp    //Not yet change to YPP
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 3;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

	drvif_self_awb_offset_adjust_proc(ptADC_info);

	if((ptADC_info->Offset_R == 0x3ff) || (ptADC_info->Offset_R == 0x00) || (ptADC_info->Offset_G == 0x3ff) || (ptADC_info->Offset_G== 0x00) || (ptADC_info->Offset_B == 0x3ff) || (ptADC_info->Offset_B == 0x00))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB Offset fail fail (%d %d %d)!!!\n", ptADC_info->Offset_R , ptADC_info->Offset_G, ptADC_info->Offset_B);
		goto PROCESS_ERROR;
	}
	else
	{
#if 0/*Fix error by Will Magellan2*/
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;
#endif
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue );
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		rtd_printk(KERN_INFO, TAG_NAME_ADC, "[SelfAWB] SelfAWB offset success for YPP!\t");

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Result: offsetR=0x%x=%d  offsetG=0x%x=%d  offsetB=0x%x=%d\n",ptADC_info->Offset_R,ptADC_info->Offset_R,ptADC_info->Offset_G,ptADC_info->Offset_G,ptADC_info->Offset_B,ptADC_info->Offset_B);

		adc_adc_vbias_reg.adc_vbias2_2_0 = 3; // 0.9V
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		// oliver+,20131126
		//fwif_ADC_SaveSelfAWBResult();
		return TRUE;
	}
PROCESS_ERROR:
#if 0/*Fix error by Will Magellan2*/
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;
#endif
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "[SelfAWB] SelfAWB Offset ABORT\n");

        return FALSE;
}

unsigned char drvif_self_awb_gain_fast_calibration(int src, ADCGainOffset * ptADC_info)
{
    bool error = false;
	enum PLAFTORM_TYPE platform = PLATFORM_KXL;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	UINT16 difftarget_y = KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y, difftarget_pr = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR, difftarget_pb = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB;
	UINT16 rev,  count, ADC_BandWidth;
	UINT16 diffvalue_y, diffvalue_pr, diffvalue_pb;
	UINT16 gain_value_r, gain_value_g, gain_value_b;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;//leochen
	adc_adc_ctl_1_RBUS adc_adc_ctl_1_reg;
	adc_adc_ctl_2_RBUS adc_adc_ctl_2_reg;
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;//leochen
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
   	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS  sync_processor_sp1_ctrl_reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sync_processor_sp1_autorst_RBUS sync_processor_sp1_autorst_reg;
	sync_processor_updw_global_ctrl1_RBUS sync_processor_updw_global_ctrl1_reg;
	UINT32 SP1_Ctrl;
	int tune_count = 0;
	unsigned char y_ready = FALSE, pr_ready = FALSE, pb_ready = FALSE;

	if(src == _SRC_YPBPR){
		platform = get_platform();//Get platform
		if(platform == PLATFORM_KXLP) {
			difftarget_y = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_Y;
			difftarget_pr = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			difftarget_pb = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PB;
		}
	}else{// _SRC_VGA
		difftarget_y = _AUTO_SELF_VGA_LEVEL_TARGET_G;
		difftarget_pr = _AUTO_SELF_VGA_LEVEL_TARGET_R;
		difftarget_pb = _AUTO_SELF_VGA_LEVEL_TARGET_B;
	}

	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
	ADC_BandWidth = adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0;
	adc_adc_dcrestore_ctrl_reg.regValue = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

	YPbPr_ADCPowerControl(ON);

	//disable up/dn clamp for awb
	sync_processor_updw_global_ctrl1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL1_reg);
	sync_processor_updw_global_ctrl1_reg.updw_en_r = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_en_g = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_en_b = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_clamp_en = 0x0;
	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL1_reg, sync_processor_updw_global_ctrl1_reg.regValue);

	adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

	//enable voltage clamp for awb
	adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 1;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

	EnableIPTGInSXGA();

	adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	adc_adc_vbias_reg.adc_vbias2_5 = 1; // clamp always enable
	adc_adc_vbias_reg.adc_vbias2_7 = 1;  // Calibration
    adc_adc_vbias_reg.adc_vbias2_4 = 1;  //Gain_Cal_DAC3B
    adc_adc_vbias_reg.adc_vbias2_2_0 = 4; // 0.85V
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	//enable Hysnc Type Detection Auto Run
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	SP1_Ctrl = sync_processor_sp1_ctrl_reg.regValue ;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel=1;
	sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
	//msleep(33);//frank@0507 hw setting 1ms from 20ms for Automatic reset
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
    //msleep(50);//AWB need for Syncprocessor

   	count = 1000;
    do{//Wait (sync_processor_sp1_autorst_reg.s1_auto_result == 6). Can not remove
		sync_processor_sp1_autorst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_AutoRst_reg);
		if((sync_processor_sp1_autorst_reg.s1_auto_result == 6) || (count-- == 0)) break;
		msleep(5);
    }while(1);

	vgip_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_vgip_chn1_ctrl_reg.ch1_in_sel = 1;
	IoReg_Write32(VGIP_VGIP_CHN1_CTRL_reg,vgip_vgip_chn1_ctrl_reg.regValue );

	ptADC_info->Gain_B = (src==_SRC_YPBPR? _AUTO_YPP_DEFAULT_GAIN_PB: _AUTO_VGA_DEFAULT_GAIN_B);
	ptADC_info->Gain_G = (src==_SRC_YPBPR? _AUTO_YPP_DEFAULT_GAIN_Y: _AUTO_VGA_DEFAULT_GAIN_G);
	ptADC_info->Gain_R = (src==_SRC_YPBPR? _AUTO_YPP_DEFAULT_GAIN_PR: _AUTO_VGA_DEFAULT_GAIN_R);
	ptADC_info->Offset_B = 0x200;
	ptADC_info->Offset_G = 0x200;
	ptADC_info->Offset_R = 0x200;

	auto_adcgainset(src, ptADC_info);
	//auto_adcoffsetset(src, ptADC_info);

	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;

	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset0_reg.adc_off_red = ptADC_info->Offset_R;
	//IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);
	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset0_reg.adc_off_grn = ptADC_info->Offset_G;
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);

	adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	adc_offset1_reg.adc_off_blu = ptADC_info->Offset_B;
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] Initial ADC Gain = %d,%d,%d\n",ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_B);//leochen

	tune_count = 0;
	auto_AdcGainAdjustReset();	// Reset ADC Gain max and min value;

	count = 20;
	do
	{
		tune_count++;

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB]Gain_Tune %2d reday:%d %d %d\t", tune_count, pr_ready, y_ready, pb_ready);
		rev = drvif_self_awb_gain_adjust_allchannel_proc(pr_ready, y_ready, pb_ready, &diffvalue_pr, &diffvalue_y, &diffvalue_pb, src, ptADC_info);

		if(rev != ERROR_SUCCEED)
			goto PROCESS_ERROR;

		if(pr_ready == FALSE)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pr:(%d %d %d)\n", diffvalue_pr, difftarget_pr, ABS(diffvalue_pr, difftarget_pr));
			if(ABS(diffvalue_pr, difftarget_pr) < 2)// && (ABS(result1, usMin_Value) < 2))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB OK for Pr, Diff = %d, Target=%d count=%d\n",diffvalue_pr,difftarget_pr, tune_count);
				pr_ready = TRUE;
			}
			else
			{
				if(diffvalue_pr < difftarget_pr)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pr Decrease gain => gain_new=%d\n",ptADC_info->Gain_R);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pr Increase gain => gain_new=%d\n",ptADC_info->Gain_R);
			}
		}

		if(y_ready == FALSE)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Y: (%d %d %d)\n", diffvalue_y, difftarget_y, ABS(diffvalue_y, difftarget_y));
			if(ABS(diffvalue_y, difftarget_y) < 2)// && (ABS(result1, usMin_Value) < 2))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB OK for Y, Diff = %d, Target=%d count=%d\n",diffvalue_y, difftarget_y, tune_count);
				y_ready = TRUE;
			}
			else
			{
				if(diffvalue_y < difftarget_y)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Y Decrease gain => gain_new=%d\n",ptADC_info->Gain_G);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Y Increase gain => gain_new=%d\n",ptADC_info->Gain_G);
			}
		}

		if(pb_ready == FALSE)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pb:(%d %d %d)\n", diffvalue_pb, difftarget_pb, ABS(diffvalue_pb, difftarget_pb));
			if(ABS(diffvalue_pb, difftarget_pb) < 2)// && (ABS(result1, usMin_Value) < 2))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB OK for Pb, Diff = %d, Target=%d count=%d\n",diffvalue_pb,difftarget_pb, tune_count);
				pb_ready = TRUE;
			}
			else
			{
				if(diffvalue_pb < difftarget_pb)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pb Decrease gain => gain_new=%d\n",ptADC_info->Gain_B);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Pb Increase gain => gain_new=%d\n",ptADC_info->Gain_B);
			}
		}
		count--;
	}
	while(count &&( y_ready == FALSE || pr_ready == FALSE || pb_ready == FALSE));

	if( y_ready == FALSE || pr_ready == FALSE || pb_ready == FALSE)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] Reday Fail %d %d %d", pr_ready, y_ready, pb_ready);
		error = true;//Not all reday
	}

	if((ptADC_info->Gain_R == 0x00) || (ptADC_info->Gain_G== 0x00) || (ptADC_info->Gain_B == 0x00) || error)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB gain fail error:%d!\n", error);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB fail!\n");
		goto PROCESS_ERROR;
	}
	else
	{
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;// connectPad, 5k
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;

		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue );
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "[SelfAWB] SelfAWB gain success!!!\t");

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Result: gainR=0x%x=%d  gainG=0x%x=%d  gainB=0x%x=%d\n", ptADC_info->Gain_R, ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_G, ptADC_info->Gain_B, ptADC_info->Gain_B);
		drvif_get_default_gainvalue(&gain_value_r, &gain_value_g, &gain_value_b ,_SRC_YPBPR);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Ideal:  gainR=0x%3x=%3d  gainG=0x%3x=%3d  gainB=0x%3x=%3d\n",gain_value_r,gain_value_r,gain_value_g,gain_value_g,gain_value_b,gain_value_b);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Diff:   diffR=%9d  diffG=%9d  diffB=%9d\n",gain_value_r-ptADC_info->Gain_R,gain_value_g-ptADC_info->Gain_G,gain_value_b-ptADC_info->Gain_B);

		adc_adc_vbias_reg.adc_vbias2_2_0 = 3; // 0.9V
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		//disable voltage clamp
		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

		/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial	*/
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;/*G_channel negative clamp enable on Y0N*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 0;

		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

		// oliver+,20131126
		//fwif_ADC_SaveSelfAWBResult();
		return TRUE;
	}
PROCESS_ERROR:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;// connectPad, 5k
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);

		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;//Disable clamp on Vin012
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

		/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial*/
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;/*G_channel negative clamp enable on Y0N*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;

		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);


		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][SelfAWB] SelfAWB gain Gain ABORT\n", __FUNCTION__, __LINE__);
        return FALSE;
}


unsigned char ypbpr_self_awb_gain_calibration(ADCGainOffset * ptADC_info)
{
	return FALSE;
#if 0//Need to check
    bool error = false;
	UINT16 rev, result0, color= SELECT_BLUE, count, ADC_BandWidth;//result1,
	UINT16 difftarget;
	UINT16 gain_value_r, gain_value_g, gain_value_b;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;//leochen
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;//leochen
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
   	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	abl_reserved_RBUS abl_Reserved_reg;//leochen
	sync_processor_sp1_ctrl_RBUS  sync_processor_sp1_ctrl_reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sync_processor_sp1_autorst_RBUS sync_processor_sp1_autorst_reg;
	UINT32 SP1_Ctrl;
	int tune_count = 0;

#if 0/*Fix error by Will Magellan2*/
	adc_adc_ctl_rgb12_reg.regValue = IoReg_Read32(ADC_ADC_CTL_RGB12_reg);
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 0;
	adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 0;
	IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);


	adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = _ENABLE;	//Red[2]- Negative Clamp Enable
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10 = _ENABLE;	//Green[1]- Negative Clamp Enable
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = _ENABLE;		//Blue[0]- Negative Clamp Enable
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0;	//Red No Swap
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4 = 0;	//Green No Swap
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_3 = 0;	//Blue No Swap
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;	//Green[4]- Negative Clamp Disable
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 0;	//R0=DAC
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 0;	//G0=DAC
	adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 0;		//B0=DAC
	IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);
#endif

	adc_adc_clamp_ctrl3_reg.regValue= IoReg_Read32(ADC_ADC_CLAMP_CTRL3_reg);
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl6_4 = 0;	//b8020028[20]
	adc_adc_clamp_ctrl3_reg.adc_clamp_ctrl6_0 = 0;	//b8020028[16]
	IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg,adc_adc_clamp_ctrl3_reg.regValue);

	abl_Reserved_reg.regValue = IoReg_Read32(ABL_Reserved_reg);//leochen

#if 0/*Fix error by Will Magellan2*/
	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
	ADC_BandWidth = adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0=0;  // 10 M
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
#endif
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

	YPbPr_ADCPowerControl(ON);

	//msleep(1000);//Fix error by will
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, 0x3ff);

	EnableIPTGInSXGA();

	adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	adc_adc_vbias_reg.adc_vbias2_5 = 1; // clamp always enable
	adc_adc_vbias_reg.adc_vbias2_7=1;  // Calibration
    adc_adc_vbias_reg.adc_vbias2_4 = 1;  //Gain_Cal_DAC3B
    adc_adc_vbias_reg.adc_vbias2_2_0 = 4; // 0.85V
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	//enable Hysnc Type Detection Auto Run
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	SP1_Ctrl = sync_processor_sp1_ctrl_reg.regValue ;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel=1;
	sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
	//msleep(33);//frank@0507 hw setting 1ms from 20ms for Automatic reset
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
    //msleep(50);//frank@0507 hw setting 1ms from 20ms for Automatic reset

	count = 1000;
    do{//Wait (sync_processor_sp1_autorst_reg.s1_auto_result == 6). Can not remove
		sync_processor_sp1_autorst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_AutoRst_reg);
		if((sync_processor_sp1_autorst_reg.s1_auto_result == 6) || (count-- == 0)) break;
		msleep(5);
    }while(1);

	vgip_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_vgip_chn1_ctrl_reg.ch1_in_sel = 1;
	IoReg_Write32(VGIP_VGIP_CHN1_CTRL_reg,vgip_vgip_chn1_ctrl_reg.regValue );

	ptADC_info->Gain_B = _AUTO_YPP_DEFAULT_GAIN_PB;
	ptADC_info->Gain_G = _AUTO_YPP_DEFAULT_GAIN_Y;
	ptADC_info->Gain_R = _AUTO_YPP_DEFAULT_GAIN_PR;
	ptADC_info->Offset_B = 0x200;
	ptADC_info->Offset_G = 0x200;
	ptADC_info->Offset_R = 0x200;

	auto_adcgainset(_SRC_YPBPR, ptADC_info);
	auto_adcoffsetset(_SRC_YPBPR, ptADC_info);

	printk(KERN_INFO "\n[SelfAWB] Initial YPP Gain = %d,%d,%d\n", ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_B);//leochen

	printk(KERN_INFO "\n[SelfAWB] Blue measure start!\t");
	tune_count = 0;
	auto_AdcGainAdjustReset();

	while(_TRUE)
	{
		count = 0x30;
		// Reset ADC Gain max and min value;

		drvif_SelfAWB_gettargetvalue(&difftarget, color, _SRC_YPBPR);

		do
		{
			tune_count++;
			if(color == SELECT_BLUE)			// 2 : Blue or PB
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[SelfAWB] SelfAWB_Tune YPP Pb  %2d\t",tune_count);
			else if(color == SELECT_GREEN)		// 1: Green or Y
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[SelfAWB] SelfAWB_Tune YPP Y   %2d\t",tune_count);
			else								// 0: Red or PR
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[SelfAWB] SelfAWB_Tune YPP Pr  %2d\t",tune_count);
			rev = drvif_self_awb_gain_adjust_proc(color, &result0, difftarget, _SRC_YPBPR, ptADC_info);

			if(rev != ERROR_SUCCEED)
				goto PROCESS_ERROR;


			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "result0=%d, usMax_Value=%d, diff=%d\n", result0, difftarget, ABS(result0, difftarget));

			if(ABS(result0, difftarget) < 2)// && (ABS(result1, usMin_Value) < 2))
			{
				printk(KERN_INFO "\n[SelfAWB] SelfAWB OK for YPP color=%d, Diff = %d, Target=%d count=%d\n",color,result0,difftarget,tune_count);
				break;
			}
			else
			{
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "[SelfAWB] Target=%d Diff-Target=%d\t=> ",difftarget,result0-difftarget);
				if(color == SELECT_BLUE)			// 2 : Blue or PB
				{
					if((result0-difftarget)<0)
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Decrease gain => gain_new=%d\n",ptADC_info->Gain_B);
					else
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Increase gain => gain_new=%d\n",ptADC_info->Gain_B);
				}
				else if(color == SELECT_GREEN)		// 1: Green or Y
				{
					if((result0-difftarget)<0)
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Decrease gain => gain_new=%d\n",ptADC_info->Gain_G);
					else
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Increase gain => gain_new=%d\n",ptADC_info->Gain_G);
				}
				else								// 0: Red or PR
				{
					if((result0-difftarget)<0)
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Decrease gain => gain_new=%d\n",ptADC_info->Gain_R);
					else
						rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "Increase gain => gain_new=%d\n",ptADC_info->Gain_R);
				}
			}
			if((count > 8) && (ABS(result0, difftarget) <= 4))// && (ABS(result1, usMin_Value)))
			{
				count = 8;
			}


		}
		while(--count);

		if(ABS(result0, difftarget)>=20)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n\n[SelfAWB] Fail ABS(result0, usMax_Value)>=%d color:%d!\n",20,color);
			error = true;//The difference between result and target is too big
			break;
		}

		if(color == SELECT_BLUE)			// 2 : Blue or PB
		{
			color = SELECT_GREEN;
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n[SelfAWB] Green measure start!\t");
			tune_count=0;
		}
		else if(color == SELECT_GREEN)		// 1: Green or Y
		{
			color = SELECT_RED;
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\n[SelfAWB] Red measure start!\t");
			tune_count=0;
		}
		else								// 0: Red or PR
			break;
	}

	if((ptADC_info->Gain_R == 0x00) || (ptADC_info->Gain_G== 0x00) || (ptADC_info->Gain_B == 0x00) || error)
	{
		printk(KERN_INFO "\n\n[SelfAWB] SelfAWB gain fail error:%d!\n",error);
		printk(KERN_INFO "[SelfAWB] SelfAWB fail!\n");
		goto PROCESS_ERROR;
	}
	else
	{
#if 0/*Fix error by Will Magellan2*/
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;
#endif
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue );
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		printk(KERN_INFO "\n[SelfAWB] SelfAWB gain success for YPP!\t");

		printk(KERN_INFO "Result: gainR=0x%x=%d  gainG=0x%x=%d  gainB=0x%x=%d\n",ptADC_info->Gain_R,ptADC_info->Gain_R,ptADC_info->Gain_G,ptADC_info->Gain_G,ptADC_info->Gain_B,ptADC_info->Gain_B);
		drvif_get_default_gainvalue(&gain_value_r, &gain_value_g, &gain_value_b ,_SRC_YPBPR);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\t\t\t\t\tIdeal:  gainR=0x%3x=%3d  gainG=0x%3x=%3d  gainB=0x%3x=%3d\n",gain_value_r,gain_value_r,gain_value_g,gain_value_g,gain_value_b,gain_value_b);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "\t\t\t\t\tDiff:   diffR=%9d  diffG=%9d  diffB=%9d\n",gain_value_r-ptADC_info->Gain_R,gain_value_g-ptADC_info->Gain_G,gain_value_b-ptADC_info->Gain_B);

		adc_adc_vbias_reg.adc_vbias2_2_0 = 3; // 0.9V
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		// oliver+,20131126
		//fwif_ADC_SaveSelfAWBResult();
		return TRUE;
	}
PROCESS_ERROR:
#if 0/*Fix error by Will Magellan2*/
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;
#endif
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
		printk(KERN_INFO "\n[SelfAWB] SelfAWB gain Gain ABORT\n");

        return FALSE;
#endif
}


unsigned char drvif_self_awb_get_target_diff_proc(int src)
{
	extern struct semaphore* get_vsc_semaphore(void);
	extern struct semaphore* get_adc_detectsemaphore(void);
	extern void ADC_set_detect_flag(unsigned char enable);
	StructDisplayInfo  *p_timing = NULL;
	UINT16  ADC_BandWidth, count;//result1,
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;//leochen
	adc_adc_clamp_ctrl0_RBUS adc_adc_clamp_ctrl0_reg;//leochen
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_clamp_ctrl2_RBUS adc_adc_clamp_ctrl2_reg;
	adc_adc_clamp_ctrl3_RBUS adc_adc_clamp_ctrl3_reg;
   	adc_adc_vbias_RBUS adc_adc_vbias_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	sync_processor_updw_global_ctrl1_RBUS sync_processor_updw_global_ctrl1_reg;
	sync_processor_sp1_ctrl_RBUS  sync_processor_sp1_ctrl_reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sync_processor_sp1_autorst_RBUS sync_processor_sp1_autorst_reg;
	UINT32 SP1_Ctrl;
	unsigned char result;
	ADCGainOffset * ptADC_info = ((src==_SRC_YPBPR)? stYPbPrGainOffsetData: stVGAGainOffset);

	down(get_vsc_semaphore());
	drvif_mode_disableonlinemeasure(_CHANNEL1);/*Disable online measure*/
	drvif_mode_onlinemeasure_setting(_CHANNEL1, src, FALSE, FALSE);/*Disable online measure*/
#ifdef CONFIG_FORCE_RUN_I3DDMA
	drvif_mode_disable_dma_onlinemeasure(); //disable dma online measure
#endif
	up(get_vsc_semaphore());

	down(get_adc_detectsemaphore());
	if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
		ADC_set_detect_flag(FALSE);
	}
	up(get_adc_detectsemaphore());

	drvif_self_awb_initial_setting();

	adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
	ADC_BandWidth = adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0;
	adc_adc_dcrestore_ctrl_reg.regValue = 0;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
	adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

	YPbPr_ADCPowerControl(ON);

	//disable up/dn clamp for awb
	sync_processor_updw_global_ctrl1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL1_reg);
	sync_processor_updw_global_ctrl1_reg.updw_en_r = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_en_g = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_en_b = 0x0;
	sync_processor_updw_global_ctrl1_reg.updw_clamp_en = 0x0;
	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL1_reg, sync_processor_updw_global_ctrl1_reg.regValue);

	adc_adc_clamp_ctrl2_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL2_reg);
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_1_0 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_2 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_4_3 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_5 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_7_6 = 0;
	adc_adc_clamp_ctrl2_reg.adc_clamp_ctrl3_8 = 0;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, adc_adc_clamp_ctrl2_reg.regValue);

	//enable voltage clamp for awb
	adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 1;
	adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 1;
	IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

	EnableIPTGInSXGA();

	adc_adc_vbias_reg.regValue = IoReg_Read32(ADC_ADC_VBIAS_reg);
	adc_adc_vbias_reg.adc_vbias2_5 = 1; // clamp always enable
	adc_adc_vbias_reg.adc_vbias2_7 = 1;  // Calibration
    adc_adc_vbias_reg.adc_vbias2_4 = 1;  //Gain_Cal_DAC3B
	IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

	//enable Hysnc Type Detection Auto Run
	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	SP1_Ctrl = sync_processor_sp1_ctrl_reg.regValue ;
	sync_processor_sp1_ctrl_reg.s1_vhs_source_sel=1;
	sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
	//msleep(33);//frank@0507 hw setting 1ms from 20ms for Automatic reset
	sync_processor_sp1_ctrl_reg.s1_auto_run = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);
    //msleep(50);//frank@0507 hw setting 1ms from 20ms for Automatic reset

	count = 1000;
    do{//Wait (sync_processor_sp1_autorst_reg.s1_auto_result == 6). Can not remove
		sync_processor_sp1_autorst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_AutoRst_reg);
		if((sync_processor_sp1_autorst_reg.s1_auto_result == 6) || (count-- == 0)) break;
		msleep(5);
    }while(1);

	vgip_vgip_chn1_ctrl_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_vgip_chn1_ctrl_reg.ch1_in_sel = 1;
	IoReg_Write32(VGIP_VGIP_CHN1_CTRL_reg,vgip_vgip_chn1_ctrl_reg.regValue );

	ptADC_info->Offset_B = 0x200;
	ptADC_info->Offset_G = 0x200;
	ptADC_info->Offset_R = 0x200;

	auto_adcgainset(src, ptADC_info);
	//auto_adcoffsetset(src, ptADC_info);

	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;

	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset0_reg.adc_off_red = ptADC_info->Offset_R;
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);
	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset0_reg.adc_off_grn = ptADC_info->Offset_G;
	IoReg_Write32(ADC_ADC_OFFSET0_reg, adc_offset0_reg.regValue);

	adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	adc_offset1_reg.adc_off_blu = ptADC_info->Offset_B;
	IoReg_Write32(ADC_ADC_OFFSET1_reg, adc_offset1_reg.regValue);

	//check 0xb8020018[21] = 1
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]####0xb8020018 = 0x%08x ####\r\n",__FUNCTION__, __LINE__,IoReg_Read32(0xb8020018));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]####0xb802001c = 0x%08x ####\r\n",__FUNCTION__, __LINE__,IoReg_Read32(0xb802001c));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]####0xb8020020 = 0x%08x ####\r\n",__FUNCTION__, __LINE__,IoReg_Read32(0xb8020020));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Initial ADC Gain   = %d,%d,%d\n", __FUNCTION__, __LINE__, ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_B);
	result = drvif_self_awb_calculate_target_diff(src, SELECT_BLUE);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] result=%d\n", __FUNCTION__, __LINE__,result);
	if(result) result = drvif_self_awb_calculate_target_diff(src, SELECT_GREEN);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] result=%d\n", __FUNCTION__, __LINE__,result);
	if(result) result = drvif_self_awb_calculate_target_diff(src, SELECT_RED);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] result=%d\n", __FUNCTION__, __LINE__,result);

	//for restart detect, rzhen@2017-11-12
	if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC) {
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
		Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
	}

	if(result == FALSE)
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] fail error!\n", __FUNCTION__, __LINE__);
		goto PROCESS_ERROR;
	}
	else
	{
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;// connectPad, 5k
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue );
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff]Target Pr:%d Y:%d Pb:%d!\n\t", __FUNCTION__, __LINE__, g_ulAWBTargetDiff_R, g_ulAWBTargetDiff_G, g_ulAWBTargetDiff_B);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff]success!!!\n\t", __FUNCTION__, __LINE__);

		adc_adc_vbias_reg.adc_vbias2_2_0 = 3; // 0.9V
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);

		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

		/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial*/
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;/*G channel negative clamp enable on Y1N */
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 0;

		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);

		// oliver+,20131126
		//fwif_ADC_SaveSelfAWBResult();
		down(get_adc_detectsemaphore());
		if (get_ADC_Global_Status() == SRC_OPEN_DONE) {//Recover open status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
		}
		else if (get_ADC_Global_Status() == SRC_CONNECT_DONE) { //Recover connect status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
			ADC_Connect(src, (src==_SRC_YPBPR? _YPBPR_INPUT1: _VGA_INPUT1));
			ADC_set_detect_flag(TRUE);
		}
		up(get_adc_detectsemaphore());
		return TRUE;
	}
PROCESS_ERROR:
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BandWidth;// connectPad, 5k
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_5 = 0;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_7 = 1;

		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		adc_adc_vbias_reg.adc_vbias2_5 = 0; // clamp always enable
		adc_adc_vbias_reg.adc_vbias2_7 = 0;  // Calibration
   		adc_adc_vbias_reg.adc_vbias2_4 = 0;  //Gain_Cal_DAC3B
		IoReg_Write32(ADC_ADC_VBIAS_reg, adc_adc_vbias_reg.regValue);
		sync_processor_sp1_ctrl_reg.regValue = SP1_Ctrl ;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg,sync_processor_sp1_ctrl_reg.regValue);

		adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;//disable clamp on Vin012
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
		adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

		/* YPP negative clamp setting, clamp DAC source select,Vmid/Voffset initial*/
		adc_adc_clamp_ctrl0_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL0_reg);;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_0 = 0;/*G channel negative clamp enable on Y1N */
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_1 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_4_3 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_5 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_7_6 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_8 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_10_9 = 1;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl2_11 = 1;

		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_1_0 = 3;/*UPDN clamp disable*//*bit[1:0]=11  bit[4:3]=11 bit [7:6]=11*/
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_2 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_4_3 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_5 = 0;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_7_6 = 3;
		adc_adc_clamp_ctrl0_reg.adc_clamp_ctrl1_8 = 0;
		IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, adc_adc_clamp_ctrl0_reg.regValue);
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)][Get Target Diff] Fail ABORT\n", __FUNCTION__, __LINE__);
		down(get_adc_detectsemaphore());
		if (get_ADC_Global_Status() == SRC_OPEN_DONE) {//Recover open status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
		}
		else if (get_ADC_Global_Status() == SRC_CONNECT_DONE) { //Recover connect status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
			ADC_Connect(src, (src==_SRC_YPBPR? _YPBPR_INPUT1: _VGA_INPUT1));
			ADC_set_detect_flag(TRUE);
		}
		up(get_adc_detectsemaphore());

        return FALSE;
}


unsigned char External_ADC_Calibration_proc(int src)
{
	unsigned char usResult = TRUE;
	ADCGainOffset tempGainOffsetData;
#ifdef CALIBRATION_SHOW_COSTTIME
	unsigned int before_time=0;
	unsigned int after_time=0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] src=%d #####\n", __func__, __LINE__, src);

	if(src == _SRC_YPBPR)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
		memcpy(&tempGainOffsetData, stYPbPrGainOffsetData,sizeof(ADCGainOffset));
		ypbpr_auto_color_initial_setting();
		usResult = ypbpr_auto_color_gain_calibration(stYPbPrGainOffsetData,_Y75UV75);

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] usResult=%d\n", __FUNCTION__, __LINE__, usResult);

		if(get_adc_abl_function()==_DISABLE) YPbPr_ABL_SETTING_OFF();

		if(usResult)	//Auto Color is success
		{
#ifdef _RUN_GET_TARGET_AFTER_AUTOCOLOR
			drvif_self_awb_get_target_diff_proc(src);
#endif
		}
		else //Auto Color is fail
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] auto color failed!!!\n", __FUNCTION__, __LINE__);
			memcpy(stYPbPrGainOffsetData, &tempGainOffsetData, sizeof(ADCGainOffset));
		}

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Final YPP Gain_R=%d,Gain_G=%d,Gain_B=%d,Offset_R=%d,Offset_G=%d,Offset_B=%d#######\r\n", __FUNCTION__, __LINE__, stYPbPrGainOffsetData->Gain_R, stYPbPrGainOffsetData->Gain_G, stYPbPrGainOffsetData->Gain_B, stYPbPrGainOffsetData->Offset_R, stYPbPrGainOffsetData->Offset_G, stYPbPrGainOffsetData->Offset_B);

#ifdef CALIBRATION_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####func:%s code time=%d ms######\r\n",__FUNCTION__,(after_time-before_time));
#endif
	}
	else if(src == _SRC_VGA)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);

		memcpy(&tempGainOffsetData, stVGAGainOffset,sizeof(ADCGainOffset));

		usResult = drvif_adc_autobalance(SLR_MAIN_DISPLAY);

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]usResult=%d\n", __FUNCTION__, __LINE__, usResult);
		if(usResult == ERROR_SUCCEED)	//Auto Color is success
		{
			usResult = TRUE;
#ifdef _RUN_GET_TARGET_AFTER_AUTOCOLOR
			drvif_self_awb_get_target_diff_proc(src);
#endif
		}
		else //Auto Color is fail
		{
			usResult = FALSE;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] auto color failed!!!\n", __FUNCTION__, __LINE__);
			memcpy(stVGAGainOffset, &tempGainOffsetData, sizeof(ADCGainOffset));
		}
	}
	else if(src == _SRC_SCART_RGB)
	{

	}
	return usResult;

}

unsigned char Internal_ADC_Calibration_proc(int src)
{
	extern void ADC_set_detect_flag(unsigned char enable);
	extern struct semaphore* get_adc_detectsemaphore(void);
	extern struct semaphore* get_vsc_semaphore(void);
	unsigned char usResult = TRUE;
	ADCGainOffset tempGainOffsetData;
	StructDisplayInfo  *p_timing = NULL;
#ifdef CALIBRATION_SHOW_COSTTIME
	unsigned int before_time=0;
	unsigned int after_time=0;
	before_time = IoReg_Read32(0xB801B690)/90;
#endif
	ADCGainOffset * ptADC_info = ((src==_SRC_YPBPR)? stYPbPrGainOffsetData: stVGAGainOffset);

	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]\n", __FUNCTION__, __LINE__);
		memcpy(&tempGainOffsetData, ptADC_info, sizeof(ADCGainOffset));
		//if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC) {
			down(get_vsc_semaphore());
			drvif_mode_disableonlinemeasure(_CHANNEL1);/*Disable online measure*/
			drvif_mode_onlinemeasure_setting(_CHANNEL1, src, FALSE, FALSE);/*Disable online measure*/
		#ifdef CONFIG_FORCE_RUN_I3DDMA
			drvif_mode_disable_dma_onlinemeasure();	//disable dma online measure
		#endif
			Scaler_DispSetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE, _MODE_STATE_SEARCH);
			up(get_vsc_semaphore());
		//}
		down(get_adc_detectsemaphore());
		if (get_ADC_Global_Status() == SRC_CONNECT_DONE) {
			ADC_set_detect_flag(FALSE);
		}
		drvif_self_awb_initial_setting();
		//usResult = ypbpr_self_awb_gain_calibration(stYPbPrGainOffsetData);
		usResult = drvif_self_awb_gain_fast_calibration(src, ptADC_info);
		//if(usResult) usResult = ypbpr_self_awb_offset_calibration(stYPbPrGainOffsetData);//Offset need to check

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] usResult=%d\n", __FUNCTION__, __LINE__, usResult);

		if(usResult)	//Self AWB is success
		{

		}
		else //Auto Color is fail
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] auto color failed!!!\n", __FUNCTION__, __LINE__);
			memcpy(ptADC_info, &tempGainOffsetData, sizeof(ADCGainOffset));
		}

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Final Gain_R=%d Gain_G=%d Gain_B=%d Offset_R=%d Offset_G=%d Offset_B=%d\n", __FUNCTION__, __LINE__ , ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_B, ptADC_info->Offset_R, ptADC_info->Offset_G, ptADC_info->Offset_B);

#ifdef CALIBRATION_SHOW_COSTTIME
	after_time = IoReg_Read32(0xB801B690)/90;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####func:%s code time=%d ms######\r\n",__FUNCTION__,(after_time-before_time));
#endif
		if (get_ADC_Global_Status() == SRC_OPEN_DONE) {//Recover open status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
		}
		else if (get_ADC_Global_Status() == SRC_CONNECT_DONE) { //Recover connect status
			p_timing = Get_ADC_Dispinfo();
			p_timing->IPH_ACT_WID_PRE = 0;
			p_timing->IPV_ACT_LEN_PRE = 0;
			p_timing->IVFreq = 0;
			p_timing->IHFreq = 0;
			p_timing->IHTotal = 0;
			p_timing->IVTotal = 0;
			p_timing->ucMode_Table_Index = Mode_Table_Init_Index;
			ADC_Open();
			ADC_Connect(src, (src==_SRC_YPBPR? _YPBPR_INPUT1: _VGA_INPUT1));
			ADC_set_detect_flag(TRUE);
		}
		up(get_adc_detectsemaphore());
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] usResult=%d\n", __FUNCTION__, __LINE__, usResult);
	return usResult;
}


void Reset_ADC_Gain_Offset(void)
{
	//YPP
	stYPbPrGainOffsetData->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_R;
	stYPbPrGainOffsetData->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_G;
	stYPbPrGainOffsetData->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_B;
	stYPbPrGainOffsetData->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_R;
	stYPbPrGainOffsetData->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_G;
	stYPbPrGainOffsetData->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_B;

	//VGA
	stVGAGainOffset->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_R;
	stVGAGainOffset->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_G;
	stVGAGainOffset->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_B;
	stVGAGainOffset->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_R;
	stVGAGainOffset->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_G;
	stVGAGainOffset->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_B;

	//SCART RGB
	stScartRGBGainOffsetData->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_R;
	stScartRGBGainOffsetData->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_G;
	stScartRGBGainOffsetData->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_B;
	stScartRGBGainOffsetData->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_R;
	stScartRGBGainOffsetData->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_G;
	stScartRGBGainOffsetData->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_B;
}


void Get_ADC_Gain_Offset_From_OTP(int src, ADCGainOffset *pGainOffsetData)
{
	if(src == _SRC_YPBPR)
	{	//YPP
		pGainOffsetData->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_R;
		pGainOffsetData->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_G;
		pGainOffsetData->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Gain_B;
		pGainOffsetData->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_R;
		pGainOffsetData->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_G;
		pGainOffsetData->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_YPBPR].Offset_B;
	}
	else if(src == _SRC_VGA)
	{
		//VGA
		pGainOffsetData->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_R;
		pGainOffsetData->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_G;
		pGainOffsetData->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Gain_B;
		pGainOffsetData->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_R;
		pGainOffsetData->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_G;
		pGainOffsetData->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_VGA].Offset_B;
	}
	else if(src == _SRC_SCART_RGB)
	{
		//SCART RGB
		pGainOffsetData->Gain_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_R;
		pGainOffsetData->Gain_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_G;
		pGainOffsetData->Gain_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Gain_B;
		pGainOffsetData->Offset_R = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_R;
		pGainOffsetData->Offset_G = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_G;
		pGainOffsetData->Offset_B = ADC_GAIN_OFFSET_DATA_OTP[ADCTYPE_SCART_RGB].Offset_B;
	}
}


/***********The follow is for ADC OTP calculation*****************/
UINT16 CURRENT_DIFF[3] = {0, 0, 0};
UINT16 SAWB_GetTARGET[3][3] = {
	{KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR, KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y, KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB},//YPP target
	{_AUTO_SELF_SCARTRGB_LEVEL_TARGET_PR, _AUTO_SELF_SCARTRGB_LEVEL_TARGET_Y, _AUTO_SELF_SCARTRGB_LEVEL_TARGET_PB},//SCART target
	{_AUTO_SELF_VGA_LEVEL_TARGET_R,_AUTO_SELF_VGA_LEVEL_TARGET_G,_AUTO_SELF_VGA_LEVEL_TARGET_B}//VGA target
};

short FINAL_GAIN[3] = {0, 0, 0};

void OTP_ADC_CRT_CTRL(unsigned char enable)
{
	if(!enable)
		return;//Does not disable CRT
	CRT_CLK_OnOff(SCALER_AUTO_CLK_2, CLK_ON, NULL );
}


void OTP_Initial_Setting(void)
{
	IoReg_Mask32(DDS_PLL_PLL_CTRL_reg, 0xfff8DffE, _BIT18|_BIT16|_BIT13|_BIT0);	 //enable APLL LDO 1.1V power, 0xb8020104[18:16]=101(05), 0xb8020104[0]=1, power down , 0xb8020104[13]=1, RSTN_OFFMS for MAC3
	msleep(1);//Necessary
    IoReg_Write32(ADC_ADC_IBIAS0123_reg, 0x00004000);
    IoReg_Write32(ADC_ADC_CTL_RGB12_reg, 0x05400080);
    IoReg_Write32(ADC_ADC_VBIAS_reg, 0x01b3cca9);
    IoReg_Write32(ADC_ADC_CLOCK_reg, 0x00210003);
    IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, 0x00f00000);
    IoReg_Write32(ADC_ADC_CLAMP_CTRL0_reg, 0x092000db);
    IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, 0x00010124);
    IoReg_Write32(ADC_ADC_CLAMP_CTRL2_reg, 0x11200000);
    IoReg_Write32(ADC_ADC_CLAMP_CTRL3_reg, 0x00006000);
    IoReg_Write32(ADC_ADC_GAIN0_reg, 0x01800180);
    IoReg_Write32(ADC_ADC_GAIN1_reg, 0x00000180);
    IoReg_Write32(ADC_ADC_OFFSET0_reg, 0x02000200);
    IoReg_Write32(ADC_ADC_OFFSET1_reg, 0x00000200);
    IoReg_Write32(ADC_ADC_CTL_1_reg, 0x00d800d8);
    IoReg_Write32(ADC_ADC_CTL_2_reg, 0x000000d8);
    IoReg_Write32(ADC_ADC_POWER_reg, 0x000000ff);

    IoReg_Write32(DDS_PLL_PLL_SET_reg, 0x0302011e);	//M=33,N=3,K=0
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, 0x00050609);	// LDO 1.1V,dual clk
	IoReg_Write32(DDS_PLL_PLLDIV_reg, 0x00000898);	// Divider=858
	IoReg_Write32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg, 0x00430040);	// ADC clk=(1/2)*VCO clk
	IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_reg, 0x00000220);	// PLL phase interpolation control load
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, 0x000002a1);	// Delay chain select (Default value)
	IoReg_Write32(DDS_PLL_FAST_PLL_CTRL_reg, 0x00000040);	// enable double buffer load
	IoReg_Write32(DDS_PLL_PLL_CTRL_reg, 0x00050608);	// enable APLL & dual clk ,LDO
}


void OTP_Gain_Compensation(ADCGainOffset *ptADC_info, unsigned char adctype)
{
	if(ABS(SAWB_GetTARGET[adctype][0], CURRENT_DIFF[0]) > OTP_COMPENSATION_THRESHOLD) {
		if	(SAWB_GetTARGET[adctype][0] >= CURRENT_DIFF[0]) {
			ptADC_info->Gain_R = ptADC_info->Gain_R - (SAWB_GetTARGET[adctype][0] - CURRENT_DIFF[0]);
		} else {
			ptADC_info->Gain_R = ptADC_info->Gain_R + (CURRENT_DIFF[0] - SAWB_GetTARGET[adctype][0]);
		}
	}
	if(ABS(SAWB_GetTARGET[adctype][1], CURRENT_DIFF[1]) > OTP_COMPENSATION_THRESHOLD) {
		if	(SAWB_GetTARGET[adctype][1] >= CURRENT_DIFF[1]) {
			ptADC_info->Gain_G = ptADC_info->Gain_G - (SAWB_GetTARGET[adctype][1] - CURRENT_DIFF[1]);
		} else {
			ptADC_info->Gain_G = ptADC_info->Gain_G + (CURRENT_DIFF[1] - SAWB_GetTARGET[adctype][1]);
		}
	}
	if(ABS(SAWB_GetTARGET[adctype][2], CURRENT_DIFF[2]) > OTP_COMPENSATION_THRESHOLD) {
		if	(SAWB_GetTARGET[adctype][2] >= CURRENT_DIFF[2]) {
			ptADC_info->Gain_B = ptADC_info->Gain_B - (SAWB_GetTARGET[adctype][2] - CURRENT_DIFF[2]);
		} else {
			ptADC_info->Gain_B = ptADC_info->Gain_B + (CURRENT_DIFF[2] - SAWB_GetTARGET[adctype][2]);
		}
	}
}

// DAC level: 000:0.25V 001:0.4V 010:0.55V 011:0.7V 100:0.85V 101:1.0V 110:1.15V 111:1.3V
void Get_CodeDiff(unsigned char DacLevel1, unsigned char DacLevel2, unsigned short GainValueR, unsigned short GainValueG, unsigned short GainValueB, unsigned char gCalibrationSource)
{
	int ii;
	unsigned char Avg_count = 16;
	unsigned int ADC_CODE_A, ADC_CODE_B;
	unsigned short temp[6] = {0, 0, 0, 0, 0, 0}, new_temp[6] = {0, 0, 0, 0, 0, 0}, old_temp[6] = {0, 0, 0, 0, 0, 0};
	//printk(KERN_NOTICE "Get_CodeDiff\n");

	if(ADCTYPE_YPBPR == gCalibrationSource)
		IoReg_Mask32(ADC_ADC_VBIAS_reg, 0xffe00fff, _BIT23|_BIT21|_BIT20|_BIT15|_BIT14); //Enable Calib mode,SH gain=1.7
	else if(ADCTYPE_VGA == gCalibrationSource)
		IoReg_Mask32(ADC_ADC_VBIAS_reg, 0xffe00fff, _BIT23|_BIT21|_BIT20|_BIT15|_BIT14); //Enable Calib mode,SH gain=1.7
	else
		IoReg_Mask32(ADC_ADC_VBIAS_reg, 0xffe00fff, _BIT23|_BIT21|_BIT20|_BIT14); //Enable Calib mode,SH gain=1.0

	IoReg_Mask32(ADC_ADC_VBIAS_reg, 0xfff8ffff, (DacLevel1&0x7)<<16); //Enable Calib mode DAC=0.55V
	//msleep(5);

	IoReg_Write32(ADC_ADC_GAIN0_reg, (GainValueG<<16)|GainValueR); //set RG gain
	IoReg_Write32(ADC_ADC_GAIN1_reg, GainValueB); //set B gain
	msleep(1);

	for (ii = 0; ii < Avg_count + 1; ii++) {
		ADC_CODE_A = 0;
		ADC_CODE_B = 0;
		ADC_CODE_A = IoReg_Read32(ADC_ADC_RGB_DATA_reg);
		ADC_CODE_B = IoReg_Read32(ADC_ADC_RGB_DATA2_reg);
		new_temp[0] = (ADC_CODE_A>>18);
		new_temp[1] = ((ADC_CODE_A&0xfff)>>2);
		new_temp[2] = (ADC_CODE_B>>18);

		if (0 != ii) {
			if((20 < (ABS(new_temp[0],old_temp[0]))) || (20 < (ABS(new_temp[1], old_temp[1]))) || (20 < (ABS(new_temp[2], old_temp[2])))) {
				ii = ii-1;
				//printk(KERN_NOTICE "Get_CodeDiff error YPP_abs(new_temp[0],old_temp[0])=%d,YPP_abs(new_temp[1],old_temp[1])=%d,YPP_abs(new_temp[2],old_temp[2])=%d,%d\n",
					//(20 < (ABS(new_temp[0], old_temp[0]))), (20 < (ABS(new_temp[1], old_temp[1]))), (20 < (ABS(new_temp[2], old_temp[2]))),
					//(20 < ABS(new_temp[0], old_temp[0])) || (20 < ABS(new_temp[1], old_temp[1])) || (20 < ABS(new_temp[2], old_temp[2])));
				//printk(KERN_NOTICE "Get_CodeDiff error new_temp[0]=%d,old_temp[0]=%d,new_temp[1]=%d,old_temp[1]=%d,new_temp[2]=%d,old_temp[2]=%d \n",
					//new_temp[0], old_temp[0], new_temp[1], old_temp[1], new_temp[2], old_temp[2]);
			} else {
				temp[0] = new_temp[0] + temp[0];
				temp[1] = new_temp[1] + temp[1];
				temp[2] = new_temp[2] + temp[2];
			}
		}
		old_temp[0] = new_temp[0];
		old_temp[1] = new_temp[1];
		old_temp[2] = new_temp[2];

		//msleep(1);
	}
	temp[0]	= temp[0]>>4;
	temp[1]	= temp[1]>>4;
	temp[2]	= temp[2]>>4;

	IoReg_Mask32(ADC_ADC_VBIAS_reg, 0xfff8ffff, (DacLevel2&0x7)<<16); //Enable Calib mode DAC=0.55V
	msleep(1);
	for(ii = 0; ii < Avg_count + 1; ii++) {
		ADC_CODE_A = 0;
		ADC_CODE_B = 0;
		ADC_CODE_A = IoReg_Read32(ADC_ADC_RGB_DATA_reg);
		ADC_CODE_B = IoReg_Read32(ADC_ADC_RGB_DATA2_reg);

		new_temp[3] = (ADC_CODE_A>>18);
		new_temp[4] = ((ADC_CODE_A&0xfff)>>2);
		new_temp[5] = (ADC_CODE_B>>18);
		if (0 != ii) {
			if((20 < (ABS(new_temp[3], old_temp[3]))) || (20 < (ABS(new_temp[4], old_temp[4]))) || (20 < (ABS(new_temp[5], old_temp[5])))) {
				ii--;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Get_CodeDiff error new_temp[3]=%d,old_temp[3]=%d,new_temp[4]=%d,old_temp[4]=%d,new_temp[5]=%d,old_temp[5]=%d \n",
					new_temp[3], old_temp[3], new_temp[4], old_temp[4], new_temp[5], old_temp[5]);
			} else {
				temp[3] = new_temp[3] + temp[3];
				temp[4] = new_temp[4] + temp[4];
				temp[5] = new_temp[5] + temp[5];
			}
		}
		old_temp[3] = new_temp[3];
		old_temp[4] = new_temp[4];
		old_temp[5] = new_temp[5];
		//msleep(1);

	}
	temp[3]	= temp[3]>>4;
	temp[4]	= temp[4]>>4;
	temp[5]	= temp[5]>>4;

	for(ii = 0; ii < 3; ii++) {
		CURRENT_DIFF[ii] = temp[3+ii] > temp[0+ii] ? (temp[3+ii] - temp[0+ii]) : (temp[0+ii] - temp[3+ii]);
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "Currently, Gain=%d,%d,%d, code=%d,%d,%d,%d,%d,%d,%d,%d,%d\n", GainValueR, GainValueG, GainValueB,
		temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], CURRENT_DIFF[0], CURRENT_DIFF[1], CURRENT_DIFF[2]);

}

unsigned char OTP_ADC_Calibration(unsigned char adctype)
{
	// get current 0.55~0.85V code diff at gain =AWB_ADC_Gain_Slice[2]
	// DAC level: 000:0.25V 001:0.4V 010:0.55V 011:0.7V 100:0.85V 101:1.0V 110:1.15V 111:1.3V
	//Step1. Get the Codediff  at currently align point.
	//Step2. Caculate Gain drift at align point. a. Caculate the which gain will have the same codediff on org-table b. code drift = a.-align point
	//Step3. Caculate the Gain for GetTagertValue and the final Gain=
	enum PLAFTORM_TYPE platform = PLATFORM_KXL;
	unsigned char error = FALSE;
	ADCGainOffset *ptADC_info, *ptADC_info_otp;
	unsigned long long  A_Red, A_Green, A_Blue, B_Red, B_Green, B_Blue, Gain_Red, Gain_Green, Gain_Blue, Tempresult;

	if(adctype == ADCTYPE_YPBPR){
		platform = get_platform();//Get platform
		if(platform == PLATFORM_KXLP)
		{//set k2lp target
			SAWB_GetTARGET[0][0] = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			SAWB_GetTARGET[0][1] = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_Y;
			SAWB_GetTARGET[0][2] = KXLP_AUTO_SELF_YPP_LEVEL_TARGET_PB;
		}
		else
		{//set to k2l target
			SAWB_GetTARGET[0][0] = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PR;
			SAWB_GetTARGET[0][1] = KXL_AUTO_SELF_YPP_LEVEL_TARGET_Y;
			SAWB_GetTARGET[0][2] = KXL_AUTO_SELF_YPP_LEVEL_TARGET_PB;
		}

		ptADC_info = stYPbPrGainOffsetData;
	}else if(adctype == ADCTYPE_SCART_RGB){
		SAWB_GetTARGET[1][0] = _AUTO_SELF_SCARTRGB_LEVEL_TARGET_PR;
		SAWB_GetTARGET[1][1] = _AUTO_SELF_SCARTRGB_LEVEL_TARGET_Y;
		SAWB_GetTARGET[1][2] = _AUTO_SELF_SCARTRGB_LEVEL_TARGET_PB;

		ptADC_info = stScartRGBGainOffsetData;
	}else{//ADCTYPE_VGA
		SAWB_GetTARGET[2][0] = _AUTO_SELF_VGA_LEVEL_TARGET_R;
		SAWB_GetTARGET[2][1] = _AUTO_SELF_VGA_LEVEL_TARGET_G;
		SAWB_GetTARGET[2][2] = _AUTO_SELF_VGA_LEVEL_TARGET_B;

		ptADC_info = stVGAGainOffset;
	}

	ptADC_info_otp = &ADC_GAIN_OFFSET_DATA_OTP[adctype];//Point to ADC_GAIN_OFFSET_DATA_OTP
	OTP_Initial_Setting();
	msleep(1);

	//cal A
	Get_CodeDiff(2, 4, 0, 0, 0, adctype);
	A_Red = (unsigned long long) 2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[0];
	do_div(A_Red, Tempresult);

	A_Green = (unsigned long long) 2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[1];
	do_div(A_Green, Tempresult);

	A_Blue = (unsigned long long) 2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[2];
	do_div(A_Blue, Tempresult);

	//msleep(1);
	//cal B
	Get_CodeDiff(2, 4, 511, 511, 511, adctype);
	B_Red = (unsigned long long)2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[0];
	do_div(B_Red, Tempresult);
	B_Red = B_Red - A_Red;

	B_Green = (unsigned long long)2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[1];
	do_div(B_Green, Tempresult);
	B_Green = B_Green - A_Green;

	B_Blue = (unsigned long long)2560512000000;
	Tempresult = (unsigned long long)94*(unsigned long long)CURRENT_DIFF[2];
	do_div(B_Blue, Tempresult);
	B_Blue = B_Blue - A_Blue;

	Gain_Red = ((unsigned long long)2560512000000 - ((unsigned long long)94 * (unsigned long long)A_Red * (unsigned long long)SAWB_GetTARGET[adctype][0])) * (unsigned long long)511;
	//Tempresult = (unsigned long long)94 * (unsigned long long)B_Red * (unsigned long long)SAWB_GetTARGET[0][0];
	Tempresult = (unsigned long long)94 * (unsigned long long)SAWB_GetTARGET[adctype][0];
	do_div(Gain_Red,  Tempresult);
	do_div(Gain_Red,  B_Red);

	Gain_Green = ((unsigned long long)2560512000000 - ((unsigned long long)94 * (unsigned long long)A_Green * (unsigned long long)SAWB_GetTARGET[adctype][1])) * (unsigned long long)511;
	//Tempresult = (unsigned long long)94 * (unsigned long long)B_Green * (unsigned long long)SAWB_GetTARGET[0][1];
	Tempresult = (unsigned long long)94 * (unsigned long long)SAWB_GetTARGET[adctype][1];
	do_div(Gain_Green,  Tempresult);
	do_div(Gain_Green,  B_Green);

	Gain_Blue = ((unsigned long long)2560512000000 - ((unsigned long long)94 * (unsigned long long)A_Blue* (unsigned long long)SAWB_GetTARGET[adctype][2])) * (unsigned long long)511;
	//Tempresult = (unsigned long long)94 * (unsigned long long)B_Blue * (unsigned long long)SAWB_GetTARGET[0][2];
	Tempresult = (unsigned long long)94 * (unsigned long long)SAWB_GetTARGET[adctype][2];
	do_div(Gain_Blue,  Tempresult);
	do_div(Gain_Blue,  B_Blue);


	ptADC_info->Gain_R = (unsigned short)Gain_Red;
	ptADC_info->Gain_G = (unsigned short)Gain_Green;
	ptADC_info->Gain_B = (unsigned short)Gain_Blue;


    Get_CodeDiff(2, 4, ptADC_info->Gain_R, ptADC_info->Gain_G, ptADC_info->Gain_B, adctype);

	OTP_Gain_Compensation(ptADC_info, adctype);

	if (ptADC_info->Gain_R > 511 || ptADC_info->Gain_R < 2) {
		error = TRUE;
	} else if (ptADC_info->Gain_G > 511 || ptADC_info->Gain_G < 2) {
		error = TRUE;
	} else if (ptADC_info->Gain_B > 511 || ptADC_info->Gain_B < 2) {
		error = TRUE;
	}

	if (error) {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "###Calib Fail####\r\n");
		ptADC_info->Gain_R = ptADC_info_otp->Gain_R;
		ptADC_info->Gain_G = ptADC_info_otp->Gain_G;
		ptADC_info->Gain_B = ptADC_info_otp->Gain_B;
		return FALSE;
	} else {
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "###Calib Success####\r\n");
		ptADC_info_otp->Gain_R = ptADC_info->Gain_R;
		ptADC_info_otp->Gain_G = ptADC_info->Gain_G;
		ptADC_info_otp->Gain_B = ptADC_info->Gain_B;
		return TRUE;
	}
}

void OTP_ADC_Calibration_proc(void)
{//OTP Calibration
	OTP_ADC_CRT_CTRL(TRUE);
	OTP_ADC_Calibration(ADCTYPE_YPBPR);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "########Final YPP Gain R:%d G:%d B:%d##########\r\n", stYPbPrGainOffsetData->Gain_R, stYPbPrGainOffsetData->Gain_G, stYPbPrGainOffsetData->Gain_B);
	OTP_ADC_Calibration(ADCTYPE_VGA);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "########Final VGA Gain R:%d G:%d B:%d##########\r\n", stVGAGainOffset->Gain_R, stVGAGainOffset->Gain_G, stVGAGainOffset->Gain_B);
	ADC_Disable_AHS_SMT_Power();//Disable AHS_SMT_Power
	drvif_adc_power_control (ADC_POWER_ALL_DISABLE_CONTROL);//Disable ADC power
}

 static unsigned char auto_adcgainoffsetadjust(unsigned char color, unsigned short delta,
	 unsigned char inc, unsigned char saturate, unsigned short* Gain_Offset)
 {
	 unsigned short usTemp;
 
	 usTemp = inc ? (0x1ff - *Gain_Offset):*Gain_Offset;
 
	 if (inc) {
		 if (usTemp > delta)
			 *Gain_Offset += delta;
		 else {
			 *Gain_Offset = 0x1ff;
			 saturate |= color;
		 }
	 } else {
		 if (usTemp > delta)
			 *Gain_Offset -= delta;
		 else {
			 *Gain_Offset = 0;
			 saturate |= color;
		 }
	 }
	 return saturate;
 
 }

 static unsigned char auto_adcgainchange(unsigned char display, unsigned char color, unsigned short delta,
	unsigned char inc)
{

	ADCGainOffset *ptADCGainOffset = NULL;
	unsigned char ucTemp = 0;

	ptADCGainOffset = stVGAGainOffset;

	if (color & SELECT_RED) {//forster modified 050728
		ucTemp = auto_adcgainoffsetadjust(SELECT_RED, delta, inc, ucTemp, (unsigned short *)&ptADCGainOffset->Gain_R);  //forster modified 050905
	}

	if (color & SELECT_GREEN) {//forster modified 050728
		ucTemp |= auto_adcgainoffsetadjust(SELECT_GREEN, delta, inc, ucTemp, (unsigned short*)&ptADCGainOffset->Gain_G);   //forster modified 050905
	}

	if (color & SELECT_BLUE) {//forster modified 050728
		ucTemp |= auto_adcgainoffsetadjust(SELECT_BLUE, delta, inc, ucTemp,	(unsigned short*)&ptADCGainOffset->Gain_B);  //forster modified 050905
	}

	auto_adcgainset(_SRC_VGA, ptADCGainOffset);

	return ucTemp;
}

static unsigned char auto_adcoffsetchange(unsigned char display, unsigned char color, unsigned short delta,
	unsigned char inc)
{

    ADCGainOffset *ptADCGainOffset = NULL;
	unsigned char ucTemp = 0;

	ptADCGainOffset = stVGAGainOffset;

	if (color & SELECT_RED) {//forster modified 050728
		ucTemp = auto_adcgainoffsetadjust(SELECT_RED, delta, inc, ucTemp,  (unsigned short *)&ptADCGainOffset->Offset_R);//forster modified 050905
	}

	if (color & SELECT_GREEN) {//forster modified 050728
		ucTemp |= auto_adcgainoffsetadjust(SELECT_GREEN, delta, inc, ucTemp, (unsigned short *)&ptADCGainOffset->Offset_G);//forster modified 050905
	}

	if (color & SELECT_BLUE) {//forster modified 050728
		ucTemp |= auto_adcgainoffsetadjust(SELECT_BLUE, delta, inc, ucTemp,	(unsigned short *)&ptADCGainOffset->Offset_B);//forster modified 050905
	}

	auto_adcoffsetset(_SRC_VGA, ptADCGainOffset);

	return ucTemp;

}

unsigned char drvif_auto_measurecolor(unsigned char display, unsigned char color, unsigned char margin, unsigned short* rev)
{
	adc_smartfit_adc_auto_r_g_b_margin_RBUS auto_r_g_b_margin_reg;
	adc_smartfit_adc_auto_adj_RBUS auto_adj_reg;
	adc_smartfit_adc_auto_field_RBUS smartfit_auto_field_reg;

	StructDisplayInfo *p_dispinfo = NULL;

	p_dispinfo = Get_ADC_Dispinfo();
	if(!p_dispinfo) return;

	auto_r_g_b_margin_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg);

	if(SELECT_RED == color)
		auto_r_g_b_margin_reg.color_sel = _COLORS_RED;
	else if(SELECT_GREEN == color)
		auto_r_g_b_margin_reg.color_sel = _COLORS_GREEN;
	else// if(SELECT_BLUE== color)
		auto_r_g_b_margin_reg.color_sel = _COLORS_BLUE;

	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_R_G_B_MARGIN_reg, auto_r_g_b_margin_reg.regValue);

#ifdef AUTO_COLOR_MEASURE_CENTER_ONLY
	unsigned short Active_Region[4];
	unsigned short HStart,HEnd,VStart,VEnd;
	drvif_color_activeregion_dragon(0, &Active_Region[0]);
	/*
	printf("Active_Region[0]=%d\n",Active_Region[0]);
	printf("Active_Region[1]=%d\n",Active_Region[1]);
	printf("Active_Region[2]=%d\n",Active_Region[2]);
	printf("Active_Region[3]=%d\n",Active_Region[3]);
	printf("Active_Region=%d,%d,%d,%d\n\n",Active_Region[0],Active_Region[0]+Active_Region[1],Active_Region[2],Active_Region[2]+Active_Region[3]);
	*/

	HStart=Active_Region[0]+Active_Region[1]/2-AUTO_COLOR_RANGE;
	HEnd=  Active_Region[0]+Active_Region[1]/2+AUTO_COLOR_RANGE;
	VStart=Active_Region[2]+Active_Region[3]/2-AUTO_COLOR_RANGE;
	VEnd=  Active_Region[2]+Active_Region[3]/2+AUTO_COLOR_RANGE;
	/*
	printf("HStart=%4d=0x%3x\n",HStart,HStart);
	printf("HEnd  =%4d=0x%3x\n",HEnd,HEnd);
	printf("VStart=%4d=0x%3x\n",VStart,VStart);
	printf("VEnd=  %4d=0x%3x\n",VEnd,VEnd);
	*/

	stAUTO_PARA.usAutoHStart = HStart;
	stAUTO_PARA.usAutoHEnd = HEnd;
	if(margin == _COLOR_MIN)
	{
	      stAUTO_PARA.usAutoVStart = 9;
	      stAUTO_PARA.usAutoVEnd = stAUTO_PARA.usAutoVStart + 4;
	}
	else
	{
	      stAUTO_PARA.usAutoVStart = VStart;
	      stAUTO_PARA.usAutoVEnd = VEnd;
	}
#else
#if 1//rzhen@2018-01-02
	stAUTO_PARA.usAutoHStart = p_dispinfo->IPH_ACT_STA;
	stAUTO_PARA.usAutoHEnd = p_dispinfo->IPH_ACT_STA + p_dispinfo->IPH_ACT_WID;

	if(margin == _COLOR_MIN){
		stAUTO_PARA.usAutoVStart = FIX_VGIP_V_START;
		stAUTO_PARA.usAutoVEnd = stAUTO_PARA.usAutoVStart + 4;
	}else{
		stAUTO_PARA.usAutoVStart = p_dispinfo->IPV_ACT_STA;
		stAUTO_PARA.usAutoVEnd = p_dispinfo->IPV_ACT_STA + p_dispinfo->IPV_ACT_STA;
	}
#else
	stAUTO_PARA.usAutoHStart = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA) + Scaler_DispGetIhsDelay();
	stAUTO_PARA.usAutoHEnd = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA) + Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID);

	if(margin == _COLOR_MIN)
	{
	      stAUTO_PARA.usAutoVStart = 9;
	      stAUTO_PARA.usAutoVEnd = stAUTO_PARA.usAutoVStart + 4;
	}
	else
	{
	      stAUTO_PARA.usAutoVStart = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA) + Scaler_DispGetIvs2DvsDelay();
	      stAUTO_PARA.usAutoVEnd = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA) + Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN);
	}
#endif	
#endif

	stAUTO_PARA.ucFieldControl = 0;

	if( Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))
	   	stAUTO_PARA.ucFieldControl |= 0x20;

	drvif_set_adc_smartfit_boundary();

	smartfit_auto_field_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg);
	smartfit_auto_field_reg.auto_balance_rgb = 2;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_FIELD_reg,smartfit_auto_field_reg.regValue);

	auto_adj_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg);
	auto_adj_reg.m_vgen_en = 0;
	auto_adj_reg.diff_pixel_sel = 1;
#if 1 //fixme force_flip remove
	if (_COLOR_MIN == margin)
		auto_adj_reg.force_flip_ = 0;
	else// if (_COLOR_MAX == margin)
		auto_adj_reg.force_flip_ = 1;
#endif	
	auto_adj_reg.sum_max = 0;
	auto_adj_reg.pulse_det_en = 0;
	auto_adj_reg.autophase_sel_tri = 0;
	auto_adj_reg.diff_en = 0;
	auto_adj_reg.now_af = 1;
	IoReg_Write32(ADC_SMARTFIT_ADC_AUTO_ADJ_reg, auto_adj_reg.regValue);

	if(drvif_adc_smartfit_waitfinish(display))
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]Measure Error Abort!!!\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	*rev = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_RESULT_PHASE_L_reg) & 0x03ff;

	if (_COLOR_MIN == margin)
		*rev ^= 0x3ff;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Measure Color=0x%08x, Margin=0x%08x\n", __FUNCTION__, __LINE__,color,*rev);
	return ERROR_SUCCEED;
}



//--------------------------------------------------
// Description  : Adjust ADC gain
// Input Value  : Adjusting setting
// Output Value : Measure status
//--------------------------------------------------
unsigned char drvif_auto_tunedevicegain(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMax_Target)
{
	unsigned short temp;

	if(drvif_auto_measurecolor(display, ucColor, _COLOR_MAX, pMargin) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]Error ABORT!!!\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	if(*pMargin < VGA_AWB_CHECK_LEVEL)
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]*pMargin < VGA_AWB_CHECK_LEVEL\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

    if(ABS(*pMargin, ucMax_Target) < 2)
    {
    	return ERROR_SUCCEED;//Don't need to change gain
    }

	if(*pMargin > ucMax_Target){
    	temp  = *pMargin - ucMax_Target;
		if(auto_adcgainchange(display, ucColor, temp, 1))                  // Increase Gain; Decrease Contrast
		{
			// oliver-
			//if(auto_adcoffsetchange(display, ucColor, (( Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VDC) ? 8 : 16), 0))               // Increase Offset; Decrease Brightness
			//	return ERROR_FINISH;
		}
	}else if(*pMargin < ucMax_Target){
		temp  = ucMax_Target - *pMargin;
		// Non-zero return value of auto_adcgainchange() means ADC gain reaches minimum.
		if(auto_adcgainchange(display, ucColor, temp, 0))                  // Decrease Gain; Increase Contrast
		{
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
unsigned char drvif_auto_tunedeviceoffset(unsigned char display, unsigned char ucColor, unsigned short *pMargin, unsigned short ucMin_Target)
{
	unsigned short temp;

	if(drvif_auto_measurecolor(display, ucColor, _COLOR_MIN, pMargin) != ERROR_SUCCEED)
	{
		rtd_printk(KERN_EMERG, TAG_NAME_ADC, "#####[%s(%d)]Error ABORT!!!\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}

	if(*pMargin > ucMin_Target){

		temp = *pMargin - ucMin_Target;
		rtd_printk(KERN_EMERG, TAG_NAME_ADC, "#####[%s(%d)]Decrease Color= %x, Offset0 BIOS = %x pMargin=%x  mintarget=%x!\n", __FUNCTION__, __LINE__,ucColor, temp,*pMargin,ucMin_Target);
		auto_adcoffsetchange(display, ucColor, ((temp > 32) ? 32 : temp), 0);

	}else if(*pMargin < ucMin_Target){

		temp = ucMin_Target - *pMargin;
		rtd_printk(KERN_EMERG, TAG_NAME_ADC, "#####[%s(%d)]Increase Color= %x, Offset1 BIOS = %x pMargin=%x mintarget=%x!\n", __FUNCTION__, __LINE__,ucColor, temp,*pMargin, ucMin_Target);

		if(*pMargin == 0)
	     	auto_adcoffsetchange(display, ucColor, temp + 16, 1);       // Increase Offset; Increase Brightness //Change_Device_Offset(ucColor, temp + 4, 1);       // Increase Offset; Increase Brightness
		else
	      auto_adcoffsetchange(display, ucColor, temp, 1);           // Increase Offset; Increase Brightness
	}

    return ERROR_SUCCEED;
}


//Gain => SW adjust, Offset => ABL adjust
unsigned char drvif_adc_autobalance_fast(unsigned char display)
{
	unsigned short rev, result0, color, count;
	unsigned short usMax_Value, usMin_Value;
	ADCGainOffset *ptADCGainOffset = NULL;
	adc_adc_gain0_RBUS adc_gain0_reg;
	adc_adc_gain1_RBUS adc_gain1_reg;
	adc_adc_offset0_RBUS adc_offset0_reg;
	adc_adc_offset1_RBUS adc_offset1_reg;
	UINT16 drvif_AutoColor_tunedevicegain_count;

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "[AutoColor] VGA Auto color progressing! fast\n\n");

	ptADCGainOffset = stVGAGainOffset;

	ptADCGainOffset->Gain_B = 0xff;
	ptADCGainOffset->Gain_G = 0xff;
	ptADCGainOffset->Gain_R = 0xff;

	adc_gain0_reg.regValue = IoReg_Read32(ADC_ADC_GAIN0_reg);
	adc_gain0_reg.adc_gain_grn = 0xff;
	adc_gain0_reg.adc_gain_red = 0xff;
	IoReg_Write32(ADC_ADC_GAIN0_reg, adc_gain0_reg.regValue);

	adc_gain1_reg.regValue = IoReg_Read32(ADC_ADC_GAIN1_reg);
	adc_gain1_reg.adc_gain_blu = 0xff;
	IoReg_Write32(ADC_ADC_GAIN1_reg, adc_gain1_reg.regValue);

#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	if(Scaler_InputSrcGetFrom(display) == _SRC_FROM_VDC)
		color =SELECT_GREEN;			  //we don't measure the blue color in VIDEO8 auto color
	else
		color = SELECT_BLUE;
#else //#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	color = SELECT_BLUE;
#endif //#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)

	Scaler_PrintADCGainInRegister();

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor] Blue measure start!\n", __FUNCTION__, __LINE__);
	drvif_AutoColor_tunedevicegain_count=0;

	while(TRUE){

		count = 0x80;
		drvif_auto_gettargetvalue(display, &usMax_Value, &usMin_Value, color);

		auto_AdcGainAdjustReset();

		do{

			drvif_AutoColor_tunedevicegain_count++;
			if(color == SELECT_BLUE)			// 2 : Blue or PB
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor] AutoColor_Tune VGA Blu %2d\n", __FUNCTION__, __LINE__, drvif_AutoColor_tunedevicegain_count);
			else if(color == SELECT_GREEN)		// 1: Green or Y
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor] AutoColor_Tune VGA Grn %2d\n", __FUNCTION__, __LINE__, drvif_AutoColor_tunedevicegain_count);
			else								// 0: Red or PR
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor] AutoColor_Tune VGA Red %2d\n", __FUNCTION__, __LINE__, drvif_AutoColor_tunedevicegain_count);

			rev = drvif_auto_tunedevicegain(display, color, &result0, usMax_Value);

			if(rev == ERROR_ABORT)
				return rev;
			if(rev == ERROR_FINISH)
				break;

			if(ABS(result0, usMax_Value) < 2){

				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]AutoColor OK for VGA color=%d, Result = %4d, Target=%4d count=%d\n", __FUNCTION__, __LINE__,color,result0,usMax_Value,drvif_AutoColor_tunedevicegain_count);
				break;
			}

			if((count > 8) && (ABS(result0, usMax_Value) <= 4)){

				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]result0=0x%08x, usMax_Value=0x%08x\n", __FUNCTION__, __LINE__, result0, usMax_Value);
				count = 8;
			}

			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Result=%4d Target=%4d Diff=%4d =>\n", __FUNCTION__, __LINE__,result0,usMax_Value,result0-usMax_Value);

			if(color == SELECT_BLUE){			// 4: Blue

				if((result0-usMax_Value)<0)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Decrease gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_B);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Increase gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_B);
			}else if(color == SELECT_GREEN){	// 2: Green

				if((result0-usMax_Value)<0)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Decrease gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_G);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Increase gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_G);
			}else{								// 1: Red

				if((result0-usMax_Value)<0)
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Decrease gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_R);
				else
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Increase gain => gain_new=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_R);
			}
		}while(--count);
		
		if(0 == count){

			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]QUIT for VGA color=%d, Result = %4d, Target=%4d Diff=%d\n", __FUNCTION__, __LINE__,color,result0,usMax_Value,result0-usMax_Value);
		}
		
		if(color == SELECT_BLUE){				// 4: Blue

			color = SELECT_GREEN;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Grn measure start!\n", __FUNCTION__, __LINE__);
			drvif_AutoColor_tunedevicegain_count=0;
		}else if(color == SELECT_GREEN){		// 2: Green

			color = SELECT_RED;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Red measure start!\n", __FUNCTION__, __LINE__);
			drvif_AutoColor_tunedevicegain_count=0;
		}else{									// 1: Red								

			break;
		}
	}

	adc_offset0_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET0_reg);
	adc_offset1_reg.regValue = IoReg_Read32(ADC_ADC_OFFSET1_reg);
	ptADCGainOffset->Offset_R = adc_offset0_reg.adc_off_red;
	ptADCGainOffset->Offset_G = adc_offset0_reg.adc_off_grn;
	ptADCGainOffset->Offset_B = adc_offset1_reg.adc_off_blu;

	if((ptADCGainOffset->Gain_R == 0x00) || (ptADCGainOffset->Gain_G == 0x00) || (ptADCGainOffset->Gain_B == 0x00))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]VGA Auto color fail!\n", __FUNCTION__, __LINE__);
		return ERROR_ABORT;
	}else{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Success: gainR=%d, gainG=%d, gainB=%d\n", __FUNCTION__, __LINE__,ptADCGainOffset->Gain_R,ptADCGainOffset->Gain_G,ptADCGainOffset->Gain_B);
		return ERROR_SUCCEED;
	}
}

//Gain => SW adjust, Offset => SW adjust
unsigned char drvif_adc_autobalance_standard(unsigned char display)
{
	unsigned short rev = 0, result0 = 0, result1 = 0, color = 0, count = 0;
	unsigned short usMax_Value = 0, usMin_Value = 0;
	ADCGainOffset *ptADCGainOffset = NULL;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor] Auto color progressing standard\n", __FUNCTION__, __LINE__);
	//VGA_ABL_Enable_Control(_DISABLE);

	ptADCGainOffset = stVGAGainOffset;
	
	ptADCGainOffset->Gain_B = 0xff;
	ptADCGainOffset->Gain_G = 0xff;
	ptADCGainOffset->Gain_R = 0xff;
	ptADCGainOffset->Offset_B = 0x1ff;
	ptADCGainOffset->Offset_G = 0x1ff;
	ptADCGainOffset->Offset_R = 0x1ff;

	auto_adcgainset(_SRC_VGA, ptADCGainOffset);
	auto_adcoffsetset(_SRC_VGA, ptADCGainOffset);

	if (drvif_auto_measurecolor(display, SELECT_GREEN, _COLOR_MAX, &rev) != ERROR_SUCCEED)
		goto PROCESS_ERROR;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]VGA_AWB_CHECK_LEVEL=0x%08x\n", __FUNCTION__, __LINE__, VGA_AWB_CHECK_LEVEL);

	if (rev < VGA_AWB_CHECK_LEVEL){

		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]ERROR_ABORT rev < 0x180 !!!\n", __FUNCTION__, __LINE__);
		goto PROCESS_ERROR;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Grn check ok !!!\n", __FUNCTION__, __LINE__);

    if (drvif_auto_measurecolor(display, SELECT_BLUE, _COLOR_MAX, &rev) != ERROR_SUCCEED)
		goto PROCESS_ERROR;

    if (rev < VGA_AWB_CHECK_LEVEL)
		goto PROCESS_ERROR;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Blu check ok !!!\n", __FUNCTION__, __LINE__);

    if (drvif_auto_measurecolor(display, SELECT_RED, _COLOR_MAX, &rev) != ERROR_SUCCEED)
		goto PROCESS_ERROR;

    if (rev < VGA_AWB_CHECK_LEVEL)
		goto PROCESS_ERROR;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Red check ok !!!\n", __FUNCTION__, __LINE__);

#if(_VIDEO_AUTO_WHITE_BLANCE == _ENABLE)
	if (Scaler_InputSrcGetFrom((SCALER_DISP_CHANNEL)display) == _SRC_FROM_VDC)
		color =SELECT_GREEN;// _GREEN;			  //we don't measure the blue color in VIDEO8 auto color
	else
		color = SELECT_BLUE;//_BLUE;
#else
	color = SELECT_BLUE;
#endif

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Blu measure start !!!\n", __FUNCTION__, __LINE__);

	while (TRUE){

		count = 0x30;
		//drvif_auto_gettargetvalue(display, &usMax_Value, &usMin_Value, color);
		usMax_Value = _AUTO_VGA_MAX_LEVEL;
		usMin_Value = _AUTO_VGA_MIN_LEVEL;

		do{

			rev = drvif_auto_tunedevicegain(display, color, &result0, usMax_Value);

			if(rev == ERROR_ABORT)
				goto PROCESS_ERROR;
			if(rev == ERROR_FINISH)
				break;

			rev = drvif_auto_tunedeviceoffset(display, color, &result1, usMin_Value);

			if ((ABS(result0, usMax_Value) < 2) && (ABS(result1, usMin_Value) < 2))
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]result0:%x, usMax_Value:%x\n", __FUNCTION__, __LINE__, result0, usMax_Value);
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]result1:%x, usMin_Value:%x\n", __FUNCTION__, __LINE__, result1, usMin_Value);
				break;
			}

			if ((count > 8) && (ABS(result0, usMax_Value) <= 4) && (ABS(result1, usMin_Value))) {
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]result0:%x, usMax_Value:%x\n", __FUNCTION__, __LINE__, result0, usMax_Value);
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]result1:%x, usMin_Value:%x\n", __FUNCTION__, __LINE__, result1, usMin_Value);
				count = 8;
			}

		} while(--count);

		if (color == SELECT_BLUE){				// 4: Blue
			color = SELECT_GREEN;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Grn measure start !!!\n", __FUNCTION__, __LINE__);
		}else if (color == SELECT_GREEN){		// 2: Green
			color = SELECT_RED;//_RED;
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Red measure start !!!\n", __FUNCTION__, __LINE__);
		}else{ 									// 1: Red
			break;
		}
	}


//	VGA_ABL_Enable_Control(_ENABLE);

	if((ptADCGainOffset->Gain_R == 0x00) || (ptADCGainOffset->Gain_G== 0x00) || (ptADCGainOffset->Gain_B == 0x00))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]VGA Auto color fail !!!\n", __FUNCTION__, __LINE__);
		goto PROCESS_ERROR;
	}else{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][AutoColor]Success: gainR=%d, gainG=%d, gainB=%d !!!\n", __FUNCTION__, __LINE__, ptADCGainOffset->Gain_R,ptADCGainOffset->Gain_G,ptADCGainOffset->Gain_B);
	}

	return ERROR_SUCCEED;

PROCESS_ERROR:
	return ERROR_ABORT;

}


/**
* drvif_adc_autobalance
* This function will Tune ADC gain and offset and do auto balance
* @param <display>       { 0:MAIN_DISPLAY;1:SUB_DISPLAY}
* @return <result>  	 { 0:ERROR_SUCCEED;not 0:FAIL}
*/
unsigned char drvif_adc_autobalance(unsigned char display)
{
	abl_abl_ctrl_RBUS abl_ctrl_reg;
	unsigned char result;

	abl_ctrl_reg.regValue = IoReg_Read32(ABL_ABL_CTRL_reg);	//mag

	if(_ENABLE == abl_ctrl_reg.abl_en)
	{
		//if VGA ABL enable, only need adjust gain value
		result = drvif_adc_autobalance_fast(display);
	}else{
		result = drvif_adc_autobalance_standard(display);
	}

	return result;
}

#if 0//This is for test. Not remove
#define ALIGNPOINT 4
#define GAINSLICE 3
#define CODESLICE 9
UINT16 ADC_Calib[3][9] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0},  //R
	{0, 0, 0, 0, 0, 0, 0, 0, 0},  //G
	{0, 0, 0, 0, 0, 0, 0, 0, 0}   //B
};

UINT16 AWB_ADC_Gain_Slice[2][9] = {
	{0x1, 0x20, 0x40, 0x80, 0xC0, 0x100, 0x160, 0x1C0, 0x1ff},//YPP 9 slice gain at  1,32,64,128,196,256,352,448,511 point
	{0x1, 0x20, 0x40, 0x80, 0xC0, 0x100, 0x160, 0x1C0, 0x1ff} //SCART 9 slice gain at  1,32,64,128,196,256,352,448,511 point
};

void Interpolate_GainValue(unsigned short iCode, unsigned char iADCSelect, short  *iNewGain, unsigned char iCalibrationSource )
{
	unsigned char interpolate_zone, i1, i2;
	unsigned short temp1, temp2;
	unsigned short ratio_tempR, ratio_tempG, ratio_tempB;
	unsigned int ratio_temp1;

	ratio_tempR = ADC_Calib[0][ALIGNPOINT];
	ratio_tempG = ADC_Calib[1][ALIGNPOINT];
	ratio_tempB = ADC_Calib[2][ALIGNPOINT];
	ratio_temp1 = CURRENT_DIFF[0] + (CURRENT_DIFF[1]<<1) + CURRENT_DIFF[2];
	//ratio = (( CURRENT_DIFF[0]/ratio_tempR) + 2*( CURRENT_DIFF[1]/ratio_tempG) + ( CURRENT_DIFF[2]/ratio_tempB))/4
	printk(KERN_NOTICE "Interpolate_GainValue ratio=%d \n", ratio_temp1);

	for(i1 = 0; i1< GAINSLICE; i1++) {
		for (i2 = 0; i2 < CODESLICE; i2++){
			ADC_Calib[i1][i2] = (ADC_Calib[i1][i2]*ratio_temp1)/(ratio_tempR + (ratio_tempG<<1) + ratio_tempB);
			//printk(KERN_NOTICE "Interpolate_GainValue new ADC_Calib[%d][%d]=%d \n", i1, i2, ADC_Calib[i1][i2]);
		}
	}
	interpolate_zone = iCode > ADC_Calib[iADCSelect][0] ? 0 : (iCode > ADC_Calib[iADCSelect][1] ? 1 :
		(iCode > ADC_Calib[iADCSelect][2] ? 2 : (iCode > ADC_Calib[iADCSelect][3] ? 3 : (iCode>ADC_Calib[iADCSelect][4] ? 4 :
		(iCode > ADC_Calib[iADCSelect][5] ? 5 : (iCode > ADC_Calib[iADCSelect][6] ? 6 : (iCode > ADC_Calib[iADCSelect][7] ? 7 :
		(iCode > ADC_Calib[iADCSelect][8] ? 8 : 9))))))));
	switch (interpolate_zone) {
	case 0:
		temp1 = ADC_Calib[iADCSelect][interpolate_zone] - ADC_Calib[iADCSelect][interpolate_zone+1];
		temp2 = ABS(AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone], AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone+1]);
		*iNewGain = AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone] - (iCode - ADC_Calib[iADCSelect][interpolate_zone]) * temp2 / temp1;
		break;
	case 9:
		temp1 = ADC_Calib[iADCSelect][interpolate_zone-2] - ADC_Calib[iADCSelect][interpolate_zone-1];
		temp2 = ABS(AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone-2], AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone-1]);
		*iNewGain = AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone-1] + (ADC_Calib[iADCSelect][interpolate_zone-1] - iCode) * temp2 / temp1;
		break;
	default:
		temp1 = ADC_Calib[iADCSelect][interpolate_zone-1] - ADC_Calib[iADCSelect][interpolate_zone];
		temp2 = ABS(AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone-1], AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone]);
		*iNewGain = AWB_ADC_Gain_Slice[iCalibrationSource][interpolate_zone] - (iCode - ADC_Calib[iADCSelect][interpolate_zone]) * temp2 / temp1;
		break;
	}
	printk(KERN_NOTICE "Interpolate_GainValue interpolate_zone=%d,iNewGain=%d\n", interpolate_zone, *iNewGain);
}

void Build_Self_AWB_ADC_Curve(unsigned char bCalibrationSource)
{
	int count, i, ii;
	printk(KERN_NOTICE "Build_Self_AWB_ADC_Curve source=%d\n", bCalibrationSource);
	OTP_Initial_Setting();
	if(0 == bCalibrationSource)
		IoReg_Mask32(ADC_ADC_VBIAS_reg,0xffe00fff, _BIT23|_BIT21|_BIT20|_BIT15); //Enable Calib mode,SH gain=1.7
	else
		IoReg_Mask32(ADC_ADC_VBIAS_reg,0xffe00fff, _BIT23|_BIT21|_BIT20); //Enable Calib mode,SH gain=1.0

	IoReg_Mask32(ADC_ADC_DCRESTORE_CTRL_reg, 0xffd0fe00, _BIT21); //Enable Calib mode OFFPAD,LPF=10M
	IoReg_Mask32(ADC_ADC_CLAMP_CTRL1_reg, 0xfffffe00, _BIT8|_BIT6|_BIT5|_BIT3|_BIT2|_BIT0); //VClamping postive Enable
	IoReg_Mask32(ADC_ADC_CLAMP_CTRL0_reg, 0xf000fe00, _BIT27|_BIT25|_BIT24|_BIT22|_BIT21|_BIT19|_BIT7|_BIT6|_BIT4|_BIT3|_BIT1|_BIT0); //VClamping postive Enable

	count = CODESLICE;
	//printk(KERN_NOTICE "Build_Self_AWB_ADC_Curve count=%d\n",count);
	for(i = 0; i < count; i++) {
		Get_CodeDiff(2, 4, AWB_ADC_Gain_Slice[bCalibrationSource][i], AWB_ADC_Gain_Slice[bCalibrationSource][i],
				AWB_ADC_Gain_Slice[bCalibrationSource][i], bCalibrationSource);
		for(ii = 0; ii < 3; ii++) {
			ADC_Calib[ii][i] = 0;
			ADC_Calib[ii][i] = CURRENT_DIFF[ii];
		}
	}
	printk(KERN_NOTICE "ADC_Calib source=%d, Gain Slice=%d,%d,%d,%d,%d,%d,%d,%d,%d\n" ,bCalibrationSource, AWB_ADC_Gain_Slice[bCalibrationSource][0],
		AWB_ADC_Gain_Slice[bCalibrationSource][1], AWB_ADC_Gain_Slice[bCalibrationSource][2],
		AWB_ADC_Gain_Slice[bCalibrationSource][3], AWB_ADC_Gain_Slice[bCalibrationSource][4],
		AWB_ADC_Gain_Slice[bCalibrationSource][5], AWB_ADC_Gain_Slice[bCalibrationSource][6],
		AWB_ADC_Gain_Slice[bCalibrationSource][7], AWB_ADC_Gain_Slice[bCalibrationSource][8]);
	printk(KERN_NOTICE "ADC_Calib R diff=%d,%d,%d,%d,%d,%d,%d,%d,%d\n", ADC_Calib[0][0], ADC_Calib[0][1], ADC_Calib[0][2], ADC_Calib[0][3],
		ADC_Calib[0][4], ADC_Calib[0][5], ADC_Calib[0][6], ADC_Calib[0][7], ADC_Calib[0][8]);
	printk(KERN_NOTICE "ADC_Calib G diff=%d,%d,%d,%d,%d,%d,%d,%d,%d\n", ADC_Calib[1][0], ADC_Calib[1][1], ADC_Calib[1][2], ADC_Calib[1][3],
		ADC_Calib[1][4], ADC_Calib[1][5], ADC_Calib[1][6], ADC_Calib[1][7], ADC_Calib[1][8]);
	printk(KERN_NOTICE "ADC_Calib B diff=%d,%d,%d,%d,%d,%d,%d,%d,%d\n", ADC_Calib[2][0], ADC_Calib[2][1], ADC_Calib[2][2], ADC_Calib[2][3],
		ADC_Calib[2][4], ADC_Calib[2][5], ADC_Calib[2][6], ADC_Calib[2][7], ADC_Calib[2][8]);
}


void SAWB_GainCalculate(unsigned char sCalibrationSource)
{
	// get current 0.55~0.85V code diff at gain =AWB_ADC_Gain_Slice[2]
	// DAC level: 000:0.25V 001:0.4V 010:0.55V 011:0.7V 100:0.85V 101:1.0V 110:1.15V 111:1.3V
	//Step1. Get the Codediff  at currently align point.
	//Step2. Caculate Gain drift at align point. a. Caculate the which gain will have the same codediff on org-table b. code drift = a.-align point
	//Step3. Caculate the Gain for GetTagertValue and the final Gain=
	int i;
	printk(KERN_NOTICE "SAWB_GainCalculate source=%d\n", sCalibrationSource);
	OTP_Initial_Setting();
	//IoReg_Mask32(ADC_ADC_DCRESTORE_CTRL_reg, 0xffd0fe00, _BIT21); //Enable Calib mode OFFPAD,LPF=10M
	//IoReg_Mask32(ADC_ADC_CLAMP_CTRL1_reg, 0xfffffe00, _BIT8|_BIT6|_BIT5|_BIT3|_BIT2|_BIT0); //VClamping postive Enable
	//IoReg_Mask32(ADC_ADC_CLAMP_CTRL0_reg, 0xf000fe00, _BIT27|_BIT25|_BIT24|_BIT22|_BIT21|_BIT19|_BIT7|_BIT6|_BIT4|_BIT3|_BIT1|_BIT0); //VClamping postive Enable,Up/Dn Nclamping off

	Get_CodeDiff(2, 4, AWB_ADC_Gain_Slice[sCalibrationSource][ALIGNPOINT], AWB_ADC_Gain_Slice[sCalibrationSource][ALIGNPOINT],
		AWB_ADC_Gain_Slice[sCalibrationSource][ALIGNPOINT], sCalibrationSource);

	for (i = 0; i < 3; i++) {
		Interpolate_GainValue(SAWB_GetTARGET[sCalibrationSource][i], i, &FINAL_GAIN[i], sCalibrationSource);
		if (FINAL_GAIN[i] > 511)
			FINAL_GAIN[i] = 511;
		else if (FINAL_GAIN[i] < 0)
			FINAL_GAIN[i] = 0;
	}
	printk(KERN_NOTICE "SAWB_GainCalculate FINAL_GAIN=%d,%d,%d\n", FINAL_GAIN[0], FINAL_GAIN[1], FINAL_GAIN[2]);
	printk(KERN_NOTICE "SAWB_GainCalculate Source=%d, GetTargetValue=%d,%d,%d\n", sCalibrationSource, SAWB_GetTARGET[sCalibrationSource][0], SAWB_GetTARGET[sCalibrationSource][1], SAWB_GetTARGET[sCalibrationSource][2]);
	//confirm final gain and GetTarget
	Get_CodeDiff(2, 4, FINAL_GAIN[0], FINAL_GAIN[1], FINAL_GAIN[2], sCalibrationSource);
}

void OTP_ADC_Calibration(void)//(ADCGainOffset *pt_info)
{

	OTP_ADC_CRT_CTRL(TRUE);
	//Build_Self_AWB_ADC_Curve(0);
	SAWB_GainCalculate(0);
	//Build_Self_AWB_ADC_Curve(1);
	//SAWB_GainCalculate(1);

}

#endif

unsigned char drvif_auto_phasedo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM, unsigned char color)
{
	unsigned char phase_tmp,filter_sel;
	adc_smartfit_adc_auto_phase_ctrl0_RBUS smartfit_auto_phase_ctrl0_reg;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Adjust Phase Start !!!!\n", __func__, __LINE__);

	drv_auto_set_phase(0);

	drvif_ypp_auto_phase_pre_setup(display, 0x80, 0x80, 0x80, _COLORS_GREEN);//Directly use timing info for auto phase setting

	drv_auto_set_difference_threshold(Difference_Threshold);

	filter_sel = drv_auto_SOD_filter_sel(display);
	
#if 1
    if(drv_auto_get_phase_flag())//0428 bit20 =1 ====>0424[31:30]=10 , 0424[24:22]=001 , 0424[6:0]=0x3f
             auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_2, HWAUTOSTEPNUM(64),  HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
     else////0428 bit20 =0 ====>0424[31:30]=10 , 0424[24:22]=000 , 0424[6:0]=0x3F
             auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_1, HWAUTOSTEPNUM(64),  HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
#else
	auto_phasesearch_start(Hardware_Auto_Phase, display, Pulse_Detection_Enable, _COLORS_GREEN, HWAUTO_STEP_8, HWAUTOSTEPNUM(16), HWAUTOSTEPSTART(0), &phase_tmp,Low_Pass_Filter_0);
#endif
	drvif_ypbpr_auto_phasedo_WaitFinish(SLR_MAIN_DISPLAY);

	smartfit_auto_phase_ctrl0_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_AUTO_PHASE_CTRL0_reg);
	if(drv_auto_get_phase_flag()){
		p_screenInfo->Phase = smartfit_auto_phase_ctrl0_reg.autophase_max_step;
	}else{
		p_screenInfo->Phase = smartfit_auto_phase_ctrl0_reg.autophase_max_step << 1;
	}

	return ERROR_SUCCEED;
}


unsigned char drvif_auto_clockdo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM,unsigned char color)
{
	unsigned short usTempClock;
	unsigned char   count, delta, stop, Result,filter_sel;
	unsigned long long max_value  = 0;
	unsigned long long  max_value_temp = 0;
	unsigned short h_start,h_end;
	unsigned short IHTotal;
	adc_smartfit_adc_pllphase_ctrl_RBUS adc_smartfit_adc_pllphase_ctrl_reg;

	//unsigned char ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX);
	//unsigned char input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX);
	unsigned short ADC_CLOCK;// = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_ADC_CLOCK);
	unsigned short IPH_ACT_WID_PRE;

	//printf("\n\n[auto adjust]**********drvif_auto_clockdo***********\n\n");
	//printf("\n\n[auto adjust]**********************************\n\n");

	//printf("\n[auto adjust]ucMode_Curr = %d",ucMode_Curr);
	//printf("\n[auto adjust]input_src = %d",input_src);
	//printf("\n[auto adjust]ADC_CLOCK = %d",ADC_CLOCK);
	//printf("\n[auto adjust]IPH_ACT_WID = %d",IPH_ACT_WID_PRE);

	StructDisplayInfo *p_dispinfo = NULL;
	p_dispinfo = Get_ADC_Dispinfo();
	if(!p_dispinfo) return ERROR_ABORT;

	IPH_ACT_WID_PRE = p_dispinfo->IPH_ACT_WID_PRE;


	p_screenInfo->Clock = 50;
	p_screenInfo->ClockShift_After_auto = 128;

	ADC_CLOCK = p_dispinfo->INPUT_ADC_CLOCK;
	usTempClock = ADC_CLOCK;

	usTempClock = usTempClock & 0xfffc;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]usTempClock = %d#####\n", __func__, __LINE__, usTempClock);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]INPUT_ADC_CLOCK = %d#####\n", __func__, __LINE__, p_dispinfo->INPUT_ADC_CLOCK);
	//stScreenModeCurrInfo[Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX)].Clock = stVGAModeCurrInfo[Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX)].Clock;


//[Code Sync][AlanLi][0980525][1]
//sync auto adjust flow
	//Adjust_ADC_Clock(display, TRUE);

	drv_adc_clock_adjust(p_screenInfo, display, TRUE);  // reset ihtotal and get value below

	IHTotal = p_dispinfo->IHTotal;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]IHTotal = %d#####\n", __func__, __LINE__, IHTotal);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]IPH_ACT_WID_PRE = %d#####\n", __func__, __LINE__, IPH_ACT_WID_PRE);

	delta = IPH_ACT_WID_PRE * (Clock_Adjust_Range>>1) / IHTotal;
	stop = 0;
	count = 10;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]delta = %d#####\n", __func__, __LINE__, delta);

	msleep(10000/p_dispinfo->IVFreq);//wait one frame
	do
	{
		Result = drvif_measure_h_position(display, _HORIZONTAL_MARGIN, &h_start, &h_end,color);
		if (ERROR_SUCCEED != Result)
		{
			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Result = 0x%02x#####\n", __func__, __LINE__, Result);
			return Result;
		}
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Active actual h_start = %d#####\n", __func__, __LINE__, h_start);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Active actual h_end = %d#####\n", __func__, __LINE__, h_end);
		h_end   = h_end  - h_start + 1;
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Active actual h_end = %d#####\n", __func__, __LINE__, h_end);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]IPH_ACT_WID_PRE = %d#####\n", __func__, __LINE__, IPH_ACT_WID_PRE);
		if(h_end < IPH_ACT_WID_PRE)
		{
			if((IPH_ACT_WID_PRE - h_end) >= delta)
			{
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]1-delta = %d#####\n", __func__, __LINE__, delta);
				stop    = 1;
			}
			else
			{
				h_start = (unsigned int)(IPH_ACT_WID_PRE - h_end) * (usTempClock) /(unsigned int)h_end;
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]h_start = %d#####\n", __func__, __LINE__, h_start);
   				if(h_start <= 2)    break;
   					h_start = (h_start + 2) & 0xfffc;
 				//if((usHStartPos + stModeUserData.Clock - stModeInfo.IHTotal) > usDelta)
				if((h_start + usTempClock) > (delta + IHTotal))
				{
					stop    = 1;
		        }
				else
		        {
		        	usTempClock += h_start;
		        }
	    	}
       	}
		else
		{
	            if((h_end - IPH_ACT_WID_PRE) >= delta)
				{
	                stop    = 1;
	            }
				else
				{
					h_start = (unsigned int)(h_end - IPH_ACT_WID_PRE) * (usTempClock) /(unsigned int)h_end;
					rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]h_start = %d#####\n", __func__, __LINE__, h_start);
					if(h_start <= 2)    break;
					h_start = (h_start + 2) & 0xfffc;
	                if((usTempClock - h_start ) < (IHTotal - delta ))
	                    stop    = 1;
	                else
	                    usTempClock -= h_start;
            	}
		}
		if(stop)   break;

		//p_screenInfo->Clock = 50;
		// CSW+ 0961003
		//SET_CLOCK(input_src, p_screenInfo->Clock);

		if(usTempClock >= p_dispinfo->INPUT_ADC_CLOCK)
		{
			if(usTempClock > (p_dispinfo->INPUT_ADC_CLOCK + 127))
			{
				stop = 1;
				break;
			}
			else
			{
				p_screenInfo->ClockShift_After_auto = usTempClock - p_dispinfo->INPUT_ADC_CLOCK + 128;
			}
		}
		else
		{
			if((usTempClock + 128) < p_dispinfo->INPUT_ADC_CLOCK)
			{
				stop = 1;
				break;
			}
			else
			{
				p_screenInfo->ClockShift_After_auto = usTempClock + 128 - p_dispinfo->INPUT_ADC_CLOCK;
			}
		}

//[Code Sync][AlanLi][0980525][1]
//sync auto adjust flow
		//Adjust_ADC_Clock(display, TRUE);
		drv_adc_clock_adjust(p_screenInfo, display, TRUE);
//[Code Sync][AlanLi][0980525][1][end]
		msleep(10000/p_dispinfo->IVFreq);//wait one frame
	}while(--count);

	if((0 == count ) || (1 == stop)){
		p_screenInfo->ClockShift_After_auto = 128;
		drv_adc_clock_adjust(p_screenInfo, display, TRUE);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]stop=%d#####\n", __func__, __LINE__, stop);
		return ERROR_ABORT;
	}
	//printf("\n[auto adjust]=========================");
	//printf("\n[auto adjust]ptVGAModeCurrInfo.Clock_after=%x\n", stVGAModeCurrInfo[ucMode_Curr].Clock);


	 // Prevent from 1/2-line moire and smear effect.
	if((h_end >= IPH_ACT_WID_PRE && (usTempClock - IHTotal) == 4)
       	|| (h_end < IPH_ACT_WID_PRE && (IHTotal - usTempClock) == 4))
	{

	//	p_screenInfo->Clock = 50;
		p_screenInfo->ClockShift_After_auto = usTempClock + 128 - p_dispinfo->INPUT_ADC_CLOCK;
		// CSW+ 0961003
		//SET_CLOCK(input_src,stVGAModeCurrInfo[ucMode_Curr].Clock);

		//[Code Sync][AlanLi][0980525][1]
		//sync auto adjust flow
		//Adjust_ADC_Clock(display, TRUE);
		drv_adc_clock_adjust(p_screenInfo, display, TRUE);
		//[Code Sync][AlanLi][0980525][1][end]

	    Result    = drvif_measure_h_position(display, 0X80, &h_start, &h_end,color);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]Result=0x%02x#####\n", __func__, __LINE__, Result);
		if(Result != ERROR_SUCCEED)
			return Result;
		h_end   = h_end  - h_start + 1;
	}
	if(0)
	//if(!((h_end == IPH_ACT_WID_PRE)&&(p_screenInfo->Clock == 50)))
	{
		// Save 4N clock
		stop    = p_screenInfo->Clock;
		p_screenInfo->Clock += (IPH_ACT_WID_PRE >= h_end) ? 4 : 2;
		// CSW+ 0961003
		//SET_CLOCK(input_src,stVGAModeCurrInfo[ucMode_Curr].Clock);

		//Adjust_ADC_Clock(display, TRUE);
		drv_adc_clock_adjust(p_screenInfo, display, TRUE);
		// CSW+

		count   = stop;
		//max_value  = 0;
		delta   = 6;    // Initial value must be (N * AUTO_CLOCK_STEP)

		drv_auto_set_difference_threshold(Difference_Threshold);

		//printf("\n[auto adjust]=====MAX=====");
		//printf("\n[auto adjust]=============");

		filter_sel = drv_auto_SOD_filter_sel(display);
		//printf("\n[auto adjust]filter_sel=%x", filter_sel);
		do
		{
		//	printf("\nnow max measure clock%x", stVGAModeCurrInfo[ucMode_Curr].Clock);

			msleep(3);
			Result    = drvif_measure_h_position(display, _HORIZONTAL_MARGIN, &h_start, &h_end,color);
			if(Result != ERROR_SUCCEED)
				return Result;
			h_end   = h_end  - h_start + 1;
			if(h_end > (IPH_ACT_WID_PRE + 2))
			{
				max_value_temp   = 0;
			}
			else
			{
				WaitFor_IVS1();
				WaitFor_IVS1();

				//64 or 128
				adc_smartfit_adc_pllphase_ctrl_reg.regValue = IoReg_Read32(ADC_SMARTFIT_ADC_PLLPHASE_CTRL_reg);
				stop = adc_smartfit_adc_pllphase_ctrl_reg.pll2d2;

				if(stop)
					max_value_temp  = autoclock_searchphase( display, Pulse_Detection_Disable/*Pulse_Detection_Enable*/, color, HWAUTO_STEP_8, HWAUTOSTEPNUM(16), HWAUTOSTEPSTART(0), filter_sel);
				else
					max_value_temp  = autoclock_searchphase( display, Pulse_Detection_Disable/*Pulse_Detection_Enable*/, color, HWAUTO_STEP_8, HWAUTOSTEPNUM(8), HWAUTOSTEPSTART(0), filter_sel);


				//printf("\nmax_value_temp=%x\n", max_value_temp);
				if(!(drv_auto_few_difference_pattern(display,max_value_temp)))
					break;

				if (0xffffffff == max_value_temp)
					return ERROR_INPUT;
			}

		        if(max_value < max_value_temp)
		        {
		            max_value = max_value_temp;
		            count = p_screenInfo->Clock;
		        }

			if(delta == 0x00)
			{
				//printf("\n Final clock:%x, Mur Clk:%x\n", stVGAModeCurrInfo[ucMode_Curr].Clock, count);
				break;
			}
			delta -= AUTO_CLOCK_PRECISION;

			p_screenInfo->Clock -= AUTO_CLOCK_PRECISION;
			// CSW+ 0961003
			//SET_CLOCK(input_src,stVGAModeCurrInfo[ucMode_Curr].Clock);

			//Adjust_ADC_Clock(display, TRUE);
			drv_adc_clock_adjust(p_screenInfo, display, TRUE);
		}while(TRUE);

		p_screenInfo->Clock = count;//Set the clock according the max phase SOD
		//printf("[auto adjust]final clock= %d\n", stVGAModeCurrInfo[ucMode_Curr].Clock);

	}
	//[Code Sync][AlanLi][0980525][1][end]
	//stVGAModeCurrInfo[ucMode_Curr].Clock = stVGAModeCurrInfo[ucMode_Curr].Clock ;
	//SET_CLOCK(input_src,stVGAModeCurrInfo[ucMode_Curr].Clock);
	//p_dispinfo->INPUT_ADC_CLOCK=usTempClock;
	p_screenInfo->Clock=50;
	//[Code Sync][AlanLi][0980525][1]
	//sync auto adjust flow
	//Adjust_ADC_Clock(display, TRUE);
	drv_adc_clock_adjust(p_screenInfo, display, TRUE);
	//[Code Sync][AlanLi][0980525][1][end]
	// CSW+ 0970303 Prevent auto adjust clock range exceed 0x32
	//if (ABS(GET_CLOCK(input_src) , 0x80) > 0x32)
	//	return ERROR_NOISE_TOO_BIG;

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Adjust Clock SUCCEED count =%x#####\n", __func__, __LINE__, count);
	return ERROR_SUCCEED;

}

unsigned char drvif_auto_positiondo(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char NM,unsigned char color)
{
	unsigned char   Result,temp;//,ori_hpos;

#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_delay_RBUS dma_vgip_dma_vgip_delay_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_dma_vgip_act_vsta_length_reg;
#else
	vgip_vgip_chn1_delay_RBUS vgip_chn1_delay_reg;
	vgip_vgip_chn1_act_hsta_width_RBUS vgip_chn1_act_hsta_reg;
#endif

	unsigned short v_start,v_end,h_start,h_end;
	//unsigned char ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX);
	//unsigned char input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX);
	//unsigned short IPH_ACT_STA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_STA);
	//unsigned short IPV_ACT_STA = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_STA);
	unsigned char ucIPV_Min_Margin = Scaler_DispGetIpMargin(SLR_IPMARGIN_V_MIN);
	unsigned char ucIPV_Max_Margin = Scaler_DispGetIpMargin(SLR_IPMARGIN_V_MAX);
	unsigned char ucIPH_Min_Margin = Scaler_DispGetIpMargin(SLR_IPMARGIN_H_MIN);
	unsigned char ucIPH_Max_Margin = Scaler_DispGetIpMargin(SLR_IPMARGIN_H_MAX);
#ifndef CONFIG_FORCE_RUN_I3DDMA
	unsigned char ucIVS2DVSDelay = Scaler_DispGetIvs2DvsDelay();
#endif
	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Adjust Position Start !!!!\n", __func__, __LINE__);

    Scaler_DispSetAutoPosition(TRUE);

	Result = drvif_measure_v_position(display, 0xb0, 0xb0, 0xb0, &v_start, &v_end,color); //darwin, mag
	if (ERROR_SUCCEED != Result){
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT Result=0x%02x, v_start=%d,v_end=%d#####\n", __func__, __LINE__, Result, v_start,v_end);
		return Result;
	}

	if(!check_v_auto_position_result(v_start, v_end, p_dispinfo))
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####confirm v position result error v_start=%d,v_end=%d#####\n", v_start,v_end);
		return ERROR_ABORT;
	}
	else if(v_start < FIX_VGIP_V_START)
	{//for special device vstart only 2
		v_start = FIX_VGIP_V_START;
	}

	Result = drvif_measure_h_position(display, 0xe0, &h_start, &h_end,color);
	if (ERROR_SUCCEED != Result){
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####[%s(%d)]ERROR_ABORT Result=0x%02x, h_start=%d,h_end=%d#####\n", __func__, __LINE__, Result, h_start,h_end);
		return Result;
	}


	if(!check_h_auto_position_result(h_start, h_end, p_dispinfo))
	{
		rtd_printk(KERN_ERR, TAG_NAME_ADC, "#####confirm h position result error h_start=%d, h_end=%d#####\n", h_start, h_end);
		return ERROR_ABORT;
	}	
	temp = p_screenInfo->V_Position;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]h_start=%d, h_end =%d v_start=%d, v_end =%d osd:%d#####\n", __func__, __LINE__, h_start, h_end, v_start, v_end, temp);

	//---------Calculate Vertical Position-----------
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]IPV_Max_Margin = %d,IPV_Min_Margin = %d#####\n", __func__, __LINE__,ucIPV_Max_Margin,ucIPV_Min_Margin);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]IPH_Max_Margin = %d,IPH_Min_Margin = %d#####\n", __func__, __LINE__,ucIPH_Max_Margin,ucIPH_Min_Margin);

#ifdef CONFIG_FORCE_RUN_I3DDMA
#if 0
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]ucIVS2DVSDelay =%d#####\n", __func__, __LINE__, ucIVS2DVSDelay);
	dma_vgip_dma_vgip_delay_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_DELAY_reg);
	ucIVS2DVSDelay = dma_vgip_dma_vgip_delay_reg.dma_ivs_dly;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]dma_ivs_dly =%d#####\n", __func__, __LINE__, dma_vgip_dma_vgip_delay_reg.dma_ivs_dly);

	Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

	dma_vgip_dma_vgip_act_vsta_length_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
	dma_vgip_dma_vgip_act_vsta_length_reg.dma_iv_act_sta = v_start - ucIVS2DVSDelay;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb802241C[29:16]=0x%04x#####\n", __func__, __LINE__,dma_vgip_dma_vgip_act_vsta_length_reg.dma_iv_act_sta);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_dma_vgip_act_vsta_length_reg.regValue);
#endif
#else
	if(v_start <= (p_dispinfo->IPV_ACT_STA+(ucIPV_Max_Margin -128)+20))
	{
		if(v_start >= (p_dispinfo->IPV_ACT_STA-(128-ucIPV_Min_Margin)))
			p_screenInfo->V_Position = (v_start -p_dispinfo->IPV_ACT_STA) + 128;
		else
			p_screenInfo->V_Position = ucIPV_Min_Margin;
	}
	else
	{
		p_screenInfo->V_Position = ucIPV_Max_Margin;
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]v_start =%d#####\n", __func__, __LINE__, v_start);
	ucIVS2DVSDelay = v_start -	Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]ucIVS2DVSDelay =%d#####\n", __func__, __LINE__, ucIVS2DVSDelay);

	Scaler_DispSetIvs2DvsDelay(ucIVS2DVSDelay);

	if(SLR_MAIN_DISPLAY == display)
	{
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]ucIVS2DVSDelay =%d#####\n", __func__, __LINE__, ucIVS2DVSDelay);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]ch1_ivs_dly =%d#####\n", __func__, __LINE__, vgip_chn1_delay_reg.ch1_ivs_dly);
		vgip_chn1_delay_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_DELAY_reg);
		vgip_chn1_delay_reg.ch1_ivs_dly = ucIVS2DVSDelay;
		Scaler_DispSetIvs2DvsDelay(vgip_chn1_delay_reg.ch1_ivs_dly);
		IoReg_Write32(VGIP_VGIP_CHN1_DELAY_reg, vgip_chn1_delay_reg.regValue);
		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]ch1_ivs_dly =%d#####\n", __func__, __LINE__, vgip_chn1_delay_reg.ch1_ivs_dly);
	}
#endif
	//p_screenInfo->V_Position = 0x32;  //osd value
	p_screenInfo->V_Start_Pos_After_Auto = v_start;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]V_Start_Pos_After_Auto =%d#####\n", __func__, __LINE__, p_screenInfo->V_Start_Pos_After_Auto);
	p_dispinfo->IPV_ACT_STA = p_screenInfo->V_Start_Pos_After_Auto;
	//SET_V_START_POS_AFTER_AUTO(input_src, v_start);

	//SET_V_POSITION(input_src,stScreenModeCurrInfo[ucMode_Curr].V_Position);
	p_screenInfo->H_Start_Pos_After_Auto = h_start - INTERNAL_H_DELAY;
	p_dispinfo->IPH_ACT_STA = p_screenInfo->H_Start_Pos_After_Auto;
	msleep(10);

	//---------Calculate Horizontal Position-----------

	//diff_2 = ((diff_2 > 0x80)? (diff_2-0x80) : (0x80 -diff_2));
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]h_start =%d#####\n", __func__, __LINE__, h_start);
#ifdef CONFIG_FORCE_RUN_I3DDMA
/*
	dma_vgip_act_hsta_width_reg.regValue = IoReg_Read32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022418[29:16]=0x%04x#####\n", __func__, __LINE__,dma_vgip_act_hsta_width_reg.dma_ih_act_sta);
	dma_vgip_act_hsta_width_reg.dma_ih_act_sta = h_start - INTERNAL_H_DELAY;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022418[29:16]=0x%04x#####\n", __func__, __LINE__,dma_vgip_act_hsta_width_reg.dma_ih_act_sta);
	IoReg_Write32(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg,dma_vgip_act_hsta_width_reg.regValue );
*/
	Scaler_SetHPosition(0x32);
	Scaler_SetVPosition(0x32);
	
#else
	Scaler_DispSetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE, v_start);
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA, p_screenInfo->H_Start_Pos_After_Auto);
	Scaler_DispSetInputInfo(SLR_INPUT_IPH_ACT_STA_PRE, p_screenInfo->H_Start_Pos_After_Auto);
	vgip_chn1_act_hsta_reg.regValue = IoReg_Read32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022218[29:16]=0x%04x#####\n", __func__, __LINE__,vgip_chn1_act_hsta_reg.ch1_ih_act_sta);
	vgip_chn1_act_hsta_reg.ch1_ih_act_sta = h_start-_H_POSITION_MOVE_TOLERANCE;
	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]0xb8022218[29:16]=0x%04x#####\n", __func__, __LINE__,vgip_chn1_act_hsta_reg.ch1_ih_act_sta);
	IoReg_Write32(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg,vgip_chn1_act_hsta_reg.regValue );
#endif

	//p_screenInfo->H_Position = 0x32;  //osd value

	//SET_H_POSITION(input_src, p_screenInfo->H_Position);
	//SET_H_START_POS_AFTER_AUTO(input_src, h_start);

    Scaler_DispSetAutoPosition(FALSE);

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)][Auto Adjust]Adjust Position SUCCEED !!!!\n", __func__, __LINE__);

    return ERROR_SUCCEED;
}

void drv_auto_clock_fail_handler(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char Curr_PosH, unsigned char Curr_Clock, unsigned char Curr_Phase)
{
	//unsigned char ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX);
	//unsigned char input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX);

	//printf("\n\n**********drvif_auto_clockdo_FAIL!!!***********\n\n");

	if (p_screenInfo->Clock != Curr_Clock)
	{
		// Fail to find out suitable clock. Restore original clock and H position.
		p_screenInfo->H_Position = Curr_PosH;
		p_screenInfo->Clock = Curr_Clock;

		// CSW+ 0961004
		//SET_H_POSITION(input_src,Curr_PosH);
		//SET_CLOCK(input_src,Curr_Clock);

		//forster modified 041122
		Adjust_ADC_Clock(display, TRUE);
	}

}

void drv_auto_phase_fail_handler(StructScreenModeInfo *stScreenModeCurrInfo, unsigned char display,unsigned char Curr_Phase)
{
	unsigned char ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX);
	unsigned char input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX);

	//printf("\n\n**********drvif_auto_phasedo_FAIL!!!***********\n\n");

	// Restore Phase
	stScreenModeCurrInfo[ucMode_Curr].Phase = Curr_Phase;

	// CSW+ 0961004
	//SET_PHASE(input_src,Curr_Phase);

	// check later
	YPbPr_SetPhase(display, Curr_Phase, TRUE);  //forster modified 071211
}

void drv_auto_position_fail_handler(StructScreenModeInfo *p_screenInfo, unsigned char display, unsigned char Curr_PosH, unsigned char Curr_PosV, unsigned char Curr_Phase, unsigned char Curr_Clock)
{
	//unsigned char ucMode_Curr = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MODE_TABLE_INDEX);
	//unsigned char input_src = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_DATA_ARRAY_IDX);

	//printf("\n\n**********drvif_auto_positiondo_FAIL!!!***********\n\n");

	p_screenInfo->H_Position = Curr_PosH;	   // Save current stMUD.H_POSITION
	p_screenInfo->V_Position = Curr_PosV;	   // Save current stMUD.V_POSITION
	p_screenInfo->Clock = Curr_Clock;
	p_screenInfo->Phase = Curr_Phase;
	//SET_CLOCK(input_src,Curr_Clock);
	//SET_PHASE(input_src,Curr_Phase);
	//SET_V_POSITION(input_src,p_screenInfo->V_Position);
	//SET_H_POSITION(input_src,p_screenInfo->H_Position);

	Adjust_ADC_Clock(display, TRUE);
	YPbPr_SetPhase(display, Curr_Phase, TRUE);  //forster modified 071211
	Scaler_SetHPosition(0x32);
	Scaler_SetVPosition(0x32);
}

