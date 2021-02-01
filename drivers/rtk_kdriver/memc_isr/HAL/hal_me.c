/**
 * @file hal_me.c
 * @brief This file is for kme me register setting
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

/**
 * @brief This function set KME ipme in mode
 * @param [in] UINT32 u32In_mode
 * @retval VOID
*/
VOID HAL_KME_IPME_SetInMode(UINT32 u32In_mode)
{
	return;
	//reg_ipme_in_mode
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_in_mode),u32In_mode);
}

/**
 * @brief This function set KME ipme h fetch mode
 * @param [in] UINT32 u32HFetch_Mode
 * @retval VOID
*/
VOID HAL_KME_IPME_SetHFetchMode(UINT32 u32HFetch_Mode)
{
	return;
	//reg_ipme_h_fetch_mode
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_h_fetch_mode),u32HFetch_Mode);	
}

/**
 * @brief This function set KME ipme v fetch mode
 * @param [in] UINT32 u32VFetch_Mode
 * @retval VOID
*/
VOID HAL_KME_IPME_SetVFetchMode(UINT32 u32VFetch_Mode)
{
	return;
	//reg_ipme_v_fetch_mode
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_v_fetch_mode),u32VFetch_Mode);	
}

/**
 * @brief This function set KME ipme2 v fetch mode
 * @param [in] UINT32 u32VFetch_Mode
 * @retval VOID
*/
VOID HAL_KME_IPME2_SetVFetchMode(UINT32 u32VFetch_Mode)
{
	return;
	//reg_ipme_v_fetch_mode
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME1__reg_ipme_v_480x270_mode),u32VFetch_Mode);	
}

/**
 * @brief This function set KME ipme h center value
 * @param [in] UINT32 u32H_Center_Value
 * @retval VOID
*/
VOID HAL_KME_IPME_SetHCenterValue(UINT32 u32H_Center_Value)
{
	return;
	//reg_ipme_h_center_value
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_h_center_value),u32H_Center_Value);
}

/**
 * @brief This function set KME ipme v center value
 * @param [in] UINT32 u32V_Center_Value
 * @retval VOID
*/
VOID HAL_KME_IPME_SetVCenterValue(UINT32 u32V_Center_Value)
{
	return;
	//reg_ipme_v_center_value
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_v_center_value),u32V_Center_Value);
}

/**
 * @brief This function set KME ipme2 v center value
 * @param [in] UINT32 u32V_Center_Value
 * @retval VOID
*/
VOID HAL_KME_IPME2_SetVCenterValue(UINT32 u32V_Center_Value)
{
	return;
	//reg_ipme_v_480x270_i_v_center
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME1__reg_ipme_v_480x270_i_v_center),u32V_Center_Value);
}

/**
 * @brief This function set KME ipme h scaler active
 * @param [in] UINT32 u32Scaler_Hactive
 * @retval VOID
*/
VOID HAL_KME_IPME_SetScalerHactive(UINT32 u32Scaler_Hactive)
{
	return;
	//reg_ipme_scaler_h_active
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_scaler_h_active),u32Scaler_Hactive);
}

/**
 * @brief This function set KME ipme pscaler v active
 * @param [in] UINT32 u32Pscaler_Vactive
 * @retval VOID
*/
VOID HAL_KME_IPME_SetPscalerVactive(UINT32 u32Pscaler_Vactive)
{
	return;
	//reg_ipme_pscaler_v_active
	WriteRegister(KIWI_REG(FRC_TOP__KME_IPME__reg_ipme_pscaler_v_active),u32Pscaler_Vactive);
}

/**
 * @brief This function set KME LBME total line number
 * @param [in] u32 u32TotalLineNum
 * @retval VOID
*/
VOID HAL_KME_LBME_SetTotalLineNum(UINT32 u32TotalLineNum)
{
	return;
	// reg_lbme_total_line_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_total_line_num),u32TotalLineNum);	
}

/**
 * @brief This function set KME LBME rim
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @retval VOID
*/
VOID HAL_KME_LBME_SetRim(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_y_start),u32Top);
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_y_end),u32Bottom);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_x_start),u32Left);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_rim_x_end),u32Right);
}

/**
 * @brief This function set KME LBME total pixel number
 * @param [in] u32 u32TotalPixelNum
 * @retval VOID
*/
VOID HAL_KME_LBME_SetTotalPixelNum(UINT32 u32TotalPixelNum)
{
	return;
	// reg_lbme_total_pixel_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_total_pixel_num),u32TotalPixelNum);	
}

/**
 * @brief This function set KME LBME block number per line
 * @param [in] u32 u32blk_num_perline
 * @retval VOID
*/
VOID HAL_KME_LBME_SetBlkNumPerLine(UINT32 u32blk_num_perline)
{
	return;
	// reg_lbme_blk_num_perline
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_blk_num_perline),u32blk_num_perline);
}

