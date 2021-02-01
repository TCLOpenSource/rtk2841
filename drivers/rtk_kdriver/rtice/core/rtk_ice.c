/*===========================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2006 *
 * All rights reserved.                                       *
 *==========================================================*/
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/dma-mapping.h>
#include <linux/string.h>
#include "rtk_ice.h"
#include "rtk_ice-debug.h"
#include "rtk_ice-aux.h"

#if defined(CONFIG_REALTEK_WATCHDOG) || defined(CONFIG_RTK_KDRV_WATCHDOG)
extern int watchdog_enable(unsigned char On);
extern int is_watchdog_enable(void);
static int rtice_watchdog_disable = 0;
#endif /*  */
#define RTICE_COMMAND_CWT 10
#define RTICE_COMMAND_BUFFER_SIZE 2096
#define DEBUG_FLAG_NONE 0xffffffff
static unsigned char *g_CmdBuff;
unsigned char *g_OutBuff;

/*===================== Static Variable =======================*/
static struct workqueue_struct *wq;
static rtice_command_handler_t rtice_cmd_map[RTICE_CMD_GROUP_ID_MAX];
static spinlock_t rtice_cmd_list_lock;
LIST_HEAD(cmd_list);
extern void early_disable_printk(void);
extern void early_enable_printk(void);
volatile UINT8 fDebugModeEnable = 0x00;
static unsigned int AudioDebugFlagAddr = 0;
static unsigned int VideoDebugFlagAddr = 0;
static unsigned int AudioDebugFlagBackup = DEBUG_FLAG_NONE;
static unsigned int VideoDebugFlagBackup = DEBUG_FLAG_NONE;


/*
* @perm is 0 if the the variable is not to appear in sysfs, or 0444
* for world-readable, 0644 for root-writable, etc.  Note that if it
* is writable, you may need to use kernel_param_lock() around
* accesses (esp. charp, which can be kfreed when it changes).
*
*/
module_param(AudioDebugFlagAddr, uint, 0444);
module_param(VideoDebugFlagAddr, uint, 0444);


