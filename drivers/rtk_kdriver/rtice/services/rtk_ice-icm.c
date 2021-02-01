#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <rbus/rbusColor_icmReg.h>
#include "rtk_ice-icm.h"
 extern volatile UINT8 fDebugModeEnable;


#define MAX_CM_TYPE		6
#define MAX_CM_ADDR		7
#define MAX_CM_SUBADDR		6
#define MAX_CM_SEG		8

#define DM_SEG_SHY_SRAM_CTRL_TYPE(x)		((x & 0x7) << 12)
#define DM_SEG_SHY_SRAM_CTRL_ADDR(x)		((x & 0x7) << 8)
#define DM_SEG_SHY_SRAM_CTRL_SUB_ADDR(x)	((x & 0x7) << 15)
#define DM_SEG_SHY_SRAM_CTRL_SEG(x)		((x & 0x7) << 4)
#define DM_SEG_SHY_SRAM_CTRL_RANDOM_ACCESS_EN	(0x1<<2)
#define DM_SEG_SHY_SRAM_CTRL_WRITE_EN		(0x1<<1)
#define DM_SEG_SHY_SRAM_CTRL_READ_EN		(0x1)
#define DM_GET_SHY_SRAM_M_S_SEL() \
	((rtd_inl(COLOR_ICM_DM_SEG_SHY_SRAM_CTRL_VADDR) >>11)&0x1)
#define DM_SEG_SHY_SRAM_M_S_SEL(x) \
	((x&0x1) << 11)

#define SET_DM_SEG_SHY_SRAM_CTRL(val) \
	rtd_outl(COLOR_ICM_DM_SEG_SHY_SRAM_CTRL_VADDR, val)
#define GET_DM_SEG_SHY_SRAM_CTRL() \
	rtd_inl(COLOR_ICM_DM_SEG_SHY_SRAM_CTRL_VADDR)
#define GET_DM_SEG_SHY_READ_SEG_RANDOM() \
	rtd_inl(COLOR_ICM_DM_SEG_SHY_READ_SEG_RANDOM_VADDR)
#define SET_DM_SEG_SHY_WRITE_SEG_RANDOM(val) \
	rtd_outl(COLOR_ICM_DM_SEG_SHY_WRITE_SEG_RANDOM_VADDR, val)


/*------------------------------------------------------------------
 * Func : rtice_icm_read_segment
 *
 * Desc : read icm segment
 *
 * Parm : cm_type : CM Type (0~MAX_CM_TYPE)
 *          0 : type 0 (dSat_bysat)
 *          1 : type 1 (dHue_bysat)
 *          2 : type 2 (dSG_bysat)
 *          3 : type 3 (dSat_byi)
 *          4 : type 4 (dHue_byi)
 *          5 : type 5 (delta_I_new_mode)
 *
 *        cm_addr     : which CM to read (0~MAX_CM_ADDR)
 *        cm_sub_addr : subaddress of cm
 *        cm_seg      : segment of sub region
 *        p_cm_val    : cm segment data output
 *
 * Retn : 0 : successed, -1 : failed
 *------------------------------------------------------------------*/
static int rtice_icm_read_segment(
				  unsigned char cm_type, unsigned char cm_addr,
				  unsigned char cm_sub_addr,
				  unsigned char cm_seg,
				  unsigned long *p_cm_val )
{
	dm_seg_shy_sram_ctrl_RBUS sram_ctrl;
	int time_out = 10;
	*p_cm_val = 0xdeaddead;
	if (cm_type >= MAX_CM_TYPE || cm_addr >= MAX_CM_ADDR
	      || cm_sub_addr >= MAX_CM_SUBADDR || cm_seg >= MAX_CM_SEG)
		return -1;
	sram_ctrl.regValue = 0;
	sram_ctrl.shy_address_type_sel = cm_type;
	sram_ctrl.shy_address_cm_sel = cm_addr;
	sram_ctrl.shy_address_sub_cm_sel = cm_sub_addr;
	sram_ctrl.shy_address_seg_sel = cm_seg;
	sram_ctrl.read_en = 1;
	sram_ctrl.shy_m_s_sel = DM_GET_SHY_SRAM_M_S_SEL();
	SET_DM_SEG_SHY_SRAM_CTRL(sram_ctrl.regValue);

	do
		 {
		udelay(100);
	} while ((sram_ctrl.regValue = GET_DM_SEG_SHY_SRAM_CTRL())
			  && sram_ctrl.read_en && (time_out-- > 0));
	if (sram_ctrl.read_en)
		return -1;
	*p_cm_val = GET_DM_SEG_SHY_READ_SEG_RANDOM();
	return 0;
}




