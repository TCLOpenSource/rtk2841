#ifndef ASMARM_ARCH_SMP_H
#define ASMARM_ARCH_SMP_H


#if 0 // before 3.14
#include <linux/irqchip/arm-gic.h>

extern void gic_raise_softirq(const struct cpumask *mask, unsigned int irq);

/*
 * We use IRQ1 as the IPI
 */
static inline void smp_cross_call(const struct cpumask *mask, int ipi)
{
	gic_raise_softirq(mask, ipi);
}
#endif

#endif
