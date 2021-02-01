/*
 * platform.c - DesignWare HS OTG Controller platform driver
 *
 * Copyright (C) Matthijs Kooijman <matthijs@stdin.nl>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The names of the above-listed copyright holders may not be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * ALTERNATIVELY, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option) any
 * later version.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/clk.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/of_device.h>
#include <linux/mutex.h>
#include <linux/platform_device.h>
#include <linux/phy/phy.h>
#include <linux/platform_data/s3c-hsotg.h>
#include <linux/reset.h>

#include <linux/usb/of.h>

#include "core.h"
#include "hcd.h"
#include "debug.h"

#ifdef CONFIG_DWC2_RTK
#include <rbus/sb2_reg.h>
#include <rbus/usb_reg.h>
#ifdef CONFIG_RTK_KDRIVER_SUPPORT
#include <rbus/sys_reg_reg.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_gpio.h>
#else
#include <rbus/crt_reg.h>
#include <mach/rtk_crt.h>
#include <mach/rtk_gpio.h>
#endif // end of CONFIG_RTK_KDRIVER_SUPPORT
#include <rbus/pll27x_reg_reg.h>
#include <rbus/stb_reg.h>
#endif  // end of CONFIG_DWC2_RTK

#ifdef CONFIG_ARM64
    extern u32 gic_irq_find_mapping(u32 hwirq);
    #define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            gic_irq_find_mapping(hwirq)
#else
    #define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            (hwirq)
#endif

static const char dwc2_driver_name[] = "dwc2";

static const struct dwc2_core_params params_hi6220 = {
	.otg_cap			= 2,	/* No HNP/SRP capable */
	.otg_ver			= 0,	/* 1.3 */
	.dma_enable			= 1,
	.dma_desc_enable		= 0,
	.dma_desc_fs_enable		= 0,
	.speed				= 0,	/* High Speed */
	.enable_dynamic_fifo		= 1,
	.en_multiple_tx_fifo		= 1,
	.host_rx_fifo_size		= 512,
	.host_nperio_tx_fifo_size	= 512,
	.host_perio_tx_fifo_size	= 512,
	.max_transfer_size		= 65535,
	.max_packet_count		= 511,
	.host_channels			= 16,
	.phy_type			= 1,	/* UTMI */
	.phy_utmi_width			= 8,
	.phy_ulpi_ddr			= 0,	/* Single */
	.phy_ulpi_ext_vbus		= 0,
	.i2c_enable			= 0,
	.ulpi_fs_ls			= 0,
	.host_support_fs_ls_low_power	= 0,
	.host_ls_low_power_phy_clk	= 0,	/* 48 MHz */
	.ts_dline			= 0,
	.reload_ctl			= 0,
	.ahbcfg				= GAHBCFG_HBSTLEN_INCR16 <<
					  GAHBCFG_HBSTLEN_SHIFT,
	.uframe_sched			= 0,
	.external_id_pin_ctl		= -1,
	.hibernation			= -1,
};

static const struct dwc2_core_params params_bcm2835 = {
	.otg_cap			= 0,	/* HNP/SRP capable */
	.otg_ver			= 0,	/* 1.3 */
	.dma_enable			= 1,
	.dma_desc_enable		= 0,
	.dma_desc_fs_enable		= 0,
	.speed				= 0,	/* High Speed */
	.enable_dynamic_fifo		= 1,
	.en_multiple_tx_fifo		= 1,
	.host_rx_fifo_size		= 774,	/* 774 DWORDs */
	.host_nperio_tx_fifo_size	= 256,	/* 256 DWORDs */
	.host_perio_tx_fifo_size	= 512,	/* 512 DWORDs */
	.max_transfer_size		= 65535,
	.max_packet_count		= 511,
	.host_channels			= 8,
	.phy_type			= 1,	/* UTMI */
	.phy_utmi_width			= 8,	/* 8 bits */
	.phy_ulpi_ddr			= 0,	/* Single */
	.phy_ulpi_ext_vbus		= 0,
	.i2c_enable			= 0,
	.ulpi_fs_ls			= 0,
	.host_support_fs_ls_low_power	= 0,
	.host_ls_low_power_phy_clk	= 0,	/* 48 MHz */
	.ts_dline			= 0,
	.reload_ctl			= 0,
	.ahbcfg				= 0x10,
	.uframe_sched			= 0,
	.external_id_pin_ctl		= -1,
	.hibernation			= -1,
};

