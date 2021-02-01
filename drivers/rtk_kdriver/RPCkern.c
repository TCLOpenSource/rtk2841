/*
 * $Id: RPCkern.c,v 1.10 2004/8/4 09:25 Jacky Exp $
 */
#include <generated/autoconf.h>
/*
#if defined(CONFIG_MODVERSIONS) && !defined(MODVERSIONS)
    #define MODVERSIONS
#endif

#ifdef MODVERSIONS
    #include <linux/modversions.h>
#endif

#ifndef MODULE
#define MODULE
#endif
*/
#include <linux/module.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>     /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/ioctl.h>    /* needed for the _IOW etc stuff used later */
#include <linux/sched.h>
#include <linux/freezer.h>
#include <linux/delay.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/kthread.h>
#include <asm/cacheflush.h>

#include <asm/io.h>
//#include <asm/system.h>     /* cli(), *_flags */
#include <asm/uaccess.h>    /* copy_to_user() copy_from_user() */
#include <rbus/sb2_reg.h>
#include <mach/platform.h>

//#define PDEBUG(fmt, args...) printk(KERN_ALERT "RPC: " fmt, ## args)
#define TIMEOUT 30*HZ
#define	LOOPCOUNT 50

static struct radix_tree_root kernel_rpc_tree = RADIX_TREE_INIT(GFP_ATOMIC);
static DEFINE_SEMAPHORE(kernel_rpc_sem);
static DEFINE_SEMAPHORE(kernel_rpc_read_sem);
extern unsigned int debugMode; // declaire in mach-rtdxxxx/init.c

#ifndef CONFIG_REALTEK_RPC_MULTIPROCESS
typedef struct RPC_STRUCT {
	unsigned long programID;      // program ID defined in IDL file
	unsigned long versionID;      // version ID defined in IDL file
	unsigned long procedureID;    // function ID defined in IDL file

	unsigned long taskID;         // the caller's task ID, assign 0 if NONBLOCK_MODE
	unsigned long parameterSize;  // packet's body size
	unsigned long mycontext;      // return address of reply value
} RPC_STRUCT;
#endif

typedef struct KRPC_INFO
{
	wait_queue_head_t *wq;
	int reply;
} KRPC_INFO;

