/**
 * @file mid_mode.h
 * @brief This file implements mode change api header.
 * @date August.30.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifndef _MID_MODE_HEADER_INCLUDE_
#define _MID_MODE_HEADER_INCLUDE_

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/memc_type.h"

/**
 * @brief This function set InOut mode.
 * @param [in] emom Specify InOut mode.
 * @retval VOID
*/
VOID Mid_Mode_SetInOutMode(INOUT_MODE emom);

/**
 * @brief This function set mc blend mode.
 * @param [in] emom Specify InOut mode.
 * @retval VOID
*/
VOID Mid_Mode_SetMCBlend(INOUT_MODE emom);

/**
 * @brief This function set parameters for this mode and check this mode if valid.
 * @param [in] emir Specify input resolution.
 * @param [in] emor Specify output resolution.
 * @param [in] emif Specify input format.
 * @param [in] emof Specify output format.
 * @param [in] bForce force to change the format or not.
 * @retval true for valid, false for invalid
*/
BOOL Mid_Mode_UpdateParameters(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, INPUT_FORMAT emif, OUTPUT_FORMAT emof);

/**
 * @brief This function set input/output format.
 * @param [in] emir Specify input resolution.
 * @param [in] emor Specify output resolution.
 * @param [in] emif Specify input format.
 * @param [in] emof Specify output format.
 * @param [in] bvflip Specify vflip.
 * @retval VOID
*/
VOID Mid_Mode_Set_VideoPath(INPUT_RESOLUTION emir, OUTPUT_RESOLUTION emor, INPUT_FORMAT emif, OUTPUT_FORMAT emof, BOOL bVflip);

/**
 * @brief This function set input timing parameters.
 * @param [in] emir Specify input resolution.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_Set_InputTimingParameters(INPUT_RESOLUTION emir);

/**
 * @brief This function get input timing parameters.
 * @param [in] VOID.
 * @retval input timing parameters
*/
TIMING_PARA_ST Mid_Mode_Get_InputTimingParameters(VOID);

/**
 * @brief This function set output timing parameters.
 * @param [in] emir Specify output resolution.
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_Set_OutputTimingParameters(OUTPUT_RESOLUTION emor);

/**
 * @brief This function get output timing parameters.
 * @param [in] VOID.
 * @retval output timing parameters
*/
TIMING_PARA_ST Mid_Mode_Get_OutputTimingParameters(VOID);

/**
 * @brief This function get ME v active.
 * @param [in] VOID.
 * @retval ME v active
*/
UINT32 Mid_Mode_Get_ME_Vact(VOID);

/**
 * @brief This function get ME row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_MERowNum(VOID);

/**
 * @brief This function get ME2 row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_ME2RowNum(VOID);

/**
 * @brief This function get Dehalo row number.
 * @param [in] VOID.
 * @retval ME row number
*/
UINT32 Mid_Mode_Get_DehaloRowNum(VOID);

/**
 * @brief This function get ME v size.
 * @param [in] VOID.
 * @retval ME v size
*/
UINT32 Mid_Mode_Get_MEVSize(VOID);

/**
 * @brief This function get ME v size.
 * @param [in] VOID.
 * @retval ME v size
*/
UINT32 Mid_Mode_Get_ME2VSize(VOID);

/**
 * @brief This function get Post H scaler.
 * @param [in] VOID.
 * @retval post h scaler
*/
POST_SCALER_RATIO_H Mid_Mode_GetPostHSC(VOID);

/**
 * @brief This function get Post V scaler.
 * @param [in] VOID.
 * @retval post v scaler
*/
POST_SCALER_RATIO_V Mid_Mode_GetPostVSC(VOID);

/**
 * @brief This function set v flip.
 * @param [in] BOOL bVflip.
 * @param [in] OUTPUT_FORMAT emof.
 * @retval VOID
*/
VOID Mid_Mode_SetVFlip(BOOL bVflip, OUTPUT_FORMAT emof);

