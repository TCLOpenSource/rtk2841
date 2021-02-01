/*
 *  linux/drivers/char/mem.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 *
 *  Added devfs support.
 *    Jan-11-1998, C. Scott Ananian <cananian@alumni.princeton.edu>
 *  Shared /dev/zero mmapping support, Feb 2000, Kanoj Sarcar <kanoj@sgi.com>
 */

#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/mman.h>
#include <linux/random.h>
#include <linux/init.h>
#include <linux/raw.h>
#include <linux/tty.h>
#include <linux/capability.h>
#include <linux/ptrace.h>
#include <linux/device.h>
#include <linux/highmem.h>
#include <linux/backing-dev.h>
#include <linux/splice.h>
#include <linux/pfn.h>
#include <linux/export.h>
#include <linux/io.h>
#include <linux/uio.h>

#include <linux/uaccess.h>

#ifdef CONFIG_IA64
# include <linux/efi.h>
#endif

#define DEVPORT_MINOR	4

static inline unsigned long size_inside_page(unsigned long start,
					     unsigned long size)
{
	unsigned long sz;

	sz = PAGE_SIZE - (start & (PAGE_SIZE - 1));

	return min(sz, size);
}

#ifndef ARCH_HAS_VALID_PHYS_ADDR_RANGE
static inline int valid_phys_addr_range(phys_addr_t addr, size_t count)
{
	return addr + count <= __pa(high_memory);
}

static inline int valid_mmap_phys_addr_range(unsigned long pfn, size_t size)
{
	return 1;
}
#endif

#ifdef CONFIG_STRICT_DEVMEM
static inline int range_is_allowed(unsigned long pfn, unsigned long size)
{
	u64 from = ((u64)pfn) << PAGE_SHIFT;
	u64 to = from + size;
	u64 cursor = from;

	while (cursor < to) {
		if (!devmem_is_allowed(pfn)) {
			printk(KERN_INFO
		"Program %s tried to access /dev/mem between %Lx->%Lx.\n",
				current->comm, from, to);
			return 0;
		}
		cursor += PAGE_SIZE;
		pfn++;
	}
	return 1;
}
#else
static inline int range_is_allowed(unsigned long pfn, unsigned long size)
{
	return 1;
}
#endif

#ifndef unxlate_dev_mem_ptr
#define unxlate_dev_mem_ptr unxlate_dev_mem_ptr
void __weak unxlate_dev_mem_ptr(phys_addr_t phys, void *addr)
{
}
#endif

/*
 * This funcion reads the *physical* memory. The f_pos points directly to the
 * memory location.
 */
static ssize_t read_mem(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
	phys_addr_t p = *ppos;
	ssize_t read, sz;
	void *ptr;

	if (p != *ppos)
		return 0;

	if (!valid_phys_addr_range(p, count))
		return -EFAULT;
	read = 0;
#ifdef __ARCH_HAS_NO_PAGE_ZERO_MAPPED
	/* we don't have page 0 mapped on sparc and m68k.. */
	if (p < PAGE_SIZE) {
		sz = size_inside_page(p, count);
		if (sz > 0) {
			if (clear_user(buf, sz))
				return -EFAULT;
			buf += sz;
			p += sz;
			count -= sz;
			read += sz;
		}
	}
#endif

	while (count > 0) {
		unsigned long remaining;

		sz = size_inside_page(p, count);

		if (!range_is_allowed(p >> PAGE_SHIFT, count))
			return -EPERM;

		/*
		 * On ia64 if a page has been mapped somewhere as uncached, then
		 * it must also be accessed uncached by the kernel or data
		 * corruption may occur.
		 */
		ptr = xlate_dev_mem_ptr(p);
		if (!ptr)
			return -EFAULT;

		remaining = copy_to_user(buf, ptr, sz);
		unxlate_dev_mem_ptr(p, ptr);
		if (remaining)
			return -EFAULT;

		buf += sz;
		p += sz;
		count -= sz;
		read += sz;
	}

	*ppos += read;
	return read;
}

