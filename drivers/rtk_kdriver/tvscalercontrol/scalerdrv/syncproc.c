/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * The file is a declaration and definition header file
 *
 * @author 	$Author:  $
 * @date 	$Date:  $
 * @version 	$Revision:  $
 * @ingroup
 */

 /**
 * @addtogroup
 * @{
 */
//Kernel Header file
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/semaphore.h>

//RBUS Header file
#include <rbus/adc_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/sync_processor_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/auto_soy_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/offms_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <scalercommon/scalerCommon.h>

//Tvscalercontrol Header file
#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scalerdrv/syncproc.h"
#include "tvscalercontrol/scalerdrv/scalerclock.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include "tvscalercontrol/scalerdrv/adjust.h"
#include "tvscalercontrol/scalerdrv/auto.h"
#include "tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h"
#include <tvscalercontrol/scalerdrv/framesync.h>
#include "tvscalercontrol/vdc/video.h"
#include "tvscalercontrol/adcsource/ypbpr.h"
#include "tvscalercontrol/adcsource/vga.h"
#include <tvscalercontrol/panel/panelapi.h>


#ifdef ENABLE_DRIVER_I3DDMA
	#include "tvscalercontrol/i3ddma/i3DDMA_Drv.h"
#endif

#include <mach/rtk_log.h>
#define TAG_NAME_ADC "ADC"

static StructUpDnClamp YPP_UpDnClamp[] = {
	{_MODE_480I,0xae,0x7c,0xad},
	{_MODE_480P,0x58,0x3e,0x57},
	{_MODE_576I,0xc8,0x7d,0xc7},
	{_MODE_576P,0x62,0x40,0x61},
	//{_MODE_720P25,0x5e,0x1d,0x5d},
	//{_MODE_720P30,0x5e,0x1d,0x5d},
	{_MODE_720P50,0x5e,0x1d,0x5d},
	{_MODE_720P60,0x5e,0x1d,0x5d},
	{_MODE_1080I25,0x47,0x20,0x46},
	{_MODE_1080I30,0x47,0x20,0x46},
	{_MODE_1080P23,0x47,0x20,0x46},
	{_MODE_1080P24,0x47,0x20,0x46},
	{_MODE_1080P25,0x47,0x20,0x46},
	{_MODE_1080P29,0x47,0x20,0x46},
	{_MODE_1080P30,0x47,0x20,0x46},
	{_MODE_1080P50,0x21,0x10,0x20},
	{_MODE_1080P60,0x21,0x10,0x20}
};

extern StructDisplayInfo * Get_ADC_Dispinfo(void);
extern ModeInformationType * Get_ADC_Timinginfo(void);
extern struct semaphore* get_offline_semaphore(void);
/*================= Common Function for VGA and YPbPr ================= */
/**
 * This function is used to set the soy source for specified sync processor
 *
 * @param sync_indicator: [input] sync processor1 or sync processor2
 * @param soy_source_index: [input] SOG0/SOY0 ~ SOG15/SOY15
 *
 * @return : None
 *
 */
 void SyncProc_SOYSourceSelect(unsigned char sync_indicator, unsigned char soy_source_index)
 {
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	 //sp2_ctrl_RBUS sync_processor_sp2_ctrl_reg;

	if(SYNC_PROCESSOR1 == sync_indicator)
	{
		sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
		sync_processor_sp1_ctrl_reg.s1_auto_run = 1;
		sync_processor_sp1_ctrl_reg.s1_vhs_source_sel = SP_VHS_SOURCE_SOY_0 + soy_source_index;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
	}
	else //if(SYNC_PROCESSOR2 == sync_indicator)
	{
		#if 0	//compile error @rzhen
		sync_processor_sp2_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
		sync_processor_sp2_ctrl_reg.s2_auto_run = 1;
		sync_processor_sp2_ctrl_reg.s2_vhs_source_sel = SP_VHS_SOURCE_SOY_0 + soy_source_index;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, sync_processor_sp2_ctrl_reg.regValue);
		#endif
	}
 }

/**
 * This function is used to progress the sync detection.
 *
 * @param sync_indicator: [input] sync processor 1 or sync processor2
 *
 * @return unsigned char
 * @retval 0 : NO_SIGNAL
 * @retval 1 : NOT_SUPPORT
 * @retval 2 : YPBPR_SYNC
 * @retval 3 : SERRATION_COMPOSITE_SYNC
 * @retval 4 : XOR_OR_COMPOSITE_WITH_EQUALIZER
 * @retval 5 : XOR_OR_COMPOSITE_WITHOUT_EQUALIZER
 * @retval 6 : SEPARATE_SYNC
 * @retval 7 : HSYNC_ONLY
 *
 */
static unsigned char SyncProc_TypeDetect(int src, unsigned char sync_indicator)
{//Detect sync type
	unsigned char ucCounter, ucResult, inverted = 0;
	sync_processor_sp1_ctrl_RBUS SP1_CTRL_reg;
	sync_processor_sp1_autorst_RBUS SP1_AutoRst_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_ctrl_RBUS SP2_CTRL_reg;
	//sp2_autorst_RBUS SP2_AutoRst_reg;
	// CSW+ 0960713 to solve the error in VGA/PbPr plug in/out
	// Turn off sync processor auto-measure first
	if(SYNC_PROCESSOR1 == sync_indicator)
	{
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);

		//disable Hysnc Type Detection Auto Run
		SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
		SP1_CTRL_reg.s1_auto_run = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);

		msleep(2);//frank@0507 hw setting 1ms from 20ms for Automatic reset

		//enable Hysnc Type Detection Auto Run
		SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
		SP1_CTRL_reg.s1_auto_run = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
		msleep(3); //LG fine tune delay 30->3
	}
	else// if(SYNC_PROCESSOR2 == sync_indicator)
	{
		#if 0	//compile error @rzhen
		//disable Hysnc Type Detection Auto Run
		SP2_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
		SP2_CTRL_reg.s2_auto_run = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, SP2_CTRL_reg.regValue);
		msleep(2);//frank@0507 hw setting 1ms from 20ms for Automatic reset

		//enable Hysnc Type Detection Auto Run
		SP2_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
		SP2_CTRL_reg.s2_auto_run = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, SP2_CTRL_reg.regValue);
		msleep(30);
		#endif
	}

	if(src == _SRC_VGA)
	{
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);

		msleep(5);
		//frank@0507 openauto run will turn on coast,turn-off coast will let VGA source phase change good
		if(SEPARATE_MODE == VGA_Detect_SyncTypeMode())
		{
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
			SP1_CTRL_reg.s1_coast_en = _DISABLE;
			IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
		}
		else
		{
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
			SP1_CTRL_reg.s1_coast_en = _ENABLE;
			IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
		}
	}

	ucCounter= 30; //500 ms from 100ms read protection,To prevent pattern gen for VGA timing tends from output wrong timing
	ucResult = 0;

	do{
		if(src  == _SRC_VGA)
			msleep(20);  // To prevent pattern gen for VGA timing tends from output wrong timing
		else
			msleep(1); //LG fine tune delay

		//check whether Hsync Type Detection Auto Run Result is ready
		if(SYNC_PROCESSOR1 == sync_indicator)
		{
			//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);

			SP1_AutoRst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_AutoRst_reg);
			ucResult = SP1_AutoRst_reg.s1_auto_result_rdy;
			inverted = SP1_AutoRst_reg.s1_input_signal_be_inverted;
		}
		else// if(SYNC_PROCESSOR2 == sync_indicator)
		{
			#if 0	//compile error @rzhen
			SP2_AutoRst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_AutoRst_reg);
			ucResult = SP2_AutoRst_reg.s2_auto_result_rdy;
			inverted = SP2_AutoRst_reg.s2_input_signal_be_inverted;
			#endif
		}
	}while((!ucResult) && (--ucCounter));

	if(inverted == 1 && src  == _SRC_YPBPR)
	{
		ucResult = NOT_SUPPORT;
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "###func:%s inverted so change to no support####\r\n", __FUNCTION__);
	}
	else if(ucCounter != 0)
	{
		//get Hsync Type Detection Auto Run Result
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		if(SYNC_PROCESSOR1 == sync_indicator)
		{
			//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			SP1_AutoRst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_AutoRst_reg);
			ucResult = SP1_AutoRst_reg.s1_auto_result;
		}
		else// if(SYNC_PROCESSOR2 == sync_indicator)
		{
			#if 0	//compile error @rzhen
			SP2_AutoRst_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_AutoRst_reg);
			ucResult = SP2_AutoRst_reg.s2_auto_result;
			#endif
		}
//		RTD_Log(LOGGER_INFO,"\n SyncProc_Detector SyncType:%x\n", ucResult);
	}
	else //measure timeout! treat as no signal
	{
		ucResult = NO_SIGNAL;
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "SyncProc_TypeDetect timeout\n");
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
	}

	return ucResult;
}

/**
 * This function is called to get the stable period.(Continue 64 times to get the same H period)
 *
 * @param indicator: [input] sync processor 1 or sync processor 2
 * @param st263xInfo->YPbPrSyncType: [output] When overflow or stable period change or stable polarity change, SyncType will set to SYNC_CHANGE
 *
 *
 * @return short
 * @retval result : the stable period result
 *
 * @Note : This function should be called after calling the YPbPr_SyncDetector
 *
 */
