#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <mach/rtk_log.h>
#include <mach/io.h>
#include <mach/pcbMgr.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-chipset.h>
#ifdef CONFIG_RTK_KDRV_GPIO_BUILT_IN_TEST
#include <rtk_kdriver/rtk_gpio-bist.h>
#endif
#include "rtk_gpio-reg.h"
#include <rtk_gpio-debug.h>
#include <rtk_kdriver/rtk_gpio-db.h>

RTK_GPIO_PCB_T* pPcbInfo = NULL;
extern Array RTK_GPIO_DB;

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)       gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)       (hwirq)
#endif
#ifdef CONFIG_WEBOS
#include "../../staging/webos/logger/wdt_log.h"
#endif

//=============================================================================


static RTK_GPIO_IRQ rtk_gpio_irq[MIS_GPIO_CNT + ISO_GPIO_CNT + GPI_MIS_CNT + GPI_ISO_CNT];

#define ENABLE_GPIO_STR

#ifdef CONFIG_CUSTOMER_TV006
static void rtk_gpio_micom(void);
#endif

static int g_lg_hal_int_flag = 0;
#define MIS_GPIO_REG_SETS           ((MIS_GPIO_CNT+31)>>5)
#define ISO_GPIO_REG_SETS           ((ISO_GPIO_CNT+31)>>5)
#define GPI_MIS_REG_SETS            ((GPI_MIS_CNT+31)>>5)
#define GPI_ISO_REG_SETS            ((GPI_ISO_CNT+31)>>5)
#define GPO_MIS_REG_SETS            ((GPO_MIS_CNT+31)>>5)
#define GPO_ISO_REG_SETS            ((GPO_ISO_CNT+31)>>5)
#define GPIO_REG_OFST(id)           ((id >> 5)<<2)
#define GPIO_REG_BIT(id)            (id & 0x1F)  // reg bit = id % 32
#define GPIO_INT_REG_OFST(id)       ((id/31)<<2)
#define GPIO_INT_REG_BIT(id)        ((id%31)+1)

#ifdef ENABLE_GPIO_STR
/* only LG pcb need to  store and recovery gpio in/output values */
static unsigned int backup_iso_gpie[ISO_GPIO_REG_SETS];
static unsigned int backup_mis_gpie[MIS_GPIO_REG_SETS];

static unsigned int backup_gpi_mis_gpie[GPI_ISO_REG_SETS];
static unsigned int backup_gpi_iso_gpie[GPI_ISO_REG_SETS];

static RTK_GPIO_CONFIG backupIsoGpioConfig[ISO_GPIO_REG_SETS];
static RTK_GPIO_CONFIG backupMisGpioConfig[MIS_GPIO_REG_SETS];

static RTK_GPIO_CONFIG backupGpoIsoConfig[GPO_ISO_REG_SETS];
static RTK_GPIO_CONFIG backupGpoMisConfig[GPO_MIS_REG_SETS];


#define GPIO_HW_SEMAPHORE (0xB801A624)

int getGpioHwSemaphore( void )
{
    unsigned int semoValue = 0;

    do{
        semoValue = rtd_inl(GPIO_HW_SEMAPHORE);

    }while( semoValue == 0  ) ;

    return 0;
}

int releaseGpioHwSemaphore( void )
{
    rtd_outl( GPIO_HW_SEMAPHORE , 0x0 );

    return 0 ;
}


#else


int getGpioHwSemaphore( void )
{
    return 0;
}

int releaseGpioHwSemaphore( void )
{
    return 0 ;
}

#endif

extern int bShowStrMessage ;

void PowerOnGPIO(void)
{
    RTK_GPIO_WARNING("power on\n");
    CRT_CLK_OnOff( GPIO, CLK_ON, 0);
}


static RTK_GPIO_IRQ *_get_gpio_entry(RTK_GPIO_ID gid)
{
    int id = gpio_idx(gid);

    switch (gpio_group(gid)) 
    {
    case MIS_GPIO:
        if (id < MIS_GPIO_CNT)
            return &rtk_gpio_irq[id];
        break;

    case ISO_GPIO:
        if (id < ISO_GPIO_CNT)
            return &rtk_gpio_irq[id + MIS_GPIO_CNT];
        break;
    case MIS_GPI:
        if (id < GPI_MIS_CNT)
            return &rtk_gpio_irq[id + MIS_GPIO_CNT + ISO_GPIO_CNT];
        break;
    case ISO_GPI:
        if (id < GPI_ISO_CNT)
            return &rtk_gpio_irq[id + MIS_GPIO_CNT + ISO_GPIO_CNT + GPI_MIS_CNT];
        break;

    default:
        break;
    }
    
    RTK_GPIO_WARNING("%s failed  %s  index = %d \n",
            __func__ ,gpio_type(gpio_group(gid)), id );

    return NULL;
}


