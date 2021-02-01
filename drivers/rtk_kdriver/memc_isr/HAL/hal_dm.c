/**
 * @file hal_dm.c
 * @brief This file is for  DM controller.
 * @date September.12.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Driver/regio.h"

/**
 * @brief This function get kmc 00 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress0(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address0),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress1(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address1
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address1),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress2(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address2
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address2),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress3(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address3
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address3),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress4(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address4
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address4),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00StartAddress5(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_start_address5
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address5),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc00LineOffsetAddress(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_00_line_offset_addr
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_line_offset_addr),&u32Val);
	return u32Val;
}

/**
 * @brief This function set kmc 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress0(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address0),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress1(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address1
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address1),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress2(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address2
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address2),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress3(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address3
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address3),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress4(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address4
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address4),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress5(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address5
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address5),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress6(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address6
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address6),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00EndAddress7(UINT32 u32Address)
{
	return;
	//reg_kmc_00_end_address7
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_end_address7),u32Address); 
}

/**
 * @brief This function set kmc 00 lr offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00LROffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kmc_00_lr_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_lr_offset_addr),u32Address);
}

/**
 * @brief This function set kmc 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kmc_00_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_line_offset_addr),u32Address);
}

/**
 * @brief This function set kmc 00 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address0),u32Address);
}

/**
 * @brief This function set kmc 00 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address1),u32Address);
}

/**
 * @brief This function set kmc 00 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress2(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address2
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address2),u32Address);
}

/**
 * @brief This function set kmc 00 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress3(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address3
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address3),u32Address);
}

/**
 * @brief This function set kmc 00 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress4(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address4
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address4),u32Address);
}

/**
 * @brief This function set kmc 00 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress5(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address5
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address5),u32Address);
}

/**
 * @brief This function set kmc 00 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress6(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address6
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address6),u32Address);
}

/**
 * @brief This function set kmc 00 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc00StartAddress7(UINT32 u32Address)
{
	return;
	//reg_kmc_00_start_address7
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_start_address7),u32Address);
}

/**
 * @brief This function set kmc 01 lr offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01LROffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kmc_01_lr_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_lr_offset_addr),u32Address);
}

/**
 * @brief This function set kmc 01 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kmc_01_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_line_offset_addr),u32Address);
}

/**
 * @brief This function set kmc 01 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address0),u32Address);
}

/**
 * @brief This function set kmc 01 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address1),u32Address);
}

/**
 * @brief This function set kmc 01 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress2(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address2),u32Address);
}

/**
 * @brief This function set kmc 01 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress3(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address3
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address3),u32Address);
}

/**
 * @brief This function set kmc 01 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress4(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address4
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address4),u32Address);
}

/**
 * @brief This function set kmc 01 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress5(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address5
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address5),u32Address);
}

/**
 * @brief This function set kmc 01 start address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress6(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address6
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address6),u32Address);
}

/**
 * @brief This function set kmc 01 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01StartAddress7(UINT32 u32Address)
{
	return;
	//reg_kmc_01_start_address7
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address7),u32Address);
}

/**
 * @brief This function get kmc 01 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress0(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address0),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 01 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress1(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address1
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address1),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress2(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address2
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address2),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress3(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address3
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address3),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress4(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address4
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address4),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01StartAddress5(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_start_address5
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_start_address5),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kmc 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKmc01LineOffsetAddress(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kmc_01_line_offset_addr
	ReadRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_line_offset_addr),&u32Val);
	return u32Val;
}

/**
 * @brief This function set kmc 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress0(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address0),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress1(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address1
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address1),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress2(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address2
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address2),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress3(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address3
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address3),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress4(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address4
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address4),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress5(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address5
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address5),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress6(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address6
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address6),u32Address); 
}

/**
 * @brief This function set kmc 00 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmc01EndAddress7(UINT32 u32Address)
{
	return;
	//reg_kmc_01_end_address7
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_end_address7),u32Address); 
}

/**
 * @brief This function set kmc vtotal
 * @param [in] UINT32 u32Vtotal
 * @retval VOID
*/
VOID HAL_DM_SetKmcVtotal(UINT32 u32Vtotal)
{
	return;
	//reg_kmc_vtotal
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_vtotal),u32Vtotal);
}

