#ifndef _RPCDRIVER_H
#define _RPCDRIVER_H

#include <linux/semaphore.h>
#include <linux/slab.h>
#include <mach/io.h>

#define KERNEL2_6

#ifdef CONFIG_DEVFS_FS
#include <linux/devfs_fs_kernel.h>
#endif

#undef PDEBUG
#ifdef RPC_DEBUG
 #ifdef __KERNEL__
  #define PDEBUG(fmt, args...) printk(KERN_ALERT "RPC: " fmt, ## args)
 #else
  #define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
 #endif // __KERNEL__
#else
 #define PDEBUG(fmt, args...)	/* empty macro */
#endif // RPC_DEBUG

#define CONFIG_REALTEK_RPC_DEBUG
//#define CONFIG_DEBUG_USER_RPC
#ifdef CONFIG_REALTEK_RPC_DEBUG
extern int rpc_pr_dispatch;
extern int rpc_pr_dispatch_more;
extern int rpc_pr_read;
extern int rpc_pr_write;
extern int rpc_pr_type;
extern char rpc_pr_typename[8];

#define PDEBUGD(fmt, args...)       if (rpc_pr_dispatch >0) printk (KERN_ALERT "RPC: " fmt, ## args) /*dispatch*/
#define DISPDEBUG(fmt, args...)     if (rpc_pr_dispatch_more >0) printk (KERN_ALERT "RPC: " fmt, ## args) /*dispatch more info*/
#define PDEBUGR(fmt, args...)	    if (rpc_pr_read >0) printk (KERN_ALERT "RPC: " fmt, ## args) /*print read pointer*/
#define PDEBUGW(fmt, args...)       if (rpc_pr_write >0) printk (KERN_ALERT "RPC: " fmt, ## args) /*print write pointer*/
#else
#define PDEBUGD(fmt, args...)
#define DISPDEBUG(fmt, args...)
#define PDEBUGR(fmt, args...)
#define PDEBUGW(fmt, args...)
#endif
#define PDEBUG_LOG(fmt, args...) rpclog_printk(fmt, ## args)
extern int rpc_pr_pid_debug;
#define PID_DEBUG(fmt, args...)       if (rpc_pr_pid_debug >0) pr_emerg("wrpc:" fmt, ## args)
#define EMERG_DEBUG(fmt, args...)     pr_emerg("wrpc:" fmt, ## args)



#define REG_SB2_CPU_INT			0xb801a104
#define REG_SB2_CPU_INT_EN		0xb801a108

#define SYNC_FLAG_ACPU			0x000000d0
#define SYNC_FLAG_V1CPU 		0x000000d4
#define SYNC_FLAG_V2CPU 		0x000000d8

#define RPC_INT_WRITE_1	1

#define CONFIG_REALTEK_RPC_KCPU

#ifdef CONFIG_REALTEK_RPC_KCPU // for platform support KCPU case
#define RPC_INT_V2K	(1 << 20)
#define RPC_INT_VK	(1 << 19)
#define RPC_INT_AK	(1 << 18)
#define RPC_INT_SK	(1 << 17)
#define RPC_INT_KV2	(1 << 16)
#define RPC_INT_KV	(1 << 15)
#define RPC_INT_KA	(1 << 14)
#define RPC_INT_KS	(1 << 13)
#endif

#define RPC_INT_VS_EN	(1 << 7)
#define RPC_INT_VA_EN	(1 << 8)

#define RPC_INT_V2V	(1 << 12)
#define RPC_INT_V2A	(1 << 11)
#define RPC_INT_V2S	(1 << 10)
#define RPC_INT_VV2	(1 << 9)
#define RPC_INT_VS	(1 << 8)
#define RPC_INT_VA	(1 << 7)
#define RPC_INT_AV2	(1 << 6)
#define RPC_INT_AV	(1 << 5)
#define RPC_INT_AS	(1 << 4)
#define RPC_INT_SV2	(1 << 3)
#define RPC_INT_SV	(1 << 2)
#define RPC_INT_SA	(1 << 1)

#define __read_32bit_caller_register()      \
({ int __res;                               \
    __asm__ __volatile__(                   \
        "mov\t%0, lr\n\t"                   \
        : "=r" (__res));                    \
    __res;                                  \
})

#define CONFIG_REALTEK_RPC_MULTIPROCESS
#define CONFIG_REALTEK_RPC_PROGRAM_REGISTER
#define CONFIG_REALTEK_RPC_PROGRAM_RELEASE_NOTICE
#define CONFIG_DEBUG_KERNEL_RPC
#define DUMP_AUDIO_BUFFER_DUMMY_REGISTER 0xb8006070

#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <asm/current.h>

#define R_PROGRAM       98
#define AUDIO_AGENT     202
#define VIDEO_AGENT     300
#endif

#define KERNELID	98
#define REPLYID		99
#define RPC_AUDIO	0x0
#define RPC_VIDEO	0x1
#ifdef CONFIG_REALTEK_RPC_VCPU2
#define RPC_VIDEO2	0x2	//add by Angus
#define RPC_KCPU	0x3
#define RPC_MAX		0x4
#else
#define RPC_KCPU	0x2
#define RPC_MAX		0x3
#endif

#define RPC_OK		0
#define RPC_FAIL	-1
#define RPC_VCPU_NOT_READY	-2

