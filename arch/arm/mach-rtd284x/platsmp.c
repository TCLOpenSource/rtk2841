/*
 *  linux/arch/arm/bsp/mach/platsmp.c
 *
 *  Copyright (C) 2012 Realtek
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/jiffies.h>
#include <linux/smp.h>
#include <linux/io.h>
#include <linux/cpu.h>
#include <linux/reboot.h>

#include <asm/cacheflush.h>
//#include <asm/localtimer.h>
#include <asm/smp_scu.h>
#include <asm/smp.h>
#include <asm/unified.h>
#include <mach/system.h>
#include <mach/common.h>
#include <mach/smp.h>
#include <linux/vmalloc.h>
#include <mach/platform.h>

//32 bits dummy reg
//b[0 : 7] save cpu2's power on status
//b[8 :15] save cpu3's power on status
//b[16:23] save cpu2's power off status
//b[24:31] save cpu3's power off status
static unsigned int rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
	unsigned int X,A,result;
	X=(1<<(endBit-startBit+1))-1;
	A=rtd_inl(reg_addr);
	result = (A & (~(X<<startBit))) | (value<<startBit);
	rtd_outl(reg_addr,result);
	return 0;
}

void write_pm_dummy_register(int cpu,int pwr_status,int code)
{
	if(code > 256)
		return;

	if(cpu==2)
	{
		if(pwr_status)
			rtd_part_outl(0xb801a610,7,0,code);

		else
			rtd_part_outl(0xb801a610,23,16,code);
	}
	if(cpu==3)
	{
		if(pwr_status)
			rtd_part_outl(0xb801a610,15,8,code);

		else
			rtd_part_outl(0xb801a610,31,24,code);
	}
}

#ifdef CONFIG_REALTEK_POWER_CUT
#ifdef CONFIG_ARCH_RTK299S
unsigned int *cci_remap=NULL;
static void *rtk_ioremap(unsigned long phys_addr, size_t size)
{
        struct vm_struct *area;
        unsigned long addr;
        area = get_vm_area_caller(size, VM_IOREMAP, __builtin_return_address(0));

        if (!area)
                return NULL;

        addr = (unsigned long)area->addr;
        area->phys_addr = phys_addr;
        if (ioremap_page_range(addr, addr + size, area->phys_addr, pgprot_rtk_device(pgprot_kernel))) {
                vunmap((void *)addr);
                return NULL;
        }

        return (void *)addr;
}
#endif

#ifdef CONFIG_ARCH_RTK299S
#define POWER_DOWN_CLUSTER
#endif
void disable_cpu1(void)
{
       while((rtd_inl(0xB805B83C) & (0x1 << 6)));  //mark sure SMP disabled of cpu1
       while(!(rtd_inl(0xB805B83C) & 0x04)); //make sure core is in WFI mode of cpu1

       rtd_outl(0xB805B828, rtd_inl(0xB805B828) & (~(1<<16))); // disable externel dbg interface of cpu1
       rtd_outl(0xb805b054,rtd_inl(0xb805b054) & (~((1<<9) |  (1<<11)))); // deassert CORST & PORCORST of cpu2

       rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<29));  // enable clamp of cpu1
       rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<31))); // power  down cpu1

       while((rtd_inl(0xb805b458) & (1<<31))!=0);

       // cpu1 sram power down
       rtd_outl(0xb805b43c,rtd_inl(0xb805b43c) | (1<<26));
}


void disable_cpu2(void)
{
	write_pm_dummy_register(2,0,1);
	while((rtd_inl(0xb805b89c) & (0x1 << 9)));
	write_pm_dummy_register(2,0,2);
	while(!(rtd_inl(0xb805b89c) & 0x02));
	write_pm_dummy_register(2,0,3);

	rtd_outl(0xB805B888, rtd_inl(0xB805B888) & (~(1<<15))); // disable externel dbg interface.

	rtd_outl(0xb805b054,rtd_inl(0xb805b054) & (~((1<<6) | (1<<4)))); // deassert CORST & PORCORST
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<22));  // enable clamp
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<24))); // power down
	write_pm_dummy_register(2,0,4);

	while((rtd_inl(0xb805b458) & (1<<27))!=0);
	write_pm_dummy_register(2,0,5);

	// ca57 core0 sram power down
	rtd_outl(0xb805b43c,rtd_inl(0xb805b43c) | (1<<20));
	write_pm_dummy_register(2,0,6);
 }

void disable_cpu3(void)
{
	write_pm_dummy_register(3,0,1);
	while((rtd_inl(0xb805b89c) & (0x1 << 10)));  // make sure SMP is disable
	write_pm_dummy_register(3,0,2);
	while(!(rtd_inl(0xb805b89c) & 0x04)); // make sure core is in WFI mode.
	write_pm_dummy_register(3,0,3);
	rtd_outl(0xB805B888, rtd_inl(0xB805B888) & (~(1<<16)));  // disable externel dbg interface.
	rtd_outl(0xb805b054,rtd_inl(0xb805b054) & (~((1<<5) | (1<<3)))); // deassert CORST & PORCORST
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<23)); // enable clamp
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<25))); // power down
	write_pm_dummy_register(3,0,4);
	while((rtd_inl(0xb805b458) & (1<<28))!=0);
	write_pm_dummy_register(3,0,5);

	// ca57 core1 sram power down
	rtd_outl(0xb805b43c,rtd_inl(0xb805b43c) | (1<<19));
	write_pm_dummy_register(3,0,6);

}

void cluster_top_power_on(void)
{
#ifndef POWER_DOWN_CLUSTER
	return;
#endif

#ifdef CONFIG_ARCH_RTK299S

	if(!(rtd_inl(0xb805b43c) & 1<<20))
		return;

	if(!(rtd_inl(0xb805b43c) & 1<<19))
		return;

	// ca57 top sram power up
	rtd_outl(0xb805b43c,(rtd_inl(0xb805b43c) & (~(1<<18))));

	rtd_outl(0xb805b450, rtd_inl(0xb805b450) | (1<<21)); // top power

	while((rtd_inl(0xb805b458) & (1<<26)) ==0);
	rtd_outl(0xb805b450, rtd_inl(0xb805b450) & (~(1<<20))); //top clamp
	rtd_inl(0xb805b89c);

	rtd_outl(0xb805b054, rtd_inl(0xb805b054) | (1<<1));//nPRESETDBG
	rtd_outl(0xb805b054, rtd_inl(0xb805b054) | (1<<2)); //nL2RESET

	rtd_outl(0xb805b880,0); // snoop enable
	if(cci_remap==NULL)
	{
		cci_remap=rtk_ioremap(0x180a5000,0x1000);
		printk("cci_remap:%x\n",cci_remap);
	}

	//rtd_outl(0xb80a5000,0xc0000003);//restore CCI setting
	writel(0xc0000003,cci_remap);
#endif
}

void enable_cpu1(void)
{
       rtd_outl(0xb805b43c,(rtd_inl(0xb805b43c) & (~(1<<26)))); //enable cpu1 sram
       rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<31)); //enable cpu1 power

       while((rtd_inl(0xb805b458) & (1<<31)) ==0);//check power status  ready

       rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<29))); //enable  cpu1 clamp

       rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<11));
       rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<9));
       {
               // Add Delay
               unsigned int  i;
               for(i=0; i<0x1000; i++)  {  asm volatile("nop"); }
       }

       rtd_outl(0xB805B828, rtd_inl(0xB805B828) | ((1<<16)));//enable  externel dbg interface of cpu2

}

void enable_cpu2(void)
{
	write_pm_dummy_register(2,1,0);
	rtd_outl(0xb805b43c,(rtd_inl(0xb805b43c) & (~(1<<20))));
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<24));
	write_pm_dummy_register(2,1,1);

	while((rtd_inl(0xb805b458) & (1<<27)) ==0);
	write_pm_dummy_register(2,1,2);

	rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<22)));
	rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<6));
	rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<4));
	{
		// Add Delay
		unsigned int  i;
		for(i=0; i<0x1000; i++)  {  asm volatile("nop"); }
	}
	write_pm_dummy_register(2,1,3);
	rtd_outl(0xB805B888, rtd_inl(0xB805B888) | ((1<<15)));
	write_pm_dummy_register(2,1,4);

 }

void enable_cpu3(void)
{
	write_pm_dummy_register(3,1,0);
	rtd_outl(0xb805b43c,(rtd_inl(0xb805b43c) & (~(1<<19))));
	rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<25));
	write_pm_dummy_register(3,1,1);

	while((rtd_inl(0xb805b458) & (1<<28)) ==0);
	write_pm_dummy_register(3,1,2);

	rtd_outl(0xb805b450,rtd_inl(0xb805b450) & (~(1<<23)));
	rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<5));
	rtd_outl(0xb805b054,rtd_inl(0xb805b054) | (1<<3));
	{
		// Add Delay
		unsigned int  i;
		for(i=0; i<0x1000; i++)  {  asm volatile("nop"); }
	}
	write_pm_dummy_register(3,1,3);
	rtd_outl(0xB805B888, rtd_inl(0xB805B888) | ((1<<16)));
	write_pm_dummy_register(3,1,4);
}

static void cluster_power_down_top(void)
{
#ifndef POWER_DOWN_CLUSTER
	return;
#endif

#ifdef CONFIG_ARCH_RTK299S
	if(!(rtd_inl(0xb805b43c) & 1<<20))
		return;

	if(!(rtd_inl(0xb805b43c) & 1<<19))
		return;

	if(cci_remap==NULL)
	{
		cci_remap=rtk_ioremap(0x180a5000,0x1000);
		printk("cci_remap:%x\n",cci_remap);
	}

	writel(0,cci_remap);
	rtd_outl(0xb805b880, 2); //L2 Flush
	while((rtd_inl( 0xb805b89c) & (1<< 11)) !=(1<<11));

	rtd_outl(0xb805b880, 0);	//Enable Snoop ?
	while((rtd_inl( 0xb805b89c) & (1<< 11)) !=0);

	rtd_outl(0xb805b880, 1);	//Disable Snoop
	while((rtd_inl( 0xb805b89c) & (1<< 0)) !=(1<<0));

	rtd_outl(0xb805b054,rtd_inl(0xb805b054) &  (~((1<<1) | (1<<2)))); //assert nPRESETDBG, nL2RESET to low

	rtd_outl(0xb805b450,rtd_inl(0xb805b450)&(~1<<21));//a57 top logic power

	rtd_outl(0xb805b450,rtd_inl(0xb805b450) | (1<<20)); // a57 top clamp

	while((rtd_inl(0xb805b458) & (1<<26))!=0);

	// ca57 top sram power down
	rtd_outl(0xb805b43c,rtd_inl(0xb805b43c) | (1<<18));
#endif
}

void cluster_power_down_flush(void)
{
        cluster_power_down_top();
}
#else

#define cluster_power_down_flush()
#define cluster_power_down_top()
#define enable_cpu2()
#define enable_cpu3()
#define disable_cpu2()
#define disable_cpu3()
#define cluster_top_power_on()
#endif

/*
 * Write pen_release in a way that is guaranteed to be visible to all
 * observers, irrespective of whether they're taking part in coherency
 * or not.  This is necessary for the hotplug code to work reliably.
 */
