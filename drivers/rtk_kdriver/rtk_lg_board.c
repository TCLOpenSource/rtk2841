#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/string.h>
#include <mach/irqs.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_lg_board.h>

#include <mach/platform.h>

#include <mach/rtk_log.h>

#undef  TAG_NAME
#define TAG_NAME  "LG_COUNTRY_TYPE"

#define LG_COUNTRY_WARN(fmt, args...)	rtd_printk( KERN_WARNING , TAG_NAME, "[Warn] " fmt, ## args)


extern bcas_info_t bcas;

int getLgK2L_PcbCountry(void)
{

	if( bcasON == bcas )
		return LG_COUNTRY_CN_HK_ATSC_KR_SMC_JP;
	else
		return LG_COUNTRY_AJJA_ATSC_CI;

	return -1;

}
EXPORT_SYMBOL(getLgK2L_PcbCountry);

int isPcbWithPcmcia( void )
{

	int PcbCountry  = getLgK2L_PcbCountry();

	LG_COUNTRY_WARN(" %s  PcbCountry = %d\n " , __func__ ,PcbCountry );

	if( PcbCountry < 0 )
		return -1;

	else  if( LG_COUNTRY_CN_HK_ATSC_KR_SMC_JP != PcbCountry )
		return 1;

	return 0;

}
EXPORT_SYMBOL(isPcbWithPcmcia);

int isPcbWithSmc( void )
{

	int PcbCountry  = getLgK2L_PcbCountry();

	LG_COUNTRY_WARN( " %s  PcbCountry = %d\n " , __func__ ,PcbCountry );


	if( PcbCountry < 0 )
		return -1;

	else  if( LG_COUNTRY_CN_HK_ATSC_KR_SMC_JP == PcbCountry )
		return 1;

	return 0;


}
EXPORT_SYMBOL(isPcbWithSmc);


