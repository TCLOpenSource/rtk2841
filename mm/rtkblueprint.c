/*
 *  linux/mm/rtkblueprint.c
 *
 *  Copyright (C) 1991, 1992, 1993, 1994  Linus Torvalds
 *
 *  Support for blueprint of dvr zone, I-Chieh Hsu
 */

#include <linux/mm.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mmzone.h>
#include <linux/slab.h>
#include <linux/memblock.h>
#include <linux/rtkblueprint.h>
#include <linux/vmalloc.h>

#ifdef CONFIG_CMA_RTK_ALLOCATOR
#include <linux/rtkrecord.h>
#include <linux/pageremap.h>
#include <linux/auth.h>

void *dma_get_allocator(struct device *dev);
#endif

#ifdef CONFIG_CMA_RTK_LMK
#include<linux/sched.h>
void  rtkbp_lowmemorykiller(struct mem_bp *bp);
#endif

#define NR_REGIONS	7
#define MB_SIZE		1024*1024
#define MB_ALIGN(addr)	ALIGN(addr, MB_SIZE)

struct mem_region {
	phys_addr_t start;
	phys_addr_t size;
	int	    type;
};

struct ban_info {
	int nr_regions;
	struct mem_region region[NR_REGIONS];
};

static struct ban_info ban_info = {0};

static spinlock_t rtkbp_lock;

int add_ban_info(unsigned long addr, unsigned long size, int type)
{
	struct mem_region *region = &ban_info.region[ban_info.nr_regions];

	if (ban_info.nr_regions >= NR_REGIONS) {
		pr_err("rtkbp: NR_REGIONS too low, ignoring memory at 0x%08lx\n", addr);
		return -EINVAL;
	}

	if (type == BAN_NOT_USED) {
		if ((addr != ALIGN(addr, PAGE_SIZE << pageblock_order)) || 
		    (size != ALIGN(size, PAGE_SIZE << pageblock_order))) {
			pr_err("#########################################################\n");
			pr_err("rtkbp: %s addr: %08lx size: %08lx\n", __FUNCTION__, addr, size);
			pr_err("rtkbp: addr & size should be aligned to pageblock size...\n");
			pr_err("#########################################################\n");
			return -EINVAL;
		}

		if (memblock_reserve(addr, size) < 0) {
			pr_err("rtkbp: can not ban region %08lx - %08lx\n", addr, addr + size);
			BUG();
		}
	}

	region->start = MB_ALIGN(addr);
	region->size = size;
	region->type = type;

	if (region->size == 0)
		return -EINVAL;

	ban_info.nr_regions++;

	return 0;
}

bool is_banned(unsigned long pfn, int mask)
{
	unsigned long addr = pfn << PAGE_SHIFT;
	int i;

	for (i = 0; i < ban_info.nr_regions; i++) {
		struct mem_region *region = &ban_info.region[i];
		if ((addr >= region->start) && (addr < (region->start + region->size)) && 
		    (mask & region->type))
			return true;
	}

	return false;
}

static inline int bad_range(struct mem_bp *bp, struct mem_unit *unit)
{
	if ((unit >= bp->rtk_mem_map) && (unit < bp->max_mem_map)) {
		return 0;
	} else {
//		printk("rtkbp: bad index: %d \n", unit - bp->rtk_mem_map);
		return 1;
	}
}

static inline struct mem_unit *
expand(struct mem_bp *bp, struct mem_area *area, struct mem_unit *unit, int low, int high)
{
	unsigned long size = 1 << high;

	while (high > low) {
		area--;
		high--;
		size >>= 1;
		BUG_ON(bad_range(bp, &unit[size]));
		list_add(&unit[size].lru, &area->free_list);
		area->nr_free++;
		unit[size].order = RTK_BUDDY_FLAG | high;
	}
	return unit;
}

static struct mem_unit *alloc_mem_unit_bulk(struct mem_bp *bp, unsigned int order)
{
	struct mem_area * area;
	unsigned int current_order;
	struct mem_unit *unit;

    spin_lock(&rtkbp_lock);

	for (current_order = order; current_order < RTK_BP_MAX_ORDER; ++current_order) {
		area = bp->rtk_free_area + current_order;
		if (list_empty(&area->free_list))
			continue;

		unit = list_entry(area->free_list.next, struct mem_unit, lru);
//		printk(" @@ alloc unit: %p \n", unit);
		list_del(&unit->lru);
		unit->order = 0;
		area->nr_free--;
		bp->avail_size -= (1 << order);
        spin_unlock(&rtkbp_lock);
		return expand(bp, area, unit, order, current_order);
	}

