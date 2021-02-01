#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <linux/ioport.h>
#include <linux/sizes.h>

#include <mach/resource.h>

#ifdef CONFIG_MACH_LG1152
#define SDHCI_NAME	"sdhci-lg1152"
#else
#define SDHCI_NAME	"sdhci-lg115x"
#endif

static struct resource sdhci_res[] = {
	DEFINE_RES_MEM_NAMED(SDHCI_BASE, SZ_4K, "emmc-reg"),
	DEFINE_RES_IRQ_NAMED(SDHCI_IRQ,         "emmc-irq"),
};

static u64 sdhci_dma_mask = DMA_BIT_MASK(32);

static struct platform_device sdhci_dev = {
	.name		= SDHCI_NAME,
	.id		= 0,
	.num_resources	= ARRAY_SIZE(sdhci_res),
	.resource	= sdhci_res,
	.dev		= {
		.dma_mask		= &sdhci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
};

void __init lg115x_init_emmc(void)
{
	platform_device_register(&sdhci_dev);
}
