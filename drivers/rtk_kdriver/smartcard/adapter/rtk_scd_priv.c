/* ------------------------------------------------------------------------
   scd_rtd299x.c  scd driver for Realtek Neptune/rtd299x
   -------------------------------------------------------------------------
    Copyright (C) 2008 Kevin Wang <kevin_wang@realtek.com.tw>

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
----------------------------------------------------------------------------
Update List :
----------------------------------------------------------------------------
    1.0     |   20090312    |   Kevin Wang  | 1) create phase
----------------------------------------------------------------------------*/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <asm/io.h>
#include <asm/irq.h>
#include <asm/delay.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif
#include "rtk_scd_priv.h"
#include "rtk_scd_reg.h"
#include "rtk_scd_debug.h"
#include <rtk_kdriver/rtk_crt.h>
MODULE_LICENSE("GPL");

#define SA_SHIRQ IRQF_SHARED

#define SET_MIS_ISR(adp, val)        rtd_outl(adp->reg.ISR,   val)
#define SET_SCFP(adp,   val)         rtd_outl(adp->reg.FP,    val)
#define SET_SCCR(adp,   val)         rtd_outl(adp->reg.CR,    val)
#define SET_SCPCR(adp,  val)         rtd_outl(adp->reg.PCR,   val)
#define SET_SC_TXFIFO(adp, val)      rtd_outl(adp->reg.TXFIFO, val)
#define SET_SCFCR(adp,  val)         rtd_outl(adp->reg.FCR,   val)
#define SET_SCIRSR(adp, val)         rtd_outl(adp->reg.IRSR,  val)
#define SET_SCIRER(adp, val)         rtd_outl(adp->reg.IRER,  val)

#define GET_MIS_ISR(adp)             rtd_inl(adp->reg.ISR)

#ifdef SC_AYNC_RBUS_READ_RECOVERY

#define READ_RECOVERY_CNT   20

static unsigned long rtd_inl_ex(unsigned long addr, int try_cnt)
{
	unsigned long val = 0;

	do {
		val = rtd_inl(addr);

		if (val)
			break;

		ndelay(500);
	} while (try_cnt-- > 0);

	return val;
}

#define GET_SCFP(adp)                rtd_inl_ex(adp->reg.FP,     READ_RECOVERY_CNT * 5)
#define GET_SCCR(adp)                rtd_inl_ex(adp->reg.CR,     READ_RECOVERY_CNT)
#define GET_SCPCR(adp)               rtd_inl_ex(adp->reg.PCR,    READ_RECOVERY_CNT)
#define GET_SC_RXLENR(adp)           rtd_inl_ex(adp->reg.RXLENR, READ_RECOVERY_CNT)
#define GET_SCFCR(adp)               rtd_inl_ex(adp->reg.FCR,    READ_RECOVERY_CNT)
#define GET_SCIRSR(adp)              rtd_inl_ex(adp->reg.IRSR,   READ_RECOVERY_CNT)
#define GET_SCIRER(adp)              rtd_inl_ex(adp->reg.IRER,   READ_RECOVERY_CNT)

unsigned long GET_SC_RXFIFO(scd *p_this)
{
	int try_cnt = READ_RECOVERY_CNT;
	int rx_len = GET_SC_RXLENR(p_this);

	unsigned long val = 0;

	/*SC_WARNING("GET_SC_RXFIFO : rx_len = %d\n", rx_len);*/

	do {
		val = GET_SC_RXFIFO(p_this);

		if (val)
			break;

		ndelay(10);
	} while (rx_len && GET_SC_RXLENR(p_this) >= rx_len && try_cnt-- > 0);

	if (val == 0 && try_cnt < 0)
		SC_ERR("GET_SC_RXFIFO retry_timeout\n");

	return val;
}

#else

#define GET_SCFP(adp)                rtd_inl(adp->reg.FP)
#define GET_SCCR(adp)                rtd_inl(adp->reg.CR)
#define GET_SCPCR(adp)               rtd_inl(adp->reg.PCR)
#define GET_SC_RXFIFO(adp)           rtd_inl(adp->reg.RXFIFO)
#define GET_SC_RXLENR(adp)           rtd_inl(adp->reg.RXLENR)
#define GET_SCFCR(adp)               rtd_inl(adp->reg.FCR)
#define GET_SCIRSR(adp)              rtd_inl(adp->reg.IRSR)
#define GET_SCIRER(adp)              rtd_inl(adp->reg.IRER)

#endif

#define MAX_SC_CLK                   8500000
#define MIN_SC_CLK                   1000000

#ifdef ISR_POLLING
#define ISR_POLLING_INTERVAL        (HZ)
static void scd_timer(unsigned long arg);
#endif

extern char *parse_token(const char *parsed_string, const char *token);


typedef struct {
    unsigned long       time_stamp;
    unsigned long       event;
    #define SC_TX_EVENT_ENTER 0
    #define SC_TX_EVENT_GO    1
    #define SC_TX_EVENT_ISR   2
    #define SC_TX_EVENT_POLL  3
    #define SC_TX_EVENT_DONE  4
    #define SC_TX_EVENT_EXIT  5
    unsigned long       tx_fifo_len;
    unsigned long       tx_status;
    unsigned long       SCCR;
    unsigned long       IRSR;
    unsigned long       IRER;    
    unsigned long       MIS_ISR;    
    
}SC_TX_EVENT_LOG;

#define MAX_TX_EVENT_LOG 32
unsigned int tx_event_log_idx = 0;
SC_TX_EVENT_LOG tx_event_log[MAX_TX_EVENT_LOG];
#define SC_RX_EVENT_ISR 10

static void _LOG_TX_STATUS(scd *p_this, unsigned long event)
{
    tx_event_log[tx_event_log_idx].time_stamp = jiffies;        
    tx_event_log[tx_event_log_idx].event = event;        
    tx_event_log[tx_event_log_idx].tx_fifo_len = kfifo_len(&p_this->tx_fifo);
    tx_event_log[tx_event_log_idx].tx_status = p_this->tx_status;
    tx_event_log[tx_event_log_idx].SCCR    = GET_SCCR(p_this);    
    tx_event_log[tx_event_log_idx].IRSR    = GET_SCIRSR(p_this);
    tx_event_log[tx_event_log_idx].IRER    = GET_SCIRER(p_this);
    tx_event_log[tx_event_log_idx].MIS_ISR = GET_MIS_ISR(p_this);          
    tx_event_log_idx++;
}

static const char* TxEvent(unsigned long event)
{
    switch(event)
    {
    case SC_TX_EVENT_ENTER: return "Enter";
    case SC_TX_EVENT_GO: return "Go";
    case SC_TX_EVENT_ISR: return "TX_ISR";
    case SC_TX_EVENT_POLL: return "Poll";
    case SC_TX_EVENT_DONE: return "Done";
    case SC_TX_EVENT_EXIT: return "Exit"; 
	case SC_RX_EVENT_ISR: return "RX_ISR";
    }
    
    return "Unknow";
}

static void LOG_SC_TX_ENTER(scd *p_this)
{
    tx_event_log_idx = 0;
    _LOG_TX_STATUS(p_this, SC_TX_EVENT_ENTER);    
}


static void dump_sc_tx_log(scd *p_this,int flag)
{
    int i=0;
    SC_WARNING("=================== SC_TX_LOG ====================\n");
    for (i=0; i<tx_event_log_idx; i++)
    {
     if(flag)
        SC_ERR("[%08lu] event=%s, fifo_len=%d, tx_status=%x, SCCR=%08lx, IRSR=%08lx, IRER=%08lx, MIS_ISR=%08lx\n", 
            tx_event_log[i].time_stamp, 
            TxEvent(tx_event_log[i].event),
            tx_event_log[i].tx_fifo_len, 
            tx_event_log[i].tx_status, 
            tx_event_log[i].SCCR,
            tx_event_log[i].IRSR,
            tx_event_log[i].IRER,
            tx_event_log[i].MIS_ISR);
	else
        SC_WARNING("[%08lu] event=%s, fifo_len=%d, tx_status=%x, SCCR=%08lx, IRSR=%08lx, IRER=%08lx, MIS_ISR=%08lx\n", 
            tx_event_log[i].time_stamp, 
            TxEvent(tx_event_log[i].event),
            tx_event_log[i].tx_fifo_len, 
            tx_event_log[i].tx_status, 
            tx_event_log[i].SCCR,
            tx_event_log[i].IRSR,
            tx_event_log[i].IRER,
            tx_event_log[i].MIS_ISR);
    }
}