    spin_unlock(&rtkbp_lock);
	return NULL;
}

static inline struct mem_unit *
unit_find_buddy(struct mem_unit *unit, unsigned long unit_idx, unsigned int order)
{
	unsigned long buddy_idx = unit_idx ^ (1 << order);

	return unit + (buddy_idx - unit_idx);
}

static void free_mem_unit_bulk(struct mem_bp *bp, struct mem_unit *unit, unsigned int order)
{
	struct mem_area *bp_area = bp->rtk_free_area;
	unsigned long unit_idx;
	int order_size = 1 << order;

    spin_lock(&rtkbp_lock);

	unit_idx = (unit - bp->rtk_mem_map) & ((1 << (RTK_BP_MAX_ORDER - 1)) - 1);
//	printk(" @@ 1unit: %p index: %lu \n", unit, unit_idx);

	BUG_ON(unit_idx & (order_size - 1));
	BUG_ON(bad_range(bp, unit));

	bp->avail_size += (1 << order);

	while (order < RTK_BP_MAX_ORDER - 1) {
		unsigned long combined_idx;
		struct mem_area *area;
		struct mem_unit *buddy;

//		printk(" @@ 2unit: %p index: %ld \n", unit, unit_idx);
		combined_idx = (unit_idx & ~(1 << order));
		buddy = unit_find_buddy(unit, unit_idx, order);
//		printk(" @@ buddy: %p combine: %ld \n", buddy, combined_idx);

		if (bad_range(bp, buddy))
			break;
		if (!(buddy->order & RTK_BUDDY_FLAG) || ((buddy->order & RTK_BUDDY_MASK) != order))
			break;		/* Move the buddy up one level. */
//		printk(" @@ combine buddy %p %p\n", unit, buddy);
		list_del(&buddy->lru);
		area = bp_area + order;
		area->nr_free--;
		buddy->order = 0;
		unit = unit + (combined_idx - unit_idx);
		unit_idx = combined_idx;
		order++;
	}
//	printk(" @@ end \n");
	unit->order = RTK_BUDDY_FLAG | order;
	list_add(&unit->lru, &bp_area[order].free_list);
	bp_area[order].nr_free++;

    spin_unlock(&rtkbp_lock);
}

void init_rtkbp(struct mem_bp *bp, unsigned long base_pfn, int count)
{
	int order;

	// init free lists
	for (order = 0; order < RTK_BP_MAX_ORDER ; order++) {
		INIT_LIST_HEAD(&bp->rtk_free_area[order].free_list);
		bp->rtk_free_area[order].nr_free = 0;
	}

	bp->rtk_mem_map = (struct mem_unit *)vmalloc(count * sizeof(struct mem_unit));
	BUG_ON(!bp->rtk_mem_map);
	bp->max_mem_map = bp->rtk_mem_map + count;
	bp->base_pfn = base_pfn;
	bp->avail_size = 0;
	memset(bp->rtk_mem_map, 0, count * sizeof(struct mem_unit));
	printk("rtkbp: memmap size: %lu \n", count * sizeof(struct mem_unit));
    spin_lock_init(&rtkbp_lock);

	// add the dvr zone into our free lists (use 1MB as unit)
	BUG_ON(count % 256);
	while ((count -= 256) >= 0) {
#ifndef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
		if (unlikely(!pfn_valid(base_pfn+count)))
			continue;
#endif
		if (unlikely(is_banned(base_pfn+count, BAN_ALL_TYPE)))
			continue;
		if (memblock_is_region_reserved((base_pfn + count) << PAGE_SHIFT, 256 << PAGE_SHIFT))
			free_mem_unit_bulk(bp, bp->rtk_mem_map + count, 8);
#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
		else if (!memblock_is_region_memory((base_pfn + count) << PAGE_SHIFT, 256 << PAGE_SHIFT))
			free_mem_unit_bulk(bp, bp->rtk_mem_map + count, 8);
#endif
		else
			printk("rtkbp: memory addr: %08lx size: %08x is not reserved by memblock...\n", 
				(base_pfn + count) << PAGE_SHIFT, 256 << PAGE_SHIFT);
	}

	show_rtkbp(bp);
}

void exit_rtkbp(struct mem_bp *bp)
{
	if (bp->rtk_mem_map) {
		vfree(bp->rtk_mem_map);
		bp->rtk_mem_map = 0;
		bp->max_mem_map = 0;
	}
}

