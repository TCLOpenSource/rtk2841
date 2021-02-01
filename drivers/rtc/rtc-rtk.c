/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2010 by Chien-An Lin <colin@realtek.com.tw>
 *
 * RTC driver for Realtek series CPUs.
 */
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/rtc.h>
#include <linux/time.h>
#include <linux/slab.h>

extern int rtk_rtc_mips_set_mmss(unsigned long nowtime);
extern void rtk_rtc_read_alarm_persistent_clock(struct timespec *ts);
extern int rtk_rtc_set_alarm_mmss(unsigned long nowtime);
extern void rtk_rtc_alarm_aie_enable(int state);
extern int rtk_rtc_alarm_aie_state(void);
extern void rtk_rtc_sb2_timeout_debug_info(void);

struct timer_list rtk_rtc_timer;
struct timespec64 *p_ts1;

// g_is_walarm_off = 1 means disable rtc alarm wakeup funciton.
int g_rtc_is_walarm_off = 0;

static int rtk_rtc_read_time(struct device *dev, struct rtc_time *time)
{
	struct timespec64 ts;

	read_persistent_clock64(&ts);
	rtc_time_to_tm(ts.tv_sec, time);

	return 0;
}

static int rtk_rtc_set_time(struct device *dev, struct rtc_time *time)
{
	unsigned long cur_sec;

	cur_sec = mktime(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday,
			time->tm_hour, time->tm_min, time->tm_sec);
	rtk_rtc_mips_set_mmss(cur_sec);

	return 0;
}

static int rtk_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct timespec64 ts;

	rtk_rtc_read_alarm_persistent_clock(&ts);
	rtc_time_to_tm(ts.tv_sec, &alrm->time);
	alrm->enabled = rtk_rtc_alarm_aie_state();

	return 0;
}

static int rtk_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	unsigned long cur_sec;
    
 	rtk_rtc_alarm_aie_enable(0);   
	if(g_rtc_is_walarm_off)
	{
		pr_info("[%s]rtc alarm wakeup function was disabled!!!\n", __func__);
		return 0;
	}

	cur_sec = mktime(alrm->time.tm_year + 1900, alrm->time.tm_mon + 1, alrm->time.tm_mday,
			alrm->time.tm_hour, alrm->time.tm_min, alrm->time.tm_sec);
	rtk_rtc_set_alarm_mmss(cur_sec);
	if(alrm->enabled)
		rtk_rtc_alarm_aie_enable(1);

	return 0;
}

static int rtk_rtc_ioctl(struct device *dev, unsigned int cmd,
	unsigned long arg)
{
	switch (cmd) {
	case RTC_AIE_ON:
		rtk_rtc_alarm_aie_enable(1); 
		break;
	case RTC_AIE_OFF:
		rtk_rtc_alarm_aie_enable(0);
		break;

	default:
		return -ENOIOCTLCMD;
	}
	return 0;
}

static const struct rtc_class_ops rtk_rtc_ops = {
	.read_time	= rtk_rtc_read_time,
	.set_time	= rtk_rtc_set_time,
//	.set_mmss	= 
	.read_alarm	= rtk_rtc_read_alarm,
	.set_alarm	= rtk_rtc_set_alarm,
	.ioctl		= rtk_rtc_ioctl,
};

void check_rtc_timerfunc(unsigned long data)
{
	struct timespec64 ts2;

	read_persistent_clock64(&ts2);
	if(p_ts1->tv_sec == ts2.tv_sec) {
		printk("RTK rtc cannot work.\n");
	} else {
		printk("RTK rtc can work.\n");
	}

	kfree(p_ts1);
}

//the real rtk_rtc_secure_rbus_bit_state() funciton was defined in rtk_rtc.c.
int __weak rtk_rtc_secure_rbus_bit_state(void)
{
	return 1;
}

