/*
 * videobuf2-kmalloc.c - kmalloc memory allocator for videobuf2
 *
 * Copyright (C) 2016 Realtek
 *
 * Author: liangliang_song <liangliang_song@apowertec.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 */

#include <linux/io.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/slab.h>

#include <media/videobuf2-v4l2.h>
#include <media/videobuf2-kmalloc.h>
#include <media/videobuf2-memops.h>

static void * kmalloc_user(unsigned long size)
{
	unsigned long phys_addr = 0;
	void *vptr = dma_alloc_coherent(NULL, size, &phys_addr, GFP_KERNEL);
	/*printk(KERN_WARNING"kmalloc_user  %08x,%08x,%08x\n" , vptr, phys_addr, virt_to_phys(vptr));*/
	return vptr;
}

static void kfree_user(void *vptr, unsigned long size)
{
	dma_free_coherent(NULL, size, vptr, virt_to_phys(vptr));
}

struct vb2_kmalloc_buf {
	void				*vaddr;
	struct frame_vector		*vec;
	enum dma_data_direction		dma_dir;
	unsigned long			size;
	atomic_t			refcount;
	struct vb2_vmarea_handler	handler;
	struct dma_buf			*dbuf;
};

static void vb2_kmalloc_put(void *buf_priv);

static void *vb2_kmalloc_alloc(void *alloc_ctx, unsigned long size,
			       enum dma_data_direction dma_dir, gfp_t gfp_flags)
{
	struct vb2_kmalloc_buf *buf;

	buf = kzalloc(sizeof(*buf), GFP_KERNEL | gfp_flags);
	if (!buf)
		return NULL;

	buf->size = size;
	buf->vaddr = kmalloc_user(buf->size);
	buf->dma_dir = dma_dir;
	buf->handler.refcount = &buf->refcount;
	buf->handler.put = vb2_kmalloc_put;
	buf->handler.arg = buf;

	if (!buf->vaddr) {
		pr_debug("kmalloc of size %ld failed\n", buf->size);
		kfree(buf);
		return NULL;
	}
	/*printk(KERN_WARNING "vb2_kmalloc_alloc:%08x, %08x\n", buf->vaddr, virt_to_phys(buf->vaddr));*/
	atomic_inc(&buf->refcount);
	return buf;
}

static void vb2_kmalloc_put(void *buf_priv)
{
	struct vb2_kmalloc_buf *buf = buf_priv;

	if (atomic_dec_and_test(&buf->refcount)) {
		kfree_user(buf->vaddr, buf->size);
		kfree(buf);
	}
}


static void *vb2_kmalloc_get_userptr(void *alloc_ctx, unsigned long vaddr,
				     unsigned long size,
				     enum dma_data_direction dma_dir)
{
	struct vb2_kmalloc_buf *buf;
	struct frame_vector *vec;
	int n_pages, offset, i;

	buf = kzalloc(sizeof(*buf), GFP_KERNEL);
	if (!buf)
		return NULL;

	buf->dma_dir = dma_dir;
	offset = vaddr & ~PAGE_MASK;
	buf->size = size;
	vec = vb2_create_framevec(vaddr, size, dma_dir == DMA_FROM_DEVICE);
	if (IS_ERR(vec))
		goto fail_pfnvec_create;
	buf->vec = vec;
	n_pages = frame_vector_count(vec);
	if (frame_vector_to_pages(vec) < 0) {
		unsigned long *nums = frame_vector_pfns(vec);

		/*
		 * We cannot get page pointers for these pfns. Check memory is
		 * physically contiguous and use direct mapping.
		 */
		for (i = 1; i < n_pages; i++)
			if (nums[i-1] + 1 != nums[i])
				goto fail_map;
		buf->vaddr = (__force void *)
				ioremap_nocache(nums[0] << PAGE_SHIFT, size);
	} else {
		buf->vaddr = vm_map_ram(frame_vector_pages(vec), n_pages, -1,
					PAGE_KERNEL);
	}

