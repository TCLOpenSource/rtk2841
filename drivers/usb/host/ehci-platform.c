/*
 * Generic platform ehci driver
 *
 * Copyright 2007 Steven Brown <sbrown@cortland.com>
 * Copyright 2010-2012 Hauke Mehrtens <hauke@hauke-m.de>
 * Copyright 2014 Hans de Goede <hdegoede@redhat.com>
 *
 * Derived from the ohci-ssb driver
 * Copyright 2007 Michael Buesch <m@bues.ch>
 *
 * Derived from the EHCI-PCI driver
 * Copyright (c) 2000-2004 by David Brownell
 *
 * Derived from the ohci-pci driver
 * Copyright 1999 Roman Weissgaerber
 * Copyright 2000-2002 David Brownell
 * Copyright 1999 Linus Torvalds
 * Copyright 1999 Gregory P. Smith
 *
 * Licensed under the GNU/GPL. See COPYING for details.
 */
#include <linux/acpi.h>
#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/hrtimer.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/phy/phy.h>
#include <linux/platform_device.h>
#include <linux/reset.h>
#include <linux/usb.h>
#include <linux/usb/hcd.h>
#include <linux/usb/ehci_pdriver.h>
#include "ehci.h"

#define DRIVER_DESC "EHCI generic platform driver"
#define EHCI_MAX_CLKS 3
#define hcd_to_ehci_priv(h) ((struct ehci_platform_priv *)hcd_to_ehci(h)->priv)

#define ehci_plat_dbg(fmt, args...)           pr_debug("[ehci] dbg, " fmt, ## args)
#define ehci_plat_info(fmt, args...)          pr_info("[ehci] info, " fmt, ## args)
#define ehci_plat_warn(fmt, args...)          pr_warn("[ehci] warn, " fmt, ## args)

#if (1)   /* RTK self defined usb2_platform ops */
static struct rtk_ehci_platform_driver *rtk_ehci_platform;
#endif

struct ehci_platform_priv {
	struct clk *clks[EHCI_MAX_CLKS];
	struct reset_control *rst;
	struct phy **phys;
	int num_phys;
	bool reset_on_resume;
};

#ifdef CONFIG_USB_EHCI_TRACE_QTD
LIST_HEAD(ehci_plat_list);
#endif

static const char hcd_name[] = "ehci-platform";

static int ehci_platform_reset(struct usb_hcd *hcd)
{
	struct platform_device *pdev = to_platform_device(hcd->self.controller);
	struct usb_ehci_pdata *pdata = dev_get_platdata(&pdev->dev);
	struct ehci_hcd *ehci = hcd_to_ehci(hcd);
	int retval;

	ehci->has_synopsys_hc_bug = pdata->has_synopsys_hc_bug;

	if (pdata->pre_setup) {
		retval = pdata->pre_setup(hcd);
		if (retval < 0)
			return retval;
	}

	ehci->caps = hcd->regs + pdata->caps_offset;
	retval = ehci_setup(hcd);
	if (retval)
		return retval;

	if (pdata->no_io_watchdog)
		ehci->need_io_watchdog = 0;
	return 0;
}

#if 0
static int ehci_platform_power_on(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct ehci_platform_priv *priv = hcd_to_ehci_priv(hcd);
	int clk, ret, phy_num;

	for (clk = 0; clk < EHCI_MAX_CLKS && priv->clks[clk]; clk++) {
		ret = clk_prepare_enable(priv->clks[clk]);
		if (ret)
			goto err_disable_clks;
	}

	for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
		ret = phy_init(priv->phys[phy_num]);
		if (ret)
			goto err_exit_phy;
		ret = phy_power_on(priv->phys[phy_num]);
		if (ret) {
			phy_exit(priv->phys[phy_num]);
			goto err_exit_phy;
		}
	}

	return 0;

err_exit_phy:
	while (--phy_num >= 0) {
		phy_power_off(priv->phys[phy_num]);
		phy_exit(priv->phys[phy_num]);
	}