static int _get_reg_ofst_bit(RTK_GPIO_ID gid ,unsigned int *pOffset, unsigned char *pBit)
{
    int id = gpio_idx(gid);

    switch (gpio_group(gid))
    {
    case MIS_GPIO:
        if (id < MIS_GPIO_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    case ISO_GPIO:
        if (id < ISO_GPIO_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    case MIS_GPI:
        if (id < GPI_MIS_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    case MIS_GPO:
        if (id < GPO_MIS_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    case ISO_GPO:
        if (id < GPO_ISO_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    case ISO_GPI:
        if (id < GPI_ISO_CNT)
        {
            *pOffset = ((id >> 5)<<2);
            *pBit = (id & 0x1F);
            return 0;
        }
        break;

    default:
        break;
    }

/*
    RTK_GPIO_WARNING("%s failed  %s  index = %d \n" , __func__ , ( ISO_GPIO == gpio_group(gid) )?("ISO"):
        ( ( ISO_GPIO == gpio_group(gid) )?("MIS"):("ISO2") )  , id );
*/

    return -EFAULT;
}

static int _get_int_reg_ofst_bit(RTK_GPIO_ID gid ,unsigned int *pOffset, unsigned char *pBit)
{

    int id = gpio_idx(gid);

    switch (gpio_group(gid))
    {
    case MIS_GPIO:
        if (id < MIS_GPIO_CNT)
        {
            if(id>122)
            {
                id++;
                *pOffset = ((id/31)<<2);
                *pBit = ((id%31)+1);
            }
            else
            {
                *pOffset = ((id/31)<<2);
                *pBit = ((id%31)+1);
            }
            return 0;
        }
        break;

    case ISO_GPIO:
        if (id < ISO_GPIO_CNT)
        {
            *pOffset = ((id/31)<<2);
            *pBit = ((id%31)+1);

            return 0;
        }
        break;

    case MIS_GPI:
        if (id < GPI_MIS_CNT)
        {
            *pOffset = ((id/31)<<2);
            *pBit = ((id%31)+1);

            return 0;
        }
        break;

    case ISO_GPI:
        if (id < GPI_ISO_CNT)
        {
            *pOffset = ((id/31)<<2);
            *pBit = ((id%31)+1);

            return 0;
        }
        break;

    default:
        break;
    }

    /*RTK_GPIO_WARNING("%s failed  %s  index = %d \n" , __func__ , ( ISO_GPIO == gpio_group(gid) )?("ISO"):
        ( ( ISO_GPIO == gpio_group(gid) )?("MIS"):("ISO2") )  , id );
    */

    return -EFAULT;
}


int rtk_gpio_request_irq(RTK_GPIO_ID gid,
             void (*handler) (RTK_GPIO_ID gid,
                      unsigned char assert, void *dev_id),
             char *name, void *dev_id)
{
    RTK_GPIO_IRQ *p_irq = _get_gpio_entry(gid);
    unsigned long flags;

    if (p_irq == NULL)
    {
        RTK_GPIO_WARNING("request_rtk_gpio_irq failed - %s GPIO(%d) does not exist\n",
             gpio_type(gpio_group(gid)), gpio_idx(gid));
        return -1;
    }

    if (name == NULL || handler == NULL || dev_id == NULL)
    {
        RTK_GPIO_WARNING("request_rtk_gpio_irq failed - in valid argument\n");
        return -1;
    }

    spin_lock_irqsave(&rtk_gpio_irq_lock, flags);

    if (p_irq->handler) {
        RTK_GPIO_WARNING("request_rtk_gpio_irq failed - %s GPIO (%d) is occupied by [%s]\n",
             gpio_type(gpio_group(gid)), gpio_idx(gid), p_irq->name);
        spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);
        return -1;
    }

    strncpy(p_irq->name, name, sizeof(p_irq->name));
    p_irq->dev_id = dev_id;
    p_irq->handler = handler;
    p_irq->irq_flag = 0;

    spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);

    RTK_GPIO_INFO("request_rtk_gpio_irq - %s GPIO (%d) irq requested by (%s)\n",
         gpio_type(gpio_group(gid)), gpio_idx(gid), p_irq->name);

    return 0;
}

EXPORT_SYMBOL(rtk_gpio_request_irq);

void rtk_gpio_free_irq(RTK_GPIO_ID gid, void *dev_id)
{
    RTK_GPIO_IRQ *p_irq = _get_gpio_entry(gid);
    unsigned long flags;
    
    if (p_irq)
    {
        spin_lock_irqsave(&rtk_gpio_irq_lock, flags);

        if (p_irq->dev_id == dev_id)
        {
            memset(p_irq, 0, sizeof(RTK_GPIO_IRQ));
            RTK_GPIO_INFO("rtk_gpio_free_irq - %s GPIO %d irq released\n",
                 gpio_type(gpio_group(gid)), gpio_idx(gid));
        }

        spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);
    }
    else
    {
        RTK_GPIO_WARNING("rtk_gpio_free_irq failed - %s GPIO %d irq does not exists \n",
             gpio_type(gpio_group(gid)), gpio_idx(gid));
    }
}

EXPORT_SYMBOL(rtk_gpio_free_irq);

static int _do_rtk_gpio_irq(RTK_GPIO_ID id, unsigned char assert)
{
    RTK_GPIO_IRQ *p_irq = _get_gpio_entry(id);
    unsigned long flags;
    int ret = 0;

    if (p_irq) 
    {
        spin_lock_irqsave(&rtk_gpio_irq_lock, flags);

        if (p_irq->handler)
            p_irq->handler(id, assert, p_irq->dev_id);

        spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);
        ret = 1;
    }
    return ret;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Interrupt Handler                                                                                //
//////////////////////////////////////////////////////////////////////////////////////////////////////

static irqreturn_t gpio_interrupt_handler(int irq, void *dev_id)
{
    RTK_GPIO_GROUP group = (RTK_GPIO_GROUP)~((unsigned long)dev_id);
    unsigned long GPIO_ISR = MIS_ISR_reg;
    unsigned long ISR_GPIO_ASSERT = (0x1 << MIS_ISR_assert_int_shift);
    unsigned long GPIO_CNT = MIS_GPIO_CNT;
    unsigned long UMSK_ISR_GPDA = MIS_UMSK_ISR_GP0DA_reg;
    unsigned long UMSK_ISR_GPA = MIS_UMSK_ISR_GP0A_reg;
    uint32_t status;
    uint32_t event;
    unsigned int i;
    unsigned int gpioNr = 0;
    unsigned int reg_ofst = 0;

    if ( (rtd_inl(MIS_ISR_reg) & (0x1 << MIS_ISR_assert_int_shift) ) == 0 &&
        (rtd_inl(ISO_ISR_reg) & (0x1 << ISO_ISR_assert_int_shift) ) == 0 )
        return IRQ_NONE;

    /* misc gpio using default value*/
    if (group == ISO_GPIO)
    {
        GPIO_ISR = ISO_ISR_reg;
        ISR_GPIO_ASSERT = (0x1 << ISO_ISR_assert_int_shift);
        GPIO_CNT = ISO_GPIO_CNT;
        UMSK_ISR_GPDA = ISO_ISR_GP0DA_reg;
        UMSK_ISR_GPA = ISO_ISR_GP0A_reg;
    }

#ifdef RTK_SUPPORT_MIS_GPI
    else if (group == MIS_GPI)
    {
        GPIO_ISR = GPI_MIS_ISR_reg;
        ISR_GPIO_ASSERT = (0x1 << GPI_MIS_ISR_assert_int_shift);
        GPIO_CNT = GPI_MIS_CNT;
        UMSK_ISR_GPDA = GPI_MIS_ISR_DEASSERT_reg;
        UMSK_ISR_GPA = GPI_MIS_ISR_ASSERT_reg;
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    else if (group == ISO_GPI)
    {
        GPIO_ISR = GPI_ISO_ISR_reg;
        ISR_GPIO_ASSERT = (0x1 << GPI_ISO_ISR_assert_int_shift);
        GPIO_CNT = GPI_ISO_CNT;
        UMSK_ISR_GPDA = GPI_ISO_ISR_DEASSERT_reg;
        UMSK_ISR_GPA = GPI_ISO_ISR_ASSERT_reg;
    }
#endif

    event = gpio_ioread32(GPIO_ISR) & ISR_GPIO_ASSERT;
    /*RTK_GPIO_WARNING("event = 0x%X ,  GPIO_ISR = 0x%X , GPIO_ISR_value = 0x%X , ISR_GPIO_ASSERT = 0x%X \n" , event ,  GPIO_ISR, gpio_ioread32(GPIO_ISR), ISR_GPIO_ASSERT);*/

    if (event == 0)
        return IRQ_NONE;

    if (event & ISR_GPIO_ASSERT)
    {
        /* dis-assert */
        gpioNr = 0;
        reg_ofst = 0;
        while (gpioNr < GPIO_CNT)
        {
            status = gpio_ioread32(UMSK_ISR_GPDA + reg_ofst) >> 1;
            if (status == 0)
            {
                gpioNr += 31;
                reg_ofst += 4;
                continue;
            }

            gpio_iowrite32(status << 1, UMSK_ISR_GPDA + reg_ofst);
            i = gpioNr;

            while (status && i < GPIO_CNT)
            {
                /* printk("status = %08x\n", status); */
                if ((status & 0x1) && rtk_gpio_chk_irq_enable(rtk_gpio_id(group, i)))
                    _do_rtk_gpio_irq(rtk_gpio_id (group, i), 0);

                i++;
                status >>= 1;
            }
            gpioNr += 31;
            reg_ofst += 4;
        }

        /* assert */
        gpioNr = 0;
        reg_ofst = 0;
        while (gpioNr < GPIO_CNT)
        {
            status = gpio_ioread32(UMSK_ISR_GPA + reg_ofst) >> 1;
            if (status == 0)
            {
                gpioNr += 31;
                reg_ofst += 4;
                continue;
            }

            gpio_iowrite32(status << 1, UMSK_ISR_GPA + reg_ofst);
            i = gpioNr;

            while (status && i < GPIO_CNT)
            {
                if ((status & 0x1)&&rtk_gpio_chk_irq_enable(rtk_gpio_id(group, i)))
                    _do_rtk_gpio_irq( rtk_gpio_id(group, i), 1);

                i++;
                status >>= 1;
            }

            gpioNr += 31;
            reg_ofst += 4;
        }
    }

    gpio_iowrite32(event, GPIO_ISR);

    return IRQ_HANDLED;
}

/*
 * Internal Used API
 */

static void __inline _rtk_gpio_disable_irq_all(void)
{
    int i;

    for (i = 0; i < MIS_GPIO_REG_SETS; i++)
        gpio_iowrite32(0, MIS_GP0IE_reg + (i << 2));

    for (i = 0; i < ISO_GPIO_REG_SETS; i++)
        gpio_iowrite32(0, ISO_GPIE_reg + (i << 2));

#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
        gpio_iowrite32(0, GPI_MIS_GPIE_reg + (i << 2));
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
        gpio_iowrite32(0, GPI_ISO_GPIE_reg + (i << 2));
#endif
}

static void __inline _rtk_gpio_clear_isr_all(void)
{
    int i;

    for (i = 0; i < MIS_GPIO_REG_SETS; i++)
    {
        gpio_iowrite32(0xFFFFFFFE, MIS_UMSK_ISR_GP0A_reg + (i << 2));
        gpio_iowrite32(0xFFFFFFFE, MIS_UMSK_ISR_GP0DA_reg + (i << 2));
    }

    for (i = 0; i < ISO_GPIO_REG_SETS; i++)
    {
        gpio_iowrite32(0xFFFFFFFE, ISO_ISR_GP0A_reg + (i << 2));
        gpio_iowrite32(0xFFFFFFFE, ISO_ISR_GP0DA_reg + (i << 2));
    }

#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
    {
        gpio_iowrite32(0xFFFFFFFE, GPI_MIS_ISR_ASSERT_reg + (i << 2));
        gpio_iowrite32(0xFFFFFFFE, GPI_MIS_ISR_DEASSERT_reg + (i << 2));
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
    {
        gpio_iowrite32(0xFFFFFFFE, GPI_ISO_ISR_ASSERT_reg + (i << 2));
        gpio_iowrite32(0xFFFFFFFE, GPI_ISO_ISR_DEASSERT_reg + (i << 2));
    }
#endif
}

/*
 * Generic API
 */

int rtk_gpio_set_dir(RTK_GPIO_ID gid, unsigned char Out)
{
    unsigned int offset;
    unsigned char bit;

    if( _get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
                __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid))
    {
    case MIS_GPIO:
        iowrite_reg_bit(MIS_GP0DIR_reg + offset,bit, Out);
        return 0;

    case ISO_GPIO:
        iowrite_reg_bit(ISO_GPDIR_reg + offset,bit, Out);
        return 0;

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_set_dir);

int rtk_gpio_get_dir(RTK_GPIO_ID gid)
{
    unsigned int offset;
    unsigned char bit;

    if(_get_reg_ofst_bit(gid,&offset,&bit)!=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
                __func__ ,gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) {
    case MIS_GPIO:
        return ioread_reg_bit(MIS_GP0DIR_reg + offset,bit);

    case ISO_GPIO:
        return ioread_reg_bit(ISO_GPDIR_reg + offset,bit);

    default:
        break;
    }
    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_get_dir);

int rtk_gpio_set_irq_polarity(RTK_GPIO_ID gid, unsigned char positive)
{
    unsigned int offset;
    unsigned char bit;

    if( _get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
                __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) {
    case MIS_GPIO:
        iowrite_reg_bit(MIS_GP0DP_reg + offset, bit, positive);
        return 0;

    case ISO_GPIO:
        iowrite_reg_bit(ISO_GPDP_reg + offset, bit, positive);
        return 0;

#ifdef RTK_SUPPORT_MIS_GPI
    case MIS_GPI:
        iowrite_reg_bit(GPI_MIS_DP_reg + offset, bit, positive);
        return 0;
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    case ISO_GPI:
        iowrite_reg_bit(GPI_ISO_DP_reg + offset, bit, positive);
        return 0;
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_set_irq_polarity);

int rtk_gpio_set_irq_trigger_type(RTK_GPIO_ID gid, RTK_GPIO_TRIGGER type)
{
    unsigned int offset;
    unsigned char bit;
    RTK_GPIO_POLARITY polarity=GPIO_LOW_ACTIVE;

    RTK_GPIO_GLOBAL_INTSEL global_int_sel = MIS_GPIO_GP_INT_SEL_get_intsel(gpio_ioread32(MIS_GP_INT_SEL_reg));
    if(type==GPIO_RISING_EDGE){
        if(global_int_sel==GPIO_DISASSERT_INTERRUPT){
            polarity=GPIO_LOW_ACTIVE;
        }else{
            polarity=GPIO_HIGH_ACTIVE;
        }
    }else{
        if(global_int_sel==GPIO_DISASSERT_INTERRUPT){
            polarity=GPIO_HIGH_ACTIVE;
        }else{
            polarity=GPIO_LOW_ACTIVE;
        }
    }
	return rtk_gpio_set_irq_polarity(gid,polarity);
}

EXPORT_SYMBOL(rtk_gpio_set_irq_trigger_type);

int rtk_gpio_set_irq_enable(RTK_GPIO_ID gid, unsigned char On)
{
    unsigned int offset;
    unsigned char bit;

    if (_get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
                __func__ ,gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) 
    {
    case MIS_GPIO:
        iowrite_reg_bit(MIS_GP0IE_reg + offset,bit, On);
        return 0;

    case ISO_GPIO:
        iowrite_reg_bit(ISO_GPIE_reg + offset,bit, On);
        return 0;

#ifdef RTK_SUPPORT_MIS_GPI
    case MIS_GPI:
        iowrite_reg_bit(GPI_MIS_GPIE_reg + offset,bit, On);
        return 0;
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    case ISO_GPI:
        iowrite_reg_bit(GPI_ISO_GPIE_reg + offset,bit, On);
        return 0;
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_set_irq_enable);

int rtk_gpio_chk_irq_enable(RTK_GPIO_ID gid)
{
    unsigned int offset;
    unsigned char bit;

    if (_get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
            __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) 
    {
    case MIS_GPIO:
        return ioread_reg_bit(MIS_GP0IE_reg + offset,bit);

    case ISO_GPIO:
        return ioread_reg_bit(ISO_GPIE_reg + offset,bit);

#ifdef RTK_SUPPORT_MIS_GPI
    case MIS_GPI:
        return ioread_reg_bit(GPI_MIS_GPIE_reg + offset,bit);
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    case ISO_GPI:
        return ioread_reg_bit(GPI_ISO_GPIE_reg + offset,bit);
#endif

    default:
        break;
    }

    return 0;
}

EXPORT_SYMBOL(rtk_gpio_chk_irq_enable);

int rtk_gpio_clear_isr(RTK_GPIO_ID gid)
{
    unsigned int offset;
    unsigned char bit;

    if (_get_int_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
            __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid))
    {
    case MIS_GPIO:
        gpio_iowrite32(1 << bit,MIS_UMSK_ISR_GP0A_reg +offset);
        gpio_iowrite32(1 << bit,MIS_UMSK_ISR_GP0DA_reg + offset);
        return 0;

    case ISO_GPIO:
        gpio_iowrite32(1 << bit,ISO_ISR_GP0A_reg + offset);
        gpio_iowrite32(1 << bit,ISO_ISR_GP0DA_reg + offset);
        return 0;

#ifdef RTK_SUPPORT_MIS_GPI
    case MIS_GPI:
        gpio_iowrite32(1 << bit,GPI_MIS_ISR_ASSERT_reg + offset);
        gpio_iowrite32(1 << bit,GPI_MIS_ISR_DEASSERT_reg +offset);
        return 0;
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    case ISO_GPI:
        gpio_iowrite32(1 << bit,GPI_ISO_ISR_ASSERT_reg + offset);
        gpio_iowrite32(1 << bit,GPI_ISO_ISR_DEASSERT_reg +offset);
        return 0;
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_clear_isr);

int rtk_gpio_set_debounce(RTK_GPIO_ID gid, unsigned char val)
{
    int id = gpio_idx(gid);

    switch (gpio_group(gid))
    {
    case MIS_GPIO:
        if (id < MIS_GPIO_CNT && val <= 7)
        {
            if (id <= 127)
                gpio_iowrite32((0x8 | val) << ((id >> 4) * 4), MIS_GPDEB_reg);
            else
                gpio_iowrite32((0x8 | val) << (((id - 127) >> 4) * 4), MIS_GPDEB_1_reg);
            return 0;
        }
        break;
        
    case ISO_GPIO:
        if (id < ISO_GPIO_CNT && val <= 7)
        {
            gpio_iowrite32((0x8 | val) << ((id >> 4) * 4), ISO_GPDEB_reg);
            return 0;
        }
        break;
        
    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_set_debounce);

int rtk_gpio_input(RTK_GPIO_ID gid)
{
    unsigned int offset;
    unsigned char bit;

    if (_get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
                __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) 
    {
    case MIS_GPIO:
        return ioread_reg_bit(MIS_GP0DATI_reg + offset, bit);

    case ISO_GPIO:
        return ioread_reg_bit(ISO_GPDATI_reg + offset, bit);

#ifdef RTK_SUPPORT_MIS_GPI
    case MIS_GPI:
        return ioread_reg_bit(GPI_MIS_DATI_reg + offset, bit);
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    case ISO_GPI:
        return ioread_reg_bit(GPI_ISO_DATI_reg + offset, bit);
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_input);

int rtk_gpio_output(RTK_GPIO_ID gid, unsigned char val)
{
    unsigned int offset;
    unsigned char bit;

    if( _get_reg_ofst_bit(gid,&offset,&bit) !=0)
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
            __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) {

    case MIS_GPIO:

#ifdef CONFIG_CUSTOMER_TV006
        if (bit >= 0 && bit <= 31 )   // share 8051  gpio usage
            getGpioHwSemaphore();
#endif

        iowrite_reg_bit(MIS_GP0DATO_reg + offset,bit, val);

#ifdef CONFIG_CUSTOMER_TV006
        if (bit >= 0 && bit <= 31 )
            releaseGpioHwSemaphore();
#endif
        return 0;

    case ISO_GPIO:
        iowrite_reg_bit(ISO_GPDATO_reg + offset,bit, val);
        return 0;

    case MIS_GPO:

#ifdef ENABLE_GPO_TYPE
        iowrite_reg_bit(MIS_GPO_DATO_reg + offset, bit, val);
        return 0;
#else
        RTK_GPIO_WARNING("unknown gpio type\n");
        break;
#endif

    case ISO_GPO:

#ifdef ENABLE_GPO_TYPE
        iowrite_reg_bit(ISO_GPO_DATO_reg + offset, bit, val);
        return 0;
#else
        RTK_GPIO_WARNING("unknown gpio type\n");
        break;
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_output);

int rtk_gpio_output_get(RTK_GPIO_ID gid )
{
    unsigned int offset;
    unsigned char bit;

    if (_get_reg_ofst_bit(gid,&offset,&bit) !=0 )
    {
        RTK_GPIO_WARNING("%s failed  %s  index = %d \n" ,
            __func__ , gpio_type(gpio_group(gid)), gpio_idx(gid) );
        return -EFAULT;
    }

    switch (gpio_group(gid)) 
    {
    case MIS_GPIO:
        return ioread_reg_bit(MIS_GP0DATO_reg + offset,bit);

    case ISO_GPIO:
        return ioread_reg_bit(ISO_GPDATO_reg + offset,bit);
        break;
    case MIS_GPO:

#ifdef ENABLE_GPO_TYPE
        return ioread_reg_bit(MIS_GPO_DATO_reg + offset, bit);
#else
        RTK_GPIO_WARNING("unknown gpio type\n");
        break;
#endif

    case ISO_GPO:
#ifdef ENABLE_GPO_TYPE
        return ioread_reg_bit(ISO_GPO_DATO_reg + offset, bit);
#else
        RTK_GPIO_WARNING("unknown gpio type\n");
        break;
#endif

    default:
        break;
    }

    return -EFAULT;
}

EXPORT_SYMBOL(rtk_gpio_output_get);

/*
 * for Power Management
 */

static struct platform_device *rtk_gpio_devs;


#ifdef CONFIG_PM


#ifdef CONFIG_HIBERNATION
static int rtk_gpio_pm_suspend_noirq_std (struct device *dev)
{
    int i = 0;
    RTK_GPIO_WARNING("power std suspend \033[1;31m  [sttest]%s,%s ,%d \n\033[m",
                    __FILE__,__FUNCTION__ ,__LINE__);

#ifdef ENABLE_GPIO_STR

    /*** backup gpio enable configuration.... ***/
    for (i = 0; i < MIS_GPIO_REG_SETS; i++)
    {
        backup_mis_gpie[i] = gpio_ioread32(MIS_GP0IE_reg + (i << 2));
        backupMisGpioConfig[i].direction = gpio_ioread32(MIS_GP0DIR_reg + (i << 2));
        backupMisGpioConfig[i].outputValue= gpio_ioread32(MIS_GP0DATO_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][MISC_GPIO]  dir      0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO]  output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }
    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_MIS_REG_SETS; i++)
    {
        backupGpoMisConfig[i].outputValue= gpio_ioread32(MIS_GPO_DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_MISC]  output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );
    }
#endif

    for (i = 0; i < ISO_GPIO_REG_SETS; i++)
    {
        backup_iso_gpie[i] = gpio_ioread32(ISO_GPIE_reg + (i << 2));
        backupIsoGpioConfig[i].direction = gpio_ioread32(ISO_GPDIR_reg + (i << 2));
        backupIsoGpioConfig[i].outputValue= gpio_ioread32(ISO_GPDATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO]  dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO]  output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_ISO_REG_SETS; i++)
    {
        backupGpoIsoConfig[i].outputValue= gpio_ioread32(ISO_GPO_DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO]  output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );
    }
#endif

#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
    {
        backup_gpi_mis_gpie[i] = gpio_ioread32(GPI_MIS_GPIE_reg + (i << 2));
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
    {
        backup_gpi_iso_gpie[i] = gpio_ioread32(GPI_ISO_GPIE_reg + (i << 2));
    }
#endif

#endif

    _rtk_gpio_disable_irq_all();

    return 0;
}



static int rtk_gpio_pm_resume_noirq_std(struct device *dev)
{
       //resume code here
    int i = 0;

    RTK_GPIO_WARNING("power std reusme\033[1;31m  [sttest]%s,%s ,%d \n\033[m",
        __FILE__,__FUNCTION__ ,__LINE__);

    _rtk_gpio_clear_isr_all();
    PowerOnGPIO();
    
#ifdef ENABLE_GPIO_STR

    for (i = 0; i < MIS_GPIO_REG_SETS; i++)
    {
        gpio_iowrite32(backup_mis_gpie[i], MIS_GP0IE_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][MISC_GPIO] pre dir      0x%X = 0x%08x.\n",
                            __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO] pre output 0x%X = 0x%08x.\n",
                            __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }

        gpio_iowrite32( backupMisGpioConfig[i].outputValue , MIS_GP0DATO_reg + (i << 2));
        gpio_iowrite32( backupMisGpioConfig[i].direction , MIS_GP0DIR_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][MISC_GPIO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO] after output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }

    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_MIS_REG_SETS; i++){
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_MISC] pre output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );

        gpio_iowrite32(backupGpoMisConfig[i].outputValue,MIS_GPO_DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_MISC] after output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );
    }
