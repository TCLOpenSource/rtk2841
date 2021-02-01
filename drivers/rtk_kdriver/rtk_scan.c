/*
 * Dora DDR test 
 *
 * Copyright (C) 2017 Realtek
 *
 */

/* product ID::
 * LxE K3  0
 * COMMON  1
 * LxE K*  2
 * SKYW    3
 * others  ?
 */
#define PRODUCT_ID 1
#define SCAN_DRV_VER  1  //later than k3*
#define _VER(prod_id, drv_ver)  ((((prod_id) & 0x0ff)<<0x8) | (((drv_ver) & 0x0ff)))

#define VERSION() _VER(PRODUCT_ID, SCAN_DRV_VER)
#define pr_fmt(fmt) "rtk_dmscan: " fmt


///////////register interface ///////////////////
/* these register should be depended on CHIP ID.
 * 
 */
#if defined(CONFIG_ARCH_RTK289X)
/* Command register: */
/* 0xb80083D0[29:28] => 0: test off; 1: test on; 2: return fail address; 3: return fail data */
/* Status register: */
/* 0xb8060124 [7:0] for error status; [31:0] for return fail address or fail data */
#define DMSCAN_CMD_REG  (0xb80083D0)
#define APP_CMD_REG  (0xb80083D0)
#define DMSCAN_STATUS_REG  (0xb8060124)
#define DMSCAN_UPDATE_STATUS(status)					\
	do {								\
		rtd_maskl(DMSCAN_STATUS_REG, ~(0x0ff<<0), (!!(status))<<0); \
	} while(0)

#define RTK_CMDREG_IRQ  IRQ_CPU2CPU

/* take use of ACPU2-to-SCPU interrupt */
/* Module::sb2	Register::CPU_INT_EN	Set::1	ATTR::ctrl	Type::SR	ADDR::0x1801_A108 */
#define CMDREG_INT_EN_REG 0xb801A108
#define CMDREG_INT_EN_BIT 26   //a2->s interrupt enable

/* Module::sb2	Register::CPU_INT	Set::1	ATTR::nor	Type::SR	ADDR::0x1801_A104 */
#define CMDREG_INT_REG 0xb801A104
#define CMDREG_INT_BIT 26 //a2-s   int

#else //#if defined(CONFIG_ARCH_RTK289X)    //284x, and later

/* Command register: */
/* 0xb8008EB4[29:28] => 0: test off; 1: test on; 2: return fail address; 3: return fail data */
/* Status register: */
/* 0xb8008EB8[23:16] for error status; [31:0] for return fail address or fail data */
#define DMSCAN_CMD_REG  (0xb8008EB4)
#define APP_CMD_REG  (0xb8008EB4)
#define DMSCAN_STATUS_REG  (0xb8008EB8)
#define DMSCAN_UPDATE_STATUS(status)					\
	do {								\
		rtd_maskl(DMSCAN_STATUS_REG, ~(0x0ff<<16), (!!(status))<<16); \
	} while(0)


#define RTK_CMDREG_IRQ  IRQ_CPU2CPU

/* take use of ACPU2-to-SCPU interrupt */
/* Module::sb2	Register::CPU_INT_EN	Set::1	ATTR::ctrl	Type::SR	ADDR::0x1801_A108 */
#define CMDREG_INT_EN_REG 0xb801A108
#define CMDREG_INT_EN_BIT 13   //k->s interrupt enable

/* Module::sb2	Register::CPU_INT	Set::1	ATTR::nor	Type::SR	ADDR::0x1801_A104 */
#define CMDREG_INT_REG 0xb801A104
#define CMDREG_INT_BIT 13 //k-s   int

#endif //


