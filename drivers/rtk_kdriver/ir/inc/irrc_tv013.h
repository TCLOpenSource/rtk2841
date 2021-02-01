#ifndef __IRRC_TV013_H__
#define __IRRC_TV013_H__

#include <rtk_kdriver/rtk_gpio.h>
#include "irrc_common.h"

#define IR_PROTOCOL     NEC

static struct timer_list led_flash_timer;
static unsigned int isLedFlash = 0;

static void venus_ir_led_flash_start(void);
void venus_ir_led_flash_end(void);


static void venus_ir_led_flash_start(void)
{
    unsigned long led_flash_jiffies = jiffies + msecs_to_jiffies(200);
//      rtd_maskl(0xb8061108, ~BIT(11), 0);
    rtk_gpio_output(rtk_gpio_id(ISO_GPIO, 11), 0);
    mod_timer(&led_flash_timer, led_flash_jiffies);
}

void venus_ir_led_flash_end(void)
{
    if(isLedFlash < 5 ) {
        if(isLedFlash % 2 == 0)
//                      rtd_maskl(0xb8061108, ~BIT(11), BIT(11));
            rtk_gpio_output(rtk_gpio_id(ISO_GPIO, 11), 1);
        else
//                      rtd_maskl(0xb8061108, ~BIT(11), 0);
            rtk_gpio_output(rtk_gpio_id(ISO_GPIO, 11), 0);
        unsigned long led_flash_jiffies = jiffies + msecs_to_jiffies(200);
        mod_timer(&led_flash_timer, led_flash_jiffies);
        isLedFlash++;
    } else {
//              rtd_maskl(0xb8061108, ~BIT(11), BIT(11));
        rtk_gpio_output(rtk_gpio_id(ISO_GPIO, 11), 1);
        isLedFlash = 0;
    }
}

#endif