static unsigned short SyncProc_GetStablePeriod(unsigned char indicator)
 {
	sync_processor_sp1_stbctrl_RBUS sync_processor_sp1_stbctrl_reg;
	sync_processor_sp1_stbrst0_RBUS sync_processor_sp1_stbrst0_reg;
	sync_processor_sp1_stbrst1_RBUS sync_processor_sp1_stbrst1_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_stbctrl_RBUS sync_processor_sp2_stbctrl_reg;
	//sp2_stbrst0_RBUS sync_processor_sp2_stbrst0_reg;
	//sp2_stbrst1_RBUS sync_processor_sp2_stbrst1_reg;

	if(SYNC_PROCESSOR1 == indicator)
	{
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);

		//clear start measure & popup
		sync_processor_sp1_stbctrl_reg.s1_popup_stable_per = 0;
		sync_processor_sp1_stbctrl_reg.s1_stable_en = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		//stable measure start
		sync_processor_sp1_stbctrl_reg.s1_stable_en = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		msleep(30);//wait a little time

		//check HS Overflow, Stable Period Change, Stable Polarity Change
		sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
		if((sync_processor_sp1_stbrst0_reg.s1_mode_det_of) || (sync_processor_sp1_stbrst0_reg.s1_stb_per_chg) || (sync_processor_sp1_stbrst0_reg.s1_stb_pol_chg))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n HS Overflow, Stable Period Change, Stable Polarity Change");
			goto error_result;
		}

		//Pop Up Stable Value
		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_popup_stable_per = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		//Check Both polarity and period are stable
		sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
		if(FALSE == sync_processor_sp1_stbrst0_reg.s1_mode_det_stable)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n Per or pol err");
			goto error_result;
		}

		//Stable HS Period
		sync_processor_sp1_stbrst1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst1_reg);
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####Stable Period = %x\n", sync_processor_sp1_stbrst1_reg.s1_stable_period_out);
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen#####Stable Hight Pulse Period = %x\n", sync_processor_sp1_stbrst1_reg.s1_stable_plswid_out);
		return sync_processor_sp1_stbrst1_reg.s1_stable_period_out;
	}
	else// if(SYNC_PROCESSOR2 == indicator)
	{
		#if 0	//compile error @rzhen
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);

		//clear start measure & popup
		sync_processor_sp2_stbctrl_reg.s2_popup_stable_per = 0;
		sync_processor_sp2_stbctrl_reg.s2_stable_en = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		//stable measure start
		sync_processor_sp2_stbctrl_reg.s2_stable_en = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		msleep(30);

		//check HS Overflow, Stable Period Change, Stable Polarity Change
		sync_processor_sp2_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbRst0_reg);
		if((sync_processor_sp2_stbrst0_reg.s2_mode_det_of) || (sync_processor_sp2_stbrst0_reg.s2_stb_per_chg) || (sync_processor_sp2_stbrst0_reg.s2_stb_pol_chg))
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n HS Overflow, Stable Period Change, Stable Polarity Change");
			goto error_result;
		}

		//Pop Up Stable Value
		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_popup_stable_per = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		//Check Both polarity and period are stable
		sync_processor_sp2_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbRst0_reg);
		if(FALSE == sync_processor_sp2_stbrst0_reg.s2_mode_det_stable)
		{
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n Per or pol err");
			goto error_result;
		}

		//Stable HS Period
		sync_processor_sp2_stbrst1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbRst1_reg);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n Stable Period = %x\n", sync_processor_sp2_stbrst1_reg.s2_stable_period_out);
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n Stable Hight Pulse Period = %x\n", sync_processor_sp2_stbrst1_reg.s2_stable_plswid_out);
		return sync_processor_sp2_stbrst1_reg.s2_stable_period_out;
		#endif
	}

	error_result:
//	sys_MessagePush(info->display?_MODE_MSG_SUB_DETECT_SIGNAL: _MODE_MSG_MAIN_DETECT_SIGNAL);
	return 0;
 }

/**
 * This function is called to set the VSync counter level
 *
 * @param indicator: [input] sync processor1 or sync processor2
 *
 * @return None
 *
 */
static unsigned char SyncProc_SetVsyncCounterLevel(unsigned char indicator)
{
	unsigned short result = 0;
	sync_processor_sp1_dcnt_RBUS  sync_processor_sp1_dcnt_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_dcnt_RBUS sync_processor_sp2_dcnt_reg;
	//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
	result = SyncProc_GetStablePeriod(indicator);

	if(result == 0)
		return _MODE_NOSUPPORT;

	//frank@0529 the below formula is the tuning result of the vsync count level for any timing
	result = (result >> 3) + 150;

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] Vsyn Level = 0x%08x #####\n", __func__, __LINE__, result);

	if(SYNC_PROCESSOR1 == indicator)
	{
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		sync_processor_sp1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		sync_processor_sp1_dcnt_reg.s1_dcnt_level = result;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, sync_processor_sp1_dcnt_reg.regValue);
	}
	else //if(SYNC_PROCESSOR2 == indicator)
	{
		#if 0	//compile error @rzhen
		sync_processor_sp2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		sync_processor_sp2_dcnt_reg.s2_dcnt_level = result;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, sync_processor_sp2_dcnt_reg.regValue);
		#endif
	}

	return _MODE_SUCCESS;
}

/**
 * This API is used to Adaptive compare level backward/forward search for Sync type
 *
 * @param [SyncProcessor] : which syncprocessor
 * @param [usCompareLevel] : compare level
 * @param [usAdaptiveStep] : the step of active
 * @param [usAdaptiveCnt] : the count of step
 * @param [result] : the pre result
 * @param [output] :
 * @return unsigned char :the sync type
 *
 */
static unsigned char Adaptive_SyncProc_Detector(int src, unsigned char SyncProcessor, unsigned char usCompareLevel, unsigned char usAdaptiveStep, unsigned char usAdaptiveCnt, unsigned char result)
{
	unsigned char usAdaptiveCompareLevel=usCompareLevel; // compare level
	unsigned char result_ret=result;

	if ((result > HSYNC_ONLY)||(result < YPBPR_SYNC)) // No Sync type found
	{
		// Backward compare level
		usAdaptiveCompareLevel = usCompareLevel - usAdaptiveStep*usAdaptiveCnt;

		// Step 1. Set compare level first
		if(src == _SRC_YPBPR)//<Stanley 080625> Only be execute by YPbPr
			YPbPr_SetSOYCompareLevel(YPBPR_SOY_PATH_SELECT, usAdaptiveCompareLevel);
		else if((_ENABLE == Scaler_Get_VGA_Support_SOG()) && (_SRC_VGA == src))
			VGA_SetSOGCompareLevel(VGA_SOG_PATH_SELECT, usAdaptiveCompareLevel);


		msleep(5);

		// Step 2. Run Sync processor to detect sync type
		result_ret = SyncProc_TypeDetect(src, SyncProcessor);

		if ((result_ret > HSYNC_ONLY)||(result_ret < YPBPR_SYNC)){ // No Sync type found
			// Forward compare level
			usAdaptiveCompareLevel = usCompareLevel + usAdaptiveStep*usAdaptiveCnt;

			// Step 1. Set compare level first
			//<Stanley 080312>Modify by stanley, do not write to register directly, need to write to register by driver.
			if(src == _SRC_YPBPR)
				YPbPr_SetSOYCompareLevel(YPBPR_SOY_PATH_SELECT, usAdaptiveCompareLevel);
			else if((_ENABLE == Scaler_Get_VGA_Support_SOG()) && (src == _SRC_VGA))
				VGA_SetSOGCompareLevel(VGA_SOG_PATH_SELECT, usAdaptiveCompareLevel);

			msleep(5);

			// Step 2. Run Sync processor to detect sync type
			result_ret = SyncProc_TypeDetect(src, SyncProcessor);

			if ((result_ret <= HSYNC_ONLY)&&(result_ret >= YPBPR_SYNC))
				rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n 3. Find Sync type in the compare level %x !!", usAdaptiveCompareLevel);
		}
		else
			rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n 2. Find Sync type in the compare level %x !!", usAdaptiveCompareLevel);
	}
	else
		rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "n 1. Find Sync type in the compare level %x !!", usAdaptiveCompareLevel);

	return result_ret;
}

/**
 * This API is used to Adaptive compare level for Sync type search
 *
 * @param [ucTempSync] : sync type
 * @param [output] :
 * @return unsigned char :the compare sync type
 *
 */
static unsigned char SyncProc_Adaptive_Compare_Level(int src, unsigned char ucTempSync,unsigned char SyncProcessor)
{
	unsigned char usCompareLevel=0x16; // 1st compare level = 16
	unsigned char usAdaptiveStep=4; // Adaptive step
	unsigned char static usAdaptiveCount=0; // loop counter
	unsigned char result_ret=ucTempSync;

	//---------------
	// modify by linmc
	// for reducing detection timg in no signal state
	// 2008.11.12
	//---------------
	usAdaptiveCount++;
	result_ret = Adaptive_SyncProc_Detector(src, SyncProcessor, usCompareLevel, usAdaptiveStep, usAdaptiveCount, result_ret);

	if ((result_ret < HSYNC_ONLY)&&(result_ret >= YPBPR_SYNC)) // Sync type found
		usAdaptiveCount = 0;
	else if (usAdaptiveCount > 4)
		usAdaptiveCount = 0;

	return result_ret;
}