#define LOG_SC_TX_GO(p_this)      _LOG_TX_STATUS(p_this, SC_TX_EVENT_GO)
#define LOG_SC_TX_ISR(p_this)     _LOG_TX_STATUS(p_this, SC_TX_EVENT_ISR)
#define LOG_SC_RX_ISR(p_this)     _LOG_TX_STATUS(p_this, SC_RX_EVENT_ISR)
#define LOG_SC_TX_POLL(p_this)    _LOG_TX_STATUS(p_this, SC_TX_EVENT_POLL)
#define LOG_SC_TX_DONE(p_this)    _LOG_TX_STATUS(p_this, SC_TX_EVENT_DONE)
#define LOG_SC_TX_EXIT(p_this)    _LOG_TX_STATUS(p_this, SC_TX_EVENT_EXIT)


/*------------------------------------------------------------------
 * Func : scd_power_enable
 *
 * Desc : enable power for SMC
 *
 * Parm : p_this : handle of smartcard ifd
 *        on     : enable / disable power
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_power_enable(scd *p_this, unsigned char on)
{
	unsigned char val =
	    (on) ? ((p_this->cmd_vcc_polarity) ? 1 : 0)
	    : ((p_this->cmd_vcc_polarity) ? 0 : 1);

	if (p_this->cmd_vcc_en) {
		/*SC_INFO("SC%d - power enable=%d, %s_GPIO[%d]=%d\n",
		p_this->id, on, gpio_type(p_this->pin_cmd_vcc), gpio_idx(p_this->pin_cmd_vcc), val);*/
		rtk_gpio_output(p_this->pin_cmd_vcc, val);
	}
}

/*------------------------------------------------------------------
 * Func : scd_power_select
 *
 * Desc : enable power select for SMC
 *
 * Parm : p_this : handle of smartcard ifd
 *        on     : enable / disable power select pin
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_power_select(scd *p_this, unsigned char on)
{
	unsigned char val =
	    (on) ? ((p_this->pwr_sel_polarity) ? 1 : 0)
	    : ((p_this->pwr_sel_polarity) ? 0 : 1);

	if (p_this->pwr_sel_en) {
		/*SC_INFO("SC%d - power select=%d, %s_GPIO[%d]=%d\n",
		p_this->id, on, gpio_type(p_this->pin_pwr_sel), gpio_idx(p_this->pin_pwr_sel), val);*/
		rtk_gpio_output(p_this->pin_pwr_sel, val);
	}
}

/*------------------------------------------------------------------
 * Func : scd_set_state
 *
 * Desc :
 *
 * Parm : p_this : handle of smartcard ifd
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int scd_set_state(scd *p_this, IFD_FSM fsm)
{
	unsigned char id = p_this->id;

	if (p_this->fsm == fsm)
		return 0;

	switch (fsm) {
	case IFD_FSM_DISABLE:

		SC_INFO("SC%d - FSM = DISABLE\n", id);

		SET_SCFP(p_this, SC_CLK_EN(0) | SC_CLKDIV((p_this->clock_div - 1)) | SC_BAUDDIV2(p_this->baud_div2) |
			 SC_BAUDDIV1((p_this->baud_div1 - 1)) |
			 SC_PRE_CLKDIV((p_this->pre_clock_div - 1)));

		SET_SCPCR(p_this, SC_TXGRDT(0) |
			  SC_CWI(0) |
			  SC_BWI(0) |
			  SC_WWI(0) |
			  SC_BGT(0x16) |
			  SC_EDC_EN(0) |
			  SC_CRC(0) |
			  SC_PROTOCOL_T(0) | SC_T0RTY(0) | SC_T0RTY_CNT(0));

		SET_SCCR(p_this,
			 SC_FIFO_RST(1) | SC_SCEN(0) | SC_AUTO_ATR(1) |
			 SC_CONV(0) | SC_PS(p_this->parity) | (1 << 19));
		SET_SCIRER(p_this, 0);	/* Disable ISR*/
		SET_SCIRSR(p_this, 0xFFFFFFFF);
		scd_power_enable(p_this, 0);
		/*rtd_outl(SC_SRC0_PIN_MUX0, (rtd_inl(SC_SRC0_PIN_MUX0)& ~0xF0) | 0xF0);      // set SC_DATA to GPIO mode  */
		p_this->atr.length = -1;
		break;

	case IFD_FSM_DEACTIVATE:

		SC_INFO("SC%d - FSM = IDEL\n", id);
		scd_set_etu(p_this, 372);
		scd_set_parity(p_this, 1);

		SET_SCFP(p_this, SC_CLK_EN(1) | SC_CLKDIV((p_this->clock_div - 1)) | SC_BAUDDIV2(p_this->baud_div2) |
			 SC_BAUDDIV1((p_this->baud_div1 - 1)) |
			 SC_PRE_CLKDIV((p_this->pre_clock_div - 1)));

		SET_SCCR(p_this,
			 SC_FIFO_RST(0) | SC_SCEN(0) | SC_AUTO_ATR(1) |
			 SC_CONV(0) | SC_PS(p_this->parity));
		udelay(1000);
		SET_SCCR(p_this,
			 SC_FIFO_RST(0) | SC_SCEN(1) | SC_AUTO_ATR(1) |
			 SC_CONV(0) | SC_PS(p_this->parity) | (1 << 19));
		SET_SCIRER(p_this, SC_CPRES_INT);
		SET_SCIRSR(p_this, 0xFFFFFFFF);
		scd_power_enable(p_this, 0);
		p_this->atr.length = -1;
		/*rtd_outl(SC_SRC0_PIN_MUX0, (rtd_inl(SC_SRC0_PIN_MUX0)& ~0xF0) | 0xF0);      // set SC_DATA to GPIO mode */
		kfifo_reset(&p_this->rx_fifo);
		break;

	case IFD_FSM_RESET:

		p_this->atr.length = -1;

		if (!scd_card_detect(p_this)) {
			SC_ERR
			    ("SC%d - RESET scd failed, no ICC exist\n",
			     id);
			scd_set_state(p_this, IFD_FSM_DEACTIVATE);
			return SC_ERR_NO_ICC;
		}

		scd_power_select(p_this, p_this->vcc_5v);
		scd_power_enable(p_this, 1);	/* Power On */
		/*rtd_outl(SC_SRC0_PIN_MUX0, (rtd_inl(SC_SRC0_PIN_MUX0)& ~0xF0) | 0x60);      // set SC_DATA to IO mode */
		msleep(10);
		/*scd_set_etu(p_this, 372);  */
		/*scd_set_parity(p_this, 1);  */
		scd_set_guard_interval(p_this, 2);	/* minimum Guard interval*/
		kfifo_reset(&p_this->rx_fifo);

		SET_SCIRER(p_this, SC_CPRES_INT |
			   SC_ATRS_INT |
			   SC_RXP_INT | SC_RCV_INT | SC_RX_FOVER_INT);

		SET_SCCR(p_this, 0);

		SET_SCCR(p_this, SC_FIFO_RST(1) |	/* pull reset pin*/
			 SC_RST(1) |
			 SC_SCEN(1) |
			 SC_AUTO_ATR(1) | SC_CONV(0) | SC_PS(p_this->parity));

		p_this->atr_timeout = jiffies + HZ;

		SC_INFO("SC%d - FSM = RESET & ATR\n", id);

		break;

	case IFD_FSM_ACTIVE:
		SC_INFO("SC%d - FSM = ACTIVATE\n", id);

		SET_SCIRER(p_this, SC_CPRES_INT |
			   SC_ATRS_INT |
			   SC_RXP_INT | SC_RCV_INT | SC_RX_FOVER_INT);
		break;

	default:
	case IFD_FSM_UNKNOWN:
		break;
	}

	p_this->fsm = fsm;

	p_this->card_status_change = 1;
	wake_up(&p_this->wq);

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_fsm_reset
 *
 * Desc :
 *
 * Parm : p_this : handle of cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_fsm_reset(scd *p_this)
{
	unsigned long event = GET_SCIRSR(p_this);
	unsigned long rx_len = 0;
	unsigned long i = 0;

	SC_INT_DBG("scd_fsm_reset : SC_RISR=%08lx\n", event);

	if ((event & SC_RXP_INT) || !(event & SC_PRES)
	    || time_after(jiffies, p_this->atr_timeout))
		goto err_atr_failed;

	if (event & SC_ATRS_INT) {
		SC_INT_DBG
		    ("scd_fsm_reset : Got ATR INT, reset ATR buffer\n");

		if (p_this->atr.length == -1)
			p_this->atr.length = 0;	/*got ATR */
	}

	if (event & SC_RCV_INT) {
		SC_INT_DBG
		    ("scd_fsm_reset : Got RCV INT, p_this->atr.length==%d, rx_len=%d\n",
		     p_this->atr.length, GET_SC_RXLENR(p_this));

		if (p_this->atr.length < 0) {
			/* unwanted data, drop it*/
			rx_len = GET_SC_RXLENR(p_this);

			for (i = 0; i < rx_len; i++)
				GET_SC_RXFIFO(p_this);

			goto end_proc;
		}
		/* receive atr :*/
		while (GET_SC_RXLENR(p_this)) {
			if (p_this->atr.length >= MAX_ATR_SIZE)
				goto err_atr_failed;

			p_this->atr.data[p_this->atr.length] =
			    GET_SC_RXFIFO(p_this);

			if (p_this->atr.length == 0) {
				switch (p_this->atr.data[0]) {
				case 0x3B:
					SC_INFO
					    ("SC%d - Direct Convention (%02x)\n",
					     p_this->id, p_this->atr.data[0]);
					break;

				case 0x03:
					p_this->atr.data[0] = 0x3F;
					SC_INFO
					    ("SC%d - Inverse Convention (%02x)\n",
					     p_this->id, p_this->atr.data[0]);
					break;

				default:
					SC_ERR("SC%d - unknown TS (%02x)\n",
						   p_this->id,
						   p_this->atr.data[0]);
					break;
				}
			}

			p_this->atr.length++;
			wake_up(&p_this->wq);
		}

		SC_INT_DBG("scd_fsm_reset : p_this->atr.length=%d\n",
			   p_this->atr.length);

		/* check atr */
		if (is_atr_complete(&p_this->atr)) {
			SC_INFO("SC%d - Got ATR Completed\n", p_this->id);

			if (decompress_atr(&p_this->atr, &p_this->atr_info) < 0)
				goto err_atr_failed;

			scd_set_state(p_this, IFD_FSM_ACTIVE);	/* jump to active state*/
		}
	}

end_proc:
	SET_SCIRSR(p_this, event);
	return;

err_atr_failed:

	if (!(event & SC_PRES)) {
		SC_ERR("SC%d - RESET ICC failed, no ICC detected\n",
			   p_this->id);
	}

	if (event & SC_RXP_INT) {
		SC_ERR("SC%d - RESET ICC failed, RX Parity Error\n",
			   p_this->id);
	}

	if (time_after(jiffies, p_this->atr_timeout)) {
		SC_ERR("SC%d - RESET ICC failed, timeout\n", p_this->id);
	}

	if (p_this->atr.length < 0) {
		SC_ERR("SC%d - RESET ICC failed, wait ATR failed\n",
			   p_this->id);
	} else if (p_this->atr.length >= MAX_ATR_SIZE) {
		SC_ERR
		    ("SC%d - RESET ICC failed, atr length %d more then %d\n",
		     p_this->id, p_this->atr.length, MAX_ATR_SIZE);
	} else if (!is_atr_complete(&p_this->atr)) {
		SC_ERR("SC%d - RESET ICC failed, incomplete atr\n",
			   p_this->id);
	} else if (decompress_atr(&p_this->atr, &p_this->atr_info) < 0) {
		SC_ERR("SC%d - RESET ICC failed, decompress atr failed\n",
			   p_this->id);
	} else {
		SC_ERR("SC%d - RESET ICC failed, parse protocol faield\n",
			   p_this->id);
	}

	scd_set_state(p_this, IFD_FSM_DEACTIVATE);
	goto end_proc;
}

