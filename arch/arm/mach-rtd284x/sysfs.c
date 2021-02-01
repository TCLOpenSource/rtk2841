/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2010 by Chien-An Lin <colin@realtek.com.tw>
 *
 * sysfs attributes in /sys/realtek_boards
 */

#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/ctype.h>
#include <linux/sched.h>
#include <linux/semaphore.h>
#include <linux/pid.h>
#include <linux/slab.h>
#include <linux/firmware.h>
#include <linux/dma-mapping.h>
#include <mach/platform.h>
#include <mach/pcbMgr.h>
#include <linux/kthread.h>
#include <mach/io.h>
#include <linux/types.h>
#ifdef CONFIG_CMA_RTK_ALLOCATOR
#include <linux/pageremap.h>
#endif
#ifdef CONFIG_REALTEK_VDEC
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#endif
#ifdef CONFIG_SUPPORT_GDMA
#include <rtk_gdma_export.h>
#endif
#include <base_types.h>
#include <linux/cpumask.h>
#include <asm/smp_plat.h>
#include <asm/cputype.h>
#include <asm/cpu.h>
#include <asm/unistd.h>
#include <asm/fcntl.h>

#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
//#include <generated/compile.h>

//#define CONFIG_DUMP_REGISTER
#ifdef CONFIG_REALTEK_POWER_CUT
#if (defined CONFIG_RTK_KDRIVER) || (defined CONFIG_ARCH_RTK284X)
#include <rtk_kdriver/rtk_thermal_sensor.h>
#else
#include <mach/rtk_thermal_sensor.h>
#endif
#endif
#ifdef CONFIG_RTK_KDRV_WATCHDOG
#include <rtk_kdriver/rtk_watchdog.h>
#endif
#ifdef CONFIG_TRUST_ZONE_FOR_NORMAL_WORLD
#include "../../kernel/TZMoniter/tz_syscalls_cmd_def.h"
#endif

#if defined(CONFIG_RTK_KDRV_GDMA)
#include <rbus/sys_reg_reg.h>
#include <rbus/gdma_reg.h>
extern unsigned int gdma_dev_addr ;//kernel winfo addr
#endif

#include <rtk_kdriver/rtd_logger.h>

#define SYNC_STRUCT_ADDR 0x000000cc
//#define UNLZMA_SYNC_ADDR 0x00000070

#define CONFIG_BOOTUP_ANIMATION

/* MPIDR */
#define MPIDR_Cluster0_Core0	0x80000000
#define MPIDR_Cluster0_Core1	0x80000001
#define MPIDR_Cluster1_Core0	0x80000100
#define MPIDR_Cluster1_Core1	0x80000101

extern char *saved_command_line;


#ifdef CONFIG_BOOTUP_ANIMATION
//extern char corepath[100];
extern void *pAnimation;
extern void *pAnimation_1;
extern void *pLastImage;
#if defined(CONFIG_REALTEK_VDEC) || defined(CONFIG_RTK_KDRV_VDEC)
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
extern unsigned int notify_rtkvdec_release_pov ;
#endif
#endif
void setup_boot_image(void);
void setup_boot_image_mars(void);

#ifdef CONFIG_REALTEK_SHOW_STACK
void show_trace(struct task_struct *task, unsigned long *stack);
#endif

#define REALTEK_BOARDS_ATTR_RO(_name) \
static struct kobj_attribute _name##_attr = __ATTR_RO(_name)

#define REALTEK_BOARDS_ATTR_RW(_name) \
static struct kobj_attribute _name##_attr = \
	__ATTR(_name, 0644, _name##_show, _name##_store)

extern void sched_show_task(struct task_struct *p); 

void dump_parent_info(char * upload_buf)
{
        int free_size = 1024;
        static char * buf = NULL;
        char * pos = NULL; 
        struct task_struct * pTask;

        //console_loglevel = 8; 
        pr_err("force change loglevel to dump family info!\n");
             
        if(!buf)
        {    
                buf = kmalloc(free_size, GFP_ATOMIC);
		if(!buf)
		{
                	pr_err("no mem for parent info dump!\n");
                	return;
		}
        }    
        memset(buf, 0, free_size);

	pos = buf;
        pos += snprintf(pos, free_size, "Start dump family : ");
        free_size = free_size - strlen(buf);
        //pr_err("%s ", current->comm);
        pTask = current;

        while((pTask)&&(free_size > 10))
        {
                //pr_err("parse pTask:%d (current:0x%08x parent:0x%08x, real_parent:0x%08x) \n", pTask->pid, pTask, pTask->parent, pTask->real_parent);
                if(pTask->comm)
                {
                        pos += snprintf(pos, free_size, " %s(PID:%04d TGID:%04d) <-", pTask->comm, pTask->pid, pTask->tgid);
                        free_size = free_size - strlen(buf);
                        //pr_err("<- %s ", pTask->comm);
                }
                sched_show_task(pTask);
                pTask = pTask->real_parent;

                if(pTask == pTask->real_parent)
                {
                        break;
                }
        }
	
	pos += snprintf(pos, free_size, " [END]\n");
	free_size = free_size - strlen(buf);

        buf[free_size - 1] = 0;

#ifdef CONFIG_REALTEK_LOGBUF
        rtdlog_save_keylog("[FAMILY INFO] %s",buf);
#endif

        if(upload_buf)
        {
            sprintf(upload_buf,"%s",buf);
        }
        pr_err("%s", buf);
	//free(buf); do not free this buf
}

#ifdef CONFIG_REALTEK_LOGBUF
extern int rtdlog_save_keylog(const char * fmt, ...);
#endif

void parent_info_dump_and_store(char * buf)
{
        dump_parent_info(buf);
}
EXPORT_SYMBOL(parent_info_dump_and_store);

static ssize_t parent_info_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	parent_info_dump_and_store(page);

	return strlen(page);
}
REALTEK_BOARDS_ATTR_RO(parent_info);

static ssize_t kernel_source_code_info_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info.kernel_source_code_info);
}
REALTEK_BOARDS_ATTR_RO(kernel_source_code_info);

static ssize_t bootloader_version_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info.bootloader_version);
}
REALTEK_BOARDS_ATTR_RO(bootloader_version);

static ssize_t board_id_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%x\n", platform_info.board_id);
}
REALTEK_BOARDS_ATTR_RO(board_id);

static ssize_t cpu_id_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%x\n", platform_info.cpu_id);
}
REALTEK_BOARDS_ATTR_RO(cpu_id);

static ssize_t tv_encoding_system_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	unsigned char *name = NULL;
	switch(platform_info.tv_encoding_system) {
	case PAL:
		name = "PAL";
		break;
	case NTSC:
	default:
		name = "NTSC";
		break;
	}
	return sprintf(page, "%x (%s)\n", platform_info.tv_encoding_system, name);
}
REALTEK_BOARDS_ATTR_RO(tv_encoding_system);

#ifdef CONFIG_REALTEK_SHOW_STACK
static void show_task_stack(int pid)
{
	struct task_struct	*task;
	struct pt_regs		*regs;

	rcu_read_lock();
	task = pid_task(find_vpid(pid), PIDTYPE_PID);
	rcu_read_unlock();
	if (task == NULL) {
		printk("Task %d doesn't exist...\n", pid);
		return;
	}
	regs = (struct pt_regs *)(((unsigned char *)task->stack)+THREAD_SIZE-32-sizeof(struct pt_regs));

	printk("task name: %s, priority: %d state: %lx flags: %lx (epc == %lx, ra == %lx) \n",
			task->comm, task->prio, task->state, task_thread_info(task)->flags,
			(unsigned long)regs->cp0_epc, (unsigned long)regs->regs[31]);
	show_stack(task, NULL);
}

static ssize_t task_stack_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "Please add thread id as parameter...\n");
}

static ssize_t task_stack_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p, buffer[20] = {0};
	int i, len, pid;

	p = memchr(page, '\n', count);
	len = p ? p - page : count;
	strncpy(buffer, page, len);
	for (i = 0; i < len; i++)
		if (!isdigit(buffer[i])) {
			printk("%c is not digit...\n", buffer[i]);
			return count;
		}
	sscanf(buffer, "%d", &pid);
	printk("pid value: %d \n", pid);
	show_task_stack(pid);

	return count;
}
REALTEK_BOARDS_ATTR_RW(task_stack);
#endif

static ssize_t apk_boost_mode_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%x\n",platform_info.apk_boost_mode);
}

static ssize_t apk_boost_mode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	platform_info.apk_boost_mode=1;
	return count;
}

//static struct kobj_attribute apk_boost_mode_attr =
//	__ATTR(apk_boost_mode, 0646, apk_boost_mode_show, apk_boost_mode_store);
REALTEK_BOARDS_ATTR_RW(apk_boost_mode);



#ifdef CONFIG_REALTEK_POWER_CUT
static int is_vo_source(void)
{
	unsigned int val=rtd_inl(0xb8022210);
	if((val & 0x01) && (val & 1<<31))
	{
		val=val & 0x70000000;
		val >>= 28;
		if(val==4 || val==5 || val==6)
		{
			return 1;
		}
	}
	return 0;
}

static int getinputwidth(void)
{
	return (rtd_inl(0xb8022218) & 0x3FFF);
}

static int getinputheight(void)
{
	return (rtd_inl(0xb802221c) & 0x1FFF);
}

static ssize_t power_cut_load_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(is_platform_KXLP())
		return sprintf(page, "%x %d %d %d %d\n", platform_info.power_cut_load,
			rtk_get_thermal_value(),is_vo_source(),getinputwidth(),getinputheight());
	else
		return sprintf(page, "%x %d %d %d %d\n", platform_info.power_cut_load,
			0,0,0,0);
}

static ssize_t power_cut_load_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page!=NULL)
		platform_info.power_cut_load=platform_info.power_cut_load^1;
	else
		platform_info.power_cut_load=0;
	return platform_info.power_cut_load;
}
REALTEK_BOARDS_ATTR_RW(power_cut_load);
#endif


#ifdef CONFIG_REALTEK_SCHED_LOG
extern void auth_sched_log_init(int size);
extern void auth_sched_log_start(void);
extern void auth_sched_log_free(char *filename);
extern void log_event(int cpu, int event);

static ssize_t sched_log_time_duration_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d\n", platform_info.sched_log_time_duration);
}


static struct task_struct *rtk_sched_log_task;

int diff_time_val_ms(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec)*1000 + ((end->tv_usec - start->tv_usec)/1000);
}

