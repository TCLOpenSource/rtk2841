#ifndef RTK_GPIO_DEBUG_H
#define RTK_GPIO_DEBUG_H

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

#ifdef GPIO_TAG_NAME
#undef GPIO_TAG_NAME
#endif

#define GPIO_TAG_NAME "GPIO"

#define Enable_MSG  1
#define Disable_MSG 0

extern unsigned char gpio_log_onoff;


extern unsigned long gpio_dbg_log_level_mask;
extern unsigned long gpio_dbg_log_block_mask;

#define GPIO_LOG_MASK_NONE   0
#define GPIO_LOG_MASK_BIT_0  1 << 0
#define GPIO_LOG_MASK_BIT_1  1 << 1
#define GPIO_LOG_MASK_BIT_2  1 << 2
#define GPIO_LOG_MASK_BIT_3  1 << 3
#define GPIO_LOG_MASK_BIT_4  1 << 4
#define GPIO_LOG_MASK_BIT_5  1 << 5
#define GPIO_LOG_MASK_BIT_6  1 << 6
#define GPIO_LOG_MASK_BIT_7  1 << 7
#define GPIO_LOG_MASK_BIT_8  1 << 8
#define GPIO_LOG_MASK_BIT_9  1 << 9
#define GPIO_LOG_MASK_BIT_10 1 << 10
#define GPIO_LOG_MASK_BIT_11 1 << 11
#define GPIO_LOG_MASK_BIT_12 1 << 12
#define GPIO_LOG_MASK_BIT_13 1 << 13
#define GPIO_LOG_MASK_BIT_14 1 << 14



enum GPIO_LOG_LEVEL_MASK_BIT {
    GPIO_LOG_LEVEL_NONE     = GPIO_LOG_MASK_NONE,
    GPIO_LOG_LEVEL_ERR      = GPIO_LOG_MASK_BIT_0,
    GPIO_LOG_LEVEL_WARNING  = GPIO_LOG_MASK_BIT_1,
    GPIO_LOG_LEVEL_NOTICE   = GPIO_LOG_MASK_BIT_2,
    GPIO_LOG_LEVEL_INFO     = GPIO_LOG_MASK_BIT_3,
    GPIO_LOG_LEVEL_DEBUG    = GPIO_LOG_MASK_BIT_4,
};

enum GPIO_LOG_BLOCK_MASK_BIT {
    GPIO_LOG_BLOCK_NONE           = GPIO_LOG_MASK_NONE,
    GPIO_LOG_BLOCK_ALWAYS         = GPIO_LOG_MASK_BIT_0,
    GPIO_LOG_BLOCK_FUNCTIN_CALLER = GPIO_LOG_MASK_BIT_1,
    GPIO_LOG_BLOCK_IOCTL          = GPIO_LOG_MASK_BIT_2,
    GPIO_LOG_BLOCK_ALL            = 0xffffffff,
};

#define GPIO_PROC_PARAM_PRESET_ALLOFF           "preset_off"                /*  a preset for log off */
#define GPIO_PROC_PARAM_PRESET_BASIC            "preset_basic"              /*  a preset for basic log */
#define GPIO_PROC_PARAM_PRESET_NIGHTRUN         "preset_nightrun"           /*  a preset for night run */
#define GPIO_PROC_PARAM_LOG_ONOFF               "log_onoff="                /*  enable & disable display GPIO log (0: disable display; 1: enable display) */
#define GPIO_PROC_PARAM_INFO_LOG_EN             "log_info="                 /*  open & close log for INFO (0: disable; 1: enable) */
#define GPIO_PROC_PARAM_WARNING_LOG_EN          "log_warning="              /*  open & close log for WARNING (0: disable; 1: enable) */
#define GPIO_PROC_PARAM_TRACE_LOG_EN            "log_trace="                /*  open & close log for TRACE (0: disable; 1: enable) */
#define GPIO_PROC_PARAM_IOCTL_LOG_EN               "ioctl_log="              /* open & close log for PID filter list  (0: disable; 1: display at add/remove; 2: display at add/remove and every time interval) */

typedef enum {
    GPIO_PROC_PRESET_ALLOFF,           /* a preset for log off */
    GPIO_PROC_PRESET_BASIC,            /* a preset for basic log */
    GPIO_PROC_PRESET_NIGHTRUN,         /* a preset for night run */
    GPIO_PROC_LOG_ONOFF,               /* enable & disable display GPIO log (0: disable display; 1: enable display) */
    GPIO_PROC_INFO_LOG_EN,             /* open & close log for INFO (0: disable; 1: enable) */
    GPIO_PROC_WARNING_LOG_EN,          /* open & close log for WARNING (0: disable; 1: enable) */
    GPIO_PROC_TRACE_LOG_EN,            /* open & close log for TRACE (0: disable; 1: enable) */
    GPIO_PROC_IOCTL_LOG_EN,                /* open & close log for DUMP (0: disable; 1: enable) */
    GPIO_PROC_COUNT,                   /* max number */
} GPIO_PROC_CMD;


