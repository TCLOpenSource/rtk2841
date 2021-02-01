#include <asm/uaccess.h>
#include <linux/bitops.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/export.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <linux/irq.h>
#include <linux/init.h>
#include <linux/ioctl.h>
#include <linux/input.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/kfifo.h>
#include <linux/kthread.h>
#include <linux/of.h>
#include <linux/pci.h>
#include <linux/poll.h>
#include <linux/platform_device.h>
#include <linux/random.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/signal.h>
#include <linux/stat.h>
#include <linux/string.h>
#include <linux/preempt.h>
#include <linux/irqflags.h>

#include <linux/kernel.h>
// #include <unistd.h>

//#include <mach/rtk_gpio.h>
//#include <mach/irqs.h>
//#include <mach/rtk_crt.h>

#include <rtk_kdriver/rtk_gpio.h>

#include <rtk_kdriver/rtk_lnbgpio.h>
#include "rtk_lnbgpio_reg.h"

int lnbgpio_dev_major;
int lnbgpio_dev_minor;


static int m_disable_lnbgpio_ioctl=0;
//static int _gLsadcIndex=0;

struct cdev *dev_cdevp_lnbgpio = NULL;

static struct class *_gstlnbgpio_class;

static struct device *lnbgpio_device_st;

static struct platform_device *pst_rtk_lnbgpio_platform_dev;

t_RTK_LNBGPIO _gLnbGpioInfo;

//#define chialinTest
#ifdef chialinTest
static RTK_GPIO_ID lnbGpio = rtk_gpio_id(MIS_GPIO, 95);
#else

static RTK_GPIO_ID lnbGpio = rtk_gpio_id(MIS_GPIO, 28);
#endif

#define HIF_Delay  5

int usdelay(int count)
{
//  volatile int i = 0 , j = 0;
    volatile int i = 0 ;
#if 0
    count *= 86;
    //count >>=1;
    //count >>=2;
    //count >>=3;
    count >>=4;
    //count *= 10;
#else
    count = HIF_Delay * count;
#endif

    for( i = 0 ; i < count ; ++i )
    {

    }

    return 0;
}


int msdelay(int count)
{
    int i = 0 ;

//    for( i = 0 ; i < count ; ++i ) usdelay(1300);
    for( i = 0 ; i < count ; ++i ) usdelay(_gLnbGpioInfo.logical_0_high);


    return 0;
}


static void lnbgpio_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
	unsigned int X,A,result;

	X=(1<<(endBit-startBit+1))-1;
	A=rtd_inl(reg_addr);

	result = (A & (~(X<<startBit))) | (value<<startBit);
	rtd_outl(reg_addr,result);
}

#define lnbGPIO_Dir_ouptut()  lnbgpio_part_outl( 0xB801bd00, 28, 28, 1 )
#define lnbGPIO_out_High()  lnbgpio_part_outl( 0xB801bd18, 28, 28, 1 )
#define lnbGPIO_out_Low()  lnbgpio_part_outl( 0xB801bd18, 28, 28, 0 )



static int rtk_lnbgpio_logical_0( void )
{


	lnbGPIO_out_Low();
	ndelay(5);

	lnbGPIO_out_High();

//	usleep_range(_gLnbGpioInfo.logical_0_high, _gLnbGpioInfo.logical_0_high+10);
	ndelay(1000*1000);
//	msdelay(1);

	lnbGPIO_out_Low();

//	usleep_range(_gLnbGpioInfo.logical_0_low, _gLnbGpioInfo.logical_0_low+10);
	ndelay(500*1000);
//	usdelay(_gLnbGpioInfo.logical_0_low);

	lnbGPIO_out_Low();
	ndelay(5);

	return 0 ;
}

static int rtk_lnbgpio_logical_1( void )
{

	lnbGPIO_out_Low();
	ndelay(5);

	lnbGPIO_out_High();

//	usleep_range(_gLnbGpioInfo.logical_1_high, _gLnbGpioInfo.logical_1_high+10);
	ndelay(500*1000);
//	usdelay(_gLnbGpioInfo.logical_0_low);

	lnbGPIO_out_Low();

//	usleep_range(_gLnbGpioInfo.logical_0_high, _gLnbGpioInfo.logical_0_high+10);
	ndelay(1000*1000);
//	msdelay(1);

	lnbGPIO_out_Low();
	ndelay(5);

	return 0 ;
}

