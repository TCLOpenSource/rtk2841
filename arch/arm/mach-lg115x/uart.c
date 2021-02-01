#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/amba/pl08x.h>
#include <linux/amba/serial.h>
#include <linux/init.h>
#include <linux/delay.h>

#include <mach/resource.h>

#include "uart.h"

#ifndef CONFIG_LG1311_A0
#define CTR(n)	((n) << 2)

static void uart1_mux_set(int val)
{
	void __iomem *base = MMIO_P2V(TOP_CTRL_BASE) + CTR(58);
	unsigned long ctr58;

	ctr58 = readl_relaxed(base);
	ctr58 &= ~(0x07 << 25);
	ctr58 |= ((val & 0x07) << 25);
	writel_relaxed(ctr58, base);
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

static struct amba_pl011_data uart1_data = {
	.init = uart1_init,
	.exit = uart1_exit,
};
#else
static void uart1_exit(void){}
static struct amba_pl011_data uart1_data = {
};
#endif

static AMBA_APB_DEVICE(uart0, "uart0", 0, UART0_BASE, UART0_IRQS, NULL);
static AMBA_APB_DEVICE(uart1, "uart1", 0, UART1_BASE, UART1_IRQS, &uart1_data);
static AMBA_APB_DEVICE(uart2, "uart2", 0, UART2_BASE, UART2_IRQS, NULL);

void __init lg115x_init_uart(void)
{
	uart1_exit();

	amba_device_register(&uart0_device, &iomem_resource);
	amba_device_register(&uart1_device, &iomem_resource);
	amba_device_register(&uart2_device, &iomem_resource);
}
