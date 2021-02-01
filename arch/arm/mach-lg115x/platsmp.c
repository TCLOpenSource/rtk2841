#include <linux/kernel.h>

#include <linux/cpumask.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/sched.h>
#include <linux/spinlock.h>

#include <asm/cacheflush.h>
#include <asm/outercache.h>
#include <asm/param.h>
#include <asm/smp.h>
#include <asm/smp_plat.h>
#include <asm/smp_scu.h>
#include <asm/system.h>

#include <mach/resource.h>

#include "smp.h"

#ifndef CONFIG_MACH_LG1156
void __iomem *scu_base_addr(void)
{
        return (void __iomem *)(MMIO_P2V(MPCORE_SCU_BASE));
}
#endif

/*
 * Write pen_release in a way that is guaranteed to be visible to all
 * observers, irrespective of whether they're taking part in coherency
 * or not.  This is necessary for the hotplug code to work reliably.
 */
static void __cpuinit write_pen_release(int val)
{
	pen_release = val;
	smp_wmb();
	__cpuc_flush_dcache_area((void *)&pen_release, sizeof(pen_release));
	outer_clean_range(__pa(&pen_release), __pa(&pen_release + 1));
}

static DEFINE_SPINLOCK(boot_lock);

void __cpuinit lg115x_secondary_init(unsigned int cpu)
{
	/*
	 * let the primary processor know we're out of the
	 * pen, then head off into the C entry point
	 */
	write_pen_release(-1);

	/*
	 * Synchronise with the boot thread.
	 */
	spin_lock(&boot_lock);
	spin_unlock(&boot_lock);
}

int __cpuinit lg115x_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	unsigned long timeout;

	/*
	 * Set synchronisation state between this boot processor
	 * and the secondary one
	 */
	spin_lock(&boot_lock);

	/*
	 * This is really belt and braces; we hold unintended secondary
	 * CPUs in the holding pen until we're ready for them. However,
	 * since we haven't sent them a soft interrupt, they shouldn't
	 * be there.
	 */
	write_pen_release(cpu_logical_map(cpu));

	/*
	 * Send the secondary CPU a soft interrupt, thereby causing
	 * the boot monitor to read the system wide flags register,
	 * and branch to the address found there.
	 */
	arch_send_wakeup_ipi_mask(cpumask_of(cpu)); 
	timeout = jiffies + (1 * HZ);
	while (time_before(jiffies, timeout)) {
		smp_rmb();
		if (pen_release == -1)
			break;

		udelay(10);
	}

	/*
	 * now the secondary core is starting up let it run its
	 * calibrations, then wait for it to finish
	 */
	spin_unlock(&boot_lock);

	return pen_release != -1 ? -ENOSYS : 0;
}

/*
 * Initialise the CPU possible map early - this describes the CPUs
 * which may be present or become present in the system.
 */
static void __init lg115x_smp_init_cpus(void)
{
#ifndef CONFIG_MACH_LG1156
	unsigned int i, ncores = scu_get_core_count(scu_base_addr());
#else
	unsigned int i, ncores = CONFIG_NR_CPUS;
#endif

	if (ncores > nr_cpu_ids) {
		pr_warn("SMP: %u cores greater than maximum (%u), clipping\n",
			ncores, nr_cpu_ids);
		ncores = nr_cpu_ids;
	}

	for (i = 0; i < ncores; i++)
		set_cpu_possible(i, true);
}

void __init lg115x_smp_prepare_cpus(unsigned int max_cpus)
{
	/*
	 * Initialise the present map, which describes the set of CPUs
	 * actually populated at the present time.
	 */
#ifndef CONFIG_MACH_LG1156
	scu_enable(scu_base_addr());
#endif

	/*
	 * Write the address of secondary startup into the
	 * system-wide flags register. The boot monitor waits
	 * until it receives a soft interrupt, and then the
	 * secondary CPU branches to this address.
	 */
	lg115x_flags_set(virt_to_phys(lg115x_secondary_startup));
}

struct smp_operations lg115x_smp_ops __initdata = {
	.smp_init_cpus		= lg115x_smp_init_cpus,
	.smp_prepare_cpus	= lg115x_smp_prepare_cpus,
	.smp_secondary_init	= lg115x_secondary_init,
	.smp_boot_secondary	= lg115x_boot_secondary,
#ifdef CONFIG_HOTPLUG_CPU
	.cpu_die		= lg115x_cpu_die
#endif
};