#define GPIO_HAS_FLAG(value, flag)   (value & flag)
#define GPIO_SET_FLAG(value, flag)   (value |= flag)
#define GPIO_CLEAR_FLAG(value, flag) (value &= (~flag))

#define CLEAR_LOG_MASK(level_value, block_value) \
gpio_dbg_log_level_mask = gpio_dbg_log_level_mask & ~level_value; \
gpio_dbg_log_block_mask = gpio_dbg_log_block_mask & ~block_value; \
 
#define SET_LOG_MASK(level_value, block_value) \
gpio_dbg_log_level_mask = gpio_dbg_log_level_mask | level_value; \
gpio_dbg_log_block_mask = gpio_dbg_log_block_mask | block_value; \
 
#define CLEAR_LOG_LEVEL_MASK(value) CLEAR_LOG_MASK(value, GPIO_LOG_BLOCK_NONE);
#define SET_LOG_LEVEL_MASK(value)   SET_LOG_MASK(value, GPIO_LOG_BLOCK_NONE);

#define CLEAR_LOG_BLOCK_MASK(value) CLEAR_LOG_MASK(GPIO_LOG_LEVEL_NONE, value);
#define SET_LOG_BLOCK_MASK(value)   SET_LOG_MASK(GPIO_LOG_LEVEL_NONE, value);

#define CHECK_LOG_BLOCK_MASK(value) (gpio_dbg_log_block_mask&value)

#define gpio_debug_emerg_log(fmt, args...)        {rtd_printk(KERN_EMERG, GPIO_TAG_NAME, fmt, ## args);}
#define gpio_mask_print_emerg(BIT_BLOCK, BIT_LEVEL, fmt, args...) {if (((BIT_LEVEL) & gpio_dbg_log_level_mask) && ((BIT_BLOCK) & gpio_dbg_log_block_mask)){gpio_debug_emerg_log(fmt, ## args);}}

#define gpio_debug_dbg_log(fmt, args...)  {rtd_printk(KERN_DEBUG, GPIO_TAG_NAME, fmt, ## args);}
#define gpio_mask_print_dbg(BIT_BLOCK, BIT_LEVEL, fmt, args...)   {if (((BIT_LEVEL) & gpio_dbg_log_level_mask) && ((BIT_BLOCK) & gpio_dbg_log_block_mask)){gpio_debug_dbg_log(fmt, ## args);}}

#define RTK_GPIO_TRACE(fmt, args...)  \
{ \
    if (gpio_log_onoff)  \
    {   \
        gpio_mask_print_emerg(GPIO_LOG_BLOCK_FUNCTIN_CALLER, GPIO_LOG_LEVEL_DEBUG, fmt, ## args) \
    }   \
}

#define RTK_GPIO_INFO(fmt, args...)      \
{  \
    if (gpio_log_onoff)     \
    {   \
        gpio_mask_print_emerg( GPIO_LOG_BLOCK_ALWAYS, GPIO_LOG_LEVEL_INFO, fmt,  ## args)      \
    }   \
}

#define RTK_GPIO_WARNING(fmt, args...)  \
{   \
    if (gpio_log_onoff)  \
    {  \
        gpio_mask_print_emerg( GPIO_LOG_BLOCK_ALWAYS, GPIO_LOG_LEVEL_WARNING, "WARN, "fmt, ## args)  \
    }   \
}

#define GPIO_WARNING_DEBUG_LEVEL(fmt, args...)  \
{   \
    if (gpio_log_onoff)  \
    {  \
        gpio_mask_print_dbg( GPIO_LOG_BLOCK_ALWAYS, GPIO_LOG_LEVEL_WARNING, "WARN, "fmt, ## args)  \
    }   \
}

#define RTK_GPIO_ERROR(fmt, args...)  \
{   \
    gpio_mask_print_emerg( GPIO_LOG_BLOCK_ALWAYS, GPIO_LOG_LEVEL_ERR, "ERROR, "fmt, ## args)  \
}

#define RTK_GPIO_DBG(fmt, args...)        {gpio_mask_print_emerg( GPIO_LOG_BLOCK_ALL, GPIO_LOG_LEVEL_DEBUG, fmt, ## args)}
#define RTK_GPIO_IOCTL_DBG(fmt, args...)  {gpio_mask_print_emerg( GPIO_LOG_BLOCK_IOCTL, GPIO_LOG_LEVEL_DEBUG, fmt, ## args)}
#define RTK_GPIO_DBG_SIMPLE(fmt, args...) do{gpio_mask_print_emerg( GPIO_LOG_BLOCK_ALL, GPIO_LOG_LEVEL_DEBUG, fmt , ## args)}while(0)


bool rtk_gpio_init_debug_proc(void);
void rtk_gpio_uninit_debug_proc(void);

#endif /* RTKGPIO_DEBUG_H */
