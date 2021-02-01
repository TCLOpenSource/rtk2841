#ifndef __RTK_MD_DEBUG_H__
#define __RTK_MD_DEBUG_H__
#include <mach/rtk_log.h>
#ifdef MD_DEBUG
#define PDEBUG(fmt, args...) rtd_printk( KERN_DEBUG, "MD", fmt, ## args)
#else
#define PDEBUG(fmt, args...)
#endif
#define PDEIFO(fmt, args...) rtd_printk( KERN_INFO, "MD", fmt, ## args)
#define PDEWAR(fmt, args...) rtd_printk( KERN_WARNING , "MD", fmt, ## args)
#define PDEERR(fmt, args...) rtd_printk( KERN_ERR, "MD", fmt, ## args)
#define PDEALT(fmt, args...) rtd_printk( KERN_ALERT, "MD", fmt, ## args)

#endif

