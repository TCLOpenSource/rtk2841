#include <linux/kernel.h>

#include <linux/compiler.h>
#include <linux/dma-mapping.h>
#include <linux/init.h>
#include <linux/irqchip/arm-gic.h>
#include <linux/memblock.h>
#include <linux/sizes.h>

#include <asm/io.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/memory.h>

#include <generated/mach-types.h>

#include <mach/resource.h>

#include "dmac.h"
#include "emmc.h"
#include "ether.h"
#include "l2cc.h"
#include "pmu.h"
#include "smp.h"
#include "spi.h"
#include "time.h"
#include "uart.h"
#include "usb.h"
#include "wdog.h"
#include "xip.h"
#include "ion.h"

static void __init lg115x_reserve(void)
{
	lg115x_reserve_ether();
	lg115x_reserve_xip();
}

static struct map_desc map_descs[] __initdata = {
	{
		.virtual        = __MMIO_P2V(MPCORE_PERIPH_BASE),
		.pfn            = __phys_to_pfn(MPCORE_PERIPH_BASE),
		.length         = SZ_16K,
		.type           = MT_DEVICE,
	},
	{
		.virtual        = __MMIO_P2V(L2CC_BASE),
		.pfn            = __phys_to_pfn(L2CC_BASE),
		.length         = SZ_4K,
		.type           = MT_DEVICE,
	},
#ifdef CONFIG_CLOCK_DETECTION
	{
		.virtual	= __MMIO_P2V(TOP_CTRL_BASE),
		.pfn		= __phys_to_pfn(TOP_CTRL_BASE),
		.length		= SZ_4K,
		.type		= MT_DEVICE,
	},
#endif
	{
		.virtual	= __MMIO_P2V(CPU_CTRL_BASE),
		.pfn		= __phys_to_pfn(CPU_CTRL_BASE),
		.length		= SZ_4K,
		.type		= MT_DEVICE,
	},
};

static void __init lg115x_map_io(void)
{
	iotable_init(map_descs, ARRAY_SIZE(map_descs));
}

static void __init lg115x_init_early(void)
{
	extern void __init lg115x_arm_firmware_init(void);

	lg115x_arm_firmware_init();

	/*
	 * We should enable PL310 in early stage. PL310 activation is done
	 * by a support code in the secure monitor, and the secure monitor
	 * runs only on the core #0.
	 */
	lg115x_init_l2cc();
}

static void __init lg115x_init_irq(void)
{
	gic_init(0, 29, MMIO_P2V(MPCORE_GIC_DIST_BASE),
	                MMIO_P2V(MPCORE_GIC_CPU_BASE));
}

static void __init lg115x_init_machine(void)
{
	lg115x_init_dmac();
	lg115x_init_emmc();
	lg115x_init_ether();
	lg115x_init_pmu();
	lg115x_init_spi();
	lg115x_init_uart();
	lg115x_init_usb();
	lg115x_init_wdog();
#ifdef CONFIG_ION_LG115X
	lg115x_register_ion();
#endif
}

static void lg115x_restart(char mode, char const *cmd)
{
	void __iomem *wdt_base;

	/*
	 * try to reset by sp805 watchdog timer
	 */
	wdt_base = ioremap(WDOG_BASE, SZ_4K);
	writel_relaxed(0x0000, wdt_base + 0x08);
	writel_relaxed(0x0000, wdt_base + 0x00);
	writel_relaxed(0x0003, wdt_base + 0x08);
}
#ifdef CONFIG_MACH_LG1154
#ifdef CONFIG_LG1311_A0
MACHINE_START(LG1154, "LG Electronics Ltd LG1311-based board")
#else
MACHINE_START(LG1154, "LG Electronics Ltd LG1154-based board")
#endif
#elif defined ( CONFIG_MACH_LG1152 )
MACHINE_START(LG1152, "LG Electronics Ltd LG1152-based board")
#else
#error "Machine type is not specified"
#endif
	.atag_offset	= 0x00000100,
        .smp            = smp_ops(lg115x_smp_ops),
	.reserve	= lg115x_reserve,
	.map_io		= lg115x_map_io,
	.init_early	= lg115x_init_early,
	.init_irq	= lg115x_init_irq,
	.init_time      = lg115x_init_time,
	.init_machine	= lg115x_init_machine,
	.restart	= lg115x_restart,
MACHINE_END
