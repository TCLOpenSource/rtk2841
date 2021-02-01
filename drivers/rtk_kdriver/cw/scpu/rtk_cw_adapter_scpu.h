#ifndef __RTK_CW_ADAPTER_SCPU_H__
#define __RTK_CW_ADAPTER_SCPU_H__
#include <asm/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <rtk_kdriver/rtk_cw_util.h>

/***********************Mutex Lock define***********************/
#define CW_DRIVER_USE_RWLOCK
#define CW_DRIVER_LOCK_DISABLE_IRQ

#ifdef CW_DRIVER_USE_RWLOCK

/*************Use rw lock to protect*************/
#include <linux/rwlock_types.h>
typedef rwlock_t    MUTEX_LOCKTYPE;
#define INIT_LOCK(lock)                 rwlock_init(&(lock))
#ifndef CW_DRIVER_LOCK_DISABLE_IRQ
#define WRITE_LOCK(lock, flags)         write_lock(&(lock))
#define WRITE_UNLOCK(lock, flags)       write_unlock(&(lock))
#define READ_LOCK(lock, flags)          read_lock(&(lock))
#define READ_UNLOCK(lock, flags)        read_unlock(&(lock))
#else
#define WRITE_LOCK(lock, flags)         write_lock_irqsave(&(lock), flags)
#define WRITE_UNLOCK(lock, flags)       write_unlock_irqrestore(&(lock), flags)
#define READ_LOCK(lock, flags)          read_lock_irqsave(&(lock), flags)
#define READ_UNLOCK(lock, flags)        read_unlock_irqrestore(&(lock), flags)
#endif
#define GFP_ALLOCK_FLAG     GFP_ATOMIC

#else

/*************Use rw semaphore to protect*************/
#include <linux/rwsem.h>
typedef struct rw_semaphore MUTEX_LOCKTYPE;
#define INIT_LOCK(lock)                 init_rwsem(&(lock))
#define WRITE_LOCK(lock, flags)         up_write(&(lock))
#define WRITE_UNLOCK(lock, flags)       down_write(&(lock))
#define READ_LOCK(lock, flags)          up_read(&(lock))
#define READ_UNLOCK(lock, flags)        down_read(&(lock))

#define GFP_ALLOCK_FLAG     GFP_KERNEL

#endif



typedef struct _cw_key_region {
    char module_name[CW_MODULE_NAME_LEN];
    unsigned char cw_use; /*the count of cw used*/
    unsigned long map[BITMAP_LEN];/*the bit map of cw used*/
    struct list_head node;
} RTK_CW_KEY_REGION;

typedef struct _cw_key_region_mm {
    MUTEX_LOCKTYPE cw_mm_lock;
    struct list_head cw_key_region_list;
    unsigned long cw_map[BITMAP_LEN];/*the bit map of cw used*/
} RTK_CW_KEY_REGION_MM;


#endif /* 
 */