static void write_pen_release(int cpu)
{
	pen_release = cpu;
	smp_wmb();
	__cpuc_flush_dcache_area((void *)&pen_release, sizeof(pen_release));
	outer_clean_range(__pa(&pen_release), __pa(&pen_release + 1));
}

static void write_sync_tag(unsigned int phy_tag, unsigned int addr)
{
	void *virt_tag = phys_to_virt(phy_tag);

	rtd_outl((long unsigned int)virt_tag, addr);
	smp_wmb();
	__cpuc_flush_dcache_area(virt_tag, sizeof(virt_tag));
	outer_clean_range(phy_tag, phy_tag + 4);
}

#if 0
static void __iomem *scu_base_addr(void)
{
	return (void __iomem *)(SYSTEM_SCU_BASE);
}
#endif

static DEFINE_SPINLOCK(boot_lock);

void platform_secondary_init(unsigned int cpu)
{
	/*
	 * if any interrupts are already enabled for the primary
	 * core (e.g. timer irq), then they will not have been enabled
	 * for us: do so
	 */

	/*
	 * let the primary processor know we're out of the
	 * pen, then head off into the C entry point
	 */
	write_pen_release(-1);

	/*
	 * Synchronise with the boot thread.
	 */
	spin_lock(&boot_lock);
	spin_unlock(&boot_lock);
}

