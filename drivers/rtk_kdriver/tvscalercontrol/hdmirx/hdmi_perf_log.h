
/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2004 *
 * All rights reserved.                                       *
 *============================================================*/

#ifndef _HDMI_PERF_LOG_H_
#define _HDMI_PERF_LOG_H_

#include <linux/kernel.h>
#include <mach/io.h>
#include <rbus/timer_reg.h>
#include "hdmi_debug.h"


#if 0   // please enable it to enable time profiling

static unsigned int start_time = 0;

#define GET_SCPU_CLK_TIME() (rtd_inl(TIMER_SCPU_CLK90K_LO_reg) / 90)
#define LOG_SCPU_TIME_SUB(func, end, start) \
{\
	HDMI_EMG("[- PERF_LOG] region of profile %s time = %d ms\n", func, end - start); \
}

#define hdmi_time_mesaure_start()   do { start_time = GET_SCPU_CLK_TIME(); } while(0)
#define hdmi_time_mesaure_stop()    LOG_SCPU_TIME_SUB(__func__, GET_SCPU_CLK_TIME(), start_time)

#else

// no timing profiling enabled
#define hdmi_time_mesaure_start() 
#define hdmi_time_mesaure_stop() 

#endif

#endif // _HDMI_PERF_LOG_H_
