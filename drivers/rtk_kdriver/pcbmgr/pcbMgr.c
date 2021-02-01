#include <linux/atomic.h>
#include <linux/bitops.h>
#include <linux/device.h>
#include <linux/export.h>
#include <linux/fs.h>
#include <linux/jiffies.h>
#include <linux/kernel.h>
#include <linux/kfifo.h>
#include <linux/io.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/ioctl.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/platform_device.h>
#include <linux/smp.h>
#include <linux/string.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/pcbMgr.h>


#ifdef CONFIG_RTK_PCBMGR_DBG_EN
#define RTK_PCBMGR_DBG(fmt, args...)      rtd_printk(KERN_DEBUG, "PCBMGR", "[Dbg]" fmt, ## args)
#define RTK_PCBMGR_INFO(fmt, args...)     rtd_printk(KERN_INFO,  "PCBMGR", "[Info]" fmt, ## args)
#else
#define RTK_PCBMGR_DBG(fmt, args...)
#define RTK_PCBMGR_INFO(fmt, args...)
#endif

#define RTK_PCBMGR_WARN(fmt, args...)     rtd_printk(KERN_WARNING,  "PCBMGR", "[Wan]" fmt, ## args)


extern void dump_stacks (void);


char* dumpPcbMgrPinTypeStr(unsigned long long pininfo)
{
    PCB_PIN_TYPE_T pintype = 0 ;

    pintype = GET_PIN_TYPE(pininfo);


    switch(pintype)
    {

    case PCB_PIN_TYPE_UNUSED:
        return "PCB_PIN_TYPE_UNUSED";

    case PCB_PIN_TYPE_LSADC:
        return "PCB_PIN_TYPE_LSADC";

    case PCB_PIN_TYPE_EMCU_GPIO:
        return "PCB_PIN_TYPE_EMCU_GPIO";

    case PCB_PIN_TYPE_GPIO:
        return "PCB_PIN_TYPE_GPIO";

    case PCB_PIN_TYPE_ISO_GPIO:
        return "PCB_PIN_TYPE_ISO_GPIO";

    case PCB_PIN_TYPE_UNIPWM:
        return "PCB_PIN_TYPE_UNIPWM";

    case PCB_PIN_TYPE_ISO_UNIPWM:
        return "PCB_PIN_TYPE_ISO_UNIPWM";

    case PCB_PIN_TYPE_PWM:
        return "PCB_PIN_TYPE_PWM";

    case PCB_PIN_TYPE_ISO_PWM:
        return "PCB_PIN_TYPE_ISO_PWM";

    case PCB_PIN_TYPE_UNDEF:
        return "PCB_PIN_TYPE_UNDEF";

    }

    return "unknow type";
}


