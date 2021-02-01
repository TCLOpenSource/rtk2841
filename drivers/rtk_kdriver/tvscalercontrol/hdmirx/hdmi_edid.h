#ifndef __HDMI_EDID_H__
#define __HDMI_EDID_H__

//#define HDMI_EDID_DBG_EN            // enable HDMI EDID debug message


///////////////////////////////////////////////////////////////////
int newbase_hdmi_check_hdmi_edid(unsigned char edid[128]);
int newbase_hdmi_dump_hdmi_edid(unsigned char edid[128]);

///////////////////////////////////////////////////////////////////
#define HDMI_EDID_EMG(fmt, args...)     rtd_printk(KERN_EMERG,  "[HDMI][EDID][EMG]", fmt, ##args)
#define HDMI_EDID_INFO(fmt, args...)    rtd_printk(KERN_EMERG,  "[HDMI][EDID][INFO]", fmt, ##args)

#ifdef HDMI_EDID_DBG_EN
#include <mach/rtk_log.h>
#define HDMI_EDID_DBG(fmt, args...)     rtd_printk(KERN_EMERG,  "[HDMI][EDID][DBG]", fmt, ##args)
#else
#define HDMI_EDID_DBG(fmt, args...)     do {} while(0)     
#endif

#endif // __HDMI_EDID_H__