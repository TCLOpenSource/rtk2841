#include <linux/init.h>
#include <linux/swap.h>
#include <linux/file.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/blkdev.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/mmzone.h>
#include <linux/auth.h>
#include <linux/rtkblueprint.h>
#include <linux/rtkrecord.h>
#include <linux/pageremap.h>

#if defined(CONFIG_REALTEK_RPC)
#include <mach/RPCDriver.h>
#endif
#if defined(CONFIG_RTK_KDRV_RPC)
#include <rtk_kdriver/RPCDriver.h>
#endif
MODULE_LICENSE("Dual BSD/GPL");
static struct class	*auth_class;
struct device		*auth_dev;
#ifdef CONFIG_HIGHMEM
extern unsigned long	cma_highmem_start;
extern unsigned long	cma_highmem_size;
#endif

const char		*dvr_auth = "Realtek DVR";

extern unsigned long get_memc_start_address(void);
extern int get_memc_size(void);
extern unsigned long get_scaler_mdomain_start_address(void);
extern int get_scaler_mdomain_size(void);
extern unsigned long get_scaler_od_start_address(void);
extern int get_scaler_od_size(void);

#ifdef CONFIG_CMA_RTK_ALLOCATOR
#include <linux/rtkrecord.h>
#include <linux/rtkblueprint.h>
#include <linux/pageremap.h>
#include <linux/auth.h>

void *dma_get_allocator(struct device *dev);
#endif

#ifdef	CONFIG_REALTEK_SCHED_LOG
#include <mach/system.h>
#include <mach/timex.h>

unsigned int		*sched_log_buf_head = NULL;
unsigned int		*sched_log_buf_tail = NULL;
unsigned int		*sched_log_buf_ptr = NULL;
unsigned int		sched_log_flag = 0;
unsigned int		sched_log_start_time = 0;
unsigned int        sched_log_from_kernel=0;
DEFINE_SPINLOCK(sched_log_lock);

void log_event(int cpu, int event)
{
	unsigned int count = 0;
	unsigned long flags;

	if (!(sched_log_flag & 0x1))
		return;

	count = log_get_time_stamp();
	spin_lock_irqsave(&sched_log_lock, flags);

	*sched_log_buf_ptr = count;
	if (++sched_log_buf_ptr == sched_log_buf_tail) {
		sched_log_buf_ptr = sched_log_buf_head;
		sched_log_flag |= 2;
	}

	*sched_log_buf_ptr = 0x20000000 | (cpu << 24) | event;
	if (++sched_log_buf_ptr == sched_log_buf_tail) {
		sched_log_buf_ptr = sched_log_buf_head;
		sched_log_flag |= 2;
	}

	spin_unlock_irqrestore(&sched_log_lock, flags); 
}

#endif // CONFIG_REALTEK_SCHED_LOG

#ifdef	CONFIG_REALTEK_SCHED_LOG
	typedef struct {
		int	name;
		int	code;
#ifdef CONFIG_SMP
		int	cpu_id;
#endif
	} sched_record_struct;


//trigger log if buffer located
void auth_sched_log_start(void)
{
	if(sched_log_buf_head) {
		printk("sched log start:%x\n",(unsigned int)sched_log_buf_head);
		sched_log_buf_ptr = sched_log_buf_head;
		sched_log_start_time = timer_get_value(SYSTEM_TIMER); // tmp use the hw timer as the time_stamp
		sched_log_flag = 1;
	}
}

static int isInRecord_smp_opt(int pid, sched_record_struct *record, int num, int cpu_id)
{
	int i;

	for (i = 0; i < num; i++) {
		if (record[i].name == pid && record[i].cpu_id == cpu_id)
			return i;
	}

	return -1;
}
static int gOUT_CPU_ID = 0;

static char *getAppName(int pid)
{
	static struct task_struct *task;

	rcu_read_lock();
	task = pid_task(find_vpid(pid), PIDTYPE_PID);
	rcu_read_unlock();
	printk("task:%s\n",task->comm);
	return task->comm;
}