/*------------------------------------------------------------------
 * Func : rtice_icm_write_segment
 *
 * Desc : write icm segment
 *
 * Parm : cm_type : CM Type (0~MAX_CM_TYPE)
 *          0 : type 0 (dSat_bysat)
 *          1 : type 1 (dHue_bysat)
 *          2 : type 2 (dSG_bysat)
 *          3 : type 3 (dSat_byi)
 *          4 : type 4 (dHue_byi)
 *          5 : type 5 (delta_I_new_mode)
 *
 *        cm_addr     : which CM to be written (0~MAX_CM_ADDR)
 *        cm_sub_addr : subaddress of cm
 *        cm_seg      : segment of sub region
 *        cm_seg_val      : cm segment value
 *
 * Retn : 0 : successed, -1 : failed
 *------------------------------------------------------------------*/
static int rtice_icm_write_segment(
				unsigned char cm_type,
				unsigned char cm_addr,
				unsigned char cm_sub_addr,
				unsigned char cm_seg,
				unsigned long cm_seg_val )
{
	int time_out = 10;
	if (cm_type >= MAX_CM_TYPE || cm_addr >= MAX_CM_ADDR
	      || cm_sub_addr >= MAX_CM_SUBADDR || cm_seg >= MAX_CM_SEG)
		return -1;
	unsigned char cM_S_SEL = DM_GET_SHY_SRAM_M_S_SEL();
	SET_DM_SEG_SHY_SRAM_CTRL(DM_SEG_SHY_SRAM_CTRL_TYPE(cm_type) |
			DM_SEG_SHY_SRAM_CTRL_ADDR(cm_addr) |
			DM_SEG_SHY_SRAM_M_S_SEL(cM_S_SEL) |
			DM_SEG_SHY_SRAM_CTRL_SUB_ADDR(cm_sub_addr) |
			DM_SEG_SHY_SRAM_CTRL_SEG(cm_seg) |
			DM_SEG_SHY_SRAM_CTRL_RANDOM_ACCESS_EN);
	SET_DM_SEG_SHY_WRITE_SEG_RANDOM(cm_seg_val);
	SET_DM_SEG_SHY_SRAM_CTRL(DM_SEG_SHY_SRAM_CTRL_TYPE(cm_type) |
			DM_SEG_SHY_SRAM_CTRL_ADDR(cm_addr) |
			DM_SEG_SHY_SRAM_M_S_SEL(cM_S_SEL) |
			DM_SEG_SHY_SRAM_CTRL_SUB_ADDR(cm_sub_addr) |
				   DM_SEG_SHY_SRAM_CTRL_SEG(cm_seg) |
				   DM_SEG_SHY_SRAM_CTRL_RANDOM_ACCESS_EN |
				   DM_SEG_SHY_SRAM_CTRL_WRITE_EN);

	do
		 {
		udelay(100);
	} while (GET_DM_SEG_SHY_SRAM_CTRL() &
			  DM_SEG_SHY_SRAM_CTRL_WRITE_EN && (time_out-- > 0));
	if (GET_DM_SEG_SHY_SRAM_CTRL() & DM_SEG_SHY_SRAM_CTRL_WRITE_EN)
		return -1;
	return 0;
}




