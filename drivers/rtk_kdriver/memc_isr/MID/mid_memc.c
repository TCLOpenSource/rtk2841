/**
 * @file mid_memc.c
 * @brief This file implements all memc api.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/MID/mid_memc.h"
#include "memc_isr/Common/memc_type.h"
#include "memc_isr/include/PQLAPI.h"

#include <mach/rtk_log.h>

/**
 * @brief This function set MEMC deblur level.
 * @param [in] iLevel Specify memc deblur level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCDeblurLevel(UINT16 u16Level)
{
	BOOL	bRet = TRUE;
	_PQL_Command Command;
	Command.u4_memc_mode_deblur_lvl = (UBYTE)u16Level;
	PQL_Command(PQL_CMD_MEMC_MODE_DEBLUR, &Command);
	return bRet;
}

/**
 * @brief This function set MEMC dejudderlevel.
 * @param [in] iLevel Specify memc dejudder level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCDejudderLevel(UINT16 u16Level)
{
	BOOL	bRet = TRUE;
	_PQL_Command Command;
	Command.u4_memc_mode_dejudder_lvl = (UBYTE)u16Level;
	PQL_Command(PQL_CMD_MEMC_MODE_DEJUDDER, &Command);
	return bRet;
}

/**
 * @brief This function set MEMC Module Ratio.
 * @param [in] UBYTE pix sft.
 * @param [in] UBYTE blk sft.
 * @param [in] UBYTE pix sft.
 * @param [in] UBYTE blk sft.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCModuleRatio(UBYTE u8_in_me1_pix_sft,UBYTE u8_in_me1_blk_sft,UBYTE u8_in_me2_pix_sft,UBYTE u8_in_me2_blk_sft)
{
	BOOL	bRet = TRUE;
	_PQL_Command Command;
	Command._stc_memc_module_ratio.u8_in_me1_pix_sft = u8_in_me1_pix_sft;
	Command._stc_memc_module_ratio.u8_in_me1_blk_sft = u8_in_me1_blk_sft;
	Command._stc_memc_module_ratio.u8_in_me2_pix_sft = u8_in_me2_pix_sft;
	Command._stc_memc_module_ratio.u8_in_me2_blk_sft = u8_in_me2_blk_sft;
	PQL_Command(PQL_CMD_MEMC_MODULE_RATIO, &Command);
	return bRet;
}

/**
 * @brief This function set MEMC fallback level.
 * @param [in] iLevel Specify memc fallback level.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetMEMCFBLevel(UINT16 u16Level)
{
	BOOL	bRet = TRUE;
	_PQL_Command Command;
	Command.u4_memc_mode_fb_lvl = (UBYTE)u16Level;
	PQL_Command(PQL_CMD_MEMC_MODE_FB, &Command);
	return bRet;
}

/**
 * @brief This function set MEMC RIM window. The rim window defines out black region while on film scene.
 * @param [in] u32Top			rim window video vertical start line
 * @param [in] u32Bottom			rim window video vertical end line
 * @param [in] u32Left 			rim window video left start line
 * @param [in] u32Right			rim window video right end line
 * @retval TRUE 				indicates success
 * @retval FALSE				indicates fail
*/
BOOL Mid_MEMC_SetRimWindow(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right)
{
	BOOL	bRet = FALSE;

	return bRet;
}