static int kthread_logging_file(void *arg)
{
	struct timeval t0_start, t0_end;
	//int *d = (int *) arg;

	unsigned int target_duration=platform_info.sched_log_time_duration;
	if(target_duration>=300)
		target_duration=300;

	do_gettimeofday(&t0_start);
    for(;;) {
        if (kthread_should_stop())
			break;

		do_gettimeofday(&t0_end);

		if(platform_info.sched_log_file_stop) //user issue stop command
			break;

		if(diff_time_val_ms(&t0_start , &t0_end)> (target_duration*1000))
			break;

		msleep(10);
    }

	printk("logging time info:%ld %ld end:%ld %ld diff:%d\n",t0_start.tv_sec, t0_start.tv_usec,
		t0_end.tv_sec, t0_end.tv_usec,diff_time_val_ms(&t0_start , &t0_end));

	if(strlen(platform_info.sched_log_name)) {
		auth_sched_log_free(platform_info.sched_log_name);
		printk("end to logging files:%s\n",platform_info.sched_log_name);
	}
	else
	{
		auth_sched_log_free("/tmp/usb/sda/sda1/Performance.vcd");
		printk("end to logging files:/tmp/usb/sda/sda1/Performance.vcd\n");
	}
	platform_info.sched_log_file_start=0;
    return 0;
}

static ssize_t sched_log_time_duration_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    int ret;

	if(platform_info.sched_log_file_start)
		return 0;

	if(page) {
		sscanf(page,"%d",&platform_info.sched_log_time_duration);
	}
	else
		platform_info.sched_log_time_duration=10;
	if(platform_info.sched_log_time_duration<=0)
		platform_info.sched_log_time_duration=10;
	if(platform_info.sched_log_size>0)
		auth_sched_log_init(platform_info.sched_log_size);
	else
		auth_sched_log_init(6*1024*1024);
	auth_sched_log_start();
	platform_info.sched_log_file_start=1;

	rtk_sched_log_task = kthread_create(kthread_logging_file, NULL, "sched_log");
	if (IS_ERR(rtk_sched_log_task)) {
        	ret = PTR_ERR(rtk_sched_log_task);
        	rtk_sched_log_task = NULL;
	}
	else
	    wake_up_process(rtk_sched_log_task);

	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_time_duration); //default 10s, use timer to stop log, set it will trigger log start and stop
static ssize_t sched_log_file_start_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d\n", platform_info.sched_log_file_start);
}

static ssize_t sched_log_file_start_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page) {
		sscanf(page,"%d",&platform_info.sched_log_file_start);
	}
	else
		platform_info.sched_log_file_start=0;
	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_file_start); // cat it will start to log file
static ssize_t sched_log_size_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.sched_log_size<=0)
		platform_info.sched_log_size=6*1024*1024;
	return sprintf(page, "%d\n", platform_info.sched_log_size);
}

static ssize_t sched_log_size_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page) {
		sscanf(page,"%d",&platform_info.sched_log_size);
	}
	else
		platform_info.sched_log_size=6*1024*1024;
	if(platform_info.sched_log_size>(12*1024*1024))
		platform_info.sched_log_size=12*1024*1024;
	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_size); //default 6M



static ssize_t sched_log_event_number_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.sched_log_event_number<=0)
		platform_info.sched_log_event_number=100;
	return sprintf(page, "%d\n", platform_info.sched_log_event_number);
}

static ssize_t sched_log_event_number_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page) {
		sscanf(page,"%d",&platform_info.sched_log_event_number);
	}
	else
		platform_info.sched_log_event_number=100;
	if(platform_info.sched_log_event_number> 65536)
		platform_info.sched_log_event_number=100;
	log_event(smp_processor_id(),platform_info.sched_log_event_number);
	log_event(smp_processor_id(),platform_info.sched_log_event_number+1);
	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_event_number);

static ssize_t sched_log_file_stop_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d\n", platform_info.sched_log_file_stop);
}

static ssize_t sched_log_file_stop_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page) {
		sscanf(page,"%d",&platform_info.sched_log_file_stop);
	}
	else
		platform_info.sched_log_file_stop=0;
	kthread_stop(rtk_sched_log_task);
	platform_info.sched_log_file_start=0;
	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_file_stop);

static ssize_t sched_log_name_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info.sched_log_name);
}

static ssize_t sched_log_name_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	if(page) {
		sscanf(page,"%s",&platform_info.sched_log_name);
	}
	else
		strcpy(platform_info.sched_log_name,"/tmp/usb/sda/sda1/Performance.vcd");
	return count;
}

REALTEK_BOARDS_ATTR_RW(sched_log_name); //default /tmp/usb/sda/sda1
#endif


#ifdef CONFIG_TRUST_ZONE_FOR_NORMAL_WORLD
//extern gic_show_info(void);
#endif

//echo "set2,18061500," > /sys/realtek_boards/arm_wrapper
#ifdef CONFIG_REALTEK_ARM_WRAPPER
__attribute__((weak)) void arm_wrapper_suspend (void) {}
__attribute__((weak)) void arm_wrapper_resume  (void) {}

__attribute__((weak)) void arm_wrapper_get (void) {}
__attribute__((weak)) void arm_wrapper_dump (void) {}
__attribute__((weak)) void arm_wrapper_set (const char *buffer) {}
static ssize_t arm_wrapper_show (struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
    arm_wrapper_get();
    return 0;
}

static volatile int arm_wrapper[0x10] __attribute__((aligned(256))) ;
//static volatile int arm_wrapper_;
static ssize_t arm_wrapper_store (struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    char buffer[128];
    int arm_wrapper_ = 0;
    static unsigned int addr_s =0,addr_e=0;

    memset(buffer, 0, sizeof(buffer));
    if (strncmp(page,"dbg_show",strlen("dbg_show"))==0)
    {
        addr_s=virt_to_phys(arm_wrapper);
        addr_e=addr_s+sizeof(arm_wrapper);
        pr_err("dbg start addr=%x, dbg end addr=%x\n",addr_s,addr_e);

        pr_err("You can set ARM wrapper cmd like below:\n");

        snprintf(buffer,sizeof(buffer),"echo \"set%d %x-%x %s\">/sys/realtek_boards/arm_wrapper",2,addr_s,addr_e,"r");
        pr_err("%s\n",buffer);
        pr_err("echo dbg_read >/sys/realtek_boards/arm_wrapper\n\n");

        snprintf(buffer,sizeof(buffer),"echo \"set%d %x-%x %s\">/sys/realtek_boards/arm_wrapper",2,addr_s,addr_e,"w");
        pr_err("%s\n",buffer);
        pr_err("echo dbg_write >/sys/realtek_boards/arm_wrapper\n\n");
    }
    else if (strncmp(page,"dbg_read",strlen("dbg_read"))==0)
    {
        pr_err("\n\n\nSCPU triggerr arm wrapper interrupt: invalid read access debug address          \e[1;31m0x%08x  \e[0m\n\n\n",addr_s);
        arm_wrapper_=arm_wrapper[2];

        pr_err("\n\n\n%s %d. SCPU dbg read finish\n",__func__,__LINE__);
    }
    else if (strncmp(page,"dbg_write",strlen("dbg_write"))==0)
    {
        pr_err("\n\n\nSCPU triggerr arm wrapper interrupt: invalid write access debug address          \e[1;31m0x%08x\e[0m\n\n\n",addr_s);
        arm_wrapper[2]=38;

        pr_err("\n\n\n%s %d. SCPU dbg write finish\n",__func__,__LINE__);
    }
    else if (strncmp(page,"dbg_dump",strlen("dbg_dump"))==0)
    {
        arm_wrapper_dump();
    }
    else
    {
        arm_wrapper_set(page);
    }
    return count;
}
REALTEK_BOARDS_ATTR_RW(arm_wrapper);
#endif

#ifdef CONFIG_RTK_KDRV_QOS_CONTROL
extern ssize_t rtk_qos_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);
extern ssize_t rtk_qos_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);

REALTEK_BOARDS_ATTR_RW(rtk_qos);
#endif

#ifdef CONFIG_DUMP_REGISTER
extern void reg_dump_set (const char *buffer);
static ssize_t reg_dump_show(struct kobject * kobj, struct kobj_attribute * attr, char * page)
{
	//rtd_printk(KERN_DEBUG, WRAP_TAG,"reg_dump_show\n");
	//pr_emerg("reg_dump_show\n");
	return 0;
}
static ssize_t reg_dump_store (struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	reg_dump_set(page);
	 return count;
}
REALTEK_BOARDS_ATTR_RW(reg_dump);
#endif

#ifdef CONFIG_RTK_KDRV_SB2
static ssize_t sb2_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
    int value=1;

	#ifdef CONFIG_TRUST_ZONE_FOR_NORMAL_WORLD
	//TZ_smc_with_cmd(NT_SMC_SWITCH, NT_SMC_SEND_SGI_INT, 0);
	//gic_show_info();
	#endif

    return sprintf(page, "sb2_show: %d\n", value);
}


//echo 1 > /sys/realtek_boards/sb2
extern unsigned int _etext[],_edata[];
static ssize_t sb2_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    unsigned int value;
    char str[2];
    strncpy(str,page,1);
    str[1]=0;
    //printk("@sb2_store       page=%s   str=%s  count=%d\n",page,str,count);

    //#define VENUS_MIS_TCWTR            0x1BB04     --> 0x1801 bb04
    //outl(0x01, VENUS_MIS_TCWTR);
    //inl(SATURN_DC_EC_ADDCMD_HI);

    //reserved rbus address at 1800_xxxx ~ 1806_xxxx
    if (strncmp(str,"1",1)==0)
    {
        //value=rtd_inl(0xb8063000);
        //value=inl(0x63000);//0x1806_3000 - 0x1806_FFFF  --> Reserved

        //test for disbale vdc
        value=rtd_inl(0xb8000114);
        rtd_outl(0xb8000114,value&0xFFBFFFFF);

        value=0Xb8019000;
        printk("trigger sb2 interrupt: access reserverd  rbus address          \e[1;31m0x%x\e[0m\n\n\n",value);
        value=rtd_inl(value);
    }
    else if (strncmp(str,"2",1)==0)
    {
        //value=rtd_inl(0xb8063000);
        //value=inl(0x63000);//0x1806_3000 - 0x1806_FFFF  --> Reserved

        //test for disbale vdc
        //value=rtd_inl(0xb8000114);
        //rtd_outl(0xb8000114,value&0xFFBFFFFF);

        value=0Xb8019000;
        printk("trigger sb2 interrupt: access reserverd  rbus address          \e[1;31m0x%x\e[0m\n\n\n",value);
        value=rtd_inl(value);
    }


    //flash space:0x1dc0_0000 - 0x1fff_ffff, rbus 0x1800_0000 -0x1806_ffff , dbus 0x0000_0000 - 0x1000_0000
    #if 0
    else if (strncmp(page,"2",1)==0)
    {
        printk("trigger sb2 interrupt: access \e[1;31minvalid address\e[0m      current mac scpu donot have this type interrupt\n\n\n");
        value= *(unsigned long *)0x9db00000;
    }
    else if (strncmp(page,"3",1)==0)
    {
        value=(unsigned int )_etext-0x10;
        printk("trigger sb2 interrupt: access \e[1;31mdebug specified address[%x,%x]\e[0m\n\n\n",value,_etext);
        //value=*(unsigned long *)(value);
        *(unsigned long *)(value)=0;
    }
    #endif
    else
    {
        printk("trigger sb2 interrupt:  no interrupt\n");
    }
    printk("trigger sb2 interrupt:        \e[1;31mfinished!\e[0m\n\n");
    return count;
}
REALTEK_BOARDS_ATTR_RW(sb2);
#endif


