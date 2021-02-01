#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>   /* DBG_PRINT()    */
#include <linux/slab.h>     /* kmalloc()      */
#include <linux/fs.h>       /* everything...  */
#include <linux/errno.h>    /* error codes    */
#include <linux/types.h>    /* size_t         */
#include <linux/cdev.h>
#include <linux/dma-mapping.h>
#include <asm/uaccess.h>    /* copy_*_user    */
#include <asm/barrier.h> /*dsb()*/

#include <linux/mm.h>
#include <linux/vmalloc.h>

#include <mach/rtk_platform.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/suspend.h>
#endif

#include <mach/irqs.h>
#include <mach/platform.h>
#include <linux/platform_device.h>
#include <gal/rtk_kadp_gal_gfx.h>


#ifndef GAL_GFX_MAJOR
#define GAL_GFX_MAJOR 0   /* dynamic major by default */
#endif

#ifndef GAL_GFX_NR_DEVS
#define GAL_GFX_NR_DEVS 1
#endif

/*#define DEBUG_GAL_GFX_MAP 1*/

struct semaphore gal_gfx_sem;

int gal_gfx_major   = GAL_GFX_MAJOR ;
int gal_gfx_minor;
int gal_gfx_nr_devs = GAL_GFX_NR_DEVS ;


extern int GAL_MEM_ADDR_START;
extern int GAL_MEM_SIZE;


static struct class *gal_gfx_class ;
struct cdev   gal_gfx_cdev ;


#if 0
#define DRV_NAME		"gal_gfx"
static const char  drv_name[] = DRV_NAME;

static struct platform_device *gal_gfx_devs;

static struct platform_driver gal_gfx_driver = {
	.driver = {
		.name         = (char *)drv_name,
		.bus          = &platform_bus_type,
	},
};
#endif

struct file_operations gal_gfx_fops
= {
	.owner    =    THIS_MODULE,
	.mmap     =    gal_gfx_mmap,
	.llseek   =    gal_gfx_llseek,
	.read     =    gal_gfx_read,
	.write    =    gal_gfx_write,
	.unlocked_ioctl    =    (void *)gal_gfx_ioctl,
	.open     =    gal_gfx_open,
	.release  =    gal_gfx_release,
} ;

loff_t gal_gfx_llseek(struct file *filp, loff_t off, int whence)
{
	return -EINVAL ;
}
ssize_t gal_gfx_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT ;
}
ssize_t gal_gfx_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	return -EFAULT ;
}
int gal_gfx_open(struct inode *inode, struct file *filp)
{
	return 0 ;
}

int gal_gfx_release(struct inode *inode, struct file *filp)
{
	return 0 ;
}

int gal_gfx_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret =  -ENOTTY ;



	return ret ;
}
int gal_gfx_mmap(struct file *filp, struct vm_area_struct *ps_vma)
{

	int ret = 0;
	unsigned int uiByteSize;
    unsigned long offset = 0;


	#if 1
		offset = (ps_vma->vm_pgoff<<PAGE_SHIFT) + GAL_MEM_ADDR_START;

	#else
		 /*GAL_USE_DVR_MEM*/
		offset = ps_vma->vm_pgoff<<PAGE_SHIFT;

	#endif


	if (down_interruptible(&gal_gfx_sem))
		return -ERESTARTSYS;

	uiByteSize = ps_vma->vm_end - ps_vma->vm_start;

	#ifdef DEBUG_GAL_GFX_MAP
    pr_debug(KERN_DEBUG " %s: Received mmap(2) request with ui32MMapOffset 0x%x and uiByteSize %d",
			 __FUNCTION__,
			 ps_vma->vm_pgoff,
			 uiByteSize);
	#endif

    /* Only support shared writeable mappings */
    if (((ps_vma->vm_flags & VM_WRITE) != 0) &&
			((ps_vma->vm_flags & VM_SHARED) == 0)) {
		pr_debug("%s: Cannot mmap non-shareable writable areas", __FUNCTION__);
		ret = -EINVAL;
		goto unlock_and_return;
    }


    /*
     * Disable mremap because our nopage handler assumes all
     * page requests have already been validated.
     */
    ps_vma->vm_flags |= VM_DONTEXPAND;

    /* Don't allow mapping to be inherited across a process fork */
    ps_vma->vm_flags |= VM_DONTCOPY;

    ps_vma->vm_flags |= VM_IO | VM_DONTDUMP;

	/*force to use noncached for test */
	//ps_vma->vm_page_prot = pgprot_noncached(ps_vma->vm_page_prot);
    ps_vma->vm_page_prot = pgprot_writecombine(ps_vma->vm_page_prot);
	if (io_remap_pfn_range(ps_vma, ps_vma->vm_start, offset >> PAGE_SHIFT,
						   uiByteSize, ps_vma->vm_page_prot)) {
		ret = -EAGAIN;
		goto unlock_and_return;
	}

unlock_and_return:

    up(&gal_gfx_sem);

	return ret ;
}

