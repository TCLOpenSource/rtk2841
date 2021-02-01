#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/i2c.h>
#include "rtk_ice-i2c.h"
#include <linux/string.h>
#include <linux/module.h>
extern volatile UINT8 fDebugModeEnable;

/*------------------------------------------------------------------
 * Func : rtice_i2c_command_probe
 *
 * Desc : proc i2c command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
int rtice_i2c_command_probe(unsigned char op_code)
{
	return (GET_OP_CODE_COMMAND(op_code) <= 1) ? 1 : 0;
}

/*------------------------------------------------------------------
 * Func : rtice_i2c_command_handler
 *
 * Desc : proc i2c command
 *
 * Parm : cmd_data : command data
 *        cmd_len  : command data len
 *        rdata  : response data
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/

int rtice_i2c_command_handler(
			      unsigned char opcode, unsigned char *cmd_data,
			      unsigned int cmd_len,
			      unsigned char *response_data,
			      unsigned int response_buff_size )
{
	RTICE_I2C_READ_DATA * pRead;
	RTICE_I2C_WRITE_DATA * pWrite;
	unsigned char data[32];
	int ret = 0;

	RTICE_I2C_DEBUG("bus_id=%d, addr=%02x, "\
	"sub_addr = %02x %02x %02x %02x(sub_addr_len=%d), rx_len=%d\n", \
				pRead->bus, pRead->addr, pRead->sub_addr[0], \
				pRead->sub_addr[1], \
				pRead->sub_addr[2],\
				pRead->sub_addr[3], \
				pRead->sub_addr_len,\
				pRead->rx_len);
	switch (opcode){
	case RTICE_I2C_CMD_I2C_WRITE:
		pWrite = (RTICE_I2C_WRITE_DATA *) cmd_data;
		memset(data, 0, sizeof(data));
		if (pWrite->sub_addr_len){
			if (pWrite->sub_addr_len >= 4)
				pWrite->sub_addr_len = 4;
			memcpy(data,\
				&pWrite->sub_addr[(4 - pWrite->sub_addr_len)],\
				pWrite->sub_addr_len);
			memcpy(data + pWrite->sub_addr_len, \
				pWrite->data,\
				 cmd_len);
		}
#if 0 // FIXME for bringup 443 compile issue
			ret = i2c_master_send_ex(pWrite->bus, \
				pWrite->addr >> 1,data,\
				(pWrite->sub_addr_len + pWrite->tx_len));

		}else{

			ret = i2c_master_send_ex(pWrite->bus, \
						pWrite->addr >> 1,\
						pWrite->data, \
						pWrite->tx_len);

		}
		ret = (ret == 1) ? 0 : -RTICE_I2C_ERR_ABORT;
#endif
	break;
	case RTICE_I2C_CMD_I2C_READ:
		pRead = (RTICE_I2C_READ_DATA *) cmd_data;
		RTICE_I2C_DEBUG("bus_id=%d, addr=%02x, "\
	"sub_addr = %02x %02x %02x %02x (sub_addr_len=%d), rx_len=%d\n", \
				pRead->bus, pRead->addr, \
				pRead->sub_addr[0], \
				pRead->sub_addr[1], pRead->sub_addr[2], \
				pRead->sub_addr[3], pRead->sub_addr_len, \
				pRead->rx_len);
		if (pRead->sub_addr_len){
			if (pRead->sub_addr_len >= 4)
				pRead->sub_addr_len = 4;
		}
#if 0 // FIXME for bringup 443 compile issue
			ret = i2c_master_recv_ex(pRead->bus, pRead->addr >> 1,\
				&pRead->sub_addr[(4 -pRead->sub_addr_len)],\
				pRead->sub_addr_len,\
				response_data, pRead->rx_len);
 			ret = (ret==2) ? pRead->rx_len : -RTICE_I2C_ERR_ABORT;
		}else{

			ret = i2c_master_recv_ex(pRead->bus, pRead->addr >> 1,\
							NULL,0,response_data,\
							pRead->rx_len);

			ret = (ret==1) ? pRead->rx_len : -RTICE_I2C_ERR_ABORT;
		}
#endif
	break;
	default:
		ret = -RTICE_ERR_UNSUPPORTED_OP_CODE;
	}
	return ret;
}

rtice_command_handler_t i2c_cmd_handler = \
{
	RTICE_CMD_GROUP_ID_I2C,
	rtice_i2c_command_probe,
	rtice_i2c_command_handler
};

/*------------------------------------------------------------------
 * Func : rtice_i2c_tool_init
 *
 * Desc : register rtice i2c tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtice_i2c_tool_init(void)
{
	rtice_register_command_handler(&i2c_cmd_handler,\
		sizeof(i2c_cmd_handler) / sizeof(rtice_command_handler_t));
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtice_i2c_tool_exit
 *
 * Desc : exit rtice i2c tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_i2c_tool_exit(void)
{
	rtice_unregister_command_handler(&i2c_cmd_handler,\
		sizeof(i2c_cmd_handler) / sizeof(rtice_command_handler_t));
}

module_init(rtice_i2c_tool_init);
module_exit(rtice_i2c_tool_exit);