#ifdef CONFIG_RTK_KDRV_SB2
void hw_monitor_get_status(char * buf, int bufsize);
void sb2_dbg_get (void);
void sb2_dbg_set (const char *buffer);
int sb2_dbg_monitor (unsigned int start,unsigned int end,int cpu_id,int set_id);
static ssize_t sb2_dbg_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
    char hw_monitor_buf[32];

    sb2_dbg_get();
    memset(hw_monitor_buf, 0, sizeof(hw_monitor_buf));
    hw_monitor_get_status(hw_monitor_buf, sizeof(hw_monitor_buf));

    return snprintf(page, sizeof(hw_monitor_buf), hw_monitor_buf);
    //return 0;
}

//echo dbg > /sys/realtek_boards/sb2_dbg
static ssize_t sb2_dbg_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    unsigned int value;
    if (strncmp(page,"dbg",3)==0)
    {
        value=0xb8061500;//hdmi
        printk("trigger sb2 dbg interrupt: access debug rbus address          \e[1;31m0x%x\e[0m\n\n\n",value);
        sb2_dbg_monitor(0x18061500,(0x18061500+0x100),3,8);
        value=rtd_inl(value);
    }
    else if (strncmp(page,"1",1)==0)
    {
        value=0xb8061500;//hdmi
        printk("trigger sb2 dbg interrupt: access debug rbus address          \e[1;31m0x%x\e[0m\n\n\n",value);
        sb2_dbg_monitor(0x18061500,(0x18061500+0x100),4,8);
    }
    else
    {
        sb2_dbg_set(page);
    }
    return count;
}

REALTEK_BOARDS_ATTR_RW(sb2_dbg);
#endif

#ifdef CONFIG_REALTEK_LOGBUF
__attribute__((weak)) void rtdlog_get (void)
{
        return;
}

__attribute__((weak)) void rtdlog_set (const char *buffer)
{
        return;
}

static ssize_t rtdlog_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
    rtdlog_get();
    return 0;
}

static ssize_t rtdlog_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    rtdlog_set(page);
    return count;
}

REALTEK_BOARDS_ATTR_RW(rtdlog);
#endif


#ifdef CONFIG_RTK_KDRV_WATCHDOG
//echo 1 > /sys/realtek_boards/watchdog
//cat /sys/realtek_boards/watchdog

#if defined(CONFIG_RTK_KDRV_RTICE)
extern volatile int watchdog_rtice;
#endif

static ssize_t watchdog_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
#if defined(CONFIG_RTK_KDRV_RTICE)
    return sprintf(page, "/sys/realtek_boards/watchdog: %d  %d.  NMI:%x WOV%x\n",
        rtk_watchdog_get_flag(),watchdog_rtice,rtd_inl(0xB806220C),rtd_inl(0xB8062210));
#else
return sprintf(page, "/sys/realtek_boards/watchdog: %d\n", rtk_watchdog_get_flag());
#endif
}

static ssize_t watchdog_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
    char str[2];
    strncpy(str,page,1);
    str[1]=0;

    if (strncmp(str,"1",1)==0)
    {
        printk("watchdog test!\n\n\n");
        local_irq_disable();
        while (1) ;
    }
    else
    {
        printk("@watchdog_store\n");
    }
    return count;
}
REALTEK_BOARDS_ATTR_RW(watchdog);
#endif

#ifdef CONFIG_RTK_KDRV_AVCPU
#if 1//#ifdef SUPPORT_AV_NO_RELOAD
static ssize_t stravnoreload_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	extern int stravnoreload;
	return sprintf(page, "stravnoreload_show:%d\n", stravnoreload);
}
REALTEK_BOARDS_ATTR_RO(stravnoreload);
#endif
#endif

/************************************************************/
// must sync with bootcode
extern phys_addr_t __initdata reserved_dvr_start;
#define POWER_ON_RESOURCE_ADDR                      (0x04eff000)     // 086ff000~0870_0000

#define RESOURCE_MAGIC_NUM  0x1234abcd
/************************************************************/
#define VSC_LINE_MAX  12
#define VSC_CONTENT_MAX  20
typedef struct
{
        unsigned int magic_num;
        unsigned int scaler_resource_offset;
        unsigned int throttle_resource_offset;
        unsigned int check_sum;
}RESOURCE_TABLE;

typedef enum
{
        VSC_KEY_TIMING_E,
        VSC_KEY_RTNR_MODE_E,
        VSC_KEY_OD_E,
        VSC_KEY_DEXC_E,
        VSC_KEY_FREE_RUN_E,
        VSC_KEY_VE_COMP_E,
        VSC_KEYDIPQC_BIT_E,
        VSC_KEY_MA_SNR_E,
        VSC_KEY_MAX_E,
}VSC_KEY_E;

typedef struct{
        unsigned int magic_num;
        unsigned int check_sum;
        bool valid;
        char reserve1;
        char reserve2;
        char reserve3;
        char vsc_content[VSC_LINE_MAX][VSC_KEY_MAX_E][VSC_CONTENT_MAX];
}VSC_RESOURCE;

#if 0
typedef struct{
	char timing_index_str[VSC_CONTENT_MAX];
	char rtnr_mode_str[VSC_CONTENT_MAX];
	char od_en_str[VSC_CONTENT_MAX];
	char dexc_en_str[VSC_CONTENT_MAX];
	char free_run_str[VSC_CONTENT_MAX];
	char ve_comp_str[VSC_CONTENT_MAX];
	char dipqc_bit_str[VSC_CONTENT_MAX];
	char ma_snr_str[VSC_CONTENT_MAX];
}VSC_CONTENT;

void dump_scaler_resource_log(VSC_CONTENT* vsc_content)
{
        int i = 0;
        
        for(i=0; i<VSC_LINE_MAX; i++)
        { 
                printk("\n");
                printk("%s ", vsc_content[i].timing_index_str);
                printk("%s ", vsc_content[i].rtnr_mode_str);
                printk("%s ", vsc_content[i].od_en_str);
                printk("%s ", vsc_content[i].dexc_en_str);
                printk("%s ", vsc_content[i].free_run_str);
                printk("%s ", vsc_content[i].ve_comp_str);
                printk("%s ", vsc_content[i].dipqc_bit_str);
                printk("%s ", vsc_content[i].ma_snr_str);
                printk("\n");
        }
}
#endif
void * __init get_platform_resource(void)
{
        RESOURCE_TABLE *resource_table_virt_addr =  NULL;
        int cal_sum = 0;
        VSC_RESOURCE *vsc_resource = NULL;
        int *p_tmp = NULL;
        int i = 0;
        
        if(pAnimation)
        {
                resource_table_virt_addr = pAnimation + POWER_ON_RESOURCE_ADDR - reserved_dvr_start;
                cal_sum = resource_table_virt_addr->magic_num + resource_table_virt_addr->scaler_resource_offset + resource_table_virt_addr->throttle_resource_offset;

                if((resource_table_virt_addr->magic_num != RESOURCE_MAGIC_NUM) ||
                        (cal_sum != resource_table_virt_addr->check_sum))
                {
                        printk("%s resource_table is invalid; magic_num(0x%x) != 0x%x, resource_table_virt_addr->check_sum(0x%x) != cal_sum(0x%x)\n", __FUNCTION__,
                                resource_table_virt_addr->magic_num, RESOURCE_MAGIC_NUM, resource_table_virt_addr->check_sum, cal_sum);
                        goto error;
                }

                vsc_resource = (VSC_RESOURCE *)((unsigned int)resource_table_virt_addr + resource_table_virt_addr->scaler_resource_offset);
                if((vsc_resource->magic_num != RESOURCE_MAGIC_NUM) || (!vsc_resource->valid))
                {
                        printk("%s vsc_resource is invalid; magic_num(0x%x) != 0x%x, valid(0x%x)\n", __FUNCTION__, vsc_resource->magic_num, RESOURCE_MAGIC_NUM, vsc_resource->valid);
                        goto error;
                 }

                 p_tmp = (int *)(vsc_resource->vsc_content);
                 cal_sum = 0;
                 for(i=0; i<sizeof(vsc_resource->vsc_content)/4; i++)
                 {
                        cal_sum += p_tmp[i];
                 }

                 if(cal_sum != vsc_resource->check_sum)
                 {
                        printk("%s vsc_resource->check_sum(0x%x) != cal_sum(0x%x)\n", __FUNCTION__, vsc_resource->check_sum, cal_sum);
                        goto error;
                 }
        }
        else
        {
                printk("%s pAnimation(0x%x) is invalid\n", __FUNCTION__, (unsigned int)pAnimation);
                goto error;
        }

        // printk("%s pAnimation(0x%x)\n", __FUNCTION__, (unsigned int)pAnimation);

        // dump_scaler_resource_log((VSC_CONTENT*)(vsc_resource->vsc_content));
        
        return (void *)(vsc_resource->vsc_content);
        
error:
        return NULL;
}


/******************************************************************/
#define THROTTLE_LINE_MAX  10
#define THROTTLE_CONTENT_MAX  8
typedef enum
{
        MODULE_NAME_KEY_E = 0,
        THROTTLE_ENABLE_KEY_E,
        THROTTLE_0_KEY_E,
        THROTTLE_1_KEY_E,
        THROTTLE_2_KEY_E,
        THROTTLE_3_KEY_E,
        THROTTLE_MAX_KEY_E,
}THROTTLE_KEY_E;