/*------------------------------------------------------------------
 * Func : scd_fsm_active
 *
 * Desc :
 *
 * Parm : p_this : handle of cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_fsm_active(scd *p_this)
{
	unsigned long event = GET_SCIRSR(p_this) & GET_SCIRER(p_this);
	unsigned char i;
	unsigned char len;
	unsigned char buff[40];

	SET_SCIRSR(p_this, event);

	if (event & SC_RCV_INT) {
		len = GET_SC_RXLENR(p_this);
		if (len) {
			for (i = 0; i < len; i++) {
				buff[i] = GET_SC_RXFIFO(p_this);
				rmb();
			}

			if (kfifo_in_locked
			    (&p_this->rx_fifo, buff, len,
			     &p_this->rx_fifo_lock) < len) {
				SC_WARNING
				    ("scd_fsm_active : fifo over flow... flush data...\n");
				kfifo_reset(&p_this->rx_fifo);
			}

			wake_up(&p_this->wq);
		}

		if (event & SC_RX_FOVER_INT) {
			SC_ERR("Rx over flow!\n");
			SET_SCCR(p_this, GET_SCCR(p_this) | SC_FIFO_RST(1));
		}
	}

	if (event & SC_TXEMPTY_INT) {
#ifdef USE_TX_FIFO

	    LOG_SC_TX_ISR(p_this);
	    
		int tx_data_len = kfifo_len(&p_this->tx_fifo);	/* get number of data to xmit*/

		if (tx_data_len && (p_this->tx_status & SC_TX_ABORT) == 0) {
			unsigned char tx_buff[40];

			tx_data_len =
			    kfifo_out(&p_this->tx_fifo, tx_buff,
				      sizeof(tx_buff));

			/*SC_WARNING("Send %d Bytes!\n", tx_data_len);*/
			for (i = 0; i < tx_data_len; i++)
				SET_SC_TXFIFO(p_this, tx_buff[i]);

			SET_SCCR(p_this, GET_SCCR(p_this) | SC_TX_GO(1));	/* Start Xmit */
		} else {
			SET_SCIRER(p_this,
				   GET_SCIRER(p_this) & ~SC_TXEMPTY_INT);
			p_this->tx_status |= SC_TX_DONE;
			
			LOG_SC_TX_DONE(p_this);
			
			wake_up(&p_this->wq);	/* wakeup queue  */
		}
#else
		p_this->tx_status = SC_TX_DONE;
		wake_up(&p_this->wq);	/* wakeup queue */
#endif
	}
}

/*------------------------------------------------------------------
 * Func : scd_work
 *
 * Desc : scd work routine
 *
 * Parm : p_this : handle of cec
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_work(scd *p_this)
{
	unsigned long status = GET_SCIRSR(p_this) & GET_SCIRER(p_this);

	/*SC_INFO("SC%d - work!!\n", p_this->id); */

	if (status & SC_CPRES_INT) {
		if (scd_card_detect(p_this)) {
			SC_INFO("SC%d - ICC detected!!\n", p_this->id);
		} else {
			scd_set_state(p_this, IFD_FSM_DEACTIVATE);
			SC_INFO("SC%d - ICC removed!!\n", p_this->id);
		}

		p_this->card_status_change = 1;
		wake_up(&p_this->wq);
	}

	switch (p_this->fsm) {
	case IFD_FSM_RESET:
		scd_fsm_reset(p_this);
		break;
	case IFD_FSM_ACTIVE:
		scd_fsm_active(p_this);
		break;
	default:
		break;
	}

	SET_SCIRSR(p_this, status);
}