int send_LnbGpio( unsigned char data )
{
	int i = 0 ;
	int oddParity = 0 ;
#if 0
	for( i = 7 ; i >= 0 ; --i )
	{
		if( data & ( (0x1) << i ) )
			rtk_lnbgpio_logical_1();
		else
			rtk_lnbgpio_logical_0();
	}
#endif

	for( i = 7 ; i >= 0 ; --i )
	{
		if( data & ( (0x1) << i ) )
			oddParity++;
	}



   local_irq_disable();
   preempt_disable();


	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( oddParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

   local_irq_enable();
   preempt_enable();

	return 0 ;
}
EXPORT_SYMBOL(send_LnbGpio);


int send_LnbGpioBytes( int length , unsigned char *bytes )
{
	int i = 0 ;
	int j = 0 ;
	int oddParity[8] = {0} ;
	int byteParity = 0 ;

	unsigned char data = 0 ;

	for( i = 0 ; i< length ; ++i ){

		oddParity[i] = 0 ;
		for( j = 7 ; j >= 0 ; --j ){
			if( bytes[i] & ( (0x1) << j ) )
				oddParity[i] = oddParity[i] + 1 ;
		}
	}



   local_irq_disable();
   preempt_disable();

if( length == 0 ) goto finish;

	data = bytes[0];
	byteParity = oddParity[0];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 1 ) goto finish;


	data = bytes[1];
	byteParity = oddParity[1];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 2 ) goto finish;


	data = bytes[2];
	byteParity = oddParity[2];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 3 ) goto finish;

	data = bytes[3];
	byteParity = oddParity[3];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 4 ) goto finish;

	data = bytes[4];
	byteParity = oddParity[4];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 5 ) goto finish;


	data = bytes[5];
	byteParity = oddParity[5];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 6 ) goto finish;

	data = bytes[6];
	byteParity = oddParity[6];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


if( length == 7 ) goto finish;

	data = bytes[7];
	byteParity = oddParity[7];
	if( data & ( (0x1) << 7 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 6 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 5 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 4 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 3 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 1 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

	if( data & ( (0x1) << 0 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();

// end bit
	if(  0 == ( byteParity %2 ) )
		rtk_lnbgpio_logical_1();
	else
		rtk_lnbgpio_logical_0();


finish:

   local_irq_enable();
   preempt_enable();

	return 0 ;
}
EXPORT_SYMBOL(send_LnbGpioBytes);




int lnbgpio_12p5ms_high( void )
{
   local_irq_disable();
   preempt_disable();


	lnbGPIO_out_Low();
	ndelay(10);

	lnbGPIO_out_High();
//	usleep_range( 11000 , 11000+20);
//	usleep_range(   1500 , 1500+20);
//	ndelay( 1000*1000 * 12 + 100*1000 * 5 );

	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );

	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );
	ndelay( 1000*1000 );

	ndelay( 1000*1000 );
	ndelay( 1000*1000 );

	ndelay( 500*1000 );
	lnbGPIO_out_Low();

	ndelay(10);

   local_irq_enable();
   preempt_enable();


	return 0 ;
}
EXPORT_SYMBOL(lnbgpio_12p5ms_high);


#if 0
int merlin2_Diseqc_SetContinue22kOnOff( unsigned int Diseqc22kOnOff )
{

	return 0 ;
}
EXPORT_SYMBOL(merlin2_Diseqc_SetContinue22kOnOff);


int merlin2_Diseqc_SetDiseqcCmd( unsigned int DataLength, unsigned char *Data)
{

	return 0 ;
}
EXPORT_SYMBOL(merlin2_Diseqc_SetDiseqcCmd);

int merlin2_Diseqc_SetUnModToneBurst( void )
{

	return 0 ;
}
EXPORT_SYMBOL(merlin2_Diseqc_SetUnModToneBurst);

int merlin2_Diseqc_SetModToneBurst( void )
{

	return 0 ;
}
EXPORT_SYMBOL(merlin2_Diseqc_SetModToneBurst);
#endif



#ifdef CONFIG_PM
/*static int rtk_pwm_suspend(struct platform_device *dev, pm_message_t state)*/
static int rtk_lnbgpio_suspend(struct device *dev)
{
	LNBGPIO_WARN("suspend\n");

	return 0;
}

/*static int rtk_pwm_resume(struct platform_device *dev)*/
static int rtk_lnbgpio_resume(struct device *dev)
{
	LNBGPIO_WARN("resume\n");

	return 0;
}

#ifdef CONFIG_HIBERNATION
static int rtk_lnbgpio_suspend_std(struct device *dev)
{
	LNBGPIO_WARN("%s \n" , __func__);

	return 0;
}
static int rtk_lnbgpio_resume_std(struct device *dev)
{
	LNBGPIO_WARN("%s \n" , __func__);

	return 0;
}

#endif

static const struct dev_pm_ops rtk_lnbgpio_pm_ops = {

	.suspend = rtk_lnbgpio_suspend,
	.resume = rtk_lnbgpio_resume,
	#ifdef CONFIG_HIBERNATION
	.freeze     = rtk_lnbgpio_suspend_std,
	.thaw       = rtk_lnbgpio_resume_std,
	#endif
};

#endif

static int rtk_lnbgpio_probe(struct platform_device *pdev)
{
	LNBGPIO_WARN("%s():\n", __FUNCTION__);
	return 0;
}

static int rtk_lnbgpio_remove(struct platform_device *pdev)
{
	LNBGPIO_WARN("%s():\n", __FUNCTION__);

	return 0;
}

ssize_t rtk_lnbgpio_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	LNBGPIO_WARN("%s():\n", __FUNCTION__);
	return -EFAULT;
}
ssize_t rtk_lnbgpio_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	LNBGPIO_WARN("%s():\n", __FUNCTION__);
	return -EFAULT;
}

