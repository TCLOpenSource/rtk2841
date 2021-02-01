#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/ioctl.h>
#include <linux/device.h>
#include <linux/mutex.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#include <linux/sched.h>
#include <linux/sched/rt.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <rbus/iso_misc_reg.h>
#include <rbus/wdog_reg.h>
#include <linux/freezer.h>

#include <linux/platform_device.h>
#include <mach/platform.h>
#include <mach/rtk_platform.h>
#include <mach/timex.h>

#include <rbus/sb2_reg.h>
#include <mach/platform.h>
#include <rtk_kdriver/rtd_logger.h>
#include <rtk_kdriver/rtk_watchdog.h>
#include <rtd_types.h>
#include <generated/autoconf.h>

#include <rtk_kdriver/io.h>

#define WDOG_DEVICE_NAME			"watchdog"
#define WDOG_FREQUENCY 27000000   //27Mhz
#define WDOG_SECS_TO_TICKS(secs)		((secs) * WDOG_FREQUENCY)
#define WDOG_TICKS_TO_SECS(ticks)		((ticks) / WDOG_FREQUENCY)
#define WDOG_TIMEOUT_MAX 10


#define WDIOS_ENABLE_WITH_KERNEL_AUTO_KICK     0x0008          /* Turn on the watchdog timer,and kernel will kick watchdog by itself */

typedef enum{
	RHAL_WDOG_IS_ON_NEED_AP_KICK = 0,
	RHAL_WDOG_IS_OFF,
	RHAL_WDOG_IS_ON_WITH_KERNEL_AUTO_KICK,
	RHAL_WDOG_STATUS_MAX	
}RHAL_WDOG_STATUS_T;

unsigned int wdog_major = 0;
unsigned int wdog_minor = 0;

static unsigned long k_force_protect = 0;
static unsigned int uboot_wdg_state = 0;  
static struct wdog_dev *wdog_drv_dev;
static struct class *wdog_class;
static unsigned int rtk_wdog_kick_by_ap = 0;
static unsigned int rtk_wdog_timeout_value = WDOG_TIMEOUT_MAX;
static __kernel_time_t rtk_wdog_expires;
static __kernel_time_t rtk_wdog_AP_expires;
static DEFINE_MUTEX(rtk_wdog_mutex);


static unsigned long    watchdog_task = 0;
static unsigned int enable_uart2rbus_once = 0;
//static unsigned int rtk_wdog_ping_count = 0;

/* From Dora: */
/* Command register: */
/* 0xb8008EB4[24] => 0: off; 1: on */
/* Status register: */
/* 0xb8008EB8[15:0] for error status */
#define CMD_REG (0xb8008EB4)
#define STA_REG (0xb8008EB8)

void enable_uart2rbus(void)
{
	if (enable_uart2rbus_once == 0)
	{
		rtd_maskl(ISO_MISC_DDC_CTRL_reg, ~ISO_MISC_DDC_CTRL_ddc_u2r_en_mask, ISO_MISC_DDC_CTRL_ddc_u2r_en(1));
		enable_uart2rbus_once = 1;
	}
}

static bool rtd_show_log[NORMAL] = {1,1,1,1,1,1,1};