static const struct dwc2_core_params params_rk3066 = {
	.otg_cap			= 2,	/* non-HNP/non-SRP */
	.otg_ver			= -1,
	.dma_enable			= -1,
	.dma_desc_enable		= 0,
	.dma_desc_fs_enable		= 0,
	.speed				= -1,
	.enable_dynamic_fifo		= 1,
	.en_multiple_tx_fifo		= -1,
	.host_rx_fifo_size		= 525,	/* 525 DWORDs */
	.host_nperio_tx_fifo_size	= 128,	/* 128 DWORDs */
	.host_perio_tx_fifo_size	= 256,	/* 256 DWORDs */
	.max_transfer_size		= -1,
	.max_packet_count		= -1,
	.host_channels			= -1,
	.phy_type			= -1,
	.phy_utmi_width			= -1,
	.phy_ulpi_ddr			= -1,
	.phy_ulpi_ext_vbus		= -1,
	.i2c_enable			= -1,
	.ulpi_fs_ls			= -1,
	.host_support_fs_ls_low_power	= -1,
	.host_ls_low_power_phy_clk	= -1,
	.ts_dline			= -1,
	.reload_ctl			= -1,
	.ahbcfg				= GAHBCFG_HBSTLEN_INCR16 <<
					  GAHBCFG_HBSTLEN_SHIFT,
	.uframe_sched			= -1,
	.external_id_pin_ctl		= -1,
	.hibernation			= -1,
};

static const struct dwc2_core_params params_ltq = {
	.otg_cap			= 2,	/* non-HNP/non-SRP */
	.otg_ver			= -1,
	.dma_enable			= -1,
	.dma_desc_enable		= -1,
	.dma_desc_fs_enable		= -1,
	.speed				= -1,
	.enable_dynamic_fifo		= -1,
	.en_multiple_tx_fifo		= -1,
	.host_rx_fifo_size		= 288,	/* 288 DWORDs */
	.host_nperio_tx_fifo_size	= 128,	/* 128 DWORDs */
	.host_perio_tx_fifo_size	= 96,	/* 96 DWORDs */
	.max_transfer_size		= 65535,
	.max_packet_count		= 128,
	.host_channels			= -1,
	.phy_type			= -1,
	.phy_utmi_width			= -1,
	.phy_ulpi_ddr			= -1,
	.phy_ulpi_ext_vbus		= -1,
	.i2c_enable			= -1,
	.ulpi_fs_ls			= -1,
	.host_support_fs_ls_low_power	= -1,
	.host_ls_low_power_phy_clk	= -1,
	.ts_dline			= -1,
	.reload_ctl			= -1,
	.ahbcfg				= GAHBCFG_HBSTLEN_INCR16 <<
					  GAHBCFG_HBSTLEN_SHIFT,
	.uframe_sched			= -1,
	.external_id_pin_ctl		= -1,
	.hibernation			= -1,
};

#ifdef CONFIG_DWC2_RTK
static const struct dwc2_core_params params_rtk = {
	.otg_cap			= 2,	/* non-HNP/non-SRP */
	.otg_ver			= -1,
	.dma_enable			= -1,
	.dma_desc_enable		= -1,
	.dma_desc_fs_enable 	= -1,
	.speed				= -1,
	.enable_dynamic_fifo		= -1,
	.en_multiple_tx_fifo		= -1,
	.host_rx_fifo_size		= 512,
	.host_nperio_tx_fifo_size	= 256,
	.host_perio_tx_fifo_size	= 256,
	.max_transfer_size		= 65535,
	.max_packet_count		= 511,
	.host_channels			= -1,
	.phy_type			= -1,
	.phy_utmi_width			= -1,
	.phy_ulpi_ddr			= -1,
	.phy_ulpi_ext_vbus		= -1,
	.i2c_enable			= -1,
	.ulpi_fs_ls			= -1,
	.host_support_fs_ls_low_power	= -1,
	.host_ls_low_power_phy_clk	= -1,
	.ts_dline			= -1,
	.reload_ctl			= -1,
	.ahbcfg				= GAHBCFG_HBSTLEN_INCR16 <<
					  GAHBCFG_HBSTLEN_SHIFT,
	.uframe_sched			= -1,
	.external_id_pin_ctl		= -1,
	.hibernation			= -1,
};

