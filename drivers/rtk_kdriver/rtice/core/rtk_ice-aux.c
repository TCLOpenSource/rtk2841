#include <linux/kernel.h>
#include "rtk_ice-aux.h"

#include "rtk_ice-debug.h"
#include <linux/delay.h>
#include <linux/delay.h>
#include <linux/mm.h>
#include <mach/io.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/misc_reg.h>
#include <rbus/misc_uart_reg.h>
//#include "rbus/scaler/rbusPinmuxReg.h"
#include <linux/string.h>

#ifndef  BOOLEAN
#define BOOLEAN int
#define FALSE 0
#define TRUE 1
#endif
#ifdef DEBUG_TM_USED
static unsigned int s_tm_last = 0;
void rtice_tm_start()
{
	s_tm_last = rtd_inl(SCPU_CLK90K_LO_reg);
}

unsigned int rtice_tm_end()
{
	unsigned int eTm = rtd_inl(SCPU_CLK90K_LO_reg) - s_tm_last;
	return eTm * 1000 / 90090;

}
#endif

void uart1_enable(void)
{
	static BOOLEAN f_enabled = FALSE;
	sys_reg_sys_srst2_RBUS sys_srst2;
	sys_reg_sys_clken2_RBUS sys_clken2;
	sys_srst2.regValue = 0;
	sys_clken2.regValue = 0;

	if(f_enabled == TRUE)
		return;
	sys_clken2.regValue =  rtd_inl(SYS_REG_SYS_CLKEN2_reg);
	if(!sys_clken2.clken_misc) {
		printk(KERN_NOTICE "RT-ICE enable misc clk.\n");
		sys_srst2.regValue = rtd_inl(SYS_REG_SYS_SRST2_reg);
		sys_clken2.regValue = rtd_inl(SYS_REG_SYS_CLKEN2_reg);

		sys_clken2.clken_misc = 0;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_srst2.rstn_misc = 0;
		rtd_outl(SYS_REG_SYS_SRST2_reg,sys_srst2.regValue);
		sys_clken2.clken_misc = 1;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_clken2.clken_misc = 0;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_srst2.rstn_misc = 1;
		rtd_outl(SYS_REG_SYS_SRST2_reg,sys_srst2.regValue);
		sys_clken2.clken_misc = 1;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
	}
	if(!sys_clken2.clken_uart1) {
		printk(KERN_NOTICE "RT-ICE enable uart1 clk.\n");
		sys_srst2.regValue = rtd_inl(SYS_REG_SYS_SRST2_reg);
		sys_clken2.regValue = rtd_inl(SYS_REG_SYS_CLKEN2_reg);

		sys_clken2.clken_uart1 = 0;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_srst2.rstn_uart1 = 0;
		rtd_outl(SYS_REG_SYS_SRST2_reg,sys_srst2.regValue);
		sys_clken2.clken_uart1 = 1;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_clken2.clken_uart1 = 0;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
		sys_srst2.rstn_uart1 = 1;
		rtd_outl(SYS_REG_SYS_SRST2_reg,sys_srst2.regValue);
		sys_clken2.clken_uart1 = 1;
		rtd_outl(SYS_REG_SYS_CLKEN2_reg,sys_clken2.regValue);
	}
	printk(KERN_NOTICE "[%s::%d]Finish time setting.\n",__func__,__LINE__);
	/*pin mux*/
	//rtd_maskl(0xb8060218, 0xffffff0f, 0x00000070);/*pad_st_gpio_27_io,rx*/
	//rtd_maskl(0xb806021C, 0x0fffffff, 0x70000000);/*pad_st_gpio_28 ,tx*/
    //rtd_maskl(0xb80008b8,0xFFFFFFCF,0x0); //src0:input mux
    rtd_maskl(0xb8060200,0xFFFF0FFF,0x00006000); //rxdi:R872  Ps_Reg:st_gpio_02_ps 
    rtd_maskl(0xb8060200,0xFF0FFFFF,0x00600000);//tx:R871  Ps_Reg:st_gpio_01_ps 
#if 0
	/*rxdi:R777  Ps_Reg:st_gpio_6_ps*/
	rtd_maskl(CRT_SYS_CLKSEL_reg,0xffff0f0f,0x00006060);
	/*use 27m(0--->98m   1--->27m)*/
	rtd_outl(CRT_SYS_CLKSEL_reg,rtd_inl(CRT_SYS_CLKSEL_reg)|0x1);
#endif
	/*uart settings*/
	rtd_outl(MISC_UART_U1LCR_reg,0x83);/*UART1_LCR ->  DLAB = 1*/
	/**
	  *UART1_DLL(Value): Timing Setting/DLL(DLAB=1)
	  *eg.115200; RX/TX FIFO data(DLAB=0)  27M/(16 *115200)
	**/
	rtd_outl(MISC_UART_U1RBR_THR_DLL_reg,0x0f);/*0x0f ---115200   0x1d ---57600*/
	/**
	  *UART1_FCR(FIFO CTRL): FIFO level: 11  for 14bytes ,
	  *Transmitter FIFO reset,Receiver FIFO reset.
	**/
	rtd_outl(MISC_UART_U1IIR_FCR_reg,0xc6);
	/*UART1_FCR(FIFO CTRL): FIFO Enable:FIFO En;*/
	rtd_outl(MISC_UART_U1IIR_FCR_reg,0xc1);
	/*UART1_LCR(Line CTRL): DLAB:0, DLL -> RX/TX FIFO*/
	rtd_outl(MISC_UART_U1LCR_reg,0x03);
	f_enabled = TRUE;
}

