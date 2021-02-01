//#include <string.h>

//#include <stdio.h>
//#include <stdlib.h>

//#include <rtio.h>
//#include <VP_def.h>

//#include <auto_conf.h> // Provides: CONFIG_VBI_CC
//#include <rtd_system.h>
//#include <rtd_memmap.h>
#include <memc_isr/scalerMEMC.h>
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
#include "vgip_isr/scalerVIP.h"
#include <linux/mutex.h>
#endif
//#include <mach/io.h>

// oliver+
//#include <kernel/scaler/scalerDrv2.h>
//#include <scaler/kernel/scaler/scalerDrv.h>
//#include <scaler/scalerDrvCommon.h>
//#include <scaler/scalerCommon.h>
//#include <memc_isr/include/memc_lib.h>
#include <rbus/ppoverlay_reg.h>
#include "rbus/crt_sys_reg.h"
#include "rbus/crt_fw.h"
#include "tvscalercontrol/vip/vip_reg_def.h"

#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <rbus/sb2_reg.h> // for hardware semaphore

#include "memc_isr/Driver/KI7416_reg.h"
#include "memc_isr/Common/kw_debug.h" // for LogPrintf

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

#define MEMC_IRQ_HANDLED 1
#define MEMC_IRQ_NONE       0

static unsigned char scaler_memc_enable = 0;
#ifndef MEMC_INIT_STATUS
static unsigned char g_scaler_memc_acon_init = 0;//for ac off->on: dma enable delay 2 vsync than slavemode set, clear when dc suspend
#else
static SCALER_MEMC_INIT_STATUS g_scaler_memc_init_status = MEMC_INIT_NONE;
#endif

#ifdef CONFIG_MEMC_TASK_QUEUE
#define MEMC_TASK_MAX_CNT 17 //Total element count of memc task queue
static SCALER_MEMC_TASK_T g_memc_tasks_queue[MEMC_TASK_MAX_CNT];
static unsigned int g_memc_tasks_header = 0;
static unsigned int g_memc_tasks_tailer = 0;
#endif

unsigned char g_scaler_memc_cadence[_FILM_MEMC_NUM] = {0};

VOID MEMC_ISR_test(void);

//==================================================================================================

void memc_suspend(void)
{
	Scaler_MEMC_SetInitFlag(0);//clear when dc suspend
	Scaler_MEMC_resetMEMCMode();

}

void Scaler_MEMC_SetInitFlag(unsigned char val)
{
	return;
#ifndef MEMC_INIT_STATUS
	if(val>1)
		g_scaler_memc_acon_init = 0;
	else
		g_scaler_memc_acon_init = val;
#else
	g_scaler_memc_init_status = val;
#endif

}

unsigned char Scaler_MEMC_GetInitFlag(void)
{
	return;
#ifndef MEMC_INIT_STATUS

	return g_scaler_memc_acon_init;
#else
	return g_scaler_memc_init_status;
#endif
}

void Scaler_MEMC_Initialize(unsigned int ME_start_addr, unsigned int MC00_start_addr, unsigned int MC01_start_addr)
{
	return;
	UINT32 Hsync_start = 0, Vsync_start = 0;
	PANEL_PARA_ST stPanelPara;
	UINT16 u16Idx = 0;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]ME_start_addr = %x\n",ME_start_addr);
	LogPrintf(DBG_MSG,  "[MEMC]MC00_start_addr = %x\n",MC00_start_addr);
	LogPrintf(DBG_MSG,  "[MEMC]MC01_start_addr = %x\n",MC01_start_addr);

#ifndef MEMC_INIT_STATUS
	Scaler_MEMC_SetInitFlag(1);
#else
	Scaler_MEMC_SetInitFlag(MEMC_INIT_ACON_ING);
