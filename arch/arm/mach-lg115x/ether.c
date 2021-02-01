#include <linux/kernel.h>

#include <linux/delay.h>
#include <linux/if_ether.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/netdevice.h>
#include <linux/phy.h>
#include <linux/platform_data/emac.h>
#include <linux/platform_data/macb.h>
#include <linux/platform_device.h>
#include <linux/sizes.h>
#include <linux/types.h>

#include <asm/io.h>
#include <asm/memblock.h>

#include <mach/resource.h>

#include "ether.h"

static unsigned char mac_addr[ETH_ALEN];

static int __init ethaddr_setup(char *str)
{
	unsigned char addr[ETH_ALEN];
	int i;

	for (i = 0; i < ETH_ALEN; ++i) {
		addr[i] = simple_strtoul(str, &str, 16);
		if (*str == ':' || *str == '-')
			++str;
	}
	memcpy(mac_addr, addr, ETH_ALEN);

	return 0;
}
__setup("ethaddr=", ethaddr_setup);

#ifdef CONFIG_EPHY_RESET_GPIO27
#define PHYRSTB_GPIO_BASE	GPIO_3_BASE
#define PHYRSTB_GPIO_OFFSET	3
#endif	/* CONFIG_EPHY_RESET_GPIO27 */

#ifdef CONFIG_EPHY_RESET_GPIO29
#define PHYRSTB_GPIO_BASE	GPIO_3_BASE
#define PHYRSTB_GPIO_OFFSET	5
#endif	/* CONFIG_EPHY_RESET_GPIO29 */

static void __init ephy_reset(void)
{
	void __iomem *base = ioremap(PHYRSTB_GPIO_BASE, SZ_4K);
	unsigned long ctrl = 1 << PHYRSTB_GPIO_OFFSET;

	writel_relaxed(readl_relaxed(base + 0x400) | ctrl, base + 0x400);

	writel_relaxed(0x00, base + (ctrl << 2));
	msleep(10);
	writel_relaxed(0xff, base + (ctrl << 2));
	msleep(150);

	iounmap(base);
}

#ifdef MACH_HAS_EMAC

static struct emac_platform_data emac_data = {
	.phy_mode = PHY_INTERFACE_MODE_RMII,
};

static struct resource emac_res[] = {
	DEFINE_RES_MEM_NAMED(EMAC_BASE, SZ_1K, "emac-reg"),
	DEFINE_RES_IRQ_NAMED(EMAC_IRQ,         "emac-irq"),
};

static struct platform_device emac_dev = {
	.name		= "emac",
	.id		= 0,
	.dev		= {
		.platform_data	= &emac_data,
	},
	.num_resources	= ARRAY_SIZE(emac_res),
	.resource	= emac_res,
};

static void __init emac_reserve(void)
{
	emac_data.desc_phys = arm_memblock_steal(SZ_1M, SZ_1M);
	emac_data.desc_size = PAGE_SIZE;
}

static void emac_init(void)
{
	memcpy(emac_data.mac_addr, mac_addr, ETH_ALEN);
	platform_device_register(&emac_dev);
}

#else	/* MACH_HAS_EMAC */

#define emac_reserve()	(void)NULL
#define emac_init()	(void)NULL

#endif	/* MACH_HAS_EMAC */

#ifdef MACH_HAS_MACB

static macb_platform_data __initdata macb_data = {
	.is_rmii	= 1,
};

static u64 macb_dma_mask = DMA_BIT_MASK(32);

static struct resource macb_res[] = {
	DEFINE_RES_MEM_NAMED(MACB_BASE, SZ_4K, "macb-reg"),
	DEFINE_RES_IRQ_NAMED(MACB_IRQ,         "macb-irq"),
};

static struct platform_device macb_dev = {
	.name		= "macb",
	.id		= 0,
	.dev		= {
		.platform_data		= &macb_data,
		.dma_mask		= &macb_dma_mask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(macb_res),
	.resource	= macb_res,
};

static void macb_init(void)
{
	platform_device_register(&macb_dev);
}

#else	/* MACH_HAS_MACB */

#define macb_init()	(void)NULL

#endif	/* MACH_HAS_MACB */

static int rtl8201f_fixup_run(struct phy_device *phydev)
{
	struct net_device *netdev = (struct net_device *)phydev->bus->priv;

	/* skip possible broadcasting address */
	if (phydev->addr == 0)
		return 0;

	/*
	 * RTL8201F: set MAC address
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0012);
	mdiobus_write(phydev->bus, phydev->addr, 0x10,
	              *(unsigned short *)&netdev->dev_addr[0]);
	mdiobus_write(phydev->bus, phydev->addr, 0x11,
	              *(unsigned short *)&netdev->dev_addr[2]);
	mdiobus_write(phydev->bus, phydev->addr, 0x12,
	              *(unsigned short *)&netdev->dev_addr[4]);

	/*
	 * RTL8201F: set max packet length
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0011);
	mdiobus_write(phydev->bus, phydev->addr, 0x11, 0x1fff);

	/*
	 * RTL8201F: wake up frame select and enable -- magic packet only
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0011);
	mdiobus_write(phydev->bus, phydev->addr, 0x10, 0x1000);

	/*
	 * RTL8201F: enable WOL
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0007);
	mdiobus_write(phydev->bus, phydev->addr, 0x13,
	              mdiobus_read(phydev->bus, phydev->addr, 0x13) | 0x0400);

	/*
	 * RTL8201F: disable EEE for better compatibility
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0004);
	mdiobus_write(phydev->bus, phydev->addr, 0x10, 0x4077);
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0000);
	mdiobus_write(phydev->bus, phydev->addr, 0x0d, 0x0007);
	mdiobus_write(phydev->bus, phydev->addr, 0x0e, 0x003c);
	mdiobus_write(phydev->bus, phydev->addr, 0x0d, 0x4007);
	mdiobus_write(phydev->bus, phydev->addr, 0x0e, 0x0000);

	/*
	 * RTL8201F: adjust RMII mode setting
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0007);
	mdiobus_write(phydev->bus, phydev->addr, 0x10, 0x077a);

	/*
	 * RTL8201F: return to page 0
	 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0000);

	return 0;
}

void __init lg115x_reserve_ether(void)
{
	emac_reserve();
}

void __init lg115x_init_ether(void)
{
	ephy_reset();

	/* fixup for Realtek RTL8201F */
	phy_register_fixup_for_uid(0x001cc816, 0xfffffff0, rtl8201f_fixup_run);

	emac_init();
	macb_init();
}
