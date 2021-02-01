#include <asm/io.h>
#include "rtkdemux_clock.h"
#include <tp/tp_drv_global.h>
#include "rtkdemux_register.h"
#include <rbus/timer_reg.h>
#include <mach/system.h>
#include <rtk_kdriver/io.h>

unsigned int DEMUX_RegRead32 (unsigned int addr)
{
	return *(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) ;
}

void DEMUX_RegWrite32 (unsigned int addr, unsigned int value)
{
	(*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value) ;
}

int64_t CLOCK_GetPTS(void)
{
	unsigned int ptrlo = rtd_inl(TIMER_SCPU_CLK90K_LO_reg) ;
	unsigned int ptrhi = rtd_inl(TIMER_SCPU_CLK90K_HI_reg) ;
	int64_t ret = ptrlo | (((int64_t)ptrhi) << 32) ;

	return ret ;
}

int64_t CLOCK_GetTPPTS(int clock_enum)
{
	int64_t ret = -1;

	unsigned int ptrlo = 0;
	unsigned int ptrhi = 0;


	switch (clock_enum) {
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
	case TP_PCRA_LOCAL_90KHz:
		ptrlo = rtd_inl(TP_TP_PCRA_90K_CNT_reg);
		ptrhi = rtd_inl(TP_TP_PCRA_90K_CNT_HIGH_reg);
		break;
	case TP_PCRB_LOCAL_90KHz:
		ptrlo = rtd_inl(TP_TP_PCRB_90K_CNT_reg);
		ptrhi = rtd_inl(TP_TP_PCRB_90K_CNT_HIGH_reg);
		break;
#endif
	default:
	ptrlo = rtd_inl(TP_TP_PCRA_90K_CNT_reg);
	ptrhi = rtd_inl(TP_TP_PCRA_90K_CNT_HIGH_reg);
		break;
	}

	ret = ptrlo | (((int64_t)ptrhi) << 32);

	return ret;
}


int64_t CLOCK_GetAVSyncPTS(REFCLOCK *pRefClock)
{
	if (pRefClock) {
		if (REFCLK_GetClockMode(pRefClock) != MISC_90KHz)
			return CLOCK_GetTPPTS(REFCLK_GetClockMode(pRefClock));
	}
	return CLOCK_GetPTS();
}