err_disable_clks:
	while (--clk >= 0)
		clk_disable_unprepare(priv->clks[clk]);

	return ret;
}
#endif

static int rtk_ehci_platform_power_on(struct platform_device *dev)
{
	ehci_plat_info("------------------ %s -------------------- \n", __func__);
	rtk_ehci_platform = get_rtk_ehci_platform_driver();
	if (!rtk_ehci_platform)
		return -ENODEV;

	if (rtk_ehci_platform->usb_on) {
        rtk_ehci_platform->usb_on();
	} else {
		rtk_put_ehci_platform(rtk_ehci_platform);
		return -ENODEV;
	}
	ehci_plat_info("------------------ %s complete ----------- \n", __func__);
	return 0;
}

#if 0
static void ehci_platform_power_off(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct ehci_platform_priv *priv = hcd_to_ehci_priv(hcd);
	int clk, phy_num;

	for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
		phy_power_off(priv->phys[phy_num]);
		phy_exit(priv->phys[phy_num]);
	}

	for (clk = EHCI_MAX_CLKS - 1; clk >= 0; clk--)
		if (priv->clks[clk])
			clk_disable_unprepare(priv->clks[clk]);
}
#endif

static void rtk_ehci_platform_power_off(struct platform_device *dev)
{
	ehci_plat_info("------------------ %s -------------------- \n", __func__);
	rtk_ehci_platform = get_rtk_ehci_platform_driver();
	if (!rtk_ehci_platform)
		return;

	if (rtk_ehci_platform->usb_off)
        rtk_ehci_platform->usb_off();

    rtk_put_ehci_platform(rtk_ehci_platform);
	ehci_plat_info("------------------ %s complete ----------- \n", __func__);
}

static struct hc_driver __read_mostly ehci_platform_hc_driver;

