#ifndef __MACH_UNCOMPRESS_H
#define __MACH_UNCOMPRESS_H

#include <asm/mach-types.h>

#include <mach/platform.h>

#define AMBA_UART_DR(base)	(*(volatile unsigned char *)((base) + 0x00))
#define AMBA_UART_LCRH(base)	(*(volatile unsigned char *)((base) + 0x2c))
#define AMBA_UART_CR(base)	(*(volatile unsigned char *)((base) + 0x30))
#define AMBA_UART_FR(base)	(*(volatile unsigned char *)((base) + 0x18))

/*
 * Return the UART base address
 */
static inline unsigned long get_uart_base(void)
{
	return LG115X_UART0_BASE;
}

/*
 * This does not append a newline
 */
static inline void putc(int c)
{
	unsigned long base = get_uart_base();

	while (AMBA_UART_FR(base) & (1 << 5))
		barrier();

	AMBA_UART_DR(base) = c;
}

static inline void flush(void)
{
	unsigned long base = get_uart_base();

	while (AMBA_UART_FR(base) & (1 << 3))
		barrier();
}

/*
 * nothing to do
 */
#define arch_decomp_setup()
#define arch_decomp_wdog()

#endif

