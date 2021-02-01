/**
 * @file hal_crtc.h
  * @brief This file is for crtc register setting
  * @date Nov.14.2014
  * @version V0.0.1
  * @author Martin Yan
  * @par Copyright (C) 2014 Real-Image Co. LTD
  * @par History:
  * 		 Version: 0.0.1
 */

#ifndef _HAL_CRTC_HEADER_INCLUDE_
#define _HAL_CRTC_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set frc timing
 * @param [in] TIMING_PARA_ST stFRCTiming
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCTiming(TIMING_PARA_ST stFRCTiming);

/**
 * @brief This function set osd timing
 * @param [in] u32Hact
 * @param [in] u32Vact
 * @retval VOID
*/
VOID HAL_CRTC_SetOSDTiming(UINT32 u32Hact, UINT32 u32Vact);

/**
 * @brief This function set panel timing
 * @param [in] TIMING_PARA_ST stFRCTiming
 * @retval VOID
*/
VOID HAL_CRTC_SetPanelTiming(PANEL_PARAMETERS_ST stPanelTiming);

/**
 * @brief This function get ME orig vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32ME_Orig_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMEOrigVtrigDelay(VOID);

/**
 * @brief This function set ME orig vtrig delay
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID HAL_CRTC_SetMEOrigVtrigDelay(UINT32 u32Val);

/**
 * @brief This function get ME vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32ME_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMEVtrigDelay(VOID);
/**
 * @brief This function get MC vtrig delay
 * @param [in] VOID
 * @retval UINT32 u32MC_Vtrig_dly
*/
UINT32 HAL_CRTC_GetMCVtrigDelay(VOID);

/**
 * @brief This function set frc vtrig delay
 * @param [in] UINT32 u32FRC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCVtrigDelay(UINT32 u32FRC_Vtrig_dly);

/**
 * @brief This function set frc vtrig delay
 * @param [in] UINT32 u32FRC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetLbmeVtrigDelay(UINT32 u32Lbme_Vtrig_dly);

/**
 * @brief This function set frc pre de l num
 * @param [in] UINT32 u32Frc_Prede_LNum
 * @retval VOID
*/
VOID HAL_CRTC_SetFrcPredeLNum(UINT32 u32Frc_Prede_LNum);

/**
 * @brief This function set dehalo vtrig delay
 * @param [in] UINT32 u32DEHALO_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloVtrigDelay(UINT32 u32DEHALO_Vtrig_dly);

/**
 * @brief This function set dec vtrig delay
 * @param [in] UINT32 u32DEC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetDecVtrigDelay(UINT32 u32DEC_Vtrig_dly);

/**
 * @brief This function set mc vtrig delay
 * @param [in] UINT32 u32MC_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetMCVtrigDelay(UINT32 u32MC_Vtrig_dly);

/**
 * @brief This function set lbmc vtrig delay
 * @param [in] UINT32 u32Lbmc_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetLbmcVtrigDelay(UINT32 u32Lbmc_Vtrig_dly);

/**
 * @brief This function set me vactive
 * @param [in] UINT32 u32ME_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetMEVactive(UINT32 u32ME_Vactive);

/**
 * @brief This function set dehalo vactive
 * @param [in] UINT32 u32Dehalo_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloVactive(UINT32 u32Dehalo_Vactive);

/**
 * @brief This function set mc vactive
 * @param [in] UINT32 u32MC_Vactive
 * @retval VOID
*/
VOID HAL_CRTC_SetMCVactive(UINT32 u32MC_Vactive);

/**
 * @brief This function set me row type
 * @param [in] UINT32 u32ME_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetME1RowType(UINT32 u32ME_Row_Type);

/**
 * @brief This function set me2 row type
 * @param [in] UINT32 u32ME_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetME2RowType(UINT32 u32ME_Row_Type);

/**
 * @brief This function set dehalo row type
 * @param [in] UINT32 u32Dehalo_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetDehaloRowType(UINT32 u32Dehalo_Row_Type);

/**
 * @brief This function set mc row type
 * @param [in] UINT32 u32MC_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetMCRowType(UINT32 u32MC_Row_Type);

/**
 * @brief This function set plogo row type
 * @param [in] UINT32 u32Plogo_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetPlogoRowType(UINT32 u32Plogo_Row_Type);

/**
 * @brief This function set plogo fetch row type
 * @param [in] UINT32 u32Plogo_fetch_Row_Type
 * @retval VOID
*/
VOID HAL_CRTC_SetPlogoFetchRowType(UINT32 u32Plogo_fetch_Row_Type);

/**
 * @brief This function set frc prede pnum
 * @param [in] UINT32 u32FRC_prede_pnum
 * @retval VOID
*/
VOID HAL_CRTC_SetFRCPreDEPNum(UINT32 u32FRC_prede_pnum);

/**
 * @brief This function set panel vtrig delay
 * @param [in] UINT32 u32Panel_Vtrig_dly
 * @retval VOID
*/
VOID HAL_CRTC_SetOutVtrigDelay(UINT32 u32Panel_Vtrig_dly);

/**
 * @brief This function set n to m
 * @param [in] UINT32 u32N
 * @param [in] UINT32 u32M
 * @retval VOID
*/
VOID HAL_CRTC_SetN2M(UINT32 u32N, UINT32 u32M);

/**
 * @brief This function set CRTC slave mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CRTC_SetSlaveModeEnable(BOOL bEnable);

/**
 * @brief This function set lbmc normal lf delay
 * @param [in] UBYTE ubyIdx (0~8)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCNormalLFDly(UBYTE ubyIdx, UBYTE ubyDly);

/**
 * @brief This function set lbmc normal hf delay
 * @param [in] UBYTE ubyIdx (0~3)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCNormalHFDly(UBYTE ubyIdx, UBYTE ubyDly);

/**
 * @brief This function set lbmc signle lf delay
 * @param [in] UBYTE ubyIdx (0~8)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCSingleLFDly(UBYTE ubyIdx, UBYTE ubyDly);

/**
 * @brief This function set lbmc single hf delay
 * @param [in] UBYTE ubyIdx (0~3)
 * @param [in] UBYTE ubyDly
 * @retval VOID
*/
VOID HAL_CRTC_SetLBMCSingleHFDly(UBYTE ubyIdx, UBYTE ubyDly);

/**
 * @brief This function get vspll lock status
 * @retval True for lock
 * @retval False for unlock
*/
BOOL HAL_CRTC_GetVSPLLStatus(VOID);

/**
 * @brief This function set crtc lr enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID HAL_CRTC_SetLREnable(BOOL bEnable);

/**
 * @brief This function set crtc lr cycle
 * @param [in] UINT32 u32Cycle
 * @retval VOID
*/
VOID HAL_CRTC_SetLRCycle(UINT32 u32Cycle);

/**
 * @brief This function set crtc lr pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID HAL_CRTC_SetLRPattern(UINT32 u32Pattern);

#endif
