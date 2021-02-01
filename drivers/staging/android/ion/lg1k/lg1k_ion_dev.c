#include <linux/platform_device.h>
#include <linux/init.h>

#include "../ion.h"

static struct ion_platform_heap lg1k_ion_heaps[] = {
	{
		.id     = ION_HEAP_TYPE_SYSTEM,
		.type   = ION_HEAP_TYPE_SYSTEM,
		.name   = "system",
	},
	{
		.id     = ION_HEAP_TYPE_SYSTEM_CONTIG,
		.type   = ION_HEAP_TYPE_SYSTEM_CONTIG,
		.name   = "system contig",
	},
};

static struct ion_platform_data lg1k_ion_pdata = {
	.nr = ARRAY_SIZE(lg1k_ion_heaps),
	.heaps = lg1k_ion_heaps,
};

static struct platform_device lg1k_ion_device = {
	.name = "ion-lg1k",
	.id = -1,
	.dev = {
		.platform_data = &lg1k_ion_pdata,
	},
};

static int __init lg1k_ion_init(void)
{
	/* memory separation for ION is already done in bootloader */
	platform_device_register(&lg1k_ion_device);
	return 0;
}
late_initcall(lg1k_ion_init);
