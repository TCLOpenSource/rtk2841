#ifndef _LINUX_RTKRECORD_H
#define _LINUX_RTKRECORD_H

#include <linux/rtkblueprint.h>
#include <linux/mmzone.h>
#include <linux/workqueue.h>

#define _MB_ 1024*1024
#define MB_calculate(x) ((x)/(1024 *1024))

typedef struct {
	unsigned long addr;
	unsigned long type;
	unsigned long priv;
	const void *caller;
	unsigned long pid;	// process id
	unsigned long tgid;	// thread id
	// timestamps
	unsigned long jiffies;
	unsigned long reserved;
} rtk_record;

typedef int list_rtk_mem_t(rtk_record **pRecords,unsigned long node_count,void *data);
typedef int free_rtk_mem_t(rtk_record *records);

#define RTK_SIGNATURE	0x70000000
#ifdef CONFIG_CMA_RANK_RBTREE
#define RTK_PARTIAL_FREE   0x80000000
#define RTK_NO_NODE			0xd0000000
#define RTK_UNKNOWN			0xe0000000
#endif
#define MAX_BUDDY_SIZE	(1 << (12+RKT_BP_MAX_ORDER-1))
#define MAX_CACHE_SIZE	(1 << (12+2))
#define BUDDY_ID	0x01000000
#define CACHE_ID	0x02000000
#define DRIVER_ID	0x03000000
#define NOSAVE_ID	0x04000000
#define BUDDY_MESG_ID	0x05000000
#define DRIVER_MESG_ID	0x06000000
#define ID_MASK		0x0f000000

#ifdef CONFIG_CMA_MONITOR
#define CMA_CALLER_STR_LENGTH 64
#define MODULE_KEYWORDS_LENGTH 32

typedef struct {
	char module_name[MODULE_KEYWORDS_LENGTH];
	unsigned long max_cma_limit;
	unsigned long low_cma_amount;
	unsigned long high_cma_amount;
} cma_monitor_record;
#endif

#define RTK_RECORD_TAG_DEFER_FREE 0
#define RTK_RECORD_DEFER_FREE_TIMEOUT 5000

void rtk_record_init(void);
void rtk_record_tag_set(rtk_record *ptr, unsigned int tag);
void rtk_record_tag_clear(unsigned long addr, unsigned int tag);
int rtk_record_tag_get(unsigned long addr, unsigned int tag);
int rtk_record_insert(unsigned long addr, unsigned long type, unsigned long priv, const void *caller);
int rtk_record_lookup(unsigned long addr, unsigned long *priv);
int rtk_record_lookup_ex(unsigned long addr, rtk_record **ptr, bool lock);
#ifdef CONFIG_CMA_RANK_RBTREE
int rtk_record_lookup_count(unsigned long addr, unsigned long *priv, size_t size, int lookup_only);
#endif
void rtk_record_delete(unsigned long addr);
void rtk_record_defer_free(struct work_struct *unused);
int list_all_rtk_memory_allocation_sort(list_rtk_mem_t list_func,int (*cmp_func)(const void *, const void *),void *data);
void free_all_rtk_memory_allocation(free_rtk_mem_t free_func);
int list_pid_mem(rtk_record **pRecords,unsigned long node_count,void *data);
int list_mem_size_descending_order(rtk_record **pRecords,unsigned long node_count,void *data);
int list_func_mem(rtk_record **pRecords,unsigned long node_count,void *data);
int list_addr_mem(rtk_record **pRecords,unsigned long node_count,void *data);
int list_mem_generic(rtk_record **pRecords,unsigned long node_count,void *data);
int cmp_caller_ascending_order(const void *a, const void *b);
int cmp_size_descending_order(const void *a, const void *b);
int cmp_pid_ascending_order(const void *a, const void *b);
int cmp_addr_ascending_order(const void *a, const void *b);

#endif /* _LINUX_RTKRECORD_H */