RPC_KERN_Dev *rpc_kern_devices;
#ifdef CONFIG_REALTEK_RPC_KCPU
RPC_KERN_Dev *rpc_kern_kcpu_devices;
struct task_struct *rpc_kthread[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR] = {0};
static wait_queue_head_t rpc_wq[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
static struct semaphore send_kernel_rpc_sem[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
#ifdef CONFIG_REALTEK_RPC_VCPU2
static char *rpc_kthread_name[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR] = {"rpc-A", "rpc-V1", "rpc-V2","rpc-K"};
#else
static char *rpc_kthread_name[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR] = {"rpc-A", "rpc-V1", "rpc-K"};
#endif
#else
struct task_struct *rpc_kthread[RPC_NR_KERN_DEVS/RPC_NR_PAIR] = {0};
static wait_queue_head_t rpc_wq[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
static struct semaphore send_kernel_rpc_sem[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
#ifdef CONFIG_REALTEK_RPC_VCPU2
static char *rpc_kthread_name[RPC_NR_KERN_DEVS/RPC_NR_PAIR] = {"rpc-A", "rpc-V1", "rpc-V2"};
#else
static char *rpc_kthread_name[RPC_NR_KERN_DEVS/RPC_NR_PAIR] = {"rpc-A", "rpc-V1"};
#endif
#endif

#ifdef CONFIG_DEBUG_KERNEL_RPC
#define DEBUG_KERNEL_RPC_MAX_LEN 15
#define DEBUG_KERNEL_RPC_MAX_TIME 50
#define KERNEL_RPC_DUMMY_REGISTER	0xb8060130

typedef struct DEBUG_KERNEL_RPC {
	unsigned long ringIn;
	unsigned long ringOut;
	unsigned long programID;
	unsigned long versionID;
	unsigned long command;
	unsigned long para1;
	unsigned long  timestamp;
} DEBUG_KERNEL_RPC;

#ifdef CONFIG_REALTEK_RPC_KCPU
DEBUG_KERNEL_RPC debug_kernel_rpc[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR][DEBUG_KERNEL_RPC_MAX_LEN] = {{{0}}};
unsigned long krpc_time_before_handle_command[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long krpc_time_after_handle_command[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long krpc_handle_command_id[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long krpc_handle_command_count[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR]= {0};
#else
DEBUG_KERNEL_RPC debug_kernel_rpc[RPC_NR_KERN_DEVS/RPC_NR_PAIR][DEBUG_KERNEL_RPC_MAX_LEN] = {0};
unsigned long krpc_time_before_handle_command[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long krpc_time_after_handle_command[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long krpc_handle_command_id[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long krpc_handle_command_count[RPC_NR_KERN_DEVS/RPC_NR_PAIR]= {0};
#endif

#ifdef CONFIG_REALTEK_RPC_KCPU
unsigned long record_isr_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long record_isr_wake_up_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long record_isr_user_wake_up_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long record_thread_timeout[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long record_send_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
unsigned long print_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR] = {0};
#else
unsigned long record_isr_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long record_isr_wake_up_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long record_isr_user_wake_up_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long record_thread_timeout[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long record_send_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
unsigned long print_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR]= {0};
#endif
int rpc_video_dummy_record = 0;
#endif

int rpc_kern_is_paused = 0;

static int rpc_kernel_thread(void *p);
extern unsigned char Scaler_GetRPCInitByVCPU(void);

int rpc_kern_init(void)
{
	static int is_init = 0;
	int result = 0, num, i;

	// Create corresponding structures for each device.
	rpc_kern_devices = (RPC_KERN_Dev *)phys_to_virt(RPC_KERN_RECORD_ADDR);

	num = RPC_NR_KERN_DEVS;
	for (i = 0; i < num; i++) {
		PDEBUG("rpc_kern_device %d addr: %x \n", i, (unsigned)&rpc_kern_devices[i]);
		rpc_kern_devices[i].ringBuf = (char *)(phys_to_virt(RPC_KERN_DEV_ADDR + i*RPC_RING_SIZE));

		// Initialize pointers...
		rpc_kern_devices[i].ringStart = rpc_kern_devices[i].ringBuf;
		rpc_kern_devices[i].ringEnd = rpc_kern_devices[i].ringBuf+RPC_RING_SIZE;
		rpc_kern_devices[i].ringIn = rpc_kern_devices[i].ringBuf;
		rpc_kern_devices[i].ringOut = rpc_kern_devices[i].ringBuf;

		PDEBUG("The %dth RPC_KERN_Dev:\n", i);
		PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_kern_devices[i].ringStart);
		PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_kern_devices[i].ringEnd);
		PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_kern_devices[i].ringIn);
		PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_kern_devices[i].ringOut);
		PDEBUG("\n");

		if (!is_init) {
			rpc_kern_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

			// Initialize wait queue...
			init_waitqueue_head(&(rpc_kern_devices[i].ptrSync->waitQueue));

			// Initialize sempahores...
			sema_init(&rpc_kern_devices[i].ptrSync->readSem, 1);
			sema_init(&rpc_kern_devices[i].ptrSync->writeSem, 1);
		}

		if (i%RPC_NR_PAIR == 1) {
			if (rpc_kthread[i/RPC_NR_PAIR] == 0)
				rpc_kthread[i/RPC_NR_PAIR] = kthread_run(rpc_kernel_thread, (void *)i, "rpc-%d", i);
		}
	}
#ifdef CONFIG_REALTEK_RPC_KCPU
	// Create corresponding structures for each device.
	rpc_kern_kcpu_devices = (RPC_KERN_Dev *)phys_to_virt(RPC_KERN_KCPU_RECORD_ADDR);

	num = RPC_NR_KERN_KCPU_DEVS;
	for (i = 0; i < num; i++) {
		PDEBUG("rpc_kern_kcpu_device %d addr: %x \n", i, (unsigned)&rpc_kern_kcpu_devices[i]);

		rpc_kern_kcpu_devices[i].ringBuf = (char *)(phys_to_virt(RPC_KERN_KCPU_DEV_ADDR + i*RPC_RING_SIZE));

		// Initialize pointers...
		rpc_kern_kcpu_devices[i].ringStart = rpc_kern_kcpu_devices[i].ringBuf;
		rpc_kern_kcpu_devices[i].ringEnd = rpc_kern_kcpu_devices[i].ringBuf+RPC_RING_SIZE;
		rpc_kern_kcpu_devices[i].ringIn = rpc_kern_kcpu_devices[i].ringBuf;
		rpc_kern_kcpu_devices[i].ringOut = rpc_kern_kcpu_devices[i].ringBuf;

		PDEBUG("The %dth RPC_KERN_Dev:\n", i);
		PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_kern_kcpu_devices[i].ringStart);
		PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_kern_kcpu_devices[i].ringEnd);
		PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_kern_kcpu_devices[i].ringIn);
		PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_kern_kcpu_devices[i].ringOut);
		PDEBUG("\n");

		if (!is_init) {
			rpc_kern_kcpu_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

			// Initialize wait queue...
			init_waitqueue_head(&(rpc_kern_kcpu_devices[i].ptrSync->waitQueue));

			// Initialize sempahores...
			sema_init(&rpc_kern_kcpu_devices[i].ptrSync->readSem, 1);
			sema_init(&rpc_kern_kcpu_devices[i].ptrSync->writeSem, 1);
		}

		if (i%RPC_NR_PAIR == 1) {
			if (rpc_kthread[(i+RPC_NR_KERN_DEVS)/RPC_NR_PAIR] == 0)
				rpc_kthread[(i+RPC_NR_KERN_DEVS)/RPC_NR_PAIR] = kthread_run(rpc_kernel_thread,
						(void *)(i+RPC_NR_KERN_DEVS), "rpc-%d", i+RPC_NR_KERN_DEVS);
		}
	}
#endif
	if (!is_init) {
#ifdef CONFIG_REALTEK_RPC_KCPU
		for (i = 0; i < (RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR; i++)
#else
		for (i = 0; i < RPC_NR_KERN_DEVS/RPC_NR_PAIR; i++)
#endif
			init_waitqueue_head(&(rpc_wq[i]));
	}

#ifdef CONFIG_REALTEK_RPC_KCPU
		for (i = 0; i < (RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR; i++)
#else
		for (i = 0; i < RPC_NR_KERN_DEVS/RPC_NR_PAIR; i++)
#endif
		{
			sema_init(&send_kernel_rpc_sem[i], 1);
		}

	is_init = 1;
	rpc_kern_is_paused = 0;

	return result;
}

int rpc_kern_pause(void)
{
	rpc_kern_is_paused = 1;

	return 0;
}

int rpc_kern_run(void)
{
	int i;
	RPC_KERN_Dev * rpc_dev = (RPC_KERN_Dev *)phys_to_virt(RPC_KERN_RECORD_ADDR);
	for (i = 0; i < RPC_NR_KERN_DEVS; i++)
	{
		if(!(ring_empty((RPC_COMMON_Dev *)(&rpc_dev[i]))))
		{
			printk(KERN_NOTICE "rpc_kern_device(%d) not empty:%d\n",
				i,get_ring_data_size(rpc_dev[i].ringStart,rpc_dev[i].ringEnd,rpc_dev[i].ringIn, rpc_dev[i].ringOut));
			peek_rpc_struct(__func__, (RPC_COMMON_Dev *)(&rpc_dev[i]));
		}
	}
	rpc_kern_is_paused = 0;
	return 0;
}

ssize_t rpc_kern_read(int opt, char *buf, size_t count)
{
    RPC_KERN_Dev *dev;
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;

	//down(&kernel_rpc_read_sem);
#ifdef CONFIG_REALTEK_RPC_KCPU
    	if ((opt == RPC_AUDIO) || (opt == RPC_VIDEO)
#ifdef CONFIG_REALTEK_RPC_VCPU2
         || (opt == RPC_VIDEO2)
#endif
         )
    		dev = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
	else
		dev = &rpc_kern_kcpu_devices[1];
#else
    	dev = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
#endif
	//up(&kernel_rpc_read_sem);
    PDEBUG("read rpc_kern_device: %x \n", (unsigned int)dev);
    if (down_interruptible(&dev->ptrSync->readSem))
        return -ERESTARTSYS;

    if (dev->ringIn == dev->ringOut)
        goto out;   // the ring is empty...
    else if (dev->ringIn > dev->ringOut)
        size = dev->ringIn - dev->ringOut;
    else
        size = RPC_RING_SIZE + dev->ringIn - dev->ringOut;

	if (count > size){
		ret = 0;
		goto out;
		//count = size;
	}

	temp = dev->ringEnd - dev->ringOut;
	if (temp >= count) {
		if (my_copy_user((int *)buf, (int *)dev->ringOut, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += count;
		ptmp = dev->ringOut + ((count+3) & 0xfffffffc);
		if (ptmp == dev->ringEnd)
			dev->ringOut = dev->ringStart;
		else
			dev->ringOut = ptmp;

    	PDEBUG("RPC Read is in 1st kind...\n");
	} else {
		if (my_copy_user((int *)buf, (int *)dev->ringOut, temp)) {
        	ret = -EFAULT;
			goto out;
		}
		count -= temp;

		if (my_copy_user((int *)(buf+temp), (int *)dev->ringStart, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += (temp + count);
		dev->ringOut = dev->ringStart+((count+3) & 0xfffffffc);

    	PDEBUG("RPC Read is in 2nd kind...\n");
	}
out:
    PDEBUG("RPC kern ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
    up(&dev->ptrSync->readSem);
    return ret;
}

ssize_t rpc_kern_write(int opt, const char *buf, size_t count)
{
    RPC_KERN_Dev *dev;
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;

	//down(&kernel_rpc_read_sem);
#ifdef CONFIG_REALTEK_RPC_KCPU
    	if ((opt == RPC_AUDIO) || (opt == RPC_VIDEO) 
#ifdef CONFIG_REALTEK_RPC_VCPU2
         || (opt == RPC_VIDEO2)
#endif
         )
    		dev = &rpc_kern_devices[opt*RPC_NR_PAIR];
	else
		dev = &rpc_kern_kcpu_devices[0];
#else
    	dev = &rpc_kern_devices[opt*RPC_NR_PAIR];
#endif
    PDEBUG("write rpc_kern_device: %x \n", (unsigned int)dev);
    PDEBUG("[rpc_kern_write] write rpc_kern_device: caller%x, *buf:0x%x \n", (unsigned int) __read_32bit_caller_register(), *(unsigned int *)buf);
    if (down_interruptible(&dev->ptrSync->writeSem))
        return -ERESTARTSYS;

    if (dev->ringIn == dev->ringOut)
        size = 0;   // the ring is empty
    else if (dev->ringIn > dev->ringOut)
        size = dev->ringIn - dev->ringOut;
    else
        size = RPC_RING_SIZE + dev->ringIn - dev->ringOut;

	if (count > (RPC_RING_SIZE - size - 1))
		goto out;

	temp = dev->ringEnd - dev->ringIn;
	if (temp >= count) {
		if (my_copy_user((int *)dev->ringIn, (int *)buf, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += count;
		ptmp = dev->ringIn + ((count+3) & 0xfffffffc);

		//modify by Angus
        dsb(sy);

		if (ptmp == dev->ringEnd)
			dev->ringIn = dev->ringStart;
		else
			dev->ringIn = ptmp;

    	PDEBUG("RPC Write is in 1st kind...\n");
	} else {
		if (my_copy_user((int *)dev->ringIn, (int *)buf, temp)) {
        	ret = -EFAULT;
			goto out;
		}
		count -= temp;

		if (my_copy_user((int *)dev->ringStart, (int *)(buf+temp), count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += (temp + count);

		//modify by Angus
        dsb(sy);

		dev->ringIn = dev->ringStart+((count+3) & 0xfffffffc);

    	PDEBUG("RPC Write is in 2nd kind...\n");
	}

	if (opt == RPC_AUDIO)
		//writel((RPC_INT_SA | RPC_INT_WRITE_1), (void *)REG_SB2_CPU_INT);        // audio
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SA | RPC_INT_WRITE_1));
	else if (opt == RPC_VIDEO)
		//writel((RPC_INT_SV | RPC_INT_WRITE_1), (void *)REG_SB2_CPU_INT);        // video
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV | RPC_INT_WRITE_1));
#ifdef CONFIG_REALTEK_RPC_VCPU2
	else if (opt == RPC_VIDEO2)
		//writel((RPC_INT_SK | RPC_INT_WRITE_1), (void *)REG_SB2_CPU_INT);        // video2
		//BUG();
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV2 | RPC_INT_WRITE_1));
#endif
#ifdef CONFIG_REALTEK_RPC_KCPU
	else if (opt == RPC_KCPU)
		//writel((RPC_INT_SK | RPC_INT_WRITE_1), (void *)REG_SB2_CPU_INT);        // kcpu
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SK | RPC_INT_WRITE_1));
#endif
	else
		pr_err("error device number...\n");

out:
    PDEBUG("RPC kern ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
    up(&dev->ptrSync->writeSem);
    return ret;
}

int register_kernel_rpc(unsigned long command, FUNC_PTR ptr)
{
	int error;
	printk(KERN_ALERT "%s %d  preempt_count()=%d\n",__func__,__LINE__,preempt_count());
	down(&kernel_rpc_sem);
	error = radix_tree_preload(GFP_KERNEL);
	if (error == 0) {
		error = radix_tree_insert(&kernel_rpc_tree, command, (void *)ptr);
		if (error)
			pr_err("RPC: register kernel rpc %ld error...\n", command);
		radix_tree_preload_end();
	}
	up(&kernel_rpc_sem);

	return error;
}

unsigned long handle_command(unsigned long command, unsigned long param1, unsigned long param2)
{
	FUNC_PTR ptr;
	int ret = 0;

	//pr_err("Handle command %lx, param1: %lx, param2: %lx, time:%lu...\n", command, param1, param2, jiffies);
	down(&kernel_rpc_sem);
	ptr = radix_tree_lookup(&kernel_rpc_tree, command);
	up(&kernel_rpc_sem);
	if (ptr)
		ret = ptr(param1, param2);
	else
		pr_err("RPC: lookup kernel rpc %ld error...\n", command);

	//pr_err("Finish Handle command: %lx, time:%lu... \n", command, jiffies);
	return ret;
}

#ifdef CONFIG_DEBUG_KERNEL_RPC
static void dump_trash_kernel_rpc_buffer(int opt)
{
	RPC_KERN_Dev *devread;
	char *out;
	char readbuf[512];
	unsigned long *tmp;
	int i = 0, j=0, size;

#ifdef CONFIG_REALTEK_RPC_KCPU
	if ((opt == RPC_AUDIO) || (opt == RPC_VIDEO)
#ifdef CONFIG_REALTEK_RPC_VCPU2
		|| (opt == RPC_VIDEO2)
#endif
		)
		devread = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
	else
		devread = &rpc_kern_kcpu_devices[1];
#else
	devread = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
#endif

	pr_err("kernel rpc -->dump trash buffer\n");
	pr_err("previous read buffer:\n");
	for(j=0; j<DEBUG_KERNEL_RPC_MAX_LEN; j++ )
	{
		pr_err("\n ringIn :0x%8lx,  ringOut:0x%8lx,  programId: %lu, versionID: %lu, command: %lx, para1: %lx, time:%lu \n",debug_kernel_rpc[opt][j].ringIn,debug_kernel_rpc[opt][j].ringOut,
		debug_kernel_rpc[opt][j].programID, debug_kernel_rpc[opt][j].versionID, debug_kernel_rpc[opt][j].command, debug_kernel_rpc[opt][j].para1, debug_kernel_rpc[opt][j].timestamp);
	}

	pr_err("Current read buffer remaining data: ringIn 0x%8x, ringOut: 0x%8x \n", (int)devread->ringIn, (int)devread->ringOut);

	size = get_ring_data_size(devread->ringStart, devread->ringEnd, devread->ringIn, devread->ringOut);
	out = get_ring_data("kern_read_buffer", (RPC_COMMON_Dev*)devread, devread ->ringOut, readbuf, size);
	tmp = (unsigned long *)readbuf;

        if(out != NULL){
		for (j=0; j<size; j++) {
			if (j%16 == 0) {
				pr_err("\n");
			}
			pr_err("%x ",ntohl(*(tmp+i)));
			i++;
		}

        }

}
#endif

static int rpc_kernel_thread(void *p)
{
	char readbuf[sizeof(RPC_STRUCT)+3*sizeof(unsigned long)];
	RPC_KERN_Dev *dev;
	RPC_STRUCT *rpc;
	unsigned long *tmp;
	int i=0, f = ((int)p/RPC_NR_PAIR);
	unsigned long previousprint = 0;

//	daemonize(current->comm);
	if (f == RPC_VIDEO) {
		struct sched_param param = { .sched_priority = 1 };
		struct cpumask rpc_cpumask;

		sched_setscheduler_nocheck(current, SCHED_FIFO, &param);
		cpumask_clear(&rpc_cpumask);
		cpumask_set_cpu(1, &rpc_cpumask); // run task in core 1
		sched_setaffinity(0, &rpc_cpumask);
	}

#ifdef CONFIG_REALTEK_RPC_KCPU
	if ((int)p >= RPC_NR_KERN_DEVS)
		dev = &rpc_kern_kcpu_devices[(int)p-RPC_NR_KERN_DEVS];
	else
#endif
	dev = &rpc_kern_devices[(int)p];
	while (1) {
//		if (current->flags & PF_FREEZE)
//			refrigerator(PF_FREEZE);
		try_to_freeze();

//		printk(" #@# wait %s %x %x \n", current->comm, dev, dev->waitQueue);
		//if (wait_event_interruptible(dev->ptrSync->waitQueue, (kthread_should_stop()) | (dev->ringIn != dev->ringOut))) {
		if (wait_event_interruptible_timeout(dev->ptrSync->waitQueue, (kthread_should_stop()) | (dev->ringIn != dev->ringOut), HZ)<0) {
			pr_err("%s got signal or should stop...\n", current->comm);
			continue;
		}
#ifdef CONFIG_DEBUG_KERNEL_RPC
		record_thread_timeout[f] = jiffies;
#endif
//		printk(" #@# wakeup %s \n", current->comm);

		if (kthread_should_stop()) {
			pr_err("%s exit...\n", current->comm);
			break;
		}

		if(dev->ringIn == dev->ringOut)
			continue;

#ifdef CONFIG_DEBUG_KERNEL_RPC
		//record buffer information
		for(i = 0; i< (DEBUG_KERNEL_RPC_MAX_LEN-1) ; i++){
			debug_kernel_rpc[f][i].ringIn = debug_kernel_rpc[f][i+1].ringIn;
			debug_kernel_rpc[f][i].ringOut = debug_kernel_rpc[f][i+1].ringOut;
 			debug_kernel_rpc[f][i].timestamp = debug_kernel_rpc[f][i+1].timestamp;
			debug_kernel_rpc[f][i].programID = debug_kernel_rpc[f][i+1].programID;
			debug_kernel_rpc[f][i].versionID= debug_kernel_rpc[f][i+1].versionID;
			debug_kernel_rpc[f][i].command = debug_kernel_rpc[f][i+1].command;
			debug_kernel_rpc[f][i].para1= debug_kernel_rpc[f][i+1].para1;

		}
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].ringIn = (int)dev->ringIn;
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].ringOut = (int)dev ->ringOut;
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].timestamp = jiffies;

		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].programID = 0; //have not get this message
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].versionID = 0;
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].command = 0;
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].para1 =0;
#endif

		// read the reply data...
		if (rpc_kern_read(((int)p)/RPC_NR_PAIR, readbuf, sizeof(RPC_STRUCT)) != sizeof(RPC_STRUCT)) {
			if(time_after(jiffies, previousprint)){
				pr_err("ERROR in read kernel RPC struct in %s ...\n", current->comm);
				previousprint = jiffies+HZ;
			}
			continue;
		}

		rpc = (RPC_STRUCT *)readbuf;
		tmp = (unsigned long *)(readbuf+sizeof(RPC_STRUCT));

#ifdef CONFIG_DEBUG_KERNEL_RPC
		//update programID & versionID
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].programID = htonl(rpc->programID);
		debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].versionID = htonl(rpc->versionID);
