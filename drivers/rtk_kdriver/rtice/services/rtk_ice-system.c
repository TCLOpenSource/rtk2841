#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/gfp.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <mach/platform.h>
#include "rtk_ice-system.h"
#include <rtk_sb2_callback.h>
#include "panelConfigParameter.h"

#include <linux/string.h>
#ifdef CONFIG_REALTEK_PCBMGR
#include "mach/pcbMgr.h"
#define PCB_NAME_BUFFER_SIZE 1024
#define FS_OPT_BUFFER_SIZE 2046

int get_pcb_names(char *tmp)
{
	char const *patternsplit = "\x2C";
	char *buf, *token, *pch;
	char pattern[16];
	char *names;
	int ret;
	
	if(tmp==NULL)
	{
	    RTICE_DEBUG("%s tmp is null\n",__func__);
            return -1;
        }

	names = (char *)kmalloc(PCB_NAME_BUFFER_SIZE, GFP_ATOMIC);
	if(names==NULL) {
	    RTICE_DEBUG("%s alloc for names failed\n",__func__);
	    return -1;
	}
		
	memset(names, 0, PCB_NAME_BUFFER_SIZE);
	buf = platform_info.pcb_enum_parameter;
	if(buf==NULL) {
	    RTICE_DEBUG("%s buf is null\n",__func__);
	    kfree(names);
	    return -1;
	}

	RTICE_DEBUG("[%s] pcb len = %d, get buf strlen = %d \n\r", __func__,\
		     	strlen(platform_info.pcb_enum_parameter), strlen(buf));
	sprintf(pattern, "pcb_enum=");
	while ((pch = strsep(&buf, patternsplit))) {
		if(pch) {
			token = strstr(pch, pattern);
			if ((token!=NULL) && (pattern!=NULL)) {
				if (strlen(names)){
					sprintf(names, "%s,%s",\
						names,token + strlen(pattern));
				}
				else{
					sprintf(names, "%s", token + strlen(pattern));
				}
			}
		}
	}
	ret = sprintf(tmp, "%s", names);
	RTICE_DEBUG("[%s] -------ret = %d \n\r", __func__, ret);
	kfree(names);
	return ret;
}
#endif	/*  */
/*File operation cmd methods defined here*/
static struct file *gfp = 0;
/**Close file that been opened by 'openFile'**/
static int closeFile(void)
{
	if(gfp != 0 && !IS_ERR(gfp))
		filp_close(gfp,0);
	gfp = 0;
	return 0;
}
/**Open file specified by pFilename and returns file size saved at pSize while read successfully**/
static int openFile(const char*pFilename,unsigned int*pSize,int openMode)
{
	mm_segment_t oldFs;

	*pSize = 0;
	/*try close file previous opened*/
	closeFile();
	/*set fs*/
	oldFs = get_fs();
	set_fs(KERNEL_DS);
	/*try open file*/
	gfp = filp_open(pFilename,openMode,0);
	if(gfp == 0 || IS_ERR(gfp)){
		set_fs(oldFs);
		return PTR_ERR(gfp);
	}
	*pSize = gfp->f_path.dentry->d_inode->i_size;
	set_fs(oldFs);
	return 0;
}
/**Read file data at address specified by 'offset'.And total read size specified by 'size'.
	The data are saved in the buffer whose address is 'pOut'.
	Notice that it must called after 'openFile' method otherwise returns false.
**/
static int readFileData(unsigned int offset,unsigned int size,char*pOut)
{
	mm_segment_t oldFs;
	unsigned int filesize = 0;
	loff_t pos = offset;

	if(size > FS_OPT_BUFFER_SIZE)
		return -RTICE_FS_OPT_ERR_WRONG_SIZE;
	if(gfp == 0 || IS_ERR(gfp))
		return -RTICE_FS_OPT_ERR_OPEN;
	filesize = gfp->f_path.dentry->d_inode->i_size;
	if(offset + size > filesize)
		return -RTICE_FS_OPT_ERR_WRONG_SIZE;
	/*read data*/
	oldFs = get_fs();
	set_fs(KERNEL_DS);
	if(size != vfs_read(gfp,pOut,size, &pos)){
		set_fs(oldFs);
		return -RTICE_FS_OPT_ERR_RW_FAIL;
	}
	set_fs(oldFs);
	return size;
}
/**Write data to file at address specified by 'offset'.pData and size indicate data for writting.
	Notice that it must called after 'openFile' method otherwise returns false.
**/
static int writeFileData(unsigned int offset,unsigned int size,char*pData)
{
	mm_segment_t oldFs;
	loff_t pos = offset;

	if(size > FS_OPT_BUFFER_SIZE)
		return -RTICE_FS_OPT_ERR_WRONG_SIZE;
	if(gfp == 0 || IS_ERR(gfp))
		return -RTICE_FS_OPT_ERR_OPEN;
	/*write data*/
	oldFs = get_fs();
	set_fs(KERNEL_DS);
	if(size != vfs_write(gfp,pData,size, &pos)){
		set_fs(oldFs);
		return -RTICE_FS_OPT_ERR_RW_FAIL;
	}
	set_fs(oldFs);
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtice_system_command_handler
 *
 * Desc : proc iomem command
 *
 * Parm : cmd_data : command data
 *        command_data_len  : command data len
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/
int rtice_system_command_handler(\
				unsigned char opcode, unsigned char *cmd_data,\
				unsigned int command_data_len,\
				unsigned char *response_data,\
				unsigned int response_buff_size )
{
	int ret = 0;
#if defined(CONFIG_REALTEK_PCBMGR)
	char pcbname[command_data_len + 1];
	unsigned long long pcbvalue;
#endif	/*  */

	switch (opcode){
	case RTICE_SYS_CMD_SET_BUSERR_IGNORE_ADDR:
		if (command_data_len < 4)
			return -RTICE_ERR_INVALID_PARAM;
		{
			unsigned long addr = B4TL(cmd_data[0], cmd_data[1],
						  cmd_data[2], cmd_data[3]);

			BUSERR_IGNORE_SET(addr);
			RTICE_DEBUG("[RTICE_SET_BUSERR_IGNORE_ADDR] addr(0x%x) \n\r", addr);
		}
		break;
	case RTICE_SYS_CMD_READ_SYSTEM_INFO:
		if (command_data_len != 1)
			return -RTICE_ERR_INVALID_PARAM;
		switch (cmd_data[0]){
		case RTICE_SYSTEM_INFO_ID_CPU_ID:
			ret = sprintf(response_data,"%x",platform_info.cpu_id);
		break;
		case RTICE_SYSTEM_INFO_ID_BOARD_ID:
			ret = sprintf(response_data,"%x",\
						platform_info.board_id);
		break;
		case RTICE_SYSTEM_INFO_ID_BOOTLOADER_VERSION:
			ret = sprintf(response_data, "%s",\
					platform_info.bootloader_version);
		break;
		case RTICE_SYSTEM_INFO_ID_AUDIO_FW_VERSION:
			ret = sprintf(response_data, "Unknown");
		break;
		case RTICE_SYSTEM_INFO_ID_VIDEO_FW_VERSION:
			ret = sprintf(response_data, "Unknown");
		break;
		case RTICE_SYSTEM_INFO_ID_KERNEL_SOURCE_CODE_INFO:
			ret = sprintf(response_data, "%s",\
					platform_info.kernel_source_code_info);
		break;
		case RTICE_SYSTEM_INFO_ID_SYSTEM_PARAMETERS:
			ret = sprintf(response_data, "%s", \
					platform_info.system_parameters);
		break;
		case RTICE_SYSTEM_INFO_ID_PANEL_NAME:
		{
			PANEL_CONFIG_PARAMETER *panel_parameter = NULL;
			panel_parameter = (PANEL_CONFIG_PARAMETER*)&platform_info.panel_parameter;
			ret = snprintf(response_data,sizeof(panel_parameter->sPanelName),"%s", \
					panel_parameter->sPanelName);
		}
		break;
		default:
			ret = -RTICE_IOMEM_ERR_INVALID_SYSTEM_INFO;
		}
		if (ret <= 0)
			ret = -RTICE_IOMEM_ERR_INVALID_SYSTEM_INFO;
	break;
	case RTICE_SYS_CMD_READ_PCB_PARAMETER:
		#if defined(CONFIG_REALTEK_PCBMGR)
		switch (cmd_data[0]) {
		case RTICE_PCB_INFO_SEARCH:
			snprintf(pcbname, command_data_len, "%s",cmd_data + 1);
			ret = pcb_mgr_get_enum_info_byname(pcbname, &pcbvalue);
			ret = sprintf(response_data, "%x",\
						(unsigned int)pcbvalue);
			RTICE_DEBUG(\
	"[RTICE_PCB_INFO_SEARCH] data = %s,value = %x , return %d(%s) \n\r", \
					pcbname, pcbvalue, ret, response_data);
		break;
		case RTICE_PCB_INFO_GET_ALL_NAME:
			ret = get_pcb_names(response_data);
		break;
		default:
			ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
		};
		#else
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
		#endif
	break;
	case RTICE_SYS_CMD_FS_OPT:
	{
		ENUM_RTICE_FS_OPT opt = (ENUM_RTICE_FS_OPT)cmd_data[0];
		if (command_data_len < 1)
			return -RTICE_ERR_INVALID_PARAM;
		if(opt == RTICE_FS_OPT_OPEN || opt == RTICE_FS_OPT_OPEN_RW || opt == RTICE_FS_OPT_OPEN_RW_TRUNC){
			unsigned int size = 0;
			int openMode = 0;

			if(opt == RTICE_FS_OPT_OPEN)
				openMode = O_RDONLY;
			else if(opt == RTICE_FS_OPT_OPEN_RW)
				openMode = O_RDWR;
			else if(opt == RTICE_FS_OPT_OPEN_RW_TRUNC)
				openMode = O_RDWR | O_TRUNC;
			cmd_data[command_data_len] = '\0';
			ret = openFile((char*)&cmd_data[1],&size,openMode);
			if(ret == 0){
				LTB4(size,response_data[0],response_data[1],\
						response_data[2],response_data[3]);
				ret = 4;
			}
		}else if(opt == RTICE_FS_OPT_CLOSE){
			ret = closeFile();
		}else if(opt == RTICE_FS_OPT_READ){
			unsigned int offset = 0,size = 0;

			if(command_data_len != 9)
				return -RTICE_ERR_INVALID_PARAM;
			offset = B4TL(cmd_data[1],cmd_data[2],cmd_data[3],cmd_data[4]);
			size = B4TL(cmd_data[5],cmd_data[6],cmd_data[7],cmd_data[8]);
			ret = readFileData(offset,size,response_data);
		}else if(opt == RTICE_FS_OPT_WRITE){
			unsigned int offset = 0,size = 0;

			if(command_data_len < 5)
				return -RTICE_ERR_INVALID_PARAM;
			offset = B4TL(cmd_data[1],cmd_data[2],cmd_data[3],cmd_data[4]);
			size = command_data_len - 5;
			if(size)
				ret = writeFileData(offset,size,&cmd_data[5]);
		}else{
			return -RTICE_ERR_INVALID_PARAM;
		}
	}
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
int rtice_system_command_probe(unsigned char op_code)
{
	switch (op_code)
	{
	case RTICE_SYS_CMD_READ_SYSTEM_INFO:
	case RTICE_SYS_CMD_READ_PCB_PARAMETER:
	case RTICE_SYS_CMD_SET_BUSERR_IGNORE_ADDR:
	case RTICE_SYS_CMD_FS_OPT:
		return 1;
	}
	return 0;
}

rtice_command_handler_t system_cmd_handler[] =  \
{
	{
		RTICE_CMD_GROUP_ID_SYSTEM, 
		rtice_system_command_probe,
		rtice_system_command_handler
	},
};

/*------------------------------------------------------------------
 * Func : rtice_system_tool_init
 *
 * Desc : register rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtice_system_tool_init(void)
{
	rtice_register_command_handler(system_cmd_handler,\
		sizeof(system_cmd_handler) /sizeof(rtice_command_handler_t));
	return 0;
}


/*------------------------------------------------------------------
 * Func : rtice_system_tool_exit
 *
 * Desc : exit rtice io/mem tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_system_tool_exit(void)
{
	rtice_unregister_command_handler(system_cmd_handler,\
		sizeof(system_cmd_handler) /sizeof(rtice_command_handler_t));
	printk("rtice_unregister_command_handler() has been executed.\n");
}

module_init(rtice_system_tool_init);
module_exit(rtice_system_tool_exit);
