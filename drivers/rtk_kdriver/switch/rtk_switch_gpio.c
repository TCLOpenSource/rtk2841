#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/interrupt.h>
#include <mach/irqs.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/io.h>
#include <mach/io.h>
#include <linux/pwm.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/types.h>
#include <rtk_kdriver/pcbMgr.h>
#include <linux/gpio.h>
#include <rtk_kdriver/rtk_gpio.h>
#include "rtk_switch.h"
#include "rtk_switch_gpio.h"

static GPIO_SWITCH_LIST g_gpio_switch_list;
static struct platform_device *g_gpio_switch_platform_dev;

static const char *g_switch_name_list[] = {
    "PIN_HP_OUT_JD", NULL
};


static ssize_t rtk_gpio_switch_print_state(struct switch_dev *sdev, char *buf)
{
    struct gpio_switch_data *switch_data = container_of (sdev, struct gpio_switch_data, sdev);
    const char *state;
    if (rtk_switch_get_state(sdev))
        state = switch_data->state_on;
    else
        state = switch_data->state_off;

    if (state)
        return sprintf(buf, "%s\n", state);
    return -1;
}

static irqreturn_t rtk_gpio_switch_irq_handler(RTK_GPIO_ID gid, unsigned char assert, void *dev_id)
{
    struct gpio_switch_data *switch_data = (struct gpio_switch_data *)dev_id;
    schedule_work(&switch_data->work);
    return IRQ_HANDLED;
}

static void rtk_gpio_switch_work(struct work_struct *work)
{
    int state;

    struct gpio_switch_data *data = container_of(work, struct gpio_switch_data, work);
    state = rtk_gpio_input(data->gpio);

    if(data->type == HP_OUT_JD){
        if (data->gpio_active_low)
            state = !state;

        if(state == 1)
            state = PLUG_IN_HEADSET_ANLG;
    }

    rtk_switch_set_state(&data->sdev, state);
}

struct gpio_switch_data* rtk_gpio_switch_find_switch_by_gid(RTK_GPIO_ID gid)
{
    int i = 0;
    struct gpio_switch_data* gpio_swtich = NULL;
    down_read(&g_gpio_switch_list.lock);
    for(i = 0; i < RTK_SWITCH_GPIO_DEV_NUM; i++) {
        if(g_gpio_switch_list.gpio_switchs[i] != NULL
            && g_gpio_switch_list.gpio_switchs[i]->gpio == gid) {
            gpio_swtich = g_gpio_switch_list.gpio_switchs[i];
            break;
        }
    }
    up_read(&g_gpio_switch_list.lock);
    return gpio_swtich;
}

struct gpio_switch_data* rtk_gpio_switch_find_switch_by_index(int index)
{
    struct gpio_switch_data* gpio_swtich = NULL;
    down_read(&g_gpio_switch_list.lock);
    if(index >= 0 && index < RTK_SWITCH_GPIO_DEV_NUM)
        gpio_swtich = g_gpio_switch_list.gpio_switchs[index];
    up_read(&g_gpio_switch_list.lock);
    return gpio_swtich;
}


int rtk_gpio_switch_add_switch(struct gpio_switch_data *gpio_switch)
{
    int ret = -1;
    int i = 0;
    int first_usable_index = -1;
    struct gpio_switch_data *tmp = NULL;
    if(gpio_switch) {
        down_write(&g_gpio_switch_list.lock);
        for(i = 0; i < RTK_SWITCH_GPIO_DEV_NUM; i++) {
            if(first_usable_index == -1 && g_gpio_switch_list.gpio_switchs[i] == NULL)
                first_usable_index = i;
            if(g_gpio_switch_list.gpio_switchs[i] != NULL
                && g_gpio_switch_list.gpio_switchs[i]->gpio == gpio_switch->gpio) {
                tmp = g_gpio_switch_list.gpio_switchs[i];
                break;
            }
        }
        if(tmp == NULL) {
            if(first_usable_index != -1) {
                g_gpio_switch_list.gpio_switchs[first_usable_index] = gpio_switch;
                ret = 0;
            }
        }
        up_write(&g_gpio_switch_list.lock);
    }
    return ret;
}

void rtk_gpio_switch_remove_switch(struct gpio_switch_data *gpio_switch)
{
    int i = 0;
    if(gpio_switch) {
        down_write(&g_gpio_switch_list.lock);
        for(i = 0; i < RTK_SWITCH_GPIO_DEV_NUM; i++) {
            if(g_gpio_switch_list.gpio_switchs[i] != NULL
                && g_gpio_switch_list.gpio_switchs[i]->gpio == gpio_switch->gpio) {
                break;
            }
        }

        if(i < RTK_SWITCH_GPIO_DEV_NUM) {
            g_gpio_switch_list.gpio_switchs[i] = NULL;
        }
        up_write(&g_gpio_switch_list.lock);
    }
}