void DDR_scan_set_error(int cpu)
{
	unsigned int reg_base = STA_REG;
	unsigned int reg_mask;
	unsigned int reg_shift;
	unsigned int ctrl_reg_base = CMD_REG;
	unsigned int i = 0;

	if (cpu >= DDR_SCAN_STATUS_NUM)
		return;

	if ((rtd_inl(ctrl_reg_base) & _BIT24) == 0x0)
		return;

	switch(cpu) {
		case DDR_SCAN_STATUS_SCPU: // SCPU
			reg_mask = 0x00000001;
			reg_shift = 0;
			break;
		case DDR_SCAN_STATUS_ACPU1: // ACPU1
			reg_mask = 0x00000002;
			reg_shift = 1;
			break;
		case DDR_SCAN_STATUS_ACPU2: // ACPU2
			reg_mask = 0x00000004;
			reg_shift = 2;
			break;
		case DDR_SCAN_STATUS_VCPU1: // VCPU1
			reg_mask = 0x00000008;
			reg_shift = 3;
			break;
		case DDR_SCAN_STATUS_VCPU2: // VCPU2
			reg_mask = 0x00000010;
			reg_shift = 4;
			break;
		case DDR_SCAN_STATUS_KCPU: // KCPU
			reg_mask = 0x00000020;
			reg_shift = 5;
			break;
		case DDR_SCAN_STATUS_GPU: // GPU
			reg_mask = 0x00000040;
			reg_shift = 6;
			break;
		default:
			return;
	}

	// wait and get hw semaphore 2
	while(1) {
		if ((rtd_inl(SB2_HD_SEM_NEW_2_reg) & _BIT0) == 0x1)
			break;

		for(i = 0;i < 1024;i++); //reduce rbus traffic
	}

	rtd_maskl(reg_base, ~(reg_mask), 1 << reg_shift);

	// release hw semaphore 2
	rtd_outl(SB2_HD_SEM_NEW_2_reg, 0x0);

}

extern unsigned int debugMode; // declaire in mach-rtdxxxx/init.c
static int my_panic(const char *fmt, ...)
{
	enable_uart2rbus();

	if (fmt) {
		struct va_format vaf;
		va_list args;

		va_start(args, fmt);

		vaf.fmt = fmt;
		vaf.va = &args;

		if (debugMode == RELEASE_LEVEL)
			panic("%pV", &vaf);
		else {
#if defined(CONFIG_CUSTOMER_TV030) || defined(CONFIG_CUSTOMER_TV010)
            printk(KERN_EMERG "hw_watchdog: my_panic call real panic\n");
			panic("%pV", &vaf);
#else
			pr_err("%pV", &vaf);
#endif
		}
#if defined (CONFIG_REALTEK_LOGBUF)
			if(rtd_show_log[g_rtdlog_panic_cpu_type]){
			        //DumpWork.param = g_rtdlog_panic_cpu_type;
			        //queue_work(p_dumpqueue, &DumpWork.work);
			        rtd_show_log[g_rtdlog_panic_cpu_type] = 0;
			        rtdlog_watchdog_dump_work(g_rtdlog_panic_cpu_type);
			}
#endif //   #if defined (CONFIG_REALTEK_LOGBUF)

		va_end(args);
	}

	return 0;
}

static int flag_watchdog=0;
static void rtk_watchdog_set_flag(int flag)
{
	flag_watchdog = flag;
}

int rtk_watchdog_get_flag(void)
{
	return flag_watchdog;
}

/* return value: 1 => success, 0 => failure */
int kill_watchdog (void)
{
    watchdog_task = 0;
    return 1;
}

int judge_watchdog (void)
{
    return watchdog_task;
}

/*If hw watchdog enable, return 1, otherwise return 0.*/
int is_watchdog_enable(void)
{
	if((rtd_inl(WDOG_TCWCR_reg) & 0xff) == 0xa5)
		return 0;
	else
		return 1;
}


