/*
 *Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <asm/uaccess.h>		/* copy_*_user */
#include <asm/io.h>
#include <mach/irqs.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_padlock.h>


#include "rtk_pcmcia_pinmux.h"
#include "rtk_pcmcia_reg.h"
#include "rtk_pcmcia.h"

#ifdef CONFIG_CUSTOMER_TV006
#include <rtk_kdriver/rtk_lg_board.h>
#endif

/*#define MAC3_VERIFY*/
#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)		(hwirq)
#endif
#define SA_SHIRQ	IRQF_SHARED
#define PCMCIA_IRQ	IRQ_MISC
#define LOCK_PCMCIA()	mutex_lock(&rtk_pcmcia_lock)
#define UNLOCK_PCMCIA()	mutex_unlock(&rtk_pcmcia_lock)
static DEFINE_MUTEX(rtk_pcmcia_lock);
static DEFINE_MUTEX(rtk_pcmcia_ioctl_lock);
static RTK_PCMCIA *rtk_pcmcia[2] = { NULL, NULL };

static RTK_PCMCIA *rtk_pcmcia_ptr=NULL;
extern char *parse_token(const char *parsed_string, const char *token);
static unsigned long long pcmcia_cfg =
    RTK_PCMCIA_CFG_PCMCIA1_EN | RTK_PCMCIA_CFG_PCMCIA0_EN;
static unsigned int pcmcia_cfg2;
static unsigned int pcmcia_cfg3;
static int bRtkPcmciaResume = 0;
static int pcmcia_fifo_mode_enable = 1;
static int pcmcia_fifo_write_debug_enable = 0;
static int pcmcia_fifo_read_debug_enable = 0;
static int pcmcia_poll_event_debug_enable = 0;
static int pcmcia_failed_count = 0;
			
#define POLL_EVENT_DBG(fmt, args...)    if (pcmcia_poll_event_debug_enable) { PCMCIA_WARNING(fmt, ##args); }

#define MAX_RX_BURST        (32 * 16)
#define MAX_TX_BURST        (32 * 16)

#if 0
/*old timing parameters*/
static unsigned long pcmcia_amtc0 = 0x00130304;
static unsigned long pcmcia_amtc1 = 0x00110002;
static unsigned long pcmcia_iomtc = 0x08020602;
static unsigned long pcmcia_matc0 = 0x00130002;
static unsigned long pcmcia_matc1 = 0x0013000a;
#elif 1
/*optimal timing parameters */
#define DEF_TAOE            10

#define TSU(x)           ((x) & 0xF)
#define THD(x)           (((x) & 0xF)<<8)
#define TWE(x)           (((x) & 0x3F)<<16)
static unsigned long pcmcia_amtc0 = TWE(DEF_TAOE + 2) | THD(8) | TSU(3);
#define TAOE(x)          (((x) & 0x3F)<<16)
#define THCE(x)          ((x) & 0x3F)
static unsigned long pcmcia_amtc1 = TAOE(DEF_TAOE) | THCE(2);
static unsigned long pcmcia_iomtc = 0x06040502;
#define TC(x)            (((x) & 0x3F)<<16)
#define THDIO(x)         ((x) & 0x3F)
static unsigned long pcmcia_matc0 = TC(0x12) | THDIO(2);
#define TCIO(x)          (((x) & 0x1FF)<<16)
#define TWIOWR(x)        ((x) & 0xFF)
static unsigned long pcmcia_matc1 = TCIO(0x12) | TWIOWR(8);
#else
/*for saving inpack pin timing parameters*/
static unsigned long pcmcia_amtc0 = 0x000b0303;
static unsigned long pcmcia_amtc1 = 0x00090002;
static unsigned long pcmcia_iomtc = 0x03020102;
static unsigned long pcmcia_matc0 = 0x00040002;
static unsigned long pcmcia_matc1 = 0x00040005;
#endif

static int g_auto_pinmux_enable = 0; /*1: auto pin mux, 0: no auto pin mux*/
static int g_fifo_func_use_hw_mode = 0; /*1: HW mode, 0: SW mode*/
static int g_cd_seperate2pins      = 0; /*1: CD need 2 pins , 0: CD need only 1 pin */
static RTK_PCMCIA_RESET_PULSE_WIDTH_TYPE g_reset_pulse_width_type = RTK_PCMCIA_RESET_PULSE_WIDTH_2MS; /*default reset pulse with is 2ms*/

static void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
    unsigned int X,A,result;

    X=(1<<(endBit-startBit+1))-1;
    A=rtd_inl(reg_addr);

    result = (A & (~(X<<startBit))) | (value<<startBit);
    rtd_outl(reg_addr,result);
}

unsigned int rtd_part_inl(unsigned int addr, unsigned int B, unsigned int C)
{
    unsigned int X,A;

    X=(1<<(B-C+1))-1;
    A=rtd_inl(addr);

    return (A>>C)&X;
}

static char *get_reset_pulse_width_info(RTK_PCMCIA_RESET_PULSE_WIDTH_TYPE reset_pulse_width_type)
{
    char *reset_pulse_width_info = "2ms";
    switch(reset_pulse_width_type)
    {
    case RTK_PCMCIA_RESET_PULSE_WIDTH_114US:
        reset_pulse_width_info = "114us";
        break;
    case RTK_PCMCIA_RESET_PULSE_WIDTH_1MS:
        reset_pulse_width_info = "1ms";
        break;
    case RTK_PCMCIA_RESET_PULSE_WIDTH_2MS:
        reset_pulse_width_info = "2ms";
        break;
    case RTK_PCMCIA_RESET_PULSE_WIDTH_20MS:
        reset_pulse_width_info = "20ms";
        break;
    default:
        reset_pulse_width_info = "unknown";
        break;
    };
    return reset_pulse_width_info;
}



unsigned int GET_PCMCIA_STS(void)
{
    int ret = 0;
    unsigned long flags = 0;
    if (PCMCIA_INT_VALID(pcmcia_cfg2))
    {
        ret = rtd_inl(PCMCIA_REG_STS);

        spin_lock_irqsave(&rtk_pcmcia_ptr->lock_int, flags);

        /*PCMCIA_INFO("pcmcia_int_status = 0x%08X\n" , rtk_pcmcia_ptr->event ); */

        if (RTK_PCMCIA_EVENT_IREQ_ASSERT & rtk_pcmcia_ptr->event)
        {
            if (rtk_pcmcia_ptr == rtk_pcmcia[0])
            {
                ret |= PC_PII1;
            }
            else
            {
                ret |= PC_PII2;
            }

            /*rtk_pcmcia_ptr->event &= ~rtk_PCMCIA_EVENT_IREQ_ASSERT; */
        }
        else
        {
            if (rtk_pcmcia_ptr == rtk_pcmcia[0])
            {
                ret &= ~PC_PII1;
            }
            else
            {
                ret &= ~PC_PII2;
            }
        }

        /*PCMCIA_INFO("pcmcia_int_status = 0x%08X  , ret = 0x%08X  \n" , rtk_pcmcia_ptr->event , ret );*/

        spin_unlock_irqrestore(&rtk_pcmcia_ptr->lock_int, flags);
    }
    else
    {
        ret = rtd_inl(PCMCIA_REG_STS);
    }

    return ret;
}

static irqreturn_t rtk_pcmcia_isr(int this_irq, void *dev_id)
{
    RTK_PCMCIA *p_this = (RTK_PCMCIA *) dev_id;
    unsigned long event;
    unsigned long flags;

    if ((rtd_inl(PCMCIA_INT) & PCMCIA_INT_MASK) == 0)
        return IRQ_NONE;

    spin_lock_irqsave(&p_this->lock, flags);

    event = GET_PCMCIA_STS();

    /* Card Detection Interrupt Handler */
    if ((event & p_this->reg_bits.CD_INT)
            && (GET_PCMCIA_CTRL() | p_this->reg_bits.CD_INT))
    {
        if (rtk_pcmcia_get_card_status(p_this) &RTK_PCMCIA_STS_CARD_PRESENT)
        {

            PCMCIA_WARNING("PCMCIA-%d, Card Inserted\n", p_this->id);
            p_this->flags &= ~PCMCIA_CARD_RESET_COMPLETE;
        }
        else
        {

            PCMCIA_WARNING("PCMCIA-%d, Card Removed, disable card\n",
                           p_this->id);

            rtk_pcmcia_card_enable(p_this, 0);
        }
        SET_PCMCIA_STS(p_this->reg_bits.CD_INT);
        p_this->event |= RTK_PCMCIA_EVENT_CARD_STATUS_CHANGE;
        wake_up(&p_this->wq);
    }
    if ((event & p_this->reg_bits.PII) && (GET_PCMCIA_CTRL() |
                                           p_this->reg_bits.PII))
    {

        POLL_EVENT_DBG("PCMCIA-%d, IREQ# detected\n", p_this->id);
        SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() & ~(p_this->reg_bits.PII));	/* disable PII interrupt*/
        SET_PCMCIA_STS(p_this->reg_bits.PII);	/* clear PII */
        p_this->event |= RTK_PCMCIA_EVENT_IREQ_ASSERT;
        POLL_EVENT_DBG("PCMCIA-%d, Status = %08x / event=%08lx\n", p_this->id, GET_PCMCIA_STS(), p_this->event);
        wake_up(&p_this->wq);
    }

    /* Assess Interrupt Handler */
    if ((event & PC_ACCESS_INT) && (p_this->flags & PCMCIA_TX_ON))
    {
        SET_PCMCIA_STS(PC_ACCESS_INT);
        PCMCIA_DBG("PCMCIA-%d, tx complete\n", p_this->id);
        p_this->tx_status = (event & PC_ACCESS_INT);
        p_this->flags &= ~PCMCIA_TX_ON;
        wake_up(&p_this->wq);
    }

#if 0
    rtd_outl(PCMCIA_INT, PCMCIA_INT_EN_MASK);

#endif	/*
 */
    spin_unlock_irqrestore(&p_this->lock, flags);
    return IRQ_HANDLED;
}

static void rtk_pcmcia_gpio_int_isr(RTK_GPIO_ID gid, unsigned char assert,
                                    void *dev_id)
{
    unsigned long flags;

    /*
    	PCMCIA_DBG("%s GPIO %d assert=%d, val=%d\n",
    			gpio_type(gpio_group(gid)), gpio_idx(gid),
    			assert, rtk_gpio_input(gid));
    */


    spin_lock_irqsave(&rtk_pcmcia_ptr->lock, flags);

    /*	PCMCIA_DBG("gpio interrupt detected\n");*/

    rtk_pcmcia_ptr->event |= RTK_PCMCIA_EVENT_IREQ_ASSERT;

    /*PCMCIA_INFO("pcmcia_int_status = 0x%08X\n" , rtk_pcmcia_ptr->event );*/

    spin_unlock_irqrestore(&rtk_pcmcia_ptr->lock, flags);
}

void rtk_pcmcia_phy_reset(void)
{
    int try_cnt = 0;
    PCMCIA_DBG("rtk_pcmcia_phy_reset\n");
    SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() | PC_PSR);
    PCMCIA_DBG("wait PSR done\n");
    while (GET_PCMCIA_CTRL() & PC_PSR && try_cnt++ < 100)
    {
        PCMCIA_DBG("wait PSR ready : %lx=%lx\n", PCMCIA_REG_CTRL,
                   GET_PCMCIA_CTRL());
        msleep(1);
    }
    PCMCIA_DBG("PSR done\n");

    if (GET_PCMCIA_CTRL() & PC_PSR)
    {
        PCMCIA_DBG("Wait PSR timeout\n");
        PCMCIA_DBG("%lx=%lx\n", PCMCIA_CLOCK_ENABLE,rtd_inl(PCMCIA_CLOCK_ENABLE));
        PCMCIA_DBG("%lx=%lx\n", PCMCIA_SOFT_RESET,rtd_inl(PCMCIA_SOFT_RESET));
    }
}

#ifdef CONFIG_REALTEK_PCBMGR

#include "mach/pcbMgr.h"
static void rtk_pcmcia_gpio_config(void)
{
    unsigned long long param;
    if (pcb_mgr_get_enum_info_byname("PCMCIA_CFG", &param) == 0)
    {
        pcmcia_cfg = param & 0xFFFFFFFFFFFFFFFF;
    }
    else
    {
        /*Card Detect PAD */
        if (pcb_mgr_get_enum_info_byname("M_PCM_CD_N", &param) == 0)
        {
            pcmcia_cfg |= PCMCIA_CD_SET(GET_PIN_INDEX(param));
            PCMCIA_WARNING("Card dtection is GPIO%d\n",GET_PIN_INDEX(param));
        }
        else
        {
            pcmcia_cfg |= PCMCIA_CD_SET(61);
            PCMCIA_WARNING ("Can't find M_PCM_CD_N config, use default as card detect.\n");
        }
        /*Power Control GPIO */
        if (pcb_mgr_get_enum_info_byname("PIN_PCMCIA_EN", &param) == 0)
        {
            if (GET_PIN_TYPE(param) == PCB_PIN_TYPE_ISO_GPIO
                    || GET_PIN_TYPE(param) == PCB_PIN_TYPE_GPIO)
            {

                pcmcia_cfg |= RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID;

                if (GET_PIN_TYPE(param) ==
                        PCB_PIN_TYPE_ISO_GPIO)
                    pcmcia_cfg |= RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_GPIO_TYPE;

                pcmcia_cfg |= GET_PIN_INDEX(param);
                if (!GET_PIN_PARAM2(param))	/*inverted */
                    pcmcia_cfg |= RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_POAL;
            }
        }
        else
        {
            PCMCIA_WARNING
            ("Can't find PIN_PCMCIA_EN config, don't use GPIO to control power.\n");
        }

        /*demo baord setting */
        /*pcmcia_cfg |= ( RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID | */
        /*                                     RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_POAL |(15)); */
#ifdef MAC3_VERIFY
        pcmcia_cfg = pcmcia_cfg & (~RTK_PCMCIA_CFG_PCMCIA1_EN);
        pcmcia_cfg |= (RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID |
                       RTK_PCMCIA_CFG_PCMCIA0_EN |
                       RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_POAL |
                       RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_GPIO_TYPE | (11));

#endif /*
 */
    }
    PCMCIA_WARNING("pcmcia_cfg = %llx\n", (unsigned long long)pcmcia_cfg);
}
static void rtk_pcmcia_gpio_config2(void)
{
    unsigned long long param2;

    if (pcb_mgr_get_enum_info_byname("PCMCIA_CFG2", &param2) == 0)
    {
        pcmcia_cfg2 = param2 & 0xFFFFFFFF;
        PCMCIA_WARNING("find PCMCIA_CFG2 config.\n");
    }
    else
    {
        PCMCIA_WARNING("Can't find PCMCIA_CFG2 config.\n");

        /*GPIO INT pin*/
        if (pcb_mgr_get_enum_info_byname("PIN_PCMCIA_INT", &param2) ==  0)
        {

            PCMCIA_WARNING("PIN_PCMCIA_INT = 0x%llx.\n", param2);

            if (GET_PIN_TYPE(param2) == PCB_PIN_TYPE_ISO_GPIO ||
                    GET_PIN_TYPE(param2) == PCB_PIN_TYPE_GPIO)
            {
                pcmcia_cfg2 |= RTK_PCMCIA_CFG_PCMCIA_INT_VALID;

                if (GET_PIN_TYPE(param2) ==
                        PCB_PIN_TYPE_ISO_GPIO)
                    pcmcia_cfg2 |=
                        RTK_PCMCIA_CFG_PCMCIA_INT_GPIO_TYPE;

                pcmcia_cfg2 |= GET_PIN_INDEX(param2);

                if (!GET_PIN_PARAM2(param2))	/*inverted*/
                    pcmcia_cfg2 |=
                        RTK_PCMCIA_CFG_PCMCIA_INT_POAL;
            }
        }
        else
        {
            PCMCIA_WARNING("Can't find PIN_PCMCIA_INT config, pcmcia operation will be abnormal.\n");
        }

        /*demo baord setting*/
        /* pcmcia_cfg2 |= ( rtk_PCMCIA_CFG_PCMCIA_INT_VALID |
        			rtk_PCMCIA_CFG_PCMCIA_INT_POAL |(14));
        */
    }

    PCMCIA_WARNING("pcmcia_cfg2 = 0x%x\n", pcmcia_cfg2);
}

