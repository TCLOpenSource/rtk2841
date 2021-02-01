#ifndef __MACH_TIMEX_H
#define __MACH_TIMEX_H

/* AMBA bus clock frequency */
#define AMBA_CLOCK_MHZ	CONFIG_AMBA_CLOCK_MHZ
#define AMBA_CLOCK	(AMBA_CLOCK_MHZ * 1000000)

/* scheduled to be removed, but still required */
#define CLOCK_TICK_RATE	AMBA_CLOCK

#endif