#endif

		if ((htonl(rpc->programID) == R_PROGRAM) || (htonl(rpc->programID) == AUDIO_AGENT)
			||(htonl(rpc->programID) == VIDEO_AGENT) || (htonl(rpc->programID)== KERNELID)) //RPC data
		{
			// handle the request...
			char replybuf[sizeof(RPC_STRUCT)+2*sizeof(unsigned long)];
			unsigned long ret;
			RPC_STRUCT *rrpc = (RPC_STRUCT *)replybuf;
			int count = 0;

			// read the payload...
			while ((rpc_kern_read(((int)p)/RPC_NR_PAIR, readbuf+sizeof(RPC_STRUCT), 3*sizeof(unsigned long))
					!= 3*sizeof(unsigned long)) && (count<LOOPCOUNT)) {/*loop 500 ms*/
				//pr_err("ERROR in read para payload in %s...\n", current->comm);
				count ++;
				msleep(10);
				//continue;
			}

			if(count == LOOPCOUNT){
				pr_err("ERROR in read para payload in %s...\n", current->comm);
				//drop data
				if (down_interruptible(&dev->ptrSync->readSem))
        				return -ERESTARTSYS;
				dev->ringOut = dev->ringIn;
				up(&dev->ptrSync->readSem);
				if(rpc->taskID)  //block mode, send reply
				{
					// fill the RPC_STRUCT...
					rrpc->programID = htonl(REPLYID);
					rrpc->versionID = htonl(REPLYID);
					rrpc->procedureID = 0;
					rrpc->taskID = 0;
#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS
					rrpc->sysPID = 0;
#endif
					rrpc->parameterSize = htonl(2*sizeof(unsigned long));
					rrpc->mycontext = rpc->mycontext;

					// fill the parameters...
					tmp = (unsigned long *)(replybuf+sizeof(RPC_STRUCT));
					*(tmp+0) = rpc->taskID;
					*(tmp+1) = htonl(0);


					if (rpc_kern_write(((int)p)/RPC_NR_PAIR, replybuf, sizeof(replybuf)) != sizeof(replybuf)) {
						pr_err("ERROR in send ack from kernel to %s ...\n", current->comm);
						return RPC_FAIL;
					}
				}
				else{
					pr_notice("kernel RPC: discard RPC data from %s ...\n", current->comm);

				}
				pr_err("kernel rpc payload: program:%u version:%u procedure:%u taskID:%u sysPID:%x size:%u context:%x",
					htonl(rpc->programID), htonl(rpc->versionID), htonl(rpc->procedureID), htonl(rpc->taskID), htonl(rpc->sysPID), htonl(rpc->parameterSize), htonl(rpc->mycontext));
				continue;
			}

#ifdef CONFIG_DEBUG_KERNEL_RPC
			krpc_time_before_handle_command[f] = jiffies;
			krpc_handle_command_id[f] = ntohl(*tmp);
			krpc_handle_command_count[f] ++;
#endif
			ret = handle_command(ntohl(*tmp), ntohl(*(tmp+1)), ntohl(*(tmp+2)));
#ifdef CONFIG_DEBUG_KERNEL_RPC
			krpc_time_after_handle_command[f] = jiffies;
			krpc_handle_command_count[f]--;
			debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].command = ntohl(*tmp);
			debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].para1 =ntohl(*(tmp+1));
