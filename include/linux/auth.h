#ifndef AUTH_H
#define AUTH_H

#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */
#include <linux/sched.h>
#include <linux/dcache.h>
#include <linux/memblock.h>
#include <linux/device.h>
#include <linux/dma-contiguous.h>

//#define DEBUG_MSG

#define AUTH_MAJOR		8
#define AUTH_NAME		"auth device"

#define DEF_MAP_ADDR		0x20000000
#define MAX_MAP_ADDR		0x60000000
#define DEF_MEM_SIZE		0x10000000
#define DEF_MAP_SIZE		0x20000000
#define STR_LENGTH	32

#ifdef	CONFIG_REALTEK_SCHED_LOG
typedef struct {
	unsigned long		addr;
	unsigned long		size;
} sched_log_struct;

typedef char COMM_STR[TASK_COMM_LEN];
#endif // CONFIG_REALTEK_SCHED_LOG

typedef char AUTH_STR[20];

typedef struct {
	unsigned long		size;
	unsigned long		flag;
	char			str[STR_LENGTH];
} mem_alloc_struct;

typedef struct {
	unsigned long		addr;
	unsigned long		size;
} mem_region_struct;

typedef struct {
	unsigned long		addr;
	unsigned long		*bitmap;
} mem_map_info;

#ifdef CONFIG_COMPAT
typedef struct {
    unsigned int        size;
    unsigned int        flag;
    char		 str[STR_LENGTH];
} compat_mem_alloc_struct;

typedef struct {
    unsigned int        addr;
    unsigned int        size;
} compat_mem_region_struct;

typedef struct {
    unsigned int        addr;
    unsigned int        *bitmap;
} compat_mem_map_info;
#endif

extern struct device	*auth_dev;

void			rtktlb_init(void);
void			rtktlb_exit(void);
unsigned long		rtktlb_mmap(unsigned long addr);
unsigned long		rtktlb_munmap(unsigned long addr);

unsigned long		pli_map_memory(struct file *filp, unsigned long phys_addr, int size);
unsigned long		pli_unmap_memory(struct file *filp, unsigned long virt_addr);

#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
void			init_overlapped_region(unsigned long base_pfn, int count);
unsigned long		alloc_overlapped_memory(size_t size);
void			free_overlapped_memory(unsigned long phys_addr);
#endif

/*
 * Ioctl definitions
 */

/* Use 'k' as magic number */
#define AUTH_IOC_MAGIC	'k'

/*
 * S means "Set"			 : through a ptr,
 * T means "Tell"			 : directly with the argument value
 * G means "Get"			 : reply by setting through a pointer
 * Q means "Query"			 : response is on the return value
 * X means "eXchange"			 : G and S atomically
 * H means "sHift"			 : T and Q atomically
 */
#define AUTH_IOCQ_MAP			 _IOW(AUTH_IOC_MAGIC, 1, AUTH_STR)
#define AUTH_IOCQ_ALLOC			 _IOW(AUTH_IOC_MAGIC, 2, mem_alloc_struct)
#define AUTH_IOCQ_FREE			 _IO(AUTH_IOC_MAGIC, 3)
#define AUTH_IOCQ_FREEALL		 _IO(AUTH_IOC_MAGIC, 4)
#define AUTH_IOCQ_LISTALL		 _IO(AUTH_IOC_MAGIC, 5)
#define AUTH_IOCS_FLUSHVIRT		 _IOW(AUTH_IOC_MAGIC, 6, mem_region_struct)
#define AUTH_IOCS_FLUSHPHYS		 _IOW(AUTH_IOC_MAGIC, 7, mem_region_struct)
#define AUTH_IOCQ_ALLOCAV		 _IOW(AUTH_IOC_MAGIC, 8, mem_alloc_struct)
#define AUTH_IOCQ_FREEAV		 _IO(AUTH_IOC_MAGIC, 9)

#define AUTH_IOCH_DUMPMEM		 _IO(AUTH_IOC_MAGIC, 10)

#ifdef	CONFIG_REALTEK_SCHED_LOG
#define AUTH_IOCSINITLOGBUF		 _IOW(AUTH_IOC_MAGIC, 11, sched_log_struct)
#define AUTH_IOCTFREELOGBUF		 _IO(AUTH_IOC_MAGIC, 12)
#define AUTH_IOCTLOGSTART		 _IO(AUTH_IOC_MAGIC, 13)
#define AUTH_IOCGLOGSTOP		 _IOR(AUTH_IOC_MAGIC, 14, sched_log_struct)
#define AUTH_IOCXLOGNAME		 _IOWR(AUTH_IOC_MAGIC, 15, COMM_STR)
#define AUTH_IOCSTHREADNAME		 _IOW(AUTH_IOC_MAGIC, 16, COMM_STR)
#define AUTH_IOCTLOGEVENT		 _IO(AUTH_IOC_MAGIC, 17)
#endif // CONFIG_REALTEK_SCHED_LOG

#define AUTH_IOCQ_DCUSIZE		 _IO(AUTH_IOC_MAGIC, 20)

#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
#define AUTH_IOCQ_ALLOC_OVERLAPPED	 _IO(AUTH_IOC_MAGIC, 30)
#define AUTH_IOCQ_FREE_OVERLAPPED	 _IO(AUTH_IOC_MAGIC, 31)
#endif

#define AUTH_IOCQ_MEMC_START_ADDRESS	 _IO(AUTH_IOC_MAGIC, 40)
#define AUTH_IOCQ_MEMC_SIZE		 _IO(AUTH_IOC_MAGIC, 41)
#define AUTH_IOCQ_MDOMAIN_START_ADDRESS	 _IO(AUTH_IOC_MAGIC, 42)
#define AUTH_IOCQ_MDOMAIN_SIZE		 _IO(AUTH_IOC_MAGIC, 43)
#define AUTH_IOCQ_OD_START_ADDRESS	 _IO(AUTH_IOC_MAGIC, 44)
#define AUTH_IOCQ_OD_SIZE		 _IO(AUTH_IOC_MAGIC, 45)

#ifdef CONFIG_COMPAT
#define COMPAT_AUTH_IOCQ_ALLOC       _IOW(AUTH_IOC_MAGIC, 2, compat_mem_alloc_struct)
#define COMPAT_AUTH_IOCS_FLUSHVIRT   _IOW(AUTH_IOC_MAGIC, 6, compat_mem_region_struct)
#define COMPAT_AUTH_IOCS_FLUSHPHYS   _IOW(AUTH_IOC_MAGIC, 7, compat_mem_region_struct)
#define COMPAT_AUTH_IOCQ_ALLOCAV     _IOW(AUTH_IOC_MAGIC, 8, compat_mem_alloc_struct)
#endif

#endif // AUTH_H

