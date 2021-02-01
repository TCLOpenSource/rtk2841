/*
 *  linux/mm/pageremap.c
 *
 *  Copyright (C) 1991, 1992, 1993, 1994  Linus Torvalds
 *
 *  Support of page remapping, EJ Hsu
 */

#include <linux/mm.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mmzone.h>
#include <linux/swap.h>
#include <linux/rmap.h>
#include <linux/semaphore.h>
#include <linux/mm_inline.h>
#include <linux/delay.h>
#include <linux/gfp.h>
#include <linux/smp.h>
#include <linux/bootmem.h>
#include <linux/migrate.h>
#include <linux/vmalloc.h>
#include <linux/dma-contiguous.h>
#include <linux/cma.h>
#include <linux/rtkblueprint.h>
#include <linux/rtkrecord.h>
#include <linux/pageremap.h>
#include <linux/auth.h>
#ifdef CONFIG_CMA_TRACK_USE_PAGE_OWNER
#include <linux/page_owner.h>
#endif

#include <asm/cacheflush.h>

typedef bool (*page_filter_t)(struct page *);

#ifdef CONFIG_CMA_FIRST_POLICY

extern int cma_reserved;

#ifdef CONFIG_QUICK_HIBERNATION
extern struct list_head dcu1_record_list;
extern struct list_head dcu2_record_list;

static record_struct *curr_record = NULL;
static struct page *pagelist = NULL;
static int page_max = 0;
static int page_cnt = 0;
#endif
#endif

#define REMAP_ZONE		0
#define REMAP_PAGE		1
#define REMAP_CMA1		2
#define REMAP_CMA2		3

#define REMAP_IN_SUSPEND	0x80000000

#define RESERVED_COUNT		1024

DEFINE_SEMAPHORE(remap_sem);
static int dcu1_size = 0;
static int dcu2_size = 0;

static struct page *rtk_page_cache = NULL;
static unsigned long *rtk_cache_bitmap = NULL;
static struct page *rtk_page_cache_low = NULL;
static unsigned long *rtk_cache_bitmap_low = NULL;
static DEFINE_MUTEX(cache_mutex);

bool _debug_cma_guardband_enabled __read_mostly;
bool _debug_cma_deferfree_enabled __read_mostly;

void add_memory_size(int flags, int size)
{
	switch (flags) {
		case GFP_DCU1:
			dcu1_size += size;
			break;

		case GFP_DCU2:
			dcu2_size += size;
			break;
	}
}
EXPORT_SYMBOL(add_memory_size);

int get_memory_size(int flags)
{
	switch (flags) {
		case GFP_DCU1:
			return dcu1_size;

		case GFP_DCU2:
			return dcu2_size;

		default:
			return 0;
	}
}
EXPORT_SYMBOL(get_memory_size);

bool check_cma_memory(unsigned long pfn)
{
	if (dcu1_size && in_cma_range(NULL, pfn))
		return true;
	if (dcu2_size && in_cma_range(auth_dev, pfn))
		return true;
	return false;
}
EXPORT_SYMBOL(check_cma_memory);

unsigned long get_cma_avail_size(void)
{
	unsigned long size = 0;

	if (dcu1_size)
		size += cma_get_avail_size(NULL);
	if (dcu2_size)
		size += cma_get_avail_size(auth_dev);

	if (size)
		return (size << PAGE_SHIFT);
	else
		return size;
}
EXPORT_SYMBOL(get_cma_avail_size);

static int cal_order(size_t size)
{
	return (size == (1 << (fls(size)-1))) ? fls(size)-1 : fls(size);
}

void *dma_get_allocator(struct device *dev);

static void list_cma_usage(void)
{
#ifdef CONFIG_CMA_RTK_ALLOCATOR
	list_all_rtk_memory_allocation_sort(list_mem_generic, NULL, NULL);
	printk("\n\tDCU1:\n");
	show_rtkbp((struct mem_bp *)dma_get_allocator(NULL));
	printk("\n\tDCU2:\n");
	show_rtkbp((struct mem_bp *)dma_get_allocator(auth_dev));
#endif
}

static struct page *alloc_contiguous_memory(size_t size, int flags, const void *caller)
{
//	void *ret = 0;
	int count = 0;
	struct page *page = NULL;

	if (DRAM_size == 0x20000) {
		flags = GFP_DCU1;
	}

	BUG_ON(size & (PAGE_SIZE - 1));
	count = size >> PAGE_SHIFT;
	if (count <= 0) {
		pr_err("[CMA ERR] %pF requests invalid CMA size %ld (count %d) \n", caller, size, count);
		return 0;
	}

	if (count && count <= MAX_CACHE_COUNT) {
		if (flags & GFP_DCU2) {
			int pageno;
			mutex_lock(&cache_mutex);
			if (!rtk_page_cache) {
				int bitmap_size = BITS_TO_LONGS(DEF_CACHE_SIZE / PAGE_SIZE) * sizeof(long);
				rtk_page_cache = dma_alloc_from_contiguous(auth_dev, DEF_CACHE_SIZE / PAGE_SIZE, 0);
				if (!rtk_page_cache) {
					pr_info("remap: can not allocate page cache on DCU2...\n");
					mutex_unlock(&cache_mutex);
					return 0;
				}
				rtk_cache_bitmap = kzalloc(bitmap_size, GFP_KERNEL);
				BUG_ON(!rtk_cache_bitmap);
			}
			pageno = bitmap_find_next_zero_area(rtk_cache_bitmap, DEF_CACHE_SIZE / PAGE_SIZE, 0, count, 0);
			if (pageno >= DEF_CACHE_SIZE / PAGE_SIZE) {
				mutex_unlock(&cache_mutex);
				pr_info("remap: not enough cache memory for DCU2...\n");
				// fall through...
			} else {
				pr_info("remap: alloc pageno: %d count: %d\n", pageno, count);
				bitmap_set(rtk_cache_bitmap, pageno, count);
//				printk("weight: %d \n", __bitmap_weight(rtk_cache_bitmap, DEF_CACHE_SIZE / PAGE_SIZE));
				mutex_unlock(&cache_mutex);
				page = rtk_page_cache + pageno;
				SetPageRTKCache(page);
				goto out;
			}
		} else if (flags & GFP_DCU1) {
			int pageno;
			mutex_lock(&cache_mutex);
			if (!rtk_page_cache_low) {
				int bitmap_size = BITS_TO_LONGS(DEF_CACHE_SIZE_LOW / PAGE_SIZE) * sizeof(long);
				rtk_page_cache_low = dma_alloc_from_contiguous(NULL, DEF_CACHE_SIZE_LOW / PAGE_SIZE, 0);
				if (!rtk_page_cache_low) {
					pr_info("remap: can not allocate page cache on DCU1...\n");
					mutex_unlock(&cache_mutex);
					return 0;
				}
				rtk_cache_bitmap_low = kzalloc(bitmap_size, GFP_KERNEL);
				BUG_ON(!rtk_cache_bitmap_low);
			}
			pageno = bitmap_find_next_zero_area(rtk_cache_bitmap_low, DEF_CACHE_SIZE_LOW / PAGE_SIZE, 0, count, 0);
			if (pageno >= DEF_CACHE_SIZE_LOW / PAGE_SIZE) {
				mutex_unlock(&cache_mutex);
				pr_debug("remap: not enough cache memory for DCU1...\n");
				// fall through...
			} else {
				pr_debug("remap: alloc pageno: %d count: %d\n", pageno, count);
				bitmap_set(rtk_cache_bitmap_low, pageno, count);
//				printk("weight: %d \n", __bitmap_weight(rtk_cache_bitmap_low, DEF_CACHE_SIZE_LOW / PAGE_SIZE));
				mutex_unlock(&cache_mutex);
				page = rtk_page_cache_low + pageno;
				SetPageRTKCache(page);
				goto out;
			}
		} else {
			if ((flags & GFP_DCU2_FIRST) && rtk_page_cache) {
				int pageno;
				mutex_lock(&cache_mutex);
				pageno = bitmap_find_next_zero_area(rtk_cache_bitmap, DEF_CACHE_SIZE / PAGE_SIZE, 0, count, 0);
				if (pageno >= DEF_CACHE_SIZE / PAGE_SIZE) {
					mutex_unlock(&cache_mutex);
					pr_info("remap: not enough cache memory for DCU2...\n");
					// fall through...
				} else {
					pr_info("remap: alloc pageno: %d count: %d\n", pageno, count);
					bitmap_set(rtk_cache_bitmap, pageno, count);
//					printk("weight: %d \n", __bitmap_weight(rtk_cache_bitmap, DEF_CACHE_SIZE / PAGE_SIZE));
					mutex_unlock(&cache_mutex);
					page = rtk_page_cache + pageno;
					SetPageRTKCache(page);
					goto out;
				}
			} else if ((flags & GFP_DCU1_FIRST) && rtk_page_cache_low) {
				int pageno;
				mutex_lock(&cache_mutex);
				pageno = bitmap_find_next_zero_area(rtk_cache_bitmap_low, DEF_CACHE_SIZE_LOW / PAGE_SIZE, 0, count, 0);
				if (pageno >= DEF_CACHE_SIZE_LOW / PAGE_SIZE) {
					mutex_unlock(&cache_mutex);
					pr_debug("remap: not enough cache memory for DCU1...\n");
					// fall through...
				} else {
					pr_debug("remap: alloc pageno: %d count: %d\n", pageno, count);
					bitmap_set(rtk_cache_bitmap_low, pageno, count);
//					printk("weight: %d \n", __bitmap_weight(rtk_cache_bitmap_low, DEF_CACHE_SIZE_LOW / PAGE_SIZE));
					mutex_unlock(&cache_mutex);
					page = rtk_page_cache_low + pageno;
					SetPageRTKCache(page);
					goto out;
				}
			}

			if (flags & GFP_DCU2_FIRST)
				page = alloc_pages(GFP_KERNEL | __GFP_HIGHMEM, cal_order(count));
			else if (flags & GFP_DCU2)
				page = alloc_pages(GFP_KERNEL, cal_order(count));
			if (page) {
				SetPageRTKCache(page);
				split_page(page, cal_order(count));
				goto out;
			} else {
				pr_info("remap: not enough cache memory for DCU1...\n");
				// fall through...
			}
		}
	}