#endif
	Vsync_start = (rtd_inl(PPOVERLAY_memcdtg_DV_DEN_Start_End_reg) & 0xffff0000)>>16;
	Hsync_start = (rtd_inl(PPOVERLAY_memcdtg_DH_DEN_Start_End_reg) & 0xffff0000)>>16;
	LogPrintf(DBG_MSG,  "[MEMC]Vsync_start = %d\n",Vsync_start);
	LogPrintf(DBG_MSG,  "[MEMC]Hsync_start = %d\n",Hsync_start);
	MEMC_LibPanel_Init();
	stPanelPara.enOutputFrameRate = OUTPUT_60HZ;
	stPanelPara.u32Htotal = 4400;
	stPanelPara.u32HtotalMax = 4800;
	stPanelPara.u32HtotalMin = 4000;
	stPanelPara.u32Hactive = 3840;
	stPanelPara.u32HSWidth = 64;
	stPanelPara.u32HSBPorch = Hsync_start - stPanelPara.u32HSWidth;
	stPanelPara.u32Vtotal = 2250;
	stPanelPara.u32VtotalMax = 2300;
	stPanelPara.u32VtotalMin = 2200;
	stPanelPara.u32Vactive = 2160;
	stPanelPara.u32VSWidth = 8;
	stPanelPara.u32VSBPorch = Vsync_start - stPanelPara.u32VSWidth;
	for(u16Idx = 0; u16Idx < OUTPUT_FRAME_MAX; u16Idx++){
		stPanelPara.enOutputFrameRate = u16Idx;
		MEMC_LibSetPanelParameters(&stPanelPara);
	}
	MEMC_LibDMAllocate(MC00_start_addr, MC01_start_addr, ME_start_addr);
	MEMC_LibInit();
	//MEMC_LibSetInOutFrameRate(INPUT_60HZ,OUTPUT_60HZ);
	//MEMC_LibSetInOutMode(MEMC_RGB_IN_VIDEO_OUT,TRUE);
	//MEMC_LibSetInOutUseCase(INPUT_3840X2160, OUTPUT_3840X2160, INPUT_2D, OUTPUT_2D);
	/* Enable in/out Vsync interrupt */
	MEMC_LibInputVSInterruptEnable(TRUE);
	MEMC_LibOutputVSInterruptEnable(TRUE);
	Scaler_MEMC_SetMEMC_Enable(1);
#ifdef MEMC_INIT_STATUS
	Scaler_MEMC_SetInitFlag(MEMC_INIT_ACON_FINISH);
#endif
	LogPrintf(DBG_MSG,  "MEMC initialize done. IOvs Intp Enable.\r\n");
}

void Scaler_MEMC_Uninitialize(void){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}

unsigned char Scaler_MEMC_Dejudder_Level_Mapping(unsigned char inLevel)
{
	return;
	unsigned char outLevel = 0;

	unsigned char level_map[11] = {0, 14, 28, 41, 55, 68, 82, 95, 106, 117, 128};	//confirmed by LG Ann


	if(inLevel > 10)
		inLevel = 10;

	outLevel = level_map[inLevel];

	return outLevel;
}

unsigned char Scaler_MEMC_Deblur_Level_Mapping(unsigned char inLevel)
{
	return;
	unsigned char outLevel = 0;

	unsigned char level_map[11] = {0, 14, 28, 41, 55, 68, 82, 95, 106, 117, 128};	//confirmed by LG Ann


	if(inLevel > 10)
		inLevel = 10;

	outLevel = level_map[inLevel];

	return outLevel;
}

void Scaler_MEMC_SetMotionComp(unsigned char blurLevel, unsigned char judderLevel, SCALER_MEMC_TYPE_T motion){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]blurLevel = %d, judderLevel = %d, motion = %d\n",blurLevel, judderLevel, motion);
	//if(MEMC_LibGetMEMC_PCModeEnable() == TRUE){
	//	return;
	//}
	_clues* SmartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues* RPC_SmartPic_clue = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);

	if((SmartPic_clue == NULL) || (RPC_SmartPic_clue == NULL))
		return;

	if(MEMC_LibGetMEMCLowDelayModeEnable() == TRUE && RPC_SmartPic_clue->MEMC_VCPU_setting_info.m_MiraCast == 1)
		return;

	if(motion == MEMC_TYPE_OFF){
		//OFF memc
		MEMC_LibSetMEMCMode(MEMC_OFF);

		if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
		{
			LogPrintf(DBG_MSG, "[RepeatMode] Power saving mode on, return.\n");
		}
		else
		{
			MEMC_LibSetMEMCFrameRepeatEnable(1, 0);
		}
	}
	else if(motion == MEMC_TYPE_LOW){
		//Set low memc
		MEMC_LibSetMEMCMode(MEMC_CLEAR);
		if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
		{
			LogPrintf(DBG_MSG, "[RepeatMode] Power saving mode on, return.\n");
		}
		else
		{
			MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		}
	}
	else if(motion == MEMC_TYPE_HIGH){
		//Set high memc
		MEMC_LibSetMEMCMode(MEMC_SMOOTH);
		if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
		{
			LogPrintf(DBG_MSG, "[RepeatMode] Power saving mode on, return.\n");
		}
		else
		{
			MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		}
	}
	else if(motion == MEMC_TYPE_USER){
		//Set user memc
		MEMC_LibSetMEMCMode(MEMC_USER);
		//Set blurLevel for Video
		blurLevel = Scaler_MEMC_Deblur_Level_Mapping(blurLevel);
		MEMC_LibSetMEMCDeblurLevel(blurLevel);
		//Set JudderLevel for Film
		judderLevel = Scaler_MEMC_Dejudder_Level_Mapping(judderLevel);
		MEMC_LibSetMEMCDejudderLevel(judderLevel);
		if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
		{
			LogPrintf(DBG_MSG, "[RepeatMode] Power saving mode on, return.\n");
		}
		else
		{
			MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		}
	}
	else if(motion == MEMC_TYPE_55_PULLDOWN){
		//On 5:5 Pull-down for 24Hz Film source
		if(RPC_SmartPic_clue->prePowerSaveStatus == PS_ON)
		{
			LogPrintf(DBG_MSG, "[RepeatMode] Power saving mode on, return.\n");
		}
		else
		{
			MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		}
	}
}

