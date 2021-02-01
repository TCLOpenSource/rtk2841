#ifndef __LINUX_PAGE_OWNER_H
#define __LINUX_PAGE_OWNER_H

#ifdef CONFIG_PAGE_OWNER
extern bool page_owner_inited;
extern struct page_ext_operations page_owner_ops;

extern void __reset_page_owner(struct page *page, unsigned int order);
extern void __set_page_owner(struct page *page,
			#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
			unsigned int count,
			#else
			unsigned int order,
			#endif
			gfp_t gfp_mask);
extern gfp_t __get_page_owner_gfp(struct page *page);
extern int __get_page_owner_single_page_info(unsigned long pfn);
extern void __dump_page_owner(struct page *page);

static inline void reset_page_owner(struct page *page, unsigned int order)
{
	if (likely(!page_owner_inited))
		return;

	__reset_page_owner(page, order);
}

static inline void set_page_owner(struct page *page,
			#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
			unsigned int count,
			#else
			unsigned int order,
			#endif
			gfp_t gfp_mask)
{
	if (likely(!page_owner_inited))
		return;

	#ifdef CONFIG_PAGE_OWNER_RECORD_COUNT
	__set_page_owner(page, count, gfp_mask);
	#else
	__set_page_owner(page, order, gfp_mask);
	#endif
}

static inline gfp_t get_page_owner_gfp(struct page *page)
{
	if (likely(!page_owner_inited))
		return 0;

	return __get_page_owner_gfp(page);
}

static inline int get_page_owner_single_page_info(unsigned long pfn)
{
	if (likely(!page_owner_inited))
		return 0;

	return __get_page_owner_single_page_info(pfn);
}

static inline void dump_page_owner(struct page *page)
{
        if (likely(!page_owner_inited))
                return 0;

		__dump_page_owner(page);
}
#else
static inline void reset_page_owner(struct page *page, unsigned int order)
{
}
static inline void set_page_owner(struct page *page,
			unsigned int order, gfp_t gfp_mask)
{
}
static inline gfp_t get_page_owner_gfp(struct page *page)
{
	return 0;
}
static inline int get_page_owner_single_page_info(unsigned long pfn)
{
	return 0;
}

static inline void dump_page_owner(struct page *page)
{
}
#endif /* CONFIG_PAGE_OWNER */
#endif /* __LINUX_PAGE_OWNER_H */
