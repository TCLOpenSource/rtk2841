#ifndef __RTK_HDCP_OTP_UTIL_H__
#define __RTK_HDCP_OTP_UTIL_H__
#include <mach/rtk_log.h>
/* --------------------------------- Debug --------------------------------- */
#define TAG_NAME "HDCP"
//#define HDCP_OTP_DEBUG
#ifdef HDCP_OTP_DEBUG
#define hdcp_otp_debug(fmt, args...)\
		rtd_printk(KERN_DEBUG, TAG_NAME,"[%s][%d] Debug, " fmt, __func__, __LINE__, ## args)
#define hdcp_otp_info(fmt, args...)\
		rtd_printk(KERN_INFO, TAG_NAME,"[%s][%d] Info, " fmt, __func__, __LINE__, ## args)
#else
#define hdcp_otp_debug(fmt, args...)
#define hdcp_otp_info(fmt, args...)
#endif

#define hdcp_otp_warning(fmt, args...)\
		rtd_printk(KERN_WARNING, TAG_NAME,"[%s][%d] Warning, " fmt, __func__, __LINE__, ## args)
#define hdcp_otp_err(fmt, args...)\
		rtd_printk(KERN_ERR, TAG_NAME,"[%s][%d] Err, " fmt, __func__, __LINE__, ## args)

void hdcp_otp_hexdump(const void *buf, unsigned int length);
int get_hdcp_22_otp(unsigned char *buf,unsigned int len);
int get_hdcp_14_otp(unsigned char *buf,unsigned int len);

#endif //__RTK_HDCP_OTP_UTIL_H__