	if (!flags || (flags & GFP_DCU1_FIRST)) {
		page = dma_alloc_from_contiguous(NULL, count, 0);
		if (!page) {
			page = dma_alloc_from_contiguous(auth_dev, count, 0);
			if (!page) {
				pr_err("[CMA ERR] %pF requests count %d as DCU1_FIRST, still no available page in DCU2\n", caller, count);
				list_cma_usage();
			}
		}
	} else if (flags & GFP_DCU2_FIRST) {
		page = dma_alloc_from_contiguous(auth_dev, count, 0);
		if (!page) {
			page = dma_alloc_from_contiguous(NULL, count, 0);
			if (!page) {
				pr_err("[CMA ERR] %pF requests count %d as DCU2_FIRST, still no available page in DCU1\n", caller, count);
				list_cma_usage();
			}
		}
	} else if (flags & GFP_DCU1) {
		page = dma_alloc_from_contiguous(NULL, count, 0);
		if (!page) {
			pr_err("[CMA ERR] %pF requests count %d from DCU1, no available page in DCU1\n", caller, count);
			list_cma_usage();
		}
	} else if (flags & GFP_DCU2) {
		page = dma_alloc_from_contiguous(auth_dev, count, 0);
		if (!page) {
			pr_err("[CMA ERR] %pF requests count %d from DCU2, no available page in DCU2\n", caller, count);
			list_cma_usage();
		}
	} else {
		pr_err("remap: wrong allocation flags: %08x\n", flags);
		page = 0;
	}

//	if (!page)
//		goto out;
//
//	/* we will flush cache later if page is in high memory... */
//	if (!PageHighMem(page)) {
//		unsigned long phys_addr = page_to_pfn(page) << PAGE_SHIFT;
//
//		ret = page_address(page);
//		if (ret) {
//			dmac_flush_range(ret, ret + size);
//			outer_flush_range(phys_addr, phys_addr + size);
//		} else {
//			BUG();
//		}
//	}
out:
	return page;
}
 
static int free_contiguous_memory(struct page *page, int count)
{
	if (PageRTKCache(page)) {
#ifdef CONFIG_HIGHMEM
		if (PageHighMem(page) && in_cma_range(auth_dev, page_to_pfn(page))) {
#else
		if (in_cma_range(auth_dev, page_to_pfn(page))) {
#endif
			int i;
			for (i = 0; i < count; i++) {
				if (page_count(page + i) != 1) {
					pr_err("remap: page %p (DCU2) reference count is wrong...\n", page);
					BUG();
				}
			}
			pr_info("remap: free pageno: %ld count: %d\n", page - rtk_page_cache, count);
			ClearPageRTKCache(page);
			mutex_lock(&cache_mutex);
			bitmap_clear(rtk_cache_bitmap, page - rtk_page_cache, count);
			mutex_unlock(&cache_mutex);
		} else if (in_cma_range(NULL, page_to_pfn(page))) {
			int i;
			for (i = 0; i < count; i++) {
				if (page_count(page + i) != 1) {
					pr_err("remap: page %p (DCU1) reference count is wrong...\n", page);
					BUG();
				}
			}
			pr_debug("remap: free pageno: %d count: %d\n", page - rtk_page_cache_low, count);
			ClearPageRTKCache(page);
			mutex_lock(&cache_mutex);
			bitmap_clear(rtk_cache_bitmap_low, page - rtk_page_cache_low, count);
			mutex_unlock(&cache_mutex);
		} else {
			if (page_count(page) != 1) {
				pr_err("remap: page %p (DCU1) reference count is wrong...\n", page);
				BUG();
			}
			pr_info("remap: free (high=%d)page %p count: %d\n", PageHighMem(page), page, count);
			ClearPageRTKCache(page);
			free_contig_range(page_to_pfn(page), 1 << cal_order(count));
		}

		return 0;
	}

	if (!dma_release_from_contiguous(NULL, page, count) && !dma_release_from_contiguous(auth_dev, page, count)) {
		BUG();
	}

	return 0;
}

unsigned long pli_malloc(size_t size, int flags)
{
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("pli malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	/* work-around for tlb table-walk problem */
	{
		unsigned long *vaddr;

		vaddr = kmap_atomic(page);
		*vaddr = phys_addr;
		kunmap_atomic(vaddr);
	}

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | BUDDY_ID | count_page, 0, __builtin_return_address(0))) {
		free_contiguous_memory(page, count);

		return INVALID_VAL;
	}
out:
	pr_info("%s(): returned %lx\n", __func__, phys_addr);
	return phys_addr;
}
EXPORT_SYMBOL(pli_malloc);

unsigned long pli_malloc_mesg(size_t size, int flags, char *mesg)
{
	int count = 0;
	struct page *page;
	unsigned long phys_addr = INVALID_VAL;
	char *ptr = NULL;

	int size_page, size_order;
	int count_page, count_order;

	ptr = kmalloc(STR_LENGTH, GFP_KERNEL);
	if (unlikely(!ptr)){
		pr_err("%s:kmalloc fail!\n",__func__);
		return INVALID_VAL;
	}

	memset(ptr,0,STR_LENGTH);
	strncpy(ptr,mesg,STR_LENGTH-1);

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("pli malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	/* work-around for tlb table-walk problem */
	{
		unsigned long *vaddr;

		vaddr = kmap_atomic(page);
		*vaddr = phys_addr;
		kunmap_atomic(vaddr);
	}

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | BUDDY_MESG_ID | count_page, 0, ptr)) {
		free_contiguous_memory(page, count);

		return INVALID_VAL;
	}
