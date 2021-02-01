#ifndef VIDEO_LOG_H
#define VIDEO_LOG_H

#include <mach/rtk_log.h>			/**< rtd_printk function */

/* emergency */
#define video_logk(fmt, ...) \
	rtd_printk(KERN_EMERG, "VIDEO", "[M]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* error */
#define video_loge(fmt, ...) \
	rtd_printk(KERN_ERR, "VIDEO", "[E]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* warning */
#define video_logw(fmt, ...) \
	rtd_printk(KERN_WARNING, "VIDEO", "[W]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* information */
#define video_logi(fmt, ...) \
	rtd_printk(KERN_NOTICE, "VIDEO", "[I]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* debug */
#define video_logd(fmt, ...) \
	rtd_printk(KERN_INFO, "VIDEO", "[D]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* verbose */
#define video_logv(fmt, ...) \
	rtd_printk(KERN_DEBUG, "VIDEO", "[V]["VIDEO_LOG"]" fmt, ##__VA_ARGS__)

/* log function name */
#define video_logf() \
	rtd_printk(KERN_INFO, "VIDEO", "[V]["VIDEO_LOG"]%s()\n", __FUNCTION__)

#define video_logl() \
	rtd_printk(KERN_INFO, "VIDEO", "[V]["VIDEO_LOG"]L:%d\n", __LINE__)

#endif /* VIDEO_LOG_H */