struct gpio_switch_data * rtk_gpio_switch_remove_switch_by_gid(RTK_GPIO_ID gid)
{
    int i = 0;
    struct gpio_switch_data *switch_data = NULL;
    down_write(&g_gpio_switch_list.lock);
    for(i = 0; i < RTK_SWITCH_GPIO_DEV_NUM; i++) {
        if(g_gpio_switch_list.gpio_switchs[i] != NULL
            && g_gpio_switch_list.gpio_switchs[i]->gpio == gid) {
            switch_data = g_gpio_switch_list.gpio_switchs[i];
            break;
        }
    }

    if(i < RTK_SWITCH_GPIO_DEV_NUM) {
        g_gpio_switch_list.gpio_switchs[i] = NULL;
    }
    up_write(&g_gpio_switch_list.lock);
    return switch_data;
}


int rtk_gpio_switch_register(RTK_GPIO_ID gid, char *name)
{
    int ret = 0;
    int state = 0;
    struct gpio_switch_data *switch_data = NULL;
    switch_data = kmalloc(sizeof(struct gpio_switch_data), GFP_KERNEL);
    if (!switch_data)
        return -ENOMEM;

    memset(switch_data, 0, sizeof(struct gpio_switch_data));
    if(!name)
        sprintf(switch_data->sdev.name, "%s-%d", gpio_type(gpio_group(gid)), gpio_idx(gid));
    else{
        if(strcmp("jd",name) == 0){
            sprintf(switch_data->sdev.name, "%s",  "h2w");
            switch_data->gpio_active_low = 1;
            switch_data->type = HP_OUT_JD;
        }
        else{
            sprintf(switch_data->sdev.name, "%s",  name);
            switch_data->gpio_active_low = 0;
            switch_data->type = GENERAL_TYPE;
        }
    }
    switch_data->gpio = gid;
    switch_data->sdev.print_state = rtk_gpio_switch_print_state;

    ret = rtk_switch_dev_register(&switch_data->sdev);
    if (ret < 0)
        goto err_switch_dev_register;

    rtk_gpio_set_dir(switch_data->gpio, 0);
    rtk_gpio_set_irq_polarity(switch_data->gpio, 1);
    INIT_WORK(&switch_data->work, rtk_gpio_switch_work);
    ret = rtk_gpio_request_irq(switch_data->gpio,
                               (void *)rtk_gpio_switch_irq_handler, "SWITCH_GPIO_INT",
                               switch_data);

    if (ret) {
        RTK_SWITCH_ERR("%s request irq fail\n", __func__);
        goto err_switch_dev_request_irq;
    }
    rtk_gpio_set_irq_enable(switch_data->gpio, 1);
    ret = rtk_gpio_switch_add_switch(switch_data);
    if(ret != 0)
        goto err_switch_add_dev;

    if(strcmp("jd",name) == 0){
        state = rtk_gpio_input(switch_data->gpio);
        state = !state;
        if(state == 1)
            state = PLUG_IN_HEADSET_ANLG;
        rtk_switch_set_state(&switch_data->sdev, state);
    }else{
        state = rtk_gpio_input(switch_data->gpio);
        rtk_switch_set_state(&switch_data->sdev, state);
    }
    RTK_SWITCH_INFO("Add switch dev for %s-%d, sys dir = %s\n",
                                    gpio_type(gpio_group(gid)), gpio_idx(gid), switch_data->sdev.name);
    return 0;
err_switch_add_dev:
    rtk_gpio_set_irq_enable(switch_data->gpio, 0);
    rtk_gpio_free_irq(switch_data->gpio,switch_data);
err_switch_dev_request_irq:
    rtk_switch_dev_unregister(&switch_data->sdev);
err_switch_dev_register:
    kfree(switch_data);
    return ret;
}


int rtk_gpio_switch_unregister(RTK_GPIO_ID gid)
{
    struct gpio_switch_data *switch_data = NULL;
    switch_data = rtk_gpio_switch_remove_switch_by_gid(gid);
    if(!switch_data)
        return 0;
    rtk_gpio_set_irq_enable(switch_data->gpio, 0);
    rtk_gpio_free_irq(switch_data->gpio,switch_data);
    rtk_switch_dev_unregister(&switch_data->sdev);
    cancel_work_sync(&switch_data->work);
    kfree(switch_data);
    return 0;
}

static int rtk_switch_gpio_probe(struct platform_device *pdev)
{
    return 0;
}

static int rtk_switch_gpio_remove(struct platform_device *pdev)
{
    return 0;
}

#ifdef CONFIG_PM
static int rtk_switch_gpio_suspend(struct device *dev)
{
    RTK_SWITCH_WARN("suspend\n");
    return 0;
}
static int rtk_switch_gpio_resume(struct device *dev)
{
    int i = 0;
    int state;
    GPIO_SWITCH_LIST *switch_list = &g_gpio_switch_list;

    for(i=0; i<RTK_SWITCH_GPIO_DEV_NUM; i++)
    {
        if (switch_list->gpio_switchs[i] != NULL)
        {
            state = rtk_gpio_input(switch_list->gpio_switchs[i]->gpio);

            if(switch_list->gpio_switchs[i]->type == HP_OUT_JD){
                if (switch_list->gpio_switchs[i]->gpio_active_low)
                    state = !state;

                if(state == 1)
                    state = PLUG_IN_HEADSET_ANLG;
            }

            rtk_switch_set_state(&switch_list->gpio_switchs[i]->sdev, state);
        }
    }
    RTK_SWITCH_WARN("resume\n");
    return 0;
}


