/**
 * @file mid_crtc.h
 * @brief This file implements crtc header.
 * @date September.3.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_CRTC_HEADER_INCLUDE_
#define _MID_CRTC_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set crtc frc timing.
 * @param [in] OUTPUT_FORMAT emof Specify output format.
 * @param [in] PANEL_PARAMETERS_ST stPanelPara Specify panel parameters.
 * @param [in] TIMING_PARA_ST stFRCTiming Specify frc timing.
 * @retval VOID
*/
VOID Mid_CRTC_SetFRCTiming(OUTPUT_FORMAT emof, PANEL_PARAMETERS_ST stPanelPara);

/**
 * @brief This function set crtc panel timing.
 * @param [in] OUTPUT_FORMAT emof Specify output format.
 * @param [in] PANEL_PARAMETERS_ST stPanelPara Specify panel parameters.
 * @retval VOID
*/
VOID Mid_CRTC_SetPanelTiming(OUTPUT_FORMAT emof, PANEL_PARAMETERS_ST stPanelPara);

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
								OUTPUT_FORMAT enOutputFormat);

/**
 * @brief This function set CRTC slave mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_CRTC_SetSlaveModeEnable(BOOL bEnable);

/**
 * @brief This function set CRTC lbmc delay
 * @param [in] OUTPUT_RESOLUTION emor
 * @retval VOID
*/
VOID Mid_CRTC_SetLbmcTrigDly(OUTPUT_RESOLUTION emor);

/**
 * @brief This function set 3d LR signal
 * @param [in] BOOL bEnable
 * @param [in] UINT32 u32Cycle
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_CRTC_Set3DLR(BOOL bEnable, UINT32 u32Cycle, UINT32 u32Pattern);

#endif