//////////////////////////////////////////////////////////////////
#include <linux/mm.h>
#include <linux/cpu.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/smpboot.h>
#include <linux/sched/rt.h>
#include <linux/tick.h>
#include <linux/dma-mapping.h>
#include <linux/kthread.h>
#include <linux/gfp.h>
#include <linux/interrupt.h>
#include <asm/delay.h>
#include "rbus/sb2_reg.h"
//#include "rtk_semaphore.h"
//#include "rtk_kdriver/io.h"


/* this file provide a low priority thread and 2 interfaces:
 * 1) low priority thread: DM scan state machine.
 * 2) a register interface with IRQ trigger. (shared IRQ with A2S interrupt).
 * 3) /proc interface.
 * 
 * the status/action is isolated for easy query by 2 interfaces.
 * - status simply queried by interfaces.
 */

static DEFINE_MUTEX(dmscan_mutex);

static int dmscan_running;
static int dmscan_status = -1;
static int dmscan_forever = 1; //no stop 
static u64 dmscan_due; //// dmscan test due time


static DECLARE_BITMAP(dmscan_cpumask_bits, CONFIG_NR_CPUS) = CPU_BITS_ALL;
static struct cpumask *dmscan_cpumask = to_cpumask(dmscan_cpumask_bits);


static int dmscan_set_cpumask(char *s);
__setup("dmscan", dmscan_set_cpumask);


/* Helper for online, unparked cpus. */
#define for_each_dmscan_cpu(cpu)					\
	for_each_cpu_and((cpu), cpu_online_mask, dmscan_cpumask)

int dmscan_update_status(int cpu);
int dmscan_clear_status(void);


/*
 * 1) 'dmscan_state' denotes whether dmscan thread is running.
 *   - also provide user interface to start/stop again.
 * 2) 'dmscan_period' the scan period is 30 seconds, if dmsca_forever is zero.
 */
static DEFINE_PER_CPU(int, dmscan_state); //// START, STOP
static DEFINE_PER_CPU(int, dmscan_result); //// dmscan test per-cpu result
static DEFINE_PER_CPU(void *, dmscan_area); //// dmscan test per-cpu sand box
static DEFINE_PER_CPU(dma_addr_t, dmscan_area_phys); //// handler of sand box.
static DEFINE_PER_CPU(struct task_struct *, dmscan_task); //to store task_struct ptr of per-cpu kthread

///////////////////////

enum { DMSCAN_STOP = 0, DMSCAN_START = 1 };


static void dmscan_pcpu_set_prio(unsigned int policy, unsigned int prio)
{
	struct sched_param param = { .sched_priority = prio };

	sched_setscheduler(current, policy, &param);
}

static void dmscan_pcpu_set_state(unsigned int cpu, int state)
{
	*per_cpu_ptr(&dmscan_state, cpu) = state;
}

#define __unused __attribute__ ((unused))
__unused  static void dmscan_pcpu_start(unsigned int cpu) 
{
	pr_debug("%s \n", __FUNCTION__);
	dmscan_pcpu_set_state(cpu, DMSCAN_START);
}

static void dmscan_pcpu_stop(unsigned int cpu)
{
	pr_debug("%s \n", __FUNCTION__);
	dmscan_pcpu_set_state(cpu, DMSCAN_STOP);
}

static void dmscan_pcpu_setup(unsigned int cpu)
{
	void *ptr;
	dma_addr_t phys_addr;

	pr_debug("%s(%d), dmscan_area: 0x%p\n", __FUNCTION__, cpu,  per_cpu(dmscan_area, cpu));
	if (!per_cpu(dmscan_area, cpu)) {
		ptr = dma_alloc_coherent(NULL, PAGE_SIZE, &phys_addr, GFP_HIGHUSER);
		if (!ptr)
			return;
		
		preempt_disable();
		per_cpu(dmscan_area, cpu) = ptr;
		per_cpu(dmscan_area_phys, cpu) = phys_addr;
		preempt_enable();
	}

	per_cpu(dmscan_result, cpu) = 0;
	
	//lowest priority.
	dmscan_pcpu_set_prio(SCHED_NORMAL, MAX_NICE);
}