/*----------------------------------------------------------------------
 * Func : _rtice_queue_command
 *
 * Desc : queu an rtice command
 *
 * Parm : data
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
static void _rtice_queue_command(rtice_cmd * cmd)
{
	unsigned long flags;
	spin_lock_irqsave(&rtice_cmd_list_lock, flags);
	list_add(&cmd_list, &cmd->list);
	spin_unlock_irqrestore(&rtice_cmd_list_lock, flags);
}

/*----------------------------------------------------------------------
 * Func : _rtice_queue_command
 *
 * Desc : queu an rtice command
 *
 * Parm : data
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
static rtice_cmd *_rtice_dequeue_command(void)
{
	unsigned long flags;
	rtice_cmd * cmd = NULL;
	spin_lock_irqsave(&rtice_cmd_list_lock, flags);
	if (!list_empty(&cmd_list)){
		cmd = list_entry(cmd_list.next, rtice_cmd, list);
		list_del(&cmd->list);
	}
	spin_unlock_irqrestore(&rtice_cmd_list_lock, flags);
	return cmd;
}


/*----------------------------------------------------------------------
 * Func : rtice_do_command
 *
 * Desc : do rtice command
 *
 * Parm :
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
static int _rtice_do_command(unsigned char op_code,\
					     unsigned char *command_data,\
					     unsigned short command_data_len,\
					     unsigned char *p_response,\
					     unsigned short response_len )
{
	int gid = GET_OP_CODE_GROUP(op_code);
	if (rtice_cmd_map[gid].handler == NULL)
		return -RTICE_ERR_UNSUPPORTED_OP_CODE;
	return rtice_cmd_map[gid].handler(op_code, command_data,\
					    command_data_len, p_response,\
					    		response_len);
}

/*----------------------------------------------------------------------
 * Func : _rtice_work
 *
 * Desc : dsr of rtice
 *
 * Parm :
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
static void _rtice_work(struct work_struct *work)
{

	do{
		rtice_cmd * cmd = NULL;
		while ((cmd = _rtice_dequeue_command()) != NULL) {
			int ret = 0;
			unsigned int cmd_len;
			RTICE_DEBUG("[%s] get %02x %02x %02x... \n\r",\
					__func__, cmd->data[0], cmd->data[1],\
					cmd->data[2]);
			if (cmd->data[1] & 0x80) {
 				cmd_len = ((cmd->data[1] & 0x7F) << 8) + \
								cmd->data[2];
				if (cmd->data[cmd_len + 3] != \
					rtice_checksum(cmd->data,cmd_len + 3)){
					unsigned char g_OutBuff[4];
					g_OutBuff[0] = ~cmd->data[0];
					g_OutBuff[1] = 1;
					g_OutBuff[2] = RTICE_ERR_LRC_ERROR;
					g_OutBuff[3] = \
						rtice_checksum(g_OutBuff, 3);
					rtice_output(g_OutBuff, 4);
					RTICE_DEBUG(\
					"[%s] - 1 RTICE_ERR_LRC_ERROR \n\r",\
								__func__);
					goto respond_end;
				} else {
					ret = _rtice_do_command(\
						cmd->data[0],\
						&cmd->data[3],\
				((cmd->data[1] & 0x7F) << 8) + cmd->data[2],\
						&g_OutBuff[3],\
						sizeof(g_OutBuff) - 4);
				}
			} else {
				cmd_len = cmd->data[1];
				if (cmd->data[cmd_len + 2] != \
					rtice_checksum(cmd->data,cmd_len + 2)){
					unsigned char g_OutBuff[4];
					g_OutBuff[0] = ~cmd->data[0];
					g_OutBuff[1] = 1;
					g_OutBuff[2] = RTICE_ERR_LRC_ERROR;
					g_OutBuff[3] = \
					    rtice_checksum(g_OutBuff, 3);
					rtice_output(g_OutBuff, 4);
					RTICE_DEBUG(\
					"[%s] - 2  RTICE_ERR_LRC_ERROR \n\r",\
								__func__);
					goto respond_end;
				} else {
					ret = _rtice_do_command(\
						cmd->data[0],\
						&cmd->data[2],\
						cmd->data[1],\
						&g_OutBuff[3],\
						sizeof(g_OutBuff) - 4);
				}
			}
			RTICE_DEBUG("_rtice_work rtice_output ret=%x\n\r",ret);
			if (ret < 0) {
				g_OutBuff[0] = ~cmd->data[0];
				g_OutBuff[1] = 1;
				g_OutBuff[2] = (-ret) & 0xFF;
				g_OutBuff[3] = rtice_checksum(g_OutBuff, 3);
				rtice_output(g_OutBuff, 4);
			} else if (ret < 0x80) {
				g_OutBuff[1] = cmd->data[0];
				g_OutBuff[2] = ret;
				g_OutBuff[3 + ret] = rtice_checksum(\
							&g_OutBuff[1],\
							2 + ret);
				rtice_output(&g_OutBuff[1], 3 + ret);
			} else if (ret < 0x7FFF) {
				g_OutBuff[0] = cmd->data[0];
				g_OutBuff[1] = 0x80 | ((ret >> 8) & 0x7F);
				g_OutBuff[2] = ret & 0xFF;
				g_OutBuff[3 + ret] = rtice_checksum(\
							&g_OutBuff[0],\
							3 + ret);
				rtice_output(g_OutBuff, 4 + ret);
			}
		respond_end:
			free_rtice_cmd(cmd);
		}
	} while (fDebugModeEnable == 2);
}

/*----------------------------------------------------------------------
 * Func : _rtice_get_command_size
 *
 * Desc : get size of command
 *
 * Parm : cmd : cmd data
 *        len : size of command data
 *
 * Retn : 0 : valid opcode, 0 : invalud opcode
 *----------------------------------------------------------------------*/
int _rtice_get_command_size(unsigned char *cmd, unsigned int len)
{
	int gid = GET_OP_CODE_GROUP(cmd[0]);
	if (rtice_cmd_map[gid].probe == NULL || \
				rtice_cmd_map[gid].probe(cmd[0]) == 0)
		return 0;
	if (len < 3)
		return 3;
	if ((cmd[1] & 0x80) == 0){
		return 3 + cmd[1];
	}else{
		return 4 + ((cmd[1] & 0x7F) << 8) + cmd[2];
	}
}

DECLARE_WORK(rtice_work, _rtice_work);

#define WAKEUP_WORK()  queue_work(wq, &rtice_work)