void Scaler_MEMC_SetBlurLevel(unsigned char blurLevel){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]blurLevel = %d\n",blurLevel);
	//Set blurLevel for Video

	blurLevel = Scaler_MEMC_Deblur_Level_Mapping(blurLevel);

	MEMC_LibSetMEMCDeblurLevel(blurLevel);
}

void Scaler_MEMC_SetJudderLevel(unsigned char judderLevel){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]judderLevel = %d\n",judderLevel);
	//Set JudderLevel for Film

	judderLevel = Scaler_MEMC_Dejudder_Level_Mapping(judderLevel);

	MEMC_LibSetMEMCDejudderLevel(judderLevel);
}

void Scaler_MEMC_MotionCompOnOff(unsigned char bOnOff){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]bOnOff = %d\n",bOnOff);

	if(bOnOff == TRUE){
		MEMC_LibSetMEMCMode(MEMC_NORMAL);
		MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
	}
	else{
		MEMC_LibSetMEMCMode(MEMC_OFF);
		MEMC_LibSetMEMCFrameRepeatEnable(1, 0);
	}
}

void Scaler_MEMC_LowDelayMode(unsigned char type){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s][%d]\n",__FUNCTION__, type);
	LogPrintf(DBG_MSG,  "$$$   scalerMEMC_LowDelay_(%d)   $$$\n\r", type);
	static MEMC_MODE last_mode = MEMC_OFF;
	static unsigned char pre_type = 255;

	if(type == MEMC_LibGetMEMCLowDelayModeEnable())
		return;

	if(MEMC_LibGetMEMC_PCModeEnable())
		return;

	if(type == 1){
		//Reduce frame buffer for low frame delay
		//if(MEMC_LibGetMEMC_PCModeEnable() == FALSE)	//PC mode first
		//{
		//	MEMC_LibSetMEMCMode(MEMC_OFF);
		//	MEMC_LibSetMEMCFrameRepeatEnable(1, 0);
		//}
		if(type != pre_type){
			last_mode = MEMC_LibGetMEMCMode();
			MEMC_LibSetMEMCMode(MEMC_OFF);
			MEMC_LibSetMEMCFrameRepeatEnable(1, 0);
		}
		MEMC_LibSetMEMCLowDelayModeEnable(TRUE);
	}
	else{
		//Normal mode
		//MEMC_LibSetMEMCMode(MEMC_NORMAL);
		//MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		if(last_mode != MEMC_OFF){
			MEMC_LibSetMEMCMode(last_mode);
			MEMC_LibSetMEMCFrameRepeatEnable(0, 0);
		}
		MEMC_LibSetMEMCLowDelayModeEnable(FALSE);
	}
}
void Scaler_MEMC_SetRGBYUVMode(unsigned char mode){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	LogPrintf(DBG_MSG,  "[MEMC]mode = %d\n",mode);

	switch(mode)
	{
		case 0:
			//MEMC_LibSetInOutMode(MEMC_RGB_IN_VIDEO_OUT, FALSE);
			MEMC_LibSetMEMC_PCModeEnable(FALSE);
			break;
		case 1:
			//MEMC_LibSetInOutMode(MEMC_RGB_IN_PC_OUT, FALSE);
			MEMC_LibSetMEMC_PCModeEnable(TRUE);
			break;
#if 0
		case 2:
			MEMC_LibSetInOutMode(MEMC_YUV_IN_VIDEO_OUT, FALSE);
			break;
		case 3:
			MEMC_LibSetInOutMode(MEMC_YUV_IN_PC_OUT, FALSE);
			break;
#endif
		default:
			MEMC_LibSetInOutMode(MEMC_RGB_IN_VIDEO_OUT, FALSE);
			MEMC_LibSetMEMC_PCModeEnable(FALSE);
			break;
 	}

}
void Scaler_MEMC_GetFrameDelay (UINT16 *pFrameDelay){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_SetVideoBlock(SCALER_MEMC_MUTE_TYPE_T type, unsigned char bOnOff){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_SetTrueMotionDemo(unsigned char bOnOff){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);

	if(bOnOff== TRUE){
		MEMC_LibSetMEMCDemoMode(DEMO_MODE_OFF);
	}
	else{
		MEMC_LibSetMEMCDemoMode(DEMO_MODE_LEFT);
	}

}
void Scaler_MEMC_GetFirmwareVersion(UINT16 *pVersion){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_SetBypassRegion(unsigned char bOnOff, SCALER_MEMC_BYPASS_REGION_T region, UINT32 x, UINT32 y, UINT32 w, UINT32 h){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);

	LogPrintf(DBG_MSG,  "[MEMC]region = %d\n",region);
	LogPrintf(DBG_MSG,  "[MEMC]rect.x = %d, rect.y = %d, rect.w = %d, rect.h = %d\n",x, y, w, h);

	LogPrintf(DBG_MSG,  "[MEMC]bOnOff = %d\n",bOnOff);

	switch(region){
		case BYPASS_REGION_0:
			MEMC_LibSetDemoWindowSettings(BYPASS_REGION_0, x, w, y, h);
			MEMC_LibSetDemoWindowEnable(BYPASS_REGION_0, bOnOff);
			break;

		case BYPASS_REGION_1:
			MEMC_LibSetDemoWindowSettings(BYPASS_REGION_1, x, w, y, h);
			MEMC_LibSetDemoWindowEnable(BYPASS_REGION_1, bOnOff);
			break;

		case BYPASS_REGION_2:
			MEMC_LibSetDemoWindowSettings(BYPASS_REGION_2, x, w, y, h);
			MEMC_LibSetDemoWindowEnable(BYPASS_REGION_2, bOnOff);
			break;

		case BYPASS_REGION_3:
			MEMC_LibSetDemoWindowSettings(BYPASS_REGION_3, x, w, y, h);
			MEMC_LibSetDemoWindowEnable(BYPASS_REGION_3, bOnOff);
			break;

		case BYPASS_REGION_4:
			MEMC_LibSetDemoWindowSettings(BYPASS_REGION_4, x, w, y, h);
			MEMC_LibSetDemoWindowEnable(BYPASS_REGION_4, bOnOff);
			break;

		default:
			break;
	}
}
void Scaler_MEMC_SetReverseControl(unsigned char u8Mode){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_Freeze(unsigned char type){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_SetDemoBar(unsigned char bOnOff, unsigned char r, unsigned char g, unsigned char b){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}
void Scaler_MEMC_DEBUG(void){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
}

void Scaler_MEMC_SetInOutputUseCase(unsigned char input_re, unsigned char output_re, unsigned char input_for, unsigned char output_for){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	MEMC_LibSetInOutUseCase(input_re, output_re, input_for, output_for);
}

void Scaler_MEMC_SetInputOutputFormat(unsigned char input_for, unsigned char output_for){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	//MEMC_LibSetInputOutputFormat(input_for, output_for);
}

void Scaler_MEMC_SetInputOutputResolution(unsigned char input_re, unsigned char output_re){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	//MEMC_LibSetInputOutputResolution(input_re, output_re);
}

void Scaler_MEMC_SetInputFrameRate(unsigned char frame_rate){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	MEMC_LibSetInputFrameRate(frame_rate);
}

void Scaler_MEMC_SetOutputFrameRate(unsigned char frame_rate){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	MEMC_LibSetOutputFrameRate(frame_rate);
}

void Scaler_MEMC_SetMEMCFrameRepeatEnable(unsigned char enable){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	MEMC_LibSetMEMCFrameRepeatEnable(enable, 0);
}

void ISR_Scaler_MEMC_SetInOutMode(unsigned char emom){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	MEMC_LibSetInOutMode(emom, FALSE);
}

void Scaler_MEMC_SetInstantBootInitPhaseTable(){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);

	//enable MEMC input/output clock before run MEMC isr
	rtd_outl(SYS_REG_SYS_DISPCLKSEL_reg,rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg)|( BIT_5 | BIT_6));

	MEMC_LibForcePhaseTableInit();
}

void Scaler_MEMC_SetMEMC_Enable(unsigned char enable){
	return;
	scaler_memc_enable = enable;
}

void Scaler_MEMC_SetCinemaMode(unsigned char enable){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s][%d]\n",__FUNCTION__, enable);

	MEMC_LibSetCinemaMode(enable);
}