static void rtk_pcmcia_gpio_config3(void)
{
    unsigned long long param3;

    if (pcb_mgr_get_enum_info_byname("PCMCIA_CFG3", &param3) == 0)
    {
        pcmcia_cfg3 = param3 & 0xFFFFFFFF;
        PCMCIA_WARNING("find PCMCIA_CFG3 config.\n");
    }
    else
    {
        PCMCIA_WARNING("Can't find PCMCIA_CFG3 config.\n");
    }


    PCMCIA_WARNING("pcmcia_cfg3 = 0x%x\n", pcmcia_cfg3);
}

#else /*
 */
static void rtk_pcmcia_gpio_config(void)
{
    pcmcia_cfg |= (RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID |
                   RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_POAL | (0xF));
}

static void rtk_pcmcia_gpio_config2(void)
{
    pcmcia_cfg2 = 0;
}

static void rtk_pcmcia_gpio_config3(void)
{
    pcmcia_cfg3 = 0;
}

#endif /*
 */

/*-----------------------------------------------------------------------------------
 * low level PCMCIA device driver
 *------------------------------------------------------------------------------------*/
RTK_PCMCIA *create_rtk_pcmcia(unsigned char id)
{
    unsigned int reset_pulse_width_cfg = 0;
    RTK_PCMCIA *p_this = NULL;
    if (id >= MAX_PCMCIA_ENTRY)
        return NULL;

    g_cd_seperate2pins  = PCMCIA_CD_SEPERATE_2PIN(pcmcia_cfg3); //need two detect pins

    p_this = (RTK_PCMCIA *) kmalloc(sizeof(RTK_PCMCIA), GFP_KERNEL);
    if (p_this)
    {
        memset(p_this, 0, sizeof(RTK_PCMCIA));
        p_this->id = id;
        init_waitqueue_head(&p_this->wq);
        spin_lock_init(&p_this->lock);
        spin_lock_init(&p_this->lock_int);

        atomic_set(&(p_this->atomic_init), 0);

        switch (id)
        {
        case 0:
            p_this->reg_bits.CE =
                PCMCIA_CE_SWAP(pcmcia_cfg) ? PC_CE1_CARD2 :
                PC_CE1_CARD1;
            p_this->reg_bits.PCR_OE = PC_PCR1_OE;
            p_this->reg_bits.PRES = (g_cd_seperate2pins)?(PC_PRES1|PC_PRES2):(PC_PRES1);
            p_this->reg_bits.PII = PC_PII1;
            p_this->reg_bits.PCR = PC_PCR1;
            p_this->reg_bits.CD_INT = PC_CARD_DETECT1_INT;
            if (PCMCIA0_PWR_EN_VALID(pcmcia_cfg))
            {
                p_this->flags |= PCMCIA_WITH_POWER_CTRL_GPIO;
                p_this->pwr_en_pin =
                    rtk_gpio_id(PCMCIA0_PWR_EN_GPIO_TYPE
                                (pcmcia_cfg),
                                PCMCIA0_PWR_EN_GPIO
                                (pcmcia_cfg));
            }
            rtd_outl(PCMCIA_REG_PIN_SEL, (rtd_inl(PCMCIA_REG_PIN_SEL))
                     | PC_INPACK0_DIS(1) | PC_WAIT0_DIS(0));
            break;
        case 1:
            p_this->reg_bits.CE = PCMCIA_CE_SWAP(pcmcia_cfg) ?
                                  PC_CE1_CARD1 : PC_CE1_CARD2;
            p_this->reg_bits.PCR_OE = PC_PCR2_OE;
            p_this->reg_bits.PRES = (g_cd_seperate2pins)?(PC_PRES1|PC_PRES2):(PC_PRES2);
            p_this->reg_bits.PII = PC_PII2;
            p_this->reg_bits.PCR = PC_PCR2;
            p_this->reg_bits.CD_INT = PC_CARD_DETECT2_INT;
            if (PCMCIA1_PWR_EN_VALID(pcmcia_cfg))
            {

                p_this->flags |= PCMCIA_WITH_POWER_CTRL_GPIO;
                p_this->pwr_en_pin =
                    rtk_gpio_id(PCMCIA1_PWR_EN_GPIO_TYPE(pcmcia_cfg),
                                PCMCIA1_PWR_EN_GPIO(pcmcia_cfg));
            }

            rtd_outl(PCMCIA_REG_PIN_SEL, (rtd_inl(PCMCIA_REG_PIN_SEL))
                     | PC_INPACK1_DIS(1) | PC_WAIT1_DIS(0));

            break;
        }
        if (p_this->flags & PCMCIA_WITH_POWER_CTRL_GPIO)
        {
            PCMCIA_WARNING("PCMCIA-%d : Power pin : %s_GPIO %d, CE=%08lx\n",
                           p_this->id,
                           gpio_type(gpio_group(p_this->pwr_en_pin)),
                           gpio_idx(p_this->pwr_en_pin),
                           p_this->reg_bits.CE);
        }
        else
        {
            PCMCIA_WARNING("PCMCIA-%d : N/A\n", p_this->id);
        }

        g_auto_pinmux_enable = PCMCIA_AUTO_PIN_SHARE_EN(pcmcia_cfg3);
        g_fifo_func_use_hw_mode = PCMCIA_FIFO_FUNC_PIN_SHARE_MODE(pcmcia_cfg3);
        p_this->skipTime = 1800;

        PCMCIA_WARNING("PCMCIA-%d : auto pinmux share function %s\n", p_this->id, g_auto_pinmux_enable ? "enable" : "disable");

        //if(g_auto_pinmux_enable )
        PCMCIA_WARNING("PCMCIA-%d : auto pinmux share function fifo mode use [%s]\n",
                       p_this->id, g_fifo_func_use_hw_mode ? "hw mode" : "soft mode");
        PCMCIA_WARNING("PCMCIA-%d : skipTime: %d\n",p_this->skipTime);


        reset_pulse_width_cfg = PCMCIA_GET_RESET_PLUSE_WIDTH_TYPE(pcmcia_cfg3);
        if((reset_pulse_width_cfg > 0) && (reset_pulse_width_cfg <= (RTK_PCMCIA_RESET_PULSE_WIDTH_20MS + 1)))
            g_reset_pulse_width_type = reset_pulse_width_cfg - 1;

        PCMCIA_WARNING("PCMCIA-%d : set reset pulse width to %s \n",
                       p_this->id, get_reset_pulse_width_info(g_reset_pulse_width_type));

        PCMCIA_WARNING("PCMCIA-%d : Card detect using %d pins \n",
                   p_this->id, g_cd_seperate2pins ? (2) : (1) );

        return p_this;

    }

    return NULL;
}

void release_rtk_pcmcia(RTK_PCMCIA *p_this)
{
    kfree(p_this);
}
void rtk_pcmcia_int_gpio_set(void)
{

    PCMCIA_WARNING("pcmcia_cfg2 = 0x%08X\n", pcmcia_cfg2);

    if (PCMCIA_INT_VALID(pcmcia_cfg2))
    {
        /* gpio interrupt pin */
        rtk_pcmcia_ptr->int_pin =
            rtk_gpio_id(PCMCIA_INT_GPIO_TYPE(pcmcia_cfg2),
                        PCMCIA_INT_GPIO(pcmcia_cfg2));

        rtk_gpio_set_dir(rtk_pcmcia_ptr->int_pin, 0);

        /* 100 us*/
        rtk_gpio_set_debounce(rtk_pcmcia_ptr->int_pin,
                              RTK_GPIO_DEBOUNCE_100us);

        rtk_gpio_set_irq_polarity(rtk_pcmcia_ptr->int_pin, 0);

        rtk_gpio_request_irq(rtk_pcmcia_ptr->int_pin,
                             rtk_pcmcia_gpio_int_isr, "PCMCIA_GPIO_INT",
                             rtk_pcmcia_gpio_int_isr);

        rtk_gpio_set_irq_enable(rtk_pcmcia_ptr->int_pin, 1);

        PCMCIA_WARNING("rtk_pcmcia_gpio_int for %s GPIO %d (%x) ready\n",
                       gpio_type(gpio_group(rtk_pcmcia_ptr->int_pin)),
                       gpio_idx(rtk_pcmcia_ptr->int_pin),
                       rtk_pcmcia_ptr->int_pin);
    }

}

int rtk_pcmcia_get_card_status(RTK_PCMCIA *p_this)
{
    int status = 0;
    unsigned long event = GET_PCMCIA_STS();

    if ( (event & p_this->reg_bits.PRES ) == p_this->reg_bits.PRES )
        status |= RTK_PCMCIA_STS_CARD_PRESENT;
    if (event & PC_AFI)
        status |= RTK_PCMCIA_STS_ACCESS_FAULT;
    if (event & p_this->reg_bits.PII)
        status |= RTK_PCMCIA_STS_IREQ_ASSERT;
    return status;
}

static inline int rtk_pcmcia_start_transfer(RTK_PCMCIA *p_this, int is_fifo_mode)
{
    unsigned long timeout = 0;
    if (!(rtk_pcmcia_get_card_status(p_this) & RTK_PCMCIA_STS_CARD_PRESENT))
    {
        PCMCIA_WARNING("access pcmcia failed - no card exists!!!\n");
        return PCMCIA_NODEV;
    }
    if (!(GET_PCMCIA_CTRL() & p_this->reg_bits.PCR_OE))
    {
        PCMCIA_DBG
            ("access pcmcia failed - please enable port first!!!\n");
        return PCMCIA_FAIL;
    }

    LOCK_PCMCIA();

#ifdef CONFIG_SD_PCMCIA_PADLOCK
    padlock(PAD_PCMCIA);    /* lock pcmcia pad  */
#endif  /*
 */
    if(g_auto_pinmux_enable)
    {
        if(is_fifo_mode && g_fifo_func_use_hw_mode)
        {
            SET_PCMCIA_FIFO_CTRL(GET_PCMCIA_FIFO_CTRL()
                                 & (~PC_PIN_SHARE_SEL_SOFT_MODE)); /*Let PCMCIA be HW mode */
            SET_TP_OUT_CTRL_REG(GET_TP_OUT_CTRL_REG()
                                |TP_OUT_SHARE_HW_MODE | TP_OUT_SHARE_EN);

        }
        else
        {
            SET_PCMCIA_FIFO_CTRL(GET_PCMCIA_FIFO_CTRL()
                                 | PC_PIN_SHARE_SEL_SOFT_MODE); /*Let PCMCIA be SW mode */
            SET_TP_OUT_CTRL_REG((GET_TP_OUT_CTRL_REG()
                                 | TP_OUT_SHARE_EN) & (~TP_OUT_SHARE_HW_MODE) );

            timeout = jiffies + 500 * HZ/1000 ; /*timeout for 500ms.*/
            while(!(GET_TP_OUT_INT_REG() & TP_PAUSE_INT))
            {
                if (time_after(jiffies, timeout))
                {
                    PCMCIA_WARNING("%s sw mode share enable pin timeout\n" , __FUNCTION__ );
                    SET_TP_OUT_CTRL_REG(GET_TP_OUT_CTRL_REG()
                                        &  (~TP_OUT_SHARE_EN));/*disable auto share*/
#ifdef CONFIG_SD_PCMCIA_PADLOCK
                    padunlock(PAD_PCMCIA);
#endif
                    UNLOCK_PCMCIA();
                    return PCMCIA_FAIL;
                }
                ndelay(100);
            }
            CLEAR_TP_PUASE_INT();
            SET_TP_OUT_CTRL_REG(GET_TP_OUT_CTRL_REG()
                                | TP_OUT_DATA_SEL_PCMCIA);/*sw mode switch pin mux from tp*/

        }
    }
    else
    {
// liangliang please confirm these
        SET_PCMCIA_FIFO_CTRL(GET_PCMCIA_FIFO_CTRL()
                             | PC_PIN_SHARE_SEL_SOFT_MODE); /*Let PCMCIA be SW mode */

    }

    /* don't enable PC Access Interrupt */
    /*SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() & ~PC_ACCESS_INT);*/

    return PCMCIA_OK;
}

static inline int rtk_pcmcia_stop_transfer(RTK_PCMCIA *p_this, int is_fifo_mode)
{
    if(g_auto_pinmux_enable)
    {
        if(!(is_fifo_mode && g_fifo_func_use_hw_mode))
        {
            SET_TP_OUT_CTRL_REG(GET_TP_OUT_CTRL_REG()
                                & (~TP_OUT_DATA_SEL_PCMCIA));/*sw mode switch pin mux from tp*/
            SET_TP_OUT_CTRL_REG(GET_TP_OUT_CTRL_REG()
                                & (~TP_OUT_SHARE_EN));/*disable auto share*/
        }
    }
#ifdef CONFIG_SD_PCMCIA_PADLOCK
    padunlock(PAD_PCMCIA);

#endif /*
 */
    UNLOCK_PCMCIA();
    return PCMCIA_OK;
}


