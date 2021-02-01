/*============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2006 *
 * All rights reserved.                                       *
 *===========================================================*/
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/workqueue.h>
#include "rtk_ice-cmd.h"

/*----------------------------------------------------------------------
 * Func : CHECK_BOUNDRARY
 *
 * Desc : check boundrary function
 *
 * Parm : cmd : handle of RTICE command
 *
 * Retn : handle of rtice command buffer
 *----------------------------------------------------------------------*/
static void CHECK_BOUNDRARY(rtice_cmd * cmd)
{
	if (cmd->data < cmd->head || cmd->tail > cmd->end \
		|| cmd->tail < cmd->data){
		rtice_cmd_warning(\
		"Error cmd(%p) : head=%p, data=%p, tail=%p, end=%p\n",\
					cmd, \
					cmd->head, \
					cmd->data, \
					cmd->tail, \
					cmd->end);
	}
}

/*----------------------------------------------------------------------
 * Func : alloc_rtice_cmd
 *
 * Desc : alloc a rtice command buffer with specified length
 *
 * Parm : len : size of rtice command
 *
 * Retn : handle of rtice command buffer
 *----------------------------------------------------------------------*/
rtice_cmd * alloc_rtice_cmd(unsigned int len)
{
	rtice_cmd * cmd;
	len += sizeof(rtice_cmd);
	cmd = (rtice_cmd *) kmalloc(len, GFP_ATOMIC);
	if (cmd){
		rtice_cmd_dbg("alloc rtice command buffer %p (len = %d)\n",\
								cmd,len);
		INIT_LIST_HEAD(&cmd->list);
		cmd->head = (unsigned char *)cmd + sizeof(rtice_cmd);
		cmd->data = cmd->head;
		cmd->tail = cmd->head;
		cmd->end = cmd->head + len - sizeof(rtice_cmd);
		cmd->len = 0;
	}
	return cmd;
}

/*----------------------------------------------------------------------
 * Func : free_rtice_cmd
 *
 * Desc : free a rtice command with specified length
 *
 * Parm : cmd : command buffer
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void free_rtice_cmd(rtice_cmd * cmd)
{
	unsigned long len;
	if (cmd){
		len = (unsigned long)cmd->end - (unsigned long)cmd;
		rtice_cmd_dbg("Free Buffer %p (len = %ul)\n", cmd, len);
		kfree((void *)cmd);
	}
}

/*----------------------------------------------------------------------
 * Func : rtice_cmd_reserve
 *
 * Desc : reserve an area in front of rtice command
 *
 * Parm : cmd : command buffer
 *        len : size to reserve
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void rtice_cmd_reserve(rtice_cmd * cmd, unsigned int len)
{
	cmd->data += len;
	cmd->tail += len;
	CHECK_BOUNDRARY(cmd);
}

/*----------------------------------------------------------------------
 * Func : rtice_cmd_put
 *
 * Desc : put data from tail of rtice command
 *
 * Parm : cmd : command buffer
 *        len : size to put
 *
 * Retn : previous buffer tail
 *----------------------------------------------------------------------*/
unsigned char *rtice_cmd_put(rtice_cmd * cmd, unsigned int len)
{
	unsigned char *ptr = cmd->tail;
	cmd->tail += len;
	cmd->len += len;
	CHECK_BOUNDRARY(cmd);
	return ptr;
}


/*----------------------------------------------------------------------
 * Func : rtice_cmd_trim
 *
 * Desc : remove data from tail of rtice command buffer
 *
 * Parm : cmd : command buffer
 *        len : size to remove
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void rtice_cmd_trim(rtice_cmd * cmd, unsigned int len)
{
	cmd->tail -= len;
	cmd->len -= len;
	CHECK_BOUNDRARY(cmd);
}

/*----------------------------------------------------------------------
 * Func : rtice_cmd_purge
 *
 * Desc : clear all data of mcp buffer
 *
 * Parm : mcpb : mcp buffer
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void rtice_cmd_purge(rtice_cmd * cmd)
{
	cmd->data = cmd->head;
	cmd->tail = cmd->head;
	cmd->len = 0;
}
