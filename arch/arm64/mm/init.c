/*
 * Based on arch/arm/mm/init.c
 *
 * Copyright (C) 1995-2005 Russell King
 * Copyright (C) 2012 ARM Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/kernel.h>
#include <linux/export.h>
#include <linux/errno.h>
#include <linux/swap.h>
#include <linux/init.h>
#include <linux/bootmem.h>
#include <linux/mman.h>
#include <linux/nodemask.h>
#include <linux/initrd.h>
#include <linux/gfp.h>
#include <linux/memblock.h>
#include <linux/sort.h>
#include <linux/of_fdt.h>
#include <linux/of_reserved_mem.h>
#include <linux/dma-mapping.h>
#include <linux/dma-contiguous.h>
#include <linux/pageremap.h>
#include <linux/efi.h>
#include <linux/swiotlb.h>

#include <asm/fixmap.h>
#include <asm/memory.h>
#include <asm/sections.h>
#include <asm/setup.h>
#include <asm/sizes.h>
#include <asm/tlb.h>
#include <asm/alternative.h>

#include "mm.h"

static unsigned long cma_high_start = 0;
static unsigned long cma_high_size = 0;
static unsigned long high_carvedout_size = 0;

#define MB     (1024*1024)
#if defined(CONFIG_ZRAM) || defined(CONFIG_DM_CRYPT)
#define ZRAM_RESERVED_SIZE  128*MB
#else
#define ZRAM_RESERVED_SIZE  0
#endif
#define GPU_RESERVED_SIZE  240*MB

phys_addr_t memstart_addr __read_mostly = 0;
phys_addr_t arm64_dma_phys_limit __read_mostly;
struct meminfo meminfo;


#ifdef CONFIG_BLK_DEV_INITRD
static int __init early_initrd(char *p)
{
	unsigned long start, size;
	char *endp;

	start = memparse(p, &endp);
	if (*endp == ',') {
		size = memparse(endp + 1, NULL);

		initrd_start = (unsigned long)__va(start);
		initrd_end = (unsigned long)__va(start + size);
	}
	return 0;
}
early_param("initrd", early_initrd);
#endif

/*
 * Return the maximum physical address for ZONE_DMA (DMA_BIT_MASK(32)). It
 * currently assumes that for memory starting above 4G, 32-bit devices will
 * use a DMA offset.
 */
static phys_addr_t max_zone_dma_phys(void)
{
#ifdef CONFIG_CMA_RTK_ALLOCATOR
	phys_addr_t offset = memblock_start_of_DRAM() & GENMASK_ULL(63, 29);
	return min(offset + (1ULL << 29), memblock_end_of_DRAM());
#else
	phys_addr_t offset = memblock_start_of_DRAM() & GENMASK_ULL(63, 32);
	return min(offset + (1ULL << 32), memblock_end_of_DRAM());
#endif
}