out:
	pr_info("%s(): returned %lx\n", __func__, phys_addr);
	return phys_addr;
}
EXPORT_SYMBOL(pli_malloc_mesg);

void pli_free_mesg(const unsigned long arg)
{
	int value, count;
	rtk_record *ptr = NULL;
	char *caller = NULL;

	value = rtk_record_lookup_ex(arg, &ptr, true);
	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: free memory (%lx) signature error...\n", arg);
		BUG();
	} else {
		caller = (char *)ptr->caller;

		if (need_debug_cma_deferfree()) {
			rtk_record_tag_set(ptr, RTK_RECORD_TAG_DEFER_FREE);
			/* defer free not alloc, mark it */
			//rtk_record_delete((unsigned long)arg);
		} else 
			rtk_record_delete((unsigned long)arg);

		if ((value & ID_MASK) == BUDDY_MESG_ID) {
			if (need_debug_cma_guardband()) {
				count = dvr_guardband_check(arg, value);
			} else {
				count = value & 0x00ffffff;
			}

			if (need_debug_cma_deferfree()) {
				/* defer free not alloc, mark it */
				//free_contiguous_memory(pfn_to_page(arg >> PAGE_SHIFT), count);
				//if(caller)
				//	kfree((void *)caller);
				dvr_guardband_padding(pfn_to_page(arg >> PAGE_SHIFT), 1, 0);
			} else {
				free_contiguous_memory(pfn_to_page(arg >> PAGE_SHIFT), count);
				if(caller)
					kfree((void *)caller);
			}
		} else {
			BUG();
		}
	}
}
EXPORT_SYMBOL(pli_free_mesg);


void pli_free(const unsigned long arg)
{
	int value, count;
	rtk_record *ptr = NULL;

	value = rtk_record_lookup_ex(arg, &ptr, true);
	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: free memory (%lx) signature error...\n", arg);
		BUG();
	} else {
		if (need_debug_cma_deferfree()) {
			rtk_record_tag_set(ptr, RTK_RECORD_TAG_DEFER_FREE);
			/* defer free not alloc, mark it */
			//rtk_record_delete((unsigned long)arg);
		} else {
			rtk_record_delete((unsigned long)arg);
		}

		if ((value & ID_MASK) == BUDDY_ID) {
			if (need_debug_cma_guardband()) {
				count = dvr_guardband_check(arg, value);
			} else {
				count = value & 0x00ffffff;
			}

			if (need_debug_cma_deferfree()) {
				/* defer free not alloc, mark it */
				//free_contiguous_memory(pfn_to_page(arg >> PAGE_SHIFT), count);
				dvr_guardband_padding(pfn_to_page(arg >> PAGE_SHIFT), 1, 0);
			} else {
				free_contiguous_memory(pfn_to_page(arg >> PAGE_SHIFT), count);
			}
		} else {
			BUG();
		}
	}
}
EXPORT_SYMBOL(pli_free);

static void *remap_memory(unsigned long phys_addr, size_t size, pgprot_t prot, const void *caller)
{
	struct vm_struct *area;
	unsigned long addr;

	area = get_vm_area_caller(size, VM_DVR | VM_IOREMAP | VM_USERMAP, caller);
	if (!area)
		return NULL;

	addr = (unsigned long)area->addr;
	area->phys_addr = phys_addr;

	if (ioremap_page_range(addr, addr + size, area->phys_addr, prot)) {
		vunmap((void *)addr);
		return NULL;
	}

	return (void *)addr;
}

void *dvr_remap_cached_memory(unsigned long phys_addr, size_t size, const void *caller)
{
	return remap_memory(phys_addr, size, pgprot_kernel, caller);
}
EXPORT_SYMBOL(dvr_remap_cached_memory);

void *dvr_remap_uncached_memory(unsigned long phys_addr, size_t size, const void *caller)
{
	return remap_memory(phys_addr, size, pgprot_noncached(pgprot_kernel), caller);
}
EXPORT_SYMBOL(dvr_remap_uncached_memory);

void dvr_unmap_memory(void *cpu_addr, size_t size)
{
	unsigned int flags = VM_DVR | VM_IOREMAP | VM_USERMAP;
	struct vm_struct *area = find_vm_area(cpu_addr);

	if (!area || (area->flags & flags) != flags) {
		WARN(1, "trying to free invalid uncached area: %p\n", cpu_addr);
		return;
	}

	unmap_kernel_range((unsigned long)cpu_addr, size);
	vunmap(cpu_addr);
}
EXPORT_SYMBOL(dvr_unmap_memory);

unsigned long dvr_to_phys(const void *dvr_addr)
{
	if (((unsigned long)dvr_addr > PAGE_OFFSET) && ((unsigned long)dvr_addr < (unsigned long)high_memory))
		return __pa(dvr_addr);
	else if (is_vmalloc_addr(dvr_addr)) {
		return vmalloc_to_pfn(dvr_addr) << PAGE_SHIFT;
	} else {
		pr_err("remap: %p is not eligible parameter...\n", dvr_addr);
		return 0;
	}
}
EXPORT_SYMBOL(dvr_to_phys);

static void *dvr_malloc_specific_internal(size_t size, int flags, int id)
{
	void *ret = 0;
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("dvr malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (PageHighMem(page)) {
		ret = dvr_remap_cached_memory(phys_addr, size, __builtin_return_address(0));
		if (!ret) {
			free_contiguous_memory(page, count);
			ret = 0;
			goto out;
		}
	} else {
		ret = page_address(page);
	}

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	dmac_flush_range(ret, ret + size);
	outer_flush_range(phys_addr, phys_addr + size);

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | id | count_page, 0, __builtin_return_address(0))) {
		free_contiguous_memory(page, count);
		ret = 0;
		goto out;
	}
out:
	pr_info("%s(): returned %p\n", __func__, ret);
	return ret;
}

void *dvr_malloc_specific(size_t size, int flags)
{
	return dvr_malloc_specific_internal(size, flags, DRIVER_ID);
}
EXPORT_SYMBOL(dvr_malloc_specific);

void *dvr_malloc(size_t size)
{
	return dvr_malloc_specific(size, 0);
}
EXPORT_SYMBOL(dvr_malloc);

void *dvr_malloc_specific_addr(size_t size, int flags, unsigned long addr)
{
	void *ret = 0;
	struct mem_bp *bp;
	unsigned long pfn;
	struct page *page;
	unsigned long phys_addr = INVALID_VAL;
	int order, count;

	order = get_order(size);
	count = 1 << order;
	
	lock_cma();

	switch (flags) {
	case GFP_DCU1:
		bp = dma_get_allocator(NULL);
		break;
	case GFP_DCU2:
		bp = dma_get_allocator(auth_dev);
		break;
	default:
		unlock_cma();
		goto out;
	}

	pfn = alloc_rtkbp_memory_specific(bp, order, addr >> PAGE_SHIFT);
	if (pfn == INVALID_VAL) {
		unlock_cma();
		goto out;
	}

	for (;;) {
		int err;

		err = alloc_contig_range(pfn, pfn + count, MIGRATE_CMA);

		if (err == 0) {
			page = pfn_to_page(pfn);
			break;
		} else if (err != -EBUSY) {
			free_rtkbp_memory(bp, pfn, order);
			unlock_cma();
			goto out;
		}

		unlock_cma();
		pr_info("remap: retry remapping...\n");
		msleep(10);
		lock_cma();
	}

	unlock_cma();

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (PageHighMem(page)) {
		ret = dvr_remap_cached_memory(phys_addr, size, __builtin_return_address(0));
		if (!ret) {
			free_contiguous_memory(page, count);
			ret = 0;
			goto out;
		}
	} else {
		ret = page_address(page);
	}
	dmac_flush_range(ret, ret + size);
	outer_flush_range(phys_addr, phys_addr + size);

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_ID | count, 0, __builtin_return_address(0))) {
		free_contiguous_memory(page, count);
		ret = 0;
		goto out;
	}