#endif
			if(rpc->taskID)	//for blocking mode RPC request
			{
			// fill the RPC_STRUCT...
			rrpc->programID = htonl(REPLYID);
			rrpc->versionID = htonl(REPLYID);
			rrpc->procedureID = 0;
			rrpc->taskID = 0;
#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS
			rrpc->sysPID = 0;
#endif
			rrpc->parameterSize = htonl(2*sizeof(unsigned long));
			rrpc->mycontext = rpc->mycontext;

			// fill the parameters...
			tmp = (unsigned long *)(replybuf+sizeof(RPC_STRUCT));
			*(tmp+0) = rpc->taskID;
			*(tmp+1) = htonl(ret);

			if (rpc_kern_write(((int)p)/RPC_NR_PAIR, replybuf, sizeof(replybuf)) != sizeof(replybuf)) {
				pr_err("ERROR in send ack from kernel to %s ...\n", current->comm);
				return RPC_FAIL;
			}
			}
		}
		else if((htonl(rpc->programID)== REPLYID) && (htonl(rpc->versionID) == REPLYID)) {	// reply data
			KRPC_INFO *info;
			int countack =0;
			// read the payload...
			while ((rpc_kern_read(((int)p)/RPC_NR_PAIR, readbuf+sizeof(RPC_STRUCT), 2*sizeof(unsigned long))
					!= 2*sizeof(unsigned long))&&(countack < LOOPCOUNT)) {
				//pr_err("ERROR in read reply payload in %s...\n", current->comm);
				countack++;
				msleep(10);
				//continue;
			}

			if(countack == LOOPCOUNT){
				pr_err("ERROR in read reply payload in %s...\n", current->comm);
				//pr_notice("kernel RPC: ack data not correct from %s...\n", current->comm);
				//drop the data
				if (down_interruptible(&dev->ptrSync->readSem))
        				return -ERESTARTSYS;
				dev->ringOut = dev->ringIn;
				up(&dev->ptrSync->readSem);
				pr_err("kernel rpc ack: program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx",
					rpc->programID, rpc->versionID, rpc->procedureID, rpc->taskID, rpc->sysPID, rpc->parameterSize, rpc->mycontext);
				continue;
			}

			// parse the reply data...
			*((unsigned long *)ntohl(rpc->mycontext)) = ntohl(*(tmp+1));
			info = (KRPC_INFO *)ntohl(*tmp);
			 info->reply = 1;
			wake_up(info->wq); // ack the sync...

#ifdef CONFIG_DEBUG_KERNEL_RPC
			debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].command = ntohl(*tmp);
			debug_kernel_rpc[f][DEBUG_KERNEL_RPC_MAX_LEN-1].para1 =ntohl(*(tmp+1));
