/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2013 *
 * All rights reserved.                                       *
 *============================================================*/

#ifndef AUDIO_HW_LOG_H
#define AUDIO_HW_LOG_H

#include <linux/kernel.h>
#include <linux/time.h>
#include <mach/rtk_log.h>

#define __ALOG_TAG "AudioHW"

#ifndef __ALOG_SUBTAG
#define __ALOG_TIME_TAG	"[%ld:%06ld] "
#else
#define __ALOG_TIME_TAG	"[%ld:%06ld][" __ALOG_SUBTAG "] "
#endif

#ifdef __ALOG_ENABLE
#define alog_emerg(fmt, ...)	\
	rtd_printk(KERN_EMERG, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_alert(fmt, ...)	\
	rtd_printk(KERN_ALERT, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_crit(fmt, ...)	\
	rtd_printk(KERN_CRIT, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_err(fmt, ...)	\
	rtd_printk(KERN_ERR, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_warning(fmt, ...)	\
	rtd_printk(KERN_WARNING, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_notice(fmt, ...)	\
	rtd_printk(KERN_NOTICE, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_info(fmt, ...)	\
	rtd_printk(KERN_INFO, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog_debug(fmt, ...)	\
	rtd_printk(KERN_DEBUG, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#define alog(fmt, ...)		\
	rtd_printk(KERN_DEFAULT, __ALOG_TAG, rtd_fmt(__ALOG_SUBTAG, fmt), ##__VA_ARGS__)
#else
#define alog_emerg(fmt, ...)	((void)0)
#define alog_alert(fmt, ...)	((void)0)
#define alog_crit(fmt, ...)	((void)0)
#define alog_err(fmt, ...)	((void)0)
#define alog_warning(fmt, ...)	((void)0)
#define alog_notice(fmt, ...)	((void)0)
#define alog_info(fmt, ...)	((void)0)
#define alog_debug(fmt, ...)	((void)0)
#define alog(fmt, ...)		((void)0)
#endif

#ifdef __ALOG_CHK_ENABLE
extern bool alog_chk_enable(void);
extern struct timeval alog_chk_gettimeofday(void);

#define alog_chk(fmt, ...) \
(void)({ \
	bool check__ = alog_chk_enable(); \
	struct timeval t___ = alog_chk_gettimeofday(); \
	if (check__) { \
		rtd_printk(KERN_DEFAULT, __ALOG_TAG, __ALOG_TIME_TAG fmt, \
			t___.tv_sec & 0xffff, t___.tv_usec, ##__VA_ARGS__); \
	} \
	(void)check___; \
})
#else
#define alog_chk(fmt, ...)	((void)0)
#endif

#endif