static bool usbotg = 0;
static int usb_otg_switch_handler(char *buf)
{
	char *p = NULL;
	if (p = strchr(buf, (int)'1'))
		usbotg = 1;
	return 0;
}
#endif

/*
 * Check the dr_mode against the module configuration and hardware
 * capabilities.
 *
 * The hardware, module, and dr_mode, can each be set to host, device,
 * or otg. Check that all these values are compatible and adjust the
 * value of dr_mode if possible.
 *
 *                      actual
 *    HW  MOD dr_mode   dr_mode
 *  ------------------------------
 *   HST  HST  any    :  HST
 *   HST  DEV  any    :  ---
 *   HST  OTG  any    :  HST
 *
 *   DEV  HST  any    :  ---
 *   DEV  DEV  any    :  DEV
 *   DEV  OTG  any    :  DEV
 *
 *   OTG  HST  any    :  HST
 *   OTG  DEV  any    :  DEV
 *   OTG  OTG  any    :  dr_mode
 */
static int dwc2_get_dr_mode(struct dwc2_hsotg *hsotg)
{
	enum usb_dr_mode mode;

	hsotg->dr_mode = usb_get_dr_mode(hsotg->dev);
	if (hsotg->dr_mode == USB_DR_MODE_UNKNOWN)
		hsotg->dr_mode = USB_DR_MODE_OTG;

	mode = hsotg->dr_mode;

	if (dwc2_hw_is_device(hsotg)) {
		if (IS_ENABLED(CONFIG_USB_DWC2_HOST)) {
			dev_err(hsotg->dev,
				"Controller does not support host mode.\n");
			return -EINVAL;
		}
		mode = USB_DR_MODE_PERIPHERAL;
	} else if (dwc2_hw_is_host(hsotg)) {
		if (IS_ENABLED(CONFIG_USB_DWC2_PERIPHERAL)) {
			dev_err(hsotg->dev,
				"Controller does not support device mode.\n");
			return -EINVAL;
		}
		mode = USB_DR_MODE_HOST;
	} else {
		if (IS_ENABLED(CONFIG_USB_DWC2_HOST))
			mode = USB_DR_MODE_HOST;
		else if (IS_ENABLED(CONFIG_USB_DWC2_PERIPHERAL))
			mode = USB_DR_MODE_PERIPHERAL;
	}

	if (mode != hsotg->dr_mode) {
		dev_warn(hsotg->dev,
			"Configuration mismatch. dr_mode forced to %s\n",
			mode == USB_DR_MODE_HOST ? "host" : "device");

		hsotg->dr_mode = mode;
	}

	return 0;
}

static int __dwc2_lowlevel_hw_enable(struct dwc2_hsotg *hsotg)
{
	struct platform_device *pdev = to_platform_device(hsotg->dev);
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(hsotg->supplies),
				    hsotg->supplies);
	if (ret)
		return ret;

	if (hsotg->clk) {
		ret = clk_prepare_enable(hsotg->clk);
		if (ret)
			return ret;
	}

	if (hsotg->uphy)
		ret = usb_phy_init(hsotg->uphy);
	else if (hsotg->plat && hsotg->plat->phy_init)
		ret = hsotg->plat->phy_init(pdev, hsotg->plat->phy_type);
	else {
		ret = phy_power_on(hsotg->phy);
		if (ret == 0)
			ret = phy_init(hsotg->phy);
	}

	return ret;
}

/**
 * dwc2_lowlevel_hw_enable - enable platform lowlevel hw resources
 * @hsotg: The driver state
 *
 * A wrapper for platform code responsible for controlling
 * low-level USB platform resources (phy, clock, regulators)
 */
int dwc2_lowlevel_hw_enable(struct dwc2_hsotg *hsotg)
{
	int ret = __dwc2_lowlevel_hw_enable(hsotg);

	if (ret == 0)
		hsotg->ll_hw_enabled = true;
	return ret;
}