#endif

    for (i = 0; i < ISO_GPIO_REG_SETS; i++){
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO] pre dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO] pre output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
        gpio_iowrite32(backup_iso_gpie[i], ISO_GPIE_reg + (i << 2));
        gpio_iowrite32( backupIsoGpioConfig[i].outputValue , ISO_GPDATO_reg + (i << 2));
        gpio_iowrite32( backupIsoGpioConfig[i].direction , ISO_GPDIR_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO] after output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_ISO_REG_SETS; i++)
    {
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO] pre dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );

        gpio_iowrite32(backupGpoIsoConfig[i].outputValue,ISO_GPO_DATO_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );

    }
#endif

#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
    {
        gpio_iowrite32(backup_gpi_mis_gpie[i], GPI_MIS_GPIE_reg + (i << 2));
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
    {
        gpio_iowrite32(backup_gpi_iso_gpie[i], GPI_ISO_GPIE_reg + (i << 2));
    }
#endif

#endif

    return 0;
}
#endif

static int rtk_gpio_pm_suspend_noirq (struct device *dev)
{
    int i = 0;
    u32 reginfo = 0;

    RTK_GPIO_WARNING("power str suspend\n");

#ifdef MIS_ISR_reg
    reginfo = gpio_ioread32((MIS_ISR_reg) ) & ~(0x1 << MIS_ISR_gpio_int_shift);
    gpio_iowrite32(reginfo, (MIS_ISR_reg) );
#endif

#ifdef ISO_ISR_reg
    reginfo = gpio_ioread32(ISO_ISR_reg) & ~(0x1 << ISO_ISR_gpio_int_shift);
    gpio_iowrite32(reginfo, ISO_ISR_reg);
#endif



#ifdef ENABLE_GPIO_STR
    /* backup gpio enable configuration.... */

    for (i = 0; i < MIS_GPIO_REG_SETS; i++)
    {
        backup_mis_gpie[i] = gpio_ioread32(MIS_GP0IE_reg + (i << 2));
        backupMisGpioConfig[i].direction = gpio_ioread32(MIS_GP0DIR_reg + (i << 2));
        backupMisGpioConfig[i].outputValue= gpio_ioread32(MIS_GP0DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG ){
            RTK_GPIO_WARNING("[%s][MISC_GPIO]  dir      0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO]  output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }

    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_MIS_REG_SETS; i++){
        backupGpoMisConfig[i].outputValue= gpio_ioread32(MIS_GPO_DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_MISC]  output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );

    }
#endif

    for (i = 0; i < ISO_GPIO_REG_SETS; i++)
    {
        backup_iso_gpie[i] = gpio_ioread32(ISO_GPIE_reg + (i << 2));
        backupIsoGpioConfig[i].direction = gpio_ioread32(ISO_GPDIR_reg + (i << 2));
        backupIsoGpioConfig[i].outputValue= gpio_ioread32(ISO_GPDATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO]  dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO]  output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_ISO_REG_SETS; i++){
        backupGpoIsoConfig[i].outputValue= gpio_ioread32(ISO_GPO_DATO_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO]  output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );

    }