//WDOG_TCWOV_reg 0xB8062210
//WDOG_TCWCR_reg 0xB8062204
int watchdog_enable (unsigned char On)
{
    printk(KERN_EMERG "hw_watchdog: watchdog_enable On=%d\n", On);
    if (On)
    {
        if(rtd_inl(WDOG_TCWOV_reg) == 0x23792379 || rtd_inl(WDOG_TCWOV_reg) == 0x23782378){
            rtd_maskl(WDOG_TCWCR_reg, ~0xFF, 0xa5);
            rtd_outl(WDOG_TCWTR_reg, 0x01);        // must clear, avoid system reset at watchdog on
            rtd_outl(WDOG_TCWOV_reg, 0x23782378);
            rtd_outl(WDOG_TCWNMI_reg, 0xffffffff);    // NMI no need
        }else {
        /* enable watchdog */
        rtd_maskl(WDOG_TCWCR_reg, ~0xFF, 0xa5);
        rtd_outl(WDOG_TCWTR_reg, 0x01);    // must clear, avoid system reset at watchdog on
        rtd_outl(WDOG_TCWNMI_reg, 0xffffffff);    // NMI no need 

#ifdef CONFIG_CUSTOMER_TV030
        rtd_outl(WDOG_TCWOV_reg, 0x11000000);// Max: 0x11000000 10.56s
#elif defined(CONFIG_CUSTOMER_TV010)
        rtd_outl(WDOG_TCWOV_reg, 0xB43EA00);//7.0s // Max: 0x11000000 10.56s
#else
        rtd_outl(WDOG_TCWOV_reg, 0x8000000);//4.97s
#endif
        rtd_maskl(WDOG_TCWCR_reg, ~0xFF, 0x00);
        rtk_watchdog_set_flag(1);
        }
    }
    else
    {
        /* disable watchdog */
        rtd_maskl(WDOG_TCWCR_reg, ~0xFF, 0xa5);
        rtd_outl(WDOG_TCWTR_reg, 0x01);    // must clear, avoid 8051 emcu reset at watchdog on
        rtd_outl(WDOG_TCWNMI_reg, 0xffffffff);    // NMI no need
        rtk_watchdog_set_flag(2);
    }
    return 1;
}

// SB2_DUMMY_2_reg:
//		[31:24] : audio1
//		[23:16] : audio2
//		[15: 0] : video1
// SB2_DUMMY_3_reg:
//		[31:16] : kcpu
//		[15: 0] : video2

#define ACPU1_WDOG_MAGIC_VALUE	(0x23000000)
#define ACPU1_WDOG_MAGIC_MASK	(0xFF000000)

#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
#define ACPU2_WDOG_MAGIC_VALUE	(0x00790000)
#define ACPU2_WDOG_MAGIC_MASK	(0x00FF0000)
#endif

#define VCPU1_WDOG_MAGIC_VALUE	(0x00002379)
#define VCPU1_WDOG_MAGIC_MASK	(0x0000FFFF)

#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
#define VCPU2_WDOG_MAGIC_VALUE	(0x00002379)
#define VCPU2_WDOG_MAGIC_MASK	(0x0000FFFF)
#endif

#define KCPU_WDOG_MAGIC_VALUE	(0x23790000)
#define KCPU_WDOG_MAGIC_MASK	(0xFFFF0000)

static unsigned int hw_watchdog_tick_enable = 0;
void hw_watchdog_tick (void)
{
    while (1)
    {
        if (hw_watchdog_tick_enable) {
            rtd_outl(WDOG_TCWTR_reg, 0x01);
            //printk(KERN_EMERG "hw_watchdog_tick\n");
        }
        msleep(1000);
    }
}