#ifdef CONFIG_CMA_TRACK_USE_PAGE_OWNER
	if (page) {
		gfp_t gfp_mask;
		gfp_mask = __GFP_DMA_ALLOC_CONTIG;
		#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
		set_page_owner(page, count, gfp_mask);
		#else
		set_page_owner(page, order, gfp_mask);
		#endif
	}
#endif

out:
	pr_info("%s(): returned %p\n", __func__, ret);
	return ret;
}

void *dvr_malloc_nosave_specific(size_t size, int flags)
{
	return dvr_malloc_specific_internal(size, flags, NOSAVE_ID);
}
EXPORT_SYMBOL(dvr_malloc_nosave_specific);

void *dvr_malloc_nosave(size_t size)
{
	return dvr_malloc_nosave_specific(size, 0);
}
EXPORT_SYMBOL(dvr_malloc_nosave);

void *dvr_malloc_uncached_specific(size_t size, int flags, void **uaddr)
{
	void *ret = 0;
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("dvr malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (PageHighMem(page)) {
		ret = dvr_remap_cached_memory(phys_addr, size, __builtin_return_address(0));
		if (!ret) {
			free_contiguous_memory(page, count);
			ret = 0;
			goto out;
		}
	} else {
		ret = page_address(page);
	}

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	dmac_flush_range(ret, ret + size);
	outer_flush_range(phys_addr, phys_addr + size);

	if (uaddr) {
		*uaddr = dvr_remap_uncached_memory(phys_addr, size, __builtin_return_address(0));
		if (!*uaddr) {
			free_contiguous_memory(page, count);
			ret = 0;
			goto out;
		}

		if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_ID | count_page, (unsigned long)*uaddr, __builtin_return_address(0))) {
			free_contiguous_memory(page, count);
			return 0;
		}
	} else {
		if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_ID | count_page, 0, __builtin_return_address(0))) {
			free_contiguous_memory(page, count);
			return 0;
		}
	}
out:
	pr_info("%s(): returned %p\n", __func__, ret);
	return ret;
}
EXPORT_SYMBOL(dvr_malloc_uncached_specific);

void *dvr_malloc_uncached(size_t size, void **uaddr)
{
	return dvr_malloc_uncached_specific(size, 0, uaddr);
}
EXPORT_SYMBOL(dvr_malloc_uncached);

void *dvr_malloc_prot_specific(size_t size, int flags, pgprot_t prot)
{
	void *ret = 0;
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("dvr malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (PageHighMem(page)) {
		ret = remap_memory(phys_addr, size, prot, __builtin_return_address(0));
		if (!ret) {
			free_contiguous_memory(page, count);
			ret = 0;
			goto out;
		}
	} else {
		ret = page_address(page);
	}

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	dmac_flush_range(ret, ret + size);
	outer_flush_range(phys_addr, phys_addr + size);

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_ID | count_page, 0, __builtin_return_address(0))) {
		free_contiguous_memory(page, count);
		ret = 0;
		goto out;
	}
out:
	pr_info("%s(): returned %p\n", __func__, ret);
	return ret;
}
EXPORT_SYMBOL(dvr_malloc_prot_specific);

void *dvr_malloc_prot(size_t size, pgprot_t prot)
{
	return dvr_malloc_prot_specific(size, 0, prot);
}
EXPORT_SYMBOL(dvr_malloc_prot);

void dvr_free(const void *virt_addr)
{
	int value, count;
	unsigned long phys_addr, priv;
	rtk_record *ptr = NULL;

	if (is_vmalloc_addr(virt_addr)) {
		phys_addr = vmalloc_to_pfn(virt_addr) << PAGE_SHIFT;
	} else {
		phys_addr = (unsigned long)(page_to_pfn((virt_to_page(virt_addr))) << PAGE_SHIFT);
	}
	value = rtk_record_lookup_ex(phys_addr, &ptr, true);
	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: free memory (%lx/%p) signature error...\n", phys_addr, virt_addr);
		BUG();
	} else {
		priv = ptr->priv;

		if (need_debug_cma_deferfree()) {
			rtk_record_tag_set(ptr, RTK_RECORD_TAG_DEFER_FREE);
			/* defer free not alloc, mark it */
			//rtk_record_delete((unsigned long)phys_addr);
		} else {
			rtk_record_delete((unsigned long)phys_addr);
		}

		if (((value & ID_MASK) == DRIVER_ID) || ((value & ID_MASK) == NOSAVE_ID)) {
			if (need_debug_cma_guardband()) {
				count = dvr_guardband_check(phys_addr, value);
			} else {
				count = value & 0x00ffffff;
			}
			if (is_vmalloc_addr(virt_addr)) {
				dvr_unmap_memory((void *)virt_addr, count << PAGE_SHIFT);
			}
			if (priv) {
				dvr_unmap_memory((void *)priv, count << PAGE_SHIFT);
			}

			if (need_debug_cma_deferfree()) {
				/* defer free not alloc, mark it */
				//free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
				dvr_guardband_padding(pfn_to_page(phys_addr >> PAGE_SHIFT), 1, 0);
			} else {
				free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
			}
		} else {
			BUG();
		}
	}
}
EXPORT_SYMBOL(dvr_free);

struct page *dvr_malloc_page(size_t size, int flags)
{
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("dvr malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_ID | count_page, 0, __builtin_return_address(0))) {
		free_contiguous_memory(page, count);
		page = 0;
		goto out;
	}
out:
	pr_info("%s(): returned %p\n", __func__, page);
	return page;
}
EXPORT_SYMBOL(dvr_malloc_page);

void dvr_free_page(const struct page *page)
{
	int value, count;
	unsigned long phys_addr;
	rtk_record *ptr = NULL;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;
	value = rtk_record_lookup_ex(phys_addr, &ptr, true);
	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: free memory (%lx) signature error...\n", phys_addr);
		BUG();
	} else {
		if (need_debug_cma_deferfree()) {
			rtk_record_tag_set(ptr, RTK_RECORD_TAG_DEFER_FREE);
			/* defer free not alloc, mark it */
			//rtk_record_delete((unsigned long)phys_addr);
		} else {
			rtk_record_delete((unsigned long)phys_addr);
		}

		if ((value & ID_MASK) == DRIVER_ID) {
			if (need_debug_cma_guardband()) {
				count = dvr_guardband_check(phys_addr, value);
			} else {
				count = value & 0x00ffffff;
			}

			if (need_debug_cma_deferfree()) {
				/* defer free not alloc, mark it */
				//free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
				dvr_guardband_padding(pfn_to_page(phys_addr >> PAGE_SHIFT), 1, 0);
			} else {
				free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
			}
		} else {
			BUG();
		}
	}
}
EXPORT_SYMBOL(dvr_free_page);

struct page *dvr_malloc_page_mesg(size_t size, int flags, char *mesg)
{
	int count = 0;

	int size_page, size_order;
	int count_page, count_order;

	struct page *page;
	unsigned long phys_addr = INVALID_VAL;
	char *ptr = NULL;

	ptr = kmalloc(STR_LENGTH, GFP_KERNEL);
	if (unlikely(!ptr)){
		pr_err("%s:kmalloc fail!\n",__func__);
		return INVALID_VAL;
	}
	memset(ptr, 0, STR_LENGTH);
	strncpy(ptr, mesg, STR_LENGTH-1);

	size = size_page = PAGE_ALIGN(size);
	count = count_page = size >> PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		size = size_order = dvr_guardband_size(size);
		count = count_order = size_order >> PAGE_SHIFT;
	}

	pr_info("dvr malloc size: %zu count: %d\n", size, count);

	page = alloc_contiguous_memory(size, flags, __builtin_return_address(0));
	if (!page)
		goto out;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;

	if (need_debug_cma_guardband()) {
		dvr_guardband_padding(page, count_order, count_page);
	}

	if (rtk_record_insert(phys_addr, RTK_SIGNATURE | DRIVER_MESG_ID | count_page, 0, ptr)) {
		free_contiguous_memory(page, count);
		page = 0;
		goto out;
	}
