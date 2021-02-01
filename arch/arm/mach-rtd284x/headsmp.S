/*
 *  linux/arch/arm/bsp/mach/headsmp.S
 *
 *  Copyright (c) 2012 Realtek
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/linkage.h>
#include <linux/init.h>

#if !defined(CONFIG_QUICK_HIBERNATION) && !defined(CONFIG_SUSPEND)
	__INIT
#endif

/*
 * specific entry point for secondary CPUs.  This provides
 * a "holding pen" into which all secondary cores are held until we're
 * ready for them to initialise.
 */
ENTRY(rtk_secondary_startup)
	/* Turn on SMP bit for each core */
#if !defined(CONFIG_OPTEE) 
	mrrc  p15, 1, r0, r1, c15
	tst      r0, #(1 << 6)
	orreq r0, #(1 << 6)
	mcrreq   p15, 1, r0, r1, c15
#endif
#if 0 // TRM 4.3.64 (L2CTLR_EL1 is writeable. However, all writes to this register are ignored.)
	/* change L2 to W2R3 state */
	mrc p15, 1, r0, c9, c0, 2     @ Read current control reg
	orr r0, r0, #(0x0 << 9)       @ L2 tag  RAM setup
	orr r0, r0, #(0x1 << 5)       @ L2 data RAM setup
	orr r0, r0, #(0x2 << 0)       @ L2 data RAM latency
	mcr p15, 1, r0, c9, c0, 2     @ Write reg back
#endif

	b	secondary_startup