/**
 * @brief This function set KME LBME debug hactive
 * @param [in] u32 u32debug_hactive
 * @retval VOID
*/
VOID HAL_KME_LBME_SetDebugHactive(UINT32 u32debug_hactive)
{
	return;
	// reg_lbme_debug_hact
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_debug_hact),u32debug_hactive);
}

/**
 * @brief This function set KME LBME total linebuf number
 * @param [in] u32 u32TotalLinebufNum
 * @retval VOID
*/
VOID HAL_KME_LBME_SetTotalLinebufNum(UINT32 u32TotalLinebufNum)
{
	return;
	// reg_lbme_total_linebuf_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_LBME_TOP__reg_lbme_total_linebuf_num),u32TotalLinebufNum);	
}

/**
 * @brief This function set KME LBME2 total line number
 * @param [in] u32 u32TotalLineNum
 * @retval VOID
*/
VOID HAL_KME2_LBME_SetTotalLineNum(UINT32 u32TotalLineNum)
{
	return;
	// reg_me2_lbme_total_line_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_total_line_num),u32TotalLineNum);	
}

/**
 * @brief This function set KME LBME2 total pixel number
 * @param [in] u32 u32TotalPixelNum
 * @retval VOID
*/
VOID HAL_KME2_LBME_SetTotalPixelNum(UINT32 u32TotalPixelNum)
{
	return;
	// reg_me2_lbme_total_pixel_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_total_pixel_num),u32TotalPixelNum);	
}

/**
 * @brief This function set KME2 LBME block number per line
 * @param [in] u32 u32blk_num_perline
 * @retval VOID
*/
VOID HAL_KME2_LBME_SetBlkNumPerLine(UINT32 u32blk_num_perline)
{
	return;
	// reg_me2_lbme_blk_num_perline
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_blk_num_perline),u32blk_num_perline);
}

/**
 * @brief This function set KME2 LBME debug hactive
 * @param [in] u32 u32debug_hactive
 * @retval VOID
*/
VOID HAL_KME2_LBME_SetDebugHactive(UINT32 u32debug_hactive)
{
	return;
	// reg_me2_lbme_debug_hact
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_debug_hact),u32debug_hactive);
}

/**
 * @brief This function set KME2 LBME total linebuf number
 * @param [in] u32 u32TotalLinebufNum
 * @retval VOID
*/
VOID HAL_KME2_LBME_SetTotalLinebufNum(UINT32 u32TotalLinebufNum)
{
	return;
	// reg_me2_lbme_total_linebuf_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_total_linebuf_num),u32TotalLinebufNum);	
}

/**
 * @brief This function set kme vbuf hactive
 * @param [in] UINT32 u32VBuf_Hactive
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_Hactive(UINT32 u32VBuf_Hactive)
{
	return;
	// reg_vbuf_hactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_hactive),u32VBuf_Hactive);
}

/**
 * @brief This function set kme vbuf vactive
 * @param [in] UINT32 u32VBuf_Vactive
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_Vactive(UINT32 u32VBuf_Vactive)
{
	return;
	// reg_vbuf_vactive
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_vactive),u32VBuf_Vactive);
}

/**
 * @brief This function set lbme update num
 * @param [in] UINT32 u32Lbme_Update_Num
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_LBMEUpdateNum(UINT32 u32Lbme_Update_Num)
{
	return;
	// reg_vbuf_lbme_update_num_1row
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_lbme_update_num_1row),u32Lbme_Update_Num);
}

/**
 * @brief This function set lbme trig mid row num
 * @param [in] UINT32 u32Lbme_TrigMidRow_Num
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_LBMETrigMidRowNum(UINT32 u32Lbme_TrigMidRow_Num)
{
	return;
	// reg_vbuf_lbme_trig_mid_row_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_lbme_trig_mid_row_num),u32Lbme_TrigMidRow_Num);
}

/**
 * @brief This function set lbme h shift bit
 * @param [in] UINT32 u32Lbme_HShift
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_LBMEHShift(UINT32 u32Lbme_HShift)
{
	return;
	// reg_vbuf_lbme_h_addr_shift_bit
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_lbme_h_addr_shift_bit),u32Lbme_HShift);
}

/**
 * @brief This function set lbme v shift bit
 * @param [in] UINT32 u32Lbme_VShift
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_LBMEVShift(UINT32 u32Lbme_VShift)
{
	return;
	// reg_vbuf_lbme_v_addr_shift_bit
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_lbme_v_addr_shift_bit),u32Lbme_VShift);
}

/**
 * @brief This function set kme2 vbuf pfv hactive
 * @param [in] UINT32 u32VBuf_Hactive
 * @retval VOID
*/
VOID HAL_KME2_VBUF_Set_PFVHactive(UINT32 u32VBuf_Hactive)
{
	return;
	// reg_kme_me2_vbuf_pfv_blksize_hact
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blksize_hact),u32VBuf_Hactive);
}

