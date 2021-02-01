#ifndef __ARCH_LG115X_PMU_H
#define __ARCH_LG115X_PMU_H

#ifndef CONFIG_CPU_HAS_PMU

static inline void lg115x_init_pmu(void)
{
}

#else	/* CONFIG_CPU_HAS_PMU */

#include <linux/init.h>

extern void __init lg115x_init_pmu(void);

#endif	/* CONFIG_CPU_HAS_PMU */

#endif	/* __ARCH_LG115X_PMU_H */