/**
 * This API is used to know whether current sync status is a valid sync
 * Here we support the YPBPR_SYNC, SERRATION_COMPOSITE_SYNC and XOR_OR_COMPOSITE_WITHOUT_EQUALIZER
 *
 * @param [input] : None
 *
 * @return unsigned char
 * @retval TRUE : sync is valid
 * @retval FALSE : sync is non valid
 */
unsigned char SyncProc_SyncHandler(int src)
{
	unsigned char ucTempSync;
	sync_processor_sp1_stbrst0_RBUS sync_processor_sp1_stbrst0_reg;

	ucTempSync = SyncProc_TypeDetect(src, SYNC_PROCESSOR1);//Detect sync type

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####[%s(%d)] Detected signal-0 => %x\n", __FUNCTION__, __LINE__, ucTempSync);

	if(_ENABLE == Scaler_Get_VGA_Support_SOG() && src == _SRC_VGA)
	{
		//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		//lewis 20090309, only SOG timing need compare level
		if(SOG_MODE == VGA_Detect_SyncTypeMode()){
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			ucTempSync = SyncProc_Adaptive_Compare_Level(src, ucTempSync, SYNC_PROCESSOR1);
		}
	}


	if(_DISABLE == Scaler_Get_YPbPr_Auto_Soy_Enable() && src == _SRC_YPBPR)
	{
		rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
		ucTempSync = SyncProc_Adaptive_Compare_Level(src, ucTempSync, SYNC_PROCESSOR1);
	}


	switch(ucTempSync)
	{
		case YPBPR_SYNC:
		case SERRATION_COMPOSITE_SYNC:
		case XOR_OR_COMPOSITE_WITHOUT_EQUALIZER:
		case XOR_OR_COMPOSITE_WITH_EQUALIZER:
		case SEPARATE_SYNC:
			//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] ucTempSync=%d #####\n", __func__, __LINE__, ucTempSync);

			if((ucTempSync == XOR_OR_COMPOSITE_WITHOUT_EQUALIZER) || (ucTempSync == XOR_OR_COMPOSITE_WITH_EQUALIZER))
			{//WOSQRTK-4614 patch 20160108
				sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
				sync_processor_sp1_stbrst0_reg.s1_cap_unlock_no_vs = 1;
				IoReg_Write32(SYNC_PROCESSOR_SP1_StbRst0_reg, sync_processor_sp1_stbrst0_reg.regValue);
				msleep(1);
				sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
				if(sync_processor_sp1_stbrst0_reg.s1_cap_unlock_no_vs == 1) {
					rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### [%s(%d)] vsync non standard so change to no support####\n", __func__, __LINE__);
					return _MODE_NOSUPPORT;
				}

			}
			//RTD_Log(LOGGER_INFO,"\nYPbPr Detected signal-1 => %x\n",ucTempSync);
			if(_ENABLE == Scaler_Get_VGA_Support_Composite_Sync())
			{
				//[Code Sync][AlanLi][0980403][1]
				//VGA support composite sync
				//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
				if(src == _SRC_VGA)
				{
					rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
					if(SEPARATE_MODE == VGA_Detect_SyncTypeMode())
					{
						rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
						if(SEPARATE_SYNC != ucTempSync){
							rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
							return _MODE_NOSUPPORT;	//return _MODE_NOSIGNAL;
						}
					}
					else// if(SEPARATE_MODE != VGA_Detect_SyncTypeMode())
					{
						rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
						if(SEPARATE_SYNC == ucTempSync){
							rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
							return _MODE_NOSUPPORT;	//return _MODE_NOSIGNAL;
						}
					}
				}
				//[Code Sync][AlanLi][0980403][1][end]
			}
			//RTD_Log(LOGGER_INFO,"\nYPbPr Detected signal-2 => %x\n",ucTempSync);
			return SyncProc_SetVsyncCounterLevel(SYNC_PROCESSOR1); //set the Vsync counter level to separate the Vsync
		break;

		case NO_SIGNAL:
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			return _MODE_NOSIGNAL;
		break;

		case NOT_SUPPORT:
		case HSYNC_ONLY:
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			return _MODE_NOSUPPORT; //sync is detected, but not the YPbPr valid sync, treat as no support
		break;

		default:
			rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] #####\n", __func__, __LINE__);
			return _MODE_NOCABLE;
		break;
	}

	/* detect success */
	return _MODE_SUCCESS;
}



/**
 * This API is used to adjust adc clock
 *
 * @param [display] : main or sub channel
 * @param [fast_lock_enable] : fask clock enable or not
 *
 * @return : none
 */
void Adjust_ADC_Clock(unsigned char display, unsigned char fast_lock_enable)
{
	UINT8 ucChangeFramesyncStatusFlag = _FALSE;
	
	StructDisplayInfo *p_dispinfo;
	p_dispinfo = Get_ADC_Dispinfo();
	
	//Mantis bug number = [common] 0043004
	//How : [OSD]OSD flashing occur when User setting operate.
	//Why : because porch is not enough, Maybe in change clock have garbage
	//What : let it free run during change clock

	//USER:LewisLee DATE:2012/07/23
	//to prevent some VGA timing (Ex : 800x600x60Hz), the porch is not enough
	//we change position, have garbage

	if(SLR_MAIN_DISPLAY == display)
	{
		if(!GET_AUTO_CONFIG_DOING())
		{
			if(_FALSE == framesync_get_enterlastline_at_frc_mode_flg())
			{
				if(_FALSE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC))
				{
					if(_MODE_STATE_ACTIVE == Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE))
					{
						if(DISPLAY_MODE_FRAME_SYNC == drvif_scaler_get_display_mode())
						{
							ucChangeFramesyncStatusFlag = _TRUE;
							drvif_scaler_set_display_mode(DISPLAY_MODE_FRC);
						}
					}
				}
			}
		}
	}

	rtd_printk(KERN_NOTICE, TAG_NAME_ADC,"#####[%s(%d)] p_dispinfo->INPUT_ADC_CLOCK=%d\n", __FUNCTION__, __LINE__, p_dispinfo->INPUT_ADC_CLOCK);
	drvif_clock_set_aclk(p_dispinfo, _SRC_VGA,  p_dispinfo->INPUT_ADC_CLOCK, FALSE);
	//mark by frank@0509  msleep(20);
}

unsigned char SyncProc_OffMeasure(int src, unsigned char OfflineSrcType)//This is for YPP and VGA offline measure
 {
	unsigned char result = _MODE_NOSIGNAL;
	StructDisplayInfo *p_adcdispinfo;
	ModeInformationType *p_adctiminginfo;
	unsigned short timingmodeindex;
	p_adcdispinfo = Get_ADC_Dispinfo();
	p_adctiminginfo = Get_ADC_Timinginfo();
	timingmodeindex = p_adcdispinfo->ucMode_Table_Index;

	down(get_offline_semaphore());
	if (drvif_mode_offlinemeasure(OfflineSrcType, ANALOG_MODE_MEASUREMENT, p_adcdispinfo, p_adctiminginfo) != _MODE_SUCCESS) {
		up(get_offline_semaphore());
		goto error_result;
	}
	up(get_offline_semaphore());

	result = mode_searchmodetable(src, p_adcdispinfo, p_adctiminginfo);

	//rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####rzhen##### [%s(%d)] result = 0x%08x#####\n", __func__, __LINE__, result);

#if TEST_PATTERN_GEN
	result = _MODE_SUCCESS;
#endif

	if ((result != _MODE_NOSUPPORT) && (result != _MODE_NOSIGNAL)) {
		p_adcdispinfo->ucMode_Table_Index = result;
		if	(p_adcdispinfo->ucMode_Table_Index != timingmodeindex) {
			mode_set_dispinfo_from_table(src, p_adcdispinfo, p_adctiminginfo);
		}
	}
	else
		goto error_result;

	return _MODE_SUCCESS;

error_result:
	SyncProc_FunctionDisable(src);

	return result;
 }





/**
 * This API is used to get the VGIP active window information and handle the mode setting
 *
 * @param [input] : None
 * @param [output] : None
 *
 *
 * @return : result
 * @retval  TRUE : detect a valid mode and progress the mode setting
 * @retval FALSE : no valid mode is detected
 */
 unsigned char SyncProc_TimingModeHandler(int src, StructSourceInput *srcinput_pt)
 {
	unsigned char result = 0;

	switch(src)
	{
		case _SRC_YPBPR:
			result = SyncProc_OffMeasure(src, _OFFLINE_MS_SRC_DEHV1);
			break;

		case _SRC_VGA:
			if((_ENABLE == Scaler_Get_VGA_Support_SOG()) || (_ENABLE == Scaler_Get_VGA_Support_Composite_Sync()))
			{
				//lewis, only separate sync off-line measure is _OFFLINE_MS_SRC_RAWHV1
				if(SEPARATE_MODE == VGA_Detect_SyncTypeMode())
				{
					result = SyncProc_OffMeasure(src, _OFFLINE_MS_SRC_RAWHV1);
					rtd_printk(KERN_INFO, TAG_NAME_ADC, "###### [%s(%d)] result = 0x%08x#####\n", __func__, __LINE__, result);
				}
				else
				{
					result = SyncProc_OffMeasure(src, _OFFLINE_MS_SRC_DEHV1);
					rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### [%s(%d)] result = 0x%08x#####\n", __func__, __LINE__, result);
				}
			}
			else
			{
				result = SyncProc_OffMeasure(src, _OFFLINE_MS_SRC_RAWHV1);
				rtd_printk(KERN_INFO, TAG_NAME_ADC, "##### [%s(%d)] result = 0x%08x#####\n", __func__, __LINE__, result);
			}
			break;

		default:
			return _MDOE_UNDKOWN;
			break;
	}
	return result;
 }


