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
/*
 * Part of SS Function Control Registers based on "SuperSpeed USB 3.0 PHY for
 * TSMC 40-nm LP 1.1/2.5 V Databook"
 * RX_OVRD_IN_HI register for rx equalizer tuning
 */
#define RX_OVRD_IN_HI 0x1006
#define RX_EQ_OVRD_MASK (1 << 11)
#define RX_EQ_MASK (7 << 8)
#define RX_EQ_EN_OVRD_MASK (1 << 7)
#define RX_EQ_EN_MASK (1 << 6)
#define CR_ACK 0x1
#define CR_NAK 0x0

static int lg1k_usb3_phy_init_v2(struct lg1k_usbphy *lgphy)
{
	union usb3_phy_param_0_union parm0;
	union usb3_phy_param_1_union parm1;
	union usb3_phy_param_2_union parm2;
	union usb3_phy_param_3_union parm3;
	union usb3_phy_param_6_union parm6;

	dev_info(lgphy->dev, "lg1k-usb3phy(v2) init\n");

	parm0.val = readl(lgphy->phy_reg + phy_offset(3, param0));
	parm1.val = readl(lgphy->phy_reg + phy_offset(3, param1));
	parm2.val = readl(lgphy->phy_reg + phy_offset(3, param2));
	parm3.val = readl(lgphy->phy_reg + phy_offset(3, param3));
	parm6.val = readl(lgphy->phy_reg + phy_offset(3, param6));

	parm0.reg.phy_lane0_ext_pclk_req = 1;
	writel(parm0.val, lgphy->phy_reg + phy_offset(3, param0));

	parm1.reg.phy_ssc_range = 1;
	parm1.reg.phy_mpll_multiplier = 0;
	parm1.reg.phy_ssc_ref_clk_sel = 0;
	writel(parm1.val, lgphy->phy_reg + phy_offset(3, param1));

	parm3.reg.phy_pcs_tx_deemph_6db = 0x23;
	parm3.reg.phy_pcs_tx_swing_full = 0x7F;
	parm3.reg.phy_lane0_tx_term_offset= 0x0;
	parm3.reg.phy_los_bias = 0x5;
	writel(parm3.val, lgphy->phy_reg + phy_offset(3, param3));

	parm2.reg.phy_tx_vboost_lvl = 0x4;
	parm2.reg.phy_txpreempamptune = 0x3;
	parm2.reg.phy_los_level = 0x7;
	writel(parm2.val, lgphy->phy_reg + phy_offset(3, param2));

	parm6.reg.phy_pcs_rx_los_mask_val = 0x0;
	writel(parm6.val, lgphy->phy_reg + phy_offset(3, param6));

	return 0;
}

static int lg1k_usb3_phy_init_v1(struct lg1k_usbphy *lgphy)
{
	union usb3_phy_param_0_union parm0;
	union usb3_phy_param_1_union parm1;
	union usb3_phy_param_2_union parm2;
	union usb3_phy_param_3_union parm3;
	union usb3_phy_param_6_union parm6;

	dev_info(lgphy->dev, "lg1k-usb3phy init\n");

	parm0.val = readl(lgphy->phy_reg + phy_offset(3, param0));
	parm1.val = readl(lgphy->phy_reg + phy_offset(3, param1));
	parm2.val = readl(lgphy->phy_reg + phy_offset(3, param2));
	parm3.val = readl(lgphy->phy_reg + phy_offset(3, param3));
	parm6.val = readl(lgphy->phy_reg + phy_offset(3, param6));

	parm0.reg.phy_lane0_ext_pclk_req = 1;
	writel(parm0.val, lgphy->phy_reg + phy_offset(3, param0));

	parm1.reg.phy_ssc_range = 1;
	writel(parm1.val, lgphy->phy_reg + phy_offset(3, param1));

	parm3.reg.phy_pcs_tx_swing_full = 0x7F;
	parm3.reg.phy_los_bias = 0x5;
	writel(parm3.val, lgphy->phy_reg + phy_offset(3, param3));

	parm2.reg.phy_tx_vboost_lvl = 0x4;
	parm2.reg.phy_txpreempamptune = 0x3;
	parm2.reg.phy_los_level = 0x11;
	writel(parm2.val, lgphy->phy_reg + phy_offset(3, param2));

	parm6.reg.phy_pcs_rx_los_mask_val = 0x0;
	writel(parm6.val, lgphy->phy_reg + phy_offset(3, param6));

	return 0;
}