/**
 * @brief This function set kmc input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcInput3DEnable(BOOL bEnable)
{
	return;
	//reg_kmc_input_3d_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_input_3d_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc input 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmcInput3DMode(UINT32 u32Mode)
{
	return;
	//reg_kmc_input_3d_mode
 	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_input_3d_mode),u32Mode);	
}

/**
 * @brief This function set kmc output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcOutput3DEnable(BOOL bEnable)
{
	return;
	//reg_kmc_output_3d_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_output_3d_enable),(UINT32)bEnable);	
}

/**
 * @brief This function set kmc output 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmcOutput3DMode(UINT32 u32Mode)
{
	return;
	//reg_kmc_output_3d_mode
 	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_output_3d_mode),u32Mode);	
}

/**
 * @brief This function set kmc 422 enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc422Enable(BOOL bEnable)
{
	return;
	//reg_kmc_mode422_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_mode422_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmcVflipEnable(BOOL bEnable)
{
	return;
	//reg_kmc_vflip_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_vflip_enable),(UINT32)bEnable);
}

/**
 * @brief This function set dm pr mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetPRMode(UINT32 u32Mode)
{
	return;
	//reg_kmc_pr_mode
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_pr_mode),u32Mode);
}

/**
 * @brief This function set kmc 00 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc00WriteEnable(BOOL bEnable)
{
	return;
	//reg_kmc_00_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_00_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc 01 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc01WriteEnable(BOOL bEnable)
{
	return;
	//reg_kmc_01_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_01_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc 04 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc04ReadEnable(BOOL bEnable)
{
	return;
	//reg_kmc_04_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_04_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc 05 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc05ReadEnable(BOOL bEnable)
{
	return;
	//reg_kmc_05_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_05_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc 06 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc06ReadEnable(BOOL bEnable)
{
	return;
	//reg_kmc_06_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_06_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmc 07 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmc07ReadEnable(BOOL bEnable)
{
	return;
	//reg_kmc_07_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KMC_DM_TOP__reg_kmc_07_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function get kme 00 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress0(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address0),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress1(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address1),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 start address 2
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress2(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address2),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 start address 3
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress3(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address3),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 start address 4
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress4(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address4),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 start address 5
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00StartAddress5(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address5),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 00 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme00LineOffsetAddress(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_line_offset_addr
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_line_offset_addr),&u32Val);	
	return u32Val;
}

/**
 * @brief This function set kme 00 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address0),u32Address);	
}

/**
 * @brief This function set kme 00 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address1),u32Address);	
}

/**
 * @brief This function set kme 00 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress2(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address2),u32Address);	
}

/**
 * @brief This function set kme 00 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress3(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address3),u32Address);	
}

/**
 * @brief This function set kme 00 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress4(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address4),u32Address);	
}

/**
 * @brief This function set kme 00 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00EndAddress5(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_end_address5),u32Address);	
}

/**
 * @brief This function get kme 12 start address 0
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12StartAddress0(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_start_address0),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 12 start address 1
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12StartAddress1(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_start_address0
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_start_address1),&u32Val);
	return u32Val;
}

/**
 * @brief This function get kme 12 line offset address
 * @param [in] VOID
 * @retval Address
*/
UINT32 HAL_DM_GetKme12LineOffsetAddress(VOID)
{
	return;
	UINT32 u32Val = 0;
	//reg_kme_00_line_offset_addr
	ReadRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_line_offset_addr),&u32Val);	
	return u32Val;
}

