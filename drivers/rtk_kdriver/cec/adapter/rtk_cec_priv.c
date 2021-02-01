/* -------------------------------------------------------------------------
   cec_rtd299x.c  cec driver for Realtek rtd299x
   -------------------------------------------------------------------------
    Copyright (C) 2012 Kevin Wang <kevin_wang@realtek.com.tw>
----------------------------------------------------------------------------
Update List :
----------------------------------------------------------------------------
    1.0     |   20120608    |   Kevin Wang  | 1) create phase
----------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/interrupt.h>
#include <linux/workqueue.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/io.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rbus/pll_reg_reg.h>
#include "rtk_cec_priv.h"
#include "rtk_cec_reg.h"
#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		(hwirq)
#endif
static rtk_cec m_cec;

#define TX_TIMEOUT      (HZ<<2)
#define SA_INTERRUPT    0
#define SA_SHIRQ        IRQF_SHARED

/*#define CONFIG_CEC_DBG*/
/*#define CEC_TX_DBG*/
/*#define CEC_RX_DBG*/

/*//////////////////////////////////////////////////////////////////////
// CEC Wakeup Function
//////////////////////////////////////////////////////////////////////*/
#define CEC_OPCODE_COMPARE_ENABLE
#ifdef CEC_OPCODE_COMPARE_ENABLE
#define IS_OPCODE_COMP_EN()	(read_reg32(GDI_CEC_OPCODE_ENABLE)&0xf)
#define PWR_STS_COMP_EN() 	(read_reg32(GDI_CEC_OPCODE_ENABLE)&0x00000001)
#define PHY_ADDR_COMP_EN() 	(read_reg32(GDI_CEC_OPCODE_ENABLE)&0x00000002)
#define CEC_VER_COMP_EN() 	(read_reg32(GDI_CEC_OPCODE_ENABLE)&0x00000004)
#define VEND_ID_COMP_EN() 	(read_reg32(GDI_CEC_OPCODE_ENABLE)&0x00000008)
#endif

/*static unsigned long  __sleepdata rtd299x_cec_standby_config          = 0;*/
/*static unsigned char  __sleepdata rtd299x_cec_standby_logical_addr  = 0xF;*/
/*static unsigned short __sleepdata rtd299x_cec_standby_physical_addr   = 0xFFFF;*/
/*static unsigned char  __sleepdata rtd299x_cec_standby_cec_version     = CEC_VERSION_1_4;*/
/*static unsigned long  __sleepdata rtd299x_cec_standby_vendor_id       = 0x000000;*/

static unsigned long rtk_cec_standby_config = 0x0;
static unsigned char rtk_cec_standby_logical_addr = 0xF;
static unsigned short rtk_cec_standby_physical_addr = 0xFFFF;
static unsigned char rtk_cec_standby_cec_version = CEC_VERSION_1_4;
static unsigned long rtk_cec_standby_vendor_id = 0x000000;
static unsigned long rtk_cec_retry_num = 5;



/*------------------------------------------------------------------
 * Func : _get_pre_div
 *
 * Desc : _get_pre_div setting
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
unsigned int _get_pre_div(void)
{
	unsigned int freq, tmp , value_f, value_n;
	unsigned int unRet;

	// get BUS PLL FN value
	tmp = read_reg32(PLL_REG_SYS_PLL_BUS2_reg);

	value_f = PLL_REG_SYS_PLL_BUS2_get_pllbus_fcode(tmp);
	value_n = PLL_REG_SYS_PLL_BUS2_get_pllbus_ncode(tmp);
	freq = 27 * (value_n + 3) + ((27 * value_f) >> 11);
	freq /= 2;

	if(freq >= 0x100)
		unRet = 0xff;
	else
		unRet = freq;

	return unRet;

}


static unsigned char rx_fifo_ofst = 0;
#define _reset_rx_fifo_ofst()       do { rx_fifo_ofst = 0; }while(0)

/*------------------------------------------------------------------
 * Func : _read_rx_fifo
 *
 * Desc : read rx fifo
 *
 * Param: rx_buff : buffer address
 *        rx_buff_size : size of rx buffer
 *
 * Retn : >=0 : number of bytes read
 *        <0 : failed
 *------------------------------------------------------------------*/
static int _read_rx_fifo(char* rx_buff, int rx_buff_size, int eom)
{
	unsigned long rx_fifo_data[4];
	unsigned long data_len = rtd_inl(CEC_RXCR0) & 0x1F;
	int rx_entry_cnt = 0;
	int i;

	cec_rx_dbg("rx_fifo_count = %d, RXCR0=%x, eom=%d\n",
		data_len, rtd_inl(CEC_RXCR0), eom);

	if (data_len==0)
		return 0;

	if (data_len > rx_buff_size)
		data_len = rx_buff_size;

	if (data_len > 16)
		data_len = 16;

	if (!eom)   // not EOM, read data should be 4 byte alignment
		data_len &= ~0x3;

	rx_entry_cnt = (data_len + 3) >>2;

	for (i = 0; i < rx_entry_cnt; i++)
	{
		rx_fifo_data[i] = __cpu_to_be32(rtd_inl(CEC_RXDR1 + (rx_fifo_ofst<<2)));
		cec_rx_dbg("rx_fifo_data[%d] = %x\n", i, rx_fifo_data[i]);
		rx_fifo_ofst++;
		rx_fifo_ofst&=0x3;
	}

	memcpy(rx_buff, (unsigned char*) rx_fifo_data, data_len);

	rtd_outl(CEC_TXDR0, RX_SUB_CNT|FIFO_CNT(data_len)); /* rx fifo count -= rx_count */

	return data_len;
}


static unsigned char tx_fifo_ofst = 0;
#define _reset_tx_fifo_ofst()   do { tx_fifo_ofst = 0; }while(0)

/*------------------------------------------------------------------
 * Func : _write_tx_fifo
 *
 * Desc : write data to tx fifo
 *
 * Param: tx_buff : buffer address
 *        tx_buff_len : size of tx buffer
 *
 * Retn : >=0 : number of bytes write
 *        <0 : failed
 *------------------------------------------------------------------*/
static int _write_tx_fifo(char* tx_buff,int tx_buff_len)
{
	unsigned long tx_fifo_data[4];
	unsigned long tx_len = tx_buff_len;
	unsigned long tx_entry;
	int i;

	if (tx_len > 16)
		tx_len = 16;

	memcpy(tx_fifo_data, tx_buff, tx_len);

	tx_entry = (tx_len+3)>>2;      // number of TX fifo entry

	for (i=0; i<tx_entry; i++)
	{
		tx_fifo_ofst &= 0x3;        // start address of tx fifo
		cec_tx_dbg("txdr1[%d] =0x%x \n", tx_fifo_ofst, __cpu_to_be32(tx_fifo_data[i]));
		rtd_outl(CEC_TXDR1 + (tx_fifo_ofst<<2), __cpu_to_be32(tx_fifo_data[i]));
		tx_fifo_ofst++;
	}

	rtd_outl(CEC_TXDR0, TX_ADD_CNT | FIFO_CNT(tx_len)); /* add data to fifo */

	return tx_len;
}