static void __init zone_sizes_init(unsigned long min, unsigned long max)
{
	struct memblock_region *reg;
	unsigned long zone_size[MAX_NR_ZONES], zhole_size[MAX_NR_ZONES];
	unsigned long max_dma = min;

	memset(zone_size, 0, sizeof(zone_size));

	/* 4GB maximum for 32-bit only capable devices */
#ifdef CONFIG_ZONE_DMA
	max_dma = PFN_DOWN(arm64_dma_phys_limit);
	zone_size[ZONE_DMA] = max_dma - min;
#endif
	zone_size[ZONE_NORMAL] = max - max_dma;

#ifdef CONFIG_CMA_RTK_ALLOCATOR
    if (get_memory_size(GFP_DCU1) >= 0x20000000)
        dma_declare_contiguous(NULL, 256*MB, 0x02000000, max_dma);
    else
        dma_declare_contiguous(NULL, get_memory_size(GFP_DCU1) - 72*MB, 0x02000000, max_dma);
#endif

	memcpy(zhole_size, zone_size, sizeof(zhole_size));

	for_each_memblock(memory, reg) {
		unsigned long start = memblock_region_memory_base_pfn(reg);
		unsigned long end = memblock_region_memory_end_pfn(reg);

		if (start >= max)
			continue;

#ifdef CONFIG_ZONE_DMA
		if (start < max_dma) {
			unsigned long dma_end = min(end, max_dma);
			zhole_size[ZONE_DMA] -= dma_end - start;
		}
#endif
		if (end > max_dma) {
			unsigned long normal_end = min(end, max);
			unsigned long normal_start = max(start, max_dma);
			zhole_size[ZONE_NORMAL] -= normal_end - normal_start;
		}
	}

#ifdef CONFIG_CMA_RTK_ALLOCATOR
    if (get_memory_size(GFP_DCU2)) {
        if ((zone_size[ZONE_NORMAL] - zhole_size[ZONE_NORMAL]) == (get_memory_size(GFP_DCU2) >> PAGE_SHIFT)) {
            if (get_memory_size(GFP_DCU2) < (high_carvedout_size + ZRAM_RESERVED_SIZE + GPU_RESERVED_SIZE)) {
                zone_size[ZONE_MOVABLE] = (get_memory_size(GFP_DCU2) - high_carvedout_size) >> PAGE_SHIFT;
            } else {
                zone_size[ZONE_MOVABLE] = (get_memory_size(GFP_DCU2) - (high_carvedout_size + ZRAM_RESERVED_SIZE + GPU_RESERVED_SIZE)) >> PAGE_SHIFT;
            }
        } else {
            if (get_memory_size(GFP_DCU2) < (high_carvedout_size + GPU_RESERVED_SIZE)) {
                zone_size[ZONE_MOVABLE] = (get_memory_size(GFP_DCU2) - high_carvedout_size) >> PAGE_SHIFT;
            } else {
                zone_size[ZONE_MOVABLE] = (get_memory_size(GFP_DCU2) - (high_carvedout_size + GPU_RESERVED_SIZE)) >> PAGE_SHIFT;
            }
        }
        zone_size[ZONE_NORMAL] = zone_size[ZONE_NORMAL] - zone_size[ZONE_MOVABLE];

        if (zone_size[ZONE_MOVABLE]) {
			if ( ((zone_size[ZONE_DMA] + zone_size[ZONE_NORMAL]) << PAGE_SHIFT) != cma_high_start || 
				 ((zone_size[ZONE_DMA] + zone_size[ZONE_NORMAL] + zone_size[ZONE_MOVABLE]) << PAGE_SHIFT) != (cma_high_start + cma_high_size) ) {
				pr_err("not match to cma_high_start (%lx/%lx)\n", cma_high_start, cma_high_start + cma_high_size);
				BUG();
			}
			printk("### normal %lx %lx movable %lx %lx ###\n",
					zone_size[ZONE_NORMAL], zhole_size[ZONE_NORMAL],
					zone_size[ZONE_MOVABLE], zhole_size[ZONE_MOVABLE]);
        }
    }
#endif

	free_area_init_node(0, zone_size, min, zhole_size);
}

#ifdef CONFIG_HAVE_ARCH_PFN_VALID
int pfn_valid(unsigned long pfn)
{
	return memblock_is_memory(pfn << PAGE_SHIFT);
}
EXPORT_SYMBOL(pfn_valid);
#endif

#ifndef CONFIG_SPARSEMEM
static void arm64_memory_present(void)
{
}
#else
static void arm64_memory_present(void)
{
	struct memblock_region *reg;

	for_each_memblock(memory, reg)
		memory_present(0, memblock_region_memory_base_pfn(reg),
			       memblock_region_memory_end_pfn(reg));
}
#endif

static phys_addr_t memory_limit = (phys_addr_t)ULLONG_MAX;

/*
 * Limit the memory size that was specified via FDT.
 */
static int __init early_mem(char *p)
{
	if (!p)
		return 1;

	memory_limit = memparse(p, &p) & PAGE_MASK;
	pr_notice("Memory limited to %lldMB\n", memory_limit >> 20);

	return 0;
}
early_param("mem", early_mem);