static void dmscan_pcpu_cleanup(unsigned int cpu, bool online)
{
	void *ptr = per_cpu(dmscan_area, cpu);
	dma_addr_t phys_addr = per_cpu(dmscan_area_phys, cpu);

	pr_debug("%s(%d), dmscan_area: 0x%p\n", __FUNCTION__, cpu,  per_cpu(dmscan_area, cpu));
	if (ptr) {
		per_cpu(dmscan_area, cpu) = NULL;
		dma_free_coherent(NULL, PAGE_SIZE, ptr, phys_addr);
	}
}


static int dmscan_pcpu_should_run(unsigned int cpu)
{
	return (__this_cpu_read(dmscan_state) != DMSCAN_STOP);
}


#define DC_BURST_LEN (32) //half burt len
#define DC(addr) ((((unsigned long)(addr) /512) & 1) + 1)  //index of DC , starting from 1.
#define DDR(addr) ((((unsigned long)(addr) /16) & 3) + 1)  //index of DDR , starting from 1.
#define BYTE(addr) ({ unsigned long __p = (unsigned long)(addr); __p %= 16; __p=(((__p&(1<<3))>>2)|(__p&1)) + 1; })  //index of BYTE , starting from 1.

const char test_pattern[] = { 0x00, 0xff, 0x01, 0xfe, 0x3, 0xfc, 0x7, 0xf1, 0x0f, 0xf0, 0x1f, 0xe0, 0x3f, 0xc0, 0x7f, 0x80, 0xff, 0x00};

/*
 * The dmscan thread function .
 *
 */
static void dmscan_pcpu_fn(unsigned int cpu)
{
	volatile char *p, c; 
	int result = 0;
	int ofs;
	int i;
	int dm_statistic_rec[2][2];
	int pat_size = sizeof(test_pattern) / sizeof(char);
	void *area = __this_cpu_read(dmscan_area);
	int size = PAGE_SIZE;

	// resize to DC_BURST_LEN aligned
	int mod = size / DC_BURST_LEN;

	pr_debug("%s(%d), dmscan_area: 0x%p, due:%llu, %llu, %d \n",
		 __FUNCTION__, cpu,  per_cpu(dmscan_area, cpu),
		 dmscan_due, jiffies_64, !!time_is_before_jiffies((unsigned long)dmscan_due));
	
	if (!area)
		return;

	if ((dmscan_forever == 0) && time_is_before_jiffies((unsigned long)dmscan_due)) {
		//dmscan_pcpu_stop(cpu);
		kthread_park(current);
		return;
	}

	// write test pattern
	for (ofs = 0; ofs < DC_BURST_LEN; ofs++) {
		p = ((char *)area) + ofs;
		
		for (i=0; i < mod; i++, p+= DC_BURST_LEN)  {
			*(volatile char *)p = test_pattern[ofs % pat_size];
			dma_wmb();
		}
	}


	//read back to check
	p = (char *)area;
	for (ofs = 0, i = 0; i < size; i++, p++, ofs= (ofs+1) % DC_BURST_LEN) {
		if ((c = *(volatile char *)p) != test_pattern[ofs % pat_size]) {
			pr_debug("\ndmscan(%x): addr:0x%08lx, data:0x%08x(again: 0x%08x) \n",
				 ofs, (long)p, c, *(volatile char *)p);

			result++;

			dm_statistic_rec[ DC(p)-1 ][ BYTE(p)-1 ] ++;
			pr_debug("DC(%d) BYTE(%d): %d \n", 1, 1, dm_statistic_rec[0][0]);
			pr_debug("DC(%d) BYTE(%d): %d \n", 1, 2, dm_statistic_rec[0][1]);
			pr_debug("DC(%d) BYTE(%d): %d \n", 2, 1, dm_statistic_rec[1][0]);
			pr_debug("DC(%d) BYTE(%d): %d \n", 2, 2, dm_statistic_rec[1][1]);
		}
	}

	__this_cpu_add(dmscan_result, result);

	//update result register
	dmscan_update_status(cpu);
	
	return;
}