	if (!buf->vaddr)
		goto fail_map;
	buf->vaddr += offset;
	return buf;

fail_map:
	vb2_destroy_framevec(vec);
fail_pfnvec_create:
	kfree(buf);

	return NULL;
}

static void vb2_kmalloc_put_userptr(void *buf_priv)
{
	struct vb2_kmalloc_buf *buf = buf_priv;
	unsigned long vaddr = (unsigned long)buf->vaddr & PAGE_MASK;
	unsigned int i;
	struct page **pages;
	unsigned int n_pages;

	if (!buf->vec->is_pfns) {
		n_pages = frame_vector_count(buf->vec);
		pages = frame_vector_pages(buf->vec);
		if (vaddr)
			vm_unmap_ram((void *)vaddr, n_pages);
		if (buf->dma_dir == DMA_FROM_DEVICE)
			for (i = 0; i < n_pages; i++)
				set_page_dirty_lock(pages[i]);
	} else {
		iounmap((__force void __iomem *)buf->vaddr);
	}
	vb2_destroy_framevec(buf->vec);
	kfree(buf);
}

static void *vb2_kmalloc_vaddr(void *buf_priv)
{
	struct vb2_kmalloc_buf *buf = buf_priv;

	if (!buf->vaddr) {
		pr_err("Address of an unallocated plane requested "
		       "or cannot map user pointer\n");
		return NULL;
	}

	return buf->vaddr;
}

static unsigned int vb2_kmalloc_num_users(void *buf_priv)
{
	struct vb2_kmalloc_buf *buf = buf_priv;
	return atomic_read(&buf->refcount);
}

static int vb2_kmalloc_mmap(void *buf_priv, struct vm_area_struct *vma)
{
	struct vb2_kmalloc_buf *buf = buf_priv;
	
	unsigned long start = vma->vm_start;
	unsigned long size = PAGE_ALIGN(vma->vm_end - vma->vm_start);
	int ret;

	if (!buf || size > buf->size) {
		pr_err("No memory to map\n");
		return -EINVAL;
	}
	
	ret = remap_pfn_range(vma, start, (virt_to_phys(buf->vaddr) >> PAGE_SHIFT),
			size, PAGE_SHARED);
	if (ret) {
		pr_err("Remapping kmalloc memory, error: %d\n", ret);
		return ret;
	}

	/*
	 * Make sure that vm_areas for 2 buffers won't be merged together
	 */
	vma->vm_flags		|= VM_DONTEXPAND;

	/*
	 * Use common vm_area operations to track buffer refcount.
	 */
	vma->vm_private_data	= &buf->handler;
	vma->vm_ops		= &vb2_common_vm_ops;

	vma->vm_ops->open(vma);

	return 0;
}

#ifdef CONFIG_HAS_DMA
/*********************************************/
/*         DMABUF ops for exporters          */
/*********************************************/

struct vb2_kmalloc_attachment {
	struct sg_table sgt;
	enum dma_data_direction dma_dir;
};

static int vb2_kmalloc_dmabuf_ops_attach(struct dma_buf *dbuf, struct device *dev,
	struct dma_buf_attachment *dbuf_attach)
{
	struct vb2_kmalloc_attachment *attach;
	struct vb2_kmalloc_buf *buf = dbuf->priv;
	int num_pages = PAGE_ALIGN(buf->size) / PAGE_SIZE;
	struct sg_table *sgt;
	struct scatterlist *sg;
	void *vaddr = buf->vaddr;
	int ret;
	int i;

	attach = kzalloc(sizeof(*attach), GFP_KERNEL);
	if (!attach)
		return -ENOMEM;