typedef struct
{
        char module_name_content[THROTTLE_CONTENT_MAX];
        int content[THROTTLE_MAX_KEY_E-1];
}THROTTLE_CONTENT_T;

typedef struct
{
        unsigned int magic_num;
        int check_sum;
        bool valid;
        char reserve1;
        char reserve2;
        char reserve3;
        THROTTLE_CONTENT_T throttle_content[THROTTLE_LINE_MAX];
}THROTTLE_RESOURC_T;

#if 0
void dump_throttle_resource_log(THROTTLE_CONTENT_T *throttle_content)
{
        int i = 0;
        int j = 0;
        
        for(i=0; i<THROTTLE_LINE_MAX; i++)
        {
                if(!strlen(throttle_content[i].module_name_content))
                        continue;
                
                printk("%s ", throttle_content[i].module_name_content);
                
                for(j=THROTTLE_ENABLE_KEY_E; j<THROTTLE_MAX_KEY_E; j++)
                        printk("%d ", throttle_content[i].content[j-1]);
                printk("\n");
        }
}
#endif

void * __init get_platform_throttle_resource(void)
{
        RESOURCE_TABLE *resource_table_virt_addr =  NULL;
        int cal_sum = 0;
        THROTTLE_RESOURC_T *throttle_resource = NULL;
        int *p_tmp = NULL;
        int i = 0;
        
        if(pAnimation)
        {
                resource_table_virt_addr = pAnimation + POWER_ON_RESOURCE_ADDR - reserved_dvr_start;
                cal_sum = resource_table_virt_addr->magic_num + resource_table_virt_addr->scaler_resource_offset + resource_table_virt_addr->throttle_resource_offset;

                if((resource_table_virt_addr->magic_num != RESOURCE_MAGIC_NUM) ||
                        (cal_sum != resource_table_virt_addr->check_sum))
                {
                        printk("%s resource_table is invalid; magic_num(0x%x) != 0x%x, resource_table_virt_addr->check_sum(0x%x) != cal_sum(0x%x)\n", __FUNCTION__,
                                resource_table_virt_addr->magic_num, RESOURCE_MAGIC_NUM, resource_table_virt_addr->check_sum, cal_sum);
                        goto error;
                }

                throttle_resource = (THROTTLE_RESOURC_T *)((unsigned int)resource_table_virt_addr + resource_table_virt_addr->throttle_resource_offset);
                if((throttle_resource->magic_num != RESOURCE_MAGIC_NUM) || (!throttle_resource->valid))
                {
                        printk("%s throttle_resource is invalid; magic_num(0x%x) != 0x%x, valid(0x%x)\n", __FUNCTION__, throttle_resource->magic_num, RESOURCE_MAGIC_NUM, throttle_resource->valid);
                        goto error;
                 }

                 p_tmp = (int *)(throttle_resource->throttle_content);
                 cal_sum = 0;
                 for(i=0; i<sizeof(throttle_resource->throttle_content)/4; i++)
                 {
                        cal_sum += p_tmp[i];
                 }

                 if(cal_sum != throttle_resource->check_sum)
                 {
                        printk("%s throttle_resource->check_sum(0x%x) != cal_sum(0x%x)\n", __FUNCTION__, throttle_resource->check_sum, cal_sum);
                        goto error;
                 }
        }
        else
        {
                printk("%s pAnimation(0x%x) is invalid\n", __FUNCTION__, (unsigned int)pAnimation);
                goto error;
        }

        // printk("%s pAnimation(0x%x)\n", __FUNCTION__, (unsigned int)pAnimation);

        // dump_throttle_resource_log((THROTTLE_CONTENT_T*)(throttle_resource->throttle_content));
        
        return (void *)(throttle_resource->throttle_content);
        
error:
        return NULL;
}

#if 0 /* sync from bootcode audio/video info */
typedef struct {
	unsigned int    dwMagicNumber;          // identificatin String "$RTK" or "STD3"

	unsigned int    dwVideoStreamAddress;   // The Location of Video ES Stream
	unsigned int    dwVideoStreamLength;    // Video ES Stream Length

	unsigned int    dwAudioStreamAddress;   // The Location of Audio ES Stream
	unsigned int    dwAudioStreamLength;    // Audio ES Stream Length

	unsigned char   bVideoDone;
	unsigned char   bAudioDone;

	unsigned char   bHDMImode;              // monitor device mode (DVI/HDMI)

	char            dwAudioStreamVolume;    // Audio ES Stream Volume -60 ~ 40
	char            dwAudioStreamRepeat;    // 0 : no repeat ; 1 :repeat

	unsigned char   bPowerOnImage;          // Alternative of power on image or video
	unsigned char   bRotate;                // enable v &h flip
	unsigned int    dwVideoStreamType;      // Video Stream Type

	unsigned int    audio_buffer_addr;      // Audio decode buffer
	unsigned int    audio_buffer_size;
	unsigned int    video_buffer_addr;      // Video decode buffer
	unsigned int    video_buffer_size;
	unsigned int    last_image_addr;        // Buffer used to keep last image
	unsigned int    last_image_size;
} boot_av_info_t;
#endif

typedef enum {
	E_STAT_NOT_READY = 0,
	E_STAT_READY_TO_FINISH,
	E_STAT_FINISH
} BOOT_ANIMATION_STATUS;

#ifdef CONFIG_BOOTUP_ANIMATION
#if 1
void do_dvr_reclaim(int cmd)
{
	int aStat = E_STAT_NOT_READY;
	int vStat = E_STAT_NOT_READY;
//	unsigned int *unlzma = (unsigned int *)phys_to_virt(UNLZMA_SYNC_ADDR);


#if defined(CONFIG_RTK_KDRV_GDMA)
	unsigned int osdwi = (unsigned int)rtd_inl(GDMA_OSD1_WI_reg);
	if(SYS_REG_SYS_DISPCLKSEL_get_clken_disp_gdma(rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg))) {
		if(osdwi && gdma_dev_addr && (osdwi < gdma_dev_addr)) {
			printk(KERN_DEBUG"[GDMA]Skip %s, used=%08x, gdma will free later..\n",__func__,osdwi);
			return;
		}
	}
#endif
	printk("\033[1;44m [%s] cmd=%d...\033[0m\n", __FUNCTION__, cmd);
	/*
	 * Reclaim pAnimation
	 *   cmd=1: will wait for animation done passively.
	 *   cmd=3: will force to stop animation actively.
	 */

	pr_info("[POV] cmd = %d, pAnimation = 0x%x\n", cmd, pAnimation);
	if (((cmd == 1) || (cmd == 3)) && (pAnimation)) {
		unsigned int sync_phy = ntohl(*(unsigned int *)phys_to_virt(SYNC_STRUCT_ADDR));
		unsigned int force_to_stop_video = 0;
		unsigned int force_to_stop_audio = 0;

		if (cmd == 3) { // flag for force to stop video/audio
			force_to_stop_video = 1;
			force_to_stop_audio = 1;
		}

		if (sync_phy) {
			volatile char *sync_tmp, *sync_ptr;
			unsigned int aEnable = 0;
			unsigned int vEnable = 0;

			printk("*****[S]check boot animation %lx...\n", sync_phy);
		#if CONFIG_ARM64
			sync_tmp = dvr_remap_cached_memory(sync_phy, PAGE_SIZE, __builtin_return_address(0));
		#else
			sync_tmp = dvr_remap_uncached_memory(sync_phy, PAGE_SIZE, __builtin_return_address(0));
		#endif
			sync_ptr = sync_tmp + (sync_phy & ~PAGE_MASK);
			aEnable = (unsigned int)*(unsigned int *)(sync_ptr+12);
			vEnable = (unsigned int)*(unsigned int *)(sync_ptr+8);

			if (aEnable == 0) {
				printk("=====[A]no animation audio...\n");
				aStat = E_STAT_FINISH;
			}

			if (vEnable == 0) {
				printk("=====[V]no animation video...\n");
				vStat = E_STAT_FINISH;
			}
			while (1) {
				/*
				 * Check POV status first.
				 */
				if (vEnable && (vStat != E_STAT_FINISH)) {
					printk("*****[V]wait for animation video done...\n");
					if (2 == sync_ptr[20]) { //video playback is halt or finished.
						if (vStat == E_STAT_NOT_READY) { //video is halt at last frame.
							printk("*****[V]get video done bit=0x%x\n", sync_ptr[20]);
							sync_ptr[20] = 1; //notify video f/w to stop playback.
							printk("*****[V]change video done bit=0x%x\n", sync_ptr[20]);
							vStat = E_STAT_READY_TO_FINISH;
						}
						else if (vStat == E_STAT_READY_TO_FINISH) { //finished.
							vStat = E_STAT_FINISH;
							printk("=====[V]animation video is ready...\n");
						}
					}
					else if (0 == sync_ptr[20]) { //video is still running
						if (force_to_stop_video) {
							printk("#####[V]get video done bit=0x%x\n", sync_ptr[20]);
							sync_ptr[20] = 1; //notify video f/w to stop playback.
							printk("#####[V]force change video done bit=0x%x\n", sync_ptr[20]);
							vStat = E_STAT_READY_TO_FINISH;
						}
					}
				}

				/*
				 * Check POM status after POV is ready.
				 */
				if (aEnable && (vStat == E_STAT_FINISH) && (aStat != E_STAT_FINISH)) { //after video is ready, check audio status
					printk("*****[A]wait for animation audio done...\n");
					if (2 == sync_ptr[21]) { //audio playback is halt or finished.
						if (aStat == E_STAT_NOT_READY) { //audio is halt
							printk("*****[A]get audio done bit=0x%x\n", sync_ptr[21]);
							sync_ptr[21] = 1; //notify audio f/w to stop playback.
							printk("*****[A]change audio done bit=0x%x\n", sync_ptr[21]);
							aStat = E_STAT_READY_TO_FINISH;
						}
						else if (aStat == E_STAT_READY_TO_FINISH) { //finished.
							aStat = E_STAT_FINISH;
							printk("=====[A]animation audio is ready...\n");
						}
					}
					else if (0 == sync_ptr[21]) { //audio is still running
						if (force_to_stop_audio) {
							printk("#####[A]get audio done bit=0x%x\n", sync_ptr[21]);
							sync_ptr[21] = 1; //notify audio f/w to stop playback.
							printk("#####[A]force change audio done bit=0x%x\n", sync_ptr[21]);
							aStat = E_STAT_READY_TO_FINISH;
						}
					}
				}

				msleep(100);

				/*
				 * Check POV and POM are both ready, we can exit boot animation and reclaim memory.
				 */
				if ((aStat == E_STAT_FINISH) && (vStat == E_STAT_FINISH)) {
					break;
				}

			}

			dvr_unmap_memory((void *)sync_tmp, PAGE_SIZE);
		}
#if 0
		else {
			/*
			 * FIXME
			 */
			printk("=====check self-unlzma flag...\n");
			while (1) {
				if (!aStat) {
					// check audio flag...
					if (!unlzma[0]) {
						aStat = 1;
						printk("*****audio is unlzma...\n");
					}
				}
				if (!vStat) {
					// check video flag...
					if (!unlzma[1]) {
						vStat = 1;
						printk("*****video is unlzma...\n");
					}
				}

				if (aStat && vStat)
					break;

				msleep(100);
			}
		}
#endif

		dvr_free(pAnimation);
		if (pAnimation_1) {
			dvr_free(pAnimation_1);
			pAnimation_1 = 0;
		}
		pAnimation = 0;

	}
	/*
	 * Reclaim pLastImage by cmd=2
	 */
	pr_info("[POV] cmd = %d, pLastImage = 0x%x\n", cmd, pLastImage);
	if ((cmd == 2) && (pLastImage)) {
		dvr_free(pLastImage);
		pLastImage = 0;
#if defined(CONFIG_REALTEK_VDEC) || defined(CONFIG_RTK_KDRV_VDEC)
		pr_info("[POV] set notify release as 1\n");
		notify_rtkvdec_release_pov = 1 ;
#endif

        printk("\033[1;44m [%s] cmd=%d...\033[0m\n", __FUNCTION__, cmd);

}

}
#else
void do_dvr_reclaim(int cmd)
{
	if(pAnimation)
	{
#ifdef CONFIG_SUPPORT_GDMA
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 0);
#endif
#ifdef CONFIG_CMA_RTK_ALLOCATOR
		dvr_free(pAnimation);
#endif
		pAnimation = 0;
		printk("\033[1;44m [%s] stop bootlogo and reclaim the memory\033[0m\n", __FUNCTION__);
	}
}
#endif