unsigned char Scaler_MEMC_GetMEMC_Enable(void){
	return;
	return scaler_memc_enable;
}

unsigned char Scaler_MEMC_GetMEMC_Mode(void){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	return MEMC_LibGetMEMCMode();
}

BOOL Scaler_MEMC_SetPowerSaveOn(){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s][%d]\n",__FUNCTION__);

	return MEMC_LibPowerSaveOn();
}

BOOL Scaler_MEMC_SetPowerSaveOff(){
	return;
	LogPrintf(DBG_MSG,  "[MEMC][%s][%d]\n",__FUNCTION__);

	return MEMC_LibPowerSaveOff();
}

#define BIT(x)               (1 <<x)
UBYTE u1_is_me_dead;
unsigned int Scaler_MEMC_ISR(void){
	return;
	//LogPrintf(DBG_MSG,  "[MEMC][%s]\n",__FUNCTION__);
	static UBYTE u1_is_me_dead_pre = 0;
	UINT32 u32_rb_val;

	//_clues* SmartPic_clue = Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues* RPC_SmartPic_clue = Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);

	if(RPC_SmartPic_clue == NULL){
		u1_is_me_dead = 255;
	} else {
		u1_is_me_dead = RPC_SmartPic_clue->MEMC_VCPU_setting_info.is_me_dead;
	}

	u32_rb_val = rtd_inl(SYS_CLKEN3_reg);
	u32_rb_val = (u32_rb_val>>30);

#if 0//def CONFIG_RTK_KDEV_DEBUG_ISR
	unsigned int reg_value = 0;
	reg_value = rtd_inl(0xb802e4f8);

	unsigned int time1;
	static unsigned int time1s_set=0;
	static unsigned int time1s_start=0;
	static unsigned int time1s_end=0;
	static unsigned int time1s_cnt=0;
	static unsigned int time_cnt1=0;
	static unsigned int time_cnt2=0;
	static unsigned int time4 =0, time4_pre = 0;
	if((reg_value & BIT(31))){
		time_cnt1++;
	}

	time1 = rtd_inl(0xB801B6A8);
	if(time1s_set==0)
	{
		time1s_start = time1;
		time1s_set=1;
		time1s_cnt=0;
	}
	time1s_end = rtd_inl(0xB801B6A8);

#endif


	if (u1_is_me_dead == 0 && u32_rb_val == 3 ) {
		if (u1_is_me_dead_pre == 1) {
			LogPrintf(DBG_WARNING,  "[Scaler_MEMC_ISR] me dead recover , enable isr now!!\n\r");
		}
#if 0//def CONFIG_RTK_KDEV_DEBUG_ISR
	time1s_cnt++;
	time_cnt2++;
#endif

		#ifdef CONFIG_MEMC_TASK_QUEUE
		/*resolve tasks from rpc*/
		if(MEMC_GetInOutISREnable())
			ScalerMEMC_TasksHandler();
		#endif

		MEMC_LibInputVSInterrupt();
		MEMC_LibOutputVSInterrupt();

	} else {
		if (u1_is_me_dead_pre == 0) {
			LogPrintf(DBG_WARNING,  "[Scaler_MEMC_ISR] me dead happened , disable isr now!!\n\r");
			}
		if (u32_rb_val != 3) {
			LogPrintf(DBG_WARNING,  "[Scaler_MEMC_ISR] memc clock off, disable isr now!!\n\r");
		}
	}
	u1_is_me_dead_pre = u1_is_me_dead;

#if 0//def CONFIG_RTK_KDEV_DEBUG_ISR
//====================================================
	time4=rtd_inl(0xB801B6A8);
	if((time1s_end-time1s_start)>=90000)
	{
		printk("[ISR]MEMC enable  %x,%d,%d,%d\n",reg_value, u1_is_me_dead, u32_rb_val, u1_is_me_dead_pre);
		printk("[ISR]MEMC timestamp %d\n",(time4 - time4_pre));
		printk("[ISR]MEMC times %d, %d\n",time_cnt1,time_cnt2);
		if((time1s_end-time1s_start)>=90000){
			printk("[ISR]MEMC isr %d times(%d CLK)\n",time1s_cnt, (time1s_end-time1s_start));
			time1s_set=0;
		}
	}
	time4_pre = time4;
//====================================================
#endif

	return MEMC_IRQ_HANDLED;
}

