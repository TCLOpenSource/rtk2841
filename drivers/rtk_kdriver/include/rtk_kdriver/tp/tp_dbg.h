#ifndef __TP_DBG_H__
#define __TP_DBG_H__

#include <mach/rtk_log.h>

// debug log don't have the color by default.  If you want to use color, please add following color tag to the log string.
#define NONE            "\033[m"
#define RED             "\033[0;32;31m"
#define LIGHT_RED       "\033[1;31m"
#define GREEN           "\033[0;32;32m"
#define LIGHT_GREEN     "\033[1;32m"
#define BLUE            "\033[0;32;34m"
#define LIGHT_BLUE      "\033[1;34m"
#define DARY_GRAY       "\033[1;30m"
#define CYAN            "\033[0;36m"
#define LIGHT_CYAN      "\033[1;36m"
#define PURPLE          "\033[0;35m"
#define LIGHT_PURPLE    "\033[1;35m"
#define BROWN           "\033[0;33m"
#define YELLOW          "\033[1;33m"
#define LIGHT_GRAY      "\033[0;37m"
#define WHITE           "\033[1;37m"

#ifdef TAG_NAME
#undef TAG_NAME
#endif

#define TAG_NAME "TP"

extern unsigned long tp_dbg_log_level_mask;
extern unsigned long tp_dbg_log_block_mask;

#define TP_LOG_MASK_NONE   0
#define TP_LOG_MASK_BIT_0  1 << 0
#define TP_LOG_MASK_BIT_1  1 << 1
#define TP_LOG_MASK_BIT_2  1 << 2
#define TP_LOG_MASK_BIT_3  1 << 3
#define TP_LOG_MASK_BIT_4  1 << 4
#define TP_LOG_MASK_BIT_5  1 << 5
#define TP_LOG_MASK_BIT_6  1 << 6
#define TP_LOG_MASK_BIT_7  1 << 7
#define TP_LOG_MASK_BIT_8  1 << 8
#define TP_LOG_MASK_BIT_9  1 << 9
#define TP_LOG_MASK_BIT_10 1 << 10
#define TP_LOG_MASK_BIT_11 1 << 11
#define TP_LOG_MASK_BIT_12 1 << 12

enum TP_LOG_LEVEL_MASK_BIT {
        TP_LOG_LEVEL_NONE         = TP_LOG_MASK_NONE,
        TP_LOG_LEVEL_ERR      = TP_LOG_MASK_BIT_0,
        TP_LOG_LEVEL_WARNING  = TP_LOG_MASK_BIT_1,
        TP_LOG_LEVEL_NOTICE   = TP_LOG_MASK_BIT_2,
        TP_LOG_LEVEL_INFO     = TP_LOG_MASK_BIT_3,
        TP_LOG_LEVEL_DEBUG    = TP_LOG_MASK_BIT_4,
        TP_LOG_LEVEL_VERBOSE  = TP_LOG_MASK_BIT_5,
};

enum TP_LOG_BLOCK_MASK_BIT {
        TP_LOG_BLOCK_NONE                       = TP_LOG_MASK_NONE,
        TP_LOG_BLOCK_ALWAYS         = TP_LOG_MASK_BIT_0,
        TP_LOG_BLOCK_FUNCTIN_CALLER = TP_LOG_MASK_BIT_1,
        TP_LOG_BLOCK_FRAMER         = TP_LOG_MASK_BIT_2,
        TP_LOG_BLOCK_CNT            = TP_LOG_MASK_BIT_3,
        TP_LOG_BLOCK_TPOUT          = TP_LOG_MASK_BIT_4,
        TP_LOG_BLOCK_PID            = TP_LOG_MASK_BIT_5,
        TP_LOG_BLOCK_PCR            = TP_LOG_MASK_BIT_6,
        TP_LOG_BLOCK_SECTION        = TP_LOG_MASK_BIT_7,
        TP_LOG_BLOCK_BUFFER         = TP_LOG_MASK_BIT_8,
        TP_LOG_BLOCK_MTP            = TP_LOG_MASK_BIT_9,
        TP_LOG_BLOCK_STARTCODE      = TP_LOG_MASK_BIT_10,
        TP_LOG_BLOCK_PVR            = TP_LOG_MASK_BIT_11,
        TP_LOG_BLOCK_ALL            = 0xffffffff,
};

