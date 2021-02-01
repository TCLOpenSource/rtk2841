#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include "rtk_ice.h"
 extern void disable_printk(void);
extern void enable_printk(void);
extern void rtice_putchar(char c);
UINT8 g_ByPassRTICECmd = 0;

int rtice_enter_debug_mode()
{
	disable_printk();
	return 0;
}

int rtice_exit_debug_mode()
{
	enable_printk();
	return 0;
}


extern volatile UINT8 fDebugModeEnable;
/*----------------------------------------------------------------------
 * Func : rtice_register_command_handler
 *
 * Desc : register a command handler
 *
 * Parm : cmd : handle of RTICE command
 *
 * Retn : handle of rtice command buffer
 *----------------------------------------------------------------------*/
int rtice_uart_handler(unsigned char data, unsigned int dir)
{
        if(g_ByPassRTICECmd > 0)
                return 0;
	int ret = rtice_input(&data, 1);
	if(fDebugModeEnable)
		return ret;
	else
		return 0;
}


/*----------------------------------------------------------------------
 * Func : rtice_output
 *
 * Desc : output data
 *
 * Parm :
 *
 * Retn :
 *----------------------------------------------------------------------*/
void rtice_output(unsigned char *data, unsigned int len)
{
	while (len--)
		rtice_putchar(*(data++));
}
