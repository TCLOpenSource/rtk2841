/**
 * @file mid_sys.c
 * @brief This file implements system api.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/MID/mid_sys.h"
#include "memc_isr/Common/memc_type.h"
#include "memc_isr/HAL/hal_ip.h"
#include "memc_isr/HAL/hal_dm.h"
#include "memc_isr/HAL/hal_post.h"

/**
 * @brief This function set MEMC output mute or unmute.
 *			This function is mostly used before/after signal change to avoid mess screen.
 * @param [in] bMute			Input mute state want to set
 * @retval VOID
*/
VOID Mid_Sys_SetMute(BOOL bMute)
{
	HAL_POST_SetMuteScreenEnable(bMute);
}

/**
 * @brief This function set MEMC output mute color
 * @param [in] bREnable			color r enable or not
 * @param [in] bREnable			color g enable or not
 * @param [in] bREnable			color b enable or not
 * @retval VOID
*/
VOID Mid_Sys_SetMuteColor(BOOL bREnable, BOOL bGEnable, BOOL bBEnable)
{
	UINT32 u32Mute_RGB = 0,u32Mute_R = 0,u32Mute_G = 0,u32Mute_B = 0;
	if(bBEnable)
	{
		u32Mute_R = (1 << 0) + (1 << 3) + (1 << 6) + (1 << 9);
	}

	if(bGEnable)
	{
		u32Mute_G = (1 << 1) + (1 << 4) + (1 << 7) + (1 << 10);
	}

	if(bREnable)
	{
		u32Mute_B = (1 << 2) + (1 << 5) + (1 << 8) + (1 << 11);
	}

	u32Mute_RGB = u32Mute_R + u32Mute_G + u32Mute_B;

	HAL_POST_SetMuteScreenRGBEnable(u32Mute_RGB);
}

/**
 * @brief This function set SG out lr inverse
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetSGOutLRInverse(BOOL bEnable)
{
	//info phase decode to inverse out lr
}

/**
 * @brief This function set PR out lr inverse
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetPROutLRInverse(BOOL bEnable)
{
	HAL_DM_SetKmcOutput3DMode((UINT32)(!bEnable));
}

/**
 * @brief This function set 3d fs lr inverse
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_Set3DFSLRInverse(BOOL bEnable)
{
	HAL_IP_Set3DFSLRInverse(bEnable);
}

/**
 * @brief This function set ippre use mute sync enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetUseMuteSyncEnable(BOOL bEnable)
{
	HAL_IP_SetIPPREMuteUseMuteSyncEnable(bEnable);
}

/**
 * @brief This function set ippre mute detect enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetMuteDetectEnable(BOOL bEnable)
{
	HAL_IP_SetIPPREMuteSetMuteDetectEnable(bEnable);
}