static int lg1k_usb3_phy_init(struct lg1k_usbphy *lgphy)
{
	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error phy reg iomem\n");
		return -EFAULT;
	}

	if (lgphy->syntop)
		writel(lgphy->syntop_val, lgphy->syntop);

	if (of_device_is_compatible(lgphy->dev->of_node,
					"lge,lg1k-usb3phy-v2")) {
		return lg1k_usb3_phy_init_v2(lgphy);
	}

	return lg1k_usb3_phy_init_v1(lgphy);
}

static int lg1k_usb3_reset(struct lg1k_usbphy *lgphy)
{
	union usb3_phy_reset_union phy_reset;
	union usb3_host_reset_union host_reset;

	if (!lgphy->phy_reg || !lgphy->host_reg) {
		dev_err(lgphy->phy_reg, "error reg iomem\n");
		return -EFAULT;
	}

	phy_reset.val = readl(lgphy->phy_reg + phy_offset(3, reset));
	host_reset.val = readl(lgphy->host_reg + host_offset(3, reset));

	phy_reset.reg.usb3_phy_reset = 1;
	writel(phy_reset.val, lgphy->phy_reg + phy_offset(3, reset));

	host_reset.reg.usb3_host_bus_reset = 1;
	host_reset.reg.usb3_host_core_reset = 1;
	writel(host_reset.val, lgphy->host_reg + host_offset(3, reset));

	return 0;
}

static int lg1k_usb3_gbl_setup(struct lg1k_usbphy *lgphy)
{
	unsigned int val;
	unsigned int vers;
	int utmi_clk_set = 0;

	if (!lgphy->base_addr) {
		dev_err(lgphy->dev, "error base addr iomem\n");
		return -EFAULT;
	}

	if (of_device_is_compatible(lgphy->dev->of_node,
					"lge,lg1k-usb3phy-v2")) {
		utmi_clk_set = lgphy->utmi_val;
	} else
		utmi_clk_set = 1;

	/* gbl_reg = base_addr + 0xC000 */
	val = readl(lgphy->gbl_reg + 0x100);
	val |= (0x3 << 2);
	writel(val, lgphy->gbl_reg + 0x100);
	val = 0x0;
	writel(val, lgphy->gbl_reg + 0x10C);

	val = readl(lgphy->gbl_reg + 0x120);
	vers = val;
	dev_dbg(lgphy->dev, "SNPSID : 0x%08X\n", val);
	if ((vers & 0xFFFF) >= 0x280A) {
		/* v2.80a : GUCTL1 - NAK_PER_ENH_HS */
		val = readl(lgphy->gbl_reg + 0x11C);
		val |= (0x1 << 18);
		writel(val, lgphy->gbl_reg + 0x11C);
		dev_dbg(lgphy->dev, "GUCTL1 : 0x%08X\n", val);
	}

	val = readl(lgphy->gbl_reg + 0x12C);
	val |= (0x1 << 14);
	writel(val, lgphy->gbl_reg + 0x12C);

	if (utmi_clk_set && ((vers & 0xFFFF) >= 0x280A)) {
		val = readl(lgphy->gbl_reg + 0x200);
		val &= ~(1<<3);
		writel(val, lgphy->gbl_reg + 0x200);
	} else {
		val = readl(lgphy->gbl_reg + 0x200);
		val |= (0x1 << 3);
		writel(val, lgphy->gbl_reg + 0x200);
	}

	return 0;
}

static inline void lg1k_usb3_wait_cr_ack(void __iomem *ack_addr, int ack_val)
{
	long cnt = 0;
	long timeout = 10 * 1000;
	union usb3_phy_param_5_union parm5;

	while (cnt < timeout) {
		parm5.val = readl(ack_addr);
		if (parm5.reg.phy_cr_ack == ack_val)
			break;
		cnt++;
		udelay(1);
	}
}

static void lg1k_usb3_cr_addr_capture(struct lg1k_usbphy *lgphy, u16 addr)
{
	union usb3_phy_param_4_union parm4;

	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error phy reg iomem\n");
		return;
	}

	parm4.val = readl(lgphy->phy_reg + phy_offset(3, param4));

	parm4.reg.phy_cr_data_in = addr;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));

	parm4.reg.phy_cr_cap_addr = 0x1;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_ACK);

	parm4.reg.phy_cr_cap_addr = 0x0;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_NAK);
}

