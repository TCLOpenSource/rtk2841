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
#include <rtk_kdriver/rtk_diseqc.h>
#include <rbus/pll_reg_reg.h>
#include "rtk_diseqc_adapter.h"


#ifdef CONFIG_ARM64
	extern u32 gic_irq_find_mapping(u32 hwirq);
	#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		gic_irq_find_mapping(hwirq)
#else
	#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		(hwirq)
#endif

#define SA_INTERRUPT    0
#define SA_SHIRQ        IRQF_SHARED

static rtk_diseqc m_diseqc;
static unsigned long rtk_diseqc_retry_num = 5;


diseqc_msleep_interruptible(unsigned long ms)
{
	msleep_interruptible(ms);
}

void diseqc_msleep(unsigned long ms)
{
	udelay(ms * 1000);
}

void diseqc_usleep(unsigned long us)
{
	udelay(us);
}

int RTK_SetEnvelopMode(unsigned int Env_en)
{
	if(diseqc_set_envelop_mode(Env_en) < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetEnvelopMode);

int RTK_SetContinue22kOnOff(unsigned int Diseqc22kOnOff)
{
	if(diseqc_set_continue_22k_on_off(Diseqc22kOnOff) < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetContinue22kOnOff);

int RTK_SetDiseqcCmd(unsigned int DataLength,unsigned char *Data)
{
	if(diseqc_set_diseqc_cmd(DataLength,Data) < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetDiseqcCmd);

int RTK_SetUnModToneBurst(void)
{
	if(diseqc_set_unmod_tone_burst() < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetUnModToneBurst);

int RTK_SetModToneBurst(void)
{
	if(diseqc_set_mod_tone_burst() < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetModToneBurst);

int RTK_SetToneBurst(TONE_MODE mode)
{
	if(diseqc_set_tone_burst(mode) < 0)
		return FAIL;
	else
		return SUCCESS;
}
EXPORT_SYMBOL(RTK_SetToneBurst);

//Support Modulated tone burst,un-modulated tone burst,Diseqc message mode
static int diseqc_wait_tx_buffer_complete(int timeout)
{
	unsigned long start = jiffies;

	diseqc_info("%s\n", __func__);

	while (!(read_reg32(DSCU_INTR) & TX_DONE_INT_MASK )) {
		if (jiffies - start > timeout) {
			diseqc_warn("%s: timeout!!\n", __func__);
			return -ETIMEDOUT;
		}
		diseqc_msleep(10);
	}
	return 0;
}

//Only for continuous mode
static int diseqc_wait_tx_message_complete(int timeout)
{
	unsigned long start = jiffies;

	diseqc_info("%s\n", __func__);

	while (!(read_reg32(DSCU_INTR) & TX_MSG_DONE_INT_MASK )) {
		if (jiffies - start > timeout) {
			diseqc_warn("%s: timeout!!\n", __func__);
			return -ETIMEDOUT;
		}   
	    diseqc_msleep(10);
	}
	return 0;
}
/*------------------------------------------------------------------
 t Func : rtd284x_diseqc_isr
 *
 * Desc : isr of rtd284x diseqc
 *
 * Parm : p_this : handle of rtd284x diseqc
 *        dev_id : handle of the rtd284x_diseqc
 *
 * Retn : IRQ_NONE, IRQ_HANDLED
 *------------------------------------------------------------------*/
static
irqreturn_t rtd284x_diseqc_isr(int this_irq, void *dev_id)
{
	rtk_diseqc *p_this = (rtk_diseqc *) dev_id;
	irqreturn_t ret = IRQ_NONE;
	
	unsigned long interrupt_event = read_reg32(DSCU_INTR);

	if(interrupt_event & TX_MSG_DONE_INT_MASK)
	{
		diseqc_info("TX Message completed\n");
	}
	else if(interrupt_event & TX_DONE_INT_MASK)
	{
		diseqc_info("TX Buffer completed\n");
	}
	else if(interrupt_event & RX_FULL_INT_MASK)
	{
		diseqc_info("RX Buffer Full\n");	
	}

#if 0
	if (read_reg32(CEC_TXCR0) & TX_INT) {
		rtd299x_cec_tx_work(&p_this->xmit.work.work);
		ret = IRQ_HANDLED;
	}

	if (read_reg32(CEC_RXCR0) & RX_INT) {
		rtd299x_cec_rx_work(&p_this->rcv.work.work);
		ret = IRQ_HANDLED;
	}
#endif

	return ret;
}

static void diseqc_dscu_control_initial(void)
{
	diseqc_info("%s\n", __func__);

	CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);        // enable clock    
	rtd_maskl(DSCU_CTL, ~INT_EN_MASK, INT_EN(1));//DSCU interrupt control
}

static void diseqc_dscu_interrupt_enable(void)
{
	diseqc_info("%s\n", __func__);
	rtd_maskl(DSCU_INTR_ENA, ~TO_INT_ENA_MASK, TO_INT_ENA);//Time out check interrupt
	rtd_maskl(DSCU_INTR_ENA, ~TX_MSG_DONE_ENA_MASK, TX_MSG_DONE_ENA);//Transmit message complete interrrupt control
	rtd_maskl(DSCU_INTR_ENA, ~TX_DONE_ENA_MASK, TX_DONE_ENA);//Transmit buffer complete interrupt control
	rtd_maskl(DSCU_INTR_ENA, ~RX_FULL_ENA_MASK, RX_FULL_ENA);//Receive buffer full interrupt control
	rtd_maskl(DSCU_INTR_ENA, ~EORM_ENA_MASK, EORM_ENA);//End of receivedd message interrupt control
	rtd_maskl(DSCU_INTR_ENA, ~INCOMING_ENA_MASK, INCOMING_ENA);//Incoming-data interrupt control
}

/*------------------------------------------------------------------
 * Func : rtd299x_diseqc_init
 *
 * Desc : init a rtd299x diseqc adapter
 *
 * Parm : N/A
 *
 * Retn : handle of diseqc module
 *------------------------------------------------------------------*/
int rtk_diseqc_init(rtk_diseqc *p_this)
{
	diseqc_data_buff *ddb = NULL;
	int i;

	if (!p_this->status.init) {
		diseqc_info("Open %s Diseqc\n", DISEQC_MODEL_NAME);

		spin_lock_init(&p_this->lock);
		p_this->xmit.state = DISEQC_IDEL;
		p_this->xmit.ddb = NULL;
		p_this->xmit.timeout = 0;

		p_this->rcv.state = DISEQC_IDEL;
		p_this->rcv.ddb = NULL;
		init_waitqueue_head(&p_this->rcv.wq);

		ddb_queue_head_init(&p_this->tx_queue);
		ddb_queue_head_init(&p_this->rx_queue);
		ddb_queue_head_init(&p_this->rx_free_queue);

		CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);        // enable clock   

		diseqc_dscu_control_initial();
		diseqc_dscu_interrupt_enable();
		p_this->status.init = 1;
	}

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_uninit
 *
 * Desc : uninit a rtk diseqc adapter
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void rtk_diseqc_uninit(rtk_diseqc *p_this)
{
	diseqc_info("%s diseqcclosed\n", DISEQC_MODEL_NAME);
}

/*------------------------------------------------------------------
 * Func : rtd299x_cec_suspend
 *
 * Desc : suspend a rtk diseqc adapter
 *
 * Parm : p_this : handle of rtk diseqc adapter
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int rtk_diseqc_suspend(rtk_diseqc *p_this)
{
	diseqc_warn("%s [%s] diseqc suspend\n", DISEQC_MODEL_NAME , __func__ );

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtk_diseqc_resume
 *
 * Desc : suspend a rtd diseqc adapter
 *
 * Parm : p_this : handle of rtk diseqc adapter
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int rtk_diseqc_resume(rtk_diseqc *p_this)
{
	diseqc_warn("%s [%s] diseqc resume\n", DISEQC_MODEL_NAME , __func__ );

	CRT_CLK_OnOff(DISEQC, CLK_ON, NULL);        // enable clock

    // do Diseqc over here
	return 0;
}

/*------------------------------------------------------------------
 * Func : pm_rtd299x_cec_suspend
 *
 * Desc : Force rtk diseqcto enter suspend state.
 *        this function will be called before enter 8051.
 *
 * Parm : None
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int pm_rtk_diseqc_suspend(void)
{
	return rtk_diseqc_suspend(&m_diseqc);
}

/*//////////////////////////////////////////////////////////////////////
// Diseqc Driver Interface                                               //
//////////////////////////////////////////////////////////////////////*/

static int diseqc_probe(diseqc_device *dev)
{
	if (dev->id != ID_RTK_DISEQC_CONTROLLER )
		return -ENODEV;

	if (rtk_diseqc_init(&m_diseqc) == 0)
		diseqc_set_drvdata(dev, &m_diseqc);

	return 0;
}

static void diseqc_remove(diseqc_device *dev)
{
	rtk_diseqc_uninit((rtk_diseqc *) diseqc_get_drvdata(dev));
}


static diseqc_data_buff *diseqc_read(diseqc_device *dev, unsigned long flags)
{
#if 0
	return rtk_diseqc_read_message((rtk_diseqc *) diseqc_get_drvdata(dev),
					flags);
#else
	return 0;
#endif
}

static int diseqc_suspend(diseqc_device *dev)
{
	return rtk_diseqc_suspend((rtk_diseqc *) diseqc_get_drvdata(dev));
}

static int diseqc_resume(diseqc_device *dev)
{
	return rtk_diseqc_resume((rtk_diseqc *) diseqc_get_drvdata(dev));
}

int diseqc_set_envelop_mode(unsigned int envelop_mode)
{
	DISEQC_INFO("%s %s %d\n", __FILE__, __func__, __LINE__);

	if(envelop_mode == DISEQC_PULSE_MODE)
		rtd_maskl(DSCU_CTL, ~TX_ENV_MODE_MASK, TV_ENV_MODE_EN_SET(0));
	else if(envelop_mode == DISEQC_ENVELOP_MODE)
		rtd_maskl(DSCU_CTL, ~TX_ENV_MODE_MASK, TV_ENV_MODE_EN_SET(1));

	return SUCCESS;
}

int diseqc_set_continue_22k_on_off(unsigned int diseqc_22k_on_off)
{
	DISEQC_INFO("%s %s %d\n", __FILE__, __func__, __LINE__);

	rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_STOP));//Tx Off

	rtd_maskl(DSCU_TX_CTL, ~XMT_MODE_MASK, XMT_MODE(CONTINUOUS_TONE));//Continue Tone Mode

	diseqc_msleep(1);
	if(diseqc_22k_on_off == DISEQC_ON)
		rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_START));//Tx Go
	else
		rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_STOP));//Tx Off

	return SUCCESS;
}