static struct smp_hotplug_thread dmscan_threads = {
	.store			= &dmscan_task,
	.thread_should_run	= dmscan_pcpu_should_run,
	.thread_fn		= dmscan_pcpu_fn,
	.thread_comm		= "dmscan_pcpu/%u",
	.create			= dmscan_pcpu_start,
	.setup			= dmscan_pcpu_setup,
	.cleanup		= dmscan_pcpu_cleanup,
	.park			= dmscan_pcpu_stop,
	.unpark			= dmscan_pcpu_start,
};


//////////////////////////////////////////////////////////////////


static int dmscan_park_threads(void)
{
	int cpu, ret = 0;

	pr_debug("%s\n", __FUNCTION__);
	
	for_each_dmscan_cpu(cpu) {
		ret = kthread_park(per_cpu(dmscan_task, cpu));
		if (ret)
			break;
	}

	return ret;
}

static void dmscan_unpark_threads(void)
{
	int cpu;

	pr_debug("%s\n", __FUNCTION__);

	for_each_dmscan_cpu(cpu)
		kthread_unpark(per_cpu(dmscan_task, cpu));
}

////////// status implementation/////////////////
static void rtd_hwsem_2_lock(void);
static void rtd_hwsem_2_unlock(void);

int dmscan_update_status(int cpu)
{
	int cpu_result = per_cpu(dmscan_result, cpu);

	if (dmscan_status ^ cpu_result) {
		mutex_lock(&dmscan_mutex);
		dmscan_status |= cpu_result;

		/* fixme */
		rtd_hwsem_2_lock();
		DMSCAN_UPDATE_STATUS(dmscan_status);
		rtd_hwsem_2_unlock();
	
		mutex_unlock(&dmscan_mutex);
	}
	pr_debug("%s: cpu:%d, 0x%x, status:0x%x \n",
		 __FUNCTION__, cpu, cpu_result, dmscan_status);

	return 0;
}

int dmscan_clear_status(void)
{
	int cpu;

	dmscan_status = 0;
	for_each_dmscan_cpu(cpu) {
		per_cpu(dmscan_result, cpu) = 0;
	}

	pr_debug("%s: \n", __FUNCTION__);

	return 0;
}

int dmscan_get_status(void)
{
	return dmscan_status;
}


/** 
 * '0' to denote as disabled cpu.
 * otherwise, a integer to denote cpu bitmask enabled.
 **/
static int dmscan_set_cpumask(char *s)
{
	unsigned long bits_cpu;
	
	pr_info("%s, %s,(0x%0lx)\n", __FUNCTION__, s, *dmscan_cpumask_bits);

	if (dmscan_running != 0) {
		pr_err("dmscan is running \n");
		return -EBUSY;
	}

	if (kstrtoul(s, 0, &bits_cpu)) {
		pr_err("ignore invalid default state: %s \n", s);
		return 0;
	}

	bitmap_copy(dmscan_cpumask_bits,  &bits_cpu, NR_CPUS);

	return 0;
}


//////////////////////////
static int update_dmscan_all_cpus(void)
{
	int ret;

	pr_debug("%s\n", __FUNCTION__);

	ret = dmscan_park_threads();
	if (ret) {
		pr_err("cannot stop all dmscan \n"); //fixme
		return ret;
	}
	
	dmscan_unpark_threads();

	return 0;
}

static void dmscan_disable_all_cpus(void)
{
	pr_debug("%s\n", __FUNCTION__);

	if (dmscan_running) {
		dmscan_running = 0;
		smpboot_unregister_percpu_thread(&dmscan_threads);
		//dmscan_park_threads();
	}
}


