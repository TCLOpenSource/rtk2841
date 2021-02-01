/*
 * CMA DebugFS Interface
 *
 * Copyright (c) 2015 Sasha Levin <sasha.levin@oracle.com>
 */


#include <linux/debugfs.h>
#include <linux/cma.h>
#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/sort.h>
#include <linux/mm_types.h>
#include <asm/uaccess.h>
#include "cma.h"

#ifdef CONFIG_CMA_RTK_ALLOCATOR
#include <linux/rtkrecord.h>
#include <linux/rtkblueprint.h>
#include <linux/pageremap.h>
#include <linux/auth.h>

void *dma_get_allocator(struct device *dev);
#endif

struct cma_mem {
	struct hlist_node node;
	struct page *p;
	unsigned long n;
};

static struct dentry *cma_debugfs_root;

static int cma_debugfs_get(void *data, u64 *val)
{
	unsigned long *p = data;

	*val = *p;

	return 0;
}
DEFINE_SIMPLE_ATTRIBUTE(cma_debugfs_fops, cma_debugfs_get, NULL, "%llu\n");

static int cma_used_get(void *data, u64 *val)
{
	struct cma *cma = data;
	unsigned long used;

	mutex_lock(&cma->lock);
	/* pages counter is smaller than sizeof(int) */
	used = bitmap_weight(cma->bitmap, (int)cma_bitmap_maxno(cma));
	mutex_unlock(&cma->lock);
	*val = (u64)used << cma->order_per_bit;

	return 0;
}
DEFINE_SIMPLE_ATTRIBUTE(cma_used_fops, cma_used_get, NULL, "%llu\n");

static int cma_maxchunk_get(void *data, u64 *val)
{
	struct cma *cma = data;
	unsigned long maxchunk = 0;
	unsigned long start, end = 0;
	unsigned long bitmap_maxno = cma_bitmap_maxno(cma);

	mutex_lock(&cma->lock);
	for (;;) {
		start = find_next_zero_bit(cma->bitmap, bitmap_maxno, end);
		if (start >= cma->count)
			break;
		end = find_next_bit(cma->bitmap, bitmap_maxno, start);
		maxchunk = max(end - start, maxchunk);
	}
	mutex_unlock(&cma->lock);
	*val = (u64)maxchunk << cma->order_per_bit;

	return 0;
}
DEFINE_SIMPLE_ATTRIBUTE(cma_maxchunk_fops, cma_maxchunk_get, NULL, "%llu\n");

static void cma_add_to_cma_mem_list(struct cma *cma, struct cma_mem *mem)
{
	spin_lock(&cma->mem_head_lock);
	hlist_add_head(&mem->node, &cma->mem_head);
	spin_unlock(&cma->mem_head_lock);
}

static struct cma_mem *cma_get_entry_from_list(struct cma *cma)
{
	struct cma_mem *mem = NULL;

	spin_lock(&cma->mem_head_lock);
	if (!hlist_empty(&cma->mem_head)) {
		mem = hlist_entry(cma->mem_head.first, struct cma_mem, node);
		hlist_del_init(&mem->node);
	}
	spin_unlock(&cma->mem_head_lock);

	return mem;
}

static int cma_free_mem(struct cma *cma, int count)
{
	struct cma_mem *mem = NULL;

	while (count) {
		mem = cma_get_entry_from_list(cma);
		if (mem == NULL)
			return 0;

		if (mem->n <= count) {
			cma_release(cma, mem->p, mem->n);
			count -= mem->n;
			kfree(mem);
		} else if (cma->order_per_bit == 0) {
			cma_release(cma, mem->p, count);
			mem->p += count;
			mem->n -= count;
			count = 0;
			cma_add_to_cma_mem_list(cma, mem);
		} else {
			pr_debug("cma: cannot release partial block when order_per_bit != 0\n");
			cma_add_to_cma_mem_list(cma, mem);
			break;
		}
	}

	return 0;

}

static int cma_free_write(void *data, u64 val)
{
	int pages = val;
	struct cma *cma = data;

	return cma_free_mem(cma, pages);
}
DEFINE_SIMPLE_ATTRIBUTE(cma_free_fops, NULL, cma_free_write, "%llu\n");

static int cma_alloc_mem(struct cma *cma, int count)
{
	struct cma_mem *mem;
	struct page *p;

	mem = kzalloc(sizeof(*mem), GFP_KERNEL);
	if (!mem)
		return -ENOMEM;

	p = cma_alloc(cma, count, 0);
	if (!p) {
		kfree(mem);
		return -ENOMEM;
	}

	mem->p = p;
	mem->n = count;

	cma_add_to_cma_mem_list(cma, mem);

	return 0;
}

static int cma_alloc_write(void *data, u64 val)
{
	int pages = val;
	struct cma *cma = data;

	return cma_alloc_mem(cma, pages);
}
DEFINE_SIMPLE_ATTRIBUTE(cma_alloc_fops, NULL, cma_alloc_write, "%llu\n");

#ifdef CONFIG_CMA_RTK_ALLOCATOR
static ssize_t
cma_addr_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
	pr_info("\n\tshow list by address ascending order:\n");
	list_all_rtk_memory_allocation_sort(list_addr_mem,cmp_addr_ascending_order,NULL);
	return 0;
}

static ssize_t cma_addr_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos)
{
	char info[64];

	pr_info("\n\tshow list by address range:\n");
	memset(info,0,sizeof(info));
	if(len > 63){
		pr_err("function name too long\n");
		return -EFBIG;
	}

	if (copy_from_user(info,buf,len))
		return -EFAULT;

	list_all_rtk_memory_allocation_sort(list_addr_mem,cmp_addr_ascending_order,info);

	return len;

}