/**
 * This API is used to check the signal is stable
 *
 * @param [input] : None
 * @param [output] :
 * @return unsigned char
 * @check success: TRUE
 * @check fail       : FALSE
 */
 /*
unsigned char SyncProc_CheckMode(void)
{
	if(!drvif_mode_onlinemeasure(ANALOG_MODE_MEASUREMENT)){
		printk(KERN_DEBUG "nSyncProcCheckModeChange\n");
		return  FALSE;
	}
	return TRUE;
}
*/

/*================= Sync Proc Callback Function ================= */

/**
 * This API is used to init src setting according  VGA, YPbPr, DVI,...
 * @param [input] : input src type
 * @param [output] : None.

 * @return None
 */

void YPbPr_SyncProc(void)
{
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	sync_processor_sp1_stbctrl_RBUS sync_processor_sp1_stbctrl_reg;
	sync_processor_sp1_clmpmsk_RBUS  sync_processor_sp1_clmpmsk_reg;
	sync_processor_sp1_dcnt_RBUS  SP1_dcnt_reg;
#if (YPBPR_SP_PATH != SYNC_PROCESSOR1)
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_dcnt_RBUS SP2_dcnt_reg;
	//sp2_clmpmsk_RBUS sync_processor_sp2_clmpmsk_reg;
	//sp2_ctrl_RBUS sync_processor_sp2_ctrl_reg;
	//sp2_stbctrl_RBUS sync_processor_sp2_stbctrl_reg;
#endif

#ifdef CONFIG_INPUT_SOURCE_IPG
	// Due to IPG will use DDS_PLL_DDS_MIX_W2_reg as 0x000002a1;
	// and it also impact the default value of other sources.
	IoReg_Write32(DDS_PLL_DDS_MIX_W2_reg, 0x000002a0);  // Delay chain select (Default value))
#endif

#if (YPBPR_SP_PATH == SYNC_PROCESSOR1)
		sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
		//De-Composite HS out in CS mode
		sync_processor_sp1_ctrl_reg.s1_dehs_out_en = 1;
		sync_processor_sp1_ctrl_reg.s1_hsraw_inv = 0;
		sync_processor_sp1_ctrl_reg.s1_hs_sync_source = YPBPR_HSYNC_SRC;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);

		sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_INIT;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_range = YPBPR_CAP_WIN_RANGE_INIT;
		sync_processor_sp1_stbctrl_reg.s1_per_range = YPBPR_PER_RANGE_TOLERANCE_INIT;
		sync_processor_sp1_stbctrl_reg.s1_popup_stable_per = 0;
		sync_processor_sp1_stbctrl_reg.s1_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		sync_processor_sp1_stbctrl_reg.s1_miss_lock_limit = YPBPR_MISS_LOCK_LIMIT_INIT;
		sync_processor_sp1_stbctrl_reg.s1_stable_en = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

		SP1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
		SP1_dcnt_reg.s1_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, SP1_dcnt_reg.regValue);

		sync_processor_sp1_clmpmsk_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CLMPMSK_reg);
		sync_processor_sp1_clmpmsk_reg.s1_mask_clamp_en = _ENABLE;
		sync_processor_sp1_clmpmsk_reg.s1_mask_front = 2;
		sync_processor_sp1_clmpmsk_reg.s1_mask_back = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPMSK_reg, sync_processor_sp1_clmpmsk_reg.regValue);

#else// if(SYNC_PROCESSOR2 == YPBPR_SP_PATH)
		#if 0	//compile error @rzhen
		sync_processor_sp2_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
		//De-Composite HS out in CS mode
		sync_processor_sp2_ctrl_reg.s2_dehs_out_en = 1;
		sync_processor_sp2_ctrl_reg.s2_hsraw_inv = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, sync_processor_sp2_ctrl_reg.regValue);

		sync_processor_sp2_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_StbCtrl_reg);
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range_lsb = YPBPR_CAP_WIN_RANGE_LSB_INIT;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_range = YPBPR_CAP_WIN_RANGE_INIT;
		sync_processor_sp2_stbctrl_reg.s2_per_range = YPBPR_PER_RANGE_TOLERANCE_INIT;
		sync_processor_sp2_stbctrl_reg.s2_popup_stable_per = 0;
		sync_processor_sp2_stbctrl_reg.s2_cap_win_step = YPBPR_CAP_WIN_SETP_INIT;
		sync_processor_sp2_stbctrl_reg.s2_miss_lock_limit = YPBPR_MISS_LOCK_LIMIT_INIT;
		sync_processor_sp2_stbctrl_reg.s2_stable_en = 0;
		IoReg_Write32(SYNC_PROCESSOR_SP2_StbCtrl_reg, sync_processor_sp2_stbctrl_reg.regValue);

		SP2_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_dcnt_reg);
		SP2_dcnt_reg.s2_deb_num = YPBPR_CHROMA_DEBOUNCE_NUM_INIT;
		IoReg_Write32(SYNC_PROCESSOR_SP2_dcnt_reg, SP2_dcnt_reg.regValue);

		sync_processor_sp2_clmpmsk_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CLMPMSK_reg);
		sync_processor_sp2_clmpmsk_reg.s2_mask_clamp_en = _ENABLE;
		sync_processor_sp2_clmpmsk_reg.s2_mask_front = 2;
		sync_processor_sp2_clmpmsk_reg.s2_mask_back = 1;
		IoReg_Write32(SYNC_PROCESSOR_SP2_CLMPMSK_reg, sync_processor_sp2_clmpmsk_reg.regValue);
		#endif
#endif
	SyncProc_SOYSourceSelect(YPBPR_SP_PATH, YPBPR_SOY_PATH_SELECT); //select the soy source SOG1
	rtd_printk(KERN_DEBUG, TAG_NAME_ADC, "YPbPr in SyncProc_InitSrc\n");
}

//USER:LewisLee DATE:2010/06/24
//to modify Hsync schmitt trigger level
//for abnormal signal
void SyncProc_adc_hs_schmitt_trigger_ctrl(void)
{
	adc_ahs_smt_ctrl_RBUS ahs_smt_ctrl_reg;

	if(HSYNC0_MODE == HSYNC0_MODE_NEW)
	{
		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_3ven = 1; // 1: Normal
		ahs_smt_ctrl_reg.hsync0_pol = HSYNC0_POL;
		ahs_smt_ctrl_reg.hsync0_mode = HSYNC0_MODE;
		ahs_smt_ctrl_reg.hsync0_vos = HSYNC0_VOS;
		ahs_smt_ctrl_reg.hsync0_vtp_1_0 = HSYNC0_VTP;
		ahs_smt_ctrl_reg.hsync0_vtn_1_0 = HSYNC0_VTN;
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
	}
	else// if(HSYNC0_MODE == HSYNC0_MODE_OLD)
	{
		ahs_smt_ctrl_reg.regValue = IoReg_Read32(ADC_AHS_SMT_CTRL_reg);
		ahs_smt_ctrl_reg.hsync0_3ven = 0; // 0: Power down (Default)
		ahs_smt_ctrl_reg.hsync0_pol = HSYNC0_POL;
		ahs_smt_ctrl_reg.hsync0_mode = HSYNC0_MODE;
		ahs_smt_ctrl_reg.hsync0_vos = HSYNC0_VOS;
		ahs_smt_ctrl_reg.hsync0_vtp_1_0 = HSYNC0_VTP;
		ahs_smt_ctrl_reg.hsync0_vtn_1_0 = HSYNC0_VTN;
		IoReg_Write32(ADC_AHS_SMT_CTRL_reg, ahs_smt_ctrl_reg.regValue);
	}
}

/**
 * This API ADCSelectInput is used to Check ADC YPbPr/VGA Data input from input0 or input1 then set the relative setting
 * @param [ptOptions] : input path
 * @param [output] : None.

 * @return None
 */
