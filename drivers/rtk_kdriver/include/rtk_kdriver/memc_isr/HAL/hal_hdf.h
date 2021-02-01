/**
 * @file hal_hdf.h
 * @brief This file is for HDF loading.
 * @date October.28.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _HAL_HDF_HEADER_INCLUDE_
#define _HAL_HDF_HEADER_INCLUDE_
	
#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

#define USE_LOAD_HDF
/**
 * @brief This function load default hdf.
 * @param [in] VOID.
 * @retval VOID
*/
VOID HAL_HDF_Load(VOID);
#endif