void Scaler_MEMC_resetMEMCMode(void)
{
	return;
	//(LGE)STR init force repeatmode, then change by WEBOS or others
	MEMC_LibResetMEMCMode();
}

unsigned char * Scaler_MEMC_GetCadence(void)
{
	return;
	return g_scaler_memc_cadence;
}

unsigned char Scaler_MEMC_GetAVSyncDelay(void)
{
	return;
	if(MEMC_LibGetMEMCLowDelayModeEnable())
		return 20;
	else
		return 60;
}

#ifdef CONFIG_MEMC_TASK_QUEUE
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
static DEFINE_MUTEX(memc_task_mutex);
#define memc_task_lock()      mutex_lock(&memc_task_mutex)
#define memc_task_unlock()    mutex_unlock(&memc_task_mutex)
#endif

unsigned char Scaler_MEMC_PushTask(SCALER_MEMC_TASK_T *pTask)
{
	return;
	unsigned int id = 0,i = 0,sem = 0,sem_timeout = 100;
	unsigned char ret = TRUE;

extern void hw_semaphore_try_lock(void);
extern void hw_semaphore_unlock(void);
	/*get HW semaphore*/
	#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	while (!(sem = (*(volatile unsigned int *)SB2_HD_SEM_NEW_5_reg)) && sem_timeout--){
		for (i=0 ; i<100 ; i++){
			asm volatile ("nop");
		}
	}
	#else
	memc_task_lock();
	#endif

	/*push task to queue*/
	id = (g_memc_tasks_header + 1) % MEMC_TASK_MAX_CNT;
	if(id == g_memc_tasks_tailer){
		LogPrintf(DBG_WARNING, "[%s]Task queue status(header=%d,tailer=%d)\n",\
			__FUNCTION__,g_memc_tasks_header,g_memc_tasks_tailer);
		g_memc_tasks_tailer = (g_memc_tasks_tailer + 1) % MEMC_TASK_MAX_CNT;
		ret = TRUE;
	}
	if(g_memc_tasks_header >= MEMC_TASK_MAX_CNT){
		LogPrintf(DBG_WARNING, "[%s]Invalid task index(%d,%d).Resume!\n",\
			__FUNCTION__,g_memc_tasks_header,g_memc_tasks_tailer);
		g_memc_tasks_header = 0;
		g_memc_tasks_tailer = 0;
		id = (g_memc_tasks_header + 1) % MEMC_TASK_MAX_CNT;
	}
	memcpy(&g_memc_tasks_queue[g_memc_tasks_header],pTask,sizeof(SCALER_MEMC_TASK_T));
	g_memc_tasks_header = id;
	/*put HW semaphore*/
	#ifndef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	if(sem)
		*(volatile unsigned int *)SB2_HD_SEM_NEW_5_reg = 0;
	else
		LogPrintf(DBG_MSG, "[%s]Waiting 'SB2_HD_SEM_NEW_5_reg' timeout!!\n",__FUNCTION__);
	#else
	memc_task_unlock();
	#endif
	/*return*/
	return ret;
}