enum TP_STATUS_LOG_FLAG_MASK_BIT {
        TP_STATUS_LOG_FLAG_NONE          = TP_LOG_MASK_NONE,
        TP_STATUS_LOG_FLAG_PKT_CNT       = TP_LOG_MASK_BIT_0,
        TP_STATUS_LOG_FLAG_ERR_CNT       = TP_LOG_MASK_BIT_1,
        TP_STATUS_LOG_FLAG_REV_CNT       = TP_LOG_MASK_BIT_2,
        TP_STATUS_LOG_FLAG_LIVERATE      = TP_LOG_MASK_BIT_3,
        TP_STATUS_LOG_FLAG_PIDFILTER     = TP_LOG_MASK_BIT_4,
        TP_STATUS_LOG_FLAG_NO_LIVERATE   = TP_LOG_MASK_BIT_5,
        TP_STATUS_LOG_FLAG_LOW_LIVERATE  = TP_LOG_MASK_BIT_6,
        TP_STATUS_LOG_FLAG_BUFFUSAGE     = TP_LOG_MASK_BIT_7,
        TP_STATUS_LOG_FLAG_MASSBUFFFULL  = TP_LOG_MASK_BIT_8,
        TP_STATUS_LOG_FLAG_ALL           = 0xffffffff,
};

#define TP_HAS_FLAG(value, flag)   (value & flag)
#define TP_SET_FLAG(value, flag)   (value |= flag)
#define TP_CLEAR_FLAG(value, flag) (value &= (~flag))

#define CLEAR_LOG_MASK(level_value, block_value) \
tp_dbg_log_level_mask = tp_dbg_log_level_mask & ~level_value; \
tp_dbg_log_block_mask = tp_dbg_log_block_mask & ~block_value; \
 
#define SET_LOG_MASK(level_value, block_value) \
tp_dbg_log_level_mask = tp_dbg_log_level_mask | level_value; \
tp_dbg_log_block_mask = tp_dbg_log_block_mask | block_value; \
 
#define CLEAR_LOG_LEVEL_MASK(value) CLEAR_LOG_MASK(value, TP_LOG_BLOCK_NONE);
#define SET_LOG_LEVEL_MASK(value)   SET_LOG_MASK(value, TP_LOG_BLOCK_NONE);

#define CLEAR_LOG_BLOCK_MASK(value) CLEAR_LOG_MASK(TP_LOG_LEVEL_NONE, value);
#define SET_LOG_BLOCK_MASK(value)   SET_LOG_MASK(TP_LOG_LEVEL_NONE, value);

#define CHECK_LOG_BLOCK_MASK(value) (tp_dbg_log_block_mask&value)

#define tp_debug_emerg_log(fmt, args...)        {rtd_printk(KERN_EMERG, TAG_NAME, fmt, ## args);}
#define tp_mask_print_emerg(BIT_BLOCK, BIT_LEVEL, fmt, args...) {if (((BIT_LEVEL) & tp_dbg_log_level_mask) && ((BIT_BLOCK) & tp_dbg_log_block_mask)){tp_debug_emerg_log(fmt, ## args);}}

#define tp_debug_dbg_log(fmt, args...)  {rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ## args);}
#define tp_mask_print_dbg(BIT_BLOCK, BIT_LEVEL, fmt, args...)   {if (((BIT_LEVEL) & tp_dbg_log_level_mask) && ((BIT_BLOCK) & tp_dbg_log_block_mask)){tp_debug_dbg_log(fmt, ## args);}}

#define TP_TRACE(fmt, args...)  \
{ \
        if (tp_log_onoff)  \
        {   \
                tp_mask_print_emerg(TP_LOG_BLOCK_FUNCTIN_CALLER, TP_LOG_LEVEL_DEBUG, fmt, ## args) \
        }   \
}

#define TP_VERBOSE(fmt, args...)  \
{ \
        if (tp_log_onoff)  \
        {   \
                tp_mask_print_emerg( TP_LOG_BLOCK_ALWAYS, TP_LOG_LEVEL_VERBOSE, fmt ,  ## args)  \
        }       \
}

#define TP_INFO(fmt, args...)      \
{  \
        if (tp_log_onoff)     \
        {   \
                tp_mask_print_emerg( TP_LOG_BLOCK_ALWAYS, TP_LOG_LEVEL_INFO, fmt,  ## args)      \
        }   \
}

#define TP_WARNING(fmt, args...)  \
{   \
        if (tp_log_onoff)  \
        {  \
                tp_mask_print_emerg( TP_LOG_BLOCK_ALWAYS, TP_LOG_LEVEL_WARNING, "WARN, "fmt, ## args)  \
        }   \
}

#define TP_WARNING_DEBUG_LEVEL(fmt, args...)  \
{   \
        if (tp_log_onoff)  \
        {  \
                tp_mask_print_dbg( TP_LOG_BLOCK_ALWAYS, TP_LOG_LEVEL_WARNING, "WARN, "fmt, ## args)  \
        }   \
}

#define TP_ERROR(fmt, args...)  \
{   \
        tp_mask_print_emerg( TP_LOG_BLOCK_ALWAYS, TP_LOG_LEVEL_ERR, "ERROR, "fmt, ## args)  \
}

#define TP_DBG(fmt, args...)        {tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_DEBUG, fmt, ## args)}

#define TP_DBG_SIMPLE(fmt, args...) do{tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_DEBUG, fmt , ## args)}while(0)


#endif          /* __TP_DBG_H__ */

