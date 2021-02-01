#ifndef __RTICE_DEBUG_H__
#define __RTICE_DEBUG_H__


/*#define DEBUG_RTICE_CMD*/
/*#define DEBUG_RTICE*/ 
/*#define DEBUG_RTICE_TIMEOUT*/
/*#define DEBUG_TM_USED*/
#ifdef DEBUG_RTICE
#define RTICE_DEBUG(fmt, args...) \
	do{\
		printk(KERN_DEBUG fmt, ##args);\
		rtice_print_string(fmt, ##args);\
	}while(0)
#else
#define RTICE_DEBUG(args...)
#endif

#ifdef DEBUG_TM_USED
extern void rtice_tm_start();
extern unsigned int rtice_tm_end();
#define RTICE_TM_START rtice_tm_start();
#define RTICE_TM_END rtice_tm_end()
#else
#define RTICE_TM_START
#define RTICE_TM_END 0
#endif


#ifdef DEBUG_RTICE_CMD
#define RTICE_CMD_DEBUG(pData, len, fmt, args...) \
	do{\
		printk(KERN_DEBUG fmt, ##args); \
		rtice_print_array(fmt, pData, len); \
	} while(0)
#else
#define RTICE_CMD_DEBUG(args...)
#endif

#define RTICE_CMD_WARNING(fmt, args...)  printk(fmt, ##args)

#define RTICE_DEBUG_REG 0xb802a100
#ifdef DEBUG_RTICE_TIMEOUT
#define RTICE_TIMEOUT_REG RTICE_DEBUG_REG
#endif

#endif // __RTICE_DEBUG_H__
