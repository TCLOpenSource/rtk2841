#include <linux/kernel.h>

#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_fdt.h>
#include <linux/of_gpio.h>
#include <linux/of_irq.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/slab.h>

#include <asm/memblock.h>

static phys_addr_t cmem;

static int __init
dt_scan_compat(unsigned long node, char const *uname, int depth, void *data)
{
	return of_flat_dt_is_compatible(node, data);
}

void __init lg115x_reserve_eth(void)
{
	if (of_scan_flat_dt(dt_scan_compat, "arasan,emac")) {
		cmem = arm_memblock_steal(SZ_1M, SZ_1M);
	}
}

static u16 rmii_mode;

static int rtl8201f_fixup_run(struct phy_device *phydev)
{
	/* adjust RMII mode setting */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0007);
	mdiobus_write(phydev->bus, phydev->addr, 0x10, rmii_mode);

	/* return to page 0 */
	mdiobus_write(phydev->bus, phydev->addr, 0x1f, 0x0000);

	return 0;
}

static int init_emac(struct device_node *np)
{
	struct platform_device *pdev;
	struct resource *res;

	res = kzalloc(sizeof(struct resource) * 2, GFP_KERNEL);
	of_address_to_resource(np, 0, &res[0]);
	of_irq_to_resource(np, 0, &res[1]);

	pdev = kzalloc(sizeof(struct platform_device), GFP_KERNEL);
	pdev->name = np->name;
	pdev->id = 0;
	pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
	pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
	pdev->dev.of_node = np;
	pdev->num_resources = 2;
	pdev->resource = res;

	if (cmem) {
		dma_declare_coherent_memory(&pdev->dev, cmem, cmem, SZ_1M,
		                            DMA_MEMORY_IO);
	}

	return platform_device_register(pdev);
}

static int init_macb(struct device_node *np)
{
	void __iomem *base;

	/* MACB/GEM: enable half-duplex mode */
	base = ioremap(0xfd3003d4, 4);
	writel_relaxed(0x00000000, base);
	iounmap(base);

	return 0;
}

static struct of_device_id const eth_ids[] = {
	{ .compatible = "arasan,emac", .data = init_emac, },
	{ .compatible = "cdns,gem",    .data = init_macb, },
	{ },
};

static int lg115x_init_eth(void)
{
	struct device_node *np;
	struct gpio_desc *reset;
	struct of_device_id const *match;
	int err;

	if (of_machine_is_compatible("lge,lg1312"))
		rmii_mode = 0x066a;
	else
		rmii_mode = 0x077a;

	phy_register_fixup_for_uid(0x001cc816, 0xfffffff0, rtl8201f_fixup_run);

	for_each_compatible_node(np, NULL, "realtek,rtl8201f") {
		reset = gpiod_get(NULL, "reset", GPIOD_ASIS);
		if (IS_ERR(reset)) {
			pr_warn("%s lacks property reset-gpios\n", np->name);
			continue;
		}

		/* reset-gpio should be initialized as output/inactive */
		gpiod_direction_output(reset, 0);
		gpiod_put(reset);
	}

	for_each_matching_node_and_match(np, eth_ids, &match) {
		if (match->data) {
			err = ((int (*)(struct device_node *))match->data)(np);
			if (err < 0)
				return err;
		}
	}

	return 0;
}
#ifndef	CONFIG_USER_INITCALL_NET
device_initcall(lg115x_init_eth);
#else	/* CONFIG_USER_INITCALL_NET */
user_initcall_grp("NET", lg115x_init_eth);
#endif	/* CONFIG_USER_INITCALL_NET */