unsigned long alloc_rtkbp_memory(struct mem_bp *bp, unsigned int order)
{
	struct mem_unit *unit;

	unit = alloc_mem_unit_bulk(bp, order);
	if (unit == 0) {
		show_rtkbp(bp);
		if (bp->base_pfn == ((struct mem_bp *)dma_get_allocator(NULL))->base_pfn) {
			printk("CMA DCU1 no free space for order %d\n", order);
		} else {
			printk("CMA DCU2 no free space for order %d\n", order);
		}

		dump_stack();

#ifdef CONFIG_CMA_RTK_ALLOCATOR
		list_all_rtk_memory_allocation_sort(list_mem_generic,NULL,NULL);
		printk("\n\tDCU1:\n");
		show_rtkbp((struct mem_bp *)dma_get_allocator(NULL));
		printk("\n\tDCU2:\n");
		show_rtkbp((struct mem_bp *)dma_get_allocator(auth_dev));
#endif

#ifdef CONFIG_CMA_RTK_LMK
		rtkbp_lowmemorykiller(bp);
#endif
		return INVALID_VAL;
	}

#ifdef CONFIG_CMA_RTK_LMK
	if (likely(current->mm))
		add_mm_counter(current->mm,MM_CMAPAGES, 1<<order);
	if(unlikely(order >8))
		rtkbp_lowmemorykiller(bp);
#endif

	pr_info("+++ ALLOC pfn: %lu order: %d \n", bp->base_pfn + (unit - bp->rtk_mem_map), order);
	return (unsigned long)(unit - bp->rtk_mem_map);
}

unsigned long alloc_rtkbp_memory_specific(struct mem_bp *bp, unsigned int order, unsigned long pfn)
{
	struct mem_unit *unit, *temp;
	struct mem_area * area;
	struct list_head *p, *head;
	unsigned int current_order;

	unit = bp->rtk_mem_map + (pfn - bp->base_pfn);

    spin_lock(&rtkbp_lock);
	// check if we can get the memory by expanding...
	for (current_order = order; current_order < RTK_BP_MAX_ORDER; ++current_order) {
		area = bp->rtk_free_area + current_order;
		if (list_empty(&area->free_list))
			continue;

		head = &area->free_list;
		list_for_each(p, head) {
			temp = list_entry(p, struct mem_unit, lru);
			if (unit == temp) {
				list_del(&temp->lru);
				temp->order = 0;
				area->nr_free--;
				bp->avail_size -= (1 << order);
				expand(bp, area, temp, order, current_order);
                spin_unlock(&rtkbp_lock);
				goto got;
			}
		}
	}

    spin_unlock(&rtkbp_lock);
	return INVALID_VAL;

got:
	pr_info("+++ ALLOC pfn: %lu order: %d \n", bp->base_pfn + (unit - bp->rtk_mem_map), order);
	pr_info("rtkbp: get physical address %08lx @ %08lx \n", 
		PAGE_SIZE << order, pfn << PAGE_SHIFT);

#ifdef CONFIG_CMA_RTK_LMK
	if (likely(current->mm))
		add_mm_counter(current->mm,MM_CMAPAGES, 1<<order);
#endif
	return pfn;
}

void free_rtkbp_memory(struct mem_bp *bp, unsigned long pageno, unsigned int order)
{
	pr_info("--- FREE pfn: %lu order: %d \n", bp->base_pfn + pageno, order);
	BUG_ON(bad_range(bp, bp->rtk_mem_map + pageno));
	free_mem_unit_bulk(bp, bp->rtk_mem_map + pageno, order);
#ifdef CONFIG_CMA_RTK_LMK
	if (likely(current->mm))
		sub_mm_counter(current->mm,MM_CMAPAGES,1<<order);
#endif
}

void show_rtkbp(struct mem_bp *bp)
{
	int idx;

	if (bp == NULL) {
		pr_err("\tNo BP info here...\n");
		return;
	}

	pr_warning("\t<<<FREE AREA BASE: %08lx>>>\n", bp->base_pfn << PAGE_SHIFT);
    spin_lock(&rtkbp_lock);
	for (idx = 0; idx < RTK_BP_MAX_ORDER; idx++) {
		struct list_head *up;
		struct mem_unit *unit;
		int index;

		pr_warning("\t%d:\t%d\n", idx, (int)bp->rtk_free_area[idx].nr_free);

		list_for_each(up, &bp->rtk_free_area[idx].free_list) {
			unit = list_entry(up, struct mem_unit, lru);
			index = unit - bp->rtk_mem_map;
			pr_warning("\t\tAddr: %08lx, order: %d \n",
				(bp->base_pfn + index) << PAGE_SHIFT, (int)(unit->order & RTK_BUDDY_MASK));
		}
	}
    spin_unlock(&rtkbp_lock);
}