static int __dwc2_lowlevel_hw_disable(struct dwc2_hsotg *hsotg)
{
	struct platform_device *pdev = to_platform_device(hsotg->dev);
	int ret = 0;

	if (hsotg->uphy)
		usb_phy_shutdown(hsotg->uphy);
	else if (hsotg->plat && hsotg->plat->phy_exit)
		ret = hsotg->plat->phy_exit(pdev, hsotg->plat->phy_type);
	else {
		ret = phy_exit(hsotg->phy);
		if (ret == 0)
			ret = phy_power_off(hsotg->phy);
	}
	if (ret)
		return ret;

	if (hsotg->clk)
		clk_disable_unprepare(hsotg->clk);

	ret = regulator_bulk_disable(ARRAY_SIZE(hsotg->supplies),
				     hsotg->supplies);

	return ret;
}

/**
 * dwc2_lowlevel_hw_disable - disable platform lowlevel hw resources
 * @hsotg: The driver state
 *
 * A wrapper for platform code responsible for controlling
 * low-level USB platform resources (phy, clock, regulators)
 */
int dwc2_lowlevel_hw_disable(struct dwc2_hsotg *hsotg)
{
	int ret = __dwc2_lowlevel_hw_disable(hsotg);

	if (ret == 0)
		hsotg->ll_hw_enabled = false;
	return ret;
}

static int dwc2_lowlevel_hw_init(struct dwc2_hsotg *hsotg)
{
	int i, ret;

	hsotg->reset = devm_reset_control_get_optional(hsotg->dev, "dwc2");
	if (IS_ERR(hsotg->reset)) {
		ret = PTR_ERR(hsotg->reset);
#ifdef CONFIG_DWC2_RTK
		ret = -ENOTSUPP;
#endif
		switch (ret) {
		case -ENOENT:
		case -ENOTSUPP:
			hsotg->reset = NULL;
			break;
		default:
			dev_err(hsotg->dev, "error getting reset control %d\n",
				ret);
			return ret;
		}
	}

	if (hsotg->reset)
		reset_control_deassert(hsotg->reset);

	/* Set default UTMI width */
	hsotg->phyif = GUSBCFG_PHYIF16;

	/*
	 * Attempt to find a generic PHY, then look for an old style
	 * USB PHY and then fall back to pdata
	 */
	hsotg->phy = devm_phy_get(hsotg->dev, "usb2-phy");
	if (IS_ERR(hsotg->phy)) {
		ret = PTR_ERR(hsotg->phy);
		switch (ret) {
		case -ENODEV:
		case -ENOSYS:
			hsotg->phy = NULL;
			break;
		case -EPROBE_DEFER:
			return ret;
		default:
			dev_err(hsotg->dev, "error getting phy %d\n", ret);
			return ret;
		}
	}

	if (!hsotg->phy) {
		hsotg->uphy = devm_usb_get_phy(hsotg->dev, USB_PHY_TYPE_USB2);
		if (IS_ERR(hsotg->uphy)) {
			ret = PTR_ERR(hsotg->uphy);
			switch (ret) {
			case -ENODEV:
			case -ENXIO:
				hsotg->uphy = NULL;
				break;
			case -EPROBE_DEFER:
				return ret;
			default:
				dev_err(hsotg->dev, "error getting usb phy %d\n",
					ret);
				return ret;
			}
		}
	}

	hsotg->plat = dev_get_platdata(hsotg->dev);

	if (hsotg->phy) {
		/*
		 * If using the generic PHY framework, check if the PHY bus
		 * width is 8-bit and set the phyif appropriately.
		 */
		if (phy_get_bus_width(hsotg->phy) == 8)
			hsotg->phyif = GUSBCFG_PHYIF8;
	}

	/* Clock */
	hsotg->clk = devm_clk_get(hsotg->dev, "otg");
	if (IS_ERR(hsotg->clk)) {
		hsotg->clk = NULL;
		dev_dbg(hsotg->dev, "cannot get otg clock\n");
	}

	/* Regulators */
	for (i = 0; i < ARRAY_SIZE(hsotg->supplies); i++)
		hsotg->supplies[i].supply = dwc2_hsotg_supply_names[i];

	ret = devm_regulator_bulk_get(hsotg->dev, ARRAY_SIZE(hsotg->supplies),
				      hsotg->supplies);
	if (ret) {
		dev_err(hsotg->dev, "failed to request supplies: %d\n", ret);
		return ret;
	}
	return 0;
}

