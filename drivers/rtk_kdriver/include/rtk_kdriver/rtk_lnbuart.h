#ifndef __RTK_LNBUART_H__
#define __RTK_LNBUART_H__

#include <mach/rtk_log.h>
#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif

#undef  TAG_NAME
#define TAG_NAME  "LNBUART"

#define LNBUART_IOC_MAGIC  'X'
#define LNBUART_IOCR_SET _IOW(LNBUART_IOC_MAGIC,  0, int)
#define LNBUART_IOCR_GET _IOR(LNBUART_IOC_MAGIC,  1, int)


#define LNBUART_WARN(fmt, args...)	rtd_printk(KERN_WARNING , TAG_NAME , "[Warn]" fmt, ## args)
#define LNBUART_ERROR(fmt, args...)	rtd_printk(KERN_ERR , TAG_NAME , "[Error]" fmt, ## args)


/*  demod function , for refreanmce to grep keyword
int merlin2_Diseqc_SetContinue22kOnOff( unsigned int Diseqc22kOnOff ) ;

int merlin2_Diseqc_SetDiseqcCmd( unsigned int DataLength, unsigned char *Data);

int merlin2_Diseqc_SetUnModToneBurst( void ) ;

int merlin2_Diseqc_SetModToneBurst( void );
*/

int send_LnbUart( unsigned char data );
int send_LnbUartBytes( int length , unsigned char *bytes );

int lnbuart_12p5ms_high( void );

#endif