#ifdef CONFIG_HIBERNATION
static int rtk_switch_gpio_suspend_std(struct device *dev)
{
    RTK_SWITCH_WARN("rtk_switch_gpio_suspend_std\n");
    return 0;
}
static int rtk_switch_gpio_resume_std(struct device *dev)
{
    RTK_SWITCH_WARN("rtk_switch_gpio_resume_std\n");
    return 0;
}

#endif

static const struct dev_pm_ops rtk_switch_gpio_pm_ops = {

    .suspend = rtk_switch_gpio_suspend,
    .resume = rtk_switch_gpio_resume,

#ifdef CONFIG_HIBERNATION
    .freeze     = rtk_switch_gpio_suspend_std,
    .thaw       = rtk_switch_gpio_resume_std,
#endif
};


#endif

static const struct of_device_id rtk_switch_gpio_devices[] = {
    {.compatible = "rtk_switch_gpio",},
    {},
};

MODULE_DEVICE_TABLE(of, rtk_switch_gpio_devices);

static struct platform_driver rtk_switch_gpio_driver = {
    .driver = {
            .name = "rtk_switch_gpio",
            .owner = THIS_MODULE,
            .of_match_table = of_match_ptr(rtk_switch_gpio_devices),

            #ifdef CONFIG_PM
            .pm = &rtk_switch_gpio_pm_ops,
            #endif
        },
    .probe = rtk_switch_gpio_probe,
    .remove = rtk_switch_gpio_remove,
};

static char * rtk_switch_gpio_get_dev_name(char *name)
{
    char *dev_name = NULL;
    if(name != NULL) {
        dev_name = strrchr(name, '_');
        if(dev_name) {
            dev_name++;
        }
    }
    return dev_name;
}
static int rtk_switch_gpio_parse_and_register_dev(char *name)
{
    int ret = 0;
    int i = 0;
    RTK_GPIO_ID gid;
    RTK_GPIO_GROUP gpio_group = MIS_GPIO;
    int gpio_index = 0;
    unsigned long long ullPcbMgrValue = 0x0;
    char dev_name[32] = {0};
    if(!name)
        return -1;
    ret = pcb_mgr_get_enum_info_byname(name, &ullPcbMgrValue);
    if(ret != 0)
        return -1;
    if (GET_PIN_TYPE(ullPcbMgrValue) == PCB_PIN_TYPE_GPIO) {
        gpio_group = MIS_GPIO;
    } else if (GET_PIN_TYPE(ullPcbMgrValue) == PCB_PIN_TYPE_ISO_GPIO) {
        gpio_group = ISO_GPIO;
    } else {
        return -1;
    }
    gpio_index = GET_PIN_INDEX(ullPcbMgrValue);
    gid = rtk_gpio_id(gpio_group, gpio_index);
    name = rtk_switch_gpio_get_dev_name(name);

    if(name == NULL || strlen(name) == 0)
        return -1;
    while(*name != '0' && i < 32) {
          dev_name[i] = *name;
          if(dev_name[i] <= 'Z' && dev_name[i] >= 'A')
            dev_name[i] = dev_name[i] + 0x20;
          name++;
          i++;
    }

    return rtk_gpio_switch_register(gid, dev_name);

}

static int __init rtk_switch_gpio_init(void)
{
    int ret = 0;
    char **namelist = (char **)g_switch_name_list;
    init_rwsem(&g_gpio_switch_list.lock);

    ret = platform_driver_register(&rtk_switch_gpio_driver);
    if (ret != 0)
            goto REGISTER_PLATFORM_DRIVER_FAIL;

    g_gpio_switch_platform_dev =
        platform_device_register_simple("rtk_switch_gpio", -1, NULL, 0);

    if (g_gpio_switch_platform_dev == NULL)
        goto REGISTER_PLATFORM_DEVICE_FAIL;

    while (*namelist != NULL) {
            rtk_switch_gpio_parse_and_register_dev(*namelist);
            namelist++;
    }
    RTK_SWITCH_INFO("switch gpio driver init sucess\n");
    return 0;
REGISTER_PLATFORM_DEVICE_FAIL:
    platform_driver_unregister(&rtk_switch_gpio_driver);
REGISTER_PLATFORM_DRIVER_FAIL:
    return -1;
}

static void __exit rtk_switch_gpio_exit(void)
{
    int i = 0;
    struct gpio_switch_data *data = NULL;

    platform_driver_unregister(&rtk_switch_gpio_driver);
    platform_device_unregister(g_gpio_switch_platform_dev);

    for(i = 0; i < RTK_SWITCH_GPIO_DEV_NUM; i++) {
        data = rtk_gpio_switch_find_switch_by_index(i);
        if(data)
            rtk_gpio_switch_unregister(data->gpio);
    }
}

module_init(rtk_switch_gpio_init);
module_exit(rtk_switch_gpio_exit);
MODULE_DESCRIPTION("Realtek Switch GPIO Driver");
MODULE_LICENSE("GPL");
