/**
 * @file mid_crtc.c
 * @brief This file implements crtc api.
 * @date Nov.14.2014
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
#include "memc_isr/HAL/hal_crtc.h"

/**
 * @brief This function set crtc frc timing.
 * @param [in] OUTPUT_FORMAT emof Specify output format.
 * @param [in] PANEL_PARAMETERS_ST stPanelPara Specify panel parameters.
 * @param [in] TIMING_PARA_ST stFRCTiming Specify frc timing.
 * @retval VOID
*/
VOID Mid_CRTC_SetFRCTiming(OUTPUT_FORMAT emof, PANEL_PARAMETERS_ST stPanelPara)
{
	UINT32 u32ME_Orig_Vtrig_dly = 0;
	UINT32 u32ME_Vtrig_dly = 0;
	UINT32 u32DEHALO_Vtrig_dly = 0;
	UINT32 u32MC_Vtrig_dly = 0;
	UINT32 u32FRC_Vtrig_dly = 0;
	UINT32 u32Val = 0;
	UINT32 u32RowSize = 0;
	TIMING_PARA_ST stFRCTiming = Mid_Mode_Get_OutputTimingParameters();
	HAL_CRTC_SetFRCTiming(stFRCTiming);

	u32RowSize = stFRCTiming.u32VActive / Mid_Mode_Get_ME2RowNum();

	u32ME_Orig_Vtrig_dly = HAL_CRTC_GetMEOrigVtrigDelay();

	u32ME_Vtrig_dly = HAL_CRTC_GetMEVtrigDelay();

	if(Mid_Mode_Get_DehaloRowNum() == Mid_Mode_Get_ME2RowNum())
	{
		if(emof == OUTPUT_FORMAT_3D_PR)
		{
			u32DEHALO_Vtrig_dly = u32RowSize * 4;
		}
		else
		{
			u32DEHALO_Vtrig_dly = u32RowSize * 7;
		}
	}
	else
	{
		u32DEHALO_Vtrig_dly = u32RowSize * 4;
	}

	u32MC_Vtrig_dly = u32DEHALO_Vtrig_dly;

	if(emof == OUTPUT_FORMAT_3D_PR)
	{
		u32FRC_Vtrig_dly = u32ME_Orig_Vtrig_dly + u32ME_Vtrig_dly + u32MC_Vtrig_dly - stFRCTiming.u32VSBPorch - stPanelPara.u32VSWidth + 3;
	}
	else
	{
		u32FRC_Vtrig_dly = u32ME_Orig_Vtrig_dly + u32ME_Vtrig_dly + u32MC_Vtrig_dly - stFRCTiming.u32VSBPorch - stPanelPara.u32VSWidth + 2;
	}

	HAL_CRTC_SetFRCVtrigDelay(u32FRC_Vtrig_dly);

	if((Mid_Mode_GetPostVSC() == POST_VSC_X2) && (emof != OUTPUT_FORMAT_3D_PR))
	{
		HAL_CRTC_SetFRCPreDEPNum(0x0F);
	}
	else if((Mid_Mode_GetPostVSC() == POST_VSC_X2) && (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_CRTC_SetFRCPreDEPNum(0x0F);
	}
	else
	{
		HAL_CRTC_SetFRCPreDEPNum(0x0D);
	}

	HAL_CRTC_SetLbmeVtrigDelay(stFRCTiming.u32VActive + u32RowSize);

	HAL_CRTC_SetDehaloVtrigDelay(u32DEHALO_Vtrig_dly);

	HAL_CRTC_SetMCVtrigDelay(u32MC_Vtrig_dly);

	//HAL_CRTC_SetDecVtrigDelay(u32RowSize * 100);

	//HAL_CRTC_SetMEVactive(stFRCTiming.u32VActive * 2 / Mid_Mode_Get_MERowNum() * (Mid_Mode_Get_MERowNum() + 6) / 2);
	HAL_CRTC_SetMEVactive(stFRCTiming.u32VActive);

	HAL_CRTC_SetDehaloVactive(stFRCTiming.u32VActive/2);

	HAL_CRTC_SetMCVactive(stFRCTiming.u32VActive/2);

	if((stFRCTiming.u32VActive / Mid_Mode_Get_MERowNum() == 16) || (stFRCTiming.u32VActive / Mid_Mode_Get_MERowNum() == 15))
	{
		u32Val = 0;
	}
	else if((stFRCTiming.u32VActive / Mid_Mode_Get_MERowNum() == 8) || (stFRCTiming.u32VActive / Mid_Mode_Get_MERowNum() == 7))
	{
		u32Val = 1;
	}
	else if(stFRCTiming.u32VActive / Mid_Mode_Get_MERowNum() == 4)
	{
		u32Val = 2;
	}
	HAL_CRTC_SetME1RowType(u32Val);

	if(stFRCTiming.u32VActive / Mid_Mode_Get_ME2RowNum() == 16)
	{
		u32Val = 0;
	}
	else if(stFRCTiming.u32VActive / Mid_Mode_Get_ME2RowNum() == 8)
	{
		u32Val = 1;
	}
	else if(stFRCTiming.u32VActive / Mid_Mode_Get_ME2RowNum() == 4)
	{
		u32Val = 2;
	}
	HAL_CRTC_SetME2RowType(u32Val);

	//HAL_CRTC_SetDehaloRowType(u32Val);

	//HAL_CRTC_SetMCRowType(u32Val);
}

/**
 * @brief This function set crtc panel timing.
 * @param [in] OUTPUT_FORMAT emof Specify output format.
 * @param [in] PANEL_PARAMETERS_ST stPanelPara Specify panel parameters.
 * @retval VOID
*/
VOID Mid_CRTC_SetPanelTiming(OUTPUT_FORMAT emof, PANEL_PARAMETERS_ST stPanelPara)
{
	UINT32 u32ME_Orig_Vtrig_dly = 0;
	UINT32 u32ME_Vtrig_dly = 0;
	UINT32 u32MC_Vtrig_dly = 0;
	UINT32 u32Out_Vtrig_dly = 0;

	HAL_CRTC_SetPanelTiming(stPanelPara);

	u32ME_Orig_Vtrig_dly = HAL_CRTC_GetMEOrigVtrigDelay();

	u32ME_Vtrig_dly = HAL_CRTC_GetMEVtrigDelay();

	u32MC_Vtrig_dly = HAL_CRTC_GetMCVtrigDelay();

	if(emof == OUTPUT_FORMAT_3D_PR)
	{
		u32Out_Vtrig_dly = u32ME_Orig_Vtrig_dly + u32ME_Vtrig_dly + u32MC_Vtrig_dly - stPanelPara.u32VSBPorch - stPanelPara.u32VSWidth + 4;

	}
	else
	{
		u32Out_Vtrig_dly = u32ME_Orig_Vtrig_dly + u32ME_Vtrig_dly + u32MC_Vtrig_dly - stPanelPara.u32VSBPorch - stPanelPara.u32VSWidth + 3;
	}

	if((Mid_Mode_GetPostVSC() == POST_VSC_X2) && (emof != OUTPUT_FORMAT_3D_PR))
	{
		HAL_CRTC_SetOutVtrigDelay(u32Out_Vtrig_dly + 1);
	}
	else if((Mid_Mode_GetPostVSC() == POST_VSC_X2) && (emof == OUTPUT_FORMAT_3D_PR))
	{
		HAL_CRTC_SetOutVtrigDelay(u32Out_Vtrig_dly);
	}
	else
	{
		HAL_CRTC_SetOutVtrigDelay(u32Out_Vtrig_dly);
	}

	//LogPrintf(DBG_MSG, "u32Out_Vtrig_dly111 = %d\r\n", (UINT32)u32Out_Vtrig_dly);
	//LogPrintf(DBG_MSG, "u32FRC_Vtrig_dly111 = %d\r\n",(UINT32)u32FRC_Vtrig_dly);
}

/**
 * @brief This function set crtc panel timing.
 * @param [in] INPUT_FRAMERATE enInputFrameRate
 * @param [in] OUTPUT_FRAMERATE enOutputFrameRate
 * @param [in] BOOL bDouble
 * @retval true for success, false for fail
*/
BOOL Mid_CRTC_SetN2M(INPUT_FRAMERATE enInputFrameRate,
								OUTPUT_FRAMERATE enOutputFrameRate,
								INPUT_FORMAT enInputFormat,
								OUTPUT_FORMAT enOutputFormat)
{
	BOOL bRet = TRUE;
	BOOL bDouble = FALSE;
	UINT32 u32N = 0, u32M = 0;

	switch(enInputFrameRate)
	{
		case INPUT_FRAMERATE_24HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_48HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 2;
					u32M = 5;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					u32N = 1;
					u32M = 4;
					break;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 1;
					u32M = 5;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 1;
					u32M = 10;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_25HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 5;
					u32M = 12;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					u32N = 1;
					u32M = 4;
					break;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 5;
					u32M = 24;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					u32N = 1;
					u32M = 8;
					break;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 5;
					u32M = 48;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_30HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 1;
					u32M = 4;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 1;
					u32M = 8;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_48HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_48HZ:
				{
					u32N = 1;
					u32M = 1;
					break;	
				}
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 4;
					u32M = 5;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 2;
					u32M = 5;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 1;
					u32M = 5;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_50HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					u32N = 1;
					u32M = 1;
					break;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 5;
					u32M = 6;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 5;
					u32M = 12;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					u32N = 1;
					u32M = 4;
					break;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 5;
					u32M = 24;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_60HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					u32N = 1;
					u32M = 1;
					break;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					u32N = 6;
					u32M = 10;
					break;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 1;
					u32M = 4;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_96HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					u32N = 1;
					u32M = 1;
					break;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 4;
					u32M = 5;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 2;
					u32M = 5;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_100HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					u32N = 1;
					u32M = 1;
					break;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 5;
					u32M = 6;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 5;
					u32M = 12;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		case INPUT_FRAMERATE_120HZ:
		{
			switch(enOutputFrameRate)
			{
				case OUTPUT_FRAMERATE_50HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_60HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_96HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_100HZ:
				{
					return FALSE;
				}
				case OUTPUT_FRAMERATE_120HZ:
				{
					u32N = 1;
					u32M = 1;
					break;
				}
				case OUTPUT_FRAMERATE_200HZ:
				{
					u32N = 6;
					u32M = 10;
					break;
				}
				case OUTPUT_FRAMERATE_240HZ:
				{
					u32N = 1;
					u32M = 2;
					break;
				}
				default:
					return FALSE;
					break;
			}
			break;
		}
		default:
			return FALSE;
	}

	if((u32M % 2 != 0) && (enOutputFrameRate > OUTPUT_FRAMERATE_60HZ))
	{
		bDouble = TRUE;
	}

	if(((u32N % 2 != 0) || (u32M % 2 != 0)) && (enInputFormat == INPUT_FORMAT_3D_LR))
	{
		bDouble = TRUE;
	}

	if((u32M % 2 != 0) && (enOutputFormat == OUTPUT_FORMAT_3D_SG))
	{
		bDouble = TRUE;
	}

	if((u32M % 4 != 0) && (enOutputFormat == OUTPUT_FORMAT_3D_SG_LLRR))
	{
		bDouble = TRUE;
	}

	if(bDouble)
	{
		u32N = u32N * 2;
		u32M = u32M * 2;
	}
// may be not support  2:5 -> 8:20
	if((u32M % 4 != 0) && (enOutputFormat == OUTPUT_FORMAT_3D_SG_LLRR))
	{
		u32N = u32N * 2;
		u32M = u32M * 2;
	}
//
	LogPrintf(DBG_MSG, "Mid crtc set N2M = %d:%d\r\n", u32N, u32M);

	HAL_CRTC_SetN2M(u32N, u32M);

	return bRet;
}

/**
 * @brief This function set CRTC slave mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_CRTC_SetSlaveModeEnable(BOOL bEnable)
{
	HAL_CRTC_SetSlaveModeEnable(bEnable);
}

/**
 * @brief This function set CRTC lbmc delay
 * @param [in] OUTPUT_RESOLUTION emor
 * @retval VOID
*/
VOID Mid_CRTC_SetLbmcTrigDly(OUTPUT_RESOLUTION emor)
{

	UBYTE Normal_LF[4][9] = {{0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24},	// 1920x1080
							 {0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46},	// 3840x2160
							 {0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A},	// 768x480
							 {0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43, 0x43}};   // 1280x720

	UBYTE Normal_HF[4][4] = {{0x35, 0x35, 0x35, 0x36},		// 1920x1080
							 {0x46, 0x46, 0x46, 0x46},		// 3840x2160
							 {0x46, 0x46, 0x46, 0x46},		// 768x480
							 {0x46, 0x46, 0x46, 0x46}};		// 3840x2160

	UBYTE Single_LF[4][9] = {{0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11}, 	// 1920x1080
							 {0x44, 0x44, 0x44, 0x44, 0x44, 0x40, 0x36, 0x30, 0x28},	// 3840x2160
							 {0x44, 0x44, 0x44, 0x44, 0x44, 0x40, 0x36, 0x30, 0x28},	// 768x480
							 {0x44, 0x44, 0x44, 0x44, 0x44, 0x40, 0x36, 0x30, 0x28}};	// 3840x2160

	UBYTE Single_HF[4][4] = {{0x32, 0x32, 0x32, 0x32},		// 1920x1080
							 {0x46, 0x46, 0x46, 0x46},		// 3840x2160
							 {0x46, 0x46, 0x46, 0x46},		// 768x480
							 {0x46, 0x46, 0x46, 0x46}};		// 3840x2160

	UBYTE ubyIdx = 0;
	if(emor == OUTPUT_RESOLUTION_1920X1080)
	{
		HAL_CRTC_SetLbmcVtrigDelay(972);
	}
	else if(emor == OUTPUT_RESOLUTION_3840X2160)
	{
		HAL_CRTC_SetLbmcVtrigDelay(2020);
	}

	for(ubyIdx = 0; ubyIdx < 9; ubyIdx++)
	{
		if(emor == OUTPUT_RESOLUTION_1920X1080)
		{
			HAL_CRTC_SetLBMCNormalLFDly(ubyIdx, Normal_LF[0][ubyIdx]);
			HAL_CRTC_SetLBMCSingleLFDly(ubyIdx, Single_LF[0][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_3840X2160)
		{
			HAL_CRTC_SetLBMCNormalLFDly(ubyIdx, Normal_LF[1][ubyIdx]);
			HAL_CRTC_SetLBMCSingleLFDly(ubyIdx, Single_LF[1][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_768X480)
		{
			HAL_CRTC_SetLBMCNormalLFDly(ubyIdx, Normal_LF[2][ubyIdx]);
			HAL_CRTC_SetLBMCSingleLFDly(ubyIdx, Single_LF[2][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_1280X720)
		{
			HAL_CRTC_SetLBMCNormalLFDly(ubyIdx, Normal_LF[3][ubyIdx]);
			HAL_CRTC_SetLBMCSingleLFDly(ubyIdx, Single_LF[3][ubyIdx]);
		}
	}

	for(ubyIdx = 0; ubyIdx < 4; ubyIdx++)
	{
		if(emor == OUTPUT_RESOLUTION_1920X1080)
		{
			HAL_CRTC_SetLBMCNormalHFDly(ubyIdx, Normal_HF[0][ubyIdx]);
			HAL_CRTC_SetLBMCSingleHFDly(ubyIdx, Single_HF[0][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_3840X2160)
		{
			HAL_CRTC_SetLBMCNormalHFDly(ubyIdx, Normal_HF[1][ubyIdx]);
			HAL_CRTC_SetLBMCSingleHFDly(ubyIdx, Single_HF[1][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_768X480)
		{
			HAL_CRTC_SetLBMCNormalHFDly(ubyIdx, Normal_HF[2][ubyIdx]);
			HAL_CRTC_SetLBMCSingleHFDly(ubyIdx, Single_HF[2][ubyIdx]);
		}
		else if(emor == OUTPUT_RESOLUTION_1280X720)
		{
			HAL_CRTC_SetLBMCNormalHFDly(ubyIdx, Normal_HF[3][ubyIdx]);
			HAL_CRTC_SetLBMCSingleHFDly(ubyIdx, Single_HF[3][ubyIdx]);
		}
	}
}

/**
 * @brief This function get vspll lock status
 * @retval True for lock
 * @retval False for unlock
*/
BOOL Mid_CRTC_GetVSPLLStatus(VOID)
{
	return HAL_CRTC_GetVSPLLStatus();
}

/**
 * @brief This function set 3d LR signal
 * @param [in] BOOL bEnable
 * @param [in] UINT32 u32Cycle
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_CRTC_Set3DLR(BOOL bEnable, UINT32 u32Cycle, UINT32 u32Pattern)
{
	HAL_CRTC_SetLREnable(bEnable);
	HAL_CRTC_SetLRCycle(u32Cycle);
	HAL_CRTC_SetLRPattern(u32Pattern);
}