void ADCSelectInput(int src, ADC_DATA_PATH adc_path, ADC_SOY_PATH soy_path, ADC_PATH_SWAP swap_path)
{
	adc_adc_clkgen_rgb_capture_RBUS adc_adc_clkgen_rgb_capture_reg;
	adc_adc_ctl_rgb12_RBUS adc_adc_ctl_rgb12_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	sync_processor_sp_adcclampsel0_RBUS  sp_adcclampsel0_reg;

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "#####[%s(%d)] (%d %d %d %d)\n", __FUNCTION__, __LINE__, src, adc_path, soy_path, swap_path);
	if (src == _SRC_VGA)
	{
		if(_ENABLE == Scaler_Get_VGA_Support_SOG())
		{
			if(SOG_MODE == VGA_Detect_SyncTypeMode())
			{
				sp_adcclampsel0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_ADCClampSel0_reg);
				sp_adcclampsel0_reg.adc_vin32_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin31_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin30_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin22_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin21_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin20_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin12_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin02_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin01_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin00_clamp_sel = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP_ADCClampSel0_reg, sp_adcclampsel0_reg.regValue);

				SyncProc_adc_hs_schmitt_trigger_ctrl();
			}
			else
			{
				sp_adcclampsel0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_ADCClampSel0_reg); //*** 1064
				sp_adcclampsel0_reg.adc_vin32_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin31_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin30_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin22_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin21_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin20_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin12_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin02_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin01_clamp_sel = 0;
				sp_adcclampsel0_reg.adc_vin00_clamp_sel = 0;

				if(ADC_DATA_INPUT1 == adc_path){
					sp_adcclampsel0_reg.adc_vin10_clamp_sel = 1;
					sp_adcclampsel0_reg.adc_vin12_clamp_sel = 1;
				}

				IoReg_Write32(SYNC_PROCESSOR_SP_ADCClampSel0_reg, sp_adcclampsel0_reg.regValue);

				SyncProc_adc_hs_schmitt_trigger_ctrl();
			}
		}
		else
		{
			sp_adcclampsel0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP_ADCClampSel0_reg);
			sp_adcclampsel0_reg.adc_vin32_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin31_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin30_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin22_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin21_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin20_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin12_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin02_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin01_clamp_sel = 0;
			sp_adcclampsel0_reg.adc_vin00_clamp_sel = 0;

			if(ADC_DATA_INPUT1 == adc_path){
				sp_adcclampsel0_reg.adc_vin10_clamp_sel= 1;
				sp_adcclampsel0_reg.adc_vin12_clamp_sel = 1;
			}

			IoReg_Write32(SYNC_PROCESSOR_SP_ADCClampSel0_reg, sp_adcclampsel0_reg.regValue);

			SyncProc_adc_hs_schmitt_trigger_ctrl();
		}

		adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
		adc_adc_clkgen_rgb_capture_reg.adc_swap = swap_path;
		adc_adc_clkgen_rgb_capture_reg.adc_clk_inv = VGA_ADC_CLK_INV;
		IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_adc_clkgen_rgb_capture_reg.regValue);
	#if 0 //remove for new flow
		adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_6= 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_4 = 1;
		adc_adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_300M;
		IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
	#endif
		/*Default VIN4p   ADC Source Input1 adc path*/
		adc_adc_ctl_rgb12_reg.regValue = IoReg_Read32(ADC_ADC_CTL_RGB12_reg);
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_11_10= 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_9    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_8    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_7    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_6    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4  = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2  = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0  = 0;

		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10= 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_9    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_8    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_7    = 1;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_6    = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4  = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2  = 0;
		adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0  = 0;
		IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);
	}else if (src == _SRC_YPBPR){

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] soy_path = %d \n", __FUNCTION__, __LINE__, soy_path);

		//ADC MUX select
		adc_adc_ctl_rgb12_reg.regValue = IoReg_Read32(ADC_ADC_CTL_RGB12_reg);
		//frank@0220 HW SD suggest

		if(ADC_SOY_MUX_VIN4P == soy_path){

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
		}else{

			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_1_0 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_3_2 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_5_4 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_6 = 1;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_7 = 0;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_8 = 1;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_9 = 0;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb2_11_10 = 1;

			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_1_0 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_3_2 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_5_4 = 2;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_6 = 0;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_7 = 0;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_8 = 0;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_9 = 1;
			adc_adc_ctl_rgb12_reg.adc_ctl_rgb1_11_10 = 0;
		}

		IoReg_Write32(ADC_ADC_CTL_RGB12_reg, adc_adc_ctl_rgb12_reg.regValue);

		rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] adc_path = %d \n", __FUNCTION__, __LINE__, adc_path);

		sp_adcclampsel0_reg.regValue = 0;

		if(ADC_DATA_INPUT0 == adc_path){

			sp_adcclampsel0_reg.adc_vin02_clamp_sel = 0; //Y
			sp_adcclampsel0_reg.adc_vin01_clamp_sel = 0; //Y
			sp_adcclampsel0_reg.adc_vin00_clamp_sel = 0; //Y
		}else if(ADC_DATA_INPUT1 == adc_path){

			sp_adcclampsel0_reg.adc_vin12_clamp_sel = 1; //nY
			sp_adcclampsel0_reg.adc_vin11_clamp_sel = 0; //Y
			sp_adcclampsel0_reg.adc_vin10_clamp_sel = 1; //nY
		}else{

			sp_adcclampsel0_reg.adc_vin22_clamp_sel = 0; //Y
			sp_adcclampsel0_reg.adc_vin21_clamp_sel = 1; //nY
			sp_adcclampsel0_reg.adc_vin20_clamp_sel = 1; //nY
		}

		IoReg_Write32(SYNC_PROCESSOR_SP_ADCClampSel0_reg, sp_adcclampsel0_reg.regValue);

		adc_adc_clkgen_rgb_capture_reg.regValue = IoReg_Read32(ADC_ADC_CLKGEN_RGB_Capture_reg);
		adc_adc_clkgen_rgb_capture_reg.adc_swap = swap_path;
		IoReg_Write32(ADC_ADC_CLKGEN_RGB_Capture_reg, adc_adc_clkgen_rgb_capture_reg.regValue);
	}
}


//Lewis, when sync lose or detect fail, disable sp function
//to prevent system fail
void SyncProc_FunctionDisable(int src)
{
	auto_soy_soych0_a0_RBUS autosoy_soych0_a0_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS  sync_processor_sp1_ctrl_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_ctrl_RBUS sync_processor_sp2_ctrl_reg;
	StructDisplayInfo * p_dispinfo =  Get_ADC_Dispinfo();


	switch(src)
	{
		case _SRC_YPBPR:
			//ABL disable
			YPbPr_ABL_SETTING_OFF();

			if(SYNC_PROCESSOR1 == YPBPR_SP_PATH)
			{
				sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
			}
			else// if(SYNC_PROCESSOR2 == YPBPR_SP_PATH)
			{
				#if 0	//compile error @rzhen
				sync_processor_sp2_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
				sync_processor_sp2_ctrl_reg.s2_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, sync_processor_sp2_ctrl_reg.regValue);
				#endif
			}

			if(_ENABLE == Scaler_Get_YPbPr_Auto_Soy_Enable())
			{
				autosoy_soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
				autosoy_soych0_a0_reg.reg_auto_mode = 0;
				IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, autosoy_soych0_a0_reg.regValue);
			}

			if(SYNC_PROCESSOR1 == YPBPR_SP_PATH)
			{
				//disable clamp signal output
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, 0x00);
			}
			else// if(SYNC_PROCESSOR2 == YPBPR_SP_PATH)
			{
				//disable clamp signal output
				#if 0	//compile error @rzhen
				IoReg_Write32(SYNC_PROCESSOR_SP2_CLMPCTRL_reg, 0x00);
				#endif
			}

			//disable clamp
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

			//disable DC Restore
			adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
			IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

			YPbPr_SetSOY_ADC_ClockSel(p_dispinfo, SP_AUTO_SOY_CLK_SEL_INIT_STATE);



		break;

		case _SRC_VGA:
			//ABL disable
			YPbPr_ABL_SETTING_OFF();

			if(SYNC_PROCESSOR1 == VGA_SP_PATH)
			{
				sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				sync_processor_sp1_ctrl_reg.s1_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);
			}
			else// if(SYNC_PROCESSOR2 == VGA_SP_PATH)
			{
				#if 0	//compile error @rzhen
				sync_processor_sp2_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
				sync_processor_sp2_ctrl_reg.s2_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, sync_processor_sp2_ctrl_reg.regValue);
				#endif
			}

			if(SYNC_PROCESSOR1 == VGA_SP_PATH)
			{
				//disable clamp signal output
				IoReg_Write32(SYNC_PROCESSOR_SP1_CLMPCTRL_reg, 0x00);
			}
			else// if(SYNC_PROCESSOR2 == VGA_SP_PATH)
			{
				//disable clamp signal output
				#if 0	//compile error @rzhen
				IoReg_Write32(SYNC_PROCESSOR_SP2_CLMPCTRL_reg, 0x00);
				#endif
			}

			//disable clamp
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

			//disable DC Restore
			adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
			IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

		break;

		default:

		break;
	}
}

