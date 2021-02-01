/**
 * @file hal_ip.c
 * @brief This file is for ip register setting
 * @date Nov.14.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Driver/regio.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set ippre csc enable
 * @param [in] BOOL bEnable true for enable, false for diable
 * @retval VOID
*/
VOID HAL_IP_SetIPPRECSCEnable(BOOL bEnable)
{
	return;
	if(bEnable)
	{
		//reg_convert_on_h
		WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_on_h),1);
		//reg_convert_on_l
		WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_on_l),1);
	}
	else
	{
		//reg_convert_on_h
		WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_on_h),0);	
		//reg_convert_on_l
		WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_on_l),0);
	}
}

/**
 * @brief This function set ippre csc mode
 * @param [in] CSC_MODE enCSC_Mode
 * @retval VOID
*/
VOID HAL_IP_SetIPPRECSCMode(CSC_MODE enCSC_Mode)
{
	return;
	//reg_convert_mode_h
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_mode_h),(UINT32)enCSC_Mode);
	//reg_convert_mode_l
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_mode_l),(UINT32)enCSC_Mode);
}

/**
 * @brief This function set ippre 444to422 Enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPRE444to422Enable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_444to422_en), (UINT32)bEnable);
}

/**
 * @brief This function set ippre retiming
 * @param [in] UINT32 u32Hact
 * @param [in] UINT32 u32Vact 
 * @retval VOID
*/
VOID HAL_IP_SetIPPRERetiming(UINT32 u32Hact, UINT32 u32Vact)
{
	return;
	//reg_ippre_retiming_hact
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_retiming_hact),u32Hact/2);
	//reg_ippre_retiming_vact
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_retiming_vact),u32Vact);
}

/**
 * @brief This function get ippre retiming dummy de
 * @param [in] VOID
 * @param [in] UINT32 u32Vact 
 * @retval retiming dummy de
*/
UINT32 HAL_IP_GetIPPRERetimingDummyDE(VOID)
{
	return;
	UINT32 uiVal = 0;
	ReadRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_retiming_dummy_num), &uiVal);
	return uiVal;
}

/**
 * @brief This function set ippre pattern size
 * @param [in] TIMING_PARA_ST stInputTiming 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREPatternSize(TIMING_PARA_ST stInputTiming)
{
	return;
	//reg_hact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_patt_hact),stInputTiming.u32HActive/2);
	//reg_vact[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_patt_vact),stInputTiming.u32VActive);
	//reg_htotal[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_patt_htotal),stInputTiming.u32HTotal/2);
	//reg_vtotal[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_patt_vtotal),stInputTiming.u32VTotal);	
}

/**
 * @brief This function set ippre use mute sync enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteUseMuteSyncEnable(BOOL bEnable)
{
	return;
	//reg_ippre_use_mute_vs
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_use_mute_vs), (UINT32)bEnable);
	//reg_ippre_use_mute_hs
	//WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_use_mute_hs), (UINT32)bEnable);
}

/**
 * @brief This function set ippre mute set mute detect enable
 * @param [in]  bool bEnable
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteSetMuteDetectEnable(BOOL bEnable)
{
	return;
	//reg_ippre_mute_det_function_en
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_det_function_en), (UINT32)bEnable);
}

/**
 * @brief This function set ippre mute h active
 * @param [in] UINT32 u32Hact 
 * @param [in] UINT32 u32Hact_Min 
 * @param [in] UINT32 u32Hact_Max 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteHactive(UINT32 u32Hact, UINT32 u32Hact_Min, UINT32 u32Hact_Max)
{
	return;
	//reg_ippre_mute_hact
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_hact), u32Hact);
	//reg_ippre_mute_hact_min
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_hact_min), u32Hact_Min);
	//reg_ippre_mute_hact_max
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_hact_max), u32Hact_Max);
}

/**
 * @brief This function set ippre v active
 * @param [in] UINT32 u32Vact 
 * @param [in] UINT32 u32Vact_Min 
 * @param [in] UINT32 u32Vact_Max 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteVactive(UINT32 u32Vact, UINT32 u32Vact_Min, UINT32 u32Vact_Max)
{
	return;
	//reg_ippre_mute_vact
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_vact), u32Vact);
	//reg_ippre_mute_vact_min
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_vact_min), u32Vact_Min);
	//reg_ippre_mute_vact_max
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_vact_max), u32Vact_Max);
}

/**
 * @brief This function set ippre mute clock threshold
 * @param [in] UINT32 u32Clk_low_th 
 * @param [in] UINT32 u32Clk_high_th 
 * @retval VOID
*/
VOID HAL_IP_SetIPPREMuteClockThreshold(UINT32 u32Clk_low_th, UINT32 u32Clk_high_th)
{
	return;
	//reg_ippre_mute_freq_low_th
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_freq_low_th), u32Clk_low_th);
	//reg_ippre_mute_freq_high_th
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_ippre_mute_freq_high_th), u32Clk_high_th);
}

