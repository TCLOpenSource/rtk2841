/*
 * rtice2ap_driver.h -- definitions for the char module
 *
 * Copyright (C) 2001 Alessandro Rubini and Jonathan Corbet
 * Copyright (C) 2001 O'Reilly & Associates
 * Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
 * The source code in this file can be freely used, adapted,
 * and redistributed in source or binary form, so long as an
 * acknowledgment apears in derived source files.  The citation
 * should list that the code comes from the book "Linux Device
 * Drivers" by Alessandro Rubini and Jonathan Corbet, published
 * by O'Reilly & Associates.   No warranty is attached;
 * we cannot take responsibility for errors or fitness for use.
 *
 * $Id: se.h,v 1.15 2004/11/04 17:51:18 rubini Exp $
 */

#ifndef __RTK_ICE_AP_DRIVER_H__
#define __RTK_ICE_AP_DRIVER_H__

#ifndef RTICE_MAJOR
#define RTICE_MAJOR 0   /* dynamic major by default */
#endif

#ifndef RTICE_NR_DEVS
#define RTICE_NR_DEVS 1    /* se0 through se3 */
#endif

typedef struct {
	unsigned char id[4];
	unsigned char size[2];
	unsigned char flag;
} ap_data;
/**
 \brief Params struct for read or write video table. 
**/
typedef struct {
	unsigned char id[2];/*Id of VIP Table*/
	unsigned char start_addr[4];
	unsigned char end_addr[4];
	unsigned char data_len[4];
	unsigned char mode1;
	unsigned char mode2;
	unsigned char flag;/* flag of read or write.*/
} ap_param;

enum RTICE_AP_STATUS {
	NO_CMD,
	RTICE_REC_CMD,
	AP_REC_DATA
};
enum RTICE_READ_STATUS {
	DEV_READ_CMD,
	DEV_READ_DATA,
	DEV_READ_ERROR,
	DEV_READ_SUCCEED,
	DEV_READ_CMD_EX
};
enum RTICE_WRITE_STATUS {
	DEV_WRITE_DATA,
	DEV_WRITE_STATUS,
	DEV_WRITE_ERROR,
	DEV_WRITE_SUCCEED
};

extern enum RTICE_READ_STATUS rtice_read_status;
extern enum RTICE_WRITE_STATUS rtice_write_status;
extern unsigned int rtice_data_size;
extern ap_data *kern_ap;
extern ap_param *kern_param;
extern unsigned char *rtice_ap_buffer;
/*void putchar(char ch);*/
/**
 * @brief wakeup_kernel Wake up rtice driver who is waiting the conditions.
 * @param timeoutMs Timeout about wakeup the rtice driver.The unit is 'ms'.
 * @return Returns FALSE while fail to wake up,otherwise returns TRUE.
**/
char wakeup_kernel(unsigned int timeoutMs);
/**
 * @brief wakeup_ap Wake up rtice2ap driver who is waiting the conditions.
 * @param timeoutMs Timeout about wakeup the rtice2ap driver.The unit is 'ms'.
 * @return Returns FALSE while fail to wake up,otherwise returns TRUE.
**/
char wakeup_ap(unsigned int timeoutMs);

#endif