#ifdef ISR_POLLING
/*------------------------------------------------------------------
 * Func : scd_timer
 *
 * Desc : timer of  scd
 *
 * Parm : arg : input param
 *
 * Retn : IRQ_NONE, IRQ_HANDLED
 *------------------------------------------------------------------*/
static void scd_timer(unsigned long arg)
{
	scd *p_this = (scd *) arg;

	unsigned long event = GET_MIS_ISR(p_this) & p_this->reg.ISR_MASK;

	/* SC_INFO("irq=%08x, sc_isr%d=%08x, ire=%08x, cr=%08x\n",GET_MIS_ISR(p_this), p_this->id, GET_SCIRSR(p_this), GET_SCIRER(p_this), GET_SCCR(p_this)); */

	if (event)
		scd_work(p_this);

	SET_MIS_ISR(p_this, event);

	mod_timer(&p_this->timer, jiffies + ISR_POLLING_INTERVAL);
}

#else

/*------------------------------------------------------------------
 * Func : scd_isr
 *
 * Desc : isr of  scd
 *
 * Parm : p_this : handle of  scd
 *        dev_id : handle of the scd
 *        regs   :
 *
 * Retn : IRQ_NONE, IRQ_HANDLED
 *------------------------------------------------------------------*/
static irqreturn_t scd_isr(int this_irq, void *dev_id)
{
	scd *p_this = (scd *) dev_id;
	unsigned long flag;
	unsigned long event = GET_MIS_ISR(p_this) & p_this->reg.ISR_MASK;

	if (!event)
		return IRQ_NONE;

	spin_lock_irqsave(&p_this->lock, flag);

	SC_INT_DBG("MIS ISR=%08x\n", GET_MIS_ISR(p_this));

	SET_MIS_ISR(p_this, event);

	scd_work(p_this);

	spin_unlock_irqrestore(&p_this->lock, flag);

	return IRQ_HANDLED;
}

#endif

/*------------------------------------------------------------------
 * Func : scd_enable
 *
 * Desc : enable  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_enable(scd *p_this, unsigned char on_off)
{
	int ret = 0;
	if (on_off) {
		if (p_this->fsm == IFD_FSM_DISABLE) {
			ret = scd_set_state(p_this, IFD_FSM_DEACTIVATE);
			msleep(200);	/* fix bug of get card status fail on darwin platform....*/
		}
	} else
		ret = scd_set_state(p_this, IFD_FSM_DISABLE);

	return ret;
}

/*------------------------------------------------------------------
 * Func : scd_set_clock
 *
 * Desc : set clock frequency of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        clk      : clock (in HZ)
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_set_clock(scd *p_this, unsigned long clk)
{
	unsigned long val;
	unsigned long div = SYSTEM_CLK / clk;

	if (clk > MAX_SC_CLK) {
		SC_ERR
		    ("clock %lu out of range, using minimum value to instead %lu\n",
		     (unsigned long)clk, (unsigned long)MAX_SC_CLK);
		clk = MAX_SC_CLK;
	}

	if (clk < MIN_SC_CLK) {
		SC_ERR
		    ("clock %lu out of range, using minimum value to instead %lu\n",
		     (unsigned long)clk, (unsigned long)MIN_SC_CLK);
		clk = MIN_SC_CLK;
	}

	if ((div & 0x1)) // make sure the divider is multiple of 2
	{        
        SC_ERR("clock divider %lu is not multiple of 2, modify to multiple of 2\n", div);
        if ((div>4) && ((div & 0x3)==0x1))	// make sure the value is could be multiple of 4
             div--;
        else
            div++;
	}
	
	// select bast divider : if clock_div is multiple of 4, it is able to support all ETU that is multiple of 8
	// if clock_div is multiple of 2, it is able to support all ETU that is multiple of 16
	p_this->clock_div = ((div & 0x3)==0 && ((div>>2)>1)) ? 4 : 2;	// note : pre_div should be	more than 2
	p_this->pre_clock_div = div / p_this->clock_div;    
	val  = GET_SCFP(p_this) & ~(SC_PRE_CLKDIV_MASK | SC_CLKDIV_MASK);   
	val |= SC_CLKDIV(p_this->clock_div-1);
	val |= SC_PRE_CLKDIV(p_this->pre_clock_div-1);

	SET_SCFP(p_this, val);

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_get_clock
 *
 * Desc : get clock frequency of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        p_clock  : clock (in HZ)
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_get_clock(scd *p_this, unsigned long *p_clock)
{
	*p_clock = SYSTEM_CLK / (p_this->pre_clock_div) / (p_this->clock_div);
	return 0;
}

unsigned int scd_get_buad2_div(unsigned int id)
{
	unsigned int baud_div2[3] = {31, 32, 39};
	return (id<3) ? baud_div2[id]: baud_div2[0];
}

/*------------------------------------------------------------------
 * Func : scd_set_etu
 *
 * Desc : set etu of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        etu      : cycles
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_set_etu(scd *p_this, unsigned long etu)
{
    unsigned long val = 0xFFFFFFFF;     
    unsigned int  div2;
    int i;
	
    SC_INFO("mars_scd_set_etu (%d)\n", etu);
    etu *= p_this->clock_div;
    p_this->baud_div2 = 0;    	
	
    // find best baud_div2
    for (i=0; i<3; i++)
    {
        div2 = scd_get_buad2_div(i);		
        if ((etu % div2) < val)
        {
            p_this->baud_div2 = i;
            val = (etu % div2);
        }
    }

    // determine baud_div1
    p_this->baud_div1 = etu / scd_get_buad2_div(p_this->baud_div2);
    val = GET_SCFP(p_this) & ~SC_BAUDDIV_MASK;            
    val |= SC_BAUDDIV1((p_this->baud_div1-1));
    val |= SC_BAUDDIV2(p_this->baud_div2);	
    
    SC_INFO("ETU = %lu. Baud Div2=%lu (%lu), Div1 = %lu, ClkDiv=%d\n", 
			etu/p_this->clock_div, 
			p_this->baud_div2,
			scd_get_buad2_div(p_this->baud_div2),
			p_this->baud_div1, 
			p_this->clock_div);


	SET_SCFP(p_this, val);
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_get_etu
 *
 * Desc : set etu of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        etu      : cycles
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_get_etu(scd *p_this, unsigned long *p_etu)
{
	*p_etu = (scd_get_buad2_div(p_this->baud_div2) * p_this->baud_div1) / p_this->clock_div;
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_set_guard_interval
 *
 * Desc : set guard interval of icam smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        guard_interval : guard interval in etu
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_set_guard_interval(scd *p_this, unsigned long guard_interval)
{
	if (guard_interval >= 0xFF)
		guard_interval = 0xFE;

	if (guard_interval < 2)
		guard_interval = 2;

	SET_SCPCR(p_this,
		  (GET_SCPCR(p_this) & ~SC_TXGRDT(0xFF)) |
		  SC_TXGRDT(guard_interval-2));
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_get_guard_interval
 *
 * Desc : set guard interval
 *
 * Parm : p_this : handle of  scd
 *        p_guard_interval : guard interval output
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_get_guard_interval(scd *p_this,
				unsigned long *p_guard_interval)
{
	unsigned long guard_time = (GET_SCPCR(p_this) >> 24) & 0xFF;
	*p_guard_interval = (guard_time < 0xFF) ? guard_time+2 : 2;
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_set_parity
 *
 * Desc : set parity of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        parity   : 0 : off,  others on
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_set_parity(scd *p_this, SC_PARITY parity)
{

	switch (parity) {
	case SC_PARITY_NONE:
		p_this->parity = 0;
		break;

	case SC_PARITY_ODD:
	case SC_PARITY_EVEN:
		p_this->parity = 1;
		break;
	default:
		return SC_FAIL;
	}

	if (p_this->parity)
		SET_SCCR(p_this, GET_SCCR(p_this) | SC_PS(p_this->parity));
	else
		SET_SCCR(p_this, GET_SCCR(p_this) & ~SC_PS(p_this->parity));

	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_get_parity
 *
 * Desc : get parity setting of  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        p_parity   : 0 : off,  others on
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_get_parity(scd *p_this, SC_PARITY *p_parity)
{
	*p_parity = (p_this->parity) ? SC_PARITY_EVEN : SC_PARITY_NONE;
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_activate
 *
 * Desc : activate an ICC
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_activate(scd *p_this)
{
	switch (p_this->fsm) {
	case IFD_FSM_DISABLE:
		SC_ERR("activate ICC failed, please enable IFD first\n");
		return SC_ERR_IFD_DISABLED;

	case IFD_FSM_DEACTIVATE:

		if (scd_reset(p_this) == 0) {
			SC_INFO("activate ICC success\n");
			return SC_SUCCESS;
		} else {
			SC_ERR("activate ICC failed\n");
			return SC_ERR_NO_ICC;
		}
		break;

	case IFD_FSM_RESET:
		SC_INFO("ICC has is reseting\n");
		return SC_SUCCESS;

	case IFD_FSM_ACTIVE:
		SC_INFO("ICC has been activated already\n");
		return SC_SUCCESS;

	default:
		SC_ERR("activate ICC failed, unknown state\n");
		return SC_FAIL;
	}
}

/*------------------------------------------------------------------
 * Func : scd_deactivate
 *
 * Desc : deactivate an ICC
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_deactivate(scd *p_this)
{
	if (p_this->fsm != IFD_FSM_DISABLE) {
		scd_set_state(p_this, IFD_FSM_DISABLE);
		scd_set_state(p_this, IFD_FSM_DEACTIVATE);
	}
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_reset
 *
 * Desc : reset  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_reset(scd *p_this)
{
	if (scd_set_state(p_this, IFD_FSM_RESET))
		return SC_FAIL;

	wait_event_interruptible_timeout(p_this->wq, p_this->atr.length > 0, (HZ >> 1));	/* wait 500 ms */

	if (p_this->atr.length <= 0) {
		SC_ERR("SC%d - Reset ICC failed, wait ATR timeout\n",
			   p_this->id);
		scd_set_state(p_this, IFD_FSM_DEACTIVATE);
		return SC_ERR_ATR_TIMEOUT;
	}

	wait_event_interruptible_timeout(p_this->wq, p_this->fsm != IFD_FSM_RESET, (HZ >> 1));	/*  wait 500 ms  */

	if (p_this->fsm != IFD_FSM_ACTIVE) {
		SC_ERR("SC%d - Reset ICC failed\n", p_this->id);
		scd_set_state(p_this, IFD_FSM_DEACTIVATE);
		return SC_ERR_ATR_TIMEOUT;
	}

	SC_INFO("SC%d - Reset ICC Complete, atr_len=%d\n", p_this->id,
		p_this->atr.length);

	return SC_SUCCESS;
}

