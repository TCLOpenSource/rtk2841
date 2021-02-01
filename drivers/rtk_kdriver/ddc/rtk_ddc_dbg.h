#ifndef __RTK_DDC_DBG_H__
#define __RTK_DDC_DBG_H__
#include <mach/rtk_log.h>
#define TAG_NAME                        "DDC"

extern int g_rtk_ddc_dbg;

#define RTK_DDC_DBG(fmt, args...)            \
{ \
    if(unlikely(g_rtk_ddc_dbg)) { \
        rtd_printk(KERN_ERR, TAG_NAME,"[DBG] " fmt, ## args);  \
    } \
}

#define RTK_DDC_INFO(fmt, args...)      rtd_printk(KERN_INFO, TAG_NAME, "[Info] " fmt, ## args)
#define RTK_DDC_WARNING(fmt, args...)   rtd_printk(KERN_WARNING, TAG_NAME, "[Warn] " fmt, ## args)
#define RTK_DDC_ERR(fmt, args...)       rtd_printk( KERN_ERR, TAG_NAME, "[Err] " fmt, ## args)
#define RTK_DDC_ALERT(fmt, args...)     rtd_printk( KERN_ALERT, TAG_NAME, "[Alert] " fmt, ## args)

#endif
