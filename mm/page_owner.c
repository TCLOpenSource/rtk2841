#include <linux/debugfs.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/bootmem.h>
#include <linux/stacktrace.h>
#include <linux/page_owner.h>
#include "internal.h"

static bool page_owner_disabled = true;
bool page_owner_inited __read_mostly;

static const char migrate_types[MIGRATE_TYPES] = {
	[MIGRATE_UNMOVABLE]	= 'U',
	[MIGRATE_MOVABLE]	= 'M',
	[MIGRATE_RECLAIMABLE]	= 'E',
#ifdef CONFIG_CMA
	[MIGRATE_CMA]		= 'C',
#endif
#ifdef CONFIG_MEMORY_ISOLATION
	[MIGRATE_ISOLATE]	= 'I',
#endif
};

static void init_early_allocated_pages(void);

static int early_page_owner_param(char *buf)
{
	if (!buf)
		return -EINVAL;

	if (strcmp(buf, "on") == 0)
		page_owner_disabled = false;

	return 0;
}
early_param("page_owner", early_page_owner_param);

static bool need_page_owner(void)
{
	if (page_owner_disabled)
		return false;

	return true;
}

static void init_page_owner(void)
{
	if (page_owner_disabled)
		return;

	page_owner_inited = true;
	init_early_allocated_pages();
}

struct page_ext_operations page_owner_ops = {
	.need = need_page_owner,
	.init = init_page_owner,
};

void __reset_page_owner(struct page *page, unsigned int order)
{
	int i;
	struct page_ext *page_ext;

	for (i = 0; i < (1 << order); i++) {
		page_ext = lookup_page_ext(page + i);
		__clear_bit(PAGE_EXT_OWNER, &page_ext->flags);
#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
		struct stack_trace trace = {
			.nr_entries = 0,
			.max_entries = ARRAY_SIZE(page_ext->trace_entries),
			.entries = &page_ext->trace_entries[0],
			.skip = 1,
		};

		save_stack_trace(&trace);

		page_ext->nr_entries = trace.nr_entries;

		__set_bit(PAGE_EXT_OWNER_FREED, &page_ext->flags);
#endif
	}
}

void __set_page_owner(struct page *page,
			#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
			unsigned int count,
			#else
			unsigned int order,
			#endif
			gfp_t gfp_mask)
{
	struct page_ext *page_ext = lookup_page_ext(page);
	struct stack_trace trace = {
		.nr_entries = 0,
		.max_entries = ARRAY_SIZE(page_ext->trace_entries),
		.entries = &page_ext->trace_entries[0],
		.skip = 1,
	};

	save_stack_trace(&trace);

	#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
	page_ext->count = count;
	#else
	page_ext->order = order;
	#endif
	page_ext->gfp_mask = gfp_mask;
	page_ext->pid = current->tgid;
	strncpy(page_ext->comm, current->comm, sizeof(page_ext->comm));
	page_ext->nr_entries = trace.nr_entries;

	__set_bit(PAGE_EXT_OWNER, &page_ext->flags);
#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
	__clear_bit(PAGE_EXT_OWNER_FREED, &page_ext->flags);
#endif
}

gfp_t __get_page_owner_gfp(struct page *page)
{
	struct page_ext *page_ext = lookup_page_ext(page);

	return page_ext->gfp_mask;
}

static void
print_page_owner_single_page_info(unsigned long pfn,
		struct page *page, struct page_ext *page_ext)
{
	int pageblock_mt, page_mt;
	struct stack_trace trace = {
		.nr_entries = page_ext->nr_entries,
		.entries = &page_ext->trace_entries[0],
	};

	pageblock_mt = get_pfnblock_migratetype(page, pfn);
	page_mt  = gfpflags_to_migratetype(page_ext->gfp_mask);

	pr_err(
			#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
			"Page size %u, mask 0x%x, type [%c], zone %s, pid %d, %s\n", page_ext->count * 4,
			#else
			"Page order %u, mask 0x%x, type [%c], zone %s, pid %d, %s\n", page_ext->order,
			#endif
			page_ext->gfp_mask, migrate_types[page_mt],
			page_zone(page)->name, page_ext->pid, page_ext->comm);