/*------------------------------------------------------------------
 * Func : scd_get_atr
 *
 * Desc : smart card interface
 *
 * Parm : p_this   : handle of  scd
 *        p_atr    : atr output buffer
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_get_atr(scd *p_this, scd_atr *p_atr)
{
	if (p_this->fsm != IFD_FSM_ACTIVE) {
		p_atr->length = -1;
		return -1;
	}

	p_atr->length = p_this->atr.length;
	memcpy(p_atr->data, p_this->atr.data, p_this->atr.length);
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_card_detect
 *
 * Desc : get card status
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : no icc exists, others : icc exists
 *------------------------------------------------------------------*/
int scd_card_detect(scd *p_this)
{
	int try_cnt = 0;

	while (try_cnt < 3) {
		if ((GET_SCIRSR(p_this) & SC_PRES)) {
			if (try_cnt) {
				SC_WARNING
				    ("scd_card_detect with retry = %d\n",
				     try_cnt);
			}

			return 1;
		}
		ndelay(5);
		try_cnt++;
	}
	return 0;
}

unsigned int g_resume_status = 0;

/*------------------------------------------------------------------
 * Func : scd_get_card_status
 *
 * Desc : get card status
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : no icc exists, others : icc exists
 *------------------------------------------------------------------*/
int scd_get_card_status(scd *p_this)
{
	if(g_resume_status<3) {
		g_resume_status ++;
		return SC_CARD_REMOVED;
	}
	else {
		switch (p_this->fsm) {
		case IFD_FSM_DISABLE:
			return SC_CARD_REMOVED;
		case IFD_FSM_DEACTIVATE:
			return scd_card_detect(p_this) ? SC_CARD_DEACTIVATE :
			    SC_CARD_REMOVED;
		case IFD_FSM_RESET:
			return SC_CARD_RESET;
		case IFD_FSM_ACTIVE:
			return SC_CARD_ACTIVATE;
		default:
			return SC_CARD_UNKNOWN;
		}
	}
}

/*------------------------------------------------------------------
 * Func : scd_poll_card_status
 *
 * Desc : poll card status change
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0 : for success, others : fail
 *------------------------------------------------------------------*/
int scd_poll_card_status(scd *p_this)
{
	wait_event_interruptible(p_this->wq, p_this->card_status_change);
	p_this->card_status_change = 0;
	return scd_get_card_status(p_this);
}

/*------------------------------------------------------------------
 * Func : scd_xmit
 *
 * Desc : xmit data via smart card bus
 *
 * Parm : p_this   : handle of  scd
 *        scb      : data to be xmit
 *
 * Retn : SC_SUCCESS / SC_FAIL
 *------------------------------------------------------------------*/
 extern unsigned char apdu_onoff;
