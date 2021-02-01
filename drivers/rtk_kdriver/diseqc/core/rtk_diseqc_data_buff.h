/*Copyright (C) 2007-2013 Realtek Semiconductor Corporation.*/
#ifndef __RTK_DISEQC_MSG_H__
#define __RTK_DISEQC_MSG_H__

#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/completion.h>
#include <linux/wait.h>

#include "rtk_diseqc_debug.h"

#define RX_BUFFER_SIZE      64

typedef struct {
	struct list_head list;
	unsigned char status;

#define WAIT_XMIT       0xff
#define XMIT_OK         0x00
#define XMIT_FAIL       0x01
#define XMIT_TIMEOUT    0x02
#define XMIT_ABORT      0x03

	unsigned char flags;
#define NONBLOCK        0x80
	wait_queue_head_t wq;
	unsigned char *head;
	unsigned char *data;
	unsigned char *tail;
	unsigned char *end;
	unsigned char len;

} diseqc_data_buff;

typedef struct {
	spinlock_t lock;
	struct list_head list;
	unsigned int qlen;
} diseqc_data_buff_head;

// ddb = diseqc data buffer
void ddb_queue_head_init (diseqc_data_buff_head *head);
void ddb_queue_head      (diseqc_data_buff_head *head, diseqc_data_buff *ddb);
void ddb_queue_tail      (diseqc_data_buff_head *head, diseqc_data_buff *ddb);
void ddb_dequeue_find    (diseqc_data_buff_head *head, diseqc_data_buff *ddb);

diseqc_data_buff *ddb_dequeue      (diseqc_data_buff_head *head);
diseqc_data_buff *ddb_dequeue_tail (diseqc_data_buff_head *head);

void ddb_queue_purge             (diseqc_data_buff_head *head);
unsigned int ddb_queue_len (const diseqc_data_buff_head *head);

diseqc_data_buff *alloc_ddb(size_t size);

void kfree_ddb(diseqc_data_buff *ddb);

void ddb_reserve(diseqc_data_buff *ddb, unsigned int len);

unsigned char *ddb_put (diseqc_data_buff *ddb, unsigned int len);
unsigned char *ddb_push(diseqc_data_buff *ddb, unsigned int len);
unsigned char *ddb_pull(diseqc_data_buff *ddb, unsigned int len);

void ddb_purge        (diseqc_data_buff *ddb);
int ddb_tailroom(const diseqc_data_buff *ddb);

#endif