int _rtk_pcmcia_fifo_read(RTK_PCMCIA *p_this, unsigned short addr,
                         unsigned char *p_data, unsigned short len,
                         unsigned long flags)
{
    int ret = PCMCIA_OK;
    unsigned long fifo_ctrl = 0;
	unsigned long ctrl;
	unsigned char attr = (flags & PCMCIA_FLAGS_ATTR) ? 1 : 0;
	unsigned long cmd = PC_CT_READ | PC_AT(attr) | PC_PA(addr);
	unsigned long try_count = 0;
	unsigned long event = 0;
	unsigned long irq_flags;
	
#ifdef FIFO_READ_DEBUG	
	static unsigned int rx_round = 0;
	unsigned int sub_round = 0;	
#endif	

    if (len == 0)
        return ret;

	if (!((GET_PCMCIA_STS() & p_this->reg_bits.PRES) == p_this->reg_bits.PRES))
	{
		PCMCIA_WARNING("access pcmcia failed - no card exists!!!\n");
		return PCMCIA_NODEV;
	}

	if (!(GET_PCMCIA_CTRL() & p_this->reg_bits.PCR_OE))
	{
		PCMCIA_DBG
			("access pcmcia failed - please enable port first!!!\n");
		return PCMCIA_FAIL;
	}
	
#ifdef FIFO_READ_DEBUG
	rx_round++;
#endif
	
    preempt_disable();
	
    spin_lock_irqsave(&p_this->lock, irq_flags);

	ctrl = GET_PCMCIA_CTRL() & ~(PC_ACCESS_INT | PC_FIFO_INT);
	ctrl |= p_this->reg_bits.CE;
	SET_PCMCIA_CTRL(ctrl);
	SET_PCMCIA_STS(PC_ACCESS_INT | PC_FIFO_INT);

	if (attr)
		fifo_ctrl |= PC_ADDR_STEP(1) | PC_WR_NUM(len) | PC_PIN_SHARE_SEL_SOFT_MODE |
					PC_FIFO_R_TRIG(1);
	else{
		fifo_ctrl |= PC_ADDR_STEP(0) | PC_WR_NUM(len) | PC_PIN_SHARE_SEL_SOFT_MODE |
					PC_FIFO_R_TRIG(1);

		rtd_outl(PCMCIA_REG_PIN_SEL, (rtd_inl(PCMCIA_REG_PIN_SEL))  | PC_INPACK0_DIS(1) |  PC_WAIT0_DIS(0));
	}
	
	if ((flags & PCMCIA_FLAGS_FIFO) || len==1)    
		fifo_ctrl |= PC_FIFO_WR_MODE_ADDRESS_NOCHANGE;  // FIFO mode, do not increase register address
	else
		fifo_ctrl |= PC_FIFO_WR_MODE_ADDRESS_INCREASE;	    

	SET_PCMCIA_FIFO_CTRL(fifo_ctrl | PC_FIFO_EN(1));
	ndelay(10);
	SET_PCMCIA_CMDFF(cmd);      // kick off fifo read
	spin_unlock_irqrestore(&p_this->lock, irq_flags);

	while (ret==PCMCIA_OK)
	{
		try_count = 3000;       // around polling time = 3000 * 300ns = 1 ms
		event = GET_PCMCIA_STS();

		//-------------- wait fifo read request interrupt --------------
		while (!(event & PC_FIFO_RX_INT) && (try_count--)) 
		{
			ndelay(300);
            event = GET_PCMCIA_STS();
        }

#ifdef FIFO_READ_DEBUG
		PCMCIA_WARNING("_rtk_pcmcia_fifo_read(%d-%d) : event=%08lx (%08lx) \n" ,
			rx_round, sub_round,
			event, (event & (PC_FIFO_R_IE | PC_FIFO_WR_OVER_IE)));

		sub_round++;	
#endif

		if ((event & PC_FIFO_RX_INT)==0)
		{
			pcmcia_failed_count++;
			if (pcmcia_failed_count < 100) {
			PCMCIA_ERROR("%s access pcmcia failed - wait rx fifo interrupt timeout, STS = 0x%X, FIFO_CTRL=%08lx, FIFO_STATUS=%08lx!!!\n" ,
					__FUNCTION__ , GET_PCMCIA_STS(), GET_PCMCIA_FIFO_CTRL(), GET_PCMCIA_FIFO_STATUS());
			}
			ret = PCMCIA_FAIL;	
			goto end_proc;
		}

		//-------------- handle interrupts ----------------------                                                                    
		if ((event & PC_FIFO_ERRO_IE)) 
		{
			PCMCIA_ERROR("%s access error , PC_FIFO_ERRO_IE !!! \n" , __FUNCTION__ , event);
			SET_PCMCIA_STS(PC_FIFO_ERRO_IE);								
			ret = PCMCIA_FAIL;
			goto end_proc;
		}
		
		if ((event & PC_FIFO_R_IE))
		{
			unsigned short fifo_len;

			spin_lock_irqsave(&p_this->lock, irq_flags);

			fifo_len = PC_FIFO_LEN(GET_PCMCIA_FIFO_STATUS());            
			SET_PCMCIA_STS(PC_FIFO_R_IE);       // trigger to start next read    

			if (fifo_len >= 16)
				fifo_len =  16;

			while (fifo_len && len) 
			{
				*p_data = GET_PCMCIA_FIFO_DATA();
				p_data++;
				len--;
				fifo_len--;
			}
			spin_unlock_irqrestore(&p_this->lock, irq_flags);
		}
		
		if ((event & PC_FIFO_WR_OVER_IE))
		{
			unsigned short fifo_len;
			
			spin_lock_irqsave(&p_this->lock, irq_flags);
						
			SET_PCMCIA_STS(PC_FIFO_WR_OVER_IE);
			
			fifo_len = PC_FIFO_LEN(GET_PCMCIA_FIFO_STATUS());

			while (fifo_len && len) 
			{
				*p_data = GET_PCMCIA_FIFO_DATA();
				p_data++;
				len--;
				fifo_len--;
			}
			
			spin_unlock_irqrestore(&p_this->lock, irq_flags);

			if (len!=0)  
			{
				PCMCIA_ERROR("%s access error , remain %d bytes unreaded !!! \n" , __FUNCTION__ , len );
				ret = PCMCIA_FAIL;
			}
			break;
		}
	}

end_proc:
    preempt_enable();
    return ret;
}



int rtk_pcmcia_fifo_read(RTK_PCMCIA *p_this, unsigned short addr,
			unsigned char *p_data, unsigned short len,
			unsigned long flags)
{
	int ret = PCMCIA_OK;
	int rx_len;
	int step;

	step = (flags & PCMCIA_FLAGS_FIFO) ? 0 : ((flags & PCMCIA_FLAGS_ATTR)) ? 2 : 1;

	// zap pinmux if necessary
	ret = rtk_pcmcia_start_transfer(p_this, 1);
	
	if (ret != PCMCIA_OK) 
	{
		PCMCIA_DBG("%s pcmcia read operation is failed , ret = 0x%X !!\n" ,
				__FUNCTION__ , ret );
		return ret;
	}

	//--- do fifo read 
	while(len)
	{
		rx_len = (len > MAX_RX_BURST) ? MAX_RX_BURST : len;

		ret = _rtk_pcmcia_fifo_read(p_this, addr, p_data, rx_len, flags);

		if (ret!=PCMCIA_OK) {
			if (pcmcia_failed_count < 100) {
			PCMCIA_WARNING("%s read failed\n" , __FUNCTION__);
			}
			goto end_proc;
		}

		p_data+= rx_len;
		len   -= rx_len;
		addr  += rx_len * step;
	}

end_proc:
	rtk_pcmcia_stop_transfer(p_this, 1);
	return ret;

}


int __rtk_pcmcia_write_tx_fifo(unsigned long cmd, unsigned char *p_data, unsigned short len)
{
	int tx_cnt = 0;

	while (tx_cnt < len) 
	{
		SET_PCMCIA_CMDFF(cmd | (*p_data));
		p_data++;
		tx_cnt++;
	}

	return tx_cnt;
}


/*----------------------------------------------------------
 * Func : _rtk_pcmcia_fifo_write
 *
 * Desc : lowlevel fifo write function.
 *
 * Para : 
 *
 * Retn : >=0 : number of bytes written, 
 *        <0  : failed
 *----------------------------------------------------------*/
int _rtk_pcmcia_fifo_write(RTK_PCMCIA *p_this, unsigned short addr,
                          unsigned char *p_data, unsigned short len,
                          unsigned long flags)
{
    int ret = PCMCIA_OK;
	int tx_bytes = 0;
	unsigned long fifo_ctrl = 0;
	unsigned char attr = (flags & PCMCIA_FLAGS_ATTR) ? 1 : 0;
	unsigned long ctrl;
	unsigned long cmd = PC_CT_WRITE | PC_AT(attr) | PC_PA(addr);
	unsigned long try_count = 3000;	   // 3000 * 300ns = 1ms
	unsigned long event;	
	static unsigned int tx_round = 0;
	unsigned int sub_round = 0;	
	unsigned long irq_flags;

	if (pcmcia_fifo_write_debug_enable)
		PCMCIA_WARNING("wr %s %s, addr = %d, len=%d\n", (flags & PCMCIA_FLAGS_ATTR) ? "attr" : "io",
			(flags & PCMCIA_FLAGS_FIFO) ? "port" : "mem", addr, len);

    if (p_data == NULL || len <= 0)
		return PCMCIA_FAIL;
		
	if (len > MAX_TX_BURST)
		len = MAX_TX_BURST;	
		
	tx_round++;  
		
    ret = rtk_pcmcia_start_transfer(p_this, 1);
    if (ret != PCMCIA_OK)
    {
        PCMCIA_WARNING("%s pcmcia read operation is failed!! , ret = 0x%X \n" ,
                       __FUNCTION__ , ret );
        return ret;
    }
	
    preempt_disable();
	//---------- Initial fifo control register -------------
    spin_lock_irqsave(&p_this->lock, irq_flags);

	ctrl  = GET_PCMCIA_CTRL() & ~(PC_ACCESS_INT | PC_FIFO_INT);
    ctrl |= p_this->reg_bits.CE;
	
	SET_PCMCIA_STS(PC_ACCESS_INT | PC_FIFO_INT);
    SET_PCMCIA_CTRL(ctrl);

	if (attr)
		fifo_ctrl = PC_ADDR_STEP(1);   // address step = 2
	else{
		fifo_ctrl = PC_ADDR_STEP(0);   // address step = 1
		rtd_outl(PCMCIA_REG_PIN_SEL, (rtd_inl(PCMCIA_REG_PIN_SEL)) | PC_INPACK0_DIS(1) | PC_WAIT0_DIS(0));
	}
	
	fifo_ctrl |= PC_WR_NUM(len) | PC_PIN_SHARE_SEL_SOFT_MODE | PC_FIFO_R_TRIG(0);
	
	if ((flags & PCMCIA_FLAGS_FIFO) || len==1)    
		fifo_ctrl |= PC_FIFO_WR_MODE_ADDRESS_NOCHANGE;  // FIFO mode, do not increase register address
	else
		fifo_ctrl |= PC_FIFO_WR_MODE_ADDRESS_INCREASE;
	
	SET_PCMCIA_FIFO_CTRL(fifo_ctrl | PC_FIFO_EN(1));   // enable fifo mode
	spin_unlock_irqrestore(&p_this->lock, irq_flags);
	
	ndelay(10);

	while(ret==PCMCIA_OK)
	{
		//---------- load fifo data if necessary -------------        
		if (len)
		{
			if (pcmcia_fifo_write_debug_enable)
			{
				PCMCIA_WARNING("going to write data(%d-%d) : STS = 0x%X, FIFO_CTRL=%08lx, FIFO_STATUS=%08lx, tx_bytes=%d!!!\n" ,					
					tx_round, sub_round,
					GET_PCMCIA_STS(), GET_PCMCIA_FIFO_CTRL(), GET_PCMCIA_FIFO_STATUS(), tx_bytes);
			}

			if (tx_bytes==0 || (GET_PCMCIA_STS() & PC_FIFO_W_IE))   // 1st write or FIFO_W enabled
			{
				int tx_len = (len > 32) ? 32 : len;

				spin_lock_irqsave(&p_this->lock, irq_flags);  // lock spinlock to make sure the following register access 
															// won't be affected by IRQ#
				if ((GET_PCMCIA_STS() & PC_FIFO_W_IE))
					SET_PCMCIA_STS(PC_FIFO_W_IE);

				if (__rtk_pcmcia_write_tx_fifo(cmd, p_data, tx_len)!=tx_len) 
				{
					spin_unlock_irqrestore(&p_this->lock, irq_flags);
				
					PCMCIA_ERROR("%s access pcmcia failed(%d-%d) - write %d bytes failed, STS = 0x%X, FIFO_CTRL=%08lx, FIFO_STATUS=%08lx, tx_bytes=%d!!!\n" ,
							__FUNCTION__ , tx_round, sub_round, 
							GET_PCMCIA_STS(), GET_PCMCIA_FIFO_CTRL(), GET_PCMCIA_FIFO_STATUS(),
							tx_bytes);

					ret = PCMCIA_FAIL;
					goto end_proc;
				}

				spin_unlock_irqrestore(&p_this->lock, irq_flags);
				len -= tx_len;
				p_data += tx_len;
				tx_bytes += tx_len;

				if (pcmcia_fifo_write_debug_enable)
				{
					PCMCIA_WARNING("after write data(%d-%d) : STS = 0x%X, FIFO_CTRL=%08lx, FIFO_STATUS=%08lx, tx_bytes=%d!!!\n" ,
						tx_round, sub_round,
						GET_PCMCIA_STS(), GET_PCMCIA_FIFO_CTRL(), GET_PCMCIA_FIFO_STATUS(), tx_bytes);     	
				}
			}
		}
		
		//---------- wait for interrupts -----------
		
		try_count = 3000;
		event = GET_PCMCIA_STS();
		while((event & PC_FIFO_TX_INT)==0 && try_count--) 
		{
			ndelay(300);
			event = GET_PCMCIA_STS();
		}
		
		if (pcmcia_fifo_write_debug_enable)
		{
			PCMCIA_WARNING("_rtk_pcmcia_fifo_write(%d-%d) : event=%08lx (%08lx) \n" , 
				tx_round, sub_round,
				event, (event & (PC_FIFO_R_IE | PC_FIFO_WR_OVER_IE)));        	
		}

		sub_round++;

		//---------- handle interrupts -----------
		if ((event & PC_FIFO_TX_INT)==0)
		{
				PCMCIA_ERROR("%s access pcmcia failed - wait WR_OVER interrupt timeout (%d-%d), STS = 0x%X, FIFO_CTRL=%08lx, FIFO_STATUS=%08lx, tx_bytes=%d!!!\n" ,
					__FUNCTION__ , tx_round, sub_round, 
					GET_PCMCIA_STS(), GET_PCMCIA_FIFO_CTRL(), GET_PCMCIA_FIFO_STATUS(),
					tx_bytes);
			ret = PCMCIA_FAIL;
			goto end_proc;
		}

		if ((event & PC_FIFO_ERRO_IE))
		{
			PCMCIA_ERROR("%s access pcmcia failed - FIFO ERROR STS=%08lx\n", 
				__FUNCTION__, event);
			ret = PCMCIA_FAIL;
			goto end_proc;
		}

		if ((event & PC_FIFO_WR_OVER_IE)) 
		{
			ret = tx_bytes;
			if (len) {
				PCMCIA_ERROR("%s access pcmcia failed - write imcomplete remain=%d\n", 
				__FUNCTION__, len);
				ret = PCMCIA_FAIL;
			}

			goto end_proc;
		}
	
		if ((GET_PCMCIA_STS() & PC_FIFO_W_IE))    // got write request, do next write     
			continue;
	}

end_proc:
	SET_PCMCIA_STS(PC_FIFO_TX_INT); 
    preempt_enable();
    rtk_pcmcia_stop_transfer(p_this, 1);
    return ret;
}



