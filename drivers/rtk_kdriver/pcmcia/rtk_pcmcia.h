/*
 *Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
 */
#ifndef __RTK_PCMCIA_H__
#define __RTK_PCMCIA_H__

#include <rtk_kdriver/rtk_gpio.h>
#include <asm/atomic.h>
#include <mach/rtk_log.h>

#undef  TAG_NAME
#define TAG_NAME  "PCMCIA"

#define MAX_PCMCIA_ENTRY     2

#define PCMCIA_OK            0
#define PCMCIA_FAIL         -1
#define PCMCIA_NODEV        -2

#define RTK_PCMCIA_STS_CARD_PRESENT   0x8000
#define RTK_PCMCIA_STS_ACCESS_FAULT   0x0800
#define RTK_PCMCIA_STS_IREQ_ASSERT    0x0080
#define RTK_PCMCIA_STS_DC_OFF_ON      0x4000

#define MINIMUM_PCMCIA_RESET_TIMEOUT    1000
#define DEFAULT_PCMCIA_RESET_TIMEOUT    3000  /* LG CI+ card needs to wait 2940ms*/
#define MAXIMUM_PCMCIA_RESET_TIMEOUT    10000

typedef enum
{
    RTK_PCMCIA_RESET_PULSE_WIDTH_114US = 0,
    RTK_PCMCIA_RESET_PULSE_WIDTH_1MS,
    RTK_PCMCIA_RESET_PULSE_WIDTH_2MS,
    RTK_PCMCIA_RESET_PULSE_WIDTH_20MS,
} RTK_PCMCIA_RESET_PULSE_WIDTH_TYPE;

typedef struct
{
    unsigned char id;
    unsigned char flags;
#define PCMCIA_WITH_POWER_CTRL_GPIO    0x80
#define PCMCIA_TX_ON                   0x40
#define PCMCIA_CARD_RESET_COMPLETE     0x1

    unsigned char event;
#define RTK_PCMCIA_EVENT_CARD_STATUS_CHANGE    0x1
#define RTK_PCMCIA_EVENT_IREQ_ASSERT           0x2

    unsigned char tx_status;

    unsigned char buff[4096];

    RTK_GPIO_ID    pwr_en_pin;
    RTK_GPIO_ID    int_pin;              //gpio interrupt pin

    wait_queue_head_t wq __attribute__ ((__aligned__(4)));

    spinlock_t    lock;
    spinlock_t    lock_int;
    atomic_t      atomic_init ;

    
    struct
    {
        unsigned long CE;
        unsigned long PCR_OE;
        unsigned long PRES;
        unsigned long PII;
        unsigned long PCR;
        unsigned long CD_INT;    /* card detect interrupt */
    } reg_bits;

    int skipTime;
} RTK_PCMCIA;

#define PCMCIA_FLAGS_ATTR       0x80
#define PCMCIA_FLAGS_IO         0x00
#define PCMCIA_FLAGS_FIFO       0x08    /* this is a fifo */
#define PCMCIA_FLAGS_RD         0x01
#define PCMCIA_FLAGS_WR         0x00
#define PCMCIA_FLAGS_FIFO_MODE  0x40

typedef struct
{
    unsigned char  flags;
    unsigned short addr;
    unsigned char  data;
} RTK_PCMCIA_RW;

typedef struct
{
    unsigned char   flags;
    unsigned short  addr;
    unsigned short  len;
    unsigned char  *p_data;
} RTK_PCMCIA_MULTI_RW;

#ifdef CONFIG_COMPAT
typedef struct
{
    unsigned char   flags;
    unsigned short  addr;
    unsigned short  len;
    unsigned int    p_data;
} COMPAT_RTK_PCMCIA_MULTI_RW;
#endif

/******************** CFG  **************************/

/**************************************
 * PCMCIA Command format
 **************************************
    D63     : skip pcmcia timming configuration (0: set up pcmcia bus timing in driver, 1: don't set up pcmcia timing config in the driver)
    D62:32  : reserved
    D31:25  : pcmcia_cd0                (card detection for PCMCIA0)
    D24     : ce1/ce2 swap              (0: no swap ce1/ce2, 1: swap ce1/ce2)
    D23     : pcmcia1_enable            (0: don't enable pcmcia1, enable pcmcia1)
    D22     : pcmcia1_pwr_en_valid      (0: no power_enable_gpio, 1: with power_enable_gpio)
    D21     : pcmcia1_pwr_en_polarity   (0: negative, 1: positive)
    D20     : pcmcia1_pwr_en_gpio_type  (0: MISC, 1: ISO)
    D19     : pcmcia0_enable            (0: don't enable pcmcia1, enable pcmcia1)
    D18     : pcmcia0_pwr_en_valid      (0: no power_enable_gpio, 1: with power_enable_gpio)
    D17     : pcmcia0_pwr_en_polarity   (0: negative, 1: positive)
    D16     : pcmcia0_pwr_en_gpio_type  (0: MISC, 1: ISO)
    D15:8   : pcmcia1_pwr_en_gpio       (power_eanble_gpio for PCMCIA1)
    D7:0    : pcmcia0_pwr_en_gpio       (power_eanble_gpio for PCMCIA0)
 **************************************/

