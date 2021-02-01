#ifndef __HDMI_DEBUG_H__
#define __HDMI_DEBUG_H__

#include <mach/rtk_log.h>

#define HDMI_RX_DBG_EN

#ifdef HDMI_RX_DBG_EN
    #define HDMI_EMG(fmt, args...)           rtd_printk(KERN_EMERG,  "[HDMI][EMG]", fmt, ##args)            
    #define HDMI_WARN(fmt, args...)          rtd_printk(KERN_INFO,   "[HDMI][WARN]", fmt, ##args) 
    #define HDMI_INFO(fmt, args...)          rtd_printk(KERN_INFO,   "[HDMI][INFO]", fmt, ##args)   
    #define HDMI_NOTICE(fmt, args...)        rtd_printk(KERN_NOTICE, "[HDMI][NOTICE]", fmt, ##args)
    #define HDMI_PRINTF(fmt, args...)        rtd_printk(KERN_NOTICE, "[HDMI]", fmt, ##args)
#else
    #define HDMI_EMG(fmt, args...)        
    #define HDMI_WARN(fmt, args...)    
    #define HDMI_INFO(fmt, args...)
    #define HDMI_NOTICE(fmt, args...)
    #define HDMI_PRINTF(fmt, args...)
#endif


#endif // __HDMI_DEBUG_H__

