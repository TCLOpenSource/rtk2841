#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/i2c.h>
#include <linux/slab.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include "rtk_ice-ap.h"

#ifdef CONFIG_SUPPORT_SCALER
#include <tvscalercontrol/scaler/scalerthread_rtice2ap.h>
static ap_data_param rtice_param_write;
#endif

#define PACKAGE_SIZE    2046

enum
{
	READ_AP = 1,
	WRITE_AP = 2,
	READ_ERROR = 3,
	WRITE_ERROR = 4,
	WRITE_SUCCEED = 5,
	ID_SIZE_ERR = 6,
};

unsigned int rtice_data_size = 0;
static char recv_finish_flag = 0;
enum RTICE_READ_STATUS rtice_read_status = DEV_READ_CMD;
enum RTICE_WRITE_STATUS rtice_write_status = DEV_WRITE_DATA;
unsigned char *rtice_ap_buffer = NULL;
enum RTICE_AP_STATUS rtice_status = NO_CMD;

static DECLARE_WAIT_QUEUE_HEAD (rtice_wait);

char wakeup_kernel(unsigned int timeoutMs)
{
	while((rtice_status != NO_CMD) && timeoutMs--){
		msleep(1);
	}
	if(rtice_status == NO_CMD){
		rtice_status = AP_REC_DATA;
		wake_up(&rtice_wait);
		return TRUE;
	}
	return FALSE;
}

/*------------------------------------------------------------------
 * Func : rtice_ap_command_handler
 *
 * Desc : proc ap command
 *
 * Parm : cmd_data : command data
 *        command_data_len  : command data len
 *
 * Retn :  < 0    : error
 * others : length of response data
	Read AP ID SIZE value:
		op_code(0xF0) command_data_len id[4] size[2] rtice_checksum
	Read data package num:
		op_code(0xF1) 0x1 package_num rtice_checksum
	Read data finished:
		op_code(0xF2) 0 rtice_checksum
	Write AP ID SIZE value:
		op_code(0xF3) command_data_len id[4] size[2] rtice_checksum
	Write AP num package data:
		op_code(0xF4) command_data_len package_num data rtice_checksum
	Write AP data status:
		op_cod(0xF5) 0 rtice_checksum
 *------------------------------------------------------------------*/
