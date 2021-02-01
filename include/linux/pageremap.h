#ifndef _LINUX_PAGEREMAP_H
#define _LINUX_PAGEREMAP_H

#include <linux/rtkrecord.h>

#define GFP_DCU1	0x00000001
#define GFP_DCU2	0x00000002
#define GFP_DCU1_FIRST	0x00000004
#define GFP_DCU2_FIRST	0x00000008

#define MEM_CHUNK_SIZE	8*1024*1024

#define MAX_CACHE_COUNT 4
#define DEF_CACHE_SIZE	4*1024*1024
#define DEF_CACHE_SIZE_LOW	4*1024*1024

#ifdef CONFIG_CMA_RANK_RBTREE
#define PAGE_LOOKUP_ONLY	0x00000001
#endif

#define GUARDBAND_SIZE 4*1024*1024 // for page order alignment case

typedef struct {
	struct list_head	list;
	struct page		*page;
} record_struct;

#ifdef CONFIG_CMA_RTK_ALLOCATOR

void add_memory_size(int flags, int size);
int get_memory_size(int flags);

bool check_cma_memory(unsigned long pfn);
unsigned long get_cma_avail_size(void);

// The following functions are used by user to allocate continuous memory...
unsigned long pli_malloc(size_t size, int flags);
void pli_free(const unsigned long arg);
unsigned long pli_malloc_mesg(size_t size, int flags, char *mesg);
void pli_free_mesg(const unsigned long arg);

// This function is used to convert the virtual address return by dvr_XXX() to physical address...
unsigned long dvr_to_phys(const void *dvr_addr);

void *dvr_remap_cached_memory(unsigned long phys_addr, size_t size, const void *caller);
void *dvr_remap_uncached_memory(unsigned long phys_addr, size_t size, const void *caller);
void dvr_unmap_memory(void *cpu_addr, size_t size);

// The following functions are used by driver to allocate continuous memory...
void *dvr_malloc(size_t size);
void *dvr_malloc_specific(size_t size, int flags);
void *dvr_malloc_specific_addr(size_t size, int flags, unsigned long addr);
void *dvr_malloc_nosave(size_t size);
void *dvr_malloc_nosave_specific(size_t size, int flags);
void *dvr_malloc_uncached(size_t size, void **uaddr);
void *dvr_malloc_uncached_specific(size_t size, int flags, void **uaddr);
void *dvr_malloc_prot(size_t size, pgprot_t prot);
void *dvr_malloc_prot_specific(size_t size, int flags, pgprot_t prot);
void dvr_free(const void *arg);

struct page *dvr_malloc_page(size_t size, int flags);
void dvr_free_page(const struct page *page);
struct page *dvr_malloc_page_mesg(size_t size, int flags, char *mesg);
void dvr_free_page_mesg(const struct page *page);
void dvr_defer_free(rtk_record *ptr);
#ifdef CONFIG_CMA_RANK_RBTREE
int dvr_free_page_count(struct page *page, size_t size, int flag);
#endif

bool need_debug_cma_deferfree(void);
bool need_debug_cma_guardband(void);
int dvr_guardband_size(size_t size_page);
int dvr_guardband_padding(struct page* page, int count_order, int count_page);
int dvr_guardband_check(unsigned long phys_addr, int value);

// The following functions are used to reserve the movable zone for special purpose...
int reserve_highmem(void);
int release_highmem(void);
int reserve_movable(void);
int release_movable(void);

#ifdef CONFIG_CMA_FIRST_POLICY
int reserve_cma(int in_suspend);
int release_cma(int in_suspend);
#endif

int remap_list_mem(rtk_record *records);
int remap_free_mem(rtk_record *records);

// This function is used by kernel to remap one page only...
int remap_one_page(struct page *page);

unsigned long get_page_cache_addr(void);

int calc_unmovable(void);

#else

static inline void add_memory_size(int flags, int size) {}
static inline int get_memory_size(int flags) { return 0; }

#endif

#endif /* _LINUX_PAGEREMAP_H */
