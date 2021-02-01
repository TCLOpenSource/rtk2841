#ifndef __ARCH_LG115X_SMP_H
#define __ARCH_LG115X_SMP_H

#include <linux/init.h>

extern void lg115x_flags_set(unsigned long data);
extern void __cpuinit lg115x_secondary_startup(void);
extern void __ref lg115x_cpu_die(unsigned int cpu);
extern void __iomem *scu_base_addr(void);

extern struct smp_operations lg115x_smp_ops;

#endif	/* __ARCH_LG115X_SMP_H */