#define intr_record_number	(128*2)
#define sched_record_number	(400*4)
#define event_record_number	(40*4)
static void createLogFile_smp_opt(const char *filename, unsigned int addr, unsigned int wrap)
{
	const char 	date[] = "$date\n Jan 1, 1900 0:00:00\n$end\n\n";
	const char 	version[] = "$version\n System Performance Graph\n$end\n\n";
	const char	time[] = "$timescale\n 1000 ns\n$end\n\n";
	const char	scope[] = "$scope module SP%d $end\n";
	const char	upscope[] = "$upscope $end\n";
	const char	enddef[] = "$enddefinitions  $end\n\n";
	const char	dumpvar[] = "$dumpvars\n";
	int		index, isout;
	unsigned int	*ptr;
    mm_segment_t old_fs;	
//#define FAST_WRITE	
#ifdef FAST_WRITE	
#define FAST_WRITE_SIZE  (1024*1024)
#define FAST_THRESHOLD_LEN (FAST_WRITE_SIZE - 100)

	char		*write_buffer=NULL;
	unsigned int write_len=0;
#else
	char		buffer[100];
#endif	
	unsigned int 	last = 0;
	long long	curr = 0;
	int		prev_task[8] = {-1};
	int		pid, code = 0, cpu_id, cpu_cnt = NR_CPUS;
	int		intr_num = 0;
	int		sched_num = 0;
	int		event_num = 0;
	sched_record_struct *intr_record=(sched_record_struct *)dvr_malloc(intr_record_number*sizeof(sched_record_struct));
	sched_record_struct *sched_record=(sched_record_struct *)dvr_malloc(sched_record_number*sizeof(sched_record_struct));
	sched_record_struct *event_record=(sched_record_struct *)dvr_malloc(event_record_number*sizeof(sched_record_struct));	
	struct file *sched_log_file = NULL; //rtd log file fd
	loff_t pos = 0;

#ifdef FAST_WRITE
	write_buffer=(char *)dvr_malloc(FAST_WRITE_SIZE);
	if(write_buffer==NULL)
		goto createfail_return;
	memset(write_buffer,0,FAST_WRITE_SIZE);
#endif
	if(intr_record==NULL || sched_record==NULL || event_record==NULL)
		goto createfail_return;

	memset(intr_record,0,intr_record_number*sizeof(sched_record_struct));
	memset(sched_record,0,sched_record_number*sizeof(sched_record_struct));
	memset(event_record,0,event_record_number*sizeof(sched_record_struct));	
	
	if (!cpu_cnt)
		cpu_cnt = 1;
	if (wrap)
		ptr = (unsigned int *)addr;
	else
		ptr = (unsigned int *)sched_log_buf_head;

//	printk("logging buffer: %x %x %x %x %d\n",addr,ptr,sched_log_buf_head,sched_log_buf_tail,wrap);
	// parse the file first...
	do {
		ptr++;
		if (ptr == (unsigned int *)sched_log_buf_tail)
			ptr = (unsigned int *)sched_log_buf_head;
		//printk("logging buffer: %x %x %x %x %d\n",addr,ptr,sched_log_buf_head,sched_log_buf_tail,wrap);

		cpu_id = (*ptr & 0x0f000000) >> 24;

		if (*ptr & 0xc0000000) {
			// case sched
			pid = *ptr & 0x00ffffff;
			if (isInRecord_smp_opt(pid, sched_record, sched_num, cpu_id) < 0) {
				sched_record[sched_num].name = pid;
				sched_record[sched_num].code = code++;
				sched_record[sched_num].cpu_id = cpu_id;
//				printf("S: [%08x] %08x [%d] %03d\n", ptr, *ptr, sched_record[sched_num].code, pid);
				sched_num++;
				if (sched_num == sched_record_number) {
					printk("too many tasks...\n");
					goto createfail_return;
				}
			}
		}
		else if (*ptr & 0x20000000) {
			// case event
			pid = *ptr & 0x00ffffff;
			if (isInRecord_smp_opt(pid, event_record, event_num, cpu_id) < 0) {
				event_record[event_num].name = pid;
				event_record[event_num].code = code++;
				event_record[event_num].cpu_id = cpu_id;
//				printf("E: [%08x] %08x [%d] %03d\n", ptr, *ptr, event_record[event_num].code, pid);
				event_num++;
				if (event_num == event_record_number) {
					printk("too many events...\n");
					goto createfail_return;
				}
			}
		}
		else {
			// case intr
			pid = *ptr & 0x00ffffff;
			if (isInRecord_smp_opt(pid, intr_record, intr_num, cpu_id) < 0) {
				intr_record[intr_num].name = pid;
				intr_record[intr_num].code = code++;
				intr_record[intr_num].cpu_id = cpu_id;
//				printf("I: [%08x] %08x [%d] %03d\n", ptr, *ptr, intr_record[intr_num].code, pid);
				intr_num++;
				if (intr_num == intr_record_number) {
					printk("too many interrupts...\n");
					goto createfail_return;
				}
			}
		}

		ptr++;
		if (ptr == (unsigned int *)sched_log_buf_tail)
			ptr = (unsigned int *)sched_log_buf_head;
	} while (ptr != (unsigned int *)addr);
	printk("before file open\n");
    old_fs = get_fs();
    set_fs(KERNEL_DS);

	sched_log_file = filp_open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	printk("file open\n");

//	printf("writing log data...");
	if(!IS_ERR(sched_log_file))
	{
		printk("file 1st write\n");
		vfs_write(sched_log_file, date, strlen(date),&pos);
		vfs_write(sched_log_file, version, strlen(version),&pos);
		vfs_write(sched_log_file, time, strlen(time),&pos);
	}
	else
	{
		printk("[%s]line %d ERROR\n",__FUNCTION__,__LINE__);
		goto createfail_return;
	}

	cpu_id = 0;
	while (cpu_id < cpu_cnt) {
#ifdef FAST_WRITE		
		if(write_len>=FAST_THRESHOLD_LEN)
		{
			if(sched_log_file) 
				vfs_write(sched_log_file, write_buffer, write_len,&pos);
			write_len=0;
			memset(write_buffer,0,FAST_WRITE_SIZE);
		}
		write_len+=sprintf(&write_buffer[write_len], scope, cpu_id);
#else
		sprintf(buffer, scope, cpu_id);
		if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif		
		for (pid = 0; pid < intr_num; pid++) {
			if (intr_record[pid].cpu_id == cpu_id) {
#ifdef FAST_WRITE
				write_len+=sprintf(&write_buffer[write_len], "$var wire 1 %03d interrupt%d $end\n",
				intr_record[pid].code, intr_record[pid].name);
#else				
				sprintf(buffer, "$var wire 1 %03d interrupt%d $end\n",
					intr_record[pid].code, intr_record[pid].name);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
		}
		for (pid = 0; pid < sched_num; pid++) {
			if (sched_record[pid].cpu_id == cpu_id) {
#ifdef FAST_WRITE
				write_len+=sprintf(&write_buffer[write_len], "$var wire 1 %03d task[%06d]:%s $end\n",
									sched_record[pid].code, sched_record[pid].name, getAppName(sched_record[pid].name));
#else				
				sprintf(buffer, "$var wire 1 %03d task[%06d]:%s $end\n",
					sched_record[pid].code, sched_record[pid].name, getAppName(sched_record[pid].name));
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
		}
		for (pid = 0; pid < event_num; pid++) {
			if (event_record[pid].cpu_id == cpu_id) {
#ifdef FAST_WRITE
				write_len+=sprintf(&write_buffer[write_len], "$var wire 1 %03d event%d $end\n",
					event_record[pid].code, event_record[pid].name);
#else				
				sprintf(buffer, "$var wire 1 %03d event%d $end\n",
					event_record[pid].code, event_record[pid].name);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
		}
#ifdef FAST_WRITE		
		if(write_len) //flush write
		{
			if(sched_log_file) 
				vfs_write(sched_log_file, write_buffer, write_len,&pos);
			write_len=0;
			memset(write_buffer,0,FAST_WRITE_SIZE);
		}		
#endif		
		vfs_write(sched_log_file, upscope, strlen(upscope),&pos);
		cpu_id++;
	}
	vfs_write(sched_log_file, enddef, strlen(enddef),&pos);
	vfs_write(sched_log_file, dumpvar, strlen(dumpvar),&pos);
	for (pid = 0; pid < code; pid ++) {
#ifdef FAST_WRITE
		if(write_len>=FAST_THRESHOLD_LEN)
		{
			if(sched_log_file) 
				vfs_write(sched_log_file, write_buffer, write_len,&pos);
			write_len=0;
			memset(write_buffer,0,FAST_WRITE_SIZE);
		}
		write_len+=sprintf(&write_buffer[write_len], "0 %03d\n", pid);
#else
		sprintf(buffer, "0 %03d\n", pid);
		if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif		
	}

	if (wrap)
		ptr = (unsigned int *)addr;
	else
		ptr = (unsigned int *)sched_log_buf_head;

	// parse the file again...
	last = *ptr;
	do {
		if (*ptr >= last) {
			curr += (*ptr-last)/sched_log_time_scale;
			last = *ptr;
		} else {
			curr += (0xffffffff-last+*ptr)/sched_log_time_scale;
			last = *ptr;
		}
#ifdef FAST_WRITE
		if(write_len>=FAST_THRESHOLD_LEN)
		{
			if(sched_log_file) 
				vfs_write(sched_log_file, write_buffer, write_len,&pos);
			write_len=0;
			memset(write_buffer,0,FAST_WRITE_SIZE);
		}
		write_len+=sprintf(&write_buffer[write_len], "#%lld\n", curr);;
#else		
		sprintf(buffer, "#%lld\n", curr);
		if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif

		ptr++;
		if (ptr == (unsigned int *)sched_log_buf_tail)
			ptr = (unsigned int *)sched_log_buf_head;

		cpu_id = (*ptr & 0x0f000000) >> 24;
		if (cpu_id >= cpu_cnt)
			printk("error cpu id: %d \n", cpu_id);

		if (*ptr & 0xc0000000) {
			// case sched
			pid = *ptr & 0x00ffffff;
			index = isInRecord_smp_opt(pid, sched_record, sched_num, cpu_id);
			if (index < 0) {
				printk("sched_record error in record index...[%x]\n", *ptr);
				goto createfail_return;
			}

#ifdef FAST_WRITE
			if( gOUT_CPU_ID)
				write_len+=sprintf(&write_buffer[write_len], "1 %03d %d\n", sched_record[index].code, cpu_id);
			else
				write_len+=sprintf(&write_buffer[write_len], "1 %03d\n", sched_record[index].code);
#else
			if( gOUT_CPU_ID)
				sprintf(buffer, "1 %03d %d\n", sched_record[index].code, cpu_id);
			else
				sprintf(buffer, "1 %03d\n", sched_record[index].code);

			if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif			

			if (prev_task[cpu_id] >= 0 && prev_task[cpu_id] != sched_record[index].code ) {
#ifdef FAST_WRITE
			if( gOUT_CPU_ID)
				write_len+=sprintf(&write_buffer[write_len], "0 %03d %d\n", prev_task[cpu_id], cpu_id);
			else
				write_len+=sprintf(&write_buffer[write_len], "0 %03d\n", prev_task[cpu_id]);
#else				
				if(gOUT_CPU_ID)
					sprintf(buffer, "0 %03d %d\n", prev_task[cpu_id], cpu_id);
				else
					sprintf(buffer, "0 %03d\n", prev_task[cpu_id]);

				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
			prev_task[cpu_id] = sched_record[index].code;
		}
		else if (*ptr & 0x20000000) {
			// case event
			pid = *ptr & 0x00ffffff;
			index = isInRecord_smp_opt(pid, event_record, event_num, cpu_id);
			if (index < 0) {
				printk("event_record error in record index...[%x]\n", *ptr);
				goto createfail_return;
			}
			if(gOUT_CPU_ID) {
#ifdef FAST_WRITE
				write_len+=sprintf(&write_buffer[write_len], "1 %03d %d\n", event_record[index].code,cpu_id);
				write_len+=sprintf(&write_buffer[write_len], "0 %03d %d\n", event_record[index].code,cpu_id);
#else
				sprintf(buffer, "1 %03d %d\n", event_record[index].code,cpu_id);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
				sprintf(buffer, "0 %03d %d\n", event_record[index].code,cpu_id);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
			else {
#ifdef FAST_WRITE
				write_len+=sprintf(&write_buffer[write_len], "1 %03d\n", event_record[index].code);
				write_len+=sprintf(&write_buffer[write_len], "0 %03d\n", event_record[index].code);
#else				
				sprintf(buffer, "1 %03d\n", event_record[index].code);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
				sprintf(buffer, "0 %03d\n", event_record[index].code);
				if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif				
			}
		}
		else {
			// case intr
			pid = *ptr & 0x00ffffff;
			isout = (*ptr & 0x10000000) >> 28;
			index = isInRecord_smp_opt(pid, intr_record, intr_num, cpu_id);
			if (index < 0) {
				printk("intr_record error in record index...[%x]\n", *ptr);
				goto createfail_return;
			}
#ifdef FAST_WRITE			
			if(gOUT_CPU_ID)
				write_len+=sprintf(&write_buffer[write_len], "%d %03d %d\n", isout, intr_record[index].code, cpu_id);
			else
				write_len+=sprintf(&write_buffer[write_len], "%d %03d\n", isout, intr_record[index].code);

#else
			if(gOUT_CPU_ID)
				sprintf(buffer, "%d %03d %d\n", isout, intr_record[index].code, cpu_id);
			else
				sprintf(buffer, "%d %03d\n", isout, intr_record[index].code);

			if(sched_log_file) vfs_write(sched_log_file, buffer, strlen(buffer),&pos);
#endif			
		}

		ptr++;
		if (ptr == (unsigned int *)(sched_log_buf_tail))
			ptr = (unsigned int *)sched_log_buf_head;
	} while (ptr != (unsigned int *)addr);
#ifdef FAST_WRITE		
	if(write_len) //flush write
	{
		if(sched_log_file) 
			vfs_write(sched_log_file, write_buffer, write_len,&pos);
		write_len=0;
	}		
#endif

//	printf("done\n");
createfail_return:
	if(!IS_ERR(sched_log_file))
	{
		set_fs(old_fs);
		filp_close(sched_log_file,NULL);
		printk("file closed\n");
	}
	if(intr_record)
		dvr_free(intr_record);
	if(sched_record)
		dvr_free(sched_record);
	if(event_record)
		dvr_free(event_record);
#ifdef FAST_WRITE	
	if(write_buffer)
		dvr_free(write_buffer);
	write_buffer=NULL;
#endif	
	intr_record=NULL;
	sched_record=NULL;
	event_record=NULL;
	sched_log_file=NULL;
	
}

//stop and save log in filename position, if file name is null
//save it in /tmp/usb/sda/sda1 if it exist, otherwise save none
static void auth_sched_log_stop(char *filename)
{
 	if (!(sched_log_flag & 0x1))
		return;
	sched_log_flag &= ~0x1;
	/* start to write file*/
	
	createLogFile_smp_opt(filename,(unsigned int)sched_log_buf_ptr,sched_log_flag&0x02);
#if 0
	while(1) {
		cur_ptr = (unsigned long)sched_log_buf_ptr;
		offset = cur_ptr - (unsigned long)sched_log_buf_head;
	
		if (offset % 0x8 == 0) // prevent cpu2 is still log
			break;
	}
	log_struct.addr = offset;
	log_struct.size = sched_log_flag;
	ret = copy_to_user((void *)arg, &log_struct, sizeof(log_struct));
#endif

}

//Alloc buffer size
void auth_sched_log_init(int size)
{
	int sched_log_size=0;
	if(size==0)
	{
		sched_log_size=1024*1024*6; //6M
	}
	else
		sched_log_size=size;

	sched_log_buf_head = (unsigned int *)dvr_malloc(sched_log_size);
	if(sched_log_buf_head) {
		sched_log_buf_tail = (unsigned int *)((unsigned char *)sched_log_buf_head + sched_log_size);
		sched_log_buf_ptr = sched_log_buf_head;
		sched_log_start_time=0;
		sched_log_flag = 0;		
		sched_log_from_kernel=1;
		printk("sched log mem inited:%x\n",(unsigned int)sched_log_buf_head);
	}

}

void auth_sched_log_free(char *filename)
{
	if(sched_log_buf_head)
	{
		if(filename!=NULL)
			auth_sched_log_stop(filename);
		dvr_free(sched_log_buf_head);
		sched_log_buf_tail=0;
		sched_log_buf_ptr=0;
		sched_log_from_kernel=0;		
	}
}
#endif // CONFIG_REALTEK_SCHED_LOG

ssize_t auth_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

ssize_t auth_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	return 0;
}

static int do_auth(const char *str)
{
	AUTH_STR buf;
	int i = 0;

	if (copy_from_user(buf, str, sizeof(AUTH_STR)))
		return 0;

	while (1) {
		if (dvr_auth[i] == buf[i]) {
			if (dvr_auth[i] == 0)
				return 1;
		} else
			return 0;
		i++;
	}
}

long auth_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct mm_struct *mm = current->mm;
	int ret = 0;

#ifdef	CONFIG_REALTEK_SCHED_LOG
	struct task_struct *task;
	sched_log_struct log_struct;
#endif // CONFIG_REALTEK_SCHED_LOG

	switch (cmd) {
		case AUTH_IOCQ_MAP:
		{
			unsigned long map_addr;
			unsigned long errno = 0;

			if (!do_auth((const char *)arg))
				return ret;

			pr_info("auth: memory count: %d\n", mm->map_count);
			map_addr = DEF_MAP_ADDR;
			while (map_addr <= MAX_MAP_ADDR) {
				errno = rtktlb_mmap(map_addr);
				if (errno & 0x80000000)
					pr_info("auth: rtktlb_mmap error code %d...\n", (int)-errno);
				else {
					map_addr = errno;
					pr_info("auth: memory address 0x%x...\n", (int)map_addr);
					break;
				}
				map_addr += 0x8000000;
			}
			pr_info("auth: memory count: %d\n", mm->map_count);

			if (errno & 0x80000000)
				return ret;		// return with error
			else {
				int bitmap_size = BITS_TO_LONGS(DEF_MEM_SIZE / PAGE_SIZE) * sizeof(long);

				mem_map_info *map = kmalloc(sizeof(mem_map_info), GFP_KERNEL);
				BUG_ON(!map);
				map->addr = map_addr;
				map->bitmap = kzalloc(bitmap_size, GFP_KERNEL);
				BUG_ON(!map->bitmap);
				filp->private_data = (void *)map;
				return map_addr;	// return normally
			}

			break;
		}

		case AUTH_IOCQ_ALLOC:
		{
			mem_alloc_struct alloc;
			ret = copy_from_user(&alloc, (void *)arg, sizeof(mem_alloc_struct));
			ret = (int)pli_malloc_mesg(alloc.size, alloc.flag, alloc.str);
			if (ret == INVALID_VAL)
				ret = 0;
			else
				ret = pli_map_memory(filp, ret, alloc.size);
			return ret;
		}

		case AUTH_IOCQ_FREE:
		{
			unsigned long pfn;

			pfn = pli_unmap_memory(filp, arg);
			pli_free_mesg(pfn << PAGE_SHIFT);
			break;
		}

#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
		case AUTH_IOCQ_ALLOC_OVERLAPPED:
		{
			ret = alloc_overlapped_memory(arg);
			break;
		}

		case AUTH_IOCQ_FREE_OVERLAPPED:
		{
			free_overlapped_memory(arg);
			break;
		}
#endif

		case AUTH_IOCQ_FREEALL:
		{
			free_all_rtk_memory_allocation(remap_free_mem);
			break;
		}

		case AUTH_IOCQ_LISTALL:
		{
			list_all_rtk_memory_allocation_sort(list_mem_generic,NULL,NULL);
			break;
		}

		case AUTH_IOCQ_ALLOCAV:
		{
			mem_alloc_struct alloc;
			ret = copy_from_user(&alloc, (void *)arg, sizeof(mem_alloc_struct));
			ret = (int)pli_malloc_mesg(alloc.size, alloc.flag, alloc.str);
			if (ret == INVALID_VAL) {
				ret = 0;
			} else {
				struct page *page = pfn_to_page(ret >> PAGE_SHIFT);
				void *ptr = NULL;

				if (PageHighMem(page)) {
					pr_err("auth: AV cpu should not allocate highmem...\n");
					pli_free_mesg(ret);
					return 0;
				}
				ptr = page_address(page);
				dmac_flush_range((void *)ptr, (void *)(ptr+alloc.size));
				outer_flush_range(ret, ret+alloc.size);
			}
			return ret;
		}

		case AUTH_IOCQ_FREEAV:
		{
			pli_free_mesg(arg);
			break;
		}

		case AUTH_IOCS_FLUSHVIRT:
		{
			mem_region_struct region;
			struct vm_area_struct *vm_area;
			unsigned long pfn, phys_addr;

			ret = copy_from_user(&region, (void *)arg, sizeof(mem_region_struct));
			if (!ret) {
				vm_area = find_vma(current->mm, region.addr);
				if (!vm_area || follow_pfn(vm_area, region.addr, &pfn)) {
					pr_err("auth: virt addr %lx is not allocated by pli...\n", region.addr);
					return -EINVAL;
				}
				phys_addr = (pfn << PAGE_SHIFT) + (region.addr & (PAGE_SIZE - 1));
//				if (!rtk_record_lookup(phys_addr, NULL)) {
//					pr_err("auth: phys addr %lx is not allocated by pli...\n", phys_addr);
//					return -EINVAL;
//				}
				dmac_flush_range((void *)region.addr, (void *)(region.addr+region.size));
				outer_flush_range(phys_addr, phys_addr+region.size);
			}
			break;
		}

		case AUTH_IOCQ_DCUSIZE:
		{
			ret = get_memory_size(arg);
			break;
		}

		case AUTH_IOCQ_MEMC_START_ADDRESS:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_MEMC_START_ADDRESS\n");
			ret = get_memc_start_address();
			pr_info("ret = 0x%x\n", ret);
			break;
		}

		case AUTH_IOCQ_MEMC_SIZE:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_MEMC_SIZE\n");
			ret = get_memc_size();
			pr_info("ret = %d\n", ret);
			break;
		}

		case AUTH_IOCQ_MDOMAIN_START_ADDRESS:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_MEMC_START_ADDRESS\n");
			ret = get_scaler_mdomain_start_address();
			pr_info("ret = 0x%x\n", ret);
			break;
		}

		case AUTH_IOCQ_MDOMAIN_SIZE:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_MEMC_SIZE\n");
			ret = get_scaler_mdomain_size();
			pr_info("ret = %d\n", ret);
			break;
		}

		case AUTH_IOCQ_OD_START_ADDRESS:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_OD_START_ADDRESS\n");
			ret = get_scaler_od_start_address();
			pr_info("ret = 0x%x\n", ret);
			break;
		}

		case AUTH_IOCQ_OD_SIZE:
		{
			pr_info("[CARVED_OUT]case AUTH_IOCQ_OD_SIZE\n");
			ret = get_scaler_od_size();
			pr_info("ret = %d\n", ret);
			break;
		}