#ifndef RPC_ID
#define RPC_ID 0x5566
#endif

#ifndef RPC_MAJOR
#define RPC_MAJOR 240		/* dynamic major by default */
#endif

typedef enum
{
	KRPC_PROCEDUREID_KERNEL = 0,
	KRPC_PROCEDUREID_ROS,
} KRPC_PROCEDUREID;

enum
{
    ENUM_KERNEL_RPC_SUSPEND = 0x401,
};

typedef enum
{
	KRPC_NON_BLOCK_MODE ,
    	KRPC_BLOCK_MODE ,
} KRPC_SENDMODE;

#ifndef RPC_NR_DEVS
//modify by Angus, 2 for S-A, 2 for A-S, 2 for S-V1, 2 for V1-S, 2 for S-V2, 2 for V2-S
typedef enum
{
	RPC_POLL_DEV_SA_ID0,
	RPC_POLL_DEV_AS_ID1,
	RPC_POLL_DEV_SV1_ID2,
	RPC_POLL_DEV_V1S_ID3,
	RPC_POLL_DEV_SV2_ID4,
	RPC_POLL_DEV_V2S_ID5,
	RPC_POLL_DEV_TOTAL
}NUM_POLL_DEV;

typedef enum
{
	RPC_INTR_DEV_SA_ID0,
	RPC_INTR_DEV_AS_ID1,
	RPC_INTR_DEV_SV1_ID2,
	RPC_INTR_DEV_V1S_ID3,
	RPC_INTR_DEV_SV2_ID4,
	RPC_INTR_DEV_V2S_ID5,
	RPC_INTR_DEV_TOTAL
}NUM_INTR_DEV;

#define RPC_NR_DEVS		(RPC_POLL_DEV_TOTAL + RPC_INTR_DEV_TOTAL)		/* total ring buffer number */

#endif

#ifndef RPC_NR_PAIR
#define RPC_NR_PAIR 2		/* for interrupt and polling mode */
#endif

#ifndef RPC_NR_KERN_DEVS
//modify by Angus, S-A,  A-S,  S-V1, V1-S,  S-V2,  V2-S

typedef enum
{
	RPC_KERN_DEV_SA_ID0,
	RPC_KERN_DEV_AS_ID1,
	RPC_KERN_DEV_SV1_ID2,
	RPC_KERN_DEV_V1S_ID3,
#ifdef CONFIG_REALTEK_RPC_VCPU2
	RPC_KERN_DEV_SV2_ID4,
	RPC_KERN_DEV_V2S_ID5,
#endif
	RPC_NR_KERN_DEVS 	/* total ring buffer number */
}NUM_KERN_DEV;

#endif

#ifndef RPC_RING_SIZE
#define RPC_RING_SIZE 2048	/* size of ring buffer */
#endif

#ifndef RPC_POLL_DEV_ADDR
#define RPC_POLL_DEV_ADDR 0x1b1f1000
#endif

#ifndef RPC_INTR_DEV_ADDR
#define RPC_INTR_DEV_ADDR (RPC_POLL_DEV_ADDR+RPC_RING_SIZE)
#endif

#ifndef RPC_KERN_DEV_ADDR
#define RPC_KERN_DEV_ADDR 0x1b1f9000
#endif

#ifndef RPC_RECORD_SIZE
#define RPC_RECORD_SIZE 64	/* size of ring buffer record */
#endif

#ifndef RPC_POLL_RECORD_ADDR
#define RPC_POLL_RECORD_ADDR 0x1b1ff000
#endif

#ifndef RPC_INTR_RECORD_ADDR
//#define RPC_INTR_RECORD_ADDR (RPC_POLL_RECORD_ADDR+RPC_RECORD_SIZE*(RPC_NR_DEVS/RPC_NR_PAIR))
#define RPC_INTR_RECORD_ADDR  0x1b1ff200
#endif

#ifndef RPC_KERN_RECORD_ADDR
#define RPC_KERN_RECORD_ADDR 0x1b1ff400
#endif


#ifdef CONFIG_REALTEK_RPC_KCPU
#define SYNC_FLAG_SCPU			0x00000800

#ifndef RPC_NR_KCPU_DEVS
//modify by Angus, 2 for S-K, 2 for K-S
typedef enum
{
	RPC_POLL_DEV_SK_ID0,
	RPC_POLL_DEV_KS_ID1,
	RPC_POLL_DEV_KCPU_TOTAL
}NUM_POLL_KCPU_DEV;

typedef enum
{
	RPC_INTR_DEV_SK_ID0,
	RPC_INTR_DEV_KS_ID1,
	RPC_INTR_DEV_KCPU_TOTAL
}NUM_INTR_KCPU_DEV;

#define RPC_NR_KCPU_DEVS	(RPC_POLL_DEV_KCPU_TOTAL + RPC_INTR_DEV_KCPU_TOTAL)	/* total ring buffer number */

#endif

#ifndef RPC_NR_KERN_KCPU_DEVS
//modify by Angus, K-A,  A-K,  K-V1, V1-K,  K-V2,  V2-K

typedef enum
{
	RPC_KERN_DEV_SK_ID0,
	RPC_KERN_DEV_KS_ID1,
	RPC_NR_KERN_KCPU_DEVS 	/* total ring buffer number */
}NUM_KERN_KCPU_DEV;