/*------------------------------------------------------------------
 * Func : rtice_icm_command_probe
 *
 * Desc : proc icm command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
int rtice_icm_command_probe(unsigned char op_code)
{
	return (GET_OP_CODE_COMMAND(op_code) <= 2) ? 1 : 0;
}


/*------------------------------------------------------------------
 * Func : rtice_icm_command_handler
 *
 * Desc : proc icm command
 *
 * Parm : cmd_data : command data
 *        cmd_len  : command data len
 *        rdata  : response data
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/
int rtice_icm_command_handler(
			      unsigned char opcode, unsigned char *cmd_data,
			      unsigned int cmd_len,
			      unsigned char *response_data,
			      unsigned int response_buff_size )
{
	unsigned char *pCMData;
	int sub_addr;
	int seg;
	int ret = 0;

	switch (opcode){
	case RTICE_ICM_GET_CM_INFO:
		response_data[0] = MAX_CM_TYPE;
		response_data[1] = MAX_CM_ADDR;
		response_data[2] = MAX_CM_SUBADDR;
		response_data[3] = MAX_CM_SEG;
		ret = 4;
	break;
	case RTICE_ICM_READ_CM:
		if (cmd_len != 2)
			return -RTICE_ERR_INVALID_PARAM;
		if (cmd_data[0] >= MAX_CM_TYPE)
			return -RTICE_ICM_ERR_INVALID_CM_TYPE;
		if (cmd_data[1] >= MAX_CM_ADDR)
			return -RTICE_ICM_ERR_INVALID_CM_ADDR;
		for (sub_addr = 0; sub_addr < MAX_CM_SUBADDR; sub_addr++)
			 {
			for (seg = 0; seg < MAX_CM_SEG; seg++)
				 {
				unsigned long seg_val;
				rtice_icm_read_segment(cmd_data[0],
							cmd_data[1], sub_addr,
							seg, &seg_val);
				response_data[ret++] = (seg_val >> 24) & 0xFF;
				response_data[ret++] = (seg_val >> 16) & 0xFF;
				response_data[ret++] = (seg_val >> 8) & 0xFF;
				response_data[ret++] = (seg_val) & 0xFF;
			} } 
	break;
	case RTICE_ICM_WRITE_CM:
		if (cmd_data[0] >= MAX_CM_TYPE)
			return -RTICE_ICM_ERR_INVALID_CM_TYPE;
		if (cmd_data[1] >= MAX_CM_ADDR)
			return -RTICE_ICM_ERR_INVALID_CM_ADDR;
		if (cmd_len != (2 + (MAX_CM_SUBADDR * MAX_CM_SEG * 4)))
			return -RTICE_ICM_ERR_INVALID_CM_DATA_LENGTH;
		pCMData = &cmd_data[2];
		for (sub_addr = 0; sub_addr < MAX_CM_SUBADDR; sub_addr++)
			 {
			for (seg = 0; seg < MAX_CM_SEG; seg++)
				 {
				unsigned long seg_val =
					(pCMData[0] << 24) + \
					(pCMData[1] << 16) + \
					(pCMData[2] << 8) + pCMData[3];
				rtice_icm_write_segment(cmd_data[0],\
							cmd_data[1], sub_addr,\
							seg, seg_val);
				pCMData += 4;
			} } response_data[0] =
		rtice_checksum(&cmd_data[2], cmd_len - 2);
		ret = 1;
	break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}
	return ret;
}

rtice_command_handler_t icm_cmd_handler = {
	RTICE_CMD_GROUP_ID_ICM, 
	rtice_icm_command_probe,
	rtice_icm_command_handler
};

/*------------------------------------------------------------------
 * Func : rtice_icm_tool_init
 *
 * Desc : register rtice icm tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtice_icm_tool_init(void)
{
	rtice_register_command_handler(&icm_cmd_handler,\
		sizeof(icm_cmd_handler) / sizeof(rtice_command_handler_t));
	return 0;
}


/*------------------------------------------------------------------
 * Func : rtice_icm_tool_exit
 *
 * Desc : exit rtice icm tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_icm_tool_exit(void)
{
	rtice_unregister_command_handler(&icm_cmd_handler,\
		sizeof(icm_cmd_handler) / sizeof(rtice_command_handler_t));
}

module_init(rtice_icm_tool_init);
module_exit(rtice_icm_tool_exit);
