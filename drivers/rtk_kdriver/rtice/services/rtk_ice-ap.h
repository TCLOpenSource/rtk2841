#ifndef __RTICE_AP_H__
#define __RTICE_AP_H__

#include "../core/rtk_ice.h"
#include "rtk_ice_ap_driver.h"

/*OPCode Code*/
/*read ap cmd*/
#define RTICE_AP_CMD(x)	 \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, x) 
#define RTICE_AP_CMD_READ_ID_SIZE \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 0)
#define RTICE_AP_CMD_READ_NUM_DATA \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 1)
#define RTICE_AP_CMD_READ_REC_FINISH	 \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 2)
/*write ap cmd*/
#define RTICE_AP_CMD_WRITE_ID_SIZE \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 3)
#define RTICE_AP_CMD_WRITE_NUM_DATA	\
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 4)
#define RTICE_AP_CMD_WRITE_STATUS \
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_AP, 5)
/*Error Code*/
#define RTICE_AP_ERR_ABORT                  		RTICE_FUNC_ERR(0)
#define RTICE_AP_ERR_TIMEOUT                		RTICE_FUNC_ERR(1)
#define RTICE_AP_ERR_INVALID_ID_SIZE        	RTICE_FUNC_ERR(2)
#define RTICE_AP_ERR_INVALID_PACKAGE_NUM    	RTICE_FUNC_ERR(3)
#define RTICE_AP_ERR_READ_DATA_FAILED       	RTICE_FUNC_ERR(4)
#define RTICE_AP_ERR_WRITE_DATA_FAILED      	RTICE_FUNC_ERR(5)

#define DEBUG_RTICE_AP 0

#ifdef DEBUG_RTICE_AP
#define RTICE_AP_DEBUG(fmt, args...)   printk(KERN_DEBUG fmt, ##args)
#else
#define RTICE_AP_DEBUG(args...)
#endif

#endif /*__RTICE_AP_H__*/