#endif

#ifndef RPC_KCPU_RING_SIZE
#define RPC_KCPU_RING_SIZE 2048	/* size of ring buffer */
#endif

#ifndef RPC_POLL_KCPU_DEV_ADDR
#define RPC_POLL_KCPU_DEV_ADDR 0x1b1e0000
#endif

#ifndef RPC_INTR_KCPU_DEV_ADDR
#define RPC_INTR_KCPU_DEV_ADDR (RPC_POLL_KCPU_DEV_ADDR+RPC_KCPU_RING_SIZE)
#endif

#ifndef RPC_KERN_KCPU_DEV_ADDR
#define RPC_KERN_KCPU_DEV_ADDR 0x1b1e2000
#endif

#ifndef RPC_POLL_KCPU_RECORD_ADDR
#define RPC_POLL_KCPU_RECORD_ADDR 0x1b1e3000
#endif

#ifndef RPC_INTR_KCPU_RECORD_ADDR
//#define RPC_INTR_KCPU_RECORD_ADDR (RPC_POLL_KCPU_RECORD_ADDR+RPC_RECORD_SIZE*(RPC_NR_KCPU_DEVS/RPC_NR_PAIR))
#define RPC_INTR_KCPU_RECORD_ADDR  0x1b1e3080
#endif

#ifndef RPC_KERN_KCPU_RECORD_ADDR
#define RPC_KERN_KCPU_RECORD_ADDR 0x1b1e3100
#endif

#endif

#define SB2_EMERGENCY_INT_BUFF_ADDR (RPC_KERN_RECORD_ADDR + RPC_NR_KERN_DEVS * RPC_RECORD_SIZE + 0x100)
#define SB2_EMERGENCY_INT_BUFF_COMMAND_SIZE    8 //command 4 bytes, parameter 4 bytes.
#define SB2_EMERGENCY_INT_TIMEOUT              4// 4sec

extern struct file_operations rpc_poll_fops;   /* for poll mode */
extern struct file_operations rpc_intr_fops;   /* for intr mode */
extern struct file_operations rpc_ctrl_fops;   /* for ctrl mode */
#ifdef CONFIG_REALTEK_RPC_DEBUG
extern struct file_operations rpc_debug_fops; /*for debug rpc mode*/
#endif
extern struct file_operations *rpc_fop_array[];

#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS
typedef struct RPC_STRUCT {
	unsigned long programID;      // program ID defined in IDL file
	unsigned long versionID;      // version ID defined in IDL file
	unsigned long procedureID;    // function ID defined in IDL file

	unsigned long taskID;         // the caller's task ID, assign 0 if NONBLOCK_MODE
	unsigned long sysPID;         // the callee's task ID
	unsigned long parameterSize;  // packet's body size
	unsigned long mycontext;      // return address of reply value
} RPC_STRUCT;

typedef struct REPLY_RPC_STRUCT {
	RPC_STRUCT rpc;
	unsigned int req_taskID;
	unsigned int replay_result;
} REPLY_RPC_STRUCT;
#endif

#ifdef CONFIG_REALTEK_RPC_DEBUG
typedef struct DEBUG_RECORD_RPC{
    RPC_STRUCT rpc;
    unsigned int  tcount;
    struct list_head        list;
}DEBUG_RECORD_RPC;

#define MAX_DEBUG_QUEUE 50
extern unsigned int user_rpc_queue_count;
#endif

typedef struct RPC_SYNC_Struct {
	wait_queue_head_t	waitQueue;	/* for blocking read */
	struct semaphore	readSem;	/* mutual exclusion semaphore */
	struct semaphore	writeSem;	/* mutual exclusion semaphore */
} RPC_SYNC_Struct;

/*
// read : nonblocking
// write: nonblocking
*/
typedef struct RPC_POLL_Dev {
	char			*ringBuf;	/* buffer for interrupt mode */
	char			*ringStart;	/* pointer to start of ring buffer */
	char			*ringEnd;	/* pointer to end   of ring buffer */
	char			*ringIn;	/* pointer to where next data will be inserted  in   the ring buffer */
	char			*ringOut;	/* pointer to where next data will be extracted from the ring buffer */

	RPC_SYNC_Struct		*ptrSync;
	unsigned long		dummy[7];
} RPC_POLL_Dev;

/*
// read : nonblocking blocking
// write: nonblocking
*/
typedef struct RPC_INTR_Dev {
	char			*ringBuf;	/* buffer for interrupt mode */
	char			*ringStart;	/* pointer to start of ring buffer */
	char			*ringEnd;	/* pointer to end   of ring buffer */
	char			*ringIn;	/* pointer to where next data will be inserted  in   the ring buffer */
	char			*ringOut;	/* pointer to where next data will be extracted from the ring buffer */

	RPC_SYNC_Struct		*ptrSync;
	unsigned long		dummy[7];
} RPC_INTR_Dev;

/*
// read : nonblocking blocking
// write: nonblocking
*/
typedef struct RPC_KERN_Dev {
	char			*ringBuf;	/* buffer for interrupt mode */
	char			*ringStart;	/* pointer to start of ring buffer */
	char			*ringEnd;	/* pointer to end   of ring buffer */
	char			*ringIn;	/* pointer to where next data will be inserted  in   the ring buffer */
	char			*ringOut;	/* pointer to where next data will be extracted from the ring buffer */

	RPC_SYNC_Struct		*ptrSync;
	unsigned long		dummy[7];
} RPC_KERN_Dev;

