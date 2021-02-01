/*
 * linux/arch/arm64/mach-lg1k/sram.c
 */

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/ioport.h>


#include <asm/io.h>
#include "sram.h"

static void __iomem *sram_base;
static phys_addr_t sram_base_phys;
static unsigned long sram_skip;
static unsigned long sram_size;
static void __iomem *sram_ceil;

/*
 * Memory allocator for SRAM: calculates the new ceiling address
 * for pushing a function using the fncpy API.
 *
 * Note that fncpy requires the returned address to be aligned
 * to an 8-byte boundary.
 */
void *lg1k_sram_push_address(unsigned long size)
{

	unsigned long available, new_ceil = (unsigned long)sram_ceil;

	available = sram_ceil - (sram_base + sram_skip);

	if (size > available) {
		pr_err("Not enough space in SRAM\n");
		return NULL;
	}

	new_ceil -= size;
	new_ceil = round_down(new_ceil, FNCPY_ALIGN);
	sram_ceil = ((void __force __iomem *)(new_ceil));
	return (void *)sram_ceil;

}

/*
 * The SRAM context is lost during off-idle and stack
 * needs to be reset.
 */
void lg1k_sram_reset(void)
{
	sram_ceil = sram_base + sram_size;
}

/*
 * Note that we cannot use ioremap for SRAM, as clock init needs SRAM early.
 */
static void __init lg1k_map_sram(unsigned long start, unsigned long size,
		unsigned long skip)
{
	if (size == 0)
		return;

	start = round_down(start, PAGE_SIZE);
	sram_size = size;
	sram_skip = skip;
	sram_base_phys = start;
	sram_base = __arm_ioremap_exec(start, size, 0);

	if (!sram_base) {
		pr_err("SRAM: Could not map\n");
		return;
	}

	lg1k_sram_reset();

	/*
	* Looks like we need to preserve some bootloader code at the
	* beginning of SRAM for jumping to flash for reboot to work...
	*/
	memset_io(sram_base, 0, sram_size);
}

phys_addr_t lg1k_sram_phys(void __iomem *virt)
{
	return sram_base_phys + (virt - sram_base);
}

void __init lg1k_of_init_sram(void)
{
	struct device_node *np;
	struct resource res;

	np = of_find_compatible_node(NULL, NULL, "lg1k-sram");

	if (!np)
		return;

	if (of_address_to_resource(np, 0, &res))
		return;

	lg1k_map_sram(res.start, resource_size(&res), 0);

	pr_info("SRAM pool: %ld KiB at 0x%p(pa:0x%p)\n",
		sram_size / 1024, sram_base, (void *)res.start);
}