int scd_xmit(scd *p_this, unsigned char *p_data, unsigned int len)
{
	unsigned char id = p_this->id;
	char str_temp[390]={0};
#ifdef USE_TX_FIFO
	unsigned long flag;
	unsigned char tx_buff[40];
	unsigned char tx_data_len;
#endif
	int i;
       int ret;
    
	if (scd_card_detect(p_this) == 0)
		return SC_ERR_NO_ICC;

	if (p_this->fsm != IFD_FSM_ACTIVE)
		return SC_ERR_ICC_DEACTIVATE;
	
	SET_SCCR(p_this, GET_SCCR(p_this) | SC_FIFO_RST(1));
	SET_SCIRER(p_this, GET_SCIRER(p_this)&(~SC_RCV_INT));	/* disable Rx interrupt */
	
	kfifo_reset(&p_this->rx_fifo);

	if(apdu_onoff)
	{      for(i=0;i<len;i++)
          {
              sprintf(str_temp+3*i, "%2.2x ",p_data[i]);
             if(i==len-1)
              sprintf(str_temp+3*i+2, "\0");

          }
	   SC_PRINT_AWAYS("scd_tx=%s\n",str_temp);

	}

#ifdef USE_TX_FIFO

	spin_lock_irqsave(&p_this->lock, flag);

	kfifo_reset(&p_this->tx_fifo);

	if (kfifo_in(&p_this->tx_fifo, p_data, len) < len) {
		SC_ERR("[SC%d] xmit data failed, tx fifo overflow\n", id);
		spin_unlock_irqrestore(&p_this->lock, flag);
		return SC_FAIL;
	}
	
	LOG_SC_TX_ENTER(p_this);
	
	/* load tx data */
	tx_data_len = kfifo_out(&p_this->tx_fifo, tx_buff, sizeof(tx_buff));

	for (i = 0; i < tx_data_len; i++)
		SET_SC_TXFIFO(p_this, tx_buff[i]);

	p_this->tx_status = 0;

	SET_SCIRSR(p_this, SC_TXEMPTY_INT);	/* clear tx empty...*/

	SET_SCIRER(p_this, GET_SCIRER(p_this) | SC_TXEMPTY_INT);	/* enable Tx empty interrupt */

	spin_unlock_irqrestore(&p_this->lock, flag);
	
	SET_SCCR(p_this, GET_SCCR(p_this) | SC_TX_GO(1));	/* Start Xmit*/
	
	LOG_SC_TX_GO(p_this);
	
#ifdef CONTINIOUS_TX_DATA_LOADING	

	while(kfifo_len(&p_this->tx_fifo)) {
	    
		mdelay(1);
		
		spin_lock_irqsave(&p_this->lock, flag);
	  
		// load data to fifo ...
		while ((rtd_inl(p_this->reg.TXFIFO) & 0x100)==0 && 
				kfifo_len(&p_this->tx_fifo)) {

			if ((p_this->tx_status & SC_TX_ABORT))
				break;

			kfifo_out(&p_this->tx_fifo, tx_buff, 1);
			SET_SC_TXFIFO(p_this, tx_buff[0]);
		}

		spin_unlock_irqrestore(&p_this->lock, flag);
	}
#endif	

	wait_event_interruptible_timeout(p_this->wq, (p_this->tx_status & SC_TX_DONE), HZ << 1);	/* max tx timeout 2sec */

    LOG_SC_TX_EXIT(p_this);

	SET_SCIRER(p_this, GET_SCIRER(p_this) & ~SC_TXEMPTY_INT|SC_RCV_INT);	/* disable Tx empty interrupt,enable Rx interrupt*/

	SET_SCCR(p_this, GET_SCCR(p_this) & ~SC_TX_GO(1));	/* Stop Xmit*/

	if ((p_this->tx_status & SC_TX_DONE) == 0) {
		SC_ERR("[SC%d] xmit data failed, tx timeout\n", id);
		dump_sc_tx_log(p_this,1);
		return SC_FAIL;
	}

	if ((p_this->tx_status & SC_TX_ABORT)) {
		SC_ERR("TX Aborted\n");
		dump_sc_tx_log(p_this,1);
		return SC_ERR_USR_ABORT;
	}
	
	dump_sc_tx_log(p_this,0);
	
#else
	while (len) {
		unsigned char tx_len = (len > 40) ? 40 : len;

		SET_SCIRSR(p_this, SC_TXEMPTY_INT);	/* clear tx empty...*/

		for (i = 0; i < tx_len; i++)
			SET_SC_TXFIFO(p_this, p_data[i]);

		len -= tx_len;
		p_data += tx_len;

		p_this->tx_status = 0;
		SET_SCIRER(p_this, GET_SCIRER(p_this) | SC_TXEMPTY_INT);	/* Enable Tx empty interrupt */
		wmb();
		SET_SCCR(p_this, GET_SCCR(p_this) | SC_TX_GO(1));	/* Start Xmit*/
		wait_event_interruptible_timeout(p_this->wq,
						 (p_this->
						  tx_status & SC_TX_DONE),
						 HZ >> 1);
		SET_SCIRER(p_this, GET_SCIRER(p_this) & ~SC_TXEMPTY_INT);	/* disable Tx empty interrupt */
		/*udelay(1000);*/                      /*don't disable it, or you'll got wrong data in next transmission*/
	}
#endif
	return SC_SUCCESS;
}

/*------------------------------------------------------------------
 * Func : scd_read
 *
 * Desc : read data via smart card bus
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : sc_buff
 *------------------------------------------------------------------*/
int scd_read(scd *p_this, unsigned char *data, unsigned int len,
		  unsigned long timeout)
{
       int ret=0 ;
	int i;
	char str_temp[390]={0};
	if (scd_card_detect(p_this) == 0) {
		SC_ERR("Read data error scd_card_detect = 0\n");
		return SC_ERR_NO_ICC;
	}

	p_this->rx_status = 0;

	wait_event_interruptible_timeout(p_this->wq,
					 kfifo_len(&p_this->rx_fifo) >= len
					 || (p_this->fsm != IFD_FSM_ACTIVE)
					 || (p_this->rx_status & SC_RX_ABORT),
					 msecs_to_jiffies(timeout));

	if (p_this->fsm != IFD_FSM_ACTIVE) {
		SC_ERR("Read data error FSM(%d)!=ACTIVATE(%d)\n",
			   p_this->fsm, IFD_FSM_ACTIVE);
		return SC_ERR_ICC_DEACTIVATE;
	}

	if ((p_this->rx_status & SC_RX_ABORT)) {
		kfifo_out_locked(&p_this->rx_fifo, data, len, &p_this->rx_fifo_lock);	/* read out data that already received*/
		SC_ERR("Read Aborted\n");
		return SC_ERR_USR_ABORT;
	}

	ret=kfifo_out_locked(&p_this->rx_fifo, data, len,
				&p_this->rx_fifo_lock);
	if(apdu_onoff&&ret)
	{     
	  for(i=0;i<len;i++)
          {
              sprintf(str_temp+3*i, "%2.2x ",data[i]);
             if(i==len-1)
              sprintf(str_temp+3*i+2, "\0");

          }
	   SC_PRINT_AWAYS("scd_rx=%s\n",str_temp);

	}
	return ret;
}

/*------------------------------------------------------------------
 * Func : scd_abort
 *
 * Desc : abort IO command
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int scd_abort(scd *p_this)
{
	p_this->tx_status |= SC_TX_ABORT;	/* abort TX */
	p_this->rx_status |= SC_RX_ABORT;	/* abort RX */
	wake_up(&p_this->wq);	/* wakeup queue */
	return 0;
}

/*------------------------------------------------------------------
 * Func : scd_load_gpio_config
 *
 * Desc : Load Gpio Config
 *
 * Parm : p_this   : handle of  scd
 *
 * Retn : sc_buff
 *------------------------------------------------------------------*/