static ssize_t write_mem(struct file *file, const char __user *buf,
			 size_t count, loff_t *ppos)
{
	phys_addr_t p = *ppos;
	ssize_t written, sz;
	unsigned long copied;
	void *ptr;

	if (p != *ppos)
		return -EFBIG;

	if (!valid_phys_addr_range(p, count))
		return -EFAULT;

	written = 0;

#ifdef __ARCH_HAS_NO_PAGE_ZERO_MAPPED
	/* we don't have page 0 mapped on sparc and m68k.. */
	if (p < PAGE_SIZE) {
		sz = size_inside_page(p, count);
		/* Hmm. Do something? */
		buf += sz;
		p += sz;
		count -= sz;
		written += sz;
	}
#endif

	while (count > 0) {
		sz = size_inside_page(p, count);

		if (!range_is_allowed(p >> PAGE_SHIFT, sz))
			return -EPERM;

		/*
		 * On ia64 if a page has been mapped somewhere as uncached, then
		 * it must also be accessed uncached by the kernel or data
		 * corruption may occur.
		 */
		ptr = xlate_dev_mem_ptr(p);
		if (!ptr) {
			if (written)
				break;
			return -EFAULT;
		}

		copied = copy_from_user(ptr, buf, sz);
		unxlate_dev_mem_ptr(p, ptr);
		if (copied) {
			written += sz - copied;
			if (written)
				break;
			return -EFAULT;
		}

		buf += sz;
		p += sz;
		count -= sz;
		written += sz;
	}

	*ppos += written;
	return written;
}

int __weak phys_mem_access_prot_allowed(struct file *file,
	unsigned long pfn, unsigned long size, pgprot_t *vma_prot)
{
	return 1;
}

#ifndef __HAVE_PHYS_MEM_ACCESS_PROT

/*
 * Architectures vary in how they handle caching for addresses
 * outside of main memory.
 *
 */
#ifdef pgprot_noncached
static int uncached_access(struct file *file, phys_addr_t addr)
{
#if defined(CONFIG_IA64)
	/*
	 * On ia64, we ignore O_DSYNC because we cannot tolerate memory
	 * attribute aliases.
	 */
	return !(efi_mem_attributes(addr) & EFI_MEMORY_WB);
#elif defined(CONFIG_MIPS)
	{
		extern int __uncached_access(struct file *file,
					     unsigned long addr);

		return __uncached_access(file, addr);
	}
#else
	/*
	 * Accessing memory above the top the kernel knows about or through a
	 * file pointer
	 * that was marked O_DSYNC will be done non-cached.
	 */
	if (file->f_flags & O_DSYNC)
		return 1;
	return addr >= __pa(high_memory);
#endif
}
#endif

static pgprot_t phys_mem_access_prot(struct file *file, unsigned long pfn,
				     unsigned long size, pgprot_t vma_prot)
{
#ifdef pgprot_noncached
	phys_addr_t offset = pfn << PAGE_SHIFT;

	if (uncached_access(file, offset))
		return pgprot_noncached(vma_prot);
#endif
	return vma_prot;
}
#endif

#ifndef CONFIG_MMU
static unsigned long get_unmapped_area_mem(struct file *file,
					   unsigned long addr,
					   unsigned long len,
					   unsigned long pgoff,
					   unsigned long flags)
{
	if (!valid_mmap_phys_addr_range(pgoff, len))
		return (unsigned long) -EINVAL;
	return pgoff << PAGE_SHIFT;
}

/* permit direct mmap, for read, write or exec */
static unsigned memory_mmap_capabilities(struct file *file)
{
	return NOMMU_MAP_DIRECT |
		NOMMU_MAP_READ | NOMMU_MAP_WRITE | NOMMU_MAP_EXEC;
}

static unsigned zero_mmap_capabilities(struct file *file)
{
	return NOMMU_MAP_COPY;
}

/* can't do an in-place private mapping if there's no MMU */
static inline int private_mapping_ok(struct vm_area_struct *vma)
{
	return vma->vm_flags & VM_MAYSHARE;
}
#else

static inline int private_mapping_ok(struct vm_area_struct *vma)
{
	return 1;
}
#endif