#ifdef	CONFIG_REALTEK_SCHED_LOG
		case AUTH_IOCSINITLOGBUF:
		{
			struct vm_area_struct *vm_area;
			unsigned long pfn, phys_addr;

			ret = copy_from_user(&log_struct, (void *)arg, sizeof(log_struct));
			if (!ret) {
				vm_area = find_vma(current->mm, log_struct.addr);
				BUG_ON(follow_pfn(vm_area, log_struct.addr, &pfn));
				phys_addr = pfn << PAGE_SHIFT;
//				printk("phys_addr: %lx\n", phys_addr);

				sched_log_buf_head = (unsigned int *)dvr_remap_cached_memory(phys_addr, log_struct.size, __builtin_return_address(0));
				sched_log_buf_tail = (unsigned int *)((unsigned char *)sched_log_buf_head + log_struct.size);
				sched_log_buf_ptr = sched_log_buf_head;
				pr_info("LOG head: %x, tail: %x, ptr: %x...\n", (int)sched_log_buf_head, (int)sched_log_buf_tail, (int)sched_log_buf_ptr);
				sched_log_flag = 0;
				ret = sched_log_time_scale;
			}
			break;
		}

		case AUTH_IOCTFREELOGBUF:
		{
			dvr_unmap_memory(sched_log_buf_head, sched_log_buf_tail - sched_log_buf_head);

			sched_log_buf_head = NULL;
			sched_log_buf_tail = NULL;
			sched_log_buf_ptr = NULL;
			sched_log_flag = 0;
			break;
		}

		case AUTH_IOCTLOGSTART:
		{
			sched_log_buf_ptr = sched_log_buf_head;
			sched_log_start_time = timer_get_value(SYSTEM_TIMER); // tmp use the hw timer as the time_stamp
			sched_log_flag = 1;
			break;
		}

		case AUTH_IOCGLOGSTOP:
		{
			unsigned long offset;
			unsigned long cur_ptr;

			if (!(sched_log_flag & 0x1))
				break;
			sched_log_flag &= ~0x1;

			while(1) {
				cur_ptr = (unsigned long)sched_log_buf_ptr;
				offset = cur_ptr - (unsigned long)sched_log_buf_head;

				if (offset % 0x8 == 0) // prevent cpu2 is still log
					break;
			}
			log_struct.addr = offset;
			log_struct.size = sched_log_flag;
			ret = copy_to_user((void *)arg, &log_struct, sizeof(log_struct));
			break;
		}

		case AUTH_IOCXLOGNAME:
		{
			get_user(ret, (int *)arg);
			rcu_read_lock();
			task = pid_task(find_vpid(ret), PIDTYPE_PID);
			rcu_read_unlock();
			if (task != NULL) {
				ret = copy_to_user((void *)arg, task->comm, TASK_COMM_LEN);
			} else {
				ret = copy_to_user((void *)arg, "NULL", 5);
			}
			break;
		}

		case AUTH_IOCSTHREADNAME:
		{
			ret = copy_from_user(current->comm, (void __user *)arg, TASK_COMM_LEN-1);
			current->comm[TASK_COMM_LEN-1] = '\0';
			WARN(ret, "Unable to get thread name @ 0x%08lx \n", arg+TASK_COMM_LEN-1-ret);
			break;
		}

		case AUTH_IOCTLOGEVENT:
		{
			int cpu = raw_smp_processor_id();

			if (!(sched_log_flag & 0x1))
				break;

//			pr_info("auth: logging event ***%lu*** \n", arg);
			log_event(cpu, arg);
			break;
		}