#endif

#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
    {
        backup_gpi_mis_gpie[i] = gpio_ioread32(GPI_MIS_GPIE_reg + (i << 2));
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
    {
        backup_gpi_iso_gpie[i] = gpio_ioread32(GPI_ISO_GPIE_reg + (i << 2));
    }
#endif

#endif

    _rtk_gpio_disable_irq_all();

    return 0;
}



static int rtk_gpio_pm_resume_noirq(struct device *dev)
{
        //resume code here
    int i = 0;
    u32 reginfo = 0;

    RTK_GPIO_WARNING("power str reusme\n");
    _rtk_gpio_clear_isr_all();

#ifdef ENABLE_GPIO_STR     // only for hmdi setting //keep hpd low while resume back.
    backupIsoGpioConfig[0].outputValue  = backupIsoGpioConfig[0].outputValue | ( 0x1 << 6  )  | ( 0x1 << 11  )  | ( 0x1 << 14  )  | ( 0x1 << 18  );
#endif

#ifdef ENABLE_GPIO_STR
/* backup gpio enable configuration.... */
    for (i = 0; i < MIS_GPIO_REG_SETS; i++){
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][MISC_GPIO] pre dir      0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO] pre output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }

        gpio_iowrite32( backupMisGpioConfig[i].outputValue , MIS_GP0DATO_reg + (i << 2));
        gpio_iowrite32( backupMisGpioConfig[i].direction , MIS_GP0DIR_reg + (i << 2));
        gpio_iowrite32(backup_mis_gpie[i], MIS_GP0IE_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][MISC_GPIO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DIR_reg + (i << 2)) , gpio_ioread32( MIS_GP0DIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][MISC_GPIO] after output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GP0DATO_reg + (i << 2)) , gpio_ioread32( MIS_GP0DATO_reg + (i << 2))  );
        }

    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_MIS_REG_SETS; i++)
    {
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_MISC] pre output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );

        gpio_iowrite32(backupGpoMisConfig[i].outputValue,MIS_GPO_DATO_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][MISC_GPO] after output 0x%X = 0x%08x.\n",
                __func__ , ( MIS_GPO_DATO_reg + (i << 2)) , gpio_ioread32( MIS_GPO_DATO_reg + (i << 2))  );

    }
