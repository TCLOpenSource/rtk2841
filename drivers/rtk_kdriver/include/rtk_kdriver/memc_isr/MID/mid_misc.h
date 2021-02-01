/**
 * @file mid_misc.h
 * @brief This file implements misc header.
 * @date September.3.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#ifndef _MID_MISC_HEADER_INCLUDE_
#define _MID_MISC_HEADER_INCLUDE_

/**
 * @brief This function set demo window Enable
 * @param [in] UBYTE ubyWinID: 0~7
 * @param [in] BOOL bEnable
 * @retval [Out] true: success, false: fail
*/
BOOL Mid_MISC_SetDemoWindowEnable(UBYTE ubyWinID, BOOL bEnable);

/**
 * @brief This function get demo window Enable
 * @param [in] UBYTE ubyWinID
 * @retval  BOOL bEnable
*/
BOOL Mid_MISC_GetDemoWindowEnable(UBYTE ubyWinID);

/**
 * @brief This function set demo window mode
 * @param [in] BOOL bMode: 0: inside MEMC OFF; 1: outside MEMC OFF
 * @retval VOID
*/
VOID Mid_MISC_SetDemoWindowMode(BOOL bMode);

/**
 * @brief This function get demo window mode
 * @retval BOOL bMode: 0: inside MEMC OFF; 1: outside MEMC OFF
*/
BOOL Mid_MISC_GetDemoWindowMode(VOID);

/**
 * @brief This function set demo window settings
 * @param [in] UBYTE ubyWinID: 0~7
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @param [in] UINT32 u32Top 
 * @param [in] UINT32 u32Bottom 
 * @retval [Out] true: success, false: fail
*/
BOOL Mid_MISC_SetDemoWindowSettings(UBYTE ubyWinID, UINT32 u32Left, UINT32 u32Right, UINT32 u32Top, UINT32 u32Bottom);

/**
 * @brief This function get demo window settings
 * @param [in] UBYTE ubyWinID
 * @param [out] UINT32 u32Left
 * @param [out] UINT32 u32Right
 * @param [out] UINT32 u32Top 
 * @param [out] UINT32 u32Bottom 
 * @retval VOID
*/
VOID Mid_MISC_GetDemoWindowSettings(UBYTE ubyWinID, UINT32 *pu32Left, UINT32 *pu32Right, UINT32 *pu32Top, UINT32 *pu32Bottom);

/**
 * @brief This function set input data mapping
 * @param [in] UINT32 u32Data_Mapping 
 * @retval VOID
*/
VOID Mid_MISC_SetInputDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get input data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetInputDataMapping(VOID);

/**
 * @brief This function set nr data mapping
 * @param [in] UINT32 u32Data_Mapping 
 * @retval VOID
*/
VOID Mid_MISC_SetNRDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get nr data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetNRDataMapping(VOID);

/**
 * @brief This function set output data mapping
 * @param [in] UINT32 u32Data_Mapping 
 * @retval VOID
*/
VOID Mid_MISC_SetOutputDataMapping(UINT32 u32Data_Mapping);

/**
 * @brief This function get output data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetOutputDataMapping(VOID);

/**
 * @brief This function set black insert line mode enable
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeEnable(BOOL bEnable);

/**
 * @brief This function set black insert line mode pattern number
 * @param [in] UINT32 u32PatternNum 
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModePatternNum(UINT32 u32PatternNum);

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern 
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeLPattern(UINT32 u32Pattern);

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern 
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeRPattern(UINT32 u32Pattern);

/**
 * @brief This function set black insert frame mode enable
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertFrameModeEnable(BOOL bEnable);

/**
 * @brief This function set input interrupt enable
 * @param [in] BOOL bEnable 
 * @param [in] u32IntType: 0 for H sync, 1 for V sync, 2 for Abnormal 
 * @retval VOID
*/
VOID Mid_MISC_SetInINTEnable(INT_TYPE enIntType, BOOL bEnable);
BOOL Mid_MISC_GetInINTEnable(INT_TYPE enIntType);

/**
 * @brief This function set in interrupt horizantal number
 * @param [in] UINT32 u32Hnum 
 * @retval VOID
*/
VOID Mid_MISC_SetInINTHnum(UINT32 u32Hnum);

/**
 * @brief This function set output interrupt enable
 * @param [in] BOOL bEnable 
 * @param [in] u32IntType: 0 for H sync, 1 for V sync
 * @retval VOID
*/
VOID Mid_MISC_SetOutINTEnable(INT_TYPE enIntType, BOOL bEnable);
BOOL Mid_MISC_GetOutINTEnable(INT_TYPE enIntType);

/**
 * @brief This function set output interrupt horizantal number
 * @param [in] UINT32 u32Hnum 
 * @retval VOID
*/
VOID Mid_MISC_SetOutINTHnum(UINT32 u32Hnum);

/**
 * @brief This function set post cursor enable
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorEnable(BOOL bEnable);

/**
 * @brief This function set post cursor show
 * @param [in] BOOL bEnable 
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorShow(BOOL bEnable);

/**
 * @brief This function set post cursor position
 * @param [in] reg_post_cursor_h
 * @param [in] reg_post_cursor_v
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorPosition(UINT32 u32Hposition, UINT32 u32Vposition);

/**
 * @brief This function set post cursor width
 * @param [in] UINT32 u32Width(0~15)
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorWidth(UINT32 u32Width);

/**
 * @brief This function set post cursor color
 * @param [in] UINT32 u32Width(0~7)
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorColor(UINT32 u32Color);

/**
 * @brief This function Lock Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_IntINTLock(INT_TYPE enIntType);
/**
 * @brief This function unLock Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_IntINTUnLock(INT_TYPE enIntType);
/**
 * @brief This function Clear Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_IntINTCLear(INT_TYPE enIntType);
/**
 * @brief This function Lock Out Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_OutINTLock(INT_TYPE enIntType);
/**
 * @brief This function unLock Out Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_OutINTUnLock(INT_TYPE enIntType);
/**
 * @brief This function Clear Out Interrupt
 * @param [in] INT_TYPE enIntType 
 * @retval VOID
*/
VOID Mid_MISC_OutINTCLear(INT_TYPE enIntType);

/**
 * @brief This function Get in intType sts
 * @param [in] INT_TYPE enIntType 
 * @retval BOOL
*/
BOOL Mid_MISC_GetInINTStatus(INT_TYPE enIntType);
/**
 * @brief This function Get out intType sts
 * @param [in] INT_TYPE enIntType 
 * @retval BOOL
*/
BOOL Mid_MISC_GetOutINTStatus(INT_TYPE enIntType);
#endif