int hw_watchdog (void *p)
{
#define TO_MSEC 2000
#define K_FORCE_PROTECT_MSEC 60000
//	unsigned long timeout;
     __kernel_time_t current_time, diff_time;
    bool hit_diff_1=false, hit_diff_10=false, hit_diff_30=false, hit_diff_40=false, hit_diff_50=false;    
	unsigned long to_a, to_v, to_k, to_v2, to_a2;
	unsigned int val_dummy_2, val_dummy_3;
	struct sched_param param = { .sched_priority = MAX_RT_PRIO-1 };
	watchdog_task = (unsigned long)current;
#if 0 // fix me - jinn - kernel porting
	daemonize("hw_watchdog");
#endif
	sched_setscheduler(current, SCHED_FIFO, &param);
	current->flags &= ~PF_NOFREEZE;

    /*watchdog on/off control by bootcode.*/
    uboot_wdg_state = is_watchdog_enable();
    if (uboot_wdg_state)
	   watchdog_enable(1);
	printk(KERN_EMERG "enter hw_watchdog!!!    %x\n",current->flags);
    k_force_protect = jiffies + msecs_to_jiffies(K_FORCE_PROTECT_MSEC);
	to_a = to_v = to_k = to_v2 = to_a2 = jiffies + msecs_to_jiffies(TO_MSEC);


	while (1)
	{
		if(rtk_wdog_kick_by_ap == 0)
		{
			//printk("now kernel control kick!!!\n");
			rtd_outl(WDOG_TCWTR_reg, 0x01);
		}
		else
		{
      			//printk("now ap control kick!!!\n");          
                  current_time = ktime_to_timespec(ktime_get()).tv_sec;
                  if (current_time > rtk_wdog_expires)
                  {
                      diff_time = current_time - rtk_wdog_expires;
                      if (!hit_diff_1 && diff_time > 1)
                      {
                          hit_diff_1 = true;
                          printk(KERN_EMERG "hw_watchdog kick by ap, expire 1 sec!!!\n");
                      }
                      else if (!hit_diff_10 && diff_time > 10)
                      {
                          hit_diff_10 = true;
                          printk(KERN_EMERG "hw_watchdog kick by ap, expire 10 sec!!!\n");
                      }
                      else if (!hit_diff_30 && diff_time > 30)
                      {
                          hit_diff_30 = true;
                          printk(KERN_EMERG "hw_watchdog kick by ap, expire 30 sec!!!\n");
                      }
                      else if (!hit_diff_40 && diff_time > 40)
                      {
                          hit_diff_40 = true;
                          printk(KERN_EMERG "hw_watchdog kick by ap, expire 40 sec!!!\n");
                      }
                      else if (!hit_diff_50 && diff_time > 50)
                      {
                          hit_diff_50 = true;
                          printk(KERN_EMERG "hw_watchdog kick by ap, expire 50 sec!!!\n");
                      }
                  }
                  else if (hit_diff_1 || hit_diff_10 || hit_diff_30)
                  {
                        hit_diff_1 = false;
                        hit_diff_10 = false;
                        hit_diff_30 = false;
                        hit_diff_40 = false;
                        hit_diff_50 = false;
                  }
      
                  if (current_time > rtk_wdog_AP_expires) {
                      //printk("now ap control kick, and expire 60sec more!!!\n");
                      rtd_outl(WDOG_TCWTR_reg, 0x01);            
                  }
                  else {
                      rtd_outl(WDOG_TCWTR_reg, 0x01);            
                  }
		}


		val_dummy_2 = rtd_inl(SB2_DUMMY_2_reg);
		val_dummy_3 = rtd_inl(SB2_DUMMY_3_reg);

		if ( (val_dummy_2 & VCPU1_WDOG_MAGIC_MASK) == VCPU1_WDOG_MAGIC_VALUE ) // video1
		{
			to_v = jiffies + msecs_to_jiffies(TO_MSEC);
			rtd_maskl(SB2_DUMMY_2_reg, ~VCPU1_WDOG_MAGIC_MASK, 0x0000);
		}
		if ( (val_dummy_2 & ACPU1_WDOG_MAGIC_MASK) == ACPU1_WDOG_MAGIC_VALUE ) // audio1
		{
			to_a = jiffies + msecs_to_jiffies(TO_MSEC);
			rtd_maskl(SB2_DUMMY_2_reg, ~ACPU1_WDOG_MAGIC_MASK, 0x00);
		}
#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
		if ( (val_dummy_2 & ACPU2_WDOG_MAGIC_MASK) == ACPU2_WDOG_MAGIC_VALUE ) // audio2
		{
			to_a2 = jiffies + msecs_to_jiffies(TO_MSEC);
			rtd_maskl(SB2_DUMMY_2_reg, ~ACPU2_WDOG_MAGIC_MASK, 0x00);
		}
#endif
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
		if ( (val_dummy_3 & VCPU2_WDOG_MAGIC_MASK) == VCPU2_WDOG_MAGIC_VALUE ) // video2
		{
			to_v2 = jiffies + msecs_to_jiffies(TO_MSEC);
			rtd_maskl(SB2_DUMMY_3_reg, ~VCPU2_WDOG_MAGIC_MASK, 0x0000);
		}
#endif

#if defined (CONFIG_REALTEK_SECURE) && !defined(CONFIG_OPTEE)
		if ( (val_dummy_3 & KCPU_WDOG_MAGIC_MASK) == KCPU_WDOG_MAGIC_VALUE ) // kcpu
		{
			to_k = jiffies + msecs_to_jiffies(TO_MSEC);
			rtd_maskl(SB2_DUMMY_3_reg, ~KCPU_WDOG_MAGIC_MASK, 0x0000);
		}
#endif

		if (time_is_before_jiffies(to_a)) {
			set_rtdlog_panic_cpu_type(ACPU1);
			DDR_scan_set_error(DDR_SCAN_STATUS_ACPU1);
			my_panic("[A1DSP] WatchDog does not receive signal for %d seconds, value: %08x \n", TO_MSEC/1000, val_dummy_2);
		}
#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
		if (time_is_before_jiffies(to_a2)) {
			set_rtdlog_panic_cpu_type(ACPU2);
			DDR_scan_set_error(DDR_SCAN_STATUS_ACPU2);
			my_panic("[A2DSP] WatchDog does not receive signal for %d seconds, value: %08x \n", TO_MSEC/1000, val_dummy_2);
		}
#endif
		if (time_is_before_jiffies(to_v)) {
			set_rtdlog_panic_cpu_type(VCPU1);
			DDR_scan_set_error(DDR_SCAN_STATUS_VCPU1);
			my_panic("[V1DSP] WatchDog does not receive signal for %d seconds, value: %08x \n", TO_MSEC/1000, val_dummy_2);
		}
#if defined (CONFIG_REALTEK_SECURE) && !defined(CONFIG_OPTEE)
		if (time_is_before_jiffies(to_k)) {
			/*ravi_li dump crt info when KCPU not kick watchdog*/
			set_rtdlog_panic_cpu_type(KCPU);
			DDR_scan_set_error(DDR_SCAN_STATUS_KCPU);
			pr_err("read 0x18000100 val == %#x read 0x18000110 val == %#x \n", rtd_inl(0xb8000100), rtd_inl(0xb8000110));
			my_panic("[KDSP] WatchDog does not receive signal for %d seconds, value: %08x \n", TO_MSEC/1000, val_dummy_3);
		}
#endif
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
		if (time_is_before_jiffies(to_v2)) {
			set_rtdlog_panic_cpu_type(VCPU2);
			DDR_scan_set_error(DDR_SCAN_STATUS_VCPU2);
			my_panic("[V2DSP] WatchDog does not receive signal for %d seconds, value: %08x \n", TO_MSEC/1000, val_dummy_3);
		}
#endif

		do
		{
			msleep(100);

			if (freezing(current))
			{
				printk(KERN_EMERG "freeze hw_watchdog!!!\n");
                hw_watchdog_tick_enable = 1;
#ifdef CONFIG_CUSTOMER_TV030
                printk(KERN_EMERG "hw_watchdog: suspending, watchdog on/off control by bootcode\n");
                rtk_wdog_kick_by_ap = 0;
                if (uboot_wdg_state)
            	   watchdog_enable(1);             // make sure is MAX timeout
                rtd_outl(WDOG_TCWTR_reg, 0x01);    // only kick not disable watchdog
#else
				watchdog_enable(0);
#endif
				__refrigerator(false);   // freezed

                rtd_outl(WDOG_TCWTR_reg, 0x01);
				printk(KERN_EMERG "monitor watchdog thread wakeup\n");
				/*watchdog on/off control by bootcode.*/
				uboot_wdg_state = is_watchdog_enable();
				if (uboot_wdg_state)
					watchdog_enable(1);    // after resume, make sure is MAX timeout
            	printk(KERN_EMERG "enter hw_watchdog!!!    %x\n",current->flags);
                k_force_protect = jiffies + msecs_to_jiffies(K_FORCE_PROTECT_MSEC);
				to_a = to_v = to_k = to_v2 = to_a2 = jiffies + msecs_to_jiffies(TO_MSEC);
                hw_watchdog_tick_enable = 0;
			}
			//try_to_freeze();

		}
		while(0);

		if (watchdog_task == 0)
		{
			watchdog_enable(0);
			break;
		}

	}

	printk(KERN_EMERG "hw_watchdog: exit...\n");
	do_exit(0);
	return 0;
}