#endif // CONFIG_REALTEK_SCHED_LOG

	}

	return ret;
}

#ifdef CONFIG_COMPAT
long auth_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct mm_struct *mm = current->mm;
	int ret = 0;

#ifdef	CONFIG_REALTEK_SCHED_LOG
	struct task_struct *task;
	sched_log_struct log_struct;
#endif // CONFIG_REALTEK_SCHED_LOG

	switch (cmd) {
	case AUTH_IOCQ_MAP:
	{
		unsigned long map_addr;
		unsigned long errno = 0;

		if (!do_auth((const char *)arg))
			return ret;

		pr_info("auth: memory count: %d\n", mm->map_count);
		map_addr = DEF_MAP_ADDR;
		while (map_addr <= MAX_MAP_ADDR) {
			errno = rtktlb_mmap(map_addr);
			if (errno & 0x80000000)
				pr_info("auth: rtktlb_mmap error code %d...\n", (int)-errno);
			else {
				map_addr = errno;
				pr_info("auth: memory address 0x%x...\n", (int)map_addr);
				break;
			}
			map_addr += 0x8000000;
		}
		pr_info("auth: memory count: %d\n", mm->map_count);

		if (errno & 0x80000000)
			return ret;		// return with error
		else {
			int bitmap_size = BITS_TO_LONGS(DEF_MEM_SIZE / PAGE_SIZE) * sizeof(long);

			mem_map_info *map = kmalloc(sizeof(mem_map_info), GFP_KERNEL);
			BUG_ON(!map);
			map->addr = map_addr;
			map->bitmap = kzalloc(bitmap_size, GFP_KERNEL);
			BUG_ON(!map->bitmap);
			filp->private_data = (void *)map;
			return map_addr;	// return normally
		}

		break;
	}

	case COMPAT_AUTH_IOCQ_ALLOC:
	{
		compat_mem_alloc_struct __user *user_req = compat_ptr(arg);
		compat_mem_alloc_struct alloc;
		ret = copy_from_user(&alloc, user_req, sizeof(compat_mem_alloc_struct));
		ret = (int)pli_malloc_mesg(alloc.size, alloc.flag, alloc.str);
		if (ret == INVALID_VAL)
			ret = 0;
		else
			ret = pli_map_memory(filp, ret, alloc.size);
		return ret;
	}

	case AUTH_IOCQ_FREE:
	{
		unsigned long pfn;

		pfn = pli_unmap_memory(filp, arg);
		pli_free_mesg(pfn << PAGE_SHIFT);
		break;
	}

#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
	case AUTH_IOCQ_ALLOC_OVERLAPPED:
	{
		ret = alloc_overlapped_memory(arg);
		break;
	}

	case AUTH_IOCQ_FREE_OVERLAPPED:
	{
		free_overlapped_memory(arg);
		break;
	}
#endif

	case AUTH_IOCQ_FREEALL:
	{
		free_all_rtk_memory_allocation(remap_free_mem);
		break;
	}

	case AUTH_IOCQ_LISTALL:
	{
		list_all_rtk_memory_allocation_sort(list_mem_generic,NULL,NULL);
		break;
	}

	case COMPAT_AUTH_IOCQ_ALLOCAV:
	{
		compat_mem_alloc_struct __user *user_req = compat_ptr(arg);
		compat_mem_alloc_struct alloc;
		ret = copy_from_user(&alloc, user_req, sizeof(compat_mem_alloc_struct));
		ret = (int)pli_malloc_mesg(alloc.size, alloc.flag, alloc.str);
		if (ret == INVALID_VAL) {
			ret = 0;
		} else {
			struct page *page = pfn_to_page(ret >> PAGE_SHIFT);
			void *ptr = NULL;

			if (PageHighMem(page)) {
				pr_err("auth: AV cpu should not allocate highmem...\n");
				pli_free_mesg(ret);
				return 0;
			}
			ptr = page_address(page);
			dmac_flush_range((void *)ptr, (void *)(ptr+alloc.size));
			outer_flush_range(ret, ret+alloc.size);
		}
		return ret;
	}

	case AUTH_IOCQ_FREEAV:
	{
		pli_free_mesg(arg);
		break;
	}

	case COMPAT_AUTH_IOCS_FLUSHVIRT:
	{
		compat_mem_region_struct __user *user_req = compat_ptr(arg);
		compat_mem_region_struct region;
		struct vm_area_struct *vm_area;
		unsigned long pfn, phys_addr;

		ret = copy_from_user(&region, user_req, sizeof(compat_mem_region_struct));
		if (!ret) {
			vm_area = find_vma(current->mm, region.addr);
			if (!vm_area || follow_pfn(vm_area, region.addr, &pfn)) {
				pr_err("auth: virt addr %x is not allocated by pli...\n", region.addr);
				return -EINVAL;
			}
			phys_addr = (pfn << PAGE_SHIFT) + (region.addr & (PAGE_SIZE - 1));
//				if (!rtk_record_lookup(phys_addr, NULL)) {
//					pr_err("auth: phys addr %lx is not allocated by pli...\n", phys_addr);
//					return -EINVAL;
//				}
			dmac_flush_range(compat_ptr(region.addr), compat_ptr(region.addr+region.size));
			outer_flush_range(phys_addr, phys_addr+region.size);
		}
		break;
	}

	case AUTH_IOCQ_DCUSIZE:
	{
		ret = get_memory_size(arg);
		break;
	}

	case AUTH_IOCQ_MEMC_START_ADDRESS:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_MEMC_START_ADDRESS\n");
		ret = get_memc_start_address();
		pr_info("ret = 0x%x\n", ret);
		break;
	}

	case AUTH_IOCQ_MEMC_SIZE:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_MEMC_SIZE\n");
		ret = get_memc_size();
		pr_info("ret = %d\n", ret);
		break;
	}

	case AUTH_IOCQ_MDOMAIN_START_ADDRESS:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_MEMC_START_ADDRESS\n");
		ret = get_scaler_mdomain_start_address();
		pr_info("ret = 0x%x\n", ret);
		break;
	}

	case AUTH_IOCQ_MDOMAIN_SIZE:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_MEMC_SIZE\n");
		ret = get_scaler_mdomain_size();
		pr_info("ret = %d\n", ret);
		break;
	}

	case AUTH_IOCQ_OD_START_ADDRESS:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_OD_START_ADDRESS\n");
		ret = get_scaler_od_start_address();
		pr_info("ret = 0x%x\n", ret);
		break;
	}

	case AUTH_IOCQ_OD_SIZE:
	{
		pr_info("[64bit CARVED_OUT]case AUTH_IOCQ_OD_SIZE\n");
		ret = get_scaler_od_size();
		pr_info("ret = %d\n", ret);
		break;
	}