int rtk_lnbgpio_open(struct inode *inode, struct file *filp)
{
	/*LSADC_WARN(KERN_"%s():\n", __FUNCTION__);*/
	return 0;
}

int rtk_lnbgpio_release(struct inode *inode, struct file *filp)
{
	//LSADC_WARN("%s():\n", __FUNCTION__);
	return 0;
}

long rtk_lnbgpio_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int retval = 0;

	if(m_disable_lnbgpio_ioctl)
		return retval;

	switch (cmd) {
/*
	case PWM_BACKLIGHT_DUTY:
		rtk_pwm_backlight_set_duty(arg);
		break;
*/
	default:
		retval = -ENOTTY;
	}

	return retval;
}


static struct file_operations rtk_lnbgpio_fops = {
	.owner = THIS_MODULE,
	.read = rtk_lnbgpio_read,
	.write = rtk_lnbgpio_write,
	.unlocked_ioctl = rtk_lnbgpio_ioctl,
	.release = rtk_lnbgpio_release,
	.open = rtk_lnbgpio_open,

};


static const struct of_device_id rtk_lnbgpio_devices[] = {
	{.compatible = "rtk-lnbGpio",},
	{},
};

static struct platform_driver rtk_lnbgpio_driver = {
	.driver = {
			.name = "rtk-lnbGpio",
			.owner = THIS_MODULE,
			.of_match_table = of_match_ptr(rtk_lnbgpio_devices),
			#ifdef CONFIG_PM
			.pm	= &rtk_lnbgpio_pm_ops,
			#endif
		},
	.probe = rtk_lnbgpio_probe,
	.remove = rtk_lnbgpio_remove,
};


ssize_t rtk_lnbgpio_show_param(struct device *dev,
			      struct device_attribute *attr, char *buf)
{
	int ret = 0;
	int adcValue =0 ;

	t_RTK_LNBGPIO *lnbgpio = NULL;

	if (dev->platform_data != NULL) {
		lnbgpio = (t_RTK_LNBGPIO *) dev->platform_data;
		if (lnbgpio->mapped == false) {
			LNBGPIO_WARN("This lnbgpio isn't initialize.\n");
			return 0;
		}
	}


