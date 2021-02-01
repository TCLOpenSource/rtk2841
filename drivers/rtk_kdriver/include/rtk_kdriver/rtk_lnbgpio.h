#ifndef __RTK_LNBGPIO_H__
#define __RTK_LNBGPIO_H__



#include <mach/rtk_log.h>
#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif

#undef  TAG_NAME
#define TAG_NAME  "LNBGPIO"



#define LNBGPIO_IOC_MAGIC  'L'
#define LNBGPIO_IOCR_SET _IOW(LNBGPIO_IOC_MAGIC,  0, int)
#define LNBGPIO_IOCR_GET _IOR(LNBGPIO_IOC_MAGIC,  1, int)


#define LNBGPIO_WARN(fmt, args...)	rtd_printk(KERN_WARNING , TAG_NAME , "[Warn]" fmt, ## args)
#define LNBGPIO_ERROR(fmt, args...)	rtd_printk(KERN_ERR , TAG_NAME , "[Error]" fmt, ## args)


//ssize_t  readLsadcValue( t_RTK_LSADC *adc , unsigned int *value );

//ssize_t  readLsadcChannelValue( int index  , unsigned int *value );

/*
int merlin2_Diseqc_SetContinue22kOnOff( unsigned int Diseqc22kOnOff ) ;

int merlin2_Diseqc_SetDiseqcCmd( unsigned int DataLength, unsigned char *Data);

int merlin2_Diseqc_SetUnModToneBurst( void ) ;

int merlin2_Diseqc_SetModToneBurst( void );
*/

int send_LnbGpio( unsigned char data );
int send_LnbGpioBytes( int length , unsigned char *bytes );

int lnbgpio_12p5ms_high( void );

#endif