/**********************PCMCIA CFG3 format************************
*    D63:6    : reserved
*    D5-3    : pcmcia_reset_pluse_width   (0x001: 114us, 0x010:1ms, 0x011:2ms, 0x100:20ms)
*    D2        : pcmcia_reset_without_ireq_check_en  (0: disable, 1: enable)
*    D1        : pcmcia_auto_pin_share_mode       (0: sw mode, 1:hw mode)
*    D0        : pcmcia_auto_pin_share_en       (0: disable, 1: enable)
****************************************************************/

#define RTK_PCMCIA_CFG_SKIP_DRIVERS_TIMING_CONFIGURATION    (((unsigned long long)1)<<63)
#define RTK_PCMCIA_CFG_CE_SWAP                              (1<<24)
#define RTK_PCMCIA_CFG_PCMCIA1_EN                           (1<<23)
#define RTK_PCMCIA_CFG_PCMCIA1_PWR_EN_VALID                 (1<<22)
#define RTK_PCMCIA_CFG_PCMCIA1_PWR_EN_POAL                  (1<<21)
#define RTK_PCMCIA_CFG_PCMCIA1_PWR_EN_GPIO_TYPE             (1<<20)
#define RTK_PCMCIA_CFG_PCMCIA0_EN                           (1<<19)
#define RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID                 (1<<18)
#define RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_POAL                  (1<<17)
#define RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_GPIO_TYPE             (1<<16)

#define PCMCIA_CD_SET(x)                 ((x & 0x7f) << 25)
#define PCMCIA_CE_SWAP(x)                ((x & RTK_PCMCIA_CFG_CE_SWAP) ? 1 : 0)

#define PCMCIA1_EN(x)                    ((x & RTK_PCMCIA_CFG_PCMCIA1_EN) ? 1 : 0)
#define PCMCIA1_PWR_EN_VALID(x)          ((x & RTK_PCMCIA_CFG_PCMCIA1_PWR_EN_VALID) ? 1 : 0)
#define PCMCIA1_PWR_EN_GPIO_TYPE(x)      ((x & RTK_PCMCIA_CFG_PCMCIA1_PWR_EN_GPIO_TYPE) ? ISO_GPIO : MIS_GPIO)
#define PCMCIA1_PWR_EN_GPIO(x)           ((x >> 8) & 0xFF)

#define PCMCIA0_EN(x)                    ((x & RTK_PCMCIA_CFG_PCMCIA0_EN) ? 1 : 0)
#define PCMCIA0_PWR_EN_VALID(x)          ((x & RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_VALID) ? 1 : 0)
#define PCMCIA0_PWR_EN_GPIO_TYPE(x)      ((x & RTK_PCMCIA_CFG_PCMCIA0_PWR_EN_GPIO_TYPE) ? ISO_GPIO : MIS_GPIO)
#define PCMCIA0_PWR_EN_GPIO(x)           (x&0xFF)

#define RTK_PCMCIA_CFG_PCMCIA_INT_VALID               (1<<18)
#define RTK_PCMCIA_CFG_PCMCIA_INT_POAL                (1<<17)
#define RTK_PCMCIA_CFG_PCMCIA_INT_GPIO_TYPE           (1<<16)
#define RTK_PCMCIA_CFG_AUTO_PIN_SHARE_EN              (1<<0)
#define RTK_PCMCIA_CFG_FIFO_FUNC_PIN_SHARE_MODE       (1<<1)
#define RTK_PCMCIA_CFG_RESET_WIHOUT_IREQ_CHECCK_EN    (1<<2)
#define RTK_PCMCIA_CFG_CD_SEPEARTE_2PIN               (1<<8)

#define PCMCIA_INT_VALID(x)        ((x & RTK_PCMCIA_CFG_PCMCIA_INT_VALID) ? 1 : 0)
#define PCMCIA_INT_GPIO_TYPE(x)    ((x & RTK_PCMCIA_CFG_PCMCIA_INT_GPIO_TYPE) ? ISO_GPIO : MIS_GPIO)
#define PCMCIA_INT_GPIO(x)         (x&0xFF)