int diseqc_set_diseqc_cmd(unsigned int data_len,unsigned char *data)
{
    DISEQC_INFO("%s %s %d\n", __FILE__, __func__, __LINE__);

	int DataCount;

    rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_STOP));//Tx Off

    rtd_maskl(DSCU_TX_CTL, ~XMT_MODE_MASK, XMT_MODE(DISEQC_MESSAGE));//Diseqc Cmd Mode

	rtd_maskl(DSCU_TX_CTL, ~MSG_LEN_MASKE, MSG_LEN(data_len-1));//Set Data Length(0:1Byte, 1:2Byte, ...)

	for(DataCount=0; DataCount<data_len; DataCount++)
	{
		write_reg32((TX_BUF0+(4*DataCount)), *(data+DataCount));
	}

	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 0 = %x\n" "\033[m", read_reg32(TX_BUF0));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 1 = %x\n" "\033[m", read_reg32(TX_BUF1));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 2 = %x\n" "\033[m", read_reg32(TX_BUF2));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 3 = %x\n" "\033[m", read_reg32(TX_BUF3));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 4 = %x\n" "\033[m", read_reg32(TX_BUF4));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 5 = %x\n" "\033[m", read_reg32(TX_BUF5));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 6 = %x\n" "\033[m", read_reg32(TX_BUF6));
	DISEQC_INFO("\033[1;32;32m" "Diseqc cmd data 7 = %x\n" "\033[m", read_reg32(TX_BUF7));

	diseqc_msleep(70);

    rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_START));//Tx Go

	if(diseqc_wait_tx_buffer_complete(150) < 0)
    {
		DISEQC_DBG("%s: tx buffer timeout!!\n", __func__);
		return FAIL;
	}

	return SUCCESS;
}