static int dmscan_enable_all_cpus(void)
{
	int err = 0;

	pr_debug("%s: running:%d cpumask:0x%lx\n", __FUNCTION__, dmscan_running, *dmscan_cpumask_bits);

	/* clear status */
	dmscan_clear_status();

	if (!dmscan_running) {
		/* int cpu; */
		
		/* //for test, set start state */
		/* for_each_dmscan_cpu(cpu)  */
		/* 	dmscan_pcpu_start(cpu); */
		
		err = smpboot_register_percpu_thread_cpumask(&dmscan_threads,
							     dmscan_cpumask);
		if (err)
			pr_err("Failed to create dmscan threads, disabled\n");
		else 
			dmscan_running = 1;
	} else {
		err = update_dmscan_all_cpus();

		if (err) {
			dmscan_disable_all_cpus();
			pr_err("Failed to update dmscan threads, disabled\n");
		}
	}

	if (!err)
		dmscan_due = jiffies_64 + 30*HZ;

	return err;
}


///////// the control interface   /////////
ssize_t dmscan_cmd_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%u\n", dmscan_running);
}

enum {CMD_STOP=0, CMD_START=1};
ssize_t dmscan_cmd_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	unsigned long cmd;
	
	if ((sscanf(buf, "0x%lx", &cmd) != 1) && (sscanf(buf, "%ld", &cmd) != 1)) {
		pr_info("wrong cmd.\n");
		return -EINVAL;
	}
		
	if (cmd == CMD_STOP)
		dmscan_disable_all_cpus();
	else	
		dmscan_enable_all_cpus();

	return count;
}

ssize_t dmscan_status_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "0x%08x\n", dmscan_get_status());
}


/* fixme, should we have this API ?*/
ssize_t dmscan_status_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	mutex_lock(&dmscan_mutex);
	dmscan_status = 0;
	mutex_unlock(&dmscan_mutex);

	return count;
}

ssize_t dmscan_cpumask_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	char bits[10];
	int ret;

	ret = sscanf(buf, "%9s", bits);
	if (ret != 1)
		return -EINVAL;

	dmscan_set_cpumask(bits);

	return count;
}

ssize_t dmscan_cpumask_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "0x%08lx\n", *dmscan_cpumask_bits);
}





static struct kobj_attribute dmscan_cmd_attr =
	__ATTR(cmd, 0644, dmscan_cmd_show, dmscan_cmd_store);

static struct kobj_attribute dmscan_status_attr =
	__ATTR(status, 0644, dmscan_status_show, dmscan_status_store);

static struct kobj_attribute dmscan_cpumask_attr =
	__ATTR(cpumask, 0644, dmscan_cpumask_show, dmscan_cpumask_store);


static struct attribute *dmscan_attrs[] = {
	&dmscan_cmd_attr.attr,
	&dmscan_status_attr.attr,
	&dmscan_cpumask_attr.attr,
	NULL,
};

static struct attribute_group dmscan_attr_group = {
	.attrs = dmscan_attrs,
};

static struct kobject *ddr_kobj;
static struct kobject *dmscan_kobj;

int cmdreg_register_isr(void);

int __init dmscan_init(void)
{
	int ret;

	pr_debug("%s\n", __FUNCTION__);

	
	cmdreg_register_isr();

	// default enable all cpu 
	//dmscan_enable_all_cpus();

	if (!ddr_kobj)
		ddr_kobj = kobject_create_and_add("ddr", NULL);

	if (!ddr_kobj) {
		pr_info("no board object, cannot create dmscan sysfs control \n");
		return -EEXIST;
	}


	dmscan_kobj = kobject_create_and_add("dmscan", ddr_kobj);
	if (!dmscan_kobj) {
		pr_info("fail to create dmscan sysfs control \n");
		return -EFAULT;
	}
	
	ret = sysfs_create_group(dmscan_kobj, &dmscan_attr_group);
	if (!ret)
		return -EFAULT;

	kobject_put(dmscan_kobj);
	return 0;
}