#ifdef CONFIG_USER_INITCALL_USB
static const struct ehci_driver_overrides platform_overrides = {
#else
static const struct ehci_driver_overrides platform_overrides __initconst = {
#endif
	.reset =		ehci_platform_reset,
	.extra_priv_size =	sizeof(struct ehci_platform_priv),
};

static struct usb_ehci_pdata ehci_platform_defaults = {
#if 1 /* We use rtk self-defined power on/off seuqeunce */
	.power_on      = rtk_ehci_platform_power_on,
	.power_off     = rtk_ehci_platform_power_off,
	.power_suspend = rtk_ehci_platform_power_off,
#else
	.power_on =		ehci_platform_power_on,
	.power_off =		ehci_platform_power_off,
	.power_suspend =	ehci_platform_power_off,
#endif
};

static int ehci_platform_probe(struct platform_device *dev)
{
	struct usb_hcd *hcd;
	struct resource *res_mem;
	struct usb_ehci_pdata *pdata = dev_get_platdata(&dev->dev);
	struct ehci_platform_priv *priv;
	struct ehci_hcd *ehci;
	int err, irq, phy_num, clk = 0;
#ifdef CONFIG_USB_EHCI_TRACE_QTD
	struct qtd_trace *qtd_trace;
#endif

	if (usb_disabled())
		return -ENODEV;

	/*
	 * Use reasonable defaults so platforms don't have to provide these
	 * with DT probing on ARM.
	 */
	if (!pdata)
		pdata = &ehci_platform_defaults;

	err = dma_coerce_mask_and_coherent(&dev->dev,
		pdata->dma_mask_64 ? DMA_BIT_MASK(64) : DMA_BIT_MASK(32));
	if (err) {
		dev_err(&dev->dev, "Error: DMA mask configuration failed\n");
		return err;
	}

	irq = platform_get_irq(dev, 0);
	if (irq < 0) {
		dev_err(&dev->dev, "no irq provided");
		return irq;
	}

	hcd = usb_create_hcd(&ehci_platform_hc_driver, &dev->dev,
			     dev_name(&dev->dev));
	if (!hcd)
		return -ENOMEM;

	platform_set_drvdata(dev, hcd);
	dev->dev.platform_data = pdata;
	priv = hcd_to_ehci_priv(hcd);
	ehci = hcd_to_ehci(hcd);

	if (pdata == &ehci_platform_defaults && dev->dev.of_node) {
		if (of_property_read_bool(dev->dev.of_node, "big-endian-regs"))
			ehci->big_endian_mmio = 1;

		if (of_property_read_bool(dev->dev.of_node, "big-endian-desc"))
			ehci->big_endian_desc = 1;

		if (of_property_read_bool(dev->dev.of_node, "big-endian"))
			ehci->big_endian_mmio = ehci->big_endian_desc = 1;

		if (of_property_read_bool(dev->dev.of_node,
					  "needs-reset-on-resume"))
			priv->reset_on_resume = true;

		if (of_property_read_bool(dev->dev.of_node,
					  "has-transaction-translator"))
			hcd->has_tt = 1;

		priv->num_phys = of_count_phandle_with_args(dev->dev.of_node,
				"phys", "#phy-cells");

		if (priv->num_phys > 0) {
			priv->phys = devm_kcalloc(&dev->dev, priv->num_phys,
					    sizeof(struct phy *), GFP_KERNEL);
			if (!priv->phys)
				return -ENOMEM;
		} else
			priv->num_phys = 0;

		for (phy_num = 0; phy_num < priv->num_phys; phy_num++) {
			priv->phys[phy_num] = devm_of_phy_get_by_index(
					&dev->dev, dev->dev.of_node, phy_num);
			if (IS_ERR(priv->phys[phy_num])) {
				err = PTR_ERR(priv->phys[phy_num]);
					goto err_put_hcd;
			}
		}

		for (clk = 0; clk < EHCI_MAX_CLKS; clk++) {
			priv->clks[clk] = of_clk_get(dev->dev.of_node, clk);
			if (IS_ERR(priv->clks[clk])) {
				err = PTR_ERR(priv->clks[clk]);
				if (err == -EPROBE_DEFER)
					goto err_put_clks;
				priv->clks[clk] = NULL;
				break;
			}
		}
	}

	priv->rst = devm_reset_control_get_optional(&dev->dev, NULL);
	if (IS_ERR(priv->rst)) {
		err = PTR_ERR(priv->rst);
		if (err == -EPROBE_DEFER)
			goto err_put_clks;
		priv->rst = NULL;
	} else {
		err = reset_control_deassert(priv->rst);
		if (err)
			goto err_put_clks;
	}

	if (pdata->big_endian_desc)
		ehci->big_endian_desc = 1;
	if (pdata->big_endian_mmio)
		ehci->big_endian_mmio = 1;
	if (pdata->has_tt)
		hcd->has_tt = 1;
	if (pdata->reset_on_resume)
		priv->reset_on_resume = true;

#ifndef CONFIG_USB_EHCI_BIG_ENDIAN_MMIO
	if (ehci->big_endian_mmio) {
		dev_err(&dev->dev,
			"Error: CONFIG_USB_EHCI_BIG_ENDIAN_MMIO not set\n");
		err = -EINVAL;
		goto err_reset;
	}
#endif
#ifndef CONFIG_USB_EHCI_BIG_ENDIAN_DESC
	if (ehci->big_endian_desc) {
		dev_err(&dev->dev,
			"Error: CONFIG_USB_EHCI_BIG_ENDIAN_DESC not set\n");
		err = -EINVAL;
		goto err_reset;
	}
#endif

	if (pdata->power_on) {
		err = pdata->power_on(dev);
		if (err < 0)
			goto err_reset;
	}

	res_mem = platform_get_resource(dev, IORESOURCE_MEM, 0);
	hcd->regs = devm_ioremap_resource(&dev->dev, res_mem);
	if (IS_ERR(hcd->regs)) {
		err = PTR_ERR(hcd->regs);
		goto err_power;
	}
	hcd->rsrc_start = res_mem->start;
	hcd->rsrc_len = resource_size(res_mem);
#if 1 /* We dont ioremap resource */
	hcd->regs = (void __iomem *)hcd->rsrc_start;
#endif

#ifdef CONFIG_USB_HCD_TEST_MODE
	hcd->port_test_mode = rtk_ehci_port_test_mode;
#endif

#ifdef CONFIG_USB_EHCI_TRACE_QTD
	/* Initialize qTD trace system */
	qtd_trace = kzalloc(sizeof(*qtd_trace), GFP_KERNEL);
	if (!qtd_trace) {
		err = -ENOMEM;
		goto err_power;
	}

	qtd_trace->max_qtd_trace_size = sizeof(qtd_trace->qtd_logs) / sizeof(*qtd_trace->qtd_logs);
	qtd_trace->qtd_count = 0;
	ehci->qtd_trace = qtd_trace;
	list_add_tail(&ehci->ehci_list, &ehci_plat_list);
#endif

	err = usb_add_hcd(hcd, irq, IRQF_SHARED);
	if (err)
		goto err_free_qtd_trace;

	if (rtk_ehci_platform->create_sysfs)
		rtk_ehci_platform->create_sysfs(hcd);

	device_wakeup_enable(hcd->self.controller);
	device_enable_async_suspend(hcd->self.controller);
	platform_set_drvdata(dev, hcd);

	return err;

err_free_qtd_trace:
#ifdef CONFIG_USB_EHCI_TRACE_QTD
	kfree(qtd_trace);
	ehci->qtd_trace = NULL;
	list_del(&ehci->ehci_list);
#endif
err_power:
	if (pdata->power_off)
		pdata->power_off(dev);
err_reset:
	if (priv->rst)
		reset_control_assert(priv->rst);
err_put_clks:
	while (--clk >= 0)
		clk_put(priv->clks[clk]);
err_put_hcd:
	if (pdata == &ehci_platform_defaults)
		dev->dev.platform_data = NULL;

	usb_put_hcd(hcd);

	return err;
}

static int ehci_platform_remove(struct platform_device *dev)
{
	struct usb_hcd *hcd = platform_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(&dev->dev);
	struct ehci_platform_priv *priv = hcd_to_ehci_priv(hcd);
	int clk;
#ifdef CONFIG_USB_EHCI_TRACE_QTD
	struct ehci_hcd *ehci = hcd_to_ehci(hcd);

	kfree(ehci->qtd_trace);
	list_del(&ehci->ehci_list);
#endif

	usb_remove_hcd(hcd);

	if (pdata->power_off)
		pdata->power_off(dev);

	if (priv->rst)
		reset_control_assert(priv->rst);

	for (clk = 0; clk < EHCI_MAX_CLKS && priv->clks[clk]; clk++)
		clk_put(priv->clks[clk]);

	usb_put_hcd(hcd);

	if (pdata == &ehci_platform_defaults)
		dev->dev.platform_data = NULL;

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int ehci_platform_suspend(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	bool do_wakeup = device_may_wakeup(dev);
	int ret;

	ret = ehci_suspend(hcd, do_wakeup);
	if (ret)
		return ret;

	if (pdata->power_suspend)
		pdata->power_suspend(pdev);

	return ret;
}

static int ehci_platform_resume(struct device *dev)
{
	struct usb_hcd *hcd = dev_get_drvdata(dev);
	struct usb_ehci_pdata *pdata = dev_get_platdata(dev);
	struct platform_device *pdev =
		container_of(dev, struct platform_device, dev);
	struct ehci_platform_priv *priv = hcd_to_ehci_priv(hcd);

	if (pdata->power_on) {
		int err = pdata->power_on(pdev);
		if (err < 0)
			return err;
	}

	ehci_resume(hcd, priv->reset_on_resume);
	return 0;
}
#endif /* CONFIG_PM_SLEEP */

#ifdef CONFIG_USB_EHCI_TRACE_QTD
#include <rtk_dc_mt.h>

extern void dump_qtds(struct ehci_hcd *ehci);
void ehci_dcmt_callback(void)
{
	struct ehci_hcd *ehci, *next;
	int platform_index = -1;

	/*
	 * TODO: Modify statment if differect SoC has differect USB2 IP. */
	if (isDcmtTrap("sb1_usb"))
		platform_index = 0;
    else if (isDcmtTrap("sb1_usb_ex"))
		platform_index = 1;

	/* Neither of our IP casuses the trap */
	if (platform_index < 0)
		return;

	list_for_each_entry_safe(ehci, next, &ehci_plat_list, ehci_list) {
		struct usb_hcd *hcd = ehci_to_hcd(ehci);
		struct platform_device *pdev = to_platform_device(hcd->self.controller);

		if (platform_get_device_id(pdev)->driver_data == platform_index) {
			dump_qtds(ehci);
			break;
		}
	}
}
DCMT_DEBUG_INFO_DECLARE(usb_ehci, ehci_dcmt_callback);
#endif

static const struct of_device_id vt8500_ehci_ids[] = {
	{ .compatible = "via,vt8500-ehci", },
	{ .compatible = "wm,prizm-ehci", },
	{ .compatible = "generic-ehci", },
	{ .compatible = "cavium,octeon-6335-ehci", },
	{}
};
MODULE_DEVICE_TABLE(of, vt8500_ehci_ids);

static const struct acpi_device_id ehci_acpi_match[] = {
	{ "PNP0D20", 0 }, /* EHCI controller without debug */
	{ }
};
MODULE_DEVICE_TABLE(acpi, ehci_acpi_match);

static const struct platform_device_id ehci_platform_table[] = {
	{ "ehci-platform", 0 },
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
	{ "ehci-platform-ex", 1 },
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */
	{ }
};
MODULE_DEVICE_TABLE(platform, ehci_platform_table);

static SIMPLE_DEV_PM_OPS(ehci_platform_pm_ops, ehci_platform_suspend,
	ehci_platform_resume);

static struct platform_driver ehci_platform_driver = {
	.id_table	= ehci_platform_table,
	.probe		= ehci_platform_probe,
	.remove		= ehci_platform_remove,
	.shutdown	= usb_hcd_platform_shutdown,
	.driver		= {
		.name	= "ehci-platform",
		.pm	= &ehci_platform_pm_ops,
		.of_match_table = vt8500_ehci_ids,
		.acpi_match_table = ACPI_PTR(ehci_acpi_match),
	}
};

#ifdef CONFIG_USER_INITCALL_USB
static int ehci_platform_init(void)
#else
static int __init ehci_platform_init(void)
#endif
{
	if (usb_disabled())
		return -ENODEV;

	pr_info("%s: " DRIVER_DESC "\n", hcd_name);

#ifdef CONFIG_USB_EHCI_TRACE_QTD
	// register DCMT callback
	DCMT_DEBUG_INFO_REGISTER(usb_ehci, ehci_dcmt_callback);
#endif

	ehci_init_driver(&ehci_platform_hc_driver, &platform_overrides);
	return platform_driver_register(&ehci_platform_driver);
}
#if defined(CONFIG_USER_INITCALL_USB) && !defined(MODULE)
user_initcall_grp("USB", ehci_platform_init);
#else
module_init(ehci_platform_init);
#endif

static void __exit ehci_platform_cleanup(void)
{
#ifdef CONFIG_USB_EHCI_TRACE_QTD
	DCMT_DEBUG_INFO_UNREGISTER(usb_ehci, ehci_dcmt_callback);
#endif
	platform_driver_unregister(&ehci_platform_driver);
}
module_exit(ehci_platform_cleanup);

MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_AUTHOR("Hauke Mehrtens");
MODULE_AUTHOR("Alan Stern");
MODULE_LICENSE("GPL");
