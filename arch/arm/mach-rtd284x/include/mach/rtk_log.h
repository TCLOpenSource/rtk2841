#ifndef __RTK_LOG_API__
#define __RTK_LOG_API__

#include <linux/printk.h>
#include <linux/dynamic_debug.h>

#define rtd_fmt(tag, fmt) "["tag"] "fmt

#if defined(CONFIG_DYNAMIC_DEBUG)
#define KERN_DEBUG_C '7'
#define rtd_printk(level, tag, fmt, ...)                    \
    do {                                    \
        if (level[1] == KERN_DEBUG_C)                   \
            dynamic_pr_debug(rtd_fmt(tag, fmt), ##__VA_ARGS__); \
        else                                \
            printk(level rtd_fmt(tag, fmt), ##__VA_ARGS__);     \
    }while(0)
#else
#define rtd_printk(level, tag, fmt, ...)                    \
    printk(level rtd_fmt(tag, fmt), ##__VA_ARGS__);
#endif

#endif // __RTK_LOG_API__
