/*
 * drivers/gpu/ion/ion_dvr_heap.c
 *
 * Copyright (C) Linaro 2012
 * Author: <benjamin.gaignard@linaro.org> for ST-Ericsson.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/device.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/err.h>
#include <linux/dma-mapping.h>
#include <linux/pageremap.h>
#include <linux/vmalloc.h>
#include <linux/highmem.h>
#include <linux/io.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/ctype.h>
#include <linux/kernel.h>

#include "ion.h"
#include "ion_priv.h"

#define DEBUG 1  //kjw test add

#define ION_DVR_ALLOCATE_FAILED -1

struct ion_dvr_heap {
	struct ion_heap heap;
	struct device *dev;
};

#define to_dvr_heap(x) container_of(x, struct ion_dvr_heap, heap)

struct ion_dvr_buffer_info {
	struct page *dvr_page;
	unsigned long phys_addr;
	unsigned long flags;
	struct sg_table *table;
};

/*
 * Create scatter-list for the already allocated DMA buffer.
 * This function could be replaced by dma_common_get_sgtable
 * as soon as it will avalaible.
 */
static int ion_dvr_get_sgtable(struct device *dev, struct sg_table *sgt,
			       void *virt_addr, unsigned long phys_addr, size_t size)
{
	struct page *page = phys_to_page(phys_addr);
	int ret;

	ret = sg_alloc_table(sgt, 1, GFP_KERNEL);
	if (unlikely(ret))
		return ret;

	sg_set_page(sgt->sgl, page, PAGE_ALIGN(size), 0);
	return 0;
}

/* ION CMA heap operations functions */
static int ion_dvr_allocate(struct ion_heap *heap, struct ion_buffer *buffer,
			    unsigned long len, unsigned long align,
			    unsigned long flags)
{
	struct ion_dvr_heap *dvr_heap = to_dvr_heap(heap);
	struct device *dev = dvr_heap->dev;
	struct ion_dvr_buffer_info *info;
	int i;
	unsigned int pid_flags=0;
	unsigned char *name_ptr=0;
	struct task_struct *ptask;
	//struct pid_namespace tmp_pid_ns;
	
	dev_dbg(dev, "Request buffer allocation len %ld\n", len);

//	if (buffer->flags & ION_FLAG_CACHED)
//		return -EINVAL;

	pid_flags = (flags & 0xffffff00)>>8;
	flags = flags & 0x000000ff;
	/* printk("func=%s line=%d pid_flags=%d \n",__FUNCTION__,__LINE__,pid_flags); */
	name_ptr = kmalloc(TASK_COMM_LEN*4,GFP_KERNEL);
	if(!name_ptr)
	    return -EINVAL;
	memset(name_ptr,'\0',TASK_COMM_LEN);
	//strcpy(name_ptr,"ION_DRV:");    	
    snprintf(name_ptr, 20, "ION_DRV:%d:",pid_flags);

	if(pid_flags != 0){
		rcu_read_lock();
		ptask = find_task_by_pid_ns(pid_flags, &init_pid_ns);
		if (ptask){

	        strcat(name_ptr,ptask->comm);
		}rcu_read_unlock();
	}
	/* printk("func=%s line=%d name_ptr=%s \n",__FUNCTION__,__LINE__,name_ptr); */
	
	if (align > PAGE_SIZE)
		return -EINVAL;

	
	info = kzalloc(sizeof(struct ion_dvr_buffer_info), GFP_KERNEL);
	if (!info) {
		dev_err(dev, "Can't allocate buffer info\n");
		return ION_DVR_ALLOCATE_FAILED;
	}
	info->flags = flags;

	if (buffer->flags & ION_FLAG_FROM_DCU1) {
		info->dvr_page = dvr_malloc_page_mesg(len, GFP_DCU1,name_ptr);
		//info->dvr_page = dvr_malloc_page(len, GFP_DCU1);
	} else if (buffer->flags & ION_FLAG_FROM_DCU2) {
		info->dvr_page = dvr_malloc_page_mesg(len, GFP_DCU2,name_ptr);
		//info->dvr_page = dvr_malloc_page(len, GFP_DCU2);
	} else {
		info->dvr_page = dvr_malloc_page_mesg(len, GFP_DCU2_FIRST,name_ptr);
		//info->dvr_page = dvr_malloc_page(len, GFP_DCU2_FIRST);
	}
	if (!info->dvr_page) {
		dev_err(dev, "Fail to allocate buffer\n");
		goto err;
	}

	for (i = 0; i < (PAGE_ALIGN(len) >> PAGE_SHIFT); i++)
		clear_highpage(info->dvr_page + i);
	ion_pages_sync_for_device(NULL, info->dvr_page, PAGE_ALIGN(len), DMA_BIDIRECTIONAL);
	info->phys_addr = page_to_phys(info->dvr_page);

	info->table = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
	if (!info->table) {
		dev_err(dev, "Fail to allocate sg table\n");
		goto free_mem;
	}

	if (ion_dvr_get_sgtable
	    (dev, info->table, NULL, info->phys_addr, len))
		goto free_table;
	/* keep this for memory release */
	buffer->priv_virt = info;
	dev_dbg(dev, "dvr ion alloc %p %d \n", info->phys_addr, len);
	return 0;

free_table:
	kfree(info->table);
free_mem:
	dvr_free_page_mesg(info->dvr_page);
	//dvr_free_page(info->dvr_page);
err:
	kfree(info);
	return ION_DVR_ALLOCATE_FAILED;
}

