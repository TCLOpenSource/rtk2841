/**
 * @file hal_post.c
 * @brief This file is for post register setting
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
 * @brief This function set post pattern size
 * @param [in] TIMING_PARA_ST stOutputTiming
 * @retval VOID
*/
VOID HAL_POST_SetPatternSize(TIMING_PARA_ST stOutputTiming)
{
	return;
	//reg_post_patt_htotal
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_patt_htotal),stOutputTiming.u32HTotal/4);
	//reg_post_patt_vtotal
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_patt_vtotal),stOutputTiming.u32VTotal);
	//reg_post_patt_hact
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_patt_hact),stOutputTiming.u32HActive/4);
	//reg_post_patt_vact
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_patt_vact),stOutputTiming.u32VActive);
}

/**
 * @brief This function set post pr mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetPREnable(BOOL bEnable)
{
	return;
	//reg_pr_mode_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_pr_mode_en),(UINT32)bEnable);
}

/**
 * @brief This function set post hde center value
 * @param [in] UINT32 u32CenterValue
 * @retval VOID
*/
VOID HAL_POST_SetHdeCenterValue(UINT32 u32CenterValue)
{
	return;
	//reg_hde_center_value
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_hde_center_value),u32CenterValue);
}

/**
 * @brief This function set post 4 port hde center value
 * @param [in] UINT32 u32CenterValue
 * @retval VOID
*/
VOID HAL_POST_Set4PortHdeCenterValue(UINT32 u32CenterValue)
{
	return;
	//reg_4port_hde_center_value
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_4port_hde_center_value),u32CenterValue);
}

/**
 * @brief This function set v scaler bypass
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetVscalerBypass(BOOL bEnable)
{
	return;
	//reg_post_vsc_bypass
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_vsc_bypass),(UINT32)bEnable);
}

/**
 * @brief This function set v scaler mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_POST_SetVscalerMode(UINT32 u32Mode)
{
	return;
	//reg_post_vsc_mode
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_vsc_mode),u32Mode);
}

/**
 * @brief This function set v active
 * @param [in] UINT32 u32Vactive
 * @retval VOID
*/
VOID HAL_POST_SetVActive(UINT32 u32Vactive)
{
	return;
	//reg_post_v_act
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_v_act),u32Vactive);
}

/**
 * @brief This function set h scaler bypass
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetHscalerBypass(BOOL bEnable)
{
	return;
	//reg_post_hsc_bypass
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_bypass),(UINT32)bEnable);
}

/**
 * @brief This function set h scaler mode
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_POST_SetHscalerMode(UINT32 u32Mode)
{
	return;
	//reg_post_hsc_mode_y
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_mode_y),u32Mode);
	//reg_post_hsc_mode_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_mode_c),u32Mode);
}

/**
 * @brief This function set h scaler mode of C
 * @param [in] UINT32 u32Mode
 * @retval VOID
*/
VOID HAL_POST_SetHscalerMode_C(UINT32 u32Mode)
{
	return;
	//reg_post_hsc_mode_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_mode_c),u32Mode);
}

/**
 * @brief This function set h scaler offset
 * @param [in] UINT32 u32Offset
 * @retval VOID
*/
VOID HAL_POST_SetHscalerOffset(UINT32 u32Offset)
{
	return;
	//reg_post_hsc_ofst_y
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_ofst_y),u32Offset);
	//reg_post_hsc_ofst_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_ofst_c),u32Offset);
}

/**
 * @brief This function set h scaler offset of C
 * @param [in] UINT32 u32Offset
 * @retval VOID
*/
VOID HAL_POST_SetHscalerOffset_C(UINT32 u32Offset)
{
	return;
	//reg_post_hsc_ofst_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_ofst_c),u32Offset);
}

/**
 * @brief This function set h scaler coef
 * @param [in] UINT32 u32Coef
 * @retval VOID
*/
VOID HAL_POST_SetHscalerCoef(UINT32 u32Coef)
{
	return;
	//reg_post_hsc_coef_y
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_y),u32Coef);
	//reg_post_hsc_coef_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_c),u32Coef);
}

