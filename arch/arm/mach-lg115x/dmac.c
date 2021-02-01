#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/amba/pl08x.h>
#include <linux/amba/pl080.h>
#include <linux/init.h>

#include <mach/resource.h>

#include "dmac.h"

#define MEMCPY_CCTL	(\
	(PL080_BSIZE_256 << PL080_CONTROL_SB_SIZE_SHIFT) |\
	(PL080_BSIZE_256 << PL080_CONTROL_DB_SIZE_SHIFT) |\
	(PL080_WIDTH_32BIT << PL080_CONTROL_SWIDTH_SHIFT) |\
	(PL080_WIDTH_32BIT << PL080_CONTROL_DWIDTH_SHIFT) |\
	PL080_CONTROL_PROT_BUFF |\
	PL080_CONTROL_PROT_CACHE |\
	PL080_CONTROL_PROT_SYS\
	)

static struct pl08x_channel_data dmac_channel_data[] = {
	[0] = {
		.bus_id = "uart0rx",
		.min_signal = 0,
		.max_signal = 0,
	},
	[1] = {
		.bus_id = "uart0tx",
		.min_signal = 1,
		.max_signal = 1,
	},
	[2] = {
		.bus_id = "uart1rx",
		.min_signal = 2,
		.max_signal = 2,
	},
	[3] = {
		.bus_id = "uart1tx",
		.min_signal = 3,
		.max_signal = 3,
	},
	[4] = {
		.bus_id = "uart2rx",
		.min_signal = 4,
		.max_signal = 4,
	},
	[5] = {
		.bus_id = "uart2tx",
		.min_signal = 5,
		.max_signal = 5,
	},
};

static int dmac_get_signal(struct pl08x_channel_data const *data)
{
	return data->min_signal;
}

static void dmac_put_signal(struct pl08x_channel_data const *data, int signal)
{
}

static struct pl08x_platform_data dmac_data = {
	.slave_channels		= dmac_channel_data,
	.num_slave_channels	= ARRAY_SIZE(dmac_channel_data),
	.memcpy_channel		= {
		.bus_id		= "memcpy",
		.cctl_memcpy	= MEMCPY_CCTL,
	},
	.get_signal		= dmac_get_signal,
	.put_signal		= dmac_put_signal,
};

static AMBA_AHB_DEVICE(dmac, "dmac", 0, DMAC_BASE, DMAC_IRQS, &dmac_data);

void __init lg115x_init_dmac(void)
{
	amba_device_register(&dmac_device, &iomem_resource);
}