//Lewis 20081230, if not use syncprocessor function(YPbPr/VGA)
//power down the IP for reduce power consumption
void SyncProcessFunctionPowerDown(int src)
{
	auto_soy_soych0_a0_RBUS soych0_a0_reg;
	adc_adc_clamp_ctrl1_RBUS adc_adc_clamp_ctrl1_reg;
	adc_adc_dcrestore_ctrl_RBUS adc_adc_dcrestore_ctrl_reg;
	dds_pll_pll_ctrl_RBUS	pll_ctrl_reg;
	sync_processor_sp1_ctrl_RBUS  SP1_CTRL_reg;
	/*
	 * mark with rzhen_ye@realtek.com
	 * sp2_xxx no exist in sync_processor_reg.h
	 * 2016-06-03
	 */
	//sp2_ctrl_RBUS SP2_CTRL_reg;
	StructDisplayInfo * p_dispinfo =  Get_ADC_Dispinfo();

	switch(src)
	{
		case _SRC_YPBPR:
			//ABL disable
			YPbPr_ABL_SETTING_OFF();

			if(YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY0)
			{
				//Auto SOY disable
				soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
				soych0_a0_reg.reg_auto_mode = 0;
				IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, soych0_a0_reg.regValue);
			}

			if(SYNC_PROCESSOR1 == YPBPR_SP_PATH)
			{
				//Sync Processor disable
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else// if(SYNC_PROCESSOR2 == YPBPR_SP_PATH)
			{
				//Sync Processor disable
				#if 0	//compile error @rzhen
				SP2_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
				SP2_CTRL_reg.s2_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, SP2_CTRL_reg.regValue);
				#endif
			}

			YPbPr_SetSOY_ADC_ClockSel(p_dispinfo, SP_AUTO_SOY_CLK_SEL_INIT_STATE);


			//APLL power down
			pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
			pll_ctrl_reg.pllpwdn = 1;
			IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);

			//disable clamp
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

			//disable DC Restore
			adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
			IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);

		break;

		case _SRC_VGA:
			//ABL disable
			YPbPr_ABL_SETTING_OFF();

			if(VGA_SOG_PATH_SELECT == SP_VHS_SOURCE_SOY0)
			{
				//Auto SOY disable
				soych0_a0_reg.regValue = IoReg_Read32(AUTO_SOY_SOYCH0_A0_reg);
				soych0_a0_reg.reg_auto_mode = 0;
				IoReg_Write32(AUTO_SOY_SOYCH0_A0_reg, soych0_a0_reg.regValue);
			}

			if(SYNC_PROCESSOR1 == VGA_SP_PATH)
			{
				//Sync Processor disable
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else// if(SYNC_PROCESSOR2 == VGA_SP_PATH)
			{
				//Sync Processor disable
				#if 0	//compile error @rzhen
				SP2_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP2_CTRL_reg);
				SP2_CTRL_reg.s2_auto_run = 0;
				IoReg_Write32(SYNC_PROCESSOR_SP2_CTRL_reg, SP2_CTRL_reg.regValue);
				#endif
			}

			//APLL power down
			pll_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_CTRL_reg);
			pll_ctrl_reg.pllpwdn = 1;
			IoReg_Write32(DDS_PLL_PLL_CTRL_reg, pll_ctrl_reg.regValue);

			//disable clamp
			adc_adc_clamp_ctrl1_reg.regValue = IoReg_Read32(ADC_ADC_CLAMP_CTRL1_reg);
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_1_0 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_2 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_4_3 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_5 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_7_6 = 0;
			adc_adc_clamp_ctrl1_reg.adc_clamp_ctrl0_8 = 0;
			IoReg_Write32(ADC_ADC_CLAMP_CTRL1_reg, adc_adc_clamp_ctrl1_reg.regValue);

			//disable DC Restore
			adc_adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_reg);
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_1_0 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_2 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_4_3 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_5 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_7_6 = 0;
			adc_adc_dcrestore_ctrl_reg.adc_dcrestore_ctrl_8 = 0;
			IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_reg, adc_adc_dcrestore_ctrl_reg.regValue);
		break;

		default:

		break;
	}
}

//USER:LewisLee DATE:2012/08/06
//For Hsync change function
void SyncProc_hs_sync_source(UINT8 SrcType, UINT8 HsyncSrc)
{
	sync_processor_sp1_ctrl_RBUS SP1_CTRL_reg;

	switch(SrcType)
	{
		case _SRC_VGA:
			if(_HSYNC_AHS == HsyncSrc)
			{
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = _HSYNC_AHS;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else if(_HSYNC_FBHS == HsyncSrc)
			{
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = _HSYNC_FBHS;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else
			{
				//Set to Default HsyncType
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = VGA_HSYNC_SRC;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
		break;

		case _SRC_YPBPR:
			if(_HSYNC_AHS == HsyncSrc)
			{
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = _HSYNC_AHS;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else if(_HSYNC_FBHS == HsyncSrc)
			{
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = _HSYNC_FBHS;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
			else
			{
				//Set to Default HsyncType
				SP1_CTRL_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
				SP1_CTRL_reg.s1_hs_sync_source = YPBPR_HSYNC_SRC;
				IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, SP1_CTRL_reg.regValue);
			}
		break;

		default:
			//do nothing
		break;
	}
}

void SyncProc_SetMinDiff(unsigned char display)
{
	ModeInformationType *p_timinginfo;
	p_timinginfo = Get_ADC_Timinginfo();
	
	auto_soy_soych0_a2_RBUS autosoy_soych0_a2_reg;
	autosoy_soych0_a2_reg.regValue=IoReg_Read32(AUTO_SOY_SOYCH0_A2_reg);

	switch(p_timinginfo->ModeCurr){
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
			autosoy_soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_NORMAL_1080_SEEK_MIN_DIFF;//COMPARE_LEVEL_SEEK_MIN_DIFF;
			break;

		case _MODE_480P:
		case _MODE_576P:
		case _MODE_480I:
		case _MODE_576I:
		default:
			autosoy_soych0_a2_reg.reg_min_diff = COMPARE_LEVEL_NORMAL_SEEK_MIN_DIFF;//COMPARE_LEVEL_SEEK_MIN_DIFF;
			break;
	}

	IoReg_Write32(AUTO_SOY_SOYCH0_A2_reg, autosoy_soych0_a2_reg.regValue);
}

extern unsigned char HsyncPolarityIndicator;
void SyncProc_Updw_Clamp_Ctrl(int src){

	sync_processor_updw_global_ctrl1_RBUS sync_processor_updw_global_ctrl1_reg;
	sync_processor_updw_global_ctrl2_RBUS SYNC_PROCESSOR_updw_global_ctrl2_reg;
	sync_processor_updw_ctrl1_r_RBUS sync_processor_updw_ctrl1_r_reg;
	sync_processor_updw_ctrl1_g_RBUS sync_processor_updw_ctrl1_g_reg;
	sync_processor_updw_ctrl1_b_RBUS sync_processor_updw_ctrl1_b_reg;

	unsigned int updn_end = 0;
	unsigned long long ulparam1 = 0;
	unsigned long long ulparam2 = 0;
	unsigned char rap_index = 0, end_index = 0;
	ModeInformationType *p_timinginfo = NULL;
	StructDisplayInfo *p_dispinfo = NULL;

	p_timinginfo = Get_ADC_Timinginfo();
	if(!p_timinginfo) return;

	p_dispinfo = Get_ADC_Dispinfo();
	if(!p_dispinfo) return;

	sync_processor_updw_global_ctrl1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL1_reg);

	if(src == _SRC_YPBPR){
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_r = 0x1;	//fixed, Non-SOY
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_g = 0x0;	//fixed, SOY
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_b = 0x1;	//fixed, Non-SOY
	}else{
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_r = 0x1;	//fixed, Non-SOY
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_g = 0x1;	//fixed, Non-SOY
		sync_processor_updw_global_ctrl1_reg.updw_ny_mode_b = 0x1;	//fixed, Non-SOY
	}

	sync_processor_updw_global_ctrl1_reg.hs_sync_edge_sel = 0x0;
	sync_processor_updw_global_ctrl1_reg.soy_stable_condition = 0x8;	// Fine tune
	sync_processor_updw_global_ctrl1_reg.meas_point_num = 0x0;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL1_reg, sync_processor_updw_global_ctrl1_reg.regValue);

	SYNC_PROCESSOR_updw_global_ctrl2_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL2_reg);

	if(src == _SRC_YPBPR){
		end_index = sizeof(YPP_UpDnClamp)/sizeof(StructUpDnClamp);

		for(rap_index=0;rap_index<end_index;rap_index++){
			if(p_dispinfo->ucMode_Curr == YPP_UpDnClamp[rap_index].index){
				SYNC_PROCESSOR_updw_global_ctrl2_reg.measure_sta = YPP_UpDnClamp[rap_index].meas_sta;
				SYNC_PROCESSOR_updw_global_ctrl2_reg.updw_sta = YPP_UpDnClamp[rap_index].updn_sta;
				SYNC_PROCESSOR_updw_global_ctrl2_reg.updw_end = YPP_UpDnClamp[rap_index].updn_end;

				break;
			}
		}
	}else{
		if(HsyncPolarityIndicator){
			SYNC_PROCESSOR_updw_global_ctrl2_reg.updw_sta = p_timinginfo->IHSyncPulseCount;
		}else{
			SYNC_PROCESSOR_updw_global_ctrl2_reg.updw_sta = p_timinginfo->IHCount - p_timinginfo->IHSyncPulseCount;
		}

		ulparam1 = (unsigned long long)(2 * CONFIG_CPU_XTAL_FREQ);
		do_div(ulparam1, 1000000); // crystal unit MHz
		ulparam1 = (unsigned long long)(ulparam1 * p_dispinfo->IPH_ACT_STA);
		//rtd_printk(KERN_EMERG, TAG_NAME_ADC,"#####[%s(%d)] ulparam1 = %lld\n", __FUNCTION__, __LINE__, ulparam1);

		ulparam2 = (unsigned long long)(3 * p_dispinfo->IHFreq * p_dispinfo->IHTotal);
		do_div(ulparam2, 10000); // clock unit MHz
		//rtd_printk(KERN_EMERG, TAG_NAME_ADC,"#####[%s(%d)] ulparam2 = %lld\n", __FUNCTION__, __LINE__, ulparam2);

		do_div(ulparam1, ulparam2);
		updn_end = (unsigned int)ulparam1;
		//rtd_printk(KERN_EMERG, TAG_NAME_ADC, "#####[%s(%d)]updn_end = %d #####\n", __func__, __LINE__,updn_end);

		SYNC_PROCESSOR_updw_global_ctrl2_reg.updw_end = updn_end;
		SYNC_PROCESSOR_updw_global_ctrl2_reg.measure_sta = updn_end+1;
	}

	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL2_reg, SYNC_PROCESSOR_updw_global_ctrl2_reg.regValue);

	sync_processor_updw_ctrl1_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_R_reg);
	sync_processor_updw_ctrl1_r_reg.chargcle_mode_sel_r = 0x0;	//fixed, auto mode for up/dn clamp
	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_R_reg, sync_processor_updw_ctrl1_r_reg.regValue);

	sync_processor_updw_ctrl1_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_G_reg);
	sync_processor_updw_ctrl1_g_reg.charge_mode_sel_g = 0x0;	//fixed, auto mode for up/dn clamp
	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_G_reg, sync_processor_updw_ctrl1_g_reg.regValue);

	sync_processor_updw_ctrl1_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_B_reg);
	sync_processor_updw_ctrl1_b_reg.charge_mode_sel_b= 0x0;	//fixed, auto mode for up/dn clamp
	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_B_reg, sync_processor_updw_ctrl1_b_reg.regValue);

	SyncProc_Updw_Ctrl1_R(src);
	SyncProc_Updw_Ctrl1_G(src);
	SyncProc_Updw_Ctrl1_B(src);
	SyncProc_Updw_Error_Stage1();
	SyncProc_Updw_Error_Stage2();
	SyncProc_Updw_Pvalue_Stage1();
	SyncProc_Updw_Pvalue_Stage2();
	SyncProc_Updw_Lock_Range();
}


