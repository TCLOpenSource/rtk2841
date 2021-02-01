#ifndef __ASM_ARCH_SERIAL_H__

#define __ASM_ARCH_SERIAL_H__

//rtd299o support 4 uarts, uart0 in ISO_MISC_OFF, uart1/2/3 in MISC

#define UART_CLOCK_27M			27000000UL
#define UART_CLOCK_40M			40000000UL
#define UART_CLOCK_98M			98000000UL

#ifdef CONFIG_REALTEK_FPGA
	#define SYSTEM_CONSOLE		1
	#define UART_CLOCK		UART_CLOCK_40M //TV FPGA
#else
	#ifndef CONFIG_REALTEK_SECURE_OS
	#define SYSTEM_CONSOLE		0
	#else
	#define SYSTEM_CONSOLE		1
	#endif
	#define UART_CLOCK		UART_CLOCK_27M
#endif	//CONFIG_REALTEK_FPGA

#ifdef IS_RDC_FPGA
	#define DEFAULT_BAUNDRATE	57600
#else
	#define DEFAULT_BAUNDRATE	115200
#endif

    //void serial_write(unsigned char ch8);
    //void searial_prints(const char * pch8);

#endif // __ASM_ARCH_SERIAL_H__
