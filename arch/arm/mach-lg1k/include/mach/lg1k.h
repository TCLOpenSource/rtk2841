#ifndef	__MACH_LG1K_H
#define __MACH_LG1K_H

#define	REG(n)		((n) << 2)

/*
 * NOTE: not contains all devices
 */
#define	UART0_PHYS	0xfe000000
#define UART1_PHYS	0xfe100000
#define UART2_PHYS	0xfe200000

/*
 * virtual addresses for static-mapped devices
 */
#define UART0_VIRT	UART0_PHYS

#endif	/* __MACH_LG1K_H */