static const struct vm_operations_struct mmap_mem_ops = {
#ifdef CONFIG_HAVE_IOREMAP_PROT
	.access = generic_access_phys
#endif
};

static int mmap_mem(struct file *file, struct vm_area_struct *vma)
{
	size_t size = vma->vm_end - vma->vm_start;

	if (!valid_mmap_phys_addr_range(vma->vm_pgoff, size))
		return -EINVAL;

	if (!private_mapping_ok(vma))
		return -ENOSYS;

	if (!range_is_allowed(vma->vm_pgoff, size))
		return -EPERM;

	if (!phys_mem_access_prot_allowed(file, vma->vm_pgoff, size,
						&vma->vm_page_prot))
		return -EINVAL;

	vma->vm_page_prot = phys_mem_access_prot(file, vma->vm_pgoff,
						 size,
						 vma->vm_page_prot);

	vma->vm_ops = &mmap_mem_ops;

	/* Remap-pfn-range will mark the range VM_IO */
	if (remap_pfn_range(vma,
			    vma->vm_start,
			    vma->vm_pgoff,
			    size,
			    vma->vm_page_prot)) {
		return -EAGAIN;
	}
	return 0;
}

static int mmap_kmem(struct file *file, struct vm_area_struct *vma)
{
	unsigned long pfn;

	/* Turn a kernel-virtual address into a physical page frame */
	pfn = __pa((u64)vma->vm_pgoff << PAGE_SHIFT) >> PAGE_SHIFT;

	/*
	 * RED-PEN: on some architectures there is more mapped memory than
	 * available in mem_map which pfn_valid checks for. Perhaps should add a
	 * new macro here.
	 *
	 * RED-PEN: vmalloc is not supported right now.
	 */
	if (!pfn_valid(pfn))
		return -EIO;

	vma->vm_pgoff = pfn;
	return mmap_mem(file, vma);
}

/*
 * This function reads the *virtual* memory as seen by the kernel.
 */
static ssize_t read_kmem(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	unsigned long p = *ppos;
	ssize_t low_count, read, sz;
	char *kbuf; /* k-addr because vread() takes vmlist_lock rwlock */
	int err = 0;

	read = 0;
	if (p < (unsigned long) high_memory) {
		low_count = count;
		if (count > (unsigned long)high_memory - p)
			low_count = (unsigned long)high_memory - p;

#ifdef __ARCH_HAS_NO_PAGE_ZERO_MAPPED
		/* we don't have page 0 mapped on sparc and m68k.. */
		if (p < PAGE_SIZE && low_count > 0) {
			sz = size_inside_page(p, low_count);
			if (clear_user(buf, sz))
				return -EFAULT;
			buf += sz;
			p += sz;
			read += sz;
			low_count -= sz;
			count -= sz;
		}
#endif
		while (low_count > 0) {
			sz = size_inside_page(p, low_count);

			/*
			 * On ia64 if a page has been mapped somewhere as
			 * uncached, then it must also be accessed uncached
			 * by the kernel or data corruption may occur
			 */
			kbuf = xlate_dev_kmem_ptr((void *)p);

			if (copy_to_user(buf, kbuf, sz))
				return -EFAULT;
			buf += sz;
			p += sz;
			read += sz;
			low_count -= sz;
			count -= sz;
		}
	}

	if (count > 0) {
		kbuf = (char *)__get_free_page(GFP_KERNEL);
		if (!kbuf)
			return -ENOMEM;
		while (count > 0) {
			sz = size_inside_page(p, count);
			if (!is_vmalloc_or_module_addr((void *)p)) {
				err = -ENXIO;
				break;
			}
			sz = vread(kbuf, (char *)p, sz);
			if (!sz)
				break;
			if (copy_to_user(buf, kbuf, sz)) {
				err = -EFAULT;
				break;
			}
			count -= sz;
			buf += sz;
			read += sz;
			p += sz;
		}
		free_page((unsigned long)kbuf);
	}
	*ppos = p;
	return read ? read : err;
}