/**
 * @brief This function set kme vbuf pfv vactive
 * @param [in] UINT32 u32VBuf_Vactive
 * @retval VOID
*/
VOID HAL_KME2_VBUF_Set_PFVVactive(UINT32 u32VBuf_Vactive)
{
	return;
	// reg_kme_me2_vbuf_pfv_blksize_vact
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blksize_vact),u32VBuf_Vactive);
}

/**
 * @brief This function set kme2 vbuf 3dpr enable
 * @param [in] UINT32 u32VBuf_Vactive
 * @retval VOID
*/
VOID HAL_KME2_VBUF_Set_3DPREnable(BOOL bEnable)
{
	return;
	// reg_kme_me2_vbuf_3dpr_en
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_3dpr_en),(UINT32)bEnable);
}

/**
 * @brief This function set kme logo0 h fetch mode
 * @param [in] UINT32 u32Logo_Hfetch_mode
 * @retval VOID
*/
VOID HAL_KME_LOGO0_Set_HFetchMode(UINT32 u32Logo_Hfetch_mode)
{
	return;
	// reg_km_logo_h_fetch_mode   
	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_h_fetch_mode),u32Logo_Hfetch_mode);
}

/**
 * @brief This function set kme logo0 v fetch mode
 * @param [in] UINT32 u32Logo_Vfetch_mode
 * @retval VOID
*/
VOID HAL_KME_LOGO0_Set_VFetchMode(UINT32 u32Logo_Vfetch_mode)
{
	return;
	// reg_km_logo_v_fetch_mode   
	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_v_fetch_mode),u32Logo_Vfetch_mode);	
}

/**
 * @brief This function set kme logo0 pscaler v active
 * @param [in] UINT32 u32Logo_Pscaler_Vactive
 * @retval VOID
*/
VOID HAL_KME_LOGO0_Set_PscalerVactive(UINT32 u32Logo_Pscaler_Vactive)
{
	return;
	// reg_km_logo_pscaler_v_active   
	WriteRegister(KIWI_REG(FRC_TOP__KME_LOGO0__reg_km_logo_pscaler_v_active),u32Logo_Pscaler_Vactive);	
}

/**
 * @brief This function set clear MV enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_METOP1_Set_ClearMVEnable(BOOL bEnable)
{
	return;
	// reg_metop_sc_clr_sw_control_en   
	//WriteRegister(KIWI_REG(FRC_TOP__KME_ME_TOP1__reg_metop_sc_clr_sw_control_en), (UINT32)bEnable);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP1__reg_me1_sc_sw_ctrl_en), (UINT32)bEnable);	
}

/**
 * @brief This function set me1 rmv size
 * @param [in] UINT32 u32RMV_Hact
 * @param [in] UINT32 u32RMV_Vact
 * @retval VOID
*/
VOID HAL_KME_ME1_Set_RMVSize(UINT32 u32RMV_Hact, UINT32 u32RMV_Vact)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__reg_me1_rmv_hact), u32RMV_Hact);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP2__reg_me1_rmv_vact), u32RMV_Vact);
}

/**
 * @brief This function set me2 rmv size
 * @param [in] UINT32 u32RMV_Hact
 * @param [in] UINT32 u32RMV_Vact
 * @retval VOID
*/
VOID HAL_KME_ME2_Set_RMVSize(UINT32 u32RMV_Hact, UINT32 u32RMV_Vact)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_TOP_REG__reg_me2_rmv_hact), u32RMV_Hact);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_TOP_REG__reg_me2_rmv_vact), u32RMV_Vact);
}

/**
 * @brief This function set me1 static size
 * @param [in] UINT32 u32Statis_Hact
 * @param [in] UINT32 u32Statis_Vact
 * @retval VOID
*/
VOID HAL_KME_ME1_Set_StatisSize(UINT32 u32Statis_Hact, UINT32 u32Statis_Vact)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__reg_me1_statis_hact), u32Statis_Hact);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME1_TOP6__reg_me1_statis_vact), u32Statis_Vact);
}