void SyncProc_Updw_Ctrl1_R(int src){

	sync_processor_updw_ctrl1_r_RBUS sync_processor_updw_ctrl1_r_reg;

	sync_processor_updw_ctrl1_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_R_reg);
	sync_processor_updw_ctrl1_r_reg.target1_r = 0x28;

	if(src == _SRC_YPBPR){
		sync_processor_updw_ctrl1_r_reg.target2_r = 0x200;
	}else{
		sync_processor_updw_ctrl1_r_reg.target2_r = 0x8;
	}

	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_R_reg, sync_processor_updw_ctrl1_r_reg.regValue);
}

void SyncProc_Updw_Ctrl1_G(int src){

	sync_processor_updw_ctrl1_g_RBUS sync_processor_updw_ctrl1_g_reg;

	sync_processor_updw_ctrl1_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_G_reg);
	sync_processor_updw_ctrl1_g_reg.target1_g= 0x28;

	if(src == _SRC_YPBPR){
		sync_processor_updw_ctrl1_g_reg.target2_g= 0x40;
	}else{
		sync_processor_updw_ctrl1_g_reg.target2_g= 0x8;
	}

	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_G_reg, sync_processor_updw_ctrl1_g_reg.regValue);
}

void SyncProc_Updw_Ctrl1_B(int src){

	sync_processor_updw_ctrl1_b_RBUS sync_processor_updw_ctrl1_b_reg;

	sync_processor_updw_ctrl1_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_CTRL1_B_reg);
	sync_processor_updw_ctrl1_b_reg.target1_b= 0x28;

	if(src == _SRC_YPBPR){
		sync_processor_updw_ctrl1_b_reg.target2_b= 0x200;
	}else{
		sync_processor_updw_ctrl1_b_reg.target2_b= 0x8;
	}

	IoReg_Write32(SYNC_PROCESSOR_updw_CTRL1_B_reg, sync_processor_updw_ctrl1_b_reg.regValue);
}

void SyncProc_Updw_Error_Stage1(void){

	sync_processor_updw_st1_ctrl_r_RBUS sync_processor_updw_st1_ctrl_r_reg;
	sync_processor_updw_st1_ctrl_g_RBUS sync_processor_updw_st1_ctrl_g_reg;
	sync_processor_updw_st1_ctrl_b_RBUS sync_processor_updw_st1_ctrl_b_reg;

	sync_processor_updw_st1_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg);
	sync_processor_updw_st1_ctrl_r_reg.sta1_boundary_high_r = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg, sync_processor_updw_st1_ctrl_r_reg.regValue);

	sync_processor_updw_st1_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg);
	sync_processor_updw_st1_ctrl_g_reg.sta1_boundary_high_g = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg, sync_processor_updw_st1_ctrl_g_reg.regValue);

	sync_processor_updw_st1_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg);
	sync_processor_updw_st1_ctrl_b_reg.sta1_boundary_high_b = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg, sync_processor_updw_st1_ctrl_b_reg.regValue);

	sync_processor_updw_st1_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg);
	sync_processor_updw_st1_ctrl_r_reg.sta1_boundary_low_r = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg, sync_processor_updw_st1_ctrl_r_reg.regValue);

	sync_processor_updw_st1_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg);
	sync_processor_updw_st1_ctrl_g_reg.sta1_boundary_low_g = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg, sync_processor_updw_st1_ctrl_g_reg.regValue);

	sync_processor_updw_st1_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg);
	sync_processor_updw_st1_ctrl_b_reg.sta1_boundary_low_b = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg, sync_processor_updw_st1_ctrl_b_reg.regValue);
}


void SyncProc_Updw_Error_Stage2(void){

	sync_processor_updw_st2_ctrl_r_RBUS sync_processor_updw_st2_ctrl_r_reg;
	sync_processor_updw_st2_ctrl_g_RBUS sync_processor_updw_st2_ctrl_g_reg;
	sync_processor_updw_st2_ctrl_b_RBUS sync_processor_updw_st2_ctrl_b_reg;

	sync_processor_updw_st2_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg);
	sync_processor_updw_st2_ctrl_r_reg.sta2_boundary_high_r = 0x8;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg, sync_processor_updw_st2_ctrl_r_reg.regValue);

	sync_processor_updw_st2_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg);
	sync_processor_updw_st2_ctrl_g_reg.sta2_boundary_high_g = 0x8;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg, sync_processor_updw_st2_ctrl_g_reg.regValue);

	sync_processor_updw_st2_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg);
	sync_processor_updw_st2_ctrl_b_reg.sta2_boundary_high_b = 0x8;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg, sync_processor_updw_st2_ctrl_b_reg.regValue);

	sync_processor_updw_st2_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg);
	sync_processor_updw_st2_ctrl_r_reg.sta2_boundary_low_r = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg, sync_processor_updw_st2_ctrl_r_reg.regValue);

	sync_processor_updw_st2_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg);
	sync_processor_updw_st2_ctrl_g_reg.sta2_boundary_low_g = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg, sync_processor_updw_st2_ctrl_g_reg.regValue);

	sync_processor_updw_st2_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg);
	sync_processor_updw_st2_ctrl_b_reg.sta2_boundary_low_b = 0x4;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg, sync_processor_updw_st2_ctrl_b_reg.regValue);
}

void SyncProc_Updw_Pvalue_Stage1(void){

	sync_processor_updw_st1_ctrl_r_RBUS sync_processor_updw_st1_ctrl_r_reg;
	sync_processor_updw_st1_ctrl_g_RBUS sync_processor_updw_st1_ctrl_g_reg;
	sync_processor_updw_st1_ctrl_b_RBUS sync_processor_updw_st1_ctrl_b_reg;

	sync_processor_updw_st1_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg);
	sync_processor_updw_st1_ctrl_r_reg.sta1_p1_value_r = 0x1C;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg, sync_processor_updw_st1_ctrl_r_reg.regValue);

	sync_processor_updw_st1_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg);
	sync_processor_updw_st1_ctrl_g_reg.sta1_p1_value_g = 0x1C;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg, sync_processor_updw_st1_ctrl_g_reg.regValue);

	sync_processor_updw_st1_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg);
	sync_processor_updw_st1_ctrl_b_reg.sta1_p1_value_b = 0x1C;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg, sync_processor_updw_st1_ctrl_b_reg.regValue);

	sync_processor_updw_st1_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg);
	sync_processor_updw_st1_ctrl_r_reg.sta1_p2_value_r = 0xA;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_R_reg, sync_processor_updw_st1_ctrl_r_reg.regValue);

	sync_processor_updw_st1_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg);
	sync_processor_updw_st1_ctrl_g_reg.sta1_p2_value_g = 0xA;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_G_reg, sync_processor_updw_st1_ctrl_g_reg.regValue);

	sync_processor_updw_st1_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg);
	sync_processor_updw_st1_ctrl_b_reg.sta1_p2_value_b = 0xA;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St1_CTRL_B_reg, sync_processor_updw_st1_ctrl_b_reg.regValue);
}