/**
 * @brief This function set h scaler coef of C
 * @param [in] UINT32 u32Coef
 * @retval VOID
*/
VOID HAL_POST_SetHscalerCoef_C(UINT32 u32Coef)
{
	return;
	//reg_post_hsc_coef_c
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_c),u32Coef);
}

/**
 * @brief This function set h scaler coef1
 * @param [in] UINT32 u32Coef
 * @retval VOID
*/
VOID HAL_POST_SetHscalerCoef1(UINT32 u32Coef)
{
	return;
	//reg_post_hsc_coef_y1
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_y1),u32Coef);
	//reg_post_hsc_coef_c1
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_c1),u32Coef);
}

/**
 * @brief This function set h scaler coef1 of C
 * @param [in] UINT32 u32Coef
 * @retval VOID
*/
VOID HAL_POST_SetHscalerCoef1_C(UINT32 u32Coef)
{
	return;
	//reg_post_hsc_coef_c1
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_hsc_coef_c1),u32Coef);
}


/**
 * @brief This function set csc enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetCSCEnable(BOOL bEnable)
{
	return;
	//reg_post_convert_on
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_convert_on),(UINT32)bEnable);
}

/**
 * @brief This function set post csc mode
 * @param [in] CSC_MODE enCSC_Mode
 * @retval VOID
*/
VOID HAL_POST_SetCSCMode(CSC_MODE enCSC_Mode)
{
	return;
	//reg_post_convert_mode
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_convert_mode),(UINT32)enCSC_Mode);
}

/**
 * @brief This function set post mute screen enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetMuteScreenEnable(BOOL bEnable)
{
	return;
	//reg_bluescreen
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_bluescreen),(UINT32)bEnable);
}

/**
 * @brief This function set post mute screen RGB
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetMuteScreenRGBEnable(UINT32 u32RGB)
{
	return;
	//reg_bluescreen_rgb
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_bluescreen_rgb),u32RGB);
}

/**
 * @brief This function set post data mapping
 * @param [in] UINT32 u32Data_Mapping
 * @retval VOID
*/
VOID HAL_POST_SetDataMapping(UINT32 u32Data_Mapping)
{
	return;
	//reg_post_convert_map
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_convert_map),(UINT32)u32Data_Mapping);
}

/**
 * @brief This function get post data mapping
 * @param [in] VOID
 * @retval data mapping
*/
UINT32 HAL_POST_GetDataMapping(VOID)
{
	return;
	UINT32 u32Data_Mapping = 0;
	//reg_post_convert_map
	ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_convert_map),&u32Data_Mapping);
	return u32Data_Mapping;
}

/**
 * @brief This function set black insert line mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetBlackInsertLineModeEnable(BOOL bEnable)
{
	return;
	//reg_blackinsert_line_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_blackinsert_line_en),(UINT32)bEnable);
}

/**
 * @brief This function set black insert line mode pattern number
 * @param [in] UINT32 u32PatternNum
 * @retval VOID
*/
VOID HAL_POST_SetBlackInsertLineModePatternNum(UINT32 u32PatternNum)
{
	return;
	//reg_blackinsert_line_type
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_blackinsert_line_type),u32PatternNum);
}

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID HAL_POST_SetBlackInsertLineModeLPattern(UINT32 u32Pattern)
{
	return;
	//reg_blackinsert_line_patt_l
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_blackinsert_line_patt_l),u32Pattern);
}

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID HAL_POST_SetBlackInsertLineModeRPattern(UINT32 u32Pattern)
{
	return;
	//reg_blackinsert_line_patt_r
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_blackinsert_line_patt_r),u32Pattern);
}

/**
 * @brief This function set black insert frame mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetBlackInsertFrameModeEnable(BOOL bEnable)
{
	return;
	//reg_blackinsert_frame_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_blackinsert_frame_en),(UINT32)bEnable);
}

/**
 * @brief This function set kpost out interrupt select
 * @param [in] 7 for FRC, 6 for OSD, 5 for Out
 * @retval VOID
*/
VOID HAL_POST_SetOutINTSel(UINT32 u32Sel)
{
	return;
	//reg_post_out_int_sel
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_out_int_sel),u32Sel);
}