#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS

typedef struct RPC_COMMON_Dev {
	char                    *ringBuf;       /* buffer for interrupt mode */
	char                    *ringStart;     /* pointer to start of ring buffer */
	char                    *ringEnd;       /* pointer to end   of ring buffer */
	char                    *ringIn;        /* pointer to where next data will be inserted  in   the ring buffer */
	char                    *ringOut;       /* pointer to where next data will be extracted from the ring buffer */
} RPC_COMMON_Dev;

typedef struct RPC_DEV_EXTRA {
	RPC_COMMON_Dev          *dev;
	void                    *currProc;      /* current process which handles rpc command */
	char                    *name;          /* the rpc device name */
	struct list_head        tasks;          /* tasks that open this rpc device */
	struct tasklet_struct   tasklet;        /* schedule a tasklet for bottom half */
	char                    *nextRpc;       /* points to next Rpc */
	spinlock_t              lock;           /* lock to protect data synchronization */
#ifdef CONFIG_DEBUG_USER_RPC
	struct list_head    blockrpc_list;  /*record block that not receive ack*/
#endif
    int not_handle_count;
    int footprint;
} RPC_DEV_EXTRA;

//maintain a list of threads in the same process
typedef struct RPC_THREAD
{
	pid_t                   pid;
	struct list_head        list;
} RPC_THREAD;

//maintain a list of processes that use the same RPC device
typedef struct RPC_PROCESS
{
	pid_t                   pid;
	wait_queue_head_t       waitQueue;
	RPC_COMMON_Dev          *dev;
	RPC_DEV_EXTRA           *extra;
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
	struct list_head        handlers;
#endif
	struct list_head        threads;        /* pids that share the same file descriptor */
	struct list_head        list;
	int                     stop;
} RPC_PROCESS;

#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
//maintain a list of handlers
typedef struct RPC_HANDLER
{
	unsigned long           programID;
	struct list_head        list;
} RPC_HANDLER;
#endif

extern int pid_max;
extern RPC_DEV_EXTRA rpc_intr_extra[RPC_NR_DEVS/RPC_NR_PAIR];
#ifdef CONFIG_REALTEK_RPC_KCPU
extern RPC_DEV_EXTRA rpc_intr_kcpu_extra[RPC_NR_KCPU_DEVS/RPC_NR_PAIR];
#endif


#define NAMESPACE_NULL   1
void rpc_dispatch(unsigned long data);
int flush_sync_flag(void);

static inline int my_memcpy(int *des, int *src, int size)
{
	char *csrc, *cdes;
	int i;

	PDEBUG("%s dest:%p src:%p size:%d\n", __func__, des, src, size);
	if (((int)src & 0x3) || ((int)des & 0x3))
		pr_err("my_copy_user: unaligned happen...\n");

	while (size >= 4) {
		*des++ = *src++;
		size -= 4;
	}

	csrc = (char *)src;
	cdes = (char *)des;
	for (i = 0; i < size; i++)
		cdes[i] = csrc[i];

	return 0;
}

static inline int get_ring_data_size(char *start, char *end, char *in, char *out)
{
	int ringsize = end - start;
	int datasize = (ringsize + in - out) % ringsize;
	PDEBUG("%s ringsize:%d datasize:%d start:%p end:%p in:%p out:%p\n", __func__,
		ringsize, datasize, start, end, in, out);
	return datasize;
}

//get ring data in buf and return next data pointer
static inline char *get_ring_data(const char *func, RPC_COMMON_Dev *dev, char *out, char *buf, int datasize)
{
	int size = get_ring_data_size(dev->ringStart, dev->ringEnd, dev->ringIn, out);
	int tail = dev->ringEnd - out;

	if(size < datasize){
		EMERG_DEBUG("%s: Size not enough %d < %d\n", func, size, datasize);
		return NULL;
	}

	if(tail >= datasize){
		my_memcpy((int *)buf, (int *)out, datasize);
		out += datasize;
	}else{
		my_memcpy((int *)buf, (int *)out, tail);
		my_memcpy((int *)(buf + tail), (int *)dev->ringStart, datasize - tail);
		out = dev->ringStart + datasize - tail;
	}

	return out;
}

static inline void convert_rpc_struct(const char *func, RPC_STRUCT *rpc)
{
	rpc->programID = ntohl(rpc->programID);
	rpc->versionID = ntohl(rpc->versionID);
	rpc->procedureID = ntohl(rpc->procedureID);
	rpc->taskID = ntohl(rpc->taskID);
	rpc->sysPID = ntohl(rpc->sysPID);
	rpc->parameterSize = ntohl(rpc->parameterSize);
	rpc->mycontext = ntohl(rpc->mycontext);
}

static inline void show_rpc_struct(const char *func, RPC_STRUCT *rpc)
{
	printk(KERN_NOTICE "%s: program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx %s\n",
		func, rpc->programID, rpc->versionID, rpc->procedureID, rpc->taskID, rpc->sysPID, rpc->parameterSize,
		rpc->mycontext, in_atomic() ? "atomic" : "");
}