void __init arm64_memblock_init(void)
{
	memblock_enforce_memory_limit(memory_limit);

	/*
	 * Register the kernel text, kernel data, initrd, and initial
	 * pagetables with memblock.
	 */
	memblock_reserve(__pa(_text), _end - _text);
#ifdef CONFIG_BLK_DEV_INITRD
	if (initrd_start)
		memblock_reserve(__virt_to_phys(initrd_start), initrd_end - initrd_start);
#endif

	early_init_fdt_scan_reserved_mem();

	/* 4GB maximum for 32-bit only capable devices */
	if (IS_ENABLED(CONFIG_ZONE_DMA))
		arm64_dma_phys_limit = max_zone_dma_phys();
	else
		arm64_dma_phys_limit = PHYS_MASK + 1;

#ifndef CONFIG_CMA_RTK_ALLOCATOR
	dma_contiguous_reserve(arm64_dma_phys_limit);
#else
	{
		unsigned long high_start = 0;
		unsigned long high_size = 0;
		unsigned long max = memblock_end_of_DRAM();

		high_start = arm64_dma_phys_limit;
		high_size = max - high_start;
		printk("HighMem: %08lx ~ %08lx, high_size = %08lx\n", high_start, max, high_size);

		high_carvedout_size = fdt_get_carvedout_mem_size_in_highmem(high_start, max);
		printk("Carvedout memory size in HighMem = %08lx\n", high_carvedout_size);

		if (get_memory_size(GFP_DCU2)) {
			if (get_memory_size(GFP_DCU2) < high_carvedout_size) {
				pr_err("[MM] ERROR! HighMem carved-out memory size is larger than DCU2!! \n");
				BUG();
			}
			if (high_size == get_memory_size(GFP_DCU2)) {
				if (get_memory_size(GFP_DCU2) < (high_carvedout_size + ZRAM_RESERVED_SIZE + GPU_RESERVED_SIZE)) {
					cma_high_size = get_memory_size(GFP_DCU2) - high_carvedout_size;
				} else {
					cma_high_size = get_memory_size(GFP_DCU2) - (high_carvedout_size + ZRAM_RESERVED_SIZE + GPU_RESERVED_SIZE);
				}
			} else {
				if (get_memory_size(GFP_DCU2) < (high_carvedout_size + GPU_RESERVED_SIZE)) {
					cma_high_size = get_memory_size(GFP_DCU2) - high_carvedout_size;
				} else {
					cma_high_size = get_memory_size(GFP_DCU2) - (high_carvedout_size + GPU_RESERVED_SIZE);
				}
			}
			cma_high_start = max - cma_high_size;

			if (cma_high_size) {
				printk("reserve %08lx - %08lx for high memory cma...\n",
						cma_high_start, cma_high_start + cma_high_size);
				memblock_reserve(cma_high_start, cma_high_size);
			}
		}
	}
#endif

	memblock_allow_resize();
	memblock_dump_all();
}

void __init bootmem_init(void)
{
	unsigned long min, max;

	min = PFN_UP(memblock_start_of_DRAM());
	max = PFN_DOWN(memblock_end_of_DRAM());
	pr_notice("[MEMINFO] bootmem_init: min = 0x%x, max = 0x%x, DRAM_size = 0x%x\n", min, max, max - min);
	DRAM_size = max - min;

	early_memtest(min << PAGE_SHIFT, max << PAGE_SHIFT);

	/*
	 * Sparsemem tries to allocate bootmem in memory_present(), so must be
	 * done after the fixed reservations.
	 */
	arm64_memory_present();

	sparse_init();
	zone_sizes_init(min, max);

	high_memory = __va((max << PAGE_SHIFT) - 1) + 1;
	max_pfn = max_low_pfn = max;
}

#ifndef CONFIG_SPARSEMEM_VMEMMAP
static inline void free_memmap(unsigned long start_pfn, unsigned long end_pfn)
{
	struct page *start_pg, *end_pg;
	unsigned long pg, pgend;

	/*
	 * Convert start_pfn/end_pfn to a struct page pointer.
	 */
	start_pg = pfn_to_page(start_pfn - 1) + 1;
	end_pg = pfn_to_page(end_pfn - 1) + 1;

	/*
	 * Convert to physical addresses, and round start upwards and end
	 * downwards.
	 */
	pg = (unsigned long)PAGE_ALIGN(__pa(start_pg));
	pgend = (unsigned long)__pa(end_pg) & PAGE_MASK;

	/*
	 * If there are free pages between these, free the section of the
	 * memmap array.
	 */
	if (pg < pgend)
		free_bootmem(pg, pgend - pg);
}

/*
 * The mem_map array can get very big. Free the unused area of the memory map.
 */
static void __init free_unused_memmap(void)
{
	unsigned long start, prev_end = 0;
	struct memblock_region *reg;

	for_each_memblock(memory, reg) {
		start = __phys_to_pfn(reg->base);

#ifdef CONFIG_SPARSEMEM
		/*
		 * Take care not to free memmap entries that don't exist due
		 * to SPARSEMEM sections which aren't present.
		 */
		start = min(start, ALIGN(prev_end, PAGES_PER_SECTION));
#endif
		/*
		 * If we had a previous bank, and there is a space between the
		 * current bank and the previous, free it.
		 */
		if (prev_end && prev_end < start)
			free_memmap(prev_end, start);

		/*
		 * Align up here since the VM subsystem insists that the
		 * memmap entries are valid from the bank end aligned to
		 * MAX_ORDER_NR_PAGES.
		 */
		prev_end = ALIGN(__phys_to_pfn(reg->base + reg->size),
				 MAX_ORDER_NR_PAGES);
	}

#ifdef CONFIG_SPARSEMEM
	if (!IS_ALIGNED(prev_end, PAGES_PER_SECTION))
		free_memmap(prev_end, ALIGN(prev_end, PAGES_PER_SECTION));
#endif
}
#endif	/* !CONFIG_SPARSEMEM_VMEMMAP */

