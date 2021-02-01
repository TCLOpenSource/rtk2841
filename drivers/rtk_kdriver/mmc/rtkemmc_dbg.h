#ifndef _MMC_RTK_DEBUG_H
#define _MMC_RTK_DEBUG_H


#include <mach/rtk_log.h>
#define DEV_NAME "EMMC"

/************************************************************************
 *  rtk log define
 ************************************************************************/
#define EM_EMERG(fmt, args...)      \
	rtd_printk( KERN_EMERG, DEV_NAME, fmt , ## args)

#define EM_ALERT(fmt, args...)   \
	rtd_printk( KERN_ALERT, DEV_NAME, fmt , ## args)

#define EM_CRIT(fmt, args...)   \
	rtd_printk( KERN_CRIT, DEV_NAME, fmt , ## args)

#define EM_ERR(fmt, args...)   \
	rtd_printk( KERN_ERR, DEV_NAME, fmt , ## args)

#define EM_WARNING(fmt, args...)   \
	rtd_printk( KERN_WARNING, DEV_NAME, fmt , ## args)

#define EM_NOTICE(fmt, args...)   \
	rtd_printk( KERN_NOTICE, DEV_NAME, fmt , ## args)

#define EM_INFO(fmt, args...)   \
	rtd_printk( KERN_INFO, DEV_NAME, fmt , ## args)

#define EM_DEBUG(fmt, args...)   \
	rtd_printk( KERN_DEBUG, DEV_NAME, fmt , ## args)


/************************************************************************
 *  emmc local dbg define
 ************************************************************************/
/* #define MMC_DEBUG */
#ifdef MMC_DEBUG
    #define mmcinfo(fmt, args...) \
               printk(KERN_ALERT "mmc:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcinfo(fmt, args...)
#endif

/* #define MMC_CORE */
#ifdef MMC_CORE
    #define mmcore(fmt, args...) \
           printk(KERN_ALERT "mmcore:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcore(fmt, args...)
#endif

/* #define MMC_CARD */
#ifdef MMC_CARD
    #define mmcard(fmt, args...) \
           printk(KERN_ALERT "mmcard:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcard(fmt, args...)
#endif

/* #define MMC_RTK */
#ifdef MMC_RTK
    #define mmcrtk(fmt, args...) \
           printk(KERN_ALERT "mmcrtk:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcrtk(fmt, args...)
#endif

/* #define MMC_SPEC */
#ifdef MMC_SPEC
    #define mmcspec(fmt, args...) \
           printk(KERN_ALERT "mmcspec:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcspec(fmt, args...)
#endif

/* #define MMC_MSG1 */
#ifdef MMC_MSG1
    #define mmcmsg1(fmt, args...) \
           printk(KERN_ALERT "mmcmsg1:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcmsg1(fmt, args...)
#endif

/* #define MMC_MSG2 */
#ifdef MMC_MSG2
    #define mmcmsg2(fmt, args...) \
           printk(KERN_ALERT "mmcmsg2:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcmsg2(fmt, args...)
#endif

/* #define MMC_MSG3 */
#ifdef MMC_MSG3
    #define mmcmsg3(fmt, args...) \
           printk(KERN_ALERT "mmcmsg3:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcmsg3(fmt, args...)
#endif

/* #define MMC_MSG4 */
#ifdef MMC_MSG4
    #define mmcmsg4(fmt, args...) \
           printk(KERN_ALERT "mmcmsg4:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcmsg4(fmt, args...)
#endif


/* #define MMC_TRH */
#ifdef MMC_TRH
    #define trhmsg(fmt, args...) \
           printk(KERN_ALERT "trhmsg:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define trhmsg(fmt, args...)
#endif

/* #define MMC_RAW */
#ifdef MMC_RAW
    #define mmcraw(fmt, args...) \
           printk(KERN_ALERT "rawmsg:%s(%d):" fmt, __func__ ,__LINE__,## args)
#else
    #define mmcraw(fmt, args...)
#endif


#endif










