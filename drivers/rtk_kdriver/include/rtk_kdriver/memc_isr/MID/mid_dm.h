/**
 * @file mid_dm.h
 * @brief This file is the header for DM controller.
 * @date Nov.19.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_DM_HEADER_INCLUDE_
#define _MID_DM_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set kme start address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEStartAddress(ME_DM_ADDRESS_ST *pMEDMAddr);

/**
 * @brief This function set kme end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEEndAddress(ME_DM_ADDRESS_ST *pMEDMAddr);

/**
 * @brief This function set kme buffer offset address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEOffsetAddress(ME_DM_ADDRESS_ST *pMEDMAddr);

/**
 * @brief This function set kmc start address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMCStartAddress(MC_DM_ADDRESS_ST *pMCDMAddr);

/**
 * @brief This function set kmv start address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVStartAddress(MV_DM_ADDRESS_ST *pMVDMAddr);

/**
 * @brief This function set kme end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVEndAddress(MV_DM_ADDRESS_ST *pMVDMAddr);

/**
 * @brief This function set kmv buffer offset address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVOffsetAddress(MV_DM_ADDRESS_ST *pMVDMAddr);

/**
 * @brief This function set kmc end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMCEndAddress(MC_DM_ADDRESS_ST *pMCDMAddr);

/**
 * @brief This function set kmc offset address
 * @param [in] INOUT_MODE eMode
 * @retval VOID
*/
VOID Mid_DM_SetKMCOffsetAddress(UINT32 u32LineOffset, UINT32 u32LROffset);

/**
 * @brief This function set kmc engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMCEngineEnable(BOOL bEnable);

/**
 * @brief This function set kme engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMEEngineEnable(BOOL bEnable,  INOUT_MODE emom, INPUT_FORMAT emif, OUTPUT_FORMAT emof);

/**
 * @brief This function set kmv engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMVEngineEnable(BOOL bEnable);

#endif