static inline void show_queued_rpc(RPC_DEV_EXTRA *extra, char *out)
{
	RPC_STRUCT rpc;
	out = get_ring_data(extra->name, extra->dev, out, (char *)&rpc, sizeof(RPC_STRUCT));
	if (out) {
		convert_rpc_struct(extra->name, &rpc);
		pr_err("%s-rpc(%p),program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx %s\n",
			extra->name, out, rpc.programID, rpc.versionID, rpc.procedureID, rpc.taskID, rpc.sysPID, rpc.parameterSize,
			rpc.mycontext, in_atomic() ? "atomic" : "");
	}
}


static inline void peek_rpc_struct(const char *func, RPC_COMMON_Dev *dev)
{
	RPC_STRUCT rpc;
	unsigned long pid;
	unsigned long arg;
	char *out = dev->ringOut;
	unsigned long command[3];

	out = get_ring_data(func, dev, out, (char *)&rpc, sizeof(RPC_STRUCT));
	if(out == NULL)
		return;
	convert_rpc_struct(func, &rpc);
	show_rpc_struct(func, &rpc);

	if(rpc.programID == AUDIO_AGENT && rpc.versionID == 0){
		//Parse more information here
	}else if(rpc.programID == VIDEO_AGENT && rpc.versionID == 0){
		//Parse more information here
	}else if(rpc.programID == R_PROGRAM && rpc.versionID == 0){
		out = get_ring_data(func, dev, out, (char *)&arg, sizeof(unsigned long));
		if(out == NULL)
			return;
		arg = ntohl(arg);
		if(rpc.procedureID == 1)
			pr_err("%s: alloc %lu bytes\n", func, arg);
		else
			pr_err("%s: free addr %lx\n", func, arg);
	}else if(rpc.programID == REPLYID && rpc.versionID == REPLYID){
		out = get_ring_data(func, dev, out, (char *)&pid, sizeof(unsigned long));
		if(out == NULL)
			return;
		pid = ntohl(pid);
		printk(KERN_NOTICE "%s: pid:%lu\n", func, pid);
	}else if(rpc.programID == KERNELID && rpc.versionID == KERNELID){
		//kernel rpc
		out = get_ring_data(func, dev, out, (char *)&command, 3*sizeof(unsigned long));
		if(out == NULL)
			return;
		command[0] = ntohl(command[0]);
		command[1] = ntohl(command[1]);
		command[2] = ntohl(command[2]);
		pr_err(KERN_NOTICE "%s: command:%lu, para1:%lu, para2: %lu\n", func, command[0], command[1],command[2]);

	}
}

static inline void update_currProc(RPC_DEV_EXTRA *extra, RPC_PROCESS *proc)
{
	extra->currProc = proc;
}

static inline void update_nextRpc(RPC_DEV_EXTRA *extra, char *nextRpc)
{
	int tmp = (int)nextRpc;
	tmp = ((tmp+3) & 0xfffffffc);
	if (tmp == (int)extra->dev->ringEnd)
		extra->nextRpc = extra->dev->ringStart;
	else
		extra->nextRpc = (char *)tmp;
}

static inline int rpc_done(RPC_DEV_EXTRA *extra)
{
	RPC_COMMON_Dev *dev = extra->dev;
	return dev->ringOut == extra->nextRpc;
}

static inline int ring_empty(RPC_COMMON_Dev *dev)
{
	return dev->ringOut == dev->ringIn;
}

static inline int need_dispatch(RPC_DEV_EXTRA *extra)
{
	//size is not zero and previous rpc is done
	return extra->currProc == NULL && !ring_empty(extra->dev) && rpc_done(extra);
}

static inline RPC_PROCESS *pick_one_proc(RPC_DEV_EXTRA *extra)
{
	RPC_PROCESS *proc = NULL;
	if(!list_empty(&extra->tasks)){
		proc = list_first_entry(&extra->tasks, RPC_PROCESS, list);
		DISPDEBUG("%s:%d Pick process:%d\n", extra->name, __LINE__, proc->pid);
	}else{
		DISPDEBUG("%s:%d No available process\n", extra->name, __LINE__);
	}
	return proc;
}

#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
static inline RPC_PROCESS *pick_supported_proc(RPC_DEV_EXTRA *extra, unsigned long programID,  unsigned long taskID, int state, int print)
{
	RPC_PROCESS *proc;
	RPC_HANDLER *handler;

    if (state == NAMESPACE_NULL) {
        pid_t pid = taskID;
        extra->footprint |= 0x80;

    	list_for_each_entry(proc, &extra->tasks, list){
            if (print) PID_DEBUG("%s:%d proc->pid:%d target-pid:%d\n", extra->name, __LINE__, proc->pid, pid);
    		if(proc->pid == pid)
    		{
                EMERG_DEBUG("%s:NAMESPACE_NULL found process:%d, taskID = %d\n", extra->name,pid,(int)taskID);
                extra->footprint |= 0x100;

    			return proc;
    		}
    		else
    		{
    			RPC_THREAD *thread;
    			list_for_each_entry(thread, &proc->threads, list){
                    if (print) PID_DEBUG("%s:%d thread->pid:%d target-pid:%d\n", extra->name, __LINE__, thread->pid, pid);
    				if(thread->pid == pid){
    					if (print) PID_DEBUG("%s:%d found thread:%d in process:%d\n", extra->name, __LINE__,pid, proc->pid);
                        extra->footprint |= 0x200;
    					return proc;
    				}
    			}
    		}
         }

    }
    extra->footprint |= 0x400;

	list_for_each_entry(proc, &extra->tasks, list){
		list_for_each_entry(handler, &proc->handlers, list){
			if(handler->programID == programID){
				if (print) PID_DEBUG("%s:%d pid:%d supports programID:%lu\n", __func__, __LINE__, proc->pid, programID);
                extra->footprint |= 0x800;

				return proc;
			}
		}
	}
    extra->footprint |= 0x1000;
	if (print) PID_DEBUG("%s:%d notfound process supports programID:%lu\n", __func__, __LINE__, programID);
	return NULL;
}
#endif

