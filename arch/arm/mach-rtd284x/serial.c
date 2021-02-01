/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright 2012 by Chuck Chen <ycchen@realtek.com>
 */

#include <linux/init.h>
#include <linux/io.h>
#include <linux/serial_reg.h>
#include <rbus/misc_uart_reg.h>
#include <rbus/iso_misc_off_uart_reg.h>
#include <mach/system.h>
#include <mach/rtk_platform.h>

#define UARTINFO_TEMT_MASK                  0x40
#define UARTINFO_THRE_MASK                  0x20
#define UARTINFO_TRANSMITTER_READY_MASK     (UARTINFO_TEMT_MASK | UARTINFO_THRE_MASK)

// used for early print

static volatile unsigned int uart_base;
static volatile unsigned int uart_configed;

/*******************************************************************************
 *
 ******************************************************************************/
void serial_write(unsigned char ch8)
{
	if( !uart_base ) {
		return;	
	}

	while((rtd_inl(uart_base+(UART_LSR << 2)) & UARTINFO_TRANSMITTER_READY_MASK) != UARTINFO_TRANSMITTER_READY_MASK);

	rtd_outl(uart_base+(UART_TX << 2), ch8);
}

void serial_prints(const char * pch8)
{
	unsigned char ch8;
		
	while (*pch8 != '\0') { 
		ch8 = *pch8;
		if (*pch8++ == '\n') {
			ch8 = 0x0D;      
			serial_write(ch8);
			ch8 = 0x0A; 
		}
		serial_write(ch8);
	}
}

int uart_setBaudrate(unsigned int baudrate)
{
    unsigned char tmp_LCR;
    unsigned int divisor;

    switch (baudrate) {
        case 9600:
        case 19200:
        case 38400:
        case 57600:
        case 115200:
        case 460800:
        	break;
        default:
            return -1;
    }

    /* Enable access to the divisor latches by setting DLAB in LCR. */
	tmp_LCR = rtd_inl(uart_base+(UART_LCR << 2));
	rtd_outl(uart_base+(UART_LCR << 2), tmp_LCR | 0x80);

    /* Set divisor latches. */
#if 1 // real ic
    divisor = ( get_uart_clock()/16/baudrate );
#else // fpga - fixed uart clock source (25MHz)
    divisor = 0x000e;
#endif
	rtd_outl(uart_base+(UART_DLL << 2), divisor & 0xff);
	rtd_outl(uart_base+(UART_DLM << 2), ((divisor & 0xff00 ) >> 8));

	rtd_outl(uart_base+(UART_LCR << 2), tmp_LCR);

    return 0;
}

void bsp_serial_init(void)
{
	if( uart_configed == 0xdeadbeef ) {
		return;	
	}

	uart_configed = 0xdeadbeef;
	
	switch(SYSTEM_CONSOLE)
	{
		default:
		case 0:
			uart_base = (unsigned int)ISO_MISC_OFF_UART_U0RBR_THR_DLL_reg;
			if (get_uart_clock() == UART_CLOCK_98M) {
				if ((rtd_inl(0xb80004e4) & (BIT(0) | BIT(1) | BIT(3))) != 0x9)
				{
					rtd_setbits(0xb80004e4, BIT(0) | BIT(3));
					rtd_clearbits(0xb80004e4, BIT(1));
				}
				rtd_clearbits(0xB8060058, BIT(0));
			}
			break;
		case 1:
			uart_base = (unsigned int)MISC_UART_U1RBR_THR_DLL_reg;
			break;
#if 0 // no uart2
		case 2:
			uart_base = (unsigned int)MISC_UART_U2RBR_THR_DLL_reg;
			break;
#endif
#if 0 // no uart3
		case 3:
			uart_base = (unsigned int)MISC_UART_U3RBR_THR_DLL_reg;
			break;
#endif
	}

	rtd_outl(uart_base+(UART_LCR << 2), 0x03);

    uart_setBaudrate(DEFAULT_BAUNDRATE);

	rtd_outl(uart_base+(UART_FCR << 2), 0x06);
	rtd_outl(uart_base+(UART_FCR << 2), 0x01);
	rtd_outl(uart_base+(UART_MCR << 2), 0x00);
	
	serial_prints("\nbsp_serial_init\n");
}

void __init heads_serial_init(void)
{
    uart_configed = 0;
    bsp_serial_init();
}
