#ifndef __RTK_GPIO_GPIO_CHIPSET_H__
#define __RTK_GPIO_GPIO_CHIPSET_H__

#include <linux/gpio.h>
#include <linux/gpio/driver.h>

#define MIS_GPIO_OFST       0       // MISC Group : Bidirectional Pads (Max: 200)
#define MIS_GPI_OFST        200     // MISC Group : Input only Pads (Max: 100)
#define MIS_GPO_OFST        300     // MISC Group : Out only Pads (Max: 100)
#define ISO_GPIO_OFST       400     // ISO Group  : Bidirectional Pads (Max: 100)
#define ISO_GPI_OFST        500     // ISO Group  : Input only Pads (Max: 100)
#define ISO_GPO_OFST        600     // ISO Group  : Output only Pads (Max: 100)


#ifdef CONFIG_RTK_KDRV_GPIO_GPIOLIB_SUPPORT
extern int  rtk_gpio_register_gpio_chipset(void);
extern void rtk_gpio_unregister_gpio_chipset(void);
#else
#define rtk_gpio_register_gpio_chipset()
#define rtk_gpio_unregister_gpio_chipset()
#endif

int rtk_gpio_id_to_number(RTK_GPIO_ID gid, unsigned int* gpio_num);


/////////////////////////////////////////////////////////////////////
#ifdef RTK_GPIO_CHIP_DBG_EN
#define RTK_GPIO_CHIP_DBG(fmt, args ...)     printk(KERN_WARNING fmt, ##args)
#else
#define RTK_GPIO_CHIP_DBG(fmt, args ...)
#endif

#endif /*__RTK_GPIO_GPIO_CHIPSET_H__ */