#endif

    for (i = 0; i < ISO_GPIO_REG_SETS; i++){
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO] pre dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO] pre output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
        gpio_iowrite32( backupIsoGpioConfig[i].outputValue , ISO_GPDATO_reg + (i << 2));
        gpio_iowrite32( backupIsoGpioConfig[i].direction , ISO_GPDIR_reg + (i << 2));
        gpio_iowrite32(backup_iso_gpie[i], ISO_GPIE_reg + (i << 2));
        if( bShowStrMessage == Enable_MSG )
        {
            RTK_GPIO_WARNING("[%s][ISO_GPIO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDIR_reg + (i << 2)) , gpio_ioread32( ISO_GPDIR_reg + (i << 2))  );
            RTK_GPIO_WARNING("[%s][ISO_GPIO] after output 0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPDATO_reg + (i << 2)) , gpio_ioread32( ISO_GPDATO_reg + (i << 2))  );
        }
    }

#ifdef ENABLE_GPO_TYPE
    for (i = 0; i < GPO_ISO_REG_SETS; i++){
        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO] pre dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );

        gpio_iowrite32(backupGpoIsoConfig[i].outputValue,ISO_GPO_DATO_reg + (i << 2));

        if( bShowStrMessage == Enable_MSG )
            RTK_GPIO_WARNING("[%s][GPO_ISO] after dir      0x%X = 0x%08x.\n",
                __func__ , ( ISO_GPO_DATO_reg + (i << 2)) , gpio_ioread32( ISO_GPO_DATO_reg + (i << 2))  );

    }