	if (strncmp(attr->attr.name, "lnbgpio", strlen("lnbgpio")  ) == 0) {

		LNBGPIO_WARN("not support read lnbgpio .\n");

	}else if (strncmp(attr->attr.name, "lnbByte0", strlen("lnbByte0")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[0] );
	}else if (strncmp(attr->attr.name, "lnbByte1", strlen("lnbByte1")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[1] );
	}else if (strncmp(attr->attr.name, "lnbByte2", strlen("lnbByte2")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[2] );
	}else if (strncmp(attr->attr.name, "lnbByte3", strlen("lnbByte3")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[3] );
	}else if (strncmp(attr->attr.name, "lnbByte4", strlen("lnbByte4")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[4] );
	}else if (strncmp(attr->attr.name, "lnbByte5", strlen("lnbByte5")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[5] );
	}else if (strncmp(attr->attr.name, "lnbByte6", strlen("lnbByte6")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[6] );
	}else if (strncmp(attr->attr.name, "lnbByte7", strlen("lnbByte7")) == 0) {

		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbgpioByte[7] );
	}else if (strncmp(attr->attr.name, "lnbByteLength", strlen("lnbByteLength")) == 0) {
		ret = sprintf(buf, "0x%X\n", lnbgpio->lnbLength );

	}else if (strncmp(attr->attr.name, "lnb12ms", strlen("lnb12ms")) == 0) {

		LNBGPIO_WARN("not support read lnb12ms .\n");
	}else if (strncmp(attr->attr.name, "lnbMoreBytes", strlen("lnbMoreBytes")) == 0) {

	}else if (strncmp(attr->attr.name, "logical_0_high", strlen("logical_0_high")) == 0) {

		ret = sprintf(buf, "%d\n", lnbgpio->logical_0_high);
	}else if (strncmp(attr->attr.name, "logical_0_low", strlen("logical_0_low")) == 0) {

		ret = sprintf(buf, "%d\n", lnbgpio->logical_0_low);
	}else if (strncmp(attr->attr.name, "logical_1_high", strlen("logical_1_high")) == 0) {

		ret = sprintf(buf, "%d\n", lnbgpio->logical_1_high);
	}else if (strncmp(attr->attr.name, "logical_1_low", strlen("logical_1_low")) == 0) {

		ret = sprintf(buf, "%d\n", lnbgpio->logical_1_low);
	} else if (strncmp(attr->attr.name, "disable_lnbgpio_ioctl", strlen("disable_lnbgpio_ioctl")) == 0) {
		ret = sprintf(buf, "%d\n", m_disable_lnbgpio_ioctl);
	}

	return ret;
}

ssize_t rtk_lnbgpio_set_param(struct device *dev,
			     struct device_attribute *attr,
			     const char *buf, size_t count)
{
	int val = 0;
	t_RTK_LNBGPIO *lnbgpio = NULL;

	sscanf(buf, "%d\n", &val);

	if (dev->platform_data != NULL) {
		lnbgpio = (t_RTK_LNBGPIO *) dev->platform_data;
		if (lnbgpio->mapped == false) {
			LNBGPIO_WARN("This lsadc isn't initialize.\n");
			return 0;
		}
	}

	if (strncmp(attr->attr.name, "lnbgpio", strlen("lnbgpio")) == 0) {

		LNBGPIO_WARN("value = 0x%X .\n" , val );

		if( 0 ==  val )
			rtk_lnbgpio_logical_0();
		else
			rtk_lnbgpio_logical_1();
	}else if (strncmp(attr->attr.name, "lnbByte0", strlen("lnbByte0")) == 0) {

		lnbgpio->lnbgpioByte[0] = val;
//		send_LnbGpio(lnbgpio->lnbgpioByte);

	}else if (strncmp(attr->attr.name, "lnbByte1", strlen("lnbByte1")) == 0) {

		lnbgpio->lnbgpioByte[1] = val;
	}else if (strncmp(attr->attr.name, "lnbByte2", strlen("lnbByte2")) == 0) {

		lnbgpio->lnbgpioByte[2] = val;
	}else if (strncmp(attr->attr.name, "lnbByte3", strlen("lnbByte3")) == 0) {

		lnbgpio->lnbgpioByte[3] = val;
	}else if (strncmp(attr->attr.name, "lnbByte4", strlen("lnbByte4")) == 0) {

		lnbgpio->lnbgpioByte[4] = val;
	}else if (strncmp(attr->attr.name, "lnbByte5", strlen("lnbByte5")) == 0) {

		lnbgpio->lnbgpioByte[5] = val;
	}else if (strncmp(attr->attr.name, "lnbByte6", strlen("lnbByte6")) == 0) {

		lnbgpio->lnbgpioByte[6] = val;
	}else if (strncmp(attr->attr.name, "lnbByte7", strlen("lnbByte7")) == 0) {

		lnbgpio->lnbgpioByte[7] = val;
	}else if (strncmp(attr->attr.name, "lnbByteLength", strlen("lnbByteLength")) == 0) {
		if( val >=  1 &&  val <=  8 ){
			send_LnbGpioBytes( val , lnbgpio->lnbgpioByte );
			lnbgpio->lnbLength= val;
		}

	}else if (strncmp(attr->attr.name, "lnb12ms", strlen("lnb12ms")) == 0) {

		if( 1 ==  val )
			lnbgpio_12p5ms_high();

	}else if (strncmp(attr->attr.name, "logical_0_high", strlen("logical_0_high")) == 0) {

		lnbgpio->logical_0_high = val;
	}else if (strncmp(attr->attr.name, "logical_0_low", strlen("logical_0_low")) == 0) {

		lnbgpio->logical_0_low = val;
	}else if (strncmp(attr->attr.name, "logical_1_high", strlen("logical_1_high")) == 0) {

		lnbgpio->logical_1_high = val;
	}else if (strncmp(attr->attr.name, "logical_1_low", strlen("logical_1_low")) == 0) {

		lnbgpio->logical_1_low = val;
	}else if (strncmp(attr->attr.name, "disable_lnbgpio_ioctl", strlen("disable_lnbgpio_ioctl")) == 0) {

		if (val == 0 ){

			m_disable_lnbgpio_ioctl = val;
			LNBGPIO_WARN("all lnbgpio ioctl disactive \n");
		}else if( val == 1){

			m_disable_lnbgpio_ioctl = val;
			LNBGPIO_WARN("all lnbgpio ioctl active \n");
		}else
			LNBGPIO_WARN("access disable_ioctl Fail!\n");
	}


	return count;
}


