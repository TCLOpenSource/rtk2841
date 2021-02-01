#ifndef	__RTK_SCD_PRIV_H__
#define	__RTK_SCD_PRIV_H__

#include <linux/wait.h>
#include <linux/timer.h>
#include <linux/spinlock.h>
#include <linux/kfifo.h>
#include "../core/rtk_scd.h"
#include "../core/rtk_scd_atr.h"
#include <rtk_kdriver/rtk_gpio.h>

#define	ID_SCD(x)					 (0x12830000 | (x	&	0x3))
#define	SCD_CHANNEL(id)		 (id & 0x03)


#define	RX_RING_LENGTH	32
#define	TX_RING_LENGTH	32


typedef	enum {
		IFD_FSM_UNKNOWN,
		IFD_FSM_DISABLE,				/* function	disabled*/
		IFD_FSM_DEACTIVATE,			/* function	enabled	but	not	reset	the	card yet*/
		IFD_FSM_RESET,					/* reset the card	and	waiting	for	ATR*/
		IFD_FSM_ACTIVE,					/* card	activated*/
} IFD_FSM;

/*#define	ISR_POLLING*/
#define	USE_TX_FIFO

typedef	struct {
		unsigned long	INT_EN;				/* CPU Interrupt Enable	*/
		unsigned long	INT_MASK;			/* CPU Interrupt Enable	Mask */
		/*-------------------------------------------*/
		unsigned long	ISR;					/* Interrupt	*/
		unsigned long	ISR_MASK;			/* Interrupt Mask	*/
		unsigned long	FP;						/* Smartcard Carrier Frequency Programmer	*/
		unsigned long	CR;						/* Smartcard Control Register	*/
		unsigned long	PCR;					/* Smartcard Protocol	Control	Register */
		unsigned long	TXFIFO;				/* Smartcard Transmit	FIFO Register	*/
		unsigned long	RXFIFO;				/* Smartcard Receive FIFO	Register */
		unsigned long	RXLENR;				/* Smartcard Receive Length	Register */
		unsigned long	FCR;					/* Smartcard Flow	Control	Register */
		unsigned long	IRSR;					/* Smartcard Interrupt Status	Register */
		unsigned long	IRER;					/* Smartcard Interrupt Enable	Register */
} SC_REG;


typedef	struct scd_tag	 scd;

struct scd_tag{
		unsigned char				id;					/* channel id	*/
		IFD_FSM							fsm;				/* finate	state	machine	of ifd*/
	unsigned char				card_status_change;
	unsigned char				tx_status;
	#define	SC_TX_DONE					0x1
	#define	SC_TX_PARITY_ERROR	(0x1<<1)
	#define	SC_TX_ABORT					(0x1<<2)
	unsigned char				rx_status;
	#define	SC_RX_ABORT					0x1

		/* config*/
		unsigned char				clock_div;					/* clock divider*/
		unsigned char				pre_clock_div;			/* pre_clock divider*/
		unsigned long				baud_div1;
		unsigned long				baud_div2;
		unsigned char				parity;

		unsigned char				vcc_5v:1;
		unsigned char				cmd_vcc_en:1;
		unsigned char				cmd_vcc_polarity:1;
		unsigned char				pwr_sel_en:1;
		unsigned char				pwr_sel_polarity:1;
		RTK_GPIO_ID				pin_cmd_vcc;				 /*	command	vcc*/
		RTK_GPIO_ID				pin_pwr_sel;				 /*	power	sel		 */

	/* atr */
	scd_atr							atr;							 /*	current	atr	*/
	scd_atr_info				atr_info;					 /*	current	atr*/
	unsigned long				atr_timeout;

		wait_queue_head_t		wq;
		struct kfifo				rx_fifo;
		struct kfifo				tx_fifo;
		spinlock_t					rx_fifo_lock;

#ifdef ISR_POLLING
		struct timer_list		timer;
#endif

		SC_REG							reg;

		spinlock_t					lock;
};

extern scd *scd_open(unsigned	char id);
extern void	scd_close(scd	*p_this);
extern int scd_suspend(scd *p_this);
extern int scd_resume(scd *p_this);
extern int scd_enable					(scd *p_this,	unsigned char	on_off);
extern int scd_set_clock				(scd *p_this,	unsigned long	clock);
extern int scd_set_etu					(scd *p_this,	unsigned long	etu);
extern int scd_set_parity				(scd *p_this,	SC_PARITY	parity);

extern int scd_get_clock				(scd *p_this,	unsigned long	*p_clock);
extern int scd_get_etu					(scd *p_this,	unsigned long	*p_etu);
extern int scd_get_parity				(scd *p_this,	SC_PARITY	*p_parity);

static inline	int	 scd_set_vcc_lvl(scd *p_this,	SC_VCC_LVL lvl)
{
	p_this->vcc_5v = (lvl	== SC_VCC_5V)	?	1	:	0;
	return SC_SUCCESS;
}

static inline	int	 scd_get_vcc_lvl(scd *p_this,	SC_VCC_LVL *p_lvl)
{
	*p_lvl = (p_this->vcc_5v)	?	SC_VCC_5V	:	SC_VCC_3V;
	return SC_SUCCESS;
}

static inline	int	 scd_set_convention(scd	*p_this, SC_CONV conv)
{
	return SC_SUCCESS;
}

static inline	int	 scd_get_convention(scd	*p_this, SC_CONV *p_conv)
{
	*p_conv	=	SC_AUTO_CONV;
	return SC_SUCCESS;
}

extern int scd_activate					(scd *p_this);
extern int scd_deactivate				(scd *p_this);
extern int scd_reset						(scd *p_this);
extern int scd_get_atr					(scd *p_this,	scd_atr	*p_atr);
extern int scd_card_detect			(scd *p_this);
extern int scd_get_card_status	(scd *p_this);
extern int scd_poll_card_status	(scd *p_this);
extern int scd_xmit							(scd *p_this,	unsigned char	*p_data, unsigned	int	len);
extern int scd_read							(scd *p_this,	unsigned char	*p_data, unsigned	int	len, unsigned	long timeout);
extern int scd_abort						(scd *p_this);
extern int scd_set_guard_interval(scd	*p_this, unsigned	long guard_interval);
extern int scd_get_guard_interval(scd	*p_this, unsigned	long *p_guard_interval);
extern unsigned long long scd_interface_value                 (scd *p_tis);

#endif /*__RTK_SCD_PRIV_H__*/