	sgt = &attach->sgt;
	ret = sg_alloc_table(sgt, num_pages, GFP_KERNEL);
	if (ret) {
		kfree(attach);
		return ret;
	}
	for_each_sg(sgt->sgl, sg, sgt->nents, i) {
		struct page *page = virt_to_page(vaddr);

		if (!page) {
			sg_free_table(sgt);
			kfree(attach);
			return -ENOMEM;
		}
		sg_set_page(sg, page, PAGE_SIZE, 0);
		vaddr += PAGE_SIZE;
	}

	attach->dma_dir = DMA_NONE;
	dbuf_attach->priv = attach;
	return 0;
}

static void vb2_kmalloc_dmabuf_ops_detach(struct dma_buf *dbuf,
	struct dma_buf_attachment *db_attach)
{
	struct vb2_kmalloc_attachment *attach = db_attach->priv;
	struct sg_table *sgt;

	if (!attach)
		return;

	sgt = &attach->sgt;

	/* release the scatterlist cache */
	if (attach->dma_dir != DMA_NONE)
		dma_unmap_sg(db_attach->dev, sgt->sgl, sgt->orig_nents,
			attach->dma_dir);
	sg_free_table(sgt);
	kfree(attach);
	db_attach->priv = NULL;
}

static struct sg_table *vb2_kmalloc_dmabuf_ops_map(
	struct dma_buf_attachment *db_attach, enum dma_data_direction dma_dir)
{
	struct vb2_kmalloc_attachment *attach = db_attach->priv;
	/* stealing dmabuf mutex to serialize map/unmap operations */
	struct mutex *lock = &db_attach->dmabuf->lock;
	struct sg_table *sgt;

	mutex_lock(lock);

	sgt = &attach->sgt;
	/* return previously mapped sg table */
	if (attach->dma_dir == dma_dir) {
		mutex_unlock(lock);
		return sgt;
	}

	/* release any previous cache */
	if (attach->dma_dir != DMA_NONE) {
		dma_unmap_sg(db_attach->dev, sgt->sgl, sgt->orig_nents,
			attach->dma_dir);
		attach->dma_dir = DMA_NONE;
	}

	/* mapping to the client with new direction */
	sgt->nents = dma_map_sg(db_attach->dev, sgt->sgl, sgt->orig_nents,
				dma_dir);
	if (!sgt->nents) {
		pr_err("failed to map scatterlist\n");
		mutex_unlock(lock);
		return ERR_PTR(-EIO);
	}

	attach->dma_dir = dma_dir;

	mutex_unlock(lock);

	return sgt;
}

static void vb2_kmalloc_dmabuf_ops_unmap(struct dma_buf_attachment *db_attach,
	struct sg_table *sgt, enum dma_data_direction dma_dir)
{
	/* nothing to be done here */
}

static void vb2_kmalloc_dmabuf_ops_release(struct dma_buf *dbuf)
{
	/* drop reference obtained in vb2_kmalloc_get_dmabuf */
	vb2_kmalloc_put(dbuf->priv);
}

static void *vb2_kmalloc_dmabuf_ops_kmap(struct dma_buf *dbuf, unsigned long pgnum)
{
	struct vb2_kmalloc_buf *buf = dbuf->priv;

	return buf->vaddr + pgnum * PAGE_SIZE;
}

static void *vb2_kmalloc_dmabuf_ops_vmap(struct dma_buf *dbuf)
{
	struct vb2_kmalloc_buf *buf = dbuf->priv;

	return buf->vaddr;
}

static int vb2_kmalloc_dmabuf_ops_mmap(struct dma_buf *dbuf,
	struct vm_area_struct *vma)
{
	return vb2_kmalloc_mmap(dbuf->priv, vma);
}

static struct dma_buf_ops vb2_kmalloc_dmabuf_ops = {
	.attach = vb2_kmalloc_dmabuf_ops_attach,
	.detach = vb2_kmalloc_dmabuf_ops_detach,
	.map_dma_buf = vb2_kmalloc_dmabuf_ops_map,
	.unmap_dma_buf = vb2_kmalloc_dmabuf_ops_unmap,
	.kmap = vb2_kmalloc_dmabuf_ops_kmap,
	.kmap_atomic = vb2_kmalloc_dmabuf_ops_kmap,
	.vmap = vb2_kmalloc_dmabuf_ops_vmap,
	.mmap = vb2_kmalloc_dmabuf_ops_mmap,
	.release = vb2_kmalloc_dmabuf_ops_release,
};