static inline int is_taskID_alive(unsigned long taskID)
{
	struct task_struct *task;
	int ret = 0;
	//sanity check
	if(unlikely(taskID > pid_max)){
		//printk("invalid taskID:%lu > pid_max:%d\n", taskID, pid_max);
		return -1;
	}

	if(unlikely(current == NULL || current->nsproxy == NULL /*|| current->nsproxy->pid_ns == NULL*/)){
		//printk("%s:%d strange happened current:%p nsproxy:%p\n", __func__, __LINE__, current, current->nsproxy);
		return -1;
	}

	rcu_read_lock();
	task = find_task_by_vpid(taskID);
	if(task == NULL){
		ret = 0;
	}
	else{
		ret = 1;
	}
	rcu_read_unlock();

	return ret;
}

static inline RPC_PROCESS *lookup_by_taskID(RPC_DEV_EXTRA *extra, unsigned long taskID, int *state, int print)
{
	pid_t pid;
	RPC_PROCESS *proc = NULL;
	struct task_struct *task;

	//sanity check
	if(unlikely(taskID > pid_max)){
		if (print) EMERG_DEBUG("%s:%d invalid taskID:%lu > pid_max:%d\n", extra->name, __LINE__, taskID, pid_max);
        extra->footprint |= 1;
		return NULL;
	}

	if(unlikely(current == NULL || current->nsproxy == NULL /*|| current->nsproxy->pid_ns == NULL*/)){
		if (print) EMERG_DEBUG("%s strange happened current:%p nsproxy:%p tgid:%d pid:%d taskID = %d\n", extra->name,current, current->nsproxy,current->tgid,current->pid, (int)taskID);
		//BUG();
        *state = NAMESPACE_NULL;
        extra->footprint |= 2;
		return NULL;
	}

	//find the tgid from task pid
	rcu_read_lock();
	task = find_task_by_vpid(taskID);
	if(task == NULL){
	        //rcu_read_unlock();
	        //return NULL;
	        pid = taskID; //taskID may be dead, use it directly
	        if (print) PID_DEBUG("%s:%d notfound by taskID:%lu\n", extra->name, __LINE__, taskID);
            extra->footprint |= 4;

	}else{
	        pid = task->tgid;
            if (print) PID_DEBUG("find_task_by_vpid(pid = %d, tgid = %d), taskID = %d\n", (int)task->pid, (int)task->tgid, (int)taskID);
            extra->footprint |= 8;
	}
	rcu_read_unlock();

	list_for_each_entry(proc, &extra->tasks, list){
        if (print) PID_DEBUG("%s:%d proc->pid:%d target-pid:%d\n", extra->name, __LINE__, proc->pid, pid);
		if(proc->pid == pid)
		{
		    if (print) PID_DEBUG("%s:%d found process:%d\n", extra->name, __LINE__, pid);
            extra->footprint |= 0x10;
			return proc;
		}
		else
		{
			RPC_THREAD *thread;
			list_for_each_entry(thread, &proc->threads, list){
                if (print) PID_DEBUG("%s:%d thread->pid:%d target-pid:%d\n", extra->name, __LINE__, thread->pid, pid);
				if(thread->pid == pid){
					if (print) PID_DEBUG("%s:%d found thread:%d in process:%d\n", extra->name, __LINE__,pid, proc->pid);
                    extra->footprint |= 0x20;
					return proc;
				}
			}
            extra->footprint |= 0x40;
		}
	}
	return NULL;
}

static inline int update_thread_list(RPC_PROCESS *proc)
{
	RPC_THREAD *thread;

	//current is main thread
	if(current->tgid == proc->pid)
		return 0;

	list_for_each_entry(thread, &proc->threads, list){
		//current is already in thread list
		if(thread->pid == current->tgid)
			return 0;
	}

	//not found, so add new thread to list
	thread = kmalloc(sizeof(RPC_THREAD), GFP_KERNEL);
	if(thread == NULL){
		pr_err("%s: failed to allocate RPC_THREAD\n", __func__);
		return -ENOMEM;
	}
	PDEBUG("%s:%d add thread:%s,%d,%d to thread list of process:%d\n", __func__, __LINE__,
		current->comm, current->pid, current->tgid, proc->pid);
	thread->pid = current->tgid;
	list_add(&thread->list, &proc->threads);

	return 1;
}

#endif //CONFIG_REALTEK_RPC_MULTIPROCESS
#ifdef CONFIG_REALTEK_RPC_DEBUG
static inline int is_pr_type_match(const char *extraName)
{
	return (rpc_pr_type&&(!strncmp(rpc_pr_typename, extraName, strlen(rpc_pr_typename)))) ||(rpc_pr_type > 4);
}