/*------------------------------------------------------------------
 * Func : _cmb_tx_complete
 *
 * Desc : complete a tx cmb
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void _cmb_tx_complete(cm_buff *cmb)
{
	if (cmb->flags & NONBLOCK) {
		kfree_cmb(cmb);
	} else {
		if (cmb->status == WAIT_XMIT)
			cmb->status = XMIT_ABORT;

		wake_up(&cmb->wq);
	}
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_rx_reset
 *
 * Desc : reset rx
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void rtd299x_cec_rx_reset(rtk_cec *p_this)
{
	write_reg32(CEC_RXCR0, RX_RST);
	wmb();
	write_reg32(CEC_RXCR0, 0);
	wmb();
	p_this->rcv.state = IDEL;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_tx_work
 *
 * Desc : rtd299x cec tx function
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void rtd299x_cec_tx_work(struct work_struct *work)
{
	rtk_cec *p_this =
	    (rtk_cec *) container_of(work, rtk_cec, xmit.work.work);
	rtk_cec_xmit *p_xmit = &p_this->xmit;
	unsigned char dest;
	unsigned long flags;
	int ret;

	spin_lock_irqsave(&p_this->lock, flags);

	if (p_xmit->state == XMIT) {
		if (read_reg32(CEC_TXCR0) & TX_EN) {
			/* xmitting */
			if (read_reg32(CEC_TXCR0) & TX_INT) {
				if (p_xmit->cmb->len) {
					ret = _write_tx_fifo(p_xmit->cmb->data, (p_xmit->cmb->len >8) ? 8 : p_xmit->cmb->len);
					cmb_pull(p_xmit->cmb, ret);

					if (p_xmit->cmb->len == 0)
						write_reg32(CEC_TXCR0, read_reg32(CEC_TXCR0) & ~TX_CONTINUOUS);	/* clear continue bits.... */
				}

				write_reg32(CEC_TXCR0, read_reg32(CEC_TXCR0));	/* clear interrupt */
			}

			if (time_after(jiffies, p_xmit->timeout)) {
				write_reg32(CEC_TXCR0, TX_INT);

				p_xmit->cmb->status = XMIT_TIMEOUT;
				_cmb_tx_complete(p_xmit->cmb);

				p_xmit->cmb = NULL;
				p_xmit->state = IDEL;

				cec_warn("cec tx timeout\n");

				cancel_delayed_work(&p_xmit->work);
			}
		} else {
			cancel_delayed_work(&p_xmit->work);

			if ((read_reg32(CEC_TXCR0) & TX_EOM) == 0) {
				p_xmit->cmb->status = XMIT_FAIL;
				cec_tx_dbg("cec tx failed\n");
			} else {
				p_xmit->cmb->status = XMIT_OK;
				cec_tx_dbg("cec tx completed\n");
			}

			write_reg32(CEC_TXCR0, TX_INT);
			_cmb_tx_complete(p_xmit->cmb);
			p_xmit->cmb = NULL;
			p_xmit->state = IDEL;
		}
	}

	if (p_xmit->state == IDEL) {
		if (p_xmit->enable) {
			p_xmit->cmb = cmb_dequeue(&p_this->tx_queue);

			if (p_xmit->cmb) {
				cec_tx_dbg("cec tx : cmb = %p, len=%d\n",
					   p_xmit->cmb, p_xmit->cmb->len);
				dest = (p_xmit->cmb->data[0] & 0xf);
				cmb_pull(p_xmit->cmb, 1);
				p_xmit->timeout = jiffies + TX_TIMEOUT;

				/* reset tx fifo */
				write_reg32(CEC_TXCR0, TX_RST);
				wmb();
				write_reg32(CEC_TXCR0, 0);
				wmb();

				_reset_tx_fifo_ofst();
				ret = _write_tx_fifo(p_xmit->cmb->data, (p_xmit->cmb->len>16) ? 16 : p_xmit->cmb->len);
				cmb_pull(p_xmit->cmb, ret);


				if (p_xmit->cmb->len == 0)
					write_reg32(CEC_TXCR0, DEST_ADDR(dest) | TX_EN | TX_INT_EN);
				else
					write_reg32(CEC_TXCR0, DEST_ADDR(dest) | TX_EN | TX_INT_EN | TX_CONTINUOUS);

				p_xmit->state = XMIT;

				cec_tx_dbg("cec tx start\n");

				/* queue delayed work for timeout detection */
				schedule_delayed_work(&p_xmit->work, TX_TIMEOUT + 1);
			}
		}
	}

	spin_unlock_irqrestore(&p_this->lock, flags);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_tx_start
 *
 * Desc : start rx
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void rtd299x_cec_tx_start(rtk_cec *p_this)
{
	unsigned long flags;
	spin_lock_irqsave(&p_this->lock, flags);

	write_reg32(CEC_RXCR0, (read_reg32(CEC_RXCR0) | RX_INT_EN) |
		RX_EN | RX_CONTINUOUS); /* enable RX */
	if (!p_this->xmit.enable) {
		cec_info("cec tx start\n");
		p_this->xmit.enable = 1;
		p_this->xmit.state = IDEL;
		p_this->xmit.cmb = NULL;

		INIT_DELAYED_WORK(&p_this->xmit.work, rtd299x_cec_tx_work);
	}

	spin_unlock_irqrestore(&p_this->lock, flags);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_tx_stop
 *
 * Desc : stop tx
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void rtd299x_cec_tx_stop(rtk_cec *p_this)
{
	cm_buff *cmb;
	unsigned long flags;
	spin_lock_irqsave(&p_this->lock, flags);

	if (p_this->xmit.enable) {
		cec_info("cec tx stop\n");

		rtd299x_cec_rx_reset(p_this);
		cancel_delayed_work(&p_this->xmit.work);
		/* reset tx fifo */
		write_reg32(CEC_TXCR0, TX_RST);
		wmb();
		write_reg32(CEC_TXCR0, 0);
		wmb();

		if (p_this->xmit.cmb)
			_cmb_tx_complete(p_this->xmit.cmb);

		while ((cmb = cmb_dequeue(&p_this->tx_queue)))
			_cmb_tx_complete(cmb);

		p_this->xmit.enable = 0;
		p_this->xmit.state = IDEL;
		p_this->xmit.cmb = NULL;
	}
	write_reg32(CEC_RXCR0, RX_EN | RX_CONTINUOUS);	/* enable RX */
	spin_unlock_irqrestore(&p_this->lock, flags);
}

extern int rtd299x_cec_xmit_message(rtk_cec *p_this, cm_buff *cmb,
				    unsigned long flags);

/*------------------------------------------------------------------
 * Func : rtd299x_cec_standby_message_handler
 *
 * Desc : rtd299x cec message handler when cec works under standby mode
 *
 * Parm : p_this : handle of rtd299x cec
 *        init   : message initator
 *        dest   : message destination
 *        opcode : opcode of message
 *        param  : param of messsage
 *        len    : length of message parameter
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void rtd299x_cec_standby_message_handler(rtk_cec *p_this,
					 unsigned char init,
					 unsigned char dest,
					 unsigned char opcode,
					 unsigned char *param,
					 unsigned char len)
{
	cm_buff *cmb = NULL;

	unsigned char dev_type_map[15] = {
		CEC_DEVICE_TV,
		CEC_DEVICE_RECORDING_DEVICE,
		CEC_DEVICE_RECORDING_DEVICE,
		CEC_DEVICE_TUNER,
		CEC_DEVICE_PLAYBACK_DEVICE,
		CEC_DEVICE_AUDIO_SYSTEM,
		CEC_DEVICE_TUNER,
		CEC_DEVICE_TUNER,
		CEC_DEVICE_PLAYBACK_DEVICE,
		CEC_DEVICE_RECORDING_DEVICE,
		CEC_DEVICE_TUNER,
		CEC_DEVICE_PLAYBACK_DEVICE,
		CEC_DEVICE_RESERVED,
		CEC_DEVICE_RESERVED,
		CEC_DEVICE_TV
	};

	/*cec_info("rtd299x_cec_standby_message_handler : init = %x, dest=%x, opcode=%x, len=%d\n", init, dest, opcode, len); */

	switch (opcode) {
	case CEC_MSG_GIVE_DEVICE_POWER_STATUS:

		if (rtk_cec_standby_config &
		    STANBY_RESPONSE_GIVE_POWER_STATUS && len == 0
		    && init != 0xF) {

#ifdef CEC_OPCODE_COMPARE_ENABLE
			if (PWR_STS_COMP_EN())
				break;
#endif
			cmb = alloc_cmb(3);
			if (cmb) {
				cmb->data[0] = (dest << 4) | init;
				cmb->data[1] = CEC_MSG_REPORT_POWER_STATUS;
				cmb->data[2] = CEC_POWER_STATUS_STANDBY;
				cmb_put(cmb, 3);
			}
		}
		break;

	case CEC_MSG_GIVE_PHYSICAL_ADDRESS:

		if (rtk_cec_standby_config &
		    STANBY_WAKEUP_BY_SET_STREAM_PATH && len == 0
		    && dest != 0xF) {

#ifdef CEC_OPCODE_COMPARE_ENABLE
			if (PHY_ADDR_COMP_EN())
				break;
#endif
			cmb = alloc_cmb(5);
			if (cmb) {
				cmb->data[0] = (dest << 4) | 0xF;
				cmb->data[1] = CEC_MSG_REPORT_PHYSICAL_ADDRESS;
				cmb->data[2] =
				    (rtk_cec_standby_physical_addr >> 8) & 0xFF;
				cmb->data[3] =
				    (rtk_cec_standby_physical_addr) & 0xFF;
				cmb->data[4] = dev_type_map[dest];
				cmb_put(cmb, 5);
			}
		}
		break;

	case CEC_MSG_STANDBY:
		break;

	default:
		/* send feature abort */
		if (init != 0xF && dest != 0xF) {
		    cmb = alloc_cmb(4);
			if (cmb) {
				cmb->data[0] = (dest << 4) | init;
				cmb->data[1] = CEC_MSG_FEATURE_ABORT;
				cmb->data[2] = opcode;	/* FEATURE ABORT */
				cmb->data[3] = CEC_ABORT_NOT_IN_CORECT_MODE;
				cmb_put(cmb, 4);
			}
		}
	}

	if (cmb)
		rtd299x_cec_xmit_message(p_this, cmb, NONBLOCK);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_rx
 *
 * Desc : rtd299x cec rx function
 *
 * Parm : work_struct : handle of work structure
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void rtd299x_cec_rx_work(struct work_struct *work)
{
	rtk_cec *p_this =
	    (rtk_cec *) container_of(work, rtk_cec, rcv.work.work);
	rtk_cec_rcv *p_rcv = &p_this->rcv;
	unsigned long flags;
	unsigned long rx_event = read_reg32(CEC_RXCR0);
	int delayed_rx_en = 0;
	bool bDrop_Data = false;
	int ret;

	spin_lock_irqsave(&p_this->lock, flags);

	if (!p_rcv->enable) {
		if (p_rcv->state == RCV) {
			cec_rx_dbg("force stop\n");
			write_reg32(CEC_RXCR0, 0);
			kfree_cmb(p_rcv->cmb);
			p_rcv->cmb = NULL;
			p_rcv->state = IDEL;
		}
		goto end_proc;
	}

	if (p_rcv->state == RCV) {
#ifdef CEC_OPCODE_COMPARE_ENABLE
		if ((rx_event & RX_EN) && (!IS_OPCODE_COMP_EN()))
#else
		if (rx_event & RX_EN)
#endif
		{
			if (rx_event & RX_INT) {
				if ((rx_event & RX_EOM))
					ret = _read_rx_fifo(p_rcv->cmb->tail, cmb_tailroom(p_rcv->cmb), 1);
				else
					ret = _read_rx_fifo(p_rcv->cmb->tail, cmb_tailroom(p_rcv->cmb), 0);

				cmb_put(p_rcv->cmb, ret);

				if (ret <0)
				{
					cec_warn
					    ("read rx fifo failed, return to rx\n");
					write_reg32(CEC_RXCR0, 0);
					_reset_rx_fifo_ofst();
					p_rcv->state = IDEL;
				}

				write_reg32(CEC_RXCR0, read_reg32(CEC_RXCR0)); // clear RX_INT
			}
		}
		else
		{
			cec_rx_dbg("rx_stop (0x%08x)\n", read_reg32(CEC_RXCR0));

			ret = _read_rx_fifo(p_rcv->cmb->tail, cmb_tailroom(p_rcv->cmb), 1);
			cmb_put(p_rcv->cmb, ret);

			if ((rx_event & RX_EOM) && p_rcv->cmb->len)
			{

				if (rx_event & BROADCAST_ADDR)
				{
#if PATCH_RX_DROP_SAME_LA_DATA
					if(((rx_event & INIT_ADDR_MASK) >>INIT_ADDR_SHIFT)==
						((read_reg32(CEC_CR0) & LOGICAL_ADDR_MASK) >> LOGICAL_ADDR_SHIFT))
					{
						cec_rx_dbg("same LA, drop it\n");
						bDrop_Data = true;
					}
#endif

					if(bDrop_Data == false)
					{
						*cmb_push(p_rcv->cmb, 1) =(
							((rx_event & INIT_ADDR_MASK) >>INIT_ADDR_SHIFT)
							<< 4) | 0xF;
					}
				}
				else
				{
					*cmb_push(p_rcv->cmb, 1) =
					    (((rx_event & INIT_ADDR_MASK) >>INIT_ADDR_SHIFT) << 4) |
					    ((read_reg32(CEC_CR0) &LOGICAL_ADDR_MASK) >>LOGICAL_ADDR_SHIFT);
				}

				if (p_this->status.standby_mode)
				{
					/* process messag */
					rtd299x_cec_standby_message_handler (
						p_this,
						p_rcv->cmb->data[0]>>4,
						p_rcv->cmb->data[0]&0xF,
						p_rcv->cmb->data[1],
						&p_rcv->cmb->data[2],
						p_rcv->cmb->len-2);
				}
				else if(bDrop_Data == false)
				{
					cmb_queue_tail(&p_this->rx_queue,
						       p_rcv->cmb);
					p_rcv->cmb = NULL;

					wake_up_interruptible(&p_this->rcv.wq);
				}

			}
			else
			{
				if ((rx_event & RX_EOM) == 0)
					delayed_rx_en = 1;
			}

			p_rcv->state = IDEL;
		}
	}

	if (p_rcv->state == IDEL) {
		if (!p_rcv->enable)
			goto end_proc;

		if (!p_rcv->cmb) {
			if (cmb_queue_len(&p_this->rx_free_queue))
				p_rcv->cmb =
				    cmb_dequeue(&p_this->rx_free_queue);
			else {
				cec_warn("[CEC] WARNING, rx over run\n");
				p_rcv->cmb = cmb_dequeue(&p_this->rx_queue);	/* reclaim form rx fifo */
			}

			if (p_rcv->cmb == NULL) {
				cec_warn("[CEC] FATAL, something wrong, no rx buffer left\n");
				goto end_proc;
			}
		}

		cmb_purge(p_rcv->cmb);
		cmb_reserve(p_rcv->cmb, 1);

		write_reg32(CEC_RXCR0, RX_RST);
		wmb();
		write_reg32(CEC_RXCR0,  RX_CONTINUOUS);
		wmb();

		_reset_rx_fifo_ofst();
		if (delayed_rx_en == 0) {
			write_reg32(CEC_RXCR0, RX_EN | RX_INT_EN );
			cec_rx_dbg("rx_restart (0x%08x)\n",read_reg32(CEC_RXCR0));
			p_rcv->state = RCV;
		}
	}

end_proc:

	spin_unlock_irqrestore(&p_this->lock, flags);
}


/*------------------------------------------------------------------
 * Func : rtd299x_cec_rx_start
 *
 * Desc : start rx
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void rtd299x_cec_rx_start(rtk_cec *p_this)
{
	unsigned long flags;
	spin_lock_irqsave(&p_this->lock, flags);

	if (!p_this->rcv.enable) {
		cec_info("rx start\n");

		p_this->rcv.enable = 1;
		p_this->rcv.state = IDEL;
		p_this->rcv.cmb = NULL;
		_reset_rx_fifo_ofst();

		INIT_DELAYED_WORK(&p_this->rcv.work, rtd299x_cec_rx_work);

		schedule_delayed_work(&p_this->rcv.work, 0);
	}

	spin_unlock_irqrestore(&p_this->lock, flags);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_rx_stop
 *
 * Desc : stop rx
 *
 * Parm : p_this : handle of rtd299x cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static
void rtd299x_cec_rx_stop(rtk_cec *p_this)
{
	cm_buff *cmb;
	unsigned long flags;

	spin_lock_irqsave(&p_this->lock, flags);

	if (p_this->rcv.enable) {
		cec_info("rx stop\n");

		write_reg32(CEC_RXCR0, RX_RST);
		wmb();
		write_reg32(CEC_RXCR0, 0);
		wmb();

		if (p_this->rcv.cmb) {
			cmb_purge(p_this->rcv.cmb);
			cmb_reserve(p_this->rcv.cmb, 1);
			cmb_queue_tail(&p_this->rx_free_queue, p_this->rcv.cmb);
		}

		while ((cmb = cmb_dequeue(&p_this->rx_queue))) {
			cmb_purge(cmb);
			cmb_reserve(cmb, 1);
			cmb_queue_tail(&p_this->rx_free_queue, cmb);
		}

		p_this->rcv.enable = 0;
		p_this->rcv.state = IDEL;
		p_this->rcv.cmb = NULL;

		wake_up_interruptible(&p_this->rcv.wq);
	}
	spin_unlock_irqrestore(&p_this->lock, flags);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_isr
 *
 * Desc : isr of rtd299x cec
 *
 * Parm : p_this : handle of rtd299x cec
 *        dev_id : handle of the rtd299x_cec
 *
 * Retn : IRQ_NONE, IRQ_HANDLED
 *------------------------------------------------------------------*/
static
irqreturn_t rtd299x_cec_isr(int this_irq, void *dev_id)
{
	rtk_cec *p_this = (rtk_cec *) dev_id;
	irqreturn_t ret = IRQ_NONE;

	if (read_reg32(CEC_TXCR0) & TX_INT) {
		rtd299x_cec_tx_work(&p_this->xmit.work.work);
		ret = IRQ_HANDLED;
	}

	if (read_reg32(CEC_RXCR0) & RX_INT) {
		rtd299x_cec_rx_work(&p_this->rcv.work.work);
		ret = IRQ_HANDLED;
	}

	return ret;
}

static void  rtd299x_cec_intial_hw_setting(void)
{
	CRT_CLK_OnOff(CEC, 0, NULL);        // disable clock
	CRT_CLK_OnOff(CEC, 1, NULL);        // enable clock

	write_reg32(CEC_CR0, CEC_MODE(0) | TEST_MODE_PAD_EN |
		LOGICAL_ADDR(0xF) | TIMER_DIV(25) |
		PRE_DIV(_get_pre_div()) | UNREG_ACK_EN);

	write_reg32(CEC_RTCR0,
		CEC_PAD_EN | CEC_PAD_EN_MODE | RETRY_NO(rtk_cec_retry_num));
	/* setup internal pull high register... */
	write_reg32(GDI_POWER_SAVING_MODE, 0x2d);

	write_reg32(CEC_RXCR0, RX_RST);

	write_reg32(CEC_RXCR0, 0);

	write_reg32(CEC_TXCR0, TX_RST);

	write_reg32(CEC_TXCR0, 0);

	write_reg32(CEC_RXTCR0,
		RX_START_LOW(135) | RX_START_PERIOD(188) |
		RX_DATA_SAMPLE(42) | RX_DATA_PERIOD(PATCH_RX_DATA_PERIOD));

	write_reg32(CEC_TXTCR0, TX_START_LOW(149) | TX_START_HIGH(31));

	write_reg32(CEC_TXTCR1,
		TX_DATA_LOW(25) | TX_DATA_01(36) |
		TX_DATA_HIGH(37));
	write_reg32(CEC_RxACKTCR1,
		RX_ACK_LOW_SEL | RX_ACK_LOW(20) | RX_ACK_BIT(30) |
		RX_ACK_LINE_ERR(94));

#ifdef CEC_OPCODE_COMPARE_ENABLE
	write_reg32(GDI_CEC_OPCODE_ENABLE, 0);	/* disable opcode compare function */
#endif

}


/*------------------------------------------------------------------
 * Func : rtd299x_cec_init
 *
 * Desc : init a rtd299x cec adapter
 *
 * Parm : N/A
 *
 * Retn : handle of cec module
 *------------------------------------------------------------------*/
int rtd299x_cec_init(rtk_cec *p_this)
{
	cm_buff *cmb = NULL;
	int i;

	if (!p_this->status.init) {
		cec_info("Open %s CEC\n", CEC_MODEL_NAME);

		rtd299x_cec_intial_hw_setting();

		spin_lock_init(&p_this->lock);
		p_this->xmit.state = IDEL;
		p_this->xmit.cmb = NULL;
		p_this->xmit.timeout = 0;

		p_this->rcv.state = IDEL;
		p_this->rcv.cmb = NULL;
		init_waitqueue_head(&p_this->rcv.wq);

		cmb_queue_head_init(&p_this->tx_queue);
		cmb_queue_head_init(&p_this->rx_queue);
		cmb_queue_head_init(&p_this->rx_free_queue);

		for (i = 0; i < RX_RING_LENGTH; i++) {
			cmb = alloc_cmb(RX_BUFFER_SIZE);
			if (cmb)
				cmb_queue_tail(&p_this->rx_free_queue, cmb);
		}

		if ( request_irq (IRQ_GET_KERNEL_IRQ_NUM(ISO_IRQ), rtd299x_cec_isr, SA_INTERRUPT | SA_SHIRQ,
				"RTD293x CEC", p_this) < 0) {

			cec_warn("cec : open %s cec failed, unable to request irq#%d\n",
			     CEC_MODEL_NAME, IRQ_GET_KERNEL_IRQ_NUM(ISO_IRQ));
			return -1;
		}
		cec_info("cec : enable CEC SCPU interrupt\n");
		write_reg32(CEC_INT_EN, CEC_INT_EN_VAL | CEC_INT_EN_WRITE_DATA);
		p_this->status.init = 1;
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_mode
 *
 * Desc : enable ces module
 *
 * Parm : p_this   : handle of rtd299x cec adapter
 *        mode     : CEC_MODE_OFF : disable CEC module
 *                   CEC_MODE_ON : enable CEC module
 *                   CEC_MODE_OFF : put CEC module into standby mode
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int rtd299x_cec_set_mode(rtk_cec *p_this, unsigned char mode)
{
	switch (mode) {
	case CEC_MODE_OFF:	/* disable */

		cec_info("%s cec mode : OFF\n", CEC_MODEL_NAME);
		write_reg32(CEC_CR0,
			    (read_reg32(CEC_CR0) & ~CTRL_MASK1) | CEC_MODE(0) |
			    LOGICAL_ADDR(0xF));
		p_this->status.enable = 0;
		p_this->status.standby_mode = 0;
		rtd299x_cec_rx_stop(p_this);
		rtd299x_cec_tx_stop(p_this);

		break;

	case CEC_MODE_ON:

		cec_info("%s cec mode : On\n", CEC_MODEL_NAME);
		write_reg32(CEC_CR0,
			    (read_reg32(CEC_CR0) & ~CTRL_MASK1) | CEC_MODE(1));
#ifdef CEC_OPCODE_COMPARE_ENABLE
		write_reg32(GDI_CEC_OPCODE_ENABLE, 0);	/*disable opcode compare function*/
#endif
		rtd299x_cec_rx_start(p_this);
		rtd299x_cec_tx_start(p_this);
		p_this->status.enable = 1;
		p_this->status.standby_mode = 0;

		break;

	case CEC_MODE_STANDBY:

		cec_info("%s cec mode : Standby (la=%x)\n", CEC_MODEL_NAME,
			 rtk_cec_standby_logical_addr);
		write_reg32(CEC_CR0,
			    (read_reg32(CEC_CR0) & ~CTRL_MASK1) | CEC_MODE(1) |
			    LOGICAL_ADDR(rtk_cec_standby_logical_addr));
		rtd299x_cec_rx_start(p_this);
		rtd299x_cec_tx_start(p_this);
		p_this->status.enable = 1;
		p_this->status.standby_mode = 1;
		break;
	}
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_enable
 *
 * Desc : enable ces module
 *
 * Parm : p_this   : handle of rtd299x cec adapter
 *        on_off   : 0 : disable, others enable
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int rtd299x_cec_enable(rtk_cec *p_this, unsigned char on_off)
{
	if (on_off) {
		rtd299x_cec_set_mode(p_this, CEC_MODE_ON);
	} else {
		if (rtk_cec_standby_config == 0
		    || rtk_cec_standby_logical_addr >= 0xF
		    || rtk_cec_standby_physical_addr == 0xFFFF)
			rtd299x_cec_set_mode(p_this, CEC_MODE_OFF);
		else
			rtd299x_cec_set_mode(p_this, CEC_MODE_STANDBY);	/* standby mode */
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_rx_mask
 *
 * Desc : set rx mask rtd299x ces
 *
 * Parm : p_this    : handle of rtd299x cec adapter
 *        rx_mask   : rx mask
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_rx_mask(rtk_cec *p_this, unsigned short rx_mask)
{
	unsigned char log_addr = 0xf;
	int i;

	for (i = 0; i < 16; i++) {
		if (TEST_BIT(rx_mask, i)) {
			log_addr = i;
			break;
		}
	}

	if (rx_mask & ~(BIT_MASK(15) | BIT_MASK(log_addr))) {
		cec_info
		    ("cec : multiple address specified (%04x), only address %x,f are valid\n",
		     rx_mask, log_addr);
	}

	write_reg32(CEC_CR0,
		    (read_reg32(CEC_CR0) & ~LOGICAL_ADDR_MASK) |
		    LOGICAL_ADDR(log_addr));

	cec_info("cec : logical address = %02x\n", log_addr);

	if (log_addr != 0xF)
		rtk_cec_standby_logical_addr = log_addr;	/* save the latest vaild logical address */

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_physical_addr
 *
 * Desc : set physical address of rtd299x ces
 *
 * Parm : p_this    : handle of rtd299x cec adapter
 *        phy_addr  : physical address
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_physical_addr(rtk_cec *p_this, unsigned short phy_addr)
{
	cec_info("cec : physcial address = %04x\n", phy_addr);

	/* we always keep latest valid physical address during standby */
	if (phy_addr != 0xffff)
		rtk_cec_standby_physical_addr = phy_addr;


	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_cec_version
 *
 * Desc : set cec version
 *
 * Parm : p_this    : handle of rtd299x cec adapter
 *        version   : cec version number
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_cec_version(rtk_cec *p_this, unsigned char version)
{
	rtk_cec_standby_cec_version = version;
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_device_vendor_id
 *
 * Desc : set vendor id of rtd299x ces
 *
 * Parm : p_this    : handle of rtd299x cec adapter
 *        vendor_id  : device vendor id
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_device_vendor_id(rtk_cec *p_this,
				     unsigned long vendor_id)
{
	rtk_cec_standby_vendor_id = vendor_id;
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_stanby_mode
 *
 * Desc : set standy mode condition of rtd299x ces
 *
 * Parm : p_this  : handle of rtd299x cec adapter
 *        mode    : cec standby mode
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_stanby_mode(rtk_cec *p_this, unsigned long mode)
{
	rtk_cec_standby_config = mode;
	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_set_retry_num
 *
 * Desc : set retry times of rtd299x cec
 *
 * Parm : p_this  : handle of rtd299x cec adapter
 *        mun    : retry times
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int rtd299x_cec_set_retry_num(rtk_cec *p_this, unsigned long num)
{
	rtk_cec_retry_num = num;
	write_reg32(CEC_RTCR0,
		    ((read_reg32(CEC_RTCR0) & ~RETRY_NO_MASK) | RETRY_NO(rtk_cec_retry_num)));
	return 0;
}


extern bool pm_freezing;
static void rtk_cec_wait_xmit_done(cm_buff *cmb)
{
#if 0
    int wait_interval = msecs_to_jiffies(100);
    int wait_jiffies = 0;
    while(wait_jiffies < TX_TIMEOUT + 50) {
        wait_event_timeout(cmb->wq, (cmb->status != WAIT_XMIT) || (pm_freezing == true), wait_interval);
        if((cmb->status != WAIT_XMIT) || (pm_freezing == true))
            break;
        wait_jiffies += wait_interval;
    }
#else

    wait_event_timeout(cmb->wq, cmb->status != WAIT_XMIT, TX_TIMEOUT + 50);

#endif

}


/*------------------------------------------------------------------
 * Func : rtd299x_cec_xmit_msg
 *
 * Desc : xmit message
 *
 * Parm : p_this   : handle of rtd299x cec
 *        cmb      : msg to xmit
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int rtd299x_cec_xmit_message(rtk_cec *p_this, cm_buff *cmb,
			     unsigned long flags)
{
	int ret = 0;
	unsigned char status;

	if (!p_this->xmit.enable)
		return -1;

       if((cmb->len == 1) && (cmb->data[0] == 0))
            cmb->poll_self = 1;
       else
            cmb->poll_self = 0;

        if(cmb->poll_self)
            cec_info("x\n");

	cmb->flags = flags;
	cmb->status = WAIT_XMIT;

	cmb_queue_tail(&p_this->tx_queue, cmb);

	schedule_delayed_work(&p_this->xmit.work, 0);

	if ((cmb->flags & NONBLOCK) == 0) {
		rtk_cec_wait_xmit_done(cmb);
		status= cmb->status;
		switch (status) {
		case XMIT_OK:
		case XMIT_ABORT:
		case XMIT_FAIL:
			if(status == XMIT_OK) {
	               if(cmb->poll_self) {
	                    cec_info("o\n");
	                    status = XMIT_FAIL;
	                }
				cec_tx_dbg("cec : xmit message success\n");
			} else if(status == XMIT_ABORT) {
                   if(cmb->poll_self){
                        cec_info("a\n");
					}
				cec_warn("cec : xmit message abort\n");
			} else{
			       if(cmb->poll_self){
                        cec_info("f\n");
			       	}
				cec_warn("cec : xmit message failed\n");
			}
            
		spin_lock_irqsave(&p_this->lock, flags);  
		kfree_cmb(cmb);
		spin_unlock_irqrestore(&p_this->lock, flags);
		break;

		case XMIT_TIMEOUT:
		case WAIT_XMIT:
		default:
                    if(cmb->poll_self)
                                cec_info("t\n");
			cec_warn("cec : xmit message timeout\n");
			spin_lock_irqsave(&p_this->lock, flags);
			if(p_this->xmit.cmb == cmb)
			{
				p_this->xmit.state = IDEL;
				p_this->xmit.cmb = NULL;
			}
			else
			{
				cmb_dequeue_find(&p_this->tx_queue,cmb);
			}

			kfree_cmb(cmb);
			spin_unlock_irqrestore(&p_this->lock, flags);
			break;
		}

		ret = (status == XMIT_OK) ? 0 : -1;

	}

	return ret;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_read_message
 *
 * Desc : read message
 *
 * Parm : p_this : handle of cec device
 *        flags  : flag of current read operation
 *
 * Retn : cec message
 *------------------------------------------------------------------*/
static cm_buff *rtd299x_cec_read_message(rtk_cec *p_this,
					 unsigned char flags)
{
	while (!(flags & NONBLOCK) && p_this->status.enable
	       && !cmb_queue_len(&p_this->rx_queue))
		wait_event_interruptible(p_this->rcv.wq, !p_this->status.enable
					 || cmb_queue_len(&p_this->rx_queue));

	if (p_this->status.enable) {
		cm_buff *cmb = cmb_dequeue(&p_this->rx_queue);

		if (cmb) {
			cec_rx_dbg("got msg %p\n", cmb);
			cmb_queue_tail(&p_this->rx_free_queue,
				       alloc_cmb(RX_BUFFER_SIZE));
			return cmb;
		}
	}

	return NULL;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_uninit
 *
 * Desc : uninit a rtd299x cec adapter
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void rtd299x_cec_uninit(rtk_cec *p_this)
{
	cec_info("%s cec closed\n", CEC_MODEL_NAME);
	write_reg32(CEC_INT_EN, CEC_INT_EN_VAL);
	free_irq(IRQ_GET_KERNEL_IRQ_NUM(ISO_IRQ), p_this);
	write_reg32(CEC_CR0, read_reg32(CEC_CR0) & ~CEC_MODE_MASK);
	write_reg32(CEC_RXCR0, 0);
	write_reg32(CEC_TXCR0, 0);
	rtd299x_cec_enable(p_this, 0);
	p_this->status.init = 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_suspend
 *
 * Desc : suspend a rtd299x cec adapter
 *
 * Parm : p_this : handle of rtd299x cec adapter
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int rtd299x_cec_suspend(rtk_cec *p_this)
{
	p_this->status.state_before_suspend = p_this->status.enable;
	write_reg32(CEC_INT_EN, CEC_INT_EN_VAL); // disable CEC interrupt
	if (!p_this->status.enable) { /*CEC is off*/
		cec_warn("[CEC]function is off when power on, doesn't enable!!\n");
		return 0;
	}

	cec_info("%s cec suspended (la=%x, pa=%04x, standby_mode=%ld)\n",
		 CEC_MODEL_NAME, rtk_cec_standby_logical_addr,
		 rtk_cec_standby_physical_addr, rtk_cec_standby_config);

	rtd299x_cec_set_mode(p_this, CEC_MODE_OFF);

	if (rtk_cec_standby_config && rtk_cec_standby_logical_addr < 0xF
	    && rtk_cec_standby_physical_addr != 0xFFFF) {
		p_this->status.enable = 1;
		p_this->status.standby_mode = 1;

		write_reg32(CEC_CR0,
			    (read_reg32(CEC_CR0) & ~(LOGICAL_ADDR(0xF) |
			    TIMER_DIV(0xFF) | PRE_DIV(0xFF))) |
			    CEC_MODE(1) | TIMER_DIV(0x14) |
			    PRE_DIV(0x21) | LOGICAL_ADDR(rtk_cec_standby_logical_addr));

		write_reg32(CEC_RXCR0, RX_RST);

		write_reg32(CEC_RXCR0, 0);

		write_reg32(CEC_TXCR0, TX_RST);

		write_reg32(CEC_TXCR0, 0);

#ifdef CEC_OPCODE_COMPARE_ENABLE
		write_reg32(GDI_CEC_OPCODE_ENABLE, 0);	/*disable */

		/*-- compare 1 */
		if (rtk_cec_standby_config &
		    STANBY_RESPONSE_GIVE_POWER_STATUS) {
			write_reg32(GDI_CEC_COMPARE_OPCODE_01,
				    CEC_MSG_GIVE_DEVICE_POWER_STATUS);
			write_reg32(GDI_CEC_SEND_OPCODE_01, CEC_MSG_REPORT_POWER_STATUS);
			write_reg32(GDI_CEC_SEND_OPERAND_NUMBER_01, 1);
			write_reg32(GDI_CEC_OPERAND_01, CEC_POWER_STATUS_STANDBY);
			write_reg32(GDI_CEC_OPCODE_ENABLE,
				    (read_reg32(GDI_CEC_OPCODE_ENABLE) | 0x01));
		}
		/*-- compare 2 */
		if (rtk_cec_standby_config &
		    STANBY_RESPONSE_GIVE_PHYSICAL_ADDR) {
			write_reg32(GDI_CEC_COMPARE_OPCODE_02, CEC_MSG_GIVE_PHYSICAL_ADDRESS);
			write_reg32(GDI_CEC_SEND_OPCODE_02,   CEC_MSG_REPORT_PHYSICAL_ADDRESS);
			write_reg32(GDI_CEC_SEND_OPERAND_NUMBER_02, 2);
			write_reg32(GDI_CEC_OPERAND_04,
				    (rtk_cec_standby_physical_addr >> 8) &
				    0xFF);
			write_reg32(GDI_CEC_OPERAND_05,
				    (rtk_cec_standby_physical_addr) & 0xFF);
			/*write_reg32(0xb8061ecc, (read_reg32(0xb8061ecc)|0x02)); //invalid, disable temporarily*/
		}
		/*-- compare 3*/
		if (rtk_cec_standby_config &
		    STANBY_RESPONSE_GET_CEC_VERISON) {
			write_reg32(GDI_CEC_COMPARE_OPCODE_03, CEC_MSG_GET_CEC_VERSION);
			write_reg32(GDI_CEC_SEND_OPCODE_03, CEC_MSG_CEC_VERSION);
			write_reg32(GDI_CEC_SEND_OPERAND_NUMBER_03, 1);
			write_reg32(GDI_CEC_OPERAND_07,
				    rtk_cec_standby_cec_version);
			write_reg32(GDI_CEC_OPCODE_ENABLE,
				    (read_reg32(GDI_CEC_OPCODE_ENABLE) | 0x04));
		}
		/*-- compare 4*/
		if (rtk_cec_standby_config &
		    STANBY_RESPONSE_GIVE_DEVICE_VENDOR_ID) {
			write_reg32(GDI_CEC_COMPARE_OPCODE_04, CEC_MSG_GIVE_DEVICE_VENDOR_ID);
			write_reg32(GDI_CEC_SEND_OPCODE_04, CEC_MSG_DEVICE_VENDOR_ID);
			write_reg32(GDI_CEC_SEND_OPERAND_NUMBER_04, 3);
			write_reg32(GDI_CEC_OPERAND_10,
				    (rtk_cec_standby_vendor_id >> 16) &
				    0xFF);
			write_reg32(GDI_CEC_OPERAND_11,
				    (rtk_cec_standby_vendor_id >> 8) &
				    0xFF);
			write_reg32(GDI_CEC_OPERAND_12,
				    (rtk_cec_standby_vendor_id) & 0xFF);
			write_reg32(GDI_CEC_OPCODE_ENABLE,
				    (read_reg32(GDI_CEC_OPCODE_ENABLE) | 0x08));
		}
		cec_info("CEC_COMP_ENABLE = %08x\n", read_reg32(GDI_CEC_OPCODE_ENABLE));
#endif /*ifdef CEC_OPCODE_COMPARE_ENABLE*/
		write_reg32(CEC_RXCR0, RX_EN | RX_CONTINUOUS);	/* enable RX */

		cec_info("cec standby enabled\n");
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_resume
 *
 * Desc : suspend a rtd299x cec adapter
 *
 * Parm : p_this : handle of rtd299x cec adapter
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int rtd299x_cec_resume(rtk_cec *p_this)
{
	cec_warn("%s cec resume\n", CEC_MODEL_NAME);

	/*p_this->status.enable = 0;*/
	p_this->status.standby_mode = 0;

	rtd299x_cec_intial_hw_setting();
	write_reg32(CEC_INT_EN, CEC_INT_EN_VAL | CEC_INT_EN_WRITE_DATA);
	if(p_this->status.state_before_suspend == 1)
	{
		p_this->status.state_before_suspend = 0;
		rtd299x_cec_set_mode(p_this, CEC_MODE_ON);
	}
	else if (rtk_cec_standby_config && rtk_cec_standby_logical_addr < 0xF
				&& rtk_cec_standby_physical_addr != 0xFFFF)
	{
		rtd299x_cec_set_mode(p_this, CEC_MODE_STANDBY);
	} 
	else
	{
	rtd299x_cec_set_mode(p_this, CEC_MODE_OFF);
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : pm_rtd299x_cec_suspend
 *
 * Desc : Force rtd299x cec to enter suspend state.
 *        this function will be called before enter 8051.
 *
 * Parm : None
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int pm_rtd299x_cec_suspend(void)
{
	return rtd299x_cec_suspend(&m_cec);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_early_enable
 *
 * Desc : Force darwin cec to enable when the system is cold boot.
 *        this function will be called by 8051
 *
 * Parm : None
 *
 * Retn : None
 *------------------------------------------------------------------*/
void rtd299x_cec_early_enable(void)
{
	/*general setup*/
	write_reg32(CEC_CR0, CEC_MODE(1) | TEST_MODE_PAD_EN |
		    LOGICAL_ADDR(0) | TIMER_DIV(25) |
		    PRE_DIV(_get_pre_div()) | UNREG_ACK_EN);
	/*reset engine*/
	write_reg32(CEC_RTCR0, RETRY_NO(rtk_cec_retry_num));
	write_reg32(CEC_RXCR0, RX_RST);
	write_reg32(CEC_RXCR0, 0);
	write_reg32(CEC_TXCR0, TX_RST);
	write_reg32(CEC_TXCR0, 0);

	/*timing setup*/
	write_reg32(CEC_RXTCR0, RX_START_LOW(140) | RX_START_PERIOD(188) |
		    RX_DATA_SAMPLE(42) | RX_DATA_PERIOD(PATCH_RX_DATA_PERIOD));
	write_reg32(CEC_TXTCR0, TX_START_LOW(149) | TX_START_HIGH(31));
	write_reg32(CEC_TXTCR1,
		    TX_DATA_LOW(25) | TX_DATA_01(36) | TX_DATA_HIGH(37));

	write_reg32(CEC_RxACKTCR1,
		    RX_ACK_LOW_SEL | RX_ACK_LOW(20) | RX_ACK_BIT(30) |
		    RX_ACK_LINE_ERR(94));
	/*enable Rx*/
	write_reg32(CEC_RXCR0, RX_EN | RX_CONTINUOUS);	/* enable RX */
}

/*//////////////////////////////////////////////////////////////////////
// CEC Driver Interface                                               //
//////////////////////////////////////////////////////////////////////*/

static int ops_probe(cec_device *dev)
{
	if (dev->id != ID_RTD299X_CEC_CONTROLLER)
		return -ENODEV;

	if (rtd299x_cec_init(&m_cec) == 0)
		cec_set_drvdata(dev, &m_cec);

	return 0;
}

static void ops_remove(cec_device *dev)
{
	rtd299x_cec_uninit((rtk_cec *) cec_get_drvdata(dev));
}

static int ops_enable(cec_device *dev, unsigned char on_off)
{

	cec_warn("ops_enable : %02x\n", on_off);
	if ((on_off & 0xf0) == 0) {
		if (on_off & 0x0f) { /*on*/
			rtk_cec_standby_config =
			    (STANBY_RESPONSE_GIVE_POWER_STATUS |
			     STANBY_RESPONSE_GET_CEC_VERISON);
			rtk_cec_standby_logical_addr = 0x0;
			rtk_cec_standby_physical_addr = 0x0000;
		} else {
			rtk_cec_standby_config = 0;
			rtk_cec_standby_logical_addr = 0xF;
			rtk_cec_standby_physical_addr = 0xFFFF;
		}
	}
	return rtd299x_cec_enable((rtk_cec *) cec_get_drvdata(dev),
				  (on_off & 0x0f));
}

static int ops_set_rx_mask(cec_device *dev, unsigned short rx_mask)
{
	return rtd299x_cec_set_rx_mask((rtk_cec *) cec_get_drvdata(dev),
				       rx_mask);
}

static int ops_set_physical_addr(cec_device *dev, unsigned short phy_addr)
{
	return rtd299x_cec_set_physical_addr((rtk_cec *)
					     cec_get_drvdata(dev), phy_addr);
}

static int ops_set_cev_version(cec_device *dev, unsigned char version)
{
	return rtd299x_cec_set_cec_version((rtk_cec *) cec_get_drvdata(dev),
					   version);
}

static int ops_set_device_vendor_id(cec_device *dev, unsigned long vendor_id)
{
	return rtd299x_cec_set_device_vendor_id((rtk_cec *)
						cec_get_drvdata(dev),
						vendor_id);
}

static int ops_xmit(cec_device *dev, cm_buff *cmb, unsigned long flags)
{
	return rtd299x_cec_xmit_message((rtk_cec *) cec_get_drvdata(dev),
					cmb, flags);
}

static cm_buff *ops_read(cec_device *dev, unsigned long flags)
{
	return rtd299x_cec_read_message((rtk_cec *) cec_get_drvdata(dev),
					flags);
}

static int ops_set_stanby_mode(cec_device *dev, unsigned long flags)
{
	return rtd299x_cec_set_stanby_mode((rtk_cec *) cec_get_drvdata(dev),
					   flags);
}

static int ops_set_retry_num(cec_device *dev, unsigned long num)
{
	return rtd299x_cec_set_retry_num((rtk_cec *) cec_get_drvdata(dev),
					 num);
}

static int ops_suspend(cec_device *dev)
{
	return rtd299x_cec_suspend((rtk_cec *) cec_get_drvdata(dev));
}

static int ops_resume(cec_device *dev)
{
	return rtd299x_cec_resume((rtk_cec *) cec_get_drvdata(dev));
}

static cec_device rtd299x_cec_controller = {
	.id = ID_RTD299X_CEC_CONTROLLER,
	.name =  CEC_DRIVE_NAME
};

static cec_driver rtd299x_cec_driver = {

	.name = CEC_DRIVE_NAME,
	.probe = ops_probe,
	.remove = ops_remove,
	.suspend = ops_suspend,
	.resume = ops_resume,
	.enable = ops_enable,
	.xmit = ops_xmit,
	.read = ops_read,
	.set_rx_mask = ops_set_rx_mask,
	.set_physical_addr = ops_set_physical_addr,
	.set_cec_version = ops_set_cev_version,
	.set_device_vendor_id = ops_set_device_vendor_id,
	.set_stanby_mode = ops_set_stanby_mode,
	.set_retry_num = ops_set_retry_num,
};

/*------------------------------------------------------------------
 * Func : rtd299x_cec_module_init
 *
 * Desc : rtd299x cec module init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtd299x_cec_module_init(void)
{
	cec_info("%s cec module init\n", CEC_MODEL_NAME);

	if (register_cec_driver(&rtd299x_cec_driver) != 0)
		return -EFAULT;

	register_cec_device(&rtd299x_cec_controller);	/* register cec device */

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_module_exit
 *
 * Desc : rtd299x cec module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtd299x_cec_module_exit(void)
{
	unregister_cec_device(&rtd299x_cec_controller);

	unregister_cec_driver(&rtd299x_cec_driver);
}

module_init(rtd299x_cec_module_init);
module_exit(rtd299x_cec_module_exit);