/*----------------------------------------------------------------------
 * Func : _rtice_input
 *
 * Desc : rtice data input
 *
 * Parm : data
 *
 * Retn : 1 : data handled, 0 : data ingored
 *----------------------------------------------------------------------*/
int _rtice_input(unsigned char data)
{
	static int cmd_len = 0;
	static int rx_len = 0;
	static unsigned long cwt_timeout = 0;
	if (cwt_timeout == 0 || time_after(jiffies, cwt_timeout)){
		rx_len = 0;
		cmd_len = 0;
	}
	cwt_timeout = jiffies + RTICE_COMMAND_CWT;
	if(!fDebugModeEnable){
		unsigned char dcmd0[4] = {0xc0,0x01,0x01,0x3e};
		unsigned char dcmd1[4] = {0xc0,0x01,0x00,0x3f};
		unsigned char dcmd2[3] = {0xc1,0x00,0x3f};

		g_CmdBuff[rx_len++] = data;
		if(g_CmdBuff[0] == 0xc1){
			cmd_len = sizeof(dcmd2);
			if(rx_len > cmd_len || \
				g_CmdBuff[rx_len - 1] != dcmd2[rx_len - 1] ){
				rx_len = 0;
				return 0;
			}
		}else if(g_CmdBuff[0] == 0xc0){
			cmd_len = sizeof(dcmd0);
			if(rx_len > cmd_len || \
				(g_CmdBuff[rx_len - 1] != dcmd0[rx_len - 1] && \
				g_CmdBuff[rx_len - 1] != dcmd1[rx_len - 1] )){
				rx_len = 0;
				return 0;
			}
		}else{
			rx_len = 0;
			return 0;
		}

		if(rx_len == cmd_len){
			rtice_cmd * cmd = NULL;

			if((cmd = alloc_rtice_cmd(rx_len))){

				memcpy(rtice_cmd_put(cmd, rx_len),\
							g_CmdBuff, rx_len);
				_rtice_queue_command(cmd);
				RTICE_CMD_DEBUG(g_CmdBuff, rx_len,\
								"RticeCmd=");
				if(cmd_len == sizeof(dcmd0))
					early_disable_printk();
				else
					early_enable_printk();
				RTICE_DEBUG("Early enter/exit debug mode.\r\n");
				WAKEUP_WORK();
				rx_len = 0;
				cmd_len = 0;
				return 1;
			}
			rx_len = 0;
			cmd_len = 0;
		}
		return 0;
	}
	if (rx_len == 0){
		g_CmdBuff[0] = data;
		cmd_len = _rtice_get_command_size(g_CmdBuff, 1);
		if (cmd_len <= 0)
			goto get_command_error;
		rx_len++;
		return 1;
	}else{
		if (rx_len < cmd_len){
			g_CmdBuff[rx_len++] = data;
			cmd_len = _rtice_get_command_size(g_CmdBuff, rx_len);
			if (cmd_len <= 0 || \
				cmd_len > RTICE_COMMAND_BUFFER_SIZE|| \
				rx_len > RTICE_COMMAND_BUFFER_SIZE)
				goto get_command_error;
			if (rx_len == cmd_len){
				rtice_cmd * cmd;
				cmd = alloc_rtice_cmd(rx_len);
				if (cmd){
					memcpy(rtice_cmd_put(cmd, rx_len),\
						g_CmdBuff, rx_len);
					_rtice_queue_command(cmd);
					RTICE_CMD_DEBUG(g_CmdBuff, rx_len,\
							  "RticeCmd=");
					if(rx_len==4 && \
						g_CmdBuff[0]==0xc0 && \
						g_CmdBuff[1]==0x01 && \
						((g_CmdBuff[2]==0x01 && \
							g_CmdBuff[3]==0x3e) ||\
							(g_CmdBuff[2]==0x00 &&\
							g_CmdBuff[3]==0x3f))){
						early_disable_printk();
						RTICE_DEBUG\
						("early_disable_printk\r\n");
					} else if (rx_len == 3 && \
						g_CmdBuff[0] == 0xc1 && \
						g_CmdBuff[1] == 0x0 && \
						g_CmdBuff[2] == 0x3f) {
						early_enable_printk();
						RTICE_DEBUG\
						("early_enable_printk\r\n");
					}
					WAKEUP_WORK();
				}
				rx_len = 0;
				cmd_len = 0;
			}
			return 1;
		}
	}
	return 0;
get_command_error:
	RTICE_DEBUG("get_command_error  cmd_len = %d, rx_len = %d \n\r",\
							cmd_len, rx_len);
	cmd_len = 0;
	rx_len = 0;
	return 0;
}