static int rtk_rtc_probe(struct platform_device *pdev)
{
	struct resource *res;
	struct rtc_device *rtc;
	int retval;

	if (pdev->num_resources != 1) {
		pr_err("%s(): Number of resource not equal to one.\n", __func__);
		return -EBUSY;
	}

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		pr_err("%s(): Get resource fail.\n", __func__);
		return -EBUSY;
	}

	if(!request_mem_region(res->start, resource_size(res), pdev->name)) {
		pr_err("%s: RTC registers at %08x are not free\n", pdev->name, res->start);
		return -EBUSY;
	}

	//should call this function before rtc_device_register.
	device_init_wakeup(&pdev->dev, 1);

	rtc = rtc_device_register(pdev->name, &pdev->dev, &rtk_rtc_ops, THIS_MODULE);
	if (IS_ERR(rtc)) {
		retval = PTR_ERR(rtc);
		pr_err("%s: can't register RTC device, err %d\n", pdev->name, retval);
		goto out;
	}

	platform_set_drvdata(pdev, rtc);

	p_ts1 = (struct timespec64*)kmalloc(sizeof(struct timespec64), GFP_KERNEL);
	read_persistent_clock64(p_ts1);
	init_timer(&rtk_rtc_timer);
	rtk_rtc_timer.function = check_rtc_timerfunc;
	rtk_rtc_timer.expires = jiffies + 2*HZ;
	add_timer(&rtk_rtc_timer);


	printk("rtc: Real Time Clock of Realtek series CPUs\n");

	return 0;

out:
	release_mem_region(res->start, resource_size(res));
	return retval;
}

static int rtk_rtc_remove(struct platform_device *pdev)
{
	struct rtc_device *rtc = platform_get_drvdata(pdev);
	struct resource *res = dev_get_drvdata(&rtc->dev);

	rtk_rtc_alarm_aie_enable(0);
	rtc_device_unregister(rtc);
	release_mem_region(res->start, resource_size(res));
	platform_set_drvdata(pdev, NULL);

	return 0;
}

#ifdef CONFIG_PM
static int rtk_rtc_clear_alarm_flag(struct device *dev)
{
	//disable alarm interrupt, and clear alarm interrupt pending bit.
	rtk_rtc_alarm_aie_enable(0);
	return 0;
}

static const struct dev_pm_ops rtc_pm_ops = {
	.complete	= rtk_rtc_clear_alarm_flag,
};
#endif


/* work with hotplug and coldplug */
MODULE_ALIAS("platform:rtc-rtk");
static struct platform_driver rtk_platform_rtc_driver = {
	.probe		= rtk_rtc_probe,
	.remove		= rtk_rtc_remove,
	.driver		= {
		.name	= "rtc-rtk",
		.owner	= THIS_MODULE,
#ifdef CONFIG_PM
		.pm 	= &rtc_pm_ops,
#endif
	},
};

static int __init rtk_rtc_init(void)
{
        if(rtk_rtc_secure_rbus_bit_state() == 0){
                return platform_driver_register(&rtk_platform_rtc_driver); //used to sync rtc time to system time
        }
        else{
#ifdef CONFIG_REALTEK_SECURE            
                return platform_driver_register(&rtk_platform_rtc_driver);
#else   
        	pr_err("[%s]ERR: Should not register rtc device to kernel!!!\n", __func__);
#endif
	}
}

static void __exit rtk_rtc_exit(void)
{
        if(rtk_rtc_secure_rbus_bit_state() == 0){
        	platform_driver_unregister(&rtk_platform_rtc_driver);
	}
        else{
#ifdef CONFIG_REALTEK_SECURE            
                platform_driver_unregister(&rtk_platform_rtc_driver);
#endif
        }
}

module_init(rtk_rtc_init);
module_exit(rtk_rtc_exit);

MODULE_AUTHOR("Colin <colin@realtek.com.tw>");
MODULE_DESCRIPTION("Realtek series RTC driver");
MODULE_LICENSE("GPL v2");
