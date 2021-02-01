/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 */

#ifndef _ASM_MACH_SYSTME_H_
#define _ASM_MACH_SYSTEM_H_

#include <asm/io.h>
#include <rbus/sys_reg_reg.h>
#include <mach/iomap.h>
#include "serial.h"

//#define CONFIG_FPGA

//rtd299o support 8 timers, timer0 for VCPU, timer1 for ACPU, timer2 for SCPU, timer3 for KCPU
#ifdef CONFIG_REALTEK_SECURE_OS
#define SYSTEM_TIMER 		3
#else
#define SYSTEM_TIMER 		2
#endif


#ifndef CONFIG_FPGA // real ic
#define TIMER_CLOCK			27000000
#define TIMER_NS_PER_TICK   37              // 37ns
#else // fpga
#define TIMER_CLOCK		    40000000
#define TIMER_NS_PER_TICK   25              // 25ns
#endif
#define MAX_HWTIMER_NUM		8

// linux will do the remapping of rbus so that you have to read/write rbus via rtd_xxx series
// or just tells a correct address to the system
#if 0 // RDC FPGA
#define GET_MAPPED_RBUS_ADDR(x)		(x - 0x2FB00000 + RBUS_BASE_VIRT)
#define SYSTEM_SCU_BASE				(0xfe000000)
#define SYSTEM_GIC_DIST_BASE		(0xfe001000)
#define SYSTEM_GIC_CPU_BASE			(0xfe002000)
#else // TV
#define GET_MAPPED_RBUS_ADDR(x)		(x - 0xb8000000 + RBUS_BASE_VIRT)
#define SYSTEM_SCU_BASE				GET_MAPPED_RBUS_ADDR(0xb8080000)
#define SYSTEM_GIC_DIST_BASE		GET_MAPPED_RBUS_ADDR(0xb8081000)
#define SYSTEM_GIC_CPU_BASE			GET_MAPPED_RBUS_ADDR(0xb8082000)
//#define SYSTEM_PL310_BASE			GET_MAPPED_RBUS_ADDR(0xb801d000)
#endif

#define DUMMY_REG_FOR_2ND_CPU_JUMPADDRESS							0x504
#define DUMMY_REG_FOR_3RD_CPU_JUMPADDRESS							0x508
#define DUMMY_REG_FOR_4TH_CPU_JUMPADDRESS							0x50c

// need content protection in secure solution
#define CONTENT_PROTECTION_KEY         0x12345678

#define GET_RETURN_ADDR()               \
({ int __res;                               \
    __asm__ __volatile__(                   \
        "mov\t%0, lr\n\t"         \
        : "=r" (__res));                \
    __res;                              \
})

#endif
