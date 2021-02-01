/**
 * @file mid_misc.c
 * @brief This file is for misc settings
 * @date Oct.17.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/HAL/hal_mc.h"
#include "memc_isr/HAL/hal_ip.h"
#include "memc_isr/HAL/hal_post.h"

/**
 * @brief This function set demo window Enable
 * @param [in] UBYTE ubyWinID: 0~7
 * @param [in] BOOL bEnable
 * @retval true: success, false: fail
*/
BOOL Mid_MISC_SetDemoWindowEnable(UBYTE ubyWinID, BOOL bEnable)
{
	if(ubyWinID > 8)
	{
		return FALSE;
	}
	else
	{
		HAL_MC_SetDemoWindowEnable(ubyWinID, bEnable);
		return TRUE;
	}
}

/**
 * @brief This function get demo window Enable
 * @param [in] UBYTE ubyWinID
 * @retval  BOOL bEnable
*/
BOOL Mid_MISC_GetDemoWindowEnable(UBYTE ubyWinID)
{
	return(HAL_MC_GetDemoWindowEnable(ubyWinID));
}

/**
 * @brief This function set demo window mode
 * @param [in] BOOL bMode: 0: inside MEMC OFF; 1: outside MEMC OFF
 * @retval VOID
*/
VOID Mid_MISC_SetDemoWindowMode(BOOL bMode)
{
	HAL_MC_SetDemoWindowMode(bMode);
}

/**
 * @brief This function get demo window mode
 * @retval BOOL bMode: 0: inside MEMC OFF; 1: outside MEMC OFF
*/
BOOL Mid_MISC_GetDemoWindowMode(VOID)
{
	return(HAL_MC_GetDemoWindowMode());
}

/**
 * @brief This function set demo window settings
 * @param [in] UBYTE ubyWinID: 0~7
 * @param [in] UINT32 u32Left
 * @param [in] UINT32 u32Right
 * @param [in] UINT32 u32Top
 * @param [in] UINT32 u32Bottom
 * @retval true: success, false: fail
*/
BOOL Mid_MISC_SetDemoWindowSettings(UBYTE ubyWinID, UINT32 u32Left, UINT32 u32Right, UINT32 u32Top, UINT32 u32Bottom)
{
	if(ubyWinID > 8)
	{
		return FALSE;
	}
	else if((u32Right < u32Left) || (u32Bottom < u32Top))
	{
		return FALSE;
	}
	else
	{
		HAL_MC_SetDemoWindowSettings(ubyWinID, u32Left, u32Right, u32Top, u32Bottom);
		return TRUE;
	}
}
/**
 * @brief This function get demo window settings
 * @param [in] UBYTE ubyWinID
 * @param [out] UINT32 u32Left
 * @param [out] UINT32 u32Right
 * @param [out] UINT32 u32Top
 * @param [out] UINT32 u32Bottom
 * @retval VOID
*/
VOID Mid_MISC_GetDemoWindowSettings(UBYTE ubyWinID, UINT32 *pu32Left, UINT32 *pu32Right, UINT32 *pu32Top, UINT32 *pu32Bottom)
{
	HAL_MC_GetDemoWindowSettings(ubyWinID, pu32Left, pu32Right, pu32Top, pu32Bottom);
}

