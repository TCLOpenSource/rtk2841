#ifndef _SE_DRIVER_H_
#define _SE_DRIVER_H_


#include <linux/types.h>

#ifndef SE_MAJOR
#define SE_MAJOR 0
#endif
#ifndef SE_NR_DEVS
#define SE_NR_DEVS 1
#endif
#define SE_COMMAND_ENTRIES (4096*sizeof(uint32_t))

#define SEOFFSET(shift) (SEREG_BASE + offsetof(SEREG_INFO, shift))
#define SE_CMD_TIMEOUT 2*HZ
#define SE_RECOVERY_VCPU

#define SEREG_BASE		0xB800C000

#ifndef UINT32
typedef	unsigned int	__UINT32;
#define UINT32 __UINT32
#endif

static struct device *se_device_st;
static struct class *se_class;
struct se_dev *se_devices;
static uint8_t *noncacheBuffer;
static dma_addr_t noncacheBufferPhy;
struct semaphore sem_checkfinish;
struct semaphore sem_cmdqueue;
static struct platform_device *se_platform_devs;

/*
 * Our parameters which can be set at load time.
 */
int se_major = SE_MAJOR;
int se_minor;
int se_nr_devs = SE_NR_DEVS;

struct se_dev {
	volatile uint32_t initialized;
	volatile uint32_t CmdBase;
	volatile uint32_t CmdLimit;
	volatile uint32_t CmdWritePtr;
	volatile uint32_t size;
	volatile uint64_t u64InstCnt;
	volatile uint64_t u64IssuedInstCnt;
	volatile uint32_t ignore_interrupt;
	volatile uint32_t queue;
	volatile uint32_t CmdReadPtr;
	volatile uint32_t CmdReadPtr_aux;
	volatile uint64_t u64QueueInstCnt;
	volatile uint8_t  CmdBuf[SE_COMMAND_ENTRIES * sizeof(uint32_t)];
	struct semaphore sem;
	struct cdev cdev;
};

ssize_t rtk_se_read(struct file *filp, char __user *buf, size_t count,
                   loff_t *f_pos);
ssize_t rtk_se_write(struct file *filp, const char __user *buf, size_t count,
                    loff_t *f_pos);
loff_t  rtk_se_llseek(struct file *filp, loff_t off, int whence);
long    rtk_se_ioctl(struct file *filp,
                    unsigned int cmd, unsigned long arg);



#endif
