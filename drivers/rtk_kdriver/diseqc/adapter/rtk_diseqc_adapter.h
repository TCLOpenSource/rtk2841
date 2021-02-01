/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_DISEQC_ADAPTER_H__
#define __RTK_DISEQC_ADAPTER_H__

#include <linux/wait.h>
#include <linux/timer.h>
#include <linux/completion.h>
#include "../core/rtk_diseqc.h"
#include "../core/rtk_diseqc_data_buff.h"

//#ifdef 284x
#include "rtk_diseqc_rtd284x-reg.h"
//#else
//#endif

//#define ID_RTK_CEC_CONTROLLER     0x1778
#define ID_RTK_DISEQC_CONTROLLER     0x2778

#define RX_RING_LENGTH  	16
#define TX_RING_LENGTH  	16



typedef struct {
	unsigned char enable:1;
	unsigned char state:7;
	diseqc_data_buff *ddb;
	unsigned long timeout;
	struct delayed_work work;
} rtk_diseqc_xmit;

typedef struct {
	unsigned char enable:1;
	unsigned char state:7;
	diseqc_data_buff *ddb;
	wait_queue_head_t wq;
	struct delayed_work work;
} rtk_diseqc_rcv;

enum {
	MODULATED_TONE_BURST = 0,
	UN_MODULATED_TONE_BURST = 1,
	DISEQC_MESSAGE = 2,
	CONTINUOUS_TONE = 3
};

enum {
	TX_STOP = 0,
	TX_START = 1
};

enum {
	DISEQC_IDEL,
	DISEQC_XMIT,
	DISEQC_RCV
};

enum {
	DISEQC_RCV_OK,
	DISEQC_RCV_FAIL
};

/*
#define CEC_MODE_OFF        0
#define CEC_MODE_ON         1
#define CEC_MODE_STANDBY    2
*/

typedef struct {
	struct {
		unsigned char init:1;
		unsigned char enable:1;
		unsigned char standby_mode:1;
	} status;

	rtk_diseqc_xmit xmit;
	rtk_diseqc_rcv rcv;
	diseqc_data_buff_head tx_queue;
	diseqc_data_buff_head rx_queue;
	diseqc_data_buff_head rx_free_queue;
	spinlock_t lock;

} rtk_diseqc;

#endif
