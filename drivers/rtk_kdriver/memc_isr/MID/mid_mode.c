/**
 * @file mid_mode.c
 * @brief This file implements mode change api.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Common/memc_type.h"
#include "memc_isr/MID/mid_mode.h"
#include "memc_isr/MID/mid_crtc.h"
#include "memc_isr/include/memc_lib.h"
#include "memc_isr/HAL/hal_ip.h"
#include "memc_isr/HAL/hal_me.h"
#include "memc_isr/HAL/hal_mc.h"
#include "memc_isr/HAL/hal_dehalo.h"
#include "memc_isr/HAL/hal_cpr.h"
#include "memc_isr/HAL/hal_post.h"
#include "memc_isr/HAL/hal_dm.h"
#include "memc_isr/include/PQLAPI.h"
#include <mach/io.h>

static TIMING_PARA_ST gstInputTiming = {2200, 1920, 16, 136, 1125, 1080, 8, 16};
static TIMING_PARA_ST gstOutputTiming = {2200, 1920, 32, 208, 1125, 1080, 8, 35};
static UINT32 u32MC_Hact = 0;
static UINT32 u32MC_Vact = 0;
static UINT32 u32ME_Hact = 0;
static UINT32 u32ME_Vact = 0;

static UINT32 u32IPME1_HSize = 960;
static UINT32 u32IPME1_VSize = 540;
static UINT32 u32ME1_BlockNum = 480;
static UINT32 u32ME1_RowNum = 270;

static UINT32 u32IPME2_HSize = 480;
static UINT32 u32IPME2_VSize = 270;
static UINT32 u32ME2_BlockNum = 240;
static UINT32 u32ME2_RowNum = 135;

static UINT32 u32ME2_PFV_BlockNum = 480;
static UINT32 u32ME2_PFV_RowNum = 270;

static UINT32 u32Dehalo_BlockNum = 480;
static UINT32 u32Dehalo_RowNum = 270;

static POST_SCALER_RATIO_H enPostHSC = POST_HSC_BYPASS;
static POST_SCALER_RATIO_V enPostVSC = POST_VSC_BYPASS;

static OUTPUT_FORMAT enOut_Format;

#define MID_PREFETCH_ROW_NUM	3

#ifndef REAL_CHIP	// FPGA
#define ME_CLOCK				135000000
#else
#define ME_CLOCK				315000000
#endif

#ifndef REAL_CHIP	//FPGA
#define ME1_480X270
#endif

/**
 * @brief This function set InOut mode.
 * @param [in] emom Specify InOut mode.
 * @retval VOID
*/
VOID Mid_Mode_SetInOutMode(INOUT_MODE emom)
{
	LogPrintf(DBG_MSG, "Mid mode set InOut mode = %d\r\n", (UINT32)emom);

	if(emom != RGB_IN_VIDEO_OUT && emom != RGB_IN_PC_OUT && \
		emom != YUV_IN_VIDEO_OUT && emom != YUV_IN_PC_OUT){
		LogPrintf(DBG_WARNING,"[%s]Invalid inout mode=%d\n",__FUNCTION__,emom);
		emom = RGB_IN_VIDEO_OUT;
	}
	if(emom == RGB_IN_VIDEO_OUT)
	{
		HAL_IP_SetIPPRE444to422Enable(TRUE);
		HAL_IP_SetIPPRECSCMode(CSC_MODE_RGB_YUV_709_LIMIT);
		HAL_IP_SetIPPRECSCEnable(TRUE);
		HAL_CPR_Set422Enable(TRUE);
		HAL_DM_SetKmc422Enable(TRUE);
		HAL_MC_SetLBMCPCMode(FALSE);
		HAL_POST_SetCSCMode(CSC_MODE_YUV_RGB_709_LIMIT);
		HAL_POST_SetCSCEnable(TRUE);
	}
	else if(emom == RGB_IN_PC_OUT)
	{
		HAL_IP_SetIPPRE444to422Enable(FALSE);
		HAL_IP_SetIPPRECSCEnable(FALSE);
		HAL_CPR_Set422Enable(FALSE);
		HAL_DM_SetKmc422Enable(FALSE);
		HAL_MC_SetLBMCPCMode(TRUE);
		HAL_POST_SetCSCEnable(FALSE);
	}
	else if(emom == YUV_IN_VIDEO_OUT)
	{
		HAL_IP_SetIPPRE444to422Enable(TRUE);
		HAL_IP_SetIPPRECSCEnable(FALSE);
		HAL_CPR_Set422Enable(TRUE);
		HAL_DM_SetKmc422Enable(TRUE);
		HAL_MC_SetLBMCPCMode(FALSE);
		HAL_POST_SetCSCMode(CSC_MODE_YUV_RGB_709_LIMIT);
		HAL_POST_SetCSCEnable(TRUE);
	}
	else if(emom == YUV_IN_PC_OUT)
	{
		HAL_IP_SetIPPRE444to422Enable(FALSE);
		HAL_IP_SetIPPRECSCMode(CSC_MODE_YUV_RGB_709_LIMIT);
		HAL_IP_SetIPPRECSCEnable(TRUE);
		HAL_CPR_Set422Enable(FALSE);
		HAL_DM_SetKmc422Enable(FALSE);
		HAL_MC_SetLBMCPCMode(TRUE);
		HAL_POST_SetCSCEnable(FALSE);
	}

	// Video out
	if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
	{
		HAL_CPR_SetBudgetPacket(5+(8*4+(4*4+4*4)*1), 5+(8*5+(4*4+4*4)*1));
		HAL_MC_SetKphaseME1IndexBsize(6);
#ifndef REAL_CHIP	//FPGA
		HAL_MC_SetKphaseME2IndexBsize(8);
		HAL_MC_SetKphaseMCIndexBsize(8);
#else
		HAL_MC_SetKphaseME2IndexBsize(6);
		HAL_MC_SetKphaseMCIndexBsize(6);
#endif
		HAL_MC_SetVarLPFEn(3);
		HAL_MC_SetVar17TapEn(TRUE);
		//HAL_MC_SetMCBlendMode(0);
		//HAL_MC_SetMCSceneChangeEnable(TRUE);
		HAL_MC_SetKphaseForceMCLFIdxEnable(FALSE);
		HAL_MC_SetKphaseForceMCHFIdxEnable(FALSE);
	}
	else // PC out
	{
		HAL_CPR_SetBudgetPacket(5+(8*4+(4*4+4*4)*2), 5+(8*5+(4*4+4*4)*2));
		HAL_MC_SetKphaseME1IndexBsize(3);
		HAL_MC_SetKphaseME2IndexBsize(3);
		HAL_MC_SetKphaseMCIndexBsize(3);
		HAL_MC_SetVarLPFEn(0);
		HAL_MC_SetVar17TapEn(FALSE);
		//HAL_MC_SetMCBlendMode(1);
		//HAL_MC_SetMCSceneChangeEnable(FALSE);
		HAL_MC_SetKphaseForceMCLFIdx(4);
		HAL_MC_SetKphaseForceMCLFIdxEnable(TRUE);
		HAL_MC_SetKphaseForceMCHFIdx(1);
		HAL_MC_SetKphaseForceMCHFIdxEnable(TRUE);
	}
}

/**
 * @brief This function set mc blend mode.
 * @param [in] emom Specify InOut mode.
 * @retval VOID
*/
VOID Mid_Mode_SetMCBlend(INOUT_MODE emom)
{
	if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
	{
		HAL_MC_SetMCBlendMode(0);
		HAL_MC_SetMCSceneChangeEnable(TRUE);
	}
	else
	{
		HAL_MC_SetMCBlendMode(1);
		HAL_MC_SetMCSceneChangeEnable(FALSE);
	}
}

static BOOL _Mid_Mode_Update2DInParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;
	switch(emof)
	{
		case OUTPUT_FORMAT_2D:
			if (((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080)) ||
				((emir == INPUT_RESOLUTION_768X480) && (emor == OUTPUT_RESOLUTION_768X480)) ||
				((emir == INPUT_RESOLUTION_1280X720) && (emor == OUTPUT_RESOLUTION_1280X720)))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum		=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum		=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum	=	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		= 	480;
				u32IPME2_VSize		= 	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum		=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum		=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum	=	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		= 	480;
				u32IPME2_VSize		= 	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#endif
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum		=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum		=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum	=	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		= 	480;
				u32IPME2_VSize		= 	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#endif
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_3840X540) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_SG:
			bRet = FALSE;
			break;
		case OUTPUT_FORMAT_3D_PR:
			bRet = FALSE;
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

