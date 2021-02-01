/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2010 by Chien-An Lin <colin@realtek.com.tw>
 *
 * Venus series board platform device registration
 */

#include <linux/dma-mapping.h>
#include <linux/platform_device.h>
#include <mach/platform.h>
#include <mach/irqs.h>
#ifdef CONFIG_RTC_DRV_RTK
#include <rbus/drtc_reg.h>
#endif
#include <rbus/sys_reg_reg.h>
#include <rbus/stb_reg.h>
#include <linux/syscalls.h>
#ifndef CONFIG_ARM64
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#else
#include <linux/of_reserved_mem.h>
#endif
#include <asm/mach/time.h>
#include <mach/common.h>
#include <mach/timex.h>
#ifdef CONFIG_CMA_RTK_ALLOCATOR
#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
#include <linux/auth.h>
#endif
#endif
#ifdef CONFIG_HIBERNATION
#include <linux/suspend.h>
#endif
#include <mach/io.h>
#include <mach/iomap.h>
#include <linux/mm.h>




#ifdef CONFIG_RTC_DRV_RTK
static struct resource rtk_rtc_resources[] = {
	[0] = {
		.start	= GET_MAPPED_RBUS_ADDR(RBUS_BASE_VIRT_OLD + DRTC_RTCSEC_reg),
		.end 	= GET_MAPPED_RBUS_ADDR(RBUS_BASE_VIRT_OLD + DRTC_RTCCR_reg + 4 - 1),
		.flags	= IORESOURCE_MEM
	},
};

static struct platform_device rtk_rtc_device = {
	.name		= "rtc-rtk",
	.num_resources	= ARRAY_SIZE(rtk_rtc_resources),
	.resource	= rtk_rtc_resources
};
#endif	//CONFIG_RTC_DRV_RTK

struct device usb_at_platform = {
	.init_name	= "usb",
	.parent		= &platform_bus,
};
EXPORT_SYMBOL_GPL(usb_at_platform);

/* EHCI_TOP (USB high speed host controller) */
static struct resource rtk_usb_ehci_top_resources[] = {
	[0] = {
		.start		= GET_MAPPED_RBUS_ADDR(0xb8013000),
		.end		= GET_MAPPED_RBUS_ADDR(0xb8013000 + 0x3ff),
		.flags		= IORESOURCE_MEM,
	},

	[1] = {
		.start		= IRQ_USB,
		.end		= IRQ_USB,
		.flags		= IORESOURCE_IRQ,
	},
};