int rtk_pcmcia_fifo_write(RTK_PCMCIA *p_this, unsigned short addr,
			unsigned char *p_data, unsigned short len,
			unsigned long flags)
{
	int ret = PCMCIA_OK;
	int step = (flags & PCMCIA_FLAGS_FIFO) ? 0 : ((flags & PCMCIA_FLAGS_ATTR)) ? 2 : 1;                            

	while(len)
	{
		ret = _rtk_pcmcia_fifo_write(p_this, addr, p_data, len, flags);
		
		if (ret<=0) 
		{
			PCMCIA_WARNING("%s failed\n" , __FUNCTION__);
			return ret;
		}
		
		p_data+= ret;
		len   -= ret;
		addr  += ret * step ;
	}
	
	return PCMCIA_OK;
}


static inline int rtk_pcmcia_do_command(RTK_PCMCIA *p_this,
                                        unsigned long cmd,
                                        unsigned long ctrl)
{
    unsigned long event = 0;
    int wait_time = 20000;
    unsigned int fifo_ctrl = 0;
    ctrl &= ~PC_ACCESS_INT;
    ctrl |= p_this->reg_bits.CE;
#if 0
    if(g_auto_pinmux_enable)
        fifo_ctrl = GET_PCMCIA_FIFO_CTRL() & PC_PIN_SHARE_SEL_SOFT_MODE;
#else
    fifo_ctrl = GET_PCMCIA_FIFO_CTRL() & PC_PIN_SHARE_SEL_SOFT_MODE;

#endif
//  PCMCIA_WARNING("%s 1)  fifo_ctrl = 0x%X ,  0x%X  =  0x%X ! \n" , __FUNCTION__ , fifo_ctrl, 0xb801b71c  , rtd_inl(0xb801b71c)  );
    fifo_ctrl = fifo_ctrl | PC_FIFO_EN(0);
//  PCMCIA_WARNING("%s 2)fifo_ctrl = 0x%X  , x%X  =  0x%X ! \n" , __FUNCTION__ , fifo_ctrl ,  0xb801b71c  , rtd_inl(0xb801b71c)  );
    SET_PCMCIA_FIFO_CTRL(fifo_ctrl);
    SET_PCMCIA_STS(PC_ACCESS_INT);
    SET_PCMCIA_CTRL(ctrl);
    SET_PCMCIA_CMDFF(cmd);
    while (wait_time--)
    {
        event = GET_PCMCIA_STS();
        if (event & PC_ACCESS_INT)
            break;
        ndelay(100);
    }
    if (event & PC_APFI)
        return PCMCIA_OK;
    if (event & PC_AFI)
    {
        PCMCIA_WARNING("%s access pcmcia failed - Access Fault!!! , GET_PCMCIA_STS() = 0x%X \n" , __func__, GET_PCMCIA_STS() );
    }
    else
    {
        PCMCIA_WARNING("%s access pcmcia failed - Access Time Out!!! , GET_PCMCIA_STS() = 0x%X \n" ,__func__, GET_PCMCIA_STS() );
        /*rtk_pcmcia_phy_reset(); */
    }
    SET_PCMCIA_STS(PC_ACCESS_INT);
    return PCMCIA_FAIL;
}

int rtk_pcmcia_read(RTK_PCMCIA *p_this, unsigned short addr,
                    unsigned char *p_data, unsigned short len,
                    unsigned long flags)
{
    int ret = PCMCIA_OK;
    unsigned char attr = (flags & PCMCIA_FLAGS_ATTR) ? 1 : 0;
    unsigned long ctrl = GET_PCMCIA_CTRL();
        
    PCMCIA_DBG("rd %s %s, addr = %d, len=%d\n",
               (flags & PCMCIA_FLAGS_ATTR) ? "attr" : "io",
               (flags & PCMCIA_FLAGS_FIFO) ? "port" : "mem", addr, len);
    
    if ((p_this->flags & PCMCIA_CARD_RESET_COMPLETE)==0)
    {
        PCMCIA_WARNING("pcmcia read operation is failed!!, read data without card reset!!!\n");
        return PCMCIA_FAIL;
    }

    ret = rtk_pcmcia_start_transfer(p_this, 0);
    if (ret != PCMCIA_OK)
    {
        PCMCIA_WARNING("%s pcmcia read operation is failed!! , ret = 0x%X \n" , __func__,  ret );
        return ret;
    }
    preempt_disable();
    while (len && ret == PCMCIA_OK)
    {
        ret = rtk_pcmcia_do_command(p_this,
                                    PC_CT_READ | PC_AT(attr) |
                                    PC_PA(addr), ctrl);
        if (ret != PCMCIA_OK)
            break;
        *p_data = (unsigned char)(GET_PCMCIA_CMDFF() & 0xFF);

        /*PCMCIA_WARNING("%s MEM[%d] = %02x\n", (attr) ? "ATTR" : "IO", addr, *p_data); */
        p_data++;
        if ((flags & PCMCIA_FLAGS_FIFO) == 0)   /* sequential read */
            addr += (attr) ? 2 : 1;
        len--;
    }
    preempt_enable();
    rtk_pcmcia_stop_transfer(p_this, 0);
    return ret;
}

int rtk_pcmcia_write(RTK_PCMCIA *p_this, unsigned short addr,
                     unsigned char *p_data, unsigned short len,
                     unsigned long flags)
{
    int ret = PCMCIA_OK;
    unsigned char attr = (flags & PCMCIA_FLAGS_ATTR) ? 1 : 0;
    unsigned long ctrl = GET_PCMCIA_CTRL();
    PCMCIA_DBG("wr %s %s, addr = %d, len=%d\n",
               (flags & PCMCIA_FLAGS_ATTR) ? "attr" : "io",
               (flags & PCMCIA_FLAGS_FIFO) ? "mem" : "port", addr, len);

    if ((p_this->flags & PCMCIA_CARD_RESET_COMPLETE)==0)
    {
        PCMCIA_WARNING("pcmcia write operation is failed!!, write data without card reset!!!\n");
        return PCMCIA_FAIL;
    }

    ret = rtk_pcmcia_start_transfer(p_this, 0);
    preempt_disable();
    while (len && ret == PCMCIA_OK)
    {
        ret = rtk_pcmcia_do_command(p_this,
                                    PC_CT_WRITE | PC_AT(attr) |
                                    PC_PA(addr) | PC_DF(*p_data++),
                                    ctrl);

        if (ret != PCMCIA_OK)
            break;
        if ((flags & PCMCIA_FLAGS_FIFO) == 0)   /* sequential read */
            addr += (attr) ? 2 : 1;
        len--;
    }
    preempt_enable();
    rtk_pcmcia_stop_transfer(p_this, 0);
    return ret;
}


int rtk_pcmcia_card_reset(RTK_PCMCIA *p_this,
                          unsigned long CardResetTimeout)
{
    int ret = PCMCIA_FAIL;
    unsigned long timeout;
    unsigned long stime;

    if (!(rtk_pcmcia_get_card_status(p_this) &
            RTK_PCMCIA_STS_CARD_PRESENT))
    {

        PCMCIA_WARNING("hardware reset pcmcia (%d) failed - no card detected\n",
                       p_this->id);

        return PCMCIA_NODEV;
    }


    /* convert from ms to jiffes */
    PCMCIA_WARNING("reset pcmcia (%d) waiting for %lu ms \n", p_this->id,CardResetTimeout);

    CardResetTimeout *= HZ;
    CardResetTimeout /= 1000;
    LOCK_PCMCIA();
    SET_PCMCIA_STS(p_this->reg_bits.PII);
    SET_PCMCIA_CTRL((GET_PCMCIA_CTRL() &(~PC_PCR_SEL_MASK))
                    | PC_PCR_SEL(g_reset_pulse_width_type) | p_this->reg_bits.PCR);

    stime = jiffies;
    timeout = jiffies + CardResetTimeout;   /* timeout = 3 sec */
    while ((GET_PCMCIA_CTRL() & p_this->reg_bits.PCR)
            && time_before(jiffies, timeout))
        msleep(10);

    if ((GET_PCMCIA_CTRL() & p_this->reg_bits.PCR))
    {
        PCMCIA_WARNING("hardware reset pcmcia (%d) failed - timeout (%lu)\n",
                       p_this->id, ((jiffies - stime) * 1000) / HZ);
        goto end_proc;
    }
    msleep(1);

    if (!PCMCIA_INT_VALID(pcmcia_cfg2))
    {
        /*PC card asserts READY within 10us of RESET if it will not be ready for access after 20ms */
        while ((GET_PCMCIA_STS() & p_this->reg_bits.PII) &&
                time_before(jiffies, timeout))
            msleep(10);

        if ((GET_PCMCIA_STS() & p_this->reg_bits.PII))
        {
            ret = PCMCIA_FAIL;
            PCMCIA_WARNING("hardware reset pcmcia (%d) failed - wait PII timeout (%lu)\n",
                           p_this->id,
                           ((jiffies - stime) * 1000) / HZ);
            goto end_proc;
        }

        SET_PCMCIA_STS(p_this->reg_bits.PII);

    }
    else
    {
        /* polling int status */
        while ((0 == rtk_gpio_input(rtk_pcmcia_ptr->int_pin))
                && time_before(jiffies, timeout))
            msleep(10);

        if (0 == rtk_gpio_input(rtk_pcmcia_ptr->int_pin))
        {
            ret = PCMCIA_FAIL;
            PCMCIA_WARNING("hardware reset pcmcia (%d) failed - wait PII timeout (%lu)\n",
                           p_this->id, ((jiffies - stime) * 1000) / HZ);
            goto end_proc;
        }
    }

    p_this->flags |= PCMCIA_CARD_RESET_COMPLETE;
    PCMCIA_WARNING("hardware reset pcmcia (%d) successed (time= %lu ms)!!\n",
                   p_this->id, ((jiffies - stime) * 1000) / HZ);
    ret = PCMCIA_OK;
end_proc:
    UNLOCK_PCMCIA();


    if( PCMCIA_FAIL == ret && 1 == PCMCIA_RESET_WIHOUT_IREQ_CHECCK(pcmcia_cfg3) )
    {
        PCMCIA_WARNING("%s this card is has a long reset duration , but skip this situation!\n",
                       __func__ );
        ret = PCMCIA_OK;
    }

    return ret;
}

int rtk_pcmcia_card_enable(RTK_PCMCIA *p_this, unsigned char On)
{
    if (On)
    {
        PCMCIA_WARNING("enable card %d\n", p_this->id);
        if (!
                (rtk_pcmcia_get_card_status(p_this) &
                 RTK_PCMCIA_STS_CARD_PRESENT))
        {
            PCMCIA_WARNING("enable card %d failed, no card detected\n",
                           p_this->id);
            return PCMCIA_FAIL;
        }

        if (p_this->flags & PCMCIA_WITH_POWER_CTRL_GPIO)
        {
            rtk_gpio_set_dir(p_this->pwr_en_pin, 1);
            rtk_gpio_output(p_this->pwr_en_pin, 1);
            PCMCIA_WARNING("PCMCIA_PWR_EN GPIO : %s_GPIO %d=1\n",
                           gpio_type(gpio_group(p_this->pwr_en_pin)),
                           gpio_idx(p_this->pwr_en_pin));
        }
        msleep(2);
        SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() | p_this->
                        reg_bits.PCR_OE | p_this->reg_bits.PII);
        /*msleep(400); */
    }
    else
    {
        PCMCIA_WARNING("Card %d Disabled\n", p_this->id);
        SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() & ~p_this->reg_bits.PCR_OE);
        if (p_this->flags & PCMCIA_WITH_POWER_CTRL_GPIO)
        {

            rtk_gpio_set_dir(p_this->pwr_en_pin, 1);
            rtk_gpio_output(p_this->pwr_en_pin, 0);
            PCMCIA_WARNING("PCMCIA_PWR_EN GPIO : %s_GPIO %d=0\n",
                           gpio_type(gpio_group(p_this->pwr_en_pin)),
                           gpio_idx(p_this->pwr_en_pin));

            p_this->flags &= ~PCMCIA_CARD_RESET_COMPLETE;
        }
    }
    return PCMCIA_OK;
}

int rtk_pcmcia_enable(RTK_PCMCIA *p_this, unsigned char On)
{
    if (On)
    {
        /* enabled card detect interrupts  */
        SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() | p_this->reg_bits.CD_INT);
    }
    else
    {
        rtk_pcmcia_card_enable(p_this, 0);
        /* clear card detect interrupts   */
        SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() & ~p_this->reg_bits.CD_INT);
        wake_up(&p_this->wq);
    }
    return 0;
}



int rtk_pcmcia_poll_event(RTK_PCMCIA *p_this, unsigned long event_mask)
{
    int ret = 0;
    unsigned long flags = 0;

    POLL_EVENT_DBG("PollEvent=%x (%d)\n", event_mask, current->pid);

    if (!PCMCIA_INT_VALID(pcmcia_cfg2))
    {

        spin_lock_irqsave(&p_this->lock, flags);

        POLL_EVENT_DBG("PCMCIA STS=%x\n", GET_PCMCIA_STS());

        if ((GET_PCMCIA_STS() & p_this->reg_bits.PII))
            p_this->event |= RTK_PCMCIA_EVENT_IREQ_ASSERT;
        else
            p_this->event &= ~RTK_PCMCIA_EVENT_IREQ_ASSERT;

        if (event_mask && (p_this->event & event_mask) == 0)
        {
            if (event_mask & RTK_PCMCIA_EVENT_IREQ_ASSERT)
                SET_PCMCIA_CTRL(GET_PCMCIA_CTRL() |
                                (p_this->reg_bits.PII));    /* eanble PII interrupt  */
            
            POLL_EVENT_DBG("start wait interrupt, PCMCIA CTRL=%x, PCMCIA STS=%x\n", 
                GET_PCMCIA_CTRL(), GET_PCMCIA_STS());

            spin_unlock_irqrestore(&p_this->lock, flags);
            wait_event_interruptible_timeout(p_this->wq,
                                             p_this->event & event_mask, HZ);

            POLL_EVENT_DBG("wait interrupt complete, PCMCIA STS=%x\n", GET_PCMCIA_STS());                           
            spin_lock_irqsave(&p_this->lock, flags);

        }

        ret = (p_this->event & event_mask);
        p_this->event = 0;
        spin_unlock_irqrestore(&p_this->lock, flags);

    }
    else
    {
        spin_lock_irqsave(&p_this->lock, flags);
        POLL_EVENT_DBG("pcmcia_int_status = 0x%08X\n", p_this->event);

        if (RTK_PCMCIA_EVENT_IREQ_ASSERT & p_this->event)
        {
            ret |= RTK_PCMCIA_EVENT_IREQ_ASSERT;
            p_this->event &= ~RTK_PCMCIA_EVENT_IREQ_ASSERT;
        }
        else
        {
            ret &= ~RTK_PCMCIA_EVENT_IREQ_ASSERT;
        }

        POLL_EVENT_DBG("pcmcia_int_status = 0x%08X  , ret = 0x%08X  \n",
                    p_this->event, ret);

        spin_unlock_irqrestore(&p_this->lock, flags);
    }

    POLL_EVENT_DBG("ExitPollEvent=%d  (%d)\n", ret, current->pid);
    return ret;
}

