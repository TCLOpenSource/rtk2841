#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <asm/page.h>
#include <mach/io.h>
#include "rtk_ice-iomem.h"
#ifdef CONFIG_RKDRV_MD
#include <rtk_kdriver/md/rtk_md.h>
#endif

extern unsigned long max_low_pfn;
struct task_struct *checkOverflow_tsk = NULL;
volatile UINT8 *backupRegAddr = NULL;
volatile UINT8 regNum = 0;
volatile static UINT32 *regValues = NULL;
volatile static UINT32 timeCounter = 0;
volatile UINT8 fThreadStop = 0x00;
extern volatile UINT8 fDebugModeEnable;

#define SAFE_FREE(x) \
if(x){ \
	kfree((void*)(x)); \
	(x) = NULL; \
}


/**after merlin2 , Rbus range extend to 0xb8200000 , old SOC range is narrow **/
#define REGISTER_L_BOUNDARY 0xb8000000
#define REGISTER_U_BOUNDARY 0xb8200000

#define MEMORY_L_BOUNDARY CONFIG_PAGE_OFFSET
#define MEMORY_U_BOUNDARY (CONFIG_PAGE_OFFSET + (max_low_pfn << PAGE_SHIFT))

BOOL Rtice_ChecAddrValid(unsigned int addr)
{
	if (addr >= REGISTER_L_BOUNDARY && addr < REGISTER_U_BOUNDARY)
		return TRUE;

	else if (addr >= MEMORY_L_BOUNDARY && addr < MEMORY_U_BOUNDARY)
		return TRUE;
	return FALSE;
}

/*------------------------------------------------------------------
 * Func : rtice_checkRegisterOverflow_task
 *
 * Desc : the thread function used to check register overflow
 *
 * Parm : arg_unused - unused
 *
 * Retn : 0 - success, others fail
 *------------------------------------------------------------------*/
static int rtice_checkRegisterOverflow_task(void *arg_unused)
{
	UINT8 i;
	UINT32 RegAddr_temp;
	UINT32 * regValues_temp = NULL;
	timeCounter = 0;
	fThreadStop = 0;

	SAFE_FREE(regValues);
	regValues = (UINT32 *) kmalloc(sizeof(*regValues)*regNum, GFP_ATOMIC);
	if (!regValues){
		return (0);
	}
	memset(regValues,0,sizeof(*regValues)*regNum);
	for (i = 0; i < regNum; i++){
		RegAddr_temp = (((UINT32) backupRegAddr[i * 4]) << 24) |\
				(((UINT32) backupRegAddr[1 + i * 4]) << 16) |\
				(((UINT32) backupRegAddr[2 + i * 4]) << 8) |\
				backupRegAddr[3 + i * 4];
		*(regValues + i) = rtd_inl(RegAddr_temp);
	}
	regValues_temp = (UINT32 *) kmalloc(sizeof(*regValues_temp) * regNum, \
								GFP_ATOMIC);
	if (!regValues_temp)
		goto thread_end;
	memset(regValues_temp,0,sizeof(*regValues_temp) * regNum);
	do{
		msleep(50);
		for (i = 0; i < regNum; i++){
			RegAddr_temp = (((UINT32)backupRegAddr[i*4]) << 24) |\
				(((UINT32) backupRegAddr[1 + i * 4]) << 16) |\
				(((UINT32) backupRegAddr[2 + i * 4]) << 8) |\
				backupRegAddr[3 + i * 4];
			*(regValues_temp + i) = rtd_inl(RegAddr_temp);
		}
		for (i = 0; i < regNum; i++){
			if ((*(regValues_temp + i) == 0xFFFFFFFF) ||\
				(*(regValues_temp + i) < *(regValues + i))){
				kfree((void *)regValues_temp);
				regValues_temp = NULL;
				goto thread_end;
			}
		}
		for (i = 0; i < regNum; i++){
			*(regValues + i) = *(regValues_temp + i);
		}
		timeCounter++;
		if (timeCounter >= 2 * 60 * 1000 / 50){
			SAFE_FREE(regValues_temp);
			SAFE_FREE(regValues);
			return (0);
		}
		if (kthread_should_stop()){
			break;
		}
	} while (1);
thread_end:
	fThreadStop = 1;
	SAFE_FREE(regValues_temp);
	return (0);
}

