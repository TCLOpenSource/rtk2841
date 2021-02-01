#ifndef MISC_EXPORT_H
#define MISC_EXPORT_H

#include <linux/types.h>

struct misc_dev {
    struct semaphore sem;     /* mutual exclusion semaphore     */
    struct cdev cdev;   /* Char device structure          */
};

/*
 * Ioctl definitions
 */
// #define SUPPORT_DCU2
typedef enum
{
        RHAL_SYS_CMD_SET_SPREAD_SPRECTRUM = 0,
        RHAL_SYS_CMD_GET_SPREAD_SPRECTRUM,
        RHAL_SYS_CMD_SET_DDR_PERIOD,
        RHAL_SYS_CMD_GET_DDR_PERIOD,
        RHAL_SYS_CMD_GET_SUPPORT_MODULE,
} RHAL_SYS_CMD_DDR_SSC_T;

/* SPREAD SPECTRUM ENUMERATIONS HAVE TO BE SAME AS KAPI */
typedef enum
{
        RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR = 0,		// include ddr1
#ifdef SUPPORT_DCU2
        RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR2,                          // include ddr2 only
#endif
        RHAL_SYS_SPREAD_SPECTRUM_MODULE_MAX,
} RHAL_SYS_SPREAD_SPRECTRUM_MODULE_T;

typedef enum
{
        RHAL_SYS_SPREAD_SPECTRUM_OFF = 0,               // 0.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_0_25,        // -0.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_0_50,        // -0.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_0_75,        // -0.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_1_00,        // -1.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_1_25,        // -1.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_1_50,        // -1.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_1_75,        // -1.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_2_00,        // -2.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_2_25,        // -2.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_2_50,        // -2.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_2_75,        // -2.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_3_00,        // -3.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_3_25,        // -3.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_3_50,        // -3.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_3_75,        // -3.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_4_00,        // -4.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_4_25,        // -4.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_4_50,        // -4.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_4_75,        // -4.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_5_00,        // -5.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_5_25,        // -5.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_5_50,        // -5.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_5_75,        // -5.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_6_00,        // -6.00%
        
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_25,        // +0.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_50,        // +0.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_75,        // +0.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_00,        // +1.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_1_25,        // +1.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_1_50,        // +1.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_1_75,        // +1.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_2_00,        // +2.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_2_25,        // +2.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_2_50,        // +2.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_2_75,        // +2.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_3_00,        // +3.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_3_25,        // +3.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_3_50,        // +3.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_3_75,        // +3.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_4_00,        // +4.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_4_25,        // +4.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_4_50,        // +4.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_4_75,        // +4.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_5_00,        // +5.00%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_5_25,        // +5.25%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_5_50,        // +5.50%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_5_75,        // +5.75%
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_6_00,        // +6.00%

        RHAL_SYS_SPREAD_SPECTRUM_RATIO_MAX,
} RHAL_SYS_SPREAD_SPECTRUM_RATIO_T;

typedef enum
{
        RHAL_SYS_DDR_PERIOD_30K = 0,
        RHAL_SYS_DDR_PERIOD_33K,                    
        RHAL_SYS_DDR_PERIOD_60K,
        RHAL_SYS_DDR_PERIOD_66K,
        RHAL_SYS_DDR_PERIOD_MAX,
} RHAL_SYS_DDR_PERIOD_T;

typedef struct
{
        RHAL_SYS_CMD_DDR_SSC_T cmd;
        RHAL_SYS_SPREAD_SPRECTRUM_MODULE_T module;
        RHAL_SYS_SPREAD_SPECTRUM_RATIO_T ratio;
        RHAL_SYS_DDR_PERIOD_T period;
        unsigned char module_support;
} DDR_SSC_PARA;

/* pinmux enable for uart0 or uart1*/
typedef enum
{
        UART0_PINMUX_ENABLE = 0,
        UART1_PINMUX_ENABLE,
        UART0_UART1_PINMUX_DISABLE,
} UART_PINMUX_ENABLE_T;

/* Use 's' as magic number */
#define MISC_IOC_MAGIC  's'

#define MISC_WAKEUP_ECPU    		_IO(MISC_IOC_MAGIC, 0)
#define MISC_SET_WOL_ENABLE    		_IOW(MISC_IOC_MAGIC, 1,int)
#define MISC_GET_WOL_ENABLE    		_IOR(MISC_IOC_MAGIC, 2,int*)
#define MISC_SET_DEBUG_LOCK    		_IOW(MISC_IOC_MAGIC, 3,int)
#define MISC_SET_DDR_SSC_PARAM    	_IOWR(MISC_IOC_MAGIC, 6,void *)

#define MISC_SET_RTDLOG          _IOW(MISC_IOC_MAGIC, 7, unsigned int)
#define MISC_GET_RTDLOG          _IOR(MISC_IOC_MAGIC, 8, unsigned int*)
//#define MISC_SET_RTDLOG_MODULE          _IOW(MISC_IOC_MAGIC, 9, unsigned int)
//#define MISC_GET_RTDLOG_MODULE          _IOR(MISC_IOC_MAGIC, 10, unsigned int*)
#define MISC_SET_WARM_WOL_ENABLE    		_IOW(MISC_IOC_MAGIC, 11,int)
#define MISC_GET_WARM_WOL_ENABLE    		_IOR(MISC_IOC_MAGIC, 12,int*)
#define MISC_QSM_OFF                        _IO(MISC_IOC_MAGIC, 13)
#ifdef CONFIG_RTK_KDRV_WATCHDOG
#define MISC_SET_WATCHDOG_ENABLE     _IOW(MISC_IOC_MAGIC, 14, int)
#endif
#define MISC_UART_PINMUX_SWITCH                   _IOW(MISC_IOC_MAGIC, 17,int)
#define MISC_UART_GET_UART0_ENABLE                _IOW(MISC_IOC_MAGIC, 18,unsigned int*)
#define MISC_UART_GET_UART1_ENABLE                _IOW(MISC_IOC_MAGIC, 19,unsigned int*)

#endif