unsigned char ScalerMEMC_PopTask(SCALER_MEMC_TASK_T *pTask)
{
	return;
	if(g_memc_tasks_tailer == g_memc_tasks_header)
		return FALSE;
	if(g_memc_tasks_tailer >= MEMC_TASK_MAX_CNT){
		LogPrintf(DBG_WARNING, "[%s]Invalid task index(%d,%d).Resume!\n",\
						__FUNCTION__,g_memc_tasks_header,g_memc_tasks_tailer);
		g_memc_tasks_header = 0;
		g_memc_tasks_tailer = 0;
		return FALSE;
	}
	memcpy(pTask,&g_memc_tasks_queue[g_memc_tasks_tailer],sizeof(SCALER_MEMC_TASK_T));
	g_memc_tasks_tailer = (g_memc_tasks_tailer + 1) % MEMC_TASK_MAX_CNT;

	return TRUE;
}

void ScalerMEMC_TasksHandler(VOID)
{
	return;
	SCALER_MEMC_TASK_T task;
	int task_cnt = 0;

	/*resolve all tasks in the queue*/
	while(task_cnt < MEMC_TASK_MAX_CNT && ScalerMEMC_PopTask(&task) == TRUE){
		switch(task.type){
		case SCALERIOC_MEMC_SETMOTIONCOMP:
		{
			LogPrintf(DBG_MSG, "[SETMOTIONCOMP]%d,%d,%d\n",\
						task.data.memc_set_motion_comp.blurLevel,\
						task.data.memc_set_motion_comp.judderLevel,\
						task.data.memc_set_motion_comp.motion);
			Scaler_MEMC_SetMotionComp(task.data.memc_set_motion_comp.blurLevel,\
						task.data.memc_set_motion_comp.judderLevel,\
						task.data.memc_set_motion_comp.motion);
		}
		break;

		case SCALERIOC_MEMC_SETBLURLEVEL:
		{
			LogPrintf(DBG_MSG, "[SETBLURLEVEL]%d\n",task.data.value);
			Scaler_MEMC_SetBlurLevel(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_SETJUDDERLEVEL:
		{
			LogPrintf(DBG_MSG, "[SETJUDDERLEVEL]%d\n",task.data.value);
			Scaler_MEMC_SetJudderLevel(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_MOTIONCOMPONOFF:
		{
			LogPrintf(DBG_MSG, "[MOTIONCOMPONOFF]%d\n",task.data.value);
			Scaler_MEMC_MotionCompOnOff(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_LOWDELAYMODE:
		{
			LogPrintf(DBG_MSG, "[LOWDELAYMODE]%d\n",task.data.value);
			Scaler_MEMC_LowDelayMode(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_SETRGBYUVMode:
		{
			LogPrintf(DBG_MSG, "[SETRGBYUVMode]%d\n",task.data.value);
			Scaler_MEMC_SetRGBYUVMode(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_GETFRAMEDELAY:
		{
			LogPrintf(DBG_MSG, "[GETFRAMEDELAY]\n");
			//Scaler_MEMC_GetFrameDelay ((UINT16 *)arg);
		}
		break;

		case SCALERIOC_MEMC_SETVIDEOBLOCK:
		{
			LogPrintf(DBG_MSG, "[SETMOTIONCOMP]%d,%d\n",\
							task.data.memc_set_video_block.type,\
							task.data.memc_set_video_block.bOnOff);
			Scaler_MEMC_SetVideoBlock(task.data.memc_set_video_block.type,\
							task.data.memc_set_video_block.bOnOff);
		}
		break;

		case SCALERIOC_MEMC_SETTRUEMOTIONDEMO:
		{
			LogPrintf(DBG_MSG, "[SETTRUEMOTIONDEMO]%d\n",task.data.value);
			Scaler_MEMC_SetTrueMotionDemo(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_GETFIRMWAREVERSION:
		{
			LogPrintf(DBG_MSG, "[GETFIRMWAREVERSION]%d\n",task.data.value);
			//Scaler_MEMC_GetFirmwareVersion((UINT16 *)arg);
		}
		break;

		case SCALERIOC_MEMC_SETBYPASSREGION:
		{
			LogPrintf(DBG_MSG, "[SETBYPASSREGION]%d,%d,%d,%d,%d,%d\n",\
							task.data.memc_set_bypass_region.bOnOff,\
							task.data.memc_set_bypass_region.region,\
							task.data.memc_set_bypass_region.x,\
							task.data.memc_set_bypass_region.y,\
							task.data.memc_set_bypass_region.w,\
							task.data.memc_set_bypass_region.h);
			Scaler_MEMC_SetBypassRegion(task.data.memc_set_bypass_region.bOnOff,\
							task.data.memc_set_bypass_region.region,\
							task.data.memc_set_bypass_region.x,\
							task.data.memc_set_bypass_region.y,\
							task.data.memc_set_bypass_region.w,\
							task.data.memc_set_bypass_region.h);
		}
		break;

		case SCALERIOC_MEMC_SETREVERSECONTROL:
		{
			LogPrintf(DBG_MSG, "[SETREVERSECONTROL]%d\n",task.data.value);
			Scaler_MEMC_SetReverseControl(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_FREEZE:
		{
			LogPrintf(DBG_MSG, "[FREEZE]%d\n",task.data.value);
			Scaler_MEMC_Freeze(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_SETDEMOBAR:
		{
			LogPrintf(DBG_MSG, "[SETDEMOBAR]%d,%d,%d,%d\n",\
						task.data.memc_set_demo_bar.bOnOff,\
						task.data.memc_set_demo_bar.r,\
						task.data.memc_set_demo_bar.g,\
						task.data.memc_set_demo_bar.b);
			Scaler_MEMC_SetDemoBar(task.data.memc_set_demo_bar.bOnOff,\
						task.data.memc_set_demo_bar.r,\
						task.data.memc_set_demo_bar.g,\
						task.data.memc_set_demo_bar.b);
		}
		break;

		case SCALERIOC_MEMC_SETINOUTUSECASE:
		{
			LogPrintf(DBG_MSG, "[SETINOUTUSECASE]%d,%d,%d,%d\n",\
							task.data.memc_set_inout_usecase.input_re,\
							task.data.memc_set_inout_usecase.output_re,\
							task.data.memc_set_inout_usecase.input_for,\
							task.data.memc_set_inout_usecase.output_for);
			Scaler_MEMC_SetInOutputUseCase(task.data.memc_set_inout_usecase.input_re,\
							task.data.memc_set_inout_usecase.output_re,\
							task.data.memc_set_inout_usecase.input_for,\
							task.data.memc_set_inout_usecase.output_for);
		}
		break;

		case SCALERIOC_MEMC_SETINPUTOUTPUTFORMAT:
		{
			LogPrintf(DBG_MSG, "[SETINPUTOUTPUTFORMAT]%d,%d\n",\
							task.data.memc_set_inout_format.input_for,\
							task.data.memc_set_inout_format.output_for);
			Scaler_MEMC_SetInputOutputFormat(task.data.memc_set_inout_format.input_for,\
							task.data.memc_set_inout_format.output_for);
		}
		break;

		case SCALERIOC_MEMC_SETINPUTOUTPUTRESOLUTION:
		{
			LogPrintf(DBG_MSG, "[SETINPUTOUTPUTRESOLUTION]%d,%d\n",\
							task.data.memc_set_inout_resolution.input_re,\
							task.data.memc_set_inout_resolution.output_re);
			Scaler_MEMC_SetInputOutputResolution(task.data.memc_set_inout_resolution.input_re,\
							task.data.memc_set_inout_resolution.output_re);
		}
		break;

		case SCALERIOC_MEMC_SETINOUTPUTFRAMERATE:
		{
			LogPrintf(DBG_MSG, "[SETINOUTPUTFRAMERATE]%d,%d\n",\
					task.data.memc_inout_framerate.input_frame_rate,\
					task.data.memc_inout_framerate.output_frame_rate);
			Scaler_MEMC_SetInputFrameRate(task.data.memc_inout_framerate.input_frame_rate);
			Scaler_MEMC_SetOutputFrameRate(task.data.memc_inout_framerate.output_frame_rate);
		}
		break;

		case SCALERIOC_MEMC_SETMEMCFRAMEREPEATENABLE:
		{
			LogPrintf(DBG_MSG, "[SETMEMCFRAMEREPEATENABLE]%d\n",task.data.value);
			Scaler_MEMC_SetMEMCFrameRepeatEnable(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_SETMEMCINOUTMODE:
		{
			LogPrintf(DBG_MSG, "[SETMEMCINOUTMODE]%d\n",task.data.value);
			ISR_Scaler_MEMC_SetInOutMode(task.data.value);
		}
		break;

		case SCALERIOC_MEMC_SETCINEMAMODE:
		{
			LogPrintf(DBG_MSG, "[SETCINEMAMODE]%d\n",task.data.value);
			Scaler_MEMC_SetCinemaMode(task.data.value);
		}
		break;

		default:
			LogPrintf(DBG_MSG, "[%s]Unknown task type=%d(header=%d,tailer=%d)\n",\
				__FUNCTION__,task.type,g_memc_tasks_header,g_memc_tasks_tailer);
			return;
		}//~switch(task.type)
		task_cnt++;
	}//~while(task_cnt < MEMC_TASK_MAX_CNT && ScalerMEMC_PopTask(&task)
	if(task_cnt == MEMC_TASK_MAX_CNT){
		LogPrintf(DBG_WARNING, "[%s]Queue lenght maybe too small(header=%d,tailer=%d,max_tasks_num=%d)\n",\
			__FUNCTION__,g_memc_tasks_header,g_memc_tasks_tailer,MEMC_TASK_MAX_CNT);
	}
}

#endif