out:
	pr_info("%s(): returned %p\n", __func__, page);
	return page;
}
EXPORT_SYMBOL(dvr_malloc_page_mesg);

void dvr_free_page_mesg(const struct page *page)
{
	int value, count;
	unsigned long phys_addr;
	rtk_record *ptr = NULL;
	char *caller = NULL;

	phys_addr = page_to_pfn(page) << PAGE_SHIFT;
	value = rtk_record_lookup_ex(phys_addr, &ptr, true);
	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: free memory (%lx) signature error...\n", phys_addr);
		BUG();
	} else {
		caller = (char *)ptr->caller;
		if (need_debug_cma_deferfree()) {
			rtk_record_tag_set(ptr, RTK_RECORD_TAG_DEFER_FREE);
			/* defer free not alloc, mark it */
			//rtk_record_delete((unsigned long)phys_addr);
		} else {
			rtk_record_delete((unsigned long)phys_addr);
		}

		if ((value & ID_MASK) == DRIVER_MESG_ID) {
			if (need_debug_cma_guardband()) {
				count = dvr_guardband_check(phys_addr, value);
			} else {
				count = value & 0x00ffffff;
			}

			if (need_debug_cma_deferfree()) {
				/* defer free not alloc, mark it */
				//free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
				dvr_guardband_padding(pfn_to_page(phys_addr >> PAGE_SHIFT), 1, 0);
			} else {
				free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);
			}
			if(caller)
				kfree((void *)caller);
		} else {
			BUG();
		}
	}
}
EXPORT_SYMBOL(dvr_free_page_mesg);

static int __init early_debug_cma_deferfree(char *buf)
{
	if (!buf)
		return -EINVAL;

	if (strcmp(buf, "on") == 0)
		_debug_cma_deferfree_enabled = true;

	return 0;
}
early_param("debug_cma_deferfree", early_debug_cma_deferfree);

static int __init early_debug_cma_guardband(char *buf)
{
	if (!buf)
		return -EINVAL;

	if (strcmp(buf, "on") == 0) {
		_debug_cma_guardband_enabled = true;
		printk(KERN_DEBUG "[cma guardband] cma guardband is enabled !\n");
	}

	return 0;
}
early_param("debug_cma_guardband", early_debug_cma_guardband);

bool need_debug_cma_deferfree(void)
{
	if (!_debug_cma_deferfree_enabled)
		return false;

	return true;
}

bool need_debug_cma_guardband(void)
{
	if (!_debug_cma_guardband_enabled)
		return false;

	return true;
}