static const struct file_operations cma_addr_fops = {
	.read		= cma_addr_read,
	.write	= cma_addr_write,
};


static ssize_t
cma_caller_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
	pr_info("\n\tshow list sort by function caller:\n");
	list_all_rtk_memory_allocation_sort(list_func_mem,cmp_caller_ascending_order,NULL);
	return 0;
}

static ssize_t cma_caller_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos)
{
	char info[128];

	pr_info("\n\tshow list by function name key word:\n");
	memset(info,0,sizeof(info));
	if(len > 127){
		pr_err("function name too long\n");
		return -EFBIG;
	}

	if (copy_from_user(info,buf,len))
		return -EFAULT;

	list_all_rtk_memory_allocation_sort(list_func_mem,cmp_caller_ascending_order,info);

	return len;
}

static const struct file_operations cma_caller_fops = {
	.read	= cma_caller_read,
	.write	= cma_caller_write,
};

static ssize_t
cma_pid_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
	pr_info("\n\tshow list sort by pid:\n");
	list_all_rtk_memory_allocation_sort(list_pid_mem,cmp_pid_ascending_order,NULL);
	return 0;
}

static ssize_t cma_pid_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos)
{
	char info[16];

	pr_info("\n\tshow list by pid:\n");
	memset(info,0,sizeof(info));
	if(len > 15){
		pr_err("function name too long\n");
		return -EFBIG;
	}

	if (copy_from_user(info,buf,len))
		return -EFAULT;

	list_all_rtk_memory_allocation_sort(list_pid_mem,cmp_pid_ascending_order,info);

	return len;
}

static const struct file_operations cma_pid_fops = {
	.read		= cma_pid_read,
	.write	= cma_pid_write,
};

static ssize_t
cma_size_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
	pr_info("\n\tshow list by size descending order:\n");
	list_all_rtk_memory_allocation_sort(list_mem_size_descending_order,cmp_size_descending_order,NULL);
	return 0;
}

static ssize_t cma_size_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos)
{
	char info[64];

	pr_info("\n\tshow list by size range:\n");
	memset(info,0,sizeof(info));
	if(len > 63){
		pr_err("function name too long\n");
		return -EFBIG;
	}

	if (copy_from_user(info,buf,len))
		return -EFAULT;

	list_all_rtk_memory_allocation_sort(list_mem_size_descending_order,cmp_size_descending_order,info);

	return len;

}

static const struct file_operations cma_size_fops = {
	.read		= cma_size_read,
	.write	= cma_size_write,
};

static ssize_t
cma_free_area_read(struct file *file, char __user *buf, size_t len, loff_t *ppos)
{
	pr_err("\n\tshow cma free area:\n");
	pr_err("\n\tDCU1:\n");
	show_rtkbp((struct mem_bp *)dma_get_allocator(NULL));
	pr_err("\n\tDCU2:\n");
	show_rtkbp((struct mem_bp *)dma_get_allocator(auth_dev));
	return 0;
}

static const struct file_operations cma_free_area_fops = {
	.read		= cma_free_area_read,
};

static void cma_debugfs_add_record(void)
{
	struct dentry *tmp;

	tmp = debugfs_create_dir("record", cma_debugfs_root);	
	debugfs_create_file("list_by_address", S_IRWXUGO, tmp, NULL,&cma_addr_fops);
	debugfs_create_file("list_by_caller", S_IRWXUGO, tmp, NULL,&cma_caller_fops);
	debugfs_create_file("list_by_pid", S_IRWXUGO, tmp, NULL,&cma_pid_fops);
	debugfs_create_file("list_by_size", S_IRWXUGO, tmp, NULL,&cma_size_fops);
	debugfs_create_file("free_area", S_IRUGO, tmp, NULL,&cma_free_area_fops);
}
#endif

static void cma_debugfs_add_one(struct cma *cma, int idx)
{
	struct dentry *tmp;
	char name[16];
	int u32s;

	sprintf(name, "cma-%d", idx);

	tmp = debugfs_create_dir(name, cma_debugfs_root);

	debugfs_create_file("alloc", S_IWUSR, tmp, cma,
				&cma_alloc_fops);

	debugfs_create_file("free", S_IWUSR, tmp, cma,
				&cma_free_fops);

	debugfs_create_file("base_pfn", S_IRUGO, tmp,
				&cma->base_pfn, &cma_debugfs_fops);
	debugfs_create_file("count", S_IRUGO, tmp,
				&cma->count, &cma_debugfs_fops);
	debugfs_create_file("order_per_bit", S_IRUGO, tmp,
				&cma->order_per_bit, &cma_debugfs_fops);
	debugfs_create_file("used", S_IRUGO, tmp, cma, &cma_used_fops);
	debugfs_create_file("maxchunk", S_IRUGO, tmp, cma, &cma_maxchunk_fops);

	u32s = DIV_ROUND_UP(cma_bitmap_maxno(cma), BITS_PER_BYTE * sizeof(u32));
	debugfs_create_u32_array("bitmap", S_IRUGO, tmp, (u32*)cma->bitmap, u32s);
}

static int __init cma_debugfs_init(void)
{
	int i;

	cma_debugfs_root = debugfs_create_dir("cma", NULL);
	if (!cma_debugfs_root)
		return -ENOMEM;

	for (i = 0; i < cma_area_count; i++)
		cma_debugfs_add_one(&cma_areas[i], i);
#ifdef CONFIG_CMA_RTK_ALLOCATOR
	cma_debugfs_add_record();
#endif
	return 0;
}
late_initcall(cma_debugfs_init);
