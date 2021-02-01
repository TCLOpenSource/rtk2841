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
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-bist.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_gpio-debug.h>
#include <rtk_kdriver/pcbMgr.h>


static unsigned long long gull_PIN_BL_ON_OFF;

static RTK_GPIO_ID pout = rtk_gpio_id(ISO_GPIO, 23);
static RTK_GPIO_ID pin = rtk_gpio_id(ISO_GPIO, 32);

void rtk_gpio_test_isr(RTK_GPIO_ID gid,
                       unsigned char assert, void *dev_id)
{
    RTK_GPIO_WARNING("%s GPIO %d assert=%d, val=%d\n",
          gpio_type(gpio_group(gid)), gpio_idx(gid),
             assert, rtk_gpio_input(pin)); 

    rtk_gpio_set_dir(pout, 1);
    rtk_gpio_output(pout, (assert) ? 0 : 1);
}

void rtk_gpio_test(void)
{
    rtk_gpio_set_dir(pin, 0);
    rtk_gpio_set_debounce(pin, RTK_GPIO_DEBOUNCE_100us);    /* 100 us */
    rtk_gpio_set_irq_polarity(pin, 0);
    rtk_gpio_request_irq(pin, rtk_gpio_test_isr, "GPIO_TEST",
                         rtk_gpio_test_isr);
    rtk_gpio_set_irq_enable(pin, 1);

    RTK_GPIO_WARNING("rtk_gpio_test for %s GPIO %d (%x) ready\n",
                     gpio_type(gpio_group(pin)), gpio_idx(pin), pin);
}

void rtk_gpio_test_by_enum(void)
{
    int ret = 0;
    int gpio_dir = 0;
    ret =
        pcb_mgr_get_enum_info_byname("PIN_BL_ON_OFF", &gull_PIN_BL_ON_OFF);

    if (ret) {
        RTK_GPIO_WARNING("[%s]- get enum error , no this pin definition \"PIN_BL_ON_OFF\". Terminate test.\n",
                         __func__);
        return;
    }
    if (!gull_PIN_BL_ON_OFF) {
        RTK_GPIO_DBG("[%s]- get enum Value = %x. Terminate test.\n",
                     __func__, (unsigned int)gull_PIN_BL_ON_OFF);
        return;
    }

    RTK_GPIO_DBG("[%s] get PIN_BL_ON_OFF = 0x%x\n", __func__,
                 (unsigned int)gull_PIN_BL_ON_OFF);

    /* set direction = OUTPUT */
    ret = rtk_SetIOPinDirection(gull_PIN_BL_ON_OFF, 1);
    if (ret)
        RTK_GPIO_WARNING("[%s]- set pin DIRECTION OUTPUT  fail!!\n",
                         __func__);
    else
        RTK_GPIO_DBG("[%s]- set pin DIRECTION OUTPUT  success.\n",
                     __func__);

    gpio_dir = rtk_GetIOPinDirection(gull_PIN_BL_ON_OFF);
    RTK_GPIO_DBG("[%s] get direction = %d\n", __func__, gpio_dir);

    /* change output pin to HIGH */
    ret = rtk_SetIOPin(gull_PIN_BL_ON_OFF, 1);
    if (ret)
        RTK_GPIO_WARNING("[%s]- set pin HIGH fail!!\n", __func__);
    else
        RTK_GPIO_DBG("[%s]- set pin HIGH success.\n", __func__);

    /* change output pin to LOW */
    ret = rtk_SetIOPin(gull_PIN_BL_ON_OFF, 0);
    if (ret)
        RTK_GPIO_WARNING("[%s]- set pin LOW fail!!\n", __func__);
    else
        RTK_GPIO_DBG("[%s]- get pin LOW success.\n", __func__);

    /* set direction = INPUT */
    ret = rtk_SetIOPinDirection(gull_PIN_BL_ON_OFF, 0);
    if (ret)
        RTK_GPIO_WARNING("[%s]- set pin DIRECTION INPUT  fail!!\n",
                         __func__);
    else
        RTK_GPIO_DBG("[%s]- set pin DIRECTION INPUT  success.\n",
                     __func__);

    gpio_dir = rtk_GetIOPinDirection(gull_PIN_BL_ON_OFF);
    RTK_GPIO_DBG("[%s] set direction = %d, get value = %08x\n", __func__,
                 gpio_dir, rtk_GetIOPin(gull_PIN_BL_ON_OFF));

    /* the below functions will print WARNING Message,
    *    *   because To Set INPUT-PIN is N/A.
    *        */

    /* chang input pin to HIGH is N/A */
    ret = rtk_SetIOPin(gull_PIN_BL_ON_OFF, 1);
    if (ret)
        RTK_GPIO_WARNING("[%s]- set pin HIGH fail!!\n", __func__);
    else
        RTK_GPIO_DBG("[%s]- get pin HIGH success.\n", __func__);

    /* change input pin to HIGH is N/A */
    ret = rtk_SetIOPin(gull_PIN_BL_ON_OFF, 0);
    if (ret)
        RTK_GPIO_WARNING("[GPIO][%s]- set pin LOW fail!!\n", __func__);
    else
        RTK_GPIO_DBG("[%s]- get pin LOW success.\n", __func__);

}




void rtk_gpio_built_in_test(void)
{
    rtk_gpio_test();
    rtk_gpio_test_by_enum();
}