void SyncProc_Updw_Pvalue_Stage2(void){

	sync_processor_updw_st2_ctrl_r_RBUS sync_processor_updw_st2_ctrl_r_reg;
	sync_processor_updw_st2_ctrl_g_RBUS sync_processor_updw_st2_ctrl_g_reg;
	sync_processor_updw_st2_ctrl_b_RBUS sync_processor_updw_st2_ctrl_b_reg;

	sync_processor_updw_st2_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg);
	sync_processor_updw_st2_ctrl_r_reg.sta2_p1_value_r = 0x3;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg, sync_processor_updw_st2_ctrl_r_reg.regValue);

	sync_processor_updw_st2_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg);
	sync_processor_updw_st2_ctrl_g_reg.sta2_p1_value_g = 0x3;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg, sync_processor_updw_st2_ctrl_g_reg.regValue);

	sync_processor_updw_st2_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg);
	sync_processor_updw_st2_ctrl_b_reg.sta2_p1_value_b = 0x3;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg, sync_processor_updw_st2_ctrl_b_reg.regValue);

	sync_processor_updw_st2_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg);
	sync_processor_updw_st2_ctrl_r_reg.sta2_p2_value_r = 0x1;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg, sync_processor_updw_st2_ctrl_r_reg.regValue);

	sync_processor_updw_st2_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg);
	sync_processor_updw_st2_ctrl_g_reg.sta2_p2_value_g = 0x1;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg, sync_processor_updw_st2_ctrl_g_reg.regValue);

	sync_processor_updw_st2_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg);
	sync_processor_updw_st2_ctrl_b_reg.sta2_p2_value_b = 0x1;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg, sync_processor_updw_st2_ctrl_b_reg.regValue);
}

void SyncProc_Updw_Lock_Range(void){

	sync_processor_updw_global_ctrl1_RBUS sync_processor_updw_global_ctrl1_reg;
	sync_processor_updw_st2_ctrl_r_RBUS sync_processor_updw_st2_ctrl_r_reg;
	sync_processor_updw_st2_ctrl_g_RBUS sync_processor_updw_st2_ctrl_g_reg;
	sync_processor_updw_st2_ctrl_b_RBUS sync_processor_updw_st2_ctrl_b_reg;

	sync_processor_updw_global_ctrl1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL1_reg);
	sync_processor_updw_global_ctrl1_reg.lock_range_y = 0x5;	// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL1_reg, sync_processor_updw_global_ctrl1_reg.regValue);

	sync_processor_updw_st2_ctrl_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg);
	sync_processor_updw_st2_ctrl_r_reg.lock_range_r = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_R_reg, sync_processor_updw_st2_ctrl_r_reg.regValue);

	sync_processor_updw_st2_ctrl_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg);
	sync_processor_updw_st2_ctrl_g_reg.lock_range_g = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_G_reg, sync_processor_updw_st2_ctrl_g_reg.regValue);

	sync_processor_updw_st2_ctrl_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg);
	sync_processor_updw_st2_ctrl_b_reg.lock_range_b = 0x2;		// Fine tune
	IoReg_Write32(SYNC_PROCESSOR_updw_St2_CTRL_B_reg, sync_processor_updw_st2_ctrl_b_reg.regValue);
}

void SyncProc_Updw_Clamp_Enable(bool enable){

	sync_processor_updw_global_ctrl1_RBUS sync_processor_updw_global_ctrl1_reg;

	sync_processor_updw_global_ctrl1_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_global_CTRL1_reg);

	if(enable){
		sync_processor_updw_global_ctrl1_reg.updw_en_r = 0x1;
		sync_processor_updw_global_ctrl1_reg.updw_en_g = 0x1;
		sync_processor_updw_global_ctrl1_reg.updw_en_b = 0x1;
		sync_processor_updw_global_ctrl1_reg.updw_clamp_en = 0x1;
	}else{
		sync_processor_updw_global_ctrl1_reg.updw_en_r = 0x0;
		sync_processor_updw_global_ctrl1_reg.updw_en_g = 0x0;
		sync_processor_updw_global_ctrl1_reg.updw_en_b = 0x0;
		sync_processor_updw_global_ctrl1_reg.updw_clamp_en = 0x0;
	}

	IoReg_Write32(SYNC_PROCESSOR_updw_global_CTRL1_reg, sync_processor_updw_global_ctrl1_reg.regValue);
}

extern unsigned judge_scaler_break_case(unsigned char display);

void SyncProc_Check_UpDn_Stable(unsigned char display){

	sync_processor_updw_stage_flag_r_RBUS updw_stage_flag_r_reg;
	sync_processor_updw_stage_flag_g_RBUS updw_stage_flag_g_reg;
	sync_processor_updw_stage_flag_b_RBUS updw_stage_flag_b_reg;

	int count = 4;

	while(count > 0){//wait stage2 stable

		updw_stage_flag_r_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_Stage_Flag_R_reg);
		updw_stage_flag_g_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_Stage_Flag_G_reg);
		updw_stage_flag_b_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_updw_Stage_Flag_B_reg);

		if(updw_stage_flag_r_reg.lock_flag_r & updw_stage_flag_g_reg.lock_flag_g & updw_stage_flag_b_reg.lock_flag_b){

			rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] ADC Up/Dn clamp stable !!!\n", __FUNCTION__, __LINE__);

			if(judge_scaler_break_case(display)) return;

			break;
		}else{
			count--;

			if((count%10) == 0){
				if(judge_scaler_break_case(display)) return;
			}

			if(count == 0){
				rtd_printk(KERN_NOTICE, TAG_NAME_ADC, "#####[%s(%d)] ADC Up/Dn clamp timeout !!!\n", __FUNCTION__, __LINE__);
			}

			msleep(5);
		}
	}
}

/*
 * Add for VGA, rzhen @2017-02-26, START
 */

void VGA_SyncProc(void)
{
	sync_processor_sp1_ctrl_RBUS sync_processor_sp1_ctrl_reg;
	sync_processor_sp1_stbctrl_RBUS sync_processor_sp1_stbctrl_reg;
	//sync_processor_sp1_clmpmsk_RBUS  sync_processor_sp1_clmpmsk_reg;
	sync_processor_sp1_dcnt_RBUS  SP1_dcnt_reg;

	sync_processor_sp1_ctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_CTRL_reg);
	//De-Composite HS out in CS mode
	sync_processor_sp1_ctrl_reg.s1_dehs_out_en = 1;
	sync_processor_sp1_ctrl_reg.s1_hsraw_inv = 0;
	sync_processor_sp1_ctrl_reg.s1_hs_sync_source = VGA_HSYNC_SRC;
	IoReg_Write32(SYNC_PROCESSOR_SP1_CTRL_reg, sync_processor_sp1_ctrl_reg.regValue);

	sync_processor_sp1_stbctrl_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbCtrl_reg);
	sync_processor_sp1_stbctrl_reg.s1_cap_win_range_lsb = VGA_CAP_WIN_RANGE_SS_LSB_INIT;
	sync_processor_sp1_stbctrl_reg.s1_cap_win_range = VGA_CAP_WIN_RANGE_SS_INIT;
	sync_processor_sp1_stbctrl_reg.s1_per_range = VGA_PER_RANGE_TOLERANCE_INIT;
	sync_processor_sp1_stbctrl_reg.s1_popup_stable_per = 0;
	sync_processor_sp1_stbctrl_reg.s1_cap_win_step = VGA_CAP_WIN_SETP_INIT;
	sync_processor_sp1_stbctrl_reg.s1_miss_lock_limit = VGA_MISS_LOCK_LIMIT_INIT;
	sync_processor_sp1_stbctrl_reg.s1_stable_en = 0;
	IoReg_Write32(SYNC_PROCESSOR_SP1_StbCtrl_reg, sync_processor_sp1_stbctrl_reg.regValue);

	SP1_dcnt_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_dcnt_reg);
	SP1_dcnt_reg.s1_deb_num = VGA_CHROMA_DEBOUNCE_NUM_INIT;
	IoReg_Write32(SYNC_PROCESSOR_SP1_dcnt_reg, SP1_dcnt_reg.regValue);

	rtd_printk(KERN_INFO, TAG_NAME_ADC, "VGA in SyncProc_InitSrc\n");
}



void reset_sp_status(void)
{
	sync_processor_sp1_stbrst0_RBUS sync_processor_sp1_stbrst0_reg;
	sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
	sync_processor_sp1_stbrst0_reg.s1_cap_32unlock = 1;
	IoReg_Write32(SYNC_PROCESSOR_SP1_StbRst0_reg, sync_processor_sp1_stbrst0_reg.regValue);
}

unsigned char check_sp_cap_unlock(void)
{//if ture: unlock. if false: stable
	sync_processor_sp1_stbrst0_RBUS sync_processor_sp1_stbrst0_reg;
	sync_processor_sp1_stbrst0_reg.regValue = IoReg_Read32(SYNC_PROCESSOR_SP1_StbRst0_reg);
	if(sync_processor_sp1_stbrst0_reg.s1_cap_32unlock)
		return TRUE;
	else
		return FALSE;
}

/*
 * Add for VGA, rzhen @2017-02-26, END
 */