static BOOL _Mid_Mode_UpdateSBSInParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;
	switch (emof)
	{
		case OUTPUT_FORMAT_2D:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	120;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	480;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	120;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	120;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	120;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#endif
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#endif
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_SG:
			if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#if 0
 			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#endif
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#endif
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	120;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	480;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	120;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	120;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	120;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if((emir == INPUT_RESOLUTION_3840X540) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_PR:
			if((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
#if 0
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#endif
			else
			{
				bRet = FALSE;
			}
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

static BOOL _Mid_Mode_UpdateTBInParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;
	switch (emof)
	{
		case OUTPUT_FORMAT_2D:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_SG:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum	 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum = 	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
#if 0
			else if((emir == INPUT_RESOLUTION_3840X540) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
			}
#endif
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_PR:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

static BOOL _Mid_Mode_UpdateLRInParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;
	switch (emof)
	{
		case OUTPUT_FORMAT_2D:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if((emir == INPUT_RESOLUTION_1920X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;

#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum	 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;

#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_SG:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if((emir == INPUT_RESOLUTION_1920X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if((emir == INPUT_RESOLUTION_3840X540) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_X2;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_PR:
			if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

static BOOL _Mid_Mode_UpdateLBLInParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;
	switch (emof)
	{
		case OUTPUT_FORMAT_2D:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_SG:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else if ((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	68;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	135;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	68;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	135;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	270;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
#endif

				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	480;
				u32Dehalo_RowNum	=	270;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		case OUTPUT_FORMAT_3D_PR:
			if ((emir == INPUT_RESOLUTION_1920X1080) && (emor == OUTPUT_RESOLUTION_1920X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X2160) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if ((emir == INPUT_RESOLUTION_1920X540) && (emor == OUTPUT_RESOLUTION_1920X540))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;

				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	135;
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	540;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if	((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X1080))
			{
				enPostVSC = POST_VSC_BYPASS;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else if((emir == INPUT_RESOLUTION_3840X1080) && (emor == OUTPUT_RESOLUTION_3840X2160))
			{
				enPostVSC = POST_VSC_X2;
				enPostHSC = POST_HSC_BYPASS;
#ifdef ME1_480X270
				u32ME1_BlockNum 	=	480;
				u32ME1_RowNum		=	135;
#else
				u32ME1_BlockNum 	=	240;
				u32ME1_RowNum		=	68;
#endif
				u32IPME1_HSize		=	960;
				u32IPME1_VSize		=	270;

				u32ME2_BlockNum 	=	240;
				u32ME2_RowNum		=	135;
#ifdef ME1_480X270
				u32ME2_PFV_BlockNum =	480;
				u32ME2_PFV_RowNum	=	270;
#else
				u32ME2_PFV_BlockNum =	240;
				u32ME2_PFV_RowNum	=	135;
#endif
				u32IPME2_HSize		=	480;
				u32IPME2_VSize		=	270;

				u32Dehalo_BlockNum	=	240;
				u32Dehalo_RowNum	=	135;
			}
			else
			{
				bRet = FALSE;
			}
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

/**
 * @brief This function set parameters for this mode and check this mode if valid.
 * @param [in] emir Specify input resolution.
 * @param [in] emor Specify output resolution.
 * @param [in] emif Specify input format.
 * @param [in] emof Specify output format.
 * @param [in] bForce force to change the format or not.
 * @retval true for valid, false for invalid
*/
BOOL Mid_Mode_UpdateParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	BOOL bRet = TRUE;

	switch (emif)
	{
		case INPUT_FORMAT_2D:
			bRet = _Mid_Mode_Update2DInParameters(emir, emor, emof);
			break;
		case INPUT_FORMAT_3D_SBS:
			bRet = _Mid_Mode_UpdateSBSInParameters(emir, emor, emof);
			break;
		case INPUT_FORMAT_3D_TB:
			bRet = _Mid_Mode_UpdateTBInParameters(emir, emor, emof);
			break;
		case INPUT_FORMAT_3D_LR:
			bRet = _Mid_Mode_UpdateLRInParameters(emir, emor, emof);
			break;
		case INPUT_FORMAT_3D_LBL:
			bRet = _Mid_Mode_UpdateLBLInParameters(emir, emor, emof);
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

/**
 * @brief This function update ippre settings
 * @param [in] VOID
 * @retval VOID
*/
static VOID _Mid_Mode_UpdateIPPRESettings(VOID)
{
	HAL_IP_SetIPPRERetiming(gstInputTiming.u32HActive, gstInputTiming.u32VActive/* + HAL_IP_GetIPPRERetimingDummyDE()*/);
	HAL_IP_SetIPPREPatternSize(gstInputTiming);
	HAL_IP_SetIPPREMuteHactive(gstInputTiming.u32HActive / 2,
								gstInputTiming.u32HActive / 2 - 8,
								gstInputTiming.u32HActive / 2 + 8);
	HAL_IP_SetIPPREMuteVactive(gstInputTiming.u32VActive,
								gstInputTiming.u32VActive - 8,
								gstInputTiming.u32VActive + 8);
}

#ifndef REAL_CHIP	// FPGA
/**
 * @brief This function update topb settings
 * @param [in] VOID
 * @retval VOID
*/
static VOID _Mid_Mode_UpdateTopBSettings(INPUT_FORMAT emif)
{
	HAL_IP_SetTOPBMuteTiming(gstInputTiming, gstOutputTiming);
	HAL_IP_SetTOPBMuteLRSelfGen((emif == INPUT_FORMAT_3D_LR)?TRUE:FALSE);
}

/**
 * @brief This function update topA settings
 * @param [in] VOID
 * @retval VOID
*/
static VOID _Mid_Mode_UpdateTopASettings(VOID)
{
	HAL_IP_SetTOPA_IPMERetiming(gstInputTiming);
}
#endif

/**
 * @brief This function update KME ipme settings
 * @param [in] VOID
 * @retval VOID
*/
static VOID _Mid_Mode_UpdateKME_IPMESettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	UINT32 u32Val = 0;
	if(emif == INPUT_FORMAT_2D)
	{
		u32Val = 4;
	}
	else if(emif == INPUT_FORMAT_3D_SBS)
	{
		u32Val = 1;
	}
	else if(emif == INPUT_FORMAT_3D_TB)
	{
		u32Val = 2;
	}
	else if(emif == INPUT_FORMAT_3D_LR)
	{
		u32Val = 0;
	}
	else if(emif == INPUT_FORMAT_3D_LBL)
	{
		u32Val = 3;
	}
	HAL_KME_IPME_SetInMode(u32Val);

	if(u32ME_Hact / u32IPME1_HSize == 1)
	{
		u32Val = 0;
	}
	else if(u32ME_Hact / u32IPME1_HSize == 2)
	{
		u32Val = 1;
	}
	else //if(u32ME_Hact / u32IPME1_HSize == 4)
	{
		u32Val = 2;
	}
	HAL_KME_IPME_SetHFetchMode(u32Val);

	if(u32ME_Vact / u32IPME1_VSize == 1)
	{
		u32Val = 0;
	}
	else if(u32ME_Vact / u32IPME1_VSize == 2)
	{
		u32Val = 1;
	}
	else //if(u32ME_Vact / u32IPME1_VSize == 4)
	{
		u32Val = 2;
	}
	HAL_KME_IPME_SetVFetchMode(u32Val);
	HAL_KME_IPME_SetHCenterValue(gstInputTiming.u32HActive/4);
	HAL_KME_IPME_SetVCenterValue(gstInputTiming.u32VActive/2);
	HAL_KME_IPME2_SetVCenterValue(u32IPME1_VSize);
	HAL_KME_IPME_SetScalerHactive(u32IPME1_HSize);
	HAL_KME_IPME_SetPscalerVactive(gstInputTiming.u32VActive + 8);

#if 0
	if(u32IPME1_VSize / u32IPME2_VSize == 2)
	{
		HAL_KME_IPME2_SetVFetchMode(0);
	}
	else //if(u32IPME1_VSize / u32IPME2_VSize == 4)
	{
		HAL_KME_IPME2_SetVFetchMode(1);
	}
#endif

	HAL_KME_ME1_Set_RMVSize(u32ME1_BlockNum, u32ME1_RowNum);
	HAL_KME_ME2_Set_RMVSize(u32ME1_BlockNum, u32ME1_RowNum);
	HAL_KME_ME1_Set_StatisSize(u32ME1_BlockNum, u32ME1_RowNum);

	if((emif == INPUT_FORMAT_2D) && (emof == OUTPUT_FORMAT_2D))
	{
		HAL_KME_Set_MeanderEnable(TRUE);
	}
	else
	{
		HAL_KME_Set_MeanderEnable(FALSE);
	}
}

static VOID _Mid_Mode_KME_VBUF_TOPSettings(OUTPUT_FORMAT emof, BOOL bVflip)
{
	HAL_KME_VBUF_Set_Hactive(u32ME1_BlockNum);
	HAL_KME_VBUF_Set_Vactive(u32ME1_RowNum);

	if(u32ME1_RowNum == 68)
	{
		HAL_KME_VBUF_Set_LBMEUpdateNum((u32IPME1_HSize / 16) * (u32IPME1_VSize * 2 / 135));
	}
	else
	{
		HAL_KME_VBUF_Set_LBMEUpdateNum((u32IPME1_HSize / 16) * (u32IPME1_VSize / u32ME1_RowNum));
	}

	HAL_KME_VBUF_Set_LBMETrigMidRowNum(u32ME1_RowNum - MID_PREFETCH_ROW_NUM);

	if(u32IPME1_HSize / u32ME1_BlockNum == 4)
	{
		HAL_KME_VBUF_Set_LBMEHShift(1);
	}
	else // if(u32IPME1_HSize / u32ME1_BlockNum == 2)
	{
		HAL_KME_VBUF_Set_LBMEHShift(0);
	}

	if(u32ME1_RowNum == 68)
	{
		if(u32IPME1_VSize * 2 / 135 == 4)
		{
			HAL_KME_VBUF_Set_LBMEVShift(1);
		}
		else // if(u32IPME1_VSize * 2 / 135 == 2)
		{
			HAL_KME_VBUF_Set_LBMEVShift(0);
		}
	}
	else
	{
		if(u32IPME1_VSize / u32ME1_RowNum == 4)
		{
			HAL_KME_VBUF_Set_LBMEVShift(1);
		}
		else // if(u32IPME1_VSize / u32ME1_RowNum == 2)
		{
			HAL_KME_VBUF_Set_LBMEVShift(0);
		}
	}

	HAL_KME2_VBUF_Set_PFVHactive(u32ME2_PFV_BlockNum);
	HAL_KME2_VBUF_Set_PFVVactive(u32ME2_PFV_RowNum);

	HAL_KME_VBUF_Set_BlockVact(u32ME1_RowNum);

	HAL_KME2_VBUF_Set_3DPREnable((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
	HAL_KME_Set_ME2LRDecEnable((emof == OUTPUT_FORMAT_3D_SG)?TRUE:FALSE);

	if(u32ME2_PFV_RowNum / u32ME2_RowNum == 2)
	{
		HAL_KME_VBUF_Set_PHPFVRatio(1);
		HAL_KME_VBUF_Set_PFVMVFetchIn1Row(2);
		HAL_KME_VBUF_Set_PPFVMVFetchIn1Row(2);
	}
	else
	{
		HAL_KME_VBUF_Set_PHPFVRatio(0);
		HAL_KME_VBUF_Set_PFVMVFetchIn1Row(1);
		HAL_KME_VBUF_Set_PPFVMVFetchIn1Row(1);
	}

	HAL_KME_Set_ME1HVRatio((u32ME1_BlockNum == 480) ? TRUE : FALSE);

	HAL_KME_Set_ME1VbufBlockRIM(0, u32ME1_RowNum - 1, 0, u32ME1_BlockNum - 1);
	HAL_KME_Set_ME2VbufPFVBlockRIM(0, u32ME2_PFV_RowNum - 1, 0, u32ME2_PFV_BlockNum - 1);
	HAL_KME_Set_BBDWindow(0 , gstOutputTiming.u32VActive - 1, 0, gstOutputTiming.u32HActive / 2 - 1);
	if(bVflip)
	{
		HAL_KME_SetMeanderBLKRIM(u32ME1_RowNum - 1, 0);
		HAL_KME_SetMeanderPIXRIM(u32IPME1_VSize - 1, 0);
	}
	else
	{
		HAL_KME_SetMeanderBLKRIM(0, u32ME1_RowNum - 1);
		HAL_KME_SetMeanderPIXRIM(0, u32IPME1_VSize - 1);
	}
}

static VOID _Mid_Mode_UpdateKME_LBME_TOPSettings(OUTPUT_FORMAT emof)
{
	HAL_KME_LBME_SetTotalLineNum(u32IPME1_VSize);
	HAL_KME_LBME_SetTotalPixelNum(u32IPME1_HSize);
	HAL_KME_LBME_SetDebugHactive(u32ME1_BlockNum);
	HAL_KME_LBME_SetBlkNumPerLine(u32IPME1_HSize * 8 / 128);

	HAL_KME_LBME_SetRim(0, u32IPME1_VSize - 1, 0, u32IPME1_HSize - 1);

	HAL_KME_LBME_SetTotalLinebufNum(96);

	//HAL_KME2_LBME_SetTotalLineNum(u32IPME2_VSize);
	HAL_KME2_LBME_SetTotalPixelNum(u32IPME2_HSize);
	HAL_KME2_LBME_SetBlkNumPerLine(u32IPME2_HSize * 8 / 64);
	HAL_KME2_LBME_SetDebugHactive(u32ME2_BlockNum);

	if(u32IPME2_HSize == 480)
	{
		HAL_KME2_LBME_SetTotalLinebufNum(48);
	}
	else // (u32IPME2_HSize == 240)
	{
		HAL_KME2_LBME_SetTotalLinebufNum(96);
	}

	HAL_KME_Set_LBME23DPREnable((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
}

static VOID _Mid_Mode_UpdateKME_LOGO0Settings(VOID)
{
	UINT32 u32Val = 0;

	if(u32ME_Hact / u32IPME1_HSize == 1)
	{
		u32Val = 0;
	}
	else if(u32ME_Hact / u32IPME1_HSize == 2)
	{
		u32Val = 1;
	}
	else //if(u32ME_Hact / u32IPME1_HSize == 4)
	{
		u32Val = 2;
	}

	HAL_KME_LOGO0_Set_HFetchMode(u32Val);

	if(u32ME_Vact / u32IPME1_VSize == 1)
	{
		u32Val = 0;
	}
	else if(u32ME_Vact / u32IPME1_VSize == 2)
	{
		u32Val = 1;
	}
	else //if(u32ME_Vact / u32IPME1_VSize == 4)
	{
		u32Val = 2;
	}

	HAL_KME_LOGO0_Set_VFetchMode(u32Val);

	HAL_KME_LOGO0_Set_PscalerVactive(u32ME_Vact);
}

static VOID _Mid_Mode_UpdateDehaloSettings(OUTPUT_FORMAT emof)
{
	UINT32 u32Val = 0;
	UINT32 u32Y_Ratio = 0, u32X_Ratio = 0;

	HAL_Dehalo_SetEnable((emof == OUTPUT_FORMAT_3D_PR)?FALSE:TRUE);
	HAL_Dehalo_SetPREnable((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
	HAL_Dehalo_SetOutTimimgMux((emof == OUTPUT_FORMAT_3D_PR)?1:0);
	HAL_Dehalo_SetRDLRFlowWRLatch((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
	HAL_Dehalo_SetSWReset((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
	HAL_Dehalo_SetShowEnable((emof == OUTPUT_FORMAT_3D_PR)?TRUE:FALSE);
	HAL_Dehalo_SetShowSelect((emof == OUTPUT_FORMAT_3D_PR)?4:0);

	if((gstOutputTiming.u32VActive / u32Dehalo_RowNum) == 4)
	{
		u32Val = 0;
	}
	else if(((gstOutputTiming.u32VActive / u32Dehalo_RowNum) == 8))
	{
		u32Val = 1;
	}
	else //if(((gstOutputTiming.u32VActive / u32Dehalo_RowNum) == 16))
	{
		u32Val = 2;
	}
	HAL_Dehalo_SetRowSize(u32Val);

	if(u32Dehalo_RowNum == 270)
	{
		u32Val = 0;
	}
	else // (u32Dehalo_RowNum == 135)
	{
		u32Val = 1;
	}
	HAL_Dehalo_SetBlockSize(u32Val);

	if((gstOutputTiming.u32VActive / 135) == 4)
	{
		u32Val = 0;
	}
	else if((gstOutputTiming.u32VActive / 135) == 8)
	{
		u32Val = 1;
	}
	else //if((gstOutputTiming.u32VActive / 135) == 16)
	{
		u32Val = 2;
	}
	HAL_Dehalo_SetLogoRowSize(u32Val);

	if(gstOutputTiming.u32HActive / 240 == 16)
	{
		u32Val = 0;
	}
	else // (gstOutputTiming.u32HActive / 240 == 8)
	{
		u32Val = 1;
	}
	HAL_Dehalo_SetLogoBlockSize(u32Val);

	if(((gstOutputTiming.u32HActive == 3840) && (gstOutputTiming.u32VActive == 2160)) && (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_Dehalo_SetBlockNum(480);
		HAL_Dehalo_SetRowNum(270);
	}
	else
	{
		HAL_Dehalo_SetBlockNum(u32Dehalo_BlockNum);
		HAL_Dehalo_SetRowNum(u32Dehalo_RowNum);
	}

	//HAL_Dehalo_SetVbufBlockNum(u32Dehalo_BlockNum);
	//HAL_Dehalo_SetVbufRowNum(u32Dehalo_RowNum);

	if(u32Dehalo_BlockNum == u32ME2_BlockNum)
	{
		u32X_Ratio = 1;
	}
	else //if (u32Dehalo_BlockNum / u32ME2_BlockNum == 2)
	{
		u32X_Ratio = 0;
	}
	if(u32Dehalo_RowNum == u32ME2_RowNum)
	{
		u32Y_Ratio = 1;
	}
	else //if (u32Dehalo_BlockNum / u32ME2_RowNum == 2)
	{
		u32Y_Ratio = 0;
	}
	HAL_Dehalo_SetYXRatio(u32X_Ratio + (u32Y_Ratio << 1));

	//if(((gstOutputTiming.u32HActive == 3840) && (gstOutputTiming.u32VActive == 2160)) && (emof == OUTPUT_FORMAT_3D_PR))
	if(gstOutputTiming.u32HActive / u32Dehalo_BlockNum == 16)
	{
		HAL_Dehalo_SetMVRDIntval(1);
	}
	else // if(gstOutputTiming.u32HActive / u32ME2_BlockNum == 8)
	{
		HAL_Dehalo_SetMVRDIntval(0);
	}

	if((u32Dehalo_BlockNum == 480) && (u32Dehalo_RowNum == 270))
	{
		HAL_Dehalo_SetHalfVTiming(FALSE);
		HAL_Dehalo_SetPattSize(FALSE);
	}
	else
	{
		HAL_Dehalo_SetHalfVTiming(TRUE);
		HAL_Dehalo_SetPattSize(TRUE);
	}
	HAL_Dehalo_SetPatternBlockRow(u32Dehalo_BlockNum, u32Dehalo_RowNum);
	HAL_Dehalo_SetVbufBlockRow(u32ME2_BlockNum, u32ME2_RowNum);

	if((u32ME1_BlockNum == u32Dehalo_BlockNum)/* && (u32ME1_BlockNum == u32Dehalo_BlockNum)*/)
	{
		HAL_Dehalo_SetErosionMode(FALSE);
	}
	else
	{
		HAL_Dehalo_SetErosionMode(TRUE);
	}
}

static VOID _Mid_Mode_UpdateKMC_TOPSettings(INPUT_FORMAT emif)
{
	UINT32 u32Val = 0;
	HAL_KMC_TOP_SetPatternSize(gstInputTiming);
	//HAL_KMC_TOP_SetKnrTrigGenMode(0);
	//HAL_KMC_TOP_SetKnrRowTrigDelay((gstInputTiming.u32HTotal - gstInputTiming.u32HActive) / 2);
	//HAL_KMC_TOP_SetKnrHalfVactive(gstInputTiming.u32VActive/2);
	//HAL_KMC_TOP_SetKnrHactive(gstInputTiming.u32HActive/2);
	HAL_KMC_TOP_SetIPMCHDECenterValue(gstInputTiming.u32HActive/4);
	if(emif == INPUT_FORMAT_2D)
	{
		u32Val = 4;
	}
	else if(emif == INPUT_FORMAT_3D_SBS)
	{
		u32Val = 1;
	}
	else if(emif == INPUT_FORMAT_3D_TB)
	{
		u32Val = 2;
	}
	else if(emif == INPUT_FORMAT_3D_LR)
	{
		u32Val = 0;
	}
	else if(emif == INPUT_FORMAT_3D_LBL)
	{
		u32Val = 3;
	}
	HAL_KMC_TOP_SetIPMCMode(u32Val);

	HAL_KMC_TOP_SetIPMCHDEActive(gstInputTiming.u32HActive/2);
	HAL_KMC_TOP_SetIPMCVactive(gstInputTiming.u32VActive);
}

static VOID _Mid_Mode_UpdateKMCDMSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof, BOOL bVflip)
{
	if(emof == OUTPUT_FORMAT_3D_PR)
	{
		HAL_DM_SetKmcVtotal(u32ME_Vact);
	}
	else
	{
		HAL_DM_SetKmcVtotal(u32ME_Vact / 2);
	}

	if(emif == INPUT_FORMAT_2D)
	{
		HAL_DM_SetKmcInput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmcInput3DEnable(TRUE);
		if(emif == INPUT_FORMAT_3D_SBS)
		{
			HAL_DM_SetKmcInput3DMode(1);
		}
		else
		{
			HAL_DM_SetKmcInput3DMode(0);
		}
	}

	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_DM_SetKmcOutput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmcOutput3DEnable(TRUE);
		if(emof == OUTPUT_FORMAT_3D_SG)
		{
			HAL_DM_SetKmcOutput3DMode(2);
		}
		else if(emof == OUTPUT_FORMAT_3D_PR)
		{
			if(bVflip)
			{
				HAL_DM_SetKmcOutput3DMode(0);
			}
			else
			{
				HAL_DM_SetKmcOutput3DMode(1);
			}
		}
		else
		{
			HAL_DM_SetKmcOutput3DMode(0);
		}
	}

	HAL_DM_SetPRMode((emof==OUTPUT_FORMAT_3D_PR)?1:0);
}

static VOID _Mid_Mode_UpdateKMEDMSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	if(emif == INPUT_FORMAT_2D)
	{
		HAL_DM_SetKmeInput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmeInput3DEnable(TRUE);
		if(emif == INPUT_FORMAT_3D_SBS)
		{
			HAL_DM_SetKmeInput3DMode(1);
		}
		else
		{
			HAL_DM_SetKmeInput3DMode(0);
		}
	}

	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_DM_SetKmeOutput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmeOutput3DEnable(TRUE);
		//if(emof == OUTPUT_FORMAT_3D_SG)
		//{
			HAL_DM_SetKmeOutput3DMode(2);
		//}
		//else //if(emof == OUTPUT_FORMAT_3D_PR))
		//{
		//	HAL_DM_SetKmeOutput3DMode(1);
		//}
	}

	HAL_DM_SetKmeMEActive(u32IPME1_HSize, u32IPME1_VSize);

	HAL_DM_SetKmeMVActive(u32ME1_BlockNum, u32ME1_RowNum);

	if((u32IPME1_HSize * 8) % 128 == 0)
	{
		HAL_DM_SetKmeMEHNum(u32IPME1_HSize * 8 / 128);
	}
	else
	{
		HAL_DM_SetKmeMEHNum(u32IPME1_HSize * 8 / 128 + 1);
	}
	HAL_DM_SetKmeMVHNum(u32ME1_BlockNum);
	if((u32ME1_BlockNum * 44) % 128 == 0)
	{
		HAL_DM_SetKmePPIHNum(u32ME1_BlockNum * 44 / 128);
	}
	else
	{
		HAL_DM_SetKmePPIHNum(u32ME1_BlockNum * 44 / 128 + 1);
	}
}

static VOID _Mid_Mode_UpdateKMVDMSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	if(emif == INPUT_FORMAT_2D)
	{
		HAL_DM_SetKmvInput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmvInput3DEnable(TRUE);
	}

	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_DM_SetKmvOutput3DEnable(FALSE);
	}
	else
	{
		HAL_DM_SetKmvOutput3DEnable(TRUE);
		HAL_DM_SetKmvME1Output3DMode(2);
		if(emof == OUTPUT_FORMAT_3D_SG)
		{
			HAL_DM_SetKmvME2Output3DMode(2);
		}
		else //if(emof == OUTPUT_FORMAT_3D_PR)
		{
			HAL_DM_SetKmvME2Output3DMode(1);
		}
	}

	HAL_DM_SetKmv01Active(u32ME2_BlockNum, u32ME2_RowNum);
	HAL_DM_SetKmv02Active(u32ME1_BlockNum, u32ME1_RowNum);

	if((u32ME1_RowNum == 68) && (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_DM_SetKmv04Active(u32ME1_BlockNum, 135);
		HAL_DM_SetKmv05Active(u32ME1_BlockNum, 135);
	}
	else if((u32ME1_RowNum == 135) && (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_DM_SetKmv04Active(u32ME1_BlockNum, 270);
		HAL_DM_SetKmv05Active(u32ME1_BlockNum, 270);
	}
	else
	{
		HAL_DM_SetKmv04Active(u32ME1_BlockNum, u32ME1_RowNum);
		HAL_DM_SetKmv05Active(u32ME1_BlockNum, u32ME1_RowNum);
	}

	HAL_DM_SetKmv12Active(u32IPME2_HSize, u32IPME2_VSize);

	if((u32ME2_BlockNum * 21) % 128 == 0)
	{
		HAL_DM_SetKmv01Hnum(u32ME2_BlockNum * 21 / 128);
	}
	else
	{
		HAL_DM_SetKmv01Hnum(u32ME2_BlockNum * 21 / 128 + 1);
	}

	if((u32ME1_BlockNum * 40) % 128 == 0)
	{
		HAL_DM_SetKmv02Hnum(u32ME1_BlockNum * 40 / 128);
	}
	else
	{
		HAL_DM_SetKmv02Hnum(u32ME1_BlockNum * 40 / 128 + 1);
	}
	if((u32ME1_BlockNum * 33) % 128 == 0)
	{
		HAL_DM_SetKmv04Hnum(u32ME1_BlockNum * 33 / 128);
	}
	else
	{
		HAL_DM_SetKmv04Hnum(u32ME1_BlockNum * 33 / 128 + 1);
	}
	if((u32ME1_BlockNum * 64) % 128 == 0)
	{
		HAL_DM_SetKmv05Hnum(u32ME1_BlockNum * 64 / 128);
	}
	else
	{
		HAL_DM_SetKmv05Hnum(u32ME1_BlockNum * 64 / 128 + 1);
	}
	if((u32IPME2_HSize * 16) % 128 == 0)
	{
		HAL_DM_SetKmv12Hnum(240 * 16 / 128);
	}
	else
	{
		HAL_DM_SetKmv12Hnum(240 * 16 / 128 + 1);
	}
}

static VOID _Mid_Mode_UpdateCPR_TOPSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	HAL_CPR_SetActive(u32ME_Hact/2 + 8, u32ME_Vact/2);

	if(emif == INPUT_FORMAT_2D)
	{
		HAL_CPR_SetEncode3DEnable(FALSE);
		HAL_CPR_SetEncode3DMode(0);
	}
	else
	{
		HAL_CPR_SetEncode3DEnable(TRUE);
		if(emif == INPUT_FORMAT_3D_SBS)
		{
			HAL_CPR_SetEncode3DMode(1);
		}
		else if(emif == INPUT_FORMAT_3D_TB)
		{
			HAL_CPR_SetEncode3DMode(2);
		}
		else if(emif == INPUT_FORMAT_3D_LBL)
		{
			HAL_CPR_SetEncode3DMode(3);
		}
		else if(emif == INPUT_FORMAT_3D_LR)
		{
			HAL_CPR_SetEncode3DMode(0);
		}
	}

	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_CPR_SetDecode3DEnable(FALSE);
		HAL_CPR_SetDecode3DMode(0);
	}
	else
	{
		HAL_CPR_SetDecode3DEnable(TRUE);
		if(emof == OUTPUT_FORMAT_3D_SG)
		{
			HAL_CPR_SetDecode3DMode(0);
		}
		else //if(emof == OUTPUT_FORMAT_3D_PR)
		{
			HAL_CPR_SetDecode3DMode(1);
		}
	}
}

static VOID _Mid_Mode_UpdateLBMCSettings(OUTPUT_RESOLUTION emor, INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
#ifndef REAL_CHIP	// FPGA
	UBYTE Normal_ILF_PrefetchNum[2][9] = {{0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x23},			// 1920x1080
										  {0x03, 0x07, 0x0B, 0x0F, 0x13, 0x17, 0x1B, 0x1F, 0x23}};			// 3840x2160

	UBYTE Normal_PLF_PrefetchNum[2][9] = {{0x23, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F},			// 1920x1080
										  {0x23, 0x1F, 0x1B, 0x17, 0x13, 0x0F, 0x0B, 0x07, 0x03}};			// 3840x2160

	UBYTE Normal_IHF_PrefetchNum[2][3] = {{0x02, 0x05, 0x08},			// 1920x1080
										  {0x02, 0x05, 0x08}};			// 3840x2160

	UBYTE Normal_PHF_PrefetchNum[2][3] = {{0x08, 0x05, 0x02},			// 1920x1080
										  {0x08, 0x05, 0x02}};			// 3840x2160

	UBYTE Single_ILF_PrefetchNum[2][9] = {{0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33},			// 1920x1080
										  {0x03, 0x0B, 0x13, 0x1B, 0x23, 0x2B, 0x33, 0x3B, 0x43}};			// 3840x2160

	UBYTE Single_PLF_PrefetchNum[2][9] = {{0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10},			// 1920x1080
										  {0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03}};			// 3840x2160

	UBYTE Single_IHF_PrefetchNum[2][3] = {{0x03, 0x07, 0x0E},			// 1920x1080
										  {0x03, 0x09, 0x0F}};			// 3840x2160

	UBYTE Single_PHF_PrefetchNum[2][3] = {{0x01, 0x01, 0x01},			// 1920x1080
										  {0x01, 0x01, 0x01}};			// 3840x2160

	UBYTE ubyIdx = 0;
#endif
	//fhd_mod
	if((gstInputTiming.u32HActive == 1920) && (gstInputTiming.u32VActive == 1080) &&
		(gstOutputTiming.u32HActive == 1920) && (gstOutputTiming.u32VActive == 1080))
	{
		HAL_MC_SetLBMCFHDMode(TRUE);
	}
	else
	{
		HAL_MC_SetLBMCFHDMode(FALSE);
	}

	HAL_MC_SetLBMCActive(u32ME_Hact, gstOutputTiming.u32VActive/2);

	HAL_MC_SetLBMC3DMode((emof==OUTPUT_FORMAT_3D_PR)?1:0);

	HAL_MC_SetLBMCPRMode((emof==OUTPUT_FORMAT_3D_PR)?1:0);

#ifndef REAL_CHIP	// FPGA
	for(ubyIdx = 0; ubyIdx < 9; ubyIdx++)
	{
		if(emor == OUTPUT_RESOLUTION_1920X1080)
		{
			HAL_MC_SetLBMCNormalLFPreFetchNum(FALSE, ubyIdx, Normal_ILF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCNormalLFPreFetchNum(TRUE, ubyIdx, Normal_PLF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCSingleLFPreFetchNum(FALSE, ubyIdx, Single_ILF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCSingleLFPreFetchNum(TRUE, ubyIdx, Single_PLF_PrefetchNum[0][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_3840X2160)
		{
			HAL_MC_SetLBMCNormalLFPreFetchNum(FALSE, ubyIdx, Normal_ILF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCNormalLFPreFetchNum(TRUE, ubyIdx, Normal_PLF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCSingleLFPreFetchNum(FALSE, ubyIdx, Single_ILF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCSingleLFPreFetchNum(TRUE, ubyIdx, Single_PLF_PrefetchNum[1][ubyIdx]);
		}
	}

	for(ubyIdx = 0; ubyIdx < 3; ubyIdx++)
	{
		if(emor == OUTPUT_RESOLUTION_1920X1080)
		{
			HAL_MC_SetLBMCNormalHFPreFetchNum(FALSE, ubyIdx, Normal_IHF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCNormalHFPreFetchNum(TRUE, ubyIdx, Normal_PHF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCSingleHFPreFetchNum(FALSE, ubyIdx, Single_IHF_PrefetchNum[0][ubyIdx]);
			HAL_MC_SetLBMCSingleHFPreFetchNum(TRUE, ubyIdx, Single_PHF_PrefetchNum[0][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_3840X2160)
		{
			HAL_MC_SetLBMCNormalHFPreFetchNum(FALSE, ubyIdx, Normal_IHF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCNormalHFPreFetchNum(TRUE, ubyIdx, Normal_PHF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCSingleHFPreFetchNum(FALSE, ubyIdx, Single_IHF_PrefetchNum[1][ubyIdx]);
			HAL_MC_SetLBMCSingleHFPreFetchNum(TRUE, ubyIdx, Single_PHF_PrefetchNum[1][ubyIdx]);
		}
	}
#endif
}

static VOID _Mid_Mode_UpdateMCSettings(OUTPUT_RESOLUTION emor, OUTPUT_FORMAT emof)
{
	UINT32 u32Val = 0, u32Val1 = 0;

	HAL_MC_SetPRMode((emof == OUTPUT_FORMAT_3D_PR)?1:0);

	HAL_MC_SetPolyEnable((emof == OUTPUT_FORMAT_3D_PR)?1:3);

	HAL_MC_SetMCHhalfsize((enPostHSC == POST_HSC_X2)?TRUE:FALSE);

	HAL_MC_SetMCVhalfsize((enPostVSC == POST_VSC_X2)?TRUE:FALSE);

	HAL_MC_SetMCActive(gstOutputTiming.u32HActive/2, u32MC_Vact);

	u32Val = HAL_MC_GetMCBlockSize();

	if((u32MC_Vact / u32Dehalo_RowNum) == 4)
	{
		u32Val = (0 << 2) + (u32Val & 0x03);
	}
	else if(((u32MC_Vact / u32Dehalo_RowNum) == 8) || ((u32MC_Vact / u32Dehalo_RowNum) == 7))
	{
		u32Val = (1 << 2) + (u32Val & 0x03);
	}
	else //if((u32FRC_Vact / u32ME1_RowNum) == 16)
	{
		u32Val = (2 << 2) + (u32Val & 0x03);
	}

	HAL_MC_SetMCBlockSize(u32Val);

	if(u32ME_Hact / u32IPME1_HSize == 1)
	{
		u32Val = 0;
	}
	else if(u32ME_Hact / u32IPME1_HSize == 2)
	{
		u32Val = 1;
	}
	else //if(u32ME_Hact / u32IPME1_HSize == 4)
	{
		u32Val = 2;
	}

	if(u32ME_Vact / u32IPME1_VSize == 1)
	{
		u32Val1 = 0;
	}
	else if(u32ME_Vact / u32IPME1_VSize == 2)
	{
		u32Val1 = 1;
	}
	else //if(u32ME_Vact / u32IPME1_Vsize == 4)
	{
		if(emof == OUTPUT_FORMAT_3D_PR)
		{
			u32Val1 = 1;
		}
		else
		{
		u32Val1 = 2;
	}
	}
	u32Val = u32Val + (u32Val1 << 2);
	HAL_MC_SetMCMVScaler(u32Val);

	HAL_MC_SetMCBlockNum(u32Dehalo_BlockNum);
	HAL_MC_SetMCRowNum(u32Dehalo_RowNum);

	HAL_MC_SetMCRim0(0, gstOutputTiming.u32VActive - 1, 0, gstOutputTiming.u32HActive - 1);
	HAL_MC_SetMCRim1(0, gstOutputTiming.u32VActive - 1, 0, gstOutputTiming.u32HActive - 1);
}

static VOID _Mid_Mode_UpdateMC2Settings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	UINT32 u32Val = 0;
	if((emif == INPUT_FORMAT_2D) && (emof == OUTPUT_FORMAT_2D))
	{
		u32Val = 3;
	}
	else
	{
		u32Val = 0;
	}
	HAL_MC_SetLogoMode(u32Val);

	if(gstOutputTiming.u32HActive / 240 == 8)
	{
		u32Val = 0;
	}
	else //if(gstOutputTiming.u32HActive / 240 == 16)
	{
		u32Val = 1;
	}
	HAL_MC_SetBlockLogoHSize(u32Val);
	HAL_MC_SetPixelLogoHSize(u32Val);

	if(gstOutputTiming.u32VActive / 135 == 8)
	{
		u32Val = 0;
	}
	else //if(gstOutputTiming.u32VActive / 135 == 16)
	{
		u32Val = 1;
	}
	HAL_MC_SetBlockLogoVSize(u32Val);
	HAL_MC_SetPixelLogoVSize(u32Val);
}

static VOID _Mid_Mode_UpdateKPhaseSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	HAL_MC_SetKphase3DFSEnable((emif == INPUT_FORMAT_3D_LR)?1:0);
	if((emif == INPUT_FORMAT_2D) || (emof == OUTPUT_FORMAT_2D))
	{
		HAL_MC_SetKphase3DEnable(0);
	}
	else
	{
		HAL_MC_SetKphase3DEnable(1);
	}

	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_MC_SetKphase3DMode(0);
	}
	else if(emof == OUTPUT_FORMAT_3D_PR)
	{
		HAL_MC_SetKphase3DMode(3);
	}
	else
	{
		HAL_MC_SetKphase3DMode(2);
	}
}

static VOID _Mid_Mode_UpdateKPostSettings(INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	HAL_POST_SetPatternSize(gstOutputTiming);
	HAL_POST_SetPREnable((emof==OUTPUT_FORMAT_3D_PR)?1:0);
	HAL_POST_SetHdeCenterValue(gstOutputTiming.u32HActive/4);
	HAL_POST_Set4PortHdeCenterValue(gstOutputTiming.u32HActive/4/2);

	// workaround , sometimes timing change hsc will enable.
	// maybe input resolution is unstable.
	if (enPostHSC != POST_HSC_BYPASS)
	{
		LogPrintf(DBG_MSG, "[_Mid_Mode_UpdateKPostSettings]POST_HSC not BYPASS mode!!\r\n");
		enPostHSC = POST_HSC_BYPASS;
	}

	if(enPostVSC == POST_VSC_BYPASS)	//bypass
	{
		HAL_POST_SetVscalerBypass(TRUE);
	}
	else if(enPostVSC == POST_VSC_X2)	// x2
	{
		HAL_POST_SetVscalerBypass(FALSE);
		HAL_POST_SetVscalerMode(3);
		HAL_POST_SetVActive(gstOutputTiming.u32VActive);
	}

	if(enPostHSC == POST_HSC_BYPASS)	// bypass
	{
		HAL_POST_SetHscalerBypass(TRUE);
	}
	else if(enPostHSC == POST_HSC_X2)	// x2
	{
		HAL_POST_SetHscalerBypass(FALSE);
		HAL_POST_SetHscalerMode(1);
		HAL_POST_SetHscalerOffset(1);
		HAL_POST_SetHscalerCoef(0x72EE06FF);
		HAL_POST_SetHscalerCoef1(0xFF03F524);
	}
}

/**
 * @brief This function set input/output format.
 * @param [in] emir Specify input resolution.
 * @param [in] emor Specify output resolution.
 * @param [in] emif Specify input format.
 * @param [in] emof Specify output format.
 * @param [in] bForce force to change the format or not.
 * @retval VOID
*/
VOID Mid_Mode_Set_VideoPath(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, INPUT_FORMAT emif, OUTPUT_FORMAT emof, BOOL bVflip)
{
	OUTPUT_FORMAT emOutput_Format;

	emOutput_Format = emof;
	enOut_Format = emof;

	if(emif == INPUT_FORMAT_3D_SBS)
	{
		u32ME_Hact = gstInputTiming.u32HActive / 2;
		u32MC_Hact = gstOutputTiming.u32HActive/2;
	}
	else
	{
		u32ME_Hact = gstInputTiming.u32HActive;
		u32MC_Hact = gstOutputTiming.u32HActive;
	}
	if((emif == INPUT_FORMAT_3D_TB) || (emif == INPUT_FORMAT_3D_LBL))
	{
		u32ME_Vact = gstInputTiming.u32VActive / 2;
		u32MC_Vact = gstOutputTiming.u32VActive / 2;
	}
	else
	{
		u32ME_Vact = gstInputTiming.u32VActive;
		u32MC_Vact = gstOutputTiming.u32VActive;
	}

	//LogPrintf(DBG_MSG, "u32FRC_Hact = %d\r\n", (UINT32)u32FRC_Hact);
	//LogPrintf(DBG_MSG, "u32FRC_Vact = %d\r\n",(UINT32)u32FRC_Vact);

	//LogPrintf(DBG_MSG, "u32MEHSize = %d\r\n", (UINT32)u32MEHSize);
	//LogPrintf(DBG_MSG, "u32MEVSize = %d\r\n",(UINT32)u32MEVSize);

	//LogPrintf(DBG_MSG, "u32MEBlockNum = %d\r\n", (UINT32)u32MEBlockNum);
	//LogPrintf(DBG_MSG, "u32MERowNum = %d\r\n",(UINT32)u32MERowNum);

#ifndef REAL_CHIP	// FPGA
	_Mid_Mode_UpdateTopBSettings(emif);
#endif
	_Mid_Mode_UpdateIPPRESettings();
#ifndef REAL_CHIP	// FPGA
	_Mid_Mode_UpdateTopASettings();
#endif
	_Mid_Mode_UpdateKME_IPMESettings(emif, emof);

	_Mid_Mode_KME_VBUF_TOPSettings(emof, bVflip);

	_Mid_Mode_UpdateKME_LBME_TOPSettings(emof);

	_Mid_Mode_UpdateKME_LOGO0Settings();

	_Mid_Mode_UpdateDehaloSettings(emof);

	_Mid_Mode_UpdateKMC_TOPSettings(emif);

	_Mid_Mode_UpdateKMCDMSettings(emif, emof, bVflip);

	_Mid_Mode_UpdateKMEDMSettings(emif, emof);

	_Mid_Mode_UpdateKMVDMSettings(emif, emof);

	_Mid_Mode_UpdateCPR_TOPSettings(emif, emof);

	_Mid_Mode_UpdateLBMCSettings(emor, emif, emof);

	_Mid_Mode_UpdateMCSettings(emor, emof);

	_Mid_Mode_UpdateMC2Settings(emif, emof);

	_Mid_Mode_UpdateKPhaseSettings(emif, emOutput_Format);

	_Mid_Mode_UpdateKPostSettings(emif, emof);
}

/**
 * @brief This function set input timing parameters.
 * @param [in] emir Specify input resolution.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_Set_InputTimingParameters(INPUT_RESOLUTION emir)
{
	BOOL bRet = TRUE;

	LogPrintf(DBG_MSG, "Mid mode set input timing = %d\r\n", (UINT32)emir);

	switch(emir)
	{
		case INPUT_RESOLUTION_1920X1080:
			gstInputTiming.u32HTotal = 2200;
			gstInputTiming.u32VTotal = 1125;
			gstInputTiming.u32HActive = 1920;
			gstInputTiming.u32VActive = 1080;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		case INPUT_RESOLUTION_1920X540:
			gstInputTiming.u32HTotal = 2200;
			gstInputTiming.u32VTotal = 562;
			gstInputTiming.u32HActive = 1920;
			gstInputTiming.u32VActive = 540;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 4;
			break;
		case INPUT_RESOLUTION_3840X2160:
			gstInputTiming.u32HTotal = 4400;
			gstInputTiming.u32VTotal = 2250;
			gstInputTiming.u32HActive = 3840;
			gstInputTiming.u32VActive = 2160;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		case INPUT_RESOLUTION_3840X1080:
			gstInputTiming.u32HTotal = 4400;
			gstInputTiming.u32VTotal = 1125;
			gstInputTiming.u32HActive = 3840;
			gstInputTiming.u32VActive = 1080;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		case INPUT_RESOLUTION_3840X540:
			gstInputTiming.u32HTotal = 4400;
			gstInputTiming.u32VTotal = 562;
			gstInputTiming.u32HActive = 3840;
			gstInputTiming.u32VActive = 540;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 4;
			break;
		case INPUT_RESOLUTION_1920X2160:
			gstInputTiming.u32HTotal = 2200;
			gstInputTiming.u32VTotal = 2250;
			gstInputTiming.u32HActive = 1920;
			gstInputTiming.u32VActive = 2160;
			gstInputTiming.u32HSBPorch = 136;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		case INPUT_RESOLUTION_768X480:
			gstInputTiming.u32HTotal = 2200;	//858;
			gstInputTiming.u32VTotal = 1125;	//525;
			gstInputTiming.u32HActive = 768;
			gstInputTiming.u32VActive = 480;
			gstInputTiming.u32HSBPorch = 36;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		case INPUT_RESOLUTION_1280X720:
			gstInputTiming.u32HTotal = 1650;
			gstInputTiming.u32VTotal = 750;
			gstInputTiming.u32HActive = 1280;
			gstInputTiming.u32VActive = 720;
			gstInputTiming.u32HSBPorch = 36;
			gstInputTiming.u32VSBPorch = 16;
			gstInputTiming.u32HSWidth = 16;
			gstInputTiming.u32VSWidth = 8;
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

/**
 * @brief This function get input timing parameters.
 * @param [in] VOID.
 * @retval input timing parameters
*/
TIMING_PARA_ST Mid_Mode_Get_InputTimingParameters(VOID)
{
	return gstInputTiming;
}

/**
 * @brief This function set output timing parameters.
 * @param [in] emir Specify output resolution.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_Set_OutputTimingParameters(OUTPUT_RESOLUTION emor)
{
	BOOL bRet = TRUE;

	LogPrintf(DBG_MSG, "Mid mode set output timing = %d\r\n", (UINT32)emor);

	switch(emor)
	{
		case OUTPUT_RESOLUTION_1920X1080:
			gstOutputTiming.u32HTotal = 2200;
			gstOutputTiming.u32VTotal = 1125;
			gstOutputTiming.u32HActive = 1920;
			gstOutputTiming.u32VActive = 1080;
			gstOutputTiming.u32HSWidth = 16;
			gstOutputTiming.u32VSWidth = 8;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 35;
			break;
		case OUTPUT_RESOLUTION_1920X540:
			gstOutputTiming.u32HTotal = 2200;
			gstOutputTiming.u32VTotal = 562;
			gstOutputTiming.u32HActive = 1920;
			gstOutputTiming.u32VActive = 540;
			gstOutputTiming.u32HSWidth = 16;
			gstOutputTiming.u32VSWidth = 8;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 16;
			break;
		case OUTPUT_RESOLUTION_3840X2160:
			gstOutputTiming.u32HTotal = 4400;
			gstOutputTiming.u32VTotal = 2250;
			gstOutputTiming.u32HActive = 3840;
			gstOutputTiming.u32VActive = 2160;
			gstOutputTiming.u32HSWidth = 16;
			gstOutputTiming.u32VSWidth = 8;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 37;
			break;
		case OUTPUT_RESOLUTION_3840X1080:
			gstOutputTiming.u32HTotal = 4400;
			gstOutputTiming.u32VTotal = 1125;
			gstOutputTiming.u32HActive = 3840;
			gstOutputTiming.u32VActive = 1080;
			gstOutputTiming.u32HSWidth = 16;
			gstOutputTiming.u32VSWidth = 8;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 16;
			break;
		case OUTPUT_RESOLUTION_3840X540:
			gstOutputTiming.u32HTotal = 4400;
			gstOutputTiming.u32VTotal = 562;
			gstOutputTiming.u32HActive = 3840;
			gstOutputTiming.u32VActive = 540;
			gstOutputTiming.u32HSWidth = 16;
			gstOutputTiming.u32VSWidth = 8;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 16;
			break;
		case OUTPUT_RESOLUTION_768X480:
			gstOutputTiming.u32HTotal = 2200;	//858;
			gstOutputTiming.u32VTotal = 1125;	//525;
			gstOutputTiming.u32HActive = 768;
			gstOutputTiming.u32VActive = 480;
			gstOutputTiming.u32HSWidth = 36;
			gstOutputTiming.u32VSWidth = 16;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 35;
			break;
		case OUTPUT_RESOLUTION_1280X720:
			gstOutputTiming.u32HTotal = 1650;
			gstOutputTiming.u32VTotal = 750;
			gstOutputTiming.u32HActive = 1280;
			gstOutputTiming.u32VActive = 720;
			gstOutputTiming.u32HSWidth = 36;
			gstOutputTiming.u32VSWidth = 16;
			gstOutputTiming.u32HSBPorch = 216;//208
			gstOutputTiming.u32VSBPorch = 8;
			break;
		default:
			bRet = FALSE;
			break;
	}
	return bRet;
}

/**
 * @brief This function get output timing parameters.
 * @param [in] VOID.
 * @retval output timing parameters
*/
TIMING_PARA_ST Mid_Mode_Get_OutputTimingParameters(VOID)
{
	return gstOutputTiming;
}

/**
 * @brief This function get ME v active.
 * @param [in] VOID.
 * @retval ME v active
*/
UINT32 Mid_Mode_Get_ME_Vact(VOID)
{
	return u32ME_Vact;
}

/**
 * @brief This function get ME row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_MERowNum(VOID)
{
	return u32ME1_RowNum;
}

/**
 * @brief This function get ME2 row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_ME2RowNum(VOID)
{
	return u32ME2_RowNum;
}

/**
 * @brief This function get Dehalo row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_DehaloRowNum(VOID)
{
	if(((gstOutputTiming.u32HActive == 3840) && (gstOutputTiming.u32VActive == 2160)) && (enOut_Format == OUTPUT_FORMAT_3D_PR))
		return 270;
	else
		return u32Dehalo_RowNum;
}

/**
 * @brief This function get ME v size.
 * @param [in] VOID.
 * @retval ME v size
*/
UINT32 Mid_Mode_Get_MEVSize(VOID)
{
	return u32IPME1_VSize;
}

/**
 * @brief This function get ME v size.
 * @param [in] VOID.
 * @retval ME v size
*/
UINT32 Mid_Mode_Get_ME2VSize(VOID)
{
	if(enOut_Format == OUTPUT_FORMAT_3D_PR)
	{
		return u32IPME2_VSize / 2;
	}
	else
	{
	return u32IPME2_VSize;
}
}

/**
 * @brief This function get Post H scaler.
 * @param [in] VOID.
 * @retval post h scaler
*/
POST_SCALER_RATIO_H Mid_Mode_GetPostHSC(VOID)
{
	return enPostHSC;
}

/**
 * @brief This function get Post V scaler.
 * @param [in] VOID.
 * @retval post v scaler
*/
POST_SCALER_RATIO_V Mid_Mode_GetPostVSC(VOID)
{
	return enPostVSC;
}

/**
 * @brief This function set v flip.
 * @param [in] BOOL bVflip.
 * @param [in] OUTPUT_FORMAT emof.
 * @retval VOID
*/
VOID Mid_Mode_SetVFlip(BOOL bVflip, OUTPUT_FORMAT emof)
{
	//UINT32 u32Val = 0;

	LogPrintf(DBG_MSG, "Mid mode set Vflip = %d\r\n", (UINT32)bVflip);

	if(bVflip)
	{
		HAL_DM_SetKmcVflipEnable(TRUE);
		HAL_DM_SetKmeVflipEnable(TRUE);
		HAL_MC_SetLBMCVflipEnable(TRUE);
		HAL_DM_SetKmeLogoVflipEnable(TRUE);
	}
	else
	{
		HAL_DM_SetKmcVflipEnable(FALSE);
		HAL_DM_SetKmeVflipEnable(FALSE);
		HAL_MC_SetLBMCVflipEnable(FALSE);
		HAL_DM_SetKmeLogoVflipEnable(FALSE);
	}
	if(emof == OUTPUT_FORMAT_3D_SG)
	{
		HAL_DM_SetKmcOutput3DMode(2);
	}
	else if(emof == OUTPUT_FORMAT_3D_PR)
	{
		if(bVflip)
		{
			HAL_DM_SetKmcOutput3DMode(0);
		}
		else
		{
			HAL_DM_SetKmcOutput3DMode(1);
		}
	}
	else
	{
		HAL_DM_SetKmcOutput3DMode(0);
	}
}

/**
 * @brief This function set last line enable.
 * @param [in] BOOL bVflip.
 * @param [in] INPUT_FORMAT emif.
 * @param [in] OUTPUT_FORMAT emof.
 * @retval VOID
*/
VOID Mid_Mode_LastLineEnable(BOOL bVflip, INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	if(bVflip)
	{
		HAL_CPR_SetLastLineEnable(FALSE);
	}
	else if(emof == OUTPUT_FORMAT_3D_PR)
	{
		HAL_CPR_SetLastLineEnable(FALSE);
	}
	else if(emif == INPUT_FORMAT_3D_LBL)
	{
		HAL_CPR_SetLastLineEnable(FALSE);
	}
	else
	{
		HAL_CPR_SetLastLineEnable(TRUE);
	}
}

/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
*/
VOID Mid_Mode_SetMEMCFrameRepeatEnable(BOOL bEnable, UBYTE *SetMCBlendMode)
{
	//LogPrintf(DBG_MSG,"[MEMC][%s][%d]\n", __FUNCTION__, bEnable);
	BOOL fPcMode = MEMC_LibGetMEMC_PCModeEnable();

	if(fPcMode)
		bEnable = TRUE;

	if(bEnable)
	{
		if(fPcMode)
			HAL_MC_SetMCBlendMode(1);
		else
			HAL_MC_SetMCBlendMode(2);

				HAL_MC_SetMCSceneChangeEnable(FALSE);
		//HAL_Dehalo_SetEnable(FALSE);
		//HAL_MC_SetLogoMode(0);
		HAL_DM_SetKme00WriteEnable(TRUE);
		HAL_DM_SetKme01ReadEnable(TRUE);
		HAL_DM_SetKme02ReadEnable(FALSE);
		HAL_DM_SetKme03ReadEnable(FALSE);
		//HAL_DM_SetKme04WriteEnable(FALSE);
		//HAL_DM_SetKme05WriteEnable(FALSE);
		//HAL_DM_SetKme06ReadEnable(FALSE);
		//HAL_DM_SetKme07ReadEnable(FALSE);
		HAL_DM_SetKme08WriteEnable(FALSE);
		HAL_DM_SetKme09ReadEnable(FALSE);
		HAL_DM_SetKme10WriteEnable(FALSE);
		HAL_DM_SetKme11ReadEnable(FALSE);
		HAL_DM_SetKme12WriteEnable(FALSE);
		HAL_DM_SetKme13ReadEnable(FALSE);
		HAL_DM_SetKme14WriteEnable(FALSE);
		HAL_DM_SetKme15ReadEnable(FALSE);

		// mv
		HAL_KME_METOP1_Set_ClearMVEnable(TRUE);
		HAL_DM_SetKmv01WriteEnable(FALSE);
		HAL_DM_SetKmv02WriteEnable(FALSE);
		HAL_DM_SetKmv04WriteEnable(FALSE);
		HAL_DM_SetKmv05WriteEnable(FALSE);
		HAL_DM_SetKmv12WriteEnable(FALSE);
		HAL_DM_SetKmv03ReadEnable(FALSE);
		HAL_DM_SetKmv06ReadEnable(FALSE);
		HAL_DM_SetKmv07ReadEnable(FALSE);
		HAL_DM_SetKmv08ReadEnable(FALSE);
		HAL_DM_SetKmv09ReadEnable(FALSE);
		HAL_DM_SetKmv10ReadEnable(FALSE);
		HAL_DM_SetKmv11ReadEnable(FALSE);

		HAL_DM_SetKmc00WriteEnable(TRUE);
		HAL_DM_SetKmc01WriteEnable(TRUE);

		if(fPcMode){
			HAL_DM_SetKmc05ReadEnable(FALSE);	// disable plf read
			HAL_DM_SetKmc07ReadEnable(FALSE);	// disable phf read
			HAL_DM_SetKmc04ReadEnable(TRUE);     // enable ilf read
			HAL_DM_SetKmc06ReadEnable(TRUE);     // enable ihf read
		}else{
			HAL_DM_SetKmc05ReadEnable(TRUE);	// enable plf read
			HAL_DM_SetKmc07ReadEnable(TRUE);	// enable phf read
			HAL_DM_SetKmc04ReadEnable(FALSE);     // disable ilf read
			HAL_DM_SetKmc06ReadEnable(FALSE);     // disable ihf read
		}

		*SetMCBlendMode = 1;
	}
	else
	{

		HAL_DM_SetKme00WriteEnable(TRUE);
		HAL_DM_SetKme01ReadEnable(TRUE);
		HAL_DM_SetKme02ReadEnable(TRUE);
		HAL_DM_SetKme03ReadEnable(TRUE);
		//HAL_DM_SetKme04WriteEnable(TRUE);
		//HAL_DM_SetKme05WriteEnable(TRUE);
		//HAL_DM_SetKme06ReadEnable(TRUE);
		//HAL_DM_SetKme07ReadEnable(TRUE);

		//mv
		HAL_DM_SetKmv01WriteEnable(TRUE);
		HAL_DM_SetKmv02WriteEnable(TRUE);
		HAL_DM_SetKmv04WriteEnable(TRUE);
		HAL_DM_SetKmv05WriteEnable(TRUE);
		HAL_DM_SetKmv12WriteEnable(TRUE);
		HAL_DM_SetKmv03ReadEnable(TRUE);
		HAL_DM_SetKmv06ReadEnable(TRUE);
		HAL_DM_SetKmv07ReadEnable(TRUE);
		HAL_DM_SetKmv08ReadEnable(TRUE);
		HAL_DM_SetKmv09ReadEnable(TRUE);
		HAL_DM_SetKmv10ReadEnable(TRUE);
		HAL_DM_SetKmv11ReadEnable(TRUE);
		HAL_KME_METOP1_Set_ClearMVEnable(FALSE);

		HAL_DM_SetKme08WriteEnable(TRUE);
		HAL_DM_SetKme09ReadEnable(TRUE);
		HAL_DM_SetKme10WriteEnable(TRUE);
		HAL_DM_SetKme11ReadEnable(TRUE);
		HAL_DM_SetKme12WriteEnable(TRUE);
		HAL_DM_SetKme13ReadEnable(TRUE);
		HAL_DM_SetKme14WriteEnable(TRUE);
		HAL_DM_SetKme15ReadEnable(TRUE);

		HAL_DM_SetKmc04ReadEnable(TRUE);     // enable ilf read
		HAL_DM_SetKmc06ReadEnable(TRUE);     // enable ihf read
		HAL_DM_SetKmc00WriteEnable(TRUE);
		HAL_DM_SetKmc01WriteEnable(TRUE);
		HAL_DM_SetKmc05ReadEnable(TRUE);	// enable plf read
		HAL_DM_SetKmc07ReadEnable(TRUE);	// enable phf read

		if(Mid_Mode_GetMC_DMA_Ready_flag() == 1){
			HAL_MC_SetMCBlendMode(0);
			HAL_MC_SetMCSceneChangeEnable(TRUE);
			*SetMCBlendMode = 1;
		} else {
			*SetMCBlendMode = 0;
		}


		//HAL_Dehalo_SetEnable(TRUE);
		//HAL_MC_SetLogoMode(3);
	}

}

VOID Mid_Mode_SetMEMC_PCModeEnable(BOOL bEnable)
 {
 	//LogPrintf(DBG_MSG,"[MEMC][%s][%d]\n", __FUNCTION__, bEnable);

	// workaround , sometimes timing change hsc will enable.
	// maybe input resolution is unstable.
	if (enPostHSC != POST_HSC_BYPASS)
	{
		LogPrintf(DBG_MSG, "[Mid_Mode_SetMEMC_PCModeEnable]POST_HSC not BYPASS mode!!\r\n");
		enPostHSC = POST_HSC_BYPASS;
	}

 	if(bEnable)
 	{
		HAL_MC_SetMCBlendMode(1);	//low delay mode use iz frame

		HAL_MC_SetMCSceneChangeEnable(FALSE);
		HAL_DM_SetKme00WriteEnable(FALSE);
		HAL_DM_SetKme01ReadEnable(FALSE);
		HAL_DM_SetKme02ReadEnable(FALSE);
		HAL_DM_SetKme03ReadEnable(FALSE);
		//HAL_DM_SetKme04WriteEnable(FALSE);
		//HAL_DM_SetKme05WriteEnable(FALSE);
		//HAL_DM_SetKme06ReadEnable(FALSE);
		//HAL_DM_SetKme07ReadEnable(FALSE);
		HAL_DM_SetKme08WriteEnable(FALSE);
		HAL_DM_SetKme09ReadEnable(FALSE);
		HAL_DM_SetKme10WriteEnable(FALSE);
		HAL_DM_SetKme11ReadEnable(FALSE);
		HAL_DM_SetKme12WriteEnable(FALSE);
		HAL_DM_SetKme13ReadEnable(FALSE);
		HAL_DM_SetKme14WriteEnable(FALSE);
		HAL_DM_SetKme15ReadEnable(FALSE);
		HAL_KME_METOP1_Set_ClearMVEnable(TRUE);
		HAL_DM_SetKmc05ReadEnable(FALSE);	// disable plf read
		HAL_DM_SetKmc07ReadEnable(FALSE);	// disable phf read

		HAL_DM_SetKmc04ReadEnable(TRUE);     // enable ilf read
		HAL_DM_SetKmc06ReadEnable(TRUE);     // enable ihf read

		if(enPostHSC == POST_HSC_X2)	// x2
		{
			HAL_POST_SetHscalerBypass(FALSE);
		}
		else
		{
			HAL_POST_SetHscalerBypass(TRUE);
		}

		HAL_POST_SetHscalerMode_C(1);
		HAL_POST_SetHscalerOffset_C(1);
		HAL_POST_SetHscalerCoef_C(0x72EE06FF);
		HAL_POST_SetHscalerCoef1_C(0xFF03F524);
	}
	else
	{
		//HAL_POST_SetHscalerBypass(FALSE);
		// workaround
		HAL_POST_SetHscalerBypass(TRUE);
		LogPrintf(DBG_MSG, "[Mid_Mode_SetMEMC_PCModeEnable]not PC mode\r\n");

		HAL_POST_SetHscalerMode_C(1);
		HAL_POST_SetHscalerOffset_C(0);
		HAL_POST_SetHscalerCoef_C(0x40000000);
		HAL_POST_SetHscalerCoef1_C(0x40);
	}
}


/**
 * @brief This function set MC PT Zero type1
 * @param [in] u32Type: 0: iz; 1: pz; 2: avg; 3: phase blend; 4: I/P by phase; 5: med3
 * @retval VOID
*/
VOID Mid_Mode_SetPTZeroType1(UINT32 u32Type)
{
	HAL_MC_SetPTZeroType1(u32Type);
}

/**
 * @brief This function set MC PT Zero type2
 * @param [in] u32Type: 0: iz; 1: pz; 2: avg; 3: phase blend; 4: I/P by phase; 5: med3
 * @retval VOID
*/
VOID Mid_Mode_SetPTZeroType2(UINT32 u32Type)
{
	HAL_MC_SetPTZeroType2(u32Type);
}

/**
* @brief This function set kmc output 3d Mode
* @param [in] UINT32 u32Mode
* @retval VOID
*/
VOID Mid_Mode_SetDMOutput3DMode(UINT32 u32Mode)
{
	HAL_DM_SetKmcOutput3DMode(u32Mode);
}

/**
 * @brief This function set LR inverse
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_Mode_SetLRInverse(BOOL bEnable)
{
	HAL_CPR_SetLRInverse(bEnable);
}

/**
 * @brief This function set ME work mode
 * @param [in] UINT32 u32WorkMode : 0 for 1:2, 1 for 1:1
 * @retval VOID
*/
VOID Mid_Mode_SetMEWorkMode(UINT32 u32WorkMode)
{
	UINT32 u32RowLine = 0;
	UINT32 u32MV_Trig_Wait_Cycle = 0;

	if(u32WorkMode == 0)
	{
		if(u32ME1_RowNum == 68)
		{
			u32RowLine = gstOutputTiming.u32VActive * 2 / 135;
		}
		else
		{
			u32RowLine = gstOutputTiming.u32VActive / u32ME1_RowNum;
		}

		if(u32RowLine == 2)
		{
			HAL_KME_VBUF_Set_RowType(0);
		}
		else if(u32RowLine == 4)
		{
			HAL_KME_VBUF_Set_RowType(1);
		}
		else if(u32RowLine == 8)
		{
			HAL_KME_VBUF_Set_RowType(2);
		}
		else if(u32RowLine == 16)
		{
			HAL_KME_VBUF_Set_RowType(3);
		}
		else if(u32RowLine == 32)
		{
			HAL_KME_VBUF_Set_RowType(4);
		}
		else if(u32RowLine == 64)
		{
			HAL_KME_VBUF_Set_RowType(5);
		}
		else
		{
			HAL_KME_VBUF_Set_RowType(2);
		}

		u32MV_Trig_Wait_Cycle = ME_CLOCK * u32RowLine * MID_PREFETCH_ROW_NUM / 120 / gstInputTiming.u32VActive;
		HAL_KME_VBUF_Set_WaitCycle(u32MV_Trig_Wait_Cycle, u32MV_Trig_Wait_Cycle);
		HAL_KME_Set_WorkMode(0);
	}
	else //if(u32WorkMode == 1)
	{
		if(u32ME1_RowNum == 68)
		{
			u32RowLine = gstOutputTiming.u32VActive * 2 / 135;
		}
		else
		{
			u32RowLine = gstOutputTiming.u32VActive / u32ME1_RowNum;
		}

		if(u32RowLine == 1)
		{
			HAL_KME_VBUF_Set_RowType(0);
		}
		else if(u32RowLine == 2)
		{
			HAL_KME_VBUF_Set_RowType(1);
		}
		else if(u32RowLine == 4)
		{
			HAL_KME_VBUF_Set_RowType(2);
		}
		else if(u32RowLine == 8)
		{
			HAL_KME_VBUF_Set_RowType(3);
		}
		else if(u32RowLine == 16)
		{
			HAL_KME_VBUF_Set_RowType(4);
		}
		else if(u32RowLine == 32)
		{
			HAL_KME_VBUF_Set_RowType(5);
		}
		else if(u32RowLine == 64)
		{
			HAL_KME_VBUF_Set_RowType(6);
		}
		else
		{
			HAL_KME_VBUF_Set_RowType(3);
		}

		HAL_KME_VBUF_Set_WaitCycle(0, 0);
		HAL_KME_Set_WorkMode(1);
	}
}

/**
 * @brief This function set ppfv index
 * @param [in] UINT32 u32WorkMode : 0 for 1:2, 1 for 1:1
 * @param [in] OUTPUT_FORMAT emof
 * @retval VOID
*/
VOID Mid_Mode_SetPPFVIDX(UINT32 u32WorkMode, OUTPUT_FORMAT emof)
{
	if(emof == OUTPUT_FORMAT_2D)
	{
		HAL_KME_Set_3DPPFVIDX(FALSE);
	}
	else if(u32WorkMode == 0) // 1:2
	{
		HAL_KME_Set_3DPPFVIDX(FALSE);
	}
	else  //1:1
	{
		HAL_KME_Set_3DPPFVIDX(TRUE);
	}
}

/**
 * @brief This function force lbmc idx
 * @param [in] INOUT_MODE emom
 * @param [in] OUTPUT_FORMAT emof
 * @retval VOID
*/
VOID Mid_Mode_ForceLBMCIdx(INOUT_MODE emom, OUTPUT_FORMAT emof)
{
	if(((emom == RGB_IN_PC_OUT) || (emom == YUV_IN_PC_OUT)) || (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_MC_SetKphaseForceMCLFIdx(4);
		HAL_MC_SetKphaseForceMCLFIdxEnable(TRUE);
		HAL_MC_SetKphaseForceMCHFIdx(1);
		HAL_MC_SetKphaseForceMCHFIdxEnable(TRUE);
	}
	else
	{
		HAL_MC_SetKphaseForceMCLFIdxEnable(FALSE);
		HAL_MC_SetKphaseForceMCHFIdxEnable(FALSE);
	}
}

/**
 * @brief This function set me 3d LR signal
 * @param [in] BOOL bEnable
 * @param [in] UINT32 u32Cycle
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_Mode_SetME3DLR(BOOL bEnable, UINT32 u32Cycle, UINT32 u32Pattern)
{
	HAL_KME_SetLREnable(bEnable);
	HAL_KME_SetLRCycle(u32Cycle);
	HAL_KME_SetLRPattern(u32Pattern);
}

/**
 * @brief This function set MEMC module ratio.
 * @param [in] UBYTE pix sft
 * @param [in] UBYTE blk sft
 * @param [in] UBYTE pix sft
 * @param [in] UBYTE blk sft
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_GetMEMCModuleSft(UBYTE *u8_in_me1_pix_sft,UBYTE *u8_in_me1_blk_sft,UBYTE *u8_in_me2_pix_sft,UBYTE *u8_in_me2_blk_sft)
{
	BOOL	bRet = TRUE;

	UBYTE  u8_in_me1_pix_ratio;
	UBYTE  u8_in_me1_blk_ratio;
	UBYTE  u8_in_me2_pix_ratio;
	UBYTE  u8_in_me2_blk_ratio;

	//u8_in_me1_pix_sft
	if(68 == u32ME1_RowNum)
	{
		u8_in_me1_pix_ratio = (10 * u32MC_Vact) / 675;
	}
	else
	{
		u8_in_me1_pix_ratio = u32MC_Vact / u32ME1_RowNum;
	}
	while((u8_in_me1_pix_ratio = u8_in_me1_pix_ratio >> 1))
	{
		(*u8_in_me1_pix_sft) ++;
	}
	//u8_in_me1_blk_sft
	u8_in_me1_blk_ratio = u32MC_Hact / u32ME1_BlockNum;
	while((u8_in_me1_blk_ratio = u8_in_me1_blk_ratio >> 1))
	{
		(*u8_in_me1_blk_sft) ++;
	}

	//u8_in_me2_pix_sft
	if(68 == u32ME2_RowNum)
	{
		u8_in_me2_pix_ratio = (10 * u32MC_Vact) / 675;
	}
	else
	{
		u8_in_me2_pix_ratio = u32MC_Vact / u32ME2_RowNum;
	}
	while((u8_in_me2_pix_ratio = u8_in_me2_pix_ratio >> 1))
	{
		(*u8_in_me2_pix_sft) ++;
	}
	//u8_in_me2_blk_sft
	u8_in_me2_blk_ratio = u32MC_Hact / u32ME2_BlockNum;
	while((u8_in_me2_blk_ratio = u8_in_me2_blk_ratio >> 1))
	{
		(*u8_in_me2_blk_sft) ++;
	}
	return bRet;
}

/**
 * @brief This function set DM PFV PPFV interval
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID Mid_Mode_SetDMPFVPPFVInterval(UINT32 uiVal)
{
	HAL_KME_ME2_SetDMPFVPPFVInterval(uiVal);
}

#ifndef REAL_CHIP	// FPGA
/**
 * @brief This function set 2 port enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_Mode_SetTOPA2PortEnable(BOOL bEnable)
{
	HAL_IP_SetTOPA2PortEnable(bEnable);
}
#endif


BOOL Mid_Mode_GetMC_DMA_Ready_flag(VOID)
{
	if(HAL_MC_GetMC04_06_total_data_cnt() == 0){
		return FALSE;
	} else {
		return TRUE;
	}
}