static struct dma_buf *vb2_kmalloc_get_dmabuf(void *buf_priv, unsigned long flags)
{
	struct vb2_kmalloc_buf *buf = buf_priv;
	struct dma_buf *dbuf;
	DEFINE_DMA_BUF_EXPORT_INFO(exp_info);

	exp_info.ops = &vb2_kmalloc_dmabuf_ops;
	exp_info.size = buf->size;
	exp_info.flags = flags;
	exp_info.priv = buf;

	if (WARN_ON(!buf->vaddr))
		return NULL;

	dbuf = dma_buf_export(&exp_info);
	if (IS_ERR(dbuf))
		return NULL;

	/* dmabuf keeps reference to vb2 buffer */
	atomic_inc(&buf->refcount);

	return dbuf;
}
#endif /* CONFIG_HAS_DMA */


/*********************************************/
/*       callbacks for DMABUF buffers        */
/*********************************************/

static int vb2_kmalloc_map_dmabuf(void *mem_priv)
{
	struct vb2_kmalloc_buf *buf = mem_priv;

	buf->vaddr = dma_buf_vmap(buf->dbuf);

	return buf->vaddr ? 0 : -EFAULT;
}

static void vb2_kmalloc_unmap_dmabuf(void *mem_priv)
{
	struct vb2_kmalloc_buf *buf = mem_priv;

	dma_buf_vunmap(buf->dbuf, buf->vaddr);
	buf->vaddr = NULL;
}

static void vb2_kmalloc_detach_dmabuf(void *mem_priv)
{
	struct vb2_kmalloc_buf *buf = mem_priv;

	if (buf->vaddr)
		dma_buf_vunmap(buf->dbuf, buf->vaddr);

	kfree(buf);
}

static void *vb2_kmalloc_attach_dmabuf(void *alloc_ctx, struct dma_buf *dbuf,
	unsigned long size, enum dma_data_direction dma_dir)
{
	struct vb2_kmalloc_buf *buf;

	if (dbuf->size < size)
		return ERR_PTR(-EFAULT);

	buf = kzalloc(sizeof(*buf), GFP_KERNEL);
	if (!buf)
		return ERR_PTR(-ENOMEM);

	buf->dbuf = dbuf;
	buf->dma_dir = dma_dir;
	buf->size = size;

	return buf;
}


const struct vb2_mem_ops vb2_kmalloc_memops = {
	.alloc		= vb2_kmalloc_alloc,
	.put		= vb2_kmalloc_put,
	.get_userptr	= vb2_kmalloc_get_userptr,
	.put_userptr	= vb2_kmalloc_put_userptr,
#ifdef CONFIG_HAS_DMA
	.get_dmabuf	= vb2_kmalloc_get_dmabuf,
#endif
	.map_dmabuf	= vb2_kmalloc_map_dmabuf,
	.unmap_dmabuf	= vb2_kmalloc_unmap_dmabuf,
	.attach_dmabuf	= vb2_kmalloc_attach_dmabuf,
	.detach_dmabuf	= vb2_kmalloc_detach_dmabuf,
	.vaddr		= vb2_kmalloc_vaddr,
	.mmap		= vb2_kmalloc_mmap,
	.num_users	= vb2_kmalloc_num_users,
};
EXPORT_SYMBOL_GPL(vb2_kmalloc_memops);

MODULE_DESCRIPTION("kmalloc memory handling routines for videobuf2");
MODULE_AUTHOR("liangliang_song<liangliang_song@apowertec.com>");
MODULE_LICENSE("GPL");