#ifdef	CONFIG_REALTEK_SCHED_LOG
	case AUTH_IOCSINITLOGBUF:
	{
		struct vm_area_struct *vm_area;
		unsigned long pfn, phys_addr;

		if(sched_log_from_kernel)
			return -EINVAL;


		ret = copy_from_user(&log_struct, (void *)arg, sizeof(log_struct));
		if (!ret) {
			vm_area = find_vma(current->mm, log_struct.addr);
			BUG_ON(follow_pfn(vm_area, log_struct.addr, &pfn));
			phys_addr = pfn << PAGE_SHIFT;
//				printk("phys_addr: %lx\n", phys_addr);

			sched_log_buf_head = (unsigned int *)dvr_remap_cached_memory(phys_addr, log_struct.size, __builtin_return_address(0));
			sched_log_buf_tail = (unsigned int *)((unsigned char *)sched_log_buf_head + log_struct.size);
			sched_log_buf_ptr = sched_log_buf_head;
			pr_info("LOG head: %x, tail: %x, ptr: %x...\n", (int)sched_log_buf_head, (int)sched_log_buf_tail, (int)sched_log_buf_ptr);
			sched_log_flag = 0;
			ret = sched_log_time_scale;
		}
		break;
	}

	case AUTH_IOCTFREELOGBUF:
	{
			if(sched_log_from_kernel)
				return -EINVAL;

		dvr_unmap_memory(sched_log_buf_head, sched_log_buf_tail - sched_log_buf_head);

		sched_log_buf_head = NULL;
		sched_log_buf_tail = NULL;
		sched_log_buf_ptr = NULL;
		sched_log_flag = 0;
		break;
	}

	case AUTH_IOCTLOGSTART:
	{
			if(sched_log_from_kernel)
				return -EINVAL;

		sched_log_buf_ptr = sched_log_buf_head;
		sched_log_start_time = timer_get_value(SYSTEM_TIMER); // tmp use the hw timer as the time_stamp
		sched_log_flag = 1;
		break;
	}

	case AUTH_IOCGLOGSTOP:
	{
		unsigned long offset;
		unsigned long cur_ptr;

			if(sched_log_from_kernel)
				return -EINVAL;

		if (!(sched_log_flag & 0x1))
			break;
		sched_log_flag &= ~0x1;

		while(1) {
			cur_ptr = (unsigned long)sched_log_buf_ptr;
			offset = cur_ptr - (unsigned long)sched_log_buf_head;

			if (offset % 0x8 == 0) // prevent cpu2 is still log
				break;
		}
		log_struct.addr = offset;
		log_struct.size = sched_log_flag;
		ret = copy_to_user((void *)arg, &log_struct, sizeof(log_struct));
		break;
	}

	case AUTH_IOCXLOGNAME:
	{
			if(sched_log_from_kernel)
				return -EINVAL;

		get_user(ret, (int *)arg);
		rcu_read_lock();
		task = pid_task(find_vpid(ret), PIDTYPE_PID);
		rcu_read_unlock();
		if (task != NULL) {
			ret = copy_to_user((void *)arg, task->comm, TASK_COMM_LEN);
		} else {
			ret = copy_to_user((void *)arg, "NULL", 5);
		}
		break;
	}

	case AUTH_IOCSTHREADNAME:
	{
			if(sched_log_from_kernel)
				return -EINVAL;

		ret = copy_from_user(current->comm, (void __user *)arg, TASK_COMM_LEN-1);
		current->comm[TASK_COMM_LEN-1] = '\0';
		WARN(ret, "Unable to get thread name @ 0x%08lx \n", arg+TASK_COMM_LEN-1-ret);
		break;
	}

	case AUTH_IOCTLOGEVENT:
	{
		int cpu = raw_smp_processor_id();

		if (!(sched_log_flag & 0x1))
			break;

//			pr_info("auth: logging event ***%lu*** \n", arg);
		log_event(cpu, arg);
		break;
	}