void write_sync_tag_by_cpuid(int cpu, unsigned int addr)
{
	unsigned int iMageTag[] = { DUMMY_REG_FOR_2ND_CPU_JUMPADDRESS,
		DUMMY_REG_FOR_3RD_CPU_JUMPADDRESS,
		DUMMY_REG_FOR_4TH_CPU_JUMPADDRESS };
	write_sync_tag(iMageTag[cpu-1], addr);
}

#ifdef CONFIG_REALTEK_POWER_CUT // must enable if we want to wakeup CPU1 from shutdown mode
int rtk_cpu_up(int cpu);
#endif

int platform_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
	unsigned long timeout;

	/*
	 * Set synchronisation state between this boot processor
	 * and the secondary one
	 */
	spin_lock(&boot_lock);

	/*
	 * This is really belt and braces; we hold unintended secondary
	 * CPUs in the holding pen until we're ready for them.  However,
	 * since we haven't sent them a soft interrupt, they shouldn't
	 * be there.
	 */
#ifdef CONFIG_REALTEK_POWER_CUT // must enable if we want to wakeup CPU1 from shutdown mode
	rtk_cpu_up(cpu);
#endif
	write_pen_release(cpu);
	write_pm_dummy_register(cpu,1,0x10);

	// Send signal to 2nd CPU to perform wake-up process
	// add your code here ( note** )
	write_sync_tag_by_cpuid(cpu,virt_to_phys(rtk_secondary_startup));

	/*
	 * Send the secondary CPU a soft interrupt, thereby causing
	 * the boot monitor to read the system wide flags register,
	 * and branch to the address found there.
	 *
	 * Note : depend on your platform design
	 */
	// echo 0 > /sys/devices/system/cpu/cpu1/online
	// echo 1 > /sys/devices/system/cpu/cpu1/online
	sev();