static u16 lg1k_usb3_cr_read(struct lg1k_usbphy *lgphy, u16 addr)
{
	union usb3_phy_param_4_union parm4;
	union usb3_phy_param_5_union parm5;
	u16 val;

	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error phy reg iomem\n");
		return 0;
	}

	lg1k_usb3_cr_addr_capture(lgphy, addr);

	parm4.val = readl(lgphy->phy_reg + phy_offset(3, param4));

	parm4.reg.phy_cr_read = 1;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_ACK);

	parm5.val = readl(lgphy->phy_reg + phy_offset(3, param5));
	val = parm5.reg.phy_cr_data_out;

	parm4.reg.phy_cr_read = 0;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_NAK);

	return val;
}

static void lg1k_usb3_cr_write(struct lg1k_usbphy *lgphy, u16 addr, u16 val)
{
	union usb3_phy_param_4_union parm4;

	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error phy reg iomem\n");
		return;
	}

	lg1k_usb3_cr_addr_capture(lgphy, addr);

	parm4.val = readl(lgphy->phy_reg + phy_offset(3, param4));

	parm4.reg.phy_cr_data_in = val;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));

	parm4.reg.phy_cr_cap_data = 1;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_ACK);
	parm4.reg.phy_cr_cap_data = 0;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_NAK);

	parm4.reg.phy_cr_write = 1;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_ACK);
	parm4.reg.phy_cr_write = 0;
	writel(parm4.val, lgphy->phy_reg + phy_offset(3, param4));
	lg1k_usb3_wait_cr_ack(lgphy->phy_reg + phy_offset(3, param5), CR_NAK);
}

/*
 * EQ1 : 0x100(H15A0 EV B'd)
 * EQ2 : 0x200(H15A1 EV B'd)
 * EQ3 : 0x300
 * EQ4 : 0x400(H15A1 System B'd)
 * EQ5 : 0x500(H15A0 System B'd)
*/
static int lg1k_usb3_rx_equalizer(struct lg1k_usbphy *lgphy)
{
	u16 val;
	u16 addr = RX_OVRD_IN_HI;

	if (!lgphy->phy_reg) {
		dev_err(lgphy->phy_reg, "error phy reg iomem\n");
		return -EFAULT;
	}

	if (lgphy->rx_eq_val) {
		val = (u16)lgphy->rx_eq_val;
		if (val & RX_EQ_MASK)
			val |= RX_EQ_OVRD_MASK;
		if (val & RX_EQ_EN_MASK)
			val |= RX_EQ_EN_OVRD_MASK;

		lg1k_usb3_cr_write(lgphy, addr, val);
		val = lg1k_usb3_cr_read(lgphy, addr);

		if ((val & RX_EQ_MASK) != (u16)lgphy->rx_eq_val) {
			dev_err(lgphy->dev, "rx_eq_val=0x%x, RX_EQ=0x%x\n",
					lgphy->rx_eq_val, val & RX_EQ_MASK);
			return -EFAULT;
		}
	} else {
		dev_warn(lgphy->dev, "no rx equalizer setting\n");
	}

	return 0;
}

#ifdef LG1K_SUPPORT_QUIRK_CHIP
static int lg1k_usb3_port_up(struct usb_phy *phy)
{
	struct lg1k_usbphy *lgphy;
	unsigned int val;

	lgphy = phy_to_lgphy(phy);

	if (!lgphy || !lgphy->base_addr)
		return -EFAULT;

	/* gbl_reg = base_addr + 0xC000 */
	val = readl(lgphy->gbl_reg + 0x2C0);
	val &= ~(1 << 31);
	writel(val, lgphy->gbl_reg + 0x2C0);

	msleep(100);

	val = readl(lgphy->base_addr + 0x420);
	val |= (1 << 9);
	writel(val, lgphy->base_addr + 0x420);

	return 0;

}

static int lg1k_usb3_port_reset(struct usb_phy *phy)
{
	struct lg1k_usbphy *lgphy;
	unsigned int val;
	union usb3_phy_reset_union phy_rst;

	lgphy = phy_to_lgphy(phy);

	if (!lgphy || !lgphy->base_addr || !lgphy->phy_reg)
		return -EFAULT;

	val = readl(base+0x420);
	val &= ~(1<<9);
	writel(val, lgphy->base + 0x420);
	msleep(100);

	/* gbl_reg = base_addr + 0xC000 */
	val = readl(lgphy->gbl_reg + 0x2C0);
	val |= (1 << 31);

	phy_rst.val = readl(lgphy->phy_reg + phy_offset(3, reset));
	phy_rst.reg.usb3_phy_reset = 0;
	writel(phy_rst.val, lgphy->phy_reg + phy_offset(3, reset));

	return 0;
}

