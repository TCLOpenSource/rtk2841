/**
 * @file mid_sys.h
 * @brief This file implements system api.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_SYS_HEADER_INCLUDE_
#define _MID_SYS_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set MEMC output mute or unmute. 
 *			This function is mostly used before/after signal change to avoid mess screen.
 * @param [in] bMute			Input mute state want to set
 * @retval VOID
*/
VOID Mid_Sys_SetMute(BOOL bMute);

/**
 * @brief This function set MEMC output mute color
 * @param [in] bREnable			color r enable or not
 * @param [in] bREnable			color g enable or not
 * @param [in] bREnable			color b enable or not
 * @retval VOID
*/
VOID Mid_Sys_SetMuteColor(BOOL bREnable, BOOL bGEnable, BOOL bBEnable);

/**
 * @brief This function set SG out lr inverse
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetSGOutLRInverse(BOOL bEnable);

/**
 * @brief This function set PR out lr inverse
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetPROutLRInverse(BOOL bEnable);

/**
 * @brief This function set 3d fs lr inverse
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_Set3DFSLRInverse(BOOL bEnable);

/**
 * @brief This function set ippre use mute sync enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetUseMuteSyncEnable(BOOL bEnable);

/**
 * @brief This function set ippre mute detect enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetMuteDetectEnable(BOOL bEnable);

#endif
