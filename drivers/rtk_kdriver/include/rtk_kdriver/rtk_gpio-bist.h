#ifndef __RTK_GPIO_BIST_H__
#define __RTK_GPIO_BIST_H__

extern void rtk_gpio_built_in_test(void);   // main function of GPIO built in test

extern void rtk_gpio_test_isr(RTK_GPIO_ID gid, unsigned char assert, void *dev_id);
extern void rtk_gpio_test(void);
extern void rtk_gpio_test_by_enum(void);

#endif /*__RTK_GPIO_BIST_H__ */

