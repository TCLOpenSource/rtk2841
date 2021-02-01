#ifndef __RTK_AMP_H__
#define __RTK_AMP_H__

#include <mach/rtk_log.h>

#define AMP_INFO(fmt, args...)  rtd_printk(KERN_DEBUG, "AMP" , fmt, ## args)
#define AMP_WARN(fmt, args...)  rtd_printk(KERN_WARNING, "AMP" , fmt, ## args)
#define AMP_ERR(fmt, args...)   rtd_printk(KERN_ERR  , "AMP" , fmt, ## args)

#define AMP_I2C         (2)
#define AMP_DEVICE_ADDR (0x1A)
#define END_FLAG        (0xFF)
#define AMP_DEBUG       (0)

typedef struct
{
	unsigned char bAddr;
	unsigned char bArray[2];
}ALC1310_REG;//markchen add for 1310


#endif
