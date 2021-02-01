#ifndef __RTICE_I2C_H__
#define __RTICE_I2C_H__

#include "../core/rtk_ice.h"
    typedef struct {
	unsigned char bus;
	 unsigned char addr;
	 unsigned char sub_addr[4];
	 unsigned char sub_addr_len;
	 unsigned char rx_len;
} RTICE_I2C_READ_DATA;
typedef struct {
	unsigned char bus;
	 unsigned char addr;
	 unsigned char sub_addr[4];
	 unsigned char sub_addr_len;
	 unsigned char tx_len;
	 unsigned char data[256];
} RTICE_I2C_WRITE_DATA;
typedef union {
	RTICE_I2C_READ_DATA read;
	RTICE_I2C_WRITE_DATA write;
} RTICE_I2C_CMD_DATA;


#define RTICE_I2C_CMD(x) RTICE_OP_CODE(RTICE_CMD_GROUP_ID_I2C, x)
#define RTICE_I2C_CMD_I2C_READ	 RTICE_OP_CODE(RTICE_CMD_GROUP_ID_I2C, 0)
#define RTICE_I2C_CMD_I2C_WRITE RTICE_OP_CODE(RTICE_CMD_GROUP_ID_I2C, 1)


#define RTICE_I2C_ERR_ABORT		RTICE_FUNC_ERR(0)
#define RTICE_I2C_ERR_TIMEOUT		RTICE_FUNC_ERR(1)
#define RTICE_I2C_ERR_INVALID_BUS_ID	RTICE_FUNC_ERR(2)
#define RTICE_I2C_ERR_INVALID_ADDRESS	RTICE_FUNC_ERR(3)

#ifdef DEBUG_RTICE_I2C
#define RTICE_I2C_DEBUG(fmt, args...)   printk(KERN_DEBUG fmt, ##args)
#else	/*  */
#define RTICE_I2C_DEBUG(args...)
#endif	/*  */

#endif