/*----------------------------------------------------------------------
 * Func : _rtice_input
 *
 * Desc : rtice data input
 *
 * Parm : data
 *
 * Retn : 1 : data handled, 0 : data ingored
 *----------------------------------------------------------------------*/
int rtice_input(unsigned char *data, unsigned int len)
{
	int ret = 0;
	while (len--)
		ret += _rtice_input(*(data++));
	return ret;
}


/*----------------------------------------------------------------------
 * Func : rtice_register_command_handler
 *
 * Desc : register a command handler
 *
 * Parm : cmd : handle of RTICE command
 *
 * Retn : handle of rtice command buffer
 *----------------------------------------------------------------------*/
int rtice_register_command_handler(
				   rtice_command_handler_t * handler,
				   unsigned char nhandle )
{
	int i = 0;
	for (i = 0; i < nhandle; i++){
		if (rtice_cmd_map[handler[i].group_id].handler == NULL){
			rtice_cmd_map[handler[i].group_id] = handler[i];
		}
	}
	return 0;
}


/*----------------------------------------------------------------------
 * Func : rtice_unregister_command_handler
 *
 * Desc : ungister a command handler
 *
 * Parm : cmd : handle of RTICE command
 *
 * Retn : handle of rtice command buffer
 *----------------------------------------------------------------------*/
void rtice_unregister_command_handler(\
					rtice_command_handler_t * handler,\
					unsigned char nhandle )
{
	int i = 0;
	for (i = 0; i < nhandle; i++){
		if (rtice_cmd_map[handler[i].group_id].handler == \
						handler[i].handler){
			memset(&rtice_cmd_map[i],\
				0,\
				sizeof(rtice_command_handler_t));
		}
	}
}