// after arch_initcall(realtek_boards_sysfs_init)
fs_initcall(dmscan_init);


/////////////// cmdreg interface /////////////////////////////////

int cmdreg_dmscan_handler(int reg, int data)
{
	int cmd;
	
	if (reg != DMSCAN_CMD_REG)
		return -1;

	
	cmd = (data >> 28) & 0x3;

	if (cmd == 1)
		dmscan_enable_all_cpus();
	else if (cmd == 0)
		dmscan_disable_all_cpus();
	/* this command is supported from SCAN_DRV_VER=1. */
#if (SCAN_DRV_VER > 0)	
	else if (cmd == 2)
		/* fixme, skip hw_semaphore protection. this should be first use. */
		rtd_outl(DMSCAN_STATUS_REG, VERSION());
#endif //#if (SCAN_DRV_VER > 0)	

	return 0;
}




//////////////// CMDREG ISR mechanism ////////////////////

typedef int (*cmdreg_handler_t)(int, int);


struct cmdreg_struct_t {
	int reg;
	cmdreg_handler_t handler;
	int data;
	int tag;
};




int cmdreg_app_handler(int reg, int data);
	
/* noted, end entite is reg=0 */
struct cmdreg_struct_t cmdreg_table[] = {
	{ DMSCAN_CMD_REG, cmdreg_dmscan_handler, 0, 0},
	{ APP_CMD_REG, cmdreg_app_handler, 0, 0},
	{ 0 },
};

#define CMDREG_TABLE_SIZE (sizeof(cmdreg_table)/sizeof(cmdreg_table[0]))

irqreturn_t cmdreg_thread_fn(int irq, void *dev_id)
{
	struct cmdreg_struct_t *t = cmdreg_table;

	while (t->reg != 0) {
		if (t->tag != 0) {
			int ret;
		
			pr_debug("%s: t.reg(0x%0x), data(0x%0x), tag(0x%0x) \n", __FUNCTION__, t->reg, t->data, t->tag);
			ret = t->handler(t->reg, t->data);
			t->tag = 0;
		}
		
		t++;
	}

	return IRQ_HANDLED;
}

/* check if any registers are changed, and tagged as 1 */
irqreturn_t cmdreg_isr(int irq, void *dev_id)
{
	int int_probe = 0;
	struct cmdreg_struct_t *t = cmdreg_table;

	pr_debug("%s: irq(%d), int(0x%0x) \n", __FUNCTION__, irq, rtd_inl(CMDREG_INT_REG));
	
	if (irq != RTK_CMDREG_IRQ)
		return IRQ_NONE;

#if (SCAN_DRV_VER < 1)  // shared IRQ may be ack-ed by another ISR.
	
	if ((rtd_inl(CMDREG_INT_REG) & (1<<CMDREG_INT_BIT)) == 0)
		return IRQ_NONE;
	
#else //#if (SCAN_DRV_VER < 1)	

	/* use CMD_REG[31] as fake interrupt status, 
	 * to avoid conflict of sharing IRQ with RPC 
	 */
	if (!(rtd_inl(DMSCAN_CMD_REG) & (1<<31)))
		return IRQ_NONE;

	int_probe ++;
	// this is to ack fake interrupt.
	rtd_maskl(DMSCAN_CMD_REG, ~(1<<31), 0);
	
#endif //#if (SCAN_DRV_VER < 1)
	
	while (t->reg != 0) {
		int data = rtd_inl(t->reg);
		
		pr_debug("%s: t.reg(0x%0x), data(0x%0x), last_data(0x%0x) \n", __FUNCTION__, t->reg, data, t->data);
		if (data != t->data) {
			int_probe ++;
			t->data = data;
			t->tag = 1;
		}

		t++;
	}

	if (int_probe == 0)
		return IRQ_NONE;

	//ack
	rtd_outl(CMDREG_INT_REG, (1<<CMDREG_INT_BIT));

	//ask thread context
	return IRQ_WAKE_THREAD;
}