#endif


#ifdef RTK_SUPPORT_MIS_GPI
    for (i = 0; i < GPI_MIS_REG_SETS; i++)
    {
        gpio_iowrite32(backup_gpi_mis_gpie[i], GPI_MIS_GPIE_reg + (i << 2));
    }
#endif

#ifdef RTK_SUPPORT_ISO_GPI
    for (i = 0; i < GPI_ISO_REG_SETS; i++)
    {
        gpio_iowrite32(backup_gpi_iso_gpie[i], GPI_ISO_GPIE_reg + (i << 2));
    }
#endif

#endif


#ifdef MIS_ISR_reg
    reginfo = gpio_ioread32(MIS_ISR_reg) | (0x1 << MIS_ISR_gpio_int_shift);

    gpio_iowrite32(reginfo, MIS_ISR_reg);
#endif

#ifdef ISO_ISR_reg
    reginfo = gpio_ioread32(ISO_ISR_reg) | (0x1 << ISO_ISR_gpio_int_shift);

    gpio_iowrite32(reginfo, ISO_ISR_reg);
#endif

    PowerOnGPIO();


    return 0;
}
#endif


static const struct dev_pm_ops gpio_pm_ops = 
{
    .suspend_noirq = rtk_gpio_pm_suspend_noirq,
    .resume_noirq  = rtk_gpio_pm_resume_noirq,

#ifdef CONFIG_HIBERNATION
    .freeze_noirq = rtk_gpio_pm_suspend_noirq_std,
    .thaw_noirq   = rtk_gpio_pm_resume_noirq_std,

    .poweroff_noirq = rtk_gpio_pm_suspend_noirq_std,
    .restore_noirq  = rtk_gpio_pm_resume_noirq_std,
#endif

};


static struct platform_driver rtk_gpio_platform_driver = 
{
    .driver = {
        .name = "rtk_gpio",
        .bus = &platform_bus_type,
#ifdef CONFIG_PM
        .pm = &gpio_pm_ops,
#endif
    },
};


RTK_GPIO_ID rtk_gpio_get_gid_by_pintype(PCB_PIN_TYPE_T pin_type, unsigned char pin_index)
{
    switch (pin_type) {
        case PCB_PIN_TYPE_GPIO:
            return rtk_gpio_id(MIS_GPIO, pin_index);
        case PCB_PIN_TYPE_ISO_GPIO:
            return rtk_gpio_id(ISO_GPIO, pin_index);
        case PCB_PIN_TYPE_GPO:
            return rtk_gpio_id(MIS_GPO, pin_index);
        case PCB_PIN_TYPE_ISO_GPO:
            return rtk_gpio_id(ISO_GPO, pin_index);
        case PCB_PIN_TYPE_GPI:
            return rtk_gpio_id(MIS_GPI, pin_index);
        case PCB_PIN_TYPE_ISO_GPI:
            return rtk_gpio_id(ISO_GPO, pin_index);
        default:
            RTK_GPIO_WARNING("pin type incorrect!!!\n");
            return 0xFFFFFFFF;
      }
}

