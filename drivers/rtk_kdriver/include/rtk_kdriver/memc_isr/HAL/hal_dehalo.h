/**
 * @file hal_dehalo.h
  * @brief This file is for dehalo register setting
  * @date Nov.14.2014
  * @version V0.0.1
  * @author Martin Yan
  * @par Copyright (C) 2014 Real-Image Co. LTD
  * @par History:
  * 		 Version: 0.0.1
 */

#ifndef _HAL_DEHALO_HEADER_INCLUDE_
#define _HAL_DEHALO_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set Dehalo on/off
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetEnable(BOOL bEnable);

/**
 * @brief This function set Dehalo row size
 * @param [in] UINT32 u32Row_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetRowSize(UINT32 u32Row_Size);

/**
 * @brief This function set Dehalo block size
 * @param [in] UINT32 u32Block_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetBlockSize(UINT32 u32Block_Size);

/**
 * @brief This function set Dehalo logo row size
 * @param [in] UINT32 u32Row_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetLogoRowSize(UINT32 u32Row_Size);

/**
 * @brief This function set Dehalo logo block size
 * @param [in] UINT32 u32Block_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetLogoBlockSize(UINT32 u32Block_Size);

/**
 * @brief This function set Dehalo YX ratio
 * @param [in] UINT32 u32YXRatio
 * @retval VOID
*/
VOID HAL_Dehalo_SetYXRatio(UINT32 u32YXRatio);

/**
 * @brief This function set Dehalo block number
 * @param [in] UINT32 u32Block_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetBlockNum(UINT32 u32Block_Num);

/**
 * @brief This function set Dehalo row number
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetRowNum(UINT32 u32Row_Num);

/**
 * @brief This function set Dehalo vbuf block number
 * @param [in] UINT32 u32Block_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufBlockNum(UINT32 u32Block_Num);

/**
 * @brief This function set Dehalo vbuf row number
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufRowNum(UINT32 u32Row_Num);

/**
 * @brief This function set Dehalo PR enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetPREnable(BOOL bEnable);

/**
 * @brief This function set Dehalo MV RD intval
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetMVRDIntval(BOOL bEnable);

/**
 * @brief This function set half v timing
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetHalfVTiming(BOOL bEnable);

/**
 * @brief This function set patt size
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetPattSize(BOOL bEnable);

/**
 * @brief This function set out timing mux
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID HAL_Dehalo_SetOutTimimgMux(UINT32 u32Val);

/**
 * @brief This function set rd lr flow wr latch
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetRDLRFlowWRLatch(BOOL bEnable);


/**
 * @brief This function set sw reset
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetSWReset(BOOL bEnable);

/**
 * @brief This function set Dehalo patt block / row number
 * @param [in] UINT32 u32Block_Num
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetPatternBlockRow(UINT32 u32Block_Num, UINT32 u32Row_Num);

/**
 * @brief This function set Dehalo vbuf block / row number
 * @param [in] UINT32 u32Block_Num
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufBlockRow(UINT32 u32Block_Num, UINT32 u32Row_Num);

/**
 * @brief This function set Dehalo show enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetShowEnable(BOOL bEnable);
/**
 * @brief This function set Dehalo show select
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetShowSelect(UINT32 u32Select);

/**
 * @brief This function set Dehalo erosion mode
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetErosionMode(BOOL bEnable);

#endif