#if 1
static ssize_t reclaim_dvr_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "Animation: %p\nLastImage: %p\n", pAnimation, pLastImage);
}

static ssize_t reclaim_dvr_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p, buffer[20] = {0};
	int len, cmd;

	p = memchr(page, '\n', count);
	len = p ? p - page : count;
	strncpy(buffer, page, len);
	sscanf(buffer, "%d", &cmd);

	do_dvr_reclaim(cmd);

	return count;
}
REALTEK_BOARDS_ATTR_RW(reclaim_dvr);
#else
static ssize_t reclaim_dvr_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "Animation: %p\n\n", pAnimation);
}
REALTEK_BOARDS_ATTR_RO(reclaim_dvr);
#endif
#endif

static ssize_t update_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d \n", platform_info.update_mode);
}

static ssize_t update_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p, buffer[20] = {0};
	int i, len, mode;

	p = memchr(page, '\n', count);
	len = p ? p - page : count;
	strncpy(buffer, page, len);
	for (i = 0; i < len; i++)
		if (!isdigit(buffer[i])) {
			printk("%c is not digit...\n", buffer[i]);
			return count;
		}
	sscanf(buffer, "%d", &mode);
	platform_info.update_mode = mode;

	return count;
}
REALTEK_BOARDS_ATTR_RW(update);

static ssize_t dvrfs_buffer_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "Please add command as parameter...\n");
}

static ssize_t dvrfs_buffer_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p, buffer[30] = {0};
	int len, cmd;
	unsigned int addr = 0, size = 0;

	p = memchr(page, '\n', count);
	len = p ? p - page : count;
	strncpy(buffer, page, len);
	sscanf(buffer, "%d %x %x", &cmd, &addr, &size);
	if (cmd == 1) {
		printk("Add video memory %x size %x into dvrfs buffer...\n", addr, size);
/////		add_dvrfs_buffer(addr, size);
	} else if (cmd == 2) {
		printk("Free dvrfs buffer...\n");
/////		free_dvrfs_buffer();
	} else {
		printk("Linux 2.6.34 does not support command %d...\n", cmd);
		BUG();
	}

	return count;
}
REALTEK_BOARDS_ATTR_RW(dvrfs_buffer);

static ssize_t misc_operations_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "0\n");
}

// We use "extern prom_printf" here because when printk is disabled, prom_printf will be defined as null if "prom.h" is included
extern void prom_printf(char *fmt, ...);

static ssize_t misc_operations_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p;
	int len;

	p = memchr(page, '\n', count);
	len = p ? p - page : count;

	if(len>0 && !strncmp(page, "1", 1)) {
		if(len>1 && !strncmp(page+1, " ", 1))
			printk("This is the current time: %s", page+2);
		else {
		printk("--------- %d\n", len);
			printk("This is the current time.\n");
		}
	} else if(len>0 && !strncmp(page, "2", 1)) {
		// set the default location of core dump...
		if(len>1 && !strncmp(page+1, " ", 1)) {
//			strcpy(corepath, page+2);
//			*strchr(corepath, '\n') = 0;
//			printk("set corepath: %s \n", corepath);
		} else {
			printk("Error, you must specify the location...\n");
		}
	}
	return count;
}
REALTEK_BOARDS_ATTR_RW(misc_operations);

#if defined(CONFIG_RTK_KDRV_RTICE)
int rtice_enable = 1;
static ssize_t rtice_enable_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
        return sprintf(page, "%x\n", rtice_enable);
}

static ssize_t rtice_enable_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
//        char *p;
//        int len;


 	 rtice_enable = simple_strtoul(page, 0, 0);

        return count;
}
REALTEK_BOARDS_ATTR_RW(rtice_enable);
#endif

/*
static ssize_t vout_interface_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d \n", (int)platform_info.vout_interface[0]);
}

static ssize_t vout_interface_store(struct kobject *kobj, struct kobj_attribute *attr, const char *page, size_t count)
{
	char *p;
	int len;

	p = memchr(page, '\n', count);
	if (!p)
		return count;
	len = p - page;
	if (!strncmp(page, "0", len)) {
		printk("[SYS] setting vout to component...\n");
		sscanf(page, "%d", &platform_info.vout_interface[0]);
	} else if (!strncmp(page, "1", len)) {
		printk("[SYS] setting vout to SCART...\n");
		sscanf(page, "%d", &platform_info.vout_interface[0]);
	} else {
		printk("[SYS] Unknown vout setting...\n");
	}

	return count;
}
REALTEK_BOARDS_ATTR_RW(vout_interface);
*/

static ssize_t system_parameters_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info.system_parameters);
}
REALTEK_BOARDS_ATTR_RO(system_parameters);

static ssize_t AES_CCMP_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.AES_CCMP_len>0) {
		memcpy(page, platform_info.AES_CCMP, platform_info.AES_CCMP_len);
		return platform_info.AES_CCMP_len;
	} else
		return 0;
}

REALTEK_BOARDS_ATTR_RO(AES_CCMP);

#if defined(CONFIG_REALTEK_PCBMGR)

static ssize_t panel_parameter_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.panel_parameter_len>0) {
		memcpy(page, platform_info.panel_parameter, platform_info.panel_parameter_len);
		return platform_info.panel_parameter_len;
	} else
		return 0;
}
REALTEK_BOARDS_ATTR_RO(panel_parameter);

// Darwin pcb enumeration for /sys/realtek_boards/pcb_enum

static int pcb_enum_count = 0;
struct linux_pcb_enum_t   pcb_enum_all[PCB_ENUM_MAX];

static struct attribute  **realtek_pcb_enum_attrs = NULL;
static struct attribute_group realtek_pcb_enum_attr_group = {
	.name = "pcb_enum",
};

int pcb_mgr_get_enum_info_byname(char *enum_name, unsigned long long *value) {


	char *buf, *token, *final;
	char pattern[256];
	buf = platform_info.pcb_enum_parameter;
	final = &platform_info.pcb_enum_parameter[platform_info.pcb_enum_parameter_len];
	sprintf(pattern, "pcb_enum=%s,", enum_name);

	//printk("PATTERN:%s\n", pattern);

	//printk("platform_info.pcb_enum_parameter = %s\n", platform_info.pcb_enum_parameter);
	token = strstr(buf, pattern);
	if (token) {
		token = token + strlen(pattern);
		if (value) {
			*value = simple_strtoull(token, 0, 0);
			return 0;
		}
	}
	return -1;
}

static ssize_t realtek_sysfs_pcb_enum_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{

	struct linux_pcb_enum_t *pos;
       pos = (struct linux_pcb_enum_t *) attr->attr.name;
	return sprintf(page, "0x%llx\n", pos->value);

}

static int pcb_enum_add(char *buffer) {
	int i;
	char *name = NULL;
	int name_len, space_hit;
	char *value = NULL;
	int len = strlen(buffer);




	if (pcb_enum_count >= PCB_ENUM_MAX) return 0;

 	for (i = 0; i<len ; i++) {
		if (buffer[i] == ' ') continue;
		name = &buffer[i];
		break;
	}
	if (i == len) return -1;

 	name_len = 0;
 	space_hit = 0;
 	for (; i< (len-1) ; i++) {
		if (buffer[i] == ',') {
			 value = &buffer[i+1];
			 break;
		}
		if (buffer[i] != ' ' && space_hit == 0) {
			  name_len++;
		} else {
	  		space_hit = 1;
	  }
	}
	if (name_len >= (PCB_ENUM_NAME_LEN_MAX-1)) return 0;
	if (value == NULL) return -1;

	strncpy(pcb_enum_all[pcb_enum_count].name, name, name_len);
	pcb_enum_all[pcb_enum_count].value = simple_strtoull(value, 0, 0);
	pcb_enum_count++;
	if (pcb_enum_count >= PCB_ENUM_MAX) return 0;
	pcb_enum_all[pcb_enum_count].name[0] = 0;
	pcb_enum_all[pcb_enum_count].value = 0;
	return 0;
}