#ifdef CONFIG_DEBUG_USER_RPC
static inline void record_block_rpc(unsigned long data, RPC_COMMON_Dev *dev)
{
    RPC_STRUCT rerpc;
    DEBUG_RECORD_RPC *rrpc;
    char *out = dev->ringOut;
    RPC_DEV_EXTRA *extra = (RPC_DEV_EXTRA *)data;
    int index;
    RPC_DEV_EXTRA           *rextra = NULL;

    out = get_ring_data(extra->name, dev, out, (char *)&rerpc, sizeof(RPC_STRUCT));
    if(out == NULL)
        return;
    convert_rpc_struct(extra->name, &rerpc);

    if((rerpc.taskID !=0)&&(user_rpc_queue_count < MAX_DEBUG_QUEUE)) //block rpc
    {
        rrpc = kmalloc(sizeof(DEBUG_RECORD_RPC), GFP_KERNEL);
        if(rrpc == NULL){
            pr_err("%s: failed to allocate DEBUG_RECORD_RPC\n", __func__);
            return;
        }
        rrpc->rpc.programID = rerpc.programID;
        rrpc->rpc.versionID = rerpc.versionID;
        rrpc->rpc.procedureID = rerpc.procedureID;
        rrpc->rpc.taskID = rerpc.taskID;
        rrpc->rpc.sysPID = rerpc.sysPID;
        rrpc->rpc.parameterSize = rerpc.parameterSize;
        rrpc->rpc.mycontext = rerpc.mycontext;
        rrpc->tcount = 0;

        if (strncmp(extra->name, "AudioIntrWrite", 14) == 0)
            index = 1;
        else if (strncmp(extra->name, "Video1IntrWrite", 14) == 0)
            index = 3;
        else if (strncmp(extra->name, "Video2IntrWrite", 14) == 0)
            index = 5;
        else if (strncmp(extra->name, "KCPUIntrWrite", 13) == 0)
            index = 7;
        else
            return;

#ifdef CONFIG_REALTEK_RPC_KCPU
        if (index >= RPC_INTR_DEV_TOTAL) {
            rextra = &rpc_intr_kcpu_extra[(index-RPC_INTR_DEV_TOTAL)];
        } else {
            rextra = &rpc_intr_extra[index];
        }
#else
        rextra = &rpc_intr_extra[index];
#endif
        if(rextra == NULL )
            return;

        //list add;
        tasklet_disable(&rextra->tasklet);
        spin_lock_bh(&rextra->lock);
        list_add(&rrpc->list, &rextra->blockrpc_list);
        user_rpc_queue_count ++;
        spin_unlock_bh(&rextra->lock);
        tasklet_enable(&rextra->tasklet);
    }

    return;
}

static inline void release_block_rpc(RPC_DEV_EXTRA *extra, unsigned long taskID)
{
    DEBUG_RECORD_RPC *rrpc, *tmprpc;

    list_for_each_entry_safe(rrpc, tmprpc, &extra->blockrpc_list, list){
        rrpc->tcount++;
        //printk("yan_wang debug the taskID == %d \n", taskID);
        if(rrpc->rpc.taskID == taskID){
            list_del(&rrpc->list);
            kfree(rrpc);
            user_rpc_queue_count --;
        }
    }
}
#endif
#endif
/*
 * Prototypes for shared functions
 */
int my_copy_to_user(int *des, int *src, int size);
int my_copy_from_user(int *des, int *src, int size);
int	my_copy_user(int *des, int *src, int size);

int     rpc_poll_init(void);
int     rpc_poll_pause(void);
int	rpc_poll_run(void);
void    rpc_poll_cleanup(void);
int     rpc_intr_init(void);
int     rpc_intr_pause(void);
int	rpc_intr_run(void);
void    rpc_intr_cleanup(void);

int     rpc_kern_init(void);
int     rpc_kern_pause(void);
int	rpc_kern_run(void);
ssize_t rpc_kern_read(int opt, char *buf, size_t count);
ssize_t rpc_kern_write(int opt, const char *buf, size_t count);

/*
 * Kernel RPC handler Command ID define
 */

/*For common API use 0x0 ~ 0xFF*/
#define RPC_DVR_MALLOC		0x1
#define RPC_DVR_FREE		0x2
#define RPC_SIO_INIT		0x3
#define RPC_MAIN_ONLINE_MEASURE_ERROR_ACK	0xd
#ifdef CONFIG_DUAL_CHANNEL
#define RPC_SUB_ONLINE_MEASURE_ERROR_ACK	0xe
#endif
/*For VCPU use 0x100 ~ 0x1FF*/
#define RPC_VCPU_ID_0x100_Test	0x100
#define RPC_VCPU_ID_0x101_VBI	0x101
#define RPC_VCPU_ID_0x102_rtkvdec_remote_malloc	0x102
#define RPC_VCPU_ID_0x103_rtkvdec_remote_free	0x103
#define RPC_VCPU_ID_0x106_rtkvdec_remote_malloc_specific	0x106
#define RPC_VCPU_ID_0x107_rtkvdec_remote_free_specific	0x107
#define RPC_VCPU_FREE_USER_MEM	0x108