/*------------------------------------------------------------------
 * Func : rtice_iomem_command_handler
 *
 * Desc : proc iomem command
 *
 * Parm : cmd_data : command data
 *        command_data_len  : command data len
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/
int rtice_iomem_command_handler(\
				unsigned char opcode, unsigned char *cmd_data,\
				unsigned int command_data_len,\
				unsigned char *response_data,\
				unsigned int response_buff_size )
{
	UINT32 AcceptedAddr;
	UINT32 GetData;
	unsigned char n_reg;
	int ret = 0;
	int i;

	switch (opcode){
	case RTICE_IOMEM_CMD_NORMAL_READ:
		if (command_data_len != 5)
			return -RTICE_ERR_INVALID_PARAM;
		ret = 0;
 		AcceptedAddr = B4TL(cmd_data[0], cmd_data[1], \
				     	cmd_data[2], cmd_data[3]);
		for (i = 0; i < cmd_data[4]; i++){
			if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
				smd_memcpy(&GetData, AcceptedAddr, 4);
#else
				return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
			}
			else{
				GetData = rtd_inl(AcceptedAddr);
			}
			LTB4(GetData, response_data[0], response_data[1],\
					response_data[2], response_data[3]);
			AcceptedAddr += 4;
			response_data += 4;
			ret += 4;
		}
	break;
	case RTICE_IOMEM_CMD_NORMAL_WRITE:
		if (command_data_len != 8)
			return -RTICE_ERR_INVALID_PARAM;
		AcceptedAddr = B4TL(cmd_data[0], cmd_data[1], \
						cmd_data[2], cmd_data[3]);
		GetData = B4TL(cmd_data[4], cmd_data[5], \
						cmd_data[6], cmd_data[7]);
		if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
			smd_memcpy(AcceptedAddr, &GetData, 4);
#else
			return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
		}
        else{
			rtd_outl(AcceptedAddr, GetData);
		}
	break;
	case RTICE_IOMEM_CMD_DATA_PORT_WRITE:
		if (command_data_len < 6)
			return -RTICE_ERR_INVALID_PARAM;
		if (command_data_len != 6 + cmd_data[0])
			return -RTICE_ERR_INVALID_PARAM;
		AcceptedAddr = B4TL(cmd_data[1], cmd_data[2], \
						cmd_data[3], cmd_data[4]);
		if (((cmd_data[0] + 1) % 4))
			return -RTICE_IOMEM_ERR_INVALID_LENGTH;
		for (i = 0; i < cmd_data[0] + 1; i += 4){
			GetData = B4TL(cmd_data[5 + i], cmd_data[6 + i],\
					cmd_data[7 + i], cmd_data[8 + i]);

			if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
				smd_memcpy(AcceptedAddr, &GetData, 4);
#else
				return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
			}
			else{
				rtd_outl(AcceptedAddr, GetData);
			}
		}
	break;
	case RTICE_IOMEM_CMD_DATA_PORT_READ:
		if (command_data_len != 5)
			return -RTICE_ERR_INVALID_PARAM;
		AcceptedAddr = B4TL(cmd_data[1], cmd_data[2], \
						cmd_data[3], cmd_data[4]);
		if (!Rtice_ChecAddrValid(AcceptedAddr))
			return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
		if (((cmd_data[0] + 1) % 4))
			return -RTICE_IOMEM_ERR_INVALID_LENGTH;
		for (i = 0; i < cmd_data[0] + 1; i += 4){
			if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
				smd_memcpy(&GetData, AcceptedAddr, 4);
#else
				return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
			}
			else{
				GetData = rtd_inl(AcceptedAddr);
			}
			LTB4(GetData, response_data[0], response_data[1],\
					response_data[2], response_data[3]);
			ret += 4;
			response_data += 4;
		}
	break;
	case RTICE_IOMEM_CMD_MULTI_READ:
		if (command_data_len < 5)
			return -RTICE_ERR_INVALID_PARAM;
		if (command_data_len != 1 + (4 * cmd_data[0]))
			return -RTICE_ERR_INVALID_PARAM;
		n_reg = cmd_data[0];
		cmd_data++;
		for (i = 0; i < n_reg; i++){
			AcceptedAddr = B4TL(cmd_data[0], cmd_data[1], \
						cmd_data[2], cmd_data[3]);
			if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
				smd_memcpy(&GetData, AcceptedAddr, 4);
#else
				return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
			}
			else{
				GetData = rtd_inl(AcceptedAddr);
			}
			LTB4(GetData, response_data[0], response_data[1],\
					response_data[2], response_data[3]);
			ret += 4;
			response_data += 4;
			cmd_data += 4;
		}
	break;
	case RTICE_IOMEM_CMD_MULTI_WRITE:
		if (command_data_len < 9)
			return -RTICE_ERR_INVALID_PARAM;
		if (command_data_len != 1 + (8 * cmd_data[0]))
			return -RTICE_ERR_INVALID_PARAM;
		n_reg = cmd_data[0];
		cmd_data++;
		for (i = 0; i < n_reg; i++){
			AcceptedAddr = B4TL(cmd_data[0], cmd_data[1], \
						cmd_data[2],cmd_data[3]);
			GetData = B4TL(cmd_data[4], cmd_data[5], \
						cmd_data[6],cmd_data[7]);
			cmd_data += 8;

			if (!Rtice_ChecAddrValid(AcceptedAddr)){
#ifdef CONFIG_RKDRV_MD
				smd_memcpy(AcceptedAddr, &GetData, 4);
#else
				return -RTICE_IOMEM_ERR_INVALID_ADDRESS;
#endif
			}
			else{
				rtd_outl(AcceptedAddr, GetData);
			}
		}
	break;
	case RTICE_IOMEM_CMD_START_BUS_MONITOR:
		if (command_data_len < 5)
			return -RTICE_ERR_INVALID_PARAM;
		if (command_data_len != 1 + (4 * cmd_data[0]))
			return -RTICE_ERR_INVALID_PARAM;
		regNum = cmd_data[0];
		if (backupRegAddr)
			return -RTICE_IOMEM_ERR_BUS_MONITOR_IS_RUNNING;
		SAFE_FREE(backupRegAddr);
		backupRegAddr = \
			(UINT8 *) kmalloc(sizeof(*backupRegAddr)*(regNum * 4),\
								GFP_ATOMIC);
		if (backupRegAddr == NULL)
			return \
		-RTICE_IOMEM_ERR_CREATE_BUS_MONITOR_REGISTER_TABLE_FAILED;
		for (i = 0; i < (regNum * 4); i++){
			if (i % 4 == 0){
				AcceptedAddr = B4TL(cmd_data[i + 1],\
							cmd_data[i + 2],\
							cmd_data[i + 3], \
							cmd_data[i + 4]);
				if (!Rtice_ChecAddrValid(AcceptedAddr)){
					SAFE_FREE(backupRegAddr);
 					return \
					-RTICE_IOMEM_ERR_INVALID_ADDRESS;
				}
			}
			*(backupRegAddr + i) = *(cmd_data + i + 1);
		}
		if (!checkOverflow_tsk)
			checkOverflow_tsk = kthread_create(\
					rtice_checkRegisterOverflow_task,\
					NULL, "checkOverflow");
		if (IS_ERR(checkOverflow_tsk)){
			printk("Unable to create thread checkOverflow.\n");
			checkOverflow_tsk = NULL;
			SAFE_FREE(backupRegAddr);
			return \
			-RTICE_IOMEM_ERR_CREATE_BUS_MONITOR_THREAD_FAILED;
		}
		wake_up_process(checkOverflow_tsk);
	break;
	case RTICE_IOMEM_CMD_STOP_BUS_MONITOR:
		if (command_data_len)
			return -RTICE_ERR_INVALID_PARAM;
		if (!backupRegAddr){
			return -RTICE_IOMEM_ERR_BUS_MONITOR_FAILED;
		}
		if (!checkOverflow_tsk){
			SAFE_FREE(backupRegAddr);
			return -RTICE_IOMEM_ERR_BUS_MONITOR_FAILED;
		}
		if (!regValues || !timeCounter){
			SAFE_FREE(backupRegAddr);
			SAFE_FREE(regValues);
			fThreadStop = 1;
			checkOverflow_tsk = NULL;
			return -RTICE_IOMEM_ERR_BUS_MONITOR_FAILED;
		}
		if (timeCounter >= 2 * 60 * 1000 / 50){
			SAFE_FREE(backupRegAddr);
			SAFE_FREE(regValues);
			fThreadStop = 1;
			checkOverflow_tsk = NULL;
			return -RTICE_IOMEM_ERR_CREATE_BUS_MONITOR_TIMEOUT;
		}
		if (fThreadStop)
			goto data_putchar;
		kthread_stop(checkOverflow_tsk);
		while (!fThreadStop)
			msleep(5);
	data_putchar:
		checkOverflow_tsk = NULL;
		SAFE_FREE(backupRegAddr);
		for (i = 0; i < regNum; i++){
			LTB4(*(regValues + i), \
				response_data[0],\
				response_data[1], \
				response_data[2],\
				response_data[3]);
			ret += 4;
			response_data += 4;
		}
		SAFE_FREE(regValues);
	break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}
	return ret;
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
int rtice_iomem_command_probe(unsigned char op_code)
{
	return 1;
}

rtice_command_handler_t iomem_cmd_handler[] =  \
{
	{
		RTICE_CMD_GROUP_ID_IOMEM,
		rtice_iomem_command_probe,
		rtice_iomem_command_handler
	},
};

/*------------------------------------------------------------------
 * Func : rtice_iomem_tool_init
 *
 * Desc : register rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtice_iomem_tool_init(void)
{
	rtice_register_command_handler(iomem_cmd_handler,\
		sizeof(iomem_cmd_handler) /sizeof(rtice_command_handler_t));
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtice_iomem_tool_exit
 *
 * Desc : exit rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_iomem_tool_exit(void)
{
	rtice_unregister_command_handler(iomem_cmd_handler,\
		sizeof(iomem_cmd_handler) / sizeof(rtice_command_handler_t));
	printk("rtice_unregister_command_handler() has been executed.\n");
	/*free some buffer*/
	SAFE_FREE(backupRegAddr);
	SAFE_FREE(regValues);
}

module_init(rtice_iomem_tool_init);
module_exit(rtice_iomem_tool_exit);