void uart1_printer(unsigned char *buff, unsigned int len)
{
	int i, cnt = 11;
	while (len) {
		int tx_len = (len > 14) ? 14 : len;
		for (i = 0; i < tx_len; i++) {
			rtd_outl(MISC_UART_U1RBR_THR_DLL_reg, *(buff++));
			len--;
		}
		while (cnt-- && ((rtd_inl(MISC_UART_U1LSR_reg) >> 5) & 0x3) != 0x3)
			udelay(100);
	}
}

void rtice_print_string(unsigned char *format, ...)
{
	unsigned char tmp[256];
	va_list argptr;
	va_start(argptr, format);
	vsprintf(tmp, format, argptr);
	va_end(argptr);
	//memset(tmp, 0x0, 256);

	#ifdef DEBUG_RTICE
	uart1_enable();
	uart1_printer(tmp, strlen(tmp) <= 256 ? strlen(tmp) : 256);
	#else
	 printk(KERN_DEBUG "%s\n", tmp);
	#endif
}

void rtice_print_array(unsigned char*fmt,unsigned char*pData,unsigned int len)
{
	#ifdef DEBUG_RTICE_CMD
	int i;
	unsigned char tmp[512];
	unsigned char *ptmp = tmp;
	uart1_enable();
	memset(tmp, 0x0, 512);
	ptmp += sprintf(ptmp, "[DEBUG_CMD] :len = %d, %s { ", len, fmt);
	for (i = 0; i < len; i++) {
		ptmp += sprintf(ptmp, "%02x, ", *pData++);
		if (ptmp + 7 - tmp >= sizeof(tmp)) {
			ptmp += sprintf(ptmp, "...");
			break;
		}
	}
	ptmp += sprintf(ptmp, "} \r\n");
	uart1_printer(tmp, strlen(tmp));
	#else /*  */
	int i;
	for (i = 0; i < len; i++)
		printk(KERN_DEBUG "%02x ", *pData++);
	printk(KERN_DEBUG "\n");
	#endif /*  */
}

unsigned char rtice_checksum(unsigned char *p_data, unsigned int len)
{
	unsigned char checksum = 0;
	while (len--)
		checksum += *(p_data++);
	return (unsigned char)-checksum;
}
