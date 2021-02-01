/**
 * @file hal_cpr.c
 * @brief This file is for cpr register setting
 * @date Nov.18.2014
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
 * @brief This function set cpr h/v active
 * @param [in] UINT32 u32Hactive
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_CPR_SetActive(UINT32 u32Hactive, UINT32 u32Vactive)
{
	return;
	//reg_hact
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_hact),u32Hactive);	// 2 port
	//reg_vact
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_vact),u32Vactive);	// hf/lf row count
}

/**
 * @brief This function set encode 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CPR_SetEncode3DEnable(BOOL bEnable)
{
	return;
	//reg_enc_3d_mode
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_enc_3d_mode),(UINT32)bEnable); 
}

/**
 * @brief This function set encode 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_CPR_SetEncode3DMode(UINT32 u32Mode)
{
	return;
	//reg_enc_3d_format
 	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_enc_3d_format),u32Mode);
}

/**
 * @brief This function set decode 3d enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CPR_SetDecode3DEnable(BOOL bEnable)
{
	return;
	//reg_dec_3d_mode
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_dec_3d_mode),(UINT32)bEnable); 
}

/**
 * @brief This function set decode 3d mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_CPR_SetDecode3DMode(UINT32 u32Mode)
{
	return;
	//dec_3d_format
 	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_dec_3d_format),u32Mode);
}

/**
 * @brief This function set 422 enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CPR_Set422Enable(BOOL bEnable)
{
	return;
	//reg_422_mode
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_422_mode),(UINT32)bEnable); 
}

/**
 * @brief This function set budget packet
 * @param [in] UINT32 u32Budget_Packet
 * @retval VOID
*/
VOID HAL_CPR_SetBudgetPacket(UINT32 u32Budget_Packet_Lf, UINT32 u32Budget_Packet_Hf)
{
	return;
	//reg_lf_budget_packet
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_lf_budget_packet),u32Budget_Packet_Lf);	
	//reg_hf_budget_packet
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_hf_budget_packet),u32Budget_Packet_Hf);		
}


/**
 * @brief This function set last line enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CPR_SetLastLineEnable(BOOL bEnable)
{
	return;
	//reg_lastline_en
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_lastline_en),(UINT32)bEnable);	
}

/**
 * @brief This function set LR inverse
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CPR_SetLRInverse(BOOL bEnable)
{
	return;
	//reg_lr_inv
	WriteRegister(KIWI_REG(FRC_TOP__KMC_CPR_TOP0__reg_lr_inv),(UINT32)bEnable);	
}

