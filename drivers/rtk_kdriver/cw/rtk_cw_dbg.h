#ifndef __RTK_CW_DBG_H__
#define __RTK_CW_DBG_H__
#include <mach/rtk_log.h>

#define CW_DBG(fmt, args...)        rtd_printk(KERN_DEBUG, "CW", "[DBG] " fmt, ##args)
#define CW_INFO(fmt, args...)       rtd_printk(KERN_INFO, "CW", "[Info] " fmt, ##args)
#define CW_WARNING(fmt, args...)    rtd_printk(KERN_WARNING, "CW", "[Warn] " fmt, ##args)
#define CW_ERR(fmt, args...)        rtd_printk(KERN_ERR, "CW", "[Err] " fmt, ##args)
#endif