static int __init rtk_gpio_init(void)
{
    int ret;
	
    /*parser all gpio pcb enmu*/
    rtk_gpio_init_pcb_pin();

    memset(rtk_gpio_irq, 0, sizeof(rtk_gpio_irq));

    _rtk_gpio_disable_irq_all();    /* disable all interrupts */
    _rtk_gpio_clear_isr_all();  /* clear all interrupts status*/

    if (request_irq(IRQ_MISC, gpio_interrupt_handler,IRQF_SHARED, "MIS_GPIO", (void *)~MIS_GPIO) < 0)
    {
        RTK_GPIO_DBG("rtk_gpio_init failed, request misc irq %d failed\n",
                        IRQ_MISC);
        ret = -EIO;
        goto err_request_misc_irq_failed;
    }

    PowerOnGPIO();
#ifdef MIS_ISR_reg
    /* enable scpu gpio interrupt */
    gpio_iowrite32(gpio_ioread32(MIS_ISR_reg) | (0x1 << MIS_ISR_gpio_int_shift), MIS_ISR_reg);
#endif

    /* set GPIO  global interrupt to :*/
    gpio_iowrite32(GPIO_BOTH_INTERRUPT,MIS_GP_INT_SEL_reg);

    if(ISO_GPIO_CNT)
    {
        if(request_irq(IRQ_ISO, gpio_interrupt_handler, IRQF_SHARED, "ISO_GPIO",(void *)~ISO_GPIO) < 0)
        {
            RTK_GPIO_DBG("rtk_gpio_init failed,request iso irq %d failed\n",IRQ_ISO);
            ret = -EIO;
            goto err_request_iso_irq_failed;
        }

        #ifdef ISO_ISR_reg
            /* enable scpu gpio interrupt */
            gpio_iowrite32(gpio_ioread32(ISO_ISR_reg) | (0x1 << ISO_ISR_gpio_int_shift),ISO_ISR_reg);
        #endif
    }

    if (GPI_ISO_CNT)
    {
        if (request_irq(IRQ_ISO, gpio_interrupt_handler,IRQF_SHARED, "GPI_ISO", (void *)~ISO_GPIO) < 0)
        {
            RTK_GPIO_DBG("rtk_gpio_init failed,request iso irq %d failed\n",IRQ_ISO);
            ret = -EIO;
            goto err_request_iso_gpi_irq_failed;
        }

        #ifdef GPI_ISO_ISR_reg
            /* enable scpu gpio interrupt */
            gpio_iowrite32(gpio_ioread32(GPI_ISO_ISR_reg) |(0x1 << GPI_ISO_ISR_int_shift),GPI_ISO_ISR_reg);
        #endif
    }


#ifdef CONFIG_PM
    rtk_gpio_devs = platform_device_register_simple("rtk_gpio", -1, NULL, 0);

    if (platform_driver_register(&rtk_gpio_platform_driver) != 0)
    {
        RTK_GPIO_DBG("rtk_gpio_init failed, register platform device failed\n");
        ret = -EFAULT;
        goto err_register_platform_driver_failed;
    }
#endif

    rtk_gpio_register_gpio_chipset();

#ifdef CONFIG_RTK_KDRV_GPIO_BUILT_IN_TEST
    rtk_gpio_built_in_test();
#endif

#if 0
    rtk_gpio_micom();
#endif

    return 0;


#ifdef CONFIG_PM
err_register_platform_driver_failed:
    platform_device_unregister(rtk_gpio_devs);
    if( ISO_GPIO_CNT || GPI_ISO_CNT )
        free_irq(IRQ_ISO, gpio_interrupt_handler);
#endif


err_request_iso_irq_failed:
err_request_iso_gpi_irq_failed:
    free_irq(IRQ_ISO, gpio_interrupt_handler);

err_request_misc_irq_failed:
    return ret;
}

static void __exit rtk_gpio_exit(void)
{
    _rtk_gpio_disable_irq_all();
    _rtk_gpio_clear_isr_all();      /* clear all interrupts status*/

    free_irq(IRQ_MISC, gpio_interrupt_handler);

    if(ISO_GPIO_CNT || GPI_ISO_CNT)
        free_irq(IRQ_ISO, gpio_interrupt_handler);

#ifdef CONFIG_PM
    platform_device_unregister(rtk_gpio_devs);
    platform_driver_unregister(&rtk_gpio_platform_driver);
#endif
}


void rtk_gpio_lg_hal_int_isr(RTK_GPIO_ID gid, unsigned char assert, void* dev_id)
{
    //RTK_GPIO_WARNING("%s GPIO %d assert=%d, val=%d\n",
    //    gpio_type(gpio_group(gid)), gpio_idx(gid),
    //    assert, rtk_gpio_input(pin));
    //unsigned long flags;

        //spin_lock_irqsave(&rtk_gpio_irq_lock, flags);

    g_lg_hal_int_flag = 1;

    //spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);

}

EXPORT_SYMBOL(rtk_gpio_lg_hal_int_isr);


int rtk_gpio_get_irq_flag( RTK_GPIO_ID gid, unsigned char positive )
{

    unsigned long flags;
    int ret = 0;

    spin_lock_irqsave(&rtk_gpio_irq_lock, flags);

    if( 1 == g_lg_hal_int_flag )
    {
        g_lg_hal_int_flag = 0;
        rtk_gpio_free_irq(gid , rtk_gpio_lg_hal_int_isr );
        ret = 1;
    }
    else
    {
        ret = 0;
    }

    spin_unlock_irqrestore(&rtk_gpio_irq_lock, flags);

    return ret;
}

/*for new gpio function*/
void rtk_gpio_rtk_int_isr(RTK_GPIO_ID gid, unsigned char assert, void* dev_id)
{
    RTK_GPIO_IRQ *p_irq = _get_gpio_entry(gid);
    if (p_irq)
    {
        p_irq->trigger_type = assert;
        p_irq->irq_flag = 1;
    }
}

EXPORT_SYMBOL(rtk_gpio_rtk_int_isr);

int rtk_gpio_get_irq_flag_ex( RTK_GPIO_ID gid, unsigned char trigger_type )
{
    int ret = 0;
    RTK_GPIO_IRQ *p_irq = _get_gpio_entry(gid);
	
    if (p_irq)
    {
        if((trigger_type == GPIO_BOTH_EDGE) ||(trigger_type == p_irq->trigger_type)){
            ret = p_irq->irq_flag;
            if(p_irq->irq_flag){
                //rtk_gpio_free_irq(gid , rtk_gpio_rtk_int_isr );
                p_irq->irq_flag = 0;
            }
        }
    }
    return ret;
}

