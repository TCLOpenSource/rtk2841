#include <linux/slab.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/time.h>
#include <linux/sched.h>
#include <rbus/pll_reg_reg.h>
#include <linux/miscdevice.h>
#include <rtk_kdriver/rtk_thermal_sensor.h>
#include <rtk_kdriver/rtk_crt.h>
#include <mach/io.h>
#include <linux/delay.h>
#include "rtk_thermal_sensor_reg.h"

static DEFINE_MUTEX(thermal_lock);

#ifdef CONFIG_RTK_KDRV_THERMAL_SIMULATOR_TEMP
static struct timeval current_tv, previous_tv;
#endif
static int thermal_init = 0;


void exit_rtk_thermal_sensor(void)
{
    thermal_init = 0;
}

static int rtk_thermal_sensor_hw_setting(void)
{
    SET_THERMAL_SENSOR_1(THERMAL_TM_A(0x07F80000));/*reg_a=29'h07F80000*/
    SET_THERMAL_SENSOR_2(THERMAL_TM_OSR(0x1) | THERMAL_TM_CHOPEN(0x1) |
                         THERMAL_TM_B(0xDD000000>>PLL_REG_TEMP_SENSOR_2_tm_b_shift));/*reg_b=22'h36F2CD,CHOPEN=1*/
    SET_THERMAL_SENSOR_4(THERMAL_TM_HOLD_DLY(0x1));

    SET_THERMAL_SENSOR_3(THERMAL_TM_POW_ON);/*tm_pow=1*/
    SET_THERMAL_SENSOR_5(THERMAL_TM_CHOPFREQSEL(0x1));/*tm_rstb=0*/
    SET_THERMAL_SENSOR_5(THERMAL_TM_RSTB(1) | THERMAL_TM_CHOPFREQSEL(0x1));/*tm_rstb=1*/

    CRT_CLK_OnOff(THERMAL_SENSOR, CLK_ON, NULL);


    mdelay(20);
    return 0;
}

void init_rtk_thermal_sensor(void)
{
    int retry_count = 0;

Init_Retry:
    if (!thermal_init) {
        mutex_lock(&thermal_lock);
        rtk_thermal_sensor_hw_setting();
        thermal_init = 1;
        mutex_unlock(&thermal_lock);
    }
    if((rtk_get_thermal_value() >= 145 || rtk_get_thermal_value() == 0) && retry_count < 5 ) {
        retry_count++;
        mutex_lock(&thermal_lock);
        thermal_init = 0;
        mutex_unlock(&thermal_lock);
        THERMAL_WARNING("Retry , temperature strange during init ");
        goto Init_Retry;
    }
#ifdef CONFIG_RTK_KDRV_THERMAL_SIMULATOR_TEMP
    do_gettimeofday(&previous_tv);
    do_gettimeofday(&current_tv);
#endif
}

#ifdef CONFIG_RTK_KDRV_THERMAL_SIMULATOR_TEMP
static int rtk_get_time_diff_sec(int diff_sec)
{
    static int simulate_temp = 60;
    int x;
    do_gettimeofday(&current_tv);
    x = (current_tv.tv_sec - previous_tv.tv_sec);

    if (x > diff_sec) {
        simulate_temp += 10;
        previous_tv = current_tv;
    }

    if (simulate_temp > 90)
        simulate_temp = 40;

    return simulate_temp;
}
#endif

static void rtk_thermal_sensor_int_on_off(bool scpu, bool on_off)
{
    if(scpu) {
        if (on_off)
            SET_THERMAL_IRQ_Threshold_1((GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_SCPU_IE_MASK)) | THERMAL_SENSOR_SCPU_IE_MASK);
        else
            SET_THERMAL_IRQ_Threshold_1(GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_SCPU_IE_MASK));
    } else {
        if (on_off)
            SET_THERMAL_IRQ_Threshold_1((GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_KCPU_IE_MASK)) | THERMAL_SENSOR_KCPU_IE_MASK);
        else
            SET_THERMAL_IRQ_Threshold_1(GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_KCPU_IE_MASK));
    }
}

void rtk_thermal_sensor_enable(int enable)
{
    if (enable)
        rtk_thermal_sensor_int_on_off(1, 1);
    else
        rtk_thermal_sensor_int_on_off(1, 0);

}
unsigned int rtk_get_thermal_reg(void)
{

    unsigned int val;
    mutex_lock(&thermal_lock);
    if( unlikely(thermal_init == 0) ) {
        mutex_unlock(&thermal_lock);
        return 0;
    }
    val = GET_THERMAL_CT_OUT_O_TM();
    mutex_unlock(&thermal_lock);

    return val;
}


