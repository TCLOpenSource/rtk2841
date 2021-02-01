#ifndef __MACH_DEBUG_MACRO_S
#define __MACH_DEBUG_MACRO_S

#include <mach/resource.h>

#define DEBUG_LL_PHYS_BASE	UART0_BASE
#define DEBUG_LL_VIRT_BASE	UART0_BASE

#define DEBUG_LL_UART_OFFSET	0x00009000

		.macro	addruart,rp,rv,tmp

		mov	\rp, #DEBUG_LL_UART_OFFSET
		orr	\rv, \rp, #DEBUG_LL_VIRT_BASE
		orr	\rp, \rp, #DEBUG_LL_PHYS_BASE

		.endm

#include <asm/hardware/debug-pl01x.S>

#endif

