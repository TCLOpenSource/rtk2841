#include <linux/kernel.h>

#include <linux/delay.h>
#include <linux/lg1k/pms.h>
#include <linux/memblock.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_fdt.h>
#include <linux/psci.h>

#include <asm/cacheflush.h>
#include <asm/cp15.h>
#include <asm/mach/map.h>
#include <asm/smp_plat.h>
#include <asm/smp_scu.h>
#include <asm/psci.h>

#include <mach/lg1k.h>

static int __init is_compatible(unsigned long node, char const *uname,
                                int depth, void *data)
{
	return of_flat_dt_is_compatible(node, data);
}

void __init lg1k_reserve_smp(void)
{
	if (PHYS_OFFSET)
		return;
	if (!of_scan_flat_dt(is_compatible, "lge,lg1156-pms") &&
	    !of_scan_flat_dt(is_compatible, "lge,lg1210-pms"))
		return;
	memblock_reserve(0x00000000, PAGE_SIZE);
}

static DEFINE_SPINLOCK(smp_boot_lock);

static void __iomem *smp_ctrl_base;

static int smp_get_boot_sync(void)
{
	return (int)readl_relaxed(smp_ctrl_base + REG(184));
}

static void smp_set_boot_sync(int sync)
{
	writel_relaxed((unsigned long)sync, smp_ctrl_base + REG(184));
}

static void __init lg1k_smp_init_cpus(void)
{
	struct device_node *np;
	unsigned int cpus = 0;
	unsigned int cpu;

	for_each_node_by_type(np, "cpu")
		cpus++;

	if (cpus > nr_cpu_ids) {
		pr_warn("SMP: %u cpus greater than maximum(%u), clipping\n",
		        cpus, nr_cpu_ids);
		cpus = nr_cpu_ids;
	}

	for (cpu = 0; cpu < cpus; cpu++)
		set_cpu_possible(cpu, true);
}

static void smp_prepare(void)
{
	extern void lg1k_smp_secondary_prepare(void __iomem *);
	extern void lg1k_smp_secondary_startup(void);

	struct device_node *np;
	void __iomem *base;

#ifdef	CONFIG_HAVE_ARM_SCU
	np = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-scu");
	if (np) {
		base = of_iomap(np, 0);
		scu_enable(base);
		iounmap(base);
	}
#endif	/* CONFIG_SMP_SCU */

	if (!psci_ops.cpu_on) {
		/* prepare for initial secondary boot */
		np = of_find_node_by_name(NULL, "core_ctrl");
		smp_ctrl_base = of_iomap(np, 0);
		writel_relaxed(virt_to_phys(lg1k_smp_secondary_startup),
			       smp_ctrl_base + REG(183));

		/* prepare for hotplug secondary boot */
		np = of_find_node_by_name(NULL, "zero_page");
		if (np) {
			base = of_iomap(np, 0);
			lg1k_smp_secondary_prepare(base);
			iounmap(base);
		}
	}
}

static void __init lg1k_smp_prepare_cpus(unsigned int max_cpus)
{
	extern void __init lg115x_init_pms(void);
	smp_prepare();
	lg115x_init_pms();
}

static void lg1k_smp_secondary_init(unsigned int cpu)
{
	smp_set_boot_sync(-1);
	spin_lock(&smp_boot_lock);
	spin_unlock(&smp_boot_lock);
}

static int smp_secondary_power_on(unsigned int cpu)
{
	/* power-on CPU if supported and powered-off */
	if (lg1k_pms_get_hotplug(cpu) == 0) {
		pr_notice("CPU%u: power-on\n", cpu);
		return lg1k_pms_set_hotplug(cpu, 1);
	}
	return 0;
}

static int lg1k_smp_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	unsigned long timeout;
	int err;

	err = smp_secondary_power_on(cpu);
	if (err < 0)
		return err;

	spin_lock(&smp_boot_lock);

	smp_set_boot_sync(cpu_logical_map(cpu));
	arch_send_wakeup_ipi_mask(cpumask_of(cpu));

	timeout = jiffies + HZ;
	while (time_before(jiffies, timeout)) {
		smp_rmb();
		if (smp_get_boot_sync() == -1)
			break;
		udelay(10);
	}

	spin_unlock(&smp_boot_lock);

	return smp_get_boot_sync() != -1 ? -ENOSYS : 0;
}

struct smp_call_info {
	unsigned int cpu;
	int err;
};