int rtk_get_thermal_value(void)
{
    unsigned int val, old_reg;
    old_reg = val = rtk_get_thermal_reg();
#ifdef CONFIG_RTK_KDRV_THERMAL_SIMULATOR_TEMP
    return rtk_get_time_diff_sec(10);
#else
    val &= 0x0007FFFF;
    if( (val & 0x40000) == 0x40000 ) {
        val -= 1;
        val = (~val) & 0x0003FFFF;
        val = -val;
        val = 0; /* no need to care minus value in thermal driver */
    }

    val /= 1024;

    if(val >= 135)
        THERMAL_WARNING("Warning , temperature higher than:%d oldreg:%x newreg:%x\n", val, old_reg, rtd_inl(0xb80003A0));
    return val;
#endif
}

int rtk_get_thermal_value_ext(void)
{
    int val, old_reg;
    old_reg = val = rtk_get_thermal_reg();
#ifdef CONFIG_RTK_KDRV_THERMAL_SIMULATOR_TEMP
    return rtk_get_time_diff_sec(10);
#else
    val &= 0x0007FFFF;
    if( (val & 0x40000) == 0x40000 ) {
        val -= 1;
        val = (~val) & 0x0003FFFF;
        val = -val;
    }

    val /= 1024;

    if(val >= 135)
        THERMAL_WARNING("Warning , temperature higher than:%d oldreg:%x newreg:%x\n", val, old_reg, rtd_inl(0xb80003A0));
    return val;
#endif

}


int rtk_thermal_trigger_high(int temp_high)
{
    rtk_thermal_sensor_int_on_off(0, 0);
    if(temp_high > 250) {
        THERMAL_ERR("thermal impossible trigger low value:%d\n", temp_high);
        temp_high = 250;
    }

    if(temp_high<0)
    {
	temp_high*=1024;	
	temp_high&=0x7FFFF;
    }	
    else {
    	temp_high *= 1024;
    	temp_high &= 0x3FFFF;
    }
    SET_THERMAL_SENSOR_THH(temp_high);
    return 0;
}

int rtk_thermal_trigger_low(int temp_low)
{
    if(temp_low < -250) {
        THERMAL_ERR("thermal impossible trigger low value:%d\n", temp_low);
        temp_low = -250;
    }
    if(temp_low<0)
    {
	temp_low*=1024;	
	temp_low&=0x7FFFF;
    }	
    else {
    	temp_low *= 1024;
    	temp_low &= 0x3FFFF;
    }
    SET_THERMAL_SENSOR_THL(temp_low);
    return 0;
}

int rtk_thermal_int_status(void)
{
    unsigned int reg = GET_THERMAL_SENSOR_IRQ_SCPU_STATUS();
    CLEAR_THERMAL_SENSOR_IRQ_SCPU_STATUS();
    return reg;
}


EXPORT_SYMBOL(init_rtk_thermal_sensor);
EXPORT_SYMBOL(exit_rtk_thermal_sensor);
EXPORT_SYMBOL(rtk_get_thermal_value);

/***************************************************************************
     ------------------- Debug FS  ----------------
****************************************************************************/

/*------------------------------------------------------------------
 * Func : rtk_thremal_show_param
 *
 * Desc : show thermal sensor status
 *
 * Parm :
 *
 * Retn : 0
 *------------------------------------------------------------------*/
ssize_t rtk_thremal_show_param(struct device *dev,
                               struct device_attribute *attr, char *buf)
{
    u64 ts = local_clock();
    unsigned long rem_nsec = do_div(ts, 1000000000);
    return sprintf(buf, "[%5lu.%06lu] tempature=%d (C)\n",  (unsigned long)ts, rem_nsec / 1000, rtk_get_thermal_value());
}


/*------------------------------------------------------------------
 * Func : rtk_thermal_store_param
 *
 * Desc : N/A
 *
 * Parm :
 *
 * Retn : 0
 *------------------------------------------------------------------*/
ssize_t rtk_thermal_store_param(struct device *dev,
                                struct device_attribute *attr,
                                const char *buf, size_t count)
{
    return count;
}

static DEVICE_ATTR(status, S_IWUSR | S_IWGRP | S_IRUGO, rtk_thremal_show_param,
                   rtk_thermal_store_param);


static struct miscdevice rtk_thermal_miscdev = {
    MISC_DYNAMIC_MINOR,
    "rtk_thermal",
    NULL
};


/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/


/*------------------------------------------------------------------
 * Func : thermal_module_init
 *
 * Desc : thermal module init function
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static int __init thermal_module_init(void)
{
    if (misc_register(&rtk_thermal_miscdev)) {
        THERMAL_ERR("register thermal misc device failed\n");
        return -1;
    }
    device_create_file(rtk_thermal_miscdev.this_device, &dev_attr_status);
    return 0;
}


/*------------------------------------------------------------------
 * Func : thermal_module_exit
 *
 * Desc : thermal module exit function
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static void __exit thermal_module_exit(void)
{
    device_remove_file(rtk_thermal_miscdev.this_device, &dev_attr_status);
    misc_deregister(&rtk_thermal_miscdev);
}

module_init(thermal_module_init);
module_exit(thermal_module_exit);
