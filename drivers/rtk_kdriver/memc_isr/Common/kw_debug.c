/**
 * @file kw_debug.c
 * @brief This header file defines Real-Image debug trace to control all model debug info.
 * @date August.24.2014
 * @version V0.0.1
 * @author Lixiangjun
 * @par KW Debug trace V0.0.1 - Copyright (C) 2014 Real-Image Co. LTD
 * @par History:
 *			Version: 0.0.1
*/
#ifdef WIN32
#define DLL_IMPLEMENT
#endif

#include "memc_isr/include/kw_type.h"
#include "memc_isr/Common/kw_debug.h"

UINT32 u32DebugLevel = DBG_MSG;

VOID COM_SetDebugLevel(UINT32 u32Level)
{
	u32DebugLevel = u32Level;
}

UINT32 COM_GetDebugLevel(VOID)
{
	return u32DebugLevel;
}
#if defined(CONFIG_RTK_KDEV_MEMC_INTERRUPT)
int64_t MEMC_GetPTS(void)
{
	unsigned int lo = rtd_inl(TIMER_SCPU_CLK90K_LO_reg) ;
	unsigned int hi = rtd_inl(TIMER_SCPU_CLK90K_HI_reg) ;
	int64_t ret = lo | (((int64_t)hi) << 32) ;

	return ret ;
}
#endif