/**
 * @brief This function set last line enable.
 * @param [in] BOOL bVflip.
 * @param [in] INPUT_FORMAT emif.
 * @param [in] OUTPUT_FORMAT emof.
 * @retval VOID
*/
VOID Mid_Mode_LastLineEnable(BOOL bVflip, INPUT_FORMAT emif, OUTPUT_FORMAT emof);

/**
 * @brief This function set MEMC frame repeat mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
*/
VOID Mid_Mode_SetMEMCFrameRepeatEnable(BOOL bEnable, UBYTE *SetMCBlendMode);

/**
 * @brief This function set MEMC low delay mode.
 * @param [in] bEnable 		true for enable, false for disalbe.
*/
VOID Mid_Mode_SetMEMC_PCModeEnable(BOOL bEnable);

/**
 * @brief This function set MC PT Zero type1
 * @param [in] u32Type: 0: iz; 1: pz; 2: avg; 3: phase blend; 4: I/P by phase; 5: med3
 * @retval VOID
*/
VOID Mid_Mode_SetPTZeroType1(UINT32 u32Type);

/**
 * @brief This function set MC PT Zero type2
 * @param [in] u32Type: 0: iz; 1: pz; 2: avg; 3: phase blend; 4: I/P by phase; 5: med3
 * @retval VOID
*/
VOID Mid_Mode_SetPTZeroType2(UINT32 u32Type);

/**
 * @brief This function set ME work mode
 * @param [in] UINT32 u32WorkMode : 0 for 1:2, 1 for 1:1
* @retval VOID
*/
VOID Mid_Mode_SetMEWorkMode(UINT32 u32WorkMode);

/**
 * @brief This function set ppfv index
 * @param [in] UINT32 u32WorkMode : 0 for 1:2, 1 for 1:1
 * @param [in] OUTPUT_FORMAT emof
 * @retval VOID
*/
VOID Mid_Mode_SetPPFVIDX(UINT32 u32WorkMode, OUTPUT_FORMAT emof);

/**
 * @brief This function set 3d LR signal
 * @param [in] BOOL bEnable
 * @param [in] UINT32 u32Cycle
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_Mode_Set3DLR(BOOL bEnable, UINT32 u32Cycle, UINT32 u32Pattern);

/**
 * @brief This function force lbmc idx
 * @param [in] INOUT_MODE emom
 * @param [in] OUTPUT_FORMAT emof
* @retval VOID
*/
VOID Mid_Mode_ForceLBMCIdx(INOUT_MODE emom, OUTPUT_FORMAT emof);

/**
 * @brief This function set me 3d LR signal
 * @param [in] BOOL bEnable
 * @param [in] UINT32 u32Cycle
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_Mode_SetME3DLR(BOOL bEnable, UINT32 u32Cycle, UINT32 u32Pattern);

/**
 * @brief This function set MEMC module ratio.
 * @param [in] UBYTE pix sft
 * @param [in] UBYTE blk sft
 * @param [in] UBYTE pix sft
 * @param [in] UBYTE blk sft
 * @retval TRUE 		indicates success
 * @retval FALSE		indicates fail.
*/
BOOL Mid_Mode_GetMEMCModuleSft(UBYTE *u8_in_me1_pix_sft,UBYTE *u8_in_me1_blk_sft,UBYTE *u8_in_me2_pix_sft,UBYTE *u8_in_me2_blk_sft);

/**
 * @brief This function set DM PFV PPFV interval
 * @param [in] UINT32 u32Val
 * @retval VOID
*/
VOID Mid_Mode_SetDMPFVPPFVInterval(UINT32 uiVal);

#ifndef REAL_CHIP	// FPGA
/**
 * @brief This function set 2 port enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_Mode_SetTOPA2PortEnable(BOOL bEnable);
#endif



/**
 * @brief This function get DMA_Ready_flag by MC04_06_total_data_cnt.
 * @param [in] VOID.
 * @retval DMA_Ready status
*/
BOOL Mid_Mode_GetMC_DMA_Ready_flag(VOID);


#endif