#if 0
int hw_watchdog(void *p)
{
    struct sched_param param = { .sched_priority = MAX_RT_PRIO-1 };
    //static int tmp=0;
#if 0 // fix me - jinn - kernel porting
    daemonize("hw_watchdog");
#endif
    sched_setscheduler(current, SCHED_FIFO, &param);
    current->flags &= ~PF_NOFREEZE;

    //  printk("************************************\n");
    //  printk("*********watchdog mechanism*********\n");
    //  printk("************************************\n");

    /* enable watchdog */
    #if 0
    rtd_outl(WDOG_TCWTR_reg, 0x01);//outl(0x01, VENUS_MIS_TCWTR);//WDOG_TCWTR_reg
    rtd_outl(WDOG_TCWCR_reg, 0xa5);//outl(0xa5, VENUS_MIS_TCWCR);
    rtd_outl(WDOG_TCWOV_reg, 0xc000000);//outl(0xc000000, VENUS_MIS_TCWOV);
    #endif

    //rtd_outl(WDOG_TCWCR_reg, 0xc000000);//outl(0x00, VENUS_MIS_TCWCR);
    watchdog_task = (unsigned long)current;
    printk("enter hw_watchdog!!!\n");

    while (1)
    {
        msleep_interruptible(1000);
        rtd_outl(WDOG_TCWTR_reg, 0x01);//outl(0x01, VENUS_MIS_TCWTR);

        if (watchdog_task == 0)
        {
            printk("hw_watchdog: exit...\n");
            break;
        }

        /* check if we need to freeze */
#if 0
        if (freezing(current))
        {
            /* disable watchdog */
            outl(0xa5, VENUS_MIS_TCWCR);

            refrigerator();

            /* enable watchdog */
            outl(0xc000000, VENUS_MIS_TCWOV);
            outl(0x00, VENUS_MIS_TCWCR);
        }
#endif

    }
    do_exit(0);
    return 0;
}
#endif

