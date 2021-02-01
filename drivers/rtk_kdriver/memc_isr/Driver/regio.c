/**
 * @file regio.c
 * @brief This file implements all memc exported api.
 * @date August.29.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par MEMC Library V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/

/*! include register db define */

#ifdef WIN32
#define DLL_IMPLEMENT
#endif

#include "memc_isr/Driver/regio.h"
#include "memc_isr/Common/kw_common.h"		///< common stdio define such as kw_printf etc
#include "memc_isr/Common/kw_debug.h"		///< debug support
#include "memc_isr/Driver/reg_offset.h"		///< register offset for different customer
//#include "drv_i2c.h"

#include "rtk_vgip_isr.h"
#include "io.h"

#ifdef WIN32
static ReadRegCallback gReadCallbackFunc = NULL;
static WriteRegCallback gWriteCallbackFunc = NULL;
#endif

static UINT32 gu32BaseOffset = BASE_OFFSET;

/**
 * @brief This function set Base Offset of Register R/W
 * @param [in] u32Offset
 * @retval FALSE
*/
VOID RegSetBaseOffset(UINT32 u32Offset)
{
	gu32BaseOffset = u32Offset;
}

/*! define register access api for use */

/* Invoke Sample:
Read named register: base: FRC_TOP Page: kmc_top Named register reg_top_patt_htotal

BOOL bRet = FASLE;
UINT32 uiVal = 0;
bRet = ReadRegister(KIWI_REG(FRC_TOP__kmc_top__reg_top_patt_htotal), &uiVal);

Write name register: base: FRC_TOP Page: kmc_top Named register reg_top_patt_htotal
BOOL bRet = FASLE;
UINT32 uiVal = 0x100;
bRet = WriteRegister(KIWI_REG(FRC_TOP__kmc_top__reg_top_patt_htotal), uiVal);
*/

/**
 * @brief This function read specified register and returns named register value, the value has been processed for specified named register.
 * @param uiAddr [in]		Named Register address, 32 bits
 * @param ibitStart [in]	Named Register start bit in register address
 * @param ibitEnd [in]		Named Register end bit in register address
 * @param puiVal [in/out]	Named Register value
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL ReadRegister(UINT32 uiAddr, SINT32 ibitStart, SINT32 ibitEnd, UINT32 *puiVal)
{
	BOOL bRet = TRUE;
	UINT32 u32Mask = 0xffffffff;

	if (ibitEnd < ibitStart)
	{
		return FALSE;
	}

	if((uiAddr % 4 == 0) && (ibitEnd - ibitStart == 31))
	{
		#ifdef WIN32
		if(gReadCallbackFunc != NULL)
		{
			bRet = gReadCallbackFunc(uiAddr, puiVal);
		}
		#else
			uiAddr += gu32BaseOffset;

#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT	//#ifdef RTK_MEMC
			*puiVal = rtd_inl(uiAddr);
#else
			*puiVal = *(UINT32*)uiAddr;
#endif
		#endif
		return bRet;
	}


#ifdef WIN32
	if(gReadCallbackFunc != NULL)
	{
		bRet = gReadCallbackFunc(uiAddr, puiVal);
	}
	//bRet = Drv_IIC_ReadDword(uiAddr, puiVal);
#else
	uiAddr += gu32BaseOffset;
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT	//#ifdef RTK_MEMC
	*puiVal = rtd_inl(uiAddr);
#else
	*puiVal = *(UINT32*)uiAddr;
#endif
#endif
	// get mask
	u32Mask = u32Mask << (31 - ibitEnd);
	u32Mask = u32Mask >> (31 - ibitEnd);
	u32Mask = u32Mask >> ibitStart;
	u32Mask = u32Mask << ibitStart;

	// set mask
	*puiVal &= u32Mask;
	*puiVal = *puiVal >> ibitStart;

	return bRet;
}

/**
 * @brief This function write specified register of named register value. The value must do not move bits.
 * @param uiAddr [in]		Named Register address, 32 bits
 * @param ibitStart [in]	Named Register start bit in register address
 * @param ibitEnd [in]		Named Register end bit in register address
 * @param uiVal [in]		Named Register value want to write
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL WriteRegister(UINT32 uiAddr, SINT32 ibitStart, SINT32 ibitEnd, UINT32 uiVal)
{
	BOOL bRet = TRUE;
	UINT32 u32Val = 0, u32Mask = 0xffffffff, u32SetValue = 0;

	if (ibitEnd < ibitStart)
	{
		return FALSE;
	}

	if((uiAddr % 4 == 0) && (ibitEnd - ibitStart == 31))
	{
		#ifdef WIN32
		if(gWriteCallbackFunc != NULL)
		{
			bRet = gWriteCallbackFunc(uiAddr, uiVal);
		}
		#else
			uiAddr += gu32BaseOffset;
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT	//#ifdef RTK_MEMC
			rtd_outl(uiAddr, uiVal);
#else
			*(UINT32*)uiAddr = uiVal;
#endif
		#endif

		return bRet;
	}

#ifdef WIN32
	if(gReadCallbackFunc != NULL)
	{
		bRet = gReadCallbackFunc(uiAddr, &u32Val);
	}
	//bRet = Drv_IIC_ReadDword(uiAddr, &u32Val);
#else
	uiAddr += gu32BaseOffset;
	//u32Val = *(UINT32*)uiAddr;//need to modify CSFC,20160906 
	u32Val = rtd_inl(uiAddr);
#endif
	u32SetValue = uiVal;

	// get mask
	u32Mask = u32Mask << (31 - ibitEnd);
	u32Mask = u32Mask >> (31 - ibitEnd);
	u32Mask = u32Mask >> ibitStart;

	// process uiset value to avoid uiset value has too many bits
	u32SetValue &= u32Mask;

	u32Mask = u32Mask << ibitStart;

	u32Mask = ~u32Mask;
	u32SetValue = u32SetValue << ibitStart;

	// set mask
	u32Val &= u32Mask;
	u32Val |= u32SetValue;

#ifdef WIN32
	if(gWriteCallbackFunc != NULL)
	{
		bRet = gWriteCallbackFunc(uiAddr, u32Val);
	}
	//bRet = Drv_IIC_WriteDword(uiAddr, u32Val);
#else
#ifdef CONFIG_RTK_KDEV_MEMC_INTERRUPT	//#ifdef RTK_MEMC
	rtd_outl(uiAddr, u32Val);
#else
	*(UINT32*)uiAddr = u32Val;
#endif
#endif
	return bRet;
}

/**
 * @brief rtk register read
 * @param uiAddr [in]		Named Register address, 32 bits
 * @param puiVal [in/out]	Named Register value
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL RTKReadRegister(UINT32 uiAddr, UINT32 *puiVal)
{
	*puiVal = rtd_inl(uiAddr);

	return TRUE;

}

/**
 * @brief rtk register write
 * @param uiAddr [in]		Named Register address, 32 bits
 * @param puiVal [in/out]	Named Register value
 * @retval TRUE 			indicates success
 * @retval FALSE			indicates fail.
*/
BOOL RTKWriteRegister(UINT32 uiAddr, UINT32 uiVal)
{
	rtd_outl(uiAddr, uiVal);

	return TRUE;
}

#ifdef WIN32
BOOL RegIOReadRegSetCallback(ReadRegCallback cb)
{
	gReadCallbackFunc = cb;
	return TRUE;
}

BOOL RegIOWriteRegSetCallback(WriteRegCallback cb)
{
	gWriteCallbackFunc = cb;
	return TRUE;
}

#endif