int rtice_ap_command_handler(\
				unsigned char opcode,
				unsigned char* cmd_data,\
				unsigned int command_data_len,\
				unsigned char* response_data,\
				unsigned int response_buff_size)
{
	int ret = 0;
	int package_num;
	unsigned char num;
	int i;
	int last_package_size;
	ap_data *p_rtice = kern_ap;
	ap_param *p_param = kern_param;
	unsigned char *read_buffer_tmp;
	unsigned int opt_timeout = 50;/*timeout of read or write is 500 ms*/

#ifdef DEBUG_RTICE_TIMEOUT
	unsigned int reg_v = 0;
#endif

	switch(opcode){
	case RTICE_AP_CMD_READ_ID_SIZE:
		if(command_data_len  == 6){
			memcpy(p_rtice,cmd_data,command_data_len);
			p_rtice->flag = READ_AP;
			p_param->flag = READ_AP;
			rtice_read_status = DEV_READ_CMD;
			rtice_data_size = (p_rtice->size[0]<<8) + \
							p_rtice->size[1];
		}else if(command_data_len  == 16){
			memcpy(p_param,cmd_data,command_data_len);
			p_param->flag = READ_AP;
			p_rtice->flag = READ_AP;
			rtice_read_status = DEV_READ_CMD_EX;
			rtice_data_size = B4TL(p_param->data_len[0], \
						p_param->data_len[1],\
						p_param->data_len[2],\
						p_param->data_len[3]);
		}else{
			ret = -RTICE_ERR_INVALID_PARAM;
			goto error_return;
		}
		if(rtice_ap_buffer != NULL){
			kfree(rtice_ap_buffer);
		}
		rtice_ap_buffer = (char *)kmalloc(rtice_data_size,GFP_KERNEL);
		if(rtice_ap_buffer == NULL)
			return -RTICE_AP_ERR_ABORT;
		#ifndef CONFIG_SUPPORT_SCALER
		if(wakeup_ap(opt_timeout * 10) == FALSE){
			/*rtice2ap driver is not waiting conditions.*/
			ret = -RTICE_AP_ERR_TIMEOUT;
			goto error_return;
		}
		#else
		wakeup_ap(1);/*try wakeup ap thread anyway*/
		#endif

		#ifdef DEBUG_RTICE_TIMEOUT
		/*read time out*/
		reg_v = rtd_inl(RTICE_TIMEOUT_REG);
		reg_v = reg_v & 0xffff;
		if(reg_v > 100)
			opt_timeout = reg_v;
		#endif


		rtice_status = NO_CMD;/*Prepare to wait rtice2ap response*/
		#ifdef CONFIG_SUPPORT_SCALER
		if (rtice_data_size > 0){
			int ret;
			ap_data_param rtice_param;
			rtice_param.id = (((unsigned short)cmd_data[0]<<8) + \
					((unsigned short)cmd_data[1]));
			rtice_param.saddr= B4TL(cmd_data[2],\
						cmd_data[3],\
						cmd_data[4],\
						cmd_data[5]);
			rtice_param.eaddr= B4TL(cmd_data[6],\
						cmd_data[7],\
						cmd_data[8],\
						cmd_data[9]);
			rtice_param.mode0= cmd_data[14];
			rtice_param.mode1= cmd_data[15];
			rtice_param.size = rtice_data_size - 1;

			if((ret = rtice_get_vip_table(rtice_param, \
						&rtice_ap_buffer[0],\
						&rtice_ap_buffer[1]) ) < 0){
				if(ret == -ID_SIZE_ERR){
					p_param->flag = ID_SIZE_ERR;
				}else{
					p_param->flag = READ_ERROR;
				}
			}
			rtice_write_status = DEV_WRITE_SUCCEED;
			rtice_status = AP_REC_DATA;
		}
		#else
		wait_event_timeout(rtice_wait, \
					(rtice_status == AP_REC_DATA),\
					opt_timeout);
		#endif

		if((rtice_status != AP_REC_DATA)){
			/*device not respond,rtice wait timeout*/
			ret = -RTICE_AP_ERR_TIMEOUT;
			goto error_return;
		}
		if((rtice_read_status == DEV_READ_ERROR) || \
				(rtice_write_status == DEV_WRITE_ERROR)){
			ret = -RTICE_AP_ERR_READ_DATA_FAILED;
			goto error_return;
		}
		if(p_rtice->flag == READ_ERROR || p_param->flag == READ_ERROR){
			/*AP return read data error*/
			ret = -RTICE_AP_ERR_READ_DATA_FAILED;
			goto error_return;
		}
		if(p_rtice->flag == ID_SIZE_ERR || \
						p_param->flag == ID_SIZE_ERR){
			/*AP return ID or SIZE error*/
			ret = -RTICE_AP_ERR_INVALID_ID_SIZE;
			goto error_return;
		}
	break;
	case RTICE_AP_CMD_READ_NUM_DATA:
		if (command_data_len != 1){
			ret = -RTICE_ERR_INVALID_PARAM;
			goto error_return;
		}
		if((rtice_ap_buffer == NULL) || \
				(rtice_write_status != DEV_WRITE_SUCCEED)){
			ret = -RTICE_AP_ERR_ABORT;
			goto error_return;
		}
		read_buffer_tmp = rtice_ap_buffer;
		num = cmd_data[0];
		last_package_size = rtice_data_size % PACKAGE_SIZE;
		if(last_package_size){
			package_num = rtice_data_size / PACKAGE_SIZE + 1;
		}else{
			package_num = rtice_data_size / PACKAGE_SIZE;
			last_package_size = PACKAGE_SIZE;
		}

		read_buffer_tmp += (PACKAGE_SIZE * (num - 1));
		response_data[0] = num;
		if((num > 0 ) && (num < package_num)){
			memcpy(&response_data[1],read_buffer_tmp,PACKAGE_SIZE);
			read_buffer_tmp += PACKAGE_SIZE;
			ret = PACKAGE_SIZE + 1;
		}else if(num == package_num){
			if(last_package_size == 0)
				last_package_size = PACKAGE_SIZE;
			memcpy(&response_data[1],read_buffer_tmp,\
							last_package_size);
			read_buffer_tmp += last_package_size;
			ret = last_package_size + 1;
		}else{
			ret = -RTICE_AP_ERR_INVALID_PACKAGE_NUM;
			goto error_return;
		}
	break;
	case RTICE_AP_CMD_READ_REC_FINISH:
		if(rtice_ap_buffer != NULL){
			kfree(rtice_ap_buffer);
			rtice_ap_buffer = NULL;
		}
	break;
	case RTICE_AP_CMD_WRITE_ID_SIZE: /*write data to ap flow*/
		if(command_data_len  == 6){
			memcpy(p_rtice,cmd_data,command_data_len);
			p_rtice->flag = WRITE_AP;
			p_param->flag = WRITE_AP;
			rtice_read_status = DEV_READ_CMD;
			rtice_data_size = (p_rtice->size[0] << 8) + \
							p_rtice->size[1];
		}else if(command_data_len  == 16){
			memcpy(p_param,cmd_data,command_data_len);
			p_param->flag = WRITE_AP;
			p_rtice->flag = WRITE_AP;
			rtice_read_status = DEV_READ_CMD_EX;
			rtice_data_size = 0;
			for(i=0;i < 4;i++){
				rtice_data_size <<= 8;
				rtice_data_size += p_param->data_len[i];
			}
		}else{
			ret = -RTICE_ERR_INVALID_PARAM;
			goto error_return;
		}

		if(rtice_ap_buffer != NULL)
			kfree(rtice_ap_buffer);
		rtice_ap_buffer = (char *)kmalloc(rtice_data_size,GFP_KERNEL);
		if(rtice_ap_buffer == NULL)
			return -RTICE_AP_ERR_ABORT;

		#ifdef CONFIG_SUPPORT_SCALER
		rtice_param_write.id = (((unsigned short)cmd_data[0]<<8) + \
					((unsigned short)cmd_data[1]));
		rtice_param_write.saddr= B4TL(cmd_data[2],\
					cmd_data[3],\
					cmd_data[4],\
					cmd_data[5]);
		rtice_param_write.eaddr= B4TL(cmd_data[6],\
					cmd_data[7],\
					cmd_data[8],\
					cmd_data[9]);
		rtice_param_write.mode0= cmd_data[14];
		rtice_param_write.mode1= cmd_data[15];
		rtice_param_write.size = rtice_data_size;
		rtice_read_status = DEV_READ_SUCCEED;
		#else
		if(wakeup_ap(opt_timeout * 10) == FALSE){
			/*rtice2ap driver is not waiting conditions.*/
			ret = -RTICE_AP_ERR_TIMEOUT;
			goto error_return;
		}
		/*
		wait_event_timeout(rtice_wait, \
			(rtice_read_status != DEV_READ_CMD ||\
			rtice_read_status != DEV_READ_CMD_EX),opt_timeout);
		*/
		i = 0;
		while(i < opt_timeout){
			msleep(5);
			if(rtice_read_status != DEV_READ_CMD ||\
				rtice_read_status != DEV_READ_CMD_EX)
				break;
			i += 5;
		}
		#endif
		if(rtice_read_status == DEV_READ_SUCCEED){
			rtice_read_status = DEV_READ_DATA;
			return 0;
		}else{
			ret = -RTICE_AP_ERR_ABORT;
			goto error_return;
		}
	break;
	case RTICE_AP_CMD_WRITE_NUM_DATA:
		if(rtice_ap_buffer == NULL){
			ret = -RTICE_AP_ERR_ABORT;
			goto error_return;
		}
		recv_finish_flag = 0;
		read_buffer_tmp = rtice_ap_buffer;
		num = cmd_data[0];
		last_package_size = rtice_data_size%PACKAGE_SIZE;
		if(last_package_size){
			package_num = rtice_data_size/PACKAGE_SIZE +1;
		}else{
			package_num = rtice_data_size/PACKAGE_SIZE;
			last_package_size = PACKAGE_SIZE;
		}

		read_buffer_tmp += (PACKAGE_SIZE * (num - 1));
		if((num > 0 )&& (num < package_num)){
			if((command_data_len - 1) !=PACKAGE_SIZE){
				ret = -RTICE_AP_ERR_WRITE_DATA_FAILED;
				goto error_return;
			}
			memcpy(read_buffer_tmp,&cmd_data[1],PACKAGE_SIZE);
			read_buffer_tmp += PACKAGE_SIZE;
		}else if(num == package_num){
			if((command_data_len - 1) !=last_package_size){
				ret = -RTICE_AP_ERR_WRITE_DATA_FAILED;
				goto error_return;
			}
			memcpy(read_buffer_tmp,&cmd_data[1],last_package_size);
			read_buffer_tmp += last_package_size;
			/*receive last package means receive finished*/
			recv_finish_flag = 1;
		}else{
			ret = -RTICE_AP_ERR_INVALID_PACKAGE_NUM;
			goto error_return;
		}
		response_data[0] = num;
		ret = 1;
		RTICE_DEBUG("[%s]recv_finish_flag=%d\r\n",__func__,\
							recv_finish_flag);
	break;
	case RTICE_AP_CMD_WRITE_STATUS:
		if(recv_finish_flag){
			rtice_read_status = DEV_READ_DATA;
			rtice_write_status = DEV_WRITE_STATUS;
			#ifndef CONFIG_SUPPORT_SCALER
			if(wakeup_ap(opt_timeout * 10) == FALSE){
				/*rtice2ap driver is not waiting conditions.*/
				ret = -RTICE_AP_ERR_TIMEOUT;
				goto error_return;
			}
			#endif
			rtice_status = NO_CMD;
			#ifdef DEBUG_RTICE_TIMEOUT
			/*read time out*/
			reg_v = rtd_inl(RTICE_TIMEOUT_REG);
			reg_v = reg_v & 0xffff;
			if(reg_v > 200)
				opt_timeout = reg_v;
			#endif
			#ifdef CONFIG_SUPPORT_SCALER
			/*if (rtice_data_size > 1)*/
			{
				int ret;
				ret = rtice_set_vip_table(rtice_param_write, \
							rtice_ap_buffer);
				if(ret == 0){
					p_param->flag = WRITE_SUCCEED;
				}else if(ret == -ID_SIZE_ERR){
					p_param->flag = ID_SIZE_ERR;
				}else{
					p_param->flag = WRITE_ERROR;
				}
				rtice_status = AP_REC_DATA;
				rtice_read_status = DEV_READ_SUCCEED;
			}
			#else
			wait_event_timeout(rtice_wait,\
					(rtice_status == AP_REC_DATA),\
					opt_timeout > 20 ? opt_timeout : 20);
			#endif
			if((rtice_status != AP_REC_DATA)){
				ret = -RTICE_AP_ERR_TIMEOUT;
				goto error_return;
			}
			if((rtice_read_status == DEV_READ_ERROR) || \
				(rtice_write_status == DEV_WRITE_ERROR)){
				ret = -RTICE_AP_ERR_WRITE_DATA_FAILED;
				goto error_return;
			}
			if(p_rtice->flag == WRITE_SUCCEED || \
					p_param->flag == WRITE_SUCCEED){
				kfree(rtice_ap_buffer);
				rtice_ap_buffer = NULL;
				return 0;
			}else if(p_rtice->flag == ID_SIZE_ERR ||\
					p_param->flag == ID_SIZE_ERR){
				ret = -RTICE_AP_ERR_INVALID_ID_SIZE;
				goto error_return;
			}else{
				RTICE_DEBUG("[%s]p_param->flag=%d\r\n",\
								__func__,\
								p_param->flag);
				ret = -RTICE_AP_ERR_WRITE_DATA_FAILED;
				goto error_return;
			}
		}else{
			ret = -RTICE_AP_ERR_WRITE_DATA_FAILED;
			goto error_return;
		}
	break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}
	return ret;
error_return:
	if(rtice_read_status == DEV_READ_DATA){
		rtice_data_size = 0;
		rtice_read_status = DEV_READ_CMD;
		wakeup_ap(opt_timeout * 10);
	}
	if(rtice_ap_buffer){
		kfree(rtice_ap_buffer);
		rtice_ap_buffer = NULL;
	}
	return ret;
}

/*------------------------------------------------------------------
 * Func : rtice_ap_command_probe
 *
 * Desc : proc ap command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
int rtice_ap_command_probe(unsigned char op_code)
{
	return (GET_OP_CODE_COMMAND(op_code) <= 5) ? 1 : 0;
}

rtice_command_handler_t ap_cmd_handler[] =
{
	{
		RTICE_CMD_GROUP_ID_AP,
		rtice_ap_command_probe,
		rtice_ap_command_handler
	},
};

/*------------------------------------------------------------------
 * Func : rtice_ap_tool_init
 *
 * Desc : register rtice ap tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtice_ap_tool_init(void)
{
	rtice_register_command_handler(ap_cmd_handler, \
		sizeof(ap_cmd_handler)/sizeof(rtice_command_handler_t));
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtice_ap_tool_exit
 *
 * Desc : exit rtice ap tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_ap_tool_exit(void)
{
	rtice_unregister_command_handler(ap_cmd_handler, \
		sizeof(ap_cmd_handler)/sizeof(rtice_command_handler_t));
	printk("rtice_unregister_command_handler() has been executed.\n");
}

module_init(rtice_ap_tool_init);
module_exit(rtice_ap_tool_exit);
