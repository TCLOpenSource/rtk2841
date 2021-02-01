#ifndef __RTK_GPIO_ATTR_H__
#define __RTK_GPIO_ATTR_H__

typedef struct
{
    unsigned int gpio_num;
    unsigned int gpio_type;
} RTK_GPIO_SETTING;

extern int  rtk_gpio_create_attr(struct device *device);
extern void rtk_gpio_remove_attr(struct device *device);

#endif /*__RTK_GPIO_ATTR_H__ */
