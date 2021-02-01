/*
 * 8250_dma.c - DMA Engine API support for 8250.c
 *
 * Copyright (C) 2013 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/serial_reg.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#include <linux/serial_core.h>
#include <linux/delay.h>

#include "8250.h"
#if defined(CONFIG_REALTEK_RTICE) || defined(CONFIG_RTK_KDRV_RTICE)
extern void serial8250_uart_write_wakeup(struct uart_8250_port* up, int delay);
#endif

#ifdef CONFIG_REALTEK_UART_DMA

int rtk_serial8250_request_dma(struct uart_8250_port *up)
{
	struct uart_port *port = &up->port;
	struct circ_buf *xmit = &port->state->xmit;
	struct uart_8250_rtk_dma *rtk_dma = NULL;
	int dma_reg_ofst = up->rtk_dma_config.dma_membase_ofst;

	rtk_dma = (struct uart_8250_rtk_dma *)kmalloc(sizeof(struct uart_8250_rtk_dma), GFP_KERNEL);
	if(!rtk_dma)
		return -ENOMEM;
	memset(rtk_dma, 0, sizeof(struct uart_8250_rtk_dma));

	up->port.dev->coherent_dma_mask = DMA_BIT_MASK(UART1_DMA_BIT_MASK);
	up->port.dev->dma_mask = &up->port.dev->coherent_dma_mask;
	if(dma_set_mask(up->port.dev, DMA_BIT_MASK(UART1_DMA_BIT_MASK))) {
		dev_dbg_ratelimited(up->port.dev, "%s DMA not supported!\n", __FUNCTION__);
	}
	dma_set_coherent_mask(up->port.dev, DMA_BIT_MASK(UART1_DMA_BIT_MASK));


	rtk_dma->tx_dma_ring_buf_head = dma_alloc_coherent(up->port.dev, UART_XMIT_SIZE,
			&rtk_dma->tx_dma_addr, GFP_KERNEL);
	if(!rtk_dma->tx_dma_ring_buf_head) {
		kfree(rtk_dma);
		rtk_dma = NULL;
		return -ENOMEM;
	}
	
	free_page((unsigned long)xmit->buf);
	xmit->buf = rtk_dma->tx_dma_ring_buf_head;
	rtk_dma->tx_dma_ring_buf_align = rtk_dma->tx_dma_ring_buf_head;
	rtk_dma->tx_dma_ring_buf_size = UART_XMIT_SIZE;

	dev_dbg_ratelimited(up->port.dev, "tx_buf_head == %08x, tx_buf_align == %08x, dma_ring_buf_len == %d tx_addr == %08x\n", 
		rtk_dma->tx_dma_ring_buf_head, rtk_dma->tx_dma_ring_buf_align, rtk_dma->tx_dma_ring_buf_size, rtk_dma->tx_dma_addr);

	/*initial the dma reg setting*/
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXBASE,
		UR1_TX_BASE(rtk_dma->tx_dma_addr));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXLIMIT,
		UR1_TX_LIMIT(rtk_dma->tx_dma_addr + rtk_dma->tx_dma_ring_buf_size));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXWRPTR,
		UR1_TX_WRPTR(rtk_dma->tx_dma_addr));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXRDPTR,
		UR1_TX_TXRDPTR(rtk_dma->tx_dma_addr));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXTHD,
		UR1_TX_THD(up->rtk_dma_config.dma_tx_thd));
	serial_port_out(port, dma_reg_ofst + UART_DMA_INT_EN, UR1_UR_TX_THD_EN(1));
	serial_port_out(port, dma_reg_ofst + UART_DMA_GATING_EN_CTRL,
		UR1_GATING_EN(1));

	/*
	pr_warning(
		"rtk_serial8250_request_dma DMA CONFIG:%08x, %08x, %08x, %08x %08x, %08x\n", 
			serial_port_in(port, dma_reg_ofst + UART_DMA_TXBASE),
			serial_port_in(port, dma_reg_ofst + UART_DMA_TXLIMIT),
			serial_port_in(port, dma_reg_ofst + UART_DMA_TXWRPTR),
			serial_port_in(port, dma_reg_ofst + UART_DMA_TXRDPTR),
			serial_port_in(port, dma_reg_ofst + UART_DMA_TXTHD),
			serial_port_in(port, dma_reg_ofst + UART_DMA_GATING_EN_CTRL)
		);
	*/
	
	serial_port_out(port, dma_reg_ofst + UART_DMA_CTRL,
		UR1_TXEMPTHR(up->rtk_dma_config.dma_tx_empty_thd) | UR1_DMAIFEN(0));

	up->rtk_dma = rtk_dma;
	
	dev_dbg_ratelimited(up->port.dev, "got both dma channels\n");
	
	return 0;
}
EXPORT_SYMBOL_GPL(rtk_serial8250_request_dma);