#endif // CONFIG_REALTEK_SCHED_LOG

	}

	return ret;
}
#endif

int auth_open(struct inode *inode, struct file *filp)
{
	filp->private_data = 0;
	return 0;
}

int auth_release(struct inode *inode, struct file *filp)
{
	unsigned long errno = 0;

	if ((unsigned long)filp->private_data) {
		mem_map_info *map = (mem_map_info *)filp->private_data;
		errno = rtktlb_munmap(map->addr);
		if (errno & 0x80000000)
			pr_err("auth: rtktlb_munmap error code %d...\n", (int)-errno);
		if (!bitmap_empty(map->bitmap, DEF_MEM_SIZE / PAGE_SIZE)) {
			pr_err("auth: there might still be pli memory which is not freed (%s %d)...\n",
				   current->comm, current->pid);
#ifdef CONFIG_CMA_RTK_ALLOCATOR
			char info[16];
			memset(info,0,sizeof(info));
			sprintf(info, "%lu", current->pid);

			list_all_rtk_memory_allocation_sort(list_pid_mem, NULL, info);
#endif
		}
		kfree(map->bitmap);
		kfree(map);
	} else {
		pr_err("auth: error in release pli interface...\n");
	}

	return 0;
}

struct file_operations auth_fops = {
	read:		auth_read,
	write:		auth_write,
	unlocked_ioctl: auth_ioctl,
#ifdef CONFIG_COMPAT
	compat_ioctl:	auth_compat_ioctl,
#endif
	open:		auth_open,
	release:	auth_release,
};