static int realtek_sysfs_pcb_enum_dir_init(struct kobject *parent_kobj) {


	int i;
	int error;
	struct kobj_attribute *kobj_attr;
	char *buf, *token, *final;

	i = 0;
	buf = platform_info.pcb_enum_parameter;
	final = &platform_info.pcb_enum_parameter[platform_info.pcb_enum_parameter_len];
//	printk("platform_info.pcb_enum_parameter = %s\n", platform_info.pcb_enum_parameter);
	do {
		if (buf < platform_info.pcb_enum_parameter) {
	  	   printk("pcb enum parse error\n");
	  	   return -1;
	  }
		// skip next space
		while(buf < final) {
			if (buf[0] == ' ') {
				buf++;
			} else {
				break;
			}
		};

		if (buf >= final) break;

		token = strstr(buf, "pcb_enum=");
		if (token == NULL)
		    break;

		if (token != buf) {
				 printk("pcb enum parse error\n");
	  	   return -1;
		}
		token += 9;
//		printk("%s\n", token);
		pcb_enum_add(token);

		// find next space
		while(buf < final) {
			if (buf[0] != ' ') {
				buf++;
			} else {
				break;
			}
		};
		if (buf >= final) break;

	} while(1);

  if (pcb_enum_count == 0) return 0;

	realtek_pcb_enum_attrs = kmalloc((pcb_enum_count+1) * sizeof(struct attribute *), GFP_KERNEL);

	for (i=0; i<pcb_enum_count; i++) {


		kobj_attr = kmalloc(sizeof(struct kobj_attribute), GFP_KERNEL);
		memset(kobj_attr, 0, sizeof(struct kobj_attribute));

		kobj_attr->show = realtek_sysfs_pcb_enum_show;
		kobj_attr->store = NULL;
		realtek_pcb_enum_attrs[i] = &kobj_attr->attr;

		realtek_pcb_enum_attrs[i]->mode = 0444;
		realtek_pcb_enum_attrs[i]->name = pcb_enum_all[i].name;
/*		realtek_pcb_enum_attrs[i]->owner = THIS_MODULE;*/
//		printk("i = %d %s %016llx\n", i, realtek_pcb_enum_attrs[i]->name , pcb_enum_all[i].value);
	}
	realtek_pcb_enum_attrs[i] = NULL;
	realtek_pcb_enum_attr_group.attrs = realtek_pcb_enum_attrs;
	error = sysfs_create_group(parent_kobj, &realtek_pcb_enum_attr_group);
	if(error) {
		for (i=0; i<pcb_enum_count; i++) {
			kobj_attr = container_of(realtek_pcb_enum_attrs[i],struct kobj_attribute, attr);
			kfree(kobj_attr);
		}
		kfree(realtek_pcb_enum_attrs);
	}
	return error;
}

//__setup("pcb_enum=", pcb_enum_add);
#endif
static ssize_t modelconfig_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.modelconfig_len>0) {
		memcpy(page, platform_info.modelconfig, platform_info.modelconfig_len);
		return platform_info.modelconfig_len;
	} else
		return 0;
}
REALTEK_BOARDS_ATTR_RO(modelconfig);

static ssize_t signature_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info.signature);
}
REALTEK_BOARDS_ATTR_RO(signature);

static ssize_t AES_IMG_KEY_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	memcpy(page, platform_info.AES_IMG_KEY, AES_IMG_KEY_LEN);
	return AES_IMG_KEY_LEN;
}
REALTEK_BOARDS_ATTR_RO(AES_IMG_KEY);

static ssize_t RSA_KEY_MODULUS_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	if(platform_info.secure_boot == 1) {
		memcpy(page, platform_info.RSA_KEY_MODULUS, RSA_KEY_MODULUS_LEN);
		return RSA_KEY_MODULUS_LEN;
	} else
		return 0;
}
REALTEK_BOARDS_ATTR_RO(RSA_KEY_MODULUS);

static ssize_t _priv__show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s\n", platform_info._priv_);
}
REALTEK_BOARDS_ATTR_RO(_priv_);

static ssize_t _custom_param__show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%s", platform_info._custom_param_);
}
REALTEK_BOARDS_ATTR_RO(_custom_param_);

static inline unsigned long get_MPIDR(void)
{
	unsigned long val;

#ifdef CONFIG_ARM64
	val = read_cpuid_mpidr();
#else
	asm("mrc   p15, 0, %0, c0, c0, 5	@ get MPIDR" : "=r" (val) : : "cc");
#endif
	return val;
}



static int cmdline_find_option(const char *option, char *buffer, int bufsize)
{
	extern char *saved_command_line;
	char *start = NULL;
	char *end = NULL;
	int size = 0;


	start = strstr(saved_command_line, option);
	if(start == NULL)
	{
		strcpy(buffer, "bootcode_git_version = unknow");
		return -1;
	}

	if((end = strstr(start, " ")))   // end with 'space'
	{
		size = end-start;
		strncpy(buffer, start, size);
	}
	else if((end = strstr(start, "\0"))) // end with '\0'
	{
		strcpy(buffer, start);
	}
	else
	{
		strcpy(buffer, "bootcode_git_version = unknow");
		return -1;
	}
	return 0;
}

//284x can not adjust scpu voltage by software, so return the const voltage value directly. said by clamp
#define SCPU_VOLTAGE   1040   //Unit: millivolt
static ssize_t scpu_voltage_show(struct kobject *kobj, struct kobj_attribute *attr, char *page)
{
	return sprintf(page, "%d\n",SCPU_VOLTAGE);
}

REALTEK_BOARDS_ATTR_RO(scpu_voltage);

static ssize_t pll_info_show(struct kobject * kobj, struct kobj_attribute * attr, char * page)
{
#if 1	//TODO
	//	char   msg[64];
	//char   page_info[512];
	char   msg[128];
	ssize_t ret_size;
	char *page_info;
    //char   page_info[1024];
	uint value_f,value_n,value_m, value;
	uint freq, tmp;
	uint gpu_pre_div;

	UINT32 frame_rate, cnt = 0x1fff, stable_cnt = 0;
        UINT32 xclk = 270000000;
	UINT32 memc_dtg_frame_rate = 1;

	/* DFS relate */
	struct file *filp0,*filp1,*filp2,*filp3;
	uint dfs_enable_A53 = 0; // if enable,value = 1; if disable ,value = 0;

	/* SCPU PLL relate */
	uint d_divisor = 0;
	mm_segment_t fs;
	struct inode *inode;
	off_t fsize;
	int ret;
	char buf[32];
	// running cpu info
	int i = 0;
	u32 cpuid = 0;
	u32 core_A53 = 0;


	page_info = kmalloc(1024, GFP_KERNEL);
	memset(page_info, 0, 1024);
#if 0
        while(cnt--){
                frame_rate = xclk / rtd_inl(0xB80282EC);
                if((frame_rate % 10) >4)
                        frame_rate = frame_rate / 10 + 1;
                else
                        frame_rate = frame_rate / 10;
                if(frame_rate == memc_dtg_frame_rate){
                        if(stable_cnt == 5)
                                break;
                        else
                                stable_cnt++;
                }
                else{
                        if(memc_dtg_frame_rate !=0)
                                stable_cnt--;
                        memc_dtg_frame_rate = frame_rate;
                        msleep(5);
                }
        }

	memset(msg, 0, sizeof(msg));
        sprintf( msg, "MEMC DTG output frame_rate = %dHz\n", frame_rate);
        strcat(page_info, msg);

	value_f = 0;
        tmp = rtd_inl(0xb809c038);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c040);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c048);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c050);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c070);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c090);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c098);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c0a0);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c114);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c11C);
        value_f += ( tmp >> 20 ) & 1;

	tmp = rtd_inl(0xb809c138);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c140);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c15C);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c164);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c180);
        value_f += ( tmp >> 20 ) & 1;

        tmp = rtd_inl(0xb809c188);
        value_f += ( tmp >> 20 ) & 1;

        memset(msg, 0, sizeof(msg));
        if ( value_f == 0 )
                sprintf( msg, "MEMC repeated mode  : On \n");
        else
                sprintf( msg, "MEMC repeated mode  : Off \n");
        strcat(page_info, msg);

	// get RTNR on/off (B8024000 B[28]=1) && (0xb80241a0 B[0]=1)
	tmp = rtd_inl(0xB8024000);
	value_f = ((tmp & 0x10000000) >> 28);
	tmp = rtd_inl(0xb80241a0);
	value_n = ((tmp & _BIT0));

	memset(msg, 0, sizeof(msg));
	if ( value_f && value_n )
		sprintf( msg, "RTNR                : On \n");
	else
	      sprintf( msg, "RTNR                : Off \n");
	strcat(page_info, msg);
#endif
	// VE compression on/off B8005100 B[0]=1
	tmp = rtd_inl(0xB8005100) & 1;
	memset(msg, 0, sizeof(msg));
	if ( tmp )
		sprintf( msg, "VE compression      : On \n");
	else
		sprintf( msg, "VE compression      : Off \n");
	strcat(page_info, msg);

	// get GPU PLL FN value
	tmp = rtd_inl(0xB8000454);
	gpu_pre_div = ((rtd_inl(0xB8000450) & 0x30) >> 4)+1;
	value_f = ((tmp & 0x07FF0000) >> 16);
	value_n = ((tmp & 0x0000FF00) >> 8);
	freq = 27 * (value_n + 3) + ((27 * value_f) >> 11); // PLL Frequency = 27*(NCODE +3+ FCODE/2048)
	freq = freq/gpu_pre_div;

	memset(msg, 0, sizeof(msg));
	sprintf( msg, "GPU    PLL       = %4d MHz\n", freq );
	strcat(page_info, msg);

		// get DDR_1 PLL FN value
	tmp = rtd_inl(0xb8008024);
	value_f = ((tmp & 0x07FF0000) >> 16);
	tmp = rtd_inl(0xb8008028);
	value_n = ((tmp & 0x0000FF00) >> 8);
	freq = 27 * (value_n + 3) + ((27 * value_f) >> 11); //	27*(NCODE + 3 + FCODE/2048)
	memset(msg, 0, sizeof(msg));
	if (freq != 0)
		sprintf( msg, "DDR    PLL       = %4d MHz (DC1)\n", freq );

	else
		sprintf( msg, "DDR    PLL       = --- MHz (DC1)\n");
	strcat(page_info, msg);

#if 0
	// get DDR_1 PLL FN value
	tmp = rtd_inl(0xb8004024);
	value_f = ((tmp & 0x07FF0000) >> 16);
	tmp = rtd_inl(0xb8004028);
	value_n = ((tmp & 0x0000FF00) >> 8);
	freq = 27 * (value_n + 3) + ((27 * value_f) >> 11); //	27*(NCODE + 3 + FCODE/2048)
	memset(msg, 0, sizeof(msg));
	if (freq != 0)
		sprintf( msg, "DDR    PLL       = %4d MHz (DC2)\n", freq );
	else
		sprintf( msg, "DDR    PLL       = --- MHz (DC2)\n");
	strcat(page_info, msg);
