/*
 *
 *  Copyright (C) 2011, Realtek
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/smp.h>
#include <linux/console.h>
#include <linux/reboot.h>
#include <asm/cacheflush.h>
#include <asm/cp15.h>
#include <mach/common.h>
#include <mach/platform.h>


static inline void cpu_enter_lowpower(void)
{
#ifdef CONFIG_REALTEK_POWER_CUT
	if(is_platform_KXLP())
	{
		if(smp_processor_id()==1 || smp_processor_id()==2 || smp_processor_id()==3)
		{
	 		asm volatile(	"	mrc	p15, 0, r3, c1, c0, 0\n"
					"	bic	r3, r3, #4\n"
					"	mcr	p15, 0, r3, c1, c0, 0\n" ::: "r3");
			asm volatile(	"dmb\n" //@ ensure ordering with previous memory accesses
			 		"mrc	 p15, 1, r0, c0, c0, 1\n" //	       @ read clidr
			 		"ands	 r3, r0, #0x7000000\n" //	       @ extract loc from clidr
			 		"mov	 r3, r3, lsr #23\n" //		       @ left align loc bit field
			 		"beq	 finished\n" // 		       @ if loc is 0, then no need to clean
			 		"mov	 r10, #0\n" //			       @ start clean at cache level 0
"flush_levels:\n" //
			 		"add	 r2, r10, r10, lsr #1\n" //	       @ work out 3x current cache level
			 		"mov	 r1, r0, lsr r2\n" //		       @ extract cache type bits from clidr
			 		"and	 r1, r1, #7\n" //		       @ mask of the bits for current cache only
			 		"cmp	 r1, #2\n" //		       @ see what cache we have at this level
			 		"blt	 skip\n" //		       @ skip if no cache, or just i-cache
#ifdef CONFIG_PREEMPT
					"mrs     r9, CPSR\n" //@make cssr&csidr read atomic
					"cpsid   i\n"
#endif
					"mcr	 p15, 2, r10, c0, c0, 0\n" //	       @ select current cache level in cssr
					"isb\n" //				       @ isb to sych the new cssr&csidr
					"mrc	 p15, 1, r1, c0, c0, 0\n" //	       @ read the new csidr
#ifdef CONFIG_PREEMPT
					"msr     CPSR_c, r9\n"
#endif
					"and	 r2, r1, #7\n" //		       @ extract the length of the cache lines
					"add	 r2, r2, #4\n" //		       @ add 4 (line length offset)
					"ldr	 r4, =0x400\n" //
					"sub	 r4, r4, #1\n" //
					"ands	 r4, r4, r1, lsr #3\n" //	       @ find maximum number on the way size
					"clz	 r5, r4\n" //		       @ find bit position of way size increment
					"ldr	 r7, =0x8000\n" //
					"sub	 r7, r7, #1\n" //

					"ands	 r7, r7, r1, lsr #13\n" //	       @ extract max number of the index size
"loop1:\n" //
					"mov	 r9, r7\n" //		       @ create working copy of max way size
"loop2:\n" //
					"orr	 r11, r10, r4, lsl r5\n" //	      @ factor way and cache number into r11
					"orr	 r11, r11, r9, lsl r2\n" //	      @ factor index number into r11
					"mcr	 p15, 0, r11, c7, c14, 2\n" //	       @ clean & invalidate by set/way
					"subs	 r9, r9, #1\n" //		       @ decrement the way
					"bge	 loop2\n" //
					"subs	 r4, r4, #1\n" //		       @ decrement the index
					"bge	 loop1\n" //
"skip:\n" //
					"add	 r10, r10, #2\n" //		       @ increment cache number
					"cmp	 r3, r10\n" //
					"bgt	 flush_levels\n" //
"finished:\n" //
					"mov	 r10, #0\n" //			       @ swith back to cache level 0
					"mcr	 p15, 2, r10, c0, c0, 0\n" //	       @ select current cache level in cssr
					"dsb\n" //
					"isb\n"
					"mov	 r0, #0\n"
					"mcr	 p15, 0, r0, c7, c1, 0\n"
					::: "r3", "r1", "r2",  "r10", "r7" , "r11", "r9", "r7", "r4", "r5");//
					//flush_cache_all();
					/* step 1 clear c bit*/

				asm volatile(
			    /* Enable SMP bit for core 0 */
				"mrrc	 p15, 1, r0, r1, c15\n"
		    		"BIC r0, r0, #(1<<6)\n"
		    		"mcrr    p15, 1, r0, r1, c15\n"
				"isb\n"
				"dsb sy");
				__asm__ __volatile__ ("wfi" : : : "memory");
		 		for (;;) {
					asm volatile("1: add r0, r0, #1\n\t"
					                      "dsb\n\t"
						         "b 1b\n\t");
				}

		}
		else
		{
			flush_cache_all();
			asm volatile(	"	mrc	p15, 0, r3, c1, c0, 0\n"
					"	bic	r3, r3, #4\n"
					"	mcr	p15, 0, r3, c1, c0, 0\n" ::: "r3");
		}
	}
	else
#endif
	{
		// flush cache
		flush_cache_all();
		asm volatile(	"	mrc	p15, 0, r3, c1, c0, 0\n"
				"	bic	r3, r3, #4\n"
				"	mcr	p15, 0, r3, c1, c0, 0\n" ::: "r3");
	}

