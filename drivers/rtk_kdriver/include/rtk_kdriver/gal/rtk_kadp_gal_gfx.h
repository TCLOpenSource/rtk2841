#ifndef _GAL_GFX_DRIVER_H_
#define _GAL_GFX_DRIVER_H_

#include <linux/cdev.h>

#ifndef GAL_GFX_MAJOR
#define GAL_GFX_MAJOR 0   /* dynamic major by default */
#endif

#ifndef GAL_GFX_NR_DEVS
#define GAL_GFX_NR_DEVS 1
#endif



ssize_t gal_gfx_read   (struct file *filp, char __user *buf, size_t count, loff_t *f_pos) ;
ssize_t gal_gfx_write  (struct file *filp, const char __user *buf, size_t count, loff_t *f_pos) ;
loff_t  gal_gfx_llseek (struct file *filp, loff_t off, int whence) ;
int     gal_gfx_ioctl  (struct file *filp, unsigned int cmd, unsigned long arg) ;
int     gal_gfx_open   (struct inode *inode, struct file *filp) ;
int     gal_gfx_release(struct inode *inode, struct file *filp) ;
int     gal_gfx_mmap(struct file *filp, struct vm_area_struct *ps_vma);

int gal_gfx_init_module(void);
#endif