#endif

	// get bootcode version
	memset(msg, 0, sizeof(msg));
	cmdline_find_option("bootcode_git_version", msg, sizeof(msg));
	strcat(page_info, msg);
	strcat(page_info, "\n");

	// get IB enable or not
	memset(msg, 0, sizeof(msg));
	if (0x1010 == (rtd_inl(0xb805c084) & 0xffff)) {
		sprintf( msg, "IB                  : disable \n");
	}
	else {
		sprintf( msg, "IB                  : enable \n");
	}
	strcat(page_info, msg);

	// get Arbitration enable or not
	memset(msg, 0, sizeof(msg));
	if (0 == (rtd_inl(0xb8007400) & (_BIT0 | _BIT1))) {
		sprintf( msg, "Arbitration         : disable \n");
	}
	else {
		sprintf( msg, "Arbitration         : enable \n");
	}
	strcat(page_info, msg);


	// GPU APM
	memset(msg, 0, sizeof(msg));
	filp0 = filp_open("/dev/dri/renderD128",O_RDONLY,0);
	if(IS_ERR(filp0))
	{
		sprintf( msg, "GPU APM             : disable \n");
	}
	else
	{
		filp_close(filp0, 0);
		if(0 == (rtd_inl(0xb8000114) & _BIT3))
		{
			sprintf( msg, "GPU APM             : enable \n");
		}
		else
		{
			if (0 == (rtd_inl(0xb810e09c) & _BIT4)) {
				sprintf( msg, "GPU APM             : enable \n");
			}
			else {
				sprintf( msg, "GPU APM             : disable \n");
			}
		}
	}
	strcat(page_info, msg);

	// VB1 status
	memset(msg, 0, sizeof(msg));
	tmp = rtd_inl(0xb802d704);
	value = ((tmp & 0x001f0000) >> 16);
	if(value)
	{
		sprintf(msg, "VB1 status          : %d lanes\n", value);
	}
	else
	{
		sprintf(msg, "VB1 status          : not use\n");
	}

	strcat(page_info, msg);

	// VP9 CLOCK
	memset(msg, 0, sizeof(msg));
	if (1 == (rtd_inl(0xb8000110) & _BIT13)) {
		sprintf( msg, "VP9 clock           : enable \n");
	}
	else {
		sprintf( msg, "VP9 clock           : disable\n");
	}
	strcat(page_info, msg);

	// EMMC MODE and PLL
	tmp = rtd_inl(0xb8000720);
	value_f = ((tmp & 0x00ff0000)>>16);

	tmp = rtd_inl(0xb8000700);
	value_n = ((tmp & 0x00000700) >> 8);
	value_m = ((tmp & 0x00020000) >> 17);
	freq = 27 * (value_f + 3)/(value_n+2)/(value_m+1)/2; //  27 *( PLLEMMC_NCODE_T +3)/ (PLLSN+2)/( PLLSDIV2+1)/2
    memset(msg, 0, sizeof(msg));
	if (freq != 0)
		sprintf( msg, "EMMC    PLL      = %4d MHz \n", freq );
	else
		sprintf( msg, "EMMC    PLL      = --- MHz \n");
	strcat(page_info, msg);

	memset(msg, 0, sizeof(msg));
	tmp = rtd_inl(0xb8010a0c);
	if(tmp & _BIT0)
	{
		sprintf( msg, "eMMC MODE           :  HS400 (%u)\n", freq );
	}
	else
	{
		if(freq > 50)
			sprintf( msg, "eMMC MODE           :  HS200 (%u)\n", freq );
		else
		{
			sprintf( msg, "eMMC MODE           :  SDR50 (%u)\n", freq );
		}
	}
	strcat(page_info, msg);


	for_each_online_cpu(i) {

#ifdef CONFIG_ARM64
        cpuid = is_smp() ? per_cpu(cpu_data, i).reg_midr : read_cpuid_id();
#else
        cpuid = is_smp() ? per_cpu(cpu_data, i).cpuid : read_cpuid_id();
#endif
		if((cpuid & 0x0000fff0) == 0x0000d030) {
				core_A53++;
		}
	}
	memset(msg, 0, sizeof(msg));
	sprintf( msg, "Running CPU core   : A53 x%d\n", core_A53);
	strcat(page_info, msg);

	// SCPU DFS
	filp0 = filp_open("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor",O_RDONLY,0);
	filp1 = filp_open("/sys/devices/system/cpu/cpu1/cpufreq/scaling_governor",O_RDONLY,0);
	filp2 = filp_open("/sys/devices/system/cpu/cpu2/cpufreq/scaling_governor",O_RDONLY,0);
	filp3 = filp_open("/sys/devices/system/cpu/cpu3/cpufreq/scaling_governor",O_RDONLY,0);
	memset(msg, 0, sizeof(msg));
	if((IS_ERR(filp0)) && (IS_ERR(filp1)) && (IS_ERR(filp2)) &&(IS_ERR(filp3)))
	{
		sprintf( msg, "SCPU    DFS         : disable \n");
		dfs_enable_A53 = 0;
	}
	else
	{
		sprintf( msg, "SCPU    DFS         : enable \n");
		if(0==IS_ERR(filp0))
		{
			dfs_enable_A53 = 1;
			filp_close(filp0, 0);
		}
		if(0==IS_ERR(filp1))
			filp_close(filp1, 0);
		if(0==IS_ERR(filp2))
		{
			filp_close(filp2, 0);
		}
		if(0==IS_ERR(filp3))
			filp_close(filp3, 0);
	}
	strcat(page_info, msg);

	// get SCPU:A53 PLL
	memset(msg, 0, sizeof(msg));
	memset(buf, 0, sizeof(buf));
	if(dfs_enable_A53 == 1) // DFS enable
	{
		filp0 = filp_open("/sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq",O_RDONLY,0);
		if(IS_ERR(filp0))
		{
			return -1;
		}
		inode = filp0->f_path.dentry->d_inode;
		fsize = inode->i_size;

		fs = get_fs();
		set_fs(KERNEL_DS);
		ret = filp0->f_op->read(filp0, buf, fsize, &(filp0->f_pos));
		set_fs(fs);

		if(ret > 0)
		{
			for(i=0; i<sizeof(buf); i++) // use 0 replace unused data
			{
				if(buf[i] == 0)
					break;
				if(buf[i]<'0' || buf[i]>'9')
				{
					buf[i] = 0;
				}
			}
			sprintf(msg, "SCPU(A53) PLL   = %s MHz\n", buf);
			strcat(page_info, msg);
		}
		else if(ret == 0)
		{
			strcat(page_info, "SCPU(A53) PLL: get fail\n");
		}
		else
		{
			strcat(page_info, "SCPU(A53) PLL: get fail\n");
		}

		if(filp0)
		{
			filp_close(filp0, NULL);
		}
	}
	else // DFS disable
	{
		d_divisor = 0;
		tmp = rtd_inl(0xb805b004);
		value_f = ((tmp & 0x07FF0000) >> 16);
		value_n = ((tmp & 0x0000FF00) >> 8);
		freq = 27 * (value_n + 3) + ((27 * value_f) >> 11); // PLL Frequency = 27*(NCODE+3+FCODE/2048)
		d_divisor = (rtd_inl(0xb805b044) & 0xf0) >>4;
		freq = freq * (16-d_divisor)/16;
		memset(msg, 0, sizeof(msg));
		sprintf( msg, "SCPU(A53) PLL   = %4d MHz\n", freq );
		strcat(page_info, msg);
	} // end if(dfs_enable_A53 == 1)

	ret_size = sprintf(page, "%s", page_info);
	kfree(page_info);
	return ret_size;
#else
	return 0;
#endif	//TODO
}
REALTEK_BOARDS_ATTR_RO(pll_info);

#define VIDEO_GIT_VERSION  "video_git_version=not_support"
#define AUDIO_GIT_VERSION  	"audio_git_version=not_support"
extern const char rtk_linux_git_version[];
extern const char rtk_kdriver_git_version[];
extern const char rtk_linux_svn_version[];
extern const char rtk_kdriver_svn_version[];

static ssize_t fw_git_version_show(struct kobject * kobj, struct kobj_attribute * attr, char * page)
{
	char *page_info = NULL;
	char   msg[128];
	ssize_t ret_size;
	
	if ((page_info = kmalloc(1024, GFP_KERNEL)) == NULL)
	{
		printk("OOM for fw_git_version\n");
		return 0; //none
	}

	memset(page_info, 0, 1024);
	
	// get bootcode version
	memset(msg, 0, sizeof(msg));
	cmdline_find_option("bootcode_git_version", msg, sizeof(msg));
	strcat(page_info, msg);
	strcat(page_info, "\n");

	// get linux git version
	memset(msg, 0, sizeof(msg));
	snprintf(msg, sizeof(msg)-1, rtk_linux_git_version);
	strcat(page_info, msg);
	strcat(page_info, "\n");

	// get rtk_kdriver git version
	memset(msg, 0, sizeof(msg));
	snprintf(msg, sizeof(msg)-1, rtk_kdriver_git_version);
	strcat(page_info, msg);
	strcat(page_info, "\n");

#ifdef CONFIG_OPTEE
	//get optee git version
	extern char optee_git_version[13];
	memset(msg, 0, sizeof(msg));
	snprintf(msg, sizeof(msg)-1, "optee_git_version=%s", optee_git_version);
	strcat(page_info, msg);
	strcat(page_info, "\n");
	ret_size = sprintf(page, "%s", page_info);
#endif

	//get audio git version
	memset(msg, 0, sizeof(msg));
	snprintf(msg, sizeof(msg)-1, VIDEO_GIT_VERSION);
	strcat(page_info, msg);
	strcat(page_info, "\n");
	ret_size = sprintf(page, "%s", page_info);

	//get video git version
	memset(msg, 0, sizeof(msg));
	snprintf(msg, sizeof(msg)-1, AUDIO_GIT_VERSION);
	strcat(page_info, msg);
	strcat(page_info, "\n");
	ret_size = sprintf(page, "%s", page_info);
	
	kfree(page_info);
	return ret_size;
}
REALTEK_BOARDS_ATTR_RO(fw_git_version);