static char *auth_devnode(struct device *dev, umode_t *mode)
{
	*mode = 0666;
	return NULL;
}

#ifdef CONFIG_REALTEK_MANAGE_OVERLAPPED_REGION
#include <linux/bootmem.h>

static struct mem_bp	overlapped_bp;
static struct list_head overlapped_list;
static DEFINE_MUTEX(overlapped_mutex);

struct overlapped_record {
	struct list_head	list;
	unsigned long		pageno;
	unsigned long		order;
};

void init_overlapped_region(unsigned long base_pfn, int count)
{
	printk("auth: initialize overlapped region... base_pfn = 0x%x, count = 0x%x\n", base_pfn, count);
	INIT_LIST_HEAD(&overlapped_list);
	if (max_low_pfn > 0x10000)
		init_rtkbp(&overlapped_bp, base_pfn, count);
	else
		overlapped_bp.rtk_mem_map = 0;
}

unsigned long alloc_overlapped_memory(size_t size)
{
	unsigned long pageno;
	int count = 0, order;
	struct overlapped_record *record;

	if (overlapped_bp.rtk_mem_map == 0) {
		pr_err("auth: there is no overlapped region in this platform %d...\n", __LINE__);
		return 0;
	}

	size = PAGE_ALIGN(size);
	count = size >> PAGE_SHIFT;
	pr_info("auth: overlapped malloc size: %zu count: %d\n", size, count);

	record = kmalloc(sizeof(struct overlapped_record), GFP_KERNEL);
	if (unlikely(record == NULL))
		return 0;
	INIT_LIST_HEAD(&record->list);

	order = get_order(count * PAGE_SIZE);
	mutex_lock(&overlapped_mutex);
	pageno = alloc_rtkbp_memory(&overlapped_bp, order);
	if (pageno == INVALID_VAL) {
		mutex_unlock(&overlapped_mutex);
		pr_err("auth: not enough memory in overlapped region!\n");
		return 0;
	} else {
//		printk("*** alloc: %lx %lx \n", record->pageno, record->order);
		record->pageno = pageno;
		record->order = order;
		list_add(&record->list, &overlapped_list);
		mutex_unlock(&overlapped_mutex);
		return (overlapped_bp.base_pfn + pageno) << PAGE_SHIFT;
	}
}