/*------------------------------------------------------------------
 * Func : rtice_i2c_command_probe
 *
 * Desc : proc i2c command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
static int rtice_flow_command_probe(unsigned char op_code)
{
	return (GET_OP_CODE_COMMAND(op_code) <= 2) ? 1 : 0;
}

/*----------------------------------------------------------------------
 * Func : rtice_do_command
 *
 * Desc : do rtice command
 *
 * Parm :
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
volatile int watchdog_rtice = 1;
static int rtice_flow_control_handler(\
					unsigned char opcode,\
					unsigned char *command_data,\
					unsigned int command_data_len,\
					unsigned char *response_data,\
					unsigned int response_len )
{
	int ret = 0;

	RTICE_DEBUG("rtice_flow_control_handler : opcode = %02x\n\r",\
			opcode);
	RTICE_CMD_DEBUG(command_data, command_data_len, "command_data=");
	RTICE_DEBUG\
		("rtice_flow_control_handler:response_len=%d,cmd[0]=%02x\n\r",\
		response_len, command_data[0]);

	switch (opcode){
	case RTICE_CTRL_CMD_ENTER_DEBUG_MODE:
		if (command_data_len != 1 || command_data[0] > 1)
			return -RTICE_ERR_INVALID_PARAM;
		RTICE_DEBUG("Got Enter Debug Mode (mode=%d)\n\r",\
			      			command_data[0]);
		rtice_enter_debug_mode();
		if (AudioDebugFlagAddr){
			dma_addr_t map_addr;
			map_addr = dma_map_single(\
					NULL,\
					phys_to_virt(AudioDebugFlagAddr),\
					sizeof(AudioDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
			if (AudioDebugFlagBackup == DEBUG_FLAG_NONE)
				AudioDebugFlagBackup = \
				*((unsigned int *)(phys_to_virt(map_addr)));
			*((unsigned int *)(phys_to_virt(map_addr))) = 0;
			dma_unmap_single(NULL, \
						map_addr,\
						sizeof(AudioDebugFlagAddr),\
						DMA_BIDIRECTIONAL);
			}
		if (VideoDebugFlagAddr){
			dma_addr_t map_addr;
			map_addr = dma_map_single(\
					NULL,\
					phys_to_virt(VideoDebugFlagAddr),\
					sizeof(VideoDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
			if (VideoDebugFlagBackup == DEBUG_FLAG_NONE)
				VideoDebugFlagBackup = \
				*((unsigned int *)(phys_to_virt(map_addr)));
			*((unsigned int *)(phys_to_virt(map_addr))) = 0;
			dma_unmap_single(NULL,\
					map_addr,\
					sizeof(VideoDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
		}
		fDebugModeEnable = command_data[0] + 1;
		RTICE_DEBUG(\
		"rtice_flow_control_handler enter:fDebugModeEnable=%x\n\r",\
							fDebugModeEnable);
		#if defined(CONFIG_REALTEK_WATCHDOG) || defined(CONFIG_RTK_KDRV_WATCHDOG)
		if(is_watchdog_enable() == 1)
		{
			watchdog_enable(0);
			watchdog_rtice++;
			rtice_watchdog_disable = 1;
		}
		#endif /*  */
	break;
	case RTICE_CTRL_CMD_EXIT_DEBUG_MODE:
		if (command_data_len)
			return -RTICE_ERR_INVALID_PARAM;
		if (AudioDebugFlagAddr){
			dma_addr_t map_addr;
			map_addr = dma_map_single(\
					NULL,\
					phys_to_virt(AudioDebugFlagAddr),\
					sizeof(AudioDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
			*((unsigned int *)(phys_to_virt(map_addr))) = \
						AudioDebugFlagBackup;
			dma_unmap_single(NULL, \
					map_addr,\
					sizeof(AudioDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
			}
		if (VideoDebugFlagAddr){
			dma_addr_t map_addr;
			map_addr = dma_map_single(\
					NULL,\
					phys_to_virt(VideoDebugFlagAddr),\
					sizeof(VideoDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
			*((unsigned int *)(phys_to_virt(map_addr))) = \
						VideoDebugFlagBackup;
			dma_unmap_single(NULL, \
					map_addr,\
					sizeof(VideoDebugFlagAddr),\
					DMA_BIDIRECTIONAL);
		}
		rtice_exit_debug_mode();
		fDebugModeEnable = 0;
		RTICE_DEBUG\
			("rtice_flow_control_handler exit: "\
			"fDebugModeEnable = %x\n\r",\
			fDebugModeEnable);
		#if defined(CONFIG_REALTEK_WATCHDOG) || defined(CONFIG_RTK_KDRV_WATCHDOG)
		if(rtice_watchdog_disable == 1)
		{
			watchdog_enable(1);
			watchdog_rtice--;
			rtice_watchdog_disable = 0;
		}
		#endif /*  */
		RTICE_DEBUG("Got Exit Debug Mode In Normal Mode\n\r");
	break;
	case RTICE_CTRL_CMD_GET_RTICE_VERSION:
		if (command_data_len)
			return -RTICE_ERR_INVALID_PARAM;
		response_data[0] = 2;
		ret = 1;
		break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}
	return ret;
}

rtice_command_handler_t rtice_flow_handler = \
{
	RTICE_CMD_GROUP_ID_RTICE,
	rtice_flow_command_probe,
	rtice_flow_control_handler
};

__init int rtice_init(void)
{
	memset(rtice_cmd_map, 0, sizeof(rtice_cmd_map));
	spin_lock_init(&rtice_cmd_list_lock);
	wq = create_singlethread_workqueue("rtice");
	rtice_register_command_handler(&rtice_flow_handler,\
		sizeof(rtice_flow_handler) / sizeof(rtice_command_handler_t));
	g_CmdBuff = \
		(unsigned char*)kmalloc(RTICE_COMMAND_BUFFER_SIZE,GFP_ATOMIC);
	g_OutBuff = \
		(unsigned char*)kmalloc(RTICE_COMMAND_BUFFER_SIZE,GFP_ATOMIC);
	printk(KERN_NOTICE\
		"[RTICE]%s alloc input/output buffer size=%d*2 bytes\n",\
		__func__, RTICE_COMMAND_BUFFER_SIZE);
	#ifdef DEBUG_RTICE
	printk(KERN_NOTICE "Enable RTICE DEBUG msg to uart1.\n");
	uart1_enable();
	#endif
	return 1;
}

subsys_initcall(rtice_init);