/*-----------------------------------------------------------------------------------
 * File Operations
 *------------------------------------------------------------------------------------*/
int rtk_pcmcia_open(struct inode *inode, struct file *file)
{
    RTK_PCMCIA *p_this = (RTK_PCMCIA *) rtk_pcmcia[0];
    file->private_data = (void *)p_this;
    if (p_this)
    {
        rtk_pcmcia_enable(p_this, 1);
        return 0;
    }
    return -ENOMEM;
}

int rtk_pcmcia_release(struct inode *inode, struct file *file)
{
    RTK_PCMCIA *p_this = (RTK_PCMCIA *) file->private_data;
    rtk_pcmcia_enable(p_this, 0);
    file->private_data = NULL;
    return 0;
}

int rtk_pcmcia_ioctrl_init(RTK_PCMCIA* p_this)
{

    PCMCIA_WARNING("pcmcia_ioctrl_init = 0x%08X  \n" ,
                   atomic_read(&p_this->atomic_init) );

    if ( atomic_read(&p_this->atomic_init) == 1 )
    {
        return -1;
    }
    else
    {
        atomic_set(&p_this->atomic_init, 1);
        return 0;
    }

    return -1;

}

int rtk_pcmcia_ioctrl_deinit(RTK_PCMCIA* p_this)
{

    PCMCIA_WARNING("pcmcia_ioctrl_init = 0x%08X  \n" ,atomic_read(&p_this->atomic_init) );

    if (atomic_read(&p_this->atomic_init) == 1 )
    {
        atomic_set(&p_this->atomic_init, 0);
        return 0;
    }

    return -1;
}


static long rtk_pcmcia_ioctl(struct file *file, unsigned int cmd,
                             unsigned long arg)
{
    RTK_PCMCIA *p_this = (RTK_PCMCIA *) file->private_data;
    RTK_PCMCIA_RW rw_cmd;
    RTK_PCMCIA_MULTI_RW multi_rw_cmd;

    int ret = -ENOTTY;
    unsigned long CardResetTimeout = DEFAULT_PCMCIA_RESET_TIMEOUT;

    mutex_lock(&rtk_pcmcia_ioctl_lock);

    switch (cmd)
    {
    case RTK_PCMCIA_IOC_ENABLE:
        ret = rtk_pcmcia_card_enable(p_this, (arg) ? 1 : 0);
        break;
    case RTK_PCMCIA_IOC_CARD_RESET:

        PCMCIA_WARNING ("%s  RTK_PCMCIA_IOC_CARD_RESET , %d ms\n" , __func__ , arg );

        if (arg)
        {
            if (arg < MINIMUM_PCMCIA_RESET_TIMEOUT)
                CardResetTimeout = MINIMUM_PCMCIA_RESET_TIMEOUT;
            else if (arg > MAXIMUM_PCMCIA_RESET_TIMEOUT)
                CardResetTimeout = MAXIMUM_PCMCIA_RESET_TIMEOUT;
            else
                CardResetTimeout = arg;
        }
        ret = rtk_pcmcia_card_reset(p_this, CardResetTimeout);
        break;

    case RTK_PCMCIA_IOC_GET_CARD_STATUS:

        ret = rtk_pcmcia_get_card_status(p_this);

        if( 1 == bRtkPcmciaResume )
        {
            ret |= RTK_PCMCIA_STS_DC_OFF_ON;
            bRtkPcmciaResume = 0;
            PCMCIA_WARNING("DC on/off happened!\n");
        }
        break;

    case RTK_PCMCIA_IOC_READ_WRITE:
        if (!(rtk_pcmcia_get_card_status(p_this) & RTK_PCMCIA_STS_CARD_PRESENT)) {
            PCMCIA_DBG("%s access pcmcia failed - no card exists!!!\n" , __func__ );
            ret = -EFAULT;
            break;
        }

        if (copy_from_user
                (&rw_cmd, (void __user *)arg, sizeof(RTK_PCMCIA_RW)))
        {
            PCMCIA_WARNING ("read write PCMCIA failed, copy data from user space failed\n");
            ret = -EFAULT;
            break;
        }

        if (rw_cmd.flags & PCMCIA_FLAGS_RD)
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_read(p_this,
                                           rw_cmd.addr, &rw_cmd.data,
                                           1, rw_cmd.flags);
            else
                ret = rtk_pcmcia_read(p_this, rw_cmd.addr,
                                      &rw_cmd.data,
                                      1, rw_cmd.flags);
            if (ret == PCMCIA_OK)
            {
                if (copy_to_user
                        ((void __user *)arg, &rw_cmd,
                         sizeof(RTK_PCMCIA_RW)))
                {
                    PCMCIA_WARNING("read write PCMCIA failed, copy data to user space failed\n");
                    ret = -EFAULT;
                    break;
                }
            }
        }
        else
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_write(p_this,
                                            rw_cmd.addr,
                                            &rw_cmd.data,
                                            1, rw_cmd.flags);
            else
                ret = rtk_pcmcia_write(p_this, rw_cmd.addr,
                                       &rw_cmd.data,
                                       1, rw_cmd.flags);
        }
        break;
    case RTK_PCMCIA_IOC_MULTI_READ_WRITE:

        if (!(rtk_pcmcia_get_card_status(p_this) & RTK_PCMCIA_STS_CARD_PRESENT)) {
            PCMCIA_DBG("%s access pcmcia failed - no card exists!!!\n" , __func__ );
            ret = -EFAULT;
            break;
        }

        if (copy_from_user(&multi_rw_cmd, (void __user *)arg,
                           sizeof(RTK_PCMCIA_MULTI_RW)))
        {
            PCMCIA_WARNING("read write PCMCIA failed, copy data from user space failed\n");
            ret = -EFAULT;
            break;
        }
        if (multi_rw_cmd.len > sizeof(p_this->buff))
        {
            PCMCIA_WARNING("read write PCMCIA failed, data size large than %u\n",
                           sizeof(p_this->buff));
            ret = -EFAULT;
            break;
        }
        if (multi_rw_cmd.flags & PCMCIA_FLAGS_RD)
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_read(p_this,
                                           multi_rw_cmd.addr,
                                           p_this->buff, multi_rw_cmd.len,
                                           multi_rw_cmd.flags);
            else
                ret = rtk_pcmcia_read(p_this,
                                      multi_rw_cmd.addr,
                                      p_this->buff, multi_rw_cmd.len,
                                      multi_rw_cmd.flags);
            if (ret == PCMCIA_OK)
            {
                if (copy_to_user
                        ((void __user *)multi_rw_cmd.p_data, p_this->buff,
                         multi_rw_cmd.len))
                {
                    PCMCIA_WARNING("read write PCMCIA failed, copy data to user space failed\n");
                    ret = -EFAULT;
                    break;
                }
            }
        }
        else
        {
            if (copy_from_user
                    (&p_this->buff, (void __user *)multi_rw_cmd.p_data,
                     multi_rw_cmd.len))
            {
                PCMCIA_WARNING("read write PCMCIA failed, copy data from user space failed\n");
                ret = -EFAULT;
                break;
            }
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_write(p_this,
                                            multi_rw_cmd.addr,
                                            p_this->buff,
                                            multi_rw_cmd.len,
                                            multi_rw_cmd.flags);
            else
                ret = rtk_pcmcia_write(p_this,
                                       multi_rw_cmd.addr,
                                       p_this->buff,
                                       multi_rw_cmd.len,
                                       multi_rw_cmd.flags);

        }
        break;
    case RTK_PCMCIA_IOC_PROBE_COMMAND:
        switch (arg)
        {
        case RTK_PCMCIA_IOC_ENABLE:
        case RTK_PCMCIA_IOC_CARD_RESET:
        case RTK_PCMCIA_IOC_GET_CARD_STATUS:
        case RTK_PCMCIA_IOC_READ_WRITE:
        case RTK_PCMCIA_IOC_MULTI_READ_WRITE:
        case RTK_PCMCIA_IOC_PROBE_COMMAND:
        case RTK_PCMCIA_IOC_POLL_EVENT:
            ret = 0;
            break;
        case RTK_PCMCIA_IOC_INIT_COMMAND:
            ret = rtk_pcmcia_ioctrl_init(p_this);
            break;
        case RTK_PCMCIA_IOC_DEINIT_COMMAND:
            ret = rtk_pcmcia_ioctrl_deinit(p_this);
            break;
        default:
            ret = -EFAULT;
        }
        break;

    case RTK_PCMCIA_IOC_POLL_EVENT:
        mutex_unlock(&rtk_pcmcia_ioctl_lock);    // unlock mutex to make sure other request won't be b;pcled
        ret = rtk_pcmcia_poll_event(p_this, arg);
        mutex_lock(&rtk_pcmcia_ioctl_lock);
        break;

    default:
        PCMCIA_WARNING("do ioctl failed, invalid command - %x\n", cmd);
    }

    mutex_unlock(&rtk_pcmcia_ioctl_lock);

    return ret;
}

#ifdef CONFIG_COMPAT
static long rtk_pcmcia_compat_ioctl(struct file *file, unsigned int cmd,
                                    unsigned long arg)
{
    RTK_PCMCIA *p_this = (RTK_PCMCIA *) file->private_data;
    RTK_PCMCIA_RW rw_cmd;
    COMPAT_RTK_PCMCIA_MULTI_RW multi_rw_cmd;

    int ret = -ENOTTY;
    unsigned long CardResetTimeout = DEFAULT_PCMCIA_RESET_TIMEOUT;
    switch (cmd)
    {
    case RTK_PCMCIA_IOC_ENABLE:
        return rtk_pcmcia_card_enable(p_this, (arg) ? 1 : 0);
    case RTK_PCMCIA_IOC_CARD_RESET:
        if (arg)
        {
            if (arg < MINIMUM_PCMCIA_RESET_TIMEOUT)
                CardResetTimeout = MINIMUM_PCMCIA_RESET_TIMEOUT;
            else if (arg > MAXIMUM_PCMCIA_RESET_TIMEOUT)
                CardResetTimeout = MAXIMUM_PCMCIA_RESET_TIMEOUT;
            else
                CardResetTimeout = arg;
        }
        ret = rtk_pcmcia_card_reset(p_this, CardResetTimeout);
        return ret;
    case RTK_PCMCIA_IOC_GET_CARD_STATUS:
        return rtk_pcmcia_get_card_status(p_this);
    case COMPAT_RTK_PCMCIA_IOC_READ_WRITE:
        if (copy_from_user
                (&rw_cmd, (void __user *)arg, sizeof(RTK_PCMCIA_RW)))
        {
            PCMCIA_WARNING
            ("read write PCMCIA failed, copy data from user space failed\n");
            return -EFAULT;
        }
        if (rw_cmd.flags & PCMCIA_FLAGS_RD)
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_read(p_this, rw_cmd.addr, &rw_cmd.data,
                                           1, rw_cmd.flags);
            else
                ret = rtk_pcmcia_read(p_this, rw_cmd.addr, &rw_cmd.data,
                                      1, rw_cmd.flags);
            if (ret == PCMCIA_OK)
            {
                if (copy_to_user
                        ((void __user *)arg, &rw_cmd,
                         sizeof(RTK_PCMCIA_RW)))
                {
                    PCMCIA_WARNING
                    ("read write PCMCIA failed, copy data to user space failed\n");
                    return -EFAULT;
                }
            }
        }
        else
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_write(p_this, rw_cmd.addr, &rw_cmd.data,
                                            1, rw_cmd.flags);
            else
                ret = rtk_pcmcia_write(p_this, rw_cmd.addr, &rw_cmd.data,
                                       1, rw_cmd.flags);
        }
        break;
    case COMPAT_RTK_PCMCIA_IOC_MULTI_READ_WRITE:
        if (copy_from_user(&multi_rw_cmd, compat_ptr(arg),
                           sizeof(COMPAT_RTK_PCMCIA_MULTI_RW)))
        {
            PCMCIA_WARNING
            ("read write PCMCIA failed, copy data from user space failed\n");
            return -EFAULT;
        }
        if (multi_rw_cmd.len > sizeof(p_this->buff))
        {
            PCMCIA_WARNING
            ("read write PCMCIA failed, data size large than %u\n",
             sizeof(p_this->buff));
            return -EFAULT;
        }
        if (multi_rw_cmd.flags & PCMCIA_FLAGS_RD)
        {
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_read(p_this,
                                           multi_rw_cmd.addr,
                                           p_this->buff, multi_rw_cmd.len,
                                           multi_rw_cmd.flags);
            else
                ret = rtk_pcmcia_read(p_this,
                                      multi_rw_cmd.addr,
                                      p_this->buff, multi_rw_cmd.len,
                                      multi_rw_cmd.flags);
            if (ret == PCMCIA_OK)
            {
                if (copy_to_user
                        (compat_ptr(multi_rw_cmd.p_data), p_this->buff,
                         multi_rw_cmd.len))
                {
                    PCMCIA_WARNING
                    ("read write PCMCIA failed, copy data to user space failed\n");
                    return -EFAULT;
                }
            }
        }
        else
        {
            if (copy_from_user
                    (&p_this->buff, compat_ptr(multi_rw_cmd.p_data),
                     multi_rw_cmd.len))
            {
                PCMCIA_WARNING
                ("read write PCMCIA failed, copy data from user space failed\n");
                return -EFAULT;
            }
            if (pcmcia_fifo_mode_enable)
                ret = rtk_pcmcia_fifo_write(p_this,
                                            multi_rw_cmd.addr,
                                            p_this->buff,
                                            multi_rw_cmd.len,
                                            multi_rw_cmd.flags);
            else
                ret = rtk_pcmcia_write(p_this,
                                       multi_rw_cmd.addr,
                                       p_this->buff,
                                       multi_rw_cmd.len,
                                       multi_rw_cmd.flags);

        }
        break;
    case COMPAT_RTK_PCMCIA_IOC_PROBE_COMMAND:
        switch (arg)
        {
        case RTK_PCMCIA_IOC_ENABLE:
        case RTK_PCMCIA_IOC_CARD_RESET:
        case RTK_PCMCIA_IOC_GET_CARD_STATUS:
        case COMPAT_RTK_PCMCIA_IOC_READ_WRITE:
        case COMPAT_RTK_PCMCIA_IOC_MULTI_READ_WRITE:
        case COMPAT_RTK_PCMCIA_IOC_PROBE_COMMAND:
        case COMPAT_RTK_PCMCIA_IOC_POLL_EVENT:
            return 0;
        default:
            ret = -EFAULT;
        }
        break;
    case COMPAT_RTK_PCMCIA_IOC_POLL_EVENT:
        ret = rtk_pcmcia_poll_event(p_this, arg);
        break;
    case COMPAT_RTK_PCMCIA_IOC_INIT_COMMAND:
        return rtk_pcmcia_ioctrl_init(p_this);
    case COMPAT_RTK_PCMCIA_IOC_DEINIT_COMMAND:
        return rtk_pcmcia_ioctrl_deinit(p_this);
    default:
        PCMCIA_WARNING("%s, do ioctl failed, invalid command - %x\n", __FUNCTION__, cmd);
    }
    return ret;
}
#endif

