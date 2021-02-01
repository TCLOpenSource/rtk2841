#include <linux/kernel.h>

#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/clocksource.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/lg1k/clk.h>

#include <asm/hardware/arm_timer.h>
#include <asm/hardware/timer-sp.h>
#include <asm/sched_clock.h>
#include <asm/smp_twd.h>

#include <mach/resource.h>
#include <mach/timex.h>

#include "time.h"

static DEFINE_TWD_LOCAL_TIMER(twd, MPCORE_TWD_TIMER_BASE, MPCORE_TWD_TIMER_IRQ);

static void __init twd_init(void)
{
	twd_local_timer_register(&twd);
}

static void __init sp804_init_timer1(void __iomem *base)
{
	sp804_clockevents_init(base, TIMER_IRQ, "timer1");
}

#ifndef CONFIG_SP804_CLOCKSOURCE_PRESET

static void __init sp804_init_timer2(void __iomem *base)
{
	sp804_clocksource_and_sched_clock_init(base, "timer2");
}

#else	/* CONFIG_SP804_CLOCKSOURCE_PRESET */

#define SP804_CLOCKSOURCE_PRESET_MULT	CONFIG_SP804_CLOCKSOURCE_PRESET_MULT
#define SP804_CLOCKSOURCE_PRESET_SHIFT	CONFIG_SP804_CLOCKSOURCE_PRESET_SHIFT

static void __iomem *sched_clock_base;

static u32 sp804_read(void)
{
	return ~readl_relaxed(sched_clock_base + TIMER_VALUE);
}

static void __init sp804_init_timer2(void __iomem *base)
{
	/* setup timer2 as free-running clocksource */
	writel_relaxed(0, base + TIMER_CTRL);
	writel_relaxed(0xffffffff, base + TIMER_LOAD);
	writel_relaxed(0xffffffff, base + TIMER_VALUE);
	writel_relaxed(TIMER_CTRL_32BIT | TIMER_CTRL_ENABLE |
	               TIMER_CTRL_PERIODIC, base + TIMER_CTRL);

	clocksource_mmio_init_preset(base + TIMER_VALUE, "timer2",
	                             SP804_CLOCKSOURCE_PRESET_MULT,
	                             SP804_CLOCKSOURCE_PRESET_SHIFT,
	                             200, 32, clocksource_mmio_readl_down);

	sched_clock_base = base;
	setup_sched_clock(sp804_read, 32, AMBA_CLOCK);
}

#endif	/* CONFIG_SP804_CLOCKSOURCE_PRESET */

static void __init sp804_init(void)
{
	void __iomem *base;

	request_mem_region(TIMER_BASE, SZ_4K, "timers");
	base = ioremap(TIMER_BASE, SZ_4K);

	sp804_init_timer1(base + TIMER_1_BASE);
	sp804_init_timer2(base + TIMER_2_BASE);
}

static struct clk_lookup periph_clkdevs[] = {
	CLKDEV_INIT("smp_twd", NULL, NULL),
};

static struct clk_lookup bus_clkdevs[] = {
	CLKDEV_INIT(NULL, "hclk", NULL),
	CLKDEV_INIT(NULL, "pclk", NULL),
	CLKDEV_INIT("dmac", NULL, NULL),
	CLKDEV_INIT("sdhci-lg115x", NULL, NULL),
	CLKDEV_INIT("sp804", NULL, NULL),
	CLKDEV_INIT("spi0", NULL, NULL),
	CLKDEV_INIT("spi1", NULL, NULL),
	CLKDEV_INIT("uart0", NULL, NULL),
	CLKDEV_INIT("uart1", NULL, NULL),
	CLKDEV_INIT("uart2", NULL, NULL),
	CLKDEV_INIT("wdog", NULL, NULL),
};

void __init lg115x_init_time(void)
{
	void __iomem *base;
	struct clk *clk;

	base = ioremap(TOP_CTRL_BASE, SZ_4K);
	clk_lg1154_init(base);

	clk = __clk_lookup("PERIPHCLK");
	clk_register_clkdevs(clk, periph_clkdevs, ARRAY_SIZE(periph_clkdevs));

	clk = __clk_lookup("BUSCLK");
	clk_register_clkdevs(clk, bus_clkdevs, ARRAY_SIZE(bus_clkdevs));

	twd_init();
	sp804_init();
}