/**
 * @brief This function set pulldown_mode.
 * @param [in] enInputFrameRate Specify memc input framerate.
 * @param [in] enOutputFrameRate Specify memc output framerate.
 * @param [in] TruMotionMode Specify memc mode(OFF/CLEAR/NORMAL/SMOOTH).
 * @param [in] enRealCinema Specify cinema mode.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_MEMC_SetPullDownMode(INPUT_FRAMERATE enInputFrameRate, OUTPUT_FRAMERATE enOutputFrameRate, UBYTE bTruMotionMode, UBYTE enRealCinema)
{
	BOOL	bRet = TRUE;
	BOOL	bEnRealCinema = (enRealCinema == TRUE);
	PQL_OUTPUT_PULLDOWN_MODE	mPullDownMode = _PQL_PULLDOWN_MODE_ELSE;
	_PQL_Command Command;

	// 2D/3D
	// all@24hz in, TruMotion off, Cinema on : 55 pull down@120hz out, 22 pull down@48hz out
	// all@24hz in, TruMotion off, Cinema off : 64 pull down@120hz out, 32 pull down@60hz out
	// all@25hz in, TruMotion off, Cinema off : 44 pull down@100hz out, 22 pull down@50hz out
	// all@30hz in, TruMotion off, Cinema off : 44 pull down@120hz out, 22 pull down@60hz out
	// all@50hz in, TruMotion off, Cinema off : 22 pull down@100hz out, bypass@50hz out
	// all@60hz in, TruMotion off, Cinema off : 22 pull down@120hz out, bypass@60hz out
	// all@60hz 32,TruMotion off, Cinema on : 55 pull down@120hz out, 32 pull down@60hz out
	// all@60hz 32,TruMotion off, Cinema off : 64 pull down@120hz out, 32 pull down@60hz out
	if(enInputFrameRate == INPUT_FRAMERATE_24HZ && (enOutputFrameRate == OUTPUT_FRAMERATE_48HZ || enOutputFrameRate == OUTPUT_FRAMERATE_120HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == TRUE)
	{
		mPullDownMode = _PQL_IN24HZ_TRUMOTOFF_CINEMAON;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_24HZ && (enOutputFrameRate == OUTPUT_FRAMERATE_60HZ || enOutputFrameRate == OUTPUT_FRAMERATE_120HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == FALSE)
	{
		mPullDownMode = _PQL_IN24HZ_TRUMOTOFF_CINEMAOFF;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_25HZ && (enOutputFrameRate == OUTPUT_FRAMERATE_50HZ || enOutputFrameRate == OUTPUT_FRAMERATE_100HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == FALSE)
	{
		mPullDownMode = _PQL_IN25HZ_TRUMOTOFF_CINEMAOFF;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_30HZ && (enOutputFrameRate == OUTPUT_FRAMERATE_60HZ || enOutputFrameRate == OUTPUT_FRAMERATE_120HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == FALSE)
	{
		mPullDownMode = _PQL_IN30HZ_TRUMOTOFF_CINEMAOFF;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_50HZ && (enOutputFrameRate == OUTPUT_FRAMERATE_50HZ || enOutputFrameRate == OUTPUT_FRAMERATE_100HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == FALSE)
	{
		mPullDownMode = _PQL_IN50HZ_TRUMOTOFF_CINEMAOFF;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_60HZ && (/*enOutputFrameRate == OUTPUT_FRAMERATE_60HZ || */enOutputFrameRate == OUTPUT_FRAMERATE_120HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == TRUE)
	{
		mPullDownMode = _PQL_IN60HZ_TRUMOTOFF_CINEMAON;
	}
	else if(enInputFrameRate == INPUT_FRAMERATE_60HZ && (/*enOutputFrameRate == OUTPUT_FRAMERATE_60HZ || */enOutputFrameRate == OUTPUT_FRAMERATE_120HZ)\
		&& bTruMotionMode == FALSE && bEnRealCinema == FALSE)
	{
		mPullDownMode = _PQL_IN60HZ_TRUMOTOFF_CINEMAOFF;
	}
	else if(bTruMotionMode == FALSE)
	{
		mPullDownMode = _PQL_INXHZ_TRUMOTOFF;
	}

	Command.u8_pulldown_mode= mPullDownMode;
	printk("[MEMC]mPullDownMode = %d (InFR=%d, OutFR=%d, isMemcON=%d, isCinemaON=%d)\r\n",\
						mPullDownMode, enInputFrameRate, enOutputFrameRate, bTruMotionMode,bEnRealCinema);
	PQL_Command(PQL_CMD_PULLDOWNMODE, &Command);

	LogPrintf(DBG_MSG, "mPullDownMode = %d (InFR=%d, OutFR=%d, isMemcON=%d, isCinemaON=%d)\r\n",\
						mPullDownMode, enInputFrameRate, enOutputFrameRate, bTruMotionMode,bEnRealCinema);


	return bRet;
}