void rtk_serial8250_release_dma(struct uart_8250_port *up)
{
	struct uart_port *port = &up->port;
	struct circ_buf *xmit = &port->state->xmit;
	struct uart_8250_rtk_dma *rtk_dma = NULL;
	int dma_reg_ofst = up->rtk_dma_config.dma_membase_ofst;
	rtk_dma = up->rtk_dma;
	up->rtk_dma = NULL;
	
	serial_port_out(port, dma_reg_ofst + UART_DMA_CTRL, UR1_DMAIFEN(0));
	serial_port_out(port, dma_reg_ofst + UART_DMA_GATING_EN_CTRL, UR1_GATING_EN(0));
	serial_port_out(port, dma_reg_ofst + UART_DMA_INT_EN, UR1_UR_TX_THD_EN(0));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXBASE, 0);
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXLIMIT, 0);
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXWRPTR, 0);
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXRDPTR, 0);
	
	dma_free_coherent(up->port.dev, UART_XMIT_SIZE, rtk_dma->tx_dma_ring_buf_head,
			  	rtk_dma->tx_dma_addr);
	xmit->buf = NULL;
	xmit->head = xmit->tail = 0;
	
	rtk_dma->tx_dma_ring_buf_head = NULL;
	rtk_dma->tx_dma_ring_buf_align = NULL;
	
	kfree(rtk_dma);
	rtk_dma = NULL;
}
EXPORT_SYMBOL_GPL(rtk_serial8250_release_dma);

void rtk_serial8250_tx_dma(struct uart_8250_port *up)
{
	struct uart_8250_rtk_dma *dma = up->rtk_dma;
	struct uart_port *port = &up->port;
	struct circ_buf *xmit = &port->state->xmit;
	int dma_reg_ofst = up->rtk_dma_config.dma_membase_ofst;
	int dma_read_ofst = 0;
	int dma_write_ofst = 0;

#if defined(CONFIG_REALTEK_RTICE) || defined(CONFIG_RTK_KDRV_RTICE)
	if (up->disable_printk)
		goto proc_disable_print;
#endif	

	dma_read_ofst = serial_port_in(port, dma_reg_ofst + UART_DMA_TXRDPTR) - up->rtk_dma->tx_dma_addr;
	xmit->tail = dma_read_ofst;

	if (uart_tx_stopped(port)) {
		return;
	}
	if(uart_circ_empty(xmit)) {
		uart_write_wakeup(port);
		return;
	}
	
	dma_write_ofst = serial_port_in(port, dma_reg_ofst + UART_DMA_TXWRPTR) -
			up->rtk_dma->tx_dma_addr;
	if(dma_read_ofst == dma_write_ofst && dma_write_ofst == xmit->head) { /*Since the last time no more data to transfer*/
		uart_write_wakeup(port);
		return;
	}
	port->icount.tx += (xmit->head > dma_write_ofst) ? (xmit->head - dma_write_ofst) :
		(UART_XMIT_SIZE -dma_write_ofst + xmit->head);
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXWRPTR,
		UR1_TX_WRPTR(dma->tx_dma_addr + xmit->head));
	serial_port_out(port, dma_reg_ofst + UART_DMA_CTRL,
		UR1_TXEMPTHR(up->rtk_dma_config.dma_tx_empty_thd) | UR1_DMAIFEN(1));
	if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
		uart_write_wakeup(port);
	
	return;
	
#if defined(CONFIG_REALTEK_RTICE) || defined(CONFIG_RTK_KDRV_RTICE)
proc_disable_print:
	xmit->tail = xmit->head;        // ignore add data...
	serial_port_out(port, dma_reg_ofst + UART_DMA_CTRL,
		UR1_TXEMPTHR(up->rtk_dma_config.dma_tx_empty_thd) | UR1_DMAIFEN(0));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXRDPTR,
		UR1_TX_TXRDPTR(up->rtk_dma->tx_dma_addr));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXWRPTR,
		UR1_TX_WRPTR(up->rtk_dma->tx_dma_addr));
	serial8250_uart_write_wakeup(up, 1);    // wait up tty after 1 jiffies
	return;
#endif	
	
}
EXPORT_SYMBOL_GPL(rtk_serial8250_tx_dma);

/*
 *	Wait for all data finshed.
 */