static void smp_psci_boot_secondary(void *param)
{
	extern void secondary_startup(void);
	struct smp_call_info *info = param;
	info->err = psci_ops.cpu_on(cpu_logical_map(info->cpu),
	                            virt_to_phys(secondary_startup));
}

static int
lg1k_smp_psci_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	struct smp_call_info info = { .cpu = cpu, };
	int err;

	err = smp_secondary_power_on(cpu);
	if (err < 0)
		return err;

	err = smp_call_function_single(0, smp_psci_boot_secondary, &info, 1);
	if (err < 0)
		return err;

	return info.err;
}

static int lg1k_smp_hotplug_cpu_kill(unsigned int cpu)
{
	/* power-off CPU only if supported and powered-on */
	if (lg1k_pms_get_hotplug(cpu) == 1) {
		pr_notice("CPU%u: power-off\n", cpu);
		return lg1k_pms_set_hotplug(cpu, 0) == 0;
	}
	return 1;
}

static void lg1k_smp_hotplug_v7_cpu_die(unsigned int cpu)
{
	unsigned int spurious = 0;
	unsigned int v;

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	bic	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	: "=&r"(v)
	: "Ir"(CR_C)
	);

	asm volatile(
	"	bl	v7_flush_dcache_louis\n"
	: /* no input(s) */
	: /* no output(s) */
	: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9", "sl", "fp", "lr"
	);

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 1\n"
	"	bic	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 1\n"
	: "=&r"(v)
	: "Ir"(0x40)
	);

	isb();
	dsb();

	while (1) {
		wfi();
		if (smp_get_boot_sync() == cpu_logical_map(cpu))
			break;
		spurious++;
	}

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 1\n"
	"	orr	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 1\n"
	: "=&r"(v)
	: "Ir"(0x40)
	);

	isb();
	dsb();

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	orr	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	: "=&r"(v)
	: "Ir"(CR_C)
	);

	if (spurious)
		pr_warn("CPU%u: %u spurious wakeup calls\n", cpu, spurious);
}

static void lg1k_smp_hotplug_v8_cpu_die(unsigned int cpu)
{
	unsigned int spurious = 0;
	unsigned int v[2];

	/*
	 * 1. Clear the appropriate System Control Register C bit,
	 *    data or unified cache enable, to prevent additional
	 *    data cache allocation.
	 */
	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	bic	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	: "=&r"(v[0])
	: "Ir"(CR_C)
	);

	/*
	 * 2. Disable L2 prefetches by writing a one to bit [38]
	 *    and zeros to bits [36:35, 33:32] of the CPU Extended
	 *    Control Register.
	 */
	asm volatile(
	"	mrrc	p15, 1, %0, %1, c15\n"
	"	bic	%1, %1, %2\n"
	"	orr	%1, %1, %3\n"
	"	mcrr	p15, 0, %0, %1, c15\n"
	: "=&r"(v[0]), "=&r"(v[1])
	: "Ir"(0x1b), "Ir"(0x40)
	);

	/*
	 * 3. Execute an ISB instruction to ensure the CPU Extended
	 *    Control Register write is complete.
	 */
	isb();

	/*
	 * 4. Execute a DSB instruction to ensure completion of any
	 *    prior prefetch requests.
	 */
	dsb();

	/*
	 * 5. Clean and invalidate all data from the L1 data cache.
	 *    The L2 duplicate Snoop Tag RAM for this core is now
	 *    empty. This prevents any new data cache snoops or data
	 *    cache maintenance operations from other processors in
	 *    the processor being issued to this core.
	 */
	asm volatile(
	"	bl	v7_flush_dcache_louis\n"
	: /* no input(s) */
	: /* no output(s) */
	: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9", "sl", "fp", "lr"
	);

	/*
	 * 6. Clear the CPUECTLR.SMPEN bit. Clearing the SMPEN bit
	 *    enables the core to be taken out of coherency by
	 *    preventing the core from receiving instruction cache,
	 *    TLB, or BTB maintenance opertions broadcast by other
	 *    processors in the multiprocessor.
	 */
	asm volatile(
	"	mrrc	p15, 1, %0, %1, c15\n"
	"	bic	%0, %0, %2\n"
	"	mcrr	p15, 1, %0, %1, c15\n"
	: "=&r"(v[0]), "=&r"(v[1])
	: "Ir"(0x40)
	);

	/*
	 * 7. Ensure that the system does not send interrupts to the
	 *    core that is being powered down.
	 */

	/*
	 * 8. Set the DBGOSDLR.DLK, Double lock control bit, that
	 * forces the debug interfaces to be quiescent.
	 */
	asm volatile(
	"	mrc	p14, 0, %0, c1, c3, 4\n"
	"	orr	%0, %0, %1\n"
	"	mcr	p14, 0, %0, c1, c3, 4\n"
	: "=&r"(v[0])
	: "Ir"(0x01)
	);

	/*
	 * 9. Execute an ISB instruction to ensure that all the
	 * System register changes from the previous steps have
	 * been committed.
	 */
	isb();

	/*
	 * 10. Execute a DSB instruction to ensure that all instruction
	 *     cache, TLB, and branch predictor maintenance operations
	 *     issued by any core in the processor before the SMPEN bit
	 *     was cleared have completed.
	 */
	dsb();

	/*
	 * 11. Execute a WFI instruction and wait until the STANDBYWFI
	 *     output asserts to indicate that the core is idle and in
	 *     the WFI low-power state.
	 */
	while (1) {
		wfi();
		if (smp_get_boot_sync() == cpu_logical_map(cpu))
			break;
		spurious++;
	}

	asm volatile(
	"	mrc	p14, 0, %0, c1, c3, 4\n"
	"	bic	%0, %0, %1\n"
	"	mcr	p14, 0, %0, c1, c3, 4\n"
	: "=&r"(v[0])
	: "Ir"(0x01)
	);

	asm volatile(
	"	mrrc	p15, 1, %0, %1, c15\n"
	"	orr	%0, %0, %2\n"
	"	mcrr	p15, 1, %0, %1, c15\n"
	: "=&r"(v[0]), "=&r"(v[1])
	: "Ir"(0x40)
	);

	asm volatile(
	"	mrrc	p15, 1, %0, %1, c15\n"
	"	orr	%1, %1, %2\n"
	"	bic	%1, %1, %3\n"
	"	mcrr	p15, 0, %0, %1, c15\n"
	: "=&r"(v[0]), "=&r"(v[1])
	: "Ir"(0x1b), "Ir"(0x40)
	);

	isb();
	dsb();

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	orr	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	: "=&r"(v[0])
	: "Ir"(CR_C)
	);

	if (spurious)
		pr_warn("CPU%u: %u spurious wakeup calls\n", cpu, spurious);
}