/**
 * dwc2_driver_remove() - Called when the DWC_otg core is unregistered with the
 * DWC_otg driver
 *
 * @dev: Platform device
 *
 * This routine is called, for example, when the rmmod command is executed. The
 * device may or may not be electrically present. If it is present, the driver
 * stops device processing. Any resources used on behalf of this device are
 * freed.
 */
static int dwc2_driver_remove(struct platform_device *dev)
{
	struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);

	dwc2_debugfs_exit(hsotg);
	if (hsotg->hcd_enabled)
		dwc2_hcd_remove(hsotg);
	if (hsotg->gadget_enabled)
		dwc2_hsotg_remove(hsotg);

	if (hsotg->ll_hw_enabled)
		dwc2_lowlevel_hw_disable(hsotg);

	if (hsotg->reset)
		reset_control_assert(hsotg->reset);

	return 0;
}

/**
 * dwc2_driver_shutdown() - Called on device shutdown
 *
 * @dev: Platform device
 *
 * In specific conditions (involving usb hubs) dwc2 devices can create a
 * lot of interrupts, even to the point of overwhelming devices running
 * at low frequencies. Some devices need to do special clock handling
 * at shutdown-time which may bring the system clock below the threshold
 * of being able to handle the dwc2 interrupts. Disabling dwc2-irqs
 * prevents reboots/poweroffs from getting stuck in such cases.
 */
static void dwc2_driver_shutdown(struct platform_device *dev)
{
	struct dwc2_hsotg *hsotg = platform_get_drvdata(dev);

	disable_irq(hsotg->irq);
}

static const struct of_device_id dwc2_of_match_table[] = {
	{ .compatible = "brcm,bcm2835-usb", .data = &params_bcm2835 },
	{ .compatible = "hisilicon,hi6220-usb", .data = &params_hi6220 },
	{ .compatible = "rockchip,rk3066-usb", .data = &params_rk3066 },
	{ .compatible = "lantiq,arx100-usb", .data = &params_ltq },
	{ .compatible = "lantiq,xrx200-usb", .data = &params_ltq },
#ifdef CONFIG_DWC2_RTK
	{ .compatible = "snps,dwc2", .data = &params_rtk },
#else
	{ .compatible = "snps,dwc2", .data = NULL },
#endif
	{ .compatible = "samsung,s3c6400-hsotg", .data = NULL},
	{},
};
MODULE_DEVICE_TABLE(of, dwc2_of_match_table);

#ifdef CONFIG_DWC2_RTK
static inline int rtk_otg_initial(void)
{
	if (!(rtd_inl(SYS_REG_SYS_SRST3_reg) &
		    SYS_REG_SYS_SRST3_rstn_usb2_phy_p3_mask)) {
	    pr_err("USB2 PHY must be initialized in XHCI platform driver\n");
	    return -1;
	}

	if (!(rtd_inl(SYS_REG_SYS_SRST2_reg) & SYS_REG_SYS_SRST2_rstn_usb_mask)) {
	    pr_err("USB MAC must initialized in XHCI platform driver\n");
	    return -1;
	}

	// enable interrupt
	rtd_maskl(SYS_REG_INT_CTRL_SCPU_reg,
		~(SYS_REG_INT_CTRL_SCPU_otg_int_scpu_routing_en_mask),
		SYS_REG_INT_CTRL_SCPU_otg_int_scpu_routing_en_mask);
	udelay(100);
	printk("enable otg interrupt\n");

	rtd_setbits(0xb8098840, 0x1);
	udelay(100);
	printk("OTG_enable, 0xb8098840 = 0x%08x\n", rtd_inl(0xb8098840));

	rtd_outl(0xb8098844, 0x010E01FE);
	//rtd_outl(0xb8098844, 0x01EC0180);  // host mode parameter
	udelay(100);
	printk("0xb8098844=0x%08x\n", rtd_inl(0xb8098844));

	rtd_setbits(0xb8098848, 0x1 << 13);
	udelay(100);
	printk("0xb8098848=0x%08x\n", rtd_inl(0xb8098848));

	return 0;
}
#endif
/**
 * dwc2_driver_probe() - Called when the DWC_otg core is bound to the DWC_otg
 * driver
 *
 * @dev: Platform device
 *
 * This routine creates the driver components required to control the device
 * (core, HCD, and PCD) and initializes the device. The driver components are
 * stored in a dwc2_hsotg structure. A reference to the dwc2_hsotg is saved
 * in the device private data. This allows the driver to access the dwc2_hsotg
 * structure on subsequent calls to driver methods for this device.
 */
