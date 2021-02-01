/**
 * @file hal_dehalo.c
 * @brief This file is for dehalo register setting
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
 * @brief This function set Dehalo on/off
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetEnable(BOOL bEnable)
{
	return;
	//reg_dh_en
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_en), (UINT32)bEnable);
}

/**
 * @brief This function set Dehalo row size
 * @param [in] UINT32 u32Row_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetRowSize(UINT32 u32Row_Size)
{
	return;
	//reg_dh_mv_row_size
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_mv_row_size),u32Row_Size);
}

/**
 * @brief This function set Dehalo block size
 * @param [in] UINT32 u32Block_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetBlockSize(UINT32 u32Block_Size)
{
	return;
	//reg_dh_blk_size
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_mv_blk_size),u32Block_Size);
}

/**
 * @brief This function set Dehalo logo row size
 * @param [in] UINT32 u32Row_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetLogoRowSize(UINT32 u32Row_Size)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_row_size),u32Row_Size);
}

/**
 * @brief This function set Dehalo logo block size
 * @param [in] UINT32 u32Block_Size
 * @retval VOID
*/
VOID HAL_Dehalo_SetLogoBlockSize(UINT32 u32Block_Size)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_logo_blk_size),u32Block_Size);
}

/**
 * @brief This function set Dehalo YX ratio
 * @param [in] UINT32 u32YXRatio
 * @retval VOID
*/
VOID HAL_Dehalo_SetYXRatio(UINT32 u32YXRatio)
{
	return;
	//reg_dh_blk_size
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_yx_ratio),u32YXRatio);
}

/**
 * @brief This function set Dehalo block number
 * @param [in] UINT32 u32Block_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetBlockNum(UINT32 u32Block_Num)
{
	return;
	//reg_dh_blk_num[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_mv_blk_num),u32Block_Num);
}

/**
 * @brief This function set Dehalo row number
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetRowNum(UINT32 u32Row_Num)
{
	return;
	//reg_dh_row_num[7:0]
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_mv_row_num),u32Row_Num);
}

/**
 * @brief This function set Dehalo vbuf block number
 * @param [in] UINT32 u32Block_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufBlockNum(UINT32 u32Block_Num)
{
	return;
	//reg_dh_vbuf_blk_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_vbuf_blk_num),u32Block_Num);
}

/**
 * @brief This function set Dehalo vbuf row number
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufRowNum(UINT32 u32Row_Num)
{
	return;
	//reg_dh_vbuf_row_num
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_vbuf_row_num),u32Row_Num);
}

/**
 * @brief This function set Dehalo PR enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetPREnable(BOOL bEnable)
{
	return;
	//reg_dh_pr_read
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_pr_read), (UINT32)bEnable);
}

/**
 * @brief This function set Dehalo MV RD intval
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetMVRDIntval(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_mv_rd_intval), (UINT32)bEnable);
}

/**
 * @brief This function set half v timing
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetHalfVTiming(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_half_v_timing), (UINT32)bEnable);
}

/**
 * @brief This function set patt size
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetPattSize(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_pre_patt_blk_size), (UINT32)bEnable);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_pre_patt_row_size), (UINT32)bEnable);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_pst_patt_blk_size), (UINT32)bEnable);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_pst_patt_row_size), (UINT32)bEnable);
}

/**
 * @brief This function set out timing mux
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID HAL_Dehalo_SetOutTimimgMux(UINT32 u32Val)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_out_tim_mux), u32Val);
}

/**
 * @brief This function set rd lr flow wr latch
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetRDLRFlowWRLatch(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_rd_lr_flow_wrlatch), (UINT32)bEnable);
}

/**
 * @brief This function set sw reset
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetSWReset(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_sw_reset), (UINT32)bEnable);
}

/**
 * @brief This function set Dehalo patt block / row number
 * @param [in] UINT32 u32Block_Num
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetPatternBlockRow(UINT32 u32Block_Num, UINT32 u32Row_Num)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_patt_blk_num),u32Block_Num);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_patt_row_num),u32Row_Num);
}

/**
 * @brief This function set Dehalo vbuf block / row number
 * @param [in] UINT32 u32Block_Num
 * @param [in] UINT32 u32Row_Num
 * @retval VOID
*/
VOID HAL_Dehalo_SetVbufBlockRow(UINT32 u32Block_Num, UINT32 u32Row_Num)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_vbuf_blk_num),u32Block_Num);
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_vbuf_row_num),u32Row_Num);
}

/**
 * @brief This function set Dehalo show enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetShowEnable(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_show_en),(UINT32)bEnable);
}

/**
 * @brief This function set Dehalo show select
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetShowSelect(UINT32 u32Select)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO__reg_dh_show_sel),u32Select);
}

/**
 * @brief This function set Dehalo erosion mode
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_Dehalo_SetErosionMode(BOOL bEnable)
{
	return;
	WriteRegister(KIWI_REG(FRC_TOP__KME_DEHALO2__reg_dh_ero_mod),(BOOL)bEnable);
}