static ssize_t do_write_kmem(unsigned long p, const char __user *buf,
				size_t count, loff_t *ppos)
{
	ssize_t written, sz;
	unsigned long copied;

	written = 0;
#ifdef __ARCH_HAS_NO_PAGE_ZERO_MAPPED
	/* we don't have page 0 mapped on sparc and m68k.. */
	if (p < PAGE_SIZE) {
		sz = size_inside_page(p, count);
		/* Hmm. Do something? */
		buf += sz;
		p += sz;
		count -= sz;
		written += sz;
	}
#endif

	while (count > 0) {
		void *ptr;

		sz = size_inside_page(p, count);

		/*
		 * On ia64 if a page has been mapped somewhere as uncached, then
		 * it must also be accessed uncached by the kernel or data
		 * corruption may occur.
		 */
		ptr = xlate_dev_kmem_ptr((void *)p);

		copied = copy_from_user(ptr, buf, sz);
		if (copied) {
			written += sz - copied;
			if (written)
				break;
			return -EFAULT;
		}
		buf += sz;
		p += sz;
		count -= sz;
		written += sz;
	}

	*ppos += written;
	return written;
}

/*
 * This function writes to the *virtual* memory as seen by the kernel.
 */
static ssize_t write_kmem(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	unsigned long p = *ppos;
	ssize_t wrote = 0;
	ssize_t virtr = 0;
	char *kbuf; /* k-addr because vwrite() takes vmlist_lock rwlock */
	int err = 0;

	if (p < (unsigned long) high_memory) {
		unsigned long to_write = min_t(unsigned long, count,
					       (unsigned long)high_memory - p);
		wrote = do_write_kmem(p, buf, to_write, ppos);
		if (wrote != to_write)
			return wrote;
		p += wrote;
		buf += wrote;
		count -= wrote;
	}

	if (count > 0) {
		kbuf = (char *)__get_free_page(GFP_KERNEL);
		if (!kbuf)
			return wrote ? wrote : -ENOMEM;
		while (count > 0) {
			unsigned long sz = size_inside_page(p, count);
			unsigned long n;

			if (!is_vmalloc_or_module_addr((void *)p)) {
				err = -ENXIO;
				break;
			}
			n = copy_from_user(kbuf, buf, sz);
			if (n) {
				err = -EFAULT;
				break;
			}
			vwrite(kbuf, (char *)p, sz);
			count -= sz;
			buf += sz;
			virtr += sz;
			p += sz;
		}
		free_page((unsigned long)kbuf);
	}

	*ppos = p;
	return virtr + wrote ? : err;
}

static ssize_t read_port(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	unsigned long i = *ppos;
	char __user *tmp = buf;

	if (!access_ok(VERIFY_WRITE, buf, count))
		return -EFAULT;
	while (count-- > 0 && i < 65536) {
		if (__put_user(inb(i), tmp) < 0)
			return -EFAULT;
		i++;
		tmp++;
	}
	*ppos = i;
	return tmp-buf;
}

static ssize_t write_port(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	unsigned long i = *ppos;
	const char __user *tmp = buf;

	if (!access_ok(VERIFY_READ, buf, count))
		return -EFAULT;
	while (count-- > 0 && i < 65536) {
		char c;

		if (__get_user(c, tmp)) {
			if (tmp > buf)
				break;
			return -EFAULT;
		}
		outb(c, i);
		i++;
		tmp++;
	}
	*ppos = i;
	return tmp-buf;
}

static ssize_t read_null(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	return 0;
}

static ssize_t write_null(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	return count;
}

static ssize_t read_iter_null(struct kiocb *iocb, struct iov_iter *to)
{
	return 0;
}

static ssize_t write_iter_null(struct kiocb *iocb, struct iov_iter *from)
{
	size_t count = iov_iter_count(from);
	iov_iter_advance(from, count);
	return count;
}

static int pipe_to_null(struct pipe_inode_info *info, struct pipe_buffer *buf,
			struct splice_desc *sd)
{
	return sd->len;
}