int rtk_SetIOPinDirection(unsigned long long pininfo, unsigned int value)
{
    PCB_PIN_TYPE_T pintype;
    RTK_GPIO_ID s_gpio;
    int pinindex = 0;
    int pinparam1 = 0, pinparam2 = 0, pinparam3 = 0;

    if (value != 0x0 && value != 0x1)
    {
        RTK_PCBMGR_WARN("[%s] unsupported value = 0x%08x.\n",
            __func__ , value);
        return -1;
    }

    pintype = GET_PIN_TYPE(pininfo);
    pinindex = GET_PIN_INDEX(pininfo);

    RTK_PCBMGR_DBG("[%s] pinType = %s , pin=0x%llx value=0x%x, type=%08x, index=%d \n",
                    __func__ , dumpPcbMgrPinTypeStr(pininfo) , (unsigned int)pininfo, value, pintype, pinindex);

    switch (pintype) {
    case PCB_PIN_TYPE_GPIO:
        {
            pinparam1 = GET_GPIO_TYPE(pininfo);
            pinparam2 = GET_GPIO_INVERT(pininfo);
            pinparam3 = GET_GPIO_INIT_VALUE(pininfo);


            RTK_PCBMGR_DBG("[GPIO-MISC][%s] param1 0x%x param2 0x%x param3 0x%x\n",
                            __func__ , pinparam1, pinparam2, pinparam3);

            if (pinparam1 == PCB_GPIO_TYPE_INPUT && value != 0)
            {
                RTK_PCBMGR_DBG("[GPIO-MISC][%s][PCB_PIN_TYPE_GPIO] Input-Only pin %d is configured to output.\n",
                                        __func__ , pinindex);
            }
            else if (pinparam1 == PCB_GPIO_TYPE_OUPUT && value != 1)
            {
                RTK_PCBMGR_DBG("[GPIO-MISC][%s][PCB_PIN_TYPE_GPIO] Output-Only pin %d is configured config to input.\n",
                                        __func__ , pinindex);
            }
            else if (pinparam1 >= PCB_GPIO_TYPE_UNDEF)
            {
                RTK_PCBMGR_WARN ("[GPIO-MISC] wrong GPIO type\n");
                return -1;
            }

            s_gpio = rtk_gpio_id(MIS_GPIO, pinindex);
            rtk_gpio_set_dir(s_gpio, value);

            RTK_PCBMGR_DBG("[GPIO-MISC][%s] config pin %d to %d.\n",
                            __func__ , pinindex, (int)value);

            return 0;
        }
    case PCB_PIN_TYPE_ISO_GPIO:
        {
            pinparam1 = GET_GPIO_TYPE(pininfo);
            pinparam2 = GET_GPIO_INVERT(pininfo);
            pinparam3 = GET_GPIO_INIT_VALUE(pininfo);

            RTK_PCBMGR_DBG("[GPIO-ISO][%s] param1 0x%x param2 0x%x param3 0x%x\n",
                            __func__, pinparam1, pinparam2, pinparam3);

            if (pinparam1 == PCB_GPIO_TYPE_INPUT && value != 0)
            {
                RTK_GPIO_DBG("[GPIO-ISO][%s][PCB_PIN_TYPE_GPIO] Input-Only pin %d is configured to output.\n",
                    __func__ , pinindex);
            }
            else if (pinparam1 == PCB_GPIO_TYPE_OUPUT&& value != 1)
            {
                RTK_GPIO_DBG("[GPIO-ISO][%s][PCB_PIN_TYPE_GPIO] Output-Only pin %d is configured to input.\n",
                    __func__ , pinindex);
            }
            else if (pinparam1 >= PCB_GPIO_TYPE_UNDEF)
            {
                RTK_PCBMGR_WARN("[GPIO-ISO] wrong GPIO type\n");
                return -1;
            }

            s_gpio = rtk_gpio_id(ISO_GPIO, pinindex);
            rtk_gpio_set_dir(s_gpio, value);
            RTK_PCBMGR_DBG("[GPIO-ISO][%s] config pin %d to %d.\n",
                __func__ , pinindex, (int)value);
            return 0;
        }

    case PCB_PIN_TYPE_UNUSED:
            return 0;

    default:
    case PCB_PIN_TYPE_AUDIO:
    case PCB_PIN_TYPE_PWM:
    case PCB_PIN_TYPE_UNIPWM:
    case PCB_PIN_TYPE_ISO_PWM:
    case PCB_PIN_TYPE_ISO_UNIPWM:
    case PCB_PIN_TYPE_LSADC:
    case PCB_PIN_TYPE_EMCU_GPIO:
        RTK_PCBMGR_WARN("[%s]  (pininfo=0x%X) Type = %s is not support .\n",
                __func__ , (unsigned int)pininfo , dumpPcbMgrPinTypeStr(pininfo)  );

        dump_stacks();

        return -1;
    }

    return -1;
}

EXPORT_SYMBOL(rtk_SetIOPinDirection);

int rtk_GetIOPinDirection(unsigned long long pininfo)
{
    PCB_PIN_TYPE_T pintype;
    RTK_GPIO_ID s_gpio;
    int pinindex = 0;

    pintype = GET_PIN_TYPE(pininfo);
    pinindex = GET_PIN_INDEX(pininfo);

    switch (pintype) {

    case PCB_PIN_TYPE_GPIO:
        s_gpio = rtk_gpio_id(MIS_GPIO, pinindex);
        return rtk_gpio_get_dir(s_gpio);
    case PCB_PIN_TYPE_ISO_GPIO:
        s_gpio = rtk_gpio_id(ISO_GPIO, pinindex);
        return rtk_gpio_get_dir(s_gpio);

    case PCB_PIN_TYPE_UNUSED:
        return 0;

    default:
    case PCB_PIN_TYPE_PWM:
    case PCB_PIN_TYPE_UNIPWM:
    case PCB_PIN_TYPE_ISO_PWM:
    case PCB_PIN_TYPE_ISO_UNIPWM:
    case PCB_PIN_TYPE_EMCU_GPIO:
    case PCB_PIN_TYPE_LSADC:
    case PCB_PIN_TYPE_AUDIO:
        RTK_PCBMGR_WARN("[%s]  (pininfo=0x%X) Type = %s is not support .\n",
                __func__ , (unsigned int)pininfo , dumpPcbMgrPinTypeStr(pininfo)  );

        dump_stacks();
        return -1;
    }
    return -1;

}