void rtk_gpio_init_pcb_pin(void){
    int i;
    int idx = 0;
    unsigned char pin_type;
    RTK_GPIO_ID gpio_id;
    unsigned char pin_index = 0;
    PCB_GPIO_TYPE_T input_type;
    unsigned char invert;
    unsigned char init_value=0;
    bool gpio_pin = true;
    RTK_GPIO_GROUP gpio_type;
	
    if(pPcbInfo==NULL)
        pPcbInfo = (RTK_GPIO_PCB_T*)kmalloc(sizeof(RTK_GPIO_PCB_T), GFP_KERNEL);
	
    memset(pPcbInfo,0,sizeof(RTK_GPIO_PCB_T));

    for(i = 0; i < PCB_ENUM_MAX; i++){
        if(pcb_enum_all[i].name[0]=='P'&&pcb_enum_all[i].name[1]=='I'&&pcb_enum_all[i].name[2]=='N'&&pcb_enum_all[i].value>0)
        {
            pin_type  = GET_PIN_TYPE(pcb_enum_all[i].value);
            pin_index = GET_PIN_INDEX(pcb_enum_all[i].value);
            input_type = GET_PIN_PARAM1(pcb_enum_all[i].value);
            invert    = GET_PIN_PARAM2(pcb_enum_all[i].value);
            init_value= GET_PIN_PARAM3(pcb_enum_all[i].value);
            gpio_pin = true;
            switch (pin_type) {
                case PCB_PIN_TYPE_GPIO:
                    gpio_id = rtk_gpio_id(MIS_GPIO, pin_index);
                    gpio_type = MIS_GPIO;
					break;
                case PCB_PIN_TYPE_ISO_GPIO:
                    gpio_id = rtk_gpio_id(ISO_GPIO, pin_index);
                    gpio_type = ISO_GPIO;
					break;
                case PCB_PIN_TYPE_GPO:
                    gpio_id = rtk_gpio_id(MIS_GPO, pin_index);
                    gpio_type = MIS_GPO;
					break;
                case PCB_PIN_TYPE_ISO_GPO:
                    gpio_id = rtk_gpio_id(ISO_GPO, pin_index);
                    gpio_type = ISO_GPO;
					break;
                case PCB_PIN_TYPE_GPI:
                    gpio_id = rtk_gpio_id(MIS_GPI, pin_index);
                    gpio_type = MIS_GPI;
					break;
                case PCB_PIN_TYPE_ISO_GPI:
                    gpio_id = rtk_gpio_id(ISO_GPI, pin_index);
                    gpio_type = ISO_GPI;
					break;
                default:
                    gpio_pin = false;
                    break;
            }
            if(gpio_pin)
            {
                strcpy(pPcbInfo->pcblist[idx].pin_name,pcb_enum_all[i].name);
                pPcbInfo->pcblist[idx].pin_type     = pin_type;
                pPcbInfo->pcblist[idx].pin_index    = pin_index;
                pPcbInfo->pcblist[idx].input_type   = input_type;
                pPcbInfo->pcblist[idx].invert       = invert;
                pPcbInfo->pcblist[idx].init_value   = init_value;
                pPcbInfo->pcblist[idx].gid          = gpio_id;
                pPcbInfo->pcblist[idx].gpio_type    = gpio_type;
                pPcbInfo->pcblist[idx].valid        = 1;
                idx++;
            }
            //RTK_GPIO_WARNING(" PIN !!!! , pcb name=%s ,value=%lld, pin_type=%d pin_index=%d, input_type=%d gpio_pin=%d\n",pcb_enum_all[i].name,pcb_enum_all[i].value,pin_type,pin_index,input_type,gpio_pin);
        }
            	
    }
    pPcbInfo->pcbcnt=idx;
#if 0
    RTK_GPIO_WARNING(" total gpio pin=%d\n",idx);
    for(i = 0; i < idx; i++){
        RTK_GPIO_PCBINFO_T pin = pPcbInfo->pcblist[i];
        RTK_GPIO_ERROR(" gpio pin_name=%s ,pin_type=%d, pin_index=%d, input_type=%d, invert=%d, init_value=%d, gid=%03x\n",
            pin.pin_name,pin.pin_type,pin.pin_index,pin.gpio_type,pin.invert,pin.init_value,pin.gid);
    }
#endif
}

int rtk_gpio_get_pcb_info(char* pinName,RTK_GPIO_PCBINFO_T*pInfo){
    int i;
    for(i = 0; i < MAX_PCB_GPIO_COUNT; i++){
        if(strcmp(pPcbInfo->pcblist[i].pin_name, pinName)==0){
            memcpy(pInfo,&pPcbInfo->pcblist[i],sizeof(RTK_GPIO_PCBINFO_T));
            return 0;
        }
    }
    return -1;
}

void rtk_gpio_get_all_pinInfo(RTK_GPIO_PCBINFO_T* pinInfolist,int *count){
    int i,idx=0;
    for(i = 0; i < pPcbInfo->pcbcnt; i++){
        if(pPcbInfo->pcblist[i].valid){
            memcpy(&pinInfolist[idx++],&pPcbInfo->pcblist[i],sizeof(RTK_GPIO_PCBINFO_T));
        }
    }
    *count = pPcbInfo->pcbcnt;
    RTK_GPIO_WARNING("rtk_gpio_copy_all_pinInfo total gpio pin= %d\n",idx);
}

void rtk_gpio_syncInfo_toDB(void)
{
    int i;
    GPIO_MAP_ENTRY *entry;
    entry = (GPIO_MAP_ENTRY*)kzalloc((pPcbInfo->pcbcnt)*sizeof(GPIO_MAP_ENTRY),GFP_KERNEL);
    for(i = 0;i < pPcbInfo->pcbcnt; i++){
        strcpy(entry[i].Name,pPcbInfo->pcblist[i].pin_name);
        entry[i].Type = pPcbInfo->pcblist[i].gpio_type;
        entry[i].Usage =
	            (pPcbInfo->pcblist[i].input_type == PCB_GPIO_TYPE_INPUT) ? GPIO_ALLOW_RD : GPIO_ALLOW_WR;
        entry[i].Number = pPcbInfo->pcblist[i].pin_index;
        rtk_gpio_array_add(&RTK_GPIO_DB,&entry[i]);
   }
}


fs_initcall(rtk_gpio_init);
module_exit(rtk_gpio_exit);

MODULE_AUTHOR("Chih-pin Wu, Realtek Semiconductor");
MODULE_LICENSE("GPL");
