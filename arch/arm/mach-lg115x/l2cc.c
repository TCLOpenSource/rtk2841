#include <linux/kernel.h>

#include <linux/init.h>

#include <asm/hardware/cache-l2x0.h>
#include <asm/io.h>
#include <asm/firmware.h>

#include <mach/resource.h>

#include "l2cc.h"
#include "smc.h"


void init_l2cc_pre(void)
{
	/*
	 * 1st-half for secure kernel: write desired control values
	 */
	if(call_firmware_op(l2x0_init) == -ENOSYS) {
		/* use reset value for the AUX_CTRL register */
		writel_relaxed(L2TLCTRL, MMIO_P2V(L2CC_BASE) + L2X0_TAG_LATENCY_CTRL);
		writel_relaxed(L2DLCTRL, MMIO_P2V(L2CC_BASE) + L2X0_DATA_LATENCY_CTRL);
		writel_relaxed(L2DBCTRL, MMIO_P2V(L2CC_BASE) + L2X0_DEBUG_CTRL);
		writel_relaxed(L2PFCTRL, MMIO_P2V(L2CC_BASE) + L2X0_PREFETCH_CTRL);
	}
}


static void l2cc_resume(void)
{
	init_l2cc_pre();
}

static void __init init_l2cc_post(void)
{
	/*
	 * 2nd-half for secure kernel: enable L2CC and register outer-cache
	 * 2nd-half for non-secure kernel: register outer-cache
	 */

	l2x0_init(MMIO_P2V(L2CC_BASE), 0x00, ~0x00);
}

void __init lg115x_init_l2cc(void)
{
	init_l2cc_pre();
	init_l2cc_post();

	outer_cache.resume = l2cc_resume;
}