static void rtk_wdog_ping (void)
{
	rtd_outl(WDOG_TCWTR_reg, 0x01);
	rtk_wdog_expires = ktime_to_timespec(ktime_get()).tv_sec + rtk_wdog_timeout_value;
    rtk_wdog_AP_expires =  ktime_to_timespec(ktime_get()).tv_sec + 60;
//    rtk_wdog_ping_count++;
//    if (rtk_wdog_ping_count%50==1)
//        printk(KERN_EMERG "hw_watchdog: rtk_wdog_ping(0x%x)\n", rtk_wdog_ping_count);
}

static void rtk_wdog_set_timeout(unsigned int timeout)
{
    printk(KERN_EMERG "hw_watchdog: rtk_wdog_set_timeout=%d\n", timeout);
	rtd_outl(WDOG_TCWOV_reg, WDOG_SECS_TO_TICKS(timeout));
	rtk_wdog_timeout_value = timeout;
}

static unsigned int rtk_wdog_get_timeout(void)
{
	//For The LSB 8 bit is fixed to 0x80 in hardware.
	//so need add additional timeout Ticks offset to get the accurate timeout seconds. 
	return WDOG_TICKS_TO_SECS(rtd_inl(WDOG_TCWOV_reg) + 0xff);
}
int rtk_wdog_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int timeout = 0;
	int timeout_left = 0;
	int option =0;
	RHAL_WDOG_STATUS_T wdog_status = RHAL_WDOG_IS_OFF;
	switch(cmd) {
			case WDIOC_KEEPALIVE:
					rtk_wdog_ping();
					break;

			case WDIOC_SETTIMEOUT:
					if (get_user(timeout, (int __user *)arg))
							return -EFAULT;
					if (timeout > WDOG_TIMEOUT_MAX)
							return -EFAULT;
					rtk_wdog_set_timeout(timeout);
					rtk_wdog_ping();
					break;	

			case WDIOC_SETOPTIONS: 
					if (copy_from_user(&option, (int __user *)arg, sizeof(int)))
							return -EFAULT;

					//printk(KERN_EMERG "hw_watchdog: ioctl WDIOC_SETOPTIONS=0x%x  k_force_protect=%ul  jiffies=%ul\n", option, k_force_protect, jiffies);	
					if (option & WDIOS_DISABLECARD) {
#ifdef CONFIG_CUSTOMER_TV030
                            if (!time_is_before_jiffies(k_force_protect)) {
                               printk(KERN_EMERG "hw_watchdog: shouldn't be disabled at beginning 60sec\n");
                               break;
                            }
#endif
							rtk_wdog_kick_by_ap = 0;
							watchdog_enable(0);
							printk(KERN_EMERG "hw_watchdog: ioctl set WDIOS_DISABLECARD\n");	
					}

					if (option & WDIOS_ENABLECARD) {
							rtk_wdog_kick_by_ap = 1;
							watchdog_enable(1);
							 //Set previous timeout value to watchdog. if this is the first time enable watchdog, We will set max timeout value to watchdog.
							rtk_wdog_set_timeout(rtk_wdog_timeout_value); 
							rtk_wdog_ping();
							printk(KERN_EMERG "hw_watchdog: ioctl set WDIOS_ENABLECARD\n");
					}

					if (option & WDIOS_ENABLE_WITH_KERNEL_AUTO_KICK) {
							rtk_wdog_kick_by_ap = 0;
							watchdog_enable(1); //use fault watchdog value.
							rtk_wdog_ping();
							printk(KERN_EMERG "hw_watchdog: ioctl set WDIOS_ENABLE_WITH_KERNEL_AUTO_KICK\n");
					}
					break;

			case WDIOC_GETTIMEOUT:
					timeout = rtk_wdog_get_timeout();
					return put_user(timeout, (int __user *)arg);	

			case WDIOC_GETTIMELEFT: 
					//get the time that's left before rebooting
					timeout_left = rtk_wdog_expires - ktime_to_timespec(ktime_get()).tv_sec;
					if(timeout_left < 0){
							timeout_left = 0;
					}

					return put_user(timeout_left, (int __user *)arg);

			case WDIOC_GETSTATUS:
					if(is_watchdog_enable()){
							if(rtk_wdog_kick_by_ap == 0){
									wdog_status = RHAL_WDOG_IS_ON_WITH_KERNEL_AUTO_KICK;
							}
							else{
									wdog_status = RHAL_WDOG_IS_ON_NEED_AP_KICK;      
							}
					}
					else{
							wdog_status = RHAL_WDOG_IS_OFF;
					}
					return put_user(wdog_status, (int __user *)arg);
                    
			default:  /* redundant, as cmd was checked against MAXNR */
					pr_err("wdog ioctl code not supported\n");
					return -ENOTTY;

	}
	return 0;
       
}

