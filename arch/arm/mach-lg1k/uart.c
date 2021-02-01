#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/amba/pl08x.h>
#include <linux/amba/serial.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_address.h>

#include <mach/lg1k.h>

static void uart1_mux_set(int val)
{
	struct device_node *np;
	void __iomem *base;
	unsigned long ctr58;

	np = of_find_node_by_name(NULL, "chip_ctrl");
	base = of_iomap(np, 0);

	ctr58 = readl_relaxed(base + REG(58));
	ctr58 &= ~(0x07 << 25);
	ctr58 |= ((val & 0x07) << 25);
	writel_relaxed(ctr58, base + REG(58));
}

static void uart1_init(void)
{
	/* CPU UART1 */
	uart1_mux_set(0x07);
}

static void uart1_exit(void)
{
	msleep(1);
	/* TrustZone UART */
	uart1_mux_set(0x00);
}

struct amba_pl011_data uart1_data = {
	.init = uart1_init,
	.exit = uart1_exit,
};