#if 0
	flush_cache_all();
/* step 1 clear c bit*/
	asm volatile(
	"mcr	p15, 0, %1, c7, c5, 0\n"
	"	mcr	p15, 0, %1, c7, c10, 4\n"
	/*
	 * Turn off coherency
	 */
	"	mrc	p15, 0, %0, c1, c0, 1\n"
	"	bic	%0, %0, %3\n"
	"	mcr	p15, 0, %0, c1, c0, 1\n"
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	bic	%0, %0, %2\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	  : "=&r" (v)
	  : "r" (0), "Ir" (CR_C), "Ir" (0x40)
	  : "cc");
#ifdef CONFIG_REALTEK_POWER_CUT
	if(is_platform_KXLP())
	{
		if(smp_processor_id()==1 || smp_processor_id()==2 || smp_processor_id()==3) {
	/* step 2,3,4 clear 32, 33, 35, 36, and set 38*/
#ifdef CONFIG_ARCH_RTK299S
		        asm volatile(
		            /* Enable SMP bit for core 0 */
		        "mrrc    p15, 1, r0, r1, c15\n"
		        "bic     r1, r1, #(1<<0)\n"
		        "bic     r1, r1, #(1<<1)\n"
		        "bic     r1, r1, #(1<<3)\n"
		        "bic     r1, r1, #(1<<4)\n"
		              "orr     r1, r1, #(1<<6)\n"
		        "mcrr    p15, 1, r0, r1, c15\n"
		        "isb\n"
		        "dsb");
#endif
	/* step 5 */
	/* step 6 clear CPUECTLR.SMPEN bit*/

			asm volatile(
		    /* Enable SMP bit for core 0 */
			"mrrc	 p15, 1, r0, r1, c15\n"
	    		"BIC r0, r0, #(1<<6)\n"
	    		"mcrr    p15, 1, r0, r1, c15\n"
			"isb\n"
			"dsb sy");

#ifdef CONFIG_ARCH_RTK299S
			asm volatile ("MRC p15, 0, r1, c1, c0, 0\n"
			"BIC r1, r1, #(1<<12)\n"
			"BIC r1, r1, #(1<<11)\n"
			"BIC r1, r1, #(1<<2)\n"
			"MCR p15, 0 , r1, c1, c0, 0\n"
			"MOV r0, #0\n"
			"MCR p15, 0, r0, c7, c5, 6\n"
			"MCR p15, 0, r0, c7, c5, 0\n"
			"DSB\n"
			"ISB");
#endif
	/* step 8 */

	/*step 9, 10*/
			asm volatile(
			"DSB\n"
			"ISB");
		}
	}
#endif
#endif
}

static inline void cpu_leave_lowpower(void)
{
	unsigned int v;

	asm volatile(
	"	mrc	p15, 0, %0, c1, c0, 0\n"
	"	orr	%0, %0, %1\n"
	"	mcr	p15, 0, %0, c1, c0, 0\n"
	  : "=&r" (v)
	  : "Ir" (CR_C), "Ir" (0x40)
	  : "cc");
}

static inline void platform_do_lowpower(unsigned int cpu, int *spurious)
{
	/*
	 * there is no power-control hardware on this platform, so all
	 * we can do is put the core into WFI; this is safe as the calling
	 * code will have already disabled interrupts
	 */
	for (;;) {
		/*
		 * here's the WFI
		 */
		asm("wfi \n\t"
		    :
		    :
		    : "memory", "cc");

		if (pen_release == cpu) {
			/*
			 * OK, proper wakeup, we're done
			 */
			break;
		}

		/*
		 * Getting here, means that we have come out of WFI without
		 * having been woken up - this shouldn't happen
		 *
		 * Just note it happening - when we're woken, we can report
		 * its occurrence.
		 */
		(*spurious)++;
	}
}

int platform_cpu_kill(unsigned int cpu)
{
	return 1;
}


int rtk_optee_cpu_suspend(int level);
/*
 * platform-specific code to shutdown a CPU
 *
 * Called with IRQs disabled
 */
void platform_cpu_die(unsigned int cpu)
{
	int spurious = 0;

	/*
	 * we're ready for shutdown now, so do it
	 */

#if  defined(CONFIG_OPTEE)
	int ret;
	/** level:
	 * 0, core
	 * 1, cluster
	 * 2, system/platform. if success, smc do not return.
	 **/
	
	printk("optee_cpu_suspend: cpu: 0x%x \n", cpu);

	ret = rtk_optee_cpu_suspend((cpu != 0) ? 0 : 2);
	if (ret != 0) {
		resume_console();
		printk(KERN_EMERG "optee_cpu_suspend: cpu: 0x%x return !! \n", cpu);
	}
	
	platform_do_lowpower(cpu, &spurious);

#else
	cpu_enter_lowpower();
	platform_do_lowpower(cpu, &spurious);

	/*
	 * bring this CPU back into the world of cache
	 * coherency, and then restore interrupts
	 */
	cpu_leave_lowpower();
#endif
	if (spurious) {
		resume_console();
		pr_warn("CPU%u: %u spurious wakeup calls\n", cpu, spurious);
	}
}

int platform_cpu_disable(unsigned int cpu)
{
	/*
	 * we don't allow CPU 0 to be shutdown (it is still too special
	 * e.g. clock tick interrupts)
	 */
	return cpu == 0 ? -EPERM : 0;
}