#ifdef CONFIG_REALTEK_POWER_CUT // must enable if we want to wakeup CPU1 from shutdown mode
	if(is_platform_KXLP()) {
		if(cpu!=1 && cpu!=2 && cpu!=3)
			arch_send_wakeup_ipi_mask(cpumask_of(cpu));
			//smp_cross_call(cpumask_of(cpu), 2);
	}
	else
#endif
		arch_send_wakeup_ipi_mask(cpumask_of(cpu));
//		smp_cross_call(cpumask_of(cpu), 2);

	timeout = jiffies + (1 * HZ);
	while (time_before(jiffies, timeout)) {
		smp_rmb();
		if (pen_release == -1) {
			break;
		}
		udelay(10);
	}
	write_pm_dummy_register(cpu,1,0x11);

	/*
	 * now the secondary core is starting up let it run its
	 * calibrations, then wait for it to finish
	 */
	spin_unlock(&boot_lock);
	write_pm_dummy_register(cpu,1,0x12);

	return pen_release != -1 ? -ENOSYS : 0;
}

/*
 * Initialise the CPU possible map early - this describes the CPUs
 * which may be present or become present in the system.
 */
#if defined(CONFIG_QUICK_HIBERNATION) || defined(CONFIG_SUSPEND)
void platform_smp_init_cpus(void)
#else
void __init platform_smp_init_cpus(void)
#endif
{
//	void __iomem *scu_base = scu_base_addr();
	unsigned int i, ncores;

#if (0)	//TODO
	ncores = scu_base ? scu_get_core_count(scu_base) : 1;

	/* sanity check */
	if (ncores > NR_CPUS) {
		printk(KERN_WARNING
		       "rtd299s : no. of cores (%d) greater than configured "
		       "maximum of %d - clipping\n",
		       ncores, NR_CPUS);
		ncores = NR_CPUS;
	}
#else
	ncores = NR_CPUS;
#endif

	for (i = 0; i < ncores; i++)
		set_cpu_possible(i, true);

//     set_smp_cross_call(gic_raise_softirq);
}

#if defined(CONFIG_QUICK_HIBERNATION) || defined(CONFIG_SUSPEND)
void platform_smp_prepare_cpus(unsigned int max_cpus)
#else
void __init platform_smp_prepare_cpus(unsigned int max_cpus)
#endif
{
	int i;

	for (i = 0; i < max_cpus; i++) {
		set_cpu_present(i, true);
	}

	//scu_enable(scu_base_addr());

	//smp_wmb();

	// Send signal to 2nd CPU to perform wake-up process
	// add your code here ( note** )
}