static int dwc2_driver_probe(struct platform_device *dev)
{
	const struct of_device_id *match;
	const struct dwc2_core_params *params;
	struct dwc2_core_params defparams;
	struct dwc2_hsotg *hsotg;
	struct resource *res;
	int retval;
	int irq;
#ifdef CONFIG_DWC2_RTK
	retval = rtk_otg_initial();
	if (retval)
	    return retval;
#endif
	match = of_match_device(dwc2_of_match_table, &dev->dev);
	if (match && match->data) {
		params = match->data;
	} else {
		/* Default all params to autodetect */
		dwc2_set_all_params(&defparams, -1);
		params = &defparams;

		/*
		 * Disable descriptor dma mode by default as the HW can support
		 * it, but does not support it for SPLIT transactions.
		 * Disable it for FS devices as well.
		 */
		defparams.dma_desc_enable = 0;
		defparams.dma_desc_fs_enable = 0;
		printk("DWC2 can't find device node\n");
	}

	hsotg = devm_kzalloc(&dev->dev, sizeof(*hsotg), GFP_KERNEL);
	if (!hsotg)
		return -ENOMEM;

	hsotg->dev = &dev->dev;

	/*
	 * Use reasonable defaults so platforms don't have to provide these.
	 */
	if (!dev->dev.dma_mask)
		dev->dev.dma_mask = &dev->dev.coherent_dma_mask;
	retval = dma_set_coherent_mask(&dev->dev, DMA_BIT_MASK(32));
	if (retval)
		return retval;

	res = platform_get_resource(dev, IORESOURCE_MEM, 0);
	hsotg->regs = devm_ioremap_resource(&dev->dev, res);
	if (IS_ERR(hsotg->regs))
		return PTR_ERR(hsotg->regs);

	dev_dbg(&dev->dev, "mapped PA %08lx to VA %p\n",
		(unsigned long)res->start, hsotg->regs);

	retval = dwc2_lowlevel_hw_init(hsotg);
	if (retval)
		return retval;

	spin_lock_init(&hsotg->lock);

	hsotg->core_params = devm_kzalloc(&dev->dev,
				sizeof(*hsotg->core_params), GFP_KERNEL);
	if (!hsotg->core_params)
		return -ENOMEM;

	dwc2_set_all_params(hsotg->core_params, -1);

	hsotg->irq = platform_get_irq(dev, 0);
#ifdef CONFIG_DWC2_RTK
	hsotg->irq =  IRQ_GET_KERNEL_IRQ_NUM(53);
#endif
	if (hsotg->irq < 0) {
		dev_err(&dev->dev, "missing IRQ resource\n");
		return hsotg->irq;
	}

	dev_dbg(hsotg->dev, "registering common handler for irq%d\n",
		hsotg->irq);
	retval = devm_request_irq(hsotg->dev, hsotg->irq,
				  dwc2_handle_common_intr, IRQF_SHARED,
				  dev_name(hsotg->dev), hsotg);
	if (retval)
		return retval;

	retval = dwc2_lowlevel_hw_enable(hsotg);
	if (retval)
		return retval;

	retval = dwc2_get_dr_mode(hsotg);
	if (retval)
		goto error;

	/*
	 * Reset before dwc2_get_hwparams() then it could get power-on real
	 * reset value form registers.
	 */
	dwc2_core_reset_and_force_dr_mode(hsotg);

	/* Detect config values from hardware */
	retval = dwc2_get_hwparams(hsotg);
	if (retval)
		goto error;

	/* Validate parameter values */
	dwc2_set_parameters(hsotg, params);

	dwc2_force_dr_mode(hsotg);

	if (hsotg->dr_mode != USB_DR_MODE_HOST) {
		retval = dwc2_gadget_init(hsotg, hsotg->irq);
		if (retval)
			goto error;
		hsotg->gadget_enabled = 1;
	}

	if (hsotg->dr_mode != USB_DR_MODE_PERIPHERAL) {
		retval = dwc2_hcd_init(hsotg, hsotg->irq);
		if (retval) {
			if (hsotg->gadget_enabled)
				dwc2_hsotg_remove(hsotg);
			goto error;
		}
		hsotg->hcd_enabled = 1;
	}

	platform_set_drvdata(dev, hsotg);

	dwc2_debugfs_init(hsotg);

	/* Gadget code manages lowlevel hw on its own */
	if (hsotg->dr_mode == USB_DR_MODE_PERIPHERAL)
		dwc2_lowlevel_hw_disable(hsotg);
	printk("RTK DWC2 HSOTG driver probe success\n");

#ifdef CONFIG_USB_USER_RESUME
	dev->dev.power.is_userresume = true;
#endif
#ifdef CONFIG_ARCH_RTK289X
	device_enable_async_suspend(&dev->dev);
#endif

	return 0;

error:
	dwc2_lowlevel_hw_disable(hsotg);
	printk("RTK DWC2 HSOTG driver probe fail\n");
	return retval;
}