void free_overlapped_memory(unsigned long phys_addr)
{
	unsigned long pageno;
	struct overlapped_record *rec, *tmp;

	if (overlapped_bp.rtk_mem_map == 0) {
		pr_err("auth: there is no overlapped region in this platform %d...\n", __LINE__);
		return;
	}

	pageno = (phys_addr >> PAGE_SHIFT) - overlapped_bp.base_pfn;
	mutex_lock(&overlapped_mutex);
	list_for_each_entry_safe(rec, tmp, &overlapped_list, list)
		if (rec->pageno == pageno) {
//			printk("*** free: %lx %lx \n", rec->pageno, rec->order);
			list_del(&rec->list);
			free_rtkbp_memory(&overlapped_bp, pageno, rec->order);
			kfree(rec);
			break;
		}
	mutex_unlock(&overlapped_mutex);
}
#endif

#if (defined(CONFIG_REALTEK_RPC))||defined(CONFIG_RTK_KDRV_RPC)
unsigned long rpc_dvr_malloc(unsigned long size, unsigned long none)
{
	unsigned long addr;
	addr = (int)pli_malloc(size, GFP_DCU1);
	if (addr == INVALID_VAL) {
		return 0;
	} else {
		struct page *page = pfn_to_page(addr >> PAGE_SHIFT);
		void *ptr = NULL;

		if (PageHighMem(page)) {
			pr_err("auth: AV cpu should not allocate highmem...\n");
			pli_free(addr);
			return 0;
		}
		ptr = page_address(page);
		dmac_flush_range((void *)ptr, (void *)(ptr+size));
		outer_flush_range(addr, addr+size);
		
		return addr;
	}
}

unsigned long rpc_dvr_free(unsigned long addr, unsigned long none)
{
	pli_free(addr);
	return 0;
}
#endif

static int auth_init(void)
{
	int result;

	result = register_chrdev(AUTH_MAJOR, AUTH_NAME, &auth_fops);
	if (result < 0) {
		pr_err("auth: can't get major %d...\n", AUTH_MAJOR);
		return result;
	}

	auth_class = class_create(THIS_MODULE, "auth");
	if (IS_ERR(auth_class))
		return PTR_ERR(auth_class);

	auth_class->devnode = auth_devnode;
#ifdef CONFIG_HIGHMEM
	auth_dev = device_create(auth_class, NULL, MKDEV(AUTH_MAJOR, 0), NULL, "auth");
	if (cma_highmem_start) {
		pr_info("release %08lx - %08lx for high memory cma...\n",
			cma_highmem_start, cma_highmem_start + cma_highmem_size);
		memblock_free(cma_highmem_start, cma_highmem_size);

		dma_declare_contiguous(auth_dev, cma_highmem_size, cma_highmem_start, 0);
	} else {
		/* we create a null cma in order to avoid kernel from using the default cma instead */
		dma_declare_null(auth_dev);
	}
#else
	auth_dev = device_create(auth_class, NULL, MKDEV(AUTH_MAJOR, 0), NULL, "auth");
	if (get_memory_size(GFP_DCU2)) {
		struct zone *zone = &NODE_DATA(0)->node_zones[ZONE_MOVABLE];
		pr_info("release %08lx - %08lx for high memory cma...\n",
				zone->zone_start_pfn << PAGE_SHIFT, zone_end_pfn(zone) << PAGE_SHIFT);
		memblock_free(zone->zone_start_pfn << PAGE_SHIFT, zone_end_pfn(zone) << PAGE_SHIFT);

		dma_declare_contiguous(auth_dev, zone->spanned_pages << PAGE_SHIFT, zone->zone_start_pfn << PAGE_SHIFT, 0);
	} else {
		dma_declare_null(auth_dev);
	}
#endif

	rtktlb_init();
	rtk_record_init();

#if (defined(CONFIG_REALTEK_RPC))||defined(CONFIG_RTK_KDRV_RPC)
	register_kernel_rpc(RPC_DVR_MALLOC, rpc_dvr_malloc);
	register_kernel_rpc(RPC_DVR_FREE, rpc_dvr_free);
#endif

	return 0; /* success */
}

#if 1//def CONFIG_HIGHMEM
pure_initcall(auth_init);
#else
static void auth_exit(void)
{
	rtktlb_exit();

	device_destroy(auth_class, MKDEV(AUTH_MAJOR, 0));
	class_destroy(auth_class);
	unregister_chrdev(AUTH_MAJOR, AUTH_NAME);
}

module_init(auth_init);
module_exit(auth_exit);
#endif