int diseqc_set_unmod_tone_burst(void)
{
	DISEQC_INFO("%s %s %d\n", __FILE__, __func__, __LINE__);
	rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_STOP));//Tx Off

    rtd_maskl(DSCU_TX_CTL, ~XMT_MODE_MASK, XMT_MODE(UN_MODULATED_TONE_BURST));//Un-Modulated Tone Burst Mode

    diseqc_msleep(1);

	rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_START));//Tx Go
	
	if(diseqc_wait_tx_buffer_complete(150) < 0)
    {
		DISEQC_DBG("%s: tx buffer timeout!!\n", __func__);
		return FAIL;
	}

	return SUCCESS;
}

int diseqc_set_mod_tone_burst(void)
{
    DISEQC_INFO("%s %s %d\n", __FILE__, __func__, __LINE__);
	rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_STOP));//Tx Off

    rtd_maskl(DSCU_TX_CTL, ~XMT_MODE_MASK, XMT_MODE(MODULATED_TONE_BURST));//Modulated Tone Burst Mode

    diseqc_msleep(1);

	rtd_maskl(DSCU_TX_CTL, ~TX_GO_MASK, TX_GO(TX_START));//Tx Go

	if(diseqc_wait_tx_buffer_complete(150) < 0)
	{
		DISEQC_DBG("%s: tx buffer timeout!!\n", __func__);
		return FAIL;
	}

    return SUCCESS;
}

