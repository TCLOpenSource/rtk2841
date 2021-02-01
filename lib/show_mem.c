/*
 * Generic show_mem() implementation
 *
 * Copyright (C) 2008 Johannes Weiner <hannes@saeurebad.de>
 * All code subject to the GPL version 2.
 */

#include <linux/mm.h>
#include <linux/quicklist.h>
#include <linux/cma.h>
#include <linux/seq_file.h>

void show_mem(unsigned int filter)
{
	pg_data_t *pgdat;
	unsigned long total = 0, reserved = 0, highmem = 0;

	printk("Mem-Info:\n");
	show_free_areas(filter);

	for_each_online_pgdat(pgdat) {
		unsigned long flags;
		int zoneid;

		pgdat_resize_lock(pgdat, &flags);
		for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
			struct zone *zone = &pgdat->node_zones[zoneid];
			if (!populated_zone(zone))
				continue;

			total += zone->present_pages;
			reserved += zone->present_pages - zone->managed_pages;

			if (is_highmem_idx(zoneid))
				highmem += zone->present_pages;
		}
		pgdat_resize_unlock(pgdat, &flags);
	}

	printk("%lu pages RAM\n", total);
	printk("%lu pages HighMem/MovableOnly\n", highmem);
	printk("%lu pages reserved\n", reserved);
#ifdef CONFIG_CMA
	printk("%lu pages cma reserved\n", totalcma_pages);
#endif
#ifdef CONFIG_QUICKLIST
	printk("%lu pages in pagetable cache\n",
		quicklist_total_size());
#endif
#ifdef CONFIG_MEMORY_FAILURE
	printk("%lu pages hwpoisoned\n", atomic_long_read(&num_poisoned_pages));
#endif
}

void show_mem_ex(unsigned int filter, struct seq_file *m)
{
#define K(x) ((x) << (PAGE_SHIFT - 10))
	pg_data_t *pgdat;
	unsigned long total = 0, reserved = 0, highmem = 0;

	seq_printf(m, "Mem-Info:\n");
	show_free_areas(filter);

	for_each_online_pgdat(pgdat) {
		unsigned long flags;
		int zoneid;

		pgdat_resize_lock(pgdat, &flags);
		for (zoneid = 0; zoneid < MAX_NR_ZONES; zoneid++) {
			struct zone *zone = &pgdat->node_zones[zoneid];
			if (!populated_zone(zone))
				continue;

			total += zone->present_pages;
			reserved += zone->present_pages - zone->managed_pages;

			if (is_highmem_idx(zoneid))
				highmem += zone->present_pages;
		}
		pgdat_resize_unlock(pgdat, &flags);
	}

	seq_printf(m, "%lu pages(%lu kB) RAM\n", total, K(total));
	seq_printf(m, "%lu pages(%lu kB) HighMem/MovableOnly\n", highmem, K(highmem));
	seq_printf(m, "%lu pages(%lu kB) reserved\n", reserved, K(reserved));
#ifdef CONFIG_CMA
	seq_printf(m, "%lu pages(%lu kB) cma reserved\n", totalcma_pages, K(totalcma_pages));
#endif
#ifdef CONFIG_QUICKLIST
	seq_printf(m, "%lu pages(%lu kB) in pagetable cache\n",
		quicklist_total_size(), K(quicklist_total_size()));
#endif
#ifdef CONFIG_MEMORY_FAILURE
	seq_printf(m, "%lu pages(%lu kB) hwpoisoned\n", atomic_long_read(&num_poisoned_pages), K(atomic_long_read(&num_poisoned_pages)));
#endif
#undef K
}