static u64 ehci_top_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtk_usb_ehci_top_device = {
    .name = "ehci-platform",
    /*.name = "ehci0-hcd",*/
	.dev = {
		.parent			= &usb_at_platform,
		.dma_mask		= &ehci_top_dmamask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(rtk_usb_ehci_top_resources),
	.resource	= rtk_usb_ehci_top_resources,
};

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
/* EHCI_EX_TOP (USB high speed host controller) for WIFI port */
static struct resource rtk_usb_ehci_ex_top_resources[] = {
	[0] = {
		.start		= GET_MAPPED_RBUS_ADDR(0xb8012000),
		.end		= GET_MAPPED_RBUS_ADDR(0xb8012000 + 0x3ff),
		.flags		= IORESOURCE_MEM,
	},

	[1] = {
		.start		= IRQ_USB,
		.end		= IRQ_USB,
		.flags		= IORESOURCE_IRQ,
	},
};

static u64 ehci_ex_top_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtk_usb_ehci_ex_top_device = {
	.name = "ehci-platform-ex",
	.dev = {
		.parent			= &usb_at_platform,
		.dma_mask		= &ehci_ex_top_dmamask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
#ifdef CONFIG_USB_USER_RESUME
		.power.is_userresume = true,
#endif
	},
	.num_resources	= ARRAY_SIZE(rtk_usb_ehci_ex_top_resources),
	.resource	= rtk_usb_ehci_ex_top_resources,
};
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

/* OHCI TOP (USB Full/Low speed host controller) */
static struct resource rtk_usb_ohci_top_resources[] = {
	[0] = {
		.start		= GET_MAPPED_RBUS_ADDR(0xb8013400),
		.end		= GET_MAPPED_RBUS_ADDR(0xb8013400 + 0x3ff),
		.flags		= IORESOURCE_MEM,
	},

	[1] = {
		.start		= IRQ_USB,
		.end		= IRQ_USB,
		.flags		= IORESOURCE_IRQ,
	},
};

static u64 ohci_top_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtk_usb_ohci_top_device = {
	.name = "ohci-platform",
	.dev = {
		.parent			= &usb_at_platform,
		.dma_mask		= &ohci_top_dmamask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
#ifdef CONFIG_USB_USER_RESUME
		.power.is_userresume = true,
#endif
	},
	.num_resources	= ARRAY_SIZE(rtk_usb_ohci_top_resources),
	.resource	= rtk_usb_ohci_top_resources,
};

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
/* OHCI_EX_TOP (USB Full/Low speed host controller) */
static struct resource rtk_usb_ohci_ex_top_resources[] = {
	[0] = {
		.start		= GET_MAPPED_RBUS_ADDR(0xb8012400),
		.end		= GET_MAPPED_RBUS_ADDR(0xb8012400 + 0x3ff),
		.flags		= IORESOURCE_MEM,
	},

	[1] = {
		.start		= IRQ_USB,
		.end		= IRQ_USB,
		.flags		= IORESOURCE_IRQ,
	},
};

static u64 ohci_ex_top_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtk_usb_ohci_ex_top_device = {
	.name = "ohci-platform-ex",
	.dev = {
		.parent			= &usb_at_platform,
		.dma_mask		= &ohci_ex_top_dmamask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
#ifdef CONFIG_USB_USER_RESUME
		.power.is_userresume = true,
#endif
	},
	.num_resources	= ARRAY_SIZE(rtk_usb_ohci_ex_top_resources),
	.resource	= rtk_usb_ohci_ex_top_resources,
};
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

#if 0
static struct resource rtk_usb_dwc_otg_resources[] = {
	[0] = {
		.start		= GET_MAPPED_RBUS_ADDR(0xb8090000),
		.end		= GET_MAPPED_RBUS_ADDR(0xb8090000 + 0x8000),
		.flags		= IORESOURCE_MEM,
	},

	[1] = {
		.start		= IRQ_USB,
		.end		= IRQ_USB,
		.flags		= IORESOURCE_IRQ,
	},
};

static u64 dwc_otg_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtk_usb_dwc_otg_device = {
	.name		= "dwc_otg",
	.id		= -1,
	.dev = {
		.parent			= &usb_at_platform,
		.dma_mask		= &dwc_otg_dmamask,
		.coherent_dma_mask	= DMA_BIT_MASK(32),
	},
	.num_resources	= ARRAY_SIZE(rtk_usb_dwc_otg_resources),
	.resource	= rtk_usb_dwc_otg_resources,
};
#endif
#ifdef CONFIG_REALTEK_FPGA
static unsigned long uart_clock = UART_CLOCK_40M;
#else
static unsigned long uart_clock = UART_CLOCK_27M;
#endif

/*****************************************************************************
 * SD/SDIO/MMC -
 ****************************************************************************/
#if 0
static struct resource rtksdio_resources[] = {
    [0] = {
        .start  = GET_MAPPED_RBUS_ADDR((u32)0xb8010C00),
        .end    = GET_MAPPED_RBUS_ADDR((u32)0xb8010C00 + 0x3ff),
        .flags  = IORESOURCE_MEM,
    },
    [1] = {
        .start  = IRQ_CR,
        .end    = IRQ_CR,
        .flags  = IORESOURCE_IRQ,
    },
};

static u64 rtksdio_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtksdio_device = {
    .name           = "rtksdio",
    .id             = -1,
    .dev            = {
        .dma_mask = &rtksdio_dmamask,
        .coherent_dma_mask = DMA_BIT_MASK(32),
    },
    .num_resources  = ARRAY_SIZE(rtksdio_resources),
    .resource       = rtksdio_resources,
};
#endif

#if defined(CONFIG_MACH_RTK_298x) || defined(CONFIG_MACH_RTK_294X)
static struct resource rtkemmc_resources[] = {
    [0] = {
        .start  = GET_MAPPED_RBUS_ADDR((u32)0xb8010800),
        .end    = GET_MAPPED_RBUS_ADDR((u32)0xb8010800 + 0x3FF),
        .flags  = IORESOURCE_MEM,
    },
    [1] = {
        .start  = IRQ_CR,
        .end    = IRQ_CR,
        .flags  = IORESOURCE_IRQ,
    },
};

static u64 rtkemmc_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtkemmc_device = {
    .name           = "rtkemmc",
    .id             = -1,
    .dev            = {
        .dma_mask = &rtkemmc_dmamask,
        .coherent_dma_mask = DMA_BIT_MASK(32),
    },
    .num_resources  = ARRAY_SIZE(rtkemmc_resources),
    .resource       = rtkemmc_resources,
};
#endif

//#if defined(CONFIG_MACH_RTK_294x) || defined(CONFIG_ARCH_RTK299S)
#if 0
static struct resource rtkemmc_dw_resources[] = {
    [0] = {
        .start  = GET_MAPPED_RBUS_ADDR((u32)0xb8010800),
        .end    = GET_MAPPED_RBUS_ADDR((u32)0xb8010800 + 0x3FF),
        .flags  = IORESOURCE_MEM,
    },
    [1] = {
        .start  = IRQ_CR,
        .end    = IRQ_CR,
        .flags  = IORESOURCE_IRQ,
    },
};

static u64 rtkemmc_dw_dmamask = DMA_BIT_MASK(32);

static struct platform_device rtkemmc_dw_device = {
    .name           = "rtkemmc_dw",
    .id             = -1,
    .dev            = {
        .dma_mask = &rtkemmc_dw_dmamask,
        .coherent_dma_mask = DMA_BIT_MASK(32),
    },
    .num_resources  = ARRAY_SIZE(rtkemmc_dw_resources),
    .resource       = rtkemmc_dw_resources,
};
#endif
#if defined(CONFIG_MTD_NAND_RTK)
static struct resource rtk_resource_nand[] = {
    [0] = {
        .start  = GET_MAPPED_RBUS_ADDR((u32)0xb8010000),
        .end    = GET_MAPPED_RBUS_ADDR((u32)0xb8010000 + 0x378),
        .flags  = IORESOURCE_MEM,
    },
    [1] = {
        .start  = IRQ_CR,
        .end    = IRQ_CR,
        .flags  = IORESOURCE_IRQ,
    },
};

static u64 rtk_nand_dma_mask= DMA_BIT_MASK(32);
struct platform_device rtknand_device = {
    .name        = "rtk_nand",
    .id        = -1,
    .dev        = {
        .dma_mask = &rtk_nand_dma_mask,
        .coherent_dma_mask = DMA_BIT_MASK(32),
    },
    .resource      =  rtk_resource_nand,
    .num_resources = ARRAY_SIZE(rtk_resource_nand),
};
#endif

#if defined(CONFIG_MTD_SPI_NAND_RTK)

static struct resource rtk_resource_spi_nand[] = {
	[0] = {
		.start	= GET_MAPPED_RBUS_ADDR((u32)0xB801A800),
		.end	= GET_MAPPED_RBUS_ADDR((u32)0xB801A800 + 0x88),
		.flags	= IORESOURCE_MEM,
	},
	[1] = {
		.start	= IRQ_CR,
		.end	= IRQ_CR,
		.flags	= IORESOURCE_IRQ,
	},
};

static u64 rtk_spi_nand_dma_mask= DMA_BIT_MASK(32);
struct platform_device rtk_spi_nand_device = {
	.name		 = "rtk_sn",
	.id 	   = -1,
	.dev		= {
		.dma_mask = &rtk_spi_nand_dma_mask,
		.coherent_dma_mask = DMA_BIT_MASK(32),
	},
	.resource	   =  rtk_resource_spi_nand,
	.num_resources = ARRAY_SIZE(rtk_resource_spi_nand),
};
#endif
/* PMU ( Performance Moniters ) */
static struct resource rtk_pmu_resources[] = {
	DEFINE_RES_IRQ(IRQ_PMU_0), // core 0
	DEFINE_RES_IRQ(IRQ_PMU_1), // core 1
	DEFINE_RES_IRQ(IRQ_PMU_2), // core 2
	DEFINE_RES_IRQ(IRQ_PMU_3)  // core 3
};

static struct platform_device rtk_pmu_device = {
	.name              = "armv7-pmu",
    .id            = -1,
    .num_resources     = ARRAY_SIZE(rtk_pmu_resources),
	.resource = rtk_pmu_resources
};


#ifdef CONFIG_ARM64
static struct platform_device *rtk_platform_devices[] = {

};
#else
static struct platform_device *rtk_platform_devices[] = {
#ifdef CONFIG_RTC_DRV_RTK
	&rtk_rtc_device,
#endif

	&rtk_usb_ehci_top_device,
	&rtk_usb_ohci_top_device,
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
	&rtk_usb_ehci_ex_top_device,
	&rtk_usb_ohci_ex_top_device,
#endif

#if defined(CONFIG_MACH_RTK_298x) || defined(CONFIG_MACH_RTK_294X) || defined(CONFIG_ARCH_RTK299S)
	&rtksdio_device,        /* SDIO */
#endif

#if defined(CONFIG_MACH_RTK_298x) || defined(CONFIG_MACH_RTK_294X)
	&rtkemmc_device,        /* EMMC */
#endif

//#if defined(CONFIG_MACH_RTK_294x) || defined(CONFIG_ARCH_RTK299S)
#if 1
#ifndef CONFIG_REALTEK_OF //temp patch, it cause system crashed
	&rtkemmc_dw_device,     /* EMMC_PLUS */
#endif
#endif
#if defined(CONFIG_MTD_NAND_RTK)
	&rtknand_device,
#endif
#if defined(CONFIG_MTD_SPI_NAND_RTK)
		&rtk_spi_nand_device,
#endif
	&rtk_pmu_device		    /* PMU */
};
#endif

void plat_mem_protect(void)
{
//#ifdef CONFIG_REALTEK_SECURE_OS
#if 0 //will be enable later
   unsigned int scramble_key = CONTENT_PROTECTION_KEY;
	int index;

   printk("do plat_mem_protect......\n");

   // KCPU code protection
	//rtd_outl(RTD298X_DC_MEM_PROTECT_SADDR0, 0x20000000);
   //rtd_outl(RTD298X_DC_MEM_PROTECT_EADDR0, 0xfffff000);

   //rtd_outl(RTD298X_DC_MEM_PROTECT_SADDR1, (CONFIG_REALTEK_LINUX_LOAD_ADDR-0x1000) & 0x1fffffff);
   //rtd_outl(RTD298X_DC_MEM_PROTECT_EADDR1, 0x1ffff000);

   //sed_rng_init();
   //sed_rng_get(&scramble_key);

	index = 0; //use 1st one to do content protection

   // Content protection
   rtd_outl(DC_MEM_SCRAMBLE_SADDR(index), VIDEO_RINGBUFFER_START);
   rtd_outl(DC_MEM_SCRAMBLE_EADDR(index), VIDEO_RINGBUFFER_START + VIDEO_RINGBUFFER_SIZE);

   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY0(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY1(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY2(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY3(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY4(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY5(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_CURR_KEY6(index), scramble_key);

   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY0(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY1(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY2(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY3(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY4(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY5(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_PREV_KEY6(index), scramble_key);

   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY0(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY1(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY2(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY3(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY4(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY5(index), scramble_key);
   rtd_outl(DC_MEM_SCRAMBLE_UPDATE_KEY6(index), scramble_key);

	// Enable all permission for KCPU/ACPU/VCPU
	rtd_outl(DC_MEM_SCRAMBLE_ACCESS(index), 0xffffffff);

   rtd_setbits(DC_MEM_SCRAMBLE_CTRL, BIT(12+index));
   rtd_setbits(DC_MEM_PROTECT_CTRL, BIT(12+index));
#endif
}

extern int  rtk_rtc_ip_init(void);
//the real rtk_rtc_early_init() funciton was defined in rtk_rtc.c.
int __weak rtk_rtc_early_init(void)
{
#ifdef CONFIG_RTC_DRV_RTK
	rtk_rtc_ip_init();
#endif
	return 0;
}

#ifdef CONFIG_RTK_KDRV_EMCU
extern int rtk_pm_load_8051(int flag);
#endif

static void rtk_platfrom_power_off(void)
{
#ifdef CONFIG_RTK_KDRV_EMCU
	rtk_pm_load_8051(1); // #define SUSPEND_NORMAL      1
#endif
}

void __init rtk_init_machine(void)
{
#ifndef CONFIG_ARM64
	int error = device_register(&usb_at_platform);
	if (error) {
        	pr_err("%s: device_register fail\n", __func__);
   	}
#endif
   	platform_add_devices(rtk_platform_devices, ARRAY_SIZE(rtk_platform_devices));

	/*[ANDROIDTV-3123] For long press RC power key -> power off */
	pm_power_off = rtk_platfrom_power_off;
}

void __init rtk_init_late(void)
{
   // add console driver node
   sys_mknod("/dev/console", S_IFCHR + 0600, new_encode_dev(MKDEV(5, 1)));

#ifdef CONFIG_CMA_RTK_ALLOCATOR
#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
   init_overlapped_region(RBUS_BASE_PHYS >> PAGE_SHIFT, RBUS_BASE_SIZE >> PAGE_SHIFT);
#endif
#endif

#ifdef CONFIG_HIBERNATION
    register_nosave_region_late(0x00000000, 0x00000100);
#endif
}

unsigned long get_uart_clock(void)
{
	return uart_clock;
}

static int __init early_uart_clock(char *str)
{
	const char *str_98M = "98M";

	if (strncmp(str_98M, str, strlen(str_98M)) == 0)
	{
		uart_clock = UART_CLOCK_98M;
		pr_info("UART_CLOCK_98M\n");
	}
	else
	{
		uart_clock = UART_CLOCK_27M;
		pr_info("UART_CLOCK_27M");
	}
	return 0;
}

early_param("uartclk", early_uart_clock);

void __init rtk_init_early(void)
{
   // init clcok&PLL or something in early stage
#ifndef CONFIG_REALTEK_FPGA
#if (SYSTEM_CONSOLE == 0)
	if (get_uart_clock() == UART_CLOCK_98M) {
		if ((rtd_inl(0xb80004e4) & (BIT(0) | BIT(1) | BIT(3))) != 0x9)
		{
			rtd_setbits(0xb80004e4, BIT(0) | BIT(3));
			rtd_clearbits(0xb80004e4, BIT(1));
		}
		rtd_clearbits(0xB8060058, BIT(0));
	}
#elif (SYSTEM_CONSOLE == 1 || CONFIG_RTK_KDRV_SERIAL_8250_RUNTIME_UARTS == 2)
	int system_concole = 1;
	CRT_CLK_OnOff(UART, CLK_ON , &system_concole);
#elif (SYSTEM_CONSOLE == 2)
	int system_concole = 2;
	CRT_CLK_OnOff(UART, CLK_ON , &system_concole);
#elif (SYSTEM_CONSOLE == 3)
	int system_concole = 3;
	CRT_CLK_OnOff(UART, CLK_ON , &system_concole);
#endif
#endif

#ifdef CONFIG_REALTEK_PCBMGR // cklai@121106 setup platform related settings
   printk("pcbMgr: RTK\n");
// printk("prom_init(), _prom_envp=%x\n", (unsigned int)_prom_envp);
   // must be called after parse_early_param that will assign _prom_envp from boot command line
   prom_init();
#endif

#ifdef CONFIG_CACHE_L2X0
   rtk_l2_cache_init();
#endif

#ifdef CONFIG_RTC_DRV_RTK
    	rtk_rtc_early_init();
#endif

	plat_mem_protect();
}

static const char * const rtk_board_compat[] = {
	"rtk,rtd299s",
	NULL
};

#ifndef CONFIG_ARM64
MACHINE_START(RTK284X, "rtd284x")

// .atag_offset   = 0x100,
#ifdef CONFIG_SMP
   .smp          = smp_ops(rtk_smp_ops),
#endif
   .nr_irqs      = 0,
   .reserve      = rtk_reserve,
   .map_io       = rtk_map_io,
   .init_early   = rtk_init_early,
   .init_irq     = gic_init_irq,
#if 0 // fix me - jinncheng - kernel porting
   .handle_irq   = gic_handle_irq,
#endif
   .init_machine = rtk_init_machine,
   .init_late    = rtk_init_late,
    .init_time    = rtk_timer_init,
   .restart      = rtk_machine_restart,
	.dt_compat    = rtk_board_compat,
MACHINE_END
#endif



#include <mach/rtk_platform.h>
/**
   list by address order,
   {addr, size}
 */
#define _TBD_ 0
unsigned long carvedout_buf[MM_LAYOUT_CARVEDOUT_NUM][CARVEDOUT_NUM][2] = {
  // MM_LAYOUT_DEFAULT
  {
	{0x00000000,  1*_MB_}, // CARVEDOUT_BOOTCODE
	{0x02000000,  8*_MB_}, // CARVEDOUT_DEMOD
	{0x10000000,  1*_MB_}, // CARVEDOUT_AV_DMEM
#if defined(CONFIG_REALTEK_SECURE) || defined(FORCE_RESERVE_KCPU_MEM)
	{0x16000000,  0*_MB_}, // CARVEDOUT_K_BOOT
#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
	{0x16000000, 15*_MB_}, // CARVEDOUT_K_OS
#else
	{0x16000000, 24*_MB_}, // CARVEDOUT_K_OS
#endif
#endif
	{RBUS_BASE_PHYS, RBUS_BASE_SIZE}, // CARVEDOUT_MAP_RBUS

#ifdef CONFIG_REALTEK_SECURE_DDK
	{0x1a500000 - RTK_GPU_FW_SIZE, RTK_GPU_FW_SIZE}, // CARVEDOUT_GPU_FW
#endif
	{0x1a500000, 9*_MB_}, // CARVEDOUT_AV_OS
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
	{0x1b180000,  0x00080000}, // CARVEDOUT_MAP_RPC
#endif
	{VIDEO_RINGBUFFER_START,  VIDEO_RINGBUFFER_SIZE}, // CARVEDOUT_VDEC_RINGBUF
#ifdef CONFIG_REALTEK_LOGBUF
	{CONST_LOGBUF_MEM_ADDR_START, CONST_LOGBUF_MEM_SIZE}, // CARVEDOUT_LOGBUF
#endif
	{0x1fc00000, 0x00008000}, // CARVEDOUT_ROMCODE
#ifdef CONFIG_PSTORE
	{0x1fd00000, 0x010000}, // RAMOOPS
#endif
#ifdef CONFIG_CUSTOMER_TV006
	{GAL_MEM_ADDR_START, GAL_MEM_SIZE}, // CARVEDOUT_GAL
#endif
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#if defined(BOOT_MEMORY_START) && defined(BOOT_MEMORY_END)
	{BOOT_MEMORY_START, BOOT_MEMORY_END - BOOT_MEMORY_START}, // CARVEDOUT_SNAPSHOT
#else
	{_TBD_, _TBD_, _TBD_, _TBD_}, // CARVEDOUT_SNAPSHOT
#endif
#endif
	{SCLAER_MODULE_START, SCALER_MODULE_SIZE}, // CARVEDOUT_SCALER
	{SCALER_MEMC_START, SCALER_MEMC_SIZE}, // CARVEDOUT_SCALER_MEMC
	{SCALER_MDOMAIN_START, SCALER_MDOMAIN_SIZE}, // CARVEDOUT_SCALER_MDOMAIN
	{SCALER_VIP_START, SCALER_VIP_SIZE}, // CARVEDOUT_SCALER_VIP
	{SCALER_OD_START, SCALER_OD_SIZE}, // CARVEDOUT_SCALER_OD
	{VDEC_BUFFER_START, VDEC_BUFFER_SIZE}, // CARVEDOUT_VDEC_VBM
	{DEMUX_TP_BUFFER_START, DEMUX_TP_BUFFER_SIZE}, // CARVEDOUT_TP

    // for desired cma size calculation
	{0, _TBD_/*CMA_LOW_RESERVED_SIZE*/}, // CARVEDOUT_CMA_LOW
	{0, CMA_HIGH_RESERVED_SIZE}, // CARVEDOUT_CMA_HIGH

#ifdef CONFIG_ZONE_ZRAM
	{0, _TBD_}, // CARVEDOUT_ZONE_ZRAM
#endif
  },

  // MM_LAYOUT_CHINA512MB
  {
	{0x00000000,	1*_MB_}, // CARVEDOUT_BOOTCODE
	{0x02000000,	8*_MB_}, // CARVEDOUT_DEMOD 	   -- Need to lower down to 2 MB
	{0x10000000,	1*_MB_}, // CARVEDOUT_AV_DMEM
#if defined(CONFIG_REALTEK_SECURE) || defined(FORCE_RESERVE_KCPU_MEM)
	{0x18300000,  0*_MB_}, // CARVEDOUT_K_BOOT
#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
	{0x18400000, 15*_MB_}, // CARVEDOUT_K_OS
#else
	{0x18400000, 16*_MB_}, // CARVEDOUT_K_OS
#endif
#endif
	{RBUS_BASE_PHYS, RBUS_BASE_SIZE}, // CARVEDOUT_MAP_RBUS
#ifdef CONFIG_REALTEK_SECURE_DDK
	{0x1a500000 - RTK_GPU_FW_SIZE, RTK_GPU_FW_SIZE}, // CARVEDOUT_GPU_FW
#endif
	{0x1a500000,	9*_MB_}, // CARVEDOUT_AV_OS
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
	{0x1b180000,  0x00080000}, // CARVEDOUT_MAP_RPC
#endif
	{CHINA_512MB_VIDEO_RINGBUFFER_START,	CHINA_512MB_VIDEO_RINGBUFFER_SIZE}, // CARVEDOUT_VDEC_RINGBUF
#ifdef CONFIG_REALTEK_LOGBUF
	{CHINA_512MB_CONST_LOGBUF_MEM_ADDR_START, CHINA_512MB_CONST_LOGBUF_MEM_SIZE}, // CARVEDOUT_LOGBUF
#endif
	{0x1fc00000, 0x00008000}, // CARVEDOUT_ROMCODE
#ifdef CONFIG_PSTORE
	{0x1fd00000, 0x010000}, // RAMOOPS
#endif
#ifdef CONFIG_CUSTOMER_TV006
	{CHINA_512MB_GAL_MEM_ADDR_START, CHINA_512MB_GAL_MEM_SIZE}, // CARVEDOUT_GAL
#endif
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#if defined(BOOT_MEMORY_START) && defined(BOOT_MEMORY_END)
	{BOOT_MEMORY_START, BOOT_MEMORY_END - BOOT_MEMORY_START}, // CARVEDOUT_SNAPSHOT
#else
	{_TBD_, _TBD_, _TBD_, _TBD_}, // CARVEDOUT_SNAPSHOT
#endif
#endif
	{CHINA_512MB_SCLAER_MODULE_START, CHINA_512MB_SCALER_MODULE_SIZE}, // CARVEDOUT_SCALER
	{CHINA_512MB_SCALER_MEMC_START, CHINA_512MB_SCALER_MEMC_SIZE}, // CARVEDOUT_SCALER_MEMC
	{CHINA_512MB_SCALER_MDOMAIN_START, CHINA_512MB_SCALER_MDOMAIN_SIZE}, // CARVEDOUT_SCALER_MDOMAIN
	{CHINA_512MB_SCALER_VIP_START, CHINA_512MB_SCALER_VIP_SIZE}, // CARVEDOUT_SCALER_VIP
	{CHINA_512MB_SCALER_OD_START, CHINA_512MB_SCALER_OD_SIZE}, // CARVEDOUT_SCALER_OD
	{CHINA_512MB_VDEC_BUFFER_START, CHINA_512MB_VDEC_BUFFER_SIZE}, // CARVEDOUT_VDEC_VBM
	{CHINA_512MB_DEMUX_TP_BUFFER_START, CHINA_512MB_DEMUX_TP_BUFFER_SIZE}, // CARVEDOUT_TP

	// for desired cma size calculation
	{0, _TBD_/*CMA_LOW_RESERVED_SIZE*/}, // CARVEDOUT_CMA_LOW
	{0, _TBD_/*CMA_HIGH_RESERVED_SIZE*/}, // CARVEDOUT_CMA_HIGH

#ifdef CONFIG_ZONE_ZRAM
	{0, _TBD_}, // CARVEDOUT_ZONE_ZRAM
#endif
  },
};

EXPORT_SYMBOL(carvedout_buf);


static enum PLAFTORM_TYPE platform=PLATFORM_OTHER;
enum PLAFTORM_TYPE get_platform (void)
{
    return platform;
}

static int boot_freqnum = 5;
static int __init early_parse_dvfs (char *str)
{
    /*const char * dvfs_4="4";
    const char * dvfs_5="5";
    if (strncmp(dvfs_4,str,strlen(dvfs_4))==0)
    {
           boot_freqnum=4;
	   pr_info("clamp parse 4\n");
    }
    else if (strncmp(dvfs_5,str,strlen(dvfs_5))==0)
    {
           boot_freqnum=5;
	   pr_info("clamp parse 5\n");
    }
    else
    {
           boot_freqnum=4;
    }*/

    //RTK hack, force using 5 freq table

    boot_freqnum = 5;

    return 0 ;
}


int platform_get_dvfs(void)
{
	pr_err("%s , boot_freqnum = %d\n", __func__, boot_freqnum);
	return boot_freqnum;
}

static void switch_platform_dvfs(void)
{
	if(boot_freqnum==4){
		boot_freqnum=5;
	   	pr_err("%s , boot_freqnum = %d\n", __func__, boot_freqnum);
	}else {
		boot_freqnum=4;
	   	pr_err("%s , boot_freqnum = %d\n", __func__, boot_freqnum);
	}
}

int is_platform_reset_freq(void)
{
	if(platform_info.apk_boost_mode)
		switch_platform_dvfs();

	pr_debug("%s , platform_info.apk_boost_mode = %d\n", __func__, platform_info.apk_boost_mode);
	return platform_info.apk_boost_mode;
}

void clear_platform_reset_freq(void)
{
	platform_info.apk_boost_mode=0;

}



static int __init early_parse_platform (char *str)
{
    const char * str_k3lp="K3LP";
    const char * str_k3l="K3L";

    if (strncmp(str_k3lp,str,strlen(str_k3lp))==0)
    {
        platform=PLATFORM_K3LP;
        pr_info("K3LP platform\n");
    }
    else if (strncmp(str_k3l,str,strlen(str_k3l))==0)
    {
        platform=PLATFORM_K3L;
        pr_info("K3L platform\n");
    }
    else
    {
        pr_err("Wrong platform  ? \e[1;31m%s\e[0m\n",str);
    }

    return 0;
}

int is_platform_KXLP(void)
{
	return (platform==PLATFORM_K3LP);
}

int is_platform_dvs_enable(void)
{
    return platform_info.enable_dvs;
}

early_param("chip", early_parse_platform);
early_param("boot_dvfs", early_parse_dvfs);

unsigned int get_ic_version(void)
{
#define GET_IC_VERSION()	rtd_inl(STB_SC_VerID_reg)
#define VERSION_A_REG_CODE	0x64560000
#define VERSION_B_REG_CODE	0x64560001

	if (GET_IC_VERSION() == VERSION_A_REG_CODE)
	{
		return VERSION_A;
	}
	else
	{
		return VERSION_B;
	}
}

unsigned long get_memc_start_address(void)
{
	unsigned long memc_size = 0;
	unsigned long memc_addr = 0;

	memc_size = carvedout_buf_query(CARVEDOUT_SCALER_MEMC, &memc_addr);

	return memc_addr;
}
EXPORT_SYMBOL(get_memc_start_address);

int get_memc_size(void)
{
	unsigned long memc_addr = 0;

	return carvedout_buf_query(CARVEDOUT_SCALER_MEMC, &memc_addr);
}
EXPORT_SYMBOL(get_memc_size);

unsigned long get_scaler_mdomain_start_address(void)
{
	unsigned long mdomain_size = 0;
	unsigned long mdomain_addr = 0;

	mdomain_size = carvedout_buf_query(CARVEDOUT_SCALER_MDOMAIN, &mdomain_addr);

	return mdomain_addr;
}
EXPORT_SYMBOL(get_scaler_mdomain_start_address);

int get_scaler_mdomain_size(void)
{
	unsigned long mdomain_addr = 0;

	return carvedout_buf_query(CARVEDOUT_SCALER_MDOMAIN, &mdomain_addr);
}
EXPORT_SYMBOL(get_scaler_mdomain_size);

unsigned long get_scaler_vip_start_address(void)
{
	unsigned long vip_size = 0;
	unsigned long vip_addr = 0;

	vip_size = carvedout_buf_query(CARVEDOUT_SCALER_VIP, &vip_addr);

	return vip_addr;
}
EXPORT_SYMBOL(get_scaler_vip_start_address);

int get_scaler_vip_size(void)
{
	unsigned long vip_addr = 0;

	return carvedout_buf_query(CARVEDOUT_SCALER_VIP, &vip_addr);
}
EXPORT_SYMBOL(get_scaler_vip_size);

unsigned long get_scaler_od_start_address(void)
{
	unsigned long od_size = 0;
	unsigned long od_addr = 0;

	od_size = carvedout_buf_query(CARVEDOUT_SCALER_OD, &od_addr);

	return od_addr;
}
EXPORT_SYMBOL(get_scaler_od_start_address);

int get_scaler_od_size(void)
{
	unsigned long od_addr = 0;

	return carvedout_buf_query(CARVEDOUT_SCALER_OD, &od_addr);
}
EXPORT_SYMBOL(get_scaler_od_size);

#ifdef CONFIG_ZONE_ZRAM
unsigned long get_zone_zram_size(void)
{
	unsigned long zone_zram_addr = 0;

	return carvedout_buf_query(CARVEDOUT_ZONE_ZRAM, &zone_zram_addr);
}
EXPORT_SYMBOL(get_zone_zram_size);
#endif

bcas_info_t bcas;
static int __init early_parse_bcas(char *str)
{
    const char *strON="on";
    const char *strOFF="off";
    if (strncmp(strON,str,strlen(strON))==0)
    {
        bcas = bcasON;
        pr_info("bcas on\n");
    }
    else if (strncmp(strOFF,str,strlen(strOFF))==0)
    {
        bcas = bcasOFF;
        pr_info("bcas off\n");
    }
    else
    {
        bcas = bcasUNKNOWN;
        pr_err("bcas is unknown, error!!\n");
    }
    return 0;
}
early_param("bcas", early_parse_bcas);

static const char *carvedout_mem_dts_name[CARVEDOUT_NUM] = {
	"boot", // CARVEDOUT_BOOTCODE
	"demod", // CARVEDOUT_DEMOD
	"dmem", // CARVEDOUT_AV_DMEM
#if defined(CONFIG_REALTEK_SECURE) || defined(FORCE_RESERVE_KCPU_MEM)
	"kboot", //CARVEDOUT_K_BOOT
	"kcpu", //CARVEDOUT_K_OS
#endif
	"rbus", // CARVEDOUT_MAP_RBUS
	"avcpu", // CARVEDOUT_AV_OS
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
	"rtkrpc", // CARVEDOUT_MAP_RPC
#endif
	"vdec_ringbuffer", // CARVEDOUT_VDEC_RINGBUF
#ifdef CONFIG_REALTEK_LOGBUF
	"logbuf", // CARVEDOUT_LOGBUF
#endif
	"rom", // CARVEDOUT_ROMCODE
#ifdef CONFIG_PSTORE
	"ramoops", // RAMOOPS
#endif
#ifdef CONFIG_CUSTOMER_TV006
	"gal", // CARVEDOUT_GAL
#endif
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	"snapshot", // CARVEDOUT_SNAPSHOT
#endif
	"scaler", // CARVEDOUT_SCALER
	"memc", // CARVEDOUT_SCALER_MEMC
	"mdomain", // CARVEDOUT_SCALER_MDOMAIN
	"vip", // CARVEDOUT_SCALER_VIP
	"od", // CARVEDOUT_SCALER_OD
	"vbm", // CARVEDOUT_VDEC_VBM
	"tp", // CARVEDOUT_TP
	"cma_low_reserved", //CARVEDOUT_CMA_LOW
	"cma_high_reserved" //CARVEDOUT_CMA_HIGH
#ifdef CONFIG_ZONE_ZRAM
	,"zone_zram" //CARVEDOUT_ZONE_ZRAM 
#endif
};

unsigned int get_memory_layout_index(void)
{
#ifdef CONFIG_ANDROID_KITKAT
	return MM_LAYOUT_CHINA512MB;  // No matter which memory size, all Android KK platforms use 512 MB memory layout
#else
	if (DRAM_size <= 0x30000) {  //(get_memory_size(GFP_DCU1) + get_memory_size(GFP_DCU2))
		pr_err("Mac5p has not supported DDR size which less than 1GB !!!\n");
		BUG();
		return MM_LAYOUT_CHINA512MB;
	}
	else
		return MM_LAYOUT_DEFAULT;
#endif
}

unsigned long carvedout_buf_query(carvedout_buf_t what, void **addr)
{
	unsigned long size = 0;
	void *address;
	unsigned int layout_idx = get_memory_layout_index();

	/* this switch case is list by address order */
	switch (what)
	{
#if defined(CONFIG_REALTEK_SECURE) || defined(FORCE_RESERVE_KCPU_MEM)
#ifndef CONFIG_ARM64
	case CARVEDOUT_K_OS:
		// OPTEE size would be depended on DRAM size DIRECTLY, even Android KK 1GB platform uses 512 MB memory layout
		if (DRAM_size > 0x30000) {
			layout_idx = MM_LAYOUT_DEFAULT;
		}
#endif
#endif

#ifdef CONFIG_ZONE_ZRAM
	case CARVEDOUT_ZONE_ZRAM:
		// If DRAM size is larger than 1GB, there will be some region set as zone ZRAM
		if (DRAM_size > 0x40000) {
			// TODO: bootcode may deliver unbalanced region size to kernel
			return (DRAM_size - 0x40000) << PAGE_SHIFT;
		} else {
			return 0;
		}
#endif

	default:
#ifndef CONFIG_ARM64
		address = (void *)carvedout_buf[layout_idx][what][0];
		size = carvedout_buf[layout_idx][what][1];
#else
		size = fdt_get_carvedout_mem_info(carvedout_mem_dts_name[what], &address);
#endif
		break;

//  implement your own specific case
//	case :
//		break;
	}

	if (addr)
		*addr = address;

	return size;
}

unsigned long carvedout_buf_query_range(carvedout_buf_t idx_start, carvedout_buf_t idx_end, void **start, void **end)
{
	unsigned long size = 0;
	unsigned long min_addr = ULONG_MAX;
	unsigned long max_addr = 0;
	int i = 0;
	int idx_a, idx_b;

	// index rule : a < b
	idx_a = idx_start;
	idx_b = idx_end;
	if (idx_start > idx_end) { // swap
		idx_a = idx_end;
		idx_b = idx_start;
	}

	for (i = idx_a; i <= idx_b; i++) {
		unsigned long tmp_addr = 0;
		unsigned long tmp_size = 0;

		tmp_size = carvedout_buf_query((carvedout_buf_t) i, &tmp_addr);
		if (tmp_size) {
			min_addr = min(min_addr, tmp_addr);
			max_addr = max(max_addr, tmp_addr + tmp_size); // end address
			size += tmp_size;
			//pr_info("idx=%d, size=%lx, min_addr=%lx, max_addr=%lx\n", i, tmp_size, min_addr, max_addr);
		}
	}

	if (start && end) {
		*start = (void *)min_addr;
		*end   = (void *)max_addr;
		pr_info("carved-out total size 0x%lx (0x%x@ 0x%x ~ 0x%x)\n", size, (*end - *start), *start, *end);
	} else {
		pr_info("carved-out non given start or end address, size 0x%lx (0x%x ~ 0x%x)\n", size, min_addr, max_addr);
	}

	if (max_addr && ((max_addr - min_addr) != size)) {
		pr_info("carved-out mismatch? size (0x%lx, 0x%lx), choose min one\n", size, (max_addr - min_addr));
		size = min((max_addr - min_addr), size);
	}

	return size;
}

unsigned int carvedout_fallback_query(carvedout_buf_t what)
{
	switch (what)
	{
	case CARVEDOUT_TP:
		return CARVEDOUT_FALLBACK_TO_CMA;

	default:
		return CARVEDOUT_NO_FALLBACK;
	}
}

