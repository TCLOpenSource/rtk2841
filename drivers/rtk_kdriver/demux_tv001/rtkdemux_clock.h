#ifndef RTKDEMUX_CLOCK_H
#define RTKDEMUX_CLOCK_H

#include <linux/kernel.h>
#include <linux/types.h>
#include "rtkdemux_refclk.h"

#if !defined(DEMUX_CLOCKS_PER_SEC) && !defined(DEMUX_CLOCKS_PER_MS)
	#define DEMUX_CLOCKS_PER_SEC (90000)
	#define DEMUX_CLOCKS_PER_MS  (90)
#endif

int64_t CLOCK_GetPTS(void);
int64_t CLOCK_GetTPPTS(int clock_enum);
int64_t CLOCK_GetAVSyncPTS(REFCLOCK *pRefClock);

#endif /* RTKDEMUX_CLOCK_H */