static struct of_device_id lg1k_smp_matches[] __initdata = {
	{
		.compatible	= "arm,cortex-a9",
		.data		= lg1k_smp_hotplug_v7_cpu_die,
	}, {
		.compatible	= "arm,cortex-a15",
		.data		= lg1k_smp_hotplug_v7_cpu_die,
	}, {
		.compatible	= "arm,cortex-a57",
		.data		= lg1k_smp_hotplug_v8_cpu_die,
	}, {
		.compatible	= "arm,cortex-a53",
		.data		= lg1k_smp_hotplug_v8_cpu_die,
	}, {
		/* sentinel */
	},
};

static struct smp_operations lg1k_smp_ops __initdata = {
	.smp_init_cpus		= lg1k_smp_init_cpus,
	.smp_prepare_cpus	= lg1k_smp_prepare_cpus,
	.cpu_kill		= lg1k_smp_hotplug_cpu_kill,
};

static bool __init lg1k_psci_fully_available(void)
{
	/* Are cpu_on, cpu_off, cpu_suspend  available? */
	return (psci_ops.cpu_off != NULL &&
		psci_ops.cpu_on != NULL &&
		psci_ops.cpu_suspend != NULL);
}

bool __init lg1k_smp_init_ops(void)
{
	struct device_node *dn;
	struct of_device_id const *id;

	if (lg1k_psci_fully_available())
		return false;

	if (psci_smp_available()) {
		lg1k_smp_ops.smp_boot_secondary	= lg1k_smp_psci_boot_secondary;
	} else {
		lg1k_smp_ops.smp_secondary_init	= lg1k_smp_secondary_init;
		lg1k_smp_ops.smp_boot_secondary	= lg1k_smp_boot_secondary;
	}

	for_each_matching_node_and_match(dn, lg1k_smp_matches, &id) {
		lg1k_smp_ops.cpu_die = id->data;
		break;
	}

	if (!id) {
		pr_warn("%s: couldn't find a matching cpu_die\n", __func__);
		pr_warn("%s: fall-back to ARMv7-type function\n", __func__);
		lg1k_smp_ops.cpu_die = lg1k_smp_hotplug_v7_cpu_die;
	}

	smp_set_ops(&lg1k_smp_ops);

	return true;
}

void lg1k_smp_resume(void)
{
	extern void lg115x_pms_resume(void);
	smp_prepare();
	lg115x_pms_resume();
}
