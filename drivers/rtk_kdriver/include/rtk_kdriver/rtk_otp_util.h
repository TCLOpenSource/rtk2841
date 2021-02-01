#ifndef __OTP_UTIL_H__
#define __OTP_UTIL_H__
#include <mach/rtk_log.h>

extern int otp_read(unsigned int ofst, unsigned int *pval);
extern int otp_read_bits(unsigned int ofst, unsigned char msb,
                        unsigned char lsb, unsigned int *pval);
extern int otp_read_region(unsigned int ofst,
                        unsigned int *data, int len);
extern int otp_read_region_byte(unsigned int ofst,
                        unsigned char *data, int len);
extern int otp_crc_auto_region(unsigned int *pval);
extern int otp_crc_partial_region(unsigned int start_ofst,
                        unsigned int len, unsigned int *pval);


#ifdef OTP_DBG_EN
#define OTP_DBG(fmt, args...)   rtd_printk(KERN_DEBUG, "OTP", "[DBG] " fmt, ##args)
#else
#define OTP_DBG(fmt, args...)
#endif
#define OTP_WARNING(fmt, args...)   rtd_printk( KERN_WARNING , "OTP", "[Warn] " fmt, ##args)


#endif /* 
 */