int cmdreg_register_isr(void)
{
	int ret = 0;
	
	ret = request_threaded_irq(RTK_CMDREG_IRQ, cmdreg_isr, cmdreg_thread_fn, IRQF_SHARED, "cmdreq", (void *)0x2266);
	if (ret) {
		pr_err("%s: can not register cmdreg irq (ret:%d) \n", __FUNCTION__, ret);
	}

	//enable int_en
	rtd_outl(CMDREG_INT_EN_REG, ((1<<CMDREG_INT_EN_BIT) | 1));

	return 0;
}



///////////////// misc. /////////////////
#if !defined (RTK_SEMAPHORE_H)

/* Notice: this API is semantically diff from hw_semaphore_try_lock.
 * return 1: get lock
 * return 0: not get lock.
 */
static int rtd_hwsem_2_trylock(void)
{
	int ret;
	ret =  (*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_2_reg));
	return ret;
}


static void rtd_hwsem_2_lock(void)
{
	while (!rtd_hwsem_2_trylock()) {
		udelay(5);
	}
}

static void rtd_hwsem_2_unlock(void)
{
	*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_2_reg) = 0;
	dsb(sy);
}


#else
static void rtd_hwsem_2_lock(void)
{
	rtd_hwsem_lock(MAKE_SEMA_UUID(SWSEM_2, SEM_SCPU, NUM0, 0));
}

static void rtd_hwsem_2_unlock(void)
{
	rtd_hwsem_unlock(MAKE_SEMA_UUID(SWSEM_2, SEM_SCPU, NUM0, 0));
}

#endif 



//////// export rtk_scan device for command register monitor ////////

atomic_t cmdreg_completion = ATOMIC_INIT(0);
unsigned int app_cmd;
int cmdreg_app_handler(int reg, int data)
{
	
	if (reg != APP_CMD_REG)
		return -1;

	
	app_cmd = (data & 0xff000);

	atomic_set(&cmdreg_completion, 1);
	sysfs_notify(ddr_kobj, NULL, "cmdreg");
	
	pr_debug("%s: reg(0x%0x), data(0x%0x) \n", __FUNCTION__, reg, data);

	return 0;
}

static ssize_t cmdreg_app_read(struct file *f, struct kobject *kobj, struct bin_attribute *attr, char *buf, loff_t pos, size_t size)
{
	int ret = atomic_read(&cmdreg_completion);

	if (!ret) 
		return 0;
	
	/* return cmdreg in format of binary */
	*(unsigned int *)buf = app_cmd; //fixme, aligned to 4 ?

	atomic_set(&cmdreg_completion, 0);
	return 4;

}

static ssize_t cmdreg_app_write(struct file *f, struct kobject *kobj, struct bin_attribute *attr, char *buf, loff_t pos, size_t count)
{
	int val;
	
	/* return cmdreg in format of binary */
	val = *(unsigned int *)buf; //fixme, aligned to 4 ?


	/* write back to rbus */
	rtd_outl(APP_CMD_REG, val);
	
	return count;
}



static struct bin_attribute cmdreg_app_attr =
	__BIN_ATTR(cmdreg, 0644, cmdreg_app_read, cmdreg_app_write, 0);


static struct bin_attribute *attrs[] = {
	&cmdreg_app_attr,
	NULL,	/* need to NULL terminate the list of attributes */
};

static struct attribute_group attr_group = {
	 .bin_attrs = attrs,
};


static int __init cmdreg_init(void)
{
	int retval;

	if (!ddr_kobj)
		ddr_kobj = kobject_create_and_add("ddr", NULL);
	
	if (!ddr_kobj)
		return -ENOMEM;

	retval = sysfs_create_group(ddr_kobj, &attr_group);
	if (retval)
		kobject_put(ddr_kobj);


	return retval;
}


module_init(cmdreg_init);