/* --- cma defer free --- */
void dvr_defer_free(rtk_record *ptr)
{
	int count;
	unsigned long value, phys_addr;

	if (!unlikely(ptr))
		return;

	value = ptr->type;
	phys_addr = ptr->addr;

	if ((value & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: defer free memory (%lx) signature error...\n", phys_addr);
		BUG();
	} else {
		/* move to rtkrecord.c, due to spinlock */
		//rtk_record_tag_clear(phys_addr, RTK_RECORD_TAG_DEFER_FREE);
		ptr->reserved = ptr->reserved & 0xfffffff0; // defer free clear

		if (((value & ID_MASK) == BUDDY_ID) || ((value & ID_MASK) == BUDDY_MESG_ID) ||
			((value & ID_MASK) == DRIVER_ID) || ((value & ID_MASK) == DRIVER_MESG_ID) || ((value & ID_MASK) == NOSAVE_ID)) {
			count = value & 0x00ffffff;

			if (dvr_guardband_check(phys_addr, value) == 0xffff0000) {
				if (((value & ID_MASK) == BUDDY_MESG_ID))
					pr_err("[cma defer_free] id: %lx defer, addr: %lx size: %8lx (%6ld/%6ld) %s\n", (value & ID_MASK),
							phys_addr, (value & 0x00ffffff) << PAGE_SHIFT, ptr->pid, ptr->tgid, (const char *)ptr->caller);
				else
					pr_err("[cma defer_free] id: %lx defer, addr: %lx size: %8lx (%6ld/%6ld) %pF\n", (value & ID_MASK),
							phys_addr, (value & 0x00ffffff) << PAGE_SHIFT, ptr->pid, ptr->tgid, (const void *)ptr->caller);
				dump_stack();
			}

			free_contiguous_memory(pfn_to_page(phys_addr >> PAGE_SHIFT), count);

			if (((value & ID_MASK) == BUDDY_MESG_ID) && ptr->caller) {
				pr_debug("[cma defer_free] pli_mesg_free defer, addr: %lx size: %8lx (%6ld/%6ld) %s\n",
						phys_addr, (value & 0x00ffffff) << PAGE_SHIFT, ptr->pid, ptr->tgid, (const char *)ptr->caller);
				kfree((void *)ptr->caller);
			}
		} else {
			BUG();
		}
	}
}
/* --- cma defer free --- */

/* --- cma guardband --- */
int my_memcmp(const void *cs, const char val, size_t count)
{
	const unsigned char *su1;
	int res = 0;

	for (su1 = cs; 0 < count; ++su1, count--)
		if ((res = *su1 - val) != 0)
			break;
	return res;
}

/*
 * in : size is page aligned
 * out: size is order aligned
 */
int dvr_guardband_size(size_t size_page)
{
	int size_order;
	int count_page, count_order;

	count_page = size_page >> PAGE_SHIFT;

	count_order = 1 << get_order(size_page);
	size_order = count_order << PAGE_SHIFT; // order align

	if ((count_order - count_page) == 0 && size_page < GUARDBAND_SIZE)   // page is order alignment
	{
		count_page += 1; // extra 1 page

		// re-calculate
		count_order = 1 << get_order(count_page << PAGE_SHIFT);
		size_order = count_order << PAGE_SHIFT;
	}

	printk(KERN_DEBUG "[cma guardband] size alignment calc page(%x)/order(%x)\n", size_page, size_order);

	return size_order;
}

int dvr_guardband_padding(struct page* page, int count_order, int count_page)
{
	if (count_order == 0)
		return INVALID_VAL;

	if (page)
	{
		int i = 0;
		unsigned long start_pfn = page_to_pfn(page);

		for (; i < count_order - count_page; i++)
		{
			struct page *page = pfn_to_page(start_pfn + count_page + i);
			char *vaddr = kmap_atomic(page);

			memset(vaddr, 0x0f, PAGE_SIZE);
			printk(KERN_DEBUG "%08x: %08x %08x %08x %08x\n", (int)(start_pfn << PAGE_SHIFT),
					 *(int *)(((int *)(vaddr)) + 0),
					 *(int *)(((int *)(vaddr)) + 1),
					 *(int *)(((int *)(vaddr)) + 2),
					 *(int *)(((int *)(vaddr)) + 3) );
			kunmap_atomic(vaddr);
		}
	}

	return 0;
}

int dvr_guardband_check(unsigned long phys_addr, int value)
{
	int count_page, count_order, count_check;

	int i = 0, my_ret = 0, my_cnt = 0;
	unsigned long start_pfn = phys_addr >> PAGE_SHIFT;

	if (need_debug_cma_deferfree()) {
		count_page = 0;
		count_order = 1;
	} else {
		count_page = value & 0x00ffffff;
		count_order = 1 << get_order(count_page << PAGE_SHIFT);
		if ( ((count_order - count_page) == 0) && ((count_page << PAGE_SHIFT) < GUARDBAND_SIZE) ) // page is order alignment
			count_order = 1 << get_order((count_page + 1) << PAGE_SHIFT); // re-calculate
	}

	count_check = count_order - count_page;
	printk(KERN_DEBUG "[cma guardband] addr(%lx), size alignment check page(%x)/order(%x)\n", phys_addr, (count_page << PAGE_SHIFT), (count_order << PAGE_SHIFT));

	for (i = 0; i < count_check; i++)
	{
		int res = 0;
		struct page *page = pfn_to_page(start_pfn + count_page + i);
		char *vaddr = kmap_atomic(page);
		res = my_memcmp((char *)vaddr, 0x0f, PAGE_SIZE);
		if (res && (my_cnt++ < 5))
		{
			int j = 0;
			for (j = 0; j < 8; j += 4) // first 2 items
				pr_err("%08x: %08x %08x %08x %08x\n", (int)((start_pfn + count_page + i) << PAGE_SHIFT),
					   *(int *)(((int *)(vaddr)) + j + 0),
					   *(int *)(((int *)(vaddr)) + j + 1),
					   *(int *)(((int *)(vaddr)) + j + 2),
					   *(int *)(((int *)(vaddr)) + j + 3));

			pr_err("-------- -------- -------- --------\n");
		}
		kunmap_atomic(vaddr);
		my_ret |= res;
	}

#if 0
	// dump last 32bytes within last page of normal request.
	if (my_ret && count_check >= 1)
	{
		struct page *page = pfn_to_page(start_pfn + count_page - 1);
		char *vaddr = kmap_atomic(page);
		{
			int j = 0;
			pr_err("-------- last 32 bytes dump -------\n");
			for (j = ((PAGE_SIZE/4) - 8); j < (PAGE_SIZE/4); j+=4) // last 2 items
				pr_err("%08x: %08x %08x %08x %08x\n", (int)((start_pfn + count_page - 1) << PAGE_SHIFT),
					   *(int *)(((int *)(vaddr)) + j + 0),
					   *(int *)(((int *)(vaddr)) + j + 1),
					   *(int *)(((int *)(vaddr)) + j + 2),
					   *(int *)(((int *)(vaddr)) + j + 3));

			pr_err("-------- -------- -------- --------\n");
		}
		kunmap_atomic(vaddr);
	}
#endif

	if (my_ret)
	{
		pr_err("[cma guardband] defer(%d)/guard(%d) memory trash (addr: %lx, size: page(%x)/order(%x))\n", 
			   (int)need_debug_cma_deferfree(), (int)need_debug_cma_guardband(), phys_addr, (count_page << PAGE_SHIFT), (count_order << PAGE_SHIFT));

		if (need_debug_cma_deferfree())
			count_order = 0xffff0000; // magic number for defer_free
		else 
			dump_stack();
	}

	return count_order;
}
/* --- cma guardband --- */

/*
 * Restrictions:
 * (1) Must be called with an elevated refcount on the page.
 * (2) The lru_locked mus be held.
 */
static int isolate_lru_page_locked(struct page *page)
{
	int ret = -EBUSY;

	BUG_ON(!PageLRU(page));

	// check if this page is in pagevec_release()...
	if (likely(get_page_unless_zero(page))) {
		ClearPageLRU(page);
		ret = 0;
	}

	return ret;
}

static struct page *remap_alloc_page(struct page *p, unsigned long private, int **result)
{
	int in_suspend = (private & REMAP_IN_SUSPEND) ? 1 : 0;

	private &= 0xff;
	if (private == REMAP_ZONE) {
		return alloc_page(GFP_HIGHUSER_MOVABLE);
	} else if (private == REMAP_PAGE) {
		return alloc_page(GFP_KERNEL);
#ifdef CONFIG_CMA_FIRST_POLICY
	} else if (private == REMAP_CMA1) {
#ifdef CONFIG_QUICK_HIBERNATION
		if (!in_suspend) {
#endif
			return alloc_page(GFP_HIGHUSER_MOVABLE);
#ifdef CONFIG_QUICK_HIBERNATION
		} else {
			struct page *page = NULL;

			if (page_is_file_cache(p)) {
				return alloc_page(GFP_HIGHUSER_MOVABLE);
			}

			/* anonymous page */
			if (!curr_record) {
				return alloc_page(GFP_HIGHUSER_MOVABLE);
			}

			page = &pagelist[page_cnt++];
			get_page(page);
			if (page_cnt == page_max) {
				curr_record = list_entry(curr_record->list.next, record_struct, list);
				if (&curr_record->list == &dcu1_record_list) {
					pr_info("swsusp: run out of CMA1 preallocated pages....\n");
					curr_record = pagelist = NULL;
					return page;
				}
				pagelist = curr_record->page;
				page_max = MEM_CHUNK_SIZE / PAGE_SIZE;
				page_cnt = 0;
			}

			return page;
		}
#endif
	} else if (private == REMAP_CMA2) {
#ifdef CONFIG_QUICK_HIBERNATION
		if (!in_suspend) {
#endif
			return alloc_page(GFP_HIGHUSER_MOVABLE);
#ifdef CONFIG_QUICK_HIBERNATION
		} else {
			struct page *page = NULL;

			if (page_is_file_cache(p)) {
				return alloc_page(GFP_HIGHUSER_MOVABLE);
			}

			/* anonymous page */
			if (!curr_record) {
				return alloc_page(GFP_HIGHUSER_MOVABLE);
			}

			page = &pagelist[page_cnt++];
			get_page(page);
			if (page_cnt == page_max) {
				curr_record = list_entry(curr_record->list.next, record_struct, list);
				if (&curr_record->list == &dcu2_record_list) {
					pr_info("swsusp: run out of CMA2 preallocated pages....\n");
					curr_record = pagelist = NULL;
					return page;
				}
				pagelist = curr_record->page;
				page_max = MEM_CHUNK_SIZE / PAGE_SIZE;
				page_cnt = 0;
			}

			return page;
		}
#endif
#endif
	} else {
		BUG();
	}
}

static int remap_zone_pages(struct zone *zone, page_filter_t filter, int type)
{
	struct list_head *list;
	LIST_HEAD(page_list);
	int lru_done = 0, lru_fail = 0;
	int map_done = 0, map_fail = 0;
	int lru, ret;

	migrate_prep();		/* flush pagevecs */

	spin_lock_irq(&zone->lru_lock);
	for_each_lru(lru) {
		struct page *page, *page2;
		list = &(zone->lruvec.lists[lru - LRU_BASE]);
		list_for_each_entry_safe(page, page2, list, lru) {
			if (filter && !filter(page))
				continue;

			if (isolate_lru_page_locked(page) == -EBUSY) {
				lru_fail++;
			} else {
				lru_done++;
				del_page_from_lru_list(page, mem_cgroup_page_lruvec(page, zone), lru);
				list_add_tail(&page->lru, &page_list);
				__mod_zone_page_state(zone, NR_ISOLATED_ANON + page_is_file_cache(page), 
					hpage_nr_pages(page));
			}
		}
		pr_info("lru: %d\t\t done: %d\t fail: %d\n", lru, lru_done, lru_fail);
		map_done += lru_done;
		map_fail += lru_fail;
		lru_done = lru_fail = 0;
	}
	spin_unlock_irq(&zone->lru_lock);
	pr_info("total isolated:\t done: %d\t fail: %d\n", map_done, map_fail);

	ret = migrate_pages(&page_list, remap_alloc_page, NULL, type, MIGRATE_SYNC, MR_CMA);
	map_done -= ret;
	map_fail += ret;
	pr_info("total migrated:\t done: %d\t fail: %d\n", map_done, ret);
	putback_movable_pages(&page_list);

	// flush again to ensure all delayed works in putback_lru_page() are done...
	migrate_prep();		/* flush pagevecs */
	drain_all_pages(NULL);	/* flush per_cpu_pages */

	if (map_fail)
		return 1;
	else
		return 0;
}

int remap_one_page(struct page *page)
{
	struct zone *zone = (struct zone *)page_zone(page);
	LIST_HEAD(page_list);
	int lru, ret;

	migrate_prep();		/* flush pagevecs */

	spin_lock_irq(&zone->lru_lock);
	if (!PageLRU(page)) {
		spin_unlock_irq(&zone->lru_lock);
		pr_info("remap: page %p (%p) might be isolated or reclaimed...\n", page, page->mapping);
		msleep(10);
		return 1;
	}
	lru = page_lru(page);
	if (isolate_lru_page_locked(page) == -EBUSY) {
		spin_unlock_irq(&zone->lru_lock);
		pr_info("remap: fail to isolate pfn %lx...\n", page_to_pfn(page));
		return 1;
	} else {
		del_page_from_lru_list(page, mem_cgroup_page_lruvec(page, zone), lru);
		list_add_tail(&page->lru, &page_list);
		__mod_zone_page_state(zone, NR_ISOLATED_ANON + page_is_file_cache(page), 
			hpage_nr_pages(page));
	}
	spin_unlock_irq(&zone->lru_lock);

	ret = migrate_pages(&page_list, remap_alloc_page, NULL, REMAP_PAGE, MIGRATE_SYNC, MR_CMA);
	pr_info("remap: remap pfn %lx return %d\n", page_to_pfn(page), ret);
	putback_movable_pages(&page_list);

	if (ret)
		return 1;
	else
		return 0;
}

int reserve_highmem(void)
{
#ifdef CONFIG_HIGHMEM
	struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_HIGHMEM];

	if (zone && populated_zone(zone)) {
//		zone_set_flag(zone, ZONE_ALLOC_LOCKED);
		set_bit(ZONE_ALLOC_LOCKED, &zone->flags);
		pr_info("remap HIGHMEM zone...\n");
		remap_zone_pages(zone, NULL, REMAP_ZONE);
	}
#endif

	return 0;
}
EXPORT_SYMBOL(reserve_highmem);

