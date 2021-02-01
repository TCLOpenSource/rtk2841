/**
 * @file mid_dm.c
 * @brief This file is for DM controller.
 * @date Nov.19.2014
 * @version V0.0.1
 * @author Martin Yan
 * @par Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

#include "memc_isr/Common/kw_common.h"
#include "memc_isr/Common/kw_debug.h"
#include "memc_isr/Common/memc_type.h"
#include "memc_isr/MID/mid_mode.h"
#include "memc_isr/HAL/hal_dm.h"

/**
 * @brief This function set kme start address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEStartAddress(ME_DM_ADDRESS_ST *pMEDMAddr)
{
	HAL_DM_SetKme00StartAddress0(pMEDMAddr->stBuf_00_0.u32StartAddress);
	HAL_DM_SetKme00StartAddress1(pMEDMAddr->stBuf_00_1.u32StartAddress);
	HAL_DM_SetKme00StartAddress2(pMEDMAddr->stBuf_00_2.u32StartAddress);
	HAL_DM_SetKme00StartAddress3(pMEDMAddr->stBuf_00_3.u32StartAddress);
	HAL_DM_SetKme00StartAddress4(pMEDMAddr->stBuf_00_4.u32StartAddress);
	HAL_DM_SetKme00StartAddress5(pMEDMAddr->stBuf_00_5.u32StartAddress);

	HAL_DM_SetKme08StartAddress0(pMEDMAddr->stBuf_08_0.u32StartAddress);
	HAL_DM_SetKme08StartAddress1(pMEDMAddr->stBuf_08_1.u32StartAddress);

	HAL_DM_SetKme10StartAddress0(pMEDMAddr->stBuf_10_0.u32StartAddress);
	HAL_DM_SetKme10StartAddress1(pMEDMAddr->stBuf_10_1.u32StartAddress);

	HAL_DM_SetKme12StartAddress0(pMEDMAddr->stBuf_12_0.u32StartAddress);
	HAL_DM_SetKme12StartAddress1(pMEDMAddr->stBuf_12_1.u32StartAddress);

	HAL_DM_SetKme14StartAddress0(pMEDMAddr->stBuf_14_0.u32StartAddress);
	HAL_DM_SetKme14StartAddress1(pMEDMAddr->stBuf_14_1.u32StartAddress);
}

/**
 * @brief This function set kme end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEEndAddress(ME_DM_ADDRESS_ST *pMEDMAddr)
{
	UINT32 u32MEVSize = Mid_Mode_Get_MEVSize();

	pMEDMAddr->stBuf_00_0.u32EndAddress = pMEDMAddr->stBuf_00_0.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_00_1.u32EndAddress = pMEDMAddr->stBuf_00_1.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_00_2.u32EndAddress = pMEDMAddr->stBuf_00_2.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_00_3.u32EndAddress = pMEDMAddr->stBuf_00_3.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_00_4.u32EndAddress = pMEDMAddr->stBuf_00_4.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_00_5.u32EndAddress = pMEDMAddr->stBuf_00_5.u32StartAddress + pMEDMAddr->u32Buf_00_LineOffset * u32MEVSize;
	pMEDMAddr->stBuf_12_0.u32EndAddress = pMEDMAddr->stBuf_12_0.u32StartAddress + pMEDMAddr->u32Buf_12_LineOffset * u32MEVSize;

	HAL_DM_SetKme00EndAddress0(pMEDMAddr->stBuf_00_0.u32EndAddress);
	HAL_DM_SetKme00EndAddress1(pMEDMAddr->stBuf_00_1.u32EndAddress);
	HAL_DM_SetKme00EndAddress2(pMEDMAddr->stBuf_00_2.u32EndAddress);
	HAL_DM_SetKme00EndAddress3(pMEDMAddr->stBuf_00_3.u32EndAddress);
	HAL_DM_SetKme00EndAddress4(pMEDMAddr->stBuf_00_4.u32EndAddress);
	HAL_DM_SetKme00EndAddress5(pMEDMAddr->stBuf_00_5.u32EndAddress);

	HAL_DM_SetKme12EndAddress0(pMEDMAddr->stBuf_12_0.u32EndAddress);
	HAL_DM_SetKme12EndAddress1(pMEDMAddr->stBuf_12_0.u32EndAddress);
}

/**
 * @brief This function set kme buffer offset address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMEOffsetAddress(ME_DM_ADDRESS_ST *pMEDMAddr)
{
	HAL_DM_SetKme00LineOffsetAddress(pMEDMAddr->u32Buf_00_LineOffset);
	HAL_DM_SetKme00LROffsetAddress(pMEDMAddr->u32Buf_00_LROffset);
	HAL_DM_SetKme08LineOffsetAddress(pMEDMAddr->u32Buf_08_LineOffset);
	HAL_DM_SetKme10LineOffsetAddress(pMEDMAddr->u32Buf_10_LineOffset);
	HAL_DM_SetKme12LineOffsetAddress(pMEDMAddr->u32Buf_12_LineOffset);
	HAL_DM_SetKme14LineOffsetAddress(pMEDMAddr->u32Buf_14_LineOffset);
}

/**
 * @brief This function set kmv start address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVStartAddress(MV_DM_ADDRESS_ST *pMVDMAddr)
{
	HAL_DM_SetKmv01StartAddress0(pMVDMAddr->stBuf_01_0.u32StartAddress);
	HAL_DM_SetKmv02StartAddress0(pMVDMAddr->stBuf_02_0.u32StartAddress);
	HAL_DM_SetKmv04StartAddress0(pMVDMAddr->stBuf_04_0.u32StartAddress);
	HAL_DM_SetKmv04StartAddress1(pMVDMAddr->stBuf_04_1.u32StartAddress);
	HAL_DM_SetKmv04StartAddress2(pMVDMAddr->stBuf_04_2.u32StartAddress);
	HAL_DM_SetKmv05StartAddress0(pMVDMAddr->stBuf_05_0.u32StartAddress);
	HAL_DM_SetKmv05StartAddress1(pMVDMAddr->stBuf_05_1.u32StartAddress);
	HAL_DM_SetKmv12StartAddress0(pMVDMAddr->stBuf_12_0.u32StartAddress);
	HAL_DM_SetKmv12StartAddress1(pMVDMAddr->stBuf_12_1.u32StartAddress);
	HAL_DM_SetKmv12StartAddress2(pMVDMAddr->stBuf_12_2.u32StartAddress);
	HAL_DM_SetKmv12StartAddress3(pMVDMAddr->stBuf_12_3.u32StartAddress);
	HAL_DM_SetKmv12StartAddress4(pMVDMAddr->stBuf_12_4.u32StartAddress);
	HAL_DM_SetKmv12StartAddress5(pMVDMAddr->stBuf_12_5.u32StartAddress);
	HAL_DM_SetKmv12StartAddress6(pMVDMAddr->stBuf_12_6.u32StartAddress);
	HAL_DM_SetKmv12StartAddress7(pMVDMAddr->stBuf_12_7.u32StartAddress);
}

/**
 * @brief This function set kme end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVEndAddress(MV_DM_ADDRESS_ST *pMVDMAddr)
{
	UINT32 u32MERowNum = Mid_Mode_Get_MERowNum();
	UINT32 u32ME2RowNum = Mid_Mode_Get_ME2RowNum();
	UINT32 u32ME2VSize = Mid_Mode_Get_ME2VSize();

	pMVDMAddr->stBuf_01_0.u32EndAddress = pMVDMAddr->stBuf_01_0.u32StartAddress + pMVDMAddr->u32Buf_01_LineOffset * u32ME2RowNum;
	pMVDMAddr->stBuf_02_0.u32EndAddress = pMVDMAddr->stBuf_02_0.u32StartAddress + pMVDMAddr->u32Buf_02_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_04_0.u32EndAddress = pMVDMAddr->stBuf_04_0.u32StartAddress + pMVDMAddr->u32Buf_04_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_04_1.u32EndAddress = pMVDMAddr->stBuf_04_1.u32StartAddress + pMVDMAddr->u32Buf_04_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_04_2.u32EndAddress = pMVDMAddr->stBuf_04_2.u32StartAddress + pMVDMAddr->u32Buf_04_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_05_0.u32EndAddress = pMVDMAddr->stBuf_05_0.u32StartAddress + pMVDMAddr->u32Buf_05_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_05_1.u32EndAddress = pMVDMAddr->stBuf_05_1.u32StartAddress + pMVDMAddr->u32Buf_05_LineOffset * u32MERowNum;
	pMVDMAddr->stBuf_12_0.u32EndAddress = pMVDMAddr->stBuf_12_0.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_1.u32EndAddress = pMVDMAddr->stBuf_12_1.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_2.u32EndAddress = pMVDMAddr->stBuf_12_2.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_3.u32EndAddress = pMVDMAddr->stBuf_12_3.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_4.u32EndAddress = pMVDMAddr->stBuf_12_4.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_5.u32EndAddress = pMVDMAddr->stBuf_12_5.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_6.u32EndAddress = pMVDMAddr->stBuf_12_6.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;
	pMVDMAddr->stBuf_12_7.u32EndAddress = pMVDMAddr->stBuf_12_7.u32StartAddress + pMVDMAddr->u32Buf_12_LineOffset * u32ME2VSize;

	HAL_DM_SetKmv01EndAddress0(pMVDMAddr->stBuf_01_0.u32EndAddress);
	HAL_DM_SetKmv02EndAddress0(pMVDMAddr->stBuf_02_0.u32EndAddress);
	HAL_DM_SetKmv04EndAddress0(pMVDMAddr->stBuf_04_0.u32EndAddress);
	HAL_DM_SetKmv04EndAddress1(pMVDMAddr->stBuf_04_1.u32EndAddress);
	HAL_DM_SetKmv04EndAddress2(pMVDMAddr->stBuf_04_2.u32EndAddress);
	HAL_DM_SetKmv05EndAddress0(pMVDMAddr->stBuf_05_0.u32EndAddress);
	HAL_DM_SetKmv05EndAddress1(pMVDMAddr->stBuf_05_1.u32EndAddress);
	HAL_DM_SetKmv12EndAddress0(pMVDMAddr->stBuf_12_0.u32EndAddress);
	HAL_DM_SetKmv12EndAddress1(pMVDMAddr->stBuf_12_1.u32EndAddress);
	HAL_DM_SetKmv12EndAddress2(pMVDMAddr->stBuf_12_2.u32EndAddress);
	HAL_DM_SetKmv12EndAddress3(pMVDMAddr->stBuf_12_3.u32EndAddress);
	HAL_DM_SetKmv12EndAddress4(pMVDMAddr->stBuf_12_4.u32EndAddress);
	HAL_DM_SetKmv12EndAddress5(pMVDMAddr->stBuf_12_5.u32EndAddress);
	HAL_DM_SetKmv12EndAddress6(pMVDMAddr->stBuf_12_6.u32EndAddress);
	HAL_DM_SetKmv12EndAddress7(pMVDMAddr->stBuf_12_7.u32EndAddress);
}

/**
 * @brief This function set kmv buffer offset address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMVOffsetAddress(MV_DM_ADDRESS_ST *pMVDMAddr)
{
	HAL_DM_SetKmv01LineOffsetAddress(pMVDMAddr->u32Buf_01_LineOffset);
	HAL_DM_SetKmv01LROffsetAddress(pMVDMAddr->u32Buf_01_LROffset);
	HAL_DM_SetKmv02LineOffsetAddress(pMVDMAddr->u32Buf_02_LineOffset);
	HAL_DM_SetKmv02LROffsetAddress(pMVDMAddr->u32Buf_02_LROffset);
	HAL_DM_SetKmv04LineOffsetAddress(pMVDMAddr->u32Buf_04_LineOffset);
	HAL_DM_SetKmv04LROffsetAddress(pMVDMAddr->u32Buf_04_LROffset);
	HAL_DM_SetKmv05LineOffsetAddress(pMVDMAddr->u32Buf_05_LineOffset);
	HAL_DM_SetKmv05LROffsetAddress(pMVDMAddr->u32Buf_05_LROffset);
	HAL_DM_SetKmv12LineOffsetAddress(pMVDMAddr->u32Buf_12_LineOffset);
	HAL_DM_SetKmv12LROffsetAddress(pMVDMAddr->u32Buf_12_LROffset);
}

/**
 * @brief This function set kmc end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMCStartAddress(MC_DM_ADDRESS_ST *pMCDMAddr)
{
	HAL_DM_SetKmc00StartAddress0(pMCDMAddr->stBuf_HF_0.u32StartAddress);
	HAL_DM_SetKmc00StartAddress1(pMCDMAddr->stBuf_HF_1.u32StartAddress);
	HAL_DM_SetKmc00StartAddress2(pMCDMAddr->stBuf_HF_2.u32StartAddress);
	HAL_DM_SetKmc00StartAddress3(pMCDMAddr->stBuf_HF_3.u32StartAddress);
	HAL_DM_SetKmc00StartAddress4(pMCDMAddr->stBuf_HF_4.u32StartAddress);
	HAL_DM_SetKmc00StartAddress5(pMCDMAddr->stBuf_HF_5.u32StartAddress);
	HAL_DM_SetKmc00StartAddress6(pMCDMAddr->stBuf_HF_6.u32StartAddress);
	HAL_DM_SetKmc00StartAddress7(pMCDMAddr->stBuf_HF_7.u32StartAddress);

	HAL_DM_SetKmc01StartAddress0(pMCDMAddr->stBuf_LF_0.u32StartAddress);
	HAL_DM_SetKmc01StartAddress1(pMCDMAddr->stBuf_LF_1.u32StartAddress);
	HAL_DM_SetKmc01StartAddress2(pMCDMAddr->stBuf_LF_2.u32StartAddress);
	HAL_DM_SetKmc01StartAddress3(pMCDMAddr->stBuf_LF_3.u32StartAddress);
	HAL_DM_SetKmc01StartAddress4(pMCDMAddr->stBuf_LF_4.u32StartAddress);
	HAL_DM_SetKmc01StartAddress5(pMCDMAddr->stBuf_LF_5.u32StartAddress);
	HAL_DM_SetKmc01StartAddress6(pMCDMAddr->stBuf_LF_6.u32StartAddress);
	HAL_DM_SetKmc01StartAddress7(pMCDMAddr->stBuf_LF_7.u32StartAddress);
}

/**
 * @brief This function set kmc end address
 * @param [in] VOID
 * @retval VOID
*/
VOID Mid_DM_SetKMCEndAddress(MC_DM_ADDRESS_ST *pMCDMAddr)
{
	UINT32 u32FRC_Vact = Mid_Mode_Get_ME_Vact();

	pMCDMAddr->stBuf_HF_0.u32EndAddress = pMCDMAddr->stBuf_HF_0.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_1.u32EndAddress = pMCDMAddr->stBuf_HF_1.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_2.u32EndAddress = pMCDMAddr->stBuf_HF_2.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_3.u32EndAddress = pMCDMAddr->stBuf_HF_3.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_4.u32EndAddress = pMCDMAddr->stBuf_HF_4.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_5.u32EndAddress = pMCDMAddr->stBuf_HF_5.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_6.u32EndAddress = pMCDMAddr->stBuf_HF_6.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_HF_7.u32EndAddress = pMCDMAddr->stBuf_HF_7.u32StartAddress + HAL_DM_GetKmc00LineOffsetAddress() * u32FRC_Vact / 2;

	HAL_DM_SetKmc00EndAddress0(pMCDMAddr->stBuf_HF_0.u32EndAddress);
	HAL_DM_SetKmc00EndAddress1(pMCDMAddr->stBuf_HF_1.u32EndAddress);
	HAL_DM_SetKmc00EndAddress2(pMCDMAddr->stBuf_HF_2.u32EndAddress);
	HAL_DM_SetKmc00EndAddress3(pMCDMAddr->stBuf_HF_3.u32EndAddress);
	HAL_DM_SetKmc00EndAddress4(pMCDMAddr->stBuf_HF_4.u32EndAddress);
	HAL_DM_SetKmc00EndAddress5(pMCDMAddr->stBuf_HF_5.u32EndAddress);
	HAL_DM_SetKmc00EndAddress6(pMCDMAddr->stBuf_HF_6.u32EndAddress);
	HAL_DM_SetKmc00EndAddress7(pMCDMAddr->stBuf_HF_7.u32EndAddress);

	pMCDMAddr->stBuf_LF_0.u32EndAddress = pMCDMAddr->stBuf_LF_0.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_1.u32EndAddress = pMCDMAddr->stBuf_LF_1.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_2.u32EndAddress = pMCDMAddr->stBuf_LF_2.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_3.u32EndAddress = pMCDMAddr->stBuf_LF_3.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_4.u32EndAddress = pMCDMAddr->stBuf_LF_4.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_5.u32EndAddress = pMCDMAddr->stBuf_LF_5.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_6.u32EndAddress = pMCDMAddr->stBuf_LF_6.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;
	pMCDMAddr->stBuf_LF_7.u32EndAddress = pMCDMAddr->stBuf_LF_7.u32StartAddress + HAL_DM_GetKmc01LineOffsetAddress() * u32FRC_Vact / 2;

	HAL_DM_SetKmc01EndAddress0(pMCDMAddr->stBuf_LF_0.u32EndAddress);
	HAL_DM_SetKmc01EndAddress1(pMCDMAddr->stBuf_LF_1.u32EndAddress);
	HAL_DM_SetKmc01EndAddress2(pMCDMAddr->stBuf_LF_2.u32EndAddress);
	HAL_DM_SetKmc01EndAddress3(pMCDMAddr->stBuf_LF_3.u32EndAddress);
	HAL_DM_SetKmc01EndAddress4(pMCDMAddr->stBuf_LF_4.u32EndAddress);
	HAL_DM_SetKmc01EndAddress5(pMCDMAddr->stBuf_LF_5.u32EndAddress);
	HAL_DM_SetKmc01EndAddress6(pMCDMAddr->stBuf_LF_6.u32EndAddress);
	HAL_DM_SetKmc01EndAddress7(pMCDMAddr->stBuf_LF_7.u32EndAddress);
}