/**
 * @brief This function set ph pfv v ratio
 * @param [in] UINT32 u32ph_pfv_v_ratio
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_PHPFVRatio(UINT32 u32ph_pfv_v_ratio)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ph_pfv_v_ratio),u32ph_pfv_v_ratio);
}

/**
 * @brief This function set pfv mv fetch in 1 row
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_PFVMVFetchIn1Row(UINT32 u32val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_mv_fetch_ln_1_row),u32val);
}	

/**
 * @brief This function set ppfv mv fetch in 1 row
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_PPFVMVFetchIn1Row(UINT32 u32val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_ppfv_mv_fetch_ln_1_row),u32val);
}

/**
 * @brief This function set vbuf blk vact
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_BlockVact(UINT32 u32val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kme_vbuf_blk_vact),u32val);
}

/**
 * @brief This function set vbuf row type
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_RowType(UINT32 u32val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kme_vbuf_row_type),u32val);
}

/**
 * @brief This function set vbuf wait cycle
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_VBUF_Set_WaitCycle(UINT32 u32MV_Trig, UINT32 u32ME_Trig)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_wait_cycle_frame2_mv_trig),u32MV_Trig);
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_wait_cycle_frame2_me_trig),u32ME_Trig);
}

/**
 * @brief This function set work mode
 * @param [in] UINT32 u32val
 * @retval VOID
*/
VOID HAL_KME_Set_WorkMode(UINT32 u32val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_me_work_mode),u32val);
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_kme_me_work_mode),u32val);
	WriteRegister(KIWI_REG(FRC_TOP__CRTC1__reg_crtc1_vspll_me_work_mode),u32val);
}

/**
 * @brief This function set meander enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_Set_MeanderEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_frame_meander_enable), (UINT32)bEnable);	
}

/**
 * @brief This function set LBME2 3DPR Enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_Set_LBME23DPREnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_LBME_TOP__reg_me2_lbme_3d_en), (UINT32)bEnable);	
}

/**
 * @brief This function set ME1 vbuf block rim
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @retval VOID
*/
VOID HAL_KME_Set_ME1VbufBlockRIM(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_top), u32Top);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_bot), u32Bottom);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_left), u32Left);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_blk_rim_right), u32Right);	
}

/**
 * @brief This function set ME2 vbuf pfv block rim
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @retval VOID
*/
VOID HAL_KME_Set_ME2VbufPFVBlockRIM(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_top), u32Top);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_bot), u32Bottom);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_left), u32Left);	
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_pfv_blk_rim_right), u32Right);	
}

/**
 * @brief This function set BBD window
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @retval VOID
*/
VOID HAL_KME_Set_BBDWindow(UINT32 u32Top, UINT32 u32Bottom, UINT32 u32Left, UINT32 u32Right)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_y_start), u32Left);	
	WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_y_end), u32Right);	
	WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_x_start), u32Top);	
	WriteRegister(KIWI_REG(FRC_TOP__BBD__reg_BBD_window_x_end), u32Bottom);	
}

/**
 * @brief This function set ME2 LR Dec enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_Set_ME2LRDecEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_me2_lr_dec_en), (UINT32)bEnable);	
}

/**
 * @brief This function set 3d ppfv index
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_Set_3DPPFVIDX(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_3d_ppfv_wr_idx_position), (UINT32)bEnable);	
}

/**
 * @brief This function set crtc lr enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_SetLREnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_3dsg_llrr_en),(UINT32)bEnable);	
}

/**
 * @brief This function set crtc lr cycle
 * @param [in] UINT32 u32Cycle
 * @retval VOID
*/
VOID HAL_KME_SetLRCycle(UINT32 u32Cycle)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_me1_llrr_nums),u32Cycle);	
}

/**
 * @brief This function set crtc lr pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID HAL_KME_SetLRPattern(UINT32 u32Pattern)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_kphase_me1_llrr_patt),u32Pattern);	
}

/**
 * @brief This function set ME1 HV Ratio
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_KME_Set_ME1HVRatio(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_lbme_hv_ratio), (UINT32)bEnable);	
}

/**
 * @brief This function set meander block rim
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @retval VOID
*/
VOID HAL_KME_SetMeanderBLKRIM(UINT32 u32Top, UINT32 u32Bottom)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_blk_rim_top),u32Top);
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_blk_rim_bot),u32Bottom);	
}

/**
 * @brief This function set meander pixel rim
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @retval VOID
*/
VOID HAL_KME_SetMeanderPIXRIM(UINT32 u32Top, UINT32 u32Bottom)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_VBUF_TOP__reg_vbuf_meander_pix_rim_top),u32Top);
	WriteRegister(KIWI_REG(FRC_TOP__KME_TOP__reg_vbuf_meander_pix_rim_bot),u32Bottom);	
}

/**
 * @brief This function set DM PFV PPFV interval
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID HAL_KME_ME2_SetDMPFVPPFVInterval(UINT32 u32Val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_dm_pfv_req_intr_interval),u32Val);
	WriteRegister(KIWI_REG(FRC_TOP__KME_ME2_VBUF_TOP__reg_kme_me2_vbuf_dm_ppfv_req_intr_interval),u32Val);	
}

