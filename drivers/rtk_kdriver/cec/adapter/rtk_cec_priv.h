/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_CEC_PRIV_H__
#define __RTK_CEC_PRIV_H__

#include <linux/wait.h>
#include <linux/timer.h>
#include <linux/completion.h>
#include "../core/rtk_cec.h"
#include "../core/rtk_cm_buff.h"

#define ID_RTD299X_CEC_CONTROLLER     0x1778

#define RX_RING_LENGTH  	16
#define TX_RING_LENGTH  	16

#define PATCH_RX_DATA_PERIOD 78
#define PATCH_RX_DROP_SAME_LA_DATA 1


typedef struct {
	unsigned char enable:1;
	unsigned char state:7;
	cm_buff *cmb;
	unsigned long timeout;
	struct delayed_work work;
} rtk_cec_xmit;

typedef struct {
	unsigned char enable:1;
	unsigned char state:7;
	cm_buff *cmb;
	wait_queue_head_t wq;
	struct delayed_work work;
} rtk_cec_rcv;

enum {
	IDEL,
	XMIT,
	RCV
};

enum {
	RCV_OK,
	RCV_FAIL,
};

#define CEC_MODE_OFF        0
#define CEC_MODE_ON         1
#define CEC_MODE_STANDBY    2

typedef struct {
	struct {
		unsigned char init:1;
		unsigned char enable:1;
		unsigned char standby_mode:1;
		unsigned char state_before_suspend:1;        
	} status;

	rtk_cec_xmit xmit;
	rtk_cec_rcv rcv;
	cm_buff_head tx_queue;
	cm_buff_head rx_queue;
	cm_buff_head rx_free_queue;
	spinlock_t lock;

} rtk_cec;

#endif /*__RTK_CEC_H__*/