static void scd_load_gpio_config(scd *p_this)
{
	unsigned long long val = 0;
	int ret = 0;

#ifdef CONFIG_REALTEK_PCBMGR
	char name[16];
	sprintf(name, "SC%d_CFG", p_this->id);
	ret = pcb_mgr_get_enum_info_byname(name, &val);
	if(ret != 0)
	{
		SC_ERR("Get PCB Parameter fail!\n");
		return;
	}
#else
	#if CONFIG_ARCH_RTK284X
	/* PinMux for RTD284X BGA Demo Board    */
	rtd_outl(0xb80008d8,(rtd_inl(0xb80008d8) & ~(0x3)));			/* Pin_Mux_Ctrl1   SC_CD_src0 */
	rtd_outl(0xb80008dc,(rtd_inl(0xb80008dc) & ~(0x3 << 28)));		/* Pin_Mux_Ctrl2   sc_data_src0_in */
	rtd_outl(0xb8000820, rtd_inl(0xb8000820) | (0xF << 12));	/* PWR SEL : GPIO 37*/
	rtd_outl(0xb8000890, rtd_inl(0xb8000890) | (0xF << 28));	/* CMD VCC : GPIO 101 */
	rtd_outl(0xb80008ac, (rtd_inl(0xb80008ac) & ~(0xF << 28)) | (0xC<< 28));	/* IO    */
	rtd_outl(0xb80008ac, (rtd_inl(0xb80008ac) & ~(0xF << 20)) | (0xC<< 20));	/* RST    */
	rtd_outl(0xb80008ac, (rtd_inl(0xb80008ac) & ~(0xF << 12)) | (0xC<< 12));	/* CLK    */
	rtd_outl(0xb80008ac, (rtd_inl(0xb80008ac) & ~(0xF << 4)) | (0xC << 4));	/* CD*/
	val = 0x8C6525;
	#endif
	
	#ifdef CONFIG_MACH_RTK_298x
	/* PinMux for RTD298X BGA Demo Board    */
	rtd_outl(0xb8000878, rtd_inl(0xb8000878) | (0x1F << 9));	/* CMD VCC : GPIO 173 */
	rtd_outl(0xb8000860, rtd_inl(0xb8000860) | (0x1F << 18));	/* PWR SEL : GPIO 96*/
	rtd_outl(0xb800085C, (rtd_inl(0xb800085C) & ~(0x1F << 18)) | (0x6 << 18));	/* CD */
	rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0x1F << 27)) | (0x6 << 27));	/* RST*/
	rtd_outl(0xb800085C, (rtd_inl(0xb800085C) & ~(0x1F << 9)) | (0x6 << 9));	/* CLK */
	rtd_outl(0xb800085C, (rtd_inl(0xb800085C) & ~(0x1F << 27)) | (0x6 << 27));	/*  IO    */
	val = 0x8CAD60;
	#endif



	#ifdef CONFIG_MACH_RTK_294X
	/* PinMux for RTD294X BGA Demo Board */
	rtd_outl(0xb8000848, rtd_inl(0xb8000848) | (0xF << 4));	/* CMD VCC : MISC GPIO 73  */
	rtd_outl(0xb8000848, rtd_inl(0xb8000848) | (0xF << 12));	/* PWR SEL : MISC GPIO 72 */
	rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF << 28)) | (0x8 << 28));	/* CD */
	rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF << 24)) | (0x8 << 24));	/* RST*/
	rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF << 24)) | (0x8 << 24));	/* CLK */
	rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF << 28)) | (0x8 << 28));	/* IO */
	val = 0x8C4948;
	#endif


	#if CONFIG_ARCH_RTKS2B
	/* PinMux for S2B BGA Demo Board */
	rtd_outl(0xb80008a0, rtd_inl(0xb80008a0) & ~(0x7) | (0x6));    /*according to GPIO_bit103 add for sc*/
	rtd_outl(0xb8060204, rtd_inl(0xb8060204) | (0xF << 28));    /* PWR SEL : ISO_MIS_GPIO_bit4   */
	rtd_outl(0xb8000844, rtd_inl(0xb8000844) | (0xF << 28));    /* CMD VCC : MIS_GPIO_bit66  */
    rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF << 28)) | (0x8 << 28));   /* CD */
    rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF << 24)) | (0x8 << 24));   /* RST*/
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF << 24)) | (0x8 << 24));   /* CLK */
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF << 28)) | (0x8 << 28));   /* IO */
    val = 0x8A4204;
	#endif

  /*#ifdef CONFIG_MACH_RTK_299S*/
	#if defined(CONFIG_ARCH_RTK299S) || defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK293x)
	/* PinMux for RTD299S BGA Demo Board         */
	rtd_outl(0xb8000810,  rtd_inl(0xb8000810) |  (0xF<<20));  /* CMD VCC : MISC GPIO 17*/
	rtd_outl(0xb8060208,  rtd_inl(0xb8060208) |  (0xF<<4));  /* PWR SEL : ST GPIO 11*/
	rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<<20)) | (0x8<<20)); /* CD */
	rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<<4)) | (0x8<<4)); /* RST */
	rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<28)) | (0x8<<28)); /* CLK */
	rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<<12)) | (0x8<<12)); /* IO */
	val = 0x8E110B;
	#endif

	#ifdef CONFIG_MACH_MERLIN2
	  /* PinMux for Merlin2 BGA Demo Board		   */
	rtd_outl(0xb8000840, rtd_inl(0xb8000840) |  (0xF<<4)); /* CMD VCC : MISC GPIO 70*/
	rtd_outl(0xb8000848, rtd_inl(0xb8000848) |  (0xF<<20));  /* PWR SEL : MISC GPIO 75*/
	rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<4)) | (0x8<<4)); /* CD */
	rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<20)) | (0x8<<20)); /* RST */
	rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<12)) | (0x8<<12)); /* CLK */
	rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<28)) | (0x8<<28)); /* IO */
	val = 0x88464b;
  #endif

#endif
		/**************************************
		* SCx Command format
		**************************************
		D31:24  : --
		D23     : cmd_vcc_en        (0: no cmd_vcc_gpio, 1: with cmd_vcc_gpio)
		D22     : cmd_vcc_polarity  (0: negative, 1: positive)
		D21     : cmd_vcc_gpio_type (0: MISC, 1: ISO)
		D20     : --
		D19     : pwr_sel_en        (0: no cmd_vcc_gpio, 1: with cmd_vcc_gpio)
		D18     : pwr_sel_polarity  (0: negative, 1: positive)
		D17     : pwr_sel_gpio_type (0: MISC, 1: ISO)
		D16     : --
		D15:8   : cmd_vcc_gpio
		D7:0    : pwr_sel_gpio
		**************************************/
	p_this->cmd_vcc_en = (val >> 23) & 0x1;
	p_this->cmd_vcc_polarity = (val >> 22) & 0x1;
	p_this->pin_cmd_vcc =
	    rtk_gpio_id(((val >> 21) & 0x1) ? ISO_GPIO : MIS_GPIO,
			  (val >> 8) & 0xFF);

	p_this->pwr_sel_en = (val >> 19) & 0x1;
	p_this->pwr_sel_polarity = (val >> 18) & 0x1;
	p_this->pin_pwr_sel =
	    rtk_gpio_id(((val >> 17) & 0x1) ? ISO_GPIO : MIS_GPIO,
			  (val & 0xFF));

	SC_INFO
	    ("SC%d - cmd_vcc(en=%d, polarity=%d, pin=%s_GPIO[%d]), pwr_sel(en=%d,polarity=%d,pin=%s_GPIO[%d])\n",
	     p_this->id, p_this->cmd_vcc_en, p_this->cmd_vcc_polarity,
	     gpio_type(gpio_group(p_this->pin_cmd_vcc)),
	     gpio_idx(p_this->pin_cmd_vcc), p_this->pwr_sel_en,
	     p_this->pwr_sel_polarity,
	     gpio_type(gpio_group(p_this->pin_pwr_sel)),
	     gpio_idx(p_this->pin_pwr_sel));
}



 unsigned long long scd_interface_value(scd *p_this)
{
       unsigned long  long val = 0;
	char name[16];
	scd this;
	sprintf(name, "SC%d_CFG", p_this->id);
	pcb_mgr_get_enum_info_byname(name, &val);
       this.cmd_vcc_en = (val >> 23) & 0x1;
	this.cmd_vcc_polarity = (val >> 22) & 0x1;
	this.pin_cmd_vcc =
	    rtk_gpio_id(((val >> 21) & 0x1) ? ISO_GPIO : MIS_GPIO,
			  (val >> 8) & 0xFF);

	this.pwr_sel_en = (val >> 19) & 0x1;
	this.pwr_sel_polarity = (val >> 18) & 0x1;
	this.pin_pwr_sel =
	    rtk_gpio_id(((val >> 17) & 0x1) ? ISO_GPIO : MIS_GPIO,
			  (val & 0xFF));

	SC_PRINT_AWAYS
	    (" \n SC%d : \n\n        interface value=%llx\n\n        cmd_vcc(en=%d, polarity=%d, pin=%s_GPIO[%d] ,pin_dir=%d(0:in,1:out) ,pin_value=%d)\n\n        pwr_sel(en=%d,polarity=%d,pin=%s_GPIO[%d] ,pin_dir=%d(0:in,1:out) ,pin_value=%d ) \n\n        reg(0xb8000858):0x%8x\n\n",
	     p_this->id,val, this.cmd_vcc_en, this.cmd_vcc_polarity,
	     gpio_type(gpio_group(this.pin_cmd_vcc)),
	     gpio_idx(this.pin_cmd_vcc), this.pwr_sel_en,rtk_gpio_get_dir(p_this->pin_cmd_vcc),rtk_gpio_output_get(p_this->pin_cmd_vcc),
	     this.pwr_sel_polarity,
	     gpio_type(gpio_group(this.pin_pwr_sel)),
	     gpio_idx(this.pin_pwr_sel),rtk_gpio_get_dir(p_this->pin_cmd_vcc),rtk_gpio_output_get(p_this->pin_pwr_sel),rtd_inl(0xb8000858));

	return val;
}

static unsigned int sc_reset_rdy;