DEVICE_ATTR( lnbgpio     , S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( disable_lnbgpio_ioctl, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);

DEVICE_ATTR( logical_0_high, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( logical_0_low, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( logical_1_high, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( logical_1_low, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);

DEVICE_ATTR( lnb12ms, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);

DEVICE_ATTR( lnbByte0, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte1, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte2, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte3, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte4, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte5, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte6, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByte7, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);
DEVICE_ATTR( lnbByteLength, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP,rtk_lnbgpio_show_param, rtk_lnbgpio_set_param);



static int rtk_hw_setting_lnbgpio_init(void)
{
	int ret = 0;

	snprintf( _gLnbGpioInfo.nodename, 16, "lnbgpio"  );

	_gLnbGpioInfo.mapped = true;

//	_gLnbGpioInfo.logical_0_high = 990;
	//_gLnbGpioInfo.logical_0_low = 490;
	_gLnbGpioInfo.logical_0_high = 2800;
	_gLnbGpioInfo.logical_0_low = 1400;

	_gLnbGpioInfo.logical_1_high = 490;
	_gLnbGpioInfo.logical_1_low = 990;

	_gLnbGpioInfo.lnbgpioByte[0] = 0;
	_gLnbGpioInfo.lnbgpioByte[1] = 0;
	_gLnbGpioInfo.lnbgpioByte[2] = 0;
	_gLnbGpioInfo.lnbgpioByte[3] = 0;
	_gLnbGpioInfo.lnbgpioByte[4] = 0;
	_gLnbGpioInfo.lnbgpioByte[5] = 0;
	_gLnbGpioInfo.lnbgpioByte[6] = 0;
	_gLnbGpioInfo.lnbgpioByte[7] = 0;

	_gLnbGpioInfo.lnbLength = 0;

	_gLnbGpioInfo.lnbgpio_device_st = device_create(_gstlnbgpio_class, NULL, MKDEV(0, 0), NULL, _gLnbGpioInfo.nodename);

	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbgpio);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_disable_lnbgpio_ioctl);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_logical_0_high);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_logical_0_low);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_logical_1_high);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_logical_1_low);


	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnb12ms);


	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte0);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte1);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte2);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte3);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte4);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte5);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte6);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByte7);
	ret = device_create_file(_gLnbGpioInfo.lnbgpio_device_st,&dev_attr_lnbByteLength);




#ifdef chialinTest

	#define LBN_TEST_PIN_MUX 0xB8000860
	lnbgpio_part_outl(LBN_TEST_PIN_MUX , 23, 20, 0x0F );
#else
//	#define LBN_TEST_PIN_MUX 0xB8000814
//	lnbgpio_part_outl(LBN_TEST_PIN_MUX , 11, 8, 0x0F );
#endif

	rtk_gpio_output( lnbGpio  , 0 );

	rtk_gpio_set_dir( lnbGpio  , 1 );

	_gLnbGpioInfo.lnbgpio_device_st->platform_data =(void *)&_gLnbGpioInfo;

	LNBGPIO_WARN("[%s]  ,Create Node  %s  device id = %d\n",
		__func__ ,  _gLnbGpioInfo.nodename,
		_gLnbGpioInfo.lnbgpio_device_st->id  );


	LNBGPIO_WARN("[%s]  ,  LNB GPIO  %s   %d  \n",
		__func__ ,  gpio_type(gpio_group(lnbGpio)), gpio_idx(lnbGpio)   );


	return 0;

}