#ifdef CONFIG_REALTEK_POWER_CUT
extern void cpu_freq_lock(void);
extern void cpu_freq_unlock(void);

int _rtk_cpu_kill(unsigned int cpu)
{
	if(is_platform_KXLP()) {
		int cur_cpu_id;
#ifdef CONFIG_PREEMPT
		preempt_disable();
		cur_cpu_id=smp_processor_id();
		preempt_enable();
#else
		cur_cpu_id=smp_processor_id();
#endif
		if(cur_cpu_id!=1&& cpu==1 && !cpu_online(1))
		{
			cpu_freq_lock();
			disable_cpu1();
			write_sync_tag_by_cpuid(1,0);
			cluster_power_down_flush();
			cpu_freq_unlock();
			return 1;
		}

		else if(cur_cpu_id!=2 && cpu==2 && !cpu_online(2))
		{
			cpu_freq_lock();
			disable_cpu2();
			write_sync_tag_by_cpuid(2,0);
			cluster_power_down_flush();
			cpu_freq_unlock();
			return 1;
		}

		else if(cur_cpu_id!=3 && cpu==3 && !cpu_online(3))
		{
			cpu_freq_lock();
			disable_cpu3();
			write_sync_tag_by_cpuid(3,0);
			cluster_power_down_flush();
			cpu_freq_unlock();
			return 1;
		}
	}
	return 1;
}

int rtk_cpu_up(int cpu)
{
	if(is_platform_KXLP()) {
		if(cpu==1)
		{
			enable_cpu1();
		}
		if(cpu==2)
		{
			enable_cpu2();
		}

		if(cpu==3)
		{
			enable_cpu3();
		}
	}
	return 0;
}
#else
#define _rtk_cpu_kill(A)
#define rtk_cpu_up(A)
#endif

/* wfi_1_0 = (rtd_inl(0xb805B83C) >> 1 ) & 0x03;	 */
/* wfi_3_2 = (rtd_inl(0xb805B89C) >> 1 ) & 0x0c;	 */
inline int wfi_pin(int cpu) 
{								
	int wfi = 0;						
	if (cpu < 2) {	// wfi_1_0 					
		int ci = cpu + 1;					
		wfi = (rtd_inl(0xb805B83C) >> ci ) & 0x01;	
	}							
	else { //wfi_3_2
		int ci = cpu -2 +1;
		wfi = (rtd_inl(0xb805B89C) >> ci ) & 0x01; 
	}							
	return wfi;							
}

#define aif()						\
	({						\
		int ret;				\
		__asm__ __volatile__ (			\
			"MRC p15, 0, %0, c12, c1, 1 \n"	\
			:"=r"(ret));			\
		ret;					\
	})



int rtk_cpu_kill(unsigned int cpu)
{
	int waitforwfi = 200; //*10ms

#ifdef CONFIG_REALTEK_POWER_CUT
	_rtk_cpu_kill(cpu);
#endif

	while ( !wfi_pin(cpu) && --waitforwfi > 0) {
		msleep(10);
		
		if (waitforwfi < 0) {
			/* pr_err("CPU%u: cpu didn't die, aif(0x%x) wfi(0x%x, 0x%x) \n", */
			/*        cpu, aif(), rtd_inl(0xb805B83C), rtd_inl(0xb805B89C)); //fixme, aif() need HCR.TGE=0, otherwise UNDEF exception. */
			pr_err("CPU%u: cpu didn't die, wfi(0x%x, 0x%x) \n", cpu, rtd_inl(0xb805B83C), rtd_inl(0xb805B89C));
			return 0;
		}
	}

	return 1;
}


#if defined(CONFIG_QUICK_HIBERNATION) || defined(CONFIG_SUSPEND)
struct smp_operations rtk_smp_ops = {
#else
struct smp_operations mwelin2_smp_ops __initdata = {
#endif
	.smp_init_cpus      = platform_smp_init_cpus,
	.smp_prepare_cpus   = platform_smp_prepare_cpus,
	.smp_secondary_init = platform_secondary_init,
	.smp_boot_secondary = platform_boot_secondary,
#ifdef CONFIG_HOTPLUG_CPU
	.cpu_die            = platform_cpu_die,
	.cpu_disable        = platform_cpu_disable,
	.cpu_kill           = rtk_cpu_kill,
#endif
};