//#define RPC_VCPU_ID_0x104_recieve_vidcuindex		0x104
//#define RPC_VCPU_ID_0x105_recieve_vivsyncinfo		0x105

#define RPC_VCPU_ID_0x110_VO_READY	    0x110
#define RPC_VCPU_ID_0x111_VO_NOSIGNAL	0x111

#define RPC_VCPU_ID_0x112_HDR_FRAMEINFO	0x112

#define RPC_VCPU_ID_0x114_VO_AVSYNC	0x114

#define RPCCMD_VIDEO_CREATE     	0x64
#define RPCCMD_VIDEO_SETDEBUGMEMORY     0x8c
#define VIDEO_RPC_ToAgent_Resource_Recovery 115  //SCPU->VCPU
#define RPC_VCPU_DEBUG_COMMAND 0x120  //SCPU->VCPU
#define RPC_VCPU_SET_DUMPES_MEMORY 0x121
#define RPC_VCPU_SET_SHARED_MEMORY 0x122
#define RPC_VCPU_ID_0x123_Resource_Recovery_Stop 0x123  //SCPU->VCPU
#define RPC_VCPU_ID_0x124_Resource_Recovery_Destory 0x124  //SCPU->VCPU
#define RPC_VCPU_ID_0x125_Resource_Recovery_Flush 0x125  //SCPU->VCPU
#define RPC_VCPU_ID_0x126_Resource_Recovery_Pause 0x126  //SCPU->VCPU
#define RPC_VCPU_ID_0x130_VGIP_ISR_VACT_START	0x130

#define RPC_MEMC_PS	0x131

/*For ACPU use 0x200 ~ 0x3FF*/
#define RPC_ACPU_RELEASE_NOTICE	0x200	// SCPU->ACPU
#define RPC_ACPU_IS_REMOTE_MALLOC_ENABLE	0x201	// SCPU->ACPU
#define RPC_ACPU_DEBUG_DUMP     0x202	// SCPU->ACPU
#define RPC_ACPU_DEBUG_COMMAND  0x203	// SCPU->ACPU

#define RPC_ACPU_REMOTE_MALLOC	0x300	// ACPU->SCPU
#define RPC_ACPU_REMOTE_FREE	0x301	// ACPU->SCPU
#define RPC_ACPU_FREE_USER_MEM	0x302	// ACPU->SCPU

/*For RTC driver use 0x410*/
#define RPC_SCPU_RTC_OPS_REQ		0x410
#define RPC_SCPU_DEBUG_COMMAND	0x420


#define RPC_SCPU_ID_0x500_teestub_resource_recovery   0x500   // SCPU->KCPU
#define RPC_KCPU_ID_0x501_teeproxy_reeapp_freemomery  0x501   // KCPU->SCPU
#define RPC_SCPU_ID_0x502_teestub_debug_command       0x502   // SCPU->KCPU
#define RPC_KCPU_ID_0x503_teeproxy_notify_teemgr_pid  0x503   // KCPU->SCPU
#define RPC_SCPU_ID_0x504_teestub_get_teemgr_pid      0x504   // SCPU->KCPU

typedef unsigned long (*FUNC_PTR)(unsigned long, unsigned long);
int register_kernel_rpc(unsigned long command, FUNC_PTR ptr);
int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue);
int send_krpc(int opt,KRPC_PROCEDUREID procedureID,KRPC_SENDMODE send_mode,unsigned long command, unsigned long param1,unsigned long param2,unsigned long *retvalue);
int rpclog_printk(const char *fmt, ...);

extern RPC_POLL_Dev *rpc_poll_devices;
extern RPC_INTR_Dev *rpc_intr_devices;
extern RPC_KERN_Dev *rpc_kern_devices;
#ifdef CONFIG_REALTEK_RPC_KCPU
extern RPC_INTR_Dev *rpc_intr_kcpu_devices;
extern RPC_KERN_Dev *rpc_kern_kcpu_devices;
#endif
#ifdef CONFIG_DEBUG_KERNEL_RPC
#ifdef CONFIG_REALTEK_RPC_KCPU
extern unsigned long record_isr_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
extern unsigned long record_isr_wake_up_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
extern unsigned long record_isr_user_wake_up_time[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
#else
extern unsigned long record_isr_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
extern unsigned long record_isr_wake_up_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
extern unsigned long record_isr_user_wake_up_time[RPC_NR_KERN_DEVS/RPC_NR_PAIR];
#endif
#endif

/* Use 'k' as magic number */
#define RPC_IOC_MAGIC  'k'

/*
 * S means "Set"		: through a ptr,
 * T means "Tell"		: directly with the argument value
 * G means "Get"		: reply by setting through a pointer
 * Q means "Query"		: response is on the return value
 * X means "eXchange"	: G and S atomically
 * H means "sHift"		: T and Q atomically
 */
#define RPC_IOCTTIMEOUT _IO(RPC_IOC_MAGIC,  0)
#define RPC_IOCQTIMEOUT _IO(RPC_IOC_MAGIC,  1)
#define RPC_IOCTRESET _IO(RPC_IOC_MAGIC,  2)
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
#define RPC_IOCTHANDLER _IO(RPC_IOC_MAGIC, 3)
#define RPC_IOSTOP      _IO(RPC_IOC_MAGIC, 4)
#endif

#endif