int release_highmem(void)
{
#ifdef CONFIG_HIGHMEM
	struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_HIGHMEM];

	if (zone && populated_zone(zone)) {
//		zone_clear_flag(zone, ZONE_ALLOC_LOCKED);
		clear_bit(ZONE_ALLOC_LOCKED, &zone->flags);
	}
#endif

	return 0;
}
EXPORT_SYMBOL(release_highmem);

int reserve_movable(void)
{
	struct zone *zone;

	if (down_interruptible(&remap_sem)) {
		// we use return value 1 to represent an signal is caught...
		pr_info("remap: %s interrupted by an signal...\n", __func__);
		return -EINTR;
	}

	zone = &NODE_DATA(0)->node_zones[ZONE_MOVABLE];
//	zone_set_flag(zone, ZONE_ALLOC_LOCKED);
	set_bit(ZONE_ALLOC_LOCKED, &zone->flags);
	pr_info("remap MOVABLE zone...\n");
	remap_zone_pages(zone, NULL, REMAP_ZONE);

	return 0;
}
EXPORT_SYMBOL(reserve_movable);

int release_movable(void)
{
	struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_MOVABLE];

//	zone_clear_flag(zone, ZONE_ALLOC_LOCKED);
	clear_bit(ZONE_ALLOC_LOCKED, &zone->flags);
	up(&remap_sem);

	return 0;
}
EXPORT_SYMBOL(release_movable);

#ifdef CONFIG_CMA_FIRST_POLICY
static bool cma_page_filter(struct page *page)
{
	if (check_cma_memory(page_to_pfn(page)))
		return true;
	else
		return false;
}

int reserve_cma(int in_suspend)
{
	struct zone *zone;

	if (down_interruptible(&remap_sem)) {
		// we use return value 1 to represent an signal is caught...
		pr_info("remap: %s interrupted by an signal...\n", __func__);
		return -EINTR;
	}

	lock_cma();

	cma_reserved = 1;
#ifdef CONFIG_QUICK_HIBERNATION
	if (in_suspend) {
		if (dcu1_size) {
			pr_info("remap DCU1 CMA...\n");
			if (!list_empty(&dcu1_record_list)) {
				curr_record = list_entry(dcu1_record_list.next, record_struct, list);
				pagelist = curr_record->page;
				page_max = MEM_CHUNK_SIZE / PAGE_SIZE;
				page_cnt = 0;
			} else {
				curr_record = pagelist = 0;
				page_cnt = page_max = 0;
			}
			zone = &NODE_DATA(0)->node_zones[ZONE_NORMAL];
			remap_zone_pages(zone, cma_page_filter, REMAP_IN_SUSPEND | REMAP_CMA1);
			if (pagelist) {
				char *vaddr;
				while (page_cnt < page_max) {
					vaddr = kmap_atomic(&pagelist[page_cnt++]);
					memset(vaddr, 0, PAGE_SIZE);
					kunmap_atomic(vaddr);
				}
			}
		}
		if (dcu2_size) {
			pr_info("remap DCU2 CMA...\n");
			if (!list_empty(&dcu2_record_list)) {
				curr_record = list_entry(dcu2_record_list.next, record_struct, list);
				pagelist = curr_record->page;
				page_max = MEM_CHUNK_SIZE / PAGE_SIZE;
				page_cnt = 0;
			} else {
				curr_record = pagelist = 0;
				page_cnt = page_max = 0;
			}
			zone = &NODE_DATA(0)->node_zones[ZONE_MOVABLE];
			remap_zone_pages(zone, cma_page_filter, REMAP_IN_SUSPEND | REMAP_CMA2);
			if (pagelist) {
				char *vaddr;
				while (page_cnt < page_max) {
					vaddr = kmap_atomic(&pagelist[page_cnt++]);
					memset(vaddr, 0, PAGE_SIZE);
					kunmap_atomic(vaddr);
				}
			}
		}
	} else {
#endif
		if (dcu1_size) {
			pr_info("remap DCU1 CMA...\n");
			zone = &NODE_DATA(0)->node_zones[ZONE_NORMAL];
			remap_zone_pages(zone, cma_page_filter, REMAP_CMA1);
		}
		if (dcu2_size) {
			pr_info("remap DCU2 CMA...\n");
			zone = &NODE_DATA(0)->node_zones[ZONE_MOVABLE];
			remap_zone_pages(zone, cma_page_filter, REMAP_CMA2);
		}
#ifdef CONFIG_QUICK_HIBERNATION
	}
#endif

	unlock_cma();

	return 0;
}
EXPORT_SYMBOL(reserve_cma);

int release_cma(int in_suspend)
{
	cma_reserved = 0;
	up(&remap_sem);

	return 0;
}
EXPORT_SYMBOL(release_cma);
#endif

int remap_list_mem(rtk_record *records)
{
	int ret;
	unsigned long addr = records->addr;
	unsigned long  type = records->type;
	const void *caller = records->caller;
	unsigned long  pid = records->pid; // process id
	unsigned long  tid = records->tgid; // thread id
	// timestamps
	unsigned long jiff = records->jiffies;
	unsigned long msec = jiffies_to_msecs(jiff);
	unsigned int defer = records->reserved & 0x0000000f;

	if ((type & 0xf0000000) != RTK_SIGNATURE) {
		pr_err("remap: list memory (%lx) signature error...\n", addr);
		return 0;
	}

	if ((type & ID_MASK) == DRIVER_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by driver) %pF (%ld.%03ld sec)\n", defer, addr, (type & 0x00ffffff) << PAGE_SHIFT, pid, tid, caller, msec / 1000, msec % 1000);
		ret = (type & 0x00ffffff) << PAGE_SHIFT;
	} else if ((type & ID_MASK) == NOSAVE_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by nosave) %pF (%ld.%03ld sec)\n", defer, addr, (type & 0x00ffffff) << PAGE_SHIFT, pid, tid, caller, msec / 1000, msec % 1000);
		ret = (type & 0x00ffffff) << PAGE_SHIFT;
	} else if ((type & ID_MASK) == CACHE_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by pli cache) %pF (%ld.%03ld sec)\n", defer, addr, type & 0x00ffffff, pid, tid, caller, msec / 1000, msec % 1000);
		ret = type & 0x00ffffff;
	} else if ((type & ID_MASK) == BUDDY_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by pli buddy) %pF (%ld.%03ld sec)\n", defer, addr, (type & 0x00ffffff) << PAGE_SHIFT, pid, tid, caller, msec / 1000, msec % 1000);
		ret = (type & 0x00ffffff) << PAGE_SHIFT;
	} else if ((type & ID_MASK) == BUDDY_MESG_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by pli buddy for user layer) %s (%ld.%03ld sec)\n", defer, addr, (type & 0x00ffffff) << PAGE_SHIFT, pid, tid, (const char *)caller, msec / 1000, msec % 1000);
		ret = (type & 0x00ffffff) << PAGE_SHIFT;
	} else if ((type & ID_MASK) == DRIVER_MESG_ID) {
		pr_info(" allocation address(%d): %lx  size: %8lx (%6ld/%6ld)(by driver) %s (%ld.%03ld sec)\n", defer, addr, (type & 0x00ffffff) << PAGE_SHIFT, pid, tid, (const char *)caller, msec / 1000, msec % 1000);
		ret = (type & 0x00ffffff) << PAGE_SHIFT;
	}
	else {
		pr_err("Unknown memory ID...\n");
		return 0;
	}

	return ret;
}