/**
 * @brief This function set kme 12 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12EndAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_end_address0),u32Address);	
}

/**
 * @brief This function set kme 12 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12EndAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_00_end_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_end_address1),u32Address);	
}

/**
 * @brief This function set kme 00 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme00WriteEnable(BOOL bEnable)
{
	return;
	//reg_kme_00_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 01 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme01ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_01_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_01_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 02 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme02ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_02_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_02_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 03 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme03ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_03_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_03_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 04 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme04WriteEnable(BOOL bEnable)
{
	return;
	//reg_kme_04_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_04_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 05 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme05WriteEnable(BOOL bEnable)
{
	return;
	//reg_kme_05_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_05_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 06 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme06ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_06_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_06_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 07 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme07ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_07_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_07_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 08 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme08WriteEnable(BOOL bEnable)
{
	return;
	// reg_kme_08_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_08_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 09 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme09ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_09_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_09_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 10 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme10WriteEnable(BOOL bEnable)
{
	return;
	// reg_kme_10_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_10_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 11 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme11ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_11_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_11_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 12 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme12WriteEnable(BOOL bEnable)
{
	return;
	// reg_kme_12_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 13 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme13ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_13_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_13_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 14 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme14WriteEnable(BOOL bEnable)
{
	return;
	// reg_kme_14_write_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_14_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 15 read enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKme15ReadEnable(BOOL bEnable)
{
	return;
	// reg_kme_15_read_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_15_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeInput3DEnable(BOOL bEnable)
{
	return;
	//reg_kme_input_3d_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_input_3d_enable),(UINT32)bEnable);	
}

/**
 * @brief This function set kme input 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmeInput3DMode(UINT32 u32Mode)
{
	return;
	//reg_kme_input_3d_mode
 	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_input_3d_mode),u32Mode);		
}

/**
 * @brief This function set kme output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeOutput3DEnable(BOOL bEnable)
{
	return;
	//reg_kme_output_3d_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_output_3d_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme output 3d Mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmeOutput3DMode(UINT32 u32Mode)
{
	return;
	//reg_kme_output_3d_mode
 	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_output_3d_mode),u32Mode);
}


/**
 * @brief This function set kme ME H/V active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmeMEActive(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	// reg_kme_me_hactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_me_hactive),u32Hactive);
	// reg_kme_me_vactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_me_vactive),u32Vactive);
}

/**
 * @brief This function set kme MV H/V active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmeMVActive(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	// reg_kme_mv_hactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_mv_hactive),u32Hactive);
	// reg_kme_mv_vactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_mv_vactive),u32Vactive);
}

/**
 * @brief This function set kme me hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmeMEHNum(UINT32 u32Hnum)
{
	return;
	// reg_kme_me_hnum
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_me_hnum),u32Hnum);
}

/**
 * @brief This function set kme mv hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmeMVHNum(UINT32 u32Hnum)
{
	return;
	// reg_kme_mv_hnum
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_mv_hnum),u32Hnum);
}

/**
 * @brief This function set kme ppi hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmePPIHNum(UINT32 u32Hnum)
{
	return;
	// reg_kme_ppi_hnum
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_ppi_hnum),u32Hnum);
}

/**
 * @brief This function set kme vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeVflipEnable(BOOL bEnable)
{
	return;
	//reg_kme_vflip_enable
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kme_system_vflip_enable),(UINT32)bEnable);	
}

/**
 * @brief This function set kme logo vflip enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmeLogoVflipEnable(BOOL bEnable)
{
	return;
	//reg_km_logo_vflip_en
	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_vflip_en),(UINT32)bEnable);
}

/**
 * @brief This function set kme 00 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address0),u32Address);	
}

/**
 * @brief This function set kme 00 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address1),u32Address);	
}

/**
 * @brief This function set kme 00 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress2(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address2
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address2),u32Address);	
}

/**
 * @brief This function set kme 00 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress3(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address3
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address3),u32Address);	
}

/**
 * @brief This function set kme 00 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress4(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address4
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address4),u32Address);	
}

/**
 * @brief This function set kme 00 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00StartAddress5(UINT32 u32Address)
{
	return;
	//reg_kme_00_start_address5
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_start_address5),u32Address);	
}

/**
 * @brief This function set kme 04 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme04StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_04_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_04_start_address0),u32Address);	
}

/**
 * @brief This function set kme 04 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme04StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_04_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_04_start_address1),u32Address);	
}

/**
 * @brief This function set kme 05 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme05StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_05_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_05_start_address0),u32Address);	
}

/**
 * @brief This function set kme 05 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme05StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_05_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_05_start_address1),u32Address);	
}

/**
 * @brief This function set kme 08 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_08_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_08_start_address0),u32Address);	
}

/**
 * @brief This function set kme 08 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_08_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_08_start_address1),u32Address);	
}

/**
 * @brief This function set kme 10 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_10_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_10_start_address0),u32Address);	
}

/**
 * @brief This function set kme 10 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_10_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_10_start_address1),u32Address);	
}

/**
 * @brief This function set kme 12 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_12_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_start_address0),u32Address);	
}

/**
 * @brief This function set kme 12 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_12_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_start_address1),u32Address);	
}

/**
 * @brief This function set kme 14 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14StartAddress0(UINT32 u32Address)
{
	return;
	//reg_kme_14_start_address0
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_14_start_address0),u32Address);	
}

/**
 * @brief This function set kme 14 start address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14StartAddress1(UINT32 u32Address)
{
	return;
	//reg_kme_14_start_address1
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_14_start_address1),u32Address);	
}

/**
 * @brief This function set kmv 01 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01StartAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_start_address0),u32Address);	
}

/**
 * @brief This function set kmv 02 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02StartAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_start_address0),u32Address);	
}

/**
 * @brief This function set kmv 04 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_start_address0),u32Address);	
}

/**
 * @brief This function set kmv 04 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_start_address1),u32Address);	
}

/**
 * @brief This function set kmv 04 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04StartAddress2(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_mv04_start_address2),u32Address);	
}

/**
 * @brief This function set kmv 05 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05StartAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_start_address0),u32Address);	
}

/**
 * @brief This function set kmv 05 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05StartAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_start_address1),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address0),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address1),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress2(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address2),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress3(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address3),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress4(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address4),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress5(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address5),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress6(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address6),u32Address);	
}

/**
 * @brief This function set kmv 12 start address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12StartAddress7(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_start_address7),u32Address);	
}

/**
 * @brief This function set kmv 01 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01EndAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_end_address0),u32Address);	
}

/**
 * @brief This function set kmv 02 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02EndAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_end_address0),u32Address);	
}

/**
 * @brief This function set kmv 04 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_end_address0),u32Address);	
}

/**
 * @brief This function set kmv 04 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_end_address1),u32Address);	
}

/**
 * @brief This function set kmv 04 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04EndAddress2(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_mv04_end_address2),u32Address);	
}

/**
 * @brief This function set kmv 05 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05EndAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_end_address0),u32Address);	
}

/**
 * @brief This function set kmv 05 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05EndAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_end_address1),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 0
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress0(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address0),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 1
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress1(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address1),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 2
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress2(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address2),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 3
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress3(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address3),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 4
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress4(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address4),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 5
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress5(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address5),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 6
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress6(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address6),u32Address);	
}

/**
 * @brief This function set kmv 12 end address 7
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12EndAddress7(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_end_address7),u32Address);	
}

/**
 * @brief This function set kmv 01 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01LineOffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_line_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 01 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv01LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 02 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02LineOffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_line_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 02 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv02LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 04 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04LineOffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_line_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 04 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv04LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 05 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05LineOffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_line_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 05 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv05LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 12 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12LineOffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_line_offset_addr),u32Address);	
}

/**
 * @brief This function set kmv 12 LR offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKmv12LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kme 01 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv01WriteEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 02 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv02WriteEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 04 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv04WriteEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 05 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv05WriteEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 12 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv12WriteEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_write_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 03 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv03ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv03_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 06 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv06ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv06_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 07 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv07ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv07_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 08 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv08ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv08_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 09 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv09ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv09_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 10 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv10ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv10_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kme 11 write enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmv11ReadEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv11_read_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmv 01 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv01Hnum(UINT32 u32Hnum)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_hnum),u32Hnum);
}

/**
 * @brief This function set kmv 02 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv02Hnum(UINT32 u32Hnum)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_hnum),u32Hnum);
}

/**
 * @brief This function set kmv 04 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv04Hnum(UINT32 u32Hnum)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_hnum),u32Hnum);
}

/**
 * @brief This function set kmv 05 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv05Hnum(UINT32 u32Hnum)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_hnum),u32Hnum);
}

/**
 * @brief This function set kmv 12 hnum
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID HAL_DM_SetKmv12Hnum(UINT32 u32Hnum)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_hnum),u32Hnum);
}

/**
 * @brief This function set kmv 01 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv01Active(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_hactive),u32Hactive);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv01_vactive),u32Vactive);
}

/**
 * @brief This function set kmv 02 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv02Active(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_hactive),u32Hactive);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv02_vactive),u32Vactive);
}

/**
 * @brief This function set kmv 04 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv04Active(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_hactive),u32Hactive);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv04_vactive),u32Vactive);
}

/**
 * @brief This function set kmv 05 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv05Active(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_hactive),u32Hactive);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv05_vactive),u32Vactive);
}

/**
 * @brief This function set kmv 12 Active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_DM_SetKmv12Active(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_hactive),u32Hactive);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv12_vactive),u32Vactive);
}

/**
 * @brief This function set kmv input 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmvInput3DEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv_input_3d_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmv output 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_DM_SetKmvOutput3DEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv_output_3d_enable),(UINT32)bEnable);
}

/**
 * @brief This function set kmv me1 output 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmvME1Output3DMode(UINT32 u32Mode)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv03_output_3d_mode),u32Mode);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv06_output_3d_mode),u32Mode);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv07_output_3d_mode),u32Mode);
}

/**
 * @brief This function set kmv me2 output 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_DM_SetKmvME2Output3DMode(UINT32 u32Mode)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv08_output_3d_mode),u32Mode);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv09_output_3d_mode),u32Mode);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv10_output_3d_mode),u32Mode);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP2__reg_mv11_output_3d_mode),u32Mode);
}

/**
 * @brief This function set kme 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00LROffsetAddress(UINT32 u32Address)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_lr_offset_addr),u32Address);	
}

/**
 * @brief This function set kme 00 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme00LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kme_00_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP0__reg_kme_00_line_offset_addr),u32Address);
}

/**
 * @brief This function set kme 08 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme08LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kme_08_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_08_line_offset_addr),u32Address);
}

/**
 * @brief This function set kme 10 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme10LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kme_10_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_10_line_offset_addr),u32Address);
}

/**
 * @brief This function set kme 12 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme12LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kme_12_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_12_line_offset_addr),u32Address);
}

/**
 * @brief This function set kme 14 line offset address
 * @param [in] UINT32 u32Address
 * @retval VOID
*/
VOID HAL_DM_SetKme14LineOffsetAddress(UINT32 u32Address)
{
	return;
	//reg_kme_14_line_offset_addr
	WriteRegister(KIWI_REG(FRC_TOP__KME_DM_TOP1__reg_kme_14_line_offset_addr),u32Address);
}

