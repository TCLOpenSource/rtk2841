#ifndef __ASM_RESOURCE_LG1156_H
#define __ASM_RESOURCE_LG1156_H

/*
 * Cortex-A15 MPcore devices
 */

#define MPCORE_PERIPH_BASE	0xf0000000
#define MPCORE_GIC_DIST_BASE	0xf0001000
#define MPCORE_GIC_CPU_BASE	0xf0002000

/*
 * external AMBA bus devices
 */

#define TOP_CTRL_BASE	0xc001c000
#define XHCI2_BASE	0xf2000000
#define XHCI3_BASE	0xf3000000
#define MACB_BASE	0xf4010000
#define XHCI0_BASE	0xf5000000
#define XHCI1_BASE	0xf6000000
#define TIMER_BASE	0xfd100000
#define TIMER_64_BASE	0xfd110000
#define WDOG_BASE	0xfd200000
#define CPU_CTRL_BASE	0xfd300000
#define GPIO_0_BASE	0xfd400000
#define GPIO_1_BASE	0xfd410000
#define GPIO_2_BASE	0xfd420000
#define GPIO_3_BASE	0xfd430000
#define GPIO_4_BASE	0xfd440000
#define GPIO_5_BASE	0xfd450000
#define GPIO_6_BASE	0xfd460000
#define GPIO_7_BASE	0xfd470000
#define GPIO_8_BASE	0xfd480000
#define GPIO_9_BASE	0xfd490000
#define GPIO10_BASE	0xfd4a0000
#define GPIO11_BASE	0xfd4b0000
#define GPIO12_BASE	0xfd4c0000
#define GPIO13_BASE	0xfd4d0000
#define GPIO14_BASE	0xfd4e0000
#define GPIO15_BASE	0xfd4f0000
#define GPIO16_BASE	0xfd500000
#define GPIO17_BASE	0xfd510000
#define UART0_BASE	0xfe000000
#define UART1_BASE	0xfe100000
#define UART2_BASE	0xfe200000
#define SPI0_BASE	0xfe800000
#define SPI1_BASE	0xfe900000
#define SDHCI_BASE	0xff000000
#define DMAC_BASE	0xff200000
#define SRAM_BASE	0xfff00000

#define UART0_IRQ	32
#define UART1_IRQ	33
#define UART2_IRQ	34
#define SPI0_IRQ	35
#define SPI1_IRQ	36
#define TIMER_IRQ	38
#define WDOG_IRQ	39
#define GPIO_0_IRQ	40
#define GPIO_1_IRQ	40
#define GPIO_2_IRQ	40
#define GPIO_3_IRQ	41
#define GPIO_4_IRQ	41
#define GPIO_5_IRQ	41
#define GPIO_6_IRQ	42
#define GPIO_7_IRQ	42
#define GPIO_8_IRQ	42
#define GPIO_9_IRQ	43
#define GPIO10_IRQ	43
#define GPIO11_IRQ	43
#define I2C0_IRQ	44
#define I2C1_IRQ	45
#define I2C2_IRQ	46
#define I2C3_IRQ	47
#define DMAC_IRQ	48
#define SDHCI_IRQ	50
#define XHCI0_IRQ	51
#define XHCI1_IRQ	53
#define XHCI2_IRQ	55
#define TIMER_64_IRQ	59
#define I2C4_IRQ	62
#define I2C5_IRQ	63
#define I2C6_IRQ	64
#define I2C7_IRQ	65
#define I2C8_IRQ	66
#define I2C9_IRQ	67
#define GPIO12_IRQ	68
#define GPIO13_IRQ	68
#define GPIO14_IRQ	68
#define GPIO15_IRQ	69
#define GPIO16_IRQ	69
#define GPIO17_IRQ	69
#define MACB_IRQ	70
#define XHCI3_IRQ	73
#define PMU0_IRQ	86
#define PMU1_IRQ	87

#define UART0_IRQS	{ UART0_IRQ }
#define UART1_IRQS	{ UART1_IRQ }
#define UART2_IRQS	{ UART2_IRQ }
#define SPI0_IRQS	{ SPI0_IRQ }
#define SPI1_IRQS	{ SPI1_IRQ }
#define WDOG_IRQS	{ WDOG_IRQ }
#define GPIO_0_IRQS	{ GPIO_0_IRQ }
#define GPIO_1_IRQS	{ GPIO_1_IRQ }
#define GPIO_2_IRQS	{ GPIO_2_IRQ }
#define GPIO_3_IRQS	{ GPIO_3_IRQ }
#define GPIO_4_IRQS	{ GPIO_4_IRQ }
#define GPIO_5_IRQS	{ GPIO_5_IRQ }
#define GPIO_6_IRQS	{ GPIO_6_IRQ }
#define GPIO_7_IRQS	{ GPIO_7_IRQ }
#define GPIO_8_IRQS	{ GPIO_8_IRQ }
#define GPIO_9_IRQS	{ GPIO_9_IRQ }
#define GPIO10_IRQS	{ GPIO10_IRQ }
#define GPIO11_IRQS	{ GPIO11_IRQ }
#define DMAC_IRQS	{ DMAC_IRQ }
#define GPIO12_IRQS	{ GPIO12_IRQ }
#define GPIO13_IRQS	{ GPIO13_IRQ }
#define GPIO14_IRQS	{ GPIO14_IRQ }
#define GPIO15_IRQS	{ GPIO15_IRQ }
#define GPIO16_IRQS	{ GPIO16_IRQ }
#define GPIO17_IRQS	{ GPIO17_IRQ }

#endif	/* __ASM_RESOURCE_LG1156_H */