	/* Print information relevant to grouping pages by mobility */
	pr_err("PFN %lu Block %lu type %d %s Flags %s%s%s%s%s%s%s%s%s%s%s%s\n",
			pfn,
			pfn >> pageblock_order,
			pageblock_mt,
			pageblock_mt != page_mt ? "Fallback" : "        ",
			PageLocked(page)	? "K" : " ",
			PageError(page)		? "E" : " ",
			PageReferenced(page)	? "R" : " ",
			PageUptodate(page)	? "U" : " ",
			PageDirty(page)		? "D" : " ",
			PageLRU(page)		? "L" : " ",
			PageActive(page)	? "A" : " ",
			PageSlab(page)		? "PageSlab" : " ",
			PageWriteback(page)	? "W" : " ",
			PageCompound(page)	? "C" : " ",
			PageSwapCache(page)	? "PageSwapCache" : " ",
			PageMappedToDisk(page)	? "M" : " ");

	print_stack_trace(&trace, 0);
	pr_err("\n");

}

int __get_page_owner_single_page_info(unsigned long pfn)
{
	struct page *page = NULL;
	struct page_ext *page_ext;

	if (!page_owner_inited)
		return -EINVAL;

	drain_all_pages(NULL);

	if (!pfn_valid(pfn)) {
		return -EINVAL;
	}

	/* Check for holes within a MAX_ORDER area */
	if (!pfn_valid_within(pfn))
		return -EINVAL;

	page = pfn_to_page(pfn);

	page_ext = lookup_page_ext(page);

	/*
	 * Some pages could be missed by concurrent allocation or free,
	 * because we don't hold the zone lock.
	 */
	if (!test_bit(PAGE_EXT_OWNER, &page_ext->flags)
#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
		&& !test_bit(PAGE_EXT_OWNER_FREED, &page_ext->flags)
#endif
		) {
		pr_err("Query PFN (0x%x) is not marked by Page Owner\n", pfn);
		return -EINVAL;
	}

	print_page_owner_single_page_info(pfn, page, page_ext);

	return 1;

}

static ssize_t
print_page_owner(char __user *buf, size_t count, unsigned long pfn,
		struct page *page, struct page_ext *page_ext)
{
	int ret;
	int pageblock_mt, page_mt;
	char *kbuf;
	struct stack_trace trace = {
		.nr_entries = page_ext->nr_entries,
		.entries = &page_ext->trace_entries[0],
	};

	kbuf = kmalloc(count, GFP_KERNEL);
	if (!kbuf)
		return -ENOMEM;

	pageblock_mt = get_pfnblock_migratetype(page, pfn);
	page_mt  = gfpflags_to_migratetype(page_ext->gfp_mask);

	ret = snprintf(kbuf, count,
			#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
			"Page size %u, mask 0x%x, type [%c], zone %s, pid %d, %s\n", page_ext->count * 4,
			#else
			"Page order %u, mask 0x%x, type [%c], zone %s, pid %d, %s\n", page_ext->order,
			#endif
			page_ext->gfp_mask, migrate_types[page_mt],
			page_zone(page)->name, page_ext->pid, page_ext->comm);

	if (ret >= count)
		goto err;

	/* Print information relevant to grouping pages by mobility */
	ret += snprintf(kbuf + ret, count - ret,
			"PFN %lu Block %lu type %d %s Flags %s%s%s%s%s%s%s%s%s%s%s%s\n",
			pfn,
			pfn >> pageblock_order,
			pageblock_mt,
			pageblock_mt != page_mt ? "Fallback" : "        ",
			PageLocked(page)	? "K" : " ",
			PageError(page)		? "E" : " ",
			PageReferenced(page)	? "R" : " ",
			PageUptodate(page)	? "U" : " ",
			PageDirty(page)		? "D" : " ",
			PageLRU(page)		? "L" : " ",
			PageActive(page)	? "A" : " ",
			PageSlab(page)		? "PageSlab" : " ",
			PageWriteback(page)	? "W" : " ",
			PageCompound(page)	? "C" : " ",
			PageSwapCache(page)	? "PageSwapCache" : " ",
			PageMappedToDisk(page)	? "M" : " ");

	if (ret >= count)
		goto err;

	ret += snprint_stack_trace(kbuf + ret, count - ret, &trace, 0);
	if (ret >= count)
		goto err;

	ret += snprintf(kbuf + ret, count - ret, "\n");
	if (ret >= count)
		goto err;

