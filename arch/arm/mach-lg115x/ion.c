/*
 * arch/arm/mach-lg115x/ion.c
 */

#include <linux/ion.h>
#include <linux/platform_device.h>

#include "ion.h"

static struct ion_platform_data lg115x_ion_data = {
	.nr = 3,
	.heaps = {
		{
			.type = ION_HEAP_TYPE_SYSTEM,
			.id = ION_HEAP_TYPE_SYSTEM,
			.name = "ION_HEAP_TYPE_SYSTEM",
		},
		{
			.type = ION_HEAP_TYPE_SYSTEM_CONTIG,
			.id = ION_HEAP_TYPE_SYSTEM_CONTIG,
			.name = "ION_HEAP_TYPE_SYSTEM_CONTIG",
		},
		{
			.type = ION_HEAP_TYPE_CARVEOUT,
			.id = ION_HEAP_TYPE_CARVEOUT,
			.name = "ION_HEAP_TYPE_CARVEOUT",
			.base = LG115X_ION_CARVEOUT_BLOCK0_BASE,
			.size = LG115X_ION_CARVEOUT_BLOCK0_SIZE,
		},
	},
};

static struct platform_device lg115x_ion_device = {
	.name = "ion-lg115x",
	.id = -1,
	.dev = {
		.platform_data = &lg115x_ion_data,
	},
};

void __init lg115x_register_ion(void)
{
	platform_device_register(&lg115x_ion_device);
}

void __init lg115x_ion_init(void)
{

/* memory separation for ION is already done in bootloader */
}
