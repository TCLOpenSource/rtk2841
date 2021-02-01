#ifndef __RTICE_H__
#define __RTICE_H__

#include "rtk_ice-cmd.h"
#include "rtk_ice-debug.h"
#include "rtk_ice-aux.h"

#define FALSE   0
#define TRUE    1
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef char BOOL;
typedef enum { 
	RTICE_CMD_GROUP_ID_RTICE = 0x18, 
	RTICE_CMD_GROUP_ID_SYSTEM = 0x19, 
	RTICE_CMD_GROUP_ID_IOMEM = 0x1A,
	#ifndef CONFIG_RTK_KDRV_RTICE_BW_CHECK
	RTICE_CMD_GROUP_ID_IOMEM2 = 0x1B,
	#else	/*  */
	RTICE_CMD_GROUP_BW_CHECK = 0x1B,
	#endif	/*  */
	RTICE_CMD_GROUP_ID_I2C = 0x1C, 
	RTICE_CMD_GROUP_ID_ICM = 0x1D, 
	RTICE_CMD_GROUP_ID_AP = 0x1E, 
	RTICE_CMD_GROUP_ID_DMA_STATUS = 0x1F,
	RTICE_CMD_GROUP_ID_MAX = 0x20,
} RTICE_CMD_GROUP_ID;

#define GET_OP_CODE_GROUP(x)        ((x >> 3) & 0x1F)
#define GET_OP_CODE_COMMAND(x)      (x & 0x7)
#define RTICE_OP_CODE(group, cmd)   ((group & 0x1F) <<3 | (cmd & 0x7))

#define RTICE_CTRL_CMD(x) \
				RTICE_OP_CODE(RTICE_CMD_GROUP_ID_RTICE, x)
#define RTICE_CTRL_CMD_ENTER_DEBUG_MODE    \
				RTICE_OP_CODE(RTICE_CMD_GROUP_ID_RTICE, 0)
#define RTICE_CTRL_CMD_EXIT_DEBUG_MODE \
				RTICE_OP_CODE(RTICE_CMD_GROUP_ID_RTICE, 1)
#define RTICE_CTRL_CMD_GET_RTICE_VERSION \
				RTICE_OP_CODE(RTICE_CMD_GROUP_ID_RTICE, 2)

#define RTICE_ERR_NOT_IN_DEBUG_MODE		0
#define RTICE_ERR_UNSUPPORTED_OP_CODE		1
#define RTICE_ERR_LRC_ERROR			2
#define RTICE_ERR_INVALID_PARAM            	3
#define RTICE_ERR_CHARACTER_TIMEOUT        	4

#define RTICE_FUNC_ERR(detailed_error)    (128 + detailed_error)
#define RTICE_FUNC_ERR_1(detailed_error)    (192 + detailed_error)
typedef struct {
	RTICE_CMD_GROUP_ID group_id;
	int (*probe) (unsigned char op_code);
	int (*handler) (unsigned char op_code, unsigned char *p_cmd_data,\
			 unsigned int cmd_len, unsigned char *p_response,\
			 unsigned int response_len);
} rtice_command_handler_t;

extern void rtice_output(unsigned char *data, unsigned int len);
extern int rtice_input(unsigned char *data, unsigned int len);
extern int rtice_enter_debug_mode(void);
extern int rtice_exit_debug_mode(void);
int rtice_register_command_handler(rtice_command_handler_t * handler,\
						unsigned char nhandler);
void rtice_unregister_command_handler(rtice_command_handler_t * handler,\
						unsigned char nhandler);

#endif	/*  */
