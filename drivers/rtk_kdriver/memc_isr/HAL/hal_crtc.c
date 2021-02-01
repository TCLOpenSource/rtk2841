/**
 * @file hal_crtc.c
 * @brief This file is for crtc register setting
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
 * @brief This function set frc timing
 * @param [in] TIMING_PARA_ST stFRCTiming
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCTiming(TIMING_PARA_ST stFRCTiming)
{
	return;
	//reg_crtc1_frc_hact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_hact),stFRCTiming.u32HActive/4);
	//reg_crtc1_frc_vact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_vact),stFRCTiming.u32VActive);
	//reg_crtc1_frc_hs_bporch[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_hs_bporch),stFRCTiming.u32HSBPorch/4);
	//reg_crtc1_frc_vs_bporch[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_vs_bporch),stFRCTiming.u32VSBPorch);
}

/**
 * @brief This function set osd timing
 * @param [in] u32Hact
 * @param [in] u32Vact
 * @retval VOID
*/
VOID HAL_CRTC_SetOSDTiming(UINT32 u32Hact, UINT32 u32Vact)
{
	return;
	//reg_crtc1_osd_hact
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_osd_hact), u32Hact);
	//reg_crtc1_osd_vact
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_osd_vact), u32Vact);
}

/**
 * @brief This function set panel timing
 * @param [in] TIMING_PARA_ST stFRCTiming
 * @retval VOID
*/
VOID HAL_CRTC_SetPanelTiming(PANEL_PARAMETERS_ST stPanelTiming)
{
	return;
	//reg_crtc1_out_htotal[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_htotal),stPanelTiming.u32Htotal/4);
	//reg_crtc1_out_vtotal[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_vtotal),stPanelTiming.u32Vtotal);
	//reg_crtc1_out_hact[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_hact),stPanelTiming.u32Hactive/4);
	//reg_crtc1_out_vact[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_vact),stPanelTiming.u32Vactive);
	//reg_crtc1_out_hs_width[6:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_hs_width),stPanelTiming.u32HSWidth/4);
	//reg_crtc1_out_vs_width[6:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_vs_width),stPanelTiming.u32VSWidth);
	//reg_crtc1_out_hs_bporch[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_hs_bporch),stPanelTiming.u32HSBPorch/4);
	//reg_crtc1_out_vs_bporch[11:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_vs_bporch),stPanelTiming.u32VSBPorch);
	//reg_crtc1_vspll_max_v_total
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_vspll_max_v_total),stPanelTiming.u32VtotalMax);
	//reg_crtc1_vspll_min_v_total
	//WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_vspll_min_v_total),stPanelTiming.u32VtotalMin);
}