static long rtk_wdog_unlocked_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int ret;

	mutex_lock(&rtk_wdog_mutex);
	ret = rtk_wdog_ioctl(file, cmd, arg);
	mutex_unlock(&rtk_wdog_mutex);

	return ret;
}

struct file_operations wdog_fops = {
        .owner                 =    THIS_MODULE,
        .unlocked_ioctl        =    rtk_wdog_unlocked_ioctl,
};


int wdog_resume_early(struct device *dev)
{
    rtd_outl(WDOG_TCWTR_reg, 0x01);
    printk(KERN_EMERG "hw_watchdog: check watchdog at wdog_resume_early\n");
    if (is_watchdog_enable())
	   watchdog_enable(1);

    return 0;
}

#ifdef CONFIG_PM
static const struct dev_pm_ops wdog_pm_ops =
{
//	.suspend    = wdog_suspend_instanboot,
	.resume_early = wdog_resume_early,
//	.resume     = wdog_resume_instanboot,
//	.complete	= wdog_resume_Backlight_TurnOn,
#ifdef CONFIG_HIBERNATION
//	.freeze 	= wdog_suspend,
//	.thaw 		= wdog_resume,
//	.poweroff 	= wdog_suspend,
//	.restore 	= wdog_resume,
#endif
};
#endif // CONFIG_PM