/**
 * @brief This function set 3d fs lr inverse
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID HAL_IP_Set3DFSLRInverse(BOOL bEnable)
{
	return;
	//reg_patt_3d_fs_lr_inv
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_patt_3d_fs_lr_inv),(UINT32)bEnable);	
}

#ifndef REAL_CHIP	// FPGA
/**
 * @brief This function set topA ipme retiming
 * @param [in] TIMING_PARA_ST stInputTiming
 * @retval VOID
*/
VOID HAL_IP_SetTOPA_IPMERetiming(TIMING_PARA_ST stInputTiming)
{
	return;
	//reg_sh7_ipme_hact
	WriteRegister(KIWI_REG(FRC_TOP__TOP_A__reg_sh7_ipme_hact),stInputTiming.u32HActive/2);	
	//reg_sh7_ipme_vact
	WriteRegister(KIWI_REG(FRC_TOP__TOP_A__reg_sh7_ipme_vact),stInputTiming.u32VActive);
}

/**
 * @brief This function set 2 port enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_IP_SetTOPA2PortEnable(BOOL bEnable)
{	
	return;
	WriteRegister(KIWI_REG(FRC_TOP__TOP_A__reg_sh13_2port_enable), (UINT32)bEnable);	
}

/**
 * @brief This function set topB mute timing
 * @param [in] TIMING_PARA_ST gstInputTiming
 * @param [in] TIMING_PARA_ST gstOutputTiming 
 * @retval VOID
*/
VOID HAL_IP_SetTOPBMuteTiming(TIMING_PARA_ST stInputTiming, TIMING_PARA_ST stOutputTiming)
{
	return;
	//reg_mute_htotal[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_htotal),stInputTiming.u32HTotal/2);	
	//reg_mute_vtotal[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vtotal),stInputTiming.u32VTotal);	
	//reg_mute_hs_bporch[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_hs_bporch),stInputTiming.u32HSBPorch/2);	
	//reg_mute_hact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_hact),stInputTiming.u32HActive/2);	
	//reg_mute_vact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vact),stInputTiming.u32VActive);	
	//reg_mute_vs_bporch[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vs_bporch),stInputTiming.u32VSBPorch);	
	//reg_mute_hs_width[3:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_hs_width),stInputTiming.u32HSWidth/2);	
	//reg_mute_hs_width[3:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vs_width),stInputTiming.u32VSWidth);		
	//reg_mute_hact_min[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_hact_min),stInputTiming.u32HActive/2 - 192);
	//reg_mute_hact_max[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_hact_max),stInputTiming.u32HActive/2);	
	//reg_mute_vact_min[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vact_min),stInputTiming.u32VActive - 50);
	//reg_mute_vact_max[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_vact_max),stInputTiming.u32VActive + 50);	
	//reg_inproc_mc_de_hact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_inproc_mc_de_hact),stOutputTiming.u32HActive/2);	
	//reg_sh19_nr_hact
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_sh19_nr_hact),stInputTiming.u32HActive/2);	
}

/**
 * @brief This function set mute lr self gen
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_IP_SetTOPBMuteLRSelfGen(BOOL bEnable)
{	
	return;
	WriteRegister(KIWI_REG(FRC_TOP__TOP_B__reg_mute_lr_slf_gen), (UINT32)bEnable);	
}
#endif

/**
 * @brief This function set ip data mapping
 * @param [in] UINT32 u32Data_Mapping 
 * @retval VOID
*/
VOID HAL_IP_SetDataMapping(UINT32 u32Data_Mapping)
{
	return;
	//reg_convert_map_h
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_map_h),(UINT32)u32Data_Mapping);	
	//reg_convert_map_l
	WriteRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_map_l),(UINT32)u32Data_Mapping);		
}

/**
 * @brief This function get ip data mapping
 * @param [in] VOID
 * @retval data mapping
*/
UINT32 HAL_IP_GetDataMapping(VOID)
{
	return;
	UINT32 u32Data_Mapping = 0;
	//reg_convert_map_h
	ReadRegister(KIWI_REG(FRC_TOP__IPPRE__reg_convert_map_h),&u32Data_Mapping);
	return u32Data_Mapping;
}