static ssize_t splice_write_null(struct pipe_inode_info *pipe, struct file *out,
				 loff_t *ppos, size_t len, unsigned int flags)
{
	return splice_from_pipe(pipe, out, ppos, len, flags, pipe_to_null);
}

static ssize_t read_iter_zero(struct kiocb *iocb, struct iov_iter *iter)
{
	size_t written = 0;

	while (iov_iter_count(iter)) {
		size_t chunk = iov_iter_count(iter), n;

		if (chunk > PAGE_SIZE)
			chunk = PAGE_SIZE;	/* Just for latency reasons */
		n = iov_iter_zero(chunk, iter);
		if (!n && iov_iter_count(iter))
			return written ? written : -EFAULT;
		written += n;
		if (signal_pending(current))
			return written ? written : -ERESTARTSYS;
		cond_resched();
	}
	return written;
}

static int mmap_zero(struct file *file, struct vm_area_struct *vma)
{
#ifndef CONFIG_MMU
	return -ENOSYS;
#endif
	if (vma->vm_flags & VM_SHARED)
		return shmem_zero_setup(vma);
	return 0;
}

static ssize_t write_full(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	return -ENOSPC;
}

/*
 * Special lseek() function for /dev/null and /dev/zero.  Most notably, you
 * can fopen() both devices with "a" now.  This was previously impossible.
 * -- SRB.
 */
static loff_t null_lseek(struct file *file, loff_t offset, int orig)
{
	return file->f_pos = 0;
}

/*
 * The memory devices use the full 32/64 bits of the offset, and so we cannot
 * check against negative addresses: they are ok. The return value is weird,
 * though, in that case (0).
 *
 * also note that seeking relative to the "end of file" isn't supported:
 * it has no meaning, so it returns -EINVAL.
 */
static loff_t memory_lseek(struct file *file, loff_t offset, int orig)
{
	loff_t ret;

	mutex_lock(&file_inode(file)->i_mutex);
	switch (orig) {
	case SEEK_CUR:
		offset += file->f_pos;
	case SEEK_SET:
		/* to avoid userland mistaking f_pos=-9 as -EBADF=-9 */
		if (IS_ERR_VALUE((unsigned long long)offset)) {
			ret = -EOVERFLOW;
			break;
		}
		file->f_pos = offset;
		ret = file->f_pos;
		force_successful_syscall_return();
		break;
	default:
		ret = -EINVAL;
	}
	mutex_unlock(&file_inode(file)->i_mutex);
	return ret;
}

static int open_port(struct inode *inode, struct file *filp)
{
#if defined (CONFIG_LG_KERNEL_EXPAND)
	//temporarily 0, should be reverted.
	return 0;
#else
	return capable(CAP_SYS_RAWIO) ? 0 : -EPERM;
#endif
}

#ifdef CONFIG_REALTEK_DEV_MEM
#include <linux/pageremap.h>

#define MEM_IOCQALLOC           _IO('k', 0x20)
#define MEM_IOCQFREE            _IO('k', 0x21)

struct mem_record_head {
	struct list_head        list;
	struct mutex            mutex;
};

struct mem_record_node {
	struct list_head        list;
	unsigned long           addr;
};

static int mmap_rtkmem(struct file *file, struct vm_area_struct *vma)
{
	size_t size = vma->vm_end - vma->vm_start;

	if (!valid_mmap_phys_addr_range(vma->vm_pgoff, size))
		return -EINVAL;

	if (!private_mapping_ok(vma))
		return -ENOSYS;

	if (!range_is_allowed(vma->vm_pgoff, size))
		return -EPERM;

	if (!phys_mem_access_prot_allowed(file, vma->vm_pgoff, size,
						&vma->vm_page_prot))
		return -EINVAL;

	if (file->f_flags & O_DSYNC)
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);

	vma->vm_ops = &mmap_mem_ops;

	/* Remap-pfn-range will mark the range VM_IO */
	if (remap_pfn_range(vma,
			    vma->vm_start,
			    vma->vm_pgoff,
			    size,
			    vma->vm_page_prot)) {
		return -EAGAIN;
	}

    if (pfn_valid(vma->vm_pgoff))
        vma->vm_flags = (vma->vm_flags | VM_PLI);

	return 0;
}