EXPORT_SYMBOL(rtk_GetIOPinDirection);


int rtk_SetIOPin(unsigned long long pininfo, unsigned int value)
{
    PCB_PIN_TYPE_T pintype;
    RTK_GPIO_ID s_gpio;
    int pinindex = 0;
    int ret = 0;

    if (rtk_GetIOPinDirection(pininfo) != 0x1)
    {
        RTK_PCBMGR_WARN("[%s] set pin 0x%08X error , pinType = %d , pinIndex = %d, this pin isn't output pin.\n",
             __func__ , (unsigned int)pininfo ,GET_PIN_TYPE(pininfo) ,  GET_PIN_INDEX(pininfo) );
        return -1;
    }

    pintype = GET_PIN_TYPE(pininfo);
    pinindex = GET_PIN_INDEX(pininfo);

    switch (pintype) {


    case PCB_PIN_TYPE_GPIO:
        s_gpio = rtk_gpio_id(MIS_GPIO, pinindex);
        ret = rtk_gpio_output(s_gpio, value);
        if (ret != 0)
        {
            RTK_PCBMGR_WARN("[%s] set MIS GPIO %d error.\n",__func__ , pinindex);
            return -1;
        }
        return 0;
    case PCB_PIN_TYPE_ISO_GPIO:
        s_gpio = rtk_gpio_id(ISO_GPIO, pinindex);
        ret = rtk_gpio_output(s_gpio, value);
        if (ret != 0)
        {
            RTK_PCBMGR_WARN("[%s] set ISO GPIO %d error.\n",__func__ , pinindex);
            return -1;
        }
        return 0;

    case PCB_PIN_TYPE_UNUSED:
        return 0;


    default:
    case PCB_PIN_TYPE_UNIPWM:
    case PCB_PIN_TYPE_ISO_UNIPWM:
    case PCB_PIN_TYPE_PWM:
    case PCB_PIN_TYPE_ISO_PWM:
    case PCB_PIN_TYPE_EMCU_GPIO:
    case PCB_PIN_TYPE_LSADC:
    case PCB_PIN_TYPE_AUDIO:

        RTK_PCBMGR_WARN("[%s]  (pininfo=0x%X) Type = %s is not support .\n",
                __func__ , (unsigned int)pininfo , dumpPcbMgrPinTypeStr(pininfo)  );

        dump_stacks();
        return -1;
    }
    return -1;

}

EXPORT_SYMBOL(rtk_SetIOPin);

int rtk_GetIOPin(unsigned long long pininfo)
{
    PCB_PIN_TYPE_T pintype;
    RTK_GPIO_ID s_gpio;
    int pinindex = 0;

    if (rtk_GetIOPinDirection(pininfo) != 0x0)
    {
        RTK_PCBMGR_WARN("[GPIO][%s] get pin %08x error, this pin isn't input pin.\n",
             __func__ , (unsigned int)pininfo);
        return -1;
    }

    pintype = GET_PIN_TYPE(pininfo);
    pinindex = GET_PIN_INDEX(pininfo);

    switch (pintype) {

    case PCB_PIN_TYPE_GPIO:
        s_gpio = rtk_gpio_id(MIS_GPIO, pinindex);
        return rtk_gpio_input(s_gpio);

    case PCB_PIN_TYPE_ISO_GPIO:
        s_gpio = rtk_gpio_id(ISO_GPIO, pinindex);
        return rtk_gpio_input(s_gpio);

    case PCB_PIN_TYPE_UNUSED:
        return 0;

    default:
    case PCB_PIN_TYPE_UNIPWM:
    case PCB_PIN_TYPE_ISO_UNIPWM:
    case PCB_PIN_TYPE_PWM:
    case PCB_PIN_TYPE_ISO_PWM:
    case PCB_PIN_TYPE_EMCU_GPIO:
    case PCB_PIN_TYPE_LSADC:
    case PCB_PIN_TYPE_AUDIO:

        RTK_PCBMGR_WARN("[%s] Error, unkown type(0x%X). pinType = %s \n",
                    __func__ , pininfo , dumpPcbMgrPinTypeStr(pininfo)  );

        dump_stacks();
        return -1;
    }
    return -1;

}

EXPORT_SYMBOL(rtk_GetIOPin);