static struct file_operations rtk_pcmcia_fops =
{
    .owner = THIS_MODULE,
    .unlocked_ioctl = rtk_pcmcia_ioctl,
    .open = rtk_pcmcia_open,
    .release = rtk_pcmcia_release,
#ifdef CONFIG_COMPAT
    .compat_ioctl = rtk_pcmcia_compat_ioctl,
#endif
};

/***************************************************************************
*------------------- Power Management ----------------
****************************************************************************/

static struct platform_device *pcmcia_platform_dev;

#ifdef CONFIG_PM
static int pcmcia_suspend(struct platform_device *dev, pm_message_t state)
{
    PCMCIA_WARNING("suspended\n");
    rtk_pcmcia_enable((RTK_PCMCIA *) (pcmcia_platform_dev->id), 0);

    if (PCMCIA_INT_VALID(pcmcia_cfg2))
    {
        rtk_gpio_set_irq_enable(rtk_pcmcia_ptr->int_pin, 0);
        rtk_gpio_clear_isr(rtk_pcmcia_ptr->int_pin);
        rtk_gpio_free_irq(rtk_pcmcia_ptr->int_pin, rtk_pcmcia_gpio_int_isr);
    }
    bRtkPcmciaResume = 1;

    return 0;
}

static int pcmcia_resume(struct platform_device *dev)
{
    PCMCIA_WARNING("resumed\n");
    PCMCIA_ClockEnable(1);     /*  enable PCMCIA clock */
    rtk_pcmcia_phy_reset();

    if (PCMCIA_INT_VALID(pcmcia_cfg2))
    {
        rtk_pcmcia_int_gpio_set();
    }
    rtd_outl(PCMCIA_REG_PIN_SEL, (rtd_inl(PCMCIA_REG_PIN_SEL))
             | PC_INPACK0_DIS(1) | PC_WAIT0_DIS(0));
    SET_PCMCIA_AMTC_0(pcmcia_amtc0);
    SET_PCMCIA_AMTC_1(pcmcia_amtc1);
    SET_PCMCIA_IOMTC(pcmcia_iomtc);
    SET_PCMCIA_MATC_0(pcmcia_matc0);
    SET_PCMCIA_MATC_1(pcmcia_matc1);
    return 0;
}

#endif

static struct platform_driver pcmcia_platform_drv =
{
#ifdef CONFIG_PM
    .suspend = pcmcia_suspend,
    .resume = pcmcia_resume,
#endif
    .driver = {
        .name = "PCMCIA",
        .bus = &platform_bus_type,
    }
};



/*
 *Device Attribute
 */
ssize_t rtk_pcmcia_show_param(struct device *dev,
                              struct device_attribute *attr, char *buf)
{
    int ret = -1;
    if (strncmp(attr->attr.name, "amtc0", 5) == 0)
    {
        pcmcia_amtc0 = GET_PCMCIA_AMTC_0();
        ret = sprintf(buf, "%08lx\n", pcmcia_amtc0);
    }
    else if (strncmp(attr->attr.name, "amtc1", 5) == 0)
    {
        pcmcia_amtc1 = GET_PCMCIA_AMTC_1();
        ret = sprintf(buf, "%08lx\n", pcmcia_amtc1);
    }
    else if (strncmp(attr->attr.name, "iomtc", 5) == 0)
    {
        pcmcia_iomtc = GET_PCMCIA_IOMTC();
        ret = sprintf(buf, "%08lx\n", pcmcia_iomtc);
    }
    else if (strncmp(attr->attr.name, "matc0", 5) == 0)
    {
        pcmcia_matc0 = GET_PCMCIA_MATC_0();
        ret = sprintf(buf, "%08lx\n", pcmcia_matc0);
    }
    else if (strncmp(attr->attr.name, "matc1", 5) == 0)
    {
        pcmcia_matc1 = GET_PCMCIA_MATC_1();
        ret = sprintf(buf, "%08lx\n", pcmcia_matc1);
    }
    else if (strncmp(attr->attr.name, "debug_ctrl", 10) == 0)
    {
        int len = 0;
        ret = sprintf(buf, "force_disconnect=%d\n", (((rtd_inl(0xb8000830) >> 20) & 0xF)!=1) ? 1 : 0);
        buf += ret; len += ret;
        ret = sprintf(buf, "fifo_mode_en=%x\n", pcmcia_fifo_mode_enable);
        buf += ret; len += ret;
        ret = sprintf(buf, "fifo_rd_dbg_en=%x\n", pcmcia_fifo_read_debug_enable);
        buf += ret; len += ret;
        ret = sprintf(buf, "fifo_wr_dbg_en=%x\n", pcmcia_fifo_write_debug_enable);              
        len += ret;
        ret = len;
    }
    else if (strncmp(attr->attr.name, "reset_pulse_width", 17) == 0)
    {
        ret = sprintf(buf, "cur:%s (114us/1ms/2ms/20ms)\n", get_reset_pulse_width_info(g_reset_pulse_width_type));
    }
    return ret;
}

ssize_t rtk_pcmcia_set_param(struct device *dev,
                             struct device_attribute *attr,
                             const char *buf, size_t count)
{
    char str[32];
    unsigned long val;
    if (strncmp(attr->attr.name, "amtc0", 5) == 0)
    {
        if (sscanf(buf, "%lx", &val) == 1)
        {
            SET_PCMCIA_AMTC_0(val);
            pcmcia_amtc0 = val;
        }
    }
    else if (strncmp(attr->attr.name, "amtc1", 5) == 0)
    {
        if (sscanf(buf, "%lx", &val) == 1)
        {
            SET_PCMCIA_AMTC_1(val);
            pcmcia_amtc1 = val;
        }
    }
    else if (strncmp(attr->attr.name, "iomtc", 5) == 0)
    {
        if (sscanf(buf, "%lx", &val) == 1)
        {
            SET_PCMCIA_IOMTC(val);
            pcmcia_iomtc = val;
        }
    }
    else if (strncmp(attr->attr.name, "matc0", 5) == 0)
    {
        if (sscanf(buf, "%lx", &val) == 1)
        {
            SET_PCMCIA_MATC_0(val);
            pcmcia_matc0 = val;
        }
    }
    else if (strncmp(attr->attr.name, "matc1", 5) == 0)
    {
        if (sscanf(buf, "%lx", &val) == 1)
        {
            SET_PCMCIA_MATC_1(val);
            pcmcia_matc1 = val;
        }
    }
    else if (strncmp(attr->attr.name, "debug_ctrl", 10) == 0)
    {
        if (sscanf(buf, "fifo_mode_en=%lu", &val) == 1)
        {
            pcmcia_fifo_mode_enable = (val) ? 1 : 0;
        }
        else if (sscanf(buf, "fifo_rd_dbg_en=%lu", &val) == 1)
        {
            pcmcia_fifo_read_debug_enable = (val) ? 1 : 0;
        }
        else if (sscanf(buf, "fifo_wr_dbg_en=%lu", &val) == 1)
        {
            pcmcia_fifo_write_debug_enable = (val) ? 1 : 0;
        }
        else if (sscanf(buf, "force_disconnect=%lu", &val) == 1) 
        {
            if (val)
                rtd_outl(0xb8000830, rtd_inl(0xb8000830) | (0xF<<20));
            else
                rtd_outl(0xb8000830, (rtd_inl(0xb8000830) & ~(0xF<<20)) | (1<<20));
        }
        else
        {
            PCMCIA_WARNING("invalid command - %s\n", buf);
        }
    }
    else if (strncmp(attr->attr.name, "reset_pulse_width", 17) == 0)
    {

        if (sscanf(buf, "%32s", &str)!=1)
            return -1;

        if(strcmp(str, "114us") == 0)
            g_reset_pulse_width_type = RTK_PCMCIA_RESET_PULSE_WIDTH_114US;
        else if(strcmp(str, "1ms") == 0)
            g_reset_pulse_width_type = RTK_PCMCIA_RESET_PULSE_WIDTH_1MS;
        else if(strcmp(str, "2ms") == 0)
            g_reset_pulse_width_type = RTK_PCMCIA_RESET_PULSE_WIDTH_2MS;
        else if(strcmp(str, "20ms") == 0)
            g_reset_pulse_width_type = RTK_PCMCIA_RESET_PULSE_WIDTH_20MS;
        else
            printk("unknown paluse width - %s\n", str);
    }
    return count;
}

