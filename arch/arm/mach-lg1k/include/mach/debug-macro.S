#ifndef __MACH_DEBUG_MACRO_S
#define __MACH_DEBUG_MACRO_S

#include <mach/lg1k.h>

#define DEBUG_LL_PHYS_BASE	UART0_PHYS
#define DEBUG_LL_VIRT_BASE	UART0_VIRT

#define DEBUG_LL_UART_OFFSET	0x00000000

		.macro	addruart,rp,rv,tmp

		mov	\rp, #DEBUG_LL_UART_OFFSET
		orr	\rv, \rp, #DEBUG_LL_VIRT_BASE
		orr	\rp, \rp, #DEBUG_LL_PHYS_BASE

		.endm

#include <debug/pl01x.S>


#endif	/* __MACH_DEBUG_MACRO_S */
