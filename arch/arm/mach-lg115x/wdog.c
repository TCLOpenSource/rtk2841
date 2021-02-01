#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/init.h>
#include <linux/sizes.h>

#include <mach/resource.h>

#include "wdog.h"

static AMBA_APB_DEVICE(wdog, "wdog", 0, WDOG_BASE, WDOG_IRQS, NULL);

void __init lg115x_init_wdog(void)
{
	amba_device_register(&wdog_device, &iomem_resource);
}