#endif
		}
		else{
			pr_err("ERROR kernel rpc:%s send a RPC with error programID : %u to kernel...\n",rpc_kthread_name[((int)p)/RPC_NR_PAIR], htonl(rpc->programID));
#ifdef CONFIG_DEBUG_KERNEL_RPC
			dump_trash_kernel_rpc_buffer(((int)p)/RPC_NR_PAIR);
#endif
		}
	}

	return 0;
}

#if defined(CONFIG_REALTEK_VDEC) || defined(CONFIG_RTK_KDRV_VDEC)
extern void rtkvdec_show_sharedmemory(void) ;
#endif

#ifdef CONFIG_DEBUG_KERNEL_RPC
void dump_kernel_rpc_data(int opt)
{
	RPC_KERN_Dev *devread, *devwrite;
	int j=0;

	pr_err("current time: %lu, send time: %lu, record_isr_time: %lu , wake_up_time: %lu, user_wake_up_time: %lu, enter thread time:%lu \n", jiffies,
		record_send_time[opt], record_isr_time[opt], record_isr_wake_up_time[opt], record_isr_user_wake_up_time[opt], record_thread_timeout[opt]);
	pr_err("last time rpc thread handle rpc command (%lu) --> enter time: %lu, out time: %lu, count : %lu\n", krpc_handle_command_id[opt], krpc_time_before_handle_command[opt],
		krpc_time_after_handle_command[opt], krpc_handle_command_count[opt]);
#ifdef CONFIG_REALTEK_RPC_KCPU
	if ((opt == RPC_AUDIO) || (opt == RPC_VIDEO) 
#ifdef CONFIG_REALTEK_RPC_VCPU2
		|| (opt == RPC_VIDEO2)
#endif
		)
		devread = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
	else
		devread = &rpc_kern_kcpu_devices[1];
#else
	devread = &rpc_kern_devices[opt*RPC_NR_PAIR+1];
#endif
	pr_err("kernel rpc timeout! current read buffer status ringIn: 0x%8x, ringOut:0x%8x\n", (int)devread->ringIn, (int)devread->ringOut);
	if(devread->ringIn != devread->ringOut){
		pr_err("Please check RPC !!!\n");
		peek_rpc_struct("kern_read_buffer", (RPC_COMMON_Dev *)devread);
	}
#ifdef CONFIG_REALTEK_RPC_KCPU
	if ((opt == RPC_AUDIO) || (opt == RPC_VIDEO)
#ifdef CONFIG_REALTEK_RPC_VCPU2
		|| (opt == RPC_VIDEO2)
#endif
		)
		devwrite = &rpc_kern_devices[opt*RPC_NR_PAIR];
	else
		devwrite = &rpc_kern_kcpu_devices[0];
#else
	devwrite = &rpc_kern_devices[opt*RPC_NR_PAIR];
#endif
	pr_err("kernel rpc timeout! current write buffer status ringIn: 0x%8x, ringOut:0x%8x\n", (int)devwrite->ringIn, (int)devwrite->ringOut);
	if(devwrite->ringIn != devwrite->ringOut){
		pr_err("Please check Audio or Video !!!\n");
		peek_rpc_struct("kern_write_buffer", (RPC_COMMON_Dev *)devwrite);
	}

	if(opt == RPC_VIDEO)
		pr_err("kernel rpc timeout! current %s dummy register info:0x%08x, current dummy register info:0x%08x\n", rpc_kthread_name[opt], rpc_video_dummy_record,(unsigned int)rtd_inl(KERNEL_RPC_DUMMY_REGISTER));

	pr_err("previous read buffer:\n");
	for(j=0; j<DEBUG_KERNEL_RPC_MAX_LEN; j++ )
	{
		pr_err("\n ringIn :0x%8lx,  ringOut:0x%8lx,  programId: %lu, versionID: %lu, command: %lx, para1: %lx,time:%lu \n",debug_kernel_rpc[opt][j].ringIn,debug_kernel_rpc[opt][j].ringOut,
			debug_kernel_rpc[opt][j].programID, debug_kernel_rpc[opt][j].versionID, debug_kernel_rpc[opt][j].command, debug_kernel_rpc[opt][j].para1, debug_kernel_rpc[opt][j].timestamp);
		//pr_err("the %d ==>ringIn :0x%8x,  ringOut:0x%8x \n",debug_kernel_rpc[opt][j].ringIn,debug_kernel_rpc[opt][j].ringOut);
	}

#if defined(CONFIG_REALTEK_VDEC) || defined(CONFIG_RTK_KDRV_VDEC)
	rtkvdec_show_sharedmemory();
#endif

	if(opt == RPC_AUDIO)
		rtd_outl(DUMP_AUDIO_BUFFER_DUMMY_REGISTER, 0xC0DE0002);

	/*pr_err("\n register status: \n");
	while(i< DEBUG_KERNEL_RPC_MAX_TIME){
		pr_err("dummy register info: 0x%08x \n", (unsigned int)rtd_inl(KERNEL_RPC_DUMMY_REGISTER));
		pr_err("a/v fw kick watchdog, dummy_register_2: 0x%08x, dummy_register_3: 0x%08x \n", (unsigned int)rtd_inl(SB2_DUMMY_2_reg),(unsigned int)rtd_inl(SB2_DUMMY_3_reg));
		//clear register;
		rtd_outl(SB2_DUMMY_2_reg, 0x00000000);
		rtd_outl(SB2_DUMMY_3_reg, 0x00000000);
		rtd_maskl(KERNEL_RPC_DUMMY_REGISTER, 0xe1ffffff, 0x00000000);

		//sleep
		msleep(100);
		i++;
	}*/

}
#else
void dump_kernel_rpc_data(int opt)
{
	return;
}
#endif


