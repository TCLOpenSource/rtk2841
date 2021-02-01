#ifndef __RTKSDIO_DBG_H
#define __RTKSDIO_DBG_H


#include <mach/rtk_log.h>
#define TAG_NAME ("CR")

#define CR_EMERG(fmt, args...)      \
	rtd_printk( KERN_EMERG, TAG_NAME, fmt , ## args)

#define CR_ALERT(fmt, args...)   \
	rtd_printk( KERN_ALERT, TAG_NAME, fmt , ## args)

#define CR_CRIT(fmt, args...)   \
	rtd_printk( KERN_CRIT, TAG_NAME, fmt , ## args)

#define CR_ERR(fmt, args...)   \
	rtd_printk( KERN_ERR, TAG_NAME, fmt , ## args)

#define CR_WARNING(fmt, args...)   \
	rtd_printk( KERN_WARNING, TAG_NAME, fmt , ## args)

#define CR_NOTICE(fmt, args...)   \
	rtd_printk( KERN_NOTICE, TAG_NAME, fmt , ## args)

#define CR_INFO(fmt, args...)   \
	rtd_printk( KERN_INFO, TAG_NAME, fmt , ## args)

#define CR_DEBUG(fmt, args...)   \
	rtd_printk( KERN_DEBUG, TAG_NAME, fmt , ## args)

#endif
