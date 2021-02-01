/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 */

#ifndef __ASM_ARCH_IRQS_H
#define __ASM_ARCH_IRQS_H

#ifdef NR_IRQS
#undef NR_IRQS
#endif

#define NR_IRQS			256  // sync as hardware gic configuration

#ifdef CONFIG_TRUST_ZONE_FOR_NORMAL_WORLD
#define IRQ_NORMAL_TO_SECURE	14
#define IRQ_SECURE_TO_NORMAL	15
#endif

#define IRQ_WDOG_NMI		32
#define IRQ_RTC			33
#define IRQ_TIMER			34
#define IRQ_CPU2CPU		35	// ACPU/VCPU/VCPU2 to SCPU
#define IRQ_DCSYS			36	// DCSYS-PHY, DCSYS/TVSB/SB2 to SCPU
#define IRQ_AUDIO_DMA		37
#define IRQ_IMDOMAIN		38	// VODMA/DDC/APLL/I/M-DOMAIN
#define IRQ_DDOMAIN		39	// DCT/UZ/OSD compression/TVE
#define IRQ_AXI			40
#define IRQ_VDEC			41
#define IRQ_VBI			42
#define IRQ_SE				43
#define IRQ_MCP			44
#define IRQ_MD				45
#define IRQ_GPU			46
#define IRQ_GPU_JOB		58
#define IRQ_GPU_MMU		59	
#define IRQ_IFDEMOD		47
#define IRQ_GPU_PMU             48              //GPU PMU
#define IRQ_NF				49	// NF
#define IRQ_CR				50	// CR/EMMC
#define IRQ_MISC			51	// GPIO/I2C/UART/SC/PCMCIA/TIMER
#define IRQ_ETH			52	// ETH/GETH
#define IRQ_USB			53
#define IRQ_TP				54
#define IRQ_HDMI			55
#define IRQ_SDIO			56
#define IRQ_CEC			57	// CEC/CBUS/MISC_ISO/MISC_ISO_OFF/SYNCP
#define IRQ_MEMC            	61
#define IRQ_PMU_0		62
#define IRQ_PMU_1		63
#define IRQ_PMU_2		64
#define IRQ_PMU_3		65
#define IRQ_DDEMOD		70		//DDEMOD
#define IRQ_THERMAL		73		//Thermal
#define IRQ_GPU_GP_MMU		74		//GPU GP IRQ
#define IRQ_GPU_PP0		75		//SB2 to KCPU
#define IRQ_GPU_PP0_MMU		76		//GPU PP0 MMU
#define IRQ_GPU_PP1		77		//GPU PP1
#define IRQ_GPU_PP1_MMU		78		//GPU PP1 MMU
#define IRQ_GPU_PP		79		//GPU PP
#define IRQ_SECURE_DCSYS	80		//DCSYS to KCPU
#define IRQ_SECURE_SB2		81		//SB2 to KCPU
#define IRQ_SECURE_SE		82		//SE to KCPU
#define IRQ_SECURE_MCP		83		//MCP to KCPU
#define IRQ_SECURE_NF		84		//MD to KCPU
#define IRQ_SECURE_MD		85		//NAND to KCPU
#define IRQ_SECURE_EMMC		86		//EMMC to KCPU
#define IRQ_SECURE_TP		87		//TP to KCPU
#define IRQ_SECURE_MISC		88		//I2C1/I2C2/UART1/UART2 to KCPU
#define IRQ_SECURE_THERMAL	89		//Thermal to KCPU

#endif
