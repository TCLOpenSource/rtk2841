#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/syscore_ops.h>

#include <asm/smp_scu.h>
#include <asm/memory.h>

#include "smp.h"

static int lg115x_pm_suspend(void)
{
	return 0;
}

static void lg115x_pm_resume(void)
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

static struct syscore_ops lg115x_pm_syscore_ops = {
	.suspend        = lg115x_pm_suspend,
	.resume         = lg115x_pm_resume,
};

static __init int lg115x_pm_syscore_init(void)
{
	register_syscore_ops(&lg115x_pm_syscore_ops);
	return 0;
}
arch_initcall(lg115x_pm_syscore_init);