	if (copy_to_user(buf, kbuf, ret))
		ret = -EFAULT;

	kfree(kbuf);
	return ret;

err:
	kfree(kbuf);
	return -ENOMEM;
}

void __dump_page_owner(struct page *page)
{
	struct page_ext *page_ext = lookup_page_ext(page);
	struct stack_trace trace = {
		.nr_entries = page_ext->nr_entries,
		.entries = &page_ext->trace_entries[0],
	};
	gfp_t gfp_mask = page_ext->gfp_mask;
	int mt = gfpflags_to_migratetype(gfp_mask);

	if (!test_bit(PAGE_EXT_OWNER, &page_ext->flags)) {
		pr_alert("page_owner info is not active (free page?)\n");
		return;
	}

	//pr_alert("page allocated via order %u, migratetype %s, "
	//		"gfp_mask %#x(%pGg)\n", page_ext->order,
	//		migratetype_names[mt], gfp_mask, &gfp_mask);
	pr_err("pid %d %s\n", &page_ext->pid, &page_ext->comm);
	print_stack_trace(&trace, 0);

	//if (page_ext->last_migrate_reason != -1)
	//	pr_alert("page has been migrated, last migrate reason: %s\n",
	//		migrate_reason_names[page_ext->last_migrate_reason]);
}

static ssize_t
read_page_owner(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	unsigned long pfn;
	struct page *page;
	struct page_ext *page_ext;

	if (!page_owner_inited)
		return -EINVAL;

	page = NULL;
	pfn = min_low_pfn + *ppos;

	/* Find a valid PFN or the start of a MAX_ORDER_NR_PAGES area */
	while (!pfn_valid(pfn) && (pfn & (MAX_ORDER_NR_PAGES - 1)) != 0)
		pfn++;

	drain_all_pages(NULL);

	/* Find an allocated page */
	for (; pfn < max_pfn; pfn++) {
		/*
		 * If the new page is in a new MAX_ORDER_NR_PAGES area,
		 * validate the area as existing, skip it if not
		 */
		if ((pfn & (MAX_ORDER_NR_PAGES - 1)) == 0 && !pfn_valid(pfn)) {
			pfn += MAX_ORDER_NR_PAGES - 1;
			continue;
		}

		/* Check for holes within a MAX_ORDER area */
		if (!pfn_valid_within(pfn))
			continue;

		page = pfn_to_page(pfn);
		if (PageBuddy(page)) {
			unsigned long freepage_order = page_order_unsafe(page);

			if (freepage_order < MAX_ORDER)
				pfn += (1UL << freepage_order) - 1;
			continue;
		}

		page_ext = lookup_page_ext(page);

		/*
		 * Some pages could be missed by concurrent allocation or free,
		 * because we don't hold the zone lock.
		 */
		if (!test_bit(PAGE_EXT_OWNER, &page_ext->flags))
			continue;

		/* Record the next PFN to read in the file offset */
		*ppos = (pfn - min_low_pfn) + 1;

		return print_page_owner(buf, count, pfn, page, page_ext);
	}

	return 0;
}

#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
static ssize_t
read_page_owner_freed(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	unsigned long pfn;
	struct page *page;
	struct page_ext *page_ext;

	if (!page_owner_inited)
		return -EINVAL;

	page = NULL;
	pfn = min_low_pfn + *ppos;

	/* Find a valid PFN or the start of a MAX_ORDER_NR_PAGES area */
	while (!pfn_valid(pfn) && (pfn & (MAX_ORDER_NR_PAGES - 1)) != 0)
		pfn++;

	drain_all_pages(NULL);

	/* Find an allocated page */
	for (; pfn < max_pfn; pfn++) {
		/*
		 * If the new page is in a new MAX_ORDER_NR_PAGES area,
		 * validate the area as existing, skip it if not
		 */
		if ((pfn & (MAX_ORDER_NR_PAGES - 1)) == 0 && !pfn_valid(pfn)) {
			pfn += MAX_ORDER_NR_PAGES - 1;
			continue;
		}

		/* Check for holes within a MAX_ORDER area */
		if (!pfn_valid_within(pfn))
			continue;

		page = pfn_to_page(pfn);
		if (PageBuddy(page)) {
			unsigned long freepage_order = page_order_unsafe(page);

			if (freepage_order < MAX_ORDER)
				pfn += (1UL << freepage_order) - 1;
			continue;
		}

		page_ext = lookup_page_ext(page);

		/*
		 * Some pages could be missed by concurrent allocation or free,
		 * because we don't hold the zone lock.
		 */
		if (!test_bit(PAGE_EXT_OWNER_FREED, &page_ext->flags))
			continue;

		/* Record the next PFN to read in the file offset */
		*ppos = (pfn - min_low_pfn) + 1;

		return print_page_owner(buf, count, pfn, page, page_ext);
	}

	return 0;
}
#endif

