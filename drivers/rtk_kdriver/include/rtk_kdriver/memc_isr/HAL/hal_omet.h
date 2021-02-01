/**
 * @file hal_omet.h
 * @brief This file is for OMET register settings.
 * @date Sep.01.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par MEMC Library V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _HAL_OMET_HEADER_
#define _HAL_OMET_HEADER_

#include "kw_common.h"
#include "regio.h"

/**
 * @brief This function set MEMC two gains.
 * @param [in] ubyFirstGain		Specify first gain.
 * @param [in] ubySecondGain	Specify second gain.
*/
VOID HAL_OMET_SetTwoGains(UBYTE ubyFirstGain, UBYTE ubySecondGain);

/**
 * @brief This function get OMET two gains.
 * @param [out] pubyFirstGain	first gain return.
 * @param [out] pubySecondGain	second gain return.
*/
VOID HAL_OMET_GetTwoGains(UBYTE *pubyFirstGain, UBYTE *pubySecondGain);

/**
 * @brief This function set pedestal setting.
 * @param [in] ubyGain		pedestal gain setting
*/
VOID HAL_OMET_SetPedestal(UBYTE ubyGain);

/**
 * @brief This function get pedestal setting.
 * @retval prdestal setting
*/
UBYTE HAL_OMET_GetPedestal(VOID);

/**
 * @brief This function get OMET red power.
 * @retval R power
*/
UINT16 HAL_OMET_GetRedPower(VOID);

/**
 * @brief This function get OMET green power.
 * @retval G power
*/
UINT16 HAL_OMET_GetGreenPower(VOID);

/**
 * @brief This function get OMET blue power.
 * @retval B power
*/
UINT16 HAL_OMET_GetBluePower(VOID);

/**
 * @brief This function set OMET window setting.
 * @param [in] ubyIndex		Indicate which control, valid value is 0 or 1
 * @param [in] u16HStart	hstart pixel
 * @param [in] u16Width		width pixel, the window is hstart, hstart + width.
 * @param [in] u16VStart	vstart line
 * @param [in] u16Height	height lines, the window is vstart + height
*/
VOID HAL_OMET_SetWindowByIndex(UBYTE ubyIndex, UINT16 u16HStart, UINT16 u16Width, UINT16 u16VStart, UINT16 u16Height);

/**
 * @brief This function get OMET window setting.
 * @param [in] ubyIndex		Indicate which control, valid value is 0 or 1
 * @param [in] pu16HStart	hstart pixel
 * @param [in] pu16Width	width pixel, the window is hstart, hstart + width.
 * @param [in] pu16VStart	vstart line
 * @param [in] pu16Height	height lines, the window is vstart + height
*/
VOID HAL_OMET_GetWindowByIndex(UBYTE ubyIndex, UINT16 *pu16HStart, UINT16 *pu16Width, UINT16 *pu16VStart, UINT16 *pu16Height);

/**
 * @brief This function set OMET 3 parameter, dfilt and two threshhold.
 * @param [in] ubyIndex				Indicate which control, valid value is 0 or 1
 * @param [in] u16DFilt				dfilt value setting
 * @param [in] u16ThreshHold0		threshhold0 value setting.
 * @param [in] u16ThreshHold1		threshhold1 value setting.
*/
VOID HAL_OMET_SetCtrlByIndex(UBYTE ubyIndex, UINT16 u16DFilt, UINT16 u16ThreshHold0, UINT16 u16ThreshHold1);

/**
 * @brief This function get OMET 3 parameter, dfilt and two threshhold.
 * @param [in] ubyIndex				Indicate which control, valid value is 0 or 1
 * @param [out] puiDFilt			dfilt value setting
 * @param [out] puiThreshHold0		threshhold0 value setting.
 * @param [out] puiThreshHold1		threshhold1 value setting.
*/
VOID HAL_OMET_GetCtrlByIndex(UBYTE ubyIndex, UINT16 *pu16DFilt, UINT16 *pu16ThreshHold0, UINT16 *pu16ThreshHold1);

/**
 * @brief This function get OMET 4 pixel count.
 * @param [out] pu16PixelCount0		Pixel count 0.
 * @param [out] pu16PixelCount1		Pixel count 1.
 * @param [out] pu16PixelCount2		Pixel count 2.
 * @param [out] pu16PixelCount3		Pixel count 3.
*/
VOID HAL_OMET_GetPixelCountByIndex(UINT16 *pu16PixelCount0, UINT16 *pu16PixelCount1, UINT16 *pu16PixelCount2, UINT16 *pu16PixelCount3);

/**
 * @brief This function get OMET 256*24bits histogram. The histo and OMET result should be calced and new gain should be set before next frame.
		  Typically, its 50Hz or 60Hz, for 100Hz and 120Hz, some frames maybe skipped.
 * @param [in/out] puiHistogram			Histogram buffer
 * @param [in] iBufSize					buffer size.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL HAL_OMET_GetHistogram(UINT32 *puiHistogram, SINT32 iBufSize);

#endif