/**
 * @brief This function set input data mapping
 * @param [in] UINT32 u32Data_Mapping
 * @retval VOID
*/
VOID Mid_MISC_SetInputDataMapping(UINT32 u32Data_Mapping)
{
	HAL_IP_SetDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get input data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetInputDataMapping(VOID)
{
	return(HAL_IP_GetDataMapping());
}

/**
 * @brief This function set nr data mapping
 * @param [in] UINT32 u32Data_Mapping
 * @retval VOID
*/
VOID Mid_MISC_SetNRDataMapping(UINT32 u32Data_Mapping)
{
	HAL_KMC_TOP_SetDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get nr data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetNRDataMapping(VOID)
{
	return (HAL_KMC_TOP_GetDataMapping());
}

/**
 * @brief This function set output data mapping
 * @param [in] UINT32 u32Data_Mapping
 * @retval VOID
*/
VOID Mid_MISC_SetOutputDataMapping(UINT32 u32Data_Mapping)
{
	HAL_POST_SetDataMapping(u32Data_Mapping);
}

/**
 * @brief This function get output data mapping
 * @param [in] VOID
 * @retval data mapping(range:0~7)
*/
UINT32 Mid_MISC_GetOutputDataMapping(VOID)
{
	return (HAL_POST_GetDataMapping());
}

/**
 * @brief This function set black insert line mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeEnable(BOOL bEnable)
{
	HAL_POST_SetBlackInsertLineModeEnable(bEnable);
}

/**
 * @brief This function set black insert line mode pattern number
 * @param [in] UINT32 u32PatternNum
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModePatternNum(UINT32 u32PatternNum)
{
	HAL_POST_SetBlackInsertLineModePatternNum(u32PatternNum);
}

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeLPattern(UINT32 u32Pattern)
{
	HAL_POST_SetBlackInsertLineModeLPattern(u32Pattern);
}

/**
 * @brief This function set black insert line mode pattern
 * @param [in] UINT32 u32Pattern
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertLineModeRPattern(UINT32 u32Pattern)
{
	HAL_POST_SetBlackInsertLineModeRPattern(u32Pattern);
}

/**
 * @brief This function set black insert frame mode enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetBlackInsertFrameModeEnable(BOOL bEnable)
{
	HAL_POST_SetBlackInsertFrameModeEnable(bEnable);
}

/**
 * @brief This function set input interrupt enable
 * @param [in] BOOL bEnable
 * @param [in] enIntType: 0 for H sync, 1 for V sync, 2 for Abnormal
 * @retval VOID
*/
VOID Mid_MISC_SetInINTEnable(INT_TYPE enIntType, BOOL bEnable)
{
	if(bEnable)
	{
		HAL_KMC_TOP_SetInINTSel(7);
		HAL_KMC_TOP_SetInINTSource(0);
	}
	HAL_KMC_TOP_SetInINTEnable((UINT32)enIntType, bEnable);
}

BOOL Mid_MISC_GetInINTEnable(INT_TYPE enIntType)
{
       return HAL_KMC_TOP_GetInINTEnable((UINT32)enIntType);
}

/**
 * @brief This function set in interrupt horizantal number
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID Mid_MISC_SetInINTHnum(UINT32 u32Hnum)
{
	HAL_KMC_TOP_SetInINTHNum(u32Hnum);
}

/**
 * @brief This function set output interrupt enable
 * @param [in] BOOL bEnable
 * @param [in] enIntType: 0 for H sync, 1 for V sync
 * @retval VOID
*/
VOID Mid_MISC_SetOutINTEnable(INT_TYPE enIntType, BOOL bEnable)
{
	if(bEnable)
	{
		HAL_POST_SetOutINTSel(7);
		HAL_POST_SetOutINTSource(0);
	}
	HAL_POST_SetOutINTEnable((UINT32)enIntType, bEnable);
}

BOOL Mid_MISC_GetOutINTEnable(INT_TYPE enIntType)
{
       return HAL_POST_GetOutINTEnable((UINT32)enIntType);
}

/**
 * @brief This function set output interrupt horizantal number
 * @param [in] UINT32 u32Hnum
 * @retval VOID
*/
VOID Mid_MISC_SetOutINTHnum(UINT32 u32Hnum)
{
	HAL_POST_SetOutINTHNum(u32Hnum);
}

/**
 * @brief This function set post cursor enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorEnable(BOOL bEnable)
{
	HAL_POST_SetCursorEnable(bEnable);
}

/**
 * @brief This function set post cursor show
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorShow(BOOL bEnable)
{
	HAL_POST_SetCursorShow(bEnable);
}

/**
 * @brief This function set post cursor position
 * @param [in] reg_post_cursor_h
 * @param [in] reg_post_cursor_v
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorPosition(UINT32 u32Hposition, UINT32 u32Vposition)
{
	HAL_POST_SetCursorPosition(u32Hposition, u32Vposition);
}

/**
 * @brief This function set post cursor width
 * @param [in] UINT32 u32Width(0~15)
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorWidth(UINT32 u32Width)
{
	HAL_POST_SetCursorWidth(u32Width);
}

/**
 * @brief This function set post cursor color
 * @param [in] UINT32 u32Width(0~7)
 * @retval VOID
*/
VOID Mid_MISC_SetPostCursorColor(UINT32 u32Color)
{
	HAL_POST_SetCursorColor(u32Color);
}
/**
 * @brief This function Lock Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_IntINTLock(INT_TYPE enIntType)
{
	HAL_KMC_TOP_SetInINTWclr(enIntType, TRUE);
}
/**
 * @brief This function unLock Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_IntINTUnLock(INT_TYPE enIntType)
{
	HAL_KMC_TOP_SetInINTWclr(enIntType, FALSE);
}
/**
 * @brief This function Clear Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_IntINTCLear(INT_TYPE enIntType)
{
	HAL_KMC_TOP_SetInINTWclr(enIntType, TRUE);
	HAL_KMC_TOP_SetInINTWclr(enIntType, FALSE);
}
/**
 * @brief This function Lock Out Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_OutINTLock(INT_TYPE enIntType)
{
	HAL_KPOST_TOP_SetOutINTWclr(enIntType, TRUE);
}
/**
 * @brief This function unLock Out Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_OutINTUnLock(INT_TYPE enIntType)
{
	HAL_KPOST_TOP_SetOutINTWclr(enIntType, FALSE);

}
/**
 * @brief This function Clear Out Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval VOID
*/
VOID Mid_MISC_OutINTCLear(INT_TYPE enIntType)
{
	HAL_KPOST_TOP_SetOutINTWclr(enIntType, TRUE);
	HAL_KPOST_TOP_SetOutINTWclr(enIntType, FALSE);

}
/**
 * @brief This function Clear Out Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval BOOL
*/
BOOL Mid_MISC_GetInINTStatus(INT_TYPE enIntType)
{
	UINT32 u32InINTSts = 0;
	u32InINTSts = HAL_KMC_TOP_GetInINTStatus();
	return ((u32InINTSts & (1 << (UINT32)enIntType))>> (UINT32)enIntType);
}

/**
 * @brief This function Clear Out Interrupt
 * @param [in] INT_TYPE enIntType
 * @retval BOOL
*/
BOOL Mid_MISC_GetOutINTStatus(INT_TYPE enIntType)
{
	UINT32 u32OutINTSts = 0;
	u32OutINTSts = HAL_KPOST_TOP_GetOutINTStatus();
	return ((u32OutINTSts & (1 << (UINT32)enIntType))>> (UINT32)enIntType);
}