#define PCMCIA_AUTO_PIN_SHARE_EN(x)           ((x & RTK_PCMCIA_CFG_AUTO_PIN_SHARE_EN) ? 1 : 0)
#define PCMCIA_FIFO_FUNC_PIN_SHARE_MODE(x)    ((x & RTK_PCMCIA_CFG_FIFO_FUNC_PIN_SHARE_MODE) ? 1 : 0)
#define PCMCIA_RESET_WIHOUT_IREQ_CHECCK(x)    (( x & RTK_PCMCIA_CFG_RESET_WIHOUT_IREQ_CHECCK_EN) ? 1 : 0)
#define PCMCIA_GET_RESET_PLUSE_WIDTH_TYPE(x)  (((x) >> 3) & 0x7)
#define PCMCIA_CD_SEPERATE_2PIN(x)            ((x & RTK_PCMCIA_CFG_CD_SEPEARTE_2PIN) ? 1 : 0)

/********************** APIs  *************************/
int rtk_pcmcia_card_enable(RTK_PCMCIA *p_this, unsigned char On);
int rtk_pcmcia_get_card_status(RTK_PCMCIA *p_this);

/********************** IOCTL  ************************/

#define RTK_PCMCIA_IOC_MAGIC              'p'
#define RTK_PCMCIA_IOC_ENABLE             _IOW(RTK_PCMCIA_IOC_MAGIC, 1, int)
#define RTK_PCMCIA_IOC_CARD_RESET         _IOW(RTK_PCMCIA_IOC_MAGIC, 2, int)
#define RTK_PCMCIA_IOC_GET_CARD_STATUS    _IOR(RTK_PCMCIA_IOC_MAGIC, 3, int)
#define RTK_PCMCIA_IOC_READ_WRITE         _IOR(RTK_PCMCIA_IOC_MAGIC, 4, RTK_PCMCIA_RW*)
#define RTK_PCMCIA_IOC_MULTI_READ_WRITE   _IOR(RTK_PCMCIA_IOC_MAGIC, 5, RTK_PCMCIA_MULTI_RW*)
#define RTK_PCMCIA_IOC_PROBE_COMMAND      _IOR(RTK_PCMCIA_IOC_MAGIC, 6, unsigned long)
#define RTK_PCMCIA_IOC_POLL_EVENT         _IOR(RTK_PCMCIA_IOC_MAGIC, 7, unsigned long)
#define RTK_PCMCIA_IOC_INIT_COMMAND       _IOR(RTK_PCMCIA_IOC_MAGIC, 8, unsigned long)
#define RTK_PCMCIA_IOC_DEINIT_COMMAND     _IOR(RTK_PCMCIA_IOC_MAGIC, 9, unsigned long)


#ifdef CONFIG_COMPAT
#define COMPAT_RTK_PCMCIA_IOC_READ_WRITE         _IOR(RTK_PCMCIA_IOC_MAGIC, 4, unsigned int)
#define COMPAT_RTK_PCMCIA_IOC_MULTI_READ_WRITE   _IOR(RTK_PCMCIA_IOC_MAGIC, 5, unsigned int)
#define COMPAT_RTK_PCMCIA_IOC_PROBE_COMMAND      _IOR(RTK_PCMCIA_IOC_MAGIC, 6, unsigned int)
#define COMPAT_RTK_PCMCIA_IOC_POLL_EVENT         _IOR(RTK_PCMCIA_IOC_MAGIC, 7, unsigned int)
#define COMPAT_RTK_PCMCIA_IOC_INIT_COMMAND       _IOR(RTK_PCMCIA_IOC_MAGIC, 8, unsigned int)
#define COMPAT_RTK_PCMCIA_IOC_DEINIT_COMMAND     _IOR(RTK_PCMCIA_IOC_MAGIC, 9, unsigned int)
#endif

/********************* DBG  ***************************/
/* #define PCMCIA_DBG_EN */
#ifdef PCMCIA_DBG_EN
#define PCMCIA_DBG(fmt, args...)            rtd_printk(KERN_DEBUG, TAG_NAME,"[DBG] " fmt, ## args)
#else    /*
 */
#define PCMCIA_DBG(fmt, args...)
#endif    /*
 */

#define PCMCIA_INFO(fmt, args...)       rtd_printk(  KERN_INFO , TAG_NAME,  "[Info] " fmt, ## args)
#define PCMCIA_WARNING(fmt, args...)    rtd_printk( KERN_WARNING , TAG_NAME, "[Warn] " fmt, ## args)
#define PCMCIA_ERROR(fmt, args...)      rtd_printk( KERN_EMERG , TAG_NAME, "[ERROR] " fmt, ## args)

#endif