/*
 * mem_init() marks the free areas in the mem_map and tells us how much memory
 * is free.  This is done after various parts of the system have claimed their
 * memory after the kernel image.
 */
void __init mem_init(void)
{
	swiotlb_init(1);

	set_max_mapnr(pfn_to_page(max_pfn) - mem_map);

#ifndef CONFIG_SPARSEMEM_VMEMMAP
	free_unused_memmap();
#endif
	/* this will put all unused low memory onto the freelists */
	free_all_bootmem();

	mem_init_print_info(NULL);

#define MLK(b, t) b, t, ((t) - (b)) >> 10
#define MLM(b, t) b, t, ((t) - (b)) >> 20
#define MLG(b, t) b, t, ((t) - (b)) >> 30
#define MLK_ROUNDUP(b, t) b, t, DIV_ROUND_UP(((t) - (b)), SZ_1K)

	pr_notice("Virtual kernel memory layout:\n"
#ifdef CONFIG_KASAN
		  "    kasan   : 0x%16lx - 0x%16lx   (%6ld GB)\n"
#endif
		  "    vmalloc : 0x%16lx - 0x%16lx   (%6ld GB)\n"
#ifdef CONFIG_SPARSEMEM_VMEMMAP
		  "    vmemmap : 0x%16lx - 0x%16lx   (%6ld GB maximum)\n"
		  "              0x%16lx - 0x%16lx   (%6ld MB actual)\n"
#endif
		  "    fixed   : 0x%16lx - 0x%16lx   (%6ld KB)\n"
		  "    PCI I/O : 0x%16lx - 0x%16lx   (%6ld MB)\n"
		  "    modules : 0x%16lx - 0x%16lx   (%6ld MB)\n"
		  "    memory  : 0x%16lx - 0x%16lx   (%6ld MB)\n"
		  "      .init : 0x%p" " - 0x%p" "   (%6ld KB)\n"
		  "      .text : 0x%p" " - 0x%p" "   (%6ld KB)\n"
		  "      .data : 0x%p" " - 0x%p" "   (%6ld KB)\n",
#ifdef CONFIG_KASAN
		  MLG(KASAN_SHADOW_START, KASAN_SHADOW_END),
#endif
		  MLG(VMALLOC_START, VMALLOC_END),
#ifdef CONFIG_SPARSEMEM_VMEMMAP
		  MLG((unsigned long)vmemmap,
		      (unsigned long)vmemmap + VMEMMAP_SIZE),
		  MLM((unsigned long)virt_to_page(PAGE_OFFSET),
		      (unsigned long)virt_to_page(high_memory)),
#endif
		  MLK(FIXADDR_START, FIXADDR_TOP),
		  MLM(PCI_IO_START, PCI_IO_END),
		  MLM(MODULES_VADDR, MODULES_END),
		  MLM(PAGE_OFFSET, (unsigned long)high_memory),
		  MLK_ROUNDUP(__init_begin, __init_end),
		  MLK_ROUNDUP(_text, _etext),
		  MLK_ROUNDUP(_sdata, _edata));

#undef MLK
#undef MLM
#undef MLK_ROUNDUP

	/*
	 * Check boundaries twice: Some fundamental inconsistencies can be
	 * detected at build time already.
	 */
#ifdef CONFIG_COMPAT
	BUILD_BUG_ON(TASK_SIZE_32			> TASK_SIZE_64);
#endif
	BUILD_BUG_ON(TASK_SIZE_64			> MODULES_VADDR);
	BUG_ON(TASK_SIZE_64				> MODULES_VADDR);

	if (PAGE_SIZE >= 16384 && get_num_physpages() <= 128) {
		extern int sysctl_overcommit_memory;
		/*
		 * On a machine this small we won't get anywhere without
		 * overcommit, so turn it on by default.
		 */
		sysctl_overcommit_memory = OVERCOMMIT_ALWAYS;
	}
}

void free_initmem(void)
{
	fixup_init();
	free_initmem_default(0);
	free_alternatives_memory();
}

#ifdef CONFIG_BLK_DEV_INITRD

static int keep_initrd __initdata;

void __init free_initrd_mem(unsigned long start, unsigned long end)
{
	if (!keep_initrd)
		free_reserved_area((void *)start, (void *)end, 0, "initrd");
}

static int __init keepinitrd_setup(char *__unused)
{
	keep_initrd = 1;
	return 1;
}

__setup("keepinitrd", keepinitrd_setup);
#endif