/**
 * @brief This function get ME orig vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32ME_Orig_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMEOrigVtrigDelay(VOID)
{
	return;
	UINT32 u32ME_Orig_Vtrig_dly = 0;
	ReadRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me2_org_vtrig_dly),&u32ME_Orig_Vtrig_dly);
	return u32ME_Orig_Vtrig_dly;
}

/**
 * @brief This function set ME orig vtrig delay
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID HAL_CRTC_SetMEOrigVtrigDelay(UINT32 u32Val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me2_org_vtrig_dly),u32Val);
}

/**
 * @brief This function get ME vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32ME_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMEVtrigDelay(VOID)
{
	return;
	UINT32 u32ME_Vtrig_dly = 0;
	ReadRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me2_vtrig_dly),&u32ME_Vtrig_dly);
	return u32ME_Vtrig_dly;
}

/**
 * @brief This function get MC vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32MC_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMCVtrigDelay(VOID)
{
	return;
	UINT32 u32MC_Vtrig_dly = 0;
	ReadRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_mc_vtrig_dly),&u32MC_Vtrig_dly);
	return u32MC_Vtrig_dly;
}

/**
 * @brief This function set frc vtrig delay
 * @param [in] UINT32 u32FRC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCVtrigDelay(UINT32 u32FRC_Vtrig_dly)
{
	return;
	//reg_crtc1_frc_vtrig_dly[9:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_vtrig_dly),u32FRC_Vtrig_dly);
}

/**
 * @brief This function set frc vtrig delay
 * @param [in] UINT32 u32FRC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetLbmeVtrigDelay(UINT32 u32Lbme_Vtrig_dly)
{
	return;
	//reg_crtc1_lbme_vtrig_dly[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbme1_vtrig_dly),u32Lbme_Vtrig_dly);
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbme2_vtrig_dly),u32Lbme_Vtrig_dly);
}

/**
 * @brief This function set dehalo vtrig delay
 * @param [in] UINT32 u32DEHALO_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloVtrigDelay(UINT32 u32DEHALO_Vtrig_dly)
{
	return;
	//reg_crtc1_dehalo_vtrig_dly[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_dehalo_vtrig_dly),u32DEHALO_Vtrig_dly);
}

/**
 * @brief This function set dec vtrig delay
 * @param [in] UINT32 u32DEC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetDecVtrigDelay(UINT32 u32DEC_Vtrig_dly)
{
	return;
	//reg_crtc1_dec_vtrig_dly[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_dec_vtrig_dly),u32DEC_Vtrig_dly);
}

/**
 * @brief This function set mc vtrig delay
 * @param [in] UINT32 u32MC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetMCVtrigDelay(UINT32 u32MC_Vtrig_dly)
{
	return;
	//reg_crtc1_mc_vtrig_dly[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_mc_vtrig_dly),u32MC_Vtrig_dly);
}

/**
 * @brief This function set lbmc vtrig delay
 * @param [in] UINT32 u32Lbmc_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetLbmcVtrigDelay(UINT32 u32Lbmc_Vtrig_dly)
{
	return;
	//reg_crtc1_lbmc_vtrig_dly[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_vtrig_dly),u32Lbmc_Vtrig_dly);
}

/**
 * @brief This function set frc pre de l num
 * @param [in] UINT32 u32Frc_Prede_LNum
 * @retval VOID
*/
VOID HAL_CRTC_SetFrcPredeLNum(UINT32 u32Frc_Prede_LNum)
{
	return;
	//crtc1_frc_prede_lnum
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_prede_lnum),u32Frc_Prede_LNum);
}