static int __maybe_unused dwc2_suspend(struct device *dev)
{
	struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
	int ret = 0;

	if (dwc2_is_device_mode(dwc2))
		dwc2_hsotg_suspend(dwc2);

	if (dwc2->ll_hw_enabled)
		ret = __dwc2_lowlevel_hw_disable(dwc2);

	return ret;
}

#ifdef CONFIG_USB_XHCI_PLATFORM
extern struct platform_device *get_hci_platform_device(void);
#endif

static int __maybe_unused dwc2_resume(struct device *dev)
{
	struct dwc2_hsotg *dwc2 = dev_get_drvdata(dev);
	int ret = 0;
#ifdef CONFIG_USB_XHCI_PLATFORM
	struct platform_device *xhci_platform_dev = get_hci_platform_device();

	if (xhci_platform_dev->dev.power.is_suspended) {
		device_pm_wait_for_dev(dev, &xhci_platform_dev->dev);
	}
#endif

#ifdef CONFIG_DWC2_RTK
	ret = rtk_otg_initial();
	if (ret)
	    return ret;
#endif

	if (dwc2->ll_hw_enabled) {
		ret = __dwc2_lowlevel_hw_enable(dwc2);
		if (ret)
			return ret;
	}

	if (dwc2_is_device_mode(dwc2))
		ret = dwc2_hsotg_resume(dwc2);

	return ret;
}

static const struct dev_pm_ops dwc2_dev_pm_ops = {
	SET_SYSTEM_SLEEP_PM_OPS(dwc2_suspend, dwc2_resume)
};

static struct platform_driver dwc2_platform_driver = {
	.driver = {
#ifdef CONFIG_DWC2_RTK
		.name ="rtk,dwc2",
#else
		.name = dwc2_driver_name,
#endif
		.of_match_table = dwc2_of_match_table,
		.pm = &dwc2_dev_pm_ops,
	},
	.probe = dwc2_driver_probe,
	.remove = dwc2_driver_remove,
	.shutdown = dwc2_driver_shutdown,
};
#ifdef CONFIG_DWC2_RTK
static __init rtkotg_init(void)
{
    int ret = 0;

#ifndef MODULE
	if (!usbotg) {
		pr_err("OTG is not enable. Use command: \"usbotg on\" in bootcode to enable it! \n");
		return -EPERM;
	}
#endif

    ret = platform_driver_probe(&dwc2_platform_driver, dwc2_driver_probe);
    if (ret < 0) {
		pr_err("RTK DWC2 HSOTG Driver install fail!!!\n");
    }

    return ret;
}

static void __exit rtkotg_exit(void)
{
    rtd_outl(0xb8098840, 0x0);
    platform_driver_unregister(&dwc2_platform_driver);
    pr_notice("Remove RTK DWC2 HSOTG Driver\n");
}

late_initcall(rtkotg_init);  // must wait for USB XHCI Platform
module_exit(rtkotg_exit);
#else
module_platform_driver(dwc2_platform_driver);
#endif

MODULE_DESCRIPTION("DESIGNWARE HS OTG Platform Glue");
MODULE_AUTHOR("Matthijs Kooijman <matthijs@stdin.nl>");
MODULE_LICENSE("Dual BSD/GPL");

#ifdef CONFIG_DWC2_RTK
__setup("usbotg", usb_otg_switch_handler);
#endif