static int register_lnbgpio_cdev(void) {
	dev_t dev;
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, "lnbgpio");
	if (ret) {
		LNBGPIO_ERROR("can't alloc chrdev\n");
		return ret;
	}

	lnbgpio_dev_major = MAJOR(dev);
	lnbgpio_dev_minor = MINOR(dev);

	dev_cdevp_lnbgpio = kzalloc(sizeof(struct cdev), GFP_KERNEL);
	if (dev_cdevp_lnbgpio == NULL) {
		LNBGPIO_ERROR("kzalloc failed\n");
		goto failed;
	}

	cdev_init(dev_cdevp_lnbgpio, &rtk_lnbgpio_fops);
	dev_cdevp_lnbgpio->owner = THIS_MODULE;
	dev_cdevp_lnbgpio->ops = &rtk_lnbgpio_fops;
	ret = cdev_add(dev_cdevp_lnbgpio, MKDEV(lnbgpio_dev_major, lnbgpio_dev_minor), 1);
	if (ret < 0) {
		LNBGPIO_WARN(" add chr dev failed\n");
		goto failed;
	}

	lnbgpio_device_st = device_create(_gstlnbgpio_class, NULL, MKDEV(lnbgpio_dev_major, lnbgpio_dev_minor), NULL, "rtkLnbGpio0");
	LNBGPIO_WARN("register chrdev(%d,%d) success.\n", lnbgpio_dev_major, lnbgpio_dev_minor);
	return 0;

failed:
	if(dev_cdevp_lnbgpio) {
		kfree(dev_cdevp_lnbgpio);
		dev_cdevp_lnbgpio = NULL;
	}
	return 0;

}



int __init rtk_lnb_gpio_init(void)
{
	int ret = 0;

	struct cpumask test_cpumask;

	cpumask_clear(&test_cpumask);
	cpumask_set_cpu(2, &test_cpumask); // run task in core 3
	sched_setaffinity(0, &test_cpumask);

	LNBGPIO_WARN("%s run at core %d\n", __func__ , smp_processor_id() );

	ret = platform_driver_register(&rtk_lnbgpio_driver);
	if (ret != 0)
		goto REGISTER_ERROR;

	_gstlnbgpio_class = class_create(THIS_MODULE, "rtk-lnbgpio");

	if (_gstlnbgpio_class == NULL)
		goto REGISTER_ERROR;

	rtk_hw_setting_lnbgpio_init( );

	pst_rtk_lnbgpio_platform_dev =platform_device_register_simple("rtk-lnbgpio", -1, NULL, 0);
	if (pst_rtk_lnbgpio_platform_dev == NULL) {
		platform_driver_unregister(&rtk_lnbgpio_driver);
		goto REGISTER_ERROR;
	}

	register_lnbgpio_cdev();

	return ret;

REGISTER_ERROR:
	class_destroy(_gstlnbgpio_class);
	device_destroy(_gstlnbgpio_class, MKDEV(0, 0));
	LNBGPIO_ERROR( "[%s] ======================================\n",__func__);
	LNBGPIO_ERROR( "[%s] LNBGPIO Register Error!\n", __func__);
	LNBGPIO_ERROR( "[%s] ======================================\n",__func__);
	return -1;


}

static void __exit rtk_lnb_gpio_uninit(void)
{
	int i = 0 ;


	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbgpio);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_disable_lnbgpio_ioctl);

	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_logical_0_high);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_logical_0_low);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_logical_1_high);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_logical_1_low);

	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnb12ms);

	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte0);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte1);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte2);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte3);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte4);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte5);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte6);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByte7);
	device_remove_file(_gLnbGpioInfo.lnbgpio_device_st, &dev_attr_lnbByteLength);


	device_destroy(_gstlnbgpio_class, MKDEV(0, 0));

	class_destroy(_gstlnbgpio_class);

	platform_driver_unregister(&rtk_lnbgpio_driver);

	platform_device_unregister(pst_rtk_lnbgpio_platform_dev);

}

module_init(rtk_lnb_gpio_init);
module_exit(rtk_lnb_gpio_uninit);
MODULE_AUTHOR("ChiaLin.Liu, Realtek Semiconductor");
MODULE_LICENSE("GPL");