/**
 * @brief This function set me vactive
 * @param [in] UINT32 u32ME_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetMEVactive(UINT32 u32ME_Vactive)
{
	return;
	//reg_crtc1_me_vact[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me1_vact),u32ME_Vactive);
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me2_vact),u32ME_Vactive);
}

/**
 * @brief This function set dehalo vactive
 * @param [in] UINT32 u32Dehalo_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloVactive(UINT32 u32Dehalo_Vactive)
{
	return;
	//reg_crtc1_dehalo_vact[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_dehalo_vact),u32Dehalo_Vactive);
}

/**
 * @brief This function set mc vactive
 * @param [in] UINT32 u32MC_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetMCVactive(UINT32 u32MC_Vactive)
{
	return;
	//reg_crtc1_mc_vact[12:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_mc_vact),u32MC_Vactive);
}

/**
 * @brief This function set me1 row type
 * @param [in] UINT32 u32ME_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetME1RowType(UINT32 u32ME_Row_Type)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me1_row_type),u32ME_Row_Type);
}

/**
 * @brief This function set me2 row type
 * @param [in] UINT32 u32ME_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetME2RowType(UINT32 u32ME_Row_Type)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_me2_row_type),u32ME_Row_Type);
}

/**
 * @brief This function set dehalo row type
 * @param [in] UINT32 u32Dehalo_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloRowType(UINT32 u32Dehalo_Row_Type)
{
	return;
	//reg_crtc1_dehalo_row_type[1:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_dehalo_row_type),u32Dehalo_Row_Type);
}

/**
 * @brief This function set mc row type
 * @param [in] UINT32 u32MC_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetMCRowType(UINT32 u32MC_Row_Type)
{
	return;
	//reg_crtc1_mc_row_type[1:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_mc_row_type),u32MC_Row_Type);
}

/**
 * @brief This function set plogo row type
 * @param [in] UINT32 u32Plogo_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetPlogoRowType(UINT32 u32Plogo_Row_Type)
{
	return;
	//reg_crtc1_plogo_row_type
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_plogo_row_type),u32Plogo_Row_Type);
}

/**
 * @brief This function set plogo fetch row type
 * @param [in] UINT32 u32Plogo_fetch_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetPlogoFetchRowType(UINT32 u32Plogo_fetch_Row_Type)
{
	return;
	//reg_crtc1_plogo_fetch_fetch_row_type
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_plogo_fetch_row_type),u32Plogo_fetch_Row_Type);
}

/**
 * @brief This function set frc prede pnum
 * @param [in] UINT32 u32FRC_prede_pnum
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCPreDEPNum(UINT32 u32FRC_prede_pnum)
{
	return;
	//reg_crtc1_frc_prede_pnum[4:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_frc_prede_pnum),u32FRC_prede_pnum);
}

/**
 * @brief This function set panel vtrig delay
 * @param [in] UINT32 u32Panel_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetOutVtrigDelay(UINT32 u32Panel_Vtrig_dly)
{
	return;
	//reg_crtc1_out_vtrig_dly[9:0]
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_out_vtrig_dly),u32Panel_Vtrig_dly);
}

/**
 * @brief This function set n to m
 * @param [in] UINT32 u32N
 * @param [in] UINT32 u32M
 * @retval VOID
*/
VOID HAL_CRTC_SetN2M(UINT32 u32N, UINT32 u32M)
{
	return;
	UINT32 u32Val = 0;
	ReadRegister(FRC_TOP__CRTC1__reg_crtc1_n_ADDR, 0, 31, &u32Val);
	u32Val = (u32Val & 0xFF0000FF) | (u32N << 8) | (u32M << 16);
	WriteRegister(FRC_TOP__CRTC1__reg_crtc1_n_ADDR, 0, 31, u32Val);
}

