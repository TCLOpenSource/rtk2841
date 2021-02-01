/* ------------------------------------------------------------------------- */
/* diseqc_data_buff.c  CEC Message Buffer                                             */
/* ------------------------------------------------------------------------- */
/*   Copyright (C) 2008 Kevin Wang <kevin_wang@realtek.com.tw>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
-------------------------------------------------------------------------
Update List :
-------------------------------------------------------------------------
    1.0     |   20081208    | Create Phase
-------------------------------------------------------------------------
    1.1     |   20081211    | Add Spinlock Protection
-------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
//#include "rtk_diseqc.h"
#include "rtk_diseqc_data_buff.h"



MODULE_LICENSE("GPL");

void ddb_queue_head_init(diseqc_data_buff_head *head)
{
	spin_lock_init(&head->lock);
	INIT_LIST_HEAD(&head->list);
	head->qlen = 0;
}

void ddb_queue_head(diseqc_data_buff_head *head, diseqc_data_buff *ddb)
{
	unsigned long flags;
	spin_lock_irqsave(&head->lock, flags);

	list_add(&ddb->list, &head->list);
	head->qlen++;

	spin_unlock_irqrestore(&head->lock, flags);
}

void ddb_queue_tail(diseqc_data_buff_head *head, diseqc_data_buff *ddb)
{
	unsigned long flags;
	spin_lock_irqsave(&head->lock, flags);

	list_add_tail(&ddb->list, &head->list);
	head->qlen++;

	spin_unlock_irqrestore(&head->lock, flags);
}







void ddb_dequeue_find(diseqc_data_buff_head *head, diseqc_data_buff *ddb)
{
	unsigned long flags;
	diseqc_data_buff *ddb_temp = NULL;

	spin_lock_irqsave(&head->lock, flags);

	ddb_temp = list_entry(head->list.next, diseqc_data_buff, list);

	while (ddb_temp->list.next != &head->list)
	{
		if(ddb == ddb_temp)
		{
			list_del_init(&ddb->list);
			head->qlen--;
			break;
		}
		ddb_temp = list_entry(ddb_temp->list.next, diseqc_data_buff, list);
	}

	spin_unlock_irqrestore(&head->lock, flags);

}


diseqc_data_buff *ddb_dequeue(diseqc_data_buff_head *head)
{
	diseqc_data_buff *ddb = NULL;
	unsigned long flags;
	spin_lock_irqsave(&head->lock, flags);

	if (!list_empty(&head->list)) {
		ddb = list_entry(head->list.next, diseqc_data_buff, list);
		list_del_init(&ddb->list);
		head->qlen--;
	}

	spin_unlock_irqrestore(&head->lock, flags);

	return ddb;
}



diseqc_data_buff *ddb_dequeue_tail(diseqc_data_buff_head *head)
{
	diseqc_data_buff *ddb = NULL;
	unsigned long flags;
	spin_lock_irqsave(&head->lock, flags);

	if (!list_empty(&head->list)) {
		ddb = list_entry(head->list.prev, diseqc_data_buff, list);
		list_del_init(&ddb->list);
		head->qlen--;
	}

	spin_unlock_irqrestore(&head->lock, flags);

	return ddb;
}


unsigned int ddb_queue_len(const diseqc_data_buff_head *head)
{
	return head->qlen;
}



void ddb_queue_purge(diseqc_data_buff_head *head)
{
	diseqc_data_buff *ddb;
	unsigned long flags;
	spin_lock_irqsave(&head->lock, flags);

	while ((ddb = ddb_dequeue(head)) != NULL)
		kfree_ddb(ddb);

	spin_unlock_irqrestore(&head->lock, flags);
}


diseqc_data_buff *alloc_ddb(size_t size)
{
	diseqc_data_buff *ddb = (diseqc_data_buff *) kmalloc(sizeof(diseqc_data_buff) + size, GFP_KERNEL);

	if (ddb) {
		INIT_LIST_HEAD(&ddb->list);
		init_waitqueue_head(&ddb->wq);
		ddb->status = 0;
		ddb->flags = 0;
		ddb->head = ((unsigned char *)ddb) + sizeof(diseqc_data_buff);
		ddb->data = ddb->head;
		ddb->tail = ddb->head;
		ddb->end = ddb->head + size;
		ddb->len = 0;
	}

	return ddb;
}



void kfree_ddb(diseqc_data_buff *ddb)
{
	if (ddb)
		kfree(ddb);
}

#define CHECK_BOUNDRARY(ddb)	\
	do {\
		if (ddb->tail > ddb->end)\
			diseqc_warn( "ddb over panic:  ddb=%p ddb->tail (%p) > ddb->end (%p)\n", ddb, ddb->tail, ddb->end);\
		if (ddb->data < ddb->head)\
			diseqc_warn( "ddb under panic: ddb=%p ddb->data (%p) < ddb->head (%p)\n", ddb, ddb->data, ddb->head);\
	} while (0)

int ddb_tailroom(const diseqc_data_buff *ddb)
{
	return ddb->end - ddb->tail;
}


/*add data from tail of buffer*/
void ddb_reserve(diseqc_data_buff *ddb, unsigned int len)
{
	ddb->data += len;
	ddb->tail += len;
	CHECK_BOUNDRARY(ddb);
}

/*add data from tail of buffer*/
unsigned char *ddb_put(diseqc_data_buff *ddb, unsigned int len)
{
	unsigned char *ptr = ddb->tail;
	ddb->tail += len;
	ddb->len += len;
	CHECK_BOUNDRARY(ddb);
	return ptr;
}

/*add data from start of buffer*/
unsigned char *ddb_push(diseqc_data_buff *ddb, unsigned int len)
{
	ddb->data -= len;
	ddb->len += len;
	CHECK_BOUNDRARY(ddb);
	return ddb->data;
}


/*remove data from start of buffer*/
unsigned char *ddb_pull(diseqc_data_buff *ddb, unsigned int len)
{
	if (len <= ddb->len) {
		ddb->data += len;
		ddb->len -= len;
		return ddb->data;
	}
	return NULL;
}


void ddb_purge(diseqc_data_buff *ddb)
{
	ddb->data = ddb->head;
	ddb->tail = ddb->head;
	ddb->len = 0;
}

EXPORT_SYMBOL(ddb_queue_head_init);
EXPORT_SYMBOL(ddb_queue_head);
EXPORT_SYMBOL(ddb_queue_tail);
EXPORT_SYMBOL(ddb_dequeue_find);
EXPORT_SYMBOL(ddb_dequeue);
EXPORT_SYMBOL(ddb_dequeue_tail);
EXPORT_SYMBOL(ddb_queue_len);
EXPORT_SYMBOL(ddb_queue_purge);
EXPORT_SYMBOL(alloc_ddb);
EXPORT_SYMBOL(kfree_ddb);
EXPORT_SYMBOL(ddb_tailroom);
EXPORT_SYMBOL(ddb_reserve);
EXPORT_SYMBOL(ddb_put);
EXPORT_SYMBOL(ddb_push);
EXPORT_SYMBOL(ddb_pull);
EXPORT_SYMBOL(ddb_purge);








