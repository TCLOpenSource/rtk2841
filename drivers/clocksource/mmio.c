/*
 * Generic MMIO clocksource support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/clocksource.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/slab.h>

struct clocksource_mmio {
	void __iomem *reg;
	struct clocksource clksrc;
};

static inline struct clocksource_mmio *to_mmio_clksrc(struct clocksource *c)
{
	return container_of(c, struct clocksource_mmio, clksrc);
}

cycle_t clocksource_mmio_readl_up(struct clocksource *c)
{
	return (cycle_t)readl_relaxed(to_mmio_clksrc(c)->reg);
}

cycle_t clocksource_mmio_readl_down(struct clocksource *c)
{
	return ~(cycle_t)readl_relaxed(to_mmio_clksrc(c)->reg) & c->mask;
}

cycle_t clocksource_mmio_readw_up(struct clocksource *c)
{
	return (cycle_t)readw_relaxed(to_mmio_clksrc(c)->reg);
}

cycle_t clocksource_mmio_readw_down(struct clocksource *c)
{
	return ~(cycle_t)readw_relaxed(to_mmio_clksrc(c)->reg) & c->mask;
}

/**
 * clocksource_mmio_init - Initialize a simple mmio based clocksource
 * @base:	Virtual address of the clock readout register
 * @name:	Name of the clocksource
 * @hz:		Frequency of the clocksource in Hz
 * @rating:	Rating of the clocksource
 * @bits:	Number of valid bits
 * @read:	One of clocksource_mmio_read*() above
 */
int __init clocksource_mmio_init(void __iomem *base, const char *name,
	unsigned long hz, int rating, unsigned bits,
	cycle_t (*read)(struct clocksource *))
{
	struct clocksource_mmio *cs;

	if (bits > 64 || bits < 16)
		return -EINVAL;

	cs = kzalloc(sizeof(struct clocksource_mmio), GFP_KERNEL);
	if (!cs)
		return -ENOMEM;

	cs->reg = base;
	cs->clksrc.name = name;
	cs->clksrc.rating = rating;
	cs->clksrc.read = read;
	cs->clksrc.mask = CLOCKSOURCE_MASK(bits);
	cs->clksrc.flags = CLOCK_SOURCE_IS_CONTINUOUS;

	return clocksource_register_hz(&cs->clksrc, hz);
}

/**
 * clocksource_mmio_init_preset - Initialize using preset mult/shift
 * @base:	Virtual address of the clock readout register
 * @name:	Name of the clocksource
 * @mult:	Preset multiplier
 * @shift:	Preset shifter
 * @rating:	Rating of the clocksource
 * @bits:	Number of valid bits
 * @read:	One of clocksource_mmio_read*() above
 */
int __init clocksource_mmio_init_preset(void __iomem *base, const char *name,
	unsigned int mult, unsigned int shift, int rating, unsigned bits,
	cycle_t (*read)(struct clocksource *))
{
	struct clocksource_mmio *cs;

	if (bits > 32 || bits < 16)
		return -EINVAL;

	cs = kzalloc(sizeof(struct clocksource_mmio), GFP_KERNEL);
	if (!cs)
		return -ENOMEM;

	cs->reg = base;
	cs->clksrc.name = name;
	cs->clksrc.rating = rating;
	cs->clksrc.read = read;
	cs->clksrc.mask = CLOCKSOURCE_MASK(bits);
	cs->clksrc.mult = mult;
	cs->clksrc.shift = shift;
	cs->clksrc.flags = CLOCK_SOURCE_IS_CONTINUOUS;

	return __clocksource_register(&cs->clksrc);
}