DEVICE_ATTR(amtc0, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(amtc1, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(iomtc, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(matc0, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(matc1, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(debug_ctrl, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
        rtk_pcmcia_show_param, rtk_pcmcia_set_param);
DEVICE_ATTR(reset_pulse_width, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,
            rtk_pcmcia_show_param, rtk_pcmcia_set_param);

/*
 * module Init
 */
static struct miscdevice rtk_pcmcia_miscdev =
{
    MISC_DYNAMIC_MINOR,
    "pcmcia-0",
    &rtk_pcmcia_fops
};


static void mac5p_pcmcia_pinmux_set(void)
{
#ifdef Mac5p_DEMO_PCB
    PCMCIA_WARNING("\n %s before setting start\n" , __func__);
    PCMCIA_WARNING("address 0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_0_UP , PCMCIA_ADDRESS_0_LOW,  PCMCIA_ADDRESS_0_REG, rtd_part_inl(PCMCIA_ADDRESS_0_REG , PCMCIA_ADDRESS_0_UP , PCMCIA_ADDRESS_0_LOW ) );
    PCMCIA_WARNING("address 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_1_UP , PCMCIA_ADDRESS_1_LOW,  PCMCIA_ADDRESS_1_REG, rtd_part_inl(PCMCIA_ADDRESS_1_REG , PCMCIA_ADDRESS_1_UP , PCMCIA_ADDRESS_1_LOW ) );
    PCMCIA_WARNING("address 2 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_2_UP , PCMCIA_ADDRESS_2_LOW,  PCMCIA_ADDRESS_2_REG, rtd_part_inl(PCMCIA_ADDRESS_2_REG , PCMCIA_ADDRESS_2_UP , PCMCIA_ADDRESS_2_LOW ) );
    PCMCIA_WARNING("address 3 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_3_UP , PCMCIA_ADDRESS_3_LOW,  PCMCIA_ADDRESS_3_REG, rtd_part_inl(PCMCIA_ADDRESS_3_REG , PCMCIA_ADDRESS_3_UP , PCMCIA_ADDRESS_3_LOW ) );
    PCMCIA_WARNING("address 4 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_4_UP , PCMCIA_ADDRESS_4_LOW,  PCMCIA_ADDRESS_4_REG, rtd_part_inl(PCMCIA_ADDRESS_4_REG , PCMCIA_ADDRESS_4_UP , PCMCIA_ADDRESS_4_LOW ) );
    PCMCIA_WARNING("address 5 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_5_UP , PCMCIA_ADDRESS_5_LOW,  PCMCIA_ADDRESS_5_REG, rtd_part_inl(PCMCIA_ADDRESS_5_REG , PCMCIA_ADDRESS_5_UP , PCMCIA_ADDRESS_5_LOW ) );
    PCMCIA_WARNING("address 6 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_6_UP , PCMCIA_ADDRESS_6_LOW,  PCMCIA_ADDRESS_6_REG, rtd_part_inl(PCMCIA_ADDRESS_6_REG , PCMCIA_ADDRESS_6_UP , PCMCIA_ADDRESS_6_LOW ) );
    PCMCIA_WARNING("address 7 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_7_UP , PCMCIA_ADDRESS_7_LOW,  PCMCIA_ADDRESS_7_REG, rtd_part_inl(PCMCIA_ADDRESS_7_REG , PCMCIA_ADDRESS_7_UP , PCMCIA_ADDRESS_7_LOW ) );
    PCMCIA_WARNING("address 8 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_8_UP , PCMCIA_ADDRESS_8_LOW,  PCMCIA_ADDRESS_8_REG, rtd_part_inl(PCMCIA_ADDRESS_8_REG , PCMCIA_ADDRESS_8_UP , PCMCIA_ADDRESS_8_LOW ) );
    PCMCIA_WARNING("address 9 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_9_UP , PCMCIA_ADDRESS_9_LOW,  PCMCIA_ADDRESS_9_REG, rtd_part_inl(PCMCIA_ADDRESS_9_REG , PCMCIA_ADDRESS_9_UP , PCMCIA_ADDRESS_9_LOW ) );
    PCMCIA_WARNING("address 10 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_10_UP , PCMCIA_ADDRESS_10_LOW,  PCMCIA_ADDRESS_10_REG, rtd_part_inl(PCMCIA_ADDRESS_10_REG , PCMCIA_ADDRESS_10_UP , PCMCIA_ADDRESS_10_LOW ) );
    PCMCIA_WARNING("address 11 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_11_UP , PCMCIA_ADDRESS_11_LOW,  PCMCIA_ADDRESS_11_REG, rtd_part_inl(PCMCIA_ADDRESS_11_REG , PCMCIA_ADDRESS_11_UP , PCMCIA_ADDRESS_11_LOW ) );
    PCMCIA_WARNING("address 12 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_12_UP , PCMCIA_ADDRESS_12_LOW,  PCMCIA_ADDRESS_12_REG, rtd_part_inl(PCMCIA_ADDRESS_12_REG , PCMCIA_ADDRESS_12_UP , PCMCIA_ADDRESS_12_LOW ) );
    PCMCIA_WARNING("address 13 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_13_UP , PCMCIA_ADDRESS_13_LOW,  PCMCIA_ADDRESS_13_REG, rtd_part_inl(PCMCIA_ADDRESS_13_REG , PCMCIA_ADDRESS_13_UP , PCMCIA_ADDRESS_13_LOW ) );
    PCMCIA_WARNING("address 14 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_14_UP , PCMCIA_ADDRESS_14_LOW,  PCMCIA_ADDRESS_14_REG, rtd_part_inl(PCMCIA_ADDRESS_14_REG , PCMCIA_ADDRESS_14_UP , PCMCIA_ADDRESS_14_LOW ) );

    PCMCIA_WARNING("data 0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_0_UP , PCMCIA_DATA_0_LOW,  PCMCIA_DATA_0_REG, rtd_part_inl(PCMCIA_DATA_0_REG , PCMCIA_DATA_0_UP , PCMCIA_DATA_0_LOW ) );
    PCMCIA_WARNING("data 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_1_UP , PCMCIA_DATA_1_LOW,  PCMCIA_DATA_1_REG, rtd_part_inl(PCMCIA_DATA_1_REG , PCMCIA_DATA_1_UP , PCMCIA_DATA_1_LOW ) );
    PCMCIA_WARNING("data 2 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_2_UP , PCMCIA_DATA_2_LOW,  PCMCIA_DATA_2_REG, rtd_part_inl(PCMCIA_DATA_2_REG , PCMCIA_DATA_2_UP , PCMCIA_DATA_2_LOW ) );
    PCMCIA_WARNING("data 3 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_3_UP , PCMCIA_DATA_3_LOW,  PCMCIA_DATA_3_REG, rtd_part_inl(PCMCIA_DATA_3_REG , PCMCIA_DATA_3_UP , PCMCIA_DATA_3_LOW ) );
    PCMCIA_WARNING("data 4 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_4_UP , PCMCIA_DATA_4_LOW,  PCMCIA_DATA_4_REG, rtd_part_inl(PCMCIA_DATA_4_REG , PCMCIA_DATA_4_UP , PCMCIA_DATA_4_LOW ) );
    PCMCIA_WARNING("data 5 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_5_UP , PCMCIA_DATA_5_LOW,  PCMCIA_DATA_5_REG, rtd_part_inl(PCMCIA_DATA_5_REG , PCMCIA_DATA_5_UP , PCMCIA_DATA_5_LOW ) );
    PCMCIA_WARNING("data 6 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_6_UP , PCMCIA_DATA_6_LOW,  PCMCIA_DATA_6_REG, rtd_part_inl(PCMCIA_DATA_6_REG , PCMCIA_DATA_6_UP , PCMCIA_DATA_6_LOW ) );
    PCMCIA_WARNING("data 7 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_7_UP , PCMCIA_DATA_7_LOW,  PCMCIA_DATA_7_REG, rtd_part_inl(PCMCIA_DATA_7_REG , PCMCIA_DATA_7_UP , PCMCIA_DATA_7_LOW ) );

    PCMCIA_WARNING("REG , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_REG_UP , PCMCIA_REG_LOW,  PCMCIA_REG_REG, rtd_part_inl(PCMCIA_REG_REG , PCMCIA_REG_UP , PCMCIA_REG_LOW ) );
    PCMCIA_WARNING("CE 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_CE1_UP , PCMCIA_CE1_LOW,  PCMCIA_CE1_REG, rtd_part_inl(PCMCIA_CE1_REG , PCMCIA_CE1_UP , PCMCIA_CE1_LOW ) );
    PCMCIA_WARNING("OE  , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_OE_UP , PCMCIA_OE_LOW,  PCMCIA_OE_REG, rtd_part_inl(PCMCIA_OE_REG , PCMCIA_OE_UP , PCMCIA_OE_LOW ) );
    PCMCIA_WARNING("WE , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_WE_UP , PCMCIA_WE_LOW,  PCMCIA_WE_REG, rtd_part_inl(PCMCIA_WE_REG , PCMCIA_WE_UP , PCMCIA_WE_LOW ) );
    PCMCIA_WARNING("IORD , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IORD_UP , PCMCIA_IORD_LOW,  PCMCIA_IORD_REG, rtd_part_inl(PCMCIA_IORD_REG , PCMCIA_IORD_UP , PCMCIA_IORD_LOW ) );
    PCMCIA_WARNING("IOWR , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IOWR_UP , PCMCIA_IOWR_LOW,  PCMCIA_IOWR_REG, rtd_part_inl(PCMCIA_IOWR_REG , PCMCIA_IOWR_UP , PCMCIA_IOWR_LOW ) );
    PCMCIA_WARNING("INPACK0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_INPACK0_UP , PCMCIA_INPACK0_LOW,  PCMCIA_INPACK0_REG, rtd_part_inl(PCMCIA_INPACK0_REG , PCMCIA_INPACK0_UP , PCMCIA_INPACK0_LOW ) );
    PCMCIA_WARNING("WAIT0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_WAIT0_UP , PCMCIA_WAIT0_LOW,  PCMCIA_WAIT0_REG, rtd_part_inl(PCMCIA_WAIT0_REG , PCMCIA_WAIT0_UP , PCMCIA_WAIT0_LOW ) );
    PCMCIA_WARNING("RESET0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_RESET0_UP , PCMCIA_RESET0_LOW,  PCMCIA_RESET0_REG, rtd_part_inl(PCMCIA_RESET0_REG , PCMCIA_RESET0_UP , PCMCIA_RESET0_LOW ) );
    PCMCIA_WARNING("CD0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_CD0_UP , PCMCIA_CD0_LOW,  PCMCIA_CD0_REG, rtd_part_inl(PCMCIA_CD0_REG , PCMCIA_CD0_UP , PCMCIA_CD0_LOW ) );
    PCMCIA_WARNING("IREQ0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IREQ0_UP , PCMCIA_IREQ0_LOW,  PCMCIA_IREQ0_REG, rtd_part_inl(PCMCIA_IREQ0_REG , PCMCIA_IREQ0_UP , PCMCIA_IREQ0_LOW ) );
    /**MODIFYING START**/
    PCMCIA_WARNING("\nafter setting start\n");

    rtd_part_outl(PCMCIA_ADDRESS_0_REG , PCMCIA_ADDRESS_0_UP , PCMCIA_ADDRESS_0_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_1_REG , PCMCIA_ADDRESS_1_UP , PCMCIA_ADDRESS_1_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_2_REG , PCMCIA_ADDRESS_2_UP , PCMCIA_ADDRESS_2_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_3_REG , PCMCIA_ADDRESS_3_UP , PCMCIA_ADDRESS_3_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_4_REG , PCMCIA_ADDRESS_4_UP , PCMCIA_ADDRESS_4_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_5_REG , PCMCIA_ADDRESS_5_UP , PCMCIA_ADDRESS_5_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_6_REG , PCMCIA_ADDRESS_6_UP , PCMCIA_ADDRESS_6_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_7_REG , PCMCIA_ADDRESS_7_UP , PCMCIA_ADDRESS_7_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_8_REG , PCMCIA_ADDRESS_8_UP , PCMCIA_ADDRESS_8_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_9_REG , PCMCIA_ADDRESS_9_UP , PCMCIA_ADDRESS_9_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_10_REG , PCMCIA_ADDRESS_10_UP , PCMCIA_ADDRESS_10_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_11_REG , PCMCIA_ADDRESS_11_UP , PCMCIA_ADDRESS_11_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_12_REG , PCMCIA_ADDRESS_12_UP , PCMCIA_ADDRESS_12_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_13_REG , PCMCIA_ADDRESS_13_UP , PCMCIA_ADDRESS_13_LOW , 0X01 );
    rtd_part_outl(PCMCIA_ADDRESS_14_REG , PCMCIA_ADDRESS_14_UP , PCMCIA_ADDRESS_14_LOW , 0X01 );

    rtd_part_outl(PCMCIA_DATA_0_REG , PCMCIA_DATA_0_UP , PCMCIA_DATA_0_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_1_REG , PCMCIA_DATA_1_UP , PCMCIA_DATA_1_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_2_REG , PCMCIA_DATA_2_UP , PCMCIA_DATA_2_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_3_REG , PCMCIA_DATA_3_UP , PCMCIA_DATA_3_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_4_REG , PCMCIA_DATA_4_UP , PCMCIA_DATA_4_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_5_REG , PCMCIA_DATA_5_UP , PCMCIA_DATA_5_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_6_REG , PCMCIA_DATA_6_UP , PCMCIA_DATA_6_LOW , 0X01 );
    rtd_part_outl(PCMCIA_DATA_7_REG , PCMCIA_DATA_7_UP , PCMCIA_DATA_7_LOW , 0X01 );

    rtd_part_outl(PCMCIA_REG_REG    , PCMCIA_REG_UP , PCMCIA_REG_LOW    , 0X01 );
    rtd_part_outl(PCMCIA_CE1_REG    , PCMCIA_CE1_UP , PCMCIA_CE1_LOW    , 0X01 );
    rtd_part_outl(PCMCIA_OE_REG , PCMCIA_OE_UP  , PCMCIA_OE_LOW , 0X01 );
    rtd_part_outl(PCMCIA_WE_REG , PCMCIA_WE_UP  , PCMCIA_WE_LOW , 0X01 );
    rtd_part_outl(PCMCIA_IORD_REG   , PCMCIA_IORD_UP    , PCMCIA_IORD_LOW , 0X01 );
    rtd_part_outl(PCMCIA_IOWR_REG   , PCMCIA_IOWR_UP    , PCMCIA_IOWR_LOW , 0X01 );
    rtd_part_outl(PCMCIA_INPACK0_REG , PCMCIA_INPACK0_UP    , PCMCIA_INPACK0_LOW , 0X01 );
    rtd_part_outl(PCMCIA_WAIT0_REG  , PCMCIA_WAIT0_UP   , PCMCIA_WAIT0_LOW , 0X01 );
    rtd_part_outl(PCMCIA_RESET0_REG , PCMCIA_RESET0_UP  , PCMCIA_RESET0_LOW , 0X01 );
    rtd_part_outl(PCMCIA_CD0_REG    , PCMCIA_CD0_UP , PCMCIA_CD0_LOW    , 0X01 );
    rtd_part_outl(PCMCIA_IREQ0_REG  , PCMCIA_IREQ0_UP   , PCMCIA_IREQ0_LOW , 0X0F );


    PCMCIA_WARNING("address 0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_0_UP , PCMCIA_ADDRESS_0_LOW,  PCMCIA_ADDRESS_0_REG, rtd_part_inl(PCMCIA_ADDRESS_0_REG , PCMCIA_ADDRESS_0_UP , PCMCIA_ADDRESS_0_LOW ) );
    PCMCIA_WARNING("address 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_1_UP , PCMCIA_ADDRESS_1_LOW,  PCMCIA_ADDRESS_1_REG, rtd_part_inl(PCMCIA_ADDRESS_1_REG , PCMCIA_ADDRESS_1_UP , PCMCIA_ADDRESS_1_LOW ) );
    PCMCIA_WARNING("address 2 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_2_UP , PCMCIA_ADDRESS_2_LOW,  PCMCIA_ADDRESS_2_REG, rtd_part_inl(PCMCIA_ADDRESS_2_REG , PCMCIA_ADDRESS_2_UP , PCMCIA_ADDRESS_2_LOW ) );
    PCMCIA_WARNING("address 3 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_3_UP , PCMCIA_ADDRESS_3_LOW,  PCMCIA_ADDRESS_3_REG, rtd_part_inl(PCMCIA_ADDRESS_3_REG , PCMCIA_ADDRESS_3_UP , PCMCIA_ADDRESS_3_LOW ) );
    PCMCIA_WARNING("address 4 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_4_UP , PCMCIA_ADDRESS_4_LOW,  PCMCIA_ADDRESS_4_REG, rtd_part_inl(PCMCIA_ADDRESS_4_REG , PCMCIA_ADDRESS_4_UP , PCMCIA_ADDRESS_4_LOW ) );
    PCMCIA_WARNING("address 5 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_5_UP , PCMCIA_ADDRESS_5_LOW,  PCMCIA_ADDRESS_5_REG, rtd_part_inl(PCMCIA_ADDRESS_5_REG , PCMCIA_ADDRESS_5_UP , PCMCIA_ADDRESS_5_LOW ) );
    PCMCIA_WARNING("address 6 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_6_UP , PCMCIA_ADDRESS_6_LOW,  PCMCIA_ADDRESS_6_REG, rtd_part_inl(PCMCIA_ADDRESS_6_REG , PCMCIA_ADDRESS_6_UP , PCMCIA_ADDRESS_6_LOW ) );
    PCMCIA_WARNING("address 7 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_7_UP , PCMCIA_ADDRESS_7_LOW,  PCMCIA_ADDRESS_7_REG, rtd_part_inl(PCMCIA_ADDRESS_7_REG , PCMCIA_ADDRESS_7_UP , PCMCIA_ADDRESS_7_LOW ) );
    PCMCIA_WARNING("address 8 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_8_UP , PCMCIA_ADDRESS_8_LOW,  PCMCIA_ADDRESS_8_REG, rtd_part_inl(PCMCIA_ADDRESS_8_REG , PCMCIA_ADDRESS_8_UP , PCMCIA_ADDRESS_8_LOW ) );
    PCMCIA_WARNING("address 9 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_9_UP , PCMCIA_ADDRESS_9_LOW,  PCMCIA_ADDRESS_9_REG, rtd_part_inl(PCMCIA_ADDRESS_9_REG , PCMCIA_ADDRESS_9_UP , PCMCIA_ADDRESS_9_LOW ) );
    PCMCIA_WARNING("address 10 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_10_UP , PCMCIA_ADDRESS_10_LOW,  PCMCIA_ADDRESS_10_REG, rtd_part_inl(PCMCIA_ADDRESS_10_REG , PCMCIA_ADDRESS_10_UP , PCMCIA_ADDRESS_10_LOW ) );
    PCMCIA_WARNING("address 11 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_11_UP , PCMCIA_ADDRESS_11_LOW,  PCMCIA_ADDRESS_11_REG, rtd_part_inl(PCMCIA_ADDRESS_11_REG , PCMCIA_ADDRESS_11_UP , PCMCIA_ADDRESS_11_LOW ) );
    PCMCIA_WARNING("address 12 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_12_UP , PCMCIA_ADDRESS_12_LOW,  PCMCIA_ADDRESS_12_REG, rtd_part_inl(PCMCIA_ADDRESS_12_REG , PCMCIA_ADDRESS_12_UP , PCMCIA_ADDRESS_12_LOW ) );
    PCMCIA_WARNING("address 13 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_13_UP , PCMCIA_ADDRESS_13_LOW,  PCMCIA_ADDRESS_13_REG, rtd_part_inl(PCMCIA_ADDRESS_13_REG , PCMCIA_ADDRESS_13_UP , PCMCIA_ADDRESS_13_LOW ) );
    PCMCIA_WARNING("address 14 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_ADDRESS_14_UP , PCMCIA_ADDRESS_14_LOW,  PCMCIA_ADDRESS_14_REG, rtd_part_inl(PCMCIA_ADDRESS_14_REG , PCMCIA_ADDRESS_14_UP , PCMCIA_ADDRESS_14_LOW ) );

    PCMCIA_WARNING("data 0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_0_UP , PCMCIA_DATA_0_LOW,  PCMCIA_DATA_0_REG, rtd_part_inl(PCMCIA_DATA_0_REG , PCMCIA_DATA_0_UP , PCMCIA_DATA_0_LOW ) );
    PCMCIA_WARNING("data 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_1_UP , PCMCIA_DATA_1_LOW,  PCMCIA_DATA_1_REG, rtd_part_inl(PCMCIA_DATA_1_REG , PCMCIA_DATA_1_UP , PCMCIA_DATA_1_LOW ) );
    PCMCIA_WARNING("data 2 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_2_UP , PCMCIA_DATA_2_LOW,  PCMCIA_DATA_2_REG, rtd_part_inl(PCMCIA_DATA_2_REG , PCMCIA_DATA_2_UP , PCMCIA_DATA_2_LOW ) );
    PCMCIA_WARNING("data 3 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_3_UP , PCMCIA_DATA_3_LOW,  PCMCIA_DATA_3_REG, rtd_part_inl(PCMCIA_DATA_3_REG , PCMCIA_DATA_3_UP , PCMCIA_DATA_3_LOW ) );
    PCMCIA_WARNING("data 4 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_4_UP , PCMCIA_DATA_4_LOW,  PCMCIA_DATA_4_REG, rtd_part_inl(PCMCIA_DATA_4_REG , PCMCIA_DATA_4_UP , PCMCIA_DATA_4_LOW ) );
    PCMCIA_WARNING("data 5 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_5_UP , PCMCIA_DATA_5_LOW,  PCMCIA_DATA_5_REG, rtd_part_inl(PCMCIA_DATA_5_REG , PCMCIA_DATA_5_UP , PCMCIA_DATA_5_LOW ) );
    PCMCIA_WARNING("data 6 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_6_UP , PCMCIA_DATA_6_LOW,  PCMCIA_DATA_6_REG, rtd_part_inl(PCMCIA_DATA_6_REG , PCMCIA_DATA_6_UP , PCMCIA_DATA_6_LOW ) );
    PCMCIA_WARNING("data 7 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_DATA_7_UP , PCMCIA_DATA_7_LOW,  PCMCIA_DATA_7_REG, rtd_part_inl(PCMCIA_DATA_7_REG , PCMCIA_DATA_7_UP , PCMCIA_DATA_7_LOW ) );

    PCMCIA_WARNING("REG , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_REG_UP , PCMCIA_REG_LOW,  PCMCIA_REG_REG, rtd_part_inl(PCMCIA_REG_REG , PCMCIA_REG_UP , PCMCIA_REG_LOW ) );
    PCMCIA_WARNING("CE 1 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_CE1_UP , PCMCIA_CE1_LOW,  PCMCIA_CE1_REG, rtd_part_inl(PCMCIA_CE1_REG , PCMCIA_CE1_UP , PCMCIA_CE1_LOW ) );
    PCMCIA_WARNING("OE  , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_OE_UP , PCMCIA_OE_LOW,  PCMCIA_OE_REG, rtd_part_inl(PCMCIA_OE_REG , PCMCIA_OE_UP , PCMCIA_OE_LOW ) );
    PCMCIA_WARNING("WE , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_WE_UP , PCMCIA_WE_LOW,  PCMCIA_WE_REG, rtd_part_inl(PCMCIA_WE_REG , PCMCIA_WE_UP , PCMCIA_WE_LOW ) );
    PCMCIA_WARNING("IORD , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IORD_UP , PCMCIA_IORD_LOW,  PCMCIA_IORD_REG, rtd_part_inl(PCMCIA_IORD_REG , PCMCIA_IORD_UP , PCMCIA_IORD_LOW ) );
    PCMCIA_WARNING("IOWR , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IOWR_UP , PCMCIA_IOWR_LOW,  PCMCIA_IOWR_REG, rtd_part_inl(PCMCIA_IOWR_REG , PCMCIA_IOWR_UP , PCMCIA_IOWR_LOW ) );
    PCMCIA_WARNING("INPACK0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_INPACK0_UP , PCMCIA_INPACK0_LOW,  PCMCIA_INPACK0_REG, rtd_part_inl(PCMCIA_INPACK0_REG , PCMCIA_INPACK0_UP , PCMCIA_INPACK0_LOW ) );
    PCMCIA_WARNING("WAIT0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_WAIT0_UP , PCMCIA_WAIT0_LOW,  PCMCIA_WAIT0_REG, rtd_part_inl(PCMCIA_WAIT0_REG , PCMCIA_WAIT0_UP , PCMCIA_WAIT0_LOW ) );
    PCMCIA_WARNING("RESET0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_RESET0_UP , PCMCIA_RESET0_LOW,  PCMCIA_RESET0_REG, rtd_part_inl(PCMCIA_RESET0_REG , PCMCIA_RESET0_UP , PCMCIA_RESET0_LOW ) );
    PCMCIA_WARNING("CD0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_CD0_UP , PCMCIA_CD0_LOW,  PCMCIA_CD0_REG, rtd_part_inl(PCMCIA_CD0_REG , PCMCIA_CD0_UP , PCMCIA_CD0_LOW ) );
    PCMCIA_WARNING("IREQ0 , up = %d , low =%d , reg 0x%X = 0x%08X , \n",PCMCIA_IREQ0_UP , PCMCIA_IREQ0_LOW,  PCMCIA_IREQ0_REG, rtd_part_inl(PCMCIA_IREQ0_REG , PCMCIA_IREQ0_UP , PCMCIA_IREQ0_LOW ) );


    PCMCIA_WARNING("\n %s end setting start\n" , __func__);
#endif
}

static void pcmcia_pinmux_set(void)
{
#if 0
    /* Please enable it to Force Enable PinMus setting*/
    rtd_outl(0xb8000850, (rtd_inl(0xb8000850) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_IREQ0_N,<I>,<HS>
    rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_CD0_N,<I>,<HS>
    rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_D_bit3,<I/O>,<HS>
    rtd_outl(0xb8000854, (rtd_inl(0xb8000854) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_D_bit4,<I/O>,<HS>
    rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_D_bit5,<I/O>,<HS>
    rtd_outl(0xb8000858, (rtd_inl(0xb8000858) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_D_bit6,<I/O>,<HS>
    rtd_outl(0xb800085c, (rtd_inl(0xb800085c) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_D_bit7,<I/O>,<HS>
    rtd_outl(0xb800085c, (rtd_inl(0xb800085c) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_CE0_0,<O>,<HS>
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit10,<OD>,<HS>
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_OE_N,<O>,<HS>
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_IORD_N,<O>,<HS>
    rtd_outl(0xb8000860, (rtd_inl(0xb8000860) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_ADDR_bit11,<OD>,<HS>
    rtd_outl(0xb8000864, (rtd_inl(0xb8000864) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_IOWR_N,<O>,<HS>
    rtd_outl(0xb8000864, (rtd_inl(0xb8000864) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_ADDR_bit9,<OD>,<HS>
    rtd_outl(0xb8000864, (rtd_inl(0xb8000864) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_ADDR_bit8,<OD>,<HS>
    rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_ADDR_bit13,<OD>,<HS>
    rtd_outl(0xb8000868, (rtd_inl(0xb8000868) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_ADDR_bit14,<OD>,<HS>
    rtd_outl(0xb800086c, (rtd_inl(0xb800086c) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_WE_N,<O>,<HS>
    rtd_outl(0xb8000874, (rtd_inl(0xb8000874) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit12,<OD>,<HS>
    rtd_outl(0xb8000874, (rtd_inl(0xb8000874) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_ADDR_bit7,<OD>,<HS>
    rtd_outl(0xb8000878, (rtd_inl(0xb8000878) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit6,<OD>,<HS>
    rtd_outl(0xb8000878, (rtd_inl(0xb8000878) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_RST0,<OD>,<HS>
    rtd_outl(0xb8000878, (rtd_inl(0xb8000878) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_ADDR_bit5,<OD>,<HS>
    rtd_outl(0xb8000878, (rtd_inl(0xb8000878) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_WAIT0_N,<I>
    rtd_outl(0xb800087c, (rtd_inl(0xb800087c) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit4,<OD>,<HS>

#if 1 //NO_INPACK PIN
    rtd_outl(0xb800087c, (rtd_inl(0xb800087c) & ~(0xF<<20)) | (0xF<<20));  //PCMCIA_INPACK0_N,<I>,<HS>  //
#else
    rtd_outl(0xb800087c, (rtd_inl(0xb800087c) & ~(0xF<<20)) | (0x1<<20));  //PCMCIA_INPACK0_N,<I>,<HS>  //
#endif
    rtd_outl(0xb800087c, (rtd_inl(0xb800087c) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_ADDR_bit3,<OD>,<HS>
    rtd_outl(0xb800087c, (rtd_inl(0xb800087c) & ~(0xF<< 4)) | (0x1<< 4));  //PCMCIA_REG_N,<O>
    rtd_outl(0xb8000880, (rtd_inl(0xb8000880) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit2,<OD>,<HS>
    rtd_outl(0xb8000880, (rtd_inl(0xb8000880) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_ADDR_bit1,<OD>,<HS>
    rtd_outl(0xb8000884, (rtd_inl(0xb8000884) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_ADDR_bit0,<OD>,<HS>
    rtd_outl(0xb8000884, (rtd_inl(0xb8000884) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_D_bit0,<I/O>,<HS>
    rtd_outl(0xb8000888, (rtd_inl(0xb8000888) & ~(0xF<<28)) | (0x1<<28));  //PCMCIA_D_bit1,<I/O>,<HS>
    rtd_outl(0xb8000888, (rtd_inl(0xb8000888) & ~(0xF<<12)) | (0x1<<12));  //PCMCIA_D_bit2,<I/O>,<HS>
#endif
#if defined( Mac5p_DEMO_PCB )
    mac5p_pcmcia_pinmux_set();
#endif

}

int __init rtk_pcmcia_module_init(void)
{
    int ret = 0;

#ifdef CONFIG_CUSTOMER_TV006
    PCMCIA_WARNING( "%s isPcbWithPcmcia = %d \n" , __func__ , isPcbWithPcmcia()   );
    if( 0 == isPcbWithPcmcia() )
    {
        PCMCIA_WARNING("this pcb is japan type , pcmcia driver is not needed \n");
        PCMCIA_WARNING("this pcb is japan type , pcmcia driver is not needed \n");
        PCMCIA_WARNING("this pcb is japan type , pcmcia driver is not needed \n");
        PCMCIA_WARNING("this pcb is japan type , pcmcia driver is not needed \n");
        PCMCIA_WARNING("this pcb is japan type , pcmcia driver is not needed \n");
        return -ENODEV;
    }
#endif


    PCMCIA_ClockEnable(1);  /*  enable PCMCIA clock */
    rtk_pcmcia_gpio_config();
    rtk_pcmcia_gpio_config2();
    rtk_pcmcia_gpio_config3();
    rtk_pcmcia_phy_reset();
    rtk_pcmcia[0] = create_rtk_pcmcia(0);
    if (rtk_pcmcia[0] == NULL)
    {
        PCMCIA_WARNING("rtk_pcmcia_module_init failed - create pcmcia driver failed\n");
        return -ENODEV;
    }
    rtk_pcmcia_ptr = rtk_pcmcia[0];
    pcmcia_pinmux_set();
    rtk_pcmcia_int_gpio_set();
    rtk_pcmcia_enable(rtk_pcmcia[0], 0);    /* disable pcmcia */
    ret =
        request_irq(IRQ_GET_KERNEL_IRQ_NUM(PCMCIA_IRQ), rtk_pcmcia_isr, SA_SHIRQ, "pcmcia",
                    rtk_pcmcia[0]);
    if (ret < 0)
    {
        PCMCIA_WARNING("rtk_pcmcia_module_init failed - Request irq%d failed(ret=%d)\n",
                       IRQ_GET_KERNEL_IRQ_NUM(PCMCIA_IRQ), ret);
        release_rtk_pcmcia(rtk_pcmcia[0]);
        rtk_pcmcia_ptr = NULL;
        return -ENODEV;
    }
    if (misc_register(&rtk_pcmcia_miscdev))
    {
        PCMCIA_WARNING
        ("rtk_pcmcia_module_init failed - register misc device failed\n");
        release_rtk_pcmcia(rtk_pcmcia[0]);
        rtk_pcmcia_ptr = NULL;
        free_irq(IRQ_GET_KERNEL_IRQ_NUM(PCMCIA_IRQ), &rtk_pcmcia_miscdev);
        return -ENODEV;
    }

#ifdef CONFIG_PM
    pcmcia_platform_dev = platform_device_register_simple("PCMCIA",(unsigned int)rtk_pcmcia[0], NULL, 0);

    platform_driver_register(&pcmcia_platform_drv); /* regist mcp driver */
#endif
    if ((pcmcia_cfg & RTK_PCMCIA_CFG_SKIP_DRIVERS_TIMING_CONFIGURATION) ==0)
    {
        PCMCIA_WARNING("using drivers pcmcia timing configuration\n");
        /* this timing is provided by DIC. */
        SET_PCMCIA_AMTC_0(pcmcia_amtc0);
        SET_PCMCIA_AMTC_1(pcmcia_amtc1);
        SET_PCMCIA_IOMTC(pcmcia_iomtc);
        SET_PCMCIA_MATC_0(pcmcia_matc0);
        SET_PCMCIA_MATC_1(pcmcia_matc1);
    }
    else
    {
        PCMCIA_WARNING("skip pcmcia timing configuration\n");
    }
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_amtc0);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_amtc1);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_iomtc);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_matc0);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_matc1);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_debug_ctrl);
    device_create_file(rtk_pcmcia_miscdev.this_device, &dev_attr_reset_pulse_width);
    return ret;
}

static void __exit rtk_pcmcia_module_exit(void)
{

    if( NULL!= rtk_pcmcia_ptr )
    {

        misc_deregister(&rtk_pcmcia_miscdev);

#ifdef CONFIG_PM
        platform_device_unregister(pcmcia_platform_dev);
        platform_driver_unregister(&pcmcia_platform_drv);

#endif /*
 */

        free_irq(IRQ_GET_KERNEL_IRQ_NUM(PCMCIA_IRQ), &rtk_pcmcia_miscdev);
        rtk_pcmcia_enable(rtk_pcmcia[0], 0);    /* disable pcmcia */
        release_rtk_pcmcia(rtk_pcmcia[0]);

        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_amtc0);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_amtc1);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_iomtc);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_matc0);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_matc1);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_debug_ctrl);
        device_remove_file(rtk_pcmcia_miscdev.this_device, &dev_attr_reset_pulse_width);

    }
}

module_init(rtk_pcmcia_module_init);
module_exit(rtk_pcmcia_module_exit);
MODULE_AUTHOR("Kevin Wang, Realtek Semiconductor");
MODULE_LICENSE("GPL");