//int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue)
int send_krpc(int opt,
    KRPC_PROCEDUREID procedureID,
    KRPC_SENDMODE send_mode,
    unsigned long command,
    unsigned long param1,
    unsigned long param2,
    unsigned long *retvalue)
{
	char sendbuf[sizeof(RPC_STRUCT)+3*sizeof(unsigned long)];
	RPC_STRUCT *rpc = (RPC_STRUCT *)sendbuf;
	KRPC_INFO info;
	unsigned long *tmp;

	if (rpc_kern_is_paused) {
		pr_err("RPCkern: someone access rpc kern during the pause...\n");
		BUG();
		return RPC_FAIL;
	}

	down(&send_kernel_rpc_sem[opt]);
	if (rpc_kthread[opt] == 0) {
		pr_err("RPCkern: %s is disabled...\n", rpc_kthread_name[opt]);
#ifdef CONFIG_DEBUG_KERNEL_RPC
		if(time_after(jiffies, (print_time[opt]+5*HZ))){
			dump_kernel_rpc_data(opt);

#if defined(CONFIG_REALTEK_VDEC) || defined(CONFIG_RTK_KDRV_VDEC)
		if ( opt == RPC_VIDEO)
			rtkvdec_show_sharedmemory();
#endif
		}
#endif
		up(&send_kernel_rpc_sem[opt]);
		return RPC_FAIL;
	}

	if( opt >= RPC_MAX)
	{
		pr_err("BUG!!! NO this CPU (command:%lx)...\n",command);
		up(&send_kernel_rpc_sem[opt]);
		return RPC_FAIL;
	}

	if( opt == RPC_VIDEO)
	{
		//invalidate sync flag before read
		dmac_flush_range(phys_to_virt(0x000000d4), phys_to_virt(0x000000d8));
		outer_inv_range(0x000000d4,0x000000d8);

		// Make sure VCPU should init RPC ready before send RPC
		// VCPU should set sync flag value not same with 0xFFFFFFFF after init RPC ready.
		if(*((int *)phys_to_virt(0x000000d4)) == (0xffffffff))
		{
			pr_err("RPCkern: VCPU not finished init RPC ...\n");
			up(&send_kernel_rpc_sem[opt]);
			return RPC_VCPU_NOT_READY;
		}
	}

#ifdef CONFIG_REALTEK_RPC_VCPU2
	if( opt == RPC_VIDEO2)
	{
		//invalidate sync flag before read
		dmac_flush_range(phys_to_virt(0x000000d8), phys_to_virt(0x000000dc));
		outer_inv_range(0x000000d8,0x000000dc);

		// Make sure VCPU2 should init RPC ready before send RPC
		// VCPU2 should set sync flag value not same with 0xFFFFFFFF after init RPC ready.
		if(*((int *)phys_to_virt(0x000000d8)) == (0xffffffff))
		{
			pr_err("RPCkern: VCPU2 not finished init RPC (command:%lx)...\n", command);
			up(&send_kernel_rpc_sem[opt]);
			return RPC_VCPU_NOT_READY;
		}
	}
#endif


//	printk(" #@# sendbuf: %d \n", sizeof(sendbuf));
	info.wq = &rpc_wq[opt];
	info.reply = 0;
	// fill the RPC_STRUCT...
	rpc->programID = htonl(KERNELID);
	rpc->versionID = htonl(KERNELID);
	rpc->procedureID = htonl(procedureID);
	//rpc->taskID = htonl((unsigned long)&info);
	rpc->taskID = (send_mode & KRPC_BLOCK_MODE) ? htonl((unsigned long)&info) : 0 ;
#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS
	rpc->sysPID = 0;
#endif
	rpc->parameterSize = htonl(3*sizeof(unsigned long));
	rpc->mycontext = htonl((unsigned long)retvalue);

	// fill the parameters...
	tmp = (unsigned long *)(sendbuf+sizeof(RPC_STRUCT));
//	printk(" aaa: %x bbb: %x \n", sendbuf, tmp);
	*tmp = htonl(command);
	*(tmp+1) = htonl(param1);
	*(tmp+2) = htonl(param2);


	if (rpc_kern_write(opt, sendbuf, sizeof(sendbuf)) != sizeof(sendbuf)) {
		pr_err("ERROR in send kernel RPC to %s : command:%lx, parm1: %lx, parm2: %lx ...\n", rpc_kthread_name[opt],
			command, param1, param2);
		up(&send_kernel_rpc_sem[opt]);
		return RPC_FAIL;
	}

#ifdef CONFIG_DEBUG_KERNEL_RPC
	if(opt == RPC_VIDEO)
		rtd_maskl(KERNEL_RPC_DUMMY_REGISTER, 0x1e000007, 0x00000000);

	record_send_time[opt] = jiffies;
#endif

	if(send_mode & KRPC_BLOCK_MODE) //for block mode
   	{
       	// wait the result...
	       if (!wait_event_timeout(rpc_wq[opt], info.reply, TIMEOUT)) {
		pr_err("[krpc timeout v1.2]kernel rpc to %s wait ack timeout ->disable %s thread:  command:0x%lx, parm1: %lx, parm2: %lx ...\n", rpc_kthread_name[opt],
			rpc_kthread_name[opt], command, param1, param2);
#ifdef CONFIG_DEBUG_KERNEL_RPC
		if(opt == RPC_VIDEO)
			rpc_video_dummy_record = (unsigned int)rtd_inl(KERNEL_RPC_DUMMY_REGISTER);
		dump_kernel_rpc_data(opt);
#endif
		if(krpc_handle_command_count[opt] != 0 ){
			pr_err("Please check this rpc command (%lu): \n", krpc_handle_command_id[opt]);
			show_stack(rpc_kthread[opt], NULL);
		}
		kthread_stop(rpc_kthread[opt]);
		rpc_kthread[opt] = 0;
		up(&send_kernel_rpc_sem[opt]);
		if (debugMode == RELEASE_LEVEL)
			panic("RPC timeout in release mode!!! need micom reset \n");

		return RPC_FAIL;
	        } else {
	            // printk(" #@# ret: %d \n", *retvalue);
	            up(&send_kernel_rpc_sem[opt]);
	            return RPC_OK;
	        }
    	}
    	else
    	{
    		up(&send_kernel_rpc_sem[opt]);
       		return RPC_OK;
    	}
}

EXPORT_SYMBOL(send_krpc);

int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue)
{
#ifdef CONFIG_SCALER_BRING_UP
	return RPC_OK;
#endif

#ifdef CONFIG_SUPPORT_SCALER
	if(Scaler_GetRPCInitByVCPU() == true)/*VCPU RPC initialize fail.*/
		return RPC_FAIL;
	else
#endif
    	return send_krpc(opt, KRPC_PROCEDUREID_KERNEL,KRPC_BLOCK_MODE, command, param1, param2, retvalue);
}


EXPORT_SYMBOL(send_rpc_command);

