#ifndef __IR_DEBUG_H__
#define __IR_DEBUG_H__
#include <mach/rtk_log.h>

extern bool ir_decode_dbg_en;

#define TAG_NAME            "IR"

#define IR_DBG(fmt, args...)            \
{ \
    if(unlikely(ir_decode_dbg_en)) { \
        rtd_printk(KERN_INFO, TAG_NAME,"[DBG] " fmt, ## args);  \
    } \
}

#define IR_INFO(fmt, args...)       rtd_printk(KERN_INFO, TAG_NAME, "[Info] " fmt, ## args)
#define IR_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, TAG_NAME, "[Warn] " fmt, ## args)
#define IR_ERR(fmt, args...)        rtd_printk( KERN_ERR, TAG_NAME, "[Err] " fmt, ## args)
#define IR_ALERT(fmt, args...)      rtd_printk( KERN_ALERT, TAG_NAME, "[Alert] " fmt, ## args)


#endif