int remap_free_mem(rtk_record *records)
{
	unsigned long addr = records->addr;
	unsigned long type = records->type;

	if ((type & 0xf0000000) != RTK_SIGNATURE) {
		pr_info("remap: free memory (%lx) signature error...\n", addr);
		return 1;
	}

	if ((type & ID_MASK) == DRIVER_ID) {
		pr_info("\t0x%lx owned by module...\n", addr);
		return 1;
	} else if ((type & ID_MASK) == NOSAVE_ID) {
		pr_info("\t0x%lx owned by nosave...\n", addr);
		return 1;
	} else if ((type & ID_MASK) == CACHE_ID) {
		kfree((void *)addr);
	} else if ((type & ID_MASK) == BUDDY_ID) {
		int count = type & 0x00ffffff;
		free_contiguous_memory(pfn_to_page(addr >> PAGE_SHIFT), count);
	} else {
		pr_info("Unknown memory ID...\n");
		return 1;
	}

	return 0;
}

unsigned long get_page_cache_addr(void)
{
	int pageno = 0;
	char *vaddr;

	if (!rtk_page_cache) {
		return INVALID_VAL;
	}

	/* clear unused page cache */
	while (1) {
		pageno = bitmap_find_next_zero_area(rtk_cache_bitmap, DEF_CACHE_SIZE / PAGE_SIZE, pageno, 1, 0);
		if (pageno >= DEF_CACHE_SIZE / PAGE_SIZE)
			break;
//		pr_info("remap: clear pageno: %d \n", pageno);
		vaddr = kmap_atomic(rtk_page_cache + pageno);
		memset(vaddr, 0, PAGE_SIZE);
		kunmap_atomic(vaddr);
		pageno++;
	}

	return page_to_pfn(rtk_page_cache) << PAGE_SHIFT;
}

static bool unmovable_page_filter(struct page *page)
{
	if (check_cma_memory(page_to_pfn(page)))
		return false;
	else
		return true;
}

int calc_unmovable(void)
{
	struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_NORMAL];
	struct list_head *list;
	LIST_HEAD(page_list);
	int lru, ret;

	migrate_prep();		/* flush pagevecs */

	spin_lock_irq(&zone->lru_lock);
	for_each_lru(lru) {
		struct page *page, *page2;
		ret = 0;
		list = &(zone->lruvec.lists[lru - LRU_BASE]);
		list_for_each_entry_safe(page, page2, list, lru) {
			if (!unmovable_page_filter(page))
				continue;
			ret++;
		}
		pr_alert(" ### lru: %d count: %d \n", lru, ret);
	}
	spin_unlock_irq(&zone->lru_lock);

	return 0;
}

static unsigned long remap_shrink_count(struct shrinker *s, struct shrink_control *sc)
{
	return 1;
}

/*
 * We will check if system need to do remapping by ourself, so this function always return -1 
 * to notify linux that linux reclaim mechanism does not need to check for us.
 */
static unsigned long remap_shrink(struct shrinker *s, struct shrink_control *sc)
{
	struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_NORMAL];
	struct list_head *list;
	LIST_HEAD(page_list);
	int lru_done = 0, lru_fail = 0;
	int map_done = 0, map_fail = 0;
	int lru, ret;

//	BUG_ON(sc->nr_to_scan);

	/* we only allow kswpad to do shrink to avoid deadlock */
	if (!(current->flags & PF_KSWAPD))
		goto out;

#ifdef CONFIG_HIGHMEM
	if ((global_page_state(NR_FREE_PAGES) - global_page_state(NR_FREE_CMA_PAGES)
		- zone_page_state(&NODE_DATA(0)->node_zones[ZONE_HIGHMEM], NR_FREE_PAGES)) >= 2048)
#else
	if ((global_page_state(NR_FREE_PAGES) - global_page_state(NR_FREE_CMA_PAGES)
		- zone_page_state(&NODE_DATA(0)->node_zones[ZONE_NORMAL], NR_FREE_PAGES)) >= 2048)
#endif
		goto out;

	if (global_page_state(NR_FREE_CMA_PAGES) <= totalreserve_pages)
		goto out;

	pr_info("remap: start to clean unmovable region...\n");
	spin_lock_irq(&zone->lru_lock);
	for_each_lru(lru) {
		struct page *page, *page2;

//		if (is_file_lru(lru))
//			continue;

		list = &(zone->lruvec.lists[lru - LRU_BASE]);
		list_for_each_entry_safe(page, page2, list, lru) {
			if (!unmovable_page_filter(page))
				continue;

			if (isolate_lru_page_locked(page) == -EBUSY) {
				lru_fail++;
			} else {
				/* now we are safe to access this page */
#ifdef CONFIG_EXT4_FS
				if (page_is_file_cache(page)) {
					int is_ext4_buddy_cache = 0;

					/* check if this inode is EXT4_BAD_INO */
					if (trylock_page(page)) {
						if (page->mapping && page->mapping->host->i_ino == 1)
							is_ext4_buddy_cache = 1;
						unlock_page(page);
					} else {
						SetPageLRU(page);
						put_page(page);
						lru_fail++;
						continue;
					}

					if (is_ext4_buddy_cache) {
						SetPageLRU(page);
						put_page(page);
						lru_fail++;
						continue;
					}
				}
#endif

				lru_done++;
				del_page_from_lru_list(page, mem_cgroup_page_lruvec(page, zone), lru);
				list_add_tail(&page->lru, &page_list);
				__mod_zone_page_state(zone, NR_ISOLATED_ANON + page_is_file_cache(page), 
					hpage_nr_pages(page));
			}

			if ((map_done + lru_done) >= SWAP_CLUSTER_MAX)
				break;
		}
		pr_info("lru: %d\t\t done: %d\t fail: %d\n", lru, lru_done, lru_fail);
		map_done += lru_done;
		map_fail += lru_fail;
		lru_done = lru_fail = 0;

		if (map_done >= SWAP_CLUSTER_MAX)
			break;
	}
	spin_unlock_irq(&zone->lru_lock);
	pr_info("total isolated:\t done: %d\t fail: %d\n", map_done, map_fail);

	ret = migrate_pages(&page_list, remap_alloc_page, NULL, REMAP_ZONE, MIGRATE_SYNC, MR_CMA);
	map_done -= ret;
	map_fail += ret;
	pr_info("total migrated:\t done: %d\t fail: %d\n", map_done, ret);
	putback_movable_pages(&page_list);

out:
	return -1;
}

struct shrinker remap_shrinker = {
	.count_objects = remap_shrink_count,
	.scan_objects = remap_shrink,
	.seeks = DEFAULT_SEEKS * 4,
};

static int __init remap_init(void)
{
	register_shrinker(&remap_shrinker);

	pr_info("remap initialized\n");

	return 0;
}

static void __exit remap_exit(void)
{
	unregister_shrinker(&remap_shrinker);

	pr_info("remap unloaded\n");
}

module_init(remap_init);
module_exit(remap_exit);