/**
 * @brief This function set kpost out interrupt source
 * @param [in] 1
 * @retval VOID
*/
VOID HAL_POST_SetOutINTSource(UINT32 u32Sor)
{
	return;
	//reg_post_int_source_sel
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_source_sel),u32Sor);
}

/**
 * @brief This function set kpost out interrupt horizantal number
 * @param [in] H number
 * @retval VOID
*/
VOID HAL_POST_SetOutINTHNum(UINT32 u32Hnum)
{
	return;
	//reg_post_out_vtotal_int
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_out_vtotal_int),u32Hnum);
}

/**
 * @brief This function set kpost out interrupt enable
 * @param [in] u32IntType: 0 for H sync, 1 for V sync
 * @param [in] bEnable
 * @retval VOID
*/
VOID HAL_POST_SetOutINTEnable(UINT32 u32IntType, BOOL bEnable)
{
	return;
	UINT32 u32InINT_en = 0;
	ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_en), &u32InINT_en);

	if(bEnable)
	{
		u32InINT_en = u32InINT_en | (1 << u32IntType);
	}
	else
	{
		u32InINT_en = u32InINT_en & (~(1 << u32IntType));
	}

	//reg_post_int_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_en),u32InINT_en);
}

BOOL HAL_POST_GetOutINTEnable(UINT32 u32IntType)
{
	return;
	UINT32 v = 0;

       ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_en),&v);
       return (v >> u32IntType) & 0x1;
}

/**
 * @brief This function set post cursor enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetCursorEnable(BOOL bEnable)
{
	return;
	//reg_post_cursor_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_en),(UINT32)bEnable);
}

/**
 * @brief This function set post cursor show
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_POST_SetCursorShow(BOOL bEnable)
{
	return;
	//reg_post_cursor_show
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_show),(UINT32)bEnable);
}

/**
 * @brief This function set post cursor position
 * @param [in] reg_post_cursor_h
 * @param [in] reg_post_cursor_v
 * @retval VOID
*/
VOID HAL_POST_SetCursorPosition(UINT32 u32Hposition, UINT32 u32Vposition)
{
	return;
	//reg_post_cursor_h
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_h),(UINT32)u32Hposition);
	//reg_post_cursor_v
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_v),(UINT32)u32Vposition);
}

/**
 * @brief This function set post cursor width
 * @param [in] UINT32 u32Width(0~15)
 * @retval VOID
*/
VOID HAL_POST_SetCursorWidth(UINT32 u32Width)
{
	return;
	//reg_post_cursor_h_width
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_h_width),(UINT32)u32Width);
}

/**
 * @brief This function set post cursor color
 * @param [in] UINT32 u32Width(0~7)
 * @retval VOID
*/
VOID HAL_POST_SetCursorColor(UINT32 u32Color)
{
	return;
	//reg_post_cursor_h_width
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_cursor_color),(UINT32)u32Color);
}

/**
 * @brief This function set kpost top out interrupt clear
 * @param [in] eIntType: 0 for H sync, 1 for V sync
 * @param [in] bWclr
 * @retval VOID
*/
VOID HAL_KPOST_TOP_SetOutINTWclr(INT_TYPE eIntType, BOOL bWclr)
{
	return;
	UINT32 u32InINT_Clear = 0;
	ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_wclr), &u32InINT_Clear);

	if(bWclr)
		u32InINT_Clear = u32InINT_Clear | ( 1 << (UINT32)eIntType);
	else
		u32InINT_Clear = u32InINT_Clear & (~( 1 << (UINT32)eIntType));

	//reg_kmc_int_en
	WriteRegister(KIWI_REG(FRC_TOP__KPOST_TOP__reg_post_int_wclr), u32InINT_Clear);
}
/**
 * @brief This function get kost top out interrupt status
 * @retval UINT32
*/
UINT32 HAL_KPOST_TOP_GetOutINTStatus(VOID)
{
	return;
	UINT32 u32OutINT_Sts = 0;
	ReadRegister(KIWI_REG(FRC_TOP__KPOST_TOP__regr_post_int_pending), &u32OutINT_Sts);
	return u32OutINT_Sts;
}