/**
 * @brief This function set kmc offset address
 * @param [in] INOUT_MODE eMode
 * @retval VOID
*/
VOID Mid_DM_SetKMCOffsetAddress(UINT32 u32LineOffset, UINT32 u32LROffset)
{
	// KMC_00
	HAL_DM_SetKmc00LROffsetAddress(u32LROffset);
	HAL_DM_SetKmc00LineOffsetAddress(u32LineOffset);

	//KMC_01
	HAL_DM_SetKmc01LROffsetAddress(u32LROffset);
	HAL_DM_SetKmc01LineOffsetAddress(u32LineOffset);
}

/**
 * @brief This function set kmc engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMCEngineEnable(BOOL bEnable)
{
	HAL_DM_SetKmc00WriteEnable(bEnable);
	HAL_DM_SetKmc01WriteEnable(bEnable);
	HAL_DM_SetKmc04ReadEnable(bEnable);
	HAL_DM_SetKmc05ReadEnable(bEnable);
	HAL_DM_SetKmc06ReadEnable(bEnable);
	HAL_DM_SetKmc07ReadEnable(bEnable);
}

/**
 * @brief This function set kme engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMEEngineEnable(BOOL bEnable,  INOUT_MODE emom, INPUT_FORMAT emif, OUTPUT_FORMAT emof)
{
	if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
	{
		HAL_DM_SetKme00WriteEnable(bEnable);
		//HAL_DM_SetKme04WriteEnable(bEnable);
		//HAL_DM_SetKme05WriteEnable(bEnable);
	}
	else
	{
		HAL_DM_SetKme00WriteEnable(FALSE);
		//HAL_DM_SetKme04WriteEnable(FALSE);
		//HAL_DM_SetKme05WriteEnable(FALSE);
	}

	if((emif == INPUT_FORMAT_2D) && (emof == OUTPUT_FORMAT_2D))
	{
		if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
		{
			HAL_DM_SetKme08WriteEnable(bEnable);
			HAL_DM_SetKme10WriteEnable(bEnable);
			HAL_DM_SetKme12WriteEnable(bEnable);
			HAL_DM_SetKme14WriteEnable(bEnable);
		}
		else
		{
			HAL_DM_SetKme08WriteEnable(FALSE);
			HAL_DM_SetKme10WriteEnable(FALSE);
			HAL_DM_SetKme12WriteEnable(FALSE);
			HAL_DM_SetKme14WriteEnable(FALSE);
		}
	}
	else
	{
		HAL_DM_SetKme08WriteEnable(FALSE);
		HAL_DM_SetKme10WriteEnable(FALSE);
		HAL_DM_SetKme12WriteEnable(FALSE);
		HAL_DM_SetKme14WriteEnable(FALSE);
	}

	if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
	{
		HAL_DM_SetKme01ReadEnable(bEnable);
		HAL_DM_SetKme02ReadEnable(bEnable);
		HAL_DM_SetKme03ReadEnable(bEnable);
		//HAL_DM_SetKme06ReadEnable(bEnable);
		//HAL_DM_SetKme07ReadEnable(bEnable);
	}
	else
	{
		HAL_DM_SetKme01ReadEnable(FALSE);
		HAL_DM_SetKme02ReadEnable(FALSE);
		HAL_DM_SetKme03ReadEnable(FALSE);
		//HAL_DM_SetKme06ReadEnable(FALSE);
		//HAL_DM_SetKme07ReadEnable(FALSE);
	}

	if((emif == INPUT_FORMAT_2D) && (emof == OUTPUT_FORMAT_2D))
	{
		if((emom == RGB_IN_VIDEO_OUT) || (emom == YUV_IN_VIDEO_OUT))
		{
			HAL_DM_SetKme09ReadEnable(bEnable);
			HAL_DM_SetKme11ReadEnable(bEnable);
			HAL_DM_SetKme13ReadEnable(bEnable);
			HAL_DM_SetKme15ReadEnable(bEnable);
		}
		else
		{
			HAL_DM_SetKme09ReadEnable(FALSE);
			HAL_DM_SetKme11ReadEnable(FALSE);
			HAL_DM_SetKme13ReadEnable(FALSE);
			HAL_DM_SetKme15ReadEnable(FALSE);
		}
	}
	else
	{
		HAL_DM_SetKme09ReadEnable(FALSE);
		HAL_DM_SetKme11ReadEnable(FALSE);
		HAL_DM_SetKme13ReadEnable(FALSE);
		HAL_DM_SetKme15ReadEnable(FALSE);
	}
}

/**
 * @brief This function set kmv engine enable
 * @param [in] BOOL bEnable
 * @retval VOID
*/
VOID Mid_DM_SetKMVEngineEnable(BOOL bEnable)
{
	HAL_DM_SetKmv01WriteEnable(bEnable);
	HAL_DM_SetKmv02WriteEnable(bEnable);
	HAL_DM_SetKmv04WriteEnable(bEnable);
	HAL_DM_SetKmv05WriteEnable(bEnable);
	HAL_DM_SetKmv12WriteEnable(bEnable);

	HAL_DM_SetKmv03ReadEnable(bEnable);
	HAL_DM_SetKmv06ReadEnable(bEnable);
	HAL_DM_SetKmv07ReadEnable(bEnable);
	HAL_DM_SetKmv08ReadEnable(bEnable);
	HAL_DM_SetKmv09ReadEnable(bEnable);
	HAL_DM_SetKmv10ReadEnable(bEnable);
	HAL_DM_SetKmv11ReadEnable(bEnable);
}

