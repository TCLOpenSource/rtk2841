#ifndef _GDMA_HAL_GAL_DRIVER_H_
#define _GDMA_HAL_GAL_DRIVER_H_

#include <linux/cdev.h>
#include "rtk_kadp_gdma_hal_gal_export_user.h"
#define GDMA_HAL_GAL_DEBUG 0
#define GDMA_HAL_GAL_DUMP_DEBUG 0
#define GDMA_HAL_GAL_DPF_DEBUG 1

#ifdef GDMA_HAL_GAL_DEBUG
#define DBG_GAL_PRINT(s, args...) pr_debug ("[GAL]" s, ## args)
//#define DBG_GAL_PRINT(s, args...) printk(KERN_DEBUG s, ## args)
#else
#define DBG_GAL_PRINT(s, args...)
#endif

//#define DBG_GAL_PRINT_WARN(s, args...) printk(KERN_WARNING s, ## args)
#define DBG_GAL_PRINT_WARN(s, args...) pr_debug("[GAL]" s, ## args)

//#define DBG_GAL_PRINT_ERR(s, args...) printk(KERN_ERR s, ## args)
#define DBG_GAL_PRINT_ERR(s, args...) pr_err("[GAL]" s, ## args)

#define DBG_GAL_PRIV_FATAL                      0x00000001
#define DBG_GAL_PRIV_ERROR                      0x00000002
#define DBG_GAL_PRIV_WARNING            0x00000004
#define DBG_GAL_PRIV_MESSAGE            0x00000008
#define DBG_GAL_PRIV_VERBOSE            0x00000010
#define DBG_GAL_PRIV_CALLTRACE          0x00000020

#define DBG_GAL_DBGLEVEL_COUNT  6

#define DBG_GAL_DBG_FATAL               DBG_GAL_PRIV_FATAL, __FUNCTION__, __LINE__
#define DBG_GAL_DBG_ERROR               DBG_GAL_PRIV_ERROR, __FUNCTION__, __LINE__
#define DBG_GAL_DBG_WARNING             DBG_GAL_PRIV_WARNING, __FUNCTION__, __LINE__
#define DBG_GAL_DBG_MESSAGE             DBG_GAL_PRIV_MESSAGE, __FUNCTION__, __LINE__
#define DBG_GAL_DBG_VERBOSE             DBG_GAL_PRIV_VERBOSE, __FUNCTION__, __LINE__
#define DBG_GAL_DBG_CALLTRACE   DBG_GAL_PRIV_CALLTRACE, __FUNCTION__, __LINE__

#ifdef GDMA_HAL_GAL_DPF_DEBUG
#define DBGGAL_DPF(X)                   DBGGALDebugPrintf X
#else
#define DBGGAL_DPF(X)
#endif
void DBGGALDebugPrintf(int ui32DebugLevel,
											const char *pszFileName,
											unsigned int ui32Line,
											const char *pszFormat, ...);

#ifndef GDMA_HAL_GAL_MAJOR
#define GDMA_HAL_GAL_MAJOR 0   /* dynamic major by default */
#endif

#ifndef GDMA_HAL_GAL_NR_DEVS
#define GDMA_HAL_GAL_NR_DEVS 1
#endif

typedef struct {
    int              initialized ;
    struct semaphore sem ;
	struct semaphore sem_mouse ;
	struct semaphore sem_slp ;
    struct cdev      cdev ;         /* Char device structure          */
    KDRV_GAL_GLOBE_GAL_INFO_T gal;
	KDRV_GAL_GLOBE_GAL_SUR_LINK_PALETTE_INFO_T gPal;
} gdma_hal_gal_dev;


ssize_t GDMA_hal_gal_read   (struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
ssize_t GDMA_hal_gal_write  (struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);
loff_t  GDMA_hal_gal_llseek (struct file *filp, loff_t off, int whence);
int     GDMA_hal_gal_ioctl  (struct file *filp, unsigned int cmd, unsigned long arg);
int     GDMA_hal_gal_open   (struct inode *inode, struct file *filp);
int     GDMA_hal_gal_release(struct inode *inode, struct file *filp);

int GDMA_hal_gal_init_module(void);
int GDMA_hal_gal_init (bool flag);
int GDMA_hal_gal_finalize (bool flag);

#endif