static int open_rtkmem(struct inode * inode, struct file * filp)
{
	return 0;
}

static int release_rtkmem(struct inode * inode, struct file * filp)
{
	if (filp->private_data != NULL) {
		struct mem_record_node *rec, *tmp;
		struct list_head *plist;

		plist = &((struct mem_record_head *)filp->private_data)->list;
		list_for_each_entry_safe(rec, tmp, plist, list) {
//			printk("*** remove2: %lx \n", rec->addr);
			dvr_free_page(pfn_to_page(rec->addr));
			list_del(&rec->list);
			kfree(rec);
		}

		kfree(filp->private_data);
		filp->private_data = NULL;
	}
	return 0;
}

static long ioctl_rtkmem(struct file *filp, unsigned int cmd, unsigned long arg)
{
	long ret = 0;

	switch (cmd) {
	case MEM_IOCQALLOC:
	{
		struct page *page;
		struct mem_record_node *record;

		page = dvr_malloc_page(arg, 0);
		if (page != 0)
			ret = page_to_pfn(page) << PAGE_SHIFT;
		else
			return -ENOMEM;

		if (filp->private_data == NULL) {
			struct mem_record_head *head;
			head = kmalloc(sizeof(struct mem_record_head), GFP_KERNEL);
			INIT_LIST_HEAD(&head->list);
			mutex_init(&head->mutex);
			filp->private_data = head;
		}

		if (mutex_lock_interruptible(&((struct mem_record_head *)filp->private_data)->mutex)) {
			// we use return value 1 to represent an signal is caught...
			printk("mem: interrupted by an signal...\n");
			dvr_free_page(page);
			return -EAGAIN;
		}
		record = kmalloc(sizeof(struct mem_record_node), GFP_KERNEL);
		INIT_LIST_HEAD(&record->list);
		record->addr = page_to_pfn(page);
		list_add(&record->list, &((struct mem_record_head *)filp->private_data)->list);
		mutex_unlock(&((struct mem_record_head *)filp->private_data)->mutex);
	}
	break;

	case MEM_IOCQFREE:
	{
		if (filp->private_data != NULL) {
			int flag = 0;
			struct mem_record_node *rec, *tmp;
			struct list_head *plist;

			if (mutex_lock_interruptible(&((struct mem_record_head *)filp->private_data)->mutex)) {
				// we use return value 1 to represent an signal is caught...
				printk("mem: interrupted by an signal...\n");
				return -EAGAIN;
			}
			plist = &((struct mem_record_head *)filp->private_data)->list;
			list_for_each_entry_safe(rec, tmp, plist, list)
				if (rec->addr == (arg >> PAGE_SHIFT)) {
//					printk("*** remove1: %lx \n", rec->addr);
					list_del(&rec->list);
					kfree(rec);
					flag = 1;
					break;
				}
			mutex_unlock(&((struct mem_record_head *)filp->private_data)->mutex);

			if (flag) {
				dvr_free_page(pfn_to_page(arg >> PAGE_SHIFT));
			} else {
				printk("mem: invalid parameter %lu in MEM_IOCQFREE...\n", arg);
				ret = -EINVAL;
			}
		}
	}
	break;

	default:
		return -EINVAL;

	}
	return ret;
}
#endif

#define zero_lseek	null_lseek
#define full_lseek      null_lseek
#define write_zero	write_null
#define write_iter_zero	write_iter_null
#define open_mem	open_port
#define open_kmem	open_mem

static const struct file_operations __maybe_unused mem_fops = {
	.llseek		= memory_lseek,
	.read		= read_mem,
	.write		= write_mem,
	.mmap		= mmap_mem,
	.open		= open_mem,
#ifndef CONFIG_MMU
	.get_unmapped_area = get_unmapped_area_mem,
	.mmap_capabilities = memory_mmap_capabilities,
#endif
};

