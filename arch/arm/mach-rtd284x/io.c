/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 */

#include <linux/kernel.h>
#include <linux/init.h>

#include <asm/tlb.h>
#include <asm/mach/map.h>
#include <mach/iomap.h>
#include <mach/platform.h>



/*
 * The machine specific code may provide the extra mapping besides the
 * default mapping provided here.
 */

static struct map_desc rtd299s_io_desc[] __initdata = {
    {
        .virtual    = RBUS_BASE_VIRT,
        .pfn        = __phys_to_pfn(RBUS_BASE_PHYS),
        .length     = RBUS_BASE_SIZE,
        .type       = MT_DEVICE,
    },
#if 0 // RDC FPGA
    {
        .virtual    = RBUS_BASE_VIRT_GIC,
        .pfn        = __phys_to_pfn(RBUS_BASE_PHYS_GIC),
        .length     = RBUS_BASE_SIZE_GIC,
        .type       = MT_DEVICE,
    },
#endif
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
    {
        .virtual    = (unsigned long)RPC_BASE_VIRT,
        .pfn        = __phys_to_pfn(RPC_BASE_PHYS),
        .length     = RPC_BASE_SIZE,
        .type       = MT_UNCACHED,
    },
#endif
};

void __weak rtd_semaphore_init(void)
{
}

void __init rtk_map_common_io(void)
{
	rtd_semaphore_init();
	iotable_init(rtd299s_io_desc, ARRAY_SIZE(rtd299s_io_desc));
}