static void ion_dvr_free(struct ion_buffer *buffer)
{
	struct ion_dvr_heap *dvr_heap = to_dvr_heap(buffer->heap);
	struct device *dev = dvr_heap->dev;
	struct ion_dvr_buffer_info *info = buffer->priv_virt;

	dev_dbg(dev, "Release buffer %p\n", buffer);
	/* release memory */
	dvr_free_page_mesg(info->dvr_page);
	//dvr_free_page(info->dvr_page);
	/* release sg table */
	sg_free_table(info->table);
	kfree(info->table);
	kfree(info);
}

/* return physical address in addr */
static int ion_dvr_phys(struct ion_heap *heap, struct ion_buffer *buffer,
			ion_phys_addr_t *addr, size_t *len)
{
	struct ion_dvr_heap *dvr_heap = to_dvr_heap(buffer->heap);
	struct device *dev = dvr_heap->dev;
	struct ion_dvr_buffer_info *info = buffer->priv_virt;

	dev_dbg(dev, "Return buffer %p physical address 0x%pa\n", buffer,
		&info->phys_addr);

	*addr = info->phys_addr;
	*len = buffer->size;

	return 0;
}

static struct sg_table *ion_dvr_heap_map_dma(struct ion_heap *heap,
					     struct ion_buffer *buffer)
{
	struct ion_dvr_buffer_info *info = buffer->priv_virt;

	return info->table;
}

static void ion_dvr_heap_unmap_dma(struct ion_heap *heap,
				   struct ion_buffer *buffer)
{
	return;
}

static int ion_dvr_mmap(struct ion_heap *mapper, struct ion_buffer *buffer,
			struct vm_area_struct *vma)
{
	struct ion_dvr_heap *dvr_heap = to_dvr_heap(buffer->heap);
	struct device *dev = dvr_heap->dev;
	struct ion_dvr_buffer_info *info = buffer->priv_virt;
	unsigned long user_count = (vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
	unsigned long count = PAGE_ALIGN(buffer->size) >> PAGE_SHIFT;
	unsigned long pfn = info->phys_addr >> PAGE_SHIFT;
	unsigned long off = vma->vm_pgoff;
	int ret = -ENXIO;

	if (!(info->flags & ION_FLAG_CACHED))
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	if (off < count && user_count <= (count - off)) {
		dev_dbg(dev, "Map %lx to %lx size %lx\n", 
			(pfn + off) << PAGE_SHIFT, vma->vm_start, user_count << PAGE_SHIFT);
	        ret = remap_pfn_range(vma, vma->vm_start,
	                              pfn + off,
	                              user_count << PAGE_SHIFT,
	                              vma->vm_page_prot);
	}

	return ret;
}

static struct ion_heap_ops ion_dvr_ops = {
	.allocate = ion_dvr_allocate,
	.free = ion_dvr_free,
	.map_dma = ion_dvr_heap_map_dma,
	.unmap_dma = ion_dvr_heap_unmap_dma,
	.phys = ion_dvr_phys,
	.map_user = ion_dvr_mmap,
	.map_kernel = ion_heap_map_kernel,
	.unmap_kernel = ion_heap_unmap_kernel,
};

struct ion_heap *ion_dvr_heap_create(struct ion_platform_heap *data)
{
	struct ion_dvr_heap *dvr_heap;
	dvr_heap = kzalloc(sizeof(struct ion_dvr_heap), GFP_KERNEL);

	if (!dvr_heap)
		return ERR_PTR(-ENOMEM);

	dvr_heap->heap.ops = &ion_dvr_ops;
	/* get device from private heaps data, later it will be
	 * used to make the link with reserved CMA memory */
	dvr_heap->dev = data->priv;
	dvr_heap->heap.type = ION_HEAP_TYPE_CUSTOM;
	return &dvr_heap->heap;
}

void ion_dvr_heap_destroy(struct ion_heap *heap)
{
	struct ion_dvr_heap *dvr_heap = to_dvr_heap(heap);

	kfree(dvr_heap);
}