int diseqc_set_tone_burst(TONE_MODE mode)
{
    DISEQC_DBG("%s %s %d\n", __FILE__, __func__, __LINE__);
	int ret = 0;
    if(mode == TONE_MODE_A)
		ret = diseqc_set_unmod_tone_burst();
	else
		ret = diseqc_set_mod_tone_burst();

	if(ret < 0)
	{
		DISEQC_DBG("%s: set tone mode failed!!\n", __func__);
        return FAIL;
	}

	return SUCCESS;
}

static diseqc_device rtk_diseqc_controller = {
	.id = ID_RTK_DISEQC_CONTROLLER,
	.name =  DISEQC_DRIVE_NAME
};

static diseqc_driver rtk_diseqc_driver = {

	.name = DISEQC_DRIVE_NAME,
	.probe = diseqc_probe,
	.remove = diseqc_remove,
	.suspend = diseqc_suspend,
	.resume = diseqc_resume,

	.set_22k_on_off = diseqc_set_continue_22k_on_off,
	.set_diseqc_cmd = diseqc_set_diseqc_cmd,
	.set_unmod_tone_burst = diseqc_set_unmod_tone_burst,
	.set_mod_tone_burst = diseqc_set_mod_tone_burst,
	.set_tone_burst = diseqc_set_tone_burst,
};

/*------------------------------------------------------------------
 * Func : rtd299x_cec_module_init
 *
 * Desc : rtk diseqcmodule init function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int __init rtk_diseqc_module_init(void)
{
	diseqc_warn("%s module init\n", DISEQC_MODEL_NAME);

	if (register_diseqc_driver(&rtk_diseqc_driver) != 0)
		return -EFAULT;

	register_diseqc_device(&rtk_diseqc_controller);

	return 0;
}

/*------------------------------------------------------------------
 * Func : rtd284x_diseqc_module_exit
 *
 * Desc : rtd284x diseqc module exit function
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtk_diseqc_module_exit(void)
{
	unregister_diseqc_device(&rtk_diseqc_controller);

	unregister_diseqc_driver(&rtk_diseqc_driver);
}

module_init(rtk_diseqc_module_init);
module_exit(rtk_diseqc_module_exit);
