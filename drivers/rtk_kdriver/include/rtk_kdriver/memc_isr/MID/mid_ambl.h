/**
 * @file mid_ambl.h
 * @brief This file implements amblight api.
 * @date March.25.2015
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_AMBL_HEADER_INCLUDE_
#define _MID_AMBL_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"

/**
 * @brief This function set amblight enable or disable
 * @param [in] bEnalbe enable or disable amblight
*/
VOID Mid_AMBL_SetEnable(BOOL bEnalbe);

/**
 * @brief This function set amblight enable or disable
 * @param [in] bEnalbe enable or disable amblight
*/
VOID Mid_AMBL_SetConfig(UINT32 u32Width, UINT32 u32Length);

/**
 * @brief This function set amblight Frq
 * @param [in] u32Frq
*/
VOID Mid_AMBL_SetFrq(UINT32 u32Frq);
#endif