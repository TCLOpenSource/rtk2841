#ifndef _LINUX_RTKAUDIO_DEBUG_H
#define _LINUX_RTKAUDIO_DEBUG_H


#define RTD_PRINT_AUDIO_EANBLE

#ifdef RTD_PRINT_AUDIO_EANBLE
#include <mach/rtk_log.h>

#undef pr_debug
#undef pr_info
#undef pr_notice
#undef pr_warning
#undef pr_err
#undef pr_crit
#undef pr_alert
#undef pr_emerg

#define TAG_NAME "ADSP"

#define pr_debug(format, args...)   rtd_printk(KERN_DEBUG, TAG_NAME, format, ## args)
#define pr_info(format, args...)    rtd_printk(KERN_INFO, TAG_NAME, format, ## args)
#define pr_notice(format, args...)  rtd_printk(KERN_NOTICE, TAG_NAME, format, ## args)
#define pr_warning(format, args...) rtd_printk(KERN_WARNING, TAG_NAME, format, ## args)
#define pr_err(format, args...)     rtd_printk(KERN_ERR, TAG_NAME, format, ## args)
#define pr_crit(format, args...)    rtd_printk(KERN_CRIT, TAG_NAME, format, ## args)
#define pr_alert(format, args...)   rtd_printk(KERN_ALERT, TAG_NAME, format, ## args)
#define pr_emerg(format, args...)   rtd_printk(KERN_EMERG, TAG_NAME, format, ## args)
#endif

enum DUMP_ID {
	DUMP_STOP = 0,
	DUMP_LOG = 1,
	DUMP_PP_FOCUS,
	DUMP_AO_PCM,
	DUMP_AO_RAW
};

int rtkaudio_dump_enable(unsigned int db_command);
void rtkaudio_dump_disable(unsigned int db_command);
void rtkaudio_send_string(const char* pattern, int length);
#endif