/*------------------------------------------------------------------
 * Func : scd_open
 *
 * Desc : open a  scd device
 *
 * Parm : id  : channel id
 *
 * Retn : handle of  scd
 *------------------------------------------------------------------*/
scd *scd_open(unsigned char id)
{
	scd *p_this;

	if (id >= MAX_IFD_CNT) {
		SC_ERR("scd : open %s scd failed, invalid id - %d\n",
			   IFD_MODOLE, id);
		return NULL;
	}

	p_this = (scd *) kmalloc(sizeof(scd), GFP_KERNEL);

	if (p_this) {
		memset(p_this, 0, sizeof(scd));

		p_this->id = id;
		p_this->fsm = IFD_FSM_UNKNOWN;
		p_this->atr.length = -1;
		p_this->reg = SCReg[p_this->id];

		if (kfifo_alloc(&p_this->rx_fifo, 1024, GFP_KERNEL) < 0) {
			SC_ERR
			    ("scd : open %s scd(%d) failed, create rx fifo failed\n",
			     IFD_MODOLE, id);
			kfree(p_this);
			return NULL;
		}

		if (kfifo_alloc(&p_this->tx_fifo, 1024, GFP_KERNEL) < 0) {
			SC_ERR
			    ("scd : open %s scd(%d) failed, create tx fifo failed\n",
			     IFD_MODOLE, id);
			kfifo_free(&p_this->rx_fifo);
			kfree(p_this);
			return NULL;
		}

		spin_lock_init(&p_this->lock);
		spin_lock_init(&p_this->rx_fifo_lock);
		init_waitqueue_head(&p_this->wq);

		if (sc_reset_rdy++ == 0) {
			CRT_CLK_OnOff(SMC, CLK_ON, NULL);
		}

		/*--- configurations ---*/
		//p_this->clock_div = 1;
		//p_this->pre_clock_div = (unsigned char)(SYSTEM_CLK / 4000000);
		//p_this->baud_div1 = 12;	/* default etu = 372 = 31 * 12 */
		//p_this->baud_div2 = 31;
		scd_set_clock(p_this, 4000000);
		scd_set_etu(p_this, 372);              
		p_this->parity = 1;
		p_this->vcc_5v = 1;

		scd_load_gpio_config(p_this);

		if (p_this->cmd_vcc_en) {
			rtk_gpio_output(p_this->pin_cmd_vcc, (p_this->cmd_vcc_polarity) ? 0 : 1);	/* power off*/
			rtk_gpio_set_dir(p_this->pin_cmd_vcc, 1);	/* set power ping to output mode */
		}

		if (p_this->pwr_sel_en) {
			rtk_gpio_output(p_this->pin_pwr_sel, (p_this->pwr_sel_polarity) ? 0 : 1);	/* 3.3v*/
			rtk_gpio_set_dir(p_this->pin_pwr_sel, 1);	/* set power ping to output mode*/
		}
		/* Set All Register to the initial value */
		SET_SCFP(p_this, SC_CLK_EN(1) | SC_CLKDIV((p_this->clock_div - 1)) | SC_BAUDDIV2(p_this->baud_div2) |
			 SC_BAUDDIV1((p_this->baud_div1 - 1)) |
			 SC_PRE_CLKDIV((p_this->pre_clock_div - 1)));

		SET_SCCR(p_this, SC_FIFO_RST(1) |
			 SC_SCEN(1) | SC_AUTO_ATR(1) | SC_CONV(0) | SC_PS(0));

		SET_SCPCR(p_this, SC_TXGRDT(0) |
			  SC_CWI(0) |
			  SC_BWI(0) |
			  SC_WWI(0) |
			  SC_BGT(0x16) |
			  SC_EDC_EN(0) |
			  SC_CRC(0) |
			  SC_PROTOCOL_T(0) | SC_T0RTY(0) | SC_T0RTY_CNT(0));

		SET_SCIRER(p_this, 0);

		SET_SCIRSR(p_this, 0xFFFFFFFF);

		/* Set Interrupt or IRQ*/

#ifdef ISR_POLLING
		init_timer(&p_this->timer);
		p_this->timer.data = (unsigned long)p_this;
		p_this->timer.function = scd_timer;
		p_this->timer.expires = jiffies + ISR_POLLING_INTERVAL;
		add_timer(&p_this->timer);	/*register timer*/
#else
		SC_INFO("Request IRQ #%d\n", MISC_IRQ);

		if (request_irq
		    (MISC_IRQ, scd_isr, SA_SHIRQ, "REALTEK SCD",
		     (void *)p_this) < 0) {
			SC_ERR
			    ("scd : open %s scd failed, unable to request irq#%d\n",
			     IFD_MODOLE, MISC_IRQ);
			kfifo_free(&p_this->tx_fifo);
			kfifo_free(&p_this->rx_fifo);
			kfree(p_this);
			return NULL;
		}
#endif

		scd_set_state(p_this, IFD_FSM_DISABLE);
	} else
		SC_ERR("scd : open scd failed, out of memory\n");

	return p_this;
}

/*------------------------------------------------------------------
 * Func : scd_close
 *
 * Desc : close a  scd device
 *
 * Parm : p_this  :  scd to be close
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void scd_close(scd *p_this)
{
#ifdef ISR_POLLING
	del_timer(&p_this->timer);	/* register timer*/
#else
	free_irq(MISC_IRQ, p_this);
#endif

	kfifo_free(&p_this->rx_fifo);
	kfifo_free(&p_this->tx_fifo);
	scd_set_state(p_this, IFD_FSM_DISABLE);
	wake_up(&p_this->wq);
	kfree(p_this);
}

/*------------------------------------------------------------------
 * Func : scd_suspend
 *
 * Desc : suspend  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *------------------------------------------------------------------*/
int scd_suspend(scd *p_this)
{

	scd_deactivate(p_this);

	CRT_CLK_OnOff(SMC, CLK_OFF, NULL);
	return 0;
}


/*------------------------------------------------------------------
 * Func : scd_resume
 *
 * Desc : resume  smart card interface
 *
 * Parm : p_this   : handle of  scd
 *------------------------------------------------------------------*/
int scd_resume(scd *p_this)
{
	g_resume_status = 0;

	CRT_CLK_OnOff(SMC, CLK_ON, NULL);
	/*set GPIO*/
	scd_load_gpio_config(p_this);
	if (p_this->cmd_vcc_en) {
	rtk_gpio_output(p_this->pin_cmd_vcc, (p_this->cmd_vcc_polarity) ? 0 : 1);	/* power off*/
	rtk_gpio_set_dir(p_this->pin_cmd_vcc, 1);	/* set power ping to output mode */
	}

	if (p_this->pwr_sel_en) {
	rtk_gpio_output(p_this->pin_pwr_sel, (p_this->pwr_sel_polarity) ? 0 : 1);	/* Force Power Pin to 3.3v */
	rtk_gpio_set_dir(p_this->pin_pwr_sel, 1);	/* set power ping to output mode*/
	}

	/* Set All Register to the initial value */
	SET_SCFP(p_this, SC_CLK_EN(1) | SC_CLKDIV((p_this->clock_div - 1)) | SC_BAUDDIV2(p_this->baud_div2) |
	SC_BAUDDIV1((p_this->baud_div1 - 1)) |
	SC_PRE_CLKDIV((p_this->pre_clock_div - 1)));

	SET_SCCR(p_this, SC_FIFO_RST(1) |
	SC_SCEN(1) | SC_AUTO_ATR(1) | SC_CONV(0) | SC_PS(0));

	SET_SCPCR(p_this, SC_TXGRDT(0) |
	SC_CWI(0) |
	SC_BWI(0) |
	SC_WWI(0) |
	SC_BGT(0x16) |
	SC_EDC_EN(0) |
	SC_CRC(0) |
	SC_PROTOCOL_T(0) | SC_T0RTY(0) | SC_T0RTY_CNT(0));

	SET_SCIRER(p_this, 0);

	SET_SCIRSR(p_this, 0xFFFFFFFF);

	scd_deactivate(p_this);


	return 0;
}
