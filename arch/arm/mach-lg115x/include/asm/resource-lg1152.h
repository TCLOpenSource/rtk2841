#ifndef __ASM_RESOURCE_LG1152_H
#define __ASM_RESOURCE_LG1152_H

/*
 * physical to virtual address mapping for static mapping table
 */
#define __MMIO_P2V(x)	(x)

/*
 * Cortex-A9 MPcore devices
 */

#define MPCORE_PERIPH_BASE	0xf0000000
#define MPCORE_SCU_BASE		0xf0000000
#define MPCORE_GIC_CPU_BASE	0xf0000100
#define MPCORE_TWD_TIMER_BASE	0xf0000600
#define MPCORE_GIC_DIST_BASE	0xf0001000

#define MPCORE_TWD_TIMER_IRQ	29

/*
 * AXI/AHB/APB bus devices
 */

#define L2CC_BASE	0xf1000000
#define EHCI0_BASE	0xfb000000
#define OHCI0_BASE	0xfb004000
#define EHCI1_BASE	0xfc000000
#define OHCI1_BASE	0xfc004000
#define EHCI2_BASE	0xf8000000
#define OHCI2_BASE	0xf8004000
#define EMAC_BASE	0xfa000000
#define TIMER_BASE	0xfd100000
#define WDOG_BASE	0xfd200000
#define CPU_CTRL_BASE	0xfd300000
#define GPIO_0_BASE	0xfd400000
#define GPIO_1_BASE	0xfd500000
#define GPIO_2_BASE	0xfd600000
#define GPIO_3_BASE	0xfd700000
#define GPIO_4_BASE	0xfd800000
#define GPIO_5_BASE	0xfd900000
#define GPIO_6_BASE	0xfda00000
#define GPIO_7_BASE	0xfdb00000
#define GPIO_8_BASE	0xfdc00000
#define GPIO_9_BASE	0xfdd00000
#define GPIO10_BASE	0xfde00000
#define GPIO11_BASE	0xfdf00000
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
#define GPIO_0_IRQ	30
#define GPIO_1_IRQ	30
#define GPIO_2_IRQ	30
#define GPIO_3_IRQ	31
#define GPIO_4_IRQ	31
#define GPIO_5_IRQ	31
#define GPIO_6_IRQ	32
#define GPIO_7_IRQ	32
#define GPIO_8_IRQ	32
#define GPIO_9_IRQ	33
#define GPIO10_IRQ	33
#define GPIO11_IRQ	33
#define DMAC_IRQ	48
#define SDHCI_IRQ	50
#define OHCI0_IRQ	51
#define EHCI0_IRQ	52
#define OHCI1_IRQ	53
#define EHCI1_IRQ	54
#define OHCI2_IRQ	55
#define EHCI2_IRQ	56
#define EMAC_IRQ	58
#define PMU0_IRQ	118
#define PMU1_IRQ	119

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

#endif	/* __ASM_RESOURCE_LG1152_H */
