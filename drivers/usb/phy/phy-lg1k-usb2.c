/*
 * SIC LABORATORY, LG ELECTRONICS INC., SEOUL, KOREA
 * Copyright(c) 2013 by LG Electronics Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/err.h>

#include "phy-lg1k-usb.h"

static int lg1k_usb2_phy_init(struct lg1k_usbphy *lgphy)
{
	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error no phy\n");
		return -EFAULT;
	}

	if (lgphy->syntop)
		writel(lgphy->syntop_val, lgphy->syntop);

	if (of_device_is_compatible(lgphy->dev->of_node,
					"lge,lg1k-usb2btphy")) {
		union usb2_bt_phy_param_0_union parm0;
		parm0.val = readl(lgphy->phy_reg +
					bt_phy_offset(param0));

		parm0.reg.phy_txpreempamptune = 0x3;

		writel(parm0.val, lgphy->phy_reg +
					bt_phy_offset(param0));
	} else {
		union usb2_phy_param_0_union parm0;
		parm0.val = readl(lgphy->phy_reg +
					phy_offset(2, param0));

		parm0.reg.phy_txpreempamptune = 0x3;

		writel(parm0.val, lgphy->phy_reg +
					phy_offset(2, param0));
	}

	return 0;
}

static int lg1k_usb2_reset(struct lg1k_usbphy *lgphy)
{
	union usb2_host_reset_union host_reset;

	if (!lgphy->phy_reg || !lgphy->host_reg) {
		dev_err(lgphy->phy_reg, "error reg iomem\n");
		return -EFAULT;
	}

	if (of_device_is_compatible(lgphy->dev->of_node,
					"lge,lg1k-usb2btphy")) {
		union usb2_bt_phy_param_0_union parm0;
		parm0.val = readl(lgphy->phy_reg +
						bt_phy_offset(param0));

		parm0.reg.phy_bt_por = 0x1;

		writel(parm0.val, lgphy->phy_reg +
					bt_phy_offset(param0));
	} else {
		union usb2_phy_reset_union phy_reset;
		phy_reset.val = readl(lgphy->phy_reg +
						phy_offset(2, reset));
		phy_reset.reg.usb2_phy_reset = 1;
		writel(phy_reset.val, lgphy->phy_reg +
						phy_offset(2, reset));
	}
	msleep(1);

	host_reset.val = readl(lgphy->host_reg + host_offset(2, reset));
	host_reset.reg.usb2_host_utmi_reset = 1;
	writel(host_reset.val, lgphy->host_reg + host_offset(2, reset));
	host_reset.reg.usb2_host_bus_reset = 1;
	host_reset.reg.usb2_host_core_reset = 1;
	writel(host_reset.val, lgphy->host_reg + host_offset(2, reset));

	return 0;
}

static int lg1k_usb2phy_init(struct usb_phy *phy)
{
	struct lg1k_usbphy *lgphy;

	lgphy = phy_to_lgphy(phy);

	if (lgphy->hw_initialized) {
		dev_info(lgphy->dev, "phy is already initialized\n");
		return 0;
	}

	lg1k_usb2_phy_init(lgphy);
	lg1k_usb2_reset(lgphy);

	lgphy->hw_initialized = 1;

	return 0;
}

static int lg1k_usb2_probe(struct platform_device *pdev)
{
	struct lg1k_usbphy *lgphy;
	struct device *dev = &(pdev->dev);
	int ret;

	lgphy = devm_kzalloc(dev, sizeof(*lgphy), GFP_KERNEL);

	if (!lgphy) {
		dev_err(dev, "lgphy alloc fail|\n");
		return -ENOMEM;
	}
	lgphy->dev = dev;

	if (dev->of_node) {
		ret = lg1k_usbphy_parse_dt(lgphy);
		if (ret < 0) {
			dev_err(dev, "device tree parsing fail!\n");
			return ret;
		}
	}

	lgphy->id		= pdev->id;
	lgphy->phy.dev		= lgphy->dev;
	lgphy->phy.label	= "lg1k-usb2";
	lgphy->phy.type		= USB_PHY_TYPE_USB2;
	lgphy->phy.init		= lg1k_usb2phy_init;
	lgphy->phy.shutdown	= lg1k_usbphy_shutdown;
	lgphy->phy.set_vbus	= lg1k_usbphy_set_vbus;
	lgphy->phy.set_wakeup	= lg1k_usbphy_set_wakeup;
	lgphy->phy.set_suspend	= lg1k_usbphy_set_suspend;

	platform_set_drvdata(pdev, lgphy);
	device_enable_async_suspend(lgphy->dev);
	dev_info(lgphy->dev, "%s:add usb phy\n", __func__);

	return usb_add_phy_dev(&lgphy->phy);
}

static int lg1k_usb2_remove(struct platform_device *pdev)
{
	struct lg1k_usbphy *lgphy = platform_get_drvdata(pdev);

	dev_info(lgphy->dev, "remove phy\n");

	lg1k_usbphy_remove(lgphy);

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int lg1k_usb2_suspend_late(struct device *dev)
{
	struct platform_device *pdev;
	struct lg1k_usbphy *lgphy;

	pdev = to_platform_device(dev);
	lgphy = platform_get_drvdata(pdev);

	dev_info(dev, "suspend_late phy\n");

	lgphy->hw_initialized = 0;

	return 0;
}

static int lg1k_usb2_resume(struct device *dev)
{
	struct platform_device *pdev;
	struct lg1k_usbphy *lgphy;

	pdev = to_platform_device(dev);
	lgphy = platform_get_drvdata(pdev);

	dev_info(dev, "resume phy\n");

	lg1k_usbphy_set_vbus(&lgphy->phy, true);
	lg1k_usb2phy_init(&lgphy->phy);

	return 0;
}

static int lg1k_usb2_resume_early(struct device *dev)
{
	return 0;
}

static const struct dev_pm_ops lg1k_usb2_pm_ops = {
	.resume = lg1k_usb2_resume,
	SET_LATE_SYSTEM_SLEEP_PM_OPS(lg1k_usb2_suspend_late,
						lg1k_usb2_resume_early)
};
#define DEV_PM_OPS	(&lg1k_usb2_pm_ops)
#else
#define DEV_PM_OPS	NULL
#endif /* CONFIG_PM_SLEEP */

static struct platform_device_id lg1k_usb2_driver_ids[] = {
	{ .name = "lg1k-usb2phy", },
	{ .name = "lg1k-usb2btphy", },
	{},
};
MODULE_DEVICE_TABLE(platform, lg1k_usb2_driver_ids);

static struct platform_driver lg1k_usb2phy_driver = {
	.probe		= lg1k_usb2_probe,
	.remove		= lg1k_usb2_remove,
	.id_table	= lg1k_usb2_driver_ids,
	.driver	= {
		.name = "lg1k-usb2phy",
		.pm = DEV_PM_OPS,
	},
};
module_platform_driver(lg1k_usb2phy_driver);

MODULE_DESCRIPTION("LG DTV USB 2.0 phy controller");
MODULE_AUTHOR("Shinhoe Kim <shinhoe.kim@lge.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:lg1k-usb2phy");