void gal_gfx_cleanup_module(void)
{
	dev_t devno = MKDEV(gal_gfx_major, gal_gfx_minor);
	cdev_del(&gal_gfx_cdev) ;
	device_destroy(gal_gfx_class, MKDEV(gal_gfx_major, 0)) ;

	class_destroy(gal_gfx_class) ;
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, gal_gfx_nr_devs) ;
}

static void gal_gfx_setup_cdev(struct cdev   *gal_gfx_cdev, int index)
{
	int err, devno = MKDEV(gal_gfx_major, gal_gfx_minor + index) ;

	cdev_init(gal_gfx_cdev, &gal_gfx_fops) ;
	gal_gfx_cdev->owner = THIS_MODULE ;
	gal_gfx_cdev->ops   = &gal_gfx_fops;
	err = cdev_add (gal_gfx_cdev, devno, 1) ;

	if (err)
		pr_debug(KERN_NOTICE "Error %d adding se%d", err, index) ;
	device_create(gal_gfx_class, NULL, MKDEV(gal_gfx_major, index), NULL, "gfx") ;
	/*device_create(gal_gfx_class, NULL, MKDEV(gal_gfx_major, index), NULL, "gdma%d", index) ;*/
}
static char *gal_gfx_devnode(struct device *dev, mode_t *mode)
{
	return NULL ;
}

int gal_gfx_init_module(void)
{
	int result;
	dev_t dev = 0 ;
	pr_debug("gal_gfx module_init init \n");

	sema_init(&gal_gfx_sem, 1);

	if (gal_gfx_major) {
		dev    = MKDEV(gal_gfx_major, gal_gfx_minor) ;
		result = register_chrdev_region(dev, gal_gfx_nr_devs, "gal_gfx") ;
	} else {
		result     = alloc_chrdev_region(&dev, gal_gfx_minor, gal_gfx_nr_devs, "gal_gfx") ;
		gal_gfx_major = MAJOR(dev) ;
	}

	if (result < 0) {
		pr_debug(KERN_WARNING "gal_gfx: can't get major %d\n", gal_gfx_major) ;
		return result ;
	}

	pr_debug(KERN_WARNING "gal_gfx init module major number = %d\n", gal_gfx_major) ;

	gal_gfx_class = class_create(THIS_MODULE, "gal_gfx");
	if (IS_ERR(gal_gfx_class))
		return PTR_ERR(gal_gfx_class) ;

	gal_gfx_class->devnode = gal_gfx_devnode ;

	gal_gfx_setup_cdev (&gal_gfx_cdev,  0) ;

#ifdef CONFIG_LG_SNAPSHOT_BOOT
	register_cma_forbidden_region(__phys_to_pfn(CONST_GAL_MEM_ADDR_START), CONST_GAL_MEM_SIZE);
#endif

	pr_debug("gal_gfx module_init finish\n");
	return 0 ;
}

module_init(gal_gfx_init_module) ;
module_exit(gal_gfx_cleanup_module) ;


/*===============================================*/
