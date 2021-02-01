/**
 * @file hal_ip.h
  * @brief This file is for ip register setting
  * @date Nov.14.2014
  * @version V0.0.1
  * @author Martin Yan
  * @par Copyright (C) 2014 Real-Image Co. LTD
  * @par History:
  * 		 Version: 0.0.1
 */

#ifndef _HAL_IP_HEADER_INCLUDE_
#define _HAL_IP_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set ippre csc enable
 * @param [in] BOOL bEnable true for enable, false for diable
 * @retval VOID
*/
VOID HAL_IP_SetIPPRECSCEnable(BOOL bEnable);

/**
 * @brief This function set ippre csc mode
 * @param [in] CSC_MODE enCSC_Mode
 * @retval VOID
*/
VOID HAL_IP_SetIPPRECSCMode(CSC_MODE enCSC_Mode);

/**
 * @brief This function set ippre 444to422 Enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPRE444to422Enable(BOOL bEnable);

/**
 * @brief This function set ippre retiming
 * @param [in] UINT32 u32Hact
 * @param [in] UINT32 u32Vact 
 * @retval VOID
*/
VOID HAL_IP_SetIPPRERetiming(UINT32 u32Hact, UINT32 u32Vact);

/**
 * @brief This function get ippre retiming dummy de
 * @param [in] VOID
 * @param [in] UINT32 u32Vact 
 * @retval retiming dummy de
*/
UINT32 HAL_IP_GetIPPRERetimingDummyDE(VOID);

/**
 * @brief This function set ippre pattern size
 * @param [in] TIMING_PARA_ST stInputTiming 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREPatternSize(TIMING_PARA_ST stInputTiming);

/**
 * @brief This function set ippre use mute sync enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteUseMuteSyncEnable(BOOL bEnable);

/**
 * @brief This function set ippre mute set mute detect enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteSetMuteDetectEnable(BOOL bEnable);

/**
 * @brief This function set ippre mute h active
 * @param [in] UINT32 u32Hact 
 * @param [in] UINT32 u32Hact_Min 
 * @param [in] UINT32 u32Hact_Max 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteHactive(UINT32 u32Hact, UINT32 u32Hact_Min, UINT32 u32Hact_Max);

/**
 * @brief This function set ippre v active
 * @param [in] UINT32 u32Vact 
 * @param [in] UINT32 u32Vact_Min 
 * @param [in] UINT32 u32Vact_Max 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteVactive(UINT32 u32Vact, UINT32 u32Vact_Min, UINT32 u32Vact_Max);

/**
 * @brief This function set ippre mute clock threshold
 * @param [in] UINT32 u32Clk_low_th 
 * @param [in] UINT32 u32Clk_high_th 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteClockThreshold(UINT32 u32Clk_low_th, UINT32 u32Clk_high_th);

/**
 * @brief This function set 3d fs lr inverse
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID HAL_IP_Set3DFSLRInverse(BOOL bEnable);

#ifndef REAL_CHIP	// FPGA
/**
 * @brief This function set topA ipme retiming
 * @param [in] TIMING_PARA_ST stInputTiming
 * @retval VOID
*/
VOID HAL_IP_SetTOPA_IPMERetiming(TIMING_PARA_ST stInputTiming);

/**
 * @brief This function set 2 port enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_IP_SetTOPA2PortEnable(BOOL bEnable);

/**
 * @brief This function set topB mute timing
 * @param [in] TIMING_PARA_ST stInputTiming
 * @param [in] TIMING_PARA_ST stOutputTiming 
 * @retval VOID
*/
VOID HAL_IP_SetTOPBMuteTiming(TIMING_PARA_ST stInputTiming, TIMING_PARA_ST stOutputTiming);

/**
 * @brief This function set mute lr self gen
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_IP_SetTOPBMuteLRSelfGen(BOOL bEnable);
#endif

/**
 * @brief This function set ip data mapping
 * @param [in] UINT32 u32Data_Mapping 
 * @retval VOID
*/
VOID HAL_IP_SetDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get ip data mapping
 * @param [in] VOID
 * @retval data mapping
*/
UINT32 HAL_IP_GetDataMapping(VOID);

#endif
