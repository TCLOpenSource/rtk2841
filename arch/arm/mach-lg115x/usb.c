#include <linux/kernel.h>

#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/platform_device.h>
#include <linux/usb/ehci_pdriver.h>
#include <linux/usb/ohci_pdriver.h>

#include <mach/resource.h>

#include "usb.h"

static u64 xhci_dma_mask = DMA_BIT_MASK(32);

#ifdef MACH_HAS_XHCI0

static struct resource xhci0_res[] = {
	DEFINE_RES_MEM_NAMED(XHCI0_BASE, SZ_4K, "xhci0-reg"),
	DEFINE_RES_IRQ_NAMED(XHCI0_IRQ,         "xhci0-irq"),
};

static struct platform_device xhci0_dev = {
	.name		= "xhci-hcd",
	.id		= 0,
	.dev = {
		.dma_mask		= &xhci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(xhci0_res),
	.resource	= xhci0_res,
};

static inline void xhci0_init(void)
{
	platform_device_register(&xhci0_dev);
}

#else	/* MACH_HAS_XHCI0 */

#define xhci0_init()	(void)NULL

#endif	/* MACH_HAS_XHCI0 */

#ifdef MACH_HAS_XHCI1

static struct resource xhci1_res[] = {
	DEFINE_RES_MEM_NAMED(XHCI1_BASE, SZ_4K, "xhci1-reg"),
	DEFINE_RES_IRQ_NAMED(XHCI1_IRQ,         "xhci1-irq"),
};

static struct platform_device xhci1_dev = {
	.name		= "xhci-hcd",
	.id		= 1,
	.dev = {
		.dma_mask		= &xhci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(xhci1_res),
	.resource	= xhci1_res,
};

static inline void xhci1_init(void)
{
	platform_device_register(&xhci1_dev);
}

#else	/* MACH_HAS_XHCI1 */

#define xhci1_init()	(void)NULL

#endif	/* MACH_HAS_XHCI1 */

#ifdef MACH_HAS_XHCI2

static struct resource xhci2_res[] = {
	DEFINE_RES_MEM_NAMED(XHCI2_BASE, SZ_4K, "xhci2-reg"),
	DEFINE_RES_IRQ_NAMED(XHCI2_IRQ,         "xhci2-irq"),
};

static struct platform_device xhci2_dev = {
	.name		= "xhci-hcd",
	.id		= 2,
	.dev = {
		.dma_mask		= &xhci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(xhci2_res),
	.resource	= xhci2_res,
};

static inline void xhci2_init(void)
{
	platform_device_register(&xhci2_dev);
}

#else	/* MACH_HAS_XHCI2 */

#define xhci2_init()	(void)NULL

#endif	/* MACH_HAS_XHCI2 */

#ifdef MACH_HAS_XHCI3

static struct resource xhci3_res[] = {
	DEFINE_RES_MEM_NAMED(XHCI3_BASE, SZ_4K, "xhci3-reg"),
	DEFINE_RES_IRQ_NAMED(XHCI3_IRQ,         "xhci3-irq"),
};

static struct platform_device xhci3_dev = {
	.name		= "xhci-hcd",
	.id		= 3,
	.dev = {
		.dma_mask		= &xhci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(xhci3_res),
	.resource	= xhci3_res,
};

static inline void xhci3_init(void)
{
	platform_device_register(&xhci3_dev);
}

#else	/* MACH_HAS_XHCI3 */

#define xhci3_init()	(void)NULL

#endif	/* MACH_HAS_XHCI3 */

static struct usb_ehci_pdata ehci_data = {
	.has_synopsys_hc_bug = 1,
};

static u64 ehci_dma_mask = DMA_BIT_MASK(32);

#ifdef MACH_HAS_EHCI0

static struct resource ehci0_res[] = {
	DEFINE_RES_MEM_NAMED(EHCI0_BASE, SZ_4K, "ehci0-reg"),
	DEFINE_RES_IRQ_NAMED(EHCI0_IRQ,         "ehci0-irq"),
};

static struct platform_device ehci0_dev = {
	.name		= "ehci-platform",
	.id		= 0,
	.dev		= {
		.dma_mask		= &ehci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ehci_data,
	},
	.num_resources	= ARRAY_SIZE(ehci0_res),
	.resource	= ehci0_res,
};

static inline void ehci0_init(void)
{
	platform_device_register(&ehci0_dev);
}

#else	/* MACH_HAS_EHCI0 */

#define ehci0_init()	(void)NULL

#endif	/* MACH_HAS_EHCI0 */

#ifdef MACH_HAS_EHCI1

static struct resource ehci1_res[] = {
	DEFINE_RES_MEM_NAMED(EHCI1_BASE, SZ_4K, "ehci1-reg"),
	DEFINE_RES_IRQ_NAMED(EHCI1_IRQ,         "ehci1-irq"),
};

static struct platform_device ehci1_dev = {
	.name		= "ehci-platform",
	.id		= 1,
	.dev		= {
		.dma_mask		= &ehci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ehci_data,
	},
	.num_resources	= ARRAY_SIZE(ehci1_res),
	.resource	= ehci1_res,
};

static inline void ehci1_init(void)
{
	platform_device_register(&ehci1_dev);
}

#else	/* MACH_HAS_EHCI1 */

#define ehci1_init()	(void)NULL

#endif	/* MACH_HAS_EHCI1 */

#ifdef MACH_HAS_EHCI2

static struct resource ehci2_res[] = {
	DEFINE_RES_MEM_NAMED(EHCI2_BASE, SZ_4K, "ehci2-reg"),
	DEFINE_RES_IRQ_NAMED(EHCI2_IRQ,         "ehci2-irq"),
};

static struct platform_device ehci2_dev = {
	.name		= "ehci-platform",
	.id		= 2,
	.dev		= {
		.dma_mask		= &ehci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ehci_data,
	},
	.num_resources	= ARRAY_SIZE(ehci2_res),
	.resource	= ehci2_res,
};

static inline void ehci2_init(void)
{
	platform_device_register(&ehci2_dev);
}

#else	/* MACH_HAS_EHCI2 */

#define ehci2_init()	(void)NULL

#endif	/* MACH_HAS_EHCI2 */

static struct usb_ohci_pdata ohci_data = {
	.num_ports = 1,
};

static u64 ohci_dma_mask = DMA_BIT_MASK(32);

#ifdef MACH_HAS_OHCI0

static struct resource ohci0_res[] = {
	DEFINE_RES_MEM_NAMED(OHCI0_BASE, SZ_4K, "ohci0-reg"),
	DEFINE_RES_IRQ_NAMED(OHCI0_IRQ,         "ohci0-irq"),
};

static struct platform_device ohci0_dev = {
	.name		= "ohci-platform",
	.id		= 0,
	.dev		= {
		.dma_mask		= &ohci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ohci_data,
	},
	.num_resources	= ARRAY_SIZE(ohci0_res),
	.resource	= ohci0_res,
};

static inline void ohci0_init(void)
{
	platform_device_register(&ohci0_dev);
}

#else	/* MACH_HAS_OHCI0 */

#define ohci0_init()	(void)NULL

#endif	/* MACH_HAS_OHCI0 */

#ifdef MACH_HAS_OHCI1

static struct resource ohci1_res[] = {
	DEFINE_RES_MEM_NAMED(OHCI1_BASE, SZ_4K, "ohci1-reg"),
	DEFINE_RES_IRQ_NAMED(OHCI1_IRQ,         "ohci1-irq"),
};

static struct platform_device ohci1_dev = {
	.name		= "ohci-platform",
	.id		= 1,
	.dev		= {
		.dma_mask		= &ohci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ohci_data,
	},
	.num_resources	= ARRAY_SIZE(ohci1_res),
	.resource	= ohci1_res,
};

static inline void ohci1_init(void)
{
	platform_device_register(&ohci1_dev);
}

#else	/* MACH_HAS_OHCI1 */

#define ohci1_init()	(void)NULL

#endif	/* MACH_HAS_OHCI1 */

#ifdef MACH_HAS_OHCI2

static struct resource ohci2_res[] = {
	DEFINE_RES_MEM_NAMED(OHCI2_BASE, SZ_4K, "ohci2-reg"),
	DEFINE_RES_IRQ_NAMED(OHCI2_IRQ,         "ohci2-irq"),
};

static struct platform_device ohci2_dev = {
	.name		= "ohci-platform",
	.id		= 2,
	.dev		= {
		.dma_mask		= &ohci_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
		.platform_data		= &ohci_data,
	},
	.num_resources	= ARRAY_SIZE(ohci2_res),
	.resource	= ohci2_res,
};

static inline void ohci2_init(void)
{
	platform_device_register(&ohci2_dev);
}

#else	/* MACH_HAS_OHCI2 */

#define ohci2_init()	(void)NULL

#endif	/* MACH_HAS_OHCI2 */

void __init lg115x_init_usb(void)
{
	xhci0_init();
	xhci1_init();
	xhci2_init();
	xhci3_init();
	ehci0_init();
	ehci1_init();
	ehci2_init();
	ohci0_init();
	ohci1_init();
	ohci2_init();
}
