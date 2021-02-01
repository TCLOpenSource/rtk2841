#ifndef __RTK_SCD_DEBUG_H__
#define __RTK_SCD_DEBUG_H__
#undef SCD_TAG_NAME
#define SCD_TAG_NAME "SCD"
#include <mach/rtk_log.h>

/*-- scd debug messages--*/
//#define CONFIG_SMARTCARD_DBG
/*#define CONFIG_SCD_INT_DBG
#define CONFIG_SCD_TX_DBG
#define CONFIG_SCD_RX_DBG*/
extern unsigned char smc_log_onoff;


#define SMC_PROC_DIR				"rhal_smc"
#define SMC_PROC_ENTRY     			"dbg"

#define SMC_PROC_PARAM_DEBUG_ON		"debug_on=1"
#define SMC_PROC_PARAM_DEBUG_OFF    "debug_on=0"
#define SMC_PROC_PARAM_ON_APDU   	"print_rtx=1"
#define SMC_PROC_PARAM_OFF_APDU  	"print_rtx=0"

typedef enum
{
	SMC_PROC_DEBUG_ON,
	SMC_PROC_DEBUG_OFF,
	SMC_PROC_ON_APDU,
	SMC_PROC_OFF_APDU,
	SMC_PROC_COUNT ,
}SMC_PROC_INDEX;


unsigned int create_smc_controller(void);


#ifdef CONFIG_SMARTCARD_DBG
#define SC_DBG   rtd_printk(KERN_WARNING, SCD_TAG_NAME, " DBG, " fmt, ## args)
#else
#define SC_DBG(args...)
#endif

#ifdef CONFIG_SCD_INT_DBG
#define SC_INT_DBG(fmt, args...)                   rtd_printk(KERN_WARNING, SCD_TAG_NAME, " INT, " fmt, ## args)
#else
#define SC_INT_DBG(args...)
#endif

#define  SC_ERR(fmt, args...)                                      rtd_printk(KERN_ERR, SCD_TAG_NAME, " ERR, " fmt, ## args)

#define SC_PRINT_AWAYS(fmt, args...)   rtd_printk(KERN_WARNING, SCD_TAG_NAME, " AWAYS, " fmt, ## args)

#define SC_INFO(fmt, args...)  \
{   \
             if(smc_log_onoff)\
             {\
                 rtd_printk(KERN_WARNING, SCD_TAG_NAME, " Info, " fmt, ## args);\
                 }\
}
#define SC_WARNING(fmt, args...)   \
{\
             if(smc_log_onoff)\
             {\
                   rtd_printk(KERN_WARNING, SCD_TAG_NAME, " Warning, " fmt, ## args);\
                   }\
}

#define SC_ATR_DBG(fmt, args...)\
{\
             if(smc_log_onoff)\
             {\
                  rtd_printk(KERN_WARNING, SCD_TAG_NAME, " " fmt, ## args);\
                  }\
}

#define SC_PRINTK(fmt, args...) \
{\
             if(smc_log_onoff)\
             {\
                  rtd_printk(KERN_WARNING, SCD_TAG_NAME, fmt, ## args);\
             }\
}



#endif /*__SCD_DEBUG_H__*/