static void init_pages_in_zone(pg_data_t *pgdat, struct zone *zone)
{
	struct page *page;
	struct page_ext *page_ext;
	unsigned long pfn = zone->zone_start_pfn, block_end_pfn;
	unsigned long end_pfn = pfn + zone->spanned_pages;
	unsigned long count = 0;

	/* Scan block by block. First and last block may be incomplete */
	pfn = zone->zone_start_pfn;

	/*
	 * Walk the zone in pageblock_nr_pages steps. If a page block spans
	 * a zone boundary, it will be double counted between zones. This does
	 * not matter as the mixed block count will still be correct
	 */
	for (; pfn < end_pfn; ) {
		if (!pfn_valid(pfn)) {
			pfn = ALIGN(pfn + 1, MAX_ORDER_NR_PAGES);
			continue;
		}

		block_end_pfn = ALIGN(pfn + 1, pageblock_nr_pages);
		block_end_pfn = min(block_end_pfn, end_pfn);

		page = pfn_to_page(pfn);

		for (; pfn < block_end_pfn; pfn++) {
			if (!pfn_valid_within(pfn))
				continue;

			page = pfn_to_page(pfn);

			if (page_zone(page) != zone)
				continue;

			/*
			 * We are safe to check buddy flag and order, because
			 * this is init stage and only single thread runs.
			 */
			if (PageBuddy(page)) {
				pfn += (1UL << page_order(page)) - 1;
				continue;
			}

			if (PageReserved(page))
				continue;

			page_ext = lookup_page_ext(page);

			/* Maybe overraping zone */
			if (test_bit(PAGE_EXT_OWNER, &page_ext->flags))
				continue;

			/* Found early allocated page */
			// Temp not set, due to kernel 4.4.3 not calling SetPageReserved in memmap_init_zone
			#if 0
			set_page_owner(page, 0, 0);
			#endif
			count++;
		}
	}

	pr_info("Node %d, zone %8s: page owner found early allocated %lu pages\n",
		pgdat->node_id, zone->name, count);
}

static void init_zones_in_node(pg_data_t *pgdat)
{
	struct zone *zone;
	struct zone *node_zones = pgdat->node_zones;
	unsigned long flags;

	for (zone = node_zones; zone - node_zones < MAX_NR_ZONES; ++zone) {
		if (!populated_zone(zone))
			continue;

		spin_lock_irqsave(&zone->lock, flags);
		init_pages_in_zone(pgdat, zone);
		spin_unlock_irqrestore(&zone->lock, flags);
	}
}

static void init_early_allocated_pages(void)
{
	pg_data_t *pgdat;

	drain_all_pages(NULL);
	for_each_online_pgdat(pgdat)
		init_zones_in_node(pgdat);
}

static const struct file_operations proc_page_owner_operations = {
	.read		= read_page_owner,
};

#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
static const struct file_operations proc_page_owner_freed_operations = {
	.read		= read_page_owner_freed,
};
#endif

static int __init pageowner_init(void)
{
	struct dentry *dentry;
#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
	struct dentry *dentry_freed;
#endif

	if (!page_owner_inited) {
		pr_info("page_owner is disabled\n");
		return 0;
	}

	dentry = debugfs_create_file("page_owner", S_IRUSR, NULL,
			NULL, &proc_page_owner_operations);
	if (IS_ERR(dentry))
		return PTR_ERR(dentry);

#ifdef CONFIG_PAGE_OWNER_FREED_TRACK
	dentry_freed = debugfs_create_file("page_owner_freed", S_IRUSR, NULL,
			NULL, &proc_page_owner_freed_operations);
	if (IS_ERR(dentry_freed))
		return PTR_ERR(dentry_freed);
#endif

	return 0;
}
late_initcall(pageowner_init)
