#ifndef __RTK_SWITCH_GPIO_H__
#define __RTK_SWITCH_GPIO_H__
#include "rtk_switch.h"
#include <linux/rwsem.h>

#define RTK_SWITCH_GPIO_DEV_NUM 32
#define INIT_LOCK(lock)         init_rwsem(&(lock))
#define WRITE_LOCK(lock)     up_write(&(lock))
#define WRITE_UNLOCK(lock)   down_write(&(lock))
#define READ_LOCK(lock)      up_read(&(lock))
#define READ_UNLOCK(lock)        down_read(&(lock))

typedef enum{
    HP_OUT_JD      = 0,
    SWITCH_WOV     = 1,
    GENERAL_TYPE   = 2,
}SWITCH_GPIO_TYPE;

//HEADSET Type From Android Framework
typedef enum{
    PLUG_OUT_HEADSET      = 0,
    PLUG_IN_NO_MIC        = 1,
    PLUG_IN_HEADSET_ANLG  = 2,
}HEADSET_STATE;


typedef struct gpio_switch_data {
    struct switch_dev sdev;
    unsigned gpio;
    bool gpio_active_low;
    const char *name_on;
    const char *name_off;
    const char *state_on;
    const char *state_off;
    struct work_struct work;
    int type;
}GPIO_SWITCH_DEV;

typedef struct gpio_switch_list
{
    struct rw_semaphore lock;
    unsigned int gpio_switch_num;
    GPIO_SWITCH_DEV *gpio_switchs[RTK_SWITCH_GPIO_DEV_NUM];
}GPIO_SWITCH_LIST;

extern int rtk_gpio_switch_register(RTK_GPIO_ID gid, char *name);
extern int rtk_gpio_switch_unregister(RTK_GPIO_ID gid);


#endif