static void lg1k_usb3_port_start(struct usb_phy *phy)
{
	struct lg1k_usbphy *lgphy;
	union usb3_phy_reset_union phy_rst;

	lgphy = phy_to_lgphy(phy);

	if (!lgphy || !lgphy->phy_reg)
		return -EFAULT;

	phy_rst.val = readl(lgphy->phy_reg + phy_offset(3, reset));
	phy_rst.reg.usb3_phy_reset = 1;
	writel(phy_rst.val, lgphy->phy_reg + phy_offset(3, reset));
}
#endif /* LG1K_SUPPORT_QUIRK_CHIP */
static int lg1k_usb3phy_init(struct usb_phy *phy)
{
	struct lg1k_usbphy *lgphy;

	lgphy = phy_to_lgphy(phy);

	if (lgphy->hw_initialized) {
		dev_info(lgphy->dev, "phy is already initialized\n");
		return 0;
	}

	lg1k_usb3_phy_init(lgphy);
	lg1k_usb3_reset(lgphy);
	lg1k_usb3_gbl_setup(lgphy);
	if (lg1k_usb3_rx_equalizer(lgphy))
		dev_warn(lgphy->dev, "rx eq setting fail.. continue..\n");

	lgphy->hw_initialized = 1;

	return 0;
}

static int lg1k_usb3_probe(struct platform_device *pdev)
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
	lgphy->phy.label	= "lg1k-usb3phy";
	lgphy->phy.type		= USB_PHY_TYPE_USB3;
	lgphy->phy.init		= lg1k_usb3phy_init;
	lgphy->phy.dev		= lgphy->dev;

	platform_set_drvdata(pdev, lgphy);
	device_enable_async_suspend(lgphy->dev);
	dev_info(lgphy->dev, "%s:add usb phy\n", __func__);

	return usb_add_phy_dev(&lgphy->phy);
}

static int lg1k_usb3_remove(struct platform_device *pdev)
{
	struct lg1k_usbphy *lgphy = platform_get_drvdata(pdev);

	dev_info(lgphy->dev, "remove phy\n");

	lg1k_usbphy_remove(lgphy);

	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int lg1k_usb3_suspend_late(struct device *dev)
{
	struct platform_device *pdev;
	struct lg1k_usbphy *lgphy;

	pdev = to_platform_device(dev);
	lgphy = platform_get_drvdata(pdev);

	dev_info(dev, "suspend_late phy\n");

	lgphy->hw_initialized = 0;

	return 0;
}

static int lg1k_usb3_resume(struct device *dev)
{
	struct platform_device *pdev;
	struct lg1k_usbphy *lgphy;

	pdev = to_platform_device(dev);
	lgphy = platform_get_drvdata(pdev);

	if (lgphy->hw_initialized) {
		dev_info(lgphy->dev, "phy is already initialized\n");
		return 0;
	}

	dev_info(dev, "resume phy\n");

	lg1k_usbphy_set_vbus(&lgphy->phy, true);

	lg1k_usb3_phy_init(lgphy);
	lg1k_usb3_reset(lgphy);
	lg1k_usb3_gbl_setup(lgphy);
	if (lg1k_usb3_rx_equalizer(lgphy))
		dev_warn(lgphy->dev, "rx eq setting fail.. continue..\n");

	lgphy->hw_initialized = 1;

	return 0;
}

static int lg1k_usb3_resume_early(struct device *dev)
{
	return 0;
}

static const struct dev_pm_ops lg1k_usb3_pm_ops = {
	.resume = lg1k_usb3_resume,
	SET_LATE_SYSTEM_SLEEP_PM_OPS(lg1k_usb3_suspend_late,
						lg1k_usb3_resume_early)
};
#define DEV_PM_OPS	(&lg1k_usb3_pm_ops)
#else
#define DEV_PM_OPS	NULL
#endif /* CONFIG_PM_SLEEP */

static struct platform_device_id lg1k_usb3_driver_ids[] = {
	{ .name = "lg1k-usb3phy", },
	{ .name = "lg1k-usb3phy-v2", },
	{},
};
MODULE_DEVICE_TABLE(platform, lg1k_usb3_driver_ids);

static struct platform_driver lg1k_usb3phy_driver = {
	.probe		= lg1k_usb3_probe,
	.remove		= lg1k_usb3_remove,
	.id_table	= lg1k_usb3_driver_ids,
	.driver	= {
		.name = "lg1k-usb3phy",
		.pm = DEV_PM_OPS,
	},
};
module_platform_driver(lg1k_usb3phy_driver);

MODULE_DESCRIPTION("LG DTV USB 3.0 phy controller");
MODULE_AUTHOR("Shinhoe Kim <shinhoe.kim@lge.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:lg1k-usb3phy");
