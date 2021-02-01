#include <linux/kernel.h>

#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/usb/ehci_pdriver.h>
#include <linux/usb/ohci_pdriver.h>
#include <linux/usb/phy.h>

struct usb_host_data {
	char const *name;
	char const *phy_name;
	int *id;
	void *pdata;
	bool is_userresume;
	bool is_userresume_phy;
};

static int xhci_id;
static int ehci_id;
static int ohci_id;

static struct usb_ehci_pdata ehci_pdata = {
	.has_synopsys_hc_bug = 1,
};

static struct usb_ohci_pdata ohci_pdata = {
	.num_ports = 1,
};

static struct usb_host_data xhci_data = {
	.name	= "xhci-hcd",
	.phy_name	= "lg1k-usb3phy",
	.id	= &xhci_id,
	.is_userresume = true,
	.is_userresume_phy = false,
};

static struct usb_host_data ehci_data = {
	.name	= "ehci-platform",
	.phy_name	= "lg1k-usb2phy",
	.id	= &ehci_id,
	.pdata	= &ehci_pdata,
	.is_userresume = true,
	.is_userresume_phy = false,
};

static struct usb_host_data ohci_data = {
	.name	= "ohci-platform",
	.phy_name	= "lg1k-usb1phy",
	.id	= &ohci_id,
	.pdata	= &ohci_pdata,
	.is_userresume = true,
	.is_userresume_phy = false,
};

static struct of_device_id const usb_host_ids[] = {
	{ .compatible = "lge,lg115x-xhci", .data = &xhci_data, },
	{ .compatible = "lge,lg115x-ehci", .data = &ehci_data, },
	{ .compatible = "lge,lg115x-ohci", .data = &ohci_data, },
	{ },
};

static int lg115x_init_usb(void)
{
	struct device_node *np;

	for_each_matching_node(np, usb_host_ids) {
		struct usb_host_data const *data;
		struct resource *res;
		struct platform_device *pdev = NULL;
		struct device_node *phy_np = NULL;

		data = of_match_node(usb_host_ids, np)->data;

		res = kzalloc(sizeof(struct resource) * 2, GFP_KERNEL);
		of_address_to_resource(np, 0, &res[0]);
		of_irq_to_resource(np, 0, &res[1]);

		pdev = kzalloc(sizeof(struct platform_device), GFP_KERNEL);
		pdev->name = data->name;
		pdev->id = (*data->id)++;
		pdev->dev.of_node = np;
		pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
		pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
		pdev->dev.platform_data = data->pdata;
		pdev->dev.power.is_userresume = data->is_userresume;
		pdev->num_resources = 2;
		pdev->resource = res;

		phy_np = of_get_next_child(np, NULL);
		if(phy_np) {
			struct platform_device *phy_pdev = NULL;
			char *pdev_name, *phy_pdev_name;

			pdev_name = kzalloc(32, GFP_KERNEL);
			phy_pdev_name = kzalloc(32, GFP_KERNEL);
			phy_pdev = kzalloc(sizeof(struct platform_device),
				GFP_KERNEL);
			phy_pdev->name = data->phy_name;
			phy_pdev->id = pdev->id;
			phy_pdev->dev.of_node = phy_np;
			phy_pdev->dev.power.is_userresume = data->is_userresume_phy;
			/*
			 * get device names and bind in advance before devices
			 * are registered. In some initcall sequence,controller
			 * must be probed after bind phy device.
			 */
			sprintf(pdev_name, "%s.%d", pdev->name, pdev->id);
			sprintf(phy_pdev_name, "%s.%d", phy_pdev->name,
					phy_pdev->id);
			usb_bind_phy(pdev_name, 0, phy_pdev_name);
			platform_device_register(phy_pdev);
		}

		platform_device_register(pdev);
	}
	return 0;
}
#ifndef	CONFIG_USER_INITCALL_USB
device_initcall(lg115x_init_usb);
#else	/* CONFIG_USER_INITCALL_USB */
user_initcall_grp("USB", lg115x_init_usb);
#endif	/* CONFIG_USER_INITCALL_USB */
