/**
 * @file hal_hdf.c
 * @brief This file is for HDF loading.
 * @date October.28.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/HAL/hal_hdf.h"
#include "memc_isr/include/hdf.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Driver/regio.h"

#define FILE_HEADER_SIZE		64
#define PAGE_HEADER_SIZE		16
#define PAGE_ADDRESS_OFFSET		4
#define PAGE_SIZE_OFFSET		8

/**
 * @brief This function load default hdf.
 * @param [in] VOID.
 * @retval VOID
*/
VOID HAL_HDF_Load(VOID)
{
	return;
#ifdef USE_LOAD_HDF
	UINT32 u32PageNum = 0;
	UINT32 u32PageSize = 0;
	UINT32 u32Page_Idx = 0;
	UINT32 u32Page_Offset = 0;
	UINT32 u32Page_Addr = 0;
	UINT32 u32Page_Reg_Idx = 0;
	UINT32 u32Page_Reg_Addr = 0;
	UINT32 u32Page_Reg_Val = 0;

	u32PageNum = (u8HDF_Array[7] << 24) + (u8HDF_Array[6] << 16) + (u8HDF_Array[5] << 8) + u8HDF_Array[4];
	u32Page_Offset = FILE_HEADER_SIZE;
	for(u32Page_Idx = 0; u32Page_Idx < u32PageNum; u32Page_Idx++)
	{	
		//LogPrintf(DBG_MSG, "u32Page_Idx = %d\r\n", u32Page_Idx);

		u32PageSize = (u8HDF_Array[u32Page_Offset + PAGE_SIZE_OFFSET + 3] << 24) + 
					  (u8HDF_Array[u32Page_Offset + PAGE_SIZE_OFFSET + 2] << 16) + 
					  (u8HDF_Array[u32Page_Offset + PAGE_SIZE_OFFSET + 1] << 8) + 
					   u8HDF_Array[u32Page_Offset + PAGE_SIZE_OFFSET];
		u32Page_Addr = (u8HDF_Array[u32Page_Offset + PAGE_ADDRESS_OFFSET + 3] << 24) + 
					   (u8HDF_Array[u32Page_Offset + PAGE_ADDRESS_OFFSET + 2] << 16) + 
					   (u8HDF_Array[u32Page_Offset + PAGE_ADDRESS_OFFSET + 1] << 8) + 
					    u8HDF_Array[u32Page_Offset + PAGE_ADDRESS_OFFSET];
		for(u32Page_Reg_Idx = 0; u32Page_Reg_Idx < u32PageSize / 4; u32Page_Reg_Idx++)
		{
			u32Page_Reg_Addr = u32Page_Addr + u32Page_Reg_Idx * 4;
			u32Page_Reg_Val = (u8HDF_Array[u32Page_Offset + PAGE_HEADER_SIZE + u32Page_Reg_Idx * 4 + 3] << 24) + 
					   		  (u8HDF_Array[u32Page_Offset + PAGE_HEADER_SIZE + u32Page_Reg_Idx * 4 + 2] << 16) + 
					   		  (u8HDF_Array[u32Page_Offset + PAGE_HEADER_SIZE + u32Page_Reg_Idx * 4 + 1] << 8) + 
					    	   u8HDF_Array[u32Page_Offset + PAGE_HEADER_SIZE + u32Page_Reg_Idx * 4];
			WriteRegister(u32Page_Reg_Addr, 0, 31, u32Page_Reg_Val);
		}
		u32Page_Offset = u32Page_Offset + PAGE_HEADER_SIZE + u32PageSize;
		if(u32Page_Idx == u32PageNum - 1)
		{
			LogPrintf(DBG_MSG, "Load hdf done... Total %d pages\r\n", u32PageNum);
		}
	}
#endif
}
