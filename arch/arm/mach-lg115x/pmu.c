#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/platform_device.h>

#include <asm/pmu.h>

#include <mach/resource.h>

#include "pmu.h"

static struct resource pmu_res[] = {
	DEFINE_RES_IRQ_NAMED(PMU0_IRQ, "pmu@cpu0-irq"),
	DEFINE_RES_IRQ_NAMED(PMU1_IRQ, "pmu@cpu1-irq"),
};

static struct platform_device pmu_dev = {
	.name		= "arm-pmu",
	.id		= ARM_PMU_DEVICE_CPU,
	.num_resources	= ARRAY_SIZE(pmu_res),
	.resource	= pmu_res,
};

void __init lg115x_init_pmu(void)
{
	platform_device_register(&pmu_dev);
}