static const struct file_operations __maybe_unused kmem_fops = {
	.llseek		= memory_lseek,
	.read		= read_kmem,
	.write		= write_kmem,
	.mmap		= mmap_kmem,
	.open		= open_kmem,
#ifndef CONFIG_MMU
	.get_unmapped_area = get_unmapped_area_mem,
	.mmap_capabilities = memory_mmap_capabilities,
#endif
};

static const struct file_operations null_fops = {
	.llseek		= null_lseek,
	.read		= read_null,
	.write		= write_null,
	.read_iter	= read_iter_null,
	.write_iter	= write_iter_null,
	.splice_write	= splice_write_null,
};

static const struct file_operations __maybe_unused port_fops = {
	.llseek		= memory_lseek,
	.read		= read_port,
	.write		= write_port,
	.open		= open_port,
};

static const struct file_operations zero_fops = {
	.llseek		= zero_lseek,
	.write		= write_zero,
	.read_iter	= read_iter_zero,
	.write_iter	= write_iter_zero,
	.mmap		= mmap_zero,
#ifndef CONFIG_MMU
	.mmap_capabilities = zero_mmap_capabilities,
#endif
};

static const struct file_operations full_fops = {
	.llseek		= full_lseek,
	.read_iter	= read_iter_zero,
	.write		= write_full,
};

#ifdef CONFIG_LG_MEM_DEVICE
static int open_lgmem(struct inode * inode, struct file * filp)
{
//	return capable(CAP_SYS_RAWIO) ? 0 : -EPERM;
//	have to return 0 for non-super users
	return 0;
}

static ssize_t read_lgmem(struct file *file, char __user *buf,
		size_t count, loff_t *ppos)
#if 1
{
	struct vm_area_struct * vma;
	struct mm_struct *mm ;
	unsigned long p = *ppos;
	unsigned int data[3];

	if ((mm = current->mm) == NULL)
		return -ENXIO;

	if (count < sizeof(data))
		return -EINVAL;

	down_read(&mm->mmap_sem);

	vma = find_vma(mm, p);

	if (!vma)
		goto bad_area;

	if (vma->vm_start > p)
		goto bad_area;

	data[0] = vma->vm_start;
	data[1] = vma->vm_end;
	data[2] = vma->vm_flags;

	up_read(&mm->mmap_sem);
	if (copy_to_user(buf, data, sizeof(data)))
		return -EFAULT;
	else
		return sizeof(data);

bad_area:
	up_read(&mm->mmap_sem);
	return -ENXIO;
}
#else
{
	int rc = -ENXIO;
	struct vm_area_struct * vma;
	struct mm_struct *mm ;

	unsigned long p = *ppos;
	char		data[256];

	if ((mm = current->mm) == NULL)
		goto bad_area;


	down_read(&mm->mmap_sem);

	vma = find_vma(mm, p);

	if (!vma)
		goto bad_area;

	if (vma->vm_start > p)
		goto bad_area;


	snprintf(data,sizeof(data),"%08lx-%08lx %c%c%c%c",
			vma->vm_start, vma->vm_end,
			vma->vm_flags & VM_READ ? 	'r' : '-',
			vma->vm_flags & VM_WRITE ? 	'w' : '-',
			vma->vm_flags & VM_EXEC ? 	'x' : '-',
			vma->vm_flags & VM_MAYSHARE ? 's' : 'p');


	if (count < (strlen(data) + 1))
		goto bad_area;

	if (copy_to_user(buf, data, strlen(data) + 1))
		goto bad_area;

	rc = strlen(data) + 1;
bad_area:
	up_read(&mm->mmap_sem);
	return rc;
}
#endif

static const struct file_operations lgmem_fops = {
	.llseek		= memory_lseek,
	.open		= open_lgmem,
	.read		= read_lgmem,
};
#endif

