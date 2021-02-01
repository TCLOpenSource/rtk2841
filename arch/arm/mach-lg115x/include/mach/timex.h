#ifndef __MACH_TIMEX_H
#define __MACH_TIMEX_H

/* AMBA bus clock frequency */
#define AMBA_CLOCK_MHZ	CONFIG_AMBA_CLOCK_MHZ
#define AMBA_CLOCK	(AMBA_CLOCK_MHZ * 1000000)

#define CLOCK_TICK_RATE	AMBA_CLOCK

#if defined(CONFIG_LOCAL_TIMERS) && !defined(CONFIG_CLOCK_DETECTION)

/* MPcore peripheral clock frequency */
#define PERI_CLOCK_MHZ	CONFIG_PERI_CLOCK_MHZ
#define PERI_CLOCK	(PERI_CLOCK_MHZ * 1000000)

#endif

#endif