static ssize_t fw_svn_version_show(struct kobject * kobj, struct kobj_attribute * attr, char * page)
{
        char *page_info = NULL;
        char   msg[128];
        ssize_t ret_size;
      
        if ((page_info = kmalloc(1024, GFP_KERNEL)) == NULL)
        {    
                printk("OOM for fw_svn_version\n");
                return 0; //none
        }    

        memset(page_info, 0, 1024);
      
        // get linux version
        memset(msg, 0, sizeof(msg));
        snprintf(msg, sizeof(msg), "%s", rtk_linux_svn_version);
        strcat(page_info, msg);
        strcat(page_info, "\n");

        // get kdriver version
        memset(msg, 0, sizeof(msg));
        snprintf(msg, sizeof(msg), "%s", rtk_kdriver_svn_version);
        strcat(page_info, msg);
        strcat(page_info, "\n");

        ret_size = sprintf(page, "%s", page_info);     

        kfree(page_info);
        return ret_size;
}
REALTEK_BOARDS_ATTR_RO(fw_svn_version);

struct kobject *realtek_boards_kobj;
EXPORT_SYMBOL(realtek_boards_kobj);

static struct attribute * realtek_boards_attrs[] = {
	&kernel_source_code_info_attr.attr,
	&bootloader_version_attr.attr,
	&board_id_attr.attr,
	&cpu_id_attr.attr,
	&tv_encoding_system_attr.attr,
#ifdef CONFIG_REALTEK_SHOW_STACK
	&task_stack_attr.attr,
#endif

//#ifdef CONFIG_BOOTUP_ANIMATION
//(defined(CONFIG_REALTEK_RESERVE_DVR) && !defined(CONFIG_REALTEK_AUTO_RECLAIM)) ||
//     defined(CONFIG_REALTEK_BOOT_UP_ANIMATION_2)
#ifdef CONFIG_BOOTUP_ANIMATION
	&reclaim_dvr_attr.attr,
#endif
//#endif
	&misc_operations_attr.attr,
//	&vout_interface_attr.attr,
	&system_parameters_attr.attr,
	&AES_CCMP_attr.attr,
	&signature_attr.attr,
	&AES_IMG_KEY_attr.attr,
	&RSA_KEY_MODULUS_attr.attr,
	&_priv__attr.attr,
	&_custom_param__attr.attr,
	&modelconfig_attr.attr,
	&update_attr.attr,
	&parent_info_attr.attr,

#ifdef CONFIG_RTK_KDRV_WATCHDOG
	&watchdog_attr.attr,
#endif

#ifdef CONFIG_RTK_KDRV_SB2
	&sb2_attr.attr,
	&sb2_dbg_attr.attr,
#endif

#ifdef CONFIG_DUMP_REGISTER
	&reg_dump_attr.attr,
#endif

#ifdef CONFIG_REALTEK_LOGBUF
        &rtdlog_attr.attr,
#endif

#ifdef CONFIG_REALTEK_ARM_WRAPPER
	&arm_wrapper_attr.attr,
#endif

#ifdef CONFIG_RTK_KDRV_QOS_CONTROL
	&rtk_qos_attr.attr,
#endif

#if defined(CONFIG_REALTEK_PCBMGR)
	&panel_parameter_attr.attr,
#endif
	&dvrfs_buffer_attr.attr,
#if defined(CONFIG_RTK_KDRV_RTICE)
	&rtice_enable_attr.attr,
#endif

	&pll_info_attr.attr,
	&scpu_voltage_attr.attr,
	&fw_git_version_attr.attr,
	&fw_svn_version_attr.attr,
	
#ifdef CONFIG_RTK_KDRV_AVCPU
#if 1//#ifdef SUPPORT_AV_NO_RELOAD
	&stravnoreload_attr.attr,
#endif
#endif
#ifdef CONFIG_REALTEK_POWER_CUT
	&power_cut_load_attr.attr,
#endif

#ifdef CONFIG_REALTEK_SCHED_LOG
	&sched_log_time_duration_attr.attr,
	&sched_log_file_start_attr.attr, // cat it will start to log file
	&sched_log_size_attr.attr, //default 6M
	&sched_log_file_stop_attr.attr,
	&sched_log_event_number_attr.attr,
	&sched_log_name_attr.attr, //default /tmp/usb/sda/sda1
#endif
	&apk_boost_mode_attr.attr,
	NULL,
	NULL
};

static struct attribute_group realtek_boards_attr_group = {
	.attrs = realtek_boards_attrs,
};

#define __LOGO_ATTR_RO(_name) { .name = __stringify(_name), .mode = 0444/*, .owner = THIS_MODULE */}

#define LOGO_ATTR_RO(_name) \
	static struct attribute _name##_attr = __LOGO_ATTR_RO(_name)

#ifdef CONFIG_PM
LOGO_ATTR_RO(showup);

static struct attribute * logo_attrs[] = {
	&showup_attr,
	NULL
};

/* This section is for updating logo image and parameters. */
#define LOGO_TARGET_ADDRESS	0xa00f0000
typedef struct logo_param {
	u32	logo_target_addr;
	u32	logo_len;
	u32	logo_reg_5370;
	u32	logo_reg_5374;
	u32	logo_reg_5378;
	u32	logo_reg_537c;
} logo_param_t;


/////static DECLARE_MUTEX(logo_param_lock);
static struct kobject logo_param_kobj;

logo_param_t logo_param = {
	.logo_target_addr	= LOGO_TARGET_ADDRESS,
	.logo_len		= 0,
	.logo_reg_5370		= 0,
	.logo_reg_5374		= 0,
	.logo_reg_5378		= 0,
	.logo_reg_537c		= 0,
};

static ssize_t logo_param_read(struct file *pfile, struct kobject *kobj, struct bin_attribute *attr,
			char *buffer, loff_t offset, size_t count)
{
	return 0;
}

static ssize_t logo_param_write(struct file *pfile, struct kobject *kobj, struct bin_attribute *attr,
			char *buffer, loff_t offset, size_t count)
{
	return 0;
}

static struct bin_attribute logo_param_attr = {
	.attr = {
		.name = "param",
		.mode = 0644,
/*		.owner = THIS_MODULE,*/
	},
	.size = 0,
	.read = logo_param_read,
	.write = logo_param_write,
};

static ssize_t logo_image_read(struct file *pfile, struct kobject *kobj, struct bin_attribute *attr,
			char *buffer, loff_t offset, size_t count)
{
	return 0;
}

static ssize_t logo_image_write(struct file *pfile, struct kobject *kobj, struct bin_attribute *attr,
			char *buffer, loff_t offset, size_t count)
{
	return 0;
}

static struct bin_attribute logo_img_attr = {
	.attr = {
		.name = "image",
		.mode = 0644,
/*		.owner = THIS_MODULE,*/
	},
	.size = 0,
	.read = logo_image_read,
	.write = logo_image_write,
};

static void logo_param_release(struct kobject *kobj) {
	return;
}

static ssize_t logo_param_show(struct kobject * kobj,
			struct attribute * attr, char * buffer) {
/* EJ: need to setup for the boot-up logo */
//	if (attr == &showup_attr) {
//		setup_boot_image();
//	}
	return 0;
}

static ssize_t logo_param_store(struct kobject * kobj,
			struct attribute * attr, const char * buffer, size_t count) {
	return 0;
}

static struct sysfs_ops logo_param_sysfs_ops = {
	.show = logo_param_show,
	.store = logo_param_store,
};

static struct kobj_type logo_param_ktype = {
	.release = logo_param_release,
	.sysfs_ops = &logo_param_sysfs_ops,
	.default_attrs = logo_attrs,
};

static int __init realtek_sysfs_logo_param_init(struct kobject *parent_kobj) {
	struct kobject *kobj;
	int err = 0;

	kobj = &logo_param_kobj;
	if ((err = kobject_init_and_add(kobj, &logo_param_ktype, parent_kobj, "logo_param"))) {
		return err;
	}
//	kobject_set_name(kobj, "logo_param");
//	kobj->ktype = &logo_param_ktype;
//	kobj->parent = parent_kobj;
//	kobj->kset = NULL;
//	if((err = kobject_register(kobj))) {
//		return err;
//	}

	if ((err = sysfs_create_bin_file(kobj, &logo_param_attr))) {
		return err;
	}

	if ((err = sysfs_create_bin_file(kobj, &logo_img_attr))) {
		return err;
	}

	return err;
}
#endif

#ifdef CONFIG_CUSTOMER_TV010
#ifdef CONFIG_RTK_KDRV_THERMAL_SENSOR
extern ssize_t rtk_monitor_active_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
extern ssize_t rtk_monitor_active_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);
extern ssize_t rtk_monitor_delay_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
extern ssize_t rtk_monitor_delay_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

static struct kobj_attribute rtk_monitor_active_attr =
    __ATTR(active, 0644, rtk_monitor_active_show, rtk_monitor_active_store);

static struct kobj_attribute rtk_monitor_delay_attr =
    __ATTR(delay, 0644, rtk_monitor_delay_show, rtk_monitor_delay_store);

static struct attribute * rtk_monitor_attrs[] = {
    &rtk_monitor_active_attr.attr,
    &rtk_monitor_delay_attr.attr,
    NULL
};

static struct attribute_group rtk_monitor_attr_group = {
    .name = "rtk_monitor",
    .attrs = rtk_monitor_attrs,
};

static int __init realtek_sysfs_rtk_monitor_init(struct kobject *parent_kobj)
{
    int err = 0;

    err = sysfs_create_group(parent_kobj, &rtk_monitor_attr_group);
    if(err) {
        printk("Realtek: sysfs init rtk_monitor failed\n");
        return err;
    }

    return err;
}
#endif
#endif

static int __init realtek_boards_sysfs_init(void)
{
	int error;

	realtek_boards_kobj = kobject_create_and_add("realtek_boards", NULL);

	if(!realtek_boards_kobj)
		return -ENOMEM;
	error = sysfs_create_group(realtek_boards_kobj, &realtek_boards_attr_group);
	if(error) {
		kobject_put(realtek_boards_kobj);
		return error;
	}

#ifdef CONFIG_PM
	realtek_sysfs_logo_param_init(realtek_boards_kobj);
#endif

 #if defined(CONFIG_REALTEK_PCBMGR)
	realtek_sysfs_pcb_enum_dir_init(realtek_boards_kobj);
#endif

#ifdef CONFIG_CUSTOMER_TV010
#if defined(CONFIG_RTK_KDRV_THERMAL_SENSOR)
    realtek_sysfs_rtk_monitor_init(realtek_boards_kobj);
#endif
#endif
	printk("Realtek: sysfs init done\n");

 	return 0;
}


arch_initcall(realtek_boards_sysfs_init);

EXPORT_SYMBOL(pcb_mgr_get_enum_info_byname);