#if 0
static ssize_t kmsg_writev(struct kiocb *iocb, const struct iovec *iv,
			   unsigned long count, loff_t pos)
{
	char *line, *p;
	int i;
	ssize_t ret = -EFAULT;
	size_t len = iov_length(iv, count);

	line = kmalloc(len + 1, GFP_KERNEL);
	if (line == NULL)
		return -ENOMEM;

	/*
	 * copy all vectors into a single string, to ensure we do
	 * not interleave our log line with other printk calls
	 */
	p = line;
	for (i = 0; i < count; i++) {
		if (copy_from_user(p, iv[i].iov_base, iv[i].iov_len))
			goto out;
		p += iv[i].iov_len;
	}
	p[0] = '\0';

	ret = printk("%s", line);
	/* printk can add a prefix */
	if (ret > len)
		ret = len;
out:
	kfree(line);
	return ret;
}
static const struct file_operations lgkmsg_fops = {
	.aio_write = kmsg_writev,
	.llseek = noop_llseek,
};
#endif

#ifdef CONFIG_REALTEK_DEV_MEM
static const struct file_operations rtkmem_fops = {
//	.llseek         = memory_lseek,
//	.read           = read_mem,
//	.write          = write_mem,
	.mmap           = mmap_rtkmem,
	.open           = open_rtkmem,
	.release        = release_rtkmem,
	.unlocked_ioctl = ioctl_rtkmem,
};
#endif

static const struct memdev {
	const char *name;
	umode_t mode;
	const struct file_operations *fops;
	fmode_t fmode;
} devlist[] = {
#ifdef CONFIG_DEVMEM
	 [1] = { "mem", 0, &mem_fops, FMODE_UNSIGNED_OFFSET },
#endif
#ifdef CONFIG_DEVKMEM
	 [2] = { "kmem", 0, &kmem_fops, FMODE_UNSIGNED_OFFSET },
#endif
	 [3] = { "null", 0666, &null_fops, 0 },
#ifdef CONFIG_DEVPORT
	 [4] = { "port", 0, &port_fops, 0 },
#endif
	 [5] = { "zero", 0666, &zero_fops, 0 },
	 [7] = { "full", 0666, &full_fops, 0 },
	 [8] = { "random", 0666, &random_fops, 0 },
	 [9] = { "urandom", 0666, &urandom_fops, 0 },
#ifdef CONFIG_PRINTK
	[11] = { "kmsg", 0644, &kmsg_fops, 0 },
#endif
#ifdef CONFIG_LG_MEM_DEVICE
	[13] = { "lgmem", 0, &lgmem_fops, NULL },
#endif
#ifdef CONFIG_REALTEK_DEV_MEM
	[14] = { "rtkmem", 0666, &rtkmem_fops, FMODE_UNSIGNED_OFFSET },
#endif
};

static int memory_open(struct inode *inode, struct file *filp)
{
	int minor;
	const struct memdev *dev;

	minor = iminor(inode);
	if (minor >= ARRAY_SIZE(devlist))
		return -ENXIO;

	dev = &devlist[minor];
	if (!dev->fops)
		return -ENXIO;

	filp->f_op = dev->fops;
	filp->f_mode |= dev->fmode;

	if (dev->fops->open)
		return dev->fops->open(inode, filp);

	return 0;
}

static const struct file_operations memory_fops = {
	.open = memory_open,
	.llseek = noop_llseek,
};

static char *mem_devnode(struct device *dev, umode_t *mode)
{
	if (mode && devlist[MINOR(dev->devt)].mode)
		*mode = devlist[MINOR(dev->devt)].mode;
	return NULL;
}

static struct class *mem_class;

static int __init chr_dev_init(void)
{
	int minor;

	if (register_chrdev(MEM_MAJOR, "mem", &memory_fops))
		printk("unable to get major %d for memory devs\n", MEM_MAJOR);

	mem_class = class_create(THIS_MODULE, "mem");
	if (IS_ERR(mem_class))
		return PTR_ERR(mem_class);

	mem_class->devnode = mem_devnode;
	for (minor = 1; minor < ARRAY_SIZE(devlist); minor++) {
		if (!devlist[minor].name)
			continue;

		/*
		 * Create /dev/port?
		 */
		if ((minor == DEVPORT_MINOR) && !arch_has_dev_port())
			continue;

		device_create(mem_class, NULL, MKDEV(MEM_MAJOR, minor),
			      NULL, devlist[minor].name);
	}

	return tty_init();
}

fs_initcall(chr_dev_init);