//static
void rtk_serial8250_dma_wait_for_xmitr(struct uart_8250_port *up)
{
	unsigned int tmout = 10000;
	int dma_reg_ofst = up->rtk_dma_config.dma_membase_ofst;
	struct uart_port *port = &up->port;
	int dma_read_ofst = 0;
	int dma_write_ofst = 0;
	int tx_wrd_count = 0;
	
	/* Wait up to 1s for the character(s) to be sent. */
	for (;;) {
		dma_read_ofst = serial_port_in(port, dma_reg_ofst + UART_DMA_TXRDPTR) - up->rtk_dma->tx_dma_addr;
		dma_write_ofst = serial_port_in(port, dma_reg_ofst + UART_DMA_TXWRPTR) - up->rtk_dma->tx_dma_addr;
		tx_wrd_count = UR1_TX_WRD_COUNT(serial_port_in(port, dma_reg_ofst + UART_DMA_STS));
		if(dma_read_ofst == dma_write_ofst)
			break;
		if (--tmout == 0)
			break;
		udelay(1);
	}

}

static int rtk_serial8250_dma_puts(struct uart_port *port,
					const unsigned char *buf, int count)
{
	struct circ_buf *circ = &port->state->xmit;;
	int c, ret = 0;
	/*
	 * This means you called this function _after_ the port was
	 * closed.  No cookie for you.
	 */
	if (!circ) {
		WARN_ON(1);
		return -EL3HLT;
	}
	if (!circ->buf)
		return -ENOBUFS;
	while (1) {
		c = CIRC_SPACE_TO_END(circ->head, circ->tail, UART_XMIT_SIZE);
		if (count < c)
			c = count;
		if (c <= 0)
			break;
		memcpy(circ->buf + circ->head, buf, c);
		circ->head = (circ->head + c) & (UART_XMIT_SIZE - 1);
		buf += c;
		count -= c;
		ret += c;
	}
	//if (!uart_tx_stopped(port))
		port->ops->start_tx(port);
	return ret;
}

static void _rtk_serial8250_dma_console_write(struct uart_port *port,
					const unsigned char *buf, int count)
{
	struct uart_8250_port *up = up_to_u8250p(port);
	int sent_count = 0;
	int ret = 0;
	//rtk_serial8250_dma_wait_for_xmitr(up);
#if !(defined(CONFIG_REALTEK_RTICE) && defined(CONFIG_RTK_KDRV_RTICE))	
	while(sent_count < count) {
		ret = rtk_serial8250_dma_puts(port, buf + sent_count, count - sent_count);
		if(ret < 0)
			break;
		else if(ret == 0)
			udelay(1);
		else
			sent_count += ret;
	}
#else
	if(up->disable_printk != 1) {
		while(sent_count < count) {
			ret = rtk_serial8250_dma_puts(port, buf + sent_count, count - sent_count);
			if(ret < 0)
				break;
			else if(ret == 0)
				udelay(1);
			else
				sent_count += ret;
		}
	} else {
		serial8250_uart_write_wakeup(up, 1);	// wait up tty after 1 jiffies
		rtk_serial8250_dma_flush_buffer(up);
	}
#endif
}

void rtk_serial8250_dma_console_write(struct uart_port *port,
					const unsigned char *buf, int count)
{
	int head = 0;
	int tail = 0;
	char ch = '\r';
	for (head = 0; head < count;) {
		if (buf[head] == '\n') {
			_rtk_serial8250_dma_console_write(port, buf + tail, head - tail + 1);
			_rtk_serial8250_dma_console_write(port, &ch, 1);
			head++;
			tail = head;
		} else {
			 head++;
		}
	}
	if(tail <= count - 1)
		_rtk_serial8250_dma_console_write(port, buf + tail, head - tail);
}
EXPORT_SYMBOL_GPL(rtk_serial8250_dma_console_write);
void rtk_serial8250_dma_flush_buffer(struct uart_8250_port *up)
{
	struct uart_port *port = &up->port;
	int dma_reg_ofst = up->rtk_dma_config.dma_membase_ofst;
	struct circ_buf *xmit = &port->state->xmit;
	xmit->tail = xmit->head = 0;        // ignore add data...
	serial_port_out(port, dma_reg_ofst + UART_DMA_CTRL,
		UR1_TXEMPTHR(up->rtk_dma_config.dma_tx_empty_thd) | UR1_DMAIFEN(0));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXRDPTR,
		UR1_TX_TXRDPTR(up->rtk_dma->tx_dma_addr));
	serial_port_out(port, dma_reg_ofst + UART_DMA_TXWRPTR,
		UR1_TX_WRPTR(up->rtk_dma->tx_dma_addr));
}
EXPORT_SYMBOL_GPL(rtk_serial8250_dma_flush_buffer);
#endif