/**
 * @brief This function set CRTC slave mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CRTC_SetSlaveModeEnable(BOOL bEnable)
{
	return;
	//reg_crtc1_slave_mode_on
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_slave_mode_on),(UINT32)bEnable);
}

/**
 * @brief This function set lbmc normal lf delay
 * @param [in] UBYTE ubyIdx (0~8)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCNormalLFDly(UBYTE ubyIdx, UBYTE ubyDly)
{
	return;
	switch(ubyIdx)
	{
		case 0:
			//reg_crtc1_lbmc_lfidx0_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx0_dly),ubyDly);
			break;
		case 1:
			//reg_crtc1_lbmc_lfidx1_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx1_dly),ubyDly);
			break;
		case 2:
			//reg_crtc1_lbmc_lfidx2_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx2_dly),ubyDly);
			break;
		case 3:
			//reg_crtc1_lbmc_lfidx3_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx3_dly),ubyDly);
			break;
		case 4:
			//reg_crtc1_lbmc_lfidx4_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx4_dly),ubyDly);
			break;
		case 5:
			//reg_crtc1_lbmc_lfidx5_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx5_dly),ubyDly);
			break;
		case 6:
			//reg_crtc1_lbmc_lfidx6_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx6_dly),ubyDly);
			break;
		case 7:
			//reg_crtc1_lbmc_lfidx7_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx7_dly),ubyDly);
			break;
		case 8:
			//reg_crtc1_lbmc_lfidx8_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_lfidx8_dly),ubyDly);
			break;
		default:
			break;
	}
}

/**
 * @brief This function set lbmc normal hf delay
 * @param [in] UBYTE ubyIdx (0~3)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCNormalHFDly(UBYTE ubyIdx, UBYTE ubyDly)
{
	return;
	switch(ubyIdx)
	{
		case 0:
			//reg_crtc1_lbmc_hfyidx0_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_hfyidx0_dly),ubyDly);
			break;
		case 1:
			//reg_crtc1_lbmc_hfyidx1_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_hfyidx1_dly),ubyDly);
			break;
		case 2:
			//reg_crtc1_lbmc_hfyidx2_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_hfyidx2_dly),ubyDly);
			break;
		case 3:
			//reg_crtc1_lbmc_hfcidx0_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_hfcidx0_dly),ubyDly);
			break;
		default:
			break;
	}
}

/**
 * @brief This function set lbmc signle lf delay
 * @param [in] UBYTE ubyIdx (0~8)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCSingleLFDly(UBYTE ubyIdx, UBYTE ubyDly)
{
	return;
	switch(ubyIdx)
	{
		case 0:
			//reg_crtc1_lbmc_s_lfidx0_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx0_dly),ubyDly);
			break;
		case 1:
			//reg_crtc1_lbmc_s_lfidx1_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx1_dly),ubyDly);
			break;
		case 2:
			//reg_crtc1_lbmc_s_lfidx2_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx2_dly),ubyDly);
			break;
		case 3:
			//reg_crtc1_lbmc_s_lfidx3_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx3_dly),ubyDly);
			break;
		case 4:
			//reg_crtc1_lbmc_s_lfidx4_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx4_dly),ubyDly);
			break;
		case 5:
			//reg_crtc1_lbmc_s_lfidx5_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx5_dly),ubyDly);
			break;
		case 6:
			//reg_crtc1_lbmc_s_lfidx6_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx6_dly),ubyDly);
			break;
		case 7:
			//reg_crtc1_lbmc_s_lfidx7_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx7_dly),ubyDly);
			break;
		case 8:
			//reg_crtc1_lbmc_s_lfidx8_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_lfidx8_dly),ubyDly);
			break;
		default:
			break;
	}
}

/**
 * @brief This function set lbmc single hf delay
 * @param [in] UBYTE ubyIdx (0~3)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCSingleHFDly(UBYTE ubyIdx, UBYTE ubyDly)
{
	return;
	switch(ubyIdx)
	{
		case 0:
			//reg_crtc1_lbmc_s_hfyidx0_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_hfyidx0_dly),ubyDly);
			break;
		case 1:
			//reg_crtc1_lbmc_s_hfyidx1_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_hfyidx1_dly),ubyDly);
			break;
		case 2:
			//reg_crtc1_lbmc_s_hfyidx2_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_hfyidx2_dly),ubyDly);
			break;
		case 3:
			//reg_crtc1_lbmc_s_hfyidx3_dly
			WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lbmc_s_hfyidx3_dly),ubyDly);
			break;
		default:
			break;
	}
}

/**
 * @brief This function get vspll lock status
 * @retval True for lock
 * @retval False for unlock
*/
BOOL HAL_CRTC_GetVSPLLStatus(VOID)
{
	return;
	UINT32 bPeriod_lock = FALSE;
	UINT32 bPhase_lock = FALSE;
	ReadRegister(KIWI_REG(FRC_TOP__CRTC1__regr_crtc1_vspll_period_lock),&bPeriod_lock);
	ReadRegister(KIWI_REG(FRC_TOP__CRTC1__regr_crtc1_vspll_phase_lock),&bPhase_lock);
	if(bPeriod_lock && bPhase_lock)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 * @brief This function set crtc lr enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CRTC_SetLREnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_3d_lr_enable),(UINT32)bEnable);
}

/**
 * @brief This function set crtc lr cycle
 * @param [in] UINT32 u32Cycle
 * @retval VOID
*/
VOID HAL_CRTC_SetLRCycle(UINT32 u32Cycle)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lr_p_cycle),u32Cycle);
}

/**
 * @brief This function set crtc lr pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID HAL_CRTC_SetLRPattern(UINT32 u32Pattern)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_lr_p_patt),u32Pattern);
}

