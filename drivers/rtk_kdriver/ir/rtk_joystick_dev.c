#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/errno.h> 
#include <linux/input.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/delay.h>


struct rtk_joystick_dev {
    struct input_dev *dev; 
    char phys[64];
    const char *name;
};

static const signed short rtk_joystick_abs[] = {
    ABS_X, ABS_Y,       /* left stick */
    ABS_RX, ABS_RY,     /* right stick */
    -1          /* terminating entry */
};



static struct rtk_joystick_dev g_rtk_joystick_dev =
{
    .name = "rtk_joystick",
};

static void rtk_joystick_set_up_abs(struct input_dev *input_dev, signed short abs)
{
    set_bit(abs, input_dev->absbit);
    switch (abs) {
    case ABS_X:
    case ABS_Y:
    case ABS_RX:
    case ABS_RY:    /* the two sticks */
        input_set_abs_params(input_dev, abs, -32768, 32767, 16, 128);
        break;
    case ABS_Z:
    case ABS_RZ:    /* the triggers (if mapped to axes) */
        input_set_abs_params(input_dev, abs, 0, 255, 0, 0);
        break;
    case ABS_HAT0X:
    case ABS_HAT0Y: /* the d-pad (only if dpad is mapped to axes */
        input_set_abs_params(input_dev, abs, -1, 1, 0, 0);
        break;
    }
}



static __init int rtk_joystick_dev_init(void)
{
    struct input_dev *input_dev = NULL;
    int error;
    int i;
    printk(KERN_ERR"%s,%d\n", __FUNCTION__, __LINE__);
    input_dev = input_allocate_device();
    if (!input_dev)
        return -ENOMEM;

    sprintf(g_rtk_joystick_dev.phys, "rtk_joystick%d", 0);
    g_rtk_joystick_dev.dev = input_dev;
    input_dev->name = g_rtk_joystick_dev.name;
    input_dev->phys = g_rtk_joystick_dev.phys;
    input_dev->id.bustype = BUS_VIRTUAL;
    input_dev->id.vendor	= 0;
    input_dev->id.product	= 0;
    input_dev->id.version	= 1;

    input_set_drvdata(input_dev, &g_rtk_joystick_dev);

    input_dev->evbit[0] = BIT_MASK(EV_SYN) | BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
    
    for(i = BTN_MISC; i <= BTN_9; i++)
        set_bit(i, input_dev->keybit);

    for(i = BTN_JOYSTICK; i < BTN_DIGI; i++)
        set_bit(i, input_dev->keybit);

    set_bit(ABS_X, input_dev->absbit);
    set_bit(ABS_Y, input_dev->absbit);
    set_bit(ABS_RX, input_dev->absbit);
    set_bit(ABS_RY, input_dev->absbit);

    for (i = 0; rtk_joystick_abs[i] >= 0; i++)
        rtk_joystick_set_up_abs(input_dev, rtk_joystick_abs[i]);

    error = input_register_device(input_dev);
    if (error)
        goto err_register_input_dev;
    printk(KERN_ERR"%s,%d\n", __FUNCTION__, __LINE__);
    return 0;

err_register_input_dev:
    input_free_device(input_dev);
    return error;

}

static __exit void  rtk_joystick_dev_uninit(void)
{
    input_unregister_device(g_rtk_joystick_dev.dev);
    input_free_device(g_rtk_joystick_dev.dev);
    g_rtk_joystick_dev.dev = NULL;
}

module_init(rtk_joystick_dev_init);
module_exit(rtk_joystick_dev_uninit);


