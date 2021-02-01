/**
 * @file mid_memc.h
 * @brief This file implements all memc api.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_MEMC_HEADER_INCLUDE_
#define _MID_MEMC_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set MEMC deblur level. 
 * @param [in] iLevel Specify memc deblur level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCDeblurLevel(UINT16 u16Level);

/**
 * @brief This function set MEMC dejudderlevel. 
 * @param [in] iLevel Specify memc dejudder level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCDejudderLevel(UINT16 u16Level);

/**
 * @brief This function set MEMC Module Ratio. 
 * @param [in] UBYTE pix sft.
 * @param [in] UBYTE blk sft.
 * @param [in] UBYTE pix sft.
 * @param [in] UBYTE blk sft.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCModuleRatio(UBYTE u8_in_me1_pix_sft,UBYTE u8_in_me1_blk_sft,UBYTE u8_in_me2_pix_sft,UBYTE u8_in_me2_blk_sft);

/**
 * @brief This function set MEMC fallback level.
 * @param [in] iLevel Specify memc fallback level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCFBLevel(UINT16 u16Level);

/**
 * @brief This function set MEMC RIM window. The rim window defines out black region while on film scene.
 * @param [in] u32Top			rim window video vertical start line
 * @param [in] u32Bottom			rim window video vertical end line
 * @param [in] u32Left 			rim window video left start line
 * @param [in] u32Right			rim window video right end line
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
BOOL Mid_MEMC_SetRimWindow(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right);

/**
 * @brief This function set pulldown_mode.
 * @param [in] enInputFrameRate Specify memc input framerate.
 * @param [in] enOutputFrameRate Specify memc output framerate.
 * @param [in] TruMotionMode Specify memc mode(OFF/CLEAR/NORMAL/SMOOTH).
 * @param [in] enRealCinema Specify cinema mode.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetPullDownMode(INPUT_FRAMERATE enInputFrameRate, OUTPUT_FRAMERATE enOutoutFrameRate, UBYTE bTruMotionMode, UBYTE enRealCinema);

#endif