static struct platform_device *wdog_platform_devs;

static struct platform_driver wdog_device_driver = {
	.driver =
	{
        .name         = WDOG_DEVICE_NAME,
//        .bus          = &platform_bus_type,
#ifdef CONFIG_PM
	 .pm         = &wdog_pm_ops,
#endif

	},
};

static char *wdog_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}
static __init int rtk_wdog_init_module(void)
{
	int result = -1;
	dev_t dev = 0;

	if (wdog_major) {
			dev = MKDEV(wdog_major, wdog_minor);
			result = register_chrdev_region(dev, 1, WDOG_DEVICE_NAME);
	} else {
			result = alloc_chrdev_region(&dev, wdog_minor, 1, WDOG_DEVICE_NAME);
			wdog_major = MAJOR(dev);
	}
	if (result < 0) {
			pr_err("wdog: can't get major %d\n", wdog_major);
			return result;
	}
	pr_info("wdog:get result:%d,get dev:0x%08x,major:%d\n", result, dev, wdog_major);

	wdog_class = class_create(THIS_MODULE, WDOG_DEVICE_NAME);
	if (IS_ERR(wdog_class))
			return PTR_ERR(wdog_class);

	wdog_class->devnode = wdog_devnode;
	wdog_platform_devs = platform_device_register_simple(WDOG_DEVICE_NAME, -1, NULL, 0);
    if((result=platform_driver_register(&wdog_device_driver)) != 0)
	{
		printk(KERN_EMERG "hw_watchdog: can not register platform driver...\n");
    	goto fail_platform_driver_register;
    }

	wdog_drv_dev = kmalloc(sizeof(struct wdog_dev), GFP_KERNEL);
	if (!wdog_drv_dev) {
			device_destroy(wdog_class, dev);
			result = -ENOMEM;
			pr_err("wdog: alloc memory Failed, result = %d\n", result);
			return result;
	}
	memset(wdog_drv_dev, 0, sizeof(struct wdog_dev));

	cdev_init(&wdog_drv_dev->cdev, &wdog_fops);
	wdog_drv_dev->cdev.owner = THIS_MODULE;
	wdog_drv_dev->cdev.ops = &wdog_fops;

	result = cdev_add(&wdog_drv_dev->cdev, dev, 1);
	if (result) {
			device_destroy(wdog_class, dev);
			pr_err("wdog: add cdev Failed, result = %d\n", result);
			goto fail;
	}

	device_create(wdog_class, NULL, dev, NULL, WDOG_DEVICE_NAME);
	pr_info("rtk_wdog_init_module successfully!! \n");

	return 0;


fail:
	platform_driver_unregister(&wdog_device_driver);
fail_platform_driver_register:
	kfree(wdog_drv_dev);
	wdog_drv_dev = NULL;
	return result;
}

static __exit  void  rtk_wdog_cleanup_module(void)
{
	dev_t devno = MKDEV(wdog_major, wdog_minor);
	if (wdog_drv_dev) {
		cdev_del(&(wdog_drv_dev->cdev));
		device_destroy(wdog_class, MKDEV(wdog_major, wdog_minor));
		kfree(wdog_drv_dev);
	}
  	platform_driver_unregister(&wdog_device_driver);
	class_destroy(wdog_class);
	unregister_chrdev_region(devno, 1);
}
EXPORT_SYMBOL(rtk_wdog_init_module);
EXPORT_SYMBOL(rtk_wdog_cleanup_module);

module_init(rtk_wdog_init_module);
module_exit(rtk_wdog_cleanup_module);
MODULE_AUTHOR("Realtek.com");
MODULE_LICENSE("GPL");


